// File Line: 53
// RVA: 0xAA9890
__int64 __fastcall AK::MusicEngine::Init(AkMusicSettings *in_pSettings)
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
  if ( CAkMusicRenderer::m_pMusicRenderer )
    CAkMusicRenderer::Destroy(CAkMusicRenderer::m_pMusicRenderer);
}

// File Line: 92
// RVA: 0xAA97E0
AKRESULT __fastcall AK::MusicEngine::GetPlayingSegmentInfo(
        unsigned int in_PlayingID,
        AkSegmentInfo *out_segmentInfo,
        bool in_bExtrapolate)
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkMusicRenderer::m_listCtx__);
}

// File Line: 111
// RVA: 0x15BE120
__int64 dynamic_initializer_for__CAkMusicRenderer::m_segmentInfoRepository__()
{
  CAkBusCallbackMgr::CAkBusCallbackMgr(&CAkMusicRenderer::m_segmentInfoRepository);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkMusicRenderer::m_segmentInfoRepository__);
}

// File Line: 112
// RVA: 0x15BE110
__int64 dynamic_initializer_for__CAkMusicRenderer::m_queuePendingStateChanges__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkMusicRenderer::m_queuePendingStateChanges__);
}

// File Line: 123
// RVA: 0xAA95B0
CAkMusicRenderer *__fastcall CAkMusicRenderer::Create(AkMusicSettings *in_pSettings)
{
  CAkMusicRenderer *result; // rax
  CAkMusicRenderer *v3; // rax

  result = CAkMusicRenderer::m_pMusicRenderer;
  if ( !CAkMusicRenderer::m_pMusicRenderer )
  {
    v3 = (CAkMusicRenderer *)AK::MemoryMgr::Malloc(
                               g_DefaultPoolId,
                               (unsigned int)((_DWORD)CAkMusicRenderer::m_pMusicRenderer + 1));
    if ( v3 )
    {
      CAkMusicRenderer::m_pMusicRenderer = v3;
      if ( CAkMusicRenderer::Init(v3, in_pSettings) == AK_Success )
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
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // rbx

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
  if ( CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems )
  {
    m_pFree = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
    while ( 1 )
    {
      m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
      if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
        break;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst->pNextListItem;
      m_pLast = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
      if ( m_pFirst == CAkMusicRenderer::m_queuePendingStateChanges.m_pLast )
        m_pLast = 0i64;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = m_pLast;
      if ( m_pFirst < CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart
        || m_pFirst >= &CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart[(unsigned __int64)CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
        m_pFree = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
        --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
      }
      else
      {
        m_pFirst->pNextListItem = m_pFree;
        --CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
        m_pFree = m_pFirst;
        CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = m_pFirst;
      }
    }
    m_pvMemStart = CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart;
    if ( m_pFree )
    {
      do
      {
        pNextListItem = m_pFree->pNextListItem;
        if ( m_pFree < m_pvMemStart
          || m_pFree >= &m_pvMemStart[CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pFree);
          m_pvMemStart = CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart;
        }
        m_pFree = pNextListItem;
      }
      while ( pNextListItem );
    }
    if ( m_pvMemStart )
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pvMemStart);
    *(_QWORD *)&CAkMusicRenderer::m_queuePendingStateChanges.m_ulMinNumListItems = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = 0i64;
  }
  if ( this )
  {
    CAkMusicRenderer::m_pMusicRenderer = 0i64;
    AK::MemoryMgr::Free(g_DefaultPoolId, this);
  }
}

// File Line: 170
// RVA: 0xAA9800
__int64 __fastcall CAkMusicRenderer::Init(CAkMusicRenderer *this, AkMusicSettings *in_pSettings)
{
  __int64 result; // rax

  if ( in_pSettings )
    CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio = in_pSettings->fStreamingLookAheadRatio;
  else
    LODWORD(CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio) = (AkMusicSettings)FLOAT_1_0;
  _((AMD_HD3D *)&CAkMusicRenderer::m_segmentInfoRepository);
  CAkMusicRenderer::m_hTermEvent = CreateEventW(0i64, 0, 0, 0i64);
  result = 2 - (unsigned int)(CAkMusicRenderer::m_hTermEvent != 0i64);
  if ( (_DWORD)result == 1 )
  {
    CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems = -1;
    CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems = 0;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pvMemStart = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = 0i64;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = 0i64;
    return 1i64;
  }
  return result;
}

// File Line: 221
// RVA: 0xAA9AD0
__int64 __fastcall CAkMusicRenderer::Play(
        CAkMusicCtx *io_pParentCtx,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_transParams,
        UserParams *in_rUserparams,
        AkTrackSrc *in_pSrcInfo,
        unsigned int in_uSourceOffset,
        int in_uFrameOffset,
        CAkMusicPBI **out_pPBI)
{
  unsigned int v13; // esi
  AKRESULT v15; // eax
  UserParams *v16; // r12
  AKRESULT v17; // ebx
  CAkIndexableVtbl *vfptr; // rax
  int v19; // eax
  bool VirtualBehaviorAction; // cl
  AkBelowThresholdBehavior VirtualBehavior; // eax
  CAkMusicPBI *v22; // rcx
  CAkMusicPBI *v23; // rax
  CAkMusicPBI *v24; // rcx
  CAkMusicPBI **v25; // rbx
  __int64 v26; // rdx
  CAkMusicPBI *v27; // rdi
  int v28; // r14d
  CAkIndexableVtbl *v29; // rax
  float out_fMaxRadius; // [rsp+70h] [rbp-90h] BYREF
  float priority; // [rsp+78h] [rbp-88h] BYREF
  CAkRegisteredObj *v32; // [rsp+80h] [rbp-80h]
  CAkLimiter *v33; // [rsp+88h] [rbp-78h]
  CAkLimiter *v34; // [rsp+90h] [rbp-70h]
  int v35; // [rsp+98h] [rbp-68h]
  __int16 v36; // [rsp+9Ch] [rbp-64h]
  PriorityInfoCurrent result; // [rsp+A0h] [rbp-60h] BYREF
  AkVirtualQueueBehavior out_Behavior[4]; // [rsp+B0h] [rbp-50h] BYREF
  PlayHistory v39; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v40; // [rsp+110h] [rbp+10h] BYREF
  int v41; // [rsp+118h] [rbp+18h]
  PriorityInfoCurrent v42; // [rsp+120h] [rbp+20h] BYREF
  AkMonitorData::NotificationReason out_eReasonOfFailure; // [rsp+178h] [rbp+78h] BYREF

  v13 = 2;
  if ( !in_pSound )
    return 31i64;
  CAkURenderer::_CalcInitialPriority(&result, in_pSound, in_pGameObj, &out_fMaxRadius);
  v15 = CAkURenderer::ValidateLimits(result.currentPriority.priority, &out_eReasonOfFailure);
  v16 = in_rUserparams;
  v17 = v15;
  if ( v15 == AK_Fail )
  {
    v13 = 3;
    goto LABEL_21;
  }
  v33 = 0i64;
  v34 = 0i64;
  vfptr = in_pSound->vfptr;
  priority = result.currentPriority.priority;
  v35 = 3;
  v36 = 256;
  v32 = in_pGameObj;
  v19 = ((__int64 (__fastcall *)(CAkSoundBase *, float *))vfptr[8].Release)(in_pSound, &priority);
  VirtualBehaviorAction = v19 != 2;
  if ( v19 == 80 || v17 == AK_MustBeVirtualized )
  {
    VirtualBehavior = (unsigned int)CAkParameterNode::GetVirtualBehavior(in_pSound, out_Behavior);
    VirtualBehaviorAction = CAkURenderer::GetVirtualBehaviorAction(VirtualBehavior);
  }
  if ( !VirtualBehaviorAction )
  {
    v13 = 3;
    out_eReasonOfFailure = NotificationReason_PlayFailedLimit;
    goto LABEL_18;
  }
  v40 = 0i64;
  v41 = 0;
  v39.arrayIsContinuous.m_iBitArray = 0;
  v39.HistArray.uiArraySize = 0;
  v22 = (CAkMusicPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x248ui64);
  if ( v22 )
  {
    v42 = result;
    CAkMusicPBI::CAkMusicPBI(
      v22,
      io_pParentCtx,
      in_pSound,
      in_pSource,
      in_pGameObj,
      v16,
      in_pSrcInfo,
      &v39,
      0,
      &v42,
      in_uSourceOffset,
      v33,
      v34);
    v24 = v23;
  }
  else
  {
    v24 = 0i64;
  }
  v25 = out_pPBI;
  *out_pPBI = v24;
  if ( !v24 )
  {
LABEL_18:
    *(_QWORD *)&v39.HistArray.aCntrHist[6] = 0i64;
    *(_QWORD *)&v39.HistArray.aCntrHist[10] = 0i64;
    v29 = in_pSound->vfptr;
    v39.HistArray.uiArraySize = 0;
    *(_DWORD *)&v39.HistArray.aCntrHist[14] = 3;
    v39.HistArray.aCntrHist[16] = 256;
    *(_QWORD *)&v39.HistArray.aCntrHist[2] = in_pGameObj;
    ((void (__fastcall *)(CAkSoundBase *, PlayHistory *))v29[8].Category)(in_pSound, &v39);
    if ( v13 != 3 )
      return v13;
LABEL_21:
    v39.arrayIsContinuous.m_iBitArray = 0;
    v39.HistArray.uiArraySize = 0;
    _((AMD_HD3D *)in_pSound);
    return v13;
  }
  if ( ((unsigned int (__fastcall *)(CAkMusicPBI *, __int64 *))v24->CAkPBI::CAkTransportAware::vfptr[1]._Stop)(
         v24,
         &v40) == 1 )
  {
    (*v25)->m_fMaxDistance = out_fMaxRadius;
    (*v25)->m_iFrameOffset = in_uFrameOffset;
    CAkMusicRenderer::Play(*v25, in_transParams);
    return 1i64;
  }
  LOBYTE(v26) = 1;
  ((void (__fastcall *)(CAkMusicPBI *, __int64))(*v25)->CAkPBI::CAkTransportAware::vfptr[1].~CAkTransportAware)(
    *v25,
    v26);
  v27 = *v25;
  v28 = g_DefaultPoolId;
  if ( *v25 )
  {
    ((void (__fastcall *)(CAkMusicPBI *, _QWORD))v27->CAkPBI::CAkTransportAware::vfptr->~CAkTransportAware)(*v25, 0i64);
    AK::MemoryMgr::Free(v28, v27);
  }
  *v25 = 0i64;
  return v13;
}

// File Line: 331
// RVA: 0xAA9A90
void __fastcall CAkMusicRenderer::Play(CAkMusicPBI *in_pContext, TransParams *in_transParams)
{
  CAkURenderer::EnqueueContext(in_pContext);
  CAkPBI::_InitPlay(in_pContext);
  CAkPBI::_Play(in_pContext, in_transParams, 0i64, 1);
}

// File Line: 379
// RVA: 0xAAA3E0
void __fastcall CAkMusicRenderer::Stop(
        CAkMusicRenderer *this,
        CAkMusicNode *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_transParams,
        unsigned int in_playingID)
{
  CAkMatrixAwareCtx *m_pFirst; // rbx
  CAkMusicCtx *v9; // rdi
  CAkChildCtxVtbl *vfptr; // rax

  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  while ( m_pFirst )
  {
    v9 = m_pFirst;
    m_pFirst = m_pFirst->pNextTopLevelSibling;
    if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMusicCtx *))v9->CAkChildCtx::vfptr[2].OnPaused)(v9) == in_pNode )
    {
      vfptr = v9[1].CAkChildCtx::vfptr;
      if ( (!in_pGameObj || in_pGameObj == (CAkRegisteredObj *)vfptr[1].OnLastFrame)
        && (!in_playingID || in_playingID == LODWORD(vfptr->~CAkChildCtx)) )
      {
        CAkMusicCtx::_Stop(v9, in_transParams, 0xFFFFFFFF);
      }
    }
  }
}

