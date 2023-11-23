// File Line: 19
// RVA: 0x131BFD0
bool __fastcall cmpLessCollisionEntries(
        hkpLinkedCollidable::CollisionEntry *entry0,
        hkpLinkedCollidable::CollisionEntry *entry1)
{
  return entry0->m_partner->m_broadPhaseHandle.m_id < entry1->m_partner->m_broadPhaseHandle.m_id;
}

// File Line: 25
// RVA: 0x131BE30
void __fastcall hkpLinkedCollidable::getCollisionEntriesSorted(
        hkpLinkedCollidable *this,
        hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *entries)
{
  int m_size; // ebx
  int v4; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkpLinkedCollidable::CollisionEntry *m_data; // rcx
  char *v10; // r8
  __int64 v11; // rdx
  hkpAgentNnEntry *v12; // rax
  hkpLinkedCollidable::CollisionEntry *v13; // rax
  __int64 v14; // rdx
  signed __int64 v15; // r8
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_size = this->m_collisionEntries.m_size;
  v4 = m_size;
  if ( m_size > entries->m_size )
    v4 = entries->m_size;
  v6 = entries->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v7 = 2 * v6;
    v8 = this->m_collisionEntries.m_size;
    if ( m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&entries->m_data, v8, 16);
  }
  m_data = entries->m_data;
  if ( v4 > 0 )
  {
    v10 = (char *)((char *)this->m_collisionEntries.m_data - (char *)m_data);
    v11 = v4;
    do
    {
      v12 = *(hkpAgentNnEntry **)((char *)&m_data->m_agentEntry + (_QWORD)v10);
      ++m_data;
      m_data[-1].m_agentEntry = v12;
      m_data[-1].m_partner = *(hkpLinkedCollidable **)((char *)m_data + (_QWORD)v10 - 8);
      --v11;
    }
    while ( v11 );
  }
  v13 = &entries->m_data[v4];
  v14 = m_size - v4;
  if ( m_size - v4 > 0 )
  {
    v15 = (char *)this->m_collisionEntries.m_data - (char *)entries->m_data;
    do
    {
      if ( v13 )
      {
        v13->m_agentEntry = *(hkpAgentNnEntry **)((char *)&v13->m_agentEntry + v15);
        v13->m_partner = *(hkpLinkedCollidable **)((char *)&v13->m_partner + v15);
      }
      ++v13;
      --v14;
    }
    while ( v14 );
  }
  entries->m_size = m_size;
  if ( *((_BYTE *)&this[2].m_boundingVolumeData.m_childShapeKeys + this->m_ownerOffset) == 5 && m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      (hkpTypedBroadPhaseHandlePair *)entries->m_data,
      0,
      m_size - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))cmpLessCollisionEntries);
}

// File Line: 39
// RVA: 0x131BF50
hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *__fastcall hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(
        hkpLinkedCollidable *this)
{
  return &this->m_collisionEntries;
}

// File Line: 51
// RVA: 0x131BF60
hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *__fastcall hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(
        hkpLinkedCollidable *this)
{
  return &this->m_collisionEntries;
}

// File Line: 63
// RVA: 0x131BF70
void __fastcall hkpLinkedCollidable::sortEntries(hkpLinkedCollidable *this)
{
  int m_size; // r8d
  int i; // eax
  hkpAgentNnEntry *m_agentEntry; // rdx

  m_size = this->m_collisionEntries.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      (hkpTypedBroadPhaseHandlePair *)this->m_collisionEntries.m_data,
      0,
      m_size - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))cmpLessCollisionEntries);
  for ( i = 0; i < this->m_collisionEntries.m_size; ++i )
  {
    m_agentEntry = this->m_collisionEntries.m_data[i].m_agentEntry;
    m_agentEntry->m_agentIndexOnCollidable[this == m_agentEntry->m_collidable[1]] = i;
  }
}

