// File Line: 68
// RVA: 0x15BE010
__int64 dynamic_initializer_for__CAkURenderer::m_listCtxs__()
{
  return atexit(dynamic_atexit_destructor_for__CAkURenderer::m_listCtxs__);
}

// File Line: 69
// RVA: 0x15BDFF0
__int64 dynamic_initializer_for__CAkURenderer::m_CtxNotifQueue__()
{
  return atexit(dynamic_atexit_destructor_for__CAkURenderer::m_CtxNotifQueue__);
}

// File Line: 72
// RVA: 0x15BDFE0
__int64 dynamic_initializer_for__CAkURenderer::m_BusLimiters__()
{
  return atexit(dynamic_atexit_destructor_for__CAkURenderer::m_BusLimiters__);
}

// File Line: 73
// RVA: 0x15BDFD0
__int64 dynamic_initializer_for__CAkURenderer::m_AMLimiters__()
{
  return atexit(dynamic_atexit_destructor_for__CAkURenderer::m_AMLimiters__);
}

// File Line: 74
// RVA: 0x15BE000
__int64 dynamic_initializer_for__CAkURenderer::m_GlobalLimiter__()
{
  return atexit(dynamic_atexit_destructor_for__CAkURenderer::m_GlobalLimiter__);
}

// File Line: 86
// RVA: 0xA626A0
signed __int64 __fastcall CAkURenderer::Init()
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v0; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v1; // rcx
  signed __int64 result; // rax
  unsigned int v3; // edx
  signed __int64 v4; // rax

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
      v4 = (signed __int64)&v1[1];
      ++v3;
      v1->pNextListItem = v1 + 1;
      ++v1;
    }
    while ( v3 < CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems );
    *(_QWORD *)(v4 - 32) = 0i64;
    result = 1i64;
  }
  else
  {
    result = 52i64;
  }
  CAkURenderer::m_CtxNotifQueue.m_pFirst = 0i64;
  CAkURenderer::m_CtxNotifQueue.m_pLast = 0i64;
  if ( (_DWORD)result == 1 )
    result = CAkLEngine::Init();
  return result;
}

