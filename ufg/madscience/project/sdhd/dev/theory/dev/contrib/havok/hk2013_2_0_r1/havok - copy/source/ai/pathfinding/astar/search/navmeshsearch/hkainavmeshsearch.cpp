// File Line: 33
// RVA: 0xBFED30
void __fastcall hkaiNavMeshSearch::hkaiNavMeshSearch(hkaiNavMeshSearch *this, hkaiSearchMemoryInfo *memInfo, hkaiSearchMemoryInfo *hierarchyMemInfo)
{
  hkaiNavMeshSearch *v3; // rsi
  hkaiSearchMemoryInfo *v4; // rdi
  unsigned __int64 v5; // rcx

  this->m_state.m_heuristicWeight = 1.0;
  this->m_state.m_bestNode = -1;
  this->m_state.m_bestNodeCost = 3.40282e38;
  this->m_state.m_maxPathCost = 3.40282e38;
  v3 = this;
  this->m_state.m_nodes = 0i64;
  this->m_state.m_hashNext = 0i64;
  this->m_state.m_hashFirst = 0i64;
  *(_QWORD *)&this->m_state.m_nodeCapacity = 0i64;
  this->m_state.m_dummyNode.m_gCost = 3.40282e38;
  this->m_state.m_dummyNode.m_hCost = 3.40282e38;
  this->m_state.m_dummyNode.m_index = -1;
  this->m_state.m_dummyNode.m_flags.m_storage = 0;
  v4 = memInfo;
  this->m_state.m_dummyNode.m_parentIndex = -1;
  v5 = memInfo->m_openSetSize;
  v3->m_openset.m_heap = (hkaiHeapOpenSet::IndexCostPair *)memInfo->m_openSetBuffer;
  v3->m_openset.m_heapSize = 0;
  v3->m_openset.m_maxSize = v5 >> 3;
  hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(&v3->m_heuristic.m_coarseSearch, hierarchyMemInfo);
  v3->m_heuristic.m_accessor.m_currentSection = -1;
  v3->m_heuristic.m_accessor.m_sectionInfo = 0i64;
  v3->m_heuristic.m_accessor.m_accessor = 0i64;
  v3->m_spuClusterGraph.m_agentInfo = 0i64;
  v3->m_spuClusterGraph.m_cachedNode.m_startEdgeIndex = -1;
  v3->m_spuClusterGraph.m_cachedNode.m_numEdges = -1;
  v3->m_spuClusterGraph.m_cachedInstanceNode.m_startEdgeIndex = -1;
  v3->m_spuClusterGraph.m_cachedInstanceNode.m_numEdges = -1;
  v3->m_spuClusterGraph.m_streamingInfo = 0i64;
  v3->m_spuClusterGraph.m_cachedIncomingSectionId = -1;
  v3->m_spuClusterGraph.m_cachedOutgoingSectionId = -1;
  v3->m_spuClusterGraph.m_cachedGeneralSectionId = -1;
  v3->m_spuClusterGraph.m_edgeFilter = 0i64;
  v3->m_spuClusterGraph.m_costModifier = 0i64;
  v3->m_spuClusterGraph.m_numGoals = 0;
  v3->m_spuClusterGraph.m_goalNodes = 0i64;
  v3->m_spuClusterGraph.m_finalCosts = 0i64;
  hkaiHashSearchState::setStorage(&v3->m_state, v4->m_searchStateBuffer, v4->m_searchStateSize);
}

