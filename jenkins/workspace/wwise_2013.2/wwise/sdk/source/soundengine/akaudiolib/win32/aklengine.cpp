// File Line: 80
// RVA: 0xA458B0
__int64 __fastcall CAkMMNotificationClient::QueryInterface(
        CAkMMNotificationClient *this,
        _GUID *riid,
        CAkMMNotificationClient **ppvObject)
{
  if ( *(_QWORD *)&riid->Data1 == *(_QWORD *)&IID_IUnknown.Data1
    && *(_QWORD *)riid->Data4 == *(_QWORD *)IID_IUnknown.Data4
    || *(_QWORD *)&riid->Data1 == *(_QWORD *)&GUID_7991eec9_7e89_4d85_8390_6c703cec60c0.Data1
    && *(_QWORD *)riid->Data4 == *(_QWORD *)GUID_7991eec9_7e89_4d85_8390_6c703cec60c0.Data4 )
  {
    *ppvObject = this;
    return 0i64;
  }
  else
  {
    *ppvObject = 0i64;
    return 2147500034i64;
  }
}

// File Line: 99
// RVA: 0xA454E0
__int64 __fastcall CAkMMNotificationClient::AddRef(CAkMMNotificationClient *this)
{
  __int64 result; // rax

  result = this->m_cRef + 1;
  this->m_cRef = result;
  return result;
}

