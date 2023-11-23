// File Line: 39
// RVA: 0xA855B0
void __fastcall CAkLayer::~CAkLayer(CAkLayer *this)
{
  unsigned int v2; // esi
  __int64 i; // rdi
  unsigned int m_crossfadingRTPCID; // r8d
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  CAkParameterNode **p_m_pChild; // rdi
  CAkParameterNode *v7; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkLayer::`vftable;
  v2 = 0;
  for ( i = 1i64; this->m_RTPCBitArray.m_iBitArray; ++v2 )
  {
    if ( (this->m_RTPCBitArray.m_iBitArray & (unsigned int)i) != 0 )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, this, v2);
      this->m_RTPCBitArray.m_iBitArray &= ~(_DWORD)i;
    }
    i = __ROL8__(i, 1);
  }
  m_crossfadingRTPCID = this->m_crossfadingRTPCID;
  if ( m_crossfadingRTPCID )
    CAkRTPCMgr::UnregisterLayer(g_pRTPCMgr, this, m_crossfadingRTPCID);
  m_pItems = this->m_assocs.m_pItems;
  if ( m_pItems != &m_pItems[this->m_assocs.m_uLength] )
  {
    p_m_pChild = &m_pItems->item.m_pChild;
    do
    {
      if ( *p_m_pChild )
      {
        CAkParameterNode::DissociateLayer(*p_m_pChild, this);
        *p_m_pChild = 0i64;
      }
      *p_m_pChild = 0i64;
      *((_DWORD *)p_m_pChild - 2) = 0;
      v7 = p_m_pChild[1];
      if ( v7 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
        p_m_pChild[1] = 0i64;
      }
      p_m_pChild[2] = 0i64;
      p_m_pChild += 5;
    }
    while ( p_m_pChild - 2 != (CAkParameterNode **)&this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
  }
  if ( this->m_assocs.m_pItems )
  {
    this->m_assocs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_assocs.m_pItems);
    this->m_assocs.m_pItems = 0i64;
    this->m_assocs.m_ulReserved = 0;
  }
  CAkIndexable::~CAkIndexable(this);
}

// File Line: 65
// RVA: 0xA85830
CAkLayer *__fastcall CAkLayer::Create(unsigned int in_ulID)
{
  CAkLayer *result; // rax
  CAkLayer *v3; // rbx

  result = (CAkLayer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkLayer::`vftable;
    v3->m_assocs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_assocs.m_uLength = 0i64;
    v3->m_RTPCBitArray.m_iBitArray = 0;
    v3->m_pOwner = 0i64;
    v3->m_crossfadingRTPCID = 0;
    CAkLayer::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 141
// RVA: 0xA858A0
__int64 __fastcall CAkLayer::GetAudioParameters(
        CAkLayer *this,
        CAkParameterNode *in_pAssociatedChild,
        AkSoundParams *io_Parameters,
        char in_ulParamSelect,
        CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap,
        CAkRegisteredObj *in_GameObjPtr)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rbx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *i; // rax
  CAkRegisteredObj *v11; // rbp
  unsigned int m_crossfadingRTPCID; // edx
  unsigned int v13; // edx
  float DefaultValue; // xmm0_4
  float v15; // xmm2_4
  AkMutedMapItem v17; // [rsp+30h] [rbp-38h] BYREF
  float out_value; // [rsp+70h] [rbp+8h] BYREF
  unsigned int out_index; // [rsp+78h] [rbp+10h] BYREF
  bool out_bGameObjectSpecificValue; // [rsp+88h] [rbp+20h] BYREF

  m_pItems = this->m_assocs.m_pItems;
  for ( i = &m_pItems[this->m_assocs.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->key == in_pAssociatedChild->key )
      break;
  }
  v11 = in_GameObjPtr;
  if ( (in_ulParamSelect & 1) != 0 && (this->m_RTPCBitArray.m_iBitArray & 1) != 0 )
    io_Parameters->Volume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0, in_GameObjPtr)
                          + io_Parameters->Volume;
  if ( (in_ulParamSelect & 2) != 0 && (this->m_RTPCBitArray.m_iBitArray & 4) != 0 )
    io_Parameters->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 2u, v11) + io_Parameters->Pitch;
  if ( (in_ulParamSelect & 4) != 0 && (this->m_RTPCBitArray.m_iBitArray & 8) != 0 )
    io_Parameters->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 3u, v11) + io_Parameters->LPF;
  m_crossfadingRTPCID = this->m_crossfadingRTPCID;
  if ( m_crossfadingRTPCID && m_pItems->item.m_fadeCurve.m_pArrayGraphPoints )
  {
    out_bGameObjectSpecificValue = 1;
    if ( CAkRTPCMgr::GetRTPCValue(g_pRTPCMgr, m_crossfadingRTPCID, v11, &out_value, &out_bGameObjectSpecificValue) )
    {
      DefaultValue = out_value;
    }
    else
    {
      v13 = this->m_crossfadingRTPCID;
      out_bGameObjectSpecificValue = 0;
      DefaultValue = CAkRTPCMgr::GetDefaultValue(g_pRTPCMgr, v13, 0i64);
      out_value = DefaultValue;
    }
    v15 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
            &m_pItems->item.m_fadeCurve,
            DefaultValue,
            0,
            &out_index);
    if ( v15 != 1.0 || out_bGameObjectSpecificValue )
    {
      v17.m_Identifier = this;
      *((_DWORD *)&v17 + 2) = *((_DWORD *)&v17 + 2) & 0xFFFFFFFC | !out_bGameObjectSpecificValue;
      CAkKeyArray<AkMutedMapItem,float,2>::Set(io_rMutedMap, &v17, v15);
    }
  }
  return 1i64;
}

