// DirectSound proxy DLL template.

#define DIRECTSOUND_VERSION 0x0800

#include <dsound.h>
#include "common.hpp"

/// System DLLs and their functions
/// -------------------------------
typedef HRESULT(WINAPI *DirectSoundCreate8_t)(
	LPCGUID pcGuidDevice,
	LPDIRECTSOUND8 *ppDS8,
	LPUNKNOWN pUnkOuter
);

HMODULE dsound;
SYS_FUNC_DEF(DirectSoundCreate8);

FUNCINITPAIR dsound_pair[] = {
	PAIR(DirectSoundCreate8),
	NULL
};
/// -------------------------------

/// IDirectSound8
/// -------------
class my_IDirectSound8 : public IDirectSound8
{
	DECLARE_COM_PROXY_CLASS_FOR(IDirectSound8);

	// IDirectSound methods
	STDMETHOD(CreateSoundBuffer)(LPCDSBUFFERDESC, LPDIRECTSOUNDBUFFER *, LPUNKNOWN);
	STDMETHOD(GetCaps)(LPDSCAPS);
	STDMETHOD(DuplicateSoundBuffer)(LPDIRECTSOUNDBUFFER, LPDIRECTSOUNDBUFFER *);
	STDMETHOD(SetCooperativeLevel)(HWND, DWORD);
	STDMETHOD(Compact)();
	STDMETHOD(GetSpeakerConfig)(LPDWORD);
	STDMETHOD(SetSpeakerConfig)(DWORD);
	STDMETHOD(Initialize)(LPCGUID);

	// IDirectSound8 methods
	STDMETHOD(VerifyCertification)(LPDWORD);
};

IMPLEMENT_IUNKNOWN_FOR(my_IDirectSound8, true);

HRESULT my_IDirectSound8::CreateSoundBuffer(
	LPCDSBUFFERDESC pcDSBufferDesc,
	LPDIRECTSOUNDBUFFER *ppDSBuffer,
	LPUNKNOWN pUnkOuter
)
{
	return pOrig->CreateSoundBuffer(pcDSBufferDesc, ppDSBuffer, pUnkOuter);
}

HRESULT my_IDirectSound8::GetCaps(
	LPDSCAPS pDSCaps
)
{
	return pOrig->GetCaps(pDSCaps);
}

HRESULT my_IDirectSound8::DuplicateSoundBuffer(
	LPDIRECTSOUNDBUFFER pDSBufferOriginal,
	LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate
)
{
	return pOrig->DuplicateSoundBuffer(pDSBufferOriginal, ppDSBufferDuplicate);
}

HRESULT my_IDirectSound8::SetCooperativeLevel(
	HWND hwnd,
	DWORD dwLevel
)
{
	return pOrig->SetCooperativeLevel(hwnd, dwLevel);
}

HRESULT my_IDirectSound8::Compact()
{
	return pOrig->Compact();
}

HRESULT my_IDirectSound8::GetSpeakerConfig(
	LPDWORD pdwSpeakerConfig
)
{
	return pOrig->GetSpeakerConfig(pdwSpeakerConfig);
}

HRESULT my_IDirectSound8::SetSpeakerConfig(
	DWORD dwSpeakerConfig
)
{
	return pOrig->SetSpeakerConfig(dwSpeakerConfig);
}

HRESULT my_IDirectSound8::Initialize(
	LPCGUID pcGuidDevice
)
{
	return pOrig->Initialize(pcGuidDevice);
}

HRESULT my_IDirectSound8::VerifyCertification(
	LPDWORD pdwCertified
)
{
	return pOrig->VerifyCertification(pdwCertified);
}
/// --------------

extern "C" HRESULT WINAPI my_DirectSoundCreate8(
	LPCGUID pcGuidDevice,
	LPDIRECTSOUND8 *ppDS8,
	LPUNKNOWN pUnkOuter
)
{
	IDirectSound8 *pOrig;
	HRESULT ret = sys_DirectSoundCreate8(pcGuidDevice, &pOrig, pUnkOuter);
	if(SUCCEEDED(ret)) {
		*ppDS8 = new my_IDirectSound8(pOrig);
	}
	return ret;
}

BOOL APIENTRY DllMain(HMODULE hDll, DWORD ulReasonForCall, LPVOID lpReserved)
{
	return DLL_MAIN_FOR(dsound, L"dsound.dll");
}
