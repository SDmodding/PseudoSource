// File Line: 49
// RVA: 0x4834F0
float __fastcall UFG::VehicleAerodynamics::calcAerodynamicDrag(UFG::VehicleAerodynamics *this, float forwardVelocity)
{
  return (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(forwardVelocity)) >> 1)
               * (float)((float)((float)(this->mDragBoost + this->m_dragCoefficient) * (float)(this->m_airDensity * -0.5))
                       * this->m_frontalArea))
       * forwardVelocity;
}

// File Line: 60
// RVA: 0x483530
void __fastcall UFG::VehicleAerodynamics::calcAerodynamics(
        UFG::VehicleAerodynamics *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *dragInfoOut)
{
  hkpEntity *m_entity; // rdi
  __m128 m_quad; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  hkpVehicleData *m_data; // rax
  __m128 v11; // xmm0
  __m128 v12; // xmm10
  __m128 v13; // xmm8
  __m128 v14; // xmm9
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  float v19; // xmm6_4
  __m128 v20; // xmm0
  __m128 v21; // xmm6

  m_entity = vehicle->m_entity;
  m_quad = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v8 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
  v9 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  m_data = vehicle->m_data;
  v11 = m_data->m_chassisOrientation.m_col0.m_quad;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 0),
              v9),
            _mm_mul_ps(
              _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 85),
              v8)),
          _mm_mul_ps(
            _mm_shuffle_ps(m_data->m_chassisOrientation.m_col1.m_quad, m_data->m_chassisOrientation.m_col1.m_quad, 170),
            m_quad));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), m_quad);
  v14 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v9), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v8));
  v15 = _mm_mul_ps(m_entity->m_motion.m_linearVelocity.m_quad, v12);
  v16 = _mm_shuffle_ps(v15, v15, 0);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), v16), _mm_shuffle_ps(v15, v15, 170));
  *(double *)v16.m128_u64 = ((double (__fastcall *)(UFG::VehicleAerodynamics *))this->vfptr[2].__vecDelDtor)(this);
  v18 = v17;
  v19 = v16.m128_f32[0];
  *(double *)v16.m128_u64 = ((double (__fastcall *)(UFG::VehicleAerodynamics *))this->vfptr[2].__first_virtual_table_function__)(this);
  v18.m128_f32[0] = v16.m128_f32[0];
  v16.m128_f32[0] = v19;
  v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v12);
  dragInfoOut->m_aerodynamicsForce.m_quad = _mm_add_ps(
                                              _mm_mul_ps(_mm_add_ps(v14, v13), _mm_shuffle_ps(v18, v18, 0)),
                                              v20);
  v21 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)LODWORD(this->mExtraGravityMultiplier),
            (__m128)LODWORD(this->mExtraGravityMultiplier),
            0),
          this->m_extraGravityws.m_quad);
  v20.m128_f32[0] = hkpMotion::getMass(&m_entity->m_motion);
  dragInfoOut->m_aerodynamicsForce.m_quad = _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v21),
                                              dragInfoOut->m_aerodynamicsForce.m_quad);
  dragInfoOut->m_aerodynamicsTorque = 0i64;
}

