// File Line: 20
// RVA: 0xC1E720
void __fastcall hkaiDirectedGraphExplicitCostBuilder::BuildOptions::BuildOptions(
        hkaiDirectedGraphExplicitCostBuilder::BuildOptions *this)
{
  this->m_allowDuplicateEdges.m_bool = 1;
}

// File Line: 25
// RVA: 0xC1E6C0
void __fastcall hkaiGraphBuilder::addSymmetricEdge(hkaiGraphBuilder *this, unsigned int a, unsigned int b, float w)
{
  ((void (__fastcall *)(hkaiGraphBuilder *))this->vfptr->addEdge)(this);
  ((void (__fastcall *)(hkaiGraphBuilder *, _QWORD, _QWORD))this->vfptr->addEdge)(this, b, a);
}

// File Line: 31
// RVA: 0xC1E730
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::addPosition(
        hkaiDirectedGraphExplicitCostBuilder *this,
        hkVector4f *p)
{
  if ( this->m_positions.m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_positions, 16);
  this->m_positions.m_data[this->m_positions.m_size++] = (hkVector4f)p->m_quad;
  return (unsigned int)(this->m_positions.m_size - 1);
}

// File Line: 37
// RVA: 0xC1E7A0
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::addEdge(
        hkaiDirectedGraphExplicitCostBuilder *this,
        int a,
        int b,
        float w)
{
  __int64 m_size; // rcx
  hkaiDirectedGraphExplicitCostBuilder::Link *m_data; // rdx
  __int64 v9; // r8

  if ( this->m_links.m_size == (this->m_links.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_links, 12);
  m_size = this->m_links.m_size;
  m_data = this->m_links.m_data;
  v9 = m_size;
  this->m_links.m_size = m_size + 1;
  m_data[v9].a = a;
  m_data[v9].w = w;
  m_data[v9].b = b;
  return (unsigned int)(this->m_links.m_size - 1);
}

// File Line: 44
// RVA: 0xC1EEB0
bool __fastcall compareLinks(
        hkaiDirectedGraphExplicitCostBuilder::Link *l1,
        hkaiDirectedGraphExplicitCostBuilder::Link *l2)
{
  return l1->a < l2->a;
}

// File Line: 49
// RVA: 0xC1EEC0
bool __fastcall compareLinksFull(
        hkaiDirectedGraphExplicitCostBuilder::Link *l1,
        hkaiDirectedGraphExplicitCostBuilder::Link *l2)
{
  int a; // r8d
  int v3; // r9d
  int b; // eax
  bool result; // al

  a = l1->a;
  v3 = l2->a;
  result = 1;
  if ( l1->a >= l2->a )
  {
    if ( a != v3 )
      return 0;
    b = l2->b;
    if ( l1->b >= b && (a != v3 || l1->b != b || l2->w <= l1->w) )
      return 0;
  }
  return result;
}

// File Line: 56
// RVA: 0xC1E830
hkaiDirectedGraphExplicitCost *__fastcall hkaiDirectedGraphExplicitCostBuilder::build(
        hkaiDirectedGraphExplicitCostBuilder *this,
        hkaiDirectedGraphExplicitCost *d)
{
  int m_size; // ebx
  int v5; // r8d
  int v6; // r13d
  int v7; // r15d
  __int64 v8; // rcx
  __int64 v9; // r14
  hkRelocationInfo::Import *m_data; // r12
  __int64 v11; // rbx
  hkaiDirectedGraphExplicitCostBuilder::Link *v12; // rax
  int v13; // ecx
  hkResultEnum v14; // esi
  hkRelocationInfo::Import *v15; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> sizeElem; // [rsp+20h] [rbp-19h] BYREF
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array[2]; // [rsp+30h] [rbp-9h] BYREF
  hkResult result; // [rsp+A0h] [rbp+67h] BYREF
  hkaiDirectedGraphExplicitCost *retaddr; // [rsp+A8h] [rbp+6Fh]
  int b; // [rsp+B0h] [rbp+77h]
  __int64 v22; // [rsp+B8h] [rbp+7Fh]

  if ( !this->m_options.m_allowDuplicateEdges.m_bool )
    hkaiDirectedGraphExplicitCostBuilder::removeDuplicateEdges(this);
  m_size = this->m_positions.m_size;
  array[0].m_capacityAndFlags = 0x80000000;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  if ( m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, array, m_size, 8);
  v5 = this->m_links.m_size;
  array[0].m_size = m_size;
  sizeElem.m_data = 0i64;
  sizeElem.m_size = 0;
  sizeElem.m_capacityAndFlags = 0x80000000;
  if ( v5 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkaiDirectedGraphExplicitCostBuilder::Link,bool (*)(hkaiDirectedGraphExplicitCostBuilder::Link const &,hkaiDirectedGraphExplicitCostBuilder::Link const &)>(
      this->m_links.m_data,
      0,
      v5 - 1,
      compareLinks);
    m_size = array[0].m_size;
  }
  v6 = 0;
  v7 = 0;
  v8 = 0i64;
  v22 = 0i64;
  if ( m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      m_data = array[0].m_data;
      *(int *)((char *)&array[0].m_data->m_fromOffset + v9 + 4) = 0;
      *(int *)((char *)&m_data->m_fromOffset + v9) = sizeElem.m_size;
      if ( v6 < this->m_links.m_size )
      {
        v11 = v8;
        do
        {
          v12 = this->m_links.m_data;
          if ( v12[v11].a != v7 )
            break;
          ++*(int *)((char *)&m_data->m_fromOffset + v9 + 4);
          v13 = sizeElem.m_size;
          b = v12[v11].b;
          *(float *)&result.m_enum = v12[v11].w * 1.0039062;
          v14 = result.m_enum >> 16;
          if ( sizeElem.m_size == (sizeElem.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &sizeElem, 8);
            v13 = sizeElem.m_size;
          }
          v15 = sizeElem.m_data;
          *((_WORD *)&sizeElem.m_data->m_fromOffset + 4 * v13) = v14;
          *((_WORD *)&v15->m_fromOffset + 4 * v13 + 1) = 0;
          *(&v15->m_fromOffset + 2 * v13 + 1) = b;
          ++sizeElem.m_size;
          v8 = v22 + 1;
          ++v6;
          ++v11;
          ++v22;
        }
        while ( v6 < this->m_links.m_size );
      }
      ++v7;
      v9 += 8i64;
    }
    while ( v7 < array[0].m_size );
    d = retaddr;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&d->m_positions,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_positions);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&d->m_nodes,
    array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&d->m_edges,
    &sizeElem);
  sizeElem.m_size = 0;
  if ( sizeElem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sizeElem.m_data,
      8 * sizeElem.m_capacityAndFlags);
  sizeElem.m_data = 0i64;
  array[0].m_size = 0;
  sizeElem.m_capacityAndFlags = 0x80000000;
  if ( array[0].m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array[0].m_data,
      8 * array[0].m_capacityAndFlags);
  return d;
}

