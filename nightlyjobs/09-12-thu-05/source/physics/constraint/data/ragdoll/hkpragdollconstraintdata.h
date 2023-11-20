// File Line: 85
// RVA: 0xD47EA0
void __fastcall hkpRagdollConstraintData::Atoms::Atoms(hkpRagdollConstraintData::Atoms *this)
{
  hkpRagdollConstraintData::Atoms *v1; // rbx
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
  this->m_ragdollMotors.m_type.m_storage = 19;
  this->m_ragdollMotors.m_isEnabled.m_bool = 1;
  this->m_ragdollMotors.m_initializedOffset = -1;
  this->m_ragdollMotors.m_previousTargetAnglesOffset = -1;
  this->m_angFriction.m_type.m_storage = 17;
  this->m_angFriction.m_isEnabled = 1;
  this->m_angFriction.m_numFrictionAxes = 1;
  v2 = &this->m_ballSocket.m_velocityStabilizationFactor;
  *(_WORD *)&v2[-100].m_value = 15;
  v2[-98].m_value = 1;
  *(_WORD *)&v2[-68].m_value = 16;
  v2[-66].m_value = 1;
  v2[-62].m_value = 0;
  *(_WORD *)&v2[-36].m_value = 16;
  v2[-34].m_value = 1;
  v2[-30].m_value = 0;
  *(_DWORD *)&v2[-4].m_value = 65541;
  hkUFloat8::operator=(v2, &fv);
  v1->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&v1->m_ballSocket.m_breachImpulse = 2139095022i64;
}

