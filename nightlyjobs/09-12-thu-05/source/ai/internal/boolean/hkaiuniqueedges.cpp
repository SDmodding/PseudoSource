// File Line: 17
// RVA: 0xBA9CC0
__int64 __fastcall anonymous_namespace_::getOrderedKey(hkaiEdgeGeometry::Edge *cur)
{
  __int64 m_a; // rdx
  __int64 m_b; // r8

  m_a = cur->m_a;
  m_b = cur->m_b;
  if ( (unsigned int)m_a >= (unsigned int)m_b )
    return m_a | (m_b << 32);
  else
    return m_b | ((unsigned __int64)(unsigned int)m_a << 32);
}

// File Line: 27
// RVA: 0xBA97C0
hkResult *__fastcall hkaiUniqueEdges::setGeometry(hkaiUniqueEdges *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  __int64 m_size; // rbx
  int v7; // r14d
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  int v13; // eax
  bool v14; // zf
  __int64 v15; // r8
  int v16; // eax
  int v17; // r9d
  int m_capacityAndFlags; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  unsigned int v23; // r11d
  __int64 v24; // r9
  __int64 v25; // r14
  __int64 v26; // r10
  hkRadixSort::SortData32 *v27; // r8
  hkaiEdgeGeometry::Edge *m_data; // rax
  unsigned int m_b; // edx
  __int64 v30; // rcx
  __int64 v31; // rcx
  __int64 v32; // rcx
  int v33; // r12d
  __int64 v34; // r8
  hkRadixSort::SortData32 *v35; // rdx
  hkaiEdgeGeometry::Edge *v36; // rax
  unsigned int v37; // ecx
  unsigned int m_a; // eax
  int v39; // r8d
  __int64 v40; // r9
  hkaiEdgeGeometry::Edge **v41; // rbx
  hkaiEdgeGeometry::Edge *v42; // rax
  __int64 v43; // rcx
  __int64 v44; // r10
  unsigned __int64 v45; // rdx
  hkaiEdgeGeometry::Edge *v46; // rax
  __int64 v47; // r10
  __int64 v48; // r11
  unsigned __int64 v49; // rcx
  hkaiEdgeGeometry::Edge **v50; // rax
  __int64 v51; // rcx
  hkRadixSort::SortData32 *array; // [rsp+30h] [rbp-20h] BYREF
  int v54; // [rsp+38h] [rbp-18h]
  int v55; // [rsp+3Ch] [rbp-14h]
  hkRadixSort::SortData32 *buffer; // [rsp+40h] [rbp-10h] BYREF
  int v57; // [rsp+48h] [rbp-8h]
  int v58; // [rsp+4Ch] [rbp-4h]
  hkResult resulta; // [rsp+80h] [rbp+30h] BYREF

  m_size = geom->m_edges.m_size;
  array = 0i64;
  v54 = 0;
  v55 = 0x80000000;
  if ( (int)m_size + 4 > 0 )
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size + 4, 8);
  v7 = m_size + 1;
  v8 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < (int)m_size + 1 )
  {
    v9 = 2 * v8;
    v10 = m_size + 1;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v10, 8);
  }
  this->m_startUniqueEdge.m_size = 0;
  v11 = this->m_startUniqueEdge.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v7 )
  {
    v12 = 2 * v11;
    if ( v7 < v12 )
      v7 = v12;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_startUniqueEdge, v7, 8);
  }
  v13 = v55 & 0x3FFFFFFF;
  if ( (v55 & 0x3FFFFFFF) != 0 && !array
    || (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_edges.m_data
    || (this->m_startUniqueEdge.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_startUniqueEdge.m_data )
  {
    v14 = v55 >= 0;
    v54 = 0;
    result->m_enum = HK_FAILURE;
    if ( v14 )
    {
      v15 = (unsigned int)(8 * v13);
LABEL_67:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v15);
      return result;
    }
    return result;
  }
  if ( v13 < (int)m_size )
  {
    v16 = 2 * v13;
    v17 = m_size;
    if ( (int)m_size < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v17, 8);
  }
  m_capacityAndFlags = this->m_edges.m_capacityAndFlags;
  v19 = m_size;
  v54 = m_size;
  v20 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < (int)m_size )
  {
    v21 = 2 * v20;
    v22 = m_size;
    if ( (int)m_size < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v22, 8);
    v19 = v54;
  }
  this->m_edges.m_size = m_size;
  v23 = 0;
  v24 = 0i64;
  v25 = m_size;
  if ( (int)m_size > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = &array[v24];
      m_data = geom->m_edges.m_data;
      m_b = m_data[v26].m_b;
      if ( m_data[v26].m_a > m_b )
        m_b = m_data[v26].m_a;
      ++v24;
      v27->m_userData = v23++;
      ++v26;
      v27->m_key = m_b;
    }
    while ( v24 < m_size );
    v19 = v54;
  }
  v54 = v19 + 1;
  array[v19].m_key = -1;
  v30 = v54++;
  array[v30].m_key = -1;
  v31 = v54++;
  array[v31].m_key = -1;
  v32 = v54++;
  array[v32].m_key = -1;
  buffer = 0i64;
  v57 = 0;
  v33 = v54;
  v58 = 0x80000000;
  if ( v54 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &buffer, v54, 8);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, buffer, 8 * v58);
      buffer = 0i64;
      v58 = 0x80000000;
      v54 = 0;
      goto LABEL_65;
    }
  }
  v57 = v33;
  if ( (int)m_size >= 8 )
  {
    hkRadixSort::sort32(array, (m_size + 3) & 0xFFFFFFFC, buffer);
  }
  else if ( (int)m_size > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(
      (hkValueIndexPair *)array,
      0,
      m_size - 1,
      0);
  }
  v34 = 0i64;
  if ( (int)m_size > 0 )
  {
    do
    {
      v35 = &array[v34];
      v36 = &geom->m_edges.m_data[v35->m_userData];
      v37 = v36->m_b;
      m_a = v36->m_a;
      if ( m_a < v37 )
        v37 = m_a;
      ++v34;
      v35->m_key = v37;
    }
    while ( v34 < m_size );
  }
  if ( (int)m_size >= 8 )
  {
    hkRadixSort::sort32(array, (m_size + 3) & 0xFFFFFFFC, buffer);
  }
  else if ( (int)m_size > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(
      (hkValueIndexPair *)array,
      0,
      m_size - 1,
      0);
  }
  v57 = 0;
  if ( v58 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, buffer, 8 * v58);
  if ( (_DWORD)m_size )
  {
    v39 = 1;
    v40 = 1i64;
    *this->m_edges.m_data = &geom->m_edges.m_data[array->m_userData];
    this->m_startUniqueEdge.m_data[this->m_startUniqueEdge.m_size++] = this->m_edges.m_data;
    if ( m_size > 1 )
    {
      do
      {
        this->m_edges.m_data[v40] = &geom->m_edges.m_data[array[v40].m_userData];
        v41 = this->m_edges.m_data;
        v42 = this->m_edges.m_data[v40];
        v43 = v42->m_b;
        v44 = v42->m_a;
        if ( (unsigned int)v44 >= (unsigned int)v43 )
          v45 = v44 | (v43 << 32);
        else
          v45 = v43 | ((unsigned __int64)(unsigned int)v44 << 32);
        v46 = v41[v40 - 1];
        v47 = v46->m_b;
        v48 = v46->m_a;
        if ( (unsigned int)v48 >= (unsigned int)v47 )
          v49 = v48 | (v47 << 32);
        else
          v49 = v47 | ((unsigned __int64)(unsigned int)v48 << 32);
        if ( v45 != v49 )
          this->m_startUniqueEdge.m_data[this->m_startUniqueEdge.m_size++] = &v41[v39];
        ++v40;
        ++v39;
      }
      while ( v40 < v25 );
    }
  }
  v50 = this->m_edges.m_data;
  v51 = this->m_startUniqueEdge.m_size;
  result->m_enum = HK_SUCCESS;
  this->m_startUniqueEdge.m_data[v51] = &v50[v25];
  ++this->m_startUniqueEdge.m_size;
  v54 = 0;
LABEL_65:
  if ( v55 >= 0 )
  {
    v15 = (unsigned int)(8 * v55);
    goto LABEL_67;
  }
  return result;
}

// File Line: 117
// RVA: 0xBA9CB0
void __fastcall hkaiUniqueEdges::clear(hkaiUniqueEdges *this)
{
  this->m_edges.m_size = 0;
  this->m_startUniqueEdge.m_size = 0;
}