// File Line: 103
// RVA: 0xA633D0
void CAkURenderer::Term(void)
{
  __int64 v0; // rdx
  __int64 v1; // rcx
  _BOOL8 v2; // r8
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v3; // rdx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v4; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v5; // rax
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v6; // rcx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v7; // rbx

  CAkLEngine::Term();
  CAkURenderer::DestroyAllPBIs(v1, v0, v2);
  CAkURenderer::m_listCtxs.m_pFirst = 0i64;
  CAkURenderer::m_listCtxs.m_pLast = 0i64;
  CAkURenderer::m_listCtxs.m_ulNumListItems = 0;
  if ( CAkURenderer::m_CtxNotifQueue.m_ulMaxNumListItems )
  {
    v3 = CAkURenderer::m_CtxNotifQueue.m_pFree;
    while ( 1 )
    {
      v4 = CAkURenderer::m_CtxNotifQueue.m_pFirst;
      if ( !CAkURenderer::m_CtxNotifQueue.m_pFirst )
        break;
      CAkURenderer::m_CtxNotifQueue.m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst->pNextListItem;
      v5 = CAkURenderer::m_CtxNotifQueue.m_pLast;
      if ( v4 == CAkURenderer::m_CtxNotifQueue.m_pLast )
        v5 = 0i64;
      CAkURenderer::m_CtxNotifQueue.m_pLast = v5;
      if ( v4 < CAkURenderer::m_CtxNotifQueue.m_pvMemStart
        || v4 >= &CAkURenderer::m_CtxNotifQueue.m_pvMemStart[(unsigned __int64)CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v4);
        v3 = CAkURenderer::m_CtxNotifQueue.m_pFree;
        --CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
      }
      else
      {
        v4->pNextListItem = v3;
        --CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
        v3 = v4;
        CAkURenderer::m_CtxNotifQueue.m_pFree = v4;
      }
    }
    v6 = CAkURenderer::m_CtxNotifQueue.m_pvMemStart;
    if ( v3 )
    {
      do
      {
        v7 = v3->pNextListItem;
        if ( v3 < v6 || v3 >= &v6[CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v3);
          v6 = CAkURenderer::m_CtxNotifQueue.m_pvMemStart;
        }
        v3 = v7;
      }
      while ( v7 );
    }
    if ( v6 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v6);
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
PriorityInfoCurrent *__fastcall CAkURenderer::_CalcInitialPriority(PriorityInfoCurrent *result, CAkSoundBase *in_pSound, CAkRegisteredObj *in_pGameObj, float *out_fMaxRadius)
{
  PriorityInfoCurrent *v4; // rdi
  CAkSoundBase *v5; // rbx
  float *v6; // rsi
  CAkRegisteredObj *v7; // rbp
  CAkIndexableVtbl *v8; // rax
  bool v9; // zf
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  PriorityInfo resulta; // [rsp+40h] [rbp+8h]

  v4 = result;
  v5 = in_pSound;
  v6 = out_fMaxRadius;
  v7 = in_pGameObj;
  *out_fMaxRadius = 0.0;
  resulta = *CAkParameterNodeBase::GetPriority((CAkParameterNodeBase *)&in_pSound->vfptr, &resulta, in_pGameObj);
  v4->priorityInfo = resulta;
  v8 = v5->vfptr;
  v4->currentPriority.priority = resulta.priority;
  if ( ((unsigned __int8 (__fastcall *)(CAkSoundBase *, float *))v8[7].Release)(v5, v6) )
  {
    v9 = v4->priorityInfo.distanceOffset == 0.0;
    *v6 = v7->m_fScalingFactor * *v6;
    if ( v9 )
      return v4;
    v10 = CAkURenderer::GetMinDistance((AkSoundPositionRef *)&v7->m_PosKeep.m_aPos);
    if ( v10 >= *v6 )
      v11 = v4->priorityInfo.priority + v4->priorityInfo.distanceOffset;
    else
      v11 = (float)((float)(v10 / *v6) * v4->priorityInfo.distanceOffset) + v4->priorityInfo.priority;
    if ( v11 >= 0.0 )
    {
      v12 = FLOAT_100_0;
      if ( v11 > 100.0 )
      {
LABEL_11:
        v4->currentPriority.priority = v12;
        return v4;
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
  return v4;
}

// File Line: 144
// RVA: 0xA62590
float __fastcall CAkURenderer::GetMinDistance(AkSoundPositionRef *in_rPosRef)
{
  unsigned int v1; // ebp
  __int64 v2; // r14
  float v3; // xmm6_4
  AkSoundPositionRef *v4; // rdi
  signed __int64 v5; // rsi
  float v6; // xmm0_4
  __int64 i; // rbx
  unsigned __int16 v9; // ax
  AkSoundPosition *v10; // rdx
  float v11; // xmm0_4

  v1 = (unsigned __int8)in_rPosRef->m_uListenerMask;
  v2 = 0i64;
  v3 = FLOAT_1_0e10;
  v4 = in_rPosRef;
  if ( in_rPosRef->m_uListenerMask )
  {
    do
    {
      if ( v1 & 1 )
      {
        v5 = 144 * v2;
        if ( !(*((_BYTE *)v4 + 11) & 7) || v4->m_uNumPos )
        {
          for ( i = 0i64; ; i = (unsigned int)(i + 1) )
          {
            v9 = 1;
            if ( *((_BYTE *)v4 + 11) & 7 )
              v9 = v4->m_uNumPos;
            if ( (unsigned int)i >= v9 )
              break;
            v10 = &g_DefaultSoundPosition;
            if ( v4->m_aPos )
              v10 = v4->m_aPos;
            v11 = AkMath::Distance((AkVector *)((char *)&CAkListener::m_listeners + v5 + 24), &v10[i].Position)
                / *(float *)((char *)&CAkListener::m_listeners + v5 + 36);
            if ( v3 >= v11 )
              v3 = v11;
          }
        }
        else
        {
          v6 = AkMath::Distance(
                 (AkVector *)((char *)&CAkListener::m_listeners + v5 + 24),
                 &g_DefaultSoundPosition.Position)
             / *(float *)((char *)&CAkListener::m_listeners + v5 + 36);
          if ( v3 >= v6 )
            v3 = v6;
        }
      }
      v2 = (unsigned int)(v2 + 1);
      v1 >>= 1;
    }
    while ( v1 );
  }
  return v3;
}

// File Line: 177
// RVA: 0xA63060
signed __int64 __fastcall ResolveExternalSource(CAkSource **io_pSource, AkPBIParams *in_rPBIParams)
{
  AkExternalSourceArray *v2; // rbx
  CAkSource **v3; // rsi
  CAkSource *v5; // rdi
  unsigned int v6; // edx
  signed __int64 v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // er10
  int v10; // ebx
  unsigned int v11; // ecx
  __int128 v12; // [rsp+40h] [rbp-28h]
  unsigned int v13; // [rsp+50h] [rbp-18h]

  v2 = in_rPBIParams->userParams.m_CustomParam.pExternalSrcs;
  v3 = io_pSource;
  if ( !v2 )
    return 2i64;
  v5 = CAkSource::Clone(*io_pSource);
  *v3 = v5;
  if ( !v5 )
    return 52i64;
  v6 = v2->m_nCount;
  v7 = (signed __int64)v2->m_pSrcs;
  v8 = 0;
  if ( !v6 )
  {
LABEL_12:
    v10 = g_DefaultPoolId;
    CAkSource::~CAkSource(v5);
    AK::MemoryMgr::Free(v10, v5);
    return 2i64;
  }
  while ( 1 )
  {
    if ( v5->m_sSrcTypeInfo.mediaInfo.uFileID != *(_DWORD *)v7 )
      goto LABEL_11;
    v9 = (*(_DWORD *)(v7 + 4) << 16) + 1;
    if ( *(_QWORD *)(v7 + 8) )
      break;
    if ( *(_DWORD *)(v7 + 24) > 0u && *(_QWORD *)(v7 + 16) )
    {
      LODWORD(v12) = v5->m_sSrcTypeInfo.mediaInfo.sourceID;
      HIDWORD(v12) = *(_DWORD *)(v7 + 24);
      *(_QWORD *)((char *)&v12 + 4) = 0xFFFFFFFFi64;
      v13 = v13 & 0xFFFFF88C | 0x18C;
      CAkSource::SetSource(v5, v9, *(void **)(v7 + 16), (AkMediaInformation *)&v12);
      return 1i64;
    }
    if ( *(_DWORD *)(v7 + 28) )
    {
      v11 = v5->m_sSrcTypeInfo.mediaInfo.sourceID;
      *((_QWORD *)&v12 + 1) = 0i64;
      LODWORD(v12) = v11;
      *(_QWORD *)((char *)&v12 + 4) = *(unsigned int *)(v7 + 28);
      v13 = v13 & 0xFFFFF804 | 0x104;
      CAkSource::SetSource(v5, v9, (AkMediaInformation *)&v12);
      return 1i64;
    }
LABEL_11:
    ++v8;
    v7 += 32i64;
    if ( v8 >= v6 )
      goto LABEL_12;
  }
  CAkSource::SetSource(
    v5,
    v5->m_sSrcTypeInfo.mediaInfo.sourceID,
    v9,
    *(const wchar_t **)(v7 + 8),
    0xFFFFFFFF,
    (*((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) >> 9) & 1,
    1);
  return 1i64;
}

// File Line: 236
// RVA: 0xA62690
bool __fastcall CAkURenderer::GetVirtualBehaviorAction(AkBelowThresholdBehavior in_belowThresholdBehavior)
{
  return in_belowThresholdBehavior != 1;
}

// File Line: 269
// RVA: 0xA62BE0
AKRESULT __fastcall CAkURenderer::Play(CAkSoundBase *in_pSound, CAkSource *in_pSource, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v3; // rdi
  AMD_HD3D *v4; // r15
  AKRESULT v5; // er12
  float v6; // xmm6_4
  AKRESULT v7; // er13
  __int64 v8; // rax
  __int64 v9; // rax
  int v10; // eax
  bool v11; // si
  CAkSource *v12; // r8
  __int64 v13; // rcx
  __int64 v14; // rax
  CAkPBIAware *v15; // rcx
  CAkIndexableVtbl *v16; // r10
  __int64 v17; // rax
  CAkPBI *v18; // rsi
  __int64 v19; // r8
  int v20; // eax
  __int64 v21; // rdx
  AKRESULT v22; // eax
  int v23; // ebx
  __int64 v24; // rax
  __int64 v25; // rax
  unsigned __int64 v26; // r8
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  unsigned __int64 v30; // r8
  PriorityInfoCurrent result; // [rsp+8h] [rbp-59h]
  __int64 v32; // [rsp+18h] [rbp-49h]
  PriorityInfoCurrent *v33; // [rsp+20h] [rbp-41h]
  __int64 v34; // [rsp+28h] [rbp-39h]
  __int64 v35; // [rsp+30h] [rbp-31h]
  __int64 v36; // [rsp+38h] [rbp-29h]
  __int64 v37; // [rsp+40h] [rbp-21h]
  int v38; // [rsp+48h] [rbp-19h]
  __int16 v39; // [rsp+4Ch] [rbp-15h]
  int v40; // [rsp+50h] [rbp-11h]
  __int64 v41; // [rsp+58h] [rbp-9h]
  __int64 v42; // [rsp+60h] [rbp-1h]
  __int64 v43; // [rsp+68h] [rbp+7h]
  int v44; // [rsp+70h] [rbp+Fh]
  __int16 v45; // [rsp+74h] [rbp+13h]
  CAkSource *io_pSource; // [rsp+D0h] [rbp+6Fh]
  float out_fMaxRadius; // [rsp+D8h] [rbp+77h]
  AkVirtualQueueBehavior out_Behavior; // [rsp+E0h] [rbp+7Fh]
  __int64 v49; // [rsp+110h] [rbp+AFh]

  v3 = in_rPBIParams;
  v4 = (AMD_HD3D *)in_pSound;
  v5 = 2;
  CAkURenderer::_CalcInitialPriority((PriorityInfoCurrent *)&v37, in_pSound, in_rPBIParams->pGameObj, (float *)&v49);
  v6 = result.currentPriority.priority;
  if ( !CAkURenderer::ValidateMemoryLimit(result.currentPriority.priority)
    || (v7 = CAkURenderer::ValidateMaximumNumberVoiceLimit(v6), v7 == 2) )
  {
    v5 = 3;
LABEL_3:
    v30 = v3->pGameObj->m_GameObjID;
    v33 = (PriorityInfoCurrent *)&v3->playHistory;
    _(v4);
    return v5;
  }
  v36 = 0i64;
  v37 = 0i64;
  v8 = (__int64)v3->pGameObj;
  *(float *)&v34 = result.currentPriority.priority;
  v35 = v8;
  v9 = *(_QWORD *)&v4->mEnableStereo;
  v38 = 3;
  v39 = 256;
  v10 = (*(__int64 (__fastcall **)(AMD_HD3D *, __int64 *))(v9 + 272))(v4, &v34);
  v11 = v10 != 2;
  if ( v10 == 80 || v7 == 80 )
  {
    v11 = 1;
    if ( CAkParameterNode::GetVirtualBehavior((CAkParameterNode *)v4, &out_Behavior) == 1 )
      v11 = 0;
  }
  if ( !v11 )
  {
    v42 = 0i64;
    v43 = 0i64;
    v28 = (__int64)v3->pGameObj;
    v40 = 0;
    v41 = v28;
    v29 = *(_QWORD *)&v4->mEnableStereo;
    v5 = 3;
    v44 = 3;
    v45 = 256;
    (*(void (__fastcall **)(AMD_HD3D *, int *))(v29 + 280))(v4, &v40);
    goto LABEL_3;
  }
  v12 = io_pSource;
  if ( (io_pSource->m_sSrcTypeInfo.dwID & 0xFFFF0000) == 0x80000 )
  {
    v5 = ResolveExternalSource(&io_pSource, v3);
    if ( v5 != 1 )
    {
      v13 = (__int64)v3->pGameObj;
      v42 = 0i64;
      v43 = 0i64;
      v14 = *(_QWORD *)&v4->mEnableStereo;
      v40 = 0;
      v41 = v13;
      v44 = 3;
      v45 = 256;
      (*(void (__fastcall **)(AMD_HD3D *, int *))(v14 + 280))(v4, &v40);
      return v5;
    }
    v12 = io_pSource;
  }
  v15 = v3->pInstigator;
  v16 = v15->vfptr;
  v35 = v37;
  v34 = v36;
  v33 = &result;
  v17 = ((__int64 (__fastcall *)(CAkPBIAware *, AMD_HD3D *, CAkSource *, AkPBIParams *, PriorityInfoCurrent *, __int64, __int64))v16[1].__vecDelDtor)(
          v15,
          v4,
          v12,
          v3,
          &result,
          v36,
          v37);
  v18 = (CAkPBI *)v17;
  if ( !v17 )
  {
    v42 = 0i64;
    v43 = 0i64;
    v24 = (__int64)v3->pGameObj;
    v40 = 0;
    v41 = v24;
    v25 = *(_QWORD *)&v4->mEnableStereo;
    v44 = 3;
    v45 = 256;
    (*(void (__fastcall **)(AMD_HD3D *, int *))(v25 + 280))(v4, &v40);
LABEL_22:
    v26 = v3->pGameObj->m_GameObjID;
    v27 = (unsigned __int8)-v3->bIsFirst;
    v33 = (PriorityInfoCurrent *)&v3->playHistory;
    _(v4);
    if ( v5 != 3 )
      return v5;
    goto LABEL_3;
  }
  if ( v3->eType )
  {
    v20 = (*(__int64 (__fastcall **)(__int64, AkPathInfo *))(*(_QWORD *)v17 + 16i64))(
            v17,
            v3->pContinuousParams->pPathInfo);
  }
  else
  {
    v19 = *(_QWORD *)v17;
    v32 = 0i64;
    LODWORD(v33) = 0;
    v20 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v19 + 16))(v17, &v32);
  }
  if ( v20 != 1
    || (v18->m_fMaxDistance = out_fMaxRadius,
        v18->m_iFrameOffset = v3->uFrameOffset,
        v22 = CAkURenderer::Play(v18, v3->pTransitionParameters, v3->ePlaybackState),
        v22 != 1) )
  {
    LOBYTE(v21) = 1;
    ((void (__fastcall *)(CAkPBI *, __int64))v18->vfptr[1].~CAkTransportAware)(v18, v21);
    v23 = g_DefaultPoolId;
    ((void (__fastcall *)(CAkPBI *, _QWORD))v18->vfptr->~CAkTransportAware)(v18, 0i64);
    AK::MemoryMgr::Free(v23, v18);
    goto LABEL_22;
  }
  return v22;
}

// File Line: 455
// RVA: 0xA62B60
AKRESULT __fastcall CAkURenderer::Play(CAkPBI *in_pContext, TransParams *in_rTparameters, AkPlaybackState in_ePlaybackState)
{
  AkPlaybackState v3; // ebx
  TransParams *v4; // rdi
  CAkPBI *v5; // rsi
  bool v6; // r8
  AKRESULT result; // eax

  v3 = in_ePlaybackState;
  v4 = in_rTparameters;
  v5 = in_pContext;
  CAkPBI::_InitPlay(in_pContext);
  v6 = 0;
  if ( v3 == 1 )
    v6 = 1;
  result = CAkPBI::_Play(v5, v4, v6, 0);
  if ( result == 1 )
  {
    v5->pNextItem = 0i64;
    if ( CAkURenderer::m_listCtxs.m_pLast )
      CAkURenderer::m_listCtxs.m_pLast->pNextItem = v5;
    else
      CAkURenderer::m_listCtxs.m_pFirst = v5;
    ++CAkURenderer::m_listCtxs.m_ulNumListItems;
    CAkURenderer::m_listCtxs.m_pLast = v5;
  }
  return result;
}

// File Line: 495
// RVA: 0xA632C0
signed __int64 __fastcall CAkURenderer::Stop(CAkSoundBase *in_pSound, CAkRegisteredObj *in_pGameObj, TransParams *in_rTparameters, unsigned int in_PlayingID)
{
  CAkPBI *v4; // rbx
  unsigned int v5; // esi
  TransParams *v6; // r14
  CAkRegisteredObj *v7; // rdi
  CAkSoundBase *v8; // rbp

  v4 = CAkURenderer::m_listCtxs.m_pFirst;
  v5 = in_PlayingID;
  v6 = in_rTparameters;
  v7 = in_pGameObj;
  v8 = in_pSound;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      if ( v4->m_pSound == v8 && (!v7 || v4->m_pGameObj == v7) && (!v5 || v4->m_UserParams.m_PlayingID == v5) )
        CAkPBI::_Stop(v4, v6, 1);
      v4 = v4->pNextItem;
    }
    while ( v4 );
  }
  return 1i64;
}

// File Line: 524
// RVA: 0xA62940
signed __int64 __fastcall CAkURenderer::Pause(CAkSoundBase *in_pSound, CAkRegisteredObj *in_pGameObj, TransParams *in_rTparameters, unsigned int in_PlayingID)
{
  CAkPBI *v4; // rbx
  unsigned int v5; // esi
  TransParams *v6; // r14
  CAkRegisteredObj *v7; // rdi
  CAkSoundBase *v8; // rbp

  v4 = CAkURenderer::m_listCtxs.m_pFirst;
  v5 = in_PlayingID;
  v6 = in_rTparameters;
  v7 = in_pGameObj;
  v8 = in_pSound;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      if ( v4->m_pSound == v8 && (!v7 || v4->m_pGameObj == v7) && (!v5 || v4->m_UserParams.m_PlayingID == v5) )
        CAkPBI::_Pause(v4, v6);
      v4 = v4->pNextItem;
    }
    while ( v4 );
  }
  return 1i64;
}

