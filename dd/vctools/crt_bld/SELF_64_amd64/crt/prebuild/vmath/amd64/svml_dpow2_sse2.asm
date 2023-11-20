// File Line: 16
// RVA: 0x12D3570
int _sse2_pow2(...)
{
  __m128i v2; // xmm3
  __m128i v3; // xmm2
  __m128i v4; // xmm0
  unsigned int v5; // eax
  unsigned int v6; // ecx
  __m128d v7; // xmm0
  __m128i v8; // xmm7
  int v9; // eax
  __int64 v10; // rcx
  __m128d v11; // xmm5
  __m128i v12; // xmm4
  __m128d v13; // xmm2
  int v14; // edx
  __m128d v15; // xmm3
  int v16; // eax
  __m128d v17; // xmm3
  __m128d v18; // xmm6
  __m128d v19; // xmm7
  __m128d v20; // xmm4
  __m128d v21; // xmm7
  __m128d v22; // xmm2
  __m128d v23; // xmm7
  __m128d v24; // xmm4
  __m128d v25; // xmm3
  __m128d v26; // xmm4
  __m128d v27; // xmm0
  __m128i v28; // xmm3
  __m128d v29; // xmm0
  __m128d v30; // xmm7
  __m128d v31; // xmm2
  __m128d v32; // xmm7
  __m128d v33; // xmm0
  __m128d v34; // xmm6
  __m128d v35; // xmm4
  __m128i v36; // xmm2
  __m128d v37; // xmm0
  __m128i v38; // xmm3
  int v39; // eax
  __m128i v40; // xmm2
  __m128d v41; // xmm7
  __m128d v42; // xmm0
  __m128d v43; // xmm4
  __m128d v44; // xmm3
  __m128d v45; // xmm0
  __m128d v46; // xmm5
  __m128d v47; // xmm3
  __m128d v48; // xmm5
  __m128d v49; // xmm7
  __m128d v50; // xmm5
  __m128d v51; // xmm2
  __m128i v52; // xmm7
  int v53; // eax
  __m128d v54; // xmm3
  __int64 v55; // rax
  __int64 v56; // rcx
  __m128d v57; // xmm3
  __m128d v58; // xmm2
  __m128d v59; // xmm5
  __m128d v60; // xmm0
  __m128d v61; // xmm1
  __m128d v62; // xmm4
  __m128d v63; // xmm5
  __m128i v65; // xmm5
  __m128i v66; // xmm5
  __int16 v67; // ax
  __m128i v68; // [rsp+20h] [rbp-78h]
  __m128i v69; // [rsp+30h] [rbp-68h]
  __m128i v70; // [rsp+40h] [rbp-58h]
  __m128d v71; // [rsp+50h] [rbp-48h]
  __int16 v72; // [rsp+88h] [rbp-10h]

  v2 = a1;
  v3 = a1;
  v72 = 0;
  v4 = _mm_srli_epi64(_mm_add_epi32(_mm_and_si128(a1, (__m128i)xmmword_142643A90), (__m128i)xmmword_142643AA0), 0x2Au);
  v5 = _mm_cvtsi128_si32(v4);
  v6 = _mm_extract_epi16(v4, 4);
  v68 = a2;
  v7.m128d_f64[0] = *((long double *)&s_Data + v5 + 74);
  v7.m128d_f64[1] = *((double *)&s_Data + v6 + 74);
  v8 = *((__m128i *)&s_Data + v5 + 550);
  v9 = _mm_extract_epi16(v2, 7);
  v69 = v2;
  v10 = 2 * v6;
  v11 = *(__m128d *)(&s_Data + 2 * v10 + 2200);
  v12 = _mm_or_si128(_mm_and_si128(v3, (__m128i)xmmword_14263D840), (__m128i)xmmword_14263D860);
  v70 = 0i64;
  v13 = _mm_mul_pd((__m128d)v12, v7);
  v14 = _mm_extract_epi16(v2, 3) + 2147483632;
  v15 = _mm_sub_pd(
          (__m128d)_mm_add_epi32(
                     _mm_and_si128(
                       _mm_srai_epi32(_mm_sub_epi64(v2, (__m128i)xmmword_14263D850), 0x14u),
                       (__m128i)xmmword_14263D870),
                     (__m128i)xmmword_14263D880),
          (__m128d)xmmword_14263D880);
  v16 = v9 + 2147483632;
  if ( v14 > -2147450913 || v16 > -2147450913 )
  {
    v65 = _mm_cmpeq_epi32((__m128i)0i64, v69);
    v66 = _mm_and_si128(
            _mm_and_si128(
              v65,
              _mm_and_si128(
                (__m128i)_mm_cmplt_pd((__m128d)0i64, (__m128d)a2),
                (__m128i)_mm_cmpnlt_pd(*(__m128d *)&s_Data, (__m128d)a2))),
            _mm_shuffle_epi32(v65, 177));
    v72 = _mm_movemask_epi8(v66);
    v70 = v66;
  }
  else
  {
    v17 = _mm_add_pd(v15, _mm_unpckl_pd((__m128d)v8, v11));
    v18 = _mm_shuffle_pd((__m128d)_mm_shuffle_epi32(v8, 14), v11, 2);
    v19 = (__m128d)_mm_and_si128((__m128i)xmmword_14263D890, v12);
    v20 = _mm_sub_pd((__m128d)v12, v19);
    v21 = _mm_sub_pd(_mm_mul_pd(v19, v7), v13);
    v22 = _mm_add_pd(v13, (__m128d)xmmword_14263D8A0);
    v23 = _mm_add_pd(v21, _mm_mul_pd(v20, v7));
    v24 = v17;
    v25 = _mm_add_pd(v17, v22);
    v26 = _mm_add_pd(_mm_sub_pd(v24, v25), v22);
    v27 = v25;
    v28 = (__m128i)_mm_add_pd(v25, v23);
    v29 = _mm_add_pd(_mm_sub_pd(v27, (__m128d)v28), v23);
    v30 = _mm_add_pd(v23, v22);
    v31 = v30;
    v32 = _mm_mul_pd(v30, v30);
    v33 = _mm_add_pd(_mm_add_pd(v29, v26), v18);
    v34 = (__m128d)v28;
    v35 = _mm_mul_pd(
            _mm_add_pd(
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd((__m128d)xmmword_14263D8D0, v32), (__m128d)xmmword_14263D8F0), v32),
                  (__m128d)xmmword_14263D910),
                v32),
              (__m128d)xmmword_14263D930),
            v31);
    v36 = _mm_shuffle_epi32(v28, 241);
    v37 = _mm_add_pd(
            v33,
            _mm_add_pd(
              v35,
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd((__m128d)xmmword_14263D8E0, v32), (__m128d)xmmword_14263D900), v32),
                  (__m128d)xmmword_14263D920),
                v32)));
    v38 = (__m128i)_mm_add_pd((__m128d)v28, v37);
    v39 = _mm_cvtsi128_si32(v36);
    v40 = _mm_shuffle_epi32(v36, 255);
    v41 = (__m128d)_mm_and_si128(a2, (__m128i)xmmword_14263D890);
    v42 = _mm_add_pd(v37, _mm_sub_pd(v34, (__m128d)v38));
    v43 = (__m128d)_mm_and_si128((__m128i)xmmword_14263D890, v38);
    v10 = v68.m128i_i32[1] & 0x7FF00000;
    v44 = _mm_sub_pd((__m128d)v38, v43);
    if ( (unsigned int)v10 + (v39 & 0x7FF00000) <= 0x80900000 )
    {
      v45 = _mm_mul_pd(v42, (__m128d)a2);
      v10 = a2.m128i_i32[3] & 0x7FF00000;
      if ( (unsigned int)v10 + (_mm_cvtsi128_si32(v40) & 0x7FF00000) <= 0x80900000 )
      {
        v46 = v44;
        v10 = v68.m128i_i32[1] & 0x7FFFFFFFu | a2.m128i_i32[0];
        a2 = (__m128i)_mm_sub_pd((__m128d)a2, v41);
        if ( v68.m128i_i32[1] & 0x7FFFFFFF | v68.m128i_i32[0] )
        {
          v47 = _mm_mul_pd(v44, v41);
          if ( (v68.m128i_i32[1] & 0x7FFFFFFFu) < 0x7FF00000 )
          {
            v10 = v68.m128i_i32[3] & 0x7FFFFFFFu | v68.m128i_i32[2];
            if ( v68.m128i_i32[3] & 0x7FFFFFFF | v68.m128i_i32[2] )
            {
              v48 = _mm_mul_pd(v46, (__m128d)a2);
              if ( (v68.m128i_i32[3] & 0x7FFFFFFFu) < 0x7FF00000 )
              {
                a2 = (__m128i)_mm_mul_pd((__m128d)a2, v43);
                v49 = _mm_mul_pd(v41, v43);
                v50 = _mm_add_pd(_mm_add_pd(v48, v47), (__m128d)a2);
                v51 = v49;
                v52 = (__m128i)_mm_add_pd(v49, (__m128d)xmmword_14263D8C0);
                v53 = _mm_cvtsi128_si32(v52);
                v54 = _mm_sub_pd((__m128d)xmmword_14263D8C0, (__m128d)v52);
                v10 = (_mm_extract_epi16(v52, 5) << 16) | (unsigned int)_mm_extract_epi16(v52, 4);
                if ( v53 < 130944 && (signed int)v10 < 130944 && v53 > -123392 && (signed int)v10 > -123392 )
                {
                  v55 = 2 * (v53 & 0x7Fu);
                  v56 = 2 * (unsigned int)(v10 & 0x7F);
                  v57 = _mm_add_pd(v54, v51);
                  v58.m128d_f64[0] = *((long double *)&s_Data + v55 + 3154);
                  v59 = _mm_add_pd(_mm_add_pd(v50, v45), v57);
                  v57.m128d_f64[0] = *((long double *)&s_Data + v55 + 3155);
                  v58.m128d_f64[1] = *((double *)&s_Data + v56 + 3154);
                  v57.m128d_f64[1] = *((double *)&s_Data + v56 + 3155);
                  v60 = _mm_mul_pd((__m128d)xmmword_14263D940, v59);
                  v61 = v59;
                  v62 = _mm_mul_pd((__m128d)xmmword_14263D960, v59);
                  v63 = _mm_mul_pd(v59, v59);
                  return _mm_mul_pd(
                           _mm_add_pd(
                             _mm_add_pd(
                               _mm_add_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_mul_pd(_mm_mul_pd(_mm_add_pd(v60, (__m128d)xmmword_14263D950), v63), v63),
                                     v58),
                                   v57),
                                 _mm_mul_pd(_mm_mul_pd(_mm_add_pd(v62, (__m128d)xmmword_14263D970), v63), v58)),
                               _mm_mul_pd(_mm_mul_pd(v61, (__m128d)xmmword_14263D980), v58)),
                             v58),
                           (__m128d)_mm_and_si128(
                                      _mm_add_epi32(_mm_slli_epi64(v52, 0x2Du), (__m128i)xmmword_14263D860),
                                      (__m128i)xmmword_14263D8B0));
                }
              }
            }
          }
        }
      }
    }
  }
  v67 = v72;
  if ( !(v72 & 0xF) )
  {
    a2 = (__m128i)v68.m128i_u64[0];
    TXTST1(v10);
    *(_QWORD *)&v71.m128d_f64[0] = v69.m128i_i64[0];
    v67 = v72;
  }
  if ( !(v67 & 0xF00) )
  {
    a2 = (__m128i)v68.m128i_u64[1];
    TXTST1(v10);
    *(_QWORD *)&v71.m128d_f64[1] = v69.m128i_i64[1];
  }
  return _mm_and_pd(v71, (__m128d)_mm_xor_si128(_mm_cmpeq_epi32(a2, a2), v70));
}

