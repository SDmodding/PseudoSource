// File Line: 23
// RVA: 0xC1FDE0
void __fastcall hkaiHierarchicalNavMeshHeuristic::init(
        hkaiHierarchicalNavMeshHeuristic *this,
        hkaiNavMeshSectionGraph *originalGraph,
        hkaiDirectedGraphVisitor *clusterGraph,
        unsigned int originalStartFaceKey,
        hkVector4f *startPosition,
        unsigned int originalEnd,
        hkVector4f *goalPosition)
{
  hkaiHierarchicalNavMeshHeuristic::init(
    this,
    originalGraph,
    clusterGraph,
    originalStartFaceKey,
    startPosition,
    &originalEnd,
    goalPosition,
    1);
}

// File Line: 28
// RVA: 0xC1FE20
void __fastcall hkaiHierarchicalNavMeshHeuristic::init(
        hkaiHierarchicalNavMeshHeuristic *this,
        hkaiNavMeshSectionGraph *originalGraph,
        hkaiDirectedGraphVisitor *clusterGraph,
        unsigned int originalStartFaceKey,
        hkVector4f *startPosition,
        unsigned int *originalGoalFaceKeys,
        hkVector4f *goalPositions,
        int numGoals)
{
  hkaiStreamingCollection::InstanceInfo *m_streamingInfo; // rax
  unsigned int *v9; // rsi
  int v11; // ecx
  __m128 m_quad; // xmm0
  int v14; // edi
  int v15; // ebp
  unsigned int ClusterForFace; // eax
  bool v17; // zf
  bool v18; // al
  unsigned int end; // eax
  unsigned int *m_endClusterKeys; // rsi

  m_streamingInfo = originalGraph->m_streamingInfo;
  v9 = originalGoalFaceKeys;
  this->m_streamingInfo = originalGraph->m_streamingInfo;
  this->m_accessor.m_sectionInfo = m_streamingInfo;
  v11 = 16;
  this->m_originalGraph = originalGraph;
  this->m_clusterGraph = clusterGraph;
  this->m_startFaceKey = originalStartFaceKey;
  if ( numGoals < 16 )
    v11 = numGoals;
  this->m_numGoals = v11;
  m_quad = startPosition->m_quad;
  this->m_goalFaceKeys = originalGoalFaceKeys;
  this->m_startPosition.m_quad = m_quad;
  this->m_hasValidGoalCluster = 0;
  this->m_goalPositions = goalPositions;
  if ( clusterGraph )
  {
    v14 = 0;
    v15 = 0;
    if ( v11 > 0 )
    {
      do
      {
        ClusterForFace = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(this, *v9);
        *(unsigned int *)((char *)v9 + (char *)this - (char *)originalGoalFaceKeys + 36) = ClusterForFace;
        if ( this->m_hasValidGoalCluster || (v17 = ClusterForFace == -1, v18 = 0, !v17) )
          v18 = 1;
        ++v15;
        this->m_hasValidGoalCluster = v18;
        ++v9;
      }
      while ( v15 < this->m_numGoals );
    }
    end = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(this, originalStartFaceKey);
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
          hkaiHierarchicalNavMeshHeuristic::getClusterPosition(
            this,
            *m_endClusterKeys,
            &this->m_endClusterPositions[v14]);
        ++v14;
        ++m_endClusterKeys;
      }
      while ( v14 < this->m_numGoals );
    }
  }
}

