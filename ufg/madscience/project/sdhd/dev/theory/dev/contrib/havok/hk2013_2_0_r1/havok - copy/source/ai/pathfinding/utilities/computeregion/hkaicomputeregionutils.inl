// File Line: 20
// RVA: 0xBC96C0
hkResult *__fastcall hkaiComputeRegionUtils::computeRegions<hkaiNavMesh,float>(hkResult *result, hkaiNavMesh *mesh, bool sortRegionsByArea, hkArrayBase<int> *regionsOut, int *numRegionsOut, hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  hkResult *v6; // r13
  hkArrayBase<int> *v7; // rsi
  bool v8; // r12
  hkSimdFloat32 *v9; // r15
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rdi
  int v16; // ebx
  int v17; // er9
  int v18; // er8
  _QWORD *v19; // r9
  unsigned __int64 v20; // r8
  unsigned __int64 v21; // rax
  int v22; // ebx
  hkLifoAllocator *v23; // rax
  int *v24; // r8
  int v25; // edx
  char *v26; // rcx
  int v27; // er14
  unsigned __int64 v28; // rsi
  int v29; // ebx
  unsigned __int64 v30; // rax
  int v31; // er8
  int v32; // edx
  int v33; // ecx
  int v34; // er8
  int *v35; // rdi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // er8
  signed __int64 v39; // rdi
  void **v40; // r11
  int v41; // er10
  signed __int64 v42; // rbx
  __int64 v43; // r8
  int v44; // ecx
  __int64 v45; // r9
  int *v46; // r14
  signed int v47; // ebx
  hkLifoAllocator *v48; // rax
  int v49; // er8
  signed __int64 v50; // rbx
  int v51; // er9
  signed int v52; // er8
  __m128i v53; // xmm5
  __m128 v54; // xmm3
  __int64 v55; // r9
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  float v58; // xmm4_4
  __int64 v59; // rdx
  __m128i v60; // xmm0
  __m128i v61; // xmm0
  unsigned int v62; // eax
  __m128i v63; // xmm0
  __m128i v64; // xmm0
  signed __int64 i; // rcx
  unsigned int v66; // er14
  __int64 v67; // rcx
  hkArray<float,hkContainerHeapAllocator> *v68; // rbx
  int v69; // eax
  int v70; // eax
  int v71; // er9
  int v72; // er8
  signed __int64 v73; // r8
  int v74; // er9
  int v75; // er8
  int v76; // edx
  __int64 v77; // r8
  signed __int64 v78; // r8
  hkArrayBase<int> *v79; // r9
  int *v80; // rax
  _QWORD *v81; // r9
  unsigned __int64 v82; // r8
  unsigned __int64 v83; // rax
  int v85; // [rsp+30h] [rbp-69h]
  hkgpCgoInternal::Set *pArr; // [rsp+38h] [rbp-61h]
  int v87; // [rsp+40h] [rbp-59h]
  int v88; // [rsp+44h] [rbp-55h]
  signed int *array; // [rsp+48h] [rbp-51h]
  int v90; // [rsp+50h] [rbp-49h]
  int v91; // [rsp+54h] [rbp-45h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+60h] [rbp-39h]
  hkArray<int,hkContainerHeapAllocator> orderedGroups; // [rsp+70h] [rbp-29h]
  hkFixedArray<int> parents; // [rsp+80h] [rbp-19h]
  hkUnionFind v95; // [rsp+90h] [rbp-9h]
  hkResult v96; // [rsp+F8h] [rbp+5Fh]
  hkResult resulta; // [rsp+100h] [rbp+67h]
  hkArrayBase<int> *v98; // [rsp+108h] [rbp+6Fh]

  v98 = regionsOut;
  v6 = result;
  v7 = regionsOut;
  v8 = sortRegionsByArea;
  v9 = (hkSimdFloat32 *)mesh;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtcomputeRegions";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = 0i64;
  v91 = 2147483648;
  array = 0i64;
  v90 = 0;
  if ( v8 )
  {
    v16 = v9[1].m_real.m128_i32[2];
    if ( v16 > 0 )
    {
      v17 = v9[1].m_real.m128_i32[2];
      if ( v16 < 0 )
        v17 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v17, 4);
      if ( resulta.m_enum )
      {
        v18 = v91;
        v6->m_enum = 1;
        v90 = 0;
        if ( v18 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            4 * v18);
        array = 0i64;
        v91 = 2147483648;
        v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v20 = v19[1];
        if ( v20 < v19[3] )
        {
          *(_QWORD *)v20 = "Et";
          v21 = __rdtsc();
          *(_DWORD *)(v20 + 8) = v21;
          v19[1] = v20 + 16;
        }
        return v6;
      }
    }
    v90 = v16;
  }
  v22 = v9[1].m_real.m128_i32[2];
  v85 = v22;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (int *)v23->m_cur;
  v25 = (4 * v22 + 127) & 0xFFFFFF80;
  v26 = (char *)v24 + v25;
  if ( v25 > v23->m_slabSize || v26 > v23->m_end )
    v24 = (int *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
  else
    v23->m_cur = v26;
  parents.m_data.m_storage = v24;
  parents.m_size.m_storage = v22;
  hkUnionFind::hkUnionFind(&v95, &parents, v22);
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_size = 0;
  elementsPerGroup.m_capacityAndFlags = 2147483648;
  orderedGroups.m_data = 0i64;
  orderedGroups.m_size = 0;
  orderedGroups.m_capacityAndFlags = 2147483648;
  v95.m_isCollapsed = 0;
  v27 = 0;
  if ( v9[1].m_real.m128_i32[2] > 0 )
  {
    do
    {
      v28 = v9[1].m_real.m128_u64[0];
      if ( *(_WORD *)(v15 + v28 + 10) <= 0 )
        v29 = *(_DWORD *)(v15 + v28);
      else
        v29 = *(_DWORD *)(v15 + v28 + 4);
      while ( v29 != -1 )
      {
        v30 = v9[2].m_real.m128_u64[0];
        if ( !(*(_BYTE *)(v30 + 20i64 * v29 + 16) & 0x40) )
        {
          v31 = *(_DWORD *)(v30 + 20i64 * v29 + 12);
          if ( v31 != -1 )
            hkUnionFind::addEdge(&v95, v27, v31 & 0x3FFFFF);
        }
        v32 = *(_DWORD *)(v15 + v28 + 4);
        if ( v29 < v32 || v29 >= *(signed __int16 *)(v15 + v28 + 10) + v32 - 1 )
        {
          if ( v29 == *(signed __int16 *)(v15 + v28 + 10) + v32 - 1 )
          {
            v29 = *(_DWORD *)(v15 + v28);
          }
          else
          {
            v33 = *(_DWORD *)(v15 + v28);
            if ( v29 < v33 || v29 >= *(signed __int16 *)(v15 + v28 + 8) + v33 - 1 )
              v29 = -1;
            else
              ++v29;
          }
        }
        else
        {
          ++v29;
        }
      }
      ++v27;
      v15 += 16i64;
    }
    while ( v27 < v9[1].m_real.m128_i32[2] );
    v7 = v98;
    LODWORD(v15) = 0;
  }
  hkUnionFind::assignGroups(&v95, &resulta, &elementsPerGroup);
  if ( resulta.m_enum || (hkUnionFind::sortByGroupId(&v95, &v96, &elementsPerGroup, &orderedGroups), v96.m_enum) )
  {
    v34 = orderedGroups.m_capacityAndFlags;
    orderedGroups.m_size = v15;
    v6->m_enum = 1;
    if ( v34 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        orderedGroups.m_data,
        4 * v34);
    elementsPerGroup.m_size = 0;
    orderedGroups.m_capacityAndFlags = 2147483648;
    orderedGroups.m_data = 0i64;
    if ( elementsPerGroup.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        elementsPerGroup.m_data,
        4 * elementsPerGroup.m_capacityAndFlags);
    elementsPerGroup.m_data = 0i64;
    v35 = parents.m_data.m_storage;
    elementsPerGroup.m_capacityAndFlags = 2147483648;
    v36 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
    v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v38 = (v36 + 15) & 0xFFFFFFF0;
    if ( v36 > v37->m_slabSize || (char *)v35 + v38 != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
      hkLifoAllocator::slowBlockFree(v37, v35, v38);
    else
      v37->m_cur = v35;
    goto LABEL_47;
  }
  v39 = elementsPerGroup.m_size;
  v40 = (void **)&array;
  if ( !v8 )
    v40 = (void **)&v7->m_data;
  v41 = 0;
  v42 = 0i64;
  v43 = 0i64;
  if ( elementsPerGroup.m_size > 0 )
  {
    do
    {
      v44 = elementsPerGroup.m_data[v42];
      if ( v44 > 0 )
      {
        v45 = (unsigned int)v44;
        do
        {
          *((_DWORD *)*v40 + orderedGroups.m_data[++v43 - 1]) = v41;
          --v45;
        }
        while ( v45 );
      }
      ++v42;
      ++v41;
    }
    while ( v42 < v39 );
  }
  orderedGroups.m_size = 0;
  if ( orderedGroups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      orderedGroups.m_data,
      4 * orderedGroups.m_capacityAndFlags);
  orderedGroups.m_data = 0i64;
  orderedGroups.m_capacityAndFlags = 2147483648;
  elementsPerGroup.m_size = 0;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  elementsPerGroup.m_data = 0i64;
  v46 = parents.m_data.m_storage;
  elementsPerGroup.m_capacityAndFlags = 2147483648;
  v47 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v49 = (v47 + 15) & 0xFFFFFFF0;
  if ( v47 > v48->m_slabSize || (char *)v46 + v49 != v48->m_cur || v48->m_firstNonLifoEnd == v46 )
    hkLifoAllocator::slowBlockFree(v48, v46, v49);
  else
    v48->m_cur = v46;
  v50 = 0i64;
  v88 = 2147483648;
  pArr = 0i64;
  v87 = 0;
  if ( !v8 )
  {
LABEL_112:
    v80 = numRegionsOut;
    v6->m_enum = v50;
    *v80 = v39;
    goto LABEL_113;
  }
  if ( (signed int)v39 <= 0 )
    goto LABEL_123;
  v51 = v39;
  if ( (signed int)v39 < 0 )
    v51 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, v51, 8);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_123:
    v87 = v39;
    v52 = 0;
    if ( (signed int)v39 > 0 && (unsigned int)v39 >= 8 )
    {
      v53 = _mm_load_si128((const __m128i *)&_xmm);
      v54 = 0i64;
      v55 = 0i64;
      v56 = _mm_shuffle_ps(v54, v54, 229);
      v57 = _mm_unpackhi_ps(v56, v56);
      LODWORD(v58) = (unsigned __int128)_mm_unpackhi_ps(v57, v57);
      do
      {
        v59 = v52;
        v55 += 8i64;
        pArr[v59].m_error = 0.0;
        v60 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v52), 0), v53);
        LODWORD(pArr[v59 + 1].m_error) = v56.m128_i32[0];
        LODWORD(pArr[v59 + 2].m_error) = v57.m128_i32[0];
        pArr[v59 + 3].m_error = v58;
        *((_DWORD *)&pArr[v55 - 7] - 1) = _mm_cvtsi128_si32(v60);
        v61 = _mm_srli_si128(v60, 4);
        *((_DWORD *)&pArr[v55 - 6] - 1) = _mm_cvtsi128_si32(v61);
        *((_DWORD *)&pArr[v55 - 5] - 1) = _mm_cvtsi128_si32(v61);
        *((_DWORD *)&pArr[v55 - 4] - 1) = _mm_cvtsi128_si32(v61);
        pArr[v59 + 4].m_error = 0.0;
        LODWORD(pArr[v59 + 5].m_error) = v56.m128_i32[0];
        LODWORD(pArr[v59 + 6].m_error) = v57.m128_i32[0];
        pArr[v59 + 7].m_error = v58;
        v62 = v52 + 4;
        v52 += 8;
        v63 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v62), 0), v53);
        *((_DWORD *)&pArr[v55 - 3] - 1) = _mm_cvtsi128_si32(v63);
        v64 = _mm_srli_si128(v63, 4);
        *((_DWORD *)&pArr[v55 - 2] - 1) = _mm_cvtsi128_si32(v64);
        *((_DWORD *)&pArr[v55 - 1] - 1) = _mm_cvtsi128_si32(v64);
        *((_DWORD *)&pArr[v55] - 1) = _mm_cvtsi128_si32(v64);
      }
      while ( v52 < (signed int)v39 - (signed int)v39 % 8 );
    }
    for ( i = v52; i < v39; ++v52 )
    {
      pArr[++i - 1].m_error = 0.0;
      *((_DWORD *)&pArr[i] - 1) = v52;
    }
    v66 = 0;
    if ( v85 > 0i64 )
    {
      do
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
          (hkaiNavMeshUtils *)&parents,
          v9,
          (hkaiNavMesh *)v66,
          (__int64)&elementsPerGroup);
        v67 = array[++v50 - 1];
        ++v66;
        pArr[v67].m_error = *(float *)&parents.m_data.m_storage + pArr[v67].m_error;
      }
      while ( v50 < v85 );
    }
    if ( v87 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpCgoInternal::Set,hkAlgorithm::greater<hkgpCgoInternal::Set>>(
        pArr,
        0,
        v87 - 1,
        0);
    v68 = areasOut;
    if ( areasOut )
    {
      v69 = areasOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v69 >= (signed int)v39 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        v70 = 2 * v69;
        v71 = v39;
        if ( (signed int)v39 < v70 )
          v71 = v70;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, areasOut, v71, 4);
        if ( resulta.m_enum )
        {
          v72 = v88;
          v6->m_enum = 1;
          v87 = 0;
          if ( v72 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              pArr,
              8 * v72);
          pArr = 0i64;
          v88 = 2147483648;
LABEL_47:
          v90 = 0;
          if ( v91 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              array,
              4 * v91);
          array = 0i64;
          goto LABEL_118;
        }
      }
      v68->m_size = v39;
      v73 = 0i64;
      if ( v39 >= 4 )
      {
        do
        {
          v73 += 4i64;
          v68->m_data[v73 - 4] = pArr[v73 - 4].m_error;
          v68->m_data[v73 - 3] = pArr[v73 - 3].m_error;
          v68->m_data[v73 - 2] = pArr[v73 - 2].m_error;
          v68->m_data[v73 - 1] = pArr[v73 - 1].m_error;
        }
        while ( v73 < v39 - 3 );
      }
      for ( ; v73 < v39; v68->m_data[v73 - 1] = pArr[v73 - 1].m_error )
        ++v73;
    }
    LODWORD(v50) = 0;
    orderedGroups.m_capacityAndFlags = 2147483648;
    orderedGroups.m_data = 0i64;
    orderedGroups.m_size = 0;
    if ( (signed int)v39 <= 0 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v74 = v39;
      if ( (signed int)v39 < 0 )
        v74 = 0;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &orderedGroups,
        v74,
        4);
      if ( resulta.m_enum )
      {
        v75 = orderedGroups.m_capacityAndFlags;
        v6->m_enum = 1;
        orderedGroups.m_size = 0;
        if ( v75 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            orderedGroups.m_data,
            4 * v75);
        orderedGroups.m_data = 0i64;
        orderedGroups.m_capacityAndFlags = 2147483648;
        goto LABEL_113;
      }
    }
    orderedGroups.m_size = v39;
    v76 = 0;
    if ( (signed int)v39 > 0 )
    {
      v77 = 0i64;
      do
      {
        ++v77;
        orderedGroups.m_data[*((signed int *)&pArr[v77] - 1)] = v76++;
      }
      while ( v76 < orderedGroups.m_size );
    }
    v78 = 0i64;
    if ( v85 > 0i64 )
    {
      v79 = v98;
      do
      {
        ++v78;
        v79->m_data[v78 - 1] = orderedGroups.m_data[array[v78 - 1]];
      }
      while ( v78 < v85 );
    }
    orderedGroups.m_size = 0;
    if ( orderedGroups.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        orderedGroups.m_data,
        4 * orderedGroups.m_capacityAndFlags);
    goto LABEL_112;
  }
  v6->m_enum = 1;
LABEL_113:
  v87 = v50;
  if ( v88 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pArr,
      8 * v88);
  pArr = 0i64;
  v88 = 2147483648;
  v90 = 0;
  if ( v91 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v91);
  array = 0i64;
LABEL_118:
  v91 = 2147483648;
  v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v82 = v81[1];
  if ( v82 < v81[3] )
  {
    v83 = __rdtsc();
    *(_DWORD *)(v82 + 8) = v83;
    *(_QWORD *)v82 = "Et";
    v81[1] = v82 + 16;
  }
  return v6;
} < v81[3] )
  {
    v83 = __rdtsc();
    *(_DWORD *)(v82 + 8) = v83;
    *(_QWORD *)v82 = "Et";
    v81[1] = v82 + 16;
  }
  return v6;
}

