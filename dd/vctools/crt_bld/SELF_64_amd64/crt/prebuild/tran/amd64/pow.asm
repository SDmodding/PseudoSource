// File Line: 121
// RVA: 0x12B73F0
// local variable allocation has failed, the output may be wrong!
double __cdecl pow(double result, double Y)
{
  __m128i v2; // xmm5
  double v3; // r8
  double v4; // xmm6_8
  __m128i v5; // xmm2
  unsigned __int64 v6; // STA0_8
  unsigned __int64 v7; // r8
  double v8; // xmm2_8
  double v9; // xmm1_8
  double v10; // xmm1_8
  double v11; // xmm4_8
  double v12; // xmm1_8
  double v13; // xmm5_8
  double v14; // xmm7_8
  double v15; // xmm1_8
  double v16; // xmm2_8
  double v17; // xmm0_8
  double v18; // xmm1_8
  double v19; // xmm3_8
  double v20; // xmm0_8
  double v21; // xmm7_8
  double v22; // xmm0_8
  double v23; // xmm5_8
  double v24; // xmm0_8
  double v25; // xmm7_8
  double v26; // xmm6_8
  long double v27; // xmm3_8
  double v28; // xmm0_8
  double v29; // xmm6_8
  __m128d v30; // xmm7
  signed __int64 v31; // rdx
  __m128i v32; // xmm4
  double v33; // xmm1_8
  int v34; // ecx
  __int64 v35; // rax
  __int64 v36; // rcx
  double v37; // xmm2_8
  int v38; // er9
  double v39; // xmm0_8
  double v40; // rcx
  double v41; // xmm1_8
  int v42; // er11
  char v43; // cl
  unsigned __int64 v44; // xmm0_8
  double v45; // r11
  __m128i v46; // xmm2
  unsigned __int64 v47; // r11
  signed __int64 v48; // r10
  double v49; // xmm0_8
  double v50; // xmm1_8
  double v51; // xmm3_8
  double v52; // xmm4_8
  double v53; // xmm1_8
  double v54; // xmm7_8
  double v55; // xmm1_8
  double v56; // xmm2_8
  double v57; // xmm0_8
  double v58; // xmm1_8
  double v59; // xmm3_8
  double v60; // xmm0_8
  double v61; // rax
  double v62; // rax
  double v63; // rax
  double v64; // rax
  double v65; // rax
  unsigned int v66; // er9
  double v67; // rax
  double v68; // r9
  bool v69; // zf
  double x; // [rsp+40h] [rbp-D8h]
  long double y; // [rsp+50h] [rbp-C8h]
  unsigned __int64 v72; // [rsp+70h] [rbp-A8h]

  x = result;
  y = Y;
  if ( !(*(_QWORD *)&Y & _exp_mant_mask_0) )
    return *(double *)&_real_one_3;
  if ( *(_QWORD *)&Y != _pos_one )
  {
    v72 = _pos_zero;
    if ( (*(_QWORD *)&result & _sign_mask) != _sign_mask )
    {
      if ( *(_QWORD *)&result == _pos_one )
        return result;
      if ( *(_QWORD *)&result == _pos_zero )
        goto __x_is_zero_0;
      if ( (*(_QWORD *)&result & _exp_mask) == _exp_mask )
        goto __x_is_inf_or_nan_4;
      if ( (signed __int64)(*(_QWORD *)&Y & _exp_mask) <= (signed __int64)_ay_max_bound )
      {
        if ( (signed __int64)(*(_QWORD *)&Y & _exp_mask) < (signed __int64)_ay_min_bound )
          return Y + 1.0;
__log_x_0:
        v3 = result;
        *(_QWORD *)&v4 = (unsigned __int128)_mm_cvtepi32_pd(
                                              _mm_sub_epi64(
                                                _mm_srli_epi64(*(__m128i *)&result, 0x34u),
                                                *(__m128i *)&_mask_1023_1));
        v5 = _mm_and_si128(*(__m128i *)&result, *(__m128i *)&_real_mant_2);
        if ( v4 == -1023.0 )
        {
          v46 = _mm_or_si128(v5, *(__m128i *)&_real_one_3);
          *(double *)v46.m128i_i64 = *(double *)v46.m128i_i64 - *(double *)&_real_one_3;
          v2.m128i_i64[0] = v46.m128i_i64[0];
          v5 = _mm_and_si128(v46, *(__m128i *)&_real_mant_2);
          v3 = *(double *)v5.m128i_i64;
          *(_QWORD *)&v4 = (unsigned __int128)_mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v2, 0x34u), *(__m128i *)&_mask_2045_0));
        }
        v6 = 2 * (_mask_mant9_0 & *(_QWORD *)&v3) + (_mask_mant_all8_0 & *(_QWORD *)&v3);
        v7 = v6 >> 44;
        *(_QWORD *)&v8 = (unsigned __int128)_mm_or_si128(v5, *(__m128i *)&_real_half_2);
        *(_QWORD *)&v9 = (unsigned __int128)_mm_or_si128((__m128i)v6, *(__m128i *)&_real_half_2);
        if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(result - *(double *)&_real_one_3) & _real_notsign_1) < 0.125 )
        {
          v49 = v9;
          v50 = v9 - v8;
          v51 = _log_F_inv_head[v7] + _log_F_inv_tail[v7];
          *(_QWORD *)&v52 = COERCE_UNSIGNED_INT64(v50 * v51) & _real_fffffffff8000000;
          v53 = (v50 - v52 * v49) * v51;
          v54 = v53;
          v55 = v53 + v52;
          v56 = v55;
          v57 = v55 * v55;
          v58 = (0.25 * v56 + 0.3333333333333333) * v56 * (v55 * v55);
          v59 = ((0.1428571428571429 * v56 + 0.1666666666666667) * v56 + 0.2) * v56 * (v57 * v57);
          v60 = v52 * v52 * 0.5;
          v16 = v52 + v60;
          v18 = 0.00000005769999047543285 * v4
              + _log_256_tail[v7]
              - (v58
               + v59
               + v52
               - (v52
                + v60)
               + v60
               + v52 * v54
               + v54 * v54 * 0.5
               + v54);
          v19 = v18 - (v52 + v60);
          v17 = _log_256_lead[v7];
        }
        else
        {
          v10 = v9 - v8;
          v11 = v10;
          v12 = v10 * _log_F_inv_head[v7];
          v13 = v12;
          v14 = v11 * _log_F_inv_tail[v7];
          v15 = v12 + v14;
          v16 = v15;
          v17 = _log_256_lead[v7];
          v18 = _log_256_tail[v7]
              + 0.00000005769999047543285 * v4
              - ((0.3333333333333333 * v16 + 0.5) * (v15 * v15)
               + ((0.1666666666666667 * v16 + 0.2) * v16 + 0.25) * (v15 * v15 * (v15 * v15))
               + v14
               + v13
               - v16);
          v19 = v18 - v16;
        }
        v20 = v17 + 0.6931471228599548 * v4;
        v21 = v20;
        v22 = v20 + v19;
        v23 = v22;
        *(_QWORD *)&v24 = *(_QWORD *)&v22 & _real_fffffffff8000000;
        v25 = v21 - v23 + v19 + v18 - (v16 + v19) + v23 - v24;
        v26 = v24 * COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&y);
        v27 = (y - COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&y)) * v25
            + (y - COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&y)) * v24
            + v25 * COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&y);
        v28 = v24 * COERCE_DOUBLE(_real_fffffffff8000000 & *(_QWORD *)&y) + v27;
        v29 = v26 - v28 + v27;
        v30 = (__m128d)_real_64_by_log2_1;
        v30.m128d_f64[0] = 92.33248261689366 * v28;
        v31 = *(_QWORD *)&v28;
        if ( 92.33248261689366 * v28 <= 65536.0 )
        {
          if ( v30.m128d_f64[0] < -68800.0 )
          {
            *(_QWORD *)&v45 = v72 | _real_zero_2;
__z_is_zero_or_inf_0:
            v66 = _flag_z_zero_0;
            if ( *(_QWORD *)&v45 & _exp_mant_mask_0 )
              v66 = _flag_z_inf_0;
            return pow_special(x, y, v45, v66);
          }
          v32 = _mm_cvtpd_epi32(v30);
          *(_QWORD *)&v33 = (unsigned __int128)_mm_cvtepi32_pd(v32);
          v34 = _mm_cvtsi128_si32(v32);
          v35 = v34 & 0x3F;
          v36 = (unsigned int)((v34 - (signed int)v35) >> 6);
          v38 = 0;
          if ( (signed int)v36 <= (signed int)_denormal_threshold_0 )
            v38 = v36;
          *(_QWORD *)&v40 = (v36 + 1023) << 52;
          v37 = v28 - 0.01083042426034808 * v33 + v33 * -4.359010638708991e-10 + v29;
          v39 = (0.5 * v37 + *(double *)&_real_one_3) * v37
              + (0.04166666666666666 * v37 + 0.1666666666666667) * (v37 * v37 * v37)
              + (0.001388888888888889 * v37 + 0.008333333333333333) * (v37 * v37 * (v37 * v37 * v37));
          v41 = _two_to_jby64_head_table[v35] * v39
              + _two_to_jby64_tail_table[v35] * v39
              + _two_to_jby64_tail_table[v35]
              + _two_to_jby64_head_table[v35];
          if ( *(_QWORD *)&v40 != _real_inf_4 )
          {
            if ( v38 )
            {
              v42 = 0;
              if ( v41 >= *(double *)&_real_one_3 )
                v42 = v38;
              if ( v42 == _denormal_threshold_0 )
              {
                *(_QWORD *)&result = COERCE_UNSIGNED_INT64(v41 * v40) | v72;
              }
              else
              {
                if ( v31 > (signed __int64)_denormal_tiny_threshold_0 )
                {
                  v44 = _real_smallest_denormal_0 | v72;
                }
                else
                {
                  v43 = v38 + 50;
                  if ( v38 + 1074 < 0 )
                    v43 = 0;
                  v44 = COERCE_UNSIGNED_INT64(v41 * COERCE_DOUBLE(1i64 << v43)) | v72;
                }
                result = pow_special(x, y, *(long double *)&v44, _flag_z_denormal_0);
              }
            }
            else
            {
              *(_QWORD *)&result = COERCE_UNSIGNED_INT64(v41 * v40) | v72;
            }
            return result;
          }
          if ( v41 < *(double *)&_real_one_3 )
          {
            *(_QWORD *)&result = *(_QWORD *)&v41 | _enable_almost_inf_0 | v72;
            return result;
          }
        }
        *(_QWORD *)&v45 = v72 | _real_inf_4;
        goto __z_is_zero_or_inf_0;
      }
      goto __ay_is_very_large_0;
    }
    if ( (signed __int64)(*(_QWORD *)&Y & _exp_mask) > (signed __int64)_ay_max_bound )
    {
__ay_is_very_large_0:
      if ( (*(_QWORD *)&result & _exp_mask) != _exp_mask )
      {
        if ( *(_QWORD *)&result & _exp_mant_mask_0 )
        {
          if ( *(_QWORD *)&result != _neg_one )
          {
            if ( (signed __int64)(_exp_mant_mask_0 & *(_QWORD *)&result) < (signed __int64)_pos_one )
            {
              v45 = 0.0;
              if ( *(_QWORD *)&Y & _sign_mask )
                v45 = *(double *)&_pos_inf;
            }
            else
            {
              v45 = 0.0;
              if ( !(*(_QWORD *)&Y & _sign_mask) )
                v45 = *(double *)&_pos_inf;
            }
            v65 = 0.0;
            if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
              v65 = Y;
            if ( *(_QWORD *)&v65 & _mant_mask )
              v45 = Y;
            if ( !(*(_QWORD *)&v65 & _mant_mask) )
            {
              if ( v65 != 0.0 )
                return v45;
              goto __z_is_zero_or_inf_0;
            }
            return pow_special(result, Y, v45, _flag_y_nan_0);
          }
__x_is_neg_one_0:
          v62 = 0.0;
          v45 = Y;
          if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
            v62 = Y;
          if ( !(*(_QWORD *)&v62 & _mant_mask) )
          {
            *(_QWORD *)&result = v72 | _pos_one;
            return result;
          }
          return pow_special(result, Y, v45, _flag_y_nan_0);
        }
__x_is_zero_0:
        v63 = 0.0;
        if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
        {
          v45 = Y;
          if ( *(_QWORD *)&Y == _neg_inf )
            v63 = *(double *)&_pos_inf;
          if ( *(_QWORD *)&Y != _neg_inf )
          {
            if ( !(*(_QWORD *)&Y & _mant_mask) )
              return v63;
            return pow_special(result, Y, v45, _flag_y_nan_0);
          }
        }
        else
        {
          if ( *(_QWORD *)&Y & _sign_mask )
            v63 = *(double *)&_pos_inf;
          if ( !(*(_QWORD *)&Y & _sign_mask) )
          {
            *(_QWORD *)&result = *(_QWORD *)&v63 | v72;
            return result;
          }
        }
        return pow_special(result, Y, COERCE_LONG_DOUBLE(*(_QWORD *)&v63 | v72), _flag_x_zero_z_inf_0);
      }
      goto __x_is_inf_or_nan_4;
    }
    v47 = *(_QWORD *)&Y & _exp_mant_mask_0;
    v48 = ((*(_QWORD *)&Y & _exp_mant_mask_0) >> _exp_shift) - _exp_bias;
    if ( v48 >= 0 )
    {
      if ( v48 > (signed __int64)_yexp_53 )
      {
__continue_after_y_int_check_0:
        if ( *(_QWORD *)&result == _neg_zero )
          goto __x_is_zero_0;
        if ( *(_QWORD *)&result == _neg_one )
          goto __x_is_neg_one_0;
        if ( (*(_QWORD *)&result & _exp_mask) != _exp_mask )
        {
          *(_OWORD *)&result = *(_QWORD *)&result & _exp_mant_mask_0;
          goto __log_x_0;
        }
__x_is_inf_or_nan_4:
        v45 = 0.0;
        if ( !(*(_QWORD *)&Y & _sign_mask) )
          v45 = *(double *)&_pos_inf;
        if ( *(_QWORD *)&result & _mant_mask )
          v45 = result;
        if ( !(*(_QWORD *)&result & _mant_mask) )
        {
          v64 = 0.0;
          if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
            v64 = Y;
          if ( *(_QWORD *)&v64 & _mant_mask )
            v45 = Y;
          if ( !(*(_QWORD *)&v64 & _mant_mask) )
          {
            *(_QWORD *)&result = *(_QWORD *)&v45 | v72;
            return result;
          }
          return pow_special(result, Y, v45, _flag_y_nan_0);
        }
        goto __x_is_nan_0;
      }
      if ( !(v47 & (_mant_full >> v48)) )
      {
        if ( v47 & (_1_before_mant >> v48) )
          v72 = _sign_mask;
        goto __continue_after_y_int_check_0;
      }
    }
    if ( (*(_QWORD *)&result & _exp_mask) != _exp_mask )
    {
      if ( *(_QWORD *)&result != _neg_zero )
        return pow_special(result, Y, -2.696539702293474e308/*NaN*/, _flag_x_neg_y_notint_0);
      goto __x_is_zero_0;
    }
    goto __x_is_inf_or_nan_4;
  }
  v61 = 0.0;
  v45 = result;
  if ( (*(_QWORD *)&result & _exp_mask) == _exp_mask )
    v61 = result;
  if ( *(_QWORD *)&v61 & _mant_mask )
  {
__x_is_nan_0:
    v67 = 0.0;
    if ( (*(_QWORD *)&Y & _exp_mask) == _exp_mask )
      v67 = Y;
    if ( *(_QWORD *)&v67 & _mant_mask )
    {
      v68 = Y;
      v69 = *(_QWORD *)&v45 == _ind_pattern;
      if ( *(_QWORD *)&v45 == _ind_pattern )
        v45 = Y;
      if ( !v69 )
      {
        if ( *(_QWORD *)&Y == _ind_pattern )
          v68 = v45;
        if ( _sign_mask & *(_QWORD *)&v68 )
          v68 = v45;
        if ( _sign_mask & *(_QWORD *)&v45 )
          v45 = v68;
      }
      result = pow_special(result, Y, v45, _flag_x_nan_y_nan_0);
    }
    else
    {
      result = pow_special(result, Y, v45, _flag_x_nan_4);
    }
  }
  return result;
}

