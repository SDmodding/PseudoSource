// File Line: 53
// RVA: 0xAA9890
signed __int64 __fastcall AK::MusicEngine::Init(AkMusicSettings *in_pSettings)
{
  if ( !CAkMusicRenderer::Create(in_pSettings) )
    return 2i64;
  AK::SoundEngine::AddBehavioralExtension(CAkMusicRenderer::PerformNextFrameBehavior);
  AK::SoundEngine::AddExternalStateHandler(CAkMusicRenderer::SetState);
  AK::SoundEngine::AddExternalBankHandler(AkMusicBank::LoadBankItem);
  return 1i64;
}

// File Line: 76
// RVA: 0xAA97D0
void __fastcall AK::MusicEngine::GetDefaultInitSettings(AkMusicSettings *out_settings)
{
  out_settings->fStreamingLookAheadRatio = 1.0;
}

// File Line: 81
// RVA: 0xAAA480
void __fastcall AK::MusicEngine::Term(AK::MusicEngine *this)
{
  JUMPOUT(CAkMusicRenderer::m_pMusicRenderer, 0i64, CAkMusicRenderer::Destroy);
}

// File Line: 92
// RVA: 0xAA97E0
AKRESULT __fastcall AK::MusicEngine::GetPlayingSegmentInfo(unsigned int in_PlayingID, AkSegmentInfo *out_segmentInfo, bool in_bExtrapolate)
{
  return CAkSegmentInfoRepository::GetSegmentInfo(
           &CAkMusicRenderer::m_segmentInfoRepository,
           in_PlayingID,
           out_segmentInfo,
           in_bExtrapolate);
}

// File Line: 110
// RVA: 0x15BE100
__int64 dynamic_initializer_for__CAkMusicRenderer::m_listCtx__()
{
  return atexit(dynamic_atexit_destructor_for__CAkMusicRenderer::m_listCtx__);
}

// File Line: 111
// RVA: 0x15BE120
__int64 dynamic_initializer_for__CAkMusicRenderer::m_segmentInfoRepository__()
{
  CAkBusCallbackMgr::CAkBusCallbackMgr(&CAkMusicRenderer::m_segmentInfoRepository);
  return atexit(dynamic_atexit_destructor_for__CAkMusicRenderer::m_segmentInfoRepository__);
}

// File Line: 112
// RVA: 0x15BE110
__int64 dynamic_initializer_for__CAkMusicRenderer::m_queuePendingStateChanges__()
{
  return atexit(dynamic_atexit_destructor_for__CAkMusicRenderer::m_queuePendingStateChanges__);
}

// File Line: 123
// RVA: 0xAA95B0
CAkMusicRenderer *__fastcall CAkMusicRenderer::Create(AkMusicSettings *in_pSettings)
{
  CAkMusicRenderer *result; // rax
  AkMusicSettings *v2; // rbx
  CAkMusicRenderer *v3; // rax

  result = CAkMusicRenderer::m_pMusicRenderer;
  v2 = in_pSettings;
  if ( !CAkMusicRenderer::m_pMusicRenderer )
  {
    v3 = (CAkMusicRenderer *)AK::MemoryMgr::Malloc(
                               g_DefaultPoolId,
                               (unsigned int)((_DWORD)CAkMusicRenderer::m_pMusicRenderer + 1));
    if ( v3 )
    {
      CAkMusicRenderer::m_pMusicRenderer = v3;
      if ( CAkMusicRenderer::Init(v3, v2) == 1 )
        return CAkMusicRenderer::m_pMusicRenderer;
      CAkMusicRenderer::Destroy(CAkMusicRenderer::m_pMusicRenderer);
    }
    result = 0i64;
    CAkMusicRenderer::m_pMusicRenderer = 0i64;
  }
  return result;
}