// File Line: 405
// RVA: 0xAA98E0
void __fastcall CAkMusicRenderer::Pause(
        CAkMusicRenderer *this,
        CAkMusicNode *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_transParams,
        unsigned int in_playingID)
{
  CAkMatrixAwareCtx *i; // rbx
  CAkMatrixSequencer *m_pSequencer; // rax

  for ( i = CAkMusicRenderer::m_listCtx.m_pFirst; i; i = i->pNextTopLevelSibling )
  {
    if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))i->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(i) == in_pNode )
    {
      m_pSequencer = i->m_pSequencer;
      if ( (!in_pGameObj || in_pGameObj == m_pSequencer->m_pGameObj)
        && (!in_playingID || in_playingID == m_pSequencer->m_UserParams.m_PlayingID) )
      {
        CAkMusicCtx::_Pause(i, in_transParams);
      }
    }
  }
}

// File Line: 428
// RVA: 0xAAA010
void __fastcall CAkMusicRenderer::Resume(
        CAkMusicRenderer *this,
        CAkMusicNode *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_transParams,
        bool in_bMasterResume,
        unsigned int in_playingID)
{
  CAkMatrixAwareCtx *i; // rbx
  CAkMatrixSequencer *m_pSequencer; // rax

  for ( i = CAkMusicRenderer::m_listCtx.m_pFirst; i; i = i->pNextTopLevelSibling )
  {
    if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))i->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(i) == in_pNode )
    {
      m_pSequencer = i->m_pSequencer;
      if ( (!in_pGameObj || in_pGameObj == m_pSequencer->m_pGameObj)
        && (!in_playingID || in_playingID == m_pSequencer->m_UserParams.m_PlayingID) )
      {
        CAkMusicCtx::_Resume(i, in_transParams, in_bMasterResume);
      }
    }
  }
}

