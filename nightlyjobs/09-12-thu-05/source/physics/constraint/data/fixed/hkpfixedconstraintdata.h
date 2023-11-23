// File Line: 43
// RVA: 0xD46520
void __fastcall hkpFixedConstraintData::Atoms::Atoms(hkpFixedConstraintData::Atoms *this)
{
  float fv; // [rsp+30h] [rbp+8h] BYREF

  this->m_transforms.m_type.m_storage = 2;
  LODWORD(fv) = (_DWORD)FLOAT_1_0;
  this->m_setupStabilization.m_type.m_storage = 23;
  this->m_setupStabilization.m_enabled.m_bool = 0;
  this->m_setupStabilization.m_maxLinImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngle = 1.8446726e19;
  *(_DWORD *)&this->m_ballSocket.m_type.m_storage = 65541;
  hkUFloat8::operator=(&this->m_ballSocket.m_velocityStabilizationFactor, &fv);
  this->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&this->m_ballSocket.m_breachImpulse = 2139095022i64;
  this->m_ang.m_type.m_storage = 24;
}

