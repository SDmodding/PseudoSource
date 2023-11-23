// File Line: 29
// RVA: 0xA78B10
void __fastcall CAkFxBase::~CAkFxBase(CAkFxBase *this)
{
  CAkFxBase::RTPCSubs *m_pItems; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // rbx
  MapStruct<unsigned long,unsigned long> *v4; // rdx
  AK::IAkPluginParam *m_pParam; // rcx

  this->vfptr = (CAkIndexableVtbl *)&CAkFxBase::`vftable;
  m_pItems = this->m_rtpcsubs.m_pItems;
  if ( m_pItems != &m_pItems[this->m_rtpcsubs.m_uLength] )
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
  }
  if ( this->m_rtpcsubs.m_pItems )
  {
    this->m_rtpcsubs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_rtpcsubs.m_pItems);
    this->m_rtpcsubs.m_pItems = 0i64;
    this->m_rtpcsubs.m_ulReserved = 0;
  }
  v4 = this->m_media.m_pItems;
  if ( v4 )
  {
    this->m_media.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    this->m_media.m_pItems = 0i64;
    this->m_media.m_ulReserved = 0;
  }
  m_pParam = this->m_pParam;
  if ( m_pParam )
    m_pParam->vfptr[2].__vecDelDtor(m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
  CAkIndexable::~CAkIndexable(this);
}

// File Line: 47
// RVA: 0xA79130
__int64 __fastcall CAkFxBase::SetInitialValues(CAkFxBase *this, char *in_pData, unsigned int in_uDataSize)
{
  unsigned int v4; // edx
  __int64 v6; // rdi
  char *v7; // rbx
  unsigned int v8; // ebp
  char *v9; // rbx
  unsigned int v10; // ecx
  unsigned __int8 *v11; // rbx
  __int64 v12; // rdi
  MapStruct<unsigned long,unsigned long> *v13; // rax
  unsigned int v14; // edx
  unsigned int v15; // r8d
  unsigned int v16; // eax
  unsigned __int8 *v17; // rbx
  __int64 v18; // rsi
  AkCurveScaling in_eScaling; // ecx
  unsigned int v20; // edx
  AkRTPC_ParameterID v21; // r8d
  unsigned int v22; // r9d
  AkRTPCGraphPointBase<float> *in_pArrayConversion; // rbx
  __int64 v24; // rdi
  unsigned int in_ulConversionArraySize; // [rsp+30h] [rbp-18h]

  v4 = *((_DWORD *)in_pData + 1);
  v6 = *((unsigned int *)in_pData + 2);
  v7 = in_pData + 12;
  v8 = 1;
  if ( v4 != -1 )
    v8 = CAkFxBase::SetFX(this, v4, v7, v6);
  v9 = &v7[v6];
  if ( v8 != 1 )
    return v8;
  v10 = (unsigned __int8)*v9;
  v11 = (unsigned __int8 *)(v9 + 1);
  v12 = v10;
  if ( (_BYTE)v10 )
  {
    v13 = (MapStruct<unsigned long,unsigned long> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v10);
    this->m_media.m_pItems = v13;
    if ( v13 )
      this->m_media.m_ulReserved = v12;
  }
  if ( (_DWORD)v12 )
  {
    do
    {
      v14 = *v11;
      v15 = *(_DWORD *)(v11 + 1);
      v11 += 5;
      CAkKeyArray<unsigned long,unsigned long,8>::Set(&this->m_media, v14, v15);
      --v12;
    }
    while ( v12 );
  }
  v16 = *(unsigned __int16 *)v11;
  v17 = v11 + 2;
  if ( v16 )
  {
    v18 = v16;
    do
    {
      in_eScaling = v17[12];
      v20 = *(_DWORD *)v17;
      v21 = *((_DWORD *)v17 + 1);
      v22 = *((_DWORD *)v17 + 2);
      in_ulConversionArraySize = *(unsigned __int16 *)(v17 + 13);
      in_pArrayConversion = (AkRTPCGraphPointBase<float> *)(v17 + 15);
      v24 = in_ulConversionArraySize;
      CAkFxBase::SetRTPC(this, v20, v21, v22, in_eScaling, in_pArrayConversion, in_ulConversionArraySize, 0);
      v17 = (unsigned __int8 *)&in_pArrayConversion[v24];
      --v18;
    }
    while ( v18 );
  }
  return 1i64;
}

// File Line: 107
// RVA: 0xA790C0
void __fastcall CAkFxBase::SetFX(CAkFxBase *this, unsigned int in_FXID, AK::IAkPluginParam *in_pParam)
{
  AK::IAkPluginParam *m_pParam; // rcx

  m_pParam = this->m_pParam;
  if ( m_pParam )
  {
    m_pParam->vfptr[2].__vecDelDtor(m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
    this->m_pParam = 0i64;
    this->m_pParam = in_pParam;
    this->m_FXID = in_FXID;
  }
  else
  {
    this->m_FXID = in_FXID;
    this->m_pParam = in_pParam;
  }
}

// File Line: 124
// RVA: 0xA79000
__int64 __fastcall CAkFxBase::SetFX(
        CAkFxBase *this,
        unsigned int in_FXID,
        void *in_pParamBlock,
        unsigned int in_uParamBlockSize)
{
  AKRESULT v8; // edi
  AK::IAkPluginParam *m_pParam; // rcx
  AK::IAkPluginParam *v11; // rdi
  AK::IAkPluginParam *out_pEffectParam; // [rsp+20h] [rbp-18h] BYREF

  out_pEffectParam = 0i64;
  if ( (unsigned int)CAkEffectsMgr::AllocParams(&AkFXMemAlloc::m_instanceUpper, in_FXID, &out_pEffectParam) == 1
    && out_pEffectParam )
  {
    v8 = out_pEffectParam->vfptr[1].SetParam(
           out_pEffectParam,
           (__int16)&AkFXMemAlloc::m_instanceUpper,
           in_pParamBlock,
           in_uParamBlockSize);
    if ( v8 != AK_Success )
    {
      out_pEffectParam->vfptr[2].__vecDelDtor(out_pEffectParam, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
      return (unsigned int)v8;
    }
    m_pParam = this->m_pParam;
    v11 = out_pEffectParam;
    if ( m_pParam )
    {
      m_pParam->vfptr[2].__vecDelDtor(m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
      this->m_pParam = 0i64;
    }
    this->m_FXID = in_FXID;
    this->m_pParam = v11;
  }
  return 1i64;
}

// File Line: 204
// RVA: 0xA79550
void __fastcall SetRTPCFunc(AK::IAkPluginParam *in_pParam, CAkRegisteredObj *in_pGameObj, void *in_pCookie)
{
  CAkRTPCMgr::SubscribeRTPC(
    g_pRTPCMgr,
    in_pParam,
    *(_DWORD *)in_pCookie,
    *((AkRTPC_ParameterID *)in_pCookie + 1),
    *((_DWORD *)in_pCookie + 2),
    *((AkCurveScaling *)in_pCookie + 3),
    *((AkRTPCGraphPointBase<float> **)in_pCookie + 2),
    *((_DWORD *)in_pCookie + 6),
    in_pGameObj,
    SubscriberType_IAkRTPCSubscriber);
}

// File Line: 218
// RVA: 0xA79240
void __fastcall CAkFxBase::SetRTPC(
        CAkFxBase *this,
        int in_RTPC_ID,
        AkRTPC_ParameterID in_ParamID,
        unsigned int in_RTPCCurveID,
        int in_eScaling,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        int in_ulConversionArraySize,
        bool in_bNotify)
{
  unsigned __int64 m_uLength; // rdi
  __int64 v13; // rdx
  CAkFxBase::RTPCSubs *v14; // rdx
  int in_pCookie[4]; // [rsp+20h] [rbp-38h] BYREF
  AkRTPCGraphPointBase<float> *v16; // [rsp+30h] [rbp-28h]
  int v17; // [rsp+38h] [rbp-20h]

  CAkFxBase::UnsetRTPC(this, in_ParamID, in_RTPCCurveID, in_bNotify);
  m_uLength = this->m_rtpcsubs.m_uLength;
  if ( (m_uLength < this->m_rtpcsubs.m_ulReserved
     || AkArray<CAkAttenuation::RTPCSubs,CAkAttenuation::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          &this->m_rtpcsubs,
          2u))
    && m_uLength < this->m_rtpcsubs.m_ulReserved )
  {
    v13 = this->m_rtpcsubs.m_uLength;
    this->m_rtpcsubs.m_uLength = v13 + 1;
    v14 = &this->m_rtpcsubs.m_pItems[v13];
    if ( v14 )
    {
      v14->ConversionTable.m_pArrayGraphPoints = 0i64;
      *(_QWORD *)&v14->ConversionTable.m_ulArraySize = 0i64;
      v14->RTPCCurveID = in_RTPCCurveID;
      v14->RTPCID = in_RTPC_ID;
      v14->ParamID = in_ParamID;
      if ( in_pArrayConversion && in_ulConversionArraySize )
        CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
          &v14->ConversionTable,
          in_pArrayConversion,
          in_ulConversionArraySize,
          (AkCurveScaling)in_eScaling);
      if ( in_bNotify )
      {
        in_pCookie[0] = in_RTPC_ID;
        in_pCookie[1] = in_ParamID;
        in_pCookie[2] = in_RTPCCurveID;
        in_pCookie[3] = in_eScaling;
        v16 = in_pArrayConversion;
        v17 = in_ulConversionArraySize;
        CAkLEngine::ForAllPluginParam(this, SetRTPCFunc, in_pCookie);
      }
    }
  }
}

// File Line: 258
// RVA: 0xA795A0
void __fastcall UnsetRTPCFunc(AK::IAkPluginParam *in_pParam, CAkRegisteredObj *__formal, unsigned int *in_pCookie)
{
  CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, in_pParam, *in_pCookie, in_pCookie[1], 0i64);
}

// File Line: 268
// RVA: 0xA79420
void __fastcall CAkFxBase::UnsetRTPC(
        CAkFxBase *this,
        AkRTPC_ParameterID in_ParamID,
        unsigned int in_RTPCCurveID,
        bool in_bNotify)
{
  CAkFxBase::RTPCSubs *m_pItems; // rax
  char v5; // si
  AkCurveScaling *p_m_eScaling; // rbx
  void *v11; // rdx
  CAkFxBase::RTPCSubs *v12; // rcx
  AkRTPC_ParameterID in_pCookie; // [rsp+50h] [rbp+8h] BYREF
  unsigned int v14; // [rsp+54h] [rbp+Ch]

  m_pItems = this->m_rtpcsubs.m_pItems;
  v5 = 0;
  if ( m_pItems != &m_pItems[this->m_rtpcsubs.m_uLength] )
  {
    p_m_eScaling = &m_pItems->ConversionTable.m_eScaling;
    do
    {
      if ( *((_DWORD *)p_m_eScaling - 5) == in_ParamID && *((_DWORD *)p_m_eScaling - 6) == in_RTPCCurveID )
      {
        v11 = *(void **)(p_m_eScaling - 3);
        if ( v11 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v11);
          *(_QWORD *)(p_m_eScaling - 3) = 0i64;
        }
        *(_QWORD *)(p_m_eScaling - 1) = 0i64;
        v12 = &this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength - 1];
        if ( p_m_eScaling - 7 < (AkCurveScaling *)v12 )
          qmemcpy(
            p_m_eScaling - 7,
            p_m_eScaling + 1,
            8
          * (((((unsigned __int64)((char *)v12 - (char *)(p_m_eScaling - 7) - 1) >> 3) & 0xFFFFFFFFFFFFFFFCui64) + 4) & 0x1FFFFFFFFFFFFFFCi64));
        --this->m_rtpcsubs.m_uLength;
        v5 = 1;
      }
      else
      {
        p_m_eScaling += 8;
      }
    }
    while ( p_m_eScaling - 7 != (AkCurveScaling *)&this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength] );
    if ( v5 )
    {
      if ( in_bNotify )
      {
        in_pCookie = in_ParamID;
        v14 = in_RTPCCurveID;
        CAkLEngine::ForAllPluginParam(this, UnsetRTPCFunc, &in_pCookie);
      }
    }
  }
}

// File Line: 301
// RVA: 0xA79370
void __fastcall CAkFxBase::SubscribeRTPC(
        CAkFxBase *this,
        AK::IAkRTPCSubscriber *in_pSubscriber,
        CAkRegisteredObj *in_pGameObj)
{
  CAkFxBase::RTPCSubs *m_pItems; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // rbx

  m_pItems = this->m_rtpcsubs.m_pItems;
  if ( m_pItems != &m_pItems[this->m_rtpcsubs.m_uLength] )
  {
    p_ConversionTable = &m_pItems->ConversionTable;
    do
    {
      CAkRTPCMgr::SubscribeRTPC(
        g_pRTPCMgr,
        in_pSubscriber,
        (unsigned int)p_ConversionTable[-1].m_pArrayGraphPoints,
        (AkRTPC_ParameterID)p_ConversionTable[-1].m_ulArraySize,
        HIDWORD(p_ConversionTable[-1].m_pArrayGraphPoints),
        p_ConversionTable->m_eScaling,
        p_ConversionTable->m_pArrayGraphPoints,
        p_ConversionTable->m_ulArraySize,
        in_pGameObj,
        SubscriberType_IAkRTPCSubscriber);
      p_ConversionTable += 2;
    }
    while ( &p_ConversionTable[-1] != (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)&this->m_rtpcsubs.m_pItems[this->m_rtpcsubs.m_uLength] );
  }
}

// File Line: 334
// RVA: 0xA78D90
CAkFxShareSet *__fastcall CAkFxShareSet::Create(unsigned int in_ulID)
{
  CAkFxShareSet *result; // rax
  CAkFxShareSet *v3; // rdi
  CAkIndexItem<CAkFxShareSet *> *p_m_idxFxShareSets; // rbx
  __int64 v5; // r8

  result = (CAkFxShareSet *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable(result, in_ulID);
    v3->m_FXID = -1;
    v3->m_pParam = 0i64;
    v3->m_media.m_pItems = 0i64;
    *(_QWORD *)&v3->m_media.m_uLength = 0i64;
    v3->m_rtpcsubs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_rtpcsubs.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkFxShareSet::`vftable;
    p_m_idxFxShareSets = &g_pIndex->m_idxFxShareSets;
    EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
    v5 = v3->key % 0xC1;
    v3->pNextItem = p_m_idxFxShareSets->m_mapIDToPtr.m_table[v5];
    p_m_idxFxShareSets->m_mapIDToPtr.m_table[v5] = v3;
    ++p_m_idxFxShareSets->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&p_m_idxFxShareSets->m_IndexLock.m_csLock);
    return v3;
  }
  return result;
}

