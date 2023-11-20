// File Line: 124
// RVA: 0x12B6950
double __cdecl exp(double result)
{
  double v1; // rdx
  __m128d v2; // xmm3
  __m128i v3; // xmm4
  double v4; // xmm1_8
  int v5; // ecx
  __int64 v6; // rax
  __int64 v7; // rcx
  double v8; // xmm2_8
  int v9; // er9
  double v10; // rcx
  double v11; // xmm0_8
  int v12; // er11
  char v13; // cl

  v1 = result;
  if ( (*(_QWORD *)&result & *(_QWORD *)&_real_inf_2) == *(_QWORD *)&_real_inf_2 )
  {
    if ( *(_QWORD *)&result != *(_QWORD *)&_real_inf_2 )
    {
      if ( *(_QWORD *)&result == _real_ninf_2 )
        result = _real_zero_1;
      else
        result = exp_special(result, COERCE_LONG_DOUBLE(_real_qnanbit_1 | *(_QWORD *)&result), _flag_x_nan_2);
    }
  }
  else
  {
    v2 = (__m128d)_real_64_by_log2_0;
    if ( (signed __int64)(_exp_mant_mask & *(_QWORD *)&result) < (signed __int64)_real_x_near0_threshold )
    {
      result = *(double *)&_real_one_1;
    }
    else
    {
      v2.m128d_f64[0] = 92.33248261689366 * result;
      if ( 92.33248261689366 * result > 65536.0 )
      {
        result = exp_special(result, 1.797693134862316e308/*+Inf*/, _flag_y_inf_0);
      }
      else if ( v2.m128d_f64[0] <= -68800.0 )
      {
        result = exp_special(result, 0.0, _flag_y_zero_0);
      }
      else
      {
        v3 = _mm_cvtpd_epi32(v2);
        *(_QWORD *)&v4 = (unsigned __int128)_mm_cvtepi32_pd(v3);
        v5 = _mm_cvtsi128_si32(v3);
        v6 = v5 & 0x3F;
        v7 = (unsigned int)((v5 - (signed int)v6) >> 6);
        v9 = 0;
        if ( (signed int)v7 <= (signed int)_denormal_threshold )
          v9 = v7;
        *(_QWORD *)&v10 = (v7 + 1023) << 52;
        v8 = result - 0.01083042469622342 * v4 + v4 * -2.572804622327669e-14;
        v11 = ((0.5 * v8 + 1.0) * v8
             + (0.04166666666666666 * v8 + 0.1666666666666667) * (v8 * v8 * v8)
             + (0.001388888888888889 * v8 + 0.008333333333333333) * (v8 * v8 * (v8 * v8 * v8)))
            * _two_to_jby64_table[v6]
            + _two_to_jby64_tail_table[v6]
            + _two_to_jby64_head_table[v6];
        if ( *(_QWORD *)&v10 == *(_QWORD *)&_real_inf_2 )
        {
          *(_QWORD *)&result = *(_QWORD *)&v11 | _enable_almost_inf;
        }
        else if ( v9 )
        {
          v12 = 0;
          if ( v11 >= 1.0 )
            v12 = v9;
          if ( v12 == _denormal_threshold )
          {
            result = v11 * v10;
          }
          else if ( *(_QWORD *)&v1 > (signed __int64)_denormal_tiny_threshold )
          {
            result = *(double *)&_real_smallest_denormal;
          }
          else
          {
            v13 = v9 + 50;
            if ( v9 + 1074 < 0 )
              v13 = 0;
            result = v11 * COERCE_DOUBLE(1i64 << v13);
          }
        }
        else
        {
          result = v11 * v10;
        }
      }
    }
  }
  return result;
}

