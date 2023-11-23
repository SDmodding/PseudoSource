// File Line: 49
// RVA: 0xB5F920
hkResult *__fastcall hkaiNavMeshSimplificationUtils::triangulatePartitions(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        bool wallClimbing,
        hkaiNavMesh *originalMesh,
        hkaiNavMesh *navMeshOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        hkArrayBase<int> *partitions,
        hkArrayBase<int> *numFacesInPartition,
        hkArrayBase<int> *partitionDir,
        hkArray<int,hkContainerHeapAllocator> *faceToPartitionMap,
        hkBitField *edgeIsBoundary,
        hkBitField *userVertexOnBoundary,
        hkArrayBase<unsigned int> *faceData)
{
  int v13; // esi
  int *p_m_numUsed; // rdi
  bool v15; // r14
  int v16; // ebx
  __int64 v17; // rsi
  __int128 *v18; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v19; // r14
  __m128i si128; // xmm3
  __m128 v21; // xmm3
  __int64 v22; // rcx
  __m128 v23; // xmm3
  __int64 v24; // rax
  int v25; // esi
  int v26; // r12d
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v27; // r13
  int m_size; // ebx
  int v29; // r8d
  char *v30; // rbx
  int v31; // r8d
  _QWORD *v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rcx
  _QWORD *v36; // rdx
  __int64 v37; // rcx
  __int64 v38; // rax
  __int64 v39; // rcx
  _QWORD *v40; // rdx
  __int64 v41; // rcx
  __int64 v42; // rax
  __int64 v43; // rcx
  _QWORD *v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  __int64 v47; // rcx
  int v48; // r8d
  __int64 v49; // rdx
  __int64 v50; // r9
  hkArrayBase<int> *v51; // r15
  __int64 v52; // rbx
  int v53; // edx
  __int64 v54; // rdi
  __int64 v55; // r14
  int v56; // ecx
  int v57; // eax
  hkaiNavMeshSimplificationUtils::SegmentIdxPid *v58; // r8
  int v59; // r9d
  int v60; // ecx
  int v61; // ebx
  hkVector4f *v62; // rax
  __m128 m_quad; // xmm0
  int *m_data; // rax
  int v65; // r15d
  int *v66; // rax
  signed int v67; // r15d
  __int64 v68; // r14
  int v69; // edi
  hkaiNavMesh::Face *v70; // rax
  hkaiNavMesh::Face *v71; // rsi
  int *v72; // r12
  unsigned __int64 v73; // r13
  hkaiNavMesh::Edge *v74; // rax
  hkaiNavMesh::Edge *v75; // rbx
  hkArray<int,hkContainerHeapAllocator> *v76; // rdx
  int v77; // r9d
  int v78; // eax
  int v79; // eax
  __int64 v80; // rcx
  __int64 v81; // r8
  hkResultEnum m_enum; // eax
  __int64 v83; // r14
  __int16 *p_m_numUserEdges; // rsi
  __int64 v85; // r15
  __int64 m_faceDataStriding; // rcx
  __int64 v87; // r11
  __int64 v88; // r9
  __int64 v89; // r8
  __int64 v90; // rcx
  __int64 v91; // r10
  __int64 m_edgeDataStriding; // rax
  int *v93; // rax
  __int64 v94; // r14
  int *v95; // rax
  int v96; // r8d
  char *v97; // rbx
  int i; // r12d
  int v99; // r8d
  _QWORD *v100; // rdx
  __int64 v101; // rcx
  __int64 v102; // rax
  __int64 v103; // rcx
  _QWORD *v104; // rdx
  __int64 v105; // rcx
  __int64 v106; // rax
  __int64 v107; // rcx
  _QWORD *v108; // rdx
  __int64 v109; // rcx
  __int64 v110; // rax
  __int64 v111; // rcx
  _QWORD *v112; // rdx
  __int64 v113; // rcx
  __int64 v114; // rax
  __int64 v115; // rcx
  char *v116; // rdi
  int v117; // r15d
  int v118; // r8d
  char *v119; // rdi
  int v120; // r15d
  int v121; // r8d
  char *v122; // rdi
  int v123; // r15d
  int v124; // r8d
  int m_capacityAndFlags; // r8d
  char *v126; // rbx
  int v127; // r8d
  char *v129; // rdi
  int v130; // r15d
  int v131; // r8d
  hkaiNavMeshSimplificationUtils::SegmentIdxPid *array; // [rsp+70h] [rbp-90h] BYREF
  int v133; // [rsp+78h] [rbp-88h]
  int v134; // [rsp+7Ch] [rbp-84h]
  hkArray<int,hkContainerTempAllocator> partitionSegments; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f dmin; // [rsp+90h] [rbp-70h] BYREF
  hkArray<int,hkContainerTempAllocator> triangleIndicesOut; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v138; // [rsp+B0h] [rbp-50h] BYREF
  int v139; // [rsp+B4h] [rbp-4Ch]
  int v140; // [rsp+B8h] [rbp-48h]
  hkVector4f dmax; // [rsp+C0h] [rbp-40h] BYREF
  int v142; // [rsp+D0h] [rbp-30h]
  hkResult v143; // [rsp+D4h] [rbp-2Ch] BYREF
  hkResult v144; // [rsp+D8h] [rbp-28h] BYREF
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings v145; // [rsp+E0h] [rbp-20h] BYREF
  hkResult v146; // [rsp+118h] [rbp+18h] BYREF
  int v147; // [rsp+11Ch] [rbp+1Ch]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings; // [rsp+120h] [rbp+20h]
  __int64 v149; // [rsp+128h] [rbp+28h]
  int *v150; // [rsp+130h] [rbp+30h]
  __int64 v151; // [rsp+138h] [rbp+38h]
  __int64 v152; // [rsp+140h] [rbp+40h]
  __int64 v153; // [rsp+148h] [rbp+48h]
  __int128 *v154; // [rsp+150h] [rbp+50h]
  int v155; // [rsp+158h] [rbp+58h]
  int v156; // [rsp+15Ch] [rbp+5Ch]
  __int128 v157[2]; // [rsp+160h] [rbp+60h] BYREF
  __int64 v158; // [rsp+188h] [rbp+88h]
  hkVector4f resulta; // [rsp+190h] [rbp+90h] BYREF
  hkVector4f v160; // [rsp+1A0h] [rbp+A0h] BYREF
  hkVector4f v161; // [rsp+1B0h] [rbp+B0h] BYREF
  __int128 v162; // [rsp+1C0h] [rbp+C0h] BYREF
  __int128 v163[11]; // [rsp+1D0h] [rbp+D0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> v164[6]; // [rsp+280h] [rbp+180h] BYREF
  char v165[60]; // [rsp+5040h] [rbp+4F40h] BYREF
  char v166[4]; // [rsp+507Ch] [rbp+4F7Ch] BYREF

  v13 = 5;
  p_m_numUsed = &v164[0].m_mesh.m_vertices.m_numUsed;
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  do
  {
    *(p_m_numUsed - 10) = 0x1FFFF;
    *((_QWORD *)p_m_numUsed - 6) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    *(p_m_numUsed - 6) = 0x1FFFF;
    *((_QWORD *)p_m_numUsed - 4) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    *((_QWORD *)p_m_numUsed - 2) = 0i64;
    *((_QWORD *)p_m_numUsed - 1) = 0i64;
    *p_m_numUsed = 0;
    *((_QWORD *)p_m_numUsed + 1) = 0i64;
    *((_QWORD *)p_m_numUsed + 2) = 0i64;
    p_m_numUsed[6] = 0;
    p_m_numUsed[10] = 0;
    *((_QWORD *)p_m_numUsed + 4) = p_m_numUsed + 12;
    p_m_numUsed[11] = -2147483584;
    `vector constructor iterator(
      (char *)p_m_numUsed + 48,
      0x10ui64,
      64,
      (void *(__fastcall *)(void *))Assembly::GetRCX);
    *((_BYTE *)p_m_numUsed + 3132) = 0;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(p_m_numUsed - 12),
      &dmin,
      &dmax,
      0.0,
      1);
    --v13;
    p_m_numUsed += 828;
  }
  while ( v13 >= 0 );
  v15 = wallClimbing;
  v155 = 2;
  v157[0] = _xmm_c4fa0000c4fa0000c4fa0000c4fa0000;
  v157[1] = _xmm;
  v154 = v157;
  v156 = -2147483646;
  dmax.m_quad.m128_i32[3] = 16;
  if ( wallClimbing )
  {
    v16 = 0;
    v17 = 0i64;
    v18 = v163;
    v19 = v164;
    do
    {
      dmin.m_quad = hkaiNavMeshSimplificationUtils::_classToDir(&resulta, v16)->m_quad;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)v154;
      dmax.m_quad.m128_i32[2] = v155;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        v19,
        (hkStridedVertices *)&dmax,
        &dmin,
        0,
        1,
        0);
      ++v16;
      si128 = _mm_load_si128((const __m128i *)&dmin);
      *(v18 - 1) = _xmm_c4f98000c4f98000c4f98000c4f98000;
      *v18 = _xmm;
      ++v19;
      v18 += 2;
      v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
      v22 = v17
          + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                   _mm_and_ps(
                                                                     _mm_cmple_ps(
                                                                       _mm_max_ps(
                                                                         _mm_shuffle_ps(v21, v21, 170),
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v21, v21, 85),
                                                                           _mm_shuffle_ps(v21, v21, 0))),
                                                                       v21),
                                                                     (__m128)xmmword_141A4CDC0))];
      v17 += 8i64;
      *((_DWORD *)&v163[-1] + v22) = -8388626;
      *((_DWORD *)v163 + v22) = 2139095022;
    }
    while ( v16 < 6 );
    v15 = wallClimbing;
  }
  else
  {
    dmax.m_quad.m128_u64[0] = (unsigned __int64)v157;
    dmax.m_quad.m128_i32[2] = 2;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
      v164,
      (hkStridedVertices *)&dmax,
      &settings->m_up,
      0,
      1,
      0);
    v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&settings->m_up), 1u), 1u);
    v163[0] = _xmm;
    v162 = _xmm_c4f98000c4f98000c4f98000c4f98000;
    v24 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmple_ps(
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v23, v23, 170),
                                                                       _mm_max_ps(
                                                                         _mm_shuffle_ps(v23, v23, 85),
                                                                         _mm_shuffle_ps(v23, v23, 0))),
                                                                     v23),
                                                                   (__m128)xmmword_141A4CDC0))];
    *((_DWORD *)&v163[-1] + v24) = -8388626;
    *((_DWORD *)v163 + v24) = 2139095022;
  }
  v25 = 0;
  v155 = 0;
  v26 = 5;
  if ( v156 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v154, 16 * v156);
  v27 = segments;
  array = 0i64;
  v133 = 0;
  m_size = segments->m_size;
  v134 = 0x80000000;
  if ( m_size <= 0 )
  {
    v138.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v138, &hkContainerTempAllocator::s_alloc, &array, m_size, 8);
    if ( v138.m_enum )
    {
      v29 = v134;
      v133 = 0;
      result->m_enum = HK_FAILURE;
      if ( v29 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v29);
      array = 0i64;
      v134 = 0x80000000;
      v30 = v165;
      do
      {
        v30 -= 3312;
        *((_QWORD *)v30 - 4) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v30 - 32),
          1);
        v31 = *((_DWORD *)v30 + 15);
        *((_DWORD *)v30 + 14) = 0;
        if ( v31 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)*((_QWORD *)v30 + 6),
            16 * v31);
        *((_QWORD *)v30 + 6) = 0i64;
        *((_DWORD *)v30 + 15) = 0x80000000;
        *((_QWORD *)v30 - 2) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
        while ( *((_QWORD *)v30 + 3) )
        {
          v32 = (_QWORD *)*((_QWORD *)v30 + 3);
          v33 = v32[833];
          v34 = v32[834];
          if ( v33 )
            *(_QWORD *)(v33 + 6672) = v34;
          else
            *((_QWORD *)v30 + 3) = v34;
          v35 = v32[834];
          if ( v35 )
            *(_QWORD *)(v35 + 6664) = v32[833];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v32, 6688);
        }
        *((_QWORD *)v30 + 4) = 0i64;
        *((_DWORD *)v30 + 10) = 0;
        while ( *((_QWORD *)v30 + 3) )
        {
          v36 = (_QWORD *)*((_QWORD *)v30 + 3);
          v37 = v36[833];
          v38 = v36[834];
          if ( v37 )
            *(_QWORD *)(v37 + 6672) = v38;
          else
            *((_QWORD *)v30 + 3) = v38;
          v39 = v36[834];
          if ( v39 )
            *(_QWORD *)(v39 + 6664) = v36[833];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v36, 6688);
        }
        while ( *(_QWORD *)v30 )
        {
          v40 = *(_QWORD **)v30;
          v41 = *(_QWORD *)(*(_QWORD *)v30 + 1544i64);
          v42 = *(_QWORD *)(*(_QWORD *)v30 + 1552i64);
          if ( v41 )
            *(_QWORD *)(v41 + 1552) = v42;
          else
            *(_QWORD *)v30 = v42;
          v43 = v40[194];
          if ( v43 )
            *(_QWORD *)(v43 + 1544) = v40[193];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v40, 1568);
        }
        *((_QWORD *)v30 + 1) = 0i64;
        *((_DWORD *)v30 + 4) = 0;
        while ( *(_QWORD *)v30 )
        {
          v44 = *(_QWORD **)v30;
          v45 = *(_QWORD *)(*(_QWORD *)v30 + 1544i64);
          v46 = *(_QWORD *)(*(_QWORD *)v30 + 1552i64);
          if ( v45 )
            *(_QWORD *)(v45 + 1552) = v46;
          else
            *(_QWORD *)v30 = v46;
          v47 = v44[194];
          if ( v47 )
            *(_QWORD *)(v47 + 1544) = v44[193];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v44, 1568);
        }
        --v26;
        *((_QWORD *)v30 - 2) = &hkBaseObject::`vftable;
        *((_QWORD *)v30 - 4) = &hkBaseObject::`vftable;
      }
      while ( v26 >= 0 );
      return result;
    }
  }
  v133 = m_size;
  v48 = 0;
  if ( segments->m_size > 0 )
  {
    v49 = 0i64;
    v50 = 0i64;
    do
    {
      ++v50;
      array[v49++].m_segmentIndex = v48++;
      array[v49 - 1].m_partitionId = segments->m_data[v50 - 1].m_partitionIdA;
    }
    while ( v48 < segments->m_size );
    m_size = v133;
  }
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavMeshSimplificationUtils::SegmentIdxPid,hkAlgorithm::less<hkaiNavMeshSimplificationUtils::SegmentIdxPid>>(
      array,
      0,
      m_size - 1,
      0);
  v51 = numFacesInPartition;
  v139 = 0;
  v52 = numFacesInPartition->m_size;
  v142 = 0;
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(&v145);
  if ( v15 )
  {
    v145.m_vertexFraction = 0.0;
    v145.m_minPartitionArea = FLOAT_3_40282e38;
    extraVertexSettings = &v145;
  }
  else
  {
    extraVertexSettings = &settings->m_simplificationSettings.m_extraVertexSettings;
  }
  v53 = 0;
  v54 = 0i64;
  v55 = 0i64;
  v153 = v52;
  v140 = 0;
  v151 = 0i64;
  v149 = 0i64;
  if ( (int)v52 <= 0 )
  {
LABEL_187:
    m_capacityAndFlags = v145.m_userVertices.m_capacityAndFlags;
    result->m_enum = HK_SUCCESS;
    v145.m_userVertices.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v145.m_userVertices.m_data,
        16 * m_capacityAndFlags);
    v145.m_userVertices.m_data = 0i64;
    v145.m_userVertices.m_capacityAndFlags = 0x80000000;
    v133 = 0;
    if ( v134 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
    array = 0i64;
    v134 = 0x80000000;
    v126 = v166;
    do
    {
      v126 -= 3312;
      *(_QWORD *)(v126 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v126 - 92),
        1);
      v127 = *(_DWORD *)v126;
      *((_DWORD *)v126 - 1) = 0;
      if ( v127 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v126 - 12),
          16 * v127);
      *(_QWORD *)(v126 - 12) = 0i64;
      *(_DWORD *)v126 = 0x80000000;
      hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::~hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>((hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator> *)(v126 - 76));
      --v26;
      *(_QWORD *)(v126 - 92) = &hkBaseObject::`vftable;
    }
    while ( v26 >= 0 );
  }
  else
  {
    while ( 1 )
    {
      v56 = 0x80000000;
      v57 = 0;
      partitionSegments.m_data = 0i64;
      partitionSegments.m_capacityAndFlags = 0x80000000;
      partitionSegments.m_size = 0;
      if ( v25 < v133 )
      {
        while ( 1 )
        {
          v58 = array;
          if ( array[v54].m_partitionId != v53 )
            break;
          v59 = v57 + 1;
          v60 = v56 & 0x3FFFFFFF;
          if ( v60 >= v57 + 1 )
          {
            v143.m_enum = HK_SUCCESS;
          }
          else
          {
            if ( v59 < 2 * v60 )
              v59 = 2 * v60;
            hkArrayUtil::_reserve(&v143, &hkContainerTempAllocator::s_alloc, &partitionSegments, v59, 4);
            if ( v143.m_enum )
            {
              v96 = partitionSegments.m_capacityAndFlags;
              partitionSegments.m_size = 0;
              result->m_enum = HK_FAILURE;
              if ( v96 >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerTempAllocator::s_alloc,
                  partitionSegments.m_data,
                  4 * v96);
              partitionSegments.m_data = 0i64;
              partitionSegments.m_capacityAndFlags = 0x80000000;
              v145.m_userVertices.m_size = 0;
              if ( v145.m_userVertices.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  v145.m_userVertices.m_data,
                  16 * v145.m_userVertices.m_capacityAndFlags);
              v145.m_userVertices.m_data = 0i64;
              v145.m_userVertices.m_capacityAndFlags = 0x80000000;
              v133 = 0;
              if ( v134 >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
              array = 0i64;
              v134 = 0x80000000;
              v97 = v165;
              for ( i = 5; i >= 0; --i )
              {
                v97 -= 3312;
                *((_QWORD *)v97 - 4) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
                hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
                  (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v97 - 32),
                  1);
                v99 = *((_DWORD *)v97 + 15);
                *((_DWORD *)v97 + 14) = 0;
                if ( v99 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    (void *)*((_QWORD *)v97 + 6),
                    16 * v99);
                *((_QWORD *)v97 + 6) = 0i64;
                *((_DWORD *)v97 + 15) = 0x80000000;
                *((_QWORD *)v97 - 2) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
                while ( *((_QWORD *)v97 + 3) )
                {
                  v100 = (_QWORD *)*((_QWORD *)v97 + 3);
                  v101 = v100[833];
                  v102 = v100[834];
                  if ( v101 )
                    *(_QWORD *)(v101 + 6672) = v102;
                  else
                    *((_QWORD *)v97 + 3) = v102;
                  v103 = v100[834];
                  if ( v103 )
                    *(_QWORD *)(v103 + 6664) = v100[833];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v100, 6688);
                }
                *((_QWORD *)v97 + 4) = 0i64;
                *((_DWORD *)v97 + 10) = 0;
                while ( *((_QWORD *)v97 + 3) )
                {
                  v104 = (_QWORD *)*((_QWORD *)v97 + 3);
                  v105 = v104[833];
                  v106 = v104[834];
                  if ( v105 )
                    *(_QWORD *)(v105 + 6672) = v106;
                  else
                    *((_QWORD *)v97 + 3) = v106;
                  v107 = v104[834];
                  if ( v107 )
                    *(_QWORD *)(v107 + 6664) = v104[833];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v104, 6688);
                }
                while ( *(_QWORD *)v97 )
                {
                  v108 = *(_QWORD **)v97;
                  v109 = *(_QWORD *)(*(_QWORD *)v97 + 1544i64);
                  v110 = *(_QWORD *)(*(_QWORD *)v97 + 1552i64);
                  if ( v109 )
                    *(_QWORD *)(v109 + 1552) = v110;
                  else
                    *(_QWORD *)v97 = v110;
                  v111 = v108[194];
                  if ( v111 )
                    *(_QWORD *)(v111 + 1544) = v108[193];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v108, 1568);
                }
                *((_QWORD *)v97 + 1) = 0i64;
                *((_DWORD *)v97 + 4) = 0;
                while ( *(_QWORD *)v97 )
                {
                  v112 = *(_QWORD **)v97;
                  v113 = *(_QWORD *)(*(_QWORD *)v97 + 1544i64);
                  v114 = *(_QWORD *)(*(_QWORD *)v97 + 1552i64);
                  if ( v113 )
                    *(_QWORD *)(v113 + 1552) = v114;
                  else
                    *(_QWORD *)v97 = v114;
                  v115 = v112[194];
                  if ( v115 )
                    *(_QWORD *)(v115 + 1544) = v112[193];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v112, 1568);
                }
                *((_QWORD *)v97 - 2) = &hkBaseObject::`vftable;
                *((_QWORD *)v97 - 4) = &hkBaseObject::`vftable;
              }
              return result;
            }
            v58 = array;
            v57 = partitionSegments.m_size;
          }
          partitionSegments.m_data[v57] = v58[v54].m_segmentIndex;
          ++v25;
          ++v54;
          v57 = partitionSegments.m_size + 1;
          v142 = v25;
          ++partitionSegments.m_size;
          v151 = v54;
          if ( v25 >= v133 )
            break;
          v56 = partitionSegments.m_capacityAndFlags;
          v53 = v140;
        }
      }
      if ( wallClimbing )
      {
        v61 = partitionDir->m_data[v55];
        v62 = hkaiNavMeshSimplificationUtils::_classToDir(&v161, v61);
      }
      else
      {
        v61 = 0;
        v62 = &v160;
        v160.m_quad = (__m128)settings->m_up;
      }
      m_quad = v62->m_quad;
      m_data = v51->m_data;
      triangleIndicesOut.m_data = 0i64;
      triangleIndicesOut.m_size = 0;
      resulta.m_quad = m_quad;
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      triangleIndicesOut.m_capacityAndFlags = 0x80000000;
      v65 = m_data[v55];
      v66 = partitions->m_data;
      dmax.m_quad.m128_i32[2] = v65;
      v67 = v65 | 0x80000000;
      v147 = v67;
      dmax.m_quad.m128_i32[3] = v67;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)&v66[v139];
      hkaiNavMeshSimplificationUtils::triangulatePartition(
        &v146,
        extraVertexSettings,
        originalMesh,
        &navMeshOut->m_vertices,
        v27,
        &partitionSegments,
        (hkArray<int const ,hkContainerHeapAllocator> *)&dmax,
        &resulta,
        &triangleIndicesOut,
        (hkArray<int,hkContainerTempAllocator> *)&dmin,
        edgeIsBoundary,
        userVertexOnBoundary,
        &v164[v61],
        (hkAabb *)&v163[2 * v61 - 1]);
      if ( v146.m_enum )
        break;
      v68 = navMeshOut->m_faces.m_size;
      v69 = triangleIndicesOut.m_size / 3;
      v70 = hkaiNavMesh::expandFacesBy(navMeshOut, triangleIndicesOut.m_size / 3, -1);
      v71 = v70;
      if ( v69 && !v70 )
      {
        result->m_enum = HK_FAILURE;
        dmin.m_quad.m128_i32[2] = 0;
        if ( dmin.m_quad.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[0],
            4 * dmin.m_quad.m128_i32[3]);
        dmin.m_quad.m128_u64[0] = 0i64;
        dmin.m_quad.m128_i32[3] = 0x80000000;
        triangleIndicesOut.m_size = 0;
        if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            triangleIndicesOut.m_data,
            4 * triangleIndicesOut.m_capacityAndFlags);
        triangleIndicesOut.m_data = 0i64;
        triangleIndicesOut.m_capacityAndFlags = 0x80000000;
        partitionSegments.m_size = 0;
        if ( partitionSegments.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            partitionSegments.m_data,
            4 * partitionSegments.m_capacityAndFlags);
        partitionSegments.m_data = 0i64;
        partitionSegments.m_capacityAndFlags = 0x80000000;
        v145.m_userVertices.m_size = 0;
        if ( v145.m_userVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v145.m_userVertices.m_data,
            16 * v145.m_userVertices.m_capacityAndFlags);
        v145.m_userVertices.m_data = 0i64;
        v145.m_userVertices.m_capacityAndFlags = 0x80000000;
        v133 = 0;
        if ( v134 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
        v134 = 0x80000000;
        v116 = v166;
        v117 = 5;
        array = 0i64;
        do
        {
          v116 -= 3312;
          *(_QWORD *)(v116 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v116 - 92),
            1);
          v118 = *(_DWORD *)v116;
          *((_DWORD *)v116 - 1) = 0;
          if ( v118 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v116 - 12),
              16 * v118);
          *(_QWORD *)(v116 - 12) = 0i64;
          *(_DWORD *)v116 = 0x80000000;
          *(_QWORD *)(v116 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> > *)(v116 - 36));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v116 - 36));
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)(v116 - 60));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v116 - 60));
          --v117;
          *(_QWORD *)(v116 - 76) = &hkBaseObject::`vftable;
          *(_QWORD *)(v116 - 92) = &hkBaseObject::`vftable;
        }
        while ( v117 >= 0 );
        return result;
      }
      v72 = triangleIndicesOut.m_data;
      v73 = dmin.m_quad.m128_u64[0];
      v138.m_enum = navMeshOut->m_edges.m_size;
      v74 = hkaiNavMesh::expandEdgesBy(navMeshOut, 3 * v69, -1);
      v75 = v74;
      if ( v69 && !v74 )
      {
        result->m_enum = HK_FAILURE;
        dmin.m_quad.m128_i32[2] = 0;
        if ( dmin.m_quad.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[0],
            4 * dmin.m_quad.m128_i32[3]);
        dmin.m_quad.m128_u64[0] = 0i64;
        dmin.m_quad.m128_i32[3] = 0x80000000;
        triangleIndicesOut.m_size = 0;
        if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            triangleIndicesOut.m_data,
            4 * triangleIndicesOut.m_capacityAndFlags);
        triangleIndicesOut.m_data = 0i64;
        triangleIndicesOut.m_capacityAndFlags = 0x80000000;
        partitionSegments.m_size = 0;
        if ( partitionSegments.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            partitionSegments.m_data,
            4 * partitionSegments.m_capacityAndFlags);
        partitionSegments.m_data = 0i64;
        partitionSegments.m_capacityAndFlags = 0x80000000;
        v145.m_userVertices.m_size = 0;
        if ( v145.m_userVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v145.m_userVertices.m_data,
            16 * v145.m_userVertices.m_capacityAndFlags);
        v145.m_userVertices.m_data = 0i64;
        v145.m_userVertices.m_capacityAndFlags = 0x80000000;
        v133 = 0;
        if ( v134 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
        v134 = 0x80000000;
        v119 = v166;
        v120 = 5;
        array = 0i64;
        do
        {
          v119 -= 3312;
          *(_QWORD *)(v119 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v119 - 92),
            1);
          v121 = *(_DWORD *)v119;
          *((_DWORD *)v119 - 1) = 0;
          if ( v121 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v119 - 12),
              16 * v121);
          *(_QWORD *)(v119 - 12) = 0i64;
          *(_DWORD *)v119 = 0x80000000;
          *(_QWORD *)(v119 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> > *)(v119 - 36));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v119 - 36));
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)(v119 - 60));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v119 - 60));
          --v120;
          *(_QWORD *)(v119 - 76) = &hkBaseObject::`vftable;
          *(_QWORD *)(v119 - 92) = &hkBaseObject::`vftable;
        }
        while ( v120 >= 0 );
        return result;
      }
      v76 = faceToPartitionMap;
      v77 = v69 + faceToPartitionMap->m_size;
      v78 = faceToPartitionMap->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v78 >= v77 )
      {
        v144.m_enum = HK_SUCCESS;
      }
      else
      {
        v79 = 2 * v78;
        if ( v77 < v79 )
          v77 = v79;
        hkArrayUtil::_reserve(&v144, &hkContainerHeapAllocator::s_alloc, faceToPartitionMap, v77, 4);
        if ( v144.m_enum )
        {
          result->m_enum = HK_FAILURE;
          dmin.m_quad.m128_i32[2] = 0;
          if ( dmin.m_quad.m128_i32[3] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              (void *)dmin.m_quad.m128_u64[0],
              4 * dmin.m_quad.m128_i32[3]);
          dmin.m_quad.m128_u64[0] = 0i64;
          dmin.m_quad.m128_i32[3] = 0x80000000;
          triangleIndicesOut.m_size = 0;
          if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              triangleIndicesOut.m_data,
              4 * triangleIndicesOut.m_capacityAndFlags);
          triangleIndicesOut.m_data = 0i64;
          triangleIndicesOut.m_capacityAndFlags = 0x80000000;
          partitionSegments.m_size = 0;
          if ( partitionSegments.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              partitionSegments.m_data,
              4 * partitionSegments.m_capacityAndFlags);
          partitionSegments.m_data = 0i64;
          partitionSegments.m_capacityAndFlags = 0x80000000;
          v145.m_userVertices.m_size = 0;
          if ( v145.m_userVertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v145.m_userVertices.m_data,
              16 * v145.m_userVertices.m_capacityAndFlags);
          v145.m_userVertices.m_data = 0i64;
          v145.m_userVertices.m_capacityAndFlags = 0x80000000;
          v133 = 0;
          if ( v134 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
          v134 = 0x80000000;
          v122 = v166;
          v123 = 5;
          array = 0i64;
          do
          {
            v122 -= 3312;
            *(_QWORD *)(v122 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v122 - 92),
              1);
            v124 = *(_DWORD *)v122;
            *((_DWORD *)v122 - 1) = 0;
            if ( v124 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v122 - 12),
                16 * v124);
            *(_QWORD *)(v122 - 12) = 0i64;
            *(_DWORD *)v122 = 0x80000000;
            *(_QWORD *)(v122 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> > *)(v122 - 36));
            hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v122 - 36));
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)(v122 - 60));
            hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v122 - 60));
            --v123;
            *(_QWORD *)(v122 - 76) = &hkBaseObject::`vftable;
            *(_QWORD *)(v122 - 92) = &hkBaseObject::`vftable;
          }
          while ( v123 >= 0 );
          return result;
        }
        v76 = faceToPartitionMap;
      }
      v80 = v76->m_size;
      v81 = v68;
      v158 = v68;
      v76->m_size = v80 + v69;
      m_enum = v138.m_enum;
      v150 = &v76->m_data[v80];
      v83 = v138.m_enum;
      v152 = v69;
      if ( v69 > 0 )
      {
        p_m_numUserEdges = &v71->m_numUserEdges;
        v85 = 0i64;
        do
        {
          *(_DWORD *)(p_m_numUserEdges - 1) = 3;
          *(_DWORD *)(p_m_numUserEdges - 5) = m_enum;
          *(_DWORD *)(p_m_numUserEdges - 3) = -1;
          p_m_numUserEdges[1] = -1;
          p_m_numUserEdges[2] = -12851;
          m_faceDataStriding = navMeshOut->m_faceDataStriding;
          v87 = 3i64;
          if ( (_DWORD)m_faceDataStriding )
            navMeshOut->m_faceData.m_data[m_faceDataStriding * (v85 + v81)] = faceData->m_data[partitions->m_data[v139]];
          v88 = 2i64;
          v89 = 0i64;
          v90 = 40i64;
          v91 = 0i64;
          do
          {
            *(int *)((char *)&v75->m_a + v90) = v72[v88];
            *(int *)((char *)&v75->m_b + v90) = v72[v89];
            *(_QWORD *)((char *)&v75->m_oppositeEdge + v90) = -1i64;
            *(_DWORD *)(&v75->m_flags.m_storage + v90) = 4;
            m_edgeDataStriding = navMeshOut->m_edgeDataStriding;
            if ( (_DWORD)m_edgeDataStriding )
              navMeshOut->m_edgeData.m_data[m_edgeDataStriding * (v88 + v83)] = *(_DWORD *)(v73 + 4 * v88);
            v88 = v89;
            v90 = v91;
            ++v89;
            v91 += 20i64;
            --v87;
          }
          while ( v87 );
          v93 = v150;
          v81 = v158;
          *v150 = v140;
          ++v85;
          v150 = v93 + 1;
          v72 += 3;
          m_enum = v138.m_enum + 3;
          v73 += 12i64;
          v75 += 3;
          v83 += 3i64;
          p_m_numUserEdges += 8;
          v138.m_enum += 3;
        }
        while ( v85 < v152 );
        v67 = v147;
      }
      v94 = v149;
      v95 = numFacesInPartition->m_data;
      dmax.m_quad.m128_i32[2] = 0;
      v139 += v95[v149];
      if ( v67 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          (void *)dmax.m_quad.m128_u64[0],
          4 * v67);
      dmax.m_quad.m128_u64[0] = 0i64;
      dmax.m_quad.m128_i32[3] = 0x80000000;
      dmin.m_quad.m128_i32[2] = 0;
      if ( dmin.m_quad.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)dmin.m_quad.m128_u64[0],
          4 * dmin.m_quad.m128_i32[3]);
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_i32[3] = 0x80000000;
      triangleIndicesOut.m_size = 0;
      if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          triangleIndicesOut.m_data,
          4 * triangleIndicesOut.m_capacityAndFlags);
      triangleIndicesOut.m_data = 0i64;
      triangleIndicesOut.m_capacityAndFlags = 0x80000000;
      partitionSegments.m_size = 0;
      if ( partitionSegments.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          partitionSegments.m_data,
          4 * partitionSegments.m_capacityAndFlags);
      partitionSegments.m_data = 0i64;
      v55 = v94 + 1;
      v53 = v140 + 1;
      partitionSegments.m_capacityAndFlags = 0x80000000;
      v149 = v55;
      ++v140;
      if ( v55 >= v153 )
      {
        v26 = 5;
        goto LABEL_187;
      }
      v54 = v151;
      v25 = v142;
      v27 = segments;
      v51 = numFacesInPartition;
    }
    result->m_enum = HK_FAILURE;
    dmin.m_quad.m128_i32[2] = 0;
    if ( dmin.m_quad.m128_i32[3] >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        (void *)dmin.m_quad.m128_u64[0],
        4 * dmin.m_quad.m128_i32[3]);
    dmin.m_quad.m128_u64[0] = 0i64;
    dmin.m_quad.m128_i32[3] = 0x80000000;
    triangleIndicesOut.m_size = 0;
    if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        triangleIndicesOut.m_data,
        4 * triangleIndicesOut.m_capacityAndFlags);
    triangleIndicesOut.m_data = 0i64;
    triangleIndicesOut.m_capacityAndFlags = 0x80000000;
    partitionSegments.m_size = 0;
    if ( partitionSegments.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        partitionSegments.m_data,
        4 * partitionSegments.m_capacityAndFlags);
    partitionSegments.m_data = 0i64;
    partitionSegments.m_capacityAndFlags = 0x80000000;
    v145.m_userVertices.m_size = 0;
    if ( v145.m_userVertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v145.m_userVertices.m_data,
        16 * v145.m_userVertices.m_capacityAndFlags);
    v145.m_userVertices.m_data = 0i64;
    v145.m_userVertices.m_capacityAndFlags = 0x80000000;
    v133 = 0;
    if ( v134 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v134);
    v134 = 0x80000000;
    v129 = v166;
    v130 = 5;
    array = 0i64;
    do
    {
      v129 -= 3312;
      *(_QWORD *)(v129 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v129 - 92),
        1);
      v131 = *(_DWORD *)v129;
      *((_DWORD *)v129 - 1) = 0;
      if ( v131 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v129 - 12),
          16 * v131);
      *(_QWORD *)(v129 - 12) = 0i64;
      *(_DWORD *)v129 = 0x80000000;
      *(_QWORD *)(v129 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> > *)(v129 - 36));
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v129 - 36));
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)(v129 - 60));
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v129 - 60));
      --v130;
      *(_QWORD *)(v129 - 76) = &hkBaseObject::`vftable;
      *(_QWORD *)(v129 - 92) = &hkBaseObject::`vftable;
    }
    while ( v130 >= 0 );
  }
  return result;
}

