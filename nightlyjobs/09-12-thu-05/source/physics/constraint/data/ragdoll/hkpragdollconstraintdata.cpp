// File Line: 17
// RVA: 0xD47350
void __fastcall hkpRagdollConstraintData::hkpRagdollConstraintData(hkpRagdollConstraintData *this)
{
  hkpRagdollConstraintData::Atoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRagdollConstraintData::`vftable;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_ballSocket.m_type.m_storage = 0i64;
  hkpRagdollConstraintData::Atoms::Atoms(p_m_atoms);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  *(_WORD *)&this->m_atoms.m_angFriction.m_firstFrictionAxis = 768;
  this->m_atoms.m_angFriction.m_maxFrictionTorque = 0.0;
  this->m_atoms.m_ragdollMotors.m_isEnabled.m_bool = 0;
  *(_DWORD *)&this->m_atoms.m_ragdollMotors.m_initializedOffset = 9699472;
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_ragdollMotors.m_motors[0] = 0i64;
  this->m_atoms.m_ragdollMotors.m_motors[1] = 0i64;
  this->m_atoms.m_ragdollMotors.m_motors[2] = 0i64;
  *(_WORD *)&this->m_atoms.m_twistLimit.m_twistAxis = 256;
  this->m_atoms.m_twistLimit.m_minAngle = -0.52359998;
  this->m_atoms.m_twistLimit.m_maxAngle = 0.52359998;
  this->m_atoms.m_twistLimit.m_angularLimitsTauFactor = 0.80000001;
  *(_WORD *)&this->m_atoms.m_coneLimit.m_twistAxisInA = 0;
  this->m_atoms.m_coneLimit.m_angleMeasurementMode.m_storage = 0;
  this->m_atoms.m_coneLimit.m_minAngle = -100.0;
  this->m_atoms.m_coneLimit.m_maxAngle = 1.0;
  this->m_atoms.m_coneLimit.m_angularLimitsTauFactor = 0.80000001;
  hkpRagdollConstraintData::setConeLimitStabilization(this, (hkBool)1);
  *(_WORD *)&this->m_atoms.m_planesLimit.m_twistAxisInA = 256;
  this->m_atoms.m_planesLimit.m_angleMeasurementMode.m_storage = 1;
  this->m_atoms.m_planesLimit.m_minAngle = -0.025;
  this->m_atoms.m_planesLimit.m_maxAngle = 0.025;
  this->m_atoms.m_planesLimit.m_angularLimitsTauFactor = 0.80000001;
}

// File Line: 75
// RVA: 0xD47320
void __fastcall hkpRagdollConstraintData::Atoms::Atoms(
        hkpRagdollConstraintData::Atoms *this,
        hkFinishLoadedObjectFlag f)
{
  this->m_ragdollMotors.m_initializedOffset = -1;
  this->m_ragdollMotors.m_previousTargetAnglesOffset = -1;
  if ( f.m_finishing )
    *(_DWORD *)&this->m_ragdollMotors.m_initializedOffset = 9699472;
}

// File Line: 87
// RVA: 0xD47540
void __fastcall hkpRagdollConstraintData::setInWorldSpace(
        hkpRagdollConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *pivot,
        hkVector4f *twistAxisW,
        hkVector4f *planeAxisW)
{
  __int64 v10; // r8
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 m_quad; // xmm4
  __m128 *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  hkVector4f v21; // xmm2
  __m128 v22; // xmm4
  hkVector4f v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  signed __int64 v27; // rcx
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm8
  __m128 v31; // xmm4
  __m128 v32; // xmm0
  __int64 v33; // rdx
  __m128 v34; // xmm1
  hkVector4f v35; // xmm2
  __m128 *v36; // rax
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42[3]; // [rsp+20h] [rbp-68h] BYREF

  v10 = 3i64;
  v11 = _mm_mul_ps(twistAxisW->m_quad, twistAxisW->m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  m_quad = planeAxisW->m_quad;
  v15 = v42;
  v42[0] = _mm_mul_ps(
             twistAxisW->m_quad,
             _mm_andnot_ps(
               _mm_cmple_ps(v12, (__m128)0i64),
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                 _mm_mul_ps(*(__m128 *)_xmm, v13))));
  v16 = _mm_mul_ps(m_quad, m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_cmple_ps(v17, (__m128)0i64);
  v20 = _mm_mul_ps(v18, v17);
  v21.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v22 = _mm_mul_ps(
          m_quad,
          _mm_andnot_ps(
            v19,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v18)), _mm_mul_ps(*(__m128 *)_xmm, v18))));
  v23.m_quad = (__m128)bodyATransform->m_rotation.m_col0;
  v24 = _mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v42[1] = v22;
  v25 = _mm_unpacklo_ps(v23.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v26 = _mm_shuffle_ps(v24, v21.m_quad, 228);
  v27 = (char *)this - (char *)v42;
  v28 = _mm_movelh_ps(v25, v21.m_quad);
  v29 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v42[0]);
  v30 = _mm_mul_ps(_mm_shuffle_ps(v42[0], v42[0], 201), v22);
  v31 = _mm_shuffle_ps(_mm_movehl_ps(v28, v25), v21.m_quad, 212);
  v32 = _mm_sub_ps(v29, v30);
  v42[2] = _mm_shuffle_ps(v32, v32, 201);
  v33 = 3i64;
  do
  {
    v34 = *v15++;
    *(__m128 *)((char *)v15 + v27 + 32) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v31),
                                              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v28)),
                                            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v26));
    --v33;
  }
  while ( v33 );
  v35.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v36 = v42;
  v37 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v38 = _mm_shuffle_ps(
          _mm_unpackhi_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad),
          v35.m_quad,
          228);
  v39 = _mm_movelh_ps(v37, v35.m_quad);
  v40 = _mm_shuffle_ps(_mm_movehl_ps(v39, v37), v35.m_quad, 212);
  do
  {
    v41 = *v36++;
    *(__m128 *)((char *)v36 + v27 + 96) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v40),
                                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v39)),
                                            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v38));
    --v10;
  }
  while ( v10 );
  hkVector4f::setTransformedInversePos(&this->m_atoms.m_transforms.m_transformA.m_translation, bodyATransform, pivot);
  hkVector4f::setTransformedInversePos(&this->m_atoms.m_transforms.m_transformB.m_translation, bodyBTransform, pivot);
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col0 = this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0;
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col1 = this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1;
  this->m_atoms.m_ragdollMotors.m_target_bRca.m_col2 = this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2;
}

// File Line: 115
// RVA: 0xD477A0
void __fastcall hkpRagdollConstraintData::setInBodySpace(
        hkpRagdollConstraintData *this,
        hkVector4f *pivotA,
        hkVector4f *pivotB,
        hkVector4f *planeAxisA,
        hkVector4f *planeAxisB,
        hkVector4f *twistAxisA,
        hkVector4f *twistAxisB)
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
  hkVector4f v23; // xmm3
  __m128 v24; // xmm1

  v7 = _mm_mul_ps(twistAxisA->m_quad, twistAxisA->m_quad);
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
                                                                       twistAxisA->m_quad);
  v10 = _mm_mul_ps(planeAxisA->m_quad, planeAxisA->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0;
  v14.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v11, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                     _mm_mul_ps(*(__m128 *)_xmm, v12))),
                 planeAxisA->m_quad);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)v14.m_quad;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v13.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v14.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v15, v15, 201);
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  v16 = _mm_mul_ps(twistAxisB->m_quad, twistAxisB->m_quad);
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
                                                                       twistAxisB->m_quad);
  v19 = _mm_mul_ps(planeAxisB->m_quad, planeAxisB->m_quad);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0;
  v23.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v20, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                     _mm_mul_ps(*(__m128 *)_xmm, v21))),
                 planeAxisB->m_quad);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)v23.m_quad;
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 201), v22.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 201), v23.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v24, v24, 201);
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  this->m_atoms.m_ragdollMotors.m_target_bRca = (hkMatrix3f)this->m_atoms.m_transforms.m_transformB.m_rotation;
}

// File Line: 134
// RVA: 0xD47DA0
void __fastcall hkpRagdollConstraintData::setBreachImpulse(hkpRagdollConstraintData *this, float breachImpulse)
{
  this->m_atoms.m_ballSocket.m_breachImpulse = breachImpulse;
}

// File Line: 139
// RVA: 0xD47DB0
float __fastcall hkpRagdollConstraintData::getBreachImpulse(hkpRagdollConstraintData *this)
{
  return this->m_atoms.m_ballSocket.m_breachImpulse;
}

// File Line: 144
// RVA: 0xD47DC0
void __fastcall hkpRagdollConstraintData::setBodyToNotify(hkpRagdollConstraintData *this, char bodyIdx)
{
  this->m_atoms.m_ballSocket.m_bodiesToNotify = 1 << bodyIdx;
}

// File Line: 152
// RVA: 0xD47DE0
__int64 __fastcall hkpRagdollConstraintData::getNotifiedBodyIndex(hkpRagdollConstraintData *this)
{
  return (unsigned __int8)this->m_atoms.m_ballSocket.m_bodiesToNotify >> 1;
}

// File Line: 159
// RVA: 0xD47D80
void __fastcall hkpRagdollConstraintData::getConstraintInfo(
        hkpRagdollConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0x180u, infoOut);
}

// File Line: 164
// RVA: 0xD47E90
void __fastcall hkpRagdollConstraintData::getRuntimeInfo(
        hkpRagdollConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 18;
  infoOut->m_sizeOfExternalRuntime = 176;
}

// File Line: 173
// RVA: 0xD47AE0
void __fastcall hkpRagdollConstraintData::setMaxFrictionTorque(hkpRagdollConstraintData *this, float tmag)
{
  this->m_atoms.m_angFriction.m_maxFrictionTorque = tmag;
}

// File Line: 178
// RVA: 0xD47A00
void __fastcall hkpRagdollConstraintData::setConeLimitStabilization(hkpRagdollConstraintData *this, hkBool enable)
{
  this->m_atoms.m_coneLimit.m_memOffsetToAngleOffset = 56 * (enable.m_bool != 0);
}

// File Line: 185
// RVA: 0xD47A20
void __fastcall hkpRagdollConstraintData::setAsymmetricConeAngle(
        hkpRagdollConstraintData *this,
        float cone_min,
        float cone_max)
{
  __m128 v5; // xmm2
  hkQuaternionf quat; // [rsp+20h] [rbp-38h] BYREF

  hkQuaternionf::setAxisAngle(
    &quat,
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1,
    COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(cone_min + cone_max) * 0.5) ^ _xmm[0]));
  hkVector4f::setRotatedDir(
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0,
    &quat,
    &this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0);
  v5 = _mm_sub_ps(
         _mm_mul_ps(
           _mm_shuffle_ps(
             this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad,
             this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad,
             201),
           this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(
             this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad,
             this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad,
             201),
           this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v5, v5, 201);
  this->m_atoms.m_coneLimit.m_maxAngle = (float)(cone_max - cone_min) * 0.5;
}

// File Line: 201
// RVA: 0xD47CA0
hkBool *__fastcall hkpRagdollConstraintData::isValid(hkpRagdollConstraintData *this, hkBool *result)
{
  float m_maxAngle; // xmm1_4

  if ( this->m_atoms.m_ballSocket.m_solvingMethod.m_storage || this->m_atoms.m_setupStabilization.m_enabled.m_bool )
  {
    if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
      && hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
      && -100.0 == this->m_atoms.m_coneLimit.m_minAngle
      && (m_maxAngle = this->m_atoms.m_coneLimit.m_maxAngle, m_maxAngle >= 0.0)
      && m_maxAngle <= 3.1415927
      && this->m_atoms.m_planesLimit.m_maxAngle >= this->m_atoms.m_planesLimit.m_minAngle
      && this->m_atoms.m_twistLimit.m_maxAngle >= this->m_atoms.m_twistLimit.m_minAngle )
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

// File Line: 226
// RVA: 0xD479B0
void __fastcall hkpRagdollConstraintData::getConstraintFrameA(
        hkpRagdollConstraintData *this,
        hkRotationf *constraintFrameA)
{
  *constraintFrameA = this->m_atoms.m_transforms.m_transformA.m_rotation;
}

// File Line: 232
// RVA: 0xD479D0
void __fastcall hkpRagdollConstraintData::getConstraintFrameB(
        hkpRagdollConstraintData *this,
        hkRotationf *constraintFrameB)
{
  *constraintFrameB = this->m_atoms.m_transforms.m_transformB.m_rotation;
}

// File Line: 246
// RVA: 0xD474E0
void __fastcall hkpRagdollConstraintData::~hkpRagdollConstraintData(hkpRagdollConstraintData *this)
{
  hkReferencedObject **m_motors; // rbx
  __int64 v3; // rdi

  m_motors = this->m_atoms.m_ragdollMotors.m_motors;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRagdollConstraintData::`vftable;
  v3 = 3i64;
  do
  {
    if ( *m_motors )
      hkReferencedObject::removeReference(*m_motors);
    ++m_motors;
    --v3;
  }
  while ( v3 );
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 257
// RVA: 0xD47C30
void __fastcall hkpRagdollConstraintData::setTarget(hkpRagdollConstraintData *this, hkMatrix3f *target_cbRca)
{
  hkMatrix3f::setMul(
    &this->m_atoms.m_ragdollMotors.m_target_bRca,
    &this->m_atoms.m_transforms.m_transformB.m_rotation,
    target_cbRca);
}

// File Line: 272
// RVA: 0xD47C50
void __fastcall hkpRagdollConstraintData::setTargetRelativeOrientationOfBodies(
        hkpRagdollConstraintData *this,
        hkRotationf *target_bRa)
{
  hkMatrix3f::setMul(
    &this->m_atoms.m_ragdollMotors.m_target_bRca,
    target_bRa,
    &this->m_atoms.m_transforms.m_transformA.m_rotation);
}

// File Line: 283
// RVA: 0xD47C70
void __fastcall hkpRagdollConstraintData::getTarget(hkpRagdollConstraintData *this, hkMatrix3f *target_cbRca)
{
  hkMatrix3f::setMulInverseMul(
    target_cbRca,
    &this->m_atoms.m_transforms.m_transformB.m_rotation,
    &this->m_atoms.m_ragdollMotors.m_target_bRca);
}

// File Line: 289
// RVA: 0xD47B60
hkpConstraintMotor *__fastcall hkpRagdollConstraintData::getTwistMotor(hkpRagdollConstraintData *this)
{
  return this->m_atoms.m_ragdollMotors.m_motors[0];
}

// File Line: 294
// RVA: 0xD47AF0
void __fastcall hkpRagdollConstraintData::setMotor(
        hkpRagdollConstraintData *this,
        hkpRagdollConstraintData::MotorIndex index,
        hkpConstraintMotor *newMotor)
{
  __int64 v4; // rdi
  hkBaseObjectVtbl **v6; // rdi
  hkReferencedObject *v7; // rcx

  v4 = index;
  if ( newMotor )
    hkReferencedObject::addReference(newMotor);
  v6 = &this->vfptr + v4;
  v7 = (hkReferencedObject *)v6[32];
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v6[32] = (hkBaseObjectVtbl *)newMotor;
}

// File Line: 310
// RVA: 0xD47B50
void __fastcall hkpRagdollConstraintData::setTwistMotor(hkpRagdollConstraintData *this, hkpConstraintMotor *motor)
{
  hkpRagdollConstraintData::setMotor(this, MOTOR_TWIST, motor);
}

// File Line: 316
// RVA: 0xD47BC0
hkpConstraintMotor *__fastcall hkpRagdollConstraintData::getConeMotor(hkpRagdollConstraintData *this)
{
  return this->m_atoms.m_ragdollMotors.m_motors[2];
}

// File Line: 322
// RVA: 0xD47BA0
void __fastcall hkpRagdollConstraintData::setConeMotor(hkpRagdollConstraintData *this, hkpConstraintMotor *motor)
{
  hkpRagdollConstraintData::setMotor(this, MOTOR_CONE, motor);
}

// File Line: 328
// RVA: 0xD47B90
hkpConstraintMotor *__fastcall hkpRagdollConstraintData::getPlaneMotor(hkpRagdollConstraintData *this)
{
  return this->m_atoms.m_ragdollMotors.m_motors[1];
}

// File Line: 333
// RVA: 0xD47B70
void __fastcall hkpRagdollConstraintData::setPlaneMotor(hkpRagdollConstraintData *this, hkpConstraintMotor *motor)
{
  hkpRagdollConstraintData::setMotor(this, MOTOR_PLANE, motor);
}

// File Line: 338
// RVA: 0xD47BD0
void __fastcall hkpRagdollConstraintData::setMotorsEnabled(
        hkpRagdollConstraintData *this,
        struct hkpConstraintRuntime *runtimeIn,
        hkBool areEnabled)
{
  this->m_atoms.m_ragdollMotors.m_isEnabled = areEnabled;
  this->m_atoms.m_angFriction.m_isEnabled = areEnabled.m_bool == 0;
  if ( runtimeIn )
  {
    *((_QWORD *)runtimeIn + 6) = 0i64;
    *((_QWORD *)runtimeIn + 7) = 0i64;
    *((_QWORD *)runtimeIn + 8) = 0i64;
    *((_QWORD *)runtimeIn + 9) = 0i64;
    *((_QWORD *)runtimeIn + 10) = 0i64;
    *((_QWORD *)runtimeIn + 11) = 0i64;
    *(_QWORD *)runtimeIn = 0i64;
    *((_QWORD *)runtimeIn + 1) = 0i64;
    *((_QWORD *)runtimeIn + 2) = 0i64;
    *((_QWORD *)runtimeIn + 3) = 0i64;
    *((_QWORD *)runtimeIn + 4) = 0i64;
    *((_QWORD *)runtimeIn + 5) = 0i64;
  }
}

// File Line: 362
// RVA: 0xD47C90
__int64 __fastcall hkpRagdollConstraintData::getType(hkpRagdollConstraintData *this)
{
  return 7i64;
}

// File Line: 370
// RVA: 0xD47DF0
void __fastcall hkpRagdollConstraintData::setSolvingMethod(
        hkpRagdollConstraintData *this,
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

// File Line: 399
// RVA: 0xD47E20
hkResult *__fastcall hkpRagdollConstraintData::getInertiaStabilizationFactor(
        hkpRagdollConstraintData *this,
        hkResult *result,
        float *inertiaStabilizationFactorOut)
{
  float m_inertiaStabilizationFactor; // eax

  m_inertiaStabilizationFactor = this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor;
  result->m_enum = HK_SUCCESS;
  *inertiaStabilizationFactorOut = m_inertiaStabilizationFactor;
  return result;
}

// File Line: 408
// RVA: 0xD47E40
hkResult *__fastcall hkpRagdollConstraintData::setInertiaStabilizationFactor(
        hkpRagdollConstraintData *this,
        hkResult *result,
        float inertiaStabilizationFactorIn)
{
  hkResult *v3; // rax

  result->m_enum = HK_SUCCESS;
  v3 = result;
  this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor = fminf(fmaxf(inertiaStabilizationFactorIn, 0.0), 1.0);
  return v3;
}