// File Line: 342
// RVA: 0xA78C70
__int64 __fastcall CAkFxShareSet::AddRef(CAkFxShareSet *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxFxShareSets.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 348
// RVA: 0xA78EF0
__int64 __fastcall CAkFxShareSet::Release(CAkFxShareSet *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxFxShareSets, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxFxShareSets.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 366
// RVA: 0xA78CC0
CAkFxCustom *__fastcall CAkFxCustom::Create(unsigned int in_ulID)
{
  CAkFxCustom *result; // rax
  CAkFxCustom *v3; // rdi
  CAkIndexItem<CAkFxCustom *> *p_m_idxFxCustom; // rbx
  __int64 v5; // r8

  result = (CAkFxCustom *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable(result, in_ulID);
    v3->m_FXID = -1;
    v3->m_pParam = 0i64;
    v3->m_media.m_pItems = 0i64;
    *(_QWORD *)&v3->m_media.m_uLength = 0i64;
    v3->m_rtpcsubs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_rtpcsubs.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkFxCustom::`vftable;
    p_m_idxFxCustom = &g_pIndex->m_idxFxCustom;
    EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
    v5 = v3->key % 0xC1;
    v3->pNextItem = p_m_idxFxCustom->m_mapIDToPtr.m_table[v5];
    p_m_idxFxCustom->m_mapIDToPtr.m_table[v5] = v3;
    ++p_m_idxFxCustom->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&p_m_idxFxCustom->m_IndexLock.m_csLock);
    return v3;
  }
  return result;
}

// File Line: 374
// RVA: 0xA78C20
__int64 __fastcall CAkFxCustom::AddRef(CAkFxCustom *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxFxCustom.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 380
// RVA: 0xA78E60
__int64 __fastcall CAkFxCustom::Release(CAkFxCustom *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxFxCustom, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxFxCustom.m_IndexLock.m_csLock);
  return m_lRef;
}