// File Line: 98
// RVA: 0xC1EAB0
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::removeDuplicateEdges(
        hkaiDirectedGraphExplicitCostBuilder *this)
{
  int m_size; // r8d
  unsigned int v2; // edi
  int v4; // r10d
  __int64 v5; // r11
  __int64 v6; // r9
  hkaiDirectedGraphExplicitCostBuilder::Link *m_data; // rax
  hkaiDirectedGraphExplicitCostBuilder::Link *v8; // rdx
  __int64 v9; // rax
  hkaiDirectedGraphExplicitCostBuilder::Link *v10; // rdx
  hkaiDirectedGraphExplicitCostBuilder::Link *v11; // r8
  hkaiDirectedGraphExplicitCostBuilder::Link *v12; // rcx
  __int64 v13; // rdx
  signed __int64 v14; // r8
  float v15; // eax

  m_size = this->m_links.m_size;
  v2 = 0;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDirectedGraphExplicitCostBuilder::Link,bool (*)(hkaiDirectedGraphExplicitCostBuilder::Link const &,hkaiDirectedGraphExplicitCostBuilder::Link const &)>(
      this->m_links.m_data,
      0,
      m_size - 1,
      compareLinksFull);
  v4 = this->m_links.m_size - 1;
  v5 = v4;
  if ( v4 >= 1i64 )
  {
    v6 = v4;
    do
    {
      m_data = this->m_links.m_data;
      v8 = &m_data[v6 - 1];
      if ( m_data[v6].a == v8->a && m_data[v6].b == v8->b )
      {
        v9 = --this->m_links.m_size;
        if ( (_DWORD)v9 != v4 )
        {
          v10 = this->m_links.m_data;
          v11 = &v10[v9];
          v12 = &v10[v6];
          v13 = 3i64;
          v14 = (char *)v11 - (char *)v12;
          do
          {
            v15 = *(float *)((char *)&v12->a + v14);
            v12 = (hkaiDirectedGraphExplicitCostBuilder::Link *)((char *)v12 + 4);
            v12[-1].w = v15;
            --v13;
          }
          while ( v13 );
        }
        ++v2;
      }
      --v4;
      --v6;
      --v5;
    }
    while ( v5 );
  }
  return v2;
}

// File Line: 152
// RVA: 0xC1EB90
__int64 __fastcall hkaiHashingDirectedGraphBuilder::addPosition(hkaiHashingDirectedGraphBuilder *this, hkVector4f *p)
{
  __int64 v4; // rdi
  int Key; // eax
  __int64 result; // rax
  int m_size; // ebp

  v4 = (73856093i64 * p->m_quad.m128_u32[0]) ^ (83492791i64 * p->m_quad.m128_u32[2]) ^ (19349663i64
                                                                                      * p->m_quad.m128_u32[1]);
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_keyToIndexMap.m_map,
                        v4);
  if ( Key > this->m_keyToIndexMap.m_map.m_hashMod )
  {
    m_size = this->m_positions.m_size;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_keyToIndexMap.m_map,
      &hkContainerHeapAllocator::s_alloc,
      v4,
      m_size);
    if ( this->m_positions.m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_positions, 16);
    result = (unsigned int)m_size;
    this->m_positions.m_data[this->m_positions.m_size++] = (hkVector4f)p->m_quad;
  }
  else
  {
    result = SLODWORD(this->m_keyToIndexMap.m_map.m_elem[Key].val);
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(p->m_quad, this->m_positions.m_data[result].m_quad)) & 7) != 7 )
      ++this->m_collisions;
  }
  return result;
}

