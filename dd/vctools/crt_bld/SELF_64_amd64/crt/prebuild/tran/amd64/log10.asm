// File Line: 110
// RVA: 0x12BAAF0
// local variable allocation has failed, the output may be wrong!
double __cdecl log10(double result)
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
  __m128i v10; // xmm0
  double v11; // xmm1_8
  double v12; // xmm6_8
  double v13; // xmm1_8
  double v14; // xmm3_8
  double v15; // xmm4_8
  __m128i v16; // xmm2
  unsigned __int64 v17; // [rsp+30h] [rbp-68h]

  v1 = result;
  *(_QWORD *)&v2 = (unsigned __int128)_mm_cvtepi32_pd(
                                        _mm_sub_epi64(
                                          _mm_srli_epi64(*(__m128i *)&result, 0x34u),
                                          *(__m128i *)&_mask_1023_2));
  v3 = (__m128i)_mm_and_pd(*(__m128d *)&result, *(__m128d *)&_real_inf_5);
  if ( *(double *)v3.m128i_i64 != *(double *)&_real_inf_5 )
  {
    v4 = _mm_and_si128(*(__m128i *)&result, *(__m128i *)&_real_mant_3);
    if ( v2 == -1023.0 )
    {
      v16 = _mm_or_si128(v4, *(__m128i *)&_real_one_4);
      *(double *)v16.m128i_i64 = *(double *)v16.m128i_i64 - *(double *)&_real_one_4;
      v3.m128i_i64[0] = v16.m128i_i64[0];
      v4 = _mm_and_si128(v16, *(__m128i *)&_real_mant_3);
      v1 = *(double *)v4.m128i_i64;
      *(_QWORD *)&v2 = (unsigned __int128)_mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v3, 0x34u), *(__m128i *)&_mask_2045_1));
    }
    v5 = 2 * (_mask_mant9_1 & *(_QWORD *)&v1) + (_mask_mant_all8_1 & *(_QWORD *)&v1);
    v17 = v5;
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(result - *(double *)&_real_one_4) & _real_notsign_2) < 0.0625 )
    {
      *(double *)v10.m128i_i64 = result - *(double *)&_real_one_4;
      v11 = *(double *)v10.m128i_i64 / (*(double *)v10.m128i_i64 + 2.0);
      v12 = *(double *)v10.m128i_i64 * v11;
      v13 = v11 + v11;
      *(_QWORD *)&v14 = (unsigned __int128)_mm_and_si128(v10, *(__m128i *)&_mask_lower);
      v15 = (0.01250000000377175 * (v13 * v13) + 0.08333333333333179) * (v13 * v13 * v13)
          + (0.0004348877777076146 * (v13 * v13) + 0.002232139987919448) * (v13 * v13 * v13 * (v13 * v13 * v13) * v13)
          - v12
          + *(double *)v10.m128i_i64
          - v14;
      return v14 * 0.0000007349550096401511
           + v15 * 0.0000007349550096401511
           + v15 * 0.4342937469482422
           + v14 * 0.4342937469482422;
    }
    v6 = v5 >> 44;
    *(_QWORD *)&v7 = (unsigned __int128)_mm_or_si128(v4, *(__m128i *)&_real_half_3);
    *(_QWORD *)&v8 = (unsigned __int128)_mm_or_si128((__m128i)v17, *(__m128i *)&_real_half_3);
    if ( result > 0.0 )
    {
      v9 = (v8 - v7) * _log_F_inv_qword[v6];
      return _log_256_lead_special[v6]
           + 0.3010299950838089 * v2
           + _log_256_tail_special[v6]
           + 5.801722962879576e-10 * v2
           - ((0.3333333333333333 * v9 + 0.5) * (v9 * v9)
            + v9
            + ((0.1666666666666667 * v9 + 0.2) * v9 + 0.25) * (v9 * v9 * (v9 * v9)))
           * 0.4342944819032518;
    }
    if ( result == 0.0 )
      return log10_special(result, -1.797693134862316e308/*-Inf*/, _flag_x_zero_1);
    return log10_special(result, -2.696539702293474e308/*NaN*/, _flag_x_neg_1);
  }
  if ( *(_QWORD *)&result != _real_inf_5 )
  {
    if ( *(_QWORD *)&result == *(_QWORD *)&_real_ninf_5 )
      return log10_special(result, -2.696539702293474e308/*NaN*/, _flag_x_neg_1);
    result = log10_special(result, COERCE_LONG_DOUBLE(_real_qnanbit_3 | *(_QWORD *)&result), _flag_x_nan_5);
  }
  return result;
}