// File Line: 554
// RVA: 0xA63230
signed __int64 __fastcall CAkURenderer::Resume(CAkSoundBase *in_pSound, CAkRegisteredObj *in_pGameObj, TransParams *in_rTparameters, bool in_bIsMasterResume, unsigned int in_PlayingID)
{
  CAkPBI *v5; // rbx
  bool v6; // r14
  TransParams *v7; // r15
  CAkRegisteredObj *v8; // rsi
  CAkSoundBase *v9; // rbp

  v5 = CAkURenderer::m_listCtxs.m_pFirst;
  v6 = in_bIsMasterResume;
  v7 = in_rTparameters;
  v8 = in_pGameObj;
  v9 = in_pSound;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      if ( v5->m_pSound == v9
        && (!v8 || v5->m_pGameObj == v8)
        && (!in_PlayingID || v5->m_UserParams.m_PlayingID == in_PlayingID) )
      {
        CAkPBI::_Resume(v5, v7, v6);
      }
      v5 = v5->pNextItem;
    }
    while ( v5 );
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
  int v2; // er12
  CAkPBI **v3; // rbx
  CAkPBI *v4; // r15
  CAkPBI **v5; // rdi
  unsigned __int16 v6; // bp
  signed int v7; // er14
  float v8; // xmm8_4
  CAkPBI *v9; // rsi
  char v10; // al
  float v11; // xmm6_4
  AkBelowThresholdBehavior v12; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+80h] [rbp+8h]

  v1 = CAkURenderer::m_uNumVirtualizedSounds-- - 1;
  if ( in_bAllowKick )
  {
    v2 = CAkURenderer::m_GlobalLimiter.m_u16LimiterMax;
    if ( CAkURenderer::m_listCtxs.m_ulNumListItems - v1 > CAkURenderer::m_GlobalLimiter.m_u16LimiterMax )
    {
      v3 = CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems;
      v4 = 0i64;
      v5 = &CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems[CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_uLength];
      v6 = 0;
      v7 = 2;
      v8 = FLOAT_101_0;
      if ( CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems != v5 )
      {
        do
        {
          v9 = *v3;
          if ( !(*((_BYTE *)*v3 + 374) & 1) )
          {
            v10 = *((_BYTE *)v9 + 375);
            if ( !(v10 & 0x10) && !(v10 & 0x40) )
            {
              v11 = v9->m_PriorityInfoCurrent.currentPriority.priority;
              ++v6;
              if ( v11 <= 101.0 )
              {
                v12 = CAkPBI::GetVirtualBehavior(*v3, &out_Behavior);
                if ( v12 )
                {
                  v7 = v12;
                  v4 = v9;
                  v8 = v11;
                }
              }
            }
          }
          ++v3;
        }
        while ( v3 != v5 );
      }
      if ( v6 + 1 > v2 && v8 <= 101.0 && v8 != 101.0 && v4 && v7 == 1 )
        CAkPBI::Kick(v4, KickFrom_OverGlobalLimit);
    }
  }
}

