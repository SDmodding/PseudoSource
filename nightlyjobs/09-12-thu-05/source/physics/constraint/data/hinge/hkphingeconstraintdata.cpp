// File Line: 16
// RVA: 0xD465F0
void __fastcall hkpHingeConstraintData::hkpHingeConstraintData(hkpHingeConstraintData *this)
{
  hkpHingeConstraintData *v1; // rbx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpHingeConstraintData::`vftable;
  hkpHingeConstraintData::Atoms::Atoms(&this->m_atoms);
  v1->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  v1->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  v1->m_atoms.m_2dAng.m_freeRotationAxis = 0;
}

// File Line: 29
// RVA: 0xD46950
void __fastcall hkpHingeConstraintData::setInWorldSpace(hkpHingeConstraintData *this, hkTransformf *bodyATransform, hkTransformf *bodyBTransform, hkVector4f *pivot, hkVector4f *axis)
{
  hkTransformf *v5; // r14
  hkpHingeConstraintData *v6; // rsi
  hkVector4f *v7; // rbp
  hkTransformf *v8; // rbx
  __m128 v9; // xmm9
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm7
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  hkVector4f b; // [rsp+20h] [rbp-68h]
  hkVector4f v22; // [rsp+30h] [rbp-58h]

  v5 = bodyBTransform;
  v6 = this;
  v7 = pivot;
  v8 = bodyATransform;
  v9 = axis->m_quad;
  v10 = _mm_shuffle_ps(axis->m_quad, _mm_unpackhi_ps(axis->m_quad, (__m128)0i64), 196);
  v11 = _mm_shuffle_ps(v10, v10, 241);
  v12 = _mm_shuffle_ps(v10, v10, 206);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_mul_ps(v11, v11);
  v15 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v16 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v15, v11), _mm_and_ps(v15, v12)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  b.m_quad = _mm_mul_ps(
               v16,
               _mm_andnot_ps(
                 _mm_cmpleps(v18, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                   _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 201), v9),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), b.m_quad));
  v22.m_quad = _mm_shuffle_ps(v20, v20, 201);
  hkVector4f::setRotatedInverseDir(
    &this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0,
    (hkMatrix3f *)&bodyATransform->m_rotation.m_col0,
    axis);
  hkVector4f::setRotatedInverseDir(
    &v6->m_atoms.m_transforms.m_transformA.m_rotation.m_col1,
    (hkMatrix3f *)&v8->m_rotation.m_col0,
    &b);
  hkVector4f::setRotatedInverseDir(
    &v6->m_atoms.m_transforms.m_transformA.m_rotation.m_col2,
    (hkMatrix3f *)&v8->m_rotation.m_col0,
    &v22);
  hkVector4f::setTransformedInversePos(&v6->m_atoms.m_transforms.m_transformA.m_translation, v8, v7);
  hkVector4f::setRotatedInverseDir(
    &v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0,
    (hkMatrix3f *)&v5->m_rotation.m_col0,
    axis);
  hkVector4f::setRotatedInverseDir(
    &v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col1,
    (hkMatrix3f *)&v5->m_rotation.m_col0,
    &b);
  hkVector4f::setRotatedInverseDir(
    &v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col2,
    (hkMatrix3f *)&v5->m_rotation.m_col0,
    &v22);
  hkVector4f::setTransformedInversePos(&v6->m_atoms.m_transforms.m_transformB.m_translation, v5, v7);
}

// File Line: 51
// RVA: 0xD46690
void __fastcall hkpHingeConstraintData::setInBodySpace(hkpHingeConstraintData *this, hkVector4f *pivotA, hkVector4f *pivotB, hkVector4f *axisA, hkVector4f *axisB)
{
  __m128 v5; // xmm7
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  hkVector4f v9; // xmm6
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  hkVector4f v26; // xmm6
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm3
  __m128 v39; // xmm1

  v5 = (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  v6 = _mm_mul_ps(axisA->m_quad, axisA->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9.m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v7, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                    _mm_mul_ps(v8, *(__m128 *)_xmm))),
                axisA->m_quad);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)v9.m_quad;
  v10 = _mm_shuffle_ps(v9.m_quad, _mm_unpackhi_ps(v9.m_quad, (__m128)0i64), 196);
  v11 = _mm_shuffle_ps(v10, v10, 241);
  v12 = _mm_shuffle_ps(v10, v10, 206);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_mul_ps(v11, v11);
  v15 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v16 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v12, v15), _mm_andnot_ps(v15, v11)), v5);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20.m_quad = (__m128)this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0;
  v21.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v18, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                     _mm_mul_ps(v19, *(__m128 *)_xmm))),
                 v16);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)v21.m_quad;
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 201), v20.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 201), v21.m_quad));
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v22, v22, 201);
  v23 = _mm_mul_ps(axisB->m_quad, axisB->m_quad);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v26.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v24, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                     _mm_mul_ps(v25, *(__m128 *)_xmm))),
                 axisB->m_quad);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)v26.m_quad;
  v27 = _mm_shuffle_ps(v26.m_quad, _mm_unpackhi_ps(v26.m_quad, (__m128)0i64), 196);
  v28 = _mm_shuffle_ps(v27, v27, 241);
  v29 = _mm_shuffle_ps(v27, v27, 206);
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_mul_ps(v28, v28);
  v32 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170)));
  v33 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v32, v28), _mm_and_ps(v29, v32)), v5);
  v34 = _mm_mul_ps(v33, v33);
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v36 = _mm_rsqrt_ps(v35);
  v37.m_quad = (__m128)this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0;
  v38.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v35, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                     _mm_mul_ps(v36, *(__m128 *)_xmm))),
                 v33);
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)v38.m_quad;
  v39 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v38.m_quad, v38.m_quad, 201), v37.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v37.m_quad, v37.m_quad, 201), v38.m_quad));
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v39, v39, 201);
}

