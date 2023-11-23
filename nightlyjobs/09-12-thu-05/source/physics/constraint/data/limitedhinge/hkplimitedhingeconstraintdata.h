// File Line: 66
// RVA: 0xD45CA0
void __fastcall hkpLimitedHingeConstraintData::Atoms::Atoms(hkpLimitedHingeConstraintData::Atoms *this)
{
  hkUFloat8 *p_m_velocityStabilizationFactor; // rcx
  float fv; // [rsp+30h] [rbp+8h] BYREF

  this->m_transforms.m_type.m_storage = 2;
  LODWORD(fv) = (_DWORD)FLOAT_1_0;
  this->m_setupStabilization.m_type.m_storage = 23;
  this->m_setupStabilization.m_enabled.m_bool = 0;
  this->m_setupStabilization.m_maxLinImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngle = 1.8446726e19;
  this->m_angMotor.m_type.m_storage = 18;
  this->m_angMotor.m_isEnabled.m_bool = 1;
  this->m_angMotor.m_initializedOffset = -1;
  this->m_angMotor.m_previousTargetAngleOffset = -1;
  this->m_angMotor.m_correspondingAngLimitSolverResultOffset = -1;
  p_m_velocityStabilizationFactor = &this->m_ballSocket.m_velocityStabilizationFactor;
  *(_WORD *)&p_m_velocityStabilizationFactor[-52].m_value = 17;
  p_m_velocityStabilizationFactor[-50].m_value = 1;
  p_m_velocityStabilizationFactor[-48].m_value = 1;
  *(_WORD *)&p_m_velocityStabilizationFactor[-36].m_value = 14;
  p_m_velocityStabilizationFactor[-34].m_value = 1;
  *(_WORD *)&p_m_velocityStabilizationFactor[-20].m_value = 12;
  *(_DWORD *)&p_m_velocityStabilizationFactor[-4].m_value = 65541;
  hkUFloat8::operator=(p_m_velocityStabilizationFactor, &fv);
  this->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&this->m_ballSocket.m_breachImpulse = 2139095022i64;
}

