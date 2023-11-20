// File Line: 23
// RVA: 0xC1FDE0
void __fastcall hkaiHierarchicalNavMeshHeuristic::init(hkaiHierarchicalNavMeshHeuristic *this, hkaiNavMeshSectionGraph *originalGraph, hkaiDirectedGraphVisitor *clusterGraph, unsigned int originalStartFaceKey, hkVector4f *startPosition, unsigned int originalEnd, hkVector4f *goalPosition)
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
void __fastcall hkaiHierarchicalNavMeshHeuristic::init(hkaiHierarchicalNavMeshHeuristic *this, hkaiNavMeshSectionGraph *originalGraph, hkaiDirectedGraphVisitor *clusterGraph, unsigned int originalStartFaceKey, hkVector4f *startPosition, const unsigned int *originalGoalFaceKeys, hkVector4f *goalPositions, int numGoals)
{
  hkaiStreamingCollection::InstanceInfo *v8; // rax
  unsigned int *v9; // rsi
  hkaiHierarchicalNavMeshHeuristic *v10; // rbx
  int v11; // ecx
  unsigned int v12; // er15
  __m128 v13; // xmm0
  int v14; // edi
  int v15; // ebp
  unsigned int v16; // eax
  bool v17; // zf
  char v18; // al
  int end; // eax
  unsigned int *v20; // rsi

  v8 = originalGraph->m_streamingInfo;
  v9 = (unsigned int *)originalGoalFaceKeys;
  v10 = this;
  this->m_streamingInfo = originalGraph->m_streamingInfo;
  this->m_accessor.m_sectionInfo = v8;
  v11 = 16;
  v10->m_originalGraph = originalGraph;
  v10->m_clusterGraph = clusterGraph;
  v10->m_startFaceKey = originalStartFaceKey;
  v12 = originalStartFaceKey;
  if ( numGoals < 16 )
    v11 = numGoals;
  v10->m_numGoals = v11;
  v13 = startPosition->m_quad;
  v10->m_goalFaceKeys = originalGoalFaceKeys;
  v10->m_startPosition.m_quad = v13;
  v10->m_hasValidGoalCluster = 0;
  v10->m_goalPositions = goalPositions;
  if ( clusterGraph )
  {
    v14 = 0;
    v15 = 0;
    if ( v11 > 0 )
    {
      do
      {
        v16 = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(v10, *v9);
        *(unsigned int *)((char *)v9 + (char *)v10 - (char *)originalGoalFaceKeys + 36) = v16;
        if ( v10->m_hasValidGoalCluster || (v17 = v16 == -1, v18 = 0, !v17) )
          v18 = 1;
        ++v15;
        v10->m_hasValidGoalCluster = v18;
        ++v9;
      }
      while ( v15 < v10->m_numGoals );
    }
    end = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(v10, v12);
    v10->m_originalStartCluster = end;
    if ( end != -1 && v10->m_hasValidGoalCluster )
      hkaiDirectedGraphEuclideanSearch::init(
        &v10->m_coarseSearch,
        v10->m_clusterGraph,
        v10->m_endClusterKeys,
        v10->m_numGoals,
        end);
    if ( v10->m_numGoals > 0 )
    {
      v20 = v10->m_endClusterKeys;
      do
      {
        if ( *v20 != -1 )
          hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v10, *v20, (hkVector4f *)v10 + v14 + 7i64);
        ++v14;
        ++v20;
      }
      while ( v14 < v10->m_numGoals );
    }
  }
}