// File Line: 212
// RVA: 0xA862F0
__int64 __fastcall CAkLayer::SetParamComplexFromRTPCManager(
        CAkLayer *this,
        _QWORD *in_pToken,
        AkRTPC_ParameterID in_Param_id,
        unsigned int in_RTPCid,
        float in_value,
        CAkRegisteredObj *in_GameObj,
        void *in_pGameObjExceptArray)
{
  float RTPCConvertedValue; // xmm0_4

  RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, in_pToken, in_GameObj, in_RTPCid);
  CAkLayer::Notification(this, in_Param_id, in_value - RTPCConvertedValue, in_GameObj, in_pGameObjExceptArray);
  return 1i64;
}

// File Line: 223
// RVA: 0xA85D00
void __fastcall CAkLayer::RecalcNotification(CAkLayer *this)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  CAkParameterNode **p_m_pChild; // rbx
  CAkParameterNode *v4; // rcx
  AkActivityChunk *m_pActivityChunk; // rax

  m_pItems = this->m_assocs.m_pItems;
  if ( m_pItems != &m_pItems[this->m_assocs.m_uLength] )
  {
    p_m_pChild = &m_pItems->item.m_pChild;
    do
    {
      v4 = *p_m_pChild;
      if ( *p_m_pChild )
      {
        m_pActivityChunk = v4->m_pActivityChunk;
        if ( m_pActivityChunk )
        {
          if ( m_pActivityChunk->m_PlayCount )
            v4->vfptr[12].Category(v4);
        }
      }
      p_m_pChild += 5;
    }
    while ( p_m_pChild - 2 != (CAkParameterNode **)&this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
  }
}

// File Line: 234
// RVA: 0xA857C0
void __fastcall CAkLayer::AddToIndex(CAkLayer *this)
{
  CAkIndexItem<CAkLayer *> *p_m_idxLayers; // rdi
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  p_m_idxLayers = &g_pIndex->m_idxLayers;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = &p_m_idxLayers->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v3[5];
  v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxLayers->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxLayers->m_IndexLock.m_csLock);
}

