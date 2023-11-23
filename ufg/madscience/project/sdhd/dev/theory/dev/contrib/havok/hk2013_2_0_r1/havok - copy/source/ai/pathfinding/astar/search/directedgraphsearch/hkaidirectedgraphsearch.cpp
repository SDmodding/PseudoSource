// File Line: 32
// RVA: 0xC02820
void __fastcall hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(
        hkaiDirectedGraphSearch *this,
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
  this->m_openSet.m_heap = (hkaiHeapOpenSet::IndexCostPair *)memInfo->m_openSetBuffer;
  this->m_openSet.m_heapSize = 0;
  this->m_openSet.m_maxSize = m_openSetSize >> 3;
  hkaiHierarchicalGraphHeuristic::hkaiHierarchicalGraphHeuristic(&this->m_heuristic, hierarchyMemInfo);
  this->m_clusterGraph.m_agentInfo = 0i64;
  this->m_clusterGraph.m_cachedNode.m_startEdgeIndex = -1;
  this->m_clusterGraph.m_cachedNode.m_numEdges = -1;
  this->m_clusterGraph.m_cachedInstanceNode.m_startEdgeIndex = -1;
  this->m_clusterGraph.m_cachedInstanceNode.m_numEdges = -1;
  this->m_clusterGraph.m_streamingInfo = 0i64;
  this->m_clusterGraph.m_cachedIncomingSectionId = -1;
  this->m_clusterGraph.m_cachedOutgoingSectionId = -1;
  this->m_clusterGraph.m_cachedGeneralSectionId = -1;
  this->m_clusterGraph.m_edgeFilter = 0i64;
  this->m_clusterGraph.m_costModifier = 0i64;
  this->m_clusterGraph.m_numGoals = 0;
  this->m_clusterGraph.m_goalNodes = 0i64;
  this->m_clusterGraph.m_finalCosts = 0i64;
  hkaiHashSearchState::setStorage(&this->m_state, memInfo->m_searchStateBuffer, memInfo->m_searchStateSize);
}

