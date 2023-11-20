// File Line: 14
// RVA: 0xD45D80
void __fastcall hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData(hkpBallAndSocketConstraintData *this)
{
  hkpBallAndSocketConstraintData *v1; // rbx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallAndSocketConstraintData::`vftable';
  hkpBallAndSocketConstraintData::Atoms::Atoms(&this->m_atoms);
  v1->m_atoms.m_pivots.m_translationA = 0i64;
  v1->m_atoms.m_pivots.m_translationB = 0i64;
}

// File Line: 22
// RVA: 0xD45DF0
void __fastcall hkpBallAndSocketConstraintData::setInWorldSpace(hkpBallAndSocketConstraintData *this, hkTransformf *bodyATransform, hkTransformf *bodyBTransform, hkVector4f *pivot)
{
  hkVector4f v4; // xmm3
  __m128 v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm2

  v4.m_quad = (__m128)bodyATransform->m_rotation.m_col2;
  v5 = _mm_sub_ps(pivot->m_quad, bodyATransform->m_translation.m_quad);
  v6 = _mm_unpacklo_ps(bodyATransform->m_rotation.m_col0.m_quad, bodyATransform->m_rotation.m_col1.m_quad);
  v7 = _mm_movelh_ps(v6, v4.m_quad);
  this->m_atoms.m_pivots.m_translationA.m_quad = _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v5, v5, 85),
                                                       _mm_shuffle_ps(_mm_movehl_ps(v7, v6), v4.m_quad, 212)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v7)),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       _mm_unpackhi_ps(
                                                         bodyATransform->m_rotation.m_col0.m_quad,
                                                         bodyATransform->m_rotation.m_col1.m_quad),
                                                       v4.m_quad,
                                                       228),
                                                     _mm_shuffle_ps(v5, v5, 170)));
  v8.m_quad = (__m128)bodyBTransform->m_rotation.m_col2;
  v9 = _mm_unpacklo_ps(bodyBTransform->m_rotation.m_col0.m_quad, bodyBTransform->m_rotation.m_col1.m_quad);
  v10 = _mm_sub_ps(pivot->m_quad, bodyBTransform->m_translation.m_quad);
  v11 = _mm_movelh_ps(v9, v8.m_quad);
  this->m_atoms.m_pivots.m_translationB.m_quad = _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v10, v10, 85),
                                                       _mm_shuffle_ps(_mm_movehl_ps(v11, v9), v8.m_quad, 212)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v11)),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       _mm_unpackhi_ps(
                                                         bodyBTransform->m_rotation.m_col0.m_quad,
                                                         bodyBTransform->m_rotation.m_col1.m_quad),
                                                       v8.m_quad,
                                                       228),
                                                     _mm_shuffle_ps(v10, v10, 170)));
}

// File Line: 29
// RVA: 0xD45DD0
void __fastcall hkpBallAndSocketConstraintData::setInBodySpace(hkpBallAndSocketConstraintData *this, hkVector4f *pivotA, hkVector4f *pivotB)
{
  this->m_atoms.m_pivots.m_translationA = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_pivots.m_translationB = (hkVector4f)pivotB->m_quad;
}

// File Line: 35
// RVA: 0xD45F00
void __fastcall hkpBallAndSocketConstraintData::setBreachImpulse(hkpBallAndSocketConstraintData *this, float breachImpulse)
{
  this->m_atoms.m_ballSocket.m_breachImpulse = breachImpulse;
}

// File Line: 40
// RVA: 0xD45F10
float __fastcall hkpBallAndSocketConstraintData::getBreachImpulse(hkpBallAndSocketConstraintData *this)
{
  return this->m_atoms.m_ballSocket.m_breachImpulse;
}

// File Line: 45
// RVA: 0xD45F20
void __fastcall hkpBallAndSocketConstraintData::setMaximumLinearImpulse(hkpBallAndSocketConstraintData *this, float maxLinearImpulse)
{
  this->m_atoms.m_setupStabilization.m_maxLinImpulse = maxLinearImpulse;
  this->m_atoms.m_ballSocket.m_enableLinearImpulseLimit.m_bool = maxLinearImpulse < 3.40282e38;
}

// File Line: 52
// RVA: 0xD45F40
float __fastcall hkpBallAndSocketConstraintData::getMaximumLinearImpulse(hkpBallAndSocketConstraintData *this)
{
  return this->m_atoms.m_setupStabilization.m_maxLinImpulse;
}

// File Line: 57
// RVA: 0xD45F50
void __fastcall hkpBallAndSocketConstraintData::setBodyToNotify(hkpBallAndSocketConstraintData *this, int bodyIdx)
{
  this->m_atoms.m_ballSocket.m_bodiesToNotify = 1 << bodyIdx;
}

// File Line: 65
// RVA: 0xD45F70
__int64 __fastcall hkpBallAndSocketConstraintData::getNotifiedBodyIndex(hkpBallAndSocketConstraintData *this)
{
  return (unsigned int)(unsigned __int8)this->m_atoms.m_ballSocket.m_bodiesToNotify >> 1;
}

// File Line: 72
// RVA: 0xD45EE0
void __fastcall hkpBallAndSocketConstraintData::getConstraintInfo(hkpBallAndSocketConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_pivots.m_type, 80, infoOut);
}

// File Line: 77
// RVA: 0xD46010
void __fastcall hkpBallAndSocketConstraintData::getRuntimeInfo(hkpBallAndSocketConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool || 3.40282e38 != this->m_atoms.m_ballSocket.m_breachImpulse )
  {
    infoOut->m_numSolverResults = 3;
    infoOut->m_sizeOfExternalRuntime = 24;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 92
// RVA: 0xD45EC0
hkBool *__fastcall hkpBallAndSocketConstraintData::isValid(hkpBallAndSocketConstraintData *this, hkBool *result)
{
  hkBool *v2; // rax

  if ( this->m_atoms.m_ballSocket.m_solvingMethod.m_storage || this->m_atoms.m_setupStabilization.m_enabled.m_bool )
  {
    result->m_bool = 1;
    v2 = result;
  }
  else
  {
    result->m_bool = 0;
    v2 = result;
  }
  return v2;
}

// File Line: 105
// RVA: 0xD45EB0
__int64 __fastcall hkpBallAndSocketConstraintData::getType(hkpBallAndSocketConstraintData *this)
{
  return 0i64;
}

// File Line: 113
// RVA: 0xD45F80
void __fastcall hkpBallAndSocketConstraintData::setSolvingMethod(hkpBallAndSocketConstraintData *this, hkpConstraintAtom::SolvingMethod method)
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

// File Line: 142
// RVA: 0xD45FA0
hkResult *__fastcall hkpBallAndSocketConstraintData::getInertiaStabilizationFactor(hkpBallAndSocketConstraintData *this, hkResult *result, float *inertiaStabilizationFactorOut)
{
  float v3; // eax

  v3 = this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor;
  result->m_enum = 0;
  *inertiaStabilizationFactorOut = v3;
  return result;
}

// File Line: 151
// RVA: 0xD45FC0
hkResult *__fastcall hkpBallAndSocketConstraintData::setInertiaStabilizationFactor(hkpBallAndSocketConstraintData *this, hkResult *result, const float inertiaStabilizationFactorIn)
{
  hkResult *v3; // rax

  result->m_enum = 0;
  v3 = result;
  this->m_atoms.m_ballSocket.m_inertiaStabilizationFactor = fminf(fmaxf(inertiaStabilizationFactorIn, 0.0), 1.0);
  return v3;
}

