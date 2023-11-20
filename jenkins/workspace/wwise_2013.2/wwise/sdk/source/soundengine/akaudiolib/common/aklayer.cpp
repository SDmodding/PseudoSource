// File Line: 39
// RVA: 0xA855B0
void __fastcall CAkLayer::~CAkLayer(CAkLayer *this)
{
  CAkLayer *v1; // rbx
  unsigned int v2; // esi
  signed __int64 i; // rdi
  unsigned int v4; // er8
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v5; // rax
  signed __int64 v6; // rdi
  void *v7; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkLayer::`vftable;
  v2 = 0;
  for ( i = 1i64; v1->m_RTPCBitArray.m_iBitArray; ++v2 )
  {
    if ( v1->m_RTPCBitArray.m_iBitArray & (unsigned int)i )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v1, v2);
      v1->m_RTPCBitArray.m_iBitArray &= ~(_DWORD)i;
    }
    i = __ROL8__(i, 1);
  }
  v4 = v1->m_crossfadingRTPCID;
  if ( v4 )
    CAkRTPCMgr::UnregisterLayer(g_pRTPCMgr, v1, v4);
  v5 = v1->m_assocs.m_pItems;
  if ( v5 != &v5[v1->m_assocs.m_uLength] )
  {
    v6 = (signed __int64)&v5->item.m_pChild;
    do
    {
      if ( *(_QWORD *)v6 )
      {
        CAkParameterNode::DissociateLayer(*(CAkParameterNode **)v6, v1);
        *(_QWORD *)v6 = 0i64;
      }
      *(_QWORD *)v6 = 0i64;
      *(_DWORD *)(v6 - 8) = 0;
      v7 = *(void **)(v6 + 8);
      if ( v7 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
        *(_QWORD *)(v6 + 8) = 0i64;
      }
      *(_QWORD *)(v6 + 16) = 0i64;
      v6 += 40i64;
    }
    while ( (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)(v6 - 16) != &v1->m_assocs.m_pItems[v1->m_assocs.m_uLength] );
  }
  if ( v1->m_assocs.m_pItems )
  {
    v1->m_assocs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_assocs.m_pItems);
    v1->m_assocs.m_pItems = 0i64;
    v1->m_assocs.m_ulReserved = 0;
  }
  CAkIndexable::~CAkIndexable((CAkIndexable *)&v1->vfptr);
}

// File Line: 65
// RVA: 0xA85830
CAkLayer *__fastcall CAkLayer::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkLayer *result; // rax
  CAkLayer *v3; // rbx

  v1 = in_ulID;
  result = (CAkLayer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v3 = result;
  if ( result )
  {
    CAkIndexable::CAkIndexable((CAkIndexable *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkLayer::`vftable;
    v3->m_assocs.m_pItems = 0i64;
    *(_QWORD *)&v3->m_assocs.m_uLength = 0i64;
    v3->m_RTPCBitArray.m_iBitArray = 0;
    v3->m_pOwner = 0i64;
    v3->m_crossfadingRTPCID = 0;
    CAkLayer::AddToIndex(v3);
    result = v3;
  }
  return result;
}

