// File Line: 15
// RVA: 0xE2A3B0
void __fastcall hkpVehicleDefaultBrake::hkpVehicleDefaultBrake(hkpVehicleDefaultBrake *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultBrake::`vftable;
  this->m_wheelBrakingProperties.m_capacityAndFlags = 2147483648;
  this->m_wheelBrakingProperties.m_data = 0i64;
  this->m_wheelBrakingProperties.m_size = 0;
  this->m_wheelsMinTimeToBlock = 0.0;
}

// File Line: 22
// RVA: 0xE2A3E0
void __fastcall hkpVehicleDefaultBrake::calcBreakingInfo(hkpVehicleDefaultBrake *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInfo, hkpVehicleBrake::WheelBreakingOutput *breakingInfo)
{
  float v5; // xmm4_4
  char v6; // r12
  __int64 v7; // rbx
  hkpVehicleInstance *v8; // rsi
  hkpVehicleDefaultBrake *v9; // r14
  signed int v10; // edi
  bool v11; // zf
  __int64 v12; // r9
  __int64 v13; // r8
  __int64 v14; // rbp
  bool v15; // r13
  float v16; // xmm7_4
  hkpVehicleData *v17; // r15
  hkpVehicleDefaultBrake::WheelBrakingProperties *v18; // rdx
  hkpVehicleData::WheelComponentParams *v19; // rcx
  float v20; // xmm3_4
  float v21; // xmm2_4
  bool v22; // cf
  signed int v23; // er10
  float v24; // xmm0_4
  __int64 v25; // r8
  __int64 v26; // rdx

  v5 = filteredDriverInfo->m_brakePedalInput;
  v6 = 0;
  v7 = 0i64;
  v8 = vehicle;
  v9 = this;
  v10 = 0;
  if ( vehicle->m_data->m_numWheels <= 0 )
    goto LABEL_21;
  v11 = filteredDriverInfo->m_handbrakeOn.m_bool == 0;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = !v11;
  v16 = 1.0 / deltaTime;
  do
  {
    breakingInfo->m_isFixed.m_data[v7].m_bool = v15
                                             && v9->m_wheelBrakingProperties.m_data[v13].m_isConnectedToHandbrake.m_bool != 0;
    v17 = v8->m_data;
    v18 = v9->m_wheelBrakingProperties.m_data;
    v19 = v17->m_wheelParams.m_data;
    v20 = v5 * v18[v13].m_maxBreakingTorque;
    if ( v5 > v18[v13].m_minPedalInputToBlock )
      v6 = 1;
    v21 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                         (float)(v19[v12].m_radius * v8->m_wheelsInfo.m_data[v14].m_spinVelocity)
                       * (float)(v16 * v19[v12].m_mass)) ^ _xmm[0])
        * v19[v12].m_radius;
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v21)) >> 1) > v20 )
    {
      v22 = v21 < 0.0;
      v11 = v21 == 0.0;
      v21 = v5 * v18[v13].m_maxBreakingTorque;
      if ( v22 || v11 )
        LODWORD(v21) = LODWORD(v20) ^ _xmm[0];
    }
    ++v10;
    ++v7;
    ++v12;
    ++v14;
    ++v13;
    breakingInfo->m_brakingTorque.m_data[v7 - 1] = v21;
  }
  while ( v10 < v17->m_numWheels );
  v23 = 0;
  if ( v6 )
  {
    v24 = breakingInfo->m_wheelsTimeSinceMaxPedalInput;
    if ( v24 < v9->m_wheelsMinTimeToBlock )
    {
      breakingInfo->m_wheelsTimeSinceMaxPedalInput = v24 + deltaTime;
    }
    else
    {
      v25 = 0i64;
      if ( v8->m_data->m_numWheels > 0 )
      {
        v26 = 0i64;
        do
        {
          if ( v5 > v9->m_wheelBrakingProperties.m_data[v26].m_minPedalInputToBlock )
            breakingInfo->m_isFixed.m_data[v25].m_bool = 1;
          ++v23;
          ++v25;
          ++v26;
        }
        while ( v23 < v8->m_data->m_numWheels );
      }
    }
  }
  else
  {
LABEL_21:
    breakingInfo->m_wheelsTimeSinceMaxPedalInput = 0.0;
  }
}

