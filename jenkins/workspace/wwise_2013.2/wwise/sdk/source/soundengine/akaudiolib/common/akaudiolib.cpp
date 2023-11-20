// File Line: 103
// RVA: 0x15BDF10
__int64 dynamic_initializer_for__g_csMain__()
{
  InitializeCriticalSection(&g_csMain.m_csLock);
  return atexit(dynamic_atexit_destructor_for__g_csMain__);
}

// File Line: 106
// RVA: 0x15BDF00
__int64 dynamic_initializer_for__g_aBehavioralExtensions__()
{
  return atexit(dynamic_atexit_destructor_for__g_aBehavioralExtensions__);
}

// File Line: 191
// RVA: 0xA420C0
signed __int64 __fastcall AK::SoundEngine::GetIDFromString(const wchar_t *in_pszString)
{
  signed __int64 result; // rax
  unsigned __int64 v2; // rbx
  signed __int64 v3; // rax
  signed __int64 v4; // rax
  int v5; // eax
  unsigned __int64 v6; // rdi
  char v7; // cl
  char *v8; // rdx
  char *v9; // r8
  int v10; // ecx
  char MultiByteStr[259]; // [rsp+40h] [rbp-118h]
  char v12; // [rsp+143h] [rbp-15h]

  if ( !in_pszString )
    return 0i64;
  v2 = -1i64;
  v3 = -1i64;
  do
    ++v3;
  while ( in_pszString[v3] );
  if ( (unsigned int)(v3 + 1) >= 0x103 )
  {
    v5 = 259;
  }
  else
  {
    v4 = -1i64;
    do
      ++v4;
    while ( in_pszString[v4] );
    v5 = v4 + 1;
  }
  v6 = 0i64;
  WideCharToMultiByte(0, 0, in_pszString, v5, MultiByteStr, 259, 0i64, 0i64);
  v12 = 0;
  do
    ++v2;
  while ( MultiByteStr[v2] );
  if ( v2 )
  {
    do
    {
      v7 = MultiByteStr[v6];
      if ( (unsigned __int8)(v7 - 65) <= 0x19u )
        MultiByteStr[v6] = v7 + 32;
      ++v6;
    }
    while ( v6 < v2 );
  }
  v8 = MultiByteStr;
  v9 = &MultiByteStr[(unsigned int)v2];
  result = 0x811C9DC5i64;
  if ( MultiByteStr < v9 )
  {
    do
    {
      v10 = (unsigned __int8)*v8++;
      result = v10 ^ (unsigned int)(0x1000193 * result);
    }
    while ( v8 < v9 );
  }
  return result;
}

// File Line: 213
// RVA: 0xA41FD0
signed __int64 __fastcall AK::SoundEngine::GetIDFromString(const char *in_pszString)
{
  const char *v1; // rsi
  signed __int64 result; // rax
  unsigned __int64 v3; // rbx
  signed __int64 v4; // rax
  unsigned __int64 v5; // rdi
  signed __int64 v6; // rdi
  unsigned __int64 v7; // rcx
  char v8; // dl
  char *v9; // r8
  char *v10; // rdx
  int v11; // ecx
  char _Dst[280]; // [rsp+20h] [rbp-118h]

  v1 = in_pszString;
  if ( !in_pszString )
    return 0i64;
  v3 = -1i64;
  v4 = -1i64;
  do
    ++v4;
  while ( in_pszString[v4] );
  v5 = 259i64;
  if ( (unsigned __int64)(v4 + 1) <= 259 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( in_pszString[v6] );
    v5 = v6 + 1;
  }
  strncpy_s(_Dst, 260ui64, in_pszString, v5);
  _Dst[v5] = 0;
  do
    ++v3;
  while ( v1[v3] );
  v7 = 0i64;                                    // Converts string to lowercase
  if ( v3 )
  {
    do
    {
      v8 = _Dst[v7];
      if ( (unsigned __int8)(v8 - 0x41) <= 0x19u )
        _Dst[v7] = v8 + 0x20;
      ++v7;
    }
    while ( v7 < v3 );
  }
  v9 = &_Dst[(unsigned int)v3];
  v10 = _Dst;
  for ( result = 0x811C9DC5i64; v10 < v9; result = v11 ^ (unsigned int)(0x1000193 * result) )
    v11 = (unsigned __int8)*v10++;
  return result;
}

// File Line: 230
// RVA: 0xA42490
_BOOL8 __fastcall AK::SoundEngine::IsInitialized()
{
  return s_bInitialized;
}

// File Line: 238
// RVA: 0xA421F0
signed __int64 __fastcall AK::SoundEngine::Init(AkInitSettings *in_pSettings, AkPlatformInitSettings *in_pPlatformSettings)
{
  AkPlatformInitSettings *v2; // rbx
  AkInitSettings *v3; // rdi
  unsigned int v5; // esi
  AKRESULT v6; // ebx
  int v7; // eax
  AK::SoundEngine *v8; // rcx
  char Dest; // [rsp+30h] [rbp-38h]
  __int64 v10; // [rsp+31h] [rbp-37h]
  __int64 v11; // [rsp+39h] [rbp-2Fh]
  __int64 v12; // [rsp+41h] [rbp-27h]
  __int64 v13; // [rsp+49h] [rbp-1Fh]
  __int16 v14; // [rsp+51h] [rbp-17h]
  char v15; // [rsp+53h] [rbp-15h]

  v2 = in_pPlatformSettings;
  v3 = in_pSettings;
  g_eVolumeThresholdPriority = 3;
  g_eNumVoicesPriority = 3;
  if ( !AK::MemoryMgr::IsInitialized() )
    return 74i64;
  if ( !AK::IAkStreamMgr::m_pStreamMgr )
    return 75i64;
  v5 = 0x1000000;
  if ( v3 )
  {
    *(_OWORD *)&g_settings.pfnAssertHook = *(_OWORD *)&v3->pfnAssertHook;
    *(_OWORD *)&in_ulMemSize = *(_OWORD *)&v3->uDefaultPoolSize;
    unk_14249E980 = *(_OWORD *)&v3->bEnableGameSyncPreparation;
    *(_OWORD *)&in_eSinkType = *(_OWORD *)&v3->eMainOutputType;
  }
  else
  {
    g_settings.pfnAssertHook = 0i64;
    in_uMaxNumPath = 255;
    in_uMaxNumTransitions = 255;
    unk_14249E974 = (_DWORD)FLOAT_1_0;
    in_ulMemSize = 0x1000000;
    unk_14249E978 = 0x40000;
    in_PoolId = -1;
    unk_14249E980 = 0;
    unk_14249E984 = 1;
    unk_14249E988 = 0x40000;
    unk_14249E98C = 0x10000i64;
    CAkLEngine::GetDefaultOutputSettings(0, &in_outputSettings);
  }
  g_pAssertHook = g_settings.pfnAssertHook;
  CAkLEngine::ApplyGlobalSettings(v2);
  v6 = 2;
  if ( !s_bInitialized )
  {
    if ( g_DefaultPoolId == -1 )
    {
      if ( in_ulMemSize > 0x40 )
        v5 = in_ulMemSize;
      v7 = AK::MemoryMgr::CreatePool(0i64, v5, 0x40u, 1u, 0);
      g_DefaultPoolId = v7;
      AkFXMemAlloc::m_instanceUpper.m_poolId = v7;
      if ( v7 == -1 )
      {
        v6 = 52;
        goto LABEL_18;
      }
    }
    v6 = (unsigned int)AK::SoundEngine::PreInit(v3);
    if ( v6 != 1 || (v6 = AK::SoundEngine::InitRenderer(), v6 != 1) )
    {
      AK::SoundEngine::Term(v8);
      v7 = g_DefaultPoolId;
LABEL_18:
      if ( !s_bInitialized && v7 != -1 )
      {
        AK::MemoryMgr::DestroyPool(v7);
        g_DefaultPoolId = -1;
      }
      goto LABEL_21;
    }
    s_bInitialized = 1;
  }
LABEL_21:
  Dest = 0;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0;
  v15 = 0;
  strncpy(&Dest, "779AD1D9-3419-4cbf-933B-B038DF5A2818", 0x24ui64);
  return (unsigned int)v6;
}

