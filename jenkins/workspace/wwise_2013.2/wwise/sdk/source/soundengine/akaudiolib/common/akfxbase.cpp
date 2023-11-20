// File Line: 29
// RVA: 0xA78B10
void __fastcall CAkFxBase::~CAkFxBase(CAkFxBase *this)
{
  CAkFxBase::RTPCSubs *v1; // rax
  CAkFxBase *v2; // rdi
  signed __int64 v3; // rbx
  MapStruct<unsigned long,unsigned long> *v4; // rdx
  AK::IAkPluginParam *v5; // rcx

  this->vfptr = (CAkIndexableVtbl *)&CAkFxBase::`vftable;
  v1 = this->m_rtpcsubs.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_rtpcsubs.m_uLength] )
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
    while ( (CAkFxBase::RTPCSubs *)(v3 - 16) != &v2->m_rtpcsubs.m_pItems[v2->m_rtpcsubs.m_uLength] );
  }
  if ( v2->m_rtpcsubs.m_pItems )
  {
    v2->m_rtpcsubs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_rtpcsubs.m_pItems);
    v2->m_rtpcsubs.m_pItems = 0i64;
    v2->m_rtpcsubs.m_ulReserved = 0;
  }
  v4 = v2->m_media.m_pItems;
  if ( v4 )
  {
    v2->m_media.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v2->m_media.m_pItems = 0i64;
    v2->m_media.m_ulReserved = 0;
  }
  v5 = v2->m_pParam;
  if ( v5 )
    v5->vfptr[2].__vecDelDtor((AK::IAkRTPCSubscriber *)&v5->vfptr, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
  CAkIndexable::~CAkIndexable((CAkIndexable *)&v2->vfptr);
}

// File Line: 47
// RVA: 0xA79130
signed __int64 __fastcall CAkFxBase::SetInitialValues(CAkFxBase *this, char *in_pData, unsigned int in_uDataSize)
{
  char *v3; // rbx
  unsigned int v4; // edx
  CAkFxBase *v5; // r14
  __int64 v6; // rdi
  char *v7; // rbx
  unsigned int v8; // ebp
  char *v9; // rbx
  unsigned int v10; // ecx
  unsigned __int8 *v11; // rbx
  __int64 v12; // rdi
  MapStruct<unsigned long,unsigned long> *v13; // rax
  unsigned int v14; // edx
  unsigned int v15; // er8
  unsigned int v16; // eax
  signed __int64 v17; // rbx
  __int64 v18; // rsi
  AkCurveScaling in_eScaling; // ecx
  unsigned int v20; // edx
  AkRTPC_ParameterID v21; // er8
  unsigned int v22; // er9
  unsigned int in_ulConversionArraySize; // ST30_4
  AkRTPCGraphPointBase<float> *in_pArrayConversion; // rbx
  __int64 v25; // rdi

  v3 = in_pData;
  v4 = *((_DWORD *)in_pData + 1);
  v5 = this;
  v6 = *((unsigned int *)v3 + 2);
  v7 = v3 + 12;
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
    v5->m_media.m_pItems = v13;
    if ( v13 )
      v5->m_media.m_ulReserved = v12;
  }
  if ( (_DWORD)v12 )
  {
    do
    {
      v14 = *v11;
      v15 = *(_DWORD *)(v11 + 1);
      v11 += 5;
      CAkKeyArray<unsigned long,unsigned long,8>::Set(&v5->m_media, v14, v15);
      --v12;
    }
    while ( v12 );
  }
  v16 = *(unsigned __int16 *)v11;
  v17 = (signed __int64)(v11 + 2);
  if ( v16 )
  {
    v18 = v16;
    do
    {
      in_eScaling = *(unsigned __int8 *)(v17 + 12);
      v20 = *(_DWORD *)v17;
      v21 = *(_DWORD *)(v17 + 4);
      v22 = *(_DWORD *)(v17 + 8);
      in_ulConversionArraySize = *(unsigned __int16 *)(v17 + 13);
      in_pArrayConversion = (AkRTPCGraphPointBase<float> *)(v17 + 15);
      v25 = in_ulConversionArraySize;
      CAkFxBase::SetRTPC(v5, v20, v21, v22, in_eScaling, in_pArrayConversion, in_ulConversionArraySize, 0);
      v17 = (signed __int64)&in_pArrayConversion[v25];
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
  CAkFxBase *v3; // rbx
  AK::IAkPluginParam *v4; // rcx
  AK::IAkPluginParam *v5; // rdi
  unsigned int v6; // esi

  v3 = this;
  v4 = this->m_pParam;
  v5 = in_pParam;
  v6 = in_FXID;
  if ( v4 )
  {
    v4->vfptr[2].__vecDelDtor((AK::IAkRTPCSubscriber *)&v4->vfptr, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
    v3->m_pParam = 0i64;
    v3->m_pParam = v5;
    v3->m_FXID = v6;
  }
  else
  {
    v3->m_FXID = in_FXID;
    v3->m_pParam = in_pParam;
  }
}

// File Line: 124
// RVA: 0xA79000
signed __int64 __fastcall CAkFxBase::SetFX(CAkFxBase *this, unsigned int in_FXID, void *in_pParamBlock, unsigned int in_uParamBlockSize)
{
  void *v4; // rbp
  CAkFxBase *v5; // rbx
  unsigned int v6; // edi
  unsigned int v7; // esi
  AKRESULT v8; // edi
  AK::IAkPluginParam *v10; // rcx
  AK::IAkPluginParam *v11; // rdi
  AK::IAkPluginParam *out_pEffectParam; // [rsp+20h] [rbp-18h]

  v4 = in_pParamBlock;
  v5 = this;
  v6 = in_uParamBlockSize;
  v7 = in_FXID;
  out_pEffectParam = 0i64;
  if ( (unsigned int)CAkEffectsMgr::AllocParams(
                       (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceUpper.vfptr,
                       in_FXID,
                       &out_pEffectParam) == 1
    && out_pEffectParam )
  {
    v8 = (unsigned int)out_pEffectParam->vfptr[1].SetParam(
                         (AK::IAkRTPCSubscriber *)out_pEffectParam,
                         (__int16)&AkFXMemAlloc::m_instanceUpper,
                         v4,
                         v6);
    if ( v8 != 1 )
    {
      out_pEffectParam->vfptr[2].__vecDelDtor(
        (AK::IAkRTPCSubscriber *)out_pEffectParam,
        (unsigned int)&AkFXMemAlloc::m_instanceUpper);
      return (unsigned int)v8;
    }
    v10 = v5->m_pParam;
    v11 = out_pEffectParam;
    if ( v10 )
    {
      v10->vfptr[2].__vecDelDtor((AK::IAkRTPCSubscriber *)&v10->vfptr, (unsigned int)&AkFXMemAlloc::m_instanceUpper);
      v5->m_pParam = 0i64;
    }
    v5->m_FXID = v7;
    v5->m_pParam = v11;
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
    0);
}

// File Line: 218
// RVA: 0xA79240
void __fastcall CAkFxBase::SetRTPC(CAkFxBase *this, unsigned int in_RTPC_ID, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID, AkCurveScaling in_eScaling, AkRTPCGraphPointBase<float> *in_pArrayConversion, unsigned int in_ulConversionArraySize, bool in_bNotify)
{
  unsigned int v8; // ebp
  AkRTPC_ParameterID v9; // er14
  unsigned int v10; // er15
  CAkFxBase *v11; // r13
  unsigned __int64 v12; // rdi
  unsigned int v13; // eax
  signed __int64 v14; // rdx
  unsigned int in_pCookie; // [rsp+20h] [rbp-38h]
  AkRTPC_ParameterID v16; // [rsp+24h] [rbp-34h]
  unsigned int v17; // [rsp+28h] [rbp-30h]
  AkCurveScaling v18; // [rsp+2Ch] [rbp-2Ch]
  AkRTPCGraphPointBase<float> *v19; // [rsp+30h] [rbp-28h]
  unsigned int v20; // [rsp+38h] [rbp-20h]

  v8 = in_RTPCCurveID;
  v9 = in_ParamID;
  v10 = in_RTPC_ID;
  v11 = this;
  CAkFxBase::UnsetRTPC(this, in_ParamID, in_RTPCCurveID, in_bNotify);
  v12 = v11->m_rtpcsubs.m_uLength;
  if ( (v12 < v11->m_rtpcsubs.m_ulReserved
     || AkArray<CAkAttenuation::RTPCSubs,CAkAttenuation::RTPCSubs const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          &v11->m_rtpcsubs,
          2u))
    && v12 < v11->m_rtpcsubs.m_ulReserved )
  {
    v13 = v11->m_rtpcsubs.m_uLength;
    v11->m_rtpcsubs.m_uLength = v13 + 1;
    v14 = (signed __int64)&v11->m_rtpcsubs.m_pItems[v13];
    if ( v14 )
    {
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_DWORD *)(v14 + 4) = v8;
      *(_DWORD *)v14 = v10;
      *(_DWORD *)(v14 + 8) = v9;
      if ( in_pArrayConversion && in_ulConversionArraySize )
        CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
          (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v14 + 16),
          in_pArrayConversion,
          in_ulConversionArraySize,
          in_eScaling);
      if ( in_bNotify )
      {
        in_pCookie = v10;
        v16 = v9;
        v17 = v8;
        v18 = in_eScaling;
        v19 = in_pArrayConversion;
        v20 = in_ulConversionArraySize;
        CAkLEngine::ForAllPluginParam(v11, SetRTPCFunc, &in_pCookie);
      }
    }
  }
}

// File Line: 258
// RVA: 0xA795A0
void __fastcall UnsetRTPCFunc(AK::IAkPluginParam *in_pParam, CAkRegisteredObj *__formal, void *in_pCookie)
{
  CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, in_pParam, *(_DWORD *)in_pCookie, *((_DWORD *)in_pCookie + 1), 0i64);
}

// File Line: 268
// RVA: 0xA79420
void __fastcall CAkFxBase::UnsetRTPC(CAkFxBase *this, AkRTPC_ParameterID in_ParamID, unsigned int in_RTPCCurveID, bool in_bNotify)
{
  CAkFxBase::RTPCSubs *v4; // rax
  char v5; // si
  bool v6; // r12
  unsigned int v7; // er14
  AkRTPC_ParameterID v8; // er15
  CAkFxBase *v9; // rbp
  signed __int64 v10; // rbx
  void *v11; // rdx
  unsigned __int64 v12; // rcx
  AkRTPC_ParameterID in_pCookie; // [rsp+50h] [rbp+8h]
  unsigned int v14; // [rsp+54h] [rbp+Ch]

  v4 = this->m_rtpcsubs.m_pItems;
  v5 = 0;
  v6 = in_bNotify;
  v7 = in_RTPCCurveID;
  v8 = in_ParamID;
  v9 = this;
  if ( v4 != &v4[this->m_rtpcsubs.m_uLength] )
  {
    v10 = (signed __int64)&v4->ConversionTable.m_eScaling;
    do
    {
      if ( *(_DWORD *)(v10 - 20) != v8 || *(_DWORD *)(v10 - 24) != v7 )
      {
        v10 += 32i64;
      }
      else
      {
        v11 = *(void **)(v10 - 12);
        if ( v11 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v11);
          *(_QWORD *)(v10 - 12) = 0i64;
        }
        *(_QWORD *)(v10 - 4) = 0i64;
        v12 = (unsigned __int64)&v9->m_rtpcsubs.m_pItems[v9->m_rtpcsubs.m_uLength - 1];
        if ( v10 - 28 < v12 )
          qmemcpy(
            (void *)(v10 - 28),
            (const void *)(v10 + 4),
            8 * (((((v12 - (v10 - 28) - 1) >> 3) & 0xFFFFFFFFFFFFFFFCui64) + 4) & 0x1FFFFFFFFFFFFFFCi64));
        --v9->m_rtpcsubs.m_uLength;
        v5 = 1;
      }
    }
    while ( (CAkFxBase::RTPCSubs *)(v10 - 28) != &v9->m_rtpcsubs.m_pItems[v9->m_rtpcsubs.m_uLength] );
    if ( v5 )
    {
      if ( v6 )
      {
        in_pCookie = v8;
        v14 = v7;
        CAkLEngine::ForAllPluginParam(v9, UnsetRTPCFunc, &in_pCookie);
      }
    }
  }
}

// File Line: 301
// RVA: 0xA79370
void __fastcall CAkFxBase::SubscribeRTPC(CAkFxBase *this, AK::IAkRTPCSubscriber *in_pSubscriber, CAkRegisteredObj *in_pGameObj)
{
  CAkFxBase::RTPCSubs *v3; // rax
  CAkRegisteredObj *in_TargetGameObject; // rsi
  AK::IAkRTPCSubscriber *v5; // rbp
  CAkFxBase *v6; // rdi
  signed __int64 v7; // rbx

  v3 = this->m_rtpcsubs.m_pItems;
  in_TargetGameObject = in_pGameObj;
  v5 = in_pSubscriber;
  v6 = this;
  if ( v3 != &v3[this->m_rtpcsubs.m_uLength] )
  {
    v7 = (signed __int64)&v3->ConversionTable;
    do
    {
      CAkRTPCMgr::SubscribeRTPC(
        g_pRTPCMgr,
        v5,
        *(_DWORD *)(v7 - 16),
        *(AkRTPC_ParameterID *)(v7 - 8),
        *(_DWORD *)(v7 - 12),
        *(AkCurveScaling *)(v7 + 12),
        *(AkRTPCGraphPointBase<float> **)v7,
        *(_DWORD *)(v7 + 8),
        in_TargetGameObject,
        0);
      v7 += 32i64;
    }
    while ( (CAkFxBase::RTPCSubs *)(v7 - 16) != &v6->m_rtpcsubs.m_pItems[v6->m_rtpcsubs.m_uLength] );
  }
}

// File Line: 334
// RVA: 0xA78D90
CAkFxShareSet *__fastcall CAkFxShareSet::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkFxShareSet *result; // rax
  CAkFxShareSet *v3; // rdi
  CAkIndexItem<CAkFxShareSet *> *v4; // rbx
  __int64 v5; // r8

  v1 = in_ulID;
  result = (CAkFxShareSet *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable((CAkIndexable *)&result->vfptr, v1);
    v3->m_FXID = -1;
    v3->m_pParam = 0i64;
    v3->m_media.m_pItems = 0i64;
    *(_QWORD *)&v3->m_media.m_uLength = 0i64;
    v3->m_rtpcsubs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_rtpcsubs.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkFxShareSet::`vftable;
    v4 = &g_pIndex->m_idxFxShareSets;
    EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
    v5 = v3->key % 0xC1;
    v3->pNextItem = v4->m_mapIDToPtr.m_table[v5];
    v4->m_mapIDToPtr.m_table[v5] = (CAkIndexable *)&v3->vfptr;
    ++v4->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&v4->m_IndexLock.m_csLock);
    result = v3;
  }
  return result;
}

