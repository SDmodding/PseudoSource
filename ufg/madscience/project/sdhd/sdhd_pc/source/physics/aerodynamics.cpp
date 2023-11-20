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
void __fastcall UFG::VehicleAerodynamics::calcAerodynamics(UFG::VehicleAerodynamics *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleAerodynamics::AerodynamicsDragOutput *dragInfoOut)
{
  hkpEntity *v4; // rdi
  hkpVehicleAerodynamics::AerodynamicsDragOutput *v5; // rsi
  __m128 *v6; // rbx
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  hkpVehicleData *v10; // rax
  __m128 v11; // xmm0
  __m128 v12; // xmm10
  __m128 v13; // xmm8
  __m128 v14; // xmm9
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm6

  v4 = vehicle->m_entity;
  v5 = dragInfoOut;
  v6 = (__m128 *)this;
  v7 = v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v8 = v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
  v9 = v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v10 = vehicle->m_data;
  v11 = v10->m_chassisOrientation.m_col0.m_quad;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v10->m_chassisOrientation.m_col1.m_quad, v10->m_chassisOrientation.m_col1.m_quad, 0),
              v9),
            _mm_mul_ps(
              _mm_shuffle_ps(v10->m_chassisOrientation.m_col1.m_quad, v10->m_chassisOrientation.m_col1.m_quad, 85),
              v8)),
          _mm_mul_ps(
            _mm_shuffle_ps(v10->m_chassisOrientation.m_col1.m_quad, v10->m_chassisOrientation.m_col1.m_quad, 170),
            v7));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v7);
  v14 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v9), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v8));
  v15 = _mm_mul_ps(v4->m_motion.m_linearVelocity.m_quad, v12);
  v16 = _mm_shuffle_ps(v15, v15, 0);
  ((void (*)(void))this->vfptr[2].__vecDelDtor)();
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), v16), _mm_shuffle_ps(v15, v15, 170));
  (*(void (__fastcall **)(__m128 *))(v6->m128_u64[0] + 40))(v6);
  v17.m128_f32[0] = v16.m128_f32[0];
  v18 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v12);
  v5->m_aerodynamicsForce.m_quad = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v14, v13), _mm_shuffle_ps(v17, v17, 0)), v18);
  v19 = _mm_mul_ps(_mm_shuffle_ps((__m128)v6[3].m128_u32[1], (__m128)v6[3].m128_u32[1], 0), v6[2]);
  v18.m128_f32[0] = hkpMotion::getMass((hkpMotion *)&v4->m_motion.vfptr);
  v5->m_aerodynamicsForce.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v19),
                                     v5->m_aerodynamicsForce.m_quad);
  v5->m_aerodynamicsTorque = 0i64;
}

