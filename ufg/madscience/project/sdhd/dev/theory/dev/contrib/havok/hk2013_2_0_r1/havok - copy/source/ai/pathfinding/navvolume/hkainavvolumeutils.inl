// File Line: 58
// RVA: 0xC1DBD0
char __fastcall hkaiNavVolumeUtils::getPortalPlaneIntersection(hkVector4f *p1, hkVector4f *p2, hkAabb *portal, hkSimdFloat32 *tOut)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  __m128 v9; // xmm9
  __m128 v10; // xmm8
  __m128 v11; // xmm9
  __m128 v12; // xmm3
  char result; // al
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm0

  v4 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(portal->m_max.m_quad, portal->m_min.m_quad), 1u), 1u);
  v5 = _mm_shuffle_ps(v4, v4, 0);
  v6 = _mm_shuffle_ps(v4, v4, 85);
  v7 = _mm_cmpltps(v6, v5);
  v8 = _mm_cmpltps(_mm_shuffle_ps(v4, v4, 170), _mm_or_ps(_mm_andnot_ps(v7, v5), _mm_and_ps(v6, v7)));
  v9 = _mm_or_ps(
         _mm_andnot_ps(v8, _mm_or_ps(_mm_andnot_ps(v7, transform.m_quad), _mm_and_ps(direction.m_quad, v7))),
         _mm_and_ps(stru_141A71280.m_quad, v8));
  v10 = _mm_mul_ps(_mm_mul_ps(_mm_add_ps(portal->m_min.m_quad, portal->m_max.m_quad), (__m128)xmmword_141A711B0), v9);
  v11 = _mm_shuffle_ps(
          v9,
          _mm_unpackhi_ps(
            v9,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170)))),
          196);
  v12 = _mm_mul_ps(_mm_sub_ps(p2->m_quad, p1->m_quad), v11);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)))) >> 1) < 0.00000011920929 )
    return 0;
  v14 = _mm_mul_ps(p1->m_quad, v11);
  result = 1;
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v16 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v11), 196);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_rcp_ps(v15);
  tOut->m_real = _mm_mul_ps(
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v18)), v18),
                   _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17)));
  return result;
}