// File Line: 95
// RVA: 0xC20710
void __fastcall hkaiHierarchicalNavMeshHeuristic::getClusterPosition(hkaiHierarchicalNavMeshHeuristic *this, unsigned int key, hkVector4f *posOut)
{
  hkaiDirectedGraphVisitor *v3; // r10
  unsigned int v4; // er11
  hkaiHierarchicalNavMeshHeuristic *v5; // rdx
  __int64 v6; // r9
  hkaiDirectedGraphInstance *v7; // rcx
  __m128 *v8; // rdx
  __m128 v9; // xmm1

  v3 = this->m_clusterGraph;
  v4 = key;
  v5 = this;
  v6 = v4 >> 22;
  if ( v3->m_cachedGeneralSectionId != (_DWORD)v6 )
  {
    v7 = v3->m_streamingInfo[v6].m_clusterGraphInstance;
    v3->m_cachedGeneralSectionId = v6;
    v3->m_generalGraph = v7;
  }
  v8 = (__m128 *)v5->m_clusterGraph->m_generalGraph;
  v9 = *(__m128 *)(v8[3].m128_u64[0] + 16i64 * (v4 & 0x3FFFFF));
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v8[14]),
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v8[13])),
                       _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v8[15])),
                     v8[16]);
}

// File Line: 109
// RVA: 0xC1FF70
float __fastcall hkaiHierarchicalNavMeshHeuristic::getHeuristic(hkaiHierarchicalNavMeshHeuristic *this, unsigned int edgeId)
{
  hkaiHierarchicalNavMeshHeuristic *v2; // rbx
  __m128 v3; // xmm6
  unsigned int v4; // edx
  hkaiNavMeshSectionGraph *v5; // rcx
  bool v6; // zf
  int v7; // ecx
  int v8; // edi
  int v9; // eax
  __int64 v10; // r8
  char v11; // r10
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  signed int v14; // er14
  unsigned int v15; // er15
  __int64 v16; // rdx
  unsigned int *v17; // rcx
  __int64 v18; // r9
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  float edgeCost; // ST30_4
  signed __int64 v25; // rax
  hkaiSearchStateNode *v26; // rdi
  signed int v27; // er12
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  _QWORD *v32; // r8
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // rax
  unsigned int v35; // er13
  unsigned int v36; // er15
  __m128 v37; // xmm7
  unsigned int i; // edi
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __int64 v43; // rdx
  __int64 v44; // rcx
  unsigned int *v45; // rax
  signed int v46; // edi
  int v47; // xmm0_4
  float v48; // xmm9_4
  __m128 v49; // xmm6
  __m128 v50; // xmm6
  __m128 v51; // xmm1
  __m128 v52; // xmm1
  __m128 v53; // xmm8
  __m128 v54; // xmm4
  __m128 v55; // xmm7
  __m128 v56; // xmm3
  _QWORD *v57; // r8
  unsigned __int64 v58; // rcx
  unsigned __int64 v59; // rax
  hkVector4f *v60; // rax
  __m128 v61; // xmm1
  __m128 v62; // xmm1
  __m128 v63; // xmm4
  __m128 v64; // xmm2
  __int64 v65; // rcx
  __m128 v66; // xmm5
  hkVector4f *v67; // rax
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  hkVector4f eb; // [rsp+40h] [rbp-69h]
  hkVector4f ea; // [rsp+50h] [rbp-59h]
  hkVector4f endPosition; // [rsp+60h] [rbp-49h]
  hkVector4f posOut; // [rsp+70h] [rbp-39h]
  float costOut; // [rsp+110h] [rbp+67h]
  int goalIndexOut; // [rsp+118h] [rbp+6Fh]

  v2 = this;
  if ( (edgeId & 0xFFC00000) == -8388608 )
  {
    v3 = this->m_startPosition.m_quad;
    v4 = this->m_startFaceKey;
  }
  else
  {
    v5 = this->m_originalGraph;
    if ( v5->m_cachedOutgoingEdge.m_flags.m_storage & 0x10 )
    {
      hkaiStreamingCollection::getEdgePoints(v5->m_streamingInfo, v5->m_cachedOutgoingEdge.m_oppositeEdge, &ea, &eb);
      v3 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(eb.m_quad, ea.m_quad), (__m128)xmmword_141A711B0), ea.m_quad);
    }
    else
    {
      v3 = v5->m_cachedOutgoingEdgeMidpoint.m_quad;
    }
    v4 = v2->m_originalGraph->m_cachedOutgoingEdge.m_oppositeFace;
  }
  v6 = v2->m_clusterGraph == 0i64;
  eb.m_quad = v3;
  if ( v6 || v2->m_originalStartCluster == -1 || !v2->m_hasValidGoalCluster )
  {
    v65 = v2->m_numGoals;
    v66 = (__m128)xmmword_141A712A0;
    if ( v65 > 0 )
    {
      v67 = v2->m_goalPositions;
      do
      {
        ++v67;
        v68 = _mm_sub_ps(v3, v67[-1].m_quad);
        v69 = _mm_mul_ps(v68, v68);
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v71 = _mm_rsqrt_ps(v70);
        v66 = _mm_min_ps(
                v66,
                _mm_andnot_ps(
                  _mm_cmpleps(v70, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v70, v71), v71)),
                      _mm_mul_ps(*(__m128 *)_xmm, v71)),
                    v70)));
        --v65;
      }
      while ( v65 );
    }
    return v66.m128_f32[0];
  }
  v7 = v2->m_originalGraph->m_cachedFace.m_clusterIndex;
  if ( v7 == -1 )
    v8 = -1;
  else
    v8 = v7 | (v2->m_originalGraph->m_cachedOutgoingSectionId << 22);
  v9 = hkaiHierarchicalNavMeshHeuristic::getClusterForFace(v2, v4);
  v10 = v2->m_numGoals;
  v11 = 0;
  v12 = (__m128)xmmword_141A712A0;
  v13 = (__m128)xmmword_141A712A0;
  v14 = 0;
  v15 = v9;
  if ( v10 > 0 )
  {
    v16 = 0i64;
    v17 = v2->m_endClusterKeys;
    v18 = v2->m_numGoals;
    do
    {
      if ( *v17 == v9 || *v17 == v8 )
      {
        v11 = 1;
        v19 = _mm_sub_ps(v3, v2->m_goalPositions[v16].m_quad);
        v20 = _mm_mul_ps(v19, v19);
        v21 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170));
        v22 = _mm_rsqrt_ps(v21);
        v13 = _mm_min_ps(
                v13,
                _mm_andnot_ps(
                  _mm_cmpleps(v21, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22)),
                    v21)));
      }
      ++v17;
      ++v16;
      --v18;
    }
    while ( v18 );
    if ( v11 )
      return v13.m128_f32[0];
  }
  if ( v9 == -1 || v8 == -1 )
  {
    if ( v10 > 0 )
    {
      v60 = v2->m_goalPositions;
      do
      {
        ++v60;
        v61 = _mm_sub_ps(v3, v60[-1].m_quad);
        v62 = _mm_mul_ps(v61, v61);
        v63 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                _mm_shuffle_ps(v62, v62, 170));
        v64 = _mm_rsqrt_ps(v63);
        v12 = _mm_min_ps(
                v12,
                _mm_andnot_ps(
                  _mm_cmpleps(v63, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v63, v64), v64)),
                      _mm_mul_ps(*(__m128 *)_xmm, v64)),
                    v63)));
        --v10;
      }
      while ( v10 );
    }
    return v12.m128_f32[0];
  }
  goalIndexOut = -1;
  if ( hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(v2, v9, &goalIndexOut, &costOut) )
  {
    v8 = v15;
  }
  else if ( v15 == v8
         || !hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(v2, v8, &goalIndexOut, &costOut) )
  {
    goto LABEL_29;
  }
  if ( v8 != -1 )
  {
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v2, v8, &posOut);
    edgeCost = costOut;
    v25 = goalIndexOut + 7i64;
    _mm_store_si128((__m128i *)&endPosition, (__m128i)v2->m_goalPositions[goalIndexOut].m_quad);
    _mm_store_si128((__m128i *)&ea, *((__m128i *)&v2->m_originalGraph + v25));
    hkaiHierarchicalNavMeshHeuristic::adjacentDistance(
      v2,
      (hkSimdFloat32 *)&posOut,
      &eb,
      &posOut,
      &endPosition,
      &ea,
      edgeCost);
    return posOut.m_quad.m128_f32[0];
  }
