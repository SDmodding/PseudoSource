// File Line: 31
// RVA: 0xA87560
CAkIndexable *__fastcall CAkAttenuation::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkIndexable *v2; // rax
  CAkIndexable *v3; // rbx

  v1 = in_ulID;
  v2 = (CAkIndexable *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x90ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkIndexable::CAkIndexable(v2, v1);
  v3->vfptr = (CAkIndexableVtbl *)&CAkAttenuation::`vftable;
  *(_QWORD *)&v3[1].key = 0i64;
  v3[2].vfptr = 0i64;
  v3[2].pNextItem = 0i64;
  *(_QWORD *)&v3[2].key = 0i64;
  v3[3].vfptr = 0i64;
  v3[3].pNextItem = 0i64;
  *(_QWORD *)&v3[3].key = 0i64;
  v3[4].vfptr = 0i64;
  v3[4].pNextItem = 0i64;
  *(_QWORD *)&v3[4].key = 0i64;
  v3[5].pNextItem = 0i64;
  *(_QWORD *)&v3[5].key = 0i64;
  if ( CAkAttenuation::Init((CAkAttenuation *)v3) == 1 )
    return v3;
  v3->vfptr->Release(v3);
  return 0i64;
}

// File Line: 45
// RVA: 0xA87810
unsigned int __fastcall CAkAttenuation::SetInitialValues(CAkAttenuation *this, char *in_pData, unsigned int in_ulDataSize)
{
  char v3; // al
  CAkAttenuation *v4; // rsi
  float *v5; // rbx
  float v6; // xmm0_4
  char v7; // al
  unsigned int v8; // er14
  AkRTPCGraphPointBase<float> *v9; // rbx
  unsigned int v10; // ebp
  unsigned int v11; // er12
  AkCurveScaling *v12; // rdi
  __int64 v13; // r15
  AkCurveScaling v14; // er9
  AkRTPCGraphPointBase<float> *v15; // rbx
  unsigned int result; // eax
  AKRESULT v17; // er8
  unsigned int i; // edx
  __int64 v19; // rax
  unsigned int v20; // eax
  signed __int64 v21; // rbx
  unsigned int v22; // ebp
  unsigned int in_ulConversionArraySize; // eax
  AkCurveScaling in_eScaling; // ecx
  unsigned int v25; // edx
  AkRTPC_ParameterID v26; // er8
  unsigned int v27; // er9
  AkRTPCGraphPointBase<float> *in_pArrayConversion; // rbx
  __int64 v29; // rdi

  v3 = in_pData[4];
  *((_BYTE *)this + 125) &= 0xFEu;
  v4 = this;
  v5 = (float *)(in_pData + 5);
  *((_BYTE *)this + 125) |= v3 != 0;
  if ( *((_BYTE *)this + 125) & 1 )
  {
    this->m_ConeParams.fInsideAngle = AkMath::ToRadians(*v5) * 0.5;
    v6 = AkMath::ToRadians(v5[1]);
    v5 += 4;
    v4->m_ConeParams.fOutsideAngle = v6 * 0.5;
    v4->m_ConeParams.fOutsideVolume = *(v5 - 2);
    v4->m_ConeParams.LoPass = *(v5 - 1);
  }
  v7 = *(_BYTE *)v5;
  v8 = 0;
  v9 = (AkRTPCGraphPointBase<float> *)((char *)v5 + 6);
  v4->m_curveToUse[0] = v7;
  v10 = 0;
  v4->m_curveToUse[1] = HIBYTE(v9[-1].To);
  v4->m_curveToUse[2] = v9[-1].Interp;
  v4->m_curveToUse[3] = BYTE1(v9[-1].Interp);
  v4->m_curveToUse[4] = BYTE2(v9[-1].Interp);
  v11 = HIBYTE(v9[-1].Interp);
  if ( !HIBYTE(v9[-1].Interp) )
    return 2;
  v12 = &v4->m_curves[0].m_eScaling;
  while ( 1 )
  {
    v13 = *(unsigned __int16 *)((char *)&v9->From + 1);
    v14 = LOBYTE(v9->From);
    v15 = (AkRTPCGraphPointBase<float> *)((char *)v9 + 3);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(&v4->m_curves[v10], v15, v13, v14);
    v17 = result;
    if ( result != 1 )
      break;
    if ( (unsigned __int8)v4->m_curveToUse[0] == v10
      || (unsigned __int8)v4->m_curveToUse[1] == v10
      || (unsigned __int8)v4->m_curveToUse[2] == v10 )
    {
      if ( *v12 )
      {
        if ( *v12 == 2 )
        {
          for ( i = 0;
                i < *((_DWORD *)v12 - 1);
                *(float *)(*(_QWORD *)(v12 - 3) + 12 * v19 + 4) = *(float *)(*(_QWORD *)(v12 - 3) + 12 * v19 + 4) + 1.0 )
          {
            v19 = i++;
          }
          *v12 = 0;
        }
      }
      else
      {
        *v12 = 4;
      }
    }
    ++v10;
    v12 += 4;
    v9 = &v15[v13];
    if ( v10 >= v11 )
    {
      v20 = LOWORD(v9->From);
      v21 = (signed __int64)&v9->From + 2;
      v22 = v20;
      if ( !v20 )
        return v17;
      do
      {
        in_ulConversionArraySize = *(unsigned __int16 *)(v21 + 13);
        in_eScaling = *(unsigned __int8 *)(v21 + 12);
        v25 = *(_DWORD *)v21;
        v26 = *(_DWORD *)(v21 + 4);
        v27 = *(_DWORD *)(v21 + 8);
        in_pArrayConversion = (AkRTPCGraphPointBase<float> *)(v21 + 15);
        v29 = in_ulConversionArraySize;
        result = CAkAttenuation::SetRTPC(v4, v25, v26, v27, in_eScaling, in_pArrayConversion, in_ulConversionArraySize);
        if ( result != 1 )
          break;
        ++v8;
        v21 = (signed __int64)&in_pArrayConversion[v29];
      }
      while ( v8 < v22 );
      return result;
    }
  }
  return result;
}

// File Line: 200
// RVA: 0xA876E0
signed __int64 __fastcall CAkAttenuation::Init(CAkAttenuation *this)
{
  CAkAttenuation *v1; // rdi
  signed __int64 v2; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v3; // rdx
  CAkIndexItem<CAkAttenuation *> *v4; // rbx
  signed __int64 v5; // rdx

  v1 = this;
  v2 = 0i64;
  v3 = this->m_curves;
  do
  {
    this->m_curveToUse[v2++] = -1;
    v3->m_pArrayGraphPoints = 0i64;
    ++v3;
  }
  while ( v2 < 5 );
  v4 = &g_pIndex->m_idxAttenuations;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v5 = (signed __int64)v4 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v5 + 40);
  *(_QWORD *)(v5 + 40) = v1;
  ++v4->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v4->m_IndexLock.m_csLock);
  return 1i64;
}

// File Line: 212
// RVA: 0xA873B0
void __fastcall CAkAttenuation::~CAkAttenuation(CAkAttenuation *this)
{
  CAkAttenuation *v1; // rsi
  CAkAttenuation::RTPCSubs *v2; // rdx
  signed __int64 v3; // rbx
  signed __int64 v4; // rdi

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkAttenuation::`vftable;
  CAkAttenuation::ClearRTPCs(this);
  v2 = v1->m_rtpcsubs.m_pItems;
  if ( v2 )
  {
    v1->m_rtpcsubs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_rtpcsubs.m_pItems = 0i64;
    v1->m_rtpcsubs.m_ulReserved = 0;
  }
  v3 = (signed __int64)v1->m_curves;
  v4 = 5i64;
  do
  {
    if ( *(_QWORD *)v3 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v3);
      *(_QWORD *)v3 = 0i64;
    }
    *(_QWORD *)(v3 + 8) = 0i64;
    v3 += 16i64;
    --v4;
  }
  while ( v4 );
  CAkIndexable::~CAkIndexable((CAkIndexable *)&v1->vfptr);
}

