// File Line: 51
// RVA: 0xD46D20
void __fastcall hkpHingeConstraintData::Atoms::Atoms(hkpHingeConstraintData::Atoms *this)
{
  float fv; // [rsp+30h] [rbp+8h] BYREF

  this->m_transforms.m_type.m_storage = 2;
  LODWORD(fv) = (_DWORD)FLOAT_1_0;
  this->m_setupStabilization.m_type.m_storage = 23;
  this->m_setupStabilization.m_enabled.m_bool = 0;
  this->m_setupStabilization.m_maxLinImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngle = 1.8446726e19;
  this->m_2dAng.m_type.m_storage = 12;
  *(_DWORD *)&this->m_ballSocket.m_type.m_storage = 65541;
  hkUFloat8::operator=(&this->m_ballSocket.m_velocityStabilizationFactor, &fv);
  this->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&this->m_ballSocket.m_breachImpulse = 2139095022i64;
}

