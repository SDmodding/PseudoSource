// File Line: 32
// RVA: 0xC02820
void __fastcall hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(hkaiDirectedGraphSearch *this, hkaiSearchMemoryInfo *memInfo, hkaiSearchMemoryInfo *hierarchyMemInfo)
{
  hkaiDirectedGraphSearch *v3; // rsi
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
  v3->m_openSet.m_heap = (hkaiHeapOpenSet::IndexCostPair *)memInfo->m_openSetBuffer;
  v3->m_openSet.m_heapSize = 0;
  v3->m_openSet.m_maxSize = v5 >> 3;
  hkaiHierarchicalGraphHeuristic::hkaiHierarchicalGraphHeuristic(&v3->m_heuristic, hierarchyMemInfo);
  v3->m_clusterGraph.m_agentInfo = 0i64;
  v3->m_clusterGraph.m_cachedNode.m_startEdgeIndex = -1;
  v3->m_clusterGraph.m_cachedNode.m_numEdges = -1;
  v3->m_clusterGraph.m_cachedInstanceNode.m_startEdgeIndex = -1;
  v3->m_clusterGraph.m_cachedInstanceNode.m_numEdges = -1;
  v3->m_clusterGraph.m_streamingInfo = 0i64;
  v3->m_clusterGraph.m_cachedIncomingSectionId = -1;
  v3->m_clusterGraph.m_cachedOutgoingSectionId = -1;
  v3->m_clusterGraph.m_cachedGeneralSectionId = -1;
  v3->m_clusterGraph.m_edgeFilter = 0i64;
  v3->m_clusterGraph.m_costModifier = 0i64;
  v3->m_clusterGraph.m_numGoals = 0;
  v3->m_clusterGraph.m_goalNodes = 0i64;
  v3->m_clusterGraph.m_finalCosts = 0i64;
  hkaiHashSearchState::setStorage(&v3->m_state, v4->m_searchStateBuffer, v4->m_searchStateSize);
}