// File Line: 342
// RVA: 0xA78C70
__int64 __fastcall CAkFxShareSet::AddRef(CAkFxShareSet *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkFxShareSet *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxFxShareSets.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 348
// RVA: 0xA78EF0
__int64 __fastcall CAkFxShareSet::Release(CAkFxShareSet *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkFxShareSet *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxFxShareSets.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxFxShareSets, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxFxShareSets.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 366
// RVA: 0xA78CC0
CAkFxCustom *__fastcall CAkFxCustom::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkFxCustom *result; // rax
  CAkFxCustom *v3; // rdi
  CAkIndexItem<CAkFxCustom *> *v4; // rbx
  __int64 v5; // r8

  v1 = in_ulID;
  result = (CAkFxCustom *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable((CAkIndexable *)&result->vfptr, v1);
    v3->m_FXID = -1;
    v3->m_pParam = 0i64;
    v3->m_media.m_pItems = 0i64;
    *(_QWORD *)&v3->m_media.m_uLength = 0i64;
    v3->m_rtpcsubs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_rtpcsubs.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkFxCustom::`vftable;
    v4 = &g_pIndex->m_idxFxCustom;
    EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
    v5 = v3->key % 0xC1;
    v3->pNextItem = v4->m_mapIDToPtr.m_table[v5];
    v4->m_mapIDToPtr.m_table[v5] = (CAkIndexable *)&v3->vfptr;
    ++v4->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&v4->m_IndexLock.m_csLock);
    result = v3;
  }
  return result;
}

// File Line: 374
// RVA: 0xA78C20
__int64 __fastcall CAkFxCustom::AddRef(CAkFxCustom *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkFxCustom *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxFxCustom.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 380
// RVA: 0xA78E60
__int64 __fastcall CAkFxCustom::Release(CAkFxCustom *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkFxCustom *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxFxCustom.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxFxCustom, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxFxCustom.m_IndexLock.m_csLock);
  return v4;
}