// File Line: 750
// RVA: 0xA62790
signed __int64 __fastcall CAkURenderer::Kick(CAkLimiter *in_pLimiter, unsigned __int16 in_uMaxInstances, float in_fPriority, CAkRegisteredObj *in_pGameObj, bool in_bKickNewest, bool in_bUseVirtualBehavior, CAkParameterNodeBase **out_pKicked, KickFrom in_eReason)
{
  CAkRegisteredObj *v8; // r12
  bool v10; // r8
  CAkPBI **v11; // rbx
  CAkPBI *v12; // r14
  float v13; // xmm8_4
  CAkPBI **v14; // rdi
  unsigned int v15; // ebp
  unsigned __int16 v16; // r13
  signed int v17; // er15
  CAkPBI *v18; // rsi
  char v19; // al
  float v20; // xmm6_4
  AkBelowThresholdBehavior v21; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+90h] [rbp+8h]
  unsigned __int16 v23; // [rsp+98h] [rbp+10h]

  v23 = in_uMaxInstances;
  v8 = in_pGameObj;
  if ( !in_pLimiter )
    return 1i64;
  v10 = in_bUseVirtualBehavior;
  v11 = in_pLimiter->m_sortedPBIList.m_pItems;
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
      v18 = *v11;
      if ( v8 && v18->m_pGameObj != v8 )
        goto LABEL_14;
      if ( *((_BYTE *)v18 + 374) & 1 )
        goto LABEL_14;
      v19 = *((_BYTE *)v18 + 375);
      if ( v19 & 0x10 )
        goto LABEL_14;
      if ( v19 & 0x40 )
        goto LABEL_14;
      v20 = v18->m_PriorityInfoCurrent.currentPriority.priority;
      ++v16;
      if ( v20 > in_fPriority )
        goto LABEL_14;
      if ( !v10 )
        goto LABEL_13;
      v21 = CAkPBI::GetVirtualBehavior(*v11, &out_Behavior);
      if ( v21 )
        break;
