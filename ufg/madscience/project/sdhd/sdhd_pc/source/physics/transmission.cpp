// File Line: 25
// RVA: 0x46A340
void __fastcall UFG::Transmission::InitializeFromPropertySet(UFG::Transmission *this, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel)
{
  signed __int64 v7; // r13
  int v8; // ebp
  int v9; // eax
  UFG::WheeledVehiclePhysicsDef *v10; // rbx
  UFG::Transmission *v11; // rsi
  int v12; // eax
  int v13; // er9
  signed __int64 v14; // rbp
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // eax
  int v22; // eax
  int v23; // er9
  signed __int64 v24; // rdx
  int v25; // eax
  int v26; // er9
  int v27; // eax
  int v28; // eax
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int v32; // er9
  signed __int64 v33; // r8
  signed __int64 v34; // rdx
  signed __int64 v35; // r9
  signed __int64 v36; // rdx
  signed __int64 v37; // r8
  signed __int64 v38; // r9
  hkResult result; // [rsp+70h] [rbp+18h]

  this->m_clutchDelayTime = vehicle_data_ptr->drivetrain_clutchDelayTime;
  v7 = firstFrontWheel;
  this->m_reverseGearRatio = vehicle_data_ptr->drivetrain_reverseGearRatio;
  v8 = numWheels;
  v9 = this->m_wheelsTorqueRatio.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = vehicle_data_ptr;
  v11 = this;
  if ( v9 < numWheels )
  {
    v12 = 2 * v9;
    v13 = numWheels;
    if ( numWheels < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_wheelsTorqueRatio,
      v13,
      4);
  }
  v11->m_wheelsTorqueRatio.m_size = v8;
  v14 = v10->drivetrain_gearRatioTable.mData.mNumItems;
  v15 = v11->m_gearsRatio.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (signed int)v14 <= 0 )
  {
    if ( v15 < 5 )
    {
      v25 = 2 * v15;
      v26 = 5;
      if ( v25 > 5 )
        v26 = v25;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->m_gearsRatio,
        v26,
        4);
    }
    v11->m_gearsRatio.m_size = 5;
    *v11->m_gearsRatio.m_data = v10->drivetrain_gearRatio1;
    *((_DWORD *)v11->m_gearsRatio.m_data + 1) = LODWORD(v10->drivetrain_gearRatio2);
    *((_DWORD *)v11->m_gearsRatio.m_data + 2) = LODWORD(v10->drivetrain_gearRatio3);
    *((_DWORD *)v11->m_gearsRatio.m_data + 3) = LODWORD(v10->drivetrain_gearRatio4);
    *((_DWORD *)v11->m_gearsRatio.m_data + 4) = LODWORD(v10->drivetrain_gearRatio5);
    v11->m_downshiftRPM = v10->drivetrain_downshiftRPM;
    v11->m_upshiftRPM = v10->drivetrain_upshiftRPM;
    v27 = v11->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 < 5 )
    {
      v28 = 2 * v27;
      v29 = 5;
      if ( v28 > 5 )
        v29 = v28;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->mUpshiftRPM,
        v29,
        4);
    }
    v11->mUpshiftRPM.m_size = 5;
    *v11->mUpshiftRPM.m_data = v11->m_upshiftRPM;
    *((_DWORD *)v11->mUpshiftRPM.m_data + 1) = LODWORD(v11->m_upshiftRPM);
    *((_DWORD *)v11->mUpshiftRPM.m_data + 2) = LODWORD(v11->m_upshiftRPM);
    *((_DWORD *)v11->mUpshiftRPM.m_data + 3) = LODWORD(v11->m_upshiftRPM);
    *((_DWORD *)v11->mUpshiftRPM.m_data + 4) = LODWORD(v11->m_upshiftRPM);
    v30 = v11->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < 5 )
    {
      v31 = 2 * v30;
      v32 = 5;
      if ( v31 > 5 )
        v32 = v31;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->mDownshiftRPM,
        v32,
        4);
    }
    v11->mDownshiftRPM.m_size = 5;
    *v11->mDownshiftRPM.m_data = v11->m_downshiftRPM;
    *((_DWORD *)v11->mDownshiftRPM.m_data + 1) = LODWORD(v11->m_downshiftRPM);
    *((_DWORD *)v11->mDownshiftRPM.m_data + 2) = LODWORD(v11->m_downshiftRPM);
    *((_DWORD *)v11->mDownshiftRPM.m_data + 3) = LODWORD(v11->m_downshiftRPM);
    *((_DWORD *)v11->mDownshiftRPM.m_data + 4) = LODWORD(v11->m_downshiftRPM);
  }
  else
  {
    if ( v15 < (signed int)v14 )
    {
      v16 = 2 * v15;
      v17 = v14;
      if ( (signed int)v14 < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->m_gearsRatio,
        v17,
        4);
    }
    v11->m_gearsRatio.m_size = v14;
    v18 = v11->mUpshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < (signed int)v14 )
    {
      v19 = 2 * v18;
      v20 = v14;
      if ( (signed int)v14 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->mUpshiftRPM,
        v20,
        4);
    }
    v11->mUpshiftRPM.m_size = v14;
    v21 = v11->mDownshiftRPM.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < (signed int)v14 )
    {
      v22 = 2 * v21;
      v23 = v14;
      if ( (signed int)v14 < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->mDownshiftRPM,
        v23,
        4);
    }
    v24 = 0i64;
    v11->mDownshiftRPM.m_size = v14;
    if ( v14 >= 4 )
    {
      do
      {
        v24 += 4i64;
        v11->m_gearsRatio.m_data[v24 - 4] = v10->drivetrain_gearRatioTable.mData.mItems[v24 - 4];
        v11->mUpshiftRPM.m_data[v24 - 4] = v10->drivetrain_upshiftTable.mData.mItems[v24 - 4];
        v11->mDownshiftRPM.m_data[v24 - 4] = v10->drivetrain_downshiftTable.mData.mItems[v24 - 4];
        v11->m_gearsRatio.m_data[v24 - 3] = v10->drivetrain_gearRatioTable.mData.mItems[v24 - 3];
        v11->mUpshiftRPM.m_data[v24 - 3] = v10->drivetrain_upshiftTable.mData.mItems[v24 - 3];
        v11->mDownshiftRPM.m_data[v24 - 3] = v10->drivetrain_downshiftTable.mData.mItems[v24 - 3];
        v11->m_gearsRatio.m_data[v24 - 2] = v10->drivetrain_gearRatioTable.mData.mItems[v24 - 2];
        v11->mUpshiftRPM.m_data[v24 - 2] = v10->drivetrain_upshiftTable.mData.mItems[v24 - 2];
        v11->mDownshiftRPM.m_data[v24 - 2] = v10->drivetrain_downshiftTable.mData.mItems[v24 - 2];
        v11->m_gearsRatio.m_data[v24 - 1] = v10->drivetrain_gearRatioTable.mData.mItems[v24 - 1];
        v11->mUpshiftRPM.m_data[v24 - 1] = v10->drivetrain_upshiftTable.mData.mItems[v24 - 1];
        v11->mDownshiftRPM.m_data[v24 - 1] = v10->drivetrain_downshiftTable.mData.mItems[v24 - 1];
      }
      while ( v24 < v14 - 3 );
    }
    for ( ; v24 < v14; v11->mDownshiftRPM.m_data[v24 - 1] = v10->drivetrain_downshiftTable.mData.mItems[v24 - 1] )
    {
      ++v24;
      v11->m_gearsRatio.m_data[v24 - 1] = v10->drivetrain_gearRatioTable.mData.mItems[v24 - 1];
      v11->mUpshiftRPM.m_data[v24 - 1] = v10->drivetrain_upshiftTable.mData.mItems[v24 - 1];
    }
  }
  v33 = lastFrontWheel;
  v34 = v7;
  if ( v7 <= lastFrontWheel )
  {
    if ( lastFrontWheel - v7 + 1 >= 4 )
    {
      v35 = lastFrontWheel - 3i64;
      do
      {
        v34 += 4i64;
        v11->m_wheelsTorqueRatio.m_data[v34 - 4] = v10->drivetrain_frontWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v34 - 3] = v10->drivetrain_frontWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v34 - 2] = v10->drivetrain_frontWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v34 - 1] = v10->drivetrain_frontWheelTorqueRatio;
      }
      while ( v34 <= v35 );
    }
    for ( ; v34 <= v33; v11->m_wheelsTorqueRatio.m_data[v34 - 1] = v10->drivetrain_frontWheelTorqueRatio )
      ++v34;
  }
  v36 = firstRearWheel;
  v37 = lastRearWheel;
  if ( firstRearWheel <= (signed __int64)lastRearWheel )
  {
    if ( lastRearWheel - (signed __int64)firstRearWheel + 1 >= 4 )
    {
      v38 = lastRearWheel - 3i64;
      do
      {
        v36 += 4i64;
        v11->m_wheelsTorqueRatio.m_data[v36 - 4] = v10->drivetrain_rearWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v36 - 3] = v10->drivetrain_rearWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v36 - 2] = v10->drivetrain_rearWheelTorqueRatio;
        v11->m_wheelsTorqueRatio.m_data[v36 - 1] = v10->drivetrain_rearWheelTorqueRatio;
      }
      while ( v36 <= v38 );
    }
    for ( ; v36 <= v37; v11->m_wheelsTorqueRatio.m_data[v36 - 1] = v10->drivetrain_rearWheelTorqueRatio )
      ++v36;
  }
  v11->m_primaryTransmissionRatio = v10->drivetrain_finalDriveRatio;
}

