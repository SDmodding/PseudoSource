// File Line: 68
// RVA: 0x15BE010
__int64 dynamic_initializer_for__CAkURenderer::m_listCtxs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkURenderer::m_listCtxs__);
}

// File Line: 69
// RVA: 0x15BDFF0
__int64 dynamic_initializer_for__CAkURenderer::m_CtxNotifQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkURenderer::m_CtxNotifQueue__);
}

// File Line: 72
// RVA: 0x15BDFE0
__int64 dynamic_initializer_for__CAkURenderer::m_BusLimiters__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkURenderer::m_BusLimiters__);
}

// File Line: 73
// RVA: 0x15BDFD0
__int64 dynamic_initializer_for__CAkURenderer::m_AMLimiters__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkURenderer::m_AMLimiters__);
}

// File Line: 74
// RVA: 0x15BE000
__int64 dynamic_initializer_for__CAkURenderer::m_GlobalLimiter__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkURenderer::m_GlobalLimiter__);
}

// File Line: 86
// RVA: 0xA626A0
__int64 __fastcall CAkURenderer::Init()
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v0; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v1; // rcx
  __int64 result; // rax
  unsigned int v3; // edx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v4; // rax

  CAkURenderer::m_uNumVirtualizedSounds = 0;
  CAkURenderer::m_CtxNotifQueue.m_ulNumListItems = 0;
  CAkURenderer::m_CtxNotifQueue.m_ulMaxNumListItems = -1;
  CAkURenderer::m_CtxNotifQueue.m_pFree = 0i64;
  v0 = (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x800ui64);
  v1 = v0;
  CAkURenderer::m_CtxNotifQueue.m_pvMemStart = v0;
  if ( v0 )
  {
    CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems = 64;
    CAkURenderer::m_CtxNotifQueue.m_pFree = v0;
    v3 = 0;
    do
    {
      v4 = v1 + 1;
      ++v3;
      v1->pNextListItem = v1 + 1;
      ++v1;
    }
    while ( v3 < CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems );
    v4[-1].pNextListItem = 0i64;
    result = 1i64;
  }
  else
  {
    result = 52i64;
  }
  CAkURenderer::m_CtxNotifQueue.m_pFirst = 0i64;
  CAkURenderer::m_CtxNotifQueue.m_pLast = 0i64;
  if ( (_DWORD)result == 1 )
    return CAkLEngine::Init();
  return result;
}

// File Line: 103
// RVA: 0xA633D0
void CAkURenderer::Term(void)
{
  __int64 v0; // rdx
  __int64 v1; // rcx
  _BOOL8 v2; // r8
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rdx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *pNextListItem; // rbx

  CAkLEngine::Term();
  CAkURenderer::DestroyAllPBIs(v1, v0, v2);
  CAkURenderer::m_listCtxs.m_pFirst = 0i64;
  CAkURenderer::m_listCtxs.m_pLast = 0i64;
  CAkURenderer::m_listCtxs.m_ulNumListItems = 0;
  if ( CAkURenderer::m_CtxNotifQueue.m_ulMaxNumListItems )
  {
    m_pFree = CAkURenderer::m_CtxNotifQueue.m_pFree;
    while ( 1 )
    {
      m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst;
      if ( !CAkURenderer::m_CtxNotifQueue.m_pFirst )
        break;
      CAkURenderer::m_CtxNotifQueue.m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst->pNextListItem;
      m_pLast = CAkURenderer::m_CtxNotifQueue.m_pLast;
      if ( m_pFirst == CAkURenderer::m_CtxNotifQueue.m_pLast )
        m_pLast = 0i64;
      CAkURenderer::m_CtxNotifQueue.m_pLast = m_pLast;
      if ( m_pFirst < CAkURenderer::m_CtxNotifQueue.m_pvMemStart
        || m_pFirst >= &CAkURenderer::m_CtxNotifQueue.m_pvMemStart[(unsigned __int64)CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
        m_pFree = CAkURenderer::m_CtxNotifQueue.m_pFree;
        --CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
      }
      else
      {
        m_pFirst->pNextListItem = m_pFree;
        --CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
        m_pFree = m_pFirst;
        CAkURenderer::m_CtxNotifQueue.m_pFree = m_pFirst;
      }
    }
    m_pvMemStart = CAkURenderer::m_CtxNotifQueue.m_pvMemStart;
    if ( m_pFree )
    {
      do
      {
        pNextListItem = m_pFree->pNextListItem;
        if ( m_pFree < m_pvMemStart || m_pFree >= &m_pvMemStart[CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pFree);
          m_pvMemStart = CAkURenderer::m_CtxNotifQueue.m_pvMemStart;
        }
        m_pFree = pNextListItem;
      }
      while ( pNextListItem );
    }
    if ( m_pvMemStart )
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pvMemStart);
    *(_QWORD *)&CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems = 0i64;
    CAkURenderer::m_CtxNotifQueue.m_pFirst = 0i64;
    CAkURenderer::m_CtxNotifQueue.m_pLast = 0i64;
  }
  CAkLimiter::Term((CAkSegmentInfoRepository *)&CAkURenderer::m_GlobalLimiter);
  CAkURenderer::m_AMLimiters.m_pFirst = 0i64;
  CAkURenderer::m_BusLimiters.m_pFirst = 0i64;
}

