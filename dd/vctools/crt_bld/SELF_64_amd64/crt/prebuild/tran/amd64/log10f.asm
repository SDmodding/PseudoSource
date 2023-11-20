// File Line: 105
// RVA: 0x12BAE10
// local variable allocation has failed, the output may be wrong!
float __cdecl log10f(float result)
{
  int v1; // eax
  float v2; // xmm5_4
  __m128i v3; // xmm2
  unsigned int v4; // eax
  __int64 v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  __m128i v9; // xmm0
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  __m128i v13; // xmm2
  __m128i v14; // xmm5
  unsigned int v15; // [rsp+30h] [rbp-48h]

  v1 = _mm_cvtsi128_si32(*(__m128i *)&result);
  LODWORD(v2) = (unsigned __int128)_mm_cvtepi32_ps(_mm_sub_epi32(_mm_srli_epi32(*(__m128i *)&result, 0x17u), *(__m128i *)&_mask_127_0));
  if ( COERCE_FLOAT(LODWORD(result) & _real_inf_6) != 3.4028237e38/*+Inf*/ )
  {
    v3 = _mm_and_si128(*(__m128i *)&result, *(__m128i *)&_real_mant_4);
    if ( v2 == -127.0 )
    {
      v13 = _mm_or_si128(v3, *(__m128i *)&_real_one_5);
      *(float *)v13.m128i_i32 = *(float *)v13.m128i_i32 - 1.0;
      v14 = v13;
      v3 = _mm_and_si128(v13, *(__m128i *)&_real_mant_4);
      v1 = _mm_cvtsi128_si32(v3);
      LODWORD(v2) = (unsigned __int128)_mm_cvtepi32_ps(_mm_sub_epi32(_mm_srli_epi32(v14, 0x17u), *(__m128i *)&_mask_253_0));
    }
    v4 = 2 * (_mask_mant8_1 & v1) + (_mask_mant_all7_1 & v1);
    v15 = v4;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result - 1.0) & _real_notsign_3) < 0.0625 )
    {
      *(float *)v9.m128i_i32 = result - 1.0;
      v10 = *(float *)v9.m128i_i32 / (float)(*(float *)v9.m128i_i32 + 2.0);
      LODWORD(v11) = (unsigned __int128)_mm_and_si128(v9, *(__m128i *)&_mask_lower_0);
      v12 = (float)((float)((float)((float)((float)((float)(v10 + v10) * (float)(v10 + v10)) * 0.0125) + 0.083333336)
                          * (float)((float)(v10 + v10) * (float)((float)(v10 + v10) * (float)(v10 + v10))))
                  - (float)(*(float *)v9.m128i_i32 * v10))
          + (float)(*(float *)v9.m128i_i32 - v11);
      return (float)((float)((float)(v11 * 0.00070073188) + (float)(v12 * 0.00070073188)) + (float)(v12 * 0.43359375))
           + (float)(v11 * 0.43359375);
    }
    v5 = v4 >> 16;
    LODWORD(v6) = (unsigned __int128)_mm_or_si128(v3, *(__m128i *)&_real_half_4);
    LODWORD(v7) = (unsigned __int128)_mm_or_si128((__m128i)v15, *(__m128i *)&_real_half_4);
    if ( result > 0.0 )
    {
      v8 = (float)(v7 - v6) * _log_F_inv_dword[v5];
      return (float)((float)(0.30078125 * v2) + _log_128_lead_0[v5])
           + (float)((float)((float)(0.00024874564 * v2)
                           - (float)((float)(v8 + (float)((float)((float)(v8 * 0.33333334) + 0.5) * (float)(v8 * v8)))
                                   * 0.43429449))
                   + _log_128_tail_0[v5]);
    }
    if ( result == 0.0 )
      return log10f_special(result, -3.4028237e38/*-Inf*/, _flag_x_zero_2);
    return log10f_special(result, -5.1042355e38/*NaN*/, _flag_x_neg_2);
  }
  if ( v1 != (_DWORD)_real_inf_6 )
  {
    if ( v1 == LODWORD(_real_ninf_6) )
      return log10f_special(result, -5.1042355e38/*NaN*/, _flag_x_neg_2);
    result = log10f_special(result, COERCE_FLOAT(_mm_cvtsi32_si128((unsigned int)_real_qnanbit_4 | v1)), _flag_x_nan_6);
  }
  return result;
}

