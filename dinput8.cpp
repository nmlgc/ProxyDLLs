// DirectInput 8 proxy DLL template.

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include "common.hpp"

/// System DLLs and their functions
/// -------------------------------
typedef HRESULT(WINAPI *DirectInput8Create_t)(
	HINSTANCE hInst,
	DWORD dwVersion,
	REFIID riidltf,
	LPVOID *ppvOut,
	LPUNKNOWN pUnkOuter
);

HMODULE dinput8;
SYS_FUNC_DEF(DirectInput8Create);

FUNCINITPAIR dinput8_pair[] = {
	PAIR(DirectInput8Create),
	NULL
};
/// -------------------------------

/// IDirectInput8A
/// --------------
class my_IDirectInput8A : public IDirectInput8A
{
	DECLARE_COM_PROXY_CLASS_FOR(IDirectInput8A);

	STDMETHOD(CreateDevice)(REFGUID, LPDIRECTINPUTDEVICE8A *, LPUNKNOWN);
	STDMETHOD(EnumDevices)(DWORD, LPDIENUMDEVICESCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetDeviceStatus)(REFGUID);
	STDMETHOD(RunControlPanel)(HWND, DWORD);
	STDMETHOD(Initialize)(HINSTANCE, DWORD);
	STDMETHOD(FindDevice)(REFGUID, LPCSTR, LPGUID);
	STDMETHOD(EnumDevicesBySemantics)(LPCSTR, LPDIACTIONFORMATA, LPDIENUMDEVICESBYSEMANTICSCBA, LPVOID, DWORD);
	STDMETHOD(ConfigureDevices)(LPDICONFIGUREDEVICESCALLBACK, LPDICONFIGUREDEVICESPARAMSA, DWORD, LPVOID);
};

IMPLEMENT_IUNKNOWN_FOR(my_IDirectInput8A);

HRESULT my_IDirectInput8A::CreateDevice(
	REFGUID rguid,
	LPDIRECTINPUTDEVICE8A * lplpDirectInputDevice,
	LPUNKNOWN pUnkOuter
)
{
	return pOrig->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);
}

HRESULT my_IDirectInput8A::EnumDevices(
	DWORD dwDevType,
	LPDIENUMDEVICESCALLBACKA lpCallback,
	LPVOID pvRef,
	DWORD dwFlags
)
{
	return pOrig->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT my_IDirectInput8A::GetDeviceStatus(
	REFGUID rguidInstance
)
{
	return pOrig->GetDeviceStatus(rguidInstance);
}

HRESULT my_IDirectInput8A::RunControlPanel(
	HWND hWndOwner,
	DWORD dwFlags
)
{
	return pOrig->RunControlPanel(hWndOwner, dwFlags);
}

HRESULT my_IDirectInput8A::Initialize(
	HINSTANCE hInst,
	DWORD dwVersion
)
{
	return pOrig->Initialize(hInst, dwVersion);
}

HRESULT my_IDirectInput8A::FindDevice(
	REFGUID rguidClass,
	LPCSTR ptszName,
	LPGUID pguidInstance
)
{
	return pOrig->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT my_IDirectInput8A::EnumDevicesBySemantics(
	LPCSTR ptszUserName,
	LPDIACTIONFORMATA lpdiActionFormat,
	LPDIENUMDEVICESBYSEMANTICSCBA lpCallback,
	LPVOID pvRef,
	DWORD dwFlags
)
{
	return pOrig->EnumDevicesBySemantics(ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT my_IDirectInput8A::ConfigureDevices(
	LPDICONFIGUREDEVICESCALLBACK lpdiCallback,
	LPDICONFIGUREDEVICESPARAMSA lpdiCDParams,
	DWORD dwFlags,
	LPVOID pvRefData
)
{
	return pOrig->ConfigureDevices(lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}
/// --------------

extern "C" HRESULT WINAPI my_DirectInput8Create(
	HINSTANCE hInst,
	DWORD dwVersion,
	REFIID riidltf,
	LPVOID *ppvOut,
	LPUNKNOWN pUnkOuter
)
{
	IDirectInput8A *pOrig;
	HRESULT ret = sys_DirectInput8Create(hInst, dwVersion, riidltf, (LPVOID*)&pOrig, pUnkOuter);
	if(SUCCEEDED(ret)) {
		*ppvOut = new my_IDirectInput8A(pOrig);
	}
	return ret;
}

BOOL APIENTRY DllMain(HMODULE hDll, DWORD ulReasonForCall, LPVOID lpReserved)
{
	return DLL_MAIN_FOR(dinput8, L"dinput8.dll");
}
