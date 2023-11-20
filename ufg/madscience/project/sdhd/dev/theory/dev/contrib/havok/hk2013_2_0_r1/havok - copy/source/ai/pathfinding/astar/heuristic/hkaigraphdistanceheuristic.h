// File Line: 39
// RVA: 0xC1FC60
float __fastcall hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor>::getHeuristic(hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor> *this, int nid)
{
  hkaiDirectedGraphInstance *v2; // r9
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm2
  float result; // xmm0_4

  v2 = this->m_graph->m_outgoingGraph;
  v3 = v2->m_originalPositions[nid & 0x3FFFFF].m_quad;
  v4 = _mm_sub_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v2->m_transform.m_rotation.m_col1.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v2->m_transform.m_rotation.m_col0.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v2->m_transform.m_rotation.m_col2.m_quad)),
           v2->m_transform.m_translation.m_quad),
         this->m_endPosition.m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  LODWORD(result) = (unsigned __int128)_mm_andnot_ps(
                                         _mm_cmpleps(v6, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v7), v7)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v7)),
                                           v6));
  return result;
}

// File Line: 80
// RVA: 0xC1CFE0
float __fastcall hkaiGraphMultiDistanceHeuristic<hkaiNavVolumeGraph>::getHeuristic(hkaiGraphMultiDistanceHeuristic<hkaiNavVolumeGraph> *this, int nid)
{
  signed __int64 v2; // rdx
  __m128 v3; // xmm6
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  hkaiGraphMultiDistanceHeuristic<hkaiNavVolumeGraph>::Goal *v9; // rax
  signed __int64 v10; // rcx
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  v2 = this->m_numGoals;
  v3 = _mm_mul_ps(
         _mm_add_ps(this->m_graph->m_cachedAdjacentAabb.m_max.m_quad, this->m_graph->m_cachedAdjacentAabb.m_min.m_quad),
         (__m128)xmmword_141A711B0);
  v4 = _mm_sub_ps(v3, this->m_goals[0].m_position.m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  v8 = _mm_andnot_ps(
         _mm_cmpleps(v6, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v7), v7)), _mm_mul_ps(*(__m128 *)_xmm, v7)),
           v6));
  if ( v2 > 1 )
  {
    v9 = &this->m_goals[1];
    v10 = v2 - 1;
    do
    {
      ++v9;
      v11 = _mm_sub_ps(v3, v9[-1].m_position.m_quad);
      v12 = _mm_mul_ps(v11, v11);
      v13 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v14 = _mm_rsqrt_ps(v13);
      v8 = _mm_min_ps(
             v8,
             _mm_andnot_ps(
               _mm_cmpleps(v13, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v14), v14)),
                   _mm_mul_ps(*(__m128 *)_xmm, v14)),
                 v13)));
      --v10;
    }
    while ( v10 );
  }
  return v8.m128_f32[0];
}

