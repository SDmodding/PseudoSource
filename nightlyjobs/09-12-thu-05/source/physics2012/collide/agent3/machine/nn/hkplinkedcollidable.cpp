// File Line: 19
// RVA: 0x131BFD0
bool __fastcall cmpLessCollisionEntries(hkpLinkedCollidable::CollisionEntry *entry0, hkpLinkedCollidable::CollisionEntry *entry1)
{
  return entry0->m_partner->m_broadPhaseHandle.m_id < entry1->m_partner->m_broadPhaseHandle.m_id;
}

// File Line: 25
// RVA: 0x131BE30
void __fastcall hkpLinkedCollidable::getCollisionEntriesSorted(hkpLinkedCollidable *this, hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *entries)
{
  int v2; // ebx
  unsigned __int128 v3; // di
  int v4; // ebp
  int v5; // eax
  int v6; // eax
  int v7; // er9
  __int64 v8; // rcx
  __int64 v9; // r8
  __int64 v10; // rdx
  __int64 v11; // rax
  _QWORD *v12; // rax
  __int64 v13; // rdx
  __int64 v14; // r8
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = this->m_collisionEntries.m_size;
  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)entries);
  v4 = this->m_collisionEntries.m_size;
  if ( v2 > entries->m_size )
    v4 = entries->m_size;
  v5 = entries->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v2 )
  {
    v6 = 2 * v5;
    v7 = this->m_collisionEntries.m_size;
    if ( v2 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, entries, v7, 16);
  }
  v8 = *(_QWORD *)v3;
  if ( v4 > 0 )
  {
    v9 = *(_QWORD *)(*((_QWORD *)&v3 + 1) + 112i64) - v8;
    v10 = v4;
    do
    {
      v11 = *(_QWORD *)(v9 + v8);
      v8 += 16i64;
      *(_QWORD *)(v8 - 16) = v11;
      *(_QWORD *)(v8 - 8) = *(_QWORD *)(v9 + v8 - 8);
      --v10;
    }
    while ( v10 );
  }
  v12 = (_QWORD *)(16i64 * v4 + *(_QWORD *)v3);
  v13 = v2 - v4;
  if ( v2 - v4 > 0 )
  {
    v14 = *(_QWORD *)(*((_QWORD *)&v3 + 1) + 112i64) - *(_QWORD *)v3;
    do
    {
      if ( v12 )
      {
        *v12 = *(_QWORD *)((char *)v12 + v14);
        v12[1] = *(_QWORD *)((char *)v12 + v14 + 8);
      }
      v12 += 2;
      --v13;
    }
    while ( v13 );
  }
  *(_DWORD *)(v3 + 8) = v2;
  if ( *(_BYTE *)(*(char *)(*((_QWORD *)&v3 + 1) + 32i64) + *((_QWORD *)&v3 + 1) + 352i64) == 5 && v2 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      *(hkpTypedBroadPhaseHandlePair **)v3,
      0,
      v2 - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))cmpLessCollisionEntries);
}

// File Line: 39
// RVA: 0x131BF50
hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *__fastcall hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(hkpLinkedCollidable *this)
{
  return &this->m_collisionEntries;
}

// File Line: 51
// RVA: 0x131BF60
hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *__fastcall hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(hkpLinkedCollidable *this)
{
  return &this->m_collisionEntries;
}

// File Line: 63
// RVA: 0x131BF70
void __fastcall hkpLinkedCollidable::sortEntries(hkpLinkedCollidable *this)
{
  int v1; // er8
  hkpLinkedCollidable *v2; // rbx
  int i; // eax
  hkpAgentNnEntry *v4; // rdx

  v1 = this->m_collisionEntries.m_size;
  v2 = this;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      (hkpTypedBroadPhaseHandlePair *)this->m_collisionEntries.m_data,
      0,
      v1 - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))cmpLessCollisionEntries);
  for ( i = 0; i < v2->m_collisionEntries.m_size; ++i )
  {
    v4 = v2->m_collisionEntries.m_data[i].m_agentEntry;
    v4->m_agentIndexOnCollidable[v2 == v4->m_collidable[1]] = i;
  }
}