// File Line: 242
// RVA: 0xB63520
void __fastcall circumcenter2D(hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, hkVector4f *ccOut)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm7
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  hkVector4f v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm3

  v4 = _mm_sub_ps(v0->m_quad, v2->m_quad);
  v5 = _mm_sub_ps(v1->m_quad, v2->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  if ( v9.m128_f32[0] >= 0.00000011920929 )
  {
    v13 = _mm_mul_ps(v4, v4);
    v14 = _mm_mul_ps(v5, v5);
    v15 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
              v5),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170)),
              v4));
    v16 = _mm_rcp_ps(v9);
    v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v7));
    v12.m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v9)), v16),
                       (__m128)xmmword_141A711B0),
                     _mm_shuffle_ps(v17, v17, 201)),
                   v2->m_quad);
  }
  else
  {
    v10 = _mm_add_ps(v1->m_quad, v0->m_quad);
    *ccOut = (hkVector4f)v10;
    v11 = _mm_add_ps(v10, v2->m_quad);
    *ccOut = (hkVector4f)v11;
    v12.m_quad = _mm_mul_ps(v11, (__m128)xmmword_141A711C0);
  }
  *ccOut = (hkVector4f)v12.m_quad;
}

// File Line: 306
// RVA: 0xB63650
void __fastcall pickRandomPoint(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkArray<TriangleArea,hkContainerHeapAllocator> *cumulativeArea,
        float totalArea,
        hkPseudoRandomGenerator *rand,
        hkVector4f *pOut)
{
  int v6; // edx
  __int64 v9; // rcx
  signed int v10; // r11d
  __int64 m_size; // r9
  float *p_m_area; // rax
  int v13; // eax
  hkVector4f v14; // xmm3
  hkVector4f v15; // xmm4
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_triangle; // rdx
  int v17; // r11d
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  int v20; // ecx
  __m128 v21; // xmm7
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  hkVector4f v24; // xmm2
  hkVector4f v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm9
  __m128 v28; // xmm8
  __m128 v29; // xmm6
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm0

  v6 = 1;
  v9 = 1i64;
  v10 = 1664525 * rand->m_current + 1013904223;
  rand->m_current = v10;
  m_size = cumulativeArea->m_size;
  if ( m_size <= 1 )
    goto LABEL_7;
  p_m_area = &cumulativeArea->m_data[1].m_area;
  while ( (float)((float)((float)v10 * 2.3283064e-10) * totalArea) > *p_m_area )
  {
    ++v9;
    ++v6;
    p_m_area += 4;
    if ( v9 >= m_size )
      goto LABEL_7;
  }
  v13 = v6 - 1;
  if ( !v6 )
LABEL_7:
    v13 = m_size - 1;
  v14.m_quad = (__m128)triangulator->m_localToWorld.m_col1;
  v15.m_quad = (__m128)triangulator->m_localToWorld.m_col2;
  m_triangle = cumulativeArea->m_data[v13].m_triangle;
  v17 = 1664525 * v10;
  v18 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&m_triangle->m_vertices[0]->m_x));
  v19 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&m_triangle->m_vertices[1]->m_x));
  v20 = 1664525 * (v17 + 1013904223);
  v21 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&m_triangle->m_vertices[2]->m_x));
  v22 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, (__m128)0i64), 180), 4),
                  4);
  v23 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)0i64), 180), 4),
                  4);
  v24.m_quad = (__m128)triangulator->m_localToWorld.m_col3;
  v25.m_quad = (__m128)triangulator->m_localToWorld.m_col0;
  v26 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, (__m128)0i64), 180), 4),
                  4);
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v25.m_quad), v24.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v14.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v15.m_quad));
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v25.m_quad), v24.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v14.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v15.m_quad));
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v25.m_quad), v24.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v14.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v15.m_quad));
  rand->m_current = v20 + 1013904223;
  v30 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(v17 + 1013904223) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(v17 + 1013904223) * 2.3283064e-10),
          0);
  v31 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(v20 + 1013904223) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(v20 + 1013904223) * 2.3283064e-10),
          0);
  v32 = _mm_cmplt_ps(query.m_quad, _mm_add_ps(v31, v30));
  v33 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(query.m_quad, v30), v32), _mm_andnot_ps(v32, v30));
  v34 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(query.m_quad, v31), v32), _mm_andnot_ps(v32, v31));
  pOut->m_quad = _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps(query.m_quad, v33), v34), v27), _mm_mul_ps(v28, v33)),
                   _mm_mul_ps(v29, v34));
}

// File Line: 330
// RVA: 0xB638C0
hkResult *__fastcall pickRandomSeeding(
        hkResult *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *evs,
        int numActiveTriangles,
        hkArray<hkVector4f,hkContainerHeapAllocator> *steinerPoints)
{
  int m_numUsed; // r9d
  int m_capacityAndFlags; // r8d
  float v9; // xmm11_4
  int m_size; // r10d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *i; // rbx
  TriangleArea *v14; // rax
  hkVector4f v15; // xmm5
  hkVector4f v16; // xmm6
  hkVector4f v17; // xmm7
  hkVector4f v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm9
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __int64 v34; // rsi
  float v35; // xmm0_4
  hkArray<hkVector4f,hkContainerHeapAllocator> *v36; // rbx
  int v37; // eax
  int v38; // eax
  int v39; // r9d
  hkResult v41; // [rsp+30h] [rbp-61h] BYREF
  hkPseudoRandomGenerator rand; // [rsp+38h] [rbp-59h] BYREF
  hkArray<TriangleArea,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-51h] BYREF
  hkVector4f pOut; // [rsp+50h] [rbp-41h] BYREF
  hkResult resulta; // [rsp+F8h] [rbp+67h] BYREF

  m_numUsed = triangulator->m_mesh.m_triangles.m_numUsed;
  m_capacityAndFlags = 0x80000000;
  v9 = 0.0;
  array.m_data = 0i64;
  m_size = 0;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( m_numUsed <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, m_numUsed, 16);
    m_capacityAndFlags = array.m_capacityAndFlags;
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      array.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          16 * m_capacityAndFlags);
      return result;
    }
    m_size = array.m_size;
  }
  for ( i = triangulator->m_mesh.m_triangles.m_used; i; i = i->m_next )
  {
    if ( (*((_BYTE *)i + 184) & 0x20) != 0 )
    {
      if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
        m_size = array.m_size;
      }
      v14 = &array.m_data[m_size];
      array.m_size = m_size + 1;
      v14->m_triangle = i;
      v14->m_area = v9;
      v15.m_quad = (__m128)triangulator->m_localToWorld.m_col0;
      v16.m_quad = (__m128)triangulator->m_localToWorld.m_col3;
      v17.m_quad = (__m128)triangulator->m_localToWorld.m_col1;
      v18.m_quad = (__m128)triangulator->m_localToWorld.m_col2;
      v19 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[0]->m_x));
      v20 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)0i64), 180), 4),
                      4);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v15.m_quad), v16.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v17.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v18.m_quad));
      v22 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[1]->m_x));
      v23 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)0i64), 180), 4),
                      4);
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15.m_quad), v16.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v17.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v18.m_quad));
      v25 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[2]->m_x));
      v26 = _mm_sub_ps(v24, v21);
      v27 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, (__m128)0i64), 180), 4),
                      4);
      v28 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v15.m_quad), v16.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v17.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v18.m_quad)),
              v21);
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v28));
      v30 = _mm_shuffle_ps(v29, v29, 201);
      v31 = _mm_mul_ps(v30, v30);
      m_capacityAndFlags = array.m_capacityAndFlags;
      m_size = array.m_size;
      v32 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170));
      v33 = _mm_rsqrt_ps(v32);
      v9 = v9
         + (float)(_mm_andnot_ps(
                     _mm_cmple_ps(v32, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                         _mm_mul_ps(*(__m128 *)_xmm, v33)),
                       v32)).m128_f32[0]
                 * 0.5);
    }
  }
  if ( !m_size || v9 < evs->m_minPartitionArea && evs->m_vertexSelectionMethod.m_storage )
    goto LABEL_32;
  if ( !evs->m_vertexSelectionMethod.m_storage )
  {
    v35 = v9 * evs->m_areaFraction;
    goto LABEL_21;
  }
  if ( evs->m_vertexSelectionMethod.m_storage == 1 )
  {
    v35 = (float)numActiveTriangles * evs->m_vertexFraction;
LABEL_21:
    LODWORD(v34) = (int)v35;
    goto LABEL_22;
  }
  LODWORD(v34) = 0;
LABEL_22:
  v36 = steinerPoints;
  rand.m_seed = m_size;
  rand.m_current = m_size;
  v37 = steinerPoints->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v37 >= (int)v34 )
  {
    v41.m_enum = HK_SUCCESS;
  }
  else
  {
    v38 = 2 * v37;
    v39 = v34;
    if ( (int)v34 < v38 )
      v39 = v38;
    hkArrayUtil::_reserve(&v41, &hkContainerHeapAllocator::s_alloc, steinerPoints, v39, 16);
    m_capacityAndFlags = array.m_capacityAndFlags;
    if ( v41.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_33;
    }
  }
  if ( (int)v34 > 0 )
  {
    v34 = (unsigned int)v34;
    do
    {
      pickRandomPoint(triangulator, &array, v9, &rand, &pOut);
      v36->m_data[v36->m_size++] = (hkVector4f)pOut.m_quad;
      --v34;
    }
    while ( v34 );
    m_capacityAndFlags = array.m_capacityAndFlags;
  }
