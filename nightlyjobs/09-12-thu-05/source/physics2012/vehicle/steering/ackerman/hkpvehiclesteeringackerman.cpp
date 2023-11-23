// File Line: 15
// RVA: 0xE30E30
void __fastcall hkpVehicleSteeringAckerman::hkpVehicleSteeringAckerman(hkpVehicleSteeringAckerman *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleSteeringAckerman::`vftable;
  this->m_doesWheelSteer.m_capacityAndFlags = 0x80000000;
  this->m_doesWheelSteer.m_data = 0i64;
  this->m_doesWheelSteer.m_size = 0;
  *(_QWORD *)&this->m_maxSteeringAngle = 0i64;
  this->m_wheelBaseLength = 2.4000001;
  this->m_trackWidth = 2.2;
}

// File Line: 23
// RVA: 0xE30EC0
void __fastcall hkpVehicleSteeringAckerman::calcMainSteeringAngle(
        hkpVehicleSteeringAckerman *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpEntity *m_entity; // rdx
  float v8; // xmm0_4
  hkVector4f *p_m_col1; // r8
  float v10; // xmm3_4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm1_4
  hkVector4f v14; // [rsp+20h] [rbp-18h] BYREF

  m_entity = vehicle->m_entity;
  v8 = filteredInfoOutput->m_steeringWheelInput * this->m_maxSteeringAngle;
  p_m_col1 = &vehicle->m_data->m_chassisOrientation.m_col1;
  steeringOutput->m_mainSteeringAngle = v8;
  steeringOutput->m_mainSteeringAngleAssumingNoReduction = v8;
  hkVector4f::setRotatedDir(&v14, &m_entity->m_motion.m_motionState.m_transform.m_rotation, p_m_col1);
  v10 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_maxSpeedFullSteeringAngle),
          (__m128)LODWORD(this->m_maxSpeedFullSteeringAngle),
          0).m128_f32[0];
  v11 = _mm_mul_ps(vehicle->m_entity->m_motion.m_linearVelocity.m_quad, v14.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  if ( v12.m128_f32[0] > v10 )
  {
    v13 = _mm_rcp_ps(v12).m128_f32[0];
    steeringOutput->m_mainSteeringAngle = (float)((float)((float)((float)(2.0 - (float)(v13 * v12.m128_f32[0])) * v13)
                                                        * v10)
                                                * (float)((float)((float)(2.0 - (float)(v13 * v12.m128_f32[0])) * v13)
                                                        * v10))
                                        * steeringOutput->m_mainSteeringAngle;
  }
}

// File Line: 49
// RVA: 0xE30E70
void __fastcall hkpVehicleSteeringAckerman::calcSteering(
        hkpVehicleSteeringAckerman *this,
        float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleSteeringAckerman::calcMainSteeringAngle(this, deltaTime, vehicle, filteredInfoOutput, steeringOutput);
  hkpVehicleSteeringAckerman::calcAckermanOuterAngles(this, vehicle, steeringOutput);
}

// File Line: 57
// RVA: 0xE30F80
void __fastcall hkpVehicleSteeringAckerman::calcAckermanOuterAngles(
        hkpVehicleSteeringAckerman *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpEntity *m_entity; // rax
  __m128i si128; // xmm9
  __m128 v8; // xmm2
  __m128i v9; // xmm15
  __m128 v10; // xmm13
  __m128 v11; // xmm12
  __m128 v12; // xmm12
  __m128 v13; // xmm2
  __m128 v14; // xmm10
  __m128i v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm14
  __m128 v18; // xmm11
  float v19; // xmm0_4
  __m128i v20; // xmm12
  float v21; // xmm13_4
  float v22; // xmm4_4
  __int64 v23; // rcx
  int v24; // edx
  __m128 v25; // xmm5
  __m128 v26; // xmm7
  __int64 v27; // r8
  float *m_data; // rax
  __m128 v29; // xmm2
  __m128i v30; // [rsp+30h] [rbp-108h] BYREF
  __m128 v31; // [rsp+40h] [rbp-F8h]
  __m128i v32; // [rsp+50h] [rbp-E8h]
  __m128 v33; // [rsp+60h] [rbp-D8h]
  __m128 m_quad; // [rsp+70h] [rbp-C8h]
  __m128 v35; // [rsp+80h] [rbp-B8h]
  unsigned int v36; // [rsp+148h] [rbp+10h]

  m_entity = vehicle->m_entity;
  m_quad = m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v35 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v36 = (unsigned int)(2 * LODWORD(steeringOutput->m_mainSteeringAngle)) >> 1;
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)v36);
  v30 = _mm_add_epi32(si128, si128);
  v9 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), si128));
  v10 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v9, v30), (__m128i)0i64);
  v11 = _mm_cvtepi32_ps(v9);
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)DP1_0), v8), _mm_mul_ps(v11, *(__m128 *)DP2)),
          _mm_mul_ps(v11, *(__m128 *)DP3));
  v33 = _mm_add_ps((__m128)v36, *(__m128 *)_xmm);
  v13 = _mm_andnot_ps(*(__m128 *)_xmm, v33);
  v14 = _mm_mul_ps(v12, v12);
  v15 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v13, *(__m128 *)_xmm)), si128));
  v16 = _mm_cvtepi32_ps(v15);
  v32 = v15;
  v31 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v15, v30), (__m128i)0i64);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v13), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v18 = _mm_mul_ps(v17, v17);
  v19 = (float)((float)((float)((float)((float)((float)(v14.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                      * v14.m128_f32[0])
                              + -0.16666655)
                      * v14.m128_f32[0])
              * v12.m128_f32[0])
      + v12.m128_f32[0];
  v20 = _mm_load_si128(&v30);
  v21 = COERCE_FLOAT((_mm_andnot_ps(
                        v10,
                        _mm_add_ps(
                          _mm_sub_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(v14, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                    v14),
                                  *(__m128 *)cosCoeff2_0),
                                v14),
                              v14),
                            _mm_mul_ps(v14, *(__m128 *)_xmm)),
                          *(__m128 *)_xmm)).m128_u32[0] | LODWORD(v19) & v10.m128_i32[0]) ^ (_mm_and_si128(
                                                                                               _mm_add_epi32(v20, v20),
                                                                                               v9).m128i_u32[0] << 29) ^ v36 & _xmm[0])
      / COERCE_FLOAT((_mm_andnot_ps(
                        v31,
                        _mm_add_ps(
                          _mm_sub_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(v18, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                    v18),
                                  *(__m128 *)cosCoeff2_0),
                                v18),
                              v18),
                            _mm_mul_ps(v18, *(__m128 *)_xmm)),
                          *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                            (float)((float)((float)((float)((float)((float)(v18.m128_f32[0] * -0.00019515296)
                                                                                                  + 0.0083321612)
                                                                                          * v18.m128_f32[0])
                                                                                  + -0.16666655)
                                                                          * v18.m128_f32[0])
                                                                  * v17.m128_f32[0])
                                                          + v17.m128_f32[0]) & v31.m128_i32[0]) ^ (_mm_and_si128(
                                                                                                     _mm_add_epi32(v20, v20),
                                                                                                     v15).m128i_u32[0] << 29) ^ v33.m128_i32[0] & _xmm[0]);
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v21)) >> 1) >= 0.00000011920929 )
    v22 = atan2f(1.0, (float)(this->m_trackWidth / this->m_wheelBaseLength) + (float)(1.0 / v21));
  else
    v22 = 0.0;
  if ( steeringOutput->m_mainSteeringAngle < 0.0 )
    LODWORD(v22) ^= _xmm[0];
  v23 = 0i64;
  v24 = 0;
  if ( this->m_doesWheelSteer.m_size > 0 )
  {
    v25 = m_quad;
    v26 = v35;
    v27 = 0i64;
    do
    {
      if ( this->m_doesWheelSteer.m_data[v23].m_bool )
      {
        m_data = steeringOutput->m_wheelsSteeringAngle.m_data;
        v29 = _mm_mul_ps(_mm_sub_ps(vehicle->m_wheelsInfo.m_data[v27].m_hardPointWs.m_quad, v25), v26);
        if ( (float)((float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                           + _mm_shuffle_ps(v29, v29, 170).m128_f32[0])
                   * steeringOutput->m_mainSteeringAngle) >= 0.00000011920929 )
          m_data[v23] = steeringOutput->m_mainSteeringAngle;
        else
          m_data[v23] = v22;
      }
      else
      {
        steeringOutput->m_wheelsSteeringAngle.m_data[v23] = 0.0;
      }
      ++v24;
      ++v23;
      ++v27;
    }
    while ( v24 < this->m_doesWheelSteer.m_size );
  }
}