// File Line: 38
// RVA: 0xC02950
void __fastcall hkaiDirectedGraphSearch::init(
        hkaiDirectedGraphSearch *this,
        hkaiDirectedGraphVisitor *graph,
        hkaiDirectedGraphVisitor *clusterGraphInfo,
        hkaiDirectedGraphSearch::StartGoalInfo *goalInfo)
{
  hkaiStreamingCollection::InstanceInfo *v4; // rax
  int numGoals; // r10d
  const unsigned int *m_goalNodeKeys; // r12
  const float *m_finalCosts; // rax
  hkaiDirectedGraphVisitor *m_storage; // rcx
  __int64 v11; // rdx
  hkaiDirectedGraphInstance *m_incomingGraph; // rax
  int v13; // r13d
  __int64 v14; // r12
  hkaiDirectedGraphVisitor *v15; // rdx
  unsigned int v16; // esi
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // r8
  __int64 v18; // rcx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  hkaiDirectedGraphVisitor *v20; // rbx
  hkaiStreamingCollection::InstanceInfo *v21; // rdx
  __m128 *v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rcx
  unsigned __int64 v25; // rax
  __int64 v26; // r8
  __m128 *v27; // r10
  int m_numEdges; // r9d
  int v29; // ecx
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v35; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v36; // r14
  int v37; // r11d
  int v38; // r9d
  int v39; // eax
  __int64 v40; // rdx
  unsigned int *p_m_target; // rcx
  hkaiHashSearchState *m_searchState; // rbx
  hkaiSearchStateNode *NodeState; // rax
  hkaiSearchStateNode *v44; // rax
  hkaiSearchStateNode *v45; // rbx
  float Heuristic; // xmm0_4
  const float *m_initialCosts; // rax
  float v48; // xmm0_4
  hkaiSearchStateNode *m_currentNodeState; // rbx
  bool v50; // zf
  float v51; // xmm0_4
  hkaiSearchStateNode *NodeStateRO; // rax
  __int64 m_heapSize; // r10
  hkaiHeapOpenSet::IndexCostPair *m_heap; // rcx
  float v55; // xmm0_4
  hkaiHeapOpenSet::IndexCostPair *v56; // rcx
  int m_idx; // ebx
  hkaiHeapOpenSet::IndexCostPair::CostUnion v58; // r11d
  int i; // r9d
  hkaiHeapOpenSet::IndexCostPair *v60; // rdx
  __int64 v61; // rcx
  __int64 j; // rbx
  unsigned int v63; // edx
  hkaiSearchStateNode *v64; // rax
  int v65; // [rsp+80h] [rbp+8h]
  const unsigned int *v66; // [rsp+88h] [rbp+10h]

  v4 = (hkaiStreamingCollection::InstanceInfo *)clusterGraphInfo;
  this->m_lastClosedNode = -1;
  this->m_graph.m_storage = graph;
  if ( clusterGraphInfo )
  {
    clusterGraphInfo = &this->m_clusterGraph;
    this->m_clusterGraph.m_streamingInfo = v4;
  }
  numGoals = goalInfo->m_numGoals;
  m_goalNodeKeys = goalInfo->m_goalNodeKeys;
  m_finalCosts = goalInfo->m_finalCosts;
  graph->m_goalNodes = m_goalNodeKeys;
  graph->m_finalCosts = m_finalCosts;
  graph->m_numGoals = numGoals;
  m_storage = this->m_graph.m_storage;
  v65 = numGoals;
  v66 = m_goalNodeKeys;
  v11 = *goalInfo->m_startNodeKeys >> 22;
  if ( !m_storage->m_streamingInfo )
  {
    m_incomingGraph = m_storage->m_incomingGraph;
    goto LABEL_7;
  }
  if ( m_storage->m_cachedOutgoingSectionId != (_DWORD)v11 )
  {
    m_incomingGraph = m_storage->m_streamingInfo[v11].m_clusterGraphInstance;
LABEL_7:
    m_storage->m_outgoingGraph = m_incomingGraph;
  }
  m_storage->m_cachedOutgoingSectionId = v11;
  hkaiHierarchicalGraphHeuristic::init(
    &this->m_heuristic,
    this->m_graph.m_storage,
    clusterGraphInfo,
    *goalInfo->m_startNodeKeys,
    goalInfo->m_goalNodeKeys,
    numGoals);
  v13 = 0;
  if ( goalInfo->m_numStartNodeKeys <= 0 )
    goto LABEL_51;
  v14 = 0i64;
  do
  {
    v15 = this->m_graph.m_storage;
    v16 = goalInfo->m_startNodeKeys[v14];
    m_streamingInfo = this->m_graph.m_storage->m_streamingInfo;
    v18 = v16 >> 22;
    if ( !m_streamingInfo )
    {
      m_clusterGraphInstance = v15->m_incomingGraph;
      goto LABEL_14;
    }
    if ( v15->m_cachedOutgoingSectionId != (_DWORD)v18 )
    {
      m_clusterGraphInstance = m_streamingInfo[v18].m_clusterGraphInstance;
LABEL_14:
      v15->m_outgoingGraph = m_clusterGraphInstance;
    }
    v15->m_cachedOutgoingSectionId = v18;
    v20 = this->m_graph.m_storage;
    v21 = this->m_graph.m_storage->m_streamingInfo;
    this->m_graph.m_storage->m_cachedNodeKey = v16;
    if ( v21 && v20->m_cachedIncomingSectionId != (_DWORD)v18 )
      v20->m_incomingGraph = v21[v18].m_clusterGraphInstance;
    v22 = (__m128 *)v20->m_incomingGraph;
    v20->m_cachedIncomingSectionId = v18;
    v23 = v16 & 0x3FFFFF;
    v20->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(v22[1].m128_u64[0] + 8 * v23);
    if ( !v22[7].m128_i32[0] || (v24 = *(int *)(v22[6].m128_u64[1] + 4 * v23), (_DWORD)v24 == -1) )
    {
      v20->m_cachedInstanceNode.m_startEdgeIndex = -1;
      v20->m_cachedInstanceNode.m_numEdges = 0;
    }
    else
    {
      v20->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(v22[7].m128_u64[1] + 8 * v24);
    }
    v25 = v22[3].m128_u64[0];
    v26 = 2 * v23;
    v27 = v22;
    m_numEdges = 24;
    v29 = 24;
    v30 = *(__m128 *)(v25 + 8 * v26);
    if ( v20->m_cachedNode.m_numEdges < 24 )
      m_numEdges = v20->m_cachedNode.m_numEdges;
    v31 = _mm_shuffle_ps(*(__m128 *)(v25 + 8 * v26), v30, 85);
    v32 = _mm_shuffle_ps(*(__m128 *)(v25 + 8 * v26), v30, 0);
    v33 = _mm_shuffle_ps(v30, v30, 170);
    if ( v20->m_cachedInstanceNode.m_numEdges < 24 )
      v29 = v20->m_cachedInstanceNode.m_numEdges;
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, v22[14]), _mm_mul_ps(v32, v22[13])), _mm_mul_ps(v33, v22[15])),
            v22[16]);
    v20->m_cachedNode.m_numEdges = m_numEdges;
    v20->m_cachedInstanceNode.m_numEdges = v29;
    v20->m_cachedPosition.m_quad = v34;
    v35 = (hkaiDirectedGraphExplicitCost::Edge *)v22[2].m128_u64[0];
    v36 = (hkaiDirectedGraphExplicitCost::Edge *)v27[8].m128_u64[1];
    v37 = v27[5].m128_i32[2];
    if ( v35 )
      copyEdges(v20->m_localEdges, v35, v20->m_cachedNode.m_startEdgeIndex, m_numEdges);
    if ( v36 )
    {
      v38 = v20->m_cachedInstanceNode.m_numEdges;
      if ( v38 > 0 )
        copyEdges(
          &v20->m_localEdges[v20->m_cachedNode.m_numEdges],
          v36,
          v20->m_cachedInstanceNode.m_startEdgeIndex - v20->m_incomingGraph->m_numOriginalEdges,
          v38);
    }
    v20->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&v20->m_numGoals;
    v39 = v20->m_cachedNode.m_numEdges + v20->m_cachedInstanceNode.m_numEdges;
    v40 = v39;
    if ( v39 > 0 )
    {
      p_m_target = &v20->m_localEdges[0].m_target;
      do
      {
        if ( (*((_BYTE *)p_m_target - 2) & 0x40) == 0 )
        {
          *p_m_target &= 0x3FFFFFu;
          *p_m_target |= v37 << 22;
        }
        p_m_target += 2;
        --v40;
      }
      while ( v40 );
    }
    m_searchState = v20->m_searchState;
    NodeState = hkaiHashSearchState::getNodeState(m_searchState, v16);
    m_searchState->m_currentNodeState = NodeState;
    m_searchState->m_parentNodeState = NodeState;
    m_searchState->m_parentIndex = (__int16)((__int64)(unsigned int)((_DWORD)NodeState - LODWORD(m_searchState->m_nodes)) >> 4);
    v44 = hkaiHashSearchState::getNodeState(&this->m_state, v16);
    v44->m_gCost = 0.0;
    v45 = v44;
    Heuristic = hkaiHierarchicalGraphHeuristic::getHeuristic(&this->m_heuristic, v16);
    v45->m_hCost = Heuristic;
    v45->m_flags.m_storage |= 5u;
    if ( Heuristic < this->m_state.m_bestNodeCost )
    {
      this->m_state.m_bestNodeCost = Heuristic;
      this->m_state.m_bestNode = v16;
    }
    if ( v45->m_hCost < 3.40282e38 )
    {
      m_initialCosts = goalInfo->m_initialCosts;
      if ( m_initialCosts )
        v48 = m_initialCosts[v14];
      else
        v48 = 0.0;
      m_currentNodeState = this->m_state.m_currentNodeState;
      v50 = (m_currentNodeState->m_flags.m_storage & 3) == 0;
      m_currentNodeState->m_gCost = v48;
      if ( v50 )
      {
        v51 = hkaiHierarchicalGraphHeuristic::getHeuristic(&this->m_heuristic, v16);
        m_currentNodeState->m_hCost = v51;
        if ( v51 < this->m_state.m_bestNodeCost )
        {
          this->m_state.m_bestNodeCost = v51;
          this->m_state.m_bestNode = v16;
        }
      }
      NodeStateRO = hkaiHashSearchState::getNodeStateRO(&this->m_state, v16);
      m_heapSize = this->m_openSet.m_heapSize;
      m_heap = this->m_openSet.m_heap;
      v55 = (float)(NodeStateRO->m_hCost * this->m_state.m_heuristicWeight) + NodeStateRO->m_gCost;
      this->m_openSet.m_heapSize = m_heapSize + 1;
      m_heap[m_heapSize].m_idx = v16;
      m_heap[m_heapSize].m_cost.m_floatCost = v55;
      v56 = this->m_openSet.m_heap;
      m_idx = v56[m_heapSize].m_idx;
      LODWORD(v58.m_floatCost) = v56[m_heapSize].m_cost;
      for ( i = ((int)m_heapSize - 1) / 2; (int)m_heapSize > 0; i = (i - 1) / 2 )
      {
        v60 = this->m_openSet.m_heap;
        if ( v60[i].m_cost.m_intCost <= v58.m_intCost )
          break;
        v61 = (int)m_heapSize;
        LODWORD(m_heapSize) = i;
        v60[v61] = v60[i];
      }
      this->m_openSet.m_heap[(int)m_heapSize].m_idx = m_idx;
      this->m_openSet.m_heap[(int)m_heapSize].m_cost = v58;
    }
    ++v13;
    ++v14;
  }
  while ( v13 < goalInfo->m_numStartNodeKeys );
  m_goalNodeKeys = v66;
