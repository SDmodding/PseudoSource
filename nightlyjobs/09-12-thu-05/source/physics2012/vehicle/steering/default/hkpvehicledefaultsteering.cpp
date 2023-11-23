// File Line: 15
// RVA: 0xE2E570
void __fastcall hkpVehicleDefaultSteering::hkpVehicleDefaultSteering(hkpVehicleDefaultSteering *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultSteering::`vftable;
  this->m_doesWheelSteer.m_capacityAndFlags = 0x80000000;
  this->m_doesWheelSteer.m_data = 0i64;
  this->m_doesWheelSteer.m_size = 0;
  *(_QWORD *)&this->m_maxSteeringAngle = 0i64;
}

// File Line: 22
// RVA: 0xE2E610
void __fastcall hkpVehicleDefaultSteering::calcMainSteeringAngle(
        hkpVehicleDefaultSteering *this,
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

// File Line: 48
// RVA: 0xE2E5A0
void __fastcall hkpVehicleDefaultSteering::calcSteering(
        hkpVehicleDefaultSteering *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  __int64 v5; // rdx
  __int64 v7; // rdx
  int i; // r8d

  ((void (__fastcall *)(hkpVehicleDefaultSteering *, __int64, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleSteering::SteeringAnglesOutput *))this->vfptr[2].__vecDelDtor)(
    this,
    v5,
    vehicle,
    filteredInfoOutput,
    steeringOutput);
  v7 = 0i64;
  for ( i = 0; i < this->m_doesWheelSteer.m_size; ++v7 )
  {
    if ( this->m_doesWheelSteer.m_data[v7].m_bool )
      steeringOutput->m_wheelsSteeringAngle.m_data[v7] = steeringOutput->m_mainSteeringAngle;
    else
      steeringOutput->m_wheelsSteeringAngle.m_data[v7] = 0.0;
    ++i;
  }
}

