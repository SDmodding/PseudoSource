// File Line: 15
// RVA: 0xE2A8B0
void __fastcall hkpVehicleDefaultAnalogDriverInput::hkpVehicleDefaultAnalogDriverInput(hkpVehicleDefaultAnalogDriverInput *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultAnalogDriverInput::`vftable';
  *(_QWORD *)&this->m_slopeChangePointX = 0i64;
  this->m_deadZone = 0.0;
  this->m_autoReverse.m_bool = 0;
}

// File Line: 24
// RVA: 0xE2A850
hkpVehicleDriverInputStatus *__fastcall hkpVehicleDriverInputAnalogStatus::clone(hkpVehicleDriverInputAnalogStatus *this)
{
  hkpVehicleDriverInputAnalogStatus *v1; // rbx
  _QWORD **v2; // rax
  hkpVehicleDriverInputStatus *result; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpVehicleDriverInputStatus *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                            v2[11],
                                            32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDriverInputAnalogStatus::`vftable';
  }
  *(float *)&result[1].vfptr = v1->m_positionX;
  HIDWORD(result[1].vfptr) = LODWORD(v1->m_positionY);
  LOBYTE(result[1].m_memSizeAndFlags) = v1->m_handbrakeButtonPressed.m_bool;
  HIBYTE(result[1].m_memSizeAndFlags) = v1->m_reverseButtonPressed.m_bool;
  return result;
}

// File Line: 37
// RVA: 0xE2A9A0
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcAcceleratorInput(hkpVehicleDefaultAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
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

// File Line: 59
// RVA: 0xE2AA00
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcBrakeInput(hkpVehicleDefaultAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
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

// File Line: 76
// RVA: 0xE2AD30
float __fastcall hkpVehicleDefaultAnalogDriverInput::calcSteeringInput(hkpVehicleDefaultAnalogDriverInput *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  float v4; // xmm7_4
  float result; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm5_4

  v4 = this->m_deadZone;
  result = 0.0;
  LODWORD(v6) = (unsigned int)(2 * LODWORD(deviceStatus->m_positionX)) >> 1;
  if ( v6 >= v4 )
  {
    if ( deviceStatus->m_positionX <= 0.0 )
      v7 = FLOAT_N1_0;
    else
      v7 = *(float *)&FLOAT_1_0;
    if ( v6 >= this->m_slopeChangePointX )
      result = (float)((float)((float)((float)(1.0
                                             - (float)((float)(this->m_slopeChangePointX - v4) * this->m_initialSlope))
                                     / (float)((float)(1.0 - v4) - (float)(this->m_slopeChangePointX - v4)))
                             * (float)(v6 - this->m_slopeChangePointX))
                     + (float)((float)(this->m_slopeChangePointX - v4) * this->m_initialSlope))
             * v7;
    else
      result = (float)((float)(v6 - v4) * this->m_initialSlope) * v7;
  }
  return result;
}

// File Line: 118
// RVA: 0xE2AA40
hkBool *__fastcall hkpVehicleDefaultAnalogDriverInput::calcTryingToReverse(hkpVehicleDefaultAnalogDriverInput *this, hkBool *result, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInputAnalogStatus *deviceStatus)
{
  hkpVehicleInstance *v5; // r11
  hkBool *v6; // rax
  __int64 v7; // r10
  hkpEntity *v8; // rdi
  int v9; // er9
  __int64 v10; // r8
  __m128 v11; // xmm6
  hkpVehicleInstance::WheelInfo *v12; // rbx
  __m128 **v13; // rax
  __m128 *v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  float v20; // xmm4_4
  bool v21; // r8
  hkVector4f v22; // ST30_16
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm3

  v5 = vehicle;
  if ( !this->m_autoReverse.m_bool )
  {
    v6 = result;
    result->m_bool = (char)deviceStatus->m_reverseButtonPressed;
    return v6;
  }
  v7 = vehicle->m_wheelsInfo.m_size;
  v8 = vehicle->m_entity;
  v9 = 0;
  v10 = 0i64;
  v11 = v8->m_motion.m_linearVelocity.m_quad;
  if ( v7 > 0 )
  {
    v12 = v5->m_wheelsInfo.m_data;
    v13 = (__m128 **)&v12->m_contactBody;
    while ( 1 )
    {
      v14 = *v13;
      if ( *v13 )
      {
        if ( v14[22].m128_i8[0] != 5 )
          break;
      }
      ++v10;
      ++v9;
      v13 += 28;
      if ( v10 >= v7 )
        goto LABEL_10;
    }
    v15 = _mm_sub_ps(v12[v9].m_contactPoint.m_position.m_quad, v14[28]);
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14[36]),
            _mm_mul_ps(_mm_shuffle_ps(v14[36], v14[36], 201), v15));
    v11 = _mm_sub_ps(v11, _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), v14[35]));
  }