LABEL_29:
  v26 = 0i64;
  if ( v2->m_coarseSearch.m_state.m_nodeSize < v2->m_coarseSearch.m_state.m_nodeCapacity )
    v26 = hkaiHashSearchState::getNodeState(&v2->m_coarseSearch.m_state, v15);
  v27 = 0;
  if ( !v26 )
    goto LABEL_60;
  if ( v26->m_flags.m_storage & 2 )
  {
LABEL_43:
    v35 = hkaiDirectedGraphEuclideanSearch::getParent(&v2->m_coarseSearch, v15);
    v36 = v35;
    v37 = 0i64;
    for ( i = hkaiDirectedGraphEuclideanSearch::getParent(&v2->m_coarseSearch, v35);
          i != -1;
          i = hkaiDirectedGraphEuclideanSearch::getParent(&v2->m_coarseSearch, i) )
    {
      if ( hkaiHashSearchState::getNodeStateRO(&v2->m_coarseSearch.m_state, i)->m_flags.m_storage & 4 )
        break;
      hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v2, v36, &posOut);
      hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v2, i, &endPosition);
      v36 = i;
      v39 = _mm_sub_ps(posOut.m_quad, endPosition.m_quad);
      v40 = _mm_mul_ps(v39, v39);
      v41 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
              _mm_shuffle_ps(v40, v40, 170));
      v42 = _mm_rsqrt_ps(v41);
      v37 = _mm_add_ps(
              v37,
              _mm_andnot_ps(
                _mm_cmpleps(v41, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v42), v42)),
                    _mm_mul_ps(*(__m128 *)_xmm, v42)),
                  v41)));
    }
    v43 = v2->m_numGoals;
    v44 = 0i64;
    if ( i == -1 )
      i = v36;
    if ( v43 <= 0 )
    {
LABEL_52:
      v46 = -1;
    }
    else
    {
      v45 = v2->m_endClusterKeys;
      while ( *v45 != i )
      {
        ++v44;
        ++v14;
        ++v45;
        if ( v44 >= v43 )
          goto LABEL_52;
      }
      v46 = v14;
    }
    *(float *)&v47 = hkaiDirectedGraphEuclideanSearch::getCost(&v2->m_coarseSearch, v35);
    goalIndexOut = v47;
    v48 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v47, (__m128)(unsigned int)v47, 0)) * 3.0)
                + v37.m128_f32[0])
        * 0.25;
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v2, v35, &posOut);
    hkaiHierarchicalNavMeshHeuristic::getClusterPosition(v2, v36, &endPosition);
    v49 = _mm_sub_ps(v3, posOut.m_quad);
    v50 = _mm_mul_ps(v49, v49);
    v51 = _mm_sub_ps(endPosition.m_quad, v2->m_goalPositions[v46].m_quad);
    v52 = _mm_mul_ps(v51, v51);
    v53 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
            _mm_shuffle_ps(v50, v50, 170));
    v54 = _mm_rsqrt_ps(v53);
    v55 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
            _mm_shuffle_ps(v52, v52, 170));
    v56 = _mm_rsqrt_ps(v55);
    return (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       _mm_cmpleps(v53, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v53, v54), v54)),
                           _mm_mul_ps(v54, *(__m128 *)_xmm)),
                         v53)))
                 + v48)
         + COERCE_FLOAT(
             _mm_andnot_ps(
               _mm_cmpleps(v55, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v56), v56)),
                   _mm_mul_ps(v56, *(__m128 *)_xmm)),
                 v55)));
  }
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "TtAbstractSearch";
    v30 = __rdtsc();
    v31 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v31 - 8) = v30;
    v28[1] = v31;
  }
  if ( v26->m_flags.m_storage & 2 )
  {
LABEL_40:
    v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v33 = v32[1];
    if ( v33 < v32[3] )
    {
      *(_QWORD *)v33 = "Et";
      v34 = __rdtsc();
      *(_DWORD *)(v33 + 8) = v34;
      v32[1] = v33 + 16;
    }
    if ( !v27 )
      goto LABEL_43;
LABEL_60:
    hkaiHierarchicalNavMeshHeuristic::getMinDistanceToGoals(v2, (hkSimdFloat32 *)&posOut, &eb);
    return posOut.m_quad.m128_f32[0];
  }
  while ( v2->m_coarseSearch.m_openSet.m_heapSize )
  {
    if ( v2->m_coarseSearch.m_openSet.m_heapSize >= v2->m_coarseSearch.m_openSet.m_maxSize
      || v2->m_coarseSearch.m_state.m_nodeSize >= v2->m_coarseSearch.m_state.m_nodeCapacity )
    {
      v27 = 1;
      goto LABEL_40;
    }
    hkaiDirectedGraphEuclideanSearch::iteration(&v2->m_coarseSearch);
    if ( v26->m_flags.m_storage & 2 )
      goto LABEL_40;
  }
  v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v58 = v57[1];
  if ( v58 < v57[3] )
  {
    *(_QWORD *)v58 = "Et";
    v59 = __rdtsc();
    *(_DWORD *)(v58 + 8) = v59;
    v57[1] = v58 + 16;
  }
  return FLOAT_3_40282e38;
}