// File Line: 227
// RVA: 0xA874D0
void __fastcall CAkAttenuation::ClearRTPCs(CAkAttenuation *this)
{
  CAkAttenuation::RTPCSubs *v1; // rax
  CAkAttenuation *v2; // rsi
  signed __int64 v3; // rbx

  v1 = this->m_rtpcsubs.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_rtpcsubs.m_uLength] )
  {
    this->m_rtpcsubs.m_uLength = 0;
  }
  else
  {
    v3 = (signed __int64)&v1->ConversionTable;
    do
    {
      if ( *(_QWORD *)v3 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v3);
        *(_QWORD *)v3 = 0i64;
      }
      *(_QWORD *)(v3 + 8) = 0i64;
      v3 += 32i64;
    }
    while ( (CAkAttenuation::RTPCSubs *)(v3 - 16) != &v2->m_rtpcsubs.m_pItems[v2->m_rtpcsubs.m_uLength] );
    v2->m_rtpcsubs.m_uLength = 0;
  }
}

// File Line: 270
// RVA: 0xA87480
__int64 __fastcall CAkAttenuation::AddRef(CAkAttenuation *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkAttenuation *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxAttenuations.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 276
// RVA: 0xA87780
__int64 __fastcall CAkAttenuation::Release(CAkAttenuation *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkAttenuation *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxAttenuations, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxAttenuations.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 296
// RVA: 0xA87A10
signed __int64 __fastcall CAkAttenuation::SetRTPC(CAkAttenuation *this, unsigned int in_RTPC_ID, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID, AkCurveScaling in_eScaling, AkRTPCGraphPointBase<float> *in_pArrayConversion, unsigned int in_ulConversionArraySize)
{
  AkRTPC_ParameterID v7; // ebp
  unsigned int v8; // er14
  unsigned int v9; // esi
  CAkAttenuation *v10; // rbx
  AkArray<CAkFxBase::RTPCSubs,CAkFxBase::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *v11; // rbx
  unsigned __int64 v12; // rdi
  unsigned int v13; // eax
  CAkFxBase::RTPCSubs *v14; // rdx
  signed __int64 v15; // rcx
  signed __int64 result; // rax

  v7 = in_ParamID;
  v8 = in_RTPC_ID;
  v9 = in_RTPCCurveID;
  v10 = this;
  CAkAttenuation::UnsetRTPC(this, in_ParamID, in_RTPCCurveID);
  v11 = (AkArray<CAkFxBase::RTPCSubs,CAkFxBase::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *)&v10->m_rtpcsubs;
  v12 = v11->m_uLength;
  if ( v12 >= v11->m_ulReserved
    && !AkArray<CAkAttenuation::RTPCSubs,CAkAttenuation::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          v11,
          2u) )
  {
    return 2i64;
  }
  if ( v12 >= v11->m_ulReserved )
    return 2i64;
  v13 = v11->m_uLength;
  v11->m_uLength = v13 + 1;
  v14 = &v11->m_pItems[v13];
  if ( !v14 )
    return 2i64;
  v15 = (signed __int64)&v14->ConversionTable;
  *(_QWORD *)v15 = 0i64;
  *(_QWORD *)(v15 + 8) = 0i64;
  v14->RTPCCurveID = v7;
  v14->ParamID = v9;
  v14->RTPCID = v8;
  if ( in_pArrayConversion && in_ulConversionArraySize )
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
               (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)v15,
               in_pArrayConversion,
               in_ulConversionArraySize,
               in_eScaling);
  else
    result = 1i64;
  return result;
}

