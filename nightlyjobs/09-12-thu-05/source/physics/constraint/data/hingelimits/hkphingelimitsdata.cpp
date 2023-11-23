// File Line: 18
// RVA: 0xD48DB0
void __fastcall hkpHingeLimitsData::hkpHingeLimitsData(hkpHingeLimitsData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpHingeLimitsData::`vftable;
  this->m_atoms.m_rotations.m_type.m_storage = 4;
  this->m_atoms.m_angLimit.m_type.m_storage = 14;
  this->m_atoms.m_angLimit.m_isEnabled = 1;
  this->m_atoms.m_2dAng.m_type.m_storage = 12;
  this->m_atoms.m_rotations.m_rotationA.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_2dAng.m_freeRotationAxis = 0;
  this->m_atoms.m_angLimit.m_limitAxis = 0;
  this->m_atoms.m_angLimit.m_minAngle = -3.1415927;
  this->m_atoms.m_angLimit.m_maxAngle = 3.1415927;
  this->m_atoms.m_angLimit.m_angularLimitsTauFactor = 1.0;
}

// File Line: 36
// RVA: 0xD49040
void __fastcall hkpHingeLimitsData::setInWorldSpace(
        hkpHingeLimitsData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *axis)
{
  __m128 m_quad; // xmm8
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  hkVector4f b; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f v21; // [rsp+30h] [rbp-48h] BYREF

  m_quad = axis->m_quad;
  v9 = _mm_shuffle_ps(axis->m_quad, _mm_unpackhi_ps(axis->m_quad, (__m128)0i64), 196);
  v10 = _mm_shuffle_ps(v9, v9, 241);
  v11 = _mm_shuffle_ps(v9, v9, 206);
  v12 = _mm_mul_ps(v10, v10);
  v13 = _mm_mul_ps(v11, v11);
  v14 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v15 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v14, v10), _mm_and_ps(v14, v11)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  b.m_quad = _mm_mul_ps(
               v15,
               _mm_andnot_ps(
                 _mm_cmple_ps(v17, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                   _mm_mul_ps(*(__m128 *)_xmm, v18))));
  v19 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), b.m_quad));
  v21.m_quad = _mm_shuffle_ps(v19, v19, 201);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationA.m_col0, &bodyATransform->m_rotation, axis);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationA.m_col1, &bodyATransform->m_rotation, &b);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationA.m_col2, &bodyATransform->m_rotation, &v21);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationB.m_col0, &bodyBTransform->m_rotation, axis);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationB.m_col1, &bodyBTransform->m_rotation, &b);
  hkVector4f::setRotatedInverseDir(&this->m_atoms.m_rotations.m_rotationB.m_col2, &bodyBTransform->m_rotation, &v21);
}

// File Line: 64
// RVA: 0xD48E70
void __fastcall hkpHingeLimitsData::setInBodySpace(
        hkpHingeLimitsData *this,
        hkVector4f *axisA,
        hkVector4f *axisB,
        hkVector4f *axisAPerp,
        hkVector4f *axisBPerp)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  v5 = _mm_mul_ps(axisA->m_quad, axisA->m_quad);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  this->m_atoms.m_rotations.m_rotationA.m_col0.m_quad = _mm_mul_ps(
                                                          _mm_andnot_ps(
                                                            _mm_cmple_ps(v6, (__m128)0i64),
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                                                              _mm_mul_ps(*(__m128 *)_xmm, v7))),
                                                          axisA->m_quad);
  v8 = _mm_mul_ps(axisAPerp->m_quad, axisAPerp->m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  this->m_atoms.m_rotations.m_rotationA.m_col1.m_quad = _mm_mul_ps(
                                                          _mm_andnot_ps(
                                                            _mm_cmple_ps(v9, (__m128)0i64),
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                                              _mm_mul_ps(*(__m128 *)_xmm, v10))),
                                                          axisAPerp->m_quad);
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axisAPerp->m_quad, axisAPerp->m_quad, 201), axisA->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(axisA->m_quad, axisA->m_quad, 201), axisAPerp->m_quad));
  this->m_atoms.m_rotations.m_rotationA.m_col2.m_quad = _mm_shuffle_ps(v11, v11, 201);
  v12 = _mm_mul_ps(axisB->m_quad, axisB->m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  this->m_atoms.m_rotations.m_rotationB.m_col0.m_quad = _mm_mul_ps(
                                                          _mm_andnot_ps(
                                                            _mm_cmple_ps(v13, (__m128)0i64),
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                                                              _mm_mul_ps(*(__m128 *)_xmm, v14))),
                                                          axisB->m_quad);
  v15 = _mm_mul_ps(axisBPerp->m_quad, axisBPerp->m_quad);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  this->m_atoms.m_rotations.m_rotationB.m_col1.m_quad = _mm_mul_ps(
                                                          _mm_andnot_ps(
                                                            _mm_cmple_ps(v16, (__m128)0i64),
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                                              _mm_mul_ps(*(__m128 *)_xmm, v17))),
                                                          axisBPerp->m_quad);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axisBPerp->m_quad, axisBPerp->m_quad, 201), axisB->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(axisB->m_quad, axisB->m_quad, 201), axisBPerp->m_quad));
  this->m_atoms.m_rotations.m_rotationB.m_col2.m_quad = _mm_shuffle_ps(v18, v18, 201);
}

// File Line: 85
// RVA: 0xD49270
void __fastcall hkpHingeLimitsData::getConstraintInfo(
        hkpHingeLimitsData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_rotations, 0x90u, infoOut);
}

// File Line: 90
// RVA: 0xD49290
void __fastcall hkpHingeLimitsData::getRuntimeInfo(
        hkpHingeLimitsData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 3;
  infoOut->m_sizeOfExternalRuntime = 28;
}

// File Line: 99
// RVA: 0xD49200
hkBool *__fastcall hkpHingeLimitsData::isValid(hkpHingeLimitsData *this, hkBool *result)
{
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationA, 0.0000099999997)
    && hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationB, 0.0000099999997) )
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

// File Line: 109
// RVA: 0xD491F0
__int64 __fastcall hkpHingeLimitsData::getType(hkpHingeLimitsData *this)
{
  return 18i64;
}

