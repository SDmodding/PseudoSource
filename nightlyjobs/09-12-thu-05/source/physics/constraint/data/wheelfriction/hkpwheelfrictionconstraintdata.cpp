// File Line: 15
// RVA: 0xD4DF30
void __fastcall hkpWheelFrictionConstraintData::init(hkpWheelFrictionConstraintData *this, hkpWheelFrictionConstraintAtom::Axle *axle, float radius)
{
  this->m_atoms.m_friction.m_radius = radius;
  this->m_atoms.m_friction.m_axle = axle;
  *(_WORD *)&this->m_atoms.m_friction.m_forwardAxis = 513;
  this->m_atoms.m_friction.m_maxFrictionForce = 3.40282e38;
  this->m_atoms.m_friction.m_isEnabled = 1;
}

// File Line: 29
// RVA: 0xD4DF60
hkBool *__fastcall hkpWheelFrictionConstraintData::isValid(hkpWheelFrictionConstraintData *this, hkBool *result)
{
  result->m_bool = this->m_atoms.m_friction.m_axle != 0i64;
  return result;
}

// File Line: 35
// RVA: 0xD4DF80
signed __int64 __fastcall hkpWheelFrictionConstraintData::getType(hkpWheelFrictionConstraintData *this)
{
  return 20i64;
}

// File Line: 45
// RVA: 0xD4DF90
void __fastcall hkpWheelFrictionConstraintData::getRuntimeInfo(hkpWheelFrictionConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 0;
  infoOut->m_sizeOfExternalRuntime = wantRuntime.m_bool != 0;
}

// File Line: 59
// RVA: 0xD4DFB0
void __fastcall hkpWheelFrictionConstraintData::getConstraintInfo(hkpWheelFrictionConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_transforms.m_type, 192, infoOut);
}

// File Line: 64
// RVA: 0xD4DFD0
void __fastcall hkpWheelFrictionConstraintData::setInWorldSpace(hkpWheelFrictionConstraintData *this, hkTransformf *bodyATransform, hkTransformf *bodyBTransform, hkVector4f *contact, hkVector4f *forward, hkVector4f *side)
{
  hkTransformf *v6; // r15
  hkpWheelFrictionConstraintData *v7; // rbp
  hkVector4f *v8; // r14
  hkTransformf *v9; // rbx
  __m128 v10; // xmm2
  hkVector4f b; // [rsp+20h] [rbp-28h]

  v6 = bodyBTransform;
  v7 = this;
  v8 = contact;
  v9 = bodyATransform;
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(side->m_quad, side->m_quad, 201), forward->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(forward->m_quad, forward->m_quad, 201), side->m_quad));
  b.m_quad = _mm_shuffle_ps(v10, v10, 201);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0,
    (hkMatrix3f *)&bodyATransform->m_rotation.m_col0,
    &b);
  hkVector4f::setRotatedInverseDir(
    &v7->m_atoms.m_transforms.m_transformA.m_rotation.m_col1,
    (hkMatrix3f *)&v9->m_rotation.m_col0,
    forward);
  hkVector4f::setRotatedInverseDir(
    &v7->m_atoms.m_transforms.m_transformA.m_rotation.m_col2,
    (hkMatrix3f *)&v9->m_rotation.m_col0,
    side);
  hkVector4f::setTransformedInversePos(&v7->m_atoms.m_transforms.m_transformA.m_translation, v9, v8);
  hkVector4f::setRotatedInverseDir(
    &v7->m_atoms.m_transforms.m_transformB.m_rotation.m_col0,
    (hkMatrix3f *)&v6->m_rotation.m_col0,
    &b);
  hkVector4f::setRotatedInverseDir(
    &v7->m_atoms.m_transforms.m_transformB.m_rotation.m_col1,
    (hkMatrix3f *)&v6->m_rotation.m_col0,
    forward);
  hkVector4f::setRotatedInverseDir(
    &v7->m_atoms.m_transforms.m_transformB.m_rotation.m_col2,
    (hkMatrix3f *)&v6->m_rotation.m_col0,
    side);
  hkVector4f::setTransformedInversePos(&v7->m_atoms.m_transforms.m_transformB.m_translation, v6, v8);
}

