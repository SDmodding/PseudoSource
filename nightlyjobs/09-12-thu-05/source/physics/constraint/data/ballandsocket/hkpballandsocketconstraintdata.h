// File Line: 44
// RVA: 0xD46040
void __fastcall hkpBallAndSocketConstraintData::Atoms::Atoms(hkpBallAndSocketConstraintData::Atoms *this)
{
  hkpBallAndSocketConstraintData::Atoms *v1; // rbx
  float fv; // [rsp+30h] [rbp+8h]

  v1 = this;
  this->m_pivots.m_type.m_storage = 3;
  fv = *(float *)&FLOAT_1_0;
  this->m_setupStabilization.m_type.m_storage = 23;
  this->m_setupStabilization.m_enabled.m_bool = 0;
  this->m_setupStabilization.m_maxLinImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngImpulse = 3.40282e38;
  this->m_setupStabilization.m_maxAngle = 1.8446726e19;
  *(_DWORD *)&this->m_ballSocket.m_type.m_storage = 65541;
  hkUFloat8::operator=(&this->m_ballSocket.m_velocityStabilizationFactor, &fv);
  v1->m_ballSocket.m_enableLinearImpulseLimit.m_bool = 0;
  *(_QWORD *)&v1->m_ballSocket.m_breachImpulse = 2139095022i64;
}