LABEL_14:
      v10 = in_bUseVirtualBehavior;
      ++v11;
      if ( v11 == v14 )
        goto LABEL_15;
    }
    v17 = v21;
LABEL_13:
    v12 = v18;
    v13 = v20;
    goto LABEL_14;
  }
LABEL_15:
  if ( v16 + 1 <= v23 )
    return 1i64;
  if ( in_fPriority < v13 || in_bKickNewest && in_fPriority == v13 || !v12 )
  {
    if ( v10 )
      v15 = 80;
  }
  else
  {
    *out_pKicked = (CAkParameterNodeBase *)&v12->m_pSound->vfptr;
    if ( !v10 || v17 == 1 )
      CAkPBI::Kick(v12, in_eReason);
    v15 = 1;
  }
  return v15;
}

// File Line: 875
// RVA: 0xA636E0
char __fastcall CAkURenderer::ValidateMemoryLimit(float in_fPriority)
{
  float v1; // xmm7_4
  float v2; // xmm8_4
  float v3; // xmm7_4
  CAkPBI *v4; // rax
  float v5; // xmm1_4
  CAkPBI *v6; // r8
  char v7; // cl
  float v8; // xmm0_4
  AK::MemoryMgr::PoolMemInfo out_memInfo; // [rsp+58h] [rbp+10h]

  v1 = unk_14249E974;
  v2 = in_fPriority;
  if ( unk_14249E974 >= 1.0
    || (AK::MemoryMgr::GetPoolMemoryUsed(g_DefaultPoolId, &out_memInfo), !out_memInfo.uReserved)
    || (float)((float)(signed int)out_memInfo.uUsed / (float)(signed int)out_memInfo.uReserved) <= v1 )
  {
    v3 = g_PDSettings.fLEngineDefaultPoolRatioThreshold;
    if ( g_PDSettings.fLEngineDefaultPoolRatioThreshold >= 1.0 )
      return 1;
    AK::MemoryMgr::GetPoolMemoryUsed(g_LEngineDefaultPoolId, &out_memInfo);
    if ( !out_memInfo.uReserved
      || (float)((float)(signed int)out_memInfo.uUsed / (float)(signed int)out_memInfo.uReserved) <= v3 )
    {
      return 1;
    }
  }
  v4 = CAkURenderer::m_listCtxs.m_pFirst;
  v5 = FLOAT_101_0;
  v6 = 0i64;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      if ( !(*((_BYTE *)v4 + 374) & 1) )
      {
        v7 = *((_BYTE *)v4 + 375);
        if ( !(v7 & 0x10) && !(v7 & 0x40) )
        {
          v8 = v4->m_PriorityInfoCurrent.currentPriority.priority;
          if ( v8 < v5 || v8 == v5 )
          {
            v6 = v4;
            v5 = v4->m_PriorityInfoCurrent.currentPriority.priority;
          }
        }
      }
      v4 = v4->pNextItem;
    }
    while ( v4 );
  }
  if ( v2 < v5 || v2 == v5 || !v6 )
    return 0;
  CAkPBI::Kick(v6, KickFrom_OverMemoryLimit);
  return 1;
}

