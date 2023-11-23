// File Line: 89
// RVA: 0xCF86B0
void __fastcall hkpCapsuleShape::getCentre(hkpCapsuleShape *this, hkVector4f *centreOut)
{
  __m128 v2; // xmm0

  v2 = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2;
  centreOut->m_quad = _mm_mul_ps(v2, (__m128)xmmword_141A711B0);
}

// File Line: 95
// RVA: 0xCF8670
void __fastcall hkpCapsuleShape::convertVertexIdsToVertices(
        hkpCapsuleShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // r10d
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
void __fastcall hkpCapsuleShape::getSupportingVertex(
        hkpCapsuleShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  hkVector4f v5; // [rsp+0h] [rbp-28h]
  hkVector4f v6; // [rsp+10h] [rbp-18h]

  v5.m_quad = (__m128)this->m_vertexA;
  v6.m_quad = (__m128)this->m_vertexB;
  v3 = _mm_mul_ps(_mm_sub_ps(v6.m_quad, v5.m_quad), direction->m_quad);
  v5.m_quad.m128_i32[3] = 1056964608;
  v6.m_quad.m128_i32[3] = 1056964624;
  v4 = _mm_cmplt_ps(
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170)),
         (__m128)0i64);
  supportingVertexOut->m_quad = _mm_or_ps(_mm_and_ps(v4, v5.m_quad), _mm_andnot_ps(v4, v6.m_quad));
}

