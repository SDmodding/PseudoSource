// File Line: 120
// RVA: 0x12AE9A0
// local variable allocation has failed, the output may be wrong!
float __cdecl powf(float X, float Y)
{
  __m128i v2; // xmm0
  double v3; // xmm2_8
  double v4; // xmm0_8
  __m128d v5; // xmm7
  __m128i v6; // xmm4
  int v7; // ecx
  long double v8; // xmm0_8
  unsigned int v9; // r11d
  unsigned int v10; // r11d
  signed int v11; // r10d
  float v12; // eax
  float v13; // eax
  float v14; // eax
  float v15; // edx
  int v16; // edx
  float v17; // eax
  float v18; // eax
  float v19; // eax
  float v20; // eax
  unsigned int v21; // r9d
  float v22; // eax
  float x; // [rsp+40h] [rbp-D8h]
  double y; // [rsp+50h] [rbp-C8h]
  unsigned int v25; // [rsp+70h] [rbp-A8h]
  unsigned __int64 v26; // [rsp+A0h] [rbp-78h]

  x = X;
  *(float *)&y = Y;
  if ( (LODWORD(Y) & _f32_exp_mant_mask) == 0 )
  {
    v13 = 0.0;
    *(float *)&v9 = X;
    if ( (LODWORD(X) & _f32_exp_mask) == _f32_exp_mask )
      v13 = X;
    if ( (LODWORD(v13) & _f32_mant_mask) == 0 )
      return _f32_pos_one;
    goto __x_is_nan;
  }
  if ( LODWORD(Y) == LODWORD(_f32_pos_one) )
  {
    v14 = 0.0;
    *(float *)&v9 = X;
    if ( (LODWORD(X) & _f32_exp_mask) == _f32_exp_mask )
      v14 = X;
    if ( (LODWORD(v14) & _f32_mant_mask) == 0 )
      return X;
__x_is_nan:
    v22 = 0.0;
    if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
      v22 = Y;
    if ( (LODWORD(v22) & _f32_mant_mask) == 0 )
      return powf_special(X, Y, *(float *)&v9, _flag_x_nan);
    if ( v9 == _f32_ind_pattern )
      *(float *)&v9 = Y;
    return powf_special(X, Y, *(float *)&v9, _flag_x_nan_y_nan);
  }
  v25 = _f32_pos_zero;
  if ( (LODWORD(X) & _f32_sign_mask) == _f32_sign_mask )
  {
    if ( (int)(LODWORD(Y) & _f32_exp_mask) > (int)_f32_ay_max_bound )
      goto __ay_is_very_large;
    v10 = LODWORD(Y) & _f32_exp_mant_mask;
    v11 = ((LODWORD(Y) & _f32_exp_mant_mask) >> _f32_exp_shift) - _f32_exp_bias;
    if ( v11 >= 0 )
    {
      if ( v11 > (int)_yexp_24 )
      {
__continue_after_y_int_check:
        if ( LODWORD(X) == _f32_neg_zero )
          goto __x_is_zero;
        if ( LODWORD(X) == _f32_neg_one )
          goto __x_is_neg_one;
        if ( (LODWORD(X) & _f32_exp_mask) != _f32_exp_mask )
        {
          *(_OWORD *)&X = LODWORD(X) & _f32_exp_mant_mask;
          goto __log_x;
        }
        goto __x_is_inf_or_nan;
      }
      if ( (v10 & (_f32_mant_full >> v11)) == 0 )
      {
        if ( (v10 & (_f32_1_before_mant >> v11)) != 0 )
          v25 = _f32_sign_mask;
        goto __continue_after_y_int_check;
      }
    }
    if ( (LODWORD(X) & _f32_exp_mask) != _f32_exp_mask )
    {
      if ( LODWORD(X) != _f32_neg_zero )
        return powf_special(X, Y, NAN, _flag_x_neg_y_notint);
      goto __x_is_zero;
    }
    goto __x_is_inf_or_nan;
  }
  if ( LODWORD(X) != LODWORD(_f32_pos_one) )
  {
    if ( LODWORD(X) == _f32_pos_zero )
      goto __x_is_zero;
    if ( (LODWORD(X) & _f32_exp_mask) != _f32_exp_mask )
    {
      if ( (int)(LODWORD(Y) & _f32_exp_mask) <= (int)_f32_ay_max_bound )
      {
        if ( (int)(LODWORD(Y) & _f32_exp_mask) < (int)_f32_ay_min_bound )
          return Y + 1.0;
__log_x:
        *(double *)v2.m128i_i64 = X;
        y = Y;
        v26 = 2 * (_mask_mant8 & v2.m128i_i64[0]) + (_mask_mant_all7 & v2.m128i_i64[0]);
        v3 = (*(double *)_mm_or_si128((__m128i)v26, *(__m128i *)&_real_half).m128i_i64
            - *(double *)_mm_or_si128(_mm_and_si128(v2, *(__m128i *)&_real_mant), *(__m128i *)&_real_half).m128i_i64)
           * _log_F_inv_special[v26 >> 45];
        v4 = (_log_128_table[v26 >> 45]
            - ((0.5 * v3 + 1.0) * v3
             + (0.25 * v3 + 0.3333333333333333) * (v3 * v3 * v3))
            + 0.6931471805599453
            * _mm_cvtepi32_pd(_mm_sub_epi64(_mm_srli_epi64(v2, 0x34u), *(__m128i *)&_mask_1023)).m128d_f64[0])
           * Y;
        v5 = (__m128d)_real_32_by_log2;
        v5.m128d_f64[0] = 46.16624130844683 * v4;
        if ( 46.16624130844683 * v4 >= 4096.0 )
        {
          v9 = v25 | _f32_real_inf;
        }
        else
        {
          if ( v5.m128d_f64[0] >= -4768.0 )
          {
            v6 = _mm_cvtpd_epi32(v5);
            v7 = _mm_cvtsi128_si32(v6);
            v8 = v4 - 0.02166084939249829 * _mm_cvtepi32_pd(v6).m128d_f64[0];
            *(float *)&v8 = (((0.5 * v8 + 1.0) * v8 + (0.04166666666666666 * v8 + 0.1666666666666667) * (v8 * v8 * v8))
                           * _two_to_jby32_table[v7 & 0x1F]
                           + _two_to_jby32_table[v7 & 0x1F])
                          * COERCE_DOUBLE(((unsigned int)((v7 - (v7 & 0x1F)) >> 5) + 1023i64) << 52);
            LODWORD(X) = LODWORD(v8) | v25;
            return X;
          }
          v9 = v25 | _f32_real_zero;
        }
        goto __z_is_zero_or_inf;
      }
__ay_is_very_large:
      if ( (LODWORD(X) & _f32_exp_mask) != _f32_exp_mask )
      {
        if ( (LODWORD(X) & _f32_exp_mant_mask) != 0 )
        {
          if ( LODWORD(X) != _f32_neg_one )
          {
            if ( (int)(_f32_exp_mant_mask & LODWORD(X)) < SLODWORD(_f32_pos_one) )
            {
              *(float *)&v9 = 0.0;
              if ( (LODWORD(Y) & _f32_sign_mask) != 0 )
                v9 = _f32_pos_inf;
            }
            else
            {
              *(float *)&v9 = 0.0;
              if ( (LODWORD(Y) & _f32_sign_mask) == 0 )
                v9 = _f32_pos_inf;
            }
            v20 = 0.0;
            if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
              v20 = Y;
            if ( (LODWORD(v20) & _f32_mant_mask) != 0 )
              *(float *)&v9 = Y;
            if ( (LODWORD(v20) & _f32_mant_mask) == 0 )
            {
              if ( v20 != 0.0 )
                return *(float *)&v9;
__z_is_zero_or_inf:
              v21 = _flag_z_zero;
              if ( (v9 & _f32_exp_mant_mask) != 0 )
                v21 = _flag_z_inf;
              return powf_special(x, *(float *)&y, *(float *)&v9, v21);
            }
            return powf_special(X, Y, *(float *)&v9, _flag_y_nan);
          }
__x_is_neg_one:
          v15 = _f32_pos_one;
          if ( LODWORD(Y) == _f32_neg_inf )
            v15 = *(float *)&_f32_neg_one;
          v16 = v25 | LODWORD(v15);
          v17 = 0.0;
          *(float *)&v9 = Y;
          if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
            v17 = Y;
          if ( (LODWORD(v17) & _f32_mant_mask) == 0 )
            return *(float *)&v16;
          return powf_special(X, Y, *(float *)&v9, _flag_y_nan);
        }
__x_is_zero:
        v18 = 0.0;
        if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
        {
          *(float *)&v9 = Y;
          if ( LODWORD(Y) == _f32_neg_inf )
            v18 = *(float *)&_f32_pos_inf;
          if ( LODWORD(Y) != _f32_neg_inf )
          {
            if ( (LODWORD(Y) & _f32_mant_mask) == 0 )
              return v18;
            return powf_special(X, Y, *(float *)&v9, _flag_y_nan);
          }
        }
        else
        {
          if ( (LODWORD(Y) & _f32_sign_mask) != 0 )
            v18 = *(float *)&_f32_pos_inf;
          if ( (LODWORD(Y) & _f32_sign_mask) == 0 )
          {
            LODWORD(X) = LODWORD(v18) | v25;
            return X;
          }
        }
        return powf_special(X, Y, COERCE_FLOAT(LODWORD(v18) | v25), _flag_x_zero_z_inf);
      }
    }
__x_is_inf_or_nan:
    *(float *)&v9 = 0.0;
    if ( (LODWORD(Y) & _f32_sign_mask) == 0 )
      v9 = _f32_pos_inf;
    if ( (LODWORD(X) & _f32_mant_mask) != 0 )
      *(float *)&v9 = X;
    if ( (LODWORD(X) & _f32_mant_mask) == 0 )
    {
      v19 = 0.0;
      if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
        v19 = Y;
      if ( (LODWORD(v19) & _f32_mant_mask) != 0 )
        *(float *)&v9 = Y;
      if ( (LODWORD(v19) & _f32_mant_mask) == 0 )
      {
        LODWORD(X) = v9 | v25;
        return X;
      }
      return powf_special(X, Y, *(float *)&v9, _flag_y_nan);
    }
    goto __x_is_nan;
  }
  v12 = 0.0;
  if ( (LODWORD(Y) & _f32_exp_mask) == _f32_exp_mask )
    v12 = Y;
  if ( (LODWORD(v12) & _f32_mant_mask) != 0 && (LODWORD(Y) & _f32_qnan_set) == 0 )
    return powf_special(X, Y, 1.0, _flag_x_one_y_snan);
  return X;
}n;
  }
  v12 = 0.0;
  if ( (LODWORD(

