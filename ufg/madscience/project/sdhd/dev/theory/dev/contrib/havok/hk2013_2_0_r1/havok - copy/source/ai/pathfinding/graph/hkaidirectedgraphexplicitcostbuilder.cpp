// File Line: 20
// RVA: 0xC1E720
void __fastcall hkaiDirectedGraphExplicitCostBuilder::BuildOptions::BuildOptions(hkaiDirectedGraphExplicitCostBuilder::BuildOptions *this)
{
  this->m_allowDuplicateEdges.m_bool = 1;
}

// File Line: 25
// RVA: 0xC1E6C0
void __fastcall hkaiGraphBuilder::addSymmetricEdge(hkaiGraphBuilder *this, int a, int b, float w)
{
  unsigned int v4; // esi
  unsigned int v5; // ebx
  hkaiGraphBuilder *v6; // rdi

  v4 = b;
  v5 = a;
  v6 = this;
  ((void (*)(void))this->vfptr->addEdge)();
  ((void (__fastcall *)(hkaiGraphBuilder *, _QWORD, _QWORD))v6->vfptr->addEdge)(v6, v4, v5);
}

// File Line: 31
// RVA: 0xC1E730
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::addPosition(hkaiDirectedGraphExplicitCostBuilder *this, hkVector4f *p)
{
  hkVector4f *v2; // rsi
  hkaiDirectedGraphExplicitCostBuilder *v3; // rdi

  v2 = p;
  v3 = this;
  if ( this->m_positions.m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_positions, 16);
  v3->m_positions.m_data[v3->m_positions.m_size++] = (hkVector4f)v2->m_quad;
  return (unsigned int)(v3->m_positions.m_size - 1);
}

