// File Line: 33
// RVA: 0xC1C5D0
void __fastcall hkaiNavVolumeSearch::hkaiNavVolumeSearch(hkaiNavVolumeSearch *this, hkaiSearchMemoryInfo *memInfo)
{
  hkaiHashSearchState *p_m_state; // rcx
  unsigned __int64 m_openSetSize; // rdx
  char *m_openSetBuffer; // rax

  this->m_state.m_heuristicWeight = 1.0;
  this->m_state.m_bestNode = -1;
  this->m_state.m_bestNodeCost = 3.40282e38;
  this->m_state.m_maxPathCost = 3.40282e38;
  p_m_state = &this->m_state;
  p_m_state->m_nodes = 0i64;
  p_m_state->m_hashNext = 0i64;
  p_m_state->m_hashFirst = 0i64;
  *(_QWORD *)&p_m_state->m_nodeCapacity = 0i64;
  p_m_state->m_dummyNode.m_parentIndex = -1;
  p_m_state->m_dummyNode.m_gCost = 3.40282e38;
  p_m_state->m_dummyNode.m_hCost = 3.40282e38;
  p_m_state->m_dummyNode.m_index = -1;
  p_m_state->m_dummyNode.m_flags.m_storage = 0;
  m_openSetSize = memInfo->m_openSetSize;
  m_openSetBuffer = memInfo->m_openSetBuffer;
  this->m_openset.m_heapSize = 0;
  this->m_openset.m_heap = (hkaiHeapOpenSet::IndexCostPair *)m_openSetBuffer;
  this->m_openset.m_maxSize = m_openSetSize >> 3;
  hkaiHashSearchState::setStorage(p_m_state, memInfo->m_searchStateBuffer, memInfo->m_searchStateSize);
}

// File Line: 39
// RVA: 0xC1C670
void __fastcall hkaiNavVolumeSearch::init(
        hkaiNavVolumeSearch *this,
        hkaiNavVolumeGraph *graph,
        hkaiAgentTraversalInfo *agentInfo,
        hkaiNavVolumeSearch::StartGoalInfo *goalInfo)
{
  int *m_goalCellKeys; // r14
  int m_startCellKey; // r10d
  __int64 m_numGoals; // rdi
  hkVector4f *m_goalPoints; // r9
  __int64 v8; // rbx
  int v10; // edx
  hkVector4f startPos; // [rsp+20h] [rbp-18h] BYREF

  this->m_graph.m_storage = graph;
  this->m_lastClosedCell = -1;
  m_goalCellKeys = (int *)goalInfo->m_goalCellKeys;
  m_startCellKey = goalInfo->m_startCellKey;
  m_numGoals = goalInfo->m_numGoals;
  m_goalPoints = goalInfo->m_goalPoints;
  this->m_heuristic.m_graph = graph;
  v8 = 0i64;
  this->m_heuristic.m_numGoals = 0;
  this->m_heuristic.m_goals[0].m_index.m_storage = *m_goalCellKeys;
  this->m_heuristic.m_goals[0].m_position = (hkVector4f)m_goalPoints->m_quad;
  ++this->m_heuristic.m_numGoals;
  hkaiNavVolumeSearch::setStartCellAndPosition(this, m_startCellKey, &startPos, agentInfo);
  if ( m_numGoals > 0 )
  {
    do
    {
      v10 = m_goalCellKeys[v8];
      if ( v10 != -1 )
        hkaiNavVolumeSearch::setEndCell(this, v10);
      ++v8;
    }
    while ( v8 < m_numGoals );
  }
}

// File Line: 86
// RVA: 0xC1C7C0
void __fastcall hkaiNavVolumeSearch::setEndCell(hkaiNavVolumeSearch *this, unsigned int endCellKey)
{
  hkaiSearchStateNode *NodeState; // rax

  NodeState = hkaiHashSearchState::getNodeState(&this->m_state, endCellKey);
  NodeState->m_hCost = 0.0;
  NodeState->m_flags.m_storage |= 8u;
}

// File Line: 91
// RVA: 0xC1C720
void __fastcall hkaiNavVolumeSearch::setStartCellAndPosition(
        hkaiNavVolumeSearch *this,
        unsigned int startCellKey,
        hkVector4f *startPos,
        hkaiAgentTraversalInfo *agentInfo)
{
  hkaiNavVolumeGraph *m_storage; // r9
  __int64 v6; // r8
  hkaiNavVolumeInstance *m_volumeInstancePtr; // rdx
  hkaiSearchStateNode *NodeStateRO; // rax

  m_storage = this->m_graph.m_storage;
  v6 = startCellKey >> 22;
  if ( this->m_graph.m_storage->m_cachedAdjacentSectionId != (_DWORD)v6 )
  {
    m_volumeInstancePtr = m_storage->m_streamingInfo[v6].m_volumeInstancePtr;
    m_storage->m_cachedAdjacentSectionId = v6;
    m_storage->m_cachedAdjacentNavVolume = m_volumeInstancePtr;
  }
  hkaiNavVolumeGraph::setAdjacentCachedCell(this->m_graph.m_storage, startCellKey);
  if ( hkaiHashSearchState::setStartNode<hkaiGraphMultiDistanceHeuristic<hkaiNavVolumeGraph>>(
         &this->m_state,
         &this->m_heuristic,
         startCellKey,
         0.0) )
  {
    NodeStateRO = hkaiHashSearchState::getNodeStateRO(&this->m_state, startCellKey);
    hkaiHeapOpenSet::insertSearchIndex(
      &this->m_openset,
      startCellKey,
      (float)(this->m_state.m_heuristicWeight * NodeStateRO->m_hCost) + NodeStateRO->m_gCost);
  }
}

// File Line: 146
// RVA: 0xC1C7F0
__int64 __fastcall hkaiNavVolumeSearch::iteration(hkaiNavVolumeSearch *this)
{
  __int64 result; // rax
  int v3; // eax
  __int64 m_numGoals; // r9
  int v5; // r8d
  __int64 v6; // rdx
  hkPadSpu<int> *p_m_index; // rcx

  if ( !this->m_openset.m_heapSize )
    return 2i64;
  v3 = hkaiAstarSearchIteration_hkaiNavVolumeGraph_hkaiNavVolumeGraph_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiGraphMultiDistanceHeuristic_hkaiNavVolumeGraph__hkaiHashSearchState_hkaiNavVolumeGraph_(
         this->m_graph.m_storage,
         this->m_graph.m_storage,
         &this->m_openset,
         &this->m_state,
         &this->m_state,
         &this->m_heuristic,
         &this->m_state,
         this->m_graph.m_storage);
  this->m_lastClosedCell = v3;
  m_numGoals = this->m_heuristic.m_numGoals;
  v5 = 0;
  v6 = 0i64;
  if ( m_numGoals > 0 )
  {
    p_m_index = &this->m_heuristic.m_goals[0].m_index;
    while ( p_m_index->m_storage != v3 )
    {
      ++v6;
      ++v5;
      p_m_index += 8;
      if ( v6 >= m_numGoals )
        goto LABEL_7;
    }
    if ( v5 != -1 )
      return 1i64;
  }
LABEL_7:
  if ( this->m_openset.m_heapSize >= this->m_openset.m_maxSize
    || this->m_state.m_nodeSize >= this->m_state.m_nodeCapacity )
  {
    return 3i64;
  }
  result = 2i64;
  if ( this->m_openset.m_heapSize )
    return 0i64;
  return result;
}