// File Line: 326
// RVA: 0xA41F60
void __fastcall AK::SoundEngine::GetDefaultInitSettings(AkInitSettings *out_settings)
{
  out_settings->uMaxNumPaths = 255;
  out_settings->uMaxNumTransitions = 255;
  out_settings->uDefaultPoolSize = 0x1000000;
  out_settings->fDefaultPoolRatioThreshold = 1.0;
  out_settings->pfnAssertHook = 0i64;
  out_settings->bEnableGameSyncPreparation = 0;
  out_settings->uCommandQueueSize = 0x40000;
  out_settings->uPrepareEventMemoryPoolID = -1;
  out_settings->uContinuousPlaybackLookAhead = 1;
  out_settings->uMonitorPoolSize = 0x40000;
  *(_QWORD *)&out_settings->uMonitorQueuePoolSize = 0x10000i64;
  CAkLEngine::GetDefaultOutputSettings(0, &out_settings->settingsMainOutput);
}

// File Line: 349
// RVA: 0xA41FC0
void __fastcall AK::SoundEngine::GetDefaultPlatformInitSettings(AkPlatformInitSettings *out_platformSettings)
{
  CAkLEngine::GetDefaultPlatformInitSettings(out_platformSettings);
}

// File Line: 354
// RVA: 0xA43870
void __fastcall AK::SoundEngine::Term(AK::SoundEngine *this)
{
  _BOOL8 v1; // rcx
  __int64 i; // rbx
  CAkAudioMgr *v3; // rbx
  int v4; // edi
  CAkBankMgr *v5; // rbx
  int v6; // edi
  CAkStateMgr *v7; // rbx
  int v8; // edi
  CAkPathManager *v9; // rbx
  int v10; // edi
  CAkTransitionManager *v11; // rbx
  int v12; // edi
  CAkRegistryMgr *v13; // rbx
  int v14; // edi
  CAkPlayingMgr *v15; // rbx
  int v16; // edi
  void *v17; // rcx
  CAkPositionRepository *v18; // rbx
  int v19; // edi
  CAkRTPCMgr *v20; // rbx
  int v21; // edi
  CAkAudioLibIndex *v22; // rbx
  int v23; // edi

  if ( CAkFeedbackDeviceMgr::s_pSingleton )
    CAkFeedbackDeviceMgr::Stop(CAkFeedbackDeviceMgr::s_pSingleton);
  if ( g_pAudioMgr )
    CAkAudioMgr::Stop(g_pAudioMgr);
  if ( g_pBankManager )
    CAkBankMgr::StopThread(g_pBankManager);
  CAkLEngine::Stop();
  for ( i = g_aBehavioralExtensions.m_uLength - 1; i >= 0; g_aBehavioralExtensions.m_pItems[i--](v1) )
    LOBYTE(v1) = 1;
  if ( g_aBehavioralExtensions.m_pItems )
  {
    g_aBehavioralExtensions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, g_aBehavioralExtensions.m_pItems);
    g_aBehavioralExtensions.m_pItems = 0i64;
    g_aBehavioralExtensions.m_ulReserved = 0;
  }
  CAkURenderer::Term();
  if ( g_pAudioMgr )
  {
    CAkAudioMgr::Term(g_pAudioMgr);
    v3 = g_pAudioMgr;
    v4 = g_DefaultPoolId;
    if ( g_pAudioMgr )
    {
      CAkAudioMgr::~CAkAudioMgr(g_pAudioMgr);
      AK::MemoryMgr::Free(v4, v3);
    }
    g_pAudioMgr = 0i64;
  }
  if ( g_pBankManager )
  {
    CAkBankMgr::Term(g_pBankManager);
    v5 = g_pBankManager;
    v6 = g_DefaultPoolId;
    if ( g_pBankManager )
    {
      CAkBankMgr::~CAkBankMgr(g_pBankManager);
      AK::MemoryMgr::Free(v6, v5);
    }
    g_pBankManager = 0i64;
  }
  if ( g_pIndex )
  {
    CAkAudioLibIndex::ReleaseTempObjects(g_pIndex);
    CAkAudioLibIndex::ReleaseDynamicSequences(g_pIndex);
  }
  if ( g_pStateMgr )
  {
    CAkStateMgr::Term(g_pStateMgr);
    v7 = g_pStateMgr;
    v8 = g_DefaultPoolId;
    if ( g_pStateMgr )
    {
      CAkStateMgr::~CAkStateMgr(g_pStateMgr);
      AK::MemoryMgr::Free(v8, v7);
    }
    g_pStateMgr = 0i64;
  }
  if ( g_pPathManager )
  {
    CAkPathManager::Term(g_pPathManager);
    v9 = g_pPathManager;
    v10 = g_DefaultPoolId;
    if ( g_pPathManager )
    {
      _((AMD_HD3D *)g_pPathManager);
      AK::MemoryMgr::Free(v10, v9);
    }
    g_pPathManager = 0i64;
  }
  if ( g_pTransitionManager )
  {
    CAkTransitionManager::Term(g_pTransitionManager);
    v11 = g_pTransitionManager;
    v12 = g_DefaultPoolId;
    if ( g_pTransitionManager )
    {
      _((AMD_HD3D *)g_pTransitionManager);
      AK::MemoryMgr::Free(v12, v11);
    }
    g_pTransitionManager = 0i64;
  }
  if ( g_pRegistryMgr )
  {
    CAkRegistryMgr::Term(g_pRegistryMgr);
    v13 = g_pRegistryMgr;
    v14 = g_DefaultPoolId;
    if ( g_pRegistryMgr )
    {
      _((AMD_HD3D *)g_pRegistryMgr);
      AK::MemoryMgr::Free(v14, v13);
    }
    g_pRegistryMgr = 0i64;
  }
  if ( g_pPlayingMgr )
  {
    _((AMD_HD3D *)g_pPlayingMgr);
    v15 = g_pPlayingMgr;
    v16 = g_DefaultPoolId;
    if ( g_pPlayingMgr )
    {
      CAkBusCallbackMgr::~CAkBusCallbackMgr(&g_pPlayingMgr->m_BusCallbackMgr);
      v17 = v15->m_CallbackEvent.m_Event;
      if ( v17 )
        CloseHandle(v17);
      DeleteCriticalSection(&v15->m_csMapLock.m_csLock);
      AK::MemoryMgr::Free(v16, v15);
    }
    g_pPlayingMgr = 0i64;
  }
  if ( g_pPositionRepository )
  {
    CAkLimiter::Term((CAkSegmentInfoRepository *)g_pPositionRepository);
    v18 = g_pPositionRepository;
    v19 = g_DefaultPoolId;
    if ( g_pPositionRepository )
    {
      DeleteCriticalSection(&g_pPositionRepository->m_lock.m_csLock);
      AK::MemoryMgr::Free(v19, v18);
    }
    g_pPositionRepository = 0i64;
  }
  if ( g_pEnvironmentMgr )
  {
    CAkEnvironmentsMgr::Term(g_pEnvironmentMgr);
    if ( g_pEnvironmentMgr )
      AK::MemoryMgr::Free(g_DefaultPoolId, g_pEnvironmentMgr);
    g_pEnvironmentMgr = 0i64;
  }
  if ( g_pRTPCMgr )
  {
    CAkRTPCMgr::Term(g_pRTPCMgr);
    v20 = g_pRTPCMgr;
    v21 = g_DefaultPoolId;
    if ( g_pRTPCMgr )
    {
      _((AMD_HD3D *)g_pRTPCMgr);
      AK::MemoryMgr::Free(v21, v20);
    }
    g_pRTPCMgr = 0i64;
  }
  if ( g_pIndex )
  {
    _((AMD_HD3D *)g_pIndex);
    v22 = g_pIndex;
    v23 = g_DefaultPoolId;
    if ( g_pIndex )
    {
      CAkAudioLibIndex::~CAkAudioLibIndex(g_pIndex);
      AK::MemoryMgr::Free(v23, v22);
    }
    g_pIndex = 0i64;
  }
  if ( g_aBehavioralExtensions.m_pItems )
  {
    g_aBehavioralExtensions.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, g_aBehavioralExtensions.m_pItems);
    g_aBehavioralExtensions.m_pItems = 0i64;
    g_aBehavioralExtensions.m_ulReserved = 0;
  }
  if ( g_DefaultPoolId != -1 )
  {
    AK::MemoryMgr::DestroyPool(g_DefaultPoolId);
    g_DefaultPoolId = -1;
  }
  s_bInitialized = 0;
}

// File Line: 493
// RVA: 0xA42E80
signed __int64 __fastcall AK::SoundEngine::RenderAudio()
{
  return CAkAudioMgr::RenderAudio(g_pAudioMgr);
}