// File Line: 246
// RVA: 0xA85770
__int64 __fastcall CAkLayer::AddRef(CAkLayer *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxLayers.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 252
// RVA: 0xA85D70
__int64 __fastcall CAkLayer::Release(CAkLayer *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxLayers, this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxLayers.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 265
// RVA: 0xA85B90
void __fastcall CAkLayer::Notification(
        CAkLayer *this,
        AkRTPC_ParameterID in_eType,
        float in_fValue,
        CAkRegisteredObj *in_pGameObj,
        void *in_pExceptArray)
{
  __int64 m_uLength; // rdx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  CAkParameterNode **p_m_pChild; // rbx
  CAkParameterNode *v9; // rcx
  AkActivityChunk *m_pActivityChunk; // rax
  AkRTPC_ParameterID v11; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v12; // [rsp+28h] [rbp-30h]
  char v13; // [rsp+30h] [rbp-28h]
  void *v14; // [rsp+38h] [rbp-20h]
  float v15; // [rsp+40h] [rbp-18h]

  v11 = in_eType;
  m_uLength = this->m_assocs.m_uLength;
  v15 = in_fValue;
  v14 = in_pExceptArray;
  m_pItems = this->m_assocs.m_pItems;
  v13 = 0;
  v12 = in_pGameObj;
  if ( m_pItems != &m_pItems[m_uLength] )
  {
    p_m_pChild = &m_pItems->item.m_pChild;
    do
    {
      v9 = *p_m_pChild;
      if ( *p_m_pChild )
      {
        m_pActivityChunk = v9->m_pActivityChunk;
        if ( m_pActivityChunk )
        {
          if ( m_pActivityChunk->m_PlayCount )
            v9->vfptr[5].__vecDelDtor(v9, (unsigned int)&v11);
        }
      }
      p_m_pChild += 5;
    }
    while ( p_m_pChild - 2 != (CAkParameterNode **)&this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
  }
}

// File Line: 292
// RVA: 0xA85B40
char __fastcall CAkLayer::IsPlaying(CAkLayer *this)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v2; // r8
  CAkParameterNode **p_m_pChild; // rax
  AkActivityChunk *m_pActivityChunk; // rdx

  m_pItems = this->m_assocs.m_pItems;
  v2 = &m_pItems[this->m_assocs.m_uLength];
  if ( m_pItems == v2 )
    return 0;
  p_m_pChild = &m_pItems->item.m_pChild;
  while ( 1 )
  {
    if ( *p_m_pChild )
    {
      m_pActivityChunk = (*p_m_pChild)->m_pActivityChunk;
      if ( m_pActivityChunk )
      {
        if ( m_pActivityChunk->m_PlayCount )
          break;
      }
    }
    p_m_pChild += 5;
    if ( p_m_pChild - 2 == (CAkParameterNode **)v2 )
      return 0;
  }
  return 1;
}

// File Line: 306
// RVA: 0xA86050
__int64 __fastcall CAkLayer::SetInitialRTPC(CAkLayer *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  unsigned int *v3; // rax
  unsigned int v6; // edx
  __int64 v8; // rbp
  unsigned int v9; // r8d
  char *v10; // rax
  AkRTPC_ParameterID v11; // r9d
  unsigned int in_RTPCCurveID; // r11d
  AkCurveScaling in_eScaling; // edx
  __int64 in_ulConversionArraySize; // rdi

  v3 = (unsigned int *)*io_rpData;
  v6 = *(unsigned __int16 *)*io_rpData;
  *io_rpData = (char *)v3 + 2;
  if ( v6 )
  {
    v8 = v6;
    do
    {
      v9 = *(_DWORD *)*io_rpData;
      v10 = *io_rpData + 4;
      *io_rpData = v10;
      v11 = *(_DWORD *)v10;
      v10 += 4;
      *io_rpData = v10;
      in_RTPCCurveID = *(_DWORD *)v10;
      v10 += 4;
      *io_rpData = v10;
      in_eScaling = (unsigned __int8)*v10++;
      *io_rpData = v10;
      in_ulConversionArraySize = *(unsigned __int16 *)v10;
      *io_rpData = v10 + 2;
      this->m_RTPCBitArray.m_iBitArray |= 1i64 << v11;
      CAkRTPCMgr::SubscribeRTPC(
        g_pRTPCMgr,
        this,
        v9,
        v11,
        in_RTPCCurveID,
        in_eScaling,
        (AkRTPCGraphPointBase<float> *)(v10 + 2),
        in_ulConversionArraySize,
        0i64,
        SubscriberType_CAkLayer);
      *io_rpData += 12 * in_ulConversionArraySize;
      *io_rulDataSize += -12 * in_ulConversionArraySize;
      --v8;
    }
    while ( v8 );
  }
  return 1i64;
}

// File Line: 338
// RVA: 0xA86140
__int64 __fastcall CAkLayer::SetInitialValues(CAkLayer *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  __int64 result; // rax
  unsigned int v7; // edx
  unsigned int v8; // r14d
  unsigned int i; // esi
  unsigned int v10; // edx
  char *v11; // rax
  __int64 v12; // rdi
  unsigned int v13; // r9d

  *io_rpData += 4;
  result = CAkLayer::SetInitialRTPC(this, io_rpData, io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v7 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    result = CAkLayer::SetCrossfadingRTPC(this, v7);
    if ( (_DWORD)result == 1 )
    {
      v8 = *(_DWORD *)*io_rpData;
      *io_rpData += 4;
      if ( v8 )
      {
        result = AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Reserve(
                   &this->m_assocs,
                   v8);
        if ( (_DWORD)result == 1 )
        {
          for ( i = 0; i < v8; ++i )
          {
            v10 = *(_DWORD *)*io_rpData;
            v11 = *io_rpData + 4;
            *io_rpData = v11;
            v12 = *(unsigned int *)v11;
            v13 = *(_DWORD *)v11;
            *io_rpData = v11 + 4;
            result = CAkLayer::SetChildAssoc(this, v10, (AkRTPCGraphPointBase<float> *)(v11 + 4), v13);
            if ( (_DWORD)result != 1 )
              break;
            *io_rpData += 12 * v12;
            *io_rulDataSize += -12 * v12;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 430
// RVA: 0xA85ED0
__int64 __fastcall CAkLayer::SetChildAssoc(
        CAkLayer *this,
        unsigned int in_ChildID,
        AkRTPCGraphPointBase<float> *in_pCrossfadingCurve,
        unsigned int in_ulCrossfadingCurveSize)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  CAkKeyArray<unsigned long,CAkLayer::CAssociatedChildData,1> *p_m_assocs; // r14
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *i; // r10
  CAkLayer::CAssociatedChildData *p_item; // rbx
  AKRESULT updated; // edi
  CAkLayer::CAssociatedChildData *v13; // rax
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  CAkParameterNode *m_pChild; // rcx

  m_pItems = this->m_assocs.m_pItems;
  p_m_assocs = &this->m_assocs;
  for ( i = &m_pItems[this->m_assocs.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->key == in_ChildID )
      break;
  }
  if ( m_pItems != i )
  {
    p_item = &m_pItems->item;
    updated = AK_Success;
    goto LABEL_6;
  }
  v13 = CAkKeyArray<unsigned long,CAkLayer::CAssociatedChildData,1>::Set(&this->m_assocs, in_ChildID);
  p_item = v13;
  if ( v13 )
  {
    v13->m_ulChildID = in_ChildID;
    updated = CAkLayer::CAssociatedChildData::UpdateChildPtr(v13, this);
    if ( updated != AK_Success )
    {
      CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Unset(
        (CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *)p_m_assocs,
        in_ChildID);
      return (unsigned int)updated;
    }
LABEL_6:
    if ( in_ulCrossfadingCurveSize )
    {
      updated = (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                                &p_item->m_fadeCurve,
                                in_pCrossfadingCurve,
                                in_ulCrossfadingCurveSize,
                                AkCurveScaling_None);
    }
    else
    {
      m_pArrayGraphPoints = p_item->m_fadeCurve.m_pArrayGraphPoints;
      if ( m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
        p_item->m_fadeCurve.m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&p_item->m_fadeCurve.m_ulArraySize = 0i64;
    }
    m_pChild = p_item->m_pChild;
    if ( m_pChild )
    {
      m_pChild->vfptr[12].Category(m_pChild);
      return (unsigned int)updated;
    }
    return (unsigned int)updated;
  }
  return 52i64;
}

// File Line: 486
// RVA: 0xA86350
__int64 __fastcall CAkLayer::UnsetChildAssoc(CAkLayer *this, unsigned int in_ChildID)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rdi
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax
  CAkParameterNode *m_pChild; // rcx
  unsigned int v6; // ebp
  unsigned int v7; // eax
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v9; // rdx

  m_pItems = this->m_assocs.m_pItems;
  v4 = &m_pItems[this->m_assocs.m_uLength];
  if ( m_pItems == v4 )
    return 16i64;
  do
  {
    if ( m_pItems->key == in_ChildID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v4 );
  if ( m_pItems == v4 )
    return 16i64;
  m_pChild = m_pItems->item.m_pChild;
  v6 = 1;
  if ( m_pChild )
  {
    v7 = CAkParameterNode::DissociateLayer(m_pChild, this);
    m_pItems->item.m_pChild = 0i64;
    v6 = v7;
  }
  m_pItems->item.m_pChild = 0i64;
  m_pItems->item.m_ulChildID = 0;
  m_pArrayGraphPoints = m_pItems->item.m_fadeCurve.m_pArrayGraphPoints;
  if ( m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
    m_pItems->item.m_fadeCurve.m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&m_pItems->item.m_fadeCurve.m_ulArraySize = 0i64;
  v9 = &this->m_assocs.m_pItems[this->m_assocs.m_uLength - 1];
  if ( m_pItems < v9 )
    qmemcpy(m_pItems, &m_pItems[1], 40 * (((char *)v9 - (char *)m_pItems - 1) / 0x28ui64 + 1));
  --this->m_assocs.m_uLength;
  return v6;
}

// File Line: 500
// RVA: 0xA86220
void __fastcall CAkLayer::SetOwner(CAkLayer *this, CAkLayerCntr *in_pOwner)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  CAkParameterNode **p_m_pChild; // rbx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v6; // rbx

  if ( this->m_pOwner )
  {
    m_pItems = this->m_assocs.m_pItems;
    if ( m_pItems != &m_pItems[this->m_assocs.m_uLength] )
    {
      p_m_pChild = &m_pItems->item.m_pChild;
      do
      {
        if ( *p_m_pChild )
        {
          CAkParameterNode::DissociateLayer(*p_m_pChild, this);
          *p_m_pChild = 0i64;
        }
        p_m_pChild += 5;
      }
      while ( p_m_pChild - 2 != (CAkParameterNode **)&this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
    }
  }
  this->m_pOwner = in_pOwner;
  if ( in_pOwner )
  {
    v6 = this->m_assocs.m_pItems;
    if ( v6 != &v6[this->m_assocs.m_uLength] )
    {
      do
      {
        CAkLayer::CAssociatedChildData::UpdateChildPtr(&v6->item, this);
        ++v6;
      }
      while ( v6 != &this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
    }
  }
}

// File Line: 525
// RVA: 0xA86450
void __fastcall CAkLayer::UpdateChildPtr(CAkLayer *this, unsigned int in_ChildID)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rcx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax

  m_pItems = this->m_assocs.m_pItems;
  v4 = &m_pItems[this->m_assocs.m_uLength];
  if ( m_pItems != v4 )
  {
    do
    {
      if ( m_pItems->key == in_ChildID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v4 );
    if ( m_pItems != v4 )
      CAkLayer::CAssociatedChildData::UpdateChildPtr(&m_pItems->item, this);
  }
}

// File Line: 543
// RVA: 0xA85FD0
__int64 __fastcall CAkLayer::SetCrossfadingRTPC(CAkLayer *this, unsigned int in_rtpcID)
{
  unsigned int m_crossfadingRTPCID; // r8d
  AKRESULT v5; // edi

  m_crossfadingRTPCID = this->m_crossfadingRTPCID;
  v5 = AK_Success;
  if ( m_crossfadingRTPCID != in_rtpcID )
  {
    if ( m_crossfadingRTPCID )
      CAkRTPCMgr::UnregisterLayer(g_pRTPCMgr, this, m_crossfadingRTPCID);
    this->m_crossfadingRTPCID = in_rtpcID;
    if ( in_rtpcID )
    {
      v5 = CAkRTPCMgr::RegisterLayer(g_pRTPCMgr, this, in_rtpcID);
      if ( v5 != AK_Success )
        this->m_crossfadingRTPCID = 0;
    }
    CAkLayer::RecalcNotification(this);
  }
  return (unsigned int)v5;
}

// File Line: 581
// RVA: 0xA86560
void __fastcall LayerMuteFunc(CAkPBI *in_pPBI, CAkRegisteredObj *__formal, void *in_pCookie)
{
  float v5; // xmm0_4
  unsigned int out_index; // [rsp+40h] [rbp+18h] BYREF

  if ( !*((_BYTE *)in_pCookie + 32) )
  {
    v5 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           *((CAkConversionTable<AkRTPCGraphPointBase<float>,float> **)in_pCookie + 2),
           *((float *)in_pCookie + 6),
           0,
           &out_index);
    *((_BYTE *)in_pCookie + 32) = 1;
    *((float *)in_pCookie + 7) = v5;
  }
  CAkPBI::MuteNotification(in_pPBI, *((float *)in_pCookie + 7), (AkMutedMapItem *)in_pCookie, 1);
}

// File Line: 593
// RVA: 0xA85C30
void __fastcall CAkLayer::OnRTPCChanged(CAkLayer *this, CAkRegisteredObj *in_GameObjPtr, float in_fValue)
{
  unsigned int v5; // r8d
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *m_pItems; // rax
  __int64 m_uLength; // rdx
  CAkParameterNode **p_m_pChild; // rbx
  AkActivityChunk *m_pActivityChunk; // rcx
  CAkLayer *v10; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v11; // [rsp+28h] [rbp-30h]
  _QWORD *v12; // [rsp+30h] [rbp-28h]
  float v13; // [rsp+38h] [rbp-20h]
  char v14; // [rsp+40h] [rbp-18h]

  if ( this->m_assocs.m_uLength )
  {
    v10 = this;
    v13 = in_fValue;
    v5 = v11 & 0xFFFFFFFC | (in_GameObjPtr == 0i64);
    m_pItems = this->m_assocs.m_pItems;
    m_uLength = this->m_assocs.m_uLength;
    v11 = v5;
    if ( m_pItems != &m_pItems[m_uLength] )
    {
      p_m_pChild = &m_pItems->item.m_pChild;
      do
      {
        if ( *p_m_pChild )
        {
          m_pActivityChunk = (*p_m_pChild)->m_pActivityChunk;
          if ( m_pActivityChunk )
          {
            if ( m_pActivityChunk->m_PlayCount )
            {
              v14 = 0;
              v12 = p_m_pChild + 1;
              ((void (__fastcall *)(CAkParameterNode *, void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *, CAkLayer **))(*p_m_pChild)->vfptr[6].Release)(
                *p_m_pChild,
                LayerMuteFunc,
                in_GameObjPtr,
                &v10);
            }
          }
        }
        p_m_pChild += 5;
      }
      while ( p_m_pChild - 2 != (CAkParameterNode **)&this->m_assocs.m_pItems[this->m_assocs.m_uLength] );
    }
  }
}

// File Line: 666
// RVA: 0xA86490
__int64 __fastcall CAkLayer::CAssociatedChildData::UpdateChildPtr(
        CAkLayer::CAssociatedChildData *this,
        ITransitionable *in_pLayer)
{
  unsigned int v5; // ebx
  CAkParameterNode *NodePtrAndAddRef; // rdi
  CAkLayerCntr *vfptr; // rcx
  int v8; // eax
  CAkLayerCntr *m_pParentNode; // rdx

  if ( this->m_pChild )
    return 1i64;
  v5 = 1;
  NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(
                                           g_pIndex,
                                           this->m_ulChildID,
                                           AkNodeType_Default);
  if ( NodePtrAndAddRef )
  {
    vfptr = (CAkLayerCntr *)in_pLayer[6].vfptr;
    v8 = 2;
    if ( vfptr && (m_pParentNode = (CAkLayerCntr *)NodePtrAndAddRef->m_pParentNode) != 0i64 )
    {
      if ( m_pParentNode == vfptr )
        v8 = 1;
    }
    else
    {
      v8 = 3;
    }
    if ( v8 == 1 )
    {
      this->m_pChild = NodePtrAndAddRef;
      v5 = CAkParameterNode::AssociateLayer(NodePtrAndAddRef, in_pLayer);
      if ( v5 != 1 )
        this->m_pChild = 0i64;
    }
    else
    {
      if ( v8 == 3 )
        v8 = 1;
      v5 = v8;
    }
    NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  }
  return v5;
}