// File Line: 83
// RVA: 0xD4E0D0
void __fastcall hkpWheelFrictionConstraintData::setMaxFrictionForce(hkpWheelFrictionConstraintData *this, float maxFrictionForce)
{
  this->m_atoms.m_friction.m_maxFrictionForce = maxFrictionForce;
}

// File Line: 88
// RVA: 0xD4E0E0
void __fastcall hkpWheelFrictionConstraintData::setTorque(hkpWheelFrictionConstraintData *this, float torque)
{
  this->m_atoms.m_friction.m_torque = torque;
}

// File Line: 93
// RVA: 0xD4E150
float __fastcall hkpWheelFrictionConstraintData::getSpinVelocity(hkpWheelFrictionConstraintData *this)
{
  return this->m_atoms.m_friction.m_axle->m_spinVelocity;
}

// File Line: 98
// RVA: 0xD4E170
void __fastcall hkpWheelFrictionConstraintData::setSpinVelocity(hkpWheelFrictionConstraintData *this, float spinVelocity)
{
  this->m_atoms.m_friction.m_axle->m_spinVelocity = spinVelocity;
}

// File Line: 103
// RVA: 0xD4E0F0
void __fastcall hkpWheelFrictionConstraintData::setInvInertia(hkpWheelFrictionConstraintData *this, float invInertia)
{
  hkpWheelFrictionConstraintAtom::Axle *v2; // rax

  v2 = this->m_atoms.m_friction.m_axle;
  v2->m_invInertia = invInertia;
  if ( invInertia == 0.0 )
    v2->m_inertia = 0.0;
  else
    v2->m_inertia = 1.0 / invInertia;
}

// File Line: 108
// RVA: 0xD4E130
void __fastcall hkpWheelFrictionConstraintData::setImpulseScaling(hkpWheelFrictionConstraintData *this, float impulseScaling, float impulseMax)
{
  hkpWheelFrictionConstraintAtom::Axle *v3; // rax

  v3 = this->m_atoms.m_friction.m_axle;
  v3->m_impulseScaling = impulseScaling;
  v3->m_impulseMax = impulseMax;
}

// File Line: 113
// RVA: 0xD4E190
float __fastcall hkpWheelFrictionConstraintData::getForwardFrictionImpulse(hkpWheelFrictionConstraintData *this)
{
  return this->m_atoms.m_friction.m_frictionImpulse[0];
}

// File Line: 118
// RVA: 0xD4E1A0
float __fastcall hkpWheelFrictionConstraintData::getSideFrictionImpulse(hkpWheelFrictionConstraintData *this)
{
  return this->m_atoms.m_friction.m_frictionImpulse[1];
}

// File Line: 123
// RVA: 0xD4E1B0
float __fastcall hkpWheelFrictionConstraintData::getForwardSlipImpulse(hkpWheelFrictionConstraintData *this)
{
  return this->m_atoms.m_friction.m_slipImpulse[0];
}

// File Line: 128
// RVA: 0xD4E1C0
float __fastcall hkpWheelFrictionConstraintData::getSideSlipImpulse(hkpWheelFrictionConstraintData *this)
{
  return this->m_atoms.m_friction.m_slipImpulse[1];
}

// File Line: 133
// RVA: 0xD4E1D0
void __fastcall hkpWheelFrictionConstraintData::resetSolverData(hkpWheelFrictionConstraintData *this)
{
  *(_QWORD *)this->m_atoms.m_friction.m_frictionImpulse = 0i64;
  *(_QWORD *)this->m_atoms.m_friction.m_slipImpulse = 0i64;
}

