// File Line: 44
// RVA: 0x469FB0
void __fastcall UFG::Engine::InitializeFromPropertySet(
        UFG::Engine *this,
        UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr)
{
  int mNumItems; // esi
  float *p; // rcx
  unsigned int v6; // ebp
  unsigned int v7; // edx
  __int64 v8; // rdx
  unsigned int v9; // eax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // r8

  this->m_clutchSlipRPM = vehicle_data_ptr->engine_clutchSlipRPM;
  mNumItems = vehicle_data_ptr->torqueTable.mData.mNumItems;
  if ( mNumItems )
  {
    p = this->mTorqueTable.p;
    if ( p )
      operator delete[](p);
    v6 = 0;
    this->mTorqueTable.p = 0i64;
    *(_QWORD *)&this->mTorqueTable.size = 0i64;
    if ( mNumItems <= 0 )
    {
      this->mTorqueTable.size = 0;
    }
    else
    {
      v7 = 1;
      if ( (unsigned int)mNumItems <= 1 )
        goto LABEL_8;
      do
        v7 *= 2;
      while ( v7 < mNumItems );
      if ( v7 <= 4 )
LABEL_8:
        v7 = 4;
      if ( v7 - mNumItems > 0x10000 )
        v7 = mNumItems + 0x10000;
      UFG::qArray<float,0>::Reallocate(&this->mTorqueTable, v7, "mTorqueTable");
      this->mTorqueTable.size = mNumItems;
    }
    v8 = 0i64;
    if ( mNumItems >= 4 )
    {
      v9 = ((unsigned int)(mNumItems - 4) >> 2) + 1;
      v10 = v9;
      v6 = 4 * v9;
      do
      {
        v8 += 4i64;
        this->mTorqueTable.p[v8 - 4] = vehicle_data_ptr->torqueTable.mData.mItems[v8 - 4];
        this->mTorqueTable.p[v8 - 3] = vehicle_data_ptr->torqueTable.mData.mItems[v8 - 3];
        this->mTorqueTable.p[v8 - 2] = vehicle_data_ptr->torqueTable.mData.mItems[v8 - 2];
        this->mTorqueTable.p[v8 - 1] = vehicle_data_ptr->torqueTable.mData.mItems[v8 - 1];
        --v10;
      }
      while ( v10 );
    }
    if ( v6 < mNumItems )
    {
      v11 = v8;
      v12 = mNumItems - v6;
      do
      {
        ++v11;
        this->mTorqueTable.p[v11 - 1] = vehicle_data_ptr->torqueTable.mData.mItems[v11 - 1];
        --v12;
      }
      while ( v12 );
    }
    this->m_minRPM = 500.0;
    this->m_maxRPM = (float)mNumItems * 500.0;
  }
  else
  {
    this->m_maxTorque = vehicle_data_ptr->engine_maxTorque;
    this->m_minRPM = vehicle_data_ptr->engine_minRPM;
    this->m_optRPM = vehicle_data_ptr->engine_optRPM;
    this->m_maxRPM = vehicle_data_ptr->engine_maxRPM;
    this->m_torqueFactorAtMinRPM = vehicle_data_ptr->engine_torqueFactorAtMinRPM;
    this->m_torqueFactorAtMaxRPM = vehicle_data_ptr->engine_torqueFactorAtMaxRPM;
  }
  this->mEngineResistanceMin = vehicle_data_ptr->engine_resistanceMin;
  this->mEngineResistanceMax = vehicle_data_ptr->engine_resistanceMax;
  this->mEngineResistanceMinSpeed = vehicle_data_ptr->engine_resistanceMinSpeed;
  this->mEngineResistanceMaxSpeed = vehicle_data_ptr->engine_resistanceMaxSpeed;
}

