// File Line: 20
// RVA: 0xC20E40
hkSimdFloat32 *__fastcall hkaiHierarchicalNavMeshHeuristic::getMinDistanceToGoals(
        hkaiHierarchicalNavMeshHeuristic *this,
        hkSimdFloat32 *result,
        hkVector4f *edgePosition)
{
  __int64 m_numGoals; // rax
  __m128 m_quad; // xmm5
  hkVector4f *m_goalPositions; // r8
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  m_numGoals = this->m_numGoals;
  *result = (hkSimdFloat32)xmmword_141A712A0;
  if ( m_numGoals > 0 )
  {
    m_quad = edgePosition->m_quad;
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

// File Line: 41
// RVA: 0xC20D70
__int64 __fastcall hkaiHierarchicalNavMeshHeuristic::getClusterForFace(
        hkaiHierarchicalNavMeshHeuristic *this,
        unsigned int faceKey)
{
  unsigned int v2; // edi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **p_m_accessor; // rbx
  unsigned int v5; // ebp
  int m_clusterIndex; // ecx

  v2 = -1;
  if ( faceKey != -1 )
  {
    p_m_accessor = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **)&this->m_accessor;
    v5 = faceKey >> 22;
    hkaiGeneralAccessor::setSection(&this->m_accessor, faceKey >> 22);
    m_clusterIndex = hkaiNavMeshInstance_get_hkaiNavMesh::Face__17(
                       (*p_m_accessor)[1].m_data,
                       (*p_m_accessor)[1].m_size,
                       *p_m_accessor + 15,
                       *p_m_accessor + 17,
                       (hkArray<int,hkContainerHeapAllocator> *)&(*p_m_accessor)[14],
                       faceKey & 0x3FFFFF)->m_clusterIndex;
    if ( m_clusterIndex != -1 )
      return m_clusterIndex | (v5 << 22);
  }
  return v2;
}