// File Line: 92
// RVA: 0x4879D0
void __fastcall UFG::Transmission::getCurrentRatio(UFG::Transmission *this, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  if ( !(*((_BYTE *)this + 104) & 1) )
    hkpVehicleDefaultTransmission::getCurrentRatio(
      (hkpVehicleDefaultTransmission *)&this->vfptr,
      vehicle,
      transmissionOut);
}

// File Line: 102
// RVA: 0x483DD0
hkBool *__fastcall UFG::Transmission::calcIsReversing(UFG::Transmission *this, hkBool *result, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  result->m_bool = (char)vehicle->m_tryingToReverse;
  return result;
}

// File Line: 109
// RVA: 0x484120
float __usercall UFG::Transmission::calcTransmissionRPM@<xmm0>(UFG::Transmission *this@<rcx>, hkpVehicleInstance *vehicle@<rdx>, hkpVehicleTransmission::TransmissionOutput *transmissionOut@<r8>, float a4@<xmm0>)
{
  signed __int64 v4; // r10
  hkpVehicleTransmission::TransmissionOutput *v5; // rdi
  signed __int64 v6; // r9
  hkpVehicleInstance *v7; // rbx
  UFG::Transmission *v8; // r11
  float v9; // xmm6_4
  float *v10; // rax
  float *v11; // rdx
  unsigned __int64 v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  signed __int64 v16; // rdx
  float *v17; // r8
  signed __int64 v18; // r9
  float v19; // xmm0_4

  v4 = 0i64;
  v5 = transmissionOut;
  v6 = vehicle->m_data->m_numWheels;
  v7 = vehicle;
  v8 = this;
  v9 = 0.0;
  if ( v6 >= 4 )
  {
    v10 = this->m_wheelsTorqueRatio.m_data + 2;
    v11 = &vehicle->m_wheelsInfo.m_data[1].m_spinVelocity;
    v12 = ((unsigned __int64)(v6 - 4) >> 2) + 1;
    v4 = 4 * v12;
    do
    {
      v13 = *(v11 - 56);
      v14 = *v11;
      v10 += 4;
      v11 += 224;
      v15 = (float)((float)((float)((float)(v13 * 60.0) * 0.15915494) * *(v10 - 6)) + v9)
          + (float)((float)((float)(v14 * 60.0) * 0.15915494) * *(v10 - 5));
      a4 = (float)((float)(*(v11 - 112) * 60.0) * 0.15915494) * *(v10 - 3);
      v9 = (float)(v15 + (float)((float)((float)(*(v11 - 168) * 60.0) * 0.15915494) * *(v10 - 4))) + a4;
      --v12;
    }
    while ( v12 );
  }
  if ( v4 < v6 )
  {
    v16 = (signed __int64)&v8->m_wheelsTorqueRatio.m_data[v4];
    v17 = &v7->m_wheelsInfo.m_data[v4].m_spinVelocity;
    v18 = v6 - v4;
    do
    {
      v19 = *v17;
      v17 += 56;
      v16 += 4i64;
      a4 = (float)((float)(v19 * 60.0) * 0.15915494) * *(float *)(v16 - 4);
      v9 = v9 + a4;
      --v18;
    }
    while ( v18 );
  }
  ((void (__fastcall *)(UFG::Transmission *, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))v8->vfptr[4].__vecDelDtor)(
    v8,
    v7,
    v5);
  return a4 * v9;
}

