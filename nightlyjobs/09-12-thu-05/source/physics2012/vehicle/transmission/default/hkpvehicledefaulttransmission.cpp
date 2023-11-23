// File Line: 15
// RVA: 0xE2AFC0
void __fastcall hkpVehicleDefaultTransmission::hkpVehicleDefaultTransmission(hkpVehicleDefaultTransmission *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultTransmission::`vftable;
  this->m_gearsRatio.m_capacityAndFlags = 0x80000000;
  this->m_gearsRatio.m_data = 0i64;
  this->m_gearsRatio.m_size = 0;
  this->m_wheelsTorqueRatio.m_data = 0i64;
  this->m_wheelsTorqueRatio.m_size = 0;
  this->m_wheelsTorqueRatio.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_downshiftRPM = 0i64;
  *(_QWORD *)&this->m_primaryTransmissionRatio = 0i64;
  this->m_reverseGearRatio = 0.0;
}

// File Line: 26
// RVA: 0xE2B440
float __fastcall hkpVehicleDefaultTransmission::getCurrentRatio(
        hkpVehicleDefaultTransmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  if ( transmissionOut->m_isReversing.m_bool )
    return COERCE_FLOAT(LODWORD(this->m_reverseGearRatio) ^ _xmm[0]) * this->m_primaryTransmissionRatio;
  else
    return this->m_gearsRatio.m_data[transmissionOut->m_currentGear] * this->m_primaryTransmissionRatio;
}

// File Line: 38
// RVA: 0xE2B0E0
float __fastcall hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatio(
        const float vehicleTopSpeedMPH,
        const float wheelRadius,
        const float maxEngineRpm,
        const float topGearRatio)
{
  return (float)(maxEngineRpm
               / (float)((float)((float)((float)((float)(vehicleTopSpeedMPH * 1.609) * 0.27777779) / wheelRadius) * 60.0)
                       * 0.15915494))
       / topGearRatio;
}

// File Line: 55
// RVA: 0xE2B120
double __fastcall hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatioKPH(
        const float vehicleTopSpeedKPH,
        float wheelRadius,
        float maxEngineRpm,
        float topGearRatio)
{
  double result; // xmm0_8

  *(float *)&result = hkpVehicleDefaultTransmission::calculatePrimaryTransmissionRatio(
                        vehicleTopSpeedKPH * 0.62099999,
                        wheelRadius,
                        maxEngineRpm,
                        topGearRatio);
  return result;
}

// File Line: 60
// RVA: 0xE2B010
void __fastcall hkpVehicleDefaultTransmission::calcTransmission(
        hkpVehicleDefaultTransmission *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  float v7; // xmm0_4
  __int64 v8; // rdx
  __int64 v9; // rcx
  char v10; // [rsp+40h] [rbp+8h] BYREF

  transmissionOut->m_isReversing.m_bool = *(_BYTE *)this->vfptr[3].__vecDelDtor(this, &v10);
  transmissionOut->m_mainTransmittedTorque = ((float (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->vfptr[2].__vecDelDtor)(
                                               this,
                                               vehicle,
                                               transmissionOut);
  v7 = ((float (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->vfptr[2].__first_virtual_table_function__)(
         this,
         vehicle,
         transmissionOut);
  v8 = 0i64;
  transmissionOut->m_transmissionRPM = v7;
  if ( this->m_wheelsTorqueRatio.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v8 = (unsigned int)(v8 + 1);
      ++v9;
      transmissionOut->m_wheelsTransmittedTorque[v9 - 1] = this->m_wheelsTorqueRatio.m_data[v9 - 1]
                                                         * transmissionOut->m_mainTransmittedTorque;
    }
    while ( (int)v8 < this->m_wheelsTorqueRatio.m_size );
  }
  ((void (__fastcall *)(hkpVehicleDefaultTransmission *, __int64, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->vfptr[3].__first_virtual_table_function__)(
    this,
    v8,
    vehicle,
    transmissionOut);
}

// File Line: 79
// RVA: 0xE2B140
float __fastcall hkpVehicleDefaultTransmission::calcMainTransmittedTorque(
        hkpVehicleDefaultTransmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  float m_torque; // xmm6_4

  if ( transmissionOut->m_delayed.m_bool )
    return 0.0;
  m_torque = vehicle->m_torque;
  return ((float (__fastcall *)(hkpVehicleDefaultTransmission *))this->vfptr[4].__vecDelDtor)(this) * m_torque;
}

// File Line: 94
// RVA: 0xE2B180
float __fastcall hkpVehicleDefaultTransmission::calcTransmissionRPM(
        hkpVehicleDefaultTransmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  __int64 v3; // r9
  __int64 m_numWheels; // r10
  float v8; // xmm6_4
  hkpVehicleInstance::WheelInfo *m_data; // r8
  float *v10; // rsi
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __int64 v14; // rdx
  __m128 m_noSlipIdealSpinVelocity_low; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  int v21; // eax
  __m128 v22; // xmm6
  __int64 v23; // rax
  __int64 v24; // rcx
  float m_noSlipIdealSpinVelocity; // xmm0_4

  v3 = 0i64;
  m_numWheels = vehicle->m_data->m_numWheels;
  v8 = 0.0;
  if ( (int)m_numWheels > 0 )
  {
    if ( (unsigned int)m_numWheels >= 8 )
    {
      m_data = vehicle->m_wheelsInfo.m_data;
      v10 = this->m_wheelsTorqueRatio.m_data;
      v11 = 0i64;
      v12 = _mm_shuffle_ps((__m128)0x42700000u, (__m128)0x42700000u, 0);
      v13 = _mm_shuffle_ps((__m128)0x3E22F983u, (__m128)0x3E22F983u, 0);
      v14 = 2i64;
      do
      {
        m_noSlipIdealSpinVelocity_low = (__m128)LODWORD(m_data[v14].m_noSlipIdealSpinVelocity);
        v16 = _mm_unpacklo_ps(
                (__m128)LODWORD(m_data[v14 - 1].m_noSlipIdealSpinVelocity),
                (__m128)LODWORD(m_data[v14 + 1].m_noSlipIdealSpinVelocity));
        v17 = (__m128)*((unsigned int *)&m_data[v14 - 1] - 7);
        v18 = (__m128)LODWORD(m_data[v14 + 5].m_noSlipIdealSpinVelocity);
        v14 += 8i64;
        v19 = _mm_unpacklo_ps(v17, m_noSlipIdealSpinVelocity_low);
        v20 = *(__m128 *)&v10[(int)v3];
        v21 = v3 + 4;
        v3 = (unsigned int)(v3 + 8);
        v11 = _mm_add_ps(
                _mm_add_ps(v11, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_unpacklo_ps(v19, v16), v12), v13), v20)),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_unpacklo_ps(
                        _mm_unpacklo_ps(
                          (__m128)*((unsigned int *)&m_data[v14 - 5] - 7),
                          (__m128)*((unsigned int *)&m_data[v14 - 3] - 7)),
                        _mm_unpacklo_ps((__m128)*((unsigned int *)&m_data[v14 - 4] - 7), v18)),
                      v12),
                    v13),
                  *(__m128 *)&v10[v21]));
      }
      while ( (int)v3 < (int)(m_numWheels - (m_numWheels & 0x80000007)) );
      v22 = _mm_add_ps(_mm_movehl_ps(v11, v11), v11);
      v8 = v22.m128_f32[0] + _mm_shuffle_ps(v22, v22, 245).m128_f32[0];
    }
    if ( (int)v3 < (int)m_numWheels )
    {
      v23 = (int)v3;
      v24 = (int)v3;
      do
      {
        m_noSlipIdealSpinVelocity = vehicle->m_wheelsInfo.m_data[v24].m_noSlipIdealSpinVelocity;
        ++v23;
        ++v24;
        v8 = v8
           + (float)((float)((float)(m_noSlipIdealSpinVelocity * 60.0) * 0.15915494)
                   * this->m_wheelsTorqueRatio.m_data[v23 - 1]);
      }
      while ( v23 < m_numWheels );
    }
  }
  return fmaxf(
           0.0,
           ((float (__fastcall *)(hkpVehicleDefaultTransmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *, __int64))this->vfptr[4].__vecDelDtor)(
             this,
             vehicle,
             transmissionOut,
             v3)
         * v8);
}

// File Line: 126
// RVA: 0xE2B3C0
void __fastcall hkpVehicleDefaultTransmission::updateCurrentGear(
        hkpVehicleDefaultTransmission *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  bool v4; // zf
  float v5; // xmm2_4
  float m_transmissionRPM; // xmm0_4
  char m_currentGear; // al
  float m_clutchDelayTime; // eax
  int v9; // edx
  float v10; // eax

  v4 = transmissionOut->m_delayed.m_bool == 0;
  v5 = transmissionOut->m_clutchDelayCountdown - deltaTime;
  transmissionOut->m_clutchDelayCountdown = v5;
  if ( !v4 && v5 <= 0.0 )
    transmissionOut->m_delayed.m_bool = 0;
  if ( !transmissionOut->m_isReversing.m_bool )
  {
    m_transmissionRPM = transmissionOut->m_transmissionRPM;
    if ( transmissionOut->m_transmissionRPM < this->m_downshiftRPM )
    {
      m_currentGear = transmissionOut->m_currentGear;
      if ( m_currentGear > 0 )
      {
        transmissionOut->m_currentGear = m_currentGear - 1;
        m_clutchDelayTime = this->m_clutchDelayTime;
        transmissionOut->m_delayed.m_bool = 1;
        transmissionOut->m_clutchDelayCountdown = m_clutchDelayTime;
      }
    }
    if ( m_transmissionRPM > this->m_upshiftRPM )
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
hkBool *__fastcall hkpVehicleDefaultTransmission::calcIsReversing(
        hkpVehicleDefaultTransmission *this,
        hkBool *result,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  if ( vehicle->m_tryingToReverse.m_bool && transmissionOut->m_currentGear <= 0 )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

