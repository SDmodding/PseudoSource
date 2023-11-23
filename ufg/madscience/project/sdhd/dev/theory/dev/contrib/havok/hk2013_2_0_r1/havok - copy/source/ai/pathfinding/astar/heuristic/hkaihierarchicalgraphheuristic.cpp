// File Line: 23
// RVA: 0xC24DB0
void __fastcall hkaiHierarchicalGraphHeuristic::hkaiHierarchicalGraphHeuristic(
        hkaiHierarchicalGraphHeuristic *this,
        hkaiSearchMemoryInfo *memInfo)
{
  this->m_originalStartCluster = -1;
  hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(&this->m_coarseSearch, memInfo);
}

// File Line: 29
// RVA: 0xC24DE0
void __fastcall hkaiHierarchicalGraphHeuristic::init(
        hkaiHierarchicalGraphHeuristic *this,
        hkaiDirectedGraphVisitor *originalGraph,
        hkaiDirectedGraphVisitor *clusterGraph,
        unsigned int originalStartNodeKey,
        unsigned int originalEnd)
{
  hkaiHierarchicalGraphHeuristic::init(this, originalGraph, clusterGraph, originalStartNodeKey, &originalEnd, 1);
}

// File Line: 34
// RVA: 0xC24E10
void __fastcall hkaiHierarchicalGraphHeuristic::init(
        hkaiHierarchicalGraphHeuristic *this,
        hkaiDirectedGraphVisitor *originalGraph,
        hkaiDirectedGraphVisitor *clusterGraph,
        unsigned int originalStartNodeKey,
        unsigned int *originalGoalNodeKeys,
        int numGoals)
{
  const unsigned int *v6; // r15
  int v8; // ecx
  int v10; // edi
  int v12; // esi
  unsigned int *v13; // r14
  int i; // r10d
  hkaiDirectedGraphVisitor *m_originalGraph; // r8
  int v16; // r9d
  __int64 v17; // rdx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx
  hkaiDirectedGraphInstance *m_generalGraph; // r8
  int m_nodeDataStriding; // eax
  const unsigned int *v21; // r8
  int v22; // edx
  bool v23; // al
  hkaiDirectedGraphVisitor *v24; // r8
  unsigned int v25; // edx
  unsigned int v26; // r12d
  __int64 v27; // rdx
  hkaiDirectedGraphInstance *v28; // rcx
  hkaiDirectedGraphInstance *v29; // r8
  int v30; // eax
  const unsigned int *v31; // r8
  int end; // edx
  unsigned int *m_endClusterKeys; // rsi

  v6 = originalGoalNodeKeys;
  v8 = 16;
  if ( numGoals < 16 )
    v8 = numGoals;
  v10 = 0;
  this->m_originalGraph = originalGraph;
  this->m_clusterGraph = clusterGraph;
  this->m_startNodeKey = originalStartNodeKey;
  this->m_numGoals = v8;
  this->m_goalNodeKeys = originalGoalNodeKeys;
  v12 = 0;
  if ( v8 > 0 )
  {
    v13 = originalGoalNodeKeys;
    do
      hkaiHierarchicalGraphHeuristic::getNodePosition(this, *v13++, &this->m_goalPositions[v12++]);
    while ( v12 < this->m_numGoals );
  }
  this->m_hasValidGoalCluster = 0;
  if ( clusterGraph )
  {
    for ( i = 0; i < this->m_numGoals; ++v6 )
    {
      m_originalGraph = this->m_originalGraph;
      v16 = *v6 & 0x3FFFFF;
      v17 = *v6 >> 22;
      if ( this->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v17 )
      {
        m_clusterGraphInstance = m_originalGraph->m_streamingInfo[v17].m_clusterGraphInstance;
        m_originalGraph->m_cachedGeneralSectionId = v17;
        m_originalGraph->m_generalGraph = m_clusterGraphInstance;
      }
      m_generalGraph = this->m_originalGraph->m_generalGraph;
      m_nodeDataStriding = m_generalGraph->m_nodeDataStriding;
      if ( m_nodeDataStriding && (v21 = &m_generalGraph->m_originalNodeData[v16 * m_nodeDataStriding]) != 0i64 )
        v22 = *v21 | ((_DWORD)v17 << 22);
      else
        v22 = -1;
      *(const unsigned int *)((char *)v6 + (char *)this - (char *)originalGoalNodeKeys + 44) = v22;
      if ( this->m_hasValidGoalCluster || (v23 = 0, v22 != -1) )
        v23 = 1;
      ++i;
      this->m_hasValidGoalCluster = v23;
    }
    v24 = this->m_originalGraph;
    v25 = originalStartNodeKey;
    v26 = originalStartNodeKey & 0x3FFFFF;
    v27 = v25 >> 22;
    if ( this->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v27 )
    {
      v28 = v24->m_streamingInfo[v27].m_clusterGraphInstance;
      v24->m_cachedGeneralSectionId = v27;
      v24->m_generalGraph = v28;
    }
    v29 = this->m_originalGraph->m_generalGraph;
    v30 = v29->m_nodeDataStriding;
    if ( v30 && (v31 = &v29->m_originalNodeData[v26 * v30]) != 0i64 )
      end = *v31 | ((_DWORD)v27 << 22);
    else
      end = -1;
    this->m_originalStartCluster = end;
    if ( end != -1 && this->m_hasValidGoalCluster )
      hkaiDirectedGraphEuclideanSearch::init(
        &this->m_coarseSearch,
        this->m_clusterGraph,
        this->m_endClusterKeys,
        this->m_numGoals,
        end);
    if ( this->m_numGoals > 0 )
    {
      m_endClusterKeys = this->m_endClusterKeys;
      do
      {
        if ( *m_endClusterKeys != -1 )
          hkaiHierarchicalGraphHeuristic::getClusterPosition(this, *m_endClusterKeys, &this->m_endClusterPositions[v10]);
        ++v10;
        ++m_endClusterKeys;
      }
      while ( v10 < this->m_numGoals );
    }
  }
}

