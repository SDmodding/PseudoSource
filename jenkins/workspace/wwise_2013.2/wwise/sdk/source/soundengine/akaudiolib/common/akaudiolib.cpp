// File Line: 103
// RVA: 0x15BDF10
__int64 dynamic_initializer_for__g_csMain__()
{
  InitializeCriticalSection(&g_csMain.m_csLock);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_csMain__);
}

// File Line: 106
// RVA: 0x15BDF00
__int64 dynamic_initializer_for__g_aBehavioralExtensions__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_aBehavioralExtensions__);
}

// File Line: 191
// RVA: 0xA420C0
signed __int64 __fastcall AK::SoundEngine::GetIDFromString(const wchar_t *in_pszString)
{
  signed __int64 result; // rax
  unsigned __int64 v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  int v5; // eax
  unsigned __int64 v6; // rdi
  char v7; // cl
  char *v8; // rdx
  char *v9; // r8
  int v10; // ecx
  char MultiByteStr[259]; // [rsp+40h] [rbp-118h] BYREF
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
  signed __int64 result; // rax
  unsigned __int64 v3; // rbx
  __int64 v4; // rax
  unsigned __int64 v5; // rdi
  __int64 v6; // rdi
  unsigned __int64 i; // rcx
  char v8; // dl
  char *v9; // r8
  char *v10; // rdx
  int v11; // ecx
  char _Dst[280]; // [rsp+20h] [rbp-118h] BYREF

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
  while ( in_pszString[v3] );
  for ( i = 0i64; i < v3; ++i )
  {
    v8 = _Dst[i];
    if ( (unsigned __int8)(v8 - 0x41) <= 0x19u )
      _Dst[i] = v8 + 0x20;
  }
  v9 = &_Dst[(unsigned int)v3];
  v10 = _Dst;
  for ( result = 0x811C9DC5i64; v10 < v9; result = v11 ^ (unsigned int)(0x1000193 * result) )
    v11 = (unsigned __int8)*v10++;
  return result;
}
/* Orphan comments:
Converts string to lowercase
*/

// File Line: 230
// RVA: 0xA42490
_BOOL8 __fastcall AK::SoundEngine::IsInitialized()
{
  return s_bInitialized;
}