LABEL_32:
  result->m_enum = HK_SUCCESS;
LABEL_33:
  array.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * m_capacityAndFlags);
  return result;
}

// File Line: 407
// RVA: 0xB63D10
bool __fastcall getVertexHeight(
        hkaiNavMeshUtils *originalMesh,
        hkArray<int const ,hkContainerHeapAllocator> *facesInPartition,
        hkVector4f *up,
        hkArrayBase<hkVector4f> *verticesOut,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *va,
        hkVector4f *vertexInOut)
{
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  hkVector4f v15; // xmm14
  __m128 v16; // xmm13
  __m128i v17; // xmm13
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  int v20; // ebx
  __int64 v21; // rdi
  __m128 m_quad; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm9
  __m128 v25; // xmm12
  __m128 v26; // xmm10
  __m128 v27; // xmm11
  __m128 v28; // xmm8
  __m128 v29; // xmm8
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm6
  __m128 v36; // xmm7
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm9
  __m128 v44; // xmm7
  __m128 v45; // xmm7
  __m128 v46; // xmm9
  __m128 v47; // xmm0
  __m128 v48; // xmm3
  bool result; // al
  hkcdRay ray; // [rsp+20h] [rbp-108h] BYREF
  __m128 v51; // [rsp+50h] [rbp-D8h]
  __m128 v52; // [rsp+60h] [rbp-C8h]

  v10 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  v11 = _mm_mul_ps(_mm_add_ps(*(__m128 *)&originalMesh[144], v10), up->m_quad);
  v12 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)&originalMesh[128], v10), up->m_quad);
  v13 = _mm_mul_ps(vertexInOut->m_quad, up->m_quad);
  v14 = _mm_sub_ps(
          vertexInOut->m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            up->m_quad));
  v15.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                     _mm_shuffle_ps(v11, v11, 170)),
                   up->m_quad),
                 v14);
  v16 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170)),
            up->m_quad),
          v14);
  ray.m_invDirection = (hkVector4f)v15.m_quad;
  v17 = (__m128i)_mm_sub_ps(v16, v15.m_quad);
  v18 = _mm_rcp_ps((__m128)v17);
  v19 = _mm_cmpeq_ps((__m128)v17, (__m128)0i64);
  v51 = _mm_shuffle_ps((__m128)v17, _mm_unpackhi_ps((__m128)v17, query.m_quad), 196);
  v52 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu), (__m128)_xmm), v19),
          _mm_andnot_ps(v19, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v17, v18)), v18)));
  v20 = 0;
  v52.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v51)) & 7 | 0x3F000000;
  if ( facesInPartition->m_size <= 0 )
  {
LABEL_5:
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
      triangulator,
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location *)&ray,
      va->m_x,
      va->m_y);
    if ( ray.m_origin.m_quad.m128_u64[1] && (*(_BYTE *)(ray.m_origin.m_quad.m128_u64[1] + 184) & 0x20) != 0 )
    {
      m_quad = verticesOut->m_data[(int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 16) + 24i64) >> 2)].m_quad;
      v23 = _mm_sub_ps(ray.m_invDirection.m_quad, m_quad);
      v24 = _mm_sub_ps(
              verticesOut->m_data[(int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 24) + 24i64) >> 2)].m_quad,
              m_quad);
      v25 = _mm_shuffle_ps(v24, v24, 201);
      v26 = _mm_sub_ps(
              verticesOut->m_data[(int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 32) + 24i64) >> 2)].m_quad,
              m_quad);
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_sub_ps(_mm_mul_ps(v24, v27), _mm_mul_ps(v26, v25));
      v29 = _mm_shuffle_ps(v28, v28, 201);
      v30 = _mm_mul_ps(v51, v29);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      if ( (float)(v31.m128_f32[0] * v31.m128_f32[0]) < 0.00000011920929 )
        return 0;
      v32 = _mm_mul_ps(v29, v23);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_rcp_ps(v31);
      v35 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v31)), v34), _mm_sub_ps((__m128)0i64, v33));
      if ( !_mm_movemask_ps(_mm_mul_ps(v33, v31)) )
        return 0;
      if ( v35.m128_f32[0] >= _mm_shuffle_ps(v51, v51, 255).m128_f32[0] )
        return 0;
      v36 = _mm_add_ps(_mm_mul_ps(v51, v35), v23);
      v37 = _mm_sub_ps(v26, v36);
      v38 = _mm_sub_ps(v24, v36);
      v39 = _mm_mul_ps(v29, v29);
      v40 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v38), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v37));
      v41 = _mm_shuffle_ps(v36, v36, 201);
      v42 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v29);
      v43 = _mm_sub_ps(_mm_mul_ps(v24, v41), _mm_mul_ps(v36, v25));
      v44 = _mm_sub_ps(_mm_mul_ps(v36, v27), _mm_mul_ps(v26, v41));
      v45 = _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v29);
      v46 = _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v29);
      v47 = _mm_unpacklo_ps(v42, v46);
      v48 = _mm_movelh_ps(v47, v45);
      if ( (_mm_movemask_ps(
              _mm_cmple_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                    _mm_shuffle_ps(v39, v39, 170)),
                  (__m128)_xmm_b951b717b951b717b951b717b951b717),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v42, v46), v45, 228),
                  _mm_add_ps(v48, _mm_shuffle_ps(_mm_movehl_ps(v48, v47), v45, 212))))) & 7) == 7 )
      {
        result = 1;
        vertexInOut->m_quad = _mm_add_ps(_mm_mul_ps(v35, (__m128)v17), v15.m_quad);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v21 = 0i64;
    while ( !hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
               originalMesh,
               (hkaiNavMesh *)(unsigned int)facesInPartition->m_data[v21],
               (int)&ray.m_invDirection,
               &ray,
               (hkSimdFloat32 *)ray.m_origin.m_quad.m128_u64[0]) )
    {
      ++v20;
      ++v21;
      if ( v20 >= facesInPartition->m_size )
        goto LABEL_5;
    }
    result = 1;
    vertexInOut->m_quad = _mm_add_ps(_mm_mul_ps(ray.m_origin.m_quad, (__m128)v17), v15.m_quad);
  }
  return result;
}on->m_size )
        goto LABEL_5;
    }
    result = 1;
    vertexInOut->m_quad = _mm_add_ps(_mm_mul_ps(ray.m_origin.m_quad, (__m128)v17), v15.m_quad);
  }


// File Line: 474
// RVA: 0xB641A0
hkResult *__fastcall addUserPoints(
        hkResult *result,
        hkaiNavMeshUtils *originalMesh,
        hkArray<int const ,hkContainerHeapAllocator> *facesInPartition,
        hkAabb *partitionAabb,
        hkVector4f *up,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings,
        hkBitField *userVertexOnBoundary,
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *ec,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v11; // r13
  hkArray<int const ,hkContainerHeapAllocator> *v12; // r10
  hkaiNavMeshUtils *v13; // r11
  int v14; // r9d
  int v15; // eax
  int v17; // eax
  int v19; // ebp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v20; // r14
  __int64 v21; // r15
  hkVector4f *m_data; // rdx
  int m_margin; // edi
  int v24; // eax
  __m128 m_quad; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128i v29; // xmm1
  int v30; // esi
  int v31; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v32; // rdx
  hkVector4f vertexInOut; // [rsp+40h] [rbp-88h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v34; // [rsp+50h] [rbp-78h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex va; // [rsp+68h] [rbp-60h] BYREF
  hkAabb *resulta; // [rsp+E8h] [rbp+20h] BYREF

  resulta = partitionAabb;
  v10 = verticesOut;
  v11 = extraVertexSettings;
  v12 = facesInPartition;
  v13 = originalMesh;
  v14 = extraVertexSettings->m_userVertices.m_size + verticesOut->m_size;
  v15 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 >= v14 )
  {
    LODWORD(resulta) = 0;
  }
  else
  {
    v17 = 2 * v15;
    if ( v14 < v17 )
      v14 = v17;
    hkArrayUtil::_reserve((hkResult *)&resulta, &hkContainerHeapAllocator::s_alloc, verticesOut, v14, 16);
    if ( (_DWORD)resulta )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
    v12 = facesInPartition;
    v13 = originalMesh;
  }
  v19 = 0;
  if ( v11->m_userVertices.m_size > 0 )
  {
    v20 = triangulator;
    v21 = 0i64;
    while ( 1 )
    {
      if ( ((userVertexOnBoundary->m_storage.m_words.m_data[(__int64)v19 >> 5] >> (v19 & 0x1F)) & 1) == 0 )
      {
        m_data = v11->m_userVertices.m_data;
        m_margin = v20->m_margin;
        v24 = 0x7FFFFF - m_margin;
        m_quad = m_data[v21].m_quad;
        v26 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v20->m_worldToLocal.m_col0.m_quad),
                    v20->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v20->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v20->m_worldToLocal.m_col2.m_quad));
        v27 = _mm_cmplt_ps(v26, (__m128)0i64);
        v28 = _mm_or_ps(
                _mm_andnot_ps(v27, _mm_add_ps(v26, (__m128)xmmword_141A711B0)),
                _mm_and_ps(_mm_sub_ps(v26, (__m128)xmmword_141A711B0), v27));
        v29 = _mm_xor_si128(
                (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v28),
                _mm_cvttps_epi32(v28));
        v30 = _mm_cvtsi128_si32(v29);
        if ( v30 >= m_margin )
        {
          if ( v30 > v24 )
            v30 = 0x7FFFFF - m_margin;
        }
        else
        {
          v30 = v20->m_margin;
        }
        va.m_x = v30;
        v31 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v29, 85));
        if ( v31 >= m_margin )
        {
          m_margin = v31;
          if ( v31 > v24 )
            m_margin = v24;
        }
        vertexInOut.m_quad = (__m128)m_data[v21];
        va.m_y = m_margin;
        if ( getVertexHeight(v13, v12, up, v10, v20, &va, &vertexInOut) )
        {
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
            v20,
            &v34,
            v30,
            m_margin,
            1,
            ec);
          if ( v34.m_type.m_storage == 10 || v20->m_status.m_storage )
          {
            result->m_enum = HK_FAILURE;
            return result;
          }
          if ( !v34.m_type.m_storage )
          {
            v32 = v34.m_edge.m_triangle->m_vertices[v34.m_edge.m_index];
            *((_QWORD *)v32 + 3) = *((_DWORD *)v32 + 6) & 3 | (unsigned __int64)(4i64 * v10->m_size);
            if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v10, 16);
            v10->m_data[v10->m_size++] = (hkVector4f)vertexInOut.m_quad;
          }
        }
      }
      ++v19;
      ++v21;
      if ( v19 >= v11->m_userVertices.m_size )
        break;
      v12 = facesInPartition;
      v13 = originalMesh;
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 529
// RVA: 0xB644C0
hkaiNavMeshSimplificationUtils::ExtraVertexSettings *__fastcall laplacianSmooth(
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *result,
        hkaiNavMesh *originalMesh,
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *facesInPartition,
        hkArrayBase<hkVector4f> *up,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings,
        int numActiveTriangles,
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *ec,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v9; // r14
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v10; // rdi
  int v11; // r15d
  __m128 v12; // xmm7
  int v14; // r9d
  int v15; // eax
  int v16; // eax
  int m_capacityAndFlags; // r8d
  signed int m_index; // r12d
  __int64 v19; // r9
  int v20; // eax
  bool v21; // dl
  int m_size; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *p_other; // r14
  __int64 v24; // r12
  int m_margin; // edi
  int v26; // eax
  __m128 m_quad; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128i v33; // xmm1
  int v34; // esi
  int v35; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v36; // rdx
  hkVector4f *m_data; // rdi
  int m_triangle; // r8d
  int v39; // edi
  int v40; // eax
  __int64 v41; // rdx
  __int64 v42; // r8
  __int64 m_used; // r10
  hkVector4f v44; // xmm3
  hkVector4f v45; // xmm4
  hkVector4f v46; // xmm5
  hkVector4f v47; // xmm6
  __int64 i; // r8
  __int64 v49; // rcx
  __int64 v50; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  __m128 v53; // xmm14
  __m128 v54; // xmm12
  __m128 v55; // xmm13
  __m128 v56; // xmm7
  __m128 v57; // xmm11
  __m128 v58; // xmm15
  __m128 v59; // xmm6
  __m128 v60; // xmm1
  __m128 v61; // xmm5
  __m128 v62; // xmm3
  __m128 v63; // xmm6
  __m128 v64; // xmm6
  __m128 v65; // xmm4
  __m128 v66; // xmm5
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  __m128 v72; // xmm4
  __m128 v73; // xmm1
  __m128 v74; // xmm8
  __m128 v75; // xmm0
  __m128 v76; // xmm3
  __m128 v77; // xmm5
  __m128 v78; // xmm1
  __m128 v79; // xmm3
  __m128 v80; // xmm2
  __m128 v81; // xmm0
  __m128 v82; // xmm6
  __m128 v83; // xmm0
  __m128 v84; // xmm6
  __m128 v85; // xmm1
  __m128 v86; // xmm5
  __m128 v87; // xmm3
  __m128 v88; // xmm0
  __m128 v89; // xmm4
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm11
  __m128 v93; // xmm1
  __m128 v94; // xmm13
  __m128 v95; // xmm14
  __m128 v96; // xmm2
  __m128 v97; // xmm3
  __m128 v98; // xmm11
  __m128 v99; // xmm2
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm10
  __int64 *v103; // rdx
  __int64 v104; // r8
  __m128 v105; // xmm1
  __m128 v106; // xmm1
  __m128 v107; // xmm1
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm4
  int v111; // ecx
  __int64 v112; // rax
  int v113; // r11d
  __int64 v114; // r10
  __m128 v115; // xmm3
  __m128 v116; // xmm2
  __int64 v117; // r8
  __int64 v118; // rdx
  hkVector4f *v119; // rcx
  __int64 v120; // rdx
  unsigned __int64 v121; // rax
  __m128 v122; // xmm1
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v124; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v125; // rdx
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v126; // rbx
  int m_triangle_high; // r8d
  bool v128; // [rsp+40h] [rbp-98h]
  hkArray<hkVector4f,hkContainerHeapAllocator> steinerPoints; // [rsp+48h] [rbp-90h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion resulta; // [rsp+58h] [rbp-80h] BYREF
  hkResult v131; // [rsp+70h] [rbp-68h] BYREF
  hkResult v132; // [rsp+74h] [rbp-64h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex va; // [rsp+78h] [rbp-60h] BYREF
  __int64 v134; // [rsp+98h] [rbp-40h] BYREF
  int v135[2]; // [rsp+A0h] [rbp-38h]
  __int64 v136; // [rsp+A8h] [rbp-30h]
  int v137; // [rsp+B0h] [rbp-28h]
  __int64 v138; // [rsp+B8h] [rbp-20h]
  int v139; // [rsp+C0h] [rbp-18h]
  hkVector4f v0; // [rsp+C8h] [rbp-10h] BYREF
  hkVector4f v1; // [rsp+D8h] [rbp+0h] BYREF
  hkVector4f v2; // [rsp+E8h] [rbp+10h] BYREF
  __m128 v143; // [rsp+F8h] [rbp+20h]
  hkVector4f ccOut; // [rsp+108h] [rbp+30h] BYREF
  hkVector4f dmax; // [rsp+118h] [rbp+40h] BYREF
  hkVector4f dmin; // [rsp+128h] [rbp+50h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> other; // [rsp+138h] [rbp+60h] BYREF
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v148; // [rsp+F18h] [rbp+E40h]
  hkaiNavMesh *originalMesha; // [rsp+F20h] [rbp+E48h]
  hkArray<int const ,hkContainerHeapAllocator> *facesInPartitiona; // [rsp+F28h] [rbp+E50h]
  hkVector4f *upa; // [rsp+F30h] [rbp+E58h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *retaddr; // [rsp+F38h] [rbp+E60h]

  v9 = result;
  v10 = result;
  v11 = 0;
  v12 = _mm_sub_ps(
          query.m_quad,
          _mm_shuffle_ps((__m128)LODWORD(result->m_iterationDamping), (__m128)LODWORD(result->m_iterationDamping), 0));
  steinerPoints.m_capacityAndFlags = 0x80000000;
  v143 = v12;
  steinerPoints.m_data = 0i64;
  steinerPoints.m_size = 0;
  pickRandomSeeding((hkResult *)&resulta.m_edge.m_index, retaddr, result, (int)originalMesh, &steinerPoints);
  if ( resulta.m_edge.m_index )
  {
    *(_DWORD *)&v10->m_vertexSelectionMethod.m_storage = 1;
LABEL_3:
    steinerPoints.m_size = 0;
    if ( steinerPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        steinerPoints.m_data,
        16 * steinerPoints.m_capacityAndFlags);
    return v10;
  }
  if ( !steinerPoints.m_size )
  {
    *(_DWORD *)&v10->m_vertexSelectionMethod.m_storage = 0;
    goto LABEL_3;
  }
  v14 = steinerPoints.m_size + up->m_size;
  v15 = up->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 >= v14 )
  {
    v131.m_enum = HK_SUCCESS;
  }
  else
  {
    v16 = 2 * v15;
    if ( v14 < v16 )
      v14 = v16;
    hkArrayUtil::_reserve(&v131, &hkContainerHeapAllocator::s_alloc, up, v14, 16);
    if ( v131.m_enum )
    {
      m_capacityAndFlags = steinerPoints.m_capacityAndFlags;
      steinerPoints.m_size = 0;
      *(_DWORD *)&v10->m_vertexSelectionMethod.m_storage = 1;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          steinerPoints.m_data,
          16 * m_capacityAndFlags);
      return v10;
    }
  }
  m_index = 0;
  resulta.m_edge.m_index = 0;
  if ( v9->m_numSmoothingIterations <= 0 )
  {
LABEL_94:
    *(_DWORD *)&v10->m_vertexSelectionMethod.m_storage = 0;
    goto LABEL_95;
  }
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  while ( 1 )
  {
    other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    memset(&other.m_mesh.m_vertices, 0, 20);
    *(_DWORD *)&other.m_memSizeAndFlags = 0x1FFFF;
    other.m_stack.m_data = other.m_stack.m_storage;
    other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    *(_DWORD *)&other.m_mesh.m_memSizeAndFlags = 0x1FFFF;
    memset(&other.m_mesh.m_triangles, 0, 20);
    other.m_stack.m_size = 0;
    other.m_stack.m_capacityAndFlags = -2147483584;
    other.m_status.m_storage = 0;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
      &other,
      &dmin,
      &dmax,
      0.0,
      1);
    v20 = v9->m_numSmoothingIterations - 1;
    v21 = m_index == v20;
    v128 = m_index == v20;
    if ( m_index != v20 )
    {
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::clone(
        retaddr,
        &v132,
        &other);
      if ( v132.m_enum == HK_SUCCESS )
      {
        v21 = v128;
        goto LABEL_21;
      }
      v10 = v148;
      other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      *(_DWORD *)&v148->m_vertexSelectionMethod.m_storage = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &other,
        1);
      other.m_stack.m_size = 0;
      if ( other.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_stack.m_data,
          16 * other.m_stack.m_capacityAndFlags);
      other.m_stack.m_data = 0i64;
      other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      other.m_stack.m_capacityAndFlags = 0x80000000;
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&other.m_mesh.m_triangles);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&other.m_mesh.m_vertices);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
      other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      other.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
LABEL_95:
      steinerPoints.m_size = 0;
      if ( steinerPoints.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          steinerPoints.m_data,
          16 * steinerPoints.m_capacityAndFlags);
      return v10;
    }
LABEL_21:
    m_size = steinerPoints.m_size;
    p_other = &other;
    if ( v21 )
      p_other = retaddr;
    if ( steinerPoints.m_size <= 0 )
      goto LABEL_44;
    v24 = 0i64;
LABEL_25:
    m_margin = p_other->m_margin;
    v26 = 0x7FFFFF - m_margin;
    m_quad = steinerPoints.m_data[v24].m_quad;
    v28 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), p_other->m_worldToLocal.m_col0.m_quad),
                p_other->m_worldToLocal.m_col3.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), p_other->m_worldToLocal.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), p_other->m_worldToLocal.m_col2.m_quad));
    v29 = _mm_sub_ps(v28, (__m128)xmmword_141A711B0);
    v30 = _mm_add_ps(v28, (__m128)xmmword_141A711B0);
    v31 = _mm_cmplt_ps(v28, (__m128)0i64);
    v32 = _mm_or_ps(_mm_andnot_ps(v31, v30), _mm_and_ps(v29, v31));
    v33 = _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v32),
            _mm_cvttps_epi32(v32));
    v34 = _mm_cvtsi128_si32(v33);
    if ( v34 >= m_margin )
    {
      if ( v34 > v26 )
        v34 = 0x7FFFFF - m_margin;
    }
    else
    {
      v34 = p_other->m_margin;
    }
    va.m_x = v34;
    v35 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v33, 85));
    if ( v35 >= m_margin )
    {
      m_margin = v35;
      if ( v35 > v26 )
        m_margin = v26;
    }
    va.m_y = m_margin;
    if ( !v21
      || getVertexHeight(
           (hkaiNavMeshUtils *)originalMesha,
           facesInPartitiona,
           upa,
           up,
           retaddr,
           &va,
           &steinerPoints.m_data[v11]) )
    {
      break;
    }
LABEL_42:
    m_size = steinerPoints.m_size;
    v21 = v128;
    ++v11;
    ++v24;
    if ( v11 < steinerPoints.m_size )
      goto LABEL_25;
    m_index = resulta.m_edge.m_index;
