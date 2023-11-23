// File Line: 197
// RVA: 0x12E6DB0
hkResult *__fastcall hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
        hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *this,
        hkResult *result,
        int newcap)
{
  __int64 m_size; // rbp
  int v4; // ebx
  int m_capacityAndFlags; // r8d
  __int64 v9; // rcx
  __int64 v10; // rsi
  hkRelocationInfo::Import *m_data; // rax
  __int64 v12; // rbx
  int v13; // r8d
  int v14; // ecx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v15; // r9
  int v16; // r10d
  int v17; // r11d
  int v18; // eax
  hkaiGeometrySegmentCaster::ExtrudedEdge *v19; // rdx
  __int64 v20; // rcx
  hkResult *v21; // rbx
  int v22; // r8d
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v23; // [rsp+30h] [rbp-38h] BYREF
  hkResult v24; // [rsp+70h] [rbp+8h] BYREF
  hkResult *v25; // [rsp+78h] [rbp+10h]
  hkResult resulta; // [rsp+80h] [rbp+18h] BYREF
  __int64 v27; // [rsp+88h] [rbp+20h]

  v25 = result;
  m_size = this->m_elem.m_size;
  v4 = 8;
  if ( newcap > 8 )
    v4 = newcap;
  v23.m_data = 0i64;
  v23.m_size = 0;
  v23.m_capacityAndFlags = 0x80000000;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v23,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
  if ( (this->m_elem.m_capacityAndFlags & 0x3FFFFFFF) >= v4 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_elem.m_data, v4, 8);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = v23.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v23.m_data,
          8 * m_capacityAndFlags);
      return result;
    }
  }
  v9 = 0i64;
  this->m_elem.m_size = v4;
  do
    this->m_elem.m_data[v9++] = (hkaiGeometrySegmentCaster::ExtrudedEdge)-1i64;
  while ( v9 < v4 );
  v10 = 0i64;
  this->m_numElems = 0;
  if ( m_size > 0 )
  {
    m_data = v23.m_data;
    do
    {
      if ( *(&m_data->m_fromOffset + 2 * v10) != -1 )
      {
        v12 = *((_QWORD *)&m_data->m_fromOffset + v10);
        v13 = this->m_elem.m_size;
        v14 = this->m_numElems & 0x7FFFFFFF;
        v27 = v12;
        if ( 2 * v14 > v13 - 1 )
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            this,
            &v24,
            2 * v13);
        v15 = this->m_elem.m_data;
        v16 = this->m_elem.m_size - 1;
        v17 = 1;
        v18 = v16 & ((23857 * v12) ^ (-1640531535 * HIDWORD(v27)));
        v19 = &this->m_elem.m_data[v18];
        if ( v19->m_a != -1 )
        {
          while ( *v19 != __PAIR64__(HIDWORD(v27), v12) )
          {
            v18 = v16 & (v18 + 1);
            v19 = &v15[v18];
            if ( v19->m_a == -1 )
              goto LABEL_21;
          }
          v17 = 0;
        }
LABEL_21:
        this->m_numElems += v17;
        v20 = v18;
        m_data = v23.m_data;
        v15[v20] = (hkaiGeometrySegmentCaster::ExtrudedEdge)v12;
      }
      ++v10;
    }
    while ( v10 < m_size );
  }
  v21 = v25;
  v22 = v23.m_capacityAndFlags;
  v25->m_enum = HK_SUCCESS;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v23.m_data, 8 * v22);
  return v21;
}

// File Line: 302
// RVA: 0xB5E4E0
void __fastcall hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(
        hkSet<int,hkContainerHeapAllocator,hkMapOperations<int> > *this)
{
  __int64 m_size; // r8
  __int64 i; // rdx

  m_size = this->m_elem.m_size;
  for ( i = 0i64; i < m_size; this->m_elem.m_data[i - 1] = -1 )
    ++i;
  this->m_numElems = 0;
}

