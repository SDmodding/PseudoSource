// File Line: 16
// RVA: 0xC25E30
hkSimdFloat32 *__fastcall hkaiHierarchicalGraphHeuristic::getMinDistanceToGoals(hkaiHierarchicalGraphHeuristic *this, hkSimdFloat32 *result, hkVector4f *nodePosition)
{
  __int64 v3; // rax
  __m128 v4; // xmm5
  hkVector4f *v5; // rcx
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v3 = this->m_numGoals;
  *result = (hkSimdFloat32)xmmword_141A712A0;
  if ( v3 > 0 )
  {
    v4 = nodePosition->m_quad;
    v5 = this->m_goalPositions;
    do
    {
      ++v5;
      v6 = _mm_sub_ps(v4, v5[-1].m_quad);
      v7 = _mm_mul_ps(v6, v6);
      v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
      v9 = _mm_rsqrt_ps(v8);
      result->m_real = _mm_min_ps(
                         result->m_real,
                         _mm_andnot_ps(
                           _mm_cmpleps(v8, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v9), v9)),
                               _mm_mul_ps(*(__m128 *)_xmm, v9)),
                             v8)));
      --v3;
    }
    while ( v3 );
  }
  return result;
}

// File Line: 30
// RVA: 0xC25DD0
signed __int64 __fastcall hkaiHierarchicalGraphHeuristic::getClusterForNode(hkaiHierarchicalGraphHeuristic *this, unsigned int nodeKey)
{
  hkaiDirectedGraphVisitor *v2; // r9
  unsigned int v3; // er8
  unsigned int v4; // edx
  __int64 v5; // r8
  hkaiHierarchicalGraphHeuristic *v6; // r10
  hkaiDirectedGraphInstance *v7; // rcx
  hkaiDirectedGraphInstance *v8; // rcx
  int v9; // eax
  const unsigned int *v10; // rax
  signed __int64 result; // rax

  v2 = this->m_originalGraph;
  v3 = nodeKey;
  v4 = nodeKey & 0x3FFFFF;
  v5 = v3 >> 22;
  v6 = this;
  if ( this->m_originalGraph->m_cachedGeneralSectionId != (_DWORD)v5 )
  {
    v7 = v2->m_streamingInfo[v5].m_clusterGraphInstance;
    v2->m_cachedGeneralSectionId = v5;
    v2->m_generalGraph = v7;
  }
  v8 = v6->m_originalGraph->m_generalGraph;
  v9 = v8->m_nodeDataStriding;
  if ( v9 && (v10 = &v8->m_originalNodeData[v4 * v9]) != 0i64 )
    result = *v10 | ((_DWORD)v5 << 22);
  else
    result = 0xFFFFFFFFi64;
  return result;
}

