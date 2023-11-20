// File Line: 104
// RVA: 0x12B0A20
// local variable allocation has failed, the output may be wrong!
float __cdecl expf(float result)
{
  unsigned int v1; // edx
  __m128d v2; // xmm3
  __m128i v3; // xmm4
  int v4; // ecx
  double v5; // xmm1_8

  v1 = _mm_cvtsi128_si32(*(__m128i *)&result);
  if ( (v1 & LODWORD(_real_inf_0)) == LODWORD(_real_inf_0) )
  {
    if ( v1 != LODWORD(_real_inf_0) )
    {
      if ( v1 == _real_ninf_0 )
        result = _real_zero_0;
      else
        result = expf_special(result, COERCE_FLOAT(_mm_cvtsi32_si128(_real_qnanbit | v1)), _flag_x_nan_0);
    }
  }
  else
  {
    *(double *)&result = result;
    v2 = (__m128d)_real_64_by_log2;
    v2.m128d_f64[0] = 92.33248261689366 * *(double *)&result;
    if ( 92.33248261689366 * *(double *)&result >= 8192.0 )
    {
      result = expf_special(COERCE_FLOAT(_mm_cvtsi32_si128(v1)), 3.4028237e38/*+Inf*/, _flag_y_inf);
    }
    else if ( v2.m128d_f64[0] < -9600.0 )
    {
      result = expf_special(COERCE_FLOAT(_mm_cvtsi32_si128(v1)), 0.0, _flag_y_zero);
    }
    else
    {
      v3 = _mm_cvtpd_epi32(v2);
      v4 = _mm_cvtsi128_si32(v3);
      v5 = *(double *)&result - 0.01083042469624915 * COERCE_DOUBLE(_mm_cvtepi32_pd(v3));
      result = ((v5 * v5 * (0.1666666666666667 * v5 + 0.5) + v5) * _two_to_jby64_table[v4 & 0x3F]
              + _two_to_jby64_table[v4 & 0x3F])
             * COERCE_DOUBLE(((unsigned int)((v4 - (v4 & 0x3F)) >> 6) + 1023i64) << 52);
    }
  }
  return result;
}