// File Line: 238
// RVA: 0xA421F0
signed __int64 __fastcall AK::SoundEngine::Init(
        AkInitSettings *in_pSettings,
        AkPlatformInitSettings *in_pPlatformSettings)
{
  unsigned int uDefaultPoolSize; // esi
  AKRESULT inited; // ebx
  int Pool; // eax
  AK::SoundEngine *v8; // rcx
  char Dest; // [rsp+30h] [rbp-38h] BYREF
  __int64 v10; // [rsp+31h] [rbp-37h]
  __int64 v11; // [rsp+39h] [rbp-2Fh]
  __int64 v12; // [rsp+41h] [rbp-27h]
  __int64 v13; // [rsp+49h] [rbp-1Fh]
  __int16 v14; // [rsp+51h] [rbp-17h]
  char v15; // [rsp+53h] [rbp-15h]

  g_eVolumeThresholdPriority = AkCommandPriority_None;
  g_eNumVoicesPriority = AkCommandPriority_None;
  if ( !AK::MemoryMgr::IsInitialized() )
    return 74i64;
  if ( !AK::IAkStreamMgr::m_pStreamMgr )
    return 75i64;
  uDefaultPoolSize = 0x1000000;
  if ( in_pSettings )
  {
    g_settings = *in_pSettings;
  }
  else
  {
    g_settings.pfnAssertHook = 0i64;
    g_settings.uMaxNumPaths = 255;
    g_settings.uMaxNumTransitions = 255;
    LODWORD(g_settings.fDefaultPoolRatioThreshold) = (_DWORD)FLOAT_1_0;
    g_settings.uDefaultPoolSize = 0x1000000;
    g_settings.uCommandQueueSize = 0x40000;
    g_settings.uPrepareEventMemoryPoolID = -1;
    g_settings.bEnableGameSyncPreparation = 0;
    g_settings.uContinuousPlaybackLookAhead = 1;
    g_settings.uMonitorPoolSize = 0x40000;
    *(_QWORD *)&g_settings.uMonitorQueuePoolSize = 0x10000i64;
    CAkLEngine::GetDefaultOutputSettings(AkSink_Main, &g_settings.settingsMainOutput);
  }
  g_pAssertHook = g_settings.pfnAssertHook;
  CAkLEngine::ApplyGlobalSettings(in_pPlatformSettings);
  inited = AK_Fail;
  if ( !s_bInitialized )
  {
    if ( g_DefaultPoolId == -1 )
    {
      if ( g_settings.uDefaultPoolSize > 0x40 )
        uDefaultPoolSize = g_settings.uDefaultPoolSize;
      Pool = AK::MemoryMgr::CreatePool(0i64, uDefaultPoolSize, 0x40u, 1u, 0);
      g_DefaultPoolId = Pool;
      AkFXMemAlloc::m_instanceUpper.m_poolId = Pool;
      if ( Pool == -1 )
      {
        inited = AK_InsufficientMemory;
        goto LABEL_18;
      }
    }
    inited = (unsigned int)AK::SoundEngine::PreInit(in_pSettings);
    if ( inited != AK_Success || (inited = AK::SoundEngine::InitRenderer(), inited != AK_Success) )
    {
      AK::SoundEngine::Term(v8);
      Pool = g_DefaultPoolId;
LABEL_18:
      if ( !s_bInitialized && Pool != -1 )
      {
        AK::MemoryMgr::DestroyPool(Pool);
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
  return (unsigned int)inited;
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
  CAkLEngine::GetDefaultOutputSettings(AkSink_Main, &out_settings->settingsMainOutput);
}

// File Line: 349
// RVA: 0xA41FC0
// attributes: thunk
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
  void *m_Event; // rcx
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
      m_Event = v15->m_CallbackEvent.m_Event;
      if ( m_Event )
        CloseHandle(m_Event);
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
// attributes: thunk
AKRESULT __fastcall AK::SoundEngine::RegisterPlugin(
        AkPluginType in_eType,
        unsigned int in_ulCompanyID,
        unsigned int in_ulPluginID,
        AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *),
        AK::IAkPluginParam *(__fastcall *in_pCreateParamFunc)(AK::IAkPluginMemAlloc *))
{
  return CAkEffectsMgr::RegisterPlugin(in_eType, in_ulCompanyID, in_ulPluginID, in_pCreateFunc, in_pCreateParamFunc);
}

// File Line: 516
// RVA: 0xA42CD0
// attributes: thunk
AKRESULT __fastcall AK::SoundEngine::RegisterCodec(
        unsigned int in_ulCompanyID,
        unsigned int in_ulPluginID,
        IAkSoftwareCodec *(__fastcall *in_pFileCreateFunc)(void *),
        IAkSoftwareCodec *(__fastcall *in_pBankCreateFunc)(void *))
{
  return CAkEffectsMgr::RegisterCodec(in_ulCompanyID, in_ulPluginID, in_pFileCreateFunc, in_pBankCreateFunc);
}

// File Line: 527
// RVA: 0xA432E0
__int64 __fastcall AK::SoundEngine::SetPosition(unsigned __int64 in_GameObj, AkSoundPosition *in_Position)
{
  __int128 v3; // xmm0
  void *v4; // xmm1_8
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( !in_GameObj )
    return 2i64;
  v3 = *(_OWORD *)&in_Position->Position.X;
  v4 = *(void **)&in_Position->Orientation.Y;
  in_rItem.type = 13;
  in_rItem.event.GameObjID = in_GameObj;
  *(_OWORD *)(&in_rItem.unreggameobj + 1) = v3;
  in_rItem.processMode.pUserData = v4;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 688
// RVA: 0xA43130
__int64 __fastcall AK::SoundEngine::SetListenerPosition(AkListenerPosition *in_Position, unsigned int in_ulIndex)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float Y; // xmm1_4
  unsigned __int16 v8; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.type = 16;
  v4 = AkMath::DotProduct(&in_Position->OrientationFront, &in_Position->OrientationTop);
  v5 = v4 * in_Position->OrientationTop.Z;
  v6 = v4 * in_Position->OrientationTop.Y;
  in_rItem.rtpc.Value = in_Position->OrientationFront.X - (float)(v4 * in_Position->OrientationTop.X);
  in_rItem.gameobjpos.Position.Position.X = in_Position->OrientationFront.Y - v6;
  *(_QWORD *)(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1) = __PAIR64__(
                                                                            LODWORD(in_Position->OrientationTop.X),
                                                                            in_Position->OrientationFront.Z - v5);
  *(_QWORD *)((char *)&in_rItem.resetrtpcvalue + 20) = *(_QWORD *)&in_Position->OrientationTop.Y;
  AkMath::Normalise(&in_rItem.listpos.Position.OrientationFront);
  AkMath::Normalise(&in_rItem.gameObjMultiPos.aMultiPosition[0].Position);
  in_rItem.rtpc.ID = in_ulIndex;
  Y = in_Position->Position.Y;
  in_rItem.gameobjenvvalues.EnvValues[2].auxBusID = LODWORD(in_Position->Position.X);
  in_rItem.event.CustomParam.pExternalSrcs = (AkExternalSourceArray *)__PAIR64__(
                                                                        LODWORD(in_Position->Position.Z),
                                                                        LODWORD(Y));
  v8 = AkQueuedMsg::Sizeof_ListenerPosition();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v8);
}

// File Line: 769
// RVA: 0xA430F0
__int64 __fastcall AK::SoundEngine::SetListenerPipeline(unsigned int in_uIndex, bool in_bAudio, bool in_bFeedback)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.rtpc.ID = in_uIndex;
  in_rItem.listpipe.bAudio = in_bAudio;
  in_rItem.type = 26;
  in_rItem.listpipe.bFeedback = in_bFeedback;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 788
// RVA: 0xA43340
__int64 __fastcall AK::SoundEngine::SetRTPCValue(
        unsigned int in_rtpcID,
        float in_value,
        unsigned __int64 in_gameObjectID,
        unsigned int in_uValueChangeDuration,
        unsigned int in_eFadeCurve)
{
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.event.GameObjID = __PAIR64__(LODWORD(in_value), in_rtpcID);
  in_rItem.rtpc.GameObjID = in_gameObjectID;
  if ( in_uValueChangeDuration )
  {
    in_rItem.event.CustomParam.customParam = __PAIR64__(in_eFadeCurve, in_uValueChangeDuration);
    in_rItem.type = 3;
    ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
  }
  else
  {
    in_rItem.type = 2;
    ClassSize = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  }
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
}

// File Line: 855
// RVA: 0xA43450
__int64 __fastcall AK::SoundEngine::SetSwitch(
        unsigned int in_SwitchGroup,
        unsigned int in_SwitchState,
        unsigned __int64 in_GameObj)
{
  unsigned __int16 ObjectType; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.rtpc.GameObjID = __PAIR64__(in_SwitchState, in_SwitchGroup);
  in_rItem.type = 8;
  ObjectType = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ObjectType);
}

