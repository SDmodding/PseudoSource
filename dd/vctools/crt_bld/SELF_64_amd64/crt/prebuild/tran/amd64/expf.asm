// File Line: 104
// RVA: 0x12B0A20
// local variable allocation has failed, the output may be wrong!
float __cdecl expf(float X)
{
  float v1; // edx
  __m128d v2; // xmm3
  __m128i v3; // xmm4
  int v4; // ecx
  long double v5; // xmm1_8

  v1 = COERCE_FLOAT(_mm_cvtsi128_si32(*(__m128i *)&X));
  if ( (LODWORD(v1) & LODWORD(_real_inf_0)) == LODWORD(_real_inf_0) )
  {
    if ( LODWORD(v1) != LODWORD(_real_inf_0) )
    {
      if ( LODWORD(v1) == _real_ninf_0 )
        return _real_zero_0;
      else
        return expf_special(X, COERCE_FLOAT(_real_qnanbit | LODWORD(v1)), _flag_x_nan_0);
    }
  }
  else
  {
    *(double *)&X = X;
    v2 = (__m128d)_real_64_by_log2;
    v2.m128d_f64[0] = 92.33248261689366 * *(double *)&X;
    if ( 92.33248261689366 * *(double *)&X >= 8192.0 )
    {
      return expf_special(v1, INFINITY, _flag_y_inf);
    }
    else if ( v2.m128d_f64[0] < -9600.0 )
    {
      return expf_special(v1, 0.0, _flag_y_zero);
    }
    else
    {
      v3 = _mm_cvtpd_epi32(v2);
      v4 = _mm_cvtsi128_si32(v3);
      v5 = *(double *)&X - 0.01083042469624915 * _mm_cvtepi32_pd(v3).m128d_f64[0];
      return ((v5 * v5 * (0.1666666666666667 * v5 + 0.5) + v5) * _two_to_jby64_table[v4 & 0x3F]
            + _two_to_jby64_table[v4 & 0x3F])
           * COERCE_DOUBLE(((unsigned int)((v4 - (v4 & 0x3F)) >> 6) + 1023i64) << 52);
    }
  }
  return X;
}

