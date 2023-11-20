// File Line: 12
// RVA: 0xC69C80
void __fastcall hkPackedVector3::pack(hkPackedVector3 *this, hkVector4f *vIn)
{
  __m128i v2; // xmm3
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128i v5; // xmm2
  __m128 v6; // xmm0
  __m128i v7; // xmm1

  v2 = (__m128i)_mm_shuffle_ps(vIn->m_quad, _mm_unpackhi_ps(vIn->m_quad, (__m128)xmmword_141A712D0), 196);
  v3 = (__m128)_mm_and_si128((__m128i)_mm_mul_ps(*(__m128 *)rounding, (__m128)v2), *(__m128i *)mask_2);
  v4 = _mm_max_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  v5 = _mm_sub_epi32(_mm_load_si128((const __m128i *)offset), (__m128i)_mm_max_ps(v4, _mm_shuffle_ps(v4, v4, 177)));
  v6 = (__m128)_mm_add_epi32(v5, v2);
  v7 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
           _mm_cvttps_epi32(v6)),
         *(__m128i *)roundingCorrection);
  this->m_values[0] = _mm_extract_epi16(v7, 1);
  this->m_values[1] = _mm_extract_epi16(v7, 3);
  this->m_values[2] = _mm_extract_epi16(v7, 5);
  this->m_values[3] = 16256 - _mm_extract_epi16(v5, 1);
}

// File Line: 84
// RVA: 0xC69D20
void __fastcall hkPackedVector3::pack(hkPackedVector3 *this, hkVector4d *vIn)
{
  double v2; // xmm2_8
  double v3; // xmm3_8
  double v4; // xmm4_8
  __m128i v5; // xmm1
  __m128 v6; // xmm0
  __m128i v7; // xmm2
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  __m128i v10; // [rsp+0h] [rbp-28h]
  __m128i v11; // [rsp+10h] [rbp-18h]

  v2 = vIn->m_quad.xy.m128d_f64[0];
  v3 = vIn->m_quad.xy.m128d_f64[1];
  v4 = vIn->m_quad.zw.m128d_f64[0];
  *(float *)&v11.m128i_i32[3] = FLOAT_1_4210855eN14;
  *(float *)v11.m128i_i32 = v2;
  *(float *)&v11.m128i_i32[1] = v3;
  *(float *)v10.m128i_i32 = *(float *)v11.m128i_i32 * 1.0000153;
  *(float *)&v10.m128i_i32[3] = FLOAT_1_4211072eN14;
  *(float *)&v10.m128i_i32[1] = *(float *)&v11.m128i_i32[1] * 1.0000153;
  *(float *)&v11.m128i_i32[2] = v4;
  *(float *)&v10.m128i_i32[2] = *(float *)&v11.m128i_i32[2] * 1.0000153;
  v5 = _mm_and_si128(_mm_load_si128(&v10), *(__m128i *)mask_2);
  _mm_store_si128(&v10, v5);
  v6 = _mm_shuffle_ps((__m128)v5, (__m128)v5, 85);
  if ( v6.m128_f32[0] <= *(float *)v5.m128i_i32 )
    v6 = (__m128)v5;
  if ( *(float *)&v10.m128i_i32[2] > v6.m128_f32[0] )
    v6 = (__m128)v10.m128i_u32[2];
  if ( *(float *)&v10.m128i_i32[3] > v6.m128_f32[0] )
    v6 = (__m128)v10.m128i_u32[3];
  v10 = (__m128i)_mm_shuffle_ps(v6, v6, 0);
  v7 = _mm_sub_epi32(_mm_load_si128((const __m128i *)offset), v10);
  v8 = (__m128)_mm_add_epi32(_mm_load_si128(&v11), v7);
  v9 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v8),
           _mm_cvttps_epi32(v8)),
         *(__m128i *)roundingCorrection);
  this->m_values[0] = _mm_extract_epi16(v9, 1);
  this->m_values[1] = _mm_extract_epi16(v9, 3);
  this->m_values[2] = _mm_extract_epi16(v9, 5);
  this->m_values[3] = 16256 - _mm_extract_epi16(v7, 1);
}

