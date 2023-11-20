// File Line: 15
// RVA: 0xE30E30
void __fastcall hkpVehicleSteeringAckerman::hkpVehicleSteeringAckerman(hkpVehicleSteeringAckerman *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleSteeringAckerman::`vftable';
  this->m_doesWheelSteer.m_capacityAndFlags = 2147483648;
  this->m_doesWheelSteer.m_data = 0i64;
  this->m_doesWheelSteer.m_size = 0;
  *(_QWORD *)&this->m_maxSteeringAngle = 0i64;
  this->m_wheelBaseLength = 2.4000001;
  this->m_trackWidth = 2.2;
}

// File Line: 23
// RVA: 0xE30EC0
void __fastcall hkpVehicleSteeringAckerman::calcMainSteeringAngle(hkpVehicleSteeringAckerman *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleInstance *v5; // rbx
  hkpEntity *v6; // rdx
  hkpVehicleSteeringAckerman *v7; // rdi
  float v8; // xmm0_4
  hkVector4f *v9; // r8
  float v10; // xmm3_4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm1_4
  hkVector4f v14; // [rsp+20h] [rbp-18h]

  v5 = vehicle;
  v6 = vehicle->m_entity;
  v7 = this;
  v8 = filteredInfoOutput->m_steeringWheelInput * this->m_maxSteeringAngle;
  v9 = &vehicle->m_data->m_chassisOrientation.m_col1;
  steeringOutput->m_mainSteeringAngle = v8;
  steeringOutput->m_mainSteeringAngleAssumingNoReduction = v8;
  hkVector4f::setRotatedDir(&v14, (hkMatrix3f *)&v6->m_motion.m_motionState.m_transform.m_rotation.m_col0, v9);
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v7->m_maxSpeedFullSteeringAngle),
                                      (__m128)LODWORD(v7->m_maxSpeedFullSteeringAngle),
                                      0);
  v11 = _mm_mul_ps(v5->m_entity->m_motion.m_linearVelocity.m_quad, v14.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  if ( v12.m128_f32[0] > v10 )
  {
    LODWORD(v13) = (unsigned __int128)_mm_rcp_ps(v12);
    steeringOutput->m_mainSteeringAngle = (float)((float)((float)((float)(2.0 - (float)(v13 * v12.m128_f32[0])) * v13)
                                                        * v10)
                                                * (float)((float)((float)(2.0 - (float)(v13 * v12.m128_f32[0])) * v13)
                                                        * v10))
                                        * steeringOutput->m_mainSteeringAngle;
  }
}

// File Line: 49
// RVA: 0xE30E70
void __fastcall hkpVehicleSteeringAckerman::calcSteering(hkpVehicleSteeringAckerman *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleInstance *v5; // rsi
  hkpVehicleSteeringAckerman *v6; // rdi

  v5 = vehicle;
  v6 = this;
  hkpVehicleSteeringAckerman::calcMainSteeringAngle(this, deltaTime, vehicle, filteredInfoOutput, steeringOutput);
  hkpVehicleSteeringAckerman::calcAckermanOuterAngles(v6, v5, steeringOutput);
}

// File Line: 57
// RVA: 0xE30F80
void __fastcall hkpVehicleSteeringAckerman::calcAckermanOuterAngles(hkpVehicleSteeringAckerman *this, hkpVehicleInstance *vehicle, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpEntity *v3; // rax
  hkpVehicleSteering::SteeringAnglesOutput *v4; // rbx
  hkpVehicleInstance *v5; // rsi
  hkpVehicleSteeringAckerman *v6; // rdi
  __m128i v7; // xmm9
  __m128 v8; // xmm2
  __m128i v9; // xmm14
  __m128i v10; // xmm15
  __m128 v11; // xmm13
  __m128 v12; // xmm12
  __m128 v13; // xmm12
  __m128 v14; // xmm2
  __m128 v15; // xmm10
  __m128i v16; // xmm9
  __m128 v17; // xmm1
  __m128 v18; // xmm14
  __m128 v19; // xmm11
  float v20; // xmm0_4
  __m128i v21; // xmm12
  float v22; // xmm13_4
  float v23; // xmm4_4
  __int64 v24; // rcx
  int v25; // edx
  __m128 v26; // xmm5
  __m128 v27; // xmm7
  __int64 v28; // r8
  float *v29; // rax
  __m128 v30; // xmm2
  __int128 v31; // [rsp+30h] [rbp-108h]
  __m128 v32; // [rsp+40h] [rbp-F8h]
  __int128 v33; // [rsp+50h] [rbp-E8h]
  __m128 v34; // [rsp+60h] [rbp-D8h]
  __m128 v35; // [rsp+70h] [rbp-C8h]
  __m128 v36; // [rsp+80h] [rbp-B8h]
  unsigned int v37; // [rsp+140h] [rbp+8h]

  v3 = vehicle->m_entity;
  v4 = steeringOutput;
  v5 = vehicle;
  v6 = this;
  v35 = v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad;
  v7 = _mm_load_si128((const __m128i *)_xmm);
  v36 = v3->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v37 = (unsigned int)(2 * LODWORD(steeringOutput->m_mainSteeringAngle)) >> 1;
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)v37);
  v9 = _mm_add_epi32(v7, v7);
  _mm_store_si128((__m128i *)&v31, v9);
  v10 = _mm_andnot_si128(v7, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v8, *(__m128 *)_xmm)), v7));
  v11 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v10, v9), (__m128i)0i64);
  v12 = _mm_cvtepi32_ps(v10);
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v12, *(__m128 *)DP1_0), v8), _mm_mul_ps(v12, *(__m128 *)DP2)),
          _mm_mul_ps(v12, *(__m128 *)DP3));
  v34 = _mm_add_ps((__m128)v37, *(__m128 *)_xmm);
  v14 = _mm_andnot_ps(*(__m128 *)_xmm, v34);
  v15 = _mm_mul_ps(v13, v13);
  v16 = _mm_andnot_si128(v7, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v14, *(__m128 *)_xmm)), v7));
  v17 = _mm_cvtepi32_ps(v16);
  _mm_store_si128((__m128i *)&v33, v16);
  v32 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v16, v9), (__m128i)0i64);
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, *(__m128 *)DP1_0), v14), _mm_mul_ps(v17, *(__m128 *)DP2)),
          _mm_mul_ps(v17, *(__m128 *)DP3));
  v19 = _mm_mul_ps(v18, v18);
  v20 = (float)((float)((float)((float)((float)((float)(v15.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                      * v15.m128_f32[0])
                              + -0.16666655)
                      * v15.m128_f32[0])
              * v13.m128_f32[0])
      + v13.m128_f32[0];
  v21 = _mm_load_si128((const __m128i *)&v31);
  v22 = COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                               v11,
                                               _mm_add_ps(
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(v15, *(__m128 *)cosCoeff0_0),
                                                             *(__m128 *)cosCoeff1),
                                                           v15),
                                                         *(__m128 *)cosCoeff2_0),
                                                       v15),
                                                     v15),
                                                   _mm_mul_ps(v15, *(__m128 *)_xmm)),
                                                 *(__m128 *)_xmm)) | LODWORD(v20) & v11.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v21, v21), v10) << 29) ^ v37 & _xmm[0])
      / COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                               v32,
                                               _mm_add_ps(
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(v19, *(__m128 *)cosCoeff0_0),
                                                             *(__m128 *)cosCoeff1),
                                                           v19),
                                                         *(__m128 *)cosCoeff2_0),
                                                       v19),
                                                     v19),
                                                   _mm_mul_ps(v19, *(__m128 *)_xmm)),
                                                 *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                       (float)((float)((float)((float)((float)((float)(v19.m128_f32[0] * -0.00019515296) + 0.0083321612) * v19.m128_f32[0])
                                                                                             + -0.16666655)
                                                                                     * v19.m128_f32[0])
                                                                             * v18.m128_f32[0])
                                                                     + v18.m128_f32[0]) & v32.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v21, v21), v16) << 29) ^ v34.m128_i32[0] & _xmm[0]);
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v22)) >> 1) >= 0.00000011920929 )
    v23 = atan2f(1.0, (float)(this->m_trackWidth / this->m_wheelBaseLength) + (float)(1.0 / v22));
  else
    v23 = 0.0;
  if ( v4->m_mainSteeringAngle < 0.0 )
    LODWORD(v23) ^= _xmm[0];
  v24 = 0i64;
  v25 = 0;
  if ( v6->m_doesWheelSteer.m_size > 0 )
  {
    v26 = v35;
    v27 = v36;
    v28 = 0i64;
    do
    {
      if ( v6->m_doesWheelSteer.m_data[v24].m_bool )
      {
        v29 = v4->m_wheelsSteeringAngle.m_data;
        v30 = _mm_mul_ps(_mm_sub_ps(v5->m_wheelsInfo.m_data[v28].m_hardPointWs.m_quad, v26), v27);
        if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170)))
                   * v4->m_mainSteeringAngle) >= 0.00000011920929 )
          v29[v24] = v4->m_mainSteeringAngle;
        else
          v29[v24] = v23;
      }
      else
      {
        v4->m_wheelsSteeringAngle.m_data[v24] = 0.0;
      }
      ++v25;
      ++v24;
      ++v28;
    }
    while ( v25 < v6->m_doesWheelSteer.m_size );
  }
}

