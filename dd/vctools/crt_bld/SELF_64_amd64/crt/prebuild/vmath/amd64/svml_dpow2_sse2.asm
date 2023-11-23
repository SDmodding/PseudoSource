// File Line: 16
// RVA: 0x12D3570
// local variable allocation has failed, the output may be wrong!
__m128d __fastcall _sse2_pow2(double a1, double a2)
{
  __m128i v2; // xmm3
  __m128i v3; // xmm2
  __m128i v4; // xmm0
  unsigned int v5; // eax
  unsigned int epi16; // ecx
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
  __m128d v30; // xmm2
  __m128d v31; // xmm7
  __m128d v32; // xmm0
  __m128d v33; // xmm6
  __m128d v34; // xmm4
  __m128i v35; // xmm2
  __m128d v36; // xmm0
  __m128i v37; // xmm3
  int v38; // eax
  __m128i v39; // xmm2
  __m128d v40; // xmm7
  __m128d v41; // xmm0
  __m128d v42; // xmm4
  __m128d v43; // xmm3
  __m128d v44; // xmm0
  __m128d v45; // xmm5
  __m128d v46; // xmm1
  __m128d v47; // xmm3
  __m128d v48; // xmm5
  __m128d v49; // xmm5
  __m128d v50; // xmm2
  __m128i v51; // xmm7
  int v52; // eax
  __m128d v53; // xmm3
  __int64 v54; // rax
  __int64 v55; // rcx
  __m128d v56; // xmm3
  __m128d v57; // xmm2
  __m128d v58; // xmm5
  __m128d v59; // xmm0
  __m128d v60; // xmm1
  __m128d v61; // xmm4
  __m128d v62; // xmm5
  __m128i v64; // xmm5
  __m128i v65; // xmm5
  __int16 v66; // ax
  __int128 v67; // [rsp+20h] [rbp-78h]
  __m128i v68; // [rsp+30h] [rbp-68h]
  __m128i v69; // [rsp+40h] [rbp-58h]
  __m128d v70; // [rsp+50h] [rbp-48h]
  __int16 v71; // [rsp+88h] [rbp-10h]

  v2 = *(__m128i *)&a1;
  v3 = *(__m128i *)&a1;
  v71 = 0;
  v4 = _mm_srli_epi64(
         _mm_add_epi32(_mm_and_si128(*(__m128i *)&a1, (__m128i)xmmword_142643A90), (__m128i)xmmword_142643AA0),
         0x2Au);
  v5 = _mm_cvtsi128_si32(v4);
  epi16 = _mm_extract_epi16(v4, 4);
  v67 = *(_OWORD *)&a2;
  v7.m128d_f64[0] = *((long double *)&s_Data + v5 + 74);
  v7.m128d_f64[1] = *((double *)&s_Data + epi16 + 74);
  v8 = *((__m128i *)&s_Data + v5 + 550);
  v9 = _mm_extract_epi16(v2, 7);
  v68 = v2;
  v10 = 2 * epi16;
  v11 = *(__m128d *)(&s_Data + 2 * v10 + 2200);
  v12 = _mm_or_si128(_mm_and_si128(v3, (__m128i)xmmword_14263D840), (__m128i)xmmword_14263D860);
  v69 = 0i64;
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
    v64 = _mm_cmpeq_epi32((__m128i)0i64, v68);
    v65 = _mm_and_si128(
            _mm_and_si128(
              v64,
              _mm_and_si128(
                (__m128i)_mm_cmplt_pd((__m128d)0i64, *(__m128d *)&a2),
                (__m128i)_mm_cmpnlt_pd(*(__m128d *)&s_Data, *(__m128d *)&a2))),
            _mm_shuffle_epi32(v64, 177));
    v71 = _mm_movemask_epi8(v65);
    v69 = v65;
  }
  else
  {
    v17 = _mm_add_pd(v15, _mm_unpacklo_pd((__m128d)v8, v11));
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
    v29 = _mm_add_pd(_mm_add_pd(_mm_sub_pd(v27, (__m128d)v28), v23), v26);
    v30 = _mm_add_pd(v23, v22);
    v31 = _mm_mul_pd(v30, v30);
    v32 = _mm_add_pd(v29, v18);
    v33 = (__m128d)v28;
    v34 = _mm_mul_pd(
            _mm_add_pd(
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd((__m128d)xmmword_14263D8D0, v31), (__m128d)xmmword_14263D8F0), v31),
                  (__m128d)xmmword_14263D910),
                v31),
              (__m128d)xmmword_14263D930),
            v30);
    v35 = _mm_shuffle_epi32(v28, 241);
    v36 = _mm_add_pd(
            v32,
            _mm_add_pd(
              v34,
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd((__m128d)xmmword_14263D8E0, v31), (__m128d)xmmword_14263D900), v31),
                  (__m128d)xmmword_14263D920),
                v31)));
    v37 = (__m128i)_mm_add_pd((__m128d)v28, v36);
    v38 = _mm_cvtsi128_si32(v35);
    v39 = _mm_shuffle_epi32(v35, 255);
    v40 = (__m128d)_mm_and_si128(*(__m128i *)&a2, (__m128i)xmmword_14263D890);
    v41 = _mm_add_pd(v36, _mm_sub_pd(v33, (__m128d)v37));
    v42 = (__m128d)_mm_and_si128((__m128i)xmmword_14263D890, v37);
    v10 = HIDWORD(a2) & 0x7FF00000;
    v43 = _mm_sub_pd((__m128d)v37, v42);
    if ( (unsigned int)v10 + (v38 & 0x7FF00000) <= 0x80900000 )
    {
      v44 = _mm_mul_pd(v41, *(__m128d *)&a2);
      v10 = *((_DWORD *)&a2 + 3) & 0x7FF00000;
      if ( (unsigned int)v10 + (_mm_cvtsi128_si32(v39) & 0x7FF00000) <= 0x80900000 )
      {
        v45 = v43;
        v10 = HIDWORD(a2) & 0x7FFFFFFFu | LODWORD(a2);
        v46 = _mm_sub_pd(*(__m128d *)&a2, v40);
        if ( DWORD1(v67) & 0x7FFFFFFF | (unsigned int)v67 )
        {
          v47 = _mm_mul_pd(v43, v40);
          if ( (DWORD1(v67) & 0x7FFFFFFFu) < 0x7FF00000 )
          {
            v10 = HIDWORD(v67) & 0x7FFFFFFFu | DWORD2(v67);
            if ( HIDWORD(v67) & 0x7FFFFFFF | DWORD2(v67) )
            {
              v48 = _mm_mul_pd(v45, v46);
              if ( (HIDWORD(v67) & 0x7FFFFFFFu) < 0x7FF00000 )
              {
                v49 = _mm_add_pd(_mm_add_pd(v48, v47), _mm_mul_pd(v46, v42));
                v50 = _mm_mul_pd(v40, v42);
                v51 = (__m128i)_mm_add_pd(v50, (__m128d)xmmword_14263D8C0);
                v52 = _mm_cvtsi128_si32(v51);
                v53 = _mm_sub_pd((__m128d)xmmword_14263D8C0, (__m128d)v51);
                v10 = (_mm_extract_epi16(v51, 5) << 16) | (unsigned int)_mm_extract_epi16(v51, 4);
                if ( v52 < 130944 && (int)v10 < 130944 && v52 > -123392 && (int)v10 > -123392 )
                {
                  v54 = 2 * (v52 & 0x7Fu);
                  v55 = 2 * (unsigned int)(v10 & 0x7F);
                  v56 = _mm_add_pd(v53, v50);
                  v57.m128d_f64[0] = *((long double *)&s_Data + v54 + 3154);
                  v58 = _mm_add_pd(_mm_add_pd(v49, v44), v56);
                  v56.m128d_f64[0] = *((long double *)&s_Data + v54 + 3155);
                  v57.m128d_f64[1] = *((double *)&s_Data + v55 + 3154);
                  v56.m128d_f64[1] = *((double *)&s_Data + v55 + 3155);
                  v59 = _mm_mul_pd((__m128d)xmmword_14263D940, v58);
                  v60 = v58;
                  v61 = _mm_mul_pd((__m128d)xmmword_14263D960, v58);
                  v62 = _mm_mul_pd(v58, v58);
                  return _mm_mul_pd(
                           _mm_add_pd(
                             _mm_add_pd(
                               _mm_add_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_mul_pd(_mm_mul_pd(_mm_add_pd(v59, (__m128d)xmmword_14263D950), v62), v62),
                                     v57),
                                   v56),
                                 _mm_mul_pd(_mm_mul_pd(_mm_add_pd(v61, (__m128d)xmmword_14263D970), v62), v57)),
                               _mm_mul_pd(_mm_mul_pd(v60, (__m128d)xmmword_14263D980), v57)),
                             v57),
                           (__m128d)_mm_and_si128(
                                      _mm_add_epi32(_mm_slli_epi64(v51, 0x2Du), (__m128i)xmmword_14263D860),
                                      (__m128i)xmmword_14263D8B0));
                }
              }
            }
          }
        }
      }
    }
  }
  v66 = v71;
  if ( (v71 & 0xF) == 0 )
  {
    v70.m128d_f64[0] = TXTST1(v10);
    v66 = v71;
  }
  if ( (v66 & 0xF00) == 0 )
    v70.m128d_f64[1] = TXTST1(v10);
  return _mm_and_pd(v70, (__m128d)_mm_xor_si128((__m128i)-1i64, v69));
}

