// File Line: 23
// RVA: 0xC24DB0
void __fastcall hkaiHierarchicalGraphHeuristic::hkaiHierarchicalGraphHeuristic(hkaiHierarchicalGraphHeuristic *this, hkaiSearchMemoryInfo *memInfo)
{
  this->m_originalStartCluster = -1;
  hkaiDirectedGraphEuclideanSearch::hkaiDirectedGraphEuclideanSearch(&this->m_coarseSearch, memInfo);
}

// File Line: 29
// RVA: 0xC24DE0
void __fastcall hkaiHierarchicalGraphHeuristic::init(hkaiHierarchicalGraphHeuristic *this, hkaiDirectedGraphVisitor *originalGraph, hkaiDirectedGraphVisitor *clusterGraph, unsigned int originalStartNodeKey, unsigned int originalEnd)
{
  hkaiHierarchicalGraphHeuristic::init(this, originalGraph, clusterGraph, originalStartNodeKey, &originalEnd, 1);
}

// File Line: 34
// RVA: 0xC24E10
void __fastcall hkaiHierarchicalGraphHeuristic::init(hkaiHierarchicalGraphHeuristic *this, hkaiDirectedGraphVisitor *originalGraph, hkaiDirectedGraphVisitor *clusterGraph, unsigned int originalStartNodeKey, const unsigned int *originalGoalNodeKeys, int numGoals)
{
  const unsigned int *v6; // r15
  hkaiHierarchicalGraphHeuristic *v7; // rbx
  int v8; // ecx
  unsigned int v9; // er12
  int v10; // edi
  hkaiDirectedGraphVisitor *v11; // rbp
  int v12; // esi
  unsigned int *v13; // r14
  int i; // er10
  hkaiDirectedGraphVisitor *v15; // r8
  int v16; // er9
  __int64 v17; // rdx
  hkaiDirectedGraphInstance *v18; // rcx
  hkaiDirectedGraphInstance *v19; // r8
  int v20; // eax
  const unsigned int *v21; // r8
  int v22; // edx
  char v23; // al
  hkaiDirectedGraphVisitor *v24; // r8
  unsigned int v25; // edx
  int v26; // er12
  __int64 v27; // rdx
  hkaiDirectedGraphInstance *v28; // rcx
  hkaiDirectedGraphInstance *v29; // r8
  int v30; // eax
  const unsigned int *v31; // r8
  signed int end; // edx
  unsigned int *v33; // rsi

  v6 = originalGoalNodeKeys;
  v7 = this;
  v8 = 16;
  v9 = originalStartNodeKey;
  if ( numGoals < 16 )
    v8 = numGoals;
  v10 = 0;
  v11 = clusterGraph;
  v7->m_originalGraph = originalGraph;
  v7->m_clusterGraph = clusterGraph;
  v7->m_startNodeKey = originalStartNodeKey;
  v7->m_numGoals = v8;
  v7->m_goalNodeKeys = originalGoalNodeKeys;
  v12 = 0;
  if ( v8 > 0 )
  {
    v13 = (unsigned int *)originalGoalNodeKeys;
    do
    {
      hkaiHierarchicalGraphHeuristic::getNodePosition(v7, *v13, (hkVector4f *)v7 + v12++ + 35i64);
      ++v13;
    }
    while ( v12 < v7->m_numGoals );
  }
  v7->m_hasValidGoalCluster = 0;
  if ( v11 )
  {
    for ( i = 0; i < v7->m_numGoals; ++v6 )
    {
      v15 = v7->m_originalGraph;
      v16 = *v6 & 0x3FFFFF;
      v17 = *v6 >> 22;
      if ( v7->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v17 )
      {
        v18 = v15->m_streamingInfo[v17].m_clusterGraphInstance;
        v15->m_cachedGeneralSectionId = v17;
        v15->m_generalGraph = v18;
      }
      v19 = v7->m_originalGraph->m_generalGraph;
      v20 = v19->m_nodeDataStriding;
      if ( v20 && (v21 = &v19->m_originalNodeData[v16 * v20]) != 0i64 )
        v22 = *v21 | ((_DWORD)v17 << 22);
      else
        v22 = -1;
      *(const unsigned int *)((char *)v6 + (char *)v7 - (char *)originalGoalNodeKeys + 44) = v22;
      if ( v7->m_hasValidGoalCluster || (v23 = 0, v22 != -1) )
        v23 = 1;
      ++i;
      v7->m_hasValidGoalCluster = v23;
    }
    v24 = v7->m_originalGraph;
    v25 = v9;
    v26 = v9 & 0x3FFFFF;
    v27 = v25 >> 22;
    if ( v7->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v27 )
    {
      v28 = v24->m_streamingInfo[v27].m_clusterGraphInstance;
      v24->m_cachedGeneralSectionId = v27;
      v24->m_generalGraph = v28;
    }
    v29 = v7->m_originalGraph->m_generalGraph;
    v30 = v29->m_nodeDataStriding;
    if ( v30 && (v31 = &v29->m_originalNodeData[v26 * v30]) != 0i64 )
      end = *v31 | ((_DWORD)v27 << 22);
    else
      end = -1;
    v7->m_originalStartCluster = end;
    if ( end != -1 && v7->m_hasValidGoalCluster )
      hkaiDirectedGraphEuclideanSearch::init(
        &v7->m_coarseSearch,
        v7->m_clusterGraph,
        v7->m_endClusterKeys,
        v7->m_numGoals,
        end);
    if ( v7->m_numGoals > 0 )
    {
      v33 = v7->m_endClusterKeys;
      do
      {
        if ( *v33 != -1 )
          hkaiHierarchicalGraphHeuristic::getClusterPosition(v7, *v33, (hkVector4f *)v7 + v10 + 7i64);
        ++v10;
        ++v33;
      }
      while ( v10 < v7->m_numGoals );
    }
  }
}

