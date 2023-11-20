// File Line: 17
// RVA: 0xBA9CC0
unsigned __int64 __fastcall anonymous_namespace_::getOrderedKey(hkaiEdgeGeometry::Edge *cur)
{
  __int64 v1; // rdx
  __int64 v2; // r8
  unsigned __int64 result; // rax

  v1 = cur->m_a;
  v2 = cur->m_b;
  if ( (unsigned int)v1 >= (unsigned int)v2 )
    result = v1 | (v2 << 32);
  else
    result = v2 | ((unsigned __int64)(unsigned int)v1 << 32);
  return result;
}

// File Line: 27
// RVA: 0xBA97C0
hkResult *__fastcall hkaiUniqueEdges::setGeometry(hkaiUniqueEdges *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  signed __int64 v3; // rbx
  hkaiEdgeGeometry *v4; // r15
  int v5; // er9
  hkResult *v6; // r13
  hkaiUniqueEdges *v7; // rsi
  int v8; // er14
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // eax
  bool v15; // zf
  __int64 v16; // r8
  int v17; // eax
  int v18; // er9
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // er9
  unsigned int v24; // er11
  signed __int64 v25; // r9
  signed __int64 v26; // r14
  __int64 v27; // r10
  hkRadixSort::SortData32 *v28; // r8
  hkaiEdgeGeometry::Edge *v29; // rax
  unsigned int v30; // edx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rcx
  int v34; // er12
  int v35; // er9
  signed __int64 v36; // r8
  hkRadixSort::SortData32 *v37; // rdx
  hkaiEdgeGeometry::Edge *v38; // rax
  unsigned int v39; // ecx
  unsigned int v40; // eax
  signed int v41; // er8
  signed __int64 v42; // r9
  hkaiEdgeGeometry::Edge **v43; // rbx
  hkaiEdgeGeometry::Edge *v44; // rax
  __int64 v45; // rcx
  __int64 v46; // r10
  unsigned __int64 v47; // rdx
  hkaiEdgeGeometry::Edge *v48; // rax
  __int64 v49; // r10
  __int64 v50; // r11
  unsigned __int64 v51; // rcx
  hkaiEdgeGeometry::Edge **v52; // rax
  __int64 v53; // rcx
  hkRadixSort::SortData32 *array; // [rsp+30h] [rbp-20h]
  int v56; // [rsp+38h] [rbp-18h]
  int v57; // [rsp+3Ch] [rbp-14h]
  hkRadixSort::SortData32 *buffer; // [rsp+40h] [rbp-10h]
  int v59; // [rsp+48h] [rbp-8h]
  int v60; // [rsp+4Ch] [rbp-4h]
  hkResult resulta; // [rsp+80h] [rbp+30h]

  v3 = geom->m_edges.m_size;
  v4 = geom;
  v5 = v3 + 4;
  v6 = result;
  v7 = this;
  array = 0i64;
  v56 = 0;
  v57 = 2147483648;
  if ( (signed int)v3 + 4 > 0 )
  {
    if ( v5 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v5, 8);
  }
  v8 = v3 + 1;
  v9 = v7->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (signed int)v3 + 1 )
  {
    v10 = 2 * v9;
    v11 = v3 + 1;
    if ( v8 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v11, 8);
  }
  v7->m_startUniqueEdge.m_size = 0;
  v12 = v7->m_startUniqueEdge.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v8 )
  {
    v13 = 2 * v12;
    if ( v8 < v13 )
      v8 = v13;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_startUniqueEdge,
      v8,
      8);
  }
  v14 = v57 & 0x3FFFFFFF;
  if ( (v57 & 0x3FFFFFFF) > 0 && !array
    || (v7->m_edges.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v7->m_edges.m_data
    || (v7->m_startUniqueEdge.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v7->m_startUniqueEdge.m_data )
  {
    v15 = v57 >= 0;
    v56 = 0;
    v6->m_enum = 1;
    if ( v15 )
    {
      v16 = (unsigned int)(8 * v14);
LABEL_71:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        v16);
      return v6;
    }
    return v6;
  }
  if ( v14 < (signed int)v3 )
  {
    v17 = 2 * v14;
    v18 = v3;
    if ( (signed int)v3 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v18, 8);
  }
  v19 = v7->m_edges.m_capacityAndFlags;
  v20 = v3;
  v56 = v3;
  v21 = v19 & 0x3FFFFFFF;
  if ( v21 < (signed int)v3 )
  {
    v22 = 2 * v21;
    v23 = v3;
    if ( (signed int)v3 < v22 )
      v23 = v22;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v23, 8);
    v20 = v56;
  }
  v7->m_edges.m_size = v3;
  v24 = 0;
  v25 = 0i64;
  v26 = v3;
  if ( (signed int)v3 > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = &array[v25];
      v29 = v4->m_edges.m_data;
      v30 = v29[v27].m_b;
      if ( v29[v27].m_a > v30 )
        v30 = v29[v27].m_a;
      ++v25;
      v28->m_userData = v24++;
      ++v27;
      v28->m_key = v30;
    }
    while ( v25 < v3 );
    v20 = v56;
  }
  v56 = v20 + 1;
  array[v20].m_key = -1;
  v31 = v56++;
  array[v31].m_key = -1;
  v32 = v56++;
  array[v32].m_key = -1;
  v33 = v56++;
  array[v33].m_key = -1;
  buffer = 0i64;
  v59 = 0;
  v34 = v56;
  v60 = 2147483648;
  if ( v56 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v35 = v56;
    if ( v56 < 0 )
      v35 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &buffer, v35, 8);
    if ( resulta.m_enum )
    {
      v6->m_enum = 1;
      v59 = 0;
      if ( v60 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          buffer,
          8 * v60);
      buffer = 0i64;
      v60 = 2147483648;
      v56 = 0;
      goto LABEL_69;
    }
  }
  v59 = v34;
  if ( (signed int)v3 >= 8 )
  {
    hkRadixSort::sort32(array, (v3 + 3) & 0xFFFFFFFC, buffer);
  }
  else if ( (signed int)v3 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(
      (hkValueIndexPair *)array,
      0,
      v3 - 1,
      0);
  }
  v36 = 0i64;
  if ( (signed int)v3 > 0 )
  {
    do
    {
      v37 = &array[v36];
      v38 = &v4->m_edges.m_data[v37->m_userData];
      v39 = v38->m_b;
      v40 = v38->m_a;
      if ( v40 < v39 )
        v39 = v40;
      ++v36;
      v37->m_key = v39;
    }
    while ( v36 < v3 );
  }
  if ( (signed int)v3 >= 8 )
  {
    hkRadixSort::sort32(array, (v3 + 3) & 0xFFFFFFFC, buffer);
  }
  else if ( (signed int)v3 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(
      (hkValueIndexPair *)array,
      0,
      v3 - 1,
      0);
  }
  v59 = 0;
  if ( v60 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      buffer,
      8 * v60);
  if ( (_DWORD)v3 )
  {
    v41 = 1;
    v42 = 1i64;
    *v7->m_edges.m_data = &v4->m_edges.m_data[array->m_userData];
    v7->m_startUniqueEdge.m_data[v7->m_startUniqueEdge.m_size++] = v7->m_edges.m_data;
    if ( v3 > 1 )
    {
      do
      {
        v7->m_edges.m_data[v42] = &v4->m_edges.m_data[array[v42].m_userData];
        v43 = v7->m_edges.m_data;
        v44 = v7->m_edges.m_data[v42];
        v45 = v44->m_b;
        v46 = v44->m_a;
        if ( (unsigned int)v46 >= (unsigned int)v45 )
          v47 = v46 | (v45 << 32);
        else
          v47 = v45 | ((unsigned __int64)(unsigned int)v46 << 32);
        v48 = v43[v42 - 1];
        v49 = v48->m_b;
        v50 = v48->m_a;
        if ( (unsigned int)v50 >= (unsigned int)v49 )
          v51 = v50 | (v49 << 32);
        else
          v51 = v49 | ((unsigned __int64)(unsigned int)v50 << 32);
        if ( v47 != v51 )
          v7->m_startUniqueEdge.m_data[v7->m_startUniqueEdge.m_size++] = &v43[v41];
        ++v42;
        ++v41;
      }
      while ( v42 < v26 );
    }
  }
  v52 = v7->m_edges.m_data;
  v53 = v7->m_startUniqueEdge.m_size;
  v6->m_enum = 0;
  v7->m_startUniqueEdge.m_data[v53] = &v52[v26];
  ++v7->m_startUniqueEdge.m_size;
  v56 = 0;
LABEL_69:
  if ( v57 >= 0 )
  {
    v16 = (unsigned int)(8 * v57);
    goto LABEL_71;
  }
  return v6;
}

// File Line: 117
// RVA: 0xBA9CB0
void __fastcall hkaiUniqueEdges::clear(hkaiUniqueEdges *this)
{
  this->m_edges.m_size = 0;
  this->m_startUniqueEdge.m_size = 0;
}