// File Line: 294
// RVA: 0x12D39F0
// local variable allocation has failed, the output may be wrong!
__m128 __fastcall TXTST1(double a1, double a2)
{
  int v2; // edx
  int v3; // ebx
  __int64 v4; // rax
  unsigned int v5; // ebp
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // edi
  int v9; // esi
  int v10; // r15d
  unsigned int v11; // r13d
  int v12; // r14d
  unsigned int v13; // r12d
  BOOL v14; // r9d
  BOOL v15; // r8d
  BOOL v16; // edi
  __int64 v17; // rcx
  BOOL v18; // ebp
  int v19; // edx
  __int64 v20; // rdx
  BOOL v21; // eax
  __int64 v22; // rsi
  double v23; // xmm5_8
  double v24; // xmm1_8
  double v25; // xmm1_8
  double v26; // xmm7_8
  double v27; // xmm4_8
  double v28; // xmm6_8
  unsigned __int64 v29; // rbx
  int v30; // eax
  double v31; // xmm2_8
  __int64 v32; // rax
  double v33; // xmm6_8
  double v34; // xmm7_8
  __int128 v35; // xmm5
  double v36; // xmm3_8
  double v37; // xmm10_8
  double v38; // xmm4_8
  double v39; // xmm9_8
  double v40; // xmm8_8
  __int64 v41; // rax
  double v42; // xmm2_8
  double v43; // xmm15_8
  double v44; // xmm2_8
  double v45; // xmm6_8
  int v47; // eax
  int v48; // ecx
  int v49; // ebx
  int v50; // eax
  int v51; // ecx
  int v52; // ebx
  BOOL v53; // [rsp+20h] [rbp-118h]
  double v54; // [rsp+20h] [rbp-118h]
  unsigned __int64 v55; // [rsp+20h] [rbp-118h]
  double v56; // [rsp+20h] [rbp-118h]
  __int64 v57; // [rsp+20h] [rbp-118h]
  double v58; // [rsp+28h] [rbp-110h]
  double v59; // [rsp+28h] [rbp-110h]
  double v60; // [rsp+28h] [rbp-110h]
  double v61; // [rsp+28h] [rbp-110h]
  double v62; // [rsp+28h] [rbp-110h]
  double v63; // [rsp+28h] [rbp-110h]
  double v64; // [rsp+28h] [rbp-110h]
  double v65; // [rsp+30h] [rbp-108h]
  double v66; // [rsp+38h] [rbp-100h]
  double v67; // [rsp+40h] [rbp-F8h]
  double v68; // [rsp+48h] [rbp-F0h]
  double v69; // [rsp+60h] [rbp-D8h]
  double v70; // [rsp+60h] [rbp-D8h]
  double v71; // [rsp+68h] [rbp-D0h]
  double v72; // [rsp+88h] [rbp-B0h]
  int v73; // [rsp+144h] [rbp+Ch]

  v2 = 0;
  v72 = a2;
  v3 = HIDWORD(a2);
  v73 = HIDWORD(a1);
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_30;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto _B2_30;
  v4 = HIDWORD(*(_QWORD *)&a1);
  v5 = HIDWORD(a1) & 0x7FFFFFFF;
  if ( (HIDWORD(a1) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_30;
  if ( v5 >= 0x100000 && (HIDWORD(a1) & 0x80000000) != 0x80000000 )
  {
    v65 = 1.0;
    goto _B2_114;
  }
  if ( !(LODWORD(a1) | v5) )
    goto _B2_30;
  if ( HIDWORD(a1) < 0x100000 )
  {
    a1 = a1 * 4.503599627370496e15;
    v2 = 52;
    v65 = 1.0;
    LODWORD(v4) = HIDWORD(a1);
_B2_114:
    LODWORD(v54) = LODWORD(a1);
    v22 = (((unsigned int)v4 & 0xFFE00) + 512) >> 10;
    HIDWORD(v54) = HIDWORD(a1) & 0xFFFFF | 0x3FF00000;
    *(_QWORD *)&v59 = LODWORD(a1) | ((unsigned __int64)HIDWORD(v54) << 32);
    v23 = *((double *)&s_Data + v22 + 74);
    LODWORD(v59) = LODWORD(a1) & 0xF8000000;
    v24 = v23 * v54 + -1.442694902420044;
    v66 = v23 * v59 - v23 * v54 + (v54 - v59) * v23;
    v67 = (double)((((int)v4 - 1072168448) >> 20) - v2) + *((double *)&s_Data + (unsigned int)(2 * v22) + 1100);
    v68 = v67 + v24;
    if ( (((v3 & 0x7FF00000) - 1072693248) >> 20) + (((HIDWORD(v68) & 0x7FF00000) - 1072693248) >> 20) <= 11 )
    {
      v69 = *((double *)&s_Data + (unsigned int)(2 * v22 + 1) + 1100) + v67 - v68 + v24 + v66 + v68 - (v68 + v66);
      v25 = v24 + v66;
      v70 = v69
          + ((((((0.01584364190639705 * v25 + -0.02666713164981555) * v25 + 0.04616704187202374) * v25
              + -0.08325619496072671)
             * v25
             + 0.160151050752973)
            * v25
            + -0.3465736568077919)
           * v25
           + 0.00000009597935033233511)
          * v25;
      v71 = v68 + v66 + v70;
      v26 = COERCE_DOUBLE(*(_QWORD *)&v71 & 0xFFFFFFFFF8000000ui64)
          * COERCE_DOUBLE(*(_QWORD *)&v72 & 0xFFFFFFFFF8000000ui64);
      v27 = v26 + 5.2776558133248e13;
      v60 = v26 + 5.2776558133248e13;
      v28 = (v72 - COERCE_DOUBLE(*(_QWORD *)&v72 & 0xFFFFFFFFF8000000ui64))
          * COERCE_DOUBLE(*(_QWORD *)&v71 & 0xFFFFFFFFF8000000ui64)
          + (v71 - COERCE_DOUBLE(*(_QWORD *)&v71 & 0xFFFFFFFFF8000000ui64))
          * COERCE_DOUBLE(*(_QWORD *)&v72 & 0xFFFFFFFFF8000000ui64)
          + (v71 - COERCE_DOUBLE(*(_QWORD *)&v71 & 0xFFFFFFFFF8000000ui64))
          * (v72 - COERCE_DOUBLE(*(_QWORD *)&v72 & 0xFFFFFFFFF8000000ui64));
      v29 = COERCE_UNSIGNED_INT64(v26 + 5.2776558133248e13) & 0x7F;
      v30 = (int)(LODWORD(v60) & 0xFFFFFF80) >> 7;
      v31 = (v70 - (v71 - (v68 + v66))) * v72;
      if ( v30 >= 1023 )
      {
        if ( v30 >= 1025 )
        {
          LODWORD(v55) = s_Data;
          HIDWORD(v55) = HIDWORD(v65) & 0x80000000 | *(&s_Data + 1);
          *(_OWORD *)&a2 = v55;
          return *(__m128 *)&a2;
        }
        *(_OWORD *)&a2 = *(unsigned __int64 *)&v65;
        --v30;
        a2 = a2 + a2;
_B2_126:
        HIDWORD(v64) = (v30 << 20) + 1072693248;
        v45 = v28 + v31 + v26 - (v27 - 5.2776558133248e13);
        LODWORD(v64) = 0;
        a2 = a2
           * (((((0.001333355814642844 * v45 + 0.009618129107628477) * v45 + 0.05550410866482158) * v45
              + 0.2402265069591007)
             * v45
             + 0.6931471805599453)
            * *((double *)&s_Data + (unsigned int)(2 * v29) + 3154)
            * v45
            + *((double *)&s_Data + (unsigned int)(2 * v29 + 1) + 3154)
            + *((double *)&s_Data + (unsigned int)(2 * v29) + 3154))
           * v64;
        return *(__m128 *)&a2;
      }
      if ( v30 > -964 )
      {
        *(_OWORD *)&a2 = *(unsigned __int64 *)&v65;
        goto _B2_126;
      }
      if ( v30 > -1076 )
      {
        HIDWORD(v61) = ((v30 + 111) << 20) + 1072693248;
        v32 = (unsigned int)(2 * v29);
        v33 = v28 + v31;
        v34 = v26 - (v27 - 5.2776558133248e13);
        v35 = *((unsigned __int64 *)&s_Data + v32 + 3154);
        v36 = v34 + v33;
        v37 = (0.001333355814642844 * (v34 + v33) + 0.009618129107628477) * (v34 + v33) + 0.05550410866482158;
        *(&a2 + 1) = 0.0;
        v38 = *((double *)&s_Data + (unsigned int)(2 * v29 + 1) + 3154);
        LODWORD(v61) = 0;
        a2 = (v37 * (v34 + v33) + 0.2402265069591007) * *(double *)&v35 * (v34 + v33) * (v34 + v33)
           + v38
           + 0.6931471805599453 * (v34 + v33) * *(double *)&v35;
        v39 = v65 * 3.851859888774472e-34;
        v40 = v61;
        v56 = v61 * *(double *)&v35 * (v65 * 3.851859888774472e-34);
        v41 = *((_QWORD *)&s_Data + v32 + 3154);
        if ( (HIDWORD(v56) & 0x7FFFFFFFu) <= 0x100000 )
        {
          HIWORD(v57) = HIWORD(v41);
          HIDWORD(v63) = HIDWORD(a2);
          LODWORD(v63) = 0;
          a2 = (a2
              - v63
              + *(double *)&v35
              - COERCE_DOUBLE(v57 & 0xFFFF000000000000ui64)
              + v63
              + COERCE_DOUBLE(v57 & 0xFFFF000000000000ui64))
             * v40
             * v39;
        }
        else
        {
          HIDWORD(v62) = HIDWORD(v41);
          v42 = (v37 * v36 + 0.2402265069591007) * v36 + 0.6931471805599453;
          v43 = v36 * v42 * v38;
          LODWORD(v62) = 0;
          v44 = v42 * (v34 - v36 + v33)
              + v36 * v42
              - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v36 * v42) & 0xFFFFFFFFFF000000ui64)
              + COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v36 * v42) & 0xFFFFFFFFFF000000ui64);
          *(&a2 + 1) = *((double *)&v35 + 1);
          a2 = ((*(double *)&v35 - v62) * v44 + v44 * v62 + v38 + v43 + *(double *)&v35) * (v39 * v40);
        }
      }
      else
      {
        *(_OWORD *)&a2 = *(_QWORD *)&v65 & 0x8000000000000000ui64;
      }
      return *(__m128 *)&a2;
    }
    if ( (HIDWORD(v68) ^ v3) >= 0 )
    {
      if ( v73 < 0 )
      {
        v47 = HIDWORD(v72) & 0x7FFFFFFF;
        if ( LODWORD(v72) | HIDWORD(v72) & 0x7FFFFFFF )
        {
          if ( (HIDWORD(v72) & 0x7FFFFFFFu) < 0x3FF00000 || (HIDWORD(v72) & 0x7FFFFFFFu) >= 0x7FF00000 )
            goto _B2_154;
          if ( (HIDWORD(v72) & 0x7FFFFFFFu) < 0x43400000 )
          {
            v48 = ((HIDWORD(v72) & 0x7FF00000) - 1072693248) >> 20;
            if ( v48 <= 20 )
            {
              if ( !(LODWORD(v72) | (v47 << v48 << 12)) )
              {
                if ( v47 << (v48 + 11) < 0 )
                {
                  *(_OWORD *)&a2 = 0xFFF0000000000000ui64;
                  return *(__m128 *)&a2;
                }
                goto _B2_144;
              }
_B2_154:
              *(_OWORD *)&a2 = 0xFFF8000000000000ui64;
              return *(__m128 *)&a2;
            }
            v49 = LODWORD(v72) << (v48 + 11);
            if ( (v49 & 0x7FFFFFFF) != 0 )
              goto _B2_154;
            if ( v49 < 0 )
            {
              *(_OWORD *)&a2 = 0xFFF0000000000000ui64;
              return *(__m128 *)&a2;
            }
          }
        }
      }
_B2_144:
      *(_OWORD *)&a2 = *(unsigned __int64 *)&s_Data;
      return *(__m128 *)&a2;
    }
    if ( v73 >= 0 )
    {
      *(_OWORD *)&a2 = 0i64;
      return *(__m128 *)&a2;
    }
    v50 = HIDWORD(v72) & 0x7FFFFFFF;
    if ( LODWORD(v72) | HIDWORD(v72) & 0x7FFFFFFF )
    {
      if ( (HIDWORD(v72) & 0x7FFFFFFFu) < 0x3FF00000 || (HIDWORD(v72) & 0x7FFFFFFFu) >= 0x7FF00000 )
        goto _B2_154;
      if ( (HIDWORD(v72) & 0x7FFFFFFFu) < 0x43400000 )
      {
        v51 = ((HIDWORD(v72) & 0x7FF00000) - 1072693248) >> 20;
        if ( v51 > 20 )
        {
          v52 = LODWORD(v72) << (v51 + 11);
          if ( (v52 & 0x7FFFFFFF) != 0 )
            goto _B2_154;
          if ( v52 < 0 )
          {
            *(_OWORD *)&a2 = 0x8000000000000000ui64;
            return *(__m128 *)&a2;
          }
        }
        else
        {
          if ( LODWORD(v72) | (v50 << v51 << 12) )
            goto _B2_154;
          if ( v50 << (v51 + 11) < 0 )
          {
            *(_OWORD *)&a2 = 0x8000000000000000ui64;
            return *(__m128 *)&a2;
          }
        }
      }
    }