// File Line: 145
// RVA: 0xAA9620
void __fastcall CAkMusicRenderer::Destroy(CAkMusicRenderer *this)
{
  CAkMusicRenderer *v1; // rdi
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v2; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v3; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v5; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v6; // rbx

  v1 = this;
  AK::SoundEngine::StopAll(0xFFFFFFFFFFFFFFFFui64);
  AK::SoundEngine::RenderAudio();
  while ( CAkMusicRenderer::m_listCtx.m_pFirst )
    WaitForSingleObject(CAkMusicRenderer::m_hTermEvent, 0xFFFFFFFF);
  if ( CAkMusicRenderer::m_hTermEvent )
    CloseHandle(CAkMusicRenderer::m_hTermEvent);
  CAkMusicRenderer::m_hTermEvent = 0i64;
  CAkMusicRenderer::m_listCtx.m_pFirst = 0i64;
  CAkMusicRenderer::m_listCtx.m_pLast = 0i64;
  CAkLimiter::Term(&CAkMusicRenderer::m_segmentInfoRepository);
  if ( CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems > 0 )
  {
    v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
    while ( 1 )
    {
      v3 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
      if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
        break;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst->pNextListItem;
      v4 = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
      if ( v3 == CAkMusicRenderer::m_queuePendingStateChanges.m_pLast )
        v4 = 0i64;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = v4;
      if ( v3 < CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart
        || v3 >= &CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart[(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
        v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
        --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
      }
      else
      {
        v3->pNextListItem = v2;
        --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
        v2 = v3;
        CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = v3;
      }
    }
    v5 = CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart;
    if ( v2 )
    {
      do
      {
        v6 = v2->pNextListItem;
        if ( v2 < v5 || v2 >= &v5[CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v2);
          v5 = CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart;
        }
        v2 = v6;
      }
      while ( v6 );
    }
    if ( v5 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    *(_QWORD *)&CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = 0i64;
  }
  if ( v1 )
  {
    CAkMusicRenderer::m_pMusicRenderer = 0i64;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
  }
}

// File Line: 170
// RVA: 0xAA9800
signed __int64 __fastcall CAkMusicRenderer::Init(CAkMusicRenderer *this, AkMusicSettings *in_pSettings)
{
  HANDLE v2; // rax
  signed __int64 result; // rax

  if ( in_pSettings )
    CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio = in_pSettings->fStreamingLookAheadRatio;
  else
    LODWORD(CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio) = (AkMusicSettings)FLOAT_1_0;
  _((AMD_HD3D *)&CAkMusicRenderer::m_segmentInfoRepository);
  v2 = CreateEventW(0i64, 0, 0, 0i64);
  CAkMusicRenderer::m_hTermEvent = v2;
  result = 2 - (unsigned int)(v2 != 0i64);
  if ( (_DWORD)result == 1 )
  {
    CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems = -1;
    CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems = 0;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = 0i64;
    result = 1i64;
  }
  return result;
}

// File Line: 221
// RVA: 0xAA9AD0
signed __int64 __fastcall CAkMusicRenderer::Play(CAkMusicCtx *io_pParentCtx, CAkSoundBase *in_pSound, CAkSource *in_pSource, CAkRegisteredObj *in_pGameObj, TransParams *in_transParams, UserParams *in_rUserparams, AkTrackSrc *in_pSrcInfo, unsigned int in_uSourceOffset, unsigned int in_uFrameOffset, CAkMusicPBI **out_pPBI)
{
  CAkRegisteredObj *v10; // r15
  CAkSource *v11; // r13
  CAkSoundBase *v12; // rdi
  unsigned int v13; // esi
  AKRESULT v15; // eax
  UserParams *v16; // r12
  AKRESULT v17; // ebx
  CAkIndexableVtbl *v18; // rax
  int v19; // eax
  bool v20; // cl
  AkBelowThresholdBehavior v21; // eax
  CAkMusicPBI *v22; // rcx
  CAkLimiter *v23; // ST60_8
  CAkLimiter *v24; // rax
  CAkMusicPBI *v25; // rax
  CAkMusicPBI *v26; // rcx
  CAkMusicPBI **v27; // rbx
  __int64 v28; // rdx
  CAkMusicPBI *v29; // rdi
  int v30; // er14
  CAkIndexableVtbl *v31; // rax
  unsigned __int64 v32; // r8
  float out_fMaxRadius; // [rsp+70h] [rbp-90h]
  float v34; // [rsp+78h] [rbp-88h]
  CAkRegisteredObj *v35; // [rsp+80h] [rbp-80h]
  CAkLimiter *v36; // [rsp+88h] [rbp-78h]
  CAkLimiter *v37; // [rsp+90h] [rbp-70h]
  int v38; // [rsp+98h] [rbp-68h]
  __int16 v39; // [rsp+9Ch] [rbp-64h]
  PriorityInfoCurrent result; // [rsp+A0h] [rbp-60h]
  AkVirtualQueueBehavior out_Behavior; // [rsp+B0h] [rbp-50h]
  int v42; // [rsp+C0h] [rbp-40h]
  CAkRegisteredObj *v43; // [rsp+C8h] [rbp-38h]
  __int64 v44; // [rsp+D0h] [rbp-30h]
  __int64 v45; // [rsp+D8h] [rbp-28h]
  int v46; // [rsp+E0h] [rbp-20h]
  __int16 v47; // [rsp+E4h] [rbp-1Ch]
  int v48; // [rsp+104h] [rbp+4h]
  __int64 v49; // [rsp+110h] [rbp+10h]
  int v50; // [rsp+118h] [rbp+18h]
  __int128 v51; // [rsp+120h] [rbp+20h]
  CAkMusicCtx *v52; // [rsp+170h] [rbp+70h]
  AkMonitorData::NotificationReason out_eReasonOfFailure; // [rsp+178h] [rbp+78h]

  v52 = io_pParentCtx;
  v10 = in_pGameObj;
  v11 = in_pSource;
  v12 = in_pSound;
  v13 = 2;
  if ( !in_pSound )
    return 31i64;
  CAkURenderer::_CalcInitialPriority(&result, in_pSound, in_pGameObj, &out_fMaxRadius);
  v15 = CAkURenderer::ValidateLimits(result.currentPriority.priority, &out_eReasonOfFailure);
  v16 = in_rUserparams;
  v17 = v15;
  if ( v15 == 2 )
  {
    v13 = 3;
    goto LABEL_21;
  }
  v36 = 0i64;
  v37 = 0i64;
  v18 = v12->vfptr;
  v34 = result.currentPriority.priority;
  v38 = 3;
  v39 = 256;
  v35 = v10;
  v19 = ((__int64 (__fastcall *)(CAkSoundBase *, float *))v18[8].Release)(v12, &v34);
  v20 = v19 != 2;
  if ( v19 == 80 || v17 == 80 )
  {
    v21 = (unsigned int)CAkParameterNode::GetVirtualBehavior((CAkParameterNode *)&v12->vfptr, &out_Behavior);
    v20 = CAkURenderer::GetVirtualBehaviorAction(v21);
  }
  if ( !v20 )
  {
    v13 = 3;
    out_eReasonOfFailure = 32;
    goto LABEL_18;
  }
  v49 = 0i64;
  v50 = 0;
  v48 = 0;
  v42 = 0;
  v22 = (CAkMusicPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x248ui64);
  if ( v22 )
  {
    v23 = v37;
    v24 = v36;
    _mm_store_si128((__m128i *)&v51, (__m128i)result);
    CAkMusicPBI::CAkMusicPBI(
      v22,
      v52,
      v12,
      v11,
      v10,
      v16,
      in_pSrcInfo,
      (PlayHistory *)&v42,
      0,
      (PriorityInfoCurrent *)&v51,
      in_uSourceOffset,
      v24,
      v23);
    v26 = v25;
  }
  else
  {
    v26 = 0i64;
  }
  v27 = out_pPBI;
  *out_pPBI = v26;
  if ( !v26 )
  {
LABEL_18:
    v44 = 0i64;
    v45 = 0i64;
    v31 = v12->vfptr;
    v42 = 0;
    v46 = 3;
    v47 = 256;
    v43 = v10;
    ((void (__fastcall *)(CAkSoundBase *, int *))v31[8].Category)(v12, &v42);
    if ( v13 != 3 )
      return v13;
LABEL_21:
    v32 = v10->m_GameObjID;
    v48 = 0;
    v42 = 0;
    _((AMD_HD3D *)v12);
    return v13;
  }
  if ( ((unsigned int (__fastcall *)(CAkMusicPBI *, __int64 *))v26->vfptr[1]._Stop)(v26, &v49) == 1 )
  {
    (*v27)->m_fMaxDistance = out_fMaxRadius;
    (*v27)->m_iFrameOffset = in_uFrameOffset;
    CAkMusicRenderer::Play(*v27, in_transParams);
    return 1i64;
  }
  LOBYTE(v28) = 1;
  ((void (__fastcall *)(CAkMusicPBI *, __int64))(*v27)->vfptr[1].~CAkTransportAware)(*v27, v28);
  v29 = *v27;
  v30 = g_DefaultPoolId;
  if ( *v27 )
  {
    ((void (__fastcall *)(CAkMusicPBI *, _QWORD))v29->vfptr->~CAkTransportAware)(*v27, 0i64);
    AK::MemoryMgr::Free(v30, v29);
  }
  *v27 = 0i64;
  return v13;
}

// File Line: 331
// RVA: 0xAA9A90
void __fastcall CAkMusicRenderer::Play(CAkMusicPBI *in_pContext, TransParams *in_transParams)
{
  TransParams *v2; // rbx
  CAkMusicPBI *v3; // rdi

  v2 = in_transParams;
  v3 = in_pContext;
  CAkURenderer::EnqueueContext((CAkPBI *)&in_pContext->vfptr);
  CAkPBI::_InitPlay((CAkPBI *)&v3->vfptr);
  CAkPBI::_Play((CAkPBI *)&v3->vfptr, v2, 0i64, 1);
}

// File Line: 379
// RVA: 0xAAA3E0
void __fastcall CAkMusicRenderer::Stop(CAkMusicRenderer *this, CAkMusicNode *in_pNode, CAkRegisteredObj *in_pGameObj, TransParams *in_transParams, unsigned int in_playingID)
{
  CAkMatrixAwareCtx *v5; // rbx
  TransParams *v6; // r14
  CAkRegisteredObj *v7; // rbp
  CAkMusicNode *v8; // r15
  CAkMusicCtx *v9; // rdi
  CAkChildCtxVtbl *v10; // rax

  v5 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v6 = in_transParams;
  v7 = in_pGameObj;
  v8 = in_pNode;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      v9 = (CAkMusicCtx *)&v5->vfptr;
      v5 = v5->pNextTopLevelSibling;
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMusicCtx *))v9->vfptr[2].OnPaused)(v9) == v8 )
      {
        v10 = v9[1].vfptr;
        if ( (!v7 || v7 == (CAkRegisteredObj *)v10[1].OnLastFrame)
          && (!in_playingID || in_playingID == LODWORD(v10->~CAkChildCtx)) )
        {
          CAkMusicCtx::_Stop(v9, v6, 0xFFFFFFFF);
        }
      }
    }
    while ( v5 );
  }
}