// File Line: 100
// RVA: 0xC25770
void __fastcall hkaiHierarchicalGraphHeuristic::getClusterPosition(
        hkaiHierarchicalGraphHeuristic *this,
        unsigned int key,
        hkVector4f *posOut)
{
  hkaiDirectedGraphVisitor *m_clusterGraph; // r10
  __int64 v6; // r9
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx
  hkaiDirectedGraphInstance *m_generalGraph; // rdx
  __m128 m_quad; // xmm1

  m_clusterGraph = this->m_clusterGraph;
  v6 = key >> 22;
  if ( m_clusterGraph->m_cachedGeneralSectionId != (_DWORD)v6 )
  {
    m_clusterGraphInstance = m_clusterGraph->m_streamingInfo[v6].m_clusterGraphInstance;
    m_clusterGraph->m_cachedGeneralSectionId = v6;
    m_clusterGraph->m_generalGraph = m_clusterGraphInstance;
  }
  m_generalGraph = this->m_clusterGraph->m_generalGraph;
  m_quad = m_generalGraph->m_originalPositions[key & 0x3FFFFF].m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 85),
                           m_generalGraph->m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(m_quad, m_quad, 0),
                           m_generalGraph->m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(m_quad, m_quad, 170),
                         m_generalGraph->m_transform.m_rotation.m_col2.m_quad)),
                     m_generalGraph->m_transform.m_translation.m_quad);
}

