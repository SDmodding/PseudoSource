// File Line: 19
// RVA: 0xD63B90
hkSimdFloat32 *__fastcall hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(hkSimdFloat32 *result, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkVector4f *centerOfMassInWorldA, hkVector4f *centerOfMassInWorldB, hkContactPoint *cp)
{
  __m128 v6; // xmm2
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm3

  v6 = _mm_sub_ps(cp->m_position.m_quad, centerOfMassInWorldB->m_quad);
  v7 = result;
  v8 = _mm_sub_ps(cp->m_position.m_quad, centerOfMassInWorldA->m_quad);
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), bodyA->m_motion.m_angularVelocity.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(bodyA->m_motion.m_angularVelocity.m_quad, bodyA->m_motion.m_angularVelocity.m_quad, 201),
           v8));
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), bodyB->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(bodyB->m_motion.m_angularVelocity.m_quad, bodyB->m_motion.m_angularVelocity.m_quad, 201),
            v6));
  v11 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(_mm_shuffle_ps(v9, v9, 201), bodyA->m_motion.m_linearVelocity.m_quad),
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 201), bodyB->m_motion.m_linearVelocity.m_quad)),
          cp->m_separatingNormal.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                     _mm_shuffle_ps(v11, v11, 170));
  return v7;
}

