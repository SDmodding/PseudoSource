// File Line: 33
// RVA: 0xC1C5D0
void __fastcall hkaiNavVolumeSearch::hkaiNavVolumeSearch(hkaiNavVolumeSearch *this, hkaiSearchMemoryInfo *memInfo)
{
  hkaiNavVolumeSearch *v2; // rbx
  hkaiHashSearchState *v3; // rcx
  hkaiSearchMemoryInfo *v4; // r9
  unsigned __int64 v5; // rdx
  char *v6; // rax

  this->m_state.m_heuristicWeight = 1.0;
  this->m_state.m_bestNode = -1;
  this->m_state.m_bestNodeCost = 3.40282e38;
  this->m_state.m_maxPathCost = 3.40282e38;
  v2 = this;
  v3 = &this->m_state;
  v4 = memInfo;
  v3->m_nodes = 0i64;
  v3->m_hashNext = 0i64;
  v3->m_hashFirst = 0i64;
  *(_QWORD *)&v3->m_nodeCapacity = 0i64;
  v3->m_dummyNode.m_parentIndex = -1;
  v3->m_dummyNode.m_gCost = 3.40282e38;
  v3->m_dummyNode.m_hCost = 3.40282e38;
  v3->m_dummyNode.m_index = -1;
  v3->m_dummyNode.m_flags.m_storage = 0;
  v5 = memInfo->m_openSetSize;
  v6 = v4->m_openSetBuffer;
  v2->m_openset.m_heapSize = 0;
  v2->m_openset.m_heap = (hkaiHeapOpenSet::IndexCostPair *)v6;
  v2->m_openset.m_maxSize = v5 >> 3;
  hkaiHashSearchState::setStorage(v3, v4->m_searchStateBuffer, v4->m_searchStateSize);
}

// File Line: 39
// RVA: 0xC1C670
void __fastcall hkaiNavVolumeSearch::init(hkaiNavVolumeSearch *this, hkaiNavVolumeGraph *graph, hkaiAgentTraversalInfo *agentInfo, hkaiNavVolumeSearch::StartGoalInfo *goalInfo)
{
  int *v4; // r14
  int v5; // er10
  __int64 v6; // rdi
  hkVector4f *v7; // r9
  __int64 v8; // rbx
  hkaiNavVolumeSearch *v9; // rsi
  int v10; // edx
  hkVector4f startPos; // [rsp+20h] [rbp-18h]

  this->m_graph.m_storage = graph;
  this->m_lastClosedCell = -1;
  v4 = (int *)goalInfo->m_goalCellKeys;
  v5 = goalInfo->m_startCellKey;
  v6 = goalInfo->m_numGoals;
  v7 = goalInfo->m_goalPoints;
  this->m_heuristic.m_graph = graph;
  v8 = 0i64;
  this->m_heuristic.m_numGoals = 0;
  v9 = this;
  this->m_heuristic.m_goals[0].m_index.m_storage = *v4;
  this->m_heuristic.m_goals[0].m_position = (hkVector4f)v7->m_quad;
  ++this->m_heuristic.m_numGoals;
  hkaiNavVolumeSearch::setStartCellAndPosition(this, v5, &startPos, agentInfo);
  if ( v6 > 0 )
  {
    do
    {
      v10 = v4[v8];
      if ( v10 != -1 )
        hkaiNavVolumeSearch::setEndCell(v9, v10);
      ++v8;
    }
    while ( v8 < v6 );
  }
}

// File Line: 86
// RVA: 0xC1C7C0
void __fastcall hkaiNavVolumeSearch::setEndCell(hkaiNavVolumeSearch *this, int endCellKey)
{
  hkaiSearchStateNode *v2; // rax

  v2 = hkaiHashSearchState::getNodeState(&this->m_state, endCellKey);
  v2->m_hCost = 0.0;
  v2->m_flags.m_storage |= 8u;
}

// File Line: 91
// RVA: 0xC1C720
void __fastcall hkaiNavVolumeSearch::setStartCellAndPosition(hkaiNavVolumeSearch *this, int startCellKey, hkVector4f *startPos, hkaiAgentTraversalInfo *agentInfo)
{
  hkaiNavVolumeGraph *v4; // r9
  int v5; // edi
  __int64 v6; // r8
  hkaiNavVolumeSearch *v7; // rbx
  hkaiNavVolumeInstance *v8; // rdx
  hkaiSearchStateNode *v9; // rax

  v4 = this->m_graph.m_storage;
  v5 = startCellKey;
  v6 = (unsigned int)startCellKey >> 22;
  v7 = this;
  if ( this->m_graph.m_storage->m_cachedAdjacentSectionId != (_DWORD)v6 )
  {
    v8 = v4->m_streamingInfo[v6].m_volumeInstancePtr;
    v4->m_cachedAdjacentSectionId = v6;
    v4->m_cachedAdjacentNavVolume = v8;
  }
  hkaiNavVolumeGraph::setAdjacentCachedCell(this->m_graph.m_storage, v5);
  if ( hkaiHashSearchState::setStartNode<hkaiGraphMultiDistanceHeuristic<hkaiNavVolumeGraph>>(
         &v7->m_state,
         &v7->m_heuristic,
         v5,
         0.0) )
  {
    v9 = hkaiHashSearchState::getNodeStateRO(&v7->m_state, v5);
    hkaiHeapOpenSet::insertSearchIndex(
      &v7->m_openset,
      v5,
      (float)(v7->m_state.m_heuristicWeight * v9->m_hCost) + v9->m_gCost);
  }
}

// File Line: 146
// RVA: 0xC1C7F0
signed __int64 __fastcall hkaiNavVolumeSearch::iteration(hkaiNavVolumeSearch *this)
{
  hkaiNavVolumeSearch *v1; // rdi
  signed __int64 result; // rax
  int v3; // eax
  __int64 v4; // r9
  int v5; // er8
  __int64 v6; // rdx
  hkPadSpu<int> *v7; // rcx

  v1 = this;
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
  v1->m_lastClosedCell = v3;
  v4 = v1->m_heuristic.m_numGoals;
  v5 = 0;
  v6 = 0i64;
  if ( v4 > 0 )
  {
    v7 = &v1->m_heuristic.m_goals[0].m_index;
    while ( v7->m_storage != v3 )
    {
      ++v6;
      ++v5;
      v7 += 8;
      if ( v6 >= v4 )
        goto LABEL_7;
    }
    if ( v5 != -1 )
      return 1i64;
  }
LABEL_7:
  if ( v1->m_openset.m_heapSize >= v1->m_openset.m_maxSize || v1->m_state.m_nodeSize >= v1->m_state.m_nodeCapacity )
    return 3i64;
  result = 2i64;
  if ( v1->m_openset.m_heapSize )
    result = 0i64;
  return result;
}

