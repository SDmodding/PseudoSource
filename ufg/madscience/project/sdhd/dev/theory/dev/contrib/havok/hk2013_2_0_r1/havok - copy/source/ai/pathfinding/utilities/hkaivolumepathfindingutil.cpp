// File Line: 42
// RVA: 0xBF8660
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(
        hkaiVolumePathfindingUtil::FindPathInput *this,
        int numGoals)
{
  int v4; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
  *(_QWORD *)&this->m_goalPoints.m_capacityAndFlags = 0xFFFFFFFF80000000ui64;
  this->m_goalPoints.m_data = 0i64;
  this->m_goalPoints.m_size = 0;
  this->m_goalCellKeys.m_data = 0i64;
  this->m_goalCellKeys.m_size = 0;
  this->m_goalCellKeys.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_searchParameters.m_costModifier = 0i64;
  this->m_searchParameters.m_edgeFilter = 0i64;
  this->m_searchParameters.m_lineOfSightFlags.m_storage = 1;
  *(_QWORD *)&this->m_searchParameters.m_heuristicWeight = 1065353216i64;
  this->m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = 0;
  *(_DWORD *)this->m_searchParameters.m_up.m_vec = -2147450880;
  this->m_searchParameters.m_up.m_vec[2] = 0x8000;
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
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalCellKeys, v6, 4);
    }
    this->m_goalCellKeys.m_size = numGoals;
    v7 = this->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < numGoals )
    {
      v8 = 2 * v7;
      v9 = numGoals;
      if ( numGoals < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalPoints, v9, 16);
    }
    this->m_goalPoints.m_size = numGoals;
  }
}

// File Line: 58
// RVA: 0xBF8790
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(
        hkaiVolumePathfindingUtil::FindPathInput *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 66
// RVA: 0xBF87D0
void __fastcall hkaiVolumePathfindingUtil::FindPathOutput::FindPathOutput(
        hkaiVolumePathfindingUtil::FindPathOutput *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
}

// File Line: 70
// RVA: 0xBF8F80
void __fastcall hkaiVolumePathfindingUtil::findPath(
        hkaiNavVolume *navVolume,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v7; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-B8h] BYREF
  hkaiNavVolumeInstance v10; // [rsp+60h] [rbp-88h] BYREF
  hkResult result; // [rsp+108h] [rbp+20h] BYREF

  hkaiNavVolumeInstance::hkaiNavVolumeInstance(&v10);
  hkaiNavVolumeInstance::tempInit(&v10, navVolume);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v7 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v7;
    }
    while ( v7 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_volumeInstancePtr = &v10;
  array.m_instances.m_data->m_volumeMediator = 0i64;
  hkaiVolumePathfindingUtil::findPath(&array, input, output);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavVolumeInstance::~hkaiNavVolumeInstance(&v10);
}

