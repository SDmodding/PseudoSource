// File Line: 196
// RVA: 0xA8BC00
void __fastcall AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Erase(AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this, unsigned int in_uIndex)
{
  unsigned __int16 *v2; // rdi
  AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v3; // r8
  unsigned __int16 *v4; // rcx
  unsigned __int16 *v5; // rdi
  unsigned __int16 *v6; // rsi
  unsigned __int64 i; // rcx

  v2 = this->m_pItems;
  v3 = this;
  v4 = &this->m_pItems[this->m_uLength - 1i64];
  v5 = &v2[in_uIndex];
  if ( v5 < v4 )
  {
    v6 = v5 + 1;
    for ( i = ((unsigned __int64)((char *)v4 - (char *)v5 - 1) >> 1) + 1; i; --i )
    {
      *v5 = *v6;
      ++v6;
      ++v5;
    }
  }
  --v3->m_uLength;
}

// File Line: 233
// RVA: 0xA85E00
signed __int64 __fastcall AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Reserve(AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this, unsigned int in_ulReserve)
{
  unsigned int v2; // ebx
  AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v3; // rdi
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax

  v2 = in_ulReserve;
  v3 = this;
  if ( in_ulReserve )
  {
    v4 = (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)AK::MemoryMgr::Malloc(
                                                                      g_DefaultPoolId,
                                                                      40i64 * in_ulReserve);
    v3->m_pItems = v4;
    if ( !v4 )
      return 52i64;
    v3->m_ulReserved = v2;
  }
  return 1i64;
}

// File Line: 285
// RVA: 0xAB5650
MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *__fastcall AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this)
{
  unsigned __int64 v1; // rsi
  unsigned __int64 v2; // rax
  AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v3; // rbx
  unsigned int v4; // ebp
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v5; // rdi
  __int64 v6; // r8
  __int64 v7; // rdx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v8; // rcx

  v1 = this->m_uLength;
  v2 = this->m_ulReserved;
  v3 = this;
  if ( v1 >= v2 )
  {
    v4 = v2 + 4;
    v5 = (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)AK::MemoryMgr::Malloc(
                                                           g_DefaultPoolId,
                                                           16i64 * (unsigned int)(v2 + 4));
    if ( !v5 )
      return 0i64;
    v6 = v3->m_uLength;
    if ( v3->m_pItems )
    {
      if ( v3->m_uLength )
      {
        v7 = 0i64;
        do
        {
          v8 = v3->m_pItems;
          ++v7;
          v5[v7 - 1].key = v3->m_pItems[v7 - 1].key;
          *((_QWORD *)&v5[v7] - 1) = *((_QWORD *)&v8[v7] - 1);
          --v6;
        }
        while ( v6 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pItems);
    }
    v3->m_pItems = v5;
    v3->m_ulReserved = v4;
  }
  if ( v1 < v3->m_ulReserved )
    return &v3->m_pItems[v3->m_uLength++];
  return 0i64;
}

// File Line: 314
// RVA: 0xAAFC90
CAkStinger *__fastcall AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *this, CAkStinger *in_rItem)
{
  unsigned __int64 v2; // rsi
  CAkStinger *v3; // rdi
  AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *v4; // rbx
  __int64 v5; // rdx
  signed __int64 v6; // r8
  CAkStinger *result; // rax

  v2 = this->m_uLength;
  v3 = in_rItem;
  v4 = this;
  if ( v2 >= this->m_ulReserved
    && !AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this,
          2u)
    || v2 >= v4->m_ulReserved )
  {
    return 0i64;
  }
  v5 = v4->m_uLength;
  v6 = (signed __int64)&v4->m_pItems[v5];
  v4->m_uLength = v5 + 1;
  result = (CAkStinger *)v6;
  if ( v6 )
  {
    *(_DWORD *)v6 = v3->m_TriggerID;
    *(_DWORD *)(v6 + 4) = v3->m_SegmentID;
    *(_DWORD *)(v6 + 8) = v3->m_SyncPlayAt;
    *(_DWORD *)(v6 + 12) = v3->m_uCueFilterHash;
    *(_DWORD *)(v6 + 16) = v3->m_DontRepeatTime;
    *(_DWORD *)(v6 + 20) = v3->m_numSegmentLookAhead;
  }
  return result;
}

