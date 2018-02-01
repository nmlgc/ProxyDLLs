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

/// IDirectSoundBuffer8
/// -------------------
const GUID IID_IDirectSoundBuffer  = {0x279afa85, 0x4981, 0x11ce, 0xa5, 0x21, 0x00, 0x20, 0xaf, 0x0b, 0xe5, 0x60};
const GUID IID_IDirectSoundBuffer8 = {0x6825a449, 0x7524, 0x4d82, 0x92, 0x0f, 0x50, 0xe3, 0x6a, 0xb3, 0xab, 0x1e};

class my_IDirectSoundBuffer8 : public IDirectSoundBuffer8
{
	DECLARE_COM_PROXY_CLASS_FOR(IDirectSoundBuffer8);

	// IDirectSoundBuffer methods
	STDMETHOD(GetCaps)(LPDSBCAPS);
	STDMETHOD(GetCurrentPosition)(LPDWORD, LPDWORD);
	STDMETHOD(GetFormat)(LPWAVEFORMATEX, DWORD, LPDWORD);
	STDMETHOD(GetVolume)(LPLONG);
	STDMETHOD(GetPan)(LPLONG);
	STDMETHOD(GetFrequency)(LPDWORD);
	STDMETHOD(GetStatus)(LPDWORD);
	STDMETHOD(Initialize)(LPDIRECTSOUND, LPCDSBUFFERDESC);
	STDMETHOD(Lock)(DWORD, DWORD, LPVOID *, LPDWORD, LPVOID *, LPDWORD, DWORD);
	STDMETHOD(Play)(DWORD, DWORD, DWORD);
	STDMETHOD(SetCurrentPosition)(DWORD);
	STDMETHOD(SetFormat)(LPCWAVEFORMATEX);
	STDMETHOD(SetVolume)(LONG);
	STDMETHOD(SetPan)(LONG);
	STDMETHOD(SetFrequency)(DWORD);
	STDMETHOD(Stop)();
	STDMETHOD(Unlock)(LPVOID, DWORD, LPVOID, DWORD);
	STDMETHOD(Restore)();

	// IDirectSoundBuffer8 methods
	STDMETHOD(SetFX)(DWORD, LPDSEFFECTDESC, LPDWORD);
	STDMETHOD(AcquireResources)(DWORD, DWORD, LPDWORD);
	STDMETHOD(GetObjectInPath)(REFGUID, DWORD, REFGUID, LPVOID *);
};

IMPLEMENT_IUNKNOWN_FOR(
	my_IDirectSoundBuffer8, (riid == IID_IDirectSoundBuffer || riid == IID_IDirectSoundBuffer8)
);

HRESULT my_IDirectSoundBuffer8::GetCaps(
	LPDSBCAPS pDSBufferCaps
)
{
	return pOrig->GetCaps(pDSBufferCaps);
}

HRESULT my_IDirectSoundBuffer8::GetCurrentPosition(
	LPDWORD pdwCurrentPlayCursor,
	LPDWORD pdwCurrentWriteCursor
)
{
	return pOrig->GetCurrentPosition(pdwCurrentPlayCursor, pdwCurrentWriteCursor);
}

HRESULT my_IDirectSoundBuffer8::GetFormat(
	LPWAVEFORMATEX pwfxFormat,
	DWORD dwSizeAllocated,
	LPDWORD pdwSizeWritten
)
{
	return pOrig->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);
}

HRESULT my_IDirectSoundBuffer8::GetVolume(
	LPLONG plVolume
)
{
	return pOrig->GetVolume(plVolume);
}

HRESULT my_IDirectSoundBuffer8::GetPan(
	LPLONG plPan
)
{
	return pOrig->GetPan(plPan);
}

HRESULT my_IDirectSoundBuffer8::GetFrequency(
	LPDWORD pdwFrequency
)
{
	return pOrig->GetFrequency(pdwFrequency);
}