LABEL_44:
    v11 = 0;
    if ( !v21 )
    {
      *(_QWORD *)&resulta.m_type.m_storage = 0i64;
      m_triangle = 0;
      resulta.m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)0x8000000000000000i64;
      if ( m_size <= 0 )
      {
        *(&resulta.m_edge.m_index + 1) = 0;
      }
      else
      {
        hkArrayUtil::_reserve(
          (hkResult *)&resulta.m_edge.m_index + 1,
          &hkContainerHeapAllocator::s_alloc,
          &resulta,
          m_size,
          16);
        if ( *(&resulta.m_edge.m_index + 1) )
        {
          v126 = v148;
          m_triangle_high = HIDWORD(resulta.m_edge.m_triangle);
          LODWORD(resulta.m_edge.m_triangle) = 0;
          *(_DWORD *)&v148->m_vertexSelectionMethod.m_storage = 1;
          if ( m_triangle_high >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)&resulta.m_type.m_storage,
              16 * m_triangle_high);
          *(_QWORD *)&resulta.m_type.m_storage = 0i64;
          HIDWORD(resulta.m_edge.m_triangle) = 0x80000000;
          other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            &other,
            1);
          other.m_stack.m_size = 0;
          if ( other.m_stack.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              other.m_stack.m_data,
              16 * other.m_stack.m_capacityAndFlags);
          goto LABEL_108;
        }
        m_size = steinerPoints.m_size;
        m_triangle = (int)resulta.m_edge.m_triangle;
      }
      v39 = m_size;
      if ( (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF) >= m_size )
      {
        LODWORD(va.m_next) = 0;
      }
      else
      {
        if ( m_size < 2 * (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF) )
          m_size = 2 * (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF);
        hkArrayUtil::_reserve((hkResult *)&va, &hkContainerHeapAllocator::s_alloc, &resulta, m_size, 16);
        m_size = steinerPoints.m_size;
        m_triangle = (int)resulta.m_edge.m_triangle;
      }
      v40 = v39 - m_triangle;
      v41 = *(_QWORD *)&resulta.m_type.m_storage + 16i64 * m_triangle;
      v42 = v39 - m_triangle;
      if ( v40 > 0 )
      {
        do
        {
          v41 += 16i64;
          *(hkVector4f *)(v41 - 16) = (hkVector4f)aabbOut.m_quad;
          --v42;
        }
        while ( v42 );
        m_size = steinerPoints.m_size;
      }
      m_used = (__int64)p_other->m_mesh.m_triangles.m_used;
      LODWORD(resulta.m_edge.m_triangle) = v39;
      if ( m_used )
      {
        do
        {
          if ( (*(_BYTE *)(m_used + 184) & 0x20) != 0 )
          {
            v44.m_quad = (__m128)retaddr->m_localToWorld.m_col0;
            v45.m_quad = (__m128)retaddr->m_localToWorld.m_col3;
            v46.m_quad = (__m128)retaddr->m_localToWorld.m_col1;
            v134 = m_used;
            v135[0] = 0;
            v136 = m_used;
            v137 = 1;
            v138 = m_used;
            v139 = 2;
            v47.m_quad = (__m128)retaddr->m_localToWorld.m_col2;
            for ( i = 0i64;
                  i < 12;
                  *(__m128 *)((char *)&v138 + i * 4) = _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v44.m_quad),
                                                             v45.m_quad),
                                                           _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v46.m_quad)),
                                                         _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v47.m_quad)) )
            {
              v49 = v135[i];
              v50 = *(_QWORD *)&v135[i - 2];
              i += 4i64;
              v51 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)(*(_QWORD *)(v50 + 8 * v49 + 16) + 16i64)));
              v52 = (__m128)_mm_srli_si128(
                              _mm_slli_si128((__m128i)_mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, (__m128)0i64), 180), 4),
                              4);
            }
            circumcenter2D(&v0, &v1, &v2, &ccOut);
            va.hkgpAbstractMeshDefinitions::Vertex<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase> = (hkgpAbstractMeshDefinitions::Vertex<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase>)_mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
            v53 = _mm_sub_ps(ccOut.m_quad, v2.m_quad);
            *(__m128 *)&resulta.m_type.m_storage = _mm_shuffle_ps(
                                                     query.m_quad,
                                                     _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0),
                                                     196);
            v54 = _mm_sub_ps(v2.m_quad, v1.m_quad);
            v55 = _mm_sub_ps(ccOut.m_quad, v1.m_quad);
            v56 = _mm_sub_ps(v1.m_quad, v0.m_quad);
            v57 = _mm_sub_ps(ccOut.m_quad, v0.m_quad);
            v58 = _mm_sub_ps(v0.m_quad, v2.m_quad);
            v59 = _mm_shuffle_ps(v54, v54, 201);
            v60 = _mm_shuffle_ps(v56, v56, 201);
            v61 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v56), _mm_mul_ps(v60, v57));
            v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v54), _mm_mul_ps(v59, v55));
            v63 = _mm_sub_ps(_mm_mul_ps(v59, v56), _mm_mul_ps(v60, v54));
            v64 = _mm_shuffle_ps(v63, v63, 201);
            v65 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v58),
                    _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v53));
            v66 = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v64);
            v67 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v64);
            v68 = _mm_unpacklo_ps(v66, v67);
            v69 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v64);
            v70 = _mm_movelh_ps(v68, v69);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      (__m128)va.hkgpAbstractMeshDefinitions::Vertex<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase>,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v70, v68), v69, 212), v70),
                        _mm_shuffle_ps(_mm_unpackhi_ps(v66, v67), v69, 228)))) & 7) == 7 )
            {
              v71 = _mm_mul_ps(v64, v64);
              v72 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                      _mm_shuffle_ps(v71, v71, 170));
              v73 = _mm_mul_ps(v64, v57);
              v74 = _mm_sub_ps(
                      ccOut.m_quad,
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpeq_ps((__m128)0i64, v72),
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                              _mm_shuffle_ps(v73, v73, 170)),
                            _mm_rcp_ps(v72))),
                        v64));
            }
            else
            {
              v75 = _mm_mul_ps(v54, v54);
              v76 = _mm_mul_ps(v56, v56);
              v77 = _mm_mul_ps(v57, v56);
              v78 = _mm_unpacklo_ps(v76, v75);
              v79 = _mm_unpackhi_ps(v76, v75);
              v80 = _mm_mul_ps(v58, v58);
              v81 = _mm_movelh_ps(v78, v80);
              v82 = _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v81, v78), v80, 212), v81);
              v83 = _mm_mul_ps(v55, v54);
              v84 = _mm_add_ps(v82, _mm_shuffle_ps(v79, v80, 228));
              v85 = _mm_unpacklo_ps(v77, v83);
              v86 = _mm_unpackhi_ps(v77, v83);
              v87 = _mm_mul_ps(v53, v58);
              v88 = _mm_movelh_ps(v85, v87);
              v89 = _mm_andnot_ps(
                      _mm_cmpeq_ps(v84, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v88, v85), v87, 212), v88),
                          _mm_shuffle_ps(v86, v87, 228)),
                        _mm_rcp_ps(v84)));
              v90 = _mm_cmplt_ps(v89, *(__m128 *)&resulta.m_type.m_storage);
              v91 = _mm_max_ps(
                      (__m128)va.hkgpAbstractMeshDefinitions::Vertex<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase>,
                      _mm_or_ps(_mm_andnot_ps(v90, *(__m128 *)&resulta.m_type.m_storage), _mm_and_ps(v89, v90)));
              v92 = _mm_sub_ps(v57, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), v56));
              v93 = _mm_mul_ps(v92, v92);
              v94 = _mm_sub_ps(v55, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 85), v54));
              v95 = _mm_sub_ps(v53, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 170), v58));
              v96 = _mm_mul_ps(v94, v94);
              v97 = _mm_cmplt_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                        _mm_shuffle_ps(v93, v93, 170)),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                        _mm_shuffle_ps(v96, v96, 170)));
              v98 = _mm_or_ps(_mm_and_ps(v92, v97), _mm_andnot_ps(v97, v94));
              v99 = _mm_mul_ps(v95, v95);
              v100 = _mm_mul_ps(v98, v98);
              v101 = _mm_cmplt_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                         _mm_shuffle_ps(v100, v100, 170)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                         _mm_shuffle_ps(v99, v99, 170)));
              v74 = _mm_sub_ps(ccOut.m_quad, _mm_or_ps(_mm_and_ps(v98, v101), _mm_andnot_ps(v101, v95)));
            }
            v102 = _mm_sub_ps(v2.m_quad, v0.m_quad);
            v103 = &v134;
            v104 = 3i64;
            v105 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v102, v102, 201), v56),
                     _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v102));
            v106 = _mm_shuffle_ps(v105, v105, 201);
            v107 = _mm_mul_ps(v106, v106);
            v108 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
                     _mm_shuffle_ps(v107, v107, 170));
            v109 = _mm_rsqrt_ps(v108);
            v110 = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v108, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v109, v108), v109)),
                           _mm_mul_ps(*(__m128 *)_xmm, v109)),
                         v108)),
                     _mm_shuffle_ps(v74, _mm_unpackhi_ps(v74, query.m_quad), 196));
            do
            {
              v111 = up->m_size;
              v112 = *(_QWORD *)(*(_QWORD *)(*v103 + 8i64 * *((int *)v103 + 2) + 16) + 24i64) >> 2;
              if ( (int)v112 >= v111 )
                *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + 16i64 * ((int)v112 - v111)) = _mm_add_ps(
                                                                                                   v110,
                                                                                                   *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + 16i64 * ((int)v112 - v111)));
              v103 += 2;
              --v104;
            }
            while ( v104 );
          }
          m_used = *(_QWORD *)m_used;
        }
        while ( m_used );
        m_size = steinerPoints.m_size;
        v12 = v143;
      }
      v113 = m_size - 1;
      v114 = m_size - 1;
      if ( m_size - 1 >= 0 )
      {
        v19 = v113;
        while ( 1 )
        {
          v115 = *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + v19 * 16);
          v116 = _mm_shuffle_ps(v115, v115, 255);
          if ( v116.m128_f32[0] >= 0.00000011920929 )
            break;
          steinerPoints.m_size = --m_size;
          if ( m_size != v113 )
          {
            v117 = 2i64;
            v118 = 16i64 * m_size;
            v119 = &steinerPoints.m_data[v19];
            v120 = v118 - v19 * 16;
            do
            {
              v121 = *(unsigned __int64 *)((char *)v119->m_quad.m128_u64 + v120);
              v119 = (hkVector4f *)((char *)v119 + 8);
              v119[-1].m_quad.m128_u64[1] = v121;
              --v117;
            }
            while ( v117 );
            goto LABEL_78;
          }
LABEL_79:
          --v113;
          --v19;
          if ( --v114 < 0 )
            goto LABEL_80;
        }
        v122 = _mm_rcp_ps(v116);
        steinerPoints.m_data[v19].m_quad = _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps(
                                                 _mm_mul_ps(
                                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v116)), v122),
                                                   v115),
                                                 steinerPoints.m_data[v19].m_quad),
                                               v12),
                                             steinerPoints.m_data[v19].m_quad);
LABEL_78:
        m_size = steinerPoints.m_size;
        goto LABEL_79;
      }
LABEL_80:
      LODWORD(resulta.m_edge.m_triangle) = 0;
      if ( SHIDWORD(resulta.m_edge.m_triangle) >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)&resulta.m_type.m_storage,
          (unsigned int)(16 * HIDWORD(resulta.m_edge.m_triangle)),
          v19 * 16);
      *(_QWORD *)&resulta.m_type.m_storage = 0i64;
      HIDWORD(resulta.m_edge.m_triangle) = 0x80000000;
    }
    other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &other,
      1);
    other.m_stack.m_size = 0;
    if ( other.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        other.m_stack.m_data,
        16 * other.m_stack.m_capacityAndFlags);
    m_firstPool = other.m_mesh.m_triangles.m_allocator.m_firstPool;
    other.m_stack.m_data = 0i64;
    other.m_stack.m_capacityAndFlags = 0x80000000;
    for ( other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          other.m_mesh.m_triangles.m_allocator.m_firstPool;
          m_firstPool = other.m_mesh.m_triangles.m_allocator.m_firstPool )
    {
      v124 = m_firstPool->m_links[0];
      if ( v124 )
        v124->m_links[1] = m_firstPool->m_links[1];
      else
        other.m_mesh.m_triangles.m_allocator.m_firstPool = m_firstPool->m_links[1];
      v125 = m_firstPool->m_links[1];
      if ( v125 )
        v125->m_links[0] = m_firstPool->m_links[0];
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_firstPool, 6688);
    }
    other.m_mesh.m_triangles.m_used = 0i64;
    other.m_mesh.m_triangles.m_numUsed = 0;
    hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
    hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&other.m_mesh.m_vertices);
    hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
    v9 = result;
    resulta.m_edge.m_index = ++m_index;
    if ( m_index >= result->m_numSmoothingIterations )
    {
      v10 = v148;
      goto LABEL_94;
    }
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
    p_other,
    &resulta,
    v34,
    m_margin,
    1,
    facesInPartition);
  if ( resulta.m_type.m_storage != 10 && !p_other->m_status.m_storage )
  {
    if ( !resulta.m_type.m_storage )
    {
      v36 = resulta.m_edge.m_triangle->m_vertices[resulta.m_edge.m_index];
      if ( v128 )
      {
        *((_QWORD *)v36 + 3) = *((_DWORD *)v36 + 6) & 3 | (unsigned __int64)(4i64 * up->m_size);
        m_data = steinerPoints.m_data;
        if ( up->m_size == (up->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, up, 16);
        up->m_data[up->m_size++] = m_data[v24];
      }
      else
      {
        *((_QWORD *)v36 + 3) = *((_DWORD *)v36 + 6) & 3 | (unsigned __int64)(4i64 * (v11 + up->m_size));
      }
    }
    goto LABEL_42;
  }
  v126 = v148;
  *(_DWORD *)&v148->m_vertexSelectionMethod.m_storage = 1;
  other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    &other,
    1);
  other.m_stack.m_size = 0;
  if ( other.m_stack.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other.m_stack.m_data,
      16 * other.m_stack.m_capacityAndFlags);
LABEL_108:
  other.m_stack.m_data = 0i64;
  other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
  other.m_stack.m_capacityAndFlags = 0x80000000;
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&other.m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&other.m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
  steinerPoints.m_size = 0;
  other.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  if ( steinerPoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      steinerPoints.m_data,
      16 * steinerPoints.m_capacityAndFlags);
  return v126;
}rn v126;
}

// File Line: 702
// RVA: 0xB697D0
bool __fastcall compareVectorW(hkVector4f *vA, hkVector4f *vB)
{
  return _mm_shuffle_ps(vA->m_quad, vA->m_quad, 255).m128_f32[0] < _mm_shuffle_ps(vB->m_quad, vB->m_quad, 255).m128_f32[0];
}