// File Line: 506
// RVA: 0xA42D50
AKRESULT __fastcall AK::SoundEngine::RegisterPlugin(AkPluginType in_eType, unsigned int in_ulCompanyID, unsigned int in_ulPluginID, AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *), AK::IAkPluginParam *(__fastcall *in_pCreateParamFunc)(AK::IAkPluginMemAlloc *))
{
  return CAkEffectsMgr::RegisterPlugin(in_eType, in_ulCompanyID, in_ulPluginID, in_pCreateFunc, in_pCreateParamFunc);
}

// File Line: 516
// RVA: 0xA42CD0
AKRESULT __fastcall AK::SoundEngine::RegisterCodec(unsigned int in_ulCompanyID, unsigned int in_ulPluginID, IAkSoftwareCodec *(__fastcall *in_pFileCreateFunc)(void *), IAkSoftwareCodec *(__fastcall *in_pBankCreateFunc)(void *))
{
  return CAkEffectsMgr::RegisterCodec(in_ulCompanyID, in_ulPluginID, in_pFileCreateFunc, in_pBankCreateFunc);
}

// File Line: 527
// RVA: 0xA432E0
__int64 __fastcall AK::SoundEngine::SetPosition(unsigned __int64 in_GameObj, AkSoundPosition *in_Position)
{
  __int128 v3; // xmm0
  void *v4; // xmm1_8
  unsigned __int16 v5; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( !in_GameObj )
    return 2i64;
  v3 = *(_OWORD *)&in_Position->Position.X;
  v4 = *(void **)&in_Position->Orientation.Y;
  in_rItem.type = 13;
  in_rItem.event.GameObjID = in_GameObj;
  *(_OWORD *)(&in_rItem.unreggameobj + 1) = v3;
  in_rItem.processMode.pUserData = v4;
  v5 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v5);
}

// File Line: 688
// RVA: 0xA43130
__int64 __fastcall AK::SoundEngine::SetListenerPosition(AkListenerPosition *in_Position, unsigned int in_ulIndex)
{
  unsigned int v2; // edi
  AkListenerPosition *v3; // rsi
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  unsigned __int16 v8; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v2 = in_ulIndex;
  v3 = in_Position;
  in_rItem.type = 16;
  v4 = AkMath::DotProduct(&in_Position->OrientationFront, &in_Position->OrientationTop);
  v5 = v4 * v3->OrientationTop.Z;
  v6 = v4 * v3->OrientationTop.Y;
  in_rItem.rtpc.Value = v3->OrientationFront.X - (float)(v4 * v3->OrientationTop.X);
  in_rItem.gameobjpos.Position.Position.X = v3->OrientationFront.Y - v6;
  *(_QWORD *)(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1) = __PAIR__(
                                                                            LODWORD(v3->OrientationTop.X),
                                                                            (float)(v3->OrientationFront.Z - v5));
  *(_QWORD *)((char *)&in_rItem.resetrtpcvalue + 20) = *(_QWORD *)&v3->OrientationTop.Y;
  AkMath::Normalise((AkVector *)&in_rItem.setstate.StateID);
  AkMath::Normalise((AkVector *)(&in_rItem.gameobjdrylevel + 1));
  in_rItem.rtpc.ID = v2;
  v7 = v3->Position.Y;
  in_rItem.eventAction.TargetPlayingID = LODWORD(v3->Position.X);
  in_rItem.event.CustomParam.pExternalSrcs = (AkExternalSourceArray *)__PAIR__(LODWORD(v3->Position.Z), LODWORD(v7));
  v8 = AkQueuedMsg::Sizeof_ListenerPosition();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v8);
}

// File Line: 769
// RVA: 0xA430F0
__int64 __fastcall AK::SoundEngine::SetListenerPipeline(unsigned int in_uIndex, bool in_bAudio, bool in_bFeedback)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.rtpc.ID = in_uIndex;
  in_rItem.listpipe.bAudio = in_bAudio;
  in_rItem.type = 26;
  in_rItem.listpipe.bFeedback = in_bFeedback;
  v3 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
}

// File Line: 788
// RVA: 0xA43340
__int64 __fastcall AK::SoundEngine::SetRTPCValue(unsigned int in_rtpcID, float in_value, unsigned __int64 in_gameObjectID, int in_uValueChangeDuration, AkCurveInterpolation in_eFadeCurve)
{
  unsigned __int16 v5; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.event.GameObjID = __PAIR__(LODWORD(in_value), in_rtpcID);
  in_rItem.rtpc.GameObjID = in_gameObjectID;
  if ( in_uValueChangeDuration )
  {
    in_rItem.event.CustomParam.customParam = __PAIR__(in_eFadeCurve, in_uValueChangeDuration);
    in_rItem.type = 3;
    v5 = UEL::ArgumentUsageExpression::GetClassSize();
  }
  else
  {
    in_rItem.type = 2;
    v5 = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  }
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v5);
}

// File Line: 855
// RVA: 0xA43450
__int64 __fastcall AK::SoundEngine::SetSwitch(unsigned int in_SwitchGroup, unsigned int in_SwitchState, unsigned __int64 in_GameObj)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.rtpc.GameObjID = __PAIR__(in_SwitchState, in_SwitchGroup);
  in_rItem.type = 8;
  v3 = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
}

// File Line: 959
// RVA: 0xA433B0
__int64 __fastcall AK::SoundEngine::SetState(unsigned int in_StateGroup, unsigned int in_State)
{
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.rtpc.ID = in_StateGroup;
  in_rItem.type = 7;
  if ( in_State == 748895195 )
    in_State = 0;
  in_rItem.gameObjMultiPos.uNumPositions = 0;
  in_rItem.setstate.StateID = in_State;
  v2 = UFG::SocialLogData_NewHighScore::VariableBindingListSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v2);
}

// File Line: 964
// RVA: 0xA43400
__int64 __fastcall AK::SoundEngine::SetState(unsigned int in_StateGroup, unsigned int in_State, bool in_bSkipTransitionTime, bool in_bSkipExtension)
{
  unsigned __int16 v4; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.rtpc.ID = in_StateGroup;
  in_rItem.setstate.bSkipTransition = in_bSkipTransitionTime;
  in_rItem.type = 7;
  if ( in_State == 748895195 )
    in_State = 0;
  in_rItem.setstate.bSkipExtension = in_bSkipExtension;
  in_rItem.setstate.StateID = in_State;
  v4 = UFG::SocialLogData_NewHighScore::VariableBindingListSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v4);
}

// File Line: 1101
// RVA: 0xA43050
__int64 __fastcall AK::SoundEngine::SetGameObjectAuxSendValues(unsigned __int64 in_GameObj, AkAuxSendValue *in_aEnvironmentValues, unsigned int in_uNumEnvValues)
{
  hkpSphereShape *v4; // rcx
  unsigned __int16 v5; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( in_uNumEnvValues > 4 )
    return 31i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.event.PlayingID = in_uNumEnvValues;
  in_rItem.type = 18;
  memmove(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1, in_aEnvironmentValues, 8 * in_uNumEnvValues);
  v5 = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v4);
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v5);
}

// File Line: 1143
// RVA: 0xA430B0
__int64 __fastcall AK::SoundEngine::SetGameObjectOutputBusVolume(unsigned __int64 in_GameObj, float in_fControlValue)
{
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.gameobjpos.Position.Position.X = in_fControlValue;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.type = 19;
  v2 = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v2);
}

// File Line: 1164
// RVA: 0xA43250
__int64 __fastcall AK::SoundEngine::SetObjectObstructionAndOcclusion(unsigned __int64 in_ObjectID, unsigned int in_uListener, float in_fObstructionLevel, float in_fOcclusionLevel)
{
  unsigned __int16 v4; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.gameobjpos.Position.Position.Z = in_fOcclusionLevel;
  in_rItem.event.GameObjID = in_ObjectID;
  in_rItem.rtpc.GameObjID = __PAIR__(LODWORD(in_fObstructionLevel), in_uListener);
  in_rItem.type = 20;
  v4 = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v4);
}

