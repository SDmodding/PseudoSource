// File Line: 22
// RVA: 0xA9B640
void __fastcall CAkPlayListRandom::CAkPlayListRandom(CAkPlayListRandom *this)
{
  this->vfptr = (CAkPlayListVtbl *)&CAkPlayListRandom::`vftable;
  this->m_PlayList.m_pItems = 0i64;
  *(_QWORD *)&this->m_PlayList.m_uLength = 0i64;
}

// File Line: 29
// RVA: 0xA9B8F0
__int64 __fastcall hkaReferencePoseAnimation::getNumOriginalFrames(hkEntitySelectorAll *this, hkpEntity *entity)
{
  return 1i64;
}

// File Line: 34
// RVA: 0xA9B780
void __fastcall CAkPlayListRandom::Destroy(CAkPlayListSequence *this)
{
  unsigned int *m_pItems; // rdx
  int v3; // ebx

  m_pItems = this->m_PlayList.m_pItems;
  if ( m_pItems )
  {
    this->m_PlayList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_PlayList.m_pItems = 0i64;
    this->m_PlayList.m_ulReserved = 0;
  }
  v3 = g_DefaultPoolId;
  this->vfptr->__vecDelDtor(this, 0i64);
  AK::MemoryMgr::Free(v3, this);
}

// File Line: 45
// RVA: 0xA9B8D0
__int64 __fastcall CAkPlayListRandom::ID(CAkPlayListRandom *this, unsigned __int16 in_wPosition)
{
  return this->m_PlayList.m_pItems[in_wPosition].ulID;
}

// File Line: 50
// RVA: 0xA9B6B0
__int64 __fastcall CAkPlayListRandom::Add(CAkPlayListRandom *this, unsigned int in_ulID, unsigned int in_weight)
{
  unsigned __int64 m_uLength; // rdi
  AkArray<AkPlaylistItem,AkPlaylistItem const &,ArrayPoolDefault,8,AkArrayAllocatorDefault> *p_m_PlayList; // rbx
  __int64 v7; // rcx
  AkPlaylistItem *v8; // rdx

  m_uLength = this->m_PlayList.m_uLength;
  p_m_PlayList = &this->m_PlayList;
  if ( m_uLength >= this->m_PlayList.m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&this->m_PlayList,
          8u) )
  {
    return 2i64;
  }
  if ( m_uLength >= p_m_PlayList->m_ulReserved )
    return 2i64;
  v7 = p_m_PlayList->m_uLength;
  v8 = &p_m_PlayList->m_pItems[v7];
  p_m_PlayList->m_uLength = v7 + 1;
  if ( !v8 )
    return 2i64;
  v8->weight = in_weight;
  v8->ulID = in_ulID;
  return 1i64;
}

// File Line: 63
// RVA: 0xA9B900
void __fastcall CAkPlayListRandom::Remove(CAkPlayListRandom *this, unsigned int in_ID)
{
  AkPlaylistItem *m_pItems; // rax
  AkPlaylistItem *v4; // rcx

  m_pItems = this->m_PlayList.m_pItems;
  if ( m_pItems != &m_pItems[this->m_PlayList.m_uLength] )
  {
    do
    {
      if ( m_pItems->ulID == in_ID )
      {
        v4 = &this->m_PlayList.m_pItems[this->m_PlayList.m_uLength - 1];
        if ( m_pItems < v4 )
          qmemcpy(m_pItems, &m_pItems[1], 8 * (((unsigned __int64)((char *)v4 - (char *)m_pItems - 1) >> 3) + 1));
        --this->m_PlayList.m_uLength;
      }
      else
      {
        ++m_pItems;
      }
    }
    while ( m_pItems != &this->m_PlayList.m_pItems[this->m_PlayList.m_uLength] );
  }
}

// File Line: 79
// RVA: 0xA9B9E0
void __fastcall CAkPlayListSequence::RemoveAll(CAkPlayListSequence *this)
{
  this->m_PlayList.m_uLength = 0;
}

// File Line: 84
// RVA: 0xA9B9F0
void __fastcall CAkPlayListRandom::SetWeight(
        CAkPlayListRandom *this,
        unsigned __int16 in_wPosition,
        unsigned int in_weight)
{
  this->m_PlayList.m_pItems[in_wPosition].weight = in_weight;
}

// File Line: 90
// RVA: 0xA9B8B0
__int64 __fastcall CAkPlayListRandom::GetWeight(CAkPlayListRandom *this, unsigned __int16 in_wPosition)
{
  return this->m_PlayList.m_pItems[in_wPosition].weight;
}

// File Line: 96
// RVA: 0xA9B760
__int64 __fastcall CAkPlayListRandom::CalculateTotalWeight(CAkPlayListRandom *this)
{
  AkPlaylistItem *m_pItems; // rdx
  __int64 result; // rax
  AkPlaylistItem *i; // r8

  m_pItems = this->m_PlayList.m_pItems;
  result = 0i64;
  for ( i = &m_pItems[this->m_PlayList.m_uLength]; m_pItems != i; ++m_pItems )
    result = (unsigned int)(m_pItems->weight + result);
  return result;
}

// File Line: 106
// RVA: 0xA9B7E0
char __fastcall CAkPlayListRandom::Exists(CAkPlayListRandom *this, unsigned int in_ID)
{
  AkPlaylistItem *m_pItems; // rax
  AkPlaylistItem *v3; // r8

  m_pItems = this->m_PlayList.m_pItems;
  v3 = &m_pItems[this->m_PlayList.m_uLength];
  if ( m_pItems == v3 )
    return 0;
  while ( m_pItems->ulID != in_ID )
  {
    if ( ++m_pItems == v3 )
      return 0;
  }
  return 1;
}

// File Line: 118
// RVA: 0xA9B840
char __fastcall CAkPlayListRandom::GetPosition(
        CAkPlayListRandom *this,
        unsigned int in_ID,
        unsigned __int16 *out_rwPosition)
{
  AkPlaylistItem *m_pItems; // rax
  unsigned __int16 v4; // r9
  AkPlaylistItem *v5; // r10

  m_pItems = this->m_PlayList.m_pItems;
  v4 = 0;
  v5 = &m_pItems[this->m_PlayList.m_uLength];
  if ( m_pItems == v5 )
    return 0;
  while ( m_pItems->ulID != in_ID )
  {
    ++m_pItems;
    ++v4;
    if ( m_pItems == v5 )
      return 0;
  }
  *out_rwPosition = v4;
  return 1;
}

// File Line: 135
// RVA: 0xA9B660
void __fastcall CAkPlayListSequence::CAkPlayListSequence(CAkPlayListSequence *this)
{
  this->vfptr = (CAkPlayListVtbl *)&CAkPlayListSequence::`vftable;
  this->m_PlayList.m_pItems = 0i64;
  *(_QWORD *)&this->m_PlayList.m_uLength = 0i64;
}