// File Line: 84
// RVA: 0x483A60
void __fastcall UFG::Engine::calcEngineInfo(
        UFG::Engine *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputOutput,
        hkpVehicleTransmission::TransmissionOutput *transmissionInfo,
        hkpVehicleEngine::EngineOutput *engineOutput)
{
  float m_acceleratorPedalInput; // xmm11_4
  float v9; // xmm1_4
  float m_clutchSlipRPM; // xmm0_4
  float m_rpm; // xmm2_4
  float v12; // xmm3_4
  float m_maxTorque; // xmm6_4
  float v14; // xmm0_4
  __m128 m_rpm_low; // xmm1
  int v16; // ecx
  unsigned int v17; // r8d
  float v18; // xmm2_4
  __int64 v19; // rdx
  float m_minRPM; // xmm2_4
  float v21; // xmm0_4
  float m_optRPM; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  float m_maxRPM; // xmm1_4
  float mDamage; // xmm0_4
  float v27; // xmm9_4
  double v28; // xmm0_8
  float v29; // xmm10_4
  float v30; // xmm1_4
  float mEngineResistanceMax; // xmm2_4
  float mEngineResistanceMin; // xmm0_4
  float mEngineResistanceMinSpeed; // xmm7_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  float v38; // xmm1_4

  m_acceleratorPedalInput = filteredDriverInputOutput->m_acceleratorPedalInput;
  LODWORD(v9) = LODWORD(transmissionInfo->m_transmissionRPM) & _xmm;
  engineOutput->m_rpm = v9;
  if ( !this->mTorqueTable.size )
  {
    m_minRPM = this->m_minRPM;
    if ( v9 < m_minRPM )
    {
      v21 = m_acceleratorPedalInput * this->m_clutchSlipRPM;
      if ( v9 >= (float)(m_minRPM * 0.5) )
        engineOutput->m_rpm = (float)((float)((float)(v9 - (float)(m_minRPM * 0.5)) * v21)
                                    / (float)(m_minRPM - (float)(m_minRPM * 0.5)))
                            + m_minRPM;
      else
        engineOutput->m_rpm = m_minRPM + v21;
    }
    m_optRPM = this->m_optRPM;
    v23 = engineOutput->m_rpm - m_optRPM;
    if ( v23 >= 0.0 )
    {
      m_maxRPM = this->m_maxRPM;
      if ( engineOutput->m_rpm >= m_maxRPM )
      {
        engineOutput->m_rpm = m_maxRPM;
        m_maxTorque = this->m_maxTorque;
        goto LABEL_29;
      }
      v24 = (float)((float)(this->m_torqueFactorAtMaxRPM - 1.0) * (float)(1.0 / (float)(m_maxRPM - m_optRPM)))
          * (float)(1.0 / (float)(m_maxRPM - m_optRPM));
    }
    else
    {
      v24 = (float)((float)(this->m_torqueFactorAtMinRPM - 1.0) * (float)(1.0 / (float)(this->m_minRPM - m_optRPM)))
          * (float)(1.0 / (float)(this->m_minRPM - m_optRPM));
    }
    m_maxTorque = (float)((float)(v24 * (float)(v23 * v23)) + 1.0) * this->m_maxTorque;
    goto LABEL_29;
  }
  m_clutchSlipRPM = this->m_clutchSlipRPM;
  if ( v9 < m_clutchSlipRPM && m_acceleratorPedalInput > 0.0 )
    engineOutput->m_rpm = m_clutchSlipRPM;
  m_rpm = engineOutput->m_rpm;
  v12 = this->m_minRPM;
  if ( m_rpm >= v12 )
  {
    v14 = this->m_maxRPM;
    if ( m_rpm <= v14 )
    {
      m_rpm_low = (__m128)LODWORD(engineOutput->m_rpm);
      m_rpm_low.m128_f32[0] = (float)(m_rpm - v12) * 0.0020000001;
      v16 = (int)m_rpm_low.m128_f32[0];
      if ( (int)m_rpm_low.m128_f32[0] != 0x80000000 && (float)v16 != m_rpm_low.m128_f32[0] )
        m_rpm_low.m128_f32[0] = (float)(v16 - (_mm_movemask_ps(_mm_unpacklo_ps(m_rpm_low, m_rpm_low)) & 1));
      v17 = (int)m_rpm_low.m128_f32[0];
      v18 = (float)(m_rpm - (float)((float)((float)(int)m_rpm_low.m128_f32[0] * 500.0) + v12)) * 0.0020000001;
      if ( v18 <= 0.0 )
      {
        v18 = 0.0;
      }
      else if ( v18 >= 1.0 )
      {
        v18 = *(float *)&FLOAT_1_0;
      }
      v19 = v17 + 1;
      if ( (_DWORD)v19 == this->mTorqueTable.size - 1 )
        v19 = v17;
      m_maxTorque = (float)((float)(this->mTorqueTable.p[v19] - this->mTorqueTable.p[v17]) * v18)
                  + this->mTorqueTable.p[v17];
    }
    else
    {
      engineOutput->m_rpm = v14;
      m_maxTorque = 0.0;
    }
  }
  else
  {
    m_maxTorque = *this->mTorqueTable.p;
    engineOutput->m_rpm = v12;
  }
LABEL_29:
  mDamage = this->mDamage;
  v27 = *(float *)&FLOAT_1_0;
  if ( mDamage >= 0.80000001 )
    v27 = 1.0 - mDamage;
  v28 = ((double (__fastcall *)(hkpVehicleInstance *))vehicle->vfptr[6].__first_virtual_table_function__)(vehicle);
  v29 = *(float *)&v28;
  if ( m_acceleratorPedalInput > 0.02 || (LODWORD(v30) = LODWORD(v28) & _xmm, COERCE_FLOAT(LODWORD(v28) & _xmm) <= 1.0) )
  {
    engineOutput->m_torque = (float)((float)(m_maxTorque + this->mTorqueBoost) * m_acceleratorPedalInput) * v27;
  }
  else
  {
    mEngineResistanceMax = this->mEngineResistanceMax;
    mEngineResistanceMin = this->mEngineResistanceMin;
    mEngineResistanceMinSpeed = this->mEngineResistanceMinSpeed;
    if ( mEngineResistanceMin >= mEngineResistanceMax )
      v34 = this->mEngineResistanceMax;
    else
      v34 = this->mEngineResistanceMin;
    if ( mEngineResistanceMin <= mEngineResistanceMax )
      v35 = this->mEngineResistanceMax;
    else
      v35 = this->mEngineResistanceMin;
    v36 = FLOAT_0_000099999997;
    if ( (float)(this->mEngineResistanceMaxSpeed - mEngineResistanceMinSpeed) >= 0.000099999997 )
      v36 = this->mEngineResistanceMaxSpeed - mEngineResistanceMinSpeed;
    v37 = (float)((float)(v30 - mEngineResistanceMinSpeed)
                * (float)((float)(mEngineResistanceMax - mEngineResistanceMin) / v36))
        + mEngineResistanceMin;
    if ( v37 <= v34 )
      v37 = v34;
    if ( v37 >= v35 )
      v37 = v35;
    LODWORD(v38) = COERCE_UNSIGNED_INT(v37 * this->m_maxTorque) ^ _xmm[0];
    engineOutput->m_torque = v38;
    if ( !transmissionInfo->m_isReversing.m_bool && transmissionInfo->m_transmissionRPM < 0.0 )
      LODWORD(engineOutput->m_torque) = LODWORD(v38) ^ _xmm[0];
  }
  if ( v29 > this->mGovernorSpeedKPH && engineOutput->m_torque > 0.0 )
    engineOutput->m_torque = 0.0;
}

