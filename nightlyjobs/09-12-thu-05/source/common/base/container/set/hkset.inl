// File Line: 197
// RVA: 0x12E6DB0
hkResult *__fastcall hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *this, hkResult *result, int newcap)
{
  __int64 v3; // rbp
  signed int v4; // ebx
  hkResult *v5; // rsi
  hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *v6; // rdi
  int v7; // er8
  signed __int64 v9; // rcx
  __int64 v10; // rsi
  hkRelocationInfo::Import *v11; // rax
  hkaiGeometrySegmentCaster::ExtrudedEdge v12; // rbx
  int v13; // er8
  int v14; // ecx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v15; // r9
  int v16; // er10
  signed int v17; // er11
  int v18; // eax
  hkaiGeometrySegmentCaster::ExtrudedEdge *v19; // rdx
  __int64 v20; // rcx
  hkResult *v21; // rbx
  int v22; // er8
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v23; // [rsp+30h] [rbp-38h]
  hkResult v24; // [rsp+70h] [rbp+8h]
  hkResult *v25; // [rsp+78h] [rbp+10h]
  hkResult resulta; // [rsp+80h] [rbp+18h]
  __int64 v27; // [rsp+88h] [rbp+20h]

  v25 = result;
  v3 = this->m_elem.m_size;
  v4 = 8;
  v5 = result;
  v6 = this;
  if ( newcap > 8 )
    v4 = newcap;
  v23.m_data = 0i64;
  v23.m_size = 0;
  v23.m_capacityAndFlags = 2147483648;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v23,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
  if ( (v6->m_elem.m_capacityAndFlags & 0x3FFFFFFF) >= v4 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v4, 8);
    if ( resulta.m_enum )
    {
      v7 = v23.m_capacityAndFlags;
      v5->m_enum = 1;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v23.m_data,
          8 * v7);
      return v5;
    }
  }
  v9 = 0i64;
  v6->m_elem.m_size = v4;
  if ( v4 > 0 )
  {
    do
      v6->m_elem.m_data[++v9 - 1] = (hkaiGeometrySegmentCaster::ExtrudedEdge)-1i64;
    while ( v9 < v4 );
  }
  v10 = 0i64;
  v6->m_numElems = 0;
  if ( v3 > 0 )
  {
    v11 = v23.m_data;
    do
    {
      if ( *(&v11->m_fromOffset + 2 * v10) != -1 )
      {
        v12 = (hkaiGeometrySegmentCaster::ExtrudedEdge)*((_QWORD *)&v11->m_fromOffset + v10);
        v13 = v6->m_elem.m_size;
        v14 = v6->m_numElems & 0x7FFFFFFF;
        v27 = *((_QWORD *)&v11->m_fromOffset + v10);
        if ( 2 * v14 > v13 - 1 )
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            v6,
            &v24,
            2 * v13);
        v15 = v6->m_elem.m_data;
        v16 = v6->m_elem.m_size - 1;
        v17 = 1;
        v18 = v16 & (23857 * v12.m_a ^ -1640531535 * HIDWORD(v27));
        v19 = &v6->m_elem.m_data[v18];
        if ( v19->m_a != -1 )
        {
          while ( v19->m_a != v12.m_a || v19->m_b != HIDWORD(v27) )
          {
            v18 = v16 & (v18 + 1);
            v19 = &v15[v18];
            if ( v19->m_a == -1 )
              goto LABEL_22;
          }
          v17 = 0;
        }
LABEL_22:
        v6->m_numElems += v17;
        v20 = v18;
        v11 = v23.m_data;
        v15[v20] = v12;
      }
      ++v10;
    }
    while ( v10 < v3 );
  }
  v21 = v25;
  v22 = v23.m_capacityAndFlags;
  v25->m_enum = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v23.m_data,
      8 * v22);
  return v21;
}

// File Line: 302
// RVA: 0xB5E4E0
void __fastcall hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(hkSet<int,hkContainerHeapAllocator,hkMapOperations<int> > *this)
{
  __int64 v1; // r8
  __int64 i; // rdx

  v1 = this->m_elem.m_size;
  for ( i = 0i64; i < v1; this->m_elem.m_data[i - 1] = -1 )
    ++i;
  this->m_numElems = 0;
}

