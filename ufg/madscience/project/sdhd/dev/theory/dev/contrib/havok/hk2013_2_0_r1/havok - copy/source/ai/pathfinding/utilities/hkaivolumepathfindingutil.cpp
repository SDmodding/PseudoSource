// File Line: 42
// RVA: 0xBF8660
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(hkaiVolumePathfindingUtil::FindPathInput *this, int numGoals)
{
  hkaiVolumePathfindingUtil::FindPathInput *v2; // rdi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // eax
  int v9; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
  *(_QWORD *)&this->m_goalPoints.m_capacityAndFlags = -2147483648i64;
  this->m_goalPoints.m_data = 0i64;
  this->m_goalPoints.m_size = 0;
  this->m_goalCellKeys.m_data = 0i64;
  this->m_goalCellKeys.m_size = 0;
  this->m_goalCellKeys.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_searchParameters.m_costModifier = 0i64;
  this->m_searchParameters.m_edgeFilter = 0i64;
  this->m_searchParameters.m_lineOfSightFlags.m_storage = 1;
  *(_QWORD *)&this->m_searchParameters.m_heuristicWeight = 1065353216i64;
  this->m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = 0;
  *(_DWORD *)this->m_searchParameters.m_up.m_vec = -2147450880;
  v3 = numGoals;
  this->m_searchParameters.m_up.m_vec[2] = -32768;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_startPoint = 0i64;
  if ( numGoals > 0 )
  {
    v4 = this->m_goalCellKeys.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v4 < numGoals )
    {
      v5 = 2 * v4;
      v6 = numGoals;
      if ( numGoals < v5 )
        v6 = v5;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_goalCellKeys,
        v6,
        4);
    }
    v2->m_goalCellKeys.m_size = v3;
    v7 = v2->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v3 )
    {
      v8 = 2 * v7;
      v9 = v3;
      if ( v3 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_goalPoints,
        v9,
        16);
    }
    v2->m_goalPoints.m_size = v3;
  }
}

// File Line: 58
// RVA: 0xBF8790
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(hkaiVolumePathfindingUtil::FindPathInput *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 66
// RVA: 0xBF87D0
void __fastcall hkaiVolumePathfindingUtil::FindPathOutput::FindPathOutput(hkaiVolumePathfindingUtil::FindPathOutput *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
}

// File Line: 70
// RVA: 0xBF8F80
void __fastcall hkaiVolumePathfindingUtil::findPath(hkaiNavVolume *navVolume, hkaiVolumePathfindingUtil::FindPathInput *input, hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  hkaiNavVolume *v3; // rbx
  hkaiVolumePathfindingUtil::FindPathOutput *v4; // rdi
  hkaiVolumePathfindingUtil::FindPathInput *v5; // rsi
  int v6; // er9
  hkaiStreamingCollection::InstanceInfo *v7; // r8
  __int64 v8; // rdx
  hkaiDirectedGraphInstance **v9; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-B8h]
  hkaiNavVolumeInstance v11; // [rsp+60h] [rbp-88h]
  hkResult result; // [rsp+108h] [rbp+20h]

  v3 = navVolume;
  v4 = output;
  v5 = input;
  hkaiNavVolumeInstance::hkaiNavVolumeInstance(&v11);
  hkaiNavVolumeInstance::tempInit(&v11, v3);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v6 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v6 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v6,
      48);
  }
  v7 = array.m_instances.m_data;
  v8 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v9 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v9 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v9 - 2) = 0i64;
        *(v9 - 1) = 0i64;
        *v9 = 0i64;
        v9[1] = 0i64;
        v9[2] = 0i64;
        *((_DWORD *)v9 + 6) = -1;
      }
      v9 += 6;
      --v8;
    }
    while ( v8 );
    v7 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v7->m_volumeInstancePtr = &v11;
  array.m_instances.m_data->m_volumeMediator = 0i64;
  hkaiVolumePathfindingUtil::findPath(&array, v5, v4);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavVolumeInstance::~hkaiNavVolumeInstance(&v11);
}