// File Line: 405
// RVA: 0xAA98E0
void __fastcall CAkMusicRenderer::Pause(CAkMusicRenderer *this, CAkMusicNode *in_pNode, CAkRegisteredObj *in_pGameObj, TransParams *in_transParams, unsigned int in_playingID)
{
  CAkMatrixAwareCtx *v5; // rbx
  TransParams *v6; // rbp
  CAkRegisteredObj *v7; // rsi
  CAkMusicNode *v8; // r14
  CAkMatrixSequencer *v9; // rax

  v5 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v6 = in_transParams;
  v7 = in_pGameObj;
  v8 = in_pNode;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v5->vfptr[2].OnPaused)(v5) == v8 )
      {
        v9 = v5->m_pSequencer;
        if ( (!v7 || v7 == v9->m_pGameObj) && (!in_playingID || in_playingID == v9->m_UserParams.m_PlayingID) )
          CAkMusicCtx::_Pause((CAkMusicCtx *)&v5->vfptr, v6);
      }
      v5 = v5->pNextTopLevelSibling;
    }
    while ( v5 );
  }
}

// File Line: 428
// RVA: 0xAAA010
void __fastcall CAkMusicRenderer::Resume(CAkMusicRenderer *this, CAkMusicNode *in_pNode, CAkRegisteredObj *in_pGameObj, TransParams *in_transParams, bool in_bMasterResume, unsigned int in_playingID)
{
  CAkMatrixAwareCtx *v6; // rbx
  TransParams *v7; // r14
  CAkRegisteredObj *v8; // rsi
  CAkMusicNode *v9; // r15
  CAkMatrixSequencer *v10; // rax

  v6 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v7 = in_transParams;
  v8 = in_pGameObj;
  v9 = in_pNode;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v6->vfptr[2].OnPaused)(v6) == v9 )
      {
        v10 = v6->m_pSequencer;
        if ( (!v8 || v8 == v10->m_pGameObj) && (!in_playingID || in_playingID == v10->m_UserParams.m_PlayingID) )
          CAkMusicCtx::_Resume((CAkMusicCtx *)&v6->vfptr, v7, in_bMasterResume);
      }
      v6 = v6->pNextTopLevelSibling;
    }
    while ( v6 );
  }
}

