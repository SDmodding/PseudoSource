// File Line: 196
// RVA: 0xA8BC00
void __fastcall AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Erase(
        AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this,
        unsigned int in_uIndex)
{
  unsigned __int16 *m_pItems; // rdi
  unsigned __int16 *v4; // rcx
  unsigned __int16 *v5; // rdi
  unsigned __int16 *v6; // rsi
  unsigned __int64 i; // rcx

  m_pItems = this->m_pItems;
  v4 = &this->m_pItems[this->m_uLength - 1];
  v5 = &m_pItems[in_uIndex];
  if ( v5 < v4 )
  {
    v6 = v5 + 1;
    for ( i = ((unsigned __int64)((char *)v4 - (char *)v5 - 1) >> 1) + 1; i; --i )
      *v5++ = *v6++;
  }
  --this->m_uLength;
}

// File Line: 233
// RVA: 0xA85E00
__int64 __fastcall AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Reserve(
        AkArray<MapStruct<unsigned long,CAkLayer::CAssociatedChildData>,MapStruct<unsigned long,CAkLayer::CAssociatedChildData> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this,
        unsigned int in_ulReserve)
{
  MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *v4; // rax

  if ( in_ulReserve )
  {
    v4 = (MapStruct<unsigned long,CAkLayer::CAssociatedChildData> *)AK::MemoryMgr::Malloc(
                                                                      g_DefaultPoolId,
                                                                      40i64 * in_ulReserve);
    this->m_pItems = v4;
    if ( !v4 )
      return 52i64;
    this->m_ulReserved = in_ulReserve;
  }
  return 1i64;
}

// File Line: 285
// RVA: 0xAB5650
MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *__fastcall AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
        AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this)
{
  unsigned __int64 m_uLength; // rsi
  unsigned __int64 m_ulReserved; // rax
  unsigned int v4; // ebp
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v5; // rdi
  __int64 v6; // r8
  __int64 v7; // rdx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *m_pItems; // rcx

  m_uLength = this->m_uLength;
  m_ulReserved = this->m_ulReserved;
  if ( m_uLength >= m_ulReserved )
  {
    v4 = m_ulReserved + 4;
    v5 = (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)AK::MemoryMgr::Malloc(
                                                           g_DefaultPoolId,
                                                           16i64 * (unsigned int)(m_ulReserved + 4));
    if ( !v5 )
      return 0i64;
    v6 = this->m_uLength;
    if ( this->m_pItems )
    {
      if ( this->m_uLength )
      {
        v7 = 0i64;
        do
        {
          m_pItems = this->m_pItems;
          ++v7;
          v5[v7 - 1].key = this->m_pItems[v7 - 1].key;
          v5[v7 - 1].item = m_pItems[v7 - 1].item;
          --v6;
        }
        while ( v6 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pItems);
    }
    this->m_pItems = v5;
    this->m_ulReserved = v4;
  }
  if ( m_uLength < this->m_ulReserved )
    return &this->m_pItems[this->m_uLength++];
  return 0i64;
}

// File Line: 314
// RVA: 0xAAFC90
CAkStinger *__fastcall AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(
        AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *this,
        CAkStinger *in_rItem)
{
  unsigned __int64 m_uLength; // rsi
  __int64 v5; // rdx
  CAkStinger *v6; // r8
  CAkStinger *result; // rax

  m_uLength = this->m_uLength;
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this,
          2u)
    || m_uLength >= this->m_ulReserved )
  {
    return 0i64;
  }
  v5 = this->m_uLength;
  v6 = &this->m_pItems[v5];
  this->m_uLength = v5 + 1;
  result = v6;
  if ( v6 )
  {
    v6->m_TriggerID = in_rItem->m_TriggerID;
    v6->m_SegmentID = in_rItem->m_SegmentID;
    v6->m_SyncPlayAt = in_rItem->m_SyncPlayAt;
    v6->m_uCueFilterHash = in_rItem->m_uCueFilterHash;
    v6->m_DontRepeatTime = in_rItem->m_DontRepeatTime;
    v6->m_numSegmentLookAhead = in_rItem->m_numSegmentLookAhead;
  }
  return result;
}

