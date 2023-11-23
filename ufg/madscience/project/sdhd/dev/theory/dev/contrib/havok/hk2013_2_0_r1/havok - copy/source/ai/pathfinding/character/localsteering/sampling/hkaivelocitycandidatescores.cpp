// File Line: 13
// RVA: 0xC29FF0
void __fastcall hkaiVelocityCandidateScores::setAll(hkaiVelocityCandidateScores *this, hkSimdFloat32 *initScore)
{
  hkSimdFloat32 *m_elements; // rsi
  int v3; // eax

  m_elements = (hkSimdFloat32 *)this->m_scores.m_elements;
  v3 = (this->m_scores.m_size + 3) >> 2;
  if ( v3 > 0 )
  {
    *m_elements = (hkSimdFloat32)initScore->m_real;
    qmemcpy(&m_elements[1], m_elements, 8 * ((unsigned __int64)(16i64 * v3 - 9) >> 3));
  }
}

// File Line: 23
// RVA: 0xC2A030
void __fastcall hkaiVelocityCandidateScores::setOne(hkaiVelocityCandidateScores *this, int scoreIndex, float score)
{
  this->m_scores.m_elements->m_quad.m128_f32[scoreIndex] = score;
}

// File Line: 28
// RVA: 0xC2A050
float __fastcall hkaiVelocityCandidateScores::getOne(hkaiVelocityCandidateScores *this, int scoreIndex)
{
  return this->m_scores.m_elements->m_quad.m128_f32[scoreIndex];
}

// File Line: 34
// RVA: 0xC2A070
__int64 __fastcall hkaiVelocityCandidateScores::prefixEqual(
        hkaiVelocityCandidateScores *this,
        hkaiVelocityCandidateScores *other,
        int numToCheck)
{
  hkVector4f *m_elements; // r9
  __int64 v4; // rcx
  int v5; // eax
  __m128 v6; // xmm1
  __int64 v7; // r8

  m_elements = this->m_scores.m_elements;
  v4 = 0i64;
  v5 = numToCheck / 4;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v7 = numToCheck / 4;
  if ( v5 <= 0 )
    return 1i64;
  while ( _mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(m_elements->m_quad, m_elements->m_quad), 1u),
                        1u),
              v6)) == 15 )
  {
    ++v4;
    ++m_elements;
    if ( v4 >= v7 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 54
// RVA: 0xC2A0F0
_BOOL8 __fastcall hkaiVelocityCandidateScores::allEqual(
        hkaiVelocityCandidateScores *this,
        hkaiVelocityCandidateScores *other)
{
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  return hkVectorNf::equals(&this->m_scores, &result, &other->m_scores, 0.0000099999997)->m_bool != 0;
}

