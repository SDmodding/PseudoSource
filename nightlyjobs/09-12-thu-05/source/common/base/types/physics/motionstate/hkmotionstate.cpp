// File Line: 13
// RVA: 0x12FEA90
void __fastcall hkMotionState::initMotionState(hkMotionState *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkMotionState *v3; // rsi
  hkQuaternionf *v4; // rbx
  hkVector4f *v5; // rdi
  float fv; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = rotation;
  v5 = position;
  hkSweptTransformf::initSweptTransform(&this->m_sweptTransform, position, rotation);
  hkRotationf::set(&v3->m_transform.m_rotation, v4);
  v3->m_transform.m_translation = (hkVector4f)v5->m_quad;
  v3->m_deltaAngle = 0i64;
  fv = 0.0;
  *(_QWORD *)&v3->m_objectRadius = 1065353216i64;
  v3->m_timeFactor.m_value = 0;
  hkUFloat8::operator=(&v3->m_maxLinearVelocity, &fv);
  fv = 0.0;
  hkUFloat8::operator=(&v3->m_maxAngularVelocity, &fv);
  v3->m_deactivationClass = 0;
}

