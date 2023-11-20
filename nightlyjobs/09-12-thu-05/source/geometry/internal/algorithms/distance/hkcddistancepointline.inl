// File Line: 31
// RVA: 0xB8EA20
hkSimdFloat32 *__fastcall hkcdPointLineDistanceSquared(hkSimdFloat32 *result, hkVector4f *point, hkVector4f *lineA, hkVector4f *lineB, hkVector4f *projectionOut)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm7
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm5

  v5 = point->m_quad;
  v6 = _mm_sub_ps(lineA->m_quad, point->m_quad);
  v7 = _mm_sub_ps(lineA->m_quad, lineB->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_mul_ps(v6, v7);
  v11 = _mm_rcp_ps(v9);
  v12 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v11)), v11),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)));
  v13 = _mm_sub_ps(v6, _mm_mul_ps(v12, v7));
  v14 = _mm_mul_ps(v13, v13);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                     _mm_shuffle_ps(v14, v14, 170));
  if ( projectionOut )
  {
    v15 = _mm_add_ps(v5, v13);
    projectionOut->m_quad = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v12), 196);
  }
  return result;
}

// File Line: 37
// RVA: 0xE00980
hkSimdFloat32 *__fastcall hkcdPointSegmentDistanceSquared_14(hkSimdFloat32 *result, hkVector4f *point, hkVector4f *lineStart, hkVector4f *lineEnd, hkVector4f *projectionOut)
{
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm6

  v5 = point->m_quad;
  v6 = _mm_sub_ps(lineStart->m_quad, point->m_quad);
  v7 = _mm_sub_ps(lineStart->m_quad, lineEnd->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_mul_ps(v6, v7);
  v11 = _mm_rcp_ps(v9);
  v12 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v11)), v11),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)));
  v13 = _mm_cmpltps(v12, query.m_quad);
  v14 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v13, v12), _mm_andnot_ps(v13, query.m_quad)));
  v15 = _mm_sub_ps(v6, _mm_mul_ps(v14, v7));
  v16 = _mm_mul_ps(v15, v15);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                     _mm_shuffle_ps(v16, v16, 170));
  if ( projectionOut )
  {
    v17 = _mm_add_ps(v5, v15);
    projectionOut->m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v14), 196);
  }
  return result;
}