LABEL_51:
  for ( j = 0i64; j < v65; ++j )
  {
    v63 = m_goalNodeKeys[j];
    if ( v63 != -1 )
    {
      v64 = hkaiHashSearchState::getNodeState(&this->m_state, v63);
      v64->m_hCost = 0.0;
      v64->m_flags.m_storage |= 8u;
    }
  }
}

// File Line: 140
// RVA: 0xC02DB0
__int64 __fastcall hkaiDirectedGraphSearch::iteration(hkaiDirectedGraphSearch *this)
{
  __int64 result; // rax
  unsigned int v3; // eax

  if ( !this->m_openSet.m_heapSize )
    return 2i64;
  v3 = hkaiAstarSearchIteration_hkaiDirectedGraphVisitor_hkaiDirectedGraphVisitor_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiHierarchicalGraphHeuristic_hkaiHashSearchState_hkaiDirectedGraphVisitor_(
         this->m_graph.m_storage,
         this->m_graph.m_storage,
         &this->m_openSet,
         &this->m_state,
         &this->m_state,
         &this->m_heuristic,
         &this->m_state,
         this->m_graph.m_storage);
  this->m_lastClosedNode = v3;
  if ( (hkaiHashSearchState::getNodeStateRO(&this->m_state, v3)->m_flags.m_storage & 8) != 0 )
    return 1i64;
  if ( this->m_openSet.m_heapSize >= this->m_openSet.m_maxSize
    || this->m_state.m_nodeSize >= this->m_state.m_nodeCapacity )
  {
    return 3i64;
  }
  result = 2i64;
  if ( this->m_openSet.m_heapSize )
    return 0i64;
  return result;
}