// File Line: 707
// RVA: 0xB62F50
hkResult *__fastcall hkaiNavMeshSimplificationUtils::getEdgeSplitting(
        hkResult *result,
        hkVector4f *vIn0,
        hkVector4f *vIn1,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings,
        bool isBoundary,
        hkBitField *userVertexOnBoundary,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeVertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  int v9; // r9d
  int v11; // eax
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  int v14; // eax
  int v15; // r10d
  int v16; // r9d
  float v17; // xmm8_4
  float v18; // xmm8_4
  hkBitField *v19; // rsi
  __m128 m_quad; // xmm7
  __int64 v21; // r11
  __int64 v22; // r8
  hkVector4f *m_data; // rax
  __m128 v24; // xmm4
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm6
  __m128 v37; // xmm6
  float v38; // xmm0_4
  int m_size; // eax
  bool v40; // cl
  int v41; // edx
  hkBool *p_m_addVerticesOnBoundaryEdges; // rax
  char v43; // r15
  __m128 v44; // xmm0
  __m128 v45; // xmm10
  __int64 v46; // rbp
  __int64 v47; // rsi
  __m128 v48; // xmm6
  __m128 v49; // xmm8
  __m128 v50; // xmm1
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  float v54; // xmm4_4
  float v55; // xmm1_4
  int v56; // eax
  __m128 v57; // xmm8
  int v58; // edi
  int v59; // r9d
  int v60; // eax
  hkResultEnum m_enum; // eax
  __m128 v62; // xmm1
  __m128 v63; // xmm1
  __m128 v64; // xmm0
  __m128 v65; // xmm7
  __m128 v66; // xmm7
  __int64 v67; // rcx
  hkResult resulta; // [rsp+D8h] [rbp+10h] BYREF

  v7 = edgeVertices;
  v9 = extraVertexSettings->m_userVertices.m_size + 2;
  v11 = edgeVertices->m_capacityAndFlags & 0x3FFFFFFF;
  v12 = _mm_shuffle_ps(vIn0->m_quad, _mm_unpackhi_ps(vIn0->m_quad, (__m128)0i64), 196);
  v13 = _mm_shuffle_ps(vIn1->m_quad, _mm_unpackhi_ps(vIn1->m_quad, query.m_quad), 196);
  if ( v11 >= v9 )
  {
    LODWORD(edgeVertices) = 0;
  }
  else
  {
    v14 = 2 * v11;
    if ( v9 < v14 )
      v9 = v14;
    hkArrayUtil::_reserve((hkResult *)&edgeVertices, &hkContainerHeapAllocator::s_alloc, edgeVertices, v9, 16);
    if ( (_DWORD)edgeVertices )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  v7->m_data[v7->m_size++].m_quad = v12;
  if ( extraVertexSettings->m_userVertices.m_size > 0 )
  {
    v15 = 0;
    v16 = 1;
    v17 = _mm_shuffle_ps(
            (__m128)LODWORD(extraVertexSettings->m_userVertexOnBoundaryTolerance),
            (__m128)LODWORD(extraVertexSettings->m_userVertexOnBoundaryTolerance),
            0).m128_f32[0];
    v18 = v17 * v17;
    v19 = userVertexOnBoundary;
    m_quad = query.m_quad;
    v21 = 0i64;
    do
    {
      v22 = (__int64)v15 >> 5;
      if ( ((v19->m_storage.m_words.m_data[v22] >> (v15 & 0x1F)) & 1) == 0 )
      {
        m_data = extraVertexSettings->m_userVertices.m_data;
        v24 = _mm_sub_ps(v12, v13);
        v25 = _mm_sub_ps(v12, m_data[v21].m_quad);
        v26 = _mm_mul_ps(v24, v24);
        v27 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170));
        v28 = _mm_mul_ps(v25, v24);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rcp_ps(v27);
        v31 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, v27)), v30), v29);
        v32 = _mm_cmplt_ps(v31, m_quad);
        v33 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v32, m_quad), _mm_and_ps(v31, v32)));
        v34 = _mm_sub_ps(v25, _mm_mul_ps(v33, v24));
        v35 = _mm_mul_ps(v34, v34);
        v36 = _mm_add_ps(v34, m_data[v21].m_quad);
        v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v33), 196);
        if ( (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                   + _mm_shuffle_ps(v35, v35, 170).m128_f32[0]) < v18 )
        {
          v38 = _mm_shuffle_ps(v37, v37, 255).m128_f32[0];
          if ( v38 > 0.0 && v38 < m_quad.m128_f32[0] )
          {
            v7->m_data[v7->m_size++].m_quad = v37;
            v19->m_storage.m_words.m_data[v22] |= v16;
            m_quad = query.m_quad;
          }
        }
      }
      v16 = __ROL4__(v16, 1);
      ++v15;
      ++v21;
    }
    while ( v15 < extraVertexSettings->m_userVertices.m_size );
    m_size = v7->m_size;
    if ( m_size > 2 && m_size - 1 > 1 )
      hkAlgorithm::quickSortRecursive<hkVector4f,bool (*)(hkVector4f const &,hkVector4f const &)>(
        v7->m_data + 1,
        0,
        m_size - 2,
        compareVectorW);
  }
  v40 = isBoundary;
  v7->m_data[v7->m_size++].m_quad = v13;
  v41 = v7->m_size;
  p_m_addVerticesOnBoundaryEdges = &extraVertexSettings->m_addVerticesOnBoundaryEdges;
  if ( !v40 )
    p_m_addVerticesOnBoundaryEdges = &extraVertexSettings->m_addVerticesOnPartitionBorders;
  if ( p_m_addVerticesOnBoundaryEdges->m_bool )
  {
    v43 = 0;
    v44 = (__m128)(v40
                 ? LODWORD(extraVertexSettings->m_boundaryEdgeSplitLength)
                 : LODWORD(extraVertexSettings->m_partitionBordersSplitLength));
    v45 = _mm_shuffle_ps(v44, v44, 0);
    v46 = v41 - 1;
    if ( v41 - 1 > 0 )
    {
      v47 = v41 - 1;
      do
      {
        v48 = v7->m_data[v47].m_quad;
        v49 = v7->m_data[v47 - 1].m_quad;
        v50 = _mm_sub_ps(v48, v49);
        v51 = _mm_mul_ps(v50, v50);
        v52 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170));
        v53 = _mm_rsqrt_ps(v52);
        v54 = _mm_andnot_ps(
                _mm_cmple_ps(v52, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v53, v52), v53)),
                    _mm_mul_ps(v53, *(__m128 *)_xmm)),
                  v52)).m128_f32[0];
        if ( v54 > v45.m128_f32[0] )
        {
          v55 = _mm_rcp_ps(v45).m128_f32[0];
          v56 = v7->m_capacityAndFlags & 0x3FFFFFFF;
          v57 = _mm_sub_ps(v49, v48);
          v43 = 1;
          v58 = (int)(float)((float)((float)(2.0 - (float)(v45.m128_f32[0] * v55)) * v55) * v54);
          v59 = v58 + v7->m_size;
          if ( v56 >= v59 )
          {
            m_enum = HK_SUCCESS;
            resulta.m_enum = HK_SUCCESS;
          }
          else
          {
            v60 = 2 * v56;
            if ( v59 < v60 )
              v59 = v60;
            hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v7, v59, 16);
            m_enum = resulta.m_enum;
          }
          LODWORD(edgeVertices) = m_enum;
          if ( m_enum )
          {
            result->m_enum = HK_FAILURE;
            return result;
          }
          v62 = 0i64;
          v62.m128_f32[0] = (float)(v58 + 1);
          v63 = _mm_shuffle_ps(v62, v62, 0);
          v64 = _mm_rcp_ps(v63);
          v65 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v63, v64)), v64);
          if ( v58 > 0 )
          {
            v66 = _mm_mul_ps(v65, v57);
            v67 = (unsigned int)v58;
            do
            {
              v48 = _mm_add_ps(v48, v66);
              v7->m_data[v7->m_size++].m_quad = v48;
              --v67;
            }
            while ( v67 );
          }
        }
        --v46;
        --v47;
      }
      while ( v46 > 0 );
      if ( v43 && v7->m_size - 1 > 1 )
        hkAlgorithm::quickSortRecursive<hkVector4f,bool (*)(hkVector4f const &,hkVector4f const &)>(
          v7->m_data + 1,
          0,
          v7->m_size - 2,
          compareVectorW);
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}
          v7->m_size - 2,
          compareVectorW);
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 795
// RVA: 0xB61110
hkResult *__fastcall hkaiNavMeshSimplificationUtils::triangulatePartition(
        hkResult *result,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings,
        hkaiNavMesh *originalMesh,
        hkBitField *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        __m128 *partitionSegments,
        hkArray<int const ,hkContainerHeapAllocator> *facesInPartition,
        hkVector4f *up,
        hkArray<int,hkContainerTempAllocator> *triangleIndicesOut,
        hkArray<int,hkContainerTempAllocator> *sharedEdgesOut,
        hkBitField *edgeIsBoundary,
        hkBitField *userVertexOnBoundary,
        hkReferencedObject *globalTriangulatorPtr,
        hkAabb *globalDomainAabb)
{
  hkVector4f v14; // xmm4
  __int64 v15; // r15
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v16; // rdi
  __int64 v17; // r11
  bool v18; // bl
  hkResult *v19; // rsi
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v21; // r13
  __int64 v22; // r8
  hkVector4f v23; // xmm3
  __int64 v24; // rdx
  int *v25; // rcx
  __int64 v26; // rax
  __m128 v27; // xmm2
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v28; // r14
  __int64 v29; // r8
  int v30; // edx
  int v31; // esi
  __int64 v32; // r10
  __int64 v33; // r15
  __int64 v34; // rcx
  unsigned __int64 v35; // rdi
  __int64 v36; // rbx
  int v37; // r9d
  int v38; // r9d
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v39; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v40; // rdx
  int v41; // r8d
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v43; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v44; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v45; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v46; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *i; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v48; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v49; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v50; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v51; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v52; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v53; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v54; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *j; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v56; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v57; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v58; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v59; // rdx
  __int64 v60; // rcx
  int v61; // edx
  __int64 v62; // rbx
  __int64 v63; // rcx
  unsigned __int64 v64; // rsi
  __int64 v65; // rdi
  int v66; // eax
  int m_size; // r9d
  __int64 v68; // r8
  int v69; // r9d
  int v70; // r10d
  __int64 v71; // rax
  hkVector4f *m_data; // rcx
  __int64 v73; // r9
  __int64 v74; // rax
  __m128 m_quad; // xmm2
  __m128 v76; // xmm1
  unsigned __int64 v77; // rax
  __int64 v78; // rdx
  __m128 v79; // xmm2
  int *v80; // r9
  bool v81; // cl
  int v82; // eax
  int v83; // r8d
  __int64 v84; // r15
  int v85; // ebx
  int v86; // edi
  int v87; // esi
  hkLifoAllocator *Value; // rax
  char *m_cur; // r13
  int v90; // edx
  char *v91; // rcx
  char *v92; // rax
  int v93; // r9d
  int v94; // eax
  int v95; // r9d
  int v96; // eax
  int m_margin; // ebx
  __m128 v98; // xmm6
  int v99; // ecx
  __m128 v100; // xmm2
  __m128 v101; // xmm4
  __m128 v102; // xmm0
  __m128 v103; // xmm2
  __m128 v104; // xmm3
  __m128i v105; // xmm1
  int v106; // edi
  int v107; // eax
  int v108; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v109; // rdx
  __int64 v110; // r9
  char *v111; // rax
  int v112; // edi
  char *v113; // rbx
  int v114; // edx
  int v115; // ecx
  int v116; // r9d
  int v117; // r10d
  __int64 v118; // rax
  unsigned __int64 v119; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v120; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v121; // r8
  int m_x; // eax
  int v123; // edx
  unsigned __int64 v124; // r8
  unsigned __int64 m_triangle; // r8
  signed int v126; // ebx
  hkLifoAllocator *v127; // rax
  int v128; // r8d
  hkResultEnum v129; // eax
  unsigned int v130; // ecx
  signed int v131; // edi
  hkLifoAllocator *v132; // rax
  int v133; // r8d
  unsigned int m_slotID; // ecx
  int v135; // ebx
  hkLifoAllocator *v136; // rax
  int v137; // r8d
  unsigned int v138; // ecx
  int v139; // ebx
  hkLifoAllocator *v140; // rax
  int v141; // r8d
  int v142; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *k; // rax
  hkArray<int const ,hkContainerHeapAllocator> *v144; // rdi
  hkaiNavMesh *v145; // r15
  char v146; // cl
  unsigned __int64 m; // rsi
  __int64 v148; // rax
  unsigned __int64 v149; // r12
  __int64 v150; // rax
  unsigned __int64 v151; // r12
  __int64 v152; // r13
  __int64 v153; // r15
  int v154; // eax
  int v155; // r9d
  __int32 v156; // eax
  int v157; // eax
  int v158; // r9d
  int v159; // eax
  int v160; // eax
  hkResultEnum m_enum; // eax
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *EdgeData; // rax
  int v163; // edx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v164; // rax
  int v165; // edx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v166; // rax
  int v167; // edx
  hkResult v169[2]; // [rsp+48h] [rbp-78h] BYREF
  hkVector4f dmax; // [rsp+50h] [rbp-70h] BYREF
  hkVector4f dmin; // [rsp+60h] [rbp-60h] BYREF
  __int64 v172; // [rsp+70h] [rbp-50h]
  hkResult resulta[2]; // [rsp+78h] [rbp-48h] BYREF
  __int64 v174; // [rsp+80h] [rbp-40h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v175; // [rsp+88h] [rbp-38h] BYREF
  hkAabb partitionAabb; // [rsp+A0h] [rbp-20h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+C0h] [rbp+0h] BYREF
  __int64 v178; // [rsp+D0h] [rbp+10h]
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > icrossing; // [rsp+D8h] [rbp+18h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex v0; // [rsp+F0h] [rbp+30h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex v1; // [rsp+110h] [rbp+50h] BYREF
  hkVector4f vIn1; // [rsp+130h] [rbp+70h] BYREF
  hkVector4f vIn0; // [rsp+140h] [rbp+80h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> v184; // [rsp+150h] [rbp+90h] BYREF
  hkResult *v185; // [rsp+EC0h] [rbp+E00h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v186; // [rsp+EC8h] [rbp+E08h]
  hkaiNavMesh *originalMesha; // [rsp+ED0h] [rbp+E10h]
  __int64 v188; // [rsp+ED8h] [rbp+E18h]
  unsigned __int64 *v189; // [rsp+EE0h] [rbp+E20h]
  hkResult v190[2]; // [rsp+EE8h] [rbp+E28h] BYREF
  hkArray<int const ,hkContainerHeapAllocator> *vars0; // [rsp+EF0h] [rbp+E30h]
  hkVector4f *retaddr; // [rsp+EF8h] [rbp+E38h]

  v14.m_quad = (__m128)xmmword_141A712A0;
  v15 = *(_QWORD *)&v190[0].m_enum;
  v16 = segments;
  v17 = *(int *)(*(_QWORD *)&v190[0].m_enum + 8i64);
  partitionAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v18 = segments == 0i64;
  v19 = result;
  v21 = extraVertexSettings;
  v22 = 0i64;
  v23.m_quad = _mm_xor_ps(
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                 (__m128)xmmword_141A712A0);
  partitionAabb.m_max = (hkVector4f)v23.m_quad;
  if ( v17 > 0 )
  {
    do
    {
      if ( v18 )
        break;
      v24 = *(int *)(*v189 + 48i64 * *(int *)(**(_QWORD **)&v190[0].m_enum + 4 * v22) + 40);
      if ( v24 > 0 )
      {
        v25 = *(int **)(*v189 + 48i64 * *(int *)(**(_QWORD **)&v190[0].m_enum + 4 * v22) + 32);
        do
        {
          v26 = 2i64 * *v25++;
          v27 = *(__m128 *)&vertices->m_storage.m_words.m_data[2 * v26];
          v14.m_quad = _mm_min_ps(v14.m_quad, v27);
          v23.m_quad = _mm_max_ps(v23.m_quad, v27);
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, partitionSegments[1]), _mm_cmple_ps(*partitionSegments, v27))) & 7) != 7 )
            v18 = 1;
          --v24;
        }
        while ( v24 );
        partitionAabb.m_max = (hkVector4f)v23.m_quad;
        partitionAabb.m_min = (hkVector4f)v14.m_quad;
      }
      ++v22;
    }
    while ( v22 < v17 );
    v21 = v186;
  }
  memset(&v184.m_mesh.m_vertices, 0, 20);
  v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
  memset(&v184.m_mesh.m_triangles, 0, 20);
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
  v184.m_stack.m_size = 0;
  *(_DWORD *)&v184.m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&v184.m_mesh.m_memSizeAndFlags = 0x1FFFF;
  v184.m_stack.m_data = v184.m_stack.m_storage;
  v184.m_stack.m_capacityAndFlags = -2147483584;
  v184.m_status.m_storage = 0;
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
    &v184,
    &dmin,
    &dmax,
    0.0,
    1);
  v28 = &v184;
  if ( !v18 )
    v28 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)v16;
  if ( v18 )
  {
    v29 = 0i64;
    v30 = 0;
    dmax.m_quad.m128_u64[0] = 0i64;
    v31 = 0;
    dmax.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    if ( *(int *)(v15 + 8) > 0 )
    {
      v32 = *(_QWORD *)&v190[0].m_enum;
      v33 = 0i64;
      do
      {
        v34 = *(int *)(*(_QWORD *)v32 + v33);
        v35 = *v189;
        v36 = 6 * v34;
        v37 = v30 + *(_DWORD *)(*v189 + 48 * v34 + 40);
        if ( (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF) >= v37 )
        {
          LODWORD(segments) = 0;
        }
        else
        {
          if ( v37 < 2 * (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            v37 = 2 * (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF);
          hkArrayUtil::_reserve((hkResult *)&segments, &hkContainerTempAllocator::s_alloc, &dmax, v37, 16);
          if ( (_DWORD)segments )
          {
            v19 = v185;
            v41 = dmax.m_quad.m128_i32[3];
            dmax.m_quad.m128_i32[2] = 0;
            v185->m_enum = HK_FAILURE;
            if ( v41 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                16 * v41);
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 0x80000000;
            v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v184,
              1);
            v184.m_stack.m_size = 0;
            if ( v184.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v184.m_stack.m_data,
                16 * v184.m_stack.m_capacityAndFlags);
            m_firstPool = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
            v184.m_stack.m_data = 0i64;
            v184.m_stack.m_capacityAndFlags = 0x80000000;
            for ( v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
                  v184.m_mesh.m_triangles.m_allocator.m_firstPool;
                  m_firstPool = v184.m_mesh.m_triangles.m_allocator.m_firstPool )
            {
              v43 = m_firstPool->m_links[0];
              if ( v43 )
                v43->m_links[1] = m_firstPool->m_links[1];
              else
                v184.m_mesh.m_triangles.m_allocator.m_firstPool = m_firstPool->m_links[1];
              v44 = m_firstPool->m_links[1];
              if ( v44 )
                v44->m_links[0] = m_firstPool->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_firstPool, 6688);
            }
            v184.m_mesh.m_triangles.m_used = 0i64;
            v184.m_mesh.m_triangles.m_numUsed = 0;
            if ( m_firstPool )
            {
              do
              {
                v45 = m_firstPool->m_links[0];
                if ( v45 )
                  v45->m_links[1] = m_firstPool->m_links[1];
                else
                  v184.m_mesh.m_triangles.m_allocator.m_firstPool = m_firstPool->m_links[1];
                v46 = m_firstPool->m_links[1];
                if ( v46 )
                  v46->m_links[0] = m_firstPool->m_links[0];
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                  &hkContainerHeapAllocator::s_alloc,
                  m_firstPool,
                  6688);
                m_firstPool = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
              }
              while ( v184.m_mesh.m_triangles.m_allocator.m_firstPool );
            }
            for ( i = v184.m_mesh.m_vertices.m_allocator.m_firstPool;
                  v184.m_mesh.m_vertices.m_allocator.m_firstPool;
                  i = v184.m_mesh.m_vertices.m_allocator.m_firstPool )
            {
              v48 = i->m_links[0];
              if ( v48 )
                v48->m_links[1] = i->m_links[1];
              else
                v184.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
              v49 = i->m_links[1];
              if ( v49 )
                v49->m_links[0] = i->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
            }
            v184.m_mesh.m_vertices.m_used = 0i64;
            v184.m_mesh.m_vertices.m_numUsed = 0;
            if ( i )
            {
              do
              {
                v50 = i->m_links[0];
                if ( v50 )
                  v50->m_links[1] = i->m_links[1];
                else
                  v184.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
                v51 = i->m_links[1];
                if ( v51 )
                  v51->m_links[0] = i->m_links[0];
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
                i = v184.m_mesh.m_vertices.m_allocator.m_firstPool;
              }
              while ( v184.m_mesh.m_vertices.m_allocator.m_firstPool );
            }
            return v19;
          }
          v30 = dmax.m_quad.m128_i32[2];
          v32 = *(_QWORD *)&v190[0].m_enum;
          v29 = 0i64;
        }
        v38 = 0;
        if ( *(int *)(v35 + 8 * v36 + 40) > 0 )
        {
          do
          {
            ++v38;
            v29 += 4i64;
            *(_OWORD *)(dmax.m_quad.m128_u64[0] + 16i64 * v30) = *(_OWORD *)&vertices->m_storage.m_words.m_data[4 * *(int *)(*(_QWORD *)(v35 + 8 * v36 + 32) + v29 - 4)];
            v30 = ++dmax.m_quad.m128_i32[2];
          }
          while ( v38 < *(_DWORD *)(v35 + 8 * v36 + 40) );
          v29 = 0i64;
        }
        ++v31;
        v33 += 4i64;
      }
      while ( v31 < *(_DWORD *)(v32 + 8) );
      v15 = *(_QWORD *)&v190[0].m_enum;
    }
    dmin.m_quad.m128_u64[1] = (unsigned int)v30 | 0x1000000000i64;
    dmin.m_quad.m128_u64[0] = dmax.m_quad.m128_u64[0];
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
      v28,
      (hkStridedVertices *)&dmin,
      retaddr,
      1,
      1,
      0);
    dmax.m_quad.m128_i32[2] = 0;
    if ( dmax.m_quad.m128_i32[3] >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        (void *)dmax.m_quad.m128_u64[0],
        16 * dmax.m_quad.m128_i32[3]);
    v19 = v185;
  }
  else
  {
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      v28,
      1);
  }
  if ( v28->m_status.m_storage )
  {
    v19->m_enum = HK_FAILURE;
    v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v184,
      1);
    v184.m_stack.m_size = 0;
    if ( v184.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v184.m_stack.m_data,
        16 * v184.m_stack.m_capacityAndFlags);
    v39 = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
    v184.m_stack.m_data = 0i64;
    v184.m_stack.m_capacityAndFlags = 0x80000000;
    for ( v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          v184.m_mesh.m_triangles.m_allocator.m_firstPool;
          v39 = v184.m_mesh.m_triangles.m_allocator.m_firstPool )
    {
      v40 = v39->m_links[0];
      if ( v40 )
        v40->m_links[1] = v39->m_links[1];
      else
        v184.m_mesh.m_triangles.m_allocator.m_firstPool = v39->m_links[1];
      v52 = v39->m_links[1];
      if ( v52 )
        v52->m_links[0] = v39->m_links[0];
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v39, 6688);
    }
    v184.m_mesh.m_triangles.m_used = 0i64;
    v184.m_mesh.m_triangles.m_numUsed = 0;
    if ( v39 )
    {
      do
      {
        v53 = v39->m_links[0];
        if ( v53 )
          v53->m_links[1] = v39->m_links[1];
        else
          v184.m_mesh.m_triangles.m_allocator.m_firstPool = v39->m_links[1];
        v54 = v39->m_links[1];
        if ( v54 )
          v54->m_links[0] = v39->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v39, 6688);
        v39 = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
      }
      while ( v184.m_mesh.m_triangles.m_allocator.m_firstPool );
    }
    for ( j = v184.m_mesh.m_vertices.m_allocator.m_firstPool;
          v184.m_mesh.m_vertices.m_allocator.m_firstPool;
          j = v184.m_mesh.m_vertices.m_allocator.m_firstPool )
    {
      v56 = j->m_links[0];
      if ( v56 )
        v56->m_links[1] = j->m_links[1];
      else
        v184.m_mesh.m_vertices.m_allocator.m_firstPool = j->m_links[1];
      v57 = j->m_links[1];
      if ( v57 )
        v57->m_links[0] = j->m_links[0];
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, j, 1568);
    }
    v184.m_mesh.m_vertices.m_used = 0i64;
    v184.m_mesh.m_vertices.m_numUsed = 0;
    if ( j )
    {
      do
      {
        v58 = j->m_links[0];
        if ( v58 )
          v58->m_links[1] = j->m_links[1];
        else
          v184.m_mesh.m_vertices.m_allocator.m_firstPool = j->m_links[1];
        v59 = j->m_links[1];
        if ( v59 )
          v59->m_links[0] = j->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, j, 1568);
        j = v184.m_mesh.m_vertices.m_allocator.m_firstPool;
      }
      while ( v184.m_mesh.m_vertices.m_allocator.m_firstPool );
    }
    return v19;
  }
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>::hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>(&icrossing);
  v60 = 0i64;
  v61 = 0;
  dmax.m_quad.m128_i32[0] = 0;
  v172 = 0i64;
  if ( *(int *)(v15 + 8) <= 0 )
  {
LABEL_168:
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::partition(v28) == -1 )
    {
      v19 = v185;
      v185->m_enum = HK_FAILURE;
      v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v184,
        1);
      v184.m_stack.m_size = 0;
      if ( v184.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v184.m_stack.m_data,
          16 * v184.m_stack.m_capacityAndFlags);
      v184.m_stack.m_data = 0i64;
LABEL_266:
      v184.m_stack.m_capacityAndFlags = 0x80000000;
      hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::~hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>(&v184.m_mesh);
      return v19;
    }
    v142 = 0;
    if ( v21->m_vertexFraction > 0.0 )
    {
      for ( k = v28->m_mesh.m_triangles.m_used; k; k = k->m_next )
      {
        if ( (*((_BYTE *)k + 184) & 0x20) != 0 )
          ++v142;
      }
    }
    v144 = vars0;
    v145 = originalMesha;
    v146 = 0;
    if ( v21->m_userVertices.m_size )
    {
      addUserPoints(
        v190,
        originalMesha,
        vars0,
        &partitionAabb,
        retaddr,
        v28,
        v21,
        vertices,
        (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)vertices);
      if ( v190[0].m_enum )
      {
LABEL_223:
        v19 = v185;
        v185->m_enum = HK_FAILURE;
        v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          &v184,
          1);
LABEL_263:
        v184.m_stack.m_size = 0;
        if ( v184.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v184.m_stack.m_data,
            16 * v184.m_stack.m_capacityAndFlags);
        v184.m_stack.m_data = 0i64;
        goto LABEL_266;
      }
      v146 = 1;
    }
    if ( (int)(float)((float)v142 * v21->m_vertexFraction) || !v21->m_vertexSelectionMethod.m_storage )
    {
      laplacianSmooth(
        v190,
        v145,
        v144,
        retaddr,
        v28,
        v21,
        v142,
        (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)vertices);
      if ( v190[0].m_enum )
        goto LABEL_223;
    }
    else if ( !v146 )
    {
      goto LABEL_231;
    }
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::partition(v28) == -1 )
      goto LABEL_223;
