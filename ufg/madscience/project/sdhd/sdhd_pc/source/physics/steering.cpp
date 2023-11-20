// File Line: 36
// RVA: 0x451710
void __fastcall UFG::Steering::~Steering(UFG::Steering *this)
{
  UFG::Steering *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&UFG::Steering::`vftable';
  this->mWheelSteeringMultiplier.m_size = 0;
  v2 = this->mWheelSteeringMultiplier.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->mWheelSteeringMultiplier.m_data,
      4 * v2);
  v1->mWheelSteeringMultiplier.m_data = 0i64;
  v1->mWheelSteeringMultiplier.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 47
// RVA: 0x46A180
void __fastcall UFG::Steering::InitializeFromPropertySet(UFG::Steering *this, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel)
{
  hkArray<float,hkContainerHeapAllocator> *v7; // rbx
  signed __int64 v8; // rbp
  int v9; // esi
  UFG::WheeledVehiclePhysicsDef *v10; // rdi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  signed __int64 v14; // r8
  signed __int64 v15; // rdx
  signed __int64 v16; // rdx
  signed __int64 v17; // r8
  signed __int64 v18; // r9
  hkResult result; // [rsp+50h] [rbp+18h]

  v7 = &this->mWheelSteeringMultiplier;
  v8 = firstFrontWheel;
  v9 = numWheels;
  v10 = vehicle_data_ptr;
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
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v13, 4);
  }
  v14 = lastFrontWheel;
  v7->m_size = v9;
  v15 = v8;
  if ( v8 <= v14 )
  {
    if ( v14 - v8 + 1 >= 4 )
    {
      do
      {
        v15 += 4i64;
        v7->m_data[v15 - 4] = v10->steering_FrontWheelMultiplier;
        v7->m_data[v15 - 3] = v10->steering_FrontWheelMultiplier;
        v7->m_data[v15 - 2] = v10->steering_FrontWheelMultiplier;
        v7->m_data[v15 - 1] = v10->steering_FrontWheelMultiplier;
      }
      while ( v15 <= v14 - 3 );
    }
    for ( ; v15 <= v14; v7->m_data[v15 - 1] = v10->steering_FrontWheelMultiplier )
      ++v15;
  }
  v16 = firstRearWheel;
  v17 = lastRearWheel;
  if ( firstRearWheel <= (signed __int64)lastRearWheel )
  {
    if ( lastRearWheel - (signed __int64)firstRearWheel + 1 >= 4 )
    {
      v18 = lastRearWheel - 3i64;
      do
      {
        v16 += 4i64;
        v7->m_data[v16 - 4] = v10->steering_RearWheelMultiplier;
        v7->m_data[v16 - 3] = v10->steering_RearWheelMultiplier;
        v7->m_data[v16 - 2] = v10->steering_RearWheelMultiplier;
        v7->m_data[v16 - 1] = v10->steering_RearWheelMultiplier;
      }
      while ( v16 <= v18 );
    }
    for ( ; v16 <= v17; v7->m_data[v16 - 1] = v10->steering_RearWheelMultiplier )
      ++v16;
  }
}

// File Line: 74
// RVA: 0x483DE0
void __fastcall UFG::Steering::calcMainSteeringAngle(UFG::Steering *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  hkpVehicleInstance *v5; // rbx
  UFG::Steering *v6; // rsi
  float v7; // xmm11_4
  hkpVehicleDriverInput::FilteredDriverInputOutput *v8; // rdi
  float v9; // xmm8_4
  __m128 v10; // xmm2
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm8_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm10_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm10_4
  float v27; // xmm7_4
  float v28; // xmm1_4
  hkpVehicleSteering::SteeringAnglesOutput *v29; // rax
  float v30; // xmm2_4
  __m128 v31; // [rsp+20h] [rbp-68h]

  v5 = vehicle;
  v6 = this;
  v7 = deltaTime;
  v8 = filteredInfoOutput;
  hkVector4f::setRotatedDir(
    (hkVector4f *)&v31,
    (hkMatrix3f *)&vehicle->m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    &vehicle->m_data->m_chassisOrientation.m_col1);
  v9 = v8->m_steeringWheelInput;
  v10 = _mm_mul_ps(v5->m_entity->m_motion.m_linearVelocity.m_quad, v31);
  v11 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170));
  v12 = v6->mPrevInputValue;
  v13 = v8->m_steeringWheelInput - v12;
  LODWORD(v14) = COERCE_UNSIGNED_INT(v11 * 3.5999999) & _xmm;
  if ( COERCE_FLOAT(LODWORD(v13) & _xmm) > 0.25 )
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
    v9 = (float)(v15 * 0.25) + v12;
  }
  v16 = v6->mSteeringModel;
  v6->mPrevInputValue = v9;
  v17 = powf(v14, v16);
  v18 = powf(v6->mSteeringSensitivityMaxSpeed, v6->mSteeringModel);
  v19 = powf(v6->mSteeringSensitivityMinSpeed, v6->mSteeringModel);
  v20 = v6->mSteeringSensitivityHi;
  v21 = v6->mSteeringSensitivityLo;
  v22 = v19;
  if ( v21 >= v20 )
    v23 = v6->mSteeringSensitivityHi;
  else
    v23 = v6->mSteeringSensitivityLo;
  if ( v21 <= v20 )
    v24 = v6->mSteeringSensitivityHi;
  else
    v24 = v6->mSteeringSensitivityLo;
  v25 = FLOAT_0_000099999997;
  v26 = v18 - v22;
  if ( v26 >= 0.000099999997 )
    v25 = v26;
  v27 = (float)((float)(v17 - v22) * (float)((float)(v20 - v21) / v25)) + v21;
  if ( v27 <= v23 )
    v27 = v23;
  if ( v27 >= v24 )
    v27 = v24;
  v28 = v6->mMaxSteeringAngle;
  v6->mMaxSteeringAngleForSpeed = v6->mMaxSteeringAngle * v27;
  if ( v9 != 0.0 )
  {
    v6->mCurrentSteeringAngle = (float)(v27 * v9) * v28;
LABEL_22:
    v29 = steeringOutput;
    goto LABEL_23;
  }
  LODWORD(v30) = LODWORD(v6->mCurrentSteeringAngle) & _xmm;
  if ( v30 <= 0.0 )
    goto LABEL_22;
  v29 = steeringOutput;
  if ( v30 >= (float)(v6->mSteeringCenteringRate * v7) )
    v6->mCurrentSteeringAngle = v6->mCurrentSteeringAngle
                              - (float)((float)(v6->mSteeringCenteringRate * (float)(v6->mCurrentSteeringAngle / v30))
                                      * v7);
  else
    v6->mCurrentSteeringAngle = 0.0;
LABEL_23:
  v29->m_mainSteeringAngle = v6->mCurrentSteeringAngle;
}

// File Line: 134
// RVA: 0x484060
void __fastcall UFG::Steering::calcSteering(UFG::Steering *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredInfoOutput, hkpVehicleSteering::SteeringAnglesOutput *steeringOutput)
{
  UFG::Steering *v5; // rbx
  int v6; // edx
  __int64 v7; // rcx

  v5 = this;
  UFG::Steering::calcMainSteeringAngle(this, deltaTime, vehicle, filteredInfoOutput, steeringOutput);
  v6 = 0;
  if ( v5->mWheelSteeringMultiplier.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v6;
      ++v7;
      steeringOutput->m_wheelsSteeringAngle.m_data[v7 - 1] = v5->mWheelSteeringMultiplier.m_data[v7 - 1]
                                                           * steeringOutput->m_mainSteeringAngle;
    }
    while ( v6 < v5->mWheelSteeringMultiplier.m_size );
  }
}