// File Line: 37
// RVA: 0xC1E7A0
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::addEdge(hkaiDirectedGraphExplicitCostBuilder *this, int a, int b, float w)
{
  int v4; // esi
  int v5; // ebp
  hkaiDirectedGraphExplicitCostBuilder *v6; // rdi
  signed __int64 v7; // rcx
  hkaiDirectedGraphExplicitCostBuilder::Link *v8; // rdx
  signed __int64 v9; // r8

  v4 = b;
  v5 = a;
  v6 = this;
  if ( this->m_links.m_size == (this->m_links.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_links, 12);
  v7 = v6->m_links.m_size;
  v8 = v6->m_links.m_data;
  v9 = v7;
  v6->m_links.m_size = v7 + 1;
  v8[v9].a = v5;
  v8[v9].w = w;
  v8[v9].b = v4;
  return (unsigned int)(v6->m_links.m_size - 1);
}

// File Line: 44
// RVA: 0xC1EEB0
bool __fastcall compareLinks(hkaiDirectedGraphExplicitCostBuilder::Link *l1, hkaiDirectedGraphExplicitCostBuilder::Link *l2)
{
  return l1->a < l2->a;
}

// File Line: 49
// RVA: 0xC1EEC0
bool __fastcall compareLinksFull(hkaiDirectedGraphExplicitCostBuilder::Link *l1, hkaiDirectedGraphExplicitCostBuilder::Link *l2)
{
  int v2; // er8
  int v3; // er9
  int v4; // eax
  bool result; // al

  v2 = l1->a;
  v3 = l2->a;
  result = 1;
  if ( l1->a >= l2->a )
  {
    if ( v2 != v3 || (v4 = l2->b, l1->b >= v4) && (v2 != v3 || l1->b != v4 || l2->w <= l1->w) )
      result = 0;
  }
  return result;
}

// File Line: 56
// RVA: 0xC1E830
hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *__fastcall hkaiDirectedGraphExplicitCostBuilder::build(hkaiDirectedGraphExplicitCostBuilder *this, hkaiDirectedGraphExplicitCost *d)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // rsi
  hkaiDirectedGraphExplicitCostBuilder *v3; // rdi
  int v4; // ebx
  int v5; // er9
  signed int v6; // er8
  int v7; // er13
  int v8; // er15
  signed __int64 v9; // rcx
  __int64 v10; // r14
  char *v11; // r12
  signed __int64 v12; // rbx
  hkaiDirectedGraphExplicitCostBuilder::Link *v13; // rax
  __int64 v14; // rcx
  signed int v15; // esi
  _WORD *v16; // rax
  int sizeElem[2]; // [rsp+20h] [rbp-19h]
  int v19; // [rsp+28h] [rbp-11h]
  int v20; // [rsp+2Ch] [rbp-Dh]
  char *array; // [rsp+30h] [rbp-9h]
  int v22; // [rsp+38h] [rbp-1h]
  int v23; // [rsp+3Ch] [rbp+3h]
  hkResult result; // [rsp+A0h] [rbp+67h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *retaddr; // [rsp+A8h] [rbp+6Fh]
  int v26; // [rsp+B0h] [rbp+77h]
  __int64 v27; // [rsp+B8h] [rbp+7Fh]

  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)d;
  v3 = this;
  if ( !this->m_options.m_allowDuplicateEdges.m_bool )
    hkaiDirectedGraphExplicitCostBuilder::removeDuplicateEdges(this);
  v4 = v3->m_positions.m_size;
  v23 = 2147483648;
  array = 0i64;
  v22 = 0;
  if ( v4 > 0 )
  {
    v5 = v4;
    if ( v4 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v5, 8);
  }
  v6 = v3->m_links.m_size;
  v22 = v4;
  *(_QWORD *)sizeElem = 0i64;
  v19 = 0;
  v20 = 2147483648;
  if ( v6 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkaiDirectedGraphExplicitCostBuilder::Link,bool (*)(hkaiDirectedGraphExplicitCostBuilder::Link const &,hkaiDirectedGraphExplicitCostBuilder::Link const &)>(
      v3->m_links.m_data,
      0,
      v6 - 1,
      compareLinks);
    v4 = v22;
  }
  v7 = 0;
  v8 = 0;
  v9 = 0i64;
  v27 = 0i64;
  if ( v4 > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = array;
      *(_DWORD *)&array[v10 + 4] = 0;
      *(_DWORD *)&v11[v10] = v19;
      if ( v7 < v3->m_links.m_size )
      {
        v12 = v9;
        do
        {
          v13 = v3->m_links.m_data;
          if ( v13[v12].a != v8 )
            break;
          ++*(_DWORD *)&v11[v10 + 4];
          LODWORD(v14) = v19;
          v26 = v13[v12].b;
          *(float *)&result.m_enum = v13[v12].w * 1.0039062;
          v15 = (signed int)result.m_enum >> 16;
          if ( v19 == (v20 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, sizeElem, 8);
            LODWORD(v14) = v19;
          }
          v16 = *(_WORD **)sizeElem;
          v14 = (signed int)v14;
          *(_WORD *)(*(_QWORD *)sizeElem + 8 * v14) = v15;
          v16[4 * v14 + 1] = 0;
          *(_DWORD *)&v16[4 * v14 + 2] = v26;
          ++v19;
          v9 = v27 + 1;
          ++v7;
          ++v12;
          ++v27;
        }
        while ( v7 < v3->m_links.m_size );
      }
      ++v8;
      v10 += 8i64;
    }
    while ( v8 < v22 );
    v2 = retaddr;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v2 + 1,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_positions);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v2 + 2,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v2 + 3,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)sizeElem);
  v19 = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)sizeElem,
      8 * v20);
  *(_QWORD *)sizeElem = 0i64;
  v22 = 0;
  v20 = 2147483648;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v23);
  return v2;
}oc.vfptr->bufFree(
      (hkM

// File Line: 98
// RVA: 0xC1EAB0
__int64 __fastcall hkaiDirectedGraphExplicitCostBuilder::removeDuplicateEdges(hkaiDirectedGraphExplicitCostBuilder *this)
{
  int v1; // er8
  unsigned int v2; // edi
  hkaiDirectedGraphExplicitCostBuilder *v3; // rbx
  int v4; // er10
  __int64 v5; // r11
  signed __int64 v6; // r9
  hkaiDirectedGraphExplicitCostBuilder::Link *v7; // rax
  hkaiDirectedGraphExplicitCostBuilder::Link *v8; // rdx
  __int64 v9; // rax
  hkaiDirectedGraphExplicitCostBuilder::Link *v10; // rdx
  signed __int64 v11; // r8
  signed __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // r8
  int v15; // eax

  v1 = this->m_links.m_size;
  v2 = 0;
  v3 = this;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDirectedGraphExplicitCostBuilder::Link,bool (*)(hkaiDirectedGraphExplicitCostBuilder::Link const &,hkaiDirectedGraphExplicitCostBuilder::Link const &)>(
      this->m_links.m_data,
      0,
      v1 - 1,
      compareLinksFull);
  v4 = v3->m_links.m_size - 1;
  v5 = v4;
  if ( v4 >= 1i64 )
  {
    v6 = v4;
    do
    {
      v7 = v3->m_links.m_data;
      v8 = &v7[v6 - 1];
      if ( v7[v6].a == v8->a && v7[v6].b == v8->b )
      {
        v9 = --v3->m_links.m_size;
        if ( (_DWORD)v9 != v4 )
        {
          v10 = v3->m_links.m_data;
          v11 = (signed __int64)&v10[v9];
          v12 = (signed __int64)&v10[v6];
          v13 = 3i64;
          v14 = v11 - v12;
          do
          {
            v15 = *(_DWORD *)(v14 + v12);
            v12 += 4i64;
            *(_DWORD *)(v12 - 4) = v15;
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
  hkVector4f *v2; // rsi
  hkaiHashingDirectedGraphBuilder *v3; // rbx
  signed __int64 v4; // rdi
  int v5; // eax
  __int64 result; // rax
  unsigned int v7; // ebp

  v2 = p;
  v3 = this;
  v4 = 73856093i64 * p->m_quad.m128_u32[0] ^ 83492791i64 * p->m_quad.m128_u32[2] ^ 19349663i64 * p->m_quad.m128_u32[1];
  v5 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_keyToIndexMap.m_map.m_elem,
                           v4);
  if ( v5 > v3->m_keyToIndexMap.m_map.m_hashMod )
  {
    v7 = v3->m_positions.m_size;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_keyToIndexMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v4,
      v3->m_positions.m_size);
    if ( v3->m_positions.m_size == (v3->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_positions, 16);
    result = v7;
    v3->m_positions.m_data[v3->m_positions.m_size++] = (hkVector4f)v2->m_quad;
  }
  else
  {
    result = SLODWORD(v3->m_keyToIndexMap.m_map.m_elem[v5].val);
    if ( (_mm_movemask_ps(_mm_cmpeqps(v2->m_quad, v3->m_positions.m_data[result].m_quad)) & 7) != 7 )
      ++v3->m_collisions;
  }
  return result;
}

