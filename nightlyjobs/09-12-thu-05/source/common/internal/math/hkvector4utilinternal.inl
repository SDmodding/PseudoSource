// File Line: 11
// RVA: 0xDC4F80
hkSimdFloat32 *__fastcall hkVector4UtilInternal::surfaceArea_5(hkSimdFloat32 *result, hkAabb *aabb)
{
  hkSimdFloat32 *v2; // rax
  __m128 v3; // xmm0
  __m128 v4; // xmm2

  v2 = result;
  v3 = _mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad);
  v4 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v3);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                     _mm_shuffle_ps(v4, v4, 170));
  return v2;
}

// File Line: 150
// RVA: 0xB7DB50
hkVector4fComparison *__fastcall hkVector4UtilInternal::intersectRayBundle(hkVector4fComparison *result, hkAabb *aabb, hkFourTransposedPointsf *rayOrg, hkFourTransposedPointsf *rayInvDir, hkVector4f *maxFraction)
{
  hkVector4f v5; // xmm6
  hkVector4fComparison *v6; // rax
  hkVector4f v7; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm4

  v5.m_quad = (__m128)aabb->m_max;
  v6 = result;
  v7.m_quad = (__m128)aabb->m_min;
  v8 = _mm_mul_ps(
         _mm_sub_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), rayOrg->m_vertices[0].m_quad),
         rayInvDir->m_vertices[0].m_quad);
  v9 = _mm_mul_ps(
         _mm_sub_ps(_mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 85), rayOrg->m_vertices[1].m_quad),
         rayInvDir->m_vertices[1].m_quad);
  v10 = _mm_mul_ps(
          _mm_sub_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 170), rayOrg->m_vertices[2].m_quad),
          rayInvDir->m_vertices[2].m_quad);
  v11 = _mm_mul_ps(
          _mm_sub_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), rayOrg->m_vertices[0].m_quad),
          rayInvDir->m_vertices[0].m_quad);
  v12 = _mm_shuffle_ps(aabb->m_max.m_quad, v5.m_quad, 85);
  v13 = _mm_mul_ps(
          _mm_sub_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 170), rayOrg->m_vertices[2].m_quad),
          rayInvDir->m_vertices[2].m_quad);
  v14 = _mm_mul_ps(_mm_sub_ps(v12, rayOrg->m_vertices[1].m_quad), rayInvDir->m_vertices[1].m_quad);
  result->m_mask = _mm_cmpleps(
                     _mm_max_ps(
                       _mm_max_ps(_mm_max_ps(_mm_min_ps(v8, v11), _mm_min_ps(v9, v14)), _mm_min_ps(v10, v13)),
                       (__m128)0i64),
                     _mm_min_ps(
                       maxFraction->m_quad,
                       _mm_min_ps(_mm_min_ps(_mm_max_ps(v8, v11), _mm_max_ps(v9, v14)), _mm_max_ps(v10, v13))));
  return v6;
}

