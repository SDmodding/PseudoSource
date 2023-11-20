// File Line: 21
// RVA: 0x4834A0
float __fastcall UFG::VehicleAnalogDriverInput::calcAcceleratorInput(UFG::VehicleAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  char v4; // al
  float v5; // xmm0_4

  v4 = vehicle->m_isReversing.m_bool;
  if ( v4 && this->m_autoReverse.m_bool )
    LODWORD(v5) = LODWORD(deviceStatus->m_positionY) ^ _xmm[0];
  else
    v5 = deviceStatus->m_positionY;
  if ( !this->m_autoReverse.m_bool && v4 )
    return *(float *)&FLOAT_1_0;
  if ( v5 <= 0.0 )
    return v5 * -1.0;
  return 0.0;
}

// File Line: 43
// RVA: 0x483690
float __fastcall UFG::VehicleAnalogDriverInput::calcBrakeInput(UFG::VehicleAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float result; // xmm0_4

  if ( vehicle->m_isReversing.m_bool && this->m_autoReverse.m_bool )
    LODWORD(result) = LODWORD(deviceStatus->m_positionY) ^ _xmm[0];
  else
    result = deviceStatus->m_positionY;
  if ( result < 0.0 )
    result = 0.0;
  return result;
}

// File Line: 60
// RVA: 0x4840C0
float __fastcall UFG::VehicleAnalogDriverInput::calcSteeringInput(UFG::VehicleAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm2_4

  v4 = this->m_deadZone;
  LODWORD(v5) = (unsigned int)(2 * LODWORD(deviceStatus->m_positionX)) >> 1;
  if ( v5 < v4 )
    return 0.0;
  if ( deviceStatus->m_positionX <= 0.0 )
    v6 = FLOAT_N1_0;
  else
    v6 = *(float *)&FLOAT_1_0;
  if ( v5 <= v4 )
    v5 = 0.0;
  return v5 * v6;
}

// File Line: 84
// RVA: 0x484280
hkBool *__fastcall UFG::VehicleAnalogDriverInput::calcTryingToReverse(UFG::VehicleAnalogDriverInput *this, hkBool *result, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  hkBool *v5; // rax
  hkpEntity *v6; // r10
  __m128 v7; // xmm7
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
  v6 = vehicle->m_entity;
  v7 = v6->m_motion.m_linearVelocity.m_quad;
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  LODWORD(v11) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v9, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v10)),
                                        v9));
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
              v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0),
              v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
            v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          v7,
          _mm_andnot_ps(
            _mm_cmpleps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16))));
  v18 = _mm_mul_ps(v14, v14);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))),
            v14),
          v17);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) >= 0.00000011920929 )
  {
LABEL_16:
    if ( vehicle->m_isReversing.m_bool )
    {
      if ( v12 )
      {
        result->m_bool = 0.1 < deviceStatus->m_positionY;
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
void __usercall UFG::VehicleAnalogDriverInput::calcDriverInput(UFG::VehicleAnalogDriverInput *this@<rcx>, const float deltaTime@<xmm1>, hkpVehicleInstance *vehicle@<r8>, hkpVehicleDriverInputStatus *deviceStatus@<r9>, float a5@<xmm0>, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInputOut)
{
  hkpVehicleDriverInput::FilteredDriverInputOutput *v6; // rbp
  hkpVehicleDriverInputStatus *v7; // rbx
  hkpVehicleInstance *v8; // rdi
  UFG::VehicleAnalogDriverInput *v9; // rsi
  __int64 v10; // rdx
  __int64 v11; // rdx
  __int64 v12; // r8

  v6 = filteredInputOut;
  v7 = deviceStatus;
  v8 = vehicle;
  v9 = this;
  ((void (__cdecl *)(UFG::VehicleAnalogDriverInput *))this->vfptr[2].__vecDelDtor)(this);
  v6->m_acceleratorPedalInput = a5;
  ((void (__fastcall *)(UFG::VehicleAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[2].__first_virtual_table_function__)(
    v9,
    v10,
    v8,
    v7,
    v6);
  v6->m_brakePedalInput = a5;
  ((void (__fastcall *)(UFG::VehicleAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[3].__first_virtual_table_function__)(
    v9,
    v11,
    v8,
    v7,
    v6);
  v6->m_steeringWheelInput = a5;
  v6->m_handbrakeOn.m_bool = v7[1].m_memSizeAndFlags;
  v6->m_tryingToReverse.m_bool = *(_BYTE *)((__int64 (__fastcall *)(UFG::VehicleAnalogDriverInput *, hkpVehicleDriverInput::FilteredDriverInputOutput **, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[3].__vecDelDtor)(
                                             v9,
                                             &filteredInputOut,
                                             v12,
                                             v8,
                                             v7,
                                             v6);
}