// File Line: 104
// RVA: 0xA45A60
__int64 __fastcall CAkMMNotificationClient::Release(CAkMMNotificationClient *this)
{
  bool v1; // zf
  unsigned int m_cRef; // esi
  int v4; // ebx

  v1 = this->m_cRef-- == 1;
  m_cRef = this->m_cRef;
  if ( v1 )
  {
    v4 = g_LEngineDefaultPoolId;
    this->vfptr = (IUnknownVtbl *)&CAkMMNotificationClient::`vftable;
    ((void (__fastcall *)(IMMDeviceEnumerator *, CAkMMNotificationClient *))this->m_pEnumerator->vfptr[2].AddRef)(
      this->m_pEnumerator,
      this);
    this->m_pEnumerator->vfptr->Release(this->m_pEnumerator);
    AK::MemoryMgr::Free(v4, this);
  }
  return m_cRef;
}

// File Line: 120
// RVA: 0xA45820
__int64 __fastcall CAkMMNotificationClient::OnDefaultDeviceChanged(
        CAkMMNotificationClient *this,
        __MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 flow,
        __MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002 role,
        const wchar_t *pwstrDefaultDeviceId)
{
  if ( flow == eRender && role == eMultimedia )
  {
    CAkLEngine::m_bResetAudioDevice = 1;
    if ( AK::SoundEngine::IsInitialized() )
      CAkAudioThread::WakeupEventsConsumer(&g_pAudioMgr->m_audioThread);
  }
  return 0i64;
}

// File Line: 146
// RVA: 0xA45590
IDirectSound8 *__fastcall AK::GetDirectSoundInstance()
{
  if ( g_pAkSink )
    return g_pAkSink->vfptr->GetDirectSoundInstance(g_pAkSink);
  else
    return 0i64;
}

// File Line: 154
// RVA: 0xA45500
void __fastcall CAkLEngine::GetDefaultPlatformInitSettings(AkPlatformInitSettings *out_pPlatformSettings)
{
  HWND__ *ForegroundWindow; // rax

  out_pPlatformSettings->hWnd = 0i64;
  *(_QWORD *)&out_pPlatformSettings->threadLEngine.nPriority = 0i64;
  *(_QWORD *)&out_pPlatformSettings->threadLEngine.uStackSize = 0i64;
  *(_QWORD *)&out_pPlatformSettings->threadBankManager.dwAffinityMask = 0i64;
  *(_QWORD *)&out_pPlatformSettings->threadMonitor.nPriority = 0i64;
  *(_QWORD *)&out_pPlatformSettings->threadMonitor.uStackSize = 0i64;
  *(_QWORD *)&out_pPlatformSettings->fLEngineDefaultPoolRatioThreshold = 0i64;
  *(_QWORD *)&out_pPlatformSettings->eAudioQuality = 0i64;
  out_pPlatformSettings->pXAudio2 = 0i64;
  ForegroundWindow = GetForegroundWindow();
  *(_QWORD *)&out_pPlatformSettings->threadLEngine.nPriority = 1i64;
  out_pPlatformSettings->hWnd = ForegroundWindow;
  *(_QWORD *)&out_pPlatformSettings->threadLEngine.uStackSize = 0x10000i64;
  out_pPlatformSettings->threadBankManager.dwAffinityMask = 0;
  out_pPlatformSettings->threadBankManager.uStackSize = 0x10000;
  out_pPlatformSettings->uLEngineDefaultPoolSize = 0x1000000;
  out_pPlatformSettings->uNumRefillsInVoice = 4;
  out_pPlatformSettings->fLEngineDefaultPoolRatioThreshold = 1.0;
  out_pPlatformSettings->eAudioQuality = AkSoundQuality_High;
  out_pPlatformSettings->bGlobalFocus = 1;
  *(_QWORD *)&out_pPlatformSettings->threadMonitor.nPriority = 1i64;
  out_pPlatformSettings->threadMonitor.uStackSize = 0x10000;
  out_pPlatformSettings->pXAudio2 = 0i64;
}

// File Line: 191
// RVA: 0xA456D0
__int64 __fastcall CAkLEngine::Init()
{
  unsigned int v0; // ecx
  AKRESULT v2; // ebx

  v0 = 48000;
  if ( g_PDSettings.eAudioQuality == AkSoundQuality_Low )
    v0 = 24000;
  AkAudioLibSettings::SetSampleFrequency(v0);
  CAkLEngine::m_bCoInitializeSucceeded = CoInitializeEx(0i64, 0) >= 0;
  CAkLEngine::m_eventProcess = CreateEventW(0i64, 0, 0, 0i64);
  if ( !CAkLEngine::m_eventProcess )
    return 2i64;
  v2 = CAkLEngine::SoftwareInit();
  if ( v2 == AK_Success )
    CAkLEngine::RegisterDeviceChange();
  return (unsigned int)v2;
}

// File Line: 233
// RVA: 0xA45AD0
void CAkLEngine::Term(void)
{
  CAkLEngine::UnregisterDeviceChange();
  CAkLEngine::SoftwareTerm();
  if ( CAkLEngine::m_bCoInitializeSucceeded )
  {
    CoUninitialize();
    CAkLEngine::m_bCoInitializeSucceeded = 0;
  }
  if ( CAkLEngine::m_eventProcess )
    CloseHandle(CAkLEngine::m_eventProcess);
  CAkLEngine::m_eventProcess = 0i64;
}

// File Line: 249
// RVA: 0xA455B0
__int64 __fastcall CAkLEngine::GetNumBufferNeededAndSubmit()
{
  int v0; // ecx
  CAkSink *v1; // rax
  CAkSink *v2; // rdi
  int v3; // ebx
  CAkSink *v4; // rbx
  unsigned int v6; // [rsp+30h] [rbp+8h] BYREF

  v0 = uNumRetries;
  v6 = 0;
  if ( !uNumRetries )
    goto LABEL_7;
  --uNumRetries;
  if ( v0 - 1 != 20 * ((v0 - 1) / 20) )
    goto LABEL_7;
  v1 = CAkSink::Create(&g_settings.settingsMainOutput, g_settings.eMainOutputType, 0);
  v2 = v1;
  if ( !v1 )
    goto LABEL_7;
  if ( (*(unsigned int (__fastcall **)(CAkSink *))v1->vfptr->gap8)(v1) != 1 )
  {
    v2->vfptr->Term(v2);
    v3 = g_LEngineDefaultPoolId;
    v2->vfptr->__vecDelDtor(v2, 0);
    AK::MemoryMgr::Free(v3, v2);
LABEL_7:
    v2 = g_pAkSink;
    goto LABEL_8;
  }
  CAkOutputMgr::ReplaceSink(0i64, v2);
  g_pAkSink = v2;
  uNumRetries = 0;
LABEL_8:
  if ( v2->vfptr->IsDataNeeded(v2, &v6) != AK_Success || CAkLEngine::m_bResetAudioDevice )
  {
    CAkLEngine::m_bResetAudioDevice = 0;
    v4 = CAkSink::Create(&g_settings.settingsMainOutput, AkSink_Dummy, 0);
    CAkOutputMgr::ReplaceSink(0i64, v4);
    g_pAkSink = v4;
    (*(void (__fastcall **)(CAkSink *))v4->vfptr->gap8)(v4);
    uNumRetries = 200;
  }
  return v6;
}

// File Line: 311
// RVA: 0xA45860
void CAkLEngine::Perform(void)
{
  _mm_setcsr(_mm_getcsr() | 0x8000);
  CAkLEngine::SoftwarePerform();
  _mm_setcsr(_mm_getcsr() & 0x8000 | _mm_getcsr() & 0xFFFF7FFF);
}

// File Line: 330
// RVA: 0xA45AC0
void CAkLEngine::StartVoice(void)
{
  (*(void (__fastcall **)(CAkSink *))g_pAkSink->vfptr->gap8)(g_pAkSink);
}

// File Line: 337
// RVA: 0xA45750
LRESULT __fastcall CAkLEngine::InternalWindowProc(HWND in_hWnd, UINT in_unMsg, WPARAM in_wParam, LPARAM in_lParam)
{
  if ( in_unMsg == 537
    && in_wParam == 0x8000
    && g_pAudioMgr
    && (*(_QWORD *)(in_lParam + 12) == *(_QWORD *)&GUID_6994ad04_93ef_11d0_a3cc_00a0c9223196.Data1
     && *(_QWORD *)(in_lParam + 20) == *(_QWORD *)GUID_6994ad04_93ef_11d0_a3cc_00a0c9223196.Data4
     || *(_QWORD *)(in_lParam + 12) == *(_QWORD *)&GUID_65e8773e_8f56_11d0_a3b9_00a0c9223196.Data1
     && *(_QWORD *)(in_lParam + 20) == *(_QWORD *)GUID_65e8773e_8f56_11d0_a3b9_00a0c9223196.Data4) )
  {
    CAkLEngine::m_bResetAudioDevice = 1;
    if ( AK::SoundEngine::IsInitialized() )
      CAkAudioThread::WakeupEventsConsumer(&g_pAudioMgr->m_audioThread);
  }
  return CallWindowProcW(CAkLEngine::m_WndProc, in_hWnd, in_unMsg, in_wParam, in_lParam);
}

// File Line: 361
// RVA: 0xA45900
void CAkLEngine::RegisterDeviceChange(void)
{
  CAkMMNotificationClient *v0; // rbx
  IMMDeviceEnumerator *v1; // rcx
  IID riid; // [rsp+30h] [rbp-40h] BYREF
  IID rclsid; // [rsp+40h] [rbp-30h] BYREF
  __int64 NotificationFilter; // [rsp+50h] [rbp-20h] BYREF
  int v5; // [rsp+58h] [rbp-18h]
  unsigned int Data1; // [rsp+5Ch] [rbp-14h]
  __int64 v7; // [rsp+60h] [rbp-10h]
  __int64 v8; // [rsp+68h] [rbp-8h]
  LPVOID ppv; // [rsp+80h] [rbp+10h] BYREF

  rclsid = GUID_bcde0395_e52f_467c_8e3d_c4579291692e;
  riid = GUID_a95664d2_9614_4f35_a746_de8db63617e6;
  if ( CoCreateInstance(&rclsid, 0i64, 0x17u, &riid, &ppv) || !ppv )
  {
    v5 = 0;
    Data1 = GUID_00000000_0000_0000_0000_000000000000.Data1;
    NotificationFilter = 0x500000020i64;
    v7 = *(_QWORD *)&GUID_00000000_0000_0000_0000_000000000000.Data2;
    v8 = *(unsigned int *)&GUID_00000000_0000_0000_0000_000000000000.Data4[4];
    CAkLEngine::m_hDevNotify = RegisterDeviceNotificationW(g_PDSettings.hWnd, &NotificationFilter, 4u);
    CAkLEngine::m_WndProc = (WNDPROC)SetWindowLongPtrW(g_PDSettings.hWnd, -4, (LONG_PTR)CAkLEngine::InternalWindowProc);
  }
  else
  {
    v0 = (CAkMMNotificationClient *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x18ui64);
    if ( v0 )
    {
      v1 = (IMMDeviceEnumerator *)ppv;
      v0->m_cRef = 1;
      v0->m_pEnumerator = v1;
      v0->vfptr = (IUnknownVtbl *)&CAkMMNotificationClient::`vftable;
      v1->vfptr->AddRef(v1);
      ((void (__fastcall *)(IMMDeviceEnumerator *, CAkMMNotificationClient *))v0->m_pEnumerator->vfptr[2].QueryInterface)(
        v0->m_pEnumerator,
        v0);
      CAkLEngine::m_pMMNotifClient = v0;
    }
    else
    {
      CAkLEngine::m_pMMNotifClient = 0i64;
    }
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16i64))(ppv);
  }
}

// File Line: 396
// RVA: 0xA45B20
void CAkLEngine::UnregisterDeviceChange(void)
{
  if ( CAkLEngine::m_pMMNotifClient )
  {
    CAkLEngine::m_pMMNotifClient->vfptr->Release(CAkLEngine::m_pMMNotifClient);
    CAkLEngine::m_pMMNotifClient = 0i64;
  }
  else
  {
    if ( CAkLEngine::m_hDevNotify )
      UnregisterDeviceNotification(CAkLEngine::m_hDevNotify);
    if ( (LRESULT (__fastcall *)(HWND, UINT, WPARAM, LPARAM))GetWindowLongPtrW(g_PDSettings.hWnd, -4) == CAkLEngine::InternalWindowProc )
      SetWindowLongPtrW(g_PDSettings.hWnd, -4, (LONG_PTR)CAkLEngine::m_WndProc);
  }
}

// File Line: 416
// RVA: 0xA454F0
void __fastcall CAkLEngine::GetDefaultOutputSettings(AkSinkType in_eSinkType, AkOutputSettings *out_settings)
{
  CAkLEngine::GetDefaultOutputSettingsCommon(out_settings);
}