// File Line: 113
// RVA: 0xC25020
float __fastcall hkaiHierarchicalGraphHeuristic::getHeuristic(
        hkaiHierarchicalGraphHeuristic *this,
        unsigned int nodeKey)
{
  unsigned int ClusterForNode; // eax
  char v5; // r9
  unsigned int v6; // edi
  __int64 v7; // rax
  __m128 v8; // xmm6
  __m128 m_quad; // xmm8
  __m128 v10; // xmm7
  hkVector4f *v11; // rdx
  unsigned int *m_endClusterKeys; // rcx
  __int64 v13; // r8
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  hkVector4f *v19; // rbx
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  int v24; // r14d
  hkaiSearchStateNode *NodeState; // r15
  int v26; // r12d
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  int v35; // r15d
  unsigned int Parent; // edi
  int v37; // edi
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *Value; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  bool v45; // zf
  __int64 v46; // rdx
  __int64 v47; // rcx
  unsigned int *v48; // rax
  _QWORD *v49; // rcx
  _QWORD *v50; // r8
  unsigned __int64 v51; // rax
  _QWORD *v52; // r8
  int v53; // esi
  __m128 v54; // xmm10
  __m128 v55; // xmm8
  __m128 v56; // xmm8
  __m128 v57; // xmm1
  __m128 v58; // xmm9
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm8
  __m128 v62; // xmm4
  __int64 m_numGoals; // rax
  __m128 v64; // xmm5
  hkVector4f *m_goalPositions; // rbx
  __m128 v66; // xmm1
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm2
  hkVector4f posOut; // [rsp+28h] [rbp-69h] BYREF
  hkVector4f endCenter; // [rsp+38h] [rbp-59h] BYREF
  hkVector4f endPosition; // [rsp+48h] [rbp-49h] BYREF
  hkVector4f startCenter; // [rsp+58h] [rbp-39h] BYREF
  float costOut; // [rsp+F8h] [rbp+67h] BYREF
  int goalIndexOut; // [rsp+100h] [rbp+6Fh] BYREF

  hkaiHierarchicalGraphHeuristic::getNodePosition(this, nodeKey, (hkVector4f *)&endCenter.m_quad.m128_u16[4]);
  if ( !this->m_clusterGraph || this->m_originalStartCluster == -1 || !this->m_hasValidGoalCluster )
  {
    m_numGoals = this->m_numGoals;
    v64 = (__m128)xmmword_141A712A0;
    if ( m_numGoals > 0 )
    {
      m_goalPositions = this->m_goalPositions;
      do
      {
        ++m_goalPositions;
        v66 = _mm_sub_ps(posOut.m_quad, m_goalPositions[-1].m_quad);
        v67 = _mm_mul_ps(v66, v66);
        v68 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                _mm_shuffle_ps(v67, v67, 170));
        v69 = _mm_rsqrt_ps(v68);
        v64 = _mm_min_ps(
                v64,
                _mm_andnot_ps(
                  _mm_cmple_ps(v68, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v69), v69)),
                      _mm_mul_ps(*(__m128 *)_xmm, v69)),
                    v68)));
        --m_numGoals;
      }
      while ( m_numGoals );
    }
    return v64.m128_f32[0];
  }
  ClusterForNode = hkaiHierarchicalGraphHeuristic::getClusterForNode(this, nodeKey);
  v5 = 0;
  v6 = ClusterForNode;
  v7 = this->m_numGoals;
  v8 = (__m128)xmmword_141A712A0;
  m_quad = posOut.m_quad;
  v10 = (__m128)xmmword_141A712A0;
  if ( v7 > 0 )
  {
    v11 = this->m_goalPositions;
    m_endClusterKeys = this->m_endClusterKeys;
    v13 = this->m_numGoals;
    do
    {
      if ( *m_endClusterKeys == v6 )
      {
        v5 = 1;
        v14 = _mm_sub_ps(posOut.m_quad, v11->m_quad);
        v15 = _mm_mul_ps(v14, v14);
        v16 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170));
        v17 = _mm_rsqrt_ps(v16);
        v10 = _mm_min_ps(
                v10,
                _mm_andnot_ps(
                  _mm_cmple_ps(v16, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v17), v17)),
                      _mm_mul_ps(*(__m128 *)_xmm, v17)),
                    v16)));
      }
      ++m_endClusterKeys;
      ++v11;
      --v13;
    }
    while ( v13 );
    if ( v5 )
      return v10.m128_f32[0];
  }
  if ( v6 == -1 )
  {
    if ( v7 > 0 )
    {
      v19 = this->m_goalPositions;
      do
      {
        ++v19;
        v20 = _mm_sub_ps(posOut.m_quad, v19[-1].m_quad);
        v21 = _mm_mul_ps(v20, v20);
        v22 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170));
        v23 = _mm_rsqrt_ps(v22);
        v8 = _mm_min_ps(
               v8,
               _mm_andnot_ps(
                 _mm_cmple_ps(v22, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v23), v23)),
                     _mm_mul_ps(v23, *(__m128 *)_xmm)),
                   v22)));
        --v7;
      }
      while ( v7 );
    }
    return v8.m128_f32[0];
  }
  goalIndexOut = -1;
  if ( hkaiHierarchicalGraphHeuristic::isFaceChunkAdjacentToGoalChunk(this, v6, &goalIndexOut, &costOut) )
  {
    hkaiHierarchicalGraphHeuristic::getClusterPosition(this, v6, &startCenter);
    posOut.m_quad.m128_f32[2] = costOut;
    endPosition.m_quad = (__m128)this->m_goalPositions[goalIndexOut];
    endCenter.m_quad = (__m128)this->m_endClusterPositions[goalIndexOut];
    hkaiHierarchicalGraphHeuristic::adjacentDistance(
      this,
      (hkSimdFloat32 *)&startCenter,
      &posOut,
      &startCenter,
      &endPosition,
      &endCenter,
      costOut);
    return startCenter.m_quad.m128_f32[0];
  }
  v24 = 0;
  NodeState = 0i64;
  if ( this->m_coarseSearch.m_state.m_nodeSize < this->m_coarseSearch.m_state.m_nodeCapacity )
    NodeState = hkaiHashSearchState::getNodeState(&this->m_coarseSearch.m_state, v6);
  v26 = 0;
  if ( !NodeState )
    goto LABEL_56;
  if ( (NodeState->m_flags.m_storage & 2) != 0 )
  {
LABEL_32:
    goalIndexOut = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, v6);
    v35 = goalIndexOut;
    Parent = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, goalIndexOut);
    if ( this->m_numGoals == 1 )
    {
      v35 = this->m_endClusterKeys[0];
      v37 = 0;
    }
    else
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v42 < Value[3] )
      {
        *v42 = "Ttwalk";
        v43 = __rdtsc();
        v44 = v42 + 2;
        *((_DWORD *)v44 - 2) = v43;
        Value[1] = v44;
      }
      v45 = Parent == -1;
      if ( Parent != -1 )
      {
        do
        {
          if ( (hkaiHashSearchState::getNodeStateRO(&this->m_coarseSearch.m_state, Parent)->m_flags.m_storage & 4) != 0 )
            break;
          v35 = Parent;
          Parent = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, Parent);
        }
        while ( Parent != -1 );
        v45 = Parent == -1;
      }
      v46 = this->m_numGoals;
      if ( v45 )
        Parent = v35;
      v47 = 0i64;
      if ( v46 <= 0 )
      {
LABEL_51:
        v37 = -1;
      }
      else
      {
        v48 = this->m_endClusterKeys;
        while ( *v48 != Parent )
        {
          ++v47;
          ++v24;
          ++v48;
          if ( v47 >= v46 )
            goto LABEL_51;
        }
        v37 = v24;
      }
      v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v50 = (_QWORD *)v49[1];
      if ( (unsigned __int64)v50 < v49[3] )
      {
        *v50 = "Et";
        v51 = __rdtsc();
        v52 = v50 + 2;
        *((_DWORD *)v52 - 2) = v51;
        v49[1] = v52;
      }
    }
    v53 = goalIndexOut;
    goalIndexOut = hkaiDirectedGraphEuclideanSearch::getCost(&this->m_coarseSearch, goalIndexOut);
    v54 = (__m128)(unsigned int)goalIndexOut;
    hkaiHierarchicalGraphHeuristic::getClusterPosition(this, v53, &startCenter);
    hkaiHierarchicalGraphHeuristic::getClusterPosition(this, v35, &endPosition);
    v55 = _mm_sub_ps(m_quad, startCenter.m_quad);
    v56 = _mm_mul_ps(v55, v55);
    v57 = _mm_sub_ps(endPosition.m_quad, this->m_goalPositions[v37].m_quad);
    v58 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
            _mm_shuffle_ps(v56, v56, 170));
    v59 = _mm_mul_ps(v57, v57);
    v60 = _mm_rsqrt_ps(v58);
    v61 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
            _mm_shuffle_ps(v59, v59, 170));
    v62 = _mm_rsqrt_ps(v61);
    return (float)(_mm_andnot_ps(
                     _mm_cmple_ps(v58, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v58), v60)),
                         _mm_mul_ps(v60, *(__m128 *)_xmm)),
                       v58)).m128_f32[0]
                 + _mm_shuffle_ps(v54, v54, 0).m128_f32[0])
         + _mm_andnot_ps(
             _mm_cmple_ps(v61, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v62, v61), v62)),
                 _mm_mul_ps(v62, *(__m128 *)_xmm)),
               v61)).m128_f32[0];
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "TtAbstractSearch";
    v29 = __rdtsc();
    v30 = v28 + 2;
    *((_DWORD *)v30 - 2) = v29;
    v27[1] = v30;
  }
  if ( (NodeState->m_flags.m_storage & 2) != 0 )
  {
LABEL_29:
    v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v32 = (_QWORD *)v31[1];
    if ( (unsigned __int64)v32 < v31[3] )
    {
      *v32 = "Et";
      v33 = __rdtsc();
      v34 = v32 + 2;
      *((_DWORD *)v34 - 2) = v33;
      v31[1] = v34;
    }
    if ( !v26 )
      goto LABEL_32;
LABEL_56:
    hkaiHierarchicalGraphHeuristic::getMinDistanceToGoals(this, (hkSimdFloat32 *)&startCenter, &posOut);
    return startCenter.m_quad.m128_f32[0];
  }
  while ( this->m_coarseSearch.m_openSet.m_heapSize )
  {
    if ( this->m_coarseSearch.m_openSet.m_heapSize >= this->m_coarseSearch.m_openSet.m_maxSize
      || this->m_coarseSearch.m_state.m_nodeSize >= this->m_coarseSearch.m_state.m_nodeCapacity )
    {
      v26 = 1;
      goto LABEL_29;
    }
    hkaiDirectedGraphEuclideanSearch::iteration(&this->m_coarseSearch);
    if ( (NodeState->m_flags.m_storage & 2) != 0 )
      goto LABEL_29;
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = v38[1];
  if ( v39 < v38[3] )
  {
    *(_QWORD *)v39 = "Et";
    v40 = __rdtsc();
    *(_DWORD *)(v39 + 8) = v40;
    v38[1] = v39 + 16;
  }
  return FLOAT_3_40282e38;
}

