// File Line: 36
// RVA: 0x451710
void __fastcall UFG::Steering::~Steering(UFG::Steering *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&UFG::Steering::`vftable;
  this->mWheelSteeringMultiplier.m_size = 0;
  m_capacityAndFlags = this->mWheelSteeringMultiplier.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mWheelSteeringMultiplier.m_data,
      4 * m_capacityAndFlags);
  this->mWheelSteeringMultiplier.m_data = 0i64;
  this->mWheelSteeringMultiplier.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 47
// RVA: 0x46A180
void __fastcall UFG::Steering::InitializeFromPropertySet(
        UFG::Steering *this,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        int numWheels,
        int firstFrontWheel,
        int lastFrontWheel,
        int firstRearWheel,
        int lastRearWheel)
{
  hkArray<float,hkContainerHeapAllocator> *p_mWheelSteeringMultiplier; // rbx
  __int64 v8; // rbp
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v14; // r8
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // r8
  __int64 v18; // r9
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  p_mWheelSteeringMultiplier = &this->mWheelSteeringMultiplier;
  v8 = firstFrontWheel;
  this->mMaxSteeringAngle = (float)(vehicle_data_ptr->steering_maxAngle * 3.1415927) * 0.0055555557;
  this->mSteeringSensitivityLo = vehicle_data_ptr->steering_SensitivityLo;
  this->mSteeringSensitivityHi = vehicle_data_ptr->steering_SensitivityHi;
  this->mSteeringSensitivityMinSpeed = vehicle_data_ptr->steering_SensitivityMinSpeed;
  this->mSteeringSensitivityMaxSpeed = vehicle_data_ptr->steering_SensitivityMaxSpeed;
  this->mSteeringCenteringRate = vehicle_data_ptr->steering_CenteringRate;
  this->mSteeringModel = vehicle_data_ptr->steering_SteeringModelExponent;
  v11 = this->mWheelSteeringMultiplier.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < numWheels )
  {
    v12 = 2 * v11;
    v13 = numWheels;
    if ( numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_mWheelSteeringMultiplier, v13, 4);
  }
  v14 = lastFrontWheel;
  p_mWheelSteeringMultiplier->m_size = numWheels;
  v15 = v8;
  if ( v8 <= v14 )
  {
    if ( v14 - v8 + 1 >= 4 )
    {
      do
      {
        v15 += 4i64;
        p_mWheelSteeringMultiplier->m_data[v15 - 4] = vehicle_data_ptr->steering_FrontWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v15 - 3] = vehicle_data_ptr->steering_FrontWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v15 - 2] = vehicle_data_ptr->steering_FrontWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v15 - 1] = vehicle_data_ptr->steering_FrontWheelMultiplier;
      }
      while ( v15 <= v14 - 3 );
    }
    for ( ; v15 <= v14; p_mWheelSteeringMultiplier->m_data[v15 - 1] = vehicle_data_ptr->steering_FrontWheelMultiplier )
      ++v15;
  }
  v16 = firstRearWheel;
  v17 = lastRearWheel;
  if ( firstRearWheel <= (__int64)lastRearWheel )
  {
    if ( lastRearWheel - (__int64)firstRearWheel + 1 >= 4 )
    {
      v18 = lastRearWheel - 3i64;
      do
      {
        v16 += 4i64;
        p_mWheelSteeringMultiplier->m_data[v16 - 4] = vehicle_data_ptr->steering_RearWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v16 - 3] = vehicle_data_ptr->steering_RearWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v16 - 2] = vehicle_data_ptr->steering_RearWheelMultiplier;
        p_mWheelSteeringMultiplier->m_data[v16 - 1] = vehicle_data_ptr->steering_RearWheelMultiplier;
      }
      while ( v16 <= v18 );
    }
    for ( ; v16 <= v17; p_mWheelSteeringMultiplier->m_data[v16 - 1] = vehicle_data_ptr->steering_RearWheelMultiplier )
      ++v16;
  }
}

// File Line: 74
// RVA: 0x483DE0
void __fastcall UFG::Steering::calcMainSteeringAngle(
        UFG::Steering *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  float m_steeringWheelInput; // xmm8_4
  __m128 v10; // xmm2
  float v11; // xmm3_4
  float mPrevInputValue; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm8_4
  float mSteeringModel; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm10_4
  float v19; // xmm0_4
  float mSteeringSensitivityHi; // xmm1_4
  float mSteeringSensitivityLo; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm10_4
  float v27; // xmm7_4
  float mMaxSteeringAngle; // xmm1_4
  hkpVehicleSteering::SteeringAnglesOutput *v29; // rax
  float v30; // xmm2_4
  hkVector4f v31; // [rsp+20h] [rbp-68h] BYREF

  hkVector4f::setRotatedDir(
    &v31,
    &vehicle->m_entity->m_motion.m_motionState.m_transform.m_rotation,
    &vehicle->m_data->m_chassisOrientation.m_col1);
  m_steeringWheelInput = filteredInfoOutput->m_steeringWheelInput;
  v10 = _mm_mul_ps(vehicle->m_entity->m_motion.m_linearVelocity.m_quad, v31.m_quad);
  v11 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
      + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
  mPrevInputValue = this->mPrevInputValue;
  v13 = m_steeringWheelInput - mPrevInputValue;
  LODWORD(v14) = COERCE_UNSIGNED_INT(v11 * 3.5999999) & _xmm;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_steeringWheelInput - mPrevInputValue) & _xmm) > 0.25 )
  {
    if ( v13 <= 0.0 )
    {
      if ( v13 >= 0.0 )
        v15 = 0.0;
      else
        v15 = FLOAT_N1_0;
    }
    else
    {
      v15 = *(float *)&FLOAT_1_0;
    }
    m_steeringWheelInput = (float)(v15 * 0.25) + mPrevInputValue;
  }
  mSteeringModel = this->mSteeringModel;
  this->mPrevInputValue = m_steeringWheelInput;
  v17 = powf(v14, mSteeringModel);
  v18 = powf(this->mSteeringSensitivityMaxSpeed, this->mSteeringModel);
  v19 = powf(this->mSteeringSensitivityMinSpeed, this->mSteeringModel);
  mSteeringSensitivityHi = this->mSteeringSensitivityHi;
  mSteeringSensitivityLo = this->mSteeringSensitivityLo;
  v22 = v19;
  if ( mSteeringSensitivityLo >= mSteeringSensitivityHi )
    v23 = this->mSteeringSensitivityHi;
  else
    v23 = this->mSteeringSensitivityLo;
  if ( mSteeringSensitivityLo <= mSteeringSensitivityHi )
    v24 = this->mSteeringSensitivityHi;
  else
    v24 = this->mSteeringSensitivityLo;
  v25 = FLOAT_0_000099999997;
  v26 = v18 - v22;
  if ( v26 >= 0.000099999997 )
    v25 = v26;
  v27 = (float)((float)(v17 - v22) * (float)((float)(mSteeringSensitivityHi - mSteeringSensitivityLo) / v25))
      + mSteeringSensitivityLo;
  if ( v27 <= v23 )
    v27 = v23;
  if ( v27 >= v24 )
    v27 = v24;
  mMaxSteeringAngle = this->mMaxSteeringAngle;
  this->mMaxSteeringAngleForSpeed = mMaxSteeringAngle * v27;
  if ( m_steeringWheelInput != 0.0 )
  {
    this->mCurrentSteeringAngle = (float)(v27 * m_steeringWheelInput) * mMaxSteeringAngle;
LABEL_22:
    v29 = steeringOutput;
    goto LABEL_23;
  }
  LODWORD(v30) = LODWORD(this->mCurrentSteeringAngle) & _xmm;
  if ( v30 <= 0.0 )
    goto LABEL_22;
  v29 = steeringOutput;
  if ( v30 >= (float)(this->mSteeringCenteringRate * deltaTime) )
    this->mCurrentSteeringAngle = this->mCurrentSteeringAngle
                                - (float)((float)(this->mSteeringCenteringRate
                                                * (float)(this->mCurrentSteeringAngle / v30))
                                        * deltaTime);
  else
    this->mCurrentSteeringAngle = 0.0;
LABEL_23:
  v29->m_mainSteeringAngle = this->mCurrentSteeringAngle;
}

// File Line: 134
// RVA: 0x484060
void __fastcall UFG::Steering::calcSteering(
        UFG::Steering *this,
        float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput,
        hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  int v6; // edx
  __int64 v7; // rcx

  UFG::Steering::calcMainSteeringAngle(this, deltaTime, vehicle, filteredInfoOutput, steeringOutput);
  v6 = 0;
  if ( this->mWheelSteeringMultiplier.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v6;
      ++v7;
      steeringOutput->m_wheelsSteeringAngle.m_data[v7 - 1] = this->mWheelSteeringMultiplier.m_data[v7 - 1]
                                                           * steeringOutput->m_mainSteeringAngle;
    }
    while ( v6 < this->mWheelSteeringMultiplier.m_size );
  }
}

