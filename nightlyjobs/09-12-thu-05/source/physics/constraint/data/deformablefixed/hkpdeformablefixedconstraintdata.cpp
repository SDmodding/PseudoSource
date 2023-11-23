// File Line: 14
// RVA: 0xD480C0
void __fastcall hkpDeformableFixedConstraintData::hkpDeformableFixedConstraintData(
        hkpDeformableFixedConstraintData *this)
{
  hkVector4f v1; // xmm2

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDeformableFixedConstraintData::`vftable;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_lin.m_type.m_storage = 25;
  this->m_atoms.m_lin.m_offset = 0i64;
  this->m_atoms.m_ang.m_type.m_storage = 26;
  this->m_atoms.m_ang.m_offset = (hkQuaternionf)qi.m_vec.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_lin.m_yieldStrengthDiag = (hkVector4f)xmmword_141A712A0;
  this->m_atoms.m_lin.m_yieldStrengthOffDiag = 0i64;
  this->m_atoms.m_lin.m_ultimateStrengthDiag = (hkVector4f)xmmword_141A712A0;
  this->m_atoms.m_lin.m_ultimateStrengthOffDiag = 0i64;
  v1.m_quad = (__m128)this->m_atoms.m_ang.m_yieldStrengthDiag;
  this->m_atoms.m_ang.m_yieldStrengthDiag = (hkVector4f)xmmword_141A712A0;
  this->m_atoms.m_ang.m_yieldStrengthOffDiag = 0i64;
  this->m_atoms.m_ang.m_yieldStrengthDiag.m_quad = _mm_shuffle_ps(
                                                     (__m128)xmmword_141A712A0,
                                                     _mm_unpackhi_ps(
                                                       (__m128)xmmword_141A712A0,
                                                       _mm_shuffle_ps(v1.m_quad, v1.m_quad, 255)),
                                                     196);
  this->m_atoms.m_ang.m_ultimateStrengthDiag = (hkVector4f)xmmword_141A712A0;
  this->m_atoms.m_ang.m_ultimateStrengthOffDiag = 0i64;
}

// File Line: 27
// RVA: 0xD48230
void __fastcall hkpDeformableFixedConstraintData::setInWorldSpace(
        hkpDeformableFixedConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkTransformf *pivotA,
        hkTransformf *pivotB)
{
  __int64 v5; // r10
  hkVector4f *p_m_translation; // rax
  __int64 v8; // r11
  hkVector4f v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 m_quad; // xmm1
  hkVector4f v14; // xmm3
  hkTransformf *p_m_transformB; // rcx
  hkVector4f *v16; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  signed __int64 v20; // rcx
  hkVector4f v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  hkVector4f v26; // xmm3
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  hkVector4f v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm6
  float v35; // xmm1_4
  float v36; // xmm4_4
  int v37; // edx
  __int64 v38; // r8
  __int64 v39; // r9
  float v40; // xmm2_4
  float v41; // xmm0_4
  __m128 v42; // xmm0
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  hkQuaternionf v46; // xmm3
  __m128 v47; // [rsp+20h] [rbp-50h]
  hkMatrix3f v48; // [rsp+30h] [rbp-40h] BYREF

  v5 = 3i64;
  p_m_translation = &pivotA->m_translation;
  v8 = 3i64;
  do
  {
    v9.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
    --p_m_translation;
    --v8;
    v10 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
    v11 = _mm_movelh_ps(v10, v9.m_quad);
    v12 = _mm_movehl_ps(v11, v10);
    m_quad = p_m_translation[1].m_quad;
    *(__m128 *)((char *)&p_m_translation[1].m_quad + (char *)&this->m_atoms.m_transforms.m_transformA - (char *)pivotA) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(v12, v9.m_quad, 212)), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v11)), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), _mm_shuffle_ps(_mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad), v9.m_quad, 228)));
  }
  while ( v8 >= 0 );
  v14.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  p_m_transformB = &this->m_atoms.m_transforms.m_transformB;
  v16 = &pivotB->m_translation;
  v17 = _mm_sub_ps(pivotA->m_translation.m_quad, bodyATransform->m_translation.m_quad);
  v18 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v19 = _mm_movelh_ps(v18, v14.m_quad);
  p_m_transformB[-1].m_translation.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(v17, v17, 85),
                                                  _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v14.m_quad, 212)),
                                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v19)),
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  _mm_unpackhi_ps(
                                                    bodyATransform->m_rotation.m_col0.m_quad,
                                                    bodyATransform->m_rotation.m_col1.m_quad),
                                                  v14.m_quad,
                                                  228),
                                                _mm_shuffle_ps(v17, v17, 170)));
  v20 = (char *)p_m_transformB - (char *)pivotB;
  do
  {
    v21.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
    --v16;
    --v5;
    v22 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
    v23 = _mm_movelh_ps(v22, v21.m_quad);
    v24 = _mm_movehl_ps(v23, v22);
    v25 = v16[1].m_quad;
    *(__m128 *)((char *)&v16[1].m_quad + v20) = _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(v25, v25, 85),
                                                      _mm_shuffle_ps(v24, v21.m_quad, 212)),
                                                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v23)),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      _mm_unpackhi_ps(
                                                        bodyBTransform->m_rotation.m_col0.m_quad,
                                                        bodyBTransform->m_rotation.m_col1.m_quad),
                                                      v21.m_quad,
                                                      228),
                                                    _mm_shuffle_ps(v25, v25, 170)));
  }
  while ( v5 >= 0 );
  v26.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v27 = _mm_sub_ps(pivotB->m_translation.m_quad, bodyBTransform->m_translation.m_quad);
  v28 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v29 = _mm_movelh_ps(v28, v26.m_quad);
  this->m_atoms.m_transforms.m_transformB.m_translation.m_quad = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_mul_ps(
                                                                       _mm_shuffle_ps(v27, v27, 85),
                                                                       _mm_shuffle_ps(
                                                                         _mm_movehl_ps(v29, v28),
                                                                         v26.m_quad,
                                                                         212)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v29)),
                                                                   _mm_mul_ps(
                                                                     _mm_shuffle_ps(
                                                                       _mm_unpackhi_ps(
                                                                         bodyBTransform->m_rotation.m_col0.m_quad,
                                                                         bodyBTransform->m_rotation.m_col1.m_quad),
                                                                       v26.m_quad,
                                                                       228),
                                                                     _mm_shuffle_ps(v27, v27, 170)));
  v30.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v31 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v32 = _mm_sub_ps(pivotB->m_translation.m_quad, pivotA->m_translation.m_quad);
  v33 = _mm_movelh_ps(v31, v30.m_quad);
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(_mm_movehl_ps(v33, v31), v30.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v33)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              _mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad),
              v30.m_quad,
              228),
            _mm_shuffle_ps(v32, v32, 170)));
  hkMatrix3f::setMulInverseMul(&v48, &pivotA->m_rotation, &pivotB->m_rotation);
  v35 = (float)(v48.m_col1.m_quad.m128_f32[1] + v48.m_col0.m_quad.m128_f32[0]) + v48.m_col2.m_quad.m128_f32[2];
  if ( v35 <= 0.0 )
  {
    v37 = 0;
    v47.m128_i32[0] = 1;
    if ( v48.m_col1.m_quad.m128_f32[1] > v48.m_col0.m_quad.m128_f32[0] )
      v37 = 1;
    *(unsigned __int64 *)((char *)v47.m128_u64 + 4) = 2i64;
    if ( v48.m_col2.m_quad.m128_f32[2] > v48.m_col0.m_quad.m128_f32[5 * v37] )
      v37 = 2;
    v38 = v47.m128_i32[v37];
    v39 = v47.m128_i32[v38];
    v40 = fsqrt(
            (float)(v48.m_col0.m_quad.m128_f32[5 * v37]
                  - (float)(v48.m_col0.m_quad.m128_f32[5 * v39] + v48.m_col0.m_quad.m128_f32[5 * v38]))
          + 1.0);
    v41 = v48.m_col0.m_quad.m128_f32[4 * v38 + v39] - v48.m_col0.m_quad.m128_f32[4 * v39 + v38];
    v47.m128_f32[v37] = v40 * 0.5;
    v47.m128_f32[3] = v41 * (float)(0.5 / v40);
    v47.m128_f32[v38] = (float)(v48.m_col0.m_quad.m128_f32[4 * v37 + v38] + v48.m_col0.m_quad.m128_f32[4 * v38 + v37])
                      * (float)(0.5 / v40);
    v47.m128_f32[v39] = (float)(v48.m_col0.m_quad.m128_f32[4 * v39 + v37] + v48.m_col0.m_quad.m128_f32[4 * v37 + v39])
                      * (float)(0.5 / v40);
  }
  else
  {
    v36 = fsqrt(v35 + 1.0);
    v47.m128_f32[3] = v36 * 0.5;
    v47.m128_f32[0] = (float)(v48.m_col1.m_quad.m128_f32[2] - v48.m_col2.m_quad.m128_f32[1]) * (float)(0.5 / v36);
    v47.m128_f32[1] = (float)(v48.m_col2.m_quad.m128_f32[0] - v48.m_col0.m_quad.m128_f32[2]) * (float)(0.5 / v36);
    v47.m128_f32[2] = (float)(v48.m_col0.m_quad.m128_f32[1] - v48.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v36);
  }
  v42 = _mm_mul_ps(v47, v47);
  v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 78), v42);
  v44 = _mm_add_ps(_mm_shuffle_ps(v43, v43, 177), v43);
  v45 = _mm_rsqrt_ps(v44);
  v46.m_vec.m_quad = _mm_mul_ps(
                       v47,
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                         _mm_mul_ps(*(__m128 *)_xmm, v45)));
  this->m_atoms.m_lin.m_offset.m_quad = _mm_shuffle_ps(
                                          v34,
                                          _mm_unpackhi_ps(
                                            v34,
                                            _mm_shuffle_ps(
                                              this->m_atoms.m_lin.m_offset.m_quad,
                                              this->m_atoms.m_lin.m_offset.m_quad,
                                              255)),
                                          196);
  this->m_atoms.m_ang.m_offset = (hkQuaternionf)v46.m_vec.m_quad;
}

// File Line: 45
// RVA: 0xD481D0
void __fastcall hkpDeformableFixedConstraintData::setInBodySpace(
        hkpDeformableFixedConstraintData *this,
        hkTransformf *pivotA,
        hkTransformf *pivotB)
{
  this->m_atoms.m_transforms.m_transformA = *pivotA;
  this->m_atoms.m_transforms.m_transformB = *pivotB;
}

// File Line: 51
// RVA: 0xD48660
void __fastcall hkpDeformableFixedConstraintData::getConstraintInfo(
        hkpDeformableFixedConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0x150u, infoOut);
}

// File Line: 56
// RVA: 0xD48680
void __fastcall hkpDeformableFixedConstraintData::getRuntimeInfo(
        hkpDeformableFixedConstraintData *this,
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

// File Line: 70
// RVA: 0xD48650
hkBool *__fastcall hkpDeformableFixedConstraintData::isValid(hkpDeformableFixedConstraintData *this, hkBool *result)
{
  result->m_bool = 1;
  return result;
}

// File Line: 75
// RVA: 0xD48640
__int64 __fastcall hkpDeformableFixedConstraintData::getType(hkpDeformableFixedConstraintData *this)
{
  return 24i64;
}