// File Line: 82
// RVA: 0xBF8800
void __fastcall hkaiVolumePathfindingUtil::findPath(hkaiStreamingCollection *collection, hkaiVolumePathfindingUtil::FindPathInput *input, hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  int v3; // er12
  signed int v4; // er15
  hkaiVolumePathfindingUtil::FindPathOutput *v5; // rdi
  hkaiVolumePathfindingUtil::FindPathInput *v6; // rsi
  hkaiStreamingCollection *v7; // r13
  int v8; // ebx
  char v9; // al
  signed int v10; // er14
  signed int v11; // er14
  unsigned int v12; // eax
  _QWORD *v13; // r8
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  char *v16; // rdx
  char v17; // r14
  int v18; // ebx
  int v19; // er8
  hkaiStreamingCollection::InstanceInfo *v20; // rax
  hkVector4f v21; // xmm1
  unsigned int v22; // edx
  hkVector4f *v23; // rcx
  hkaiAstarEdgeFilter *v24; // rax
  const unsigned int *v25; // rax
  int v26; // er15
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  int v32; // ebx
  hkaiAstarOutputParameters::SearchStatus v33; // eax
  signed int v34; // ecx
  unsigned int v35; // er14
  BOOL v36; // ebx
  __int64 v37; // r8
  signed int v38; // edx
  __int64 v39; // rcx
  unsigned int *v40; // rax
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *v45; // r15
  __m128i *v46; // rcx
  __m128 *v47; // r8
  __m128i v48; // xmm5
  __m128 *v49; // rax
  __m128i v50; // xmm2
  __m128i v51; // xmm5
  __m128i v52; // xmm2
  __m128 v53; // xmm1
  int v54; // er9
  int v55; // eax
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut; // rdi
  int v57; // eax
  int v58; // er9
  int v59; // eax
  _QWORD *v60; // r8
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  signed __int64 v63; // rcx
  __m128 v64; // xmm1
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __int64 v68; // rcx
  signed __int64 v69; // rdx
  __int64 v70; // rcx
  signed __int64 v71; // rdx
  hkaiSearchMemoryInfo memInfo; // [rsp+40h] [rbp-98h]
  hkArray<char,hkContainerTempAllocator> array; // [rsp+58h] [rbp-80h]
  hkArray<char,hkContainerTempAllocator> v74; // [rsp+68h] [rbp-70h]
  hkVector4f *v75; // [rsp+78h] [rbp-60h]
  unsigned int v76; // [rsp+80h] [rbp-58h]
  const unsigned int *v77; // [rsp+88h] [rbp-50h]
  int v78; // [rsp+90h] [rbp-48h]
  hkaiNavVolumeGraph graph; // [rsp+98h] [rbp-40h]
  hkaiNavVolumeSearch v80; // [rsp+1D8h] [rbp+100h]
  int closestGoalIndex[2]; // [rsp+340h] [rbp+268h]

  v3 = input->m_goalPoints.m_size;
  v4 = 0;
  v5 = output;
  output->m_outputParameters.m_numIterations = 0;
  v6 = input;
  v7 = collection;
  if ( !input->m_goalCellKeys.m_size || input->m_startCellKey == -1 )
  {
    output->m_outputParameters.m_goalIndex = -1;
    output->m_outputParameters.m_status.m_storage = 5;
    return;
  }
  v8 = -1;
  v9 = input->m_searchParameters.m_lineOfSightFlags.m_storage;
  closestGoalIndex[0] = -1;
  if ( v9 & 4 || v9 & 1 && !input->m_searchParameters.m_costModifier )
  {
    v10 = 1;
    v12 = hkaiVolumePathfindingUtil::_checkInitialCell(collection, input, closestGoalIndex);
    v8 = closestGoalIndex[0];
    if ( v12 )
    {
      v4 = 1;
      goto LABEL_8;
    }
  }
  else
  {
    v10 = 0;
  }
  if ( !v10 )
  {
LABEL_12:
    v11 = 0;
    goto LABEL_13;
  }
LABEL_8:
  if ( !hkaiVolumePathfindingUtil::checkLineOfSight(v7, v6, v8, v5) )
    goto LABEL_12;
  v11 = 1;
LABEL_13:
  if ( v4 || v11 )
  {
    v5->m_outputParameters.m_status.m_storage = 1;
    v5->m_outputParameters.m_goalIndex = v8;
    v64 = _mm_sub_ps(v6->m_startPoint.m_quad, v6->m_goalPoints.m_data[v8].m_quad);
    v65 = _mm_mul_ps(v64, v64);
    v66 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
            _mm_shuffle_ps(v65, v65, 170));
    v67 = _mm_rsqrt_ps(v66);
    LODWORD(v5->m_outputParameters.m_pathLength) = (unsigned __int128)_mm_andnot_ps(
                                                                        _mm_cmpleps(v66, (__m128)0i64),
                                                                        _mm_mul_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_sub_ps(
                                                                              (__m128)_xmm,
                                                                              _mm_mul_ps(_mm_mul_ps(v66, v67), v67)),
                                                                            _mm_mul_ps(*(__m128 *)_xmm, v67)),
                                                                          v66));
    if ( v5->m_pathOut.m_size == (v5->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_pathOut, 48);
    v68 = v5->m_pathOut.m_size;
    v5->m_pathOut.m_size = v68 + 1;
    v69 = (signed __int64)&v5->m_pathOut.m_data[v68];
    *(_DWORD *)(v69 + 32) = 0;
    *(_OWORD *)(v69 + 16) = 0i64;
    *(_BYTE *)(v69 + 40) = 0;
    *(hkVector4f *)v69 = v6->m_startPoint;
    *(_DWORD *)(v69 + 36) = v6->m_startCellKey >> 22;
    if ( v5->m_pathOut.m_size == (v5->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_pathOut, 48);
    v70 = v5->m_pathOut.m_size;
    v5->m_pathOut.m_size = v70 + 1;
    v71 = (signed __int64)&v5->m_pathOut.m_data[v70];
    *(_OWORD *)(v71 + 16) = 0i64;
    *(_BYTE *)(v71 + 40) = 0;
    *(_DWORD *)(v71 + 32) = 0;
    *(hkVector4f *)v71 = v6->m_goalPoints.m_data[v8];
    *(_DWORD *)(v71 + 36) = v6->m_goalCellKeys.m_data[v8] >> 22;
    if ( v4 && !v11 )
    {
      if ( v5->m_visitedCells.m_size == (v5->m_visitedCells.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_visitedCells, 4);
      v5->m_visitedCells.m_data[v5->m_visitedCells.m_size++] = v6->m_startCellKey;
    }
  }
  else
  {
    v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = v13[1];
    if ( v14 < v13[3] )
    {
      *(_QWORD *)v14 = "LtFindPath";
      *(_QWORD *)(v14 + 16) = "Stinit";
      v15 = __rdtsc();
      *(_DWORD *)(v14 + 8) = v15;
      v13[1] = v14 + 24;
    }
    v16 = v6->m_searchBuffers.m_openSetBuffer;
    v17 = 0;
    *(hkaiSearchParameters::BufferSizes *)closestGoalIndex = v6->m_searchParameters.m_bufferSizes;
    v18 = closestGoalIndex[1];
    v19 = closestGoalIndex[0];
    if ( closestGoalIndex[0] <= 0 )
      v19 = 0x20000;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 2147483648;
    if ( closestGoalIndex[1] <= 0 )
      v18 = 590336;
    v74.m_data = 0i64;
    v74.m_size = 0;
    v74.m_capacityAndFlags = 2147483648;
    hkaiSearchMemoryStorage::_setupArray(&array, v16, v19);
    hkaiSearchMemoryStorage::_setupArray(&v74, v6->m_searchBuffers.m_searchStateBuffer, v18);
    memInfo.m_openSetBuffer = array.m_data;
    memInfo.m_openSetSize = array.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = v74.m_data;
    memInfo.m_searchStateSize = v74.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavVolumeSearch::hkaiNavVolumeSearch(&v80, &memInfo);
    v20 = v7->m_instances.m_data;
    v21.m_quad = (__m128)v6->m_startPoint;
    v80.m_state.m_heuristicWeight = v6->m_searchParameters.m_heuristicWeight;
    graph.m_startPoint = (hkVector4f)v21.m_quad;
    v74 = (hkArray<char,hkContainerTempAllocator>)v21.m_quad;
    v22 = v6->m_startCellKey;
    v23 = v6->m_goalPoints.m_data;
    graph.m_streamingInfo = v20;
    graph.m_costModifier = v6->m_searchParameters.m_costModifier;
    v24 = v6->m_searchParameters.m_edgeFilter;
    v80.m_graph.m_storage = &graph;
    graph.m_edgeFilter = v24;
    graph.m_info = v6->m_agentInfo;
    LODWORD(v24) = v6->m_goalPoints.m_size;
    *(_QWORD *)&graph.m_cachedCurrentSectionId = -1i64;
    graph.m_numGoals = (signed int)v24;
    v25 = v6->m_goalCellKeys.m_data;
    *(_QWORD *)&graph.m_cachedCurrentCell.m_min[1] = 0i64;
    graph.m_cachedCurrentCell.m_min[0] = 0;
    *(_DWORD *)&graph.m_cachedCurrentCell.m_max[1] = 0;
    *(_QWORD *)&graph.m_cachedCurrentCell.m_startEdgeIndex = 0i64;
    graph.m_endCellKeys = v25;
    v77 = v25;
    *(_QWORD *)&graph.m_cachedAdjacentCell.m_min[1] = 0i64;
    graph.m_cachedAdjacentCell.m_min[0] = 0;
    *(_DWORD *)&graph.m_cachedAdjacentCell.m_max[1] = 0;
    *(_QWORD *)&graph.m_cachedAdjacentCell.m_startEdgeIndex = 0i64;
    graph.m_cachedModifierInfo.m_currentCellInfo.m_cellKey = -1;
    graph.m_cachedModifierInfo.m_currentCellInfo.m_cell = 0i64;
    graph.m_cachedModifierInfo.m_adjacentCellInfo.m_cellKey = -1;
    graph.m_cachedModifierInfo.m_adjacentCellInfo.m_cell = 0i64;
    graph.m_cachedModifierInfo.m_edgeKey = -1;
    graph.m_cachedModifierInfo.m_edge = 0i64;
    graph.m_startCellKey = v22;
    graph.m_endPoints = v23;
    graph.m_searchState = &v80.m_state;
    v76 = v22;
    v75 = v23;
    v78 = v3;
    hkaiNavVolumeSearch::init(&v80, &graph, &v6->m_agentInfo, (hkaiNavVolumeSearch::StartGoalInfo *)&v74);
    v26 = v6->m_maxNumberOfIterations;
    v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v28 = (_QWORD *)v27[1];
    v29 = v27;
    if ( (unsigned __int64)v28 < v27[3] )
    {
      *v28 = "StAStar";
      v30 = __rdtsc();
      v31 = (signed __int64)(v28 + 2);
      *(_DWORD *)(v31 - 8) = v30;
      v29[1] = v31;
    }
    v32 = 0;
    while ( v32 < v26 )
    {
      ++v32;
      v33 = hkaiNavVolumeSearch::iteration(&v80);
      v34 = v33;
      if ( v33 == 3 )
      {
        v17 = (v80.m_openset.m_heapSize < v80.m_openset.m_maxSize) + 2;
        goto LABEL_30;
      }
      if ( v33 )
        goto LABEL_30;
    }
    v34 = 3;
    v17 = 1;
LABEL_30:
    v5->m_outputParameters.m_numIterations = v32;
    v5->m_outputParameters.m_status.m_storage = v34;
    v5->m_outputParameters.m_terminationCause.m_storage = v17;
    v5->m_outputParameters.m_goalIndex = -1;
    if ( !((v34 - 1) & 0xFFFFFFFD) )
    {
      v35 = v80.m_state.m_bestNode;
      v36 = v34 == 1;
      if ( v34 == 1 )
        v35 = v80.m_lastClosedCell;
      if ( v34 != 1 || (v37 = v6->m_goalCellKeys.m_size, v38 = 0, v39 = 0i64, v37 <= 0) )
      {
LABEL_38:
        v38 = -1;
      }
      else
      {
        v40 = v6->m_goalCellKeys.m_data;
        while ( *v40 != v80.m_lastClosedCell )
        {
          ++v39;
          ++v38;
          ++v40;
          if ( v39 >= v37 )
            goto LABEL_38;
        }
      }
      v5->m_outputParameters.m_goalIndex = v38;
      v80.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v80.m_state, v35);
      v80.m_state.m_parentNodeState = v80.m_state.m_currentNodeState;
      v80.m_state.m_parentIndex = (signed __int16)((_QWORD)((char *)v80.m_state.m_currentNodeState
                                                          - (char *)v80.m_state.m_nodes) >> 4);
      v5->m_outputParameters.m_pathLength = v80.m_state.m_currentNodeState->m_gCost;
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "Stoutput";
        v43 = __rdtsc();
        v44 = (signed __int64)(v42 + 2);
        *(_DWORD *)(v44 - 8) = v43;
        v41[1] = v44;
      }
      v45 = &v5->m_visitedCells;
      hkaiSearchStateUtils::getPath(&v80.m_state, v35, 0, &v5->m_visitedCells, 0x7FFFFFFF);
      v46 = (__m128i *)v6->m_goalPoints.m_data;
      _mm_store_si128((__m128i *)&array, *v46);
      if ( v36 )
      {
        array = (hkArray<char,hkContainerTempAllocator>)v46[v5->m_outputParameters.m_goalIndex];
      }
      else if ( v5->m_visitedCells.m_size )
      {
        v47 = (__m128 *)v7->m_instances.m_data[v5->m_visitedCells.m_data[v5->m_visitedCells.m_size - 1] >> 22].m_volumeInstancePtr;
        v48 = _mm_loadu_si128((const __m128i *)(v47[1].m128_u64[0]
                                              + 24i64
                                              * (v5->m_visitedCells.m_data[v5->m_visitedCells.m_size - 1] & 0x3FFFFF)));
        v49 = (__m128 *)v47[3].m128_u64[0];
        v50 = v48;
        v51 = _mm_unpackhi_epi16(v48, (__m128i)0i64);
        v52 = _mm_unpacklo_epi16(v50, (__m128i)0i64);
        v53 = _mm_add_ps(v49[7], v47[7]);
        array = (hkArray<char,hkContainerTempAllocator>)_mm_mul_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                v49[6],
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(
                                                                    _mm_cvtepi32_ps(_mm_srli_epi32(v51, 0x10u)),
                                                                    (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v51, 0x10u), 0x10u)))),
                                                              v53),
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                v49[6],
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(
                                                                    _mm_cvtepi32_ps(_mm_srli_epi32(v52, 0x10u)),
                                                                    (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v52, 0x10u), 0x10u)))),
                                                              v53)),
                                                          (__m128)xmmword_141A711B0);
      }
      v54 = v5->m_visitedCells.m_size;
      v55 = v5->m_pathOut.m_capacityAndFlags;
      pathArrayOut = &v5->m_pathOut;
      v57 = v55 & 0x3FFFFFFF;
      v58 = v54 + 1;
      if ( v57 < v58 )
      {
        v59 = 2 * v57;
        if ( v58 < v59 )
          v58 = v59;
        hkArrayUtil::_reserve(
          (hkResult *)closestGoalIndex,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          pathArrayOut,
          v58,
          48);
      }
      hkaiVolumePathSmoothingUtil::findSmoothedPath(
        v7->m_instances.m_data,
        v45,
        v6->m_startCellKey,
        &v6->m_startPoint,
        (hkVector4f *)&array,
        pathArrayOut,
        0i64,
        0);
    }
    v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v61 = (_QWORD *)v60[1];
    if ( (unsigned __int64)v61 < v60[3] )
    {
      *v61 = "lt";
      v62 = __rdtsc();
      v63 = (signed __int64)(v61 + 2);
      *(_DWORD *)(v63 - 8) = v62;
      v60[1] = v63;
    }
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage((hkaiSearchMemoryStorage *)&memInfo);
  }
}

