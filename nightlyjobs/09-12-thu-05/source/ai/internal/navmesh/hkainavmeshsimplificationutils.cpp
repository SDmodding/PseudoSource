// File Line: 65
// RVA: 0xB50490
hkSimdFloat32 *__fastcall getReciprocalInt(hkSimdFloat32 *result, int i)
{
  __m128 v2; // xmm1
  hkSimdFloat32 *v3; // rax

  v2 = 0i64;
  v2.m128_f32[0] = (float)i;
  v3 = result;
  result->m_real = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v2, v2, 0));
  return v3;
}

// File Line: 83
// RVA: 0xB49200
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this)
{
  this->m_vertexSelectionMethod.m_storage = 0;
  this->m_vertexFraction = 0.025;
  this->m_areaFraction = 0.00012500001;
  this->m_minPartitionArea = 1000.0;
  this->m_numSmoothingIterations = 20;
  this->m_iterationDamping = 0.050000001;
  *(_WORD *)&this->m_addVerticesOnBoundaryEdges.m_bool = 257;
  this->m_boundaryEdgeSplitLength = 50.0;
  this->m_partitionBordersSplitLength = 50.0;
  this->m_userVertexOnBoundaryTolerance = 0.001;
  this->m_userVertices.m_data = 0i64;
  this->m_userVertices.m_size = 0;
  this->m_userVertices.m_capacityAndFlags = 2147483648;
}

// File Line: 87
// RVA: 0xB49260
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this, hkaiNavMeshSimplificationUtils::ExtraVertexSettings *other)
{
  this->m_userVertices.m_capacityAndFlags = 2147483648;
  this->m_userVertices.m_data = 0i64;
  this->m_userVertices.m_size = 0;
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::operator=(this, other);
}

// File Line: 92
// RVA: 0xB49290
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::disable(hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this)
{
  *(_QWORD *)&this->m_vertexFraction = 0i64;
  *(_WORD *)&this->m_addVerticesOnBoundaryEdges.m_bool = 0;
}

// File Line: 124
// RVA: 0xB492B0
void __fastcall hkaiNavMeshSimplificationUtils::Settings::Settings(hkaiNavMeshSimplificationUtils::Settings *this)
{
  hkaiNavMeshSimplificationUtils::Settings *v1; // rbx

  this->m_maxBorderSimplifyArea = 1.5;
  this->m_maxConcaveBorderSimplifyArea = 0.15000001;
  this->m_minCorridorWidth = 0.40000001;
  this->m_maxCorridorWidth = 0.60000002;
  this->m_holeReplacementArea = 1.0;
  this->m_aabbReplacementAreaFraction = 1.2;
  this->m_maxLoopShrinkFraction = 0.75;
  this->m_maxBorderHeightError = 1.5;
  this->m_maxBorderDistanceError = 2.0;
  this->m_maxPartitionSize = 40000;
  this->m_useHeightPartitioning.m_bool = 0;
  this->m_maxPartitionHeightError = 100.0;
  this->m_useConservativeHeightPartitioning.m_bool = 0;
  this->m_hertelMehlhornHeightError = 0.0099999998;
  this->m_cosPlanarityThreshold = 0.99000001;
  this->m_nonconvexityThreshold = 0.1;
  this->m_boundaryEdgeFilterThreshold = 0.0099999998;
  this->m_maxSharedVertexHorizontalError = 1.0;
  this->m_maxSharedVertexVerticalError = 1.0;
  this->m_maxBoundaryVertexHorizontalError = 1.0;
  this->m_maxBoundaryVertexVerticalError = 1.0;
  this->m_mergeLongestEdgesFirst.m_bool = 1;
  v1 = this;
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(&this->m_extraVertexSettings);
  v1->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&v1->m_snapshotFilename, 0i64);
}

// File Line: 130
// RVA: 0xB49380
void __fastcall hkaiNavMeshSimplificationUtils::Settings::Settings(hkaiNavMeshSimplificationUtils::Settings *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, f);
}

// File Line: 134
// RVA: 0xB493B0
void __fastcall hkaiNavMeshSimplificationUtils::Settings::setForBorderPreservation(hkaiNavMeshSimplificationUtils::Settings *this)
{
  *(_QWORD *)&this->m_maxBorderSimplifyArea = 0i64;
  this->m_holeReplacementArea = 0.0;
  *(_QWORD *)&this->m_maxLoopShrinkFraction = 0i64;
  this->m_maxBorderDistanceError = 0.0;
  *(_QWORD *)&this->m_maxSharedVertexHorizontalError = 0i64;
  *(_QWORD *)&this->m_maxBoundaryVertexHorizontalError = 0i64;
}

// File Line: 150
// RVA: 0xB504C0
hkResult *__fastcall vertexUnionFind(hkResult *result, hkaiNavMesh *mesh, hkArray<int,hkContainerHeapAllocator> *partitionSizes, hkArray<int,hkContainerHeapAllocator> *partitions)
{
  int v4; // edi
  hkResult *v5; // r14
  hkArray<int,hkContainerHeapAllocator> *v6; // rsi
  hkArray<int,hkContainerHeapAllocator> *v7; // r13
  hkaiNavMesh *v8; // rbp
  LPVOID v9; // rax
  hkLifoAllocator *v10; // rcx
  int *v11; // rax
  int v12; // ebx
  char *v13; // rdx
  unsigned int v14; // ecx
  hkLifoAllocator *v15; // rax
  int v16; // er8
  int *v17; // rdx
  int v18; // ebx
  __int64 v19; // rdi
  hkaiNavMesh::Edge *v20; // rsi
  __int64 v21; // rax
  int v22; // edx
  int v23; // er8
  int *v24; // r15
  int v25; // edx
  int *v26; // rdi
  unsigned int v27; // ecx
  int v28; // ebx
  signed int v29; // ebx
  hkResult v31; // [rsp+20h] [rbp-58h]
  hkFixedArray<int> parents; // [rsp+28h] [rbp-50h]
  hkUnionFind v33; // [rsp+38h] [rbp-40h]
  hkResult resulta; // [rsp+88h] [rbp+10h]
  hkArray<int,hkContainerHeapAllocator> *v35; // [rsp+98h] [rbp+20h]

  v35 = partitions;
  v4 = mesh->m_vertices.m_size;
  v5 = result;
  v6 = partitions;
  v7 = partitionSizes;
  v8 = mesh;
  v9 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkLifoAllocator *)v9;
  v11 = (int *)*((_QWORD *)v9 + 3);
  v12 = (4 * v4 + 127) & 0xFFFFFF80;
  v13 = (char *)v11 + v12;
  if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    v11 = (int *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
  else
    v10->m_cur = v13;
  parents.m_data.m_storage = v11;
  parents.m_size.m_storage = v4;
  if ( v11 )
  {
    hkUnionFind::hkUnionFind(&v33, &parents, v4);
    v18 = 0;
    v33.m_isCollapsed = 0;
    if ( v8->m_edges.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        v20 = v8->m_edges.m_data;
        v21 = (signed int)v20[v19].m_oppositeEdge;
        if ( (_DWORD)v21 != -1 )
        {
          v22 = v20[v19].m_a;
          v23 = v20[v21].m_b;
          v24 = &v20[v21].m_a;
          if ( v22 != v23 )
            hkUnionFind::addEdge(&v33, v22, v23);
          v25 = v20[v19].m_b;
          if ( v25 != *v24 )
            hkUnionFind::addEdge(&v33, v25, *v24);
        }
        ++v18;
        ++v19;
      }
      while ( v18 < v8->m_edges.m_size );
      v6 = v35;
    }
    hkUnionFind::assignGroups(&v33, &resulta, v7);
    if ( resulta.m_enum )
    {
      v26 = parents.m_data.m_storage;
      v27 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v28 = 4 * parents.m_size.m_storage + 127;
      v5->m_enum = 1;
      v29 = v28 & 0xFFFFFF80;
    }
    else
    {
      hkUnionFind::sortByGroupId(&v33, &v31, v7, v6);
      v26 = parents.m_data.m_storage;
      v27 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v29 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
      if ( v31.m_enum )
        v5->m_enum = 1;
      else
        v5->m_enum = 0;
    }
    v15 = (hkLifoAllocator *)TlsGetValue(v27);
    v16 = (v29 + 15) & 0xFFFFFFF0;
    if ( v29 <= v15->m_slabSize && (char *)v26 + v16 == v15->m_cur && v15->m_firstNonLifoEnd != v26 )
    {
      v15->m_cur = v26;
      return v5;
    }
    v17 = v26;
LABEL_30:
    hkLifoAllocator::slowBlockFree(v15, v17, v16);
    return v5;
  }
  v14 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v5->m_enum = 1;
  v15 = (hkLifoAllocator *)TlsGetValue(v14);
  v16 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v15->m_slabSize || (void *)v16 != v15->m_cur || !v15->m_firstNonLifoEnd )
  {
    v17 = 0i64;
    goto LABEL_30;
  }
  v15->m_cur = 0i64;
  return v5;
}

// File Line: 186
// RVA: 0xB493D0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::mergeSharedVertices(hkResult *result, hkaiNavMesh *mesh)
{
  hkResult *v2; // r14
  hkaiNavMesh *v3; // rbx
  int v4; // er9
  int v5; // edx
  int v6; // esi
  int v7; // er9
  _DWORD *v8; // rdi
  __int64 v9; // rcx
  int *v10; // r8
  int v11; // er11
  __int64 v12; // rsi
  __int64 v13; // rdi
  __int64 v14; // r10
  __int64 v15; // rdx
  __m128 v16; // xmm2
  __int64 v17; // rcx
  __m128 v18; // xmm1
  __int64 v19; // rax
  __int64 v20; // rdx
  __m128 v21; // xmm1
  __int64 v22; // rcx
  int v23; // er8
  __int64 v24; // rdi
  hkaiNavMesh::Edge *v25; // rdx
  __int64 v26; // rcx
  _DWORD *array; // [rsp+30h] [rbp-38h]
  int v29; // [rsp+38h] [rbp-30h]
  int v30; // [rsp+3Ch] [rbp-2Ch]
  hkArray<int,hkContainerHeapAllocator> partitions; // [rsp+40h] [rbp-28h]
  hkArray<int,hkContainerHeapAllocator> partitionSizes; // [rsp+50h] [rbp-18h]
  hkResult resulta; // [rsp+A0h] [rbp+38h]
  hkResult v34; // [rsp+A8h] [rbp+40h]

  v2 = result;
  v3 = mesh;
  partitionSizes.m_data = 0i64;
  partitionSizes.m_size = 0;
  partitionSizes.m_capacityAndFlags = 2147483648;
  partitions.m_data = 0i64;
  partitions.m_size = 0;
  partitions.m_capacityAndFlags = 2147483648;
  vertexUnionFind(&resulta, mesh, &partitionSizes, &partitions);
  if ( resulta.m_enum )
  {
    v2->m_enum = 1;
    goto LABEL_32;
  }
  v4 = v3->m_vertices.m_size;
  v5 = 0;
  array = 0i64;
  v29 = 0;
  v30 = 2147483648;
  if ( v4 <= 0 )
  {
    resulta.m_enum = 0;
    goto LABEL_8;
  }
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v4, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v5 = v29;
LABEL_8:
    v6 = v3->m_vertices.m_size;
    if ( (v30 & 0x3FFFFFFF) < v6 )
    {
      v7 = v3->m_vertices.m_size;
      if ( v6 < 2 * (v30 & 0x3FFFFFFF) )
        v7 = 2 * (v30 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v34, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v7, 4);
      v5 = v29;
    }
    v8 = &array[v5];
    v9 = v6 - v5;
    if ( v6 - v5 > 0 )
    {
      while ( v9 )
      {
        *v8 = -1;
        ++v8;
        --v9;
      }
    }
    v10 = partitions.m_data;
    v29 = v6;
    v11 = 0;
    if ( partitionSizes.m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = 0i64;
        v14 = partitionSizes.m_data[v12];
        if ( (signed int)v14 > 0 )
        {
          do
          {
            v15 = v10[v13++];
            array[v15] = *v10;
          }
          while ( v13 < v14 );
        }
        if ( (signed int)v14 > 1 )
        {
          v16 = 0i64;
          v17 = 0i64;
          v18 = 0i64;
          if ( (signed int)v14 > 0 )
          {
            do
            {
              v19 = v10[v17++];
              v18 = _mm_add_ps(v18, v3->m_vertices.m_data[v19].m_quad);
            }
            while ( v17 < v14 );
          }
          v16.m128_f32[0] = (float)(signed int)v14;
          v20 = 0i64;
          v21 = _mm_mul_ps(v18, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v16, v16, 0)));
          if ( (signed int)v14 > 0 )
          {
            do
            {
              v22 = v10[v20++];
              v3->m_vertices.m_data[v22].m_quad = v21;
            }
            while ( v20 < v14 );
          }
        }
        ++v11;
        ++v12;
        v10 += v14;
      }
      while ( v11 < partitionSizes.m_size );
    }
    v23 = 0;
    if ( v3->m_edges.m_size > 0 )
    {
      v24 = 0i64;
      do
      {
        v25 = v3->m_edges.m_data;
        ++v23;
        v26 = v25[v24].m_a;
        ++v24;
        v25[v24 - 1].m_a = array[v26];
        *((_DWORD *)&v25[v24] - 4) = array[*((signed int *)&v25[v24] - 4)];
      }
      while ( v23 < v3->m_edges.m_size );
    }
    v2->m_enum = 0;
    goto LABEL_29;
  }
  v2->m_enum = 1;
LABEL_29:
  v29 = 0;
  if ( v30 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v30);
  v30 = 2147483648;
  array = 0i64;
LABEL_32:
  partitions.m_size = 0;
  if ( partitions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partitions.m_data,
      4 * partitions.m_capacityAndFlags);
  partitions.m_data = 0i64;
  partitions.m_capacityAndFlags = 2147483648;
  partitionSizes.m_size = 0;
  if ( partitionSizes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partitionSizes.m_data,
      4 * partitionSizes.m_capacityAndFlags);
  return v2;
}

// File Line: 258
// RVA: 0xB502F0
hkVector4f *__fastcall hkaiNavMeshSimplificationUtils::_classToDir(hkVector4f *result, int i)
{
  unsigned int v2; // eax
  hkVector4f *v3; // rax

  v2 = _S1_41;
  if ( !(_S1_41 & 1) )
  {
    v2 = _S1_41 | 1;
    _S1_41 |= 1u;
    _mm_store_si128((__m128i *)directions, (__m128i)transform.m_quad);
    _mm_store_si128((__m128i *)&xmmword_1424A1390, (__m128i)direction.m_quad);
    _mm_store_si128((__m128i *)&xmmword_1424A13A0, (__m128i)stru_141A71280.m_quad);
  }
  if ( !(v2 & 2) )
  {
    _S1_41 = v2 | 2;
    _mm_store_si128((__m128i *)signMuls, (__m128i)g_vectorfConstants[0]);
    _mm_store_si128((__m128i *)&xmmword_1424A13D0, (__m128i)query.m_quad);
  }
  v3 = result;
  result->m_quad = _mm_mul_ps(signMuls[i & 1].m_quad, directions[i / 2].m_quad);
  return v3;
}

// File Line: 334
// RVA: 0xB496A0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::tracePartitionBoundaries(hkResult *result, hkaiNavMesh *mesh, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitions, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsOut, hkArray<int,hkContainerHeapAllocator> *edgesToRemove)
{
  hkArray<int,hkContainerHeapAllocator> *v6; // rsi
  int v7; // er9
  hkArray<int,hkContainerHeapAllocator> *v8; // r14
  hkaiNavMesh *v9; // r13
  hkResult *v10; // r12
  int v11; // edi
  int v12; // er8
  int v14; // ebx
  int v15; // er9
  __int64 v16; // rcx
  char *v17; // rdi
  int v18; // er8
  __int64 v19; // r9
  hkaiNavMesh::Face *v20; // rdi
  __int64 v21; // rcx
  signed __int64 v22; // rdx
  int v23; // er9
  int v24; // edx
  int v25; // ebx
  int v26; // er9
  char *v27; // rdi
  __int64 v28; // rcx
  int *v29; // r11
  __int64 v30; // r8
  __int64 v31; // rbx
  __int64 v32; // r9
  __int64 v33; // r10
  hkaiNavMesh::Face *v34; // rdx
  __int64 v35; // rax
  signed __int64 v36; // rdi
  int v37; // ebx
  int v38; // edi
  __int32 v39; // eax
  float *v40; // r9
  signed int v41; // er8
  int v42; // er9
  __int64 v43; // r8
  float *v44; // rdx
  __int64 v45; // rcx
  float *v46; // rdi
  hkpRigidBody **v47; // r10
  int v48; // ebx
  hkArray<int,hkContainerHeapAllocator> *v49; // r12
  int v50; // er8
  int v51; // er9
  int v52; // er10
  hkpRigidBody **v53; // r11
  __int64 v54; // rsi
  __int64 v55; // r14
  _DWORD *v56; // r15
  __int64 v57; // rcx
  signed int v58; // eax
  __int64 v59; // rdi
  int v60; // edx
  __int64 v61; // rcx
  int *v62; // rax
  int v63; // edx
  __int64 v64; // rax
  hkResult *v65; // rsi
  int v66; // ecx
  __int64 v67; // r9
  int v68; // er8
  __int64 v69; // rax
  int v70; // ecx
  __int64 v71; // r14
  hkaiNavMesh::Edge *v72; // r13
  int v73; // ecx
  __int64 v74; // rbx
  int v75; // esi
  __int64 v76; // r12
  hkaiNavMesh::Edge *v77; // r9
  __int64 v78; // rax
  hkaiNavMesh::Face *v79; // r8
  int v80; // edi
  int v81; // edx
  __int64 v82; // r10
  signed int v83; // er11
  int v84; // edi
  int v85; // er8
  int v86; // edi
  int v87; // er8
  int v88; // edx
  __int64 v89; // r10
  int v90; // er8
  signed __int64 v91; // rcx
  int v92; // er11
  __int64 v93; // r13
  int v94; // er12
  __int64 v95; // r14
  signed int v96; // er10
  hkResultEnum v97; // esi
  signed int v98; // eax
  hkResultEnum v99; // ecx
  signed int v100; // ebx
  hkaiNavMesh *v101; // r15
  int v102; // edx
  __int64 v103; // rdi
  signed __int64 v104; // rcx
  int v105; // er10
  signed __int64 v106; // rax
  hkaiNavMesh::Edge *v107; // rdx
  __int64 v108; // rcx
  hkaiNavMesh::Face *v109; // rsi
  int v110; // er9
  int v111; // eax
  int v112; // eax
  bool v113; // sf
  int v114; // eax
  __int64 v115; // rbx
  int *v116; // rdi
  int v117; // er8
  int v118; // er8
  hkaiNavMesh::Face *v119; // r11
  signed int *v120; // r8
  int v121; // edi
  hkaiNavMesh::Edge *v122; // rcx
  int v123; // er8
  int v124; // edi
  int v125; // er8
  __int64 v126; // rdx
  int v127; // edi
  int v128; // er8
  int v129; // eax
  __int64 v130; // rbx
  int *v131; // rdi
  int v132; // er8
  int v133; // er8
  int v134; // edi
  int v135; // er8
  int v136; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v137; // rdi
  int v138; // er8
  __int64 v139; // rdx
  __int64 v140; // rdi
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v141; // rsi
  __int64 v142; // r14
  int v143; // eax
  int v144; // eax
  int v145; // edi
  hkaiNavMeshSimplificationUtils::Segment *v146; // rbx
  __int64 v147; // rcx
  __int64 v148; // rdx
  signed __int64 v149; // rcx
  int v150; // er8
  int v151; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v152; // rdi
  int v153; // ebx
  __int64 v154; // rdi
  __int64 v155; // r14
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v156; // rdx
  int v157; // er8
  int v158; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v159; // rdi
  hkResult resulta; // [rsp+30h] [rbp-A9h]
  char *v161; // [rsp+38h] [rbp-A1h]
  int v162; // [rsp+40h] [rbp-99h]
  int v163; // [rsp+44h] [rbp-95h]
  hkResult v164[2]; // [rsp+48h] [rbp-91h]
  unsigned int v165; // [rsp+50h] [rbp-89h]
  int v166; // [rsp+54h] [rbp-85h]
  int v167; // [rsp+58h] [rbp-81h]
  char *array; // [rsp+60h] [rbp-79h]
  int v169; // [rsp+68h] [rbp-71h]
  int v170; // [rsp+6Ch] [rbp-6Dh]
  int v171; // [rsp+70h] [rbp-69h]
  int v172; // [rsp+74h] [rbp-65h]
  SegmentInfo *pArr; // [rsp+78h] [rbp-61h]
  int v174; // [rsp+80h] [rbp-59h]
  int v175; // [rsp+84h] [rbp-55h]
  hkaMatrix<float> v176; // [rsp+88h] [rbp-51h]
  hkQueue<hkpRigidBody *> v177; // [rsp+A0h] [rbp-39h]
  int v178; // [rsp+B8h] [rbp-21h]
  hkResult v179; // [rsp+BCh] [rbp-1Dh]
  int v180; // [rsp+C0h] [rbp-19h]
  hkResult v181; // [rsp+C4h] [rbp-15h]
  int v182; // [rsp+C8h] [rbp-11h]
  hkaiNavMesh::Face *v183; // [rsp+D0h] [rbp-9h]
  unsigned int v184; // [rsp+D8h] [rbp-1h]
  __int64 v185; // [rsp+E0h] [rbp+7h]
  hkResult v186; // [rsp+E8h] [rbp+Fh]
  int v187; // [rsp+ECh] [rbp+13h]
  hkResult *v188; // [rsp+130h] [rbp+57h]
  hkaiNavMesh *v189; // [rsp+138h] [rbp+5Fh]

  v189 = mesh;
  v188 = result;
  v6 = partitions;
  v7 = mesh->m_edges.m_size;
  v8 = numFacesInPartition;
  v9 = mesh;
  v10 = result;
  array = 0i64;
  v11 = 0;
  v169 = 0;
  v170 = 2147483648;
  if ( v7 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 4);
    if ( resulta.m_enum )
    {
      v12 = v170;
      v10->m_enum = 1;
      v169 = 0;
      if ( v12 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v12);
      return v10;
    }
    v11 = v169;
  }
  v14 = v9->m_edges.m_size;
  if ( (v170 & 0x3FFFFFFF) < v14 )
  {
    v15 = v9->m_edges.m_size;
    if ( v14 < 2 * (v170 & 0x3FFFFFFF) )
      v15 = 2 * (v170 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v179, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
    v11 = v169;
  }
  v16 = v14 - v11;
  if ( v14 - v11 > 0 )
  {
    v17 = &array[4 * v11];
    while ( v16 )
    {
      *(_DWORD *)v17 = -1;
      v17 += 4;
      --v16;
    }
  }
  v169 = v14;
  v18 = 0;
  if ( v9->m_faces.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = &v9->m_faces.m_data[v19];
      v21 = v20->m_startEdgeIndex;
      if ( (signed int)v21 < (signed int)v21 + v20->m_numEdges )
      {
        v22 = 4 * v21;
        do
        {
          LODWORD(v21) = v21 + 1;
          v22 += 4i64;
          *(_DWORD *)&array[v22 - 4] = v18;
        }
        while ( (signed int)v21 < v20->m_startEdgeIndex + v20->m_numEdges );
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v9->m_faces.m_size );
  }
  v23 = v9->m_edges.m_size;
  v24 = 0;
  v161 = 0i64;
  v162 = 0;
  v163 = 2147483648;
  if ( v23 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v161, v23, 4);
    if ( resulta.m_enum )
    {
      v10->m_enum = 1;
LABEL_267:
      v162 = 0;
      if ( v163 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v161,
          4 * v163);
      v169 = 0;
      v163 = 2147483648;
      v161 = 0i64;
      if ( v170 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v170);
      return v10;
    }
    v24 = v162;
  }
  v25 = v9->m_edges.m_size;
  if ( (v163 & 0x3FFFFFFF) < v25 )
  {
    v26 = v9->m_edges.m_size;
    if ( v25 < 2 * (v163 & 0x3FFFFFFF) )
      v26 = 2 * (v163 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v179, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v161, v26, 4);
    v24 = v162;
  }
  v27 = &v161[4 * v24];
  v28 = v25 - v24;
  if ( v25 - v24 > 0 )
  {
    while ( v28 )
    {
      *(_DWORD *)v27 = -2;
      v27 += 4;
      --v28;
    }
  }
  v29 = v6->m_data;
  v162 = v25;
  v30 = 0i64;
  if ( v8->m_size > 0 )
  {
    v31 = 0i64;
    do
    {
      v32 = 0i64;
      v33 = v8->m_data[v31];
      if ( v33 > 0 )
      {
        do
        {
          v34 = &v9->m_faces.m_data[v29[v32]];
          v35 = v34->m_startEdgeIndex;
          if ( (signed int)v35 < (signed int)v35 + v34->m_numEdges )
          {
            v36 = 4 * v35;
            do
            {
              LODWORD(v35) = v35 + 1;
              v36 += 4i64;
              *(_DWORD *)&v161[v36 - 4] = v30;
            }
            while ( (signed int)v35 < v34->m_startEdgeIndex + v34->m_numEdges );
          }
          ++v32;
        }
        while ( v32 < v33 );
      }
      v30 = (unsigned int)(v30 + 1);
      ++v31;
      v29 += v33;
    }
    while ( (signed int)v30 < v8->m_size );
  }
  v37 = v9->m_edges.m_size;
  v176.m_data.m_data = 0i64;
  v176.m_data.m_size = 0;
  v176.m_data.m_capacityAndFlags = 2147483648;
  v38 = (v37 + 31) >> 5;
  v39 = v38;
  if ( v38 )
  {
    resulta.m_enum = 4 * v38;
    v40 = (float *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                     &hkContainerHeapAllocator::s_alloc,
                     &resulta,
                     v30);
    v39 = resulta.m_enum / 4;
  }
  else
  {
    v40 = 0i64;
  }
  v41 = 2147483648;
  v176.m_data.m_data = v40;
  if ( v39 )
    v41 = v39;
  v176.m_data.m_size = (v37 + 31) >> 5;
  v176.m_m = v37;
  v176.m_data.m_capacityAndFlags = v41;
  if ( (v41 & 0x3FFFFFFF) < v38 )
  {
    v42 = (v37 + 31) >> 5;
    if ( v38 < 2 * (v41 & 0x3FFFFFFF) )
      v42 = 2 * (v41 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v179, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v176, v42, 4);
    v41 = v176.m_data.m_capacityAndFlags;
    v40 = v176.m_data.m_data;
  }
  v176.m_data.m_size = (v37 + 31) >> 5;
  if ( !v40 )
  {
    v10->m_enum = 1;
    v176.m_data.m_size = 0;
    if ( v41 < 0 )
    {
LABEL_55:
      v176.m_data.m_data = 0i64;
      v176.m_data.m_capacityAndFlags = 2147483648;
      goto LABEL_267;
    }
    v43 = (unsigned int)(4 * v41);
    v44 = 0i64;
LABEL_54:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v44, v43);
    goto LABEL_55;
  }
  if ( v38 - 1 >= 0 )
  {
    v45 = (unsigned int)v38;
    v46 = v40;
    while ( v45 )
    {
      *v46 = 0.0;
      ++v46;
      --v45;
    }
  }
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v177);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v177, 8);
  v47 = v177.m_data;
  if ( !v177.m_data )
  {
    v10->m_enum = 1;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v177);
    v176.m_data.m_size = 0;
    if ( v176.m_data.m_capacityAndFlags < 0 )
      goto LABEL_55;
    v44 = v176.m_data.m_data;
    v43 = (unsigned int)(4 * v176.m_data.m_capacityAndFlags);
    goto LABEL_54;
  }
  v48 = 0;
  if ( v9->m_edges.m_size <= 0 )
  {
    v56 = v161;
  }
  else
  {
    v49 = edgesToRemove;
    v50 = v177.m_tail;
    v51 = v177.m_elementsInUse;
    v52 = v177.m_capacity;
    v53 = v177.m_data;
    v54 = 0i64;
    v55 = 0i64;
    v56 = v161;
    do
    {
      v57 = (signed int)v9->m_edges.m_data[v54].m_oppositeEdge;
      if ( (_DWORD)v57 == -1 )
        v58 = -1;
      else
        v58 = v56[v57];
      if ( v56[v55] != v58 )
      {
        v59 = v49->m_size;
        v60 = 0;
        v61 = 0i64;
        if ( v59 <= 0 )
          goto LABEL_75;
        v62 = v49->m_data;
        while ( *v62 != v48 )
        {
          ++v61;
          ++v60;
          ++v62;
          if ( v61 >= v59 )
            goto LABEL_75;
        }
        if ( v60 == -1 )
        {
LABEL_75:
          LODWORD(v176.m_data.m_data[(signed __int64)v48 >> 5]) |= 1 << (v48 & 0x1F);
          if ( v51 >= v52 )
          {
            hkQueue<int>::setCapacity((hkQueue<int> *)&v177, 2 * v52);
            v53 = v177.m_data;
            if ( !v177.m_data )
            {
              v65 = v188;
              v188->m_enum = 1;
              hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v177);
              v176.m_data.m_size = 0;
              if ( v176.m_data.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v176.m_data.m_data,
                  4 * v176.m_data.m_capacityAndFlags);
              v176.m_data.m_data = 0i64;
              v176.m_data.m_capacityAndFlags = 2147483648;
              v162 = 0;
              if ( v163 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v161,
                  4 * v163);
              v161 = 0i64;
              v169 = 0;
              goto LABEL_211;
            }
            v51 = v177.m_elementsInUse;
            if ( v177.m_elementsInUse >= v177.m_capacity )
            {
              v63 = 8;
              if ( v177.m_capacity )
                v63 = 2 * v177.m_capacity;
              hkQueue<int>::setCapacity((hkQueue<int> *)&v177, v63);
              v53 = v177.m_data;
              v51 = v177.m_elementsInUse;
            }
            v50 = v177.m_tail;
            v52 = v177.m_capacity;
          }
          if ( v50 == v52 )
            v50 = 0;
          v64 = v50++;
          ++v51;
          *((_DWORD *)v53 + v64) = v48;
          v56 = v161;
          v177.m_elementsInUse = v51;
          v177.m_tail = v50;
        }
      }
      ++v48;
      ++v55;
      ++v54;
    }
    while ( v48 < v9->m_edges.m_size );
    v47 = v177.m_data;
  }
  v66 = v177.m_head;
  v166 = 2147483648;
  *(_QWORD *)&v164[0].m_enum = 0i64;
  v67 = 0i64;
  v184 = 0;
  v165 = 0;
LABEL_94:
  v68 = v177.m_elementsInUse;
  if ( !v177.m_elementsInUse )
    goto LABEL_214;
  while ( 1 )
  {
    v69 = v66;
    v70 = v66 + 1;
    v71 = *((signed int *)v47 + v69);
    if ( v70 == v177.m_capacity )
      v70 = 0;
    --v68;
    v182 = v70;
    v177.m_head = v70;
    v180 = v71;
    v177.m_elementsInUse = v68;
    if ( (LODWORD(v176.m_data.m_data[v71 >> 5]) >> (v71 & 0x1F)) & 1 )
      break;
    if ( !v68 )
      goto LABEL_214;
    v66 = v182;
  }
  v178 = v71;
  if ( (_DWORD)v71 == -1 )
  {
LABEL_214:
    v175 = 2147483648;
    v134 = v67;
    pArr = 0i64;
    v174 = 0;
    if ( (signed int)v67 <= 0 )
    {
      LODWORD(v189) = 0;
    }
    else
    {
      if ( (signed int)v67 < 0 )
        LODWORD(v67) = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&v189,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &pArr,
        v67,
        16);
      if ( (_DWORD)v189 )
      {
        v10 = v188;
        v135 = v175;
        v174 = 0;
        v188->m_enum = 1;
        if ( v135 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            pArr,
            16 * v135);
        pArr = 0i64;
        v175 = 2147483648;
        v136 = v165 - 1;
        if ( (signed int)(v165 - 1) >= 0 )
        {
          v137 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v164[0].m_enum + 48i64 * v136);
          do
          {
            hkaiNavMeshSimplificationUtils::Segment::~Segment(v137);
            --v137;
            --v136;
          }
          while ( v136 >= 0 );
        }
        goto LABEL_264;
      }
      v67 = v165;
    }
    v174 = v134;
    v138 = 0;
    if ( v134 > 0 )
    {
      v139 = 0i64;
      v140 = 0i64;
      do
      {
        v140 += 48i64;
        ++v139;
        pArr[v139 - 1].m_segmentIndex = v138++;
        *((_DWORD *)&pArr[v139] - 3) = *(_DWORD *)(*(_QWORD *)&v164[0].m_enum + v140 - 44);
        *((_DWORD *)&pArr[v139] - 2) = *(_DWORD *)(*(_QWORD *)&v164[0].m_enum + v140 - 40);
        *((_DWORD *)&pArr[v139] - 1) = *(_DWORD *)(*(_QWORD *)&v164[0].m_enum + v140 - 24);
      }
      while ( v138 < v174 );
      v67 = v165;
    }
    if ( v174 > 1 )
    {
      hkAlgorithm::quickSortRecursive<`anonymous namespace::SegmentInfo,hkAlgorithm::less<`anonymous namespace::SegmentInfo>>(
        pArr,
        0,
        v174 - 1,
        0);
      v67 = v165;
    }
    v141 = segmentsOut;
    v142 = (signed int)v67;
    v143 = segmentsOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v143 >= (signed int)v67 )
    {
      v181.m_enum = 0;
    }
    else
    {
      v144 = 2 * v143;
      if ( (signed int)v67 < v144 )
        LODWORD(v67) = v144;
      hkArrayUtil::_reserve(&v181, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, segmentsOut, v67, 48);
      v67 = v165;
      if ( v181.m_enum )
        goto LABEL_249;
    }
    v145 = v141->m_size - v142 - 1;
    if ( v145 >= 0 )
    {
      v146 = &v141->m_data[v142 + v145];
      do
      {
        hkaiNavMeshSimplificationUtils::Segment::~Segment(v146);
        --v146;
        --v145;
      }
      while ( v145 >= 0 );
      v67 = v165;
    }
    v147 = v141->m_size;
    v148 = (signed int)v142 - (signed int)v147;
    if ( (signed int)v142 - (signed int)v147 > 0 )
    {
      v149 = (signed __int64)&v141->m_data[v147].m_boundary.m_capacityAndFlags;
      do
      {
        if ( v149 != 28 )
        {
          *(_QWORD *)(v149 - 12) = 0i64;
          *(_DWORD *)(v149 - 4) = 0;
          *(_DWORD *)v149 = 2147483648;
          *(_QWORD *)(v149 + 4) = 0i64;
          *(_DWORD *)(v149 + 12) = 0;
          *(_DWORD *)(v149 + 16) = 2147483648;
        }
        v149 += 48i64;
        --v148;
      }
      while ( v148 );
      v67 = v165;
    }
    v141->m_size = v142;
    if ( v181.m_enum == HK_SUCCESS )
    {
      v153 = 0;
      if ( v174 > 0 )
      {
        v154 = 0i64;
        v155 = 0i64;
        do
        {
          v156 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(*(_QWORD *)&v164[0].m_enum
                                                                              + 48i64 * pArr[v155].m_segmentIndex
                                                                              + 16);
          v141->m_data[v154].m_partitionIdA = *(_DWORD *)(*(_QWORD *)&v164[0].m_enum
                                                        + 48i64 * pArr[v155].m_segmentIndex
                                                        + 4);
          v141->m_data[v154].m_partitionIdB = v156[-1].m_size;
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v141->m_data[v153++].m_boundary,
            v156);
          ++v155;
          ++v154;
        }
        while ( v153 < v174 );
        v67 = v165;
      }
      v10 = v188;
      v157 = v175;
      v174 = 0;
      v188->m_enum = 0;
      if ( v157 >= 0 )
      {
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, SegmentInfo *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          (unsigned int)(16 * v157),
          v67);
        LODWORD(v67) = v165;
      }
      v158 = v67 - 1;
      pArr = 0i64;
      v175 = 2147483648;
      if ( (signed int)v67 - 1 >= 0 )
      {
        v159 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v164[0].m_enum + 48i64 * v158);
        do
        {
          hkaiNavMeshSimplificationUtils::Segment::~Segment(v159);
          --v159;
          --v158;
        }
        while ( v158 >= 0 );
      }
      goto LABEL_264;
    }
LABEL_249:
    v10 = v188;
    v150 = v175;
    v174 = 0;
    v188->m_enum = 1;
    if ( v150 >= 0 )
    {
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, SegmentInfo *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        pArr,
        (unsigned int)(16 * v150),
        v67);
      LODWORD(v67) = v165;
    }
    v151 = v67 - 1;
    pArr = 0i64;
    v175 = 2147483648;
    if ( (signed int)v67 - 1 >= 0 )
    {
      v152 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v164[0].m_enum + 48i64 * v151);
      do
      {
        hkaiNavMeshSimplificationUtils::Segment::~Segment(v152);
        --v152;
        --v151;
      }
      while ( v151 >= 0 );
    }
LABEL_264:
    v165 = 0;
    if ( v166 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)&v164[0].m_enum,
        48 * (v166 & 0x3FFFFFFF));
    *(_QWORD *)&v164[0].m_enum = 0i64;
    v166 = 2147483648;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v177);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v176);
    goto LABEL_267;
  }
  v72 = v9->m_edges.m_data;
  v73 = v56[v71];
  v74 = (signed int)v72[v71].m_oppositeEdge;
  v75 = v71;
  v76 = v71;
  resulta.m_enum = (signed int)v74;
  v187 = v74;
  v171 = v73;
  if ( (_DWORD)v74 == -1 )
    v167 = -1;
  else
    v167 = v56[v74];
  if ( (_DWORD)v74 == -1 )
  {
    LODWORD(v77) = v73;
  }
  else
  {
    v78 = (signed int)v72[v74].m_oppositeEdge;
    if ( (_DWORD)v78 == -1 )
      LODWORD(v77) = -1;
    else
      LODWORD(v77) = v56[v78];
  }
  v79 = v189->m_faces.m_data;
  v183 = v189->m_faces.m_data;
  while ( 1 )
  {
    v80 = v79[*(signed int *)&array[4 * v76]].m_startEdgeIndex;
    v81 = (v75 - 1 + v79[*(signed int *)&array[4 * v76]].m_numEdges - v80)
        % v79[*(signed int *)&array[4 * v76]].m_numEdges;
    v75 = v80 + v81;
    v76 = v80 + v81;
    v172 = v80 + v81;
    v185 = v80 + v81;
    v82 = (signed int)v72[v76].m_oppositeEdge;
    if ( (_DWORD)v82 == -1 )
      v83 = -1;
    else
      v83 = v56[v82];
    if ( v171 == v83 )
    {
      do
      {
        if ( v75 == (_DWORD)v71 )
          break;
        v84 = v79[*(signed int *)&array[4 * (signed int)v82]].m_numEdges;
        v85 = v79[*(signed int *)&array[4 * (signed int)v82]].m_startEdgeIndex;
        v75 = v85 + ((signed int)v82 - 1 + v84 - v85) % v84;
        v76 = v75;
        v82 = (signed int)v72[v75].m_oppositeEdge;
        v83 = (_DWORD)v82 == -1 ? -1 : v56[v82];
        v79 = v183;
      }
      while ( v171 == v83 );
      LODWORD(v74) = resulta;
      v185 = v76;
      v172 = v75;
    }
    if ( (_DWORD)v74 == -1 )
    {
      v90 = v167;
    }
    else
    {
      v86 = v79[*(signed int *)&array[4 * (signed int)v74]].m_numEdges;
      v87 = v79[*(signed int *)&array[4 * (signed int)v74]].m_startEdgeIndex;
      v88 = ((signed int)v74 + 1 + v86 - v87) % v86;
      LODWORD(v74) = v87 + v88;
      resulta.m_enum = v87 + v88;
      v89 = (signed int)v72[v87 + v88].m_oppositeEdge;
      if ( (_DWORD)v89 == -1 )
        LODWORD(v77) = -1;
      else
        LODWORD(v77) = v56[v89];
      v90 = v167;
      if ( v167 == (_DWORD)v77 )
      {
        do
        {
          if ( (_DWORD)v74 == v187 )
            break;
          v91 = (signed __int64)&v189->m_faces.m_data[*(signed int *)&array[4 * (signed int)v89]];
          LODWORD(v74) = *(_DWORD *)v91
                       + ((signed int)v89 + 1 + (signed int)*(signed __int16 *)(v91 + 8) - *(_DWORD *)v91)
                       % *(signed __int16 *)(v91 + 8);
          v89 = (signed int)v72[(signed int)v74].m_oppositeEdge;
          LODWORD(v77) = (_DWORD)v89 == -1 ? -1 : v56[v89];
          v90 = v167;
        }
        while ( v167 == (_DWORD)v77 );
        v75 = v172;
        LODWORD(v71) = v180;
        v76 = v185;
        resulta.m_enum = (signed int)v74;
      }
    }
    if ( v171 != (_DWORD)v77 || v90 != v83 )
      break;
    v79 = v183;
    v92 = v75;
    v178 = v75;
    if ( v75 == (_DWORD)v71 )
      goto LABEL_137;
  }
  v92 = v178;
LABEL_137:
  v93 = v92;
  v94 = v92;
  v95 = (signed int)v189->m_edges.m_data[v92].m_oppositeEdge;
  v172 = v95;
  v180 = v95;
  if ( v92 == -1 )
    v96 = -1;
  else
    v96 = v56[v92];
  v171 = v96;
  if ( (_DWORD)v95 == -1 )
    v97 = -1;
  else
    v97 = v56[v95];
  v98 = v184;
  v99 = v97;
  v100 = -2;
  resulta.m_enum = v97;
  v167 = -2;
  v183 = 0i64;
  while ( 1 )
  {
    if ( v96 == v100 && v99 == v97 )
    {
      v101 = v189;
      goto LABEL_159;
    }
    v101 = v189;
    if ( v98 > v189->m_edges.m_size )
      __debugbreak();
    hkaiArrayUtil::reserveForNonPodType<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v179,
      v164,
      (hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *)(unsigned int)(v98 + 1),
      (int)v77);
    if ( v179.m_enum )
      break;
    v102 = v165;
    if ( v165 == (v166 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v164, 48);
      v102 = v165;
    }
    v103 = *(_QWORD *)&v164[0].m_enum;
    v104 = *(_QWORD *)&v164[0].m_enum + 48i64 * v102;
    if ( v104 )
    {
      *(_QWORD *)(v104 + 16) = 0i64;
      *(_DWORD *)(v104 + 24) = 0;
      *(_DWORD *)(v104 + 28) = 2147483648;
      *(_QWORD *)(v104 + 32) = 0i64;
      *(_DWORD *)(v104 + 40) = 0;
      *(_DWORD *)(v104 + 44) = 2147483648;
      v102 = v165;
      v103 = *(_QWORD *)&v164[0].m_enum;
    }
    v105 = v171;
    v165 = v102 + 1;
    resulta.m_enum = v97;
    v106 = v103 + 48i64 * v102;
    v183 = (hkaiNavMesh::Face *)v106;
    *(_DWORD *)(v106 + 4) = v171;
    *(_DWORD *)(v106 + 8) = v97;
    v107 = v101->m_edges.m_data;
    v95 = (signed int)v107[v93].m_oppositeEdge;
    v172 = v95;
    if ( (_DWORD)v95 == -1 )
    {
      v100 = v105;
      v167 = v105;
    }
    else if ( v107[v95].m_oppositeEdge == -1 )
    {
      v100 = -1;
      v167 = -1;
    }
    else
    {
      v108 = (signed int)v107[v95].m_oppositeEdge;
      v100 = *(_DWORD *)&v161[4 * v108];
      v167 = *(_DWORD *)&v161[4 * v108];
    }
LABEL_159:
    v109 = v183;
    v110 = *(_DWORD *)&v183[1].m_numEdges + 1;
    v111 = *(_DWORD *)&v183[1].m_clusterIndex & 0x3FFFFFFF;
    if ( v111 >= v110 )
    {
      v186.m_enum = 0;
    }
    else
    {
      v112 = 2 * v111;
      if ( v110 < v112 )
        v110 = v112;
      hkArrayUtil::_reserve(&v186, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v183[1], v110, 4);
      if ( v186.m_enum )
      {
        v65 = v188;
        v113 = (signed int)(v165 - 1) < 0;
        v114 = v165 - 1;
        v188->m_enum = 1;
        v115 = v114;
        if ( !v113 )
        {
          v116 = (int *)(48i64 * v114 + *(_QWORD *)&v164[0].m_enum + 44i64);
          do
          {
            v117 = *v116;
            *(v116 - 1) = 0;
            if ( v117 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v116 - 3),
                4 * v117);
            *(_QWORD *)(v116 - 3) = 0i64;
            *v116 = 2147483648;
            v118 = *(v116 - 4);
            *(v116 - 5) = 0;
            if ( v118 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v116 - 7),
                4 * v118);
            *(_QWORD *)(v116 - 7) = 0i64;
            *(v116 - 4) = 2147483648;
            v116 -= 12;
            --v115;
          }
          while ( v115 >= 0 );
        }
        goto LABEL_204;
      }
    }
    *(_DWORD *)(*(_QWORD *)&v109[1].m_startEdgeIndex + 4i64 * (signed int)(*(_DWORD *)&v109[1].m_numEdges)++) = v94;
    LODWORD(v176.m_data.m_data[v93 >> 5]) &= ~(1 << (v94 & 0x1F));
    v119 = v101->m_faces.m_data;
    v120 = (signed int *)array;
    v121 = v119[*(signed int *)&array[4 * v93]].m_startEdgeIndex;
    v122 = v101->m_edges.m_data;
    v56 = v161;
    v94 = v121
        + (v94 + 1 + v119[*(signed int *)&array[4 * v93]].m_numEdges - v121)
        % v119[*(signed int *)&array[4 * v93]].m_numEdges;
    v93 = v94;
    v185 = v94;
    v77 = (hkaiNavMesh::Edge *)(signed int)v122[v94].m_oppositeEdge;
    if ( (_DWORD)v77 == -1 )
      v97 = -1;
    else
      v97 = *(_DWORD *)&v161[4 * (_QWORD)v77];
    v96 = v171;
    if ( v171 == v97 )
    {
      do
      {
        if ( v94 == v178 )
          break;
        v123 = v119[*(signed int *)&array[4 * (signed int)v77]].m_startEdgeIndex;
        v94 = v123
            + ((signed int)v77 + 1 + v119[*(signed int *)&array[4 * (signed int)v77]].m_numEdges - v123)
            % v119[*(signed int *)&array[4 * (signed int)v77]].m_numEdges;
        v93 = v94;
        v77 = (hkaiNavMesh::Edge *)(signed int)v189->m_edges.m_data[v94].m_oppositeEdge;
        v97 = (_DWORD)v77 == -1 ? -1 : *(_DWORD *)&v161[4 * (_QWORD)v77];
      }
      while ( v171 == v97 );
      v100 = v167;
      LODWORD(v95) = v172;
      v120 = (signed int *)array;
      v185 = v93;
    }
    if ( (_DWORD)v95 == -1 )
    {
      v99 = resulta.m_enum;
    }
    else
    {
      v124 = v119[v120[(signed int)v95]].m_numEdges;
      v125 = v119[v120[(signed int)v95]].m_startEdgeIndex;
      LODWORD(v95) = v125 + ((signed int)v95 - 1 + v124 - v125) % v124;
      v172 = v95;
      v77 = v189->m_edges.m_data;
      v126 = (signed int)v77[(signed int)v95].m_oppositeEdge;
      if ( (_DWORD)v126 == -1 )
        v100 = -1;
      else
        v100 = *(_DWORD *)&v161[4 * v126];
      v99 = resulta.m_enum;
      v167 = v100;
      if ( resulta.m_enum == v100 )
      {
        do
        {
          if ( (_DWORD)v95 == v180 )
            break;
          v127 = v119[*(signed int *)&array[4 * (signed int)v126]].m_numEdges;
          v128 = v119[*(signed int *)&array[4 * (signed int)v126]].m_startEdgeIndex;
          LODWORD(v95) = v128 + ((signed int)v126 - 1 + v127 - v128) % v127;
          v126 = (signed int)v77[(signed int)v95].m_oppositeEdge;
          v100 = (_DWORD)v126 == -1 ? -1 : *(_DWORD *)&v161[4 * v126];
          v99 = resulta.m_enum;
        }
        while ( resulta.m_enum == v100 );
        v93 = v185;
        v96 = v171;
        v172 = v95;
        v167 = v100;
      }
    }
    if ( v94 == v178 )
    {
      v67 = v165;
      v66 = v182;
      v9 = v189;
      v47 = v177.m_data;
      v184 = v165;
      goto LABEL_94;
    }
    v98 = v165;
  }
  v65 = v188;
  v113 = (signed int)(v165 - 1) < 0;
  v129 = v165 - 1;
  v188->m_enum = 1;
  v130 = v129;
  if ( !v113 )
  {
    v131 = (int *)(48i64 * v129 + *(_QWORD *)&v164[0].m_enum + 44i64);
    do
    {
      v132 = *v131;
      *(v131 - 1) = 0;
      if ( v132 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v131 - 3),
          4 * v132);
      *(_QWORD *)(v131 - 3) = 0i64;
      *v131 = 2147483648;
      v133 = *(v131 - 4);
      *(v131 - 5) = 0;
      if ( v133 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v131 - 7),
          4 * v133);
      *(_QWORD *)(v131 - 7) = 0i64;
      *(v131 - 4) = 2147483648;
      v131 -= 12;
      --v130;
    }
    while ( v130 >= 0 );
  }
LABEL_204:
  v165 = 0;
  if ( v166 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&v164[0].m_enum,
      48 * (v166 & 0x3FFFFFFF));
  *(_QWORD *)&v164[0].m_enum = 0i64;
  v166 = 2147483648;
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v177);
  v176.m_data.m_size = 0;
  if ( v176.m_data.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v176.m_data.m_data,
      4 * v176.m_data.m_capacityAndFlags);
  v162 = 0;
  v176.m_data.m_capacityAndFlags = 2147483648;
  v176.m_data.m_data = 0i64;
  if ( v163 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v161,
      4 * v163);
  v161 = 0i64;
  v169 = 0;
LABEL_211:
  v163 = 2147483648;
  if ( v170 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v170);
  return v65;
} 12;
      --v130;
    }
    while ( v130 >= 0 );
  }
LABEL_204:
  v165 = 0;
  if ( v166 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&v164[0].m_enum,
      48 * (v166 & 0x3FFFFFFF));
  *(_QWORD *)&v1

// File Line: 926
// RVA: 0xB506E0
void __fastcall anonymous_namespace_::getProjectionMatrix(int majorAxis, hkRotationf *projectionMatrix)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm4
  __m128 v4; // xmm2
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx

  v2 = transform.m_quad;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      v2 = _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 216), (__m128)xmmword_141A71320);
    }
    else if ( majorAxis != 2 )
    {
      if ( majorAxis == 3 )
      {
        v2 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 230);
      }
      else if ( majorAxis == 4 )
      {
        v2 = _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 210), (__m128)xmmword_141A71320);
      }
      else
      {
        v2 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 225);
      }
    }
  }
  else
  {
    v2 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 233);
  }
  v3 = direction.m_quad;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      v3 = _mm_mul_ps(_mm_shuffle_ps(direction.m_quad, direction.m_quad, 216), (__m128)xmmword_141A71320);
    }
    else if ( majorAxis != 2 )
    {
      if ( majorAxis == 3 )
      {
        v3 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 230);
      }
      else if ( majorAxis == 4 )
      {
        v3 = _mm_mul_ps(_mm_shuffle_ps(direction.m_quad, direction.m_quad, 210), (__m128)xmmword_141A71320);
      }
      else
      {
        v3 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 225);
      }
    }
  }
  else
  {
    v3 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 233);
  }
  v4 = stru_141A71280.m_quad;
  if ( majorAxis )
  {
    v5 = majorAxis - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 == 1 )
            v4 = _mm_mul_ps(
                   _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 210),
                   (__m128)xmmword_141A71320);
          else
            v4 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 225);
        }
        else
        {
          v4 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 230);
        }
      }
    }
    else
    {
      v4 = _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 216), (__m128)xmmword_141A71320);
    }
  }
  else
  {
    v4 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 233);
  }
  projectionMatrix->m_col0.m_quad = _mm_shuffle_ps(v2, _mm_unpackhi_ps(v2, (__m128)0i64), 180);
  projectionMatrix->m_col1.m_quad = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, (__m128)0i64), 180);
  projectionMatrix->m_col2.m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, (__m128)0i64), 180);
}

// File Line: 950
// RVA: 0xB507E0
hkSimdFloat32 *__fastcall `anonymous namespace::computeSignedLoopArea(hkSimdFloat32 *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<int,hkContainerHeapAllocator> *indices, int majorAxis)
{
  hkVector4f *v4; // r11
  int *v5; // r10
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  __int64 v8; // rdx
  __int64 v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  hkSimdFloat32 *v15; // rax

  v4 = vertices->m_data;
  v5 = indices->m_data;
  v6 = 0i64;
  v7 = vertices->m_data[*indices->m_data].m_quad;
  v8 = indices->m_size - 1;
  if ( indices->m_size - 1 > 0 )
  {
    while ( 1 )
    {
      v9 = *v5;
      ++v5;
      v10 = _mm_sub_ps(v4[v9].m_quad, v7);
      v11 = _mm_sub_ps(v4[*v5].m_quad, v7);
      if ( !majorAxis )
        break;
      switch ( majorAxis )
      {
        case 1:
          v10 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 216), (__m128)xmmword_141A71320);
          break;
        case 2:
          break;
        case 3:
          v12 = _mm_shuffle_ps(v10, v10, 230);
LABEL_12:
          v10 = v12;
          break;
        case 4:
          v10 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 210), (__m128)xmmword_141A71320);
          break;
        default:
          v10 = _mm_shuffle_ps(v10, v10, 225);
          break;
      }
      if ( !majorAxis )
      {
        v13 = _mm_shuffle_ps(v11, v11, 233);
LABEL_23:
        v11 = v13;
        goto LABEL_24;
      }
      if ( majorAxis == 1 )
      {
        v11 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 216), (__m128)xmmword_141A71320);
      }
      else if ( majorAxis != 2 )
      {
        if ( majorAxis != 3 )
        {
          if ( majorAxis == 4 )
            v11 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 210), (__m128)xmmword_141A71320);
          else
            v11 = _mm_shuffle_ps(v11, v11, 225);
          goto LABEL_24;
        }
        v13 = _mm_shuffle_ps(v11, v11, 230);
        goto LABEL_23;
      }
LABEL_24:
      v14 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 225), v11);
      v6 = _mm_add_ps(v6, _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), _mm_shuffle_ps(v14, v14, 85)));
      if ( !--v8 )
        goto LABEL_25;
    }
    v12 = _mm_shuffle_ps(v10, v10, 233);
    goto LABEL_12;
  }
LABEL_25:
  v15 = result;
  result->m_real = _mm_mul_ps((__m128)xmmword_141A711B0, v6);
  return v15;
}

// File Line: 971
// RVA: 0xB50920
char __fastcall `anonymous namespace::areOppositeSegments(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkaiNavMeshSimplificationUtils::Segment *seg1, hkaiNavMeshSimplificationUtils::Segment *seg2, hkaiNavMesh *navMesh, hkResult *resOut)
{
  hkResult *v5; // r14
  hkaiNavMesh *v6; // r15
  hkaiNavMeshSimplificationUtils::Segment *v7; // rdi
  hkaiNavMeshSimplificationUtils::Segment *v8; // rsi
  signed __int64 v9; // rbx
  hkResultEnum v11; // eax
  hkResultEnum v12; // eax
  signed __int64 i; // r9
  int *v14; // r8
  int *v15; // r8
  __int64 v16; // rax
  hkaiNavMesh::Edge *v17; // rdx
  hkaiNavMesh::Edge *v18; // r10
  char v19; // bl
  int *pArr; // [rsp+30h] [rbp-20h]
  int v21; // [rsp+38h] [rbp-18h]
  int v22; // [rsp+3Ch] [rbp-14h]
  int *array; // [rsp+40h] [rbp-10h]
  int v24; // [rsp+48h] [rbp-8h]
  int v25; // [rsp+4Ch] [rbp-4h]

  v5 = resOut;
  v6 = navMesh;
  resOut->m_enum = 0;
  v7 = seg2;
  v8 = seg1;
  if ( *(_QWORD *)&seg1->m_partitionIdA != __PAIR__(seg2->m_partitionIdA, seg2->m_partitionIdB) )
    return 0;
  v9 = seg1->m_boundary.m_size;
  if ( (_DWORD)v9 != seg2->m_boundary.m_size )
    return 0;
  array = 0i64;
  v24 = 0;
  v25 = 2147483648;
  pArr = 0i64;
  v21 = 0;
  v22 = 2147483648;
  if ( (signed int)v9 <= 0 )
  {
    v11 = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      (hkResult *)&resOut,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v9,
      4);
    v11 = (signed int)resOut;
  }
  v5->m_enum = v11;
  if ( v11 )
    goto LABEL_26;
  if ( (v22 & 0x3FFFFFFF) >= (signed int)v9 )
  {
    v12 = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      (hkResult *)&resOut,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &pArr,
      v9,
      4);
    v12 = (signed int)resOut;
  }
  v5->m_enum = v12;
  if ( v12 )
    goto LABEL_26;
  for ( i = 0i64; i < v9; ++v21 )
  {
    v14 = &v8->m_boundary.m_data[i++];
    array[v24++] = *v14;
    pArr[v21] = v6->m_edges.m_data[v7->m_boundary.m_data[i - 1]].m_oppositeEdge;
  }
  if ( v24 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(array, 0, v24 - 1, 0);
  if ( v21 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(pArr, 0, v21 - 1, 0);
  navMesh = 0i64;
  if ( v9 > 0 )
  {
    v15 = array;
    while ( 1 )
    {
      v16 = *v15;
      if ( (_DWORD)v16 != *(int *)((char *)v15 + (char *)pArr - (char *)array) )
        break;
      v17 = v6->m_edges.m_data;
      v18 = &v17[v16];
      if ( v18->m_a != v17[v17[v16].m_oppositeEdge].m_b || v18->m_b != v17[v17[v16].m_oppositeEdge].m_a )
        break;
      navMesh = (hkaiNavMesh *)((char *)navMesh + 1);
      ++v15;
      if ( (signed __int64)navMesh >= v9 )
        goto LABEL_25;
    }
LABEL_26:
    v19 = 0;
    goto LABEL_27;
  }
LABEL_25:
  v19 = 1;
LABEL_27:
  v21 = 0;
  if ( v22 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, hkaiNavMesh *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      pArr,
      (unsigned int)(4 * v22),
      navMesh);
  pArr = 0i64;
  v22 = 2147483648;
  v24 = 0;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v25);
  return v19;
}

// File Line: 1017
// RVA: 0xB50BA0
hkSimdFloat32 *__fastcall `anonymous namespace::getSignedSegmentArea(hkSimdFloat32 *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkaiNavMeshSimplificationUtils::Segment *seg, bool forwards, int majorAxis)
{
  int *v5; // r10
  hkVector4f *v6; // r11
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  int v9; // eax
  int v10; // eax
  __int64 v11; // r8
  __int64 v12; // rax
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  int v18; // eax
  __int64 v19; // r9
  int *v20; // r8
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  hkSimdFloat32 *v26; // rax

  v5 = seg->m_indices.m_data;
  v6 = vertices->m_data;
  v7 = 0i64;
  v8 = vertices->m_data[*v5].m_quad;
  v9 = seg->m_indices.m_size;
  if ( !forwards )
  {
    v18 = v9 - 2;
    v19 = v18;
    if ( v18 < 0 )
      goto LABEL_52;
    v20 = &v5[v18];
    while ( 1 )
    {
      v21 = _mm_sub_ps(v6[v20[1]].m_quad, v8);
      v22 = _mm_sub_ps(v6[*v20].m_quad, v8);
      if ( !majorAxis )
        break;
      switch ( majorAxis )
      {
        case 1:
          v21 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 216), (__m128)xmmword_141A71320);
          break;
        case 2:
          break;
        case 3:
          v23 = _mm_shuffle_ps(v21, v21, 230);
LABEL_39:
          v21 = v23;
          break;
        case 4:
          v21 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 210), (__m128)xmmword_141A71320);
          break;
        default:
          v21 = _mm_shuffle_ps(v21, v21, 225);
          break;
      }
      if ( !majorAxis )
      {
        v24 = _mm_shuffle_ps(v22, v22, 233);
LABEL_50:
        v22 = v24;
        goto LABEL_51;
      }
      if ( majorAxis == 1 )
      {
        v22 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 216), (__m128)xmmword_141A71320);
      }
      else if ( majorAxis != 2 )
      {
        if ( majorAxis != 3 )
        {
          if ( majorAxis == 4 )
            v22 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 210), (__m128)xmmword_141A71320);
          else
            v22 = _mm_shuffle_ps(v22, v22, 225);
          goto LABEL_51;
        }
        v24 = _mm_shuffle_ps(v22, v22, 230);
        goto LABEL_50;
      }
LABEL_51:
      --v20;
      --v19;
      v25 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 225), v22);
      v7 = _mm_add_ps(v7, _mm_sub_ps(_mm_shuffle_ps(v25, v25, 0), _mm_shuffle_ps(v25, v25, 85)));
      if ( v19 < 0 )
        goto LABEL_52;
    }
    v23 = _mm_shuffle_ps(v21, v21, 233);
    goto LABEL_39;
  }
  v10 = v9 - 1;
  v11 = v10;
  if ( v10 > 0 )
  {
    while ( 1 )
    {
      v12 = *v5;
      ++v5;
      v13 = _mm_sub_ps(v6[v12].m_quad, v8);
      v14 = _mm_sub_ps(v6[*v5].m_quad, v8);
      if ( !majorAxis )
        break;
      switch ( majorAxis )
      {
        case 1:
          v13 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 216), (__m128)xmmword_141A71320);
          break;
        case 2:
          break;
        case 3:
          v15 = _mm_shuffle_ps(v13, v13, 230);
LABEL_13:
          v13 = v15;
          break;
        case 4:
          v13 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 210), (__m128)xmmword_141A71320);
          break;
        default:
          v13 = _mm_shuffle_ps(v13, v13, 225);
          break;
      }
      if ( !majorAxis )
      {
        v16 = _mm_shuffle_ps(v14, v14, 233);
LABEL_24:
        v14 = v16;
        goto LABEL_25;
      }
      if ( majorAxis == 1 )
      {
        v14 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 216), (__m128)xmmword_141A71320);
      }
      else if ( majorAxis != 2 )
      {
        if ( majorAxis != 3 )
        {
          if ( majorAxis == 4 )
            v14 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 210), (__m128)xmmword_141A71320);
          else
            v14 = _mm_shuffle_ps(v14, v14, 225);
          goto LABEL_25;
        }
        v16 = _mm_shuffle_ps(v14, v14, 230);
        goto LABEL_24;
      }
LABEL_25:
      v17 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 225), v14);
      v7 = _mm_add_ps(v7, _mm_sub_ps(_mm_shuffle_ps(v17, v17, 0), _mm_shuffle_ps(v17, v17, 85)));
      if ( !--v11 )
        goto LABEL_52;
    }
    v15 = _mm_shuffle_ps(v13, v13, 233);
    goto LABEL_13;
  }
LABEL_52:
  v26 = result;
  result->m_real = _mm_mul_ps((__m128)xmmword_141A711B0, v7);
  return v26;
}

// File Line: 1060
// RVA: 0xB50DE0
__int64 __fastcall `anonymous namespace::computeSignedPartitionArea(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, hkArrayBase<int> *segmentToOppositeMap, hkPointerMultiMap<int,int> *parToSegIdxMap, int segmentIndex, int partition, int majorAxis, hkSimdFloat32 *areaOut, hkResult *resOut)
{
  hkResult *v9; // r12
  int v10; // esi
  unsigned __int64 v11; // rdi
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v12; // r13
  hkPointerMultiMap<int,int> *v13; // r15
  hkaiNavMeshSimplificationUtils::Segment *v14; // r10
  int *v15; // rdx
  int v16; // er14
  signed int v17; // ebx
  __int64 v18; // r14
  signed __int64 v19; // rsi
  int v20; // ecx
  int v21; // er8
  int v22; // er9
  int v23; // eax
  __int64 v24; // rax
  __int64 v25; // r10
  int v26; // er8
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v28; // rax
  int v29; // er8
  signed int *v30; // r12
  int v31; // er13
  int v32; // er15
  int v33; // edi
  __int64 v34; // rbx
  signed int *v35; // rdx
  __int64 v36; // r14
  hkaiNavMeshSimplificationUtils::Segment *v37; // rsi
  _DWORD *v38; // rcx
  unsigned __int8 v39; // bl
  hkSimdFloat32 *v40; // rax
  int *v41; // rax
  signed __int64 v42; // rcx
  signed __int64 v43; // rbx
  signed __int64 v44; // rdx
  __int64 v45; // rax
  hkSimdFloat32 *v46; // rax
  signed __int64 v47; // rcx
  signed __int64 v48; // rbx
  signed __int64 v49; // rdx
  __int64 v50; // rax
  signed int *array; // [rsp+30h] [rbp-30h]
  int v53; // [rsp+38h] [rbp-28h]
  int v54; // [rsp+3Ch] [rbp-24h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-20h]
  hkSimdFloat32 v56; // [rsp+50h] [rbp-10h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *verticesa; // [rsp+A0h] [rbp+40h]
  int v58; // [rsp+A8h] [rbp+48h]
  hkArrayBase<int> *v59; // [rsp+B0h] [rbp+50h]

  v59 = segmentToOppositeMap;
  verticesa = vertices;
  v9 = resOut;
  v10 = segmentIndex;
  v11 = partition;
  v12 = segments;
  resOut->m_enum = 0;
  v13 = parToSegIdxMap;
  v14 = &segments->m_data[segmentIndex];
  v15 = v14->m_indices.m_data;
  v58 = *v15;
  v16 = v15[v14->m_indices.m_size - 1];
  array = 0i64;
  v53 = 0;
  *areaOut = 0i64;
  LODWORD(resOut) = v16;
  v54 = 2147483648;
  v17 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                            &parToSegIdxMap->m_map,
                            v11);
  if ( v17 <= v13->m_map.m_hashMod )
  {
    do
    {
      v18 = SLODWORD(v13->m_map.m_elem[v17].val);
      v19 = (signed __int64)&v12->m_data[v18];
      if ( **(_DWORD **)(v19 + 32) != *(_DWORD *)(*(_QWORD *)(v19 + 32) + 4i64 * *(signed int *)(v19 + 40) - 4) )
      {
        v20 = v53;
        v21 = v54;
        v22 = v53 + 1;
        if ( (v54 & 0x3FFFFFFF) >= v53 + 1 )
        {
          v23 = 0;
          partition = 0;
        }
        else
        {
          if ( v22 < 2 * (v54 & 0x3FFFFFFF) )
            v22 = 2 * (v54 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(
            (hkResult *)&partition,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &array,
            v22,
            16);
          v21 = v54;
          v20 = v53;
          v23 = partition;
        }
        v9->m_enum = v23;
        if ( v23 )
        {
          v30 = array;
          v39 = 0;
          goto LABEL_48;
        }
        if ( v20 == (v21 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16);
          v20 = v53;
        }
        v24 = (__int64)&array[4 * v20];
        v53 = v20 + 1;
        *(_QWORD *)v24 = v19;
        *(_DWORD *)(v24 + 8) = v18;
      }
      v25 = v13->m_map.m_hashMod;
      v26 = v17 + 1;
      for ( i = v17 + 1; i > v25; i = 0i64 )
LABEL_18:
        v26 = 0;
      v28 = &v13->m_map.m_elem[i];
      while ( v28->key != -1i64 )
      {
        if ( v28->key == v11 )
        {
          v17 = v26;
          goto LABEL_21;
        }
        ++i;
        ++v26;
        ++v28;
        if ( i > v25 )
          goto LABEL_18;
      }
      v17 = v25 + 1;
LABEL_21:
      ;
    }
    while ( v17 <= (signed int)v25 );
    v10 = segmentIndex;
    v16 = (signed int)resOut;
  }
  v29 = v58;
  v30 = array;
  if ( v58 == v16 )
    goto LABEL_47;
  v31 = majorAxis;
  v32 = v53;
  while ( 2 )
  {
    v33 = 0;
    v34 = 0i64;
    if ( v32 <= 0 )
      goto LABEL_45;
    v35 = v30;
    while ( 1 )
    {
      v36 = v35[2];
      if ( (_DWORD)v36 == v10 || v59->m_data[v36] == v10 )
        goto LABEL_32;
      v37 = *(hkaiNavMeshSimplificationUtils::Segment **)v35;
      v38 = *(_DWORD **)(*(_QWORD *)v35 + 32i64);
      if ( *v38 == v29 )
        break;
      if ( v38[v37->m_indices.m_size - 1] == v29 )
      {
        v40 = `anonymous namespace::getSignedSegmentArea(&result, verticesa, v37, 0, v31);
        --v32;
        segmentIndex = v36;
        areaOut->m_real = _mm_add_ps(areaOut->m_real, v40->m_real);
        v41 = v37->m_indices.m_data;
        v10 = v36;
        v29 = *v41;
        v53 = v32;
        if ( v32 == v33 )
          goto LABEL_43;
        v42 = 2i64;
        v43 = (signed __int64)&v30[4 * v34];
        v44 = (signed __int64)&v30[4 * v32] - v43;
        do
        {
          v45 = *(_QWORD *)(v44 + v43);
          v43 += 8i64;
          *(_QWORD *)(v43 - 8) = v45;
          --v42;
        }
        while ( v42 );
        goto LABEL_42;
      }
      v10 = segmentIndex;
LABEL_32:
      ++v33;
      ++v34;
      v35 += 4;
      if ( v33 >= v32 )
        goto LABEL_44;
    }
    v46 = `anonymous namespace::getSignedSegmentArea(&v56, verticesa, v37, 1, v31);
    --v32;
    segmentIndex = v36;
    areaOut->m_real = _mm_add_ps(areaOut->m_real, v46->m_real);
    v29 = v37->m_indices.m_data[v37->m_indices.m_size - 1];
    v10 = v36;
    v53 = v32;
    if ( v32 == v33 )
      goto LABEL_43;
    v47 = 2i64;
    v48 = (signed __int64)&v30[4 * v34];
    v49 = (signed __int64)&v30[4 * v32] - v48;
    do
    {
      v50 = *(_QWORD *)(v49 + v48);
      v48 += 8i64;
      *(_QWORD *)(v48 - 8) = v50;
      --v47;
    }
    while ( v47 );
LABEL_42:
    v32 = v53;
    v30 = array;
LABEL_43:
    --v33;
LABEL_44:
    v16 = (signed int)resOut;
LABEL_45:
    if ( v33 != v32 )
    {
      if ( v29 == v16 )
      {
LABEL_47:
        v21 = v54;
        v39 = 1;
        goto LABEL_48;
      }
      continue;
    }
    break;
  }
  v21 = v54;
  v39 = 0;
LABEL_48:
  v53 = 0;
  if ( v21 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v30,
      16 * v21);
  return v39;
}

// File Line: 1139
// RVA: 0xB51180
signed __int64 __fastcall `anonymous namespace::computePartialSignedPartitionAreas(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, hkArrayBase<int> *segmentToOppositeMap, hkPointerMultiMap<int,int> *parToSegIdxMap, int segmentIndex, int majorAxisA, int majorAxisB, hkSimdFloat32 *area1Out, hkSimdFloat32 *area2Out, hkResult *resOut)
{
  unsigned int v10; // ebx
  hkPointerMultiMap<int,int> *v11; // r13
  hkaiNavMeshSimplificationUtils::Segment *v12; // rdi
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v13; // r15
  char v15; // cl
  bool v16; // zf
  int partition; // ecx
  char v18; // al
  hkArray<hkVector4f,hkContainerHeapAllocator> *verticesa; // [rsp+90h] [rbp+8h]
  hkArrayBase<int> *segmentToOppositeMapa; // [rsp+A0h] [rbp+18h]

  segmentToOppositeMapa = segmentToOppositeMap;
  verticesa = vertices;
  v10 = 0;
  resOut->m_enum = 0;
  v11 = parToSegIdxMap;
  v12 = &segments->m_data[segmentIndex];
  v13 = segments;
  if ( *v12->m_indices.m_data == v12->m_indices.m_data[v12->m_indices.m_size - 1] )
    return 1i64;
  *area1Out = 0i64;
  *area2Out = 0i64;
  v15 = `anonymous namespace::computeSignedPartitionArea(
          vertices,
          segments,
          segmentToOppositeMap,
          parToSegIdxMap,
          segmentIndex,
          v12->m_partitionIdA,
          majorAxisA,
          area1Out,
          resOut);
  if ( resOut->m_enum )
    return 0i64;
  v16 = v15 == 0;
  partition = v12->m_partitionIdB;
  if ( !v16 )
    v10 = 1;
  if ( partition != -1 )
  {
    v18 = `anonymous namespace::computeSignedPartitionArea(
            verticesa,
            v13,
            segmentToOppositeMapa,
            v11,
            segmentIndex,
            partition,
            majorAxisB,
            area2Out,
            resOut);
    if ( resOut->m_enum )
      return 0i64;
    if ( v18 )
    {
      if ( !v10 )
        *area1Out = (hkSimdFloat32)area2Out->m_real;
      ++v10;
    }
  }
  return v10;
}

// File Line: 1185
// RVA: 0xB512D0
void __fastcall `anonymous namespace::computeFullSignedPartitionAreas(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, int segmentIndex, int majorAxisA, int majorAxisB, hkSimdFloat32 *area1InOut, hkSimdFloat32 *area2InOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rsi
  int v8; // edi
  hkaiNavMeshSimplificationUtils::Segment *v9; // rbx
  __m128 v10; // xmm1
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h]

  v7 = vertices;
  v8 = majorAxisA;
  v9 = &segments->m_data[segmentIndex];
  if ( *v9->m_indices.m_data == v9->m_indices.m_data[v9->m_indices.m_size - 1] )
  {
    *area1InOut = (hkSimdFloat32)`anonymous namespace::computeSignedLoopArea(
                                   &result,
                                   vertices,
                                   &v9->m_indices,
                                   majorAxisA)->m_real;
  }
  else
  {
    `anonymous namespace::getSignedSegmentArea(&result, vertices, v9, 0, majorAxisA);
    v10 = result.m_real;
    area1InOut->m_real = _mm_add_ps(area1InOut->m_real, result.m_real);
    if ( v8 == majorAxisB )
    {
      area2InOut->m_real = _mm_add_ps(area2InOut->m_real, v10);
    }
    else if ( majorAxisB != -1 )
    {
      area2InOut->m_real = _mm_add_ps(
                             `anonymous namespace::getSignedSegmentArea(&result, v7, v9, 0, majorAxisB)->m_real,
                             area2InOut->m_real);
    }
  }
}

// File Line: 1211
// RVA: 0xB513C0
float __fastcall `anonymous namespace::getTriangleArea(hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  __m128 v8; // xmm5
  __m128 v9; // xmm2

  v3 = _mm_sub_ps(c->m_quad, a->m_quad);
  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3));
  v6 = _mm_shuffle_ps(v5, v5, 201);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  return COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpleps(v8, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
               v8)))
       * 0.5;
}

// File Line: 1219
// RVA: 0xB51450
float __fastcall `anonymous namespace::getProjectedTriangleArea(hkVector4f *a, hkVector4f *b, hkVector4f *c, int majorAxis)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  int v7; // er9
  int v8; // er9
  int v9; // er9
  __m128 v10; // xmm0
  __m128 v11; // xmm2

  v4 = _mm_sub_ps(c->m_quad, b->m_quad);
  v5 = _mm_sub_ps(c->m_quad, a->m_quad);
  switch ( majorAxis )
  {
    case 0:
      v6 = _mm_shuffle_ps(v5, v5, 233);
      goto LABEL_11;
    case 1:
      v5 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 216), (__m128)xmmword_141A71320);
      break;
    case 2:
      break;
    case 3:
      v6 = _mm_shuffle_ps(v5, v5, 230);
LABEL_11:
      v5 = v6;
      break;
    case 4:
      v5 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 210), (__m128)xmmword_141A71320);
      break;
    default:
      v5 = _mm_shuffle_ps(v5, v5, 225);
      break;
  }
  if ( !majorAxis )
  {
    v10 = _mm_shuffle_ps(v4, v4, 233);
    goto LABEL_22;
  }
  v7 = majorAxis - 1;
  if ( !v7 )
  {
    v4 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 216), (__m128)xmmword_141A71320);
    goto LABEL_23;
  }
  v8 = v7 - 1;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        v4 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 210), (__m128)xmmword_141A71320);
      else
        v4 = _mm_shuffle_ps(v4, v4, 225);
      goto LABEL_23;
    }
    v10 = _mm_shuffle_ps(v4, v4, 230);
LABEL_22:
    v4 = v10;
  }
LABEL_23:
  v11 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 225), v4);
  return COERCE_FLOAT((unsigned int)(2
                                   * COERCE_SIGNED_INT(
                                       COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0))
                                     - COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)))) >> 1)
       * 0.5;
}

// File Line: 1279
// RVA: 0xB51540
char __fastcall `anonymous namespace::edgesIntersect(hkVector2f *s0, hkVector2f *e0, hkVector2f *s1, hkVector2f *e1, hkVector2f *out)
{
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm9_4
  float v11; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm3_4
  float v17; // xmm1_4

  v5 = s1->y;
  v6 = e0->x - s0->x;
  v7 = s0->y;
  v8 = e1->y - v5;
  v9 = e1->x - s1->x;
  v10 = e0->y - v7;
  v11 = (float)(v6 * v8) - (float)(v9 * v10);
  if ( v11 == 0.0 )
    return 0;
  v13 = v7 - v5;
  v14 = s0->x - s1->x;
  v15 = 1.0 / v11;
  v16 = (float)((float)(v13 * v9) - (float)(v14 * v8)) * (float)(1.0 / v11);
  if ( v16 < 0.0 )
    return 0;
  if ( v16 > 1.0 )
    return 0;
  v17 = (float)((float)(v13 * v6) - (float)(v14 * v10)) * v15;
  if ( v17 < 0.0 || v17 > 1.0 )
    return 0;
  out->x = (float)(v6 * v16) + s0->x;
  out->y = (float)((float)(e0->y - s0->y) * v16) + s0->y;
  return 1;
}

// File Line: 1374
// RVA: 0xB51680
_BOOL8 __fastcall `anonymous namespace::_pointsAreDistinct(hkVector4f *start, hkVector4f *end, hkVector4f *v1, hkVector4f *v2, hkVector4f *epsilon)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1

  v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(start->m_quad, v2->m_quad), 1u), 1u);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(start->m_quad, v1->m_quad), 1u), 1u);
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(end->m_quad, v1->m_quad), 1u), 1u);
  v8 = _mm_shuffle_ps(v6, v5, 68);
  v9 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(end->m_quad, v2->m_quad), 1u), 1u);
  v10 = _mm_shuffle_ps(v7, v9, 68);
  return _mm_movemask_ps(
           _mm_cmpltps(
             epsilon->m_quad,
             _mm_max_ps(
               _mm_max_ps(_mm_shuffle_ps(v8, v10, 136), _mm_shuffle_ps(v8, v10, 221)),
               _mm_shuffle_ps(_mm_shuffle_ps(v6, v5, 238), _mm_shuffle_ps(v7, v9, 238), 136)))) == 15;
}

// File Line: 1470
// RVA: 0xB5A1A0
_BOOL8 __fastcall _processLeaf_PartitionIntersectionQuery__A0x257692e2_2_UEAAIIAEBVhkAabb___Z(PartitionIntersectionQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  PartitionIntersectionQuery *v3; // rsi
  hkaiNavMeshSimplificationUtils::Segment *v4; // rbx
  int v5; // eax
  hkRotationf *v6; // r14
  int v7; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v8; // r12
  __int64 v9; // rbp
  __int64 v10; // rdi
  __m128 v11; // xmm5
  __int64 v12; // r11
  __int64 v13; // r15
  int *v14; // r10
  __int64 v15; // rdx
  __int64 v16; // rax
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm13
  __m128 v21; // xmm1
  __m128 v22; // xmm12
  __m128 v23; // xmm1
  __m128 v24; // xmm14
  __m128 v25; // xmm1
  __m128 v26; // xmm11
  __m128 v27; // xmm11
  __m128 v28; // xmm12
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm10
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm9
  __m128 v36; // xmm8
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm1
  __m128 v57; // xmm15
  __m128 v58; // xmm15
  __m128 v59; // xmm8
  hkArray<hkVector4f,hkContainerHeapAllocator> *v60; // rbp
  __int64 v61; // rdi
  __int64 v62; // r13
  hkVector4f *v63; // rbp
  int *v64; // rbx
  __m128 v65; // xmm6
  __int64 v66; // rax
  __m128 v67; // xmm7
  __m128 v68; // xmm3
  __m128 v69; // xmm4
  __m128 v70; // xmm13
  __m128 v71; // xmm12
  __m128 v72; // xmm14
  __m128 v73; // xmm11
  __m128 v74; // xmm11
  __m128 v75; // xmm12
  __m128 v76; // xmm1
  __m128 v77; // xmm1
  __m128 v78; // xmm2
  __m128 v79; // xmm10
  __m128 v80; // xmm1
  __m128 v81; // xmm2
  __m128 v82; // xmm9
  __m128 v83; // xmm8
  __m128 v84; // xmm1
  __m128 v85; // xmm5
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm4
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm3
  __m128 v93; // xmm1
  __m128 v94; // xmm7
  __m128 v95; // xmm6
  __m128 v96; // xmm1
  __m128 v97; // xmm0
  __m128 v98; // xmm2
  __m128 v99; // xmm0
  __m128 v100; // xmm3
  __m128 v101; // xmm2
  __m128 v102; // xmm0
  __m128 v103; // xmm15
  __m128 v104; // xmm15
  char v105; // al
  hkVector4f epsilon; // [rsp+30h] [rbp-F8h]
  hkVector4f v2; // [rsp+40h] [rbp-E8h]
  hkVector4f v1; // [rsp+50h] [rbp-D8h]

  v3 = this;
  v4 = &this->m_segments->m_data[leafKey];
  v5 = this->m_wallClimbingPartition;
  if ( v5 < -1 || v4->m_partitionIdA == v5 || v4->m_partitionIdB == v5 )
  {
    v6 = this->m_proj;
    v7 = v4->m_indices.m_size - 1;
    if ( this->m_useIndices )
    {
      v8 = this->m_vertices;
      v9 = this->m_endIndex;
      v10 = this->m_startIndex;
      v11 = (__m128)_xmm;
      v12 = 0i64;
      v13 = v7;
      if ( v7 > 0 )
      {
        v14 = v4->m_indices.m_data;
        do
        {
          v15 = *v14;
          if ( (_DWORD)v10 != (_DWORD)v15 )
          {
            v16 = v14[1];
            if ( (_DWORD)v10 != (_DWORD)v16 && (_DWORD)v9 != (_DWORD)v15 && (_DWORD)v9 != (_DWORD)v16 )
            {
              v17 = v6->m_col1.m_quad;
              v18 = v6->m_col2.m_quad;
              v19 = v8->m_data[v10].m_quad;
              v20 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v6->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v8->m_data[v10].m_quad, v19, 85), v17)),
                      _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v18));
              v21 = v8->m_data[v9].m_quad;
              v22 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v6->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v8->m_data[v9].m_quad, v21, 85), v17)),
                      _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v18));
              v23 = v8->m_data[v15].m_quad;
              v24 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v6->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v8->m_data[v15].m_quad, v23, 85), v17)),
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v18));
              v25 = v8->m_data[v16].m_quad;
              v26 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v6->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v8->m_data[v16].m_quad, v25, 85), v17)),
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v18));
              if ( !(_mm_movemask_ps(
                       _mm_or_ps(
                         _mm_cmpltps(_mm_add_ps(_mm_max_ps(v20, v22), v11), _mm_min_ps(v24, v26)),
                         _mm_cmpltps(_mm_max_ps(v24, v26), _mm_sub_ps(_mm_min_ps(v20, v22), v11)))) & 3) )
              {
                v27 = _mm_sub_ps(v26, v24);
                v28 = _mm_sub_ps(v22, v20);
                v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 225), v28);
                if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85))) != 0.0 )
                {
                  v30 = _mm_mul_ps(v28, v27);
                  v31 = _mm_sub_ps(v24, v20);
                  v32 = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                          _mm_shuffle_ps(v30, v30, 170));
                  v33 = _mm_mul_ps(v28, v31);
                  v34 = _mm_mul_ps(v31, v27);
                  v35 = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                          _mm_shuffle_ps(v33, v33, 170));
                  v36 = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                          _mm_shuffle_ps(v34, v34, 170));
                  v37 = _mm_mul_ps(v28, v28);
                  v38 = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                          _mm_shuffle_ps(v37, v37, 170));
                  v39 = _mm_mul_ps(v27, v27);
                  v40 = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                          _mm_shuffle_ps(v39, v39, 170));
                  v41 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v40, v38), _mm_mul_ps(v32, v32)), *(__m128 *)&::epsilon);
                  v42 = _mm_rcp_ps(v41);
                  v43 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v41)), v42);
                  v44 = _mm_rcp_ps(v40);
                  v45 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v40)), v44);
                  v46 = _mm_rcp_ps(v38);
                  v47 = _mm_mul_ps(v46, v38);
                  v48 = _mm_cmpleps(v41, *(__m128 *)&::epsilon);
                  v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v47), v46);
                  v50 = _mm_sub_ps(_mm_mul_ps(v40, v35), _mm_mul_ps(v36, v32));
                  v51 = _mm_cmpltps(v50, v41);
                  v52 = _mm_sub_ps(
                          _mm_mul_ps(
                            _mm_or_ps(
                              _mm_andnot_ps(
                                v48,
                                _mm_mul_ps(
                                  _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v51, v41), _mm_and_ps(v51, v50))),
                                  v43)),
                              _mm_and_ps(v48, query.m_quad)),
                            _mm_mul_ps(v32, v45)),
                          _mm_mul_ps(v36, v45));
                  v53 = _mm_cmpltps(v52, query.m_quad);
                  v54 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v53, query.m_quad), _mm_and_ps(v53, v52)));
                  v55 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v32, v49), v54), _mm_mul_ps(v35, v49));
                  v56 = _mm_cmpltps(v55, query.m_quad);
                  v57 = _mm_sub_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_max_ps(
                                (__m128)0i64,
                                _mm_or_ps(_mm_andnot_ps(v56, query.m_quad), _mm_and_ps(v56, v55))),
                              v28),
                            v20),
                          _mm_add_ps(_mm_mul_ps(v54, v27), v24));
                  v58 = _mm_mul_ps(v57, v57);
                  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 170))) < 0.0000010000001 )
                    goto LABEL_27;
                  v11 = (__m128)_xmm;
                }
              }
            }
          }
          ++v12;
          ++v14;
        }
        while ( v12 < v13 );
      }
    }
    else
    {
      v59 = (__m128)_xmm;
      v60 = this->m_vertices;
      v61 = 0i64;
      v62 = v7;
      epsilon.m_quad = (__m128)_xmm;
      if ( v7 > 0 )
      {
        v63 = v60->m_data;
        v64 = v4->m_indices.m_data;
        do
        {
          v65 = v63[*v64].m_quad;
          v66 = v64[1];
          v1.m_quad = (__m128)v63[*v64];
          v67 = v63[v66].m_quad;
          v2.m_quad = (__m128)v63[v66];
          if ( (unsigned int)`anonymous namespace::_pointsAreDistinct(&v3->m_start, &v3->m_end, &v1, &v2, &epsilon) )
          {
            v68 = v6->m_col1.m_quad;
            v69 = v6->m_col2.m_quad;
            v70 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v3->m_start.m_quad, v3->m_start.m_quad, 0), v6->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v3->m_start.m_quad, v3->m_start.m_quad, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v3->m_start.m_quad, v3->m_start.m_quad, 170), v69));
            v71 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v3->m_end.m_quad, v3->m_end.m_quad, 0), v6->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v3->m_end.m_quad, v3->m_end.m_quad, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v3->m_end.m_quad, v3->m_end.m_quad, 170), v69));
            v72 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v6->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), v69));
            v73 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), v6->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v67, v67, 170), v69));
            if ( !(_mm_movemask_ps(
                     _mm_or_ps(
                       _mm_cmpltps(_mm_add_ps(_mm_max_ps(v70, v71), v59), _mm_min_ps(v72, v73)),
                       _mm_cmpltps(_mm_max_ps(v72, v73), _mm_sub_ps(_mm_min_ps(v70, v71), v59)))) & 3) )
            {
              v74 = _mm_sub_ps(v73, v72);
              v75 = _mm_sub_ps(v71, v70);
              v76 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 225), v75);
              if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 85))) != 0.0 )
              {
                v77 = _mm_mul_ps(v74, v75);
                v78 = _mm_sub_ps(v72, v70);
                v79 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                        _mm_shuffle_ps(v77, v77, 170));
                v80 = _mm_mul_ps(v78, v75);
                v81 = _mm_mul_ps(v78, v74);
                v82 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                        _mm_shuffle_ps(v80, v80, 170));
                v83 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                        _mm_shuffle_ps(v81, v81, 170));
                v84 = _mm_mul_ps(v75, v75);
                v85 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                        _mm_shuffle_ps(v84, v84, 170));
                v86 = _mm_mul_ps(v74, v74);
                v87 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
                        _mm_shuffle_ps(v86, v86, 170));
                v88 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v87, v85), _mm_mul_ps(v79, v79)), *(__m128 *)&::epsilon);
                v89 = _mm_rcp_ps(v88);
                v90 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v89, v88)), v89);
                v91 = _mm_rcp_ps(v87);
                v92 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v91, v87)), v91);
                v93 = _mm_rcp_ps(v85);
                v94 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v93, v85)), v93);
                v95 = _mm_sub_ps(_mm_mul_ps(v87, v82), _mm_mul_ps(v83, v79));
                v96 = _mm_cmpleps(v88, *(__m128 *)&::epsilon);
                v97 = _mm_cmpltps(v95, v88);
                v98 = _mm_sub_ps(
                        _mm_mul_ps(
                          _mm_or_ps(
                            _mm_andnot_ps(
                              v96,
                              _mm_mul_ps(
                                _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v95, v97), _mm_andnot_ps(v97, v88))),
                                v90)),
                            _mm_and_ps(v96, query.m_quad)),
                          _mm_mul_ps(v92, v79)),
                        _mm_mul_ps(v92, v83));
                v99 = _mm_cmpltps(v98, query.m_quad);
                v100 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v99, query.m_quad), _mm_and_ps(v98, v99)));
                v101 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v94, v79), v100), _mm_mul_ps(v94, v82));
                v102 = _mm_cmpltps(v101, query.m_quad);
                v103 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_andnot_ps(v102, query.m_quad), _mm_and_ps(v101, v102))),
                             v75),
                           v70),
                         _mm_add_ps(_mm_mul_ps(v100, v74), v72));
                v104 = _mm_mul_ps(v103, v103);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 170))) < 0.0000010000001 )
                {
LABEL_27:
                  v105 = 1;
                  goto LABEL_26;
                }
                v59 = (__m128)_xmm;
              }
            }
          }
          ++v61;
          ++v64;
        }
        while ( v61 < v62 );
      }
    }
  }
  v105 = 0;
LABEL_26:
  v3->m_intersects = v105;
  return v105 == 0;
}

// File Line: 1497
// RVA: 0xB51720
char __fastcall `anonymous namespace::doesLineSegmentIntersectPartition(int startIndex, int endIndex, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments)
{
  __int64 v4; // rbx
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v5; // rsi
  __m128 v6; // xmm2
  hkVector4f *v7; // r9
  __int64 v8; // rdi
  __int64 v9; // rax
  __m128 v10; // xmm0
  hkcdDynamicAabbTree *v11; // r12
  __m128 v12; // xmm5
  hkaiNavMeshSimplificationUtils::Segment *v13; // rcx
  signed __int64 v14; // rsi
  int *v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm13
  __m128 v22; // xmm1
  __m128 v23; // xmm12
  __m128 v24; // xmm1
  __m128 v25; // xmm14
  __m128 v26; // xmm1
  __m128 v27; // xmm11
  __m128 v28; // xmm11
  __m128 v29; // xmm12
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm10
  __m128 v34; // xmm1
  __m128 v35; // xmm9
  __m128 v36; // xmm1
  __m128 v37; // xmm8
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm7
  __m128 v51; // xmm6
  __m128 v52; // xmm0
  __m128 v53; // xmm3
  __m128 v54; // xmm1
  __m128 v55; // xmm2
  __m128 v56; // xmm10
  __m128 v57; // xmm1
  __m128 v58; // xmm15
  __m128 v59; // xmm15
  hkVector4f v61; // xmm0
  hkVector4f v62; // xmm0
  __m128 v63; // xmm1
  hkVector4f v64; // xmm1
  __int64 v65; // rax
  __int64 v66; // rax
  __m128 v67; // xmm6
  hkaiNavMeshSimplificationUtils::Segment *v68; // rcx
  __int64 v69; // rsi
  signed __int64 v70; // r14
  __int64 v71; // r10
  __int64 v72; // rax
  int *v73; // rdx
  __int64 v74; // r8
  __int64 v75; // rax
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm4
  __m128 v79; // xmm13
  __m128 v80; // xmm1
  __m128 v81; // xmm12
  __m128 v82; // xmm1
  __m128 v83; // xmm14
  __m128 v84; // xmm1
  __m128 v85; // xmm11
  __m128 v86; // xmm11
  __m128 v87; // xmm12
  __m128 v88; // xmm1
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm10
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm9
  __m128 v95; // xmm8
  __m128 v96; // xmm1
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  __m128 v99; // xmm6
  __m128 v100; // xmm4
  __m128 v101; // xmm1
  __m128 v102; // xmm3
  __m128 v103; // xmm1
  __m128 v104; // xmm5
  __m128 v105; // xmm1
  __m128 v106; // xmm0
  __m128 v107; // xmm2
  __m128 v108; // xmm7
  __m128 v109; // xmm6
  __m128 v110; // xmm0
  __m128 v111; // xmm3
  __m128 v112; // xmm1
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  __m128 v116; // xmm15
  __m128 v117; // xmm15
  __int64 v118; // r8
  __int64 v119; // r13
  signed int *v120; // r8
  __int64 v121; // r9
  signed int v122; // ecx
  __m128 v123; // xmm3
  __m128 v124; // xmm1
  __m128 v125; // xmm4
  __m128 v126; // xmm13
  __m128 v127; // xmm1
  __m128 v128; // xmm12
  __m128 v129; // xmm1
  __m128 v130; // xmm14
  __m128 v131; // xmm1
  __m128 v132; // xmm11
  __m128 v133; // xmm11
  __m128 v134; // xmm12
  __m128 v135; // xmm1
  __m128 v136; // xmm1
  __m128 v137; // xmm2
  __m128 v138; // xmm10
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm9
  __m128 v142; // xmm8
  __m128 v143; // xmm1
  __m128 v144; // xmm5
  __m128 v145; // xmm1
  __m128 v146; // xmm6
  __m128 v147; // xmm4
  __m128 v148; // xmm1
  __m128 v149; // xmm2
  __m128 v150; // xmm1
  __m128 v151; // xmm3
  __m128 v152; // xmm1
  __m128 v153; // xmm7
  __m128 v154; // xmm6
  __m128 v155; // xmm1
  __m128 v156; // xmm0
  __m128 v157; // xmm2
  __m128 v158; // xmm0
  __m128 v159; // xmm3
  __m128 v160; // xmm1
  __m128 v161; // xmm0
  __m128 v162; // xmm15
  __m128 v163; // xmm15
  __int64 v164; // [rsp+20h] [rbp-A8h]
  hkAabb aabb; // [rsp+30h] [rbp-98h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+50h] [rbp-78h]
  hkcdDynamicAabbTree *v167; // [rsp+58h] [rbp-70h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v168; // [rsp+60h] [rbp-68h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v169; // [rsp+68h] [rbp-60h]
  int v170; // [rsp+70h] [rbp-58h]
  __int64 v171; // [rsp+78h] [rbp-50h]
  hkAabb v172; // [rsp+88h] [rbp-40h]
  hkcdAabbTreeQueries::AabbCollector v173; // [rsp+A8h] [rbp-20h]
  hkcdDynamicAabbTree *v174; // [rsp+B0h] [rbp-18h]
  _QWORD *v175; // [rsp+B8h] [rbp-10h]
  _QWORD *v176; // [rsp+C0h] [rbp-8h]
  int v177; // [rsp+C8h] [rbp+0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v178; // [rsp+D0h] [rbp+8h]
  char v179; // [rsp+D8h] [rbp+10h]
  int v180; // [rsp+DCh] [rbp+14h]
  int v181; // [rsp+E0h] [rbp+18h]
  int v182; // [rsp+108h] [rbp+40h]
  char v183; // [rsp+10Ch] [rbp+44h]
  _QWORD *v184; // [rsp+208h] [rbp+140h]
  _QWORD *v185; // [rsp+210h] [rbp+148h]
  hkcdDynamicAabbTree *v186; // [rsp+218h] [rbp+150h]
  int vars0; // [rsp+220h] [rbp+158h]
  void *retaddr; // [rsp+228h] [rbp+160h]
  signed int v189; // [rsp+230h] [rbp+168h]
  __int64 v190; // [rsp+238h] [rbp+170h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v191; // [rsp+240h] [rbp+178h]

  v191 = vertices;
  v4 = startIndex;
  v5 = segments;
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         0);
  v7 = vertices->m_data;
  v8 = endIndex;
  if ( (_DWORD)retaddr == v189 )
  {
    LODWORD(v9) = (_DWORD)retaddr - 3;
    aabb.m_min.m_quad = _mm_min_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    v10 = _mm_max_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v6);
    aabb.m_max.m_quad = _mm_add_ps(v10, v6);
    if ( (signed int)retaddr < 3 )
      LODWORD(v9) = (_DWORD)retaddr;
    v11 = v186;
    v12 = (__m128)_xmm;
    v9 = (signed int)v9;
    v169 = v5;
    v168 = vertices;
    aabb.m_max.m_quad.m128_i32[v9] = 2139095022;
    aabb.m_min.m_quad.m128_i32[v9] = -8388626;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
    v167 = v11;
    v170 = (signed int)retaddr;
    v171 = v190;
    v13 = v5->m_data;
    v14 = 0i64;
    if ( v13[vars0].m_indices.m_size - 1 > 0 )
    {
      v15 = v13[vars0].m_indices.m_data;
      do
      {
        v16 = *v15;
        if ( (_DWORD)v4 != (_DWORD)v16 )
        {
          v17 = v15[1];
          if ( (_DWORD)v4 != (_DWORD)v17 && (_DWORD)v8 != (_DWORD)v16 && (_DWORD)v8 != (_DWORD)v17 )
          {
            v18 = v7[v4].m_quad;
            v19 = *(__m128 *)(v190 + 16);
            v20 = *(__m128 *)(v190 + 32);
            v21 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v4].m_quad, v18, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v20));
            v22 = v7[v8].m_quad;
            v23 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v8].m_quad, v22, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v20));
            v24 = v7[v16].m_quad;
            v25 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v16].m_quad, v24, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20));
            v26 = v7[v17].m_quad;
            v27 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v17].m_quad, v26, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v20));
            if ( !(_mm_movemask_ps(
                     _mm_or_ps(
                       _mm_cmpltps(_mm_add_ps(_mm_max_ps(v21, v23), v12), _mm_min_ps(v25, v27)),
                       _mm_cmpltps(_mm_max_ps(v25, v27), _mm_sub_ps(_mm_min_ps(v21, v23), v12)))) & 3) )
            {
              v28 = _mm_sub_ps(v27, v25);
              v29 = _mm_sub_ps(v23, v21);
              v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 225), v29);
              if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))) != 0.0 )
              {
                v31 = _mm_mul_ps(v28, v29);
                v32 = _mm_sub_ps(v25, v21);
                v33 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                        _mm_shuffle_ps(v31, v31, 170));
                v34 = _mm_mul_ps(v29, v32);
                v35 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                        _mm_shuffle_ps(v34, v34, 170));
                v36 = _mm_mul_ps(v28, v32);
                v37 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                        _mm_shuffle_ps(v36, v36, 170));
                v38 = _mm_mul_ps(v29, v29);
                v39 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                        _mm_shuffle_ps(v38, v38, 170));
                v40 = _mm_mul_ps(v28, v28);
                v41 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                        _mm_shuffle_ps(v40, v40, 170));
                v42 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v41, v39), _mm_mul_ps(v33, v33)), *(__m128 *)&epsilon);
                v43 = _mm_rcp_ps(v42);
                v44 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v42)), v43);
                v45 = _mm_rcp_ps(v41);
                v46 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v41)), v45);
                v47 = _mm_rcp_ps(v39);
                v48 = _mm_mul_ps(v47, v39);
                v49 = _mm_cmpleps(v42, *(__m128 *)&epsilon);
                v50 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v48), v47);
                v51 = _mm_sub_ps(_mm_mul_ps(v41, v35), _mm_mul_ps(v37, v33));
                v52 = _mm_cmpltps(v51, v42);
                v53 = _mm_sub_ps(
                        _mm_mul_ps(
                          _mm_or_ps(
                            _mm_andnot_ps(
                              v49,
                              _mm_mul_ps(
                                _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v52, v51), _mm_andnot_ps(v52, v42))),
                                v44)),
                            _mm_and_ps(v49, query.m_quad)),
                          _mm_mul_ps(v33, v46)),
                        _mm_mul_ps(v37, v46));
                v54 = _mm_cmpltps(v53, query.m_quad);
                v55 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v54, query.m_quad), _mm_and_ps(v54, v53)));
                v56 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v33, v50), v55), _mm_mul_ps(v35, v50));
                v57 = _mm_cmpltps(v56, query.m_quad);
                v58 = _mm_sub_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v57, query.m_quad), _mm_and_ps(v57, v56))),
                            v29),
                          v21),
                        _mm_add_ps(_mm_mul_ps(v28, v55), v25));
                v59 = _mm_mul_ps(v58, v58);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 170))) < 0.0000010000001 )
                  return 1;
                v12 = (__m128)_xmm;
              }
            }
          }
        }
        ++v14;
        ++v15;
      }
      while ( v14 < v13[vars0].m_indices.m_size - 1 );
    }
    aabb.m_max.m_quad.m128_i8[8] = 1;
    aabb.m_max.m_quad.m128_i32[3] = v4;
    LODWORD(collector.vfptr) = v8;
    BYTE4(v171) = 0;
    LODWORD(v171) = -2;
    hkcdDynamicAabbTree::queryAabb(v11, &aabb, &collector);
    if ( BYTE4(v171) )
      return 1;
  }
  else
  {
    v61.m_quad = _mm_min_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    aabb.m_min = (hkVector4f)v61.m_quad;
    v62.m_quad = _mm_sub_ps(v61.m_quad, v6);
    v63 = _mm_max_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    aabb.m_min = (hkVector4f)v62.m_quad;
    v64.m_quad = _mm_add_ps(v63, v6);
    aabb.m_max = (hkVector4f)v64.m_quad;
    if ( v189 != -1 )
    {
      v172.m_min = (hkVector4f)v62.m_quad;
      v172.m_max = (hkVector4f)v64.m_quad;
      LODWORD(v65) = v189 - 3;
      if ( v189 < 3 )
        LODWORD(v65) = v189;
      v65 = (signed int)v65;
      v172.m_max.m_quad.m128_i32[v65] = 2139095022;
      v172.m_min.m_quad.m128_i32[v65] = -8388626;
    }
    LODWORD(v66) = (_DWORD)retaddr - 3;
    if ( (signed int)retaddr < 3 )
      LODWORD(v66) = (_DWORD)retaddr;
    v67 = (__m128)_xmm;
    v66 = (signed int)v66;
    aabb.m_max.m_quad.m128_i32[v66] = 2139095022;
    aabb.m_min.m_quad.m128_i32[v66] = -8388626;
    v170 = (signed int)retaddr;
    v68 = v5->m_data;
    v169 = v5;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
    v168 = vertices;
    v167 = v186;
    v171 = v190;
    v69 = 0i64;
    v70 = 6i64 * vars0;
    v71 = 0i64;
    LODWORD(retaddr) = v68[vars0].m_partitionIdA;
    LODWORD(v72) = v68[vars0].m_indices.m_size - 1;
    v164 = (signed int)v72;
    if ( (signed int)v72 > 0 )
    {
      v73 = v68[vars0].m_indices.m_data;
      v72 = (signed int)v72;
      do
      {
        v74 = *v73;
        if ( (_DWORD)v4 != (_DWORD)v74 )
        {
          v75 = v73[1];
          if ( (_DWORD)v4 != (_DWORD)v75 && (_DWORD)v8 != (_DWORD)v74 && (_DWORD)v8 != (_DWORD)v75 )
          {
            v76 = v7[v4].m_quad;
            v77 = *(__m128 *)(v190 + 16);
            v78 = *(__m128 *)(v190 + 32);
            v79 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v4].m_quad, v76, 85), v77)),
                    _mm_mul_ps(_mm_shuffle_ps(v76, v76, 170), v78));
            v80 = v7[v8].m_quad;
            v81 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v8].m_quad, v80, 85), v77)),
                    _mm_mul_ps(_mm_shuffle_ps(v80, v80, 170), v78));
            v82 = v7[v74].m_quad;
            v83 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v74].m_quad, v82, 85), v77)),
                    _mm_mul_ps(_mm_shuffle_ps(v82, v82, 170), v78));
            v84 = v7[v75].m_quad;
            v85 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), *(__m128 *)v190),
                      _mm_mul_ps(_mm_shuffle_ps(v7[v75].m_quad, v84, 85), v77)),
                    _mm_mul_ps(_mm_shuffle_ps(v84, v84, 170), v78));
            if ( !(_mm_movemask_ps(
                     _mm_or_ps(
                       _mm_cmpltps(_mm_add_ps(_mm_max_ps(v79, v81), v67), _mm_min_ps(v83, v85)),
                       _mm_cmpltps(_mm_max_ps(v83, v85), _mm_sub_ps(_mm_min_ps(v79, v81), v67)))) & 3) )
            {
              v86 = _mm_sub_ps(v85, v83);
              v87 = _mm_sub_ps(v81, v79);
              v88 = _mm_mul_ps(_mm_shuffle_ps(v86, v86, 225), v87);
              if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85))) != 0.0 )
              {
                v89 = _mm_mul_ps(v86, v87);
                v90 = _mm_sub_ps(v83, v79);
                v91 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
                        _mm_shuffle_ps(v89, v89, 170));
                v92 = _mm_mul_ps(v90, v87);
                v93 = _mm_mul_ps(v90, v86);
                v94 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                        _mm_shuffle_ps(v92, v92, 170));
                v95 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                        _mm_shuffle_ps(v93, v93, 170));
                v96 = _mm_mul_ps(v87, v87);
                v97 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                        _mm_shuffle_ps(v96, v96, 170));
                v98 = _mm_mul_ps(v86, v86);
                v99 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
                        _mm_shuffle_ps(v98, v98, 170));
                v100 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v99, v97), _mm_mul_ps(v91, v91)), *(__m128 *)&epsilon);
                v101 = _mm_rcp_ps(v100);
                v102 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v101, v100)), v101);
                v103 = _mm_rcp_ps(v99);
                v104 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v103, v99)), v103);
                v105 = _mm_rcp_ps(v97);
                v106 = _mm_mul_ps(v105, v97);
                v107 = _mm_cmpleps(v100, *(__m128 *)&epsilon);
                v108 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v106), v105);
                v109 = _mm_sub_ps(_mm_mul_ps(v99, v94), _mm_mul_ps(v95, v91));
                v110 = _mm_cmpltps(v109, v100);
                v111 = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_or_ps(
                             _mm_andnot_ps(
                               v107,
                               _mm_mul_ps(
                                 _mm_max_ps(
                                   aabbOut.m_quad,
                                   _mm_or_ps(_mm_andnot_ps(v110, v100), _mm_and_ps(v110, v109))),
                                 v102)),
                             _mm_and_ps(v107, query.m_quad)),
                           _mm_mul_ps(v104, v91)),
                         _mm_mul_ps(v95, v104));
                v112 = _mm_cmpltps(v111, query.m_quad);
                v113 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v112, v111), _mm_andnot_ps(v112, query.m_quad)));
                v114 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v108, v91), v113), _mm_mul_ps(v94, v108));
                v115 = _mm_cmpltps(v114, query.m_quad);
                v116 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_and_ps(v115, v114), _mm_andnot_ps(v115, query.m_quad))),
                             v87),
                           v79),
                         _mm_add_ps(_mm_mul_ps(v113, v86), v83));
                v117 = _mm_mul_ps(v116, v116);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v117, v117, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v117, v117, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v117, v117, 170))) < 0.0000010000001 )
                  return 1;
                v67 = (__m128)_xmm;
              }
            }
          }
          v72 = v164;
        }
        ++v71;
        ++v73;
      }
      while ( v71 < v72 );
    }
    LODWORD(v171) = (_DWORD)retaddr;
    aabb.m_max.m_quad.m128_i8[8] = 1;
    aabb.m_max.m_quad.m128_i32[3] = v4;
    LODWORD(collector.vfptr) = v8;
    BYTE4(v171) = 0;
    hkcdDynamicAabbTree::queryAabb(v186, &aabb, &collector);
    if ( BYTE4(v171) )
      return 1;
    if ( v189 != -1 )
    {
      v177 = v189;
      v175 = v184;
      v178 = v191;
      v173.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
      v174 = v186;
      v118 = *v185;
      v176 = v185;
      LODWORD(retaddr) = *(_DWORD *)(v118 + 8 * v70 + 8);
      v119 = *(_DWORD *)(v118 + 8 * v70 + 40) - 1;
      if ( *(_DWORD *)(v118 + 8 * v70 + 40) - 1 > 0 )
      {
        v120 = *(signed int **)(v118 + 8 * v70 + 32);
        do
        {
          v121 = *v120;
          if ( (_DWORD)v4 != (_DWORD)v121 )
          {
            v122 = v120[1];
            if ( (_DWORD)v4 != v122 && (_DWORD)v8 != (_DWORD)v121 && (_DWORD)v8 != v122 )
            {
              v123 = (__m128)v191[1];
              v124 = *(__m128 *)(*v184 + 16 * v4);
              v125 = (__m128)v191[2];
              v126 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v124, v124, 85), v123),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(*v184 + 16 * v4), v124, 0), *(__m128 *)v191)),
                       _mm_mul_ps(_mm_shuffle_ps(v124, v124, 170), v125));
              v127 = *(__m128 *)(*v184 + 16 * v8);
              v128 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v127, v127, 0), *(__m128 *)v191),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(*v184 + 16 * v8), v127, 85), v123)),
                       _mm_mul_ps(_mm_shuffle_ps(v127, v127, 170), v125));
              v129 = *(__m128 *)(*v184 + 16 * v121);
              v130 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v129, v129, 0), *(__m128 *)v191),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(*v184 + 16 * v121), v129, 85), v123)),
                       _mm_mul_ps(_mm_shuffle_ps(v129, v129, 170), v125));
              v131 = *(__m128 *)(*v184 + 16i64 * v120[1]);
              v132 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v131, v131, 0), *(__m128 *)v191),
                         _mm_mul_ps(_mm_shuffle_ps(v131, v131, 85), v123)),
                       _mm_mul_ps(_mm_shuffle_ps(v131, v131, 170), v125));
              if ( !(_mm_movemask_ps(
                       _mm_or_ps(
                         _mm_cmpltps(_mm_add_ps(_mm_max_ps(v126, v128), v67), _mm_min_ps(v130, v132)),
                         _mm_cmpltps(_mm_max_ps(v130, v132), _mm_sub_ps(_mm_min_ps(v126, v128), v67)))) & 3) )
              {
                v133 = _mm_sub_ps(v132, v130);
                v134 = _mm_sub_ps(v128, v126);
                v135 = _mm_mul_ps(_mm_shuffle_ps(v133, v133, 225), v134);
                if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 85))) != 0.0 )
                {
                  v136 = _mm_mul_ps(v133, v134);
                  v137 = _mm_sub_ps(v130, v126);
                  v138 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                           _mm_shuffle_ps(v136, v136, 170));
                  v139 = _mm_mul_ps(v137, v134);
                  v140 = _mm_mul_ps(v137, v133);
                  v141 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
                           _mm_shuffle_ps(v139, v139, 170));
                  v142 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                           _mm_shuffle_ps(v140, v140, 170));
                  v143 = _mm_mul_ps(v134, v134);
                  v144 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                           _mm_shuffle_ps(v143, v143, 170));
                  v145 = _mm_mul_ps(v133, v133);
                  v146 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                           _mm_shuffle_ps(v145, v145, 170));
                  v147 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v146, v144), _mm_mul_ps(v138, v138)), *(__m128 *)&epsilon);
                  v148 = _mm_rcp_ps(v147);
                  v149 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v148, v147)), v148);
                  v150 = _mm_rcp_ps(v146);
                  v151 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v150, v146)), v150);
                  v152 = _mm_rcp_ps(v144);
                  v153 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v152, v144)), v152);
                  v154 = _mm_sub_ps(_mm_mul_ps(v146, v141), _mm_mul_ps(v142, v138));
                  v155 = _mm_cmpleps(v147, *(__m128 *)&epsilon);
                  v156 = _mm_cmpltps(v154, v147);
                  v157 = _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v155,
                                 _mm_mul_ps(
                                   _mm_max_ps(
                                     aabbOut.m_quad,
                                     _mm_or_ps(_mm_and_ps(v154, v156), _mm_andnot_ps(v156, v147))),
                                   v149)),
                               _mm_and_ps(v155, query.m_quad)),
                             _mm_mul_ps(v151, v138)),
                           _mm_mul_ps(v151, v142));
                  v158 = _mm_cmpltps(v157, query.m_quad);
                  v159 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v157, v158), _mm_andnot_ps(v158, query.m_quad)));
                  v160 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v153, v138), v159), _mm_mul_ps(v153, v141));
                  v161 = _mm_cmpltps(v160, query.m_quad);
                  v162 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_max_ps(
                                 (__m128)0i64,
                                 _mm_or_ps(_mm_and_ps(v160, v161), _mm_andnot_ps(v161, query.m_quad))),
                               v134),
                             v126),
                           _mm_add_ps(_mm_mul_ps(v159, v133), v130));
                  v163 = _mm_mul_ps(v162, v162);
                  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v163, v163, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v163, v163, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v163, v163, 170))) < 0.0000010000001 )
                    return 1;
                }
              }
            }
          }
          v67 = (__m128)_xmm;
          ++v69;
          ++v120;
        }
        while ( v69 < v119 );
      }
      v182 = (signed int)retaddr;
      v179 = 1;
      v180 = v4;
      v181 = v8;
      v183 = 0;
      hkcdDynamicAabbTree::queryAabb(v186, &v172, &v173);
      if ( v183 )
        return 1;
    }
  }
  return 0;
}v173);
      if ( v183 )
        return 1;
    }
  }
  return 0;
}

// File Line: 1557
// RVA: 0xB524F0
char __fastcall `anonymous namespace::doesLineSegmentIntersectPartition(hkVector4f *start, hkVector4f *end, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments)
{
  int v4; // edi
  __m128 v5; // xmm8
  hkVector4f *v6; // r14
  hkVector4f *v7; // rsi
  __m128 v8; // xmm2
  __m128 v9; // xmm15
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  __int64 v12; // rax
  __m128 v13; // xmm9
  __int64 v14; // rbx
  __int64 v15; // r13
  hkVector4f *v16; // r12
  int *v17; // rdi
  __m128 v18; // xmm6
  __int64 v19; // rax
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm13
  __m128 v24; // xmm12
  __m128 v25; // xmm14
  __m128 v26; // xmm11
  __m128 v27; // xmm11
  __m128 v28; // xmm12
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm10
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm9
  __m128 v36; // xmm8
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm3
  __int64 v60; // rax
  __int64 v61; // rax
  hkaiNavMeshSimplificationUtils::Segment *v62; // rdx
  hkVector4f v63; // xmm9
  __int64 v64; // rbx
  signed __int64 v65; // r13
  signed __int64 v66; // r15
  hkVector4f *v67; // rcx
  int *v68; // rdi
  __m128 v69; // xmm6
  __int64 v70; // rax
  __m128 v71; // xmm7
  __m128 v72; // xmm3
  __m128 v73; // xmm4
  __m128 v74; // xmm13
  __m128 v75; // xmm12
  __m128 v76; // xmm14
  __m128 v77; // xmm11
  __m128 v78; // xmm11
  __m128 v79; // xmm12
  __m128 v80; // xmm1
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm10
  __m128 v84; // xmm1
  __m128 v85; // xmm2
  __m128 v86; // xmm9
  __m128 v87; // xmm8
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm1
  __m128 v91; // xmm6
  __m128 v92; // xmm5
  __m128 v93; // xmm1
  __m128 v94; // xmm3
  __m128 v95; // xmm1
  __m128 v96; // xmm4
  __m128 v97; // xmm1
  __m128 v98; // xmm0
  __m128 v99; // xmm2
  __m128 v100; // xmm7
  __m128 v101; // xmm6
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128 v104; // xmm1
  __m128 v105; // xmm2
  __m128 v106; // xmm10
  __m128 v107; // xmm1
  __m128 v108; // xmm3
  __m128 v109; // xmm3
  hkcdDynamicAabbTree *v110; // r15
  __int64 v111; // rdi
  __int64 v112; // rax
  signed int *v113; // rdi
  __int64 v114; // r12
  __int64 v115; // r13
  __m128 v116; // xmm6
  __int64 v117; // rax
  __m128 v118; // xmm7
  __m128 v119; // xmm3
  __m128 v120; // xmm4
  __m128 v121; // xmm13
  __m128 v122; // xmm12
  __m128 v123; // xmm14
  __m128 v124; // xmm11
  __m128 v125; // xmm11
  __m128 v126; // xmm12
  __m128 v127; // xmm1
  __m128 v128; // xmm1
  __m128 v129; // xmm2
  __m128 v130; // xmm10
  __m128 v131; // xmm1
  __m128 v132; // xmm2
  __m128 v133; // xmm9
  __m128 v134; // xmm8
  __m128 v135; // xmm1
  __m128 v136; // xmm5
  __m128 v137; // xmm1
  __m128 v138; // xmm6
  __m128 v139; // xmm4
  __m128 v140; // xmm1
  __m128 v141; // xmm2
  __m128 v142; // xmm1
  __m128 v143; // xmm0
  __m128 v144; // xmm3
  __m128 v145; // xmm1
  __m128 v146; // xmm7
  __m128 v147; // xmm6
  __m128 v148; // xmm0
  __m128 v149; // xmm2
  __m128 v150; // xmm0
  __m128 v151; // xmm3
  __m128 v152; // xmm10
  __m128 v153; // xmm0
  __m128 v154; // xmm15
  __m128 v155; // xmm15
  __int128 v156; // xmm1
  hkVector4f epsilon; // [rsp+30h] [rbp-98h]
  hkVector4f v2; // [rsp+40h] [rbp-88h]
  hkAabb aabb; // [rsp+50h] [rbp-78h]
  hkcdAabbTreeQueries::AabbCollector collector[2]; // [rsp+70h] [rbp-58h]
  hkcdDynamicAabbTree *v161; // [rsp+80h] [rbp-48h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v162; // [rsp+88h] [rbp-40h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v163; // [rsp+90h] [rbp-38h]
  int v164; // [rsp+98h] [rbp-30h]
  __int64 v165; // [rsp+A0h] [rbp-28h]
  char v166; // [rsp+A8h] [rbp-20h]
  __m128 v167; // [rsp+B8h] [rbp-10h]
  __m128 v168; // [rsp+C8h] [rbp+0h]
  int v169; // [rsp+D8h] [rbp+10h]
  char v170; // [rsp+DCh] [rbp+14h]
  hkAabb v171; // [rsp+E8h] [rbp+20h]
  hkAabb v172; // [rsp+108h] [rbp+40h]
  hkcdAabbTreeQueries::AabbCollector v173; // [rsp+128h] [rbp+60h]
  hkcdDynamicAabbTree *v174; // [rsp+130h] [rbp+68h]
  _QWORD *v175; // [rsp+138h] [rbp+70h]
  _QWORD *v176; // [rsp+140h] [rbp+78h]
  int v177; // [rsp+148h] [rbp+80h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v178; // [rsp+150h] [rbp+88h]
  char v179; // [rsp+158h] [rbp+90h]
  hkVector4f v180; // [rsp+168h] [rbp+A0h]
  __int128 v181; // [rsp+178h] [rbp+B0h]
  int v182; // [rsp+188h] [rbp+C0h]
  char v183; // [rsp+18Ch] [rbp+C4h]
  _QWORD *v184; // [rsp+288h] [rbp+1C0h]
  _QWORD *v185; // [rsp+290h] [rbp+1C8h]
  hkcdDynamicAabbTree *v186; // [rsp+298h] [rbp+1D0h]
  int vars0; // [rsp+2A0h] [rbp+1D8h]
  void *retaddr; // [rsp+2A8h] [rbp+1E0h]
  signed int v189; // [rsp+2B0h] [rbp+1E8h]
  int v190; // [rsp+2B0h] [rbp+1E8h]
  __int64 v191; // [rsp+2B8h] [rbp+1F0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v192; // [rsp+2C0h] [rbp+1F8h]

  v192 = vertices;
  v4 = v189;
  v5 = end->m_quad;
  v6 = start;
  v7 = end;
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         0);
  v9 = start->m_quad;
  v10.m_quad = _mm_sub_ps(_mm_min_ps(start->m_quad, end->m_quad), v8);
  v11.m_quad = _mm_add_ps(_mm_max_ps(start->m_quad, end->m_quad), v8);
  if ( (_DWORD)retaddr == v189 )
  {
    v2.m_quad = end->m_quad;
    aabb.m_max = (hkVector4f)v11.m_quad;
    aabb.m_min = (hkVector4f)v10.m_quad;
    LODWORD(v12) = (_DWORD)retaddr - 3;
    if ( (signed int)retaddr < 3 )
      LODWORD(v12) = (_DWORD)retaddr;
    v13 = (__m128)_xmm;
    v12 = (signed int)v12;
    aabb.m_max.m_quad.m128_i32[v12] = 2139095022;
    aabb.m_min.m_quad.m128_i32[v12] = -8388626;
    epsilon.m_quad = (__m128)_xmm;
    collector[1].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
    v162 = vertices;
    v161 = v186;
    v163 = segments;
    v164 = (signed int)retaddr;
    v165 = v191;
    v14 = 0i64;
    v15 = segments->m_data[vars0].m_indices.m_size - 1;
    if ( segments->m_data[vars0].m_indices.m_size - 1 > 0 )
    {
      v16 = vertices->m_data;
      v17 = segments->m_data[vars0].m_indices.m_data;
      do
      {
        v18 = v16[*v17].m_quad;
        v19 = v17[1];
        *(hkVector4f *)((char *)&aabb.m_max + 8) = v16[*v17];
        v20 = v16[v19].m_quad;
        *(hkVector4f *)((char *)&v2 + 8) = v16[v19];
        if ( (unsigned int)`anonymous namespace::_pointsAreDistinct(
                             v6,
                             v7,
                             (hkVector4f *)((char *)&aabb.m_max + 8),
                             (hkVector4f *)((char *)&v2 + 8),
                             &epsilon) )
        {
          v21 = *(__m128 *)(v191 + 16);
          v22 = *(__m128 *)(v191 + 32);
          v23 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v22));
          v24 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v22));
          v25 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v22));
          v26 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v22));
          if ( !(_mm_movemask_ps(
                   _mm_or_ps(
                     _mm_cmpltps(_mm_add_ps(_mm_max_ps(v23, v24), v13), _mm_min_ps(v25, v26)),
                     _mm_cmpltps(_mm_max_ps(v25, v26), _mm_sub_ps(_mm_min_ps(v23, v24), v13)))) & 3) )
          {
            v27 = _mm_sub_ps(v26, v25);
            v28 = _mm_sub_ps(v24, v23);
            *(hkVector4f *)((char *)&aabb.m_min + 8) = 0i64;
            v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 225), v28);
            if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85))) != 0.0 )
            {
              v30 = _mm_mul_ps(v27, v28);
              v31 = _mm_sub_ps(v25, v23);
              v32 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                      _mm_shuffle_ps(v30, v30, 170));
              v33 = _mm_mul_ps(v31, v28);
              v34 = _mm_mul_ps(v31, v27);
              v35 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                      _mm_shuffle_ps(v33, v33, 170));
              v36 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                      _mm_shuffle_ps(v34, v34, 170));
              v37 = _mm_mul_ps(v28, v28);
              v38 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                      _mm_shuffle_ps(v37, v37, 170));
              v39 = _mm_mul_ps(v27, v27);
              v40 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                      _mm_shuffle_ps(v39, v39, 170));
              v41 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v40, v38), _mm_mul_ps(v32, v32)), *(__m128 *)&::epsilon);
              v42 = _mm_rcp_ps(v41);
              v43 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v41)), v42);
              v44 = _mm_rcp_ps(v40);
              v45 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v40)), v44);
              v46 = _mm_rcp_ps(v38);
              v47 = _mm_mul_ps(v46, v38);
              v48 = _mm_cmpleps(v41, *(__m128 *)&::epsilon);
              v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v47), v46);
              v50 = _mm_sub_ps(_mm_mul_ps(v40, v35), _mm_mul_ps(v36, v32));
              v51 = _mm_cmpltps(v50, v41);
              v52 = _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_or_ps(
                          _mm_andnot_ps(
                            v48,
                            _mm_mul_ps(
                              _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v51, v41), _mm_and_ps(v51, v50))),
                              v43)),
                          _mm_and_ps(v48, query.m_quad)),
                        _mm_mul_ps(v32, v45)),
                      _mm_mul_ps(v36, v45));
              v53 = _mm_cmpltps(v52, query.m_quad);
              v54 = _mm_max_ps(
                      *(__m128 *)((char *)&aabb.m_min.m_quad + 8),
                      _mm_or_ps(_mm_andnot_ps(v53, query.m_quad), _mm_and_ps(v53, v52)));
              v55 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v32, v49), v54), _mm_mul_ps(v35, v49));
              v56 = _mm_cmpltps(v55, query.m_quad);
              v57 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_max_ps(
                            *(__m128 *)((char *)&aabb.m_min.m_quad + 8),
                            _mm_or_ps(_mm_andnot_ps(v56, query.m_quad), _mm_and_ps(v56, v55))),
                          v28),
                        v23),
                      _mm_add_ps(_mm_mul_ps(v54, v27), v25));
              v58 = _mm_mul_ps(v57, v57);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 170))) < 0.0000010000001 )
                return 1;
              v5 = v2.m_quad;
              v13 = (__m128)_xmm;
            }
          }
        }
        ++v14;
        ++v17;
      }
      while ( v14 < v15 );
    }
    v167 = v9;
    v168 = v5;
    v166 = 0;
    v170 = 0;
    v169 = -2;
    hkcdDynamicAabbTree::queryAabb(v186, &aabb, &collector[1]);
    if ( v170 )
      return 1;
  }
  else
  {
    aabb.m_min = (hkVector4f)end->m_quad;
    v171.m_max = (hkVector4f)v11.m_quad;
    v171.m_min = (hkVector4f)v10.m_quad;
    if ( v189 != -1 )
    {
      v172.m_min = (hkVector4f)v10.m_quad;
      v172.m_max = (hkVector4f)v11.m_quad;
      LODWORD(v60) = v189 - 3;
      if ( v189 < 3 )
        LODWORD(v60) = v189;
      v60 = (signed int)v60;
      v172.m_max.m_quad.m128_i32[v60] = 2139095022;
      v172.m_min.m_quad.m128_i32[v60] = -8388626;
    }
    LODWORD(v61) = (_DWORD)retaddr - 3;
    if ( (signed int)retaddr < 3 )
      LODWORD(v61) = (_DWORD)retaddr;
    v62 = segments->m_data;
    v63.m_quad = (__m128)_xmm;
    v61 = (signed int)v61;
    v162 = vertices;
    v163 = segments;
    v2.m_quad = (__m128)_xmm;
    v171.m_max.m_quad.m128_i32[v61] = 2139095022;
    v171.m_min.m_quad.m128_i32[v61] = -8388626;
    collector[1].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
    v164 = (signed int)retaddr;
    v161 = v186;
    v165 = v191;
    v64 = 0i64;
    v65 = 6i64 * vars0;
    v66 = 0i64;
    LODWORD(retaddr) = v62[vars0].m_partitionIdA;
    v2.m_quad.m128_u64[1] = v62[vars0].m_indices.m_size - 1;
    if ( (signed __int64)v2.m_quad.m128_u64[1] > 0 )
    {
      v67 = vertices->m_data;
      v68 = v62[vars0].m_indices.m_data;
      epsilon.m_quad.m128_u64[0] = (unsigned __int64)vertices->m_data;
      do
      {
        v69 = v67[*v68].m_quad;
        v70 = v68[1];
        *(hkVector4f *)((char *)&aabb.m_max + 8) = v67[*v68];
        v71 = v67[v70].m_quad;
        *(hkVector4f *)((char *)&aabb.m_min + 8) = v67[v70];
        if ( (unsigned int)`anonymous namespace::_pointsAreDistinct(
                             v6,
                             v7,
                             (hkVector4f *)((char *)&aabb.m_max + 8),
                             (hkVector4f *)((char *)&aabb.m_min + 8),
                             &v2) )
        {
          v72 = *(__m128 *)(v191 + 16);
          v73 = *(__m128 *)(v191 + 32);
          v74 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v73));
          v75 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v73));
          v76 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v69, v69, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v69, v69, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v69, v69, 170), v73));
          v77 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), *(__m128 *)v191),
                    _mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v71, v71, 170), v73));
          if ( !(_mm_movemask_ps(
                   _mm_or_ps(
                     _mm_cmpltps(_mm_add_ps(_mm_max_ps(v74, v75), v63.m_quad), _mm_min_ps(v76, v77)),
                     _mm_cmpltps(_mm_max_ps(v76, v77), _mm_sub_ps(_mm_min_ps(v74, v75), v63.m_quad)))) & 3) )
          {
            v78 = _mm_sub_ps(v77, v76);
            v79 = _mm_sub_ps(v75, v74);
            *(_OWORD *)&collector[0].vfptr = 0i64;
            v80 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 225), v79);
            if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 85))) != 0.0 )
            {
              v81 = _mm_mul_ps(v78, v79);
              v82 = _mm_sub_ps(v76, v74);
              v83 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                      _mm_shuffle_ps(v81, v81, 170));
              v84 = _mm_mul_ps(v82, v79);
              v85 = _mm_mul_ps(v82, v78);
              v86 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                      _mm_shuffle_ps(v84, v84, 170));
              v87 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
                      _mm_shuffle_ps(v85, v85, 170));
              v88 = _mm_mul_ps(v79, v79);
              v89 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                      _mm_shuffle_ps(v88, v88, 170));
              v90 = _mm_mul_ps(v78, v78);
              v91 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                      _mm_shuffle_ps(v90, v90, 170));
              v92 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v91, v89), _mm_mul_ps(v83, v83)), *(__m128 *)&::epsilon);
              v93 = _mm_rcp_ps(v92);
              v94 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v93, v92)), v93);
              v95 = _mm_rcp_ps(v91);
              v96 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v95, v91)), v95);
              v97 = _mm_rcp_ps(v89);
              v98 = _mm_mul_ps(v97, v89);
              v99 = _mm_cmpleps(v92, *(__m128 *)&::epsilon);
              v100 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v98), v97);
              v101 = _mm_sub_ps(_mm_mul_ps(v91, v86), _mm_mul_ps(v87, v83));
              v102 = _mm_cmpltps(v101, v92);
              v103 = _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_or_ps(
                           _mm_andnot_ps(
                             v99,
                             _mm_mul_ps(
                               _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v102, v101), _mm_andnot_ps(v102, v92))),
                               v94)),
                           _mm_and_ps(v99, query.m_quad)),
                         _mm_mul_ps(v83, v96)),
                       _mm_mul_ps(v87, v96));
              v104 = _mm_cmpltps(v103, query.m_quad);
              v105 = _mm_max_ps(
                       *(__m128 *)&collector[0].vfptr,
                       _mm_or_ps(_mm_andnot_ps(v104, query.m_quad), _mm_and_ps(v104, v103)));
              v106 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v83, v100), v105), _mm_mul_ps(v86, v100));
              v107 = _mm_cmpltps(v106, query.m_quad);
              v108 = _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_max_ps(
                             *(__m128 *)&collector[0].vfptr,
                             _mm_or_ps(_mm_andnot_ps(v107, query.m_quad), _mm_and_ps(v107, v106))),
                           v79),
                         v74),
                       _mm_add_ps(_mm_mul_ps(v105, v78), v76));
              v109 = _mm_mul_ps(v108, v108);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 170))) < 0.0000010000001 )
                return 1;
              v5 = aabb.m_min.m_quad;
              v63.m_quad = (__m128)_xmm;
            }
          }
        }
        v67 = (hkVector4f *)epsilon.m_quad.m128_u64[0];
        ++v66;
        ++v68;
      }
      while ( v66 < (signed __int64)v2.m_quad.m128_u64[1] );
      v4 = v189;
    }
    v110 = v186;
    v167 = v9;
    v168 = v5;
    v166 = 0;
    v170 = 0;
    v169 = (signed int)retaddr;
    hkcdDynamicAabbTree::queryAabb(v186, &v171, &collector[1]);
    if ( v170 )
      return 1;
    if ( v4 != -1 )
    {
      v174 = v110;
      aabb.m_min = (hkVector4f)v63.m_quad;
      v177 = v4;
      v175 = v184;
      v173.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7PartitionIntersectionQuery__A0x257692e2_1_6B_;
      v178 = v192;
      v111 = *v185;
      v176 = v185;
      v190 = *(_DWORD *)(v111 + 8 * v65 + 8);
      v112 = *(_DWORD *)(v111 + 8 * v65 + 40) - 1;
      if ( v112 > 0 )
      {
        v113 = *(signed int **)(v111 + 8 * v65 + 32);
        v114 = *v184;
        v115 = v112;
        do
        {
          v116 = *(__m128 *)(v114 + 16i64 * *v113);
          v117 = v113[1];
          v2.m_quad = *(__m128 *)(v114 + 16i64 * *v113);
          v118 = *(__m128 *)(v114 + 16 * v117);
          *(_OWORD *)&collector[0].vfptr = *(_OWORD *)(v114 + 16 * v117);
          if ( (unsigned int)`anonymous namespace::_pointsAreDistinct(
                               v6,
                               v7,
                               &v2,
                               (hkVector4f *)collector,
                               &aabb.m_min) )
          {
            v119 = (__m128)v192[1];
            v120 = (__m128)v192[2];
            v121 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 0), *(__m128 *)v192),
                       _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 170), v120));
            v122 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v7->m_quad, v7->m_quad, 0), *(__m128 *)v192),
                       _mm_mul_ps(_mm_shuffle_ps(v7->m_quad, v7->m_quad, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v7->m_quad, v7->m_quad, 170), v120));
            v123 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 0), *(__m128 *)v192),
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v116, v116, 170), v120));
            v124 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v118, v118, 0), *(__m128 *)v192),
                       _mm_mul_ps(_mm_shuffle_ps(v118, v118, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v118, v118, 170), v120));
            if ( !(_mm_movemask_ps(
                     _mm_or_ps(
                       _mm_cmpltps(_mm_add_ps(_mm_max_ps(v121, v122), v63.m_quad), _mm_min_ps(v123, v124)),
                       _mm_cmpltps(_mm_max_ps(v123, v124), _mm_sub_ps(_mm_min_ps(v121, v122), v63.m_quad)))) & 3) )
            {
              v125 = _mm_sub_ps(v124, v123);
              v126 = _mm_sub_ps(v122, v121);
              v127 = _mm_mul_ps(_mm_shuffle_ps(v125, v125, 225), v126);
              if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v127, v127, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v127, v127, 85))) != 0.0 )
              {
                v128 = _mm_mul_ps(v125, v126);
                v129 = _mm_sub_ps(v123, v121);
                v130 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                         _mm_shuffle_ps(v128, v128, 170));
                v131 = _mm_mul_ps(v129, v126);
                v132 = _mm_mul_ps(v129, v125);
                v133 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                         _mm_shuffle_ps(v131, v131, 170));
                v134 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                         _mm_shuffle_ps(v132, v132, 170));
                v135 = _mm_mul_ps(v126, v126);
                v136 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
                         _mm_shuffle_ps(v135, v135, 170));
                v137 = _mm_mul_ps(v125, v125);
                v138 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v137, v137, 85), _mm_shuffle_ps(v137, v137, 0)),
                         _mm_shuffle_ps(v137, v137, 170));
                v139 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v138, v136), _mm_mul_ps(v130, v130)), *(__m128 *)&::epsilon);
                v140 = _mm_rcp_ps(v139);
                v141 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v139, v140)), v140);
                v142 = _mm_rcp_ps(v138);
                v143 = _mm_rcp_ps(v136);
                v144 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v138, v142)), v142);
                v145 = _mm_cmpleps(v139, *(__m128 *)&::epsilon);
                v146 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v143)), v143);
                v147 = _mm_sub_ps(_mm_mul_ps(v138, v133), _mm_mul_ps(v134, v130));
                v148 = _mm_cmpltps(v147, v139);
                v149 = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_or_ps(
                             _mm_andnot_ps(
                               v145,
                               _mm_mul_ps(
                                 _mm_max_ps(
                                   aabbOut.m_quad,
                                   _mm_or_ps(_mm_and_ps(v147, v148), _mm_andnot_ps(v148, v139))),
                                 v141)),
                             _mm_and_ps(v145, query.m_quad)),
                           _mm_mul_ps(v130, v144)),
                         _mm_mul_ps(v134, v144));
                v150 = _mm_cmpltps(v149, query.m_quad);
                v151 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v150, query.m_quad), _mm_and_ps(v149, v150)));
                v152 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v130, v146), v151), _mm_mul_ps(v133, v146));
                v153 = _mm_cmpltps(v152, query.m_quad);
                v154 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_andnot_ps(v153, query.m_quad), _mm_and_ps(v152, v153))),
                             v126),
                           v121),
                         _mm_add_ps(_mm_mul_ps(v151, v125), v123));
                v155 = _mm_mul_ps(v154, v154);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v155, v155, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v155, v155, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v155, v155, 170))) < 0.0000010000001 )
                  return 1;
                v63.m_quad = (__m128)_xmm;
              }
            }
          }
          ++v64;
          ++v113;
        }
        while ( v64 < v115 );
      }
      v156 = (__int128)v7->m_quad;
      v180.m_quad = v6->m_quad;
      v181 = v156;
      v182 = v190;
      v179 = 0;
      v183 = 0;
      hkcdDynamicAabbTree::queryAabb(v186, &v172, &v173);
      if ( v183 )
        return 1;
    }
  }
  return 0;
}72, &v173);
      if ( v183 )
        return 1;
    }
  }
  return 0;
}

// File Line: 1617
// RVA: 0xB532F0
hkSimdFloat32 *__fastcall `anonymous namespace::getClosestPointOnLine(hkSimdFloat32 *result, hkVector4f *p, hkVector4f *a, hkVector4f *b, int majorAxis, hkVector4f *out)
{
  __m128 v6; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm7
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  hkVector4f v18; // xmm4
  __m128 v19; // xmm4
  hkSimdFloat32 *v20; // rax
  __m128 v21; // xmm4

  v6 = b->m_quad;
  v7 = a->m_quad;
  v8 = p->m_quad;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      v9 = _mm_shuffle_ps(_mm_unpacklo_ps(v7, (__m128)0i64), v7, 228);
      v10 = _mm_shuffle_ps(_mm_unpacklo_ps(v6, (__m128)0i64), v6, 228);
      v11 = _mm_shuffle_ps(_mm_unpacklo_ps(v8, (__m128)0i64), v8, 228);
    }
    else
    {
      v9 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 180);
      v10 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, (__m128)0i64), 180);
      v11 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, (__m128)0i64), 180);
    }
  }
  else
  {
    v9 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v7, 4), 4);
    v10 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v6, 4), 4);
    v11 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v8, 4), 4);
  }
  v12 = _mm_sub_ps(v10, v9);
  v13 = _mm_mul_ps(_mm_sub_ps(v11, v9), v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(v12, v12);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rcp_ps(v16);
  v18.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpltps(
                       v16,
                       _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), v14)),
                   v12),
                 v9);
  *out = (hkVector4f)v18.m_quad;
  v19 = _mm_sub_ps(v18.m_quad, v11);
  v20 = result;
  v21 = _mm_mul_ps(v19, v19);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                     _mm_shuffle_ps(v21, v21, 170));
  return v20;
}

// File Line: 1653
// RVA: 0xB53440
hkSimdFloat32 *__fastcall `anonymous namespace::getHeightErrorSquared(hkSimdFloat32 *result, hkVector4f *p, hkVector4f *a, hkVector4f *b, int majorAxis)
{
  int v5; // ebx
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rsi
  hkVector4f *v8; // r14
  hkSimdFloat32 *v9; // rbp
  __m128 v10; // xmm5
  hkSimdFloat32 *v11; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm7
  hkVector4f out; // [rsp+30h] [rbp-38h]
  hkSimdFloat32 resulta; // [rsp+40h] [rbp-28h]

  v5 = majorAxis;
  v6 = b;
  v7 = a;
  v8 = p;
  v9 = result;
  if ( majorAxis >= 3 )
    v5 = majorAxis - 3;
  `anonymous namespace::getClosestPointOnLine(&resulta, p, a, b, v5, &out);
  v10 = _mm_sub_ps(v6->m_quad, v7->m_quad);
  out.m_quad.m128_i32[v5] = v8->m_quad.m128_i32[v5];
  v11 = v9;
  v12 = _mm_mul_ps(_mm_sub_ps(out.m_quad, v7->m_quad), v10);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_mul_ps(v10, v10);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rcp_ps(v15);
  v17 = _mm_sub_ps(
          out.m_quad,
          _mm_add_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpltps(
                  v15,
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v15)), v16), v13)),
              v10),
            v7->m_quad));
  v18 = _mm_mul_ps(v17, v17);
  v9->m_real = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                 _mm_shuffle_ps(v18, v18, 170));
  return v11;
}

// File Line: 1685
// RVA: 0xB53580
float __fastcall `anonymous namespace::computeAabb(hkArrayBase<hkVector2f> *points, hkVector2f *centerOut, hkVector2f *e0Out, hkVector2f *e1Out)
{
  signed __int64 v4; // r10
  float result; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  hkVector2f *v10; // rax
  signed __int64 v11; // rcx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm4_4

  v4 = points->m_size;
  if ( !(_DWORD)v4 )
    return 0.0;
  LODWORD(v6) = *(unsigned __int64 *)points->m_data >> 32;
  LODWORD(v7) = *points->m_data;
  LODWORD(v8) = *(unsigned __int64 *)points->m_data >> 32;
  LODWORD(v9) = *points->m_data;
  if ( v4 > 1 )
  {
    v10 = points->m_data + 1;
    v11 = v4 - 1;
    do
    {
      v12 = v10->x;
      v13 = v10->y;
      ++v10;
      v7 = fminf(v7, v12);
      v6 = fminf(v6, v13);
      v9 = fmaxf(v9, v12);
      v8 = fmaxf(v8, v13);
      --v11;
    }
    while ( v11 );
  }
  v14 = v8 - v6;
  v15 = v9 - v7;
  centerOut->y = (float)(v14 * 0.5) + v6;
  centerOut->x = (float)(v15 * 0.5) + v7;
  e0Out->y = 0.0;
  e0Out->x = v15 * 0.5;
  e1Out->x = 0.0;
  result = v14 * v15;
  e1Out->y = v14 * 0.5;
  return result;
}

// File Line: 1706
// RVA: 0xB536B0
char __fastcall `anonymous namespace::convertSegmentToObb(hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, int segmentIndex, int majorAxisA, int majorAxisB, hkcdDynamicAabbTree *tree, hkResult *resOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v8; // rdi
  hkaiNavMeshSimplificationUtils::Segment *v9; // r13
  signed __int64 v10; // rdx
  __int64 v11; // r14
  hkArray<int,hkContainerHeapAllocator> *v12; // rsi
  int *v14; // rbx
  int v15; // er15
  float v16; // xmm7_4
  int v17; // er12
  __m128 v18; // xmm6
  signed int v19; // er14
  __m128 v20; // xmm2
  __int64 v21; // rcx
  __int64 v22; // rax
  __m128 v23; // xmm0
  float v24; // xmm0_4
  signed __int64 v25; // rbx
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm7
  __m128 v30; // xmm1
  __m128 v31; // xmm13
  __m128 v32; // xmm4
  float v33; // xmm1_4
  __m128 v34; // xmm6
  __m128 v35; // xmm10
  __m128 v36; // xmm2
  __m128 v37; // xmm9
  __m128 v38; // xmm11
  __m128 v39; // xmm6
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm6
  __m128 v48; // xmm14
  int v49; // er9
  float v50; // eax
  hkResult *v51; // r13
  unsigned __int64 v52; // rbx
  int v53; // er8
  float v54; // xmm9_4
  __int64 v55; // rdx
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __int64 v59; // rcx
  __m128 v60; // xmm4
  __m128 v61; // xmm5
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm3
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm2
  float v68; // xmm1_4
  float v69; // xmm14_4
  float v70; // xmm0_4
  hkVector2f v71; // rcx
  hkVector2f v72; // rax
  __m128 v73; // xmm0
  __m128 v74; // xmm4
  __m128 v75; // xmm2
  __m128 v76; // xmm3
  __m128 v77; // xmm0
  __m128 v78; // xmm3
  __m128 v79; // xmm1
  __m128 v80; // xmm2
  __m128 v81; // xmm13
  __m128 v82; // xmm10
  __m128 v83; // xmm8
  __m128 v84; // xmm9
  float v85; // xmm12_4
  __m128 v86; // xmm4
  float v87; // xmm11_4
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm1
  __m128 v91; // xmm4
  int v92; // ebx
  int v93; // er9
  int v94; // eax
  int v95; // eax
  hkResultEnum v96; // eax
  __int64 v97; // rcx
  __m128 v98; // xmm0
  __int64 v99; // rax
  __int64 v100; // rcx
  signed __int64 v101; // rax
  char v102; // bl
  hkVector2f v103; // [rsp+50h] [rbp-B0h]
  hkVector2f e1Out; // [rsp+58h] [rbp-A8h]
  hkVector2f e0Out; // [rsp+60h] [rbp-A0h]
  void *array; // [rsp+68h] [rbp-98h]
  int v107; // [rsp+70h] [rbp-90h]
  int v108; // [rsp+74h] [rbp-8Ch]
  hkVector2f centerOut; // [rsp+78h] [rbp-88h]
  hkQuaternionf quat; // [rsp+80h] [rbp-80h]
  hkSimdFloat32 result; // [rsp+90h] [rbp-70h]
  hkVector4f planeOut; // [rsp+A0h] [rbp-60h]
  __int64 v113; // [rsp+B0h] [rbp-50h]
  hkArrayBase<hkVector4f> points; // [rsp+C0h] [rbp-40h]
  __m128 v115; // [rsp+D0h] [rbp-30h]
  hkVector4f end; // [rsp+E0h] [rbp-20h]
  hkVector4f v117; // [rsp+F0h] [rbp-10h]
  hkVector4f start; // [rsp+100h] [rbp+0h]
  hkVector4f v119; // [rsp+110h] [rbp+10h]
  hkVector4f v120; // [rsp+120h] [rbp+20h]
  hkVector4f v121; // [rsp+130h] [rbp+30h]
  hkVector4f v122; // [rsp+140h] [rbp+40h]
  hkVector4f direction; // [rsp+150h] [rbp+50h]
  hkRotationf v124; // [rsp+160h] [rbp+60h]
  hkRotationf projectionMatrix; // [rsp+190h] [rbp+90h]
  hkaiNavMeshSimplificationUtils::PlaneFitter v126; // [rsp+1C0h] [rbp+C0h]
  hkaiNavMeshGenerationSettings *v127; // [rsp+300h] [rbp+200h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments; // [rsp+310h] [rbp+210h]
  hkResult v129; // [rsp+318h] [rbp+218h]

  v129.m_enum = segmentIndex;
  segments = segmentsInOut;
  v127 = settings;
  v8 = verticesInOut;
  resOut->m_enum = 0;
  v9 = segmentsInOut->m_data;
  v10 = segmentIndex;
  v113 = v10 * 48;
  v11 = v9[v10].m_indices.m_size;
  v12 = (hkArray<int,hkContainerHeapAllocator> *)&v9[v10];
  if ( (signed int)v11 <= 5 )
    return 0;
  v14 = v12[2].m_data;
  if ( *v14 != v14[v11 - 1] || v9[v10].m_partitionIdB != -1 )
    return 0;
  v15 = majorAxisA;
  `anonymous namespace::computeSignedLoopArea(&result, v8, v12 + 2, majorAxisA);
  v16 = result.m_real.m128_f32[0];
  if ( result.m_real.m128_f32[0] <= 0.0 )
    return 0;
  v17 = majorAxisB;
  v18.m128_i32[0] = 0;
  if ( v15 != majorAxisB && majorAxisB != -1 )
  {
    v18 = `anonymous namespace::computeSignedLoopArea(&result, v8, v12 + 2, majorAxisB)->m_real;
    if ( v18.m128_f32[0] <= 0.0 )
      return 0;
  }
  v19 = v11 - 1;
  v20 = 0i64;
  if ( v19 > 0 )
  {
    v21 = v19;
    do
    {
      v22 = *v14;
      ++v14;
      v20 = _mm_add_ps(v20, v8->m_data[v22].m_quad);
      --v21;
    }
    while ( v21 );
  }
  v23 = 0i64;
  v23.m128_f32[0] = (float)v19;
  points.m_size = 1;
  points.m_data = (hkVector4f *)&v115;
  points.m_capacityAndFlags = -2147483647;
  v115 = _mm_mul_ps(_mm_div_ps(query.m_quad, _mm_shuffle_ps(v23, v23, 0)), v20);
  result.m_real.m128_u64[0] = (unsigned __int64)hkaiNavMeshGenerationSettings::getSimplificationSettings(
                                                  v127,
                                                  &points,
                                                  *(int *)((char *)&v9->m_materialSettingsIndex + v113));
  v24 = *(float *)(result.m_real.m128_u64[0] + 16);
  if ( v16 <= v24 && v18.m128_f32[0] <= v24 )
  {
    hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&v126);
    v25 = 0i64;
    if ( v19 > 0 )
    {
      do
        hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v126, &v8->m_data[v12[2].m_data[v25++]]);
      while ( v25 < v19 );
    }
    hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v126, (hkResult *)&v103, &planeOut);
    v26 = _mm_mul_ps(planeOut.m_quad, planeOut.m_quad);
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170));
    v28 = _mm_rsqrt_ps(v27);
    v29 = _mm_mul_ps(
            planeOut.m_quad,
            _mm_andnot_ps(
              _mm_cmpleps(v27, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                _mm_mul_ps(v28, *(__m128 *)_xmm))));
    planeOut.m_quad = v29;
    v30 = _mm_mul_ps(v29, stru_141A71280.m_quad);
    v31 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v29, v29, 255));
    v32 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v103.x = FLOAT_0_99998999;
    LODWORD(v33) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        0);
    if ( v32.m128_f32[0] <= v33 )
    {
      if ( v32.m128_f32[0] < (float)(0.0 - v33) )
      {
        hkQuaternionf::setFlippedRotation(&quat, &planeOut);
        v29 = planeOut.m_quad;
        v34 = quat.m_vec.m_quad;
        goto LABEL_27;
      }
      v35 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v32), (__m128)xmmword_141A711B0);
      v36 = _mm_rsqrt_ps(v35);
      v37 = _mm_andnot_ps(
              _mm_cmpleps(v35, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                _mm_mul_ps(v36, *(__m128 *)_xmm)));
      v38 = _mm_mul_ps(v37, (__m128)xmmword_141A711B0);
      v39 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v29),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), stru_141A71280.m_quad));
      v40 = _mm_shuffle_ps(v39, v39, 201);
      v103.x = FLOAT_N0_99900001;
      if ( v32.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0)) )
      {
        v41 = _mm_mul_ps(v40, v40);
        v42 = _mm_sub_ps(v35, v32);
        v43 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170));
        v44 = _mm_rsqrt_ps(v43);
        v45 = _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                _mm_mul_ps(v44, *(__m128 *)_xmm));
        v46 = _mm_rsqrt_ps(v42);
        v38 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v42, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v42), v46)),
                      _mm_mul_ps(v46, *(__m128 *)_xmm))),
                  v42),
                _mm_andnot_ps(_mm_cmpleps(v43, (__m128)0i64), v45));
      }
      v47 = _mm_mul_ps(v40, v38);
      v34 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, _mm_mul_ps(v37, v35)), 196);
    }
    else
    {
      v34 = qi.m_vec.m_quad;
    }
    quat.m_vec.m_quad = v34;
LABEL_27:
    v48 = 0i64;
    v108 = 2147483648;
    array = 0i64;
    v107 = 0;
    if ( v19 <= 0 )
    {
      v50 = 0.0;
    }
    else
    {
      v49 = v19;
      if ( v19 < 0 )
        v49 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&v103,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &array,
        v49,
        8);
      v50 = v103.x;
      v29 = planeOut.m_quad;
      v34 = quat.m_vec.m_quad;
      if ( LODWORD(v103.x) )
      {
        v19 = v107;
        goto LABEL_34;
      }
    }
    v107 = v19;
LABEL_34:
    v51 = resOut;
    *(float *)&resOut->m_enum = v50;
    if ( v50 == 0.0 )
    {
      v52 = result.m_real.m128_u64[0];
      v53 = 0;
      LODWORD(v54) = (unsigned __int128)_mm_shuffle_ps(
                                          (__m128)*(unsigned int *)(result.m_real.m128_u64[0] + 28),
                                          (__m128)*(unsigned int *)(result.m_real.m128_u64[0] + 28),
                                          0);
      if ( v19 <= 0 )
      {
LABEL_40:
        v66 = 0i64;
        v66.m128_f32[0] = (float)v19;
        centerOut = 0i64;
        e0Out = 0i64;
        v67 = _mm_shuffle_ps(v66, v66, 0);
        LODWORD(v68) = (unsigned __int128)_mm_rcp_ps(v67);
        e1Out = 0i64;
        v69 = v48.m128_f32[0] * (float)((float)(2.0 - (float)(v67.m128_f32[0] * v68)) * v68);
        v70 = hkVector2Util::computeObb((hkArrayBase<hkVector2f> *)&array, &centerOut, &e0Out, &e1Out, v51);
        if ( v51->m_enum == HK_SUCCESS )
        {
          resOut = 0i64;
          v103 = 0i64;
          result.m_real.m128_u64[0] = 0i64;
          if ( `anonymous namespace::computeAabb(
                 (hkArrayBase<hkVector2f> *)&array,
                 (hkVector2f *)&resOut,
                 &v103,
                 (hkVector2f *)&result) >= (float)(v70 * *(float *)(v52 + 20)) )
          {
            v72 = e0Out;
            v71 = e1Out;
          }
          else
          {
            v71 = (hkVector2f)result.m_real.m128_u64[0];
            centerOut = (hkVector2f)resOut;
            v72 = v103;
            e1Out = (hkVector2f)result.m_real.m128_u64[0];
            e0Out = v103;
          }
          v73 = _mm_mul_ps((__m128)*(unsigned __int64 *)&v72, (__m128)*(unsigned __int64 *)&v72);
          v74 = _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0));
          v75 = _mm_rsqrt_ps(v74);
          v76 = _mm_andnot_ps(
                  _mm_cmpleps(v74, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v74), v75)),
                    _mm_mul_ps(*(__m128 *)_xmm, v75)));
          resOut = (hkResult *)*(_OWORD *)&_mm_mul_ps((__m128)*(unsigned __int64 *)&v72, v76);
          if ( (float)(v76.m128_f32[0] * v74.m128_f32[0]) >= 0.00000011920929 )
          {
            v77 = _mm_mul_ps((__m128)*(unsigned __int64 *)&v71, (__m128)*(unsigned __int64 *)&v71);
            v78 = _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0));
            v79 = _mm_rsqrt_ps(v78);
            v80 = _mm_andnot_ps(
                    _mm_cmpleps(v78, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v79, v78), v79)),
                      _mm_mul_ps(v79, *(__m128 *)_xmm)));
            v103 = (hkVector2f)*(_OWORD *)&_mm_mul_ps((__m128)*(unsigned __int64 *)&v71, v80);
            if ( (float)(v80.m128_f32[0] * v78.m128_f32[0]) >= 0.00000011920929 )
            {
              v81 = (__m128)LODWORD(e0Out.x);
              v82 = (__m128)LODWORD(e0Out.y);
              v83 = (__m128)LODWORD(centerOut.y);
              v84 = (__m128)LODWORD(centerOut.x);
              v81.m128_f32[0] = e0Out.x + (float)(*(float *)&resOut * 0.0020000001);
              v85 = e1Out.x + (float)(v103.x * 0.0020000001);
              v82.m128_f32[0] = e0Out.y + (float)(*((float *)&resOut + 1) * 0.0020000001);
              v84.m128_f32[0] = centerOut.x - v81.m128_f32[0];
              v86 = v84;
              v87 = e1Out.y + (float)(v103.y * 0.0020000001);
              v86.m128_f32[0] = (float)(centerOut.x - v81.m128_f32[0]) + v85;
              v83.m128_f32[0] = centerOut.y - v82.m128_f32[0];
              v88 = v83;
              v88.m128_f32[0] = (float)(centerOut.y - v82.m128_f32[0]) + v87;
              e0Out.y = e0Out.y + (float)(*((float *)&resOut + 1) * 0.0020000001);
              v82.m128_f32[0] = v82.m128_f32[0] + centerOut.y;
              v89 = v88;
              v90 = v82;
              e0Out.x = e0Out.x + (float)(*(float *)&resOut * 0.0020000001);
              v81.m128_f32[0] = v81.m128_f32[0] + centerOut.x;
              v90.m128_f32[0] = v82.m128_f32[0] + v87;
              *(float *)&resOut = v69;
              v82.m128_f32[0] = v82.m128_f32[0] - v87;
              v84.m128_f32[0] = v84.m128_f32[0] - v85;
              v83.m128_f32[0] = v83.m128_f32[0] - v87;
              e1Out.x = e1Out.x + (float)(v103.x * 0.0020000001);
              direction.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(v86, (__m128)LODWORD(v69)),
                                   _mm_unpacklo_ps(v89, (__m128)0i64));
              v91 = v81;
              v91.m128_f32[0] = v81.m128_f32[0] + v85;
              v81.m128_f32[0] = v81.m128_f32[0] - v85;
              e1Out.y = e1Out.y + (float)(v103.y * 0.0020000001);
              v121.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(v91, (__m128)LODWORD(v69)),
                              _mm_unpacklo_ps(v90, (__m128)0i64));
              v120.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(v81, (__m128)LODWORD(v69)),
                              _mm_unpacklo_ps(v82, (__m128)0i64));
              v122.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(v84, (__m128)LODWORD(v69)),
                              _mm_unpacklo_ps(v83, (__m128)0i64));
              hkVector4f::setRotatedInverseDir(&start, &quat, &direction);
              hkVector4f::setRotatedInverseDir(&end, &quat, &v121);
              hkVector4f::setRotatedInverseDir(&v119, &quat, &v120);
              hkVector4f::setRotatedInverseDir(&v117, &quat, &v122);
              anonymous_namespace_::getProjectionMatrix(majorAxisA, &projectionMatrix);
              anonymous_namespace_::getProjectionMatrix(v17, &v124);
              if ( !`anonymous namespace::doesLineSegmentIntersectPartition(&start, &end, v8, segments)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(&end, &v119, v8, segments)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(&v119, &v117, v8, segments)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(&v117, &start, v8, segments) )
              {
                v92 = v8->m_size;
                v93 = v92 + 4;
                v94 = v8->m_capacityAndFlags & 0x3FFFFFFF;
                if ( v94 >= v92 + 4 )
                {
                  v96 = 0;
                }
                else
                {
                  v95 = 2 * v94;
                  if ( v93 < v95 )
                    v93 = v95;
                  hkArrayUtil::_reserve(
                    &v129,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v8,
                    v93,
                    16);
                  v96 = v129.m_enum;
                }
                v51->m_enum = v96;
                if ( v96 == HK_SUCCESS )
                {
                  v97 = v8->m_size;
                  v98 = start.m_quad;
                  v8->m_size = v97 + 4;
                  v99 = v97;
                  v100 = v113;
                  v101 = (signed __int64)&v8->m_data[v99];
                  *(__m128 *)v101 = v98;
                  *(hkVector4f *)(v101 + 16) = (hkVector4f)end.m_quad;
                  *(hkVector4f *)(v101 + 32) = (hkVector4f)v119.m_quad;
                  *(hkVector4f *)(v101 + 48) = (hkVector4f)v117.m_quad;
                  v12[2].m_size = 5;
                  *(int *)((char *)&segments->m_data->m_boundary.m_size + v100) = 4;
                  *v12[2].m_data = v92;
                  v12[2].m_data[1] = v92 + 1;
                  v12[2].m_data[2] = v92 + 2;
                  v12[2].m_data[3] = v92 + 3;
                  v12[2].m_data[4] = v92;
                  v102 = 1;
LABEL_58:
                  v107 = 0;
                  if ( v108 >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      array,
                      8 * v108);
                  array = 0i64;
                  v108 = 2147483648;
                  goto LABEL_62;
                }
              }
            }
          }
        }
      }
      else
      {
        v55 = 0i64;
        while ( 1 )
        {
          v56 = v8->m_data[v12[2].m_data[v55]].m_quad;
          v57 = _mm_mul_ps(v29, v56);
          v58 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                    _mm_shuffle_ps(v57, v57, 170)),
                  v31);
          if ( COERCE_FLOAT((unsigned int)(2 * v58.m128_i32[0]) >> 1) > v54 )
            break;
          v59 = v53++;
          ++v55;
          v60 = _mm_shuffle_ps(v34, v34, 255);
          v61 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v58), v29), v56);
          v62 = _mm_mul_ps(v34, v61);
          v63 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v34),
                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v61));
          v64 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                        _mm_shuffle_ps(v62, v62, 170)),
                      v34),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v60, v60), (__m128)xmmword_141A711B0), v61)),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v60));
          v65 = _mm_add_ps(v64, v64);
          *((_QWORD *)array + v59) = v65.m128_u64[0];
          v19 = v107;
          v48 = _mm_add_ps(v48, _mm_shuffle_ps(v65, v65, 170));
          if ( v53 >= v107 )
            goto LABEL_40;
          v29 = planeOut.m_quad;
          v34 = quat.m_vec.m_quad;
        }
      }
    }
    v102 = 0;
    goto LABEL_58;
  }
  v102 = 0;
LABEL_62:
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v102;
}dd_ps(v48, _mm_shuffle_ps(v65, v65, 170));
          if ( v53 >= v107 )
            goto LABEL_40;
          v29 = planeOut.m_quad;
          v34 = quat.m_vec.m_quad;
        }
      }
    }
    v102 = 0;
    goto LABEL_58;
  }
  v102 = 0;
LABEL_62:
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHea

// File Line: 1951
// RVA: 0xB54280
void __fastcall anonymous_namespace_::setPackXY(hkVector4f *vOut, hkVector4f *p1, hkVector4f *p2)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm3

  v3 = p2->m_quad;
  v4 = _mm_shuffle_ps(p1->m_quad, _mm_unpackhi_ps(p1->m_quad, _mm_shuffle_ps(v3, v3, 0)), 180);
  vOut->m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, _mm_shuffle_ps(v3, v3, 85)), 196);
}

// File Line: 1959
// RVA: 0xB542B0
void __fastcall anonymous_namespace_::unpackXY(hkVector4f *vIn, hkVector4f *p1, hkVector4f *p2)
{
  p1->m_quad = _mm_shuffle_ps(vIn->m_quad, vIn->m_quad, 68);
  p2->m_quad = _mm_shuffle_ps(vIn->m_quad, vIn->m_quad, 238);
}

// File Line: 1966
// RVA: 0xB542D0
hkResult *__fastcall anonymous_namespace_::gatherCorridorSegments(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkaiNavMeshSimplificationUtils::Segment *segment, hkRotationf *proj, int skipIndex, hkVector4f *va, hkVector4f *vb, hkVector4f *vap, hkVector4f *vbp, hkArray<hkVector4f,hkContainerTempAllocator> *testSegs)
{
  int v10; // esi
  hkaiNavMeshSimplificationUtils::Segment *v11; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v12; // r10
  hkResult *v13; // r13
  hkArray<hkVector4f,hkContainerTempAllocator> *v14; // rbx
  hkVector4f *v15; // r15
  hkVector4f *v16; // r12
  int v17; // er14
  __int64 v18; // rdi
  int *v19; // rax
  __int64 v20; // r8
  __int64 v21; // rdx
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  float v24; // xmm11_4
  float v25; // xmm10_4
  float v26; // xmm13_4
  float v27; // xmm14_4
  float v28; // xmm8_4
  float v29; // xmm15_4
  __m128 v30; // xmm6
  __m128 v31; // xmm7
  float v32; // xmm4_4
  BOOL v33; // edx
  float v34; // xmm0_4
  float v35; // xmm8_4
  BOOL v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm5_4
  BOOL v39; // eax
  int v40; // er9
  int v41; // eax
  int v42; // eax
  __m128 *v43; // rcx
  __m128 v44; // xmm6
  hkArray<hkVector4f,hkContainerHeapAllocator> *v46; // [rsp+128h] [rbp+10h]
  hkResult resulta; // [rsp+130h] [rbp+18h]
  hkRotationf *v48; // [rsp+138h] [rbp+20h]

  v48 = proj;
  v46 = vertices;
  v10 = 0;
  v11 = segment;
  v12 = vertices;
  v13 = result;
  if ( segment->m_indices.m_size - 1 <= 0 )
  {
LABEL_30:
    v13->m_enum = 0;
    return v13;
  }
  v14 = testSegs;
  v15 = vbp;
  v16 = vap;
  v17 = skipIndex;
  v18 = 0i64;
  while ( 1 )
  {
    v19 = v11->m_indices.m_data;
    v20 = v19[v18];
    if ( (_DWORD)v20 == v17 )
      goto LABEL_29;
    v21 = v19[v18 + 1];
    if ( (_DWORD)v21 == v17 )
      goto LABEL_29;
    v22 = v12->m_data[v20].m_quad;
    v23 = v12->m_data[v21].m_quad;
    v24 = va->m_quad.m128_f32[0];
    v25 = va->m_quad.m128_f32[1];
    v26 = vb->m_quad.m128_f32[0];
    v27 = vb->m_quad.m128_f32[1];
    v28 = vb->m_quad.m128_f32[0] - va->m_quad.m128_f32[0];
    v29 = vb->m_quad.m128_f32[1] - v25;
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), proj->m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v12->m_data[v20].m_quad, v22, 85), proj->m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), proj->m_col2.m_quad));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), proj->m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v12->m_data[v21].m_quad, v23, 85), proj->m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), proj->m_col2.m_quad));
    LODWORD(v32) = (unsigned __int128)_mm_shuffle_ps(v30, v30, 85);
    v33 = (float)((float)(v28 * (float)(v32 - v25)) - (float)((float)(v30.m128_f32[0] - va->m_quad.m128_f32[0]) * v29)) < 0.0
       && (float)((float)((float)(v31.m128_f32[1] - v25) * v28) - (float)((float)(v31.m128_f32[0] - v24) * v29)) < 0.0;
    v34 = v16->m_quad.m128_f32[0] - v24;
    v35 = v16->m_quad.m128_f32[1] - v25;
    v36 = (float)((float)((float)(v32 - v25) * v34) - (float)((float)(v30.m128_f32[0] - va->m_quad.m128_f32[0]) * v35)) > 0.0
       && (float)((float)((float)(v31.m128_f32[1] - v25) * v34) - (float)((float)(v31.m128_f32[0] - v24) * v35)) > 0.0;
    v37 = v15->m_quad.m128_f32[0] - v26;
    v38 = v15->m_quad.m128_f32[1] - v27;
    v39 = (float)((float)((float)(v32 - v27) * v37) - (float)((float)(v30.m128_f32[0] - v26) * v38)) < 0.0
       && (float)((float)((float)(v31.m128_f32[1] - v27) * v37) - (float)((float)(v31.m128_f32[0] - v26) * v38)) < 0.0;
    if ( v33 || v36 || v39 )
      goto LABEL_29;
    v40 = v14->m_size + 1;
    v41 = v14->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v41 < v40 )
      break;
    resulta.m_enum = 0;
LABEL_26:
    if ( v14->m_size == (v14->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v14, 16);
    proj = v48;
    v12 = v46;
    v43 = &v14->m_data[v14->m_size].m_quad;
    v44 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, _mm_shuffle_ps(v31, v31, 0)), 180);
    ++v14->m_size;
    *v43 = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, _mm_shuffle_ps(v31, v31, 85)), 196);
LABEL_29:
    ++v10;
    ++v18;
    if ( v10 >= v11->m_indices.m_size - 1 )
      goto LABEL_30;
  }
  v42 = 2 * v41;
  if ( v40 < v42 )
    v40 = v42;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v14, v40, 16);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_26;
  v13->m_enum = resulta.m_enum;
  return v13;
}

// File Line: 2046
// RVA: 0xB5A120
_BOOL8 __fastcall _processLeaf_CorridorIntersectionQuery__A0x257692e2_2_UEAAIIAEBVhkAabb___Z(CorridorIntersectionQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  CorridorIntersectionQuery *v3; // rbx
  hkResult *v4; // rax
  hkResultEnum v5; // ecx
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = this;
  v4 = anonymous_namespace_::gatherCorridorSegments(
         &result,
         this->m_vertices,
         &this->m_segments->m_data[leafKey],
         this->m_proj,
         this->m_skipIndex,
         &this->m_va,
         &this->m_vb,
         &this->m_vap,
         &this->m_vbp,
         this->m_testSegs);
  v5 = v4->m_enum;
  v3->m_res = (hkResult)v4->m_enum;
  return v5 == 0;
}

// File Line: 2070
// RVA: 0xB546A0
char __fastcall `anonymous namespace::collapseMakesCorridorImpassable(float minCorridorWidth, float maxCorridorWidth, hkVector4f *p0, hkVector4f *p1, hkVector4f *p2, hkVector4f *pa, hkVector4f *pb, int skipIndex, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, __int64 segmentIndex, int majorAxis, hkRotationf *projection, hkcdDynamicAabbTree *tree, hkResult *resOut)
{
  int *v15; // rdi
  float v16; // xmm9_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  __m128 v19; // xmm11
  __m128 v21; // xmm10
  __m128 v22; // xmm12
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> v36; // xmm2
  __m128 v37; // xmm14
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm7
  __m128 v41; // xmm12
  __m128 v42; // xmm4
  __m128 v43; // xmm4
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm8
  __int64 v47; // rax
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  __m128 v51; // xmm9
  __m128 v52; // xmm10
  int v53; // eax
  hkVector4f *v54; // r11
  char v55; // bl
  signed int v56; // er8
  signed int v57; // er9
  signed int v58; // ebx
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm6
  __m128 v64; // xmm5
  __m128 v65; // xmm4
  __m128 v66; // xmm12
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm14
  __m128 v70; // xmm1
  __m128i v71; // xmm3
  __m128 v72; // xmm14
  __m128 v73; // xmm9
  __m128 v74; // xmm10
  __m128 v75; // xmm12
  __m128 v76; // xmm7
  __m128 v77; // xmm4
  __m128 v78; // xmm2
  __m128 v79; // xmm2
  __m128 v80; // xmm2
  __m128 v81; // xmm1
  __m128 v82; // xmm5
  __m128 v83; // xmm3
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm6
  __m128 v89; // xmm0
  __m128 v90; // xmm0
  __m128 v91; // xmm6
  __m128 v92; // xmm0
  signed int v93; // ecx
  __m128 v94; // xmm4
  __m128 v95; // xmm2
  __m128 v96; // xmm1
  __m128 v97; // xmm1
  __m128 v98; // xmm1
  __m128 v99; // xmm5
  __m128 v100; // xmm0
  __m128 v101; // xmm3
  __m128 v102; // xmm1
  __m128 v103; // xmm3
  __m128 v104; // xmm6
  __m128 v105; // xmm6
  __m128 v106; // xmm0
  __m128 v107; // xmm0
  __m128 v108; // xmm6
  __m128 v109; // xmm0
  signed int v110; // eax
  __m128 v111; // xmm11
  __m128 v112; // xmm12
  hkVector4f *v113; // rcx
  __int64 v114; // rdx
  __m128 v115; // xmm8
  __m128 v116; // xmm6
  __m128 v117; // xmm5
  __m128 v118; // xmm8
  __m128 v119; // xmm2
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  __m128 v122; // xmm1
  __m128 v123; // xmm1
  __m128 v124; // xmm7
  __m128 v125; // xmm0
  __m128 v126; // xmm4
  __m128 v127; // xmm1
  __m128 v128; // xmm4
  __m128 v129; // xmm8
  __m128 v130; // xmm8
  __m128 v131; // xmm0
  __m128 v132; // xmm0
  __m128 v133; // xmm8
  __m128 v134; // xmm0
  __m128 v135; // xmm1
  __m128 v136; // xmm1
  __m128 v137; // xmm4
  __m128 v138; // xmm2
  __m128 v139; // xmm10
  __m128 v140; // xmm10
  __m128 v141; // xmm4
  __m128 v142; // xmm2
  hkArray<hkVector4f,hkContainerTempAllocator> testSegs; // [rsp+50h] [rbp-98h]
  float v144; // [rsp+60h] [rbp-88h]
  hkVector4f vb; // [rsp+68h] [rbp-80h]
  hkVector4f vbp; // [rsp+78h] [rbp-70h]
  hkVector4f va; // [rsp+88h] [rbp-60h]
  __m128 v148; // [rsp+98h] [rbp-50h]
  __m128 v149; // [rsp+A8h] [rbp-40h]
  __m128 v150; // [rsp+B8h] [rbp-30h]
  __m128 v151; // [rsp+C8h] [rbp-20h]
  hkAabb aabb; // [rsp+D8h] [rbp-10h]
  __m128 v153; // [rsp+F8h] [rbp+10h]
  __m128 v154; // [rsp+108h] [rbp+20h]
  __m128 v155; // [rsp+118h] [rbp+30h]
  __m128 v156; // [rsp+128h] [rbp+40h]
  __m128 v157; // [rsp+138h] [rbp+50h]
  __m128 v158; // [rsp+148h] [rbp+60h]
  __m128 v159; // [rsp+158h] [rbp+70h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+168h] [rbp+80h]
  hkcdDynamicAabbTree *v161; // [rsp+170h] [rbp+88h]
  hkVector4f *v162; // [rsp+178h] [rbp+90h]
  hkVector4f *v163; // [rsp+180h] [rbp+98h]
  int v164; // [rsp+188h] [rbp+A0h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v165; // [rsp+190h] [rbp+A8h]
  int v166; // [rsp+198h] [rbp+B0h]
  __m128 v167; // [rsp+1A8h] [rbp+C0h]
  __m128 v168; // [rsp+1B8h] [rbp+D0h]
  __m128 v169; // [rsp+1C8h] [rbp+E0h]
  __m128 v170; // [rsp+1D8h] [rbp+F0h]
  hkArray<hkVector4f,hkContainerTempAllocator> *v171; // [rsp+1E8h] [rbp+100h]
  int v172; // [rsp+1F0h] [rbp+108h]
  unsigned int v173; // [rsp+2B8h] [rbp+1D0h]
  unsigned int vars0; // [rsp+2C0h] [rbp+1D8h]
  __m128 *v175; // [rsp+2D8h] [rbp+1F0h]
  __m128 *v176; // [rsp+2E0h] [rbp+1F8h]
  __m128 *v177; // [rsp+2E8h] [rbp+200h]

  *(float *)&v175 = maxCorridorWidth;
  v15 = *(int **)&majorAxis;
  **(_DWORD **)&majorAxis = 0;
  v16 = maxCorridorWidth;
  v17 = (float)(minCorridorWidth + maxCorridorWidth) * 0.5;
  v144 = (float)(minCorridorWidth + maxCorridorWidth) * 0.5;
  v18 = v17 * 0.0099999998;
  *(float *)&majorAxis = v17 * 0.2;
  v19 = _mm_shuffle_ps((__m128)(unsigned int)majorAxis, (__m128)(unsigned int)majorAxis, 0);
  v151 = v19;
  if ( maxCorridorWidth <= 0.0 )
    return 0;
  v21 = p1->m_quad;
  v22 = *v175;
  v23 = _mm_sub_ps(p0->m_quad, *v175);
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_sub_ps(p0->m_quad, p1->m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v27 = _mm_mul_ps(v25, v23);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rcp_ps(v26);
  v30 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v26)), v29), v28);
  v31 = _mm_cmpltps(v30, query.m_quad);
  v32 = _mm_sub_ps(
          v25,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v30, v31), _mm_andnot_ps(v31, query.m_quad))), v23));
  v33 = _mm_mul_ps(v32, v32);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))) < (float)(v18 * v18) )
    return 0;
  v34 = (__m128)segments[2];
  v35 = (__m128)segments[1];
  v36 = *segments;
  v150 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 0), *(__m128 *)segments),
             _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 170), v34));
  v149 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), (__m128)v36),
             _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v34));
  v148 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), (__m128)v36),
             _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v34));
  v37 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(*v176, *v176, 0), (__m128)v36),
            _mm_mul_ps(_mm_shuffle_ps(*v176, *v176, 85), v35)),
          _mm_mul_ps(_mm_shuffle_ps(*v176, *v176, 170), v34));
  v38 = *v177;
  v39 = *v177;
  v155 = v37;
  va.m_quad = v37;
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v36),
            _mm_mul_ps(_mm_shuffle_ps(v39, v38, 85), v35)),
          _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v34));
  v41 = _mm_sub_ps(v40, v37);
  v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 225), (__m128)xmmword_141A71310);
  v43 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, (__m128)0i64), 180), 4),
                  4);
  v44 = _mm_mul_ps(v43, v43);
  v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 78), v44);
  v46 = (__m128)_xmm;
  *(float *)&majorAxis = v16 * 10.0;
  LODWORD(v47) = (_DWORD)vertices - 3;
  v48 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v45);
  v49 = _mm_rsqrt_ps(v48);
  v50 = _mm_shuffle_ps(
          (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
          (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
          0);
  v158 = _mm_mul_ps(
           _mm_mul_ps(
             _mm_andnot_ps(
               _mm_cmpleps(v48, (__m128)0i64),
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                 _mm_mul_ps(v49, *(__m128 *)_xmm))),
             v43),
           _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v16 * 10.0), (__m128)COERCE_UNSIGNED_INT(v16 * 10.0), 0));
  v51 = _mm_add_ps(v158, v37);
  v52 = _mm_add_ps(v158, v40);
  vb.m_quad = v51;
  vbp.m_quad = v52;
  aabb.m_max.m_quad = _mm_add_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(v37, v40), v51), v52), v50);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(_mm_min_ps(_mm_min_ps(v37, v40), v51), v52), v50);
  if ( (signed int)vertices < 3 )
    LODWORD(v47) = (_DWORD)vertices;
  v47 = (signed int)v47;
  v164 = (signed int)vertices;
  v163 = pb;
  aabb.m_max.m_quad.m128_i32[v47] = 2139095022;
  aabb.m_min.m_quad.m128_i32[v47] = -8388626;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)___7CorridorIntersectionQuery__A0x257692e2_1_6B_;
  testSegs.m_data = 0i64;
  v161 = (hkcdDynamicAabbTree *)segmentIndex;
  testSegs.m_size = 0;
  testSegs.m_capacityAndFlags = 2147483648;
  v162 = pa;
  v165 = segments;
  anonymous_namespace_::gatherCorridorSegments(
    (hkResult *)&majorAxis,
    (hkArray<hkVector4f,hkContainerHeapAllocator> *)pa,
    (hkaiNavMeshSimplificationUtils::Segment *)(pb->m_quad.m128_u64[0] + 48i64 * skipIndex),
    (hkRotationf *)segments,
    (int)p2,
    &va,
    (hkVector4f *)((char *)&vb + 8),
    &vb,
    &vbp,
    &testSegs);
  v53 = majorAxis;
  if ( *(float *)&majorAxis == 0.0 )
  {
    v167 = v37;
    v168 = v40;
    v169 = v51;
    v171 = &testSegs;
    v166 = (signed int)p2;
    v170 = v52;
    v172 = 0;
    hkcdDynamicAabbTree::queryAabb(v161, &aabb, &collector);
    v53 = v172;
  }
  v54 = testSegs.m_data;
  *v15 = v53;
  if ( v53 )
  {
    v55 = 0;
  }
  else
  {
    v56 = 0;
    v57 = -1;
    v58 = 0;
    v59 = _mm_mul_ps(v41, v41);
    v60 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
    v61 = _mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60);
    v62 = _mm_rsqrt_ps(v61);
    v63 = _mm_sub_ps(v149, v150);
    v154 = v63;
    v64 = _mm_shuffle_ps(v63, v63, 201);
    vbp.m_quad = v64;
    v65 = _mm_andnot_ps(
            _mm_cmpleps(v61, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v62, v61), v62)),
              _mm_mul_ps(v62, *(__m128 *)_xmm)));
    v66 = _mm_mul_ps(v41, v65);
    v67 = _mm_mul_ps(v65, v61);
    v156 = v66;
    v68 = _mm_cmpleps(v67, v19);
    v157 = v67;
    v69 = _mm_andnot_ps(v68, _mm_mul_ps(v19, (__m128)xmmword_141A711B0));
    v70 = _mm_and_ps(_mm_mul_ps(v67, (__m128)xmmword_141A711B0), v68);
    v71 = 0i64;
    v72 = _mm_or_ps(v69, v70);
    vb.m_quad = v72;
    v153 = _mm_shuffle_ps((__m128)v173, (__m128)v173, 0);
    v159 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
    v148 = _mm_sub_ps(v148, v149);
    *(hkVector4f *)((char *)&vb + 8) = (hkVector4f)_mm_shuffle_ps(v148, v148, 201);
    while ( 1 )
    {
      ++v58;
      v73 = 0i64;
      v74 = _mm_add_ps(_mm_mul_ps(v72, v66), v155);
      va.m_quad = v74;
      v75 = _mm_add_ps(v74, v158);
      v76 = _mm_sub_ps(_mm_sub_ps(v74, v158), v74);
      v77 = _mm_shuffle_ps(v76, v76, 201);
      v78 = _mm_sub_ps(_mm_mul_ps(v76, v64), _mm_mul_ps(v63, v77));
      v79 = _mm_shuffle_ps(v78, v78, 201);
      v80 = _mm_shuffle_ps(v79, v79, 170);
      v81 = _mm_rcp_ps(v80);
      v82 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeqps(v80, (__m128)0i64), v71);
      v83 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v81, v80));
      v84 = _mm_sub_ps(v74, v150);
      v85 = _mm_mul_ps(v83, v81);
      v86 = _mm_shuffle_ps(v84, v84, 201);
      v87 = _mm_sub_ps(_mm_mul_ps(v63, v86), _mm_mul_ps(v84, vbp.m_quad));
      v88 = _mm_shuffle_ps(v87, v87, 201);
      v89 = _mm_sub_ps(_mm_mul_ps(v76, v86), _mm_mul_ps(v84, v77));
      v90 = _mm_shuffle_ps(v89, v89, 201);
      v91 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 170), v85);
      v92 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 170), v85);
      if ( _mm_movemask_ps(
             _mm_and_ps(
               _mm_and_ps(
                 _mm_and_ps(_mm_cmpleps((__m128)0i64, v92), _mm_cmpleps(v92, query.m_quad)),
                 _mm_and_ps(_mm_cmpleps((__m128)0i64, v91), _mm_cmpleps(v91, query.m_quad))),
               v82)) & 1 )
      {
        v93 = 1;
        v73 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), v76), v74);
      }
      else
      {
        v93 = 0;
      }
      v94 = _mm_shuffle_ps(v76, v76, 201);
      v95 = _mm_sub_ps(v74, v149);
      v96 = _mm_sub_ps(_mm_mul_ps(v76, *(__m128 *)((char *)&vb.m_quad + 8)), _mm_mul_ps(v148, v94));
      v97 = _mm_shuffle_ps(v96, v96, 201);
      v98 = _mm_shuffle_ps(v97, v97, 170);
      v99 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeqps(v98, (__m128)0i64), (__m128i)0i64);
      v100 = _mm_rcp_ps(v98);
      v101 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v98, v100));
      v102 = _mm_shuffle_ps(v95, v95, 201);
      v103 = _mm_mul_ps(v101, v100);
      v104 = _mm_sub_ps(_mm_mul_ps(v148, v102), _mm_mul_ps(v95, *(__m128 *)((char *)&vb.m_quad + 8)));
      v105 = _mm_shuffle_ps(v104, v104, 201);
      v106 = _mm_sub_ps(_mm_mul_ps(v76, v102), _mm_mul_ps(v95, v94));
      v107 = _mm_shuffle_ps(v106, v106, 201);
      v108 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 170), v103);
      v109 = _mm_mul_ps(_mm_shuffle_ps(v107, v107, 170), v103);
      if ( _mm_movemask_ps(
             _mm_and_ps(
               _mm_and_ps(
                 _mm_and_ps(_mm_cmpleps((__m128)0i64, v109), _mm_cmpleps(v109, query.m_quad)),
                 _mm_and_ps(_mm_cmpleps((__m128)0i64, v108), _mm_cmpleps(v108, query.m_quad))),
               v99)) & 1 )
      {
        v110 = 1;
        v73 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v108, v108, 0), v76), v74);
      }
      else
      {
        v110 = 0;
      }
      if ( v93 | v110 )
      {
        v111 = (__m128)xmmword_141A712A0;
        if ( testSegs.m_size > 0 )
        {
          v112 = _mm_sub_ps(v75, v73);
          v113 = v54;
          v114 = (unsigned int)testSegs.m_size;
          do
          {
            v115 = v113->m_quad;
            v116 = _mm_shuffle_ps(v112, v112, 201);
            v117 = _mm_shuffle_ps(v115, v115, 68);
            v118 = _mm_sub_ps(_mm_shuffle_ps(v115, v115, 238), v117);
            v119 = _mm_sub_ps(v73, v117);
            v120 = _mm_shuffle_ps(v118, v118, 201);
            v121 = _mm_sub_ps(_mm_mul_ps(v112, v120), _mm_mul_ps(v118, v116));
            v122 = _mm_shuffle_ps(v121, v121, 201);
            v123 = _mm_shuffle_ps(v122, v122, 170);
            v124 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeqps(v123, (__m128)0i64), (__m128i)0i64);
            v125 = _mm_rcp_ps(v123);
            v126 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v123, v125));
            v127 = _mm_shuffle_ps(v119, v119, 201);
            v128 = _mm_mul_ps(v126, v125);
            v129 = _mm_sub_ps(_mm_mul_ps(v118, v127), _mm_mul_ps(v119, v120));
            v130 = _mm_shuffle_ps(v129, v129, 201);
            v131 = _mm_sub_ps(_mm_mul_ps(v112, v127), _mm_mul_ps(v119, v116));
            v132 = _mm_shuffle_ps(v131, v131, 201);
            v133 = _mm_mul_ps(_mm_shuffle_ps(v130, v130, 170), v128);
            v134 = _mm_mul_ps(_mm_shuffle_ps(v132, v132, 170), v128);
            if ( _mm_movemask_ps(
                   _mm_and_ps(
                     _mm_and_ps(
                       _mm_and_ps(_mm_cmpleps((__m128)0i64, v134), _mm_cmpleps(v134, query.m_quad)),
                       _mm_and_ps(_mm_cmpleps((__m128)0i64, v133), _mm_cmpleps(v133, query.m_quad))),
                     v124)) & 1 )
            {
              v135 = _mm_sub_ps(v73, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v133, v133, 0), v112), v73));
              v136 = _mm_mul_ps(v135, v135);
              v137 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                       _mm_shuffle_ps(v136, v136, 170));
              v138 = _mm_rsqrt_ps(v137);
              v111 = _mm_min_ps(
                       v111,
                       _mm_andnot_ps(
                         _mm_cmpleps(v137, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v137, v138), v138)),
                             _mm_mul_ps(v138, *(__m128 *)_xmm)),
                           v137)));
            }
            ++v113;
            --v114;
          }
          while ( v114 );
          v74 = va.m_quad;
          v72 = vb.m_quad;
          v46 = (__m128)_xmm;
        }
        if ( v111.m128_f32[0] < v153.m128_f32[0]
          || (v139 = _mm_sub_ps(v74, v73),
              v140 = _mm_mul_ps(v139, v139),
              v141 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                       _mm_shuffle_ps(v140, v140, 170)),
              v142 = _mm_rsqrt_ps(v141),
              (float)(v111.m128_f32[0]
                    - COERCE_FLOAT(
                        _mm_andnot_ps(
                          _mm_cmpleps(v141, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps(v46, _mm_mul_ps(_mm_mul_ps(v141, v142), v142)),
                              _mm_mul_ps(v142, *(__m128 *)_xmm)),
                            v141)))) > v159.m128_f32[0]) )
        {
          if ( v57 > v56 )
            v56 = v57;
          v57 = v56;
          v56 = 0;
        }
        else
        {
          ++v56;
        }
        v19 = v151;
      }
      v72 = _mm_add_ps(v72, v19);
      vb.m_quad = v72;
      if ( (float)((float)v57 * v19.m128_f32[0]) >= v144 )
        break;
      v63 = v154;
      v64 = vbp.m_quad;
      v71 = 0i64;
      v66 = v156;
      if ( v72.m128_f32[0] >= v157.m128_f32[0] )
      {
        if ( v57 > v56 )
          v56 = v57;
        if ( (float)((float)v56 * v19.m128_f32[0]) < v144 && (v58 > 2 || v56 <= 0) )
        {
          v55 = 0;
          goto LABEL_41;
        }
        break;
      }
    }
    v55 = 1;
  }
LABEL_41:
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  testSegs.m_size = 0;
  if ( testSegs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v54,
      16 * testSegs.m_capacityAndFlags);
  return v55;
}

// File Line: 2198
// RVA: 0xB55160
hkSimdFloat32 *__fastcall `anonymous namespace::getProjectedDistanceErrorSquared(hkSimdFloat32 *result, hkVector4f *a, hkVector4f *b, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<int,hkContainerHeapAllocator> *indices, int majorAxis)
{
  int v6; // edi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // r15
  hkVector4f *v8; // r12
  hkVector4f *v9; // r13
  hkSimdFloat32 *v10; // rbx
  __int64 v11; // rsi
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-48h]
  hkVector4f out; // [rsp+40h] [rbp-38h]

  v6 = 0;
  v7 = vertices;
  v8 = b;
  v9 = a;
  v10 = result;
  result->m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  if ( indices->m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      `anonymous namespace::getClosestPointOnLine(&resulta, &v7->m_data[indices->m_data[v11]], v9, v8, majorAxis, &out);
      ++v6;
      ++v11;
      v10->m_real = _mm_max_ps(v10->m_real, resulta.m_real);
    }
    while ( v6 < indices->m_size );
  }
  return v10;
}

// File Line: 2234
// RVA: 0xB55230
hkResult *__fastcall `anonymous namespace::simplifyInternalOrConvexBoundary(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArrayBase<int> *segmentToOppositeMap, int segmentIndex, int majorAxisA, int majorAxisB, hkcdDynamicAabbTree *tree, hkPointerMultiMap<int,int> *parToSegIdxMap, hkBitField *unremovableVertices)
{
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v11; // r13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v12; // r15
  hkResult *v13; // r10
  signed __int64 v14; // r11
  int v15; // edx
  _DWORD *v16; // r12
  int v17; // edi
  int v18; // ebx
  hkLifoAllocator *v19; // rax
  hkVector4f *v20; // r8
  int v21; // edx
  char *v22; // rcx
  unsigned int v23; // ecx
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // er8
  int v28; // er10
  __int64 v29; // r9
  int v30; // eax
  char *v31; // rdi
  int v32; // ebx
  hkResult *v33; // rsi
  unsigned int v34; // ecx
  bool v35; // zf
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // er8
  _DWORD *v39; // rdx
  __int64 v40; // rax
  int v41; // ecx
  hkaiNavMeshSimplificationUtils::Segment *v42; // rax
  __int64 v43; // rdi
  int v44; // eax
  char *v45; // rdi
  int v46; // ebx
  unsigned int v47; // ecx
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  __m128 v51; // xmm11
  __m128 v52; // xmm12
  int v53; // ebx
  int v54; // er9
  int v55; // er8
  __int64 v56; // rdx
  __int64 v57; // r9
  int v58; // er8
  int v59; // eax
  char *v60; // rdi
  signed int v61; // ebx
  hkLifoAllocator *v62; // rax
  int v63; // er8
  float v64; // xmm8_4
  float v65; // xmm10_4
  int v66; // ebx
  signed int v67; // esi
  int v68; // er9
  signed int v69; // er14
  signed __int64 v70; // rcx
  __int64 v71; // r8
  __int64 v72; // rdx
  int v73; // eax
  __int64 v74; // r12
  hkVector4f *v75; // rax
  hkVector4f *v76; // r15
  hkVector4f *v77; // r12
  hkVector4f *v78; // r13
  float v79; // xmm0_4
  float v80; // xmm6_4
  int v81; // er9
  hkgpCgo::ClusterData *v82; // rbx
  unsigned __int64 v83; // rdi
  __int64 v84; // rbx
  unsigned __int64 v85; // rdi
  float v86; // ebx
  int v87; // edi
  int v88; // eax
  int v89; // eax
  int v90; // er9
  unsigned __int64 v91; // r8
  __int64 v92; // rdx
  __int64 v93; // rax
  __int64 v94; // rcx
  __int64 v95; // rdx
  __int64 v96; // r15
  __int64 v97; // r13
  __int64 v98; // rsi
  signed int v99; // eax
  __int64 v100; // r12
  hkVector4f *v101; // rdi
  hkVector4f *v102; // r14
  hkVector4f *v103; // rdx
  __m128 v104; // xmm2
  __m128 v105; // xmm1
  __m128 v106; // xmm3
  __m128 v107; // xmm0
  __m128 v108; // xmm3
  bool v109; // al
  __m128 v110; // xmm0
  __m128 v111; // xmm0
  __m128 v112; // xmm1
  __int128 v113; // xmm1
  float v114; // xmm6_4
  __int128 v115; // xmm0
  hkaiNavMeshSimplificationUtils::Settings *v116; // rbx
  _DWORD *v117; // r9
  float v118; // ebx
  int v119; // edi
  int v120; // er9
  int v121; // er8
  __int64 v122; // rdx
  signed __int64 v123; // rcx
  int v124; // er10
  int v125; // edx
  __int64 v126; // rdx
  int v127; // eax
  _DWORD *v128; // rsi
  int v129; // eax
  __int64 v130; // rcx
  int v131; // eax
  int v132; // eax
  __int64 v133; // rdx
  int v134; // eax
  int v135; // ebx
  int v136; // er9
  int v137; // eax
  int v138; // eax
  float v139; // er8
  int v140; // eax
  int v141; // eax
  int v142; // er9
  __int64 v143; // r8
  int v144; // ecx
  float v145; // xmm2_4
  float v146; // xmm4_4
  float v147; // xmm3_4
  float v148; // xmm5_4
  signed __int64 v149; // rdx
  float v150; // xmm1_4
  int v151; // ST38_4
  hkVector4f *v152; // r13
  char v153; // al
  _DWORD *v154; // rbx
  int v155; // edx
  signed int v156; // edi
  signed __int64 v157; // r9
  int v158; // ecx
  signed __int64 v159; // rax
  signed int v160; // er14
  int v161; // ecx
  char *v162; // rax
  int v163; // ecx
  _DWORD *v164; // rax
  int v165; // edi
  signed __int64 v166; // rsi
  signed __int64 v167; // rdi
  signed __int64 v168; // rdi
  hkVector4f *v169; // rdi
  hkSimdFloat32 *v170; // rax
  __int64 v171; // rbx
  __int64 v172; // r10
  int v173; // edx
  __int64 v174; // r11
  hkaiNavMeshSimplificationUtils::Segment *v175; // rcx
  signed int v176; // eax
  __int64 v177; // rcx
  int v178; // eax
  int v179; // eax
  __int64 v180; // rdx
  int v181; // eax
  int v182; // ebx
  int v183; // eax
  int v184; // eax
  int v185; // eax
  signed __int64 v186; // rcx
  int v187; // edx
  __int64 v188; // rdx
  int v189; // eax
  __int64 v190; // r11
  hkaiNavMeshSimplificationUtils::Segment *v191; // rcx
  __int64 v192; // rax
  int v193; // eax
  int v194; // eax
  char *v195; // rdi
  signed int v196; // ebx
  hkLifoAllocator *v197; // rax
  int v198; // er8
  float v199; // er8
  int v200; // eax
  char *v201; // rdi
  signed int v202; // ebx
  hkLifoAllocator *v203; // rax
  int v204; // er8
  hkcdDynamicAabbTree *v205; // [rsp+20h] [rbp-E0h]
  hkSimdFloat32 *area1InOut; // [rsp+28h] [rbp-D8h]
  hkSimdFloat32 *area2InOut; // [rsp+30h] [rbp-D0h]
  hkSimdFloat32 *area1Out; // [rsp+38h] [rbp-C8h]
  hkRotationf *area2Out; // [rsp+40h] [rbp-C0h]
  hkRotationf *resOut; // [rsp+48h] [rbp-B8h]
  __int64 v211; // [rsp+50h] [rbp-B0h]
  char v212; // [rsp+80h] [rbp-80h]
  hkSimdFloat32 v213; // [rsp+90h] [rbp-70h]
  hkgpCgo::ClusterData *pArr; // [rsp+A0h] [rbp-60h]
  int v215; // [rsp+A8h] [rbp-58h]
  int v216; // [rsp+ACh] [rbp-54h]
  hkArray<int,hkContainerHeapAllocator> indices; // [rsp+B0h] [rbp-50h]
  char *array; // [rsp+C0h] [rbp-40h]
  int v219; // [rsp+C8h] [rbp-38h]
  int v220; // [rsp+CCh] [rbp-34h]
  hkArrayBase<hkVector4f> points; // [rsp+D0h] [rbp-30h]
  void *p; // [rsp+E0h] [rbp-20h]
  int v223; // [rsp+E8h] [rbp-18h]
  hkSimdFloat32 v224; // [rsp+F0h] [rbp-10h]
  bool v225; // [rsp+100h] [rbp+0h]
  bool v226; // [rsp+101h] [rbp+1h]
  int v227; // [rsp+104h] [rbp+4h]
  hkResult v228; // [rsp+108h] [rbp+8h]
  hkArrayBase<hkVector4f> v229; // [rsp+110h] [rbp+10h]
  __m128 v230; // [rsp+120h] [rbp+20h]
  __int128 v231; // [rsp+130h] [rbp+30h]
  __int128 v232; // [rsp+140h] [rbp+40h]
  hkVector4f *b; // [rsp+150h] [rbp+50h]
  void *v234; // [rsp+158h] [rbp+58h]
  __int64 v235; // [rsp+160h] [rbp+60h]
  hkResult resulta; // [rsp+168h] [rbp+68h]
  hkResult v237; // [rsp+16Ch] [rbp+6Ch]
  hkResult v238; // [rsp+170h] [rbp+70h]
  hkResult v239; // [rsp+174h] [rbp+74h]
  hkResult v240; // [rsp+178h] [rbp+78h]
  hkResult v241; // [rsp+17Ch] [rbp+7Ch]
  int v242; // [rsp+180h] [rbp+80h]
  hkResult v243; // [rsp+184h] [rbp+84h]
  unsigned __int64 v244; // [rsp+188h] [rbp+88h]
  __int64 v245; // [rsp+190h] [rbp+90h]
  int localSettingsIndex; // [rsp+198h] [rbp+98h]
  hkResult v247; // [rsp+19Ch] [rbp+9Ch]
  hkResult v248; // [rsp+1A0h] [rbp+A0h]
  hkaiNavMeshSimplificationUtils::Settings *v249; // [rsp+1A8h] [rbp+A8h]
  hkVector4f *a; // [rsp+1B0h] [rbp+B0h]
  hkaiNavMeshSimplificationUtils::Settings *v251; // [rsp+1B8h] [rbp+B8h]
  hkSimdFloat32 v252; // [rsp+1C0h] [rbp+C0h]
  hkSimdFloat32 v253; // [rsp+1D0h] [rbp+D0h]
  hkSimdFloat32 v254; // [rsp+1E0h] [rbp+E0h]
  hkRotationf projectionMatrix; // [rsp+1F0h] [rbp+F0h]
  hkSimdFloat32 v256; // [rsp+220h] [rbp+120h]
  hkSimdFloat32 v257; // [rsp+230h] [rbp+130h]
  hkSimdFloat32 v258; // [rsp+240h] [rbp+140h]
  hkRotationf projB; // [rsp+250h] [rbp+150h]
  hkResult *v260; // [rsp+340h] [rbp+240h]
  hkaiNavMeshGenerationSettings *v261; // [rsp+348h] [rbp+248h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *vertices; // [rsp+350h] [rbp+250h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments; // [rsp+358h] [rbp+258h]

  segments = segmentsInOut;
  vertices = verticesInOut;
  v261 = settings;
  v260 = result;
  v11 = segmentsInOut;
  v12 = verticesInOut;
  if ( majorAxisA == majorAxisB || (v212 = 1, majorAxisB == -1) )
    v212 = 0;
  anonymous_namespace_::getProjectionMatrix(majorAxisA, &projectionMatrix);
  anonymous_namespace_::getProjectionMatrix(majorAxisB, &projB);
  v14 = 48i64 * segmentIndex;
  v15 = 0;
  v16 = (_DWORD *)((char *)&v11->m_data->m_indices + v14);
  v244 = 48i64 * segmentIndex;
  v17 = v16[2];
  v234 = v16;
  points.m_data = 0i64;
  v18 = v17;
  points.m_size = 0;
  points.m_capacityAndFlags = 2147483648;
  v223 = v17;
  if ( v17 )
  {
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkVector4f *)v19->m_cur;
    v21 = (16 * v17 + 127) & 0xFFFFFF80;
    v22 = (char *)v20 + v21;
    if ( v21 > v19->m_slabSize || v22 > v19->m_end )
      v20 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
    else
      v19->m_cur = v22;
    v18 = v223;
    v15 = points.m_size;
    v13 = v260;
    v14 = v244;
    points.m_data = v20;
  }
  else
  {
    v20 = 0i64;
    points.m_data = 0i64;
  }
  p = v20;
  points.m_capacityAndFlags = v17 | 0x80000000;
  if ( !v20 )
  {
    v23 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v13->m_enum = 1;
    points.m_size = 0;
    v24 = (16 * v18 + 127) & 0xFFFFFF80;
    v25 = (hkLifoAllocator *)TlsGetValue(v23);
    v26 = (v24 + 15) & 0xFFFFFFF0;
    if ( v24 <= v25->m_slabSize && (void *)v26 == v25->m_cur && v25->m_firstNonLifoEnd )
      v25->m_cur = 0i64;
    else
      hkLifoAllocator::slowBlockFree(v25, 0i64, v26);
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    return v260;
  }
  v28 = 0;
  if ( v16[2] > 0 )
  {
    v29 = 0i64;
    while ( 1 )
    {
      ++v28;
      v29 += 4i64;
      v20[v15] = v12->m_data[*(signed int *)(*(_QWORD *)v16 + v29 - 4)];
      v15 = points.m_size++ + 1;
      if ( v28 >= v16[2] )
        break;
      v20 = points.m_data;
    }
  }
  localSettingsIndex = *(int *)((char *)&v11->m_data->m_materialSettingsIndex + v14);
  v251 = hkaiNavMeshGenerationSettings::getSimplificationSettings(v261, &points, localSettingsIndex);
  if ( v251->m_maxLoopShrinkFraction >= 1.0 )
  {
    v30 = points.m_size;
    v31 = (char *)p;
    v32 = v223;
    v33 = v260;
    v34 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v35 = p == points.m_data;
    v260->m_enum = 0;
    if ( v35 )
      v30 = 0;
    points.m_size = v30;
    v36 = (16 * v32 + 127) & 0xFFFFFF80;
    v37 = (hkLifoAllocator *)TlsGetValue(v34);
    v38 = (v36 + 15) & 0xFFFFFFF0;
    if ( v36 > v37->m_slabSize || &v31[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v31 )
      hkLifoAllocator::slowBlockFree(v37, v31, v38);
    else
      v37->m_cur = v31;
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    return v33;
  }
  v39 = *(_DWORD **)v16;
  v40 = (signed int)v16[2];
  v224.m_real = 0i64;
  v213.m_real = 0i64;
  v41 = v39[v40 - 1];
  v42 = v11->m_data;
  v226 = *v39 == v41;
  v225 = v42[v244 / 0x30].m_partitionIdB == -1;
  v43 = (signed int)`anonymous namespace::computePartialSignedPartitionAreas(
                      v12,
                      v11,
                      segmentToOppositeMap,
                      parToSegIdxMap,
                      segmentIndex,
                      majorAxisA,
                      majorAxisB,
                      &v224,
                      &v213,
                      &v228);
  if ( v228.m_enum )
  {
    v44 = points.m_size;
    v45 = (char *)p;
    v46 = v223;
    v35 = p == points.m_data;
    v33 = v260;
    v47 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v260->m_enum = 1;
    if ( v35 )
      v44 = 0;
    points.m_size = v44;
    v48 = (16 * v46 + 127) & 0xFFFFFF80;
    v49 = (hkLifoAllocator *)TlsGetValue(v47);
    v50 = (v48 + 15) & 0xFFFFFFF0;
    if ( v48 > v49->m_slabSize || &v45[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v45 )
      hkLifoAllocator::slowBlockFree(v49, v45, v50);
    else
      v49->m_cur = v45;
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    return v33;
  }
  v51 = v224.m_real;
  v52 = v213.m_real;
  _mm_store_si128((__m128i *)&v224, (__m128i)v224.m_real);
  _mm_store_si128((__m128i *)&v213, (__m128i)v52);
  `anonymous namespace::computeFullSignedPartitionAreas(v12, v11, segmentIndex, majorAxisA, majorAxisB, &v224, &v213);
  array = 0i64;
  v219 = 0;
  v220 = 2147483648;
  v53 = v16[2];
  if ( v53 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v54 = v16[2];
    if ( v53 < 0 )
      v54 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v54, 4);
    if ( resulta.m_enum )
    {
      v33 = v260;
      v260->m_enum = 1;
LABEL_60:
      v219 = 0;
      if ( v220 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v220);
      v59 = points.m_size;
      v60 = (char *)p;
      array = 0i64;
      if ( p == points.m_data )
        v59 = 0;
      v220 = 2147483648;
      points.m_size = v59;
      v61 = (16 * v223 + 127) & 0xFFFFFF80;
      v62 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v63 = (v61 + 15) & 0xFFFFFFF0;
      if ( v61 > v62->m_slabSize || &v60[v63] != v62->m_cur || v62->m_firstNonLifoEnd == v60 )
        hkLifoAllocator::slowBlockFree(v62, v60, v63);
      else
        v62->m_cur = v60;
      points.m_size = 0;
      if ( points.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          points.m_data,
          16 * points.m_capacityAndFlags);
      return v33;
    }
  }
  v219 = v53;
  v55 = 0;
  if ( v16[2] > 0 )
  {
    v56 = 0i64;
    do
    {
      ++v55;
      v56 += 4i64;
      *(_DWORD *)&array[v56 - 4] = *(_DWORD *)(v56 + *(_QWORD *)v16 - 4);
    }
    while ( v55 < v16[2] );
  }
  indices.m_data = 0i64;
  indices.m_size = 0;
  indices.m_capacityAndFlags = 2147483648;
  v57 = (unsigned int)v16[2];
  if ( (signed int)v57 <= 0 )
  {
    v239.m_enum = 0;
  }
  else
  {
    if ( (signed int)v57 < 0 )
      LODWORD(v57) = 0;
    hkArrayUtil::_reserve(&v239, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &indices, v57, 4);
    if ( v239.m_enum )
    {
      v33 = v260;
      v58 = indices.m_capacityAndFlags;
      indices.m_size = 0;
      v260->m_enum = 1;
      if ( v58 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * v58);
      indices.m_data = 0i64;
      indices.m_capacityAndFlags = 2147483648;
      goto LABEL_60;
    }
  }
  v64 = v213.m_real.m128_f32[0];
  v245 = v43;
  v65 = v224.m_real.m128_f32[0];
  while ( 2 )
  {
    if ( v226 && v16[2] < 4 )
      goto LABEL_354;
    v66 = v16[2] - (2 - (v226 != 0));
    v227 = v66;
    if ( v66 < 1 )
      goto LABEL_354;
    v213.m_real.m128_u64[0] = 0i64;
    v213.m_real.m128_u64[1] = 0x8000000000000000i64;
    pArr = 0i64;
    v67 = 0;
    v215 = 0;
    v216 = 2147483648;
    if ( v66 <= 0 )
    {
      v237.m_enum = 0;
    }
    else
    {
      v68 = v66;
      if ( v66 < 0 )
        v68 = 0;
      hkArrayUtil::_reserve(&v237, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v213, v68, 8);
      if ( v237.m_enum )
      {
        v33 = v260;
        v193 = v216;
        v215 = 0;
        v260->m_enum = 1;
        if ( v193 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            pArr,
            12 * (v193 & 0x3FFFFFFF));
        pArr = 0i64;
        v216 = 2147483648;
        v213.m_real.m128_i32[2] = 0;
        if ( v213.m_real.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            (void *)v213.m_real.m128_u64[0],
            8 * v213.m_real.m128_i32[3]);
        v213.m_real.m128_u64[0] = 0i64;
        v213.m_real.m128_i32[3] = 2147483648;
        indices.m_size = 0;
        if ( indices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            indices.m_data,
            4 * indices.m_capacityAndFlags);
        indices.m_data = 0i64;
        indices.m_capacityAndFlags = 2147483648;
        v219 = 0;
        if ( v220 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * v220);
        v194 = points.m_size;
        v195 = (char *)p;
        array = 0i64;
        if ( p == points.m_data )
          v194 = 0;
        v220 = 2147483648;
        points.m_size = v194;
        v196 = (16 * v223 + 127) & 0xFFFFFF80;
        v197 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v198 = (v196 + 15) & 0xFFFFFFF0;
        if ( v196 > v197->m_slabSize || &v195[v198] != v197->m_cur || v197->m_firstNonLifoEnd == v195 )
        {
          hkLifoAllocator::slowBlockFree(v197, v195, v198);
          points.m_size = 0;
        }
        else
        {
          v197->m_cur = v195;
          points.m_size = 0;
        }
        goto LABEL_369;
      }
      v67 = v215;
    }
    v69 = 1;
    if ( v66 >= 1 )
    {
      v70 = 2i64;
      v71 = 4i64;
      b = (hkVector4f *)2;
      v235 = 4i64;
      while ( 1 )
      {
        v72 = *(_QWORD *)v16;
        v73 = v16[2];
        v74 = *(signed int *)(v71 + *(_QWORD *)v16);
        v35 = v69 == v73 - 1;
        v75 = v12->m_data;
        if ( v35 )
          v70 = 1i64;
        v76 = &v75[*(signed int *)(v71 + v72 - 4)];
        v77 = &v75[v74];
        v78 = &v75[*(signed int *)(v72 + 4 * v70)];
        v79 = `anonymous namespace::getProjectedTriangleArea(v76, v77, v78, majorAxisA);
        v80 = v79;
        if ( v212 || v79 >= 0.001 )
        {
          if ( v213.m_real.m128_i32[2] == (v213.m_real.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v213, 8);
          v84 = v213.m_real.m128_i32[2];
          ++v213.m_real.m128_i32[2];
          v85 = v213.m_real.m128_u64[0];
          *(_DWORD *)(v213.m_real.m128_u64[0] + 8 * v84 + 4) = v69;
          if ( v212 )
            v80 = `anonymous namespace::getTriangleArea(v76, v77, v78);
          *(float *)(v85 + 8 * v84) = v80;
        }
        else
        {
          v81 = v67 + 1;
          if ( (v216 & 0x3FFFFFFF) >= v67 + 1 )
          {
            v238.m_enum = 0;
          }
          else
          {
            if ( v81 < 2 * (v216 & 0x3FFFFFFF) )
              v81 = 2 * (v216 & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v238, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, v81, 12);
            if ( v238.m_enum )
            {
              v33 = v260;
              v260->m_enum = 1;
LABEL_327:
              v215 = 0;
              if ( v216 >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  pArr,
                  12 * (v216 & 0x3FFFFFFF));
              pArr = 0i64;
              v216 = 2147483648;
              v213.m_real.m128_i32[2] = 0;
              if ( v213.m_real.m128_i32[3] >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  (void *)v213.m_real.m128_u64[0],
                  8 * v213.m_real.m128_i32[3]);
              indices.m_size = 0;
              v213.m_real.m128_i32[3] = 2147483648;
              v213.m_real.m128_u64[0] = 0i64;
              if ( indices.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  indices.m_data,
                  4 * indices.m_capacityAndFlags);
              indices.m_data = 0i64;
              indices.m_capacityAndFlags = 2147483648;
              v219 = 0;
              if ( v220 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  array,
                  4 * v220);
              array = 0i64;
              goto LABEL_360;
            }
            v67 = v215;
          }
          if ( v67 == (v216 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, 12);
            v67 = v215;
          }
          v82 = pArr;
          v83 = v67;
          v215 = v67 + 1;
          LODWORD(pArr[v83].m_errorRange[1]) = v69;
          *(float *)&v82[v83].m_numVertices = v79;
          v82[v83].m_errorRange[0] = `anonymous namespace::getTriangleArea(v76, v77, v78);
        }
        v67 = v215;
        v16 = v234;
        v71 = v235 + 4;
        v70 = (signed __int64)b->m_quad.m128_i64 + 1;
        ++v69;
        v235 += 4i64;
        b = (hkVector4f *)((char *)b + 1);
        if ( v69 > v227 )
          break;
        v12 = vertices;
      }
    }
    if ( v213.m_real.m128_i32[2] > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
        (DuplicateVertexRef *)v213.m_real.m128_u64[0],
        0,
        v213.m_real.m128_i32[2] - 1,
        0);
      v67 = v215;
    }
    if ( v67 )
    {
      if ( v67 > 1 )
      {
        hkAlgorithm::quickSortRecursive<hkgpCgo::ClusterData,hkAlgorithm::less<hkgpCgo::ClusterData>>(
          pArr,
          0,
          v67 - 1,
          0);
        v67 = v215;
      }
      v86 = v213.m_real.m128_f32[2];
      v87 = v67 + v213.m_real.m128_i32[2];
      v88 = v213.m_real.m128_i32[3] & 0x3FFFFFFF;
      if ( v67 + v213.m_real.m128_i32[2] > (v213.m_real.m128_i32[3] & 0x3FFFFFFF) )
      {
        if ( v88 >= v87 )
        {
          v247.m_enum = 0;
        }
        else
        {
          v89 = 2 * v88;
          v90 = v67 + v213.m_real.m128_i32[2];
          if ( v87 < v89 )
            v90 = v89;
          hkArrayUtil::_reserve(&v247, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v213, v90, 8);
        }
      }
      hkMemUtil::memMove(
        (void *)(v213.m_real.m128_u64[0] + 8i64 * v67),
        (const void *)v213.m_real.m128_u64[0],
        8 * LODWORD(v86));
      v213.m_real.m128_i32[2] = v87;
      v57 = 0i64;
      if ( v215 > 0 )
      {
        v91 = v213.m_real.m128_u64[0];
        v92 = 0i64;
        do
        {
          v57 = (unsigned int)(v57 + 1);
          ++v92;
          v91 += 8i64;
          *(_DWORD *)(v91 - 4) = *((_DWORD *)&pArr[v92] - 2);
          *(_DWORD *)(v91 - 8) = *((_DWORD *)&pArr[v92] - 1);
        }
        while ( (signed int)v57 < v215 );
      }
    }
    v93 = 0i64;
    v242 = 0;
    v235 = 0i64;
    if ( v213.m_real.m128_i32[2] <= 0 )
    {
LABEL_350:
      v215 = 0;
      if ( v216 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkgpCgo::ClusterData *, _QWORD, __int64, hkcdDynamicAabbTree *, hkSimdFloat32 *, hkSimdFloat32 *, hkSimdFloat32 *, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          12 * (v216 & 0x3FFFFFFFu),
          v57,
          v205,
          area1InOut,
          area2InOut,
          area1Out,
          area2Out,
          resOut);
      pArr = 0i64;
      v216 = 2147483648;
      v213.m_real.m128_i32[2] = 0;
      if ( v213.m_real.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, unsigned __int64, _QWORD, __int64, hkcdDynamicAabbTree *, hkSimdFloat32 *, hkSimdFloat32 *, hkSimdFloat32 *, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v213.m_real.m128_u64[0],
          (unsigned int)(8 * v213.m_real.m128_i32[3]),
          v57,
          v205,
          area1InOut,
          area2InOut,
          area1Out,
          area2Out,
          resOut);
LABEL_354:
      v33 = v260;
      v260->m_enum = 0;
      goto LABEL_355;
    }
    while ( 1 )
    {
      v94 = *(_QWORD *)v16;
      v95 = *(signed int *)(v213.m_real.m128_u64[0] + 8 * v93 + 4);
      v96 = *(signed int *)(*(_QWORD *)v16 + 4 * v95 - 4);
      v97 = *(signed int *)(*(_QWORD *)v16 + 4 * v95);
      v35 = (_DWORD)v95 == v16[2] - 1;
      v227 = *(_DWORD *)(v213.m_real.m128_u64[0] + 8 * v93 + 4);
      v98 = v95;
      v99 = 1;
      if ( !v35 )
        v99 = v95 + 1;
      v57 = v225;
      v100 = *(signed int *)(v94 + 4i64 * v99);
      if ( (!v225 || (_DWORD)v96 != (_DWORD)v100)
        && !((unremovableVertices->m_storage.m_words.m_data[v97 >> 5] >> (v97 & 0x1F)) & 1) )
      {
        v101 = &vertices->m_data[v96];
        v102 = &vertices->m_data[v97];
        v103 = &vertices->m_data[v100];
        a = &vertices->m_data[v96];
        b = v103;
        if ( !(_BYTE)v57 )
          goto LABEL_172;
        v104 = _mm_sub_ps(v103->m_quad, v102->m_quad);
        v105 = _mm_sub_ps(v103->m_quad, v101->m_quad);
        v106 = v105;
        if ( majorAxisA )
        {
          if ( majorAxisA == 1 )
          {
            v106 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 216), (__m128)xmmword_141A71320);
          }
          else if ( majorAxisA != 2 )
          {
            if ( majorAxisA == 3 )
            {
              v106 = _mm_shuffle_ps(v105, v105, 230);
            }
            else if ( majorAxisA == 4 )
            {
              v106 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 210), (__m128)xmmword_141A71320);
            }
            else
            {
              v106 = _mm_shuffle_ps(v105, v105, 225);
            }
          }
        }
        else
        {
          v106 = _mm_shuffle_ps(v105, v105, 233);
        }
        v107 = v104;
        if ( majorAxisA )
        {
          if ( majorAxisA == 1 )
          {
            v107 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 216), (__m128)xmmword_141A71320);
          }
          else if ( majorAxisA != 2 )
          {
            if ( majorAxisA == 3 )
            {
              v107 = _mm_shuffle_ps(v104, v104, 230);
            }
            else if ( majorAxisA == 4 )
            {
              v107 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 210), (__m128)xmmword_141A71320);
            }
            else
            {
              v107 = _mm_shuffle_ps(v104, v104, 225);
            }
          }
        }
        else
        {
          v107 = _mm_shuffle_ps(v104, v104, 233);
        }
        v108 = _mm_mul_ps(_mm_shuffle_ps(v106, v106, 225), v107);
        v108.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v108, v108, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v108, v108, 85));
        v109 = v108.m128_f32[0] <= 0.0;
        if ( v108.m128_f32[0] <= 0.0 )
          break;
      }
LABEL_297:
      v93 = v235 + 1;
      ++v242;
      ++v235;
      if ( v242 >= v213.m_real.m128_i32[2] )
        goto LABEL_350;
      v16 = v234;
    }
    v57 = (unsigned int)majorAxisB;
    if ( majorAxisA == majorAxisB || (_DWORD)v57 == -1 )
      goto LABEL_171;
    switch ( (_DWORD)v57 )
    {
      case 0:
        v110 = _mm_shuffle_ps(v105, v105, 233);
        goto LABEL_158;
      case 1:
        v105 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 216), (__m128)xmmword_141A71320);
        break;
      case 2:
        break;
      case 3:
        v110 = _mm_shuffle_ps(v105, v105, 230);
LABEL_158:
        v105 = v110;
        break;
      case 4:
        v105 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 210), (__m128)xmmword_141A71320);
        break;
      default:
        v105 = _mm_shuffle_ps(v105, v105, 225);
        break;
    }
    if ( !(_DWORD)v57 )
    {
      v111 = _mm_shuffle_ps(v104, v104, 233);
LABEL_169:
      v104 = v111;
      goto LABEL_170;
    }
    if ( (_DWORD)v57 == 1 )
    {
      v104 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 216), (__m128)xmmword_141A71320);
    }
    else if ( (_DWORD)v57 != 2 )
    {
      if ( (_DWORD)v57 != 3 )
      {
        if ( (_DWORD)v57 == 4 )
          v104 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 210), (__m128)xmmword_141A71320);
        else
          v104 = _mm_shuffle_ps(v104, v104, 225);
        goto LABEL_170;
      }
      v111 = _mm_shuffle_ps(v104, v104, 230);
      goto LABEL_169;
    }
LABEL_170:
    v112 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 225), v104);
    v109 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v112, v112, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v112, v112, 85))) <= 0.0;
LABEL_171:
    if ( !v109 )
      goto LABEL_297;
LABEL_172:
    v113 = (__int128)v102->m_quad;
    v114 = *(float *)(v213.m_real.m128_u64[0] + 8 * v235);
    v230 = v101->m_quad;
    v229.m_size = 3;
    v229.m_capacityAndFlags = -2147483645;
    v115 = (__int128)v103->m_quad;
    v231 = v113;
    v229.m_data = (hkVector4f *)&v230;
    v232 = v115;
    v116 = hkaiNavMeshGenerationSettings::getSimplificationSettings(v261, &v229, localSettingsIndex);
    v249 = v116;
    if ( v114 > v116->m_maxBorderSimplifyArea
      || COERCE_FLOAT(*`anonymous namespace::getHeightErrorSquared(&v254, v102, v101, b, majorAxisA)) > (float)(v116->m_maxBorderHeightError * v116->m_maxBorderHeightError)
      || v212
      && COERCE_FLOAT(*`anonymous namespace::getHeightErrorSquared(&v258, v102, v101, b, majorAxisB)) > (float)(v116->m_maxBorderHeightError * v116->m_maxBorderHeightError) )
    {
      goto LABEL_173;
    }
    resOut = &projB;
    area2Out = &projectionMatrix;
    LODWORD(area1Out) = majorAxisB;
    LODWORD(area2InOut) = majorAxisA;
    LODWORD(area1InOut) = segmentIndex;
    v205 = tree;
    if ( `anonymous namespace::doesLineSegmentIntersectPartition(v96, v100, vertices, segments) )
      goto LABEL_173;
    if ( v245 )
    {
      v117 = v234;
      v118 = -0.0;
      v119 = *((_DWORD *)v234 + 2);
      v224.m_real.m128_u64[0] = 0i64;
      v224.m_real.m128_u64[1] = 0x8000000000000000i64;
      if ( v119 <= 0 )
      {
        v241.m_enum = 0;
      }
      else
      {
        v120 = v119;
        if ( v119 < 0 )
          v120 = 0;
        hkArrayUtil::_reserve(&v241, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v224, v120, 4);
        if ( v241.m_enum )
        {
          v33 = v260;
          v199 = v224.m_real.m128_f32[3];
          v260->m_enum = 1;
          v224.m_real.m128_i32[2] = 0;
          if ( v199 >= 0.0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (void *)v224.m_real.m128_u64[0],
              4 * LODWORD(v199));
          v224.m_real.m128_u64[0] = 0i64;
          v224.m_real.m128_i32[3] = 2147483648;
          v229.m_size = 0;
          if ( v229.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v229.m_data,
              16 * v229.m_capacityAndFlags);
          v229.m_data = 0i64;
          v229.m_capacityAndFlags = 2147483648;
          v215 = 0;
          if ( v216 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              pArr,
              12 * (v216 & 0x3FFFFFFF));
          pArr = 0i64;
          v216 = 2147483648;
          v213.m_real.m128_i32[2] = 0;
          if ( v213.m_real.m128_i32[3] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (void *)v213.m_real.m128_u64[0],
              8 * v213.m_real.m128_i32[3]);
          v213.m_real.m128_u64[0] = 0i64;
          v213.m_real.m128_i32[3] = 2147483648;
          indices.m_size = 0;
          if ( indices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              indices.m_data,
              4 * indices.m_capacityAndFlags);
          indices.m_data = 0i64;
          indices.m_capacityAndFlags = 2147483648;
          v219 = 0;
          if ( v220 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              4 * v220);
          array = 0i64;
          v220 = 2147483648;
          goto LABEL_361;
        }
        v118 = v224.m_real.m128_f32[3];
        v117 = v234;
      }
      v224.m_real.m128_i32[2] = v119;
      v121 = 0;
      if ( v119 > 0 )
      {
        v122 = 0i64;
        do
        {
          ++v121;
          v122 += 4i64;
          *(_DWORD *)(v122 + v224.m_real.m128_u64[0] - 4) = *(_DWORD *)(v122 + *(_QWORD *)v117 - 4);
          v119 = v224.m_real.m128_i32[2];
        }
        while ( v121 < v224.m_real.m128_i32[2] );
        v118 = v224.m_real.m128_f32[3];
      }
      --v117[2];
      v123 = *(_QWORD *)v117 + 4 * v98;
      v124 = v98;
      v125 = 4 * (v117[2] - v98);
      if ( v125 > 0 )
      {
        v126 = ((unsigned int)(v125 - 1) >> 2) + 1;
        do
        {
          v127 = *(_DWORD *)(v123 + 4);
          v123 += 4i64;
          *(_DWORD *)(v123 - 4) = v127;
          --v126;
        }
        while ( v126 );
        v118 = v224.m_real.m128_f32[3];
        v119 = v224.m_real.m128_i32[2];
      }
      v128 = v234;
      v129 = *((_DWORD *)v234 + 2);
      if ( v124 == v129 )
      {
        v130 = *(_QWORD *)v234;
        v131 = v129 - 1;
        *((_DWORD *)v234 + 2) = v131;
        v132 = 4 * v131;
        if ( v132 > 0 )
        {
          v133 = ((unsigned int)(v132 - 1) >> 2) + 1;
          do
          {
            v134 = *(_DWORD *)(v130 + 4);
            v130 += 4i64;
            *(_DWORD *)(v130 - 4) = v134;
            --v133;
          }
          while ( v133 );
        }
        v135 = **(_DWORD **)v128;
        v136 = v128[2] + 1;
        v137 = v128[3] & 0x3FFFFFFF;
        if ( v137 >= v136 )
        {
          v243.m_enum = 0;
        }
        else
        {
          v138 = 2 * v137;
          if ( v136 < v138 )
            v136 = v138;
          hkArrayUtil::_reserve(&v243, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v128, v136, 4);
          if ( v243.m_enum )
          {
LABEL_202:
            v139 = v224.m_real.m128_f32[3];
            v33 = v260;
            v260->m_enum = 1;
            v224.m_real.m128_i32[2] = 0;
            if ( v139 >= 0.0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                (void *)v224.m_real.m128_u64[0],
                4 * LODWORD(v139));
            v224.m_real.m128_u64[0] = 0i64;
            v224.m_real.m128_i32[3] = 2147483648;
            goto LABEL_205;
          }
        }
        *(_DWORD *)(*(_QWORD *)v128 + 4i64 * (signed int)v128[2]++) = v135;
        v118 = v224.m_real.m128_f32[3];
        v119 = v224.m_real.m128_i32[2];
      }
      _mm_store_si128((__m128i *)&v253, (__m128i)v51);
      _mm_store_si128((__m128i *)&v252, (__m128i)v52);
      `anonymous namespace::computeFullSignedPartitionAreas(
        vertices,
        segments,
        segmentIndex,
        majorAxisA,
        majorAxisB,
        &v253,
        &v252);
      v140 = v128[3] & 0x3FFFFFFF;
      if ( v140 >= v119 )
      {
        v240.m_enum = 0;
      }
      else
      {
        v141 = 2 * v140;
        v142 = v119;
        if ( v119 < v141 )
          v142 = v141;
        hkArrayUtil::_reserve(&v240, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v128, v142, 4);
        if ( v240.m_enum )
          goto LABEL_202;
        v118 = v224.m_real.m128_f32[3];
      }
      v128[2] = v119;
      v57 = 0i64;
      if ( v119 > 0 )
      {
        v143 = 0i64;
        do
        {
          v57 = (unsigned int)(v57 + 1);
          v144 = *(_DWORD *)(v224.m_real.m128_u64[0] + v143);
          v143 += 4i64;
          *(_DWORD *)(v143 + *(_QWORD *)v128 - 4) = v144;
        }
        while ( (signed int)v57 < v128[2] );
        v118 = v224.m_real.m128_f32[3];
      }
      LODWORD(v145) = (unsigned int)(2 * v253.m_real.m128_i32[0]) >> 1;
      LODWORD(v146) = (unsigned int)(2 * v252.m_real.m128_i32[0]) >> 1;
      LODWORD(v147) = (unsigned int)(2 * LODWORD(v65)) >> 1;
      LODWORD(v148) = (unsigned int)(2 * LODWORD(v64)) >> 1;
      if ( v212 )
      {
        if ( v145 > v147 )
          goto LABEL_222;
        v149 = v245;
        if ( v245 > 1 && v146 > v148 )
          goto LABEL_222;
      }
      else
      {
        v149 = v245;
      }
      LODWORD(v150) = (unsigned __int128)_mm_shuffle_ps(
                                           (__m128)LODWORD(v251->m_maxLoopShrinkFraction),
                                           (__m128)LODWORD(v251->m_maxLoopShrinkFraction),
                                           0);
      if ( v253.m_real.m128_f32[0] < 0.0 != v65 < 0.0
        || v145 <= (float)(v150 * v147)
        || v149 > 1 && (v252.m_real.m128_f32[0] < 0.0 != v64 < 0.0 || v146 <= (float)(v150 * v148)) )
      {
LABEL_222:
        v224.m_real.m128_i32[2] = 0;
        if ( v118 >= 0.0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            (void *)v224.m_real.m128_u64[0],
            4 * LODWORD(v118));
        v224.m_real.m128_u64[0] = 0i64;
        v224.m_real.m128_i32[3] = 2147483648;
        goto LABEL_173;
      }
      v224.m_real.m128_i32[2] = 0;
      if ( v118 >= 0.0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          (void *)v224.m_real.m128_u64[0],
          4 * LODWORD(v118));
      v116 = v249;
      v224.m_real.m128_u64[0] = 0i64;
      v101 = a;
      v224.m_real.m128_i32[3] = 2147483648;
    }
    if ( majorAxisA == majorAxisB )
    {
      LODWORD(v211) = segmentIndex;
      v151 = v97;
      v152 = b;
      v153 = `anonymous namespace::collapseMakesCorridorImpassable(
               v116->m_minCorridorWidth,
               v116->m_maxCorridorWidth,
               v101,
               v102,
               b,
               v101,
               b,
               v151,
               vertices,
               segments,
               v211,
               majorAxisA,
               &projectionMatrix,
               tree,
               &v248);
      if ( v248.m_enum )
      {
        v33 = v260;
        v260->m_enum = 1;
LABEL_205:
        v229.m_size = 0;
        if ( v229.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v229.m_data,
            16 * v229.m_capacityAndFlags);
        v229.m_data = 0i64;
        v229.m_capacityAndFlags = 2147483648;
        goto LABEL_327;
      }
      if ( v153 )
        goto LABEL_173;
    }
    else
    {
      v152 = b;
    }
    v154 = array;
    v155 = 0;
    v156 = -1;
    v157 = -1i64;
    v158 = 0;
    v159 = 0i64;
    if ( v219 > 0 )
    {
      while ( *(_DWORD *)&array[4 * v159] != (_DWORD)v96 )
      {
        ++v158;
        ++v159;
        if ( v158 >= v219 )
          goto LABEL_247;
      }
      v156 = v158;
      v157 = v159;
    }
LABEL_247:
    v160 = -1;
    v161 = v156;
    if ( v156 < v219 )
    {
      v162 = &array[4 * v157];
      while ( *(_DWORD *)v162 != (_DWORD)v100 )
      {
        ++v161;
        v162 += 4;
        if ( v161 >= v219 )
          goto LABEL_253;
      }
      v160 = v161;
    }
LABEL_253:
    v163 = 0;
    indices.m_size = 0;
    if ( v160 == -1 )
    {
      if ( v219 > 0 )
      {
        v164 = array;
        while ( *v164 != (_DWORD)v100 )
        {
          ++v155;
          ++v164;
          if ( v155 >= v219 )
            goto LABEL_260;
        }
        v160 = v155;
      }
LABEL_260:
      v165 = v156 + 1;
      if ( v165 < v219 )
      {
        v166 = 4 * v157 + 4;
        do
        {
          if ( v163 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &indices, 4);
            v163 = indices.m_size;
          }
          indices.m_data[v163] = *(_DWORD *)((char *)v154 + v166);
          v154 = array;
          v163 = indices.m_size + 1;
          ++v165;
          v166 += 4i64;
          ++indices.m_size;
        }
        while ( v165 < v219 );
      }
      v167 = 0i64;
      if ( v160 > 0 )
      {
        while ( 1 )
        {
          if ( v163 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &indices, 4);
            v163 = indices.m_size;
          }
          indices.m_data[v163] = v154[v167++];
          v163 = indices.m_size++ + 1;
          if ( v167 >= v160 )
            break;
          v154 = array;
        }
      }
    }
    else
    {
      v168 = v157 + 1;
      if ( v157 + 1 < v160 )
      {
        while ( 1 )
        {
          if ( v163 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &indices, 4);
            v163 = indices.m_size;
          }
          indices.m_data[v163] = v154[v168++];
          v163 = indices.m_size++ + 1;
          if ( v168 >= v160 )
            break;
          v154 = array;
        }
      }
    }
    v12 = vertices;
    v169 = a;
    v170 = `anonymous namespace::getProjectedDistanceErrorSquared(&v257, a, v152, vertices, &indices, majorAxisA);
    v171 = (__int64)v249;
    if ( COERCE_FLOAT(*v170) > (float)(v249->m_maxBorderDistanceError * v249->m_maxBorderDistanceError)
      || v212
      && COERCE_FLOAT(*`anonymous namespace::getProjectedDistanceErrorSquared(
                         &v256,
                         v169,
                         v152,
                         vertices,
                         &indices,
                         majorAxisB)) > (float)(*(float *)(v171 + 32) * *(float *)(v171 + 32)) )
    {
LABEL_173:
      v229.m_size = 0;
      if ( v229.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v229.m_data,
          16 * v229.m_capacityAndFlags);
      goto LABEL_297;
    }
    v229.m_size = 0;
    if ( v229.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v229.m_data,
        16 * v229.m_capacityAndFlags);
    v172 = v227;
    if ( v227 == -1 )
      goto LABEL_350;
    v16 = v234;
    v173 = *((_DWORD *)v234 + 2) - 1;
    *((_DWORD *)v234 + 2) = v173;
    if ( (_DWORD)v172 != v173 )
    {
      v57 = v172;
      v186 = *(_QWORD *)v16 + 4 * v172;
      v187 = 4 * (v173 - v172);
      if ( v187 > 0 )
      {
        v188 = ((unsigned int)(v187 - 1) >> 2) + 1;
        do
        {
          v189 = *(_DWORD *)(v186 + 4);
          v186 += 4i64;
          *(_DWORD *)(v186 - 4) = v189;
          --v188;
        }
        while ( v188 );
      }
      v190 = v244;
      v191 = segments->m_data;
      v192 = --*(int *)((char *)&v191->m_boundary.m_size + v190);
      if ( (_DWORD)v192 != (_DWORD)v172 )
        (*(int **)((char *)&v191->m_boundary.m_data + v190))[v172] = (*(int **)((char *)&v191->m_boundary.m_data + v190))[v192];
LABEL_306:
      v215 = 0;
      if ( v216 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          pArr,
          12 * (v216 & 0x3FFFFFFF));
      pArr = 0i64;
      v216 = 2147483648;
      v213.m_real.m128_i32[2] = 0;
      if ( v213.m_real.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          (void *)v213.m_real.m128_u64[0],
          8 * v213.m_real.m128_i32[3]);
      v213.m_real.m128_u64[0] = 0i64;
      v213.m_real.m128_i32[3] = 2147483648;
      continue;
    }
    break;
  }
  v174 = v244;
  v175 = segments->m_data;
  v35 = segments->m_data[v244 / 0x30].m_boundary.m_size == 1;
  --*(int *)((char *)&v175->m_boundary.m_size + v174);
  if ( !v35 )
    **(int **)((char *)&v175->m_boundary.m_data + v174) = (*(int **)((char *)&v175->m_boundary.m_data + v174))[*(int *)((char *)&v175->m_boundary.m_size + v174)];
  v176 = v16[2];
  if ( v176 <= 4 )
    goto LABEL_350;
  v177 = *(_QWORD *)v16;
  v178 = v176 - 1;
  v16[2] = v178;
  v179 = 4 * v178;
  if ( v179 > 0 )
  {
    v180 = ((unsigned int)(v179 - 1) >> 2) + 1;
    do
    {
      v181 = *(_DWORD *)(v177 + 4);
      v177 += 4i64;
      *(_DWORD *)(v177 - 4) = v181;
      --v180;
    }
    while ( v180 );
  }
  v182 = **(_DWORD **)v16;
  v57 = (unsigned int)(v16[2] + 1);
  v183 = v16[3] & 0x3FFFFFFF;
  if ( v183 >= (signed int)v57 )
  {
    v228.m_enum = 0;
LABEL_300:
    *(_DWORD *)(*(_QWORD *)v16 + 4i64 * (signed int)v16[2]++) = v182;
    goto LABEL_306;
  }
  v184 = 2 * v183;
  if ( (signed int)v57 < v184 )
    LODWORD(v57) = v184;
  hkArrayUtil::_reserve(&v228, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, v57, 4);
  if ( v228.m_enum == HK_SUCCESS )
    goto LABEL_300;
  v33 = v260;
  v185 = v216;
  v215 = 0;
  v260->m_enum = 1;
  if ( v185 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pArr,
      12 * (v185 & 0x3FFFFFFF));
  pArr = 0i64;
  v216 = 2147483648;
  v213.m_real.m128_i32[2] = 0;
  if ( v213.m_real.m128_i32[3] >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      (void *)v213.m_real.m128_u64[0],
      8 * v213.m_real.m128_i32[3]);
  v213.m_real.m128_u64[0] = 0i64;
  v213.m_real.m128_i32[3] = 2147483648;
LABEL_355:
  indices.m_size = 0;
  if ( indices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      indices.m_data,
      4 * indices.m_capacityAndFlags);
  v219 = 0;
  indices.m_capacityAndFlags = 2147483648;
  indices.m_data = 0i64;
  if ( v220 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v220);
  array = 0i64;
LABEL_360:
  v220 = 2147483648;
LABEL_361:
  v200 = points.m_size;
  v201 = (char *)p;
  if ( p == points.m_data )
    v200 = 0;
  points.m_size = v200;
  v202 = (16 * v223 + 127) & 0xFFFFFF80;
  v203 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v204 = (v202 + 15) & 0xFFFFFFF0;
  if ( v202 > v203->m_slabSize || &v201[v204] != v203->m_cur || v203->m_firstNonLifoEnd == v201 )
    hkLifoAllocator::slowBlockFree(v203, v201, v204);
  else
    v203->m_cur = v201;
  points.m_size = 0;
LABEL_369:
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v33;
}alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      (void *)v213.m_real.m128_u64[0],
      8 * v213.m_real.m128_i32[3]);
  v213.m_real.m128_u64[0] = 0i64;
  v213.m_real.m128_i32[3] = 2147483648;
LABEL_355:
  indices.m_size = 0;
  if ( indices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      indices.m_data,
      4 * indices.m_capacityAndFlags);
  v219 = 0;
  indices.m_capacityAndFlags = 2147483648;
  indices.m_data = 0i64;
  if ( v220 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v220);
  array = 0i64;
LABEL_360:
  v220 = 2147483648;
LABEL_361:
  v200 = points.m_size;
  v201 = (char *)p;
  if ( p == points.m_data )
    v200 = 0;
  points.m_size = v200;
  v202 = (16 * v223 + 127) & 0xFFFFFF80;
  v203 = (hkLifoAllocator *)TlsGetValue(hkMem

// File Line: 2600
// RVA: 0xB56F10
hkResult *__fastcall `anonymous namespace::simplifyConcaveBoundary(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArrayBase<int> *segmentToOppositeMap, int segmentIndex, int majorAxisA, int majorAxisB, hkcdDynamicAabbTree *tree, hkPointerMultiMap<int,int> *parToSegIdxMap)
{
  int v10; // er13
  int v11; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v12; // rax
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v13; // r12
  signed __int64 v14; // rdi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v15; // r14
  bool v16; // zf
  bool v17; // r10
  hkResult *v18; // rax
  int v19; // er11
  __int64 v20; // rax
  _DWORD *v21; // rsi
  int v22; // edi
  __m128 v23; // xmm14
  __m128 v24; // xmm15
  char v25; // r10
  int v26; // eax
  __int64 v27; // r8
  bool v28; // cl
  signed int v29; // eax
  signed int v30; // er13
  int v31; // ebx
  __int64 v32; // r9
  signed int v33; // er12
  int v34; // ecx
  _DWORD *v35; // r8
  hkVector4f *v36; // r9
  hkVector4f *v37; // rbx
  __int64 v38; // rdi
  hkVector4f *v39; // rdi
  float v40; // xmm0_4
  float v41; // xmm6_4
  int v42; // er9
  hkgpCgo::ClusterData *v43; // rbx
  hkVector4f *v44; // r8
  hkVector4f *v45; // rdx
  hkVector4f *v46; // rcx
  unsigned __int64 v47; // rdi
  __int64 v48; // r12
  hkVector4f *v49; // rax
  float v50; // xmm0_4
  int v51; // ebx
  int v52; // edi
  int v53; // eax
  int v54; // eax
  int v55; // er9
  DuplicateVertexRef *v56; // r8
  __int64 v57; // rdx
  char *v58; // rax
  int v59; // ecx
  _DWORD *v60; // r8
  __int64 v61; // r10
  __int64 v62; // rdi
  __int64 v63; // rcx
  hkVector4f *v64; // rdi
  hkVector4f *v65; // r12
  hkVector4f *v66; // rbx
  __int128 v67; // xmm5
  __int128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm0
  __m128 v72; // xmm0
  __m128 v73; // xmm1
  float v74; // xmm6_4
  hkSimdFloat32 *v75; // rax
  hkSimdFloat32 *v76; // rax
  __m128 v77; // xmm5
  __m128 v78; // xmm1
  __m128 v79; // xmm6
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm4
  __m128 v84; // xmm0
  __m128 v85; // xmm1
  __m128 v86; // xmm6
  __m128 v87; // xmm12
  __m128 v88; // xmm6
  __m128 v89; // xmm4
  __m128 v90; // xmm2
  __m128 v91; // xmm3
  __m128 v92; // xmm7
  __m128 v93; // xmm0
  __m128 v94; // xmm7
  int v95; // er9
  int *v96; // r10
  int v97; // er9
  int v98; // eax
  int v99; // eax
  _DWORD *v100; // rbx
  int v101; // er8
  char v102; // al
  char v103; // cl
  unsigned int v104; // eax
  __int64 v105; // r12
  char *v106; // rdi
  signed int v107; // ebx
  __int64 v108; // r8
  __int64 v109; // r9
  int v110; // ecx
  _DWORD *v111; // r8
  __m128 v112; // xmm8
  __m128 v113; // xmm3
  __m128 v114; // xmm1
  __m128 v115; // xmm2
  __int64 v116; // r9
  int v117; // edx
  hkVector4f *v118; // rcx
  __m128 v119; // xmm1
  __m128 v120; // xmm6
  __m128 v121; // xmm7
  __m128 v122; // xmm7
  hkVector4f *v123; // rdx
  __int64 v124; // rax
  signed __int64 v125; // rdx
  int v126; // er9
  __int64 v127; // rcx
  int v128; // eax
  int v129; // ecx
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v130; // r13
  int v131; // eax
  int v132; // eax
  int v133; // er9
  int v134; // er8
  __int64 v135; // rdx
  int v136; // xmm1_4
  int v137; // xmm0_4
  int v138; // xmm2_4
  float v139; // xmm2_4
  float v140; // xmm3_4
  int v141; // er9
  int v142; // er9
  int v143; // ebx
  int v144; // eax
  int v145; // eax
  __int64 v146; // rbx
  int v147; // ecx
  __m128 v148; // xmm1
  __m128 v149; // xmm4
  __m128 v150; // xmm2
  __int64 v151; // rdi
  __m128 v152; // xmm3
  __m128 v153; // xmm2
  __int64 v154; // r9
  __int64 v155; // r12
  __int64 v156; // rax
  int v157; // er9
  __m128 v158; // xmm6
  __m128 v159; // xmm7
  int v160; // eax
  __m128 v161; // xmm7
  int v162; // eax
  signed __int64 v163; // rcx
  int v164; // edx
  __int64 v165; // rdx
  int v166; // eax
  __int64 v167; // rcx
  hkaiNavMeshSimplificationUtils::Segment *v168; // rax
  int v169; // edx
  signed __int64 v170; // rcx
  int v171; // edx
  __int64 v172; // rdx
  int v173; // eax
  hkcdDynamicAabbTree *v174; // [rsp+20h] [rbp-B0h]
  hkSimdFloat32 *area1InOut; // [rsp+28h] [rbp-A8h]
  hkSimdFloat32 *area2InOut; // [rsp+30h] [rbp-A0h]
  hkSimdFloat32 *area1Out; // [rsp+38h] [rbp-98h]
  hkRotationf *area2Out; // [rsp+40h] [rbp-90h]
  hkRotationf *resOut; // [rsp+48h] [rbp-88h]
  __int64 v180; // [rsp+50h] [rbp-80h]
  hkgpCgo::ClusterData *pArr; // [rsp+58h] [rbp-78h]
  hkRotationf *projection; // [rsp+60h] [rbp-70h]
  hkcdDynamicAabbTree *v183; // [rsp+68h] [rbp-68h]
  DuplicateVertexRef *array; // [rsp+70h] [rbp-60h]
  int v185; // [rsp+78h] [rbp-58h]
  int v186; // [rsp+7Ch] [rbp-54h]
  bool v187; // [rsp+80h] [rbp-50h]
  int v188; // [rsp+84h] [rbp-4Ch]
  int v189; // [rsp+88h] [rbp-48h]
  hkVector4f *b; // [rsp+90h] [rbp-40h]
  hkVector4f *c; // [rsp+98h] [rbp-38h]
  hkResult v192; // [rsp+A0h] [rbp-30h]
  hkResult v193; // [rsp+A4h] [rbp-2Ch]
  hkResult v194; // [rsp+A8h] [rbp-28h]
  hkResult resulta; // [rsp+ACh] [rbp-24h]
  hkVector4f *a; // [rsp+B0h] [rbp-20h]
  int v197; // [rsp+B8h] [rbp-18h]
  hkResult v198; // [rsp+BCh] [rbp-14h]
  hkSimdFloat32 v199; // [rsp+C0h] [rbp-10h]
  hkSimdFloat32 v200; // [rsp+D0h] [rbp+0h]
  hkArrayBase<hkVector4f> points; // [rsp+E0h] [rbp+10h]
  __m128 v202; // [rsp+F0h] [rbp+20h]
  __int128 v203; // [rsp+100h] [rbp+30h]
  __int128 v204; // [rsp+110h] [rbp+40h]
  int localSettingsIndex; // [rsp+120h] [rbp+50h]
  hkResult v206; // [rsp+124h] [rbp+54h]
  hkResult v207; // [rsp+128h] [rbp+58h]
  int skipIndex; // [rsp+12Ch] [rbp+5Ch]
  int v209; // [rsp+130h] [rbp+60h]
  hkVector4f *end; // [rsp+138h] [rbp+68h]
  unsigned __int64 v211; // [rsp+140h] [rbp+70h]
  __int64 v212; // [rsp+148h] [rbp+78h]
  hkVector4f *start; // [rsp+150h] [rbp+80h]
  __m128 v214; // [rsp+160h] [rbp+90h]
  __m128 v215; // [rsp+170h] [rbp+A0h]
  hkSimdFloat32 v216; // [rsp+180h] [rbp+B0h]
  __m128 v217; // [rsp+190h] [rbp+C0h]
  hkSimdFloat32 v218; // [rsp+1A0h] [rbp+D0h]
  hkRotationf projectionMatrix; // [rsp+1B0h] [rbp+E0h]
  hkRotationf projB; // [rsp+1E0h] [rbp+110h]
  hkSimdFloat32 v221; // [rsp+210h] [rbp+140h]
  hkSimdFloat32 v222; // [rsp+220h] [rbp+150h]
  _DWORD *v223; // [rsp+310h] [rbp+240h]
  hkaiNavMeshGenerationSettings *v224; // [rsp+318h] [rbp+248h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments; // [rsp+328h] [rbp+258h]
  hkArrayBase<int> *vars0; // [rsp+330h] [rbp+260h]
  void *retaddr; // [rsp+338h] [rbp+268h]
  hkResult *majorAxis; // [rsp+340h] [rbp+270h]
  hkaiNavMeshGenerationSettings *v229; // [rsp+348h] [rbp+278h]
  hkcdDynamicAabbTree *v230; // [rsp+350h] [rbp+280h]
  hkPointerMultiMap<int,int> *v231; // [rsp+358h] [rbp+288h]

  v231 = (hkPointerMultiMap<int,int> *)segmentsInOut;
  v229 = settings;
  majorAxis = result;
  v10 = (signed int)result;
  v11 = (signed int)settings;
  v12 = segmentsInOut->m_data;
  v13 = segmentsInOut;
  v214 = _mm_shuffle_ps(
           (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
           (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
           0);
  v14 = (signed int)retaddr;
  v15 = verticesInOut;
  v16 = v12[v14].m_partitionIdB == -1;
  v211 = 48i64 * (signed int)retaddr;
  v187 = v16;
  v17 = (_DWORD)result != (_DWORD)settings && (_DWORD)settings != -1;
  BYTE1(v180) = v17;
  if ( !v16 && !v17 )
  {
    v18 = result;
    result->m_enum = 0;
    return v18;
  }
  anonymous_namespace_::getProjectionMatrix((int)result, &projectionMatrix);
  anonymous_namespace_::getProjectionMatrix(v11, &projB);
  v21 = (_DWORD *)(v14 * 48 + v20 + 32);
  v22 = 0;
  v23 = 0i64;
  v199.m_real = 0i64;
  v215 = 0i64;
  v217 = 0i64;
  v24 = 0i64;
  v200.m_real = 0i64;
  if ( v25 )
  {
    v26 = `anonymous namespace::computePartialSignedPartitionAreas(
            v15,
            v13,
            vars0,
            v231,
            v19,
            v10,
            v11,
            &v199,
            &v200,
            &v192);
    v23 = v199.m_real;
    v24 = v200.m_real;
    v22 = v26;
    `anonymous namespace::computeFullSignedPartitionAreas(v15, v13, (int)retaddr, v10, v11, &v199, &v200);
    v215 = v199.m_real;
    v217 = v200.m_real;
  }
  v27 = (signed int)v21[2];
  v28 = **(_DWORD **)v21 == *(_DWORD *)(*(_QWORD *)v21 + 4 * v27 - 4);
  LOBYTE(v180) = v28;
  if ( v28 )
    v21[2] = v27 - 1;
  localSettingsIndex = v13->m_data[v211 / 0x30].m_materialSettingsIndex;
  v212 = v22;
LABEL_13:
  if ( !v28 || v21[2] >= 4 )
  {
    v29 = 3;
    if ( v28 )
      v29 = 1;
    v30 = 2;
    if ( v28 )
      v30 = 0;
    v31 = v21[2] - v29;
    v188 = v31;
    v32 = (unsigned int)(v31 - v30 + 1);
    if ( (signed int)v32 >= 1 )
    {
      array = 0i64;
      v185 = 0;
      v186 = 2147483648;
      pArr = 0i64;
      v33 = 0;
      projection = (hkRotationf *)0x8000000000000000i64;
      if ( (signed int)v32 <= 0 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        if ( (signed int)v32 < 0 )
          LODWORD(v32) = 0;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v32, 8);
        if ( resulta.m_enum )
        {
          v100 = v223;
          *v223 = 1;
LABEL_184:
          LODWORD(projection) = 0;
          if ( SHIDWORD(projection) >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              pArr,
              12 * (HIDWORD(projection) & 0x3FFFFFFF));
          pArr = 0i64;
          HIDWORD(projection) = 2147483648;
          v185 = 0;
          if ( v186 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              array,
              8 * v186);
          return (hkResult *)v100;
        }
        v33 = (signed int)projection;
      }
      if ( v30 <= v31 )
      {
        do
        {
          v34 = v21[2];
          v35 = *(_DWORD **)v21;
          v36 = v15->m_data;
          v37 = &v15->m_data[*(signed int *)(*(_QWORD *)v21 + 4i64 * ((v30 + v34 - 1) % v34))];
          a = v37;
          v38 = (signed int)v35[v30 % v34];
          v189 = v30 + 1;
          v39 = &v36[v38];
          b = v39;
          c = &v36[v35[(v30 + 1) % v34]];
          v40 = `anonymous namespace::getProjectedTriangleArea(v37, v39, c, (int)majorAxis);
          v41 = v40;
          if ( BYTE1(v180) || v40 >= 0.001 )
          {
            if ( v185 == (v186 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
            v48 = v185;
            v49 = (hkVector4f *)array;
            ++v185;
            array[v48].m_index = v30;
            b = v49;
            if ( BYTE1(v180) )
            {
              v50 = `anonymous namespace::getTriangleArea(v37, v39, c);
              v49 = b;
              v41 = v50;
            }
            v49->m_quad.m128_f32[2 * v48] = v41;
          }
          else
          {
            v42 = v33 + 1;
            if ( (HIDWORD(projection) & 0x3FFFFFFF) >= v33 + 1 )
            {
              v193.m_enum = 0;
            }
            else
            {
              if ( v42 < 2 * (HIDWORD(projection) & 0x3FFFFFFF) )
                v42 = 2 * (HIDWORD(projection) & 0x3FFFFFFF);
              hkArrayUtil::_reserve(
                &v193,
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                &pArr,
                v42,
                12);
              if ( v193.m_enum )
              {
LABEL_170:
                v100 = v223;
                *v223 = 1;
                goto LABEL_184;
              }
              v33 = (signed int)projection;
            }
            if ( v33 == (HIDWORD(projection) & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, 12);
              v33 = (signed int)projection;
            }
            v43 = pArr;
            v44 = c;
            v45 = b;
            v46 = a;
            v47 = v33;
            LODWORD(projection) = v33 + 1;
            LODWORD(pArr[v47].m_errorRange[1]) = v30;
            *(float *)&v43[v47].m_numVertices = v40;
            v43[v47].m_errorRange[0] = `anonymous namespace::getTriangleArea(v46, v45, v44);
          }
          v30 = v189;
          v33 = (signed int)projection;
        }
        while ( v189 <= v188 );
      }
      if ( v185 > 1 )
      {
        hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
          array,
          0,
          v185 - 1,
          0);
        v33 = (signed int)projection;
      }
      if ( v33 )
      {
        if ( v33 > 1 )
        {
          hkAlgorithm::quickSortRecursive<hkgpCgo::ClusterData,hkAlgorithm::less<hkgpCgo::ClusterData>>(
            pArr,
            0,
            v33 - 1,
            0);
          v33 = (signed int)projection;
        }
        v51 = v185;
        v52 = v33 + v185;
        v53 = v186 & 0x3FFFFFFF;
        if ( v33 + v185 > (v186 & 0x3FFFFFFF) )
        {
          if ( v53 >= v52 )
          {
            v207.m_enum = 0;
          }
          else
          {
            v54 = 2 * v53;
            v55 = v33 + v185;
            if ( v52 < v54 )
              v55 = v54;
            hkArrayUtil::_reserve(&v207, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v55, 8);
          }
        }
        hkMemUtil::memMove(&array[v33], array, 8 * v51);
        v185 = v52;
        v32 = 0i64;
        if ( (signed int)projection > 0 )
        {
          v56 = array;
          v57 = 0i64;
          do
          {
            v32 = (unsigned int)(v32 + 1);
            ++v57;
            ++v56;
            v56[-1].m_index = *((_DWORD *)&pArr[v57] - 2);
            v56[-1].m_value = *((float *)&pArr[v57] - 1);
          }
          while ( (signed int)v32 < (signed int)projection );
        }
      }
      v58 = 0i64;
      v189 = 0;
      c = 0i64;
      if ( v185 <= 0 )
      {
LABEL_148:
        LODWORD(projection) = 0;
        if ( SHIDWORD(projection) >= 0 )
          ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkgpCgo::ClusterData *, _QWORD, __int64, hkcdDynamicAabbTree *, hkSimdFloat32 *, hkSimdFloat32 *, hkSimdFloat32 *, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerTempAllocator::s_alloc,
            pArr,
            12 * (HIDWORD(projection) & 0x3FFFFFFFu),
            v32,
            v174,
            area1InOut,
            area2InOut,
            area1Out,
            area2Out,
            resOut);
        pArr = 0i64;
        HIDWORD(projection) = 2147483648;
        v185 = 0;
        if ( v186 >= 0 )
          ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, DuplicateVertexRef *, _QWORD, __int64, hkcdDynamicAabbTree *, hkSimdFloat32 *, hkSimdFloat32 *, hkSimdFloat32 *, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerTempAllocator::s_alloc,
            array,
            (unsigned int)(8 * v186),
            v32,
            v174,
            area1InOut,
            area2InOut,
            area1Out,
            area2Out,
            resOut);
        v28 = v180;
        goto LABEL_153;
      }
      while ( 1 )
      {
        v59 = v21[2];
        v60 = *(_DWORD **)v21;
        v32 = (unsigned int)array[(_QWORD)v58].m_index;
        v188 = v32;
        v61 = (signed int)v60[((signed int)v32 + v59 - 1) % v59];
        v62 = (signed int)v60[(signed int)v32 % v59];
        LODWORD(a) = v32 + 1;
        skipIndex = v62;
        v63 = (signed int)v60[((signed int)v32 + 1) % v59];
        if ( v187 && (_DWORD)v61 == (_DWORD)v63 )
          goto LABEL_147;
        v64 = &v15->m_data[v62];
        v65 = &v15->m_data[v63];
        v66 = &v15->m_data[v61];
        v67 = (__int128)v64->m_quad;
        v68 = (__int128)v65->m_quad;
        v69 = _mm_sub_ps(v65->m_quad, v66->m_quad);
        v70 = _mm_sub_ps(v65->m_quad, v64->m_quad);
        if ( !BYTE1(v180) )
          break;
LABEL_85:
        v74 = array[(_QWORD)c].m_value;
        v202 = v66->m_quad;
        v203 = v67;
        v204 = v68;
        points.m_size = 3;
        points.m_capacityAndFlags = -2147483645;
        points.m_data = (hkVector4f *)&v202;
        b = (hkVector4f *)hkaiNavMeshGenerationSettings::getSimplificationSettings(v224, &points, localSettingsIndex);
        if ( v74 < b->m_quad.m128_f32[1] )
        {
          v75 = `anonymous namespace::getHeightErrorSquared(&v222, v64, v66, v65, (int)majorAxis);
          if ( COERCE_FLOAT(*v75) <= (float)(b[1].m_quad.m128_f32[3] * b[1].m_quad.m128_f32[3]) )
          {
            if ( !BYTE1(v180)
              || (v76 = `anonymous namespace::getHeightErrorSquared(&v221, v64, v66, v65, (int)v229),
                  COERCE_FLOAT(*v76) <= (float)(b[1].m_quad.m128_f32[3] * b[1].m_quad.m128_f32[3])) )
            {
              v77 = _mm_sub_ps(v66->m_quad, v65->m_quad);
              v78 = _mm_mul_ps(v77, v77);
              v79 = _mm_sub_ps(v66->m_quad, v64->m_quad);
              v80 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                      _mm_shuffle_ps(v78, v78, 170));
              v81 = _mm_mul_ps(v79, v77);
              v82 = _mm_rcp_ps(v80);
              v83 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                        _mm_shuffle_ps(v81, v81, 170)),
                      _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v80, v82)), v82));
              v84 = _mm_cmpltps(v83, query.m_quad);
              v85 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v83, v84), _mm_andnot_ps(v84, query.m_quad)));
              v86 = _mm_add_ps(_mm_sub_ps(v79, _mm_mul_ps(v85, v77)), v64->m_quad);
              v87 = _mm_sub_ps(v64->m_quad, _mm_shuffle_ps(v86, _mm_unpackhi_ps(v86, v85), 196));
              v88 = _mm_mul_ps(v87, v87);
              v89 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                      _mm_shuffle_ps(v88, v88, 170));
              v90 = _mm_rsqrt_ps(v89);
              v91 = _mm_andnot_ps(
                      _mm_cmpleps(v89, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v90, v89), v90)),
                        _mm_mul_ps(*(__m128 *)_xmm, v90)));
              v92 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0), v214),
                        _mm_mul_ps(v91, v89)),
                      _mm_mul_ps(v91, v87));
              v93 = v92;
              v94 = _mm_add_ps(v92, v65->m_quad);
              v199.m_real = _mm_add_ps(v93, v66->m_quad);
              v95 = v21[2];
              v96 = *(int **)v21;
              v200.m_real = v94;
              start = &v15->m_data[v96[(v95 + v188 - 2) % v95]];
              end = &v15->m_data[v96[(v188 + 2) % v95]];
              if ( (_BYTE)v180 )
              {
                v97 = v95 + 1;
                v209 = *v96;
                v98 = v21[3] & 0x3FFFFFFF;
                if ( v98 >= v97 )
                {
                  v198.m_enum = 0;
                }
                else
                {
                  v99 = 2 * v98;
                  if ( v97 < v99 )
                    v97 = v99;
                  hkArrayUtil::_reserve(
                    &v198,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v21,
                    v97,
                    4);
                  if ( v198.m_enum )
                  {
LABEL_94:
                    v100 = v223;
                    v101 = points.m_capacityAndFlags;
                    points.m_size = 0;
                    *v223 = 1;
                    if ( v101 >= 0 )
                      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                        points.m_data,
                        16 * v101);
                    points.m_data = 0i64;
                    points.m_capacityAndFlags = 2147483648;
                    goto LABEL_184;
                  }
                }
                *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (signed int)v21[2]++) = v209;
              }
              resOut = &projB;
              area2Out = &projectionMatrix;
              LODWORD(area1Out) = (_DWORD)v229;
              LODWORD(area2InOut) = (_DWORD)majorAxis;
              LODWORD(area1InOut) = (_DWORD)retaddr;
              v174 = v230;
              if ( `anonymous namespace::doesLineSegmentIntersectPartition(
                     (hkVector4f *)&v199,
                     (hkVector4f *)&v200,
                     v15,
                     segments) )
              {
                goto LABEL_193;
              }
              resOut = &projB;
              area2Out = &projectionMatrix;
              LODWORD(area1Out) = (_DWORD)v229;
              LODWORD(area2InOut) = (_DWORD)majorAxis;
              LODWORD(area1InOut) = (_DWORD)retaddr;
              v174 = v230;
              if ( `anonymous namespace::doesLineSegmentIntersectPartition(start, (hkVector4f *)&v199, v15, segments)
                || (resOut = &projB,
                    area2Out = &projectionMatrix,
                    LODWORD(area1Out) = (_DWORD)v229,
                    LODWORD(area2InOut) = (_DWORD)majorAxis,
                    LODWORD(area1InOut) = (_DWORD)retaddr,
                    v174 = v230,
                    (v102 = `anonymous namespace::doesLineSegmentIntersectPartition(
                              (hkVector4f *)&v200,
                              end,
                              v15,
                              segments)) != 0) )
              {
LABEL_193:
                v102 = 1;
              }
              v103 = 0;
              LOBYTE(v183) = v102;
              if ( !v102 && (_DWORD)majorAxis == (_DWORD)v229 )
              {
                array = (DuplicateVertexRef *)&v206;
                v183 = v230;
                projection = &projectionMatrix;
                LODWORD(pArr) = (_DWORD)majorAxis;
                LODWORD(v180) = (_DWORD)retaddr;
                v103 = `anonymous namespace::collapseMakesCorridorImpassable(
                         b->m_quad.m128_f32[2],
                         b->m_quad.m128_f32[3],
                         v66,
                         v64,
                         v65,
                         (hkVector4f *)&v199,
                         (hkVector4f *)&v200,
                         skipIndex,
                         v15,
                         segments,
                         v180,
                         (int)majorAxis,
                         &projectionMatrix,
                         v230,
                         &v206);
                if ( v206.m_enum )
                  goto LABEL_94;
                v102 = (char)v183;
              }
              if ( (_BYTE)v180 )
                --v21[2];
              if ( !v102 && !v103 )
              {
                if ( !BYTE1(v180) )
                {
                  v112 = v214;
                  v130 = segments;
                  goto LABEL_163;
                }
                v104 = v21[2];
                v105 = v104;
                if ( v104 )
                {
                  v197 = 4 * v104;
                  v106 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                   &v197);
                  v104 = v197 / 4;
                }
                else
                {
                  v106 = 0i64;
                }
                v107 = 2147483648;
                if ( v104 )
                  v107 = v104;
                if ( (signed int)v105 > 0 )
                {
                  v108 = 0i64;
                  v109 = v105;
                  do
                  {
                    v108 += 4i64;
                    *(_DWORD *)&v106[v108 - 4] = *(_DWORD *)(v108 + *(_QWORD *)v21 - 4);
                    --v109;
                  }
                  while ( v109 );
                }
                v110 = v21[2];
                v111 = *(_DWORD **)v21;
                v112 = v214;
                v113 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                         _mm_shuffle_ps(v88, v88, 170));
                v114 = _mm_rsqrt_ps(v113);
                v115 = _mm_andnot_ps(
                         _mm_cmpleps(v113, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v114, v113), v114)),
                           _mm_mul_ps(*(__m128 *)_xmm, v114)));
                v116 = (v110 + v188 - 1) % v110;
                v117 = (signed int)a % v110;
                v118 = v15->m_data;
                v119 = _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0), v214),
                           _mm_mul_ps(v115, v113)),
                         _mm_mul_ps(v115, v87));
                v120 = _mm_add_ps(v15->m_data[*(signed int *)(*(_QWORD *)v21 + 4 * v116)].m_quad, v119);
                end = (hkVector4f *)v117;
                v121 = v118[v111[v117]].m_quad;
                v111[v116] = v15->m_size;
                v122 = _mm_add_ps(v121, v119);
                if ( v15->m_size == (v15->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v15, 16);
                v123 = end;
                v15->m_data[v15->m_size++].m_quad = v120;
                *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (_QWORD)v123) = v15->m_size;
                if ( v15->m_size == (v15->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v15, 16);
                v15->m_data[v15->m_size++].m_quad = v122;
                v124 = v188;
                --v21[2];
                v125 = *(_QWORD *)v21 + 4 * v124;
                v126 = 4 * (v21[2] - v124);
                if ( v126 > 0 )
                {
                  v127 = ((unsigned int)(v126 - 1) >> 2) + 1;
                  do
                  {
                    v128 = *(_DWORD *)(v125 + 4);
                    v125 += 4i64;
                    *(_DWORD *)(v125 - 4) = v128;
                    --v127;
                  }
                  while ( v127 );
                }
                if ( (_BYTE)v180 )
                {
                  v129 = v21[2];
                  if ( v129 > 0 )
                  {
                    LODWORD(a) = **(_DWORD **)v21;
                    if ( v129 == (v21[3] & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v21, 4);
                    *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (signed int)v21[2]++) = (_DWORD)a;
                  }
                }
                _mm_store_si128((__m128i *)&v216, (__m128i)v23);
                _mm_store_si128((__m128i *)&v218, (__m128i)v24);
                v130 = segments;
                `anonymous namespace::computeFullSignedPartitionAreas(
                  v15,
                  segments,
                  (int)retaddr,
                  (int)majorAxis,
                  (int)v229,
                  &v216,
                  &v218);
                v131 = v21[3] & 0x3FFFFFFF;
                if ( v131 >= (signed int)v105 )
                {
                  v192.m_enum = 0;
                }
                else
                {
                  v132 = 2 * v131;
                  v133 = v105;
                  if ( (signed int)v105 < v132 )
                    v133 = v132;
                  hkArrayUtil::_reserve(
                    &v192,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v21,
                    v133,
                    4);
                }
                v21[2] = v105;
                v134 = 0;
                if ( (signed int)v105 > 0 )
                {
                  v135 = 0i64;
                  do
                  {
                    ++v134;
                    *(_DWORD *)(v135 + *(_QWORD *)v21) = *(_DWORD *)&v106[v135];
                    v135 += 4i64;
                  }
                  while ( v134 < v21[2] );
                }
                v136 = (unsigned __int128)_mm_load_si128((const __m128i *)&v216);
                v137 = (unsigned __int128)_mm_load_si128((const __m128i *)&v215);
                v138 = (unsigned __int128)_mm_load_si128((const __m128i *)&v218);
                v15->m_size -= 2;
                LODWORD(v139) = (unsigned int)(2 * v138) >> 1;
                LODWORD(v140) = 2 * (unsigned int)*(_OWORD *)&_mm_load_si128((const __m128i *)&v217) >> 1;
                if ( COERCE_FLOAT((unsigned int)(2 * v136) >> 1) < COERCE_FLOAT((unsigned int)(2 * v137) >> 1)
                  && (v212 <= 1 || v139 < v140) )
                {
                  if ( v107 >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      v106,
                      4 * v107);
LABEL_163:
                  points.m_size = 0;
                  if ( points.m_capacityAndFlags >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      points.m_data,
                      16 * points.m_capacityAndFlags);
                  v146 = v188;
                  if ( v188 == -1 )
                    goto LABEL_148;
                  v147 = v21[2];
                  v148 = _mm_mul_ps(v87, v87);
                  v149 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
                           _mm_shuffle_ps(v148, v148, 170));
                  v150 = _mm_rsqrt_ps(v149);
                  v151 = (v147 + v188 - 1) % v147;
                  v152 = _mm_andnot_ps(
                           _mm_cmpleps(v149, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v150, v149), v150)),
                             _mm_mul_ps(*(__m128 *)_xmm, v150)));
                  v153 = _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v112, _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0)),
                             _mm_mul_ps(v152, v149)),
                           _mm_mul_ps(v152, v87));
                  v154 = (v188 + 1) % v147;
                  v155 = v154;
                  v156 = *(signed int *)(*(_QWORD *)v21 + 4 * v154);
                  v157 = v15->m_size + 2;
                  v158 = _mm_add_ps(v15->m_data[*(signed int *)(*(_QWORD *)v21 + 4 * v151)].m_quad, v153);
                  v159 = v15->m_data[v156].m_quad;
                  v160 = v15->m_capacityAndFlags & 0x3FFFFFFF;
                  v161 = _mm_add_ps(v159, v153);
                  if ( v160 >= v157 )
                  {
                    v194.m_enum = 0;
                  }
                  else
                  {
                    v162 = 2 * v160;
                    if ( v157 < v162 )
                      v157 = v162;
                    hkArrayUtil::_reserve(
                      &v194,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      v15,
                      v157,
                      16);
                    if ( v194.m_enum )
                      goto LABEL_170;
                  }
                  *(_DWORD *)(*(_QWORD *)v21 + 4 * v151) = v15->m_size;
                  v15->m_data[v15->m_size++].m_quad = v158;
                  *(_DWORD *)(*(_QWORD *)v21 + 4 * v155) = v15->m_size;
                  v15->m_data[v15->m_size++].m_quad = v161;
                  --v21[2];
                  v163 = *(_QWORD *)v21 + 4 * v146;
                  v164 = 4 * (v21[2] - v146);
                  if ( v164 > 0 )
                  {
                    v165 = ((unsigned int)(v164 - 1) >> 2) + 1;
                    do
                    {
                      v166 = *(_DWORD *)(v163 + 4);
                      v163 += 4i64;
                      *(_DWORD *)(v163 - 4) = v166;
                      --v165;
                    }
                    while ( v165 );
                  }
                  v167 = v211;
                  v168 = v130->m_data;
                  v169 = --*(int *)((char *)&v168->m_boundary.m_size + v167);
                  v170 = (signed __int64)&(*(int **)((char *)&v168->m_boundary.m_data + v167))[v146];
                  v171 = 4 * (v169 - v146);
                  if ( v171 > 0 )
                  {
                    v172 = ((unsigned int)(v171 - 1) >> 2) + 1;
                    do
                    {
                      v173 = *(_DWORD *)(v170 + 4);
                      v170 += 4i64;
                      *(_DWORD *)(v170 - 4) = v173;
                      --v172;
                    }
                    while ( v172 );
                  }
                  LODWORD(projection) = 0;
                  if ( SHIDWORD(projection) >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      pArr,
                      12 * (HIDWORD(projection) & 0x3FFFFFFF));
                  pArr = 0i64;
                  HIDWORD(projection) = 2147483648;
                  v185 = 0;
                  if ( v186 >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      array,
                      8 * v186);
                  v28 = v180;
                  array = 0i64;
                  v186 = 2147483648;
                  goto LABEL_13;
                }
                if ( v107 >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    v106,
                    4 * v107);
              }
            }
          }
        }
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
LABEL_147:
        v58 = &c->m_quad.m128_i8[1];
        ++v189;
        c = (hkVector4f *)((char *)c + 1);
        if ( v189 >= v185 )
          goto LABEL_148;
      }
      if ( (_DWORD)majorAxis )
      {
        if ( (_DWORD)majorAxis == 1 )
        {
          v69 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 216), (__m128)xmmword_141A71320);
          goto LABEL_73;
        }
        if ( (_DWORD)majorAxis == 2 )
          goto LABEL_73;
        if ( (_DWORD)majorAxis != 3 )
        {
          if ( (_DWORD)majorAxis == 4 )
            v69 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 210), (__m128)xmmword_141A71320);
          else
            v69 = _mm_shuffle_ps(v69, v69, 225);
LABEL_73:
          if ( (_DWORD)majorAxis )
          {
            if ( (_DWORD)majorAxis == 1 )
            {
              v70 = _mm_mul_ps(_mm_shuffle_ps(v70, v70, 216), (__m128)xmmword_141A71320);
              goto LABEL_84;
            }
            if ( (_DWORD)majorAxis == 2 )
              goto LABEL_84;
            if ( (_DWORD)majorAxis != 3 )
            {
              if ( (_DWORD)majorAxis == 4 )
                v70 = _mm_mul_ps(_mm_shuffle_ps(v70, v70, 210), (__m128)xmmword_141A71320);
              else
                v70 = _mm_shuffle_ps(v70, v70, 225);
LABEL_84:
              v73 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 225), v70);
              if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 0)) - COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 85))) < 0.0 )
                goto LABEL_147;
              goto LABEL_85;
            }
            v72 = _mm_shuffle_ps(v70, v70, 230);
          }
          else
          {
            v72 = _mm_shuffle_ps(v70, v70, 233);
          }
          v70 = v72;
          goto LABEL_84;
        }
        v71 = _mm_shuffle_ps(v69, v69, 230);
      }
      else
      {
        v71 = _mm_shuffle_ps(v69, v69, 233);
      }
      v69 = v71;
      goto LABEL_73;
    }
  }
LABEL_153:
  if ( v28 )
  {
    v141 = v21[2];
    if ( v141 > 0 )
    {
      v142 = v141 + 1;
      v143 = **(_DWORD **)v21;
      v144 = v21[3] & 0x3FFFFFFF;
      if ( v144 < v142 )
      {
        v145 = 2 * v144;
        if ( v142 < v145 )
          v142 = v145;
        hkArrayUtil::_reserve(
          (hkResult *)&v229,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v21,
          v142,
          4);
        if ( (_DWORD)v229 )
        {
          v100 = v223;
          *v223 = 1;
          return (hkResult *)v100;
        }
      }
      *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (signed int)v21[2]++) = v143;
    }
  }
  v100 = v223;
  *v223 = 0;
  return (hkResult *)v100;
}

// File Line: 2919
// RVA: 0xB582E0
hkResult *__fastcall `anonymous namespace::simplifySegment(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArrayBase<int> *segmentToOppositeMap, int segmentIndex, int majorAxisA, int majorAxisB, hkPointerMultiMap<int,int> *parToSegIdxMap, hkBitField *unremovableVertices)
{
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v10; // r13
  hkResult *v11; // r12
  hkaiNavMeshSimplificationUtils::Segment *v12; // rbx
  __int64 v13; // r11
  hkResult *v14; // rax
  hkPointerMultiMap<int,int> *v15; // r15
  signed int v16; // edi
  int v17; // er11
  int v18; // edx
  signed __int64 v19; // r8
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // er9
  __int64 v24; // rsi
  int v25; // er9
  __int64 i; // rdx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v27; // rcx
  int v28; // eax
  int v29; // er11
  signed int v30; // edi
  int v31; // er8
  signed __int64 v32; // rdx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // er9
  __int64 v37; // rsi
  int v38; // er9
  __int64 j; // rdx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v40; // rax
  int *v41; // r9
  signed int v42; // edx
  int v43; // ecx
  int *v44; // rbx
  __int64 v45; // rax
  int v46; // er8
  signed __int64 v47; // rbx
  int v48; // er9
  int v49; // ecx
  int v50; // esi
  int v51; // edi
  __int64 v52; // rbx
  __int64 v53; // r8
  hkVector4f v54; // xmm2
  signed __int64 v55; // rdx
  int v56; // er10
  hkVector4f v57; // xmm1
  __int64 v58; // r9
  hkVector4f *v59; // r11
  __int64 v60; // rax
  signed __int64 v61; // rcx
  int v62; // edi
  int v63; // ebx
  bool v64; // al
  int v65; // ST28_4
  hkArrayBase<int> *v66; // rsi
  int *array; // [rsp+60h] [rbp-59h]
  int v68; // [rsp+68h] [rbp-51h]
  int v69; // [rsp+6Ch] [rbp-4Dh]
  hkcdDynamicAabbTree tree; // [rsp+70h] [rbp-49h]
  hkAabb aabb; // [rsp+90h] [rbp-29h]
  hkaiNavMeshGenerationSettings *settingsa; // [rsp+F8h] [rbp+3Fh]
  hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOuta; // [rsp+100h] [rbp+47h]
  hkResult resulta; // [rsp+108h] [rbp+4Fh]

  verticesInOuta = verticesInOut;
  settingsa = settings;
  v10 = segmentsInOut;
  v11 = result;
  v12 = &segmentsInOut->m_data[segmentIndex];
  v13 = v12->m_indices.m_size;
  if ( *v12->m_indices.m_data == v12->m_indices.m_data[v13 - 1] && (signed int)v13 <= 2 )
  {
    v14 = result;
    result->m_enum = 0;
    return v14;
  }
  v69 = 2147483648;
  array = 0i64;
  v68 = 0;
  v15 = parToSegIdxMap;
  v16 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                            &parToSegIdxMap->m_map,
                            v12->m_partitionIdA);
  if ( v16 <= v15->m_map.m_hashMod )
  {
    v17 = v68;
    do
    {
      v18 = v12->m_partitionIdA;
      v19 = (signed __int64)&v10->m_data[SLODWORD(v15->m_map.m_elem[v16].val)];
      v20 = *(_DWORD *)(v19 + 4);
      if ( v20 == v18
        || (v21 = v12->m_partitionIdB, v20 == v21)
        || v21 != -1 && ((v22 = *(_DWORD *)(v19 + 8), v22 == v18) || v22 == v21) )
      {
        v23 = v17 + 1;
        if ( (v69 & 0x3FFFFFFF) >= v17 + 1 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v23 < 2 * (v69 & 0x3FFFFFFF) )
            v23 = 2 * (v69 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v23, 4);
          if ( resulta.m_enum )
          {
LABEL_39:
            v11->m_enum = 1;
            goto LABEL_83;
          }
          v17 = v68;
        }
        array[v17] = v15->m_map.m_elem[v16].val;
        v17 = v68++ + 1;
      }
      v24 = v15->m_map.m_hashMod;
      v25 = v16 + 1;
      for ( i = v16 + 1; i > v24; i = 0i64 )
LABEL_24:
        v25 = 0;
      v27 = &v15->m_map.m_elem[i];
      while ( v27->key != -1i64 )
      {
        if ( v27->key == v12->m_partitionIdA )
        {
          v16 = v25;
          goto LABEL_27;
        }
        ++i;
        ++v25;
        ++v27;
        if ( i > v24 )
          goto LABEL_24;
      }
      v16 = v24 + 1;
LABEL_27:
      ;
    }
    while ( v16 <= (signed int)v24 );
  }
  v28 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                            &v15->m_map,
                            v12->m_partitionIdB);
  v29 = v68;
  v30 = v28;
  if ( v28 <= v15->m_map.m_hashMod )
  {
    do
    {
      v31 = v12->m_partitionIdA;
      v32 = (signed __int64)&v10->m_data[SLODWORD(v15->m_map.m_elem[v30].val)];
      v33 = *(_DWORD *)(v32 + 4);
      if ( v33 == v31
        || (v34 = v12->m_partitionIdB, v33 == v34)
        || v34 != -1 && ((v35 = *(_DWORD *)(v32 + 8), v35 == v31) || v35 == v34) )
      {
        v36 = v29 + 1;
        if ( (v69 & 0x3FFFFFFF) >= v29 + 1 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v36 < 2 * (v69 & 0x3FFFFFFF) )
            v36 = 2 * (v69 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v36, 4);
          if ( resulta.m_enum )
            goto LABEL_39;
          v29 = v68;
        }
        array[v29] = v15->m_map.m_elem[v30].val;
        v29 = v68++ + 1;
      }
      v37 = v15->m_map.m_hashMod;
      v38 = v30 + 1;
      for ( j = v30 + 1; j > v37; j = 0i64 )
LABEL_48:
        v38 = 0;
      v40 = &v15->m_map.m_elem[j];
      while ( v40->key != -1i64 )
      {
        if ( v40->key == v12->m_partitionIdB )
        {
          v30 = v38;
          goto LABEL_51;
        }
        ++j;
        ++v38;
        ++v40;
        if ( j > v37 )
          goto LABEL_48;
      }
      v30 = v37 + 1;
LABEL_51:
      ;
    }
    while ( v30 <= (signed int)v37 );
  }
  if ( v29 > 1 )
  {
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(array, 0, v29 - 1, 0);
    v29 = v68;
  }
  v41 = array;
  v42 = -1;
  v43 = 0;
  v44 = array;
  if ( v29 > 0 )
  {
    v45 = 0i64;
    do
    {
      v46 = v41[v45];
      if ( v46 != v42 )
      {
        v42 = v41[v45];
        ++v44;
        *(v44 - 1) = v46;
        v29 = v68;
        v41 = array;
      }
      ++v43;
      ++v45;
    }
    while ( v43 < v29 );
  }
  v47 = v44 - v41;
  if ( (v69 & 0x3FFFFFFF) < (signed int)v47 )
  {
    v48 = v47;
    if ( (signed int)v47 < 2 * (v69 & 0x3FFFFFFF) )
      v48 = 2 * (v69 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v48, 4);
  }
  v68 = v47;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&tree);
  v49 = v68;
  v50 = segmentIndex;
  v51 = 0;
  if ( v68 > 0 )
  {
    v52 = 0i64;
    do
    {
      v53 = array[v52];
      if ( (_DWORD)v53 != v50 )
      {
        v54.m_quad = (__m128)xmmword_141A712A0;
        aabb.m_min = (hkVector4f)xmmword_141A712A0;
        v55 = (signed __int64)&v10->m_data[v53];
        v56 = 0;
        v57.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       (__m128)xmmword_141A712A0);
        aabb.m_max = (hkVector4f)v57.m_quad;
        if ( *(_DWORD *)(v55 + 40) > 0 )
        {
          v58 = 0i64;
          v59 = verticesInOuta->m_data;
          do
          {
            v60 = *(_QWORD *)(v55 + 32);
            ++v56;
            v58 += 4i64;
            v61 = *(signed int *)(v60 + v58 - 4);
            v54.m_quad = _mm_min_ps(v54.m_quad, v59[*(signed int *)(v60 + v58 - 4)].m_quad);
            aabb.m_min = (hkVector4f)v54.m_quad;
            v57.m_quad = _mm_max_ps(v57.m_quad, v59[v61].m_quad);
            aabb.m_max = (hkVector4f)v57.m_quad;
          }
          while ( v56 < *(_DWORD *)(v55 + 40) );
        }
        hkcdDynamicAabbTree::tryInsert(&tree, &aabb, v53, &resulta);
        if ( resulta.m_enum )
          goto LABEL_75;
        v49 = v68;
      }
      ++v51;
      ++v52;
    }
    while ( v51 < v49 );
  }
  v62 = majorAxisA;
  v63 = majorAxisB;
  if ( majorAxisA == majorAxisB || majorAxisB == -1 )
  {
    v64 = `anonymous namespace::convertSegmentToObb(
            settingsa,
            verticesInOuta,
            v10,
            v50,
            majorAxisA,
            majorAxisB,
            &tree,
            &resulta) == 0;
    if ( resulta.m_enum )
    {
LABEL_75:
      v11->m_enum = 1;
      goto LABEL_82;
    }
    if ( !v64 )
      goto LABEL_88;
  }
  v65 = v50;
  v66 = segmentToOppositeMap;
  `anonymous namespace::simplifyInternalOrConvexBoundary(
    &resulta,
    settingsa,
    verticesInOuta,
    v10,
    segmentToOppositeMap,
    v65,
    v62,
    v63,
    &tree,
    v15,
    unremovableVertices);
  if ( resulta.m_enum )
  {
    v11->m_enum = 1;
    goto LABEL_82;
  }
  `anonymous namespace::simplifyConcaveBoundary(
    (hkResult *)&segmentIndex,
    settingsa,
    verticesInOuta,
    v10,
    v66,
    segmentIndex,
    v62,
    v63,
    &tree,
    v15);
  if ( segmentIndex )
    v11->m_enum = 1;
  else
LABEL_88:
    v11->m_enum = 0;
LABEL_82:
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&tree);
LABEL_83:
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v69);
  return v11;
}

// File Line: 3040
// RVA: 0xB4A980
hkResult *__fastcall hkaiNavMeshSimplificationUtils::setSegmentIndices(hkResult *result, hkaiNavMesh *navMesh, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut, hkPointerMap<int,int,hkContainerHeapAllocator> *vertexIndexMapOut)
{
  bool v5; // zf
  bool v6; // sf
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rdi
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v8; // rax
  hkaiNavMesh *v9; // r12
  hkResult *v10; // r13
  hkPointerMap<int,int,hkContainerHeapAllocator> *v11; // r14
  __int64 v12; // rdx
  char *v13; // r15
  int v14; // er9
  int v15; // eax
  int v16; // er9
  int v17; // eax
  hkaiNavMesh::Edge *v18; // rax
  hkaiNavMesh::Edge *v19; // rbp
  unsigned __int64 v20; // rsi
  unsigned __int64 v21; // rax
  int v22; // er9
  int v23; // eax
  int v24; // eax
  int v25; // ebp
  __int64 v26; // r14
  hkaiNavMesh::Edge *v27; // rax
  signed __int64 v28; // r12
  unsigned __int64 v29; // rsi
  unsigned __int64 v30; // rax
  int v31; // er9
  int v32; // eax
  int v33; // eax
  hkResult resulta; // [rsp+30h] [rbp-58h]
  hkResult v36; // [rsp+34h] [rbp-54h]
  hkResult v37; // [rsp+38h] [rbp-50h]
  int v38; // [rsp+3Ch] [rbp-4Ch]
  hkResult res; // [rsp+40h] [rbp-48h]
  hkResult v40; // [rsp+44h] [rbp-44h]
  __int64 v41; // [rsp+48h] [rbp-40h]
  hkaiNavMesh *v42; // [rsp+98h] [rbp+10h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v43; // [rsp+A0h] [rbp+18h]

  v43 = segmentsInOut;
  v42 = navMesh;
  v5 = segmentsInOut->m_size == 0;
  v6 = segmentsInOut->m_size < 0;
  v7 = verticesOut;
  v8 = segmentsInOut;
  v9 = navMesh;
  v10 = result;
  v38 = 0;
  if ( v6 || v5 )
  {
LABEL_30:
    v10->m_enum = 0;
    return v10;
  }
  v11 = vertexIndexMapOut;
  v12 = 0i64;
  v41 = 0i64;
  while ( 1 )
  {
    v13 = (char *)v8->m_data + v12;
    v14 = *((_DWORD *)v13 + 6);
    *(_DWORD *)v13 = -1;
    v15 = *((_DWORD *)v13 + 11) & 0x3FFFFFFF;
    v16 = v14 + 1;
    if ( v15 >= v16 )
    {
      resulta.m_enum = 0;
      goto LABEL_9;
    }
    v17 = 2 * v15;
    if ( v16 < v17 )
      v16 = v17;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13 + 32, v16, 4);
    if ( resulta.m_enum )
      break;
LABEL_9:
    v18 = v9->m_edges.m_data;
    v19 = &v18[**((signed int **)v13 + 2)];
    LODWORD(v20) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11->m_map.m_elem,
                     v18[**((signed int **)v13 + 2)].m_a,
                     0xFFFFFFFFFFFFFFFFui64);
    if ( (_DWORD)v20 == -1 )
    {
      v21 = v7->m_size;
      v20 = v21;
      v22 = v21 + 1;
      v23 = v7->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v23 >= v22 )
      {
        v36.m_enum = 0;
      }
      else
      {
        v24 = 2 * v23;
        if ( v22 < v24 )
          v22 = v24;
        hkArrayUtil::_reserve(&v36, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v22, 16);
        if ( v36.m_enum )
          break;
      }
      v7->m_data[v7->m_size++] = v9->m_vertices.m_data[v19->m_a];
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11->m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v19->m_a,
        v20,
        &res);
      if ( res.m_enum )
        break;
    }
    v25 = 0;
    *(_DWORD *)(*((_QWORD *)v13 + 4) + 4i64 * (signed int)(*((_DWORD *)v13 + 10))++) = v20;
    if ( *((_DWORD *)v13 + 6) > 0 )
    {
      v26 = 0i64;
      do
      {
        v27 = v9->m_edges.m_data;
        v28 = (signed __int64)&v27[*(signed int *)(v26 + *((_QWORD *)v13 + 2))];
        LODWORD(v29) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexIndexMapOut->m_map.m_elem,
                         v27[*(signed int *)(v26 + *((_QWORD *)v13 + 2))].m_b,
                         0xFFFFFFFFFFFFFFFFui64);
        if ( (_DWORD)v29 == -1 )
        {
          v30 = v7->m_size;
          v29 = v30;
          v31 = v30 + 1;
          v32 = v7->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v32 >= v31 )
          {
            v37.m_enum = 0;
          }
          else
          {
            v33 = 2 * v32;
            if ( v31 < v33 )
              v31 = v33;
            hkArrayUtil::_reserve(&v37, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v31, 16);
            if ( v37.m_enum )
              goto LABEL_7;
          }
          v7->m_data[v7->m_size++] = v42->m_vertices.m_data[*(signed int *)(v28 + 4)];
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexIndexMapOut->m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            *(signed int *)(v28 + 4),
            v29,
            &v40);
          if ( v40.m_enum )
            goto LABEL_7;
        }
        v9 = v42;
        *(_DWORD *)(*((_QWORD *)v13 + 4) + 4i64 * (signed int)(*((_DWORD *)v13 + 10))++) = v29;
        ++v25;
        v26 += 4i64;
      }
      while ( v25 < *((_DWORD *)v13 + 6) );
      v11 = vertexIndexMapOut;
    }
    v8 = v43;
    v12 = v41 + 48;
    ++v38;
    v41 += 48i64;
    if ( v38 >= v43->m_size )
      goto LABEL_30;
  }
LABEL_7:
  v10->m_enum = 1;
  return v10;
}

// File Line: 3090
// RVA: 0xB4AC90
hkResult *__fastcall hkaiNavMeshSimplificationUtils::setMaterialSettingsIndices(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *mesh, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitions, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut)
{
  hkArray<int,hkContainerHeapAllocator> *v6; // r15
  hkaiNavMesh *v7; // r13
  hkaiNavMeshGenerationSettings *v8; // r14
  hkResult *v9; // r12
  int v11; // edi
  __int64 v12; // rsi
  hkaiNavMeshGenerationSettings::OverrideSettings *v13; // rax
  int v14; // esi
  int *v15; // rdx
  signed __int64 v16; // rdi
  int v17; // er9
  __int64 v18; // r8
  hkArray<int,hkContainerHeapAllocator> *v19; // r11
  int v20; // er10
  int v21; // er8
  signed int i; // er8
  __int64 v23; // r9
  int v24; // ecx
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v25; // r12
  int v26; // er14
  __int64 v27; // r15
  hkaiNavMeshSimplificationUtils::Segment *v28; // rsi
  signed int v29; // edi
  signed int v30; // eax
  int v31; // er8
  char *array; // [rsp+30h] [rbp-28h]
  int v33; // [rsp+38h] [rbp-20h]
  int v34; // [rsp+3Ch] [rbp-1Ch]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v35; // [rsp+40h] [rbp-18h]
  hkResult *v36; // [rsp+90h] [rbp+38h]
  hkResult resulta; // [rsp+A8h] [rbp+50h]

  v36 = result;
  v6 = numFacesInPartition;
  v7 = mesh;
  v8 = settings;
  v9 = result;
  if ( !numFacesInPartition->m_size )
  {
    result->m_enum = 0;
    return result;
  }
  v35.m_elem = 0i64;
  v11 = 0;
  v35.m_numElems = 0;
  v35.m_hashMod = -1;
  if ( settings->m_overrideSettings.m_size <= 0 )
  {
LABEL_8:
    v14 = v6->m_size;
    v15 = 0i64;
    array = 0i64;
    v33 = 0;
    v34 = 2147483648;
    v16 = 1i64;
    if ( v14 <= 0 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v17 = v14;
      if ( v14 < 0 )
        v17 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v17, 4);
      if ( resulta.m_enum )
      {
        v33 = 0;
        v9->m_enum = 1;
        if ( v34 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            4 * v34);
        array = 0i64;
        v34 = 2147483648;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &v35,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&v35);
        return v9;
      }
      v15 = (int *)array;
    }
    v18 = v7->m_faceDataStriding;
    v19 = partitions;
    v33 = v14;
    v20 = 0;
    if ( (_DWORD)v18 )
      v21 = v7->m_faceData.m_data[v18 * *partitions->m_data];
    else
      v21 = 0;
    *v15 = v21;
    for ( i = 1; i < v6->m_size; *(_DWORD *)&array[v16 * 4 - 4] = v24 )
    {
      v23 = v7->m_faceDataStriding;
      v20 += v6->m_data[v16 - 1];
      if ( (_DWORD)v23 )
        v24 = v7->m_faceData.m_data[v23 * v19->m_data[v20]];
      else
        v24 = 0;
      ++i;
      ++v16;
    }
    v25 = segmentsInOut;
    v26 = 0;
    if ( segmentsInOut->m_size <= 0 )
    {
LABEL_40:
      v31 = v34;
      v33 = 0;
      v36->m_enum = 0;
      if ( v31 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v31);
      array = 0i64;
      v34 = 2147483648;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v35,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v35);
      return v36;
    }
    v27 = 0i64;
    while ( 1 )
    {
      v28 = &v25->m_data[v27];
      v29 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v35,
              *(signed int *)&array[4 * v28->m_partitionIdA],
              0xFFFFFFFFFFFFFFFFui64);
      if ( v28->m_partitionIdB == -1 )
        v30 = -1;
      else
        v30 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v35,
                *(signed int *)&array[4 * v28->m_partitionIdB],
                0xFFFFFFFFFFFFFFFFui64);
      if ( v29 == -1 )
      {
        if ( v30 != -1 )
          goto LABEL_38;
      }
      else
      {
        if ( v30 != -1 )
        {
          if ( v29 < v30 )
            v30 = v29;
LABEL_38:
          v28->m_materialSettingsIndex = v30;
          goto LABEL_39;
        }
        v28->m_materialSettingsIndex = v29;
      }
LABEL_39:
      ++v26;
      ++v27;
      if ( v26 >= v25->m_size )
        goto LABEL_40;
    }
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v8->m_overrideSettings.m_data;
    if ( !v13[v12].m_volume.m_pntr )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        &v35,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v13[v12].m_material,
        v11,
        &resulta);
      if ( resulta.m_enum )
        break;
    }
    ++v11;
    ++v12;
    if ( v11 >= v8->m_overrideSettings.m_size )
      goto LABEL_8;
  }
  v9->m_enum = 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v35,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v35);
  return v9;
}

// File Line: 3166
// RVA: 0xB4AFA0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::simplifySegments(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArray<int,hkContainerHeapAllocator> *segmentToOppositeMap, hkaiNavMesh *navMesh, hkBitField *unremovableVertices, hkArray<int,hkContainerHeapAllocator> *partitionDir, hkaiNavMeshGenerationProgressCallback *callbacks)
{
  __int64 v9; // r13
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v10; // rbx
  hkaiNavMeshGenerationSettings *v11; // r12
  SegmentPtrIdxKey *v12; // rdi
  hkResult *v13; // r15
  signed int v14; // er10
  int v15; // er14
  __int64 v16; // rsi
  int v17; // er9
  hkaiNavMeshSimplificationUtils::Segment *v18; // rax
  signed __int64 v19; // rdx
  __int64 v20; // rdi
  __int64 v21; // r8
  __int64 v22; // rcx
  hkArray<int,hkContainerHeapAllocator> *v23; // r11
  int v24; // er9
  int v25; // er8
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // er9
  __int64 v31; // rdx
  __int64 v32; // rcx
  int *v33; // rdi
  signed __int64 v34; // r15
  signed int v35; // er12
  int v36; // er14
  signed __int64 v37; // rsi
  bool v38; // al
  hkArray<int,hkContainerHeapAllocator> *v39; // r11
  signed __int64 v40; // r15
  __m128i v41; // xmm4
  __m128 v42; // xmm6
  unsigned int v43; // er14
  signed int v44; // esi
  int v45; // edi
  __m128 v46; // xmm3
  hkResultEnum majorAxisA; // er13
  int v48; // eax
  hkArray<int,hkContainerHeapAllocator> *v49; // r9
  hkResultEnum v50; // eax
  int v51; // er12
  int v52; // er15
  signed __int64 v53; // rcx
  hkArray<int,hkContainerHeapAllocator> *v54; // r8
  hkArray<int,hkContainerHeapAllocator> *v55; // r12
  hkVector4f *v56; // rax
  __m128 v57; // xmm4
  __m128 v58; // xmm3
  int v59; // er9
  hkResult *v60; // rdi
  int v61; // er8
  DuplicateVertexRef *v62; // rdi
  int v63; // er9
  int v64; // er9
  int v65; // er14
  int v66; // eax
  int v67; // eax
  int v68; // er9
  _DWORD *v69; // rdi
  int v70; // er8
  __int64 v71; // rdx
  int v72; // ecx
  int v73; // edi
  __int64 v74; // rsi
  hkaiNavMeshSimplificationUtils::Segment *v75; // r14
  int v76; // edi
  int v77; // er9
  int v78; // er8
  int v79; // edx
  __int64 v80; // rdi
  hkArray<int,hkContainerHeapAllocator> *v81; // r15
  unsigned __int64 v82; // r14
  signed __int64 segmentIndex; // r14
  signed int v84; // edi
  hkVector4f *v85; // rax
  __m128 v86; // xmm4
  __m128 v87; // xmm3
  hkResultEnum majorAxisB; // edx
  __int64 v89; // rcx
  hkVector4f *v90; // rax
  __m128 v91; // xmm4
  __m128 v92; // xmm3
  hkaiNavMeshSimplificationUtils::Segment *v93; // rcx
  signed __int64 v94; // r14
  signed __int64 v95; // rsi
  signed __int64 v96; // r15
  signed __int64 v97; // rdi
  int v98; // eax
  int v99; // eax
  int v100; // er9
  hkaiNavMeshSimplificationUtils::Segment *v101; // r13
  int v102; // edi
  int v103; // eax
  int v104; // eax
  int v105; // er9
  signed __int64 v106; // rdi
  signed __int64 v107; // r8
  int v108; // er8
  void *src; // [rsp+50h] [rbp-B0h]
  int v110; // [rsp+58h] [rbp-A8h]
  int v111; // [rsp+5Ch] [rbp-A4h]
  hkResult resOut; // [rsp+60h] [rbp-A0h]
  DuplicateVertexRef *pArr; // [rsp+68h] [rbp-98h]
  int v114; // [rsp+70h] [rbp-90h]
  int v115; // [rsp+74h] [rbp-8Ch]
  SegmentPtrIdxKey *array; // [rsp+80h] [rbp-80h]
  int v117; // [rsp+88h] [rbp-78h]
  int v118; // [rsp+8Ch] [rbp-74h]
  hkResult v119; // [rsp+90h] [rbp-70h]
  hkResult v120; // [rsp+94h] [rbp-6Ch]
  signed int *v121; // [rsp+98h] [rbp-68h]
  int v122; // [rsp+A0h] [rbp-60h]
  int v123; // [rsp+A4h] [rbp-5Ch]
  hkResult v124[2]; // [rsp+A8h] [rbp-58h]
  hkResult v125; // [rsp+B0h] [rbp-50h]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> parToSegIdxMap; // [rsp+B8h] [rbp-48h]
  hkSimdFloat32 v127; // [rsp+D0h] [rbp-30h]
  hkVector4f v128; // [rsp+E0h] [rbp-20h]
  hkVector4f v129; // [rsp+F0h] [rbp-10h]
  hkaiNavMeshGenerationProgressCallbackContext v130; // [rsp+100h] [rbp+0h]
  hkResult *v131; // [rsp+1E0h] [rbp+E0h]
  hkaiNavMeshGenerationSettings *settingsa; // [rsp+1E8h] [rbp+E8h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *vertices; // [rsp+1F0h] [rbp+F0h]
  hkResult resulta; // [rsp+1F8h] [rbp+F8h]

  vertices = verticesInOut;
  settingsa = settings;
  v131 = result;
  v9 = 0i64;
  v10 = segmentsInOut;
  v11 = settings;
  v12 = 0i64;
  v13 = result;
  v118 = 2147483648;
  array = 0i64;
  v14 = 0;
  v117 = 0;
  v15 = 0;
  if ( segmentsInOut->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      if ( v10->m_data[v16].m_partitionIdB != -1 )
      {
        v17 = v14 + 1;
        if ( (v118 & 0x3FFFFFFF) >= v14 + 1 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v17 < 2 * (v118 & 0x3FFFFFFF) )
            v17 = 2 * (v118 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(
            &resulta,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &array,
            v17,
            16);
          if ( resulta.m_enum )
            goto LABEL_22;
          v14 = v117;
          v12 = array;
        }
        if ( v14 == (v118 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16);
          v14 = v117;
          v12 = array;
        }
        v18 = v10->m_data;
        v117 = v14 + 1;
        v19 = (signed __int64)&v12[v14];
        *(_DWORD *)v19 = v18[v16].m_indices.m_size;
        *(_DWORD *)(v19 + 4) = v15;
        v20 = v10->m_data[v16].m_partitionIdB;
        v21 = v10->m_data[v16].m_partitionIdA;
        if ( (signed int)v21 >= (signed int)v20 )
          v22 = v21 | (v20 << 32);
        else
          v22 = v20 | (v21 << 32);
        *(_QWORD *)(v19 + 8) = v22;
        v12 = array;
        v14 = v117;
      }
      ++v15;
      ++v16;
    }
    while ( v15 < v10->m_size );
  }
  if ( v14 > 1 )
  {
    hkAlgorithm::quickSortRecursive<`anonymous namespace::SegmentPtrIdxKey,hkAlgorithm::less<`anonymous namespace::SegmentPtrIdxKey>>(
      v12,
      0,
      v14 - 1,
      0);
    v14 = v117;
    v12 = array;
  }
  v23 = segmentToOppositeMap;
  v24 = v10->m_size;
  if ( (segmentToOppositeMap->m_capacityAndFlags & 0x3FFFFFFF) >= v24 )
  {
    v119.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &v119,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      segmentToOppositeMap,
      v24,
      4);
    if ( v119.m_enum )
    {
LABEL_22:
      v25 = v118;
      v13->m_enum = 1;
      v117 = 0;
      if ( v25 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          16 * v25);
      return v13;
    }
    v14 = v117;
    v12 = array;
    v23 = segmentToOppositeMap;
  }
  v27 = v10->m_size;
  v28 = v23->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v28 < v27 )
  {
    v29 = 2 * v28;
    v30 = v10->m_size;
    if ( v27 < v29 )
      v30 = v29;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v23, v30, 4);
    v14 = v117;
    v12 = array;
    v23 = segmentToOppositeMap;
  }
  v31 = v23->m_size;
  v32 = v27 - (signed int)v31;
  if ( v27 - (signed int)v31 > 0 )
  {
    v33 = &v23->m_data[v31];
    while ( v32 )
    {
      *v33 = -1;
      ++v33;
      --v32;
    }
    v14 = v117;
    v12 = array;
  }
  v23->m_size = v27;
  resulta.m_enum = 0;
  if ( v14 - 1 > 0 )
  {
    v34 = 1i64;
    *(_QWORD *)&v124[0].m_enum = 1i64;
    v35 = 1;
    do
    {
      v36 = v35;
      if ( v35 < v14 )
      {
        v37 = v9 + 16;
        while ( *(unsigned __int64 *)((char *)&v12->m_key + v9) == *(unsigned __int64 *)((char *)&v12->m_key + v37)
             && *(int *)((char *)&v12->m_segmentSize + v9) == *(int *)((char *)&v12->m_segmentSize + v37) )
        {
          v38 = `anonymous namespace::areOppositeSegments(
                  vertices,
                  &v10->m_data[*(int *)((char *)&v12->m_index + v9)],
                  &v10->m_data[*(int *)((char *)&v12->m_index + v37)],
                  navMesh,
                  &resOut);
          if ( resOut.m_enum )
          {
            v60 = v131;
            v61 = v118;
            v117 = 0;
            v131->m_enum = 1;
            if ( v61 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                array,
                16 * v61);
            return v60;
          }
          if ( v38 )
          {
            v39 = segmentToOppositeMap;
            v40 = v34;
            segmentToOppositeMap->m_data[*(int *)((char *)&array->m_index + v9)] = array[v40].m_index;
            v39->m_data[array[v40].m_index] = *(int *)((char *)&array->m_index + v9);
            v14 = v117;
            v12 = array;
            break;
          }
          v14 = v117;
          v12 = array;
          ++v36;
          ++v34;
          v37 += 16i64;
          if ( v36 >= v117 )
            break;
        }
      }
      v34 = *(_QWORD *)&v124[0].m_enum + 1i64;
      ++v35;
      v9 += 16i64;
      ++resulta.m_enum;
      ++*(_QWORD *)&v124[0].m_enum;
    }
    while ( resulta.m_enum < v14 - 1 );
    v11 = settingsa;
    LODWORD(v9) = 0;
  }
  v117 = v9;
  if ( v118 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v12,
      16 * v118);
  v41 = _mm_load_si128((const __m128i *)&v11->m_up);
  v42 = (__m128)xmmword_141A4C9F0;
  v43 = 2147483648;
  pArr = 0i64;
  v44 = 0;
  v114 = 0;
  src = 0i64;
  v45 = 0;
  v110 = 0;
  v115 = 2147483648;
  v46 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v41, 1u), 1u);
  v111 = 2147483648;
  majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmpleps(
                                                                          _mm_max_ps(
                                                                            _mm_shuffle_ps(v46, v46, 170),
                                                                            _mm_max_ps(
                                                                              _mm_shuffle_ps(v46, v46, 85),
                                                                              _mm_shuffle_ps(v46, v46, 0))),
                                                                          v46),
                                                                        (__m128)xmmword_141A4C9F0))];
  resulta.m_enum = majorAxisA;
  v48 = _mm_movemask_ps(_mm_cmpltps((__m128)v41, (__m128)0i64));
  if ( _bittest(&v48, majorAxisA) )
  {
    majorAxisA += 3;
    resulta.m_enum = majorAxisA;
  }
  v49 = partitionDir;
  v50 = majorAxisA;
  if ( partitionDir )
    v50 = -1;
  v51 = 0;
  v119.m_enum = v50;
  v52 = 0;
  if ( v10->m_size > 0 )
  {
    v53 = 0i64;
    *(_QWORD *)&v124[0].m_enum = 0i64;
    while ( 1 )
    {
      v54 = (hkArray<int,hkContainerHeapAllocator> *)((char *)v10->m_data + v53);
      v55 = v54 + 2;
      if ( *v54[2].m_data == v54[2].m_data[v54[2].m_size - 1] )
      {
        if ( v49 )
        {
          v56 = hkaiNavMeshSimplificationUtils::_classToDir((hkVector4f *)&array, v49->m_data[SHIDWORD(v54->m_data)]);
          v57 = _mm_cmpltps(v56->m_quad, (__m128)0i64);
          v58 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v56->m_quad, 1u), 1u);
          majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                              _mm_and_ps(
                                                                                _mm_cmpleps(
                                                                                  _mm_max_ps(
                                                                                    _mm_shuffle_ps(v58, v58, 170),
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v58, v58, 85),
                                                                                      _mm_shuffle_ps(v58, v58, 0))),
                                                                                  v58),
                                                                                v42))];
          resulta.m_enum = majorAxisA;
          LODWORD(v56) = _mm_movemask_ps(v57);
          if ( _bittest((const signed int *)&v56, majorAxisA) )
          {
            majorAxisA += 3;
            resulta.m_enum = majorAxisA;
          }
        }
        v59 = v44 + 1;
        if ( (signed int)(v43 & 0x3FFFFFFF) >= v44 + 1 )
        {
          v120.m_enum = 0;
        }
        else
        {
          if ( v59 < (signed int)(2 * (v43 & 0x3FFFFFFF)) )
            v59 = 2 * (v43 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v120, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &pArr, v59, 8);
          if ( v120.m_enum )
            goto LABEL_80;
          v43 = v115;
          v44 = v114;
        }
        if ( v44 == (v43 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &pArr, 8);
          v44 = v114;
        }
        v62 = &pArr[v44];
        v114 = v44 + 1;
        LODWORD(v62->m_value) = 2
                              * (unsigned int)*(_OWORD *)&_mm_load_si128((const __m128i *)`anonymous namespace::computeSignedLoopArea(
                                                                                            &v127,
                                                                                            vertices,
                                                                                            v55,
                                                                                            majorAxisA)) >> 1;
        v62->m_index = v52;
        v45 = v110;
      }
      else
      {
        v63 = v45 + 1;
        if ( (v111 & 0x3FFFFFFF) >= v45 + 1 )
        {
          resOut.m_enum = 0;
        }
        else
        {
          if ( v63 < 2 * (v111 & 0x3FFFFFFF) )
            v63 = 2 * (v111 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resOut, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &src, v63, 4);
          if ( resOut.m_enum )
          {
LABEL_80:
            v60 = v131;
            v131->m_enum = 1;
            goto LABEL_162;
          }
          v45 = v110;
        }
        *((_DWORD *)src + v45) = v52;
        v45 = v110++ + 1;
      }
      v44 = v114;
      ++v52;
      v53 = *(_QWORD *)&v124[0].m_enum + 48i64;
      *(_QWORD *)&v124[0].m_enum += 48i64;
      if ( v52 >= v10->m_size )
        break;
      v43 = v115;
      v42 = (__m128)xmmword_141A4C9F0;
      v49 = partitionDir;
    }
    v51 = 0;
  }
  if ( v44 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
      pArr,
      0,
      v44 - 1,
      0);
    v44 = v114;
    v45 = v110;
  }
  v64 = v45 + v44;
  if ( (v111 & 0x3FFFFFFF) >= v45 + v44 )
  {
    v125.m_enum = 0;
  }
  else
  {
    if ( v64 < 2 * (v111 & 0x3FFFFFFF) )
      v64 = 2 * (v111 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v125, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &src, v64, 4);
    if ( v125.m_enum )
    {
      v60 = v131;
      v131->m_enum = 1;
LABEL_89:
      v110 = 0;
      if ( v111 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          src,
          4 * v111);
      src = 0i64;
      v114 = 0;
      goto LABEL_165;
    }
    v44 = v114;
    v45 = v110;
  }
  if ( v44 > 0 )
  {
    v65 = v45 + v44;
    v66 = v111 & 0x3FFFFFFF;
    if ( v45 + v44 > (v111 & 0x3FFFFFFF) )
    {
      if ( v66 >= v65 )
      {
        resOut.m_enum = 0;
      }
      else
      {
        v67 = 2 * v66;
        v68 = v45 + v44;
        if ( v65 < v67 )
          v68 = v67;
        hkArrayUtil::_reserve(&resOut, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &src, v68, 4);
      }
    }
    hkMemUtil::memMove((char *)src + 4 * v44, src, 4 * v45);
    v69 = src;
    v110 = v65;
    v70 = 0;
    if ( v114 > 0 )
    {
      v71 = 0i64;
      do
      {
        ++v70;
        ++v69;
        v72 = pArr[v71].m_index;
        ++v71;
        *(v69 - 1) = v72;
      }
      while ( v70 < v114 );
    }
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
  if ( !parToSegIdxMap.m_elem )
  {
LABEL_105:
    v60 = v131;
    v131->m_enum = 1;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
    goto LABEL_89;
  }
  v73 = 0;
  if ( v10->m_size > 0 )
  {
    v74 = 0i64;
    do
    {
      v75 = v10->m_data;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
        &parToSegIdxMap,
        &resOut,
        v10->m_data[v74].m_partitionIdA,
        v73);
      if ( resOut.m_enum )
        goto LABEL_105;
      if ( v75[v74].m_partitionIdB != -1 )
      {
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
          &parToSegIdxMap,
          &v120,
          v75[v74].m_partitionIdB,
          v73);
        if ( v120.m_enum )
          goto LABEL_105;
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v10->m_size );
  }
  v76 = v10->m_size;
  v121 = 0i64;
  v122 = 0;
  v123 = 2147483648;
  if ( v76 <= 0 )
  {
    resOut.m_enum = 0;
  }
  else
  {
    v77 = v76;
    if ( v76 < 0 )
      v77 = 0;
    hkArrayUtil::_reserve(&resOut, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v121, v77, 4);
    if ( resOut.m_enum )
    {
      v60 = v131;
      v78 = v123;
      v122 = 0;
      v131->m_enum = 1;
      if ( v78 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v121,
          4 * v78);
      v121 = 0i64;
      v123 = 2147483648;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
      goto LABEL_89;
    }
  }
  v122 = v76;
  v79 = 0;
  if ( v110 <= 0 )
    goto LABEL_158;
  v80 = 0i64;
  do
  {
    v80 += 4i64;
    v121[*(signed int *)((char *)src + v80 - 4)] = v79++;
  }
  while ( v79 < v110 );
  if ( v110 <= 0 )
  {
LABEL_158:
    v60 = v131;
    v131->m_enum = 0;
LABEL_159:
    v122 = 0;
    if ( v123 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v121,
        4 * v123);
    v121 = 0i64;
    v123 = 2147483648;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
LABEL_162:
    v110 = 0;
    if ( v111 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        src,
        4 * v111);
    v114 = 0;
    src = 0i64;
  }
  else
  {
    v81 = segmentToOppositeMap;
    v82 = 0i64;
    v127.m_real.m128_u64[0] = 0i64;
    while ( 1 )
    {
      hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&v130, settingsa);
      if ( callbacks )
      {
        if ( v51 == 99 * (v51 / 99)
          && !callbacks->vfptr->stepMiddleCallback(
                callbacks,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
                v51,
                v110,
                &v130) )
        {
          break;
        }
      }
      segmentIndex = *(signed int *)((char *)src + v82);
      if ( (_DWORD)segmentIndex != -1 )
      {
        v84 = v81->m_data[segmentIndex];
        if ( v84 != -1 || v10->m_data[segmentIndex].m_partitionIdB == -1 )
        {
          if ( v84 <= (signed int)segmentIndex )
            v84 = -1;
          if ( partitionDir )
          {
            v85 = hkaiNavMeshSimplificationUtils::_classToDir(
                    &v128,
                    partitionDir->m_data[v10->m_data[segmentIndex].m_partitionIdA]);
            v86 = _mm_cmpltps(v85->m_quad, (__m128)0i64);
            v87 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v85->m_quad, 1u), 1u);
            majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                _mm_and_ps(
                                                                                  _mm_cmpleps(
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v87, v87, 170),
                                                                                      _mm_max_ps(
                                                                                        _mm_shuffle_ps(v87, v87, 85),
                                                                                        _mm_shuffle_ps(v87, v87, 0))),
                                                                                    v87),
                                                                                  (__m128)xmmword_141A4C9F0))];
            resulta.m_enum = majorAxisA;
            LODWORD(v85) = _mm_movemask_ps(v86);
            if ( _bittest((const signed int *)&v85, majorAxisA) )
            {
              majorAxisA += 3;
              resulta.m_enum = majorAxisA;
            }
            majorAxisB = -1;
            v119.m_enum = -1;
            v89 = v10->m_data[segmentIndex].m_partitionIdB;
            if ( (_DWORD)v89 != -1 )
            {
              v90 = hkaiNavMeshSimplificationUtils::_classToDir(&v129, partitionDir->m_data[v89]);
              v91 = _mm_cmpltps(v90->m_quad, (__m128)0i64);
              v92 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v90->m_quad, 1u), 1u);
              majorAxisB = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                  _mm_and_ps(
                                                                                    _mm_cmpleps(
                                                                                      _mm_max_ps(
                                                                                        _mm_shuffle_ps(v92, v92, 170),
                                                                                        _mm_max_ps(
                                                                                          _mm_shuffle_ps(v92, v92, 85),
                                                                                          _mm_shuffle_ps(v92, v92, 0))),
                                                                                      v92),
                                                                                    (__m128)xmmword_141A4C9F0))];
              v119.m_enum = majorAxisB;
              LODWORD(v90) = _mm_movemask_ps(v91);
              if ( _bittest((const signed int *)&v90, majorAxisB) )
              {
                majorAxisB += 3;
                v119.m_enum = majorAxisB;
              }
            }
          }
          else
          {
            majorAxisB = v119.m_enum;
          }
          `anonymous namespace::simplifySegment(
            &resOut,
            settingsa,
            vertices,
            v10,
            (hkArrayBase<int> *)&segmentToOppositeMap->m_data,
            segmentIndex,
            majorAxisA,
            majorAxisB,
            (hkPointerMultiMap<int,int> *)&parToSegIdxMap,
            unremovableVertices);
          if ( resOut.m_enum )
          {
            v60 = v131;
            v131->m_enum = 1;
            goto LABEL_159;
          }
          if ( v84 != -1 )
          {
            v93 = v10->m_data;
            array = (SegmentPtrIdxKey *)v84;
            v94 = segmentIndex;
            v95 = v84;
            v93[v95].m_partitionIdA = v93[v94].m_partitionIdB;
            v10->m_data[v95].m_partitionIdB = v10->m_data[v94].m_partitionIdA;
            v96 = v10->m_data[v94].m_indices.m_size;
            v97 = (signed __int64)&v10->m_data[v84];
            v98 = v10->m_data[v95].m_indices.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v98 >= (signed int)v96 )
            {
              v120.m_enum = 0;
            }
            else
            {
              v99 = 2 * v98;
              v100 = v10->m_data[v94].m_indices.m_size;
              if ( (signed int)v96 < v99 )
                v100 = v99;
              hkArrayUtil::_reserve(
                &v120,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (void *)(v97 + 32),
                v100,
                4);
            }
            *(_DWORD *)(v97 + 40) = v96;
            v101 = v10->m_data;
            v102 = v96 - 1;
            v103 = v10->m_data[v95].m_boundary.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v103 >= (signed int)v96 - 1 )
            {
              v124[0].m_enum = 0;
            }
            else
            {
              v104 = 2 * v103;
              v105 = v96 - 1;
              if ( v102 < v104 )
                v105 = v104;
              hkArrayUtil::_reserve(
                v124,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v101[v95].m_boundary,
                v105,
                4);
            }
            v101[v95].m_boundary.m_size = v102;
            v106 = 0i64;
            if ( (signed int)v96 > 0 )
            {
              v107 = v96;
              do
              {
                ++v106;
                --v107;
                v10->m_data[v95].m_indices.m_data[v106 - 1] = v10->m_data[v94].m_indices.m_data[v107];
              }
              while ( v106 < v96 );
            }
            majorAxisA = resulta.m_enum;
            *((_DWORD *)src + v121[(_QWORD)array]) = -1;
          }
          v81 = segmentToOppositeMap;
        }
      }
      ++v51;
      v82 = v127.m_real.m128_u64[0] + 4;
      v127.m_real.m128_u64[0] += 4i64;
      if ( v51 >= v110 )
        goto LABEL_158;
    }
    v60 = v131;
    v108 = v123;
    v131->m_enum = 0;
    v122 = 0;
    if ( v108 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v121,
        4 * v108);
    v121 = 0i64;
    v123 = 2147483648;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
    v110 = 0;
    if ( v111 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        src,
        4 * v111);
    src = 0i64;
    v114 = 0;
  }
LABEL_165:
  v111 = 2147483648;
  if ( v115 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pArr,
      8 * v115);
  return v60;
}r->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v121,
        4 * v108);
    v121 = 0i64;
    v123 = 2147483648;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<un

// File Line: 3521
// RVA: 0xB4EA80
hkResult *__fastcall hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupOut, hkArray<int,hkContainerHeapAllocator> *edgesToRemoveOut, hkBitField *removableEdges)
{
  hkaiNavMesh *v7; // r13
  hkResult *v8; // r12
  __m128 v10; // xmm1
  __m128 v11; // xmm12
  int v12; // ecx
  int v13; // edi
  __m128 v14; // xmm11
  unsigned int v15; // edx
  __m128 v16; // xmm13
  __int64 v17; // rbx
  int v18; // er9
  int v19; // edx
  int v20; // er14
  int v21; // er15
  __int64 v22; // r12
  hkaiNavMesh::Edge *v23; // rbx
  signed __int64 v24; // rcx
  signed __int64 v25; // rdi
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  unsigned int v29; // eax
  hkResult *v30; // rdi
  int v31; // eax
  int v32; // eax
  int v33; // er9
  char *v34; // rdi
  int v35; // eax
  unsigned __int64 v36; // rcx
  __int64 v37; // rdx
  int v38; // er12
  hkaiNavMesh::Edge *v39; // r13
  signed __int64 v40; // rax
  signed __int64 v41; // rbx
  int v42; // edi
  int v43; // er14
  int v44; // er15
  int v45; // edx
  int v46; // ecx
  int v47; // er15
  __int64 v48; // rdx
  int v49; // er14
  int v50; // edx
  int v51; // ecx
  __int64 v52; // rdx
  int v53; // er14
  int v54; // er15
  __int64 v55; // rcx
  unsigned __int64 v56; // rdx
  __int64 v57; // rbx
  int v58; // eax
  int v59; // er10
  int v60; // er13
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v61; // r9
  __int64 v62; // rdx
  hkaiNavMesh::Edge *v63; // rdi
  int v64; // eax
  int v65; // edx
  int v66; // ecx
  __int64 v67; // rdx
  int v68; // ecx
  int v69; // er9
  int v70; // edi
  signed __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v72; // rax
  int v73; // edi
  unsigned int *v74; // rcx
  hkaiNavMesh::Edge *v75; // rdx
  signed __int64 v76; // r8
  hkVector4f *v77; // rcx
  int v78; // er8
  hkVector4f *v79; // rdx
  __m128 v80; // xmm6
  __m128 v81; // xmm1
  __m128 v82; // xmm5
  __m128 v83; // xmm5
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm4
  __m128 v88; // xmm7
  __m128 v89; // xmm6
  unsigned int v90; // eax
  int v91; // ebx
  int v92; // er9
  int v93; // er11
  __int64 v94; // r9
  __int64 v95; // r10
  hkaiNavMesh::Edge *v96; // rdx
  hkVector4f *v97; // r8
  signed __int64 v98; // rdi
  __int64 v99; // rcx
  int j; // edi
  hkResult *v101; // rax
  signed int v102; // edi
  __m128 v103; // xmm1
  __m128 v104; // xmm4
  __m128 v105; // xmm3
  hkVector4f *v106; // rax
  __int64 v107; // rcx
  __m128 v108; // xmm0
  __m128 v109; // xmm3
  __m128 v110; // xmm0
  __m128 v111; // xmm7
  __m128 v112; // xmm2
  __m128 v113; // xmm7
  __m128 v114; // xmm1
  __m128 v115; // xmm4
  __m128 v116; // xmm2
  __m128 v117; // xmm7
  __m128 v118; // xmm1
  __m128 v119; // xmm11
  __m128 v120; // xmm4
  float v121; // xmm1_4
  __m128 v122; // xmm6
  __m128 v123; // xmm9
  __m128 v124; // xmm2
  __m128 v125; // xmm10
  __m128 v126; // xmm6
  __m128 v127; // xmm6
  __m128 v128; // xmm8
  __m128 v129; // xmm1
  __m128 v130; // xmm5
  __m128 v131; // xmm2
  __m128 v132; // xmm4
  __m128 v133; // xmm3
  __m128 v134; // xmm6
  __m128 v135; // xmm13
  int v136; // er9
  int v137; // edx
  __int64 v138; // r8
  __int64 v139; // rcx
  __m128 v140; // xmm4
  __m128 v141; // xmm1
  __m128 v142; // xmm5
  __m128 v143; // xmm1
  __m128 v144; // xmm2
  __m128 v145; // xmm3
  __m128 v146; // xmm3
  __m128 v147; // xmm2
  __m128 v148; // xmm2
  __m128 v149; // xmm1
  __m128 v150; // xmm13
  float v151; // xmm6_4
  __int128 v152; // xmm1
  __m128 v153; // xmm7
  __m128 v154; // xmm10
  __m128 v155; // xmm11
  __m128 v156; // xmm12
  __m128 v157; // xmm1
  __m128 v158; // xmm4
  __m128 v159; // xmm3
  __m128 v160; // xmm1
  __m128 v161; // xmm4
  __m128 v162; // xmm7
  __m128 v163; // xmm9
  __m128 v164; // xmm8
  __m128 v165; // xmm1
  __m128 v166; // xmm4
  __m128 v167; // xmm2
  __m128 v168; // xmm3
  __m128 v169; // xmm6
  __m128 v170; // xmm1
  __m128 v171; // xmm5
  __m128 v172; // xmm5
  __m128 v173; // xmm1
  __m128 v174; // xmm3
  __m128 v175; // xmm2
  __m128 v176; // xmm4
  __m128 v177; // xmm13
  __m128 v178; // xmm11
  __m128 v179; // xmm10
  __m128 v180; // xmm7
  __m128 v181; // xmm8
  __m128 v182; // xmm9
  __m128 v183; // xmm1
  __m128 v184; // xmm4
  __m128 v185; // xmm2
  __m128 v186; // xmm3
  __m128 v187; // xmm6
  __m128 v188; // xmm1
  __m128 v189; // xmm3
  __m128 v190; // xmm3
  __m128 v191; // xmm1
  __m128 v192; // xmm2
  __m128 v193; // xmm0
  __m128 v194; // xmm1
  unsigned int v195; // eax
  int v196; // er8
  int v197; // er9
  int v198; // eax
  int v199; // eax
  int v200; // ecx
  int v201; // er9
  int v202; // eax
  int v203; // eax
  int v204; // er9
  __int64 v205; // r8
  __int64 v206; // rcx
  int v207; // er8
  unsigned int *a; // [rsp+30h] [rbp-D0h]
  int numtoinsert; // [rsp+38h] [rbp-C8h]
  int v210; // [rsp+3Ch] [rbp-C4h]
  char *v211; // [rsp+40h] [rbp-C0h]
  int v212; // [rsp+48h] [rbp-B8h]
  int v213; // [rsp+4Ch] [rbp-B4h]
  _DWORD *array; // [rsp+50h] [rbp-B0h]
  int numElem; // [rsp+58h] [rbp-A8h]
  int v216; // [rsp+5Ch] [rbp-A4h]
  hkArrayBase<hkVector4f> v217; // [rsp+60h] [rbp-A0h]
  hkArrayBase<hkVector2f> v218; // [rsp+70h] [rbp-90h]
  hkResult v219; // [rsp+80h] [rbp-80h]
  hkQueue<hkpRigidBody *> v220; // [rsp+88h] [rbp-78h]
  hkResult resulta; // [rsp+A0h] [rbp-60h]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v222; // [rsp+A8h] [rbp-58h]
  hkResult v223; // [rsp+B8h] [rbp-48h]
  hkResult v224; // [rsp+BCh] [rbp-44h]
  hkResult v225; // [rsp+C0h] [rbp-40h]
  hkResult v226; // [rsp+C4h] [rbp-3Ch]
  hkResult v227; // [rsp+C8h] [rbp-38h]
  hkResult v228; // [rsp+CCh] [rbp-34h]
  hkVector2f e1Out; // [rsp+D0h] [rbp-30h]
  hkVector2f e0Out; // [rsp+D8h] [rbp-28h]
  hkVector2f centerOut; // [rsp+E0h] [rbp-20h]
  hkQuaternionf quat; // [rsp+F0h] [rbp-10h]
  int v233; // [rsp+100h] [rbp+0h]
  __int64 v234; // [rsp+108h] [rbp+8h]
  int v235; // [rsp+110h] [rbp+10h]
  unsigned int v236; // [rsp+114h] [rbp+14h]
  int v237; // [rsp+118h] [rbp+18h]
  hkResult resOut; // [rsp+11Ch] [rbp+1Ch]
  hkVector4f planeOut; // [rsp+120h] [rbp+20h]
  hkVector4f extrusion; // [rsp+130h] [rbp+30h]
  hkVector4f v241; // [rsp+140h] [rbp+40h]
  __int64 v242; // [rsp+150h] [rbp+50h]
  hkResult v243; // [rsp+158h] [rbp+58h]
  hkVector4f v244; // [rsp+160h] [rbp+60h]
  hkArrayBase<hkVector4f> points; // [rsp+170h] [rbp+70h]
  hkVector4f v246; // [rsp+180h] [rbp+80h]
  hkVector4f v247; // [rsp+190h] [rbp+90h]
  hkVector4f v248; // [rsp+1D0h] [rbp+D0h]
  hkVector4f v249; // [rsp+1E0h] [rbp+E0h]
  __m128 v250; // [rsp+1F0h] [rbp+F0h]
  __m128 v251; // [rsp+200h] [rbp+100h]
  hkVector4f direction; // [rsp+210h] [rbp+110h]
  hkVector4f v253; // [rsp+220h] [rbp+120h]
  hkVector4f v254; // [rsp+230h] [rbp+130h]
  hkVector4f v255; // [rsp+240h] [rbp+140h]
  hkVector4f v256; // [rsp+250h] [rbp+150h]
  hkVector4f v257; // [rsp+260h] [rbp+160h]
  hkVector4f v258; // [rsp+270h] [rbp+170h]
  hkVector4f start; // [rsp+280h] [rbp+180h]
  hkVector4f v260; // [rsp+290h] [rbp+190h]
  hkVector4f end; // [rsp+2A0h] [rbp+1A0h]
  hkResult *v262; // [rsp+3A0h] [rbp+2A0h]
  hkaiNavMeshGenerationSettings *v263; // [rsp+3A8h] [rbp+2A8h]
  hkaiNavMesh *v264; // [rsp+3B0h] [rbp+2B0h]
  hkaiEdgeGeometryRaycaster *v265; // [rsp+3B8h] [rbp+2B8h]

  v265 = raycaster;
  v264 = mesh;
  v263 = settings;
  v262 = result;
  v7 = mesh;
  v8 = result;
  if ( !settings->m_overrideSettings.m_size && settings->m_simplificationSettings.m_boundaryEdgeFilterThreshold <= 0.0
    || !raycaster )
  {
    result->m_enum = 0;
    return result;
  }
  v10 = (__m128)LODWORD(settings->m_characterHeight);
  v11 = 0i64;
  v12 = 0;
  array = 0i64;
  v13 = 0;
  numElem = 0;
  extrusion.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v10, v10, 0)), settings->m_up.m_quad);
  v14 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(settings->m_edgeMatchingParams.m_maxStepHeight * 0.60000002),
            (__m128)COERCE_UNSIGNED_INT(settings->m_edgeMatchingParams.m_maxStepHeight * 0.60000002),
            0),
          settings->m_up.m_quad);
  v219.m_enum = LODWORD(FLOAT_0_0099999998);
  v15 = 2147483648;
  v216 = 2147483648;
  v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v251 = v14;
  v250 = v16;
  if ( mesh->m_edges.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( v7->m_edges.m_data[v17].m_oppositeEdge == -1 )
      {
        v18 = v12 + 1;
        v19 = v15 & 0x3FFFFFFF;
        if ( v19 >= v12 + 1 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          if ( v18 < 2 * v19 )
            v18 = 2 * v19;
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v18, 4);
          if ( resulta.m_enum )
          {
            v8->m_enum = 1;
            goto LABEL_18;
          }
          v12 = numElem;
        }
        array[v12] = v13;
        v15 = v216;
        v12 = numElem++ + 1;
      }
      ++v13;
      ++v17;
    }
    while ( v13 < v7->m_edges.m_size );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v222);
  if ( !v222.m_elem )
  {
    v8->m_enum = 1;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v222);
LABEL_18:
    numElem = 0;
    if ( v216 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v216);
    return v8;
  }
  v20 = numElem;
  v21 = 0;
  if ( numElem > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = v7->m_edges.m_data;
      v24 = (signed int)array[v22];
      v25 = v24;
      if ( v23[v24].m_oppositeEdge == -1 )
      {
        v26 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
                                  &v222,
                                  v23[v24].m_a,
                                  v21);
        if ( v26 > v222.m_hashMod
          && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
                &v222,
                &v219,
                v23[v25].m_a,
                v21),
              v219.m_enum)
          || (v27 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
                                        &v222,
                                        v23[v25].m_b,
                                        v21),
              v27 > v222.m_hashMod)
          && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
                &v222,
                &v223,
                v23[v25].m_b,
                v21),
              v223.m_enum) )
        {
          v30 = v262;
          v262->m_enum = 1;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v222);
          numElem = 0;
          if ( v216 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              array,
              4 * v216);
          return v30;
        }
        v20 = numElem;
      }
      ++v21;
      ++v22;
    }
    while ( v21 < v20 );
    v8 = v262;
  }
  v28 = 0;
  v29 = 2147483648;
  v211 = 0i64;
  v212 = 0;
  v213 = 2147483648;
  if ( v20 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v211, v20, 1);
    if ( resulta.m_enum )
    {
      v8->m_enum = 1;
LABEL_52:
      v212 = 0;
      if ( v213 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v211,
          v213 & 0x3FFFFFFF);
      v211 = 0i64;
      v213 = 2147483648;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v222);
      numElem = 0;
      if ( v216 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v216);
      return v8;
    }
    v20 = numElem;
    v29 = v213;
    v28 = v212;
  }
  v31 = v29 & 0x3FFFFFFF;
  if ( v31 < v20 )
  {
    v32 = 2 * v31;
    v33 = v20;
    if ( v20 < v32 )
      v33 = v32;
    hkArrayUtil::_reserve(&v226, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v211, v33, 1);
    v28 = v212;
  }
  v34 = &v211[v28];
  v35 = v20 - v28;
  v36 = v20 - v28;
  if ( v35 > 0 )
    memset(v34, 0, v36);
  v212 = v20;
  a = 0i64;
  numtoinsert = 0;
  v210 = 2147483648;
  hkArrayUtil::_reserve(&v219, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, 8, 4);
  if ( v219.m_enum )
  {
    v8->m_enum = 1;
LABEL_49:
    numtoinsert = 0;
    if ( v210 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        a,
        4 * v210);
    v210 = 2147483648;
    a = 0i64;
    goto LABEL_52;
  }
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v220);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v220, 8);
  if ( !v220.m_data )
  {
    v8->m_enum = 1;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v220);
    goto LABEL_49;
  }
  v37 = 0i64;
  v219.m_enum = 0;
  v234 = 0i64;
  if ( numElem <= 0 )
  {
LABEL_212:
    v30 = v262;
    v262->m_enum = 0;
    goto LABEL_213;
  }
  v38 = v220.m_capacity;
  while ( 1 )
  {
    if ( v211[v37] )
      goto LABEL_203;
    v211[v37] = 1;
    v39 = v7->m_edges.m_data;
    v40 = (signed int)array[v37];
    numtoinsert = 0;
    v41 = v40;
    v42 = 0;
    *a = array[v37];
    ++numtoinsert;
    *(_QWORD *)&v220.m_head = 0i64;
    v43 = 0;
    v44 = 0;
    v220.m_elementsInUse = 0;
    if ( v38 <= 0 )
    {
      v45 = 8;
      if ( v38 )
        v45 = 2 * v38;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v220, v45);
      v38 = v220.m_capacity;
      v42 = v220.m_head;
      v43 = v220.m_tail;
      v44 = v220.m_elementsInUse;
    }
    v46 = v39[v41].m_a;
    if ( v43 == v38 )
      v43 = 0;
    v47 = v44 + 1;
    v48 = v43;
    v49 = v43 + 1;
    v220.m_elementsInUse = v47;
    *((_DWORD *)v220.m_data + v48) = v46;
    v220.m_tail = v49;
    if ( v47 >= v38 )
    {
      v50 = 8;
      if ( v38 )
        v50 = 2 * v38;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v220, v50);
      v38 = v220.m_capacity;
      v42 = v220.m_head;
      v49 = v220.m_tail;
      v47 = v220.m_elementsInUse;
    }
    v51 = v39[v41].m_b;
    if ( v49 == v38 )
      v49 = 0;
    v52 = v49;
    v53 = v49 + 1;
    v54 = v47 + 1;
    v220.m_elementsInUse = v54;
    *((_DWORD *)v220.m_data + v52) = v51;
    v220.m_tail = v53;
    while ( v54 )
    {
      v55 = v42++;
      v56 = *((signed int *)v220.m_data + v55);
      if ( v42 == v38 )
        v42 = 0;
      --v54;
      v57 = *((signed int *)v220.m_data + v55);
      v220.m_head = v42;
      v220.m_elementsInUse = v54;
      v58 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                                &v222,
                                v56);
      v59 = v222.m_hashMod;
      v60 = v58;
      if ( v58 <= v222.m_hashMod )
      {
        v61 = v222.m_elem;
        do
        {
          v62 = SLODWORD(v61[v60].val);
          v242 = v62;
          if ( !v211[v62] )
          {
            v236 = array[v62];
            v63 = &v264->m_edges.m_data[v236];
            v64 = v57;
            if ( v63->m_a == (_DWORD)v57 || v63->m_b == (_DWORD)v57 )
            {
              if ( v54 >= v38 )
              {
                hkQueue<int>::setCapacity((hkQueue<int> *)&v220, 2 * v38);
                if ( !v220.m_data )
                  goto LABEL_183;
                v54 = v220.m_elementsInUse;
                v53 = v220.m_tail;
                v38 = v220.m_capacity;
                v64 = v57;
              }
              if ( v63->m_a == v64 )
                v63 = (hkaiNavMesh::Edge *)((char *)v63 + 4);
              if ( v54 >= v38 )
              {
                v65 = 8;
                if ( v38 )
                  v65 = 2 * v38;
                hkQueue<int>::setCapacity((hkQueue<int> *)&v220, v65);
                v38 = v220.m_capacity;
                v53 = v220.m_tail;
                v54 = v220.m_elementsInUse;
              }
              v66 = v63->m_a;
              if ( v53 == v38 )
                v53 = 0;
              v67 = v53++;
              v220.m_elementsInUse = ++v54;
              *((_DWORD *)v220.m_data + v67) = v66;
              v220.m_tail = v53;
            }
            v68 = numtoinsert;
            v69 = numtoinsert + 1;
            if ( (v210 & 0x3FFFFFFF) >= numtoinsert + 1 )
            {
              v224.m_enum = 0;
            }
            else
            {
              if ( v69 < 2 * (v210 & 0x3FFFFFFF) )
                v69 = 2 * (v210 & 0x3FFFFFFF);
              hkArrayUtil::_reserve(&v224, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, v69, 4);
              if ( v224.m_enum )
                goto LABEL_183;
              v68 = numtoinsert;
            }
            a[v68] = v236;
            ++numtoinsert;
            v211[v242] = 1;
            v59 = v222.m_hashMod;
            v61 = v222.m_elem;
          }
          v70 = v60 + 1;
          for ( i = v60 + 1; i > v59; i = 0i64 )
LABEL_105:
            v70 = 0;
          v72 = &v61[i];
          while ( v72->key != -1i64 )
          {
            if ( v72->key == v57 )
            {
              v60 = v70;
              goto LABEL_108;
            }
            ++i;
            ++v70;
            ++v72;
            if ( i > v59 )
              goto LABEL_105;
          }
          v60 = v59 + 1;
LABEL_108:
          ;
        }
        while ( v60 <= v59 );
        v42 = v220.m_head;
      }
    }
    v73 = numtoinsert;
    v74 = a;
    v7 = v264;
    if ( numtoinsert != 2 )
      break;
    v75 = v264->m_edges.m_data;
    v76 = (signed int)*a;
    if ( v75[*a].m_a != v75[a[1]].m_b || v75[*a].m_b != v75[a[1]].m_a )
      break;
    v77 = v264->m_vertices.m_data;
    points.m_size = numtoinsert;
    points.m_capacityAndFlags = -2147483646;
    points.m_data = &v246;
    v246.m_quad = (__m128)v77[v75[v76].m_a];
    v247.m_quad = (__m128)v77[v75[v76].m_b];
    if ( hkaiNavMeshGenerationSettings::getSimplificationSettings(v263, &points, -1)->m_boundaryEdgeFilterThreshold <= 0.0 )
    {
      v78 = points.m_capacityAndFlags;
      points.m_size = 0;
LABEL_116:
      if ( v78 < 0 )
        goto LABEL_203;
      v79 = points.m_data;
LABEL_118:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v79,
        16 * v78);
      goto LABEL_203;
    }
    v79 = points.m_data;
    v80 = points.m_data[1].m_quad;
    v81 = _mm_sub_ps(points.m_data->m_quad, v80);
    v82 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v263->m_up.m_quad, v263->m_up.m_quad, 201), v81),
            _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v263->m_up.m_quad));
    v83 = _mm_shuffle_ps(v82, v82, 201);
    v84 = _mm_mul_ps(v83, v83);
    v85 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
            _mm_shuffle_ps(v84, v84, 170));
    v86 = _mm_rsqrt_ps(v85);
    v87 = _mm_cmpltps(_mm_sub_ps(v11, v85), v11);
    v88 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v85, v11),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v86, v85), v86)),
                    _mm_mul_ps(*(__m128 *)_xmm, v86))),
                v83),
              v87),
            _mm_andnot_ps(v87, v83));
    if ( _mm_movemask_ps(v87) )
    {
      v89 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v80, points.m_data->m_quad), (__m128)xmmword_141A711B0),
                points.m_data->m_quad),
              v14);
      start.m_quad = _mm_add_ps(v89, _mm_mul_ps(v88, v16));
      end.m_quad = _mm_add_ps(v89, _mm_mul_ps(_mm_sub_ps(v11, v16), v88));
      v90 = hkaiEdgeGeometryRaycaster::castRayExtruded(v265, &start, &end, &extrusion);
      v78 = points.m_capacityAndFlags;
      points.m_size = 0;
      if ( v90 )
        goto LABEL_116;
      if ( points.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          points.m_data,
          16 * points.m_capacityAndFlags);
LABEL_177:
      if ( numEdgesInGroupOut && edgesToRemoveOut )
      {
        v197 = numEdgesInGroupOut->m_size + 1;
        v198 = numEdgesInGroupOut->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v198 >= v197 )
        {
          v227.m_enum = 0;
        }
        else
        {
          v199 = 2 * v198;
          if ( v197 < v199 )
            v197 = v199;
          hkArrayUtil::_reserve(
            &v227,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            numEdgesInGroupOut,
            v197,
            4);
          if ( v227.m_enum )
          {
LABEL_183:
            v30 = v262;
            v262->m_enum = 1;
            goto LABEL_213;
          }
        }
        numEdgesInGroupOut->m_data[numEdgesInGroupOut->m_size++] = numtoinsert;
        v200 = numtoinsert;
        v201 = numtoinsert + edgesToRemoveOut->m_size;
        v202 = edgesToRemoveOut->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v202 >= v201 )
        {
          v223.m_enum = 0;
        }
        else
        {
          v203 = 2 * v202;
          if ( v201 < v203 )
            v201 = v203;
          hkArrayUtil::_reserve(
            &v223,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            edgesToRemoveOut,
            v201,
            4);
          if ( v223.m_enum )
            goto LABEL_183;
          v200 = numtoinsert;
        }
        hkArrayBase<unsigned int>::_append(
          (hkArrayBase<unsigned int> *)edgesToRemoveOut,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          a,
          v200);
      }
      if ( removableEdges )
      {
        v204 = 0;
        if ( numtoinsert > 0 )
        {
          v205 = 0i64;
          do
          {
            ++v204;
            v206 = (signed int)a[v205];
            ++v205;
            removableEdges->m_storage.m_words.m_data[v206 >> 5] |= 1 << (v206 & 0x1F);
          }
          while ( v204 < numtoinsert );
          v38 = v220.m_capacity;
        }
      }
      goto LABEL_203;
    }
    v78 = points.m_capacityAndFlags;
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      goto LABEL_118;
LABEL_203:
    ++v234;
    if ( ++v219.m_enum >= numElem )
      goto LABEL_212;
    v14 = v251;
    v16 = v250;
    v37 = v234;
  }
  v91 = 2 * numtoinsert;
  v217.m_data = 0i64;
  v217.m_size = 0;
  v217.m_capacityAndFlags = 2147483648;
  if ( 2 * numtoinsert <= 0 )
  {
    v225.m_enum = 0;
  }
  else
  {
    v92 = 2 * numtoinsert;
    if ( v91 < 0 )
      v92 = 0;
    hkArrayUtil::_reserve(&v225, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v217, v92, 16);
    if ( v225.m_enum )
    {
      v30 = v262;
      v262->m_enum = 1;
      goto LABEL_206;
    }
    v73 = numtoinsert;
    v74 = a;
  }
  v217.m_size = v91;
  v93 = 0;
  if ( v73 > 0 )
  {
    v94 = 0i64;
    v95 = 0i64;
    while ( 1 )
    {
      v96 = v264->m_edges.m_data;
      v97 = v217.m_data;
      v98 = (signed int)v74[v95];
      ++v93;
      v99 = v96[v74[v95]].m_a;
      ++v95;
      v94 += 2i64;
      v217.m_data[v94 - 2] = v264->m_vertices.m_data[v99];
      v97[v94 - 1] = v264->m_vertices.m_data[v96[v98].m_b];
      if ( v93 >= numtoinsert )
        break;
      v74 = a;
    }
  }
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter((hkaiNavMeshSimplificationUtils::PlaneFitter *)&points);
  for ( j = 0; j < v217.m_size; ++j )
    hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(
      (hkaiNavMeshSimplificationUtils::PlaneFitter *)&points,
      &v217.m_data[j]);
  v101 = hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(
           (hkaiNavMeshSimplificationUtils::PlaneFitter *)&points,
           &v243,
           &planeOut);
  v102 = v217.m_size;
  if ( v101->m_enum == 1 )
  {
    v103 = (__m128)xmmword_141A712A0;
    v104 = v11;
    v105 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v217.m_size > 0 )
    {
      v106 = v217.m_data;
      v107 = (unsigned int)v217.m_size;
      do
      {
        v108 = v106->m_quad;
        ++v106;
        v103 = _mm_min_ps(v103, v108);
        v105 = _mm_max_ps(v105, v108);
        v104 = _mm_add_ps(v104, v108);
        --v107;
      }
      while ( v107 );
    }
    v109 = _mm_sub_ps(v105, v103);
    v110 = v11;
    v110.m128_f32[0] = (float)v217.m_size;
    v111 = *(&transform.m_quad
           + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmpleps(
                                                                         v109,
                                                                         _mm_min_ps(
                                                                           _mm_shuffle_ps(v109, v109, 170),
                                                                           _mm_min_ps(
                                                                             _mm_shuffle_ps(v109, v109, 85),
                                                                             _mm_shuffle_ps(v109, v109, 0)))),
                                                                       (__m128)xmmword_141A4C9F0))]);
    v112 = _mm_mul_ps(_mm_mul_ps(_mm_div_ps(query.m_quad, _mm_shuffle_ps(v110, v110, 0)), v104), v111);
    v113 = _mm_shuffle_ps(
             v111,
             _mm_unpackhi_ps(
               v111,
               _mm_sub_ps(
                 v11,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                   _mm_shuffle_ps(v112, v112, 170)))),
             196);
  }
  else
  {
    v113 = planeOut.m_quad;
  }
  v235 = 1065353048;
  v114 = _mm_mul_ps(v113, v113);
  v115 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
           _mm_shuffle_ps(v114, v114, 170));
  v116 = _mm_rsqrt_ps(v115);
  v117 = _mm_mul_ps(
           v113,
           _mm_andnot_ps(
             _mm_cmpleps(v115, v11),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v116, v115), v116)),
               _mm_mul_ps(v116, *(__m128 *)_xmm))));
  planeOut.m_quad = v117;
  v118 = _mm_mul_ps(v117, stru_141A71280.m_quad);
  v119 = _mm_sub_ps(v11, _mm_shuffle_ps(v117, v117, 255));
  v120 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
           _mm_shuffle_ps(v118, v118, 170));
  LODWORD(v121) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0);
  if ( v120.m128_f32[0] <= v121 )
  {
    if ( v120.m128_f32[0] < (float)(v11.m128_f32[0] - v121) )
    {
      hkQuaternionf::setFlippedRotation(&quat, &planeOut);
      v102 = v217.m_size;
      v117 = planeOut.m_quad;
      v122 = quat.m_vec.m_quad;
      goto LABEL_151;
    }
    v237 = -1082147209;
    v123 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v120), (__m128)xmmword_141A711B0);
    v124 = _mm_rsqrt_ps(v123);
    v125 = _mm_andnot_ps(
             _mm_cmpleps(v123, v11),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v124, v123), v124)),
               _mm_mul_ps(v124, *(__m128 *)_xmm)));
    v126 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v117),
             _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), stru_141A71280.m_quad));
    v127 = _mm_shuffle_ps(v126, v126, 201);
    v128 = _mm_mul_ps(v125, (__m128)xmmword_141A711B0);
    if ( v120.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0)) )
    {
      v129 = _mm_mul_ps(v127, v127);
      v130 = _mm_sub_ps(v123, v120);
      v131 = _mm_rsqrt_ps(v130);
      v132 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
               _mm_shuffle_ps(v129, v129, 170));
      v133 = _mm_rsqrt_ps(v132);
      v128 = _mm_mul_ps(
               _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v130, v11),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v131, v130), v131)),
                     _mm_mul_ps(*(__m128 *)_xmm, v131))),
                 v130),
               _mm_andnot_ps(
                 _mm_cmpleps(v132, v11),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v133, v132), v133)),
                   _mm_mul_ps(*(__m128 *)_xmm, v133))));
    }
    v134 = _mm_mul_ps(v127, v128);
    v122 = _mm_shuffle_ps(v134, _mm_unpackhi_ps(v134, _mm_mul_ps(v125, v123)), 196);
  }
  else
  {
    v122 = qi.m_vec.m_quad;
  }
  quat.m_vec.m_quad = v122;
LABEL_151:
  v135 = v11;
  v218.m_data = 0i64;
  v218.m_size = 0;
  v218.m_capacityAndFlags = 2147483648;
  if ( v102 <= 0 )
  {
    v228.m_enum = 0;
LABEL_157:
    v218.m_size = v102;
    v137 = 0;
    if ( v102 > 0 )
    {
      v138 = 0i64;
      while ( 1 )
      {
        v139 = v137++;
        ++v138;
        v140 = _mm_shuffle_ps(v122, v122, 255);
        v141 = _mm_mul_ps(v217.m_data[v138 - 1].m_quad, v117);
        v142 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     v11,
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v141, v141, 85), _mm_shuffle_ps(v141, v141, 0)),
                         _mm_shuffle_ps(v141, v141, 170)),
                       v119)),
                   v117),
                 v217.m_data[v138 - 1].m_quad);
        v143 = _mm_mul_ps(v122, v142);
        v144 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v142, v142, 201), v122),
                 _mm_mul_ps(_mm_shuffle_ps(v122, v122, 201), v142));
        v145 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                       _mm_shuffle_ps(v143, v143, 170)),
                     v122),
                   _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v140, v140), (__m128)xmmword_141A711B0), v142)),
                 _mm_mul_ps(_mm_shuffle_ps(v144, v144, 201), v140));
        v146 = _mm_add_ps(v145, v145);
        v218.m_data[v139] = (hkVector2f)v146.m128_u64[0];
        v102 = v218.m_size;
        v135 = _mm_add_ps(v135, _mm_shuffle_ps(v146, v146, 170));
        if ( v137 >= v218.m_size )
          break;
        v117 = planeOut.m_quad;
        v122 = quat.m_vec.m_quad;
      }
    }
    v147 = v11;
    v147.m128_f32[0] = (float)v102;
    centerOut = 0i64;
    v148 = _mm_shuffle_ps(v147, v147, 0);
    v149 = _mm_rcp_ps(v148);
    e0Out = 0i64;
    e1Out = 0i64;
    v150 = _mm_mul_ps(v135, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v148, v149)), v149));
    v151 = hkVector2Util::computeObb(&v218, &centerOut, &e0Out, &e1Out, &resOut);
    if ( resOut.m_enum )
      goto LABEL_209;
    v152 = LODWORD(hkaiNavMeshGenerationSettings::getSimplificationSettings(v263, &v217, -1)->m_boundaryEdgeFilterThreshold);
    if ( *(float *)&v152 <= 0.0 || v151 > *(float *)&v152 )
      goto LABEL_197;
    v153 = (__m128)LODWORD(e0Out.y);
    v154 = (__m128)LODWORD(e0Out.x);
    v155 = (__m128)LODWORD(centerOut.y);
    v156 = (__m128)LODWORD(centerOut.x);
    v155.m128_f32[0] = centerOut.y - e0Out.y;
    v156.m128_f32[0] = centerOut.x - e0Out.x;
    v153.m128_f32[0] = e0Out.y + centerOut.y;
    v157 = v155;
    v158 = v156;
    v158.m128_f32[0] = (float)(centerOut.x - e0Out.x) + e1Out.x;
    v157.m128_f32[0] = (float)(centerOut.y - e0Out.y) + e1Out.y;
    v154.m128_f32[0] = e0Out.x + centerOut.x;
    v159 = v157;
    v160 = v153;
    v160.m128_f32[0] = (float)(e0Out.y + centerOut.y) + e1Out.y;
    v153.m128_f32[0] = (float)(e0Out.y + centerOut.y) - e1Out.y;
    v156.m128_f32[0] = (float)(centerOut.x - e0Out.x) - e1Out.x;
    direction.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v158, v150), _mm_unpacklo_ps(v159, (__m128)0i64));
    v161 = v154;
    v161.m128_f32[0] = (float)(e0Out.x + centerOut.x) + e1Out.x;
    v154.m128_f32[0] = (float)(e0Out.x + centerOut.x) - e1Out.x;
    v155.m128_f32[0] = (float)(centerOut.y - e0Out.y) - e1Out.y;
    v254.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v161, v150), _mm_unpacklo_ps(v160, (__m128)0i64));
    v258.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v154, v150), _mm_unpacklo_ps(v153, (__m128)0i64));
    v256.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v156, v150), _mm_unpacklo_ps(v155, (__m128)0i64));
    hkVector4f::setRotatedInverseDir(&v253, &quat, &direction);
    hkVector4f::setRotatedInverseDir(&v260, &quat, &v254);
    hkVector4f::setRotatedInverseDir(&v255, &quat, &v258);
    hkVector4f::setRotatedInverseDir(&v257, &quat, &v256);
    v162 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v255.m_quad, v260.m_quad), (__m128)xmmword_141A711B0), v260.m_quad);
    v241.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v260.m_quad, v253.m_quad), (__m128)xmmword_141A711B0), v253.m_quad);
    v248.m_quad = v162;
    v11 = 0i64;
    v233 = 953267991;
    v163 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v253.m_quad, v257.m_quad), (__m128)xmmword_141A711B0), v257.m_quad);
    v249.m_quad = v163;
    v164 = _mm_sub_ps(v163, v162);
    v244.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v257.m_quad, v255.m_quad), (__m128)xmmword_141A711B0), v255.m_quad);
    v165 = _mm_mul_ps(v164, v164);
    v166 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v165, v165, 85), _mm_shuffle_ps(v165, v165, 0)),
             _mm_shuffle_ps(v165, v165, 170));
    v167 = _mm_rsqrt_ps(v166);
    v168 = _mm_andnot_ps(
             _mm_cmpleps(v166, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v167, v166), v167)),
               _mm_mul_ps(v167, *(__m128 *)_xmm)));
    v169 = _mm_mul_ps(v164, v168);
    if ( (float)(v168.m128_f32[0] * v166.m128_f32[0]) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
    {
      v170 = _mm_sub_ps(v162, v163);
      v171 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v263->m_up.m_quad, v263->m_up.m_quad, 201), v170),
               _mm_mul_ps(_mm_shuffle_ps(v170, v170, 201), v263->m_up.m_quad));
      v172 = _mm_shuffle_ps(v171, v171, 201);
      v173 = _mm_mul_ps(v172, v172);
      v174 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v173, v173, 85), _mm_shuffle_ps(v173, v173, 0)),
               _mm_shuffle_ps(v173, v173, 170));
      v175 = _mm_rsqrt_ps(v174);
      v176 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v174), (__m128)0i64);
      v169 = _mm_or_ps(
               _mm_and_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v174, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v175, v174), v175)),
                       _mm_mul_ps(v175, *(__m128 *)_xmm))),
                   v172),
                 v176),
               _mm_andnot_ps(v176, v172));
      if ( !_mm_movemask_ps(v176) )
        goto LABEL_197;
      v162 = _mm_add_ps(v162, _mm_mul_ps(v164, (__m128)xmmword_141A711B0));
      v163 = v162;
    }
    v177 = v250;
    v178 = v251;
    v179 = _mm_sub_ps((__m128)0i64, v250);
    v249.m_quad = _mm_add_ps(_mm_mul_ps(v169, v250), _mm_add_ps(v163, v251));
    v248.m_quad = _mm_add_ps(_mm_add_ps(v162, v251), _mm_mul_ps(v169, v179));
    if ( hkaiEdgeGeometryRaycaster::castRayExtruded(v265, &v248, &v249, &extrusion) )
    {
LABEL_197:
      v196 = v218.m_capacityAndFlags;
      v218.m_size = 0;
LABEL_198:
      if ( v196 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v218.m_data,
          8 * v196);
      v218.m_data = 0i64;
      v218.m_capacityAndFlags = 2147483648;
      v217.m_size = 0;
      if ( v217.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v217.m_data,
          16 * v217.m_capacityAndFlags);
      v217.m_data = 0i64;
      v217.m_capacityAndFlags = 2147483648;
      goto LABEL_203;
    }
    v180 = v244.m_quad;
    v181 = v241.m_quad;
    v226.m_enum = 953267991;
    v182 = _mm_sub_ps(v244.m_quad, v241.m_quad);
    v183 = _mm_mul_ps(v182, v182);
    v184 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v183, v183, 85), _mm_shuffle_ps(v183, v183, 0)),
             _mm_shuffle_ps(v183, v183, 170));
    v185 = _mm_rsqrt_ps(v184);
    v186 = _mm_andnot_ps(
             _mm_cmpleps(v184, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v185, v184), v185)),
               _mm_mul_ps(v185, *(__m128 *)_xmm)));
    v187 = _mm_mul_ps(v182, v186);
    if ( (float)(v186.m128_f32[0] * v184.m128_f32[0]) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
    {
      v188 = _mm_sub_ps(v241.m_quad, v244.m_quad);
      v189 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v263->m_up.m_quad, v263->m_up.m_quad, 201), v188),
               _mm_mul_ps(_mm_shuffle_ps(v188, v188, 201), v263->m_up.m_quad));
      v190 = _mm_shuffle_ps(v189, v189, 201);
      v191 = _mm_mul_ps(v190, v190);
      v192 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v191, v191, 85), _mm_shuffle_ps(v191, v191, 0)),
               _mm_shuffle_ps(v191, v191, 170));
      v193 = _mm_rsqrt_ps(v192);
      v194 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v192), (__m128)0i64);
      v187 = _mm_or_ps(
               _mm_and_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v192, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v192, v193), v193)),
                       _mm_mul_ps(*(__m128 *)_xmm, v193))),
                   v190),
                 v194),
               _mm_andnot_ps(v194, v190));
      if ( !_mm_movemask_ps(v194) )
        goto LABEL_197;
      v180 = _mm_add_ps(_mm_mul_ps(v182, (__m128)xmmword_141A711B0), v241.m_quad);
      v181 = v180;
    }
    v244.m_quad = _mm_add_ps(_mm_mul_ps(v187, v177), _mm_add_ps(v180, v178));
    v241.m_quad = _mm_add_ps(_mm_add_ps(v181, v178), _mm_mul_ps(v187, v179));
    v195 = hkaiEdgeGeometryRaycaster::castRayExtruded(v265, &v241, &v244, &extrusion);
    v196 = v218.m_capacityAndFlags;
    v218.m_size = 0;
    if ( v195 )
      goto LABEL_198;
    if ( v218.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v218.m_data,
        8 * v218.m_capacityAndFlags);
    v218.m_data = 0i64;
    v218.m_capacityAndFlags = 2147483648;
    v217.m_size = 0;
    if ( v217.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v217.m_data,
        16 * v217.m_capacityAndFlags);
    v217.m_data = 0i64;
    v217.m_capacityAndFlags = 2147483648;
    goto LABEL_177;
  }
  v136 = v102;
  if ( v102 < 0 )
    v136 = 0;
  hkArrayUtil::_reserve(&v228, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v218, v136, 8);
  if ( v228.m_enum == HK_SUCCESS )
  {
    v117 = planeOut.m_quad;
    v122 = quat.m_vec.m_quad;
    goto LABEL_157;
  }
LABEL_209:
  v30 = v262;
  v207 = v218.m_capacityAndFlags;
  v218.m_size = 0;
  v262->m_enum = 1;
  if ( v207 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v218.m_data,
      8 * v207);
  v218.m_data = 0i64;
  v218.m_capacityAndFlags = 2147483648;
LABEL_206:
  v217.m_size = 0;
  if ( v217.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v217.m_data,
      16 * v217.m_capacityAndFlags);
  v217.m_data = 0i64;
  v217.m_capacityAndFlags = 2147483648;
LABEL_213:
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v220);
  numtoinsert = 0;
  if ( v210 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      a,
      4 * v210);
  v212 = 0;
  v210 = 2147483648;
  a = 0i64;
  if ( v213 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v211,
      v213 & 0x3FFFFFFF);
  v211 = 0i64;
  v213 = 2147483648;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v222);
  numElem = 0;
  if ( v216 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v216);
  return v30;
}cator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v216);
  return v30;
}

// File Line: 3901
// RVA: 0xB58880
_BOOL8 __fastcall canMergeVertexPair(hkaiNavMeshSimplificationUtils::Settings *simplificationSettings, int vertComponentIdx, hkVector4f *unmergedVertexA, hkVector4f *unmergedVertexB, hkVector4f *mergedVertex, bool aIsBoundary, bool bIsBoundary)
{
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  float v14; // xmm8_4
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  float v17; // xmm3_4
  float v18; // xmm2_4
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  int v21; // edx
  int v22; // edx
  __m128 v23; // xmm5
  float v24; // xmm7_4
  char *v25; // rax
  float v26; // xmm8_4
  float v27; // xmm7_4
  __m128 v28; // xmm2
  float v29; // xmm3_4
  __m128 v30; // xmm2
  char *v32; // rax
  char *v33; // rdx
  __m128 v34; // xmm4
  float v35; // xmm2_4
  __m128 v36; // xmm4
  char *v37; // rcx

  v7 = unmergedVertexB->m_quad;
  v8 = unmergedVertexA->m_quad;
  v9 = mergedVertex->m_quad;
  v10 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], mergedVertex->m_quad);
  v11 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], unmergedVertexA->m_quad);
  v13 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], unmergedVertexB->m_quad);
  LODWORD(v14) = *(unsigned __int128 *)&_mm_shuffle_ps(v11, v11, 177) | v11.m128_i32[0];
  v15 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v16 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  LODWORD(v17) = *(unsigned __int128 *)&_mm_shuffle_ps(v15, v15, 177) | v15.m128_i32[0];
  LODWORD(v18) = *(unsigned __int128 *)&_mm_shuffle_ps(v16, v16, 177) | v16.m128_i32[0];
  switch ( vertComponentIdx )
  {
    case 1:
      v19 = _mm_shuffle_ps(_mm_unpacklo_ps(v9, (__m128)0i64), v9, 228);
      break;
    case 2:
      v19 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, (__m128)0i64), 180);
      break;
    case 3:
      v19 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v9, 4), 4);
      break;
    default:
      v19 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v9, 4), 4);
      break;
  }
  switch ( vertComponentIdx )
  {
    case 1:
      v20 = _mm_shuffle_ps(_mm_unpacklo_ps(v8, (__m128)0i64), v8, 228);
      break;
    case 2:
      v20 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, (__m128)0i64), 180);
      break;
    case 3:
      v20 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v8, 4), 4);
      break;
    default:
      v20 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v8, 4), 4);
      break;
  }
  v21 = vertComponentIdx - 1;
  if ( v21 )
  {
    v22 = v21 - 1;
    if ( v22 )
    {
      if ( v22 == 1 )
        v23 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v7, 4), 4);
      else
        v23 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v7, 4), 4);
    }
    else
    {
      v23 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 180);
    }
  }
  else
  {
    v23 = _mm_shuffle_ps(_mm_unpacklo_ps(v7, (__m128)0i64), v7, 228);
  }
  v24 = v14;
  v25 = (char *)&simplificationSettings->m_maxBoundaryVertexHorizontalError;
  LODWORD(v26) = (unsigned int)(2 * COERCE_SIGNED_INT(v14 - v18)) >> 1;
  LODWORD(v27) = (unsigned int)(2 * COERCE_SIGNED_INT(v24 - v17)) >> 1;
  if ( !aIsBoundary )
    v25 = (char *)&simplificationSettings->m_maxSharedVertexHorizontalError;
  v28 = _mm_sub_ps(v19, v20);
  LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)v25, (__m128)*(unsigned int *)v25, 0);
  v30 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) > (float)(v29 * v29) )
    return 0i64;
  v32 = (char *)&simplificationSettings->m_maxBoundaryVertexVerticalError;
  if ( !aIsBoundary )
    v32 = (char *)&simplificationSettings->m_maxSharedVertexVerticalError;
  if ( v27 > COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)v32, (__m128)*(unsigned int *)v32, 0)) )
    return 0i64;
  v33 = (char *)&simplificationSettings->m_maxBoundaryVertexHorizontalError;
  if ( !bIsBoundary )
    v33 = (char *)&simplificationSettings->m_maxSharedVertexHorizontalError;
  v34 = _mm_sub_ps(v19, v23);
  LODWORD(v35) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)v33, (__m128)*(unsigned int *)v33, 0);
  v36 = _mm_mul_ps(v34, v34);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170))) > (float)(v35 * v35) )
    return 0i64;
  if ( bIsBoundary )
    v37 = (char *)&simplificationSettings->m_maxBoundaryVertexVerticalError;
  else
    v37 = (char *)&simplificationSettings->m_maxSharedVertexVerticalError;
  return v26 <= COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)v37, (__m128)*(unsigned int *)v37, 0));
}

// File Line: 3936
// RVA: 0xB4E140
hkResult *__fastcall hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *mesh)
{
  hkResult *v3; // r14
  hkaiNavMesh *v4; // rbx
  hkaiNavMeshGenerationSettings *v5; // r12
  int v7; // er13
  int v8; // er15
  int v9; // esi
  __int32 v10; // eax
  _DWORD *v11; // rdi
  signed int v12; // er8
  int v13; // er9
  __int64 i; // rcx
  int v15; // er10
  __int64 v16; // r8
  hkaiNavMesh::Edge *v17; // r9
  signed __int64 v18; // rdi
  int v19; // esi
  __m128 v20; // xmm3
  hkLifoAllocator *v21; // rax
  int *v22; // rcx
  int v23; // edi
  char *v24; // rdx
  unsigned int v25; // ecx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  int *v28; // rdx
  __int64 v29; // rsi
  hkaiNavMesh::Edge *v30; // r14
  signed __int64 v31; // rax
  hkVector4f *v32; // rcx
  signed __int64 v33; // r15
  signed __int64 v34; // rax
  __int128 v35; // xmm0
  signed __int64 v36; // rax
  hkaiNavMeshSimplificationUtils::Settings *v37; // rax
  __int64 v38; // r15
  _DWORD *v39; // r12
  __int64 v40; // rcx
  hkaiNavMeshSimplificationUtils::Settings *v41; // r10
  __m128 v42; // xmm0
  __int64 v43; // rcx
  __int64 v44; // rdx
  hkVector4f *v45; // rcx
  unsigned int v46; // er9
  __int64 v47; // r15
  __int64 v48; // r14
  hkVector4f *v49; // rcx
  int v50; // er9
  int v51; // eax
  int v52; // esi
  int v53; // ecx
  int v54; // er9
  char *v55; // rdi
  __int64 v56; // rcx
  int *v57; // rdi
  int v58; // er11
  __int64 v59; // rsi
  __int64 v60; // r8
  __int64 v61; // r10
  __int64 v62; // rdx
  __m128 v63; // xmm2
  __int64 v64; // rcx
  __m128 v65; // xmm1
  __int64 v66; // rax
  __int64 v67; // rdx
  __m128 v68; // xmm1
  __int64 v69; // rcx
  int v70; // er8
  __int64 v71; // rdi
  hkaiNavMesh::Edge *v72; // rdx
  __int64 v73; // rcx
  int *v74; // rbx
  signed int v75; // edi
  _DWORD *array; // [rsp+40h] [rbp-C0h]
  int v77; // [rsp+48h] [rbp-B8h]
  int v78; // [rsp+4Ch] [rbp-B4h]
  int v79; // [rsp+50h] [rbp-B0h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+58h] [rbp-A8h]
  hkArray<int,hkContainerHeapAllocator> orderedGroups; // [rsp+68h] [rbp-98h]
  char *v82; // [rsp+78h] [rbp-88h]
  int v83; // [rsp+80h] [rbp-80h]
  int v84; // [rsp+84h] [rbp-7Ch]
  hkFixedArray<int> parents; // [rsp+88h] [rbp-78h]
  hkResult v86[2]; // [rsp+98h] [rbp-68h]
  hkResult v87; // [rsp+A0h] [rbp-60h]
  hkResult v88; // [rsp+A4h] [rbp-5Ch]
  hkResult resulta; // [rsp+A8h] [rbp-58h]
  hkUnionFind v90; // [rsp+B0h] [rbp-50h]
  __int64 v91; // [rsp+C8h] [rbp-38h]
  hkArrayBase<hkVector4f> points; // [rsp+D0h] [rbp-30h]
  __int128 v93; // [rsp+E0h] [rbp-20h]
  hkVector4f v94; // [rsp+F0h] [rbp-10h]
  hkVector4f v95; // [rsp+100h] [rbp+0h]
  hkVector4f v96; // [rsp+110h] [rbp+10h]
  hkVector4f mergedVertex; // [rsp+120h] [rbp+20h]
  hkVector4f unmergedVertexB; // [rsp+130h] [rbp+30h]
  hkVector4f unmergedVertexA; // [rsp+140h] [rbp+40h]
  hkVector4f v100; // [rsp+150h] [rbp+50h]
  hkVector4f v101; // [rsp+160h] [rbp+60h]
  hkVector4f v102; // [rsp+170h] [rbp+70h]
  hkaiNavMesh mesha; // [rsp+180h] [rbp+80h]
  hkResult *v104; // [rsp+270h] [rbp+170h]
  hkaiNavMeshGenerationSettings *v105; // [rsp+278h] [rbp+178h]
  hkResult v106; // [rsp+288h] [rbp+188h]

  v105 = settings;
  v104 = result;
  v3 = result;
  v4 = mesh;
  v5 = settings;
  hkaiNavMesh::hkaiNavMesh(&mesha);
  hkaiNavMesh::copy(&mesha, &resulta, v4);
  if ( resulta.m_enum || (hkaiNavMeshSimplificationUtils::mergeSharedVertices(&v106, &mesha), v106.m_enum) )
  {
    v3->m_enum = 1;
    hkaiNavMesh::~hkaiNavMesh(&mesha);
    return v3;
  }
  v7 = 0;
  v8 = v4->m_vertices.m_size;
  array = 0i64;
  v77 = 0;
  v9 = (v8 + 31) >> 5;
  v78 = 2147483648;
  v10 = v9;
  if ( v9 )
  {
    v106.m_enum = 4 * v9;
    v11 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      (int *)&v106);
    v10 = v106.m_enum / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 2147483648;
  array = v11;
  if ( v10 )
    v12 = v10;
  v77 = (v8 + 31) >> 5;
  v79 = v8;
  v78 = v12;
  if ( (v12 & 0x3FFFFFFF) < v9 )
  {
    v13 = (v8 + 31) >> 5;
    if ( v9 < 2 * (v12 & 0x3FFFFFFF) )
      v13 = 2 * (v12 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v106, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 4);
    v12 = v78;
    v11 = array;
  }
  v77 = (v8 + 31) >> 5;
  if ( v11 )
  {
    if ( v9 - 1 >= 0 )
    {
      for ( i = (unsigned int)v9; i; --i )
      {
        *v11 = 0;
        ++v11;
      }
      v11 = array;
    }
    v15 = 0;
    if ( v4->m_edges.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        v17 = v4->m_edges.m_data;
        if ( v17[v16].m_oppositeEdge == -1 )
        {
          v11[(signed __int64)v17[v16].m_a >> 5] |= 1 << (v17[v16].m_a & 0x1F);
          v18 = (signed __int64)v17[v16].m_b >> 5;
          array[v18] |= 1 << (v17[v16].m_b & 0x1F);
          v11 = array;
        }
        ++v15;
        ++v16;
      }
      while ( v15 < v4->m_edges.m_size );
    }
    v19 = v4->m_vertices.m_size;
    v20 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v5->m_up), 1u), 1u);
    v106.m_enum = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                         _mm_and_ps(
                                                                           _mm_cmpleps(
                                                                             _mm_max_ps(
                                                                               _mm_shuffle_ps(v20, v20, 170),
                                                                               _mm_max_ps(
                                                                                 _mm_shuffle_ps(v20, v20, 85),
                                                                                 _mm_shuffle_ps(v20, v20, 0))),
                                                                             v20),
                                                                           (__m128)xmmword_141A4C9F0))];
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (int *)v21->m_cur;
    v23 = (4 * v19 + 127) & 0xFFFFFF80;
    v24 = (char *)v22 + v23;
    if ( v23 > v21->m_slabSize || v24 > v21->m_end )
      v22 = (int *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
    else
      v21->m_cur = v24;
    parents.m_data.m_storage = v22;
    parents.m_size.m_storage = v19;
    if ( v19 > 0 && !v22 )
    {
      v25 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v3->m_enum = 1;
      v26 = (hkLifoAllocator *)TlsGetValue(v25);
      v27 = (v23 + 15) & 0xFFFFFFF0;
      if ( v23 <= v26->m_slabSize && (void *)v27 == v26->m_cur && v26->m_firstNonLifoEnd )
      {
        v26->m_cur = 0i64;
LABEL_96:
        v77 = 0;
        if ( v78 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * v78);
        array = 0i64;
        goto LABEL_99;
      }
      v28 = 0i64;
      goto LABEL_95;
    }
    hkUnionFind::hkUnionFind(&v90, &parents, v19);
    v90.m_isCollapsed = 0;
    if ( v4->m_edges.m_size > 0 )
    {
      v29 = 0i64;
      do
      {
        v30 = v4->m_edges.m_data;
        v31 = (signed int)v30[v29].m_oppositeEdge;
        if ( (_DWORD)v31 != -1 )
        {
          v32 = v4->m_vertices.m_data;
          v33 = v31;
          points.m_size = 4;
          points.m_capacityAndFlags = -2147483644;
          points.m_data = (hkVector4f *)&v93;
          v34 = v30[v29].m_a;
          v91 = v33 * 5;
          v35 = (__int128)v32[v34];
          v36 = v30[v29].m_b;
          v93 = v35;
          v94.m_quad = (__m128)v32[v36];
          v95.m_quad = (__m128)v32[v30[v33].m_a];
          v96.m_quad = (__m128)v32[v30[v33].m_b];
          v37 = hkaiNavMeshGenerationSettings::getSimplificationSettings(v5, &points, -1);
          v38 = v30[v33].m_b;
          v39 = array;
          v40 = mesha.m_edges.m_data[v29].m_a;
          v41 = v37;
          *(_QWORD *)&v86[0].m_enum = v37;
          v42 = mesha.m_vertices.m_data[v40].m_quad;
          v43 = mesha.m_edges.m_data[v29].m_b;
          mergedVertex.m_quad = v42;
          v44 = v30[v29].m_a;
          v101.m_quad = (__m128)mesha.m_vertices.m_data[v43];
          if ( (_DWORD)v44 != (_DWORD)v38 )
          {
            v45 = v4->m_vertices.m_data;
            unmergedVertexA.m_quad = (__m128)v45[v44];
            v46 = array[v38 >> 5];
            unmergedVertexB.m_quad = (__m128)v45[v38];
            if ( canMergeVertexPair(
                   v37,
                   v106.m_enum,
                   &unmergedVertexA,
                   &unmergedVertexB,
                   &mergedVertex,
                   (array[v44 >> 5] >> (v44 & 0x1F)) & 1,
                   (v46 >> (v38 & 0x1F)) & 1) )
            {
              hkUnionFind::addEdge(&v90, v30[v29].m_a, v38);
              v39 = array;
            }
            v41 = *(hkaiNavMeshSimplificationUtils::Settings **)&v86[0].m_enum;
          }
          v47 = v30[v29].m_b;
          v48 = *(&v30->m_a + v91);
          if ( (_DWORD)v47 != (_DWORD)v48 )
          {
            v49 = v4->m_vertices.m_data;
            v100.m_quad = (__m128)v49[v47];
            v102.m_quad = (__m128)v49[v48];
            if ( canMergeVertexPair(
                   v41,
                   v106.m_enum,
                   &v100,
                   &v102,
                   &v101,
                   (v39[v47 >> 5] >> (v47 & 0x1F)) & 1,
                   (v39[v48 >> 5] >> (v48 & 0x1F)) & 1) )
            {
              hkUnionFind::addEdge(&v90, v47, v48);
            }
          }
          points.m_size = 0;
          if ( points.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              points.m_data,
              16 * points.m_capacityAndFlags);
          v5 = v105;
        }
        ++v7;
        ++v29;
      }
      while ( v7 < v4->m_edges.m_size );
      v3 = v104;
    }
    elementsPerGroup.m_data = 0i64;
    elementsPerGroup.m_size = 0;
    elementsPerGroup.m_capacityAndFlags = 2147483648;
    orderedGroups.m_data = 0i64;
    orderedGroups.m_size = 0;
    orderedGroups.m_capacityAndFlags = 2147483648;
    hkUnionFind::assignGroups(&v90, &v88, &elementsPerGroup);
    if ( v88.m_enum )
    {
      v3->m_enum = 1;
LABEL_86:
      orderedGroups.m_size = 0;
      if ( orderedGroups.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          orderedGroups.m_data,
          4 * orderedGroups.m_capacityAndFlags);
      elementsPerGroup.m_size = 0;
      orderedGroups.m_capacityAndFlags = 2147483648;
      orderedGroups.m_data = 0i64;
      if ( elementsPerGroup.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          elementsPerGroup.m_data,
          4 * elementsPerGroup.m_capacityAndFlags);
      v74 = parents.m_data.m_storage;
      elementsPerGroup.m_data = 0i64;
      elementsPerGroup.m_capacityAndFlags = 2147483648;
      v75 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
      v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v27 = (v75 + 15) & 0xFFFFFFF0;
      if ( v75 <= v26->m_slabSize && (char *)v74 + v27 == v26->m_cur && v26->m_firstNonLifoEnd != v74 )
      {
        v26->m_cur = v74;
        goto LABEL_96;
      }
      v28 = v74;
LABEL_95:
      hkLifoAllocator::slowBlockFree(v26, v28, v27);
      goto LABEL_96;
    }
    hkUnionFind::sortByGroupId(&v90, &v87, &elementsPerGroup, &orderedGroups);
    if ( v87.m_enum )
    {
      v3->m_enum = 1;
      goto LABEL_86;
    }
    v50 = v4->m_vertices.m_size;
    v51 = 0;
    v82 = 0i64;
    v83 = 0;
    v84 = 2147483648;
    if ( v50 <= 0 )
    {
      v106.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(&v106, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v82, v50, 4);
      if ( v106.m_enum )
      {
        v3->m_enum = 1;
LABEL_83:
        v83 = 0;
        if ( v84 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v82,
            4 * v84);
        v84 = 2147483648;
        v82 = 0i64;
        goto LABEL_86;
      }
      v51 = v83;
    }
    v52 = v4->m_vertices.m_size;
    v53 = v84 & 0x3FFFFFFF;
    if ( (v84 & 0x3FFFFFFF) < v52 )
    {
      v54 = v4->m_vertices.m_size;
      if ( v52 < 2 * v53 )
        v54 = 2 * v53;
      hkArrayUtil::_reserve(v86, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v82, v54, 4);
      v51 = v83;
    }
    v55 = &v82[4 * v51];
    v56 = v52 - v51;
    if ( v56 > 0 )
    {
      while ( v56 )
      {
        *(_DWORD *)v55 = -1;
        v55 += 4;
        --v56;
      }
    }
    v57 = orderedGroups.m_data;
    v83 = v52;
    v58 = 0;
    if ( elementsPerGroup.m_size > 0 )
    {
      v59 = 0i64;
      do
      {
        v60 = 0i64;
        v61 = elementsPerGroup.m_data[v59];
        if ( (signed int)v61 > 0 )
        {
          do
          {
            v62 = v57[v60++];
            *(_DWORD *)&v82[4 * v62] = *v57;
          }
          while ( v60 < v61 );
        }
        if ( (signed int)v61 > 1 )
        {
          v63 = 0i64;
          v64 = 0i64;
          v65 = 0i64;
          if ( (signed int)v61 > 0 )
          {
            do
            {
              v66 = v57[v64++];
              v65 = _mm_add_ps(v65, v4->m_vertices.m_data[v66].m_quad);
            }
            while ( v64 < v61 );
          }
          v63.m128_f32[0] = (float)(signed int)v61;
          v67 = 0i64;
          v68 = _mm_mul_ps(v65, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v63, v63, 0)));
          if ( (signed int)v61 > 0 )
          {
            do
            {
              v69 = v57[v67++];
              v4->m_vertices.m_data[v69].m_quad = v68;
            }
            while ( v67 < v61 );
          }
        }
        ++v58;
        ++v59;
        v57 += v61;
      }
      while ( v58 < elementsPerGroup.m_size );
    }
    v70 = 0;
    if ( v4->m_edges.m_size > 0 )
    {
      v71 = 0i64;
      do
      {
        v72 = v4->m_edges.m_data;
        ++v70;
        v73 = v72[v71].m_a;
        ++v71;
        v72[v71 - 1].m_a = *(_DWORD *)&v82[4 * v73];
        *((_DWORD *)&v72[v71] - 4) = *(_DWORD *)&v82[4 * *((signed int *)&v72[v71] - 4)];
      }
      while ( v70 < v4->m_edges.m_size );
    }
    v3->m_enum = 0;
    goto LABEL_83;
  }
  v3->m_enum = 1;
  v77 = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      0i64,
      4 * v12);
  array = 0i64;
LABEL_99:
  v78 = 2147483648;
  hkaiNavMesh::~hkaiNavMesh(&mesha);
  return v3;
}

// File Line: 4089
// RVA: 0xB58AF0
void __fastcall mergeDegenerateSharedEdges(hkaiNavMesh *mesh)
{
  int v1; // edx
  __int64 v2; // r8
  hkaiNavMesh::Edge *v3; // rbx
  __int64 v4; // rax
  int v5; // er9
  int v6; // er10
  bool v7; // di

  v1 = 0;
  if ( mesh->m_edges.m_size > 0 )
  {
    v2 = 0i64;
    do
    {
      v3 = mesh->m_edges.m_data;
      v4 = (signed int)v3[v2].m_oppositeEdge;
      if ( (_DWORD)v4 != -1 )
      {
        v5 = v3[v2].m_a;
        v6 = v3[v4].m_a;
        v7 = v6 == v3[v4].m_b;
        if ( v5 == v3[v2].m_b )
        {
          if ( !v7 )
          {
            v3[v4].m_b = v5;
            v3[v4].m_a = v5;
          }
        }
        else if ( v7 )
        {
          v3[v2].m_b = v6;
          v3[v2].m_a = v6;
        }
      }
      ++v1;
      ++v2;
    }
    while ( v1 < mesh->m_edges.m_size );
  }
}

// File Line: 4116
// RVA: 0xB58B80
hkResult *__fastcall removeDegenerateEdges(hkResult *result, hkaiNavMesh *mesh)
{
  int v2; // esi
  hkaiNavMesh *v3; // rbx
  hkResult *v4; // r12
  int v5; // edi
  __int32 v6; // eax
  _DWORD *v7; // rcx
  signed int v8; // er8
  int v9; // er9
  __int64 v10; // r8
  void *v11; // rdx
  int v13; // eax
  _DWORD *v14; // rdi
  __int64 i; // rcx
  int v16; // er10
  __int64 v17; // r11
  int v18; // edi
  hkaiNavMesh::Face *v19; // r8
  int v20; // er9
  int v21; // ecx
  hkaiNavMesh::Edge *v22; // rdx
  int v23; // esi
  int v24; // er9
  int v25; // er8
  int v26; // er9
  int v27; // edi
  __int64 v28; // r8
  int v29; // er8
  __int64 v30; // r9
  hkaiNavMesh::Face *v31; // rdi
  __int64 v32; // rdx
  int v33; // edi
  __int64 v34; // r8
  hkaiNavMesh::Edge *v35; // r9
  __int64 v36; // rdx
  int v37; // edi
  __int64 v38; // rsi
  int v39; // esi
  signed __int64 v40; // r14
  int v41; // edx
  __int64 v42; // rdi
  hkaiNavMesh::Edge *v43; // r8
  unsigned int v44; // ecx
  int v45; // er14
  __int64 v46; // r15
  hkaiNavMesh::Face *v47; // r8
  __int16 v48; // di
  __int64 v49; // rdx
  hkaiNavMesh::Edge *v50; // r10
  signed __int64 v51; // rsi
  signed __int64 v52; // r11
  __int64 v53; // rax
  signed __int64 v54; // r9
  signed __int64 v55; // rcx
  signed int v56; // edx
  hkaiNavMesh::Edge *v57; // rdi
  __int64 v58; // rax
  int v59; // er9
  _DWORD *v60; // [rsp+30h] [rbp-48h]
  int v61; // [rsp+38h] [rbp-40h]
  int v62; // [rsp+3Ch] [rbp-3Ch]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+40h] [rbp-38h]
  _DWORD *array; // [rsp+50h] [rbp-28h]
  int v65; // [rsp+58h] [rbp-20h]
  int v66; // [rsp+5Ch] [rbp-1Ch]
  int v67; // [rsp+60h] [rbp-18h]
  hkResult resulta; // [rsp+B8h] [rbp+40h]
  hkResult v69; // [rsp+C0h] [rbp+48h]

  v2 = mesh->m_edges.m_size;
  v3 = mesh;
  v4 = result;
  v66 = 2147483648;
  v5 = (v2 + 31) >> 5;
  array = 0i64;
  v65 = 0;
  v6 = v5;
  if ( v5 )
  {
    resulta.m_enum = 4 * v5;
    v7 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     (int *)&resulta);
    v6 = resulta.m_enum / 4;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 2147483648;
  array = v7;
  if ( v6 )
    v8 = v6;
  v65 = (v2 + 31) >> 5;
  v67 = v2;
  v66 = v8;
  if ( (v8 & 0x3FFFFFFF) < v5 )
  {
    v9 = (v2 + 31) >> 5;
    if ( v5 < 2 * (v8 & 0x3FFFFFFF) )
      v9 = 2 * (v8 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v9, 4);
    v8 = v66;
  }
  v65 = (v2 + 31) >> 5;
  if ( !array )
  {
    v4->m_enum = 1;
    v65 = 0;
    if ( v8 >= 0 )
    {
      v10 = (unsigned int)(4 * v8);
      v11 = 0i64;
LABEL_13:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v11,
        v10);
      return v4;
    }
    return v4;
  }
  v13 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    v14 = array;
    for ( i = (unsigned int)(v13 + 1); i; --i )
    {
      *v14 = 0;
      ++v14;
    }
  }
  v16 = 0;
  if ( v3->m_faces.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      v18 = 0;
      v19 = &v3->m_faces.m_data[v17];
      v20 = v19->m_numEdges;
      if ( v20 > 0 )
      {
        do
        {
          v21 = v18 + v19->m_startEdgeIndex;
          v22 = &v3->m_edges.m_data[v21];
          if ( v22->m_a == v22->m_b )
          {
            array[(signed __int64)v21 >> 5] |= 1 << (v21 & 0x1F);
            --v19->m_numEdges;
          }
          ++v18;
        }
        while ( v18 < v20 );
      }
      ++v16;
      ++v17;
    }
    while ( v16 < v3->m_faces.m_size );
  }
  v23 = v3->m_edges.m_size;
  v60 = 0i64;
  v61 = 0;
  v62 = 2147483648;
  if ( v23 <= 0 )
  {
    resulta.m_enum = 0;
LABEL_34:
    v61 = v23;
    v26 = 0;
    v27 = 0;
    if ( v23 > 0 )
    {
      v28 = 0i64;
      do
      {
        v60[v28] = v26;
        if ( (array[(signed __int64)v27 >> 5] >> (v27 & 0x1F)) & 1 )
          ++v26;
        ++v27;
        ++v28;
      }
      while ( v27 < v61 );
    }
    v29 = 0;
    if ( v3->m_faces.m_size > 0 )
    {
      v30 = 0i64;
      do
      {
        v31 = v3->m_faces.m_data;
        ++v29;
        v32 = v31[v30].m_startEdgeIndex;
        ++v30;
        v31[v30 - 1].m_startEdgeIndex = v32 - v60[v32];
      }
      while ( v29 < v3->m_faces.m_size );
    }
    v33 = 0;
    if ( v3->m_edges.m_size > 0 )
    {
      v34 = 0i64;
      do
      {
        v35 = v3->m_edges.m_data;
        v36 = (signed int)v35[v34].m_oppositeEdge;
        if ( (_DWORD)v36 != -1 )
          v35[v34].m_oppositeEdge = v36 - v60[v36];
        ++v33;
        ++v34;
      }
      while ( v33 < v3->m_edges.m_size );
    }
    v37 = v3->m_edges.m_size - 1;
    if ( v37 >= 0 )
    {
      v38 = v37;
      do
      {
        if ( (array[v38 >> 5] >> (v37 & 0x1F)) & 1 )
          hkaiNavMesh::removeEdgeAtAndCopy(v3, v37);
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    v39 = v3->m_faces.m_size - 1;
    if ( v39 >= 0 )
    {
      v40 = v39;
      do
      {
        if ( !v3->m_faces.m_data[v40].m_numEdges )
        {
          hkaiNavMesh::removeFaceAtAndCopy(v3, v39);
          v41 = 0;
          if ( v3->m_edges.m_size > 0 )
          {
            v42 = 0i64;
            do
            {
              v43 = v3->m_edges.m_data;
              v44 = v43[v42].m_oppositeFace;
              if ( v44 != -1 && (signed int)(v44 & 0x3FFFFF) > v39 )
                v43[v42].m_oppositeFace = v44 - 1;
              ++v41;
              ++v42;
            }
            while ( v41 < v3->m_edges.m_size );
          }
        }
        --v40;
        --v39;
      }
      while ( v39 >= 0 );
    }
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 2147483648;
    v45 = 0;
    if ( v3->m_faces.m_size > 0 )
    {
      v46 = 0i64;
      do
      {
        v47 = &v3->m_faces.m_data[v46];
        v48 = v47->m_numEdges;
        if ( v48 < 3 )
        {
          if ( v48 != 2
            || (v49 = v47->m_startEdgeIndex,
                v50 = v3->m_edges.m_data,
                v51 = (signed __int64)&v50[v49],
                v52 = (signed __int64)&v50[(signed int)v49 + 1],
                v53 = *(signed int *)(v51 + 8),
                (_DWORD)v53 == -1)
            || (v54 = *(signed int *)(v52 + 8), (_DWORD)v54 == -1) )
          {
            v56 = 0;
            if ( v48 > 0 )
            {
              do
              {
                v57 = v3->m_edges.m_data;
                v58 = (signed int)v57[v56 + v47->m_startEdgeIndex].m_oppositeEdge;
                if ( (_DWORD)v58 != -1 )
                  *(_QWORD *)&v57[v58].m_oppositeEdge = -1i64;
                ++v56;
              }
              while ( v56 < v47->m_numEdges );
            }
          }
          else
          {
            v50[v53].m_oppositeEdge = v54;
            v55 = v54;
            v50[v55].m_oppositeEdge = *(_DWORD *)(v51 + 8);
            v50[v53].m_oppositeFace = *(_DWORD *)(v52 + 12);
            v50[v55].m_oppositeFace = *(_DWORD *)(v51 + 12);
          }
          v59 = facesToRemove.m_size + 1;
          if ( (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) >= facesToRemove.m_size + 1 )
          {
            resulta.m_enum = 0;
          }
          else
          {
            if ( v59 < 2 * (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
              v59 = 2 * (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF);
            hkArrayUtil::_reserve(
              &resulta,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              &facesToRemove,
              v59,
              4);
            if ( resulta.m_enum )
              goto LABEL_82;
          }
          facesToRemove.m_data[facesToRemove.m_size] = v45;
          ++facesToRemove.m_size;
        }
        ++v45;
        ++v46;
      }
      while ( v45 < v3->m_faces.m_size );
    }
    hkaiNavMeshUtils::removeFaces(&v69, v3, &facesToRemove, 0);
    if ( v69.m_enum )
LABEL_82:
      v4->m_enum = 1;
    else
      v4->m_enum = 0;
    facesToRemove.m_size = 0;
    if ( facesToRemove.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        facesToRemove.m_data,
        4 * facesToRemove.m_capacityAndFlags);
    facesToRemove.m_data = 0i64;
    facesToRemove.m_capacityAndFlags = 2147483648;
    v61 = 0;
    if ( v62 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v60,
        4 * v62);
    v60 = 0i64;
    v62 = 2147483648;
    v65 = 0;
    if ( v66 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        4 * v66);
    return v4;
  }
  v24 = v23;
  if ( v23 < 0 )
    v24 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v60, v24, 4);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_34;
  v25 = v62;
  v4->m_enum = 1;
  v61 = 0;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v60,
      4 * v25);
  v60 = 0i64;
  v62 = 2147483648;
  v65 = 0;
  if ( v66 >= 0 )
  {
    v11 = array;
    v10 = (unsigned int)(4 * v66);
    goto LABEL_13;
  }
  return v4;
}

// File Line: 4253
// RVA: 0xB59140
hkResult *__fastcall findUnremovableVertices(hkResult *result, hkaiNavMesh *navMesh, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitions, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments, hkBitField *unremovableVerticesOut)
{
  hkArray<int,hkContainerHeapAllocator> *v6; // rbx
  hkArray<int,hkContainerHeapAllocator> *v7; // r13
  hkResult *v8; // rsi
  unsigned int *v9; // rdi
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v11; // r9
  hkaiNavMesh *v13; // r10
  __int64 v14; // r12
  int v15; // er14
  signed int *v16; // rsi
  signed __int64 v17; // rdi
  signed __int64 v18; // rbx
  int v19; // edi
  _DWORD *v20; // r11
  int v21; // er9
  hkResult *v22; // rdi
  int v23; // er8
  bool v24; // zf
  bool v25; // sf
  int *v26; // r8
  int v27; // edx
  __int64 v28; // rcx
  __int64 v29; // rdi
  __int64 v30; // rax
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v31; // rax
  int v32; // ecx
  __int64 v33; // rdi
  __int64 v34; // rax
  int v35; // edx
  int v36; // er15
  __int64 v37; // r13
  signed int *v38; // r8
  hkaiNavMesh::Edge *v39; // rdi
  __int64 v40; // rsi
  int v41; // er12
  int v42; // er14
  int v43; // eax
  int v44; // edx
  int v45; // edi
  signed __int64 j; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v47; // rax
  int v48; // er8
  hkResult resulta; // [rsp+30h] [rbp-50h]
  __int64 v50; // [rsp+38h] [rbp-48h]
  __int64 v51; // [rsp+40h] [rbp-40h]
  _DWORD *array; // [rsp+48h] [rbp-38h]
  int v53; // [rsp+50h] [rbp-30h]
  int v54; // [rsp+54h] [rbp-2Ch]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v55; // [rsp+58h] [rbp-28h]
  hkResult *v56; // [rsp+B0h] [rbp+30h]
  hkaiNavMesh *v57; // [rsp+B8h] [rbp+38h]
  hkArray<int,hkContainerHeapAllocator> *v58; // [rsp+C8h] [rbp+48h]

  v58 = partitions;
  v57 = navMesh;
  v56 = result;
  v6 = partitions;
  v7 = numFacesInPartition;
  v8 = result;
  if ( unremovableVerticesOut->m_storage.m_words.m_size - 1 >= 0 )
  {
    v9 = unremovableVerticesOut->m_storage.m_words.m_data;
    for ( i = (unsigned int)unremovableVerticesOut->m_storage.m_words.m_size; i; --i )
    {
      *v9 = 0;
      ++v9;
    }
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v55);
  if ( !v55.m_elem )
  {
    v8->m_enum = 1;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v55);
    return v8;
  }
  v13 = v57;
  v14 = 0i64;
  v15 = 0;
  if ( v57->m_faces.m_size > 0 )
  {
    while ( 1 )
    {
      v16 = (int *)((char *)&v13->m_faces.m_data->m_startEdgeIndex + v14);
      v17 = *v16;
      if ( (signed int)v17 < (signed int)v17 + *((signed __int16 *)v16 + 4) )
        break;
LABEL_12:
      ++v15;
      v14 += 16i64;
      if ( v15 >= v13->m_faces.m_size )
      {
        v6 = v58;
        v8 = v56;
        LODWORD(v14) = 0;
        goto LABEL_14;
      }
    }
    v18 = v17;
    while ( 1 )
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
        &v55,
        &resulta,
        v13->m_edges.m_data[v18].m_a,
        v15);
      if ( resulta.m_enum )
        break;
      v13 = v57;
      LODWORD(v17) = v17 + 1;
      ++v18;
      if ( (signed int)v17 >= *v16 + *((signed __int16 *)v16 + 4) )
        goto LABEL_12;
    }
    v22 = v56;
    v56->m_enum = 1;
    goto LABEL_59;
  }
LABEL_14:
  v19 = v13->m_faces.m_size;
  v20 = 0i64;
  array = 0i64;
  v53 = 0;
  v54 = 2147483648;
  if ( v19 <= 0 )
  {
    resulta.m_enum = (signed int)v14;
    goto LABEL_24;
  }
  v21 = v19;
  if ( v19 < 0 )
    v21 = v14;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v21, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v20 = array;
    v13 = v57;
LABEL_24:
    v24 = v7->m_size == 0;
    v25 = v7->m_size < 0;
    v26 = v6->m_data;
    v53 = v19;
    v27 = v14;
    if ( !v25 && !v24 )
    {
      v11 = 0i64;
      do
      {
        v28 = 0i64;
        v29 = *(signed int *)((char *)&v11->key + (unsigned __int64)v7->m_data);
        if ( v29 > 0 )
        {
          do
          {
            v30 = v26[v28++];
            v20[v30] = v27;
            v20 = array;
          }
          while ( v28 < v29 );
        }
        ++v27;
        v11 = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)((char *)v11 + 4);
        v26 += v29;
      }
      while ( v27 < v7->m_size );
    }
    v31 = segments;
    v32 = v14;
    v24 = segments->m_size == 0;
    v25 = segments->m_size < 0;
    resulta.m_enum = (signed int)v14;
    if ( !v25 && !v24 )
    {
      v33 = 0i64;
      v50 = 0i64;
      do
      {
        v34 = (__int64)v31->m_data + v33;
        v51 = v34;
        if ( *(_DWORD *)(v34 + 8) != -1 )
        {
          v35 = *(_DWORD *)(v34 + 24);
          v36 = v14;
          if ( v35 > 0 )
          {
            v37 = 0i64;
            do
            {
              v38 = *(signed int **)(v34 + 16);
              v39 = v13->m_edges.m_data;
              v40 = v39[v38[v37]].m_b;
              v11 = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)&v39[v38[v37]];
              if ( v36 != v35 - 1 || (_DWORD)v40 == v39[*v38].m_a )
              {
                v41 = v20[v39[SLODWORD(v11->val)].m_oppositeFace];
                v42 = v20[SHIDWORD(v11->val)];
                v43 = (unsigned __int64)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                                          &v55,
                                          v39[v38[v37]].m_b);
                v20 = array;
                if ( v43 <= v55.m_hashMod )
                {
                  v11 = v55.m_elem;
                  while ( 1 )
                  {
                    v44 = array[SLODWORD(v55.m_elem[v43].val)];
                    if ( v44 != v41 && v44 != v42 )
                      break;
                    v45 = v43 + 1;
                    for ( j = v43 + 1; j > v55.m_hashMod; j = 0i64 )
LABEL_46:
                      v45 = 0;
                    v47 = &v55.m_elem[j];
                    while ( v47->key != -1i64 )
                    {
                      if ( v47->key == v40 )
                      {
                        v43 = v45;
                        goto LABEL_49;
                      }
                      ++j;
                      ++v45;
                      ++v47;
                      if ( j > v55.m_hashMod )
                        goto LABEL_46;
                    }
                    v43 = v55.m_hashMod + 1;
LABEL_49:
                    if ( v43 > v55.m_hashMod )
                      goto LABEL_52;
                  }
                  unremovableVerticesOut->m_storage.m_words.m_data[v40 >> 5] |= 1 << (v40 & 0x1F);
                  v20 = array;
                }
LABEL_52:
                v13 = v57;
              }
              v34 = v51;
              ++v36;
              ++v37;
              v35 = *(_DWORD *)(v51 + 24);
            }
            while ( v36 < v35 );
            v32 = resulta.m_enum;
            v33 = v50;
            LODWORD(v14) = 0;
          }
        }
        v31 = segments;
        ++v32;
        v33 += 48i64;
        resulta.m_enum = v32;
        v50 = v33;
      }
      while ( v32 < segments->m_size );
    }
    v22 = v56;
    v48 = v54;
    v53 = v14;
    v56->m_enum = v14;
    if ( v48 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v20,
        (unsigned int)(4 * v48),
        v11);
    array = 0i64;
    v54 = 2147483648;
LABEL_59:
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v55);
    return v22;
  }
  v23 = v54;
  v8->m_enum = 1;
  v53 = v14;
  if ( v23 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v23);
  array = 0i64;
  v54 = 2147483648;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v55);
  return v8;
}

// File Line: 4326
// RVA: 0xB4CA10
hkaiNavMeshSimplificationUtils::SimplificationResult __fastcall hkaiNavMeshSimplificationUtils::simplifyNavMesh(hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMesh, hkaiNavMesh *navMeshOut, hkaiNavMeshGenerationProgressCallback *callback)
{
  return hkaiNavMeshSimplificationUtils::_simplifyNavMesh(settings, navMesh, navMeshOut, 0i64, callback);
}

// File Line: 4332
// RVA: 0xB4CA30
hkaiNavMeshSimplificationUtils::SimplificationResult __fastcall hkaiNavMeshSimplificationUtils::simplifyWallClimbingNavMesh(hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMesh, hkaiNavMesh *navMeshOut, hkaiNavMeshGenerationProgressCallback *callback)
{
  return hkaiNavMeshSimplificationUtils::_simplifyNavMesh(settings, navMesh, navMeshOut, 0i64, callback);
}

// File Line: 4341
// RVA: 0xB4CA50
__int64 __fastcall hkaiNavMeshSimplificationUtils::_simplifyNavMesh(hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMesh, hkaiNavMesh *navMeshOut, hkaiEdgeGeometryRaycaster *raycaster, hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  hkaiNavMesh *v5; // r13
  bool v6; // r14
  hkaiNavMeshGenerationSettings *v7; // r15
  hkaiNavMeshGenerationProgressCallback *callbacks; // r12
  hkaiEdgeGeometryRaycaster *v9; // rdi
  hkaiNavMesh *v10; // rsi
  unsigned int v11; // er14
  int v12; // er14
  int v13; // edi
  int v14; // eax
  void *v15; // r8
  unsigned int v16; // ecx
  int v17; // ecx
  int v18; // er9
  int v19; // er14
  int v20; // edi
  int v21; // ecx
  unsigned int *v22; // r8
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // er9
  __int64 v27; // rcx
  unsigned int *v28; // rdi
  int i; // er15
  int v30; // eax
  hkArray<int,hkContainerHeapAllocator> *v31; // rax
  int v32; // er15
  int v33; // edi
  hkResultEnum v34; // eax
  float *v35; // rcx
  int v36; // ecx
  int v37; // ecx
  int v38; // er9
  int v39; // er15
  int v40; // er9
  int v41; // eax
  float *v42; // rdi
  __int64 j; // rcx
  int v44; // er8
  signed int v45; // edi
  __int64 v46; // r9
  __int64 v47; // rdx
  hkaiNavMesh::Edge *v48; // rax
  int v49; // edi
  int v50; // er9
  __int64 v51; // rdx
  int k; // edi
  unsigned int v53; // ecx
  int v54; // er8
  int v55; // eax
  int v56; // er8
  int v57; // edi
  int v58; // er9
  int v59; // er8
  __int64 v60; // rdi
  __int64 v61; // r9
  hkaiNavMesh::Edge *v62; // rcx
  __int64 v63; // rax
  __int64 v64; // rdx
  __int64 v65; // rcx
  int v66; // edi
  __int64 v67; // rdx
  __int64 v68; // rax
  __int64 v69; // r8
  signed __int64 v70; // r12
  hkaiNavMesh::Edge *v71; // r11
  int v72; // er10
  int v73; // er8
  signed __int64 v74; // r8
  __int64 v75; // r8
  __int64 v76; // r8
  unsigned int v77; // eax
  int v78; // er9
  int v79; // edx
  int v80; // er15
  int v81; // eax
  int v82; // eax
  int v83; // er9
  char *v84; // rdi
  __int64 v85; // rcx
  int v86; // er9
  __int64 v87; // rdi
  hkaiNavMesh::Face *v88; // r8
  __int64 v89; // rcx
  signed __int64 v90; // rdx
  int v91; // er15
  unsigned int v92; // eax
  int v93; // edx
  int v94; // eax
  int v95; // eax
  int v96; // er9
  char *v97; // rdi
  __int64 v98; // rcx
  int v99; // edx
  __int64 v100; // rdi
  __int64 v101; // rax
  int v102; // eax
  __int64 v103; // r9
  __int64 v104; // r8
  __int64 v105; // r10
  hkaiNavMesh::Edge *v106; // r15
  __int64 v107; // rdx
  __int64 v108; // rdi
  signed __int64 v109; // rcx
  hkaiNavMesh::Edge *v110; // rdx
  signed __int64 v111; // rdi
  __int64 v112; // rax
  const float *v113; // r9
  hkResult *v114; // rcx
  int v115; // edi
  __int64 l; // r8
  int v117; // esi
  hkaiNavMeshSimplificationUtils::Segment *v118; // rdi
  hkResult v120; // [rsp+70h] [rbp-90h]
  EdgeKey *pArr; // [rsp+78h] [rbp-88h]
  int v122; // [rsp+80h] [rbp-80h]
  int v123; // [rsp+84h] [rbp-7Ch]
  char *v124; // [rsp+88h] [rbp-78h]
  int v125; // [rsp+90h] [rbp-70h]
  int v126; // [rsp+94h] [rbp-6Ch]
  char *v127; // [rsp+98h] [rbp-68h]
  int v128; // [rsp+A0h] [rbp-60h]
  int v129; // [rsp+A4h] [rbp-5Ch]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> segmentsOut; // [rsp+A8h] [rbp-58h]
  hkArrayBase<unsigned int> faceData; // [rsp+B8h] [rbp-48h]
  hkArray<int,hkContainerHeapAllocator> numEdgesInGroupOut; // [rsp+C8h] [rbp-38h]
  hkArray<int,hkContainerHeapAllocator> oppositeEdges; // [rsp+D8h] [rbp-28h]
  hkArray<int,hkContainerHeapAllocator> numFacesInPartition; // [rsp+E8h] [rbp-18h]
  hkArray<int,hkContainerHeapAllocator> partitions; // [rsp+F8h] [rbp-8h]
  hkResult v136; // [rsp+108h] [rbp+8h]
  hkResult v137; // [rsp+10Ch] [rbp+Ch]
  hkResult v138; // [rsp+110h] [rbp+10h]
  hkResult v139; // [rsp+114h] [rbp+14h]
  hkArray<int,hkContainerHeapAllocator> edgesToRemoveOut; // [rsp+118h] [rbp+18h]
  int v141; // [rsp+128h] [rbp+28h]
  hkResult v142; // [rsp+12Ch] [rbp+2Ch]
  hkArray<int,hkContainerHeapAllocator> partitionDir; // [rsp+130h] [rbp+30h]
  hkaMatrix<float> edgeIsBoundary; // [rsp+140h] [rbp+40h]
  hkArray<int,hkContainerHeapAllocator> faceToPartitionMapInOut; // [rsp+158h] [rbp+58h]
  hkArray<int,hkContainerHeapAllocator> segmentToOppositeMap; // [rsp+168h] [rbp+68h]
  void *array; // [rsp+178h] [rbp+78h]
  int v148; // [rsp+180h] [rbp+80h]
  unsigned int v149; // [rsp+184h] [rbp+84h]
  int v150; // [rsp+188h] [rbp+88h]
  hkBitField unremovableVertices; // [rsp+190h] [rbp+90h]
  hkResult v152; // [rsp+1A8h] [rbp+A8h]
  hkResult v153; // [rsp+1ACh] [rbp+ACh]
  hkResult v154; // [rsp+1B0h] [rbp+B0h]
  hkResult v155; // [rsp+1B4h] [rbp+B4h]
  hkResult v156; // [rsp+1B8h] [rbp+B8h]
  hkResult v157; // [rsp+1BCh] [rbp+BCh]
  hkResult v158; // [rsp+1C0h] [rbp+C0h]
  hkResult v159; // [rsp+1C4h] [rbp+C4h]
  hkResult result; // [rsp+1C8h] [rbp+C8h]
  hkaiNavMeshGenerationProgressCallback *v161; // [rsp+1D0h] [rbp+D0h]
  hkPointerMap<int,int,hkContainerHeapAllocator> vertexIndexMapOut; // [rsp+1D8h] [rbp+D8h]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > userVertexOnBoundary; // [rsp+1E8h] [rbp+E8h]
  hkaiNavMeshGenerationProgressCallbackContext v164; // [rsp+200h] [rbp+100h]
  hkResult v165; // [rsp+270h] [rbp+170h]
  hkResult v166; // [rsp+274h] [rbp+174h]
  hkResult v167; // [rsp+278h] [rbp+178h]
  char v168; // [rsp+27Ch] [rbp+17Ch]
  void **v169; // [rsp+280h] [rbp+180h]
  hkResult v170; // [rsp+288h] [rbp+188h]
  hkaiNavMesh origMesh; // [rsp+290h] [rbp+190h]
  hkaiNavMeshGenerationSettings *settingsa; // [rsp+380h] [rbp+280h]
  bool v173; // [rsp+388h] [rbp+288h]

  settingsa = settings;
  v5 = navMesh;
  v6 = settings->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v169 = &hkaiNavMeshGenerationProgressCallback::`vftable;
  v7 = settings;
  callbacks = (hkaiNavMeshGenerationProgressCallback *)&v169;
  v9 = raycaster;
  if ( _callbacks )
    callbacks = _callbacks;
  v10 = navMeshOut;
  v173 = v6;
  v161 = callbacks;
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&v164, settings);
  v164.m_originalMesh = v5;
  v164.m_simplifiedMesh = v5;
  if ( !callbacks->vfptr->stepStartedCallback(callbacks, END|BEGIN|0x8, &v164)
    || !callbacks->vfptr->stepEndedCallback(callbacks, END|BEGIN|0x8, &v164) )
  {
    return 0i64;
  }
  v10->m_vertices.m_size = 0;
  v10->m_faces.m_size = 0;
  v10->m_faceData.m_size = 0;
  v10->m_edges.m_size = 0;
  v10->m_edgeData.m_size = 0;
  v10->m_erosionRadius = v5->m_erosionRadius;
  hkaiNavMesh::hkaiNavMesh(&origMesh);
  numFacesInPartition.m_data = 0i64;
  numFacesInPartition.m_size = 0;
  numFacesInPartition.m_capacityAndFlags = 2147483648;
  partitionDir.m_data = 0i64;
  partitionDir.m_size = 0;
  partitionDir.m_capacityAndFlags = 2147483648;
  partitions.m_data = 0i64;
  partitions.m_size = 0;
  partitions.m_capacityAndFlags = 2147483648;
  edgesToRemoveOut.m_data = 0i64;
  edgesToRemoveOut.m_size = 0;
  edgesToRemoveOut.m_capacityAndFlags = 2147483648;
  if ( !v7->m_simplificationSettings.m_useHeightPartitioning.m_bool
    || !v7->m_simplificationSettings.m_useConservativeHeightPartitioning.m_bool
    || (hkaiNavMesh::copy(&origMesh, &result, v5), result.m_enum == HK_SUCCESS) )
  {
    if ( !callbacks->vfptr->stepStartedCallback(
            callbacks,
            (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)12i64,
            &v164) )
    {
      v11 = 0;
      goto LABEL_280;
    }
    if ( !v6 )
    {
      hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices(&v120, v7, v5);
      if ( v120.m_enum )
      {
        v11 = 1;
        goto LABEL_280;
      }
      mergeDegenerateSharedEdges(v5);
      removeDegenerateEdges(&v120, v5);
      if ( v120.m_enum )
      {
        v11 = 1;
        goto LABEL_280;
      }
    }
    if ( !callbacks->vfptr->stepEndedCallback(
            callbacks,
            (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)12i64,
            &v164) )
    {
      v11 = 0;
      goto LABEL_280;
    }
    if ( v6 )
    {
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_280;
      }
      v164.m_numFacesInPartition = (hkArrayBase<int> *)&numFacesInPartition;
      v164.m_partitions = (hkArrayBase<int> *)&partitions;
      hkaiNavMeshSimplificationUtils::partitionWC(v5, &origMesh, v7, &numFacesInPartition, &partitionDir, &partitions);
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_280;
      }
LABEL_38:
      segmentsOut.m_data = 0i64;
      segmentsOut.m_size = 0;
      segmentsOut.m_capacityAndFlags = 2147483648;
      v164.m_segments = (hkArrayBase<hkaiNavMeshSimplificationUtils::Segment> *)&segmentsOut;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)15i64,
              &v164) )
      {
        v11 = 0;
LABEL_274:
        v117 = segmentsOut.m_size - 1;
        if ( segmentsOut.m_size - 1 >= 0 )
        {
          v118 = &segmentsOut.m_data[v117];
          do
          {
            hkaiNavMeshSimplificationUtils::Segment::`scalar deleting destructor(v118, 0);
            --v118;
            --v117;
          }
          while ( v117 >= 0 );
        }
        segmentsOut.m_size = 0;
        if ( segmentsOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            segmentsOut.m_data,
            48 * (segmentsOut.m_capacityAndFlags & 0x3FFFFFFF));
        segmentsOut.m_data = 0i64;
        segmentsOut.m_capacityAndFlags = 2147483648;
        goto LABEL_280;
      }
      hkaiNavMeshSimplificationUtils::tracePartitionBoundaries(
        &v120,
        v5,
        &numFacesInPartition,
        &partitions,
        &segmentsOut,
        &edgesToRemoveOut);
      if ( v120.m_enum )
      {
        v11 = 1;
        goto LABEL_274;
      }
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)15i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_274;
      }
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_274;
      }
      vertexIndexMapOut.m_map.m_elem = 0i64;
      vertexIndexMapOut.m_map.m_numElems = 0;
      vertexIndexMapOut.m_map.m_hashMod = -1;
      hkaiNavMeshSimplificationUtils::setSegmentIndices(&v120, v5, &segmentsOut, &v10->m_vertices, &vertexIndexMapOut);
      if ( v120.m_enum )
      {
        v11 = 1;
LABEL_273:
        hkPointerMap<int,int,hkContainerHeapAllocator>::~hkPointerMap<int,int,hkContainerHeapAllocator>((hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&vertexIndexMapOut);
        goto LABEL_274;
      }
      v12 = v5->m_vertices.m_size;
      array = 0i64;
      v148 = 0;
      v149 = 2147483648;
      v13 = (v12 + 31) >> 5;
      v14 = v13;
      if ( v13 )
      {
        LODWORD(_callbacks) = 4 * v13;
        v15 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                (int *)&_callbacks);
        v14 = (signed int)_callbacks / 4;
      }
      else
      {
        v15 = 0i64;
      }
      v16 = 2147483648;
      array = v15;
      if ( v14 )
        v16 = v14;
      v148 = (v12 + 31) >> 5;
      v150 = v12;
      v149 = v16;
      v17 = v16 & 0x3FFFFFFF;
      if ( v17 >= v13 )
      {
        v155.m_enum = 0;
      }
      else
      {
        v18 = (v12 + 31) >> 5;
        if ( v13 < 2 * v17 )
          v18 = 2 * v17;
        hkArrayUtil::_reserve(&v155, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 4);
        v15 = array;
      }
      v148 = (v12 + 31) >> 5;
      if ( !v15
        || (findUnremovableVertices(&v120, v5, &numFacesInPartition, &partitions, &segmentsOut, (hkBitField *)&array),
            v120.m_enum) )
      {
        v11 = 1;
        goto LABEL_272;
      }
      v19 = v10->m_vertices.m_size;
      unremovableVertices.m_storage.m_words.m_data = 0i64;
      unremovableVertices.m_storage.m_words.m_size = 0;
      unremovableVertices.m_storage.m_words.m_capacityAndFlags = 2147483648;
      v20 = (v19 + 31) >> 5;
      v21 = v20;
      if ( v20 )
      {
        v141 = 4 * v20;
        v22 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                &v141);
        v21 = v141 / 4;
      }
      else
      {
        v22 = 0i64;
      }
      v23 = 2147483648;
      unremovableVertices.m_storage.m_words.m_data = v22;
      if ( v21 )
        v23 = v21;
      unremovableVertices.m_storage.m_words.m_size = (v19 + 31) >> 5;
      unremovableVertices.m_storage.m_numBits = v19;
      unremovableVertices.m_storage.m_words.m_capacityAndFlags = v23;
      v24 = v23 & 0x3FFFFFFF;
      if ( v24 >= v20 )
      {
        v159.m_enum = 0;
      }
      else
      {
        v25 = 2 * v24;
        v26 = (v19 + 31) >> 5;
        if ( v20 < v25 )
          v26 = v25;
        hkArrayUtil::_reserve(
          &v159,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &unremovableVertices,
          v26,
          4);
        v22 = unremovableVertices.m_storage.m_words.m_data;
      }
      unremovableVertices.m_storage.m_words.m_size = (v19 + 31) >> 5;
      v11 = 1;
      if ( !v22 )
        goto LABEL_132;
      if ( v20 - 1 >= 0 )
      {
        v27 = (unsigned int)v20;
        v28 = v22;
        while ( v27 )
        {
          *v28 = 0;
          ++v28;
          --v27;
        }
      }
      for ( i = 0; i < v5->m_vertices.m_size; ++i )
      {
        if ( (*((_DWORD *)array + ((signed __int64)i >> 5)) >> (i & 0x1F)) & 1 )
        {
          v30 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&vertexIndexMapOut.m_map.m_elem,
                  i,
                  0xFFFFFFFFFFFFFFFFui64);
          unremovableVertices.m_storage.m_words.m_data[(signed __int64)v30 >> 5] |= 1 << (v30 & 0x1F);
        }
      }
      hkaiNavMeshSimplificationUtils::setMaterialSettingsIndices(
        &v120,
        settingsa,
        v5,
        &numFacesInPartition,
        &partitions,
        &segmentsOut);
      if ( v120.m_enum )
      {
LABEL_132:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&unremovableVertices);
LABEL_272:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&array);
        goto LABEL_273;
      }
      v31 = &partitionDir;
      if ( !v173 )
        v31 = 0i64;
      segmentToOppositeMap.m_data = 0i64;
      segmentToOppositeMap.m_size = 0;
      segmentToOppositeMap.m_capacityAndFlags = 2147483648;
      hkaiNavMeshSimplificationUtils::simplifySegments(
        &v120,
        settingsa,
        &v10->m_vertices,
        &segmentsOut,
        &segmentToOppositeMap,
        v5,
        &unremovableVertices,
        v31,
        callbacks);
      if ( v120.m_enum )
      {
LABEL_129:
        segmentToOppositeMap.m_size = 0;
        if ( segmentToOppositeMap.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            segmentToOppositeMap.m_data,
            4 * segmentToOppositeMap.m_capacityAndFlags);
        segmentToOppositeMap.m_data = 0i64;
        segmentToOppositeMap.m_capacityAndFlags = 2147483648;
        goto LABEL_132;
      }
      userVertexOnBoundary.m_storage.m_words.m_data = 0i64;
      userVertexOnBoundary.m_storage.m_words.m_size = 0;
      userVertexOnBoundary.m_storage.m_words.m_capacityAndFlags = 2147483648;
      userVertexOnBoundary.m_storage.m_numBits = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
        &userVertexOnBoundary,
        &v120,
        0,
        settingsa->m_simplificationSettings.m_extraVertexSettings.m_userVertices.m_size,
        0);
      if ( v120.m_enum )
      {
LABEL_128:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&userVertexOnBoundary);
        goto LABEL_129;
      }
      v164.m_segmentVertices = (hkArrayBase<hkVector4f> *)&v10->m_vertices.m_data;
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_128;
      }
      oppositeEdges.m_data = 0i64;
      oppositeEdges.m_size = 0;
      oppositeEdges.m_capacityAndFlags = 2147483648;
      faceToPartitionMapInOut.m_data = 0i64;
      faceToPartitionMapInOut.m_size = 0;
      faceToPartitionMapInOut.m_capacityAndFlags = 2147483648;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)17i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_123;
      }
      v32 = v5->m_edges.m_size;
      edgeIsBoundary.m_data.m_data = 0i64;
      edgeIsBoundary.m_data.m_size = 0;
      edgeIsBoundary.m_data.m_capacityAndFlags = 2147483648;
      v33 = (v32 + 31) >> 5;
      v34 = v33;
      v120.m_enum = (v32 + 31) >> 5;
      if ( v33 )
      {
        v35 = (float *)hkMemoryAllocator::_bufAlloc<unsigned int>(
                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                         (int *)&v120);
        v34 = v120.m_enum;
      }
      else
      {
        v35 = 0i64;
      }
      edgeIsBoundary.m_data.m_data = v35;
      v36 = 2147483648;
      if ( v34 )
        v36 = v34;
      edgeIsBoundary.m_data.m_size = (v32 + 31) >> 5;
      edgeIsBoundary.m_m = v32;
      edgeIsBoundary.m_data.m_capacityAndFlags = v36;
      v37 = v36 & 0x3FFFFFFF;
      if ( v37 >= v33 )
      {
        v153.m_enum = 0;
      }
      else
      {
        v38 = (v32 + 31) >> 5;
        if ( v33 < 2 * v37 )
          v38 = 2 * v37;
        hkArrayUtil::_reserve(
          &v153,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &edgeIsBoundary,
          v38,
          4);
      }
      edgeIsBoundary.m_data.m_size = (v32 + 31) >> 5;
      if ( !edgeIsBoundary.m_data.m_data )
      {
LABEL_122:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&edgeIsBoundary);
        goto LABEL_123;
      }
      v39 = v5->m_edges.m_size;
      if ( (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF) >= v39 )
      {
        v137.m_enum = 0;
      }
      else
      {
        v40 = v5->m_edges.m_size;
        if ( v39 < 2 * (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF) )
          v40 = 2 * (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &v137,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &oppositeEdges,
          v40,
          4);
        if ( v137.m_enum )
          goto LABEL_122;
        v33 = edgeIsBoundary.m_data.m_size;
      }
      v41 = v33 - 1;
      oppositeEdges.m_size = v39;
      if ( v33 - 1 >= 0 )
      {
        v42 = edgeIsBoundary.m_data.m_data;
        for ( j = (unsigned int)(v41 + 1); j; --j )
        {
          *v42 = 0.0;
          ++v42;
        }
      }
      v44 = 0;
      v45 = 1;
      if ( v5->m_edges.m_size > 0 )
      {
        v46 = 0i64;
        v47 = 0i64;
        do
        {
          v48 = v5->m_edges.m_data;
          if ( v48[v47].m_oppositeEdge == -1 || v48[v47].m_flags.m_storage & 0x20 )
            LODWORD(edgeIsBoundary.m_data.m_data[(signed __int64)v44 >> 5]) |= v45;
          v45 = __ROL4__(v45, 1);
          ++v44;
          ++v46;
          oppositeEdges.m_data[v46 - 1] = v5->m_edges.m_data[v47].m_oppositeEdge;
          ++v47;
        }
        while ( v44 < v5->m_edges.m_size );
      }
      hkaiNavMesh::setEdgeDataStriding(v5, &v170, 0, 0);
      faceData.m_data = 0i64;
      faceData.m_size = 0;
      faceData.m_capacityAndFlags = 2147483648;
      v49 = v5->m_faces.m_size;
      if ( v49 <= 0 )
      {
        v139.m_enum = 0;
      }
      else
      {
        v50 = v5->m_faces.m_size;
        if ( v49 < 0 )
          v50 = 0;
        hkArrayUtil::_reserve(&v139, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &faceData, v50, 4);
        if ( v139.m_enum )
          goto LABEL_119;
      }
      faceData.m_size = v49;
      v51 = 0i64;
      for ( k = 0; k < v5->m_faces.m_size; faceData.m_data[v51 - 1] = v53 )
      {
        if ( v5->m_faceDataStriding )
          v53 = v5->m_faceData.m_data[v51 * v5->m_faceDataStriding];
        else
          v53 = 0;
        ++k;
        ++v51;
      }
      hkaiNavMesh::setFaceDataStriding(v5, &v167, 0, 0);
      hkaiNavMeshSimplificationUtils::addVerticesBetweenSegments(
        &v120,
        settingsa,
        &v10->m_vertices,
        &segmentsOut,
        (hkArrayBase<int> *)&segmentToOppositeMap.m_data,
        v5,
        (hkBitField *)&userVertexOnBoundary,
        &oppositeEdges);
      if ( v120.m_enum
        || (hkaiNavMeshSimplificationUtils::triangulatePartitions(
              &v154,
              settingsa,
              v173,
              v5,
              v10,
              &segmentsOut,
              (hkArrayBase<int> *)&partitions.m_data,
              (hkArrayBase<int> *)&numFacesInPartition.m_data,
              (hkArrayBase<int> *)&partitionDir.m_data,
              &faceToPartitionMapInOut,
              (hkBitField *)&edgeIsBoundary,
              (hkBitField *)&userVertexOnBoundary,
              &faceData),
            v154.m_enum) )
      {
LABEL_119:
        faceData.m_size = 0;
        if ( faceData.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            faceData.m_data,
            4 * faceData.m_capacityAndFlags);
        faceData.m_data = 0i64;
        faceData.m_capacityAndFlags = 2147483648;
        goto LABEL_122;
      }
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)17i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_119;
      }
      faceData.m_size = 0;
      if ( faceData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          faceData.m_data,
          4 * faceData.m_capacityAndFlags);
      faceData.m_data = 0i64;
      faceData.m_capacityAndFlags = 2147483648;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&edgeIsBoundary);
      v5->m_faces.m_size = 0;
      v54 = v5->m_faces.m_capacityAndFlags;
      if ( v54 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v5->m_faces.m_data,
          16 * v54);
      v5->m_faces.m_data = 0i64;
      v5->m_faces.m_capacityAndFlags = 2147483648;
      v5->m_edges.m_size = 0;
      v55 = v5->m_edges.m_capacityAndFlags;
      if ( v55 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v5->m_edges.m_data,
          20 * (v55 & 0x3FFFFFFF));
      v5->m_edges.m_data = 0i64;
      v5->m_edges.m_capacityAndFlags = 2147483648;
      v5->m_vertices.m_size = 0;
      v56 = v5->m_vertices.m_capacityAndFlags;
      if ( v56 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v5->m_vertices.m_data,
          16 * v56);
      v5->m_vertices.m_data = 0i64;
      v5->m_vertices.m_capacityAndFlags = 2147483648;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)18i64,
              &v164) )
      {
        v11 = 0;
        goto LABEL_123;
      }
      pArr = 0i64;
      v122 = 0;
      v123 = 2147483648;
      v57 = v10->m_edges.m_size;
      if ( v57 <= 0 )
      {
        v138.m_enum = 0;
      }
      else
      {
        v58 = v10->m_edges.m_size;
        if ( v57 < 0 )
          v58 = 0;
        hkArrayUtil::_reserve(&v138, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &pArr, v58, 16);
        if ( v138.m_enum )
          goto LABEL_242;
      }
      v122 = v57;
      v59 = 0;
      if ( v10->m_edges.m_size > 0 )
      {
        v60 = 0i64;
        v61 = 0i64;
        do
        {
          v62 = v10->m_edges.m_data;
          pArr[v60].m_edgeId = v59;
          pArr[v60].m_faceId = v59 / 3;
          v63 = v62[v61].m_b;
          v64 = v62[v61].m_a;
          if ( (signed int)v64 >= (signed int)v63 )
            v65 = v64 | (v63 << 32);
          else
            v65 = v63 | (v64 << 32);
          ++v59;
          ++v60;
          *((_QWORD *)&pArr[v60] - 1) = v65;
          ++v61;
        }
        while ( v59 < v10->m_edges.m_size );
      }
      if ( v122 > 1 )
        hkAlgorithm::quickSortRecursive<EdgeKey,hkAlgorithm::less<EdgeKey>>(pArr, 0, v122 - 1, 0);
      v66 = 0;
      if ( v122 - 1 > 0 )
      {
        v67 = 0i64;
        do
        {
          if ( pArr[v67].m_key == pArr[v67 + 1].m_key )
          {
            v68 = pArr[v67].m_edgeId;
            v69 = v10->m_edgeDataStriding;
            v70 = pArr[v67 + 1].m_edgeId;
            v71 = v10->m_edges.m_data;
            if ( (_DWORD)v69 )
              v72 = v10->m_edgeData.m_data[v68 * v69];
            else
              v72 = 0;
            if ( (_DWORD)v69 )
              v73 = v10->m_edgeData.m_data[pArr[v67 + 1].m_edgeId * v69];
            else
              v73 = 0;
            if ( v72 != -1 && v73 != -1 )
            {
              v71[v68].m_oppositeEdge = v70;
              v74 = v70;
              v71[v68].m_oppositeFace = pArr[v67 + 1].m_faceId;
              v71[v74].m_oppositeEdge = pArr[v67].m_edgeId;
              v71[v74].m_oppositeFace = pArr[v67].m_faceId;
              v75 = v10->m_edgeDataStriding;
              if ( (_DWORD)v75 )
                v10->m_edgeData.m_data[v75 * pArr[v67].m_edgeId] = -1;
              v76 = v10->m_edgeDataStriding;
              if ( (_DWORD)v76 )
                v10->m_edgeData.m_data[v76 * pArr[v67 + 1].m_edgeId] = -1;
            }
            v66 += 2;
            v67 += 2i64;
          }
          else
          {
            ++v66;
            ++v67;
          }
        }
        while ( v66 < v122 - 1 );
        callbacks = v161;
      }
      v77 = 2147483648;
      v124 = 0i64;
      v125 = 0;
      v126 = 2147483648;
      v78 = v10->m_edges.m_size;
      v79 = 0;
      if ( v78 <= 0 )
      {
        v142.m_enum = 0;
      }
      else
      {
        hkArrayUtil::_reserve(&v142, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v124, v78, 4);
        if ( v142.m_enum )
        {
LABEL_239:
          v125 = 0;
          if ( v126 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v124,
              4 * v126);
          v124 = 0i64;
          v126 = 2147483648;
LABEL_242:
          v122 = 0;
          if ( v123 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              pArr,
              16 * v123);
          pArr = 0i64;
          v123 = 2147483648;
          goto LABEL_123;
        }
        v77 = v126;
        v79 = v125;
      }
      v80 = v10->m_edges.m_size;
      v81 = v77 & 0x3FFFFFFF;
      if ( v81 >= v80 )
      {
        v156.m_enum = 0;
      }
      else
      {
        v82 = 2 * v81;
        v83 = v10->m_edges.m_size;
        if ( v80 < v82 )
          v83 = v82;
        hkArrayUtil::_reserve(&v156, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v124, v83, 4);
        v79 = v125;
      }
      v84 = &v124[4 * v79];
      v85 = v80 - v79;
      if ( v80 - v79 > 0 )
      {
        while ( v85 )
        {
          *(_DWORD *)v84 = -1;
          v84 += 4;
          --v85;
        }
      }
      v125 = v80;
      v86 = 0;
      if ( v10->m_faces.m_size > 0 )
      {
        v87 = 0i64;
        do
        {
          v88 = v10->m_faces.m_data;
          v89 = v88[v87].m_startEdgeIndex;
          if ( (signed int)v89 < (signed int)v89 + v88[v87].m_numEdges )
          {
            v90 = 4 * v89;
            do
            {
              LODWORD(v89) = v89 + 1;
              v90 += 4i64;
              *(_DWORD *)&v124[v90 - 4] = v86;
            }
            while ( (signed int)v89 < v88[v87].m_startEdgeIndex + v88[v87].m_numEdges );
          }
          ++v86;
          ++v87;
        }
        while ( v86 < v10->m_faces.m_size );
      }
      v91 = oppositeEdges.m_size;
      v92 = 2147483648;
      v127 = 0i64;
      v93 = 0;
      v128 = 0;
      v129 = 2147483648;
      if ( oppositeEdges.m_size <= 0 )
      {
        v136.m_enum = 0;
      }
      else
      {
        hkArrayUtil::_reserve(
          &v136,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &v127,
          oppositeEdges.m_size,
          4);
        if ( v136.m_enum )
        {
LABEL_236:
          v128 = 0;
          if ( v129 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v127,
              4 * v129);
          v127 = 0i64;
          v129 = 2147483648;
          goto LABEL_239;
        }
        v91 = oppositeEdges.m_size;
        v92 = v129;
        v93 = v128;
      }
      v94 = v92 & 0x3FFFFFFF;
      if ( v94 >= v91 )
      {
        v158.m_enum = 0;
      }
      else
      {
        v95 = 2 * v94;
        v96 = v91;
        if ( v91 < v95 )
          v96 = v95;
        hkArrayUtil::_reserve(&v158, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v127, v96, 4);
        v93 = v128;
      }
      v97 = &v127[4 * v93];
      v98 = v91 - v93;
      if ( v91 - v93 > 0 )
      {
        while ( v98 )
        {
          *(_DWORD *)v97 = -1;
          v97 += 4;
          --v98;
        }
      }
      v128 = v91;
      v99 = 0;
      v100 = 0i64;
      if ( v10->m_edges.m_size > 0 )
      {
        while ( 1 )
        {
          v101 = v10->m_edgeDataStriding;
          if ( !(_DWORD)v101 )
            break;
          v102 = v10->m_edgeData.m_data[v100 * v101];
          if ( v102 >= 0 )
            goto LABEL_221;
LABEL_222:
          ++v99;
          ++v100;
          if ( v99 >= v10->m_edges.m_size )
            goto LABEL_223;
        }
        v102 = 0;
LABEL_221:
        *(_DWORD *)&v127[4 * v102] = v99;
        goto LABEL_222;
      }
LABEL_223:
      v103 = 0i64;
      v104 = 0i64;
      if ( v10->m_edges.m_size > 0 )
      {
        v105 = 0i64;
        while ( 1 )
        {
          v106 = v10->m_edges.m_data;
          if ( !v10->m_edgeDataStriding )
            break;
          LODWORD(v107) = v10->m_edgeData.m_data[v104 * v10->m_edgeDataStriding];
          if ( (signed int)v107 >= 0 )
            goto LABEL_229;
LABEL_233:
          v103 = (unsigned int)(v103 + 1);
          ++v104;
          ++v105;
          if ( (signed int)v103 >= v10->m_edges.m_size )
            goto LABEL_234;
        }
        LODWORD(v107) = 0;
LABEL_229:
        v107 = (signed int)v107;
        v108 = oppositeEdges.m_data[(signed int)v107];
        v109 = *(signed int *)&v127[4 * v108];
        if ( (_DWORD)v109 != -1 )
        {
          *(_DWORD *)&v127[4 * v107] = -1;
          *(_DWORD *)&v127[4 * v108] = -1;
          v110 = v10->m_edges.m_data;
          v106[v105].m_oppositeEdge = v109;
          v111 = v109;
          v110[v111].m_oppositeEdge = v103;
          v106[v105].m_oppositeFace = *(_DWORD *)&v124[4 * v109];
          v110[v111].m_oppositeFace = *(_DWORD *)&v124[4 * v104];
          v112 = v10->m_edgeDataStriding;
          if ( (_DWORD)v112 )
          {
            v10->m_edgeData.m_data[v104 * v112] = -1;
            if ( v10->m_edgeDataStriding )
              v10->m_edgeData.m_data[v109 * v10->m_edgeDataStriding] = -1;
          }
        }
        goto LABEL_233;
      }
LABEL_234:
      if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshGenerationProgressCallback *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *, __int64))callbacks->vfptr->stepEndedCallback)(
             callbacks,
             18i64,
             &v164,
             v103) )
      {
        v128 = 0;
        if ( v129 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v127,
            4 * v129);
        v127 = 0i64;
        v129 = 2147483648;
        v125 = 0;
        if ( v126 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v124,
            4 * v126);
        v124 = 0i64;
        v126 = 2147483648;
        v122 = 0;
        if ( v123 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            pArr,
            16 * v123);
        pArr = 0i64;
        v123 = 2147483648;
        if ( callbacks->vfptr->stepStartedCallback(callbacks, END|BEGIN|0x10, &v164) )
        {
          v10->m_aabb.m_min = v5->m_aabb.m_min;
          v10->m_aabb.m_max = v5->m_aabb.m_max;
          hkaiNavMeshUtils::validate(v10, 1);
          if ( settingsa->m_simplificationSettings.m_useHeightPartitioning.m_bool
            && settingsa->m_simplificationSettings.m_useConservativeHeightPartitioning.m_bool )
          {
            if ( hkaiNavMeshSimplificationUtils::hertelMehlhorn(&v165, settingsa, v10, 0i64, &faceToPartitionMapInOut)->m_enum )
              goto LABEL_123;
            v113 = &settingsa->m_simplificationSettings.m_hertelMehlhornHeightError;
            v114 = (hkResult *)&v168;
          }
          else
          {
            v113 = 0i64;
            v114 = &v166;
          }
          if ( hkaiNavMeshSimplificationUtils::hertelMehlhorn(v114, settingsa, v10, v113, 0i64)->m_enum == HK_SUCCESS )
          {
            hkaiNavMeshUtils::compactVertices(&v152, v10, 0, 0);
            if ( v152.m_enum == HK_SUCCESS )
            {
              v115 = 0;
              for ( l = 0i64; v115 < v10->m_edges.m_size; ++l )
              {
                if ( v10->m_edgeDataStriding )
                  v10->m_edgeData.m_data[l * v10->m_edgeDataStriding] = 0;
                ++v115;
              }
              if ( callbacks->vfptr->stepEndedCallback(callbacks, END|BEGIN|0x10, &v164) )
              {
                if ( callbacks->vfptr->stepStartedCallback(
                       callbacks,
                       (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)20i64,
                       &v164) )
                {
                  if ( callbacks->vfptr->stepEndedCallback(
                         callbacks,
                         (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)20i64,
                         &v164) )
                  {
                    v11 = 2;
                  }
                  else
                  {
                    v11 = 0;
                  }
                }
                else
                {
                  v11 = 0;
                }
              }
              else
              {
                v11 = 0;
              }
            }
          }
          goto LABEL_123;
        }
        v11 = 0;
LABEL_123:
        faceToPartitionMapInOut.m_size = 0;
        if ( faceToPartitionMapInOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            faceToPartitionMapInOut.m_data,
            4 * faceToPartitionMapInOut.m_capacityAndFlags);
        faceToPartitionMapInOut.m_data = 0i64;
        faceToPartitionMapInOut.m_capacityAndFlags = 2147483648;
        oppositeEdges.m_size = 0;
        if ( oppositeEdges.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            oppositeEdges.m_data,
            4 * oppositeEdges.m_capacityAndFlags);
        oppositeEdges.m_data = 0i64;
        oppositeEdges.m_capacityAndFlags = 2147483648;
        goto LABEL_128;
      }
      v11 = 0;
      goto LABEL_236;
    }
    numEdgesInGroupOut.m_data = 0i64;
    numEdgesInGroupOut.m_size = 0;
    v164.m_boundaryFilterNumEdgesInGroup = (hkArrayBase<int> *)&numEdgesInGroupOut;
    numEdgesInGroupOut.m_capacityAndFlags = 2147483648;
    v164.m_boundaryFilterEdgesToRemove = (hkArrayBase<int> *)&edgesToRemoveOut;
    if ( callbacks->vfptr->stepStartedCallback(
           callbacks,
           (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)13i64,
           &v164) )
    {
      hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(
        &v120,
        v7,
        v5,
        v9,
        &numEdgesInGroupOut,
        &edgesToRemoveOut,
        0i64);
      if ( v120.m_enum )
      {
        v11 = 1;
LABEL_32:
        numEdgesInGroupOut.m_size = 0;
        if ( numEdgesInGroupOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            numEdgesInGroupOut.m_data,
            4 * numEdgesInGroupOut.m_capacityAndFlags);
        numEdgesInGroupOut.m_data = 0i64;
        numEdgesInGroupOut.m_capacityAndFlags = 2147483648;
        goto LABEL_280;
      }
      if ( callbacks->vfptr->stepEndedCallback(
             callbacks,
             (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)13i64,
             &v164) )
      {
        v164.m_numFacesInPartition = (hkArrayBase<int> *)&numFacesInPartition;
        v164.m_partitions = (hkArrayBase<int> *)&partitions;
        if ( callbacks->vfptr->stepStartedCallback(
               callbacks,
               (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
               &v164) )
        {
          hkaiNavMeshSimplificationUtils::partition(
            &v157,
            v5,
            &origMesh,
            v7,
            &numFacesInPartition,
            &partitions,
            &numEdgesInGroupOut,
            &edgesToRemoveOut);
          if ( v157.m_enum )
          {
            v11 = 1;
            goto LABEL_32;
          }
          if ( callbacks->vfptr->stepEndedCallback(
                 callbacks,
                 (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
                 &v164) )
          {
            numEdgesInGroupOut.m_size = 0;
            if ( numEdgesInGroupOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                numEdgesInGroupOut.m_data,
                4 * numEdgesInGroupOut.m_capacityAndFlags);
            numEdgesInGroupOut.m_data = 0i64;
            numEdgesInGroupOut.m_capacityAndFlags = 2147483648;
            goto LABEL_38;
          }
        }
      }
    }
    v11 = 0;
    goto LABEL_32;
  }
  v11 = 1;
LABEL_280:
  edgesToRemoveOut.m_size = 0;
  if ( edgesToRemoveOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      edgesToRemoveOut.m_data,
      4 * edgesToRemoveOut.m_capacityAndFlags);
  edgesToRemoveOut.m_data = 0i64;
  edgesToRemoveOut.m_capacityAndFlags = 2147483648;
  partitions.m_size = 0;
  if ( partitions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partitions.m_data,
      4 * partitions.m_capacityAndFlags);
  partitions.m_data = 0i64;
  partitions.m_capacityAndFlags = 2147483648;
  partitionDir.m_size = 0;
  if ( partitionDir.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partitionDir.m_data,
      4 * partitionDir.m_capacityAndFlags);
  partitionDir.m_data = 0i64;
  partitionDir.m_capacityAndFlags = 2147483648;
  numFacesInPartition.m_size = 0;
  if ( numFacesInPartition.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      numFacesInPartition.m_data,
      4 * numFacesInPartition.m_capacityAndFlags);
  numFacesInPartition.m_data = 0i64;
  numFacesInPartition.m_capacityAndFlags = 2147483648;
  hkaiNavMesh::~hkaiNavMesh(&origMesh);
  return v11;
}

// File Line: 4866
// RVA: 0xB4BE60
hkResult *__fastcall hkaiNavMeshSimplificationUtils::addVerticesBetweenSegments(hkResult *result, hkaiNavMeshGenerationSettings *settings, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut, hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut, hkArrayBase<int> *segmentToOppositeMap, hkaiNavMesh *navMesh, hkBitField *userVertexOnBoundary, hkArray<int,hkContainerHeapAllocator> *oppositeEdges)
{
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v8; // r10
  int v9; // eax
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v10; // r11
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // r13
  bool v12; // cf
  hkResult *v13; // rsi
  int v14; // er12
  signed int v15; // er9
  __int64 v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r8
  int *v19; // rax
  __int64 v20; // rcx
  hkArrayBase<unsigned int> *v21; // r15
  int v22; // ebx
  int v23; // ebx
  __int64 v24; // r8
  hkVector4f *v25; // rdx
  __int64 v26; // rax
  __m128i v27; // xmm0
  int v28; // edi
  int v29; // ebx
  int v30; // er9
  int v31; // er9
  int v32; // er9
  hkResultEnum v33; // eax
  int v34; // er9
  hkResultEnum v35; // eax
  hkArray<int,hkContainerHeapAllocator> *v36; // r14
  int v37; // er9
  int v38; // eax
  int v39; // eax
  int v40; // er8
  hkResult *v41; // rbx
  __int64 v42; // rcx
  signed __int64 v43; // rdx
  signed __int64 v44; // r11
  signed __int64 v45; // r9
  int v46; // er8
  int v47; // er10
  int v48; // er8
  int v49; // er9
  int v50; // eax
  int v51; // eax
  __int64 v52; // rsi
  __int64 v53; // r14
  int v54; // eax
  int v55; // er9
  int v56; // eax
  hkResultEnum v57; // eax
  hkArrayBase<unsigned int> *v58; // rbx
  hkArrayBase<unsigned int> *v59; // r15
  int v60; // eax
  int v61; // er9
  int v62; // eax
  hkResultEnum v63; // eax
  int v64; // er9
  hkArrayBase<unsigned int> *v65; // r14
  int v66; // er9
  int v67; // eax
  int v68; // eax
  hkResultEnum v69; // eax
  hkArrayBase<unsigned int> *v70; // rsi
  int v71; // eax
  int v72; // er9
  int v73; // eax
  hkResultEnum v74; // eax
  int v75; // ebx
  bool v76; // sf
  int v78; // er8
  int v79; // er8
  unsigned int *p; // [rsp+40h] [rbp-C0h]
  int v81; // [rsp+48h] [rbp-B8h]
  int v82; // [rsp+4Ch] [rbp-B4h]
  void *array; // [rsp+50h] [rbp-B0h]
  int v84; // [rsp+58h] [rbp-A8h]
  int v85; // [rsp+5Ch] [rbp-A4h]
  unsigned int *v86; // [rsp+60h] [rbp-A0h]
  int v87; // [rsp+68h] [rbp-98h]
  int v88; // [rsp+6Ch] [rbp-94h]
  unsigned int *v89; // [rsp+70h] [rbp-90h]
  int v90; // [rsp+78h] [rbp-88h]
  int v91; // [rsp+7Ch] [rbp-84h]
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeVertices; // [rsp+80h] [rbp-80h]
  hkResult v93; // [rsp+90h] [rbp-70h]
  int v94; // [rsp+94h] [rbp-6Ch]
  hkResult v95; // [rsp+98h] [rbp-68h]
  hkResult v96; // [rsp+9Ch] [rbp-64h]
  hkResult v97; // [rsp+A0h] [rbp-60h]
  hkResult v98; // [rsp+A4h] [rbp-5Ch]
  hkResult v99; // [rsp+A8h] [rbp-58h]
  hkResult v100; // [rsp+ACh] [rbp-54h]
  hkResult v101; // [rsp+B0h] [rbp-50h]
  int v102; // [rsp+B4h] [rbp-4Ch]
  hkResult v103; // [rsp+B8h] [rbp-48h]
  __int64 v104; // [rsp+C0h] [rbp-40h]
  hkResult resulta; // [rsp+C8h] [rbp-38h]
  int v106; // [rsp+CCh] [rbp-34h]
  hkArrayBase<unsigned int> *v107; // [rsp+D0h] [rbp-30h]
  __int64 v108; // [rsp+D8h] [rbp-28h]
  __int64 v109; // [rsp+E0h] [rbp-20h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v110; // [rsp+E8h] [rbp-18h]
  hkArrayBase<unsigned int> *v111; // [rsp+F0h] [rbp-10h]
  hkaiNavMeshSimplificationUtils::Segment *v112; // [rsp+F8h] [rbp-8h]
  hkVector4f vIn1; // [rsp+100h] [rbp+0h]
  hkVector4f vIn0; // [rsp+110h] [rbp+10h]
  hkResult *v115; // [rsp+160h] [rbp+60h]
  int index; // [rsp+168h] [rbp+68h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v117; // [rsp+178h] [rbp+78h]

  v117 = segmentsInOut;
  v115 = result;
  v8 = &settings->m_simplificationSettings.m_extraVertexSettings;
  v9 = navMesh->m_edges.m_size;
  v10 = segmentsInOut;
  v11 = verticesInOut;
  v12 = settings->m_simplificationSettings.m_extraVertexSettings.m_partitionBordersSplitLength > 0.0;
  v13 = result;
  v14 = 0;
  v110 = &settings->m_simplificationSettings.m_extraVertexSettings;
  v106 = v9;
  if ( !v12 || !settings->m_simplificationSettings.m_extraVertexSettings.m_addVerticesOnPartitionBorders.m_bool )
  {
    result->m_enum = 0;
    return result;
  }
  v15 = 0;
  v102 = 0;
  if ( v10->m_size <= 0 )
    goto LABEL_103;
  v16 = 0i64;
  v17 = 0i64;
  v109 = 0i64;
  v104 = 0i64;
  while ( 1 )
  {
    v18 = (__int64)v10->m_data;
    v19 = segmentToOppositeMap->m_data;
    v112 = v10->m_data;
    v20 = *(int *)((char *)v19 + v16);
    if ( (_DWORD)v20 != -1 && (signed int)v20 >= v15 )
    {
      v21 = (hkArrayBase<unsigned int> *)(v17 + v18 + 32);
      v22 = v21->m_size;
      v107 = (hkArrayBase<unsigned int> *)(v17 + v18 + 32);
      v23 = v22 - 2;
      v111 = (hkArrayBase<unsigned int> *)(v18 + 48 * v20);
      v24 = v23;
      v94 = v23;
      v108 = v23;
      if ( v23 >= 0 )
        break;
    }
LABEL_101:
    ++v15;
    v17 += 48i64;
    v16 = v109 + 4;
    v102 = v15;
    v104 = v17;
    v109 += 4i64;
    if ( v15 >= v10->m_size )
    {
      v13 = v115;
LABEL_103:
      v13->m_enum = 0;
      return v13;
    }
  }
  index = v23 + 1;
  while ( 1 )
  {
    v25 = v11->m_data;
    v26 = (signed int)v21->m_data[v24 + 1];
    _mm_store_si128((__m128i *)&vIn0, (__m128i)v11->m_data[v21->m_data[v24]].m_quad);
    v27 = (__m128i)v25[v26];
    edgeVertices.m_data = 0i64;
    _mm_store_si128((__m128i *)&vIn1, v27);
    edgeVertices.m_size = 0;
    edgeVertices.m_capacityAndFlags = 2147483648;
    hkaiNavMeshSimplificationUtils::getEdgeSplitting(&resulta, &vIn0, &vIn1, v8, 0, userVertexOnBoundary, &edgeVertices);
    if ( resulta.m_enum )
    {
      v13 = v115;
      v115->m_enum = 1;
      goto LABEL_129;
    }
    v28 = edgeVertices.m_size - 2;
    if ( edgeVertices.m_size != 2 )
      break;
    edgeVertices.m_size = 0;
    if ( edgeVertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        edgeVertices.m_data,
        16 * edgeVertices.m_capacityAndFlags);
LABEL_99:
    --index;
    v8 = v110;
    --v23;
    v24 = v108 - 1;
    v76 = v108 - 1 < 0;
    edgeVertices.m_capacityAndFlags = 2147483648;
    --v108;
    edgeVertices.m_data = 0i64;
    v94 = v23;
    if ( v76 )
    {
      v17 = v104;
      v15 = v102;
      v10 = v117;
      goto LABEL_101;
    }
  }
  v29 = v11->m_size;
  array = 0i64;
  v84 = 0;
  v85 = 2147483648;
  p = 0i64;
  v81 = 0;
  v82 = 2147483648;
  if ( v28 <= 0 )
  {
    v95.m_enum = 0;
  }
  else
  {
    v30 = edgeVertices.m_size - 2;
    if ( v28 < 0 )
      v30 = 0;
    hkArrayUtil::_reserve(&v95, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v30, 4);
    if ( v95.m_enum )
    {
LABEL_17:
      v13 = v115;
      v115->m_enum = 1;
      goto LABEL_123;
    }
  }
  v84 = v28;
  if ( (v82 & 0x3FFFFFFF) >= v28 )
  {
    v93.m_enum = 0;
  }
  else
  {
    v31 = v28;
    if ( v28 < 2 * (v82 & 0x3FFFFFFF) )
      v31 = 2 * (v82 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v93, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &p, v31, 4);
    if ( v93.m_enum )
      goto LABEL_17;
  }
  v81 = v28;
  v89 = 0i64;
  v90 = 0;
  v91 = 2147483648;
  v86 = 0i64;
  v87 = 0;
  v88 = 2147483648;
  if ( v28 <= 0 )
  {
    v33 = 0;
    v101.m_enum = 0;
LABEL_31:
    v90 = v28;
    goto LABEL_32;
  }
  v32 = v28;
  if ( v28 < 0 )
    v32 = 0;
  hkArrayUtil::_reserve(&v101, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v89, v32, 4);
  v33 = v101.m_enum;
  if ( v101.m_enum == HK_SUCCESS )
    goto LABEL_31;
LABEL_32:
  v95.m_enum = v33;
  if ( v33 )
    goto LABEL_118;
  if ( (v88 & 0x3FFFFFFF) >= v28 )
  {
    v35 = 0;
    v100.m_enum = 0;
LABEL_39:
    v87 = v28;
    goto LABEL_40;
  }
  v34 = v28;
  if ( v28 < 2 * (v88 & 0x3FFFFFFF) )
    v34 = 2 * (v88 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(&v100, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v86, v34, 4);
  v35 = v100.m_enum;
  if ( v100.m_enum == HK_SUCCESS )
    goto LABEL_39;
LABEL_40:
  v93.m_enum = v35;
  if ( v35 )
  {
LABEL_118:
    v79 = v88;
    v13 = v115;
    v87 = 0;
    v115->m_enum = 1;
    if ( v79 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v86,
        4 * v79);
    v90 = 0;
    v88 = 2147483648;
    v86 = 0i64;
    if ( v91 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v89,
        4 * v91);
    v91 = 2147483648;
    v89 = 0i64;
LABEL_123:
    v81 = 0;
    if ( v82 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        p,
        4 * v82);
    p = 0i64;
    v82 = 2147483648;
    v84 = 0;
    if ( v85 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v85);
    array = 0i64;
    v85 = 2147483648;
LABEL_129:
    edgeVertices.m_size = 0;
    if ( edgeVertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        edgeVertices.m_data,
        16 * edgeVertices.m_capacityAndFlags);
    return v13;
  }
  v36 = oppositeEdges;
  v37 = 2 * v28 + oppositeEdges->m_size;
  v38 = oppositeEdges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v38 >= v37 )
  {
    v97.m_enum = 0;
  }
  else
  {
    v39 = 2 * v38;
    if ( v37 < v39 )
      v37 = v39;
    hkArrayUtil::_reserve(&v97, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, oppositeEdges, v37, 4);
    if ( v97.m_enum )
    {
LABEL_45:
      v40 = v88;
      v41 = v115;
      v115->m_enum = 1;
      v87 = 0;
      if ( v40 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v86,
          4 * v40);
      v90 = 0;
      v88 = 2147483648;
      v86 = 0i64;
      if ( v91 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v89,
          4 * v91);
      v81 = 0;
      v91 = 2147483648;
      v89 = 0i64;
      if ( v82 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          p,
          4 * v82);
      p = 0i64;
      v82 = 2147483648;
      v84 = 0;
      if ( v85 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v85);
      array = 0i64;
      edgeVertices.m_size = 0;
      goto LABEL_115;
    }
  }
  v42 = v36->m_size;
  v43 = 0i64;
  v36->m_size = v42 + 2 * v28;
  v44 = (signed __int64)&v36->m_data[v42];
  if ( v28 > 0 )
  {
    v45 = v44 + 4;
    v46 = v14 + v106;
    v47 = v29 + v28 - 1;
    do
    {
      ++v43;
      v14 += 2;
      *((_DWORD *)array + v43 - 1) = v29++;
      p[v43 - 1] = v47--;
      v89[v43 - 1] = v46;
      v48 = v46 + 1;
      v86[v43 - 1] = v48;
      v46 = v48 + 1;
      v45 += 8i64;
      *(_DWORD *)(v44 + 8 * v43 - 8) = v86[v43 - 1];
      *(_DWORD *)(v45 - 8) = v89[v43 - 1];
    }
    while ( v43 < v28 );
  }
  v49 = v28 + v11->m_size;
  v50 = v11->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v50 >= v49 )
  {
    LODWORD(navMesh) = 0;
  }
  else
  {
    v51 = 2 * v50;
    if ( v49 < v51 )
      v49 = v51;
    hkArrayUtil::_reserve(
      (hkResult *)&navMesh,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v11,
      v49,
      16);
    if ( (_DWORD)navMesh )
      goto LABEL_45;
  }
  v52 = v104;
  v53 = (__int64)v112;
  v54 = v21->m_capacityAndFlags & 0x3FFFFFFF;
  v55 = v28 + *(int *)((char *)&v112->m_indices.m_size + v104);
  if ( v54 >= v55 )
  {
    v57 = 0;
    v99.m_enum = 0;
  }
  else
  {
    v56 = 2 * v54;
    if ( v55 < v56 )
      v55 = v56;
    hkArrayUtil::_reserve(&v99, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v21, v55, 4);
    v57 = v99.m_enum;
  }
  LODWORD(navMesh) = v57;
  if ( v57 == HK_SUCCESS )
  {
    v58 = v111;
    v59 = v111 + 2;
    v60 = v111[2].m_capacityAndFlags & 0x3FFFFFFF;
    v61 = v28 + v111[2].m_size;
    if ( v60 >= v61 )
    {
      v63 = 0;
      v96.m_enum = 0;
    }
    else
    {
      v62 = 2 * v60;
      if ( v61 < v62 )
        v61 = v62;
      hkArrayUtil::_reserve(&v96, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v111[2], v61, 4);
      v63 = v96.m_enum;
    }
    LODWORD(navMesh) = v63;
    if ( v63 == HK_SUCCESS )
    {
      v64 = *(_DWORD *)(v52 + v53 + 24);
      v65 = (hkArrayBase<unsigned int> *)(v52 + v53);
      v66 = v28 + v64;
      v67 = v65[1].m_capacityAndFlags & 0x3FFFFFFF;
      if ( v67 >= v66 )
      {
        v69 = 0;
        v103.m_enum = 0;
      }
      else
      {
        v68 = 2 * v67;
        if ( v66 < v68 )
          v66 = v68;
        hkArrayUtil::_reserve(&v103, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v65[1], v66, 4);
        v69 = v103.m_enum;
      }
      LODWORD(navMesh) = v69;
      if ( v69 == HK_SUCCESS )
      {
        v70 = v58 + 1;
        v71 = v58[1].m_capacityAndFlags & 0x3FFFFFFF;
        v72 = v28 + v58[1].m_size;
        if ( v71 >= v72 )
        {
          v74 = 0;
          v98.m_enum = 0;
        }
        else
        {
          v73 = 2 * v71;
          if ( v72 < v73 )
            v72 = v73;
          hkArrayUtil::_reserve(&v98, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v58[1], v72, 4);
          v74 = v98.m_enum;
        }
        LODWORD(navMesh) = v74;
        if ( v74 == HK_SUCCESS )
        {
          hkArrayBase<hkVector4f>::_append(
            (hkArrayBase<hkVector4f> *)&v11->m_data,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            edgeVertices.m_data + 1,
            v28);
          v75 = v58[2].m_size - v94;
          hkArrayBase<unsigned int>::_insertAt(
            v107,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            index,
            (const unsigned int *)array,
            v28);
          hkArrayBase<unsigned int>::_insertAt(
            v59,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v75 - 1,
            p,
            v28);
          hkArrayBase<unsigned int>::_insertAt(
            v65 + 1,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            index,
            v89,
            v28);
          hkArrayBase<unsigned int>::_insertAt(
            v70,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v75 - 2,
            v86,
            v28);
          v87 = 0;
          if ( v88 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v86,
              4 * v88);
          v86 = 0i64;
          v88 = 2147483648;
          v90 = 0;
          if ( v91 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v89,
              4 * v91);
          v89 = 0i64;
          v91 = 2147483648;
          v81 = 0;
          if ( v82 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              p,
              4 * v82);
          p = 0i64;
          v82 = 2147483648;
          v84 = 0;
          if ( v85 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              array,
              4 * v85);
          array = 0i64;
          v85 = 2147483648;
          edgeVertices.m_size = 0;
          if ( edgeVertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              edgeVertices.m_data,
              16 * edgeVertices.m_capacityAndFlags);
          v23 = v94;
          v21 = v107;
          goto LABEL_99;
        }
      }
    }
  }
  v78 = v88;
  v41 = v115;
  v87 = 0;
  v115->m_enum = 1;
  if ( v78 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v86,
      4 * v78);
  v90 = 0;
  v88 = 2147483648;
  v86 = 0i64;
  if ( v91 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v89,
      4 * v91);
  v81 = 0;
  v91 = 2147483648;
  v89 = 0i64;
  if ( v82 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      p,
      4 * v82);
  v84 = 0;
  v82 = 2147483648;
  p = 0i64;
  if ( v85 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v85);
  array = 0i64;
  edgeVertices.m_size = 0;
LABEL_115:
  v85 = 2147483648;
  if ( edgeVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      edgeVertices.m_data,
      16 * edgeVertices.m_capacityAndFlags);
  return v41;
}