// File Line: 100
// RVA: 0xC25770
void __fastcall hkaiHierarchicalGraphHeuristic::getClusterPosition(hkaiHierarchicalGraphHeuristic *this, unsigned int key, hkVector4f *posOut)
{
  hkaiDirectedGraphVisitor *v3; // r10
  unsigned int v4; // er11
  hkaiHierarchicalGraphHeuristic *v5; // rdx
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

// File Line: 113
// RVA: 0xC25020
float __fastcall hkaiHierarchicalGraphHeuristic::getHeuristic(hkaiHierarchicalGraphHeuristic *this, unsigned int nodeKey)
{
  unsigned int v2; // edi
  hkaiHierarchicalGraphHeuristic *v3; // rbx
  unsigned int v4; // eax
  char v5; // r9
  unsigned int v6; // edi
  __int64 v7; // rax
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm7
  __m128 *v11; // rdx
  unsigned int *v12; // rcx
  __int64 v13; // r8
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  signed __int64 v19; // rbx
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  signed __int64 v24; // rax
  __m128i v25; // xmm0
  signed int v26; // er14
  hkaiSearchStateNode *v27; // r15
  signed int v28; // er12
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  int v37; // er15
  unsigned int v38; // edi
  signed int v39; // edi
  _QWORD *v40; // r8
  unsigned __int64 v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  bool v47; // zf
  __int64 v48; // rdx
  __int64 v49; // rcx
  unsigned int *v50; // rax
  _QWORD *v51; // rcx
  _QWORD *v52; // r8
  unsigned __int64 v53; // rax
  signed __int64 v54; // r8
  int v55; // esi
  int v56; // xmm0_4
  __m128 v57; // xmm8
  __m128 v58; // xmm8
  __m128 v59; // xmm1
  __m128 v60; // xmm9
  __m128 v61; // xmm1
  __m128 v62; // xmm5
  __m128 v63; // xmm8
  __m128 v64; // xmm4
  __int64 v65; // rax
  __m128 v66; // xmm5
  signed __int64 v67; // rbx
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  hkVector4f posOut; // [rsp+28h] [rbp-69h]
  hkVector4f endCenter; // [rsp+38h] [rbp-59h]
  hkVector4f endPosition; // [rsp+48h] [rbp-49h]
  hkVector4f startCenter; // [rsp+58h] [rbp-39h]
  float costOut; // [rsp+F8h] [rbp+67h]
  int goalIndexOut; // [rsp+100h] [rbp+6Fh]

  v2 = nodeKey;
  v3 = this;
  hkaiHierarchicalGraphHeuristic::getNodePosition(this, nodeKey, (hkVector4f *)((char *)&endCenter + 8));
  if ( !v3->m_clusterGraph || v3->m_originalStartCluster == -1 || !v3->m_hasValidGoalCluster )
  {
    v65 = v3->m_numGoals;
    v66 = (__m128)xmmword_141A712A0;
    if ( v65 > 0 )
    {
      v67 = (signed __int64)v3->m_goalPositions;
      do
      {
        v67 += 16i64;
        v68 = _mm_sub_ps(posOut.m_quad, *(__m128 *)(v67 - 16));
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
  v4 = hkaiHierarchicalGraphHeuristic::getClusterForNode(v3, v2);
  v5 = 0;
  v6 = v4;
  v7 = v3->m_numGoals;
  v8 = (__m128)xmmword_141A712A0;
  v9 = posOut.m_quad;
  v10 = (__m128)xmmword_141A712A0;
  if ( v7 > 0 )
  {
    v11 = (__m128 *)v3->m_goalPositions;
    v12 = v3->m_endClusterKeys;
    v13 = v3->m_numGoals;
    do
    {
      if ( *v12 == v6 )
      {
        v5 = 1;
        v14 = _mm_sub_ps(posOut.m_quad, *v11);
        v15 = _mm_mul_ps(v14, v14);
        v16 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170));
        v17 = _mm_rsqrt_ps(v16);
        v10 = _mm_min_ps(
                v10,
                _mm_andnot_ps(
                  _mm_cmpleps(v16, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v17), v17)),
                      _mm_mul_ps(*(__m128 *)_xmm, v17)),
                    v16)));
      }
      ++v12;
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
      v19 = (signed __int64)v3->m_goalPositions;
      do
      {
        v19 += 16i64;
        v20 = _mm_sub_ps(posOut.m_quad, *(__m128 *)(v19 - 16));
        v21 = _mm_mul_ps(v20, v20);
        v22 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170));
        v23 = _mm_rsqrt_ps(v22);
        v8 = _mm_min_ps(
               v8,
               _mm_andnot_ps(
                 _mm_cmpleps(v22, (__m128)0i64),
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
  if ( hkaiHierarchicalGraphHeuristic::isFaceChunkAdjacentToGoalChunk(v3, v6, &goalIndexOut, &costOut) )
  {
    hkaiHierarchicalGraphHeuristic::getClusterPosition(v3, v6, &startCenter);
    posOut.m_quad.m128_f32[2] = costOut;
    v24 = goalIndexOut + 7i64;
    _mm_store_si128((__m128i *)&endPosition, (__m128i)v3->m_goalPositions[goalIndexOut].m_quad);
    v25 = *((__m128i *)&v3->m_originalGraph + v24);
    posOut.m_quad.m128_u64[0] = (unsigned __int64)&endCenter;
    _mm_store_si128((__m128i *)&endCenter, v25);
    hkaiHierarchicalGraphHeuristic::adjacentDistance(
      v3,
      (hkSimdFloat32 *)&startCenter,
      &posOut,
      &startCenter,
      &endPosition,
      (hkVector4f *)posOut.m_quad.m128_u64[0],
      posOut.m_quad.m128_f32[2]);
    return startCenter.m_quad.m128_f32[0];
  }
  v26 = 0;
  v27 = 0i64;
  if ( v3->m_coarseSearch.m_state.m_nodeSize < v3->m_coarseSearch.m_state.m_nodeCapacity )
    v27 = hkaiHashSearchState::getNodeState(&v3->m_coarseSearch.m_state, v6);
  v28 = 0;
  if ( !v27 )
    goto LABEL_56;
  if ( v27->m_flags.m_storage & 2 )
  {
LABEL_32:
    goalIndexOut = hkaiDirectedGraphEuclideanSearch::getParent(&v3->m_coarseSearch, v6);
    v37 = goalIndexOut;
    v38 = hkaiDirectedGraphEuclideanSearch::getParent(&v3->m_coarseSearch, goalIndexOut);
    if ( v3->m_numGoals == 1 )
    {
      v37 = v3->m_endClusterKeys[0];
      v39 = 0;
    }
    else
    {
      v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v44 = (_QWORD *)v43[1];
      if ( (unsigned __int64)v44 < v43[3] )
      {
        *v44 = "Ttwalk";
        v45 = __rdtsc();
        v46 = (signed __int64)(v44 + 2);
        *(_DWORD *)(v46 - 8) = v45;
        v43[1] = v46;
      }
      v47 = v38 == -1;
      if ( v38 != -1 )
      {
        do
        {
          if ( hkaiHashSearchState::getNodeStateRO(&v3->m_coarseSearch.m_state, v38)->m_flags.m_storage & 4 )
            break;
          v37 = v38;
          v38 = hkaiDirectedGraphEuclideanSearch::getParent(&v3->m_coarseSearch, v38);
        }
        while ( v38 != -1 );
        v47 = v38 == -1;
      }
      v48 = v3->m_numGoals;
      if ( v47 )
        v38 = v37;
      v49 = 0i64;
      if ( v48 <= 0 )
      {
LABEL_51:
        v39 = -1;
      }
      else
      {
        v50 = v3->m_endClusterKeys;
        while ( *v50 != v38 )
        {
          ++v49;
          ++v26;
          ++v50;
          if ( v49 >= v48 )
            goto LABEL_51;
        }
        v39 = v26;
      }
      v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v52 = (_QWORD *)v51[1];
      if ( (unsigned __int64)v52 < v51[3] )
      {
        *v52 = "Et";
        v53 = __rdtsc();
        v54 = (signed __int64)(v52 + 2);
        *(_DWORD *)(v54 - 8) = v53;
        v51[1] = v54;
      }
    }
    v55 = goalIndexOut;
    *(float *)&v56 = hkaiDirectedGraphEuclideanSearch::getCost(&v3->m_coarseSearch, goalIndexOut);
    goalIndexOut = v56;
    hkaiHierarchicalGraphHeuristic::getClusterPosition(v3, v55, &startCenter);
    hkaiHierarchicalGraphHeuristic::getClusterPosition(v3, v37, &endPosition);
    v57 = _mm_sub_ps(v9, startCenter.m_quad);
    v58 = _mm_mul_ps(v57, v57);
    v59 = _mm_sub_ps(endPosition.m_quad, v3->m_goalPositions[v39].m_quad);
    v60 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
            _mm_shuffle_ps(v58, v58, 170));
    v61 = _mm_mul_ps(v59, v59);
    v62 = _mm_rsqrt_ps(v60);
    v63 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
            _mm_shuffle_ps(v61, v61, 170));
    v64 = _mm_rsqrt_ps(v63);
    return (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       _mm_cmpleps(v60, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v62, v60), v62)),
                           _mm_mul_ps(v62, *(__m128 *)_xmm)),
                         v60)))
                 + COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v56, (__m128)(unsigned int)v56, 0)))
         + COERCE_FLOAT(
             _mm_andnot_ps(
               _mm_cmpleps(v63, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                   _mm_mul_ps(v64, *(__m128 *)_xmm)),
                 v63)));
  }
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "TtAbstractSearch";
    v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] = v32;
  }
  if ( v27->m_flags.m_storage & 2 )
  {
LABEL_29:
    v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v34 = (_QWORD *)v33[1];
    if ( (unsigned __int64)v34 < v33[3] )
    {
      *v34 = "Et";
      v35 = __rdtsc();
      v36 = (signed __int64)(v34 + 2);
      *(_DWORD *)(v36 - 8) = v35;
      v33[1] = v36;
    }
    if ( !v28 )
      goto LABEL_32;
LABEL_56:
    hkaiHierarchicalGraphHeuristic::getMinDistanceToGoals(v3, (hkSimdFloat32 *)&startCenter, &posOut);
    return startCenter.m_quad.m128_f32[0];
  }
  while ( v3->m_coarseSearch.m_openSet.m_heapSize )
  {
    if ( v3->m_coarseSearch.m_openSet.m_heapSize >= v3->m_coarseSearch.m_openSet.m_maxSize
      || v3->m_coarseSearch.m_state.m_nodeSize >= v3->m_coarseSearch.m_state.m_nodeCapacity )
    {
      v28 = 1;
      goto LABEL_29;
    }
    hkaiDirectedGraphEuclideanSearch::iteration(&v3->m_coarseSearch);
    if ( v27->m_flags.m_storage & 2 )
      goto LABEL_29;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = v40[1];
  if ( v41 < v40[3] )
  {
    *(_QWORD *)v41 = "Et";
    v42 = __rdtsc();
    *(_DWORD *)(v41 + 8) = v42;
    v40[1] = v41 + 16;
  }
  return FLOAT_3_40282e38;
}

