// File Line: 15
// RVA: 0xE2A8B0
void __fastcall hkpVehicleDefaultAnalogDriverInput::hkpVehicleDefaultAnalogDriverInput(
        hkpVehicleDefaultAnalogDriverInput *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultAnalogDriverInput::`vftable;
  *(_QWORD *)&this->m_slopeChangePointX = 0i64;
  this->m_deadZone = 0.0;
  this->m_autoReverse.m_bool = 0;
}

// File Line: 24
// RVA: 0xE2A850
hkpVehicleDriverInputStatus *__fastcall hkpVehicleDriverInputAnalogStatus::clone(
        hkpVehicleDriverInputAnalogStatus *this)
{
  _QWORD **Value; // rax
  hkpVehicleDriverInputStatus *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpVehicleDriverInputStatus *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                            Value[11],
                                            32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDriverInputAnalogStatus::`vftable;
  }
  *(float *)&result[1].vfptr = this->m_positionX;
  HIDWORD(result[1].vfptr) = LODWORD(this->m_positionY);
  LOBYTE(result[1].m_memSizeAndFlags) = this->m_handbrakeButtonPressed.m_bool;
  HIBYTE(result[1].m_memSizeAndFlags) = this->m_reverseButtonPressed.m_bool;
  return result;
}

// File Line: 37
// RVA: 0xE2A9A0
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcAcceleratorInput(
        hkpVehicleDefaultAnalogDriverInput *this,
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

// File Line: 59
// RVA: 0xE2AA00
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcBrakeInput(
        hkpVehicleDefaultAnalogDriverInput *this,
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

// File Line: 76
// RVA: 0xE2AD30
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcSteeringInput(
        hkpVehicleDefaultAnalogDriverInput *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float m_deadZone; // xmm7_4
  float result; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm5_4

  m_deadZone = this->m_deadZone;
  result = 0.0;
  LODWORD(v6) = (unsigned int)(2 * LODWORD(deviceStatus->m_positionX)) >> 1;
  if ( v6 >= m_deadZone )
  {
    if ( deviceStatus->m_positionX <= 0.0 )
      v7 = FLOAT_N1_0;
    else
      v7 = *(float *)&FLOAT_1_0;
    if ( v6 >= this->m_slopeChangePointX )
      return (float)((float)((float)((float)(1.0
                                           - (float)((float)(this->m_slopeChangePointX - m_deadZone)
                                                   * this->m_initialSlope))
                                   / (float)((float)(1.0 - m_deadZone) - (float)(this->m_slopeChangePointX - m_deadZone)))
                           * (float)(v6 - this->m_slopeChangePointX))
                   + (float)((float)(this->m_slopeChangePointX - m_deadZone) * this->m_initialSlope))
           * v7;
    else
      return (float)((float)(v6 - m_deadZone) * this->m_initialSlope) * v7;
  }
  return result;
}

// File Line: 118
// RVA: 0xE2AA40
hkBool *__fastcall hkpVehicleDefaultAnalogDriverInput::calcTryingToReverse(
        hkpVehicleDefaultAnalogDriverInput *this,
        hkBool *result,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  hkBool *v6; // rax
  __int64 m_size; // r10
  hkpEntity *m_entity; // rdi
  int v9; // r9d
  __int64 v10; // r8
  __m128 m_quad; // xmm6
  hkpVehicleInstance::WheelInfo *m_data; // rbx
  __m128 **p_m_contactBody; // rax
  __m128 *v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  float v20; // xmm4_4
  bool v21; // r8
  hkVector4f v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm6
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm3

  if ( !this->m_autoReverse.m_bool )
  {
    v6 = result;
    result->m_bool = (char)deviceStatus->m_reverseButtonPressed;
    return v6;
  }
  m_size = vehicle->m_wheelsInfo.m_size;
  m_entity = vehicle->m_entity;
  v9 = 0;
  v10 = 0i64;
  m_quad = m_entity->m_motion.m_linearVelocity.m_quad;
  if ( m_size > 0 )
  {
    m_data = vehicle->m_wheelsInfo.m_data;
    p_m_contactBody = (__m128 **)&m_data->m_contactBody;
    while ( 1 )
    {
      v14 = *p_m_contactBody;
      if ( *p_m_contactBody )
      {
        if ( v14[22].m128_i8[0] != 5 )
          break;
      }
      ++v10;
      ++v9;
      p_m_contactBody += 28;
      if ( v10 >= m_size )
        goto LABEL_10;
    }
    v15 = _mm_sub_ps(m_data[v9].m_contactPoint.m_position.m_quad, v14[28]);
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14[36]),
            _mm_mul_ps(_mm_shuffle_ps(v14[36], v14[36], 201), v15));
    m_quad = _mm_sub_ps(m_quad, _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), v14[35]));
  }
LABEL_10:
  v17 = _mm_mul_ps(m_quad, m_quad);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_andnot_ps(
          _mm_cmple_ps(v18, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19)),
            v18)).m128_f32[0];
  v21 = v20 < _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_388889), (__m128)LODWORD(FLOAT_1_388889), 0).m128_f32[0];
  if ( deviceStatus->m_positionY > 0.1 && v20 > 0.00000011920929 )
  {
    v22.m_quad = (__m128)vehicle->m_data->m_chassisOrientation.m_col1;
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v22.m_quad, v22.m_quad, 85),
                m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v22.m_quad, v22.m_quad, 0),
                m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v22.m_quad, v22.m_quad, 170),
              m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v24 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v25 = _mm_rsqrt_ps(v24);
    v26 = _mm_mul_ps(
            m_quad,
            _mm_andnot_ps(
              _mm_cmple_ps(v24, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                _mm_mul_ps(*(__m128 *)_xmm, v25))));
    v27 = _mm_mul_ps(v23, v23);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = _mm_rsqrt_ps(v28);
    v30 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v28, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                  _mm_mul_ps(*(__m128 *)_xmm, v29))),
              v23),
            v26);
    if ( (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
               + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) < 0.00000011920929 )
      goto LABEL_13;
  }
  if ( !vehicle->m_isReversing.m_bool )
  {
    if ( !v21 || deviceStatus->m_positionY <= 0.1 )
    {
      result->m_bool = 0;
      return result;
    }
LABEL_13:
    result->m_bool = 1;
    return result;
  }
  v6 = result;
  result->m_bool = !v21 || deviceStatus->m_positionY > 0.1;
  return v6;
}

// File Line: 194
// RVA: 0xE2A8E0
void __fastcall hkpVehicleDefaultAnalogDriverInput::calcDriverInput(
        hkpVehicleDefaultAnalogDriverInput *this,
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
  v9 = ((double (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *))this->vfptr[2].__vecDelDtor)(this);
  v5->m_acceleratorPedalInput = *(float *)&v9;
  v11 = ((double (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[2].__first_virtual_table_function__)(
          this,
          v10,
          vehicle,
          deviceStatus,
          v5);
  v5->m_brakePedalInput = *(float *)&v11;
  v13 = ((double (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[3].__first_virtual_table_function__)(
          this,
          v12,
          vehicle,
          deviceStatus,
          v5);
  v5->m_steeringWheelInput = *(float *)&v13;
  v5->m_handbrakeOn.m_bool = deviceStatus[1].m_memSizeAndFlags;
  v5->m_tryingToReverse.m_bool = *(_BYTE *)((__int64 (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, hkpVehicleDriverInput::FilteredDriverInputOutput **, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->vfptr[3].__vecDelDtor)(
                                             this,
                                             &filteredInputOut,
                                             v14,
                                             vehicle,
                                             deviceStatus,
                                             v5);
}