// File Line: 120
// RVA: 0xA63870
PriorityInfoCurrent *__fastcall CAkURenderer::_CalcInitialPriority(
        PriorityInfoCurrent *result,
        CAkSoundBase *in_pSound,
        CAkRegisteredObj *in_pGameObj,
        float *out_fMaxRadius)
{
  CAkIndexableVtbl *vfptr; // rax
  bool v9; // zf
  float MinDistance; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  PriorityInfo resulta; // [rsp+40h] [rbp+8h] BYREF

  *out_fMaxRadius = 0.0;
  resulta = *CAkParameterNodeBase::GetPriority(in_pSound, &resulta, in_pGameObj);
  result->priorityInfo = resulta;
  vfptr = in_pSound->vfptr;
  result->currentPriority.priority = resulta.priority;
  if ( ((unsigned __int8 (__fastcall *)(CAkSoundBase *, float *))vfptr[7].Release)(in_pSound, out_fMaxRadius) )
  {
    v9 = result->priorityInfo.distanceOffset == 0.0;
    *out_fMaxRadius = in_pGameObj->m_fScalingFactor * *out_fMaxRadius;
    if ( v9 )
      return result;
    MinDistance = CAkURenderer::GetMinDistance(&in_pGameObj->m_PosKeep);
    if ( MinDistance >= *out_fMaxRadius )
      v11 = result->priorityInfo.priority + result->priorityInfo.distanceOffset;
    else
      v11 = (float)((float)(MinDistance / *out_fMaxRadius) * result->priorityInfo.distanceOffset)
          + result->priorityInfo.priority;
    if ( v11 >= 0.0 )
    {
      v12 = FLOAT_100_0;
      if ( v11 > 100.0 )
      {
LABEL_11:
        result->currentPriority.priority = v12;
        return result;
      }
      if ( v11 >= 0.0 )
      {
        v12 = v11;
        goto LABEL_11;
      }
    }
    v12 = 0.0;
    goto LABEL_11;
  }
  return result;
}

// File Line: 144
// RVA: 0xA62590
float __fastcall CAkURenderer::GetMinDistance(AkSoundPositionRef *in_rPosRef)
{
  unsigned int m_uListenerMask; // ebp
  __int64 v2; // r14
  float i; // xmm6_4
  __int64 v5; // rsi
  float v6; // xmm0_4
  __int64 j; // rbx
  unsigned __int16 m_uNumPos; // ax
  AkSoundPosition *m_aPos; // rdx
  float v11; // xmm0_4

  m_uListenerMask = (unsigned __int8)in_rPosRef->m_uListenerMask;
  v2 = 0i64;
  for ( i = FLOAT_1_0e10; m_uListenerMask; m_uListenerMask >>= 1 )
  {
    if ( (m_uListenerMask & 1) != 0 )
    {
      v5 = 144 * v2;
      if ( (*((_BYTE *)in_rPosRef + 11) & 7) == 0 || in_rPosRef->m_uNumPos )
      {
        for ( j = 0i64; ; j = (unsigned int)(j + 1) )
        {
          m_uNumPos = 1;
          if ( (*((_BYTE *)in_rPosRef + 11) & 7) != 0 )
            m_uNumPos = in_rPosRef->m_uNumPos;
          if ( (unsigned int)j >= m_uNumPos )
            break;
          m_aPos = &g_DefaultSoundPosition;
          if ( in_rPosRef->m_aPos )
            m_aPos = in_rPosRef->m_aPos;
          v11 = AkMath::Distance((AkVector *)((char *)&CAkListener::m_listeners + v5 + 24), &m_aPos[j].Position)
              / *(float *)((char *)&CAkListener::m_listeners + v5 + 36);
          if ( i >= v11 )
            i = v11;
        }
      }
      else
      {
        v6 = AkMath::Distance(
               (AkVector *)((char *)&CAkListener::m_listeners + v5 + 24),
               &g_DefaultSoundPosition.Position)
           / *(float *)((char *)&CAkListener::m_listeners + v5 + 36);
        if ( i >= v6 )
          i = v6;
      }
    }
    v2 = (unsigned int)(v2 + 1);
  }
  return i;
}