// File Line: 95
// RVA: 0xC20710
void __fastcall hkaiHierarchicalNavMeshHeuristic::getClusterPosition(
        hkaiHierarchicalNavMeshHeuristic *this,
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

// File Line: 109
// RVA: 0xC1FF70
float __fastcall hkaiHierarchicalNavMeshHeuristic::getHeuristic(
        hkaiHierarchicalNavMeshHeuristic *this,
        unsigned int edgeId)
{
  __m128 m_quad; // xmm6
  unsigned int m_startFaceKey; // edx
  hkaiNavMeshSectionGraph *m_originalGraph; // rcx
  bool v6; // zf
  int m_clusterIndex; // ecx
  int v8; // edi
  int ClusterForFace; // eax
  __int64 v10; // r8
  char v11; // r10
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  int v14; // r14d
  unsigned int v15; // r15d
  __int64 v16; // rdx
  unsigned int *m_endClusterKeys; // rcx
  __int64 v18; // r9
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  hkaiSearchStateNode *NodeState; // rdi
  int v25; // r12d
  _QWORD *Value; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rcx
  unsigned __int64 v32; // rax
  unsigned int Parent; // r13d
  unsigned int v34; // r15d
  __m128 v35; // xmm7
  unsigned int i; // edi
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __int64 v41; // rdx
  __int64 v42; // rcx
  unsigned int *v43; // rax
  int v44; // edi
  float v45; // xmm9_4
  __m128 v46; // xmm6
  __m128 v47; // xmm6
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm8
  __m128 v51; // xmm4
  __m128 v52; // xmm7
  __m128 v53; // xmm3
  _QWORD *v54; // r8
  unsigned __int64 v55; // rcx
  unsigned __int64 v56; // rax
  hkVector4f *v57; // rax
  __m128 v58; // xmm1
  __m128 v59; // xmm1
  __m128 v60; // xmm4
  __m128 v61; // xmm2
  __int64 m_numGoals; // rcx
  __m128 v63; // xmm5
  hkVector4f *m_goalPositions; // rax
  __m128 v65; // xmm1
  __m128 v66; // xmm1
  __m128 v67; // xmm4
  __m128 v68; // xmm2
  hkVector4f eb; // [rsp+40h] [rbp-69h] BYREF
  hkVector4f ea; // [rsp+50h] [rbp-59h] BYREF
  hkVector4f endPosition; // [rsp+60h] [rbp-49h] BYREF
  hkVector4f posOut; // [rsp+70h] [rbp-39h] BYREF
  float costOut; // [rsp+110h] [rbp+67h] BYREF
  int goalIndexOut; // [rsp+118h] [rbp+6Fh] BYREF

  if ( (edgeId & 0xFFC00000) == -8388608 )
  {
    m_quad = this->m_startPosition.m_quad;
    m_startFaceKey = this->m_startFaceKey;
  }
  else
  {
    m_originalGraph = this->m_originalGraph;
    if ( (m_originalGraph->m_cachedOutgoingEdge.m_flags.m_storage & 0x10) != 0 )
    {
      hkaiStreamingCollection::getEdgePoints(
        m_originalGraph->m_streamingInfo,
        m_originalGraph->m_cachedOutgoingEdge.m_oppositeEdge,
        &ea,
        &eb);
      m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(eb.m_quad, ea.m_quad), (__m128)xmmword_141A711B0), ea.m_quad);
    }
    else
    {
      m_quad = m_originalGraph->m_cachedOutgoingEdgeMidpoint.m_quad;
    }
    m_startFaceKey = this->m_originalGraph->m_cachedOutgoingEdge.m_oppositeFace;
  }
  v6 = this->m_clusterGraph == 0i64;
  eb.m_quad = m_quad;
  if ( v6 || this->m_originalStartCluster == -1 || !this->m_hasValidGoalCluster )
  {
    m_numGoals = this->m_numGoals;
    v63 = (__m128)xmmword_141A712A0;
    if ( m_numGoals > 0 )
    {
      m_goalPositions = this->m_goalPositions;
      do
      {
        ++m_goalPositions;
        v65 = _mm_sub_ps(m_quad, m_goalPositions[-1].m_quad);
        v66 = _mm_mul_ps(v65, v65);
        v67 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                _mm_shuffle_ps(v66, v66, 170));
        v68 = _mm_rsqrt_ps(v67);
        v63 = _mm_min_ps(
                v63,
                _mm_andnot_ps(
                  _mm_cmple_ps(v67, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v67, v68), v68)),
                      _mm_mul_ps(*(__m128 *)_xmm, v68)),
                    v67)));
        --m_numGoals;
      }
      while ( m_numGoals );
    }
    return v63.m128_f32[0];
  }
  m_clusterIndex = this->m_originalGraph->m_cachedFace.m_clusterIndex;
  if ( m_clusterIndex == -1 )
    v8 = -1;
  else
    v8 = m_clusterIndex | (this->m_originalGraph->m_cachedOutgoingSectionId << 22);
  ClusterForFace = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(this, m_startFaceKey);
  v10 = this->m_numGoals;
  v11 = 0;
  v12 = (__m128)xmmword_141A712A0;
  v13 = (__m128)xmmword_141A712A0;
  v14 = 0;
  v15 = ClusterForFace;
  if ( v10 > 0 )
  {
    v16 = 0i64;
    m_endClusterKeys = this->m_endClusterKeys;
    v18 = this->m_numGoals;
    do
    {
      if ( *m_endClusterKeys == ClusterForFace || *m_endClusterKeys == v8 )
      {
        v11 = 1;
        v19 = _mm_sub_ps(m_quad, this->m_goalPositions[v16].m_quad);
        v20 = _mm_mul_ps(v19, v19);
        v21 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170));
        v22 = _mm_rsqrt_ps(v21);
        v13 = _mm_min_ps(
                v13,
                _mm_andnot_ps(
                  _mm_cmple_ps(v21, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22)),
                    v21)));
      }
      ++m_endClusterKeys;
      ++v16;
      --v18;
    }
    while ( v18 );
    if ( v11 )
      return v13.m128_f32[0];
  }
  if ( ClusterForFace == -1 || v8 == -1 )
  {
    if ( v10 > 0 )
    {
      v57 = this->m_goalPositions;
      do
      {
        ++v57;
        v58 = _mm_sub_ps(m_quad, v57[-1].m_quad);
        v59 = _mm_mul_ps(v58, v58);
        v60 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                _mm_shuffle_ps(v59, v59, 170));
        v61 = _mm_rsqrt_ps(v60);
        v12 = _mm_min_ps(
                v12,
                _mm_andnot_ps(
                  _mm_cmple_ps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v61), v61)),
                      _mm_mul_ps(*(__m128 *)_xmm, v61)),
                    v60)));
        --v10;
      }
      while ( v10 );
    }
    return v12.m128_f32[0];
  }
  goalIndexOut = -1;
  if ( hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(this, ClusterForFace, &goalIndexOut, &costOut) )
  {
    v8 = v15;
LABEL_27:
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(this, v8, &posOut);
    endPosition.m_quad = (__m128)this->m_goalPositions[goalIndexOut];
    ea.m_quad = (__m128)this->m_endClusterPositions[goalIndexOut];
    hkaiHierarchicalNavMeshHeuristic::adjacentDistance(
      this,
      (hkSimdFloat32 *)&posOut,
      &eb,
      &posOut,
      &endPosition,
      &ea,
      costOut);
    return posOut.m_quad.m128_f32[0];
  }
  if ( v15 != v8 && hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(this, v8, &goalIndexOut, &costOut) )
    goto LABEL_27;
  NodeState = 0i64;
  if ( this->m_coarseSearch.m_state.m_nodeSize < this->m_coarseSearch.m_state.m_nodeCapacity )
    NodeState = hkaiHashSearchState::getNodeState(&this->m_coarseSearch.m_state, v15);
  v25 = 0;
  if ( !NodeState )
    goto LABEL_58;
  if ( (NodeState->m_flags.m_storage & 2) != 0 )
  {
LABEL_42:
    Parent = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, v15);
    v34 = Parent;
    v35 = 0i64;
    for ( i = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, Parent);
          i != -1;
          i = hkaiDirectedGraphEuclideanSearch::getParent(&this->m_coarseSearch, i) )
    {
      if ( (hkaiHashSearchState::getNodeStateRO(&this->m_coarseSearch.m_state, i)->m_flags.m_storage & 4) != 0 )
        break;
      hkaiHierarchicalNavMeshHeuristic::getClusterPosition(this, v34, &posOut);
      hkaiHierarchicalNavMeshHeuristic::getClusterPosition(this, i, &endPosition);
      v34 = i;
      v37 = _mm_sub_ps(posOut.m_quad, endPosition.m_quad);
      v38 = _mm_mul_ps(v37, v37);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_rsqrt_ps(v39);
      v35 = _mm_add_ps(
              v35,
              _mm_andnot_ps(
                _mm_cmple_ps(v39, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v40), v40)),
                    _mm_mul_ps(*(__m128 *)_xmm, v40)),
                  v39)));
    }
    v41 = this->m_numGoals;
    v42 = 0i64;
    if ( i == -1 )
      i = v34;
    if ( v41 <= 0 )
    {
LABEL_51:
      v44 = -1;
    }
    else
    {
      v43 = this->m_endClusterKeys;
      while ( *v43 != i )
      {
        ++v42;
        ++v14;
        ++v43;
        if ( v42 >= v41 )
          goto LABEL_51;
      }
      v44 = v14;
    }
    goalIndexOut = hkaiDirectedGraphEuclideanSearch::getCost(&this->m_coarseSearch, Parent);
    v45 = (float)((float)(_mm_shuffle_ps((__m128)(unsigned int)goalIndexOut, (__m128)(unsigned int)goalIndexOut, 0).m128_f32[0]
                        * 3.0)
                + v35.m128_f32[0])
        * 0.25;
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(this, Parent, &posOut);
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(this, v34, &endPosition);
    v46 = _mm_sub_ps(m_quad, posOut.m_quad);
    v47 = _mm_mul_ps(v46, v46);
    v48 = _mm_sub_ps(endPosition.m_quad, this->m_goalPositions[v44].m_quad);
    v49 = _mm_mul_ps(v48, v48);
    v50 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
            _mm_shuffle_ps(v47, v47, 170));
    v51 = _mm_rsqrt_ps(v50);
    v52 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
            _mm_shuffle_ps(v49, v49, 170));
    v53 = _mm_rsqrt_ps(v52);
    return (float)(_mm_andnot_ps(
                     _mm_cmple_ps(v50, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v51), v51)),
                         _mm_mul_ps(v51, *(__m128 *)_xmm)),
                       v50)).m128_f32[0]
                 + v45)
         + _mm_andnot_ps(
             _mm_cmple_ps(v52, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v53), v53)),
                 _mm_mul_ps(v53, *(__m128 *)_xmm)),
               v52)).m128_f32[0];
  }
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v27 < Value[3] )
  {
    *v27 = "TtAbstractSearch";
    v28 = __rdtsc();
    v29 = v27 + 2;
    *((_DWORD *)v29 - 2) = v28;
    Value[1] = v29;
  }
  if ( (NodeState->m_flags.m_storage & 2) != 0 )
  {
LABEL_39:
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = v30[1];
    if ( v31 < v30[3] )
    {
      *(_QWORD *)v31 = "Et";
      v32 = __rdtsc();
      *(_DWORD *)(v31 + 8) = v32;
      v30[1] = v31 + 16;
    }
    if ( !v25 )
      goto LABEL_42;
LABEL_58:
    hkaiHierarchicalNavMeshHeuristic::getMinDistanceToGoals(this, (hkSimdFloat32 *)&posOut, &eb);
    return posOut.m_quad.m128_f32[0];
  }
  while ( this->m_coarseSearch.m_openSet.m_heapSize )
  {
    if ( this->m_coarseSearch.m_openSet.m_heapSize >= this->m_coarseSearch.m_openSet.m_maxSize
      || this->m_coarseSearch.m_state.m_nodeSize >= this->m_coarseSearch.m_state.m_nodeCapacity )
    {
      v25 = 1;
      goto LABEL_39;
    }
    hkaiDirectedGraphEuclideanSearch::iteration(&this->m_coarseSearch);
    if ( (NodeState->m_flags.m_storage & 2) != 0 )
      goto LABEL_39;
  }
  v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v55 = v54[1];
  if ( v55 < v54[3] )
  {
    *(_QWORD *)v55 = "Et";
    v56 = __rdtsc();
    *(_DWORD *)(v55 + 8) = v56;
    v54[1] = v55 + 16;
  }
  return FLOAT_3_40282e38;
}eanSearch::iteration(&this->m_coarseSearch);
    if ( (NodeState->m_flags.m_storage & 2) != 0 )
      goto LABEL_39;
  }
  v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v55 = v54[1];
  if ( v55 < v54[3] )
  {
    *(_QWORD *)v55 = "Et";
    v56 = __rdtsc();
    *(_DWORD *)(v55 + 8) = v56;
    v5

// File Line: 364
// RVA: 0xC20C10
hkSimdFloat32 *__fastcall hkaiHierarchicalNavMeshHeuristic::adjacentDistance(
        hkaiHierarchicalNavMeshHeuristic *this,
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

// File Line: 417
// RVA: 0xC207A0
__int64 __fastcall hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(
        hkaiHierarchicalNavMeshHeuristic *this,
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
    copyEdges_1(m_clusterGraph->m_localEdges, v24, m_clusterGraph->m_cachedNode.m_startEdgeIndex, m_numEdges);
  if ( v25 )
  {
    v27 = m_clusterGraph->m_cachedInstanceNode.m_numEdges;
    if ( v27 > 0 )
      copyEdges_1(
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

