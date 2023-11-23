// File Line: 31
// RVA: 0xA87560
CAkAttenuation *__fastcall CAkAttenuation::Create(unsigned int in_ulID)
{
  CAkIndexable *v2; // rax
  CAkIndexable *v3; // rbx

  v2 = (CAkIndexable *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x90ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkIndexable::CAkIndexable(v2, in_ulID);
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
  if ( CAkAttenuation::Init((CAkAttenuation *)v3) == AK_Success )
    return (CAkAttenuation *)v3;
  v3->vfptr->Release(v3);
  return 0i64;
}

// File Line: 45
// RVA: 0xA87810
unsigned int __fastcall CAkAttenuation::SetInitialValues(
        CAkAttenuation *this,
        char *in_pData,
        unsigned int in_ulDataSize)
{
  char v3; // al
  float *v5; // rbx
  float v6; // xmm0_4
  char v7; // al
  unsigned int v8; // r14d
  AkRTPCGraphPointBase<float> *v9; // rbx
  unsigned int v10; // ebp
  unsigned int Interp_high; // r12d
  AkCurveScaling *p_m_eScaling; // rdi
  __int64 v13; // r15
  AkCurveScaling From_low; // r9d
  AkRTPCGraphPointBase<float> *v15; // rbx
  unsigned int result; // eax
  unsigned int i; // edx
  __int64 v18; // rax
  unsigned int v19; // eax
  unsigned __int8 *v20; // rbx
  unsigned int v21; // ebp
  AkCurveScaling in_eScaling; // ecx
  unsigned int v23; // edx
  AkRTPC_ParameterID v24; // r8d
  unsigned int v25; // r9d
  AkRTPCGraphPointBase<float> *in_pArrayConversion; // rbx
  __int64 v27; // rdi
  unsigned int in_ulConversionArraySize; // [rsp+30h] [rbp-38h]

  v3 = in_pData[4];
  *((_BYTE *)this + 125) &= ~1u;
  v5 = (float *)(in_pData + 5);
  *((_BYTE *)this + 125) |= v3 != 0;
  if ( (*((_BYTE *)this + 125) & 1) != 0 )
  {
    this->m_ConeParams.fInsideAngle = AkMath::ToRadians(*v5) * 0.5;
    v6 = AkMath::ToRadians(v5[1]);
    v5 += 4;
    this->m_ConeParams.fOutsideAngle = v6 * 0.5;
    this->m_ConeParams.fOutsideVolume = *(v5 - 2);
    this->m_ConeParams.LoPass = *(v5 - 1);
  }
  v7 = *(_BYTE *)v5;
  v8 = 0;
  v9 = (AkRTPCGraphPointBase<float> *)((char *)v5 + 6);
  this->m_curveToUse[0] = v7;
  v10 = 0;
  this->m_curveToUse[1] = HIBYTE(v9[-1].To);
  this->m_curveToUse[2] = v9[-1].Interp;
  this->m_curveToUse[3] = BYTE1(v9[-1].Interp);
  this->m_curveToUse[4] = BYTE2(v9[-1].Interp);
  Interp_high = HIBYTE(v9[-1].Interp);
  if ( !HIBYTE(v9[-1].Interp) )
    return 2;
  p_m_eScaling = &this->m_curves[0].m_eScaling;
  while ( 1 )
  {
    v13 = *(unsigned __int16 *)((char *)&v9->From + 1);
    From_low = LOBYTE(v9->From);
    v15 = (AkRTPCGraphPointBase<float> *)((char *)&v9->From + 3);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(&this->m_curves[v10], v15, v13, From_low);
    if ( result != 1 )
      break;
    if ( (unsigned __int8)this->m_curveToUse[0] == v10
      || (unsigned __int8)this->m_curveToUse[1] == v10
      || (unsigned __int8)this->m_curveToUse[2] == v10 )
    {
      if ( *p_m_eScaling )
      {
        if ( *p_m_eScaling == AkCurveScaling_dB )
        {
          for ( i = 0;
                i < *((_DWORD *)p_m_eScaling - 1);
                *(float *)(*(_QWORD *)(p_m_eScaling - 3) + 12 * v18 + 4) = *(float *)(*(_QWORD *)(p_m_eScaling - 3)
                                                                                    + 12 * v18
                                                                                    + 4)
                                                                         + 1.0 )
          {
            v18 = i++;
          }
          *p_m_eScaling = AkCurveScaling_None;
        }
      }
      else
      {
        *p_m_eScaling = AkCurveScaling_dBToLin;
      }
    }
    ++v10;
    p_m_eScaling += 4;
    v9 = &v15[v13];
    if ( v10 >= Interp_high )
    {
      v19 = LOWORD(v9->From);
      v20 = (unsigned __int8 *)&v9->From + 2;
      v21 = v19;
      if ( !v19 )
        return 1;
      do
      {
        in_eScaling = v20[12];
        v23 = *(_DWORD *)v20;
        v24 = *((_DWORD *)v20 + 1);
        v25 = *((_DWORD *)v20 + 2);
        in_ulConversionArraySize = *(unsigned __int16 *)(v20 + 13);
        in_pArrayConversion = (AkRTPCGraphPointBase<float> *)(v20 + 15);
        v27 = in_ulConversionArraySize;
        result = CAkAttenuation::SetRTPC(
                   this,
                   v23,
                   v24,
                   v25,
                   in_eScaling,
                   in_pArrayConversion,
                   in_ulConversionArraySize);
        if ( result != 1 )
          break;
        ++v8;
        v20 = (unsigned __int8 *)&in_pArrayConversion[v27];
      }
      while ( v8 < v21 );
      return result;
    }
  }
  return result;
} __int8 *)&in_pArrayConversion[v27];
      }