// File Line: 177
// RVA: 0xA63060
__int64 __fastcall ResolveExternalSource(CAkSource **io_pSource, AkPBIParams *in_rPBIParams)
{
  AkExternalSourceArray *pExternalSrcs; // rbx
  CAkSource *v5; // rdi
  unsigned int m_nCount; // edx
  AkExternalSourceInfo *m_pSrcs; // rax
  unsigned int v8; // ecx
  unsigned int v9; // r10d
  int v10; // ebx
  unsigned int sourceID; // ecx
  AkMediaInformation v12[2]; // [rsp+40h] [rbp-28h] BYREF

  pExternalSrcs = in_rPBIParams->userParams.m_CustomParam.pExternalSrcs;
  if ( !pExternalSrcs )
    return 2i64;
  v5 = CAkSource::Clone(*io_pSource);
  *io_pSource = v5;
  if ( !v5 )
    return 52i64;
  m_nCount = pExternalSrcs->m_nCount;
  m_pSrcs = pExternalSrcs->m_pSrcs;
  v8 = 0;
  if ( !m_nCount )
  {
LABEL_12:
    v10 = g_DefaultPoolId;
    CAkSource::~CAkSource(v5);
    AK::MemoryMgr::Free(v10, v5);
    return 2i64;
  }
  while ( 1 )
  {
    if ( v5->m_sSrcTypeInfo.mediaInfo.uFileID != m_pSrcs->iExternalSrcCookie )
      goto LABEL_11;
    v9 = (m_pSrcs->idCodec << 16) + 1;
    if ( m_pSrcs->szFile )
      break;
    if ( m_pSrcs->uiMemorySize && m_pSrcs->pInMemory )
    {
      v12[0].sourceID = v5->m_sSrcTypeInfo.mediaInfo.sourceID;
      v12[0].uInMemoryMediaSize = m_pSrcs->uiMemorySize;
      *(_QWORD *)&v12[0].uFileID = 0xFFFFFFFFi64;
      *((_DWORD *)v12 + 4) = *((_DWORD *)v12 + 4) & 0xFFFFF800 | 0x18C;
      CAkSource::SetSource(v5, v9, m_pSrcs->pInMemory, v12);
      return 1i64;
    }
    if ( m_pSrcs->idFile )
    {
      sourceID = v5->m_sSrcTypeInfo.mediaInfo.sourceID;
      *(_QWORD *)&v12[0].uFileOffset = 0i64;
      v12[0].sourceID = sourceID;
      v12[0].uFileID = m_pSrcs->idFile;
      *((_DWORD *)v12 + 4) = *((_DWORD *)v12 + 4) & 0xFFFFF800 | 0x104;
      CAkSource::SetSource(v5, v9, v12);
      return 1i64;
    }
LABEL_11:
    ++v8;
    ++m_pSrcs;
    if ( v8 >= m_nCount )
      goto LABEL_12;
  }
  CAkSource::SetSource(
    v5,
    v5->m_sSrcTypeInfo.mediaInfo.sourceID,
    v9,
    m_pSrcs->szFile,
    0xFFFFFFFF,
    (*((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) & 0x200) != 0,
    1);
  return 1i64;
}

// File Line: 236
// RVA: 0xA62690
bool __fastcall CAkURenderer::GetVirtualBehaviorAction(AkBelowThresholdBehavior in_belowThresholdBehavior)
{
  return in_belowThresholdBehavior != AkBelowThresholdBehavior_KillVoice;
}

// File Line: 269
// RVA: 0xA62BE0
AKRESULT __fastcall CAkURenderer::Play(CAkSoundBase *in_pSound, CAkSource *in_pSource, AkPBIParams *in_rPBIParams)
{
  AKRESULT v5; // r12d
  float priority; // xmm6_4
  AKRESULT v7; // r13d
  CAkRegisteredObj *pGameObj; // rax
  CAkIndexableVtbl *vfptr; // rax
  int v10; // eax
  bool v11; // si
  CAkSource *v12; // r8
  CAkRegisteredObj *v13; // rcx
  CAkIndexableVtbl *v14; // rax
  __int64 v15; // rax
  CAkPBI *v16; // rsi
  __int64 v17; // r8
  int v18; // eax
  __int64 v19; // rdx
  AKRESULT v20; // eax
  int v21; // ebx
  CAkRegisteredObj *v22; // rax
  CAkIndexableVtbl *v23; // rax
  CAkRegisteredObj *v24; // rax
  CAkIndexableVtbl *v25; // rax
  PriorityInfoCurrent result; // [rsp+8h] [rbp-59h] BYREF
  __int64 v27; // [rsp+18h] [rbp-49h] BYREF
  PlayHistory *p_playHistory; // [rsp+20h] [rbp-41h]
  __int64 v29[2]; // [rsp+28h] [rbp-39h] BYREF
  __int64 v30; // [rsp+38h] [rbp-29h]
  PriorityInfoCurrent v31; // [rsp+40h] [rbp-21h] BYREF
  int v32; // [rsp+50h] [rbp-11h] BYREF
  CAkRegisteredObj *v33; // [rsp+58h] [rbp-9h]
  __int64 v34; // [rsp+60h] [rbp-1h]
  __int64 v35; // [rsp+68h] [rbp+7h]
  int v36; // [rsp+70h] [rbp+Fh]
  __int16 v37; // [rsp+74h] [rbp+13h]
  CAkSource *io_pSource; // [rsp+D0h] [rbp+6Fh] BYREF
  float out_fMaxRadius; // [rsp+D8h] [rbp+77h]
  AkVirtualQueueBehavior out_Behavior[4]; // [rsp+E0h] [rbp+7Fh] BYREF
  float v41; // [rsp+110h] [rbp+AFh] BYREF

  v5 = AK_Fail;
  CAkURenderer::_CalcInitialPriority(&v31, in_pSound, in_rPBIParams->pGameObj, &v41);
  priority = result.currentPriority.priority;
  if ( !CAkURenderer::ValidateMemoryLimit(result.currentPriority.priority)
    || (v7 = CAkURenderer::ValidateMaximumNumberVoiceLimit(priority), v7 == AK_Fail) )
  {
    v5 = AK_PartialSuccess;
LABEL_20:
    p_playHistory = &in_rPBIParams->playHistory;
    _((AMD_HD3D *)in_pSound);
    return v5;
  }
  v30 = 0i64;
  v31.currentPriority = 0i64;
  pGameObj = in_rPBIParams->pGameObj;
  *(float *)v29 = result.currentPriority.priority;
  v29[1] = (__int64)pGameObj;
  vfptr = in_pSound->vfptr;
  LODWORD(v31.priorityInfo.priority) = 3;
  LOWORD(v31.priorityInfo.distanceOffset) = 256;
  v10 = ((__int64 (__fastcall *)(CAkSoundBase *, __int64 *))vfptr[8].Release)(in_pSound, v29);
  v11 = v10 != 2;
  if ( v10 == 80 || v7 == AK_MustBeVirtualized )
    v11 = CAkParameterNode::GetVirtualBehavior(in_pSound, out_Behavior) != AkBelowThresholdBehavior_KillVoice;
  if ( !v11 )
  {
    v34 = 0i64;
    v35 = 0i64;
    v24 = in_rPBIParams->pGameObj;
    v32 = 0;
    v33 = v24;
    v25 = in_pSound->vfptr;
    v5 = AK_PartialSuccess;
    v36 = 3;
    v37 = 256;
    ((void (__fastcall *)(CAkSoundBase *, int *))v25[8].Category)(in_pSound, &v32);
    goto LABEL_20;
  }
  v12 = io_pSource;
  if ( (io_pSource->m_sSrcTypeInfo.dwID & 0xFFFF0000) == 0x80000 )
  {
    v5 = ResolveExternalSource(&io_pSource, in_rPBIParams);
    if ( v5 != AK_Success )
    {
      v13 = in_rPBIParams->pGameObj;
      v34 = 0i64;
      v35 = 0i64;
      v14 = in_pSound->vfptr;
      v32 = 0;
      v33 = v13;
      v36 = 3;
      v37 = 256;
      ((void (__fastcall *)(CAkSoundBase *, int *))v14[8].Category)(in_pSound, &v32);
      return v5;
    }
    v12 = io_pSource;
  }
  v15 = ((__int64 (__fastcall *)(CAkPBIAware *, CAkSoundBase *, CAkSource *, AkPBIParams *, PriorityInfoCurrent *, __int64, _QWORD))in_rPBIParams->pInstigator->vfptr[1].__vecDelDtor)(
          in_rPBIParams->pInstigator,
          in_pSound,
          v12,
          in_rPBIParams,
          &result,
          v30,
          *(_QWORD *)&v31.currentPriority);
  v16 = (CAkPBI *)v15;
  if ( !v15 )
  {
    v34 = 0i64;
    v35 = 0i64;
    v22 = in_rPBIParams->pGameObj;
    v32 = 0;
    v33 = v22;
    v23 = in_pSound->vfptr;
    v36 = 3;
    v37 = 256;
    ((void (__fastcall *)(CAkSoundBase *, int *))v23[8].Category)(in_pSound, &v32);
    goto LABEL_20;
  }
  if ( in_rPBIParams->eType )
  {
    v18 = (*(__int64 (__fastcall **)(__int64, AkPathInfo *))(*(_QWORD *)v15 + 16i64))(
            v15,
            in_rPBIParams->pContinuousParams->pPathInfo);
  }
  else
  {
    v17 = *(_QWORD *)v15;
    v27 = 0i64;
    LODWORD(p_playHistory) = 0;
    v18 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v17 + 16))(v15, &v27);
  }
  if ( v18 != 1
    || (v16->m_fMaxDistance = out_fMaxRadius,
        v16->m_iFrameOffset = in_rPBIParams->uFrameOffset,
        v20 = CAkURenderer::Play(v16, in_rPBIParams->pTransitionParameters, in_rPBIParams->ePlaybackState),
        v20 != AK_Success) )
  {
    LOBYTE(v19) = 1;
    ((void (__fastcall *)(CAkPBI *, __int64))v16->CAkTransportAware::vfptr[1].~CAkTransportAware)(v16, v19);
    v21 = g_DefaultPoolId;
    ((void (__fastcall *)(CAkPBI *, _QWORD))v16->CAkTransportAware::vfptr->~CAkTransportAware)(v16, 0i64);
    AK::MemoryMgr::Free(v21, v16);
    goto LABEL_20;
  }
  return v20;
}

