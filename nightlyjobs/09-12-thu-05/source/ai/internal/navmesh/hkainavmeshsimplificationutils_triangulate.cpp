// File Line: 49
// RVA: 0xB5F920
hkResult *__fastcall hkaiNavMeshSimplificationUtils::triangulatePartitions(hkResult *result, hkaiNavMeshGenerationSettings *settings, bool wallClimbing, hkaiNavMesh *originalMesh, hkaiNavMesh *navMeshOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, hkArrayBase<int> *partitions, hkArrayBase<int> *numFacesInPartition, hkArrayBase<int> *partitionDir, hkArray<int,hkContainerHeapAllocator> *faceToPartitionMap, hkBitField *edgeIsBoundary, hkBitField *userVertexOnBoundary, hkArrayBase<unsigned int> *faceData)
{
  signed int v13; // esi
  int *v14; // rdi
  bool v15; // r14
  int v16; // ebx
  __int64 v17; // rsi
  __int128 *v18; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v19; // r14
  __m128i v20; // xmm3
  __m128 v21; // xmm3
  __int64 v22; // rcx
  __m128 v23; // xmm3
  __int64 v24; // rax
  int v25; // esi
  signed int v26; // er12
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v27; // r13
  int v28; // ebx
  int v29; // er9
  int v30; // er8
  char *v31; // rbx
  int v32; // er8
  _QWORD *v33; // rdx
  __int64 v34; // rcx
  __int64 v35; // rax
  __int64 v36; // rcx
  _QWORD *v37; // rdx
  __int64 v38; // rcx
  __int64 v39; // rax
  __int64 v40; // rcx
  _QWORD *v41; // rdx
  __int64 v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rcx
  _QWORD *v45; // rdx
  __int64 v46; // rcx
  __int64 v47; // rax
  __int64 v48; // rcx
  int v49; // er8
  __int64 v50; // rdx
  __int64 v51; // r9
  hkArrayBase<int> *v52; // r15
  __int64 v53; // rbx
  int v54; // edx
  __int64 v55; // rdi
  signed __int64 v56; // r14
  int v57; // ecx
  int v58; // eax
  hkaiNavMeshSimplificationUtils::SegmentIdxPid *v59; // r8
  int v60; // er9
  int v61; // ecx
  int v62; // ebx
  __int128 *v63; // rax
  __m128i v64; // xmm0
  int *v65; // rax
  __int64 v66; // rcx
  int v67; // er15
  int *v68; // rax
  signed int v69; // er15
  int *v70; // r12
  __int64 v71; // r14
  int v72; // edi
  hkaiNavMesh::Face *v73; // rax
  hkaiNavMesh::Face *v74; // rsi
  int *v75; // r12
  unsigned __int64 v76; // r13
  hkaiNavMesh::Edge *v77; // rax
  hkaiNavMesh::Edge *v78; // rbx
  hkArray<int,hkContainerHeapAllocator> *v79; // rdx
  int v80; // er9
  int v81; // eax
  int v82; // eax
  __int64 v83; // rcx
  __int64 v84; // r8
  hkResultEnum v85; // eax
  __int64 v86; // r14
  signed __int64 v87; // rsi
  __int64 v88; // r15
  __int64 v89; // rcx
  signed __int64 v90; // r11
  signed __int64 v91; // r9
  signed __int64 v92; // r8
  signed __int64 v93; // rcx
  signed __int64 v94; // r10
  __int64 v95; // rax
  int *v96; // rax
  __int64 v97; // r14
  int *v98; // rax
  int v99; // er8
  char *v100; // rbx
  signed int v101; // er12
  int v102; // er8
  _QWORD *v103; // rdx
  __int64 v104; // rcx
  __int64 v105; // rax
  __int64 v106; // rcx
  _QWORD *v107; // rdx
  __int64 v108; // rcx
  __int64 v109; // rax
  __int64 v110; // rcx
  _QWORD *v111; // rdx
  __int64 v112; // rcx
  __int64 v113; // rax
  __int64 v114; // rcx
  _QWORD *v115; // rdx
  __int64 v116; // rcx
  __int64 v117; // rax
  __int64 v118; // rcx
  char *v119; // rdi
  signed int v120; // er15
  int v121; // er8
  char *v122; // rdi
  signed int v123; // er15
  int v124; // er8
  char *v125; // rdi
  signed int v126; // er15
  int v127; // er8
  int v128; // er8
  char *v129; // rbx
  int v130; // er8
  char *v132; // rdi
  signed int v133; // er15
  int v134; // er8
  hkaiNavMeshSimplificationUtils::SegmentIdxPid *array; // [rsp+70h] [rbp-90h]
  int v136; // [rsp+78h] [rbp-88h]
  int v137; // [rsp+7Ch] [rbp-84h]
  hkArray<int,hkContainerTempAllocator> partitionSegments; // [rsp+80h] [rbp-80h]
  hkVector4f dmin; // [rsp+90h] [rbp-70h]
  hkArray<int,hkContainerTempAllocator> triangleIndicesOut; // [rsp+A0h] [rbp-60h]
  hkResult v141; // [rsp+B0h] [rbp-50h]
  int v142; // [rsp+B4h] [rbp-4Ch]
  int v143; // [rsp+B8h] [rbp-48h]
  hkVector4f dmax; // [rsp+C0h] [rbp-40h]
  int v145; // [rsp+D0h] [rbp-30h]
  hkResult v146; // [rsp+D4h] [rbp-2Ch]
  hkResult v147; // [rsp+D8h] [rbp-28h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings v148; // [rsp+E0h] [rbp-20h]
  hkResult v149; // [rsp+118h] [rbp+18h]
  int v150; // [rsp+11Ch] [rbp+1Ch]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings; // [rsp+120h] [rbp+20h]
  __int64 v152; // [rsp+128h] [rbp+28h]
  int *v153; // [rsp+130h] [rbp+30h]
  __int64 v154; // [rsp+138h] [rbp+38h]
  __int64 v155; // [rsp+140h] [rbp+40h]
  __int64 v156; // [rsp+148h] [rbp+48h]
  __int128 *v157; // [rsp+150h] [rbp+50h]
  int v158; // [rsp+158h] [rbp+58h]
  int v159; // [rsp+15Ch] [rbp+5Ch]
  __int128 v160; // [rsp+160h] [rbp+60h]
  __int128 v161; // [rsp+170h] [rbp+70h]
  __int64 v162; // [rsp+188h] [rbp+88h]
  hkVector4f resulta; // [rsp+190h] [rbp+90h]
  __int128 v164; // [rsp+1A0h] [rbp+A0h]
  hkVector4f v165; // [rsp+1B0h] [rbp+B0h]
  __int128 v166; // [rsp+1C0h] [rbp+C0h]
  __int128 v167; // [rsp+1D0h] [rbp+D0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> v168[6]; // [rsp+280h] [rbp+180h]
  char v169; // [rsp+5040h] [rbp+4F40h]
  char v170; // [rsp+507Ch] [rbp+4F7Ch]
  hkResult *v171; // [rsp+5090h] [rbp+4F90h]
  hkaiNavMeshGenerationSettings *v172; // [rsp+5098h] [rbp+4F98h]
  bool v173; // [rsp+50A0h] [rbp+4FA0h]
  hkaiNavMesh *originalMesha; // [rsp+50A8h] [rbp+4FA8h]

  originalMesha = originalMesh;
  v173 = wallClimbing;
  v172 = settings;
  v171 = result;
  v13 = 5;
  v14 = &v168[0].m_mesh.m_vertices.m_numUsed;
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  do
  {
    *(v14 - 10) = 0x1FFFF;
    *((_QWORD *)v14 - 6) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
    *(v14 - 6) = 0x1FFFF;
    *((_QWORD *)v14 - 4) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
    *((_QWORD *)v14 - 2) = 0i64;
    *((_QWORD *)v14 - 1) = 0i64;
    *v14 = 0;
    *((_QWORD *)v14 + 1) = 0i64;
    *((_QWORD *)v14 + 2) = 0i64;
    v14[6] = 0;
    v14[10] = 0;
    *((_QWORD *)v14 + 4) = v14 + 12;
    v14[11] = -2147483584;
    `vector constructor iterator'(v14 + 12, 0x10ui64, 64, (void *(__fastcall *)(void *))Assembly::GetRCX);
    *((_BYTE *)v14 + 3132) = 0;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v14 - 12),
      &dmin,
      &dmax,
      0.0,
      1);
    --v13;
    v14 += 828;
  }
  while ( v13 >= 0 );
  v15 = v173;
  v158 = 2;
  v160 = _xmm_c4fa0000c4fa0000c4fa0000c4fa0000;
  v161 = _xmm;
  v157 = &v160;
  v159 = -2147483646;
  dmax.m_quad.m128_i32[3] = 16;
  if ( v173 )
  {
    v16 = 0;
    v17 = 0i64;
    v18 = &v167;
    v19 = v168;
    do
    {
      dmin.m_quad = hkaiNavMeshSimplificationUtils::_classToDir(&resulta, v16)->m_quad;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)v157;
      dmax.m_quad.m128_i32[2] = v158;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        v19,
        (hkStridedVertices *)&dmax,
        &dmin,
        0,
        1,
        0);
      ++v16;
      v20 = _mm_load_si128((const __m128i *)&dmin);
      *(v18 - 1) = _xmm_c4f98000c4f98000c4f98000c4f98000;
      *v18 = _xmm;
      ++v19;
      v18 += 2;
      v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v20, 1u), 1u);
      v22 = v17
          + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                   _mm_and_ps(
                                                                     _mm_cmpleps(
                                                                       _mm_max_ps(
                                                                         _mm_shuffle_ps(v21, v21, 170),
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v21, v21, 85),
                                                                           _mm_shuffle_ps(v21, v21, 0))),
                                                                       v21),
                                                                     (__m128)xmmword_141A4CDC0))];
      v17 += 8i64;
      *((_DWORD *)&v166 + v22) = -8388626;
      *((_DWORD *)&v167 + v22) = 2139095022;
    }
    while ( v16 < 6 );
    v15 = v173;
  }
  else
  {
    dmax.m_quad.m128_u64[0] = (unsigned __int64)&v160;
    dmax.m_quad.m128_i32[2] = 2;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
      v168,
      (hkStridedVertices *)&dmax,
      &v172->m_up,
      0,
      1,
      0);
    v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v172->m_up), 1u), 1u);
    v167 = _xmm;
    v166 = _xmm_c4f98000c4f98000c4f98000c4f98000;
    v24 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v23, v23, 170),
                                                                       _mm_max_ps(
                                                                         _mm_shuffle_ps(v23, v23, 85),
                                                                         _mm_shuffle_ps(v23, v23, 0))),
                                                                     v23),
                                                                   (__m128)xmmword_141A4CDC0))];
    *((_DWORD *)&v166 + v24) = -8388626;
    *((_DWORD *)&v167 + v24) = 2139095022;
  }
  v25 = 0;
  v158 = 0;
  v26 = 5;
  if ( v159 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v157,
      16 * v159);
  v27 = segments;
  array = 0i64;
  v136 = 0;
  v28 = segments->m_size;
  v137 = 2147483648;
  if ( v28 <= 0 )
  {
    v141.m_enum = 0;
  }
  else
  {
    v29 = v28;
    if ( v28 < 0 )
      v29 = 0;
    hkArrayUtil::_reserve(&v141, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v29, 8);
    if ( v141.m_enum )
    {
      v30 = v137;
      v136 = 0;
      v171->m_enum = 1;
      if ( v30 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          8 * v30);
      array = 0i64;
      v137 = 2147483648;
      v31 = &v169;
      do
      {
        v31 -= 3312;
        *((_QWORD *)v31 - 4) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v31 - 32),
          1);
        v32 = *((_DWORD *)v31 + 15);
        *((_DWORD *)v31 + 14) = 0;
        if ( v32 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)*((_QWORD *)v31 + 6),
            16 * v32);
        *((_QWORD *)v31 + 6) = 0i64;
        *((_DWORD *)v31 + 15) = 2147483648;
        *((_QWORD *)v31 - 2) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
        while ( *((_QWORD *)v31 + 3) )
        {
          v33 = (_QWORD *)*((_QWORD *)v31 + 3);
          v34 = v33[833];
          v35 = v33[834];
          if ( v34 )
            *(_QWORD *)(v34 + 6672) = v35;
          else
            *((_QWORD *)v31 + 3) = v35;
          v36 = v33[834];
          if ( v36 )
            *(_QWORD *)(v36 + 6664) = v33[833];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v33,
            6688);
        }
        *((_QWORD *)v31 + 4) = 0i64;
        *((_DWORD *)v31 + 10) = 0;
        while ( *((_QWORD *)v31 + 3) )
        {
          v37 = (_QWORD *)*((_QWORD *)v31 + 3);
          v38 = v37[833];
          v39 = v37[834];
          if ( v38 )
            *(_QWORD *)(v38 + 6672) = v39;
          else
            *((_QWORD *)v31 + 3) = v39;
          v40 = v37[834];
          if ( v40 )
            *(_QWORD *)(v40 + 6664) = v37[833];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v37,
            6688);
        }
        while ( *(_QWORD *)v31 )
        {
          v41 = *(_QWORD **)v31;
          v42 = *(_QWORD *)(*(_QWORD *)v31 + 1544i64);
          v43 = *(_QWORD *)(*(_QWORD *)v31 + 1552i64);
          if ( v42 )
            *(_QWORD *)(v42 + 1552) = v43;
          else
            *(_QWORD *)v31 = v43;
          v44 = v41[194];
          if ( v44 )
            *(_QWORD *)(v44 + 1544) = v41[193];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v41,
            1568);
        }
        *((_QWORD *)v31 + 1) = 0i64;
        *((_DWORD *)v31 + 4) = 0;
        while ( *(_QWORD *)v31 )
        {
          v45 = *(_QWORD **)v31;
          v46 = *(_QWORD *)(*(_QWORD *)v31 + 1544i64);
          v47 = *(_QWORD *)(*(_QWORD *)v31 + 1552i64);
          if ( v46 )
            *(_QWORD *)(v46 + 1552) = v47;
          else
            *(_QWORD *)v31 = v47;
          v48 = v45[194];
          if ( v48 )
            *(_QWORD *)(v48 + 1544) = v45[193];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v45,
            1568);
        }
        --v26;
        *((_QWORD *)v31 - 2) = &hkBaseObject::`vftable';
        *((_QWORD *)v31 - 4) = &hkBaseObject::`vftable';
      }
      while ( v26 >= 0 );
      return v171;
    }
  }
  v136 = v28;
  v49 = 0;
  if ( segments->m_size > 0 )
  {
    v50 = 0i64;
    v51 = 0i64;
    do
    {
      ++v51;
      ++v50;
      array[v50 - 1].m_segmentIndex = v49++;
      *((_DWORD *)&array[v50] - 1) = *((_DWORD *)&segments->m_data[v51] - 11);
    }
    while ( v49 < segments->m_size );
    v28 = v136;
  }
  if ( v28 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavMeshSimplificationUtils::SegmentIdxPid,hkAlgorithm::less<hkaiNavMeshSimplificationUtils::SegmentIdxPid>>(
      array,
      0,
      v28 - 1,
      0);
  v52 = numFacesInPartition;
  v142 = 0;
  v53 = numFacesInPartition->m_size;
  v145 = 0;
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(&v148);
  if ( v15 )
  {
    v148.m_vertexFraction = 0.0;
    v148.m_minPartitionArea = FLOAT_3_40282e38;
    extraVertexSettings = &v148;
  }
  else
  {
    extraVertexSettings = &v172->m_simplificationSettings.m_extraVertexSettings;
  }
  v54 = 0;
  v55 = 0i64;
  v56 = 0i64;
  v156 = v53;
  v143 = 0;
  v154 = 0i64;
  v152 = 0i64;
  if ( (signed int)v53 <= 0 )
  {
LABEL_195:
    v128 = v148.m_userVertices.m_capacityAndFlags;
    v171->m_enum = 0;
    v148.m_userVertices.m_size = 0;
    if ( v128 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v148.m_userVertices.m_data,
        16 * v128);
    v148.m_userVertices.m_data = 0i64;
    v148.m_userVertices.m_capacityAndFlags = 2147483648;
    v136 = 0;
    if ( v137 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        8 * v137);
    array = 0i64;
    v137 = 2147483648;
    v129 = &v170;
    do
    {
      v129 -= 3312;
      *(_QWORD *)(v129 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v129 - 92),
        1);
      v130 = *(_DWORD *)v129;
      *((_DWORD *)v129 - 1) = 0;
      if ( v130 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v129 - 12),
          16 * v130);
      *(_QWORD *)(v129 - 12) = 0i64;
      *(_DWORD *)v129 = 2147483648;
      hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::~hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>((hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAl)(v129 - 76));
      --v26;
      *(_QWORD *)(v129 - 92) = &hkBaseObject::`vftable';
    }
    while ( v26 >= 0 );
  }
  else
  {
    while ( 1 )
    {
      v57 = 2147483648;
      v58 = 0;
      partitionSegments.m_data = 0i64;
      partitionSegments.m_capacityAndFlags = 2147483648;
      partitionSegments.m_size = 0;
      if ( v25 < v136 )
      {
        while ( 1 )
        {
          v59 = array;
          if ( array[v55].m_partitionId != v54 )
            break;
          v60 = v58 + 1;
          v61 = v57 & 0x3FFFFFFF;
          if ( v61 >= v58 + 1 )
          {
            v146.m_enum = 0;
          }
          else
          {
            if ( v60 < 2 * v61 )
              v60 = 2 * v61;
            hkArrayUtil::_reserve(
              &v146,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              &partitionSegments,
              v60,
              4);
            if ( v146.m_enum )
            {
              v99 = partitionSegments.m_capacityAndFlags;
              partitionSegments.m_size = 0;
              v171->m_enum = 1;
              if ( v99 >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  partitionSegments.m_data,
                  4 * v99);
              partitionSegments.m_data = 0i64;
              partitionSegments.m_capacityAndFlags = 2147483648;
              v148.m_userVertices.m_size = 0;
              if ( v148.m_userVertices.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v148.m_userVertices.m_data,
                  16 * v148.m_userVertices.m_capacityAndFlags);
              v148.m_userVertices.m_data = 0i64;
              v148.m_userVertices.m_capacityAndFlags = 2147483648;
              v136 = 0;
              if ( v137 >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  array,
                  8 * v137);
              array = 0i64;
              v137 = 2147483648;
              v100 = &v169;
              v101 = 5;
              do
              {
                v100 -= 3312;
                *((_QWORD *)v100 - 4) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
                hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
                  (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v100 - 32),
                  1);
                v102 = *((_DWORD *)v100 + 15);
                *((_DWORD *)v100 + 14) = 0;
                if ( v102 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    (void *)*((_QWORD *)v100 + 6),
                    16 * v102);
                *((_QWORD *)v100 + 6) = 0i64;
                *((_DWORD *)v100 + 15) = 2147483648;
                *((_QWORD *)v100 - 2) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
                while ( *((_QWORD *)v100 + 3) )
                {
                  v103 = (_QWORD *)*((_QWORD *)v100 + 3);
                  v104 = v103[833];
                  v105 = v103[834];
                  if ( v104 )
                    *(_QWORD *)(v104 + 6672) = v105;
                  else
                    *((_QWORD *)v100 + 3) = v105;
                  v106 = v103[834];
                  if ( v106 )
                    *(_QWORD *)(v106 + 6664) = v103[833];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v103,
                    6688);
                }
                *((_QWORD *)v100 + 4) = 0i64;
                *((_DWORD *)v100 + 10) = 0;
                while ( *((_QWORD *)v100 + 3) )
                {
                  v107 = (_QWORD *)*((_QWORD *)v100 + 3);
                  v108 = v107[833];
                  v109 = v107[834];
                  if ( v108 )
                    *(_QWORD *)(v108 + 6672) = v109;
                  else
                    *((_QWORD *)v100 + 3) = v109;
                  v110 = v107[834];
                  if ( v110 )
                    *(_QWORD *)(v110 + 6664) = v107[833];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v107,
                    6688);
                }
                while ( *(_QWORD *)v100 )
                {
                  v111 = *(_QWORD **)v100;
                  v112 = *(_QWORD *)(*(_QWORD *)v100 + 1544i64);
                  v113 = *(_QWORD *)(*(_QWORD *)v100 + 1552i64);
                  if ( v112 )
                    *(_QWORD *)(v112 + 1552) = v113;
                  else
                    *(_QWORD *)v100 = v113;
                  v114 = v111[194];
                  if ( v114 )
                    *(_QWORD *)(v114 + 1544) = v111[193];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v111,
                    1568);
                }
                *((_QWORD *)v100 + 1) = 0i64;
                *((_DWORD *)v100 + 4) = 0;
                while ( *(_QWORD *)v100 )
                {
                  v115 = *(_QWORD **)v100;
                  v116 = *(_QWORD *)(*(_QWORD *)v100 + 1544i64);
                  v117 = *(_QWORD *)(*(_QWORD *)v100 + 1552i64);
                  if ( v116 )
                    *(_QWORD *)(v116 + 1552) = v117;
                  else
                    *(_QWORD *)v100 = v117;
                  v118 = v115[194];
                  if ( v118 )
                    *(_QWORD *)(v118 + 1544) = v115[193];
                  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v115,
                    1568);
                }
                --v101;
                *((_QWORD *)v100 - 2) = &hkBaseObject::`vftable';
                *((_QWORD *)v100 - 4) = &hkBaseObject::`vftable';
              }
              while ( v101 >= 0 );
              return v171;
            }
            v59 = array;
            v58 = partitionSegments.m_size;
          }
          partitionSegments.m_data[v58] = v59[v55].m_segmentIndex;
          ++v25;
          ++v55;
          v58 = partitionSegments.m_size + 1;
          v145 = v25;
          ++partitionSegments.m_size;
          v154 = v55;
          if ( v25 >= v136 )
            break;
          v57 = partitionSegments.m_capacityAndFlags;
          v54 = v143;
        }
      }
      if ( v173 )
      {
        v62 = partitionDir->m_data[v56];
        v63 = (__int128 *)hkaiNavMeshSimplificationUtils::_classToDir(&v165, partitionDir->m_data[v56]);
      }
      else
      {
        v62 = 0;
        v63 = &v164;
        _mm_store_si128((__m128i *)&v164, (__m128i)v172->m_up.m_quad);
      }
      v64 = (__m128i)*v63;
      v65 = v52->m_data;
      v66 = v142;
      triangleIndicesOut.m_data = 0i64;
      triangleIndicesOut.m_size = 0;
      _mm_store_si128((__m128i *)&resulta, v64);
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_u64[1] = 0x8000000000000000i64;
      triangleIndicesOut.m_capacityAndFlags = 2147483648;
      v67 = v65[v56];
      v68 = partitions->m_data;
      dmax.m_quad.m128_i32[2] = v67;
      v69 = v67 | 0x80000000;
      v70 = &v68[v66];
      v150 = v69;
      dmax.m_quad.m128_i32[3] = v69;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)&v68[v66];
      hkaiNavMeshSimplificationUtils::triangulatePartition(
        &v149,
        extraVertexSettings,
        originalMesha,
        &navMeshOut->m_vertices,
        v27,
        &partitionSegments,
        (hkArray<int const ,hkContainerHeapAllocator> *)&dmax,
        &resulta,
        &triangleIndicesOut,
        (hkArray<int,hkContainerTempAllocator> *)&dmin,
        edgeIsBoundary,
        userVertexOnBoundary,
        (hkReferencedObject *)&v168[v62].vfptr,
        (hkAabb *)&v166 + v62);
      if ( v149.m_enum )
        break;
      v71 = navMeshOut->m_faces.m_size;
      v72 = triangleIndicesOut.m_size / 3;
      v73 = hkaiNavMesh::expandFacesBy(navMeshOut, triangleIndicesOut.m_size / 3, -1);
      v74 = v73;
      if ( v72 && !v73 )
      {
        v171->m_enum = 1;
        if ( v69 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v70,
            4 * v69);
        dmin.m_quad.m128_i32[2] = 0;
        if ( dmin.m_quad.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[0],
            4 * dmin.m_quad.m128_i32[3]);
        dmin.m_quad.m128_u64[0] = 0i64;
        dmin.m_quad.m128_i32[3] = 2147483648;
        triangleIndicesOut.m_size = 0;
        if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            triangleIndicesOut.m_data,
            4 * triangleIndicesOut.m_capacityAndFlags);
        triangleIndicesOut.m_data = 0i64;
        triangleIndicesOut.m_capacityAndFlags = 2147483648;
        partitionSegments.m_size = 0;
        if ( partitionSegments.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            partitionSegments.m_data,
            4 * partitionSegments.m_capacityAndFlags);
        partitionSegments.m_data = 0i64;
        partitionSegments.m_capacityAndFlags = 2147483648;
        v148.m_userVertices.m_size = 0;
        if ( v148.m_userVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v148.m_userVertices.m_data,
            16 * v148.m_userVertices.m_capacityAndFlags);
        v148.m_userVertices.m_data = 0i64;
        v148.m_userVertices.m_capacityAndFlags = 2147483648;
        v136 = 0;
        if ( v137 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            8 * v137);
        v137 = 2147483648;
        v119 = &v170;
        v120 = 5;
        array = 0i64;
        do
        {
          v119 -= 3312;
          *(_QWORD *)(v119 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v119 - 92),
            1);
          v121 = *(_DWORD *)v119;
          *((_DWORD *)v119 - 1) = 0;
          if ( v121 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v119 - 12),
              16 * v121);
          *(_QWORD *)(v119 - 12) = 0i64;
          *(_DWORD *)v119 = 2147483648;
          *(_QWORD *)(v119 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgp)(v119 - 36));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v119 - 36));
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)(v119 - 60));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v119 - 60));
          --v120;
          *(_QWORD *)(v119 - 76) = &hkBaseObject::`vftable';
          *(_QWORD *)(v119 - 92) = &hkBaseObject::`vftable';
        }
        while ( v120 >= 0 );
        return v171;
      }
      v75 = triangleIndicesOut.m_data;
      v76 = dmin.m_quad.m128_u64[0];
      v141.m_enum = navMeshOut->m_edges.m_size;
      v77 = hkaiNavMesh::expandEdgesBy(navMeshOut, 3 * v72, -1);
      v78 = v77;
      if ( v72 && !v77 )
      {
        v171->m_enum = 1;
        if ( v69 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)dmax.m_quad.m128_u64[0],
            4 * v69);
        dmin.m_quad.m128_i32[2] = 0;
        if ( dmin.m_quad.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[0],
            4 * dmin.m_quad.m128_i32[3]);
        dmin.m_quad.m128_u64[0] = 0i64;
        dmin.m_quad.m128_i32[3] = 2147483648;
        triangleIndicesOut.m_size = 0;
        if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            triangleIndicesOut.m_data,
            4 * triangleIndicesOut.m_capacityAndFlags);
        triangleIndicesOut.m_data = 0i64;
        triangleIndicesOut.m_capacityAndFlags = 2147483648;
        partitionSegments.m_size = 0;
        if ( partitionSegments.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            partitionSegments.m_data,
            4 * partitionSegments.m_capacityAndFlags);
        partitionSegments.m_data = 0i64;
        partitionSegments.m_capacityAndFlags = 2147483648;
        v148.m_userVertices.m_size = 0;
        if ( v148.m_userVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v148.m_userVertices.m_data,
            16 * v148.m_userVertices.m_capacityAndFlags);
        v148.m_userVertices.m_data = 0i64;
        v148.m_userVertices.m_capacityAndFlags = 2147483648;
        v136 = 0;
        if ( v137 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            8 * v137);
        v137 = 2147483648;
        v122 = &v170;
        v123 = 5;
        array = 0i64;
        do
        {
          v122 -= 3312;
          *(_QWORD *)(v122 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v122 - 92),
            1);
          v124 = *(_DWORD *)v122;
          *((_DWORD *)v122 - 1) = 0;
          if ( v124 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v122 - 12),
              16 * v124);
          *(_QWORD *)(v122 - 12) = 0i64;
          *(_DWORD *)v122 = 2147483648;
          *(_QWORD *)(v122 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgp)(v122 - 36));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v122 - 36));
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)(v122 - 60));
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v122 - 60));
          --v123;
          *(_QWORD *)(v122 - 76) = &hkBaseObject::`vftable';
          *(_QWORD *)(v122 - 92) = &hkBaseObject::`vftable';
        }
        while ( v123 >= 0 );
        return v171;
      }
      v79 = faceToPartitionMap;
      v80 = v72 + faceToPartitionMap->m_size;
      v81 = faceToPartitionMap->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v81 >= v80 )
      {
        v147.m_enum = 0;
      }
      else
      {
        v82 = 2 * v81;
        if ( v80 < v82 )
          v80 = v82;
        hkArrayUtil::_reserve(
          &v147,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          faceToPartitionMap,
          v80,
          4);
        if ( v147.m_enum )
        {
          v171->m_enum = 1;
          if ( v69 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (void *)dmax.m_quad.m128_u64[0],
              4 * v69);
          dmin.m_quad.m128_i32[2] = 0;
          if ( dmin.m_quad.m128_i32[3] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (void *)dmin.m_quad.m128_u64[0],
              4 * dmin.m_quad.m128_i32[3]);
          dmin.m_quad.m128_u64[0] = 0i64;
          dmin.m_quad.m128_i32[3] = 2147483648;
          triangleIndicesOut.m_size = 0;
          if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              triangleIndicesOut.m_data,
              4 * triangleIndicesOut.m_capacityAndFlags);
          triangleIndicesOut.m_data = 0i64;
          triangleIndicesOut.m_capacityAndFlags = 2147483648;
          partitionSegments.m_size = 0;
          if ( partitionSegments.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              partitionSegments.m_data,
              4 * partitionSegments.m_capacityAndFlags);
          partitionSegments.m_data = 0i64;
          partitionSegments.m_capacityAndFlags = 2147483648;
          v148.m_userVertices.m_size = 0;
          if ( v148.m_userVertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v148.m_userVertices.m_data,
              16 * v148.m_userVertices.m_capacityAndFlags);
          v148.m_userVertices.m_data = 0i64;
          v148.m_userVertices.m_capacityAndFlags = 2147483648;
          v136 = 0;
          if ( v137 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              array,
              8 * v137);
          v137 = 2147483648;
          v125 = &v170;
          v126 = 5;
          array = 0i64;
          do
          {
            v125 -= 3312;
            *(_QWORD *)(v125 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v125 - 92),
              1);
            v127 = *(_DWORD *)v125;
            *((_DWORD *)v125 - 1) = 0;
            if ( v127 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v125 - 12),
                16 * v127);
            *(_QWORD *)(v125 - 12) = 0i64;
            *(_DWORD *)v125 = 2147483648;
            *(_QWORD *)(v125 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgp)(v125 - 36));
            hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v125 - 36));
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)(v125 - 60));
            hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v125 - 60));
            --v126;
            *(_QWORD *)(v125 - 76) = &hkBaseObject::`vftable';
            *(_QWORD *)(v125 - 92) = &hkBaseObject::`vftable';
          }
          while ( v126 >= 0 );
          return v171;
        }
        v79 = faceToPartitionMap;
      }
      v83 = v79->m_size;
      v84 = v71;
      v162 = v71;
      v79->m_size = v83 + v72;
      v85 = v141.m_enum;
      v153 = &v79->m_data[v83];
      v86 = v141.m_enum;
      v155 = v72;
      if ( v72 > 0 )
      {
        v87 = (signed __int64)&v74->m_numUserEdges;
        v88 = 0i64;
        do
        {
          *(_DWORD *)(v87 - 2) = 3;
          *(_DWORD *)(v87 - 10) = v85;
          *(_DWORD *)(v87 - 6) = -1;
          *(_WORD *)(v87 + 2) = -1;
          *(_WORD *)(v87 + 4) = -12851;
          v89 = navMeshOut->m_faceDataStriding;
          v90 = 3i64;
          if ( (_DWORD)v89 )
            navMeshOut->m_faceData.m_data[v89 * (v88 + v84)] = faceData->m_data[partitions->m_data[v142]];
          v91 = 2i64;
          v92 = 0i64;
          v93 = 40i64;
          v94 = 0i64;
          do
          {
            *(int *)((char *)&v78->m_a + v93) = v75[v91];
            *(int *)((char *)&v78->m_b + v93) = v75[v92];
            *(_QWORD *)((char *)&v78->m_oppositeEdge + v93) = -1i64;
            *(_DWORD *)(&v78->m_flags.m_storage + v93) = 4;
            v95 = navMeshOut->m_edgeDataStriding;
            if ( (_DWORD)v95 )
              navMeshOut->m_edgeData.m_data[v95 * (v91 + v86)] = *(_DWORD *)(v76 + 4 * v91);
            v91 = v92;
            v93 = v94;
            ++v92;
            v94 += 20i64;
            --v90;
          }
          while ( v90 );
          v96 = v153;
          v84 = v162;
          *v153 = v143;
          ++v88;
          v153 = v96 + 1;
          v75 += 3;
          v85 = v141.m_enum + 3;
          v76 += 12i64;
          v78 += 3;
          v86 += 3i64;
          v87 += 16i64;
          v141.m_enum += 3;
        }
        while ( v88 < v155 );
        v69 = v150;
      }
      v97 = v152;
      v98 = numFacesInPartition->m_data;
      dmax.m_quad.m128_i32[2] = 0;
      v142 += v98[v152];
      if ( v69 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          (void *)dmax.m_quad.m128_u64[0],
          4 * v69);
      dmax.m_quad.m128_u64[0] = 0i64;
      dmax.m_quad.m128_i32[3] = 2147483648;
      dmin.m_quad.m128_i32[2] = 0;
      if ( dmin.m_quad.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          (void *)dmin.m_quad.m128_u64[0],
          4 * dmin.m_quad.m128_i32[3]);
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_i32[3] = 2147483648;
      triangleIndicesOut.m_size = 0;
      if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          triangleIndicesOut.m_data,
          4 * triangleIndicesOut.m_capacityAndFlags);
      triangleIndicesOut.m_data = 0i64;
      triangleIndicesOut.m_capacityAndFlags = 2147483648;
      partitionSegments.m_size = 0;
      if ( partitionSegments.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          partitionSegments.m_data,
          4 * partitionSegments.m_capacityAndFlags);
      partitionSegments.m_data = 0i64;
      v56 = v97 + 1;
      v54 = v143 + 1;
      partitionSegments.m_capacityAndFlags = 2147483648;
      v152 = v56;
      ++v143;
      if ( v56 >= v156 )
      {
        v26 = 5;
        goto LABEL_195;
      }
      v55 = v154;
      v25 = v145;
      v27 = segments;
      v52 = numFacesInPartition;
    }
    v171->m_enum = 1;
    if ( v69 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v70,
        4 * v69);
    dmin.m_quad.m128_i32[2] = 0;
    if ( dmin.m_quad.m128_i32[3] >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        (void *)dmin.m_quad.m128_u64[0],
        4 * dmin.m_quad.m128_i32[3]);
    dmin.m_quad.m128_u64[0] = 0i64;
    dmin.m_quad.m128_i32[3] = 2147483648;
    triangleIndicesOut.m_size = 0;
    if ( triangleIndicesOut.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        triangleIndicesOut.m_data,
        4 * triangleIndicesOut.m_capacityAndFlags);
    triangleIndicesOut.m_data = 0i64;
    triangleIndicesOut.m_capacityAndFlags = 2147483648;
    partitionSegments.m_size = 0;
    if ( partitionSegments.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        partitionSegments.m_data,
        4 * partitionSegments.m_capacityAndFlags);
    partitionSegments.m_data = 0i64;
    partitionSegments.m_capacityAndFlags = 2147483648;
    v148.m_userVertices.m_size = 0;
    if ( v148.m_userVertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v148.m_userVertices.m_data,
        16 * v148.m_userVertices.m_capacityAndFlags);
    v148.m_userVertices.m_data = 0i64;
    v148.m_userVertices.m_capacityAndFlags = 2147483648;
    v136 = 0;
    if ( v137 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        8 * v137);
    v137 = 2147483648;
    v132 = &v170;
    v133 = 5;
    array = 0i64;
    do
    {
      v132 -= 3312;
      *(_QWORD *)(v132 - 92) = &hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *)(v132 - 92),
        1);
      v134 = *(_DWORD *)v132;
      *((_DWORD *)v132 - 1) = 0;
      if ( v134 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v132 - 12),
          16 * v134);
      *(_QWORD *)(v132 - 12) = 0i64;
      *(_DWORD *)v132 = 2147483648;
      *(_QWORD *)(v132 - 76) = &hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgp)(v132 - 36));
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)(v132 - 36));
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)(v132 - 60));
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)(v132 - 60));
      --v133;
      *(_QWORD *)(v132 - 76) = &hkBaseObject::`vftable';
      *(_QWORD *)(v132 - 92) = &hkBaseObject::`vftable';
    }
    while ( v133 >= 0 );
  }
  return v171;
}llocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBa

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
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm2
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
    v10.m_quad = _mm_add_ps(v1->m_quad, v0->m_quad);
    *ccOut = (hkVector4f)v10.m_quad;
    v11.m_quad = _mm_add_ps(v10.m_quad, v2->m_quad);
    *ccOut = (hkVector4f)v11.m_quad;
    v12.m_quad = _mm_mul_ps(v11.m_quad, (__m128)xmmword_141A711C0);
  }
  *ccOut = (hkVector4f)v12.m_quad;
}