// File Line: 959
// RVA: 0xA433B0
__int64 __fastcall AK::SoundEngine::SetState(unsigned int in_StateGroup, unsigned int in_State)
{
  unsigned __int16 v2; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

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
__int64 __fastcall AK::SoundEngine::SetState(
        unsigned int in_StateGroup,
        unsigned int in_State,
        bool in_bSkipTransitionTime,
        bool in_bSkipExtension)
{
  unsigned __int16 v4; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

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
__int64 __fastcall AK::SoundEngine::SetGameObjectAuxSendValues(
        unsigned __int64 in_GameObj,
        AkAuxSendValue *in_aEnvironmentValues,
        unsigned int in_uNumEnvValues)
{
  hkpSphereShape *v4; // rcx
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( in_uNumEnvValues > 4 )
    return 31i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.event.PlayingID = in_uNumEnvValues;
  in_rItem.type = 18;
  memmove(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1, in_aEnvironmentValues, 8 * in_uNumEnvValues);
  Size = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v4);
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 1143
// RVA: 0xA430B0
__int64 __fastcall AK::SoundEngine::SetGameObjectOutputBusVolume(unsigned __int64 in_GameObj, float in_fControlValue)
{
  unsigned __int16 ObjectType; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.gameobjpos.Position.Position.X = in_fControlValue;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.type = 19;
  ObjectType = Scaleform::GFx::AS2::ExternalInterface::GetObjectType();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ObjectType);
}

// File Line: 1164
// RVA: 0xA43250
__int64 __fastcall AK::SoundEngine::SetObjectObstructionAndOcclusion(
        unsigned __int64 in_ObjectID,
        unsigned int in_uListener,
        float in_fObstructionLevel,
        float in_fOcclusionLevel)
{
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.gameobjpos.Position.Position.Z = in_fOcclusionLevel;
  in_rItem.event.GameObjID = in_ObjectID;
  in_rItem.rtpc.GameObjID = __PAIR64__(LODWORD(in_fObstructionLevel), in_uListener);
  in_rItem.type = 20;
  ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
}

// File Line: 1188
// RVA: 0xA43490
signed __int64 __fastcall AK::SoundEngine::SetVolumeThresholdInternal(
        float in_fVolumeThresholdDB,
        AK::SoundEngine::AkCommandPriority in_uReserved)
{
  float v3; // xmm7_4
  float v5; // xmm9_4
  __m128 v6; // xmm0
  int v7; // edx
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm9_4
  int v12; // ecx
  __m128 v14; // [rsp+20h] [rbp-68h]

  if ( in_fVolumeThresholdDB < -96.300003 )
    return 31i64;
  v3 = 0.0;
  if ( in_fVolumeThresholdDB > 0.0 )
    return 31i64;
  if ( in_uReserved <= g_eVolumeThresholdPriority )
  {
    g_eVolumeThresholdPriority = in_uReserved;
    v6 = (__m128)LODWORD(FLOAT_10_0);
    v5 = in_fVolumeThresholdDB * 0.050000001;
    v6.m128_f32[0] = powf(10.0, v5);
    v7 = `AkMath::FastPow10::`4::`local static guard;
    v8 = v6.m128_f32[0];
    if ( v5 >= -37.0 )
    {
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v9 = FLOAT_2_7866352e7;
        v7 = `AkMath::FastPow10::`4::`local static guard | 1;
        `AkMath::FastPow10::`4::`local static guard |= 1u;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v11 = (float)(v5 * v9) + 1065353200.0;
      v12 = (int)v11 & 0x7FFFFF;
      v6 = (__m128)(unsigned int)(v12 + 1065353216);
      v10 = (float)((float)((float)((float)(COERCE_FLOAT(v12 + 1065353216) * 0.32518977) + 0.020805772)
                          * COERCE_FLOAT(v12 + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)v11 & 0xFF800000);
    }
    else
    {
      v9 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      v10 = 0.0;
    }
    v6.m128_f32[0] = in_fVolumeThresholdDB;
    v14 = _mm_shuffle_ps(v6, v6, 0);
    if ( (float)(v14.m128_f32[0] * 0.050000001) >= -37.0 )
    {
      if ( (v7 & 1) == 0 )
      {
        v9 = FLOAT_2_7866352e7;
        v7 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v3 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((int)(float)((float)(v9 * (float)(v14.m128_f32[0] * 0.050000001))
                                                         + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(
                             ((int)(float)((float)(v9 * (float)(v14.m128_f32[0] * 0.050000001)) + 1065353200.0) & 0x7FFFFF)
                           + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((int)(float)((float)(v9 * (float)(v14.m128_f32[0] * 0.050000001)) + 1065353200.0) & 0xFF800000);
    }
    if ( (float)(v14.m128_f32[1] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[2] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[3] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[3] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[0] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[1] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      v7 |= 1u;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7;
    }
    if ( (float)(v14.m128_f32[2] * 0.050000001) >= -37.0 && (v7 & 1) == 0 )
    {
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard = v7 | 1;
    }
    if ( v8 <= v10 )
      v8 = v10;
    if ( v8 > v3 )
    {
      g_fVolumeThreshold = v8;
      g_fVolumeThresholdDB = in_fVolumeThresholdDB;
      return 1i64;
    }
    g_fVolumeThreshold = v3;
    g_fVolumeThresholdDB = in_fVolumeThresholdDB;
  }
  return 1i64;
}

// File Line: 1315
// RVA: 0xA43220
signed __int64 __fastcall AK::SoundEngine::SetMaxNumVoicesLimitInternal(
        unsigned __int16 in_maxNumberVoices,
        AK::SoundEngine::AkCommandPriority in_uReserved)
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
AkExternalSourceArray *__fastcall AK::SoundEngine::PostEvent(
        unsigned int in_ulEventID,
        unsigned __int64 in_GameObjID,
        unsigned int in_uiFlags,
        void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *),
        void *in_pCookie,
        unsigned int in_cExternals,
        AkExternalSourceInfo *in_pExternalSources,
        unsigned int in_PlayingID)
{
  AkCustomParamType *in_pCustomParam; // r10
  AkExternalSourceArray *result; // rax
  AkExternalSourceArray *pExternalSrcs; // rbx
  unsigned int v15; // esi
  AkCustomParamType v16; // [rsp+40h] [rbp-28h] BYREF

  in_pCustomParam = 0i64;
  if ( in_cExternals )
  {
    v16.customParam = 0i64;
    v16.ui32Reserved = 0;
    result = AkExternalSourceArray::Create(in_cExternals, in_pExternalSources);
    pExternalSrcs = result;
    v16.pExternalSrcs = result;
    if ( !result )
      return result;
    in_pCustomParam = &v16;
  }
  else
  {
    pExternalSrcs = v16.pExternalSrcs;
  }
  v15 = AK::SoundEngine::PostEvent(
          in_ulEventID,
          in_GameObjID,
          in_uiFlags,
          in_pfnCallback,
          in_pCookie,
          in_pCustomParam,
          in_PlayingID);
  if ( !v15 )
  {
    if ( in_cExternals )
      AkExternalSourceArray::Release(pExternalSrcs);
  }
  return (AkExternalSourceArray *)v15;
}

// File Line: 1406
// RVA: 0xA427C0
__int64 __fastcall AK::SoundEngine::PostEvent(
        unsigned int in_ulEventID,
        unsigned __int64 in_GameObjID,
        unsigned int in_uiFlags,
        void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *),
        void *in_pCookie,
        AkCustomParamType *in_pCustomParam,
        unsigned int in_PlayingID)
{
  AkExternalSourceArray *pExternalSrcs; // rax
  hkpSphereShape *v11; // rcx
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+30h] [rbp-48h] BYREF

  in_rItem.type = 1;
  if ( in_pCustomParam )
  {
    *((_OWORD *)&in_rItem.gameobjdrylevel + 1) = *(_OWORD *)&in_pCustomParam->customParam;
    pExternalSrcs = in_pCustomParam->pExternalSrcs;
  }
  else
  {
    pExternalSrcs = 0i64;
    in_rItem.event.CustomParam.customParam = 0i64;
    in_rItem.event.CustomParam.ui32Reserved = 0;
  }
  in_rItem.event.CustomParam.pExternalSrcs = pExternalSrcs;
  in_rItem.event.Event = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                       (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                       in_ulEventID);
  if ( !in_rItem.event.Event )
    return 0i64;
  in_rItem.event.GameObjID = in_GameObjID;
  in_rItem.rtpc.GameObjID = __PAIR64__(in_PlayingID, _InterlockedIncrement((volatile signed __int32 *)&g_PlayingID));
  if ( (unsigned int)CAkPlayingMgr::AddPlayingID(
                       g_pPlayingMgr,
                       &in_rItem.event,
                       in_pfnCallback,
                       in_pCookie,
                       in_uiFlags,
                       in_rItem.event.Event->key) != 1 )
  {
    in_rItem.event.Event->vfptr->Release(in_rItem.event.Event);
    return 0i64;
  }
  Size = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v11);
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
  return in_rItem.event.PlayingID;
}

// File Line: 1584
// RVA: 0xA41EB0
__int64 __fastcall AK::SoundEngine::ExecuteActionOnEvent(
        unsigned int in_eventID,
        int in_ActionType,
        unsigned __int64 in_gameObjectID,
        unsigned int in_uTransitionDuration,
        unsigned int in_eFadeCurve,
        unsigned int in_PlayingID)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.type = 31;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.rtpc.GameObjID = in_gameObjectID;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = in_ActionType;
  *(_QWORD *)((char *)&in_rItem.resetrtpcvalue + 20) = __PAIR64__(in_eFadeCurve, in_uTransitionDuration);
  in_rItem.gameobjenvvalues.EnvValues[2].auxBusID = in_PlayingID;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 1642
// RVA: 0xA42F10
__int64 __fastcall AK::SoundEngine::SeekOnEvent(
        unsigned int in_eventID,
        unsigned __int64 in_gameObjectID,
        int in_iPosition,
        bool in_bSeekToNearestMarker)
{
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.type = 35;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.rtpc.GameObjID = in_gameObjectID;
  in_rItem.seek.bIsSeekRelativeToDuration = 0;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = in_iPosition;
  in_rItem.seek.bSnapToMarker = in_bSeekToNearestMarker;
  ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
}

// File Line: 1695
// RVA: 0xA42FB0
__int64 __fastcall AK::SoundEngine::SeekOnEvent(
        unsigned int in_eventID,
        unsigned __int64 in_gameObjectID,
        float in_fPercent,
        bool in_bSeekToNearestMarker)
{
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-58h] BYREF

  in_rItem.type = 35;
  in_rItem.event.GameObjID = (unsigned __int64)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                                 in_eventID);
  if ( !in_rItem.event.GameObjID )
    return 2i64;
  in_rItem.gameobjpos.Position.Position.Z = in_fPercent;
  in_rItem.rtpc.GameObjID = in_gameObjectID;
  in_rItem.seek.bIsSeekRelativeToDuration = 1;
  in_rItem.seek.bSnapToMarker = in_bSeekToNearestMarker;
  ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
}

// File Line: 1760
// RVA: 0xA421D0
AKRESULT __fastcall AK::SoundEngine::GetSourcePlayPosition(
        unsigned int in_PlayingID,
        int *out_puPosition,
        bool in_bExtrapolate)
{
  if ( out_puPosition )
    return CAkPositionRepository::GetCurrPosition(g_pPositionRepository, in_PlayingID, out_puPosition, in_bExtrapolate);
  else
    return 31;
}

// File Line: 1779
// RVA: 0xA42E90
CAkIndexable *__fastcall AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(
        unsigned int in_eventID,
        unsigned int *in_aArgumentValues,
        unsigned int in_uNumArguments,
        unsigned int in_idSequence)
{
  CAkIndexable *result; // rax
  CAkIndexable *v8; // rdi
  unsigned int v9; // ebx

  result = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
             (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDialogueEvents,
             in_eventID);
  v8 = result;
  if ( result )
  {
    v9 = AkDecisionTree::ResolvePath(
           (AkDecisionTree *)&result[1],
           result->key,
           in_aArgumentValues,
           in_uNumArguments,
           in_idSequence);
    v8->vfptr->Release(v8);
    return (CAkIndexable *)v9;
  }
  return result;
}

// File Line: 1868
// RVA: 0xA42570
__int64 __fastcall AK::SoundEngine::DynamicSequence::Open(
        unsigned __int64 in_gameObjectID,
        unsigned int in_uiFlags,
        void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *),
        void *in_pCookie,
        AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  unsigned int v9; // ecx
  hkpSphereShape *v10; // rcx
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+30h] [rbp-48h] BYREF

  in_rItem.type = 22;
  v9 = _InterlockedIncrement((volatile signed __int32 *)&g_PlayingID);
  in_rItem.rtpc.GameObjID = v9;
  in_rItem.event.Event = (CAkEvent *)CAkDynamicSequence::Create(v9, in_eDynamicSequenceType);
  if ( !in_rItem.event.Event )
    return 0i64;
  in_rItem.event.GameObjID = in_gameObjectID;
  in_rItem.event.CustomParam.customParam = 0i64;
  in_rItem.event.CustomParam.ui32Reserved = 0;
  in_rItem.event.CustomParam.pExternalSrcs = 0i64;
  if ( (unsigned int)CAkPlayingMgr::AddPlayingID(
                       g_pPlayingMgr,
                       &in_rItem.event,
                       in_pfnCallback,
                       in_pCookie,
                       in_uiFlags,
                       0) != 1 )
  {
    in_rItem.event.Event->vfptr->Release(in_rItem.event.Event);
    return 0i64;
  }
  Size = Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::GetSize(v10);
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
  return in_rItem.event.PlayingID;
}

// File Line: 1954
// RVA: 0xA42660
__int64 __fastcall AK::SoundEngine::DynamicSequence::Play(
        unsigned int in_playingID,
        unsigned int in_uTransitionDuration,
        unsigned int in_eFadeCurve)
{
  CAkIndexable *PtrAndAddRef; // rax
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.type = 23;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
                   in_playingID);
  in_rItem.event.GameObjID = (unsigned __int64)PtrAndAddRef;
  if ( PtrAndAddRef )
  {
    if ( !LOBYTE(PtrAndAddRef[5].pNextItem) )
    {
      in_rItem.event.PlayingID = 0;
      *(_QWORD *)(&in_rItem.gameobjactcontroller.uActiveControllerMask + 1) = __PAIR64__(
                                                                                in_eFadeCurve,
                                                                                in_uTransitionDuration);
      ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
      return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
    }
    PtrAndAddRef->vfptr->Release(PtrAndAddRef);
  }
  return 2i64;
}

// File Line: 1979
// RVA: 0xA41CB0
__int64 __fastcall AK::SoundEngine::DynamicSequence::Close(unsigned int in_playingID)
{
  CAkIndexable *PtrAndAddRef; // rax
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.type = 23;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
                   in_playingID);
  in_rItem.event.GameObjID = (unsigned __int64)PtrAndAddRef;
  if ( PtrAndAddRef )
  {
    if ( !LOBYTE(PtrAndAddRef[5].pNextItem) )
    {
      LOBYTE(PtrAndAddRef[5].pNextItem) = 1;
      in_rItem.rtpc.GameObjID = 3i64;
      in_rItem.rtpcWithTransition.transParams.TransitionTime = 4;
      ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
      return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
    }
    PtrAndAddRef->vfptr->Release(PtrAndAddRef);
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
    return (CAkIndexable *)&v2[1].m_uLength;
  }
  return result;
}

// File Line: 2008
// RVA: 0xA43CC0
__int64 __fastcall AK::SoundEngine::DynamicSequence::UnlockPlaylist(unsigned int in_playingID)
{
  CAkDynamicSequence *PtrAndAddRef; // rax
  CAkDynamicSequence *v2; // rbx

  PtrAndAddRef = (CAkDynamicSequence *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDynamicSequences,
                                         in_playingID);
  v2 = PtrAndAddRef;
  if ( !PtrAndAddRef )
    return 2i64;
  CAkDynamicSequence::UnlockPlaylist(PtrAndAddRef);
  v2->vfptr->Release(v2);
  return 1i64;
}

// File Line: 2046
// RVA: 0xA42CE0
__int64 __fastcall AK::SoundEngine::RegisterGameObj(
        unsigned __int64 in_GameObj,
        const char *in_pszObjName,
        unsigned int in_uListenerMask)
{
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( in_GameObj - 1 > 0xFFFFFFFFFFFFFFFDui64 )
    return 2i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.event.PlayingID = in_uListenerMask;
  in_rItem.type = 11;
  in_rItem.event.CustomParam.customParam = 0i64;
  ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
}

// File Line: 2068
// RVA: 0xA43D10
__int64 __fastcall AK::SoundEngine::UnregisterGameObj(unsigned __int64 in_GameObj)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( !in_GameObj )
    return 2i64;
  in_rItem.event.GameObjID = in_GameObj;
  in_rItem.type = 12;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 2098
// RVA: 0xA41E90
void __fastcall AK::SoundEngine::DefaultBankCallbackFunc(
        unsigned int __formal,
        const void *a2,
        AKRESULT in_eLoadResult,
        int in_memPoolId,
        void *in_pCookie)
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
  unsigned int v2; // [rsp+20h] [rbp-98h] BYREF
  HANDLE hObject; // [rsp+28h] [rbp-90h]
  CAkBankMgr::AkBankQueueItem v4; // [rsp+38h] [rbp-80h]
  CAkBankMgr::AkBankQueueItem v5; // [rsp+70h] [rbp-48h] BYREF

  if ( !g_pBankManager )
    return 2i64;
  result = AK::SoundEngine::ClearPreparedEvents();
  if ( (_DWORD)result == 1 )
  {
    hObject = CreateEventW(0i64, 0, 0, 0i64);
    if ( !hObject )
      return 2i64;
    v4.eType = QueueItemClearBanks;
    v4.callbackInfo.pfnBankCallback = AK::SoundEngine::DefaultBankCallbackFunc;
    v4.bankLoadFlag = AkBankLoadFlag_None;
    v4.callbackInfo.pCookie = &v2;
    v5 = v4;
    v1 = CAkBankMgr::QueueBankCommand(g_pBankManager, &v5);
    if ( v1 == 1 )
    {
      WaitForSingleObject(hObject, 0xFFFFFFFF);
      if ( hObject )
        CloseHandle(hObject);
      return v2;
    }
    else if ( hObject )
    {
      CloseHandle(hObject);
      return v1;
    }
    return v1;
  }
  return result;
}

// File Line: 2518
// RVA: 0xA424A0
__int64 __fastcall AK::SoundEngine::LoadBank(
        unsigned int in_bankID,
        void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *),
        void *in_pCookie,
        unsigned int in_memPoolId)
{
  __int128 v5; // [rsp+20h] [rbp-88h]
  __int128 v6; // [rsp+30h] [rbp-78h]
  unsigned int *v7; // [rsp+50h] [rbp-58h]
  CAkBankMgr::AkBankQueueItem v8; // [rsp+60h] [rbp-48h] BYREF

  LODWORD(v5) = 0;
  *((_QWORD *)&v5 + 1) = in_pfnBankCallback;
  *(_QWORD *)&v6 = in_pCookie;
  LODWORD(v7) = 0;
  DWORD2(v6) = 2;
  *(_OWORD *)&v8.eType = v5;
  *(_OWORD *)&v8.callbackInfo.pCookie = v6;
  v8.prepare = (AkPrepareEventQueueItemLoad)__PAIR64__(in_memPoolId, in_bankID);
  v8.gameSync.pGameSyncID = v7;
  return CAkBankMgr::QueueBankCommand(g_pBankManager, &v8);
}

// File Line: 2659
// RVA: 0xA43C40
__int64 __fastcall AK::SoundEngine::UnloadBank(
        unsigned int in_bankID,
        unsigned int *in_pInMemoryBankPtr,
        void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *),
        void *in_pCookie)
{
  CAkBankMgr::AkBankQueueItem v5; // [rsp+20h] [rbp-88h]
  CAkBankMgr::AkBankQueueItem v6; // [rsp+60h] [rbp-48h] BYREF

  *(_QWORD *)&v5.prepare.numEvents = in_bankID | 0xFFFFFFFF00000000ui64;
  v5.eType = QueueItemUnload;
  v5.prepare.pEventID = in_pInMemoryBankPtr;
  v5.callbackInfo.pfnBankCallback = in_pfnBankCallback;
  v5.callbackInfo.pCookie = in_pCookie;
  v5.load.ui32InMemoryBankSize = 0;
  v5.bankLoadFlag = in_pInMemoryBankPtr != 0i64;
  v6 = v5;
  return CAkBankMgr::QueueBankCommand(g_pBankManager, &v6);
}

// File Line: 2983
// RVA: 0xA41BB0
signed __int64 __fastcall AK::SoundEngine::ClearPreparedEvents()
{
  unsigned int v1; // ebx
  unsigned int v2; // [rsp+20h] [rbp-98h] BYREF
  HANDLE hObject; // [rsp+28h] [rbp-90h]
  CAkBankMgr::AkBankQueueItem v4; // [rsp+38h] [rbp-80h]
  CAkBankMgr::AkBankQueueItem v5; // [rsp+70h] [rbp-48h] BYREF

  hObject = CreateEventW(0i64, 0, 0, 0i64);
  if ( !hObject )
    return 2i64;
  v4.eType = QueueItemUnprepareAllEvents;
  v4.callbackInfo.pfnBankCallback = AK::SoundEngine::DefaultBankCallbackFunc;
  v4.bankLoadFlag = AkBankLoadFlag_None;
  v4.callbackInfo.pCookie = &v2;
  v5 = v4;
  v1 = CAkBankMgr::QueueBankCommand(g_pBankManager, &v5);
  if ( v1 == 1 )
  {
    WaitForSingleObject(hObject, 0xFFFFFFFF);
    if ( hObject )
      CloseHandle(hObject);
    return v2;
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
__int64 __fastcall AK::SoundEngine::AddBehavioralExtension(void (__fastcall *in_pCallback)(bool))
{
  unsigned __int64 v1; // r8
  unsigned int m_ulReserved; // esi
  void (__fastcall **v3)(bool); // rbx
  unsigned __int64 m_uLength; // rbp
  void (__fastcall **m_pItems)(bool); // rdi
  void (__fastcall **v7)(bool); // rdx
  unsigned __int64 v8; // rcx
  void (__fastcall *v9)(bool); // rax
  __int64 result; // rax

  LODWORD(v1) = g_aBehavioralExtensions.m_uLength;
  m_ulReserved = g_aBehavioralExtensions.m_ulReserved;
  v3 = 0i64;
  m_uLength = g_aBehavioralExtensions.m_uLength;
  if ( g_aBehavioralExtensions.m_uLength < (unsigned __int64)g_aBehavioralExtensions.m_ulReserved )
  {
    m_pItems = g_aBehavioralExtensions.m_pItems;
  }
  else
  {
    m_ulReserved = g_aBehavioralExtensions.m_ulReserved + 1;
    m_pItems = (void (__fastcall **)(bool))AK::MemoryMgr::Malloc(
                                             g_DefaultPoolId,
                                             8i64 * (g_aBehavioralExtensions.m_ulReserved + 1));
    if ( !m_pItems )
      goto LABEL_12;
    v7 = g_aBehavioralExtensions.m_pItems;
    v1 = g_aBehavioralExtensions.m_uLength;
    if ( g_aBehavioralExtensions.m_pItems )
    {
      v8 = 0i64;
      if ( g_aBehavioralExtensions.m_uLength )
      {
        do
        {
          v9 = v7[v8++];
          m_pItems[v8 - 1] = v9;
          v7 = g_aBehavioralExtensions.m_pItems;
        }
        while ( v8 < v1 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      LODWORD(v1) = g_aBehavioralExtensions.m_uLength;
    }
    g_aBehavioralExtensions.m_pItems = m_pItems;
    g_aBehavioralExtensions.m_ulReserved = m_ulReserved;
  }
  if ( m_uLength < m_ulReserved )
  {
    v3 = &m_pItems[(unsigned int)v1];
    g_aBehavioralExtensions.m_uLength = v1 + 1;
    if ( v3 )
      *v3 = in_pCallback;
  }
LABEL_12:
  result = 52i64;
  if ( v3 )
    return 1i64;
  return result;
}

// File Line: 3373
// RVA: 0xA42DC0
__int64 __fastcall AK::SoundEngine::RemoveBehavioralExtension(void (__fastcall *in_pCallback)(bool))
{
  void (__fastcall **m_pItems)(bool); // rdi
  unsigned int m_uLength; // edx
  void (__fastcall **v3)(bool); // rax
  __int64 result; // rax

  m_pItems = g_aBehavioralExtensions.m_pItems;
  m_uLength = g_aBehavioralExtensions.m_uLength;
  v3 = &g_aBehavioralExtensions.m_pItems[g_aBehavioralExtensions.m_uLength];
  if ( g_aBehavioralExtensions.m_pItems == v3 )
    return 2i64;
  do
  {
    if ( *m_pItems == in_pCallback )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v3 );
  if ( m_pItems == v3 )
    return 2i64;
  if ( m_pItems < v3 - 1 )
  {
    qmemcpy(m_pItems, m_pItems + 1, 8 * (((unsigned __int64)((char *)(v3 - 1) - (char *)m_pItems - 1) >> 3) + 1));
    m_uLength = g_aBehavioralExtensions.m_uLength;
  }
  result = 1i64;
  g_aBehavioralExtensions.m_uLength = m_uLength - 1;
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
void __fastcall AK::SoundEngine::AddExternalBankHandler(
        AKRESULT (__fastcall *in_pCallback)(AkBank::AKBKSubHircSection *, CAkUsageSlot *, unsigned int))
{
  g_pExternalBankHandlerCallback = in_pCallback;
}

// File Line: 3522
// RVA: 0xA428D0
__int64 __fastcall AK::SoundEngine::PreInit(AkInitSettings *io_pSettings)
{
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
  LARGE_INTEGER Frequency; // [rsp+30h] [rbp+8h] BYREF

  v2 = 1;
  QueryPerformanceFrequency(&Frequency);
  AK::g_fFreqRatio = (float)(int)(Frequency.QuadPart / 1000);
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
    v2 = CAkTransitionManager::Init(v17, g_settings.uMaxNumTransitions);
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
    v2 = CAkPathManager::Init(v19, g_settings.uMaxNumPaths);
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
  if ( io_pSettings )
    *io_pSettings = g_settings;
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
  if ( !g_pAudioMgr && result == AK_Success )
  {
    v1 = (CAkAudioMgr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF0ui64);
    if ( v1 )
    {
      CAkAudioMgr::CAkAudioMgr(v1);
      g_pAudioMgr = v2;
      if ( v2 )
      {
        result = CAkAudioMgr::Init(v2);
        if ( result == AK_Success )
          return CAkAudioMgr::Start(g_pAudioMgr);
        return result;
      }
    }
    else
    {
      g_pAudioMgr = 0i64;
    }
    return 52;
  }
  return result;
}

// File Line: 3676
// RVA: 0xA437F0
void __fastcall AK::SoundEngine::StopAll(unsigned __int64 in_gameObjectID)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.event.GameObjID = in_gameObjectID;
  in_rItem.type = 25;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 3689
// RVA: 0xA43830
void __fastcall AK::SoundEngine::StopPlayingID(
        unsigned int in_playingID,
        unsigned int in_uTransitionDuration,
        unsigned int in_eFadeCurve)
{
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( in_playingID )
  {
    in_rItem.event.GameObjID = __PAIR64__(in_uTransitionDuration, in_playingID);
    in_rItem.type = 30;
    in_rItem.event.PlayingID = in_eFadeCurve;
    v3 = UFG::SocialLogData_NewHighScore::VariableBindingListSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
  }
}

// File Line: 3889
// RVA: 0xA41A40
__int64 __fastcall AK::MotionEngine::AddPlayerMotionDevice(
        unsigned __int8 in_iPlayerID,
        unsigned int in_iCompanyID,
        unsigned __int16 in_iDevicePluginID,
        unsigned __int64 in_pDevice)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( in_iPlayerID > 3u )
    return 2i64;
  in_rItem.rtpc.GameObjID = in_pDevice;
  in_rItem.playerdevice.bAdd = 1;
  in_rItem.type = 27;
  in_rItem.gameobjenvvalues.EnvValues[1].auxBusID = in_iPlayerID;
  in_rItem.rtpcWithTransition.transParams.TransitionTime = in_iDevicePluginID;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
  return CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 3920
// RVA: 0xA42E30
void __fastcall AK::MotionEngine::RemovePlayerMotionDevice(
        unsigned __int8 in_iPlayerID,
        unsigned int in_iCompanyID,
        unsigned __int16 in_iDevicePluginID)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  if ( in_iPlayerID <= 3u )
  {
    in_rItem.rtpc.GameObjID = 0i64;
    in_rItem.playerdevice.bAdd = 0;
    in_rItem.type = 27;
    in_rItem.gameobjenvvalues.EnvValues[1].auxBusID = in_iPlayerID;
    in_rItem.rtpcWithTransition.transParams.TransitionTime = in_iDevicePluginID;
    Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
  }
}

// File Line: 3939
// RVA: 0xA42D40
// attributes: thunk
void __fastcall AK::MotionEngine::RegisterMotionDevice(
        unsigned int in_ulCompanyID,
        unsigned int in_ulPluginID,
        AK::IAkPlugin *(__fastcall *in_pCreateFunc)(AK::IAkPluginMemAlloc *))
{
  CAkEffectsMgr::RegisterFeedbackBus(in_ulCompanyID, in_ulPluginID, in_pCreateFunc);
}

// File Line: 3956
// RVA: 0xA432A0
void __fastcall AK::MotionEngine::SetPlayerVolume(unsigned __int8 in_iPlayerID, float in_fVolume)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  in_rItem.playervolume.fVolume = in_fVolume;
  in_rItem.type = 29;
  in_rItem.setstate.StateID = in_iPlayerID;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
}

// File Line: 4065
// RVA: 0xA41D30
AkExternalSourceArray *__fastcall AkExternalSourceArray::Create(unsigned int in_nCount, AkExternalSourceInfo *in_pSrcs)
{
  AkExternalSourceArray *result; // rax
  AkExternalSourceArray *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebp
  wchar_t **p_szFile; // rbx
  signed __int64 v9; // r12
  __int64 v10; // rax
  bool v11; // zf
  unsigned int v12; // r14d
  wchar_t *v13; // rax
  wchar_t *szFile; // rdx

  result = (AkExternalSourceArray *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 32 * (in_nCount - 1) + 40);
  v5 = result;
  if ( !result )
    return result;
  v6 = 0;
  result->m_cRefCount = 1;
  result->m_nCount = in_nCount;
  v7 = 0;
  if ( !in_nCount )
    return v5;
  p_szFile = &in_pSrcs->szFile;
  v9 = (char *)result - (char *)in_pSrcs;
  while ( 1 )
  {
    *(wchar_t **)((char *)p_szFile + v9) = *(p_szFile - 1);
    *(wchar_t **)((char *)p_szFile + v9 + 8) = *p_szFile;
    *(wchar_t **)((char *)p_szFile + v9 + 16) = p_szFile[1];
    *(wchar_t **)((char *)p_szFile + v9 + 24) = p_szFile[2];
    if ( *p_szFile )
      break;
LABEL_9:
    ++v7;
    p_szFile += 4;
    if ( v7 >= in_nCount )
      return v5;
  }
  v10 = -1i64;
  do
    v11 = (*p_szFile)[++v10] == 0;
  while ( !v11 );
  v12 = 2 * v10 + 2;
  v13 = (wchar_t *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v12);
  *(wchar_t **)((char *)p_szFile + v9 + 8) = v13;
  if ( v13 )
  {
    memmove(v13, *p_szFile, v12);
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
        szFile = v5->m_pSrcs[v6].szFile;
        if ( szFile )
          AK::MemoryMgr::Free(g_DefaultPoolId, szFile);
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
  unsigned int i; // ebx
  wchar_t *szFile; // rdx

  if ( this->m_cRefCount-- == 1 )
  {
    for ( i = 0; i < this->m_nCount; ++i )
    {
      szFile = this->m_pSrcs[i].szFile;
      if ( szFile )
        AK::MemoryMgr::Free(g_DefaultPoolId, szFile);
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, this);
  }
}