LABEL_231:
    for ( m = (unsigned __int64)v28->m_mesh.m_triangles.m_used; m; m = *(_QWORD *)m )
    {
      if ( (*(_BYTE *)(m + 184) & 0x20) != 0 )
      {
        v148 = *(_QWORD *)(m + 16);
        partitionAabb.m_min.m_quad.m128_u64[0] = m;
        v149 = *(_QWORD *)(v148 + 24);
        v150 = *(_QWORD *)(m + 24);
        partitionAabb.m_min.m_quad.m128_i32[2] = 0;
        v151 = v149 >> 2;
        v152 = *(_QWORD *)(v150 + 24) >> 2;
        v153 = *(_QWORD *)(*(_QWORD *)(m + 32) + 24i64) >> 2;
        partitionAabb.m_max.m_quad.m128_u64[0] = m;
        edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m;
        partitionAabb.m_max.m_quad.m128_i32[2] = 1;
        edge.m_index = 2;
        if ( (_DWORD)v151 != (_DWORD)v152 && (_DWORD)v151 != (_DWORD)v153 && (_DWORD)v152 != (_DWORD)v153 )
        {
          v154 = *(_DWORD *)(v188 + 8);
          if ( (int)v151 < v154 && (int)v152 < v154 && (int)v153 < v154 )
          {
            v155 = result[2].m_enum + 3;
            v156 = result[3].m_enum & 0x3FFFFFFF;
            if ( v156 >= v155 )
            {
              LODWORD(segments) = 0;
            }
            else
            {
              v157 = 2 * v156;
              if ( v155 < v157 )
                v155 = v157;
              hkArrayUtil::_reserve((hkResult *)&segments, &hkContainerTempAllocator::s_alloc, result, v155, 4);
            }
            v158 = LODWORD(extraVertexSettings->m_areaFraction) + 3;
            v159 = LODWORD(extraVertexSettings->m_minPartitionArea) & 0x3FFFFFFF;
            if ( v159 >= v158 )
            {
              m_enum = HK_SUCCESS;
              v190[0].m_enum = HK_SUCCESS;
            }
            else
            {
              v160 = 2 * v159;
              if ( v158 < v160 )
                v158 = v160;
              hkArrayUtil::_reserve(v190, &hkContainerTempAllocator::s_alloc, extraVertexSettings, v158, 4);
              m_enum = v190[0].m_enum;
            }
            if ( (_DWORD)segments || m_enum )
              goto LABEL_223;
            *(_DWORD *)(*(_QWORD *)&result->m_enum + 4i64 * (int)result[2].m_enum++) = v151;
            *(_DWORD *)(*(_QWORD *)&result->m_enum + 4i64 * (int)result[2].m_enum++) = v152;
            *(_DWORD *)(*(_QWORD *)&result->m_enum + 4i64 * (int)result[2].m_enum++) = v153;
            EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                         v28,
                         (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&partitionAabb);
            if ( EdgeData )
              v163 = *(_DWORD *)EdgeData->m_tags.m_data;
            else
              v163 = -2;
            *(_DWORD *)(*(_QWORD *)&extraVertexSettings->m_vertexSelectionMethod.m_storage
                      + 4i64 * (int)LODWORD(extraVertexSettings->m_areaFraction)++) = v163;
            v164 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                     v28,
                     (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&partitionAabb.m_max);
            if ( v164 )
              v165 = *(_DWORD *)v164->m_tags.m_data;
            else
              v165 = -2;
            *(_DWORD *)(*(_QWORD *)&extraVertexSettings->m_vertexSelectionMethod.m_storage
                      + 4i64 * (int)LODWORD(extraVertexSettings->m_areaFraction)++) = v165;
            v166 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                     v28,
                     &edge);
            if ( v166 )
              v167 = *(_DWORD *)v166->m_tags.m_data;
            else
              v167 = -2;
            *(_DWORD *)(*(_QWORD *)&extraVertexSettings->m_vertexSelectionMethod.m_storage
                      + 4i64 * (int)LODWORD(extraVertexSettings->m_areaFraction)++) = v167;
          }
        }
      }
    }
    v19 = v185;
    v185->m_enum = HK_SUCCESS;
    v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v184,
      1);
    goto LABEL_263;
  }
  while ( 1 )
  {
    v62 = 0i64;
    v169[0].m_enum = HK_SUCCESS;
    v63 = *(int *)(*(_QWORD *)v15 + 4 * v60);
    v174 = 0i64;
    v64 = *v189;
    v65 = 48 * v63;
    dmin.m_quad.m128_u64[0] = v64;
    v66 = *(_DWORD *)(48 * v63 + v64 + 40);
    v178 = 48 * v63;
    if ( v66 - 1 > 0 )
      break;
LABEL_167:
    ++v61;
    v60 = v172 + 1;
    dmax.m_quad.m128_i32[0] = v61;
    ++v172;
    if ( v61 >= *(_DWORD *)(v15 + 8) )
      goto LABEL_168;
  }
  while ( 1 )
  {
    m_size = v21->m_userVertices.m_size;
    v68 = 0i64;
    dmax.m_quad.m128_u64[0] = 0i64;
    v69 = m_size + 2;
    v70 = 0;
    dmax.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    if ( v69 <= 0 )
    {
      dmax.m_quad.m128_i32[1] = 0;
    }
    else
    {
      hkArrayUtil::_reserve((hkResult *)&dmax.m_quad.m128_i16[2], &hkContainerHeapAllocator::s_alloc, &dmax, v69, 16);
      if ( dmax.m_quad.m128_i32[1] )
      {
        v19 = v185;
        v185->m_enum = HK_FAILURE;
LABEL_173:
        dmax.m_quad.m128_i32[2] = 0;
        if ( dmax.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)dmax.m_quad.m128_u64[0],
            16 * dmax.m_quad.m128_i32[3]);
        dmax.m_quad.m128_u64[0] = 0i64;
        dmax.m_quad.m128_i32[3] = 0x80000000;
        v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          &v184,
          1);
        v184.m_stack.m_size = 0;
        if ( v184.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v184.m_stack.m_data,
            16 * v184.m_stack.m_capacityAndFlags);
        v184.m_stack.m_data = 0i64;
        goto LABEL_178;
      }
      v70 = dmax.m_quad.m128_i32[2];
      v68 = dmax.m_quad.m128_u32[0];
    }
    v71 = *(_QWORD *)(v65 + v64 + 32);
    m_data = (hkVector4f *)vertices->m_storage.m_words.m_data;
    v73 = *(int *)(v71 + 4 * v62 + 4);
    v74 = *(int *)(v71 + 4 * v62);
    resulta[0].m_enum = v74;
    dmax.m_quad.m128_i32[2] = v73;
    m_quad = m_data[v73].m_quad;
    v76 = _mm_shuffle_ps(m_data[v74].m_quad, _mm_unpackhi_ps(m_data[v74].m_quad, (__m128)0i64), 196);
    v77 = *v189;
    v78 = 3i64 * *(int *)(*(_QWORD *)v15 + 4 * v172);
    vIn0.m_quad = v76;
    v79 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
    vIn1.m_quad = v79;
    v80 = *(int **)(v77 + 16 * v78 + 16);
    if ( *v80 >= SLODWORD(originalMesh->m_faces.m_data) )
      goto LABEL_105;
    if ( ((*((_DWORD *)&originalMesh->vfptr->__vecDelDtor + ((__int64)*v80 >> 5)) >> (*v80 & 0x1F)) & 1) != 0 )
    {
      v81 = 1;
      v82 = -1;
    }
    else
    {
LABEL_105:
      v82 = v80[v62];
      v81 = 0;
    }
    dmin.m_quad.m128_u64[1] = (unsigned __int64)resulta;
    *(_QWORD *)&resulta[0].m_enum = v82;
    v172 = 0x8000000200000001ui64;
    if ( v81 )
    {
      hkaiNavMeshSimplificationUtils::getEdgeSplitting(
        &resulta[1],
        &vIn0,
        &vIn1,
        v21,
        v81,
        vertices,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)&dmax);
      if ( resulta[1].m_enum )
      {
        v19 = v185;
        v185->m_enum = HK_FAILURE;
LABEL_180:
        LODWORD(v172) = 0;
        if ( v172 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[1],
            8 * HIDWORD(v172));
        dmin.m_quad.m128_u64[1] = 0i64;
        HIDWORD(v172) = 0x80000000;
        goto LABEL_173;
      }
      v83 = dmax.m_quad.m128_i32[2];
    }
    else
    {
      *(__m128 *)(v68 + 16i64 * v70) = v76;
      ++dmax.m_quad.m128_i32[2];
      *(__m128 *)(dmax.m_quad.m128_u64[0] + 16i64 * dmax.m_quad.m128_i32[2]) = v79;
      v83 = ++dmax.m_quad.m128_i32[2];
    }
    v84 = 0i64;
    v85 = v83;
    v86 = v83;
    LODWORD(segments) = v83;
    v87 = 0;
    if ( v83 )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v90 = (32 * v85 + 127) & 0xFFFFFF80;
      v91 = &m_cur[v90];
      if ( v90 > Value->m_slabSize || v91 > Value->m_end )
      {
        v92 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v90);
        v83 = dmax.m_quad.m128_i32[2];
        m_cur = v92;
      }
      else
      {
        Value->m_cur = v91;
        v83 = dmax.m_quad.m128_i32[2];
      }
    }
    else
    {
      m_cur = 0i64;
    }
    v93 = vertices->m_storage.m_words.m_size - 2;
    v94 = vertices->m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
    dmin.m_quad.m128_i32[0] = v85 | 0x80000000;
    v95 = v83 + v93;
    if ( v94 < v95 )
      break;
    v169[1].m_enum = HK_SUCCESS;
LABEL_122:
    if ( v83 > 0 )
    {
      while ( 1 )
      {
        m_margin = v28->m_margin;
        v98 = *(__m128 *)(dmax.m_quad.m128_u64[0] + 16 * v84);
        v99 = 0x7FFFFF - m_margin;
        v100 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), v28->m_worldToLocal.m_col0.m_quad),
                     v28->m_worldToLocal.m_col3.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), v28->m_worldToLocal.m_col1.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), v28->m_worldToLocal.m_col2.m_quad));
        v101 = _mm_sub_ps(v100, (__m128)xmmword_141A711B0);
        v102 = _mm_add_ps(v100, (__m128)xmmword_141A711B0);
        v103 = _mm_cmplt_ps(v100, (__m128)0i64);
        v104 = _mm_or_ps(_mm_andnot_ps(v103, v102), _mm_and_ps(v101, v103));
        v105 = _mm_xor_si128(
                 (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v104),
                 _mm_cvttps_epi32(v104));
        v106 = _mm_cvtsi128_si32(v105);
        if ( v106 >= m_margin )
        {
          if ( v106 > v99 )
            v106 = 0x7FFFFF - m_margin;
        }
        else
        {
          v106 = v28->m_margin;
        }
        v107 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v105, 85));
        if ( v107 >= m_margin )
        {
          m_margin = v107;
          if ( v107 > v99 )
            m_margin = v99;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
          v28,
          &v175,
          v106,
          m_margin,
          1,
          (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing);
        if ( v175.m_type.m_storage == 10 || v28->m_status.m_storage )
          break;
        if ( v84 )
        {
          if ( v87 == dmax.m_quad.m128_i32[2] - 1 )
          {
            v108 = dmax.m_quad.m128_i32[2];
          }
          else
          {
            v108 = vertices->m_storage.m_words.m_size;
            *(__m128 *)&vertices->m_storage.m_words.m_data[4 * v108] = v98;
            ++vertices->m_storage.m_words.m_size;
          }
        }
        else
        {
          v108 = resulta[0].m_enum;
        }
        v109 = v175.m_edge.m_triangle->m_vertices[v175.m_edge.m_index];
        v110 = (4i64 * v108) | *((_BYTE *)&v0 + 24) & 3;
        *((_QWORD *)v109 + 3) = (4i64 * v108) | *((_DWORD *)v109 + 6) & 3;
        v111 = &m_cur[32 * v87];
        if ( v111 )
        {
          *((_DWORD *)v111 + 4) = v106;
          *((_DWORD *)v111 + 5) = m_margin;
          *((_QWORD *)v111 + 3) = v110;
        }
        v83 = dmax.m_quad.m128_i32[2];
        ++v87;
        ++v84;
        if ( v87 >= dmax.m_quad.m128_i32[2] )
          goto LABEL_140;
      }
      v19 = v185;
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v135 = 32 * (_DWORD)segments + 127;
      v185->m_enum = HK_FAILURE;
      v135 &= 0xFFFFFF80;
      v136 = (hkLifoAllocator *)TlsGetValue(m_slotID);
      v137 = (v135 + 15) & 0xFFFFFFF0;
      if ( v135 > v136->m_slabSize || &m_cur[v137] != v136->m_cur || v136->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v136, m_cur, v137);
      else
        v136->m_cur = m_cur;
      if ( dmin.m_quad.m128_i32[0] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          m_cur,
          32 * dmin.m_quad.m128_i32[0]);
      goto LABEL_180;
    }
LABEL_140:
    v112 = 0;
    if ( v83 - 1 > 0 )
    {
      v113 = m_cur + 52;
      do
      {
        v114 = *((_DWORD *)v113 - 9);
        v115 = *((_DWORD *)v113 - 1);
        v116 = *((_DWORD *)v113 - 8);
        v117 = *(_DWORD *)v113;
        *((_QWORD *)&v0 + 3) = *(_QWORD *)(v113 - 28);
        v118 = *(_QWORD *)(v113 + 4);
        v0.m_x = v114;
        v0.m_y = v116;
        v1.m_x = v115;
        v1.m_y = v117;
        *((_QWORD *)&v1 + 3) = v118;
        if ( v114 != v115 || v116 != v117 )
        {
          hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>::setPossibleVertsAndTriangulator(
            &icrossing,
            &v0,
            &v1,
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)v28);
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertCrossingEdge<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
            v28,
            &v175,
            v0.m_x,
            v0.m_y,
            v1.m_x,
            v1.m_y,
            1,
            (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing,
            (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)&dmin.m_quad.m128_u16[4]);
          if ( v175.m_type.m_storage == 10 || v28->m_status.m_storage )
          {
            v19 = v185;
            v138 = hkMemoryRouter::s_memoryRouter.m_slotID;
            v139 = 32 * (_DWORD)segments + 127;
            v185->m_enum = HK_FAILURE;
            v139 &= 0xFFFFFF80;
            v140 = (hkLifoAllocator *)TlsGetValue(v138);
            v141 = (v139 + 15) & 0xFFFFFFF0;
            if ( v139 > v140->m_slabSize || &m_cur[v141] != v140->m_cur || v140->m_firstNonLifoEnd == m_cur )
              hkLifoAllocator::slowBlockFree(v140, m_cur, v141);
            else
              v140->m_cur = m_cur;
            if ( dmin.m_quad.m128_i32[0] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                m_cur,
                32 * dmin.m_quad.m128_i32[0]);
            LODWORD(v172) = 0;
            if ( v172 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                (void *)dmin.m_quad.m128_u64[1],
                8 * HIDWORD(v172));
            dmin.m_quad.m128_u64[1] = 0i64;
            HIDWORD(v172) = 0x80000000;
            dmax.m_quad.m128_i32[2] = 0;
            if ( dmax.m_quad.m128_i32[3] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                16 * dmax.m_quad.m128_i32[3]);
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 0x80000000;
            v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v184,
              1);
            v184.m_stack.m_size = 0;
            if ( v184.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v184.m_stack.m_data,
                16 * v184.m_stack.m_capacityAndFlags);
            v184.m_stack.m_data = 0i64;
            goto LABEL_178;
          }
          LOBYTE(v119) = v175.m_edge.m_index;
          v120 = v175.m_edge.m_triangle->m_vertices[v175.m_edge.m_index];
          v121 = v175.m_edge.m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(v175.m_edge.m_index))) & 3];
          m_x = v120->m_x;
          v123 = v121->m_x;
          if ( m_x >= v123
            && (m_x > v123 || v120->m_y > v121->m_y)
            && (v124 = v175.m_edge.m_triangle->m_links[v175.m_edge.m_index], (v124 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v119 = v175.m_edge.m_triangle->m_links[v175.m_edge.m_index] & 3;
            m_triangle = v124 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            m_triangle = (unsigned __int64)v175.m_edge.m_triangle;
          }
          *(_WORD *)(m_triangle + 184) ^= ((unsigned __int8)*(_WORD *)(m_triangle + 184) ^ (unsigned __int8)(*(_WORD *)(m_triangle + 184) | (1 << v119))) & 7;
          v83 = dmax.m_quad.m128_i32[2];
        }
        ++v112;
        v113 += 32;
      }
      while ( v112 < v83 - 1 );
    }
    v126 = (32 * (_DWORD)segments + 127) & 0xFFFFFF80;
    v127 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v128 = (v126 + 15) & 0xFFFFFFF0;
    if ( v126 > v127->m_slabSize || &m_cur[v128] != v127->m_cur || v127->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v127, m_cur, v128);
    else
      v127->m_cur = m_cur;
    if ( dmin.m_quad.m128_i32[0] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_cur,
        32 * dmin.m_quad.m128_i32[0]);
    LODWORD(v172) = 0;
    if ( v172 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)dmin.m_quad.m128_u64[1],
        8 * HIDWORD(v172));
    dmin.m_quad.m128_u64[1] = 0i64;
    HIDWORD(v172) = 0x80000000;
    dmax.m_quad.m128_i32[2] = 0;
    if ( dmax.m_quad.m128_i32[3] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)dmax.m_quad.m128_u64[0],
        16 * dmax.m_quad.m128_i32[3]);
    v65 = v178;
    v64 = dmin.m_quad.m128_u64[0];
    v21 = v186;
    v15 = *(_QWORD *)&v190[0].m_enum;
    v62 = v174 + 1;
    v129 = *(_DWORD *)(v178 + dmin.m_quad.m128_u64[0] + 40) - 1;
    dmax.m_quad.m128_u64[0] = 0i64;
    dmax.m_quad.m128_i32[3] = 0x80000000;
    ++v169[0].m_enum;
    ++v174;
    if ( v169[0].m_enum >= v129 )
    {
      v61 = dmax.m_quad.m128_i32[0];
      goto LABEL_167;
    }
  }
  v96 = 2 * v94;
  if ( v95 < v96 )
    v95 = v96;
  hkArrayUtil::_reserve(&v169[1], &hkContainerHeapAllocator::s_alloc, vertices, v95, 16);
  if ( v169[1].m_enum == HK_SUCCESS )
  {
    v83 = dmax.m_quad.m128_i32[2];
    goto LABEL_122;
  }
  v19 = v185;
  v130 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v185->m_enum = HK_FAILURE;
  v131 = (32 * v86 + 127) & 0xFFFFFF80;
  v132 = (hkLifoAllocator *)TlsGetValue(v130);
  v133 = (v131 + 15) & 0xFFFFFFF0;
  if ( v131 > v132->m_slabSize || &m_cur[v133] != v132->m_cur || v132->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v132, m_cur, v133);
  else
    v132->m_cur = m_cur;
  LODWORD(v172) = 0;
  if ( v172 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)dmin.m_quad.m128_u64[1],
      8 * HIDWORD(v172));
  dmin.m_quad.m128_u64[1] = 0i64;
  HIDWORD(v172) = 0x80000000;
  dmax.m_quad.m128_i32[2] = 0;
  if ( dmax.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)dmax.m_quad.m128_u64[0],
      16 * dmax.m_quad.m128_i32[3]);
  dmax.m_quad.m128_u64[0] = 0i64;
  dmax.m_quad.m128_i32[3] = 0x80000000;
  v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    &v184,
    1);
  v184.m_stack.m_size = 0;
  if ( v184.m_stack.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v184.m_stack.m_data,
      16 * v184.m_stack.m_capacityAndFlags);
  v184.m_stack.m_data = 0i64;
LABEL_178:
  v184.m_stack.m_capacityAndFlags = 0x80000000;
  v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&v184.m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&v184.m_mesh.m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&v184.m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&v184.m_mesh.m_vertices);
  return v19;
}
}

// File Line: 1107
// RVA: 0xB65480
void __fastcall anonymous_namespace_::projectPoints(
        hkVector4f *projDir,
        hkArrayBase<hkVector4f> *verticesIn,
        hkArray<hkVector2f,hkContainerHeapAllocator> *verticesOut)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  float v8; // xmm1_4
  __m128 m_quad; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  int v22; // edx
  __int64 v23; // r8
  __int64 v24; // rcx
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  hkQuaternionf v31; // [rsp+20h] [rbp-88h] BYREF

  v6 = _mm_mul_ps(projDir->m_quad, stru_141A71280.m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
  if ( v7.m128_f32[0] <= v8 )
  {
    if ( v7.m128_f32[0] >= (float)(0.0 - v8) )
    {
      v10 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v7), (__m128)xmmword_141A711B0);
      v11 = _mm_rsqrt_ps(v10);
      v12 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), projDir->m_quad),
              _mm_mul_ps(_mm_shuffle_ps(projDir->m_quad, projDir->m_quad, 201), stru_141A71280.m_quad));
      v13 = _mm_shuffle_ps(v12, v12, 201);
      v14 = _mm_andnot_ps(
              _mm_cmple_ps(v10, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                _mm_mul_ps(*(__m128 *)_xmm, v11)));
      v15 = _mm_mul_ps(v14, (__m128)xmmword_141A711B0);
      if ( v7.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0).m128_f32[0] )
      {
        v16 = _mm_mul_ps(v13, v13);
        v17 = _mm_sub_ps(v10, v7);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170));
        v19 = _mm_rsqrt_ps(v18);
        v20 = _mm_rsqrt_ps(v17);
        v15 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v17, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)),
                      _mm_mul_ps(*(__m128 *)_xmm, v20))),
                  v17),
                _mm_andnot_ps(
                  _mm_cmple_ps(v18, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))));
      }
      v21 = _mm_mul_ps(v13, v15);
      m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, _mm_mul_ps(v14, v10)), 196);
      v31.m_vec.m_quad = m_quad;
    }
    else
    {
      hkQuaternionf::setFlippedRotation(&v31, projDir);
      m_quad = v31.m_vec.m_quad;
    }
  }
  else
  {
    m_quad = qi.m_vec.m_quad;
    v31.m_vec.m_quad = qi.m_vec.m_quad;
  }
  v22 = 0;
  if ( verticesOut->m_size > 0 )
  {
    v23 = 0i64;
    while ( 1 )
    {
      v24 = v22++;
      ++v23;
      v25 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v26 = _mm_mul_ps(verticesIn->m_data[v23 - 1].m_quad, projDir->m_quad);
      v27 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                    _mm_shuffle_ps(v26, v26, 170))),
                projDir->m_quad),
              verticesIn->m_data[v23 - 1].m_quad);
      v28 = _mm_mul_ps(m_quad, v27);
      v29 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v27));
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                    _mm_shuffle_ps(v28, v28, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v27)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v25));
      verticesOut->m_data[v24] = (hkVector2f)_mm_add_ps(v30, v30).m128_u64[0];
      if ( v22 >= verticesOut->m_size )
        break;
      m_quad = v31.m_vec.m_quad;
    }
  }
}

// File Line: 1261
// RVA: 0xB65770
__int64 __fastcall mergeAllowedByHeightPartition(
        hkLocalArray<hkVector4f> *points,
        hkSimdFloat32 *heightPartitionThreshold)
{
  unsigned int v4; // esi
  int i; // ebx
  __int64 m_size; // rdx
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  hkVector4f *m_data; // rcx
  __m128 m_quad; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  hkVector4f planeOut; // [rsp+20h] [rbp-88h] BYREF
  hkaiNavMeshSimplificationUtils::PlaneFitter v21; // [rsp+30h] [rbp-78h] BYREF
  hkResult result; // [rsp+B0h] [rbp+8h] BYREF

  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&v21);
  v4 = 0;
  for ( i = 0; i < points->m_size; ++i )
    hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v21, &points->m_data[i]);
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v21, &result, &planeOut);
  m_size = points->m_size;
  v7 = _mm_mul_ps(planeOut.m_quad, planeOut.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_cmple_ps(v8, (__m128)0i64);
  v11 = _mm_mul_ps(v9, v8);
  v12 = (__m128)xmmword_141A712A0;
  v13 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v14 = _mm_mul_ps(
          planeOut.m_quad,
          _mm_andnot_ps(v10, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))));
  planeOut.m_quad = v14;
  if ( m_size > 0 )
  {
    m_data = points->m_data;
    do
    {
      m_quad = m_data->m_quad;
      ++m_data;
      v17 = _mm_mul_ps(m_quad, v14);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v13 = _mm_max_ps(v18, v13);
      v12 = _mm_min_ps(v18, v12);
      --m_size;
    }
    while ( m_size );
  }
  if ( (float)(v13.m128_f32[0] - v12.m128_f32[0]) <= heightPartitionThreshold->m_real.m128_f32[0] )
    return 1;
  return v4;
}

