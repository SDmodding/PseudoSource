// File Line: 30
// RVA: 0xC1F030
void __fastcall hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(
        hkaiDirectedGraphEuclideanSearch *this,
        hkaiSearchMemoryInfo *memInfo)
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
  this->m_openSet.m_heapSize = 0;
  this->m_openSet.m_heap = (hkaiHeapOpenSet::IndexCostPair *)m_openSetBuffer;
  this->m_openSet.m_maxSize = m_openSetSize >> 3;
  hkaiHashSearchState::setStorage(p_m_state, memInfo->m_searchStateBuffer, memInfo->m_searchStateSize);
}

// File Line: 35
// RVA: 0xC1F0D0
void __fastcall hkaiDirectedGraphEuclideanSearch::init(
        hkaiDirectedGraphEuclideanSearch *this,
        hkaiDirectedGraphVisitor *graph,
        unsigned int start,
        int end)
{
  unsigned int startPtr; // [rsp+50h] [rbp+18h] BYREF

  startPtr = start;
  hkaiDirectedGraphEuclideanSearch::init(this, graph, &startPtr, 1, end);
}

// File Line: 39
// RVA: 0xC1F100
void __fastcall hkaiDirectedGraphEuclideanSearch::init(
        hkaiDirectedGraphEuclideanSearch *this,
        hkaiDirectedGraphVisitor *graph,
        unsigned int *startPtr,
        unsigned int numStartNodes,
        unsigned int end)
{
  hkaiHashSearchState *p_m_state; // r10
  __int64 v6; // rsi
  __int64 v9; // rcx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  hkaiDirectedGraphVisitor *m_graph; // rax
  __m128 *m_outgoingGraph; // r8
  __m128 v13; // xmm1
  hkaiDirectedGraphVisitor *v14; // rdx
  __int64 v15; // rax
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // r8
  hkaiDirectedGraphInstance *m_incomingGraph; // rcx

  p_m_state = &this->m_state;
  v6 = numStartNodes;
  if ( this->m_state.m_nodeSize >= this->m_state.m_nodeCapacity )
    return;
  this->m_graph = graph;
  v9 = end >> 22;
  if ( graph->m_streamingInfo )
  {
    if ( graph->m_cachedOutgoingSectionId == (_DWORD)v9 )
      goto LABEL_7;
    m_clusterGraphInstance = graph->m_streamingInfo[v9].m_clusterGraphInstance;
  }
  else
  {
    m_clusterGraphInstance = graph->m_incomingGraph;
  }
  graph->m_outgoingGraph = m_clusterGraphInstance;
LABEL_7:
  graph->m_cachedOutgoingSectionId = v9;
  m_graph = this->m_graph;
  this->m_heuristic.m_endKey = end;
  this->m_heuristic.m_graph = m_graph;
  m_outgoingGraph = (__m128 *)m_graph->m_outgoingGraph;
  v13 = *(__m128 *)(m_outgoingGraph[3].m128_u64[0] + 16i64 * (end & 0x3FFFFF));
  this->m_heuristic.m_endPosition.m_quad = _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), m_outgoingGraph[14]),
                                                 _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), m_outgoingGraph[13])),
                                               _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), m_outgoingGraph[15])),
                                             m_outgoingGraph[16]);
  this->m_graph->m_searchState = p_m_state;
  hkaiDirectedGraphEuclideanSearch::setEndNode(this, end);
  if ( (int)v6 > 0 )
  {
    while ( *startPtr == -1 )
    {
LABEL_15:
      ++startPtr;
      if ( !--v6 )
        return;
    }
    v14 = this->m_graph;
    v15 = *startPtr >> 22;
    m_streamingInfo = this->m_graph->m_streamingInfo;
    if ( m_streamingInfo )
    {
      if ( v14->m_cachedOutgoingSectionId == (_DWORD)v15 )
      {
LABEL_14:
        v14->m_cachedOutgoingSectionId = v15;
        hkaiDirectedGraphEuclideanSearch::setStartNode(this, *startPtr);
        goto LABEL_15;
      }
      m_incomingGraph = m_streamingInfo[v15].m_clusterGraphInstance;
    }
    else
    {
      m_incomingGraph = v14->m_incomingGraph;
    }
    v14->m_outgoingGraph = m_incomingGraph;
    goto LABEL_14;
  }
}

// File Line: 66
// RVA: 0xC1F240
void __fastcall hkaiDirectedGraphEuclideanSearch::setStartNode(
        hkaiDirectedGraphEuclideanSearch *this,
        unsigned int nid)
{
  hkaiHashSearchState *p_m_state; // rbx
  hkaiHeapOpenSet *p_m_openSet; // rdi
  hkaiSearchStateNode *NodeStateRO; // rax

  p_m_state = &this->m_state;
  if ( this->m_state.m_nodeSize < this->m_state.m_nodeCapacity )
  {
    p_m_openSet = &this->m_openSet;
    if ( this->m_openSet.m_heapSize < this->m_openSet.m_maxSize )
    {
      hkaiHashSearchState::setStartNode<hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor>>(
        &this->m_state,
        &this->m_heuristic,
        nid,
        0.0);
      NodeStateRO = hkaiHashSearchState::getNodeStateRO(p_m_state, nid);
      hkaiHeapOpenSet::insertSearchIndex(
        p_m_openSet,
        nid,
        (float)(p_m_state->m_heuristicWeight * NodeStateRO->m_hCost) + NodeStateRO->m_gCost);
    }
  }
}

// File Line: 76
// RVA: 0xC1F2C0
void __fastcall hkaiDirectedGraphEuclideanSearch::setEndNode(hkaiDirectedGraphEuclideanSearch *this, unsigned int nid)
{
  hkaiSearchStateNode *NodeState; // rax
  hkaiDirectedGraphVisitor *m_graph; // rax
  __m128 *m_outgoingGraph; // r8
  __m128 v7; // xmm1

  NodeState = hkaiHashSearchState::getNodeState(&this->m_state, nid);
  NodeState->m_hCost = 0.0;
  NodeState->m_flags.m_storage |= 8u;
  m_graph = this->m_heuristic.m_graph;
  this->m_heuristic.m_endKey = nid;
  m_outgoingGraph = (__m128 *)m_graph->m_outgoingGraph;
  v7 = *(__m128 *)(m_outgoingGraph[3].m128_u64[0] + 16i64 * (nid & 0x3FFFFF));
  this->m_heuristic.m_endPosition.m_quad = _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), m_outgoingGraph[14]),
                                                 _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), m_outgoingGraph[13])),
                                               _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), m_outgoingGraph[15])),
                                             m_outgoingGraph[16]);
}

// File Line: 82
// RVA: 0xC1F360
__int64 __fastcall hkaiDirectedGraphEuclideanSearch::iteration(hkaiDirectedGraphEuclideanSearch *this)
{
  __int64 result; // rax

  if ( !this->m_openSet.m_heapSize )
    return 2i64;
  if ( this->m_heuristic.m_endKey == hkaiAstarSearchIteration_hkaiDirectedGraphVisitor_hkaiDirectedGraphVisitor_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiGraphDistanceHeuristic_hkaiDirectedGraphVisitor__hkaiHashSearchState_hkaiDirectedGraphVisitor_(
                                       this->m_graph,
                                       this->m_graph,
                                       &this->m_openSet,
                                       &this->m_state,
                                       &this->m_state,
                                       &this->m_heuristic,
                                       &this->m_state,
                                       this->m_graph) )
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

