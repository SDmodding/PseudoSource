// File Line: 89
// RVA: 0xCF86B0
void __fastcall hkpCapsuleShape::getCentre(hkpCapsuleShape *this, hkVector4f *centreOut)
{
  hkVector4f v2; // xmm0

  v2.m_quad = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2.m_quad;
  centreOut->m_quad = _mm_mul_ps(v2.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 95
// RVA: 0xCF8670
void __fastcall hkpCapsuleShape::convertVertexIdsToVertices(hkpCapsuleShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int i; // er10
  __int64 v5; // r8

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = v5 | 0x3F000000 )
  {
    v5 = *ids;
    ++verticesOut;
    ++ids;
    --i;
    verticesOut[-1] = *(hkcdVertex *)((char *)&this->m_vertexA + v5);
  }
}

// File Line: 107
// RVA: 0xCF86D0
void __fastcall hkpCapsuleShape::getSupportingVertex(hkpCapsuleShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkVector4f v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // [rsp+0h] [rbp-28h]
  __m128 v8; // [rsp+10h] [rbp-18h]

  v3.m_quad = (__m128)this->m_vertexB;
  v4 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  _mm_store_si128((__m128i *)&v7, (__m128i)this->m_vertexA.m_quad);
  _mm_store_si128((__m128i *)&v8, (__m128i)v3.m_quad);
  v5 = _mm_mul_ps(v4, direction->m_quad);
  v7.m128_i32[3] = 1056964608;
  v8.m128_i32[3] = 1056964624;
  v6 = _mm_cmpltps(
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
         (__m128)0i64);
  supportingVertexOut->m_quad = _mm_or_ps(_mm_and_ps(v6, v7), _mm_andnot_ps(v6, v8));
}

