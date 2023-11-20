// File Line: 12
// RVA: 0xCF2B50
void __fastcall hkpSphereShape::getSupportingVertex(hkpSphereShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  *supportingVertexOut = 0i64;
}

// File Line: 17
// RVA: 0xCF2AB0
void __fastcall hkpSphereShape::convertVertexIdsToVertices(hkpSphereShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  __int64 v4; // rcx
  hkcdVertex *v5; // rax

  v4 = numIds - 1;
  if ( numIds - 1 >= 0 )
  {
    v5 = &verticesOut[numIds - 1];
    do
    {
      --v4;
      *v5 = 0i64;
      --v5;
    }
    while ( v4 >= 0 );
  }
}

// File Line: 25
// RVA: 0xCF2B10
void __fastcall hkpSphereShape::getCentre(hkpSphereShape *this, hkVector4f *centreOut)
{
  *centreOut = 0i64;
}

// File Line: 35
// RVA: 0xCF2AE0
void __fastcall hkpSphereShape::getAabb(hkpSphereShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  __m128 v4; // xmm3

  v4 = _mm_shuffle_ps(
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         0);
  out->m_min.m_quad = _mm_sub_ps(localToWorld->m_translation.m_quad, v4);
  out->m_max.m_quad = _mm_add_ps(localToWorld->m_translation.m_quad, v4);
}

// File Line: 43
// RVA: 0xCF2B20
hkSphere *__fastcall hkpSphereShape::getCollisionSpheres(hkpSphereShape *this, hkSphere *sphereBuffer)
{
  hkSphere *result; // rax

  result = sphereBuffer;
  sphereBuffer->m_pos.m_quad = _mm_shuffle_ps(
                                 aabbOut.m_quad,
                                 _mm_unpackhi_ps(
                                   aabbOut.m_quad,
                                   _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0)),
                                 196);
  return result;
}