// File Line: 450
// RVA: 0xAAA140
void __fastcall CAkMusicRenderer::SeekTimeAbsolute(
        CAkMusicRenderer *this,
        CAkMusicNode *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        int in_iSeekTime,
        bool in_bSnapToCue)
{
  CAkMatrixAwareCtx *m_pFirst; // rbx
  bool v8; // r14
  CAkMatrixAwareCtx *v9; // rdi
  int v10; // [rsp+58h] [rbp+20h] BYREF

  v10 = in_iSeekTime;
  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    v8 = in_bSnapToCue;
    do
    {
      v9 = m_pFirst;
      m_pFirst = m_pFirst->pNextTopLevelSibling;
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v9->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(v9) == in_pNode
        && (!in_pGameObj || v9->m_pSequencer->m_pGameObj == in_pGameObj)
        && ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, int *, bool))v9->CAkMusicCtx::CAkChildCtx::vfptr[2].VirtualRelease)(
             v9,
             &v10,
             v8) == 1 )
      {
        CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, v9->m_pSequencer->m_UserParams.m_PlayingID);
      }
    }
    while ( m_pFirst );
  }
}

// File Line: 483
// RVA: 0xAAA0A0
void __fastcall CAkMusicRenderer::SeekPercent(
        CAkMusicRenderer *this,
        CAkMusicNode *in_pNode,
        CAkRegisteredObj *in_pGameObj,
        float in_fSeekPercent,
        bool in_bSnapToCue)
{
  CAkMatrixAwareCtx *m_pFirst; // rbx
  bool v8; // r14
  CAkMatrixAwareCtx *v9; // rdi
  float v10; // [rsp+58h] [rbp+20h] BYREF

  v10 = in_fSeekPercent;
  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    v8 = in_bSnapToCue;
    do
    {
      v9 = m_pFirst;
      m_pFirst = m_pFirst->pNextTopLevelSibling;
      if ( (CAkMusicNode *)((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v9->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(v9) == in_pNode
        && (!in_pGameObj || v9->m_pSequencer->m_pGameObj == in_pGameObj)
        && ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, float *, bool))v9->CAkMusicCtx::CAkChildCtx::vfptr[2].~CAkChildCtx)(
             v9,
             &v10,
             v8) == 1 )
      {
        CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, v9->m_pSequencer->m_UserParams.m_PlayingID);
      }
    }
    while ( m_pFirst );
  }
}

