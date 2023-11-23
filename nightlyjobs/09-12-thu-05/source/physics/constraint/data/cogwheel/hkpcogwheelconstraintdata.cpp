// File Line: 16
// RVA: 0xD4B450
void __fastcall hkpCogWheelConstraintData::hkpCogWheelConstraintData(hkpCogWheelConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCogWheelConstraintData::`vftable;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_cogWheels.m_type.m_storage = 22;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_cogWheels.m_cogWheelRadiusA = 1.0;
  this->m_atoms.m_cogWheels.m_cogWheelRadiusB = 1.0;
  *(_DWORD *)&this->m_atoms.m_cogWheels.m_isScrew.m_bool = 403703808;
}

// File Line: 32
// RVA: 0xD4B500
void __fastcall hkpCogWheelConstraintData::setInWorldSpace(
        hkpCogWheelConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *rotationPivotA,
        hkVector4f *rotationAxisA,
        float radiusA,
        hkVector4f *rotationPivotB,
        hkVector4f *rotationAxisB,
        float radiusB)
{
  __m128 v13; // xmm9
  __m128 inserted; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm9
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128 v21; // xmm9
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm9
  __m128 v27; // xmm3
  __m128 v28; // xmm7
  hkTransformf *p_m_transformA; // rcx
  __int64 v30; // r8
  hkTransformf *p_m_transformB; // rax
  char *v32; // r9
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm0
  hkVector4f v41; // xmm2
  __m128 v42; // xmm7
  __m128 v43; // xmm0
  hkVector4f v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __int64 v48; // rdx
  __m128 v49; // xmm5
  __m128 v50; // xmm4
  __m128 v51; // xmm1
  hkVector4f v52; // xmm2
  char *v53; // rcx
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm5
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  hkVector4f v59; // xmm3
  __m128 v60; // xmm5
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  hkVector4f v63; // xmm3
  __m128 v64; // xmm1
  __m128 v65; // xmm5
  __m128 v66; // xmm2
  hkVector4f v67; // xmm1
  __m128 m_quad; // [rsp+0h] [rbp-C8h] BYREF
  __m128 v69; // [rsp+10h] [rbp-B8h]
  __m128 v70; // [rsp+20h] [rbp-A8h]
  __m128 v71[9]; // [rsp+30h] [rbp-98h] BYREF

  m_quad = rotationAxisA->m_quad;
  v13 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
  inserted = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v71[0] = rotationAxisB->m_quad;
  v15 = _mm_shuffle_ps(v13, v13, 241);
  v16 = _mm_shuffle_ps(v13, v13, 206);
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_mul_ps(v16, v16);
  v19 = _mm_shuffle_ps(v71[0], _mm_unpackhi_ps(v71[0], (__m128)0i64), 196);
  v20 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170)));
  v21 = _mm_or_ps(_mm_and_ps(v16, v20), _mm_andnot_ps(v20, v15));
  v22 = _mm_shuffle_ps(v19, v19, 241);
  v23 = _mm_shuffle_ps(v19, v19, 206);
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_mul_ps(v23, v23);
  v26 = _mm_xor_ps(v21, inserted);
  v27 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170)));
  v28 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v27, v22), _mm_and_ps(v23, v27)), inserted);
  p_m_transformA = &this->m_atoms.m_transforms.m_transformA;
  v30 = 3i64;
  p_m_transformB = &this->m_atoms.m_transforms.m_transformB;
  v32 = (char *)((char *)&m_quad - (char *)p_m_transformA);
  v33 = _mm_mul_ps(v26, v26);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_mul_ps(v28, v28);
  v69 = _mm_mul_ps(
          v26,
          _mm_andnot_ps(
            _mm_cmple_ps(v34, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35))));
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  v39 = _mm_cmple_ps(v37, (__m128)0i64);
  v40 = _mm_mul_ps(v38, v37);
  v41.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v42 = _mm_mul_ps(
          v28,
          _mm_andnot_ps(
            v39,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v38)), _mm_mul_ps(*(__m128 *)_xmm, v38))));
  v43 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v69));
  v44.m_quad = (__m128)bodyATransform->m_rotation.m_col0;
  v71[1] = v42;
  v70 = _mm_shuffle_ps(v43, v43, 201);
  v45 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v71[0]),
          _mm_mul_ps(_mm_shuffle_ps(v71[0], v71[0], 201), v42));
  v71[2] = _mm_shuffle_ps(v45, v45, 201);
  v46 = _mm_unpacklo_ps(v44.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v47 = _mm_shuffle_ps(_mm_unpackhi_ps(v44.m_quad, bodyATransform->m_rotation.m_col1.m_quad), v41.m_quad, 228);
  v48 = 3i64;
  v49 = _mm_movelh_ps(v46, v41.m_quad);
  v50 = _mm_shuffle_ps(_mm_movehl_ps(v49, v46), v41.m_quad, 212);
  do
  {
    v51 = *(__m128 *)((char *)&p_m_transformA->m_rotation.m_col0.m_quad + (_QWORD)v32);
    p_m_transformA = (hkTransformf *)((char *)p_m_transformA + 16);
    p_m_transformA[-1].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), v50),
                                                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v49)),
                                                _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), v47));
    --v48;
  }
  while ( v48 );
  v52.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v53 = (char *)((char *)v71 - (char *)p_m_transformB);
  v54 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v55 = _mm_shuffle_ps(
          _mm_unpackhi_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad),
          v52.m_quad,
          228);
  v56 = _mm_movelh_ps(v54, v52.m_quad);
  v57 = _mm_shuffle_ps(_mm_movehl_ps(v56, v54), v52.m_quad, 212);
  do
  {
    v58 = *(__m128 *)((char *)&p_m_transformB->m_rotation.m_col0.m_quad + (_QWORD)v53);
    p_m_transformB = (hkTransformf *)((char *)p_m_transformB + 16);
    p_m_transformB[-1].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v58, v58, 85), v57),
                                                  _mm_mul_ps(_mm_shuffle_ps(v58, v58, 0), v56)),
                                                _mm_mul_ps(_mm_shuffle_ps(v58, v58, 170), v55));
    --v30;
  }
  while ( v30 );
  v59.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v60 = _mm_sub_ps(rotationPivotA->m_quad, bodyATransform->m_translation.m_quad);
  v61 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v62 = _mm_movelh_ps(v61, v59.m_quad);
  this->m_atoms.m_transforms.m_transformA.m_translation.m_quad = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_mul_ps(
                                                                       _mm_shuffle_ps(v60, v60, 85),
                                                                       _mm_shuffle_ps(
                                                                         _mm_movehl_ps(v62, v61),
                                                                         v59.m_quad,
                                                                         212)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v62)),
                                                                   _mm_mul_ps(
                                                                     _mm_shuffle_ps(v60, v60, 170),
                                                                     _mm_shuffle_ps(
                                                                       _mm_unpackhi_ps(
                                                                         bodyATransform->m_rotation.m_col0.m_quad,
                                                                         bodyATransform->m_rotation.m_col1.m_quad),
                                                                       v59.m_quad,
                                                                       228)));
  v63.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v64 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v65 = _mm_sub_ps(rotationPivotB->m_quad, bodyBTransform->m_translation.m_quad);
  v66 = _mm_movelh_ps(v64, v63.m_quad);
  v67.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(_mm_movehl_ps(v66, v64), v63.m_quad, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v66)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(v65, v65, 170),
                   _mm_shuffle_ps(
                     _mm_unpackhi_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad),
                     v63.m_quad,
                     228)));
  this->m_atoms.m_cogWheels.m_cogWheelRadiusA = radiusA;
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)v67.m_quad;
  this->m_atoms.m_cogWheels.m_cogWheelRadiusB = radiusB;
}

// File Line: 73
// RVA: 0xD4B930
void __fastcall hkpCogWheelConstraintData::setInBodySpace(
        hkpCogWheelConstraintData *this,
        hkVector4f *rotationPivotAInA,
        hkVector4f *rotationAxisAInA,
        float radiusA,
        hkVector4f *rotationPivotBInB,
        hkVector4f *rotationAxisBInB,
        float radiusB)
{
  __m128 inserted; // xmm7
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm2
  hkVector4f v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  hkVector4f v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm2
  __m128 m_quad; // xmm1

  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)rotationAxisAInA->m_quad;
  inserted = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)rotationAxisBInB->m_quad;
  v9 = _mm_shuffle_ps(
         this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad,
         _mm_unpackhi_ps(this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad, (__m128)0i64),
         196);
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
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad = _mm_xor_ps(
                                                                       _mm_or_ps(
                                                                         _mm_andnot_ps(v14, v10),
                                                                         _mm_and_ps(v11, v14)),
                                                                       inserted);
  v15 = _mm_shuffle_ps(
          this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad,
          _mm_unpackhi_ps(this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad, (__m128)0i64),
          196);
  v16 = _mm_shuffle_ps(v15, v15, 241);
  v17 = _mm_shuffle_ps(v15, v15, 206);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_mul_ps(v16, v16);
  v20 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170)));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad = _mm_xor_ps(
                                                                       _mm_or_ps(
                                                                         _mm_and_ps(v17, v20),
                                                                         _mm_andnot_ps(v20, v16)),
                                                                       inserted);
  v21.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1;
  v22 = _mm_mul_ps(v21.m_quad, v21.m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v23, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v24))),
                                                                       v21.m_quad);
  v25.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1;
  v26 = _mm_mul_ps(v25.m_quad, v25.m_quad);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v27, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v28))),
                                                                       v25.m_quad);
  v29 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad,
              this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad,
              201),
            this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad,
              this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad,
              201),
            this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v29, v29, 201);
  v30 = _mm_sub_ps(
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
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v30, v30, 201);
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)rotationPivotAInA->m_quad;
  m_quad = rotationPivotBInB->m_quad;
  this->m_atoms.m_cogWheels.m_cogWheelRadiusA = radiusA;
  this->m_atoms.m_cogWheels.m_cogWheelRadiusB = radiusB;
  this->m_atoms.m_transforms.m_transformB.m_translation.m_quad = m_quad;
}

// File Line: 108
// RVA: 0xD4BBB0
hkBool *__fastcall hkpCogWheelConstraintData::isValid(hkpCogWheelConstraintData *this, hkBool *result)
{
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
    && hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
    && COERCE_FLOAT((unsigned int)(2 * COERCE_INT(0.0 - this->m_atoms.m_cogWheels.m_cogWheelRadiusA)) >> 1) > 0.00000011920929
    && COERCE_FLOAT((unsigned int)(2 * COERCE_INT(0.0 - this->m_atoms.m_cogWheels.m_cogWheelRadiusB)) >> 1) > 0.00000011920929 )
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

// File Line: 116
// RVA: 0xD4BBA0
__int64 __fastcall hkpCogWheelConstraintData::getType(hkpCogWheelConstraintData *this)
{
  return 22i64;
}

// File Line: 121
// RVA: 0xD4BCA0
void __fastcall hkpCogWheelConstraintData::getConstraintInfo(
        hkpCogWheelConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0xA0u, infoOut);
}

// File Line: 126
// RVA: 0xD4BCC0
void __fastcall hkpCogWheelConstraintData::getRuntimeInfo(
        hkpCogWheelConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 1;
  infoOut->m_sizeOfExternalRuntime = 32;
}