// File Line: 306
// RVA: 0xB63650
void __fastcall pickRandomPoint(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkArray<TriangleArea,hkContainerHeapAllocator> *cumulativeArea, float totalArea, hkPseudoRandomGenerator *rand, hkVector4f *pOut)
{
  hkArray<TriangleArea,hkContainerHeapAllocator> *v5; // r10
  signed int v6; // edx
  hkPseudoRandomGenerator *v7; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v8; // rdi
  signed __int64 v9; // rcx
  signed int v10; // er11
  signed __int64 v11; // r9
  float *v12; // rax
  int v13; // eax
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v16; // rdx
  int v17; // er11
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  int v20; // ecx
  __m128 v21; // xmm7
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm9
  __m128 v28; // xmm8
  __m128 v29; // xmm6
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm0

  v5 = cumulativeArea;
  v6 = 1;
  v7 = rand;
  v8 = triangulator;
  v9 = 1i64;
  v10 = 1664525 * rand->m_current + 1013904223;
  rand->m_current = v10;
  v11 = v5->m_size;
  if ( v11 <= 1 )
    goto LABEL_7;
  v12 = &v5->m_data[1].m_area;
  while ( (float)((float)((float)v10 * 2.3283064e-10) * totalArea) > *v12 )
  {
    ++v9;
    ++v6;
    v12 += 4;
    if ( v9 >= v11 )
      goto LABEL_7;
  }
  v13 = v6 - 1;
  if ( !v6 )
LABEL_7:
    v13 = v11 - 1;
  v14 = v8->m_localToWorld.m_col1.m_quad;
  v15 = v8->m_localToWorld.m_col2.m_quad;
  v16 = v5->m_data[v13].m_triangle;
  v17 = 1664525 * v10;
  v18 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&v16->m_vertices[0]->m_x));
  v19 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&v16->m_vertices[1]->m_x));
  v20 = 1664525 * (v17 + 1013904223);
  v21 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&v16->m_vertices[2]->m_x));
  v22 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, (__m128)0i64), 180), 4),
                  4);
  v23 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)0i64), 180), 4),
                  4);
  v24 = v8->m_localToWorld.m_col3.m_quad;
  v25 = v8->m_localToWorld.m_col0.m_quad;
  v26 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, (__m128)0i64), 180), 4),
                  4);
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v25), v24),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v15));
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v25), v24),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v15));
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v25), v24),
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v15));
  v7->m_current = v20 + 1013904223;
  v30 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(v17 + 1013904223) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(v17 + 1013904223) * 2.3283064e-10),
          0);
  v31 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(v20 + 1013904223) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(v20 + 1013904223) * 2.3283064e-10),
          0);
  v32 = _mm_cmpltps(query.m_quad, _mm_add_ps(v31, v30));
  v33 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(query.m_quad, v30), v32), _mm_andnot_ps(v32, v30));
  v34 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(query.m_quad, v31), v32), _mm_andnot_ps(v32, v31));
  pOut->m_quad = _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps(query.m_quad, v33), v34), v27), _mm_mul_ps(v28, v33)),
                   _mm_mul_ps(v29, v34));
}