// File Line: 326
// RVA: 0xA87AE0
void __fastcall CAkAttenuation::UnsetRTPC(CAkAttenuation *this, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID)
{
  CAkAttenuation::RTPCSubs *v3; // rax
  unsigned int v4; // er14
  AkRTPC_ParameterID v5; // er15
  CAkAttenuation *v6; // rbp
  signed __int64 v7; // rbx
  void *v8; // rdx
  unsigned __int64 v9; // rcx

  v3 = this->m_rtpcsubs.m_pItems;
  v4 = in_RTPCCurveID;
  v5 = in_ParamID;
  v6 = this;
  if ( v3 != &v3[this->m_rtpcsubs.m_uLength] )
  {
    v7 = (signed __int64)&v3->ConversionTable.m_eScaling;
    do
    {
      if ( *(_DWORD *)(v7 - 24) != v5 || *(_DWORD *)(v7 - 20) != v4 )
      {
        v7 += 32i64;
      }
      else
      {
        v8 = *(void **)(v7 - 12);
        if ( v8 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v8);
          *(_QWORD *)(v7 - 12) = 0i64;
        }
        *(_QWORD *)(v7 - 4) = 0i64;
        v9 = (unsigned __int64)&v6->m_rtpcsubs.m_pItems[v6->m_rtpcsubs.m_uLength - 1];
        if ( v7 - 28 < v9 )
          qmemcpy(
            (void *)(v7 - 28),
            (const void *)(v7 + 4),
            8 * (((((v9 - (v7 - 28) - 1) >> 3) & 0xFFFFFFFFFFFFFFFCui64) + 4) & 0x1FFFFFFFFFFFFFFCi64));
        --v6->m_rtpcsubs.m_uLength;
      }
    }
    while ( (CAkAttenuation::RTPCSubs *)(v7 - 28) != &v6->m_rtpcsubs.m_pItems[v6->m_rtpcsubs.m_uLength] );
  }
}