// File Line: 1188
// RVA: 0xA43490
signed __int64 __fastcall AK::SoundEngine::SetVolumeThresholdInternal(float in_fVolumeThresholdDB, AK::SoundEngine::AkCommandPriority in_uReserved)
{
  float v2; // xmm8_4
  float v3; // xmm7_4
  float v4; // xmm9_4
  float v5; // xmm9_4
  __m128 v6; // xmm0
  int v7; // edx
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm9_4
  int v12; // ecx
  __m128 v13; // xmm0
  float v14; // xmm0_4
  __m128 v16; // [rsp+20h] [rbp-68h]
  __m128 v17; // [rsp+30h] [rbp-58h]

  v2 = in_fVolumeThresholdDB;
  if ( in_fVolumeThresholdDB < -96.300003 )
    return 31i64;
  v3 = 0.0;
  if ( in_fVolumeThresholdDB > 0.0 )
    return 31i64;
  if ( in_uReserved <= g_eVolumeThresholdPriority )
  {
    g_eVolumeThresholdPriority = in_uReserved;
    v4 = in_fVolumeThresholdDB;
    v6 = (__m128)LODWORD(FLOAT_10_0);
    v5 = v4 * 0.050000001;
    v6.m128_f32[0] = powf(10.0, v5);
    v7 = `AkMath::FastPow10'::`4'::`local static guard';
    v8 = v6.m128_f32[0];
    if ( v5 >= -37.0 )
    {
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v9 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        v9 = FLOAT_2_7866352e7;
        v7 = `AkMath::FastPow10'::`4'::`local static guard' | 1;
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v11 = (float)(v5 * v9) + 1065353200.0;
      v12 = (signed int)v11 & 0x7FFFFF;
      v6 = (__m128)(unsigned int)(v12 + 1065353216);
      v10 = (float)((float)((float)((float)(COERCE_FLOAT(v12 + 1065353216) * 0.32518977) + 0.020805772)
                          * COERCE_FLOAT(v12 + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)v11 & 0xFF800000);
    }
    else
    {
      v9 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      v10 = 0.0;
    }
    v6.m128_f32[0] = v2;
    v13 = _mm_shuffle_ps(v6, v6, 0);
    v16 = v13;
    v17 = v13;
    v14 = v13.m128_f32[0] * 0.050000001;
    if ( v14 >= -37.0 )
    {
      if ( !(v7 & 1) )
      {
        v9 = FLOAT_2_7866352e7;
        v7 |= 1u;
        `AkMath::FastPow10'::`4'::`local static guard' = v7;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v3 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v9 * v14) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v9 * v14) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v9 * v14) + 1065353200.0) & 0xFF800000);
    }
    if ( (float)(v16.m128_f32[1] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v16.m128_f32[2] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v17.m128_f32[3] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v16.m128_f32[3] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v17.m128_f32[0] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v17.m128_f32[1] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      v7 |= 1u;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7;
    }
    if ( (float)(v17.m128_f32[2] * 0.050000001) >= -37.0 && !(v7 & 1) )
    {
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' = v7 | 1;
    }
    if ( v8 <= v10 )
      v8 = v10;
    if ( v8 > v3 )
    {
      g_fVolumeThreshold = v8;
      g_fVolumeThresholdDB = v2;
      return 1i64;
    }
    g_fVolumeThreshold = v3;
    g_fVolumeThresholdDB = v2;
  }
  return 1i64;
}

// File Line: 1315
// RVA: 0xA43220
signed __int64 __fastcall AK::SoundEngine::SetMaxNumVoicesLimitInternal(unsigned __int16 in_maxNumberVoices, AK::SoundEngine::AkCommandPriority in_uReserved)
{
  if ( !in_maxNumberVoices )
    return 31i64;
  if ( in_uReserved <= g_eNumVoicesPriority )
  {
    g_eNumVoicesPriority = in_uReserved;
    CAkURenderer::m_GlobalLimiter.m_u16LimiterMax = in_maxNumberVoices;
  }
  return 1i64;
}

// File Line: 1376
// RVA: 0xA426F0
AkExternalSourceArray *__fastcall AK::SoundEngine::PostEvent(unsigned int in_ulEventID, unsigned __int64 in_GameObjID, unsigned int in_uiFlags, void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *), void *in_pCookie, unsigned int in_cExternals, AkExternalSourceInfo *in_pExternalSources, unsigned int in_PlayingID)
{
  AkCustomParamType *in_pCustomParam; // r10
  void (__fastcall *v9)(AkCallbackType, AkCallbackInfo *); // rsi
  unsigned int v10; // ebp
  unsigned __int64 v11; // r14
  unsigned int v12; // er15
  AkExternalSourceArray *result; // rax
  AkExternalSourceArray *v14; // rbx
  unsigned int v15; // esi
  AkCustomParamType v16; // [rsp+40h] [rbp-28h]

  in_pCustomParam = 0i64;
  v9 = in_pfnCallback;
  v10 = in_uiFlags;
  v11 = in_GameObjID;
  v12 = in_ulEventID;
  if ( in_cExternals )
  {
    v16.customParam = 0i64;
    v16.ui32Reserved = 0;
    result = AkExternalSourceArray::Create(in_cExternals, in_pExternalSources);
    v14 = result;
    v16.pExternalSrcs = result;
    if ( !result )
      return result;
    in_pCustomParam = &v16;
  }
  else
  {
    v14 = v16.pExternalSrcs;
  }
  v15 = AK::SoundEngine::PostEvent(v12, v11, v10, v9, in_pCookie, in_pCustomParam, in_PlayingID);
  if ( !v15 )
  {
    if ( in_cExternals )
      AkExternalSourceArray::Release(v14);
  }
  return (AkExternalSourceArray *)v15;
}

// File Line: 1406
// RVA: 0xA427C0
__int64 __fastcall AK::SoundEngine::PostEvent(unsigned int in_ulEventID, unsigned __int64 in_GameObjID, unsigned int in_uiFlags, void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *), void *in_pCookie, AkCustomParamType *in_pCustomParam, unsigned int in_PlayingID)
{
  unsigned __int64 v7; // rbp
  void (__fastcall *v8)(AkCallbackType, AkCallbackInfo *); // rdi
  unsigned int in_uiRegisteredNotif; // esi
  AkExternalSourceArray *v10; // rax
  hkpSphereShape *v11; // rcx
  unsigned __int16 v13; // ax
  AkQueuedMsg in_rItem; // [rsp+30h] [rbp-48h]

  v7 = in_GameObjID;
  v8 = in_pfnCallback;
  in_uiRegisteredNotif = in_uiFlags;
  in_rItem.type = 1;
  if ( in_pCustomParam )
  {
    *((_OWORD *)&in_rItem.gameobjdrylevel + 1) = *(_OWORD *)&in_pCustomParam->customParam;
    v10 = in_pCustomParam->pExternalSrcs;
  }
  else
  {
    v10 = 0i64;
    in_rItem.event.CustomParam.customParam = 0i64;
    in_rItem.event.CustomParam.ui32Reserved = 0;
  }
  in_rItem.event.CustomParam.pExternalSrcs = v10;
  in_rItem.event.Event = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                       (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                       in_ulEventID);
  if ( !in_rItem.event.Event )
    return 0i64;
  in_rItem.event.GameObjID = v7;
  in_rItem.rtpc.GameObjID = __PAIR__(in_PlayingID, _InterlockedIncrement((volatile signed __int32 *)&g_PlayingID));
  if ( (unsigned int)CAkPlayingMgr::AddPlayingID(
                       g_pPlayingMgr,
                       (AkQueuedMsg_EventBase *)&in_rItem.event.GameObjID,
                       v8,
                       in_pCookie,
                       in_uiRegisteredNotif,
                       in_rItem.event.Event->key) != 1 )
  {
    ((void (*)(void))in_rItem.event.Event->vfptr->Release)();
    return 0i64;
  }
  v13 = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v11);
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v13);
  return in_rItem.event.PlayingID;
}

// File Line: 1584
// RVA: 0xA41EB0
__int64 __fastcall AK::SoundEngine::ExecuteActionOnEvent(unsigned int in_eventID, AK::SoundEngine::AkActionOnEventType in_ActionType, unsigned __int64 in_gameObjectID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve, unsigned int in_PlayingID)
{
  int v6; // esi
  int v7; // ebx
  unsigned __int64 v8; // rdi
  unsigned __int16 v9; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v6 = in_ActionType;
  v7 = in_uTransitionDuration;
  v8 = in_gameObjectID;
  in_rItem.type = 31;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.rtpc.GameObjID = v8;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = v6;
  *(_QWORD *)((char *)&in_rItem.resetrtpcvalue + 20) = __PAIR__(in_eFadeCurve, v7);
  in_rItem.eventAction.TargetPlayingID = in_PlayingID;
  v9 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v9);
}

