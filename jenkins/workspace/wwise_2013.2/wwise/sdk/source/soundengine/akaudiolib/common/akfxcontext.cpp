// File Line: 31
// RVA: 0xA84BF0
void __fastcall AkDataReferenceArray::~AkDataReferenceArray(AkDataReferenceArray *this)
{
  CAkUsageSlot **p_pUsageSlot; // rbx
  unsigned int v3; // edx
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rdx

  if ( this->m_pItems != &this->m_pItems[this->m_uLength] )
  {
    p_pUsageSlot = &this->m_pItems->item.pUsageSlot;
    do
    {
      if ( *(p_pUsageSlot - 2) )
      {
        v3 = *((_DWORD *)p_pUsageSlot - 1);
        if ( v3 != -1 )
        {
          CAkBankMgr::ReleaseMedia(g_pBankManager, v3);
          if ( *p_pUsageSlot )
            CAkUsageSlot::Release(*p_pUsageSlot, 0);
        }
      }
      p_pUsageSlot += 4;
    }
    while ( p_pUsageSlot - 3 != (CAkUsageSlot **)&this->m_pItems[this->m_uLength] );
  }
  m_pItems = this->m_pItems;
  if ( this->m_pItems )
  {
    this->m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_pItems = 0i64;
    this->m_ulReserved = 0;
  }
}

// File Line: 47
// RVA: 0xA84D50
AkDataReference *__fastcall AkDataReferenceArray::AcquireData(
        AkDataReferenceArray *this,
        unsigned int in_uDataIdx,
        unsigned int in_uSourceID)
{
  AkDataReference *v6; // rax
  AkDataReference *v7; // rbx
  unsigned int uInMemoryDataSize; // eax
  AkMediaInfo result; // [rsp+20h] [rbp-18h] BYREF
  CAkUsageSlot *out_pUsageSlot; // [rsp+58h] [rbp+20h] BYREF

  out_pUsageSlot = 0i64;
  CAkBankMgr::GetMedia(g_pBankManager, &result, in_uSourceID, &out_pUsageSlot);
  if ( !result.pInMemoryData )
    return 0i64;
  v6 = CAkKeyArray<unsigned long,AkDataReference,2>::Set(this, in_uDataIdx);
  v7 = v6;
  if ( v6 )
  {
    v6->pData = result.pInMemoryData;
    uInMemoryDataSize = result.uInMemoryDataSize;
    v7->uSourceID = in_uSourceID;
    v7->uSize = uInMemoryDataSize;
    v7->pUsageSlot = out_pUsageSlot;
    return v7;
  }
  CAkBankMgr::ReleaseMedia(g_pBankManager, in_uSourceID);
  if ( !out_pUsageSlot )
    return v7;
  CAkUsageSlot::Release(out_pUsageSlot, 0);
  return 0i64;
}

// File Line: 89
// RVA: 0xA852D0
AK::IAkStreamMgr *__fastcall CAkEffectContextBase::GetStreamMgr(CAkSourceFXContext *this)
{
  return AK::IAkStreamMgr::m_pStreamMgr;
}

