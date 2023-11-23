// File Line: 15
// RVA: 0xD4BD30
void __fastcall hkpLinearClearanceConstraintData::hkpLinearClearanceConstraintData(
        hkpLinearClearanceConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpLinearClearanceConstraintData::`vftable;
  this->m_userData = 0i64;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_motor.m_type.m_storage = 11;
  this->m_atoms.m_motor.m_isEnabled.m_bool = 1;
  this->m_atoms.m_motor.m_initializedOffset = -1;
  this->m_atoms.m_motor.m_previousTargetPositionOffset = -1;
  this->m_atoms.m_friction0.m_type.m_storage = 10;
  this->m_atoms.m_friction0.m_isEnabled = 1;
  this->m_atoms.m_friction1.m_type.m_storage = 10;
  this->m_atoms.m_friction1.m_isEnabled = 1;
  this->m_atoms.m_friction2.m_type.m_storage = 10;
  this->m_atoms.m_friction2.m_isEnabled = 1;
  this->m_atoms.m_ang.m_type.m_storage = 13;
  this->m_atoms.m_linLimit0.m_type.m_storage = 9;
  this->m_atoms.m_linLimit1.m_type.m_storage = 9;
  this->m_atoms.m_linLimit2.m_type.m_storage = 9;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  *(_QWORD *)&this->m_atoms.m_linLimit0.m_min = 0i64;
  this->m_atoms.m_linLimit0.m_axisIndex = 0;
  *(_QWORD *)&this->m_atoms.m_linLimit1.m_min = 0i64;
  this->m_atoms.m_linLimit1.m_axisIndex = 1;
  *(_QWORD *)&this->m_atoms.m_linLimit2.m_min = 0i64;
  this->m_atoms.m_linLimit2.m_axisIndex = 2;
  this->m_atoms.m_friction0.m_maxFrictionForce = 0.0;
  this->m_atoms.m_friction0.m_frictionAxis = 0;
  this->m_atoms.m_friction1.m_maxFrictionForce = 0.0;
  this->m_atoms.m_friction1.m_frictionAxis = 1;
  this->m_atoms.m_friction2.m_maxFrictionForce = 0.0;
  this->m_atoms.m_friction2.m_frictionAxis = 2;
  *(_DWORD *)&this->m_atoms.m_motor.m_isEnabled.m_bool = 7340032;
  this->m_atoms.m_motor.m_previousTargetPositionOffset = 116;
  this->m_atoms.m_motor.m_targetPosition = 0.0;
  this->m_atoms.m_motor.m_motor = 0i64;
  *(_WORD *)&this->m_atoms.m_ang.m_firstConstrainedAxis = 768;
}

// File Line: 67
// RVA: 0xD4BD00
void __fastcall hkpLinearClearanceConstraintData::Atoms::Atoms(
        hkpLinearClearanceConstraintData::Atoms *this,
        hkFinishLoadedObjectFlag f)
{
  this->m_motor.m_initializedOffset = -1;
  this->m_motor.m_previousTargetPositionOffset = -1;
  if ( f.m_finishing )
    *(_DWORD *)&this->m_motor.m_initializedOffset = 7602288;
}

// File Line: 77
// RVA: 0xD4BEB0
void __fastcall hkpLinearClearanceConstraintData::~hkpLinearClearanceConstraintData(
        hkpLinearClearanceConstraintData *this)
{
  hkpConstraintMotor *m_motor; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpLinearClearanceConstraintData::`vftable;
  m_motor = this->m_atoms.m_motor.m_motor;
  if ( m_motor )
    hkReferencedObject::removeReference(m_motor);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 87
// RVA: 0xD4BEF0
void __fastcall hkpLinearClearanceConstraintData::setInWorldSpace(
        hkpLinearClearanceConstraintData *this,
        hkpLinearClearanceConstraintData::Type type,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *pivot,
        hkVector4f *axis1,
        hkVector4f *axis2)
{
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  hkVector4f axis2B; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f axis2A; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f axis1B; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f axis1A; // [rsp+70h] [rbp-68h] BYREF
  hkVector4f pivotB; // [rsp+80h] [rbp-58h] BYREF
  hkVector4f pivotA; // [rsp+90h] [rbp-48h] BYREF

  hkVector4f::setRotatedInverseDir(&axis1A, &bodyATransform->m_rotation, axis1);
  v11 = _mm_mul_ps(axis1A.m_quad, axis1A.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  axis1A.m_quad = _mm_mul_ps(
                    axis1A.m_quad,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v12, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                        _mm_mul_ps(*(__m128 *)_xmm, v13))));
  hkVector4f::setRotatedInverseDir(&axis2A, &bodyATransform->m_rotation, axis2);
  v14 = _mm_mul_ps(axis2A.m_quad, axis2A.m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  axis2A.m_quad = _mm_mul_ps(
                    axis2A.m_quad,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v15, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                        _mm_mul_ps(*(__m128 *)_xmm, v16))));
  hkVector4f::setTransformedInversePos(&pivotA, bodyATransform, pivot);
  hkVector4f::setRotatedInverseDir(&axis1B, &bodyBTransform->m_rotation, axis1);
  v17 = _mm_mul_ps(axis1B.m_quad, axis1B.m_quad);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  axis1B.m_quad = _mm_mul_ps(
                    axis1B.m_quad,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v18, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                        _mm_mul_ps(*(__m128 *)_xmm, v19))));
  hkVector4f::setRotatedInverseDir(&axis2B, &bodyBTransform->m_rotation, axis2);
  v20 = _mm_mul_ps(axis2B.m_quad, axis2B.m_quad);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rsqrt_ps(v21);
  axis2B.m_quad = _mm_mul_ps(
                    axis2B.m_quad,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v21, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                        _mm_mul_ps(*(__m128 *)_xmm, v22))));
  hkVector4f::setTransformedInversePos(&pivotB, bodyBTransform, pivot);
  hkpLinearClearanceConstraintData::setInBodySpace(this, type, &pivotA, &pivotB, &axis1A, &axis1B, &axis2A, &axis2B);
}

