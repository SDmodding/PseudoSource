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
signed __int64 __fastcall hkaReferencePoseAnimation::getNumOriginalFrames(hkEntitySelectorAll *this, hkpEntity *entity)
{
  return 1i64;
}

// File Line: 34
// RVA: 0xA9B780
void __fastcall CAkPlayListRandom::Destroy(CAkPlayListSequence *this)
{
  unsigned int *v1; // rdx
  CAkPlayListSequence *v2; // rdi
  int v3; // ebx

  v1 = this->m_PlayList.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->m_PlayList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_PlayList.m_pItems = 0i64;
    v2->m_PlayList.m_ulReserved = 0;
  }
  v3 = g_DefaultPoolId;
  v2->vfptr->__vecDelDtor((CAkPlayList *)&v2->vfptr, 0);
  AK::MemoryMgr::Free(v3, v2);
}

// File Line: 45
// RVA: 0xA9B8D0
__int64 __fastcall CAkPlayListRandom::ID(CAkPlayListRandom *this, unsigned __int16 in_wPosition)
{
  return this->m_PlayList.m_pItems[in_wPosition].ulID;
}

// File Line: 50
// RVA: 0xA9B6B0
signed __int64 __fastcall CAkPlayListRandom::Add(CAkPlayListRandom *this, unsigned int in_ulID, unsigned int in_weight)
{
  unsigned __int64 v3; // rdi
  AkArray<AkPlaylistItem,AkPlaylistItem const &,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v4; // rbx
  unsigned int v5; // esi
  unsigned int v6; // ebp
  __int64 v7; // rcx
  unsigned int *v8; // rdx

  v3 = this->m_PlayList.m_uLength;
  v4 = &this->m_PlayList;
  v5 = in_weight;
  v6 = in_ulID;
  if ( v3 >= this->m_PlayList.m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&this->m_PlayList,
          8u) )
  {
    return 2i64;
  }
  if ( v3 >= v4->m_ulReserved )
    return 2i64;
  v7 = v4->m_uLength;
  v8 = (unsigned int *)&v4->m_pItems[v7];
  v4->m_uLength = v7 + 1;
  if ( !v8 )
    return 2i64;
  v8[1] = v5;
  *v8 = v6;
  return 1i64;
}