// File Line: 141
// RVA: 0xA858A0
signed __int64 __fastcall CAkLayer::GetAudioParameters(CAkLayer *this, CAkParameterNode *in_pAssociatedChild, AkSoundParams *io_Parameters, unsigned int in_ulParamSelect, CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap, CAkRegisteredObj *in_GameObjPtr)
{
  CAkLayer *v6; // rdi
  char v7; // r14
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v8; // rbx
  AkSoundParams *v9; // rsi
  signed __int64 i; // rax
  CAkRegisteredObj *v11; // rbp
  unsigned int v12; // edx
  unsigned int v13; // edx
  float v14; // xmm0_4
  float v15; // xmm2_4
  CAkKeyArray<AkMutedMapItem,float,2> *v16; // rcx
  AkMutedMapItem v18; // [rsp+30h] [rbp-38h]
  float out_value; // [rsp+70h] [rbp+8h]
  unsigned int out_index; // [rsp+78h] [rbp+10h]
  bool out_bGameObjectSpecificValue; // [rsp+88h] [rbp+20h]

  v6 = this;
  v7 = in_ulParamSelect;
  v8 = this->m_assocs.m_pItems;
  v9 = io_Parameters;
  for ( i = (signed __int64)&v8[this->m_assocs.m_uLength];
        v8 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)i;
        ++v8 )
  {
    if ( v8->key == in_pAssociatedChild->key )
      break;
  }
  v11 = in_GameObjPtr;
  if ( in_ulParamSelect & 1 && this->m_RTPCBitArray.m_iBitArray & 1 )
    io_Parameters->Volume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0, in_GameObjPtr)
                          + io_Parameters->Volume;
  if ( v7 & 2 && (v6->m_RTPCBitArray.m_iBitArray >> 2) & 1 )
    v9->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v6, 2u, v11) + v9->Pitch;
  if ( v7 & 4 && (v6->m_RTPCBitArray.m_iBitArray >> 3) & 1 )
    v9->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v6, 3u, v11) + v9->LPF;
  v12 = v6->m_crossfadingRTPCID;
  if ( v12 && v8->item.m_fadeCurve.m_pArrayGraphPoints )
  {
    out_bGameObjectSpecificValue = 1;
    if ( CAkRTPCMgr::GetRTPCValue(g_pRTPCMgr, v12, v11, &out_value, &out_bGameObjectSpecificValue) )
    {
      v14 = out_value;
    }
    else
    {
      v13 = v6->m_crossfadingRTPCID;
      out_bGameObjectSpecificValue = 0;
      v14 = CAkRTPCMgr::GetDefaultValue(g_pRTPCMgr, v13, 0i64);
      out_value = v14;
    }
    v15 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
            &v8->item.m_fadeCurve,
            v14,
            0,
            &out_index);
    if ( v15 != 1.0 || out_bGameObjectSpecificValue )
    {
      v18.m_Identifier = v6;
      *((_DWORD *)&v18 + 2) = *((_DWORD *)&v18 + 2) & 0xFFFFFFFC | (out_bGameObjectSpecificValue == 0);
      v16 = io_rMutedMap;
      _mm_store_si128((__m128i *)&v18, (__m128i)v18);
      CAkKeyArray<AkMutedMapItem,float,2>::Set(v16, &v18, v15);
    }
  }
  return 1i64;
}

// File Line: 212
// RVA: 0xA862F0
signed __int64 __fastcall CAkLayer::SetParamComplexFromRTPCManager(CAkLayer *this, void *in_pToken, AkRTPC_ParameterID in_Param_id, unsigned int in_RTPCid, float in_value, CAkRegisteredObj *in_GameObj, void *in_pGameObjExceptArray)
{
  AkRTPC_ParameterID v7; // esi
  CAkLayer *v8; // rdi
  float v9; // xmm0_4

  v7 = in_Param_id;
  v8 = this;
  v9 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, in_pToken, in_GameObj, in_RTPCid);
  CAkLayer::Notification(v8, v7, in_value - v9, in_GameObj, in_pGameObjExceptArray);
  return 1i64;
}

// File Line: 223
// RVA: 0xA85D00
void __fastcall CAkLayer::RecalcNotification(CAkLayer *this)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v1; // rax
  CAkLayer *v2; // rdi
  CAkParameterNode **v3; // rbx
  CAkParameterNode *v4; // rcx
  AkActivityChunk *v5; // rax

  v1 = this->m_assocs.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_assocs.m_uLength] )
  {
    v3 = &v1->item.m_pChild;
    do
    {
      v4 = *v3;
      if ( *v3 )
      {
        v5 = v4->m_pActivityChunk;
        if ( v5 )
        {
          if ( v5->m_PlayCount )
            ((void (*)(void))v4->vfptr[12].Category)();
        }
      }
      v3 += 5;
    }
    while ( v3 - 2 != (CAkParameterNode **)&v2->m_assocs.m_pItems[v2->m_assocs.m_uLength] );
  }
}

