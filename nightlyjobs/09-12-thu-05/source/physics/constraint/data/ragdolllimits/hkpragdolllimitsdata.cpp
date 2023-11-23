// File Line: 14
// RVA: 0xD486D0
void __fastcall hkpRagdollLimitsData::hkpRagdollLimitsData(hkpRagdollLimitsData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRagdollLimitsData::`vftable;
  this->m_atoms.m_rotations.m_type.m_storage = 4;
  this->m_atoms.m_twistLimit.m_type.m_storage = 15;
  this->m_atoms.m_twistLimit.m_isEnabled = 1;
  this->m_atoms.m_coneLimit.m_type.m_storage = 16;
  this->m_atoms.m_coneLimit.m_isEnabled = 1;
  this->m_atoms.m_coneLimit.m_memOffsetToAngleOffset = 0;
  this->m_atoms.m_planesLimit.m_type.m_storage = 16;
  this->m_atoms.m_planesLimit.m_isEnabled = 1;
  this->m_atoms.m_planesLimit.m_memOffsetToAngleOffset = 0;
  this->m_atoms.m_rotations.m_rotationA.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  *(_WORD *)&this->m_atoms.m_twistLimit.m_twistAxis = 256;
  this->m_atoms.m_twistLimit.m_minAngle = -0.52359998;
  this->m_atoms.m_twistLimit.m_maxAngle = 0.52359998;
  this->m_atoms.m_twistLimit.m_angularLimitsTauFactor = 0.80000001;
  *(_WORD *)&this->m_atoms.m_coneLimit.m_twistAxisInA = 0;
  this->m_atoms.m_coneLimit.m_angleMeasurementMode.m_storage = 0;
  this->m_atoms.m_coneLimit.m_minAngle = -100.0;
  this->m_atoms.m_coneLimit.m_maxAngle = 1.0;
  this->m_atoms.m_coneLimit.m_angularLimitsTauFactor = 0.80000001;
  hkpRagdollLimitsData::setConeLimitStabilization(this, (hkBool)1);
  *(_WORD *)&this->m_atoms.m_planesLimit.m_twistAxisInA = 256;
  this->m_atoms.m_planesLimit.m_angleMeasurementMode.m_storage = 1;
  this->m_atoms.m_planesLimit.m_minAngle = -0.025;
  this->m_atoms.m_planesLimit.m_maxAngle = 0.025;
  this->m_atoms.m_planesLimit.m_angularLimitsTauFactor = 0.80000001;
}

// File Line: 49
// RVA: 0xD48820
void __fastcall hkpRagdollLimitsData::setInWorldSpace(
        hkpRagdollLimitsData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkVector4f *twistAxisW,
        hkVector4f *planeAxisW)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 m_quad; // xmm4
  __m128 *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  hkVector4f v16; // xmm2
  __m128 v17; // xmm4
  hkVector4f v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  signed __int64 v22; // rcx
  __int64 v23; // rdx
  __int64 v24; // r8
  __m128 v25; // xmm5
  __m128 v26; // xmm0
  __m128 v27; // xmm8
  __m128 v28; // xmm4
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  hkVector4f v31; // xmm2
  __m128 *v32; // rax
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38[3]; // [rsp+0h] [rbp-68h] BYREF

  v6 = _mm_mul_ps(twistAxisW->m_quad, twistAxisW->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  m_quad = planeAxisW->m_quad;
  v10 = v38;
  v38[0] = _mm_mul_ps(
             twistAxisW->m_quad,
             _mm_andnot_ps(
               _mm_cmple_ps(v7, (__m128)0i64),
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8))));
  v11 = _mm_mul_ps(m_quad, m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_cmple_ps(v12, (__m128)0i64);
  v15 = _mm_mul_ps(v13, v12);
  v16.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v17 = _mm_mul_ps(
          m_quad,
          _mm_andnot_ps(
            v14,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v13)), _mm_mul_ps(*(__m128 *)_xmm, v13))));
  v18.m_quad = (__m128)bodyATransform->m_rotation.m_col0;
  v19 = _mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v38[1] = v17;
  v20 = _mm_unpacklo_ps(v18.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v21 = _mm_shuffle_ps(v19, v16.m_quad, 228);
  v22 = (char *)this - (char *)v38;
  v23 = 3i64;
  v24 = 3i64;
  v25 = _mm_movelh_ps(v20, v16.m_quad);
  v26 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v38[0]);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v38[0], v38[0], 201), v17);
  v28 = _mm_shuffle_ps(_mm_movehl_ps(v25, v20), v16.m_quad, 212);
  v29 = _mm_sub_ps(v26, v27);
  v38[2] = _mm_shuffle_ps(v29, v29, 201);
  do
  {
    v30 = *v10++;
    *(__m128 *)((char *)v10 + v22 + 32) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v28),
                                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v25)),
                                            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v21));
    --v24;
  }
  while ( v24 );
  v31.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v32 = v38;
  v33 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v34 = _mm_shuffle_ps(
          _mm_unpackhi_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad),
          v31.m_quad,
          228);
  v35 = _mm_movelh_ps(v33, v31.m_quad);
  v36 = _mm_shuffle_ps(_mm_movehl_ps(v35, v33), v31.m_quad, 212);
  do
  {
    v37 = *v32++;
    *(__m128 *)((char *)v32 + v22 + 80) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), v36),
                                              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v35)),
                                            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), v34));
    --v23;
  }
  while ( v23 );
}                     _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), v34))

// File Line: 75
// RVA: 0xD48A00
void __fastcall hkpRagdollLimitsData::setInBodySpace(
        hkpRagdollLimitsData *this,
        hkVector4f *planeAxisA,
        hkVector4f *planeAxisB,
        hkVector4f *twistAxisA,
        hkVector4f *twistAxisB)
{
  __m128 m_quad; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  hkVector4f v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  hkVector4f v13; // xmm4
  __m128 v14; // xmm0
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  hkVector4f v21; // xmm5
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  hkVector4f v26; // xmm3
  __m128 v27; // xmm0

  m_quad = planeAxisA->m_quad;
  v6 = _mm_mul_ps(twistAxisA->m_quad, twistAxisA->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9.m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v7, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                    _mm_mul_ps(*(__m128 *)_xmm, v8))),
                twistAxisA->m_quad);
  v10 = _mm_mul_ps(m_quad, m_quad);
  this->m_atoms.m_rotations.m_rotationA.m_col0 = (hkVector4f)v9.m_quad;
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v11, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                     _mm_mul_ps(*(__m128 *)_xmm, v12))),
                 m_quad);
  this->m_atoms.m_rotations.m_rotationA.m_col1 = (hkVector4f)v13.m_quad;
  v14 = _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v9.m_quad);
  v15 = _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 201), v13.m_quad);
  v16 = twistAxisB->m_quad;
  v17 = _mm_sub_ps(v14, v15);
  v18 = _mm_mul_ps(v16, v16);
  this->m_atoms.m_rotations.m_rotationA.m_col2.m_quad = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v19, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                     _mm_mul_ps(*(__m128 *)_xmm, v20))),
                 v16);
  v22 = planeAxisB->m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col0 = (hkVector4f)v21.m_quad;
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v26.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v24, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                     _mm_mul_ps(*(__m128 *)_xmm, v25))),
                 v22);
  this->m_atoms.m_rotations.m_rotationB.m_col1 = (hkVector4f)v26.m_quad;
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v26.m_quad, v26.m_quad, 201), v21.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 201), v26.m_quad));
  this->m_atoms.m_rotations.m_rotationB.m_col2.m_quad = _mm_shuffle_ps(v27, v27, 201);
}

// File Line: 92
// RVA: 0xD48D50
void __fastcall hkpRagdollLimitsData::getConstraintInfo(
        hkpRagdollLimitsData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_rotations, 0xD0u, infoOut);
}

// File Line: 97
// RVA: 0xD48D70
void __fastcall hkpRagdollLimitsData::getRuntimeInfo(
        hkpRagdollLimitsData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 3;
  infoOut->m_sizeOfExternalRuntime = 28;
}

// File Line: 107
// RVA: 0xD48C50
hkBool *__fastcall hkpRagdollLimitsData::isValid(hkpRagdollLimitsData *this, hkBool *result)
{
  char isOrthonormal; // al
  bool v5; // al
  bool v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // al

  result->m_bool = 1;
  isOrthonormal = hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationA, 0.0000099999997);
  result->m_bool = isOrthonormal;
  v5 = isOrthonormal && hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationB, 0.0000099999997);
  result->m_bool = v5;
  v6 = v5 && -100.0 == this->m_atoms.m_coneLimit.m_minAngle;
  result->m_bool = v6;
  v7 = v6 && this->m_atoms.m_coneLimit.m_maxAngle >= 0.0;
  result->m_bool = v7;
  v8 = v7 && this->m_atoms.m_coneLimit.m_maxAngle < 3.1415927;
  result->m_bool = v8;
  v9 = v8 && this->m_atoms.m_planesLimit.m_maxAngle >= this->m_atoms.m_planesLimit.m_minAngle;
  result->m_bool = v9;
  if ( v9 && this->m_atoms.m_twistLimit.m_maxAngle >= this->m_atoms.m_twistLimit.m_minAngle )
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

// File Line: 126
// RVA: 0xD48C20
void __fastcall hkpRagdollLimitsData::setConeLimitStabilization(hkpRagdollLimitsData *this, hkBool enable)
{
  this->m_atoms.m_coneLimit.m_memOffsetToAngleOffset = 16 * (enable.m_bool != 0);
}

// File Line: 135
// RVA: 0xD48BD0
void __fastcall hkpRagdollLimitsData::getConstraintFrameA(hkpRagdollLimitsData *this, hkRotationf *constraintFrameA)
{
  *constraintFrameA = this->m_atoms.m_rotations.m_rotationA;
}

// File Line: 142
// RVA: 0xD48BF0
void __fastcall hkpRagdollLimitsData::getConstraintFrameB(hkpRagdollLimitsData *this, hkRotationf *constraintFrameB)
{
  *constraintFrameB = this->m_atoms.m_rotations.m_rotationB;
}

// File Line: 149
// RVA: 0xD48C40
__int64 __fastcall hkpRagdollLimitsData::getType(hkpRagdollLimitsData *this)
{
  return 19i64;
}

