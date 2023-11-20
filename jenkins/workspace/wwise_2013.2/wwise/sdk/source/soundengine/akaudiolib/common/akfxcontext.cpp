// File Line: 31
// RVA: 0xA84BF0
void __fastcall AkDataReferenceArray::~AkDataReferenceArray(AkDataReferenceArray *this)
{
  AkDataReferenceArray *v1; // rdi
  CAkUsageSlot **v2; // rbx
  unsigned int v3; // edx
  MapStruct<unsigned long,AkDataReference> *v4; // rdx

  v1 = this;
  if ( this->m_pItems != &this->m_pItems[this->m_uLength] )
  {
    v2 = &this->m_pItems->item.pUsageSlot;
    do
    {
      if ( *(v2 - 2) )
      {
        v3 = *((_DWORD *)v2 - 1);
        if ( v3 != -1 )
        {
          CAkBankMgr::ReleaseMedia(g_pBankManager, v3);
          if ( *v2 )
            CAkUsageSlot::Release(*v2, 0);
        }
      }
      v2 += 4;
    }
    while ( v2 - 3 != (CAkUsageSlot **)&v1->m_pItems[v1->m_uLength] );
  }
  v4 = v1->m_pItems;
  if ( v1->m_pItems )
  {
    v1->m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v1->m_pItems = 0i64;
    v1->m_ulReserved = 0;
  }
}

// File Line: 47
// RVA: 0xA84D50
AkDataReference *__fastcall AkDataReferenceArray::AcquireData(AkDataReferenceArray *this, unsigned int in_uDataIdx, unsigned int in_uSourceID)
{
  AkDataReferenceArray *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // edi
  AkDataReference *v6; // rax
  AkDataReference *v7; // rbx
  unsigned int v8; // eax
  AkMediaInfo result; // [rsp+20h] [rbp-18h]
  CAkUsageSlot *out_pUsageSlot; // [rsp+58h] [rbp+20h]

  v3 = this;
  v4 = in_uDataIdx;
  v5 = in_uSourceID;
  out_pUsageSlot = 0i64;
  CAkBankMgr::GetMedia(g_pBankManager, &result, in_uSourceID, &out_pUsageSlot);
  if ( !result.pInMemoryData )
    return 0i64;
  v6 = CAkKeyArray<unsigned long,AkDataReference,2>::Set(
         (CAkKeyArray<unsigned long,AkDataReference,2> *)&v3->m_pItems,
         v4);
  v7 = v6;
  if ( v6 )
  {
    v6->pData = result.pInMemoryData;
    v8 = result.uInMemoryDataSize;
    v7->uSourceID = v5;
    v7->uSize = v8;
    v7->pUsageSlot = out_pUsageSlot;
    return v7;
  }
  CAkBankMgr::ReleaseMedia(g_pBankManager, v5);
  if ( !out_pUsageSlot )
    return v7;
  CAkUsageSlot::Release(out_pUsageSlot, 0);
  return v7;
}

// File Line: 89
// RVA: 0xA852D0
AK::IAkStreamMgr *__fastcall CAkEffectContextBase::GetStreamMgr(CAkSourceFXContext *this)
{
  return AK::IAkStreamMgr::m_pStreamMgr;
}

// File Line: 138
// RVA: 0xA853D0
char __fastcall CAkEffectContextBase::IsUsingThisSlot(CAkEffectContextBase *this, CAkUsageSlot *in_pUsageSlot, AK::IAkPlugin *in_pCorrespondingFX)
{
  MapStruct<unsigned long,AkDataReference> *v3; // rax
  AK::IAkPlugin *v4; // rdi
  CAkUsageSlot *v5; // rbp
  CAkEffectContextBase *v6; // rsi
  CAkUsageSlot **v7; // rbx
  unsigned int v8; // er8
  unsigned int v9; // edx
  AkMediaInfo result; // [rsp+20h] [rbp-28h]
  CAkUsageSlot *out_pUsageSlot; // [rsp+50h] [rbp+8h]

  v3 = this->m_dataArray.m_pItems;
  v4 = in_pCorrespondingFX;
  v5 = in_pUsageSlot;
  v6 = this;
  if ( v3 == &v3[this->m_dataArray.m_uLength] )
    return 0;
  v7 = &v3->item.pUsageSlot;
  while ( *v7 != v5 )
  {
LABEL_12:
    v7 += 4;
    if ( v7 - 3 == (CAkUsageSlot **)&v6->m_dataArray.m_pItems[v6->m_dataArray.m_uLength] )
      return 0;
  }
  if ( !v4->vfptr->SupportMediaRelocation(v4) )
    return 1;
  v8 = *((_DWORD *)v7 - 1);
  out_pUsageSlot = 0i64;
  CAkBankMgr::GetMedia(g_pBankManager, &result, v8, &out_pUsageSlot);
  if ( !result.pInMemoryData )
    return 1;
  if ( v4->vfptr->RelocateMedia(v4, result.pInMemoryData, (char *)*(v7 - 2)) == 1 )
  {
    if ( *(v7 - 2) )
    {
      v9 = *((_DWORD *)v7 - 1);
      if ( v9 != -1 )
      {
        CAkBankMgr::ReleaseMedia(g_pBankManager, v9);
        if ( *v7 )
          CAkUsageSlot::Release(*v7, 0);
      }
    }
    *(v7 - 2) = (CAkUsageSlot *)result.pInMemoryData;
    *v7 = out_pUsageSlot;
    goto LABEL_12;
  }
  if ( result.pInMemoryData )
  {
    CAkBankMgr::ReleaseMedia(g_pBankManager, *((_DWORD *)v7 - 1));
    if ( out_pUsageSlot )
      CAkUsageSlot::Release(out_pUsageSlot, 0);
  }
  return 1;
}