// File Line: 234
// RVA: 0xA857C0
void __fastcall CAkLayer::AddToIndex(CAkLayer *this)
{
  CAkLayer *v1; // rbx
  CAkIndexItem<CAkLayer *> *v2; // rdi
  signed __int64 v3; // rdx

  v1 = this;
  v2 = &g_pIndex->m_idxLayers;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v3 + 40);
  *(_QWORD *)(v3 + 40) = v1;
  ++v2->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
}

// File Line: 246
// RVA: 0xA85770
__int64 __fastcall CAkLayer::AddRef(CAkLayer *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkLayer *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxLayers.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 252
// RVA: 0xA85D70
__int64 __fastcall CAkLayer::Release(CAkLayer *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkLayer *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxLayers.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxLayers, v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxLayers.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 265
// RVA: 0xA85B90
void __fastcall CAkLayer::Notification(CAkLayer *this, AkRTPC_ParameterID in_eType, float in_fValue, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  __int64 v5; // rdx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v6; // rax
  CAkLayer *v7; // rdi
  CAkParameterNode **v8; // rbx
  CAkParameterNode *v9; // rcx
  AkActivityChunk *v10; // rax
  AkRTPC_ParameterID v11; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v12; // [rsp+28h] [rbp-30h]
  char v13; // [rsp+30h] [rbp-28h]
  void *v14; // [rsp+38h] [rbp-20h]
  float v15; // [rsp+40h] [rbp-18h]

  v11 = in_eType;
  v5 = this->m_assocs.m_uLength;
  v15 = in_fValue;
  v14 = in_pExceptArray;
  v6 = this->m_assocs.m_pItems;
  v7 = this;
  v13 = 0;
  v12 = in_pGameObj;
  if ( v6 != &v6[v5] )
  {
    v8 = &v6->item.m_pChild;
    do
    {
      v9 = *v8;
      if ( *v8 )
      {
        v10 = v9->m_pActivityChunk;
        if ( v10 )
        {
          if ( v10->m_PlayCount )
            v9->vfptr[5].__vecDelDtor((CAkIndexable *)&v9->vfptr, (unsigned int)&v11);
        }
      }
      v8 += 5;
    }
    while ( v8 - 2 != (CAkParameterNode **)&v7->m_assocs.m_pItems[v7->m_assocs.m_uLength] );
  }
}

// File Line: 292
// RVA: 0xA85B40
char __fastcall CAkLayer::IsPlaying(CAkLayer *this)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v1; // rax
  signed __int64 v2; // r8
  signed __int64 v3; // rax
  __int64 v4; // rdx

  v1 = this->m_assocs.m_pItems;
  v2 = (signed __int64)&v1[this->m_assocs.m_uLength];
  if ( v1 == (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v2 )
    return 0;
  v3 = (signed __int64)&v1->item.m_pChild;
  while ( 1 )
  {
    if ( *(_QWORD *)v3 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)v3 + 48i64);
      if ( v4 )
      {
        if ( *(_WORD *)(v4 + 72) )
          break;
      }
    }
    v3 += 40i64;
    if ( v3 - 16 == v2 )
      return 0;
  }
  return 1;
}