// File Line: 138
// RVA: 0xA853D0
char __fastcall CAkEffectContextBase::IsUsingThisSlot(
        CAkEffectContextBase *this,
        CAkUsageSlot *in_pUsageSlot,
        AK::IAkPlugin *in_pCorrespondingFX)
{
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rax
  CAkUsageSlot **p_pUsageSlot; // rbx
  unsigned int v8; // r8d
  unsigned int v9; // edx
  AkMediaInfo result; // [rsp+20h] [rbp-28h] BYREF
  CAkUsageSlot *out_pUsageSlot; // [rsp+50h] [rbp+8h] BYREF

  m_pItems = this->m_dataArray.m_pItems;
  if ( m_pItems == &m_pItems[this->m_dataArray.m_uLength] )
    return 0;
  p_pUsageSlot = &m_pItems->item.pUsageSlot;
  while ( *p_pUsageSlot != in_pUsageSlot )
  {
LABEL_12:
    p_pUsageSlot += 4;
    if ( p_pUsageSlot - 3 == (CAkUsageSlot **)&this->m_dataArray.m_pItems[this->m_dataArray.m_uLength] )
      return 0;
  }
  if ( !in_pCorrespondingFX->vfptr->SupportMediaRelocation(in_pCorrespondingFX) )
    return 1;
  v8 = *((_DWORD *)p_pUsageSlot - 1);
  out_pUsageSlot = 0i64;
  CAkBankMgr::GetMedia(g_pBankManager, &result, v8, &out_pUsageSlot);
  if ( !result.pInMemoryData )
    return 1;
  if ( in_pCorrespondingFX->vfptr->RelocateMedia(in_pCorrespondingFX, result.pInMemoryData, (char *)*(p_pUsageSlot - 2)) == AK_Success )
  {
    if ( *(p_pUsageSlot - 2) )
    {
      v9 = *((_DWORD *)p_pUsageSlot - 1);
      if ( v9 != -1 )
      {
        CAkBankMgr::ReleaseMedia(g_pBankManager, v9);
        if ( *p_pUsageSlot )
          CAkUsageSlot::Release(*p_pUsageSlot, 0);
      }
    }
    *(p_pUsageSlot - 2) = (CAkUsageSlot *)result.pInMemoryData;
    *p_pUsageSlot = out_pUsageSlot;
    goto LABEL_12;
  }
  if ( result.pInMemoryData )
  {
    CAkBankMgr::ReleaseMedia(g_pBankManager, *((_DWORD *)p_pUsageSlot - 1));
    if ( out_pUsageSlot )
      CAkUsageSlot::Release(out_pUsageSlot, 0);
  }
  return 1;
}

// File Line: 153
// RVA: 0xA853A0
char __fastcall CAkEffectContextBase::IsUsingThisSlot(CAkEffectContextBase *this, char *in_pData)
{
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rax
  MapStruct<unsigned long,AkDataReference> *v3; // r8

  m_pItems = this->m_dataArray.m_pItems;
  v3 = &m_pItems[this->m_dataArray.m_uLength];
  if ( m_pItems == v3 )
    return 0;
  while ( m_pItems->item.pData != in_pData )
  {
    if ( ++m_pItems == v3 )
      return 0;
  }
  return 1;
}

// File Line: 166
// RVA: 0xA852C0
// attributes: thunk
AK::AkRuntimeEnvironmentMgr *__fastcall CAkSourceFXContext::GetProcessorFeatures(CAkSourceFXContext *this)
{
  return AK::AkRuntimeEnvironmentMgr::Instance();
}