_B2_75:
    *(_OWORD *)&a2 = 0i64;
    return *(__m128 *)&a2;
  }
  v6 = HIDWORD(a2) & 0x7FFFFFFF;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto _B2_22;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) < 0x3FF00000 || (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_16;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x43400000 )
  {
_B2_22:
    v8 = 2;
    goto _B2_23;
  }
  v7 = ((HIDWORD(a2) & 0x7FF00000) - 1072693248) >> 20;
  if ( v7 > 20 )
  {
    v9 = LODWORD(a2) << (v7 + 11);
    if ( (v9 & 0x7FFFFFFF) == 0 )
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
  if ( (HIDWORD(a1) & 0x80000000) == 0x80000000 && v8 )
  {
    a1 = 0.0 - a1;
    v58 = a1;
    if ( v8 == 1 )
      v65 = -1.0;
    else
      v65 = 1.0;
    LODWORD(v4) = HIDWORD(v58);
    if ( (HIDWORD(v58) & 0x7FFFFFFFu) < 0x100000 )
    {
      a1 = a1 * 4.503599627370496e15;
      v2 = 52;
      LODWORD(v4) = HIDWORD(a1);
    }
    goto _B2_114;
  }
_B2_30:
  v10 = HIDWORD(a1) & 0x7FFFFFFF;
  v11 = HIDWORD(a1) & 0x80000000;
  v12 = HIDWORD(a2) & 0x7FFFFFFF;
  v13 = HIDWORD(a2) & 0x80000000;
  v53 = (HIDWORD(a1) & 0x7FFFFFFF) == 2146435072 && LODWORD(a1) == 0;
  v14 = v12 == 2146435072 && LODWORD(a2) == 0;
  v15 = (HIDWORD(a1) & 0x7FF00000) == 2146435072 && !v53;
  v16 = (HIDWORD(a2) & 0x7FF00000) == 2146435072 && !v14;
  v17 = !v16 && !v14;
  v18 = v10 == 1072693248 && LODWORD(a1) == 0;
  v19 = HIDWORD(a2) & 0x7FFFFFFF;
  if ( !(LODWORD(a2) | HIDWORD(a2) & 0x7FFFFFFF) )
    goto _B2_53;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) < 0x3FF00000 || (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x7FF00000 )
    goto _B2_47;
  if ( (HIDWORD(a2) & 0x7FFFFFFFu) >= 0x43400000 )
  {
_B2_53:
    v20 = 2i64;
    goto _B2_54;
  }
  v17 = (unsigned int)(((HIDWORD(a2) & 0x7FF00000) - 1072693248) >> 20);
  if ( (int)v17 > 20 )
  {
    v17 = (unsigned int)(v17 + 11);
    if ( ((LODWORD(a2) << v17) & 0x7FFFFFFF) == 0 )
    {
      v20 = ((~(LODWORD(a2) << v17) & 0x80000000) >> 31) + 1;
      goto _B2_54;
    }
    goto _B2_47;
  }
  if ( LODWORD(a2) | (v19 << v17 << 12) )
  {
_B2_47:
    v20 = 0i64;
    goto _B2_54;
  }
  v17 = (unsigned int)(v17 + 11);
  v20 = ((~(v19 << v17) & 0x80000000) >> 31) + 1;