// File Line: 290
// RVA: 0xBF90C0
bool __fastcall hkaiVolumePathfindingUtil::checkLineOfSight(hkaiStreamingCollection *collection, hkaiVolumePathfindingUtil::FindPathInput *input, int goalIndex, hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  hkaiStreamingCollection *v4; // rbp
  hkaiVolumePathfindingUtil::FindPathOutput *v5; // rsi
  __int64 v6; // rbx
  hkaiVolumePathfindingUtil::FindPathInput *v7; // rdi
  hkVector4f *v8; // rax
  hkVector4f v9; // xmm0
  hkArray<unsigned int,hkContainerHeapAllocator> *v10; // r8
  unsigned int *v11; // rax
  unsigned int v12; // ecx
  hkaiAgentTraversalInfo v13; // rax
  int *numIterationsOut; // rax
  bool result; // al
  hkaiVolumeLineOfSightUtil::LineOfSightInput inputa; // [rsp+30h] [rbp-48h]

  v4 = collection;
  v5 = output;
  v6 = goalIndex;
  v7 = input;
  hkaiVolumeLineOfSightUtil::LineOfSightInput::LineOfSightInput(&inputa);
  v8 = v7->m_goalPoints.m_data;
  inputa.m_startPoint = v7->m_startPoint;
  v9.m_quad = (__m128)v8[v6];
  v10 = 0i64;
  inputa.m_startCellKey = v7->m_startCellKey;
  v11 = v7->m_goalCellKeys.m_data;
  inputa.m_endPoint = (hkVector4f)v9.m_quad;
  v12 = v11[v6];
  inputa.m_maxNumberOfIterations = v7->m_maxNumberOfIterations;
  v13 = v7->m_agentInfo;
  inputa.m_endCellKey = v12;
  inputa.m_agentInfo = v13;
  inputa.m_edgeFilter = v7->m_searchParameters.m_edgeFilter;
  numIterationsOut = 0i64;
  if ( v5 )
  {
    v10 = &v5->m_visitedCells;
    numIterationsOut = &v5->m_outputParameters.m_numIterations;
  }
  result = hkaiVolumeLineOfSightUtil::checkLineOfSight(v4->m_instances.m_data, &inputa, v10, 0, numIterationsOut);
  if ( v5 )
    v5->m_outputParameters.m_status.m_storage = (result == 0) + 1;
  return result;
}