// File Line: 517
// RVA: 0xAA9340
__int64 __fastcall CAkMusicRenderer::AddChild(
        CAkMusicRenderer *this,
        CAkMatrixAwareCtx *in_pMusicCtx,
        UserParams *in_rUserparams,
        CAkRegisteredObj *in_pGameObj)
{
  CAkMatrixSequencer *v7; // rax
  CAkMatrixSequencer *v8; // rax
  CAkMatrixSequencer *v9; // rsi
  __int64 v10; // rax
  __int64 v11; // rdi
  unsigned int m_PlayingID; // edx
  unsigned int v13; // edi
  int v15; // ebx
  unsigned int out_puRegisteredNotif[6]; // [rsp+20h] [rbp-18h] BYREF

  v7 = (CAkMatrixSequencer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v7 )
    return 2i64;
  CAkMatrixSequencer::CAkMatrixSequencer(v7, in_pMusicCtx, in_rUserparams, in_pGameObj);
  v9 = v8;
  if ( !v8 )
    return 2i64;
  v10 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))in_pMusicCtx->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(in_pMusicCtx);
  v11 = v10;
  if ( !v10 )
  {
LABEL_15:
    v15 = g_DefaultPoolId;
    CAkMatrixSequencer::~CAkMatrixSequencer(v9);
    AK::MemoryMgr::Free(v15, v9);
    return 2i64;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 304i64))(v10, 3i64) )
  {
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 312i64))(v11, 3i64);
    goto LABEL_15;
  }
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    in_pMusicCtx->pNextTopLevelSibling = CAkMusicRenderer::m_listCtx.m_pFirst;
    CAkMusicRenderer::m_listCtx.m_pFirst = in_pMusicCtx;
  }
  else
  {
    CAkMusicRenderer::m_listCtx.m_pLast = in_pMusicCtx;
    CAkMusicRenderer::m_listCtx.m_pFirst = in_pMusicCtx;
    in_pMusicCtx->pNextTopLevelSibling = 0i64;
  }
  CAkMatrixAwareCtx::SetSequencer(in_pMusicCtx, v9);
  m_PlayingID = in_rUserparams->m_PlayingID;
  if ( !m_PlayingID )
    return 2i64;
  out_puRegisteredNotif[0] = 0;
  v13 = CAkPlayingMgr::SetPBI(g_pPlayingMgr, m_PlayingID, &in_pMusicCtx->CAkTransportAware, out_puRegisteredNotif);
  CAkMatrixAwareCtx::SetRegisteredNotif(in_pMusicCtx, out_puRegisteredNotif[0]);
  if ( (out_puRegisteredNotif[0] & 0x20000) != 0
    && CAkSegmentInfoRepository::CreateEntry(&CAkMusicRenderer::m_segmentInfoRepository, in_rUserparams->m_PlayingID) != AK_Success )
  {
    CAkMatrixAwareCtx::SetRegisteredNotif(in_pMusicCtx, out_puRegisteredNotif[0] & 0xFFFDFFFF);
  }
  CAkPlayingMgr::NotifyMusicPlayStarted(g_pPlayingMgr, in_rUserparams->m_PlayingID);
  return v13;
}

