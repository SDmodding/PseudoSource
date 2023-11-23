// File Line: 16
// RVA: 0xE26010
void __fastcall hkpVehicleDefaultAerodynamics::hkpVehicleDefaultAerodynamics(hkpVehicleDefaultAerodynamics *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultAerodynamics::`vftable;
  this->m_extraGravityws = 0i64;
  *(_QWORD *)&this->m_airDensity = 0i64;
  *(_QWORD *)&this->m_dragCoefficient = 0i64;
}

// File Line: 26
// RVA: 0xE261B0
float __fastcall hkpVehicleDefaultAerodynamics::calcAerodynamicDrag(
        hkpVehicleDefaultAerodynamics *this,
        float forwardVelocity)
{
  return (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(forwardVelocity)) >> 1)
               * (float)((float)((float)(this->m_airDensity * -0.5) * this->m_dragCoefficient) * this->m_frontalArea))
       * forwardVelocity;
}

// File Line: 33
// RVA: 0xE261F0
float __fastcall hkpVehicleDefaultAerodynamics::calcAerodynamicLift(
        hkpVehicleDefaultAerodynamics *this,
        float forwardVelocity)
{
  return (float)((float)((float)((float)(this->m_airDensity * 0.5) * this->m_liftCoefficient) * this->m_frontalArea)
               * forwardVelocity)
       * forwardVelocity;
}

// File Line: 39
// RVA: 0xE26040
void __fastcall hkpVehicleDefaultAerodynamics::calcAerodynamics(
        hkpVehicleDefaultAerodynamics *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *dragInfoOut)
{
  hkpEntity *m_entity; // rbx
  hkpVehicleData *m_data; // rax
  __m128 m_quad; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm9
  __m128 v13; // xmm8
  __m128 v14; // xmm7
  unsigned int v15; // [rsp+70h] [rbp+8h]
  float v16; // [rsp+80h] [rbp+18h]

  m_entity = vehicle->m_entity;
  m_data = vehicle->m_data;
  m_quad = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v9 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
  v10 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v11 = m_data->m_chassisOrientation.m_col0.m_quad;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 0),
              v10),
            _mm_mul_ps(
              _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 85),
              v9)),
          _mm_mul_ps(
            _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 170),
            m_quad));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), m_quad);
  v14 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v10), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v9));
  *(double *)v11.m128_u64 = ((double (__fastcall *)(hkpVehicleDefaultAerodynamics *))this->vfptr[2].__vecDelDtor)(this);
  v15 = v11.m128_i32[0];
  v16 = ((float (__fastcall *)(hkpVehicleDefaultAerodynamics *))this->vfptr[2].__first_virtual_table_function__)(this);
  dragInfoOut->m_aerodynamicsForce.m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps((__m128)LODWORD(v16), (__m128)LODWORD(v16), 0),
                                                _mm_add_ps(v14, v13)),
                                              _mm_mul_ps(_mm_shuffle_ps((__m128)v15, (__m128)v15, 0), v12));
  v11.m128_f32[0] = hkpMotion::getMass(&m_entity->m_motion);
  dragInfoOut->m_aerodynamicsForce.m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps((__m128)v11.m128_u32[0], (__m128)v11.m128_u32[0], 0),
                                                this->m_extraGravityws.m_quad),
                                              dragInfoOut->m_aerodynamicsForce.m_quad);
  dragInfoOut->m_aerodynamicsTorque = 0i64;
}

