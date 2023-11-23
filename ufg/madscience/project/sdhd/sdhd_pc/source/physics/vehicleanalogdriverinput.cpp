// File Line: 21
// RVA: 0x4834A0
float __fastcall UFG::VehicleAnalogDriverInput::calcAcceleratorInput(
        UFG::VehicleAnalogDriverInput *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  char m_bool; // al
  float m_positionY; // xmm0_4

  m_bool = vehicle->m_isReversing.m_bool;
  if ( m_bool && this->m_autoReverse.m_bool )
    LODWORD(m_positionY) = LODWORD(deviceStatus->m_positionY) ^ _xmm[0];
  else
    m_positionY = deviceStatus->m_positionY;
  if ( !this->m_autoReverse.m_bool && m_bool )
    return *(float *)&FLOAT_1_0;
  if ( m_positionY <= 0.0 )
    return m_positionY * -1.0;
  return 0.0;
}

// File Line: 43
// RVA: 0x483690
float __fastcall UFG::VehicleAnalogDriverInput::calcBrakeInput(
        UFG::VehicleAnalogDriverInput *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float result; // xmm0_4

  if ( vehicle->m_isReversing.m_bool && this->m_autoReverse.m_bool )
    LODWORD(result) = LODWORD(deviceStatus->m_positionY) ^ _xmm[0];
  else
    result = deviceStatus->m_positionY;
  if ( result < 0.0 )
    return 0.0;
  return result;
}

// File Line: 60
// RVA: 0x4840C0
float __fastcall UFG::VehicleAnalogDriverInput::calcSteeringInput(
        UFG::VehicleAnalogDriverInput *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float m_deadZone; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm2_4

  m_deadZone = this->m_deadZone;
  LODWORD(v5) = (unsigned int)(2 * LODWORD(deviceStatus->m_positionX)) >> 1;
  if ( v5 < m_deadZone )
    return 0.0;
  if ( deviceStatus->m_positionX <= 0.0 )
    v6 = FLOAT_N1_0;
  else
    v6 = *(float *)&FLOAT_1_0;
  if ( v5 <= m_deadZone )
    v5 = 0.0;
  return v5 * v6;
}

// File Line: 84
// RVA: 0x484280
hkBool *__fastcall UFG::VehicleAnalogDriverInput::calcTryingToReverse(
        UFG::VehicleAnalogDriverInput *this,
        hkBool *result,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  hkBool *v5; // rax
  hkpEntity *m_entity; // r10
  __m128 m_quad; // xmm7
  __m128 v8; // xmm5
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  float v11; // xmm4_4
  bool v12; // cl
  hkVector4f v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm3

  if ( !this->m_autoReverse.m_bool )
  {
    v5 = result;
    result->m_bool = (char)deviceStatus->m_reverseButtonPressed;
    return v5;
  }
  m_entity = vehicle->m_entity;
  m_quad = m_entity->m_motion.m_linearVelocity.m_quad;
  v8 = _mm_mul_ps(m_quad, m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_andnot_ps(
          _mm_cmple_ps(v9, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10)),
            v9)).m128_f32[0];
  v12 = v11 < 1.388889;
  if ( deviceStatus->m_positionY <= 0.1 )
    goto LABEL_16;
  if ( v11 <= 0.00000011920929 )
    goto LABEL_16;
  v13.m_quad = (__m128)vehicle->m_data->m_chassisOrientation.m_col1;
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85),
              m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0),
              m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
            m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          m_quad,
          _mm_andnot_ps(
            _mm_cmple_ps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16))));
  v18 = _mm_mul_ps(v14, v14);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))),
            v14),
          v17);
  if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) >= 0.00000011920929 )
  {
LABEL_16:
    if ( vehicle->m_isReversing.m_bool )
    {
      if ( v12 )
      {
        result->m_bool = deviceStatus->m_positionY > 0.1;
        return result;
      }
    }
    else if ( !v12 || deviceStatus->m_positionY <= 0.1 )
    {
      result->m_bool = 0;
      return result;
    }
  }
  result->m_bool = 1;
  return result;
}

// File Line: 144
// RVA: 0x4839A0
void __fastcall UFG::VehicleAnalogDriverInput::calcDriverInput(
        UFG::VehicleAnalogDriverInput *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputStatus *deviceStatus,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInputOut)
{
  hkpVehicleDriverInput::FilteredDriverInputOutput *v5; // rbp
  double v9; // xmm0_8
  __int64 v10; // rdx
  double v11; // xmm0_8
  __int64 v12; // rdx
  double v13; // xmm0_8
  __int64 v14; // r8

  v5 = filteredInputOut;
  v9 = ((double (__fastcall *)(UFG::VehicleAnalogDriverInput *))this->vfptr[2].__vecDelDtor)(this);
  v5->m_acceleratorPedalInput = *(float *)&v9;
  v11 = ((double (__fastcall *)(UFG::VehicleAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[2].__first_virtual_table_function__)(
          this,
          v10,
          vehicle,
          deviceStatus,
          v5);
  v5->m_brakePedalInput = *(float *)&v11;
  v13 = ((double (__fastcall *)(UFG::VehicleAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[3].__first_virtual_table_function__)(
          this,
          v12,
          vehicle,
          deviceStatus,
          v5);
  v5->m_steeringWheelInput = *(float *)&v13;
  v5->m_handbrakeOn.m_bool = deviceStatus[1].m_memSizeAndFlags;
  v5->m_tryingToReverse.m_bool = *(_BYTE *)((__int64 (__fastcall *)(UFG::VehicleAnalogDriverInput *, hkpVehicleDriverInput::FilteredDriverInputOutput **, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[3].__vecDelDtor)(
                                             this,
                                             &filteredInputOut,
                                             v14,
                                             vehicle,
                                             deviceStatus,
                                             v5);
}