_B2_54:
  v21 = (HIDWORD(a1) & 0x7FFFFFFFu) > 0x3FF00000 || v10 == 1072693248 && LODWORD(a1);
  if ( !(LODWORD(a2) | v12) )
    goto _B2_61;
  if ( v11 )
  {
    if ( v18 && v14 )
    {
      *(_OWORD *)&a2 = *(unsigned __int64 *)&2il0floatpacket_16;
      return *(__m128 *)&a2;
    }
  }
  else if ( v18 )
  {
_B2_61:
    *(_OWORD *)&a2 = *(unsigned __int64 *)&2il0floatpacket_16;
    return *(__m128 *)&a2;
  }
  if ( v15 )
  {
    *(_OWORD *)&a2 = *(_OWORD *)&a1;
    return *(__m128 *)&a2;
  }
  if ( !v16 )
  {
    if ( !(LODWORD(a1) | v10) && v13 && v14 )
      goto _B2_102;
    if ( v21 )
    {
      if ( v13 )
      {
        if ( v14 )
          goto _B2_75;
      }
      else if ( v14 )
      {
_B2_73:
        *(_OWORD *)&a2 = *(unsigned __int64 *)&INF_c_1080_0_4;
        return *(__m128 *)&a2;
      }
    }
    if ( (HIDWORD(a1) & 0x7FFFFFFFu) < 0x3FF00000 )
    {
      if ( v13 )
      {
        if ( v14 )
        {
          *(_OWORD *)&a2 = *(unsigned __int64 *)&INF_c_1080_0_4;
          return *(__m128 *)&a2;
        }
      }
      else if ( v14 )
      {
        *(_OWORD *)&a2 = 0i64;
        return *(__m128 *)&a2;
      }
    }
    if ( !v11 )
    {
      if ( v53 )
      {
        if ( v13 )
        {
          *(_OWORD *)&a2 = 0i64;
          return *(__m128 *)&a2;
        }
        goto _B2_73;
      }
      if ( LODWORD(a1) | v10 )
        goto _B2_75;
      if ( v13 )
      {
_B2_102:
        raise_zerodivide(v17, v20);
        *(_OWORD *)&a2 = *(unsigned __int64 *)&INF_c_1080_0_4;
        return *(__m128 *)&a2;
      }
_B2_105:
      if ( !v16 && !v14 )
      {
        *(_OWORD *)&a2 = 0i64;
        return *(__m128 *)&a2;
      }
      goto _B2_75;
    }
    if ( v53 )
    {
      if ( v13 )
      {
        *(_OWORD *)&a2 = *(unsigned __int64 *)&2il0floatpacket_15;
        if ( (_DWORD)v20 != 1 )
          *(_OWORD *)&a2 = 0i64;
        return *(__m128 *)&a2;
      }
      if ( (_DWORD)v20 != 1 )
      {
        *(_OWORD *)&a2 = *(unsigned __int64 *)&INF_c_1080_0_4;
        return *(__m128 *)&a2;
      }
    }
    else
    {
      if ( v16 || v14 || (_DWORD)v20 )
      {
        if ( LODWORD(a1) | v10 )
          goto _B2_75;
      }
      else if ( LODWORD(a1) | v10 )
      {
        TXTST3();
        *(_OWORD *)&a2 = *(unsigned __int64 *)&QNaN_c_1080_0_4;
        return *(__m128 *)&a2;
      }
      if ( !v13 )
      {
        if ( (_DWORD)v20 == 1 )
        {
          *(_OWORD *)&a2 = *(unsigned __int64 *)&2il0floatpacket_15;
          return *(__m128 *)&a2;
        }
        goto _B2_105;
      }
      if ( (_DWORD)v20 != 1 )
        goto _B2_102;
      ((void (*)(void))raise_zerodivide)();
    }
    *(_OWORD *)&a2 = 0i64;
    a2 = 0.0 - INFINITY;
  }
  return *(__m128 *)&a2;
}

// File Line: 1420
// RVA: 0x12D4790
float raise_zerodivide()
{
  return -1.5845633e29 / 0.0;
}

// File Line: 1447
// RVA: 0x12D47B0
float TXTST3()
{
  return NAN + NAN;
}