// File Line: 904
// RVA: 0xA63580
signed __int64 __fastcall CAkURenderer::ValidateMaximumNumberVoiceLimit(float in_fPriority)
{
  int v1; // er12
  CAkPBI **v2; // rbx
  CAkPBI *v3; // r15
  CAkPBI **v4; // rdi
  float v5; // xmm8_4
  unsigned __int16 v6; // bp
  signed int v7; // er14
  CAkPBI *v8; // rsi
  char v9; // al
  float v10; // xmm6_4
  AkBelowThresholdBehavior v11; // eax
  AkVirtualQueueBehavior out_Behavior; // [rsp+88h] [rbp+10h]

  v1 = CAkURenderer::m_GlobalLimiter.m_u16LimiterMax;
  if ( CAkURenderer::m_listCtxs.m_ulNumListItems - CAkURenderer::m_uNumVirtualizedSounds + 1 <= CAkURenderer::m_GlobalLimiter.m_u16LimiterMax )
    return 1i64;
  v2 = CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems;
  v3 = 0i64;
  v4 = &CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems[CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_uLength];
  v5 = FLOAT_101_0;
  v6 = 0;
  v7 = 2;
  if ( CAkURenderer::m_GlobalLimiter.m_sortedPBIList.m_pItems != v4 )
  {
    do
    {
      v8 = *v2;
      if ( !(*((_BYTE *)*v2 + 374) & 1) )
      {
        v9 = *((_BYTE *)v8 + 375);
        if ( !(v9 & 0x10) && !(v9 & 0x40) )
        {
          v10 = v8->m_PriorityInfoCurrent.currentPriority.priority;
          ++v6;
          if ( v10 <= in_fPriority )
          {
            v11 = CAkPBI::GetVirtualBehavior(*v2, &out_Behavior);
            if ( v11 )
            {
              v7 = v11;
              v3 = v8;
              v5 = v10;
            }
          }
        }
      }
      ++v2;
    }
    while ( v2 != v4 );
  }
  if ( v6 + 1 <= v1 )
    return 1i64;
  if ( in_fPriority >= v5 && in_fPriority != v5 && v3 )
  {
    if ( v7 == 1 )
      CAkPBI::Kick(v3, KickFrom_OverGlobalLimit);
    return 1i64;
  }
  return 80i64;
}

// File Line: 933
// RVA: 0xA63530
AKRESULT __fastcall CAkURenderer::ValidateLimits(float in_fPriority, AkMonitorData::NotificationReason *out_eReasonOfFailure)
{
  AkMonitorData::NotificationReason *v2; // rbx
  AKRESULT result; // eax

  v2 = out_eReasonOfFailure;
  if ( CAkURenderer::ValidateMemoryLimit(in_fPriority) )
  {
    *v2 = 33;
    result = CAkURenderer::ValidateMaximumNumberVoiceLimit(in_fPriority);
  }
  else
  {
    *v2 = 34;
    result = 2;
  }
  return result;
}