// File Line: 455
// RVA: 0xA62B60
AKRESULT __fastcall CAkURenderer::Play(
        CAkPBI *in_pContext,
        TransParams *in_rTparameters,
        AkPlaybackState in_ePlaybackState)
{
  AKRESULT result; // eax

  CAkPBI::_InitPlay(in_pContext);
  result = CAkPBI::_Play(in_pContext, in_rTparameters, in_ePlaybackState == PB_Paused, 0);
  if ( result == AK_Success )
  {
    in_pContext->pNextItem = 0i64;
    if ( CAkURenderer::m_listCtxs.m_pLast )
      CAkURenderer::m_listCtxs.m_pLast->pNextItem = in_pContext;
    else
      CAkURenderer::m_listCtxs.m_pFirst = in_pContext;
    ++CAkURenderer::m_listCtxs.m_ulNumListItems;
    CAkURenderer::m_listCtxs.m_pLast = in_pContext;
  }
  return result;
}

// File Line: 495
// RVA: 0xA632C0
__int64 __fastcall CAkURenderer::Stop(
        CAkSoundBase *in_pSound,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_rTparameters,
        unsigned int in_PlayingID)
{
  CAkPBI *i; // rbx

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
  {
    if ( i->m_pSound == in_pSound
      && (!in_pGameObj || i->m_pGameObj == in_pGameObj)
      && (!in_PlayingID || i->m_UserParams.m_PlayingID == in_PlayingID) )
    {
      CAkPBI::_Stop(i, in_rTparameters, 1);
    }
  }
  return 1i64;
}

// File Line: 524
// RVA: 0xA62940
__int64 __fastcall CAkURenderer::Pause(
        CAkSoundBase *in_pSound,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_rTparameters,
        unsigned int in_PlayingID)
{
  CAkPBI *i; // rbx

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
  {
    if ( i->m_pSound == in_pSound
      && (!in_pGameObj || i->m_pGameObj == in_pGameObj)
      && (!in_PlayingID || i->m_UserParams.m_PlayingID == in_PlayingID) )
    {
      CAkPBI::_Pause(i, in_rTparameters);
    }
  }
  return 1i64;
}

// File Line: 554
// RVA: 0xA63230
__int64 __fastcall CAkURenderer::Resume(
        CAkSoundBase *in_pSound,
        CAkRegisteredObj *in_pGameObj,
        TransParams *in_rTparameters,
        bool in_bIsMasterResume,
        unsigned int in_PlayingID)
{
  CAkPBI *i; // rbx

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
  {
    if ( i->m_pSound == in_pSound
      && (!in_pGameObj || i->m_pGameObj == in_pGameObj)
      && (!in_PlayingID || i->m_UserParams.m_PlayingID == in_PlayingID) )
    {
      CAkPBI::_Resume(i, in_rTparameters, in_bIsMasterResume);
    }
  }
  return 1i64;
}

// File Line: 636
// RVA: 0xA62470
void __fastcall CAkURenderer::EnqueueContext(CAkPBI *in_pContext)
{
  in_pContext->pNextItem = 0i64;
  if ( CAkURenderer::m_listCtxs.m_pLast )
  {
    CAkURenderer::m_listCtxs.m_pLast->pNextItem = in_pContext;
    ++CAkURenderer::m_listCtxs.m_ulNumListItems;
  }
  else
  {
    ++CAkURenderer::m_listCtxs.m_ulNumListItems;
    CAkURenderer::m_listCtxs.m_pFirst = in_pContext;
  }
  CAkURenderer::m_listCtxs.m_pLast = in_pContext;
}