// File Line: 178
// RVA: 0xA84BB0
void __fastcall CAkInsertFXContext::CAkInsertFXContext(
        CAkInsertFXContext *this,
        CAkPBI *in_pCtx,
        unsigned int in_uFXIndex)
{
  this->m_uFXIndex = in_uFXIndex;
  this->m_dataArray.m_pItems = 0i64;
  *(_QWORD *)&this->m_dataArray.m_uLength = 0i64;
  this->vfptr = (AK::IAkPluginContextBaseVtbl *)&CAkInsertFXContext::`vftable;
  this->m_pContext = in_pCtx;
}

// File Line: 212
// RVA: 0xA85090
void __fastcall CAkInsertFXContext::GetPluginMedia(
        CAkInsertFXContext *this,
        unsigned int in_dataIndex,
        char **out_rpData,
        unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rax
  AkDataReferenceArray *p_m_dataArray; // r14
  MapStruct<unsigned long,AkDataReference> *v8; // r10
  AkDataReference *p_item; // rax
  __int64 v11; // r8
  __int64 m_uFXIndex; // rdx
  CAkPBI *m_pContext; // rcx
  unsigned int out_rDataID; // [rsp+30h] [rbp+8h] BYREF

  m_pItems = this->m_dataArray.m_pItems;
  p_m_dataArray = &this->m_dataArray;
  v8 = &m_pItems[this->m_dataArray.m_uLength];
  if ( m_pItems != v8 )
  {
    do
    {
      if ( m_pItems->key == in_dataIndex )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v8 );
    if ( m_pItems != v8 )
    {
      p_item = &m_pItems->item;
      if ( p_item )
        goto LABEL_8;
    }
  }
  v11 = in_dataIndex;
  m_uFXIndex = this->m_uFXIndex;
  m_pContext = this->m_pContext;
  out_rDataID = -1;
  CAkPBI::GetFXDataID(m_pContext, m_uFXIndex, v11, &out_rDataID);
  if ( out_rDataID == -1
    || (p_item = AkDataReferenceArray::AcquireData(p_m_dataArray, in_dataIndex, out_rDataID)) == 0i64 )
  {
    *out_rpData = 0i64;
    *out_rDataSize = 0;
  }
  else
  {
LABEL_8:
    *out_rDataSize = p_item->uSize;
    *out_rpData = p_item->pData;
  }
}

// File Line: 258
// RVA: 0xA84B80
void __fastcall CAkBusFXContext::CAkBusFXContext(
        CAkBusFXContext *this,
        CAkBusFX *in_pBusFX,
        unsigned int in_uFXIndex,
        AK::CAkBusCtx *in_rBusContext)
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
void __fastcall CAkBusFXContext::GetPluginMedia(
        CAkBusFXContext *this,
        unsigned int in_dataIndex,
        char **out_rpData,
        unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rax
  AkDataReferenceArray *p_m_dataArray; // r14
  MapStruct<unsigned long,AkDataReference> *v8; // r10
  AkDataReference *p_item; // rax
  __int64 m_uFXIndex; // rdx
  unsigned int out_rDataID; // [rsp+30h] [rbp+8h] BYREF

  m_pItems = this->m_dataArray.m_pItems;
  p_m_dataArray = &this->m_dataArray;
  v8 = &m_pItems[this->m_dataArray.m_uLength];
  if ( m_pItems != v8 )
  {
    do
    {
      if ( m_pItems->key == in_dataIndex )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v8 );
    if ( m_pItems != v8 )
    {
      p_item = &m_pItems->item;
      if ( p_item )
        goto LABEL_8;
    }
  }
  m_uFXIndex = this->m_uFXIndex;
  out_rDataID = -1;
  AK::CAkBusCtx::GetFXDataID(&this->m_BuxCtx, m_uFXIndex, in_dataIndex, &out_rDataID);
  if ( out_rDataID == -1
    || (p_item = AkDataReferenceArray::AcquireData(p_m_dataArray, in_dataIndex, out_rDataID)) == 0i64 )
  {
    *out_rpData = 0i64;
    *out_rDataSize = 0;
  }
  else
  {
LABEL_8:
    *out_rDataSize = p_item->uSize;
    *out_rpData = p_item->pData;
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
void __fastcall CAkSourceFXContext::GetPluginMedia(
        CAkSourceFXContext *this,
        unsigned int in_dataIndex,
        char **out_rpData,
        unsigned int *out_rDataSize)
{
  MapStruct<unsigned long,AkDataReference> *m_pItems; // rax
  AkDataReferenceArray *p_m_dataArray; // r15
  MapStruct<unsigned long,AkDataReference> *i; // r10
  AkDataReference *p_item; // rax
  CAkIndexable *PtrAndAddRef; // rax
  unsigned int *v12; // rdx
  _DWORD *v13; // rax
  _DWORD *v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // edi

  m_pItems = this->m_dataArray.m_pItems;
  p_m_dataArray = &this->m_dataArray;
  for ( i = &m_pItems[this->m_dataArray.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->key == in_dataIndex )
      break;
  }
  if ( m_pItems != i )
  {
    p_item = &m_pItems->item;
    if ( p_item )
      goto LABEL_16;
  }
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                   this->m_pContext->m_pSource->m_sSrcTypeInfo.mediaInfo.sourceID);
  v12 = (unsigned int *)PtrAndAddRef;
  if ( !PtrAndAddRef )
    goto LABEL_17;
  v13 = *(_DWORD **)&PtrAndAddRef[1].key;
  v14 = &v13[2 * v12[12]];
  if ( v13 == v14 )
    goto LABEL_13;
  do
  {
    if ( *v13 == in_dataIndex )
      break;
    v13 += 2;
  }
  while ( v13 != v14 );
  if ( v13 == v14 || (v15 = v13 + 1) == 0i64 )
LABEL_13:
    v16 = 0;
  else
    v16 = *v15;
  (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v12 + 16i64))(v12);
  if ( v16 != -1 && (p_item = AkDataReferenceArray::AcquireData(p_m_dataArray, in_dataIndex, v16)) != 0i64 )
  {
LABEL_16:
    *out_rDataSize = p_item->uSize;
    *out_rpData = p_item->pData;
  }
  else
  {
LABEL_17:
    *out_rpData = 0i64;
    *out_rDataSize = 0;
  }
}