// File Line: 82
// RVA: 0xBF8800
void __fastcall hkaiVolumePathfindingUtil::findPath(
        hkaiStreamingCollection *collection,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  int m_size; // r12d
  int v4; // r15d
  int v8; // ebx
  char m_storage; // al
  int v10; // r14d
  int v11; // r14d
  unsigned int v12; // eax
  _QWORD *Value; // r8
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rax
  char *m_openSetBuffer; // rdx
  char v17; // r14
  int v18; // r8d
  int v19; // ebx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkVector4f v21; // xmm1
  int m_startCellKey; // edx
  hkVector4f *v23; // rcx
  hkaiAstarEdgeFilter *m_edgeFilter; // rax
  unsigned int *v25; // rax
  int m_maxNumberOfIterations; // r15d
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  int v32; // ebx
  hkaiAstarOutputParameters::SearchStatus v33; // eax
  int v34; // ecx
  unsigned int m_bestNode; // r14d
  BOOL v36; // ebx
  __int64 v37; // r8
  int v38; // edx
  __int64 v39; // rcx
  unsigned int *v40; // rax
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_visitedCells; // r15
  hkVector4f *v46; // rcx
  hkaiNavVolumeInstance *m_volumeInstancePtr; // r8
  __m128 *m_pntr; // rax
  __m128i v49; // xmm2
  __m128i v50; // xmm0
  __m128 v51; // xmm1
  __m128 v52; // xmm4
  __m128i v53; // xmm0
  int v54; // r9d
  int m_capacityAndFlags; // eax
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut; // rdi
  int v57; // eax
  int v58; // r9d
  int v59; // eax
  _QWORD *v60; // r8
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  _QWORD *v63; // rcx
  __m128 v64; // xmm1
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __int64 v68; // rcx
  hkaiPath::PathPoint *v69; // rdx
  __int64 v70; // rcx
  hkaiPath::PathPoint *v71; // rdx
  hkaiSearchMemoryStorage memInfo; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f *v73; // [rsp+78h] [rbp-60h]
  int v74; // [rsp+80h] [rbp-58h]
  unsigned int *v75; // [rsp+88h] [rbp-50h]
  int v76; // [rsp+90h] [rbp-48h]
  hkaiNavVolumeGraph graph; // [rsp+98h] [rbp-40h] BYREF
  hkaiNavVolumeSearch v78; // [rsp+1D8h] [rbp+100h] BYREF
  int closestGoalIndex[2]; // [rsp+340h] [rbp+268h] BYREF

  m_size = input->m_goalPoints.m_size;
  v4 = 0;
  output->m_outputParameters.m_numIterations = 0;
  if ( !input->m_goalCellKeys.m_size || input->m_startCellKey == -1 )
  {
    output->m_outputParameters.m_goalIndex = -1;
    output->m_outputParameters.m_status.m_storage = 5;
    return;
  }
  v8 = -1;
  m_storage = input->m_searchParameters.m_lineOfSightFlags.m_storage;
  closestGoalIndex[0] = -1;
  if ( (m_storage & 4) != 0 || (m_storage & 1) != 0 && !input->m_searchParameters.m_costModifier )
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
  if ( !hkaiVolumePathfindingUtil::checkLineOfSight(collection, input, v8, output) )
    goto LABEL_12;
  v11 = 1;
LABEL_13:
  if ( v4 || v11 )
  {
    output->m_outputParameters.m_status.m_storage = 1;
    output->m_outputParameters.m_goalIndex = v8;
    v64 = _mm_sub_ps(input->m_startPoint.m_quad, input->m_goalPoints.m_data[v8].m_quad);
    v65 = _mm_mul_ps(v64, v64);
    v66 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
            _mm_shuffle_ps(v65, v65, 170));
    v67 = _mm_rsqrt_ps(v66);
    LODWORD(output->m_outputParameters.m_pathLength) = _mm_andnot_ps(
                                                         _mm_cmple_ps(v66, (__m128)0i64),
                                                         _mm_mul_ps(
                                                           _mm_mul_ps(
                                                             _mm_sub_ps(
                                                               (__m128)_xmm,
                                                               _mm_mul_ps(_mm_mul_ps(v66, v67), v67)),
                                                             _mm_mul_ps(*(__m128 *)_xmm, v67)),
                                                           v66)).m128_u32[0];
    if ( output->m_pathOut.m_size == (output->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &output->m_pathOut, 48);
    v68 = output->m_pathOut.m_size;
    output->m_pathOut.m_size = v68 + 1;
    v69 = &output->m_pathOut.m_data[v68];
    v69->m_userEdgeData = 0;
    v69->m_normal = 0i64;
    v69->m_flags.m_storage = 0;
    v69->m_position = input->m_startPoint;
    v69->m_sectionId = input->m_startCellKey >> 22;
    if ( output->m_pathOut.m_size == (output->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &output->m_pathOut, 48);
    v70 = output->m_pathOut.m_size;
    output->m_pathOut.m_size = v70 + 1;
    v71 = &output->m_pathOut.m_data[v70];
    v71->m_normal = 0i64;
    v71->m_flags.m_storage = 0;
    v71->m_userEdgeData = 0;
    v71->m_position = input->m_goalPoints.m_data[v8];
    v71->m_sectionId = input->m_goalCellKeys.m_data[v8] >> 22;
    if ( v4 && !v11 )
    {
      if ( output->m_visitedCells.m_size == (output->m_visitedCells.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &output->m_visitedCells, 4);
      output->m_visitedCells.m_data[output->m_visitedCells.m_size++] = input->m_startCellKey;
    }
  }
  else
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v14 = Value[1];
    if ( v14 < Value[3] )
    {
      *(_QWORD *)v14 = "LtFindPath";
      *(_QWORD *)(v14 + 16) = "Stinit";
      v15 = __rdtsc();
      *(_DWORD *)(v14 + 8) = v15;
      Value[1] = v14 + 24;
    }
    m_openSetBuffer = input->m_searchBuffers.m_openSetBuffer;
    v17 = 0;
    *(hkaiSearchParameters::BufferSizes *)closestGoalIndex = input->m_searchParameters.m_bufferSizes;
    v18 = closestGoalIndex[0];
    v19 = closestGoalIndex[1];
    if ( closestGoalIndex[0] <= 0 )
      v18 = 0x20000;
    memInfo.m_openSetStorage.m_data = 0i64;
    memInfo.m_openSetStorage.m_size = 0;
    memInfo.m_openSetStorage.m_capacityAndFlags = 0x80000000;
    if ( closestGoalIndex[1] <= 0 )
      v19 = 590336;
    memInfo.m_searchStateStorage.m_data = 0i64;
    memInfo.m_searchStateStorage.m_size = 0;
    memInfo.m_searchStateStorage.m_capacityAndFlags = 0x80000000;
    hkaiSearchMemoryStorage::_setupArray(&memInfo.m_openSetStorage, m_openSetBuffer, v18);
    hkaiSearchMemoryStorage::_setupArray(&memInfo.m_searchStateStorage, input->m_searchBuffers.m_searchStateBuffer, v19);
    memInfo.m_openSetBuffer = memInfo.m_openSetStorage.m_data;
    memInfo.m_openSetSize = memInfo.m_openSetStorage.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = memInfo.m_searchStateStorage.m_data;
    memInfo.m_searchStateSize = memInfo.m_searchStateStorage.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavVolumeSearch::hkaiNavVolumeSearch(&v78, &memInfo);
    m_data = collection->m_instances.m_data;
    v21.m_quad = (__m128)input->m_startPoint;
    v78.m_state.m_heuristicWeight = input->m_searchParameters.m_heuristicWeight;
    graph.m_startPoint = (hkVector4f)v21.m_quad;
    memInfo.m_searchStateStorage = (hkArray<char,hkContainerTempAllocator>)v21.m_quad;
    m_startCellKey = input->m_startCellKey;
    v23 = input->m_goalPoints.m_data;
    graph.m_streamingInfo = m_data;
    graph.m_costModifier = input->m_searchParameters.m_costModifier;
    m_edgeFilter = input->m_searchParameters.m_edgeFilter;
    v78.m_graph.m_storage = &graph;
    graph.m_edgeFilter = m_edgeFilter;
    graph.m_info = input->m_agentInfo;
    LODWORD(m_edgeFilter) = input->m_goalPoints.m_size;
    *(_QWORD *)&graph.m_cachedCurrentSectionId = -1i64;
    graph.m_numGoals = (int)m_edgeFilter;
    v25 = input->m_goalCellKeys.m_data;
    *(_QWORD *)&graph.m_cachedCurrentCell.m_min[1] = 0i64;
    graph.m_cachedCurrentCell.m_min[0] = 0;
    *(_DWORD *)&graph.m_cachedCurrentCell.m_max[1] = 0;
    *(_QWORD *)&graph.m_cachedCurrentCell.m_startEdgeIndex = 0i64;
    graph.m_endCellKeys = v25;
    v75 = v25;
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
    graph.m_startCellKey = m_startCellKey;
    graph.m_endPoints = v23;
    graph.m_searchState = &v78.m_state;
    v74 = m_startCellKey;
    v73 = v23;
    v76 = m_size;
    hkaiNavVolumeSearch::init(
      &v78,
      &graph,
      &input->m_agentInfo,
      (hkaiNavVolumeSearch::StartGoalInfo *)&memInfo.m_searchStateStorage);
    m_maxNumberOfIterations = input->m_maxNumberOfIterations;
    v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v28 = (_QWORD *)v27[1];
    v29 = v27;
    if ( (unsigned __int64)v28 < v27[3] )
    {
      *v28 = "StAStar";
      v30 = __rdtsc();
      v31 = v28 + 2;
      *((_DWORD *)v31 - 2) = v30;
      v29[1] = v31;
    }
    v32 = 0;
    while ( v32 < m_maxNumberOfIterations )
    {
      ++v32;
      v33 = hkaiNavVolumeSearch::iteration(&v78);
      v34 = v33;
      if ( v33 == SEARCH_TERMINATED )
      {
        v17 = (v78.m_openset.m_heapSize < v78.m_openset.m_maxSize) + 2;
        goto LABEL_30;
      }
      if ( v33 )
        goto LABEL_30;
    }
    v34 = 3;
    v17 = 1;
LABEL_30:
    output->m_outputParameters.m_numIterations = v32;
    output->m_outputParameters.m_status.m_storage = v34;
    output->m_outputParameters.m_terminationCause.m_storage = v17;
    output->m_outputParameters.m_goalIndex = -1;
    if ( ((v34 - 1) & 0xFFFFFFFD) == 0 )
    {
      m_bestNode = v78.m_state.m_bestNode;
      v36 = v34 == 1;
      if ( v34 == 1 )
        m_bestNode = v78.m_lastClosedCell;
      if ( v34 == 1 && (v37 = input->m_goalCellKeys.m_size, v38 = 0, v39 = 0i64, v37 > 0) )
      {
        v40 = input->m_goalCellKeys.m_data;
        while ( *v40 != v78.m_lastClosedCell )
        {
          ++v39;
          ++v38;
          ++v40;
          if ( v39 >= v37 )
            goto LABEL_38;
        }
      }
      else
      {
LABEL_38:
        v38 = -1;
      }
      output->m_outputParameters.m_goalIndex = v38;
      v78.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v78.m_state, m_bestNode);
      v78.m_state.m_parentNodeState = v78.m_state.m_currentNodeState;
      v78.m_state.m_parentIndex = (__int16)(v78.m_state.m_currentNodeState - v78.m_state.m_nodes);
      output->m_outputParameters.m_pathLength = v78.m_state.m_currentNodeState->m_gCost;
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "Stoutput";
        v43 = __rdtsc();
        v44 = v42 + 2;
        *((_DWORD *)v44 - 2) = v43;
        v41[1] = v44;
      }
      p_m_visitedCells = &output->m_visitedCells;
      hkaiSearchStateUtils::getPath(
        &v78.m_state,
        m_bestNode,
        GET_PATH_PRESERVE_ALL,
        &output->m_visitedCells,
        0x7FFFFFFF);
      v46 = input->m_goalPoints.m_data;
      memInfo.m_openSetStorage = (hkArray<char,hkContainerTempAllocator>)v46->m_quad;
      if ( v36 )
      {
        memInfo.m_openSetStorage = (hkArray<char,hkContainerTempAllocator>)v46[output->m_outputParameters.m_goalIndex];
      }
      else if ( output->m_visitedCells.m_size )
      {
        m_volumeInstancePtr = collection->m_instances.m_data[output->m_visitedCells.m_data[output->m_visitedCells.m_size
                                                                                         - 1] >> 22].m_volumeInstancePtr;
        m_pntr = (__m128 *)m_volumeInstancePtr->m_originalVolume.m_pntr;
        v49 = _mm_loadu_si128((const __m128i *)&m_volumeInstancePtr->m_originalCells[output->m_visitedCells.m_data[output->m_visitedCells.m_size - 1] & 0x3FFFFF]);
        v50 = _mm_unpacklo_epi16(v49, (__m128i)0i64);
        v51 = _mm_add_ps(m_pntr[7], m_volumeInstancePtr->m_translation.m_quad);
        v52 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v50, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v50, 0x10u), 0x10u)));
        v53 = _mm_unpackhi_epi16(v49, (__m128i)0i64);
        memInfo.m_openSetStorage = (hkArray<char,hkContainerTempAllocator>)_mm_mul_ps(
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   m_pntr[6],
                                                                                   _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_cvtepi32_ps(_mm_srli_epi32(v53, 0x10u)),
                                                                                       (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                                                                     _mm_cvtepi32_ps(
                                                                                       _mm_srli_epi32(
                                                                                         _mm_slli_epi32(v53, 0x10u),
                                                                                         0x10u)))),
                                                                                 v51),
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(m_pntr[6], v52),
                                                                                 v51)),
                                                                             (__m128)xmmword_141A711B0);
      }
      v54 = output->m_visitedCells.m_size;
      m_capacityAndFlags = output->m_pathOut.m_capacityAndFlags;
      pathArrayOut = &output->m_pathOut;
      v57 = m_capacityAndFlags & 0x3FFFFFFF;
      v58 = v54 + 1;
      if ( v57 < v58 )
      {
        v59 = 2 * v57;
        if ( v58 < v59 )
          v58 = v59;
        hkArrayUtil::_reserve((hkResult *)closestGoalIndex, &hkContainerHeapAllocator::s_alloc, pathArrayOut, v58, 48);
      }
      hkaiVolumePathSmoothingUtil::findSmoothedPath(
        collection->m_instances.m_data,
        p_m_visitedCells,
        input->m_startCellKey,
        &input->m_startPoint,
        (hkVector4f *)&memInfo.m_openSetStorage,
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
      v63 = v61 + 2;
      *((_DWORD *)v63 - 2) = v62;
      v60[1] = v63;
    }
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(&memInfo);
  }
} hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(&memInfo);
  }
}