// File Line: 644
// RVA: 0xA62270
void __fastcall CAkURenderer::DecrementVirtualCount(bool in_bAllowKick)
{
  unsigned int v1; // edx
  int m_u16LimiterMax; // r12d
  CAkPBI **m_pItems; // rbx
  CAkPBI *v4; // r15
  CAkPBI **v5; // rdi
  unsigned __int16 v6; // bp
  int v7; // r14d
  float v8; // xmm8_4
  CAkPBI *v9; // rsi
  char v10; // al
  float priority; // xmm6_4
  AkBelowThresholdBehavior VirtualBehavior; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+80h] [rbp+8h] BYREF

  v1 = --CAkURenderer::m_uNumVirtualizedSounds;
  if ( in_bAllowKick )
  {
    m_u16LimiterMax = CAkURenderer::m_GlobalLimiter.m_u16LimiterMax;
    if ( CAkURenderer::m_listCtxs.m_ulNumListItems - v1 > CAkURenderer::m_GlobalLimiter.m_u16LimiterMax )
    {
      m_pItems = CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems;
      v4 = 0i64;
      v5 = &CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems[CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_uLength];
      v6 = 0;
      v7 = 2;
      v8 = FLOAT_101_0;
      if ( CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems != v5 )
      {
        do
        {
          v9 = *m_pItems;
          if ( (*((_BYTE *)*m_pItems + 374) & 1) == 0 )
          {
            v10 = *((_BYTE *)v9 + 375);
            if ( (v10 & 0x10) == 0 && (v10 & 0x40) == 0 )
            {
              priority = v9->m_PriorityInfoCurrent.currentPriority.priority;
              ++v6;
              if ( priority <= 101.0 )
              {
                VirtualBehavior = CAkPBI::GetVirtualBehavior(*m_pItems, &out_Behavior);
                if ( VirtualBehavior )
                {
                  v7 = VirtualBehavior;
                  v4 = v9;
                  v8 = priority;
                }
              }
            }
          }
          ++m_pItems;
        }
        while ( m_pItems != v5 );
      }
      if ( v6 + 1 > m_u16LimiterMax && v8 < 101.0 && v4 && v7 == 1 )
        CAkPBI::Kick(v4, KickFrom_OverGlobalLimit);
    }
  }
}

// File Line: 750
// RVA: 0xA62790
__int64 __fastcall CAkURenderer::Kick(
        CAkLimiter *in_pLimiter,
        unsigned __int16 in_uMaxInstances,
        float in_fPriority,
        CAkRegisteredObj *in_pGameObj,
        bool in_bKickNewest,
        bool in_bUseVirtualBehavior,
        CAkParameterNodeBase **out_pKicked,
        KickFrom in_eReason)
{
  bool v10; // r8
  CAkPBI **m_pItems; // rbx
  CAkPBI *v12; // r14
  float v13; // xmm8_4
  CAkPBI **v14; // rdi
  unsigned int v15; // ebp
  unsigned __int16 v16; // r13
  int v17; // r15d
  CAkPBI *v18; // rsi
  char v19; // al
  float priority; // xmm6_4
  AkBelowThresholdBehavior VirtualBehavior; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+90h] [rbp+8h] BYREF
  unsigned __int16 v23; // [rsp+98h] [rbp+10h]

  v23 = in_uMaxInstances;
  if ( !in_pLimiter )
    return 1i64;
  v10 = in_bUseVirtualBehavior;
  m_pItems = in_pLimiter->m_sortedPBIList.m_pItems;
  v12 = 0i64;
  v13 = FLOAT_101_0;
  v14 = &in_pLimiter->m_sortedPBIList.m_pItems[in_pLimiter->m_sortedPBIList.m_uLength];
  v15 = 2;
  v16 = 0;
  v17 = 2;
  if ( in_pLimiter->m_sortedPBIList.m_pItems != v14 )
  {
    while ( 1 )
    {
      v18 = *m_pItems;
      if ( in_pGameObj && v18->m_pGameObj != in_pGameObj )
        goto LABEL_14;
      if ( (*((_BYTE *)v18 + 374) & 1) != 0 )
        goto LABEL_14;
      v19 = *((_BYTE *)v18 + 375);
      if ( (v19 & 0x10) != 0 )
        goto LABEL_14;
      if ( (v19 & 0x40) != 0 )
        goto LABEL_14;
      priority = v18->m_PriorityInfoCurrent.currentPriority.priority;
      ++v16;
      if ( priority > in_fPriority )
        goto LABEL_14;
      if ( !v10 )
        goto LABEL_13;
      VirtualBehavior = CAkPBI::GetVirtualBehavior(*m_pItems, &out_Behavior);
      if ( VirtualBehavior )
        break;
LABEL_14:
      v10 = in_bUseVirtualBehavior;
      if ( ++m_pItems == v14 )
        goto LABEL_15;
    }
    v17 = VirtualBehavior;
LABEL_13:
    v12 = v18;
    v13 = priority;
    goto LABEL_14;
  }
LABEL_15:
  if ( v16 + 1 <= v23 )
    return 1i64;
  if ( in_fPriority < v13 || in_bKickNewest && in_fPriority == v13 || !v12 )
  {
    if ( v10 )
      return 80;
  }
  else
  {
    *out_pKicked = v12->m_pSound;
    if ( !v10 || v17 == 1 )
      CAkPBI::Kick(v12, in_eReason);
    return 1;
  }
  return v15;
}

