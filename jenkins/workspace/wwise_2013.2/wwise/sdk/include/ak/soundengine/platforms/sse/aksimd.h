// File Line: 209
// RVA: 0xAE8250
void __fastcall AKSIMD_HORIZONTALADD_1(__m128 *vVec)
{
  __m128 v1; // xmm1

  v1 = _mm_add_ps(_mm_movehl_ps(*vVec, *vVec), *vVec);
  *vVec = _mm_add_ps(_mm_shuffle_ps(v1, v1, 85), v1);
}

// File Line: 217
// RVA: 0xAE8270
__m128 __fastcall AKSIMD_DOTPRODUCT(__m128 *result, __m128 *vVec, __m128 *vfSigns)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm0
  __m128 v5; // xmm0

  v3 = _mm_mul_ps(*result, *vVec);
  v4 = _mm_add_ps(v3, _mm_movehl_ps(v3, v3));
  v5 = _mm_add_ps(v4, _mm_shuffle_ps(v4, v4, 85));
  return _mm_shuffle_ps(v5, v5, 0);
}

// File Line: 225
// RVA: 0xB19FA0
__m128 __fastcall AKSIMD_COMPLEXMUL_2(__m128 *result, __m128 *vCIn1, __m128 *vCIn2)
{
  return _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(*result, *result, 245), _xmm), _mm_shuffle_ps(*vCIn1, *vCIn1, 177)),
           _mm_mul_ps(_mm_shuffle_ps(*result, *result, 160), *vCIn1));
}

// File Line: 242
// RVA: 0xB18100
__m128 __fastcall AKSIMD_COMPLEXMUL_SSE3(__m128 *result, __m128 *vCIn1, __m128 *vCIn2)
{
  return _mm_addsub_ps(
           _mm_mul_ps(_mm_moveldup_ps(*result), *vCIn1),
           _mm_mul_ps(_mm_shuffle_ps(*vCIn1, *vCIn1, 177), _mm_movehdup_ps(*result)));
}

// File Line: 297
// RVA: 0xAF0650
__m128 __fastcall AKSIMD_VSEL_V4F32(__m128 *result, __m128 *vA, __m128 *vB, __m128 *vMask)
{
  __m128 v4; // xmm1

  *vA = _mm_and_ps(*vA, *vB);
  v4 = _mm_andnot_ps(*vB, *result);
  *result = v4;
  return _mm_or_ps(*vA, v4);
}