// File Line: 101
// RVA: 0xD4C170
void __fastcall hkpLinearClearanceConstraintData::setInBodySpace(
        hkpLinearClearanceConstraintData *this,
        int type,
        hkVector4f *pivotA,
        hkVector4f *pivotB,
        hkVector4f *axis1A,
        hkVector4f *axis1B,
        hkVector4f *axis2A,
        hkVector4f *axis2B)
{
  hkVector4f *v8; // rax
  __m128 m_quad; // xmm5
  hkVector4f *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  hkVector4f *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  hkVector4f *v25; // rax
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm3
  __m128 v32; // xmm1
  __int16 v33; // [rsp+48h] [rbp+10h]
  char v34; // [rsp+4Ah] [rbp+12h]

  v8 = axis1A;
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  m_quad = v8->m_quad;
  v10 = axis2A;
  v11 = _mm_mul_ps(m_quad, m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v12, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v13))),
                                                                       m_quad);
  v14 = v10->m_quad;
  v15 = axis1B;
  v16 = _mm_mul_ps(v14, v14);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0;
  v20.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v17, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                     _mm_mul_ps(*(__m128 *)_xmm, v18))),
                 v14);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)v20.m_quad;
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 201), v19.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 201), v20.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v21, v21, 201);
  v22 = v15->m_quad;
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = axis2B;
  v26 = _mm_rsqrt_ps(v24);
  v33 = 515;
  v34 = 0;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v24, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v26, v24), v26)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v26))),
                                                                       v22);
  v27 = _mm_mul_ps(v25->m_quad, v25->m_quad);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0;
  v31.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v28, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                     _mm_mul_ps(*(__m128 *)_xmm, v29))),
                 v25->m_quad);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)v31.m_quad;
  v32 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v31.m_quad, 201), v30.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v30.m_quad, v30.m_quad, 201), v31.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v32, v32, 201);
  this->m_atoms.m_ang.m_numConstrainedAxes = *((_BYTE *)&v33 + type);
}

// File Line: 122
// RVA: 0xD4C370
void __fastcall hkpLinearClearanceConstraintData::setMotor(
        hkpLinearClearanceConstraintData *this,
        hkpConstraintMotor *motor)
{
  hkpConstraintMotor *m_motor; // rcx

  if ( motor )
    hkReferencedObject::addReference(motor);
  m_motor = this->m_atoms.m_motor.m_motor;
  if ( m_motor )
    hkReferencedObject::removeReference(m_motor);
  this->m_atoms.m_motor.m_motor = motor;
}

// File Line: 137
// RVA: 0xD4C4B0
void __fastcall hkpLinearClearanceConstraintData::getConstraintInfo(
        hkpLinearClearanceConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0x118u, infoOut);
}

// File Line: 142
// RVA: 0xD4C4D0
void __fastcall hkpLinearClearanceConstraintData::getRuntimeInfo(
        hkpLinearClearanceConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 14;
  infoOut->m_sizeOfExternalRuntime = 120;
}

// File Line: 150
// RVA: 0xD4C410
hkBool *__fastcall hkpLinearClearanceConstraintData::isValid(hkpLinearClearanceConstraintData *this, hkBool *result)
{
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
    && hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
    && this->m_atoms.m_linLimit0.m_max >= this->m_atoms.m_linLimit0.m_min
    && this->m_atoms.m_linLimit1.m_max >= this->m_atoms.m_linLimit1.m_min
    && this->m_atoms.m_linLimit2.m_max >= this->m_atoms.m_linLimit2.m_min
    && this->m_atoms.m_ang.m_numConstrainedAxes <= 3u )
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

// File Line: 159
// RVA: 0xD4C400
__int64 __fastcall hkpLinearClearanceConstraintData::getType(hkpLinearClearanceConstraintData *this)
{
  return 25i64;
}

// File Line: 164
// RVA: 0xD4C3C0
void __fastcall hkpLinearClearanceConstraintData::setMotorEnabled(
        hkpLinearClearanceConstraintData *this,
        struct hkpConstraintRuntime *runtimeIn,
        hkBool isEnabled)
{
  this->m_atoms.m_motor.m_isEnabled = isEnabled;
  this->m_atoms.m_friction0.m_isEnabled = isEnabled.m_bool == 0;
  if ( runtimeIn )
  {
    *(_QWORD *)runtimeIn = 0i64;
    *((_QWORD *)runtimeIn + 1) = 0i64;
    *((_QWORD *)runtimeIn + 2) = 0i64;
    *((_QWORD *)runtimeIn + 3) = 0i64;
  }
}

