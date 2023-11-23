// File Line: 13
// RVA: 0x12FEA90
void __fastcall hkMotionState::initMotionState(hkMotionState *this, hkVector4f *position, hkQuaternionf *rotation)
{
  float fv; // [rsp+30h] [rbp+8h] BYREF

  hkSweptTransformf::initSweptTransform(&this->m_sweptTransform, position, rotation);
  hkRotationf::set(&this->m_transform.m_rotation, rotation);
  this->m_transform.m_translation = (hkVector4f)position->m_quad;
  this->m_deltaAngle = 0i64;
  fv = 0.0;
  *(_QWORD *)&this->m_objectRadius = 1065353216i64;
  this->m_timeFactor.m_value = 0;
  hkUFloat8::operator=(&this->m_maxLinearVelocity, &fv);
  fv = 0.0;
  hkUFloat8::operator=(&this->m_maxAngularVelocity, &fv);
  this->m_deactivationClass = 0;
}