// File Line: 38
// RVA: 0xC02950
void __fastcall hkaiDirectedGraphSearch::init(hkaiDirectedGraphSearch *this, hkaiDirectedGraphVisitor *graph, hkaiStreamingCollection::InstanceInfo *clusterGraphInfo, hkaiDirectedGraphSearch::StartGoalInfo *goalInfo)
{
  hkaiStreamingCollection::InstanceInfo *v4; // rax
  hkaiDirectedGraphSearch::StartGoalInfo *v5; // r15
  hkaiDirectedGraphSearch *v6; // rdi
  int numGoals; // er10
  const unsigned int *v8; // r12
  const float *v9; // rax
  hkaiDirectedGraphVisitor *v10; // rcx
  __int64 v11; // rdx
  hkaiDirectedGraphInstance *v12; // rax
  int v13; // er13
  __int64 v14; // r12
  hkaiDirectedGraphVisitor *v15; // rdx
  unsigned int v16; // esi
  hkaiStreamingCollection::InstanceInfo *v17; // r8
  __int64 v18; // rcx
  hkaiDirectedGraphInstance *v19; // rax
  hkaiDirectedGraphVisitor *v20; // rbx
  hkaiStreamingCollection::InstanceInfo *v21; // rdx
  __m128 *v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // r8
  __m128 *v27; // r10
  int v28; // er9
  signed int v29; // ecx
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v35; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v36; // r14
  float v37; // er11
  float originalGoalNodeKeys; // ST20_4
  int v39; // er9
  hkaiDirectedGraphInstance *v40; // r10
  int v41; // ST20_4
  int v42; // eax
  __int64 v43; // rdx
  unsigned int *v44; // rcx
  hkaiHashSearchState *v45; // rbx
  hkaiSearchStateNode *v46; // rax
  hkaiSearchStateNode *v47; // rax
  hkaiSearchStateNode *v48; // rbx
  float v49; // xmm0_4
  const float *v50; // rax
  float v51; // xmm0_4
  hkaiSearchStateNode *v52; // rbx
  bool v53; // zf
  float v54; // xmm0_4
  hkaiSearchStateNode *v55; // rax
  __int64 v56; // r10
  hkaiHeapOpenSet::IndexCostPair *v57; // rcx
  float v58; // xmm0_4
  hkaiHeapOpenSet::IndexCostPair *v59; // rcx
  int v60; // ebx
  hkaiHeapOpenSet::IndexCostPair::CostUnion v61; // er11
  int i; // er9
  hkaiHeapOpenSet::IndexCostPair *v63; // rdx
  __int64 v64; // rcx
  __int64 v65; // rcx
  signed __int64 j; // rbx
  unsigned int v67; // edx
  hkaiSearchStateNode *v68; // rax
  int v69; // [rsp+80h] [rbp+8h]
  const unsigned int *v70; // [rsp+88h] [rbp+10h]

  v4 = clusterGraphInfo;
  v5 = goalInfo;
  v6 = this;
  this->m_lastClosedNode = -1;
  this->m_graph.m_storage = graph;
  if ( clusterGraphInfo )
  {
    clusterGraphInfo = (hkaiStreamingCollection::InstanceInfo *)&this->m_clusterGraph;
    this->m_clusterGraph.m_streamingInfo = v4;
  }
  numGoals = goalInfo->m_numGoals;
  v8 = goalInfo->m_goalNodeKeys;
  v9 = goalInfo->m_finalCosts;
  graph->m_goalNodes = v8;
  graph->m_finalCosts = v9;
  graph->m_numGoals = numGoals;
  v10 = this->m_graph.m_storage;
  v69 = numGoals;
  v70 = v8;
  v11 = *goalInfo->m_startNodeKeys >> 22;
  if ( !v10->m_streamingInfo )
  {
    v12 = v10->m_incomingGraph;
    goto LABEL_7;
  }
  if ( v10->m_cachedOutgoingSectionId != (_DWORD)v11 )
  {
    v12 = v10->m_streamingInfo[v11].m_clusterGraphInstance;
LABEL_7:
    v10->m_outgoingGraph = v12;
  }
  v10->m_cachedOutgoingSectionId = v11;
  hkaiHierarchicalGraphHeuristic::init(
    &v6->m_heuristic,
    v6->m_graph.m_storage,
    (hkaiDirectedGraphVisitor *)clusterGraphInfo,
    *goalInfo->m_startNodeKeys,
    goalInfo->m_goalNodeKeys,
    numGoals);
  v13 = 0;
  if ( v5->m_numStartNodeKeys <= 0 )
    goto LABEL_51;
  v14 = 0i64;
  do
  {
    v15 = v6->m_graph.m_storage;
    v16 = v5->m_startNodeKeys[v14];
    v17 = v6->m_graph.m_storage->m_streamingInfo;
    v18 = v5->m_startNodeKeys[v14] >> 22;
    if ( !v17 )
    {
      v19 = v15->m_incomingGraph;
      goto LABEL_14;
    }
    if ( v15->m_cachedOutgoingSectionId != (_DWORD)v18 )
    {
      v19 = v17[v18].m_clusterGraphInstance;
LABEL_14:
      v15->m_outgoingGraph = v19;
    }
    v15->m_cachedOutgoingSectionId = v18;
    v20 = v6->m_graph.m_storage;
    v21 = v6->m_graph.m_storage->m_streamingInfo;
    v6->m_graph.m_storage->m_cachedNodeKey = v16;
    if ( v21 && v20->m_cachedIncomingSectionId != (_DWORD)v18 )
      v20->m_incomingGraph = v21[v18].m_clusterGraphInstance;
    v22 = (__m128 *)v20->m_incomingGraph;
    v20->m_cachedIncomingSectionId = v18;
    v23 = v16 & 0x3FFFFF;
    v20->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(v22[1].m128_u64[0] + 8 * v23);
    if ( v22[7].m128_i32[0] && (v24 = *(signed int *)(v22[6].m128_u64[1] + 4 * v23), (_DWORD)v24 != -1) )
    {
      v20->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(v22[7].m128_u64[1] + 8 * v24);
    }
    else
    {
      v20->m_cachedInstanceNode.m_startEdgeIndex = -1;
      v20->m_cachedInstanceNode.m_numEdges = 0;
    }
    v25 = v22[3].m128_u64[0];
    v26 = 2 * v23;
    v27 = v22;
    v28 = 24;
    v29 = 24;
    v30 = *(__m128 *)(v25 + 8 * v26);
    if ( v20->m_cachedNode.m_numEdges < 24 )
      v28 = v20->m_cachedNode.m_numEdges;
    v31 = _mm_shuffle_ps(*(__m128 *)(v25 + 8 * v26), v30, 85);
    v32 = _mm_shuffle_ps(*(__m128 *)(v25 + 8 * v26), v30, 0);
    v33 = _mm_shuffle_ps(v30, v30, 170);
    if ( v20->m_cachedInstanceNode.m_numEdges < 24 )
      v29 = v20->m_cachedInstanceNode.m_numEdges;
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, v22[14]), _mm_mul_ps(v32, v22[13])), _mm_mul_ps(v33, v22[15])),
            v22[16]);
    v20->m_cachedNode.m_numEdges = v28;
    v20->m_cachedInstanceNode.m_numEdges = v29;
    v20->m_cachedPosition.m_quad = v34;
    v35 = (hkaiDirectedGraphExplicitCost::Edge *)v22[2].m128_u64[0];
    v36 = (hkaiDirectedGraphExplicitCost::Edge *)v27[8].m128_u64[1];
    v37 = v27[5].m128_f32[2];
    if ( v35 )
    {
      originalGoalNodeKeys = v27[2].m128_f32[2];
      copyEdges(v20->m_localEdges, v35, v20->m_cachedNode.m_startEdgeIndex, v28);
    }
    if ( v36 )
    {
      v39 = v20->m_cachedInstanceNode.m_numEdges;
      if ( v39 > 0 )
      {
        v40 = v20->m_incomingGraph;
        v41 = v40->m_ownedEdges.m_size;
        copyEdges(
          (hkaiDirectedGraphExplicitCost::Edge *)&v20->m_streamingInfo + v20->m_cachedNode.m_numEdges + 18i64,
          v36,
          v20->m_cachedInstanceNode.m_startEdgeIndex - v40->m_numOriginalEdges,
          v39);
      }
    }
    v20->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&v20->m_numGoals;
    v42 = v20->m_cachedNode.m_numEdges + v20->m_cachedInstanceNode.m_numEdges;
    v43 = v42;
    if ( v42 > 0 )
    {
      v44 = &v20->m_localEdges[0].m_target;
      do
      {
        if ( !(*((_BYTE *)v44 - 2) & 0x40) )
        {
          *v44 &= 0x3FFFFFu;
          *v44 |= LODWORD(v37) << 22;
        }
        v44 += 2;
        --v43;
      }
      while ( v43 );
    }
    v45 = v20->m_searchState;
    v46 = hkaiHashSearchState::getNodeState(v45, v16);
    v45->m_currentNodeState = v46;
    v45->m_parentNodeState = v46;
    v45->m_parentIndex = (signed __int16)((signed __int64)(unsigned int)((_DWORD)v46 - LODWORD(v45->m_nodes)) >> 4);
    v47 = hkaiHashSearchState::getNodeState(&v6->m_state, v16);
    v47->m_gCost = 0.0;
    v48 = v47;
    v49 = hkaiHierarchicalGraphHeuristic::getHeuristic(&v6->m_heuristic, v16);
    v48->m_hCost = v49;
    v48->m_flags.m_storage |= 5u;
    if ( v49 < v6->m_state.m_bestNodeCost )
    {
      v6->m_state.m_bestNodeCost = v49;
      v6->m_state.m_bestNode = v16;
    }
    if ( v48->m_hCost < 3.40282e38 )
    {
      v50 = v5->m_initialCosts;
      if ( v50 )
        v51 = v50[v14];
      else
        v51 = 0.0;
      v52 = v6->m_state.m_currentNodeState;
      v53 = (v52->m_flags.m_storage & 3) == 0;
      v52->m_gCost = v51;
      if ( v53 )
      {
        v54 = hkaiHierarchicalGraphHeuristic::getHeuristic(&v6->m_heuristic, v16);
        v52->m_hCost = v54;
        if ( v54 < v6->m_state.m_bestNodeCost )
        {
          v6->m_state.m_bestNodeCost = v54;
          v6->m_state.m_bestNode = v16;
        }
      }
      v55 = hkaiHashSearchState::getNodeStateRO(&v6->m_state, v16);
      v56 = v6->m_openSet.m_heapSize;
      v57 = v6->m_openSet.m_heap;
      v58 = (float)(v55->m_hCost * v6->m_state.m_heuristicWeight) + v55->m_gCost;
      v6->m_openSet.m_heapSize = v56 + 1;
      v57[v56].m_idx = v16;
      v57[v56].m_cost.m_floatCost = v58;
      v59 = v6->m_openSet.m_heap;
      v60 = v59[v56].m_idx;
      LODWORD(v61.m_floatCost) = v59[v56].m_cost;
      for ( i = ((signed int)v56 - 1) / 2; (signed int)v56 > 0; i = (i - 1) / 2 )
      {
        v63 = v6->m_openSet.m_heap;
        if ( v63[i].m_cost.m_intCost <= v61.m_intCost )
          break;
        v64 = (signed int)v56;
        LODWORD(v56) = i;
        v63[v64] = v63[i];
      }
      v65 = (signed int)v56;
      v6->m_openSet.m_heap[v65].m_idx = v60;
      v6->m_openSet.m_heap[v65].m_cost = v61;
    }
    ++v13;
    ++v14;
  }
  while ( v13 < v5->m_numStartNodeKeys );
  v8 = v70;
LABEL_51:
  for ( j = 0i64; j < v69; ++j )
  {
    v67 = v8[j];
    if ( v67 != -1 )
    {
      v68 = hkaiHashSearchState::getNodeState(&v6->m_state, v67);
      v68->m_hCost = 0.0;
      v68->m_flags.m_storage |= 8u;
    }
  }
}

// File Line: 140
// RVA: 0xC02DB0
signed __int64 __fastcall hkaiDirectedGraphSearch::iteration(hkaiDirectedGraphSearch *this)
{
  hkaiDirectedGraphSearch *v1; // rbx
  signed __int64 result; // rax
  unsigned int v3; // eax

  v1 = this;
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
  v1->m_lastClosedNode = v3;
  if ( hkaiHashSearchState::getNodeStateRO(&v1->m_state, v3)->m_flags.m_storage & 8 )
    return 1i64;
  if ( v1->m_openSet.m_heapSize >= v1->m_openSet.m_maxSize || v1->m_state.m_nodeSize >= v1->m_state.m_nodeCapacity )
    return 3i64;
  result = 2i64;
  if ( v1->m_openSet.m_heapSize )
    result = 0i64;
  return result;
}