// File Line: 1642
// RVA: 0xA42F10
__int64 __fastcall AK::SoundEngine::SeekOnEvent(unsigned int in_eventID, unsigned __int64 in_gameObjectID, int in_iPosition, bool in_bSeekToNearestMarker)
{
  unsigned __int64 v4; // rsi
  bool v5; // bl
  int v6; // edi
  unsigned __int16 v7; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v4 = in_gameObjectID;
  v5 = in_bSeekToNearestMarker;
  v6 = in_iPosition;
  in_rItem.type = 35;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.rtpc.GameObjID = v4;
  in_rItem.seek.bIsSeekRelativeToDuration = 0;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = v6;
  in_rItem.seek.bSnapToMarker = v5;
  v7 = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v7);
}

// File Line: 1695
// RVA: 0xA42FB0
__int64 __fastcall AK::SoundEngine::SeekOnEvent(unsigned int in_eventID, unsigned __int64 in_gameObjectID, float in_fPercent, bool in_bSeekToNearestMarker)
{
  unsigned __int64 v4; // rdi
  bool v5; // bl
  unsigned __int16 v6; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-58h]

  v4 = in_gameObjectID;
  v5 = in_bSeekToNearestMarker;
  in_rItem.type = 35;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.gameobjpos.Position.Position.Z = in_fPercent;
  in_rItem.rtpc.GameObjID = v4;
  in_rItem.seek.bIsSeekRelativeToDuration = 1;
  in_rItem.seek.bSnapToMarker = v5;
  v6 = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v6);
}

// File Line: 1760
// RVA: 0xA421D0
AKRESULT __fastcall AK::SoundEngine::GetSourcePlayPosition(unsigned int in_PlayingID, int *out_puPosition, bool in_bExtrapolate)
{
  AKRESULT result; // eax

  if ( out_puPosition )
    result = CAkPositionRepository::GetCurrPosition(
               g_pPositionRepository,
               in_PlayingID,
               out_puPosition,
               in_bExtrapolate);
  else
    result = 31;
  return result;
}

// File Line: 1779
// RVA: 0xA42E90
CAkIndexable *__fastcall AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(unsigned int in_eventID, unsigned int *in_aArgumentValues, unsigned int in_uNumArguments, unsigned int in_idSequence)
{
  unsigned int *v4; // rbp
  unsigned int v5; // ebx
  unsigned int v6; // esi
  CAkIndexable *result; // rax
  CAkIndexable *v8; // rdi
  unsigned int v9; // ebx

  v4 = in_aArgumentValues;
  v5 = in_idSequence;
  v6 = in_uNumArguments;
  result = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
             (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDialogueEvents,
             in_eventID);
  v8 = result;
  if ( result )
  {
    v9 = AkDecisionTree::ResolvePath((AkDecisionTree *)&result[1], result->key, v4, v6, v5);
    v8->vfptr->Release(v8);
    result = (CAkIndexable *)v9;
  }
  return result;
}

// File Line: 1868
// RVA: 0xA42570
__int64 __fastcall AK::SoundEngine::DynamicSequence::Open(unsigned __int64 in_gameObjectID, unsigned int in_uiFlags, void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *), void *in_pCookie, AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  unsigned __int64 v5; // rbp
  void *v6; // rbx
  void (__fastcall *v7)(AkCallbackType, AkCallbackInfo *); // rdi
  unsigned int in_uiRegisteredNotif; // esi
  unsigned int v9; // ecx
  hkpSphereShape *v10; // rcx
  unsigned __int16 v12; // ax
  AkQueuedMsg in_rItem; // [rsp+30h] [rbp-48h]

  v5 = in_gameObjectID;
  v6 = in_pCookie;
  v7 = in_pfnCallback;
  in_uiRegisteredNotif = in_uiFlags;
  in_rItem.type = 22;
  v9 = _InterlockedIncrement((volatile signed __int32 *)&g_PlayingID);
  in_rItem.rtpc.GameObjID = v9;
  in_rItem.event.Event = (CAkEvent *)CAkDynamicSequence::Create(v9, in_eDynamicSequenceType);
  if ( !in_rItem.event.Event )
    return 0i64;
  in_rItem.event.GameObjID = v5;
  in_rItem.event.CustomParam.customParam = 0i64;
  in_rItem.event.CustomParam.ui32Reserved = 0;
  in_rItem.event.CustomParam.pExternalSrcs = 0i64;
  if ( (unsigned int)CAkPlayingMgr::AddPlayingID(
                       g_pPlayingMgr,
                       (AkQueuedMsg_EventBase *)&in_rItem.event.GameObjID,
                       v7,
                       v6,
                       in_uiRegisteredNotif,
                       0) != 1 )
  {
    ((void (*)(void))in_rItem.event.Event->vfptr->Release)();
    return 0i64;
  }
  v12 = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v10);
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v12);
  return in_rItem.event.PlayingID;
}

// File Line: 1954
// RVA: 0xA42660
__int64 __fastcall AK::SoundEngine::DynamicSequence::Play(unsigned int in_playingID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  int v3; // edi
  AkCurveInterpolation v4; // ebx
  CAkIndexable *v5; // rax
  unsigned __int16 v6; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v3 = in_uTransitionDuration;
  v4 = in_eFadeCurve;
  in_rItem.type = 23;
  v5 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
         in_playingID);
  in_rItem.event.GameObjID = (unsigned __int64)v5;
  if ( v5 )
  {
    if ( !LOBYTE(v5[5].pNextItem) )
    {
      in_rItem.event.PlayingID = 0;
      *(_QWORD *)(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1) = __PAIR__(v4, v3);
      v6 = UEL::ArgumentUsageExpression::GetClassSize();
      return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v6);
    }
    v5->vfptr->Release(v5);
  }
  return 2i64;
}

// File Line: 1979
// RVA: 0xA41CB0
__int64 __fastcall AK::SoundEngine::DynamicSequence::Close(unsigned int in_playingID)
{
  CAkIndexable *v1; // rax
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.type = 23;
  v1 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
         in_playingID);
  in_rItem.event.GameObjID = (unsigned __int64)v1;
  if ( v1 )
  {
    if ( !LOBYTE(v1[5].pNextItem) )
    {
      LOBYTE(v1[5].pNextItem) = 1;
      in_rItem.rtpc.GameObjID = 3i64;
      in_rItem.rtpcWithTransition.transParams.TransitionTime = 4;
      v2 = UEL::ArgumentUsageExpression::GetClassSize();
      return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v2);
    }
    v1->vfptr->Release(v1);
  }
  return 2i64;
}

// File Line: 1986
// RVA: 0xA42520
CAkIndexable *__fastcall AK::SoundEngine::DynamicSequence::LockPlaylist(unsigned int in_playingID)
{
  CAkIndexable *result; // rax
  AK::SoundEngine::DynamicSequence::Playlist *v2; // rbx

  result = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
             (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
             in_playingID);
  v2 = (AK::SoundEngine::DynamicSequence::Playlist *)result;
  if ( result )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&result[1].key);
    ((void (__fastcall *)(AK::SoundEngine::DynamicSequence::Playlist *))v2->m_pItems->pExternalSrcs)(v2);
    result = (CAkIndexable *)&v2[1].m_uLength;
  }
  return result;
}

// File Line: 2008
// RVA: 0xA43CC0
signed __int64 __fastcall AK::SoundEngine::DynamicSequence::UnlockPlaylist(unsigned int in_playingID)
{
  CAkDynamicSequence *v1; // rax
  CAkDynamicSequence *v2; // rbx

  v1 = (CAkDynamicSequence *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                               (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
                               in_playingID);
  v2 = v1;
  if ( !v1 )
    return 2i64;
  CAkDynamicSequence::UnlockPlaylist(v1);
  v2->vfptr->Release((CAkIndexable *)&v2->vfptr);
  return 1i64;
}

// File Line: 2046
// RVA: 0xA42CE0
__int64 __fastcall AK::SoundEngine::RegisterGameObj(unsigned __int64 in_GameObj, const char *in_pszObjName, unsigned int in_uListenerMask)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( in_GameObj - 1 > 0xFFFFFFFFFFFFFFFDui64 )
    return 2i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.event.PlayingID = in_uListenerMask;
  in_rItem.type = 11;
  in_rItem.event.CustomParam.customParam = 0i64;
  v3 = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
}