// File Line: 329
// RVA: 0xBF9190
signed __int64 __fastcall hkaiVolumePathfindingUtil::_checkInitialCell(hkaiStreamingCollection *collection, hkaiVolumePathfindingUtil::FindPathInput *input, int *closestGoalIndex)
{
  hkVector4f v3; // xmm0
  hkaiVolumePathfindingUtil::FindPathInput *v4; // rdi
  int v5; // edx
  hkaiStreamingCollection *v6; // rsi
  hkVector4f *v7; // rcx
  int *v8; // rbx
  int v9; // eax
  unsigned int v10; // er9
  __int64 v11; // r10
  __int128 v12; // xmm0
  unsigned __int64 v13; // r8
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  hkVector4f *v16; // rax
  __int64 v17; // rcx
  __int128 v18; // xmm0
  hkaiAstarEdgeFilter *v19; // rcx
  signed __int64 result; // rax
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+20h] [rbp-78h]
  int *v22; // [rsp+30h] [rbp-68h]
  char v23; // [rsp+38h] [rbp-60h]
  unsigned int v24; // [rsp+40h] [rbp-58h]
  __int64 v25; // [rsp+48h] [rbp-50h]
  __int128 v26; // [rsp+50h] [rbp-48h]
  unsigned int v27; // [rsp+60h] [rbp-38h]
  __int64 v28; // [rsp+68h] [rbp-30h]
  __int128 v29; // [rsp+70h] [rbp-28h]
  int v30; // [rsp+80h] [rbp-18h]
  __int64 v31; // [rsp+88h] [rbp-10h]

  v3.m_quad = (__m128)input->m_startPoint;
  v4 = input;
  v5 = input->m_goalPoints.m_size;
  v6 = collection;
  v7 = v4->m_goalPoints.m_data;
  v8 = closestGoalIndex;
  _mm_store_si128((__m128i *)&evalFunc, (__m128i)v3.m_quad);
  v9 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(v7, v5, &evalFunc);
  *v8 = v9;
  v10 = v4->m_startCellKey;
  v11 = v9;
  if ( v10 != v4->m_goalCellKeys.m_data[v9] )
    goto LABEL_8;
  v12 = (__int128)v4->m_startPoint;
  v13 = (unsigned __int64)v6->m_instances.m_data[v10 >> 22].m_volumeInstancePtr;
  v24 = -1;
  v25 = 0i64;
  v27 = -1;
  v28 = 0i64;
  v30 = -1;
  v31 = 0i64;
  v14 = *(_QWORD *)(v13 + 16);
  v26 = v12;
  v24 = v10;
  v15 = 24i64 * (v10 & 0x3FFFFF);
  v16 = v4->m_goalPoints.m_data;
  v25 = v15 + v14;
  v17 = *(_QWORD *)(v13 + 16);
  v27 = v10;
  v28 = v15 + v17;
  v18 = (__int128)v16[v11];
  v22 = (int *)&v24;
  v19 = v4->m_searchParameters.m_edgeFilter;
  v29 = v18;
  v31 = 0i64;
  v30 = -1;
  evalFunc.m_p.m_quad.m128_u64[0] = v13;
  v23 = 82;
  evalFunc.m_p.m_quad.m128_u64[1] = (unsigned __int64)&v4->m_agentInfo;
  if ( !v19 )
    goto LABEL_9;
  if ( !(unsigned __int8)v19->vfptr[2].__vecDelDtor((hkBaseObject *)&v19->vfptr, (unsigned int)&evalFunc) )
LABEL_8:
    result = 0i64;
  else
LABEL_9:
    result = 1i64;
  return result;
}

// File Line: 370
// RVA: 0xBF87C0
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::checkDeterminism(hkaiVolumePathfindingUtil::FindPathInput *this)
{
  ;
}

// File Line: 393
// RVA: 0xBF87F0
void __fastcall hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(hkaiVolumePathfindingUtil::FindPathOutput *this)
{
  ;
}

