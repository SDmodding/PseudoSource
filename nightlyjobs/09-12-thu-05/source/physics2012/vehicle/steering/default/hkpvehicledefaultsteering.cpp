// File Line: 15
// RVA: 0xE2E570
void __fastcall hkpVehicleDefaultSteering::hkpVehicleDefaultSteering(hkpVehicleDefaultSteering *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultSteering::`vftable';
  this->m_doesWheelSteer.m_capacityAndFlags = 2147483648;
  this->m_doesWheelSteer.m_data = 0i64;
  this->m_doesWheelSteer.m_size = 0;
  *(_QWORD *)&this->m_maxSteeringAngle = 0i64;
}

// File Line: 22
// RVA: 0xE2E610
void __fastcall hkpVehicleDefaultSteering::calcMainSteeringAngle(hkpVehicleDefaultSteering *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleInstance *v5; // rbx
  hkpEntity *v6; // rdx
  hkpVehicleDefaultSteering *v7; // rdi
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

// File Line: 48
// RVA: 0xE2E5A0
void __usercall hkpVehicleDefaultSteering::calcSteering(hkpVehicleDefaultSteering *this@<rcx>, const float deltaTime@<xmm1>, hkpVehicleInstance *vehicle@<r8>, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput@<r9>, __int64 a5@<rdx>, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleDefaultSteering *v6; // rdi
  __int64 v7; // rdx
  int i; // er8

  v6 = this;
  ((void (__fastcall *)(hkpVehicleDefaultSteering *, __int64, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleSteering::SteeringAnglesOutput *))this->vfptr[2].__vecDelDtor)(
    this,
    a5,
    vehicle,
    filteredInfoOutput,
    steeringOutput);
  v7 = 0i64;
  for ( i = 0; i < v6->m_doesWheelSteer.m_size; ++v7 )
  {
    if ( v6->m_doesWheelSteer.m_data[v7].m_bool )
      steeringOutput->m_wheelsSteeringAngle.m_data[v7] = steeringOutput->m_mainSteeringAngle;
    else
      steeringOutput->m_wheelsSteeringAngle.m_data[v7] = 0.0;
    ++i;
  }
}