// File Line: 200
// RVA: 0xA876E0
__int64 __fastcall CAkAttenuation::Init(CAkAttenuation *this)
{
  __int64 v2; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_curves; // rdx
  CAkIndexItem<CAkAttenuation *> *p_m_idxAttenuations; // rbx
  _RTL_CRITICAL_SECTION_DEBUG **v5; // rdx

  v2 = 0i64;
  m_curves = this->m_curves;
  do
  {
    this->m_curveToUse[v2++] = -1;
    m_curves->m_pArrayGraphPoints = 0i64;
    ++m_curves;
  }
  while ( v2 < 5 );
  p_m_idxAttenuations = &g_pIndex->m_idxAttenuations;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v5 = &p_m_idxAttenuations->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v5[5];
  v5[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxAttenuations->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxAttenuations->m_IndexLock.m_csLock);
  return 1i64;
}

// File Line: 212
// RVA: 0xA873B0
void __fastcall CAkAttenuation::~CAkAttenuation(CAkAttenuation *this)
{
  CAkAttenuation::RTPCSubs *m_pItems; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_curves; // rbx
  __int64 v4; // rdi

  this->vfptr = (CAkIndexableVtbl *)&CAkAttenuation::`vftable;
  CAkAttenuation::ClearRTPCs(this);
  m_pItems = this->m_rtpcsubs.m_pItems;
  if ( m_pItems )
  {
    this->m_rtpcsubs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_rtpcsubs.m_pItems = 0i64;
    this->m_rtpcsubs.m_ulReserved = 0;
  }
  m_curves = this->m_curves;
  v4 = 5i64;
  do
  {
    if ( m_curves->m_pArrayGraphPoints )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_curves->m_pArrayGraphPoints);
      m_curves->m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&m_curves->m_ulArraySize = 0i64;
    ++m_curves;
    --v4;
  }
  while ( v4 );
  CAkIndexable::~CAkIndexable(this);
}

// File Line: 227
// RVA: 0xA874D0
void __fastcall CAkAttenuation::ClearRTPCs(CAkAttenuation *this)
{
  CAkAttenuation::RTPCSubs *m_pItems; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // rbx

  m_pItems = this->m_rtpcsubs.m_pItems;
  if ( m_pItems == &m_pItems[this->m_rtpcsubs.m_uLength] )
  {
    this->m_rtpcsubs.m_uLength = 0;
  }
  else
  {
    p_ConversionTable = &m_pItems->ConversionTable;
    do
    {
      if ( p_ConversionTable->m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, p_ConversionTable->m_pArrayGraphPoints);
        p_ConversionTable->m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&p_ConversionTable->m_ulArraySize = 0i64;
      p_ConversionTable += 2;
    }
    while ( &p_ConversionTable[-1] != (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)&this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength] );
    this->m_rtpcsubs.m_uLength = 0;
  }
}

// File Line: 270
// RVA: 0xA87480
__int64 __fastcall CAkAttenuation::AddRef(CAkAttenuation *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxAttenuations.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 276
// RVA: 0xA87780
__int64 __fastcall CAkAttenuation::Release(CAkAttenuation *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxAttenuations.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxAttenuations, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxAttenuations.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 296
// RVA: 0xA87A10
__int64 __fastcall CAkAttenuation::SetRTPC(
        CAkAttenuation *this,
        unsigned int in_RTPC_ID,
        AkRTPC_ParameterID in_ParamID,
        unsigned int in_RTPCCurveID,
        AkCurveScaling in_eScaling,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        unsigned int in_ulConversionArraySize)
{
  AkArray<CAkFxBase::RTPCSubs,CAkFxBase::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *p_m_rtpcsubs; // rbx
  unsigned __int64 m_uLength; // rdi
  __int64 v13; // rdx
  __int64 v14; // rdx

  CAkAttenuation::UnsetRTPC(this, in_ParamID, in_RTPCCurveID);
  p_m_rtpcsubs = (AkArray<CAkFxBase::RTPCSubs,CAkFxBase::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *)&this->m_rtpcsubs;
  m_uLength = p_m_rtpcsubs->m_uLength;
  if ( m_uLength >= p_m_rtpcsubs->m_ulReserved
    && !AkArray<CAkAttenuation::RTPCSubs,CAkAttenuation::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          p_m_rtpcsubs,
          2u) )
  {
    return 2i64;
  }
  if ( m_uLength >= p_m_rtpcsubs->m_ulReserved )
    return 2i64;
  v13 = p_m_rtpcsubs->m_uLength;
  p_m_rtpcsubs->m_uLength = v13 + 1;
  v14 = (__int64)&p_m_rtpcsubs->m_pItems[v13];
  if ( !v14 )
    return 2i64;
  *(_QWORD *)(v14 + 16) = 0i64;
  *(_QWORD *)(v14 + 24) = 0i64;
  *(_DWORD *)(v14 + 4) = in_ParamID;
  *(_DWORD *)(v14 + 8) = in_RTPCCurveID;
  *(_DWORD *)v14 = in_RTPC_ID;
  if ( in_pArrayConversion && in_ulConversionArraySize )
    return CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
             (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v14 + 16),
             in_pArrayConversion,
             in_ulConversionArraySize,
             in_eScaling);
  else
    return 1i64;
}

// File Line: 326
// RVA: 0xA87AE0
void __fastcall CAkAttenuation::UnsetRTPC(
        CAkAttenuation *this,
        AkRTPC_ParameterID in_ParamID,
        unsigned int in_RTPCCurveID)
{
  CAkAttenuation::RTPCSubs *m_pItems; // rax
  AkCurveScaling *p_m_eScaling; // rbx
  void *v8; // rdx
  CAkAttenuation::RTPCSubs *v9; // rcx

  m_pItems = this->m_rtpcsubs.m_pItems;
  if ( m_pItems != &m_pItems[this->m_rtpcsubs.m_uLength] )
  {
    p_m_eScaling = &m_pItems->ConversionTable.m_eScaling;
    do
    {
      if ( *((_DWORD *)p_m_eScaling - 6) == in_ParamID && *((_DWORD *)p_m_eScaling - 5) == in_RTPCCurveID )
      {
        v8 = *(void **)(p_m_eScaling - 3);
        if ( v8 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v8);
          *(_QWORD *)(p_m_eScaling - 3) = 0i64;
        }
        *(_QWORD *)(p_m_eScaling - 1) = 0i64;
        v9 = &this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength - 1];
        if ( p_m_eScaling - 7 < (AkCurveScaling *)v9 )
          qmemcpy(
            p_m_eScaling - 7,
            p_m_eScaling + 1,
            8
          * (((((unsigned __int64)((char *)v9 - (char *)(p_m_eScaling - 7) - 1) >> 3) & 0xFFFFFFFFFFFFFFFCui64) + 4) & 0x1FFFFFFFFFFFFFFCi64));
        --this->m_rtpcsubs.m_uLength;
      }
      else
      {
        p_m_eScaling += 8;
      }
    }
    while ( p_m_eScaling - 7 != (AkCurveScaling *)&this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength] );
  }
}