// File Line: 39
// RVA: 0xBFEE70
void __fastcall hkaiNavMeshSearch::init(hkaiNavMeshSearch *this, hkaiNavMeshSectionGraph *graph, hkaiAgentTraversalInfo *agentInfo, hkaiNavMeshSearch::StartGoalInfo *goalInfo, bool isHierarchical)
{
  float v5; // eax
  hkaiNavMeshSearch *v6; // rdi
  hkaiDirectedGraphVisitor *v7; // r8
  hkVector4f *goalPositions; // rax
  __int64 numGoals; // r15
  const unsigned int *originalGoalFaceKeys; // r14
  unsigned int v11; // ebp
  hkaiNavMeshSectionGraph *v12; // rsi
  signed int v13; // edx
  hkaiNavMeshInstance *v14; // rcx
  hkaiNavMeshInstance *v15; // rcx
  hkaiNavMesh::Face *v16; // rax
  int *v17; // r8
  int *v18; // rax
  hkaiHashSearchState *v19; // rbp
  hkaiSearchStateNode *v20; // rax
  int v21; // edi
  __int64 v22; // rbx
  hkaiSearchStateNode *v23; // rax
  hkVector4f startPosition; // [rsp+60h] [rbp-38h]
  int *dataPtrOut; // [rsp+A0h] [rbp+8h]

  v5 = agentInfo->m_diameter;
  v6 = this;
  *(_QWORD *)&this->m_lastClosedNode = -1i64;
  this->m_graph.m_storage = graph;
  this->m_diameter = v5;
  if ( isHierarchical )
  {
    v7 = &this->m_spuClusterGraph;
    this->m_spuClusterGraph.m_streamingInfo = graph->m_streamingInfo;
  }
  else
  {
    v7 = 0i64;
  }
  goalPositions = goalInfo->m_goalPoints;
  numGoals = goalInfo->m_numGoals;
  originalGoalFaceKeys = goalInfo->m_goalFaceKeys;
  _mm_store_si128((__m128i *)&startPosition, (__m128i)goalInfo->m_startPoint.m_quad);
  v11 = goalInfo->m_startFaceKey;
  hkaiHierarchicalNavMeshHeuristic::init(
    &this->m_heuristic,
    graph,
    v7,
    goalInfo->m_startFaceKey,
    &startPosition,
    originalGoalFaceKeys,
    goalPositions,
    numGoals);
  v12 = v6->m_graph.m_storage;
  v13 = v11 >> 22;
  if ( v11 >> 22 == 1021 )
    v13 = v12->m_endFaceKeys[v11 & 0x3FFFFF] >> 22;
  if ( v12->m_cachedOutgoingSectionId != v13 )
  {
    v14 = v12->m_streamingInfo[v13].m_instancePtr;
    v12->m_cachedOutgoingSectionId = v13;
    v12->m_cachedOutgoingNavMesh = v14;
  }
  v15 = v12->m_cachedOutgoingNavMesh;
  v16 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int__1(
          v15->m_originalFaces,
          v15->m_numOriginalFaces,
          &v15->m_instancedFaces,
          &v15->m_ownedFaces,
          v15->m_originalFaceData,
          &v15->m_instancedFaceData,
          &v15->m_ownedFaceData,
          &v15->m_faceMap,
          v11 & 0x3FFFFF,
          v15->m_faceDataStriding,
          (const int **)&dataPtrOut);
  v12->m_cachedFaceKey = v11;
  v17 = &v12->m_cachedFace.m_startEdgeIndex;
  *v17 = v16->m_startEdgeIndex;
  v17[1] = v16->m_startUserEdgeIndex;
  v17[2] = *(_DWORD *)&v16->m_numEdges;
  v17[3] = *(_DWORD *)&v16->m_clusterIndex;
  v18 = dataPtrOut;
  v12->m_cachedEdgePairInfo.m_faceKey = v11;
  v12->m_cachedEdgePairInfo.m_face = &v12->m_cachedFace;
  v19 = &v6->m_state;
  v12->m_cachedEdgePairInfo.m_faceData = v18;
  if ( hkaiHashSearchState::setStartNode<hkaiHierarchicalNavMeshHeuristic>(
         &v6->m_state,
         &v6->m_heuristic,
         0xFF800000,
         0.0) )
  {
    v20 = hkaiHashSearchState::getNodeStateRO(&v6->m_state, 0xFF800000);
    hkaiHeapOpenSet::insertSearchIndex(
      &v6->m_openset,
      -8388608,
      (float)(v6->m_state.m_heuristicWeight * v20->m_hCost) + v20->m_gCost);
  }
  v21 = 0;
  v22 = 0i64;
  if ( (signed int)numGoals > 0 )
  {
    do
    {
      if ( originalGoalFaceKeys[v22] != -1 )
      {
        v23 = hkaiHashSearchState::getNodeState(v19, v21 | 0xFF400000);
        v23->m_hCost = 0.0;
        v23->m_flags.m_storage |= 8u;
      }
      ++v22;
      ++v21;
    }
    while ( v22 < numGoals );
  }
}

// File Line: 132
// RVA: 0xBFF0A0
signed __int64 __fastcall hkaiNavMeshSearch::iteration(hkaiNavMeshSearch *this)
{
  hkaiNavMeshSearch *v1; // rbx
  signed __int64 result; // rax
  unsigned int v3; // edi

  v1 = this;
  if ( !this->m_openset.m_heapSize )
    return 2i64;
  v3 = hkaiAstarSearchIteration_hkaiNavMeshSectionGraph_hkaiNavMeshSectionGraph_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiHierarchicalNavMeshHeuristic_hkaiHashSearchState_hkaiNavMeshSectionGraph_(
         this->m_graph.m_storage,
         this->m_graph.m_storage,
         &this->m_openset,
         &this->m_state,
         &this->m_state,
         &this->m_heuristic,
         &this->m_state,
         this->m_graph.m_storage);
  v1->m_lastClosedNode = v3;
  if ( hkaiHashSearchState::getNodeStateRO(&v1->m_state, v3)->m_flags.m_storage & 8 )
  {
    result = 1i64;
    v1->m_goalFoundIndex = v3 & 0x3FFFFF;
  }
  else if ( v1->m_openset.m_heapSize >= v1->m_openset.m_maxSize || v1->m_state.m_nodeSize >= v1->m_state.m_nodeCapacity )
  {
    result = 3i64;
  }
  else
  {
    result = 2i64;
    if ( v1->m_openset.m_heapSize )
      result = 0i64;
  }
  return result;
}