// File Line: 306
// RVA: 0xA86050
signed __int64 __fastcall CAkLayer::SetInitialRTPC(CAkLayer *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char *v3; // rax
  unsigned int **v4; // rbx
  unsigned int *v5; // r14
  unsigned int v6; // edx
  CAkLayer *v7; // rsi
  __int64 v8; // rbp
  unsigned int v9; // er8
  unsigned __int16 *v10; // rax
  AkRTPC_ParameterID v11; // er9
  unsigned int in_RTPCCurveID; // er11
  AkCurveScaling in_eScaling; // edx
  __int64 in_ulConversionArraySize; // rdi

  v3 = *io_rpData;
  v4 = (unsigned int **)io_rpData;
  v5 = io_rulDataSize;
  v6 = *(unsigned __int16 *)*io_rpData;
  v7 = this;
  *v4 = (unsigned int *)(v3 + 2);
  if ( v6 )
  {
    v8 = v6;
    do
    {
      v9 = **v4;
      v10 = (unsigned __int16 *)(*v4 + 1);
      *v4 = (unsigned int *)v10;
      v11 = *(_DWORD *)v10;
      v10 += 2;
      *v4 = (unsigned int *)v10;
      in_RTPCCurveID = *(_DWORD *)v10;
      v10 += 2;
      *v4 = (unsigned int *)v10;
      in_eScaling = *(unsigned __int8 *)v10;
      v10 = (unsigned __int16 *)((char *)v10 + 1);
      *v4 = (unsigned int *)v10;
      in_ulConversionArraySize = *v10;
      *v4 = (unsigned int *)(v10 + 1);
      v7->m_RTPCBitArray.m_iBitArray |= 1i64 << v11;
      CAkRTPCMgr::SubscribeRTPC(
        g_pRTPCMgr,
        v7,
        v9,
        v11,
        in_RTPCCurveID,
        in_eScaling,
        (AkRTPCGraphPointBase<float> *)(v10 + 1),
        in_ulConversionArraySize,
        0i64,
        SubscriberType_CAkLayer);
      *v4 += 3 * in_ulConversionArraySize;
      *v5 += -12 * in_ulConversionArraySize;
      --v8;
    }
    while ( v8 );
  }
  return 1i64;
}

// File Line: 338
// RVA: 0xA86140
signed __int64 __fastcall CAkLayer::SetInitialValues(CAkLayer *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  unsigned int *v3; // rbp
  unsigned int **v4; // rbx
  CAkLayer *v5; // r15
  signed __int64 result; // rax
  unsigned int v7; // edx
  unsigned int v8; // er14
  unsigned int v9; // esi
  unsigned int v10; // edx
  unsigned int *v11; // rax
  __int64 v12; // rdi
  unsigned int v13; // er9

  *io_rpData += 4;
  v3 = io_rulDataSize;
  v4 = (unsigned int **)io_rpData;
  v5 = this;
  result = CAkLayer::SetInitialRTPC(this, io_rpData, io_rulDataSize);
  if ( (_DWORD)result == 1 )
  {
    v7 = **v4;
    ++*v4;
    result = CAkLayer::SetCrossfadingRTPC(v5, v7);
    if ( (_DWORD)result == 1 )
    {
      v8 = **v4;
      ++*v4;
      if ( v8 )
      {
        result = AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Reserve(
                   (AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&v5->m_assocs.m_pItems,
                   v8);
        if ( (_DWORD)result == 1 )
        {
          v9 = 0;
          if ( v8 )
          {
            do
            {
              v10 = **v4;
              v11 = *v4 + 1;
              *v4 = v11;
              v12 = *v11;
              v13 = *v11;
              *v4 = v11 + 1;
              result = CAkLayer::SetChildAssoc(v5, v10, (AkRTPCGraphPointBase<float> *)(v11 + 1), v13);
              if ( (_DWORD)result != 1 )
                break;
              ++v9;
              *v4 += 3 * v12;
              *v3 += -12 * v12;
            }
            while ( v9 < v8 );
          }
        }
      }
    }
  }
  return result;
}

// File Line: 430
// RVA: 0xA85ED0
signed __int64 __fastcall CAkLayer::SetChildAssoc(CAkLayer *this, unsigned int in_ChildID, AkRTPCGraphPointBase<float> *in_pCrossfadingCurve, unsigned int in_ulCrossfadingCurveSize)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax
  CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *v5; // r14
  unsigned int v6; // ebp
  AkRTPCGraphPointBase<float> *v7; // r15
  signed __int64 v8; // r10
  unsigned int v9; // esi
  CAkLayer *i; // rdi
  signed __int64 v11; // rbx
  AKRESULT v12; // edi
  CAkLayer::CAssociatedChildData *v13; // rax
  void *v15; // rdx
  __int64 v16; // rcx

  v4 = this->m_assocs.m_pItems;
  v5 = (CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *)&this->m_assocs;
  v6 = in_ulCrossfadingCurveSize;
  v7 = in_pCrossfadingCurve;
  v8 = (signed __int64)&v4[this->m_assocs.m_uLength];
  v9 = in_ChildID;
  for ( i = this; v4 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v8; ++v4 )
  {
    if ( v4->key == in_ChildID )
      break;
  }
  if ( v4 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v8 )
  {
    v11 = (signed __int64)&v4->item;
    v12 = 1;
    goto LABEL_6;
  }
  v13 = CAkKeyArray<unsigned long,CAkLayer::CAssociatedChildData,1>::Set(&this->m_assocs, in_ChildID);
  v11 = (signed __int64)v13;
  if ( v13 )
  {
    v13->m_ulChildID = v9;
    v12 = CAkLayer::CAssociatedChildData::UpdateChildPtr(v13, i);
    if ( v12 != 1 )
    {
      CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Unset(v5, v9);
      return (unsigned int)v12;
    }
LABEL_6:
    if ( v6 )
    {
      v12 = (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                            (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v11 + 16),
                            v7,
                            v6,
                            0);
    }
    else
    {
      v15 = *(void **)(v11 + 16);
      if ( v15 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v15);
        *(_QWORD *)(v11 + 16) = 0i64;
      }
      *(_QWORD *)(v11 + 24) = 0i64;
    }
    v16 = *(_QWORD *)(v11 + 8);
    if ( v16 )
    {
      (*(void (**)(void))(*(_QWORD *)v16 + 408i64))();
      return (unsigned int)v12;
    }
    return (unsigned int)v12;
  }
  return 52i64;
}

