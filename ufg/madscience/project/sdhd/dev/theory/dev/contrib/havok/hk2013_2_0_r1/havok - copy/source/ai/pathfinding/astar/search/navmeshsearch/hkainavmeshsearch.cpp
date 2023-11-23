// File Line: 33
// RVA: 0xBFED30
void __fastcall hkaiNavMeshSearch::hkaiNavMeshSearch(
        hkaiNavMeshSearch *this,
        hkaiSearchMemoryInfo *memInfo,
        hkaiSearchMemoryInfo *hierarchyMemInfo)
{
  unsigned __int64 m_openSetSize; // rcx

  this->m_state.m_heuristicWeight = 1.0;
  this->m_state.m_bestNode = -1;
  this->m_state.m_bestNodeCost = 3.40282e38;
  this->m_state.m_maxPathCost = 3.40282e38;
  this->m_state.m_nodes = 0i64;
  this->m_state.m_hashNext = 0i64;
  this->m_state.m_hashFirst = 0i64;
  *(_QWORD *)&this->m_state.m_nodeCapacity = 0i64;
  this->m_state.m_dummyNode.m_gCost = 3.40282e38;
  this->m_state.m_dummyNode.m_hCost = 3.40282e38;
  this->m_state.m_dummyNode.m_index = -1;
  this->m_state.m_dummyNode.m_flags.m_storage = 0;
  this->m_state.m_dummyNode.m_parentIndex = -1;
  m_openSetSize = memInfo->m_openSetSize;
  this->m_openset.m_heap = (hkaiHeapOpenSet::IndexCostPair *)memInfo->m_openSetBuffer;
  this->m_openset.m_heapSize = 0;
  this->m_openset.m_maxSize = m_openSetSize >> 3;
  hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(
    &this->m_heuristic.m_coarseSearch,
    hierarchyMemInfo);
  this->m_heuristic.m_accessor.m_currentSection = -1;
  this->m_heuristic.m_accessor.m_sectionInfo = 0i64;
  this->m_heuristic.m_accessor.m_accessor = 0i64;
  this->m_spuClusterGraph.m_agentInfo = 0i64;
  this->m_spuClusterGraph.m_cachedNode.m_startEdgeIndex = -1;
  this->m_spuClusterGraph.m_cachedNode.m_numEdges = -1;
  this->m_spuClusterGraph.m_cachedInstanceNode.m_startEdgeIndex = -1;
  this->m_spuClusterGraph.m_cachedInstanceNode.m_numEdges = -1;
  this->m_spuClusterGraph.m_streamingInfo = 0i64;
  this->m_spuClusterGraph.m_cachedIncomingSectionId = -1;
  this->m_spuClusterGraph.m_cachedOutgoingSectionId = -1;
  this->m_spuClusterGraph.m_cachedGeneralSectionId = -1;
  this->m_spuClusterGraph.m_edgeFilter = 0i64;
  this->m_spuClusterGraph.m_costModifier = 0i64;
  this->m_spuClusterGraph.m_numGoals = 0;
  this->m_spuClusterGraph.m_goalNodes = 0i64;
  this->m_spuClusterGraph.m_finalCosts = 0i64;
  hkaiHashSearchState::setStorage(&this->m_state, memInfo->m_searchStateBuffer, memInfo->m_searchStateSize);
}