// File Line: 571
// RVA: 0xAA9D70
void __fastcall CAkMusicRenderer::RemoveChild(CAkMusicRenderer *this, CAkMatrixAwareCtx *in_pMusicCtx)
{
  CAkMatrixAwareCtx *v3; // rdx
  CAkMatrixAwareCtx *m_pFirst; // rax
  CAkMatrixAwareCtx *m_pLast; // rcx
  CAkMatrixSequencer *m_pSequencer; // rdi
  unsigned int m_PlayingID; // edx
  __int64 v8; // rax
  int v9; // ebx

  v3 = 0i64;
  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  if ( CAkMusicRenderer::m_listCtx.m_pFirst )
  {
    while ( m_pFirst != in_pMusicCtx )
    {
      v3 = m_pFirst;
      m_pFirst = m_pFirst->pNextTopLevelSibling;
      if ( !m_pFirst )
        goto LABEL_12;
    }
    if ( m_pFirst )
    {
      if ( m_pFirst == CAkMusicRenderer::m_listCtx.m_pFirst )
        CAkMusicRenderer::m_listCtx.m_pFirst = m_pFirst->pNextTopLevelSibling;
      else
        v3->pNextTopLevelSibling = m_pFirst->pNextTopLevelSibling;
      m_pLast = CAkMusicRenderer::m_listCtx.m_pLast;
      if ( m_pFirst == CAkMusicRenderer::m_listCtx.m_pLast )
        m_pLast = v3;
      CAkMusicRenderer::m_listCtx.m_pLast = m_pLast;
    }
  }
LABEL_12:
  m_pSequencer = in_pMusicCtx->m_pSequencer;
  if ( m_pSequencer )
  {
    m_PlayingID = m_pSequencer->m_UserParams.m_PlayingID;
    if ( m_PlayingID )
    {
      if ( (in_pMusicCtx->m_uRegisteredNotif & 0x20000) != 0 )
        CAkPositionRepository::RemovePlayingID(&CAkMusicRenderer::m_segmentInfoRepository, m_PlayingID);
      CAkPlayingMgr::Remove(g_pPlayingMgr, m_pSequencer->m_UserParams.m_PlayingID, &in_pMusicCtx->CAkTransportAware);
      if ( ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))in_pMusicCtx->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(in_pMusicCtx) )
      {
        v8 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))in_pMusicCtx->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(in_pMusicCtx);
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v8 + 312i64))(v8, 3i64);
      }
    }
    v9 = g_DefaultPoolId;
    CAkMatrixSequencer::~CAkMatrixSequencer(m_pSequencer);
    AK::MemoryMgr::Free(v9, m_pSequencer);
  }
  SetEvent(CAkMusicRenderer::m_hTermEvent);
}