// File Line: 330
// RVA: 0xB638C0
hkResult *__fastcall pickRandomSeeding(hkResult *result, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *evs, int numActiveTriangles, hkArray<hkVector4f,hkContainerHeapAllocator> *steinerPoints)
{
  int v5; // er15
  int v6; // er9
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v7; // rsi
  signed int v8; // er8
  float v9; // xmm11_4
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v10; // r14
  hkResult *v11; // rdi
  signed int v12; // er10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *i; // rbx
  __int64 v14; // rax
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm8
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
  int v39; // er9
  hkResult v41; // [rsp+30h] [rbp-61h]
  hkPseudoRandomGenerator rand; // [rsp+38h] [rbp-59h]
  char *array; // [rsp+40h] [rbp-51h]
  int v44; // [rsp+48h] [rbp-49h]
  int v45; // [rsp+4Ch] [rbp-45h]
  hkVector4f pOut; // [rsp+50h] [rbp-41h]
  hkResult resulta; // [rsp+F8h] [rbp+67h]

  v5 = numActiveTriangles;
  v6 = triangulator->m_mesh.m_triangles.m_numUsed;
  v7 = evs;
  v8 = 2147483648;
  v9 = 0.0;
  v10 = triangulator;
  v11 = result;
  array = 0i64;
  v12 = 0;
  v44 = 0;
  v45 = 2147483648;
  if ( v6 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v6 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v6, 16);
    v8 = v45;
    if ( resulta.m_enum )
    {
      v11->m_enum = 1;
      v44 = 0;
      if ( v8 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          16 * v8);
      return v11;
    }
    v12 = v44;
  }
  for ( i = v10->m_mesh.m_triangles.m_used; i; i = i->m_next )
  {
    if ( *((_BYTE *)i + 184) & 0x20 )
    {
      if ( v12 == (v8 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v12 = v44;
      }
      v14 = (__int64)&array[16 * v12];
      v44 = v12 + 1;
      *(_QWORD *)v14 = i;
      *(float *)(v14 + 8) = v9;
      v15 = v10->m_localToWorld.m_col0.m_quad;
      v16 = v10->m_localToWorld.m_col3.m_quad;
      v17 = v10->m_localToWorld.m_col1.m_quad;
      v18 = v10->m_localToWorld.m_col2.m_quad;
      v19 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[0]->m_x));
      v20 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)0i64), 180), 4),
                      4);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v15), v16),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v17)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v18));
      v22 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[1]->m_x));
      v23 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)0i64), 180), 4),
                      4);
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15), v16),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v17)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v18));
      v25 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&i->m_vertices[2]->m_x));
      v26 = _mm_sub_ps(v24, v21);
      v27 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, (__m128)0i64), 180), 4),
                      4);
      v28 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v15), v16),
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v17)),
                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v18)),
              v21);
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v28));
      v30 = _mm_shuffle_ps(v29, v29, 201);
      v31 = _mm_mul_ps(v30, v30);
      v8 = v45;
      v12 = v44;
      v32 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170));
      v33 = _mm_rsqrt_ps(v32);
      v9 = v9
         + (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       _mm_cmpleps(v32, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                           _mm_mul_ps(*(__m128 *)_xmm, v33)),
                         v32)))
                 * 0.5);
    }
  }
  if ( !v12 || v9 < v7->m_minPartitionArea && v7->m_vertexSelectionMethod.m_storage )
    goto LABEL_34;
  if ( !v7->m_vertexSelectionMethod.m_storage )
  {
    v35 = v9 * v7->m_areaFraction;
    goto LABEL_23;
  }
  if ( v7->m_vertexSelectionMethod.m_storage == 1 )
  {
    v35 = (float)v5 * v7->m_vertexFraction;
LABEL_23:
    LODWORD(v34) = (signed int)v35;
    goto LABEL_24;
  }
  LODWORD(v34) = 0;
LABEL_24:
  v36 = steinerPoints;
  rand.m_seed = v12;
  rand.m_current = v12;
  v37 = steinerPoints->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v37 >= (signed int)v34 )
  {
    v41.m_enum = 0;
  }
  else
  {
    v38 = 2 * v37;
    v39 = v34;
    if ( (signed int)v34 < v38 )
      v39 = v38;
    hkArrayUtil::_reserve(&v41, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, steinerPoints, v39, 16);
    v8 = v45;
    if ( v41.m_enum )
    {
      v11->m_enum = 1;
      goto LABEL_35;
    }
  }
  if ( (signed int)v34 > 0 )
  {
    v34 = (unsigned int)v34;
    do
    {
      pickRandomPoint(v10, (hkArray<TriangleArea,hkContainerHeapAllocator> *)&array, v9, &rand, &pOut);
      v36->m_data[v36->m_size++] = (hkVector4f)pOut.m_quad;
      --v34;
    }
    while ( v34 );
    v8 = v45;
  }
LABEL_34:
  v11->m_enum = 0;
LABEL_35:
  v44 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v8);
  return v11;
}

// File Line: 407
// RVA: 0xB63D10
char __fastcall getVertexHeight(hkaiNavMesh *originalMesh, hkArray<int const ,hkContainerHeapAllocator> *facesInPartition, hkVector4f *up, hkArrayBase<hkVector4f> *verticesOut, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *va, hkVector4f *vertexInOut)
{
  hkArrayBase<hkVector4f> *v7; // r15
  hkArray<int const ,hkContainerHeapAllocator> *v8; // rsi
  hkaiNavMesh *v9; // rbp
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
  __m128 v22; // xmm0
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
  char result; // al
  hkcdRay ray; // [rsp+20h] [rbp-108h]
  __m128 v51; // [rsp+50h] [rbp-D8h]
  __m128 v52; // [rsp+60h] [rbp-C8h]

  v7 = verticesOut;
  v8 = facesInPartition;
  v9 = originalMesh;
  v10 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  v11 = _mm_mul_ps(_mm_add_ps(originalMesh->m_aabb.m_max.m_quad, v10), up->m_quad);
  v12 = _mm_mul_ps(_mm_sub_ps(originalMesh->m_aabb.m_min.m_quad, v10), up->m_quad);
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
  v19 = _mm_cmpeqps((__m128)v17, (__m128)0i64);
  v51 = _mm_shuffle_ps((__m128)v17, _mm_unpackhi_ps((__m128)v17, query.m_quad), 196);
  v52 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu), (__m128)_xmm), v19),
          _mm_andnot_ps(v19, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v17, v18)), v18)));
  v20 = 0;
  v52.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v51)) & 7 | 0x3F000000;
  if ( facesInPartition->m_size <= 0 )
  {
LABEL_5:
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
      triangulator,
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location *)&ray,
      va->m_x,
      va->m_y);
    if ( ray.m_origin.m_quad.m128_u64[1] && *(_BYTE *)(ray.m_origin.m_quad.m128_u64[1] + 184) & 0x20 )
    {
      v22 = v7->m_data[(signed int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 16) + 24i64) >> 2)].m_quad;
      v23 = _mm_sub_ps(ray.m_invDirection.m_quad, v22);
      v24 = _mm_sub_ps(
              v7->m_data[(signed int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 24) + 24i64) >> 2)].m_quad,
              v22);
      v25 = _mm_shuffle_ps(v24, v24, 201);
      v26 = _mm_sub_ps(
              v7->m_data[(signed int)(*(_QWORD *)(*(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 32) + 24i64) >> 2)].m_quad,
              v22);
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_sub_ps(_mm_mul_ps(v24, v27), _mm_mul_ps(v26, v25));
      v29 = _mm_shuffle_ps(v28, v28, 201);
      v30 = _mm_mul_ps(v51, v29);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      if ( (float)(v31.m128_f32[0] * v31.m128_f32[0]) < 0.00000011920929 )
        goto LABEL_18;
      v32 = _mm_mul_ps(v29, v23);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_rcp_ps(v31);
      v35 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v31)), v34), _mm_sub_ps((__m128)0i64, v33));
      if ( !_mm_movemask_ps(_mm_mul_ps(v33, v31)) )
        goto LABEL_18;
      if ( v35.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 255)) )
        goto LABEL_18;
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
              _mm_cmpleps(
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
LABEL_18:
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v21 = 0i64;
    while ( !hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
               (hkaiNavMeshUtils *)v9,
               (hkaiNavMesh *)(unsigned int)v8->m_data[v21],
               (unsigned __int64)&ray.m_invDirection,
               &ray,
               (hkSimdFloat32 *)ray.m_origin.m_quad.m128_u64[0]) )
    {
      ++v20;
      ++v21;
      if ( v20 >= v8->m_size )
        goto LABEL_5;
    }
    result = 1;
    vertexInOut->m_quad = _mm_add_ps(_mm_mul_ps(ray.m_origin.m_quad, (__m128)v17), v15.m_quad);
  }
  return result;
}v8->m_size )
        goto LABEL_5;
  

// File Line: 474
// RVA: 0xB641A0
hkResult *__fastcall addUserPoints(hkResult *result, hkaiNavMesh *originalMesh, hkArray<int const ,hkContainerHeapAllocator> *facesInPartition, hkAabb *partitionAabb, hkVector4f *up, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings, hkBitField *userVertexOnBoundary, hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *ec, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v11; // r13
  hkArray<int const ,hkContainerHeapAllocator> *v12; // r10
  hkaiNavMesh *v13; // r11
  int v14; // er9
  int v15; // eax
  hkResult *v16; // r12
  int v17; // eax
  int v19; // ebp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v20; // r14
  __int64 v21; // r15
  hkVector4f *v22; // rdx
  int v23; // edi
  int v24; // eax
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128i v29; // xmm1
  int v30; // esi
  int v31; // ecx
  hkVector4f *v32; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v33; // rdx
  hkVector4f vertexInOut; // [rsp+40h] [rbp-88h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v35; // [rsp+50h] [rbp-78h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex va; // [rsp+68h] [rbp-60h]
  hkaiNavMesh *v37; // [rsp+D8h] [rbp+10h]
  hkArray<int const ,hkContainerHeapAllocator> *v38; // [rsp+E0h] [rbp+18h]
  hkAabb *resulta; // [rsp+E8h] [rbp+20h]

  resulta = partitionAabb;
  v38 = facesInPartition;
  v37 = originalMesh;
  v10 = verticesOut;
  v11 = extraVertexSettings;
  v12 = facesInPartition;
  v13 = originalMesh;
  v14 = extraVertexSettings->m_userVertices.m_size + verticesOut->m_size;
  v15 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
  v16 = result;
  if ( v15 >= v14 )
  {
    LODWORD(resulta) = 0;
  }
  else
  {
    v17 = 2 * v15;
    if ( v14 < v17 )
      v14 = v17;
    hkArrayUtil::_reserve(
      (hkResult *)&resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      verticesOut,
      v14,
      16);
    if ( (_DWORD)resulta )
    {
      v16->m_enum = 1;
      return v16;
    }
    v12 = v38;
    v13 = v37;
  }
  v19 = 0;
  if ( v11->m_userVertices.m_size > 0 )
  {
    v20 = triangulator;
    v21 = 0i64;
    while ( 1 )
    {
      if ( !((userVertexOnBoundary->m_storage.m_words.m_data[(signed __int64)v19 >> 5] >> (v19 & 0x1F)) & 1) )
      {
        v22 = v11->m_userVertices.m_data;
        v23 = v20->m_margin;
        v24 = 0x7FFFFF - v23;
        v25 = v22[v21].m_quad;
        v26 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v20->m_worldToLocal.m_col0.m_quad),
                    v20->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v22[v21].m_quad, v25, 85), v20->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v20->m_worldToLocal.m_col2.m_quad));
        v27 = _mm_cmpltps(v26, (__m128)0i64);
        v28 = _mm_or_ps(
                _mm_andnot_ps(v27, _mm_add_ps(v26, (__m128)xmmword_141A711B0)),
                _mm_and_ps(_mm_sub_ps(v26, (__m128)xmmword_141A711B0), v27));
        v29 = _mm_xor_si128(
                (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v28),
                _mm_cvttps_epi32(v28));
        v30 = _mm_cvtsi128_si32(v29);
        if ( v30 >= v23 )
        {
          if ( v30 > v24 )
            v30 = 0x7FFFFF - v23;
        }
        else
        {
          v30 = v20->m_margin;
        }
        va.m_x = v30;
        v31 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v29, 85));
        if ( v31 >= v23 )
        {
          v23 = v31;
          if ( v31 > v24 )
            v23 = v24;
        }
        v32 = up;
        _mm_store_si128((__m128i *)&vertexInOut, (__m128i)v22[v21].m_quad);
        va.m_y = v23;
        if ( getVertexHeight(v13, v12, v32, (hkArrayBase<hkVector4f> *)&v10->m_data, v20, &va, &vertexInOut) )
        {
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
            v20,
            &v35,
            v30,
            v23,
            1,
            ec);
          if ( v35.m_type.m_storage == 10 || v20->m_status.m_storage )
          {
            v16->m_enum = 1;
            return v16;
          }
          if ( !v35.m_type.m_storage )
          {
            v33 = v35.m_edge.m_triangle->m_vertices[v35.m_edge.m_index];
            *((_QWORD *)v33 + 3) = *((_DWORD *)v33 + 6) & 3 | (unsigned __int64)(4i64 * v10->m_size);
            if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
            v10->m_data[v10->m_size++] = (hkVector4f)vertexInOut.m_quad;
          }
        }
      }
      ++v19;
      ++v21;
      if ( v19 >= v11->m_userVertices.m_size )
        break;
      v12 = v38;
      v13 = v37;
    }
  }
  v16->m_enum = 0;
  return v16;
}

// File Line: 529
// RVA: 0xB644C0
hkResult *__fastcall laplacianSmooth(hkResult *result, hkaiNavMesh *originalMesh, hkArray<int const ,hkContainerHeapAllocator> *facesInPartition, hkVector4f *up, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings, int numActiveTriangles, hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *ec, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  hkResult *v9; // r14
  hkResult *v10; // rdi
  int v11; // er15
  __m128 v12; // xmm7
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er8
  signed int v18; // er12
  __int64 v19; // r9
  int v20; // eax
  bool v21; // dl
  int v22; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v23; // r14
  __int64 v24; // r12
  int v25; // edi
  int v26; // eax
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128i v33; // xmm1
  int v34; // esi
  int v35; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v36; // rdx
  hkVector4f *v37; // rdi
  int v38; // er8
  int v39; // edi
  int v40; // eax
  signed __int64 v41; // rdx
  __int64 v42; // r8
  __int64 v43; // r10
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  __m128 v46; // xmm5
  __m128 v47; // xmm6
  signed __int64 v48; // r8
  __int64 v49; // rcx
  __int64 v50; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  __m128 v53; // xmm14
  __m128 v54; // xmm12
  __m128 v55; // xmm13
  __m128 v56; // xmm7
  __m128 v57; // xmm11
  __m128 v58; // xmm2
  __m128 v59; // xmm15
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
  signed __int64 v104; // r8
  __m128 v105; // xmm1
  __m128 v106; // xmm1
  __m128 v107; // xmm1
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm4
  signed int v111; // ecx
  __int64 v112; // rax
  int v113; // er11
  __int64 v114; // r10
  __m128 v115; // xmm3
  __m128 v116; // xmm2
  signed __int64 v117; // r8
  signed __int64 v118; // rdx
  hkVector4f *v119; // rcx
  signed __int64 v120; // rdx
  unsigned __int64 v121; // rax
  __m128 v122; // xmm1
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v123; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v124; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v125; // rdx
  hkResult *v126; // rbx
  int v127; // er8
  bool v128; // [rsp+40h] [rbp-98h]
  hkArray<hkVector4f,hkContainerHeapAllocator> steinerPoints; // [rsp+48h] [rbp-90h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion resulta; // [rsp+58h] [rbp-80h]
  hkResult v131; // [rsp+70h] [rbp-68h]
  hkResult v132; // [rsp+74h] [rbp-64h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex va; // [rsp+78h] [rbp-60h]
  __int64 v134; // [rsp+98h] [rbp-40h]
  int v135[2]; // [rsp+A0h] [rbp-38h]
  __int64 v136; // [rsp+A8h] [rbp-30h]
  int v137; // [rsp+B0h] [rbp-28h]
  __int128 v138; // [rsp+B8h] [rbp-20h]
  hkVector4f v0; // [rsp+C8h] [rbp-10h]
  hkVector4f v1; // [rsp+D8h] [rbp+0h]
  hkVector4f v2; // [rsp+E8h] [rbp+10h]
  __m128 v142; // [rsp+F8h] [rbp+20h]
  hkVector4f ccOut; // [rsp+108h] [rbp+30h]
  hkVector4f dmax; // [rsp+118h] [rbp+40h]
  hkVector4f dmin; // [rsp+128h] [rbp+50h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> other; // [rsp+138h] [rbp+60h]
  hkResult *v147; // [rsp+F18h] [rbp+E40h]
  hkaiNavMesh *originalMesha; // [rsp+F20h] [rbp+E48h]
  hkArray<int const ,hkContainerHeapAllocator> *facesInPartitiona; // [rsp+F28h] [rbp+E50h]
  hkVector4f *upa; // [rsp+F30h] [rbp+E58h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *retaddr; // [rsp+F38h] [rbp+E60h]
  hkResult *evs; // [rsp+F40h] [rbp+E68h]
  hkaiNavMesh *v153; // [rsp+F48h] [rbp+E70h]
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *icrossing; // [rsp+F50h] [rbp+E78h]
  hkArrayBase<hkVector4f> *array; // [rsp+F58h] [rbp+E80h]

  array = (hkArrayBase<hkVector4f> *)up;
  icrossing = (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)facesInPartition;
  v153 = originalMesh;
  evs = result;
  v9 = result;
  v10 = result;
  v11 = 0;
  v12 = _mm_sub_ps(
          query.m_quad,
          _mm_shuffle_ps((__m128)(unsigned int)evs[5].m_enum, (__m128)(unsigned int)evs[5].m_enum, 0));
  steinerPoints.m_capacityAndFlags = 2147483648;
  v142 = v12;
  steinerPoints.m_data = 0i64;
  steinerPoints.m_size = 0;
  pickRandomSeeding(
    (hkResult *)&resulta.m_edge.m_index,
    retaddr,
    (hkaiNavMeshSimplificationUtils::ExtraVertexSettings *)result,
    (int)originalMesh,
    &steinerPoints);
  if ( resulta.m_edge.m_index )
  {
    v10->m_enum = 1;
LABEL_3:
    steinerPoints.m_size = 0;
    if ( steinerPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        steinerPoints.m_data,
        16 * steinerPoints.m_capacityAndFlags);
    return v10;
  }
  if ( !steinerPoints.m_size )
  {
    v10->m_enum = 0;
    goto LABEL_3;
  }
  v14 = steinerPoints.m_size + array->m_size;
  v15 = array->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 >= v14 )
  {
    v131.m_enum = 0;
  }
  else
  {
    v16 = 2 * v15;
    if ( v14 < v16 )
      v14 = v16;
    hkArrayUtil::_reserve(&v131, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, v14, 16);
    if ( v131.m_enum )
    {
      v17 = steinerPoints.m_capacityAndFlags;
      steinerPoints.m_size = 0;
      v10->m_enum = 1;
      if ( v17 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          steinerPoints.m_data,
          16 * v17);
      return v10;
    }
  }
  v18 = 0;
  resulta.m_edge.m_index = 0;
  if ( v9[4].m_enum <= 0 )
  {
LABEL_96:
    v10->m_enum = 0;
    goto LABEL_97;
  }
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  while ( 1 )
  {
    other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
    _mm_store_si128((__m128i *)&other.m_mesh.m_vertices, (__m128i)0i64);
    *(_DWORD *)&other.m_memSizeAndFlags = 0x1FFFF;
    other.m_stack.m_data = other.m_stack.m_storage;
    other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
    *(_DWORD *)&other.m_mesh.m_memSizeAndFlags = 0x1FFFF;
    other.m_mesh.m_vertices.m_numUsed = 0;
    other.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
    other.m_mesh.m_triangles.m_used = 0i64;
    other.m_mesh.m_triangles.m_numUsed = 0;
    other.m_stack.m_size = 0;
    other.m_stack.m_capacityAndFlags = -2147483584;
    other.m_status.m_storage = 0;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
      &other,
      &dmin,
      &dmax,
      0.0,
      1);
    v20 = v9[4].m_enum - 1;
    v21 = v18 == v20;
    v128 = v18 == v20;
    if ( v18 != v20 )
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
      v10 = v147;
      other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
      v147->m_enum = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &other,
        1);
      other.m_stack.m_size = 0;
      if ( other.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_stack.m_data,
          16 * other.m_stack.m_capacityAndFlags);
      other.m_stack.m_data = 0i64;
      other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
      other.m_stack.m_capacityAndFlags = 2147483648;
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&other.m_mesh.m_triangles);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&other.m_mesh.m_vertices);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
      other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
      other.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
LABEL_97:
      steinerPoints.m_size = 0;
      if ( steinerPoints.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          steinerPoints.m_data,
          16 * steinerPoints.m_capacityAndFlags);
      return v10;
    }
LABEL_21:
    v22 = steinerPoints.m_size;
    v23 = &other;
    if ( v21 )
      v23 = retaddr;
    if ( steinerPoints.m_size <= 0 )
      goto LABEL_44;
    v24 = 0i64;
