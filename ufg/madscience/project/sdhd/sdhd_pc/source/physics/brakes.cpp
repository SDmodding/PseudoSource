// File Line: 40
// RVA: 0x469C70
void __fastcall UFG::Brakes::InitializeFromPropertySet(UFG::Brakes *this, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel)
{
  signed __int64 v7; // rbp
  int v8; // esi
  UFG::WheeledVehiclePhysicsDef *v9; // rdi
  UFG::Brakes *v10; // r14
  int v11; // eax
  int v12; // eax
  int v13; // er9
  __int64 v14; // rdx
  signed __int64 v15; // r9
  int v16; // er8
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  signed __int64 v19; // rdx
  unsigned __int64 v20; // r10
  signed __int64 v21; // rdx
  signed __int64 v22; // r8
  signed __int64 v23; // r9
  signed __int64 v24; // r8
  signed __int64 v25; // rdx
  unsigned __int64 v26; // r10
  signed __int64 v27; // rdx
  signed __int64 v28; // r8
  hkResult result; // [rsp+80h] [rbp+18h]

  v7 = firstFrontWheel;
  v8 = numWheels;
  v9 = vehicle_data_ptr;
  v10 = this;
  v11 = this->m_wheelBrakingProperties.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < numWheels )
  {
    v12 = 2 * v11;
    v13 = numWheels;
    if ( numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_wheelBrakingProperties,
      v13,
      12);
  }
  v14 = v10->m_wheelBrakingProperties.m_size;
  v15 = (signed __int64)&v10->m_wheelBrakingProperties.m_data[v14];
  v16 = 0;
  result.m_enum = 0;
  if ( v8 - (signed int)v14 > 0 )
  {
    do
      result.m_enum = ++v16;
    while ( v16 < v8 - v10->m_wheelBrakingProperties.m_size );
  }
  v10->m_wheelBrakingProperties.m_size = v8;
  v17 = v7;
  v18 = lastFrontWheel;
  if ( v7 <= lastFrontWheel )
  {
    if ( lastFrontWheel - v7 + 1 >= 4 )
    {
      v19 = v7;
      v20 = ((unsigned __int64)(lastFrontWheel - v7 - 3) >> 2) + 1;
      v17 = v7 + 4 * v20;
      do
      {
        v10->m_wheelBrakingProperties.m_data[v19].m_maxBreakingTorque = v9->brakes_maxTorqueFront;
        v10->m_wheelBrakingProperties.m_data[v19].m_isConnectedToHandbrake.m_bool = 0;
        v10->m_wheelBrakingProperties.m_data[v19].m_minPedalInputToBlock = v9->brakes_frontMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v19 + 1].m_maxBreakingTorque = v9->brakes_maxTorqueFront;
        v10->m_wheelBrakingProperties.m_data[v19 + 1].m_isConnectedToHandbrake.m_bool = 0;
        v10->m_wheelBrakingProperties.m_data[v19 + 1].m_minPedalInputToBlock = v9->brakes_frontMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v19 + 2].m_maxBreakingTorque = v9->brakes_maxTorqueFront;
        v10->m_wheelBrakingProperties.m_data[v19 + 2].m_isConnectedToHandbrake.m_bool = 0;
        v10->m_wheelBrakingProperties.m_data[v19 + 2].m_minPedalInputToBlock = v9->brakes_frontMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v19 + 3].m_maxBreakingTorque = v9->brakes_maxTorqueFront;
        v10->m_wheelBrakingProperties.m_data[v19 + 3].m_isConnectedToHandbrake.m_bool = 0;
        v10->m_wheelBrakingProperties.m_data[v19 + 3].m_minPedalInputToBlock = v9->brakes_frontMinPedalInputToBlock;
        v19 += 4i64;
        --v20;
      }
      while ( v20 );
    }
    if ( v17 <= v18 )
    {
      v21 = v17;
      v22 = v18 - v17 + 1;
      do
      {
        v10->m_wheelBrakingProperties.m_data[v21].m_maxBreakingTorque = v9->brakes_maxTorqueFront;
        v10->m_wheelBrakingProperties.m_data[v21].m_isConnectedToHandbrake.m_bool = 0;
        v10->m_wheelBrakingProperties.m_data[v21].m_minPedalInputToBlock = v9->brakes_frontMinPedalInputToBlock;
        ++v21;
        --v22;
      }
      while ( v22 );
    }
  }
  v23 = firstRearWheel;
  v24 = lastRearWheel;
  if ( firstRearWheel <= (signed __int64)lastRearWheel )
  {
    if ( lastRearWheel - (signed __int64)firstRearWheel + 1 >= 4 )
    {
      v25 = firstRearWheel;
      v26 = ((unsigned __int64)(lastRearWheel - (signed __int64)firstRearWheel - 3) >> 2) + 1;
      v23 = firstRearWheel + 4 * v26;
      do
      {
        v10->m_wheelBrakingProperties.m_data[v25].m_maxBreakingTorque = v9->brakes_maxTorqueRear;
        v10->m_wheelBrakingProperties.m_data[v25].m_isConnectedToHandbrake.m_bool = 1;
        v10->m_wheelBrakingProperties.m_data[v25].m_minPedalInputToBlock = v9->brakes_rearMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v25 + 1].m_maxBreakingTorque = v9->brakes_maxTorqueRear;
        v10->m_wheelBrakingProperties.m_data[v25 + 1].m_isConnectedToHandbrake.m_bool = 1;
        v10->m_wheelBrakingProperties.m_data[v25 + 1].m_minPedalInputToBlock = v9->brakes_rearMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v25 + 2].m_maxBreakingTorque = v9->brakes_maxTorqueRear;
        v10->m_wheelBrakingProperties.m_data[v25 + 2].m_isConnectedToHandbrake.m_bool = 1;
        v10->m_wheelBrakingProperties.m_data[v25 + 2].m_minPedalInputToBlock = v9->brakes_rearMinPedalInputToBlock;
        v10->m_wheelBrakingProperties.m_data[v25 + 3].m_maxBreakingTorque = v9->brakes_maxTorqueRear;
        v10->m_wheelBrakingProperties.m_data[v25 + 3].m_isConnectedToHandbrake.m_bool = 1;
        v10->m_wheelBrakingProperties.m_data[v25 + 3].m_minPedalInputToBlock = v9->brakes_rearMinPedalInputToBlock;
        v25 += 4i64;
        --v26;
      }
      while ( v26 );
    }
    if ( v23 <= v24 )
    {
      v27 = v23;
      v28 = v24 - v23 + 1;
      do
      {
        v10->m_wheelBrakingProperties.m_data[v27].m_maxBreakingTorque = v9->brakes_maxTorqueRear;
        v10->m_wheelBrakingProperties.m_data[v27].m_isConnectedToHandbrake.m_bool = 1;
        v10->m_wheelBrakingProperties.m_data[v27].m_minPedalInputToBlock = v9->brakes_rearMinPedalInputToBlock;
        ++v27;
        --v28;
      }
      while ( v28 );
    }
  }
  v10->m_wheelsMinTimeToBlock = v9->brakes_minTimeToBlock;
  v10->mTimeToMaxPedal = v9->brakes_timeToMaxPedal;
}

