// File Line: 20
// RVA: 0xC20E40
hkSimdFloat32 *__fastcall hkaiHierarchicalNavMeshHeuristic::getMinDistanceToGoals(hkaiHierarchicalNavMeshHeuristic *this, hkSimdFloat32 *result, hkVector4f *edgePosition)
{
  __int64 v3; // rax
  __m128 v4; // xmm5
  hkVector4f *v5; // r8
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v3 = this->m_numGoals;
  *result = (hkSimdFloat32)xmmword_141A712A0;
  if ( v3 > 0 )
  {
    v4 = edgePosition->m_quad;
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

// File Line: 41
// RVA: 0xC20D70
__int64 __fastcall hkaiHierarchicalNavMeshHeuristic::getClusterForFace(hkaiHierarchicalNavMeshHeuristic *this, unsigned int faceKey)
{
  unsigned int v2; // edi
  unsigned int v3; // esi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **v4; // rbx
  unsigned int v5; // ebp
  int v6; // ecx

  v2 = -1;
  v3 = faceKey;
  if ( faceKey != -1 )
  {
    v4 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **)&this->m_accessor;
    v5 = faceKey >> 22;
    hkaiGeneralAccessor::setSection(&this->m_accessor, faceKey >> 22);
    v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__17(
           (*v4)[1].m_data,
           (*v4)[1].m_size,
           *v4 + 15,
           *v4 + 17,
           (hkArray<int,hkContainerHeapAllocator> *)&(*v4)[14],
           v3 & 0x3FFFFF)->m_clusterIndex;
    if ( v6 != -1 )
      v2 = v6 | (v5 << 22);
  }
  return v2;
}