// File Line: 600
// RVA: 0xAA9A10
void __fastcall CAkMusicRenderer::PerformNextFrameBehavior(bool __formal)
{
  CAkMatrixAwareCtx *m_pFirst; // rbx
  CAkMatrixAwareCtx *v2; // rcx
  CAkMatrixSequencer *m_pSequencer; // rdi
  AkSegmentInfo in_segmentInfo; // [rsp+20h] [rbp-28h] BYREF

  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  while ( m_pFirst )
  {
    v2 = m_pFirst;
    m_pFirst = m_pFirst->pNextTopLevelSibling;
    m_pSequencer = v2->m_pSequencer;
    if ( (v2->m_uRegisteredNotif & 0x20000) != 0
      && ((unsigned int (__fastcall *)(CAkMatrixAwareCtx *, AkSegmentInfo *))v2->CAkMusicCtx::CAkChildCtx::vfptr[3].OnLastFrame)(
           v2,
           &in_segmentInfo) == 1 )
    {
      CAkSegmentInfoRepository::UpdateSegmentInfo(
        &CAkMusicRenderer::m_segmentInfoRepository,
        m_pSequencer->m_UserParams.m_PlayingID,
        &in_segmentInfo);
    }
    CAkMatrixSequencer::Execute(m_pSequencer, 0x400u);
  }
}

