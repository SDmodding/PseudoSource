// File Line: 150
// RVA: 0x12B7130
// local variable allocation has failed, the output may be wrong!
double __cdecl log(double X)
{
  double v1; // rax
  double v2; // xmm6_8
  __m128i v3; // xmm5
  __m128i v4; // xmm2
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rax
  double v7; // xmm2_8
  double v8; // xmm1_8
  double v9; // xmm2_8
  double v10; // xmm0_8
  double v11; // xmm1_8
  double v12; // xmm6_8
  double v13; // xmm1_8
  __m128i v14; // xmm2
  unsigned __int64 v15; // [rsp+30h] [rbp-68h]

  v1 = X;
  *(_QWORD *)&v2 = *(_OWORD *)&_mm_cvtepi32_pd(_mm_sub_epi64(_mm_srli_epi64(*(__m128i *)&X, 0x34u), *(__m128i *)&_mask_1023_0));
  v3 = (__m128i)_mm_and_pd(*(__m128d *)&X, *(__m128d *)&_real_inf_3);
  if ( *(double *)v3.m128i_i64 != *(double *)&_real_inf_3 )
  {
    v4 = _mm_and_si128(*(__m128i *)&X, *(__m128i *)&_real_mant_1);
    if ( v2 == -1023.0 )
    {
      v14 = _mm_or_si128(v4, *(__m128i *)&_real_one_2);
      *(double *)v14.m128i_i64 = *(double *)v14.m128i_i64 - *(double *)&_real_one_2;
      v3.m128i_i64[0] = v14.m128i_i64[0];
      v4 = _mm_and_si128(v14, *(__m128i *)&_real_mant_1);
      v1 = *(double *)v4.m128i_i64;
      *(_QWORD *)&v2 = *(_OWORD *)&_mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v3, 0x34u), *(__m128i *)&_mask_2045));
    }
    v5 = 2 * (_mask_mant9 & *(_QWORD *)&v1) + (_mask_mant_all8 & *(_QWORD *)&v1);
    v15 = v5;
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(X - *(double *)&_real_one_2) & _real_notsign_0) < 0.0625 )
    {
      v10 = X - *(double *)&_real_one_2;
      v11 = v10 / (v10 + 2.0);
      v12 = v10 * v11;
      v13 = v11 + v11;
      return v10
           + (0.01250000000377175 * (v13 * v13) + 0.08333333333333179) * (v13 * v13 * v13)
           + (0.0004348877777076146 * (v13 * v13) + 0.002232139987919448) * (v13 * v13 * v13 * (v13 * v13 * v13) * v13)
           - v12;
    }
    v6 = v5 >> 44;
    *(_QWORD *)&v7 = _mm_or_si128(v4, *(__m128i *)&_real_half_1).m128i_u64[0];
    *(_QWORD *)&v8 = _mm_or_si128((__m128i)v15, *(__m128i *)&_real_half_1).m128i_u64[0];
    if ( X > 0.0 )
    {
      v9 = (v8 - v7) * _log_F_inv_qword[v6];
      return _log_256_lead[v6]
           + 0.6931471228599548 * v2
           + _log_256_tail[v6]
           + 0.00000005769999047543285 * v2
           - ((0.3333333333333333 * v9 + 0.5) * (v9 * v9)
            + v9
            + ((0.1666666666666667 * v9 + 0.2) * v9 + 0.25) * (v9 * v9 * (v9 * v9)));
    }
    if ( X == 0.0 )
      return log_special(X, -INFINITY, _flag_x_zero_0);
    return log_special(X, NAN, _flag_x_neg_0);
  }
  if ( *(_QWORD *)&X != _real_inf_3 )
  {
    if ( *(_QWORD *)&X == *(_QWORD *)&_real_ninf_3 )
      return log_special(X, NAN, _flag_x_neg_0);
    return log_special(X, COERCE_LONG_DOUBLE(_real_qnanbit_2 | *(_QWORD *)&X), _flag_x_nan_3);
  }
  return X;
}

