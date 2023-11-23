// File Line: 25
// RVA: 0x46A340
void __fastcall UFG::Transmission::InitializeFromPropertySet(
        UFG::Transmission *this,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr,
        int numWheels,
        int firstFrontWheel,
        int lastFrontWheel,
        int firstRearWheel,
        int lastRearWheel)
{
  __int64 v7; // r13
  int v9; // eax
  int v12; // eax
  int v13; // r9d
  __int64 mNumItems; // rbp
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // eax
  int v22; // eax
  int v23; // r9d
  __int64 v24; // rdx
  int v25; // eax
  int v26; // r9d
  int v27; // r9d
  int v28; // r9d
  __int64 v29; // r8
  __int64 v30; // rdx
  __int64 v31; // r9
  __int64 v32; // rdx
  __int64 v33; // r8
  __int64 v34; // r9
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  this->m_clutchDelayTime = vehicle_data_ptr->drivetrain_clutchDelayTime;
  v7 = firstFrontWheel;
  this->m_reverseGearRatio = vehicle_data_ptr->drivetrain_reverseGearRatio;
  v9 = this->m_wheelsTorqueRatio.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < numWheels )
  {
    v12 = 2 * v9;
    v13 = numWheels;
    if ( numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_wheelsTorqueRatio, v13, 4);
  }
  this->m_wheelsTorqueRatio.m_size = numWheels;
  mNumItems = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mNumItems;
  v15 = this->m_gearsRatio.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (int)mNumItems <= 0 )
  {
    if ( (this->m_gearsRatio.m_capacityAndFlags & 0x3FFFFFFFu) < 5 )
    {
      v25 = 2 * v15;
      v26 = 5;
      if ( v25 > 5 )
        v26 = v25;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_gearsRatio, v26, 4);
    }
    this->m_gearsRatio.m_size = 5;
    *this->m_gearsRatio.m_data = vehicle_data_ptr->drivetrain_gearRatio1;
    *((_DWORD *)this->m_gearsRatio.m_data + 1) = LODWORD(vehicle_data_ptr->drivetrain_gearRatio2);
    *((_DWORD *)this->m_gearsRatio.m_data + 2) = LODWORD(vehicle_data_ptr->drivetrain_gearRatio3);
    *((_DWORD *)this->m_gearsRatio.m_data + 3) = LODWORD(vehicle_data_ptr->drivetrain_gearRatio4);
    *((_DWORD *)this->m_gearsRatio.m_data + 4) = LODWORD(vehicle_data_ptr->drivetrain_gearRatio5);
    this->m_downshiftRPM = vehicle_data_ptr->drivetrain_downshiftRPM;
    this->m_upshiftRPM = vehicle_data_ptr->drivetrain_upshiftRPM;
    if ( (this->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFFu) < 5 )
    {
      v27 = 5;
      if ( 2 * (this->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFF) > 5 )
        v27 = 2 * (this->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mUpshiftRPM, v27, 4);
    }
    this->mUpshiftRPM.m_size = 5;
    *this->mUpshiftRPM.m_data = this->m_upshiftRPM;
    *((_DWORD *)this->mUpshiftRPM.m_data + 1) = LODWORD(this->m_upshiftRPM);
    *((_DWORD *)this->mUpshiftRPM.m_data + 2) = LODWORD(this->m_upshiftRPM);
    *((_DWORD *)this->mUpshiftRPM.m_data + 3) = LODWORD(this->m_upshiftRPM);
    *((_DWORD *)this->mUpshiftRPM.m_data + 4) = LODWORD(this->m_upshiftRPM);
    if ( (this->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFFu) < 5 )
    {
      v28 = 5;
      if ( 2 * (this->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFF) > 5 )
        v28 = 2 * (this->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mDownshiftRPM, v28, 4);
    }
    this->mDownshiftRPM.m_size = 5;
    *this->mDownshiftRPM.m_data = this->m_downshiftRPM;
    *((_DWORD *)this->mDownshiftRPM.m_data + 1) = LODWORD(this->m_downshiftRPM);
    *((_DWORD *)this->mDownshiftRPM.m_data + 2) = LODWORD(this->m_downshiftRPM);
    *((_DWORD *)this->mDownshiftRPM.m_data + 3) = LODWORD(this->m_downshiftRPM);
    *((_DWORD *)this->mDownshiftRPM.m_data + 4) = LODWORD(this->m_downshiftRPM);
  }
  else
  {
    if ( v15 < (int)mNumItems )
    {
      v16 = 2 * v15;
      v17 = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mNumItems;
      if ( (int)mNumItems < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_gearsRatio, v17, 4);
    }
    this->m_gearsRatio.m_size = mNumItems;
    v18 = this->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < (int)mNumItems )
    {
      v19 = 2 * v18;
      v20 = mNumItems;
      if ( (int)mNumItems < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mUpshiftRPM, v20, 4);
    }
    this->mUpshiftRPM.m_size = mNumItems;
    v21 = this->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < (int)mNumItems )
    {
      v22 = 2 * v21;
      v23 = mNumItems;
      if ( (int)mNumItems < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->mDownshiftRPM, v23, 4);
    }
    v24 = 0i64;
    this->mDownshiftRPM.m_size = mNumItems;
    if ( mNumItems >= 4 )
    {
      do
      {
        v24 += 4i64;
        this->m_gearsRatio.m_data[v24 - 4] = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mItems[v24 - 4];
        this->mUpshiftRPM.m_data[v24 - 4] = vehicle_data_ptr->drivetrain_upshiftTable.mData.mItems[v24 - 4];
        this->mDownshiftRPM.m_data[v24 - 4] = vehicle_data_ptr->drivetrain_downshiftTable.mData.mItems[v24 - 4];
        this->m_gearsRatio.m_data[v24 - 3] = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mItems[v24 - 3];
        this->mUpshiftRPM.m_data[v24 - 3] = vehicle_data_ptr->drivetrain_upshiftTable.mData.mItems[v24 - 3];
        this->mDownshiftRPM.m_data[v24 - 3] = vehicle_data_ptr->drivetrain_downshiftTable.mData.mItems[v24 - 3];
        this->m_gearsRatio.m_data[v24 - 2] = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mItems[v24 - 2];
        this->mUpshiftRPM.m_data[v24 - 2] = vehicle_data_ptr->drivetrain_upshiftTable.mData.mItems[v24 - 2];
        this->mDownshiftRPM.m_data[v24 - 2] = vehicle_data_ptr->drivetrain_downshiftTable.mData.mItems[v24 - 2];
        this->m_gearsRatio.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mItems[v24 - 1];
        this->mUpshiftRPM.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_upshiftTable.mData.mItems[v24 - 1];
        this->mDownshiftRPM.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_downshiftTable.mData.mItems[v24 - 1];
      }
      while ( v24 < mNumItems - 3 );
    }
    for ( ;
          v24 < mNumItems;
          this->mDownshiftRPM.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_downshiftTable.mData.mItems[v24 - 1] )
    {
      ++v24;
      this->m_gearsRatio.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_gearRatioTable.mData.mItems[v24 - 1];
      this->mUpshiftRPM.m_data[v24 - 1] = vehicle_data_ptr->drivetrain_upshiftTable.mData.mItems[v24 - 1];
    }
  }
  v29 = lastFrontWheel;
  v30 = v7;
  if ( v7 <= lastFrontWheel )
  {
    if ( lastFrontWheel - v7 + 1 >= 4 )
    {
      v31 = lastFrontWheel - 3i64;
      do
      {
        v30 += 4i64;
        this->m_wheelsTorqueRatio.m_data[v30 - 4] = vehicle_data_ptr->drivetrain_frontWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v30 - 3] = vehicle_data_ptr->drivetrain_frontWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v30 - 2] = vehicle_data_ptr->drivetrain_frontWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v30 - 1] = vehicle_data_ptr->drivetrain_frontWheelTorqueRatio;
      }
      while ( v30 <= v31 );
    }
    for ( ; v30 <= v29; this->m_wheelsTorqueRatio.m_data[v30 - 1] = vehicle_data_ptr->drivetrain_frontWheelTorqueRatio )
      ++v30;
  }
  v32 = firstRearWheel;
  v33 = lastRearWheel;
  if ( firstRearWheel <= (__int64)lastRearWheel )
  {
    if ( lastRearWheel - (__int64)firstRearWheel + 1 >= 4 )
    {
      v34 = lastRearWheel - 3i64;
      do
      {
        v32 += 4i64;
        this->m_wheelsTorqueRatio.m_data[v32 - 4] = vehicle_data_ptr->drivetrain_rearWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v32 - 3] = vehicle_data_ptr->drivetrain_rearWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v32 - 2] = vehicle_data_ptr->drivetrain_rearWheelTorqueRatio;
        this->m_wheelsTorqueRatio.m_data[v32 - 1] = vehicle_data_ptr->drivetrain_rearWheelTorqueRatio;
      }
      while ( v32 <= v34 );
    }
    for ( ; v32 <= v33; this->m_wheelsTorqueRatio.m_data[v32 - 1] = vehicle_data_ptr->drivetrain_rearWheelTorqueRatio )
      ++v32;
  }
  this->m_primaryTransmissionRatio = vehicle_data_ptr->drivetrain_finalDriveRatio;
}