// File Line: 153
// RVA: 0xA853A0
char __fastcall CAkEffectContextBase::IsUsingThisSlot(CAkEffectContextBase *this, const char *in_pData)
{
  MapStruct<unsigned long,AkDataReference> *v2; // rax
  signed __int64 v3; // r8

  v2 = this->m_dataArray.m_pItems;
  v3 = (signed __int64)&v2[this->m_dataArray.m_uLength];
  if ( v2 == (MapStruct<unsigned long,AkDataReference> *)v3 )
    return 0;
  while ( v2->item.pData != in_pData )
  {
    ++v2;
    if ( v2 == (MapStruct<unsigned long,AkDataReference> *)v3 )
      return 0;
  }
  return 1;
}

// File Line: 166
// RVA: 0xA852C0
AK::AkRuntimeEnvironmentMgr *__fastcall CAkSourceFXContext::GetProcessorFeatures(CAkSourceFXContext *this)
{
  return AK::AkRuntimeEnvironmentMgr::Instance();
}

// File Line: 178
// RVA: 0xA84BB0
void __fastcall CAkInsertFXContext::CAkInsertFXContext(CAkInsertFXContext *this, CAkPBI *in_pCtx, unsigned int in_uFXIndex)
{
  this->m_uFXIndex = in_uFXIndex;
  this->m_dataArray.m_pItems = 0i64;
  *(_QWORD *)&this->m_dataArray.m_uLength = 0i64;
  this->vfptr = (AK::IAkPluginContextBaseVtbl *)&CAkInsertFXContext::`vftable;
  this->m_pContext = in_pCtx;
}

// File Line: 212
// RVA: 0xA85090
void __fastcall CAkInsertFXContext::GetPluginMedia(CAkInsertFXContext *this, unsigned int in_dataIndex, char **out_rpData, unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *v4; // rax
  AkDataReferenceArray *v5; // r14
  unsigned int *v6; // rdi
  char **v7; // rsi
  signed __int64 v8; // r10
  unsigned int v9; // ebx
  AkDataReference *v10; // rax
  __int64 v11; // r8
  __int64 v12; // rdx
  CAkPBI *v13; // rcx
  unsigned int out_rDataID; // [rsp+30h] [rbp+8h]

  v4 = this->m_dataArray.m_pItems;
  v5 = &this->m_dataArray;
  v6 = out_rDataSize;
  v7 = out_rpData;
  v8 = (signed __int64)&v4[this->m_dataArray.m_uLength];
  v9 = in_dataIndex;
  if ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 )
  {
    do
    {
      if ( v4->key == in_dataIndex )
        break;
      ++v4;
    }
    while ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 );
    if ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 )
    {
      v10 = &v4->item;
      if ( v10 )
        goto LABEL_12;
    }
  }
  v11 = in_dataIndex;
  v12 = this->m_uFXIndex;
  v13 = this->m_pContext;
  out_rDataID = -1;
  CAkPBI::GetFXDataID(v13, v12, v11, &out_rDataID);
  if ( out_rDataID != -1 && (v10 = AkDataReferenceArray::AcquireData(v5, v9, out_rDataID)) != 0i64 )
  {
LABEL_12:
    *v6 = v10->uSize;
    *v7 = v10->pData;
  }
  else
  {
    *v7 = 0i64;
    *v6 = 0;
  }
}

// File Line: 258
// RVA: 0xA84B80
void __fastcall CAkBusFXContext::CAkBusFXContext(CAkBusFXContext *this, CAkBusFX *in_pBusFX, unsigned int in_uFXIndex, AK::CAkBusCtx *in_rBusContext)
{
  this->m_uFXIndex = in_uFXIndex;
  this->m_dataArray.m_pItems = 0i64;
  *(_QWORD *)&this->m_dataArray.m_uLength = 0i64;
  this->vfptr = (AK::IAkPluginContextBaseVtbl *)&CAkBusFXContext::`vftable;
  this->m_pBusFX = in_pBusFX;
  this->m_BuxCtx = (AK::CAkBusCtx)in_rBusContext->m_pBus;
}