LABEL_25:
    v25 = v23->m_margin;
    v26 = 0x7FFFFF - v25;
    v27 = steinerPoints.m_data[v24].m_quad;
    v28 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v23->m_worldToLocal.m_col0.m_quad),
                v23->m_worldToLocal.m_col3.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(steinerPoints.m_data[v24].m_quad, v27, 85), v23->m_worldToLocal.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v23->m_worldToLocal.m_col2.m_quad));
    v29 = _mm_sub_ps(v28, (__m128)xmmword_141A711B0);
    v30 = _mm_add_ps(v28, (__m128)xmmword_141A711B0);
    v31 = _mm_cmpltps(v28, (__m128)0i64);
    v32 = _mm_or_ps(_mm_andnot_ps(v31, v30), _mm_and_ps(v29, v31));
    v33 = _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v32),
            _mm_cvttps_epi32(v32));
    v34 = _mm_cvtsi128_si32(v33);
    if ( v34 >= v25 )
    {
      if ( v34 > v26 )
        v34 = 0x7FFFFF - v25;
    }
    else
    {
      v34 = v23->m_margin;
    }
    va.m_x = v34;
    v35 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v33, 85));
    if ( v35 >= v25 )
    {
      v25 = v35;
      if ( v35 > v26 )
        v25 = v26;
    }
    va.m_y = v25;
    if ( !v21 || getVertexHeight(originalMesha, facesInPartitiona, upa, array, retaddr, &va, &steinerPoints.m_data[v11]) )
      break;
LABEL_42:
    v22 = steinerPoints.m_size;
    v21 = v128;
    ++v11;
    ++v24;
    if ( v11 < steinerPoints.m_size )
      goto LABEL_25;
    v18 = resulta.m_edge.m_index;
LABEL_44:
    v11 = 0;
    if ( !v21 )
    {
      *(_QWORD *)&resulta.m_type.m_storage = 0i64;
      v38 = 0;
      resulta.m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)0x8000000000000000i64;
      if ( v22 <= 0 )
      {
        *(&resulta.m_edge.m_index + 1) = 0;
      }
      else
      {
        if ( v22 < 0 )
          v22 = 0;
        hkArrayUtil::_reserve(
          (hkResult *)&resulta.m_edge.m_index + 1,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &resulta,
          v22,
          16);
        if ( *(&resulta.m_edge.m_index + 1) )
        {
          v126 = v147;
          v127 = HIDWORD(resulta.m_edge.m_triangle);
          LODWORD(resulta.m_edge.m_triangle) = 0;
          v147->m_enum = 1;
          if ( v127 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)&resulta.m_type.m_storage,
              16 * v127);
          *(_QWORD *)&resulta.m_type.m_storage = 0i64;
          HIDWORD(resulta.m_edge.m_triangle) = 2147483648;
          other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            &other,
            1);
          other.m_stack.m_size = 0;
          if ( other.m_stack.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              other.m_stack.m_data,
              16 * other.m_stack.m_capacityAndFlags);
          other.m_stack.m_data = 0i64;
          other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          other.m_stack.m_capacityAndFlags = 2147483648;
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&other.m_mesh.m_triangles);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&other.m_mesh.m_vertices);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
          steinerPoints.m_size = 0;
          goto LABEL_112;
        }
        v22 = steinerPoints.m_size;
        v38 = (int)resulta.m_edge.m_triangle;
      }
      v39 = v22;
      if ( (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF) >= v22 )
      {
        LODWORD(va.m_next) = 0;
      }
      else
      {
        if ( v22 < 2 * (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF) )
          v22 = 2 * (HIDWORD(resulta.m_edge.m_triangle) & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          (hkResult *)&va,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &resulta,
          v22,
          16);
        v22 = steinerPoints.m_size;
        v38 = (int)resulta.m_edge.m_triangle;
      }
      v40 = v39 - v38;
      v41 = *(_QWORD *)&resulta.m_type.m_storage + 16i64 * v38;
      v42 = v39 - v38;
      if ( v40 > 0 )
      {
        do
        {
          v41 += 16i64;
          *(hkVector4f *)(v41 - 16) = (hkVector4f)aabbOut.m_quad;
          --v42;
        }
        while ( v42 );
        v22 = steinerPoints.m_size;
      }
      v43 = (__int64)v23->m_mesh.m_triangles.m_used;
      LODWORD(resulta.m_edge.m_triangle) = v39;
      if ( v43 )
      {
        do
        {
          if ( *(_BYTE *)(v43 + 184) & 0x20 )
          {
            v44 = retaddr->m_localToWorld.m_col0.m_quad;
            v45 = retaddr->m_localToWorld.m_col3.m_quad;
            v46 = retaddr->m_localToWorld.m_col1.m_quad;
            v134 = v43;
            v135[0] = 0;
            v136 = v43;
            v137 = 1;
            *(_QWORD *)&v138 = v43;
            DWORD2(v138) = 2;
            v47 = retaddr->m_localToWorld.m_col2.m_quad;
            v48 = 0i64;
            do
            {
              v49 = v135[v48];
              v50 = *(__int64 *)((char *)&v134 + v48 * 4);
              v48 += 4i64;
              v51 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)(*(_QWORD *)(v50 + 8 * v49 + 16) + 16i64)));
              v52 = (__m128)_mm_srli_si128(
                              _mm_slli_si128((__m128i)_mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, (__m128)0i64), 180), 4),
                              4);
              *(__int128 *)((char *)&v138 + v48 * 4) = (__int128)_mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v44),
                                                                       v45),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v46)),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v47));
            }
            while ( v48 < 12 );
            circumcenter2D(&v0, &v1, &v2, &ccOut);
            va.0 = (hkgpAbstractMeshDefinitions::Vertex<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase>)_mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
            v53 = _mm_sub_ps(ccOut.m_quad, v2.m_quad);
            *(__m128 *)&resulta.m_type.m_storage = _mm_shuffle_ps(
                                                     query.m_quad,
                                                     _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0),
                                                     196);
            v54 = _mm_sub_ps(v2.m_quad, v1.m_quad);
            v55 = _mm_sub_ps(ccOut.m_quad, v1.m_quad);
            v56 = _mm_sub_ps(v1.m_quad, v0.m_quad);
            v57 = _mm_sub_ps(ccOut.m_quad, v0.m_quad);
            v58 = _mm_shuffle_ps(v54, v54, 201);
            v59 = _mm_sub_ps(v0.m_quad, v2.m_quad);
            v60 = _mm_shuffle_ps(v56, v56, 201);
            v61 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v56), _mm_mul_ps(v60, v57));
            v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v54), _mm_mul_ps(v58, v55));
            v63 = _mm_sub_ps(_mm_mul_ps(v58, v56), _mm_mul_ps(v60, v54));
            v64 = _mm_shuffle_ps(v63, v63, 201);
            v65 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v59),
                    _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v53));
            v66 = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v64);
            v67 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v64);
            v68 = _mm_unpacklo_ps(v66, v67);
            v69 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v64);
            v70 = _mm_movelh_ps(v68, v69);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
                      (__m128)va.0,
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
                          _mm_cmpeqps((__m128)0i64, v72),
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
              v80 = _mm_mul_ps(v59, v59);
              v81 = _mm_movelh_ps(v78, v80);
              v82 = _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v81, v78), v80, 212), v81);
              v83 = _mm_mul_ps(v55, v54);
              v84 = _mm_add_ps(v82, _mm_shuffle_ps(v79, v80, 228));
              v85 = _mm_unpacklo_ps(v77, v83);
              v86 = _mm_unpackhi_ps(v77, v83);
              v87 = _mm_mul_ps(v53, v59);
              v88 = _mm_movelh_ps(v85, v87);
              v89 = _mm_andnot_ps(
                      _mm_cmpeqps(v84, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v88, v85), v87, 212), v88),
                          _mm_shuffle_ps(v86, v87, 228)),
                        _mm_rcp_ps(v84)));
              v90 = _mm_cmpltps(v89, *(__m128 *)&resulta.m_type.m_storage);
              v91 = _mm_max_ps(
                      (__m128)va.0,
                      _mm_or_ps(_mm_andnot_ps(v90, *(__m128 *)&resulta.m_type.m_storage), _mm_and_ps(v89, v90)));
              v92 = _mm_sub_ps(v57, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), v56));
              v93 = _mm_mul_ps(v92, v92);
              v94 = _mm_sub_ps(v55, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 85), v54));
              v95 = _mm_sub_ps(v53, _mm_mul_ps(_mm_shuffle_ps(v91, v91, 170), v59));
              v96 = _mm_mul_ps(v94, v94);
              v97 = _mm_cmpltps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                        _mm_shuffle_ps(v93, v93, 170)),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                        _mm_shuffle_ps(v96, v96, 170)));
              v98 = _mm_or_ps(_mm_and_ps(v92, v97), _mm_andnot_ps(v97, v94));
              v99 = _mm_mul_ps(v95, v95);
              v100 = _mm_mul_ps(v98, v98);
              v101 = _mm_cmpltps(
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
                       _mm_cmpleps(v108, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v109, v108), v109)),
                           _mm_mul_ps(*(__m128 *)_xmm, v109)),
                         v108)),
                     _mm_shuffle_ps(v74, _mm_unpackhi_ps(v74, query.m_quad), 196));
            do
            {
              v111 = array->m_size;
              v112 = *(_QWORD *)(*(_QWORD *)(*v103 + 8i64 * *((signed int *)v103 + 2) + 16) + 24i64) >> 2;
              if ( (signed int)v112 >= v111 )
                *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + 16i64 * ((signed int)v112 - v111)) = _mm_add_ps(v110, *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + 16i64 * ((signed int)v112 - v111)));
              v103 += 2;
              --v104;
            }
            while ( v104 );
          }
          v43 = *(_QWORD *)v43;
        }
        while ( v43 );
        v22 = steinerPoints.m_size;
        v12 = v142;
      }
      v113 = v22 - 1;
      v114 = v22 - 1;
      if ( v22 - 1 >= 0 )
      {
        v19 = v113;
        while ( 1 )
        {
          v115 = *(__m128 *)(*(_QWORD *)&resulta.m_type.m_storage + v19 * 16);
          v116 = _mm_shuffle_ps(v115, v115, 255);
          if ( v116.m128_f32[0] >= 0.00000011920929 )
            break;
          steinerPoints.m_size = --v22;
          if ( v22 != v113 )
          {
            v117 = 2i64;
            v118 = 16i64 * v22;
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
            goto LABEL_80;
          }
LABEL_81:
          --v113;
          --v19;
          if ( --v114 < 0 )
            goto LABEL_82;
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
LABEL_80:
        v22 = steinerPoints.m_size;
        goto LABEL_81;
      }
LABEL_82:
      LODWORD(resulta.m_edge.m_triangle) = 0;
      if ( SHIDWORD(resulta.m_edge.m_triangle) >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)&resulta.m_type.m_storage,
          (unsigned int)(16 * HIDWORD(resulta.m_edge.m_triangle)),
          v19 * 16);
      *(_QWORD *)&resulta.m_type.m_storage = 0i64;
      HIDWORD(resulta.m_edge.m_triangle) = 2147483648;
    }
    other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &other,
      1);
    other.m_stack.m_size = 0;
    if ( other.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        other.m_stack.m_data,
        16 * other.m_stack.m_capacityAndFlags);
    v123 = other.m_mesh.m_triangles.m_allocator.m_firstPool;
    other.m_stack.m_data = 0i64;
    other.m_stack.m_capacityAndFlags = 2147483648;
    for ( other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          other.m_mesh.m_triangles.m_allocator.m_firstPool;
          v123 = other.m_mesh.m_triangles.m_allocator.m_firstPool )
    {
      v124 = v123->m_links[0];
      if ( v124 )
        v124->m_links[1] = v123->m_links[1];
      else
        other.m_mesh.m_triangles.m_allocator.m_firstPool = v123->m_links[1];
      v125 = v123->m_links[1];
      if ( v125 )
        v125->m_links[0] = v123->m_links[0];
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v123,
        6688);
    }
    other.m_mesh.m_triangles.m_used = 0i64;
    other.m_mesh.m_triangles.m_numUsed = 0;
    hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
    hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&other.m_mesh.m_vertices);
    hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
    v9 = evs;
    resulta.m_edge.m_index = ++v18;
    if ( v18 >= evs[4].m_enum )
    {
      v10 = v147;
      goto LABEL_96;
    }
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
    v23,
    &resulta,
    v34,
    v25,
    1,
    icrossing);
  if ( resulta.m_type.m_storage != 10 && !v23->m_status.m_storage )
  {
    if ( !resulta.m_type.m_storage )
    {
      v36 = resulta.m_edge.m_triangle->m_vertices[resulta.m_edge.m_index];
      if ( v128 )
      {
        *((_QWORD *)v36 + 3) = *((_DWORD *)v36 + 6) & 3 | (unsigned __int64)(4i64 * array->m_size);
        v37 = steinerPoints.m_data;
        if ( array->m_size == (array->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, 16);
        array->m_data[array->m_size++] = v37[v24];
      }
      else
      {
        *((_QWORD *)v36 + 3) = *((_DWORD *)v36 + 6) & 3 | (unsigned __int64)(4i64 * (v11 + array->m_size));
      }
    }
    goto LABEL_42;
  }
  v126 = v147;
  v147->m_enum = 1;
  other.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    &other,
    1);
  other.m_stack.m_size = 0;
  if ( other.m_stack.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      other.m_stack.m_data,
      16 * other.m_stack.m_capacityAndFlags);
  other.m_stack.m_data = 0i64;
  other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
  other.m_stack.m_capacityAndFlags = 2147483648;
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&other.m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&other.m_mesh.m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&other.m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
  steinerPoints.m_size = 0;
LABEL_112:
  other.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  other.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  if ( steinerPoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      steinerPoints.m_data,
      16 * steinerPoints.m_capacityAndFlags);
  return v126;
}torBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&other.m_mesh.m_vertices);
  steinerPoints.m_size = 0;
LABEL_112:
  other.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  other.m_mesh.vfptr = (hkBaseObjec

// File Line: 702
// RVA: 0xB697D0
bool __fastcall compareVectorW(hkVector4f *vA, hkVector4f *vB)
{
  return COERCE_FLOAT(_mm_shuffle_ps(vA->m_quad, vA->m_quad, 255)) < COERCE_FLOAT(_mm_shuffle_ps(vB->m_quad, vB->m_quad, 255));
}

// File Line: 707
// RVA: 0xB62F50
hkResult *__fastcall hkaiNavMeshSimplificationUtils::getEdgeSplitting(hkResult *result, hkVector4f *vIn0, hkVector4f *vIn1, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings, bool isBoundary, hkBitField *userVertexOnBoundary, hkArray<hkVector4f,hkContainerHeapAllocator> *edgeVertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v8; // rdi
  int v9; // er9
  hkResult *v10; // r14
  int v11; // eax
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  int v14; // eax
  int v15; // eax
  int v16; // er10
  signed int v17; // er9
  float v18; // xmm8_4
  float v19; // xmm8_4
  hkBitField *v20; // rsi
  __m128 v21; // xmm7
  __int64 v22; // r11
  signed __int64 v23; // r8
  hkVector4f *v24; // rax
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  __m128 v38; // xmm6
  float v39; // xmm0_4
  signed int v40; // eax
  bool v41; // cl
  int v42; // edx
  hkBool *v43; // rax
  char v44; // r15
  unsigned __int128 v45; // xmm0
  __m128 v46; // xmm10
  __int64 v47; // rbp
  signed __int64 v48; // rsi
  __m128 v49; // xmm6
  __m128 v50; // xmm8
  __m128 v51; // xmm1
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  float v55; // xmm4_4
  float v56; // xmm1_4
  int v57; // eax
  __m128 v58; // xmm8
  signed int v59; // edi
  int v60; // er9
  int v61; // eax
  hkResultEnum v62; // eax
  __m128 v63; // xmm1
  __m128 v64; // xmm1
  __m128 v65; // xmm0
  __m128 v66; // xmm7
  __m128 v67; // xmm7
  __int64 v68; // rcx
  hkResult resulta; // [rsp+D8h] [rbp+10h]

  v7 = edgeVertices;
  v8 = extraVertexSettings;
  v9 = extraVertexSettings->m_userVertices.m_size + 2;
  v10 = result;
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
    hkArrayUtil::_reserve(
      (hkResult *)&edgeVertices,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      edgeVertices,
      v9,
      16);
    if ( (_DWORD)edgeVertices )
    {
      v10->m_enum = 1;
      return v10;
    }
  }
  v7->m_data[v7->m_size++].m_quad = v12;
  v15 = v8->m_userVertices.m_size;
  if ( v15 > 0 )
  {
    v16 = 0;
    v17 = 1;
    LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)LODWORD(v8->m_userVertexOnBoundaryTolerance),
                                        (__m128)LODWORD(v8->m_userVertexOnBoundaryTolerance),
                                        0);
    v19 = v18 * v18;
    if ( v15 > 0 )
    {
      v20 = userVertexOnBoundary;
      v21 = query.m_quad;
      v22 = 0i64;
      do
      {
        v23 = (signed __int64)v16 >> 5;
        if ( !((v20->m_storage.m_words.m_data[v23] >> (v16 & 0x1F)) & 1) )
        {
          v24 = v8->m_userVertices.m_data;
          v25 = _mm_sub_ps(v12, v13);
          v26 = _mm_sub_ps(v12, v24[v22].m_quad);
          v27 = _mm_mul_ps(v25, v25);
          v28 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170));
          v29 = _mm_mul_ps(v26, v25);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v31 = _mm_rcp_ps(v28);
          v32 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v28)), v31), v30);
          v33 = _mm_cmpltps(v32, v21);
          v34 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v33, v21), _mm_and_ps(v32, v33)));
          v35 = _mm_sub_ps(v26, _mm_mul_ps(v34, v25));
          v36 = _mm_mul_ps(v35, v35);
          v37 = _mm_add_ps(v35, v24[v22].m_quad);
          v38 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v34), 196);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170))) < v19 )
          {
            LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(v38, v38, 255);
            if ( v39 > 0.0 && v39 < v21.m128_f32[0] )
            {
              v7->m_data[v7->m_size++].m_quad = v38;
              v20->m_storage.m_words.m_data[v23] |= v17;
              v21 = query.m_quad;
            }
          }
        }
        v17 = __ROL4__(v17, 1);
        ++v16;
        ++v22;
      }
      while ( v16 < v8->m_userVertices.m_size );
    }
    v40 = v7->m_size;
    if ( v40 > 2 && v40 - 1 > 1 )
      hkAlgorithm::quickSortRecursive<hkVector4f,bool (*)(hkVector4f const &,hkVector4f const &)>(
        v7->m_data + 1,
        0,
        v40 - 2,
        compareVectorW);
  }
  v41 = isBoundary;
  v7->m_data[v7->m_size++].m_quad = v13;
  v42 = v7->m_size;
  v43 = &v8->m_addVerticesOnBoundaryEdges;
  if ( !v41 )
    v43 = &v8->m_addVerticesOnPartitionBorders;
  if ( v43->m_bool )
  {
    v44 = 0;
    v45 = v41 ? (unsigned __int128)LODWORD(v8->m_boundaryEdgeSplitLength) : (unsigned __int128)LODWORD(v8->m_partitionBordersSplitLength);
    v46 = _mm_shuffle_ps((__m128)v45, (__m128)v45, 0);
    v47 = v42 - 1;
    if ( v42 - 1 > 0 )
    {
      v48 = v42 - 1;
      do
      {
        v49 = v7->m_data[v48].m_quad;
        v50 = v7->m_data[v48 - 1].m_quad;
        v51 = _mm_sub_ps(v7->m_data[v48].m_quad, v50);
        v52 = _mm_mul_ps(v51, v51);
        v53 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170));
        v54 = _mm_rsqrt_ps(v53);
        LODWORD(v55) = (unsigned __int128)_mm_andnot_ps(
                                            _mm_cmpleps(v53, (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                                                _mm_mul_ps(v54, *(__m128 *)_xmm)),
                                              v53));
        if ( v55 > v46.m128_f32[0] )
        {
          LODWORD(v56) = (unsigned __int128)_mm_rcp_ps(v46);
          v57 = v7->m_capacityAndFlags & 0x3FFFFFFF;
          v58 = _mm_sub_ps(v50, v49);
          v44 = 1;
          v59 = (signed int)(float)((float)((float)(2.0 - (float)(v46.m128_f32[0] * v56)) * v56) * v55);
          v60 = v59 + v7->m_size;
          if ( v57 >= v60 )
          {
            v62 = 0;
            resulta.m_enum = 0;
          }
          else
          {
            v61 = 2 * v57;
            if ( v60 < v61 )
              v60 = v61;
            hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v60, 16);
            v62 = resulta.m_enum;
          }
          LODWORD(edgeVertices) = v62;
          if ( v62 )
          {
            v10->m_enum = 1;
            return v10;
          }
          v63 = 0i64;
          v63.m128_f32[0] = (float)(v59 + 1);
          v64 = _mm_shuffle_ps(v63, v63, 0);
          v65 = _mm_rcp_ps(v64);
          v66 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v64, v65)), v65);
          if ( v59 > 0 )
          {
            v67 = _mm_mul_ps(v66, v58);
            v68 = (unsigned int)v59;
            do
            {
              v49 = _mm_add_ps(v49, v67);
              v7->m_data[v7->m_size++].m_quad = v49;
              --v68;
            }
            while ( v68 );
          }
        }
        --v47;
        --v48;
      }
      while ( v47 > 0 );
      if ( v44 && v7->m_size - 1 > 1 )
        hkAlgorithm::quickSortRecursive<hkVector4f,bool (*)(hkVector4f const &,hkVector4f const &)>(
          v7->m_data + 1,
          0,
          v7->m_size - 2,
          compareVectorW);
    }
  }
  v10->m_enum = 0;
  return v10;
}