// File Line: 64
// RVA: 0x4836D0
void __usercall UFG::Brakes::calcBreakingInfo(UFG::Brakes *this@<rcx>, const float deltaTime@<xmm1>, hkpVehicleInstance *vehicle@<r8>, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInfo@<r9>, hkpVehicleDefaultBrake::WheelBrakingProperties *a5@<rdx>, float a6@<xmm0>, hkpVehicleBrake::WheelBreakingOutput *breakingInfo)
{
  float v7; // xmm2_4
  char v8; // bl
  float v9; // xmm6_4
  hkpVehicleInstance *v10; // r15
  UFG::Brakes *v11; // rbp
  float v12; // xmm0_4
  signed int v13; // er13
  __int64 v14; // r14
  __int64 v15; // r12
  __int64 v16; // r8
  char v17; // di
  hkpVehicleData *v18; // r10
  float v19; // xmm3_4
  float v20; // xmm2_4
  bool v21; // cf
  bool v22; // zf
  signed int v23; // edi
  float v24; // xmm0_4
  __int64 v25; // r8
  __int64 v26; // rdx
  __int64 v27; // [rsp+D0h] [rbp+18h]
  __int64 v28; // [rsp+D8h] [rbp+20h]

  v7 = this->mTimeToMaxPedal;
  v8 = filteredDriverInfo->m_handbrakeOn.m_bool;
  v9 = filteredDriverInfo->m_brakePedalInput;
  v10 = vehicle;
  v11 = this;
  if ( v7 > 0.0 )
  {
    if ( v9 < 0.25 )
      v12 = 0.0;
    else
      v12 = deltaTime + this->mTimePedalDown;
    this->mTimePedalDown = v12;
    if ( v12 > v7 )
      this->mTimePedalDown = v7;
    a6 = this->mTimePedalDown / v7;
    v9 = v9 * a6;
  }
  v13 = 0;
  v14 = 0i64;
  if ( vehicle->m_data->m_numWheels <= 0 )
    goto LABEL_32;
  v15 = 0i64;
  v28 = 0i64;
  v16 = 0i64;
  v27 = 0i64;
  v17 = 0;
  do
  {
    breakingInfo->m_isFixed.m_data[v14].m_bool = 0;
    if ( v8 )
    {
      ((void (__fastcall *)(hkpVehicleInstance *, hkpVehicleDefaultBrake::WheelBrakingProperties *, __int64))v10->vfptr[6].__first_virtual_table_function__)(
        v10,
        a5,
        v16);
      v16 = v27;
      if ( COERCE_FLOAT(LODWORD(a6) & _xmm) >= v10->m_data->m_maxVelocityForPositionalFriction )
        breakingInfo->m_isFixed.m_data[v14].m_bool = v11->m_wheelBrakingProperties.m_data[v15].m_isConnectedToHandbrake.m_bool;
      else
        breakingInfo->m_isFixed.m_data[v14].m_bool = 1;
    }
    a5 = v11->m_wheelBrakingProperties.m_data;
    v18 = v10->m_data;
    v19 = v9 * a5[v15].m_maxBreakingTorque;
    if ( v9 > a5[v15].m_minPedalInputToBlock )
      v17 = 1;
    v20 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                         (float)(*(float *)((char *)&v18->m_wheelParams.m_data->m_radius + v16)
                               * v10->m_wheelsInfo.m_data[v28].m_spinVelocity)
                       * (float)((float)(1.0 / deltaTime) * *(float *)((char *)&v18->m_wheelParams.m_data->m_mass + v16))) ^ _xmm[0])
        * *(float *)((char *)&v18->m_wheelParams.m_data->m_radius + v16);
    LODWORD(a6) = (unsigned int)(2 * LODWORD(v20)) >> 1;
    if ( a6 > v19 )
    {
      v21 = v20 < 0.0;
      v22 = v20 == 0.0;
      v20 = v9 * a5[v15].m_maxBreakingTorque;
      if ( v21 || v22 )
        LODWORD(v20) = LODWORD(v19) ^ _xmm[0];
    }
    ++v28;
    v16 += 40i64;
    ++v13;
    ++v14;
    ++v15;
    breakingInfo->m_brakingTorque.m_data[v14 - 1] = v20;
    v27 = v16;
  }
  while ( v13 < v18->m_numWheels );
  v22 = v17 == 0;
  v23 = 0;
  if ( v22 )
  {
LABEL_32:
    breakingInfo->m_wheelsTimeSinceMaxPedalInput = 0.0;
  }
  else
  {
    v24 = breakingInfo->m_wheelsTimeSinceMaxPedalInput;
    if ( v24 < v11->m_wheelsMinTimeToBlock )
    {
      breakingInfo->m_wheelsTimeSinceMaxPedalInput = v24 + deltaTime;
    }
    else
    {
      v25 = 0i64;
      if ( v18->m_numWheels > 0 )
      {
        v26 = 0i64;
        do
        {
          if ( v9 > v11->m_wheelBrakingProperties.m_data[v26].m_minPedalInputToBlock )
            breakingInfo->m_isFixed.m_data[v25].m_bool = 1;
          ++v23;
          ++v25;
          ++v26;
        }
        while ( v23 < v10->m_data->m_numWheels );
      }
    }
  }
}