// File Line: 875
// RVA: 0xA636E0
char __fastcall CAkURenderer::ValidateMemoryLimit(float in_fPriority)
{
  float fDefaultPoolRatioThreshold; // xmm7_4
  float fLEngineDefaultPoolRatioThreshold; // xmm7_4
  CAkPBI *m_pFirst; // rax
  float priority; // xmm1_4
  CAkPBI *i; // r8
  char v6; // cl
  AK::MemoryMgr::PoolMemInfo out_memInfo; // [rsp+58h] [rbp+10h] BYREF

  fDefaultPoolRatioThreshold = g_settings.fDefaultPoolRatioThreshold;
  if ( g_settings.fDefaultPoolRatioThreshold >= 1.0
    || (AK::MemoryMgr::GetPoolMemoryUsed(g_DefaultPoolId, &out_memInfo), !out_memInfo.uReserved)
    || (float)((float)(int)out_memInfo.uUsed / (float)(int)out_memInfo.uReserved) <= fDefaultPoolRatioThreshold )
  {
    fLEngineDefaultPoolRatioThreshold = g_PDSettings.fLEngineDefaultPoolRatioThreshold;
    if ( g_PDSettings.fLEngineDefaultPoolRatioThreshold >= 1.0 )
      return 1;
    AK::MemoryMgr::GetPoolMemoryUsed(g_LEngineDefaultPoolId, &out_memInfo);
    if ( !out_memInfo.uReserved
      || (float)((float)(int)out_memInfo.uUsed / (float)(int)out_memInfo.uReserved) <= fLEngineDefaultPoolRatioThreshold )
    {
      return 1;
    }
  }
  m_pFirst = CAkURenderer::m_listCtxs.m_pFirst;
  priority = FLOAT_101_0;
  for ( i = 0i64; m_pFirst; m_pFirst = m_pFirst->pNextItem )
  {
    if ( (*((_BYTE *)m_pFirst + 374) & 1) == 0 )
    {
      v6 = *((_BYTE *)m_pFirst + 375);
      if ( (v6 & 0x10) == 0 && (v6 & 0x40) == 0 && m_pFirst->m_PriorityInfoCurrent.currentPriority.priority <= priority )
      {
        i = m_pFirst;
        priority = m_pFirst->m_PriorityInfoCurrent.currentPriority.priority;
      }
    }
  }
  if ( in_fPriority <= priority || !i )
    return 0;
  CAkPBI::Kick(i, KickFrom_OverMemoryLimit);
  return 1;
}

// File Line: 904
// RVA: 0xA63580
__int64 __fastcall CAkURenderer::ValidateMaximumNumberVoiceLimit(float in_fPriority)
{
  int m_u16LimiterMax; // r12d
  CAkPBI **m_pItems; // rbx
  CAkPBI *v3; // r15
  CAkPBI **v4; // rdi
  float v5; // xmm8_4
  unsigned __int16 v6; // bp
  int v7; // r14d
  CAkPBI *v8; // rsi
  char v9; // al
  float priority; // xmm6_4
  AkBelowThresholdBehavior VirtualBehavior; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+88h] [rbp+10h] BYREF

  m_u16LimiterMax = CAkURenderer::m_GlobalLimiter.m_u16LimiterMax;
  if ( CAkURenderer::m_listCtxs.m_ulNumListItems - CAkURenderer::m_uNumVirtualizedSounds + 1 <= CAkURenderer::m_GlobalLimiter.m_u16LimiterMax )
    return 1i64;
  m_pItems = CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems;
  v3 = 0i64;
  v4 = &CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems[CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_uLength];
  v5 = FLOAT_101_0;
  v6 = 0;
  v7 = 2;
  if ( CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems != v4 )
  {
    do
    {
      v8 = *m_pItems;
      if ( (*((_BYTE *)*m_pItems + 374) & 1) == 0 )
      {
        v9 = *((_BYTE *)v8 + 375);
        if ( (v9 & 0x10) == 0 && (v9 & 0x40) == 0 )
        {
          priority = v8->m_PriorityInfoCurrent.currentPriority.priority;
          ++v6;
          if ( priority <= in_fPriority )
          {
            VirtualBehavior = CAkPBI::GetVirtualBehavior(*m_pItems, &out_Behavior);
            if ( VirtualBehavior )
            {
              v7 = VirtualBehavior;
              v3 = v8;
              v5 = priority;
            }
          }
        }
      }
      ++m_pItems;
    }
    while ( m_pItems != v4 );
  }
  if ( v6 + 1 <= m_u16LimiterMax )
    return 1i64;
  if ( in_fPriority > v5 && v3 )
  {
    if ( v7 == 1 )
      CAkPBI::Kick(v3, KickFrom_OverGlobalLimit);
    return 1i64;
  }
  return 80i64;
}

// File Line: 933
// RVA: 0xA63530
AKRESULT __fastcall CAkURenderer::ValidateLimits(
        float in_fPriority,
        AkMonitorData::NotificationReason *out_eReasonOfFailure)
{
  if ( CAkURenderer::ValidateMemoryLimit(in_fPriority) )
  {
    *out_eReasonOfFailure = NotificationReason_PlayFailedGlobalLimit;
    return CAkURenderer::ValidateMaximumNumberVoiceLimit(in_fPriority);
  }
  else
  {
    *out_eReasonOfFailure = NotificationReason_PlayFailedMemoryThreshold;
    return 2;
  }
}

