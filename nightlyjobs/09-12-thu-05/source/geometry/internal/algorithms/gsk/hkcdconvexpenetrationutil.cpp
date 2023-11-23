// File Line: 14
// RVA: 0x1319460
hkSimdFloat32 *__fastcall hkcdConvexPenetrationUtil::findBestProjection(
        hkcdConvexPenetrationUtil *this,
        hkSimdFloat32 *result,
        hkVector4f *direction,
        hkVector4f *from,
        hkcdWingedEdge::Vertex *resulta)
{
  hkVector4f v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  hkcdVertex v14; // xmm0
  hkcdVertex v15; // xmm1
  hkcdWingedEdge::Edge *m_storage; // rax
  hkVector4f directiona; // [rsp+20h] [rbp-58h] BYREF
  hkcdWingedEdge::Vertex v19; // [rsp+30h] [rbp-48h] BYREF

  directiona.m_quad = _mm_xor_ps(
                        (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                        direction->m_quad);
  hkcdConvexPenetrationUtil::getPointForSimplex(this, direction, &v19);
  hkcdConvexPenetrationUtil::getPointForSimplex(this, &directiona, resulta);
  v9.m_quad = (__m128)v19.m_position;
  v10 = _mm_mul_ps(_mm_sub_ps(resulta->m_position.m_quad, from->m_quad), directiona.m_quad);
  v11 = _mm_mul_ps(_mm_sub_ps(v19.m_position.m_quad, from->m_quad), direction->m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  result->m_real = _mm_max_ps(v12, v13);
  if ( v13.m128_f32[0] < v12.m128_f32[0] )
  {
    v14.m_quad = (__m128)v19.m_pointAinA;
    v15.m_quad = (__m128)v19.m_pointBinX;
    m_storage = v19.m_referee.m_storage;
    resulta->m_position = (hkVector4f)v9.m_quad;
    resulta->m_pointAinA = (hkcdVertex)v14.m_quad;
    resulta->m_pointBinX = (hkcdVertex)v15.m_quad;
    resulta->m_referee.m_storage = m_storage;
  }
  return result;
}

// File Line: 47
// RVA: 0x13193E0
void __fastcall hkcdConvexPenetrationUtil::getPointForSimplex(
        hkcdConvexPenetrationUtil *this,
        hkVector4f *direction,
        hkcdWingedEdge::Vertex *result)
{
  hkcdVertex *p_m_pointAinA; // rbx
  __m128 v5; // xmm1
  __m128 v6; // [rsp+40h] [rbp-28h] BYREF
  __m128 v7; // [rsp+50h] [rbp-18h] BYREF

  p_m_pointAinA = &result->m_pointAinA;
  this->m_shapeInterface.m_storage->vfptr->getSupportingVertices(
    this->m_shapeInterface.m_storage,
    this->m_shapeA.m_storage,
    direction,
    this->m_shapeB.m_storage,
    (hkTransformf *)this,
    &result->m_pointAinA,
    (hkcdVertex *)&v7,
    (hkVector4f *)&v6);
  v5 = v6;
  result->m_position.m_quad = _mm_sub_ps(p_m_pointAinA->m_quad, v6);
  result->m_pointBinX.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, v7), 196);
}

