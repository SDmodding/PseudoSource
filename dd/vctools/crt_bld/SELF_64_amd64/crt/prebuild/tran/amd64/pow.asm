// File Line: 121
// RVA: 0x12B73F0
// local variable allocation has failed, the output may be wrong!
double __cdecl pow(double X, double Y)
{
  __m128i v2; // xmm5
  double v3; // r8
  double v4; // xmm6_8
  __m128i v5; // xmm2
  unsigned __int64 v6; // r8
  double v7; // xmm2_8
  double v8; // xmm1_8
  double v9; // xmm4_8
  double v10; // xmm5_8
  double v11; // xmm7_8
  double v12; // xmm2_8
  double v13; // xmm0_8
  double v14; // xmm1_8
  double v15; // xmm3_8
  double v16; // xmm7_8
  double v17; // xmm0_8
  double v18; // xmm7_8
  double v19; // xmm6_8
  double v20; // xmm3_8
  double v21; // xmm0_8
  double v22; // xmm6_8
  __m128d v23; // xmm7
  signed __int64 v24; // rdx
  __m128i v25; // xmm4
  double v26; // xmm1_8
  int v27; // ecx
  __int64 v28; // rax
  __int64 v29; // rcx
  double v30; // xmm2_8
  int v31; // r9d
  double v32; // xmm0_8
  double v33; // rcx
  double v34; // xmm1_8
  int v35; // r11d
  char v36; // cl
  unsigned __int64 v37; // xmm0_8
  double v38; // r11
  __m128i v39; // xmm2
  unsigned __int64 v40; // r11
  signed __int64 v41; // r10
  double v42; // xmm0_8
  double v43; // xmm1_8
  double v44; // xmm3_8
  double v45; // xmm5_8
  double v46; // xmm7_8
  double v47; // xmm2_8
  double v48; // xmm1_8
  double v49; // xmm3_8
  double v50; // xmm2_8
  double v51; // xmm5_8
  double v52; // xmm7_8
  double v53; // xmm4_8
  double v54; // rax
  double v55; // rax
  double v56; // rax
  double v57; // rax
  double v58; // rax
  unsigned int v59; // r9d
  double v60; // rax
  double v61; // r9
  bool v62; // zf
  double x; // [rsp+40h] [rbp-D8h]
  unsigned __int64 v65; // [rsp+70h] [rbp-A8h]
  unsigned __int64 v66; // [rsp+A0h] [rbp-78h]

  x = X;
  if ( (*(_QWORD *)&Y & _exp_mant_mask_0) == 0 )
    return *(double *)&_real_one_3;
  if ( *(_QWORD *)&Y != _pos_one )
  {
    v65 = _pos_zero;
    if ( (*(_QWORD *)&X & _sign_mask) != _sign_mask )
    {
      if ( *(_QWORD *)&X == _pos_one )
        return X;
      if ( *(_QWORD *)&X == _pos_zero )
        goto __x_is_zero_0;
      if ( (*(_QWORD *)&X & _exp_mask) == _exp_mask )
        goto __x_is_inf_or_nan_4;
      if ( (__int64)(*(_QWORD *)&Y & _exp_mask) <= (__int64)_ay_max_bound )
      {
        if ( (__int64)(*(_QWORD *)&Y & _exp_mask) < (__int64)_ay_min_bound )
          return Y + 1.0;
__log_x_0:
        v3 = X;
        v4 = _mm_cvtepi32_pd(_mm_sub_epi64(_mm_srli_epi64(*(__m128i *)&X, 0x34u), *(__m128i *)&_mask_1023_1)).m128d_f64[0];
        v5 = _mm_and_si128(*(__m128i *)&X, *(__m128i *)&_real_mant_2);
        if ( v4 == -1023.0 )
        {
          v39 = _mm_or_si128(v5, *(__m128i *)&_real_one_3);
          *(double *)v39.m128i_i64 = *(double *)v39.m128i_i64 - *(double *)&_real_one_3;
          v2.m128i_i64[0] = v39.m128i_i64[0];
          v5 = _mm_and_si128(v39, *(__m128i *)&_real_mant_2);
          v3 = *(double *)v5.m128i_i64;
          *(_QWORD *)&v4 = *(_OWORD *)&_mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v2, 0x34u), *(__m128i *)&_mask_2045_0));
        }
        v66 = 2 * (_mask_mant9_0 & *(_QWORD *)&v3) + (_mask_mant_all8_0 & *(_QWORD *)&v3);
        v6 = v66 >> 44;
        *(_QWORD *)&v7 = _mm_or_si128(v5, *(__m128i *)&_real_half_2).m128i_u64[0];
        *(_QWORD *)&v8 = _mm_or_si128((__m128i)v66, *(__m128i *)&_real_half_2).m128i_u64[0];
        if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(X - *(double *)&_real_one_3) & _real_notsign_1) < 0.125 )
        {
          v42 = v8;
          v43 = v8 - v7;
          v44 = _log_F_inv_head[v6] + _log_F_inv_tail[v6];
          *(_QWORD *)&v45 = COERCE_UNSIGNED_INT64(v43 * v44) & _real_fffffffff8000000;
          v46 = (v43 - v45 * v42) * v44;
          v47 = v46 + v45;
          v48 = (0.25 * v47 + 0.3333333333333333) * v47 * (v47 * v47);
          v49 = ((0.1428571428571429 * v47 + 0.1666666666666667) * v47 + 0.2) * v47 * (v47 * v47 * (v47 * v47));
          v50 = v45;
          v51 = v45 * v46 + v46 * v46 * 0.5 + v46;
          v52 = v50;
          v53 = v50 * v50 * 0.5;
          v12 = v50 + v53;
          v14 = 0.00000005769999047543285 * v4 + _log_256_tail[v6] - (v48 + v49 + v52 - v12 + v53 + v51);
          v15 = v14 - v12;
          v13 = _log_256_lead[v6];
        }
        else
        {
          v9 = v8 - v7;
          v10 = v9 * _log_F_inv_head[v6];
          v11 = v9 * _log_F_inv_tail[v6];
          v12 = v10 + v11;
          v13 = _log_256_lead[v6];
          v14 = _log_256_tail[v6]
              + 0.00000005769999047543285 * v4
              - ((0.3333333333333333 * v12 + 0.5) * (v12 * v12)
               + ((0.1666666666666667 * v12 + 0.2) * v12 + 0.25) * (v12 * v12 * (v12 * v12))
               + v11
               + v10
               - v12);
          v15 = v14 - v12;
        }
        v16 = v13 + 0.6931471228599548 * v4;
        *(_QWORD *)&v17 = COERCE_UNSIGNED_INT64(v16 + v15) & _real_fffffffff8000000;
        v18 = v16 - (v16 + v15) + v15 + v14 - (v12 + v15) + v16 + v15 - v17;
        v19 = v17 * COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&Y);
        v20 = (Y - COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&Y)) * v18
            + (Y - COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&Y)) * v17
            + v18 * COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&Y);
        v21 = v19 + v20;
        v22 = v19 - v21 + v20;
        v23 = (__m128d)_real_64_by_log2_1;
        v23.m128d_f64[0] = 92.33248261689366 * v21;
        v24 = *(_QWORD *)&v21;
        if ( 92.33248261689366 * v21 <= 65536.0 )
        {
          if ( v23.m128d_f64[0] < -68800.0 )
          {
            *(_QWORD *)&v38 = v65 | _real_zero_2;
__z_is_zero_or_inf_0:
            v59 = _flag_z_zero_0;
            if ( (*(_QWORD *)&v38 & _exp_mant_mask_0) != 0 )
              v59 = _flag_z_inf_0;
            return pow_special(x, Y, v38, v59);
          }
          v25 = _mm_cvtpd_epi32(v23);
          v26 = _mm_cvtepi32_pd(v25).m128d_f64[0];
          v27 = _mm_cvtsi128_si32(v25);
          v28 = v27 & 0x3F;
          v29 = (unsigned int)((v27 - (int)v28) >> 6);
          v31 = 0;
          if ( (int)v29 <= (int)_denormal_threshold_0 )
            v31 = v29;
          *(_QWORD *)&v33 = (v29 + 1023) << 52;
          v30 = v21 - 0.01083042426034808 * v26 + v26 * -4.359010638708991e-10 + v22;
          v32 = (0.5 * v30 + *(double *)&_real_one_3) * v30
              + (0.04166666666666666 * v30 + 0.1666666666666667) * (v30 * v30 * v30)
              + (0.001388888888888889 * v30 + 0.008333333333333333) * (v30 * v30 * (v30 * v30 * v30));
          v34 = _two_to_jby64_head_table[v28] * v32
              + _two_to_jby64_tail_table[v28] * v32
              + _two_to_jby64_tail_table[v28]
              + _two_to_jby64_head_table[v28];
          if ( *(_QWORD *)&v33 != _real_inf_4 )
          {
            if ( v31 )
            {
              v35 = 0;
              if ( v34 >= *(double *)&_real_one_3 )
                v35 = v31;
              if ( v35 == _denormal_threshold_0 )
              {
                *(_QWORD *)&X = COERCE_UNSIGNED_INT64(v34 * v33) | v65;
              }
              else
              {
                if ( v24 > (__int64)_denormal_tiny_threshold_0 )
                {
                  v37 = _real_smallest_denormal_0 | v65;
                }
                else
                {
                  v36 = v31 + 50;
                  if ( v31 + 1074 < 0 )
                    v36 = 0;
                  v37 = COERCE_UNSIGNED_INT64(v34 * COERCE_DOUBLE(1i64 << v36)) | v65;
                }
                return pow_special(x, Y, *(long double *)&v37, _flag_z_denormal_0);
              }
            }
            else
            {
              *(_QWORD *)&X = COERCE_UNSIGNED_INT64(v34 * v33) | v65;
            }
            return X;
          }
          if ( v34 < *(double *)&_real_one_3 )
          {
            *(_QWORD *)&X = *(_QWORD *)&v34 | _enable_almost_inf_0 | v65;
            return X;
          }
        }
        *(_QWORD *)&v38 = v65 | _real_inf_4;
        goto __z_is_zero_or_inf_0;
      }
      goto __ay_is_very_large_0;
    }
    if ( (__int64)(*(_QWORD *)&Y & _exp_mask) > (__int64)_ay_max_bound )
    {
__ay_is_very_large_0:
      if ( (*(_QWORD *)&X & _exp_mask) != _exp_mask )
      {
        if ( (*(_QWORD *)&X & _exp_mant_mask_0) != 0 )
        {
          if ( *(_QWORD *)&X != _neg_one )
          {
            if ( (__int64)(_exp_mant_mask_0 & *(_QWORD *)&X) < (__int64)_pos_one )
            {
              v38 = 0.0;
              if ( (*(_QWORD *)&Y & _sign_mask) != 0 )
                v38 = *(double *)&_pos_inf;
            }
            else
            {
              v38 = 0.0;
              if ( (*(_QWORD *)&Y & _sign_mask) == 0 )
                v38 = *(double *)&_pos_inf;
            }
            v58 = 0.0;
            if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
              v58 = Y;
            if ( (*(_QWORD *)&v58 & _mant_mask) != 0 )
              v38 = Y;
            if ( (*(_QWORD *)&v58 & _mant_mask) == 0 )
            {
              if ( v58 != 0.0 )
                return v38;
              goto __z_is_zero_or_inf_0;
            }
            return pow_special(X, Y, v38, _flag_y_nan_0);
          }
__x_is_neg_one_0:
          v55 = 0.0;
          v38 = Y;
          if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
            v55 = Y;
          if ( (*(_QWORD *)&v55 & _mant_mask) == 0 )
          {
            *(_QWORD *)&X = v65 | _pos_one;
            return X;
          }
          return pow_special(X, Y, v38, _flag_y_nan_0);
        }
__x_is_zero_0:
        v56 = 0.0;
        if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
        {
          v38 = Y;
          if ( *(_QWORD *)&Y == _neg_inf )
            v56 = *(double *)&_pos_inf;
          if ( *(_QWORD *)&Y != _neg_inf )
          {
            if ( (*(_QWORD *)&Y & _mant_mask) == 0 )
              return v56;
            return pow_special(X, Y, v38, _flag_y_nan_0);
          }
        }
        else
        {
          if ( (*(_QWORD *)&Y & _sign_mask) != 0 )
            v56 = *(double *)&_pos_inf;
          if ( (*(_QWORD *)&Y & _sign_mask) == 0 )
          {
            *(_QWORD *)&X = *(_QWORD *)&v56 | v65;
            return X;
          }
        }
        return pow_special(X, Y, COERCE_LONG_DOUBLE(*(_QWORD *)&v56 | v65), _flag_x_zero_z_inf_0);
      }
      goto __x_is_inf_or_nan_4;
    }
    v40 = *(_QWORD *)&Y & _exp_mant_mask_0;
    v41 = ((*(_QWORD *)&Y & _exp_mant_mask_0) >> _exp_shift) - _exp_bias;
    if ( v41 >= 0 )
    {
      if ( v41 > (__int64)_yexp_53 )
      {
__continue_after_y_int_check_0:
        if ( *(_QWORD *)&X == _neg_zero )
          goto __x_is_zero_0;
        if ( *(_QWORD *)&X == _neg_one )
          goto __x_is_neg_one_0;
        if ( (*(_QWORD *)&X & _exp_mask) != _exp_mask )
        {
          *(_OWORD *)&X = *(_QWORD *)&X & _exp_mant_mask_0;
          goto __log_x_0;
        }
__x_is_inf_or_nan_4:
        v38 = 0.0;
        if ( (*(_QWORD *)&Y & _sign_mask) == 0 )
          v38 = *(double *)&_pos_inf;
        if ( (*(_QWORD *)&X & _mant_mask) != 0 )
          v38 = X;
        if ( (*(_QWORD *)&X & _mant_mask) == 0 )
        {
          v57 = 0.0;
          if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
            v57 = Y;
          if ( (*(_QWORD *)&v57 & _mant_mask) != 0 )
            v38 = Y;
          if ( (*(_QWORD *)&v57 & _mant_mask) == 0 )
          {
            *(_QWORD *)&X = *(_QWORD *)&v38 | v65;
            return X;
          }
          return pow_special(X, Y, v38, _flag_y_nan_0);
        }
        goto __x_is_nan_0;
      }
      if ( (v40 & (_mant_full >> v41)) == 0 )
      {
        if ( (v40 & (_1_before_mant >> v41)) != 0 )
          v65 = _sign_mask;
        goto __continue_after_y_int_check_0;
      }
    }
    if ( (*(_QWORD *)&X & _exp_mask) != _exp_mask )
    {
      if ( *(_QWORD *)&X != _neg_zero )
        return pow_special(X, Y, NAN, _flag_x_neg_y_notint_0);
      goto __x_is_zero_0;
    }
    goto __x_is_inf_or_nan_4;
  }
  v54 = 0.0;
  v38 = X;
  if ( (*(_QWORD *)&X & _exp_mask) == _exp_mask )
    v54 = X;
  if ( (*(_QWORD *)&v54 & _mant_mask) != 0 )
  {
__x_is_nan_0:
    v60 = 0.0;
    if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
      v60 = Y;
    if ( (*(_QWORD *)&v60 & _mant_mask) != 0 )
    {
      v61 = Y;
      v62 = *(_QWORD *)&v38 == _ind_pattern;
      if ( *(_QWORD *)&v38 == _ind_pattern )
        v38 = Y;
      if ( !v62 )
      {
        if ( *(_QWORD *)&Y == _ind_pattern )
          v61 = v38;
        if ( (_sign_mask & *(_QWORD *)&v61) != 0 )
          v61 = v38;
        if ( (_sign_mask & *(_QWORD *)&v38) != 0 )
          v38 = v61;
      }
      return pow_special(X, Y, v38, _flag_x_nan_y_nan_0);
    }
    else
    {
      return pow_special(X, Y, v38, _flag_x_nan_4);
    }
  }
  return X;
}