// File Line: 946
// RVA: 0xA624B0
void __fastcall CAkURenderer::EnqueueContextNotif(
        CAkPBI *in_pPBI,
        AkCtxState in_eState,
        AkCtxDestroyReason in_eDestroyReason,
        float in_fEstimatedTime)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pFree; // r9
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkURenderer::ContextNotif *p_Item; // rax

  m_pFree = CAkURenderer::m_CtxNotifQueue.m_pFree;
  if ( !CAkURenderer::m_CtxNotifQueue.m_pFree )
  {
    if ( CAkURenderer::m_CtxNotifQueue.m_ulNumListItems >= CAkURenderer::m_CtxNotifQueue.m_ulMaxNumListItems
      || (v8 = (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(LODWORD(CAkURenderer::m_CtxNotifQueue.m_pFree) + 32)),
          (m_pFree = v8) == 0i64) )
    {
LABEL_9:
      CAkURenderer::PerformContextNotif();
      p_Item = CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::AddLast(&CAkURenderer::m_CtxNotifQueue);
      goto LABEL_10;
    }
    v8->pNextListItem = CAkURenderer::m_CtxNotifQueue.m_pFree;
    CAkURenderer::m_CtxNotifQueue.m_pFree = v8;
  }
  if ( CAkURenderer::m_CtxNotifQueue.m_pLast )
  {
    CAkURenderer::m_CtxNotifQueue.m_pLast->pNextListItem = m_pFree;
    m_pFree = CAkURenderer::m_CtxNotifQueue.m_pFree;
  }
  else
  {
    CAkURenderer::m_CtxNotifQueue.m_pFirst = m_pFree;
  }
  CAkURenderer::m_CtxNotifQueue.m_pLast = m_pFree;
  CAkURenderer::m_CtxNotifQueue.m_pFree = m_pFree->pNextListItem;
  m_pFree->pNextListItem = 0i64;
  ++CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
  p_Item = &CAkURenderer::m_CtxNotifQueue.m_pLast->Item;
  if ( CAkURenderer::m_CtxNotifQueue.m_pLast == (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
    goto LABEL_9;
LABEL_10:
  p_Item->fEstimatedLength = in_fEstimatedTime;
  p_Item->pPBI = in_pPBI;
  p_Item->DestroyReason = in_eDestroyReason;
  p_Item->state = in_eState;
}

// File Line: 971
// RVA: 0xA629D0
void CAkURenderer::PerformContextNotif(void)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkPBI *v1; // rdx
  CAkPBI *v2; // rcx
  CAkPBI *m_pLast; // rax
  CAkPBI *pPBI; // rdi
  int v5; // ebx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  unsigned int m_ulNumListItems; // eax

  if ( CAkURenderer::m_CtxNotifQueue.m_ulNumListItems )
  {
    m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst;
    do
    {
      CAkPBI::ProcessContextNotif(
        m_pFirst->Item.pPBI,
        m_pFirst->Item.state,
        m_pFirst->Item.DestroyReason,
        m_pFirst->Item.fEstimatedLength);
      if ( m_pFirst->Item.state == CtxStateToDestroy )
      {
        v1 = 0i64;
        v2 = CAkURenderer::m_listCtxs.m_pFirst;
        if ( CAkURenderer::m_listCtxs.m_pFirst )
        {
          while ( v2 != m_pFirst->Item.pPBI )
          {
            v1 = v2;
            v2 = v2->pNextItem;
            if ( !v2 )
              goto LABEL_15;
          }
          if ( v2 )
          {
            if ( v2 == CAkURenderer::m_listCtxs.m_pFirst )
              CAkURenderer::m_listCtxs.m_pFirst = v2->pNextItem;
            else
              v1->pNextItem = v2->pNextItem;
            m_pLast = CAkURenderer::m_listCtxs.m_pLast;
            if ( v2 == CAkURenderer::m_listCtxs.m_pLast )
              m_pLast = v1;
            --CAkURenderer::m_listCtxs.m_ulNumListItems;
            CAkURenderer::m_listCtxs.m_pLast = m_pLast;
          }
        }
LABEL_15:
        pPBI = m_pFirst->Item.pPBI;
        CAkLEngineCmds::DequeuePBI(pPBI);
        ((void (__fastcall *)(CAkPBI *, _QWORD))pPBI->CAkTransportAware::vfptr[1].~CAkTransportAware)(pPBI, 0i64);
        v5 = g_DefaultPoolId;
        ((void (__fastcall *)(CAkPBI *, _QWORD))pPBI->CAkTransportAware::vfptr->~CAkTransportAware)(pPBI, 0i64);
        AK::MemoryMgr::Free(v5, pPBI);
      }
      m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst;
      if ( CAkURenderer::m_CtxNotifQueue.m_pFirst )
      {
        CAkURenderer::m_CtxNotifQueue.m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst->pNextListItem;
        v6 = CAkURenderer::m_CtxNotifQueue.m_pLast;
        if ( m_pFirst == CAkURenderer::m_CtxNotifQueue.m_pLast )
          v6 = 0i64;
        CAkURenderer::m_CtxNotifQueue.m_pLast = v6;
        if ( m_pFirst < CAkURenderer::m_CtxNotifQueue.m_pvMemStart
          || m_pFirst >= &CAkURenderer::m_CtxNotifQueue.m_pvMemStart[(unsigned __int64)CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
        }
        else
        {
          m_pFirst->pNextListItem = CAkURenderer::m_CtxNotifQueue.m_pFree;
          CAkURenderer::m_CtxNotifQueue.m_pFree = m_pFirst;
        }
        m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst;
        m_ulNumListItems = --CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
      }
      else
      {
        m_ulNumListItems = CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
      }
    }
    while ( m_ulNumListItems );
  }
}

// File Line: 1024
// RVA: 0xA623C0
void __fastcall CAkURenderer::DestroyAllPBIs(__int64 a1, __int64 a2, _BOOL8 a3)
{
  CAkPBI *m_pFirst; // rax
  CAkPBI *i; // rdi
  CAkPBI *pNextItem; // rax
  int v6; // ebx

  m_pFirst = CAkURenderer::m_listCtxs.m_pFirst;
  for ( i = CAkURenderer::m_listCtxs.m_pFirst; CAkURenderer::m_listCtxs.m_pFirst; i = CAkURenderer::m_listCtxs.m_pFirst )
  {
    pNextItem = m_pFirst->pNextItem;
    if ( pNextItem )
    {
      CAkURenderer::m_listCtxs.m_pFirst = pNextItem;
    }
    else
    {
      CAkURenderer::m_listCtxs.m_pFirst = 0i64;
      CAkURenderer::m_listCtxs.m_pLast = 0i64;
    }
    --CAkURenderer::m_listCtxs.m_ulNumListItems;
    LOBYTE(a3) = 1;
    i->CAkTransportAware::vfptr->_Stop(i, AkPBIStopMode_Normal, a3, 0);
    CAkLEngineCmds::DequeuePBI(i);
    ((void (__fastcall *)(CAkPBI *, _QWORD))i->CAkTransportAware::vfptr[1].~CAkTransportAware)(i, 0i64);
    v6 = g_DefaultPoolId;
    ((void (__fastcall *)(CAkPBI *, _QWORD))i->CAkTransportAware::vfptr->~CAkTransportAware)(i, 0i64);
    AK::MemoryMgr::Free(v6, i);
    m_pFirst = CAkURenderer::m_listCtxs.m_pFirst;
  }
}

// File Line: 1034
// RVA: 0xA63350
void __fastcall CAkURenderer::StopAllPBIs(CAkUsageSlot *in_pUsageSlot)
{
  CAkPBI *i; // rbx
  TransParams in_transParams; // [rsp+38h] [rbp+10h] BYREF

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
  {
    if ( CAkPBI::IsUsingThisSlot(i, in_pUsageSlot) )
    {
      in_transParams = 0i64;
      CAkPBI::_Stop(i, &in_transParams, 1);
      CAkAudioMgr::StopPendingAction(g_pAudioMgr, i->m_pSound, 0i64, 0);
    }
  }
  CAkLEngine::StopMixBussesUsingThisSlot(in_pUsageSlot);
}

// File Line: 1153
// RVA: 0xA62740
void CAkURenderer::InvalidateAllMotionPBIs(void)
{
  CAkPBI *i; // rbx
  char v1; // al

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
  {
    v1 = *((_BYTE *)i + 371);
    if ( (v1 & 3) == 1 && (v1 & 0xC) == 4 )
      CAkPBI::InvalidateFeedbackParameters(i);
  }
}

// File Line: 1163
// RVA: 0xA621C0
void __fastcall CAkURenderer::AddBusLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *m_pFirst; // rax

  m_pFirst = CAkURenderer::m_BusLimiters.m_pFirst;
  if ( CAkURenderer::m_BusLimiters.m_pFirst )
  {
    in_pLimiter->pNextLightItem = CAkURenderer::m_BusLimiters.m_pFirst;
    CAkURenderer::m_BusLimiters.m_pFirst = in_pLimiter;
  }
  else
  {
    CAkURenderer::m_BusLimiters.m_pFirst = in_pLimiter;
    in_pLimiter->pNextLightItem = m_pFirst;
  }
}