// File Line: 290
// RVA: 0xBF90C0
bool __fastcall hkaiVolumePathfindingUtil::checkLineOfSight(
        hkaiStreamingCollection *collection,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        int goalIndex,
        hkaiVolumePathfindingUtil::FindPathOutput *output)
{
  __int64 v6; // rbx
  hkVector4f *m_data; // rax
  hkVector4f v9; // xmm0
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_visitedCells; // r8
  unsigned int *v11; // rax
  unsigned int v12; // ecx
  hkaiAgentTraversalInfo m_agentInfo; // rax
  hkaiAstarOutputParameters *numIterationsOut; // rax
  bool result; // al
  hkaiVolumeLineOfSightUtil::LineOfSightInput inputa; // [rsp+30h] [rbp-48h] BYREF

  v6 = goalIndex;
  hkaiVolumeLineOfSightUtil::LineOfSightInput::LineOfSightInput(&inputa);
  m_data = input->m_goalPoints.m_data;
  inputa.m_startPoint = input->m_startPoint;
  v9.m_quad = (__m128)m_data[v6];
  p_m_visitedCells = 0i64;
  inputa.m_startCellKey = input->m_startCellKey;
  v11 = input->m_goalCellKeys.m_data;
  inputa.m_endPoint = (hkVector4f)v9.m_quad;
  v12 = v11[v6];
  inputa.m_maxNumberOfIterations = input->m_maxNumberOfIterations;
  m_agentInfo = input->m_agentInfo;
  inputa.m_endCellKey = v12;
  inputa.m_agentInfo = m_agentInfo;
  inputa.m_edgeFilter = input->m_searchParameters.m_edgeFilter;
  numIterationsOut = 0i64;
  if ( output )
  {
    p_m_visitedCells = &output->m_visitedCells;
    numIterationsOut = &output->m_outputParameters;
  }
  result = hkaiVolumeLineOfSightUtil::checkLineOfSight(
             collection->m_instances.m_data,
             &inputa,
             p_m_visitedCells,
             0,
             &numIterationsOut->m_numIterations);
  if ( output )
    output->m_outputParameters.m_status.m_storage = !result + 1;
  return result;
}

