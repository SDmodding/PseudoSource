// File Line: 40
// RVA: 0x469C70
void __fastcall UFG::Brakes::InitializeFromPropertySet(
        UFG::Brakes *this,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        int numWheels,
        int firstFrontWheel,
        int lastFrontWheel,
        int firstRearWheel,
        int lastRearWheel)
{
  __int64 v7; // rbp
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int m_size; // edx
  int v15; // r8d
  __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // rdx
  unsigned __int64 v19; // r10
  __int64 v20; // rdx
  __int64 v21; // r8
  __int64 v22; // r9
  __int64 v23; // r8
  __int64 v24; // rdx
  unsigned __int64 v25; // r10
  __int64 v26; // rdx
  __int64 v27; // r8
  hkResult result; // [rsp+80h] [rbp+18h] BYREF

  v7 = firstFrontWheel;
  v11 = this->m_wheelBrakingProperties.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < numWheels )
  {
    v12 = 2 * v11;
    v13 = numWheels;
    if ( numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_wheelBrakingProperties, v13, 12);
  }
  m_size = this->m_wheelBrakingProperties.m_size;
  v15 = 0;
  result.m_enum = HK_SUCCESS;
  if ( numWheels - m_size > 0 )
  {
    do
      result.m_enum = ++v15;
    while ( v15 < numWheels - this->m_wheelBrakingProperties.m_size );
  }
  this->m_wheelBrakingProperties.m_size = numWheels;
  v16 = v7;
  v17 = lastFrontWheel;
  if ( v7 <= lastFrontWheel )
  {
    if ( lastFrontWheel - v7 + 1 >= 4 )
    {
      v18 = v7;
      v19 = ((unsigned __int64)(lastFrontWheel - v7 - 3) >> 2) + 1;
      v16 = v7 + 4 * v19;
      do
      {
        this->m_wheelBrakingProperties.m_data[v18].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueFront;
        this->m_wheelBrakingProperties.m_data[v18].m_isConnectedToHandbrake.m_bool = 0;
        this->m_wheelBrakingProperties.m_data[v18].m_minPedalInputToBlock = vehicle_data_ptr->brakes_frontMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v18 + 1].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueFront;
        this->m_wheelBrakingProperties.m_data[v18 + 1].m_isConnectedToHandbrake.m_bool = 0;
        this->m_wheelBrakingProperties.m_data[v18 + 1].m_minPedalInputToBlock = vehicle_data_ptr->brakes_frontMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v18 + 2].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueFront;
        this->m_wheelBrakingProperties.m_data[v18 + 2].m_isConnectedToHandbrake.m_bool = 0;
        this->m_wheelBrakingProperties.m_data[v18 + 2].m_minPedalInputToBlock = vehicle_data_ptr->brakes_frontMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v18 + 3].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueFront;
        this->m_wheelBrakingProperties.m_data[v18 + 3].m_isConnectedToHandbrake.m_bool = 0;
        this->m_wheelBrakingProperties.m_data[v18 + 3].m_minPedalInputToBlock = vehicle_data_ptr->brakes_frontMinPedalInputToBlock;
        v18 += 4i64;
        --v19;
      }
      while ( v19 );
    }
    if ( v16 <= v17 )
    {
      v20 = v16;
      v21 = v17 - v16 + 1;
      do
      {
        this->m_wheelBrakingProperties.m_data[v20].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueFront;
        this->m_wheelBrakingProperties.m_data[v20].m_isConnectedToHandbrake.m_bool = 0;
        this->m_wheelBrakingProperties.m_data[v20++].m_minPedalInputToBlock = vehicle_data_ptr->brakes_frontMinPedalInputToBlock;
        --v21;
      }
      while ( v21 );
    }
  }
  v22 = firstRearWheel;
  v23 = lastRearWheel;
  if ( firstRearWheel <= (__int64)lastRearWheel )
  {
    if ( lastRearWheel - (__int64)firstRearWheel + 1 >= 4 )
    {
      v24 = firstRearWheel;
      v25 = ((unsigned __int64)(lastRearWheel - (__int64)firstRearWheel - 3) >> 2) + 1;
      v22 = firstRearWheel + 4 * v25;
      do
      {
        this->m_wheelBrakingProperties.m_data[v24].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueRear;
        this->m_wheelBrakingProperties.m_data[v24].m_isConnectedToHandbrake.m_bool = 1;
        this->m_wheelBrakingProperties.m_data[v24].m_minPedalInputToBlock = vehicle_data_ptr->brakes_rearMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v24 + 1].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueRear;
        this->m_wheelBrakingProperties.m_data[v24 + 1].m_isConnectedToHandbrake.m_bool = 1;
        this->m_wheelBrakingProperties.m_data[v24 + 1].m_minPedalInputToBlock = vehicle_data_ptr->brakes_rearMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v24 + 2].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueRear;
        this->m_wheelBrakingProperties.m_data[v24 + 2].m_isConnectedToHandbrake.m_bool = 1;
        this->m_wheelBrakingProperties.m_data[v24 + 2].m_minPedalInputToBlock = vehicle_data_ptr->brakes_rearMinPedalInputToBlock;
        this->m_wheelBrakingProperties.m_data[v24 + 3].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueRear;
        this->m_wheelBrakingProperties.m_data[v24 + 3].m_isConnectedToHandbrake.m_bool = 1;
        this->m_wheelBrakingProperties.m_data[v24 + 3].m_minPedalInputToBlock = vehicle_data_ptr->brakes_rearMinPedalInputToBlock;
        v24 += 4i64;
        --v25;
      }
      while ( v25 );
    }
    if ( v22 <= v23 )
    {
      v26 = v22;
      v27 = v23 - v22 + 1;
      do
      {
        this->m_wheelBrakingProperties.m_data[v26].m_maxBreakingTorque = vehicle_data_ptr->brakes_maxTorqueRear;
        this->m_wheelBrakingProperties.m_data[v26].m_isConnectedToHandbrake.m_bool = 1;
        this->m_wheelBrakingProperties.m_data[v26++].m_minPedalInputToBlock = vehicle_data_ptr->brakes_rearMinPedalInputToBlock;
        --v27;
      }
      while ( v27 );
    }
  }
  this->m_wheelsMinTimeToBlock = vehicle_data_ptr->brakes_minTimeToBlock;
  this->mTimeToMaxPedal = vehicle_data_ptr->brakes_timeToMaxPedal;
}