// File Line: 366
// RVA: 0xA6F9E0
void __fastcall AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::RemoveAll(
        AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *this)
{
  CAkContinueListItem *v2; // rbx
  CAkSmartPtr<CAkMultiPlayNode> *p_m_pMultiPlayNode; // rdi
  CAkMultiPlayNode *m_pT; // rcx
  CAkMultiPlayNode *v5; // rcx

  v2 = &this->m_pItems[this->m_uLength];
  if ( this->m_pItems == v2 )
  {
    this->m_uLength = 0;
  }
  else
  {
    p_m_pMultiPlayNode = &this->m_pItems->m_pMultiPlayNode;
    do
    {
      m_pT = p_m_pMultiPlayNode[-2].m_pT;
      if ( m_pT )
      {
        m_pT->vfptr->AddRef(m_pT);
        p_m_pMultiPlayNode[-2].m_pT = 0i64;
      }
      if ( p_m_pMultiPlayNode->m_pT )
      {
        p_m_pMultiPlayNode->m_pT->vfptr->Release(p_m_pMultiPlayNode->m_pT);
        p_m_pMultiPlayNode->m_pT = 0i64;
      }
      v5 = p_m_pMultiPlayNode[-3].m_pT;
      if ( v5 )
      {
        v5->vfptr->Release(v5);
        p_m_pMultiPlayNode[-3].m_pT = 0i64;
      }
      p_m_pMultiPlayNode += 5;
    }
    while ( &p_m_pMultiPlayNode[-3] != (CAkSmartPtr<CAkMultiPlayNode> *)v2 );
    this->m_uLength = 0;
  }
}

// File Line: 383
// RVA: 0xA7C450
CAkParameterNodeBase **__fastcall AkArray<CAkParameterNodeBase *,CAkParameterNodeBase * const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(
        AkArray<CAkParameterNodeBase *,CAkParameterNodeBase * const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this,
        unsigned int in_uIndex)
{
  unsigned __int64 m_uLength; // rdi
  __int64 v3; // rsi
  __int64 v5; // rcx
  CAkParameterNodeBase **m_pItems; // rdx
  __int64 v7; // r8
  CAkParameterNodeBase **v8; // rax
  CAkParameterNodeBase *v9; // rcx

  m_uLength = this->m_uLength;
  v3 = in_uIndex;
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)this,
          1u)
    || m_uLength >= this->m_ulReserved )
  {
    return 0i64;
  }
  v5 = this->m_uLength;
  m_pItems = this->m_pItems;
  v7 = v3;
  v8 = &this->m_pItems[v5];
  this->m_uLength = v5 + 1;
  if ( v8 > &m_pItems[v3] )
  {
    do
    {
      v9 = *--v8;
      v8[1] = v9;
    }
    while ( v8 > &this->m_pItems[v7] );
  }
  return &this->m_pItems[v7];
}

// File Line: 425
// RVA: 0xA64880
bool __fastcall AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
        AkArray<MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus>,MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this,
        unsigned int in_uGrowBy)
{
  unsigned int v3; // esi
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v4; // rax
  MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *v5; // rdi
  __int64 m_uLength; // r9
  __int64 v7; // r10
  char *v8; // r8
  _QWORD *v9; // r8

  v3 = in_uGrowBy + this->m_ulReserved;
  v4 = (MapStruct<unsigned long,CAkFeedbackDeviceMgr::DeviceBus> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16i64 * v3);
  v5 = v4;
  if ( v4 )
  {
    m_uLength = this->m_uLength;
    if ( this->m_pItems )
    {
      if ( this->m_uLength )
      {
        v7 = -(__int64)v4;
        do
        {
          if ( v4 )
            v4->item.m_pFinalBus = 0i64;
          v8 = (char *)v4++ + v7;
          v9 = (_QWORD *)((char *)&this->m_pItems->key + (unsigned __int64)v8);
          *(_QWORD *)&v4[-1].key = *v9;
          v4[-1].item.m_pFinalBus = (IAkMotionMixBus *)v9[1];
          --m_uLength;
        }
        while ( m_uLength );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pItems);
    }
    this->m_ulReserved = v3;
    this->m_pItems = v5;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 459
// RVA: 0xA90490
bool __fastcall AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Resize(
        AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *this,
        unsigned int in_uiSize)
{
  unsigned __int64 m_uLength; // rsi
  unsigned __int64 v3; // rdi
  bool result; // al
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  CAkSplitterBus::PlayerSlot *v8; // rax

  m_uLength = this->m_uLength;
  v3 = in_uiSize;
  if ( in_uiSize >= (unsigned int)m_uLength )
  {
    if ( in_uiSize <= this->m_ulReserved
      || (result = AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                     this,
                     in_uiSize - m_uLength)) )
    {
      if ( m_uLength < v3 )
      {
        v6 = v3 - m_uLength;
        v7 = m_uLength;
        do
        {
          v8 = &this->m_pItems[v7];
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
      this->m_uLength = v3;
      return 1;
    }
  }
  else
  {
    this->m_uLength = in_uiSize;
    return 1;
  }
  return result;
}