// File Line: 450
// RVA: 0xAAA140
void __fastcall CAkMusicRenderer::SeekTimeAbsolute(CAkMusicRenderer *this, CAkMusicNode *in_pNode, CAkRegisteredObj *in_pGameObj, int in_iSeekTime, bool in_bSnapToCue)
{
  CAkMatrixAwareCtx *v5; // rbx
  CAkRegisteredObj *v6; // rsi
  CAkMusicNode *v7; // rbp
  bool v8; // r14
  CAkMatrixAwareCtx *v9; // rdi
  int v10; // [rsp+58h] [rbp+20h]

  v10 = in_iSeekTime;
  v5 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v6 = in_pGameObj;
  v7 = in_pNode;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    v8 = in_bSnapToCue;
    do
    {
      v9 = v5;
      v5 = v5->pNextTopLevelSibling;
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v9->vfptr[2].OnPaused)(v9) == v7
        && (!v6 || v9->m_pSequencer->m_pGameObj == v6)
        && ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, int *, bool))v9->vfptr[2].VirtualRelease)(v9, &v10, v8) == 1 )
      {
        CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, v9->m_pSequencer->m_UserParams.m_PlayingID);
      }
    }
    while ( v5 );
  }
}

// File Line: 483
// RVA: 0xAAA0A0
void __fastcall CAkMusicRenderer::SeekPercent(CAkMusicRenderer *this, CAkMusicNode *in_pNode, CAkRegisteredObj *in_pGameObj, float in_fSeekPercent, bool in_bSnapToCue)
{
  CAkMatrixAwareCtx *v5; // rbx
  CAkRegisteredObj *v6; // rsi
  CAkMusicNode *v7; // rbp
  bool v8; // r14
  CAkMatrixAwareCtx *v9; // rdi
  float v10; // [rsp+58h] [rbp+20h]

  v10 = in_fSeekPercent;
  v5 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v6 = in_pGameObj;
  v7 = in_pNode;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    v8 = in_bSnapToCue;
    do
    {
      v9 = v5;
      v5 = v5->pNextTopLevelSibling;
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v9->vfptr[2].OnPaused)(v9) == v7
        && (!v6 || v9->m_pSequencer->m_pGameObj == v6)
        && ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, float *, bool))v9->vfptr[2].~CAkChildCtx)(v9, &v10, v8) == 1 )
      {
        CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, v9->m_pSequencer->m_UserParams.m_PlayingID);
      }
    }
    while ( v5 );
  }
}