// File Line: 92
// RVA: 0x4879D0
double __fastcall UFG::Transmission::getCurrentRatio(
        UFG::Transmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  double result; // xmm0_8

  if ( (*((_BYTE *)this + 104) & 1) != 0 )
    return 0.0;
  *(float *)&result = hkpVehicleDefaultTransmission::getCurrentRatio(this, vehicle, transmissionOut);
  return result;
}

// File Line: 102
// RVA: 0x483DD0
hkBool *__fastcall UFG::Transmission::calcIsReversing(
        UFG::Transmission *this,
        hkBool *result,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  result->m_bool = (char)vehicle->m_tryingToReverse;
  return result;
}

// File Line: 109
// RVA: 0x484120
float __fastcall UFG::Transmission::calcTransmissionRPM(
        UFG::Transmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  __int64 v3; // r10
  __int64 m_numWheels; // r9
  float v8; // xmm6_4
  float *v9; // rax
  float *p_m_spinVelocity; // rdx
  unsigned __int64 v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float *v14; // rdx
  float *v15; // r8
  __int64 v16; // r9
  float v17; // xmm0_4

  v3 = 0i64;
  m_numWheels = vehicle->m_data->m_numWheels;
  v8 = 0.0;
  if ( m_numWheels >= 4 )
  {
    v9 = this->m_wheelsTorqueRatio.m_data + 2;
    p_m_spinVelocity = &vehicle->m_wheelsInfo.m_data[1].m_spinVelocity;
    v11 = ((unsigned __int64)(m_numWheels - 4) >> 2) + 1;
    v3 = 4 * v11;
    do
    {
      v12 = *(p_m_spinVelocity - 56);
      v13 = *p_m_spinVelocity;
      v9 += 4;
      p_m_spinVelocity += 224;
      v8 = (float)((float)((float)((float)((float)((float)(v12 * 60.0) * 0.15915494) * *(v9 - 6)) + v8)
                         + (float)((float)((float)(v13 * 60.0) * 0.15915494) * *(v9 - 5)))
                 + (float)((float)((float)(*(p_m_spinVelocity - 168) * 60.0) * 0.15915494) * *(v9 - 4)))
         + (float)((float)((float)(*(p_m_spinVelocity - 112) * 60.0) * 0.15915494) * *(v9 - 3));
      --v11;
    }
    while ( v11 );
  }
  if ( v3 < m_numWheels )
  {
    v14 = &this->m_wheelsTorqueRatio.m_data[v3];
    v15 = &vehicle->m_wheelsInfo.m_data[v3].m_spinVelocity;
    v16 = m_numWheels - v3;
    do
    {
      v17 = *v15;
      v15 += 56;
      v8 = v8 + (float)((float)((float)(v17 * 60.0) * 0.15915494) * *v14++);
      --v16;
    }
    while ( v16 );
  }
  return ((float (__fastcall *)(UFG::Transmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->vfptr[4].__vecDelDtor)(
           this,
           vehicle,
           transmissionOut)
       * v8;
}

// File Line: 142
// RVA: 0x484020
float __fastcall UFG::Transmission::calcMainTransmittedTorque(
        UFG::Transmission *this,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  float m_torque; // xmm6_4

  if ( transmissionOut->m_delayed.m_bool )
    return 0.0;
  m_torque = vehicle->m_torque;
  return ((float (__fastcall *)(UFG::Transmission *))this->vfptr[4].__vecDelDtor)(this) * m_torque;
}

// File Line: 159
// RVA: 0x4895E0
void __fastcall UFG::Transmission::updateCurrentGear(
        UFG::Transmission *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  bool v4; // zf
  float v5; // xmm2_4
  __int64 m_currentGear; // rdx
  float m_transmissionRPM; // xmm0_4
  float m_clutchDelayTime; // eax
  __int64 v9; // rdx
  float v10; // eax

  v4 = transmissionOut->m_delayed.m_bool == 0;
  v5 = transmissionOut->m_clutchDelayCountdown - deltaTime;
  transmissionOut->m_clutchDelayCountdown = v5;
  if ( !v4 && v5 <= 0.0 )
    transmissionOut->m_delayed.m_bool = 0;
  if ( !transmissionOut->m_isReversing.m_bool )
  {
    m_currentGear = transmissionOut->m_currentGear;
    m_transmissionRPM = transmissionOut->m_transmissionRPM;
    if ( transmissionOut->m_transmissionRPM < this->mDownshiftRPM.m_data[m_currentGear] && (char)m_currentGear > 0 )
    {
      transmissionOut->m_currentGear = m_currentGear - 1;
      m_clutchDelayTime = this->m_clutchDelayTime;
      transmissionOut->m_delayed.m_bool = 1;
      transmissionOut->m_clutchDelayCountdown = m_clutchDelayTime;
    }
    v9 = transmissionOut->m_currentGear;
    if ( m_transmissionRPM > this->mUpshiftRPM.m_data[v9] && (char)v9 + 1 < this->m_gearsRatio.m_size )
    {
      transmissionOut->m_currentGear = v9 + 1;
      v10 = this->m_clutchDelayTime;
      transmissionOut->m_delayed.m_bool = 1;
      transmissionOut->m_clutchDelayCountdown = v10;
    }
  }
}