// File Line: 39
// RVA: 0xBFEE70
void __fastcall hkaiNavMeshSearch::init(
        hkaiNavMeshSearch *this,
        hkaiNavMeshSectionGraph *graph,
        hkaiAgentTraversalInfo *agentInfo,
        hkaiNavMeshSearch::StartGoalInfo *goalInfo,
        bool isHierarchical)
{
  float m_diameter; // eax
  hkaiDirectedGraphVisitor *p_m_spuClusterGraph; // r8
  hkVector4f *goalPositions; // rax
  __int64 numGoals; // r15
  const unsigned int *originalGoalFaceKeys; // r14
  unsigned int m_startFaceKey; // ebp
  hkaiNavMeshSectionGraph *m_storage; // rsi
  int v13; // edx
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiNavMeshInstance *m_cachedOutgoingNavMesh; // rcx
  hkaiNavMesh::Face *v16; // rax
  int *v17; // rax
  hkaiHashSearchState *p_m_state; // rbp
  hkaiSearchStateNode *NodeStateRO; // rax
  int v20; // edi
  __int64 v21; // rbx
  hkaiSearchStateNode *NodeState; // rax
  hkVector4f startPosition; // [rsp+60h] [rbp-38h] BYREF
  int *dataPtrOut; // [rsp+A0h] [rbp+8h] BYREF

  m_diameter = agentInfo->m_diameter;
  *(_QWORD *)&this->m_lastClosedNode = -1i64;
  this->m_graph.m_storage = graph;
  this->m_diameter = m_diameter;
  if ( isHierarchical )
  {
    p_m_spuClusterGraph = &this->m_spuClusterGraph;
    this->m_spuClusterGraph.m_streamingInfo = graph->m_streamingInfo;
  }
  else
  {
    p_m_spuClusterGraph = 0i64;
  }
  goalPositions = goalInfo->m_goalPoints;
  numGoals = goalInfo->m_numGoals;
  originalGoalFaceKeys = goalInfo->m_goalFaceKeys;
  startPosition.m_quad = (__m128)goalInfo->m_startPoint;
  m_startFaceKey = goalInfo->m_startFaceKey;
  hkaiHierarchicalNavMeshHeuristic::init(
    &this->m_heuristic,
    graph,
    p_m_spuClusterGraph,
    m_startFaceKey,
    &startPosition,
    originalGoalFaceKeys,
    goalPositions,
    numGoals);
  m_storage = this->m_graph.m_storage;
  v13 = m_startFaceKey >> 22;
  if ( m_startFaceKey >> 22 == 1021 )
    v13 = m_storage->m_endFaceKeys[m_startFaceKey & 0x3FFFFF] >> 22;
  if ( m_storage->m_cachedOutgoingSectionId != v13 )
  {
    m_instancePtr = m_storage->m_streamingInfo[v13].m_instancePtr;
    m_storage->m_cachedOutgoingSectionId = v13;
    m_storage->m_cachedOutgoingNavMesh = m_instancePtr;
  }
  m_cachedOutgoingNavMesh = m_storage->m_cachedOutgoingNavMesh;
  v16 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int__1(
          m_cachedOutgoingNavMesh->m_originalFaces,
          m_cachedOutgoingNavMesh->m_numOriginalFaces,
          &m_cachedOutgoingNavMesh->m_instancedFaces,
          &m_cachedOutgoingNavMesh->m_ownedFaces,
          m_cachedOutgoingNavMesh->m_originalFaceData,
          &m_cachedOutgoingNavMesh->m_instancedFaceData,
          &m_cachedOutgoingNavMesh->m_ownedFaceData,
          &m_cachedOutgoingNavMesh->m_faceMap,
          m_startFaceKey & 0x3FFFFF,
          m_cachedOutgoingNavMesh->m_faceDataStriding,
          (const int **)&dataPtrOut);
  m_storage->m_cachedFaceKey = m_startFaceKey;
  m_storage->m_cachedFace = *v16;
  v17 = dataPtrOut;
  m_storage->m_cachedEdgePairInfo.m_faceKey = m_startFaceKey;
  m_storage->m_cachedEdgePairInfo.m_face = &m_storage->m_cachedFace;
  p_m_state = &this->m_state;
  m_storage->m_cachedEdgePairInfo.m_faceData = v17;
  if ( hkaiHashSearchState::setStartNode<hkaiHierarchicalNavMeshHeuristic>(
         &this->m_state,
         &this->m_heuristic,
         0xFF800000,
         0.0) )
  {
    NodeStateRO = hkaiHashSearchState::getNodeStateRO(&this->m_state, 0xFF800000);
    hkaiHeapOpenSet::insertSearchIndex(
      &this->m_openset,
      -8388608,
      (float)(this->m_state.m_heuristicWeight * NodeStateRO->m_hCost) + NodeStateRO->m_gCost);
  }
  v20 = 0;
  v21 = 0i64;
  if ( (int)numGoals > 0 )
  {
    do
    {
      if ( originalGoalFaceKeys[v21] != -1 )
      {
        NodeState = hkaiHashSearchState::getNodeState(p_m_state, v20 | 0xFF400000);
        NodeState->m_hCost = 0.0;
        NodeState->m_flags.m_storage |= 8u;
      }
      ++v21;
      ++v20;
    }
    while ( v21 < numGoals );
  }
}

// File Line: 132
// RVA: 0xBFF0A0
__int64 __fastcall hkaiNavMeshSearch::iteration(hkaiNavMeshSearch *this)
{
  __int64 result; // rax
  unsigned int v3; // edi

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
  this->m_lastClosedNode = v3;
  if ( (hkaiHashSearchState::getNodeStateRO(&this->m_state, v3)->m_flags.m_storage & 8) != 0 )
  {
    result = 1i64;
    this->m_goalFoundIndex = v3 & 0x3FFFFF;
  }
  else if ( this->m_openset.m_heapSize >= this->m_openset.m_maxSize
         || this->m_state.m_nodeSize >= this->m_state.m_nodeCapacity )
  {
    return 3i64;
  }
  else
  {
    result = 2i64;
    if ( this->m_openset.m_heapSize )
      return 0i64;
  }
  return result;
}