// File Line: 517
// RVA: 0xAA9340
signed __int64 __fastcall CAkMusicRenderer::AddChild(CAkMusicRenderer *this, CAkMatrixAwareCtx *in_pMusicCtx, UserParams *in_rUserparams, CAkRegisteredObj *in_pGameObj)
{
  CAkMatrixAwareCtx *v4; // rbx
  CAkRegisteredObj *v5; // rdi
  UserParams *v6; // rbp
  CAkMatrixSequencer *v7; // rax
  CAkMatrixSequencer *v8; // rax
  CAkMatrixSequencer *v9; // rsi
  __int64 v10; // rax
  __int64 v11; // rdi
  unsigned int v12; // edx
  unsigned int v13; // edi
  int v15; // ebx
  unsigned int out_puRegisteredNotif; // [rsp+20h] [rbp-18h]

  v4 = in_pMusicCtx;
  v5 = in_pGameObj;
  v6 = in_rUserparams;
  v7 = (CAkMatrixSequencer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v7 )
    return 2i64;
  CAkMatrixSequencer::CAkMatrixSequencer(v7, v4, v6, v5);
  v9 = v8;
  if ( !v8 )
    return 2i64;
  v10 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v4->vfptr[2].OnPaused)(v4);
  v11 = v10;
  if ( !v10 )
    goto LABEL_15;
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v10 + 304i64))(v10, 3i64) )
  {
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v11 + 312i64))(v11, 3i64);
LABEL_15:
    v15 = g_DefaultPoolId;
    CAkMatrixSequencer::~CAkMatrixSequencer(v9);
    AK::MemoryMgr::Free(v15, v9);
    return 2i64;
  }
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    v4->pNextTopLevelSibling = CAkMusicRenderer::m_listCtx.m_pFirst;
    CAkMusicRenderer::m_listCtx.m_pFirst = v4;
  }
  else
  {
    CAkMusicRenderer::m_listCtx.m_pLast = v4;
    CAkMusicRenderer::m_listCtx.m_pFirst = v4;
    v4->pNextTopLevelSibling = 0i64;
  }
  CAkMatrixAwareCtx::SetSequencer(v4, v9);
  v12 = v6->m_PlayingID;
  if ( !v12 )
    return 2i64;
  out_puRegisteredNotif = 0;
  v13 = CAkPlayingMgr::SetPBI(g_pPlayingMgr, v12, (CAkTransportAware *)&v4->vfptr, &out_puRegisteredNotif);
  CAkMatrixAwareCtx::SetRegisteredNotif(v4, out_puRegisteredNotif);
  if ( out_puRegisteredNotif & 0x20000 )
  {
    if ( CAkSegmentInfoRepository::CreateEntry(&CAkMusicRenderer::m_segmentInfoRepository, v6->m_PlayingID) != 1 )
      CAkMatrixAwareCtx::SetRegisteredNotif(v4, out_puRegisteredNotif & 0xFFFDFFFF);
  }
  CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, v6->m_PlayingID);
  return v13;
}

