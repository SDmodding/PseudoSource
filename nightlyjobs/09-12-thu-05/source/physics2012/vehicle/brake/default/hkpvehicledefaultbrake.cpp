// File Line: 15
// RVA: 0xE2A3B0
void __fastcall hkpVehicleDefaultBrake::hkpVehicleDefaultBrake(hkpVehicleDefaultBrake *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultBrake::`vftable;
  this->m_wheelBrakingProperties.m_capacityAndFlags = 0x80000000;
  this->m_wheelBrakingProperties.m_data = 0i64;
  this->m_wheelBrakingProperties.m_size = 0;
  this->m_wheelsMinTimeToBlock = 0.0;
}

// File Line: 22
// RVA: 0xE2A3E0
void __fastcall hkpVehicleDefaultBrake::calcBreakingInfo(
        hkpVehicleDefaultBrake *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInfo,
        hkpVehicleBrake::WheelBreakingOutput *breakingInfo)
{
  float m_brakePedalInput; // xmm4_4
  char v6; // r12
  __int64 v7; // rbx
  int v9; // edi
  bool v10; // zf
  __int64 v11; // r9
  __int64 v12; // r8
  __int64 v13; // rbp
  hkpVehicleData *m_data; // r15
  hkpVehicleDefaultBrake::WheelBrakingProperties *v15; // rdx
  float v16; // xmm3_4
  float v17; // xmm2_4
  bool v18; // cc
  int v19; // r10d
  float m_wheelsTimeSinceMaxPedalInput; // xmm0_4
  __int64 v21; // r8
  __int64 v22; // rdx

  m_brakePedalInput = filteredDriverInfo->m_brakePedalInput;
  v6 = 0;
  v7 = 0i64;
  v9 = 0;
  if ( vehicle->m_data->m_numWheels <= 0 )
    goto LABEL_18;
  v10 = filteredDriverInfo->m_handbrakeOn.m_bool == 0;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  do
  {
    breakingInfo->m_isFixed.m_data[v7].m_bool = !v10
                                             && this->m_wheelBrakingProperties.m_data[v12].m_isConnectedToHandbrake.m_bool != 0;
    m_data = vehicle->m_data;
    v15 = this->m_wheelBrakingProperties.m_data;
    v16 = m_brakePedalInput * v15[v12].m_maxBreakingTorque;
    if ( m_brakePedalInput > v15[v12].m_minPedalInputToBlock )
      v6 = 1;
    v17 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                         (float)(m_data->m_wheelParams.m_data[v11].m_radius
                               * vehicle->m_wheelsInfo.m_data[v13].m_spinVelocity)
                       * (float)((float)(1.0 / deltaTime) * m_data->m_wheelParams.m_data[v11].m_mass)) ^ _xmm[0])
        * m_data->m_wheelParams.m_data[v11].m_radius;
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v17)) >> 1) > v16 )
    {
      v18 = v17 <= 0.0;
      v17 = m_brakePedalInput * v15[v12].m_maxBreakingTorque;
      if ( v18 )
        LODWORD(v17) = LODWORD(v16) ^ _xmm[0];
    }
    ++v9;
    ++v7;
    ++v11;
    ++v13;
    ++v12;
    breakingInfo->m_brakingTorque.m_data[v7 - 1] = v17;
  }
  while ( v9 < m_data->m_numWheels );
  v19 = 0;
  if ( v6 )
  {
    m_wheelsTimeSinceMaxPedalInput = breakingInfo->m_wheelsTimeSinceMaxPedalInput;
    if ( m_wheelsTimeSinceMaxPedalInput < this->m_wheelsMinTimeToBlock )
    {
      breakingInfo->m_wheelsTimeSinceMaxPedalInput = m_wheelsTimeSinceMaxPedalInput + deltaTime;
    }
    else
    {
      v21 = 0i64;
      if ( vehicle->m_data->m_numWheels > 0 )
      {
        v22 = 0i64;
        do
        {
          if ( m_brakePedalInput > this->m_wheelBrakingProperties.m_data[v22].m_minPedalInputToBlock )
            breakingInfo->m_isFixed.m_data[v21].m_bool = 1;
          ++v19;
          ++v21;
          ++v22;
        }
        while ( v19 < vehicle->m_data->m_numWheels );
      }
    }
  }
  else
  {
LABEL_18:
    breakingInfo->m_wheelsTimeSinceMaxPedalInput = 0.0;
  }
}

