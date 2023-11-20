// File Line: 120
// RVA: 0x12AE9A0
// local variable allocation has failed, the output may be wrong!
float __cdecl powf(float result, float Y)
{
  __m128i v2; // xmm0
  unsigned __int64 v3; // STA0_8
  double v4; // xmm1_8
  double v5; // xmm0_8
  __m128d v6; // xmm7
  __m128i v7; // xmm4
  int v8; // ecx
  double v9; // xmm0_8
  float v10; // er11
  unsigned int v11; // er11
  signed int v12; // er10
  float v13; // eax
  float v14; // eax
  float v15; // eax
  float v16; // edx
  int v17; // edx
  float v18; // eax
  unsigned int v19; // eax
  float v20; // eax
  float v21; // eax
  unsigned int v22; // er9
  float v23; // eax
  float x; // [rsp+40h] [rbp-D8h]
  double y; // [rsp+50h] [rbp-C8h]
  unsigned int v26; // [rsp+70h] [rbp-A8h]

  x = result;
  *(float *)&y = Y;
  if ( !(LODWORD(Y) & _f32_exp_mant_mask) )
  {
    v14 = 0.0;
    v10 = result;
    if ( (LODWORD(result) & _f32_exp_mask) == _f32_exp_mask )
      v14 = result;
    if ( !(LODWORD(v14) & _f32_mant_mask) )
      return _f32_pos_one;
__x_is_nan:
    v23 = 0.0;
    if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
      v23 = Y;
    if ( !(LODWORD(v23) & _f32_mant_mask) )
      return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_x_nan);
    if ( LODWORD(v10) == _f32_ind_pattern )
      v10 = Y;
    return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_x_nan_y_nan);
  }
  if ( LODWORD(Y) == LODWORD(_f32_pos_one) )
  {
    v15 = 0.0;
    v10 = result;
    if ( (LODWORD(result) & _f32_exp_mask) == _f32_exp_mask )
      v15 = result;
    if ( !(LODWORD(v15) & _f32_mant_mask) )
    {
      LODWORD(result) = (unsigned __int128)_mm_cvtsi32_si128(LODWORD(result));
      return result;
    }
    goto __x_is_nan;
  }
  v26 = _f32_pos_zero;
  if ( (LODWORD(result) & _f32_sign_mask) == _f32_sign_mask )
  {
    if ( (signed int)(LODWORD(Y) & _f32_exp_mask) > (signed int)_f32_ay_max_bound )
      goto __ay_is_very_large;
    v11 = LODWORD(Y) & _f32_exp_mant_mask;
    v12 = ((LODWORD(Y) & _f32_exp_mant_mask) >> _f32_exp_shift) - _f32_exp_bias;
    if ( v12 >= 0 )
    {
      if ( v12 > (signed int)_yexp_24 )
      {
__continue_after_y_int_check:
        if ( LODWORD(result) == _f32_neg_zero )
          goto __x_is_zero;
        if ( LODWORD(result) == _f32_neg_one )
          goto __x_is_neg_one;
        if ( (LODWORD(result) & _f32_exp_mask) != _f32_exp_mask )
        {
          *(_OWORD *)&result = LODWORD(result) & _f32_exp_mant_mask;
__log_x:
          *(double *)v2.m128i_i64 = result;
          y = Y;
          v3 = 2 * (_mask_mant8 & v2.m128i_i64[0]) + (_mask_mant_all7 & v2.m128i_i64[0]);
          v4 = (COERCE_DOUBLE(_mm_or_si128((__m128i)v3, *(__m128i *)&_real_half))
              - COERCE_DOUBLE(_mm_or_si128(_mm_and_si128(v2, *(__m128i *)&_real_mant), *(__m128i *)&_real_half)))
             * _log_F_inv_special[v3 >> 45];
          v5 = (_log_128_table[v3 >> 45]
              - ((0.5 * v4 + 1.0) * v4
               + (0.25 * v4 + 0.3333333333333333) * (v4 * v4 * v4))
              + 0.6931471805599453
              * COERCE_DOUBLE(_mm_cvtepi32_pd(_mm_sub_epi64(_mm_srli_epi64(v2, 0x34u), *(__m128i *)&_mask_1023))))
             * y;
          v6 = (__m128d)_real_32_by_log2;
          v6.m128d_f64[0] = 46.16624130844683 * v5;
          if ( 46.16624130844683 * v5 >= 4096.0 )
          {
            LODWORD(v10) = v26 | _f32_real_inf;
          }
          else
          {
            if ( v6.m128d_f64[0] >= -4768.0 )
            {
              v7 = _mm_cvtpd_epi32(v6);
              v8 = _mm_cvtsi128_si32(v7);
              v9 = v5 - 0.02166084939249829 * COERCE_DOUBLE(_mm_cvtepi32_pd(v7));
              *(float *)&v9 = (((0.5 * v9 + 1.0) * v9 + (0.04166666666666666 * v9 + 0.1666666666666667) * (v9 * v9 * v9))
                             * _two_to_jby32_table[v8 & 0x1F]
                             + _two_to_jby32_table[v8 & 0x1F])
                            * COERCE_DOUBLE(((unsigned int)((v8 - (v8 & 0x1F)) >> 5) + 1023i64) << 52);
              LODWORD(result) = LODWORD(v9) | v26;
              return result;
            }
            LODWORD(v10) = v26 | _f32_real_zero;
          }
__z_is_zero_or_inf:
          v22 = _flag_z_zero;
          if ( LODWORD(v10) & _f32_exp_mant_mask )
            v22 = _flag_z_inf;
          return powf_special(x, *(float *)&y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), v22);
        }
        goto __x_is_inf_or_nan;
      }
      if ( !(v11 & (_f32_mant_full >> v12)) )
      {
        if ( v11 & (_f32_1_before_mant >> v12) )
          v26 = _f32_sign_mask;
        goto __continue_after_y_int_check;
      }
    }
    if ( (LODWORD(result) & _f32_exp_mask) != _f32_exp_mask )
    {
      if ( LODWORD(result) != _f32_neg_zero )
        return powf_special(result, Y, -5.1042355e38/*NaN*/, _flag_x_neg_y_notint);
      goto __x_is_zero;
    }
    goto __x_is_inf_or_nan;
  }
  if ( LODWORD(result) != LODWORD(_f32_pos_one) )
  {
    if ( LODWORD(result) == _f32_pos_zero )
      goto __x_is_zero;
    if ( (LODWORD(result) & _f32_exp_mask) != _f32_exp_mask )
    {
      if ( (signed int)(LODWORD(Y) & _f32_exp_mask) <= (signed int)_f32_ay_max_bound )
      {
        if ( (signed int)(LODWORD(Y) & _f32_exp_mask) < (signed int)_f32_ay_min_bound )
          return Y + 1.0;
        goto __log_x;
      }
__ay_is_very_large:
      if ( (LODWORD(result) & _f32_exp_mask) != _f32_exp_mask )
      {
        if ( LODWORD(result) & _f32_exp_mant_mask )
        {
          if ( LODWORD(result) != _f32_neg_one )
          {
            if ( (signed int)(_f32_exp_mant_mask & LODWORD(result)) < SLODWORD(_f32_pos_one) )
            {
              v10 = 0.0;
              if ( LODWORD(Y) & _f32_sign_mask )
                v10 = *(float *)&_f32_pos_inf;
            }
            else
            {
              v10 = 0.0;
              if ( !(LODWORD(Y) & _f32_sign_mask) )
                v10 = *(float *)&_f32_pos_inf;
            }
            v21 = 0.0;
            if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
              v21 = Y;
            if ( LODWORD(v21) & _f32_mant_mask )
              v10 = Y;
            if ( !(LODWORD(v21) & _f32_mant_mask) )
            {
              if ( v21 != 0.0 )
              {
                LODWORD(result) = (unsigned __int128)_mm_cvtsi32_si128(LODWORD(v10));
                return result;
              }
              goto __z_is_zero_or_inf;
            }
            return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_y_nan);
          }
__x_is_neg_one:
          v16 = _f32_pos_one;
          if ( LODWORD(Y) == _f32_neg_inf )
            v16 = *(float *)&_f32_neg_one;
          v17 = v26 | LODWORD(v16);
          v18 = 0.0;
          v10 = Y;
          if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
            v18 = Y;
          if ( !(LODWORD(v18) & _f32_mant_mask) )
          {
            LODWORD(result) = (unsigned __int128)_mm_cvtsi32_si128(v17);
            return result;
          }
          return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_y_nan);
        }
__x_is_zero:
        v19 = 0;
        if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
        {
          v10 = Y;
          if ( LODWORD(Y) == _f32_neg_inf )
            v19 = _f32_pos_inf;
          if ( LODWORD(Y) != _f32_neg_inf )
          {
            if ( !(LODWORD(Y) & _f32_mant_mask) )
            {
              LODWORD(result) = (unsigned __int128)_mm_cvtsi32_si128(v19);
              return result;
            }
            return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_y_nan);
          }
        }
        else
        {
          if ( LODWORD(Y) & _f32_sign_mask )
            v19 = _f32_pos_inf;
          if ( !(LODWORD(Y) & _f32_sign_mask) )
          {
            LODWORD(result) = *(unsigned __int128 *)&_mm_cvtsi32_si128(v19) | v26;
            return result;
          }
        }
        return powf_special(
                 result,
                 Y,
                 COERCE_FLOAT(*(unsigned __int128 *)&_mm_cvtsi32_si128(v19) | v26),
                 _flag_x_zero_z_inf);
      }
    }
__x_is_inf_or_nan:
    v10 = 0.0;
    if ( !(LODWORD(Y) & _f32_sign_mask) )
      v10 = *(float *)&_f32_pos_inf;
    if ( LODWORD(result) & _f32_mant_mask )
      v10 = result;
    if ( !(LODWORD(result) & _f32_mant_mask) )
    {
      v20 = 0.0;
      if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
        v20 = Y;
      if ( LODWORD(v20) & _f32_mant_mask )
        v10 = Y;
      if ( !(LODWORD(v20) & _f32_mant_mask) )
      {
        LODWORD(result) = *(unsigned __int128 *)&_mm_cvtsi32_si128(LODWORD(v10)) | v26;
        return result;
      }
      return powf_special(result, Y, COERCE_FLOAT(_mm_cvtsi32_si128(LODWORD(v10))), _flag_y_nan);
    }
    goto __x_is_nan;
  }
  v13 = 0.0;
  if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
    v13 = Y;
  if ( LODWORD(v13) & _f32_mant_mask && !(LODWORD(Y) & _f32_qnan_set) )
    result = powf_special(result, Y, 1.0, _flag_x_one_y_snan);
  return result;
}

