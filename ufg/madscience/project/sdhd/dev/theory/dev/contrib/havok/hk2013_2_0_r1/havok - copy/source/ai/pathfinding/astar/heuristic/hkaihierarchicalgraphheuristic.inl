// File Line: 16
// RVA: 0xC25E30
hkSimdFloat32 *__fastcall hkaiHierarchicalGraphHeuristic::getMinDistanceToGoals(
        hkaiHierarchicalGraphHeuristic *this,
        hkSimdFloat32 *result,
        hkVector4f *nodePosition)
{
  __int64 m_numGoals; // rax
  __m128 m_quad; // xmm5
  hkVector4f *m_goalPositions; // rcx
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  m_numGoals = this->m_numGoals;
  *result = (hkSimdFloat32)xmmword_141A712A0;
  if ( m_numGoals > 0 )
  {
    m_quad = nodePosition->m_quad;
    m_goalPositions = this->m_goalPositions;
    do
    {
      ++m_goalPositions;
      v6 = _mm_sub_ps(m_quad, m_goalPositions[-1].m_quad);
      v7 = _mm_mul_ps(v6, v6);
      v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
      v9 = _mm_rsqrt_ps(v8);
      result->m_real = _mm_min_ps(
                         result->m_real,
                         _mm_andnot_ps(
                           _mm_cmple_ps(v8, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v9), v9)),
                               _mm_mul_ps(*(__m128 *)_xmm, v9)),
                             v8)));
      --m_numGoals;
    }
    while ( m_numGoals );
  }
  return result;
}

// File Line: 30
// RVA: 0xC25DD0
__int64 __fastcall hkaiHierarchicalGraphHeuristic::getClusterForNode(
        hkaiHierarchicalGraphHeuristic *this,
        unsigned int nodeKey)
{
  hkaiDirectedGraphVisitor *m_originalGraph; // r9
  unsigned int v4; // edx
  __int64 v5; // r8
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx
  hkaiDirectedGraphInstance *m_generalGraph; // rcx
  int m_nodeDataStriding; // eax
  const unsigned int *v10; // rax

  m_originalGraph = this->m_originalGraph;
  v4 = nodeKey & 0x3FFFFF;
  v5 = nodeKey >> 22;
  if ( this->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v5 )
  {
    m_clusterGraphInstance = m_originalGraph->m_streamingInfo[v5].m_clusterGraphInstance;
    m_originalGraph->m_cachedGeneralSectionId = v5;
    m_originalGraph->m_generalGraph = m_clusterGraphInstance;
  }
  m_generalGraph = this->m_originalGraph->m_generalGraph;
  m_nodeDataStriding = m_generalGraph->m_nodeDataStriding;
  if ( m_nodeDataStriding && (v10 = &m_generalGraph->m_originalNodeData[v4 * m_nodeDataStriding]) != 0i64 )
    return *v10 | ((_DWORD)v5 << 22);
  else
    return 0xFFFFFFFFi64;
}