// File Line: 267
// RVA: 0xA85390
bool __fastcall CAkBusFXContext::IsSendModeEffect(CAkBusFXContext *this)
{
  return AK::CAkBusCtx::IsAuxBus(&this->m_BuxCtx);
}

// File Line: 301
// RVA: 0xA84FE0
void __fastcall CAkBusFXContext::GetPluginMedia(CAkBusFXContext *this, unsigned int in_dataIndex, char **out_rpData, unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *v4; // rax
  AkDataReferenceArray *v5; // r14
  unsigned int v6; // ebx
  unsigned int *v7; // rdi
  signed __int64 v8; // r10
  char **v9; // rsi
  AkDataReference *v10; // rax
  __int64 v11; // rdx
  unsigned int out_rDataID; // [rsp+30h] [rbp+8h]

  v4 = this->m_dataArray.m_pItems;
  v5 = &this->m_dataArray;
  v6 = in_dataIndex;
  v7 = out_rDataSize;
  v8 = (signed __int64)&v4[this->m_dataArray.m_uLength];
  v9 = out_rpData;
  if ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 )
  {
    do
    {
      if ( v4->key == in_dataIndex )
        break;
      ++v4;
    }
    while ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 );
    if ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 )
    {
      v10 = &v4->item;
      if ( v10 )
        goto LABEL_12;
    }
  }
  v11 = this->m_uFXIndex;
  out_rDataID = -1;
  AK::CAkBusCtx::GetFXDataID(&this->m_BuxCtx, v11, v6, &out_rDataID);
  if ( out_rDataID != -1 && (v10 = AkDataReferenceArray::AcquireData(v5, v6, out_rDataID)) != 0i64 )
  {
LABEL_12:
    *v7 = v10->uSize;
    *v9 = v10->pData;
  }
  else
  {
    *v9 = 0i64;
    *v7 = 0;
  }
}

// File Line: 334
// RVA: 0xA84BD0
void __fastcall CAkSourceFXContext::CAkSourceFXContext(CAkSourceFXContext *this, CAkPBI *in_pCtx)
{
  this->m_pContext = in_pCtx;
  this->vfptr = (AK::IAkPluginContextBaseVtbl *)&CAkSourceFXContext::`vftable;
  this->m_dataArray.m_pItems = 0i64;
  *(_QWORD *)&this->m_dataArray.m_uLength = 0i64;
}

// File Line: 344
// RVA: 0xA84FB0
__int64 __fastcall CAkSourceFXContext::GetNumLoops(CAkSourceFXContext *this)
{
  return (unsigned __int16)this->m_pContext->m_LoopCount;
}

// File Line: 386
// RVA: 0xA85140
void __fastcall CAkSourceFXContext::GetPluginMedia(CAkSourceFXContext *this, unsigned int in_dataIndex, char **out_rpData, unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *v4; // rax
  AkDataReferenceArray *v5; // r15
  unsigned int *v6; // rsi
  char **v7; // r14
  signed __int64 v8; // r10
  unsigned int i; // ebx
  AkDataReference *v10; // rax
  CAkIndexable *v11; // rax
  unsigned int *v12; // rdx
  _DWORD *v13; // rax
  signed __int64 v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // edi

  v4 = this->m_dataArray.m_pItems;
  v5 = &this->m_dataArray;
  v6 = out_rDataSize;
  v7 = out_rpData;
  v8 = (signed __int64)&v4[this->m_dataArray.m_uLength];
  for ( i = in_dataIndex; v4 != (MapStruct<unsigned long,AkDataReference> *)v8; ++v4 )
  {
    if ( v4->key == in_dataIndex )
      break;
  }
  if ( v4 != (MapStruct<unsigned long,AkDataReference> *)v8 )
  {
    v10 = &v4->item;
    if ( v10 )
      goto LABEL_20;
  }
  v11 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
          (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
          this->m_pContext->m_pSource->m_sSrcTypeInfo.mediaInfo.sourceID);
  v12 = (unsigned int *)v11;
  if ( !v11 )
    goto LABEL_21;
  v13 = *(_DWORD **)&v11[1].key;
  v14 = (signed __int64)&v13[2 * v12[12]];
  if ( v13 == (_DWORD *)v14 )
    goto LABEL_22;
  do
  {
    if ( *v13 == i )
      break;
    v13 += 2;
  }
  while ( v13 != (_DWORD *)v14 );
  if ( v13 != (_DWORD *)v14 && (v15 = v13 + 1) != 0i64 )
    v16 = *v15;
  else
LABEL_22:
    v16 = 0;
  (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v12 + 16i64))(v12);
  if ( v16 != -1 && (v10 = AkDataReferenceArray::AcquireData(v5, i, v16)) != 0i64 )
  {
LABEL_20:
    *v6 = v10->uSize;
    *v7 = v10->pData;
  }
  else
  {
LABEL_21:
    *v7 = 0i64;
    *v6 = 0;
  }
}