// File Line: 795
// RVA: 0xB61110
hkResult *__fastcall hkaiNavMeshSimplificationUtils::triangulatePartition(hkResult *result, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *extraVertexSettings, hkaiNavMesh *originalMesh, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, hkArray<int,hkContainerTempAllocator> *partitionSegments, hkArray<int const ,hkContainerHeapAllocator> *facesInPartition, hkVector4f *up, hkArray<int,hkContainerTempAllocator> *triangleIndicesOut, hkArray<int,hkContainerTempAllocator> *sharedEdgesOut, hkBitField *edgeIsBoundary, hkBitField *userVertexOnBoundary, hkReferencedObject *globalTriangulatorPtr, hkAabb *globalDomainAabb)
{
  hkVector4f v14; // xmm4
  __int64 v15; // r15
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v16; // rdi
  __int64 v17; // r11
  bool v18; // bl
  hkResult *v19; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v20; // r12
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v21; // r13
  __int64 v22; // r8
  hkVector4f v23; // xmm3
  __int64 v24; // rdx
  signed int *v25; // rcx
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
  signed __int64 v36; // rbx
  int v37; // er9
  int v38; // er9
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v39; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v40; // rdx
  float v41; // er8
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v42; // rcx
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
  signed __int64 v65; // rdi
  int v66; // eax
  int v67; // er9
  __int64 v68; // r8
  int v69; // er9
  float v70; // er10
  __int64 v71; // rax
  hkVector4f *v72; // rcx
  __int64 v73; // r9
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  unsigned __int64 v76; // rax
  signed __int64 v77; // rdx
  __m128 v78; // xmm2
  signed int *v79; // r9
  bool v80; // cl
  signed int v81; // eax
  int v82; // er8
  __int64 v83; // r15
  int v84; // ebx
  int v85; // edi
  int v86; // esi
  hkLifoAllocator *v87; // rax
  char *v88; // r13
  int v89; // edx
  char *v90; // rcx
  char *v91; // rax
  signed int v92; // ebx
  int v93; // er9
  int v94; // eax
  int v95; // er9
  int v96; // eax
  int v97; // ebx
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
  hkResultEnum v108; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v109; // rdx
  signed __int64 v110; // r9
  signed __int64 v111; // rax
  int v112; // edi
  signed __int64 v113; // rbx
  int v114; // edx
  int v115; // ecx
  int v116; // er9
  int v117; // er10
  __int64 v118; // rax
  unsigned __int64 v119; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v120; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v121; // r8
  int v122; // eax
  int v123; // edx
  unsigned __int64 v124; // r8
  unsigned __int64 v125; // r8
  signed int v126; // ebx
  hkLifoAllocator *v127; // rax
  int v128; // er8
  hkResultEnum v129; // eax
  unsigned int v130; // ecx
  signed int v131; // edi
  hkLifoAllocator *v132; // rax
  int v133; // er8
  unsigned int v134; // ecx
  int v135; // ebx
  hkLifoAllocator *v136; // rax
  int v137; // er8
  unsigned int v138; // ecx
  int v139; // ebx
  hkLifoAllocator *v140; // rax
  int v141; // er8
  int v142; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *k; // rax
  hkArray<int const ,hkContainerHeapAllocator> *v144; // rdi
  hkaiNavMesh *v145; // r15
  char v146; // cl
  unsigned __int64 l; // rsi
  __int64 v148; // rax
  unsigned __int64 v149; // r12
  __int64 v150; // rax
  unsigned __int64 v151; // r12
  __int64 v152; // r13
  __int64 v153; // r15
  signed int v154; // eax
  int v155; // er9
  int v156; // eax
  int v157; // eax
  int v158; // er9
  int v159; // eax
  int v160; // eax
  hkResultEnum v161; // eax
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v162; // rax
  signed int v163; // edx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v164; // rax
  signed int v165; // edx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v166; // rax
  signed int v167; // edx
  hkResult v169[2]; // [rsp+48h] [rbp-78h]
  hkVector4f dmax; // [rsp+50h] [rbp-70h]
  hkVector4f dmin; // [rsp+60h] [rbp-60h]
  __int64 v172; // [rsp+70h] [rbp-50h]
  hkResult resulta[2]; // [rsp+78h] [rbp-48h]
  __int64 v174; // [rsp+80h] [rbp-40h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v175; // [rsp+88h] [rbp-38h]
  hkAabb partitionAabb; // [rsp+A0h] [rbp-20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+C0h] [rbp+0h]
  __int64 v178; // [rsp+D0h] [rbp+10h]
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > icrossing; // [rsp+D8h] [rbp+18h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex v0; // [rsp+F0h] [rbp+30h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex v1; // [rsp+110h] [rbp+50h]
  hkVector4f vIn1; // [rsp+130h] [rbp+70h]
  hkVector4f vIn0; // [rsp+140h] [rbp+80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> v184; // [rsp+150h] [rbp+90h]
  hkResult *v185; // [rsp+EC0h] [rbp+E00h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v186; // [rsp+EC8h] [rbp+E08h]
  hkaiNavMesh *originalMesha; // [rsp+ED0h] [rbp+E10h]
  __int64 v188; // [rsp+ED8h] [rbp+E18h]
  unsigned __int64 *v189; // [rsp+EE0h] [rbp+E20h]
  hkResult v190[2]; // [rsp+EE8h] [rbp+E28h]
  hkArray<int const ,hkContainerHeapAllocator> *vars0; // [rsp+EF0h] [rbp+E30h]
  hkVector4f *retaddr; // [rsp+EF8h] [rbp+E38h]
  hkResult *array; // [rsp+F00h] [rbp+E40h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v194; // [rsp+F08h] [rbp+E48h]
  hkaiNavMesh *v195; // [rsp+F10h] [rbp+E50h]
  hkBitField *v196; // [rsp+F18h] [rbp+E58h]

  v196 = (hkBitField *)vertices;
  v195 = originalMesh;
  v194 = extraVertexSettings;
  array = result;
  v14.m_quad = (__m128)xmmword_141A712A0;
  v15 = *(_QWORD *)&v190[0].m_enum;
  v16 = segments;
  v17 = *(signed int *)(*(_QWORD *)&v190[0].m_enum + 8i64);
  partitionAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v18 = segments == 0i64;
  v19 = result;
  v20 = vertices;
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
      v24 = *(signed int *)(*v189 + 48i64 * *(signed int *)(**(_QWORD **)&v190[0].m_enum + 4 * v22) + 40);
      if ( v24 > 0 )
      {
        v25 = *(signed int **)(*v189 + 48i64 * *(signed int *)(**(_QWORD **)&v190[0].m_enum + 4 * v22) + 32);
        do
        {
          v26 = *v25;
          ++v25;
          v27 = vertices->m_data[v26].m_quad;
          v14.m_quad = _mm_min_ps(v14.m_quad, v27);
          v23.m_quad = _mm_max_ps(v23.m_quad, v27);
          if ( (_mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmpleps(v27, (__m128)partitionSegments[1]),
                    _mm_cmpleps(*(__m128 *)partitionSegments, v27))) & 7) != 7 )
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
  _mm_store_si128((__m128i *)&v184.m_mesh.m_vertices, (__m128i)0i64);
  v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
  v184.m_mesh.m_vertices.m_numUsed = 0;
  v184.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
  dmin.m_quad = (__m128)_xmm;
  dmax.m_quad = _xmm;
  v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
  v184.m_mesh.m_triangles.m_used = 0i64;
  v184.m_mesh.m_triangles.m_numUsed = 0;
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
    dmax.m_quad.m128_u64[1] = 0x8000000000000000i64;
    if ( *(_DWORD *)(v15 + 8) > 0 )
    {
      v32 = *(_QWORD *)&v190[0].m_enum;
      v33 = 0i64;
      do
      {
        v34 = *(signed int *)(*(_QWORD *)v32 + v33);
        v35 = *v189;
        v36 = 6 * v34;
        v37 = v30 + *(_DWORD *)(*v189 + 48 * v34 + 40);
        if ( (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF) >= v37 )
        {
          LODWORD(segments) = v29;
        }
        else
        {
          if ( v37 < 2 * (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            v37 = 2 * (dmax.m_quad.m128_i32[3] & 0x3FFFFFFF);
          hkArrayUtil::_reserve(
            (hkResult *)&segments,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &dmax,
            v37,
            16);
          if ( (_DWORD)segments )
          {
            v19 = v185;
            v41 = dmax.m_quad.m128_f32[3];
            dmax.m_quad.m128_i32[2] = 0;
            v185->m_enum = 1;
            if ( v41 >= 0.0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                16 * LODWORD(v41));
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 2147483648;
            v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v184,
              1);
            v184.m_stack.m_size = 0;
            if ( v184.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v184.m_stack.m_data,
                16 * v184.m_stack.m_capacityAndFlags);
            v42 = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
            v184.m_stack.m_data = 0i64;
            v184.m_stack.m_capacityAndFlags = 2147483648;
            for ( v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
                  v184.m_mesh.m_triangles.m_allocator.m_firstPool;
                  v42 = v184.m_mesh.m_triangles.m_allocator.m_firstPool )
            {
              v43 = v42->m_links[0];
              if ( v43 )
                v43->m_links[1] = v42->m_links[1];
              else
                v184.m_mesh.m_triangles.m_allocator.m_firstPool = v42->m_links[1];
              v44 = v42->m_links[1];
              if ( v44 )
                v44->m_links[0] = v42->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v42,
                6688);
            }
            v184.m_mesh.m_triangles.m_used = 0i64;
            v184.m_mesh.m_triangles.m_numUsed = 0;
            if ( v42 )
            {
              do
              {
                v45 = v42->m_links[0];
                if ( v45 )
                  v45->m_links[1] = v42->m_links[1];
                else
                  v184.m_mesh.m_triangles.m_allocator.m_firstPool = v42->m_links[1];
                v46 = v42->m_links[1];
                if ( v46 )
                  v46->m_links[0] = v42->m_links[0];
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v42,
                  6688);
                v42 = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
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
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                i,
                1568);
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
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  i,
                  1568);
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
        v38 = v29;
        if ( *(_DWORD *)(v35 + 8 * v36 + 40) > 0 )
        {
          do
          {
            ++v38;
            v29 += 4i64;
            *(hkVector4f *)(dmax.m_quad.m128_u64[0] + 16i64 * v30) = v20->m_data[*(signed int *)(*(_QWORD *)(v35 + 8 * v36 + 32)
                                                                                               + v29
                                                                                               - 4)];
            v30 = dmax.m_quad.m128_i32[2]++ + 1;
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
    dmin.m_quad.m128_u64[1] = __PAIR__(16, v30);
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
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
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
    v19->m_enum = 1;
    v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v184,
      1);
    v184.m_stack.m_size = 0;
    if ( v184.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v184.m_stack.m_data,
        16 * v184.m_stack.m_capacityAndFlags);
    v39 = v184.m_mesh.m_triangles.m_allocator.m_firstPool;
    v184.m_stack.m_data = 0i64;
    v184.m_stack.m_capacityAndFlags = 2147483648;
    for ( v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
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
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v39,
        6688);
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
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v39,
          6688);
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
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        j,
        1568);
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
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          j,
          1568);
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
  if ( *(_DWORD *)(v15 + 8) <= 0 )
  {
LABEL_170:
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::partition(v28) == -1 )
    {
      v19 = v185;
      v185->m_enum = 1;
      v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v184,
        1);
      v184.m_stack.m_size = 0;
      if ( v184.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v184.m_stack.m_data,
          16 * v184.m_stack.m_capacityAndFlags);
      v184.m_stack.m_data = 0i64;
LABEL_270:
      v184.m_stack.m_capacityAndFlags = 2147483648;
      hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::~hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>(&v184.m_mesh);
      return v19;
    }
    v142 = 0;
    if ( v21->m_vertexFraction > 0.0 )
    {
      for ( k = v28->m_mesh.m_triangles.m_used; k; k = k->m_next )
      {
        if ( *((_BYTE *)k + 184) & 0x20 )
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
        v196,
        (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing,
        v20);
      if ( v190[0].m_enum )
      {
LABEL_227:
        v19 = v185;
        v185->m_enum = 1;
        v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          &v184,
          1);
LABEL_267:
        v184.m_stack.m_size = 0;
        if ( v184.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v184.m_stack.m_data,
            16 * v184.m_stack.m_capacityAndFlags);
        v184.m_stack.m_data = 0i64;
        goto LABEL_270;
      }
      v146 = 1;
    }
    if ( (signed int)(float)((float)v142 * v21->m_vertexFraction) || !v21->m_vertexSelectionMethod.m_storage )
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
        v20);
      if ( v190[0].m_enum )
        goto LABEL_227;
    }
    else if ( !v146 )
    {
      goto LABEL_235;
    }
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::partition(v28) == -1 )
      goto LABEL_227;
LABEL_235:
    for ( l = (unsigned __int64)v28->m_mesh.m_triangles.m_used; l; l = *(_QWORD *)l )
    {
      if ( *(_BYTE *)(l + 184) & 0x20 )
      {
        v148 = *(_QWORD *)(l + 16);
        partitionAabb.m_min.m_quad.m128_u64[0] = l;
        v149 = *(_QWORD *)(v148 + 24);
        v150 = *(_QWORD *)(l + 24);
        partitionAabb.m_min.m_quad.m128_i32[2] = 0;
        v151 = v149 >> 2;
        v152 = *(_QWORD *)(v150 + 24) >> 2;
        v153 = *(_QWORD *)(*(_QWORD *)(l + 32) + 24i64) >> 2;
        partitionAabb.m_max.m_quad.m128_u64[0] = l;
        edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)l;
        partitionAabb.m_max.m_quad.m128_i32[2] = 1;
        edge.m_index = 2;
        if ( (_DWORD)v151 != (_DWORD)v152 && (_DWORD)v151 != (_DWORD)v153 && (_DWORD)v152 != (_DWORD)v153 )
        {
          v154 = *(_DWORD *)(v188 + 8);
          if ( (signed int)v151 < v154 && (signed int)v152 < v154 && (signed int)v153 < v154 )
          {
            v155 = array[2].m_enum + 3;
            v156 = array[3].m_enum & 0x3FFFFFFF;
            if ( v156 >= v155 )
            {
              LODWORD(segments) = 0;
            }
            else
            {
              v157 = 2 * v156;
              if ( v155 < v157 )
                v155 = v157;
              hkArrayUtil::_reserve(
                (hkResult *)&segments,
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                array,
                v155,
                4);
            }
            v158 = LODWORD(v194->m_areaFraction) + 3;
            v159 = LODWORD(v194->m_minPartitionArea) & 0x3FFFFFFF;
            if ( v159 >= v158 )
            {
              v161 = 0;
              v190[0].m_enum = 0;
            }
            else
            {
              v160 = 2 * v159;
              if ( v158 < v160 )
                v158 = v160;
              hkArrayUtil::_reserve(v190, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v194, v158, 4);
              v161 = v190[0].m_enum;
            }
            if ( (_DWORD)segments || v161 )
              goto LABEL_227;
            *(_DWORD *)(*(_QWORD *)&array->m_enum + 4i64 * (signed int)array[2].m_enum++) = v151;
            *(_DWORD *)(*(_QWORD *)&array->m_enum + 4i64 * (signed int)array[2].m_enum++) = v152;
            *(_DWORD *)(*(_QWORD *)&array->m_enum + 4i64 * (signed int)array[2].m_enum++) = v153;
            v162 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                     v28,
                     (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&partitionAabb);
            if ( v162 )
              v163 = *(_DWORD *)v162->m_tags.m_data;
            else
              v163 = -2;
            *(_DWORD *)(*(_QWORD *)&v194->m_vertexSelectionMethod.m_storage
                      + 4i64 * (signed int)LODWORD(v194->m_areaFraction)++) = v163;
            v164 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                     v28,
                     (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&partitionAabb.m_max);
            if ( v164 )
              v165 = *(_DWORD *)v164->m_tags.m_data;
            else
              v165 = -2;
            *(_DWORD *)(*(_QWORD *)&v194->m_vertexSelectionMethod.m_storage
                      + 4i64 * (signed int)LODWORD(v194->m_areaFraction)++) = v165;
            v166 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                     v28,
                     &edge);
            if ( v166 )
              v167 = *(_DWORD *)v166->m_tags.m_data;
            else
              v167 = -2;
            *(_DWORD *)(*(_QWORD *)&v194->m_vertexSelectionMethod.m_storage
                      + 4i64 * (signed int)LODWORD(v194->m_areaFraction)++) = v167;
          }
        }
      }
    }
    v19 = v185;
    v185->m_enum = 0;
    v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v184,
      1);
    goto LABEL_267;
  }
  while ( 1 )
  {
    v62 = 0i64;
    v169[0].m_enum = 0;
    v63 = *(signed int *)(*(_QWORD *)v15 + 4 * v60);
    v174 = 0i64;
    v64 = *v189;
    v65 = 48 * v63;
    dmin.m_quad.m128_u64[0] = v64;
    v66 = *(_DWORD *)(48 * v63 + v64 + 40);
    v178 = 48 * v63;
    if ( v66 - 1 > 0 )
      break;
LABEL_169:
    ++v61;
    v60 = v172 + 1;
    dmax.m_quad.m128_i32[0] = v61;
    ++v172;
    if ( v61 >= *(_DWORD *)(v15 + 8) )
      goto LABEL_170;
  }
  while ( 1 )
  {
    v67 = v21->m_userVertices.m_size;
    v68 = 0i64;
    dmax.m_quad.m128_u64[0] = 0i64;
    v69 = v67 + 2;
    v70 = 0.0;
    dmax.m_quad.m128_u64[1] = 0x8000000000000000i64;
    if ( v69 <= 0 )
    {
      dmax.m_quad.m128_i32[1] = 0;
    }
    else
    {
      if ( v69 < 0 )
        v69 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&dmax.m_quad.m128_i16[2],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &dmax,
        v69,
        16);
      if ( dmax.m_quad.m128_i32[1] )
      {
        v19 = v185;
        v185->m_enum = 1;
LABEL_175:
        dmax.m_quad.m128_i32[2] = 0;
        if ( dmax.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)dmax.m_quad.m128_u64[0],
            16 * dmax.m_quad.m128_i32[3]);
        dmax.m_quad.m128_u64[0] = 0i64;
        dmax.m_quad.m128_i32[3] = 2147483648;
        v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          &v184,
          1);
        v184.m_stack.m_size = 0;
        if ( v184.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v184.m_stack.m_data,
            16 * v184.m_stack.m_capacityAndFlags);
        v184.m_stack.m_data = 0i64;
        goto LABEL_180;
      }
      v70 = dmax.m_quad.m128_f32[2];
      v68 = dmax.m_quad.m128_u32[0];
    }
    v71 = *(_QWORD *)(v65 + v64 + 32);
    v72 = v20->m_data;
    v73 = *(signed int *)(v71 + 4 * v62 + 4);
    resulta[0] = *(hkResult *)(v71 + 4 * v62);
    dmax.m_quad.m128_i32[2] = v73;
    v74 = v72[v73].m_quad;
    v75 = _mm_shuffle_ps(
            v72[resulta[0].m_enum].m_quad,
            _mm_unpackhi_ps(v72[resulta[0].m_enum].m_quad, (__m128)0i64),
            196);
    v76 = *v189;
    v77 = 3i64 * *(signed int *)(*(_QWORD *)v15 + 4 * v172);
    vIn0.m_quad = v75;
    v78 = _mm_shuffle_ps(v74, _mm_unpackhi_ps(v74, query.m_quad), 196);
    vIn1.m_quad = v78;
    v79 = *(signed int **)(v76 + 16 * v77 + 16);
    if ( *v79 >= SLODWORD(v195->m_faces.m_data) )
      goto LABEL_274;
    if ( (*((_DWORD *)&v195->vfptr->__vecDelDtor + ((signed __int64)*v79 >> 5)) >> (*v79 & 0x1F)) & 1 )
    {
      v80 = 1;
      v81 = -1;
    }
    else
    {
LABEL_274:
      v81 = v79[v62];
      v80 = 0;
    }
    dmin.m_quad.m128_u64[1] = (unsigned __int64)resulta;
    *(_QWORD *)&resulta[0].m_enum = v81;
    v172 = -9223372028264841215i64;
    if ( v80 )
    {
      hkaiNavMeshSimplificationUtils::getEdgeSplitting(
        &resulta[1],
        &vIn0,
        &vIn1,
        v21,
        v80,
        v196,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)&dmax);
      if ( resulta[1].m_enum )
      {
        v19 = v185;
        v185->m_enum = 1;
LABEL_182:
        LODWORD(v172) = 0;
        if ( v172 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)dmin.m_quad.m128_u64[1],
            8 * HIDWORD(v172));
        dmin.m_quad.m128_u64[1] = 0i64;
        HIDWORD(v172) = 2147483648;
        goto LABEL_175;
      }
      v82 = dmax.m_quad.m128_i32[2];
    }
    else
    {
      *(__m128 *)(v68 + 16i64 * SLODWORD(v70)) = v75;
      ++dmax.m_quad.m128_i32[2];
      *(__m128 *)(dmax.m_quad.m128_u64[0] + 16i64 * dmax.m_quad.m128_i32[2]) = v78;
      v82 = dmax.m_quad.m128_i32[2]++ + 1;
    }
    v83 = 0i64;
    v84 = v82;
    v85 = v82;
    LODWORD(segments) = v82;
    v86 = 0;
    if ( v82 )
    {
      v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v88 = (char *)v87->m_cur;
      v89 = (32 * v84 + 127) & 0xFFFFFF80;
      v90 = &v88[v89];
      if ( v89 > v87->m_slabSize || v90 > v87->m_end )
      {
        v91 = (char *)hkLifoAllocator::allocateFromNewSlab(v87, v89);
        v82 = dmax.m_quad.m128_i32[2];
        v88 = v91;
      }
      else
      {
        v87->m_cur = v90;
        v82 = dmax.m_quad.m128_i32[2];
      }
    }
    else
    {
      v88 = 0i64;
    }
    v92 = v84 | 0x80000000;
    v93 = v20->m_size - 2;
    v94 = v20->m_capacityAndFlags & 0x3FFFFFFF;
    dmin.m_quad.m128_i32[0] = v92;
    v95 = v82 + v93;
    if ( v94 < v95 )
      break;
    v169[1].m_enum = 0;
