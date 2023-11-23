// File Line: 15
// RVA: 0xE2A600
void __fastcall hkpVehicleDefaultEngine::hkpVehicleDefaultEngine(hkpVehicleDefaultEngine *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_minRPM = 1000.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultEngine::`vftable;
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
void __fastcall hkpVehicleDefaultEngine::calcEngineInfo(
        hkpVehicleDefaultEngine *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo,
        hkpVehicleTransmission::TransmissionOutput *transmissionInfo,
        hkpVehicleEngine::EngineOutput *engineOutput)
{
  float m_transmissionRPM; // xmm1_4
  float m_minRPM; // xmm2_4
  float m_acceleratorPedalInput; // xmm7_4
  float v9; // xmm0_4
  float m_optRPM; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float m_maxRPM; // xmm0_4
  float v16; // xmm0_4
  float m_resistanceFactorAtMaxRPM; // xmm5_4

  m_transmissionRPM = transmissionInfo->m_transmissionRPM;
  engineOutput->m_rpm = transmissionInfo->m_transmissionRPM;
  m_minRPM = this->m_minRPM;
  m_acceleratorPedalInput = filteredDriverInputInfo->m_acceleratorPedalInput;
  if ( m_transmissionRPM < m_minRPM )
  {
    v9 = m_acceleratorPedalInput * this->m_clutchSlipRPM;
    if ( m_transmissionRPM >= (float)(m_minRPM * 0.5) )
      engineOutput->m_rpm = (float)((float)((float)(m_transmissionRPM - (float)(m_minRPM * 0.5)) * v9)
                                  / (float)(m_minRPM - (float)(m_minRPM * 0.5)))
                          + m_minRPM;
    else
      engineOutput->m_rpm = m_minRPM + v9;
  }
  m_optRPM = this->m_optRPM;
  v11 = 0.0;
  v12 = engineOutput->m_rpm - m_optRPM;
  if ( v12 >= 0.0 )
  {
    m_maxRPM = this->m_maxRPM;
    if ( engineOutput->m_rpm >= m_maxRPM )
    {
      engineOutput->m_rpm = m_maxRPM;
      m_resistanceFactorAtMaxRPM = this->m_resistanceFactorAtMaxRPM;
    }
    else
    {
      v16 = m_maxRPM - m_optRPM;
      m_resistanceFactorAtMaxRPM = (float)((float)((float)(this->m_resistanceFactorAtMaxRPM
                                                         - this->m_resistanceFactorAtOptRPM)
                                                 * (float)(1.0 / v16))
                                         * v12)
                                 + this->m_resistanceFactorAtOptRPM;
      v11 = (float)((float)((float)((float)((float)(this->m_torqueFactorAtMaxRPM - 1.0) * (float)(1.0 / v16))
                                  * (float)(1.0 / v16))
                          * (float)(v12 * v12))
                  + 1.0)
          * this->m_maxTorque;
    }
    v14 = m_resistanceFactorAtMaxRPM * this->m_maxTorque;
  }
  else
  {
    v13 = this->m_minRPM - m_optRPM;
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
  engineOutput->m_torque = (float)(v11 * m_acceleratorPedalInput) - v14;
}