// File Line: 64
// RVA: 0x4836D0
void __fastcall UFG::Brakes::calcBreakingInfo(
        UFG::Brakes *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInfo,
        hkpVehicleBrake::WheelBreakingOutput *breakingInfo)
{
  hkpVehicleDefaultBrake::WheelBrakingProperties *m_data; // rdx
  float mTimeToMaxPedal; // xmm2_4
  char m_bool; // bl
  float m_brakePedalInput; // xmm6_4
  float v11; // xmm0_4
  int v12; // r13d
  __int64 v13; // r14
  __int64 v14; // r12
  __int64 v15; // r8
  char v16; // di
  double v17; // xmm0_8
  hkpVehicleData *v18; // r10
  float v19; // xmm3_4
  float v20; // xmm2_4
  bool v21; // cc
  bool v22; // zf
  int v23; // edi
  float m_wheelsTimeSinceMaxPedalInput; // xmm0_4
  __int64 v25; // r8
  __int64 v26; // rdx
  __int64 v27; // [rsp+D0h] [rbp+18h]
  __int64 v28; // [rsp+D8h] [rbp+20h]

  mTimeToMaxPedal = this->mTimeToMaxPedal;
  m_bool = filteredDriverInfo->m_handbrakeOn.m_bool;
  m_brakePedalInput = filteredDriverInfo->m_brakePedalInput;
  if ( mTimeToMaxPedal > 0.0 )
  {
    if ( m_brakePedalInput < 0.25 )
      v11 = 0.0;
    else
      v11 = deltaTime + this->mTimePedalDown;
    this->mTimePedalDown = v11;
    if ( v11 > mTimeToMaxPedal )
      this->mTimePedalDown = mTimeToMaxPedal;
    m_brakePedalInput = m_brakePedalInput * (float)(this->mTimePedalDown / mTimeToMaxPedal);
  }
  v12 = 0;
  v13 = 0i64;
  if ( vehicle->m_data->m_numWheels <= 0 )
    goto LABEL_29;
  v14 = 0i64;
  v28 = 0i64;
  v15 = 0i64;
  v27 = 0i64;
  v16 = 0;
  do
  {
    breakingInfo->m_isFixed.m_data[v13].m_bool = 0;
    if ( m_bool )
    {
      v17 = ((double (__fastcall *)(hkpVehicleInstance *, hkpVehicleDefaultBrake::WheelBrakingProperties *, __int64))vehicle->vfptr[6].__first_virtual_table_function__)(
              vehicle,
              m_data,
              v15);
      v15 = v27;
      if ( COERCE_FLOAT(LODWORD(v17) & _xmm) >= vehicle->m_data->m_maxVelocityForPositionalFriction )
        breakingInfo->m_isFixed.m_data[v13].m_bool = this->m_wheelBrakingProperties.m_data[v14].m_isConnectedToHandbrake.m_bool;
      else
        breakingInfo->m_isFixed.m_data[v13].m_bool = 1;
    }
    m_data = this->m_wheelBrakingProperties.m_data;
    v18 = vehicle->m_data;
    v19 = m_brakePedalInput * m_data[v14].m_maxBreakingTorque;
    if ( m_brakePedalInput > m_data[v14].m_minPedalInputToBlock )
      v16 = 1;
    v20 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                         (float)(*(float *)((char *)&v18->m_wheelParams.m_data->m_radius + v15)
                               * vehicle->m_wheelsInfo.m_data[v28].m_spinVelocity)
                       * (float)((float)(1.0 / deltaTime) * *(float *)((char *)&v18->m_wheelParams.m_data->m_mass + v15))) ^ _xmm[0])
        * *(float *)((char *)&v18->m_wheelParams.m_data->m_radius + v15);
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v20)) >> 1) > v19 )
    {
      v21 = v20 <= 0.0;
      v20 = m_brakePedalInput * m_data[v14].m_maxBreakingTorque;
      if ( v21 )
        LODWORD(v20) = LODWORD(v19) ^ _xmm[0];
    }
    ++v28;
    v15 += 40i64;
    ++v12;
    ++v13;
    ++v14;
    breakingInfo->m_brakingTorque.m_data[v13 - 1] = v20;
    v27 = v15;
  }
  while ( v12 < v18->m_numWheels );
  v22 = v16 == 0;
  v23 = 0;
  if ( v22 )
  {
LABEL_29:
    breakingInfo->m_wheelsTimeSinceMaxPedalInput = 0.0;
  }
  else
  {
    m_wheelsTimeSinceMaxPedalInput = breakingInfo->m_wheelsTimeSinceMaxPedalInput;
    if ( m_wheelsTimeSinceMaxPedalInput < this->m_wheelsMinTimeToBlock )
    {
      breakingInfo->m_wheelsTimeSinceMaxPedalInput = m_wheelsTimeSinceMaxPedalInput + deltaTime;
    }
    else
    {
      v25 = 0i64;
      if ( v18->m_numWheels > 0 )
      {
        v26 = 0i64;
        do
        {
          if ( m_brakePedalInput > this->m_wheelBrakingProperties.m_data[v26].m_minPedalInputToBlock )
            breakingInfo->m_isFixed.m_data[v25].m_bool = 1;
          ++v23;
          ++v25;
          ++v26;
        }
        while ( v23 < vehicle->m_data->m_numWheels );
      }
    }
  }
}
          ++v25;
          ++v26;