LABEL_124:
    if ( v82 > 0 )
    {
      while ( 1 )
      {
        v97 = v28->m_margin;
        v98 = *(__m128 *)(dmax.m_quad.m128_u64[0] + 16 * v83);
        v99 = 0x7FFFFF - v97;
        v100 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), v28->m_worldToLocal.m_col0.m_quad),
                     v28->m_worldToLocal.m_col3.m_quad),
                   _mm_mul_ps(
                     _mm_shuffle_ps(*(__m128 *)(dmax.m_quad.m128_u64[0] + 16 * v83), v98, 85),
                     v28->m_worldToLocal.m_col1.m_quad)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(*(__m128 *)(dmax.m_quad.m128_u64[0] + 16 * v83), v98, 170),
                   v28->m_worldToLocal.m_col2.m_quad));
        v101 = _mm_sub_ps(v100, (__m128)xmmword_141A711B0);
        v102 = _mm_add_ps(v100, (__m128)xmmword_141A711B0);
        v103 = _mm_cmpltps(v100, (__m128)0i64);
        v104 = _mm_or_ps(_mm_andnot_ps(v103, v102), _mm_and_ps(v101, v103));
        v105 = _mm_xor_si128(
                 (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v104),
                 _mm_cvttps_epi32(v104));
        v106 = _mm_cvtsi128_si32(v105);
        if ( v106 >= v97 )
        {
          if ( v106 > v99 )
            v106 = 0x7FFFFF - v97;
        }
        else
        {
          v106 = v28->m_margin;
        }
        v107 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v105, 85));
        if ( v107 >= v97 )
        {
          v97 = v107;
          if ( v107 > v99 )
            v97 = v99;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
          v28,
          &v175,
          v106,
          v97,
          1,
          (hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> > *)&icrossing);
        if ( v175.m_type.m_storage == 10 || v28->m_status.m_storage )
          break;
        if ( v83 )
        {
          if ( v86 == dmax.m_quad.m128_i32[2] - 1 )
          {
            v108 = dmax.m_quad.m128_i32[2];
          }
          else
          {
            v108 = v20->m_size;
            v20->m_data[v20->m_size++].m_quad = v98;
          }
        }
        else
        {
          v108 = resulta[0].m_enum;
        }
        v109 = v175.m_edge.m_triangle->m_vertices[v175.m_edge.m_index];
        v110 = 4i64 * (signed int)v108 | *((_BYTE *)&v0 + 24) & 3;
        *((_QWORD *)v109 + 3) = 4i64 * (signed int)v108 | *((_DWORD *)v109 + 6) & 3;
        v111 = (signed __int64)&v88[32 * v86];
        if ( v111 )
        {
          *(_DWORD *)(v111 + 16) = v106;
          *(_DWORD *)(v111 + 20) = v97;
          *(_QWORD *)(v111 + 24) = v110;
        }
        v82 = dmax.m_quad.m128_i32[2];
        ++v86;
        ++v83;
        if ( v86 >= dmax.m_quad.m128_i32[2] )
          goto LABEL_142;
      }
      v19 = v185;
      v134 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v135 = 32 * (_DWORD)segments + 127;
      v185->m_enum = 1;
      v135 &= 0xFFFFFF80;
      v136 = (hkLifoAllocator *)TlsGetValue(v134);
      v137 = (v135 + 15) & 0xFFFFFFF0;
      if ( v135 > v136->m_slabSize || &v88[v137] != v136->m_cur || v136->m_firstNonLifoEnd == v88 )
        hkLifoAllocator::slowBlockFree(v136, v88, v137);
      else
        v136->m_cur = v88;
      if ( dmin.m_quad.m128_i32[0] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v88,
          32 * dmin.m_quad.m128_i32[0]);
      goto LABEL_182;
    }