// File Line: 2068
// RVA: 0xA43D10
__int64 __fastcall AK::SoundEngine::UnregisterGameObj(unsigned __int64 in_GameObj)
{
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( !in_GameObj )
    return 2i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.type = 12;
  v2 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v2);
}

// File Line: 2098
// RVA: 0xA41E90
void __fastcall AK::SoundEngine::DefaultBankCallbackFunc(unsigned int __formal, const void *a2, AKRESULT in_eLoadResult, int in_memPoolId, void *in_pCookie)
{
  *(_DWORD *)in_pCookie = in_eLoadResult;
  *((_DWORD *)in_pCookie + 4) = in_memPoolId;
  SetEvent(*((HANDLE *)in_pCookie + 1));
}

// File Line: 2110
// RVA: 0xA41AA0
signed __int64 __fastcall AK::SoundEngine::ClearBanks()
{
  signed __int64 result; // rax
  unsigned int v1; // ebx
  unsigned int v2; // [rsp+20h] [rbp-98h]
  HANDLE hObject; // [rsp+28h] [rbp-90h]
  __int128 v4; // [rsp+38h] [rbp-80h]
  __int128 v5; // [rsp+48h] [rbp-70h]
  __int128 v6; // [rsp+58h] [rbp-60h]
  __int64 v7; // [rsp+68h] [rbp-50h]
  __int128 v8; // [rsp+70h] [rbp-48h]
  __int128 v9; // [rsp+80h] [rbp-38h]
  __int128 v10; // [rsp+90h] [rbp-28h]
  __int64 v11; // [rsp+A0h] [rbp-18h]

  if ( !g_pBankManager )
    return 2i64;
  result = AK::SoundEngine::ClearPreparedEvents();
  if ( (_DWORD)result == 1 )
  {
    hObject = CreateEventW(0i64, 0, 0, 0i64);
    if ( !hObject )
      return 2i64;
    LODWORD(v4) = 8;
    *((_QWORD *)&v4 + 1) = AK::SoundEngine::DefaultBankCallbackFunc;
    DWORD2(v5) = 0;
    *(_QWORD *)&v5 = &v2;
    v8 = v4;
    v10 = v6;
    v9 = v5;
    v11 = v7;
    v1 = CAkBankMgr::QueueBankCommand(g_pBankManager, (CAkBankMgr::AkBankQueueItem *)&v8);
    if ( v1 == 1 )
    {
      WaitForSingleObject(hObject, 0xFFFFFFFF);
      if ( hObject )
        CloseHandle(hObject);
      v1 = v2;
    }
    else if ( hObject )
    {
      CloseHandle(hObject);
      return v1;
    }
    result = v1;
  }
  return result;
}

// File Line: 2518
// RVA: 0xA424A0
__int64 __fastcall AK::SoundEngine::LoadBank(unsigned int in_bankID, void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *), void *in_pCookie, int in_memPoolId)
{
  __int128 v5; // [rsp+20h] [rbp-88h]
  __int128 v6; // [rsp+30h] [rbp-78h]
  __int64 v7; // [rsp+50h] [rbp-58h]
  __int128 v8; // [rsp+60h] [rbp-48h]
  __int128 v9; // [rsp+70h] [rbp-38h]
  __int128 v10; // [rsp+80h] [rbp-28h]
  __int64 v11; // [rsp+90h] [rbp-18h]

  LODWORD(v5) = 0;
  *((_QWORD *)&v5 + 1) = in_pfnBankCallback;
  *(_QWORD *)&v6 = in_pCookie;
  LODWORD(v7) = 0;
  DWORD2(v6) = 2;
  v8 = v5;
  v9 = v6;
  v10 = __PAIR__((unsigned int)in_memPoolId, in_bankID);
  v11 = v7;
  return CAkBankMgr::QueueBankCommand(g_pBankManager, (CAkBankMgr::AkBankQueueItem *)&v8);
}

// File Line: 2659
// RVA: 0xA43C40
__int64 __fastcall AK::SoundEngine::UnloadBank(unsigned int in_bankID, const void *in_pInMemoryBankPtr, void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *), void *in_pCookie)
{
  __int128 v4; // ST40_16
  __int128 v6; // [rsp+20h] [rbp-88h]
  __int128 v7; // [rsp+30h] [rbp-78h]
  __int64 v8; // [rsp+50h] [rbp-58h]
  __int128 v9; // [rsp+60h] [rbp-48h]
  __int128 v10; // [rsp+70h] [rbp-38h]
  __int128 v11; // [rsp+80h] [rbp-28h]
  __int64 v12; // [rsp+90h] [rbp-18h]

  *(_QWORD *)&v4 = __PAIR__(-1, in_bankID);
  LODWORD(v6) = 1;
  *((_QWORD *)&v4 + 1) = in_pInMemoryBankPtr;
  *((_QWORD *)&v6 + 1) = in_pfnBankCallback;
  *(_QWORD *)&v7 = in_pCookie;
  LODWORD(v8) = 0;
  v9 = v6;
  DWORD2(v7) = in_pInMemoryBankPtr != 0i64;
  v10 = v7;
  v11 = v4;
  v12 = v8;
  return CAkBankMgr::QueueBankCommand(g_pBankManager, (CAkBankMgr::AkBankQueueItem *)&v9);
}

// File Line: 2983
// RVA: 0xA41BB0
signed __int64 __fastcall AK::SoundEngine::ClearPreparedEvents()
{
  unsigned int v1; // ebx
  unsigned int v2; // [rsp+20h] [rbp-98h]
  HANDLE hObject; // [rsp+28h] [rbp-90h]
  __int128 v4; // [rsp+38h] [rbp-80h]
  __int128 v5; // [rsp+48h] [rbp-70h]
  __int128 v6; // [rsp+58h] [rbp-60h]
  __int64 v7; // [rsp+68h] [rbp-50h]
  __int128 v8; // [rsp+70h] [rbp-48h]
  __int128 v9; // [rsp+80h] [rbp-38h]
  __int128 v10; // [rsp+90h] [rbp-28h]
  __int64 v11; // [rsp+A0h] [rbp-18h]

  hObject = CreateEventW(0i64, 0, 0, 0i64);
  if ( !hObject )
    return 2i64;
  LODWORD(v4) = 5;
  *((_QWORD *)&v4 + 1) = AK::SoundEngine::DefaultBankCallbackFunc;
  DWORD2(v5) = 0;
  *(_QWORD *)&v5 = &v2;
  v8 = v4;
  v10 = v6;
  v9 = v5;
  v11 = v7;
  v1 = CAkBankMgr::QueueBankCommand(g_pBankManager, (CAkBankMgr::AkBankQueueItem *)&v8);
  if ( v1 == 1 )
  {
    WaitForSingleObject(hObject, 0xFFFFFFFF);
    if ( hObject )
      CloseHandle(hObject);
    v1 = v2;
  }
  else if ( hObject )
  {
    CloseHandle(hObject);
    return v1;
  }
  return v1;
}

