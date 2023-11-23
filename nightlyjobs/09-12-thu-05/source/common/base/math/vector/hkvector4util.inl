// File Line: 1928
// RVA: 0xD16B50
void __fastcall hkVector4UtilImpl<float>::getFloatToInt16FloorCorrection(float *out)
{
  __m128i v1; // xmm0
  float v2; // xmm4_4
  __int128 v3; // xmm2
  __int64 v4; // rax
  __m128i si128; // xmm10
  __m128i v6; // xmm11
  __int128 v7; // xmm3
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  __m128i v10; // xmm1

  v2 = FLOAT_10_0;
  v3 = LODWORD(FLOAT_11_0);
  v4 = 23i64;
  si128 = _mm_load_si128((const __m128i *)&_xmm);
  v6 = _mm_load_si128((const __m128i *)&`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
  do
  {
    v7 = v3;
    *(float *)&v7 = (float)(*(float *)&v3 + v2) * 0.5;
    v1.m128i_i32[0] = v7;
    v8 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps((__m128)v1, (__m128)v1, 0), aabbOut.m_quad), query.m_quad);
    v9 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8);
    v1 = _mm_cvttps_epi32(v8);
    v10 = _mm_sub_epi32(_mm_xor_si128(v9, v1), si128);
    if ( _mm_add_epi16(_mm_packs_epi32(v10, v10), v6).m128i_u16[0] >= 0xBu )
      v3 = v7;
    else
      v2 = (float)(*(float *)&v3 + v2) * 0.5;
    --v4;
  }
  while ( v4 );
  *out = (float)((float)(*(float *)&v3 + v2) * 0.5) - 11.0;
}

// File Line: 1989
// RVA: 0xD3AAF0
__int64 __fastcall hkVector4UtilImpl<float>::packQuaternionIntoInt32(hkVector4f *qin)
{
  __m128 v1; // xmm1
  __m128i v2; // xmm2

  v1 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_116_36363), (__m128)LODWORD(FLOAT_116_36363), 0), qin->m_quad),
         (__m128)xmmword_141A711B0);
  v2 = _mm_and_si128(
         _mm_add_epi32(
           _mm_xor_si128(
             (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v1),
             _mm_cvttps_epi32(v1)),
           (__m128i)_xmm),
         (__m128i)_xmm);
  return _mm_cvtsi128_si32(v2) | ((_mm_cvtsi128_si32(_mm_srli_si128(v2, 4)) | ((_mm_cvtsi128_si32(_mm_srli_si128(v2, 8)) | (unsigned int)(_mm_cvtsi128_si32(_mm_srli_si128(v2, 12)) << 8)) << 8)) << 8);
}

