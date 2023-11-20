// File Line: 53
// RVA: 0x488650
void __fastcall hkpContactPointEvent::setNormal(hkpContactPointEvent *this, hkVector4f *normal)
{
  hkContactPoint *v2; // rax
  __m128 v3; // xmm1
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h]

  v2 = this->m_contactPoint;
  v3 = _mm_mul_ps(v2->m_separatingNormal.m_quad, normal->m_quad);
  v2->m_separatingNormal.m_quad = _mm_shuffle_ps(
                                    normal->m_quad,
                                    _mm_unpackhi_ps(
                                      normal->m_quad,
                                      _mm_mul_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)),
                                          _mm_shuffle_ps(v3, v3, 170)),
                                        _mm_shuffle_ps(
                                          v2->m_separatingNormal.m_quad,
                                          v2->m_separatingNormal.m_quad,
                                          255))),
                                    196);
  if ( this->m_separatingVelocity )
    *(_DWORD *)this->m_separatingVelocity = *hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
                                               &result,
                                               this->m_bodies[0],
                                               this->m_bodies[1],
                                               &this->m_bodies[0]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                                               &this->m_bodies[1]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                                               this->m_contactPoint);
}