// File Line: 366
// RVA: 0xA6F9E0
void __fastcall AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::RemoveAll(AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *this)
{
  AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *v1; // r14
  CAkContinueListItem *v2; // rbx
  CAkSmartPtr<CAkMultiPlayNode> *v3; // rdi
  CAkMultiPlayNode *v4; // rcx
  CAkMultiPlayNode *v5; // rcx

  v1 = this;
  v2 = &this->m_pItems[this->m_uLength];
  if ( this->m_pItems == v2 )
  {
    this->m_uLength = 0;
  }
  else
  {
    v3 = &this->m_pItems->m_pMultiPlayNode;
    do
    {
      v4 = v3[-2].m_pT;
      if ( v4 )
      {
        ((void (*)(void))v4->vfptr->AddRef)();
        v3[-2].m_pT = 0i64;
      }
      if ( v3->m_pT )
      {
        ((void (*)(void))v3->m_pT->vfptr->Release)();
        v3->m_pT = 0i64;
      }
      v5 = v3[-3].m_pT;
      if ( v5 )
      {
        ((void (*)(void))v5->vfptr->Release)();
        v3[-3].m_pT = 0i64;
      }
      v3 += 5;
    }
    while ( &v3[-3] != (CAkSmartPtr<CAkMultiPlayNode> *)v2 );
    v1->m_uLength = 0;
  }
}

// File Line: 383
// RVA: 0xA7C450
CAkParameterNodeBase **__fastcall AkArray<CAkParameterNodeBase *,CAkParameterNodeBase * const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(AkArray<CAkParameterNodeBase *,CAkParameterNodeBase * const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this, unsigned int in_uIndex)
{
  unsigned __int64 v2; // rdi
  signed __int64 v3; // rsi
  AkArray<CAkParameterNodeBase *,CAkParameterNodeBase * const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v4; // rbx
  __int64 v5; // rcx
  CAkParameterNodeBase **v6; // rdx
  signed __int64 v7; // r8
  unsigned __int64 v8; // rax
  __int64 v9; // rcx

  v2 = this->m_uLength;
  v3 = in_uIndex;
  v4 = this;
  if ( v2 >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)this,
          1u)
    || v2 >= v4->m_ulReserved )
  {
    return 0i64;
  }
  v5 = v4->m_uLength;
  v6 = v4->m_pItems;
  v7 = v3;
  v8 = (unsigned __int64)&v4->m_pItems[v5];
  v4->m_uLength = v5 + 1;
  if ( v8 > (unsigned __int64)&v6[v3] )
  {
    do
    {
      v9 = *(_QWORD *)(v8 - 8);
      v8 -= 8i64;
      *(_QWORD *)(v8 + 8) = v9;
    }
    while ( (CAkParameterNodeBase **)v8 > &v4->m_pItems[v7] );
  }
  return &v4->m_pItems[v7];
}

// File Line: 425
// RVA: 0xA64880
bool __fastcall AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this, unsigned int in_uGrowBy)
{
  AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v2; // rbx
  unsigned int v3; // esi
  signed __int64 v4; // rax
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v5; // rdi
  __int64 v6; // r9
  signed __int64 v7; // r10
  char *v8; // r8
  _QWORD *v9; // r8

  v2 = this;
  v3 = in_uGrowBy + this->m_ulReserved;
  v4 = (signed __int64)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16i64 * v3);
  v5 = (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)v4;
  if ( v4 )
  {
    v6 = v2->m_uLength;
    if ( v2->m_pItems )
    {
      if ( v2->m_uLength )
      {
        v7 = -v4;
        do
        {
          if ( v4 )
            *(_QWORD *)(v4 + 8) = 0i64;
          v8 = (char *)(v7 + v4);
          v4 += 16i64;
          v9 = (_QWORD *)((char *)&v2->m_pItems->key + (unsigned __int64)v8);
          *(_QWORD *)(v4 - 16) = *v9;
          *(_QWORD *)(v4 - 8) = v9[1];
          --v6;
        }
        while ( v6 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pItems);
    }
    v2->m_ulReserved = v3;
    v2->m_pItems = v5;
    LOBYTE(v4) = 1;
  }
  return v4;
}

// File Line: 459
// RVA: 0xA90490
bool __fastcall AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Resize(AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this, unsigned int in_uiSize)
{
  unsigned __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v4; // rbx
  bool result; // al
  unsigned __int64 v6; // rdx
  signed __int64 v7; // rcx
  CAkSplitterBus::PlayerSlot *v8; // rax

  v2 = this->m_uLength;
  v3 = in_uiSize;
  v4 = this;
  if ( in_uiSize >= (unsigned int)v2 )
  {
    if ( (unsigned int)v3 <= this->m_ulReserved
      || (result = AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                     this,
                     in_uiSize - v2)) != 0 )
    {
      if ( v2 < v3 )
      {
        v6 = v3 - v2;
        v7 = v2;
        do
        {
          v8 = &v4->m_pItems[v7];
          if ( v8 )
          {
            v8->m_pFeedbackMixBus = 0i64;
            v8->m_pAudioMixBus = 0i64;
            v8->m_DeviceID = 0;
          }
          ++v7;
          --v6;
        }
        while ( v6 );
      }
      v4->m_uLength = v3;
      result = 1;
    }
  }
  else
  {
    this->m_uLength = v3;
    result = 1;
  }
  return result;
}

