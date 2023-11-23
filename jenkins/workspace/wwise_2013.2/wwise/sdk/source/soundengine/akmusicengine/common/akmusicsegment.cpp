// File Line: 54
// RVA: 0xAB0750
CAkMusicSegment *__fastcall CAkMusicSegment::Create(unsigned int in_ulID)
{
  CAkMusicSegment *result; // rax
  CAkMusicSegment *v3; // rbx
  unsigned int v4; // eax
  int v5; // ecx
  bool v6; // al

  result = (CAkMusicSegment *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  v3 = result;
  if ( result )
  {
    CAkMusicNode::CAkMusicNode(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkMusicSegment::`vftable;
    v3->m_markers.m_pItems = 0i64;
    *(_QWORD *)&v3->m_markers.m_uLength = 0i64;
    v3->m_uDuration = 0;
    v4 = v3->vfptr[3].Release(v3);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) &= ~2u;
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 68
// RVA: 0xAB1420
__int64 __fastcall CAkMusicSegment::SetInitialValues(CAkMusicSegment *this, char *in_pData, unsigned int in_ulDataSize)
{
  __int64 result; // rax
  AKRESULT v5; // ebx
  char *v6; // rcx
  double v7; // xmm0_8
  double v8; // xmm1_8
  double v9; // xmm0_8
  char *v10; // rcx
  __int64 v11; // rsi
  AkMusicMarkerWwise *v12; // rax
  AkMusicMarkerWwise *v13; // r15
  unsigned int v14; // edi
  char **p_pszName; // rbx
  int v16; // ecx
  double v17; // xmm0_8
  char *v18; // rax
  __int64 v19; // rcx
  char *v20; // rbp
  __int64 v21; // r14
  char *v22; // rax
  char *io_rpData; // [rsp+68h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+70h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  result = CAkMusicNode::SetMusicNodeParams(this, &io_rpData, &io_rulDataSize, 0);
  v5 = (int)result;
  if ( (_DWORD)result != 1 )
    return result;
  v6 = io_rpData + 8;
  v7 = *(double *)io_rpData;
  io_rpData += 8;
  v8 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * v7 * 0.001;
  if ( v8 <= 0.0 )
    v9 = DOUBLE_N0_5;
  else
    v9 = DOUBLE_0_5;
  v10 = v6 + 4;
  this->m_uDuration = (int)(v9 + v8);
  v11 = *((unsigned int *)v10 - 1);
  io_rpData = v10;
  if ( !(_DWORD)v11 )
    return (unsigned int)v5;
  v12 = (AkMusicMarkerWwise *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v11);
  v13 = v12;
  if ( !v12 )
    return 52i64;
  v14 = 0;
  p_pszName = &v12->pszName;
  while ( 1 )
  {
    v16 = *(_DWORD *)io_rpData;
    io_rpData += 4;
    *((_DWORD *)p_pszName - 4) = v16;
    v17 = *(double *)io_rpData;
    io_rpData += 8;
    *((double *)p_pszName - 1) = v17;
    v18 = io_rpData + 4;
    v19 = *(unsigned int *)io_rpData;
    io_rpData += 4;
    if ( !(_DWORD)v19 )
    {
      *p_pszName = 0i64;
      goto LABEL_14;
    }
    v20 = v18;
    v21 = (unsigned int)v19;
    io_rpData = &v18[v19];
    v22 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(v19 + 1));
    *p_pszName = v22;
    if ( !v22 )
      break;
    memmove(v22, v20, (unsigned int)v21);
    (*p_pszName)[v21] = 0;
LABEL_14:
    ++v14;
    p_pszName += 3;
    if ( v14 >= (unsigned int)v11 )
    {
      v5 = CAkMusicSegment::SetMarkers(this, v13, v11);
      goto LABEL_16;
    }
  }
  v5 = AK_Fail;
LABEL_16:
  AK::MemoryMgr::Free(g_DefaultPoolId, v13);
  return (unsigned int)v5;
}

// File Line: 128
// RVA: 0xAB1230
__int64 __fastcall Scaleform::GFx::AS2::ArrayObject::GetObjectType(CAkMusicSegment *this)
{
  return 7i64;
}

// File Line: 134
// RVA: 0xAB0940
__int64 __fastcall CAkMusicSegment::ExecuteAction(CAkMusicSegment *this, ActionParams *in_rAction)
{
  char v2; // al
  float v3; // xmm3_4
  float v4; // xmm0_4

  if ( in_rAction->eType != ActionParamType_Seek )
    return CAkMusicNode::ExecuteAction(this, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  if ( (v2 & 1) != 0 )
  {
    v3 = *(float *)&in_rAction[1].eType;
    v4 = 0.0;
    if ( v3 < 0.0 || (v4 = *(float *)&FLOAT_1_0, v3 > 1.0) )
      v3 = v4;
    CAkMusicRenderer::SeekPercent(CAkMusicRenderer::m_pMusicRenderer, this, in_rAction->pGameObj, v3, (v2 & 2) != 0);
    return 1i64;
  }
  else
  {
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      in_rAction->pGameObj,
      in_rAction[1].eType,
      (v2 & 2) != 0);
    return 1i64;
  }
}

// File Line: 162
// RVA: 0xAB09D0
__int64 __fastcall CAkMusicSegment::ExecuteActionExcept(CAkMusicSegment *this, ActionParamsExcept *in_rAction)
{
  char v2; // al
  float v3; // xmm3_4
  float v4; // xmm0_4

  if ( in_rAction->eType != ActionParamType_Seek )
    return CAkMusicNode::ExecuteActionExcept(this, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  if ( (v2 & 1) != 0 )
  {
    v3 = *(float *)&in_rAction[1].eType;
    v4 = 0.0;
    if ( v3 < 0.0 || (v4 = *(float *)&FLOAT_1_0, v3 > 1.0) )
      v3 = v4;
    CAkMusicRenderer::SeekPercent(CAkMusicRenderer::m_pMusicRenderer, this, in_rAction->pGameObj, v3, (v2 & 2) != 0);
    return 1i64;
  }
  else
  {
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      in_rAction->pGameObj,
      in_rAction[1].eType,
      (v2 & 2) != 0);
    return 1i64;
  }
}

// File Line: 197
// RVA: 0xAB07F0
// attributes: thunk
CAkSequencableSegmentCtx *__fastcall CAkMusicSegment::CreateContext(
        CAkMusicSegment *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  return CAkMusicSegment::CreateSegmentContext(this, in_pParentCtx, in_GameObject, in_rUserparams);
}

// File Line: 206
// RVA: 0xAB08A0
CAkSequencableSegmentCtx *__fastcall CAkMusicSegment::CreateSegmentContext(
        CAkMusicSegment *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  CAkSequencableSegmentCtx *v9; // rax
  CAkSequencableSegmentCtx *v10; // rax
  CAkMusicCtx *v11; // rbx

  if ( !this->m_markers.m_uLength )
    return 0i64;
  v9 = (CAkSequencableSegmentCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA0ui64);
  if ( !v9 )
    return 0i64;
  CAkSequencableSegmentCtx::CAkSequencableSegmentCtx(v9, this, in_pParentCtx);
  v11 = v10;
  if ( v10 )
  {
    ++v10->m_uRefCount;
    if ( CAkSequencableSegmentCtx::Init(v10, in_GameObject, in_rUserparams) == AK_Success )
    {
      CAkMusicCtx::Release(v11);
      return (CAkSequencableSegmentCtx *)v11;
    }
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v11);
    CAkMusicCtx::Release(v11);
    return 0i64;
  }
  return (CAkSequencableSegmentCtx *)v11;
}

// File Line: 236
// RVA: 0xAB0800
CAkSegmentCtx *__fastcall CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(
        CAkMusicSegment *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  CAkSegmentCtx *v9; // rax
  CAkSegmentCtx *v10; // rax
  CAkMusicCtx *v11; // rbx

  if ( !this->m_markers.m_uLength )
    return 0i64;
  v9 = (CAkSegmentCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v9 )
  {
    CAkSegmentCtx::CAkSegmentCtx(v9, this, in_pParentCtx);
    v11 = v10;
    if ( !v10 )
      return (CAkSegmentCtx *)v11;
    ++v10->m_uRefCount;
    if ( (unsigned int)CAkSegmentCtx::Init(v10, in_GameObject, in_rUserparams) == 1 )
      return (CAkSegmentCtx *)v11;
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v11);
    CAkMusicCtx::Release(v11);
  }
  return 0i64;
}

// File Line: 257
// RVA: 0xAB06B0
__int64 __fastcall CAkMusicSegment::CanAddChild(CAkMusicSegment *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int key; // edi

  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release(in_pAudioNode);
  if ( (unsigned __int16)this->vfptr[20].Release(this) == 0xFFFF )
    return 9i64;
  if ( v5 != 6 )
    return 4i64;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  key = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         key) )
  {
    return 5i64;
  }
  if ( this->key == key )
    return 23;
  return v4;
}

// File Line: 288
// RVA: 0xAB1300
__int64 __fastcall CAkMusicSegment::PlayInternal(CAkMusicSegment *this, AkPBIParams *in_rPBIParams)
{
  CAkSequencableSegmentCtx *SegmentContext; // rax
  CAkMusicCtx *v4; // rbx
  TransParams *pTransitionParameters; // rdx
  CAkTransition **v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h] BYREF

  SegmentContext = CAkMusicSegment::CreateSegmentContext(
                     this,
                     0i64,
                     in_rPBIParams->pGameObj,
                     &in_rPBIParams->userParams);
  v4 = SegmentContext;
  if ( !SegmentContext )
    return 2i64;
  pTransitionParameters = in_rPBIParams->pTransitionParameters;
  in_fadeParams.transitionTime = pTransitionParameters->TransitionTime;
  in_fadeParams.eFadeCurve = pTransitionParameters->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(SegmentContext);
  CAkMusicCtx::_Play(v4, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 327
// RVA: 0xAB1600
__int64 __fastcall CAkMusicSegment::SetMarkers(
        CAkMusicSegment *this,
        AkMusicMarkerWwise *in_pArrayMarkers,
        unsigned int in_ulNumMarkers)
{
  AkArray<AkMusicMarker,AkMusicMarker const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *p_m_markers; // rbx
  __int64 v4; // rdi
  AkMusicMarker *v6; // rax
  unsigned int v7; // r9d
  __int64 v8; // r10
  char **p_pszName; // rdx
  unsigned int v10; // eax
  __int64 v11; // r8
  unsigned int m_uLength; // eax
  __int64 v13; // rcx
  double v15; // xmm1_8
  double v16; // xmm0_8
  unsigned int v17; // eax
  __int64 v18; // rcx
  double v19; // xmm1_8
  double v20; // xmm0_8
  unsigned int v21; // eax
  __int64 v22; // rcx
  double v23; // xmm1_8
  double v24; // xmm0_8
  unsigned int v25; // eax
  __int64 v26; // rcx
  double v27; // xmm1_8
  double v28; // xmm0_8
  __int64 v29; // r8
  char **v30; // rdx
  unsigned int v31; // eax
  __int64 v32; // rcx
  double v33; // xmm1_8
  double v34; // xmm0_8

  p_m_markers = &this->m_markers;
  v4 = in_ulNumMarkers;
  if ( this->m_markers.m_pItems )
  {
    AkArray<AkMusicMarker,AkMusicMarker const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(&this->m_markers);
    AK::MemoryMgr::Free(g_DefaultPoolId, p_m_markers->m_pItems);
    p_m_markers->m_pItems = 0i64;
    p_m_markers->m_ulReserved = 0;
  }
  if ( (_DWORD)v4 )
  {
    v6 = (AkMusicMarker *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16 * v4);
    p_m_markers->m_pItems = v6;
    if ( !v6 )
      return 2i64;
    p_m_markers->m_ulReserved = v4;
  }
  v7 = 0;
  v8 = 0i64;
  if ( (int)v4 >= 4 )
  {
    p_pszName = &in_pArrayMarkers->pszName;
    v10 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v11 = v10;
    v7 = 4 * v10;
    v8 = 4i64 * v10;
    do
    {
      m_uLength = p_m_markers->m_uLength;
      if ( m_uLength >= p_m_markers->m_ulReserved )
      {
        v13 = 0i64;
      }
      else
      {
        p_m_markers->m_uLength = m_uLength + 1;
        v13 = (__int64)&p_m_markers->m_pItems[m_uLength];
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *(_QWORD *)(v13 + 8) = 0i64;
        }
      }
      *(_DWORD *)v13 = *((_DWORD *)p_pszName - 4);
      v15 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * *((double *)p_pszName - 1) * 0.001;
      if ( v15 <= 0.0 )
        v16 = DOUBLE_N0_5;
      else
        v16 = DOUBLE_0_5;
      *(_DWORD *)(v13 + 4) = (int)(v16 + v15);
      *(_QWORD *)(v13 + 8) = *p_pszName;
      v17 = p_m_markers->m_uLength;
      if ( v17 >= p_m_markers->m_ulReserved )
      {
        v18 = 0i64;
      }
      else
      {
        p_m_markers->m_uLength = v17 + 1;
        v18 = (__int64)&p_m_markers->m_pItems[v17];
        if ( v18 )
        {
          *(_QWORD *)v18 = 0i64;
          *(_QWORD *)(v18 + 8) = 0i64;
        }
      }
      *(_DWORD *)v18 = *((_DWORD *)p_pszName + 2);
      v19 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * *((double *)p_pszName + 2) * 0.001;
      if ( v19 <= 0.0 )
        v20 = DOUBLE_N0_5;
      else
        v20 = DOUBLE_0_5;
      *(_DWORD *)(v18 + 4) = (int)(v20 + v19);
      *(_QWORD *)(v18 + 8) = p_pszName[3];
      v21 = p_m_markers->m_uLength;
      if ( v21 >= p_m_markers->m_ulReserved )
      {
        v22 = 0i64;
      }
      else
      {
        p_m_markers->m_uLength = v21 + 1;
        v22 = (__int64)&p_m_markers->m_pItems[v21];
        if ( v22 )
        {
          *(_QWORD *)v22 = 0i64;
          *(_QWORD *)(v22 + 8) = 0i64;
        }
      }
      *(_DWORD *)v22 = *((_DWORD *)p_pszName + 8);
      v23 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * *((double *)p_pszName + 5) * 0.001;
      if ( v23 <= 0.0 )
        v24 = DOUBLE_N0_5;
      else
        v24 = DOUBLE_0_5;
      *(_DWORD *)(v22 + 4) = (int)(v24 + v23);
      *(_QWORD *)(v22 + 8) = p_pszName[6];
      v25 = p_m_markers->m_uLength;
      if ( v25 >= p_m_markers->m_ulReserved )
      {
        v26 = 0i64;
      }
      else
      {
        p_m_markers->m_uLength = v25 + 1;
        v26 = (__int64)&p_m_markers->m_pItems[v25];
        if ( v26 )
        {
          *(_QWORD *)v26 = 0i64;
          *(_QWORD *)(v26 + 8) = 0i64;
        }
      }
      *(_DWORD *)v26 = *((_DWORD *)p_pszName + 14);
      v27 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * *((double *)p_pszName + 8) * 0.001;
      if ( v27 <= 0.0 )
        v28 = DOUBLE_N0_5;
      else
        v28 = DOUBLE_0_5;
      p_pszName += 12;
      *(_DWORD *)(v26 + 4) = (int)(v28 + v27);
      *(_QWORD *)(v26 + 8) = *(p_pszName - 3);
      --v11;
    }
    while ( v11 );
  }
  if ( v7 < (unsigned int)v4 )
  {
    v29 = (unsigned int)v4 - v7;
    v30 = &in_pArrayMarkers->pszName + 2 * v8 + v8;
    do
    {
      v31 = p_m_markers->m_uLength;
      if ( v31 >= p_m_markers->m_ulReserved )
      {
        v32 = 0i64;
      }
      else
      {
        p_m_markers->m_uLength = v31 + 1;
        v32 = (__int64)&p_m_markers->m_pItems[v31];
        if ( v32 )
        {
          *(_QWORD *)v32 = 0i64;
          *(_QWORD *)(v32 + 8) = 0i64;
        }
      }
      *(_DWORD *)v32 = *((_DWORD *)v30 - 4);
      v33 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * *((double *)v30 - 1) * 0.001;
      if ( v33 <= 0.0 )
        v34 = DOUBLE_N0_5;
      else
        v34 = DOUBLE_0_5;
      v30 += 3;
      *(_DWORD *)(v32 + 4) = (int)(v34 + v33);
      *(_QWORD *)(v32 + 8) = *(v30 - 3);
      --v29;
    }
    while ( v29 );
  }
  return 1i64;
}

// File Line: 349
// RVA: 0xAB18F0
CAkMusicTrack *__fastcall CAkMusicSegment::Track(CAkMusicSegment *this, unsigned __int16 in_uIndex)
{
  if ( in_uIndex >= this->m_mapChildId.m_uLength )
    return 0i64;
  else
    return (CAkMusicTrack *)this->m_mapChildId.m_pItems[in_uIndex];
}

// File Line: 362
// RVA: 0xAB0BB0
int __fastcall CAkMusicSegment::GetExitSyncPos(
        CAkMusicSegment *this,
        unsigned int in_uSrcMinTime,
        AkSyncType in_eSyncType,
        unsigned int *io_uCueFilterHash,
        bool in_bSkipEntryCue,
        unsigned int *out_uExitSyncPos)
{
  AkMusicMarker *m_pItems; // r9
  int v10; // r10d
  unsigned int v11; // edx
  CAkParameterNodeBase **MusicGrid; // rax
  unsigned int v13; // edx
  int v14; // r8d
  unsigned int v15; // r11d
  BOOL v16; // r10d
  int v18; // edx
  unsigned int *v19; // r8
  unsigned int v20; // r9d
  unsigned int i; // eax
  int v22; // edx
  unsigned int NextMarkerPosition; // ecx

  m_pItems = this->m_markers.m_pItems;
  v10 = 2;
  v11 = m_pItems[this->m_markers.m_uLength - 1].uPosition - m_pItems->uPosition;
  if ( in_uSrcMinTime <= v11 )
  {
    switch ( in_eSyncType )
    {
      case SyncTypeImmediate:
        *io_uCueFilterHash = 0;
        *out_uExitSyncPos = in_uSrcMinTime;
        return 1;
      case SyncTypeNextGrid:
        MusicGrid = CAkMusicNode::GetMusicGrid(this);
        v13 = *((_DWORD *)MusicGrid + 3);
        v14 = *((_DWORD *)MusicGrid + 2);
        if ( in_bSkipEntryCue )
          ++in_uSrcMinTime;
        v15 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = v13;
        if ( v14 )
        {
          if ( v13 <= in_uSrcMinTime )
          {
            do
              v13 += v14;
            while ( v13 <= in_uSrcMinTime );
            *out_uExitSyncPos = v13;
          }
        }
        else
        {
          *out_uExitSyncPos = in_uSrcMinTime + 1;
        }
        v16 = *out_uExitSyncPos > v15;
        *io_uCueFilterHash = 0;
        return v16 + 1;
      case SyncTypeNextBar:
        v22 = *((_DWORD *)CAkMusicNode::GetMusicGrid(this) + 1);
        if ( in_bSkipEntryCue )
          ++in_uSrcMinTime;
        v19 = out_uExitSyncPos;
        v20 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = 0;
        if ( !v22 )
          goto LABEL_18;
        for ( i = 0; i <= in_uSrcMinTime; i += v22 )
          ;
        goto LABEL_19;
      case SyncTypeNextBeat:
        v18 = *(_DWORD *)CAkMusicNode::GetMusicGrid(this);
        if ( in_bSkipEntryCue )
          ++in_uSrcMinTime;
        v19 = out_uExitSyncPos;
        v20 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = 0;
        if ( v18 )
        {
          for ( i = 0; i <= in_uSrcMinTime; i += v18 )
            ;
        }
        else
        {
LABEL_18:
          i = in_uSrcMinTime + 1;
        }
LABEL_19:
        *v19 = i;
        *io_uCueFilterHash = 0;
        return (i > v20) + 1;
      case SyncTypeNextMarker:
        NextMarkerPosition = CAkMusicSegment::GetNextMarkerPosition(
                               this,
                               in_uSrcMinTime,
                               io_uCueFilterHash,
                               in_bSkipEntryCue);
        goto LABEL_32;
      case SyncTypeNextUserMarker:
        return CAkMusicSegment::GetNextUserMarkerPosition(this, in_uSrcMinTime, io_uCueFilterHash, out_uExitSyncPos);
      case SyncTypeEntryMarker:
        if ( in_uSrcMinTime || in_bSkipEntryCue )
          return v10;
        NextMarkerPosition = 0;
        *io_uCueFilterHash = m_pItems->id;
LABEL_32:
        *out_uExitSyncPos = NextMarkerPosition;
        break;
      case SyncTypeExitMarker:
        *out_uExitSyncPos = v11;
        *io_uCueFilterHash = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].id;
        break;
      default:
        return v10;
    }
    return 1;
  }
  return v10;
}

// File Line: 443
// RVA: 0xAB0AF0
void __fastcall CAkMusicSegment::GetEntrySyncPos(
        CAkMusicSegment *this,
        AkMusicTransDestRule *in_rule,
        unsigned int in_uMinimumEntryPosition,
        unsigned int in_uCueHashForMatchSrc,
        unsigned int *out_uSelectedCueHash,
        unsigned int *out_uRequiredEntryPosition)
{
  unsigned int v8; // ecx
  __int16 v9; // cx
  __int16 v10; // ax
  bool v11; // r9

  v8 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
  if ( v8 )
    *out_uRequiredEntryPosition = in_uMinimumEntryPosition % v8;
  else
    *out_uRequiredEntryPosition = 0;
  *out_uSelectedCueHash = 0;
  v9 = *((_WORD *)in_rule + 10);
  v10 = v9 & 7;
  if ( (v9 & 7) != 0 )
  {
    if ( v10 == 2 )
    {
      if ( (v9 & 0x10) == 0 )
        in_uCueHashForMatchSrc = in_rule->uCueFilterHash;
      v11 = 0;
    }
    else
    {
      if ( v10 != 3 )
        return;
      if ( (v9 & 0x10) == 0 )
        in_uCueHashForMatchSrc = in_rule->uCueFilterHash;
      v11 = 1;
    }
    *out_uRequiredEntryPosition = CAkMusicSegment::GetRandomCue(
                                    this,
                                    *out_uRequiredEntryPosition,
                                    in_uCueHashForMatchSrc,
                                    v11,
                                    out_uSelectedCueHash);
  }
  else if ( !in_uMinimumEntryPosition )
  {
    *out_uSelectedCueHash = this->m_markers.m_pItems->id;
  }
}

// File Line: 480
// RVA: 0xAB1060
__int64 __fastcall CAkMusicSegment::GetRandomCue(
        CAkMusicSegment *this,
        unsigned int in_uMinPosition,
        unsigned int in_uCueFilter,
        bool in_bAvoidEntryCue,
        unsigned int *out_uSelectedCueHash)
{
  AkMusicMarker *m_pItems; // r8
  unsigned int v7; // edx
  __int64 v8; // rbx
  unsigned int v9; // r9d
  unsigned int *p_uPosition; // rax
  unsigned int v12; // edi
  unsigned int v13; // ecx
  AkMusicMarker *v14; // rax
  __int64 v15; // rcx
  unsigned int v16; // edx
  __int64 v17; // rdx
  __int64 v18; // rdx

  m_pItems = this->m_markers.m_pItems;
  v7 = m_pItems->uPosition + in_uMinPosition;
  v8 = in_bAvoidEntryCue;
  v9 = this->m_markers.m_uLength - 1;
  if ( (unsigned int)v8 < v9 )
  {
    p_uPosition = &m_pItems[v8].uPosition;
    do
    {
      if ( *p_uPosition >= v7 )
        break;
      LODWORD(v8) = v8 + 1;
      p_uPosition += 4;
    }
    while ( (unsigned int)v8 < v9 );
  }
  if ( in_uCueFilter )
  {
    v12 = 0;
    v13 = v8;
    if ( !(_DWORD)v8 )
    {
      v12 = 1;
      v13 = 1;
    }
    if ( v13 < v9 )
    {
      v14 = &m_pItems[v13];
      v15 = v9 - v13;
      do
      {
        if ( v14->id == in_uCueFilter )
          ++v12;
        ++v14;
        --v15;
      }
      while ( v15 );
    }
  }
  else
  {
    v12 = v9 - v8;
  }
  if ( v12 )
  {
    v16 = rand() % v12;
    if ( in_uCueFilter )
    {
      if ( (_DWORD)v8 )
        goto LABEL_20;
      if ( !v16 )
      {
LABEL_24:
        v17 = 0i64;
        goto LABEL_27;
      }
      --v16;
      LODWORD(v8) = 1;
      while ( 1 )
      {
LABEL_20:
        if ( this->m_markers.m_pItems[(unsigned int)v8].id == in_uCueFilter )
        {
          if ( !v16 )
          {
            v17 = (unsigned int)v8;
            goto LABEL_27;
          }
          --v16;
        }
        LODWORD(v8) = v8 + 1;
        if ( (unsigned int)v8 >= this->m_markers.m_uLength )
          goto LABEL_24;
      }
    }
    v17 = (unsigned int)v8 + v16;
LABEL_27:
    v18 = v17;
    *out_uSelectedCueHash = this->m_markers.m_pItems[v18].id;
    return this->m_markers.m_pItems[v18].uPosition - this->m_markers.m_pItems->uPosition;
  }
  else
  {
    *out_uSelectedCueHash = m_pItems->id;
    return 0i64;
  }
}

// File Line: 593
// RVA: 0xAB1390
__int64 __fastcall CAkMusicSegment::PreEntryDuration(CAkMusicSegment *this)
{
  return this->m_markers.m_pItems->uPosition;
}

// File Line: 601
// RVA: 0xAB1370
__int64 __fastcall CAkMusicSegment::PostExitDuration(CAkMusicSegment *this)
{
  return this->m_uDuration - this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition;
}

// File Line: 609
// RVA: 0xAB0690
__int64 __fastcall CAkMusicSegment::ActiveDuration(CAkMusicSegment *this)
{
  return this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
}

// File Line: 633
// RVA: 0xAB0E00
__int64 __fastcall CAkMusicSegment::GetNextMarkerPosition(
        CAkMusicSegment *this,
        int in_iPosition,
        unsigned int *io_uCueFilterHash,
        bool in_bDoSkipEntryCue)
{
  AkMusicMarker *m_pItems; // rcx
  AkMusicMarker *v7; // rax
  AkMusicMarker *v8; // r8

  m_pItems = this->m_markers.m_pItems;
  v7 = m_pItems;
  if ( in_bDoSkipEntryCue )
    v7 = m_pItems + 1;
  v8 = &m_pItems[this->m_markers.m_uLength];
  if ( v7 == v8 )
  {
LABEL_8:
    *io_uCueFilterHash = v8[-1].id;
    return this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
  }
  else
  {
    while ( v7->uPosition < in_iPosition + m_pItems->uPosition || *io_uCueFilterHash && v7->id != *io_uCueFilterHash )
    {
      if ( ++v7 == v8 )
        goto LABEL_8;
    }
    *io_uCueFilterHash = v7->id;
    return v7->uPosition - this->m_markers.m_pItems->uPosition;
  }
}

// File Line: 672
// RVA: 0xAB0E90
__int64 __fastcall CAkMusicSegment::GetNextUserMarkerPosition(
        CAkMusicSegment *this,
        unsigned int in_uPosition,
        unsigned int *io_uCueFilterHash,
        unsigned int *out_uMarkerPosition)
{
  AkMusicMarker *m_pItems; // r11
  unsigned int v5; // eax
  __int64 result; // rax
  __int64 v7; // rdx

  m_pItems = this->m_markers.m_pItems;
  v5 = 1;
  if ( this->m_markers.m_uLength == 2 )
    return 2i64;
  while ( m_pItems[v5].uPosition <= in_uPosition + m_pItems->uPosition
       || *io_uCueFilterHash && m_pItems[v5].id != *io_uCueFilterHash )
  {
    if ( ++v5 > this->m_markers.m_uLength - 2 )
      return 2i64;
  }
  v7 = v5;
  result = 1i64;
  v7 *= 2i64;
  *io_uCueFilterHash = *(&m_pItems->id + 2 * v7);
  *out_uMarkerPosition = *(&this->m_markers.m_pItems->uPosition + 2 * v7) - this->m_markers.m_pItems->uPosition;
  return result;
}

// File Line: 707
// RVA: 0xAB1240
void __fastcall CAkMusicSegment::NotifyUserCuesInRange(
        CAkMusicSegment *this,
        unsigned int in_playingID,
        AkMusicGrid *in_rGrid,
        int in_iStartPosition,
        unsigned int in_uRangeSize)
{
  int v5; // edi
  unsigned int v9; // ebp
  unsigned int v10; // esi
  unsigned int v11; // ebx
  AkMusicMarker *v12; // r9
  unsigned int uPosition; // eax

  v5 = this->m_markers.m_pItems->uPosition + in_iStartPosition;
  if ( v5 < 0 )
  {
    v9 = v5 + in_uRangeSize;
    if ( (int)(v5 + in_uRangeSize) <= 0 )
      return;
    v5 = 0;
  }
  else
  {
    v9 = v5 + in_uRangeSize;
  }
  v10 = this->m_markers.m_uLength - 2;
  v11 = 1;
  if ( this->m_markers.m_uLength != 2 )
  {
    do
    {
      v12 = &this->m_markers.m_pItems[v11];
      uPosition = v12->uPosition;
      if ( uPosition >= v5 )
      {
        if ( uPosition >= v9 )
          return;
        CAkPlayingMgr::NotifyMusicUserCues(g_pPlayingMgr, in_playingID, in_rGrid, v12->pszName);
      }
      ++v11;
    }
    while ( v11 <= v10 );
  }
}

// File Line: 757
// RVA: 0xAB0F20
void __fastcall CAkMusicSegment::GetNumMusicGridInRange(
        CAkMusicSegment *this,
        int in_iStartPosition,
        unsigned int in_uRangeSize,
        unsigned int *out_uNumBars,
        unsigned int *out_uNumBeats,
        unsigned int *out_uNumGrids)
{
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int v9; // edi
  unsigned int v10; // edx
  CAkParameterNodeBase **MusicGrid; // r8
  unsigned int v12; // r9d
  unsigned int v13; // r10d
  unsigned int v14; // r9d
  unsigned int v15; // r10d
  unsigned int v16; // r9d

  v6 = 0;
  v7 = in_uRangeSize;
  v9 = in_iStartPosition;
  if ( in_iStartPosition < 0 )
  {
    if ( in_uRangeSize <= -in_iStartPosition )
    {
LABEL_3:
      *out_uNumBars = 0;
      *out_uNumBeats = 0;
      *out_uNumGrids = 0;
      return;
    }
    v7 = in_uRangeSize + in_iStartPosition;
    v9 = 0;
  }
  v10 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].uPosition - this->m_markers.m_pItems->uPosition;
  if ( v9 + v7 > v10 )
  {
    if ( v9 >= v10 )
      goto LABEL_3;
    v7 = v10 - v9;
  }
  MusicGrid = CAkMusicNode::GetMusicGrid(this);
  v12 = *((_DWORD *)MusicGrid + 1);
  if ( v12 )
    v13 = ((v12 + v9) % v12 + v12 - 1 + v7) / v12 - ((v12 + v9) % v12 + v12 - 1) / v12;
  else
    v13 = 0;
  *out_uNumBars = v13;
  if ( *(_DWORD *)MusicGrid )
  {
    v14 = *(_DWORD *)MusicGrid;
    v15 = ((v14 + v9) % v14 + v14 - 1 + v7) / v14 - ((v14 + v9) % v14 + v14 - 1) / v14;
  }
  else
  {
    v15 = 0;
  }
  *out_uNumBeats = v15;
  v16 = *((_DWORD *)MusicGrid + 2);
  if ( v16 )
    v6 = ((v9 + v16 - *((_DWORD *)MusicGrid + 3)) % v16 + v16 - 1 + v7) / v16
       - ((v9 + v16 - *((_DWORD *)MusicGrid + 3)) % v16 + v16 - 1) / v16;
  *out_uNumGrids = v6;
}

// File Line: 822
// RVA: 0xAB0A60
__int64 __fastcall CAkMusicSegment::GetClosestCuePosition(CAkMusicSegment *this, int in_iPosition)
{
  AkMusicMarker *m_pItems; // rbx
  unsigned int m_uLength; // r11d
  AkMusicMarker *v4; // r8
  unsigned int uPosition; // esi
  unsigned int *p_uPosition; // r9
  unsigned int v7; // ecx
  unsigned int v8; // r11d
  signed int v9; // r10d
  signed int v10; // eax
  signed int v12; // [rsp+10h] [rbp+10h]

  m_pItems = this->m_markers.m_pItems;
  m_uLength = this->m_markers.m_uLength;
  v4 = 0i64;
  uPosition = m_pItems->uPosition;
  p_uPosition = &m_pItems->uPosition;
  v7 = 0;
  v8 = m_uLength - 1;
  if ( v8 )
  {
    v9 = v12;
    do
    {
      v10 = abs32(*p_uPosition - (uPosition + in_iPosition));
      if ( !v4 || v10 < v9 )
      {
        v9 = v10;
        v4 = &m_pItems[v7];
      }
      ++v7;
      p_uPosition += 4;
    }
    while ( v7 < v8 );
  }
  return v4->uPosition - uPosition;
}

// File Line: 848
// RVA: 0xAB11A0
char __fastcall CAkMusicSegment::GetStateSyncTypes(
        CAkMusicSegment *this,
        unsigned int in_stateGroupID,
        CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes)
{
  CAkParameterNodeBase **m_pItems; // rbx

  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems == &m_pItems[this->m_mapChildId.m_uLength] )
    return CAkParameterNodeBase::GetStateSyncTypes(this, in_stateGroupID, io_pSyncTypes, 0);
  while ( !CAkMusicTrack::GetStateSyncTypes((CAkMusicTrack *)*m_pItems, in_stateGroupID, io_pSyncTypes) )
  {
    if ( ++m_pItems == &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] )
      return CAkParameterNodeBase::GetStateSyncTypes(this, in_stateGroupID, io_pSyncTypes, 0);
  }
  return 1;
}