// File Line: 354
// RVA: 0xC25C70
hkSimdFloat32 *__fastcall hkaiHierarchicalGraphHeuristic::adjacentDistance(
        hkaiHierarchicalGraphHeuristic *this,
        hkSimdFloat32 *result,
        hkVector4f *startPosition,
        hkVector4f *startCenter,
        hkVector4f *endPosition,
        hkVector4f *endCenter)
{
  __m128 v6; // xmm9
  __m128 v7; // xmm1
  __m128 v8; // xmm9
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm10
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  hkSimdFloat32 *v20; // rax

  v6 = _mm_sub_ps(startPosition->m_quad, endCenter->m_quad);
  v7 = _mm_sub_ps(startPosition->m_quad, endPosition->m_quad);
  v8 = _mm_mul_ps(v6, v6);
  v9 = _mm_mul_ps(v7, v7);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_andnot_ps(
          _mm_cmple_ps(v10, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v11), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11)),
            v10));
  v13 = _mm_sub_ps(endCenter->m_quad, endPosition->m_quad);
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_andnot_ps(
          _mm_cmple_ps(v15, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v16), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)),
            v15));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = result;
  result->m_real = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v18, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v19), v19)),
                               _mm_mul_ps(*(__m128 *)_xmm, v19)),
                             v18)),
                         v17),
                       v12),
                     (__m128)xmmword_141A711B0);
  return v20;
}