// File Line: 294
// RVA: 0x12D39F0
__int64 __fastcall TXTST1(double a1, double a2)
{
  signed int v2; // edx
  int v3; // ebx
  __int64 v4; // rax
  unsigned int v5; // ebp
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // edi
  int v9; // esi
  double v10; // xmm1_8
  int v11; // er15
  unsigned int v12; // er13
  int v13; // er14
  unsigned int v14; // er12
  signed int v15; // er9
  signed int v16; // er8
  signed int v17; // edi
  signed int v18; // esi
  signed __int64 v19; // rcx
  signed int v20; // ebp
  int v21; // edx
  signed __int64 v22; // rdx
  __int64 result; // rax
  __int64 v24; // rsi
  double v25; // ST28_8
  double v26; // xmm5_8
  double v27; // xmm1_8
  double v28; // ST60_8
  double v29; // xmm1_8
  double v30; // ST60_8
  double v31; // ST68_8
  double v32; // xmm7_8
  double v33; // xmm4_8
  double v34; // ST28_8
  double v35; // xmm6_8
  unsigned __int64 v36; // rbx
  signed int v37; // eax
  double v38; // xmm2_8
  double v39; // xmm1_8
  double v40; // ST28_8
  __int64 v41; // rax
  double v42; // xmm5_8
  double v43; // xmm3_8
  double v44; // xmm1_8
  double v45; // ST20_8
  double v46; // ST28_8
  double v47; // xmm6_8
  double v48; // xmm1_8
  signed int v49; // edx
  signed int v50; // ecx
  int v51; // ebx
  signed int v52; // ecx
  int v53; // ebx
  signed int v54; // [rsp+20h] [rbp-118h]
  double v55; // [rsp+28h] [rbp-110h]
  double v56; // [rsp+30h] [rbp-108h]
  int v57; // [rsp+30h] [rbp-108h]
  double v58; // [rsp+38h] [rbp-100h]
  double v59; // [rsp+40h] [rbp-F8h]
  double v60; // [rsp+48h] [rbp-F0h]
  double v61; // [rsp+88h] [rbp-B0h]
  double v62; // [rsp+140h] [rbp+8h]

  v2 = 0;
  v61 = a2;
  v3 = HIDWORD(a2);
  v62 = a1;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_30;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto _B2_30;
  v4 = *(_QWORD *)&a1 >> 32;
  v5 = HIDWORD(a1) & 0x7FFFFFFF;
  if ( (HIDWORD(a1) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_30;
  if ( v5 >= 0x100000 && (v4 & 0x80000000) != 0x80000000 )
  {
    v56 = 1.0;
    goto _B2_114;
  }
  if ( !(LODWORD(a1) | v5) )
    goto _B2_30;
  if ( (unsigned int)v4 < 0x100000 )
  {
    a1 = a1 * 4.503599627370496e15;
    v2 = 52;
    v56 = 1.0;
    LODWORD(v4) = HIDWORD(a1);
    goto _B2_114;
  }
  v6 = HIDWORD(a2) & 0x7FFFFFFF;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto LABEL_166;
  if ( v6 < 1072693248 || v6 >= 2146435072 )
    goto _B2_16;
  if ( v6 >= 1128267776 )
  {
LABEL_166:
    v8 = 2;
    goto _B2_23;
  }
  v7 = ((HIDWORD(a2) & 0x7FF00000) - 1072693248) >> 20;
  if ( v7 > 20 )
  {
    v9 = LODWORD(a2) << (v7 + 11);
    if ( !(v9 & 0x7FFFFFFF) )
    {
      v8 = ((~v9 & 0x80000000) >> 31) + 1;
      goto _B2_23;
    }
    goto _B2_16;
  }
  if ( LODWORD(a2) | (v6 << v7 << 12) )
  {
_B2_16:
    v8 = 0;
    goto _B2_23;
  }
  v8 = ((~(v6 << (v7 + 11)) & 0x80000000) >> 31) + 1;
_B2_23:
  if ( (v4 & 0x80000000) == 0x80000000 && v8 )
  {
    v10 = a1;
    a1 = 0.0 - a1;
    v55 = 0.0 - v10;
    if ( v8 == 1 )
      v56 = -1.0;
    else
      v56 = 1.0;
    LODWORD(v4) = HIDWORD(v55);
    if ( (HIDWORD(v55) & 0x7FFFFFFFu) < 0x100000 )
    {
      a1 = a1 * 4.503599627370496e15;
      v2 = 52;
      LODWORD(v4) = HIDWORD(a1);
    }
_B2_114:
    v24 = (((unsigned int)v4 & 0xFFE00) + 512) >> 10;
    *(_QWORD *)&v25 = LODWORD(a1) | ((unsigned __int64)(HIDWORD(a1) & 0xFFFFF | 0x3FF00000u) << 32);
    v26 = *((double *)&s_Data + v24 + 74);
    LODWORD(v25) = LODWORD(a1) & 0xF8000000;
    v27 = *(double *)&xmmword_14263D8A0
        + v26 * COERCE_DOUBLE(__PAIR__(HIDWORD(a1) & 0xFFFFF, LODWORD(a1)) | 0x3FF0000000000000i64);
    v58 = v26 * v25
        - v26 * COERCE_DOUBLE(__PAIR__(HIDWORD(a1) & 0xFFFFF, LODWORD(a1)) | 0x3FF0000000000000i64)
        + (COERCE_DOUBLE(__PAIR__(HIDWORD(a1) & 0xFFFFF, LODWORD(a1)) | 0x3FF0000000000000i64) - v25) * v26;
    v59 = (double)((((signed int)v4 - 1072168448) >> 20) - v2) + *((double *)&s_Data + (unsigned int)(2 * v24) + 1100);
    v60 = v59 + v27;
    result = HIDWORD(v60);
    if ( (((v3 & 0x7FF00000) - 1072693248) >> 20) + (((HIDWORD(v60) & 0x7FF00000) - 1072693248) >> 20) > 11 )
    {
      if ( (signed int)(result ^ v3) < 0 )
      {
        if ( v62 < 0.0 )
        {
          result = HIDWORD(v61) & 0x7FFFFFFF;
          if ( LODWORD(v61) | HIDWORD(v61) & 0x7FFFFFFF )
          {
            if ( (signed int)result >= 1072693248 && (signed int)result < 2146435072 && (signed int)result < 1128267776 )
            {
              v52 = (signed int)((result & 0x7FF00000) - 1072693248) >> 20;
              if ( v52 > 20 )
              {
                v53 = LODWORD(v61) << (v52 + 11);
                if ( !(v53 & 0x7FFFFFFF) )
                  v53 >= 0;
              }
              else if ( !(LODWORD(v61) | ((_DWORD)result << v52 << 12)) )
              {
                result = (unsigned int)((_DWORD)result << (v52 + 11));
                (signed int)result >= 0;
              }
            }
          }
        }
      }
      else if ( v62 < 0.0 )
      {
        result = HIDWORD(v61) & 0x7FFFFFFF;
        if ( LODWORD(v61) | HIDWORD(v61) & 0x7FFFFFFF )
        {
          if ( (signed int)result >= 1072693248 && (signed int)result < 2146435072 && (signed int)result < 1128267776 )
          {
            v50 = (signed int)((result & 0x7FF00000) - 1072693248) >> 20;
            if ( v50 > 20 )
            {
              v51 = LODWORD(v61) << (v50 + 11);
              if ( !(v51 & 0x7FFFFFFF) )
                v51 >= 0;
            }
            else if ( !(LODWORD(v61) | ((_DWORD)result << v50 << 12)) )
            {
              result = (unsigned int)((_DWORD)result << (v50 + 11));
              (signed int)result >= 0;
            }
          }
        }
      }
    }
    else
    {
      v28 = *((double *)&s_Data + (unsigned int)(2 * v24 + 1) + 1100) + v59 - v60 + v27 + v58 + v60 - (v60 + v58);
      v29 = v27 + v58;
      v30 = v28
          + ((((((*(double *)&xmmword_14263D8D0 * v29 + -1.146269986081537094e-2518) * v29
               + *(double *)&xmmword_14263D8F0)
              * v29
              + -3.2680126864983184864e-895)
             * v29
             + *(double *)&xmmword_14263D910)
            * v29
            + 4.4426331466408956363e79)
           * v29
           + *(double *)&xmmword_14263D930)
          * v29;
      v31 = v60 + v58 + v30;
      v32 = COERCE_DOUBLE(*(_QWORD *)&v31 & 0xFFFFFFFFF8000000ui64)
          * COERCE_DOUBLE(*(_QWORD *)&v61 & 0xFFFFFFFFF8000000ui64);
      v33 = *(double *)&xmmword_14263D8C0 + v32;
      v34 = *(double *)&xmmword_14263D8C0 + v32;
      v35 = (v61 - COERCE_DOUBLE(*(_QWORD *)&v61 & 0xFFFFFFFFF8000000ui64))
          * COERCE_DOUBLE(*(_QWORD *)&v31 & 0xFFFFFFFFF8000000ui64)
          + (v31 - COERCE_DOUBLE(*(_QWORD *)&v31 & 0xFFFFFFFFF8000000ui64))
          * COERCE_DOUBLE(*(_QWORD *)&v61 & 0xFFFFFFFFF8000000ui64)
          + (v31 - COERCE_DOUBLE(*(_QWORD *)&v31 & 0xFFFFFFFFF8000000ui64))
          * (v61 - COERCE_DOUBLE(*(_QWORD *)&v61 & 0xFFFFFFFFF8000000ui64));
      v36 = COERCE_UNSIGNED_INT64(*(double *)&xmmword_14263D8C0 + v32) & 0x7F;
      v37 = (signed int)(LODWORD(v34) & 0xFFFFFF80) >> 7;
      v38 = (v30 - (v31 - (v60 + v58))) * v61;
      if ( v37 >= 1023 )
      {
        if ( v37 >= 1025 )
          return HIDWORD(v56) & 0x80000000 | *(&s_Data + 1);
        --v37;
        v39 = v56 + v56;
        goto _B2_126;
      }
      if ( v37 > -964 )
      {
        v39 = v56;
_B2_126:
        HIDWORD(v46) = (v37 << 20) + 1072693248;
        result = (unsigned int)(2 * v36);
        v47 = v35 + v38 + v32 - (v33 - *(double *)&xmmword_14263D8C0);
        LODWORD(v46) = 0;
        v48 = v39
            * (((((*(double *)&xmmword_14263D940 * v47 + *(double *)&xmmword_14263D950) * v47
                + *(double *)&xmmword_14263D960)
               * v47
               + *(double *)&xmmword_14263D970)
              * v47
              + *(double *)&xmmword_14263D980)
             * *((double *)&s_Data + result + 3154)
             * v47
             + *((double *)&s_Data + (unsigned int)(2 * v36 + 1) + 3154)
             + *((double *)&s_Data + result + 3154))
            * v46;
        return result;
      }
      if ( v37 > -1076 )
      {
        HIDWORD(v40) = ((v37 + 111) << 20) + 1072693248;
        v41 = (unsigned int)(2 * v36);
        v42 = *((double *)&s_Data + v41 + 3154);
        v43 = v32 - (v33 - *(double *)&xmmword_14263D8C0) + v35 + v38;
        LODWORD(v40) = 0;
        v44 = (((*(double *)&xmmword_14263D940 * v43 + *(double *)&xmmword_14263D950) * v43
              + *(double *)&xmmword_14263D960)
             * v43
             + *(double *)&xmmword_14263D970)
            * v42
            * v43
            * v43
            + *((double *)&s_Data + (unsigned int)(2 * v36 + 1) + 3154)
            + *(double *)&xmmword_14263D980 * v43 * v42;
        v45 = v40 * v42 * (v56 * 3.851859888774472e-34);
        result = *((_QWORD *)&s_Data + v41 + 3154);
        if ( (HIDWORD(v45) & 0x7FFFFFFFu) <= 0x100000 )
          result = 0i64;
      }
      else
      {
        result = HIDWORD(v56) & 0x80000000;
      }
    }
    return result;
  }
_B2_30:
  v11 = HIDWORD(a1) & 0x7FFFFFFF;
  v12 = HIDWORD(a1) & 0x80000000;
  v13 = HIDWORD(a2) & 0x7FFFFFFF;
  v14 = HIDWORD(a2) & 0x80000000;
  if ( (HIDWORD(a1) & 0x7FFFFFFF) == 2146435072 )
  {
    v49 = 0;
    if ( !LODWORD(a1) )
      v49 = 1;
    v54 = v49;
  }
  else
  {
    v54 = 0;
  }
  if ( v13 == 2146435072 )
  {
    v15 = 0;
    if ( !LODWORD(a2) )
      v15 = 1;
  }
  else
  {
    v15 = 0;
  }
  if ( (HIDWORD(a1) & 0x7FF00000) == 2146435072 )
  {
    v16 = 0;
    if ( !v54 )
      v16 = 1;
  }
  else
  {
    v16 = 0;
  }
  if ( (HIDWORD(a2) & 0x7FF00000) == 2146435072 )
  {
    v17 = 0;
    if ( !v15 )
      v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  v18 = 0;
  if ( !(LODWORD(a1) | v11) )
    v18 = 1;
  v19 = 0i64;
  if ( !(v17 | v15) )
    v19 = 1i64;
  v57 = v19;
  if ( v11 == 1072693248 )
  {
    v20 = 0;
    if ( !LODWORD(a1) )
      v20 = 1;
  }
  else
  {
    v20 = 0;
  }
  v21 = HIDWORD(a2) & 0x7FFFFFFF;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto LABEL_167;
  if ( v21 < 1072693248 || v21 >= 2146435072 )
    goto _B2_47;
  if ( v21 >= 1128267776 )
  {
LABEL_167:
    v22 = 2i64;
    goto _B2_54;
  }
  v19 = (unsigned int)(((HIDWORD(a2) & 0x7FF00000) - 1072693248) >> 20);
  if ( (signed int)v19 > 20 )
  {
    v19 = (unsigned int)(v19 + 11);
    if ( !((LODWORD(a2) << v19) & 0x7FFFFFFF) )
    {
      v22 = ((~(LODWORD(a2) << v19) & 0x80000000) >> 31) + 1;
      goto _B2_54;
    }
    goto _B2_47;
  }
  if ( LODWORD(a2) | (v21 << v19 << 12) )
  {
_B2_47:
    v22 = 0i64;
    goto _B2_54;
  }
  v19 = (unsigned int)(v19 + 11);
  v22 = ((~(v21 << v19) & 0x80000000) >> 31) + 1;
_B2_54:
  result = v11 > 1072693248 || v11 == 1072693248 && LODWORD(a1);
  if ( !(LODWORD(a2) | v13) )
    return result;
  if ( v12 )
  {
    if ( v20 && v15 )
      return result;
  }
  else if ( v20 )
  {
    return result;
  }
  if ( v16 || v17 )
    return result;
  if ( v18 && v14 && v15 )
    return raise_zerodivide(v19, v22);
  if ( (_DWORD)result )
  {
    if ( v14 )
    {
      if ( v15 )
        return result;
    }
    else if ( v15 )
    {
      return result;
    }
  }
  if ( v11 < 1072693248 )
  {
    if ( v14 )
    {
      if ( v15 )
        return result;
    }
    else if ( v15 )
    {
      return result;
    }
  }
  if ( v12 )
  {
    if ( v54 )
    {
      if ( !v14 )
        (_DWORD)v22 == 1;
      return result;
    }
    if ( !v57 || (_DWORD)v22 )
    {
      if ( !v18 )
        return result;
    }
    else if ( !v18 )
    {
      return TXTST3();
    }
    if ( !v14 )
    {
      if ( (_DWORD)v22 == 1 )
        return result;
      goto _B2_105;
    }
    if ( (_DWORD)v22 == 1 )
      return ((__int64 (*)(void))raise_zerodivide)();
    return raise_zerodivide(v19, v22);
  }
  if ( v54 )
  {
    !v14;
    return result;
  }
  if ( v18 )
  {
    if ( v14 )
      return raise_zerodivide(v19, v22);
_B2_105:
    !v57;
  }
  return result;
} ( !v18 )
    {
      return TXTST3();
    }
    if ( !v14 )
    {
      if ( (_DWORD)v22 == 1 )
        return result;
      goto _B2_105;
    }
    if ( (_DWORD)v22 == 1 )
      return ((__int64 (*)(void))raise_

// File Line: 1420
// RVA: 0x12D4790
int raise_zerodivide(...)
{
  return COERCE_FLOAT((unsigned int)*(_OWORD *)&_mm_cmpeq_epi32(a1, a1) << 28) / 0.0;
}

// File Line: 1447
// RVA: 0x12D47B0
float TXTST3()
{
  float v0; // xmm0_4

  LODWORD(v0) = (unsigned __int128)_mm_cvtsi32_si128(0xFF8FFFFF);
  return v0 + v0;
}

