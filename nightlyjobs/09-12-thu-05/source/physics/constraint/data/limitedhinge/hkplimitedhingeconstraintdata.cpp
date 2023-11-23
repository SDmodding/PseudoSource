// File Line: 17
// RVA: 0xD454D0
void __fastcall hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(hkpLimitedHingeConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpLimitedHingeConstraintData::`vftable;
  this->m_userData = 0i64;
  hkpLimitedHingeConstraintData::Atoms::Atoms(&this->m_atoms);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_angMotor.m_correspondingAngLimitSolverResultOffset = 32;
  this->m_atoms.m_2dAng.m_freeRotationAxis = 0;
  this->m_atoms.m_angLimit.m_limitAxis = 0;
  this->m_atoms.m_angLimit.m_minAngle = -3.1415927;
  this->m_atoms.m_angLimit.m_maxAngle = 3.1415927;
  this->m_atoms.m_angLimit.m_angularLimitsTauFactor = 1.0;
  *(_WORD *)&this->m_atoms.m_angFriction.m_firstFrictionAxis = 256;
  this->m_atoms.m_angFriction.m_maxFrictionTorque = 0.0;
  *(_DWORD *)&this->m_atoms.m_angMotor.m_initializedOffset = 5505104;
  *(_WORD *)&this->m_atoms.m_angMotor.m_isEnabled.m_bool = 0;
  this->m_atoms.m_angMotor.m_targetAngle = 0.0;
  this->m_atoms.m_angMotor.m_motor = 0i64;
}

// File Line: 59
// RVA: 0xD45490
void __fastcall hkpLimitedHingeConstraintData::Atoms::Atoms(
        hkpLimitedHingeConstraintData::Atoms *this,
        hkFinishLoadedObjectFlag f)
{
  this->m_angMotor.m_initializedOffset = -1;
  this->m_angMotor.m_previousTargetAngleOffset = -1;
  this->m_angMotor.m_correspondingAngLimitSolverResultOffset = -1;
  if ( f.m_finishing )
  {
    *(_DWORD *)&this->m_angMotor.m_initializedOffset = 5505104;
    this->m_angMotor.m_correspondingAngLimitSolverResultOffset = 32;
  }
}

// File Line: 70
// RVA: 0xD455D0
void __fastcall hkpLimitedHingeConstraintData::~hkpLimitedHingeConstraintData(hkpLimitedHingeConstraintData *this)
{
  hkpConstraintMotor *m_motor; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpLimitedHingeConstraintData::`vftable;
  m_motor = this->m_atoms.m_angMotor.m_motor;
  if ( m_motor )
    hkReferencedObject::removeReference(m_motor);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 82
// RVA: 0xD457F0
void __fastcall hkpLimitedHingeConstraintData::setInWorldSpace(
        hkpLimitedHingeConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *pivot,
        hkVector4f *axisIn)
{
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm5
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  hkVector4f b; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f v24; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f v25; // [rsp+40h] [rbp-68h] BYREF

  v9 = _mm_mul_ps(axisIn->m_quad, axisIn->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  b.m_quad = _mm_mul_ps(
               axisIn->m_quad,
               _mm_andnot_ps(
                 _mm_cmple_ps(v10, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                   _mm_mul_ps(*(__m128 *)_xmm, v11))));
  v12 = _mm_shuffle_ps(b.m_quad, _mm_unpackhi_ps(b.m_quad, (__m128)0i64), 196);
  v13 = _mm_shuffle_ps(v12, v12, 241);
  v14 = _mm_shuffle_ps(v12, v12, 206);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(v13, v13);
  v17 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170)));
  v18 = _mm_xor_ps(
          _mm_or_ps(_mm_and_ps(v14, v17), _mm_andnot_ps(v17, v13)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v24.m_quad = _mm_mul_ps(
                 v18,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v20, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                     _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v24.m_quad, v24.m_quad, 201), b.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 201), v24.m_quad));
  v25.m_quad = _mm_shuffle_ps(v22, v22, 201);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0,
    &bodyATransform->m_rotation,
    &b);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1,
    &bodyATransform->m_rotation,
    &v24);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2,
    &bodyATransform->m_rotation,
    &v25);
  hkVector4f::setTransformedInversePos(&this->m_atoms.m_transforms.m_transformA.m_translation, bodyATransform, pivot);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0,
    &bodyBTransform->m_rotation,
    &b);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1,
    &bodyBTransform->m_rotation,
    &v24);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2,
    &bodyBTransform->m_rotation,
    &v25);
  hkVector4f::setTransformedInversePos(&this->m_atoms.m_transforms.m_transformB.m_translation, bodyBTransform, pivot);
}

// File Line: 109
// RVA: 0xD45610
void __fastcall hkpLimitedHingeConstraintData::setInBodySpace(
        hkpLimitedHingeConstraintData *this,
        hkVector4f *pivotA,
        hkVector4f *pivotB,
        hkVector4f *axisA,
        hkVector4f *axisB,
        hkVector4f *axisAPerp,
        hkVector4f *axisBPerp)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm4
  __m128 v24; // xmm4

  v7 = _mm_mul_ps(axisA->m_quad, axisA->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v8, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v9))),
                                                                       axisA->m_quad);
  v10 = _mm_mul_ps(axisAPerp->m_quad, axisAPerp->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0;
  v14.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v11, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                     _mm_mul_ps(*(__m128 *)_xmm, v12))),
                 axisAPerp->m_quad);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)v14.m_quad;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v13.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v14.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v15, v15, 201);
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  v16 = _mm_mul_ps(axisB->m_quad, axisB->m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v17, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v18))),
                                                                       axisB->m_quad);
  v19 = _mm_mul_ps(axisBPerp->m_quad, axisBPerp->m_quad);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0;
  v23.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v20, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                     _mm_mul_ps(*(__m128 *)_xmm, v21))),
                 axisBPerp->m_quad);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)v23.m_quad;
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 201), v22.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 201), v23.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v24, v24, 201);
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
}