// File Line: 407
// RVA: 0xC25800
__int64 __fastcall hkaiHierarchicalGraphHeuristic::isFaceChunkAdjacentToGoalChunk(
        hkaiHierarchicalGraphHeuristic *this,
        unsigned int faceIndex,
        int *goalIndexOut,
        float *costOut)
{
  hkaiDirectedGraphVisitor *m_clusterGraph; // r11
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // r10
  __int64 v7; // rcx
  __m128 *m_incomingGraph; // rdx
  __int64 v12; // r8
  __int64 v13; // rcx
  unsigned __int64 v14; // rax
  __int64 v15; // r8
  int v16; // ecx
  __m128 *v17; // r10
  int m_numEdges; // r9d
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v24; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v25; // rsi
  int v26; // edi
  int v27; // r9d
  int v28; // eax
  __int64 v29; // rdx
  unsigned int *p_m_target; // rcx
  int v31; // r15d
  hkLifoAllocator *Value; // rax
  int *m_cur; // rdi
  int v34; // edx
  char *v35; // rcx
  hkaiDirectedGraphVisitor *v36; // rsi
  signed int v37; // edx
  int v38; // r8d
  int v39; // r9d
  unsigned int m_startEdgeIndex; // r11d
  int v41; // r14d
  int *v42; // rcx
  __m128i si128; // xmm2
  __m128i v44; // xmm1
  __m128i v45; // xmm0
  unsigned int v46; // eax
  unsigned int v47; // r10d
  signed int v48; // edx
  __m128i v49; // xmm2
  __m128i v50; // xmm1
  __m128i v51; // xmm0
  unsigned int v52; // eax
  int *v53; // r9
  int *v54; // r11
  hkaiDirectedGraphVisitor *v55; // rcx
  int v56; // esi
  hkaiStreamingCollection::InstanceInfo *v57; // r8
  __int64 v58; // rax
  __int64 v59; // rdx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  __int64 m_numGoals; // r8
  int v62; // edx
  unsigned int m_target; // r10d
  __int64 v64; // rcx
  unsigned int *m_endClusterKeys; // rax
  unsigned __int8 v66; // si
  signed int v67; // ebx
  hkLifoAllocator *v68; // rax
  int v69; // r8d
  float TotalCost; // xmm0_4

  m_clusterGraph = this->m_clusterGraph;
  m_streamingInfo = m_clusterGraph->m_streamingInfo;
  v7 = faceIndex >> 22;
  m_clusterGraph->m_cachedNodeKey = faceIndex;
  if ( m_streamingInfo && m_clusterGraph->m_cachedIncomingSectionId != (_DWORD)v7 )
    m_clusterGraph->m_incomingGraph = m_streamingInfo[v7].m_clusterGraphInstance;
  m_incomingGraph = (__m128 *)m_clusterGraph->m_incomingGraph;
  m_clusterGraph->m_cachedIncomingSectionId = v7;
  v12 = faceIndex & 0x3FFFFF;
  m_clusterGraph->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(m_incomingGraph[1].m128_u64[0] + 8 * v12);
  if ( !m_incomingGraph[7].m128_i32[0] || (v13 = *(int *)(m_incomingGraph[6].m128_u64[1] + 4 * v12), (_DWORD)v13 == -1) )
  {
    m_clusterGraph->m_cachedInstanceNode.m_startEdgeIndex = -1;
    m_clusterGraph->m_cachedInstanceNode.m_numEdges = 0;
  }
  else
  {
    m_clusterGraph->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(m_incomingGraph[7].m128_u64[1]
                                                                                  + 8 * v13);
  }
  v14 = m_incomingGraph[3].m128_u64[0];
  v15 = 2 * v12;
  v16 = 24;
  v17 = m_incomingGraph;
  m_numEdges = 24;
  v19 = *(__m128 *)(v14 + 8 * v15);
  if ( m_clusterGraph->m_cachedNode.m_numEdges < 24 )
    m_numEdges = m_clusterGraph->m_cachedNode.m_numEdges;
  v20 = _mm_shuffle_ps(*(__m128 *)(v14 + 8 * v15), v19, 85);
  v21 = _mm_shuffle_ps(*(__m128 *)(v14 + 8 * v15), v19, 0);
  v22 = _mm_shuffle_ps(v19, v19, 170);
  if ( m_clusterGraph->m_cachedInstanceNode.m_numEdges < 24 )
    v16 = m_clusterGraph->m_cachedInstanceNode.m_numEdges;
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v20, m_incomingGraph[14]), _mm_mul_ps(v21, m_incomingGraph[13])),
            _mm_mul_ps(v22, m_incomingGraph[15])),
          m_incomingGraph[16]);
  m_clusterGraph->m_cachedNode.m_numEdges = m_numEdges;
  m_clusterGraph->m_cachedInstanceNode.m_numEdges = v16;
  m_clusterGraph->m_cachedPosition.m_quad = v23;
  v24 = (hkaiDirectedGraphExplicitCost::Edge *)m_incomingGraph[2].m128_u64[0];
  v25 = (hkaiDirectedGraphExplicitCost::Edge *)v17[8].m128_u64[1];
  v26 = v17[5].m128_i32[2];
  if ( v24 )
    copyEdges_2(m_clusterGraph->m_localEdges, v24, m_clusterGraph->m_cachedNode.m_startEdgeIndex, m_numEdges);
  if ( v25 )
  {
    v27 = m_clusterGraph->m_cachedInstanceNode.m_numEdges;
    if ( v27 > 0 )
      copyEdges_2(
        &m_clusterGraph->m_localEdges[m_clusterGraph->m_cachedNode.m_numEdges],
        v25,
        m_clusterGraph->m_cachedInstanceNode.m_startEdgeIndex - m_clusterGraph->m_incomingGraph->m_numOriginalEdges,
        v27);
  }
  m_clusterGraph->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&m_clusterGraph->m_numGoals;
  v28 = m_clusterGraph->m_cachedNode.m_numEdges + m_clusterGraph->m_cachedInstanceNode.m_numEdges;
  v29 = v28;
  if ( v28 > 0 )
  {
    p_m_target = &m_clusterGraph->m_localEdges[0].m_target;
    do
    {
      if ( (*((_BYTE *)p_m_target - 2) & 0x40) == 0 )
      {
        *p_m_target &= 0x3FFFFFu;
        *p_m_target |= v26 << 22;
      }
      p_m_target += 2;
      --v29;
    }
    while ( v29 );
  }
  v31 = this->m_clusterGraph->m_cachedNode.m_numEdges + this->m_clusterGraph->m_cachedInstanceNode.m_numEdges;
  if ( v31 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (int *)Value->m_cur;
    v34 = (4 * v31 + 127) & 0xFFFFFF80;
    v35 = (char *)m_cur + v34;
    if ( v34 > Value->m_slabSize || v35 > Value->m_end )
      m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v34);
    else
      Value->m_cur = v35;
  }
  else
  {
    m_cur = 0i64;
  }
  v36 = this->m_clusterGraph;
  v37 = 0;
  v38 = v36->m_cachedNode.m_numEdges;
  v39 = v36->m_cachedInstanceNode.m_numEdges;
  m_startEdgeIndex = v36->m_cachedNode.m_startEdgeIndex;
  v41 = v39 + v38;
  v42 = m_cur;
  if ( v38 > 0 )
  {
    if ( (unsigned int)v38 >= 4 )
    {
      si128 = _mm_load_si128((const __m128i *)&_xmm);
      v44 = _mm_shuffle_epi32(_mm_cvtsi32_si128(m_startEdgeIndex), 0);
      do
      {
        v45 = _mm_cvtsi32_si128(v37);
        v37 += 4;
        v42 += 4;
        *((__m128i *)v42 - 1) = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v45, 0), si128), v44);
      }
      while ( v37 < (int)(v38 - (v38 & 0x80000003)) );
    }
    for ( ; v37 < v38; *(v42 - 1) = v46 )
    {
      v46 = v37 + m_startEdgeIndex;
      ++v37;
      ++v42;
    }
  }
  v47 = v36->m_cachedInstanceNode.m_startEdgeIndex;
  v48 = 0;
  if ( v39 > 0 )
  {
    if ( (unsigned int)v39 >= 4 )
    {
      v49 = _mm_load_si128((const __m128i *)&_xmm);
      v50 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v47), 0);
      do
      {
        v51 = _mm_cvtsi32_si128(v48);
        v48 += 4;
        v42 += 4;
        *((__m128i *)v42 - 1) = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v51, 0), v49), v50);
      }
      while ( v48 < (int)(v39 - (v39 & 0x80000003)) );
    }
    for ( ; v48 < v39; *(v42 - 1) = v52 )
    {
      v52 = v48 + v47;
      ++v48;
      ++v42;
    }
  }
  v53 = m_cur;
  v54 = &m_cur[v41];
  if ( m_cur >= v54 )
  {
LABEL_51:
    v66 = 0;
    goto LABEL_52;
  }
  while ( 1 )
  {
    v55 = this->m_clusterGraph;
    v56 = *v53;
    v57 = v55->m_streamingInfo;
    v58 = (__int64)&v55->m_currentEdge[1];
    v55->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)v58;
    v59 = *(_DWORD *)(v58 + 4) >> 22;
    if ( v57 )
    {
      if ( v55->m_cachedOutgoingSectionId == (_DWORD)v59 )
        goto LABEL_46;
      m_clusterGraphInstance = v57[v59].m_clusterGraphInstance;
    }
    else
    {
      m_clusterGraphInstance = v55->m_incomingGraph;
    }
    v55->m_outgoingGraph = m_clusterGraphInstance;