LABEL_142:
    v112 = 0;
    if ( v82 - 1 > 0 )
    {
      v113 = (signed __int64)(v88 + 52);
      do
      {
        v114 = *(_DWORD *)(v113 - 36);
        v115 = *(_DWORD *)(v113 - 4);
        v116 = *(_DWORD *)(v113 - 32);
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
            v185->m_enum = 1;
            v139 &= 0xFFFFFF80;
            v140 = (hkLifoAllocator *)TlsGetValue(v138);
            v141 = (v139 + 15) & 0xFFFFFFF0;
            if ( v139 > v140->m_slabSize || &v88[v141] != v140->m_cur || v140->m_firstNonLifoEnd == v88 )
              hkLifoAllocator::slowBlockFree(v140, v88, v141);
            else
              v140->m_cur = v88;
            if ( dmin.m_quad.m128_i32[0] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v88,
                32 * dmin.m_quad.m128_i32[0]);
            LODWORD(v172) = 0;
            if ( v172 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                (void *)dmin.m_quad.m128_u64[1],
                8 * HIDWORD(v172));
            dmin.m_quad.m128_u64[1] = 0i64;
            HIDWORD(v172) = 2147483648;
            dmax.m_quad.m128_i32[2] = 0;
            if ( dmax.m_quad.m128_i32[3] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                16 * dmax.m_quad.m128_i32[3]);
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 2147483648;
            v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v184,
              1);
            v184.m_stack.m_size = 0;
            if ( v184.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v184.m_stack.m_data,
                16 * v184.m_stack.m_capacityAndFlags);
            v184.m_stack.m_data = 0i64;
            goto LABEL_180;
          }
          LOBYTE(v119) = v175.m_edge.m_index;
          v120 = v175.m_edge.m_triangle->m_vertices[v175.m_edge.m_index];
          v121 = v175.m_edge.m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(v175.m_edge.m_index)) & 3];
          v122 = v120->m_x;
          v123 = v121->m_x;
          if ( v122 >= v123
            && (v122 > v123 || v120->m_y > v121->m_y)
            && (v124 = v175.m_edge.m_triangle->m_links[v175.m_edge.m_index], v124 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v119 = v175.m_edge.m_triangle->m_links[v175.m_edge.m_index] & 3;
            v125 = v124 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v125 = (unsigned __int64)v175.m_edge.m_triangle;
          }
          *(_WORD *)(v125 + 184) ^= ((unsigned __int8)*(_WORD *)(v125 + 184) ^ (unsigned __int8)(*(unsigned __int16 *)(v125 + 184) | (1 << v119))) & 7;
          v82 = dmax.m_quad.m128_i32[2];
        }
        ++v112;
        v113 += 32i64;
      }
      while ( v112 < v82 - 1 );
    }
    v126 = (32 * (_DWORD)segments + 127) & 0xFFFFFF80;
    v127 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v128 = (v126 + 15) & 0xFFFFFFF0;
    if ( v126 > v127->m_slabSize || &v88[v128] != v127->m_cur || v127->m_firstNonLifoEnd == v88 )
      hkLifoAllocator::slowBlockFree(v127, v88, v128);
    else
      v127->m_cur = v88;
    if ( dmin.m_quad.m128_i32[0] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v88,
        32 * dmin.m_quad.m128_i32[0]);
    LODWORD(v172) = 0;
    if ( v172 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)dmin.m_quad.m128_u64[1],
        8 * HIDWORD(v172));
    dmin.m_quad.m128_u64[1] = 0i64;
    HIDWORD(v172) = 2147483648;
    dmax.m_quad.m128_i32[2] = 0;
    if ( dmax.m_quad.m128_i32[3] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)dmax.m_quad.m128_u64[0],
        16 * dmax.m_quad.m128_i32[3]);
    v65 = v178;
    v64 = dmin.m_quad.m128_u64[0];
    v21 = v186;
    v15 = *(_QWORD *)&v190[0].m_enum;
    v62 = v174 + 1;
    v129 = *(_DWORD *)(v178 + dmin.m_quad.m128_u64[0] + 40) - 1;
    dmax.m_quad.m128_u64[0] = 0i64;
    dmax.m_quad.m128_i32[3] = 2147483648;
    ++v169[0].m_enum;
    ++v174;
    if ( v169[0].m_enum >= v129 )
    {
      v61 = dmax.m_quad.m128_i32[0];
      goto LABEL_169;
    }
  }
  v96 = 2 * v94;
  if ( v95 < v96 )
    v95 = v96;
  hkArrayUtil::_reserve(&v169[1], (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, v95, 16);
  if ( v169[1].m_enum == HK_SUCCESS )
  {
    v82 = dmax.m_quad.m128_i32[2];
    goto LABEL_124;
  }
  v19 = v185;
  v130 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v185->m_enum = 1;
  v131 = (32 * v85 + 127) & 0xFFFFFF80;
  v132 = (hkLifoAllocator *)TlsGetValue(v130);
  v133 = (v131 + 15) & 0xFFFFFFF0;
  if ( v131 > v132->m_slabSize || &v88[v133] != v132->m_cur || v132->m_firstNonLifoEnd == v88 )
    hkLifoAllocator::slowBlockFree(v132, v88, v133);
  else
    v132->m_cur = v88;
  if ( v92 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v88,
      32 * v92);
  LODWORD(v172) = 0;
  if ( v172 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)dmin.m_quad.m128_u64[1],
      8 * HIDWORD(v172));
  dmin.m_quad.m128_u64[1] = 0i64;
  HIDWORD(v172) = 2147483648;
  dmax.m_quad.m128_i32[2] = 0;
  if ( dmax.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)dmax.m_quad.m128_u64[0],
      16 * dmax.m_quad.m128_i32[3]);
  dmax.m_quad.m128_u64[0] = 0i64;
  dmax.m_quad.m128_i32[3] = 2147483648;
  v184.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::`vftable';
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    &v184,
    1);
  v184.m_stack.m_size = 0;
  if ( v184.m_stack.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v184.m_stack.m_data,
      16 * v184.m_stack.m_capacityAndFlags);
  v184.m_stack.m_data = 0i64;
LABEL_180:
  v184.m_stack.m_capacityAndFlags = 2147483648;
  v184.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable';
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&v184.m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>(&v184.m_mesh.m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v184.m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&v184.m_mesh.m_vertices);
  return v19;
}es);
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryPr

// File Line: 1107
// RVA: 0xB65480
void __fastcall anonymous_namespace_::projectPoints(hkVector4f *projDir, hkArrayBase<hkVector4f> *verticesIn, hkArray<hkVector2f,hkContainerHeapAllocator> *verticesOut)
{
  hkArray<hkVector2f,hkContainerHeapAllocator> *v3; // rdi
  hkArrayBase<hkVector4f> *v4; // rsi
  hkVector4f *v5; // rbx
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  float v8; // xmm1_4
  __m128 v9; // xmm6
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
  hkQuaternionf v31; // [rsp+20h] [rbp-88h]

  v3 = verticesOut;
  v4 = verticesIn;
  v5 = projDir;
  v6 = _mm_mul_ps(projDir->m_quad, stru_141A71280.m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_99998999),
                                     (__m128)LODWORD(FLOAT_0_99998999),
                                     0);
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
              _mm_cmpleps(v10, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                _mm_mul_ps(*(__m128 *)_xmm, v11)));
      v15 = _mm_mul_ps(v14, (__m128)xmmword_141A711B0);
      if ( v7.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0)) )
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
                    _mm_cmpleps(v17, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)),
                      _mm_mul_ps(*(__m128 *)_xmm, v20))),
                  v17),
                _mm_andnot_ps(
                  _mm_cmpleps(v18, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))));
      }
      v21 = _mm_mul_ps(v13, v15);
      v9 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, _mm_mul_ps(v14, v10)), 196);
      v31.m_vec.m_quad = v9;
    }
    else
    {
      hkQuaternionf::setFlippedRotation(&v31, projDir);
      v9 = v31.m_vec.m_quad;
    }
  }
  else
  {
    v9 = qi.m_vec.m_quad;
    v31.m_vec.m_quad = qi.m_vec.m_quad;
  }
  v22 = 0;
  if ( v3->m_size > 0 )
  {
    v23 = 0i64;
    while ( 1 )
    {
      v24 = v22++;
      ++v23;
      v25 = _mm_shuffle_ps(v9, v9, 255);
      v26 = _mm_mul_ps(v4->m_data[v23 - 1].m_quad, v5->m_quad);
      v27 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                    _mm_shuffle_ps(v26, v26, 170))),
                v5->m_quad),
              v4->m_data[v23 - 1].m_quad);
      v28 = _mm_mul_ps(v9, v27);
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v27));
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                    _mm_shuffle_ps(v28, v28, 170)),
                  v9),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v27)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v25));
      v3->m_data[v24] = (hkVector2f)_mm_add_ps(v30, v30);
      if ( v22 >= v3->m_size )
        break;
      v9 = v31.m_vec.m_quad;
    }
  }
}

// File Line: 1261
// RVA: 0xB65770
__int64 __fastcall mergeAllowedByHeightPartition(hkLocalArray<hkVector4f> *points, hkSimdFloat32 *heightPartitionThreshold)
{
  hkLocalArray<hkVector4f> *v2; // rdi
  hkSimdFloat32 *v3; // rbp
  unsigned int v4; // esi
  int i; // ebx
  __int64 v6; // rdx
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 *v15; // rcx
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  hkVector4f planeOut; // [rsp+20h] [rbp-88h]
  hkaiNavMeshSimplificationUtils::PlaneFitter v21; // [rsp+30h] [rbp-78h]
  hkResult result; // [rsp+B0h] [rbp+8h]

  v2 = points;
  v3 = heightPartitionThreshold;
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&v21);
  v4 = 0;
  for ( i = 0; i < v2->m_size; ++i )
    hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v21, &v2->m_data[i]);
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v21, &result, &planeOut);
  v6 = v2->m_size;
  v7 = _mm_mul_ps(planeOut.m_quad, planeOut.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_cmpleps(v8, (__m128)0i64);
  v11 = _mm_mul_ps(v9, v8);
  v12 = (__m128)xmmword_141A712A0;
  v13 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v14 = _mm_mul_ps(
          planeOut.m_quad,
          _mm_andnot_ps(v10, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))));
  planeOut.m_quad = v14;
  if ( v6 > 0 )
  {
    v15 = &v2->m_data->m_quad;
    do
    {
      v16 = *v15;
      ++v15;
      v17 = _mm_mul_ps(v16, v14);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v13 = _mm_max_ps(v18, v13);
      v12 = _mm_min_ps(v18, v12);
      --v6;
    }
    while ( v6 );
  }
  if ( (float)(v13.m128_f32[0] - v12.m128_f32[0]) <= v3->m_real.m128_f32[0] )
    v4 = 1;
  return v4;
}

// File Line: 1287
// RVA: 0xB658D0
__int64 __fastcall hertelMehlhorn_canMerge(int edgeIdx, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *mesh, const float *heightErrorOverride, hkPointerMap<int,int,hkContainerHeapAllocator> *settingsIndexMap, hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut, hkResult *memoryRes)
{
  int v7; // er13
  hkaiNavMesh::Edge *v8; // rdi
  signed __int64 v9; // r15
  hkSimdFloat32 *v10; // rbx
  unsigned int v11; // eax
  hkaiNavMesh::Face *v13; // rdx
  __int64 v14; // r8
  int v15; // er9
  __int64 v16; // r12
  __int64 v17; // r11
  signed __int64 v18; // r10
  int v19; // eax
  signed int v20; // er8
  signed __int64 v21; // r14
  int v22; // eax
  signed __int64 v23; // rdx
  int *v24; // rcx
  int v25; // esi
  hkVector4f *v26; // ST20_8
  int v27; // edx
  hkLifoAllocator *v28; // rax
  hkVector4f *v29; // r8
  int v30; // edx
  char *v31; // rcx
  hkVector4f *v32; // rax
  __int64 v33; // r9
  signed __int64 v34; // r8
  __int64 v35; // r9
  signed __int64 v36; // r8
  int v37; // eax
  hkaiNavMeshSimplificationUtils::Settings *v38; // rax
  hkaiNavMeshSimplificationUtils::Settings *v39; // rsi
  __m128 v40; // xmm1
  const float *v41; // rax
  unsigned int v42; // ecx
  unsigned __int64 v43; // r10
  int v44; // eax
  signed __int64 v45; // r14
  int v46; // eax
  signed __int64 v47; // r11
  int v48; // er13
  int v49; // ecx
  __int64 v50; // r8
  __m128i v51; // xmm5
  __int64 v52; // rdx
  unsigned __int64 v53; // rcx
  __m128 v54; // xmm8
  __m128i v55; // xmm7
  __m128 v56; // xmm2
  __m128i v57; // xmm5
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  signed __int64 v62; // rax
  signed __int64 v63; // rax
  __int128 v64; // xmm0
  __int64 v65; // rax
  __int128 v66; // xmm0
  char v67; // dl
  char v68; // r8
  float v69; // xmm9_4
  float v70; // xmm5_4
  float v71; // xmm11_4
  float v72; // xmm12_4
  float v73; // xmm13_4
  float v74; // xmm14_4
  float v75; // xmm3_4
  bool v76; // cf
  bool v77; // zf
  float v78; // xmm13_4
  bool v79; // cl
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm8_4
  float v84; // xmm3_4
  bool v85; // al
  unsigned int v86; // edi
  bool v87; // bl
  char *v88; // rsi
  signed int v89; // ebx
  hkLifoAllocator *v90; // rax
  int v91; // er8
  hkVector4f *normalOut; // [rsp+20h] [rbp-E0h]
  int normalOuta; // [rsp+20h] [rbp-E0h]
  hkVector4f *normalOutb; // [rsp+20h] [rbp-E0h]
  hkArrayBase<hkVector4f> points; // [rsp+28h] [rbp-D8h]
  void *p; // [rsp+38h] [rbp-C8h]
  int v97; // [rsp+40h] [rbp-C0h]
  hkSimdFloat32 heightPartitionThreshold; // [rsp+50h] [rbp-B0h]
  hkVector2f v99; // [rsp+60h] [rbp-A0h]
  hkVector2f v100; // [rsp+68h] [rbp-98h]
  hkVector2f v101; // [rsp+70h] [rbp-90h]
  hkaiNavMesh *mesha; // [rsp+80h] [rbp-80h]
  int v103; // [rsp+94h] [rbp-6Ch]
  int v104; // [rsp+98h] [rbp-68h]
  int v105; // [rsp+9Ch] [rbp-64h]
  int v106[4]; // [rsp+A0h] [rbp-60h]
  int v107; // [rsp+B0h] [rbp-50h]
  const float *v108; // [rsp+C0h] [rbp-40h]
  int faceIndex[4]; // [rsp+D0h] [rbp-30h]
  hkArray<hkVector2f,hkContainerHeapAllocator> verticesOut; // [rsp+E0h] [rbp-20h]
  char v111; // [rsp+F0h] [rbp-10h]
  hkArrayBase<hkVector4f> verticesIn; // [rsp+120h] [rbp+20h]
  __int128 v113; // [rsp+130h] [rbp+30h]
  __int128 v114; // [rsp+140h] [rbp+40h]
  __int128 v115; // [rsp+150h] [rbp+50h]
  __int128 v116; // [rsp+160h] [rbp+60h]
  __int128 v117; // [rsp+170h] [rbp+70h]
  __int128 v118; // [rsp+180h] [rbp+80h]
  int v119; // [rsp+260h] [rbp+160h]
  hkaiNavMeshGenerationSettings *v120; // [rsp+268h] [rbp+168h]
  int v121; // [rsp+270h] [rbp+170h]
  int v122; // [rsp+270h] [rbp+170h]
  float v123; // [rsp+270h] [rbp+170h]
  hkResult *memoryResa; // [rsp+290h] [rbp+190h]

  v120 = settings;
  v7 = edgeIdx;
  memoryRes->m_enum = 0;
  v8 = mesh->m_edges.m_data;
  v9 = edgeIdx;
  v108 = heightErrorOverride;
  v10 = (hkSimdFloat32 *)mesh;
  v11 = v8[edgeIdx].m_oppositeEdge;
  if ( v11 == -1 )
    return 0i64;
  v13 = mesh->m_faces.m_data;
  v14 = mesh->m_faceDataStriding;
  LODWORD(normalOut) = v8[v11 & 0x3FFFFF].m_a;
  LODWORD(v99.x) = v8[v11 & 0x3FFFFF].m_b;
  v106[2] = v8[v11 & 0x3FFFFF].m_oppositeEdge;
  v106[3] = v8[v11 & 0x3FFFFF].m_oppositeFace;
  LODWORD(mesha) = v106[3];
  v107 = *(_DWORD *)&v8[v11 & 0x3FFFFF].m_flags.m_storage;
  v15 = v8[edgeIdx].m_oppositeFace & 0x3FFFFF;
  v16 = v13[v15].m_startEdgeIndex;
  *(unsigned __int64 *)((char *)heightPartitionThreshold.m_real.m128_u64 + 4) = *(_QWORD *)&v13[v15].m_startUserEdgeIndex;
  heightPartitionThreshold.m_real.m128_i32[3] = *(_DWORD *)&v13[v15].m_clusterIndex;
  if ( (_DWORD)v14 )
    v121 = *(_DWORD *)(v10[5].m_real.m128_u64[0] + 4 * v15 * v14);
  else
    v121 = 0;
  v17 = v106[3] & 0x3FFFFF;
  v18 = v13[v17].m_startEdgeIndex;
  v103 = v13[v17].m_startUserEdgeIndex;
  v19 = *(_DWORD *)&v13[v17].m_numEdges;
  LODWORD(v101.x) = v18;
  v104 = v19;
  v105 = *(_DWORD *)&v13[v17].m_clusterIndex;
  if ( (_DWORD)v14 )
    v119 = *(_DWORD *)(v10[5].m_real.m128_u64[0] + 4 * v17 * v14);
  else
    v119 = 0;
  v20 = 0;
  v21 = v18;
  v22 = v18 + (signed __int16)v104;
  LODWORD(v100.x) = v18 + (signed __int16)v104;
  if ( v18 < v22 )
  {
    v23 = v22 - v18;
    v24 = &v8->m_a + v18 + 4 * v18 + 3;
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
  if ( v119 != v121 )
    return 0i64;
  v25 = heightPartitionThreshold.m_real.m128_i16[4] + (signed __int16)v104;
  v122 = heightPartitionThreshold.m_real.m128_i16[4];
  if ( v25 - 2 >= v120->m_maxNumEdgesPerFace )
    return 0i64;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    (hkaiNavMeshUtils *)&mesha,
    v10,
    (hkaiNavMesh *)(unsigned int)mesha,
    (unsigned __int64)faceIndex,
    normalOut);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    (hkaiNavMeshUtils *)&mesha,
    v10,
    (hkaiNavMesh *)v8[v9].m_oppositeFace,
    (unsigned __int64)v106,
    v26);
  points.m_capacityAndFlags = 2147483648;
  points.m_data = 0i64;
  v27 = 0;
  points.m_size = 0;
  v97 = v25;
  if ( v25 )
  {
    v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (hkVector4f *)v28->m_cur;
    v30 = (16 * v25 + 127) & 0xFFFFFF80;
    v31 = (char *)v29 + v30;
    if ( v30 > v28->m_slabSize || v31 > v28->m_end )
    {
      v32 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v28, v30);
      v27 = points.m_size;
      points.m_data = v32;
    }
    else
    {
      v28->m_cur = v31;
      v27 = points.m_size;
      points.m_data = v29;
    }
  }
  else
  {
    points.m_data = 0i64;
  }
  points.m_capacityAndFlags = v25 | 0x80000000;
  p = points.m_data;
  if ( !points.m_data )
  {
    memoryRes->m_enum = 1;
LABEL_85:
    v86 = 0;
    goto LABEL_86;
  }
  v33 = (signed __int16)v104;
  if ( (signed __int16)v104 > 0i64 )
  {
    v34 = 20 * v21;
    do
    {
      v34 += 20i64;
      points.m_data[v27] = *(hkVector4f *)(v10[3].m_real.m128_u64[0]
                                         + 16i64 * *(signed int *)(v10[2].m_real.m128_u64[0] + v34 - 20));
      v27 = points.m_size++ + 1;
      --v33;
    }
    while ( v33 );
  }
  v35 = heightPartitionThreshold.m_real.m128_i16[4];
  if ( heightPartitionThreshold.m_real.m128_i16[4] > 0i64 )
  {
    v36 = 20 * v16;
    do
    {
      v36 += 20i64;
      points.m_data[v27] = *(hkVector4f *)(v10[3].m_real.m128_u64[0]
                                         + 16i64 * *(signed int *)(v10[2].m_real.m128_u64[0] + v36 - 20));
      v27 = points.m_size++ + 1;
      --v35;
    }
    while ( v35 );
  }
  v37 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&settingsIndexMap->m_map.m_elem,
          v119,
          0xFFFFFFFFFFFFFFFFui64);
  v38 = hkaiNavMeshGenerationSettings::getSimplificationSettings(v120, &points, v37);
  v39 = v38;
  v40 = _mm_mul_ps(*(__m128 *)v106, *(__m128 *)faceIndex);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)))
             + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) < COERCE_FLOAT(
                                                                _mm_shuffle_ps(
                                                                  (__m128)LODWORD(v38->m_cosPlanarityThreshold),
                                                                  (__m128)LODWORD(v38->m_cosPlanarityThreshold),
                                                                  0)) )
    goto LABEL_99;
  if ( v38->m_useHeightPartitioning.m_bool )
  {
    v41 = v108;
    if ( !v108 )
      v41 = &v39->m_maxPartitionHeightError;
    heightPartitionThreshold.m_real = _mm_shuffle_ps((__m128)*(unsigned int *)v41, (__m128)*(unsigned int *)v41, 0);
    if ( !(unsigned int)mergeAllowedByHeightPartition((hkLocalArray<hkVector4f> *)&points, &heightPartitionThreshold) )
    {
LABEL_99:
      v27 = points.m_size;
      goto LABEL_85;
    }
  }
  v42 = v8[v9].m_oppositeEdge;
  v43 = v10[2].m_real.m128_u64[0];
  v44 = v7 + 1;
  if ( v7 + 1 == LODWORD(v100.x) )
    v44 = LODWORD(v101.x);
  v45 = 5i64 * v44;
  if ( v42 == (_DWORD)v16 )
    v46 = v16 + v122 - 1;
  else
    v46 = v42 - 1;
  v47 = 5i64 * v46;
  if ( v7 == LODWORD(v101.x) )
    v48 = LODWORD(v100.x) - 1;
  else
    v48 = v7 - 1;
  v49 = v42 + 1;
  v50 = v8[v9].m_a;
  if ( v49 == v122 + (_DWORD)v16 )
    v49 = v16;
  if ( (_DWORD)v50 != LODWORD(v99.x) || v8[v9].m_b != normalOuta )
    goto LABEL_100;
  v51 = _mm_load_si128((const __m128i *)_xmm);
  v123 = v39->m_nonconvexityThreshold;
  verticesIn.m_size = 6;
  verticesIn.m_capacityAndFlags = -2147483642;
  v52 = *(signed int *)(v43 + 20i64 * v49 + 4);
  v53 = v10[3].m_real.m128_u64[0];
  verticesIn.m_data = (hkVector4f *)&v113;
  v54 = _mm_add_ps((__m128)COERCE_UNSIGNED_INT(v123 * 0.017453292), *(__m128 *)_xmm);
  v55 = _mm_add_epi32(v51, v51);
  v56 = _mm_andnot_ps(*(__m128 *)_xmm, v54);
  v57 = _mm_andnot_si128(v51, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v56, *(__m128 *)_xmm)), v51));
  v58 = _mm_cvtepi32_ps(v57);
  v59 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v57, v55), (__m128i)0i64);
  v60 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v58, *(__m128 *)DP1_0), v56), _mm_mul_ps(v58, *(__m128 *)DP2)),
          _mm_mul_ps(v58, *(__m128 *)DP3));
  v61 = _mm_mul_ps(v60, v60);
  heightPartitionThreshold.m_real = _mm_xor_ps(
                                      _mm_xor_ps(
                                        _mm_or_ps(
                                          _mm_andnot_ps(
                                            v59,
                                            _mm_add_ps(
                                              _mm_sub_ps(
                                                _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(v61, *(__m128 *)cosCoeff0_0),
                                                          *(__m128 *)cosCoeff1),
                                                        v61),
                                                      *(__m128 *)cosCoeff2_0),
                                                    v61),
                                                  v61),
                                                _mm_mul_ps(v61, *(__m128 *)_xmm)),
                                              *(__m128 *)_xmm)),
                                          _mm_and_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(v61, *(__m128 *)sinCoeff0),
                                                        *(__m128 *)sinCoeff1_0),
                                                      v61),
                                                    *(__m128 *)sinCoeff2_0),
                                                  v61),
                                                v60),
                                              v60),
                                            v59)),
                                        _mm_xor_ps(
                                          (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v55, v55), v57), 0x1Du),
                                          _mm_and_ps(v54, *(__m128 *)_xmm))),
                                      *(__m128 *)_xmm);
  v113 = *(_OWORD *)(v53 + 16 * v50);
  v62 = 2i64 * *(signed int *)(v43 + 4 * v45 + 4);
  v114 = *(_OWORD *)(v53 + 16i64 * normalOuta);
  v115 = *(_OWORD *)(v53 + 8 * v62);
  v63 = 2i64 * *(signed int *)(v43 + 20i64 * v48);
  v116 = *(_OWORD *)(v53 + 16 * v52);
  v64 = *(_OWORD *)(v53 + 8 * v63);
  v65 = *(signed int *)(v43 + 4 * v47);
  v117 = v64;
  v66 = *(_OWORD *)(v53 + 16 * v65);
  verticesOut.m_size = 6;
  v118 = v66;
  verticesOut.m_data = (hkVector2f *)&v111;
  verticesOut.m_capacityAndFlags = -2147483642;
  anonymous_namespace_::projectPoints((hkVector4f *)faceIndex, &verticesIn, &verticesOut);
  v67 = 1;
  v68 = 1;
  v101 = *verticesOut.m_data;
  normalOutb = (hkVector4f *)verticesOut.m_data[1];
  mesha = (hkaiNavMesh *)verticesOut.m_data[2];
  v99 = verticesOut.m_data[3];
  memoryResa = (hkResult *)verticesOut.m_data[4];
  v69 = v99.x - v101.x;
  v70 = v99.y - v101.y;
  v100 = verticesOut.m_data[5];
  v71 = *(float *)&memoryResa - v101.x;
  v72 = *((float *)&memoryResa + 1) - v101.y;
  v73 = (float)((float)(v101.x - *(float *)&memoryResa) * (float)(v99.y - *((float *)&memoryResa + 1)))
      - (float)((float)(v99.x - *(float *)&memoryResa) * (float)(v101.y - *((float *)&memoryResa + 1)));
  v74 = (float)((float)(*(float *)&normalOutb - v100.x) * (float)(*((float *)&mesha + 1) - v100.y))
      - (float)((float)(*(float *)&mesha - v100.x) * (float)(*((float *)&normalOutb + 1) - v100.y));
  v75 = (float)((float)(v99.y - v101.y) * (float)(*((float *)&memoryResa + 1) - v101.y))
      + (float)((float)(v99.x - v101.x) * (float)(*(float *)&memoryResa - v101.x));
  if ( v75 <= 0.0 )
  {
    v76 = v73 < 0.0;
    v78 = FLOAT_0_99900001;
    v79 = !v76;
  }
  else
  {
    v67 = 0;
    v76 = v73 < 0.0;
    v77 = v73 == 0.0;
    v78 = FLOAT_0_99900001;
    v79 = !v76
       && !v77
       && (float)(v75
                / (float)(fsqrt((float)(v70 * v70) + (float)(v69 * v69)) * fsqrt((float)(v72 * v72) + (float)(v71 * v71)))) < 0.99900001;
  }
  v80 = *(float *)&mesha - *(float *)&normalOutb;
  v81 = *((float *)&mesha + 1) - *((float *)&normalOutb + 1);
  v82 = v100.x - *(float *)&normalOutb;
  v83 = v100.y - *((float *)&normalOutb + 1);
  v84 = (float)((float)(*((float *)&mesha + 1) - *((float *)&normalOutb + 1))
              * (float)(v100.y - *((float *)&normalOutb + 1)))
      + (float)((float)(*(float *)&mesha - *(float *)&normalOutb) * (float)(v100.x - *(float *)&normalOutb));
  if ( v84 <= 0.0 )
  {
    v85 = v74 >= 0.0;
  }
  else
  {
    v68 = 0;
    v85 = v74 > 0.0
       && (float)(v84
                / (float)(fsqrt((float)(v81 * v81) + (float)(v80 * v80)) * fsqrt((float)(v83 * v83) + (float)(v82 * v82)))) < v78;
  }
  v86 = 1;
  if ( v123 != 0.0 )
  {
    if ( !v79
      && v67
      && heightPartitionThreshold.m_real.m128_f32[0] > (float)((float)((float)(v70 * v72) + (float)(v69 * v71))
                                                             / (float)(fsqrt((float)(v70 * v70) + (float)(v69 * v69))
                                                                     * fsqrt((float)(v72 * v72) + (float)(v71 * v71)))) )
    {
      v79 = 1;
    }
    if ( !v85
      && v68
      && heightPartitionThreshold.m_real.m128_f32[0] > (float)((float)((float)(v81 * v83) + (float)(v80 * v82))
                                                             / (float)(fsqrt((float)(v81 * v81) + (float)(v80 * v80))
                                                                     * fsqrt((float)(v83 * v83) + (float)(v82 * v82)))) )
    {
      v85 = 1;
    }
  }
  v87 = v79 && v85;
  verticesOut.m_size = 0;
  if ( verticesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      verticesOut.m_data,
      8 * verticesOut.m_capacityAndFlags);
  verticesOut.m_data = 0i64;
  verticesOut.m_capacityAndFlags = 2147483648;
  verticesIn.m_size = 0;
  if ( verticesIn.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      verticesIn.m_data,
      16 * verticesIn.m_capacityAndFlags);
  if ( !v87 )
  {
LABEL_100:
    v27 = points.m_size;
    goto LABEL_85;
  }
  v27 = points.m_size;
LABEL_86:
  v88 = (char *)p;
  if ( p == points.m_data )
    v27 = 0;
  points.m_size = v27;
  v89 = (16 * v97 + 127) & 0xFFFFFF80;
  v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (v89 + 15) & 0xFFFFFFF0;
  if ( v89 > v90->m_slabSize || &v88[v91] != v90->m_cur || v90->m_firstNonLifoEnd == v88 )
    hkLifoAllocator::slowBlockFree(v90, v88, v91);
  else
    v90->m_cur = v88;
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v86;
}

// File Line: 1408
// RVA: 0xB66430
hkResult *__fastcall hertelMehlhorn_doMerge(hkResult *result, int edgeIdx, hkaiNavMesh *mesh, hkArray<int,hkContainerTempAllocator> *facesToRemove, hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut)
{
  __int32 v5; // er9
  hkaiNavMesh *v6; // rbx
  hkaiNavMesh::Edge *v7; // r8
  signed __int64 v8; // r10
  hkResult *v9; // r13
  int v10; // eax
  hkaiNavMesh::Face *v11; // rdx
  int *v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rax
  int v15; // er11
  int *v16; // rcx
  __int64 v17; // rax
  int v18; // edi
  int v19; // er10
  hkaiNavMesh::Edge *v20; // rax
  signed __int64 v21; // r8
  unsigned int v22; // esi
  unsigned int v23; // er14
  int v24; // er15
  int v25; // er12
  int v26; // er8
  int v27; // eax
  int v28; // er9
  int v29; // ecx
  __int64 v30; // rdx
  char v31; // al
  __int16 v32; // ax
  int v33; // ecx
  int v34; // er9
  signed __int64 v35; // r9
  int *v36; // rdx
  int *v37; // r8
  signed __int64 v38; // rcx
  signed __int64 v39; // r8
  int v40; // eax
  hkaiNavMesh::Edge *v41; // rdx
  __int64 v42; // rax
  hkResultEnum v43; // er10
  int v44; // er11
  hkResultEnum v45; // er9
  __int32 v46; // edi
  hkaiNavMesh::Edge *v47; // rax
  unsigned int v48; // esi
  unsigned int v49; // er14
  int v50; // er15
  int v51; // er12
  signed __int64 v52; // r8
  unsigned __int64 v53; // rax
  int v54; // er8
  int v55; // eax
  int v56; // er9
  int v57; // ecx
  __int64 v58; // rdx
  char v59; // al
  __int16 v60; // ax
  int v61; // ecx
  int v62; // er9
  signed __int64 v63; // r9
  int *v64; // rax
  int *v65; // r8
  signed __int64 v66; // rdx
  signed __int64 v67; // r8
  int v68; // ecx
  hkaiNavMesh::Edge *v69; // rdx
  __int64 v70; // rax
  _DWORD *v71; // rdi
  int v72; // er9
  int v73; // eax
  int v74; // eax
  __int64 v75; // rsi
  hkaiNavMesh::Face *v76; // rax
  __int64 v77; // r14
  signed __int64 v78; // rdi
  __int64 v79; // rdx
  int v80; // er8
  signed __int64 v81; // rdx
  hkaiNavMesh::Edge *v82; // r8
  signed __int64 v83; // rax
  signed __int64 v84; // rcx
  hkArray<int,hkContainerHeapAllocator> *v85; // rbx
  int v86; // er9
  int v87; // eax
  int v88; // eax
  int *edgeData; // [rsp+30h] [rbp-71h]
  int v91; // [rsp+38h] [rbp-69h]
  int v92; // [rsp+3Ch] [rbp-65h]
  hkaiNavMesh::Edge *array; // [rsp+40h] [rbp-61h]
  int n; // [rsp+48h] [rbp-59h]
  int v95; // [rsp+4Ch] [rbp-55h]
  hkResult resulta; // [rsp+50h] [rbp-51h]
  hkResult v97; // [rsp+54h] [rbp-4Dh]
  int v98; // [rsp+58h] [rbp-49h]
  int v99; // [rsp+5Ch] [rbp-45h]
  int v100; // [rsp+60h] [rbp-41h]
  int v101; // [rsp+64h] [rbp-3Dh]
  unsigned __int64 v102; // [rsp+68h] [rbp-39h]
  int v103; // [rsp+70h] [rbp-31h]
  int v104; // [rsp+78h] [rbp-29h]
  __int64 v105; // [rsp+80h] [rbp-21h]
  int v106; // [rsp+88h] [rbp-19h]
  int v107; // [rsp+8Ch] [rbp-15h]
  unsigned int v108; // [rsp+90h] [rbp-11h]
  __int64 v109; // [rsp+98h] [rbp-9h]
  __int64 v110; // [rsp+A0h] [rbp-1h]
  int v111; // [rsp+ACh] [rbp+Bh]
  int v112; // [rsp+B0h] [rbp+Fh]
  int v113; // [rsp+B4h] [rbp+13h]
  hkResult v114; // [rsp+108h] [rbp+67h]
  hkResult v115; // [rsp+110h] [rbp+6Fh]
  void *v116; // [rsp+118h] [rbp+77h]

  v116 = facesToRemove;
  v114.m_enum = edgeIdx;
  v5 = edgeIdx;
  v6 = mesh;
  v7 = mesh->m_edges.m_data;
  v8 = edgeIdx;
  v9 = result;
  v10 = v7[edgeIdx].m_oppositeEdge & 0x3FFFFF;
  v115.m_enum = v10;
  v100 = v7[v10].m_a;
  v101 = v7[v10].m_b;
  v102 = *(_QWORD *)&v7[v10].m_oppositeEdge;
  v11 = v6->m_faces.m_data;
  v103 = *(_DWORD *)&v7[v10].m_flags.m_storage;
  v108 = v7[v8].m_oppositeFace & 0x3FFFFF;
  v12 = &v11[v108].m_startEdgeIndex;
  v98 = *v12;
  v111 = v12[1];
  v112 = v12[2];
  v113 = v12[3];
  v13 = HIDWORD(v102) & 0x3FFFFF;
  v109 = v13;
  v13 = (signed int)v13;
  v110 = v13;
  v14 = 2i64 * (signed int)v13;
  v15 = *(&v11->m_startEdgeIndex + 2 * v14);
  v16 = &v11->m_startEdgeIndex + 2 * v14;
  LODWORD(v14) = v16[1];
  v99 = v15;
  HIDWORD(v105) = v14;
  v106 = v16[2];
  LODWORD(v14) = v16[3];
  array = 0i64;
  n = 0;
  v95 = 2147483648;
  edgeData = 0i64;
  v107 = v14;
  v91 = 0;
  v92 = 2147483648;
  v17 = (signed int)v7[v8].m_oppositeEdge;
  if ( (_DWORD)v17 != -1 )
  {
    v7[v17].m_oppositeEdge = -1;
    v6->m_edges.m_data[v7[v8].m_oppositeEdge].m_oppositeFace = -1;
  }
  *(_QWORD *)&v7[v8].m_oppositeEdge = -1i64;
  v18 = v5 + 1;
  v19 = v15 + (signed __int16)v106;
  if ( v5 + 1 == v19 )
    v18 = v15;
  v104 = v15 + (signed __int16)v106;
  while ( v18 != v5 )
  {
    v20 = v6->m_edges.m_data;
    v21 = 20i64 * v18;
    v105 = v21;
    v22 = *(unsigned int *)((char *)&v20->m_oppositeEdge + v21);
    v23 = *(unsigned int *)((char *)&v20->m_oppositeFace + v21);
    v24 = *(int *)((char *)&v20->m_a + v21);
    v25 = *(int *)((char *)&v20->m_b + v21);
    LODWORD(v20) = *(_DWORD *)(&v20->m_flags.m_storage + v21);
    v102 = __PAIR__(v23, v22);
    v103 = (signed int)v20;
    if ( v23 == -1 || (v23 & 0x3FFFFF) != v108 )
    {
      v26 = n;
      v27 = v95;
      v28 = n + 1;
      v29 = v95 & 0x3FFFFFFF;
      if ( (v95 & 0x3FFFFFFF) >= n + 1 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        if ( v28 < 2 * v29 )
          v28 = 2 * v29;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v28, 20);
        if ( resulta.m_enum )
        {
LABEL_37:
          v9->m_enum = 1;
          goto LABEL_101;
        }
        v27 = v95;
        v26 = n;
      }
      if ( v26 == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 20);
        v26 = n;
      }
      n = v26 + 1;
      v30 = (__int64)&array[v26];
      *(_BYTE *)(v30 + 16) = v103;
      v31 = BYTE1(v103);
      *(_DWORD *)v30 = v24;
      *(_BYTE *)(v30 + 17) = v31;
      v32 = HIWORD(v103);
      *(_DWORD *)(v30 + 4) = v25;
      *(_DWORD *)(v30 + 8) = v22;
      *(_DWORD *)(v30 + 12) = v23;
      *(_WORD *)(v30 + 18) = v32;
      v33 = v91;
      v34 = v91 + v6->m_edgeDataStriding;
      if ( (v92 & 0x3FFFFFFF) >= v34 )
      {
        v97.m_enum = 0;
      }
      else
      {
        if ( v34 < 2 * (v92 & 0x3FFFFFFF) )
          v34 = 2 * (v92 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v97, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &edgeData, v34, 4);
        if ( v97.m_enum )
          goto LABEL_76;
        v33 = v91;
      }
      v35 = v6->m_edgeDataStriding;
      v91 = v35 + v33;
      v36 = &edgeData[v33];
      if ( (_DWORD)v35 )
        v37 = &v6->m_edgeData.m_data[v18 * (signed int)v35];
      else
        v37 = 0i64;
      if ( (_DWORD)v35 == 1 )
      {
        *v36 = *v37;
      }
      else
      {
        v38 = v35;
        if ( v35 >= 1 )
        {
          v39 = (char *)v37 - (char *)v36;
          do
          {
            v40 = *(int *)((char *)v36 + v39);
            ++v36;
            *(v36 - 1) = v40;
            --v38;
          }
          while ( v38 );
        }
      }
      v21 = v105;
      v5 = v114.m_enum;
      v15 = v99;
      v19 = v104;
    }
    v41 = v6->m_edges.m_data;
    v42 = *(signed int *)((char *)&v41->m_oppositeEdge + v21);
    if ( (_DWORD)v42 != -1 )
    {
      v41[v42].m_oppositeEdge = -1;
      v6->m_edges.m_data[*(signed int *)((char *)&v41->m_oppositeEdge + v21)].m_oppositeFace = -1;
    }
    *(_QWORD *)((char *)&v41->m_oppositeEdge + v21) = -1i64;
    if ( ++v18 == v19 )
      v18 = v15;
  }
  v43 = v115.m_enum;
  v44 = v98;
  v45 = v98 + (signed __int16)v112;
  v46 = v115.m_enum + 1;
  v114.m_enum = v98 + (signed __int16)v112;
  if ( v115.m_enum + 1 == v45 )
    v46 = v98;
  if ( v46 != v115.m_enum )
  {
    do
    {
      v47 = v6->m_edges.m_data;
      v48 = v47[v46].m_oppositeEdge;
      v49 = v47[v46].m_oppositeFace;
      v50 = v47[v46].m_a;
      v51 = v47[v46].m_b;
      v52 = 20i64 * v46;
      v103 = *(_DWORD *)&v47[v46].m_flags.m_storage;
      v102 = __PAIR__(v49, v48);
      v105 = 20i64 * v46;
      v53 = __PAIR__(v49, v48) >> 32;
      if ( v49 == -1 || (v53 & 0x3FFFFF) != (_DWORD)v109 )
      {
        v54 = n;
        v55 = v95;
        v56 = n + 1;
        v57 = v95 & 0x3FFFFFFF;
        if ( (v95 & 0x3FFFFFFF) >= n + 1 )
        {
          v97.m_enum = 0;
        }
        else
        {
          if ( v56 < 2 * v57 )
            v56 = 2 * v57;
          hkArrayUtil::_reserve(&v97, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v56, 20);
          if ( v97.m_enum )
            goto LABEL_37;
          v55 = v95;
          v54 = n;
        }
        if ( v54 == (v55 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 20);
          v54 = n;
        }
        n = v54 + 1;
        v58 = (__int64)&array[v54];
        *(_BYTE *)(v58 + 16) = v103;
        v59 = BYTE1(v103);
        *(_DWORD *)v58 = v50;
        *(_BYTE *)(v58 + 17) = v59;
        v60 = HIWORD(v103);
        *(_DWORD *)(v58 + 4) = v51;
        *(_DWORD *)(v58 + 8) = v48;
        *(_DWORD *)(v58 + 12) = v49;
        *(_WORD *)(v58 + 18) = v60;
        v61 = v91;
        v62 = v91 + v6->m_edgeDataStriding;
        if ( (v92 & 0x3FFFFFFF) >= v62 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v62 < 2 * (v92 & 0x3FFFFFFF) )
            v62 = 2 * (v92 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(
            &resulta,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &edgeData,
            v62,
            4);
          if ( resulta.m_enum )
            goto LABEL_76;
          v61 = v91;
        }
        v63 = v6->m_edgeDataStriding;
        v91 = v63 + v61;
        v64 = &edgeData[v61];
        if ( (_DWORD)v63 )
          v65 = &v6->m_edgeData.m_data[v46 * (signed int)v63];
        else
          v65 = 0i64;
        if ( (_DWORD)v63 == 1 )
        {
          *v64 = *v65;
        }
        else
        {
          v66 = v63;
          if ( v63 >= 1 )
          {
            v67 = (char *)v65 - (char *)v64;
            do
            {
              v68 = *(int *)((char *)v64 + v67);
              ++v64;
              *(v64 - 1) = v68;
              --v66;
            }
            while ( v66 );
          }
        }
        v52 = v105;
        v45 = v114.m_enum;
        v43 = v115.m_enum;
        v44 = v98;
      }
      v69 = v6->m_edges.m_data;
      v70 = *(signed int *)((char *)&v69->m_oppositeEdge + v52);
      if ( (_DWORD)v70 != -1 )
      {
        v69[v70].m_oppositeEdge = -1;
        v6->m_edges.m_data[*(signed int *)((char *)&v69->m_oppositeEdge + v52)].m_oppositeFace = -1;
      }
      *(_QWORD *)((char *)&v69->m_oppositeEdge + v52) = -1i64;
      if ( ++v46 == v45 )
        v46 = v44;
    }
    while ( v46 != v43 );
  }
  v71 = v116;
  v72 = *((_DWORD *)v116 + 2) + 2;
  v73 = *((_DWORD *)v116 + 3) & 0x3FFFFFFF;
  if ( v73 < v72 )
  {
    v74 = 2 * v73;
    if ( v72 < v74 )
      v72 = v74;
    hkArrayUtil::_reserve(&v114, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v116, v72, 4);
    if ( v114.m_enum )
    {
LABEL_76:
      v9->m_enum = 1;
      goto LABEL_101;
    }
  }
  *(_DWORD *)(*(_QWORD *)v71 + 4i64 * (signed int)v71[2]++) = v109;
  *(_DWORD *)(*(_QWORD *)v71 + 4i64 * (signed int)v71[2]++) = v108;
  if ( n > 2 )
  {
    v75 = v6->m_faces.m_size;
    v76 = hkaiNavMesh::expandFacesBy(v6, 1, -1);
    if ( !v76 )
    {
      v9->m_enum = 1;
      goto LABEL_101;
    }
    v77 = v110;
    v76->m_startEdgeIndex = -1;
    *(_QWORD *)&v76->m_startUserEdgeIndex = 0xFFFFFFFFi64;
    v76->m_clusterIndex = -1;
    v76->m_padding = -12851;
    v78 = v6->m_edges.m_size;
    v76->m_startEdgeIndex = v78;
    v76->m_numEdges = n;
    v79 = v6->m_faceDataStriding;
    if ( (_DWORD)v79 )
      v80 = v6->m_faceData.m_data[v77 * v79];
    else
      v80 = 0;
    if ( (_DWORD)v79 )
      v6->m_faceData.m_data[v75 * v79] = v80;
    hkaiNavMesh::appendEdges(v6, &v115, array, edgeData, n);
    if ( v115.m_enum )
    {
      v9->m_enum = 1;
      goto LABEL_101;
    }
    if ( (signed int)v78 < v6->m_edges.m_size )
    {
      v81 = v78;
      do
      {
        v82 = v6->m_edges.m_data;
        v83 = (signed int)v82[v81].m_oppositeEdge;
        if ( (_DWORD)v83 != -1 )
        {
          v84 = v83;
          v82[v84].m_oppositeFace = v75;
          v82[v84].m_oppositeEdge = v78;
        }
        LODWORD(v78) = v78 + 1;
        ++v81;
      }
      while ( (signed int)v78 < v6->m_edges.m_size );
    }
    v85 = faceToPartitionMapInOut;
    if ( faceToPartitionMapInOut )
    {
      v86 = faceToPartitionMapInOut->m_size + 1;
      v87 = faceToPartitionMapInOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v87 >= v86 )
      {
        v114.m_enum = 0;
      }
      else
      {
        v88 = 2 * v87;
        if ( v86 < v88 )
          v86 = v88;
        hkArrayUtil::_reserve(
          &v114,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          faceToPartitionMapInOut,
          v86,
          4);
        if ( v114.m_enum )
        {
          v9->m_enum = 1;
          goto LABEL_101;
        }
      }
      v85->m_data[v85->m_size++] = v85->m_data[v77];
    }
  }
  v9->m_enum = 0;
LABEL_101:
  v91 = 0;
  if ( v92 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      edgeData,
      4 * v92);
  edgeData = 0i64;
  v92 = 2147483648;
  n = 0;
  if ( v95 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      20 * (v95 & 0x3FFFFFFF));
  return v9;
}

// File Line: 1529
// RVA: 0xB629C0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::hertelMehlhorn(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *mesh, const float *heightErrorOverride, hkArray<int,hkContainerHeapAllocator> *faceToPartitionMapInOut)
{
  const float *v5; // rax
  hkaiNavMesh *v6; // rbx
  hkaiNavMeshGenerationSettings *v7; // r15
  hkResult *v8; // r12
  int v9; // esi
  __int64 v10; // rdi
  hkaiNavMeshGenerationSettings::OverrideSettings *v11; // rax
  hkArray<int,hkContainerHeapAllocator> *v12; // r13
  int v13; // er9
  signed int v14; // er10
  hkResult *v15; // rax
  int v16; // esi
  __int64 v17; // rdi
  hkaiNavMesh::Edge *v18; // rcx
  unsigned int v19; // edx
  __int64 v20; // r14
  __int64 v21; // r12
  hkVector4f *v22; // rdx
  __m128 *v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  char v28; // r12
  int v29; // edi
  __int64 v30; // rsi
  int v31; // er14
  unsigned int v32; // eax
  int v33; // er8
  int v34; // er8
  hkArray<int,hkContainerHeapAllocator> *v35; // rsi
  char v36; // r14
  int v37; // edi
  unsigned int v38; // eax
  int v39; // er8
  hkResult memoryRes; // [rsp+40h] [rbp-41h]
  hkResult v41; // [rsp+44h] [rbp-3Dh]
  hkResult v42; // [rsp+48h] [rbp-39h]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+50h] [rbp-31h]
  LongestEdge *array; // [rsp+60h] [rbp-21h]
  int v45; // [rsp+68h] [rbp-19h]
  int v46; // [rsp+6Ch] [rbp-15h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v47; // [rsp+70h] [rbp-11h]
  unsigned int v48; // [rsp+8Ch] [rbp+Bh]
  int v49; // [rsp+90h] [rbp+Fh]
  hkResult *v50; // [rsp+E0h] [rbp+5Fh]
  hkResult resulta; // [rsp+E8h] [rbp+67h]
  float *heightErrorOverridea; // [rsp+F8h] [rbp+77h]

  heightErrorOverridea = (float *)heightErrorOverride;
  v50 = result;
  v5 = heightErrorOverride;
  v6 = mesh;
  v7 = settings;
  v8 = result;
  v47.m_hashMod = -1;
  v47.m_elem = 0i64;
  v47.m_numElems = 0;
  v9 = 0;
  if ( settings->m_overrideSettings.m_size <= 0 )
  {
LABEL_7:
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 2147483648;
    if ( v7->m_simplificationSettings.m_mergeLongestEdgesFirst.m_bool )
    {
      v12 = faceToPartitionMapInOut;
      while ( 1 )
      {
        v13 = v6->m_edges.m_size;
        array = 0i64;
        v14 = 0;
        v45 = 0;
        v46 = 2147483648;
        if ( v13 <= 0 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v13 < 0 )
            v13 = 0;
          hkArrayUtil::_reserve(
            &resulta,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &array,
            v13,
            32);
          if ( resulta.m_enum )
          {
            v8 = v50;
            v33 = v46;
            v45 = 0;
            v50->m_enum = 1;
            if ( v33 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                array,
                32 * v33);
            array = 0i64;
            v46 = 2147483648;
            goto LABEL_58;
          }
          v14 = v45;
        }
        v16 = 0;
        if ( v6->m_edges.m_size > 0 )
        {
          v17 = 0i64;
          do
          {
            v18 = v6->m_edges.m_data;
            v19 = v18[v17].m_oppositeEdge;
            v20 = v18[v17].m_a;
            v21 = v18[v17].m_b;
            v48 = v18[v17].m_oppositeFace;
            v49 = *(_DWORD *)&v18[v17].m_flags.m_storage;
            if ( v19 != -1 && v16 < (signed int)(v19 & 0x3FFFFF) )
            {
              if ( v14 == (v46 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 32);
                v14 = v45;
              }
              v22 = v6->m_vertices.m_data;
              v23 = &array[v14].length.m_real;
              v45 = v14 + 1;
              v24 = _mm_sub_ps(v22[v20].m_quad, v22[v21].m_quad);
              v23[1].m128_i32[0] = v16;
              v25 = _mm_mul_ps(v24, v24);
              v26 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                      _mm_shuffle_ps(v25, v25, 170));
              v27 = _mm_rsqrt_ps(v26);
              *v23 = _mm_andnot_ps(
                       _mm_cmpleps(v26, (__m128)0i64),
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
          while ( v16 < v6->m_edges.m_size );
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
LABEL_32:
        v45 = 0;
        if ( v46 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            32 * v46);
        array = 0i64;
        v46 = 2147483648;
        if ( !v28 )
        {
          v8 = v50;
          goto LABEL_55;
        }
      }
      v30 = 0i64;
      while ( 1 )
      {
        v31 = array[v30].index;
        v32 = hertelMehlhorn_canMerge(
                array[v30].index,
                v7,
                v6,
                heightErrorOverridea,
                (hkPointerMap<int,int,hkContainerHeapAllocator> *)&v47,
                v12,
                &memoryRes);
        if ( memoryRes.m_enum )
          break;
        if ( v32 )
        {
          v28 = 1;
          hertelMehlhorn_doMerge(&v41, v31, v6, &facesToRemove, v12);
          if ( v41.m_enum )
            break;
        }
        ++v29;
        ++v30;
        if ( v29 >= v45 )
          goto LABEL_32;
      }
      v34 = v46;
      v50->m_enum = 1;
      v45 = 0;
      if ( v34 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          32 * v34);
      facesToRemove.m_size = 0;
      v46 = 2147483648;
      array = 0i64;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          facesToRemove.m_data,
          4 * facesToRemove.m_capacityAndFlags);
      facesToRemove.m_data = 0i64;
      facesToRemove.m_capacityAndFlags = 2147483648;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v47,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v47);
      v15 = v50;
    }
    else
    {
      v35 = faceToPartitionMapInOut;
      do
      {
        v36 = 0;
        v37 = 0;
        if ( v6->m_edges.m_size <= 0 )
          break;
        do
        {
          v38 = hertelMehlhorn_canMerge(
                  v37,
                  v7,
                  v6,
                  v5,
                  (hkPointerMap<int,int,hkContainerHeapAllocator> *)&v47,
                  v35,
                  &resulta);
          if ( resulta.m_enum
            || v38 && (v36 = 1, hertelMehlhorn_doMerge(&v41, v37, v6, &facesToRemove, v35), v41.m_enum) )
          {
            v39 = facesToRemove.m_capacityAndFlags;
            v8->m_enum = 1;
            facesToRemove.m_size = 0;
            if ( v39 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                facesToRemove.m_data,
                4 * v39);
            facesToRemove.m_data = 0i64;
            goto LABEL_61;
          }
          v5 = heightErrorOverridea;
          ++v37;
        }
        while ( v37 < v6->m_edges.m_size );
      }
      while ( v36 );
LABEL_55:
      hkaiNavMeshUtils::removeFaces(&v42, v6, &facesToRemove, 0);
      if ( v42.m_enum )
        v8->m_enum = 1;
      else
        v8->m_enum = 0;
LABEL_58:
      facesToRemove.m_size = 0;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          facesToRemove.m_data,
          4 * facesToRemove.m_capacityAndFlags);
      facesToRemove.m_data = 0i64;
LABEL_61:
      facesToRemove.m_capacityAndFlags = 2147483648;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v47,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v47);
      v15 = v8;
    }
  }
  else
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = v7->m_overrideSettings.m_data;
      if ( !v11[v10].m_volume.m_pntr )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          &v47,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v11[v10].m_material,
          v9,
          &resulta);
        if ( resulta.m_enum )
          break;
      }
      ++v9;
      ++v10;
      if ( v9 >= v7->m_overrideSettings.m_size )
      {
        v5 = heightErrorOverridea;
        goto LABEL_7;
      }
    }
    v8->m_enum = 1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v47,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v47);
    v15 = v8;
  }
  return v15;
}