// File Line: 130
// RVA: 0xD45BA0
void __fastcall hkpLimitedHingeConstraintData::setBreachImpulse(
        hkpLimitedHingeConstraintData *this,
        float breachImpulse)
{
  this->m_atoms.m_ballSocket.m_breachImpulse = breachImpulse;
}

// File Line: 135
// RVA: 0xD45BB0
float __fastcall hkpLimitedHingeConstraintData::getBreachImpulse(hkpLimitedHingeConstraintData *this)
{
  return this->m_atoms.m_ballSocket.m_breachImpulse;
}

// File Line: 140
// RVA: 0xD45BC0
void __fastcall hkpLimitedHingeConstraintData::setBodyToNotify(hkpLimitedHingeConstraintData *this, char bodyIdx)
{
  this->m_atoms.m_ballSocket.m_bodiesToNotify = 1 << bodyIdx;
}

// File Line: 148
// RVA: 0xD45BE0
__int64 __fastcall hkpLimitedHingeConstraintData::getNotifiedBodyIndex(hkpLimitedHingeConstraintData *this)
{
  return (unsigned __int8)this->m_atoms.m_ballSocket.m_bodiesToNotify >> 1;
}

// File Line: 155
// RVA: 0xD45A90
void __fastcall hkpLimitedHingeConstraintData::setMotorEnabled(
        hkpLimitedHingeConstraintData *this,
        struct hkpConstraintRuntime *runtimeIn,
        hkBool isEnabled)
{
  this->m_atoms.m_angMotor.m_isEnabled = isEnabled;
  this->m_atoms.m_angFriction.m_isEnabled = isEnabled.m_bool == 0;
  if ( runtimeIn )
  {
    *(_QWORD *)runtimeIn = 0i64;
    *((_QWORD *)runtimeIn + 1) = 0i64;
    *((_QWORD *)runtimeIn + 2) = 0i64;
    *((_QWORD *)runtimeIn + 3) = 0i64;
  }
}

// File Line: 170
// RVA: 0xD45A40
void __fastcall hkpLimitedHingeConstraintData::setMotor(hkpLimitedHingeConstraintData *this, hkpConstraintMotor *motor)
{
  hkpConstraintMotor *m_motor; // rcx

  if ( motor )
    hkReferencedObject::addReference(motor);
  m_motor = this->m_atoms.m_angMotor.m_motor;
  if ( m_motor )
    hkReferencedObject::removeReference(m_motor);
  this->m_atoms.m_angMotor.m_motor = motor;
}

// File Line: 184
// RVA: 0xD45B80
void __fastcall hkpLimitedHingeConstraintData::getConstraintInfo(
        hkpLimitedHingeConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0x108u, infoOut);
}

// File Line: 189
// RVA: 0xD45C90
void __fastcall hkpLimitedHingeConstraintData::getRuntimeInfo(
        hkpLimitedHingeConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 10;
  infoOut->m_sizeOfExternalRuntime = 96;
}

// File Line: 197
// RVA: 0xD45AE0
hkBool *__fastcall hkpLimitedHingeConstraintData::isValid(hkpLimitedHingeConstraintData *this, hkBool *result)
{
  if ( this->m_atoms.m_ballSocket.m_solvingMethod.m_storage || this->m_atoms.m_setupStabilization.m_enabled.m_bool )
  {
    if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
      && hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
      && (!this->m_atoms.m_angMotor.m_isEnabled.m_bool || this->m_atoms.m_angLimit.m_isEnabled) )
    {
      result->m_bool = 1;
      return result;
    }
    else
    {
      result->m_bool = 0;
      return result;
    }
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 214
// RVA: 0xD45AD0
__int64 __fastcall hkpLimitedHingeConstraintData::getType(hkpLimitedHingeConstraintData *this)
{
  return 2i64;
}

// File Line: 222
// RVA: 0xD45BF0
void __fastcall hkpLimitedHingeConstraintData::setSolvingMethod(
        hkpLimitedHingeConstraintData *this,
        hkpConstraintAtom::SolvingMethod method)
{
  if ( method )
  {
    if ( method == METHOD_OLD )
    {
      this->m_atoms.m_setupStabilization.m_enabled.m_bool = 0;
      this->m_atoms.m_ballSocket.m_solvingMethod.m_storage = 1;
    }
  }
  else
  {
    this->m_atoms.m_setupStabilization.m_enabled.m_bool = 1;
    this->m_atoms.m_ballSocket.m_solvingMethod.m_storage = 0;
  }
}

// File Line: 251
// RVA: 0xD45C20
hkResult *__fastcall hkpLimitedHingeConstraintData::getInertiaStabilizationFactor(
        hkpLimitedHingeConstraintData *this,
        hkResult *result,
        float *inertiaStabilizationFactorOut)
{
  float m_inertiaStabilizationFactor; // eax

  m_inertiaStabilizationFactor = this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor;
  result->m_enum = HK_SUCCESS;
  *inertiaStabilizationFactorOut = m_inertiaStabilizationFactor;
  return result;
}

// File Line: 260
// RVA: 0xD45C40
hkResult *__fastcall hkpLimitedHingeConstraintData::setInertiaStabilizationFactor(
        hkpLimitedHingeConstraintData *this,
        hkResult *result,
        float inertiaStabilizationFactorIn)
{
  hkResult *v3; // rax

  result->m_enum = HK_SUCCESS;
  v3 = result;
  this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor = fminf(fmaxf(inertiaStabilizationFactorIn, 0.0), 1.0);
  return v3;
}

