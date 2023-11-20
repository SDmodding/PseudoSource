// File Line: 17
// RVA: 0xD49300
void __fastcall hkpPrismaticConstraintData::hkpPrismaticConstraintData(hkpPrismaticConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPrismaticConstraintData::`vftable;
  this->m_userData = 0i64;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_motor.m_type.m_storage = 11;
  this->m_atoms.m_motor.m_isEnabled.m_bool = 1;
  this->m_atoms.m_motor.m_initializedOffset = -1;
  this->m_atoms.m_motor.m_previousTargetPositionOffset = -1;
  this->m_atoms.m_friction.m_type.m_storage = 10;
  this->m_atoms.m_friction.m_isEnabled = 1;
  this->m_atoms.m_ang.m_type.m_storage = 13;
  this->m_atoms.m_lin0.m_type.m_storage = 7;
  this->m_atoms.m_lin1.m_type.m_storage = 7;
  this->m_atoms.m_linLimit.m_type.m_storage = 9;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_linLimit.m_min = -3.40282e38;
  this->m_atoms.m_linLimit.m_max = 3.40282e38;
  this->m_atoms.m_linLimit.m_axisIndex = 0;
  this->m_atoms.m_friction.m_maxFrictionForce = 0.0;
  this->m_atoms.m_friction.m_frictionAxis = 0;
  *(_DWORD *)&this->m_atoms.m_motor.m_isEnabled.m_bool = 5242880;
  this->m_atoms.m_motor.m_previousTargetPositionOffset = 84;
  this->m_atoms.m_motor.m_targetPosition = 0.0;
  this->m_atoms.m_motor.m_motor = 0i64;
  *(_WORD *)&this->m_atoms.m_ang.m_firstConstrainedAxis = 768;
  this->m_atoms.m_lin0.m_axisIndex = 1;
  this->m_atoms.m_lin1.m_axisIndex = 2;
}

// File Line: 56
// RVA: 0xD492D0
void __fastcall hkpPrismaticConstraintData::Atoms::Atoms(hkpPrismaticConstraintData::Atoms *this, hkFinishLoadedObjectFlag f)
{
  this->m_motor.m_initializedOffset = -1;
  this->m_motor.m_previousTargetPositionOffset = -1;
  if ( f.m_finishing )
    *(_DWORD *)&this->m_motor.m_initializedOffset = 5505104;
}

// File Line: 66
// RVA: 0xD49450
void __fastcall hkpPrismaticConstraintData::~hkpPrismaticConstraintData(hkpPrismaticConstraintData *this)
{
  hkpPrismaticConstraintData *v1; // rbx
  hkpConstraintMotor *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPrismaticConstraintData::`vftable;
  v2 = this->m_atoms.m_motor.m_motor;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 76
// RVA: 0xD49490
void __fastcall hkpPrismaticConstraintData::setInWorldSpace(hkpPrismaticConstraintData *this, hkTransformf *bodyATransform, hkTransformf *bodyBTransform, hkVector4f *pivot, hkVector4f *axis)
{
  hkVector4f *v5; // rsi
  hkTransformf *v6; // rbx
  hkTransformf *v7; // r9
  hkpPrismaticConstraintData *v8; // rdi
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  signed __int64 v23; // r8
  __m128 *v24; // rax
  __m128 v25; // xmm0
  hkVector4f v26; // xmm2
  __m128 v27; // xmm4
  hkVector4f v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  signed __int64 v32; // rcx
  signed __int64 v33; // rdx
  __m128 v34; // xmm5
  __m128 v35; // xmm0
  __m128 v36; // xmm10
  __m128 v37; // xmm4
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 *v41; // rax
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 v46; // xmm1
  __m128 v47; // [rsp+20h] [rbp-88h]
  __m128 v48; // [rsp+30h] [rbp-78h]
  __m128 v49; // [rsp+40h] [rbp-68h]

  v5 = pivot;
  v6 = bodyBTransform;
  v7 = bodyATransform;
  v8 = this;
  v9 = _mm_mul_ps(axis->m_quad, axis->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v47 = _mm_mul_ps(
          axis->m_quad,
          _mm_andnot_ps(
            _mm_cmpleps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))));
  v12 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, (__m128)0i64), 196);
  v13 = _mm_shuffle_ps(v12, v12, 241);
  v14 = _mm_shuffle_ps(v12, v12, 206);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(v13, v13);
  v17 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170)));
  v18 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v17, v13), _mm_and_ps(v14, v17)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_cmpleps(v20, (__m128)0i64);
  v23 = 3i64;
  v24 = &v47;
  v25 = _mm_mul_ps(v21, v20);
  v26.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v27 = _mm_mul_ps(
          v18,
          _mm_andnot_ps(
            v22,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v21)), _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v28.m_quad = (__m128)bodyATransform->m_rotation.m_col0;
  v29 = _mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v48 = v27;
  v30 = _mm_unpacklo_ps(v28.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v31 = _mm_shuffle_ps(v29, v26.m_quad, 228);
  v32 = (char *)this - (char *)&v47;
  v33 = 3i64;
  v34 = _mm_movelh_ps(v30, v26.m_quad);
  v35 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v47);
  v36 = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v27);
  v37 = _mm_shuffle_ps(_mm_movehl_ps(v34, v30), v26.m_quad, 212);
  v38 = _mm_sub_ps(v35, v36);
  v49 = _mm_shuffle_ps(v38, v38, 201);
  do
  {
    v39 = *v24;
    ++v24;
    *(__m128 *)((char *)v24 + v32 + 32) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), v37),
                                              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v34)),
                                            _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), v31));
    --v33;
  }
  while ( v33 );
  v40 = v6->m_rotation.m_col2.m_quad;
  v41 = &v47;
  v42 = _mm_unpacklo_ps(v6->m_rotation.m_col0.m_quad, v6->m_rotation.m_col1.m_quad);
  v43 = _mm_shuffle_ps(_mm_unpackhi_ps(v6->m_rotation.m_col0.m_quad, v6->m_rotation.m_col1.m_quad), v40, 228);
  v44 = _mm_movelh_ps(v42, v40);
  v45 = _mm_shuffle_ps(_mm_movehl_ps(v44, v42), v40, 212);
  do
  {
    v46 = *v41;
    ++v41;
    *(__m128 *)((char *)v41 + v32 + 96) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v45),
                                              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v44)),
                                            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v43));
    --v23;
  }
  while ( v23 );
  hkVector4f::setTransformedInversePos(&v8->m_atoms.m_transforms.m_transformA.m_translation, v7, v5);
  hkVector4f::setTransformedInversePos(&v8->m_atoms.m_transforms.m_transformB.m_translation, v6, v5);
}