// File Line: 946
// RVA: 0xA624B0
void __fastcall CAkURenderer::EnqueueContextNotif(CAkPBI *in_pPBI, AkCtxState in_eState, AkCtxDestroyReason in_eDestroyReason, float in_fEstimatedTime)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v4; // r9
  AkCtxDestroyReason v5; // ebx
  AkCtxState v6; // edi
  CAkPBI *v7; // rsi
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkURenderer::ContextNotif *v9; // rax

  v4 = CAkURenderer::m_CtxNotifQueue.m_pFree;
  v5 = in_eDestroyReason;
  v6 = in_eState;
  v7 = in_pPBI;
  if ( !CAkURenderer::m_CtxNotifQueue.m_pFree )
  {
    if ( CAkURenderer::m_CtxNotifQueue.m_ulNumListItems >= CAkURenderer::m_CtxNotifQueue.m_ulMaxNumListItems
      || (v8 = (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(LODWORD(CAkURenderer::m_CtxNotifQueue.m_pFree) + 32)),
          (v4 = v8) == 0i64) )
    {
LABEL_9:
      CAkURenderer::PerformContextNotif();
      v9 = CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::AddLast(&CAkURenderer::m_CtxNotifQueue);
      goto LABEL_10;
    }
    v8->pNextListItem = CAkURenderer::m_CtxNotifQueue.m_pFree;
    CAkURenderer::m_CtxNotifQueue.m_pFree = v8;
  }
  if ( CAkURenderer::m_CtxNotifQueue.m_pLast )
  {
    CAkURenderer::m_CtxNotifQueue.m_pLast->pNextListItem = v4;
    v4 = CAkURenderer::m_CtxNotifQueue.m_pFree;
  }
  else
  {
    CAkURenderer::m_CtxNotifQueue.m_pFirst = v4;
  }
  CAkURenderer::m_CtxNotifQueue.m_pLast = v4;
  CAkURenderer::m_CtxNotifQueue.m_pFree = v4->pNextListItem;
  v4->pNextListItem = 0i64;
  ++CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
  v9 = &CAkURenderer::m_CtxNotifQueue.m_pLast->Item;
  if ( CAkURenderer::m_CtxNotifQueue.m_pLast == (CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
    goto LABEL_9;
LABEL_10:
  v9->fEstimatedLength = in_fEstimatedTime;
  v9->pPBI = v7;
  v9->DestroyReason = v5;
  v9->state = v6;
}

// File Line: 971
// RVA: 0xA629D0
void CAkURenderer::PerformContextNotif(void)
{
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v0; // rbx
  CAkPBI *v1; // rdx
  CAkPBI *v2; // rcx
  CAkPBI *v3; // rax
  CAkPBI *v4; // rdi
  int v5; // ebx
  CAkList2<CAkURenderer::ContextNotif,CAkURenderer::ContextNotif const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  unsigned int v7; // eax

  if ( CAkURenderer::m_CtxNotifQueue.m_ulNumListItems )
  {
    v0 = CAkURenderer::m_CtxNotifQueue.m_pFirst;
    do
    {
      CAkPBI::ProcessContextNotif(v0->Item.pPBI, v0->Item.state, v0->Item.DestroyReason, v0->Item.fEstimatedLength);
      if ( v0->Item.state == 4 )
      {
        v1 = 0i64;
        v2 = CAkURenderer::m_listCtxs.m_pFirst;
        if ( CAkURenderer::m_listCtxs.m_pFirst )
        {
          while ( v2 != v0->Item.pPBI )
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
            v3 = CAkURenderer::m_listCtxs.m_pLast;
            if ( v2 == CAkURenderer::m_listCtxs.m_pLast )
              v3 = v1;
            --CAkURenderer::m_listCtxs.m_ulNumListItems;
            CAkURenderer::m_listCtxs.m_pLast = v3;
          }
        }
LABEL_15:
        v4 = v0->Item.pPBI;
        CAkLEngineCmds::DequeuePBI(v0->Item.pPBI);
        ((void (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr[1].~CAkTransportAware)(v4, 0i64);
        v5 = g_DefaultPoolId;
        ((void (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr->~CAkTransportAware)(v4, 0i64);
        AK::MemoryMgr::Free(v5, v4);
      }
      v0 = CAkURenderer::m_CtxNotifQueue.m_pFirst;
      if ( CAkURenderer::m_CtxNotifQueue.m_pFirst )
      {
        CAkURenderer::m_CtxNotifQueue.m_pFirst = CAkURenderer::m_CtxNotifQueue.m_pFirst->pNextListItem;
        v6 = CAkURenderer::m_CtxNotifQueue.m_pLast;
        if ( v0 == CAkURenderer::m_CtxNotifQueue.m_pLast )
          v6 = 0i64;
        CAkURenderer::m_CtxNotifQueue.m_pLast = v6;
        if ( v0 < CAkURenderer::m_CtxNotifQueue.m_pvMemStart
          || v0 >= &CAkURenderer::m_CtxNotifQueue.m_pvMemStart[(unsigned __int64)CAkURenderer::m_CtxNotifQueue.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v0);
        }
        else
        {
          v0->pNextListItem = CAkURenderer::m_CtxNotifQueue.m_pFree;
          CAkURenderer::m_CtxNotifQueue.m_pFree = v0;
        }
        v0 = CAkURenderer::m_CtxNotifQueue.m_pFirst;
        v7 = CAkURenderer::m_CtxNotifQueue.m_ulNumListItems-- - 1;
      }
      else
      {
        v7 = CAkURenderer::m_CtxNotifQueue.m_ulNumListItems;
      }
    }
    while ( v7 );
  }
}

// File Line: 1024
// RVA: 0xA623C0
void __fastcall CAkURenderer::DestroyAllPBIs(__int64 a1, __int64 a2, _BOOL8 a3)
{
  CAkPBI *v3; // rax
  CAkPBI *v4; // rdi
  CAkPBI *v5; // rax
  int v6; // ebx

  v3 = CAkURenderer::m_listCtxs.m_pFirst;
  v4 = CAkURenderer::m_listCtxs.m_pFirst;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    if ( !CAkURenderer::m_listCtxs.m_pFirst )
      goto LABEL_7;
    do
    {
      v5 = v3->pNextItem;
      if ( v5 )
      {
        CAkURenderer::m_listCtxs.m_pFirst = v5;
      }
      else
      {
        CAkURenderer::m_listCtxs.m_pFirst = 0i64;
        CAkURenderer::m_listCtxs.m_pLast = 0i64;
      }
      --CAkURenderer::m_listCtxs.m_ulNumListItems;
LABEL_7:
      LOBYTE(a3) = 1;
      v4->vfptr->_Stop((CAkTransportAware *)&v4->vfptr, 0i64, a3, 0);
      CAkLEngineCmds::DequeuePBI(v4);
      ((void (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr[1].~CAkTransportAware)(v4, 0i64);
      v6 = g_DefaultPoolId;
      ((void (__fastcall *)(CAkPBI *, _QWORD))v4->vfptr->~CAkTransportAware)(v4, 0i64);
      AK::MemoryMgr::Free(v6, v4);
      v3 = CAkURenderer::m_listCtxs.m_pFirst;
      v4 = CAkURenderer::m_listCtxs.m_pFirst;
    }
    while ( CAkURenderer::m_listCtxs.m_pFirst );
  }
}

// File Line: 1034
// RVA: 0xA63350
void __fastcall CAkURenderer::StopAllPBIs(CAkUsageSlot *in_pUsageSlot)
{
  CAkPBI *v1; // rbx
  CAkUsageSlot *v2; // rdi
  TransParams in_transParams; // [rsp+38h] [rbp+10h]

  v1 = CAkURenderer::m_listCtxs.m_pFirst;
  v2 = in_pUsageSlot;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      if ( CAkPBI::IsUsingThisSlot(v1, v2) )
      {
        in_transParams = 0i64;
        CAkPBI::_Stop(v1, &in_transParams, 1);
        CAkAudioMgr::StopPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v1->m_pSound->vfptr, 0i64, 0);
      }
      v1 = v1->pNextItem;
    }
    while ( v1 );
  }
  CAkLEngine::StopMixBussesUsingThisSlot(v2);
}

// File Line: 1153
// RVA: 0xA62740
void CAkURenderer::InvalidateAllMotionPBIs(void)
{
  CAkPBI *v0; // rbx
  char v1; // al

  v0 = CAkURenderer::m_listCtxs.m_pFirst;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      v1 = *((_BYTE *)v0 + 371);
      if ( (v1 & 3) == 1 && (v1 & 0xC) == 4 )
        CAkPBI::InvalidateFeedbackParameters(v0);
      v0 = v0->pNextItem;
    }
    while ( v0 );
  }
}