HRESULT my_IDirectSoundBuffer8::GetStatus(
	LPDWORD pdwStatus
)
{
	return pOrig->GetStatus(pdwStatus);
}

HRESULT my_IDirectSoundBuffer8::Initialize(
	LPDIRECTSOUND pDirectSound,
	LPCDSBUFFERDESC pcDSBufferDesc
)
{
	return pOrig->Initialize(pDirectSound, pcDSBufferDesc);
}

HRESULT my_IDirectSoundBuffer8::Lock(
	DWORD dwOffset,
	DWORD dwBytes,
	LPVOID *ppvAudioPtr1,
	LPDWORD pdwAudioBytes1,
	LPVOID *ppvAudioPtr2,
	LPDWORD pdwAudioBytes2,
	DWORD dwFlags
)
{
	return pOrig->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);
}

HRESULT my_IDirectSoundBuffer8::Play(
	DWORD dwReserved1,
	DWORD dwPriority,
	DWORD dwFlags
)
{
	return pOrig->Play(dwReserved1, dwPriority, dwFlags);
}

HRESULT my_IDirectSoundBuffer8::SetCurrentPosition(
	DWORD dwNewPosition
)
{
	return pOrig->SetCurrentPosition(dwNewPosition);
}

HRESULT my_IDirectSoundBuffer8::SetFormat(
	LPCWAVEFORMATEX pcfxFormat
)
{
	return pOrig->SetFormat(pcfxFormat);
}

HRESULT my_IDirectSoundBuffer8::SetVolume(
	LONG lVolume
)
{
	return pOrig->SetVolume(lVolume);
}

HRESULT my_IDirectSoundBuffer8::SetPan(
	LONG lPan
)
{
	return pOrig->SetPan(lPan);
}

HRESULT my_IDirectSoundBuffer8::SetFrequency(
	DWORD dwFrequency
)
{
	return pOrig->SetFrequency(dwFrequency);
}

HRESULT my_IDirectSoundBuffer8::Stop()
{
	return pOrig->Stop();
}

HRESULT my_IDirectSoundBuffer8::Unlock(
	LPVOID pvAudioPtr1,
	DWORD dwAudioBytes1,
	LPVOID pvAudioPtr2,
	DWORD dwAudioBytes2
)
{
	return pOrig->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);
}

HRESULT my_IDirectSoundBuffer8::Restore()
{
	return pOrig->Restore();
}

HRESULT my_IDirectSoundBuffer8::SetFX(
	DWORD dwEffectsCount,
	LPDSEFFECTDESC pDSFXDesc,
	LPDWORD pdwResultCodes
)
{
	return pOrig->SetFX(dwEffectsCount, pDSFXDesc, pdwResultCodes);
}

HRESULT my_IDirectSoundBuffer8::AcquireResources(
	DWORD dwFlags,
	DWORD dwEffectsCount,
	LPDWORD pdwResultCodes
)
{
	return pOrig->AcquireResources(dwFlags, dwEffectsCount, pdwResultCodes);
}

HRESULT my_IDirectSoundBuffer8::GetObjectInPath(
	REFGUID rguidObject,
	DWORD dwIndex,
	REFGUID rguidInterface,
	LPVOID *ppObject
)
{
	return pOrig->GetObjectInPath(rguidObject, dwIndex, rguidInterface, ppObject);
}
/// -------------------

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
	HRESULT ret = pOrig->CreateSoundBuffer(pcDSBufferDesc, ppDSBuffer, pUnkOuter);
	if(SUCCEEDED(ret)) {
		*ppDSBuffer = new my_IDirectSoundBuffer8((IDirectSoundBuffer8*)*ppDSBuffer);
	}
	return ret;
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
	HRESULT ret = pOrig->DuplicateSoundBuffer(pDSBufferOriginal, ppDSBufferDuplicate);
	if(SUCCEEDED(ret)) {
		*ppDSBufferDuplicate = new my_IDirectSoundBuffer8((IDirectSoundBuffer8*)*ppDSBufferDuplicate);
	}
	return ret;
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
