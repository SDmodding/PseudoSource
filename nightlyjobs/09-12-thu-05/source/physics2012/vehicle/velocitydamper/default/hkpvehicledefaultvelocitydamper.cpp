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
void __fastcall hkpVehicleDefaultVelocityDamper::applyVelocityDamping(hkpVehicleDefaultVelocityDamper *this, const float deltaTime, hkpVehicleInstance *vehicle)
{
  hkpEntity *v3; // rbx
  __m128 v4; // xmm4
  __m128 v5; // xmm2
  float v6; // xmm2_4
  __m128 v7; // [rsp+20h] [rbp-18h]

  v3 = vehicle->m_entity;
  v4 = v3->m_motion.m_angularVelocity.m_quad;
  v5 = _mm_mul_ps(v4, v4);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170))) <= (float)(this->m_collisionThreshold
                                                                   * this->m_collisionThreshold) )
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * this->m_normalSpinDamping));
  else
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * this->m_collisionSpinDamping));
  v7 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0), v4);
  hkpEntity::activate(v3);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v3->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v3->m_motion,
    &v7);
}