// File Line: 486
// RVA: 0xA86350
signed __int64 __fastcall CAkLayer::UnsetChildAssoc(CAkLayer *this, unsigned int in_ChildID)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v2; // rdi
  CAkLayer *v3; // rbx
  signed __int64 v4; // rax
  CAkParameterNode *v5; // rcx
  unsigned int v6; // ebp
  unsigned int v7; // eax
  AkRTPCGraphPointBase<float> *v8; // rdx
  unsigned __int64 v9; // rdx

  v2 = this->m_assocs.m_pItems;
  v3 = this;
  v4 = (signed __int64)&v2[this->m_assocs.m_uLength];
  if ( v2 == (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 )
    return 16i64;
  do
  {
    if ( v2->key == in_ChildID )
      break;
    ++v2;
  }
  while ( v2 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 );
  if ( v2 == (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 )
    return 16i64;
  v5 = v2->item.m_pChild;
  v6 = 1;
  if ( v5 )
  {
    v7 = CAkParameterNode::DissociateLayer(v5, v3);
    v2->item.m_pChild = 0i64;
    v6 = v7;
  }
  v2->item.m_pChild = 0i64;
  v2->item.m_ulChildID = 0;
  v8 = v2->item.m_fadeCurve.m_pArrayGraphPoints;
  if ( v8 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    v2->item.m_fadeCurve.m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&v2->item.m_fadeCurve.m_ulArraySize = 0i64;
  v9 = (unsigned __int64)v3->m_assocs.m_pItems + 8 * (5i64 * v3->m_assocs.m_uLength - 5);
  if ( (unsigned __int64)v2 < v9 )
    qmemcpy(
      v2,
      &v2[1],
      40
    * (((unsigned __int64)((v9 - (unsigned __int64)v2 - 1) * (unsigned __int128)0xCCCCCCCCCCCCCCCDui64 >> 64) >> 5) + 1));
  --v3->m_assocs.m_uLength;
  return v6;
}

// File Line: 500
// RVA: 0xA86220
void __fastcall CAkLayer::SetOwner(CAkLayer *this, CAkLayerCntr *in_pOwner)
{
  CAkLayer *v2; // rdi
  CAkLayerCntr *v3; // rsi
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax
  CAkParameterNode **v5; // rbx
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v6; // rbx

  v2 = this;
  v3 = in_pOwner;
  if ( this->m_pOwner )
  {
    v4 = this->m_assocs.m_pItems;
    if ( v4 != &v4[this->m_assocs.m_uLength] )
    {
      v5 = &v4->item.m_pChild;
      do
      {
        if ( *v5 )
        {
          CAkParameterNode::DissociateLayer(*v5, v2);
          *v5 = 0i64;
        }
        v5 += 5;
      }
      while ( v5 - 2 != (CAkParameterNode **)&v2->m_assocs.m_pItems[v2->m_assocs.m_uLength] );
    }
  }
  v2->m_pOwner = v3;
  if ( v3 )
  {
    v6 = v2->m_assocs.m_pItems;
    if ( v6 != &v6[v2->m_assocs.m_uLength] )
    {
      do
      {
        CAkLayer::CAssociatedChildData::UpdateChildPtr(&v6->item, v2);
        ++v6;
      }
      while ( v6 != &v2->m_assocs.m_pItems[v2->m_assocs.m_uLength] );
    }
  }
}

// File Line: 525
// RVA: 0xA86450
void __fastcall CAkLayer::UpdateChildPtr(CAkLayer *this, unsigned int in_ChildID)
{
  CAkLayer *v2; // r9
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v3; // rcx
  signed __int64 v4; // rax

  v2 = this;
  v3 = this->m_assocs.m_pItems;
  v4 = (signed __int64)&v3[v2->m_assocs.m_uLength];
  if ( v3 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 )
  {
    do
    {
      if ( v3->key == in_ChildID )
        break;
      ++v3;
    }
    while ( v3 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 );
    if ( v3 != (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)v4 )
      CAkLayer::CAssociatedChildData::UpdateChildPtr(&v3->item, v2);
  }
}

// File Line: 543
// RVA: 0xA85FD0
__int64 __fastcall CAkLayer::SetCrossfadingRTPC(CAkLayer *this, unsigned int in_rtpcID)
{
  unsigned int v2; // er8
  unsigned int v3; // esi
  CAkLayer *v4; // rbx
  AKRESULT v5; // edi

  v2 = this->m_crossfadingRTPCID;
  v3 = in_rtpcID;
  v4 = this;
  v5 = 1;
  if ( v2 != in_rtpcID )
  {
    if ( v2 )
      CAkRTPCMgr::UnregisterLayer(g_pRTPCMgr, this, v2);
    v4->m_crossfadingRTPCID = v3;
    if ( v3 )
    {
      v5 = CAkRTPCMgr::RegisterLayer(g_pRTPCMgr, v4, v3);
      if ( v5 != 1 )
        v4->m_crossfadingRTPCID = 0;
    }
    CAkLayer::RecalcNotification(v4);
  }
  return (unsigned int)v5;
}

// File Line: 581
// RVA: 0xA86560
void __fastcall LayerMuteFunc(CAkPBI *in_pPBI, CAkRegisteredObj *__formal, void *in_pCookie)
{
  void *v3; // rbx
  CAkPBI *v4; // rdi
  float v5; // xmm0_4
  unsigned int out_index; // [rsp+40h] [rbp+18h]

  v3 = in_pCookie;
  v4 = in_pPBI;
  if ( !*((_BYTE *)in_pCookie + 32) )
  {
    v5 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           *((CAkConversionTable<AkRTPCGraphPointBase<float>,float> **)in_pCookie + 2),
           *((float *)in_pCookie + 6),
           0,
           &out_index);
    *((_BYTE *)v3 + 32) = 1;
    *((float *)v3 + 7) = v5;
  }
  CAkPBI::MuteNotification(v4, *((float *)v3 + 7), (AkMutedMapItem *)v3, 1);
}

// File Line: 593
// RVA: 0xA85C30
void __fastcall CAkLayer::OnRTPCChanged(CAkLayer *this, CAkRegisteredObj *in_GameObjPtr, float in_fValue)
{
  CAkRegisteredObj *v3; // rsi
  CAkLayer *v4; // rdi
  unsigned int v5; // er8
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v6; // rax
  signed __int64 v7; // rdx
  CAkParameterNode **v8; // rbx
  AkActivityChunk *v9; // rcx
  CAkLayer *v10; // [rsp+20h] [rbp-38h]
  unsigned int v11; // [rsp+28h] [rbp-30h]
  _QWORD *v12; // [rsp+30h] [rbp-28h]
  float v13; // [rsp+38h] [rbp-20h]
  char v14; // [rsp+40h] [rbp-18h]

  v3 = in_GameObjPtr;
  v4 = this;
  if ( this->m_assocs.m_uLength )
  {
    v10 = this;
    v13 = in_fValue;
    v5 = v11 & 0xFFFFFFFC | (in_GameObjPtr == 0i64);
    v6 = this->m_assocs.m_pItems;
    v7 = this->m_assocs.m_uLength;
    v11 = v5;
    if ( v6 != &v6[v7] )
    {
      v8 = &v6->item.m_pChild;
      do
      {
        if ( *v8 )
        {
          v9 = (*v8)->m_pActivityChunk;
          if ( v9 )
          {
            if ( v9->m_PlayCount )
            {
              v14 = 0;
              v12 = v8 + 1;
              ((void (__fastcall *)(CAkParameterNode *, void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *, CAkLayer **, CAkLayer *, _QWORD, CAkParameterNode **, _QWORD, _QWORD))(*v8)->vfptr[6].Release)(
                *v8,
                LayerMuteFunc,
                v3,
                &v10,
                v10,
                *(_QWORD *)&v11,
                v8 + 1,
                *(_QWORD *)&v13,
                *(_QWORD *)&v14);
            }
          }
        }
        v8 += 5;
      }
      while ( v8 - 2 != (CAkParameterNode **)&v4->m_assocs.m_pItems[v4->m_assocs.m_uLength] );
    }
  }
}

// File Line: 666
// RVA: 0xA86490
signed __int64 __fastcall CAkLayer::CAssociatedChildData::UpdateChildPtr(CAkLayer::CAssociatedChildData *this, CAkLayer *in_pLayer)
{
  CAkLayer *v2; // rbp
  CAkLayer::CAssociatedChildData *v3; // rsi
  unsigned int v5; // ebx
  CAkParameterNode *v6; // rdi
  CAkLayerCntr *v7; // rcx
  signed int v8; // eax
  CAkParameterNodeBase *v9; // rdx

  v2 = in_pLayer;
  v3 = this;
  if ( this->m_pChild )
    return 1i64;
  v5 = 1;
  v6 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, this->m_ulChildID, 0);
  if ( v6 )
  {
    v7 = v2->m_pOwner;
    v8 = 2;
    if ( v7 && (v9 = v6->m_pParentNode) != 0i64 )
    {
      if ( v9 == (CAkParameterNodeBase *)v7 )
        v8 = 1;
    }
    else
    {
      v8 = 3;
    }
    if ( v8 == 1 )
    {
      v3->m_pChild = v6;
      v5 = CAkParameterNode::AssociateLayer(v6, v2);
      if ( v5 != 1 )
        v3->m_pChild = 0i64;
    }
    else
    {
      if ( v8 == 3 )
        v8 = 1;
      v5 = v8;
    }
    v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
  }
  return v5;
}

