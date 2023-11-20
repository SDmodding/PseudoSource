// File Line: 15
// RVA: 0xE2AFC0
void __fastcall hkpVehicleDefaultTransmission::hkpVehicleDefaultTransmission(hkpVehicleDefaultTransmission *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultTransmission::`vftable';
  this->m_gearsRatio.m_capacityAndFlags = 2147483648;
  this->m_gearsRatio.m_data = 0i64;
  this->m_gearsRatio.m_size = 0;
  this->m_wheelsTorqueRatio.m_data = 0i64;
  this->m_wheelsTorqueRatio.m_size = 0;
  this->m_wheelsTorqueRatio.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_downshiftRPM = 0i64;
  *(_QWORD *)&this->m_primaryTransmissionRatio = 0i64;
  this->m_reverseGearRatio = 0.0;
}

// File Line: 26
// RVA: 0xE2B440
float __fastcall hkpVehicleDefaultTransmission::getCurrentRatio(hkpVehicleDefaultTransmission *this, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  float result; // xmm0_4

  if ( transmissionOut->m_isReversing.m_bool )
    result = COERCE_FLOAT(LODWORD(this->m_reverseGearRatio) ^ _xmm[0]) * this->m_primaryTransmissionRatio;
  else
    result = this->m_gearsRatio.m_data[transmissionOut->m_currentGear] * this->m_primaryTransmissionRatio;
  return result;
}

// File Line: 38
// RVA: 0xE2B0E0
float __fastcall hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatio(const float vehicleTopSpeedMPH, const float wheelRadius, const float maxEngineRpm, const float topGearRatio)
{
  return (float)(maxEngineRpm
               / (float)((float)((float)((float)((float)(vehicleTopSpeedMPH * 1.609) * 0.27777779) / wheelRadius) * 60.0)
                       * 0.15915494))
       / topGearRatio;
}

// File Line: 55
// RVA: 0xE2B120
void __fastcall hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatioKPH(const float vehicleTopSpeedKPH, const float wheelRadius, const float maxEngineRpm, const float topGearRatio)
{
  hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatio(
    vehicleTopSpeedKPH * 0.62099999,
    wheelRadius,
    maxEngineRpm,
    topGearRatio);
}

// File Line: 60
// RVA: 0xE2B010
void __usercall hkpVehicleDefaultTransmission::calcTransmission(hkpVehicleDefaultTransmission *this@<rcx>, const float deltaTime@<xmm1>, hkpVehicleInstance *vehicle@<r8>, hkpVehicleTransmission::TransmissionOutput *transmissionOut@<r9>, float a5@<xmm0>)
{
  hkpVehicleTransmission::TransmissionOutput *v5; // rdi
  hkpVehicleInstance *v6; // rsi
  hkpVehicleDefaultTransmission *v7; // rbx
  __int64 v8; // rdx
  __int64 v9; // rcx
  char v10; // [rsp+40h] [rbp+8h]

  v5 = transmissionOut;
  v6 = vehicle;
  v7 = this;
  transmissionOut->m_isReversing.m_bool = *(_BYTE *)this->vfptr[3].__vecDelDtor(
                                                      (hkBaseObject *)this,
                                                      (unsigned int)&v10);
  ((void (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))v7->vfptr[2].__vecDelDtor)(
    v7,
    v6,
    v5);
  v5->m_mainTransmittedTorque = a5;
  ((void (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))v7->vfptr[2].__first_virtual_table_function__)(
    v7,
    v6,
    v5);
  v8 = 0i64;
  v5->m_transmissionRPM = a5;
  if ( v7->m_wheelsTorqueRatio.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v8 = (unsigned int)(v8 + 1);
      ++v9;
      v5->m_wheelsTransmittedTorque[v9 - 1] = v7->m_wheelsTorqueRatio.m_data[v9 - 1] * v5->m_mainTransmittedTorque;
    }
    while ( (signed int)v8 < v7->m_wheelsTorqueRatio.m_size );
  }
  ((void (__fastcall *)(hkpVehicleDefaultTransmission *, __int64, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))v7->vfptr[3].__first_virtual_table_function__)(
    v7,
    v8,
    v6,
    v5);
}

// File Line: 79
// RVA: 0xE2B140
float __usercall hkpVehicleDefaultTransmission::calcMainTransmittedTorque@<xmm0>(hkpVehicleDefaultTransmission *this@<rcx>, hkpVehicleInstance *vehicle@<rdx>, hkpVehicleTransmission::TransmissionOutput *transmissionOut@<r8>, float a4@<xmm0>)
{
  float v5; // xmm6_4

  if ( transmissionOut->m_delayed.m_bool )
    return 0.0;
  v5 = vehicle->m_torque;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  return a4 * v5;
}

// File Line: 94
// RVA: 0xE2B180
float __usercall hkpVehicleDefaultTransmission::calcTransmissionRPM@<xmm0>(hkpVehicleDefaultTransmission *this@<rcx>, hkpVehicleInstance *vehicle@<rdx>, hkpVehicleTransmission::TransmissionOutput *transmissionOut@<r8>, float a4@<xmm0>)
{
  __int64 v4; // r9
  hkpVehicleTransmission::TransmissionOutput *v5; // rbp
  __int64 v6; // r10
  hkpVehicleInstance *v7; // r11
  hkpVehicleDefaultTransmission *v8; // rbx
  float v9; // xmm6_4
  hkpVehicleInstance::WheelInfo *v10; // r8
  float *v11; // rsi
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  signed __int64 v15; // rdx
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  int v22; // eax
  __m128 v23; // xmm6
  __int64 v24; // rax
  signed __int64 v25; // rcx
  float v26; // xmm0_4

  v4 = 0i64;
  v5 = transmissionOut;
  v6 = vehicle->m_data->m_numWheels;
  v7 = vehicle;
  v8 = this;
  v9 = 0.0;
  if ( (signed int)v6 > 0 )
  {
    if ( (unsigned int)v6 >= 8 )
    {
      v10 = vehicle->m_wheelsInfo.m_data;
      v11 = this->m_wheelsTorqueRatio.m_data;
      v12 = 0i64;
      v13 = _mm_shuffle_ps((__m128)0x42700000u, (__m128)0x42700000u, 0);
      v14 = _mm_shuffle_ps((__m128)0x3E22F983u, (__m128)0x3E22F983u, 0);
      v15 = 2i64;
      do
      {
        v16 = (__m128)LODWORD(v10[v15].m_noSlipIdealSpinVelocity);
        v17 = _mm_unpacklo_ps(
                (__m128)*((unsigned int *)&v10[v15] - 7),
                (__m128)LODWORD(v10[v15 + 1].m_noSlipIdealSpinVelocity));
        v18 = (__m128)*((unsigned int *)&v10[v15 - 1] - 7);
        v19 = (__m128)LODWORD(v10[v15 + 5].m_noSlipIdealSpinVelocity);
        v15 += 8i64;
        v20 = _mm_unpacklo_ps(v18, v16);
        v21 = *(__m128 *)&v11[(signed int)v4];
        v22 = v4 + 4;
        v4 = (unsigned int)(v4 + 8);
        v12 = _mm_add_ps(
                _mm_add_ps(v12, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_unpacklo_ps(v20, v17), v13), v14), v21)),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_unpacklo_ps(
                        _mm_unpacklo_ps(
                          (__m128)*((unsigned int *)&v10[v15 - 5] - 7),
                          (__m128)*((unsigned int *)&v10[v15 - 3] - 7)),
                        _mm_unpacklo_ps((__m128)*((unsigned int *)&v10[v15 - 4] - 7), v19)),
                      v13),
                    v14),
                  *(__m128 *)&v11[v22]));
      }
      while ( (signed int)v4 < (signed int)v6 - (signed int)v6 % 8 );
      v23 = _mm_add_ps(_mm_movehl_ps(v12, v12), v12);
      LODWORD(a4) = (unsigned __int128)_mm_shuffle_ps(v23, v23, 245);
      v9 = v23.m128_f32[0] + a4;
    }
    if ( (signed int)v4 < (signed int)v6 )
    {
      v24 = (signed int)v4;
      v25 = (signed int)v4;
      do
      {
        v26 = v7->m_wheelsInfo.m_data[v25].m_noSlipIdealSpinVelocity;
        ++v24;
        ++v25;
        a4 = (float)((float)(v26 * 60.0) * 0.15915494) * v8->m_wheelsTorqueRatio.m_data[v24 - 1];
        v9 = v9 + a4;
      }
      while ( v24 < v6 );
    }
  }
  ((void (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *, __int64))v8->vfptr[4].__vecDelDtor)(
    v8,
    v7,
    v5,
    v4);
  return fmaxf(0.0, a4 * v9);
}

// File Line: 126
// RVA: 0xE2B3C0
void __fastcall hkpVehicleDefaultTransmission::updateCurrentGear(hkpVehicleDefaultTransmission *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  bool v4; // zf
  float v5; // xmm2_4
  float v6; // xmm0_4
  char v7; // al
  float v8; // eax
  int v9; // edx
  float v10; // eax

  v4 = transmissionOut->m_delayed.m_bool == 0;
  v5 = transmissionOut->m_clutchDelayCountdown - deltaTime;
  transmissionOut->m_clutchDelayCountdown = v5;
  if ( !v4 && v5 <= 0.0 )
    transmissionOut->m_delayed.m_bool = 0;
  if ( !transmissionOut->m_isReversing.m_bool )
  {
    v6 = transmissionOut->m_transmissionRPM;
    if ( transmissionOut->m_transmissionRPM < this->m_downshiftRPM )
    {
      v7 = transmissionOut->m_currentGear;
      if ( v7 > 0 )
      {
        transmissionOut->m_currentGear = v7 - 1;
        v8 = this->m_clutchDelayTime;
        transmissionOut->m_delayed.m_bool = 1;
        transmissionOut->m_clutchDelayCountdown = v8;
      }
    }
    if ( v6 > this->m_upshiftRPM )
    {
      v9 = transmissionOut->m_currentGear;
      if ( v9 + 1 < this->m_gearsRatio.m_size )
      {
        transmissionOut->m_currentGear = v9 + 1;
        v10 = this->m_clutchDelayTime;
        transmissionOut->m_delayed.m_bool = 1;
        transmissionOut->m_clutchDelayCountdown = v10;
      }
    }
  }
}

// File Line: 155
// RVA: 0xE2B390
hkBool *__fastcall hkpVehicleDefaultTransmission::calcIsReversing(hkpVehicleDefaultTransmission *this, hkBool *result, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  hkBool *v4; // rax

  if ( vehicle->m_tryingToReverse.m_bool && transmissionOut->m_currentGear <= 0 )
  {
    result->m_bool = 1;
    v4 = result;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

