// File Line: 28
// RVA: 0xC1F420
__int64 __fastcall hkaiAstarSearchIteration_hkaiDirectedGraphVisitor_hkaiDirectedGraphVisitor_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiGraphDistanceHeuristic_hkaiDirectedGraphVisitor__hkaiHashSearchState_hkaiDirectedGraphVisitor_(
        hkaiDirectedGraphVisitor *graph,
        hkaiDirectedGraphVisitor *edgeCost,
        hkaiHeapOpenSet *openset,
        hkaiHashSearchState *flags,
        hkaiHashSearchState *parent,
        hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor> *heuristic,
        hkaiHashSearchState *pathCost,
        hkaiDirectedGraphVisitor *listener)
{
  unsigned int SearchIndex; // eax
  hkaiDirectedGraphVisitor *v12; // rdi
  unsigned int v13; // esi
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // r9
  __int64 v15; // r8
  __m128 *m_incomingGraph; // rdx
  __int64 v17; // r9
  __int64 v18; // rcx
  int v19; // ecx
  __m128 *v20; // r8
  __m128 v21; // xmm1
  int m_numEdges; // r9d
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v27; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v28; // rbx
  int v29; // r11d
  int v30; // r9d
  int v31; // eax
  __int64 v32; // rdx
  unsigned int *p_m_target; // rcx
  hkaiHashSearchState *m_searchState; // rbx
  hkaiSearchStateNode *NodeState; // rax
  hkaiHashSearchState *v36; // rsi
  bool v37; // zf
  int v38; // ebx
  hkLifoAllocator *Value; // rax
  int *m_cur; // r12
  int v41; // edx
  char *v42; // rcx
  int v43; // r8d
  int v44; // r9d
  int m_startEdgeIndex; // r11d
  signed int v46; // edx
  int *v47; // rcx
  signed int v48; // r13d
  __m128i si128; // xmm2
  __m128i v50; // xmm1
  __m128i v51; // xmm0
  int v52; // eax
  int v53; // r10d
  signed int v54; // edx
  __m128i v55; // xmm2
  __m128i v56; // xmm1
  __m128i v57; // xmm0
  int v58; // eax
  int *v59; // r14
  hkaiDirectedGraphVisitor *v60; // r12
  int v61; // r13d
  hkaiHashSearchState *v62; // rbx
  __int64 v63; // rax
  unsigned int v64; // edx
  __int64 v65; // rcx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  __int64 v67; // r9
  __int64 v68; // r10
  int m_target; // ebx
  int v70; // eax
  __int128 v71; // xmm0
  __m128 *v72; // r8
  __int64 v73; // rdx
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  __int64 v76; // rax
  float TotalCost; // xmm0_4
  hkaiSearchStateNode *m_currentNodeState; // rcx
  int v79; // edx
  float v80; // xmm2_4
  hkaiSearchStateNode *m_parentNodeState; // rax
  int v82; // ebx
  signed int v83; // ebx
  hkLifoAllocator *v84; // rax
  int v85; // r8d
  int *v87; // [rsp+30h] [rbp-C8h]
  int *v88; // [rsp+38h] [rbp-C0h]
  __int64 v89[4]; // [rsp+40h] [rbp-B8h] BYREF
  int v90; // [rsp+60h] [rbp-98h] BYREF
  __int64 v91; // [rsp+68h] [rbp-90h]
  __int128 v92; // [rsp+70h] [rbp-88h]
  int v93; // [rsp+80h] [rbp-78h]
  hkaiDirectedGraphVisitor **v94; // [rsp+88h] [rbp-70h]
  __m128 v95; // [rsp+90h] [rbp-68h]
  int v96; // [rsp+A0h] [rbp-58h]
  __int64 v97; // [rsp+A8h] [rbp-50h]
  hkaiDirectedGraphVisitor *v98; // [rsp+100h] [rbp+8h] BYREF
  hkaiDirectedGraphVisitor *v99; // [rsp+108h] [rbp+10h]
  unsigned int nit; // [rsp+118h] [rbp+20h]

  v99 = edgeCost;
  v98 = graph;
  SearchIndex = hkaiHeapOpenSet::popNextSearchIndex(openset);
  v12 = listener;
  v13 = SearchIndex;
  m_streamingInfo = listener->m_streamingInfo;
  v15 = SearchIndex >> 22;
  nit = SearchIndex;
  listener->m_cachedNodeKey = SearchIndex;
  if ( m_streamingInfo && v12->m_cachedIncomingSectionId != (_DWORD)v15 )
    v12->m_incomingGraph = m_streamingInfo[v15].m_clusterGraphInstance;
  m_incomingGraph = (__m128 *)v12->m_incomingGraph;
  v12->m_cachedIncomingSectionId = v15;
  v17 = SearchIndex & 0x3FFFFF;
  v12->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(m_incomingGraph[1].m128_u64[0] + 8 * v17);
  if ( !m_incomingGraph[7].m128_i32[0] || (v18 = *(int *)(m_incomingGraph[6].m128_u64[1] + 4 * v17), (_DWORD)v18 == -1) )
  {
    v12->m_cachedInstanceNode.m_startEdgeIndex = -1;
    v12->m_cachedInstanceNode.m_numEdges = 0;
  }
  else
  {
    v12->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(m_incomingGraph[7].m128_u64[1] + 8 * v18);
  }
  v19 = 24;
  v20 = m_incomingGraph;
  v21 = *(__m128 *)(m_incomingGraph[3].m128_u64[0] + 16 * v17);
  m_numEdges = 24;
  if ( v12->m_cachedNode.m_numEdges < 24 )
    m_numEdges = v12->m_cachedNode.m_numEdges;
  v23 = _mm_shuffle_ps(v21, v21, 85);
  v24 = _mm_shuffle_ps(v21, v21, 0);
  v25 = _mm_shuffle_ps(v21, v21, 170);
  if ( v12->m_cachedInstanceNode.m_numEdges < 24 )
    v19 = v12->m_cachedInstanceNode.m_numEdges;
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v23, m_incomingGraph[14]), _mm_mul_ps(v24, m_incomingGraph[13])),
            _mm_mul_ps(v25, m_incomingGraph[15])),
          m_incomingGraph[16]);
  v12->m_cachedNode.m_numEdges = m_numEdges;
  v12->m_cachedInstanceNode.m_numEdges = v19;
  v12->m_cachedPosition.m_quad = v26;
  v27 = (hkaiDirectedGraphExplicitCost::Edge *)m_incomingGraph[2].m128_u64[0];
  v28 = (hkaiDirectedGraphExplicitCost::Edge *)v20[8].m128_u64[1];
  v29 = v20[5].m128_i32[2];
  if ( v27 )
    copyEdges_0(v12->m_localEdges, v27, v12->m_cachedNode.m_startEdgeIndex, m_numEdges);
  if ( v28 )
  {
    v30 = v12->m_cachedInstanceNode.m_numEdges;
    if ( v30 > 0 )
      copyEdges_0(
        &v12->m_localEdges[v12->m_cachedNode.m_numEdges],
        v28,
        v12->m_cachedInstanceNode.m_startEdgeIndex - v12->m_incomingGraph->m_numOriginalEdges,
        v30);
  }
  v12->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&v12->m_numGoals;
  v31 = v12->m_cachedNode.m_numEdges + v12->m_cachedInstanceNode.m_numEdges;
  v32 = v31;
  if ( v31 > 0 )
  {
    p_m_target = &v12->m_localEdges[0].m_target;
    do
    {
      if ( (*((_BYTE *)p_m_target - 2) & 0x40) == 0 )
      {
        *p_m_target &= 0x3FFFFFu;
        *p_m_target |= v29 << 22;
      }
      p_m_target += 2;
      --v32;
    }
    while ( v32 );
  }
  m_searchState = v12->m_searchState;
  NodeState = hkaiHashSearchState::getNodeState(m_searchState, v13);
  v36 = pathCost;
  m_searchState->m_currentNodeState = NodeState;
  m_searchState->m_parentNodeState = NodeState;
  m_searchState->m_parentIndex = (__int16)((__int64)(unsigned int)((_DWORD)NodeState - LODWORD(m_searchState->m_nodes)) >> 4);
  LODWORD(m_searchState) = graph->m_cachedInstanceNode.m_numEdges;
  v37 = graph->m_cachedNode.m_numEdges + (_DWORD)m_searchState == 0;
  v38 = graph->m_cachedNode.m_numEdges + (_DWORD)m_searchState;
  LODWORD(pathCost) = v38;
  if ( v37 )
  {
    m_cur = 0i64;
    v87 = 0i64;
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (int *)Value->m_cur;
    v41 = (4 * v38 + 127) & 0xFFFFFF80;
    v87 = m_cur;
    v42 = (char *)m_cur + v41;
    if ( v41 > Value->m_slabSize || v42 > Value->m_end )
    {
      m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v41);
      v87 = m_cur;
    }
    else
    {
      Value->m_cur = v42;
    }
  }
  v43 = graph->m_cachedNode.m_numEdges;
  v44 = graph->m_cachedInstanceNode.m_numEdges;
  m_startEdgeIndex = graph->m_cachedNode.m_startEdgeIndex;
  v46 = 0;
  v47 = m_cur;
  v48 = v38 | 0x80000000;
  LODWORD(listener) = v38 | 0x80000000;
  if ( v43 > 0 )
  {
    if ( (unsigned int)v43 >= 4 )
    {
      si128 = _mm_load_si128((const __m128i *)&_xmm);
      v50 = _mm_shuffle_epi32(_mm_cvtsi32_si128(m_startEdgeIndex), 0);
      do
      {
        v51 = _mm_cvtsi32_si128(v46);
        v46 += 4;
        v47 += 4;
        *((__m128i *)v47 - 1) = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v51, 0), si128), v50);
      }
      while ( v46 < (int)(v43 - (v43 & 0x80000003)) );
    }
    for ( ; v46 < v43; *(v47 - 1) = v52 )
    {
      v52 = v46 + m_startEdgeIndex;
      ++v46;
      ++v47;
    }
  }
  v53 = graph->m_cachedInstanceNode.m_startEdgeIndex;
  v54 = 0;
  if ( v44 > 0 )
  {
    if ( (unsigned int)v44 >= 4 )
    {
      v55 = _mm_load_si128((const __m128i *)&_xmm);
      v56 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v53), 0);
      do
      {
        v57 = _mm_cvtsi32_si128(v54);
        v54 += 4;
        v47 += 4;
        *((__m128i *)v47 - 1) = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v57, 0), v55), v56);
      }
      while ( v54 < (int)(v44 - (v44 & 0x80000003)) );
    }
    for ( ; v54 < v44; *(v47 - 1) = v58 )
    {
      v58 = v54 + v53;
      ++v54;
      ++v47;
    }
  }
  v59 = m_cur;
  v88 = &m_cur[v44 + v43];
  if ( m_cur < v88 )
  {
    v60 = v98;
    while ( 1 )
    {
      v61 = *v59;
      if ( flags->m_nodeSize >= flags->m_nodeCapacity )
      {
LABEL_62:
        m_cur = v87;
        v48 = (int)listener;
        goto LABEL_63;
      }
      v62 = v12->m_searchState;
      v63 = (__int64)&v12->m_currentEdge[1];
      v12->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)v63;
      v64 = *(_DWORD *)(v63 + 4);
      v62->m_currentNodeState = v64 == -1 ? 0i64 : hkaiHashSearchState::getNodeState(v62, v64);
      v65 = v12->m_currentEdge->m_target >> 22;
      if ( !v12->m_streamingInfo )
        break;
      if ( v12->m_cachedOutgoingSectionId != (_DWORD)v65 )
      {
        m_clusterGraphInstance = v12->m_streamingInfo[v65].m_clusterGraphInstance;
LABEL_50:
        v12->m_outgoingGraph = m_clusterGraphInstance;
      }
      v67 = (__int64)v99;
      v12->m_cachedOutgoingSectionId = v65;
      v68 = *(_QWORD *)(v67 + 40);
      m_target = v60->m_currentEdge->m_target;
      if ( !v68 )
        goto LABEL_73;
      v70 = *(_DWORD *)(v67 + 116);
      v71 = *(_OWORD *)(v67 + 64);
      v94 = 0i64;
      v90 = v70;
      v97 = 0i64;
      v72 = *(__m128 **)(v67 + 16);
      v92 = v71;
      v93 = -1;
      v96 = -1;
      v91 = v67 + 48;
      v73 = m_target & 0x3FFFFF;
      v98 = *(hkaiDirectedGraphVisitor **)(v72[1].m128_u64[0] + 8 * v73);
      v74 = *(__m128 *)(v72[3].m128_u64[0] + 16 * v73);
      v75 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v74, v74, 85), v72[14]),
                  _mm_mul_ps(_mm_shuffle_ps(v74, v74, 0), v72[13])),
                _mm_mul_ps(_mm_shuffle_ps(v74, v74, 170), v72[15])),
              v72[16]);
      v94 = &v98;
      v76 = *(_QWORD *)(v67 + 96);
      v93 = m_target;
      v97 = v76;
      LODWORD(v76) = *(_DWORD *)(v67 + 104);
      v95 = v75;
      v96 = v61 | ((_DWORD)v76 << 22);
      v89[0] = *(_QWORD *)v67;
      v89[1] = v67 + 80;
      v89[2] = (__int64)&v90;
      if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v68 + 24i64))(v68, v89) )
      {
LABEL_73:
        TotalCost = hkaiDirectedGraphVisitor::getTotalCost(v60, nit, m_target, v61);
        if ( TotalCost <= v36->m_maxPathCost
          && ((flags->m_currentNodeState->m_flags.m_storage & 3) == 0 || TotalCost < v36->m_currentNodeState->m_gCost) )
        {
          hkaiHashSearchState::setCost<hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor>>(
            v36,
            heuristic,
            m_target,
            TotalCost);
          parent->m_currentNodeState->m_parentIndex = parent->m_parentIndex;
          m_currentNodeState = flags->m_currentNodeState;
          v79 = m_currentNodeState->m_flags.m_storage & 1;
          v80 = (float)(v36->m_currentNodeState->m_hCost * v36->m_heuristicWeight) + v36->m_currentNodeState->m_gCost;
          if ( v80 <= v36->m_maxPathCost )
          {
            m_currentNodeState->m_flags.m_storage &= ~2u;
            m_currentNodeState->m_flags.m_storage |= 1u;
            if ( v79 )
            {
              hkaiHeapOpenSet::adjustValue(openset, m_target, v80);
            }
            else
            {
              if ( openset->m_heapSize >= openset->m_maxSize )
                goto LABEL_62;
              hkaiHeapOpenSet::insertSearchIndex(openset, m_target, v80);
            }
          }
        }
      }
      if ( ++v59 >= v88 )
        goto LABEL_62;
    }
    m_clusterGraphInstance = v12->m_incomingGraph;
    goto LABEL_50;
  }
LABEL_63:
  m_parentNodeState = flags->m_parentNodeState;
  v82 = (int)pathCost;
  m_parentNodeState->m_flags.m_storage &= ~1u;
  m_parentNodeState->m_flags.m_storage |= 2u;
  v83 = (4 * v82 + 127) & 0xFFFFFF80;
  v84 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v85 = (v83 + 15) & 0xFFFFFFF0;
  if ( v83 > v84->m_slabSize || (char *)m_cur + v85 != v84->m_cur || v84->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v84, m_cur, v85);
  else
    v84->m_cur = m_cur;
  if ( v48 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 4 * v48);
  return nit;
}

