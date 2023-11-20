// File Line: 44
// RVA: 0x469FB0
void __fastcall UFG::Engine::InitializeFromPropertySet(UFG::Engine *this, UFG::WheeledVehiclePhysicsDef *vehicle_data_ptr)
{
  UFG::WheeledVehiclePhysicsDef *v2; // rdi
  UFG::Engine *v3; // rbx
  unsigned int v4; // esi
  float *v5; // rcx
  unsigned int v6; // ebp
  unsigned int v7; // edx
  signed __int64 v8; // rdx
  unsigned int v9; // eax
  __int64 v10; // r8
  signed __int64 v11; // rdx
  __int64 v12; // r8

  v2 = vehicle_data_ptr;
  v3 = this;
  this->m_clutchSlipRPM = vehicle_data_ptr->engine_clutchSlipRPM;
  v4 = vehicle_data_ptr->torqueTable.mData.mNumItems;
  if ( v4 )
  {
    v5 = this->mTorqueTable.p;
    if ( v5 )
      operator delete[](v5);
    v6 = 0;
    v3->mTorqueTable.p = 0i64;
    *(_QWORD *)&v3->mTorqueTable.size = 0i64;
    if ( (signed int)v4 <= 0 )
    {
      if ( v4 )
        v3->mTorqueTable.size = 0;
    }
    else
    {
      v7 = 1;
      if ( v4 <= 1 )
        goto LABEL_25;
      do
        v7 *= 2;
      while ( v7 < v4 );
      if ( v7 <= 4 )
LABEL_25:
        v7 = 4;
      if ( v7 - v4 > 0x10000 )
        v7 = v4 + 0x10000;
      UFG::qArray<float,0>::Reallocate(&v3->mTorqueTable, v7, "mTorqueTable");
      v3->mTorqueTable.size = v4;
    }
    v8 = 0i64;
    if ( (signed int)v4 >= 4 )
    {
      v9 = ((v4 - 4) >> 2) + 1;
      v10 = v9;
      v6 = 4 * v9;
      do
      {
        v8 += 4i64;
        v3->mTorqueTable.p[v8 - 4] = v2->torqueTable.mData.mItems[v8 - 4];
        v3->mTorqueTable.p[v8 - 3] = v2->torqueTable.mData.mItems[v8 - 3];
        v3->mTorqueTable.p[v8 - 2] = v2->torqueTable.mData.mItems[v8 - 2];
        v3->mTorqueTable.p[v8 - 1] = v2->torqueTable.mData.mItems[v8 - 1];
        --v10;
      }
      while ( v10 );
    }
    if ( v6 < v4 )
    {
      v11 = v8;
      v12 = v4 - v6;
      do
      {
        ++v11;
        v3->mTorqueTable.p[v11 - 1] = v2->torqueTable.mData.mItems[v11 - 1];
        --v12;
      }
      while ( v12 );
    }
    v3->m_minRPM = 500.0;
    v3->m_maxRPM = (float)(signed int)v4 * 500.0;
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
  v3->mEngineResistanceMin = v2->engine_resistanceMin;
  v3->mEngineResistanceMax = v2->engine_resistanceMax;
  v3->mEngineResistanceMinSpeed = v2->engine_resistanceMinSpeed;
  v3->mEngineResistanceMaxSpeed = v2->engine_resistanceMaxSpeed;
}

// File Line: 84
// RVA: 0x483A60
void __fastcall UFG::Engine::calcEngineInfo(UFG::Engine *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputOutput, hkpVehicleTransmission::TransmissionOutput *transmissionInfo, hkpVehicleEngine::EngineOutput *engineOutput)
{
  hkpVehicleInstance *v6; // r10
  UFG::Engine *v7; // rbx
  float v8; // xmm11_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  __m128 v15; // xmm1
  signed int v16; // ecx
  unsigned int v17; // er8
  float v18; // xmm2_4
  __int64 v19; // rdx
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm1_4

  v6 = vehicle;
  v7 = this;
  v8 = filteredDriverInputOutput->m_acceleratorPedalInput;
  LODWORD(v9) = LODWORD(transmissionInfo->m_transmissionRPM) & _xmm;
  engineOutput->m_rpm = v9;
  if ( !this->mTorqueTable.size )
  {
    v20 = this->m_minRPM;
    if ( v9 < v20 )
    {
      v21 = v8 * this->m_clutchSlipRPM;
      if ( v9 >= (float)(v20 * 0.5) )
        engineOutput->m_rpm = (float)((float)((float)(v9 - (float)(v20 * 0.5)) * v21) / (float)(v20 - (float)(v20 * 0.5)))
                            + v20;
      else
        engineOutput->m_rpm = v20 + v21;
    }
    v22 = this->m_optRPM;
    v23 = engineOutput->m_rpm - v22;
    if ( v23 >= 0.0 )
    {
      v25 = this->m_maxRPM;
      if ( engineOutput->m_rpm >= v25 )
      {
        engineOutput->m_rpm = v25;
        v13 = this->m_maxTorque;
        goto LABEL_29;
      }
      v24 = (float)((float)(this->m_torqueFactorAtMaxRPM - 1.0) * (float)(1.0 / (float)(v25 - v22)))
          * (float)(1.0 / (float)(v25 - v22));
    }
    else
    {
      v24 = (float)((float)(this->m_torqueFactorAtMinRPM - 1.0) * (float)(1.0 / (float)(this->m_minRPM - v22)))
          * (float)(1.0 / (float)(this->m_minRPM - v22));
    }
    v13 = (float)((float)(v24 * (float)(v23 * v23)) + 1.0) * this->m_maxTorque;
    goto LABEL_29;
  }
  v10 = this->m_clutchSlipRPM;
  if ( v9 < v10 && v8 > 0.0 )
    engineOutput->m_rpm = v10;
  v11 = engineOutput->m_rpm;
  v12 = this->m_minRPM;
  if ( v11 >= v12 )
  {
    v14 = this->m_maxRPM;
    if ( v11 <= v14 )
    {
      v15 = (__m128)LODWORD(engineOutput->m_rpm);
      v15.m128_f32[0] = (float)(v11 - v12) * 0.0020000001;
      v16 = (signed int)v15.m128_f32[0];
      if ( (signed int)v15.m128_f32[0] != 0x80000000 && (float)v16 != v15.m128_f32[0] )
        v15.m128_f32[0] = (float)(v16 - (_mm_movemask_ps(_mm_unpacklo_ps(v15, v15)) & 1));
      v17 = (signed int)v15.m128_f32[0];
      v18 = (float)(v11 - (float)((float)((float)(signed int)v15.m128_f32[0] * 500.0) + v12)) * 0.0020000001;
      if ( v18 <= 0.0 )
      {
        v18 = 0.0;
      }
      else if ( v18 >= 1.0 )
      {
        v18 = *(float *)&FLOAT_1_0;
      }
      v19 = v17 + 1;
      if ( (_DWORD)v19 == v7->mTorqueTable.size - 1 )
        v19 = v17;
      v13 = (float)((float)(v7->mTorqueTable.p[v19] - v7->mTorqueTable.p[v17]) * v18) + v7->mTorqueTable.p[v17];
    }
    else
    {
      engineOutput->m_rpm = v14;
      v13 = 0.0;
    }
  }
  else
  {
    v13 = *this->mTorqueTable.p;
    engineOutput->m_rpm = v12;
  }
LABEL_29:
  v26 = v7->mDamage;
  v27 = *(float *)&FLOAT_1_0;
  if ( v26 >= 0.80000001 )
    v27 = 1.0 - v26;
  v6->vfptr[6].__first_virtual_table_function__((hkBaseObject *)&v6->vfptr);
  v28 = v26;
  if ( v8 > 0.02 || (LODWORD(v29) = LODWORD(v26) & _xmm, COERCE_FLOAT(LODWORD(v26) & _xmm) <= 1.0) )
  {
    engineOutput->m_torque = (float)((float)(v13 + v7->mTorqueBoost) * v8) * v27;
  }
  else
  {
    v30 = v7->mEngineResistanceMax;
    v31 = v7->mEngineResistanceMin;
    v32 = v7->mEngineResistanceMinSpeed;
    if ( v31 >= v30 )
      v33 = v7->mEngineResistanceMax;
    else
      v33 = v7->mEngineResistanceMin;
    if ( v31 <= v30 )
      v34 = v7->mEngineResistanceMax;
    else
      v34 = v7->mEngineResistanceMin;
    v35 = FLOAT_0_000099999997;
    if ( (float)(v7->mEngineResistanceMaxSpeed - v32) >= 0.000099999997 )
      v35 = v7->mEngineResistanceMaxSpeed - v32;
    v36 = (float)((float)(v29 - v32) * (float)((float)(v30 - v31) / v35)) + v31;
    if ( v36 <= v33 )
      v36 = v33;
    if ( v36 >= v34 )
      v36 = v34;
    LODWORD(v37) = COERCE_UNSIGNED_INT(v36 * v7->m_maxTorque) ^ _xmm[0];
    engineOutput->m_torque = v37;
    if ( !transmissionInfo->m_isReversing.m_bool && transmissionInfo->m_transmissionRPM < 0.0 )
      LODWORD(engineOutput->m_torque) = LODWORD(v37) ^ _xmm[0];
  }
  if ( v28 > v7->mGovernorSpeedKPH && engineOutput->m_torque > 0.0 )
    engineOutput->m_torque = 0.0;
}

