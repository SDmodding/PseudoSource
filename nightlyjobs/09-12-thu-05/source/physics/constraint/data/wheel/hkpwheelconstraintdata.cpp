// File Line: 16
// RVA: 0xD49D20
void __fastcall hkpWheelConstraintData::hkpWheelConstraintData(hkpWheelConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWheelConstraintData::`vftable;
  this->m_userData = 0i64;
  this->m_atoms.m_suspensionBase.m_type.m_storage = 2;
  this->m_atoms.m_lin0Limit.m_type.m_storage = 9;
  this->m_atoms.m_lin0Soft.m_type.m_storage = 8;
  this->m_atoms.m_lin1.m_type.m_storage = 7;
  this->m_atoms.m_lin2.m_type.m_storage = 7;
  this->m_atoms.m_steeringBase.m_type.m_storage = 4;
  this->m_atoms.m_2dAng.m_type.m_storage = 12;
  this->m_atoms.m_lin0Limit.m_axisIndex = 0;
  this->m_atoms.m_lin0Soft.m_axisIndex = 0;
  this->m_atoms.m_lin1.m_axisIndex = 1;
  this->m_atoms.m_lin2.m_axisIndex = 2;
  this->m_atoms.m_lin0Limit.m_min = -0.5;
  this->m_atoms.m_lin0Limit.m_max = 0.5;
  *(_QWORD *)&this->m_atoms.m_lin0Soft.m_tau = 0i64;
  this->m_atoms.m_steeringBase.m_rotationA.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_steeringBase.m_rotationA.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_steeringBase.m_rotationA.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_steeringBase.m_rotationB.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_steeringBase.m_rotationB.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_steeringBase.m_rotationB.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_translation = 0i64;
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_suspensionBase.m_transformB.m_translation = 0i64;
  this->m_atoms.m_2dAng.m_freeRotationAxis = 0;
}

// File Line: 40
// RVA: 0xD49E80
void __fastcall hkpWheelConstraintData::setInWorldSpace(
        hkpWheelConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *pivot,
        hkVector4f *axleTmp,
        hkVector4f *suspensionAxis,
        hkVector4f *steeringAxisTmp)
{
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  hkVector4f v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  hkVector4f v32; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f v33; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f b; // [rsp+40h] [rbp-68h] BYREF
  hkVector4f v35; // [rsp+50h] [rbp-58h] BYREF

  v11 = _mm_mul_ps(axleTmp->m_quad, axleTmp->m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v32.m_quad = _mm_mul_ps(
                 axleTmp->m_quad,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v12, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                     _mm_mul_ps(v13, *(__m128 *)_xmm))));
  v14 = _mm_mul_ps(steeringAxisTmp->m_quad, steeringAxisTmp->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          steeringAxisTmp->m_quad,
          _mm_andnot_ps(
            _mm_cmple_ps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(v16, *(__m128 *)_xmm))));
  b.m_quad = _mm_sub_ps(pivot->m_quad, bodyATransform->m_translation.m_quad);
  v33.m_quad = v17;
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_suspensionBase.m_transformA.m_translation,
    &bodyATransform->m_rotation,
    &b);
  v35.m_quad = _mm_sub_ps(pivot->m_quad, bodyBTransform->m_translation.m_quad);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_suspensionBase.m_transformB.m_translation,
    &bodyBTransform->m_rotation,
    &v35);
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0,
    &bodyBTransform->m_rotation,
    suspensionAxis);
  v18 = _mm_shuffle_ps(
          this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0.m_quad,
          _mm_unpackhi_ps(this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0.m_quad, (__m128)0i64),
          196);
  v19 = _mm_shuffle_ps(v18, v18, 241);
  v20 = _mm_shuffle_ps(v18, v18, 206);
  v21 = _mm_mul_ps(v19, v19);
  v22 = _mm_mul_ps(v20, v20);
  v23 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
            _mm_shuffle_ps(v22, v22, 170)));
  v24 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v23, v19), _mm_and_ps(v20, v23)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v28.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v26, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                     _mm_mul_ps(v27, *(__m128 *)_xmm))),
                 v24);
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col1 = (hkVector4f)v28.m_quad;
  v29 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(v28.m_quad, v28.m_quad, 201),
            this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0.m_quad,
              this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0.m_quad,
              201),
            v28.m_quad));
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v29, v29, 201);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_steeringBase.m_rotationA.m_col0, &bodyATransform->m_rotation, &v32);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_steeringBase.m_rotationB.m_col0, &bodyBTransform->m_rotation, &v32);
  this->m_initialAxleInB = this->m_atoms.m_steeringBase.m_rotationB.m_col0;
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_steeringBase.m_rotationA.m_col1, &bodyATransform->m_rotation, &v33);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_steeringBase.m_rotationB.m_col1, &bodyBTransform->m_rotation, &v33);
  this->m_initialSteeringAxisInB = this->m_atoms.m_steeringBase.m_rotationB.m_col1;
  v30 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad,
              this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad,
              this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad));
  this->m_atoms.m_steeringBase.m_rotationA.m_col2.m_quad = _mm_shuffle_ps(v30, v30, 201);
  v31 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad,
              this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad,
              this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad));
  this->m_atoms.m_steeringBase.m_rotationB.m_col2.m_quad = _mm_shuffle_ps(v31, v31, 201);
}

// File Line: 85
// RVA: 0xD4A1C0
void __fastcall hkpWheelConstraintData::setInBodySpace(
        hkpWheelConstraintData *this,
        hkVector4f *pivotA,
        hkVector4f *pivotB,
        hkVector4f *axleA,
        hkVector4f *axleB,
        hkVector4f *suspensionAxisB,
        hkVector4f *steeringAxisB)
{
  __m128 m_quad; // xmm6
  __m128 inserted; // xmm8
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  hkVector4f v29; // xmm4
  __m128 v30; // xmm7
  __m128 v31; // xmm5
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  hkVector4f v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm2

  this->m_atoms.m_suspensionBase.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_suspensionBase.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_suspensionBase.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  m_quad = suspensionAxisB->m_quad;
  inserted = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0 = (hkVector4f)suspensionAxisB->m_quad;
  v9 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
  v10 = _mm_shuffle_ps(v9, v9, 241);
  v11 = _mm_shuffle_ps(v9, v9, 206);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_mul_ps(v10, v10);
  v14 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)));
  v15 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v11, v14), _mm_andnot_ps(v14, v10)), inserted);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19.m_quad = (__m128)this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col0;
  v20.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v17, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                     _mm_mul_ps(*(__m128 *)_xmm, v18))),
                 v15);
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col1 = (hkVector4f)v20.m_quad;
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 201), v19.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 201), v20.m_quad));
  this->m_atoms.m_suspensionBase.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v21, v21, 201);
  v22 = _mm_mul_ps(axleA->m_quad, axleA->m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad = _mm_mul_ps(
                                                             _mm_andnot_ps(
                                                               _mm_cmple_ps(v23, (__m128)0i64),
                                                               _mm_mul_ps(
                                                                 _mm_sub_ps(
                                                                   (__m128)_xmm,
                                                                   _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                                                                 _mm_mul_ps(*(__m128 *)_xmm, v24))),
                                                             axleA->m_quad);
  v25 = axleB->m_quad;
  this->m_atoms.m_steeringBase.m_rotationB.m_col0 = (hkVector4f)axleB->m_quad;
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v27, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                     _mm_mul_ps(v28, *(__m128 *)_xmm))),
                 this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad);
  this->m_atoms.m_steeringBase.m_rotationB.m_col0 = (hkVector4f)v29.m_quad;
  this->m_initialAxleInB = (hkVector4f)v29.m_quad;
  v30 = _mm_shuffle_ps(
          this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad,
          _mm_unpackhi_ps(this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad, (__m128)0i64),
          196);
  v31 = _mm_shuffle_ps(v30, v30, 241);
  v32 = _mm_shuffle_ps(v30, v30, 206);
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_mul_ps(v31, v31);
  v35 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170)));
  v36 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v35, v31), _mm_and_ps(v32, v35)), inserted);
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad = _mm_mul_ps(
                                                             _mm_andnot_ps(
                                                               _mm_cmple_ps(v38, (__m128)0i64),
                                                               _mm_mul_ps(
                                                                 _mm_sub_ps(
                                                                   (__m128)_xmm,
                                                                   _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                                                                 _mm_mul_ps(v39, *(__m128 *)_xmm))),
                                                             v36);
  v40 = steeringAxisB->m_quad;
  this->m_atoms.m_steeringBase.m_rotationB.m_col1 = (hkVector4f)steeringAxisB->m_quad;
  v41 = _mm_mul_ps(v40, v40);
  v42 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v43 = _mm_rsqrt_ps(v42);
  v44.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v42, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                     _mm_mul_ps(v43, *(__m128 *)_xmm))),
                 this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad);
  this->m_atoms.m_steeringBase.m_rotationB.m_col1 = (hkVector4f)v44.m_quad;
  this->m_initialSteeringAxisInB = (hkVector4f)v44.m_quad;
  v45 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad,
              this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad,
              this->m_atoms.m_steeringBase.m_rotationA.m_col0.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationA.m_col1.m_quad));
  this->m_atoms.m_steeringBase.m_rotationA.m_col2.m_quad = _mm_shuffle_ps(v45, v45, 201);
  v46 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad,
              this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad,
              this->m_atoms.m_steeringBase.m_rotationB.m_col0.m_quad,
              201),
            this->m_atoms.m_steeringBase.m_rotationB.m_col1.m_quad));
  this->m_atoms.m_steeringBase.m_rotationB.m_col2.m_quad = _mm_shuffle_ps(v46, v46, 201);
}

// File Line: 121
// RVA: 0xD4A590
void __fastcall hkpWheelConstraintData::setSteeringAngle(hkpWheelConstraintData *this, float angle)
{
  __m128i si128; // xmm6
  __m128 v3; // xmm3
  __m128i v4; // xmm7
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  float v10; // xmm0_4
  hkVector4f v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // xmm3
  __m128 v14; // xmm1
  float v15; // [rsp+50h] [rbp+8h]
  float v16; // [rsp+58h] [rbp+10h]

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(angle));
  v4 = _mm_add_epi32(si128, si128);
  v5 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v3)), si128));
  v6 = _mm_cvtepi32_ps(v5);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v5, v4), (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v6), v3), _mm_mul_ps(*(__m128 *)DP2, v6)),
         _mm_mul_ps(*(__m128 *)DP3, v6));
  v9 = _mm_mul_ps(v8, v8);
  v3.m128_f32[0] = _mm_andnot_ps(
                     v7,
                     _mm_add_ps(
                       _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v9, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v9),
                               *(__m128 *)cosCoeff2_0),
                             v9),
                           v9),
                         _mm_mul_ps(v9, *(__m128 *)_xmm)),
                       *(__m128 *)_xmm)).m128_f32[0];
  v10 = (float)((float)((float)((float)(v9.m128_f32[0] * -0.00019515296) + 0.0083321612) * v9.m128_f32[0]) + -0.16666655)
      * v9.m128_f32[0];
  v11.m_quad = (__m128)this->m_initialAxleInB;
  LODWORD(v15) = (v3.m128_i32[0] | COERCE_UNSIGNED_INT((float)(v10 * v8.m128_f32[0]) + v8.m128_f32[0]) & v7.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v4, v4), v5).m128i_u32[0] << 29) ^ _xmm[0] & LODWORD(angle);
  v16 = fsqrt(1.0 - (float)(v15 * v15));
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 201), this->m_initialSteeringAxisInB.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(this->m_initialSteeringAxisInB.m_quad, this->m_initialSteeringAxisInB.m_quad, 201),
            v11.m_quad));
  v13.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(v12, v12, 201),
                   _mm_shuffle_ps((__m128)LODWORD(v15), (__m128)LODWORD(v15), 0)),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v16), (__m128)LODWORD(v16), 0), v11.m_quad));
  this->m_atoms.m_steeringBase.m_rotationB.m_col0 = (hkVector4f)v13.m_quad;
  v14 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(this->m_initialSteeringAxisInB.m_quad, this->m_initialSteeringAxisInB.m_quad, 201),
            v13.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), this->m_initialSteeringAxisInB.m_quad));
  this->m_atoms.m_steeringBase.m_rotationB.m_col2.m_quad = _mm_shuffle_ps(v14, v14, 201);
}

// File Line: 137
// RVA: 0xD4A870
void __fastcall hkpWheelConstraintData::getConstraintInfo(
        hkpWheelConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_suspensionBase, 0x150u, infoOut);
}

// File Line: 142
// RVA: 0xD4A890
void __fastcall hkpWheelConstraintData::getRuntimeInfo(
        hkpWheelConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool )
  {
    infoOut->m_numSolverResults = 6;
    infoOut->m_sizeOfExternalRuntime = 48;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 157
// RVA: 0xD4A770
hkBool *__fastcall hkpWheelConstraintData::isValid(hkpWheelConstraintData *this, hkBool *result)
{
  hkVector4f v2; // xmm0
  hkVector4f v3; // xmm1
  hkTransformf *p_m_transformA; // rcx
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  hkRotationf v11; // [rsp+20h] [rbp-98h] BYREF
  __m128 m_quad; // [rsp+50h] [rbp-68h]
  hkRotationf v13; // [rsp+60h] [rbp-58h] BYREF
  __m128 v14; // [rsp+90h] [rbp-28h]

  v2.m_quad = (__m128)this->m_atoms.m_steeringBase.m_rotationA.m_col0;
  v3.m_quad = (__m128)this->m_atoms.m_steeringBase.m_rotationA.m_col1;
  p_m_transformA = &this->m_atoms.m_suspensionBase.m_transformA;
  v11.m_col0 = (hkVector4f)v2.m_quad;
  v7.m_quad = (__m128)p_m_transformA[3].m_translation;
  v11.m_col1 = (hkVector4f)v3.m_quad;
  v8.m_quad = (__m128)p_m_transformA[4].m_rotation.m_col1;
  v11.m_col2 = (hkVector4f)v7.m_quad;
  v13.m_col0 = p_m_transformA[4].m_rotation.m_col0;
  v9.m_quad = (__m128)p_m_transformA[4].m_rotation.m_col2;
  v13.m_col1 = (hkVector4f)v8.m_quad;
  v13.m_col2 = (hkVector4f)v9.m_quad;
  m_quad = aabbOut.m_quad;
  v14 = aabbOut.m_quad;
  result->m_bool = hkRotationf::isOrthonormal(&p_m_transformA->m_rotation, 0.0000099999997)
                && hkRotationf::isOrthonormal(&this->m_atoms.m_suspensionBase.m_transformB.m_rotation, 0.0000099999997)
                && hkRotationf::isOrthonormal(&v11, 0.0000099999997)
                && hkRotationf::isOrthonormal(&v13, 0.0000099999997)
                && this->m_atoms.m_lin0Limit.m_max >= this->m_atoms.m_lin0Limit.m_min;
  return result;
}

// File Line: 168
// RVA: 0xD4A760
__int64 __fastcall hkpWheelConstraintData::getType(hkpWheelConstraintData *this)
{
  return 9i64;
}

