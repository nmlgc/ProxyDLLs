// Shared code for all proxy DLLs, #included from the main compilation units.

#pragma comment(lib, "unicows.lib")

#define SYS_FUNC_DEF(func) \
	func##_t sys_##func;

#define SYS_GET_PROC_ADDRESS(handle, func) \
	sys_##func = (func##_t)GetProcAddress(handle, #func)

#define DECLARE_COM_PROXY_CLASS_FOR(x) \
protected: \
	x *pOrig; \
\
public: \
	my_##x(x *_pOrig) : pOrig(_pOrig) {} \
\
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj); \
	ULONG __stdcall AddRef(); \
	ULONG __stdcall Release();

#define IMPLEMENT_IUNKNOWN_FOR(x) \
	HRESULT x::QueryInterface(REFIID riid, void** ppvObj) \
	{ \
		*ppvObj = NULL; \
		\
		HRESULT hRes = pOrig->QueryInterface(riid, ppvObj); \
		if(hRes == NOERROR) { \
			*ppvObj = this; \
		} \
		return hRes; \
	} \
	\
	ULONG x::AddRef() \
	{ \
		return pOrig->AddRef(); \
	} \
	\
	ULONG x::Release() \
	{ \
		ULONG count = pOrig->Release(); \
		if(count == 0) { \
			delete this; \
		} \
		return count; \
	}

// Terminated with a NULL pointer in the name slot.
struct FUNCINITPAIR {
	void **func;
	const char *name;
};

#define PAIR(func) \
	{(void**)&sys_##func, #func}

wchar_t* SystemDLLPath(const wchar_t *DLL)
{
	UINT dll_len = lstrlenW(DLL) + 1;
	UINT sysdll_len = GetSystemDirectoryW(NULL, 0) + dll_len + 1;

	wchar_t *sysdll = new wchar_t[sysdll_len];
	if(!sysdll) {
		return NULL;
	}
	GetSystemDirectoryW(sysdll, sysdll_len);
	lstrcatW(sysdll, L"\\");
	lstrcatW(sysdll, DLL);
	return sysdll;
}

// Loads [DLL] from the system directory.
HMODULE LoadSystemDLL(const wchar_t *DLL)
{
	HMODULE ret = NULL;
	if(!DLL) {
		return NULL;
	}

	// And yes, we *have* to construct the path. LOAD_LIBRARY_SEARCH_SYSTEM32,
	// introduced with KB2533623 for Windows Vista, 7 and Server 2008, and
	// available natively on Windows 8 and above, does *not* work, and may
	// just end up incrementing the reference count of any other DLL with
	// the same name that might have been loaded into the address space of
	// the process before.

	wchar_t *sysdll = SystemDLLPath(DLL);
	ret = LoadLibraryW(sysdll);
	delete[] sysdll;
	return ret;
}

BOOL DllMainFor(HMODULE *hMod, const wchar_t *DLL, const FUNCINITPAIR *Pair, DWORD ulReasonForCall)
{
	const FUNCINITPAIR *p; // at this position for compatibility reasons

	switch(ulReasonForCall) {
	case DLL_PROCESS_ATTACH:
		*hMod = LoadSystemDLL(DLL);
		// TODO: GetLastError, FormatMessage, etc.
		for(p = Pair; p->name; p++) {
			*p->func = (void*)GetProcAddress(*hMod, p->name);
			// TODO: GetLastError, FormatMessage, etc.
		}
		break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(*hMod);
		break;
	}
	return TRUE;
}

// L""#dll".dll" would probably break in a lot of older compilers.
#define DLL_MAIN_FOR(dll, fn) \
	DllMainFor(&dll, fn, dll##_pair, ulReasonForCall)
