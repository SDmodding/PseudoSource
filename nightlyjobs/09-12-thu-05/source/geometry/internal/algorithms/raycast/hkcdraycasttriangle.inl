// File Line: 90
// RVA: 0xD09EE0
void __fastcall hkcdHelperEdgeDots(
        hkVector4f *vA,
        hkVector4f *vB,
        hkFourTransposedPointsf *vI,
        hkVector4f *vN,
        hkVector4f *vDotsOut)
{
  __m128 m_quad; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  __m128 v12; // xmm3

  m_quad = vA->m_quad;
  v6 = vN->m_quad;
  v7 = _mm_sub_ps(vI->m_vertices[0].m_quad, _mm_shuffle_ps(m_quad, m_quad, 0));
  v8 = _mm_shuffle_ps(v6, v6, 85);
  v9 = _mm_sub_ps(vI->m_vertices[1].m_quad, _mm_shuffle_ps(vA->m_quad, vA->m_quad, 85));
  v10 = _mm_sub_ps(vI->m_vertices[2].m_quad, _mm_shuffle_ps(m_quad, m_quad, 170));
  v11 = _mm_shuffle_ps(vN->m_quad, vN->m_quad, 0);
  v12 = _mm_shuffle_ps(v6, v6, 170);
  vDotsOut->m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(vI->m_vertices[0].m_quad, _mm_shuffle_ps(vB->m_quad, vB->m_quad, 0)),
                           _mm_sub_ps(_mm_mul_ps(v10, v8), _mm_mul_ps(v9, v12))),
                         _mm_mul_ps(
                           _mm_sub_ps(vI->m_vertices[1].m_quad, _mm_shuffle_ps(vB->m_quad, vB->m_quad, 85)),
                           _mm_sub_ps(_mm_mul_ps(v7, v12), _mm_mul_ps(v10, v11)))),
                       _mm_mul_ps(
                         _mm_sub_ps(vI->m_vertices[2].m_quad, _mm_shuffle_ps(vB->m_quad, vB->m_quad, 170)),
                         _mm_sub_ps(_mm_mul_ps(v9, v11), _mm_mul_ps(v7, v8))));
}