// File Line: 571
// RVA: 0xAA9D70
void __fastcall CAkMusicRenderer::RemoveChild(CAkMusicRenderer *this, CAkMatrixAwareCtx *in_pMusicCtx)
{
  CAkMatrixAwareCtx *v2; // rbx
  CAkMatrixAwareCtx *v3; // rdx
  CAkMatrixAwareCtx *v4; // rax
  CAkMatrixAwareCtx *v5; // rcx
  CAkMatrixSequencer *v6; // rdi
  unsigned int v7; // edx
  __int64 v8; // rax
  int v9; // ebx

  v2 = in_pMusicCtx;
  v3 = 0i64;
  v4 = CAkMusicRenderer::m_listCtx.m_pFirst;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    while ( v4 != v2 )
    {
      v3 = v4;
      v4 = v4->pNextTopLevelSibling;
      if ( !v4 )
        goto LABEL_12;
    }
    if ( v4 )
    {
      if ( v4 == CAkMusicRenderer::m_listCtx.m_pFirst )
        CAkMusicRenderer::m_listCtx.m_pFirst = v4->pNextTopLevelSibling;
      else
        v3->pNextTopLevelSibling = v4->pNextTopLevelSibling;
      v5 = CAkMusicRenderer::m_listCtx.m_pLast;
      if ( v4 == CAkMusicRenderer::m_listCtx.m_pLast )
        v5 = v3;
      CAkMusicRenderer::m_listCtx.m_pLast = v5;
    }
  }
LABEL_12:
  v6 = v2->m_pSequencer;
  if ( v6 )
  {
    v7 = v6->m_UserParams.m_PlayingID;
    if ( v7 )
    {
      if ( v2->m_uRegisteredNotif & 0x20000 )
        CAkPositionRepository::RemovePlayingID(&CAkMusicRenderer::m_segmentInfoRepository, v7);
      CAkPlayingMgr::Remove(g_pPlayingMgr, v6->m_UserParams.m_PlayingID, (CAkTransportAware *)&v2->vfptr);
      if ( ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v2->vfptr[2].OnPaused)(v2) )
      {
        v8 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v2->vfptr[2].OnPaused)(v2);
        (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v8 + 312i64))(v8, 3i64);
      }
    }
    v9 = g_DefaultPoolId;
    CAkMatrixSequencer::~CAkMatrixSequencer(v6);
    AK::MemoryMgr::Free(v9, v6);
  }
  SetEvent(CAkMusicRenderer::m_hTermEvent);
}

// File Line: 600
// RVA: 0xAA9A10
void __fastcall CAkMusicRenderer::PerformNextFrameBehavior(bool __formal)
{
  CAkMatrixAwareCtx *v1; // rbx
  CAkMatrixAwareCtx *v2; // rcx
  CAkMatrixSequencer *v3; // rdi
  AkSegmentInfo in_segmentInfo; // [rsp+20h] [rbp-28h]

  v1 = CAkMusicRenderer::m_listCtx.m_pFirst;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      v2 = v1;
      v1 = v1->pNextTopLevelSibling;
      v3 = v2->m_pSequencer;
      if ( v2->m_uRegisteredNotif & 0x20000 )
      {
        if ( ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, AkSegmentInfo *))v2->vfptr[3].OnLastFrame)(
               v2,
               &in_segmentInfo) == 1 )
          CAkSegmentInfoRepository::UpdateSegmentInfo(
            &CAkMusicRenderer::m_segmentInfoRepository,
            v3->m_UserParams.m_PlayingID,
            &in_segmentInfo);
      }
      CAkMatrixSequencer::Execute(v3, 0x400u);
    }
    while ( v1 );
  }
}