// File Line: 101
// RVA: 0xD49740
void __fastcall hkpPrismaticConstraintData::setInBodySpace(hkpPrismaticConstraintData *this, hkVector4f *pivotA, hkVector4f *pivotB, hkVector4f *axisA, hkVector4f *axisB, hkVector4f *axisAPerp, hkVector4f *axisBPerp)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm5
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm3
  __m128 v24; // xmm1

  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  v7 = _mm_mul_ps(axisA->m_quad, axisA->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmpleps(v8, (__m128)0i64),
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
                   _mm_cmpleps(v11, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                     _mm_mul_ps(*(__m128 *)_xmm, v12))),
                 axisAPerp->m_quad);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)v14.m_quad;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v13.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v14.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v15, v15, 201);
  v16 = _mm_mul_ps(axisB->m_quad, axisB->m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmpleps(v17, (__m128)0i64),
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
                   _mm_cmpleps(v20, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                     _mm_mul_ps(*(__m128 *)_xmm, v21))),
                 axisBPerp->m_quad);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)v23.m_quad;
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 201), v22.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 201), v23.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v24, v24, 201);
}

// File Line: 119
// RVA: 0xD49920
void __fastcall hkpPrismaticConstraintData::setMotor(hkpPrismaticConstraintData *this, hkpConstraintMotor *motor)
{
  hkpConstraintMotor *v2; // rbx
  hkpPrismaticConstraintData *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = motor;
  v3 = this;
  if ( motor )
    hkReferencedObject::addReference((hkReferencedObject *)&motor->vfptr);
  v4 = (hkReferencedObject *)&v3->m_atoms.m_motor.m_motor->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_atoms.m_motor.m_motor = v2;
}

// File Line: 134
// RVA: 0xD49A40
void __fastcall hkpPrismaticConstraintData::getConstraintInfo(hkpPrismaticConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_transforms.m_type, 248, infoOut);
}

// File Line: 139
// RVA: 0xD49A60
void __fastcall hkpPrismaticConstraintData::getRuntimeInfo(hkpPrismaticConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 10;
  infoOut->m_sizeOfExternalRuntime = 88;
}

// File Line: 147
// RVA: 0xD499C0
hkBool *__fastcall hkpPrismaticConstraintData::isValid(hkpPrismaticConstraintData *this, hkBool *result)
{
  hkpPrismaticConstraintData *v2; // rdi
  hkBool *v3; // rbx
  hkBool *v4; // rax

  v2 = this;
  v3 = result;
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
    && hkRotationf::isOrthonormal(&v2->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
    && v2->m_atoms.m_linLimit.m_max >= v2->m_atoms.m_linLimit.m_min )
  {
    v3->m_bool = 1;
    v4 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v4 = v3;
  }
  return v4;
}

// File Line: 152
// RVA: 0xD499B0
signed __int64 __fastcall hkpPrismaticConstraintData::getType(hkpPrismaticConstraintData *this)
{
  return 6i64;
}

// File Line: 157
// RVA: 0xD49970
void __fastcall hkpPrismaticConstraintData::setMotorEnabled(hkpPrismaticConstraintData *this, struct hkpConstraintRuntime *runtimeIn, hkBool isEnabled)
{
  this->m_atoms.m_motor.m_isEnabled = isEnabled;
  this->m_atoms.m_friction.m_isEnabled = isEnabled.m_bool == 0;
  if ( runtimeIn )
  {
    *(_QWORD *)runtimeIn = 0i64;
    *((_QWORD *)runtimeIn + 1) = 0i64;
    *((_QWORD *)runtimeIn + 2) = 0i64;
    *((_QWORD *)runtimeIn + 3) = 0i64;
  }
}