// File Line: 1287
// RVA: 0xB658D0
__int64 __fastcall hertelMehlhorn_canMerge(
        int edgeIdx,
        hkaiNavMeshGenerationSettings *settings,
        hkSimdFloat32 *mesh,
        const float *heightErrorOverride,
        hkPointerMap<int,int,hkContainerHeapAllocator> *settingsIndexMap,
        hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut,
        hkResult *memoryRes)
{
  hkaiNavMesh::Edge *v8; // rdi
  __int64 v9; // r15
  unsigned int m_oppositeEdge; // eax
  hkaiNavMesh::Face *v13; // rdx
  __int64 v14; // r8
  int v15; // r9d
  __int64 m_startEdgeIndex; // r12
  __int64 v17; // r11
  __int64 v18; // r10
  int v19; // eax
  int v20; // r8d
  __int64 v21; // r14
  float v22; // eax
  __int64 v23; // rdx
  unsigned int *v24; // rcx
  int v25; // esi
  int m_size; // edx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // r8
  int v29; // edx
  char *v30; // rcx
  hkVector4f *v31; // rax
  __int64 v32; // r9
  __int64 v33; // r8
  __int64 v34; // r9
  __int64 v35; // r8
  int v36; // eax
  hkaiNavMeshSimplificationUtils::Settings *SimplificationSettings; // rax
  hkaiNavMeshSimplificationUtils::Settings *v38; // rsi
  __m128 v39; // xmm1
  const float *p_m_maxPartitionHeightError; // rax
  unsigned int v41; // ecx
  hkaiNavMesh::Edge *v42; // r10
  float x; // eax
  __int64 v44; // r14
  signed int v45; // eax
  __int64 v46; // r11
  int v47; // r13d
  unsigned int v48; // ecx
  __int64 m_a; // r8
  __m128i si128; // xmm5
  __int64 m_b; // rdx
  hkVector4f *v52; // rcx
  __m128 v53; // xmm8
  __m128i v54; // xmm7
  __m128 v55; // xmm2
  __m128i v56; // xmm5
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __int64 v61; // rax
  __int64 v62; // rax
  __int128 v63; // xmm0
  __int64 v64; // rax
  __int128 v65; // xmm0
  char v66; // dl
  char v67; // r8
  float v68; // xmm9_4
  float v69; // xmm5_4
  float v70; // xmm11_4
  float v71; // xmm12_4
  float v72; // xmm13_4
  float v73; // xmm14_4
  float v74; // xmm3_4
  bool v75; // cc
  float v76; // xmm13_4
  bool v77; // cl
  bool v78; // cf
  float v79; // xmm6_4
  float v80; // xmm4_4
  float v81; // xmm7_4
  float v82; // xmm8_4
  float v83; // xmm3_4
  bool v84; // al
  unsigned int v85; // edi
  bool v86; // bl
  hkVector4f *m_localMemory; // rsi
  signed int v88; // ebx
  hkLifoAllocator *v89; // rax
  int v90; // r8d
  hkVector4f *normalOut; // [rsp+20h] [rbp-E0h]
  hkVector4f *normalOutc; // [rsp+20h] [rbp-E0h]
  int normalOuta; // [rsp+20h] [rbp-E0h]
  hkVector4f *normalOutb; // [rsp+20h] [rbp-E0h]
  hkLocalArray<hkVector4f> points; // [rsp+28h] [rbp-D8h] BYREF
  hkSimdFloat32 heightPartitionThreshold; // [rsp+50h] [rbp-B0h] BYREF
  hkVector2f v97; // [rsp+60h] [rbp-A0h]
  hkVector2f v98; // [rsp+68h] [rbp-98h]
  hkVector2f v99; // [rsp+70h] [rbp-90h]
  hkaiNavMesh *mesha[2]; // [rsp+80h] [rbp-80h] BYREF
  int m_startUserEdgeIndex; // [rsp+94h] [rbp-6Ch]
  int v102; // [rsp+98h] [rbp-68h]
  int v103; // [rsp+9Ch] [rbp-64h]
  int v104[4]; // [rsp+A0h] [rbp-60h] BYREF
  int v105; // [rsp+B0h] [rbp-50h]
  const float *v106; // [rsp+C0h] [rbp-40h]
  int faceIndex[4]; // [rsp+D0h] [rbp-30h] BYREF
  hkArray<hkVector2f,hkContainerHeapAllocator> verticesOut; // [rsp+E0h] [rbp-20h] BYREF
  char v109; // [rsp+F0h] [rbp-10h] BYREF
  hkArrayBase<hkVector4f> verticesIn; // [rsp+120h] [rbp+20h] BYREF
  __int128 v111[6]; // [rsp+130h] [rbp+30h] BYREF
  int v112; // [rsp+260h] [rbp+160h]
  int v114; // [rsp+270h] [rbp+170h]
  int v115; // [rsp+270h] [rbp+170h]
  float m_nonconvexityThreshold; // [rsp+270h] [rbp+170h]
  hkResult *memoryResa; // [rsp+290h] [rbp+190h]

  memoryRes->m_enum = HK_SUCCESS;
  v8 = (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0];
  v9 = edgeIdx;
  v106 = heightErrorOverride;
  m_oppositeEdge = v8[edgeIdx].m_oppositeEdge;
  if ( m_oppositeEdge == -1 )
    return 0i64;
  v13 = (hkaiNavMesh::Face *)mesh[1].m_real.m128_u64[0];
  v14 = mesh[7].m_real.m128_i32[0];
  LODWORD(normalOut) = v8[m_oppositeEdge & 0x3FFFFF].m_a;
  LODWORD(v97.x) = v8[m_oppositeEdge & 0x3FFFFF].m_b;
  v104[2] = v8[m_oppositeEdge & 0x3FFFFF].m_oppositeEdge;
  v104[3] = v8[m_oppositeEdge & 0x3FFFFF].m_oppositeFace;
  LODWORD(mesha[0]) = v104[3];
  v105 = *(_DWORD *)&v8[m_oppositeEdge & 0x3FFFFF].m_flags.m_storage;
  v15 = v8[edgeIdx].m_oppositeFace & 0x3FFFFF;
  m_startEdgeIndex = v13[v15].m_startEdgeIndex;
  *(unsigned __int64 *)((char *)heightPartitionThreshold.m_real.m128_u64 + 4) = *(_QWORD *)&v13[v15].m_startUserEdgeIndex;
  heightPartitionThreshold.m_real.m128_i32[3] = *(_DWORD *)&v13[v15].m_clusterIndex;
  if ( (_DWORD)v14 )
    v114 = *(_DWORD *)(mesh[5].m_real.m128_u64[0] + 4 * v15 * v14);
  else
    v114 = 0;
  v17 = v104[3] & 0x3FFFFF;
  v18 = v13[v17].m_startEdgeIndex;
  m_startUserEdgeIndex = v13[v17].m_startUserEdgeIndex;
  v19 = *(_DWORD *)&v13[v17].m_numEdges;
  LODWORD(v99.x) = v18;
  v102 = v19;
  v103 = *(_DWORD *)&v13[v17].m_clusterIndex;
  if ( (_DWORD)v14 )
    v112 = *(_DWORD *)(mesh[5].m_real.m128_u64[0] + 4 * v17 * v14);
  else
    v112 = 0;
  v20 = 0;
  v21 = v18;
  LODWORD(v22) = v18 + (__int16)v102;
  v98.x = v22;
  if ( v18 < SLODWORD(v22) )
  {
    v23 = SLODWORD(v22) - v18;
    v24 = &v8->m_oppositeFace + 4 * v18 + v18;
    do
    {
      if ( *v24 != -1 && (*v24 & 0x3FFFFF) == v15 )
        ++v20;
      v24 += 5;
      --v23;
    }
    while ( v23 );
    if ( v20 > 1 )
      return 0i64;
  }
  if ( faceToPartitionMapInOut && faceToPartitionMapInOut->m_data[v17] != faceToPartitionMapInOut->m_data[v15] )
    return 0i64;
  if ( v112 != v114 )
    return 0i64;
  v25 = heightPartitionThreshold.m_real.m128_i16[4] + (__int16)v102;
  v115 = heightPartitionThreshold.m_real.m128_i16[4];
  if ( v25 - 2 >= settings->m_maxNumEdgesPerFace )
    return 0i64;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    (hkaiNavMeshUtils *)mesha,
    mesh,
    (hkaiNavMesh *)LODWORD(mesha[0]),
    (int)faceIndex,
    normalOut);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    (hkaiNavMeshUtils *)mesha,
    mesh,
    (hkaiNavMesh *)v8[v9].m_oppositeFace,
    (int)v104,
    normalOutc);
  points.m_capacityAndFlags = 0x80000000;
  points.m_data = 0i64;
  m_size = 0;
  points.m_size = 0;
  points.m_initialCapacity = v25;
  if ( v25 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v29 = (16 * v25 + 127) & 0xFFFFFF80;
    v30 = (char *)m_cur + v29;
    if ( v29 > Value->m_slabSize || v30 > Value->m_end )
    {
      v31 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v29);
      m_size = points.m_size;
      points.m_data = v31;
    }
    else
    {
      Value->m_cur = v30;
      m_size = points.m_size;
      points.m_data = m_cur;
    }
  }
  else
  {
    points.m_data = 0i64;
  }
  points.m_capacityAndFlags = v25 | 0x80000000;
  points.m_localMemory = points.m_data;
  if ( !points.m_data )
  {
    memoryRes->m_enum = HK_FAILURE;
LABEL_85:
    v85 = 0;
    goto LABEL_86;
  }
  v32 = (__int16)v102;
  if ( (__int16)v102 > 0 )
  {
    v33 = 20 * v21;
    do
    {
      v33 += 20i64;
      points.m_data[m_size] = *(hkVector4f *)(mesh[3].m_real.m128_u64[0]
                                            + 16i64 * *(int *)(mesh[2].m_real.m128_u64[0] + v33 - 20));
      m_size = ++points.m_size;
      --v32;
    }
    while ( v32 );
  }
  v34 = heightPartitionThreshold.m_real.m128_i16[4];
  if ( heightPartitionThreshold.m_real.m128_i16[4] > 0 )
  {
    v35 = 20 * m_startEdgeIndex;
    do
    {
      v35 += 20i64;
      points.m_data[m_size] = *(hkVector4f *)(mesh[3].m_real.m128_u64[0]
                                            + 16i64 * *(int *)(mesh[2].m_real.m128_u64[0] + v35 - 20));
      m_size = ++points.m_size;
      --v34;
    }
    while ( v34 );
  }
  v36 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          &settingsIndexMap->m_map,
          v112,
          0xFFFFFFFFFFFFFFFFui64);
  SimplificationSettings = hkaiNavMeshGenerationSettings::getSimplificationSettings(settings, &points, v36);
  v38 = SimplificationSettings;
  v39 = _mm_mul_ps(*(__m128 *)v104, *(__m128 *)faceIndex);
  if ( (float)((float)(_mm_shuffle_ps(v39, v39, 0).m128_f32[0] + _mm_shuffle_ps(v39, v39, 85).m128_f32[0])
             + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) < _mm_shuffle_ps(
                                                              (__m128)LODWORD(SimplificationSettings->m_cosPlanarityThreshold),
                                                              (__m128)LODWORD(SimplificationSettings->m_cosPlanarityThreshold),
                                                              0).m128_f32[0] )
    goto LABEL_84;
  if ( SimplificationSettings->m_useHeightPartitioning.m_bool )
  {
    p_m_maxPartitionHeightError = v106;
    if ( !v106 )
      p_m_maxPartitionHeightError = &v38->m_maxPartitionHeightError;
    heightPartitionThreshold.m_real = _mm_shuffle_ps(
                                        (__m128)*(unsigned int *)p_m_maxPartitionHeightError,
                                        (__m128)*(unsigned int *)p_m_maxPartitionHeightError,
                                        0);
    if ( !(unsigned int)mergeAllowedByHeightPartition(&points, &heightPartitionThreshold) )
    {
LABEL_84:
      m_size = points.m_size;
      goto LABEL_85;
    }
  }
  v41 = v8[v9].m_oppositeEdge;
  v42 = (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0];
  LODWORD(x) = edgeIdx + 1;
  if ( edgeIdx + 1 == LODWORD(v98.x) )
    x = v99.x;
  v44 = SLODWORD(x);
  if ( v41 == (_DWORD)m_startEdgeIndex )
    v45 = m_startEdgeIndex + v115 - 1;
  else
    v45 = v41 - 1;
  v46 = v45;
  if ( edgeIdx == LODWORD(v99.x) )
    v47 = LODWORD(v98.x) - 1;
  else
    v47 = edgeIdx - 1;
  v48 = v41 + 1;
  m_a = v8[v9].m_a;
  if ( v48 == v115 + (_DWORD)m_startEdgeIndex )
    v48 = m_startEdgeIndex;
  if ( (_DWORD)m_a != LODWORD(v97.x) || v8[v9].m_b != normalOuta )
    goto LABEL_83;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  m_nonconvexityThreshold = v38->m_nonconvexityThreshold;
  verticesIn.m_size = 6;
  verticesIn.m_capacityAndFlags = -2147483642;
  m_b = v42[v48].m_b;
  v52 = (hkVector4f *)mesh[3].m_real.m128_u64[0];
  verticesIn.m_data = (hkVector4f *)v111;
  v53 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(m_nonconvexityThreshold * 0.017453292), *(__m128 *)_xmm);
  v54 = _mm_add_epi32(si128, si128);
  v55 = _mm_andnot_ps(*(__m128 *)_xmm, v53);
  v56 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v55, *(__m128 *)_xmm)), si128));
  v57 = _mm_cvtepi32_ps(v56);
  v58 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v56, v54), (__m128i)0i64);
  v59 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v57, *(__m128 *)DP1_0), v55), _mm_mul_ps(v57, *(__m128 *)DP2)),
          _mm_mul_ps(v57, *(__m128 *)DP3));
  v60 = _mm_mul_ps(v59, v59);
  heightPartitionThreshold.m_real = _mm_xor_ps(
                                      _mm_xor_ps(
                                        _mm_or_ps(
                                          _mm_andnot_ps(
                                            v58,
                                            _mm_add_ps(
                                              _mm_sub_ps(
                                                _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(v60, *(__m128 *)cosCoeff0_0),
                                                          *(__m128 *)cosCoeff1),
                                                        v60),
                                                      *(__m128 *)cosCoeff2_0),
                                                    v60),
                                                  v60),
                                                _mm_mul_ps(v60, *(__m128 *)_xmm)),
                                              *(__m128 *)_xmm)),
                                          _mm_and_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(v60, *(__m128 *)sinCoeff0),
                                                        *(__m128 *)sinCoeff1_0),
                                                      v60),
                                                    *(__m128 *)sinCoeff2_0),
                                                  v60),
                                                v59),
                                              v59),
                                            v58)),
                                        _mm_xor_ps(
                                          (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v54, v54), v56), 0x1Du),
                                          _mm_and_ps(v53, *(__m128 *)_xmm))),
                                      *(__m128 *)_xmm);
  v111[0] = (__int128)v52[m_a];
  v61 = v42[v44].m_b;
  v111[1] = (__int128)v52[normalOuta];
  v111[2] = (__int128)v52[v61];
  v62 = v42[v47].m_a;
  v111[3] = (__int128)v52[m_b];
  v63 = (__int128)v52[v62];
  v64 = v42[v46].m_a;
  v111[4] = v63;
  v65 = (__int128)v52[v64];
  verticesOut.m_size = 6;
  v111[5] = v65;
  verticesOut.m_data = (hkVector2f *)&v109;
  verticesOut.m_capacityAndFlags = -2147483642;
  anonymous_namespace_::projectPoints((hkVector4f *)faceIndex, &verticesIn, &verticesOut);
  v66 = 1;
  v67 = 1;
  v99 = *verticesOut.m_data;
  normalOutb = (hkVector4f *)verticesOut.m_data[1];
  mesha[0] = (hkaiNavMesh *)verticesOut.m_data[2];
  v97 = verticesOut.m_data[3];
  memoryResa = (hkResult *)verticesOut.m_data[4];
  v68 = v97.x - v99.x;
  v69 = v97.y - v99.y;
  v98 = verticesOut.m_data[5];
  v70 = *(float *)&memoryResa - v99.x;
  v71 = *((float *)&memoryResa + 1) - v99.y;
  v72 = (float)((float)(v99.x - *(float *)&memoryResa) * (float)(v97.y - *((float *)&memoryResa + 1)))
      - (float)((float)(v97.x - *(float *)&memoryResa) * (float)(v99.y - *((float *)&memoryResa + 1)));
  v73 = (float)((float)(*(float *)&normalOutb - v98.x) * (float)(*((float *)mesha + 1) - v98.y))
      - (float)((float)(*(float *)mesha - v98.x) * (float)(*((float *)&normalOutb + 1) - v98.y));
  v74 = (float)((float)(v97.y - v99.y) * (float)(*((float *)&memoryResa + 1) - v99.y))
      + (float)((float)(v97.x - v99.x) * (float)(*(float *)&memoryResa - v99.x));
  if ( v74 <= 0.0 )
  {
    v78 = v72 < 0.0;
    v76 = FLOAT_0_99900001;
    v77 = !v78;
  }
  else
  {
    v66 = 0;
    v75 = v72 <= 0.0;
    v76 = FLOAT_0_99900001;
    v77 = !v75
       && (float)(v74
                / (float)(fsqrt((float)(v69 * v69) + (float)(v68 * v68)) * fsqrt((float)(v71 * v71) + (float)(v70 * v70)))) < 0.99900001;
  }
  v79 = *(float *)mesha - *(float *)&normalOutb;
  v80 = *((float *)mesha + 1) - *((float *)&normalOutb + 1);
  v81 = v98.x - *(float *)&normalOutb;
  v82 = v98.y - *((float *)&normalOutb + 1);
  v83 = (float)((float)(*((float *)mesha + 1) - *((float *)&normalOutb + 1))
              * (float)(v98.y - *((float *)&normalOutb + 1)))
      + (float)((float)(*(float *)mesha - *(float *)&normalOutb) * (float)(v98.x - *(float *)&normalOutb));
  if ( v83 <= 0.0 )
  {
    v84 = v73 >= 0.0;
  }
  else
  {
    v67 = 0;
    v84 = v73 > 0.0
       && (float)(v83
                / (float)(fsqrt((float)(v80 * v80) + (float)(v79 * v79)) * fsqrt((float)(v82 * v82) + (float)(v81 * v81)))) < v76;
  }
  v85 = 1;
  if ( m_nonconvexityThreshold != 0.0 )
  {
    if ( !v77
      && v66
      && heightPartitionThreshold.m_real.m128_f32[0] > (float)((float)((float)(v69 * v71) + (float)(v68 * v70))
                                                             / (float)(fsqrt((float)(v69 * v69) + (float)(v68 * v68))
                                                                     * fsqrt((float)(v71 * v71) + (float)(v70 * v70)))) )
    {
      v77 = 1;
    }
    if ( !v84
      && v67
      && heightPartitionThreshold.m_real.m128_f32[0] > (float)((float)((float)(v80 * v82) + (float)(v79 * v81))
                                                             / (float)(fsqrt((float)(v80 * v80) + (float)(v79 * v79))
                                                                     * fsqrt((float)(v82 * v82) + (float)(v81 * v81)))) )
    {
      v84 = 1;
    }
  }
  v86 = v77 && v84;
  verticesOut.m_size = 0;
  if ( verticesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      verticesOut.m_data,
      8 * verticesOut.m_capacityAndFlags);
  verticesOut.m_data = 0i64;
  verticesOut.m_capacityAndFlags = 0x80000000;
  verticesIn.m_size = 0;
  if ( verticesIn.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      verticesIn.m_data,
      16 * verticesIn.m_capacityAndFlags);
  if ( !v86 )
  {
LABEL_83:
    m_size = points.m_size;
    goto LABEL_85;
  }
  m_size = points.m_size;
LABEL_86:
  m_localMemory = points.m_localMemory;
  if ( points.m_localMemory == points.m_data )
    m_size = 0;
  points.m_size = m_size;
  v88 = (16 * points.m_initialCapacity + 127) & 0xFFFFFF80;
  v89 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v90 = (v88 + 15) & 0xFFFFFFF0;
  if ( v88 > v89->m_slabSize || (char *)m_localMemory + v90 != v89->m_cur || v89->m_firstNonLifoEnd == m_localMemory )
    hkLifoAllocator::slowBlockFree(v89, m_localMemory, v90);
  else
    v89->m_cur = m_localMemory;
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v85;
}