// File Line: 354
// RVA: 0xC25C70
hkSimdFloat32 *__fastcall hkaiHierarchicalGraphHeuristic::adjacentDistance(hkaiHierarchicalGraphHeuristic *this, hkSimdFloat32 *result, hkVector4f *startPosition, hkVector4f *startCenter, hkVector4f *endPosition, hkVector4f *endCenter)
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

// File Line: 407
// RVA: 0xC25800
__int64 __fastcall hkaiHierarchicalGraphHeuristic::isFaceChunkAdjacentToGoalChunk(hkaiHierarchicalGraphHeuristic *this, int faceIndex, int *goalIndexOut, float *costOut)
{
  hkaiDirectedGraphVisitor *v4; // r11
  hkaiHierarchicalGraphHeuristic *v5; // rbx
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
    copyEdges_2(v4->m_localEdges, v24, v4->m_cachedNode.m_startEdgeIndex, v18);
  }
  if ( v25 )
  {
    v28 = v4->m_cachedInstanceNode.m_numEdges;
    if ( v28 > 0 )
    {
      v29 = v4->m_incomingGraph;
      v30 = v29->m_ownedEdges.m_size;
      copyEdges_2(
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

// File Line: 441
// RVA: 0xC256D0
void __fastcall hkaiHierarchicalGraphHeuristic::getNodePosition(hkaiHierarchicalGraphHeuristic *this, unsigned int nodeKey, hkVector4f *posOut)
{
  hkaiDirectedGraphVisitor *v3; // r9
  hkaiStreamingCollection::InstanceInfo *v4; // r11
  __int64 v5; // r10
  hkaiDirectedGraphInstance *v6; // rax
  hkaiDirectedGraphVisitor *v7; // rax
  unsigned int v8; // ecx
  __m128 *v9; // rdx
  __m128 v10; // xmm1

  v3 = this->m_originalGraph;
  v4 = this->m_originalGraph->m_streamingInfo;
  v5 = nodeKey >> 22;
  if ( !v4 )
  {
    v6 = v3->m_incomingGraph;
    goto LABEL_5;
  }
  if ( v3->m_cachedOutgoingSectionId != (_DWORD)v5 )
  {
    v6 = v4[v5].m_clusterGraphInstance;
LABEL_5:
    v3->m_outgoingGraph = v6;
  }
  v3->m_cachedOutgoingSectionId = v5;
  v7 = this->m_originalGraph;
  v8 = nodeKey;
  v9 = (__m128 *)v7->m_outgoingGraph;
  v10 = *(__m128 *)(v9[3].m128_u64[0] + 16i64 * (v8 & 0x3FFFFF));
  posOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v9[14]),
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v9[13])),
                       _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v9[15])),
                     v9[16]);
}