// File Line: 1163
// RVA: 0xA621C0
void __fastcall CAkURenderer::AddBusLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // rax

  v1 = CAkURenderer::m_BusLimiters.m_pFirst;
  if ( CAkURenderer::m_BusLimiters.m_pFirst )
  {
    in_pLimiter->pNextLightItem = CAkURenderer::m_BusLimiters.m_pFirst;
    CAkURenderer::m_BusLimiters.m_pFirst = in_pLimiter;
  }
  else
  {
    CAkURenderer::m_BusLimiters.m_pFirst = in_pLimiter;
    in_pLimiter->pNextLightItem = v1;
  }
}

// File Line: 1168
// RVA: 0xA63010
void __fastcall CAkURenderer::RemoveBusLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // r8
  CAkLimiter *v2; // rdx

  v1 = 0i64;
  v2 = CAkURenderer::m_BusLimiters.m_pFirst;
  if ( CAkURenderer::m_BusLimiters.m_pFirst )
  {
    while ( v2 != in_pLimiter )
    {
      v1 = v2;
      v2 = v2->pNextLightItem;
      if ( !v2 )
        return;
    }
    if ( v2 )
    {
      if ( v2 == CAkURenderer::m_BusLimiters.m_pFirst )
        CAkURenderer::m_BusLimiters.m_pFirst = v2->pNextLightItem;
      else
        v1->pNextLightItem = v2->pNextLightItem;
    }
  }
}

// File Line: 1173
// RVA: 0xA62190
void __fastcall CAkURenderer::AddAMLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // rax

  v1 = CAkURenderer::m_AMLimiters.m_pFirst;
  if ( CAkURenderer::m_AMLimiters.m_pFirst )
  {
    in_pLimiter->pNextLightItem = CAkURenderer::m_AMLimiters.m_pFirst;
    CAkURenderer::m_AMLimiters.m_pFirst = in_pLimiter;
  }
  else
  {
    CAkURenderer::m_AMLimiters.m_pFirst = in_pLimiter;
    in_pLimiter->pNextLightItem = v1;
  }
}

// File Line: 1178
// RVA: 0xA62FC0
void __fastcall CAkURenderer::RemoveAMLimiter(CAkLimiter *in_pLimiter)
{
  CAkLimiter *v1; // r8
  CAkLimiter *v2; // rdx

  v1 = 0i64;
  v2 = CAkURenderer::m_AMLimiters.m_pFirst;
  if ( CAkURenderer::m_AMLimiters.m_pFirst )
  {
    while ( v2 != in_pLimiter )
    {
      v1 = v2;
      v2 = v2->pNextLightItem;
      if ( !v2 )
        return;
    }
    if ( v2 )
    {
      if ( v2 == CAkURenderer::m_AMLimiters.m_pFirst )
        CAkURenderer::m_AMLimiters.m_pFirst = v2->pNextLightItem;
      else
        v1->pNextLightItem = v2->pNextLightItem;
    }
  }
}

// File Line: 1183
// RVA: 0xA62F30
void CAkURenderer::ProcessLimiters(void)
{
  CAkPBI *v0; // rax
  CAkLimiter *v1; // rbx
  CAkLimiter *v2; // rbx

  v0 = CAkURenderer::m_listCtxs.m_pFirst;
  if ( CAkURenderer::m_listCtxs.m_pFirst )
  {
    do
    {
      *((_BYTE *)v0 + 375) = *((_BYTE *)v0 + 375) & 0xCF | 2 * (*((_BYTE *)v0 + 375) & 0x10);
      v0 = v0->pNextItem;
    }
    while ( v0 );
  }
  CAkLimiter::UpdateFlags(&CAkURenderer::m_GlobalLimiter);
  v1 = CAkURenderer::m_BusLimiters.m_pFirst;
  if ( CAkURenderer::m_BusLimiters.m_pFirst )
  {
    do
    {
      CAkLimiter::UpdateFlags(v1);
      v1 = v1->pNextLightItem;
    }
    while ( v1 );
  }
  v2 = CAkURenderer::m_AMLimiters.m_pFirst;
  if ( CAkURenderer::m_AMLimiters.m_pFirst )
  {
    do
    {
      CAkLimiter::UpdateFlags(v2);
      v2 = v2->pNextLightItem;
    }
    while ( v2 );
  }
}

