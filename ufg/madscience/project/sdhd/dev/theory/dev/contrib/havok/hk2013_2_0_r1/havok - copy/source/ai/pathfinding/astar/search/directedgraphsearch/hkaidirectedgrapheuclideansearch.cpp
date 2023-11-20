// File Line: 30
// RVA: 0xC1F030
void __fastcall hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(hkaiDirectedGraphEuclideanSearch *this, hkaiSearchMemoryInfo *memInfo)
{
  hkaiDirectedGraphEuclideanSearch *v2; // rbx
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
  v2->m_openSet.m_heapSize = 0;
  v2->m_openSet.m_heap = (hkaiHeapOpenSet::IndexCostPair *)v6;
  v2->m_openSet.m_maxSize = v5 >> 3;
  hkaiHashSearchState::setStorage(v3, v4->m_searchStateBuffer, v4->m_searchStateSize);
}

// File Line: 35
// RVA: 0xC1F0D0
void __fastcall hkaiDirectedGraphEuclideanSearch::init(hkaiDirectedGraphEuclideanSearch *this, hkaiDirectedGraphVisitor *graph, unsigned int start, int end)
{
  unsigned int startPtr; // [rsp+50h] [rbp+18h]

  startPtr = start;
  hkaiDirectedGraphEuclideanSearch::init(this, graph, &startPtr, 1, end);
}

// File Line: 39
// RVA: 0xC1F100
void __fastcall hkaiDirectedGraphEuclideanSearch::init(hkaiDirectedGraphEuclideanSearch *this, hkaiDirectedGraphVisitor *graph, const unsigned int *startPtr, int numStartNodes, int end)
{
  hkaiHashSearchState *v5; // r10
  __int64 v6; // rsi
  const unsigned int *v7; // rbx
  hkaiDirectedGraphEuclideanSearch *v8; // rdi
  __int64 v9; // rcx
  hkaiDirectedGraphInstance *v10; // rax
  hkaiDirectedGraphVisitor *v11; // rax
  __m128 *v12; // r8
  __m128 v13; // xmm1
  hkaiDirectedGraphVisitor *v14; // rdx
  __int64 v15; // rax
  hkaiStreamingCollection::InstanceInfo *v16; // r8
  hkaiDirectedGraphInstance *v17; // rcx

  v5 = &this->m_state;
  v6 = (unsigned int)numStartNodes;
  v7 = startPtr;
  v8 = this;
  if ( this->m_state.m_nodeSize >= this->m_state.m_nodeCapacity )
    return;
  this->m_graph = graph;
  v9 = (unsigned int)end >> 22;
  if ( graph->m_streamingInfo )
  {
    if ( graph->m_cachedOutgoingSectionId == (_DWORD)v9 )
      goto LABEL_7;
    v10 = graph->m_streamingInfo[v9].m_clusterGraphInstance;
  }
  else
  {
    v10 = graph->m_incomingGraph;
  }
  graph->m_outgoingGraph = v10;
LABEL_7:
  graph->m_cachedOutgoingSectionId = v9;
  v11 = v8->m_graph;
  v8->m_heuristic.m_endKey = end;
  v8->m_heuristic.m_graph = v11;
  v12 = (__m128 *)v11->m_outgoingGraph;
  v13 = *(__m128 *)(v12[3].m128_u64[0] + 16i64 * (end & 0x3FFFFF));
  v8->m_heuristic.m_endPosition.m_quad = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v12[14]),
                                               _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v12[13])),
                                             _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v12[15])),
                                           v12[16]);
  v8->m_graph->m_searchState = v5;
  hkaiDirectedGraphEuclideanSearch::setEndNode(v8, end);
  if ( (signed int)v6 > 0 )
  {
    while ( *v7 == -1 )
    {
LABEL_15:
      ++v7;
      if ( !--v6 )
        return;
    }
    v14 = v8->m_graph;
    v15 = *v7 >> 22;
    v16 = v8->m_graph->m_streamingInfo;
    if ( v16 )
    {
      if ( v14->m_cachedOutgoingSectionId == (_DWORD)v15 )
      {
LABEL_14:
        v14->m_cachedOutgoingSectionId = v15;
        hkaiDirectedGraphEuclideanSearch::setStartNode(v8, *v7);
        goto LABEL_15;
      }
      v17 = v16[v15].m_clusterGraphInstance;
    }
    else
    {
      v17 = v14->m_incomingGraph;
    }
    v14->m_outgoingGraph = v17;
    goto LABEL_14;
  }
}

// File Line: 66
// RVA: 0xC1F240
void __fastcall hkaiDirectedGraphEuclideanSearch::setStartNode(hkaiDirectedGraphEuclideanSearch *this, unsigned int nid)
{
  hkaiHashSearchState *v2; // rbx
  unsigned int v3; // esi
  hkaiHeapOpenSet *v4; // rdi
  hkaiSearchStateNode *v5; // rax

  v2 = &this->m_state;
  v3 = nid;
  if ( this->m_state.m_nodeSize < this->m_state.m_nodeCapacity )
  {
    v4 = &this->m_openSet;
    if ( this->m_openSet.m_heapSize < this->m_openSet.m_maxSize )
    {
      hkaiHashSearchState::setStartNode<hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor>>(
        &this->m_state,
        &this->m_heuristic,
        nid,
        0.0);
      v5 = hkaiHashSearchState::getNodeStateRO(v2, v3);
      hkaiHeapOpenSet::insertSearchIndex(v4, v3, (float)(v2->m_heuristicWeight * v5->m_hCost) + v5->m_gCost);
    }
  }
}

// File Line: 76
// RVA: 0xC1F2C0
void __fastcall hkaiDirectedGraphEuclideanSearch::setEndNode(hkaiDirectedGraphEuclideanSearch *this, unsigned int nid)
{
  hkaiDirectedGraphEuclideanSearch *v2; // rdi
  unsigned int v3; // ebx
  hkaiSearchStateNode *v4; // rax
  hkaiDirectedGraphVisitor *v5; // rax
  __m128 *v6; // r8
  __m128 v7; // xmm1

  v2 = this;
  v3 = nid;
  v4 = hkaiHashSearchState::getNodeState(&this->m_state, nid);
  v4->m_hCost = 0.0;
  v4->m_flags.m_storage |= 8u;
  v5 = v2->m_heuristic.m_graph;
  v2->m_heuristic.m_endKey = v3;
  v6 = (__m128 *)v5->m_outgoingGraph;
  v7 = *(__m128 *)(v6[3].m128_u64[0] + 16i64 * (v3 & 0x3FFFFF));
  v2->m_heuristic.m_endPosition.m_quad = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v6[14]),
                                               _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6[13])),
                                             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v6[15])),
                                           v6[16]);
}

// File Line: 82
// RVA: 0xC1F360
signed __int64 __fastcall hkaiDirectedGraphEuclideanSearch::iteration(hkaiDirectedGraphEuclideanSearch *this)
{
  hkaiDirectedGraphEuclideanSearch *v1; // rbx
  signed __int64 result; // rax

  v1 = this;
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
  if ( v1->m_openSet.m_heapSize >= v1->m_openSet.m_maxSize || v1->m_state.m_nodeSize >= v1->m_state.m_nodeCapacity )
    return 3i64;
  result = 2i64;
  if ( v1->m_openSet.m_heapSize )
    result = 0i64;
  return result;
}

