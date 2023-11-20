// File Line: 66
// RVA: 0xD45CA0
void __fastcall hkpLimitedHingeConstraintData::Atoms::Atoms(hkpLimitedHingeConstraintData::Atoms *this)
{
  hkpLimitedHingeConstraintData::Atoms *v1; // rbx
  hkUFloat8 *v2; // rcx
  float fv; // [rsp+30h] [rbp+8h]

  v1 = this;
  this->m_transforms.m_type.m_storage = 2;
  fv = *(float *)&FLOAT_1_0;
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
  v2 = &this->m_ballSocket.m_velocityStabilizationFactor;
  *(_WORD *)&v2[-52].m_value = 17;
  v2[-50].m_value = 1;
  v2[-48].m_value = 1;
  *(_WORD *)&v2[-36].m_value = 14;
  v2[-34].m_value = 1;
  *(_WORD *)&v2[-20].m_value = 12;
  *(_DWORD *)&v2[-4].m_value = 65541;
  hkUFloat8::operator=(v2, &fv);
  v1->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&v1->m_ballSocket.m_breachImpulse = 2139095022i64;
}