// File Line: 142
// RVA: 0x484020
float __usercall UFG::Transmission::calcMainTransmittedTorque@<xmm0>(UFG::Transmission *this@<rcx>, hkpVehicleInstance *vehicle@<rdx>, hkpVehicleTransmission::TransmissionOutput *transmissionOut@<r8>, float a4@<xmm0>)
{
  float v5; // xmm6_4

  if ( transmissionOut->m_delayed.m_bool )
    return 0.0;
  v5 = vehicle->m_torque;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  return a4 * v5;
}

// File Line: 159
// RVA: 0x4895E0
void __fastcall UFG::Transmission::updateCurrentGear(UFG::Transmission *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleTransmission::TransmissionOutput *transmissionOut)
{
  bool v4; // zf
  float v5; // xmm2_4
  __int64 v6; // rdx
  float v7; // xmm0_4
  float v8; // eax
  __int64 v9; // rdx
  float v10; // eax

  v4 = transmissionOut->m_delayed.m_bool == 0;
  v5 = transmissionOut->m_clutchDelayCountdown - deltaTime;
  transmissionOut->m_clutchDelayCountdown = v5;
  if ( !v4 && v5 <= 0.0 )
    transmissionOut->m_delayed.m_bool = 0;
  if ( !transmissionOut->m_isReversing.m_bool )
  {
    v6 = transmissionOut->m_currentGear;
    v7 = transmissionOut->m_transmissionRPM;
    if ( transmissionOut->m_transmissionRPM < this->mDownshiftRPM.m_data[v6] && (char)v6 > 0 )
    {
      transmissionOut->m_currentGear = v6 - 1;
      v8 = this->m_clutchDelayTime;
      transmissionOut->m_delayed.m_bool = 1;
      transmissionOut->m_clutchDelayCountdown = v8;
    }
    v9 = transmissionOut->m_currentGear;
    if ( v7 > this->mUpshiftRPM.m_data[v9] && (char)v9 + 1 < this->m_gearsRatio.m_size )
    {
      transmissionOut->m_currentGear = v9 + 1;
      v10 = this->m_clutchDelayTime;
      transmissionOut->m_delayed.m_bool = 1;
      transmissionOut->m_clutchDelayCountdown = v10;
    }
  }
}

