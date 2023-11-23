// File Line: 16
// RVA: 0xD4D450
void __fastcall hkpRackAndPinionConstraintData::hkpRackAndPinionConstraintData(hkpRackAndPinionConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRackAndPinionConstraintData::`vftable;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_rackAndPinion.m_type.m_storage = 21;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch = 1.0;
  *(_DWORD *)&this->m_atoms.m_rackAndPinion.m_isScrew.m_bool = 269223936;
}

// File Line: 33
// RVA: 0xD4D500
void __fastcall hkpRackAndPinionConstraintData::setInWorldSpace(
        hkpRackAndPinionConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *pinionARotationPivot,
        hkVector4f *pinionARotationAxis,
        hkVector4f *rackBShiftAxis,
        float pinionRadiusOrScrewPitch,
        hkpRackAndPinionConstraintData::Type type)
{
  __m128 v12; // xmm5
  __m128 inserted; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm8
  __m128 v19; // xmm3
  __m128 v20; // xmm7
  __m128 v21; // xmm4
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm7
  __m128 v26; // xmm3
  __m128 v27; // xmm8
  hkTransformf *p_m_transformA; // rcx
  __int64 v29; // r8
  hkTransformf *p_m_transformB; // rax
  __m128 v31; // xmm1
  char *v32; // r9
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  hkVector4f v40; // xmm2
  __m128 v41; // xmm8
  hkVector4f v42; // xmm3
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __int64 v47; // rdx
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm1
  hkVector4f v51; // xmm2
  char *v52; // rcx
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm1
  __m128 m_quad; // [rsp+20h] [rbp-C8h] BYREF
  __m128 v59; // [rsp+30h] [rbp-B8h]
  __m128 v60; // [rsp+40h] [rbp-A8h]
  __m128 v61[9]; // [rsp+50h] [rbp-98h] BYREF

  m_quad = pinionARotationAxis->m_quad;
  v12 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
  inserted = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v61[0] = rackBShiftAxis->m_quad;
  v14 = _mm_shuffle_ps(v12, v12, 241);
  v15 = _mm_shuffle_ps(v12, v12, 206);
  v16 = _mm_mul_ps(v14, v14);
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_shuffle_ps(v61[0], _mm_unpackhi_ps(v61[0], (__m128)0i64), 196);
  v19 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170)));
  v20 = _mm_andnot_ps(v19, v14);
  v21 = _mm_shuffle_ps(v18, v18, 241);
  v22 = _mm_shuffle_ps(v18, v18, 206);
  v23 = _mm_mul_ps(v21, v21);
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_xor_ps(_mm_or_ps(v20, _mm_and_ps(v15, v19)), inserted);
  v26 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
            _mm_shuffle_ps(v23, v23, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  v27 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v22, v26), _mm_andnot_ps(v26, v21)), inserted);
  p_m_transformA = &this->m_atoms.m_transforms.m_transformA;
  v29 = 3i64;
  p_m_transformB = &this->m_atoms.m_transforms.m_transformB;
  v31 = _mm_mul_ps(v25, v25);
  v32 = (char *)((char *)&m_quad - (char *)p_m_transformA);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(v27, v27);
  v59 = _mm_mul_ps(
          v25,
          _mm_andnot_ps(
            _mm_cmple_ps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(v34, *(__m128 *)_xmm))));
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_cmple_ps(v36, (__m128)0i64);
  v39 = _mm_mul_ps(v37, v36);
  v40.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v41 = _mm_mul_ps(
          v27,
          _mm_andnot_ps(
            v38,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v37)), _mm_mul_ps(v37, *(__m128 *)_xmm))));
  v42.m_quad = (__m128)bodyATransform->m_rotation.m_col0;
  v43 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v59));
  v61[1] = v41;
  v60 = _mm_shuffle_ps(v43, v43, 201);
  v44 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v61[0]),
          _mm_mul_ps(_mm_shuffle_ps(v61[0], v61[0], 201), v41));
  v61[2] = _mm_shuffle_ps(v44, v44, 201);
  v45 = _mm_unpacklo_ps(v42.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v46 = _mm_shuffle_ps(_mm_unpackhi_ps(v42.m_quad, bodyATransform->m_rotation.m_col1.m_quad), v40.m_quad, 228);
  v47 = 3i64;
  v48 = _mm_movelh_ps(v45, v40.m_quad);
  v49 = _mm_shuffle_ps(_mm_movehl_ps(v48, v45), v40.m_quad, 212);
  do
  {
    v50 = *(__m128 *)((char *)&p_m_transformA->m_rotation.m_col0.m_quad + (_QWORD)v32);
    p_m_transformA = (hkTransformf *)((char *)p_m_transformA + 16);
    p_m_transformA[-1].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v49),
                                                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v48)),
                                                _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v46));
    --v47;
  }
  while ( v47 );
  v51.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v52 = (char *)((char *)v61 - (char *)p_m_transformB);
  v53 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v54 = _mm_shuffle_ps(
          _mm_unpackhi_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad),
          v51.m_quad,
          228);
  v55 = _mm_movelh_ps(v53, v51.m_quad);
  v56 = _mm_shuffle_ps(_mm_movehl_ps(v55, v53), v51.m_quad, 212);
  do
  {
    v57 = *(__m128 *)((char *)&p_m_transformB->m_rotation.m_col0.m_quad + (_QWORD)v52);
    p_m_transformB = (hkTransformf *)((char *)p_m_transformB + 16);
    p_m_transformB[-1].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v56),
                                                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v55)),
                                                _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v54));
    --v29;
  }
  while ( v29 );
  hkVector4f::setTransformedInversePos(
    &this->m_atoms.m_transforms.m_transformA.m_translation,
    bodyATransform,
    pinionARotationPivot);
  hkVector4f::setTransformedInversePos(
    &this->m_atoms.m_transforms.m_transformB.m_translation,
    bodyBTransform,
    pinionARotationPivot);
  this->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch = pinionRadiusOrScrewPitch;
  this->m_atoms.m_rackAndPinion.m_isScrew.m_bool = type == TYPE_SCREW;
}

// File Line: 75
// RVA: 0xD4D880
void __fastcall hkpRackAndPinionConstraintData::setInBodySpace(
        hkpRackAndPinionConstraintData *this,
        hkVector4f *pinionARotationPivotInA,
        hkVector4f *pinionARotationPivotInB,
        hkVector4f *pinionARotationAxisInA,
        hkVector4f *rackBShiftAxisInB,
        float pinionRadiusOrScrewPitch,
        hkpRackAndPinionConstraintData::Type type)
{
  __m128 inserted; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  hkVector4f v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  hkVector4f v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 m_quad; // xmm1

  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)pinionARotationAxisInA->m_quad;
  inserted = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)rackBShiftAxisInB->m_quad;
  v8 = _mm_shuffle_ps(
         this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad,
         _mm_unpackhi_ps(this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0.m_quad, (__m128)0i64),
         196);
  v9 = _mm_shuffle_ps(v8, v8, 241);
  v10 = _mm_shuffle_ps(v8, v8, 206);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_mul_ps(v9, v9);
  v13 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad = _mm_xor_ps(
                                                                       _mm_or_ps(
                                                                         _mm_andnot_ps(v13, v9),
                                                                         _mm_and_ps(v10, v13)),
                                                                       inserted);
  v14 = _mm_shuffle_ps(
          this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad,
          _mm_unpackhi_ps(this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad, (__m128)0i64),
          196);
  v15 = _mm_shuffle_ps(v14, v14, 241);
  v16 = _mm_shuffle_ps(v14, v14, 206);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_mul_ps(v15, v15);
  v19 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170)));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad = _mm_xor_ps(
                                                                       _mm_or_ps(
                                                                         _mm_and_ps(v16, v19),
                                                                         _mm_andnot_ps(v19, v15)),
                                                                       inserted);
  v20.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1;
  v21 = _mm_mul_ps(v20.m_quad, v20.m_quad);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v22, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v23))),
                                                                       v20.m_quad);
  v24.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1;
  v25 = _mm_mul_ps(v24.m_quad, v24.m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1.m_quad = _mm_mul_ps(
                                                                       _mm_andnot_ps(
                                                                         _mm_cmple_ps(v26, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_sub_ps(
                                                                             (__m128)_xmm,
                                                                             _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                                                           _mm_mul_ps(*(__m128 *)_xmm, v27))),
                                                                       v24.m_quad);
  v28 = _mm_sub_ps(
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
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v28, v28, 201);
  v29 = _mm_sub_ps(
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
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v29, v29, 201);
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pinionARotationPivotInA->m_quad;
  m_quad = pinionARotationPivotInB->m_quad;
  this->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch = pinionRadiusOrScrewPitch;
  this->m_atoms.m_transforms.m_transformB.m_translation.m_quad = m_quad;
  this->m_atoms.m_rackAndPinion.m_isScrew.m_bool = type == TYPE_SCREW;
}

// File Line: 109
// RVA: 0xD4DAF0
hkBool *__fastcall hkpRackAndPinionConstraintData::isValid(hkpRackAndPinionConstraintData *this, hkBool *result)
{
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
    && hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997)
    && COERCE_FLOAT((unsigned int)(2 * COERCE_INT(0.0 - this->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch)) >> 1) > 0.00000011920929 )
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
// RVA: 0xD4DAE0
__int64 __fastcall hkpRackAndPinionConstraintData::getType(hkpRackAndPinionConstraintData *this)
{
  return 21i64;
}

// File Line: 121
// RVA: 0xD4DBA0
void __fastcall hkpRackAndPinionConstraintData::getConstraintInfo(
        hkpRackAndPinionConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0xA0u, infoOut);
}

// File Line: 126
// RVA: 0xD4DBC0
void __fastcall hkpRackAndPinionConstraintData::getRuntimeInfo(
        hkpRackAndPinionConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 1;
  infoOut->m_sizeOfExternalRuntime = 20;
}