// File Line: 3366
// RVA: 0xA41920
signed __int64 __fastcall AK::SoundEngine::AddBehavioralExtension(void (__fastcall *in_pCallback)(bool))
{
  unsigned __int64 v1; // r8
  unsigned int v2; // esi
  void (__fastcall **v3)(bool); // rbx
  void (__fastcall *v4)(bool); // r14
  unsigned __int64 v5; // rbp
  void (__fastcall **v6)(bool); // rdi
  void (__fastcall **v7)(bool); // rdx
  unsigned __int64 v8; // rcx
  void (__fastcall *v9)(bool); // rax
  signed __int64 result; // rax

  LODWORD(v1) = g_aBehavioralExtensions.m_uLength;
  v2 = g_aBehavioralExtensions.m_ulReserved;
  v3 = 0i64;
  v4 = in_pCallback;
  v5 = g_aBehavioralExtensions.m_uLength;
  if ( g_aBehavioralExtensions.m_uLength < (unsigned __int64)g_aBehavioralExtensions.m_ulReserved )
  {
    v6 = g_aBehavioralExtensions.m_pItems;
  }
  else
  {
    v2 = g_aBehavioralExtensions.m_ulReserved + 1;
    v6 = (void (__fastcall **)(bool))AK::MemoryMgr::Malloc(
                                       g_DefaultPoolId,
                                       8i64 * (g_aBehavioralExtensions.m_ulReserved + 1));
    if ( !v6 )
      goto LABEL_12;
    v7 = g_aBehavioralExtensions.m_pItems;
    v1 = g_aBehavioralExtensions.m_uLength;
    if ( g_aBehavioralExtensions.m_pItems )
    {
      v8 = 0i64;
      if ( (_DWORD)v1 )
      {
        do
        {
          v9 = v7[v8++];
          v6[v8 - 1] = v9;
          v7 = g_aBehavioralExtensions.m_pItems;
        }
        while ( v8 < v1 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      LODWORD(v1) = g_aBehavioralExtensions.m_uLength;
    }
    g_aBehavioralExtensions.m_pItems = v6;
    g_aBehavioralExtensions.m_ulReserved = v2;
  }
  if ( v5 < v2 )
  {
    v3 = &v6[(unsigned int)v1];
    g_aBehavioralExtensions.m_uLength = v1 + 1;
    if ( v3 )
      *v3 = v4;
  }
LABEL_12:
  result = 52i64;
  if ( v3 )
    result = 1i64;
  return result;
}

// File Line: 3373
// RVA: 0xA42DC0
signed __int64 __fastcall AK::SoundEngine::RemoveBehavioralExtension(void (__fastcall *in_pCallback)(bool))
{
  void (__fastcall **v1)(bool); // rdi
  unsigned int v2; // edx
  void (__fastcall **v3)(bool); // rax
  signed __int64 result; // rax

  v1 = g_aBehavioralExtensions.m_pItems;
  v2 = g_aBehavioralExtensions.m_uLength;
  v3 = &g_aBehavioralExtensions.m_pItems[g_aBehavioralExtensions.m_uLength];
  if ( g_aBehavioralExtensions.m_pItems == v3 )
    return 2i64;
  do
  {
    if ( *v1 == in_pCallback )
      break;
    ++v1;
  }
  while ( v1 != v3 );
  if ( v1 == v3 )
    return 2i64;
  if ( v1 < v3 - 1 )
  {
    qmemcpy(v1, v1 + 1, 8 * (((unsigned __int64)((char *)(v3 - 1) - (char *)v1 - 1) >> 3) + 1));
    v2 = g_aBehavioralExtensions.m_uLength;
  }
  result = 1i64;
  g_aBehavioralExtensions.m_uLength = v2 - 1;
  return result;
}

// File Line: 3392
// RVA: 0xA41A30
void __fastcall AK::SoundEngine::AddExternalStateHandler(bool (__fastcall *in_pCallback)(unsigned int, unsigned int))
{
  g_pExternalStateHandler = in_pCallback;
}

// File Line: 3398
// RVA: 0xA41A20
void __fastcall AK::SoundEngine::AddExternalBankHandler(AKRESULT (__fastcall *in_pCallback)(AkBank::AKBKSubHircSection *, CAkUsageSlot *, unsigned int))
{
  g_pExternalBankHandlerCallback = in_pCallback;
}

// File Line: 3522
// RVA: 0xA428D0
__int64 __fastcall AK::SoundEngine::PreInit(AkInitSettings *io_pSettings)
{
  AkInitSettings *v1; // rsi
  unsigned int v2; // ebx
  CAkAudioLibIndex *v3; // rax
  CAkAudioLibIndex *v4; // rax
  CAkRTPCMgr *v5; // rax
  CAkRTPCMgr *v6; // rax
  CAkEnvironmentsMgr *v7; // rax
  CAkBankMgr *v8; // rax
  CAkBankMgr *v9; // rax
  CAkPlayingMgr *v10; // rax
  CAkPlayingMgr *v11; // rax
  CAkSegmentInfoRepository *v12; // rax
  CAkPositionRepository *v13; // rax
  CAkRegistryMgr *v14; // rax
  CAkRegistryMgr *v15; // rax
  CAkTransitionManager *v16; // rax
  CAkTransitionManager *v17; // rax
  CAkPathManager *v18; // rax
  CAkPathManager *v19; // rax
  CAkStateMgr *v20; // rax
  CAkStateMgr *v21; // rax
  __int64 result; // rax
  LARGE_INTEGER Frequency; // [rsp+30h] [rbp+8h]

  v1 = io_pSettings;
  v2 = 1;
  QueryPerformanceFrequency(&Frequency);
  AK::g_fFreqRatio = (float)(signed int)(((unsigned __int64)((unsigned __int128)(Frequency.QuadPart
                                                                               * (signed __int128)2361183241434822607i64) >> 64) >> 63)
                                       + ((signed __int64)((unsigned __int128)(Frequency.QuadPart
                                                                             * (signed __int128)2361183241434822607i64) >> 64) >> 7));
  if ( !g_pIndex )
  {
    v3 = (CAkAudioLibIndex *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x4468ui64);
    if ( !v3 )
    {
      g_pIndex = 0i64;
      goto LABEL_50;
    }
    CAkAudioLibIndex::CAkAudioLibIndex(v3);
    g_pIndex = v4;
    if ( !v4 )
      goto LABEL_50;
    CAkAudioLibIndex::Init(v4);
  }
  if ( !g_pRTPCMgr )
  {
    v5 = (CAkRTPCMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x1298ui64);
    if ( !v5 )
    {
      g_pRTPCMgr = 0i64;
      goto LABEL_50;
    }
    CAkRTPCMgr::CAkRTPCMgr(v5);
    g_pRTPCMgr = v6;
    if ( !v6 )
      goto LABEL_50;
    v2 = CAkRTPCMgr::Init(v6);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pEnvironmentMgr )
  {
    v7 = (CAkEnvironmentsMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
    if ( !v7 )
    {
      g_pEnvironmentMgr = 0i64;
      goto LABEL_50;
    }
    v7->ConversionTable[0][0].m_pArrayGraphPoints = 0i64;
    *(_QWORD *)&v7->ConversionTable[0][0].m_ulArraySize = 0i64;
    v7->ConversionTable[0][1].m_pArrayGraphPoints = 0i64;
    *(_QWORD *)&v7->ConversionTable[0][1].m_ulArraySize = 0i64;
    v7->ConversionTable[1][0].m_pArrayGraphPoints = 0i64;
    *(_QWORD *)&v7->ConversionTable[1][0].m_ulArraySize = 0i64;
    v7->ConversionTable[1][1].m_pArrayGraphPoints = 0i64;
    *(_QWORD *)&v7->ConversionTable[1][1].m_ulArraySize = 0i64;
    g_pEnvironmentMgr = v7;
    v2 = CAkEnvironmentsMgr::Init(v7);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pBankManager )
  {
    v8 = (CAkBankMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x958ui64);
    if ( !v8 )
    {
      g_pBankManager = 0i64;
      goto LABEL_50;
    }
    CAkBankMgr::CAkBankMgr(v8);
    g_pBankManager = v9;
    if ( !v9 )
      goto LABEL_50;
    v2 = CAkBankMgr::Init(v9);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pPlayingMgr )
  {
    v10 = (CAkPlayingMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x168ui64);
    if ( !v10 )
    {
      g_pPlayingMgr = 0i64;
      goto LABEL_50;
    }
    CAkPlayingMgr::CAkPlayingMgr(v10);
    g_pPlayingMgr = v11;
    if ( !v11 )
      goto LABEL_50;
    v2 = CAkPlayingMgr::Init(v11);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pPositionRepository )
  {
    v12 = (CAkSegmentInfoRepository *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
    if ( !v12 )
    {
      g_pPositionRepository = 0i64;
      goto LABEL_50;
    }
    CAkBusCallbackMgr::CAkBusCallbackMgr(v12);
    g_pPositionRepository = v13;
    if ( !v13 )
      goto LABEL_50;
    v2 = CAkPositionRepository::Init(v13);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pRegistryMgr )
  {
    v14 = (CAkRegistryMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x648ui64);
    if ( !v14 )
    {
      g_pRegistryMgr = 0i64;
      goto LABEL_50;
    }
    CAkRegistryMgr::CAkRegistryMgr(v14);
    g_pRegistryMgr = v15;
    if ( !v15 )
      goto LABEL_50;
    v2 = CAkRegistryMgr::Init(v15);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( !g_pTransitionManager )
  {
    v16 = (CAkTransitionManager *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
    if ( !v16 )
    {
      g_pTransitionManager = 0i64;
      goto LABEL_50;
    }
    CAkTransitionManager::CAkTransitionManager(v16);
    g_pTransitionManager = v17;
    if ( !v17 )
      goto LABEL_50;
    v2 = CAkTransitionManager::Init(v17, in_uMaxNumTransitions);
    if ( v2 != 1 )
      goto $preinit_failure;
  }
  if ( g_pPathManager )
    goto LABEL_36;
  v18 = (CAkPathManager *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
  if ( !v18 )
  {
    g_pPathManager = 0i64;
    goto LABEL_50;
  }
  CAkPathManager::CAkPathManager(v18);
  g_pPathManager = v19;
  if ( v19 )
  {
    v2 = CAkPathManager::Init(v19, in_uMaxNumPath);
    if ( v2 != 1 )
      goto $preinit_failure;
LABEL_36:
    if ( g_pStateMgr )
      goto $preinit_failure;
    v20 = (CAkStateMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xB8ui64);
    if ( v20 )
    {
      CAkStateMgr::CAkStateMgr(v20);
      g_pStateMgr = v21;
      if ( v21 )
      {
        v2 = CAkStateMgr::Init(v21);
        goto $preinit_failure;
      }
    }
    else
    {
      g_pStateMgr = 0i64;
    }
  }
LABEL_50:
  v2 = 52;
$preinit_failure:
  result = v2;
  if ( v1 )
  {
    *(_OWORD *)&v1->pfnAssertHook = *(_OWORD *)&g_settings.pfnAssertHook;
    *(_OWORD *)&v1->uDefaultPoolSize = *(_OWORD *)&in_ulMemSize;
    *(_OWORD *)&v1->bEnableGameSyncPreparation = unk_14249E980;
    *(_OWORD *)&v1->eMainOutputType = *(_OWORD *)&in_eSinkType;
  }
  return result;
}

// File Line: 3653
// RVA: 0xA42410
AKRESULT __fastcall AK::SoundEngine::InitRenderer()
{
  AKRESULT result; // eax
  CAkAudioMgr *v1; // rax
  CAkAudioMgr *v2; // rax

  result = CAkURenderer::Init();
  if ( !g_pAudioMgr && result == 1 )
  {
    v1 = (CAkAudioMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF0ui64);
    if ( v1 )
    {
      CAkAudioMgr::CAkAudioMgr(v1);
      g_pAudioMgr = v2;
      if ( v2 )
      {
        result = CAkAudioMgr::Init(v2);
        if ( result == 1 )
          result = CAkAudioMgr::Start(g_pAudioMgr);
        return result;
      }
    }
    else
    {
      g_pAudioMgr = 0i64;
    }
    result = 52;
  }
  return result;
}

// File Line: 3676
// RVA: 0xA437F0
void __fastcall AK::SoundEngine::StopAll(unsigned __int64 in_gameObjectID)
{
  unsigned __int16 v1; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.event.GameObjID = in_gameObjectID;
  in_rItem.type = 25;
  v1 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v1);
}

// File Line: 3689
// RVA: 0xA43830
void __fastcall AK::SoundEngine::StopPlayingID(unsigned int in_playingID, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( in_playingID )
  {
    in_rItem.event.GameObjID = __PAIR__(in_uTransitionDuration, in_playingID);
    in_rItem.type = 30;
    in_rItem.event.PlayingID = in_eFadeCurve;
    v3 = UFG::SocialLogData_NewHighScore::VariableBindingListSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
  }
}

// File Line: 3889
// RVA: 0xA41A40
__int64 __fastcall AK::MotionEngine::AddPlayerMotionDevice(char in_iPlayerID, unsigned int in_iCompanyID, unsigned int in_iDevicePluginID, void *in_pDevice)
{
  unsigned __int16 v5; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( (unsigned __int8)in_iPlayerID > 3u )
    return 2i64;
  in_rItem.rtpc.GameObjID = (unsigned __int64)in_pDevice;
  in_rItem.playerdevice.bAdd = 1;
  in_rItem.type = 27;
  in_rItem.playerdevice.iPlayer = (unsigned __int8)in_iPlayerID;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = (unsigned __int16)in_iDevicePluginID;
  v5 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v5);
}

// File Line: 3920
// RVA: 0xA42E30
void __fastcall AK::MotionEngine::RemovePlayerMotionDevice(char in_iPlayerID, unsigned int in_iCompanyID, unsigned int in_iDevicePluginID)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  if ( (unsigned __int8)in_iPlayerID <= 3u )
  {
    in_rItem.rtpc.GameObjID = 0i64;
    in_rItem.playerdevice.bAdd = 0;
    in_rItem.type = 27;
    in_rItem.playerdevice.iPlayer = (unsigned __int8)in_iPlayerID;
    in_rItem.rtpcWithTransition.transParams.TransitionTime = (unsigned __int16)in_iDevicePluginID;
    v3 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
  }
}

// File Line: 3939
// RVA: 0xA42D40
void __fastcall AK::MotionEngine::RegisterMotionDevice(unsigned int in_ulCompanyID, unsigned int in_ulPluginID, AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *))
{
  CAkEffectsMgr::RegisterFeedbackBus(in_ulCompanyID, in_ulPluginID, in_pCreateFunc);
}

// File Line: 3956
// RVA: 0xA432A0
void __fastcall AK::MotionEngine::SetPlayerVolume(char in_iPlayerID, float in_fVolume)
{
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  in_rItem.playervolume.fVolume = in_fVolume;
  in_rItem.type = 29;
  in_rItem.setstate.StateID = (unsigned __int8)in_iPlayerID;
  v2 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v2);
}

// File Line: 4065
// RVA: 0xA41D30
AkExternalSourceArray *__fastcall AkExternalSourceArray::Create(unsigned int in_nCount, AkExternalSourceInfo *in_pSrcs)
{
  AkExternalSourceInfo *v2; // r14
  unsigned int v3; // er15
  AkExternalSourceArray *result; // rax
  AkExternalSourceArray *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebp
  signed __int64 v8; // rbx
  char *v9; // r12
  signed __int64 v10; // rax
  bool v11; // zf
  unsigned int v12; // er14
  void *v13; // rax
  wchar_t *v14; // rdx

  v2 = in_pSrcs;
  v3 = in_nCount;
  result = (AkExternalSourceArray *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 32 * (in_nCount - 1) + 40);
  v5 = result;
  if ( !result )
    return result;
  v6 = 0;
  result->m_cRefCount = 1;
  result->m_nCount = v3;
  v7 = 0;
  if ( !v3 )
    return v5;
  v8 = (signed __int64)&v2->szFile;
  v9 = (char *)((char *)result - (char *)v2);
  while ( 1 )
  {
    *(_QWORD *)&v9[v8] = *(_QWORD *)(v8 - 8);
    *(_QWORD *)&v9[v8 + 8] = *(_QWORD *)v8;
    *(_QWORD *)&v9[v8 + 16] = *(_QWORD *)(v8 + 8);
    *(_QWORD *)&v9[v8 + 24] = *(_QWORD *)(v8 + 16);
    if ( *(_QWORD *)v8 )
      break;
LABEL_9:
    ++v7;
    v8 += 32i64;
    if ( v7 >= v3 )
      return v5;
  }
  v10 = -1i64;
  do
    v11 = *(_WORD *)(*(_QWORD *)v8 + 2 * v10++ + 2) == 0;
  while ( !v11 );
  v12 = 2 * v10 + 2;
  v13 = AK::MemoryMgr::Malloc(g_DefaultPoolId, v12);
  *(_QWORD *)&v9[v8 + 8] = v13;
  if ( v13 )
  {
    memmove(v13, *(const void **)v8, v12);
    goto LABEL_9;
  }
  v11 = v5->m_cRefCount-- == 1;
  v5->m_nCount = v7;
  if ( v11 )
  {
    if ( v7 )
    {
      do
      {
        v14 = v5->m_pSrcs[v6].szFile;
        if ( v14 )
          AK::MemoryMgr::Free(g_DefaultPoolId, v14);
        ++v6;
      }
      while ( v6 < v5->m_nCount );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
  }
  return 0i64;
}

// File Line: 4104
// RVA: 0xA42D60
void __fastcall AkExternalSourceArray::Release(AkExternalSourceArray *this)
{
  bool v1; // zf
  AkExternalSourceArray *v2; // rdi
  unsigned int v3; // ebx
  wchar_t *v4; // rdx

  v1 = this->m_cRefCount-- == 1;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    if ( this->m_nCount )
    {
      do
      {
        v4 = v2->m_pSrcs[v3].szFile;
        if ( v4 )
          AK::MemoryMgr::Free(g_DefaultPoolId, v4);
        ++v3;
      }
      while ( v3 < v2->m_nCount );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
  }
}

