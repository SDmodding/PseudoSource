// File Line: 54
// RVA: 0xAB0750
CAkMusicSegment *__fastcall CAkMusicSegment::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkMusicSegment *result; // rax
  CAkMusicSegment *v3; // rbx
  unsigned int v4; // eax
  signed int v5; // ecx
  bool v6; // al

  v1 = in_ulID;
  result = (CAkMusicSegment *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  v3 = result;
  if ( result )
  {
    CAkMusicNode::CAkMusicNode((CAkMusicNode *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkMusicSegment::`vftable';
    v3->m_markers.m_pItems = 0i64;
    *(_QWORD *)&v3->m_markers.m_uLength = 0i64;
    v3->m_uDuration = 0;
    v4 = v3->vfptr[3].Release((CAkIndexable *)&v3->vfptr);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->0 + 83) &= 0xFDu;
    *((_BYTE *)&v3->0 + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v3->vfptr);
    result = v3;
  }
  return result;
}

// File Line: 68
// RVA: 0xAB1420
__int64 __fastcall CAkMusicSegment::SetInitialValues(CAkMusicSegment *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkMusicSegment *v3; // r13
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
  char **v15; // rbx
  int v16; // ecx
  double v17; // xmm0_8
  char *v18; // rax
  __int64 v19; // rcx
  char *v20; // rbp
  __int64 v21; // r14
  char *v22; // rax
  char *io_rpData; // [rsp+68h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+70h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  v3 = this;
  result = CAkMusicNode::SetMusicNodeParams((CAkMusicNode *)&this->vfptr, &io_rpData, &io_rulDataSize, 0);
  v5 = (signed int)result;
  if ( (_DWORD)result != 1 )
    return result;
  v6 = io_rpData + 8;
  v7 = *(double *)io_rpData;
  io_rpData += 8;
  v8 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v7 * 0.001;
  if ( v8 <= 0.0 )
    v9 = DOUBLE_N0_5;
  else
    v9 = DOUBLE_0_5;
  v10 = v6 + 4;
  v3->m_uDuration = (signed int)(v9 + v8);
  v11 = *((unsigned int *)v10 - 1);
  io_rpData = v10;
  if ( !(_DWORD)v11 )
    return (unsigned int)v5;
  v12 = (AkMusicMarkerWwise *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v11);
  v13 = v12;
  if ( !v12 )
    return 52i64;
  v14 = 0;
  if ( !(_DWORD)v11 )
  {
LABEL_15:
    v5 = CAkMusicSegment::SetMarkers(v3, v13, v11);
    goto LABEL_16;
  }
  v15 = &v12->pszName;
  while ( 1 )
  {
    v16 = *(_DWORD *)io_rpData;
    io_rpData += 4;
    *((_DWORD *)v15 - 4) = v16;
    v17 = *(double *)io_rpData;
    io_rpData += 8;
    *((double *)v15 - 1) = v17;
    v18 = io_rpData + 4;
    v19 = *(unsigned int *)io_rpData;
    io_rpData += 4;
    if ( !(_DWORD)v19 )
    {
      *v15 = 0i64;
      goto LABEL_14;
    }
    v20 = v18;
    v21 = (unsigned int)v19;
    io_rpData = &v18[v19];
    v22 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(v19 + 1));
    *v15 = v22;
    if ( !v22 )
      break;
    memmove(v22, v20, (unsigned int)v21);
    (*v15)[v21] = 0;
LABEL_14:
    ++v14;
    v15 += 3;
    if ( v14 >= (unsigned int)v11 )
      goto LABEL_15;
  }
  v5 = 2;
LABEL_16:
  AK::MemoryMgr::Free(g_DefaultPoolId, v13);
  return (unsigned int)v5;
}

// File Line: 128
// RVA: 0xAB1230
signed __int64 __fastcall Scaleform::GFx::AS2::ArrayObject::GetObjectType(CAkMusicSegment *this)
{
  return 7i64;
}

// File Line: 134
// RVA: 0xAB0940
__int64 __fastcall CAkMusicSegment::ExecuteAction(CAkMusicSegment *this, ActionParams *in_rAction)
{
  unsigned __int8 v2; // al
  float v3; // xmm3_4
  float v4; // xmm0_4
  __int64 result; // rax

  if ( in_rAction->eType != 4 )
    return CAkMusicNode::ExecuteAction((CAkMusicNode *)&this->vfptr, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  if ( v2 & 1 )
  {
    v3 = *(float *)&in_rAction[1].eType;
    v4 = 0.0;
    if ( v3 < 0.0 || (v4 = *(float *)&FLOAT_1_0, v3 > 1.0) )
      v3 = v4;
    CAkMusicRenderer::SeekPercent(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      in_rAction->pGameObj,
      v3,
      (v2 >> 1) & 1);
    result = 1i64;
  }
  else
  {
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      in_rAction->pGameObj,
      in_rAction[1].eType,
      (v2 >> 1) & 1);
    result = 1i64;
  }
  return result;
}

// File Line: 162
// RVA: 0xAB09D0
__int64 __fastcall CAkMusicSegment::ExecuteActionExcept(CAkMusicSegment *this, ActionParamsExcept *in_rAction)
{
  unsigned __int8 v2; // al
  float v3; // xmm3_4
  float v4; // xmm0_4
  __int64 result; // rax

  if ( in_rAction->eType != 4 )
    return CAkMusicNode::ExecuteActionExcept((CAkMusicNode *)&this->vfptr, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  if ( v2 & 1 )
  {
    v3 = *(float *)&in_rAction[1].eType;
    v4 = 0.0;
    if ( v3 < 0.0 || (v4 = *(float *)&FLOAT_1_0, v3 > 1.0) )
      v3 = v4;
    CAkMusicRenderer::SeekPercent(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      in_rAction->pGameObj,
      v3,
      (v2 >> 1) & 1);
    result = 1i64;
  }
  else
  {
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      in_rAction->pGameObj,
      in_rAction[1].eType,
      (v2 >> 1) & 1);
    result = 1i64;
  }
  return result;
}

// File Line: 197
// RVA: 0xAB07F0
CAkSequencableSegmentCtx *__fastcall CAkMusicSegment::CreateContext(CAkMusicSegment *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  return CAkMusicSegment::CreateSegmentContext(this, in_pParentCtx, in_GameObject, in_rUserparams);
}

// File Line: 206
// RVA: 0xAB08A0
CAkMusicCtx *__fastcall CAkMusicSegment::CreateSegmentContext(CAkMusicSegment *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  UserParams *v4; // rsi
  CAkRegisteredObj *v5; // rbp
  CAkMatrixAwareCtx *v6; // rdi
  CAkMusicSegment *v7; // rbx
  CAkSequencableSegmentCtx *v9; // rax
  CAkSequencableSegmentCtx *v10; // rax
  CAkMusicCtx *v11; // rbx

  v4 = in_rUserparams;
  v5 = in_GameObject;
  v6 = in_pParentCtx;
  v7 = this;
  if ( !this->m_markers.m_uLength )
    return 0i64;
  v9 = (CAkSequencableSegmentCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA0ui64);
  if ( !v9 )
    goto LABEL_8;
  CAkSequencableSegmentCtx::CAkSequencableSegmentCtx(v9, v7, (CAkMusicCtx *)&v6->vfptr);
  v11 = (CAkMusicCtx *)&v10->vfptr;
  if ( v10 )
  {
    ++v10->m_uRefCount;
    if ( CAkSequencableSegmentCtx::Init(v10, v5, v4) == 1 )
    {
      CAkMusicCtx::Release(v11);
      return v11;
    }
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v11);
    CAkMusicCtx::Release(v11);
LABEL_8:
    v11 = 0i64;
  }
  return v11;
}

// File Line: 236
// RVA: 0xAB0800
CAkMusicCtx *__fastcall CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(CAkMusicSegment *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  UserParams *v4; // rsi
  CAkRegisteredObj *v5; // rbp
  CAkMatrixAwareCtx *v6; // rdi
  CAkMusicSegment *v7; // rbx
  CAkSegmentCtx *v9; // rax
  CAkSegmentCtx *v10; // rax
  CAkMusicCtx *v11; // rbx

  v4 = in_rUserparams;
  v5 = in_GameObject;
  v6 = in_pParentCtx;
  v7 = this;
  if ( !this->m_markers.m_uLength )
    return 0i64;
  v9 = (CAkSegmentCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v9 )
  {
    CAkSegmentCtx::CAkSegmentCtx(v9, v7, (CAkMusicCtx *)&v6->vfptr);
    v11 = (CAkMusicCtx *)&v10->vfptr;
    if ( !v10 )
      return v11;
    ++v10->m_uRefCount;
    if ( (unsigned int)CAkSegmentCtx::Init(v10, v5, v4) == 1 )
      return v11;
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v11);
    CAkMusicCtx::Release(v11);
  }
  return 0i64;
}

// File Line: 257
// RVA: 0xAB06B0
signed __int64 __fastcall CAkMusicSegment::CanAddChild(CAkMusicSegment *this, CAkParameterNodeBase *in_pAudioNode)
{
  CAkMusicSegment *v2; // rsi
  CAkParameterNodeBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int v7; // edi

  v2 = this;
  v3 = in_pAudioNode;
  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release((CAkIndexable *)in_pAudioNode);
  if ( (unsigned __int16)v2->vfptr[20].Release((CAkIndexable *)&v2->vfptr) >= 0xFFFFu )
    return 9i64;
  if ( v5 != 6 )
    return 4i64;
  if ( v3->m_pParentNode )
    return 21i64;
  v7 = v3->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &v2->m_mapChildId,
         v7) )
  {
    return 5i64;
  }
  if ( v2->key == v7 )
    v4 = 23;
  return v4;
}

// File Line: 288
// RVA: 0xAB1300
signed __int64 __fastcall CAkMusicSegment::PlayInternal(CAkMusicSegment *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rdi
  CAkMatrixAwareCtx *v3; // rax
  CAkMusicCtx *v4; // rbx
  TransParams *v5; // rdx
  __int64 v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h]

  v2 = in_rPBIParams;
  v3 = (CAkMatrixAwareCtx *)CAkMusicSegment::CreateSegmentContext(
                              this,
                              0i64,
                              in_rPBIParams->pGameObj,
                              &in_rPBIParams->userParams);
  v4 = (CAkMusicCtx *)&v3->vfptr;
  if ( !v3 )
    return 2i64;
  v5 = v2->pTransitionParameters;
  in_fadeParams.transitionTime = v5->TransitionTime;
  in_fadeParams.eFadeCurve = v5->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(v3);
  CAkMusicCtx::_Play(v4, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 327
// RVA: 0xAB1600
signed __int64 __fastcall CAkMusicSegment::SetMarkers(CAkMusicSegment *this, AkMusicMarkerWwise *in_pArrayMarkers, unsigned int in_ulNumMarkers)
{
  AkArray<AkMusicMarker,AkMusicMarker const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v3; // rbx
  __int64 v4; // rdi
  AkMusicMarkerWwise *v5; // rsi
  AkMusicMarker *v6; // rax
  unsigned int v7; // er9
  signed __int64 v8; // r10
  signed __int64 v9; // rdx
  unsigned int v10; // eax
  __int64 v11; // r8
  unsigned int v12; // eax
  signed __int64 v13; // rcx
  double v15; // xmm1_8
  double v16; // xmm0_8
  unsigned int v17; // eax
  signed __int64 v18; // rcx
  double v19; // xmm1_8
  double v20; // xmm0_8
  unsigned int v21; // eax
  signed __int64 v22; // rcx
  double v23; // xmm1_8
  double v24; // xmm0_8
  unsigned int v25; // eax
  signed __int64 v26; // rcx
  double v27; // xmm1_8
  double v28; // xmm0_8
  __int64 v29; // r8
  signed __int64 v30; // rdx
  unsigned int v31; // eax
  signed __int64 v32; // rcx
  double v33; // xmm1_8
  double v34; // xmm0_8

  v3 = &this->m_markers;
  v4 = in_ulNumMarkers;
  v5 = in_pArrayMarkers;
  if ( this->m_markers.m_pItems )
  {
    AkArray<AkMusicMarker,AkMusicMarker const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(&this->m_markers);
    AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pItems);
    v3->m_pItems = 0i64;
    v3->m_ulReserved = 0;
  }
  if ( (_DWORD)v4 )
  {
    v6 = (AkMusicMarker *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16 * v4);
    v3->m_pItems = v6;
    if ( !v6 )
      return 2i64;
    v3->m_ulReserved = v4;
  }
  v7 = 0;
  v8 = 0i64;
  if ( (signed int)v4 >= 4 )
  {
    v9 = (signed __int64)&v5->pszName;
    v10 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v11 = v10;
    v7 = 4 * v10;
    v8 = 4i64 * v10;
    do
    {
      v12 = v3->m_uLength;
      if ( v12 >= v3->m_ulReserved )
      {
        v13 = 0i64;
      }
      else
      {
        v3->m_uLength = v12 + 1;
        v13 = (signed __int64)&v3->m_pItems[v12];
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *(_QWORD *)(v13 + 8) = 0i64;
        }
      }
      *(_DWORD *)v13 = *(_DWORD *)(v9 - 16);
      v15 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * *(double *)(v9 - 8) * 0.001;
      if ( v15 <= 0.0 )
        v16 = DOUBLE_N0_5;
      else
        v16 = DOUBLE_0_5;
      *(_DWORD *)(v13 + 4) = (signed int)(v16 + v15);
      *(_QWORD *)(v13 + 8) = *(_QWORD *)v9;
      v17 = v3->m_uLength;
      if ( v17 >= v3->m_ulReserved )
      {
        v18 = 0i64;
      }
      else
      {
        v3->m_uLength = v17 + 1;
        v18 = (signed __int64)&v3->m_pItems[v17];
        if ( v18 )
        {
          *(_QWORD *)v18 = 0i64;
          *(_QWORD *)(v18 + 8) = 0i64;
        }
      }
      *(_DWORD *)v18 = *(_DWORD *)(v9 + 8);
      v19 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * *(double *)(v9 + 16) * 0.001;
      if ( v19 <= 0.0 )
        v20 = DOUBLE_N0_5;
      else
        v20 = DOUBLE_0_5;
      *(_DWORD *)(v18 + 4) = (signed int)(v20 + v19);
      *(_QWORD *)(v18 + 8) = *(_QWORD *)(v9 + 24);
      v21 = v3->m_uLength;
      if ( v21 >= v3->m_ulReserved )
      {
        v22 = 0i64;
      }
      else
      {
        v3->m_uLength = v21 + 1;
        v22 = (signed __int64)&v3->m_pItems[v21];
        if ( v22 )
        {
          *(_QWORD *)v22 = 0i64;
          *(_QWORD *)(v22 + 8) = 0i64;
        }
      }
      *(_DWORD *)v22 = *(_DWORD *)(v9 + 32);
      v23 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * *(double *)(v9 + 40) * 0.001;
      if ( v23 <= 0.0 )
        v24 = DOUBLE_N0_5;
      else
        v24 = DOUBLE_0_5;
      *(_DWORD *)(v22 + 4) = (signed int)(v24 + v23);
      *(_QWORD *)(v22 + 8) = *(_QWORD *)(v9 + 48);
      v25 = v3->m_uLength;
      if ( v25 >= v3->m_ulReserved )
      {
        v26 = 0i64;
      }
      else
      {
        v3->m_uLength = v25 + 1;
        v26 = (signed __int64)&v3->m_pItems[v25];
        if ( v26 )
        {
          *(_QWORD *)v26 = 0i64;
          *(_QWORD *)(v26 + 8) = 0i64;
        }
      }
      *(_DWORD *)v26 = *(_DWORD *)(v9 + 56);
      v27 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * *(double *)(v9 + 64) * 0.001;
      if ( v27 <= 0.0 )
        v28 = DOUBLE_N0_5;
      else
        v28 = DOUBLE_0_5;
      v9 += 96i64;
      *(_DWORD *)(v26 + 4) = (signed int)(v28 + v27);
      *(_QWORD *)(v26 + 8) = *(_QWORD *)(v9 - 24);
      --v11;
    }
    while ( v11 );
  }
  if ( v7 < (unsigned int)v4 )
  {
    v29 = (unsigned int)v4 - v7;
    v30 = (signed __int64)v5 + 8 * (v8 + 2 * (v8 + 1));
    do
    {
      v31 = v3->m_uLength;
      if ( v31 >= v3->m_ulReserved )
      {
        v32 = 0i64;
      }
      else
      {
        v3->m_uLength = v31 + 1;
        v32 = (signed __int64)&v3->m_pItems[v31];
        if ( v32 )
        {
          *(_QWORD *)v32 = 0i64;
          *(_QWORD *)(v32 + 8) = 0i64;
        }
      }
      *(_DWORD *)v32 = *(_DWORD *)(v30 - 16);
      v33 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * *(double *)(v30 - 8) * 0.001;
      if ( v33 <= 0.0 )
        v34 = DOUBLE_N0_5;
      else
        v34 = DOUBLE_0_5;
      v30 += 24i64;
      *(_DWORD *)(v32 + 4) = (signed int)(v34 + v33);
      *(_QWORD *)(v32 + 8) = *(_QWORD *)(v30 - 24);
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
  CAkMusicTrack *result; // rax

  if ( in_uIndex >= this->m_mapChildId.m_uLength )
    result = 0i64;
  else
    result = (CAkMusicTrack *)this->m_mapChildId.m_pItems[in_uIndex];
  return result;
}

// File Line: 362
// RVA: 0xAB0BB0
int __fastcall CAkMusicSegment::GetExitSyncPos(CAkMusicSegment *this, unsigned int in_uSrcMinTime, AkSyncType in_eSyncType, unsigned int *io_uCueFilterHash, bool in_bSkipEntryCue, unsigned int *out_uExitSyncPos)
{
  unsigned int v6; // ebx
  unsigned int *v7; // rsi
  AkMusicMarker *v8; // r9
  CAkMusicSegment *v9; // rdi
  signed int v10; // er10
  unsigned int v11; // edx
  CAkParameterNodeBase **v12; // rax
  unsigned int v13; // edx
  int v14; // er8
  unsigned int v15; // er11
  BOOL v16; // er10
  int v18; // edx
  unsigned int *v19; // r8
  unsigned int v20; // er9
  unsigned int v21; // eax
  int v22; // edx
  unsigned int v23; // ecx

  v6 = in_uSrcMinTime;
  v7 = io_uCueFilterHash;
  v8 = this->m_markers.m_pItems;
  v9 = this;
  v10 = 2;
  v11 = *((_DWORD *)&v8[this->m_markers.m_uLength] - 3) - v8->uPosition;
  if ( v6 <= v11 )
  {
    switch ( 0x40000000 )
    {
      case 0:
        *v7 = 0;
        *out_uExitSyncPos = v6;
        break;
      case 1:
        v12 = CAkMusicNode::GetMusicGrid((CAkMusicNode *)&this->vfptr);
        v13 = *((_DWORD *)v12 + 3);
        v14 = *((_DWORD *)v12 + 2);
        if ( in_bSkipEntryCue )
          ++v6;
        v15 = *((_DWORD *)&v9->m_markers.m_pItems[v9->m_markers.m_uLength] - 3) - v9->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = v13;
        if ( v14 )
        {
          if ( v13 <= v6 )
          {
            do
              v13 += v14;
            while ( v13 <= v6 );
            *out_uExitSyncPos = v13;
          }
        }
        else
        {
          *out_uExitSyncPos = v6 + 1;
        }
        v16 = *out_uExitSyncPos > v15;
        *v7 = 0;
        return v16 + 1;
      case 2:
        v22 = *((_DWORD *)CAkMusicNode::GetMusicGrid((CAkMusicNode *)&this->vfptr) + 1);
        if ( in_bSkipEntryCue )
          ++v6;
        v19 = out_uExitSyncPos;
        v20 = *((_DWORD *)&v9->m_markers.m_pItems[v9->m_markers.m_uLength] - 3) - v9->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = 0;
        if ( !v22 )
          goto LABEL_18;
        v21 = 0;
        do
          v21 += v22;
        while ( v21 <= v6 );
        goto LABEL_19;
      case 3:
        v18 = *(_DWORD *)CAkMusicNode::GetMusicGrid((CAkMusicNode *)&this->vfptr);
        if ( in_bSkipEntryCue )
          ++v6;
        v19 = out_uExitSyncPos;
        v20 = *((_DWORD *)&v9->m_markers.m_pItems[v9->m_markers.m_uLength] - 3) - v9->m_markers.m_pItems->uPosition;
        *out_uExitSyncPos = 0;
        if ( v18 )
        {
          v21 = 0;
          do
            v21 += v18;
          while ( v21 <= v6 );
        }
        else
        {
LABEL_18:
          v21 = v6 + 1;
        }
LABEL_19:
        *v19 = v21;
        *v7 = 0;
        return (v21 > v20) + 1;
      case 4:
        v23 = CAkMusicSegment::GetNextMarkerPosition(this, v6, v7, in_bSkipEntryCue);
        goto LABEL_32;
      case 5:
        return CAkMusicSegment::GetNextUserMarkerPosition(this, v6, v7, out_uExitSyncPos);
      case 6:
        if ( v6 || in_bSkipEntryCue )
          return v10;
        v23 = 0;
        *v7 = v8->id;
LABEL_32:
        *out_uExitSyncPos = v23;
        break;
      case 7:
        *out_uExitSyncPos = v11;
        *v7 = this->m_markers.m_pItems[this->m_markers.m_uLength - 1].id;
        break;
      default:
        return v10;
    }
    v10 = 1;
  }
  return v10;
}

// File Line: 443
// RVA: 0xAB0AF0
void __fastcall CAkMusicSegment::GetEntrySyncPos(CAkMusicSegment *this, AkMusicTransDestRule *in_rule, unsigned int in_uMinimumEntryPosition, unsigned int in_uCueHashForMatchSrc, unsigned int *out_uSelectedCueHash, unsigned int *out_uRequiredEntryPosition)
{
  CAkMusicSegment *v6; // r11
  unsigned int v7; // er10
  unsigned int v8; // ecx
  __int16 v9; // cx
  __int16 v10; // ax
  bool v11; // r9

  v6 = this;
  v7 = in_uCueHashForMatchSrc;
  v8 = *((_DWORD *)&this->m_markers.m_pItems[this->m_markers.m_uLength] - 3) - this->m_markers.m_pItems->uPosition;
  if ( v8 )
    *out_uRequiredEntryPosition = in_uMinimumEntryPosition % v8;
  else
    *out_uRequiredEntryPosition = 0;
  *out_uSelectedCueHash = 0;
  v9 = *((_WORD *)in_rule + 10);
  v10 = *((_WORD *)in_rule + 10) & 7;
  if ( v9 & 7 )
  {
    if ( v10 == 2 )
    {
      if ( !(v9 & 0x10) )
        v7 = in_rule->uCueFilterHash;
      v11 = 0;
    }
    else
    {
      if ( v10 != 3 )
        return;
      if ( !(v9 & 0x10) )
        v7 = in_rule->uCueFilterHash;
      v11 = 1;
    }
    *out_uRequiredEntryPosition = CAkMusicSegment::GetRandomCue(
                                    v6,
                                    *out_uRequiredEntryPosition,
                                    v7,
                                    v11,
                                    out_uSelectedCueHash);
  }
  else if ( !in_uMinimumEntryPosition )
  {
    *out_uSelectedCueHash = v6->m_markers.m_pItems->id;
  }
}

// File Line: 480
// RVA: 0xAB1060
__int64 __fastcall CAkMusicSegment::GetRandomCue(CAkMusicSegment *this, unsigned int in_uMinPosition, unsigned int in_uCueFilter, bool in_bAvoidEntryCue, unsigned int *out_uSelectedCueHash)
{
  unsigned int v5; // esi
  AkMusicMarker *v6; // r8
  unsigned int v7; // edx
  bool v8; // zf
  unsigned int v9; // ebx
  unsigned int v10; // er9
  CAkMusicSegment *v11; // rbp
  unsigned int *v12; // rax
  unsigned int v13; // edi
  unsigned int v14; // ecx
  AkMusicMarker *v15; // rax
  __int64 v16; // rcx
  unsigned int v17; // edx
  signed __int64 v18; // rdx
  signed __int64 v19; // rdx
  __int64 result; // rax

  v5 = in_uCueFilter;
  v6 = this->m_markers.m_pItems;
  v7 = v6->uPosition + in_uMinPosition;
  v8 = in_bAvoidEntryCue == 0;
  v9 = in_bAvoidEntryCue != 0;
  v10 = this->m_markers.m_uLength - 1;
  v11 = this;
  if ( v9 < v10 )
  {
    v12 = &v6[!v8].uPosition;
    do
    {
      if ( *v12 >= v7 )
        break;
      ++v9;
      v12 += 4;
    }
    while ( v9 < v10 );
  }
  if ( v5 )
  {
    v13 = 0;
    v14 = v9;
    if ( !v9 )
    {
      v13 = 1;
      v14 = 1;
    }
    if ( v14 < v10 )
    {
      v15 = &v6[v14];
      v16 = v10 - v14;
      do
      {
        if ( v15->id == v5 )
          ++v13;
        ++v15;
        --v16;
      }
      while ( v16 );
    }
  }
  else
  {
    v13 = v10 - v9;
  }
  if ( v13 )
  {
    v17 = rand() % v13;
    if ( v5 )
    {
      if ( v9 )
        goto LABEL_20;
      if ( !v17 )
      {
LABEL_24:
        v18 = 0i64;
        goto LABEL_27;
      }
      --v17;
      v9 = 1;
      while ( 1 )
      {
LABEL_20:
        if ( v11->m_markers.m_pItems[v9].id == v5 )
        {
          if ( !v17 )
          {
            v18 = v9;
            goto LABEL_27;
          }
          --v17;
        }
        if ( ++v9 >= v11->m_markers.m_uLength )
          goto LABEL_24;
      }
    }
    v18 = v9 + v17;
LABEL_27:
    v19 = v18;
    *out_uSelectedCueHash = v11->m_markers.m_pItems[v19].id;
    result = v11->m_markers.m_pItems[v19].uPosition - v11->m_markers.m_pItems->uPosition;
  }
  else
  {
    *out_uSelectedCueHash = v6->id;
    result = 0i64;
  }
  return result;
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
  return this->m_uDuration - *((_DWORD *)&this->m_markers.m_pItems[this->m_markers.m_uLength] - 3);
}

// File Line: 609
// RVA: 0xAB0690
__int64 __fastcall CAkMusicSegment::ActiveDuration(CAkMusicSegment *this)
{
  return *((_DWORD *)&this->m_markers.m_pItems[this->m_markers.m_uLength] - 3) - this->m_markers.m_pItems->uPosition;
}

// File Line: 633
// RVA: 0xAB0E00
__int64 __fastcall CAkMusicSegment::GetNextMarkerPosition(CAkMusicSegment *this, int in_iPosition, unsigned int *io_uCueFilterHash, bool in_bDoSkipEntryCue)
{
  CAkMusicSegment *v4; // rbx
  AkMusicMarker *v5; // rcx
  unsigned int *v6; // r10
  AkMusicMarker *v7; // rax
  signed __int64 v8; // r8
  __int64 result; // rax

  v4 = this;
  v5 = this->m_markers.m_pItems;
  v6 = io_uCueFilterHash;
  v7 = v5;
  if ( in_bDoSkipEntryCue )
    v7 = v5 + 1;
  v8 = (signed __int64)&v5[v4->m_markers.m_uLength];
  if ( v7 == (AkMusicMarker *)v8 )
  {
LABEL_8:
    *v6 = *(_DWORD *)(v8 - 16);
    result = *((_DWORD *)&v4->m_markers.m_pItems[v4->m_markers.m_uLength] - 3) - v4->m_markers.m_pItems->uPosition;
  }
  else
  {
    while ( v7->uPosition < in_iPosition + v5->uPosition || *v6 && v7->id != *v6 )
    {
      ++v7;
      if ( v7 == (AkMusicMarker *)v8 )
        goto LABEL_8;
    }
    *v6 = v7->id;
    result = v7->uPosition - v4->m_markers.m_pItems->uPosition;
  }
  return result;
}

// File Line: 672
// RVA: 0xAB0E90
signed __int64 __fastcall CAkMusicSegment::GetNextUserMarkerPosition(CAkMusicSegment *this, unsigned int in_uPosition, unsigned int *io_uCueFilterHash, unsigned int *out_uMarkerPosition)
{
  AkMusicMarker *v4; // r11
  unsigned int v5; // eax
  unsigned int v6; // er10
  signed __int64 result; // rax
  __int64 v8; // rdx

  v4 = this->m_markers.m_pItems;
  v5 = 1;
  v6 = this->m_markers.m_uLength - 2;
  if ( v6 < 1 )
    return 2i64;
  while ( v4[v5].uPosition <= in_uPosition + v4->uPosition || *io_uCueFilterHash && v4[v5].id != *io_uCueFilterHash )
  {
    if ( ++v5 > v6 )
      return 2i64;
  }
  v8 = v5;
  result = 1i64;
  v8 *= 2i64;
  *io_uCueFilterHash = *(&v4->id + 2 * v8);
  *out_uMarkerPosition = *(&this->m_markers.m_pItems->uPosition + 2 * v8) - this->m_markers.m_pItems->uPosition;
  return result;
}

// File Line: 707
// RVA: 0xAB1240
void __fastcall CAkMusicSegment::NotifyUserCuesInRange(CAkMusicSegment *this, unsigned int in_playingID, AkMusicGrid *in_rGrid, int in_iStartPosition, unsigned int in_uRangeSize)
{
  unsigned int v5; // edi
  AkMusicGrid *v6; // r15
  unsigned int v7; // er12
  CAkMusicSegment *v8; // r14
  unsigned int v9; // ebp
  unsigned int v10; // esi
  unsigned int i; // ebx
  signed __int64 v12; // r9
  unsigned int v13; // eax

  v5 = this->m_markers.m_pItems->uPosition + in_iStartPosition;
  v6 = in_rGrid;
  v7 = in_playingID;
  v8 = this;
  if ( (v5 & 0x80000000) != 0 )
  {
    v9 = v5 + in_uRangeSize;
    if ( (signed int)(v5 + in_uRangeSize) <= 0 )
      return;
    v5 = 0;
  }
  else
  {
    v9 = v5 + in_uRangeSize;
  }
  v10 = this->m_markers.m_uLength - 2;
  for ( i = 1; i <= v10; ++i )
  {
    v12 = (signed __int64)&v8->m_markers.m_pItems[i];
    v13 = *(_DWORD *)(v12 + 4);
    if ( v13 >= v5 )
    {
      if ( v13 >= v9 )
        return;
      CAkPlayingMgr::NotifyMusicUserCues(g_pPlayingMgr, v7, v6, *(char **)(v12 + 8));
    }
  }
}

// File Line: 757
// RVA: 0xAB0F20
void __fastcall CAkMusicSegment::GetNumMusicGridInRange(CAkMusicSegment *this, int in_iStartPosition, unsigned int in_uRangeSize, unsigned int *out_uNumBars, unsigned int *out_uNumBeats, unsigned int *out_uNumGrids)
{
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int *v8; // r14
  unsigned int v9; // edi
  unsigned int v10; // edx
  CAkParameterNodeBase **v11; // r8
  unsigned int v12; // er9
  unsigned int v13; // er10
  unsigned int v14; // er9
  unsigned int v15; // er10
  unsigned int v16; // er9

  v6 = 0;
  v7 = in_uRangeSize;
  v8 = out_uNumBars;
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
  v10 = *((_DWORD *)&this->m_markers.m_pItems[this->m_markers.m_uLength] - 3) - this->m_markers.m_pItems->uPosition;
  if ( v9 + v7 > v10 )
  {
    if ( v9 >= v10 )
      goto LABEL_3;
    v7 = v10 - v9;
  }
  v11 = CAkMusicNode::GetMusicGrid((CAkMusicNode *)&this->vfptr);
  v12 = *((_DWORD *)v11 + 1);
  if ( v12 )
    v13 = ((v12 + v9) % v12 + v12 - 1 + v7) / v12 - ((v12 + v9) % v12 + v12 - 1) / v12;
  else
    v13 = 0;
  *v8 = v13;
  if ( *(_DWORD *)v11 )
  {
    v14 = *(_DWORD *)v11;
    v15 = ((v14 + v9) % v14 + v14 - 1 + v7) / v14 - ((v14 + v9) % v14 + v14 - 1) / v14;
  }
  else
  {
    v15 = 0;
  }
  *out_uNumBeats = v15;
  v16 = *((_DWORD *)v11 + 2);
  if ( v16 )
    v6 = ((v9 + v16 - *((_DWORD *)v11 + 3)) % v16 + v16 - 1 + v7) / v16
       - ((v9 + v16 - *((_DWORD *)v11 + 3)) % v16 + v16 - 1) / v16;
  *out_uNumGrids = v6;
}

// File Line: 822
// RVA: 0xAB0A60
__int64 __fastcall CAkMusicSegment::GetClosestCuePosition(CAkMusicSegment *this, int in_iPosition)
{
  AkMusicMarker *v2; // rbx
  unsigned int v3; // er11
  signed __int64 v4; // r8
  unsigned int v5; // esi
  unsigned int *v6; // r9
  unsigned int v7; // ecx
  unsigned int v8; // er11
  int v9; // er10
  int v10; // eax
  int v12; // [rsp+10h] [rbp+10h]

  v2 = this->m_markers.m_pItems;
  v3 = this->m_markers.m_uLength;
  v4 = 0i64;
  v5 = v2->uPosition;
  v6 = &v2->uPosition;
  v7 = 0;
  v8 = v3 - 1;
  if ( v8 )
  {
    v9 = v12;
    do
    {
      v10 = abs(*v6 - (v5 + in_iPosition));
      if ( !v4 || v10 < v9 )
      {
        v9 = v10;
        v4 = (signed __int64)&v2[v7];
      }
      ++v7;
      v6 += 4;
    }
    while ( v7 < v8 );
  }
  return *(_DWORD *)(v4 + 4) - v5;
}

// File Line: 848
// RVA: 0xAB11A0
char __fastcall CAkMusicSegment::GetStateSyncTypes(CAkMusicSegment *this, unsigned int in_stateGroupID, CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes)
{
  CAkParameterNodeBase **v3; // rbx
  CAkParameterNodeBase::CAkStateSyncArray *v4; // rsi
  unsigned int v5; // ebp
  CAkMusicSegment *v6; // rdi

  v3 = this->m_mapChildId.m_pItems;
  v4 = io_pSyncTypes;
  v5 = in_stateGroupID;
  v6 = this;
  if ( v3 == &v3[this->m_mapChildId.m_uLength] )
    return CAkParameterNodeBase::GetStateSyncTypes((CAkParameterNodeBase *)&v6->vfptr, v5, v4, 0);
  while ( !CAkMusicTrack::GetStateSyncTypes((CAkMusicTrack *)*v3, v5, v4) )
  {
    ++v3;
    if ( v3 == &v6->m_mapChildId.m_pItems[v6->m_mapChildId.m_uLength] )
      return CAkParameterNodeBase::GetStateSyncTypes((CAkParameterNodeBase *)&v6->vfptr, v5, v4, 0);
  }
  return 1;
}