// File Line: 181
// RVA: 0xC69E40
void __fastcall hkPackedVector8_3::pack(hkPackedVector8_3 *this, hkVector4f *vIn)
{
  __m128i v2; // xmm3
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128i v5; // xmm2
  __m128 v6; // xmm0
  __m128i v7; // xmm1

  v2 = (__m128i)_mm_shuffle_ps(vIn->m_quad, _mm_unpackhi_ps(vIn->m_quad, (__m128)xmmword_141A712D0), 196);
  v3 = (__m128)_mm_and_si128((__m128i)_mm_mul_ps((__m128)v2, *(__m128 *)rounding_0), *(__m128i *)mask_2);
  v4 = _mm_max_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  v5 = _mm_sub_epi32(_mm_load_si128((const __m128i *)offset), (__m128i)_mm_max_ps(v4, _mm_shuffle_ps(v4, v4, 177)));
  v6 = (__m128)_mm_add_epi32(v5, v2);
  v7 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
           _mm_cvttps_epi32(v6)),
         *(__m128i *)roundingCorrection_0);
  this->m_values[0] = _mm_cvtsi128_si32(_mm_srli_si128(v7, 3));
  this->m_values[1] = _mm_cvtsi128_si32(_mm_srli_si128(v7, 7));
  this->m_values[2] = _mm_cvtsi128_si32(_mm_srli_si128(v7, 11));
  this->m_values[3] = (16256 - _mm_extract_epi16(v5, 1)) >> 7;
}

// File Line: 255
// RVA: 0xC69EF0
void __fastcall hkPackedVector8_3::pack(hkPackedVector8_3 *this, hkVector4d *vIn)
{
  unsigned __int64 v2; // rbp
  __m128 v3; // xmm3
  __m128 v4; // xmm0
  __m128i v5; // xmm3
  float v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  unsigned int v12; // er8
  float v13; // xmm1_4
  __m128i v14; // xmm3
  int v15; // [rsp+20h] [rbp+0h]

  v2 = (unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64;
  v3 = _mm_cvtpd_ps(vIn->m_quad.xy);
  v4 = _mm_cvtpd_ps(vIn->m_quad.zw);
  *(_DWORD *)v2 = 1065385984;
  v5 = (__m128i)_mm_movelh_ps(v3, v4);
  v6 = *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64);
  v7 = COERCE_FLOAT(_mm_shuffle_ps((__m128)v5, (__m128)v5, 85))
     * *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64);
  *(float *)(v2 + 32) = *(float *)v5.m128i_i32 * *(float *)v2;
  *(_DWORD *)(v2 + 32) &= 0x7F800000u;
  *(float *)(v2 + 36) = v7;
  v8 = *(_DWORD *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  *(_DWORD *)(v2 + 36) &= 0x7F800000u;
  v4.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps((__m128)v5, (__m128)v5, 170)) * v6;
  *(_DWORD *)v2 = v8;
  v9 = *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64);
  *(_DWORD *)(v2 + 40) = v4.m128_i32[0];
  v4.m128_i32[0] = *(_DWORD *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 0x24);
  *(_DWORD *)(v2 + 40) &= 0x7F800000u;
  *(_DWORD *)(v2 + 8) = v4.m128_i32[0];
  v10 = fmaxf(v9, *(float *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 8));
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 40);
  *(float *)v2 = v10;
  v11 = *(float *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 8);
  *(float *)(v2 + 8) = FLOAT_1_4210855eN14;
  *(float *)v2 = fmaxf(v11, *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64));
  *(float *)(v2 + 8) = fmaxf(
                         *(float *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 8),
                         *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64));
  v12 = 1317011456 - *(_DWORD *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 8);
  *(_DWORD *)(v2 + 32) = v12 + _mm_cvtsi128_si32(v5);
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 32);
  *(_DWORD *)(v2 + 36) = v12 + _mm_cvtsi128_si32(_mm_srli_si128(v5, 4));
  *(_DWORD *)v2 = *(_DWORD *)(v2 + 36);
  v4.m128_i32[0] = *(_DWORD *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 8);
  v13 = *(float *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64);
  *(_DWORD *)(v2 + 16) = v12 + _mm_cvtsi128_si32(_mm_srli_si128(v5, 8));
  v14 = _mm_add_epi32(
          _mm_unpacklo_epi32(
            _mm_unpacklo_epi32(
              _mm_cvtsi32_si128((signed int)v4.m128_f32[0]),
              _mm_cvtsi32_si128((signed int)*(float *)(((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10))),
            _mm_unpacklo_epi32(_mm_cvtsi32_si128((signed int)v13), _mm_cvtsi32_si128(v12))),
          *(__m128i *)roundingCorrection_0);
  this->m_values[0] = _mm_cvtsi128_si32(_mm_srli_si128(v14, 3));
  this->m_values[1] = _mm_cvtsi128_si32(_mm_srli_si128(v14, 7));
  this->m_values[2] = _mm_cvtsi128_si32(_mm_srli_si128(v14, 11));
  this->m_values[3] = (16256 - _mm_extract_epi16(_mm_shuffle_epi32(_mm_cvtsi32_si128(v12), 0), 1)) >> 7;
}

