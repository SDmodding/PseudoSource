// File Line: 20
// RVA: 0xBC96C0
hkResult *__fastcall hkaiComputeRegionUtils::computeRegions<hkaiNavMesh,float>(
        hkResult *result,
        hkSimdFloat32 *mesh,
        bool sortRegionsByArea,
        hkArrayBase<int> *regionsOut,
        int *numRegionsOut,
        hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  hkArrayBase<int> *v7; // rsi
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  __int64 v15; // rdi
  int v16; // ebx
  int v17; // r8d
  _QWORD *v18; // r9
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rax
  int v21; // ebx
  hkLifoAllocator *v22; // rax
  int *m_cur; // r8
  int v24; // edx
  char *v25; // rcx
  int v26; // r14d
  hkaiNavMesh::Face *v27; // rsi
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *v29; // rax
  unsigned int m_oppositeFace; // r8d
  int m_startUserEdgeIndex; // edx
  int v32; // ecx
  int m_capacityAndFlags; // r8d
  int *m_storage; // rdi
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // r8d
  __int64 m_size; // rdi
  void **p_array; // r11
  int v40; // r10d
  __int64 v41; // rbx
  __int64 v42; // r8
  int v43; // ecx
  __int64 v44; // r9
  int *v45; // r14
  signed int v46; // ebx
  hkLifoAllocator *v47; // rax
  int v48; // r8d
  __int64 v49; // rbx
  signed int v50; // r8d
  __m128i si128; // xmm5
  __int64 v52; // r9
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  float v55; // xmm4_4
  __m128i v56; // xmm0
  __m128i v57; // xmm0
  __m128i v58; // xmm0
  unsigned int v59; // eax
  __m128i v60; // xmm0
  __m128i v61; // xmm0
  __m128i v62; // xmm0
  __int64 i; // rcx
  unsigned int v64; // r14d
  __int64 v65; // rcx
  hkArray<float,hkContainerHeapAllocator> *v66; // rbx
  int v67; // eax
  int v68; // eax
  int v69; // r9d
  int v70; // r8d
  __int64 v71; // r8
  int v72; // r8d
  int v73; // edx
  __int64 v74; // r8
  __int64 v75; // r8
  hkArrayBase<int> *v76; // r9
  int *v77; // rax
  _QWORD *v78; // r9
  unsigned __int64 v79; // r8
  unsigned __int64 v80; // rax
  int v82; // [rsp+30h] [rbp-69h]
  hkgpCgoInternal::Set *pArr; // [rsp+38h] [rbp-61h] BYREF
  int v84; // [rsp+40h] [rbp-59h]
  int v85; // [rsp+44h] [rbp-55h]
  int *array; // [rsp+48h] [rbp-51h] BYREF
  int v87; // [rsp+50h] [rbp-49h]
  int v88; // [rsp+54h] [rbp-45h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+60h] [rbp-39h] BYREF
  hkArray<int,hkContainerHeapAllocator> orderedGroups; // [rsp+70h] [rbp-29h] BYREF
  hkFixedArray<int> parents; // [rsp+80h] [rbp-19h] BYREF
  hkUnionFind v92; // [rsp+90h] [rbp-9h] BYREF
  hkResult v93; // [rsp+F8h] [rbp+5Fh] BYREF
  hkResult resulta; // [rsp+100h] [rbp+67h] BYREF
  hkArrayBase<int> *v95; // [rsp+108h] [rbp+6Fh]

  v95 = regionsOut;
  v7 = regionsOut;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtcomputeRegions";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = 0i64;
  v88 = 0x80000000;
  array = 0i64;
  v87 = 0;
  if ( sortRegionsByArea )
  {
    v16 = mesh[1].m_real.m128_i32[2];
    if ( v16 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, mesh[1].m_real.m128_i32[2], 4);
      if ( resulta.m_enum )
      {
        v17 = v88;
        result->m_enum = HK_FAILURE;
        v87 = 0;
        if ( v17 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v17);
        array = 0i64;
        v88 = 0x80000000;
        v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v19 = v18[1];
        if ( v19 < v18[3] )
        {
          *(_QWORD *)v19 = "Et";
          v20 = __rdtsc();
          *(_DWORD *)(v19 + 8) = v20;
          v18[1] = v19 + 16;
        }
        return result;
      }
    }
    v87 = v16;
  }
  v21 = mesh[1].m_real.m128_i32[2];
  v82 = v21;
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)v22->m_cur;
  v24 = (4 * v21 + 127) & 0xFFFFFF80;
  v25 = (char *)m_cur + v24;
  if ( v24 > v22->m_slabSize || v25 > v22->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
  else
    v22->m_cur = v25;
  parents.m_data.m_storage = m_cur;
  parents.m_size.m_storage = v21;
  hkUnionFind::hkUnionFind(&v92, &parents, v21);
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_size = 0;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
  orderedGroups.m_data = 0i64;
  orderedGroups.m_size = 0;
  orderedGroups.m_capacityAndFlags = 0x80000000;
  v92.m_isCollapsed = 0;
  v26 = 0;
  if ( mesh[1].m_real.m128_i32[2] > 0 )
  {
    do
    {
      v27 = (hkaiNavMesh::Face *)mesh[1].m_real.m128_u64[0];
      if ( v27[v15].m_numUserEdges <= 0 )
        m_startEdgeIndex = v27[v15].m_startEdgeIndex;
      else
        m_startEdgeIndex = v27[v15].m_startUserEdgeIndex;
      while ( m_startEdgeIndex != -1 )
      {
        v29 = (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0];
        if ( (v29[m_startEdgeIndex].m_flags.m_storage & 0x40) == 0 )
        {
          m_oppositeFace = v29[m_startEdgeIndex].m_oppositeFace;
          if ( m_oppositeFace != -1 )
            hkUnionFind::addEdge(&v92, v26, m_oppositeFace & 0x3FFFFF);
        }
        m_startUserEdgeIndex = v27[v15].m_startUserEdgeIndex;
        if ( m_startEdgeIndex < m_startUserEdgeIndex
          || m_startEdgeIndex >= v27[v15].m_numUserEdges + m_startUserEdgeIndex - 1 )
        {
          if ( m_startEdgeIndex == v27[v15].m_numUserEdges + m_startUserEdgeIndex - 1 )
          {
            m_startEdgeIndex = v27[v15].m_startEdgeIndex;
          }
          else
          {
            v32 = v27[v15].m_startEdgeIndex;
            if ( m_startEdgeIndex < v32 || m_startEdgeIndex >= v27[v15].m_numEdges + v32 - 1 )
              m_startEdgeIndex = -1;
            else
              ++m_startEdgeIndex;
          }
        }
        else
        {
          ++m_startEdgeIndex;
        }
      }
      ++v26;
      ++v15;
    }
    while ( v26 < mesh[1].m_real.m128_i32[2] );
    v7 = v95;
  }
  hkUnionFind::assignGroups(&v92, &resulta, &elementsPerGroup);
  if ( resulta.m_enum || (hkUnionFind::sortByGroupId(&v92, &v93, &elementsPerGroup, &orderedGroups), v93.m_enum) )
  {
    m_capacityAndFlags = orderedGroups.m_capacityAndFlags;
    orderedGroups.m_size = 0;
    result->m_enum = HK_FAILURE;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        orderedGroups.m_data,
        4 * m_capacityAndFlags);
    elementsPerGroup.m_size = 0;
    orderedGroups.m_capacityAndFlags = 0x80000000;
    orderedGroups.m_data = 0i64;
    if ( elementsPerGroup.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        elementsPerGroup.m_data,
        4 * elementsPerGroup.m_capacityAndFlags);
    elementsPerGroup.m_data = 0i64;
    m_storage = parents.m_data.m_storage;
    elementsPerGroup.m_capacityAndFlags = 0x80000000;
    v35 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
    v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (v35 + 15) & 0xFFFFFFF0;
    if ( v35 > v36->m_slabSize || (char *)m_storage + v37 != v36->m_cur || v36->m_firstNonLifoEnd == m_storage )
      hkLifoAllocator::slowBlockFree(v36, m_storage, v37);
    else
      v36->m_cur = m_storage;
    goto LABEL_45;
  }
  m_size = elementsPerGroup.m_size;
  p_array = (void **)&array;
  if ( !sortRegionsByArea )
    p_array = (void **)&v7->m_data;
  v40 = 0;
  v41 = 0i64;
  v42 = 0i64;
  if ( elementsPerGroup.m_size > 0 )
  {
    do
    {
      v43 = elementsPerGroup.m_data[v41];
      if ( v43 > 0 )
      {
        v44 = (unsigned int)v43;
        do
        {
          *((_DWORD *)*p_array + orderedGroups.m_data[v42++]) = v40;
          --v44;
        }
        while ( v44 );
      }
      ++v41;
      ++v40;
    }
    while ( v41 < m_size );
  }
  orderedGroups.m_size = 0;
  if ( orderedGroups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      orderedGroups.m_data,
      4 * orderedGroups.m_capacityAndFlags);
  orderedGroups.m_data = 0i64;
  orderedGroups.m_capacityAndFlags = 0x80000000;
  elementsPerGroup.m_size = 0;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  elementsPerGroup.m_data = 0i64;
  v45 = parents.m_data.m_storage;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
  v46 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v48 = (v46 + 15) & 0xFFFFFFF0;
  if ( v46 > v47->m_slabSize || (char *)v45 + v48 != v47->m_cur || v47->m_firstNonLifoEnd == v45 )
    hkLifoAllocator::slowBlockFree(v47, v45, v48);
  else
    v47->m_cur = v45;
  v49 = 0i64;
  v85 = 0x80000000;
  pArr = 0i64;
  v84 = 0;
  if ( !sortRegionsByArea )
  {
LABEL_105:
    v77 = numRegionsOut;
    result->m_enum = HK_SUCCESS;
    *v77 = m_size;
    goto LABEL_106;
  }
  if ( (int)m_size <= 0
    || (hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &pArr, m_size, 8),
        resulta.m_enum == HK_SUCCESS) )
  {
    v84 = m_size;
    v50 = 0;
    if ( (int)m_size >= 8 )
    {
      si128 = _mm_load_si128((const __m128i *)&_xmm);
      v52 = 0i64;
      v53 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 229);
      v54 = _mm_unpackhi_ps(v53, v53);
      LODWORD(v55) = _mm_unpackhi_ps(v54, v54).m128_u32[0];
      do
      {
        v52 += 8i64;
        pArr[v50].m_error = 0.0;
        v56 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v50), 0), si128);
        LODWORD(pArr[v50 + 1].m_error) = v53.m128_i32[0];
        LODWORD(pArr[v50 + 2].m_error) = v54.m128_i32[0];
        pArr[v50 + 3].m_error = v55;
        *((_DWORD *)&pArr[v52 - 7] - 1) = _mm_cvtsi128_si32(v56);
        v57 = _mm_srli_si128(v56, 4);
        *((_DWORD *)&pArr[v52 - 6] - 1) = _mm_cvtsi128_si32(v57);
        v58 = _mm_srli_si128(v57, 4);
        *((_DWORD *)&pArr[v52 - 5] - 1) = _mm_cvtsi128_si32(v58);
        *((_DWORD *)&pArr[v52 - 4] - 1) = _mm_cvtsi128_si32(_mm_srli_si128(v58, 4));
        pArr[v50 + 4].m_error = 0.0;
        LODWORD(pArr[v50 + 5].m_error) = v53.m128_i32[0];
        LODWORD(pArr[v50 + 6].m_error) = v54.m128_i32[0];
        pArr[v50 + 7].m_error = v55;
        v59 = v50 + 4;
        v50 += 8;
        v60 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v59), 0), si128);
        *((_DWORD *)&pArr[v52 - 3] - 1) = _mm_cvtsi128_si32(v60);
        v61 = _mm_srli_si128(v60, 4);
        *((_DWORD *)&pArr[v52 - 2] - 1) = _mm_cvtsi128_si32(v61);
        v62 = _mm_srli_si128(v61, 4);
        *((_DWORD *)&pArr[v52 - 1] - 1) = _mm_cvtsi128_si32(v62);
        pArr[v52 - 1].m_index = _mm_cvtsi128_si32(_mm_srli_si128(v62, 4));
      }
      while ( v50 < (int)(m_size - (m_size & 0x80000007)) );
    }
    for ( i = v50; i < m_size; pArr[i - 1].m_index = v50++ )
      pArr[i++].m_error = 0.0;
    v64 = 0;
    if ( v82 > 0 )
    {
      do
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
          (hkaiNavMeshUtils *)&parents,
          mesh,
          (hkaiNavMesh *)v64,
          (__m128 *)&elementsPerGroup);
        v65 = array[v49++];
        ++v64;
        pArr[v65].m_error = *(float *)&parents.m_data.m_storage + pArr[v65].m_error;
      }
      while ( v49 < v82 );
    }
    if ( v84 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpCgoInternal::Set,hkAlgorithm::greater<hkgpCgoInternal::Set>>(
        pArr,
        0,
        v84 - 1,
        0);
    v66 = areasOut;
    if ( areasOut )
    {
      v67 = areasOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v67 >= (int)m_size )
      {
        resulta.m_enum = HK_SUCCESS;
      }
      else
      {
        v68 = 2 * v67;
        v69 = m_size;
        if ( (int)m_size < v68 )
          v69 = v68;
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, areasOut, v69, 4);
        if ( resulta.m_enum )
        {
          v70 = v85;
          result->m_enum = HK_FAILURE;
          v84 = 0;
          if ( v70 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 8 * v70);
          pArr = 0i64;
          v85 = 0x80000000;
LABEL_45:
          v87 = 0;
          if ( v88 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v88);
          array = 0i64;
          goto LABEL_111;
        }
      }
      v66->m_size = m_size;
      v71 = 0i64;
      if ( m_size >= 4 )
      {
        do
        {
          v71 += 4i64;
          v66->m_data[v71 - 4] = pArr[v71 - 4].m_error;
          v66->m_data[v71 - 3] = pArr[v71 - 3].m_error;
          v66->m_data[v71 - 2] = pArr[v71 - 2].m_error;
          v66->m_data[v71 - 1] = pArr[v71 - 1].m_error;
        }
        while ( v71 < m_size - 3 );
      }
      for ( ; v71 < m_size; v66->m_data[v71 - 1] = pArr[v71 - 1].m_error )
        ++v71;
    }
    orderedGroups.m_capacityAndFlags = 0x80000000;
    orderedGroups.m_data = 0i64;
    orderedGroups.m_size = 0;
    if ( (int)m_size <= 0 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &orderedGroups, m_size, 4);
      if ( resulta.m_enum )
      {
        v72 = orderedGroups.m_capacityAndFlags;
        result->m_enum = HK_FAILURE;
        orderedGroups.m_size = 0;
        if ( v72 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            orderedGroups.m_data,
            4 * v72);
        orderedGroups.m_data = 0i64;
        orderedGroups.m_capacityAndFlags = 0x80000000;
        goto LABEL_106;
      }
    }
    orderedGroups.m_size = m_size;
    v73 = 0;
    if ( (int)m_size > 0 )
    {
      v74 = 0i64;
      do
        orderedGroups.m_data[pArr[v74++].m_index] = v73++;
      while ( v73 < orderedGroups.m_size );
    }
    v75 = 0i64;
    if ( v82 > 0i64 )
    {
      v76 = v95;
      do
      {
        ++v75;
        v76->m_data[v75 - 1] = orderedGroups.m_data[array[v75 - 1]];
      }
      while ( v75 < v82 );
    }
    orderedGroups.m_size = 0;
    if ( orderedGroups.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        orderedGroups.m_data,
        4 * orderedGroups.m_capacityAndFlags);
    goto LABEL_105;
  }
  result->m_enum = HK_FAILURE;
LABEL_106:
  v84 = 0;
  if ( v85 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 8 * v85);
  pArr = 0i64;
  v85 = 0x80000000;
  v87 = 0;
  if ( v88 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v88);
  array = 0i64;
LABEL_111:
  v88 = 0x80000000;
  v78 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v79 = v78[1];
  if ( v79 < v78[3] )
  {
    v80 = __rdtsc();
    *(_DWORD *)(v79 + 8) = v80;
    *(_QWORD *)v79 = "Et";
    v78[1] = v79 + 16;
  }
  return result;
}