// File Line: 1408
// RVA: 0xB66430
hkResult *__fastcall hertelMehlhorn_doMerge(
        hkResult *result,
        hkResultEnum edgeIdx,
        hkaiNavMesh *mesh,
        hkArray<int,hkContainerTempAllocator> *facesToRemove,
        hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut)
{
  hkResultEnum m_enum; // r9d
  hkaiNavMesh::Edge *m_data; // r8
  __int64 v8; // r10
  hkaiNavMesh::Face *v10; // rdx
  int *p_m_startEdgeIndex; // rcx
  int m_startEdgeIndex; // r11d
  hkaiNavMesh::Face *v13; // rcx
  int m_startUserEdgeIndex; // eax
  int v15; // eax
  __int64 m_oppositeEdge; // rax
  int v17; // edi
  int v18; // r10d
  hkaiNavMesh::Edge *v19; // rax
  __int64 v20; // r8
  unsigned int v21; // esi
  unsigned int v22; // r14d
  int v23; // r15d
  int v24; // r12d
  int v25; // r8d
  int v26; // eax
  int v27; // r9d
  int v28; // ecx
  hkaiNavMesh::Edge *v29; // rdx
  char v30; // al
  __int16 v31; // ax
  int v32; // ecx
  int v33; // r9d
  __int64 m_edgeDataStriding; // r9
  int *v35; // rdx
  int *v36; // r8
  __int64 v37; // rcx
  signed __int64 v38; // r8
  int v39; // eax
  hkaiNavMesh::Edge *v40; // rdx
  __int64 v41; // rax
  hkResultEnum v42; // r10d
  int v43; // r11d
  hkResultEnum v44; // r9d
  __int32 v45; // edi
  hkaiNavMesh::Edge *v46; // rax
  unsigned int v47; // esi
  unsigned int m_oppositeFace; // r14d
  int v49; // r15d
  int v50; // r12d
  __int64 v51; // r8
  int v52; // r8d
  int v53; // eax
  int v54; // r9d
  int v55; // ecx
  hkaiNavMesh::Edge *v56; // rdx
  char v57; // al
  __int16 v58; // ax
  int v59; // ecx
  int v60; // r9d
  __int64 v61; // r9
  int *v62; // rax
  int *v63; // r8
  __int64 v64; // rdx
  signed __int64 v65; // r8
  int v66; // ecx
  hkaiNavMesh::Edge *v67; // rdx
  __int64 v68; // rax
  _DWORD *v69; // rdi
  int v70; // r9d
  int v71; // eax
  int v72; // eax
  __int64 m_size; // rsi
  hkaiNavMesh::Face *v74; // rax
  __int64 v75; // r14
  __int64 v76; // rdi
  __int64 m_faceDataStriding; // rdx
  int v78; // r8d
  __int64 v79; // rdx
  hkaiNavMesh::Edge *v80; // r8
  __int64 v81; // rax
  __int64 v82; // rcx
  hkArray<int,hkContainerHeapAllocator> *v83; // rbx
  int v84; // r9d
  int v85; // eax
  int v86; // eax
  int *edgeData; // [rsp+30h] [rbp-71h] BYREF
  int v89; // [rsp+38h] [rbp-69h]
  int v90; // [rsp+3Ch] [rbp-65h]
  hkaiNavMesh::Edge *array; // [rsp+40h] [rbp-61h] BYREF
  int n; // [rsp+48h] [rbp-59h]
  int v93; // [rsp+4Ch] [rbp-55h]
  hkResult resulta; // [rsp+50h] [rbp-51h] BYREF
  hkResult v95; // [rsp+54h] [rbp-4Dh] BYREF
  int v96; // [rsp+58h] [rbp-49h]
  int v97; // [rsp+5Ch] [rbp-45h]
  int m_a; // [rsp+60h] [rbp-41h]
  int m_b; // [rsp+64h] [rbp-3Dh]
  unsigned __int64 v100; // [rsp+68h] [rbp-39h]
  int v101; // [rsp+70h] [rbp-31h]
  int v102; // [rsp+78h] [rbp-29h]
  __int64 v103; // [rsp+80h] [rbp-21h]
  int v104; // [rsp+88h] [rbp-19h]
  int v105; // [rsp+8Ch] [rbp-15h]
  unsigned int v106; // [rsp+90h] [rbp-11h]
  __int64 v107; // [rsp+98h] [rbp-9h]
  __int64 v108; // [rsp+A0h] [rbp-1h]
  int v109; // [rsp+ACh] [rbp+Bh]
  int v110; // [rsp+B0h] [rbp+Fh]
  int v111; // [rsp+B4h] [rbp+13h]
  hkResult v112; // [rsp+108h] [rbp+67h] BYREF
  hkResult v113; // [rsp+110h] [rbp+6Fh] BYREF
  void *v114; // [rsp+118h] [rbp+77h]

  v114 = facesToRemove;
  v112.m_enum = edgeIdx;
  m_enum = edgeIdx;
  m_data = mesh->m_edges.m_data;
  v8 = edgeIdx;
  v113.m_enum = m_data[edgeIdx].m_oppositeEdge & 0x3FFFFF;
  m_a = m_data[v113.m_enum].m_a;
  m_b = m_data[v113.m_enum].m_b;
  v100 = *(_QWORD *)&m_data[v113.m_enum].m_oppositeEdge;
  v10 = mesh->m_faces.m_data;
  v101 = *(_DWORD *)&m_data[v113.m_enum].m_flags.m_storage;
  v106 = m_data[v8].m_oppositeFace & 0x3FFFFF;
  p_m_startEdgeIndex = &v10[v106].m_startEdgeIndex;
  v96 = *p_m_startEdgeIndex;
  v109 = p_m_startEdgeIndex[1];
  v110 = p_m_startEdgeIndex[2];
  v111 = p_m_startEdgeIndex[3];
  v107 = HIDWORD(v100) & 0x3FFFFF;
  v108 = (int)v107;
  m_startEdgeIndex = v10[(int)v107].m_startEdgeIndex;
  v13 = &v10[(int)v107];
  m_startUserEdgeIndex = v13->m_startUserEdgeIndex;
  v97 = m_startEdgeIndex;
  HIDWORD(v103) = m_startUserEdgeIndex;
  v104 = *(_DWORD *)&v13->m_numEdges;
  v15 = *(_DWORD *)&v13->m_clusterIndex;
  array = 0i64;
  n = 0;
  v93 = 0x80000000;
  edgeData = 0i64;
  v105 = v15;
  v89 = 0;
  v90 = 0x80000000;
  m_oppositeEdge = (int)m_data[v8].m_oppositeEdge;
  if ( (_DWORD)m_oppositeEdge != -1 )
  {
    m_data[m_oppositeEdge].m_oppositeEdge = -1;
    mesh->m_edges.m_data[m_data[v8].m_oppositeEdge].m_oppositeFace = -1;
  }
  *(_QWORD *)&m_data[v8].m_oppositeEdge = -1i64;
  v17 = m_enum + 1;
  v18 = m_startEdgeIndex + (__int16)v104;
  if ( m_enum + 1 == v18 )
    v17 = m_startEdgeIndex;
  v102 = m_startEdgeIndex + (__int16)v104;
  while ( v17 != m_enum )
  {
    v19 = mesh->m_edges.m_data;
    v20 = 20i64 * v17;
    v103 = v20;
    v21 = *(unsigned int *)((char *)&v19->m_oppositeEdge + v20);
    v22 = *(unsigned int *)((char *)&v19->m_oppositeFace + v20);
    v23 = *(int *)((char *)&v19->m_a + v20);
    v24 = *(int *)((char *)&v19->m_b + v20);
    LODWORD(v19) = *(_DWORD *)(&v19->m_flags.m_storage + v20);
    v100 = __PAIR64__(v22, v21);
    v101 = (int)v19;
    if ( v22 == -1 || (v22 & 0x3FFFFF) != v106 )
    {
      v25 = n;
      v26 = v93;
      v27 = n + 1;
      v28 = v93 & 0x3FFFFFFF;
      if ( (v93 & 0x3FFFFFFF) >= n + 1 )
      {
        resulta.m_enum = HK_SUCCESS;
      }
      else
      {
        if ( v27 < 2 * v28 )
          v27 = 2 * v28;
        hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v27, 20);
        if ( resulta.m_enum )
        {
LABEL_37:
          result->m_enum = HK_FAILURE;
          goto LABEL_101;
        }
        v26 = v93;
        v25 = n;
      }
      if ( v25 == (v26 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 20);
        v25 = n;
      }
      n = v25 + 1;
      v29 = &array[v25];
      v29->m_flags.m_storage = v101;
      v30 = BYTE1(v101);
      v29->m_a = v23;
      v29->m_paddingByte = v30;
      v31 = HIWORD(v101);
      v29->m_b = v24;
      v29->m_oppositeEdge = v21;
      v29->m_oppositeFace = v22;
      v29->m_userEdgeCost.m_value = v31;
      v32 = v89;
      v33 = v89 + mesh->m_edgeDataStriding;
      if ( (v90 & 0x3FFFFFFF) >= v33 )
      {
        v95.m_enum = HK_SUCCESS;
      }
      else
      {
        if ( v33 < 2 * (v90 & 0x3FFFFFFF) )
          v33 = 2 * (v90 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v95, &hkContainerTempAllocator::s_alloc, &edgeData, v33, 4);
        if ( v95.m_enum )
          goto LABEL_76;
        v32 = v89;
      }
      m_edgeDataStriding = mesh->m_edgeDataStriding;
      v89 = m_edgeDataStriding + v32;
      v35 = &edgeData[v32];
      if ( (_DWORD)m_edgeDataStriding )
        v36 = &mesh->m_edgeData.m_data[v17 * (int)m_edgeDataStriding];
      else
        v36 = 0i64;
      if ( (_DWORD)m_edgeDataStriding == 1 )
      {
        *v35 = *v36;
      }
      else
      {
        v37 = m_edgeDataStriding;
        if ( m_edgeDataStriding >= 1 )
        {
          v38 = (char *)v36 - (char *)v35;
          do
          {
            v39 = *(int *)((char *)v35++ + v38);
            *(v35 - 1) = v39;
            --v37;
          }
          while ( v37 );
        }
      }
      v20 = v103;
      m_enum = v112.m_enum;
      m_startEdgeIndex = v97;
      v18 = v102;
    }
    v40 = mesh->m_edges.m_data;
    v41 = *(int *)((char *)&v40->m_oppositeEdge + v20);
    if ( (_DWORD)v41 != -1 )
    {
      v40[v41].m_oppositeEdge = -1;
      mesh->m_edges.m_data[*(int *)((char *)&v40->m_oppositeEdge + v20)].m_oppositeFace = -1;
    }
    *(_QWORD *)((char *)&v40->m_oppositeEdge + v20) = -1i64;
    if ( ++v17 == v18 )
      v17 = m_startEdgeIndex;
  }
  v42 = v113.m_enum;
  v43 = v96;
  v44 = v96 + (__int16)v110;
  v45 = v113.m_enum + 1;
  v112.m_enum = v44;
  if ( v113.m_enum + 1 == v44 )
    v45 = v96;
  if ( v45 != v113.m_enum )
  {
    do
    {
      v46 = mesh->m_edges.m_data;
      v47 = v46[v45].m_oppositeEdge;
      m_oppositeFace = v46[v45].m_oppositeFace;
      v49 = v46[v45].m_a;
      v50 = v46[v45].m_b;
      v51 = 20i64 * v45;
      v101 = *(_DWORD *)(&v46->m_flags.m_storage + v51);
      v100 = __PAIR64__(m_oppositeFace, v47);
      v103 = v51;
      if ( m_oppositeFace == -1 || (m_oppositeFace & 0x3FFFFF) != (_DWORD)v107 )
      {
        v52 = n;
        v53 = v93;
        v54 = n + 1;
        v55 = v93 & 0x3FFFFFFF;
        if ( (v93 & 0x3FFFFFFF) >= n + 1 )
        {
          v95.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v54 < 2 * v55 )
            v54 = 2 * v55;
          hkArrayUtil::_reserve(&v95, &hkContainerTempAllocator::s_alloc, &array, v54, 20);
          if ( v95.m_enum )
            goto LABEL_37;
          v53 = v93;
          v52 = n;
        }
        if ( v52 == (v53 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 20);
          v52 = n;
        }
        n = v52 + 1;
        v56 = &array[v52];
        v56->m_flags.m_storage = v101;
        v57 = BYTE1(v101);
        v56->m_a = v49;
        v56->m_paddingByte = v57;
        v58 = HIWORD(v101);
        v56->m_b = v50;
        v56->m_oppositeEdge = v47;
        v56->m_oppositeFace = m_oppositeFace;
        v56->m_userEdgeCost.m_value = v58;
        v59 = v89;
        v60 = v89 + mesh->m_edgeDataStriding;
        if ( (v90 & 0x3FFFFFFF) >= v60 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v60 < 2 * (v90 & 0x3FFFFFFF) )
            v60 = 2 * (v90 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &edgeData, v60, 4);
          if ( resulta.m_enum )
            goto LABEL_76;
          v59 = v89;
        }
        v61 = mesh->m_edgeDataStriding;
        v89 = v61 + v59;
        v62 = &edgeData[v59];
        if ( (_DWORD)v61 )
          v63 = &mesh->m_edgeData.m_data[v45 * (int)v61];
        else
          v63 = 0i64;
        if ( (_DWORD)v61 == 1 )
        {
          *v62 = *v63;
        }
        else
        {
          v64 = v61;
          if ( v61 >= 1 )
          {
            v65 = (char *)v63 - (char *)v62;
            do
            {
              v66 = *(int *)((char *)v62++ + v65);
              *(v62 - 1) = v66;
              --v64;
            }
            while ( v64 );
          }
        }
        v51 = v103;
        v44 = v112.m_enum;
        v42 = v113.m_enum;
        v43 = v96;
      }
      v67 = mesh->m_edges.m_data;
      v68 = *(int *)((char *)&v67->m_oppositeEdge + v51);
      if ( (_DWORD)v68 != -1 )
      {
        v67[v68].m_oppositeEdge = -1;
        mesh->m_edges.m_data[*(int *)((char *)&v67->m_oppositeEdge + v51)].m_oppositeFace = -1;
      }
      *(_QWORD *)((char *)&v67->m_oppositeEdge + v51) = -1i64;
      if ( ++v45 == v44 )
        v45 = v43;
    }
    while ( v45 != v42 );
  }
  v69 = v114;
  v70 = *((_DWORD *)v114 + 2) + 2;
  v71 = *((_DWORD *)v114 + 3) & 0x3FFFFFFF;
  if ( v71 < v70 )
  {
    v72 = 2 * v71;
    if ( v70 < v72 )
      v70 = v72;
    hkArrayUtil::_reserve(&v112, &hkContainerTempAllocator::s_alloc, v114, v70, 4);
    if ( v112.m_enum )
    {
LABEL_76:
      result->m_enum = HK_FAILURE;
      goto LABEL_101;
    }
  }
  *(_DWORD *)(*(_QWORD *)v69 + 4i64 * (int)v69[2]++) = v107;
  *(_DWORD *)(*(_QWORD *)v69 + 4i64 * (int)v69[2]++) = v106;
  if ( n > 2 )
  {
    m_size = mesh->m_faces.m_size;
    v74 = hkaiNavMesh::expandFacesBy(mesh, 1, -1);
    if ( !v74 )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_101;
    }
    v75 = v108;
    v74->m_startEdgeIndex = -1;
    *(_QWORD *)&v74->m_startUserEdgeIndex = 0xFFFFFFFFi64;
    v74->m_clusterIndex = -1;
    v74->m_padding = -12851;
    v76 = mesh->m_edges.m_size;
    v74->m_startEdgeIndex = v76;
    v74->m_numEdges = n;
    m_faceDataStriding = mesh->m_faceDataStriding;
    if ( (_DWORD)m_faceDataStriding )
      v78 = mesh->m_faceData.m_data[v75 * m_faceDataStriding];
    else
      v78 = 0;
    if ( (_DWORD)m_faceDataStriding )
      mesh->m_faceData.m_data[m_size * m_faceDataStriding] = v78;
    hkaiNavMesh::appendEdges(mesh, &v113, array, edgeData, n);
    if ( v113.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_101;
    }
    if ( (int)v76 < mesh->m_edges.m_size )
    {
      v79 = v76;
      do
      {
        v80 = mesh->m_edges.m_data;
        v81 = (int)v80[v79].m_oppositeEdge;
        if ( (_DWORD)v81 != -1 )
        {
          v82 = v81;
          v80[v82].m_oppositeFace = m_size;
          v80[v82].m_oppositeEdge = v76;
        }
        LODWORD(v76) = v76 + 1;
        ++v79;
      }
      while ( (int)v76 < mesh->m_edges.m_size );
    }
    v83 = faceToPartitionMapInOut;
    if ( faceToPartitionMapInOut )
    {
      v84 = faceToPartitionMapInOut->m_size + 1;
      v85 = faceToPartitionMapInOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v85 >= v84 )
      {
        v112.m_enum = HK_SUCCESS;
      }
      else
      {
        v86 = 2 * v85;
        if ( v84 < v86 )
          v84 = v86;
        hkArrayUtil::_reserve(&v112, &hkContainerHeapAllocator::s_alloc, faceToPartitionMapInOut, v84, 4);
        if ( v112.m_enum )
        {
          result->m_enum = HK_FAILURE;
          goto LABEL_101;
        }
      }
      v83->m_data[v83->m_size++] = v83->m_data[v75];
    }
  }
  result->m_enum = HK_SUCCESS;
LABEL_101:
  v89 = 0;
  if ( v90 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, edgeData, 4 * v90);
  edgeData = 0i64;
  v90 = 0x80000000;
  n = 0;
  if ( v93 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 20 * (v93 & 0x3FFFFFFF));
  return result;
}

// File Line: 1529
// RVA: 0xB629C0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::hertelMehlhorn(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *mesh,
        float *heightErrorOverride,
        hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut)
{
  float *v5; // rax
  hkResult *v8; // r12
  int v9; // esi
  __int64 v10; // rdi
  hkaiNavMeshGenerationSettings::OverrideSettings *v11; // rax
  hkArray<int,hkContainerHeapAllocator> *v12; // r13
  int m_size; // r9d
  int v14; // r10d
  int v16; // esi
  __int64 v17; // rdi
  hkaiNavMesh::Edge *m_data; // rcx
  unsigned int m_oppositeEdge; // edx
  __int64 m_a; // r14
  __int64 m_b; // r12
  hkVector4f *v22; // rdx
  LongestEdge *v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  char v28; // r12
  int v29; // edi
  __int64 v30; // rsi
  int index; // r14d
  unsigned int canMerge; // eax
  int v33; // r8d
  int v34; // r8d
  hkArray<int,hkContainerHeapAllocator> *v35; // rsi
  char v36; // r14
  int v37; // edi
  unsigned int v38; // eax
  int m_capacityAndFlags; // r8d
  hkResult memoryRes; // [rsp+40h] [rbp-41h] BYREF
  hkResult v41; // [rsp+44h] [rbp-3Dh] BYREF
  hkResult v42; // [rsp+48h] [rbp-39h] BYREF
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+50h] [rbp-31h] BYREF
  LongestEdge *array; // [rsp+60h] [rbp-21h] BYREF
  int v45; // [rsp+68h] [rbp-19h]
  int v46; // [rsp+6Ch] [rbp-15h]
  AMD_HD3D v47; // [rsp+70h] [rbp-11h] BYREF
  int v48; // [rsp+90h] [rbp+Fh]
  hkResult resulta; // [rsp+E8h] [rbp+67h] BYREF
  float *heightErrorOverridea; // [rsp+F8h] [rbp+77h]

  heightErrorOverridea = heightErrorOverride;
  v5 = heightErrorOverride;
  v8 = result;
  v47.mHeight = -1;
  *(_QWORD *)&v47.mEnableStereo = 0i64;
  v47.mWidth = 0;
  v9 = 0;
  if ( settings->m_overrideSettings.m_size <= 0 )
  {
LABEL_7:
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 0x80000000;
    if ( settings->m_simplificationSettings.m_mergeLongestEdgesFirst.m_bool )
    {
      v12 = faceToPartitionMapInOut;
      while ( 1 )
      {
        m_size = mesh->m_edges.m_size;
        array = 0i64;
        v14 = 0;
        v45 = 0;
        v46 = 0x80000000;
        if ( m_size <= 0 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 32);
          if ( resulta.m_enum )
          {
            v8 = result;
            v33 = v46;
            v45 = 0;
            result->m_enum = HK_FAILURE;
            if ( v33 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v33);
            array = 0i64;
            v46 = 0x80000000;
            goto LABEL_56;
          }
          v14 = v45;
        }
        v16 = 0;
        if ( mesh->m_edges.m_size > 0 )
        {
          v17 = 0i64;
          do
          {
            m_data = mesh->m_edges.m_data;
            m_oppositeEdge = m_data[v17].m_oppositeEdge;
            m_a = m_data[v17].m_a;
            m_b = m_data[v17].m_b;
            HIDWORD(v47.mExtension) = m_data[v17].m_oppositeFace;
            v48 = *(_DWORD *)&m_data[v17].m_flags.m_storage;
            if ( m_oppositeEdge != -1 && v16 < (int)(m_oppositeEdge & 0x3FFFFF) )
            {
              if ( v14 == (v46 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 32);
                v14 = v45;
              }
              v22 = mesh->m_vertices.m_data;
              v23 = &array[v14];
              v45 = v14 + 1;
              v24 = _mm_sub_ps(v22[m_a].m_quad, v22[m_b].m_quad);
              v23->index = v16;
              v25 = _mm_mul_ps(v24, v24);
              v26 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                      _mm_shuffle_ps(v25, v25, 170));
              v27 = _mm_rsqrt_ps(v26);
              v23->length.m_real = _mm_andnot_ps(
                                     _mm_cmple_ps(v26, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v27)),
                                       v26));
              v14 = v45;
            }
            ++v16;
            ++v17;
          }
          while ( v16 < mesh->m_edges.m_size );
        }
        if ( v14 > 1 )
        {
          hkAlgorithm::quickSortRecursive<LongestEdge,hkAlgorithm::less<LongestEdge>>(array, 0, v14 - 1, 0);
          v14 = v45;
        }
        v28 = 0;
        v29 = 0;
        if ( v14 > 0 )
          break;
LABEL_30:
        v45 = 0;
        if ( v46 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v46);
        array = 0i64;
        v46 = 0x80000000;
        if ( !v28 )
        {
          v8 = result;
          goto LABEL_53;
        }
      }
      v30 = 0i64;
      while ( 1 )
      {
        index = array[v30].index;
        canMerge = hertelMehlhorn_canMerge(
                     index,
                     settings,
                     mesh,
                     heightErrorOverridea,
                     (hkPointerMap<int,int,hkContainerHeapAllocator> *)&v47,
                     v12,
                     &memoryRes);
        if ( memoryRes.m_enum )
          break;
        if ( canMerge )
        {
          v28 = 1;
          hertelMehlhorn_doMerge(&v41, index, mesh, &facesToRemove, v12);
          if ( v41.m_enum )
            break;
        }
        ++v29;
        ++v30;
        if ( v29 >= v45 )
          goto LABEL_30;
      }
      v34 = v46;
      result->m_enum = HK_FAILURE;
      v45 = 0;
      if ( v34 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v34);
      facesToRemove.m_size = 0;
      v46 = 0x80000000;
      array = 0i64;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          facesToRemove.m_data,
          4 * facesToRemove.m_capacityAndFlags);
      facesToRemove.m_data = 0i64;
      facesToRemove.m_capacityAndFlags = 0x80000000;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v47,
        &hkContainerHeapAllocator::s_alloc);
      _(&v47);
      return result;
    }
    else
    {
      v35 = faceToPartitionMapInOut;
      do
      {
        v36 = 0;
        v37 = 0;
        if ( mesh->m_edges.m_size <= 0 )
          break;
        do
        {
          v38 = hertelMehlhorn_canMerge(
                  v37,
                  settings,
                  mesh,
                  v5,
                  (hkPointerMap<int,int,hkContainerHeapAllocator> *)&v47,
                  v35,
                  &resulta);
          if ( resulta.m_enum
            || v38 && (v36 = 1, hertelMehlhorn_doMerge(&v41, v37, mesh, &facesToRemove, v35), v41.m_enum) )
          {
            m_capacityAndFlags = facesToRemove.m_capacityAndFlags;
            v8->m_enum = HK_FAILURE;
            facesToRemove.m_size = 0;
            if ( m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                facesToRemove.m_data,
                4 * m_capacityAndFlags);
            facesToRemove.m_data = 0i64;
            goto LABEL_59;
          }
          v5 = heightErrorOverridea;
          ++v37;
        }
        while ( v37 < mesh->m_edges.m_size );
      }
      while ( v36 );
LABEL_53:
      hkaiNavMeshUtils::removeFaces(&v42, mesh, &facesToRemove, 0);
      if ( v42.m_enum )
        v8->m_enum = HK_FAILURE;
      else
        v8->m_enum = HK_SUCCESS;
LABEL_56:
      facesToRemove.m_size = 0;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          facesToRemove.m_data,
          4 * facesToRemove.m_capacityAndFlags);
      facesToRemove.m_data = 0i64;
LABEL_59:
      facesToRemove.m_capacityAndFlags = 0x80000000;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v47,
        &hkContainerHeapAllocator::s_alloc);
      _(&v47);
      return v8;
    }
  }
  else
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = settings->m_overrideSettings.m_data;
      if ( !v11[v10].m_volume.m_pntr )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v47,
          &hkContainerHeapAllocator::s_alloc,
          v11[v10].m_material,
          v9,
          &resulta);
        if ( resulta.m_enum )
          break;
      }
      ++v9;
      ++v10;
      if ( v9 >= settings->m_overrideSettings.m_size )
      {
        v5 = heightErrorOverridea;
        goto LABEL_7;
      }
    }
    v8->m_enum = HK_FAILURE;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v47,
      &hkContainerHeapAllocator::s_alloc);
    _(&v47);
    return v8;
  }
}