// File Line: 364
// RVA: 0xC20C10
hkSimdFloat32 *__fastcall hkaiHierarchicalNavMeshHeuristic::adjacentDistance(hkaiHierarchicalNavMeshHeuristic *this, hkSimdFloat32 *result, hkVector4f *startPosition, hkVector4f *startCenter, hkVector4f *endPosition, hkVector4f *endCenter)
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
          _mm_cmpleps(v10, (__m128)0i64),
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
          _mm_cmpleps(v15, (__m128)0i64),
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
                           _mm_cmpleps(v18, (__m128)0i64),
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
__int64 __fastcall hkaiHierarchicalNavMeshHeuristic::isFaceChunkAdjacentToGoalChunk(hkaiHierarchicalNavMeshHeuristic *this, int faceIndex, int *goalIndexOut, float *costOut)
{
  hkaiDirectedGraphVisitor *v4; // r11
  hkaiHierarchicalNavMeshHeuristic *v5; // rbx
  hkaiStreamingCollection::InstanceInfo *v6; // r10
  __int64 v7; // rcx
  float *v8; // r13
  int v9; // er12
  int v10; // eax
  __m128 *v11; // rdx
  __int64 v12; // r8
  __int64 v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // r8
  signed int v16; // ecx
  __m128 *v17; // r10
  int v18; // er9
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v24; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v25; // rsi
  float v26; // edi
  int arraySize; // ST20_4
  int v28; // er9
  hkaiDirectedGraphInstance *v29; // r10
  int v30; // ST20_4
  int v31; // eax
  __int64 v32; // rdx
  unsigned int *v33; // rcx
  int v34; // er15
  hkLifoAllocator *v35; // rax
  int *v36; // rdi
  int v37; // edx
  char *v38; // rcx
  hkaiDirectedGraphVisitor *v39; // rsi
  signed int v40; // edx
  signed int v41; // er8
  signed int v42; // er9
  unsigned int v43; // er11
  signed int v44; // ebp
  int v45; // er14
  int *v46; // rcx
  __m128i v47; // xmm2
  __m128i v48; // xmm1
  __m128i v49; // xmm0
  int v50; // eax
  unsigned int v51; // er10
  signed int v52; // edx
  __m128i v53; // xmm2
  __m128i v54; // xmm1
  __m128i v55; // xmm0
  int v56; // eax
  int *v57; // r9
  unsigned __int64 v58; // r11
  hkaiDirectedGraphVisitor *v59; // rcx
  int v60; // esi
  hkaiStreamingCollection::InstanceInfo *v61; // r8
  signed __int64 v62; // rax
  __int64 v63; // rdx
  hkaiDirectedGraphInstance *v64; // rax
  __int64 v65; // r8
  int v66; // edx
  unsigned int v67; // er10
  __int64 v68; // rcx
  unsigned int *v69; // rax
  unsigned __int8 v70; // si
  signed int v71; // ebx
  hkLifoAllocator *v72; // rax
  int v73; // er8
  float v74; // xmm0_4
  int *v76; // [rsp+70h] [rbp+18h]

  v76 = goalIndexOut;
  v4 = this->m_clusterGraph;
  v5 = this;
  v6 = v4->m_streamingInfo;
  v7 = (unsigned int)faceIndex >> 22;
  v8 = costOut;
  v9 = faceIndex;
  v4->m_cachedNodeKey = faceIndex;
  if ( v6 && v4->m_cachedIncomingSectionId != (_DWORD)v7 )
    v4->m_incomingGraph = v6[v7].m_clusterGraphInstance;
  v10 = faceIndex;
  v11 = (__m128 *)v4->m_incomingGraph;
  v4->m_cachedIncomingSectionId = v7;
  v12 = v10 & 0x3FFFFF;
  v4->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(v11[1].m128_u64[0] + 8 * v12);
  if ( v11[7].m128_i32[0] && (v13 = *(signed int *)(v11[6].m128_u64[1] + 4 * v12), (_DWORD)v13 != -1) )
  {
    v4->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(v11[7].m128_u64[1] + 8 * v13);
  }
  else
  {
    v4->m_cachedInstanceNode.m_startEdgeIndex = -1;
    v4->m_cachedInstanceNode.m_numEdges = 0;
  }
  v14 = v11[3].m128_u64[0];
  v15 = 2 * v12;
  v16 = 24;
  v17 = v11;
  v18 = 24;
  v19 = *(__m128 *)(v14 + 8 * v15);
  if ( v4->m_cachedNode.m_numEdges < 24 )
    v18 = v4->m_cachedNode.m_numEdges;
  v20 = _mm_shuffle_ps(*(__m128 *)(v14 + 8 * v15), v19, 85);
  v21 = _mm_shuffle_ps(*(__m128 *)(v14 + 8 * v15), v19, 0);
  v22 = _mm_shuffle_ps(v19, v19, 170);
  if ( v4->m_cachedInstanceNode.m_numEdges < 24 )
    v16 = v4->m_cachedInstanceNode.m_numEdges;
  v23 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, v11[14]), _mm_mul_ps(v21, v11[13])), _mm_mul_ps(v22, v11[15])),
          v11[16]);
  v4->m_cachedNode.m_numEdges = v18;
  v4->m_cachedInstanceNode.m_numEdges = v16;
  v4->m_cachedPosition.m_quad = v23;
  v24 = (hkaiDirectedGraphExplicitCost::Edge *)v11[2].m128_u64[0];
  v25 = (hkaiDirectedGraphExplicitCost::Edge *)v17[8].m128_u64[1];
  v26 = v17[5].m128_f32[2];
  if ( v24 )
  {
    arraySize = v17[2].m128_i32[2];
    copyEdges_1(v4->m_localEdges, v24, v4->m_cachedNode.m_startEdgeIndex, v18);
  }
  if ( v25 )
  {
    v28 = v4->m_cachedInstanceNode.m_numEdges;
    if ( v28 > 0 )
    {
      v29 = v4->m_incomingGraph;
      v30 = v29->m_ownedEdges.m_size;
      copyEdges_1(
        (hkaiDirectedGraphExplicitCost::Edge *)&v4->m_streamingInfo + v4->m_cachedNode.m_numEdges + 18i64,
        v25,
        v4->m_cachedInstanceNode.m_startEdgeIndex - v29->m_numOriginalEdges,
        v28);
    }
  }
  v4->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&v4->m_numGoals;
  v31 = v4->m_cachedNode.m_numEdges + v4->m_cachedInstanceNode.m_numEdges;
  v32 = v31;
  if ( v31 > 0 )
  {
    v33 = &v4->m_localEdges[0].m_target;
    do
    {
      if ( !(*((_BYTE *)v33 - 2) & 0x40) )
      {
        *v33 &= 0x3FFFFFu;
        *v33 |= LODWORD(v26) << 22;
      }
      v33 += 2;
      --v32;
    }
    while ( v32 );
  }
  v34 = v5->m_clusterGraph->m_cachedNode.m_numEdges + v5->m_clusterGraph->m_cachedInstanceNode.m_numEdges;
  if ( v34 )
  {
    v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v36 = (int *)v35->m_cur;
    v37 = (4 * v34 + 127) & 0xFFFFFF80;
    v38 = (char *)v36 + v37;
    if ( v37 > v35->m_slabSize || v38 > v35->m_end )
      v36 = (int *)hkLifoAllocator::allocateFromNewSlab(v35, v37);
    else
      v35->m_cur = v38;
  }
  else
  {
    v36 = 0i64;
  }
  v39 = v5->m_clusterGraph;
  v40 = 0;
  v41 = v39->m_cachedNode.m_numEdges;
  v42 = v39->m_cachedInstanceNode.m_numEdges;
  v43 = v39->m_cachedNode.m_startEdgeIndex;
  v44 = v34 | 0x80000000;
  v45 = v42 + v41;
  v46 = v36;
  if ( v41 > 0 )
  {
    if ( (unsigned int)v41 >= 4 )
    {
      v47 = _mm_load_si128((const __m128i *)&_xmm);
      v48 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v43), 0);
      do
      {
        v49 = _mm_cvtsi32_si128(v40);
        v40 += 4;
        v46 += 4;
        _mm_storeu_si128((__m128i *)v46 - 1, _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v49, 0), v47), v48));
      }
      while ( v40 < v41 - v41 % 4 );
    }
    for ( ; v40 < v41; *(v46 - 1) = v50 )
    {
      v50 = v40++ + v43;
      ++v46;
    }
  }
  v51 = v39->m_cachedInstanceNode.m_startEdgeIndex;
  v52 = 0;
  if ( v42 > 0 )
  {
    if ( (unsigned int)v42 >= 4 )
    {
      v53 = _mm_load_si128((const __m128i *)&_xmm);
      v54 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v51), 0);
      do
      {
        v55 = _mm_cvtsi32_si128(v52);
        v52 += 4;
        v46 += 4;
        _mm_storeu_si128((__m128i *)v46 - 1, _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v55, 0), v53), v54));
      }
      while ( v52 < v42 - v42 % 4 );
    }
    for ( ; v52 < v42; *(v46 - 1) = v56 )
    {
      v56 = v52++ + v51;
      ++v46;
    }
  }
  v57 = v36;
  v58 = (unsigned __int64)&v36[v45];
  if ( (unsigned __int64)v36 >= v58 )
  {
LABEL_51:
    v70 = 0;
    goto LABEL_52;
  }
  while ( 1 )
  {
    v59 = v5->m_clusterGraph;
    v60 = *v57;
    v61 = v59->m_streamingInfo;
    v62 = (signed __int64)&v59->m_currentEdge[1];
    v59->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)v62;
    v63 = (unsigned int)(*(_DWORD *)(v62 + 4) >> 22);
    if ( v61 )
    {
      if ( v59->m_cachedOutgoingSectionId == (_DWORD)v63 )
        goto LABEL_46;
      v64 = v61[v63].m_clusterGraphInstance;
    }
    else
    {
      v64 = v59->m_incomingGraph;
    }
    v59->m_outgoingGraph = v64;