LABEL_46:
    v55->m_cachedOutgoingSectionId = v59;
    m_numGoals = this->m_numGoals;
    v62 = 0;
    m_target = this->m_clusterGraph->m_currentEdge->m_target;
    v64 = 0i64;
    if ( m_numGoals > 0 )
      break;
LABEL_50:
    if ( ++v53 >= v54 )
      goto LABEL_51;
  }
  m_endClusterKeys = this->m_endClusterKeys;
  while ( m_target != *m_endClusterKeys )
  {
    ++v64;
    ++v62;
    ++m_endClusterKeys;
    if ( v64 >= m_numGoals )
      goto LABEL_50;
  }
  *goalIndexOut = v62;
  TotalCost = hkaiDirectedGraphVisitor::getTotalCost(this->m_clusterGraph, faceIndex, m_target, v56);
  v66 = 1;
  *costOut = TotalCost;
LABEL_52:
  v67 = (4 * v31 + 127) & 0xFFFFFF80;
  v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v69 = (v67 + 15) & 0xFFFFFFF0;
  if ( v67 > v68->m_slabSize || (char *)m_cur + v69 != v68->m_cur || v68->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v68, m_cur, v69);
  else
    v68->m_cur = m_cur;
  return v66;
}

// File Line: 441
// RVA: 0xC256D0
void __fastcall hkaiHierarchicalGraphHeuristic::getNodePosition(
        hkaiHierarchicalGraphHeuristic *this,
        unsigned int nodeKey,
        hkVector4f *posOut)
{
  hkaiDirectedGraphVisitor *m_originalGraph; // r9
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // r11
  __int64 v5; // r10
  hkaiDirectedGraphInstance *m_incomingGraph; // rax
  hkaiDirectedGraphVisitor *v7; // rax
  __m128 *m_outgoingGraph; // rdx
  __m128 v10; // xmm1

  m_originalGraph = this->m_originalGraph;
  m_streamingInfo = this->m_originalGraph->m_streamingInfo;
  v5 = nodeKey >> 22;
  if ( !m_streamingInfo )
  {
    m_incomingGraph = m_originalGraph->m_incomingGraph;
    goto LABEL_5;
  }
  if ( m_originalGraph->m_cachedOutgoingSectionId != (_DWORD)v5 )
  {
    m_incomingGraph = m_streamingInfo[v5].m_clusterGraphInstance;
LABEL_5:
    m_originalGraph->m_outgoingGraph = m_incomingGraph;
  }
  m_originalGraph->m_cachedOutgoingSectionId = v5;
  v7 = this->m_originalGraph;
  m_outgoingGraph = (__m128 *)v7->m_outgoingGraph;
  v10 = *(__m128 *)(m_outgoingGraph[3].m128_u64[0] + 16i64 * (nodeKey & 0x3FFFFF));
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), m_outgoingGraph[14]),
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), m_outgoingGraph[13])),
                       _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), m_outgoingGraph[15])),
                     m_outgoingGraph[16]);
}