LABEL_10:
  v17 = _mm_mul_ps(v11, v11);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  LODWORD(v20) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v18, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                        v18));
  v21 = v20 < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_388889), (__m128)LODWORD(FLOAT_1_388889), 0));
  if ( deviceStatus->m_positionY > 0.1 && v20 > 0.00000011920929 )
  {
    v22.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_translation;
    v23 = v5->m_data->m_chassisOrientation.m_col1.m_quad;
    v24 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v8->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v26 = _mm_rsqrt_ps(v25);
    v27 = _mm_mul_ps(
            v11,
            _mm_andnot_ps(
              _mm_cmpleps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(*(__m128 *)_xmm, v26))));
    v28 = _mm_mul_ps(v24, v24);
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170));
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                  _mm_mul_ps(*(__m128 *)_xmm, v30))),
              v24),
            v27);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 170))) < 0.00000011920929 )
      goto LABEL_13;
  }
  if ( !v5->m_isReversing.m_bool )
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
  if ( v21 )
    result->m_bool = 0.1 < deviceStatus->m_positionY;
  else
    result->m_bool = 1;
  return v6;
}

// File Line: 194
// RVA: 0xE2A8E0
void __usercall hkpVehicleDefaultAnalogDriverInput::calcDriverInput(hkpVehicleDefaultAnalogDriverInput *this@<rcx>, const float deltaTime@<xmm1>, hkpVehicleInstance *vehicle@<r8>, hkpVehicleDriverInputStatus *deviceStatus@<r9>, float a5@<xmm0>, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInputOut)
{
  hkpVehicleDriverInput::FilteredDriverInputOutput *v6; // rbp
  hkpVehicleDriverInputStatus *v7; // rbx
  hkpVehicleInstance *v8; // rdi
  hkpVehicleDefaultAnalogDriverInput *v9; // rsi
  __int64 v10; // rdx
  __int64 v11; // rdx
  __int64 v12; // r8

  v6 = filteredInputOut;
  v7 = deviceStatus;
  v8 = vehicle;
  v9 = this;
  ((void (__cdecl *)(hkpVehicleDefaultAnalogDriverInput *))this->vfptr[2].__vecDelDtor)(this);
  v6->m_acceleratorPedalInput = a5;
  ((void (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[2].__first_virtual_table_function__)(
    v9,
    v10,
    v8,
    v7,
    v6);
  v6->m_brakePedalInput = a5;
  ((void (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[3].__first_virtual_table_function__)(
    v9,
    v11,
    v8,
    v7,
    v6);
  v6->m_steeringWheelInput = a5;
  v6->m_handbrakeOn.m_bool = v7[1].m_memSizeAndFlags;
  v6->m_tryingToReverse.m_bool = *(_BYTE *)((__int64 (__fastcall *)(hkpVehicleDefaultAnalogDriverInput *, hkpVehicleDriverInput::FilteredDriverInputOutput **, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))v9->vfptr[3].__vecDelDtor)(
                                             v9,
                                             &filteredInputOut,
                                             v12,
                                             v8,
                                             v7,
                                             v6);
}