LABEL_46:
    v59->m_cachedOutgoingSectionId = v63;
    v65 = v5->m_numGoals;
    v66 = 0;
    v67 = v5->m_clusterGraph->m_currentEdge->m_target;
    v68 = 0i64;
    if ( v65 > 0 )
      break;
LABEL_50:
    ++v57;
    if ( (unsigned __int64)v57 >= v58 )
      goto LABEL_51;
  }
  v69 = v5->m_endClusterKeys;
  while ( v67 != *v69 )
  {
    ++v68;
    ++v66;
    ++v69;
    if ( v68 >= v65 )
      goto LABEL_50;
  }
  *v76 = v66;
  v74 = hkaiDirectedGraphVisitor::getTotalCost(v5->m_clusterGraph, v9, v67, v60);
  v70 = 1;
  *v8 = v74;
LABEL_52:
  v71 = (4 * v34 + 127) & 0xFFFFFF80;
  v72 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v73 = (v71 + 15) & 0xFFFFFFF0;
  if ( v71 > v72->m_slabSize || (char *)v36 + v73 != v72->m_cur || v72->m_firstNonLifoEnd == v36 )
    hkLifoAllocator::slowBlockFree(v72, v36, v73);
  else
    v72->m_cur = v36;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v36,
      4 * v44);
  return v70;
}

