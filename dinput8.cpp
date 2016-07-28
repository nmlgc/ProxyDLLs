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

/// IDirectInputDevice8A
/// --------------------
class my_IDirectInputDevice8A : public IDirectInputDevice8A
{
	DECLARE_COM_PROXY_CLASS_FOR(IDirectInputDevice8A);

	STDMETHOD(GetCapabilities)(LPDIDEVCAPS);
	STDMETHOD(EnumObjects)(LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetProperty)(REFGUID, LPDIPROPHEADER);
	STDMETHOD(SetProperty)(REFGUID, LPCDIPROPHEADER);
	STDMETHOD(Acquire)();
	STDMETHOD(Unacquire)();
	STDMETHOD(GetDeviceState)(DWORD, LPVOID);
	STDMETHOD(GetDeviceData)(DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
	STDMETHOD(SetDataFormat)(LPCDIDATAFORMAT);
	STDMETHOD(SetEventNotification)(HANDLE);
	STDMETHOD(SetCooperativeLevel)(HWND, DWORD);
	STDMETHOD(GetObjectInfo)(LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD);
	STDMETHOD(GetDeviceInfo)(LPDIDEVICEINSTANCEA);
	STDMETHOD(RunControlPanel)(HWND, DWORD);
	STDMETHOD(Initialize)(HINSTANCE, DWORD, REFGUID);
	STDMETHOD(CreateEffect)(REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT *, LPUNKNOWN);
	STDMETHOD(EnumEffects)(LPDIENUMEFFECTSCALLBACKA, LPVOID, DWORD);
	STDMETHOD(GetEffectInfo)(LPDIEFFECTINFOA, REFGUID);
	STDMETHOD(GetForceFeedbackState)(LPDWORD);
	STDMETHOD(SendForceFeedbackCommand)(DWORD);
	STDMETHOD(EnumCreatedEffectObjects)(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD);
	STDMETHOD(Escape)(LPDIEFFESCAPE);
	STDMETHOD(Poll)();
	STDMETHOD(SendDeviceData)(DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD);
	STDMETHOD(EnumEffectsInFile)(LPCSTR, LPDIENUMEFFECTSINFILECALLBACK, LPVOID, DWORD);
	STDMETHOD(WriteEffectToFile)(LPCSTR, DWORD, LPDIFILEEFFECT, DWORD);
	STDMETHOD(BuildActionMap)(LPDIACTIONFORMATA, LPCSTR, DWORD);
	STDMETHOD(SetActionMap)(LPDIACTIONFORMATA, LPCSTR, DWORD);
	STDMETHOD(GetImageInfo)(LPDIDEVICEIMAGEINFOHEADERA);
};

IMPLEMENT_IUNKNOWN_FOR(my_IDirectInputDevice8A);

HRESULT my_IDirectInputDevice8A::GetCapabilities(
	LPDIDEVCAPS lpDIDevCaps
)
{
	return pOrig->GetCapabilities(lpDIDevCaps);
}

HRESULT my_IDirectInputDevice8A::EnumObjects(
	LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback,
	LPVOID pvRef,
	DWORD dwFlags
)
{
	return pOrig->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT my_IDirectInputDevice8A::GetProperty(
	REFGUID rguidProp,
	LPDIPROPHEADER pdiph
)
{
	return pOrig->GetProperty(rguidProp, pdiph);
}

HRESULT my_IDirectInputDevice8A::SetProperty(
	REFGUID rguidProp,
	LPCDIPROPHEADER pdiph
)
{
	return pOrig->SetProperty(rguidProp, pdiph);
}

HRESULT my_IDirectInputDevice8A::Acquire()
{
	return pOrig->Acquire();
}

HRESULT my_IDirectInputDevice8A::Unacquire()
{
	return pOrig->Unacquire();
}

HRESULT my_IDirectInputDevice8A::GetDeviceState(
	DWORD cbData,
	LPVOID lpvData
)
{
	return pOrig->GetDeviceState(cbData, lpvData);
}

HRESULT my_IDirectInputDevice8A::GetDeviceData(
	DWORD cbObjectData,
	LPDIDEVICEOBJECTDATA rgdod,
	LPDWORD pdwInOut,
	DWORD dwFlags
)
{
	return pOrig->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT my_IDirectInputDevice8A::SetDataFormat(
	LPCDIDATAFORMAT lpdf
)
{
	return pOrig->SetDataFormat(lpdf);
}

HRESULT my_IDirectInputDevice8A::SetEventNotification(
	HANDLE hEvent
)
{
	return pOrig->SetEventNotification(hEvent);
}

HRESULT my_IDirectInputDevice8A::SetCooperativeLevel(
	HWND hWnd,
	DWORD dwFlags
)
{
	return pOrig->SetCooperativeLevel(hWnd, dwFlags);
}

HRESULT my_IDirectInputDevice8A::GetObjectInfo(
	LPDIDEVICEOBJECTINSTANCEA pdidoi,
	DWORD dwObj,
	DWORD dwHow
)
{
	return pOrig->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT my_IDirectInputDevice8A::GetDeviceInfo(
	LPDIDEVICEINSTANCEA pdidi
)
{
	return pOrig->GetDeviceInfo(pdidi);
}

HRESULT my_IDirectInputDevice8A::RunControlPanel(
	HWND hWndOwner,
	DWORD dwFlags
)
{
	return pOrig->RunControlPanel(hWndOwner, dwFlags);
}

HRESULT my_IDirectInputDevice8A::Initialize(
	HINSTANCE hInst,
	DWORD dwVersion,
	REFGUID rguid
)
{
	return pOrig->Initialize(hInst, dwVersion, rguid);
}

HRESULT my_IDirectInputDevice8A::CreateEffect(
	REFGUID rguid,
	LPCDIEFFECT lpeff,
	LPDIRECTINPUTEFFECT * ppdeff,
	LPUNKNOWN pUnkOuter
)
{
	return pOrig->CreateEffect(rguid, lpeff, ppdeff, pUnkOuter);
}

HRESULT my_IDirectInputDevice8A::EnumEffects(
	LPDIENUMEFFECTSCALLBACKA lpCallback,
	LPVOID pvRef,
	DWORD dwEffType
	)
{
	return pOrig->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT my_IDirectInputDevice8A::GetEffectInfo(
	LPDIEFFECTINFOA pdei,
	REFGUID rguid
)
{
	return pOrig->GetEffectInfo(pdei, rguid);
}

HRESULT my_IDirectInputDevice8A::GetForceFeedbackState(
	LPDWORD pdwOut
)
{
	return pOrig->GetForceFeedbackState(pdwOut);
}

HRESULT my_IDirectInputDevice8A::SendForceFeedbackCommand(
	DWORD dwFlags
)
{
	return pOrig->SendForceFeedbackCommand(dwFlags);
}

HRESULT my_IDirectInputDevice8A::EnumCreatedEffectObjects(
	LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback,
	LPVOID pvRef,
	DWORD fl
)
{
	return pOrig->EnumCreatedEffectObjects(lpCallback, pvRef, fl);
}

HRESULT my_IDirectInputDevice8A::Escape(
	LPDIEFFESCAPE pesc
)
{
	return pOrig->Escape(pesc);
}

HRESULT my_IDirectInputDevice8A::Poll()
{
	return pOrig->Poll();
}

HRESULT my_IDirectInputDevice8A::SendDeviceData(
	DWORD cbObjectData,
	LPCDIDEVICEOBJECTDATA rgdod,
	LPDWORD pdwInOut,
	DWORD fl
)
{
	return pOrig->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT my_IDirectInputDevice8A::EnumEffectsInFile(
	LPCSTR lpszFileName,
	LPDIENUMEFFECTSINFILECALLBACK pec,
	LPVOID pvRef,
	DWORD dwFlags
)
{
	return pOrig->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT my_IDirectInputDevice8A::WriteEffectToFile(
	LPCSTR lpszFileName,
	DWORD dwEntries,
	LPDIFILEEFFECT rgDiFileEft,
	DWORD dwFlags
)
{
	return pOrig->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HRESULT my_IDirectInputDevice8A::BuildActionMap(
	LPDIACTIONFORMATA lpdiaf,
	LPCSTR lpszUserName,
	DWORD dwFlags
)
{
	return pOrig->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
}

HRESULT my_IDirectInputDevice8A::SetActionMap(
	LPDIACTIONFORMATA lpdiActionFormat,
	LPCSTR lpszUserName,
	DWORD dwFlags
)
{
	return pOrig->SetActionMap(lpdiActionFormat, lpszUserName, dwFlags);
}

HRESULT my_IDirectInputDevice8A::GetImageInfo(
	LPDIDEVICEIMAGEINFOHEADERA lpdiDevImageInfoHeader
)
{
	return pOrig->GetImageInfo(lpdiDevImageInfoHeader);
}
/// --------------------

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
	IDirectInputDevice8A *pOrigDevice;
	HRESULT ret = pOrig->CreateDevice(rguid, &pOrigDevice, pUnkOuter);
	if(SUCCEEDED(ret)) {
		*lplpDirectInputDevice = new my_IDirectInputDevice8A(pOrigDevice);
	}
	return ret;
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
