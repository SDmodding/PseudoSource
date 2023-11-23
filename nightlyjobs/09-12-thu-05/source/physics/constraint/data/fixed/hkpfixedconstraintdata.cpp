// File Line: 14
// RVA: 0xD460B0
void __fastcall hkpFixedConstraintData::hkpFixedConstraintData(hkpFixedConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpFixedConstraintData::`vftable;
  hkpFixedConstraintData::Atoms::Atoms(&this->m_atoms);
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_setupStabilization.m_enabled.m_bool = 1;
  this->m_atoms.m_ballSocket.m_solvingMethod.m_storage = 0;
}

// File Line: 24
// RVA: 0xD461B0
void __fastcall hkpFixedConstraintData::setInWorldSpace(
        hkpFixedConstraintData *this,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform,
        hkTransformf *pivot)
{
  __int64 v4; // r10
  hkVector4f *p_m_translation; // rax
  __int64 v6; // rbx
  hkVector4f v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 m_quad; // xmm1
  hkVector4f v12; // xmm3
  hkVector4f *v13; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  hkTransformf *p_m_transformB; // rdx
  __m128 v18; // xmm2
  signed __int64 v19; // rcx
  hkVector4f v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  hkVector4f v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm2

  v4 = 3i64;
  p_m_translation = &pivot->m_translation;
  v6 = 3i64;
  do
  {
    v7.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
    --p_m_translation;
    --v6;
    v8 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
    v9 = _mm_movelh_ps(v8, v7.m_quad);
    v10 = _mm_movehl_ps(v9, v8);
    m_quad = p_m_translation[1].m_quad;
    *(__m128 *)((char *)&p_m_translation[1].m_quad + (char *)&this->m_atoms.m_transforms.m_transformA - (char *)pivot) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(v10, v7.m_quad, 212)), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v9)), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), _mm_shuffle_ps(_mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad), v7.m_quad, 228)));
  }
  while ( v6 >= 0 );
  v12.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v13 = &pivot->m_translation;
  v14 = _mm_sub_ps(pivot->m_translation.m_quad, bodyATransform->m_translation.m_quad);
  v15 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v16 = _mm_shuffle_ps(
          _mm_unpackhi_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad),
          v12.m_quad,
          228);
  p_m_transformB = &this->m_atoms.m_transforms.m_transformB;
  v18 = _mm_movelh_ps(v15, v12.m_quad);
  this->m_atoms.m_transforms.m_transformA.m_translation.m_quad = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_mul_ps(
                                                                       _mm_shuffle_ps(v14, v14, 85),
                                                                       _mm_shuffle_ps(
                                                                         _mm_movehl_ps(v18, v15),
                                                                         v12.m_quad,
                                                                         212)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v18)),
                                                                   _mm_mul_ps(v16, _mm_shuffle_ps(v14, v14, 170)));
  v19 = (char *)&this->m_atoms.m_transforms.m_transformB - (char *)pivot;
  do
  {
    v20.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
    --v13;
    --v4;
    v21 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
    v22 = _mm_movelh_ps(v21, v20.m_quad);
    v23 = _mm_movehl_ps(v22, v21);
    v24 = v13[1].m_quad;
    *(__m128 *)((char *)&v13[1].m_quad + v19) = _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(v24, v24, 85),
                                                      _mm_shuffle_ps(v23, v20.m_quad, 212)),
                                                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v22)),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(v24, v24, 170),
                                                    _mm_shuffle_ps(
                                                      _mm_unpackhi_ps(
                                                        bodyBTransform->m_rotation.m_col0.m_quad,
                                                        bodyBTransform->m_rotation.m_col1.m_quad),
                                                      v20.m_quad,
                                                      228)));
  }
  while ( v4 >= 0 );
  v25.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v26 = _mm_sub_ps(pivot->m_translation.m_quad, bodyBTransform->m_translation.m_quad);
  v27 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v28 = _mm_movelh_ps(v27, v25.m_quad);
  p_m_transformB->m_translation.m_quad = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v26, v26, 85),
                                               _mm_shuffle_ps(_mm_movehl_ps(v28, v27), v25.m_quad, 212)),
                                             _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v28)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(
                                               _mm_unpackhi_ps(
                                                 bodyBTransform->m_rotation.m_col0.m_quad,
                                                 bodyBTransform->m_rotation.m_col1.m_quad),
                                               v25.m_quad,
                                               228),
                                             _mm_shuffle_ps(v26, v26, 170)));
}

// File Line: 30
// RVA: 0xD46150
void __fastcall hkpFixedConstraintData::setInBodySpace(
        hkpFixedConstraintData *this,
        hkTransformf *pivotA,
        hkTransformf *pivotB)
{
  this->m_atoms.m_transforms.m_transformA = *pivotA;
  this->m_atoms.m_transforms.m_transformB = *pivotB;
}

// File Line: 36
// RVA: 0xD463D0
void __fastcall hkpFixedConstraintData::setMaximumLinearImpulse(hkpFixedConstraintData *this, float maxLinearImpulse)
{
  this->m_atoms.m_setupStabilization.m_maxLinImpulse = maxLinearImpulse;
  this->m_atoms.m_ballSocket.m_enableLinearImpulseLimit.m_bool = maxLinearImpulse < 3.40282e38;
}

// File Line: 43
// RVA: 0xD463F0
void __fastcall hkpFixedConstraintData::setMaximumAngularImpulse(hkpFixedConstraintData *this, float maxAngularImpulse)
{
  this->m_atoms.m_setupStabilization.m_maxAngImpulse = maxAngularImpulse;
}

// File Line: 48
// RVA: 0xD46400
float __fastcall hkpFixedConstraintData::getMaximumLinearImpulse(hkpFixedConstraintData *this)
{
  return this->m_atoms.m_setupStabilization.m_maxLinImpulse;
}

// File Line: 53
// RVA: 0xD46410
float __fastcall hkpFixedConstraintData::getMaximumAngularImpulse(hkpFixedConstraintData *this)
{
  return this->m_atoms.m_setupStabilization.m_maxAngImpulse;
}

// File Line: 58
// RVA: 0xD46420
void __fastcall hkpFixedConstraintData::setBodyToNotify(hkpFixedConstraintData *this, char bodyIdx)
{
  this->m_atoms.m_ballSocket.m_bodiesToNotify = 1 << bodyIdx;
}

// File Line: 64
// RVA: 0xD46440
__int64 __fastcall hkpFixedConstraintData::getNotifiedBodyIndex(hkpFixedConstraintData *this)
{
  return (unsigned __int8)this->m_atoms.m_ballSocket.m_bodiesToNotify >> 1;
}

// File Line: 71
// RVA: 0xD463B0
void __fastcall hkpFixedConstraintData::getConstraintInfo(
        hkpFixedConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_transforms, 0xC0u, infoOut);
}

// File Line: 76
// RVA: 0xD464F0
void __fastcall hkpFixedConstraintData::getRuntimeInfo(
        hkpFixedConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool || 3.40282e38 != this->m_atoms.m_ballSocket.m_breachImpulse )
  {
    infoOut->m_numSolverResults = 6;
    infoOut->m_sizeOfExternalRuntime = 48;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 90
// RVA: 0xD46380
hkBool *__fastcall hkpFixedConstraintData::isValid(hkpFixedConstraintData *this, hkBool *result)
{
  if ( this->m_atoms.m_ballSocket.m_solvingMethod.m_storage || this->m_atoms.m_setupStabilization.m_enabled.m_bool )
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

// File Line: 102
// RVA: 0xD46370
__int64 __fastcall hkpFixedConstraintData::getType(hkpFixedConstraintData *this)
{
  return 23i64;
}

// File Line: 107
// RVA: 0xD46450
void __fastcall hkpFixedConstraintData::setSolvingMethod(
        hkpFixedConstraintData *this,
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

// File Line: 133
// RVA: 0xD46480
hkResult *__fastcall hkpFixedConstraintData::getInertiaStabilizationFactor(
        hkpFixedConstraintData *this,
        hkResult *result,
        float *inertiaStabilizationFactorOut)
{
  float m_inertiaStabilizationFactor; // eax

  m_inertiaStabilizationFactor = this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor;
  result->m_enum = HK_SUCCESS;
  *inertiaStabilizationFactorOut = m_inertiaStabilizationFactor;
  return result;
}

// File Line: 139
// RVA: 0xD464A0
hkResult *__fastcall hkpFixedConstraintData::setInertiaStabilizationFactor(
        hkpFixedConstraintData *this,
        hkResult *result,
        float inertiaStabilizationFactorIn)
{
  hkResult *v3; // rax

  result->m_enum = HK_SUCCESS;
  v3 = result;
  this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor = fminf(fmaxf(inertiaStabilizationFactorIn, 0.0), 1.0);
  return v3;
}

