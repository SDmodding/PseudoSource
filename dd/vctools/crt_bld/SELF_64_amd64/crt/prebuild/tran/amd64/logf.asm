// File Line: 105
// RVA: 0x12B12E0
// local variable allocation has failed, the output may be wrong!
float __cdecl logf(float result)
{
  int v1; // eax
  float v2; // xmm5_4
  __m128i v3; // xmm2
  unsigned int v4; // eax
  __int64 v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  __m128i v11; // xmm2
  __m128i v12; // xmm5
  unsigned int v13; // [rsp+30h] [rbp-48h]

  v1 = _mm_cvtsi128_si32(*(__m128i *)&result);
  LODWORD(v2) = (unsigned __int128)_mm_cvtepi32_ps(_mm_sub_epi32(_mm_srli_epi32(*(__m128i *)&result, 0x17u), *(__m128i *)&_mask_127));
  if ( COERCE_FLOAT(LODWORD(result) & _real_inf_1) != 3.4028237e38/*+Inf*/ )
  {
    v3 = _mm_and_si128(*(__m128i *)&result, *(__m128i *)&_real_mant_0);
    if ( v2 == -127.0 )
    {
      v11 = _mm_or_si128(v3, *(__m128i *)&_real_one_0);
      *(float *)v11.m128i_i32 = *(float *)v11.m128i_i32 - 1.0;
      v12 = v11;
      v3 = _mm_and_si128(v11, *(__m128i *)&_real_mant_0);
      v1 = _mm_cvtsi128_si32(v3);
      LODWORD(v2) = (unsigned __int128)_mm_cvtepi32_ps(_mm_sub_epi32(_mm_srli_epi32(v12, 0x17u), *(__m128i *)&_mask_253));
    }
    v4 = 2 * (_mask_mant8_0 & v1) + (_mask_mant_all7_0 & v1);
    v13 = v4;
    if ( result == 2.7182817 )
      return *(float *)&_real_one_0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result - 1.0) & _real_notsign) < 0.0625 )
    {
      v9 = result - 1.0;
      v10 = v9 / (float)(v9 + 2.0);
      return v9
           + (float)((float)((float)((float)((float)((float)(v10 + v10) * (float)(v10 + v10)) * 0.0125) + 0.083333336)
                           * (float)((float)(v10 + v10) * (float)((float)(v10 + v10) * (float)(v10 + v10))))
                   - (float)(v9 * v10));
    }
    v5 = v4 >> 16;
    LODWORD(v6) = (unsigned __int128)_mm_or_si128(v3, *(__m128i *)&_real_half_0);
    LODWORD(v7) = (unsigned __int128)_mm_or_si128((__m128i)v13, *(__m128i *)&_real_half_0);
    if ( result > 0.0 )
    {
      v8 = (float)(v7 - v6) * _log_F_inv_dword[v5];
      return (float)((float)(0.69311523 * v2) + _log_128_lead[v5])
           + (float)((float)((float)(0.000031946183 * v2)
                           - (float)(v8 + (float)((float)((float)(v8 * 0.33333334) + 0.5) * (float)(v8 * v8))))
                   + _log_128_tail[v5]);
    }
    if ( result == 0.0 )
      return logf_special(result, -3.4028237e38/*-Inf*/, _flag_x_zero);
    return logf_special(result, -5.1042355e38/*NaN*/, _flag_x_neg);
  }
  if ( v1 != (_DWORD)_real_inf_1 )
  {
    if ( v1 == LODWORD(_real_ninf_1) )
      return logf_special(result, -5.1042355e38/*NaN*/, _flag_x_neg);
    result = logf_special(result, COERCE_FLOAT(_mm_cvtsi32_si128((unsigned int)_real_qnanbit_0 | v1)), _flag_x_nan_1);
  }
  return result;
}