// File Line: 657
// RVA: 0xAAA1E0
bool __fastcall CAkMusicRenderer::SetState(unsigned int in_stateGroupID, unsigned int in_stateID)
{
  CAkMatrixAwareCtx *m_pFirst; // rbx
  unsigned int v3; // r14d
  __int64 v4; // r15
  __int64 v7; // rdi
  CAkMatrixAwareCtx *i; // rbp
  char v9; // al
  __int64 v10; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkMusicRenderer::AkStateChangeRecord *p_Item; // rbx
  AKRESULT v14; // eax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v15; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v16; // rax
  __int64 out_uSegmentLookAhead; // [rsp+70h] [rbp+18h] BYREF
  __int64 out_iSyncTime; // [rsp+78h] [rbp+20h] BYREF

  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  v3 = out_uSegmentLookAhead;
  v4 = out_uSegmentLookAhead;
  v7 = 0i64;
  for ( i = 0i64; m_pFirst; m_pFirst = m_pFirst->pNextTopLevelSibling )
  {
    v9 = *((_BYTE *)&m_pFirst->CAkMusicCtx + 98);
    if ( (v9 & 1) != 0 && (v9 & 0x10) == 0 )
    {
      v10 = CAkMatrixSequencer::QueryStateChangeDelay(
              m_pFirst->m_pSequencer,
              in_stateGroupID,
              (unsigned int *)&out_uSegmentLookAhead,
              &out_iSyncTime);
      if ( !i || v10 < v7 )
      {
        v4 = out_iSyncTime;
        v3 = out_uSegmentLookAhead;
        v7 = v10;
        i = m_pFirst;
      }
    }
  }
  if ( v7 - 1024 <= 0 )
    goto LABEL_32;
  m_pFree = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
  if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFree )
  {
    if ( CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems >= CAkMusicRenderer::m_queuePendingStateChanges.m_ulMaxNumListItems
      || (m_pFree = (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64)) == 0i64 )
    {
LABEL_16:
      for ( m_pFree = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst; m_pFree; m_pFree = m_pFree->pNextListItem )
      {
        if ( m_pFree->Item.stateGroupID == in_stateGroupID )
          *((_DWORD *)&m_pFree->Item + 2) |= 1u;
      }
LABEL_32:
      LOBYTE(v14) = 0;
      return v14;
    }
    m_pFree->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFree;
    CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = m_pFree;
  }
  m_pLast = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
  p_Item = &m_pFree->Item;
  if ( !CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst )
    m_pLast = m_pFree;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = m_pLast;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pFree = m_pFree->pNextListItem;
  m_pFree->pNextListItem = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  ++CAkMusicRenderer::m_queuePendingStateChanges.m_ulNumListItems;
  CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = m_pFree;
  if ( m_pFree == (CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
    goto LABEL_16;
  v14 = CAkMatrixSequencer::ProcessDelayedStateChange(i->m_pSequencer, &m_pFree->Item, v3, v4);
  if ( v14 != AK_Success )
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
  *((_DWORD *)p_Item + 2) &= ~1u;
  *((_DWORD *)p_Item + 2) |= 2u;
  p_Item->stateGroupID = in_stateGroupID;
  p_Item->stateID = in_stateID;
  return v14;
}

// File Line: 722
// RVA: 0xAA9970
void __fastcall CAkMusicRenderer::PerformDelayedStateChange(
        CAkMusicRenderer *this,
        CAkMusicRenderer::AkStateChangeRecord *in_pCookie)
{
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  int v3; // eax
  unsigned int stateGroupID; // edi
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *j; // rax

  for ( i = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst; i; i = i->pNextListItem )
  {
    if ( &i->Item == in_pCookie )
      break;
  }
  *((_DWORD *)&i->Item + 2) &= ~2u;
  v3 = *((_DWORD *)&i->Item + 2);
  if ( (v3 & 1) == 0 )
  {
    *((_DWORD *)&i->Item + 2) = v3 | 1;
    stateGroupID = i->Item.stateGroupID;
    AK::SoundEngine::SetState(stateGroupID, i->Item.stateID, 0, 1);
    for ( j = i->pNextListItem; j; j = j->pNextListItem )
    {
      if ( j->Item.stateGroupID == stateGroupID )
        *((_DWORD *)&j->Item + 2) |= 1u;
    }
  }
  CAkMusicRenderer::CleanPendingStateChanges();
}

// File Line: 756
// RVA: 0xAA9E70
void __fastcall CAkMusicRenderer::RescheduleDelayedStateChange(
        CAkMusicRenderer *this,
        CAkMusicRenderer::AkStateChangeRecord *in_pCookie)
{
  __int64 v2; // rbp
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *i; // rdi
  int v5; // eax
  CAkMatrixAwareCtx *m_pFirst; // rbx
  unsigned int stateGroupID; // esi
  unsigned int v8; // r12d
  __int64 v9; // r13
  CAkMatrixAwareCtx *j; // r14
  char v11; // al
  __int64 v12; // rax
  __int64 out_uSegmentLookAhead; // [rsp+80h] [rbp+18h] BYREF
  __int64 out_iSyncTime; // [rsp+88h] [rbp+20h] BYREF

  v2 = 0i64;
  for ( i = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst; i; i = i->pNextListItem )
  {
    if ( &i->Item == in_pCookie )
      break;
  }
  v5 = *((_DWORD *)&i->Item + 2);
  if ( (v5 & 1) != 0 )
  {
    *((_DWORD *)&i->Item + 2) = v5 & 0xFFFFFFFD;
    CAkMusicRenderer::CleanPendingStateChanges();
    return;
  }
  m_pFirst = CAkMusicRenderer::m_listCtx.m_pFirst;
  stateGroupID = i->Item.stateGroupID;
  v8 = out_uSegmentLookAhead;
  v9 = out_uSegmentLookAhead;
  for ( j = 0i64; m_pFirst; m_pFirst = m_pFirst->pNextTopLevelSibling )
  {
    v11 = *((_BYTE *)&m_pFirst->CAkMusicCtx + 98);
    if ( (v11 & 1) != 0 && (v11 & 0x10) == 0 )
    {
      v12 = CAkMatrixSequencer::QueryStateChangeDelay(
              m_pFirst->m_pSequencer,
              stateGroupID,
              (unsigned int *)&out_uSegmentLookAhead,
              &out_iSyncTime);
      if ( !j || v12 < v2 )
      {
        v9 = out_iSyncTime;
        v8 = out_uSegmentLookAhead;
        v2 = v12;
        j = m_pFirst;
      }
    }
  }
  if ( v2 - 1024 <= 0 )
  {
    AK::SoundEngine::SetState(stateGroupID, i->Item.stateID, 0, 1);
    *((_DWORD *)&i->Item + 2) = *((_DWORD *)&i->Item + 2) & 0xFFFFFFFC | 1;
    do
    {
      if ( i->Item.stateGroupID == stateGroupID )
        *((_DWORD *)&i->Item + 2) |= 1u;
      i = i->pNextListItem;
    }
    while ( i );
LABEL_17:
    CAkMusicRenderer::CleanPendingStateChanges();
    return;
  }
  if ( CAkMatrixSequencer::ProcessDelayedStateChange(j->m_pSequencer, in_pCookie, v8, v9) != AK_Success )
  {
    AK::SoundEngine::SetState(stateGroupID, i->Item.stateID, 0, 1);
    *((_DWORD *)&i->Item + 2) = *((_DWORD *)&i->Item + 2) & 0xFFFFFFFC | 1;
    do
    {
      if ( i->Item.stateGroupID == stateGroupID )
        *((_DWORD *)&i->Item + 2) |= 1u;
      i = i->pNextListItem;
    }
    while ( i );
    goto LABEL_17;
  }
}

// File Line: 895
// RVA: 0xAA94D0
void CAkMusicRenderer::CleanPendingStateChanges(void)
{
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // r8
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v1; // rcx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v2; // rdx
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rax
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // [rsp+20h] [rbp-28h]
  CAkList2<CAkMusicRenderer::AkStateChangeRecord,CAkMusicRenderer::AkStateChangeRecord const &,1,ArrayPoolDefault>::ListItem *v5; // [rsp+28h] [rbp-20h]

  m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  v1 = 0i64;
  v2 = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
  while ( v2 )
  {
    if ( (*((_BYTE *)&v2->Item + 8) & 2) != 0 )
    {
      v1 = v2;
      v2 = v2->pNextListItem;
    }
    else
    {
      v5 = v1;
      pNextListItem = v2->pNextListItem;
      if ( v2 == m_pFirst )
        CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst = v2->pNextListItem;
      else
        v1->pNextListItem = v2->pNextListItem;
      m_pLast = CAkMusicRenderer::m_queuePendingStateChanges.m_pLast;
      if ( v2 == CAkMusicRenderer::m_queuePendingStateChanges.m_pLast )
        m_pLast = v1;
      CAkMusicRenderer::m_queuePendingStateChanges.m_pLast = m_pLast;
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
      m_pFirst = CAkMusicRenderer::m_queuePendingStateChanges.m_pFirst;
      v1 = v5;
      v2 = pNextListItem;
    }
  }
}