// File Line: 69
// RVA: 0xD46C10
void __fastcall hkpHingeConstraintData::setBreachImpulse(hkpHingeConstraintData *this, float breachImpulse)
{
  this->m_atoms.m_ballSocket.m_breachImpulse = breachImpulse;
}

// File Line: 74
// RVA: 0xD46C20
float __fastcall hkpHingeConstraintData::getBreachImpulse(hkpHingeConstraintData *this)
{
  return this->m_atoms.m_ballSocket.m_breachImpulse;
}

// File Line: 79
// RVA: 0xD46C30
void __fastcall hkpHingeConstraintData::setBodyToNotify(hkpHingeConstraintData *this, int bodyIdx)
{
  this->m_atoms.m_ballSocket.m_bodiesToNotify = 1 << bodyIdx;
}

// File Line: 87
// RVA: 0xD46C50
__int64 __fastcall hkpHingeConstraintData::getNotifiedBodyIndex(hkpHingeConstraintData *this)
{
  return (unsigned int)(unsigned __int8)this->m_atoms.m_ballSocket.m_bodiesToNotify >> 1;
}

// File Line: 94
// RVA: 0xD46D00
void __fastcall hkpHingeConstraintData::getRuntimeInfo(hkpHingeConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool )
  {
    infoOut->m_numSolverResults = 5;
    infoOut->m_sizeOfExternalRuntime = 40;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 108
// RVA: 0xD46BF0
void __fastcall hkpHingeConstraintData::getConstraintInfo(hkpHingeConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_transforms.m_type, 192, infoOut);
}

// File Line: 115
// RVA: 0xD46B60
hkBool *__fastcall hkpHingeConstraintData::isValid(hkpHingeConstraintData *this, hkBool *result)
{
  hkBool *v2; // rbx
  hkpHingeConstraintData *v3; // rdi
  hkBool *v4; // rax

  v2 = result;
  v3 = this;
  if ( this->m_atoms.m_ballSocket.m_solvingMethod.m_storage || this->m_atoms.m_setupStabilization.m_enabled.m_bool )
  {
    if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
      && hkRotationf::isOrthonormal(&v3->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997) )
    {
      v2->m_bool = 1;
      v4 = v2;
    }
    else
    {
      v2->m_bool = 0;
      v4 = v2;
    }
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 128
// RVA: 0xD46B50
signed __int64 __fastcall hkpHingeConstraintData::getType(hkpHingeConstraintData *this)
{
  return 1i64;
}

// File Line: 136
// RVA: 0xD46C60
void __fastcall hkpHingeConstraintData::setSolvingMethod(hkpHingeConstraintData *this, hkpConstraintAtom::SolvingMethod method)
{
  if ( method )
  {
    if ( method == 1 )
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

// File Line: 165
// RVA: 0xD46C90
hkResult *__fastcall hkpHingeConstraintData::getInertiaStabilizationFactor(hkpHingeConstraintData *this, hkResult *result, float *inertiaStabilizationFactorOut)
{
  float v3; // eax

  v3 = this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor;
  result->m_enum = 0;
  *inertiaStabilizationFactorOut = v3;
  return result;
}

// File Line: 174
// RVA: 0xD46CB0
hkResult *__fastcall hkpHingeConstraintData::setInertiaStabilizationFactor(hkpHingeConstraintData *this, hkResult *result, const float inertiaStabilizationFactorIn)
{
  hkResult *v3; // rax

  result->m_enum = 0;
  v3 = result;
  this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor = fminf(fmaxf(inertiaStabilizationFactorIn, 0.0), 1.0);
  return v3;
}