// File Line: 63
// RVA: 0xA9B900
void __fastcall CAkPlayListRandom::Remove(CAkPlayListRandom *this, unsigned int in_ID)
{
  AkPlaylistItem *v2; // rax
  CAkPlayListRandom *v3; // r8
  unsigned __int64 v4; // rcx

  v2 = this->m_PlayList.m_pItems;
  v3 = this;
  if ( v2 != &v2[this->m_PlayList.m_uLength] )
  {
    do
    {
      if ( v2->ulID == in_ID )
      {
        v4 = (unsigned __int64)&v3->m_PlayList.m_pItems[v3->m_PlayList.m_uLength - 1];
        if ( (unsigned __int64)v2 < v4 )
          qmemcpy(v2, &v2[1], 8 * (((v4 - (unsigned __int64)v2 - 1) >> 3) + 1));
        --v3->m_PlayList.m_uLength;
      }
      else
      {
        ++v2;
      }
    }
    while ( v2 != &v3->m_PlayList.m_pItems[v3->m_PlayList.m_uLength] );
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
void __fastcall CAkPlayListRandom::SetWeight(CAkPlayListRandom *this, unsigned __int16 in_wPosition, unsigned int in_weight)
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
  AkPlaylistItem *v1; // rdx
  __int64 result; // rax
  signed __int64 i; // r8

  v1 = this->m_PlayList.m_pItems;
  result = 0i64;
  for ( i = (signed __int64)&v1[this->m_PlayList.m_uLength]; v1 != (AkPlaylistItem *)i; ++v1 )
    result = (unsigned int)(v1->weight + result);
  return result;
}

// File Line: 106
// RVA: 0xA9B7E0
char __fastcall CAkPlayListRandom::Exists(CAkPlayListRandom *this, unsigned int in_ID)
{
  AkPlaylistItem *v2; // rax
  signed __int64 v3; // r8

  v2 = this->m_PlayList.m_pItems;
  v3 = (signed __int64)&v2[this->m_PlayList.m_uLength];
  if ( v2 == (AkPlaylistItem *)v3 )
    return 0;
  while ( v2->ulID != in_ID )
  {
    ++v2;
    if ( v2 == (AkPlaylistItem *)v3 )
      return 0;
  }
  return 1;
}

// File Line: 118
// RVA: 0xA9B840
char __fastcall CAkPlayListRandom::GetPosition(CAkPlayListRandom *this, unsigned int in_ID, unsigned __int16 *out_rwPosition)
{
  AkPlaylistItem *v3; // rax
  unsigned __int16 v4; // r9
  signed __int64 v5; // r10

  v3 = this->m_PlayList.m_pItems;
  v4 = 0;
  v5 = (signed __int64)&v3[this->m_PlayList.m_uLength];
  if ( v3 == (AkPlaylistItem *)v5 )
    return 0;
  while ( v3->ulID != in_ID )
  {
    ++v3;
    ++v4;
    if ( v3 == (AkPlaylistItem *)v5 )
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
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  v3 = in_ulID;
  v4 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&this->m_PlayList);
  if ( v4 )
    *v4 = v3;
  return 2 - (unsigned int)(v4 != 0i64);
}

// File Line: 167
// RVA: 0xA9B980
void __fastcall CAkPlayListSequence::Remove(CAkPlayListSequence *this, unsigned int in_ulID)
{
  unsigned int *v2; // rdi
  CAkPlayListSequence *v3; // r8
  signed __int64 v4; // rax
  unsigned int *v5; // rsi
  unsigned __int64 i; // rcx

  v2 = this->m_PlayList.m_pItems;
  v3 = this;
  v4 = (signed __int64)&v2[this->m_PlayList.m_uLength];
  if ( v2 != (unsigned int *)v4 )
  {
    do
    {
      if ( *v2 == in_ulID )
        break;
      ++v2;
    }
    while ( v2 != (unsigned int *)v4 );
    if ( v2 != (unsigned int *)v4 )
    {
      if ( (unsigned __int64)v2 < v4 - 4 )
      {
        v5 = v2 + 1;
        for ( i = ((unsigned __int64)(v4 - 4 - (_QWORD)v2 - 1) >> 2) + 1; i; --i )
        {
          *v2 = *v5;
          ++v5;
          ++v2;
        }
      }
      --v3->m_PlayList.m_uLength;
    }
  }
}

// File Line: 181
// RVA: 0xA9B810
bool __fastcall CAkPlayListSequence::Exists(CAkPlayListSequence *this, unsigned int in_ulID)
{
  unsigned int *v2; // rax
  signed __int64 v3; // rcx
  bool v4; // zf

  v2 = this->m_PlayList.m_pItems;
  v3 = (signed __int64)&v2[this->m_PlayList.m_uLength];
  v4 = v2 == (unsigned int *)v3;
  if ( v2 != (unsigned int *)v3 )
  {
    do
    {
      if ( *v2 == in_ulID )
        break;
      ++v2;
    }
    while ( v2 != (unsigned int *)v3 );
    v4 = v2 == (unsigned int *)v3;
  }
  return !v4;
}

// File Line: 190
// RVA: 0xA9B870
char __fastcall CAkPlayListSequence::GetPosition(CAkPlayListSequence *this, unsigned int in_ID, unsigned __int16 *out_rwPosition)
{
  unsigned int *v3; // r9
  signed __int64 v4; // rcx
  unsigned int *i; // rax

  v3 = this->m_PlayList.m_pItems;
  v4 = (signed __int64)&v3[this->m_PlayList.m_uLength];
  for ( i = v3; i != (unsigned int *)v4; ++i )
  {
    if ( *i == in_ID )
      break;
  }
  if ( i == (unsigned int *)v4 )
    return 0;
  *out_rwPosition = i - v3;
  return 1;
}

