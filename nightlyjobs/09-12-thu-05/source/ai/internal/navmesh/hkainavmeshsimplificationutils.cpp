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
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this)
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
  this->m_userVertices.m_capacityAndFlags = 0x80000000;
}

// File Line: 87
// RVA: 0xB49260
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this,
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *other)
{
  this->m_userVertices.m_capacityAndFlags = 0x80000000;
  this->m_userVertices.m_data = 0i64;
  this->m_userVertices.m_size = 0;
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::operator=(this, other);
}

// File Line: 92
// RVA: 0xB49290
void __fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::disable(
        hkaiNavMeshSimplificationUtils::ExtraVertexSettings *this)
{
  *(_QWORD *)&this->m_vertexFraction = 0i64;
  *(_WORD *)&this->m_addVerticesOnBoundaryEdges.m_bool = 0;
}

// File Line: 124
// RVA: 0xB492B0
void __fastcall hkaiNavMeshSimplificationUtils::Settings::Settings(hkaiNavMeshSimplificationUtils::Settings *this)
{
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
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings::ExtraVertexSettings(&this->m_extraVertexSettings);
  this->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, 0i64);
}

// File Line: 130
// RVA: 0xB49380
void __fastcall hkaiNavMeshSimplificationUtils::Settings::Settings(
        hkaiNavMeshSimplificationUtils::Settings *this,
        hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, f);
}

// File Line: 134
// RVA: 0xB493B0
void __fastcall hkaiNavMeshSimplificationUtils::Settings::setForBorderPreservation(
        hkaiNavMeshSimplificationUtils::Settings *this)
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
hkResult *__fastcall vertexUnionFind(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkArray<int,hkContainerHeapAllocator> *partitionSizes,
        hkArray<int,hkContainerHeapAllocator> *partitions)
{
  int m_size; // edi
  hkArray<int,hkContainerHeapAllocator> *v6; // rsi
  hkLifoAllocator *Value; // rcx
  int *m_cur; // rax
  int v11; // ebx
  char *v12; // rdx
  unsigned int v13; // ecx
  hkLifoAllocator *v14; // rax
  int v15; // r8d
  int *v16; // rdx
  int v17; // ebx
  __int64 v18; // rdi
  hkaiNavMesh::Edge *m_data; // rsi
  __int64 m_oppositeEdge; // rax
  int m_a; // edx
  int m_b; // r8d
  int *p_m_a; // r15
  int v24; // edx
  int *m_storage; // rdi
  unsigned int m_slotID; // ecx
  int v27; // ebx
  signed int v28; // ebx
  hkResult v30; // [rsp+20h] [rbp-58h] BYREF
  hkFixedArray<int> parents; // [rsp+28h] [rbp-50h] BYREF
  hkUnionFind v32; // [rsp+38h] [rbp-40h] BYREF
  hkResult resulta; // [rsp+88h] [rbp+10h] BYREF
  hkArray<int,hkContainerHeapAllocator> *v34; // [rsp+98h] [rbp+20h]

  v34 = partitions;
  m_size = mesh->m_vertices.m_size;
  v6 = partitions;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v11 = (4 * m_size + 127) & 0xFFFFFF80;
  v12 = (char *)m_cur + v11;
  if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
  else
    Value->m_cur = v12;
  parents.m_data.m_storage = m_cur;
  parents.m_size.m_storage = m_size;
  if ( m_cur )
  {
    hkUnionFind::hkUnionFind(&v32, &parents, m_size);
    v17 = 0;
    v32.m_isCollapsed = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        m_data = mesh->m_edges.m_data;
        m_oppositeEdge = (int)m_data[v18].m_oppositeEdge;
        if ( (_DWORD)m_oppositeEdge != -1 )
        {
          m_a = m_data[v18].m_a;
          m_b = m_data[m_oppositeEdge].m_b;
          p_m_a = &m_data[m_oppositeEdge].m_a;
          if ( m_a != m_b )
            hkUnionFind::addEdge(&v32, m_a, m_b);
          v24 = m_data[v18].m_b;
          if ( v24 != *p_m_a )
            hkUnionFind::addEdge(&v32, v24, *p_m_a);
        }
        ++v17;
        ++v18;
      }
      while ( v17 < mesh->m_edges.m_size );
      v6 = v34;
    }
    hkUnionFind::assignGroups(&v32, &resulta, partitionSizes);
    if ( resulta.m_enum )
    {
      m_storage = parents.m_data.m_storage;
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v27 = 4 * parents.m_size.m_storage + 127;
      result->m_enum = HK_FAILURE;
      v28 = v27 & 0xFFFFFF80;
    }
    else
    {
      hkUnionFind::sortByGroupId(&v32, &v30, partitionSizes, v6);
      m_storage = parents.m_data.m_storage;
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v28 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
      if ( v30.m_enum )
        result->m_enum = HK_FAILURE;
      else
        result->m_enum = HK_SUCCESS;
    }
    v14 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v15 = (v28 + 15) & 0xFFFFFFF0;
    if ( v28 <= v14->m_slabSize && (char *)m_storage + v15 == v14->m_cur && v14->m_firstNonLifoEnd != m_storage )
    {
      v14->m_cur = m_storage;
      return result;
    }
    v16 = m_storage;
LABEL_30:
    hkLifoAllocator::slowBlockFree(v14, v16, v15);
    return result;
  }
  v13 = hkMemoryRouter::s_memoryRouter.m_slotID;
  result->m_enum = HK_FAILURE;
  v14 = (hkLifoAllocator *)TlsGetValue(v13);
  v15 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v14->m_slabSize || (void *)v15 != v14->m_cur || !v14->m_firstNonLifoEnd )
  {
    v16 = 0i64;
    goto LABEL_30;
  }
  v14->m_cur = 0i64;
  return result;
}

// File Line: 186
// RVA: 0xB493D0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::mergeSharedVertices(hkResult *result, hkaiNavMesh *mesh)
{
  int m_size; // r9d
  int v5; // edx
  int v6; // esi
  int v7; // r9d
  _DWORD *v8; // rdi
  __int64 v9; // rcx
  int *m_data; // r8
  int v11; // r11d
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
  int v23; // r8d
  __int64 v24; // rdi
  hkaiNavMesh::Edge *v25; // rdx
  __int64 m_a; // rcx
  _DWORD *array; // [rsp+30h] [rbp-38h] BYREF
  int v29; // [rsp+38h] [rbp-30h]
  int v30; // [rsp+3Ch] [rbp-2Ch]
  hkArray<int,hkContainerHeapAllocator> partitions; // [rsp+40h] [rbp-28h] BYREF
  hkArray<int,hkContainerHeapAllocator> partitionSizes; // [rsp+50h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+A0h] [rbp+38h] BYREF
  hkResult v34; // [rsp+A8h] [rbp+40h] BYREF

  partitionSizes.m_data = 0i64;
  partitionSizes.m_size = 0;
  partitionSizes.m_capacityAndFlags = 0x80000000;
  partitions.m_data = 0i64;
  partitions.m_size = 0;
  partitions.m_capacityAndFlags = 0x80000000;
  vertexUnionFind(&resulta, mesh, &partitionSizes, &partitions);
  if ( resulta.m_enum )
  {
    result->m_enum = HK_FAILURE;
    goto LABEL_32;
  }
  m_size = mesh->m_vertices.m_size;
  v5 = 0;
  array = 0i64;
  v29 = 0;
  v30 = 0x80000000;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_8;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v5 = v29;
LABEL_8:
    v6 = mesh->m_vertices.m_size;
    if ( (v30 & 0x3FFFFFFF) < v6 )
    {
      v7 = mesh->m_vertices.m_size;
      if ( v6 < 2 * (v30 & 0x3FFFFFFF) )
        v7 = 2 * (v30 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v34, &hkContainerTempAllocator::s_alloc, &array, v7, 4);
      v5 = v29;
    }
    v8 = &array[v5];
    v9 = v6 - v5;
    if ( v6 - v5 > 0 )
    {
      while ( v9 )
      {
        *v8++ = -1;
        --v9;
      }
    }
    m_data = partitions.m_data;
    v29 = v6;
    v11 = 0;
    if ( partitionSizes.m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = 0i64;
        v14 = partitionSizes.m_data[v12];
        if ( (int)v14 > 0 )
        {
          do
          {
            v15 = m_data[v13++];
            array[v15] = *m_data;
          }
          while ( v13 < v14 );
        }
        if ( (int)v14 > 1 )
        {
          v16 = 0i64;
          v17 = 0i64;
          v18 = 0i64;
          do
          {
            v19 = m_data[v17++];
            v18 = _mm_add_ps(v18, mesh->m_vertices.m_data[v19].m_quad);
          }
          while ( v17 < v14 );
          v16.m128_f32[0] = (float)(int)v14;
          v20 = 0i64;
          v21 = _mm_mul_ps(v18, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v16, v16, 0)));
          do
          {
            v22 = m_data[v20++];
            mesh->m_vertices.m_data[v22].m_quad = v21;
          }
          while ( v20 < v14 );
        }
        ++v11;
        ++v12;
        m_data += v14;
      }
      while ( v11 < partitionSizes.m_size );
    }
    v23 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v24 = 0i64;
      do
      {
        v25 = mesh->m_edges.m_data;
        ++v23;
        m_a = v25[v24++].m_a;
        v25[v24 - 1].m_a = array[m_a];
        v25[v24 - 1].m_b = array[v25[v24 - 1].m_b];
      }
      while ( v23 < mesh->m_edges.m_size );
    }
    result->m_enum = HK_SUCCESS;
    goto LABEL_29;
  }
  result->m_enum = HK_FAILURE;
LABEL_29:
  v29 = 0;
  if ( v30 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v30);
  v30 = 0x80000000;
  array = 0i64;
LABEL_32:
  partitions.m_size = 0;
  if ( partitions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partitions.m_data,
      4 * partitions.m_capacityAndFlags);
  partitions.m_data = 0i64;
  partitions.m_capacityAndFlags = 0x80000000;
  partitionSizes.m_size = 0;
  if ( partitionSizes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partitionSizes.m_data,
      4 * partitionSizes.m_capacityAndFlags);
  return result;
}

// File Line: 258
// RVA: 0xB502F0
hkVector4f *__fastcall hkaiNavMeshSimplificationUtils::_classToDir(hkVector4f *result, int i)
{
  unsigned int v2; // eax
  hkVector4f *v3; // rax

  v2 = _S1_41;
  if ( (_S1_41 & 1) == 0 )
  {
    v2 = _S1_41 | 1;
    _S1_41 |= 1u;
    directions[0] = (hkVector4f)transform.m_quad;
    xmmword_1424A1390 = (__int128)direction.m_quad;
    xmmword_1424A13A0 = (__int128)stru_141A71280.m_quad;
  }
  if ( (v2 & 2) == 0 )
  {
    _S1_41 = v2 | 2;
    signMuls[0] = (hkVector4f)g_vectorfConstants[0];
    xmmword_1424A13D0 = (__int128)query.m_quad;
  }
  v3 = result;
  result->m_quad = _mm_mul_ps(signMuls[i & 1].m_quad, directions[i / 2].m_quad);
  return v3;
}

// File Line: 334
// RVA: 0xB496A0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::tracePartitionBoundaries(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitions,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsOut,
        hkArray<int,hkContainerHeapAllocator> *edgesToRemove)
{
  int m_size; // r9d
  hkaiNavMesh *v9; // r13
  hkResult *v10; // r12
  int v11; // edi
  int v12; // r8d
  int v14; // ebx
  int v15; // r9d
  __int64 v16; // rcx
  char *v17; // rdi
  int v18; // r8d
  __int64 v19; // r9
  hkaiNavMesh::Face *v20; // rdi
  __int64 m_startEdgeIndex; // rcx
  __int64 v22; // rdx
  int v23; // r9d
  int v24; // edx
  int v25; // ebx
  int v26; // r9d
  char *v27; // rdi
  __int64 v28; // rcx
  int *m_data; // r11
  __int64 v30; // r8
  __int64 v31; // rbx
  __int64 v32; // r9
  __int64 v33; // r10
  hkaiNavMesh::Face *v34; // rdx
  __int64 v35; // rax
  __int64 v36; // rdi
  int v37; // ebx
  int v38; // edi
  __int32 v39; // eax
  float *v40; // r9
  int m_capacityAndFlags; // r8d
  int v42; // r9d
  __int64 v43; // r8
  float *v44; // rdx
  __int64 v45; // rcx
  float *v46; // rdi
  hkpRigidBody **v47; // r10
  int v48; // ebx
  hkArray<int,hkContainerHeapAllocator> *v49; // r12
  int m_tail; // r8d
  int m_elementsInUse; // r9d
  int m_capacity; // r10d
  hkpRigidBody **v53; // r11
  __int64 v54; // rsi
  __int64 v55; // r14
  _DWORD *v56; // r15
  __int64 m_oppositeEdge; // rcx
  int v58; // eax
  __int64 v59; // rdi
  int v60; // edx
  __int64 v61; // rcx
  int *v62; // rax
  int v63; // edx
  __int64 v64; // rax
  hkResult *v65; // rsi
  int m_head; // ecx
  __int64 v67; // r9
  int v68; // r8d
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
  __int64 v81; // r10
  int v82; // r11d
  int m_numEdges; // edi
  int v84; // r8d
  int v85; // edi
  int v86; // r8d
  __int64 v87; // r10
  int v88; // r8d
  __int64 v89; // rcx
  int v90; // r11d
  __int64 v91; // r13
  int v92; // r12d
  __int64 v93; // r14
  int v94; // r10d
  hkResultEnum v95; // esi
  signed int v96; // eax
  hkResultEnum m_enum; // ecx
  int v98; // ebx
  hkaiNavMesh *v99; // r15
  int v100; // edx
  __int64 v101; // rdi
  __int64 v102; // rcx
  int v103; // r10d
  __int64 v104; // rax
  hkaiNavMesh::Edge *v105; // rdx
  hkaiNavMesh::Face *v106; // rsi
  int v107; // r9d
  int v108; // eax
  int v109; // eax
  bool v110; // sf
  signed int v111; // eax
  __int64 v112; // rbx
  int *v113; // rdi
  int v114; // r8d
  int v115; // r8d
  hkaiNavMesh::Face *v116; // r11
  int *v117; // r8
  int v118; // edi
  hkaiNavMesh::Edge *v119; // rcx
  int v120; // r8d
  int v121; // edi
  int v122; // r8d
  __int64 v123; // rdx
  int v124; // edi
  int v125; // r8d
  signed int v126; // eax
  __int64 v127; // rbx
  int *v128; // rdi
  int v129; // r8d
  int v130; // r8d
  int v131; // edi
  int v132; // r8d
  int v133; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v134; // rdi
  int v135; // r8d
  __int64 v136; // rdx
  __int64 v137; // rdi
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v138; // rsi
  __int64 v139; // r14
  int v140; // eax
  int v141; // eax
  int v142; // edi
  hkaiNavMeshSimplificationUtils::Segment *v143; // rbx
  __int64 v144; // rcx
  __int64 v145; // rdx
  __int64 p_m_capacityAndFlags; // rcx
  int v147; // r8d
  int v148; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v149; // rdi
  int v150; // ebx
  __int64 v151; // rdi
  __int64 v152; // r14
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v153; // rdx
  int v154; // r8d
  int v155; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v156; // rdi
  hkResult resulta; // [rsp+30h] [rbp-A9h] BYREF
  char *v158; // [rsp+38h] [rbp-A1h] BYREF
  int v159; // [rsp+40h] [rbp-99h]
  int v160; // [rsp+44h] [rbp-95h]
  hkResult v161[2]; // [rsp+48h] [rbp-91h] BYREF
  unsigned int v162; // [rsp+50h] [rbp-89h]
  int v163; // [rsp+54h] [rbp-85h]
  int v164; // [rsp+58h] [rbp-81h]
  char *array; // [rsp+60h] [rbp-79h] BYREF
  int v166; // [rsp+68h] [rbp-71h]
  int v167; // [rsp+6Ch] [rbp-6Dh]
  int v168; // [rsp+70h] [rbp-69h]
  int v169; // [rsp+74h] [rbp-65h]
  SegmentInfo *pArr; // [rsp+78h] [rbp-61h] BYREF
  int v171; // [rsp+80h] [rbp-59h]
  int v172; // [rsp+84h] [rbp-55h]
  hkaMatrix<float> v173; // [rsp+88h] [rbp-51h] BYREF
  hkQueue<hkpRigidBody *> v174; // [rsp+A0h] [rbp-39h] BYREF
  int v175; // [rsp+B8h] [rbp-21h]
  hkResult v176; // [rsp+BCh] [rbp-1Dh] BYREF
  int v177; // [rsp+C0h] [rbp-19h]
  hkResult v178; // [rsp+C4h] [rbp-15h] BYREF
  int v179; // [rsp+C8h] [rbp-11h]
  hkaiNavMesh::Face *v180; // [rsp+D0h] [rbp-9h]
  unsigned int v181; // [rsp+D8h] [rbp-1h]
  __int64 v182; // [rsp+E0h] [rbp+7h]
  hkResult v183; // [rsp+E8h] [rbp+Fh] BYREF
  int v184; // [rsp+ECh] [rbp+13h]
  hkaiNavMesh *v186; // [rsp+138h] [rbp+5Fh] BYREF

  v186 = mesh;
  m_size = mesh->m_edges.m_size;
  v9 = mesh;
  v10 = result;
  array = 0i64;
  v11 = 0;
  v166 = 0;
  v167 = 0x80000000;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
      v12 = v167;
      v10->m_enum = HK_FAILURE;
      v166 = 0;
      if ( v12 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v12);
      return v10;
    }
    v11 = v166;
  }
  v14 = v9->m_edges.m_size;
  if ( (v167 & 0x3FFFFFFF) < v14 )
  {
    v15 = v9->m_edges.m_size;
    if ( v14 < 2 * (v167 & 0x3FFFFFFF) )
      v15 = 2 * (v167 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v176, &hkContainerHeapAllocator::s_alloc, &array, v15, 4);
    v11 = v166;
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
  v166 = v14;
  v18 = 0;
  if ( v9->m_faces.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = &v9->m_faces.m_data[v19];
      m_startEdgeIndex = v20->m_startEdgeIndex;
      if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v20->m_numEdges )
      {
        v22 = 4 * m_startEdgeIndex;
        do
        {
          LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
          v22 += 4i64;
          *(_DWORD *)&array[v22 - 4] = v18;
        }
        while ( (int)m_startEdgeIndex < v20->m_startEdgeIndex + v20->m_numEdges );
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v9->m_faces.m_size );
  }
  v23 = v9->m_edges.m_size;
  v24 = 0;
  v158 = 0i64;
  v159 = 0;
  v160 = 0x80000000;
  if ( v23 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v158, v23, 4);
    if ( resulta.m_enum )
    {
      v10->m_enum = HK_FAILURE;
LABEL_265:
      v159 = 0;
      if ( v160 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v158, 4 * v160);
      v166 = 0;
      v160 = 0x80000000;
      v158 = 0i64;
      if ( v167 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v167);
      return v10;
    }
    v24 = v159;
  }
  v25 = v9->m_edges.m_size;
  if ( (v160 & 0x3FFFFFFF) < v25 )
  {
    v26 = v9->m_edges.m_size;
    if ( v25 < 2 * (v160 & 0x3FFFFFFF) )
      v26 = 2 * (v160 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v176, &hkContainerHeapAllocator::s_alloc, &v158, v26, 4);
    v24 = v159;
  }
  v27 = &v158[4 * v24];
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
  m_data = partitions->m_data;
  v159 = v25;
  v30 = 0i64;
  if ( numFacesInPartition->m_size > 0 )
  {
    v31 = 0i64;
    do
    {
      v32 = 0i64;
      v33 = numFacesInPartition->m_data[v31];
      if ( v33 > 0 )
      {
        do
        {
          v34 = &v9->m_faces.m_data[m_data[v32]];
          v35 = v34->m_startEdgeIndex;
          if ( (int)v35 < (int)v35 + v34->m_numEdges )
          {
            v36 = 4 * v35;
            do
            {
              LODWORD(v35) = v35 + 1;
              v36 += 4i64;
              *(_DWORD *)&v158[v36 - 4] = v30;
            }
            while ( (int)v35 < v34->m_startEdgeIndex + v34->m_numEdges );
          }
          ++v32;
        }
        while ( v32 < v33 );
      }
      v30 = (unsigned int)(v30 + 1);
      ++v31;
      m_data += v33;
    }
    while ( (int)v30 < numFacesInPartition->m_size );
  }
  v37 = v9->m_edges.m_size;
  v173.m_data.m_data = 0i64;
  v173.m_data.m_size = 0;
  v173.m_data.m_capacityAndFlags = 0x80000000;
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
  m_capacityAndFlags = 0x80000000;
  v173.m_data.m_data = v40;
  if ( v39 )
    m_capacityAndFlags = v39;
  v173.m_data.m_size = (v37 + 31) >> 5;
  v173.m_m = v37;
  v173.m_data.m_capacityAndFlags = m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < v38 )
  {
    v42 = (v37 + 31) >> 5;
    if ( v38 < 2 * (m_capacityAndFlags & 0x3FFFFFFF) )
      v42 = 2 * (m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v176, &hkContainerHeapAllocator::s_alloc, &v173, v42, 4);
    m_capacityAndFlags = v173.m_data.m_capacityAndFlags;
    v40 = v173.m_data.m_data;
  }
  v173.m_data.m_size = (v37 + 31) >> 5;
  if ( !v40 )
  {
    v10->m_enum = HK_FAILURE;
    v173.m_data.m_size = 0;
    if ( m_capacityAndFlags < 0 )
    {
LABEL_55:
      v173.m_data.m_data = 0i64;
      v173.m_data.m_capacityAndFlags = 0x80000000;
      goto LABEL_265;
    }
    v43 = (unsigned int)(4 * m_capacityAndFlags);
    v44 = 0i64;
LABEL_54:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v44, v43);
    goto LABEL_55;
  }
  if ( v38 - 1 >= 0 )
  {
    v45 = (unsigned int)v38;
    v46 = v40;
    while ( v45 )
    {
      *v46++ = 0.0;
      --v45;
    }
  }
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v174);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v174, 8);
  v47 = v174.m_data;
  if ( !v174.m_data )
  {
    v10->m_enum = HK_FAILURE;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v174);
    v173.m_data.m_size = 0;
    if ( v173.m_data.m_capacityAndFlags < 0 )
      goto LABEL_55;
    v44 = v173.m_data.m_data;
    v43 = (unsigned int)(4 * v173.m_data.m_capacityAndFlags);
    goto LABEL_54;
  }
  v48 = 0;
  if ( v9->m_edges.m_size <= 0 )
  {
    v56 = v158;
  }
  else
  {
    v49 = edgesToRemove;
    m_tail = v174.m_tail;
    m_elementsInUse = v174.m_elementsInUse;
    m_capacity = v174.m_capacity;
    v53 = v174.m_data;
    v54 = 0i64;
    v55 = 0i64;
    v56 = v158;
    do
    {
      m_oppositeEdge = (int)v9->m_edges.m_data[v54].m_oppositeEdge;
      if ( (_DWORD)m_oppositeEdge == -1 )
        v58 = -1;
      else
        v58 = v56[m_oppositeEdge];
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
          LODWORD(v173.m_data.m_data[(__int64)v48 >> 5]) |= 1 << (v48 & 0x1F);
          if ( m_elementsInUse >= m_capacity )
          {
            hkQueue<int>::setCapacity((hkQueue<int> *)&v174, 2 * m_capacity);
            v53 = v174.m_data;
            if ( !v174.m_data )
            {
              v65 = result;
              result->m_enum = HK_FAILURE;
              hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v174);
              v173.m_data.m_size = 0;
              if ( v173.m_data.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  v173.m_data.m_data,
                  4 * v173.m_data.m_capacityAndFlags);
              v173.m_data.m_data = 0i64;
              v173.m_data.m_capacityAndFlags = 0x80000000;
              v159 = 0;
              if ( v160 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v158, 4 * v160);
              v158 = 0i64;
              v166 = 0;
              goto LABEL_211;
            }
            m_elementsInUse = v174.m_elementsInUse;
            if ( v174.m_elementsInUse >= v174.m_capacity )
            {
              v63 = 8;
              if ( v174.m_capacity )
                v63 = 2 * v174.m_capacity;
              hkQueue<int>::setCapacity((hkQueue<int> *)&v174, v63);
              v53 = v174.m_data;
              m_elementsInUse = v174.m_elementsInUse;
            }
            m_tail = v174.m_tail;
            m_capacity = v174.m_capacity;
          }
          if ( m_tail == m_capacity )
            m_tail = 0;
          v64 = m_tail++;
          ++m_elementsInUse;
          *((_DWORD *)v53 + v64) = v48;
          v56 = v158;
          v174.m_elementsInUse = m_elementsInUse;
          v174.m_tail = m_tail;
        }
      }
      ++v48;
      ++v55;
      ++v54;
    }
    while ( v48 < v9->m_edges.m_size );
    v47 = v174.m_data;
  }
  m_head = v174.m_head;
  v163 = 0x80000000;
  *(_QWORD *)&v161[0].m_enum = 0i64;
  v67 = 0i64;
  v181 = 0;
  v162 = 0;
LABEL_94:
  v68 = v174.m_elementsInUse;
  if ( !v174.m_elementsInUse )
    goto LABEL_214;
  while ( 1 )
  {
    v69 = m_head;
    v70 = m_head + 1;
    v71 = *((int *)v47 + v69);
    if ( v70 == v174.m_capacity )
      v70 = 0;
    --v68;
    v179 = v70;
    v174.m_head = v70;
    v177 = v71;
    v174.m_elementsInUse = v68;
    if ( ((LODWORD(v173.m_data.m_data[v71 >> 5]) >> (v71 & 0x1F)) & 1) != 0 )
      break;
    if ( !v68 )
      goto LABEL_214;
    m_head = v179;
  }
  v175 = v71;
  if ( (_DWORD)v71 == -1 )
  {
LABEL_214:
    v172 = 0x80000000;
    v131 = v67;
    pArr = 0i64;
    v171 = 0;
    if ( (int)v67 <= 0 )
    {
      LODWORD(v186) = 0;
    }
    else
    {
      hkArrayUtil::_reserve((hkResult *)&v186, &hkContainerTempAllocator::s_alloc, &pArr, v67, 16);
      if ( (_DWORD)v186 )
      {
        v10 = result;
        v132 = v172;
        v171 = 0;
        result->m_enum = HK_FAILURE;
        if ( v132 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 16 * v132);
        pArr = 0i64;
        v172 = 0x80000000;
        v133 = v162 - 1;
        if ( (int)(v162 - 1) >= 0 )
        {
          v134 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v161[0].m_enum + 48i64 * v133);
          do
          {
            hkaiNavMeshSimplificationUtils::Segment::~Segment(v134--);
            --v133;
          }
          while ( v133 >= 0 );
        }
        goto LABEL_262;
      }
      v67 = v162;
    }
    v171 = v131;
    v135 = 0;
    if ( v131 > 0 )
    {
      v136 = 0i64;
      v137 = 0i64;
      do
      {
        v137 += 48i64;
        pArr[v136++].m_segmentIndex = v135++;
        pArr[v136 - 1].m_partitionIdA = *(_DWORD *)(*(_QWORD *)&v161[0].m_enum + v137 - 44);
        pArr[v136 - 1].m_partitionIdB = *(_DWORD *)(*(_QWORD *)&v161[0].m_enum + v137 - 40);
        pArr[v136 - 1].m_boundarySize = *(_DWORD *)(*(_QWORD *)&v161[0].m_enum + v137 - 24);
      }
      while ( v135 < v171 );
      v67 = v162;
    }
    if ( v171 > 1 )
    {
      hkAlgorithm::quickSortRecursive<`anonymous namespace::SegmentInfo,hkAlgorithm::less<`anonymous namespace::SegmentInfo>>(
        pArr,
        0,
        v171 - 1,
        0);
      v67 = v162;
    }
    v138 = segmentsOut;
    v139 = (int)v67;
    v140 = segmentsOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v140 >= (int)v67 )
    {
      v178.m_enum = HK_SUCCESS;
    }
    else
    {
      v141 = 2 * v140;
      if ( (int)v67 < v141 )
        LODWORD(v67) = v141;
      hkArrayUtil::_reserve(&v178, &hkContainerHeapAllocator::s_alloc, segmentsOut, v67, 48);
      v67 = v162;
      if ( v178.m_enum )
        goto LABEL_247;
    }
    v142 = v138->m_size - v139 - 1;
    if ( v142 >= 0 )
    {
      v143 = &v138->m_data[v139 + v142];
      do
      {
        hkaiNavMeshSimplificationUtils::Segment::~Segment(v143--);
        --v142;
      }
      while ( v142 >= 0 );
      v67 = v162;
    }
    v144 = v138->m_size;
    v145 = (int)v139 - (int)v144;
    if ( (int)v139 - (int)v144 > 0 )
    {
      p_m_capacityAndFlags = (__int64)&v138->m_data[v144].m_boundary.m_capacityAndFlags;
      do
      {
        if ( p_m_capacityAndFlags != 28 )
        {
          *(_QWORD *)(p_m_capacityAndFlags - 12) = 0i64;
          *(_DWORD *)(p_m_capacityAndFlags - 4) = 0;
          *(_DWORD *)p_m_capacityAndFlags = 0x80000000;
          *(_QWORD *)(p_m_capacityAndFlags + 4) = 0i64;
          *(_DWORD *)(p_m_capacityAndFlags + 12) = 0;
          *(_DWORD *)(p_m_capacityAndFlags + 16) = 0x80000000;
        }
        p_m_capacityAndFlags += 48i64;
        --v145;
      }
      while ( v145 );
      v67 = v162;
    }
    v138->m_size = v139;
    if ( v178.m_enum == HK_SUCCESS )
    {
      v150 = 0;
      if ( v171 > 0 )
      {
        v151 = 0i64;
        v152 = 0i64;
        do
        {
          v153 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(*(_QWORD *)&v161[0].m_enum
                                                                              + 48i64 * pArr[v152].m_segmentIndex
                                                                              + 16);
          v138->m_data[v151].m_partitionIdA = *(_DWORD *)(*(_QWORD *)&v161[0].m_enum
                                                        + 48i64 * pArr[v152].m_segmentIndex
                                                        + 4);
          v138->m_data[v151].m_partitionIdB = v153[-1].m_size;
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v138->m_data[v150++].m_boundary,
            v153);
          ++v152;
          ++v151;
        }
        while ( v150 < v171 );
        v67 = v162;
      }
      v10 = result;
      v154 = v172;
      v171 = 0;
      result->m_enum = HK_SUCCESS;
      if ( v154 >= 0 )
      {
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, SegmentInfo *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          (unsigned int)(16 * v154),
          v67);
        LODWORD(v67) = v162;
      }
      v155 = v67 - 1;
      pArr = 0i64;
      v172 = 0x80000000;
      if ( (int)v67 - 1 >= 0 )
      {
        v156 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v161[0].m_enum + 48i64 * v155);
        do
        {
          hkaiNavMeshSimplificationUtils::Segment::~Segment(v156--);
          --v155;
        }
        while ( v155 >= 0 );
      }
      goto LABEL_262;
    }
LABEL_247:
    v10 = result;
    v147 = v172;
    v171 = 0;
    result->m_enum = HK_FAILURE;
    if ( v147 >= 0 )
    {
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, SegmentInfo *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        pArr,
        (unsigned int)(16 * v147),
        v67);
      LODWORD(v67) = v162;
    }
    v148 = v67 - 1;
    pArr = 0i64;
    v172 = 0x80000000;
    if ( (int)v67 - 1 >= 0 )
    {
      v149 = (hkaiNavMeshSimplificationUtils::Segment *)(*(_QWORD *)&v161[0].m_enum + 48i64 * v148);
      do
      {
        hkaiNavMeshSimplificationUtils::Segment::~Segment(v149--);
        --v148;
      }
      while ( v148 >= 0 );
    }
LABEL_262:
    v162 = 0;
    if ( v163 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&v161[0].m_enum,
        48 * (v163 & 0x3FFFFFFF));
    *(_QWORD *)&v161[0].m_enum = 0i64;
    v163 = 0x80000000;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v174);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v173);
    goto LABEL_265;
  }
  v72 = v9->m_edges.m_data;
  v73 = v56[v71];
  v74 = (int)v72[v71].m_oppositeEdge;
  v75 = v71;
  v76 = v71;
  resulta.m_enum = (int)v74;
  v184 = v74;
  v168 = v73;
  if ( (_DWORD)v74 == -1 )
    v164 = -1;
  else
    v164 = v56[v74];
  if ( (_DWORD)v74 == -1 )
  {
    LODWORD(v77) = v73;
  }
  else
  {
    v78 = (int)v72[v74].m_oppositeEdge;
    if ( (_DWORD)v78 == -1 )
      LODWORD(v77) = -1;
    else
      LODWORD(v77) = v56[v78];
  }
  v79 = v186->m_faces.m_data;
  v180 = v79;
  while ( 1 )
  {
    v80 = v79[*(int *)&array[4 * v76]].m_startEdgeIndex;
    v75 = v80 + (v75 - 1 + v79[*(int *)&array[4 * v76]].m_numEdges - v80) % v79[*(int *)&array[4 * v76]].m_numEdges;
    v76 = v75;
    v169 = v75;
    v182 = v75;
    v81 = (int)v72[v75].m_oppositeEdge;
    if ( (_DWORD)v81 == -1 )
      v82 = -1;
    else
      v82 = v56[v81];
    if ( v168 == v82 )
    {
      do
      {
        if ( v75 == (_DWORD)v71 )
          break;
        m_numEdges = v79[*(int *)&array[4 * (int)v81]].m_numEdges;
        v84 = v79[*(int *)&array[4 * (int)v81]].m_startEdgeIndex;
        v75 = v84 + ((int)v81 - 1 + m_numEdges - v84) % m_numEdges;
        v76 = v75;
        v81 = (int)v72[v75].m_oppositeEdge;
        v82 = (_DWORD)v81 == -1 ? -1 : v56[v81];
        v79 = v180;
      }
      while ( v168 == v82 );
      LODWORD(v74) = resulta;
      v182 = v76;
      v169 = v75;
    }
    if ( (_DWORD)v74 == -1 )
    {
      v88 = v164;
    }
    else
    {
      v85 = v79[*(int *)&array[4 * (int)v74]].m_numEdges;
      v86 = v79[*(int *)&array[4 * (int)v74]].m_startEdgeIndex;
      LODWORD(v74) = v86 + ((int)v74 + 1 + v85 - v86) % v85;
      resulta.m_enum = (int)v74;
      v87 = (int)v72[(int)v74].m_oppositeEdge;
      if ( (_DWORD)v87 == -1 )
        LODWORD(v77) = -1;
      else
        LODWORD(v77) = v56[v87];
      v88 = v164;
      if ( v164 == (_DWORD)v77 )
      {
        do
        {
          if ( (_DWORD)v74 == v184 )
            break;
          v89 = (__int64)&v186->m_faces.m_data[*(int *)&array[4 * (int)v87]];
          LODWORD(v74) = *(_DWORD *)v89
                       + ((int)v87 + 1 + *(__int16 *)(v89 + 8) - *(_DWORD *)v89) % *(__int16 *)(v89 + 8);
          v87 = (int)v72[(int)v74].m_oppositeEdge;
          LODWORD(v77) = (_DWORD)v87 == -1 ? -1 : v56[v87];
          v88 = v164;
        }
        while ( v164 == (_DWORD)v77 );
        v75 = v169;
        LODWORD(v71) = v177;
        v76 = v182;
        resulta.m_enum = (int)v74;
      }
    }
    if ( v168 != (_DWORD)v77 || v88 != v82 )
      break;
    v79 = v180;
    v90 = v75;
    v175 = v75;
    if ( v75 == (_DWORD)v71 )
      goto LABEL_137;
  }
  v90 = v175;
LABEL_137:
  v91 = v90;
  v92 = v90;
  v93 = (int)v186->m_edges.m_data[v90].m_oppositeEdge;
  v169 = v93;
  v177 = v93;
  if ( v90 == -1 )
    v94 = -1;
  else
    v94 = v56[v90];
  v168 = v94;
  if ( (_DWORD)v93 == -1 )
    v95 = -1;
  else
    v95 = v56[v93];
  v96 = v181;
  m_enum = v95;
  v98 = -2;
  resulta.m_enum = v95;
  v164 = -2;
  v180 = 0i64;
  while ( 1 )
  {
    if ( v94 == v98 && m_enum == v95 )
    {
      v99 = v186;
      goto LABEL_159;
    }
    v99 = v186;
    if ( v96 > v186->m_edges.m_size )
      __debugbreak();
    hkaiArrayUtil::reserveForNonPodType<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v176,
      v161,
      (hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *)(unsigned int)(v96 + 1),
      (int)v77);
    if ( v176.m_enum )
      break;
    v100 = v162;
    if ( v162 == (v163 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v161, 48);
      v100 = v162;
    }
    v101 = *(_QWORD *)&v161[0].m_enum;
    v102 = *(_QWORD *)&v161[0].m_enum + 48i64 * v100;
    if ( v102 )
    {
      *(_QWORD *)(v102 + 16) = 0i64;
      *(_DWORD *)(v102 + 24) = 0;
      *(_DWORD *)(v102 + 28) = 0x80000000;
      *(_QWORD *)(v102 + 32) = 0i64;
      *(_DWORD *)(v102 + 40) = 0;
      *(_DWORD *)(v102 + 44) = 0x80000000;
      v100 = v162;
      v101 = *(_QWORD *)&v161[0].m_enum;
    }
    v103 = v168;
    v162 = v100 + 1;
    resulta.m_enum = v95;
    v104 = v101 + 48i64 * v100;
    v180 = (hkaiNavMesh::Face *)v104;
    *(_DWORD *)(v104 + 4) = v168;
    *(_DWORD *)(v104 + 8) = v95;
    v105 = v99->m_edges.m_data;
    v93 = (int)v105[v91].m_oppositeEdge;
    v169 = v93;
    if ( (_DWORD)v93 == -1 )
    {
      v98 = v103;
      v164 = v103;
    }
    else if ( v105[v93].m_oppositeEdge == -1 )
    {
      v98 = -1;
      v164 = -1;
    }
    else
    {
      v98 = *(_DWORD *)&v158[4 * v105[v93].m_oppositeEdge];
      v164 = v98;
    }
LABEL_159:
    v106 = v180;
    v107 = *(_DWORD *)&v180[1].m_numEdges + 1;
    v108 = *(_DWORD *)&v180[1].m_clusterIndex & 0x3FFFFFFF;
    if ( v108 >= v107 )
    {
      v183.m_enum = HK_SUCCESS;
    }
    else
    {
      v109 = 2 * v108;
      if ( v107 < v109 )
        v107 = v109;
      hkArrayUtil::_reserve(&v183, &hkContainerHeapAllocator::s_alloc, &v180[1], v107, 4);
      if ( v183.m_enum )
      {
        v65 = result;
        v110 = (int)(v162 - 1) < 0;
        v111 = v162 - 1;
        result->m_enum = HK_FAILURE;
        v112 = v111;
        if ( !v110 )
        {
          v113 = (int *)(48i64 * v111 + *(_QWORD *)&v161[0].m_enum + 44i64);
          do
          {
            v114 = *v113;
            *(v113 - 1) = 0;
            if ( v114 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v113 - 3),
                4 * v114);
            *(_QWORD *)(v113 - 3) = 0i64;
            *v113 = 0x80000000;
            v115 = *(v113 - 4);
            *(v113 - 5) = 0;
            if ( v115 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v113 - 7),
                4 * v115);
            *(_QWORD *)(v113 - 7) = 0i64;
            *(v113 - 4) = 0x80000000;
            v113 -= 12;
            --v112;
          }
          while ( v112 >= 0 );
        }
        goto LABEL_204;
      }
    }
    *(_DWORD *)(*(_QWORD *)&v106[1].m_startEdgeIndex + 4i64 * (int)(*(_DWORD *)&v106[1].m_numEdges)++) = v92;
    LODWORD(v173.m_data.m_data[v91 >> 5]) &= ~(1 << (v92 & 0x1F));
    v116 = v99->m_faces.m_data;
    v117 = (int *)array;
    v118 = v116[*(int *)&array[4 * v91]].m_startEdgeIndex;
    v119 = v99->m_edges.m_data;
    v56 = v158;
    v92 = v118 + (v92 + 1 + v116[*(int *)&array[4 * v91]].m_numEdges - v118) % v116[*(int *)&array[4 * v91]].m_numEdges;
    v91 = v92;
    v182 = v92;
    v77 = (hkaiNavMesh::Edge *)(int)v119[v92].m_oppositeEdge;
    if ( (_DWORD)v77 == -1 )
      v95 = -1;
    else
      v95 = *(_DWORD *)&v158[4 * (_QWORD)v77];
    v94 = v168;
    if ( v168 == v95 )
    {
      do
      {
        if ( v92 == v175 )
          break;
        v120 = v116[*(int *)&array[4 * (int)v77]].m_startEdgeIndex;
        v92 = v120
            + ((int)v77 + 1 + v116[*(int *)&array[4 * (int)v77]].m_numEdges - v120)
            % v116[*(int *)&array[4 * (int)v77]].m_numEdges;
        v91 = v92;
        v77 = (hkaiNavMesh::Edge *)(int)v186->m_edges.m_data[v92].m_oppositeEdge;
        v95 = (_DWORD)v77 == -1 ? -1 : *(_DWORD *)&v158[4 * (_QWORD)v77];
      }
      while ( v168 == v95 );
      v98 = v164;
      LODWORD(v93) = v169;
      v117 = (int *)array;
      v182 = v91;
    }
    if ( (_DWORD)v93 == -1 )
    {
      m_enum = resulta.m_enum;
    }
    else
    {
      v121 = v116[v117[(int)v93]].m_numEdges;
      v122 = v116[v117[(int)v93]].m_startEdgeIndex;
      LODWORD(v93) = v122 + ((int)v93 - 1 + v121 - v122) % v121;
      v169 = v93;
      v77 = v186->m_edges.m_data;
      v123 = (int)v77[(int)v93].m_oppositeEdge;
      if ( (_DWORD)v123 == -1 )
        v98 = -1;
      else
        v98 = *(_DWORD *)&v158[4 * v123];
      m_enum = resulta.m_enum;
      v164 = v98;
      if ( resulta.m_enum == v98 )
      {
        do
        {
          if ( (_DWORD)v93 == v177 )
            break;
          v124 = v116[*(int *)&array[4 * (int)v123]].m_numEdges;
          v125 = v116[*(int *)&array[4 * (int)v123]].m_startEdgeIndex;
          LODWORD(v93) = v125 + ((int)v123 - 1 + v124 - v125) % v124;
          v123 = (int)v77[(int)v93].m_oppositeEdge;
          v98 = (_DWORD)v123 == -1 ? -1 : *(_DWORD *)&v158[4 * v123];
          m_enum = resulta.m_enum;
        }
        while ( resulta.m_enum == v98 );
        v91 = v182;
        v94 = v168;
        v169 = v93;
        v164 = v98;
      }
    }
    if ( v92 == v175 )
    {
      v67 = v162;
      m_head = v179;
      v9 = v186;
      v47 = v174.m_data;
      v181 = v162;
      goto LABEL_94;
    }
    v96 = v162;
  }
  v65 = result;
  v110 = (int)(v162 - 1) < 0;
  v126 = v162 - 1;
  result->m_enum = HK_FAILURE;
  v127 = v126;
  if ( !v110 )
  {
    v128 = (int *)(48i64 * v126 + *(_QWORD *)&v161[0].m_enum + 44i64);
    do
    {
      v129 = *v128;
      *(v128 - 1) = 0;
      if ( v129 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v128 - 3),
          4 * v129);
      *(_QWORD *)(v128 - 3) = 0i64;
      *v128 = 0x80000000;
      v130 = *(v128 - 4);
      *(v128 - 5) = 0;
      if ( v130 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v128 - 7),
          4 * v130);
      *(_QWORD *)(v128 - 7) = 0i64;
      *(v128 - 4) = 0x80000000;
      v128 -= 12;
      --v127;
    }
    while ( v127 >= 0 );
  }
LABEL_204:
  v162 = 0;
  if ( v163 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&v161[0].m_enum,
      48 * (v163 & 0x3FFFFFFF));
  *(_QWORD *)&v161[0].m_enum = 0i64;
  v163 = 0x80000000;
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v174);
  v173.m_data.m_size = 0;
  if ( v173.m_data.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v173.m_data.m_data,
      4 * v173.m_data.m_capacityAndFlags);
  v159 = 0;
  v173.m_data.m_capacityAndFlags = 0x80000000;
  v173.m_data.m_data = 0i64;
  if ( v160 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v158, 4 * v160);
  v158 = 0i64;
  v166 = 0;
LABEL_211:
  v160 = 0x80000000;
  if ( v167 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v167);
  return v65;
} )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v167);
  return v65;
}

// File Line: 926
// RVA: 0xB506E0
void __fastcall anonymous_namespace_::getProjectionMatrix(int majorAxis, hkRotationf *projectionMatrix)
{
  __m128 m_quad; // xmm3
  __m128 v3; // xmm4
  __m128 v4; // xmm2
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx

  m_quad = transform.m_quad;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      m_quad = _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 216), (__m128)xmmword_141A71320);
    }
    else if ( majorAxis != 2 )
    {
      if ( majorAxis == 3 )
      {
        m_quad = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 230);
      }
      else if ( majorAxis == 4 )
      {
        m_quad = _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 210), (__m128)xmmword_141A71320);
      }
      else
      {
        m_quad = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 225);
      }
    }
  }
  else
  {
    m_quad = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 233);
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
  projectionMatrix->m_col0.m_quad = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 180);
  projectionMatrix->m_col1.m_quad = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, (__m128)0i64), 180);
  projectionMatrix->m_col2.m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, (__m128)0i64), 180);
}

// File Line: 950
// RVA: 0xB507E0
hkSimdFloat32 *__fastcall `anonymous namespace::computeSignedLoopArea(
        hkSimdFloat32 *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<int,hkContainerHeapAllocator> *indices,
        int majorAxis)
{
  hkVector4f *m_data; // r11
  int *v5; // r10
  __m128 v6; // xmm4
  __m128 m_quad; // xmm5
  __int64 v8; // rdx
  __int64 v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  hkSimdFloat32 *v15; // rax

  m_data = vertices->m_data;
  v5 = indices->m_data;
  v6 = 0i64;
  m_quad = vertices->m_data[*indices->m_data].m_quad;
  v8 = indices->m_size - 1;
  if ( indices->m_size - 1 > 0 )
  {
    while ( 1 )
    {
      v9 = *v5++;
      v10 = _mm_sub_ps(m_data[v9].m_quad, m_quad);
      v11 = _mm_sub_ps(m_data[*v5].m_quad, m_quad);
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
char __fastcall `anonymous namespace::areOppositeSegments(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkaiNavMeshSimplificationUtils::Segment *seg1,
        hkaiNavMeshSimplificationUtils::Segment *seg2,
        hkaiNavMesh *navMesh,
        hkResult *resOut)
{
  hkResult *v5; // r14
  hkaiNavMesh *v6; // r15
  __int64 m_size; // rbx
  hkResultEnum v11; // eax
  hkResultEnum v12; // eax
  __int64 i; // r9
  int *v14; // r8
  int *v15; // r8
  __int64 v16; // rax
  hkaiNavMesh::Edge *m_data; // rdx
  hkaiNavMesh::Edge *v18; // r10
  char v19; // bl
  int *pArr; // [rsp+30h] [rbp-20h] BYREF
  int v21; // [rsp+38h] [rbp-18h]
  int v22; // [rsp+3Ch] [rbp-14h]
  int *array; // [rsp+40h] [rbp-10h] BYREF
  int v24; // [rsp+48h] [rbp-8h]
  int v25; // [rsp+4Ch] [rbp-4h]

  v5 = resOut;
  v6 = navMesh;
  resOut->m_enum = HK_SUCCESS;
  if ( __PAIR64__(seg1->m_partitionIdA, seg1->m_partitionIdB) != *(_QWORD *)&seg2->m_partitionIdA )
    return 0;
  m_size = seg1->m_boundary.m_size;
  if ( (_DWORD)m_size != seg2->m_boundary.m_size )
    return 0;
  array = 0i64;
  v24 = 0;
  v25 = 0x80000000;
  pArr = 0i64;
  v21 = 0;
  v22 = 0x80000000;
  if ( (int)m_size <= 0 )
  {
    v11 = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
    v11 = (int)resOut;
  }
  v5->m_enum = v11;
  if ( v11 )
    goto LABEL_25;
  if ( (v22 & 0x3FFFFFFF) >= (int)m_size )
  {
    v12 = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerTempAllocator::s_alloc, &pArr, m_size, 4);
    v12 = (int)resOut;
  }
  v5->m_enum = v12;
  if ( v12 )
    goto LABEL_25;
  for ( i = 0i64; i < m_size; ++v21 )
  {
    v14 = &seg1->m_boundary.m_data[i++];
    array[v24++] = *v14;
    pArr[v21] = v6->m_edges.m_data[seg2->m_boundary.m_data[i - 1]].m_oppositeEdge;
  }
  if ( v24 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(array, 0, v24 - 1, 0);
  if ( v21 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(pArr, 0, v21 - 1, 0);
  navMesh = 0i64;
  if ( m_size > 0 )
  {
    v15 = array;
    while ( 1 )
    {
      v16 = *v15;
      if ( (_DWORD)v16 != *(int *)((char *)v15 + (char *)pArr - (char *)array) )
        break;
      m_data = v6->m_edges.m_data;
      v18 = &m_data[v16];
      if ( v18->m_a != m_data[v18->m_oppositeEdge].m_b || v18->m_b != m_data[m_data[v16].m_oppositeEdge].m_a )
        break;
      navMesh = (hkaiNavMesh *)((char *)navMesh + 1);
      ++v15;
      if ( (__int64)navMesh >= m_size )
        goto LABEL_24;
    }
LABEL_25:
    v19 = 0;
    goto LABEL_26;
  }
LABEL_24:
  v19 = 1;
LABEL_26:
  v21 = 0;
  if ( v22 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, hkaiNavMesh *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      pArr,
      (unsigned int)(4 * v22),
      navMesh);
  pArr = 0i64;
  v22 = 0x80000000;
  v24 = 0;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v25);
  return v19;
}

// File Line: 1017
// RVA: 0xB50BA0
hkSimdFloat32 *__fastcall `anonymous namespace::getSignedSegmentArea(
        hkSimdFloat32 *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkaiNavMeshSimplificationUtils::Segment *seg,
        bool forwards,
        int majorAxis)
{
  int *m_data; // r10
  hkVector4f *v6; // r11
  __m128 v7; // xmm4
  __m128 m_quad; // xmm5
  int m_size; // eax
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

  m_data = seg->m_indices.m_data;
  v6 = vertices->m_data;
  v7 = 0i64;
  m_quad = vertices->m_data[*m_data].m_quad;
  m_size = seg->m_indices.m_size;
  if ( !forwards )
  {
    v18 = m_size - 2;
    v19 = v18;
    if ( v18 < 0 )
      goto LABEL_52;
    v20 = &m_data[v18];
    while ( 1 )
    {
      v21 = _mm_sub_ps(v6[v20[1]].m_quad, m_quad);
      v22 = _mm_sub_ps(v6[*v20].m_quad, m_quad);
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
  v10 = m_size - 1;
  v11 = v10;
  if ( v10 > 0 )
  {
    while ( 1 )
    {
      v12 = *m_data++;
      v13 = _mm_sub_ps(v6[v12].m_quad, m_quad);
      v14 = _mm_sub_ps(v6[*m_data].m_quad, m_quad);
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
__int64 __fastcall `anonymous namespace::computeSignedPartitionArea(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        hkArrayBase<int> *segmentToOppositeMap,
        hkPointerMultiMap<int,int> *parToSegIdxMap,
        int segmentIndex,
        int partition,
        int majorAxis,
        hkSimdFloat32 *areaOut,
        hkResult *resOut)
{
  hkResult *v9; // r12
  int v10; // esi
  unsigned __int64 v11; // rdi
  hkaiNavMeshSimplificationUtils::Segment *v14; // r10
  int *m_data; // rdx
  int v16; // r14d
  int Key; // ebx
  __int64 val_low; // r14
  hkaiNavMeshSimplificationUtils::Segment *v19; // rsi
  int v20; // ecx
  int v21; // r8d
  int v22; // r9d
  int v23; // eax
  int *v24; // rax
  __int64 m_hashMod; // r10
  int v26; // r8d
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v28; // rax
  int v29; // r8d
  int *v30; // r12
  int v31; // r13d
  int v32; // r15d
  int v33; // edi
  __int64 v34; // rbx
  int *v35; // rdx
  __int64 v36; // r14
  hkaiNavMeshSimplificationUtils::Segment *v37; // rsi
  _DWORD *v38; // rcx
  unsigned __int8 v39; // bl
  hkSimdFloat32 *SignedSegmentArea; // rax
  int *v41; // rax
  __int64 v42; // rcx
  int *v43; // rbx
  char *v44; // rdx
  __int64 v45; // rax
  hkSimdFloat32 *v46; // rax
  __int64 v47; // rcx
  int *v48; // rbx
  char *v49; // rdx
  __int64 v50; // rax
  int *array; // [rsp+30h] [rbp-30h] BYREF
  int v53; // [rsp+38h] [rbp-28h]
  int v54; // [rsp+3Ch] [rbp-24h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-20h] BYREF
  hkSimdFloat32 v56; // [rsp+50h] [rbp-10h] BYREF
  int v58; // [rsp+A8h] [rbp+48h]

  v9 = resOut;
  v10 = segmentIndex;
  v11 = partition;
  resOut->m_enum = HK_SUCCESS;
  v14 = &segments->m_data[segmentIndex];
  m_data = v14->m_indices.m_data;
  v58 = *m_data;
  v16 = m_data[v14->m_indices.m_size - 1];
  array = 0i64;
  v53 = 0;
  *areaOut = 0i64;
  LODWORD(resOut) = v16;
  v54 = 0x80000000;
  Key = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                        &parToSegIdxMap->m_map,
                        v11);
  if ( Key <= parToSegIdxMap->m_map.m_hashMod )
  {
    do
    {
      val_low = SLODWORD(parToSegIdxMap->m_map.m_elem[Key].val);
      v19 = &segments->m_data[val_low];
      if ( *v19->m_indices.m_data != v19->m_indices.m_data[v19->m_indices.m_size - 1] )
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
          hkArrayUtil::_reserve((hkResult *)&partition, &hkContainerTempAllocator::s_alloc, &array, v22, 16);
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
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 16);
          v20 = v53;
        }
        v24 = &array[4 * v20];
        v53 = v20 + 1;
        *(_QWORD *)v24 = v19;
        v24[2] = val_low;
      }
      m_hashMod = parToSegIdxMap->m_map.m_hashMod;
      v26 = Key + 1;
      for ( i = Key + 1; i > m_hashMod; i = 0i64 )
LABEL_18:
        v26 = 0;
      v28 = &parToSegIdxMap->m_map.m_elem[i];
      while ( v28->key != -1i64 )
      {
        if ( v28->key == v11 )
        {
          Key = v26;
          goto LABEL_21;
        }
        ++i;
        ++v26;
        ++v28;
        if ( i > m_hashMod )
          goto LABEL_18;
      }
      Key = m_hashMod + 1;
LABEL_21:
      ;
    }
    while ( Key <= (int)m_hashMod );
    v10 = segmentIndex;
    v16 = (int)resOut;
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
      if ( (_DWORD)v36 == v10 || segmentToOppositeMap->m_data[v36] == v10 )
        goto LABEL_32;
      v37 = *(hkaiNavMeshSimplificationUtils::Segment **)v35;
      v38 = *(_DWORD **)(*(_QWORD *)v35 + 32i64);
      if ( *v38 == v29 )
        break;
      if ( v38[v37->m_indices.m_size - 1] == v29 )
      {
        SignedSegmentArea = `anonymous namespace::getSignedSegmentArea(&result, vertices, v37, 0, v31);
        --v32;
        segmentIndex = v36;
        areaOut->m_real = _mm_add_ps(areaOut->m_real, SignedSegmentArea->m_real);
        v41 = v37->m_indices.m_data;
        v10 = v36;
        v29 = *v41;
        v53 = v32;
        if ( v32 == v33 )
          goto LABEL_43;
        v42 = 2i64;
        v43 = &v30[4 * v34];
        v44 = (char *)((char *)&v30[4 * v32] - (char *)v43);
        do
        {
          v45 = *(_QWORD *)((char *)v43 + (_QWORD)v44);
          v43 += 2;
          *((_QWORD *)v43 - 1) = v45;
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
    v46 = `anonymous namespace::getSignedSegmentArea(&v56, vertices, v37, 1, v31);
    --v32;
    segmentIndex = v36;
    areaOut->m_real = _mm_add_ps(areaOut->m_real, v46->m_real);
    v29 = v37->m_indices.m_data[v37->m_indices.m_size - 1];
    v10 = v36;
    v53 = v32;
    if ( v32 == v33 )
      goto LABEL_43;
    v47 = 2i64;
    v48 = &v30[4 * v34];
    v49 = (char *)((char *)&v30[4 * v32] - (char *)v48);
    do
    {
      v50 = *(_QWORD *)((char *)v48 + (_QWORD)v49);
      v48 += 2;
      *((_QWORD *)v48 - 1) = v50;
      --v47;
    }
    while ( v47 );
LABEL_42:
    v32 = v53;
    v30 = array;
LABEL_43:
    --v33;
LABEL_44:
    v16 = (int)resOut;
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
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v30, 16 * v21);
  return v39;
}

// File Line: 1139
// RVA: 0xB51180
__int64 __fastcall `anonymous namespace::computePartialSignedPartitionAreas(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        hkArrayBase<int> *segmentToOppositeMap,
        hkPointerMultiMap<int,int> *parToSegIdxMap,
        int segmentIndex,
        int majorAxisA,
        int majorAxisB,
        hkSimdFloat32 *area1Out,
        hkSimdFloat32 *area2Out,
        hkResult *resOut)
{
  unsigned int v10; // ebx
  hkaiNavMeshSimplificationUtils::Segment *v12; // rdi
  char v15; // cl
  bool v16; // zf
  int partition; // ecx
  char v18; // al

  v10 = 0;
  resOut->m_enum = HK_SUCCESS;
  v12 = &segments->m_data[segmentIndex];
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
            vertices,
            segments,
            segmentToOppositeMap,
            parToSegIdxMap,
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
void __fastcall `anonymous namespace::computeFullSignedPartitionAreas(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        int segmentIndex,
        int majorAxisA,
        int majorAxisB,
        hkSimdFloat32 *area1InOut,
        hkSimdFloat32 *area2InOut)
{
  hkaiNavMeshSimplificationUtils::Segment *v9; // rbx
  __m128 m_real; // xmm1
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h] BYREF

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
    m_real = result.m_real;
    area1InOut->m_real = _mm_add_ps(area1InOut->m_real, result.m_real);
    if ( majorAxisA == majorAxisB )
    {
      area2InOut->m_real = _mm_add_ps(area2InOut->m_real, m_real);
    }
    else if ( majorAxisB != -1 )
    {
      area2InOut->m_real = _mm_add_ps(
                             `anonymous namespace::getSignedSegmentArea(&result, vertices, v9, 0, majorAxisB)->m_real,
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
  return _mm_andnot_ps(
           _mm_cmple_ps(v8, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
             v8)).m128_f32[0]
       * 0.5;
}

// File Line: 1219
// RVA: 0xB51450
float __fastcall `anonymous namespace::getProjectedTriangleArea(
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        int majorAxis)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  int v7; // r9d
  int v8; // r9d
  int v9; // r9d
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
                                   * COERCE_INT(
                                       _mm_shuffle_ps(v11, v11, 0).m128_f32[0]
                                     - _mm_shuffle_ps(v11, v11, 85).m128_f32[0])) >> 1)
       * 0.5;
}

// File Line: 1279
// RVA: 0xB51540
char __fastcall `anonymous namespace::edgesIntersect(
        hkVector2f *s0,
        hkVector2f *e0,
        hkVector2f *s1,
        hkVector2f *e1,
        hkVector2f *out)
{
  float y; // xmm4_4
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

  y = s1->y;
  v6 = e0->x - s0->x;
  v7 = s0->y;
  v8 = e1->y - y;
  v9 = e1->x - s1->x;
  v10 = e0->y - v7;
  v11 = (float)(v6 * v8) - (float)(v9 * v10);
  if ( v11 == 0.0 )
    return 0;
  v13 = v7 - y;
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
_BOOL8 __fastcall `anonymous namespace::_pointsAreDistinct(
        hkVector4f *start,
        hkVector4f *end,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *epsilon)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm1

  v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(start->m_quad, v2->m_quad), 1u), 1u);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(end->m_quad, v1->m_quad), 1u), 1u);
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(start->m_quad, v1->m_quad), 1u), 1u);
  v8 = _mm_shuffle_ps(v7, v5, 238);
  v9 = _mm_shuffle_ps(v7, v5, 68);
  v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(end->m_quad, v2->m_quad), 1u), 1u);
  v11 = _mm_shuffle_ps(v6, v10, 68);
  return _mm_movemask_ps(
           _mm_cmplt_ps(
             epsilon->m_quad,
             _mm_max_ps(
               _mm_max_ps(_mm_shuffle_ps(v9, v11, 136), _mm_shuffle_ps(v9, v11, 221)),
               _mm_shuffle_ps(v8, _mm_shuffle_ps(v6, v10, 238), 136)))) == 15;
}

// File Line: 1470
// RVA: 0xB5A1A0
_BOOL8 __fastcall A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::processLeaf(
        PartitionIntersectionQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkaiNavMeshSimplificationUtils::Segment *v4; // rbx
  int m_wallClimbingPartition; // eax
  hkRotationf *m_proj; // r14
  int v7; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *m_vertices; // r12
  __int64 m_endIndex; // rbp
  __int64 m_startIndex; // rdi
  __m128 v11; // xmm5
  __int64 v12; // r11
  __int64 v13; // r15
  int *m_data; // r10
  __int64 v15; // rdx
  __int64 v16; // rax
  __m128 m_quad; // xmm3
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
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm0
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
  bool v105; // al
  hkVector4f epsilon; // [rsp+30h] [rbp-F8h] BYREF
  hkVector4f v2; // [rsp+40h] [rbp-E8h] BYREF
  hkVector4f v1; // [rsp+50h] [rbp-D8h] BYREF

  v4 = &this->m_segments->m_data[leafKey];
  m_wallClimbingPartition = this->m_wallClimbingPartition;
  if ( m_wallClimbingPartition < -1
    || v4->m_partitionIdA == m_wallClimbingPartition
    || v4->m_partitionIdB == m_wallClimbingPartition )
  {
    m_proj = this->m_proj;
    v7 = v4->m_indices.m_size - 1;
    if ( this->m_useIndices )
    {
      m_vertices = this->m_vertices;
      m_endIndex = this->m_endIndex;
      m_startIndex = this->m_startIndex;
      v11 = (__m128)_xmm;
      v12 = 0i64;
      v13 = v7;
      if ( v7 > 0 )
      {
        m_data = v4->m_indices.m_data;
        do
        {
          v15 = *m_data;
          if ( (_DWORD)m_startIndex != (_DWORD)v15 )
          {
            v16 = m_data[1];
            if ( (_DWORD)m_startIndex != (_DWORD)v16
              && (_DWORD)m_endIndex != (_DWORD)v15
              && (_DWORD)m_endIndex != (_DWORD)v16 )
            {
              m_quad = m_proj->m_col1.m_quad;
              v18 = m_proj->m_col2.m_quad;
              v19 = m_vertices->m_data[m_startIndex].m_quad;
              v20 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), m_proj->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v18));
              v21 = m_vertices->m_data[m_endIndex].m_quad;
              v22 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), m_proj->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v18));
              v23 = m_vertices->m_data[v15].m_quad;
              v24 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), m_proj->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v18));
              v25 = m_vertices->m_data[v16].m_quad;
              v26 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), m_proj->m_col0.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v18));
              if ( (_mm_movemask_ps(
                      _mm_or_ps(
                        _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v20, v22), v11), _mm_min_ps(v24, v26)),
                        _mm_cmplt_ps(_mm_max_ps(v24, v26), _mm_sub_ps(_mm_min_ps(v20, v22), v11)))) & 3) == 0 )
              {
                v27 = _mm_sub_ps(v26, v24);
                v28 = _mm_sub_ps(v22, v20);
                v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 225), v28);
                if ( (float)(_mm_shuffle_ps(v29, v29, 0).m128_f32[0] - _mm_shuffle_ps(v29, v29, 85).m128_f32[0]) != 0.0 )
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
                  v48 = _mm_cmple_ps(v41, *(__m128 *)&::epsilon);
                  v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v47), v46);
                  v50 = _mm_sub_ps(_mm_mul_ps(v40, v35), _mm_mul_ps(v36, v32));
                  v51 = _mm_cmplt_ps(v50, v41);
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
                  v53 = _mm_cmplt_ps(v52, query.m_quad);
                  v54 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v53, query.m_quad), _mm_and_ps(v53, v52)));
                  v55 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v32, v49), v54), _mm_mul_ps(v35, v49));
                  v56 = _mm_cmplt_ps(v55, query.m_quad);
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
                  if ( (float)((float)(_mm_shuffle_ps(v58, v58, 85).m128_f32[0] + _mm_shuffle_ps(v58, v58, 0).m128_f32[0])
                             + _mm_shuffle_ps(v58, v58, 170).m128_f32[0]) < 0.0000010000001 )
                    goto LABEL_27;
                  v11 = (__m128)_xmm;
                }
              }
            }
          }
          ++v12;
          ++m_data;
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
          v1.m_quad = v65;
          v67 = v63[v66].m_quad;
          v2.m_quad = v67;
          if ( `anonymous namespace::_pointsAreDistinct(&this->m_start, &this->m_end, &v1, &v2, &epsilon) )
          {
            v68 = m_proj->m_col1.m_quad;
            v69 = m_proj->m_col2.m_quad;
            v70 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(this->m_start.m_quad, this->m_start.m_quad, 0), m_proj->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(this->m_start.m_quad, this->m_start.m_quad, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(this->m_start.m_quad, this->m_start.m_quad, 170), v69));
            v71 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(this->m_end.m_quad, this->m_end.m_quad, 0), m_proj->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(this->m_end.m_quad, this->m_end.m_quad, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(this->m_end.m_quad, this->m_end.m_quad, 170), v69));
            v72 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), m_proj->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), v69));
            v73 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), m_proj->m_col0.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), v68)),
                    _mm_mul_ps(_mm_shuffle_ps(v67, v67, 170), v69));
            if ( (_mm_movemask_ps(
                    _mm_or_ps(
                      _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v70, v71), v59), _mm_min_ps(v72, v73)),
                      _mm_cmplt_ps(_mm_max_ps(v72, v73), _mm_sub_ps(_mm_min_ps(v70, v71), v59)))) & 3) == 0 )
            {
              v74 = _mm_sub_ps(v73, v72);
              v75 = _mm_sub_ps(v71, v70);
              v76 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 225), v75);
              if ( (float)(_mm_shuffle_ps(v76, v76, 0).m128_f32[0] - _mm_shuffle_ps(v76, v76, 85).m128_f32[0]) != 0.0 )
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
                v96 = _mm_cmple_ps(v88, *(__m128 *)&::epsilon);
                v97 = _mm_cmplt_ps(v95, v88);
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
                v99 = _mm_cmplt_ps(v98, query.m_quad);
                v100 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v99, query.m_quad), _mm_and_ps(v98, v99)));
                v101 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v94, v79), v100), _mm_mul_ps(v94, v82));
                v102 = _mm_cmplt_ps(v101, query.m_quad);
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
                if ( (float)((float)(_mm_shuffle_ps(v104, v104, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v104, v104, 0).m128_f32[0])
                           + _mm_shuffle_ps(v104, v104, 170).m128_f32[0]) < 0.0000010000001 )
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
  this->m_intersects = v105;
  return !v105;
} }
  }
  v105 = 0;
LABEL_26:
  this->m_intersects = v105;
  return !v105;
}

// File Line: 1497
// RVA: 0xB51720
char __fastcall `anonymous namespace::doesLineSegmentIntersectPartition(
        int startIndex,
        int endIndex,
        __m128 *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments)
{
  __int64 v4; // rbx
  __m128 v6; // xmm2
  hkVector4f *v7; // r9
  __int64 v8; // rdi
  int v9; // eax
  __m128 v10; // xmm0
  hkcdDynamicAabbTree *v11; // r12
  __m128 v12; // xmm5
  hkaiNavMeshSimplificationUtils::Segment *m_data; // rcx
  __int64 v14; // rsi
  int *v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rax
  __m128 m_quad; // xmm1
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
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  __m128 v56; // xmm10
  __m128 v57; // xmm0
  __m128 v58; // xmm15
  __m128 v59; // xmm15
  hkVector4f v61; // xmm0
  __m128 v62; // xmm1
  hkVector4f v63; // xmm1
  int v64; // eax
  int v65; // eax
  __m128 v66; // xmm6
  hkaiNavMeshSimplificationUtils::Segment *v67; // rcx
  __int64 v68; // rsi
  __int64 v69; // r14
  __int64 v70; // r10
  __int64 v71; // rax
  int *v72; // rdx
  __int64 v73; // r8
  __int64 v74; // rax
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm4
  __m128 v78; // xmm13
  __m128 v79; // xmm1
  __m128 v80; // xmm12
  __m128 v81; // xmm1
  __m128 v82; // xmm14
  __m128 v83; // xmm1
  __m128 v84; // xmm11
  __m128 v85; // xmm11
  __m128 v86; // xmm12
  __m128 v87; // xmm1
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm10
  __m128 v91; // xmm1
  __m128 v92; // xmm2
  __m128 v93; // xmm9
  __m128 v94; // xmm8
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm1
  __m128 v98; // xmm6
  __m128 v99; // xmm4
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm1
  __m128 v103; // xmm5
  __m128 v104; // xmm1
  __m128 v105; // xmm0
  __m128 v106; // xmm2
  __m128 v107; // xmm7
  __m128 v108; // xmm6
  __m128 v109; // xmm1
  __m128 v110; // xmm3
  __m128 v111; // xmm0
  __m128 v112; // xmm3
  __m128 v113; // xmm2
  __m128 v114; // xmm0
  __m128 v115; // xmm15
  __m128 v116; // xmm15
  __int64 v117; // r8
  __int64 v118; // r13
  int *v119; // r8
  __int64 v120; // r9
  int v121; // ecx
  __m128 v122; // xmm3
  __m128 v123; // xmm1
  __m128 v124; // xmm4
  __m128 v125; // xmm13
  __m128 v126; // xmm1
  __m128 v127; // xmm12
  __m128 v128; // xmm1
  __m128 v129; // xmm14
  __m128 v130; // xmm1
  __m128 v131; // xmm11
  __m128 v132; // xmm11
  __m128 v133; // xmm12
  __m128 v134; // xmm1
  __m128 v135; // xmm1
  __m128 v136; // xmm2
  __m128 v137; // xmm10
  __m128 v138; // xmm1
  __m128 v139; // xmm2
  __m128 v140; // xmm9
  __m128 v141; // xmm8
  __m128 v142; // xmm1
  __m128 v143; // xmm5
  __m128 v144; // xmm1
  __m128 v145; // xmm6
  __m128 v146; // xmm4
  __m128 v147; // xmm1
  __m128 v148; // xmm2
  __m128 v149; // xmm1
  __m128 v150; // xmm3
  __m128 v151; // xmm1
  __m128 v152; // xmm7
  __m128 v153; // xmm6
  __m128 v154; // xmm1
  __m128 v155; // xmm0
  __m128 v156; // xmm2
  __m128 v157; // xmm0
  __m128 v158; // xmm3
  __m128 v159; // xmm1
  __m128 v160; // xmm0
  __m128 v161; // xmm15
  __m128 v162; // xmm15
  __int64 v163; // [rsp+20h] [rbp-A8h]
  hkAabb aabb; // [rsp+30h] [rbp-98h] BYREF
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+50h] [rbp-78h] BYREF
  hkcdDynamicAabbTree *v166; // [rsp+58h] [rbp-70h]
  __m128 *v167; // [rsp+60h] [rbp-68h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v168; // [rsp+68h] [rbp-60h]
  int v169; // [rsp+70h] [rbp-58h]
  __int64 v170; // [rsp+78h] [rbp-50h]
  hkAabb v171; // [rsp+88h] [rbp-40h] BYREF
  hkcdAabbTreeQueries::AabbCollector v172; // [rsp+A8h] [rbp-20h] BYREF
  hkcdDynamicAabbTree *v173; // [rsp+B0h] [rbp-18h]
  _QWORD *v174; // [rsp+B8h] [rbp-10h]
  _QWORD *v175; // [rsp+C0h] [rbp-8h]
  int v176; // [rsp+C8h] [rbp+0h]
  __m128 *v177; // [rsp+D0h] [rbp+8h]
  char v178; // [rsp+D8h] [rbp+10h]
  int v179; // [rsp+DCh] [rbp+14h]
  int v180; // [rsp+E0h] [rbp+18h]
  int v181; // [rsp+108h] [rbp+40h]
  char v182; // [rsp+10Ch] [rbp+44h]
  _QWORD *v183; // [rsp+208h] [rbp+140h]
  _QWORD *v184; // [rsp+210h] [rbp+148h]
  hkcdDynamicAabbTree *v185; // [rsp+218h] [rbp+150h]
  int vars0; // [rsp+220h] [rbp+158h]
  void *retaddr; // [rsp+228h] [rbp+160h]
  int v188; // [rsp+230h] [rbp+168h]
  __int64 v189; // [rsp+238h] [rbp+170h]

  v4 = startIndex;
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         0);
  v7 = (hkVector4f *)vertices->m128_u64[0];
  v8 = endIndex;
  if ( (_DWORD)retaddr == v188 )
  {
    v9 = (_DWORD)retaddr - 3;
    aabb.m_min.m_quad = _mm_min_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    v10 = _mm_max_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v6);
    aabb.m_max.m_quad = _mm_add_ps(v10, v6);
    if ( (int)retaddr < 3 )
      v9 = (int)retaddr;
    v11 = v185;
    v12 = (__m128)_xmm;
    v168 = segments;
    v167 = vertices;
    aabb.m_max.m_quad.m128_i32[v9] = 2139095022;
    aabb.m_min.m_quad.m128_i32[v9] = -8388626;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
    v166 = v11;
    v169 = (int)retaddr;
    v170 = v189;
    m_data = segments->m_data;
    v14 = 0i64;
    if ( m_data[vars0].m_indices.m_size - 1 > 0 )
    {
      v15 = m_data[vars0].m_indices.m_data;
      do
      {
        v16 = *v15;
        if ( (_DWORD)v4 != (_DWORD)v16 )
        {
          v17 = v15[1];
          if ( (_DWORD)v4 != (_DWORD)v17 && (_DWORD)v8 != (_DWORD)v16 && (_DWORD)v8 != (_DWORD)v17 )
          {
            m_quad = v7[v4].m_quad;
            v19 = *(__m128 *)(v189 + 16);
            v20 = *(__m128 *)(v189 + 32);
            v21 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v20));
            v22 = v7[v8].m_quad;
            v23 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v20));
            v24 = v7[v16].m_quad;
            v25 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20));
            v26 = v7[v17].m_quad;
            v27 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v19)),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v20));
            if ( (_mm_movemask_ps(
                    _mm_or_ps(
                      _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v21, v23), v12), _mm_min_ps(v25, v27)),
                      _mm_cmplt_ps(_mm_max_ps(v25, v27), _mm_sub_ps(_mm_min_ps(v21, v23), v12)))) & 3) == 0 )
            {
              v28 = _mm_sub_ps(v27, v25);
              v29 = _mm_sub_ps(v23, v21);
              v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 225), v29);
              if ( (float)(_mm_shuffle_ps(v30, v30, 0).m128_f32[0] - _mm_shuffle_ps(v30, v30, 85).m128_f32[0]) != 0.0 )
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
                v49 = _mm_cmple_ps(v42, *(__m128 *)&epsilon);
                v50 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v48), v47);
                v51 = _mm_sub_ps(_mm_mul_ps(v41, v35), _mm_mul_ps(v37, v33));
                v52 = _mm_cmplt_ps(v51, v42);
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
                v54 = _mm_cmplt_ps(v53, query.m_quad);
                v55 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v54, query.m_quad), _mm_and_ps(v54, v53)));
                v56 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v33, v50), v55), _mm_mul_ps(v35, v50));
                v57 = _mm_cmplt_ps(v56, query.m_quad);
                v58 = _mm_sub_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v57, query.m_quad), _mm_and_ps(v57, v56))),
                            v29),
                          v21),
                        _mm_add_ps(_mm_mul_ps(v28, v55), v25));
                v59 = _mm_mul_ps(v58, v58);
                if ( (float)((float)(_mm_shuffle_ps(v59, v59, 85).m128_f32[0] + _mm_shuffle_ps(v59, v59, 0).m128_f32[0])
                           + _mm_shuffle_ps(v59, v59, 170).m128_f32[0]) < 0.0000010000001 )
                  return 1;
                v12 = (__m128)_xmm;
              }
            }
          }
        }
        ++v14;
        ++v15;
      }
      while ( v14 < m_data[vars0].m_indices.m_size - 1 );
    }
    aabb.m_max.m_quad.m128_i8[8] = 1;
    aabb.m_max.m_quad.m128_i32[3] = v4;
    LODWORD(collector.vfptr) = v8;
    BYTE4(v170) = 0;
    LODWORD(v170) = -2;
    hkcdDynamicAabbTree::queryAabb(v11, &aabb, &collector);
    if ( BYTE4(v170) )
      return 1;
  }
  else
  {
    aabb.m_min.m_quad = _mm_min_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    v61.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v6);
    v62 = _mm_max_ps(v7[startIndex].m_quad, v7[endIndex].m_quad);
    aabb.m_min = (hkVector4f)v61.m_quad;
    v63.m_quad = _mm_add_ps(v62, v6);
    aabb.m_max = (hkVector4f)v63.m_quad;
    if ( v188 != -1 )
    {
      v171.m_min = (hkVector4f)v61.m_quad;
      v171.m_max = (hkVector4f)v63.m_quad;
      v64 = v188 - 3;
      if ( v188 < 3 )
        v64 = v188;
      v171.m_max.m_quad.m128_i32[v64] = 2139095022;
      v171.m_min.m_quad.m128_i32[v64] = -8388626;
    }
    v65 = (_DWORD)retaddr - 3;
    if ( (int)retaddr < 3 )
      v65 = (int)retaddr;
    v66 = (__m128)_xmm;
    aabb.m_max.m_quad.m128_i32[v65] = 2139095022;
    aabb.m_min.m_quad.m128_i32[v65] = -8388626;
    v169 = (int)retaddr;
    v67 = segments->m_data;
    v168 = segments;
    collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
    v167 = vertices;
    v166 = v185;
    v170 = v189;
    v68 = 0i64;
    v69 = 6i64 * vars0;
    v70 = 0i64;
    LODWORD(retaddr) = v67[vars0].m_partitionIdA;
    LODWORD(v71) = v67[vars0].m_indices.m_size - 1;
    v163 = (int)v71;
    if ( (int)v71 > 0 )
    {
      v72 = v67[vars0].m_indices.m_data;
      v71 = (int)v71;
      do
      {
        v73 = *v72;
        if ( (_DWORD)v4 != (_DWORD)v73 )
        {
          v74 = v72[1];
          if ( (_DWORD)v4 != (_DWORD)v74 && (_DWORD)v8 != (_DWORD)v73 && (_DWORD)v8 != (_DWORD)v74 )
          {
            v75 = v7[v4].m_quad;
            v76 = *(__m128 *)(v189 + 16);
            v77 = *(__m128 *)(v189 + 32);
            v78 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v75, v75, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v75, v75, 85), v76)),
                    _mm_mul_ps(_mm_shuffle_ps(v75, v75, 170), v77));
            v79 = v7[v8].m_quad;
            v80 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v79, v79, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v79, v79, 85), v76)),
                    _mm_mul_ps(_mm_shuffle_ps(v79, v79, 170), v77));
            v81 = v7[v73].m_quad;
            v82 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v81, v81, 85), v76)),
                    _mm_mul_ps(_mm_shuffle_ps(v81, v81, 170), v77));
            v83 = v7[v74].m_quad;
            v84 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v83, v83, 0), *(__m128 *)v189),
                      _mm_mul_ps(_mm_shuffle_ps(v83, v83, 85), v76)),
                    _mm_mul_ps(_mm_shuffle_ps(v83, v83, 170), v77));
            if ( (_mm_movemask_ps(
                    _mm_or_ps(
                      _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v78, v80), v66), _mm_min_ps(v82, v84)),
                      _mm_cmplt_ps(_mm_max_ps(v82, v84), _mm_sub_ps(_mm_min_ps(v78, v80), v66)))) & 3) == 0 )
            {
              v85 = _mm_sub_ps(v84, v82);
              v86 = _mm_sub_ps(v80, v78);
              v87 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 225), v86);
              if ( (float)(_mm_shuffle_ps(v87, v87, 0).m128_f32[0] - _mm_shuffle_ps(v87, v87, 85).m128_f32[0]) != 0.0 )
              {
                v88 = _mm_mul_ps(v85, v86);
                v89 = _mm_sub_ps(v82, v78);
                v90 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                        _mm_shuffle_ps(v88, v88, 170));
                v91 = _mm_mul_ps(v89, v86);
                v92 = _mm_mul_ps(v89, v85);
                v93 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                        _mm_shuffle_ps(v91, v91, 170));
                v94 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                        _mm_shuffle_ps(v92, v92, 170));
                v95 = _mm_mul_ps(v86, v86);
                v96 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                        _mm_shuffle_ps(v95, v95, 170));
                v97 = _mm_mul_ps(v85, v85);
                v98 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170));
                v99 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v98, v96), _mm_mul_ps(v90, v90)), *(__m128 *)&epsilon);
                v100 = _mm_rcp_ps(v99);
                v101 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v100, v99)), v100);
                v102 = _mm_rcp_ps(v98);
                v103 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v102, v98)), v102);
                v104 = _mm_rcp_ps(v96);
                v105 = _mm_mul_ps(v104, v96);
                v106 = _mm_cmple_ps(v99, *(__m128 *)&epsilon);
                v107 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v105), v104);
                v108 = _mm_sub_ps(_mm_mul_ps(v98, v93), _mm_mul_ps(v94, v90));
                v109 = _mm_cmplt_ps(v108, v99);
                v110 = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_or_ps(
                             _mm_andnot_ps(
                               v106,
                               _mm_mul_ps(
                                 _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v109, v99), _mm_and_ps(v109, v108))),
                                 v101)),
                             _mm_and_ps(v106, query.m_quad)),
                           _mm_mul_ps(v103, v90)),
                         _mm_mul_ps(v94, v103));
                v111 = _mm_cmplt_ps(v110, query.m_quad);
                v112 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v111, v110), _mm_andnot_ps(v111, query.m_quad)));
                v113 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v107, v90), v112), _mm_mul_ps(v93, v107));
                v114 = _mm_cmplt_ps(v113, query.m_quad);
                v115 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_and_ps(v114, v113), _mm_andnot_ps(v114, query.m_quad))),
                             v86),
                           v78),
                         _mm_add_ps(_mm_mul_ps(v112, v85), v82));
                v116 = _mm_mul_ps(v115, v115);
                if ( (float)((float)(_mm_shuffle_ps(v116, v116, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v116, v116, 0).m128_f32[0])
                           + _mm_shuffle_ps(v116, v116, 170).m128_f32[0]) < 0.0000010000001 )
                  return 1;
                v66 = (__m128)_xmm;
              }
            }
          }
          v71 = v163;
        }
        ++v70;
        ++v72;
      }
      while ( v70 < v71 );
    }
    LODWORD(v170) = (_DWORD)retaddr;
    aabb.m_max.m_quad.m128_i8[8] = 1;
    aabb.m_max.m_quad.m128_i32[3] = v4;
    LODWORD(collector.vfptr) = v8;
    BYTE4(v170) = 0;
    hkcdDynamicAabbTree::queryAabb(v185, &aabb, &collector);
    if ( BYTE4(v170) )
      return 1;
    if ( v188 != -1 )
    {
      v176 = v188;
      v174 = v183;
      v177 = vertices;
      v172.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
      v173 = v185;
      v117 = *v184;
      v175 = v184;
      LODWORD(retaddr) = *(_DWORD *)(v117 + 8 * v69 + 8);
      v118 = *(_DWORD *)(v117 + 8 * v69 + 40) - 1;
      if ( *(_DWORD *)(v117 + 8 * v69 + 40) - 1 > 0 )
      {
        v119 = *(int **)(v117 + 8 * v69 + 32);
        do
        {
          v120 = *v119;
          if ( (_DWORD)v4 != (_DWORD)v120 )
          {
            v121 = v119[1];
            if ( (_DWORD)v4 != v121 && (_DWORD)v8 != (_DWORD)v120 && (_DWORD)v8 != v121 )
            {
              v122 = vertices[1];
              v123 = *(__m128 *)(*v183 + 16 * v4);
              v124 = vertices[2];
              v125 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v123, v123, 85), v122),
                         _mm_mul_ps(_mm_shuffle_ps(v123, v123, 0), *vertices)),
                       _mm_mul_ps(_mm_shuffle_ps(v123, v123, 170), v124));
              v126 = *(__m128 *)(*v183 + 16 * v8);
              v127 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v126, v126, 0), *vertices),
                         _mm_mul_ps(_mm_shuffle_ps(v126, v126, 85), v122)),
                       _mm_mul_ps(_mm_shuffle_ps(v126, v126, 170), v124));
              v128 = *(__m128 *)(*v183 + 16 * v120);
              v129 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v128, v128, 0), *vertices),
                         _mm_mul_ps(_mm_shuffle_ps(v128, v128, 85), v122)),
                       _mm_mul_ps(_mm_shuffle_ps(v128, v128, 170), v124));
              v130 = *(__m128 *)(*v183 + 16i64 * v119[1]);
              v131 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v130, v130, 0), *vertices),
                         _mm_mul_ps(_mm_shuffle_ps(v130, v130, 85), v122)),
                       _mm_mul_ps(_mm_shuffle_ps(v130, v130, 170), v124));
              if ( (_mm_movemask_ps(
                      _mm_or_ps(
                        _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v125, v127), v66), _mm_min_ps(v129, v131)),
                        _mm_cmplt_ps(_mm_max_ps(v129, v131), _mm_sub_ps(_mm_min_ps(v125, v127), v66)))) & 3) == 0 )
              {
                v132 = _mm_sub_ps(v131, v129);
                v133 = _mm_sub_ps(v127, v125);
                v134 = _mm_mul_ps(_mm_shuffle_ps(v132, v132, 225), v133);
                if ( (float)(_mm_shuffle_ps(v134, v134, 0).m128_f32[0] - _mm_shuffle_ps(v134, v134, 85).m128_f32[0]) != 0.0 )
                {
                  v135 = _mm_mul_ps(v132, v133);
                  v136 = _mm_sub_ps(v129, v125);
                  v137 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
                           _mm_shuffle_ps(v135, v135, 170));
                  v138 = _mm_mul_ps(v136, v133);
                  v139 = _mm_mul_ps(v136, v132);
                  v140 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                           _mm_shuffle_ps(v138, v138, 170));
                  v141 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
                           _mm_shuffle_ps(v139, v139, 170));
                  v142 = _mm_mul_ps(v133, v133);
                  v143 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                           _mm_shuffle_ps(v142, v142, 170));
                  v144 = _mm_mul_ps(v132, v132);
                  v145 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v144, v144, 85), _mm_shuffle_ps(v144, v144, 0)),
                           _mm_shuffle_ps(v144, v144, 170));
                  v146 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v145, v143), _mm_mul_ps(v137, v137)), *(__m128 *)&epsilon);
                  v147 = _mm_rcp_ps(v146);
                  v148 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v147, v146)), v147);
                  v149 = _mm_rcp_ps(v145);
                  v150 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v149, v145)), v149);
                  v151 = _mm_rcp_ps(v143);
                  v152 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v151, v143)), v151);
                  v153 = _mm_sub_ps(_mm_mul_ps(v145, v140), _mm_mul_ps(v141, v137));
                  v154 = _mm_cmple_ps(v146, *(__m128 *)&epsilon);
                  v155 = _mm_cmplt_ps(v153, v146);
                  v156 = _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v154,
                                 _mm_mul_ps(
                                   _mm_max_ps(
                                     aabbOut.m_quad,
                                     _mm_or_ps(_mm_and_ps(v153, v155), _mm_andnot_ps(v155, v146))),
                                   v148)),
                               _mm_and_ps(v154, query.m_quad)),
                             _mm_mul_ps(v150, v137)),
                           _mm_mul_ps(v150, v141));
                  v157 = _mm_cmplt_ps(v156, query.m_quad);
                  v158 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v156, v157), _mm_andnot_ps(v157, query.m_quad)));
                  v159 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v152, v137), v158), _mm_mul_ps(v152, v140));
                  v160 = _mm_cmplt_ps(v159, query.m_quad);
                  v161 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_max_ps(
                                 (__m128)0i64,
                                 _mm_or_ps(_mm_and_ps(v159, v160), _mm_andnot_ps(v160, query.m_quad))),
                               v133),
                             v125),
                           _mm_add_ps(_mm_mul_ps(v158, v132), v129));
                  v162 = _mm_mul_ps(v161, v161);
                  if ( (float)((float)(_mm_shuffle_ps(v162, v162, 85).m128_f32[0]
                                     + _mm_shuffle_ps(v162, v162, 0).m128_f32[0])
                             + _mm_shuffle_ps(v162, v162, 170).m128_f32[0]) < 0.0000010000001 )
                    return 1;
                }
              }
            }
          }
          v66 = (__m128)_xmm;
          ++v68;
          ++v119;
        }
        while ( v68 < v118 );
      }
      v181 = (int)retaddr;
      v178 = 1;
      v179 = v4;
      v180 = v8;
      v182 = 0;
      hkcdDynamicAabbTree::queryAabb(v185, &v171, &v172);
      if ( v182 )
        return 1;
    }
  }
  return 0;
}

// File Line: 1557
// RVA: 0xB524F0
char __fastcall `anonymous namespace::doesLineSegmentIntersectPartition(
        hkVector4f *start,
        hkVector4f *end,
        __m128 *vertices,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments)
{
  int v4; // edi
  __m128 m_quad; // xmm8
  __m128 v8; // xmm2
  __m128 v9; // xmm15
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  int v12; // eax
  __m128 v13; // xmm9
  __int64 v14; // rbx
  __int64 v15; // r13
  hkVector4f *v16; // r12
  int *m_data; // rdi
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
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm0
  __m128 v57; // xmm3
  __m128 v58; // xmm3
  int v60; // eax
  int v61; // eax
  hkaiNavMeshSimplificationUtils::Segment *v62; // rdx
  __m128 v63; // xmm9
  __int64 v64; // rbx
  __int64 v65; // r13
  __int64 v66; // r15
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
  __m128 v102; // xmm1
  __m128 v103; // xmm3
  __m128 v104; // xmm0
  __m128 v105; // xmm2
  __m128 v106; // xmm10
  __m128 v107; // xmm0
  __m128 v108; // xmm3
  __m128 v109; // xmm3
  hkcdDynamicAabbTree *v110; // r15
  __int64 v111; // rdi
  __int64 v112; // rax
  int *v113; // rdi
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
  __m128 v156; // xmm1
  hkVector4f epsilon; // [rsp+30h] [rbp-98h] BYREF
  _BYTE v2[64]; // [rsp+40h] [rbp-88h] BYREF
  hkcdDynamicAabbTree *v159; // [rsp+80h] [rbp-48h]
  __m128 *v160; // [rsp+88h] [rbp-40h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v161; // [rsp+90h] [rbp-38h]
  int v162; // [rsp+98h] [rbp-30h]
  __int64 v163; // [rsp+A0h] [rbp-28h]
  char v164; // [rsp+A8h] [rbp-20h]
  __m128 v165; // [rsp+B8h] [rbp-10h]
  __m128 v166; // [rsp+C8h] [rbp+0h]
  int v167; // [rsp+D8h] [rbp+10h]
  char v168; // [rsp+DCh] [rbp+14h]
  hkAabb v169; // [rsp+E8h] [rbp+20h] BYREF
  hkAabb v170; // [rsp+108h] [rbp+40h] BYREF
  hkcdAabbTreeQueries::AabbCollector v171; // [rsp+128h] [rbp+60h] BYREF
  hkcdDynamicAabbTree *v172; // [rsp+130h] [rbp+68h]
  _QWORD *v173; // [rsp+138h] [rbp+70h]
  _QWORD *v174; // [rsp+140h] [rbp+78h]
  int v175; // [rsp+148h] [rbp+80h]
  __m128 *v176; // [rsp+150h] [rbp+88h]
  char v177; // [rsp+158h] [rbp+90h]
  __m128 v178; // [rsp+168h] [rbp+A0h]
  __m128 v179; // [rsp+178h] [rbp+B0h]
  int v180; // [rsp+188h] [rbp+C0h]
  char v181; // [rsp+18Ch] [rbp+C4h]
  _QWORD *v182; // [rsp+288h] [rbp+1C0h]
  _QWORD *v183; // [rsp+290h] [rbp+1C8h]
  hkcdDynamicAabbTree *v184; // [rsp+298h] [rbp+1D0h]
  int vars0; // [rsp+2A0h] [rbp+1D8h]
  void *retaddr; // [rsp+2A8h] [rbp+1E0h]
  int v187; // [rsp+2B0h] [rbp+1E8h]
  int v188; // [rsp+2B0h] [rbp+1E8h]
  __int64 v189; // [rsp+2B8h] [rbp+1F0h]

  v4 = v187;
  m_quad = end->m_quad;
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
         0);
  v9 = start->m_quad;
  v10.m_quad = _mm_sub_ps(_mm_min_ps(start->m_quad, end->m_quad), v8);
  v11.m_quad = _mm_add_ps(_mm_max_ps(start->m_quad, end->m_quad), v8);
  if ( (_DWORD)retaddr == v187 )
  {
    *(hkVector4f *)v2 = (hkVector4f)end->m_quad;
    *(hkVector4f *)&v2[32] = (hkVector4f)v11.m_quad;
    *(hkVector4f *)&v2[16] = (hkVector4f)v10.m_quad;
    v12 = (_DWORD)retaddr - 3;
    if ( (int)retaddr < 3 )
      v12 = (int)retaddr;
    v13 = (__m128)_xmm;
    *(_DWORD *)&v2[4 * v12 + 32] = 2139095022;
    *(_DWORD *)&v2[4 * v12 + 16] = -8388626;
    epsilon.m_quad = (__m128)_xmm;
    *(_QWORD *)&v2[56] = &A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
    v160 = vertices;
    v159 = v184;
    v161 = segments;
    v162 = (int)retaddr;
    v163 = v189;
    v14 = 0i64;
    v15 = segments->m_data[vars0].m_indices.m_size - 1;
    if ( segments->m_data[vars0].m_indices.m_size - 1 > 0 )
    {
      v16 = (hkVector4f *)vertices->m128_u64[0];
      m_data = segments->m_data[vars0].m_indices.m_data;
      do
      {
        v18 = v16[*m_data].m_quad;
        v19 = m_data[1];
        *(__m128 *)&v2[40] = v18;
        v20 = v16[v19].m_quad;
        *(__m128 *)&v2[8] = v20;
        if ( `anonymous namespace::_pointsAreDistinct(
               start,
               end,
               (hkVector4f *)&v2[40],
               (hkVector4f *)&v2[8],
               &epsilon) )
        {
          v21 = *(__m128 *)(v189 + 16);
          v22 = *(__m128 *)(v189 + 32);
          v23 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v22));
          v24 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v22));
          v25 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v22));
          v26 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v21)),
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v22));
          if ( (_mm_movemask_ps(
                  _mm_or_ps(
                    _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v23, v24), v13), _mm_min_ps(v25, v26)),
                    _mm_cmplt_ps(_mm_max_ps(v25, v26), _mm_sub_ps(_mm_min_ps(v23, v24), v13)))) & 3) == 0 )
          {
            v27 = _mm_sub_ps(v26, v25);
            v28 = _mm_sub_ps(v24, v23);
            *(_OWORD *)&v2[24] = 0i64;
            v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 225), v28);
            if ( (float)(_mm_shuffle_ps(v29, v29, 0).m128_f32[0] - _mm_shuffle_ps(v29, v29, 85).m128_f32[0]) != 0.0 )
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
              v48 = _mm_cmple_ps(v41, *(__m128 *)&::epsilon);
              v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v47), v46);
              v50 = _mm_sub_ps(_mm_mul_ps(v40, v35), _mm_mul_ps(v36, v32));
              v51 = _mm_cmplt_ps(v50, v41);
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
              v53 = _mm_cmplt_ps(v52, query.m_quad);
              v54 = _mm_max_ps(*(__m128 *)&v2[24], _mm_or_ps(_mm_andnot_ps(v53, query.m_quad), _mm_and_ps(v53, v52)));
              v55 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v32, v49), v54), _mm_mul_ps(v35, v49));
              v56 = _mm_cmplt_ps(v55, query.m_quad);
              v57 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_max_ps(
                            *(__m128 *)&v2[24],
                            _mm_or_ps(_mm_andnot_ps(v56, query.m_quad), _mm_and_ps(v56, v55))),
                          v28),
                        v23),
                      _mm_add_ps(_mm_mul_ps(v54, v27), v25));
              v58 = _mm_mul_ps(v57, v57);
              if ( (float)((float)(_mm_shuffle_ps(v58, v58, 85).m128_f32[0] + _mm_shuffle_ps(v58, v58, 0).m128_f32[0])
                         + _mm_shuffle_ps(v58, v58, 170).m128_f32[0]) < 0.0000010000001 )
                return 1;
              m_quad = *(__m128 *)v2;
              v13 = (__m128)_xmm;
            }
          }
        }
        ++v14;
        ++m_data;
      }
      while ( v14 < v15 );
    }
    v165 = v9;
    v166 = m_quad;
    v164 = 0;
    v168 = 0;
    v167 = -2;
    hkcdDynamicAabbTree::queryAabb(v184, (hkAabb *)&v2[16], (hkcdAabbTreeQueries::AabbCollector *)&v2[56]);
    if ( v168 )
      return 1;
  }
  else
  {
    *(hkVector4f *)&v2[16] = (hkVector4f)end->m_quad;
    v169.m_max = (hkVector4f)v11.m_quad;
    v169.m_min = (hkVector4f)v10.m_quad;
    if ( v187 != -1 )
    {
      v170.m_min = (hkVector4f)v10.m_quad;
      v170.m_max = (hkVector4f)v11.m_quad;
      v60 = v187 - 3;
      if ( v187 < 3 )
        v60 = v187;
      v170.m_max.m_quad.m128_i32[v60] = 2139095022;
      v170.m_min.m_quad.m128_i32[v60] = -8388626;
    }
    v61 = (_DWORD)retaddr - 3;
    if ( (int)retaddr < 3 )
      v61 = (int)retaddr;
    v62 = segments->m_data;
    v63 = (__m128)_xmm;
    v160 = vertices;
    v161 = segments;
    *(_OWORD *)v2 = _xmm;
    v169.m_max.m_quad.m128_i32[v61] = 2139095022;
    v169.m_min.m_quad.m128_i32[v61] = -8388626;
    *(_QWORD *)&v2[56] = &A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
    v162 = (int)retaddr;
    v159 = v184;
    v163 = v189;
    v64 = 0i64;
    v65 = 6i64 * vars0;
    v66 = 0i64;
    LODWORD(retaddr) = v62[vars0].m_partitionIdA;
    *(_QWORD *)&v2[8] = v62[vars0].m_indices.m_size - 1;
    if ( *(__int64 *)&v2[8] > 0 )
    {
      v67 = (hkVector4f *)vertices->m128_u64[0];
      v68 = v62[vars0].m_indices.m_data;
      epsilon.m_quad.m128_u64[0] = vertices->m128_u64[0];
      do
      {
        v69 = v67[*v68].m_quad;
        v70 = v68[1];
        *(__m128 *)&v2[40] = v69;
        v71 = v67[v70].m_quad;
        *(__m128 *)&v2[24] = v71;
        if ( `anonymous namespace::_pointsAreDistinct(
               start,
               end,
               (hkVector4f *)&v2[40],
               (hkVector4f *)&v2[24],
               (hkVector4f *)v2) )
        {
          v72 = *(__m128 *)(v189 + 16);
          v73 = *(__m128 *)(v189 + 32);
          v74 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v73));
          v75 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v73));
          v76 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v69, v69, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v69, v69, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v69, v69, 170), v73));
          v77 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), *(__m128 *)v189),
                    _mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v72)),
                  _mm_mul_ps(_mm_shuffle_ps(v71, v71, 170), v73));
          if ( (_mm_movemask_ps(
                  _mm_or_ps(
                    _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v74, v75), v63), _mm_min_ps(v76, v77)),
                    _mm_cmplt_ps(_mm_max_ps(v76, v77), _mm_sub_ps(_mm_min_ps(v74, v75), v63)))) & 3) == 0 )
          {
            v78 = _mm_sub_ps(v77, v76);
            v79 = _mm_sub_ps(v75, v74);
            *(_OWORD *)&v2[48] = 0i64;
            v80 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 225), v79);
            if ( (float)(_mm_shuffle_ps(v80, v80, 0).m128_f32[0] - _mm_shuffle_ps(v80, v80, 85).m128_f32[0]) != 0.0 )
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
              v99 = _mm_cmple_ps(v92, *(__m128 *)&::epsilon);
              v100 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v98), v97);
              v101 = _mm_sub_ps(_mm_mul_ps(v91, v86), _mm_mul_ps(v87, v83));
              v102 = _mm_cmplt_ps(v101, v92);
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
              v104 = _mm_cmplt_ps(v103, query.m_quad);
              v105 = _mm_max_ps(
                       *(__m128 *)&v2[48],
                       _mm_or_ps(_mm_andnot_ps(v104, query.m_quad), _mm_and_ps(v104, v103)));
              v106 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v83, v100), v105), _mm_mul_ps(v86, v100));
              v107 = _mm_cmplt_ps(v106, query.m_quad);
              v108 = _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_max_ps(
                             *(__m128 *)&v2[48],
                             _mm_or_ps(_mm_andnot_ps(v107, query.m_quad), _mm_and_ps(v107, v106))),
                           v79),
                         v74),
                       _mm_add_ps(_mm_mul_ps(v105, v78), v76));
              v109 = _mm_mul_ps(v108, v108);
              if ( (float)((float)(_mm_shuffle_ps(v109, v109, 85).m128_f32[0] + _mm_shuffle_ps(v109, v109, 0).m128_f32[0])
                         + _mm_shuffle_ps(v109, v109, 170).m128_f32[0]) < 0.0000010000001 )
                return 1;
              m_quad = *(__m128 *)&v2[16];
              v63 = (__m128)_xmm;
            }
          }
        }
        v67 = (hkVector4f *)epsilon.m_quad.m128_u64[0];
        ++v66;
        ++v68;
      }
      while ( v66 < *(__int64 *)&v2[8] );
      v4 = v187;
    }
    v110 = v184;
    v165 = v9;
    v166 = m_quad;
    v164 = 0;
    v168 = 0;
    v167 = (int)retaddr;
    hkcdDynamicAabbTree::queryAabb(v184, &v169, (hkcdAabbTreeQueries::AabbCollector *)&v2[56]);
    if ( v168 )
      return 1;
    if ( v4 != -1 )
    {
      v172 = v110;
      *(__m128 *)&v2[16] = v63;
      v175 = v4;
      v173 = v182;
      v171.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&A0x257692e2::`anonymous namespace::PartitionIntersectionQuery::`vftable;
      v176 = vertices;
      v111 = *v183;
      v174 = v183;
      v188 = *(_DWORD *)(v111 + 8 * v65 + 8);
      v112 = *(_DWORD *)(v111 + 8 * v65 + 40) - 1;
      if ( v112 > 0 )
      {
        v113 = *(int **)(v111 + 8 * v65 + 32);
        v114 = *v182;
        v115 = v112;
        do
        {
          v116 = *(__m128 *)(v114 + 16i64 * *v113);
          v117 = v113[1];
          *(__m128 *)v2 = v116;
          v118 = *(__m128 *)(v114 + 16 * v117);
          *(__m128 *)&v2[48] = v118;
          if ( `anonymous namespace::_pointsAreDistinct(
                 start,
                 end,
                 (hkVector4f *)v2,
                 (hkVector4f *)&v2[48],
                 (hkVector4f *)&v2[16]) )
          {
            v119 = vertices[1];
            v120 = vertices[2];
            v121 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(start->m_quad, start->m_quad, 0), *vertices),
                       _mm_mul_ps(_mm_shuffle_ps(start->m_quad, start->m_quad, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(start->m_quad, start->m_quad, 170), v120));
            v122 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(end->m_quad, end->m_quad, 0), *vertices),
                       _mm_mul_ps(_mm_shuffle_ps(end->m_quad, end->m_quad, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(end->m_quad, end->m_quad, 170), v120));
            v123 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 0), *vertices),
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v116, v116, 170), v120));
            v124 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v118, v118, 0), *vertices),
                       _mm_mul_ps(_mm_shuffle_ps(v118, v118, 85), v119)),
                     _mm_mul_ps(_mm_shuffle_ps(v118, v118, 170), v120));
            if ( (_mm_movemask_ps(
                    _mm_or_ps(
                      _mm_cmplt_ps(_mm_add_ps(_mm_max_ps(v121, v122), v63), _mm_min_ps(v123, v124)),
                      _mm_cmplt_ps(_mm_max_ps(v123, v124), _mm_sub_ps(_mm_min_ps(v121, v122), v63)))) & 3) == 0 )
            {
              v125 = _mm_sub_ps(v124, v123);
              v126 = _mm_sub_ps(v122, v121);
              v127 = _mm_mul_ps(_mm_shuffle_ps(v125, v125, 225), v126);
              if ( (float)(_mm_shuffle_ps(v127, v127, 0).m128_f32[0] - _mm_shuffle_ps(v127, v127, 85).m128_f32[0]) != 0.0 )
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
                v145 = _mm_cmple_ps(v139, *(__m128 *)&::epsilon);
                v146 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v143)), v143);
                v147 = _mm_sub_ps(_mm_mul_ps(v138, v133), _mm_mul_ps(v134, v130));
                v148 = _mm_cmplt_ps(v147, v139);
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
                v150 = _mm_cmplt_ps(v149, query.m_quad);
                v151 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v150, query.m_quad), _mm_and_ps(v149, v150)));
                v152 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v130, v146), v151), _mm_mul_ps(v133, v146));
                v153 = _mm_cmplt_ps(v152, query.m_quad);
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
                if ( (float)((float)(_mm_shuffle_ps(v155, v155, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v155, v155, 0).m128_f32[0])
                           + _mm_shuffle_ps(v155, v155, 170).m128_f32[0]) < 0.0000010000001 )
                  return 1;
                v63 = (__m128)_xmm;
              }
            }
          }
          ++v64;
          ++v113;
        }
        while ( v64 < v115 );
      }
      v156 = end->m_quad;
      v178 = start->m_quad;
      v179 = v156;
      v180 = v188;
      v177 = 0;
      v181 = 0;
      hkcdDynamicAabbTree::queryAabb(v184, &v170, &v171);
      if ( v181 )
        return 1;
    }
  }
  return 0;
}

// File Line: 1617
// RVA: 0xB532F0
hkSimdFloat32 *__fastcall `anonymous namespace::getClosestPointOnLine(
        hkSimdFloat32 *result,
        hkVector4f *p,
        hkVector4f *a,
        hkVector4f *b,
        int majorAxis,
        hkVector4f *out)
{
  __m128 m_quad; // xmm5
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
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  hkSimdFloat32 *v20; // rax
  __m128 v21; // xmm4

  m_quad = b->m_quad;
  v7 = a->m_quad;
  v8 = p->m_quad;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      v9 = _mm_shuffle_ps(_mm_unpacklo_ps(v7, (__m128)0i64), v7, 228);
      v10 = _mm_shuffle_ps(_mm_unpacklo_ps(m_quad, (__m128)0i64), m_quad, 228);
      v11 = _mm_shuffle_ps(_mm_unpacklo_ps(v8, (__m128)0i64), v8, 228);
    }
    else
    {
      v9 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 180);
      v10 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 180);
      v11 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, (__m128)0i64), 180);
    }
  }
  else
  {
    v9 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v7, 4), 4);
    v10 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)m_quad, 4), 4);
    v11 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v8, 4), 4);
  }
  v12 = _mm_sub_ps(v10, v9);
  v13 = _mm_mul_ps(_mm_sub_ps(v11, v9), v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(v12, v12);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rcp_ps(v16);
  v18 = _mm_add_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmplt_ps(
                v16,
                _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), v14)),
            v12),
          v9);
  *out = (hkVector4f)v18;
  v19 = _mm_sub_ps(v18, v11);
  v20 = result;
  v21 = _mm_mul_ps(v19, v19);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                     _mm_shuffle_ps(v21, v21, 170));
  return v20;
}

// File Line: 1653
// RVA: 0xB53440
hkSimdFloat32 *__fastcall `anonymous namespace::getHeightErrorSquared(
        hkSimdFloat32 *result,
        hkVector4f *p,
        hkVector4f *a,
        hkVector4f *b,
        int majorAxis)
{
  int v5; // ebx
  __m128 v10; // xmm5
  hkSimdFloat32 *v11; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm7
  hkVector4f out; // [rsp+30h] [rbp-38h] BYREF
  hkSimdFloat32 resulta; // [rsp+40h] [rbp-28h] BYREF

  v5 = majorAxis;
  if ( majorAxis >= 3 )
    v5 = majorAxis - 3;
  `anonymous namespace::getClosestPointOnLine(&resulta, p, a, b, v5, &out);
  v10 = _mm_sub_ps(b->m_quad, a->m_quad);
  out.m_quad.m128_i32[v5] = p->m_quad.m128_i32[v5];
  v11 = result;
  v12 = _mm_mul_ps(_mm_sub_ps(out.m_quad, a->m_quad), v10);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_mul_ps(v10, v10);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rcp_ps(v15);
  v17 = _mm_sub_ps(
          out.m_quad,
          _mm_add_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmplt_ps(
                  v15,
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v15)), v16), v13)),
              v10),
            a->m_quad));
  v18 = _mm_mul_ps(v17, v17);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                     _mm_shuffle_ps(v18, v18, 170));
  return v11;
}

// File Line: 1685
// RVA: 0xB53580
float __fastcall `anonymous namespace::computeAabb(
        hkArrayBase<hkVector2f> *points,
        hkVector2f *centerOut,
        hkVector2f *e0Out,
        hkVector2f *e1Out)
{
  __int64 m_size; // r10
  float result; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  hkVector2f *v10; // rax
  __int64 v11; // rcx
  float x; // xmm2_4
  float y; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm4_4

  m_size = points->m_size;
  if ( !(_DWORD)m_size )
    return 0.0;
  LODWORD(v6) = HIDWORD(*(unsigned __int64 *)points->m_data);
  LODWORD(v7) = *(hkVector2f *)&points->m_data->x;
  v8 = v6;
  v9 = v7;
  if ( m_size > 1 )
  {
    v10 = points->m_data + 1;
    v11 = m_size - 1;
    do
    {
      x = v10->x;
      y = v10->y;
      ++v10;
      v7 = fminf(v7, x);
      v6 = fminf(v6, y);
      v9 = fmaxf(v9, x);
      v8 = fmaxf(v8, y);
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
char __fastcall `anonymous namespace::convertSegmentToObb(
        hkaiNavMeshGenerationSettings *settings,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkResultEnum segmentIndex,
        int majorAxisA,
        int majorAxisB,
        hkcdDynamicAabbTree *tree,
        hkResult *resOut)
{
  hkaiNavMeshSimplificationUtils::Segment *m_data; // r13
  __int64 v10; // rdx
  __int64 m_size; // r14
  hkArray<int,hkContainerHeapAllocator> *v12; // rsi
  int *v14; // rbx
  int v15; // r15d
  float v16; // xmm7_4
  int v17; // r12d
  __m128 m_real; // xmm6
  int v19; // r14d
  __m128 v20; // xmm2
  __int64 v21; // rcx
  __int64 v22; // rax
  __m128 v23; // xmm0
  float v24; // xmm0_4
  __int64 i; // rbx
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 m_quad; // xmm7
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
  float x; // eax
  hkResult *v50; // r13
  unsigned __int64 v51; // rbx
  int v52; // r8d
  float v53; // xmm9_4
  __int64 v54; // rdx
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __int64 v58; // rcx
  __m128 v59; // xmm4
  __m128 v60; // xmm5
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm3
  __m128 v65; // xmm2
  __m128 v66; // xmm2
  float v67; // xmm1_4
  float v68; // xmm14_4
  float v69; // xmm0_4
  hkVector2f v70; // rcx
  hkVector2f v71; // rax
  __m128 v72; // xmm0
  __m128 v73; // xmm4
  __m128 v74; // xmm2
  __m128 v75; // xmm3
  __m128 v76; // xmm0
  __m128 v77; // xmm3
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 x_low; // xmm13
  __m128 y_low; // xmm10
  __m128 v82; // xmm8
  __m128 v83; // xmm9
  float v84; // xmm12_4
  __m128 v85; // xmm4
  float v86; // xmm11_4
  __m128 v87; // xmm1
  __m128 v88; // xmm2
  __m128 v89; // xmm1
  __m128 v90; // xmm4
  int v91; // ebx
  int v92; // r9d
  int v93; // eax
  int v94; // eax
  hkResultEnum m_enum; // eax
  __int64 v96; // rcx
  __m128 v97; // xmm0
  __int64 v98; // rax
  __int64 v99; // rcx
  hkVector4f *v100; // rax
  char v101; // bl
  hkVector2f v102; // [rsp+50h] [rbp-B0h] BYREF
  hkVector2f e1Out; // [rsp+58h] [rbp-A8h] BYREF
  hkVector2f e0Out; // [rsp+60h] [rbp-A0h] BYREF
  hkArrayBase<hkVector2f> array; // [rsp+68h] [rbp-98h] BYREF
  hkVector2f centerOut; // [rsp+78h] [rbp-88h] BYREF
  hkQuaternionf quat; // [rsp+80h] [rbp-80h] BYREF
  hkSimdFloat32 result; // [rsp+90h] [rbp-70h] BYREF
  hkVector4f planeOut; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v110; // [rsp+B0h] [rbp-50h]
  hkArrayBase<hkVector4f> points; // [rsp+C0h] [rbp-40h] BYREF
  __m128 v112; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f end; // [rsp+E0h] [rbp-20h] BYREF
  hkVector4f v114; // [rsp+F0h] [rbp-10h] BYREF
  hkVector4f start; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f v116; // [rsp+110h] [rbp+10h] BYREF
  hkVector4f v117; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f v118; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f v119; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f direction; // [rsp+150h] [rbp+50h] BYREF
  hkRotationf v121; // [rsp+160h] [rbp+60h] BYREF
  hkRotationf projectionMatrix; // [rsp+190h] [rbp+90h] BYREF
  hkaiNavMeshSimplificationUtils::PlaneFitter v123; // [rsp+1C0h] [rbp+C0h] BYREF
  hkResult v126; // [rsp+318h] [rbp+218h] BYREF

  v126.m_enum = segmentIndex;
  resOut->m_enum = HK_SUCCESS;
  m_data = segmentsInOut->m_data;
  v10 = segmentIndex;
  v110 = v10 * 48;
  m_size = m_data[v10].m_indices.m_size;
  v12 = (hkArray<int,hkContainerHeapAllocator> *)&m_data[v10];
  if ( (int)m_size <= 5 )
    return 0;
  v14 = v12[2].m_data;
  if ( *v14 != v14[m_size - 1] || m_data[v10].m_partitionIdB != -1 )
    return 0;
  v15 = majorAxisA;
  `anonymous namespace::computeSignedLoopArea(&result, verticesInOut, v12 + 2, majorAxisA);
  v16 = result.m_real.m128_f32[0];
  if ( result.m_real.m128_f32[0] <= 0.0 )
    return 0;
  v17 = majorAxisB;
  m_real.m128_i32[0] = 0;
  if ( v15 != majorAxisB && majorAxisB != -1 )
  {
    m_real = `anonymous namespace::computeSignedLoopArea(&result, verticesInOut, v12 + 2, majorAxisB)->m_real;
    if ( m_real.m128_f32[0] <= 0.0 )
      return 0;
  }
  v19 = m_size - 1;
  v20 = 0i64;
  if ( v19 > 0 )
  {
    v21 = v19;
    do
    {
      v22 = *v14++;
      v20 = _mm_add_ps(v20, verticesInOut->m_data[v22].m_quad);
      --v21;
    }
    while ( v21 );
  }
  v23 = 0i64;
  v23.m128_f32[0] = (float)v19;
  points.m_size = 1;
  points.m_data = (hkVector4f *)&v112;
  points.m_capacityAndFlags = -2147483647;
  v112 = _mm_mul_ps(_mm_div_ps(query.m_quad, _mm_shuffle_ps(v23, v23, 0)), v20);
  result.m_real.m128_u64[0] = (unsigned __int64)hkaiNavMeshGenerationSettings::getSimplificationSettings(
                                                  settings,
                                                  &points,
                                                  *(int *)((char *)&m_data->m_materialSettingsIndex + v110));
  v24 = *(float *)(result.m_real.m128_u64[0] + 16);
  if ( v16 <= v24 && m_real.m128_f32[0] <= v24 )
  {
    hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&v123);
    for ( i = 0i64;
          i < v19;
          hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v123, &verticesInOut->m_data[v12[2].m_data[i++]]) )
    {
      ;
    }
    hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v123, (hkResult *)&v102, &planeOut);
    v26 = _mm_mul_ps(planeOut.m_quad, planeOut.m_quad);
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170));
    v28 = _mm_rsqrt_ps(v27);
    m_quad = _mm_mul_ps(
               planeOut.m_quad,
               _mm_andnot_ps(
                 _mm_cmple_ps(v27, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                   _mm_mul_ps(v28, *(__m128 *)_xmm))));
    planeOut.m_quad = m_quad;
    v30 = _mm_mul_ps(m_quad, stru_141A71280.m_quad);
    v31 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(m_quad, m_quad, 255));
    v32 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v102.x = FLOAT_0_99998999;
    v33 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
    if ( v32.m128_f32[0] <= v33 )
    {
      if ( v32.m128_f32[0] < (float)(0.0 - v33) )
      {
        hkQuaternionf::setFlippedRotation(&quat, &planeOut);
        m_quad = planeOut.m_quad;
        v34 = quat.m_vec.m_quad;
        goto LABEL_27;
      }
      v35 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v32), (__m128)xmmword_141A711B0);
      v36 = _mm_rsqrt_ps(v35);
      v37 = _mm_andnot_ps(
              _mm_cmple_ps(v35, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                _mm_mul_ps(v36, *(__m128 *)_xmm)));
      v38 = _mm_mul_ps(v37, (__m128)xmmword_141A711B0);
      v39 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), stru_141A71280.m_quad));
      v40 = _mm_shuffle_ps(v39, v39, 201);
      v102.x = FLOAT_N0_99900001;
      if ( v32.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0).m128_f32[0] )
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
                    _mm_cmple_ps(v42, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v42), v46)),
                      _mm_mul_ps(v46, *(__m128 *)_xmm))),
                  v42),
                _mm_andnot_ps(_mm_cmple_ps(v43, (__m128)0i64), v45));
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
    array.m_capacityAndFlags = 0x80000000;
    array.m_data = 0i64;
    array.m_size = 0;
    if ( v19 <= 0 )
    {
      x = 0.0;
    }
    else
    {
      hkArrayUtil::_reserve((hkResult *)&v102, &hkContainerTempAllocator::s_alloc, &array, v19, 8);
      x = v102.x;
      m_quad = planeOut.m_quad;
      v34 = quat.m_vec.m_quad;
      if ( LODWORD(v102.x) )
      {
        v19 = array.m_size;
        goto LABEL_32;
      }
    }
    array.m_size = v19;
LABEL_32:
    v50 = resOut;
    *(float *)&resOut->m_enum = x;
    if ( x == 0.0 )
    {
      v51 = result.m_real.m128_u64[0];
      v52 = 0;
      LODWORD(v53) = _mm_shuffle_ps(
                       (__m128)*(unsigned int *)(result.m_real.m128_u64[0] + 28),
                       (__m128)*(unsigned int *)(result.m_real.m128_u64[0] + 28),
                       0).m128_u32[0];
      if ( v19 <= 0 )
      {
LABEL_38:
        v65 = 0i64;
        v65.m128_f32[0] = (float)v19;
        centerOut = 0i64;
        e0Out = 0i64;
        v66 = _mm_shuffle_ps(v65, v65, 0);
        v67 = _mm_rcp_ps(v66).m128_f32[0];
        e1Out = 0i64;
        v68 = v48.m128_f32[0] * (float)((float)(2.0 - (float)(v66.m128_f32[0] * v67)) * v67);
        v69 = hkVector2Util::computeObb(&array, &centerOut, &e0Out, &e1Out, v50);
        if ( v50->m_enum == HK_SUCCESS )
        {
          resOut = 0i64;
          v102 = 0i64;
          result.m_real.m128_u64[0] = 0i64;
          if ( `anonymous namespace::computeAabb(&array, (hkVector2f *)&resOut, &v102, (hkVector2f *)&result) >= (float)(v69 * *(float *)(v51 + 20)) )
          {
            v71 = e0Out;
            v70 = e1Out;
          }
          else
          {
            v70 = (hkVector2f)result.m_real.m128_u64[0];
            centerOut = (hkVector2f)resOut;
            v71 = v102;
            e1Out = (hkVector2f)result.m_real.m128_u64[0];
            e0Out = v102;
          }
          v72 = _mm_mul_ps((__m128)*(unsigned __int64 *)&v71, (__m128)*(unsigned __int64 *)&v71);
          v73 = _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0));
          v74 = _mm_rsqrt_ps(v73);
          v75 = _mm_andnot_ps(
                  _mm_cmple_ps(v73, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v74, v73), v74)),
                    _mm_mul_ps(*(__m128 *)_xmm, v74)));
          resOut = (hkResult *)_mm_mul_ps((__m128)*(unsigned __int64 *)&v71, v75).m128_u64[0];
          if ( (float)(v75.m128_f32[0] * v73.m128_f32[0]) >= 0.00000011920929 )
          {
            v76 = _mm_mul_ps((__m128)*(unsigned __int64 *)&v70, (__m128)*(unsigned __int64 *)&v70);
            v77 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0));
            v78 = _mm_rsqrt_ps(v77);
            v79 = _mm_andnot_ps(
                    _mm_cmple_ps(v77, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                      _mm_mul_ps(v78, *(__m128 *)_xmm)));
            v102 = (hkVector2f)_mm_mul_ps((__m128)*(unsigned __int64 *)&v70, v79).m128_u64[0];
            if ( (float)(v79.m128_f32[0] * v77.m128_f32[0]) >= 0.00000011920929 )
            {
              x_low = (__m128)LODWORD(e0Out.x);
              y_low = (__m128)LODWORD(e0Out.y);
              v82 = (__m128)LODWORD(centerOut.y);
              v83 = (__m128)LODWORD(centerOut.x);
              x_low.m128_f32[0] = e0Out.x + (float)(*(float *)&resOut * 0.0020000001);
              v84 = e1Out.x + (float)(v102.x * 0.0020000001);
              y_low.m128_f32[0] = e0Out.y + (float)(*((float *)&resOut + 1) * 0.0020000001);
              v83.m128_f32[0] = centerOut.x - x_low.m128_f32[0];
              v85 = v83;
              v86 = e1Out.y + (float)(v102.y * 0.0020000001);
              v85.m128_f32[0] = (float)(centerOut.x - x_low.m128_f32[0]) + v84;
              v82.m128_f32[0] = centerOut.y - y_low.m128_f32[0];
              v87 = v82;
              v87.m128_f32[0] = (float)(centerOut.y - y_low.m128_f32[0]) + v86;
              e0Out.y = y_low.m128_f32[0];
              y_low.m128_f32[0] = y_low.m128_f32[0] + centerOut.y;
              v88 = v87;
              v89 = y_low;
              e0Out.x = x_low.m128_f32[0];
              x_low.m128_f32[0] = x_low.m128_f32[0] + centerOut.x;
              v89.m128_f32[0] = y_low.m128_f32[0] + v86;
              *(float *)&resOut = v68;
              y_low.m128_f32[0] = y_low.m128_f32[0] - v86;
              v83.m128_f32[0] = v83.m128_f32[0] - v84;
              v82.m128_f32[0] = v82.m128_f32[0] - v86;
              e1Out.x = v84;
              direction.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(v85, (__m128)LODWORD(v68)),
                                   _mm_unpacklo_ps(v88, (__m128)0i64));
              v90 = x_low;
              v90.m128_f32[0] = x_low.m128_f32[0] + v84;
              x_low.m128_f32[0] = x_low.m128_f32[0] - v84;
              e1Out.y = v86;
              v118.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(v90, (__m128)LODWORD(v68)),
                              _mm_unpacklo_ps(v89, (__m128)0i64));
              v117.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(x_low, (__m128)LODWORD(v68)),
                              _mm_unpacklo_ps(y_low, (__m128)0i64));
              v119.m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(v83, (__m128)LODWORD(v68)),
                              _mm_unpacklo_ps(v82, (__m128)0i64));
              hkVector4f::setRotatedInverseDir(&start, &quat, &direction);
              hkVector4f::setRotatedInverseDir(&end, &quat, &v118);
              hkVector4f::setRotatedInverseDir(&v116, &quat, &v117);
              hkVector4f::setRotatedInverseDir(&v114, &quat, &v119);
              anonymous_namespace_::getProjectionMatrix(majorAxisA, &projectionMatrix);
              anonymous_namespace_::getProjectionMatrix(v17, &v121);
              if ( !`anonymous namespace::doesLineSegmentIntersectPartition(
                      &start,
                      &end,
                      (__m128 *)verticesInOut,
                      segmentsInOut)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(
                      &end,
                      &v116,
                      (__m128 *)verticesInOut,
                      segmentsInOut)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(
                      &v116,
                      &v114,
                      (__m128 *)verticesInOut,
                      segmentsInOut)
                && !`anonymous namespace::doesLineSegmentIntersectPartition(
                      &v114,
                      &start,
                      (__m128 *)verticesInOut,
                      segmentsInOut) )
              {
                v91 = verticesInOut->m_size;
                v92 = v91 + 4;
                v93 = verticesInOut->m_capacityAndFlags & 0x3FFFFFFF;
                if ( v93 >= v91 + 4 )
                {
                  m_enum = HK_SUCCESS;
                }
                else
                {
                  v94 = 2 * v93;
                  if ( v92 < v94 )
                    v92 = v94;
                  hkArrayUtil::_reserve(&v126, &hkContainerHeapAllocator::s_alloc, verticesInOut, v92, 16);
                  m_enum = v126.m_enum;
                }
                v50->m_enum = m_enum;
                if ( m_enum == HK_SUCCESS )
                {
                  v96 = verticesInOut->m_size;
                  v97 = start.m_quad;
                  verticesInOut->m_size = v96 + 4;
                  v98 = v96;
                  v99 = v110;
                  v100 = &verticesInOut->m_data[v98];
                  *v100 = (hkVector4f)v97;
                  v100[1] = (hkVector4f)end.m_quad;
                  v100[2] = (hkVector4f)v116.m_quad;
                  v100[3] = (hkVector4f)v114.m_quad;
                  v12[2].m_size = 5;
                  *(int *)((char *)&segmentsInOut->m_data->m_boundary.m_size + v99) = 4;
                  *v12[2].m_data = v91;
                  v12[2].m_data[1] = v91 + 1;
                  v12[2].m_data[2] = v91 + 2;
                  v12[2].m_data[3] = v91 + 3;
                  v12[2].m_data[4] = v91;
                  v101 = 1;
LABEL_56:
                  array.m_size = 0;
                  if ( array.m_capacityAndFlags >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerTempAllocator::s_alloc,
                      array.m_data,
                      8 * array.m_capacityAndFlags);
                  array.m_data = 0i64;
                  array.m_capacityAndFlags = 0x80000000;
                  goto LABEL_60;
                }
              }
            }
          }
        }
      }
      else
      {
        v54 = 0i64;
        while ( 1 )
        {
          v55 = verticesInOut->m_data[v12[2].m_data[v54]].m_quad;
          v56 = _mm_mul_ps(m_quad, v55);
          v57 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                    _mm_shuffle_ps(v56, v56, 170)),
                  v31);
          if ( COERCE_FLOAT((unsigned int)(2 * v57.m128_i32[0]) >> 1) > v53 )
            break;
          v58 = v52++;
          ++v54;
          v59 = _mm_shuffle_ps(v34, v34, 255);
          v60 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v57), m_quad), v55);
          v61 = _mm_mul_ps(v34, v60);
          v62 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v34),
                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v60));
          v63 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                        _mm_shuffle_ps(v61, v61, 170)),
                      v34),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v59, v59), (__m128)xmmword_141A711B0), v60)),
                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v59));
          v64 = _mm_add_ps(v63, v63);
          array.m_data[v58] = (hkVector2f)v64.m128_u64[0];
          v19 = array.m_size;
          v48 = _mm_add_ps(v48, _mm_shuffle_ps(v64, v64, 170));
          if ( v52 >= array.m_size )
            goto LABEL_38;
          m_quad = planeOut.m_quad;
          v34 = quat.m_vec.m_quad;
        }
      }
    }
    v101 = 0;
    goto LABEL_56;
  }
  v101 = 0;
LABEL_60:
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v101;
}rHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v101;
}

// File Line: 1951
// RVA: 0xB54280
void __fastcall anonymous_namespace_::setPackXY(hkVector4f *vOut, hkVector4f *p1, hkVector4f *p2)
{
  __m128 v3; // xmm3

  v3 = _mm_shuffle_ps(p1->m_quad, _mm_unpackhi_ps(p1->m_quad, _mm_shuffle_ps(p2->m_quad, p2->m_quad, 0)), 180);
  vOut->m_quad = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, _mm_shuffle_ps(p2->m_quad, p2->m_quad, 85)), 196);
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
hkResult *__fastcall anonymous_namespace_::gatherCorridorSegments(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkaiNavMeshSimplificationUtils::Segment *segment,
        hkRotationf *proj,
        int skipIndex,
        hkVector4f *va,
        hkVector4f *vb,
        hkVector4f *vap,
        hkVector4f *vbp,
        hkArray<hkVector4f,hkContainerTempAllocator> *testSegs)
{
  int v10; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v12; // r10
  hkArray<hkVector4f,hkContainerTempAllocator> *v14; // rbx
  hkVector4f *v15; // r15
  hkVector4f *v16; // r12
  int v17; // r14d
  __int64 v18; // rdi
  int *m_data; // rax
  __int64 v20; // r8
  __int64 v21; // rdx
  __m128 m_quad; // xmm1
  __m128 v23; // xmm5
  float v24; // xmm11_4
  float v25; // xmm10_4
  float v26; // xmm13_4
  float v27; // xmm14_4
  float v28; // xmm8_4
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  float v31; // xmm4_4
  BOOL v32; // edx
  float v33; // xmm0_4
  float v34; // xmm8_4
  BOOL v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm5_4
  BOOL v38; // eax
  int v39; // r9d
  int v40; // eax
  int v41; // eax
  __m128 *p_m_quad; // rcx
  __m128 v43; // xmm6
  hkResult resulta; // [rsp+130h] [rbp+18h] BYREF
  hkRotationf *v47; // [rsp+138h] [rbp+20h]

  v47 = proj;
  v10 = 0;
  v12 = vertices;
  if ( segment->m_indices.m_size - 1 <= 0 )
  {
LABEL_30:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v14 = testSegs;
  v15 = vbp;
  v16 = vap;
  v17 = skipIndex;
  v18 = 0i64;
  while ( 1 )
  {
    m_data = segment->m_indices.m_data;
    v20 = m_data[v18];
    if ( (_DWORD)v20 == v17 )
      goto LABEL_29;
    v21 = m_data[v18 + 1];
    if ( (_DWORD)v21 == v17 )
      goto LABEL_29;
    m_quad = v12->m_data[v20].m_quad;
    v23 = v12->m_data[v21].m_quad;
    v24 = va->m_quad.m128_f32[0];
    v25 = va->m_quad.m128_f32[1];
    v26 = vb->m_quad.m128_f32[0];
    v27 = vb->m_quad.m128_f32[1];
    v28 = vb->m_quad.m128_f32[0] - va->m_quad.m128_f32[0];
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), proj->m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), proj->m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), proj->m_col2.m_quad));
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), proj->m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), proj->m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), proj->m_col2.m_quad));
    v31 = _mm_shuffle_ps(v29, v29, 85).m128_f32[0];
    v32 = (float)((float)(v28 * (float)(v31 - v25))
                - (float)((float)(v29.m128_f32[0] - va->m_quad.m128_f32[0]) * (float)(v27 - v25))) < 0.0
       && (float)((float)((float)(v30.m128_f32[1] - v25) * v28)
                - (float)((float)(v30.m128_f32[0] - v24) * (float)(v27 - v25))) < 0.0;
    v33 = v16->m_quad.m128_f32[0] - v24;
    v34 = v16->m_quad.m128_f32[1] - v25;
    v35 = (float)((float)((float)(v31 - v25) * v33) - (float)((float)(v29.m128_f32[0] - va->m_quad.m128_f32[0]) * v34)) > 0.0
       && (float)((float)((float)(v30.m128_f32[1] - v25) * v33) - (float)((float)(v30.m128_f32[0] - v24) * v34)) > 0.0;
    v36 = v15->m_quad.m128_f32[0] - v26;
    v37 = v15->m_quad.m128_f32[1] - v27;
    v38 = (float)((float)((float)(v31 - v27) * v36) - (float)((float)(v29.m128_f32[0] - v26) * v37)) < 0.0
       && (float)((float)((float)(v30.m128_f32[1] - v27) * v36) - (float)((float)(v30.m128_f32[0] - v26) * v37)) < 0.0;
    if ( v32 || v35 || v38 )
      goto LABEL_29;
    v39 = v14->m_size + 1;
    v40 = v14->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v40 < v39 )
      break;
    resulta.m_enum = HK_SUCCESS;
LABEL_26:
    if ( v14->m_size == (v14->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v14, 16);
    proj = v47;
    v12 = vertices;
    p_m_quad = &v14->m_data[v14->m_size].m_quad;
    v43 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, _mm_shuffle_ps(v30, v30, 0)), 180);
    ++v14->m_size;
    *p_m_quad = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, _mm_shuffle_ps(v30, v30, 85)), 196);
LABEL_29:
    ++v10;
    ++v18;
    if ( v10 >= segment->m_indices.m_size - 1 )
      goto LABEL_30;
  }
  v41 = 2 * v40;
  if ( v39 < v41 )
    v39 = v41;
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, v14, v39, 16);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_26;
  result->m_enum = resulta.m_enum;
  return result;
}

// File Line: 2046
// RVA: 0xB5A120
_BOOL8 __fastcall A0x257692e2::`anonymous namespace::CorridorIntersectionQuery::processLeaf(
        CorridorIntersectionQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkResult *v4; // rax
  hkResultEnum m_enum; // ecx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

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
  m_enum = v4->m_enum;
  this->m_res = (hkResult)v4->m_enum;
  return m_enum == HK_SUCCESS;
}

// File Line: 2070
// RVA: 0xB546A0
char __fastcall `anonymous namespace::collapseMakesCorridorImpassable(
        float minCorridorWidth,
        float maxCorridorWidth,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *pa,
        hkVector4f *pb,
        int skipIndex,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkRotationf *segments,
        hkcdDynamicAabbTree *segmentIndex,
        int *majorAxis,
        hkRotationf *projection,
        hkcdDynamicAabbTree *tree,
        hkResult *resOut)
{
  int *v15; // rdi
  float v17; // xmm2_4
  float v18; // xmm7_4
  __m128 v19; // xmm11
  __m128 m_quad; // xmm10
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
  __m128 v36; // xmm2
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
  int v47; // eax
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  __m128 v51; // xmm9
  __m128 v52; // xmm10
  int v53; // eax
  hkVector4f *m_data; // r11
  char v55; // bl
  int v56; // r8d
  int v57; // r9d
  int v58; // ebx
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
  int v93; // ecx
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
  int v110; // eax
  __m128 v111; // xmm11
  __m128 v112; // xmm12
  hkVector4f *v113; // rcx
  __int64 m_size; // rdx
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
  hkArray<hkVector4f,hkContainerTempAllocator> testSegs; // [rsp+50h] [rbp-98h] BYREF
  float v144; // [rsp+60h] [rbp-88h]
  __m256i vb; // [rsp+68h] [rbp-80h] BYREF
  hkVector4f va; // [rsp+88h] [rbp-60h] BYREF
  __m128 v147; // [rsp+98h] [rbp-50h]
  __m128 v148; // [rsp+A8h] [rbp-40h]
  __m128 v149; // [rsp+B8h] [rbp-30h]
  __m128 v150; // [rsp+C8h] [rbp-20h]
  hkAabb aabb; // [rsp+D8h] [rbp-10h] BYREF
  __m128 v152; // [rsp+F8h] [rbp+10h]
  __m128 v153; // [rsp+108h] [rbp+20h]
  __m128 v154; // [rsp+118h] [rbp+30h]
  __m128 v155; // [rsp+128h] [rbp+40h]
  __m128 v156; // [rsp+138h] [rbp+50h]
  __m128 v157; // [rsp+148h] [rbp+60h]
  __m128 v158; // [rsp+158h] [rbp+70h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+168h] [rbp+80h] BYREF
  hkcdDynamicAabbTree *v160; // [rsp+170h] [rbp+88h]
  hkVector4f *v161; // [rsp+178h] [rbp+90h]
  hkVector4f *v162; // [rsp+180h] [rbp+98h]
  int v163; // [rsp+188h] [rbp+A0h]
  hkRotationf *v164; // [rsp+190h] [rbp+A8h]
  int v165; // [rsp+198h] [rbp+B0h]
  __m128 v166; // [rsp+1A8h] [rbp+C0h]
  __m128 v167; // [rsp+1B8h] [rbp+D0h]
  __m128 v168; // [rsp+1C8h] [rbp+E0h]
  __m128 v169; // [rsp+1D8h] [rbp+F0h]
  hkArray<hkVector4f,hkContainerTempAllocator> *p_testSegs; // [rsp+1E8h] [rbp+100h]
  int v171; // [rsp+1F0h] [rbp+108h]
  unsigned int v172; // [rsp+2B8h] [rbp+1D0h]
  unsigned int vars0; // [rsp+2C0h] [rbp+1D8h]
  __m128 *v174; // [rsp+2D8h] [rbp+1F0h]
  __m128 *v175; // [rsp+2E0h] [rbp+1F8h]
  __m128 *v176; // [rsp+2E8h] [rbp+200h]

  *(float *)&v174 = maxCorridorWidth;
  v15 = majorAxis;
  *majorAxis = 0;
  v17 = (float)(minCorridorWidth + maxCorridorWidth) * 0.5;
  v144 = v17;
  v18 = v17 * 0.0099999998;
  *(float *)&majorAxis = v17 * 0.2;
  v19 = _mm_shuffle_ps((__m128)(unsigned int)majorAxis, (__m128)(unsigned int)majorAxis, 0);
  v150 = v19;
  if ( maxCorridorWidth <= 0.0 )
    return 0;
  m_quad = p1->m_quad;
  v22 = *v174;
  v23 = _mm_sub_ps(p0->m_quad, *v174);
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_sub_ps(p0->m_quad, p1->m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v27 = _mm_mul_ps(v25, v23);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rcp_ps(v26);
  v30 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v26)), v29), v28);
  v31 = _mm_cmplt_ps(v30, query.m_quad);
  v32 = _mm_sub_ps(
          v25,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v30, v31), _mm_andnot_ps(v31, query.m_quad))), v23));
  v33 = _mm_mul_ps(v32, v32);
  if ( (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
             + _mm_shuffle_ps(v33, v33, 170).m128_f32[0]) < (float)(v18 * v18) )
    return 0;
  v34 = segments->m_col2.m_quad;
  v35 = segments->m_col1.m_quad;
  v36 = segments->m_col0.m_quad;
  v149 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 0), segments->m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 170), v34));
  v148 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v36),
             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v34));
  v147 = _mm_add_ps(
           _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v36), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v35)),
           _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v34));
  v37 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(*v175, *v175, 0), v36),
            _mm_mul_ps(_mm_shuffle_ps(*v175, *v175, 85), v35)),
          _mm_mul_ps(_mm_shuffle_ps(*v175, *v175, 170), v34));
  v38 = *v176;
  v39 = *v176;
  v154 = v37;
  va.m_quad = v37;
  v40 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v36), _mm_mul_ps(_mm_shuffle_ps(v39, v38, 85), v35)),
          _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v34));
  v41 = _mm_sub_ps(v40, v37);
  v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 225), (__m128)xmmword_141A71310);
  v43 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, (__m128)0i64), 180), 4),
                  4);
  v44 = _mm_mul_ps(v43, v43);
  v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 78), v44);
  v46 = (__m128)_xmm;
  *(float *)&majorAxis = maxCorridorWidth * 10.0;
  v47 = (_DWORD)vertices - 3;
  v48 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v45);
  v49 = _mm_rsqrt_ps(v48);
  v50 = _mm_shuffle_ps(
          (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
          (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
          0);
  v157 = _mm_mul_ps(
           _mm_mul_ps(
             _mm_andnot_ps(
               _mm_cmple_ps(v48, (__m128)0i64),
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                 _mm_mul_ps(v49, *(__m128 *)_xmm))),
             v43),
           _mm_shuffle_ps(
             (__m128)COERCE_UNSIGNED_INT(maxCorridorWidth * 10.0),
             (__m128)COERCE_UNSIGNED_INT(maxCorridorWidth * 10.0),
             0));
  v51 = _mm_add_ps(v157, v37);
  v52 = _mm_add_ps(v157, v40);
  *(__m128 *)vb.m256i_i8 = v51;
  *(__m128 *)&vb.m256i_u64[2] = v52;
  aabb.m_max.m_quad = _mm_add_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(v37, v40), v51), v52), v50);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(_mm_min_ps(_mm_min_ps(v37, v40), v51), v52), v50);
  if ( (int)vertices < 3 )
    v47 = (int)vertices;
  v163 = (int)vertices;
  v162 = pb;
  aabb.m_max.m_quad.m128_i32[v47] = 2139095022;
  aabb.m_min.m_quad.m128_i32[v47] = -8388626;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&A0x257692e2::`anonymous namespace::CorridorIntersectionQuery::`vftable;
  testSegs.m_data = 0i64;
  v160 = segmentIndex;
  testSegs.m_size = 0;
  testSegs.m_capacityAndFlags = 0x80000000;
  v161 = pa;
  v164 = segments;
  anonymous_namespace_::gatherCorridorSegments(
    (hkResult *)&majorAxis,
    (hkArray<hkVector4f,hkContainerHeapAllocator> *)pa,
    (hkaiNavMeshSimplificationUtils::Segment *)(pb->m_quad.m128_u64[0] + 48i64 * skipIndex),
    segments,
    (int)p2,
    &va,
    (hkVector4f *)&vb.m256i_u64[1],
    (hkVector4f *)&vb,
    (hkVector4f *)&vb.m256i_u64[2],
    &testSegs);
  v53 = (int)majorAxis;
  if ( !(_DWORD)majorAxis )
  {
    v166 = v37;
    v167 = v40;
    v168 = v51;
    p_testSegs = &testSegs;
    v165 = (int)p2;
    v169 = v52;
    v171 = 0;
    hkcdDynamicAabbTree::queryAabb(v160, &aabb, &collector);
    v53 = v171;
  }
  m_data = testSegs.m_data;
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
    v63 = _mm_sub_ps(v148, v149);
    v153 = v63;
    v64 = _mm_shuffle_ps(v63, v63, 201);
    vb.m256i_i64[3] = v64.m128_i64[1];
    v65 = _mm_andnot_ps(
            _mm_cmple_ps(v61, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v62, v61), v62)),
              _mm_mul_ps(v62, *(__m128 *)_xmm)));
    v66 = _mm_mul_ps(v41, v65);
    v67 = _mm_mul_ps(v65, v61);
    v155 = v66;
    v68 = _mm_cmple_ps(v67, v19);
    v156 = v67;
    v69 = _mm_andnot_ps(v68, _mm_mul_ps(v19, (__m128)xmmword_141A711B0));
    v70 = _mm_and_ps(_mm_mul_ps(v67, (__m128)xmmword_141A711B0), v68);
    v71 = 0i64;
    v72 = _mm_or_ps(v69, v70);
    vb.m256i_i64[0] = v72.m128_u64[0];
    v152 = _mm_shuffle_ps((__m128)v172, (__m128)v172, 0);
    v158 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
    v147 = _mm_sub_ps(v147, v148);
    *(__m128 *)&vb.m256i_u64[1] = _mm_shuffle_ps(v147, v147, 201);
    while ( 1 )
    {
      ++v58;
      v73 = 0i64;
      v74 = _mm_add_ps(_mm_mul_ps(v72, v66), v154);
      va.m_quad = v74;
      v75 = _mm_add_ps(v74, v157);
      v76 = _mm_sub_ps(_mm_sub_ps(v74, v157), v74);
      v77 = _mm_shuffle_ps(v76, v76, 201);
      v78 = _mm_sub_ps(_mm_mul_ps(v76, v64), _mm_mul_ps(v63, v77));
      v79 = _mm_shuffle_ps(v78, v78, 201);
      v80 = _mm_shuffle_ps(v79, v79, 170);
      v81 = _mm_rcp_ps(v80);
      v82 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeq_ps(v80, (__m128)0i64), v71);
      v83 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v81, v80));
      v84 = _mm_sub_ps(v74, v149);
      v85 = _mm_mul_ps(v83, v81);
      v86 = _mm_shuffle_ps(v84, v84, 201);
      v87 = _mm_sub_ps(_mm_mul_ps(v63, v86), _mm_mul_ps(v84, *(__m128 *)&vb.m256i_u64[2]));
      v88 = _mm_shuffle_ps(v87, v87, 201);
      v89 = _mm_sub_ps(_mm_mul_ps(v76, v86), _mm_mul_ps(v84, v77));
      v90 = _mm_shuffle_ps(v89, v89, 201);
      v91 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 170), v85);
      v92 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 170), v85);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(_mm_cmple_ps((__m128)0i64, v92), _mm_cmple_ps(v92, query.m_quad)),
                  _mm_and_ps(_mm_cmple_ps((__m128)0i64, v91), _mm_cmple_ps(v91, query.m_quad))),
                v82)) & 1) != 0 )
      {
        v93 = 1;
        v73 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), v76), v74);
      }
      else
      {
        v93 = 0;
      }
      v94 = _mm_shuffle_ps(v76, v76, 201);
      v95 = _mm_sub_ps(v74, v148);
      v96 = _mm_sub_ps(_mm_mul_ps(v76, *(__m128 *)&vb.m256i_u64[1]), _mm_mul_ps(v147, v94));
      v97 = _mm_shuffle_ps(v96, v96, 201);
      v98 = _mm_shuffle_ps(v97, v97, 170);
      v99 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeq_ps(v98, (__m128)0i64), (__m128i)0i64);
      v100 = _mm_rcp_ps(v98);
      v101 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v98, v100));
      v102 = _mm_shuffle_ps(v95, v95, 201);
      v103 = _mm_mul_ps(v101, v100);
      v104 = _mm_sub_ps(_mm_mul_ps(v147, v102), _mm_mul_ps(v95, *(__m128 *)&vb.m256i_u64[1]));
      v105 = _mm_shuffle_ps(v104, v104, 201);
      v106 = _mm_sub_ps(_mm_mul_ps(v76, v102), _mm_mul_ps(v95, v94));
      v107 = _mm_shuffle_ps(v106, v106, 201);
      v108 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 170), v103);
      v109 = _mm_mul_ps(_mm_shuffle_ps(v107, v107, 170), v103);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(_mm_cmple_ps((__m128)0i64, v109), _mm_cmple_ps(v109, query.m_quad)),
                  _mm_and_ps(_mm_cmple_ps((__m128)0i64, v108), _mm_cmple_ps(v108, query.m_quad))),
                v99)) & 1) != 0 )
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
          v113 = m_data;
          m_size = (unsigned int)testSegs.m_size;
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
            v124 = (__m128)_mm_cmpeq_epi32((__m128i)_mm_cmpeq_ps(v123, (__m128)0i64), (__m128i)0i64);
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
            if ( (_mm_movemask_ps(
                    _mm_and_ps(
                      _mm_and_ps(
                        _mm_and_ps(_mm_cmple_ps((__m128)0i64, v134), _mm_cmple_ps(v134, query.m_quad)),
                        _mm_and_ps(_mm_cmple_ps((__m128)0i64, v133), _mm_cmple_ps(v133, query.m_quad))),
                      v124)) & 1) != 0 )
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
                         _mm_cmple_ps(v137, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v137, v138), v138)),
                             _mm_mul_ps(v138, *(__m128 *)_xmm)),
                           v137)));
            }
            ++v113;
            --m_size;
          }
          while ( m_size );
          v74 = va.m_quad;
          v72 = *(__m128 *)vb.m256i_i8;
          v46 = (__m128)_xmm;
        }
        if ( v111.m128_f32[0] < v152.m128_f32[0]
          || (v139 = _mm_sub_ps(v74, v73),
              v140 = _mm_mul_ps(v139, v139),
              v141 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                       _mm_shuffle_ps(v140, v140, 170)),
              v142 = _mm_rsqrt_ps(v141),
              (float)(v111.m128_f32[0]
                    - _mm_andnot_ps(
                        _mm_cmple_ps(v141, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps(v46, _mm_mul_ps(_mm_mul_ps(v141, v142), v142)),
                            _mm_mul_ps(v142, *(__m128 *)_xmm)),
                          v141)).m128_f32[0]) > v158.m128_f32[0]) )
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
        v19 = v150;
      }
      v72 = _mm_add_ps(v72, v19);
      *(__m128 *)vb.m256i_i8 = v72;
      if ( (float)((float)v57 * v19.m128_f32[0]) >= v144 )
        break;
      v63 = v153;
      v64 = *(__m128 *)&vb.m256i_u64[2];
      v71 = 0i64;
      v66 = v155;
      if ( v72.m128_f32[0] >= v156.m128_f32[0] )
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
      &hkContainerTempAllocator::s_alloc,
      m_data,
      16 * testSegs.m_capacityAndFlags);
  return v55;
}

// File Line: 2198
// RVA: 0xB55160
hkSimdFloat32 *__fastcall `anonymous namespace::getProjectedDistanceErrorSquared(
        hkSimdFloat32 *result,
        hkVector4f *a,
        hkVector4f *b,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<int,hkContainerHeapAllocator> *indices,
        int majorAxis)
{
  int v6; // edi
  __int64 v11; // rsi
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f out; // [rsp+40h] [rbp-38h] BYREF

  v6 = 0;
  result->m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  if ( indices->m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      `anonymous namespace::getClosestPointOnLine(
        &resulta,
        &vertices->m_data[indices->m_data[v11]],
        a,
        b,
        majorAxis,
        &out);
      ++v6;
      ++v11;
      result->m_real = _mm_max_ps(result->m_real, resulta.m_real);
    }
    while ( v6 < indices->m_size );
  }
  return result;
}

// File Line: 2234
// RVA: 0xB55230
hkResult *__fastcall `anonymous namespace::simplifyInternalOrConvexBoundary(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        __m128 *verticesInOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkArrayBase<int> *segmentToOppositeMap,
        int segmentIndex,
        int majorAxisA,
        unsigned int majorAxisB,
        hkcdDynamicAabbTree *tree,
        hkPointerMultiMap<int,int> *parToSegIdxMap,
        hkBitField *unremovableVertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v12; // r15
  hkResult *v13; // r10
  __int64 v14; // r11
  int m_size; // edx
  int *v16; // r12
  int v17; // edi
  int v18; // ebx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // r8
  int v21; // edx
  char *v22; // rcx
  unsigned int m_slotID; // ecx
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // r8d
  int v28; // r10d
  __int64 v29; // r9
  int v30; // eax
  char *v31; // rdi
  int v32; // ebx
  hkResult *v33; // rsi
  unsigned int v34; // ecx
  bool v35; // zf
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  int *v39; // rdx
  __int64 v40; // rax
  int v41; // ecx
  hkaiNavMeshSimplificationUtils::Segment *m_data; // rax
  __int64 v43; // rdi
  int v44; // eax
  char *v45; // rdi
  int v46; // ebx
  unsigned int v47; // ecx
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // r8d
  int m_capacityAndFlags; // r8d
  __m128 m_real; // xmm11
  __m128 v53; // xmm12
  int v54; // ebx
  int v55; // r8d
  __int64 v56; // rdx
  int v57; // r9d
  int v58; // r8d
  int v59; // eax
  char *v60; // rdi
  signed int v61; // ebx
  hkLifoAllocator *v62; // rax
  int v63; // r8d
  float v64; // xmm8_4
  float v65; // xmm10_4
  int v66; // ebx
  int v67; // esi
  int v68; // r14d
  __int64 v69; // rcx
  __int64 v70; // r8
  int *v71; // rdx
  int v72; // eax
  __int64 v73; // r12
  hkVector4f *v74; // rax
  hkVector4f *v75; // r15
  hkVector4f *v76; // r12
  hkVector4f *v77; // r13
  __int64 v78; // r9
  float ProjectedTriangleArea; // xmm0_4
  float TriangleArea; // xmm6_4
  int v81; // r9d
  hkgpCgo::ClusterData *v82; // rbx
  unsigned __int64 v83; // rdi
  __int64 v84; // rbx
  unsigned __int64 v85; // rdi
  int v86; // ebx
  int v87; // edi
  int v88; // r9d
  unsigned __int64 v89; // r8
  __int64 v90; // rdx
  __int64 v91; // rax
  int *v92; // rcx
  __int64 v93; // rdx
  __int64 v94; // r15
  __int64 v95; // r13
  __int64 v96; // rsi
  int v97; // eax
  __int64 v98; // r12
  hkVector4f *v99; // rdi
  hkVector4f *v100; // r14
  hkVector4f *v101; // rdx
  __m128 v102; // xmm2
  __m128 v103; // xmm1
  __m128 v104; // xmm3
  __m128 v105; // xmm0
  __m128 v106; // xmm3
  bool v107; // al
  __m128 v108; // xmm0
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __int128 m_quad; // xmm1
  float v112; // xmm6_4
  __int128 v113; // xmm0
  hkaiNavMeshSimplificationUtils::Settings *v114; // rbx
  _DWORD *v115; // r9
  int v116; // ebx
  int v117; // edi
  int v118; // r8d
  __int64 v119; // rdx
  __int64 v120; // rcx
  int v121; // r10d
  int v122; // edx
  __int64 v123; // rdx
  int v124; // eax
  _DWORD *v125; // rsi
  int v126; // eax
  __int64 v127; // rcx
  int v128; // eax
  int v129; // eax
  __int64 v130; // rdx
  int v131; // eax
  int v132; // ebx
  int v133; // r9d
  int v134; // eax
  int v135; // eax
  int v136; // r8d
  int v137; // eax
  int v138; // eax
  int v139; // r9d
  __int64 v140; // r8
  int v141; // ecx
  float v142; // xmm2_4
  float v143; // xmm4_4
  float v144; // xmm3_4
  float v145; // xmm5_4
  __int64 v146; // rdx
  float v147; // xmm1_4
  hkVector4f *v148; // r13
  char v149; // al
  _DWORD *v150; // rbx
  int v151; // edx
  int v152; // edi
  __int64 v153; // r9
  int v154; // ecx
  __int64 v155; // rax
  int v156; // r14d
  int v157; // ecx
  char *v158; // rax
  int v159; // ecx
  _DWORD *v160; // rax
  int v161; // edi
  __int64 v162; // rsi
  __int64 v163; // rdi
  __int64 v164; // rdi
  hkVector4f *v165; // rdi
  hkSimdFloat32 *ProjectedDistanceErrorSquared; // rax
  __int64 v167; // rbx
  __int64 v168; // r10
  int v169; // edx
  __int64 v170; // r11
  hkaiNavMeshSimplificationUtils::Segment *v171; // rcx
  int v172; // eax
  int *v173; // rcx
  int v174; // eax
  int v175; // eax
  __int64 v176; // rdx
  int v177; // eax
  int v178; // ebx
  int v179; // r9d
  int v180; // eax
  int v181; // eax
  int v182; // eax
  __int64 v183; // rcx
  int v184; // edx
  __int64 v185; // rdx
  int v186; // eax
  __int64 v187; // r11
  hkaiNavMeshSimplificationUtils::Segment *v188; // rcx
  __int64 v189; // rax
  int v190; // eax
  int v191; // eax
  char *v192; // rdi
  signed int v193; // ebx
  hkLifoAllocator *v194; // rax
  int v195; // r8d
  int v196; // r8d
  int v197; // eax
  char *v198; // rdi
  signed int v199; // ebx
  hkLifoAllocator *v200; // rax
  int v201; // r8d
  hkcdDynamicAabbTree *v202; // [rsp+20h] [rbp-E0h]
  int area1InOut; // [rsp+28h] [rbp-D8h]
  int area2InOut; // [rsp+30h] [rbp-D0h]
  unsigned int area1Out; // [rsp+38h] [rbp-C8h]
  int area1Outa; // [rsp+38h] [rbp-C8h]
  hkRotationf *area2Out; // [rsp+40h] [rbp-C0h]
  hkRotationf *resOut; // [rsp+48h] [rbp-B8h]
  hkcdDynamicAabbTree *v209; // [rsp+50h] [rbp-B0h]
  int *majorAxis; // [rsp+58h] [rbp-A8h]
  char v211; // [rsp+80h] [rbp-80h]
  hkSimdFloat32 v212; // [rsp+90h] [rbp-70h] BYREF
  hkgpCgo::ClusterData *pArr; // [rsp+A0h] [rbp-60h] BYREF
  int v214; // [rsp+A8h] [rbp-58h]
  int v215; // [rsp+ACh] [rbp-54h]
  hkArray<int,hkContainerHeapAllocator> indices; // [rsp+B0h] [rbp-50h] BYREF
  char *array; // [rsp+C0h] [rbp-40h] BYREF
  int v218; // [rsp+C8h] [rbp-38h]
  int v219; // [rsp+CCh] [rbp-34h]
  hkArrayBase<hkVector4f> points; // [rsp+D0h] [rbp-30h] BYREF
  void *p; // [rsp+E0h] [rbp-20h]
  int v222; // [rsp+E8h] [rbp-18h]
  hkSimdFloat32 v223; // [rsp+F0h] [rbp-10h] BYREF
  bool v224; // [rsp+100h] [rbp+0h]
  bool v225; // [rsp+101h] [rbp+1h]
  int v226; // [rsp+104h] [rbp+4h]
  hkResult v227; // [rsp+108h] [rbp+8h] BYREF
  hkArrayBase<hkVector4f> v228; // [rsp+110h] [rbp+10h] BYREF
  __int128 v229[3]; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f *b; // [rsp+150h] [rbp+50h]
  void *v231; // [rsp+158h] [rbp+58h]
  __int64 v232; // [rsp+160h] [rbp+60h]
  hkResult resulta; // [rsp+168h] [rbp+68h] BYREF
  hkResult v234; // [rsp+16Ch] [rbp+6Ch] BYREF
  hkResult v235; // [rsp+170h] [rbp+70h] BYREF
  hkResult v236; // [rsp+174h] [rbp+74h] BYREF
  hkResult v237; // [rsp+178h] [rbp+78h] BYREF
  hkResult v238; // [rsp+17Ch] [rbp+7Ch] BYREF
  int v239; // [rsp+180h] [rbp+80h]
  hkResult v240; // [rsp+184h] [rbp+84h] BYREF
  __int64 v241; // [rsp+188h] [rbp+88h]
  __int64 v242; // [rsp+190h] [rbp+90h]
  int localSettingsIndex; // [rsp+198h] [rbp+98h]
  hkResult v244; // [rsp+19Ch] [rbp+9Ch] BYREF
  hkResult v245; // [rsp+1A0h] [rbp+A0h] BYREF
  hkaiNavMeshSimplificationUtils::Settings *v246; // [rsp+1A8h] [rbp+A8h]
  hkVector4f *a; // [rsp+1B0h] [rbp+B0h]
  hkaiNavMeshSimplificationUtils::Settings *SimplificationSettings; // [rsp+1B8h] [rbp+B8h]
  hkSimdFloat32 v249; // [rsp+1C0h] [rbp+C0h] BYREF
  hkSimdFloat32 v250; // [rsp+1D0h] [rbp+D0h] BYREF
  hkSimdFloat32 v251; // [rsp+1E0h] [rbp+E0h] BYREF
  hkRotationf projectionMatrix; // [rsp+1F0h] [rbp+F0h] BYREF
  hkSimdFloat32 v253; // [rsp+220h] [rbp+120h] BYREF
  hkSimdFloat32 v254; // [rsp+230h] [rbp+130h] BYREF
  hkSimdFloat32 v255; // [rsp+240h] [rbp+140h] BYREF
  hkRotationf projB; // [rsp+250h] [rbp+150h] BYREF

  v12 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut;
  if ( majorAxisA == majorAxisB || (v211 = 1, majorAxisB == -1) )
    v211 = 0;
  anonymous_namespace_::getProjectionMatrix(majorAxisA, &projectionMatrix);
  anonymous_namespace_::getProjectionMatrix(majorAxisB, &projB);
  v14 = 48i64 * segmentIndex;
  m_size = 0;
  v16 = (int *)((char *)&segmentsInOut->m_data->m_indices + v14);
  v241 = v14;
  v17 = v16[2];
  v231 = v16;
  points.m_data = 0i64;
  v18 = v17;
  points.m_size = 0;
  points.m_capacityAndFlags = 0x80000000;
  v222 = v17;
  if ( v17 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v21 = (16 * v17 + 127) & 0xFFFFFF80;
    v22 = (char *)m_cur + v21;
    if ( v21 > Value->m_slabSize || v22 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v21);
    else
      Value->m_cur = v22;
    v18 = v222;
    m_size = points.m_size;
    v13 = result;
    v14 = v241;
    points.m_data = m_cur;
  }
  else
  {
    m_cur = 0i64;
    points.m_data = 0i64;
  }
  p = m_cur;
  points.m_capacityAndFlags = v17 | 0x80000000;
  if ( !m_cur )
  {
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    v13->m_enum = HK_FAILURE;
    points.m_size = 0;
    v24 = (16 * v18 + 127) & 0xFFFFFF80;
    v25 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v26 = (v24 + 15) & 0xFFFFFFF0;
    if ( v24 <= v25->m_slabSize && (void *)v26 == v25->m_cur && v25->m_firstNonLifoEnd )
      v25->m_cur = 0i64;
    else
      hkLifoAllocator::slowBlockFree(v25, 0i64, v26);
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    return result;
  }
  v28 = 0;
  if ( v16[2] > 0 )
  {
    v29 = 0i64;
    while ( 1 )
    {
      ++v28;
      v29 += 4i64;
      m_cur[m_size] = v12->m_data[*(int *)(*(_QWORD *)v16 + v29 - 4)];
      m_size = ++points.m_size;
      if ( v28 >= v16[2] )
        break;
      m_cur = points.m_data;
    }
  }
  localSettingsIndex = *(int *)((char *)&segmentsInOut->m_data->m_materialSettingsIndex + v14);
  SimplificationSettings = hkaiNavMeshGenerationSettings::getSimplificationSettings(
                             settings,
                             &points,
                             localSettingsIndex);
  if ( SimplificationSettings->m_maxLoopShrinkFraction >= 1.0 )
  {
    v30 = points.m_size;
    v31 = (char *)p;
    v32 = v222;
    v33 = result;
    v34 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v35 = p == points.m_data;
    result->m_enum = HK_SUCCESS;
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
        &hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    return v33;
  }
  v39 = *(int **)v16;
  v40 = v16[2];
  v223.m_real = 0i64;
  v212.m_real = 0i64;
  v41 = v39[v40 - 1];
  m_data = segmentsInOut->m_data;
  v225 = *v39 == v41;
  v224 = *(int *)((char *)&m_data->m_partitionIdB + v241) == -1;
  v43 = (int)`anonymous namespace::computePartialSignedPartitionAreas(
               v12,
               segmentsInOut,
               segmentToOppositeMap,
               parToSegIdxMap,
               segmentIndex,
               majorAxisA,
               majorAxisB,
               &v223,
               &v212,
               &v227);
  if ( v227.m_enum )
  {
    v44 = points.m_size;
    v45 = (char *)p;
    v46 = v222;
    v35 = p == points.m_data;
    v33 = result;
    v47 = hkMemoryRouter::s_memoryRouter.m_slotID;
    result->m_enum = HK_FAILURE;
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
    m_capacityAndFlags = points.m_capacityAndFlags;
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      goto LABEL_356;
    return v33;
  }
  m_real = v223.m_real;
  v53 = v212.m_real;
  `anonymous namespace::computeFullSignedPartitionAreas(
    v12,
    segmentsInOut,
    segmentIndex,
    majorAxisA,
    majorAxisB,
    &v223,
    &v212);
  array = 0i64;
  v218 = 0;
  v219 = 0x80000000;
  v54 = v16[2];
  if ( v54 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v16[2], 4);
    if ( resulta.m_enum )
    {
      v33 = result;
      result->m_enum = HK_FAILURE;
      goto LABEL_56;
    }
  }
  v218 = v54;
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
  indices.m_capacityAndFlags = 0x80000000;
  v57 = v16[2];
  if ( v57 <= 0 )
  {
    v236.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v236, &hkContainerHeapAllocator::s_alloc, &indices, v57, 4);
    if ( v236.m_enum )
    {
      v33 = result;
      v58 = indices.m_capacityAndFlags;
      indices.m_size = 0;
      result->m_enum = HK_FAILURE;
      if ( v58 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, indices.m_data, 4 * v58);
      indices.m_data = 0i64;
      indices.m_capacityAndFlags = 0x80000000;
LABEL_56:
      v218 = 0;
      if ( v219 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v219);
      v59 = points.m_size;
      v60 = (char *)p;
      array = 0i64;
      if ( p == points.m_data )
        v59 = 0;
      v219 = 0x80000000;
      points.m_size = v59;
      v61 = (16 * v222 + 127) & 0xFFFFFF80;
      v62 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v63 = (v61 + 15) & 0xFFFFFFF0;
      if ( v61 > v62->m_slabSize || &v60[v63] != v62->m_cur || v62->m_firstNonLifoEnd == v60 )
        hkLifoAllocator::slowBlockFree(v62, v60, v63);
      else
        v62->m_cur = v60;
      m_capacityAndFlags = points.m_capacityAndFlags;
      points.m_size = 0;
      if ( points.m_capacityAndFlags >= 0 )
        goto LABEL_356;
      return v33;
    }
  }
  v64 = v212.m_real.m128_f32[0];
  v242 = v43;
  v65 = v223.m_real.m128_f32[0];
  while ( 2 )
  {
    if ( v225 && v16[2] < 4 )
      goto LABEL_340;
    v66 = v16[2] - (2 - v225);
    v226 = v66;
    if ( v66 < 1 )
      goto LABEL_340;
    v212.m_real.m128_u64[0] = 0i64;
    v212.m_real.m128_u64[1] = 0x8000000000000000ui64;
    pArr = 0i64;
    v214 = 0;
    v215 = 0x80000000;
    hkArrayUtil::_reserve(&v234, &hkContainerTempAllocator::s_alloc, &v212, v66, 8);
    if ( v234.m_enum )
    {
      v33 = result;
      v190 = v215;
      v214 = 0;
      result->m_enum = HK_FAILURE;
      if ( v190 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          12 * (v190 & 0x3FFFFFFF));
      pArr = 0i64;
      v215 = 0x80000000;
      v212.m_real.m128_i32[2] = 0;
      if ( v212.m_real.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)v212.m_real.m128_u64[0],
          8 * v212.m_real.m128_i32[3]);
      v212.m_real.m128_u64[0] = 0i64;
      v212.m_real.m128_i32[3] = 0x80000000;
      indices.m_size = 0;
      if ( indices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          indices.m_data,
          4 * indices.m_capacityAndFlags);
      indices.m_data = 0i64;
      indices.m_capacityAndFlags = 0x80000000;
      v218 = 0;
      if ( v219 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v219);
      v191 = points.m_size;
      v192 = (char *)p;
      array = 0i64;
      if ( p == points.m_data )
        v191 = 0;
      v219 = 0x80000000;
      points.m_size = v191;
      v193 = (16 * v222 + 127) & 0xFFFFFF80;
      v194 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v195 = (v193 + 15) & 0xFFFFFFF0;
      if ( v193 > v194->m_slabSize || &v192[v195] != v194->m_cur || v194->m_firstNonLifoEnd == v192 )
      {
        hkLifoAllocator::slowBlockFree(v194, v192, v195);
        points.m_size = 0;
      }
      else
      {
        v194->m_cur = v192;
        points.m_size = 0;
      }
      goto LABEL_355;
    }
    v67 = v214;
    v68 = 1;
    v69 = 2i64;
    v70 = 4i64;
    b = (hkVector4f *)2;
    v232 = 4i64;
    while ( 1 )
    {
      v71 = *(int **)v16;
      v72 = v16[2];
      v73 = *(int *)(v70 + *(_QWORD *)v16);
      v35 = v68 == v72 - 1;
      v74 = v12->m_data;
      if ( v35 )
        v69 = 1i64;
      v75 = &v74[*(int *)((char *)v71 + v70 - 4)];
      v76 = &v74[v73];
      v77 = &v74[v71[v69]];
      ProjectedTriangleArea = `anonymous namespace::getProjectedTriangleArea(v75, v76, v77, majorAxisA);
      TriangleArea = ProjectedTriangleArea;
      if ( v211 || ProjectedTriangleArea >= 0.001 )
      {
        if ( v212.m_real.m128_i32[2] == (v212.m_real.m128_i32[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &v212, 8);
        v84 = v212.m_real.m128_i32[2]++;
        v85 = v212.m_real.m128_u64[0];
        *(_DWORD *)(v212.m_real.m128_u64[0] + 8 * v84 + 4) = v68;
        if ( v211 )
          TriangleArea = `anonymous namespace::getTriangleArea(v75, v76, v77);
        *(float *)(v85 + 8 * v84) = TriangleArea;
      }
      else
      {
        v81 = v67 + 1;
        if ( (v215 & 0x3FFFFFFF) >= v67 + 1 )
        {
          v235.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v81 < 2 * (v215 & 0x3FFFFFFF) )
            v81 = 2 * (v215 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v235, &hkContainerTempAllocator::s_alloc, &pArr, v81, 12);
          if ( v235.m_enum )
          {
            v33 = result;
            result->m_enum = HK_FAILURE;
LABEL_313:
            v214 = 0;
            if ( v215 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                pArr,
                12 * (v215 & 0x3FFFFFFF));
            pArr = 0i64;
            v215 = 0x80000000;
            v212.m_real.m128_i32[2] = 0;
            if ( v212.m_real.m128_i32[3] >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                (void *)v212.m_real.m128_u64[0],
                8 * v212.m_real.m128_i32[3]);
            indices.m_size = 0;
            v212.m_real.m128_i32[3] = 0x80000000;
            v212.m_real.m128_u64[0] = 0i64;
            if ( indices.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                indices.m_data,
                4 * indices.m_capacityAndFlags);
            indices.m_data = 0i64;
            indices.m_capacityAndFlags = 0x80000000;
            v218 = 0;
            if ( v219 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v219);
            array = 0i64;
            goto LABEL_346;
          }
          v67 = v214;
        }
        if ( v67 == (v215 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &pArr, 12);
          v67 = v214;
        }
        v82 = pArr;
        v83 = v67;
        v214 = v67 + 1;
        LODWORD(pArr[v83].m_errorRange[1]) = v68;
        *(float *)&v82[v83].m_numVertices = ProjectedTriangleArea;
        v82[v83].m_errorRange[0] = `anonymous namespace::getTriangleArea(v75, v76, v77);
      }
      v67 = v214;
      v16 = (int *)v231;
      v70 = v232 + 4;
      v69 = (__int64)b->m_quad.m128_i64 + 1;
      ++v68;
      v232 += 4i64;
      b = (hkVector4f *)((char *)b + 1);
      if ( v68 > v226 )
        break;
      v12 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut;
    }
    if ( v212.m_real.m128_i32[2] > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
        (DuplicateVertexRef *)v212.m_real.m128_u64[0],
        0,
        v212.m_real.m128_i32[2] - 1,
        0);
      v67 = v214;
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
        v67 = v214;
      }
      v86 = v212.m_real.m128_i32[2];
      v87 = v67 + v212.m_real.m128_i32[2];
      if ( v67 + v212.m_real.m128_i32[2] > (v212.m_real.m128_i32[3] & 0x3FFFFFFF) )
      {
        v88 = v67 + v212.m_real.m128_i32[2];
        if ( v87 < 2 * (v212.m_real.m128_i32[3] & 0x3FFFFFFF) )
          v88 = 2 * (v212.m_real.m128_i32[3] & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v244, &hkContainerTempAllocator::s_alloc, &v212, v88, 8);
      }
      hkMemUtil::memMove((void *)(v212.m_real.m128_u64[0] + 8i64 * v67), (const void *)v212.m_real.m128_u64[0], 8 * v86);
      v212.m_real.m128_i32[2] = v87;
      v78 = 0i64;
      if ( v214 > 0 )
      {
        v89 = v212.m_real.m128_u64[0];
        v90 = 0i64;
        do
        {
          v78 = (unsigned int)(v78 + 1);
          ++v90;
          v89 += 8i64;
          *(float *)(v89 - 4) = pArr[v90 - 1].m_errorRange[1];
          *(_DWORD *)(v89 - 8) = pArr[v90 - 1].m_numVertices;
        }
        while ( (int)v78 < v214 );
      }
    }
    v91 = 0i64;
    v239 = 0;
    v232 = 0i64;
    if ( v212.m_real.m128_i32[2] <= 0 )
    {
LABEL_336:
      v214 = 0;
      if ( v215 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkgpCgo::ClusterData *, _QWORD, __int64, hkcdDynamicAabbTree *, int, int, unsigned int, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          12 * (v215 & 0x3FFFFFFFu),
          v78,
          v202,
          area1InOut,
          area2InOut,
          area1Out,
          area2Out,
          resOut);
      pArr = 0i64;
      v215 = 0x80000000;
      v212.m_real.m128_i32[2] = 0;
      if ( v212.m_real.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v212.m_real.m128_u64[0],
          (unsigned int)(8 * v212.m_real.m128_i32[3]),
          v78);
LABEL_340:
      v33 = result;
      result->m_enum = HK_SUCCESS;
      goto LABEL_341;
    }
    while ( 1 )
    {
      v92 = *(int **)v16;
      v93 = *(int *)(v212.m_real.m128_u64[0] + 8 * v91 + 4);
      v94 = *(int *)(*(_QWORD *)v16 + 4 * v93 - 4);
      v95 = *(int *)(*(_QWORD *)v16 + 4 * v93);
      v35 = (_DWORD)v93 == v16[2] - 1;
      v226 = *(_DWORD *)(v212.m_real.m128_u64[0] + 8 * v91 + 4);
      v96 = v93;
      v97 = 1;
      if ( !v35 )
        v97 = v93 + 1;
      v78 = v224;
      v98 = v92[v97];
      if ( (!v224 || (_DWORD)v94 != (_DWORD)v98)
        && ((unremovableVertices->m_storage.m_words.m_data[v95 >> 5] >> (v95 & 0x1F)) & 1) == 0 )
      {
        v99 = (hkVector4f *)(verticesInOut->m128_u64[0] + 16 * v94);
        v100 = (hkVector4f *)(verticesInOut->m128_u64[0] + 16 * v95);
        v101 = (hkVector4f *)(verticesInOut->m128_u64[0] + 16 * v98);
        a = v99;
        b = v101;
        if ( !v224 )
          goto LABEL_160;
        v102 = _mm_sub_ps(v101->m_quad, v100->m_quad);
        v103 = _mm_sub_ps(v101->m_quad, v99->m_quad);
        v104 = v103;
        if ( majorAxisA )
        {
          if ( majorAxisA == 1 )
          {
            v104 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 216), (__m128)xmmword_141A71320);
          }
          else if ( majorAxisA != 2 )
          {
            if ( majorAxisA == 3 )
            {
              v104 = _mm_shuffle_ps(v103, v103, 230);
            }
            else if ( majorAxisA == 4 )
            {
              v104 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 210), (__m128)xmmword_141A71320);
            }
            else
            {
              v104 = _mm_shuffle_ps(v103, v103, 225);
            }
          }
        }
        else
        {
          v104 = _mm_shuffle_ps(v103, v103, 233);
        }
        v105 = v102;
        if ( majorAxisA )
        {
          if ( majorAxisA == 1 )
          {
            v105 = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 216), (__m128)xmmword_141A71320);
          }
          else if ( majorAxisA != 2 )
          {
            if ( majorAxisA == 3 )
            {
              v105 = _mm_shuffle_ps(v102, v102, 230);
            }
            else if ( majorAxisA == 4 )
            {
              v105 = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 210), (__m128)xmmword_141A71320);
            }
            else
            {
              v105 = _mm_shuffle_ps(v102, v102, 225);
            }
          }
        }
        else
        {
          v105 = _mm_shuffle_ps(v102, v102, 233);
        }
        v106 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 225), v105);
        v106.m128_f32[0] = _mm_shuffle_ps(v106, v106, 0).m128_f32[0] - _mm_shuffle_ps(v106, v106, 85).m128_f32[0];
        v107 = v106.m128_f32[0] <= 0.0;
        if ( v106.m128_f32[0] <= 0.0 )
          break;
      }
LABEL_283:
      v91 = v232 + 1;
      ++v239;
      ++v232;
      if ( v239 >= v212.m_real.m128_i32[2] )
        goto LABEL_336;
      v16 = (int *)v231;
    }
    v78 = majorAxisB;
    if ( majorAxisA == majorAxisB || majorAxisB == -1 )
      goto LABEL_159;
    switch ( majorAxisB )
    {
      case 0u:
        v108 = _mm_shuffle_ps(v103, v103, 233);
        goto LABEL_146;
      case 1u:
        v103 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 216), (__m128)xmmword_141A71320);
        break;
      case 2u:
        break;
      case 3u:
        v108 = _mm_shuffle_ps(v103, v103, 230);
LABEL_146:
        v103 = v108;
        break;
      case 4u:
        v103 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 210), (__m128)xmmword_141A71320);
        break;
      default:
        v103 = _mm_shuffle_ps(v103, v103, 225);
        break;
    }
    if ( !majorAxisB )
    {
      v109 = _mm_shuffle_ps(v102, v102, 233);
LABEL_157:
      v102 = v109;
      goto LABEL_158;
    }
    if ( majorAxisB == 1 )
    {
      v102 = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 216), (__m128)xmmword_141A71320);
    }
    else if ( majorAxisB != 2 )
    {
      if ( majorAxisB != 3 )
      {
        if ( majorAxisB == 4 )
          v102 = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 210), (__m128)xmmword_141A71320);
        else
          v102 = _mm_shuffle_ps(v102, v102, 225);
        goto LABEL_158;
      }
      v109 = _mm_shuffle_ps(v102, v102, 230);
      goto LABEL_157;
    }
LABEL_158:
    v110 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 225), v102);
    v107 = (float)(_mm_shuffle_ps(v110, v110, 0).m128_f32[0] - _mm_shuffle_ps(v110, v110, 85).m128_f32[0]) <= 0.0;
LABEL_159:
    if ( !v107 )
      goto LABEL_283;
LABEL_160:
    m_quad = (__int128)v100->m_quad;
    v112 = *(float *)(v212.m_real.m128_u64[0] + 8 * v232);
    v229[0] = (__int128)v99->m_quad;
    v228.m_size = 3;
    v228.m_capacityAndFlags = -2147483645;
    v113 = (__int128)v101->m_quad;
    v229[1] = m_quad;
    v228.m_data = (hkVector4f *)v229;
    v229[2] = v113;
    v114 = hkaiNavMeshGenerationSettings::getSimplificationSettings(settings, &v228, localSettingsIndex);
    v246 = v114;
    if ( v112 > v114->m_maxBorderSimplifyArea
      || COERCE_FLOAT(*`anonymous namespace::getHeightErrorSquared(&v251, v100, v99, b, majorAxisA)) > (float)(v114->m_maxBorderHeightError * v114->m_maxBorderHeightError)
      || v211
      && COERCE_FLOAT(*`anonymous namespace::getHeightErrorSquared(&v255, v100, v99, b, majorAxisB)) > (float)(v114->m_maxBorderHeightError * v114->m_maxBorderHeightError) )
    {
      goto LABEL_161;
    }
    resOut = &projB;
    area2Out = &projectionMatrix;
    area1Out = majorAxisB;
    area2InOut = majorAxisA;
    area1InOut = segmentIndex;
    v202 = tree;
    if ( `anonymous namespace::doesLineSegmentIntersectPartition(v94, v98, verticesInOut, segmentsInOut) )
      goto LABEL_161;
    if ( v242 )
    {
      v115 = v231;
      v116 = 0x80000000;
      v117 = *((_DWORD *)v231 + 2);
      v223.m_real.m128_u64[0] = 0i64;
      v223.m_real.m128_u64[1] = 0x8000000000000000ui64;
      if ( v117 <= 0 )
      {
        v238.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v238, &hkContainerTempAllocator::s_alloc, &v223, v117, 4);
        if ( v238.m_enum )
        {
          v33 = result;
          v196 = v223.m_real.m128_i32[3];
          result->m_enum = HK_FAILURE;
          v223.m_real.m128_i32[2] = 0;
          if ( v196 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              (void *)v223.m_real.m128_u64[0],
              4 * v196);
          v223.m_real.m128_u64[0] = 0i64;
          v223.m_real.m128_i32[3] = 0x80000000;
          v228.m_size = 0;
          if ( v228.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v228.m_data,
              16 * v228.m_capacityAndFlags);
          v228.m_data = 0i64;
          v228.m_capacityAndFlags = 0x80000000;
          v214 = 0;
          if ( v215 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              pArr,
              12 * (v215 & 0x3FFFFFFF));
          pArr = 0i64;
          v215 = 0x80000000;
          v212.m_real.m128_i32[2] = 0;
          if ( v212.m_real.m128_i32[3] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              (void *)v212.m_real.m128_u64[0],
              8 * v212.m_real.m128_i32[3]);
          v212.m_real.m128_u64[0] = 0i64;
          v212.m_real.m128_i32[3] = 0x80000000;
          indices.m_size = 0;
          if ( indices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              indices.m_data,
              4 * indices.m_capacityAndFlags);
          indices.m_data = 0i64;
          indices.m_capacityAndFlags = 0x80000000;
          v218 = 0;
          if ( v219 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v219);
          array = 0i64;
          v219 = 0x80000000;
          goto LABEL_347;
        }
        v116 = v223.m_real.m128_i32[3];
        v115 = v231;
      }
      v223.m_real.m128_i32[2] = v117;
      v118 = 0;
      if ( v117 > 0 )
      {
        v119 = 0i64;
        do
        {
          ++v118;
          v119 += 4i64;
          *(_DWORD *)(v119 + v223.m_real.m128_u64[0] - 4) = *(_DWORD *)(v119 + *(_QWORD *)v115 - 4);
          v117 = v223.m_real.m128_i32[2];
        }
        while ( v118 < v223.m_real.m128_i32[2] );
        v116 = v223.m_real.m128_i32[3];
      }
      --v115[2];
      v120 = *(_QWORD *)v115 + 4 * v96;
      v121 = v96;
      v122 = 4 * (v115[2] - v96);
      if ( v122 > 0 )
      {
        v123 = ((unsigned int)(v122 - 1) >> 2) + 1;
        do
        {
          v124 = *(_DWORD *)(v120 + 4);
          v120 += 4i64;
          *(_DWORD *)(v120 - 4) = v124;
          --v123;
        }
        while ( v123 );
        v116 = v223.m_real.m128_i32[3];
        v117 = v223.m_real.m128_i32[2];
      }
      v125 = v231;
      v126 = *((_DWORD *)v231 + 2);
      if ( v121 == v126 )
      {
        v127 = *(_QWORD *)v231;
        v128 = v126 - 1;
        *((_DWORD *)v231 + 2) = v128;
        v129 = 4 * v128;
        if ( v129 > 0 )
        {
          v130 = ((unsigned int)(v129 - 1) >> 2) + 1;
          do
          {
            v131 = *(_DWORD *)(v127 + 4);
            v127 += 4i64;
            *(_DWORD *)(v127 - 4) = v131;
            --v130;
          }
          while ( v130 );
        }
        v132 = **(_DWORD **)v125;
        v133 = v125[2] + 1;
        v134 = v125[3] & 0x3FFFFFFF;
        if ( v134 >= v133 )
        {
          v240.m_enum = HK_SUCCESS;
        }
        else
        {
          v135 = 2 * v134;
          if ( v133 < v135 )
            v133 = v135;
          hkArrayUtil::_reserve(&v240, &hkContainerHeapAllocator::s_alloc, v125, v133, 4);
          if ( v240.m_enum )
          {
LABEL_188:
            v136 = v223.m_real.m128_i32[3];
            v33 = result;
            result->m_enum = HK_FAILURE;
            v223.m_real.m128_i32[2] = 0;
            if ( v136 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                (void *)v223.m_real.m128_u64[0],
                4 * v136);
            v223.m_real.m128_u64[0] = 0i64;
            v223.m_real.m128_i32[3] = 0x80000000;
            goto LABEL_191;
          }
        }
        *(_DWORD *)(*(_QWORD *)v125 + 4i64 * (int)v125[2]++) = v132;
        v116 = v223.m_real.m128_i32[3];
        v117 = v223.m_real.m128_i32[2];
      }
      v250.m_real = m_real;
      v249.m_real = v53;
      `anonymous namespace::computeFullSignedPartitionAreas(
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut,
        segmentsInOut,
        segmentIndex,
        majorAxisA,
        majorAxisB,
        &v250,
        &v249);
      v137 = v125[3] & 0x3FFFFFFF;
      if ( v137 >= v117 )
      {
        v237.m_enum = HK_SUCCESS;
      }
      else
      {
        v138 = 2 * v137;
        v139 = v117;
        if ( v117 < v138 )
          v139 = v138;
        hkArrayUtil::_reserve(&v237, &hkContainerHeapAllocator::s_alloc, v125, v139, 4);
        if ( v237.m_enum )
          goto LABEL_188;
        v116 = v223.m_real.m128_i32[3];
      }
      v125[2] = v117;
      v78 = 0i64;
      if ( v117 > 0 )
      {
        v140 = 0i64;
        do
        {
          v78 = (unsigned int)(v78 + 1);
          v141 = *(_DWORD *)(v223.m_real.m128_u64[0] + v140);
          v140 += 4i64;
          *(_DWORD *)(v140 + *(_QWORD *)v125 - 4) = v141;
        }
        while ( (int)v78 < v125[2] );
        v116 = v223.m_real.m128_i32[3];
      }
      LODWORD(v142) = (unsigned int)(2 * v250.m_real.m128_i32[0]) >> 1;
      LODWORD(v143) = (unsigned int)(2 * v249.m_real.m128_i32[0]) >> 1;
      LODWORD(v144) = (unsigned int)(2 * LODWORD(v65)) >> 1;
      LODWORD(v145) = (unsigned int)(2 * LODWORD(v64)) >> 1;
      if ( v211 )
      {
        if ( v142 > v144 )
          goto LABEL_208;
        v146 = v242;
        if ( v242 > 1 && v143 > v145 )
          goto LABEL_208;
      }
      else
      {
        v146 = v242;
      }
      LODWORD(v147) = _mm_shuffle_ps(
                        (__m128)LODWORD(SimplificationSettings->m_maxLoopShrinkFraction),
                        (__m128)LODWORD(SimplificationSettings->m_maxLoopShrinkFraction),
                        0).m128_u32[0];
      if ( v250.m_real.m128_f32[0] < 0.0 != v65 < 0.0
        || v142 <= (float)(v147 * v144)
        || v146 > 1 && (v249.m_real.m128_f32[0] < 0.0 != v64 < 0.0 || v143 <= (float)(v147 * v145)) )
      {
LABEL_208:
        v223.m_real.m128_i32[2] = 0;
        if ( v116 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            (void *)v223.m_real.m128_u64[0],
            4 * v116);
        v223.m_real.m128_u64[0] = 0i64;
        v223.m_real.m128_i32[3] = 0x80000000;
        goto LABEL_161;
      }
      v223.m_real.m128_i32[2] = 0;
      if ( v116 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)v223.m_real.m128_u64[0],
          4 * v116);
      v114 = v246;
      v223.m_real.m128_u64[0] = 0i64;
      v99 = a;
      v223.m_real.m128_i32[3] = 0x80000000;
    }
    if ( majorAxisA == majorAxisB )
    {
      LODWORD(majorAxis) = majorAxisA;
      LODWORD(v209) = segmentIndex;
      area1Outa = v95;
      v148 = b;
      v149 = `anonymous namespace::collapseMakesCorridorImpassable(
               v114->m_minCorridorWidth,
               v114->m_maxCorridorWidth,
               v99,
               v100,
               b,
               v99,
               b,
               area1Outa,
               (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut,
               (hkRotationf *)segmentsInOut,
               v209,
               majorAxis,
               &projectionMatrix,
               tree,
               &v245);
      if ( v245.m_enum )
      {
        v33 = result;
        result->m_enum = HK_FAILURE;
LABEL_191:
        v228.m_size = 0;
        if ( v228.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v228.m_data,
            16 * v228.m_capacityAndFlags);
        v228.m_data = 0i64;
        v228.m_capacityAndFlags = 0x80000000;
        goto LABEL_313;
      }
      if ( v149 )
        goto LABEL_161;
    }
    else
    {
      v148 = b;
    }
    v150 = array;
    v151 = 0;
    v152 = -1;
    v153 = -1i64;
    v154 = 0;
    v155 = 0i64;
    if ( v218 > 0 )
    {
      while ( *(_DWORD *)&array[4 * v155] != (_DWORD)v94 )
      {
        ++v154;
        ++v155;
        if ( v154 >= v218 )
          goto LABEL_233;
      }
      v152 = v154;
      v153 = v155;
    }
LABEL_233:
    v156 = -1;
    v157 = v152;
    if ( v152 < v218 )
    {
      v158 = &array[4 * v153];
      while ( *(_DWORD *)v158 != (_DWORD)v98 )
      {
        ++v157;
        v158 += 4;
        if ( v157 >= v218 )
          goto LABEL_239;
      }
      v156 = v157;
    }
LABEL_239:
    v159 = 0;
    indices.m_size = 0;
    if ( v156 == -1 )
    {
      if ( v218 > 0 )
      {
        v160 = array;
        while ( *v160 != (_DWORD)v98 )
        {
          ++v151;
          ++v160;
          if ( v151 >= v218 )
            goto LABEL_246;
        }
        v156 = v151;
      }
LABEL_246:
      v161 = v152 + 1;
      if ( v161 < v218 )
      {
        v162 = 4 * v153 + 4;
        do
        {
          if ( v159 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &indices, 4);
            v159 = indices.m_size;
          }
          indices.m_data[v159] = *(_DWORD *)((char *)v150 + v162);
          v150 = array;
          v159 = indices.m_size + 1;
          ++v161;
          v162 += 4i64;
          ++indices.m_size;
        }
        while ( v161 < v218 );
      }
      v163 = 0i64;
      if ( v156 > 0 )
      {
        while ( 1 )
        {
          if ( v159 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &indices, 4);
            v159 = indices.m_size;
          }
          indices.m_data[v159] = v150[v163++];
          v159 = ++indices.m_size;
          if ( v163 >= v156 )
            break;
          v150 = array;
        }
      }
    }
    else
    {
      v164 = v153 + 1;
      if ( v153 + 1 < v156 )
      {
        while ( 1 )
        {
          if ( v159 == (indices.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &indices, 4);
            v159 = indices.m_size;
          }
          indices.m_data[v159] = v150[v164++];
          v159 = ++indices.m_size;
          if ( v164 >= v156 )
            break;
          v150 = array;
        }
      }
    }
    v12 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut;
    v165 = a;
    ProjectedDistanceErrorSquared = `anonymous namespace::getProjectedDistanceErrorSquared(
                                      &v254,
                                      a,
                                      v148,
                                      (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut,
                                      &indices,
                                      majorAxisA);
    v167 = (__int64)v246;
    if ( COERCE_FLOAT(*ProjectedDistanceErrorSquared) > (float)(v246->m_maxBorderDistanceError
                                                              * v246->m_maxBorderDistanceError)
      || v211
      && COERCE_FLOAT(*`anonymous namespace::getProjectedDistanceErrorSquared(
                         &v253,
                         v165,
                         v148,
                         (hkArray<hkVector4f,hkContainerHeapAllocator> *)verticesInOut,
                         &indices,
                         majorAxisB)) > (float)(*(float *)(v167 + 32) * *(float *)(v167 + 32)) )
    {
LABEL_161:
      v228.m_size = 0;
      if ( v228.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v228.m_data,
          16 * v228.m_capacityAndFlags);
      goto LABEL_283;
    }
    v228.m_size = 0;
    if ( v228.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v228.m_data,
        16 * v228.m_capacityAndFlags);
    v168 = v226;
    if ( v226 == -1 )
      goto LABEL_336;
    v16 = (int *)v231;
    v169 = *((_DWORD *)v231 + 2) - 1;
    *((_DWORD *)v231 + 2) = v169;
    if ( (_DWORD)v168 != v169 )
    {
      v183 = *(_QWORD *)v16 + 4 * v168;
      v184 = 4 * (v169 - v168);
      if ( v184 > 0 )
      {
        v185 = ((unsigned int)(v184 - 1) >> 2) + 1;
        do
        {
          v186 = *(_DWORD *)(v183 + 4);
          v183 += 4i64;
          *(_DWORD *)(v183 - 4) = v186;
          --v185;
        }
        while ( v185 );
      }
      v187 = v241;
      v188 = segmentsInOut->m_data;
      --*(int *)((char *)&v188->m_boundary.m_size + v241);
      v189 = *(int *)((char *)&v188->m_boundary.m_size + v187);
      if ( (_DWORD)v189 != (_DWORD)v168 )
        (*(int **)((char *)&v188->m_boundary.m_data + v187))[v168] = (*(int **)((char *)&v188->m_boundary.m_data + v187))[v189];
LABEL_292:
      v214 = 0;
      if ( v215 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          pArr,
          12 * (v215 & 0x3FFFFFFF));
      pArr = 0i64;
      v215 = 0x80000000;
      v212.m_real.m128_i32[2] = 0;
      if ( v212.m_real.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)v212.m_real.m128_u64[0],
          8 * v212.m_real.m128_i32[3]);
      v212.m_real.m128_u64[0] = 0i64;
      v212.m_real.m128_i32[3] = 0x80000000;
      continue;
    }
    break;
  }
  v170 = v241;
  v171 = segmentsInOut->m_data;
  v35 = (*(int *)((char *)&segmentsInOut->m_data->m_boundary.m_size + v241))-- == 1;
  if ( !v35 )
    **(_DWORD **)((char *)&v171->m_boundary.m_data + v170) = (*(int **)((char *)&v171->m_boundary.m_data + v170))[*(int *)((char *)&v171->m_boundary.m_size + v170)];
  v172 = v16[2];
  if ( v172 <= 4 )
    goto LABEL_336;
  v173 = *(int **)v16;
  v174 = v172 - 1;
  v16[2] = v174;
  v175 = 4 * v174;
  if ( v175 > 0 )
  {
    v176 = ((unsigned int)(v175 - 1) >> 2) + 1;
    do
    {
      v177 = v173[1];
      *v173++ = v177;
      --v176;
    }
    while ( v176 );
  }
  v178 = **(_DWORD **)v16;
  v179 = v16[2] + 1;
  v180 = v16[3] & 0x3FFFFFFF;
  if ( v180 >= v179 )
  {
    v227.m_enum = HK_SUCCESS;
LABEL_286:
    *(_DWORD *)(*(_QWORD *)v16 + 4i64 * v16[2]++) = v178;
    goto LABEL_292;
  }
  v181 = 2 * v180;
  if ( v179 < v181 )
    v179 = v181;
  hkArrayUtil::_reserve(&v227, &hkContainerHeapAllocator::s_alloc, v16, v179, 4);
  if ( v227.m_enum == HK_SUCCESS )
    goto LABEL_286;
  v33 = result;
  v182 = v215;
  v214 = 0;
  result->m_enum = HK_FAILURE;
  if ( v182 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 12 * (v182 & 0x3FFFFFFF));
  pArr = 0i64;
  v215 = 0x80000000;
  v212.m_real.m128_i32[2] = 0;
  if ( v212.m_real.m128_i32[3] >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      (void *)v212.m_real.m128_u64[0],
      8 * v212.m_real.m128_i32[3]);
  v212.m_real.m128_u64[0] = 0i64;
  v212.m_real.m128_i32[3] = 0x80000000;
LABEL_341:
  indices.m_size = 0;
  if ( indices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      indices.m_data,
      4 * indices.m_capacityAndFlags);
  v218 = 0;
  indices.m_capacityAndFlags = 0x80000000;
  indices.m_data = 0i64;
  if ( v219 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v219);
  array = 0i64;
LABEL_346:
  v219 = 0x80000000;
LABEL_347:
  v197 = points.m_size;
  v198 = (char *)p;
  if ( p == points.m_data )
    v197 = 0;
  points.m_size = v197;
  v199 = (16 * v222 + 127) & 0xFFFFFF80;
  v200 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v201 = (v199 + 15) & 0xFFFFFFF0;
  if ( v199 > v200->m_slabSize || &v198[v201] != v200->m_cur || v200->m_firstNonLifoEnd == v198 )
    hkLifoAllocator::slowBlockFree(v200, v198, v201);
  else
    v200->m_cur = v198;
  points.m_size = 0;
LABEL_355:
  m_capacityAndFlags = points.m_capacityAndFlags;
  if ( points.m_capacityAndFlags >= 0 )
LABEL_356:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * m_capacityAndFlags);
  return v33;
}

// File Line: 2600
// RVA: 0xB56F10
hkResult *__fastcall `anonymous namespace::simplifyConcaveBoundary(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut,
        hkPointerMultiMap<int,int> *segmentsInOut,
        hkArrayBase<int> *segmentToOppositeMap,
        int segmentIndex,
        int majorAxisA,
        int majorAxisB,
        hkcdDynamicAabbTree *tree,
        hkPointerMultiMap<int,int> *parToSegIdxMap)
{
  int v10; // r13d
  int v11; // ebx
  hkaiNavMeshSimplificationUtils::Segment *m_elem; // rax
  __int64 v14; // rdi
  bool v16; // zf
  bool v17; // r10
  hkResult *v18; // rax
  int v19; // r11d
  __int64 v20; // rax
  _DWORD *v21; // rsi
  int v22; // edi
  __m128 m_real; // xmm14
  __m128 v24; // xmm15
  char v25; // r10
  int v26; // eax
  __int64 v27; // r8
  bool v28; // cl
  int v29; // eax
  int v30; // r13d
  int v31; // ebx
  int v32; // r9d
  __int64 v33; // r9
  int v34; // r12d
  int v35; // ecx
  _DWORD *v36; // r8
  hkVector4f *m_data; // r9
  hkVector4f *v38; // rbx
  __int64 v39; // rdi
  hkVector4f *v40; // rdi
  float ProjectedTriangleArea; // xmm0_4
  float v42; // xmm6_4
  int v43; // r9d
  hkgpCgo::ClusterData *v44; // rbx
  hkVector4f *v45; // r8
  hkVector4f *v46; // rdx
  hkVector4f *v47; // rcx
  unsigned __int64 v48; // rdi
  __int64 v49; // r12
  hkVector4f *v50; // rax
  float TriangleArea; // xmm0_4
  int v52; // ebx
  int v53; // edi
  int v54; // r9d
  DuplicateVertexRef *v55; // r8
  __int64 v56; // rdx
  char *v57; // rax
  int v58; // ecx
  _DWORD *v59; // r8
  __int64 v60; // r10
  __int64 v61; // rdi
  __int64 v62; // rcx
  hkVector4f *v63; // rdi
  hkVector4f *v64; // r12
  hkVector4f *v65; // rbx
  __int128 m_quad; // xmm5
  __int128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm0
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  float v73; // xmm6_4
  hkSimdFloat32 *HeightErrorSquared; // rax
  hkSimdFloat32 *v75; // rax
  __m128 v76; // xmm5
  __m128 v77; // xmm1
  __m128 v78; // xmm6
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm2
  __m128 v82; // xmm4
  __m128 v83; // xmm0
  __m128 v84; // xmm1
  __m128 v85; // xmm6
  __m128 v86; // xmm12
  __m128 v87; // xmm6
  __m128 v88; // xmm4
  __m128 v89; // xmm2
  __m128 v90; // xmm0
  __m128 v91; // xmm0
  __m128 v92; // xmm7
  int v93; // r9d
  int *v94; // r10
  int v95; // r9d
  int v96; // eax
  int v97; // eax
  _DWORD *v98; // rbx
  int m_capacityAndFlags; // r8d
  char doesLineSegmentIntersectPartition; // al
  char v101; // cl
  unsigned int v102; // eax
  __int64 v103; // r12
  char *v104; // rdi
  int v105; // ebx
  __int64 v106; // r8
  __int64 v107; // r9
  int v108; // ecx
  _DWORD *v109; // r8
  __m128 v110; // xmm8
  __m128 v111; // xmm3
  __m128 v112; // xmm1
  __int64 v113; // r9
  int v114; // edx
  hkVector4f *v115; // rcx
  __m128 v116; // xmm0
  __m128 v117; // xmm1
  __m128 v118; // xmm6
  __m128 v119; // xmm7
  __m128 v120; // xmm7
  hkVector4f *v121; // rdx
  __int64 v122; // rax
  __int64 v123; // rdx
  int v124; // r9d
  __int64 v125; // rcx
  int v126; // eax
  int v127; // ecx
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v128; // r13
  int v129; // eax
  int v130; // eax
  int v131; // r9d
  int v132; // r8d
  __int64 v133; // rdx
  unsigned int v134; // xmm1_4
  unsigned int v135; // xmm0_4
  unsigned int v136; // xmm2_4
  float v137; // xmm2_4
  float v138; // xmm3_4
  int v139; // r9d
  int v140; // r9d
  int v141; // ebx
  int v142; // eax
  int v143; // eax
  __int64 v144; // rbx
  int v145; // ecx
  __m128 v146; // xmm1
  __m128 v147; // xmm4
  __m128 v148; // xmm2
  __int64 v149; // rdi
  __m128 v150; // xmm1
  __m128 v151; // xmm2
  __int64 v152; // r12
  int v153; // r9d
  __m128 v154; // xmm6
  int v155; // eax
  __m128 v156; // xmm7
  int v157; // eax
  __int64 v158; // rcx
  int v159; // edx
  __int64 v160; // rdx
  int v161; // eax
  __int64 v162; // rcx
  hkaiNavMeshSimplificationUtils::Segment *v163; // rax
  int v164; // edx
  __int64 v165; // rcx
  int v166; // edx
  __int64 v167; // rdx
  int v168; // eax
  hkcdDynamicAabbTree *v169; // [rsp+20h] [rbp-B0h]
  int area1InOut; // [rsp+28h] [rbp-A8h]
  int area2InOut; // [rsp+30h] [rbp-A0h]
  int area1Out; // [rsp+38h] [rbp-98h]
  hkRotationf *area2Out; // [rsp+40h] [rbp-90h]
  hkRotationf *resOut; // [rsp+48h] [rbp-88h]
  hkcdDynamicAabbTree *v175; // [rsp+50h] [rbp-80h]
  hkgpCgo::ClusterData *pArr; // [rsp+58h] [rbp-78h] BYREF
  hkRotationf *projection; // [rsp+60h] [rbp-70h]
  hkcdDynamicAabbTree *v178; // [rsp+68h] [rbp-68h]
  hkVector4f *array; // [rsp+70h] [rbp-60h] BYREF
  int v180; // [rsp+78h] [rbp-58h]
  int v181; // [rsp+7Ch] [rbp-54h]
  bool v182; // [rsp+80h] [rbp-50h]
  int v183; // [rsp+84h] [rbp-4Ch]
  int v184; // [rsp+88h] [rbp-48h]
  hkVector4f *b; // [rsp+90h] [rbp-40h]
  hkVector4f *c; // [rsp+98h] [rbp-38h]
  hkResult v187; // [rsp+A0h] [rbp-30h] BYREF
  hkResult v188; // [rsp+A4h] [rbp-2Ch] BYREF
  hkResult v189; // [rsp+A8h] [rbp-28h] BYREF
  hkResult resulta; // [rsp+ACh] [rbp-24h] BYREF
  hkVector4f *a; // [rsp+B0h] [rbp-20h]
  int v192; // [rsp+B8h] [rbp-18h] BYREF
  hkResult v193; // [rsp+BCh] [rbp-14h] BYREF
  hkSimdFloat32 v194; // [rsp+C0h] [rbp-10h] BYREF
  hkSimdFloat32 v195; // [rsp+D0h] [rbp+0h] BYREF
  hkArrayBase<hkVector4f> points; // [rsp+E0h] [rbp+10h] BYREF
  __int128 v197[3]; // [rsp+F0h] [rbp+20h] BYREF
  int localSettingsIndex; // [rsp+120h] [rbp+50h]
  hkResult v199; // [rsp+124h] [rbp+54h] BYREF
  hkResult v200; // [rsp+128h] [rbp+58h] BYREF
  int skipIndex; // [rsp+12Ch] [rbp+5Ch]
  int v202; // [rsp+130h] [rbp+60h]
  hkVector4f *end; // [rsp+138h] [rbp+68h]
  __int64 v204; // [rsp+140h] [rbp+70h]
  __int64 v205; // [rsp+148h] [rbp+78h]
  hkVector4f *start; // [rsp+150h] [rbp+80h]
  __m128 v207; // [rsp+160h] [rbp+90h]
  __m128 v208; // [rsp+170h] [rbp+A0h] BYREF
  hkSimdFloat32 v209; // [rsp+180h] [rbp+B0h] BYREF
  __m128 v210; // [rsp+190h] [rbp+C0h] BYREF
  hkSimdFloat32 v211; // [rsp+1A0h] [rbp+D0h] BYREF
  hkRotationf projectionMatrix; // [rsp+1B0h] [rbp+E0h] BYREF
  hkRotationf projB; // [rsp+1E0h] [rbp+110h] BYREF
  hkSimdFloat32 v214; // [rsp+210h] [rbp+140h] BYREF
  hkSimdFloat32 v215; // [rsp+220h] [rbp+150h] BYREF
  _DWORD *v216; // [rsp+310h] [rbp+240h]
  hkaiNavMeshGenerationSettings *v217; // [rsp+318h] [rbp+248h]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments; // [rsp+328h] [rbp+258h]
  hkArrayBase<int> *vars0; // [rsp+330h] [rbp+260h]
  void *retaddr; // [rsp+338h] [rbp+268h]
  int majorAxis; // [rsp+340h] [rbp+270h]
  hkaiNavMeshGenerationSettings *v222; // [rsp+348h] [rbp+278h] BYREF
  hkcdDynamicAabbTree *v223; // [rsp+350h] [rbp+280h]
  hkPointerMultiMap<int,int> *v224; // [rsp+358h] [rbp+288h]

  v224 = segmentsInOut;
  v222 = settings;
  majorAxis = (int)result;
  v10 = (int)result;
  v11 = (int)settings;
  m_elem = (hkaiNavMeshSimplificationUtils::Segment *)segmentsInOut->m_map.m_elem;
  v207 = _mm_shuffle_ps(
           (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
           (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
           0);
  v14 = 48i64 * (int)retaddr;
  v16 = m_elem[(unsigned __int64)v14 / 0x30].m_partitionIdB == -1;
  v204 = v14;
  v182 = v16;
  v17 = (_DWORD)result != (_DWORD)settings && (_DWORD)settings != -1;
  BYTE1(v175) = v17;
  if ( !v16 && !v17 )
  {
    v18 = result;
    result->m_enum = HK_SUCCESS;
    return v18;
  }
  anonymous_namespace_::getProjectionMatrix((int)result, &projectionMatrix);
  anonymous_namespace_::getProjectionMatrix(v11, &projB);
  v21 = (_DWORD *)(v14 + v20 + 32);
  v22 = 0;
  m_real = 0i64;
  v194.m_real = 0i64;
  v208 = 0i64;
  v210 = 0i64;
  v24 = 0i64;
  v195.m_real = 0i64;
  if ( v25 )
  {
    v26 = `anonymous namespace::computePartialSignedPartitionAreas(
            verticesInOut,
            (hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *)segmentsInOut,
            vars0,
            v224,
            v19,
            v10,
            v11,
            &v194,
            &v195,
            &v187);
    m_real = v194.m_real;
    v24 = v195.m_real;
    v22 = v26;
    `anonymous namespace::computeFullSignedPartitionAreas(
      verticesInOut,
      (hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *)segmentsInOut,
      (int)retaddr,
      v10,
      v11,
      &v194,
      &v195);
    v208 = v194.m_real;
    v210 = v195.m_real;
  }
  v27 = (int)v21[2];
  v28 = **(_DWORD **)v21 == *(_DWORD *)(*(_QWORD *)v21 + 4 * v27 - 4);
  LOBYTE(v175) = v28;
  if ( **(_DWORD **)v21 == *(_DWORD *)(*(_QWORD *)v21 + 4 * v27 - 4) )
    v21[2] = v27 - 1;
  localSettingsIndex = *(_DWORD *)((char *)&segmentsInOut->m_map.m_elem->key + v204);
  v205 = v22;
LABEL_13:
  if ( !v28 || (int)v21[2] >= 4 )
  {
    v29 = 3;
    if ( v28 )
      v29 = 1;
    v30 = 2;
    if ( v28 )
      v30 = 0;
    v31 = v21[2] - v29;
    v183 = v31;
    v32 = v31 - v30 + 1;
    if ( v32 >= 1 )
    {
      array = 0i64;
      v180 = 0;
      v181 = 0x80000000;
      pArr = 0i64;
      projection = (hkRotationf *)0x8000000000000000i64;
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v32, 8);
      if ( resulta.m_enum )
      {
        v98 = v216;
        *v216 = 1;
LABEL_177:
        LODWORD(projection) = 0;
        if ( SHIDWORD(projection) >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            pArr,
            12 * (HIDWORD(projection) & 0x3FFFFFFF));
        pArr = 0i64;
        HIDWORD(projection) = 0x80000000;
        v180 = 0;
        if ( v181 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v181);
        return (hkResult *)v98;
      }
      v34 = (int)projection;
      if ( v30 <= v31 )
      {
        do
        {
          v35 = v21[2];
          v36 = *(_DWORD **)v21;
          m_data = verticesInOut->m_data;
          v38 = &verticesInOut->m_data[*(int *)(*(_QWORD *)v21 + 4i64 * ((v30 + v35 - 1) % v35))];
          a = v38;
          v39 = (int)v36[v30 % v35];
          v184 = v30 + 1;
          v40 = &m_data[v39];
          b = v40;
          c = &m_data[v36[(v30 + 1) % v35]];
          ProjectedTriangleArea = `anonymous namespace::getProjectedTriangleArea(v38, v40, c, majorAxis);
          v42 = ProjectedTriangleArea;
          if ( BYTE1(v175) || ProjectedTriangleArea >= 0.001 )
          {
            if ( v180 == (v181 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 8);
            v49 = v180;
            v50 = array;
            ++v180;
            array->m_quad.m128_i32[2 * v49 + 1] = v30;
            b = v50;
            if ( BYTE1(v175) )
            {
              TriangleArea = `anonymous namespace::getTriangleArea(v38, v40, c);
              v50 = b;
              v42 = TriangleArea;
            }
            v50->m_quad.m128_f32[2 * v49] = v42;
          }
          else
          {
            v43 = v34 + 1;
            if ( (HIDWORD(projection) & 0x3FFFFFFF) >= v34 + 1 )
            {
              v188.m_enum = HK_SUCCESS;
            }
            else
            {
              if ( v43 < 2 * (HIDWORD(projection) & 0x3FFFFFFF) )
                v43 = 2 * (HIDWORD(projection) & 0x3FFFFFFF);
              hkArrayUtil::_reserve(&v188, &hkContainerTempAllocator::s_alloc, &pArr, v43, 12);
              if ( v188.m_enum )
              {
LABEL_163:
                v98 = v216;
                *v216 = 1;
                goto LABEL_177;
              }
              v34 = (int)projection;
            }
            if ( v34 == (HIDWORD(projection) & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &pArr, 12);
              v34 = (int)projection;
            }
            v44 = pArr;
            v45 = c;
            v46 = b;
            v47 = a;
            v48 = v34;
            LODWORD(projection) = v34 + 1;
            LODWORD(pArr[v48].m_errorRange[1]) = v30;
            *(float *)&v44[v48].m_numVertices = ProjectedTriangleArea;
            v44[v48].m_errorRange[0] = `anonymous namespace::getTriangleArea(v47, v46, v45);
          }
          v30 = v184;
          v34 = (int)projection;
        }
        while ( v184 <= v183 );
      }
      if ( v180 > 1 )
      {
        hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
          (DuplicateVertexRef *)array,
          0,
          v180 - 1,
          0);
        v34 = (int)projection;
      }
      if ( v34 )
      {
        if ( v34 > 1 )
        {
          hkAlgorithm::quickSortRecursive<hkgpCgo::ClusterData,hkAlgorithm::less<hkgpCgo::ClusterData>>(
            pArr,
            0,
            v34 - 1,
            0);
          v34 = (int)projection;
        }
        v52 = v180;
        v53 = v34 + v180;
        if ( v34 + v180 > (v181 & 0x3FFFFFFF) )
        {
          v54 = v34 + v180;
          if ( v53 < 2 * (v181 & 0x3FFFFFFF) )
            v54 = 2 * (v181 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v200, &hkContainerTempAllocator::s_alloc, &array, v54, 8);
        }
        hkMemUtil::memMove((char *)array + 8 * v34, array, 8 * v52);
        v180 = v53;
        v33 = 0i64;
        if ( (int)projection > 0 )
        {
          v55 = (DuplicateVertexRef *)array;
          v56 = 0i64;
          do
          {
            v33 = (unsigned int)(v33 + 1);
            ++v56;
            ++v55;
            v55[-1].m_index = LODWORD(pArr[v56 - 1].m_errorRange[1]);
            LODWORD(v55[-1].m_value) = pArr[v56 - 1].m_numVertices;
          }
          while ( (int)v33 < (int)projection );
        }
      }
      v57 = 0i64;
      v184 = 0;
      c = 0i64;
      if ( v180 <= 0 )
      {
LABEL_141:
        LODWORD(projection) = 0;
        if ( SHIDWORD(projection) >= 0 )
          ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkgpCgo::ClusterData *, _QWORD, __int64, hkcdDynamicAabbTree *, int, int, int, hkRotationf *, hkRotationf *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerTempAllocator::s_alloc,
            pArr,
            12 * (HIDWORD(projection) & 0x3FFFFFFFu),
            v33,
            v169,
            area1InOut,
            area2InOut,
            area1Out,
            area2Out,
            resOut);
        pArr = 0i64;
        HIDWORD(projection) = 0x80000000;
        v180 = 0;
        if ( v181 >= 0 )
          ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkVector4f *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerTempAllocator::s_alloc,
            array,
            (unsigned int)(8 * v181),
            v33);
        v28 = (char)v175;
        goto LABEL_146;
      }
      while ( 1 )
      {
        v58 = v21[2];
        v59 = *(_DWORD **)v21;
        v33 = array->m_quad.m128_u32[2 * (_QWORD)v57 + 1];
        v183 = v33;
        v60 = (int)v59[((int)v33 + v58 - 1) % v58];
        v61 = (int)v59[(int)v33 % v58];
        LODWORD(a) = v33 + 1;
        skipIndex = v61;
        v62 = (int)v59[((int)v33 + 1) % v58];
        if ( v182 && (_DWORD)v60 == (_DWORD)v62 )
          goto LABEL_140;
        v63 = &verticesInOut->m_data[v61];
        v64 = &verticesInOut->m_data[v62];
        v65 = &verticesInOut->m_data[v60];
        m_quad = (__int128)v63->m_quad;
        v67 = (__int128)v64->m_quad;
        v68 = _mm_sub_ps(v64->m_quad, v65->m_quad);
        v69 = _mm_sub_ps(v64->m_quad, v63->m_quad);
        if ( !BYTE1(v175) )
          break;
LABEL_78:
        v73 = array->m_quad.m128_f32[2 * (_QWORD)c];
        v197[0] = (__int128)v65->m_quad;
        v197[1] = m_quad;
        v197[2] = v67;
        points.m_size = 3;
        points.m_capacityAndFlags = -2147483645;
        points.m_data = (hkVector4f *)v197;
        b = (hkVector4f *)hkaiNavMeshGenerationSettings::getSimplificationSettings(v217, &points, localSettingsIndex);
        if ( v73 < b->m_quad.m128_f32[1] )
        {
          HeightErrorSquared = `anonymous namespace::getHeightErrorSquared(&v215, v63, v65, v64, majorAxis);
          if ( COERCE_FLOAT(*HeightErrorSquared) <= (float)(b[1].m_quad.m128_f32[3] * b[1].m_quad.m128_f32[3]) )
          {
            if ( !BYTE1(v175)
              || (v75 = `anonymous namespace::getHeightErrorSquared(&v214, v63, v65, v64, (int)v222),
                  COERCE_FLOAT(*v75) <= (float)(b[1].m_quad.m128_f32[3] * b[1].m_quad.m128_f32[3])) )
            {
              v76 = _mm_sub_ps(v65->m_quad, v64->m_quad);
              v77 = _mm_mul_ps(v76, v76);
              v78 = _mm_sub_ps(v65->m_quad, v63->m_quad);
              v79 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                      _mm_shuffle_ps(v77, v77, 170));
              v80 = _mm_mul_ps(v78, v76);
              v81 = _mm_rcp_ps(v79);
              v82 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                        _mm_shuffle_ps(v80, v80, 170)),
                      _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v79, v81)), v81));
              v83 = _mm_cmplt_ps(v82, query.m_quad);
              v84 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v82, v83), _mm_andnot_ps(v83, query.m_quad)));
              v85 = _mm_add_ps(_mm_sub_ps(v78, _mm_mul_ps(v84, v76)), v63->m_quad);
              v86 = _mm_sub_ps(v63->m_quad, _mm_shuffle_ps(v85, _mm_unpackhi_ps(v85, v84), 196));
              v87 = _mm_mul_ps(v86, v86);
              v88 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                      _mm_shuffle_ps(v87, v87, 170));
              v89 = _mm_rsqrt_ps(v88);
              v90 = _mm_andnot_ps(
                      _mm_cmple_ps(v88, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v89, v88), v89)),
                        _mm_mul_ps(*(__m128 *)_xmm, v89)));
              v91 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0), v207),
                        _mm_mul_ps(v90, v88)),
                      _mm_mul_ps(v90, v86));
              v92 = _mm_add_ps(v91, v64->m_quad);
              v194.m_real = _mm_add_ps(v91, v65->m_quad);
              v93 = v21[2];
              v94 = *(int **)v21;
              v195.m_real = v92;
              start = &verticesInOut->m_data[v94[(v93 + v183 - 2) % v93]];
              end = &verticesInOut->m_data[v94[(v183 + 2) % v93]];
              if ( (_BYTE)v175 )
              {
                v95 = v93 + 1;
                v202 = *v94;
                v96 = v21[3] & 0x3FFFFFFF;
                if ( v96 >= v95 )
                {
                  v193.m_enum = HK_SUCCESS;
                }
                else
                {
                  v97 = 2 * v96;
                  if ( v95 < v97 )
                    v95 = v97;
                  hkArrayUtil::_reserve(&v193, &hkContainerHeapAllocator::s_alloc, v21, v95, 4);
                  if ( v193.m_enum )
                  {
LABEL_87:
                    v98 = v216;
                    m_capacityAndFlags = points.m_capacityAndFlags;
                    points.m_size = 0;
                    *v216 = 1;
                    if ( m_capacityAndFlags >= 0 )
                      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                        &hkContainerHeapAllocator::s_alloc,
                        points.m_data,
                        16 * m_capacityAndFlags);
                    points.m_data = 0i64;
                    points.m_capacityAndFlags = 0x80000000;
                    goto LABEL_177;
                  }
                }
                *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (int)v21[2]++) = v202;
              }
              resOut = &projB;
              area2Out = &projectionMatrix;
              area1Out = (int)v222;
              area2InOut = majorAxis;
              area1InOut = (int)retaddr;
              v169 = v223;
              if ( `anonymous namespace::doesLineSegmentIntersectPartition(
                     (hkVector4f *)&v194,
                     (hkVector4f *)&v195,
                     (__m128 *)verticesInOut,
                     segments) )
              {
                goto LABEL_95;
              }
              resOut = &projB;
              area2Out = &projectionMatrix;
              area1Out = (int)v222;
              area2InOut = majorAxis;
              area1InOut = (int)retaddr;
              v169 = v223;
              if ( `anonymous namespace::doesLineSegmentIntersectPartition(
                     start,
                     (hkVector4f *)&v194,
                     (__m128 *)verticesInOut,
                     segments)
                || (resOut = &projB,
                    area2Out = &projectionMatrix,
                    area1Out = (int)v222,
                    area2InOut = majorAxis,
                    area1InOut = (int)retaddr,
                    v169 = v223,
                    (doesLineSegmentIntersectPartition = `anonymous namespace::doesLineSegmentIntersectPartition(
                                                           (hkVector4f *)&v195,
                                                           end,
                                                           (__m128 *)verticesInOut,
                                                           segments)) != 0) )
              {
LABEL_95:
                doesLineSegmentIntersectPartition = 1;
              }
              v101 = 0;
              LOBYTE(v178) = doesLineSegmentIntersectPartition;
              if ( !doesLineSegmentIntersectPartition && majorAxis == (_DWORD)v222 )
              {
                array = (hkVector4f *)&v199;
                v178 = v223;
                projection = &projectionMatrix;
                LODWORD(pArr) = majorAxis;
                LODWORD(v175) = (_DWORD)retaddr;
                v101 = `anonymous namespace::collapseMakesCorridorImpassable(
                         b->m_quad.m128_f32[2],
                         b->m_quad.m128_f32[3],
                         v65,
                         v63,
                         v64,
                         (hkVector4f *)&v194,
                         (hkVector4f *)&v195,
                         skipIndex,
                         verticesInOut,
                         (hkRotationf *)segments,
                         v175,
                         (int *)pArr,
                         &projectionMatrix,
                         v223,
                         &v199);
                if ( v199.m_enum )
                  goto LABEL_87;
                doesLineSegmentIntersectPartition = (char)v178;
              }
              if ( (_BYTE)v175 )
                --v21[2];
              if ( !doesLineSegmentIntersectPartition && !v101 )
              {
                if ( !BYTE1(v175) )
                {
                  v110 = v207;
                  v128 = segments;
                  goto LABEL_156;
                }
                v102 = v21[2];
                v103 = v102;
                if ( v102 )
                {
                  v192 = 4 * v102;
                  v104 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerTempAllocator::s_alloc,
                                   &v192);
                  v102 = v192 / 4;
                }
                else
                {
                  v104 = 0i64;
                }
                v105 = 0x80000000;
                if ( v102 )
                  v105 = v102;
                if ( (int)v103 > 0 )
                {
                  v106 = 0i64;
                  v107 = v103;
                  do
                  {
                    v106 += 4i64;
                    *(_DWORD *)&v104[v106 - 4] = *(_DWORD *)(v106 + *(_QWORD *)v21 - 4);
                    --v107;
                  }
                  while ( v107 );
                }
                v108 = v21[2];
                v109 = *(_DWORD **)v21;
                v110 = v207;
                v111 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                         _mm_shuffle_ps(v87, v87, 170));
                v112 = _mm_rsqrt_ps(v111);
                v113 = (v108 + v183 - 1) % v108;
                v114 = (int)a % v108;
                v115 = verticesInOut->m_data;
                v116 = _mm_andnot_ps(
                         _mm_cmple_ps(v111, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v112, v111), v112)),
                           _mm_mul_ps(*(__m128 *)_xmm, v112)));
                v117 = _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0), v207),
                           _mm_mul_ps(v116, v111)),
                         _mm_mul_ps(v116, v86));
                v118 = _mm_add_ps(verticesInOut->m_data[*(int *)(*(_QWORD *)v21 + 4 * v113)].m_quad, v117);
                end = (hkVector4f *)v114;
                v119 = v115[v109[v114]].m_quad;
                v109[v113] = verticesInOut->m_size;
                v120 = _mm_add_ps(v119, v117);
                if ( verticesInOut->m_size == (verticesInOut->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, verticesInOut, 16);
                v121 = end;
                verticesInOut->m_data[verticesInOut->m_size++].m_quad = v118;
                *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (_QWORD)v121) = verticesInOut->m_size;
                if ( verticesInOut->m_size == (verticesInOut->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, verticesInOut, 16);
                verticesInOut->m_data[verticesInOut->m_size++].m_quad = v120;
                v122 = v183;
                --v21[2];
                v123 = *(_QWORD *)v21 + 4 * v122;
                v124 = 4 * (v21[2] - v122);
                if ( v124 > 0 )
                {
                  v125 = ((unsigned int)(v124 - 1) >> 2) + 1;
                  do
                  {
                    v126 = *(_DWORD *)(v123 + 4);
                    v123 += 4i64;
                    *(_DWORD *)(v123 - 4) = v126;
                    --v125;
                  }
                  while ( v125 );
                }
                if ( (_BYTE)v175 )
                {
                  v127 = v21[2];
                  if ( v127 > 0 )
                  {
                    LODWORD(a) = **(_DWORD **)v21;
                    if ( v127 == (v21[3] & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v21, 4);
                    *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (int)v21[2]++) = (_DWORD)a;
                  }
                }
                v209.m_real = m_real;
                v211.m_real = v24;
                v128 = segments;
                `anonymous namespace::computeFullSignedPartitionAreas(
                  verticesInOut,
                  segments,
                  (int)retaddr,
                  majorAxis,
                  (int)v222,
                  &v209,
                  &v211);
                v129 = v21[3] & 0x3FFFFFFF;
                if ( v129 >= (int)v103 )
                {
                  v187.m_enum = HK_SUCCESS;
                }
                else
                {
                  v130 = 2 * v129;
                  v131 = v103;
                  if ( (int)v103 < v130 )
                    v131 = v130;
                  hkArrayUtil::_reserve(&v187, &hkContainerHeapAllocator::s_alloc, v21, v131, 4);
                }
                v21[2] = v103;
                v132 = 0;
                if ( (int)v103 > 0 )
                {
                  v133 = 0i64;
                  do
                  {
                    ++v132;
                    *(_DWORD *)(v133 + *(_QWORD *)v21) = *(_DWORD *)&v104[v133];
                    v133 += 4i64;
                  }
                  while ( v132 < v21[2] );
                }
                v134 = _mm_load_si128((const __m128i *)&v209).m128i_u32[0];
                v135 = _mm_load_si128((const __m128i *)&v208).m128i_u32[0];
                v136 = _mm_load_si128((const __m128i *)&v211).m128i_u32[0];
                verticesInOut->m_size -= 2;
                LODWORD(v137) = (2 * v136) >> 1;
                LODWORD(v138) = (2 * _mm_load_si128((const __m128i *)&v210).m128i_u32[0]) >> 1;
                if ( COERCE_FLOAT((2 * v134) >> 1) < COERCE_FLOAT((2 * v135) >> 1) && (v205 <= 1 || v137 < v138) )
                {
                  if ( v105 >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v104, 4 * v105);
LABEL_156:
                  points.m_size = 0;
                  if ( points.m_capacityAndFlags >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerHeapAllocator::s_alloc,
                      points.m_data,
                      16 * points.m_capacityAndFlags);
                  v144 = v183;
                  if ( v183 == -1 )
                    goto LABEL_141;
                  v145 = v21[2];
                  v146 = _mm_mul_ps(v86, v86);
                  v147 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v146, v146, 85), _mm_shuffle_ps(v146, v146, 0)),
                           _mm_shuffle_ps(v146, v146, 170));
                  v148 = _mm_rsqrt_ps(v147);
                  v149 = (v145 + v183 - 1) % v145;
                  v150 = _mm_andnot_ps(
                           _mm_cmple_ps(v147, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v148, v147), v148)),
                             _mm_mul_ps(*(__m128 *)_xmm, v148)));
                  v151 = _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v110, _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0)),
                             _mm_mul_ps(v150, v147)),
                           _mm_mul_ps(v150, v86));
                  v152 = (v183 + 1) % v145;
                  v153 = verticesInOut->m_size + 2;
                  v154 = _mm_add_ps(verticesInOut->m_data[*(int *)(*(_QWORD *)v21 + 4 * v149)].m_quad, v151);
                  v155 = verticesInOut->m_capacityAndFlags & 0x3FFFFFFF;
                  v156 = _mm_add_ps(verticesInOut->m_data[*(int *)(*(_QWORD *)v21 + 4 * v152)].m_quad, v151);
                  if ( v155 >= v153 )
                  {
                    v189.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v157 = 2 * v155;
                    if ( v153 < v157 )
                      v153 = v157;
                    hkArrayUtil::_reserve(&v189, &hkContainerHeapAllocator::s_alloc, verticesInOut, v153, 16);
                    if ( v189.m_enum )
                      goto LABEL_163;
                  }
                  *(_DWORD *)(*(_QWORD *)v21 + 4 * v149) = verticesInOut->m_size;
                  verticesInOut->m_data[verticesInOut->m_size++].m_quad = v154;
                  *(_DWORD *)(*(_QWORD *)v21 + 4 * v152) = verticesInOut->m_size;
                  verticesInOut->m_data[verticesInOut->m_size++].m_quad = v156;
                  --v21[2];
                  v158 = *(_QWORD *)v21 + 4 * v144;
                  v159 = 4 * (v21[2] - v144);
                  if ( v159 > 0 )
                  {
                    v160 = ((unsigned int)(v159 - 1) >> 2) + 1;
                    do
                    {
                      v161 = *(_DWORD *)(v158 + 4);
                      v158 += 4i64;
                      *(_DWORD *)(v158 - 4) = v161;
                      --v160;
                    }
                    while ( v160 );
                  }
                  v162 = v204;
                  v163 = v128->m_data;
                  --*(int *)((char *)&v163->m_boundary.m_size + v204);
                  v164 = *(int *)((char *)&v163->m_boundary.m_size + v162);
                  v165 = (__int64)&(*(int **)((char *)&v163->m_boundary.m_data + v162))[v144];
                  v166 = 4 * (v164 - v144);
                  if ( v166 > 0 )
                  {
                    v167 = ((unsigned int)(v166 - 1) >> 2) + 1;
                    do
                    {
                      v168 = *(_DWORD *)(v165 + 4);
                      v165 += 4i64;
                      *(_DWORD *)(v165 - 4) = v168;
                      --v167;
                    }
                    while ( v167 );
                  }
                  LODWORD(projection) = 0;
                  if ( SHIDWORD(projection) >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerTempAllocator::s_alloc,
                      pArr,
                      12 * (HIDWORD(projection) & 0x3FFFFFFF));
                  pArr = 0i64;
                  HIDWORD(projection) = 0x80000000;
                  v180 = 0;
                  if ( v181 >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerTempAllocator::s_alloc,
                      array,
                      8 * v181);
                  v28 = (char)v175;
                  array = 0i64;
                  v181 = 0x80000000;
                  goto LABEL_13;
                }
                if ( v105 >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v104, 4 * v105);
              }
            }
          }
        }
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
LABEL_140:
        v57 = &c->m_quad.m128_i8[1];
        ++v184;
        c = (hkVector4f *)((char *)c + 1);
        if ( v184 >= v180 )
          goto LABEL_141;
      }
      if ( majorAxis )
      {
        if ( majorAxis == 1 )
        {
          v68 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 216), (__m128)xmmword_141A71320);
          goto LABEL_66;
        }
        if ( majorAxis == 2 )
          goto LABEL_66;
        if ( majorAxis != 3 )
        {
          if ( majorAxis == 4 )
            v68 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 210), (__m128)xmmword_141A71320);
          else
            v68 = _mm_shuffle_ps(v68, v68, 225);
LABEL_66:
          if ( majorAxis )
          {
            if ( majorAxis == 1 )
            {
              v69 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 216), (__m128)xmmword_141A71320);
              goto LABEL_77;
            }
            if ( majorAxis == 2 )
              goto LABEL_77;
            if ( majorAxis != 3 )
            {
              if ( majorAxis == 4 )
                v69 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 210), (__m128)xmmword_141A71320);
              else
                v69 = _mm_shuffle_ps(v69, v69, 225);
LABEL_77:
              v72 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 225), v69);
              if ( (float)(_mm_shuffle_ps(v72, v72, 0).m128_f32[0] - _mm_shuffle_ps(v72, v72, 85).m128_f32[0]) < 0.0 )
                goto LABEL_140;
              goto LABEL_78;
            }
            v71 = _mm_shuffle_ps(v69, v69, 230);
          }
          else
          {
            v71 = _mm_shuffle_ps(v69, v69, 233);
          }
          v69 = v71;
          goto LABEL_77;
        }
        v70 = _mm_shuffle_ps(v68, v68, 230);
      }
      else
      {
        v70 = _mm_shuffle_ps(v68, v68, 233);
      }
      v68 = v70;
      goto LABEL_66;
    }
  }
LABEL_146:
  if ( v28 )
  {
    v139 = v21[2];
    if ( v139 > 0 )
    {
      v140 = v139 + 1;
      v141 = **(_DWORD **)v21;
      v142 = v21[3] & 0x3FFFFFFF;
      if ( v142 < v140 )
      {
        v143 = 2 * v142;
        if ( v140 < v143 )
          v140 = v143;
        hkArrayUtil::_reserve((hkResult *)&v222, &hkContainerHeapAllocator::s_alloc, v21, v140, 4);
        if ( (_DWORD)v222 )
        {
          v98 = v216;
          *v216 = 1;
          return (hkResult *)v98;
        }
      }
      *(_DWORD *)(*(_QWORD *)v21 + 4i64 * (int)v21[2]++) = v141;
    }
  }
  v98 = v216;
  *v216 = 0;
  return (hkResult *)v98;
}

// File Line: 2919
// RVA: 0xB582E0
hkResult *__fastcall `anonymous namespace::simplifySegment(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkArrayBase<int> *segmentToOppositeMap,
        int segmentIndex,
        int majorAxisA,
        int majorAxisB,
        hkPointerMultiMap<int,int> *parToSegIdxMap,
        hkBitField *unremovableVertices)
{
  hkaiNavMeshSimplificationUtils::Segment *v12; // rbx
  __int64 m_size; // r11
  hkResult *v14; // rax
  hkPointerMultiMap<int,int> *v15; // r15
  int Key; // edi
  int v17; // r11d
  int m_partitionIdA; // edx
  hkaiNavMeshSimplificationUtils::Segment *v19; // r8
  int v20; // ecx
  int m_partitionIdB; // eax
  int v22; // ecx
  int v23; // r9d
  __int64 m_hashMod; // rsi
  int v25; // r9d
  __int64 i; // rdx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v27; // rcx
  signed int v28; // eax
  int v29; // r11d
  int v30; // edi
  int v31; // r8d
  hkaiNavMeshSimplificationUtils::Segment *v32; // rdx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // r9d
  __int64 v37; // rsi
  int v38; // r9d
  __int64 j; // rdx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v40; // rax
  int *v41; // r9
  int v42; // edx
  int v43; // ecx
  int *v44; // rbx
  __int64 v45; // rax
  int v46; // r8d
  __int64 v47; // rbx
  int v48; // r9d
  int v49; // ecx
  hkResultEnum v50; // esi
  int v51; // edi
  __int64 v52; // rbx
  __int64 v53; // r8
  hkVector4f v54; // xmm2
  hkaiNavMeshSimplificationUtils::Segment *v55; // rdx
  int v56; // r10d
  hkVector4f v57; // xmm1
  __int64 v58; // r9
  hkVector4f *m_data; // r11
  int *v60; // rax
  __int64 v61; // rcx
  int v62; // edi
  int v63; // ebx
  bool v64; // al
  hkArrayBase<int> *v65; // rsi
  int v66; // [rsp+28h] [rbp-91h]
  int *array; // [rsp+60h] [rbp-59h] BYREF
  int v68; // [rsp+68h] [rbp-51h]
  int v69; // [rsp+6Ch] [rbp-4Dh]
  hkcdDynamicAabbTree tree; // [rsp+70h] [rbp-49h] BYREF
  hkAabb aabb; // [rsp+90h] [rbp-29h] BYREF
  hkResult resulta; // [rsp+108h] [rbp+4Fh] BYREF

  v12 = &segmentsInOut->m_data[segmentIndex];
  m_size = v12->m_indices.m_size;
  if ( *v12->m_indices.m_data == v12->m_indices.m_data[m_size - 1] && (int)m_size <= 2 )
  {
    v14 = result;
    result->m_enum = HK_SUCCESS;
    return v14;
  }
  v69 = 0x80000000;
  array = 0i64;
  v68 = 0;
  v15 = parToSegIdxMap;
  Key = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                        &parToSegIdxMap->m_map,
                        v12->m_partitionIdA);
  if ( Key <= v15->m_map.m_hashMod )
  {
    v17 = v68;
    do
    {
      m_partitionIdA = v12->m_partitionIdA;
      v19 = &segmentsInOut->m_data[SLODWORD(v15->m_map.m_elem[Key].val)];
      v20 = v19->m_partitionIdA;
      if ( v20 == m_partitionIdA
        || (m_partitionIdB = v12->m_partitionIdB, v20 == m_partitionIdB)
        || m_partitionIdB != -1 && ((v22 = v19->m_partitionIdB, v22 == m_partitionIdA) || v22 == m_partitionIdB) )
      {
        v23 = v17 + 1;
        if ( (v69 & 0x3FFFFFFF) >= v17 + 1 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v23 < 2 * (v69 & 0x3FFFFFFF) )
            v23 = 2 * (v69 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v23, 4);
          if ( resulta.m_enum )
          {
LABEL_39:
            result->m_enum = HK_FAILURE;
            goto LABEL_83;
          }
          v17 = v68;
        }
        array[v17] = v15->m_map.m_elem[Key].val;
        v17 = ++v68;
      }
      m_hashMod = v15->m_map.m_hashMod;
      v25 = Key + 1;
      for ( i = Key + 1; i > m_hashMod; i = 0i64 )
LABEL_24:
        v25 = 0;
      v27 = &v15->m_map.m_elem[i];
      while ( v27->key != -1i64 )
      {
        if ( v27->key == v12->m_partitionIdA )
        {
          Key = v25;
          goto LABEL_27;
        }
        ++i;
        ++v25;
        ++v27;
        if ( i > m_hashMod )
          goto LABEL_24;
      }
      Key = m_hashMod + 1;
LABEL_27:
      ;
    }
    while ( Key <= (int)m_hashMod );
  }
  v28 = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                        &v15->m_map,
                        v12->m_partitionIdB);
  v29 = v68;
  v30 = v28;
  if ( v28 <= v15->m_map.m_hashMod )
  {
    do
    {
      v31 = v12->m_partitionIdA;
      v32 = &segmentsInOut->m_data[SLODWORD(v15->m_map.m_elem[v30].val)];
      v33 = v32->m_partitionIdA;
      if ( v33 == v31
        || (v34 = v12->m_partitionIdB, v33 == v34)
        || v34 != -1 && ((v35 = v32->m_partitionIdB, v35 == v31) || v35 == v34) )
      {
        v36 = v29 + 1;
        if ( (v69 & 0x3FFFFFFF) >= v29 + 1 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v36 < 2 * (v69 & 0x3FFFFFFF) )
            v36 = 2 * (v69 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v36, 4);
          if ( resulta.m_enum )
            goto LABEL_39;
          v29 = v68;
        }
        array[v29] = v15->m_map.m_elem[v30].val;
        v29 = ++v68;
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
    while ( v30 <= (int)v37 );
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
        *v44++ = v46;
        v29 = v68;
        v41 = array;
      }
      ++v43;
      ++v45;
    }
    while ( v43 < v29 );
  }
  v47 = v44 - v41;
  if ( (v69 & 0x3FFFFFFF) < (int)v47 )
  {
    v48 = v47;
    if ( (int)v47 < 2 * (v69 & 0x3FFFFFFF) )
      v48 = 2 * (v69 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v48, 4);
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
        v55 = &segmentsInOut->m_data[v53];
        v56 = 0;
        v57.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       (__m128)xmmword_141A712A0);
        aabb.m_max = (hkVector4f)v57.m_quad;
        if ( v55->m_indices.m_size > 0 )
        {
          v58 = 0i64;
          m_data = verticesInOut->m_data;
          do
          {
            v60 = v55->m_indices.m_data;
            ++v56;
            v61 = v60[v58++];
            v54.m_quad = _mm_min_ps(v54.m_quad, m_data[v60[v58 - 1]].m_quad);
            aabb.m_min = (hkVector4f)v54.m_quad;
            v57.m_quad = _mm_max_ps(v57.m_quad, m_data[v61].m_quad);
            aabb.m_max = (hkVector4f)v57.m_quad;
          }
          while ( v56 < v55->m_indices.m_size );
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
            settings,
            verticesInOut,
            segmentsInOut,
            v50,
            majorAxisA,
            majorAxisB,
            &tree,
            &resulta) == 0;
    if ( resulta.m_enum )
    {
LABEL_75:
      result->m_enum = HK_FAILURE;
      goto LABEL_82;
    }
    if ( !v64 )
      goto LABEL_81;
  }
  v66 = v50;
  v65 = segmentToOppositeMap;
  `anonymous namespace::simplifyInternalOrConvexBoundary(
    &resulta,
    settings,
    (__m128 *)verticesInOut,
    segmentsInOut,
    segmentToOppositeMap,
    v66,
    v62,
    v63,
    &tree,
    v15,
    unremovableVertices);
  if ( resulta.m_enum )
  {
    result->m_enum = HK_FAILURE;
    goto LABEL_82;
  }
  `anonymous namespace::simplifyConcaveBoundary(
    (hkResult *)&segmentIndex,
    settings,
    verticesInOut,
    (hkPointerMultiMap<int,int> *)segmentsInOut,
    v65,
    segmentIndex,
    v62,
    v63,
    &tree,
    v15);
  if ( !segmentIndex )
LABEL_81:
    result->m_enum = HK_SUCCESS;
  else
    result->m_enum = HK_FAILURE;
LABEL_82:
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&tree);
LABEL_83:
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v69);
  return result;
}

// File Line: 3040
// RVA: 0xB4A980
hkResult *__fastcall hkaiNavMeshSimplificationUtils::setSegmentIndices(
        hkResult *result,
        hkaiNavMesh *navMesh,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut,
        hkPointerMap<int,int,hkContainerHeapAllocator> *vertexIndexMapOut)
{
  bool v5; // cc
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v7; // rax
  hkaiNavMesh *v8; // r12
  hkPointerMap<int,int,hkContainerHeapAllocator> *v10; // r14
  __int64 v11; // rdx
  char *v12; // r15
  int v13; // r9d
  int v14; // eax
  int v15; // r9d
  int v16; // eax
  hkaiNavMesh::Edge *v17; // rbp
  unsigned __int64 m_size; // rsi
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  int v22; // ebp
  __int64 v23; // r14
  __int64 v24; // r12
  unsigned __int64 v25; // rsi
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  hkResult resulta; // [rsp+30h] [rbp-58h] BYREF
  hkResult v31; // [rsp+34h] [rbp-54h] BYREF
  hkResult v32; // [rsp+38h] [rbp-50h] BYREF
  int v33; // [rsp+3Ch] [rbp-4Ch]
  hkResult res; // [rsp+40h] [rbp-48h] BYREF
  hkResult v35; // [rsp+44h] [rbp-44h] BYREF
  __int64 v36; // [rsp+48h] [rbp-40h]

  v5 = segmentsInOut->m_size <= 0;
  v7 = segmentsInOut;
  v8 = navMesh;
  v33 = 0;
  if ( v5 )
  {
LABEL_30:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v10 = vertexIndexMapOut;
  v11 = 0i64;
  v36 = 0i64;
  while ( 1 )
  {
    v12 = (char *)v7->m_data + v11;
    v13 = *((_DWORD *)v12 + 6);
    *(_DWORD *)v12 = -1;
    v14 = *((_DWORD *)v12 + 11) & 0x3FFFFFFF;
    v15 = v13 + 1;
    if ( v14 >= v15 )
    {
      resulta.m_enum = HK_SUCCESS;
      goto LABEL_9;
    }
    v16 = 2 * v14;
    if ( v15 < v16 )
      v15 = v16;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v12 + 32, v15, 4);
    if ( resulta.m_enum )
      break;
LABEL_9:
    v17 = &v8->m_edges.m_data[**((int **)v12 + 2)];
    LODWORD(m_size) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                        &v10->m_map,
                        v17->m_a,
                        0xFFFFFFFFFFFFFFFFui64);
    if ( (_DWORD)m_size == -1 )
    {
      m_size = verticesOut->m_size;
      v19 = m_size + 1;
      v20 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v20 >= (int)m_size + 1 )
      {
        v31.m_enum = HK_SUCCESS;
      }
      else
      {
        v21 = 2 * v20;
        if ( v19 < v21 )
          v19 = v21;
        hkArrayUtil::_reserve(&v31, &hkContainerHeapAllocator::s_alloc, verticesOut, v19, 16);
        if ( v31.m_enum )
          break;
      }
      verticesOut->m_data[verticesOut->m_size++] = v8->m_vertices.m_data[v17->m_a];
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        &v10->m_map,
        &hkContainerHeapAllocator::s_alloc,
        v17->m_a,
        m_size,
        &res);
      if ( res.m_enum )
        break;
    }
    v22 = 0;
    *(_DWORD *)(*((_QWORD *)v12 + 4) + 4i64 * (int)(*((_DWORD *)v12 + 10))++) = m_size;
    if ( *((int *)v12 + 6) > 0 )
    {
      v23 = 0i64;
      do
      {
        v24 = (__int64)&v8->m_edges.m_data[*(int *)(v23 + *((_QWORD *)v12 + 2))];
        LODWORD(v25) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         &vertexIndexMapOut->m_map,
                         *(int *)(v24 + 4),
                         0xFFFFFFFFFFFFFFFFui64);
        if ( (_DWORD)v25 == -1 )
        {
          v25 = verticesOut->m_size;
          v26 = v25 + 1;
          v27 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v27 >= (int)v25 + 1 )
          {
            v32.m_enum = HK_SUCCESS;
          }
          else
          {
            v28 = 2 * v27;
            if ( v26 < v28 )
              v26 = v28;
            hkArrayUtil::_reserve(&v32, &hkContainerHeapAllocator::s_alloc, verticesOut, v26, 16);
            if ( v32.m_enum )
              goto LABEL_7;
          }
          verticesOut->m_data[verticesOut->m_size++] = navMesh->m_vertices.m_data[*(int *)(v24 + 4)];
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
            &vertexIndexMapOut->m_map,
            &hkContainerHeapAllocator::s_alloc,
            *(int *)(v24 + 4),
            v25,
            &v35);
          if ( v35.m_enum )
            goto LABEL_7;
        }
        v8 = navMesh;
        *(_DWORD *)(*((_QWORD *)v12 + 4) + 4i64 * (int)(*((_DWORD *)v12 + 10))++) = v25;
        ++v22;
        v23 += 4i64;
      }
      while ( v22 < *((_DWORD *)v12 + 6) );
      v10 = vertexIndexMapOut;
    }
    v7 = segmentsInOut;
    v11 = v36 + 48;
    ++v33;
    v36 += 48i64;
    if ( v33 >= segmentsInOut->m_size )
      goto LABEL_30;
  }
LABEL_7:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 3090
// RVA: 0xB4AC90
hkResult *__fastcall hkaiNavMeshSimplificationUtils::setMaterialSettingsIndices(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *mesh,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitions,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut)
{
  int v11; // edi
  __int64 v12; // rsi
  hkaiNavMeshGenerationSettings::OverrideSettings *m_data; // rax
  int m_size; // esi
  int *v15; // rdx
  __int64 v16; // rdi
  __int64 m_faceDataStriding; // r8
  hkArray<int,hkContainerHeapAllocator> *v18; // r11
  int v19; // r10d
  int v20; // r8d
  int i; // r8d
  __int64 v22; // r9
  int v23; // ecx
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v24; // r12
  int v25; // r14d
  __int64 v26; // r15
  hkaiNavMeshSimplificationUtils::Segment *v27; // rsi
  int v28; // edi
  int v29; // eax
  int v30; // r8d
  char *array; // [rsp+30h] [rbp-28h] BYREF
  int v32; // [rsp+38h] [rbp-20h]
  int v33; // [rsp+3Ch] [rbp-1Ch]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v34; // [rsp+40h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+A8h] [rbp+50h] BYREF

  if ( !numFacesInPartition->m_size )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v34.m_elem = 0i64;
  v11 = 0;
  v34.m_numElems = 0;
  v34.m_hashMod = -1;
  if ( settings->m_overrideSettings.m_size <= 0 )
  {
LABEL_8:
    m_size = numFacesInPartition->m_size;
    v15 = 0i64;
    array = 0i64;
    v32 = 0;
    v33 = 0x80000000;
    v16 = 1i64;
    if ( m_size <= 0 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
      if ( resulta.m_enum )
      {
        v32 = 0;
        result->m_enum = HK_FAILURE;
        if ( v33 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v33);
        array = 0i64;
        v33 = 0x80000000;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &v34,
          &hkContainerHeapAllocator::s_alloc);
        _((AMD_HD3D *)&v34);
        return result;
      }
      v15 = (int *)array;
    }
    m_faceDataStriding = mesh->m_faceDataStriding;
    v18 = partitions;
    v32 = m_size;
    v19 = 0;
    if ( (_DWORD)m_faceDataStriding )
      v20 = mesh->m_faceData.m_data[m_faceDataStriding * *partitions->m_data];
    else
      v20 = 0;
    *v15 = v20;
    for ( i = 1; i < numFacesInPartition->m_size; *(_DWORD *)&array[v16 * 4 - 4] = v23 )
    {
      v22 = mesh->m_faceDataStriding;
      v19 += numFacesInPartition->m_data[v16 - 1];
      if ( (_DWORD)v22 )
        v23 = mesh->m_faceData.m_data[v22 * v18->m_data[v19]];
      else
        v23 = 0;
      ++i;
      ++v16;
    }
    v24 = segmentsInOut;
    v25 = 0;
    if ( segmentsInOut->m_size <= 0 )
    {
LABEL_38:
      v30 = v33;
      v32 = 0;
      result->m_enum = HK_SUCCESS;
      if ( v30 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v30);
      array = 0i64;
      v33 = 0x80000000;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v34,
        &hkContainerHeapAllocator::s_alloc);
      _((AMD_HD3D *)&v34);
      return result;
    }
    v26 = 0i64;
    while ( 1 )
    {
      v27 = &v24->m_data[v26];
      v28 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v34,
              *(int *)&array[4 * v27->m_partitionIdA],
              0xFFFFFFFFFFFFFFFFui64);
      if ( v27->m_partitionIdB == -1 )
        v29 = -1;
      else
        v29 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v34,
                *(int *)&array[4 * v27->m_partitionIdB],
                0xFFFFFFFFFFFFFFFFui64);
      if ( v28 == -1 )
      {
        if ( v29 != -1 )
          goto LABEL_36;
      }
      else
      {
        if ( v29 != -1 )
        {
          if ( v28 < v29 )
            v29 = v28;
LABEL_36:
          v27->m_materialSettingsIndex = v29;
          goto LABEL_37;
        }
        v27->m_materialSettingsIndex = v28;
      }
LABEL_37:
      ++v25;
      ++v26;
      if ( v25 >= v24->m_size )
        goto LABEL_38;
    }
  }
  v12 = 0i64;
  while ( 1 )
  {
    m_data = settings->m_overrideSettings.m_data;
    if ( !m_data[v12].m_volume.m_pntr )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        &v34,
        &hkContainerHeapAllocator::s_alloc,
        m_data[v12].m_material,
        v11,
        &resulta);
      if ( resulta.m_enum )
        break;
    }
    ++v11;
    ++v12;
    if ( v11 >= settings->m_overrideSettings.m_size )
      goto LABEL_8;
  }
  result->m_enum = HK_FAILURE;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v34,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v34);
  return result;
}

// File Line: 3166
// RVA: 0xB4AFA0
hkResult *__fastcall hkaiNavMeshSimplificationUtils::simplifySegments(
        hkResult *result,
        __m128i *settings,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkArray<int,hkContainerHeapAllocator> *segmentToOppositeMap,
        hkaiNavMesh *navMesh,
        hkBitField *unremovableVertices,
        hkArray<int,hkContainerHeapAllocator> *partitionDir,
        hkaiNavMeshGenerationProgressCallback *callbacks)
{
  __int64 v9; // r13
  const __m128i *v11; // r12
  SegmentPtrIdxKey *v12; // rdi
  int v14; // r10d
  int v15; // r14d
  __int64 v16; // rsi
  int v17; // r9d
  hkaiNavMeshSimplificationUtils::Segment *m_data; // rax
  SegmentPtrIdxKey *v19; // rdx
  __int64 m_partitionIdB; // rdi
  __int64 m_partitionIdA; // r8
  unsigned __int64 v22; // rcx
  hkArray<int,hkContainerHeapAllocator> *v23; // r11
  int m_size; // r9d
  int v25; // r8d
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  __int64 v31; // rdx
  __int64 v32; // rcx
  int *v33; // rdi
  __int64 v34; // r15
  int v35; // r12d
  int v36; // r14d
  __int64 v37; // rsi
  bool v38; // al
  hkArray<int,hkContainerHeapAllocator> *v39; // r11
  __int64 v40; // r15
  __m128i si128; // xmm4
  __m128 v42; // xmm6
  unsigned int v43; // r14d
  int v44; // esi
  int v45; // edi
  __m128 v46; // xmm3
  hkResultEnum majorAxisA; // r13d
  int v48; // eax
  hkArray<int,hkContainerHeapAllocator> *v49; // r9
  hkResultEnum v50; // eax
  int v51; // r12d
  int v52; // r15d
  __int64 v53; // rcx
  hkArray<int,hkContainerHeapAllocator> *v54; // r8
  hkArray<int,hkContainerHeapAllocator> *v55; // r12
  hkVector4f *v56; // rax
  __m128 v57; // xmm4
  __m128 v58; // xmm3
  int v59; // r9d
  hkResult *v60; // rdi
  int v61; // r8d
  DuplicateVertexRef *v62; // rdi
  int v63; // r9d
  int v64; // r9d
  int v65; // r14d
  int v66; // r9d
  _DWORD *v67; // rdi
  int v68; // r8d
  __int64 v69; // rdx
  int m_index; // ecx
  int v71; // edi
  __int64 v72; // rsi
  hkaiNavMeshSimplificationUtils::Segment *v73; // r14
  int v74; // edi
  int v75; // r8d
  int v76; // edx
  __int64 v77; // rdi
  hkArray<int,hkContainerHeapAllocator> *v78; // r15
  unsigned __int64 v79; // r14
  unsigned __int64 segmentIndex; // r14
  int v81; // edi
  hkVector4f *v82; // rax
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  hkResultEnum majorAxisB; // edx
  __int64 v86; // rcx
  hkVector4f *v87; // rax
  __m128 v88; // xmm4
  __m128 v89; // xmm3
  hkaiNavMeshSimplificationUtils::Segment *v90; // rcx
  unsigned __int64 v91; // r14
  unsigned __int64 v92; // rsi
  __int64 v93; // r15
  hkaiNavMeshSimplificationUtils::Segment *v94; // rdi
  int v95; // eax
  int v96; // eax
  int v97; // r9d
  hkaiNavMeshSimplificationUtils::Segment *v98; // r13
  int v99; // edi
  int v100; // eax
  int v101; // eax
  int v102; // r9d
  __int64 v103; // rdi
  __int64 v104; // r8
  int v105; // r8d
  void *src; // [rsp+50h] [rbp-B0h] BYREF
  int v107; // [rsp+58h] [rbp-A8h]
  int v108; // [rsp+5Ch] [rbp-A4h]
  hkResult resOut; // [rsp+60h] [rbp-A0h] BYREF
  DuplicateVertexRef *pArr; // [rsp+68h] [rbp-98h] BYREF
  int v111; // [rsp+70h] [rbp-90h]
  int v112; // [rsp+74h] [rbp-8Ch]
  hkVector4f array; // [rsp+80h] [rbp-80h] BYREF
  hkResult v114; // [rsp+90h] [rbp-70h] BYREF
  hkResult v115; // [rsp+94h] [rbp-6Ch] BYREF
  int *v116; // [rsp+98h] [rbp-68h] BYREF
  int v117; // [rsp+A0h] [rbp-60h]
  int v118; // [rsp+A4h] [rbp-5Ch]
  hkResult v119[2]; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v120; // [rsp+B0h] [rbp-50h] BYREF
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> parToSegIdxMap; // [rsp+B8h] [rbp-48h] BYREF
  hkSimdFloat32 v122; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f v123; // [rsp+E0h] [rbp-20h] BYREF
  hkVector4f v124; // [rsp+F0h] [rbp-10h] BYREF
  hkaiNavMeshGenerationProgressCallbackContext v125; // [rsp+100h] [rbp+0h] BYREF
  hkResult resulta; // [rsp+1F8h] [rbp+F8h] BYREF

  v9 = 0i64;
  v11 = settings;
  v12 = 0i64;
  array.m_quad.m128_u64[0] = 0i64;
  v14 = 0;
  array.m_quad.m128_u64[1] = 0x8000000000000000ui64;
  v15 = 0;
  if ( segmentsInOut->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      if ( segmentsInOut->m_data[v16].m_partitionIdB != -1 )
      {
        v17 = v14 + 1;
        if ( (array.m_quad.m128_i32[3] & 0x3FFFFFFF) >= v14 + 1 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v17 < 2 * (array.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            v17 = 2 * (array.m_quad.m128_i32[3] & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v17, 16);
          if ( resulta.m_enum )
            goto LABEL_22;
          v14 = array.m_quad.m128_i32[2];
          v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
        }
        if ( v14 == (array.m_quad.m128_i32[3] & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 16);
          v14 = array.m_quad.m128_i32[2];
          v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
        }
        m_data = segmentsInOut->m_data;
        array.m_quad.m128_i32[2] = v14 + 1;
        v19 = &v12[v14];
        v19->m_segmentSize = m_data[v16].m_indices.m_size;
        v19->m_index = v15;
        m_partitionIdB = segmentsInOut->m_data[v16].m_partitionIdB;
        m_partitionIdA = segmentsInOut->m_data[v16].m_partitionIdA;
        if ( (int)m_partitionIdA >= (int)m_partitionIdB )
          v22 = m_partitionIdA | (m_partitionIdB << 32);
        else
          v22 = m_partitionIdB | (m_partitionIdA << 32);
        v19->m_key = v22;
        v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
        v14 = array.m_quad.m128_i32[2];
      }
      ++v15;
      ++v16;
    }
    while ( v15 < segmentsInOut->m_size );
  }
  if ( v14 > 1 )
  {
    hkAlgorithm::quickSortRecursive<`anonymous namespace::SegmentPtrIdxKey,hkAlgorithm::less<`anonymous namespace::SegmentPtrIdxKey>>(
      v12,
      0,
      v14 - 1,
      0);
    v14 = array.m_quad.m128_i32[2];
    v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
  }
  v23 = segmentToOppositeMap;
  m_size = segmentsInOut->m_size;
  if ( (segmentToOppositeMap->m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    v114.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v114, &hkContainerHeapAllocator::s_alloc, segmentToOppositeMap, m_size, 4);
    if ( v114.m_enum )
    {
LABEL_22:
      v25 = array.m_quad.m128_i32[3];
      result->m_enum = HK_FAILURE;
      array.m_quad.m128_i32[2] = 0;
      if ( v25 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)array.m_quad.m128_u64[0],
          16 * v25);
      return result;
    }
    v14 = array.m_quad.m128_i32[2];
    v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
    v23 = segmentToOppositeMap;
  }
  v27 = segmentsInOut->m_size;
  v28 = v23->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v28 < v27 )
  {
    v29 = 2 * v28;
    v30 = segmentsInOut->m_size;
    if ( v27 < v29 )
      v30 = v29;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v23, v30, 4);
    v14 = array.m_quad.m128_i32[2];
    v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
    v23 = segmentToOppositeMap;
  }
  v31 = v23->m_size;
  v32 = v27 - (int)v31;
  if ( v27 - (int)v31 > 0 )
  {
    v33 = &v23->m_data[v31];
    while ( v32 )
    {
      *v33++ = -1;
      --v32;
    }
    v14 = array.m_quad.m128_i32[2];
    v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
  }
  v23->m_size = v27;
  resulta.m_enum = HK_SUCCESS;
  if ( v14 - 1 > 0 )
  {
    v34 = 1i64;
    *(_QWORD *)&v119[0].m_enum = 1i64;
    v35 = 1;
    do
    {
      v36 = v35;
      if ( v35 < v14 )
      {
        v37 = v9 * 16 + 16;
        while ( v12[v9].m_key == *(unsigned __int64 *)((char *)&v12->m_key + v37)
             && v12[v9].m_segmentSize == *(int *)((char *)&v12->m_segmentSize + v37) )
        {
          v38 = `anonymous namespace::areOppositeSegments(
                  verticesInOut,
                  &segmentsInOut->m_data[v12[v9].m_index],
                  &segmentsInOut->m_data[*(int *)((char *)&v12->m_index + v37)],
                  navMesh,
                  &resOut);
          if ( resOut.m_enum )
          {
            v60 = result;
            v61 = array.m_quad.m128_i32[3];
            array.m_quad.m128_i32[2] = 0;
            result->m_enum = HK_FAILURE;
            if ( v61 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                (void *)array.m_quad.m128_u64[0],
                16 * v61);
            return v60;
          }
          if ( v38 )
          {
            v39 = segmentToOppositeMap;
            v40 = 2 * v34;
            segmentToOppositeMap->m_data[*(int *)(array.m_quad.m128_u64[0] + v9 * 16 + 4)] = *(_DWORD *)(array.m_quad.m128_u64[0] + 8 * v40 + 4);
            v39->m_data[*(int *)(array.m_quad.m128_u64[0] + 8 * v40 + 4)] = *(_DWORD *)(array.m_quad.m128_u64[0]
                                                                                      + v9 * 16
                                                                                      + 4);
            v14 = array.m_quad.m128_i32[2];
            v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
            break;
          }
          v14 = array.m_quad.m128_i32[2];
          v12 = (SegmentPtrIdxKey *)array.m_quad.m128_u64[0];
          ++v36;
          ++v34;
          v37 += 16i64;
          if ( v36 >= array.m_quad.m128_i32[2] )
            break;
        }
      }
      v34 = *(_QWORD *)&v119[0].m_enum + 1i64;
      ++v35;
      ++v9;
      ++resulta.m_enum;
      ++*(_QWORD *)&v119[0].m_enum;
    }
    while ( resulta.m_enum < v14 - 1 );
    v11 = settings;
  }
  array.m_quad.m128_i32[2] = 0;
  if ( array.m_quad.m128_i32[3] >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v12,
      16 * array.m_quad.m128_i32[3]);
  si128 = _mm_load_si128(v11 + 1);
  v42 = (__m128)xmmword_141A4C9F0;
  v43 = 0x80000000;
  pArr = 0i64;
  v44 = 0;
  v111 = 0;
  src = 0i64;
  v45 = 0;
  v107 = 0;
  v112 = 0x80000000;
  v46 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
  v108 = 0x80000000;
  majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmple_ps(
                                                                          _mm_max_ps(
                                                                            _mm_shuffle_ps(v46, v46, 170),
                                                                            _mm_max_ps(
                                                                              _mm_shuffle_ps(v46, v46, 85),
                                                                              _mm_shuffle_ps(v46, v46, 0))),
                                                                          v46),
                                                                        (__m128)xmmword_141A4C9F0))];
  resulta.m_enum = majorAxisA;
  v48 = _mm_movemask_ps(_mm_cmplt_ps((__m128)si128, (__m128)0i64));
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
  v114.m_enum = v50;
  v52 = 0;
  if ( segmentsInOut->m_size > 0 )
  {
    v53 = 0i64;
    *(_QWORD *)&v119[0].m_enum = 0i64;
    while ( 1 )
    {
      v54 = (hkArray<int,hkContainerHeapAllocator> *)((char *)segmentsInOut->m_data + v53);
      v55 = v54 + 2;
      if ( *v54[2].m_data == v54[2].m_data[v54[2].m_size - 1] )
      {
        if ( v49 )
        {
          v56 = hkaiNavMeshSimplificationUtils::_classToDir(&array, v49->m_data[SHIDWORD(v54->m_data)]);
          v57 = _mm_cmplt_ps(v56->m_quad, (__m128)0i64);
          v58 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v56->m_quad, 1u), 1u);
          majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                              _mm_and_ps(
                                                                                _mm_cmple_ps(
                                                                                  _mm_max_ps(
                                                                                    _mm_shuffle_ps(v58, v58, 170),
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v58, v58, 85),
                                                                                      _mm_shuffle_ps(v58, v58, 0))),
                                                                                  v58),
                                                                                v42))];
          resulta.m_enum = majorAxisA;
          LODWORD(v56) = _mm_movemask_ps(v57);
          if ( _bittest((const int *)&v56, majorAxisA) )
          {
            majorAxisA += 3;
            resulta.m_enum = majorAxisA;
          }
        }
        v59 = v44 + 1;
        if ( (int)(v43 & 0x3FFFFFFF) >= v44 + 1 )
        {
          v115.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v59 < (int)(2 * (v43 & 0x3FFFFFFF)) )
            v59 = 2 * (v43 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v115, &hkContainerHeapAllocator::s_alloc, &pArr, v59, 8);
          if ( v115.m_enum )
            goto LABEL_80;
          v43 = v112;
          v44 = v111;
        }
        if ( v44 == (v43 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &pArr, 8);
          v44 = v111;
        }
        v62 = &pArr[v44];
        v111 = v44 + 1;
        LODWORD(v62->m_value) = (2
                               * _mm_load_si128((const __m128i *)`anonymous namespace::computeSignedLoopArea(
                                                                   &v122,
                                                                   verticesInOut,
                                                                   v55,
                                                                   majorAxisA)).m128i_u32[0]) >> 1;
        v62->m_index = v52;
        v45 = v107;
      }
      else
      {
        v63 = v45 + 1;
        if ( (v108 & 0x3FFFFFFF) >= v45 + 1 )
        {
          resOut.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v63 < 2 * (v108 & 0x3FFFFFFF) )
            v63 = 2 * (v108 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resOut, &hkContainerHeapAllocator::s_alloc, &src, v63, 4);
          if ( resOut.m_enum )
          {
LABEL_80:
            v60 = result;
            result->m_enum = HK_FAILURE;
            goto LABEL_158;
          }
          v45 = v107;
        }
        *((_DWORD *)src + v45) = v52;
        v45 = ++v107;
      }
      v44 = v111;
      ++v52;
      v53 = *(_QWORD *)&v119[0].m_enum + 48i64;
      *(_QWORD *)&v119[0].m_enum += 48i64;
      if ( v52 >= segmentsInOut->m_size )
        break;
      v43 = v112;
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
    v44 = v111;
    v45 = v107;
  }
  v64 = v45 + v44;
  if ( (v108 & 0x3FFFFFFF) >= v45 + v44 )
  {
    v120.m_enum = HK_SUCCESS;
  }
  else
  {
    if ( v64 < 2 * (v108 & 0x3FFFFFFF) )
      v64 = 2 * (v108 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v120, &hkContainerHeapAllocator::s_alloc, &src, v64, 4);
    if ( v120.m_enum )
    {
      v60 = result;
      result->m_enum = HK_FAILURE;
LABEL_89:
      v107 = 0;
      if ( v108 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, src, 4 * v108);
      src = 0i64;
      v111 = 0;
      goto LABEL_161;
    }
    v44 = v111;
    v45 = v107;
  }
  if ( v44 > 0 )
  {
    v65 = v45 + v44;
    if ( v45 + v44 > (v108 & 0x3FFFFFFF) )
    {
      v66 = v45 + v44;
      if ( v65 < 2 * (v108 & 0x3FFFFFFF) )
        v66 = 2 * (v108 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resOut, &hkContainerHeapAllocator::s_alloc, &src, v66, 4);
    }
    hkMemUtil::memMove((char *)src + 4 * v44, src, 4 * v45);
    v67 = src;
    v107 = v65;
    v68 = 0;
    if ( v111 > 0 )
    {
      v69 = 0i64;
      do
      {
        ++v68;
        ++v67;
        m_index = pArr[v69++].m_index;
        *(v67 - 1) = m_index;
      }
      while ( v68 < v111 );
    }
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
  if ( !parToSegIdxMap.m_elem )
  {
LABEL_103:
    v60 = result;
    result->m_enum = HK_FAILURE;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
    goto LABEL_89;
  }
  v71 = 0;
  if ( segmentsInOut->m_size > 0 )
  {
    v72 = 0i64;
    do
    {
      v73 = segmentsInOut->m_data;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
        &parToSegIdxMap,
        &resOut,
        segmentsInOut->m_data[v72].m_partitionIdA,
        v71);
      if ( resOut.m_enum )
        goto LABEL_103;
      if ( v73[v72].m_partitionIdB != -1 )
      {
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
          &parToSegIdxMap,
          &v115,
          v73[v72].m_partitionIdB,
          v71);
        if ( v115.m_enum )
          goto LABEL_103;
      }
      ++v71;
      ++v72;
    }
    while ( v71 < segmentsInOut->m_size );
  }
  v74 = segmentsInOut->m_size;
  v116 = 0i64;
  v117 = 0;
  v118 = 0x80000000;
  if ( v74 <= 0 )
  {
    resOut.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resOut, &hkContainerTempAllocator::s_alloc, &v116, v74, 4);
    if ( resOut.m_enum )
    {
      v60 = result;
      v75 = v118;
      v117 = 0;
      result->m_enum = HK_FAILURE;
      if ( v75 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v116, 4 * v75);
      v116 = 0i64;
      v118 = 0x80000000;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
      goto LABEL_89;
    }
  }
  v117 = v74;
  v76 = 0;
  if ( v107 <= 0 )
    goto LABEL_154;
  v77 = 0i64;
  do
  {
    v77 += 4i64;
    v116[*(int *)((char *)src + v77 - 4)] = v76++;
  }
  while ( v76 < v107 );
  if ( v107 <= 0 )
  {
LABEL_154:
    v60 = result;
    result->m_enum = HK_SUCCESS;
LABEL_155:
    v117 = 0;
    if ( v118 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v116, 4 * v118);
    v116 = 0i64;
    v118 = 0x80000000;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
LABEL_158:
    v107 = 0;
    if ( v108 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, src, 4 * v108);
    v111 = 0;
    src = 0i64;
  }
  else
  {
    v78 = segmentToOppositeMap;
    v79 = 0i64;
    v122.m_real.m128_u64[0] = 0i64;
    while ( 1 )
    {
      hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(
        &v125,
        (hkaiNavMeshGenerationSettings *)settings);
      if ( callbacks )
      {
        if ( v51 == 99 * (v51 / 99)
          && !callbacks->vfptr->stepMiddleCallback(
                callbacks,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
                v51,
                v107,
                &v125) )
        {
          break;
        }
      }
      segmentIndex = *(int *)((char *)src + v79);
      if ( (_DWORD)segmentIndex != -1 )
      {
        v81 = v78->m_data[segmentIndex];
        if ( v81 != -1 || segmentsInOut->m_data[segmentIndex].m_partitionIdB == -1 )
        {
          if ( v81 <= (int)segmentIndex )
            v81 = -1;
          if ( partitionDir )
          {
            v82 = hkaiNavMeshSimplificationUtils::_classToDir(
                    &v123,
                    partitionDir->m_data[segmentsInOut->m_data[segmentIndex].m_partitionIdA]);
            v83 = _mm_cmplt_ps(v82->m_quad, (__m128)0i64);
            v84 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v82->m_quad, 1u), 1u);
            majorAxisA = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                _mm_and_ps(
                                                                                  _mm_cmple_ps(
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v84, v84, 170),
                                                                                      _mm_max_ps(
                                                                                        _mm_shuffle_ps(v84, v84, 85),
                                                                                        _mm_shuffle_ps(v84, v84, 0))),
                                                                                    v84),
                                                                                  (__m128)xmmword_141A4C9F0))];
            resulta.m_enum = majorAxisA;
            LODWORD(v82) = _mm_movemask_ps(v83);
            if ( _bittest((const int *)&v82, majorAxisA) )
            {
              majorAxisA += 3;
              resulta.m_enum = majorAxisA;
            }
            majorAxisB = -1;
            v114.m_enum = -1;
            v86 = segmentsInOut->m_data[segmentIndex].m_partitionIdB;
            if ( (_DWORD)v86 != -1 )
            {
              v87 = hkaiNavMeshSimplificationUtils::_classToDir(&v124, partitionDir->m_data[v86]);
              v88 = _mm_cmplt_ps(v87->m_quad, (__m128)0i64);
              v89 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v87->m_quad, 1u), 1u);
              majorAxisB = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                  _mm_and_ps(
                                                                                    _mm_cmple_ps(
                                                                                      _mm_max_ps(
                                                                                        _mm_shuffle_ps(v89, v89, 170),
                                                                                        _mm_max_ps(
                                                                                          _mm_shuffle_ps(v89, v89, 85),
                                                                                          _mm_shuffle_ps(v89, v89, 0))),
                                                                                      v89),
                                                                                    (__m128)xmmword_141A4C9F0))];
              v114.m_enum = majorAxisB;
              LODWORD(v87) = _mm_movemask_ps(v88);
              if ( _bittest((const int *)&v87, majorAxisB) )
              {
                majorAxisB += 3;
                v114.m_enum = majorAxisB;
              }
            }
          }
          else
          {
            majorAxisB = v114.m_enum;
          }
          `anonymous namespace::simplifySegment(
            &resOut,
            (hkaiNavMeshGenerationSettings *)settings,
            verticesInOut,
            segmentsInOut,
            segmentToOppositeMap,
            segmentIndex,
            majorAxisA,
            majorAxisB,
            (hkPointerMultiMap<int,int> *)&parToSegIdxMap,
            unremovableVertices);
          if ( resOut.m_enum )
          {
            v60 = result;
            result->m_enum = HK_FAILURE;
            goto LABEL_155;
          }
          if ( v81 != -1 )
          {
            v90 = segmentsInOut->m_data;
            array.m_quad.m128_u64[0] = v81;
            v91 = segmentIndex;
            v92 = v81;
            v90[v92].m_partitionIdA = v90[v91].m_partitionIdB;
            segmentsInOut->m_data[v92].m_partitionIdB = segmentsInOut->m_data[v91].m_partitionIdA;
            v93 = segmentsInOut->m_data[v91].m_indices.m_size;
            v94 = &segmentsInOut->m_data[v81];
            v95 = v94->m_indices.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v95 >= (int)v93 )
            {
              v115.m_enum = HK_SUCCESS;
            }
            else
            {
              v96 = 2 * v95;
              v97 = segmentsInOut->m_data[v91].m_indices.m_size;
              if ( (int)v93 < v96 )
                v97 = v96;
              hkArrayUtil::_reserve(&v115, &hkContainerHeapAllocator::s_alloc, &v94->m_indices, v97, 4);
            }
            v94->m_indices.m_size = v93;
            v98 = segmentsInOut->m_data;
            v99 = v93 - 1;
            v100 = segmentsInOut->m_data[v92].m_boundary.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v100 >= (int)v93 - 1 )
            {
              v119[0].m_enum = HK_SUCCESS;
            }
            else
            {
              v101 = 2 * v100;
              v102 = v93 - 1;
              if ( v99 < v101 )
                v102 = v101;
              hkArrayUtil::_reserve(v119, &hkContainerHeapAllocator::s_alloc, &v98[v92].m_boundary, v102, 4);
            }
            v98[v92].m_boundary.m_size = v99;
            v103 = 0i64;
            if ( (int)v93 > 0 )
            {
              v104 = v93;
              do
                segmentsInOut->m_data[v92].m_indices.m_data[v103++] = segmentsInOut->m_data[v91].m_indices.m_data[--v104];
              while ( v103 < v93 );
            }
            majorAxisA = resulta.m_enum;
            *((_DWORD *)src + v116[array.m_quad.m128_u64[0]]) = -1;
          }
          v78 = segmentToOppositeMap;
        }
      }
      ++v51;
      v79 = v122.m_real.m128_u64[0] + 4;
      v122.m_real.m128_u64[0] += 4i64;
      if ( v51 >= v107 )
        goto LABEL_154;
    }
    v60 = result;
    v105 = v118;
    result->m_enum = HK_SUCCESS;
    v117 = 0;
    if ( v105 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v116, 4 * v105);
    v116 = 0i64;
    v118 = 0x80000000;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
    v107 = 0;
    if ( v108 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, src, 4 * v108);
    src = 0i64;
    v111 = 0;
  }
LABEL_161:
  v108 = 0x80000000;
  if ( v112 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 8 * v112);
  return v60;
} v117 = 0;
    if ( v105 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v116, 4 * v105);
    v116 = 0i64;
    v118 = 0x80000000;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&parToSegIdxMap);
    v107 = 0;
    if ( v108 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr

// File Line: 3521
// RVA: 0xB4EA80
hkResult *__fastcall hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *mesh,
        hkaiEdgeGeometryRaycaster *raycaster,
        hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupOut,
        hkArrayBase<unsigned int> *edgesToRemoveOut,
        hkBitField *removableEdges)
{
  hkaiNavMesh *v7; // r13
  hkResult *v8; // r12
  __m128 m_characterHeight_low; // xmm1
  __m128 v11; // xmm12
  int v12; // ecx
  int v13; // edi
  __m128 v14; // xmm11
  unsigned int v15; // edx
  __m128 v16; // xmm13
  __int64 v17; // rbx
  int v18; // r9d
  int v19; // edx
  int v20; // r14d
  int v21; // r15d
  __int64 v22; // r12
  hkaiNavMesh::Edge *m_data; // rbx
  __int64 v24; // rcx
  __int64 v25; // rdi
  int KeyWithValue; // eax
  int v27; // eax
  int v28; // ecx
  unsigned int v29; // eax
  hkResult *v30; // rdi
  int v31; // eax
  int v32; // eax
  int v33; // r9d
  char *v34; // rdi
  int v35; // eax
  unsigned __int64 v36; // rcx
  __int64 v37; // rdx
  int m_capacity; // r12d
  hkaiNavMesh::Edge *v39; // r13
  __int64 v40; // rax
  __int64 v41; // rbx
  int m_head; // edi
  int m_tail; // r14d
  int m_elementsInUse; // r15d
  int v45; // edx
  int m_a; // ecx
  int v47; // r15d
  __int64 v48; // rdx
  int v49; // r14d
  int v50; // edx
  int m_b; // ecx
  __int64 v52; // rdx
  int v53; // r14d
  int v54; // r15d
  __int64 v55; // rcx
  unsigned __int64 v56; // rdx
  __int64 v57; // rbx
  int Key; // eax
  int m_hashMod; // r10d
  int v60; // r13d
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // r9
  __int64 val_low; // rdx
  hkaiNavMesh::Edge *v63; // rdi
  int v64; // eax
  int v65; // edx
  int v66; // ecx
  __int64 v67; // rdx
  int v68; // ecx
  int v69; // r9d
  int v70; // edi
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v72; // rax
  int v73; // edi
  unsigned int *v74; // rcx
  hkaiNavMesh::Edge *v75; // rdx
  __int64 v76; // r8
  hkVector4f *v77; // rcx
  int v78; // r8d
  hkBaseObjectVtbl *vfptr; // rdx
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
  int v92; // r9d
  int v93; // r11d
  __int64 v94; // r9
  __int64 v95; // r10
  hkaiNavMesh::Edge *v96; // rdx
  hkVector4f *v97; // r8
  __int64 v98; // rdi
  __int64 v99; // rcx
  int j; // edi
  hkResult *v101; // rax
  int m_size; // edi
  __m128 v103; // xmm1
  __m128 v104; // xmm4
  __m128 v105; // xmm3
  hkVector4f *v106; // rax
  __int64 v107; // rcx
  __m128 m_quad; // xmm0
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
  int v136; // edx
  __int64 v137; // r8
  __int64 v138; // rcx
  __m128 v139; // xmm4
  __m128 v140; // xmm1
  __m128 v141; // xmm5
  __m128 v142; // xmm1
  __m128 v143; // xmm2
  __m128 v144; // xmm3
  __m128 v145; // xmm3
  __m128 v146; // xmm2
  __m128 v147; // xmm2
  __m128 v148; // xmm1
  __m128 v149; // xmm13
  float v150; // xmm6_4
  float m_boundaryEdgeFilterThreshold; // xmm1_4
  __m128 y_low; // xmm7
  __m128 x_low; // xmm10
  __m128 v154; // xmm11
  __m128 v155; // xmm12
  __m128 v156; // xmm1
  __m128 v157; // xmm4
  __m128 v158; // xmm3
  __m128 v159; // xmm1
  __m128 v160; // xmm4
  __m128 v161; // xmm7
  __m128 v162; // xmm9
  __m128 v163; // xmm8
  __m128 v164; // xmm1
  __m128 v165; // xmm4
  __m128 v166; // xmm2
  __m128 v167; // xmm3
  __m128 v168; // xmm6
  __m128 v169; // xmm1
  __m128 v170; // xmm5
  __m128 v171; // xmm5
  __m128 v172; // xmm1
  __m128 v173; // xmm3
  __m128 v174; // xmm2
  __m128 v175; // xmm4
  __m128 v176; // xmm13
  __m128 v177; // xmm11
  __m128 v178; // xmm10
  __m128 v179; // xmm7
  __m128 v180; // xmm8
  __m128 v181; // xmm9
  __m128 v182; // xmm1
  __m128 v183; // xmm4
  __m128 v184; // xmm2
  __m128 v185; // xmm3
  __m128 v186; // xmm6
  __m128 v187; // xmm1
  __m128 v188; // xmm3
  __m128 v189; // xmm3
  __m128 v190; // xmm1
  __m128 v191; // xmm2
  __m128 v192; // xmm0
  __m128 v193; // xmm1
  unsigned int v194; // eax
  int m_capacityAndFlags; // r8d
  int v196; // r9d
  int v197; // eax
  int v198; // eax
  int v199; // ecx
  int v200; // r9d
  int v201; // eax
  int v202; // eax
  int v203; // r9d
  __int64 v204; // r8
  __int64 v205; // rcx
  int v206; // r8d
  unsigned int *a; // [rsp+30h] [rbp-D0h] BYREF
  int numtoinsert; // [rsp+38h] [rbp-C8h]
  int v209; // [rsp+3Ch] [rbp-C4h]
  char *v210; // [rsp+40h] [rbp-C0h] BYREF
  int v211; // [rsp+48h] [rbp-B8h]
  int v212; // [rsp+4Ch] [rbp-B4h]
  _DWORD *array; // [rsp+50h] [rbp-B0h] BYREF
  int numElem; // [rsp+58h] [rbp-A8h]
  int v215; // [rsp+5Ch] [rbp-A4h]
  hkArrayBase<hkVector4f> v216; // [rsp+60h] [rbp-A0h] BYREF
  hkArrayBase<hkVector2f> v217; // [rsp+70h] [rbp-90h] BYREF
  hkResult v218; // [rsp+80h] [rbp-80h] BYREF
  hkQueue<hkpRigidBody *> v219; // [rsp+88h] [rbp-78h] BYREF
  hkResult resulta; // [rsp+A0h] [rbp-60h] BYREF
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v221; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v222; // [rsp+B8h] [rbp-48h] BYREF
  hkResult v223; // [rsp+BCh] [rbp-44h] BYREF
  hkResult v224; // [rsp+C0h] [rbp-40h] BYREF
  hkResult v225; // [rsp+C4h] [rbp-3Ch] BYREF
  hkResult v226; // [rsp+C8h] [rbp-38h] BYREF
  hkResult v227; // [rsp+CCh] [rbp-34h] BYREF
  hkVector2f e1Out; // [rsp+D0h] [rbp-30h] BYREF
  hkVector2f e0Out; // [rsp+D8h] [rbp-28h] BYREF
  hkVector2f centerOut; // [rsp+E0h] [rbp-20h] BYREF
  hkQuaternionf quat; // [rsp+F0h] [rbp-10h] BYREF
  int v232; // [rsp+100h] [rbp+0h]
  __int64 v233; // [rsp+108h] [rbp+8h]
  int v234; // [rsp+110h] [rbp+10h]
  unsigned int v235; // [rsp+114h] [rbp+14h]
  int v236; // [rsp+118h] [rbp+18h]
  hkResult resOut; // [rsp+11Ch] [rbp+1Ch] BYREF
  hkVector4f planeOut; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f extrusion; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f v240; // [rsp+140h] [rbp+40h] BYREF
  __int64 v241; // [rsp+150h] [rbp+50h]
  hkResult v242; // [rsp+158h] [rbp+58h] BYREF
  hkVector4f v243; // [rsp+160h] [rbp+60h] BYREF
  hkaiNavMeshSimplificationUtils::PlaneFitter points; // [rsp+170h] [rbp+70h] BYREF
  hkVector4f v245; // [rsp+1D0h] [rbp+D0h] BYREF
  hkVector4f v246; // [rsp+1E0h] [rbp+E0h] BYREF
  __m128 v247; // [rsp+1F0h] [rbp+F0h]
  __m128 v248; // [rsp+200h] [rbp+100h]
  hkVector4f direction; // [rsp+210h] [rbp+110h] BYREF
  hkVector4f v250; // [rsp+220h] [rbp+120h] BYREF
  hkVector4f v251; // [rsp+230h] [rbp+130h] BYREF
  hkVector4f v252; // [rsp+240h] [rbp+140h] BYREF
  hkVector4f v253; // [rsp+250h] [rbp+150h] BYREF
  hkVector4f v254; // [rsp+260h] [rbp+160h] BYREF
  hkVector4f v255; // [rsp+270h] [rbp+170h] BYREF
  hkVector4f start; // [rsp+280h] [rbp+180h] BYREF
  hkVector4f v257; // [rsp+290h] [rbp+190h] BYREF
  hkVector4f end; // [rsp+2A0h] [rbp+1A0h] BYREF

  v7 = mesh;
  v8 = result;
  if ( !settings->m_overrideSettings.m_size && settings->m_simplificationSettings.m_boundaryEdgeFilterThreshold <= 0.0
    || !raycaster )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  m_characterHeight_low = (__m128)LODWORD(settings->m_characterHeight);
  v11 = 0i64;
  v12 = 0;
  array = 0i64;
  v13 = 0;
  numElem = 0;
  extrusion.m_quad = _mm_mul_ps(
                       _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(m_characterHeight_low, m_characterHeight_low, 0)),
                       settings->m_up.m_quad);
  v14 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(settings->m_edgeMatchingParams.m_maxStepHeight * 0.60000002),
            (__m128)COERCE_UNSIGNED_INT(settings->m_edgeMatchingParams.m_maxStepHeight * 0.60000002),
            0),
          settings->m_up.m_quad);
  v218.m_enum = LODWORD(FLOAT_0_0099999998);
  v15 = 0x80000000;
  v215 = 0x80000000;
  v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v248 = v14;
  v247 = v16;
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
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v18 < 2 * v19 )
            v18 = 2 * v19;
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v18, 4);
          if ( resulta.m_enum )
          {
            v8->m_enum = HK_FAILURE;
            goto LABEL_18;
          }
          v12 = numElem;
        }
        array[v12] = v13;
        v15 = v215;
        v12 = ++numElem;
      }
      ++v13;
      ++v17;
    }
    while ( v13 < v7->m_edges.m_size );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v221);
  if ( !v221.m_elem )
  {
    v8->m_enum = HK_FAILURE;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v221);
LABEL_18:
    numElem = 0;
    if ( v215 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v215);
    return v8;
  }
  v20 = numElem;
  v21 = 0;
  if ( numElem > 0 )
  {
    v22 = 0i64;
    do
    {
      m_data = v7->m_edges.m_data;
      v24 = (int)array[v22];
      v25 = v24;
      if ( m_data[v24].m_oppositeEdge == -1 )
      {
        KeyWithValue = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
                                       &v221,
                                       m_data[v24].m_a,
                                       v21);
        if ( KeyWithValue > v221.m_hashMod
          && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
                &v221,
                &v218,
                m_data[v25].m_a,
                v21),
              v218.m_enum)
          || (v27 = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
                                    &v221,
                                    m_data[v25].m_b,
                                    v21),
              v27 > v221.m_hashMod)
          && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
                &v221,
                &v222,
                m_data[v25].m_b,
                v21),
              v222.m_enum) )
        {
          v30 = result;
          result->m_enum = HK_FAILURE;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v221);
          numElem = 0;
          if ( v215 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v215);
          return v30;
        }
        v20 = numElem;
      }
      ++v21;
      ++v22;
    }
    while ( v21 < v20 );
    v8 = result;
  }
  v28 = 0;
  v29 = 0x80000000;
  v210 = 0i64;
  v211 = 0;
  v212 = 0x80000000;
  if ( v20 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v210, v20, 1);
    if ( resulta.m_enum )
    {
      v8->m_enum = HK_FAILURE;
LABEL_52:
      v211 = 0;
      if ( v212 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v210, v212 & 0x3FFFFFFF);
      v210 = 0i64;
      v212 = 0x80000000;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v221);
      numElem = 0;
      if ( v215 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v215);
      return v8;
    }
    v20 = numElem;
    v29 = v212;
    v28 = v211;
  }
  v31 = v29 & 0x3FFFFFFF;
  if ( v31 < v20 )
  {
    v32 = 2 * v31;
    v33 = v20;
    if ( v20 < v32 )
      v33 = v32;
    hkArrayUtil::_reserve(&v225, &hkContainerTempAllocator::s_alloc, &v210, v33, 1);
    v28 = v211;
  }
  v34 = &v210[v28];
  v35 = v20 - v28;
  v36 = v20 - v28;
  if ( v35 > 0 )
    memset(v34, 0, v36);
  v211 = v20;
  a = 0i64;
  numtoinsert = 0;
  v209 = 0x80000000;
  hkArrayUtil::_reserve(&v218, &hkContainerTempAllocator::s_alloc, &a, 8, 4);
  if ( v218.m_enum )
  {
    v8->m_enum = HK_FAILURE;
LABEL_49:
    numtoinsert = 0;
    if ( v209 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 4 * v209);
    v209 = 0x80000000;
    a = 0i64;
    goto LABEL_52;
  }
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v219);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v219, 8);
  if ( !v219.m_data )
  {
    v8->m_enum = HK_FAILURE;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v219);
    goto LABEL_49;
  }
  v37 = 0i64;
  v218.m_enum = HK_SUCCESS;
  v233 = 0i64;
  if ( numElem <= 0 )
  {
LABEL_210:
    v30 = result;
    result->m_enum = HK_SUCCESS;
    goto LABEL_211;
  }
  m_capacity = v219.m_capacity;
  while ( 1 )
  {
    if ( v210[v37] )
      goto LABEL_201;
    v210[v37] = 1;
    v39 = v7->m_edges.m_data;
    v40 = (int)array[v37];
    numtoinsert = 0;
    v41 = v40;
    m_head = 0;
    *a = array[v37];
    ++numtoinsert;
    *(_QWORD *)&v219.m_head = 0i64;
    m_tail = 0;
    m_elementsInUse = 0;
    v219.m_elementsInUse = 0;
    if ( m_capacity <= 0 )
    {
      v45 = 8;
      if ( m_capacity )
        v45 = 2 * m_capacity;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v219, v45);
      m_capacity = v219.m_capacity;
      m_head = v219.m_head;
      m_tail = v219.m_tail;
      m_elementsInUse = v219.m_elementsInUse;
    }
    m_a = v39[v41].m_a;
    if ( m_tail == m_capacity )
      m_tail = 0;
    v47 = m_elementsInUse + 1;
    v48 = m_tail;
    v49 = m_tail + 1;
    v219.m_elementsInUse = v47;
    *((_DWORD *)v219.m_data + v48) = m_a;
    v219.m_tail = v49;
    if ( v47 >= m_capacity )
    {
      v50 = 8;
      if ( m_capacity )
        v50 = 2 * m_capacity;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v219, v50);
      m_capacity = v219.m_capacity;
      m_head = v219.m_head;
      v49 = v219.m_tail;
      v47 = v219.m_elementsInUse;
    }
    m_b = v39[v41].m_b;
    if ( v49 == m_capacity )
      v49 = 0;
    v52 = v49;
    v53 = v49 + 1;
    v54 = v47 + 1;
    v219.m_elementsInUse = v54;
    *((_DWORD *)v219.m_data + v52) = m_b;
    v219.m_tail = v53;
    while ( v54 )
    {
      v55 = m_head++;
      v56 = *((int *)v219.m_data + v55);
      if ( m_head == m_capacity )
        m_head = 0;
      --v54;
      v57 = *((int *)v219.m_data + v55);
      v219.m_head = m_head;
      v219.m_elementsInUse = v54;
      Key = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                            &v221,
                            v56);
      m_hashMod = v221.m_hashMod;
      v60 = Key;
      if ( Key <= v221.m_hashMod )
      {
        m_elem = v221.m_elem;
        do
        {
          val_low = SLODWORD(m_elem[v60].val);
          v241 = val_low;
          if ( !v210[val_low] )
          {
            v235 = array[val_low];
            v63 = &mesh->m_edges.m_data[v235];
            v64 = v57;
            if ( v63->m_a == (_DWORD)v57 || v63->m_b == (_DWORD)v57 )
            {
              if ( v54 >= m_capacity )
              {
                hkQueue<int>::setCapacity((hkQueue<int> *)&v219, 2 * m_capacity);
                if ( !v219.m_data )
                  goto LABEL_181;
                v54 = v219.m_elementsInUse;
                v53 = v219.m_tail;
                m_capacity = v219.m_capacity;
                v64 = v57;
              }
              if ( v63->m_a == v64 )
                v63 = (hkaiNavMesh::Edge *)((char *)v63 + 4);
              if ( v54 >= m_capacity )
              {
                v65 = 8;
                if ( m_capacity )
                  v65 = 2 * m_capacity;
                hkQueue<int>::setCapacity((hkQueue<int> *)&v219, v65);
                m_capacity = v219.m_capacity;
                v53 = v219.m_tail;
                v54 = v219.m_elementsInUse;
              }
              v66 = v63->m_a;
              if ( v53 == m_capacity )
                v53 = 0;
              v67 = v53++;
              v219.m_elementsInUse = ++v54;
              *((_DWORD *)v219.m_data + v67) = v66;
              v219.m_tail = v53;
            }
            v68 = numtoinsert;
            v69 = numtoinsert + 1;
            if ( (v209 & 0x3FFFFFFF) >= numtoinsert + 1 )
            {
              v223.m_enum = HK_SUCCESS;
            }
            else
            {
              if ( v69 < 2 * (v209 & 0x3FFFFFFF) )
                v69 = 2 * (v209 & 0x3FFFFFFF);
              hkArrayUtil::_reserve(&v223, &hkContainerTempAllocator::s_alloc, &a, v69, 4);
              if ( v223.m_enum )
                goto LABEL_181;
              v68 = numtoinsert;
            }
            a[v68] = v235;
            ++numtoinsert;
            v210[v241] = 1;
            m_hashMod = v221.m_hashMod;
            m_elem = v221.m_elem;
          }
          v70 = v60 + 1;
          for ( i = v60 + 1; i > m_hashMod; i = 0i64 )
LABEL_105:
            v70 = 0;
          v72 = &m_elem[i];
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
            if ( i > m_hashMod )
              goto LABEL_105;
          }
          v60 = m_hashMod + 1;
LABEL_108:
          ;
        }
        while ( v60 <= m_hashMod );
        m_head = v219.m_head;
      }
    }
    v73 = numtoinsert;
    v74 = a;
    v7 = mesh;
    if ( numtoinsert != 2 )
      break;
    v75 = mesh->m_edges.m_data;
    v76 = (int)*a;
    if ( v75[*a].m_a != v75[a[1]].m_b || v75[*a].m_b != v75[a[1]].m_a )
      break;
    v77 = mesh->m_vertices.m_data;
    *(_DWORD *)&points.m_memSizeAndFlags = numtoinsert;
    *(_DWORD *)(&points.m_referenceCount + 1) = -2147483646;
    points.vfptr = (hkBaseObjectVtbl *)&points.m_sum;
    points.m_sum = v77[v75[v76].m_a];
    points.m_productSums.m_col0 = v77[v75[v76].m_b];
    if ( hkaiNavMeshGenerationSettings::getSimplificationSettings(settings, (hkArrayBase<hkVector4f> *)&points, -1)->m_boundaryEdgeFilterThreshold <= 0.0 )
    {
      v78 = *(_DWORD *)(&points.m_referenceCount + 1);
      *(_DWORD *)&points.m_memSizeAndFlags = 0;
LABEL_116:
      if ( v78 < 0 )
        goto LABEL_201;
      vfptr = points.vfptr;
LABEL_118:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, vfptr, 16 * v78);
      goto LABEL_201;
    }
    vfptr = points.vfptr;
    v80 = (__m128)points.vfptr[1];
    v81 = _mm_sub_ps(*(__m128 *)points.vfptr, v80);
    v82 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(settings->m_up.m_quad, settings->m_up.m_quad, 201), v81),
            _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), settings->m_up.m_quad));
    v83 = _mm_shuffle_ps(v82, v82, 201);
    v84 = _mm_mul_ps(v83, v83);
    v85 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
            _mm_shuffle_ps(v84, v84, 170));
    v86 = _mm_rsqrt_ps(v85);
    v87 = _mm_cmplt_ps(_mm_sub_ps(v11, v85), v11);
    v88 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v85, v11),
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
                _mm_mul_ps(_mm_sub_ps(v80, *(__m128 *)points.vfptr), (__m128)xmmword_141A711B0),
                *(__m128 *)points.vfptr),
              v14);
      start.m_quad = _mm_add_ps(v89, _mm_mul_ps(v88, v16));
      end.m_quad = _mm_add_ps(v89, _mm_mul_ps(_mm_sub_ps(v11, v16), v88));
      v90 = hkaiEdgeGeometryRaycaster::castRayExtruded(raycaster, &start, &end, &extrusion);
      v78 = *(_DWORD *)(&points.m_referenceCount + 1);
      *(_DWORD *)&points.m_memSizeAndFlags = 0;
      if ( v90 )
        goto LABEL_116;
      if ( *(int *)(&points.m_referenceCount + 1) >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          points.vfptr,
          16 * *(_DWORD *)(&points.m_referenceCount + 1));
LABEL_175:
      if ( numEdgesInGroupOut && edgesToRemoveOut )
      {
        v196 = numEdgesInGroupOut->m_size + 1;
        v197 = numEdgesInGroupOut->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v197 >= v196 )
        {
          v226.m_enum = HK_SUCCESS;
        }
        else
        {
          v198 = 2 * v197;
          if ( v196 < v198 )
            v196 = v198;
          hkArrayUtil::_reserve(&v226, &hkContainerHeapAllocator::s_alloc, numEdgesInGroupOut, v196, 4);
          if ( v226.m_enum )
          {
LABEL_181:
            v30 = result;
            result->m_enum = HK_FAILURE;
            goto LABEL_211;
          }
        }
        numEdgesInGroupOut->m_data[numEdgesInGroupOut->m_size++] = numtoinsert;
        v199 = numtoinsert;
        v200 = numtoinsert + edgesToRemoveOut->m_size;
        v201 = edgesToRemoveOut->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v201 >= v200 )
        {
          v222.m_enum = HK_SUCCESS;
        }
        else
        {
          v202 = 2 * v201;
          if ( v200 < v202 )
            v200 = v202;
          hkArrayUtil::_reserve(&v222, &hkContainerHeapAllocator::s_alloc, edgesToRemoveOut, v200, 4);
          if ( v222.m_enum )
            goto LABEL_181;
          v199 = numtoinsert;
        }
        hkArrayBase<unsigned int>::_append(edgesToRemoveOut, &hkContainerHeapAllocator::s_alloc, a, v199);
      }
      if ( removableEdges )
      {
        v203 = 0;
        if ( numtoinsert > 0 )
        {
          v204 = 0i64;
          do
          {
            ++v203;
            v205 = (int)a[v204++];
            removableEdges->m_storage.m_words.m_data[v205 >> 5] |= 1 << (v205 & 0x1F);
          }
          while ( v203 < numtoinsert );
          m_capacity = v219.m_capacity;
        }
      }
      goto LABEL_201;
    }
    v78 = *(_DWORD *)(&points.m_referenceCount + 1);
    *(_DWORD *)&points.m_memSizeAndFlags = 0;
    if ( *(int *)(&points.m_referenceCount + 1) >= 0 )
      goto LABEL_118;
LABEL_201:
    ++v233;
    if ( ++v218.m_enum >= numElem )
      goto LABEL_210;
    v14 = v248;
    v16 = v247;
    v37 = v233;
  }
  v91 = 2 * numtoinsert;
  v216.m_data = 0i64;
  v216.m_size = 0;
  v216.m_capacityAndFlags = 0x80000000;
  if ( 2 * numtoinsert <= 0 )
  {
    v224.m_enum = HK_SUCCESS;
  }
  else
  {
    v92 = 2 * numtoinsert;
    if ( (numtoinsert & 0x40000000) != 0 )
      v92 = 0;
    hkArrayUtil::_reserve(&v224, &hkContainerTempAllocator::s_alloc, &v216, v92, 16);
    if ( v224.m_enum )
    {
      v30 = result;
      result->m_enum = HK_FAILURE;
      goto LABEL_204;
    }
    v73 = numtoinsert;
    v74 = a;
  }
  v216.m_size = v91;
  v93 = 0;
  if ( v73 > 0 )
  {
    v94 = 0i64;
    v95 = 0i64;
    while ( 1 )
    {
      v96 = mesh->m_edges.m_data;
      v97 = v216.m_data;
      v98 = (int)v74[v95];
      ++v93;
      v99 = v96[v74[v95++]].m_a;
      v94 += 2i64;
      v216.m_data[v94 - 2] = mesh->m_vertices.m_data[v99];
      v97[v94 - 1] = mesh->m_vertices.m_data[v96[v98].m_b];
      if ( v93 >= numtoinsert )
        break;
      v74 = a;
    }
  }
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&points);
  for ( j = 0; j < v216.m_size; ++j )
    hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&points, &v216.m_data[j]);
  v101 = hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&points, &v242, &planeOut);
  m_size = v216.m_size;
  if ( v101->m_enum == HK_FAILURE )
  {
    v103 = (__m128)xmmword_141A712A0;
    v104 = v11;
    v105 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v216.m_size > 0 )
    {
      v106 = v216.m_data;
      v107 = (unsigned int)v216.m_size;
      do
      {
        m_quad = v106->m_quad;
        ++v106;
        v103 = _mm_min_ps(v103, m_quad);
        v105 = _mm_max_ps(v105, m_quad);
        v104 = _mm_add_ps(v104, m_quad);
        --v107;
      }
      while ( v107 );
    }
    v109 = _mm_sub_ps(v105, v103);
    v110 = v11;
    v110.m128_f32[0] = (float)v216.m_size;
    v111 = *(&transform.m_quad
           + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmple_ps(
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
  v234 = 1065353048;
  v114 = _mm_mul_ps(v113, v113);
  v115 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
           _mm_shuffle_ps(v114, v114, 170));
  v116 = _mm_rsqrt_ps(v115);
  v117 = _mm_mul_ps(
           v113,
           _mm_andnot_ps(
             _mm_cmple_ps(v115, v11),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v116, v115), v116)),
               _mm_mul_ps(v116, *(__m128 *)_xmm))));
  planeOut.m_quad = v117;
  v118 = _mm_mul_ps(v117, stru_141A71280.m_quad);
  v119 = _mm_sub_ps(v11, _mm_shuffle_ps(v117, v117, 255));
  v120 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
           _mm_shuffle_ps(v118, v118, 170));
  v121 = _mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0).m128_f32[0];
  if ( v120.m128_f32[0] <= v121 )
  {
    if ( v120.m128_f32[0] < (float)(v11.m128_f32[0] - v121) )
    {
      hkQuaternionf::setFlippedRotation(&quat, &planeOut);
      m_size = v216.m_size;
      v117 = planeOut.m_quad;
      v122 = quat.m_vec.m_quad;
      goto LABEL_151;
    }
    v236 = -1082147209;
    v123 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v120), (__m128)xmmword_141A711B0);
    v124 = _mm_rsqrt_ps(v123);
    v125 = _mm_andnot_ps(
             _mm_cmple_ps(v123, v11),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v124, v123), v124)),
               _mm_mul_ps(v124, *(__m128 *)_xmm)));
    v126 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v117),
             _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), stru_141A71280.m_quad));
    v127 = _mm_shuffle_ps(v126, v126, 201);
    v128 = _mm_mul_ps(v125, (__m128)xmmword_141A711B0);
    if ( v120.m128_f32[0] < _mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0).m128_f32[0] )
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
                   _mm_cmple_ps(v130, v11),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v131, v130), v131)),
                     _mm_mul_ps(*(__m128 *)_xmm, v131))),
                 v130),
               _mm_andnot_ps(
                 _mm_cmple_ps(v132, v11),
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
  v217.m_data = 0i64;
  v217.m_size = 0;
  v217.m_capacityAndFlags = 0x80000000;
  if ( m_size <= 0 )
  {
    v227.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v227, &hkContainerTempAllocator::s_alloc, &v217, m_size, 8);
    if ( v227.m_enum )
      goto LABEL_207;
    v117 = planeOut.m_quad;
    v122 = quat.m_vec.m_quad;
  }
  v217.m_size = m_size;
  v136 = 0;
  if ( m_size > 0 )
  {
    v137 = 0i64;
    while ( 1 )
    {
      v138 = v136++;
      ++v137;
      v139 = _mm_shuffle_ps(v122, v122, 255);
      v140 = _mm_mul_ps(v216.m_data[v137 - 1].m_quad, v117);
      v141 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_sub_ps(
                   v11,
                   _mm_sub_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                       _mm_shuffle_ps(v140, v140, 170)),
                     v119)),
                 v117),
               v216.m_data[v137 - 1].m_quad);
      v142 = _mm_mul_ps(v122, v141);
      v143 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v141, v141, 201), v122),
               _mm_mul_ps(_mm_shuffle_ps(v122, v122, 201), v141));
      v144 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                     _mm_shuffle_ps(v142, v142, 170)),
                   v122),
                 _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v139, v139), (__m128)xmmword_141A711B0), v141)),
               _mm_mul_ps(_mm_shuffle_ps(v143, v143, 201), v139));
      v145 = _mm_add_ps(v144, v144);
      v217.m_data[v138] = (hkVector2f)v145.m128_u64[0];
      m_size = v217.m_size;
      v135 = _mm_add_ps(v135, _mm_shuffle_ps(v145, v145, 170));
      if ( v136 >= v217.m_size )
        break;
      v117 = planeOut.m_quad;
      v122 = quat.m_vec.m_quad;
    }
  }
  v146 = v11;
  v146.m128_f32[0] = (float)m_size;
  centerOut = 0i64;
  v147 = _mm_shuffle_ps(v146, v146, 0);
  v148 = _mm_rcp_ps(v147);
  e0Out = 0i64;
  e1Out = 0i64;
  v149 = _mm_mul_ps(v135, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v147, v148)), v148));
  v150 = hkVector2Util::computeObb(&v217, &centerOut, &e0Out, &e1Out, &resOut);
  if ( resOut.m_enum == HK_SUCCESS )
  {
    m_boundaryEdgeFilterThreshold = hkaiNavMeshGenerationSettings::getSimplificationSettings(settings, &v216, -1)->m_boundaryEdgeFilterThreshold;
    if ( m_boundaryEdgeFilterThreshold <= 0.0 || v150 > m_boundaryEdgeFilterThreshold )
      goto LABEL_195;
    y_low = (__m128)LODWORD(e0Out.y);
    x_low = (__m128)LODWORD(e0Out.x);
    v154 = (__m128)LODWORD(centerOut.y);
    v155 = (__m128)LODWORD(centerOut.x);
    v154.m128_f32[0] = centerOut.y - e0Out.y;
    v155.m128_f32[0] = centerOut.x - e0Out.x;
    y_low.m128_f32[0] = e0Out.y + centerOut.y;
    v156 = v154;
    v157 = v155;
    v157.m128_f32[0] = (float)(centerOut.x - e0Out.x) + e1Out.x;
    v156.m128_f32[0] = (float)(centerOut.y - e0Out.y) + e1Out.y;
    x_low.m128_f32[0] = e0Out.x + centerOut.x;
    v158 = v156;
    v159 = y_low;
    v159.m128_f32[0] = (float)(e0Out.y + centerOut.y) + e1Out.y;
    y_low.m128_f32[0] = (float)(e0Out.y + centerOut.y) - e1Out.y;
    v155.m128_f32[0] = (float)(centerOut.x - e0Out.x) - e1Out.x;
    direction.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v157, v149), _mm_unpacklo_ps(v158, (__m128)0i64));
    v160 = x_low;
    v160.m128_f32[0] = (float)(e0Out.x + centerOut.x) + e1Out.x;
    x_low.m128_f32[0] = (float)(e0Out.x + centerOut.x) - e1Out.x;
    v154.m128_f32[0] = (float)(centerOut.y - e0Out.y) - e1Out.y;
    v251.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v160, v149), _mm_unpacklo_ps(v159, (__m128)0i64));
    v255.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, v149), _mm_unpacklo_ps(y_low, (__m128)0i64));
    v253.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v155, v149), _mm_unpacklo_ps(v154, (__m128)0i64));
    hkVector4f::setRotatedInverseDir(&v250, &quat, &direction);
    hkVector4f::setRotatedInverseDir(&v257, &quat, &v251);
    hkVector4f::setRotatedInverseDir(&v252, &quat, &v255);
    hkVector4f::setRotatedInverseDir(&v254, &quat, &v253);
    v161 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v252.m_quad, v257.m_quad), (__m128)xmmword_141A711B0), v257.m_quad);
    v240.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v257.m_quad, v250.m_quad), (__m128)xmmword_141A711B0), v250.m_quad);
    v245.m_quad = v161;
    v11 = 0i64;
    v232 = 953267991;
    v162 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v250.m_quad, v254.m_quad), (__m128)xmmword_141A711B0), v254.m_quad);
    v246.m_quad = v162;
    v163 = _mm_sub_ps(v162, v161);
    v243.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v254.m_quad, v252.m_quad), (__m128)xmmword_141A711B0), v252.m_quad);
    v164 = _mm_mul_ps(v163, v163);
    v165 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v164, v164, 85), _mm_shuffle_ps(v164, v164, 0)),
             _mm_shuffle_ps(v164, v164, 170));
    v166 = _mm_rsqrt_ps(v165);
    v167 = _mm_andnot_ps(
             _mm_cmple_ps(v165, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v166, v165), v166)),
               _mm_mul_ps(v166, *(__m128 *)_xmm)));
    v168 = _mm_mul_ps(v163, v167);
    if ( (float)(v167.m128_f32[0] * v165.m128_f32[0]) < _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0] )
    {
      v169 = _mm_sub_ps(v161, v162);
      v170 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(settings->m_up.m_quad, settings->m_up.m_quad, 201), v169),
               _mm_mul_ps(_mm_shuffle_ps(v169, v169, 201), settings->m_up.m_quad));
      v171 = _mm_shuffle_ps(v170, v170, 201);
      v172 = _mm_mul_ps(v171, v171);
      v173 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v172, v172, 85), _mm_shuffle_ps(v172, v172, 0)),
               _mm_shuffle_ps(v172, v172, 170));
      v174 = _mm_rsqrt_ps(v173);
      v175 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v173), (__m128)0i64);
      v168 = _mm_or_ps(
               _mm_and_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmple_ps(v173, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v174, v173), v174)),
                       _mm_mul_ps(v174, *(__m128 *)_xmm))),
                   v171),
                 v175),
               _mm_andnot_ps(v175, v171));
      if ( !_mm_movemask_ps(v175) )
        goto LABEL_195;
      v161 = _mm_add_ps(v161, _mm_mul_ps(v163, (__m128)xmmword_141A711B0));
      v162 = v161;
    }
    v176 = v247;
    v177 = v248;
    v178 = _mm_sub_ps((__m128)0i64, v247);
    v246.m_quad = _mm_add_ps(_mm_mul_ps(v168, v247), _mm_add_ps(v162, v248));
    v245.m_quad = _mm_add_ps(_mm_add_ps(v161, v248), _mm_mul_ps(v168, v178));
    if ( hkaiEdgeGeometryRaycaster::castRayExtruded(raycaster, &v245, &v246, &extrusion) )
    {
LABEL_195:
      m_capacityAndFlags = v217.m_capacityAndFlags;
      v217.m_size = 0;
LABEL_196:
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v217.m_data,
          8 * m_capacityAndFlags);
      v217.m_data = 0i64;
      v217.m_capacityAndFlags = 0x80000000;
      v216.m_size = 0;
      if ( v216.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v216.m_data,
          16 * v216.m_capacityAndFlags);
      v216.m_data = 0i64;
      v216.m_capacityAndFlags = 0x80000000;
      goto LABEL_201;
    }
    v179 = v243.m_quad;
    v180 = v240.m_quad;
    v225.m_enum = 953267991;
    v181 = _mm_sub_ps(v243.m_quad, v240.m_quad);
    v182 = _mm_mul_ps(v181, v181);
    v183 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v182, v182, 85), _mm_shuffle_ps(v182, v182, 0)),
             _mm_shuffle_ps(v182, v182, 170));
    v184 = _mm_rsqrt_ps(v183);
    v185 = _mm_andnot_ps(
             _mm_cmple_ps(v183, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v184, v183), v184)),
               _mm_mul_ps(v184, *(__m128 *)_xmm)));
    v186 = _mm_mul_ps(v181, v185);
    if ( (float)(v185.m128_f32[0] * v183.m128_f32[0]) < _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0] )
    {
      v187 = _mm_sub_ps(v240.m_quad, v243.m_quad);
      v188 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(settings->m_up.m_quad, settings->m_up.m_quad, 201), v187),
               _mm_mul_ps(_mm_shuffle_ps(v187, v187, 201), settings->m_up.m_quad));
      v189 = _mm_shuffle_ps(v188, v188, 201);
      v190 = _mm_mul_ps(v189, v189);
      v191 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v190, v190, 85), _mm_shuffle_ps(v190, v190, 0)),
               _mm_shuffle_ps(v190, v190, 170));
      v192 = _mm_rsqrt_ps(v191);
      v193 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v191), (__m128)0i64);
      v186 = _mm_or_ps(
               _mm_and_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmple_ps(v191, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v191, v192), v192)),
                       _mm_mul_ps(*(__m128 *)_xmm, v192))),
                   v189),
                 v193),
               _mm_andnot_ps(v193, v189));
      if ( !_mm_movemask_ps(v193) )
        goto LABEL_195;
      v179 = _mm_add_ps(_mm_mul_ps(v181, (__m128)xmmword_141A711B0), v240.m_quad);
      v180 = v179;
    }
    v243.m_quad = _mm_add_ps(_mm_mul_ps(v186, v176), _mm_add_ps(v179, v177));
    v240.m_quad = _mm_add_ps(_mm_add_ps(v180, v177), _mm_mul_ps(v186, v178));
    v194 = hkaiEdgeGeometryRaycaster::castRayExtruded(raycaster, &v240, &v243, &extrusion);
    m_capacityAndFlags = v217.m_capacityAndFlags;
    v217.m_size = 0;
    if ( v194 )
      goto LABEL_196;
    if ( v217.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v217.m_data,
        8 * v217.m_capacityAndFlags);
    v217.m_data = 0i64;
    v217.m_capacityAndFlags = 0x80000000;
    v216.m_size = 0;
    if ( v216.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v216.m_data,
        16 * v216.m_capacityAndFlags);
    v216.m_data = 0i64;
    v216.m_capacityAndFlags = 0x80000000;
    goto LABEL_175;
  }
LABEL_207:
  v30 = result;
  v206 = v217.m_capacityAndFlags;
  v217.m_size = 0;
  result->m_enum = HK_FAILURE;
  if ( v206 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v217.m_data, 8 * v206);
  v217.m_data = 0i64;
  v217.m_capacityAndFlags = 0x80000000;
LABEL_204:
  v216.m_size = 0;
  if ( v216.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v216.m_data,
      16 * v216.m_capacityAndFlags);
  v216.m_data = 0i64;
  v216.m_capacityAndFlags = 0x80000000;
LABEL_211:
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v219);
  numtoinsert = 0;
  if ( v209 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 4 * v209);
  v211 = 0;
  v209 = 0x80000000;
  a = 0i64;
  if ( v212 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v210, v212 & 0x3FFFFFFF);
  v210 = 0i64;
  v212 = 0x80000000;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v221);
  numElem = 0;
  if ( v215 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v215);
  return v30;
}

// File Line: 3901
// RVA: 0xB58880
_BOOL8 __fastcall canMergeVertexPair(
        hkaiNavMeshSimplificationUtils::Settings *simplificationSettings,
        int vertComponentIdx,
        hkVector4f *unmergedVertexA,
        hkVector4f *unmergedVertexB,
        hkVector4f *mergedVertex,
        bool aIsBoundary,
        bool bIsBoundary)
{
  __m128 m_quad; // xmm5
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
  float *p_m_maxBoundaryVertexHorizontalError; // rax
  float v26; // xmm8_4
  float v27; // xmm7_4
  __m128 v28; // xmm2
  float v29; // xmm3_4
  __m128 v30; // xmm2
  float *p_m_maxBoundaryVertexVerticalError; // rax
  float *p_m_maxSharedVertexHorizontalError; // rdx
  __m128 v34; // xmm4
  float v35; // xmm2_4
  __m128 v36; // xmm4
  float *p_m_maxSharedVertexVerticalError; // rcx

  m_quad = unmergedVertexB->m_quad;
  v8 = unmergedVertexA->m_quad;
  v9 = mergedVertex->m_quad;
  v10 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], mergedVertex->m_quad);
  v11 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], unmergedVertexA->m_quad);
  v13 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[vertComponentIdx], unmergedVertexB->m_quad);
  LODWORD(v14) = _mm_shuffle_ps(v11, v11, 177).m128_u32[0] | v11.m128_i32[0];
  v15 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v16 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  LODWORD(v17) = _mm_shuffle_ps(v15, v15, 177).m128_u32[0] | v15.m128_i32[0];
  LODWORD(v18) = _mm_shuffle_ps(v16, v16, 177).m128_u32[0] | v16.m128_i32[0];
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
        v23 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)m_quad, 4), 4);
      else
        v23 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)m_quad, 4), 4);
    }
    else
    {
      v23 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 180);
    }
  }
  else
  {
    v23 = _mm_shuffle_ps(_mm_unpacklo_ps(m_quad, (__m128)0i64), m_quad, 228);
  }
  v24 = v14;
  p_m_maxBoundaryVertexHorizontalError = &simplificationSettings->m_maxBoundaryVertexHorizontalError;
  LODWORD(v26) = (unsigned int)(2 * COERCE_INT(v14 - v18)) >> 1;
  LODWORD(v27) = (unsigned int)(2 * COERCE_INT(v24 - v17)) >> 1;
  if ( !aIsBoundary )
    p_m_maxBoundaryVertexHorizontalError = &simplificationSettings->m_maxSharedVertexHorizontalError;
  v28 = _mm_sub_ps(v19, v20);
  v29 = _mm_shuffle_ps(
          (__m128)*(unsigned int *)p_m_maxBoundaryVertexHorizontalError,
          (__m128)*(unsigned int *)p_m_maxBoundaryVertexHorizontalError,
          0).m128_f32[0];
  v30 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
             + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) > (float)(v29 * v29) )
    return 0i64;
  p_m_maxBoundaryVertexVerticalError = &simplificationSettings->m_maxBoundaryVertexVerticalError;
  if ( !aIsBoundary )
    p_m_maxBoundaryVertexVerticalError = &simplificationSettings->m_maxSharedVertexVerticalError;
  if ( v27 > _mm_shuffle_ps(
               (__m128)*(unsigned int *)p_m_maxBoundaryVertexVerticalError,
               (__m128)*(unsigned int *)p_m_maxBoundaryVertexVerticalError,
               0).m128_f32[0] )
    return 0i64;
  p_m_maxSharedVertexHorizontalError = &simplificationSettings->m_maxBoundaryVertexHorizontalError;
  if ( !bIsBoundary )
    p_m_maxSharedVertexHorizontalError = &simplificationSettings->m_maxSharedVertexHorizontalError;
  v34 = _mm_sub_ps(v19, v23);
  v35 = _mm_shuffle_ps(
          (__m128)*(unsigned int *)p_m_maxSharedVertexHorizontalError,
          (__m128)*(unsigned int *)p_m_maxSharedVertexHorizontalError,
          0).m128_f32[0];
  v36 = _mm_mul_ps(v34, v34);
  if ( (float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
             + _mm_shuffle_ps(v36, v36, 170).m128_f32[0]) > (float)(v35 * v35) )
    return 0i64;
  if ( bIsBoundary )
    p_m_maxSharedVertexVerticalError = &simplificationSettings->m_maxBoundaryVertexVerticalError;
  else
    p_m_maxSharedVertexVerticalError = &simplificationSettings->m_maxSharedVertexVerticalError;
  return v26 <= _mm_shuffle_ps(
                  (__m128)*(unsigned int *)p_m_maxSharedVertexVerticalError,
                  (__m128)*(unsigned int *)p_m_maxSharedVertexVerticalError,
                  0).m128_f32[0];
}

// File Line: 3936
// RVA: 0xB4E140
hkResult *__fastcall hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *mesh)
{
  hkResult *v3; // r14
  hkaiNavMeshGenerationSettings *v5; // r12
  int v7; // r13d
  int m_size; // r15d
  int v9; // esi
  __int32 v10; // eax
  _DWORD *v11; // rdi
  int v12; // r8d
  int v13; // r9d
  __int64 i; // rcx
  int v15; // r10d
  __int64 v16; // r8
  hkaiNavMesh::Edge *m_data; // r9
  int v18; // esi
  __m128 v19; // xmm3
  hkLifoAllocator *Value; // rax
  int *m_cur; // rcx
  int v22; // edi
  char *v23; // rdx
  unsigned int m_slotID; // ecx
  hkLifoAllocator *v25; // rax
  int v26; // r8d
  int *v27; // rdx
  __int64 v28; // rsi
  hkaiNavMesh::Edge *v29; // r14
  __int64 m_oppositeEdge; // rax
  hkVector4f *v31; // rcx
  __int64 v32; // r15
  __int64 m_a; // rax
  __int128 v34; // xmm0
  __int64 m_b; // rax
  hkaiNavMeshSimplificationUtils::Settings *SimplificationSettings; // rax
  __int64 v37; // r15
  _DWORD *v38; // r12
  __int64 v39; // rcx
  hkaiNavMeshSimplificationUtils::Settings *v40; // r10
  __m128 m_quad; // xmm0
  __int64 v42; // rcx
  __int64 v43; // rdx
  hkVector4f *v44; // rcx
  unsigned int v45; // r9d
  __int64 v46; // r15
  __int64 v47; // r14
  hkVector4f *v48; // rcx
  int v49; // r9d
  int v50; // eax
  int v51; // esi
  int v52; // ecx
  int v53; // r9d
  char *v54; // rdi
  __int64 v55; // rcx
  int *v56; // rdi
  int v57; // r11d
  __int64 v58; // rsi
  __int64 v59; // r8
  __int64 v60; // r10
  __int64 v61; // rdx
  __m128 v62; // xmm2
  __int64 v63; // rcx
  __m128 v64; // xmm1
  __int64 v65; // rax
  __int64 v66; // rdx
  __m128 v67; // xmm1
  __int64 v68; // rcx
  int v69; // r8d
  __int64 v70; // rdi
  hkaiNavMesh::Edge *v71; // rdx
  __int64 v72; // rcx
  int *m_storage; // rbx
  signed int v74; // edi
  _DWORD *array; // [rsp+40h] [rbp-C0h] BYREF
  int v76; // [rsp+48h] [rbp-B8h]
  int v77; // [rsp+4Ch] [rbp-B4h]
  int v78; // [rsp+50h] [rbp-B0h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+58h] [rbp-A8h] BYREF
  hkArray<int,hkContainerHeapAllocator> orderedGroups; // [rsp+68h] [rbp-98h] BYREF
  char *v81; // [rsp+78h] [rbp-88h] BYREF
  int v82; // [rsp+80h] [rbp-80h]
  int v83; // [rsp+84h] [rbp-7Ch]
  hkFixedArray<int> parents; // [rsp+88h] [rbp-78h] BYREF
  hkResult v85[2]; // [rsp+98h] [rbp-68h] BYREF
  hkResult v86; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v87; // [rsp+A4h] [rbp-5Ch] BYREF
  hkResult resulta; // [rsp+A8h] [rbp-58h] BYREF
  hkUnionFind v89; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v90; // [rsp+C8h] [rbp-38h]
  hkArrayBase<hkVector4f> points; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v92[4]; // [rsp+E0h] [rbp-20h] BYREF
  hkVector4f mergedVertex; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f unmergedVertexB; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f unmergedVertexA; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f v96; // [rsp+150h] [rbp+50h] BYREF
  hkVector4f v97; // [rsp+160h] [rbp+60h] BYREF
  hkVector4f v98; // [rsp+170h] [rbp+70h] BYREF
  hkaiNavMesh mesha; // [rsp+180h] [rbp+80h] BYREF
  hkResult v102; // [rsp+288h] [rbp+188h] BYREF

  v3 = result;
  v5 = settings;
  hkaiNavMesh::hkaiNavMesh(&mesha);
  hkaiNavMesh::copy(&mesha, &resulta, mesh);
  if ( resulta.m_enum || (hkaiNavMeshSimplificationUtils::mergeSharedVertices(&v102, &mesha), v102.m_enum) )
  {
    v3->m_enum = HK_FAILURE;
    hkaiNavMesh::~hkaiNavMesh(&mesha);
    return v3;
  }
  v7 = 0;
  m_size = mesh->m_vertices.m_size;
  array = 0i64;
  v76 = 0;
  v9 = (m_size + 31) >> 5;
  v77 = 0x80000000;
  v10 = v9;
  if ( v9 )
  {
    v102.m_enum = 4 * v9;
    v11 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v102);
    v10 = v102.m_enum / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 0x80000000;
  array = v11;
  if ( v10 )
    v12 = v10;
  v76 = (m_size + 31) >> 5;
  v78 = m_size;
  v77 = v12;
  if ( (v12 & 0x3FFFFFFF) < v9 )
  {
    v13 = (m_size + 31) >> 5;
    if ( v9 < 2 * (v12 & 0x3FFFFFFF) )
      v13 = 2 * (v12 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v102, &hkContainerHeapAllocator::s_alloc, &array, v13, 4);
    v12 = v77;
    v11 = array;
  }
  v76 = (m_size + 31) >> 5;
  if ( v11 )
  {
    if ( v9 - 1 >= 0 )
    {
      for ( i = (unsigned int)v9; i; --i )
        *v11++ = 0;
      v11 = array;
    }
    v15 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        m_data = mesh->m_edges.m_data;
        if ( m_data[v16].m_oppositeEdge == -1 )
        {
          v11[(__int64)m_data[v16].m_a >> 5] |= 1 << (m_data[v16].m_a & 0x1F);
          array[(__int64)m_data[v16].m_b >> 5] |= 1 << (m_data[v16].m_b & 0x1F);
          v11 = array;
        }
        ++v15;
        ++v16;
      }
      while ( v15 < mesh->m_edges.m_size );
    }
    v18 = mesh->m_vertices.m_size;
    v19 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v5->m_up), 1u), 1u);
    v102.m_enum = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                         _mm_and_ps(
                                                                           _mm_cmple_ps(
                                                                             _mm_max_ps(
                                                                               _mm_shuffle_ps(v19, v19, 170),
                                                                               _mm_max_ps(
                                                                                 _mm_shuffle_ps(v19, v19, 85),
                                                                                 _mm_shuffle_ps(v19, v19, 0))),
                                                                             v19),
                                                                           (__m128)xmmword_141A4C9F0))];
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (int *)Value->m_cur;
    v22 = (4 * v18 + 127) & 0xFFFFFF80;
    v23 = (char *)m_cur + v22;
    if ( v22 > Value->m_slabSize || v23 > Value->m_end )
      m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v22);
    else
      Value->m_cur = v23;
    parents.m_data.m_storage = m_cur;
    parents.m_size.m_storage = v18;
    if ( v18 > 0 && !m_cur )
    {
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v3->m_enum = HK_FAILURE;
      v25 = (hkLifoAllocator *)TlsGetValue(m_slotID);
      v26 = (v22 + 15) & 0xFFFFFFF0;
      if ( v22 <= v25->m_slabSize && (void *)v26 == v25->m_cur && v25->m_firstNonLifoEnd )
      {
        v25->m_cur = 0i64;
LABEL_96:
        v76 = 0;
        if ( v77 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v77);
        array = 0i64;
        goto LABEL_99;
      }
      v27 = 0i64;
      goto LABEL_95;
    }
    hkUnionFind::hkUnionFind(&v89, &parents, v18);
    v89.m_isCollapsed = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v28 = 0i64;
      do
      {
        v29 = mesh->m_edges.m_data;
        m_oppositeEdge = (int)v29[v28].m_oppositeEdge;
        if ( (_DWORD)m_oppositeEdge != -1 )
        {
          v31 = mesh->m_vertices.m_data;
          v32 = m_oppositeEdge;
          points.m_size = 4;
          points.m_capacityAndFlags = -2147483644;
          points.m_data = (hkVector4f *)v92;
          m_a = v29[v28].m_a;
          v90 = v32 * 5;
          v34 = (__int128)v31[m_a];
          m_b = v29[v28].m_b;
          v92[0] = v34;
          v92[1] = (__int128)v31[m_b];
          v92[2] = (__int128)v31[v29[v32].m_a];
          v92[3] = (__int128)v31[v29[v32].m_b];
          SimplificationSettings = hkaiNavMeshGenerationSettings::getSimplificationSettings(v5, &points, -1);
          v37 = v29[v32].m_b;
          v38 = array;
          v39 = mesha.m_edges.m_data[v28].m_a;
          v40 = SimplificationSettings;
          *(_QWORD *)&v85[0].m_enum = SimplificationSettings;
          m_quad = mesha.m_vertices.m_data[v39].m_quad;
          v42 = mesha.m_edges.m_data[v28].m_b;
          mergedVertex.m_quad = m_quad;
          v43 = v29[v28].m_a;
          v97.m_quad = (__m128)mesha.m_vertices.m_data[v42];
          if ( (_DWORD)v43 != (_DWORD)v37 )
          {
            v44 = mesh->m_vertices.m_data;
            unmergedVertexA.m_quad = (__m128)v44[v43];
            v45 = array[v37 >> 5];
            unmergedVertexB.m_quad = (__m128)v44[v37];
            if ( canMergeVertexPair(
                   SimplificationSettings,
                   v102.m_enum,
                   &unmergedVertexA,
                   &unmergedVertexB,
                   &mergedVertex,
                   (array[v43 >> 5] >> (v43 & 0x1F)) & 1,
                   (v45 >> (v37 & 0x1F)) & 1) )
            {
              hkUnionFind::addEdge(&v89, v29[v28].m_a, v37);
              v38 = array;
            }
            v40 = *(hkaiNavMeshSimplificationUtils::Settings **)&v85[0].m_enum;
          }
          v46 = v29[v28].m_b;
          v47 = *(&v29->m_a + v90);
          if ( (_DWORD)v46 != (_DWORD)v47 )
          {
            v48 = mesh->m_vertices.m_data;
            v96.m_quad = (__m128)v48[v46];
            v98.m_quad = (__m128)v48[v47];
            if ( canMergeVertexPair(
                   v40,
                   v102.m_enum,
                   &v96,
                   &v98,
                   &v97,
                   (v38[v46 >> 5] >> (v46 & 0x1F)) & 1,
                   (v38[v47 >> 5] >> (v47 & 0x1F)) & 1) )
            {
              hkUnionFind::addEdge(&v89, v46, v47);
            }
          }
          points.m_size = 0;
          if ( points.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              points.m_data,
              16 * points.m_capacityAndFlags);
          v5 = settings;
        }
        ++v7;
        ++v28;
      }
      while ( v7 < mesh->m_edges.m_size );
      v3 = result;
    }
    elementsPerGroup.m_data = 0i64;
    elementsPerGroup.m_size = 0;
    elementsPerGroup.m_capacityAndFlags = 0x80000000;
    orderedGroups.m_data = 0i64;
    orderedGroups.m_size = 0;
    orderedGroups.m_capacityAndFlags = 0x80000000;
    hkUnionFind::assignGroups(&v89, &v87, &elementsPerGroup);
    if ( v87.m_enum )
    {
      v3->m_enum = HK_FAILURE;
LABEL_86:
      orderedGroups.m_size = 0;
      if ( orderedGroups.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          orderedGroups.m_data,
          4 * orderedGroups.m_capacityAndFlags);
      elementsPerGroup.m_size = 0;
      orderedGroups.m_capacityAndFlags = 0x80000000;
      orderedGroups.m_data = 0i64;
      if ( elementsPerGroup.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          elementsPerGroup.m_data,
          4 * elementsPerGroup.m_capacityAndFlags);
      m_storage = parents.m_data.m_storage;
      elementsPerGroup.m_data = 0i64;
      elementsPerGroup.m_capacityAndFlags = 0x80000000;
      v74 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
      v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (v74 + 15) & 0xFFFFFFF0;
      if ( v74 <= v25->m_slabSize && (char *)m_storage + v26 == v25->m_cur && v25->m_firstNonLifoEnd != m_storage )
      {
        v25->m_cur = m_storage;
        goto LABEL_96;
      }
      v27 = m_storage;
LABEL_95:
      hkLifoAllocator::slowBlockFree(v25, v27, v26);
      goto LABEL_96;
    }
    hkUnionFind::sortByGroupId(&v89, &v86, &elementsPerGroup, &orderedGroups);
    if ( v86.m_enum )
    {
      v3->m_enum = HK_FAILURE;
      goto LABEL_86;
    }
    v49 = mesh->m_vertices.m_size;
    v50 = 0;
    v81 = 0i64;
    v82 = 0;
    v83 = 0x80000000;
    if ( v49 <= 0 )
    {
      v102.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v102, &hkContainerTempAllocator::s_alloc, &v81, v49, 4);
      if ( v102.m_enum )
      {
        v3->m_enum = HK_FAILURE;
LABEL_83:
        v82 = 0;
        if ( v83 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v81, 4 * v83);
        v83 = 0x80000000;
        v81 = 0i64;
        goto LABEL_86;
      }
      v50 = v82;
    }
    v51 = mesh->m_vertices.m_size;
    v52 = v83 & 0x3FFFFFFF;
    if ( (v83 & 0x3FFFFFFF) < v51 )
    {
      v53 = mesh->m_vertices.m_size;
      if ( v51 < 2 * v52 )
        v53 = 2 * v52;
      hkArrayUtil::_reserve(v85, &hkContainerTempAllocator::s_alloc, &v81, v53, 4);
      v50 = v82;
    }
    v54 = &v81[4 * v50];
    v55 = v51 - v50;
    if ( v55 > 0 )
    {
      while ( v55 )
      {
        *(_DWORD *)v54 = -1;
        v54 += 4;
        --v55;
      }
    }
    v56 = orderedGroups.m_data;
    v82 = v51;
    v57 = 0;
    if ( elementsPerGroup.m_size > 0 )
    {
      v58 = 0i64;
      do
      {
        v59 = 0i64;
        v60 = elementsPerGroup.m_data[v58];
        if ( (int)v60 > 0 )
        {
          do
          {
            v61 = v56[v59++];
            *(_DWORD *)&v81[4 * v61] = *v56;
          }
          while ( v59 < v60 );
        }
        if ( (int)v60 > 1 )
        {
          v62 = 0i64;
          v63 = 0i64;
          v64 = 0i64;
          do
          {
            v65 = v56[v63++];
            v64 = _mm_add_ps(v64, mesh->m_vertices.m_data[v65].m_quad);
          }
          while ( v63 < v60 );
          v62.m128_f32[0] = (float)(int)v60;
          v66 = 0i64;
          v67 = _mm_mul_ps(v64, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v62, v62, 0)));
          do
          {
            v68 = v56[v66++];
            mesh->m_vertices.m_data[v68].m_quad = v67;
          }
          while ( v66 < v60 );
        }
        ++v57;
        ++v58;
        v56 += v60;
      }
      while ( v57 < elementsPerGroup.m_size );
    }
    v69 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v70 = 0i64;
      do
      {
        v71 = mesh->m_edges.m_data;
        ++v69;
        v72 = v71[v70++].m_a;
        v71[v70 - 1].m_a = *(_DWORD *)&v81[4 * v72];
        v71[v70 - 1].m_b = *(_DWORD *)&v81[4 * v71[v70 - 1].m_b];
      }
      while ( v69 < mesh->m_edges.m_size );
    }
    v3->m_enum = HK_SUCCESS;
    goto LABEL_83;
  }
  v3->m_enum = HK_FAILURE;
  v76 = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * v12);
  array = 0i64;
LABEL_99:
  v77 = 0x80000000;
  hkaiNavMesh::~hkaiNavMesh(&mesha);
  return v3;
}

// File Line: 4089
// RVA: 0xB58AF0
void __fastcall mergeDegenerateSharedEdges(hkaiNavMesh *mesh)
{
  int v1; // edx
  __int64 v2; // r8
  hkaiNavMesh::Edge *m_data; // rbx
  __int64 m_oppositeEdge; // rax
  int m_a; // r9d
  int v6; // r10d

  v1 = 0;
  if ( mesh->m_edges.m_size > 0 )
  {
    v2 = 0i64;
    do
    {
      m_data = mesh->m_edges.m_data;
      m_oppositeEdge = (int)m_data[v2].m_oppositeEdge;
      if ( (_DWORD)m_oppositeEdge != -1 )
      {
        m_a = m_data[v2].m_a;
        v6 = m_data[m_oppositeEdge].m_a;
        if ( m_a == m_data[v2].m_b )
        {
          if ( v6 != m_data[m_oppositeEdge].m_b )
          {
            m_data[m_oppositeEdge].m_b = m_a;
            m_data[m_oppositeEdge].m_a = m_a;
          }
        }
        else if ( v6 == m_data[m_oppositeEdge].m_b )
        {
          m_data[v2].m_b = v6;
          m_data[v2].m_a = v6;
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
  int m_size; // esi
  int v5; // edi
  __int32 v6; // eax
  _DWORD *v7; // rcx
  int v8; // r8d
  int v9; // r9d
  __int64 v10; // r8
  void *v11; // rdx
  int v13; // eax
  _DWORD *v14; // rdi
  __int64 i; // rcx
  int v16; // r10d
  __int64 v17; // r11
  int v18; // edi
  hkaiNavMesh::Face *v19; // r8
  int m_numEdges; // r9d
  int v21; // ecx
  hkaiNavMesh::Edge *v22; // rdx
  int v23; // esi
  int v24; // r8d
  int v25; // r9d
  int v26; // edi
  __int64 v27; // r8
  int v28; // r8d
  __int64 v29; // r9
  hkaiNavMesh::Face *m_data; // rdi
  __int64 m_startEdgeIndex; // rdx
  int v32; // edi
  __int64 v33; // r8
  hkaiNavMesh::Edge *v34; // r9
  __int64 m_oppositeEdge; // rdx
  int v36; // edi
  __int64 v37; // rsi
  int v38; // esi
  __int64 v39; // r14
  int v40; // edx
  __int64 v41; // rdi
  hkaiNavMesh::Edge *v42; // r8
  unsigned int m_oppositeFace; // ecx
  int v44; // r14d
  __int64 v45; // r15
  hkaiNavMesh::Face *v46; // r8
  __int16 v47; // di
  __int64 v48; // rdx
  hkaiNavMesh::Edge *v49; // r10
  hkaiNavMesh::Edge *v50; // rsi
  hkaiNavMesh::Edge *v51; // r11
  __int64 v52; // rax
  __int64 v53; // r9
  __int64 v54; // rcx
  int v55; // edx
  hkaiNavMesh::Edge *v56; // rdi
  __int64 v57; // rax
  int v58; // r9d
  _DWORD *v59; // [rsp+30h] [rbp-48h] BYREF
  int v60; // [rsp+38h] [rbp-40h]
  int v61; // [rsp+3Ch] [rbp-3Ch]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+40h] [rbp-38h] BYREF
  _DWORD *array; // [rsp+50h] [rbp-28h] BYREF
  int v64; // [rsp+58h] [rbp-20h]
  int v65; // [rsp+5Ch] [rbp-1Ch]
  int v66; // [rsp+60h] [rbp-18h]
  hkResult resulta; // [rsp+B8h] [rbp+40h] BYREF
  hkResult v68; // [rsp+C0h] [rbp+48h] BYREF

  m_size = mesh->m_edges.m_size;
  v65 = 0x80000000;
  v5 = (m_size + 31) >> 5;
  array = 0i64;
  v64 = 0;
  v6 = v5;
  if ( v5 )
  {
    resulta.m_enum = 4 * v5;
    v7 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &resulta);
    v6 = resulta.m_enum / 4;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 0x80000000;
  array = v7;
  if ( v6 )
    v8 = v6;
  v64 = (m_size + 31) >> 5;
  v66 = m_size;
  v65 = v8;
  if ( (v8 & 0x3FFFFFFF) < v5 )
  {
    v9 = (m_size + 31) >> 5;
    if ( v5 < 2 * (v8 & 0x3FFFFFFF) )
      v9 = 2 * (v8 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v9, 4);
    v8 = v65;
  }
  v64 = (m_size + 31) >> 5;
  if ( !array )
  {
    result->m_enum = HK_FAILURE;
    v64 = 0;
    if ( v8 >= 0 )
    {
      v10 = (unsigned int)(4 * v8);
      v11 = 0i64;
LABEL_13:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v11, v10);
      return result;
    }
    return result;
  }
  v13 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    v14 = array;
    for ( i = (unsigned int)(v13 + 1); i; --i )
      *v14++ = 0;
  }
  v16 = 0;
  if ( mesh->m_faces.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      v18 = 0;
      v19 = &mesh->m_faces.m_data[v17];
      m_numEdges = v19->m_numEdges;
      if ( m_numEdges > 0 )
      {
        do
        {
          v21 = v18 + v19->m_startEdgeIndex;
          v22 = &mesh->m_edges.m_data[v21];
          if ( v22->m_a == v22->m_b )
          {
            array[(__int64)v21 >> 5] |= 1 << (v21 & 0x1F);
            --v19->m_numEdges;
          }
          ++v18;
        }
        while ( v18 < m_numEdges );
      }
      ++v16;
      ++v17;
    }
    while ( v16 < mesh->m_faces.m_size );
  }
  v23 = mesh->m_edges.m_size;
  v59 = 0i64;
  v60 = 0;
  v61 = 0x80000000;
  if ( v23 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_32;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v59, v23, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_32:
    v60 = v23;
    v25 = 0;
    v26 = 0;
    if ( v23 > 0 )
    {
      v27 = 0i64;
      do
      {
        v59[v27] = v25;
        if ( ((array[(__int64)v26 >> 5] >> (v26 & 0x1F)) & 1) != 0 )
          ++v25;
        ++v26;
        ++v27;
      }
      while ( v26 < v60 );
    }
    v28 = 0;
    if ( mesh->m_faces.m_size > 0 )
    {
      v29 = 0i64;
      do
      {
        m_data = mesh->m_faces.m_data;
        ++v28;
        m_startEdgeIndex = m_data[v29++].m_startEdgeIndex;
        m_data[v29 - 1].m_startEdgeIndex = m_startEdgeIndex - v59[m_startEdgeIndex];
      }
      while ( v28 < mesh->m_faces.m_size );
    }
    v32 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v33 = 0i64;
      do
      {
        v34 = mesh->m_edges.m_data;
        m_oppositeEdge = (int)v34[v33].m_oppositeEdge;
        if ( (_DWORD)m_oppositeEdge != -1 )
          v34[v33].m_oppositeEdge = m_oppositeEdge - v59[m_oppositeEdge];
        ++v32;
        ++v33;
      }
      while ( v32 < mesh->m_edges.m_size );
    }
    v36 = mesh->m_edges.m_size - 1;
    if ( v36 >= 0 )
    {
      v37 = v36;
      do
      {
        if ( ((array[v37 >> 5] >> (v36 & 0x1F)) & 1) != 0 )
          hkaiNavMesh::removeEdgeAtAndCopy(mesh, v36);
        --v37;
        --v36;
      }
      while ( v36 >= 0 );
    }
    v38 = mesh->m_faces.m_size - 1;
    if ( v38 >= 0 )
    {
      v39 = v38;
      do
      {
        if ( !mesh->m_faces.m_data[v39].m_numEdges )
        {
          hkaiNavMesh::removeFaceAtAndCopy(mesh, v38);
          v40 = 0;
          if ( mesh->m_edges.m_size > 0 )
          {
            v41 = 0i64;
            do
            {
              v42 = mesh->m_edges.m_data;
              m_oppositeFace = v42[v41].m_oppositeFace;
              if ( m_oppositeFace != -1 && (int)(m_oppositeFace & 0x3FFFFF) > v38 )
                v42[v41].m_oppositeFace = m_oppositeFace - 1;
              ++v40;
              ++v41;
            }
            while ( v40 < mesh->m_edges.m_size );
          }
        }
        --v39;
        --v38;
      }
      while ( v38 >= 0 );
    }
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 0x80000000;
    v44 = 0;
    if ( mesh->m_faces.m_size > 0 )
    {
      v45 = 0i64;
      do
      {
        v46 = &mesh->m_faces.m_data[v45];
        v47 = v46->m_numEdges;
        if ( v47 < 3 )
        {
          if ( v47 != 2
            || (v48 = v46->m_startEdgeIndex,
                v49 = mesh->m_edges.m_data,
                v50 = &v49[v48],
                v51 = &v49[(int)v48 + 1],
                v52 = (int)v50->m_oppositeEdge,
                (_DWORD)v52 == -1)
            || (v53 = (int)v51->m_oppositeEdge, (_DWORD)v53 == -1) )
          {
            v55 = 0;
            if ( v47 > 0 )
            {
              do
              {
                v56 = mesh->m_edges.m_data;
                v57 = (int)v56[v55 + v46->m_startEdgeIndex].m_oppositeEdge;
                if ( (_DWORD)v57 != -1 )
                  *(_QWORD *)&v56[v57].m_oppositeEdge = -1i64;
                ++v55;
              }
              while ( v55 < v46->m_numEdges );
            }
          }
          else
          {
            v49[v52].m_oppositeEdge = v53;
            v54 = v53;
            v49[v54].m_oppositeEdge = v50->m_oppositeEdge;
            v49[v52].m_oppositeFace = v51->m_oppositeFace;
            v49[v54].m_oppositeFace = v50->m_oppositeFace;
          }
          v58 = facesToRemove.m_size + 1;
          if ( (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) >= facesToRemove.m_size + 1 )
          {
            resulta.m_enum = HK_SUCCESS;
          }
          else
          {
            if ( v58 < 2 * (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
              v58 = 2 * (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &facesToRemove, v58, 4);
            if ( resulta.m_enum )
              goto LABEL_80;
          }
          facesToRemove.m_data[facesToRemove.m_size++] = v44;
        }
        ++v44;
        ++v45;
      }
      while ( v44 < mesh->m_faces.m_size );
    }
    hkaiNavMeshUtils::removeFaces(&v68, mesh, &facesToRemove, 0);
    if ( v68.m_enum )
LABEL_80:
      result->m_enum = HK_FAILURE;
    else
      result->m_enum = HK_SUCCESS;
    facesToRemove.m_size = 0;
    if ( facesToRemove.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        facesToRemove.m_data,
        4 * facesToRemove.m_capacityAndFlags);
    facesToRemove.m_data = 0i64;
    facesToRemove.m_capacityAndFlags = 0x80000000;
    v60 = 0;
    if ( v61 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v59, 4 * v61);
    v59 = 0i64;
    v61 = 0x80000000;
    v64 = 0;
    if ( v65 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v65);
    return result;
  }
  v24 = v61;
  result->m_enum = HK_FAILURE;
  v60 = 0;
  if ( v24 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v59, 4 * v24);
  v59 = 0i64;
  v61 = 0x80000000;
  v64 = 0;
  if ( v65 >= 0 )
  {
    v11 = array;
    v10 = (unsigned int)(4 * v65);
    goto LABEL_13;
  }
  return result;
}

// File Line: 4253
// RVA: 0xB59140
hkResult *__fastcall findUnremovableVertices(
        hkResult *result,
        hkaiNavMesh *navMesh,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitions,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segments,
        hkBitField *unremovableVerticesOut)
{
  hkArray<int,hkContainerHeapAllocator> *v6; // rbx
  hkResult *v8; // rsi
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // r9
  hkaiNavMesh *v13; // r10
  __int64 v14; // r12
  int v15; // r14d
  hkaiNavMesh::Face *v16; // rsi
  __int64 m_startEdgeIndex; // rdi
  __int64 v18; // rbx
  int m_size; // edi
  _DWORD *v20; // r11
  hkResult *v21; // rdi
  int v22; // r8d
  bool v23; // cc
  int *v24; // r8
  int v25; // edx
  __int64 v26; // rcx
  __int64 v27; // rdi
  __int64 v28; // rax
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v29; // rax
  int m_enum; // ecx
  __int64 v31; // rdi
  __int64 v32; // rax
  int v33; // edx
  int v34; // r15d
  __int64 v35; // r13
  int *v36; // r8
  hkaiNavMesh::Edge *v37; // rdi
  __int64 m_b; // rsi
  int v39; // r12d
  int v40; // r14d
  int Key; // eax
  int v42; // edx
  int v43; // edi
  __int64 j; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v45; // rax
  int v46; // r8d
  hkResult resulta; // [rsp+30h] [rbp-50h] BYREF
  __int64 v48; // [rsp+38h] [rbp-48h]
  __int64 v49; // [rsp+40h] [rbp-40h]
  _DWORD *array; // [rsp+48h] [rbp-38h] BYREF
  int v51; // [rsp+50h] [rbp-30h]
  int v52; // [rsp+54h] [rbp-2Ch]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v53; // [rsp+58h] [rbp-28h] BYREF

  v6 = partitions;
  v8 = result;
  if ( unremovableVerticesOut->m_storage.m_words.m_size - 1 >= 0 )
  {
    m_data = unremovableVerticesOut->m_storage.m_words.m_data;
    for ( i = (unsigned int)unremovableVerticesOut->m_storage.m_words.m_size; i; --i )
      *m_data++ = 0;
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v53);
  if ( !v53.m_elem )
  {
    v8->m_enum = HK_FAILURE;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v53);
    return v8;
  }
  v13 = navMesh;
  v14 = 0i64;
  v15 = 0;
  if ( navMesh->m_faces.m_size > 0 )
  {
    while ( 1 )
    {
      v16 = &v13->m_faces.m_data[v14];
      m_startEdgeIndex = v16->m_startEdgeIndex;
      if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v16->m_numEdges )
        break;
LABEL_12:
      ++v15;
      ++v14;
      if ( v15 >= v13->m_faces.m_size )
      {
        v6 = partitions;
        v8 = result;
        goto LABEL_14;
      }
    }
    v18 = m_startEdgeIndex;
    while ( 1 )
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
        &v53,
        &resulta,
        v13->m_edges.m_data[v18].m_a,
        v15);
      if ( resulta.m_enum )
        break;
      v13 = navMesh;
      LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
      ++v18;
      if ( (int)m_startEdgeIndex >= v16->m_startEdgeIndex + v16->m_numEdges )
        goto LABEL_12;
    }
    v21 = result;
    result->m_enum = HK_FAILURE;
    goto LABEL_57;
  }
LABEL_14:
  m_size = v13->m_faces.m_size;
  v20 = 0i64;
  array = 0i64;
  v51 = 0;
  v52 = 0x80000000;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_22;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v20 = array;
    v13 = navMesh;
LABEL_22:
    v23 = numFacesInPartition->m_size <= 0;
    v24 = v6->m_data;
    v51 = m_size;
    v25 = 0;
    if ( !v23 )
    {
      m_elem = 0i64;
      do
      {
        v26 = 0i64;
        v27 = *(int *)((char *)&m_elem->key + (unsigned __int64)numFacesInPartition->m_data);
        if ( v27 > 0 )
        {
          do
          {
            v28 = v24[v26++];
            v20[v28] = v25;
            v20 = array;
          }
          while ( v26 < v27 );
        }
        ++v25;
        m_elem = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)((char *)m_elem + 4);
        v24 += v27;
      }
      while ( v25 < numFacesInPartition->m_size );
    }
    v29 = segments;
    m_enum = 0;
    v23 = segments->m_size <= 0;
    resulta.m_enum = HK_SUCCESS;
    if ( !v23 )
    {
      v31 = 0i64;
      v48 = 0i64;
      do
      {
        v32 = (__int64)v29->m_data + v31;
        v49 = v32;
        if ( *(_DWORD *)(v32 + 8) != -1 )
        {
          v33 = *(_DWORD *)(v32 + 24);
          v34 = 0;
          if ( v33 > 0 )
          {
            v35 = 0i64;
            do
            {
              v36 = *(int **)(v32 + 16);
              v37 = v13->m_edges.m_data;
              m_b = v37[v36[v35]].m_b;
              m_elem = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)&v37[v36[v35]];
              if ( v34 != v33 - 1 || (_DWORD)m_b == v37[*v36].m_a )
              {
                v39 = v20[v37[SLODWORD(m_elem->val)].m_oppositeFace];
                v40 = v20[SHIDWORD(m_elem->val)];
                Key = (unsigned int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                                      &v53,
                                      v37[v36[v35]].m_b);
                v20 = array;
                if ( Key <= v53.m_hashMod )
                {
                  m_elem = v53.m_elem;
                  while ( 1 )
                  {
                    v42 = array[SLODWORD(v53.m_elem[Key].val)];
                    if ( v42 != v39 && v42 != v40 )
                      break;
                    v43 = Key + 1;
                    for ( j = Key + 1; j > v53.m_hashMod; j = 0i64 )
LABEL_44:
                      v43 = 0;
                    v45 = &v53.m_elem[j];
                    while ( v45->key != -1i64 )
                    {
                      if ( v45->key == m_b )
                      {
                        Key = v43;
                        goto LABEL_47;
                      }
                      ++j;
                      ++v43;
                      ++v45;
                      if ( j > v53.m_hashMod )
                        goto LABEL_44;
                    }
                    Key = v53.m_hashMod + 1;
LABEL_47:
                    if ( Key > v53.m_hashMod )
                      goto LABEL_50;
                  }
                  unremovableVerticesOut->m_storage.m_words.m_data[m_b >> 5] |= 1 << (m_b & 0x1F);
                  v20 = array;
                }
LABEL_50:
                v13 = navMesh;
              }
              v32 = v49;
              ++v34;
              ++v35;
              v33 = *(_DWORD *)(v49 + 24);
            }
            while ( v34 < v33 );
            m_enum = resulta.m_enum;
            v31 = v48;
          }
        }
        v29 = segments;
        ++m_enum;
        v31 += 48i64;
        resulta.m_enum = m_enum;
        v48 = v31;
      }
      while ( m_enum < segments->m_size );
    }
    v21 = result;
    v46 = v52;
    v51 = 0;
    result->m_enum = HK_SUCCESS;
    if ( v46 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v20,
        (unsigned int)(4 * v46),
        m_elem);
    array = 0i64;
    v52 = 0x80000000;
LABEL_57:
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v53);
    return v21;
  }
  v22 = v52;
  v8->m_enum = HK_FAILURE;
  v51 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v22);
  array = 0i64;
  v52 = 0x80000000;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v53);
  return v8;
}

// File Line: 4326
// RVA: 0xB4CA10
hkaiNavMeshSimplificationUtils::SimplificationResult __fastcall hkaiNavMeshSimplificationUtils::simplifyNavMesh(
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMesh,
        hkaiNavMesh *navMeshOut,
        hkaiNavMeshGenerationProgressCallback *callback)
{
  return hkaiNavMeshSimplificationUtils::_simplifyNavMesh(settings, navMesh, navMeshOut, 0i64, callback);
}

// File Line: 4332
// RVA: 0xB4CA30
hkaiNavMeshSimplificationUtils::SimplificationResult __fastcall hkaiNavMeshSimplificationUtils::simplifyWallClimbingNavMesh(
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMesh,
        hkaiNavMesh *navMeshOut,
        hkaiNavMeshGenerationProgressCallback *callback)
{
  return hkaiNavMeshSimplificationUtils::_simplifyNavMesh(settings, navMesh, navMeshOut, 0i64, callback);
}

// File Line: 4341
// RVA: 0xB4CA50
__int64 __fastcall hkaiNavMeshSimplificationUtils::_simplifyNavMesh(
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMesh,
        hkaiNavMesh *navMeshOut,
        hkaiEdgeGeometryRaycaster *raycaster,
        hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  bool v6; // r14
  hkaiNavMeshGenerationProgressCallback *callbacks; // r12
  unsigned int v11; // r14d
  int m_size; // r14d
  int v13; // edi
  int v14; // eax
  unsigned int *m_data; // r8
  int v16; // ecx
  int v17; // ecx
  int v18; // r9d
  int v19; // r14d
  int v20; // edi
  int v21; // ecx
  unsigned int *v22; // r8
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  __int64 v27; // rcx
  unsigned int *v28; // rdi
  int i; // r15d
  int v30; // eax
  hkArray<int,hkContainerHeapAllocator> *p_partitionDir; // rax
  int v32; // r15d
  int v33; // edi
  hkResultEnum m_enum; // eax
  float *v35; // rcx
  int v36; // ecx
  int v37; // ecx
  int v38; // r9d
  int v39; // r15d
  int v40; // r9d
  int v41; // eax
  float *v42; // rdi
  __int64 j; // rcx
  int v44; // r8d
  int v45; // edi
  __int64 v46; // r9
  __int64 v47; // rdx
  hkaiNavMesh::Edge *v48; // rax
  int v49; // edi
  __int64 v50; // rdx
  int k; // edi
  int v52; // ecx
  int m_capacityAndFlags; // r8d
  int v54; // eax
  int v55; // r8d
  int v56; // edi
  int v57; // r8d
  __int64 v58; // rdi
  __int64 v59; // r9
  hkaiNavMesh::Edge *v60; // rcx
  __int64 m_b; // rax
  __int64 m_a; // rdx
  unsigned __int64 v63; // rcx
  int v64; // edi
  __int64 v65; // rdx
  __int64 m_edgeId; // rax
  __int64 m_edgeDataStriding; // r8
  __int64 v68; // r12
  hkaiNavMesh::Edge *v69; // r11
  int v70; // r10d
  int v71; // r8d
  __int64 v72; // r8
  __int64 v73; // r8
  __int64 v74; // r8
  unsigned int v75; // eax
  int v76; // r9d
  int v77; // edx
  int v78; // r15d
  int v79; // eax
  int v80; // eax
  int v81; // r9d
  char *v82; // rdi
  __int64 v83; // rcx
  int v84; // r9d
  __int64 v85; // rdi
  hkaiNavMesh::Face *v86; // r8
  __int64 m_startEdgeIndex; // rcx
  __int64 v88; // rdx
  int v89; // r15d
  unsigned int v90; // eax
  int v91; // edx
  int v92; // eax
  int v93; // eax
  int v94; // r9d
  char *v95; // rdi
  __int64 v96; // rcx
  int v97; // edx
  __int64 v98; // rdi
  __int64 v99; // rax
  int v100; // eax
  __int64 v101; // r9
  __int64 v102; // r8
  __int64 v103; // r10
  hkaiNavMesh::Edge *v104; // r15
  int v105; // edx
  __int64 v106; // rdi
  __int64 v107; // rcx
  hkaiNavMesh::Edge *v108; // rdx
  __int64 v109; // rdi
  __int64 v110; // rax
  float *p_m_hertelMehlhornHeightError; // r9
  hkResult *v112; // rcx
  int v113; // edi
  __int64 m; // r8
  int v115; // esi
  hkaiNavMeshSimplificationUtils::Segment *v116; // rdi
  hkResult v118; // [rsp+70h] [rbp-90h] BYREF
  EdgeKey *pArr; // [rsp+78h] [rbp-88h] BYREF
  int v120; // [rsp+80h] [rbp-80h]
  int v121; // [rsp+84h] [rbp-7Ch]
  char *v122; // [rsp+88h] [rbp-78h] BYREF
  int v123; // [rsp+90h] [rbp-70h]
  int v124; // [rsp+94h] [rbp-6Ch]
  char *v125; // [rsp+98h] [rbp-68h] BYREF
  int v126; // [rsp+A0h] [rbp-60h]
  int v127; // [rsp+A4h] [rbp-5Ch]
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> segmentsOut; // [rsp+A8h] [rbp-58h] BYREF
  hkArrayBase<unsigned int> faceData; // [rsp+B8h] [rbp-48h] BYREF
  hkArray<int,hkContainerHeapAllocator> numEdgesInGroupOut; // [rsp+C8h] [rbp-38h] BYREF
  hkArray<int,hkContainerHeapAllocator> oppositeEdges; // [rsp+D8h] [rbp-28h] BYREF
  hkArray<int,hkContainerHeapAllocator> numFacesInPartition; // [rsp+E8h] [rbp-18h] BYREF
  hkArray<int,hkContainerHeapAllocator> partitions; // [rsp+F8h] [rbp-8h] BYREF
  hkResult v134; // [rsp+108h] [rbp+8h] BYREF
  hkResult v135; // [rsp+10Ch] [rbp+Ch] BYREF
  hkResult v136; // [rsp+110h] [rbp+10h] BYREF
  hkResult v137; // [rsp+114h] [rbp+14h] BYREF
  hkArray<int,hkContainerHeapAllocator> edgesToRemoveOut; // [rsp+118h] [rbp+18h] BYREF
  int v139; // [rsp+128h] [rbp+28h] BYREF
  hkResult v140; // [rsp+12Ch] [rbp+2Ch] BYREF
  hkArray<int,hkContainerHeapAllocator> partitionDir; // [rsp+130h] [rbp+30h] BYREF
  hkaMatrix<float> edgeIsBoundary; // [rsp+140h] [rbp+40h] BYREF
  hkArray<int,hkContainerHeapAllocator> faceToPartitionMapInOut; // [rsp+158h] [rbp+58h] BYREF
  hkArray<int,hkContainerHeapAllocator> segmentToOppositeMap; // [rsp+168h] [rbp+68h] BYREF
  hkBitField array; // [rsp+178h] [rbp+78h] BYREF
  hkBitField unremovableVertices; // [rsp+190h] [rbp+90h] BYREF
  hkResult v147; // [rsp+1A8h] [rbp+A8h] BYREF
  hkResult v148; // [rsp+1ACh] [rbp+ACh] BYREF
  hkResult v149; // [rsp+1B0h] [rbp+B0h] BYREF
  hkResult v150; // [rsp+1B4h] [rbp+B4h] BYREF
  hkResult v151; // [rsp+1B8h] [rbp+B8h] BYREF
  hkResult v152; // [rsp+1BCh] [rbp+BCh] BYREF
  hkResult v153; // [rsp+1C0h] [rbp+C0h] BYREF
  hkResult v154; // [rsp+1C4h] [rbp+C4h] BYREF
  hkResult result; // [rsp+1C8h] [rbp+C8h] BYREF
  hkaiNavMeshGenerationProgressCallback *v156; // [rsp+1D0h] [rbp+D0h]
  hkPointerMap<int,int,hkContainerHeapAllocator> vertexIndexMapOut; // [rsp+1D8h] [rbp+D8h] BYREF
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > userVertexOnBoundary; // [rsp+1E8h] [rbp+E8h] BYREF
  hkaiNavMeshGenerationProgressCallbackContext v159; // [rsp+200h] [rbp+100h] BYREF
  hkResult v160; // [rsp+270h] [rbp+170h] BYREF
  hkResult v161; // [rsp+274h] [rbp+174h] BYREF
  hkResult v162; // [rsp+278h] [rbp+178h] BYREF
  char v163; // [rsp+27Ch] [rbp+17Ch] BYREF
  void **v164; // [rsp+280h] [rbp+180h] BYREF
  hkResult v165; // [rsp+288h] [rbp+188h] BYREF
  hkaiNavMesh origMesh; // [rsp+290h] [rbp+190h] BYREF
  bool v168; // [rsp+388h] [rbp+288h]

  v6 = settings->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v164 = &hkaiNavMeshGenerationProgressCallback::`vftable;
  callbacks = (hkaiNavMeshGenerationProgressCallback *)&v164;
  if ( _callbacks )
    callbacks = _callbacks;
  v168 = v6;
  v156 = callbacks;
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&v159, settings);
  v159.m_originalMesh = navMesh;
  v159.m_simplifiedMesh = navMesh;
  if ( !callbacks->vfptr->stepStartedCallback(callbacks, END|BEGIN|0x8, &v159)
    || !callbacks->vfptr->stepEndedCallback(callbacks, END|BEGIN|0x8, &v159) )
  {
    return 0i64;
  }
  navMeshOut->m_vertices.m_size = 0;
  navMeshOut->m_faces.m_size = 0;
  navMeshOut->m_faceData.m_size = 0;
  navMeshOut->m_edges.m_size = 0;
  navMeshOut->m_edgeData.m_size = 0;
  navMeshOut->m_erosionRadius = navMesh->m_erosionRadius;
  hkaiNavMesh::hkaiNavMesh(&origMesh);
  numFacesInPartition.m_data = 0i64;
  numFacesInPartition.m_size = 0;
  numFacesInPartition.m_capacityAndFlags = 0x80000000;
  partitionDir.m_data = 0i64;
  partitionDir.m_size = 0;
  partitionDir.m_capacityAndFlags = 0x80000000;
  partitions.m_data = 0i64;
  partitions.m_size = 0;
  partitions.m_capacityAndFlags = 0x80000000;
  edgesToRemoveOut.m_data = 0i64;
  edgesToRemoveOut.m_size = 0;
  edgesToRemoveOut.m_capacityAndFlags = 0x80000000;
  if ( !settings->m_simplificationSettings.m_useHeightPartitioning.m_bool
    || !settings->m_simplificationSettings.m_useConservativeHeightPartitioning.m_bool
    || (hkaiNavMesh::copy(&origMesh, &result, navMesh), result.m_enum == HK_SUCCESS) )
  {
    if ( !callbacks->vfptr->stepStartedCallback(
            callbacks,
            (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)12i64,
            &v159) )
    {
      v11 = 0;
      goto LABEL_276;
    }
    if ( !v6 )
    {
      hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices(&v118, settings, navMesh);
      if ( v118.m_enum )
      {
        v11 = 1;
        goto LABEL_276;
      }
      mergeDegenerateSharedEdges(navMesh);
      removeDegenerateEdges(&v118, navMesh);
      if ( v118.m_enum )
      {
        v11 = 1;
        goto LABEL_276;
      }
    }
    if ( !callbacks->vfptr->stepEndedCallback(
            callbacks,
            (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)12i64,
            &v159) )
    {
      v11 = 0;
      goto LABEL_276;
    }
    if ( v6 )
    {
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_276;
      }
      v159.m_numFacesInPartition = &numFacesInPartition;
      v159.m_partitions = &partitions;
      hkaiNavMeshSimplificationUtils::partitionWC(
        navMesh,
        &origMesh,
        settings,
        &numFacesInPartition,
        &partitionDir,
        &partitions);
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_276;
      }
LABEL_38:
      segmentsOut.m_data = 0i64;
      segmentsOut.m_size = 0;
      segmentsOut.m_capacityAndFlags = 0x80000000;
      v159.m_segments = &segmentsOut;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)15i64,
              &v159) )
      {
        v11 = 0;
LABEL_270:
        v115 = segmentsOut.m_size - 1;
        if ( segmentsOut.m_size - 1 >= 0 )
        {
          v116 = &segmentsOut.m_data[v115];
          do
          {
            hkaiNavMeshSimplificationUtils::Segment::`scalar deleting destructor(v116--, 0);
            --v115;
          }
          while ( v115 >= 0 );
        }
        segmentsOut.m_size = 0;
        if ( segmentsOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            segmentsOut.m_data,
            48 * (segmentsOut.m_capacityAndFlags & 0x3FFFFFFF));
        segmentsOut.m_data = 0i64;
        segmentsOut.m_capacityAndFlags = 0x80000000;
        goto LABEL_276;
      }
      hkaiNavMeshSimplificationUtils::tracePartitionBoundaries(
        &v118,
        navMesh,
        &numFacesInPartition,
        &partitions,
        &segmentsOut,
        &edgesToRemoveOut);
      if ( v118.m_enum )
      {
        v11 = 1;
        goto LABEL_270;
      }
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)15i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_270;
      }
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_270;
      }
      vertexIndexMapOut.m_map.m_elem = 0i64;
      vertexIndexMapOut.m_map.m_numElems = 0;
      vertexIndexMapOut.m_map.m_hashMod = -1;
      hkaiNavMeshSimplificationUtils::setSegmentIndices(
        &v118,
        navMesh,
        &segmentsOut,
        &navMeshOut->m_vertices,
        &vertexIndexMapOut);
      if ( v118.m_enum )
      {
        v11 = 1;
LABEL_269:
        hkPointerMap<int,int,hkContainerHeapAllocator>::~hkPointerMap<int,int,hkContainerHeapAllocator>((hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&vertexIndexMapOut);
        goto LABEL_270;
      }
      m_size = navMesh->m_vertices.m_size;
      array.m_storage.m_words.m_data = 0i64;
      array.m_storage.m_words.m_size = 0;
      array.m_storage.m_words.m_capacityAndFlags = 0x80000000;
      v13 = (m_size + 31) >> 5;
      v14 = v13;
      if ( v13 )
      {
        LODWORD(_callbacks) = 4 * v13;
        m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerHeapAllocator::s_alloc,
                                   &_callbacks);
        v14 = (int)_callbacks / 4;
      }
      else
      {
        m_data = 0i64;
      }
      v16 = 0x80000000;
      array.m_storage.m_words.m_data = m_data;
      if ( v14 )
        v16 = v14;
      array.m_storage.m_words.m_size = (m_size + 31) >> 5;
      array.m_storage.m_numBits = m_size;
      array.m_storage.m_words.m_capacityAndFlags = v16;
      v17 = v16 & 0x3FFFFFFF;
      if ( v17 >= v13 )
      {
        v150.m_enum = HK_SUCCESS;
      }
      else
      {
        v18 = (m_size + 31) >> 5;
        if ( v13 < 2 * v17 )
          v18 = 2 * v17;
        hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, &array, v18, 4);
        m_data = array.m_storage.m_words.m_data;
      }
      array.m_storage.m_words.m_size = (m_size + 31) >> 5;
      if ( !m_data
        || (findUnremovableVertices(&v118, navMesh, &numFacesInPartition, &partitions, &segmentsOut, &array), v118.m_enum) )
      {
        v11 = 1;
        goto LABEL_268;
      }
      v19 = navMeshOut->m_vertices.m_size;
      unremovableVertices.m_storage.m_words.m_data = 0i64;
      unremovableVertices.m_storage.m_words.m_size = 0;
      unremovableVertices.m_storage.m_words.m_capacityAndFlags = 0x80000000;
      v20 = (v19 + 31) >> 5;
      v21 = v20;
      if ( v20 )
      {
        v139 = 4 * v20;
        v22 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerHeapAllocator::s_alloc,
                                &v139);
        v21 = v139 / 4;
      }
      else
      {
        v22 = 0i64;
      }
      v23 = 0x80000000;
      unremovableVertices.m_storage.m_words.m_data = v22;
      if ( v21 )
        v23 = v21;
      unremovableVertices.m_storage.m_words.m_size = (v19 + 31) >> 5;
      unremovableVertices.m_storage.m_numBits = v19;
      unremovableVertices.m_storage.m_words.m_capacityAndFlags = v23;
      v24 = v23 & 0x3FFFFFFF;
      if ( v24 >= v20 )
      {
        v154.m_enum = HK_SUCCESS;
      }
      else
      {
        v25 = 2 * v24;
        v26 = (v19 + 31) >> 5;
        if ( v20 < v25 )
          v26 = v25;
        hkArrayUtil::_reserve(&v154, &hkContainerHeapAllocator::s_alloc, &unremovableVertices, v26, 4);
        v22 = unremovableVertices.m_storage.m_words.m_data;
      }
      unremovableVertices.m_storage.m_words.m_size = (v19 + 31) >> 5;
      v11 = 1;
      if ( !v22 )
        goto LABEL_130;
      if ( v20 - 1 >= 0 )
      {
        v27 = (unsigned int)v20;
        v28 = v22;
        while ( v27 )
        {
          *v28++ = 0;
          --v27;
        }
      }
      for ( i = 0; i < navMesh->m_vertices.m_size; ++i )
      {
        if ( ((array.m_storage.m_words.m_data[(__int64)i >> 5] >> (i & 0x1F)) & 1) != 0 )
        {
          v30 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &vertexIndexMapOut.m_map,
                  i,
                  0xFFFFFFFFFFFFFFFFui64);
          unremovableVertices.m_storage.m_words.m_data[(__int64)v30 >> 5] |= 1 << (v30 & 0x1F);
        }
      }
      hkaiNavMeshSimplificationUtils::setMaterialSettingsIndices(
        &v118,
        settings,
        navMesh,
        &numFacesInPartition,
        &partitions,
        &segmentsOut);
      if ( v118.m_enum )
      {
LABEL_130:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&unremovableVertices);
LABEL_268:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&array);
        goto LABEL_269;
      }
      p_partitionDir = &partitionDir;
      if ( !v168 )
        p_partitionDir = 0i64;
      segmentToOppositeMap.m_data = 0i64;
      segmentToOppositeMap.m_size = 0;
      segmentToOppositeMap.m_capacityAndFlags = 0x80000000;
      hkaiNavMeshSimplificationUtils::simplifySegments(
        &v118,
        (__m128i *)settings,
        &navMeshOut->m_vertices,
        &segmentsOut,
        &segmentToOppositeMap,
        navMesh,
        &unremovableVertices,
        p_partitionDir,
        callbacks);
      if ( v118.m_enum )
      {
LABEL_127:
        segmentToOppositeMap.m_size = 0;
        if ( segmentToOppositeMap.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            segmentToOppositeMap.m_data,
            4 * segmentToOppositeMap.m_capacityAndFlags);
        segmentToOppositeMap.m_data = 0i64;
        segmentToOppositeMap.m_capacityAndFlags = 0x80000000;
        goto LABEL_130;
      }
      userVertexOnBoundary.m_storage.m_words.m_data = 0i64;
      userVertexOnBoundary.m_storage.m_words.m_size = 0;
      userVertexOnBoundary.m_storage.m_words.m_capacityAndFlags = 0x80000000;
      userVertexOnBoundary.m_storage.m_numBits = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
        &userVertexOnBoundary,
        &v118,
        0,
        settings->m_simplificationSettings.m_extraVertexSettings.m_userVertices.m_size,
        0);
      if ( v118.m_enum )
      {
LABEL_126:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&userVertexOnBoundary);
        goto LABEL_127;
      }
      v159.m_segmentVertices = &navMeshOut->m_vertices;
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)16i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_126;
      }
      oppositeEdges.m_data = 0i64;
      oppositeEdges.m_size = 0;
      oppositeEdges.m_capacityAndFlags = 0x80000000;
      faceToPartitionMapInOut.m_data = 0i64;
      faceToPartitionMapInOut.m_size = 0;
      faceToPartitionMapInOut.m_capacityAndFlags = 0x80000000;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)17i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_121;
      }
      v32 = navMesh->m_edges.m_size;
      edgeIsBoundary.m_data.m_data = 0i64;
      edgeIsBoundary.m_data.m_size = 0;
      edgeIsBoundary.m_data.m_capacityAndFlags = 0x80000000;
      v33 = (v32 + 31) >> 5;
      m_enum = v33;
      v118.m_enum = v33;
      if ( v33 )
      {
        v35 = (float *)hkMemoryAllocator::_bufAlloc<unsigned int>(&hkContainerHeapAllocator::s_alloc, (int *)&v118);
        m_enum = v118.m_enum;
      }
      else
      {
        v35 = 0i64;
      }
      edgeIsBoundary.m_data.m_data = v35;
      v36 = 0x80000000;
      if ( m_enum )
        v36 = m_enum;
      edgeIsBoundary.m_data.m_size = (v32 + 31) >> 5;
      edgeIsBoundary.m_m = v32;
      edgeIsBoundary.m_data.m_capacityAndFlags = v36;
      v37 = v36 & 0x3FFFFFFF;
      if ( v37 >= v33 )
      {
        v148.m_enum = HK_SUCCESS;
      }
      else
      {
        v38 = (v32 + 31) >> 5;
        if ( v33 < 2 * v37 )
          v38 = 2 * v37;
        hkArrayUtil::_reserve(&v148, &hkContainerHeapAllocator::s_alloc, &edgeIsBoundary, v38, 4);
      }
      edgeIsBoundary.m_data.m_size = (v32 + 31) >> 5;
      if ( !edgeIsBoundary.m_data.m_data )
      {
LABEL_120:
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&edgeIsBoundary);
        goto LABEL_121;
      }
      v39 = navMesh->m_edges.m_size;
      if ( (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF) >= v39 )
      {
        v135.m_enum = HK_SUCCESS;
      }
      else
      {
        v40 = navMesh->m_edges.m_size;
        if ( v39 < 2 * (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF) )
          v40 = 2 * (oppositeEdges.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v135, &hkContainerHeapAllocator::s_alloc, &oppositeEdges, v40, 4);
        if ( v135.m_enum )
          goto LABEL_120;
        v33 = edgeIsBoundary.m_data.m_size;
      }
      v41 = v33 - 1;
      oppositeEdges.m_size = v39;
      if ( v33 - 1 >= 0 )
      {
        v42 = edgeIsBoundary.m_data.m_data;
        for ( j = (unsigned int)(v41 + 1); j; --j )
          *v42++ = 0.0;
      }
      v44 = 0;
      v45 = 1;
      if ( navMesh->m_edges.m_size > 0 )
      {
        v46 = 0i64;
        v47 = 0i64;
        do
        {
          v48 = navMesh->m_edges.m_data;
          if ( v48[v47].m_oppositeEdge == -1 || (v48[v47].m_flags.m_storage & 0x20) != 0 )
            LODWORD(edgeIsBoundary.m_data.m_data[(__int64)v44 >> 5]) |= v45;
          v45 = __ROL4__(v45, 1);
          ++v44;
          oppositeEdges.m_data[v46++] = navMesh->m_edges.m_data[v47++].m_oppositeEdge;
        }
        while ( v44 < navMesh->m_edges.m_size );
      }
      hkaiNavMesh::setEdgeDataStriding(navMesh, &v165, 0, 0);
      faceData.m_data = 0i64;
      faceData.m_size = 0;
      faceData.m_capacityAndFlags = 0x80000000;
      v49 = navMesh->m_faces.m_size;
      if ( v49 <= 0 )
      {
        v137.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v137, &hkContainerHeapAllocator::s_alloc, &faceData, navMesh->m_faces.m_size, 4);
        if ( v137.m_enum )
        {
LABEL_117:
          faceData.m_size = 0;
          if ( faceData.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              faceData.m_data,
              4 * faceData.m_capacityAndFlags);
          faceData.m_data = 0i64;
          faceData.m_capacityAndFlags = 0x80000000;
          goto LABEL_120;
        }
      }
      faceData.m_size = v49;
      v50 = 0i64;
      for ( k = 0; k < navMesh->m_faces.m_size; faceData.m_data[v50 - 1] = v52 )
      {
        if ( navMesh->m_faceDataStriding )
          v52 = navMesh->m_faceData.m_data[v50 * navMesh->m_faceDataStriding];
        else
          v52 = 0;
        ++k;
        ++v50;
      }
      hkaiNavMesh::setFaceDataStriding(navMesh, &v162, 0, 0);
      hkaiNavMeshSimplificationUtils::addVerticesBetweenSegments(
        &v118,
        settings,
        &navMeshOut->m_vertices,
        &segmentsOut,
        &segmentToOppositeMap,
        navMesh,
        (hkBitField *)&userVertexOnBoundary,
        &oppositeEdges);
      if ( v118.m_enum )
        goto LABEL_117;
      hkaiNavMeshSimplificationUtils::triangulatePartitions(
        &v149,
        settings,
        v168,
        navMesh,
        navMeshOut,
        &segmentsOut,
        &partitions,
        &numFacesInPartition,
        &partitionDir,
        &faceToPartitionMapInOut,
        (hkBitField *)&edgeIsBoundary,
        (hkBitField *)&userVertexOnBoundary,
        &faceData);
      if ( v149.m_enum )
        goto LABEL_117;
      if ( !callbacks->vfptr->stepEndedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)17i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_117;
      }
      faceData.m_size = 0;
      if ( faceData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          faceData.m_data,
          4 * faceData.m_capacityAndFlags);
      faceData.m_data = 0i64;
      faceData.m_capacityAndFlags = 0x80000000;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&edgeIsBoundary);
      navMesh->m_faces.m_size = 0;
      m_capacityAndFlags = navMesh->m_faces.m_capacityAndFlags;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          navMesh->m_faces.m_data,
          16 * m_capacityAndFlags);
      navMesh->m_faces.m_data = 0i64;
      navMesh->m_faces.m_capacityAndFlags = 0x80000000;
      navMesh->m_edges.m_size = 0;
      v54 = navMesh->m_edges.m_capacityAndFlags;
      if ( v54 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          navMesh->m_edges.m_data,
          20 * (v54 & 0x3FFFFFFF));
      navMesh->m_edges.m_data = 0i64;
      navMesh->m_edges.m_capacityAndFlags = 0x80000000;
      navMesh->m_vertices.m_size = 0;
      v55 = navMesh->m_vertices.m_capacityAndFlags;
      if ( v55 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          navMesh->m_vertices.m_data,
          16 * v55);
      navMesh->m_vertices.m_data = 0i64;
      navMesh->m_vertices.m_capacityAndFlags = 0x80000000;
      if ( !callbacks->vfptr->stepStartedCallback(
              callbacks,
              (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)18i64,
              &v159) )
      {
        v11 = 0;
        goto LABEL_121;
      }
      pArr = 0i64;
      v120 = 0;
      v121 = 0x80000000;
      v56 = navMeshOut->m_edges.m_size;
      if ( v56 <= 0 )
      {
        v136.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v136, &hkContainerHeapAllocator::s_alloc, &pArr, navMeshOut->m_edges.m_size, 16);
        if ( v136.m_enum )
        {
LABEL_238:
          v120 = 0;
          if ( v121 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 16 * v121);
          pArr = 0i64;
          v121 = 0x80000000;
          goto LABEL_121;
        }
      }
      v120 = v56;
      v57 = 0;
      if ( navMeshOut->m_edges.m_size > 0 )
      {
        v58 = 0i64;
        v59 = 0i64;
        do
        {
          v60 = navMeshOut->m_edges.m_data;
          pArr[v58].m_edgeId = v57;
          pArr[v58].m_faceId = v57 / 3;
          m_b = v60[v59].m_b;
          m_a = v60[v59].m_a;
          if ( (int)m_a >= (int)m_b )
            v63 = m_a | (m_b << 32);
          else
            v63 = m_b | (m_a << 32);
          ++v57;
          pArr[v58++].m_key = v63;
          ++v59;
        }
        while ( v57 < navMeshOut->m_edges.m_size );
      }
      if ( v120 > 1 )
        hkAlgorithm::quickSortRecursive<EdgeKey,hkAlgorithm::less<EdgeKey>>(pArr, 0, v120 - 1, 0);
      v64 = 0;
      if ( v120 - 1 > 0 )
      {
        v65 = 0i64;
        do
        {
          if ( pArr[v65].m_key == pArr[v65 + 1].m_key )
          {
            m_edgeId = pArr[v65].m_edgeId;
            m_edgeDataStriding = navMeshOut->m_edgeDataStriding;
            v68 = pArr[v65 + 1].m_edgeId;
            v69 = navMeshOut->m_edges.m_data;
            if ( (_DWORD)m_edgeDataStriding )
              v70 = navMeshOut->m_edgeData.m_data[m_edgeId * m_edgeDataStriding];
            else
              v70 = 0;
            if ( (_DWORD)m_edgeDataStriding )
              v71 = navMeshOut->m_edgeData.m_data[pArr[v65 + 1].m_edgeId * m_edgeDataStriding];
            else
              v71 = 0;
            if ( v70 != -1 && v71 != -1 )
            {
              v69[m_edgeId].m_oppositeEdge = v68;
              v72 = v68;
              v69[m_edgeId].m_oppositeFace = pArr[v65 + 1].m_faceId;
              v69[v72].m_oppositeEdge = pArr[v65].m_edgeId;
              v69[v72].m_oppositeFace = pArr[v65].m_faceId;
              v73 = navMeshOut->m_edgeDataStriding;
              if ( (_DWORD)v73 )
                navMeshOut->m_edgeData.m_data[v73 * pArr[v65].m_edgeId] = -1;
              v74 = navMeshOut->m_edgeDataStriding;
              if ( (_DWORD)v74 )
                navMeshOut->m_edgeData.m_data[v74 * pArr[v65 + 1].m_edgeId] = -1;
            }
            v64 += 2;
            v65 += 2i64;
          }
          else
          {
            ++v64;
            ++v65;
          }
        }
        while ( v64 < v120 - 1 );
        callbacks = v156;
      }
      v75 = 0x80000000;
      v122 = 0i64;
      v123 = 0;
      v124 = 0x80000000;
      v76 = navMeshOut->m_edges.m_size;
      v77 = 0;
      if ( v76 <= 0 )
      {
        v140.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v140, &hkContainerTempAllocator::s_alloc, &v122, v76, 4);
        if ( v140.m_enum )
        {
LABEL_235:
          v123 = 0;
          if ( v124 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v122, 4 * v124);
          v122 = 0i64;
          v124 = 0x80000000;
          goto LABEL_238;
        }
        v75 = v124;
        v77 = v123;
      }
      v78 = navMeshOut->m_edges.m_size;
      v79 = v75 & 0x3FFFFFFF;
      if ( v79 >= v78 )
      {
        v151.m_enum = HK_SUCCESS;
      }
      else
      {
        v80 = 2 * v79;
        v81 = navMeshOut->m_edges.m_size;
        if ( v78 < v80 )
          v81 = v80;
        hkArrayUtil::_reserve(&v151, &hkContainerTempAllocator::s_alloc, &v122, v81, 4);
        v77 = v123;
      }
      v82 = &v122[4 * v77];
      v83 = v78 - v77;
      if ( v78 - v77 > 0 )
      {
        while ( v83 )
        {
          *(_DWORD *)v82 = -1;
          v82 += 4;
          --v83;
        }
      }
      v123 = v78;
      v84 = 0;
      if ( navMeshOut->m_faces.m_size > 0 )
      {
        v85 = 0i64;
        do
        {
          v86 = navMeshOut->m_faces.m_data;
          m_startEdgeIndex = v86[v85].m_startEdgeIndex;
          if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v86[v85].m_numEdges )
          {
            v88 = 4 * m_startEdgeIndex;
            do
            {
              LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
              v88 += 4i64;
              *(_DWORD *)&v122[v88 - 4] = v84;
            }
            while ( (int)m_startEdgeIndex < v86[v85].m_startEdgeIndex + v86[v85].m_numEdges );
          }
          ++v84;
          ++v85;
        }
        while ( v84 < navMeshOut->m_faces.m_size );
      }
      v89 = oppositeEdges.m_size;
      v90 = 0x80000000;
      v125 = 0i64;
      v91 = 0;
      v126 = 0;
      v127 = 0x80000000;
      if ( oppositeEdges.m_size <= 0 )
      {
        v134.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v134, &hkContainerTempAllocator::s_alloc, &v125, oppositeEdges.m_size, 4);
        if ( v134.m_enum )
        {
LABEL_232:
          v126 = 0;
          if ( v127 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v125, 4 * v127);
          v125 = 0i64;
          v127 = 0x80000000;
          goto LABEL_235;
        }
        v89 = oppositeEdges.m_size;
        v90 = v127;
        v91 = v126;
      }
      v92 = v90 & 0x3FFFFFFF;
      if ( v92 >= v89 )
      {
        v153.m_enum = HK_SUCCESS;
      }
      else
      {
        v93 = 2 * v92;
        v94 = v89;
        if ( v89 < v93 )
          v94 = v93;
        hkArrayUtil::_reserve(&v153, &hkContainerTempAllocator::s_alloc, &v125, v94, 4);
        v91 = v126;
      }
      v95 = &v125[4 * v91];
      v96 = v89 - v91;
      if ( v89 - v91 > 0 )
      {
        while ( v96 )
        {
          *(_DWORD *)v95 = -1;
          v95 += 4;
          --v96;
        }
      }
      v126 = v89;
      v97 = 0;
      v98 = 0i64;
      if ( navMeshOut->m_edges.m_size > 0 )
      {
        while ( 1 )
        {
          v99 = navMeshOut->m_edgeDataStriding;
          if ( !(_DWORD)v99 )
            break;
          v100 = navMeshOut->m_edgeData.m_data[v98 * v99];
          if ( v100 >= 0 )
            goto LABEL_217;
LABEL_218:
          ++v97;
          ++v98;
          if ( v97 >= navMeshOut->m_edges.m_size )
            goto LABEL_219;
        }
        v100 = 0;
LABEL_217:
        *(_DWORD *)&v125[4 * v100] = v97;
        goto LABEL_218;
      }
LABEL_219:
      v101 = 0i64;
      v102 = 0i64;
      if ( navMeshOut->m_edges.m_size > 0 )
      {
        v103 = 0i64;
        while ( 1 )
        {
          v104 = navMeshOut->m_edges.m_data;
          if ( !navMeshOut->m_edgeDataStriding )
            break;
          v105 = navMeshOut->m_edgeData.m_data[v102 * navMeshOut->m_edgeDataStriding];
          if ( v105 >= 0 )
            goto LABEL_225;
LABEL_229:
          v101 = (unsigned int)(v101 + 1);
          ++v102;
          ++v103;
          if ( (int)v101 >= navMeshOut->m_edges.m_size )
            goto LABEL_230;
        }
        v105 = 0;
LABEL_225:
        v106 = oppositeEdges.m_data[v105];
        v107 = *(int *)&v125[4 * v106];
        if ( (_DWORD)v107 != -1 )
        {
          *(_DWORD *)&v125[4 * v105] = -1;
          *(_DWORD *)&v125[4 * v106] = -1;
          v108 = navMeshOut->m_edges.m_data;
          v104[v103].m_oppositeEdge = v107;
          v109 = v107;
          v108[v109].m_oppositeEdge = v101;
          v104[v103].m_oppositeFace = *(_DWORD *)&v122[4 * v107];
          v108[v109].m_oppositeFace = *(_DWORD *)&v122[4 * v102];
          v110 = navMeshOut->m_edgeDataStriding;
          if ( (_DWORD)v110 )
          {
            navMeshOut->m_edgeData.m_data[v102 * v110] = -1;
            if ( navMeshOut->m_edgeDataStriding )
              navMeshOut->m_edgeData.m_data[v107 * navMeshOut->m_edgeDataStriding] = -1;
          }
        }
        goto LABEL_229;
      }
LABEL_230:
      if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshGenerationProgressCallback *, __int64, hkaiNavMeshGenerationProgressCallbackContext *, __int64))callbacks->vfptr->stepEndedCallback)(
             callbacks,
             18i64,
             &v159,
             v101) )
      {
        v126 = 0;
        if ( v127 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v125, 4 * v127);
        v125 = 0i64;
        v127 = 0x80000000;
        v123 = 0;
        if ( v124 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v122, 4 * v124);
        v122 = 0i64;
        v124 = 0x80000000;
        v120 = 0;
        if ( v121 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 16 * v121);
        pArr = 0i64;
        v121 = 0x80000000;
        if ( callbacks->vfptr->stepStartedCallback(callbacks, END|BEGIN|0x10, &v159) )
        {
          navMeshOut->m_aabb.m_min = navMesh->m_aabb.m_min;
          navMeshOut->m_aabb.m_max = navMesh->m_aabb.m_max;
          hkaiNavMeshUtils::validate(navMeshOut, 1);
          if ( settings->m_simplificationSettings.m_useHeightPartitioning.m_bool
            && settings->m_simplificationSettings.m_useConservativeHeightPartitioning.m_bool )
          {
            if ( hkaiNavMeshSimplificationUtils::hertelMehlhorn(
                   &v160,
                   settings,
                   navMeshOut,
                   0i64,
                   &faceToPartitionMapInOut)->m_enum )
              goto LABEL_121;
            p_m_hertelMehlhornHeightError = &settings->m_simplificationSettings.m_hertelMehlhornHeightError;
            v112 = (hkResult *)&v163;
          }
          else
          {
            p_m_hertelMehlhornHeightError = 0i64;
            v112 = &v161;
          }
          if ( hkaiNavMeshSimplificationUtils::hertelMehlhorn(
                 v112,
                 settings,
                 navMeshOut,
                 p_m_hertelMehlhornHeightError,
                 0i64)->m_enum == HK_SUCCESS )
          {
            hkaiNavMeshUtils::compactVertices(&v147, navMeshOut, 0, 0);
            if ( v147.m_enum == HK_SUCCESS )
            {
              v113 = 0;
              for ( m = 0i64; v113 < navMeshOut->m_edges.m_size; ++m )
              {
                if ( navMeshOut->m_edgeDataStriding )
                  navMeshOut->m_edgeData.m_data[m * navMeshOut->m_edgeDataStriding] = 0;
                ++v113;
              }
              if ( callbacks->vfptr->stepEndedCallback(callbacks, END|BEGIN|0x10, &v159) )
              {
                if ( callbacks->vfptr->stepStartedCallback(
                       callbacks,
                       (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)20i64,
                       &v159) )
                {
                  if ( callbacks->vfptr->stepEndedCallback(
                         callbacks,
                         (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)20i64,
                         &v159) )
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
          goto LABEL_121;
        }
        v11 = 0;
LABEL_121:
        faceToPartitionMapInOut.m_size = 0;
        if ( faceToPartitionMapInOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            faceToPartitionMapInOut.m_data,
            4 * faceToPartitionMapInOut.m_capacityAndFlags);
        faceToPartitionMapInOut.m_data = 0i64;
        faceToPartitionMapInOut.m_capacityAndFlags = 0x80000000;
        oppositeEdges.m_size = 0;
        if ( oppositeEdges.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            oppositeEdges.m_data,
            4 * oppositeEdges.m_capacityAndFlags);
        oppositeEdges.m_data = 0i64;
        oppositeEdges.m_capacityAndFlags = 0x80000000;
        goto LABEL_126;
      }
      v11 = 0;
      goto LABEL_232;
    }
    numEdgesInGroupOut.m_data = 0i64;
    numEdgesInGroupOut.m_size = 0;
    v159.m_boundaryFilterNumEdgesInGroup = &numEdgesInGroupOut;
    numEdgesInGroupOut.m_capacityAndFlags = 0x80000000;
    v159.m_boundaryFilterEdgesToRemove = &edgesToRemoveOut;
    if ( callbacks->vfptr->stepStartedCallback(
           callbacks,
           (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)13i64,
           &v159) )
    {
      hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(
        &v118,
        settings,
        navMesh,
        raycaster,
        &numEdgesInGroupOut,
        &edgesToRemoveOut,
        0i64);
      if ( v118.m_enum )
      {
        v11 = 1;
LABEL_32:
        numEdgesInGroupOut.m_size = 0;
        if ( numEdgesInGroupOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            numEdgesInGroupOut.m_data,
            4 * numEdgesInGroupOut.m_capacityAndFlags);
        numEdgesInGroupOut.m_data = 0i64;
        numEdgesInGroupOut.m_capacityAndFlags = 0x80000000;
        goto LABEL_276;
      }
      if ( callbacks->vfptr->stepEndedCallback(
             callbacks,
             (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)13i64,
             &v159) )
      {
        v159.m_numFacesInPartition = &numFacesInPartition;
        v159.m_partitions = &partitions;
        if ( callbacks->vfptr->stepStartedCallback(
               callbacks,
               (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
               &v159) )
        {
          hkaiNavMeshSimplificationUtils::partition(
            &v152,
            navMesh,
            &origMesh,
            settings,
            &numFacesInPartition,
            &partitions,
            &numEdgesInGroupOut,
            &edgesToRemoveOut);
          if ( v152.m_enum )
          {
            v11 = 1;
            goto LABEL_32;
          }
          if ( callbacks->vfptr->stepEndedCallback(
                 callbacks,
                 (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)14i64,
                 &v159) )
          {
            numEdgesInGroupOut.m_size = 0;
            if ( numEdgesInGroupOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                numEdgesInGroupOut.m_data,
                4 * numEdgesInGroupOut.m_capacityAndFlags);
            numEdgesInGroupOut.m_data = 0i64;
            numEdgesInGroupOut.m_capacityAndFlags = 0x80000000;
            goto LABEL_38;
          }
        }
      }
    }
    v11 = 0;
    goto LABEL_32;
  }
  v11 = 1;
LABEL_276:
  edgesToRemoveOut.m_size = 0;
  if ( edgesToRemoveOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgesToRemoveOut.m_data,
      4 * edgesToRemoveOut.m_capacityAndFlags);
  edgesToRemoveOut.m_data = 0i64;
  edgesToRemoveOut.m_capacityAndFlags = 0x80000000;
  partitions.m_size = 0;
  if ( partitions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partitions.m_data,
      4 * partitions.m_capacityAndFlags);
  partitions.m_data = 0i64;
  partitions.m_capacityAndFlags = 0x80000000;
  partitionDir.m_size = 0;
  if ( partitionDir.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partitionDir.m_data,
      4 * partitionDir.m_capacityAndFlags);
  partitionDir.m_data = 0i64;
  partitionDir.m_capacityAndFlags = 0x80000000;
  numFacesInPartition.m_size = 0;
  if ( numFacesInPartition.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      numFacesInPartition.m_data,
      4 * numFacesInPartition.m_capacityAndFlags);
  numFacesInPartition.m_data = 0i64;
  numFacesInPartition.m_capacityAndFlags = 0x80000000;
  hkaiNavMesh::~hkaiNavMesh(&origMesh);
  return v11;
}

// File Line: 4866
// RVA: 0xB4BE60
hkResult *__fastcall hkaiNavMeshSimplificationUtils::addVerticesBetweenSegments(
        hkResult *result,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut,
        hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *segmentsInOut,
        hkArrayBase<int> *segmentToOppositeMap,
        hkaiNavMesh *navMesh,
        hkBitField *userVertexOnBoundary,
        hkArray<int,hkContainerHeapAllocator> *oppositeEdges)
{
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *p_m_extraVertexSettings; // r10
  int m_size; // eax
  hkArray<hkaiNavMeshSimplificationUtils::Segment,hkContainerHeapAllocator> *v10; // r11
  bool v12; // cf
  hkResult *v13; // rsi
  int v14; // r12d
  int v15; // r9d
  __int64 v16; // rcx
  __int64 v17; // rdx
  __int64 m_data; // r8
  int *v19; // rax
  __int64 v20; // rcx
  hkArrayBase<unsigned int> *v21; // r15
  int v22; // ebx
  int v23; // ebx
  __int64 v24; // r8
  hkVector4f *v25; // rdx
  __int64 v26; // rax
  __m128 m_quad; // xmm0
  int v28; // edi
  int v29; // ebx
  int v30; // r9d
  hkResultEnum m_enum; // eax
  int v32; // r9d
  hkResultEnum v33; // eax
  hkArray<int,hkContainerHeapAllocator> *v34; // r14
  int v35; // r9d
  int v36; // eax
  int v37; // eax
  int v38; // r8d
  hkResult *v39; // rbx
  __int64 v40; // rcx
  __int64 v41; // rdx
  __int64 v42; // r11
  __int64 v43; // r9
  unsigned int v44; // r8d
  unsigned int v45; // r10d
  unsigned int v46; // r8d
  int v47; // r9d
  int v48; // eax
  int v49; // eax
  __int64 v50; // rsi
  __int64 v51; // r14
  int v52; // eax
  int v53; // r9d
  int v54; // eax
  hkResultEnum v55; // eax
  hkArrayBase<unsigned int> *v56; // rbx
  hkArrayBase<unsigned int> *v57; // r15
  int v58; // eax
  int v59; // r9d
  int v60; // eax
  hkResultEnum v61; // eax
  int v62; // r9d
  hkArrayBase<unsigned int> *v63; // r14
  int v64; // r9d
  int v65; // eax
  int v66; // eax
  hkResultEnum v67; // eax
  hkArrayBase<unsigned int> *v68; // rsi
  int v69; // eax
  int v70; // r9d
  int v71; // eax
  hkResultEnum v72; // eax
  int v73; // ebx
  bool v74; // sf
  int v76; // r8d
  int v77; // r8d
  unsigned int *p; // [rsp+40h] [rbp-C0h] BYREF
  int v79; // [rsp+48h] [rbp-B8h]
  int v80; // [rsp+4Ch] [rbp-B4h]
  unsigned int *array; // [rsp+50h] [rbp-B0h] BYREF
  int v82; // [rsp+58h] [rbp-A8h]
  int v83; // [rsp+5Ch] [rbp-A4h]
  unsigned int *v84; // [rsp+60h] [rbp-A0h] BYREF
  int v85; // [rsp+68h] [rbp-98h]
  int v86; // [rsp+6Ch] [rbp-94h]
  unsigned int *v87; // [rsp+70h] [rbp-90h] BYREF
  int v88; // [rsp+78h] [rbp-88h]
  int v89; // [rsp+7Ch] [rbp-84h]
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeVertices; // [rsp+80h] [rbp-80h] BYREF
  hkResult v91; // [rsp+90h] [rbp-70h] BYREF
  int v92; // [rsp+94h] [rbp-6Ch]
  hkResult v93; // [rsp+98h] [rbp-68h] BYREF
  hkResult v94; // [rsp+9Ch] [rbp-64h] BYREF
  hkResult v95; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v96; // [rsp+A4h] [rbp-5Ch] BYREF
  hkResult v97; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v98; // [rsp+ACh] [rbp-54h] BYREF
  hkResult v99; // [rsp+B0h] [rbp-50h] BYREF
  int v100; // [rsp+B4h] [rbp-4Ch]
  hkResult v101; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v102; // [rsp+C0h] [rbp-40h]
  hkResult resulta; // [rsp+C8h] [rbp-38h] BYREF
  int v104; // [rsp+CCh] [rbp-34h]
  hkArrayBase<unsigned int> *v105; // [rsp+D0h] [rbp-30h]
  __int64 v106; // [rsp+D8h] [rbp-28h]
  __int64 v107; // [rsp+E0h] [rbp-20h]
  hkaiNavMeshSimplificationUtils::ExtraVertexSettings *v108; // [rsp+E8h] [rbp-18h]
  hkArrayBase<unsigned int> *v109; // [rsp+F0h] [rbp-10h]
  hkaiNavMeshSimplificationUtils::Segment *v110; // [rsp+F8h] [rbp-8h]
  hkVector4f vIn1; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f vIn0; // [rsp+110h] [rbp+10h] BYREF
  int index; // [rsp+168h] [rbp+68h]

  p_m_extraVertexSettings = &settings->m_simplificationSettings.m_extraVertexSettings;
  m_size = navMesh->m_edges.m_size;
  v10 = segmentsInOut;
  v12 = settings->m_simplificationSettings.m_extraVertexSettings.m_partitionBordersSplitLength > 0.0;
  v13 = result;
  v14 = 0;
  v108 = &settings->m_simplificationSettings.m_extraVertexSettings;
  v104 = m_size;
  if ( !v12 || !settings->m_simplificationSettings.m_extraVertexSettings.m_addVerticesOnPartitionBorders.m_bool )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v15 = 0;
  v100 = 0;
  if ( v10->m_size <= 0 )
    goto LABEL_99;
  v16 = 0i64;
  v17 = 0i64;
  v107 = 0i64;
  v102 = 0i64;
  while ( 1 )
  {
    m_data = (__int64)v10->m_data;
    v19 = segmentToOppositeMap->m_data;
    v110 = v10->m_data;
    v20 = *(int *)((char *)v19 + v16);
    if ( (_DWORD)v20 != -1 && (int)v20 >= v15 )
    {
      v21 = (hkArrayBase<unsigned int> *)(v17 + m_data + 32);
      v22 = v21->m_size;
      v105 = v21;
      v23 = v22 - 2;
      v109 = (hkArrayBase<unsigned int> *)(m_data + 48 * v20);
      v24 = v23;
      v92 = v23;
      v106 = v23;
      if ( v23 >= 0 )
        break;
    }
LABEL_97:
    ++v15;
    v17 += 48i64;
    v16 = v107 + 4;
    v100 = v15;
    v102 = v17;
    v107 += 4i64;
    if ( v15 >= v10->m_size )
    {
      v13 = result;
LABEL_99:
      v13->m_enum = HK_SUCCESS;
      return v13;
    }
  }
  index = v23 + 1;
  while ( 1 )
  {
    v25 = verticesInOut->m_data;
    v26 = (int)v21->m_data[v24 + 1];
    vIn0.m_quad = (__m128)verticesInOut->m_data[v21->m_data[v24]];
    m_quad = v25[v26].m_quad;
    edgeVertices.m_data = 0i64;
    vIn1.m_quad = m_quad;
    edgeVertices.m_size = 0;
    edgeVertices.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshSimplificationUtils::getEdgeSplitting(
      &resulta,
      &vIn0,
      &vIn1,
      p_m_extraVertexSettings,
      0,
      userVertexOnBoundary,
      &edgeVertices);
    if ( resulta.m_enum )
    {
      v13 = result;
      result->m_enum = HK_FAILURE;
LABEL_124:
      edgeVertices.m_size = 0;
      if ( edgeVertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          edgeVertices.m_data,
          16 * edgeVertices.m_capacityAndFlags);
      return v13;
    }
    v28 = edgeVertices.m_size - 2;
    if ( edgeVertices.m_size != 2 )
      break;
    edgeVertices.m_size = 0;
    if ( edgeVertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        edgeVertices.m_data,
        16 * edgeVertices.m_capacityAndFlags);
LABEL_95:
    --index;
    p_m_extraVertexSettings = v108;
    --v23;
    v24 = v106 - 1;
    v74 = v106 - 1 < 0;
    edgeVertices.m_capacityAndFlags = 0x80000000;
    --v106;
    edgeVertices.m_data = 0i64;
    v92 = v23;
    if ( v74 )
    {
      v17 = v102;
      v15 = v100;
      v10 = segmentsInOut;
      goto LABEL_97;
    }
  }
  v29 = verticesInOut->m_size;
  array = 0i64;
  v82 = 0;
  v83 = 0x80000000;
  p = 0i64;
  v79 = 0;
  v80 = 0x80000000;
  if ( v28 <= 0 )
  {
    v93.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v93, &hkContainerTempAllocator::s_alloc, &array, edgeVertices.m_size - 2, 4);
    if ( v93.m_enum )
      goto LABEL_15;
  }
  v82 = v28;
  if ( (v80 & 0x3FFFFFFF) >= v28 )
  {
    v91.m_enum = HK_SUCCESS;
    goto LABEL_23;
  }
  v30 = v28;
  if ( v28 < 2 * (v80 & 0x3FFFFFFF) )
    v30 = 2 * (v80 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(&v91, &hkContainerTempAllocator::s_alloc, &p, v30, 4);
  if ( v91.m_enum )
  {
LABEL_15:
    v13 = result;
    result->m_enum = HK_FAILURE;
LABEL_118:
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, p, 4 * v80);
    p = 0i64;
    v80 = 0x80000000;
    v82 = 0;
    if ( v83 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v83);
    array = 0i64;
    v83 = 0x80000000;
    goto LABEL_124;
  }
LABEL_23:
  v79 = v28;
  v87 = 0i64;
  v88 = 0;
  v89 = 0x80000000;
  v84 = 0i64;
  v85 = 0;
  v86 = 0x80000000;
  if ( v28 <= 0 )
  {
    m_enum = HK_SUCCESS;
    v99.m_enum = HK_SUCCESS;
    goto LABEL_27;
  }
  hkArrayUtil::_reserve(&v99, &hkContainerTempAllocator::s_alloc, &v87, v28, 4);
  m_enum = v99.m_enum;
  if ( v99.m_enum == HK_SUCCESS )
LABEL_27:
    v88 = v28;
  v93.m_enum = m_enum;
  if ( m_enum )
    goto LABEL_113;
  if ( (v86 & 0x3FFFFFFF) >= v28 )
  {
    v33 = HK_SUCCESS;
    v98.m_enum = HK_SUCCESS;
LABEL_35:
    v85 = v28;
    goto LABEL_36;
  }
  v32 = v28;
  if ( v28 < 2 * (v86 & 0x3FFFFFFF) )
    v32 = 2 * (v86 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(&v98, &hkContainerTempAllocator::s_alloc, &v84, v32, 4);
  v33 = v98.m_enum;
  if ( v98.m_enum == HK_SUCCESS )
    goto LABEL_35;
LABEL_36:
  v91.m_enum = v33;
  if ( v33 )
  {
LABEL_113:
    v77 = v86;
    v13 = result;
    v85 = 0;
    result->m_enum = HK_FAILURE;
    if ( v77 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v84, 4 * v77);
    v88 = 0;
    v86 = 0x80000000;
    v84 = 0i64;
    if ( v89 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v87, 4 * v89);
    v89 = 0x80000000;
    v87 = 0i64;
    goto LABEL_118;
  }
  v34 = oppositeEdges;
  v35 = 2 * v28 + oppositeEdges->m_size;
  v36 = oppositeEdges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v36 >= v35 )
  {
    v95.m_enum = HK_SUCCESS;
  }
  else
  {
    v37 = 2 * v36;
    if ( v35 < v37 )
      v35 = v37;
    hkArrayUtil::_reserve(&v95, &hkContainerHeapAllocator::s_alloc, oppositeEdges, v35, 4);
    if ( v95.m_enum )
    {
LABEL_41:
      v38 = v86;
      v39 = result;
      result->m_enum = HK_FAILURE;
      v85 = 0;
      if ( v38 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v84, 4 * v38);
      v88 = 0;
      v86 = 0x80000000;
      v84 = 0i64;
      if ( v89 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v87, 4 * v89);
      v79 = 0;
      v89 = 0x80000000;
      v87 = 0i64;
      if ( v80 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, p, 4 * v80);
      p = 0i64;
      v80 = 0x80000000;
      v82 = 0;
      if ( v83 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v83);
      array = 0i64;
      edgeVertices.m_size = 0;
      goto LABEL_110;
    }
  }
  v40 = v34->m_size;
  v41 = 0i64;
  v34->m_size = v40 + 2 * v28;
  v42 = (__int64)&v34->m_data[v40];
  if ( v28 > 0 )
  {
    v43 = v42 + 4;
    v44 = v14 + v104;
    v45 = v29 + v28 - 1;
    do
    {
      ++v41;
      v14 += 2;
      array[v41 - 1] = v29++;
      p[v41 - 1] = v45--;
      v87[v41 - 1] = v44;
      v46 = v44 + 1;
      v84[v41 - 1] = v46;
      v44 = v46 + 1;
      v43 += 8i64;
      *(_DWORD *)(v42 + 8 * v41 - 8) = v84[v41 - 1];
      *(_DWORD *)(v43 - 8) = v87[v41 - 1];
    }
    while ( v41 < v28 );
  }
  v47 = v28 + verticesInOut->m_size;
  v48 = verticesInOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v48 >= v47 )
  {
    LODWORD(navMesh) = 0;
  }
  else
  {
    v49 = 2 * v48;
    if ( v47 < v49 )
      v47 = v49;
    hkArrayUtil::_reserve((hkResult *)&navMesh, &hkContainerHeapAllocator::s_alloc, verticesInOut, v47, 16);
    if ( (_DWORD)navMesh )
      goto LABEL_41;
  }
  v50 = v102;
  v51 = (__int64)v110;
  v52 = v21->m_capacityAndFlags & 0x3FFFFFFF;
  v53 = v28 + *(int *)((char *)&v110->m_indices.m_size + v102);
  if ( v52 >= v53 )
  {
    v55 = HK_SUCCESS;
    v97.m_enum = HK_SUCCESS;
  }
  else
  {
    v54 = 2 * v52;
    if ( v53 < v54 )
      v53 = v54;
    hkArrayUtil::_reserve(&v97, &hkContainerHeapAllocator::s_alloc, v21, v53, 4);
    v55 = v97.m_enum;
  }
  LODWORD(navMesh) = v55;
  if ( v55 == HK_SUCCESS )
  {
    v56 = v109;
    v57 = v109 + 2;
    v58 = v109[2].m_capacityAndFlags & 0x3FFFFFFF;
    v59 = v28 + v109[2].m_size;
    if ( v58 >= v59 )
    {
      v61 = HK_SUCCESS;
      v94.m_enum = HK_SUCCESS;
    }
    else
    {
      v60 = 2 * v58;
      if ( v59 < v60 )
        v59 = v60;
      hkArrayUtil::_reserve(&v94, &hkContainerHeapAllocator::s_alloc, &v109[2], v59, 4);
      v61 = v94.m_enum;
    }
    LODWORD(navMesh) = v61;
    if ( v61 == HK_SUCCESS )
    {
      v62 = *(_DWORD *)(v50 + v51 + 24);
      v63 = (hkArrayBase<unsigned int> *)(v50 + v51);
      v64 = v28 + v62;
      v65 = v63[1].m_capacityAndFlags & 0x3FFFFFFF;
      if ( v65 >= v64 )
      {
        v67 = HK_SUCCESS;
        v101.m_enum = HK_SUCCESS;
      }
      else
      {
        v66 = 2 * v65;
        if ( v64 < v66 )
          v64 = v66;
        hkArrayUtil::_reserve(&v101, &hkContainerHeapAllocator::s_alloc, &v63[1], v64, 4);
        v67 = v101.m_enum;
      }
      LODWORD(navMesh) = v67;
      if ( v67 == HK_SUCCESS )
      {
        v68 = v56 + 1;
        v69 = v56[1].m_capacityAndFlags & 0x3FFFFFFF;
        v70 = v28 + v56[1].m_size;
        if ( v69 >= v70 )
        {
          v72 = HK_SUCCESS;
          v96.m_enum = HK_SUCCESS;
        }
        else
        {
          v71 = 2 * v69;
          if ( v70 < v71 )
            v70 = v71;
          hkArrayUtil::_reserve(&v96, &hkContainerHeapAllocator::s_alloc, &v56[1], v70, 4);
          v72 = v96.m_enum;
        }
        LODWORD(navMesh) = v72;
        if ( v72 == HK_SUCCESS )
        {
          hkArrayBase<hkVector4f>::_append(
            verticesInOut,
            &hkContainerHeapAllocator::s_alloc,
            edgeVertices.m_data + 1,
            v28);
          v73 = v56[2].m_size - v92;
          hkArrayBase<unsigned int>::_insertAt(v105, &hkContainerHeapAllocator::s_alloc, index, array, v28);
          hkArrayBase<unsigned int>::_insertAt(v57, &hkContainerHeapAllocator::s_alloc, v73 - 1, p, v28);
          hkArrayBase<unsigned int>::_insertAt(v63 + 1, &hkContainerHeapAllocator::s_alloc, index, v87, v28);
          hkArrayBase<unsigned int>::_insertAt(v68, &hkContainerHeapAllocator::s_alloc, v73 - 2, v84, v28);
          v85 = 0;
          if ( v86 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v84, 4 * v86);
          v84 = 0i64;
          v86 = 0x80000000;
          v88 = 0;
          if ( v89 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v87, 4 * v89);
          v87 = 0i64;
          v89 = 0x80000000;
          v79 = 0;
          if ( v80 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, p, 4 * v80);
          p = 0i64;
          v80 = 0x80000000;
          v82 = 0;
          if ( v83 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v83);
          array = 0i64;
          v83 = 0x80000000;
          edgeVertices.m_size = 0;
          if ( edgeVertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              edgeVertices.m_data,
              16 * edgeVertices.m_capacityAndFlags);
          v23 = v92;
          v21 = v105;
          goto LABEL_95;
        }
      }
    }
  }
  v76 = v86;
  v39 = result;
  v85 = 0;
  result->m_enum = HK_FAILURE;
  if ( v76 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v84, 4 * v76);
  v88 = 0;
  v86 = 0x80000000;
  v84 = 0i64;
  if ( v89 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v87, 4 * v89);
  v79 = 0;
  v89 = 0x80000000;
  v87 = 0i64;
  if ( v80 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, p, 4 * v80);
  v82 = 0;
  v80 = 0x80000000;
  p = 0i64;
  if ( v83 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v83);
  array = 0i64;
  edgeVertices.m_size = 0;
LABEL_110:
  v83 = 0x80000000;
  if ( edgeVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeVertices.m_data,
      16 * edgeVertices.m_capacityAndFlags);
  return v39;
}ocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, p, 4 * v80);
  v82 = 0;
  v80 = 0x80000000;
  p = 0i64;
  if ( v83 >= 0 )
    hkContainerTempAllocator::s_alloc.v