// File Line: 1168
// RVA: 0xA63010
void __fastcall CAkURenderer::RemoveBusLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // r8
  CAkLimiter *m_pFirst; // rdx

  v1 = 0i64;
  m_pFirst = CAkURenderer::m_BusLimiters.m_pFirst;
  if ( CAkURenderer::m_BusLimiters.m_pFirst )
  {
    while ( m_pFirst != in_pLimiter )
    {
      v1 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
      if ( !m_pFirst )
        return;
    }
    if ( m_pFirst )
    {
      if ( m_pFirst == CAkURenderer::m_BusLimiters.m_pFirst )
        CAkURenderer::m_BusLimiters.m_pFirst = m_pFirst->pNextLightItem;
      else
        v1->pNextLightItem = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 1173
// RVA: 0xA62190
void __fastcall CAkURenderer::AddAMLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *m_pFirst; // rax

  m_pFirst = CAkURenderer::m_AMLimiters.m_pFirst;
  if ( CAkURenderer::m_AMLimiters.m_pFirst )
  {
    in_pLimiter->pNextLightItem = CAkURenderer::m_AMLimiters.m_pFirst;
    CAkURenderer::m_AMLimiters.m_pFirst = in_pLimiter;
  }
  else
  {
    CAkURenderer::m_AMLimiters.m_pFirst = in_pLimiter;
    in_pLimiter->pNextLightItem = m_pFirst;
  }
}

// File Line: 1178
// RVA: 0xA62FC0
void __fastcall CAkURenderer::RemoveAMLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // r8
  CAkLimiter *m_pFirst; // rdx

  v1 = 0i64;
  m_pFirst = CAkURenderer::m_AMLimiters.m_pFirst;
  if ( CAkURenderer::m_AMLimiters.m_pFirst )
  {
    while ( m_pFirst != in_pLimiter )
    {
      v1 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
      if ( !m_pFirst )
        return;
    }
    if ( m_pFirst )
    {
      if ( m_pFirst == CAkURenderer::m_AMLimiters.m_pFirst )
        CAkURenderer::m_AMLimiters.m_pFirst = m_pFirst->pNextLightItem;
      else
        v1->pNextLightItem = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 1183
// RVA: 0xA62F30
void CAkURenderer::ProcessLimiters(void)
{
  CAkPBI *i; // rax
  CAkLimiter *j; // rbx
  CAkLimiter *k; // rbx

  for ( i = CAkURenderer::m_listCtxs.m_pFirst; i; i = i->pNextItem )
    *((_BYTE *)i + 375) = *((_BYTE *)i + 375) & 0xCF | (2 * (*((_BYTE *)i + 375) & 0x10));
  CAkLimiter::UpdateFlags(&CAkURenderer::m_GlobalLimiter);
  for ( j = CAkURenderer::m_BusLimiters.m_pFirst; j; j = j->pNextLightItem )
    CAkLimiter::UpdateFlags(j);
  for ( k = CAkURenderer::m_AMLimiters.m_pFirst; k; k = k->pNextLightItem )
    CAkLimiter::UpdateFlags(k);
}