// File Line: 157
// RVA: 0xA9B8E0
__int64 __fastcall CAkPlayListSequence::ID(CAkPlayListSequence *this, unsigned __int16 in_wPosition)
{
  return this->m_PlayList.m_pItems[in_wPosition];
}

// File Line: 162
// RVA: 0xA9B730
__int64 __fastcall CAkPlayListSequence::Add(CAkPlayListSequence *this, unsigned int in_ulID, unsigned int __formal)
{
  unsigned int *v4; // rax

  v4 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&this->m_PlayList);
  if ( v4 )
    *v4 = in_ulID;
  return 2 - (unsigned int)(v4 != 0i64);
}

// File Line: 167
// RVA: 0xA9B980
void __fastcall CAkPlayListSequence::Remove(CAkPlayListSequence *this, unsigned int in_ulID)
{
  unsigned int *m_pItems; // rdi
  unsigned int *v4; // rax
  unsigned int *v5; // rsi
  unsigned __int64 i; // rcx

  m_pItems = this->m_PlayList.m_pItems;
  v4 = &m_pItems[this->m_PlayList.m_uLength];
  if ( m_pItems != v4 )
  {
    do
    {
      if ( *m_pItems == in_ulID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v4 );
    if ( m_pItems != v4 )
    {
      if ( m_pItems < v4 - 1 )
      {
        v5 = m_pItems + 1;
        for ( i = ((unsigned __int64)((char *)(v4 - 1) - (char *)m_pItems - 1) >> 2) + 1; i; --i )
          *m_pItems++ = *v5++;
      }
      --this->m_PlayList.m_uLength;
    }
  }
}

// File Line: 181
// RVA: 0xA9B810
bool __fastcall CAkPlayListSequence::Exists(CAkPlayListSequence *this, unsigned int in_ulID)
{
  unsigned int *m_pItems; // rax
  unsigned int *v3; // rcx
  bool v4; // zf

  m_pItems = this->m_PlayList.m_pItems;
  v3 = &m_pItems[this->m_PlayList.m_uLength];
  v4 = m_pItems == v3;
  if ( m_pItems != v3 )
  {
    do
    {
      if ( *m_pItems == in_ulID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v3 );
    v4 = m_pItems == v3;
  }
  return !v4;
}

// File Line: 190
// RVA: 0xA9B870
char __fastcall CAkPlayListSequence::GetPosition(
        CAkPlayListSequence *this,
        unsigned int in_ID,
        unsigned __int16 *out_rwPosition)
{
  unsigned int *m_pItems; // r9
  unsigned int *v4; // rcx
  unsigned int *i; // rax

  m_pItems = this->m_PlayList.m_pItems;
  v4 = &m_pItems[this->m_PlayList.m_uLength];
  for ( i = m_pItems; i != v4; ++i )
  {
    if ( *i == in_ID )
      break;
  }
  if ( i == v4 )
    return 0;
  *out_rwPosition = i - m_pItems;
  return 1;
}