// File Line: 657
// RVA: 0xAAA1E0
bool __fastcall CAkMusicRenderer::SetState(unsigned int in_stateGroupID, unsigned int in_stateID)
{
  CAkMatrixAwareCtx *v2; // rbx
  unsigned int v3; // er14
  __int64 v4; // r15
  unsigned int v5; // er12
  unsigned int v6; // esi
  __int64 v7; // rdi
  CAkMatrixAwareCtx *v8; // rbp
  char v9; // al
  __int64 v10; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *i; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkMusicRenderer::AkStateChangeRecord *v13; // rbx
  AKRESULT v14; // eax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v15; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v16; // rax
  unsigned int out_uSegmentLookAhead; // [rsp+70h] [rbp+18h]
  __int64 out_iSyncTime; // [rsp+78h] [rbp+20h]

  v2 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v3 = out_uSegmentLookAhead;
  v4 = *(_QWORD *)&out_uSegmentLookAhead;
  v5 = in_stateID;
  v6 = in_stateGroupID;
  v7 = 0i64;
  v8 = 0i64;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      v9 = *((_BYTE *)&v2->0 + 98);
      if ( v9 & 1 )
      {
        if ( !(v9 & 0x10) )
        {
          v10 = CAkMatrixSequencer::QueryStateChangeDelay(v2->m_pSequencer, v6, &out_uSegmentLookAhead, &out_iSyncTime);
          if ( !v8 || v10 < v7 )
          {
            v4 = out_iSyncTime;
            v3 = out_uSegmentLookAhead;
            v7 = v10;
            v8 = v2;
          }
        }
      }
      v2 = v2->pNextTopLevelSibling;
    }
    while ( v2 );
  }
  if ( v7 - 1024 <= 0 )
    goto LABEL_32;
  i = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
  if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFree )
  {
    if ( CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems >= CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems
      || (i = (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64)) == 0i64 )
    {
LABEL_16:
      for ( i = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst; i; i = i->pNextListItem )
      {
        if ( i->Item.stateGroupID == v6 )
          *((_DWORD *)&i->Item + 2) |= 1u;
      }
LABEL_32:
      LOBYTE(v14) = 0;
      return v14;
    }
    i->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = i;
  }
  v12 = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
  v13 = &i->Item;
  if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
    v12 = i;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = v12;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = i->pNextListItem;
  i->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  ++CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = i;
  if ( i == (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
    goto LABEL_16;
  v14 = CAkMatrixSequencer::ProcessDelayedStateChange(v8->m_pSequencer, &i->Item, v3, v4);
  if ( v14 != 1 )
  {
    v15 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
    if ( CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
    {
      CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst->pNextListItem;
      v16 = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
      if ( v15 == CAkMusicRenderer::m_queuePendingStateChanges.m_pLast )
        v16 = 0i64;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = v16;
      if ( v15 < CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart
        || v15 >= &CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart[(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v15);
      }
      else
      {
        v15->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
        CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = v15;
      }
      --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
    }
    goto LABEL_32;
  }
  *((_DWORD *)v13 + 2) &= 0xFFFFFFFE;
  *((_DWORD *)v13 + 2) |= 2u;
  v13->stateGroupID = v6;
  v13->stateID = v5;
  return v14;
}

// File Line: 722
// RVA: 0xAA9970
void __fastcall CAkMusicRenderer::PerformDelayedStateChange(CAkMusicRenderer *this, void *in_pCookie)
{
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  __int64 *v3; // rbx
  int v4; // eax
  int v5; // edi
  __int64 *v6; // rax
  __int128 v7; // [rsp+20h] [rbp-18h]

  v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  v7 = (unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  _mm_store_si128((__m128i *)&v7, (__m128i)(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst);
  v3 = (__int64 *)v7;
  if ( v2 )
  {
    do
    {
      if ( v3 + 1 == in_pCookie )
        break;
      v3 = (__int64 *)*v3;
    }
    while ( v3 );
  }
  *((_DWORD *)v3 + 4) &= 0xFFFFFFFD;
  v4 = *((_DWORD *)v3 + 4);
  if ( !(v4 & 1) )
  {
    *((_DWORD *)v3 + 4) = v4 | 1;
    v5 = *((_DWORD *)v3 + 2);
    AK::SoundEngine::SetState(*((_DWORD *)v3 + 2), *((_DWORD *)v3 + 3), 0, 1);
    v6 = (__int64 *)*v3;
    if ( *v3 )
    {
      do
      {
        if ( *((_DWORD *)v6 + 2) == v5 )
          *((_DWORD *)v6 + 4) |= 1u;
        v6 = (__int64 *)*v6;
      }
      while ( v6 );
    }
  }
  CAkMusicRenderer::CleanPendingStateChanges();
}

// File Line: 756
// RVA: 0xAA9E70
void __fastcall CAkMusicRenderer::RescheduleDelayedStateChange(CAkMusicRenderer *this, void *in_pCookie)
{
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v2; // rax
  __int64 v3; // rbp
  void *v4; // r15
  __int64 *v5; // rdi
  int v6; // eax
  CAkMatrixAwareCtx *v7; // rbx
  unsigned int v8; // esi
  unsigned int v9; // er12
  __int64 v10; // r13
  CAkMatrixAwareCtx *v11; // r14
  char v12; // al
  __int64 v13; // rax
  __int128 v14; // [rsp+20h] [rbp-48h]
  unsigned int out_uSegmentLookAhead; // [rsp+80h] [rbp+18h]
  __int64 out_iSyncTime; // [rsp+88h] [rbp+20h]

  v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  v3 = 0i64;
  v4 = in_pCookie;
  v14 = (unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  _mm_store_si128((__m128i *)&v14, (__m128i)(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst);
  v5 = (__int64 *)v14;
  if ( v2 )
  {
    do
    {
      if ( v5 + 1 == in_pCookie )
        break;
      v5 = (__int64 *)*v5;
    }
    while ( v5 );
  }
  v6 = *((_DWORD *)v5 + 4);
  if ( v6 & 1 )
  {
    *((_DWORD *)v5 + 4) = v6 & 0xFFFFFFFD;
    CAkMusicRenderer::CleanPendingStateChanges();
    return;
  }
  v7 = CAkMusicRenderer::m_listCtx.m_pFirst;
  v8 = *((_DWORD *)v5 + 2);
  v9 = out_uSegmentLookAhead;
  v10 = *(_QWORD *)&out_uSegmentLookAhead;
  v11 = 0i64;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    do
    {
      v12 = *((_BYTE *)&v7->0 + 98);
      if ( v12 & 1 )
      {
        if ( !(v12 & 0x10) )
        {
          v13 = CAkMatrixSequencer::QueryStateChangeDelay(v7->m_pSequencer, v8, &out_uSegmentLookAhead, &out_iSyncTime);
          if ( !v11 || v13 < v3 )
          {
            v10 = out_iSyncTime;
            v9 = out_uSegmentLookAhead;
            v3 = v13;
            v11 = v7;
          }
        }
      }
      v7 = v7->pNextTopLevelSibling;
    }
    while ( v7 );
  }
  if ( v3 - 1024 <= 0 )
  {
    AK::SoundEngine::SetState(v8, *((_DWORD *)v5 + 3), 0, 1);
    *((_DWORD *)v5 + 4) = v5[2] & 0xFFFFFFFD | 1;
    do
    {
      if ( *((_DWORD *)v5 + 2) == v8 )
        *((_DWORD *)v5 + 4) |= 1u;
      v5 = (__int64 *)*v5;
    }
    while ( v5 );
LABEL_17:
    CAkMusicRenderer::CleanPendingStateChanges();
    return;
  }
  if ( CAkMatrixSequencer::ProcessDelayedStateChange(v11->m_pSequencer, v4, v9, v10) != 1 )
  {
    AK::SoundEngine::SetState(v8, *((_DWORD *)v5 + 3), 0, 1);
    *((_DWORD *)v5 + 4) = v5[2] & 0xFFFFFFFD | 1;
    do
    {
      if ( *((_DWORD *)v5 + 2) == v8 )
        *((_DWORD *)v5 + 4) |= 1u;
      v5 = (__int64 *)*v5;
    }
    while ( v5 );
    goto LABEL_17;
  }
}

// File Line: 895
// RVA: 0xAA94D0
void CAkMusicRenderer::CleanPendingStateChanges(void)
{
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v0; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v1; // rcx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v2; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v3; // rax
  __m128i v4; // [rsp+20h] [rbp-28h]
  __m128i v5; // [rsp+30h] [rbp-18h]

  v0 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  v1 = 0i64;
  v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  if ( CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
  {
    do
    {
      if ( *((_BYTE *)&v2->Item + 8) & 2 )
      {
        v1 = v2;
        v2 = v2->pNextListItem;
      }
      else
      {
        v4.m128i_i64[1] = (__int64)v1;
        v4.m128i_i64[0] = (__int64)v2->pNextListItem;
        if ( v2 == v0 )
          CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = v2->pNextListItem;
        else
          v1->pNextListItem = v2->pNextListItem;
        v3 = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
        if ( v2 == CAkMusicRenderer::m_queuePendingStateChanges.m_pLast )
          v3 = v1;
        CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = v3;
        if ( v2 < CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart
          || v2 >= &CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart[(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v2);
        }
        else
        {
          v2->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
          CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = v2;
        }
        --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
        v0 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
        _mm_store_si128(&v5, v4);
        v1 = (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)v5.m128i_i64[1];
        v2 = (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)v5.m128i_i64[0];
      }
    }
    while ( v2 );
  }
}

