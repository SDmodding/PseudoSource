// File Line: 85
// RVA: 0xD47EA0
void __fastcall hkpRagdollConstraintData::Atoms::Atoms(hkpRagdollConstraintData::Atoms *this)
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
  this->m_ragdollMotors.m_type.m_storage = 19;
  this->m_ragdollMotors.m_isEnabled.m_bool = 1;
  this->m_ragdollMotors.m_initializedOffset = -1;
  this->m_ragdollMotors.m_previousTargetAnglesOffset = -1;
  this->m_angFriction.m_type.m_storage = 17;
  this->m_angFriction.m_isEnabled = 1;
  this->m_angFriction.m_numFrictionAxes = 1;
  p_m_velocityStabilizationFactor = &this->m_ballSocket.m_velocityStabilizationFactor;
  *(_WORD *)&p_m_velocityStabilizationFactor[-100].m_value = 15;
  p_m_velocityStabilizationFactor[-98].m_value = 1;
  *(_WORD *)&p_m_velocityStabilizationFactor[-68].m_value = 16;
  p_m_velocityStabilizationFactor[-66].m_value = 1;
  p_m_velocityStabilizationFactor[-62].m_value = 0;
  *(_WORD *)&p_m_velocityStabilizationFactor[-36].m_value = 16;
  p_m_velocityStabilizationFactor[-34].m_value = 1;
  p_m_velocityStabilizationFactor[-30].m_value = 0;
  *(_DWORD *)&p_m_velocityStabilizationFactor[-4].m_value = 65541;
  hkUFloat8::operator=(p_m_velocityStabilizationFactor, &fv);
  this->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&this->m_ballSocket.m_breachImpulse = 2139095022i64;
}