// File Line: 329
// RVA: 0xBF9190
_BOOL8 __fastcall hkaiVolumePathfindingUtil::_checkInitialCell(
        hkaiStreamingCollection *collection,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        int *closestGoalIndex)
{
  __m128 m_quad; // xmm0
  int m_size; // edx
  hkVector4f *m_data; // rcx
  int v9; // eax
  unsigned int m_startCellKey; // r9d
  __int64 v11; // r10
  hkVector4f v12; // xmm0
  hkaiNavVolumeInstance *m_volumeInstancePtr; // r8
  hkaiNavVolume::Cell *m_originalCells; // rcx
  __int64 v15; // rdx
  hkVector4f *v16; // rax
  hkaiNavVolume::Cell *v17; // rcx
  __int128 v18; // xmm0
  hkaiAstarEdgeFilter *m_edgeFilter; // rcx
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+20h] [rbp-78h] BYREF
  int *v22; // [rsp+30h] [rbp-68h]
  char v23; // [rsp+38h] [rbp-60h]
  unsigned int v24; // [rsp+40h] [rbp-58h] BYREF
  hkaiNavVolume::Cell *v25; // [rsp+48h] [rbp-50h]
  __m128 v26; // [rsp+50h] [rbp-48h]
  unsigned int v27; // [rsp+60h] [rbp-38h]
  hkaiNavVolume::Cell *v28; // [rsp+68h] [rbp-30h]
  __int128 v29; // [rsp+70h] [rbp-28h]
  int v30; // [rsp+80h] [rbp-18h]
  __int64 v31; // [rsp+88h] [rbp-10h]

  m_quad = input->m_startPoint.m_quad;
  m_size = input->m_goalPoints.m_size;
  m_data = input->m_goalPoints.m_data;
  evalFunc.m_p.m_quad = m_quad;
  v9 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(m_data, m_size, &evalFunc);
  *closestGoalIndex = v9;
  m_startCellKey = input->m_startCellKey;
  v11 = v9;
  if ( m_startCellKey != input->m_goalCellKeys.m_data[v9] )
    return 0i64;
  v12.m_quad = (__m128)input->m_startPoint;
  m_volumeInstancePtr = collection->m_instances.m_data[m_startCellKey >> 22].m_volumeInstancePtr;
  v24 = -1;
  v25 = 0i64;
  v27 = -1;
  v28 = 0i64;
  v30 = -1;
  v31 = 0i64;
  m_originalCells = m_volumeInstancePtr->m_originalCells;
  v26 = v12.m_quad;
  v24 = m_startCellKey;
  v15 = m_startCellKey & 0x3FFFFF;
  v16 = input->m_goalPoints.m_data;
  v25 = &m_originalCells[v15];
  v17 = m_volumeInstancePtr->m_originalCells;
  v27 = m_startCellKey;
  v28 = &v17[v15];
  v18 = (__int128)v16[v11];
  v22 = (int *)&v24;
  m_edgeFilter = input->m_searchParameters.m_edgeFilter;
  v29 = v18;
  v31 = 0i64;
  v30 = -1;
  evalFunc.m_p.m_quad.m128_u64[0] = (unsigned __int64)m_volumeInstancePtr;
  v23 = 82;
  evalFunc.m_p.m_quad.m128_u64[1] = (unsigned __int64)&input->m_agentInfo;
  return !m_edgeFilter || m_edgeFilter->vfptr[2].__vecDelDtor(m_edgeFilter, (unsigned int)&evalFunc);
}

// File Line: 370
// RVA: 0xBF87C0
void __fastcall hkaiVolumePathfindingUtil::FindPathInput::checkDeterminism(
        hkaiVolumePathfindingUtil::FindPathInput *this)
{
  ;
}

// File Line: 393
// RVA: 0xBF87F0
void __fastcall hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(
        hkaiVolumePathfindingUtil::FindPathOutput *this)
{
  ;
}

