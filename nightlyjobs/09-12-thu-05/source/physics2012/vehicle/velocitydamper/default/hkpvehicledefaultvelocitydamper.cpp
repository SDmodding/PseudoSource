// File Line: 17
// RVA: 0xE2AEC0
void __fastcall hkpVehicleDefaultVelocityDamper::hkpVehicleDefaultVelocityDamper(hkpVehicleDefaultVelocityDamper *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_collisionThreshold = 1.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultVelocityDamper::`vftable;
  *(_QWORD *)&this->m_normalSpinDamping = 0i64;
}

// File Line: 25
// RVA: 0xE2AEF0
void __fastcall hkpVehicleDefaultVelocityDamper::applyVelocityDamping(
        hkpVehicleDefaultVelocityDamper *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle)
{
  hkpEntity *m_entity; // rbx
  __m128 m_quad; // xmm4
  __m128 v5; // xmm2
  float v6; // xmm2_4
  __m128 v7; // [rsp+20h] [rbp-18h] BYREF

  m_entity = vehicle->m_entity;
  m_quad = m_entity->m_motion.m_angularVelocity.m_quad;
  v5 = _mm_mul_ps(m_quad, m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
             + _mm_shuffle_ps(v5, v5, 170).m128_f32[0]) <= (float)(this->m_collisionThreshold
                                                                 * this->m_collisionThreshold) )
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * this->m_normalSpinDamping));
  else
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * this->m_collisionSpinDamping));
  v7 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0), m_quad);
  hkpEntity::activate(m_entity);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))m_entity->m_motion.vfptr[9].__first_virtual_table_function__)(
    &m_entity->m_motion,
    &v7);
}

