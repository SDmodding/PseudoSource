// File Line: 15
// RVA: 0xE2A600
void __fastcall hkpVehicleDefaultEngine::hkpVehicleDefaultEngine(hkpVehicleDefaultEngine *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_minRPM = 1000.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultEngine::`vftable';
  this->m_optRPM = 4000.0;
  *(_QWORD *)&this->m_resistanceFactorAtOptRPM = 0i64;
  this->m_maxRPM = 6000.0;
  this->m_maxTorque = 800.0;
  this->m_torqueFactorAtMinRPM = 1.0;
  *(_QWORD *)&this->m_torqueFactorAtMaxRPM = 1065353216i64;
  this->m_clutchSlipRPM = 2000.0;
}

// File Line: 30
// RVA: 0xE2A660
void __fastcall hkpVehicleDefaultEngine::calcEngineInfo(hkpVehicleDefaultEngine *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo, hkpVehicleTransmission::TransmissionOutput *transmissionInfo, hkpVehicleEngine::EngineOutput *engineOutput)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm5_4

  v6 = transmissionInfo->m_transmissionRPM;
  engineOutput->m_rpm = transmissionInfo->m_transmissionRPM;
  v7 = this->m_minRPM;
  v8 = filteredDriverInputInfo->m_acceleratorPedalInput;
  if ( v6 < v7 )
  {
    v9 = v8 * this->m_clutchSlipRPM;
    if ( v6 >= (float)(v7 * 0.5) )
      engineOutput->m_rpm = (float)((float)((float)(v6 - (float)(v7 * 0.5)) * v9) / (float)(v7 - (float)(v7 * 0.5)))
                          + v7;
    else
      engineOutput->m_rpm = v7 + v9;
  }
  v10 = this->m_optRPM;
  v11 = 0.0;
  v12 = engineOutput->m_rpm - v10;
  if ( v12 >= 0.0 )
  {
    v15 = this->m_maxRPM;
    if ( engineOutput->m_rpm >= v15 )
    {
      engineOutput->m_rpm = v15;
      v17 = this->m_resistanceFactorAtMaxRPM;
    }
    else
    {
      v16 = v15 - v10;
      v17 = (float)((float)((float)(this->m_resistanceFactorAtMaxRPM - this->m_resistanceFactorAtOptRPM)
                          * (float)(1.0 / v16))
                  * v12)
          + this->m_resistanceFactorAtOptRPM;
      v11 = (float)((float)((float)((float)((float)(this->m_torqueFactorAtMaxRPM - 1.0) * (float)(1.0 / v16))
                                  * (float)(1.0 / v16))
                          * (float)(v12 * v12))
                  + 1.0)
          * this->m_maxTorque;
    }
    v14 = v17 * this->m_maxTorque;
  }
  else
  {
    v13 = this->m_minRPM - v10;
    v14 = (float)((float)((float)((float)(this->m_resistanceFactorAtMinRPM - this->m_resistanceFactorAtOptRPM)
                                * (float)(1.0 / v13))
                        * v12)
                + this->m_resistanceFactorAtOptRPM)
        * this->m_maxTorque;
    v11 = (float)((float)((float)((float)((float)(this->m_torqueFactorAtMinRPM - 1.0) * (float)(1.0 / v13))
                                * (float)(1.0 / v13))
                        * (float)(v12 * v12))
                + 1.0)
        * this->m_maxTorque;
    if ( transmissionInfo->m_transmissionRPM < this->m_minRPM )
      v14 = v14 * (float)(transmissionInfo->m_transmissionRPM / this->m_minRPM);
  }
  engineOutput->m_torque = (float)(v11 * v8) - v14;
}

