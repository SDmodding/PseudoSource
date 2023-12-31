// File Line: 46
// RVA: 0xB431B0
void __fastcall hkaQuantizedQuaternion::packQuaternions48(
        unsigned __int16 *dst,
        hkQuaternionf *src0,
        hkQuaternionf *src1,
        hkQuaternionf *src2)
{
  __m128 *v4; // r15
  __m128 v5; // xmm12
  __m128 v6; // xmm10
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm14
  __m128 v10; // xmm9
  __m128i v11; // xmm0
  __m128i v12; // xmm0
  __m128i v13; // xmm0
  __m128 v14; // xmm3
  __m128i v15; // xmm15
  __m128 v16; // xmm11
  __m128i v17; // xmm2
  __m128 v18; // xmm3
  __m128i v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm13
  __m128 v22; // xmm2
  __m128i v23; // xmm4
  __m128 v24; // xmm1
  __m128i v25; // xmm2
  __m128i v26; // xmm15
  __m128i v27; // xmm0
  __m128i v28; // xmm0
  __m128i v29; // xmm0
  __m128i v30; // xmm0
  __m128i v31; // xmm0
  __m128i v32; // [rsp+0h] [rbp-E8h]
  __m128i v33; // [rsp+10h] [rbp-D8h]
  __m128i v34; // [rsp+20h] [rbp-C8h]
  __m128i v35; // [rsp+30h] [rbp-B8h]
  __m128i v36; // [rsp+40h] [rbp-A8h]
  __m128i v37; // [rsp+50h] [rbp-98h]
  __m128i v38; // [rsp+60h] [rbp-88h]
  __m128 *v39; // [rsp+138h] [rbp+50h]
  unsigned __int64 v40; // [rsp+138h] [rbp+50h]

  v4 = v39;
  v5 = _mm_shuffle_ps(src2->m_vec.m_quad, *v39, 68);
  v6 = _mm_add_ps(
         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
  v7 = _mm_mul_ps(_mm_sub_ps(src0->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v8 = _mm_mul_ps(_mm_sub_ps(src1->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v9 = _mm_shuffle_ps(src2->m_vec.m_quad, *v39, 238);
  v10 = _mm_mul_ps(_mm_sub_ps(src2->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v11 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v7);
  v36 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v7, _mm_and_ps((__m128)v11, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v11, 0x1Fu)),
          (__m128i)_mm_cmple_ps(v6, v7));
  v32 = v36;
  v12 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8);
  v37 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v8, _mm_and_ps((__m128)v12, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v12, 0x1Fu)),
          (__m128i)_mm_cmple_ps(v6, v8));
  v33 = v37;
  v13 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v10);
  v14 = _mm_shuffle_ps(src0->m_vec.m_quad, src1->m_vec.m_quad, 238);
  v38 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v10, _mm_and_ps((__m128)v13, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v13, 0x1Fu)),
          (__m128i)_mm_cmple_ps(v6, v10));
  v34 = v38;
  v15 = (__m128i)_mm_shuffle_ps(v14, v9, 221);
  v16 = _mm_mul_ps(_mm_sub_ps(*v39, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v17 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v16);
  v18 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v14, v9, 136), 1u), 1u);
  v19 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v16, _mm_and_ps((__m128)v17, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v17, 0x1Fu)),
          (__m128i)_mm_cmple_ps(v6, v16));
  v20 = _mm_shuffle_ps(src0->m_vec.m_quad, src1->m_vec.m_quad, 68);
  v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v20, v5, 221), 1u), 1u);
  v35 = v19;
  v22 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v20, v5, 136), 1u), 1u);
  v23 = (__m128i)_mm_cmplt_ps(v21, v22);
  v24 = _mm_or_ps(_mm_andnot_ps((__m128)v23, v21), _mm_and_ps((__m128)v23, v22));
  v25 = (__m128i)_mm_cmplt_ps(v18, v24);
  v26 = (__m128i)_mm_cmplt_ps(
                   (__m128)_mm_srli_epi32(_mm_slli_epi32(v15, 1u), 1u),
                   _mm_or_ps(_mm_and_ps(v24, (__m128)v25), _mm_andnot_ps((__m128)v25, v18)));
  v27 = _mm_or_si128(
          _mm_and_si128(
            _mm_or_si128(
              _mm_and_si128(
                _mm_or_si128(
                  _mm_andnot_si128(v23, (__m128i)xmmword_141A72090),
                  _mm_and_si128(v23, *(__m128i *)&g_intVectorConstants[0][0])),
                v25),
              _mm_andnot_si128(v25, (__m128i)xmmword_141A720A0)),
            v26),
          _mm_andnot_si128(v26, (__m128i)xmmword_141A720E0));
  v40 = _mm_packs_epi32(v27, v27).m128i_u64[0];
  if ( (_WORD)v40 )
  {
    if ( (unsigned __int16)v40 == 1 )
    {
      v28 = _mm_shuffle_epi32(v36, 120);
    }
    else
    {
      if ( (unsigned __int16)v40 != 2 )
        goto LABEL_8;
      v28 = _mm_shuffle_epi32(v36, 180);
    }
  }
  else
  {
    v28 = _mm_shuffle_epi32(v36, 57);
  }
  v32 = v28;
LABEL_8:
  if ( WORD1(v40) )
  {
    if ( WORD1(v40) == 1 )
    {
      v29 = _mm_shuffle_epi32(v37, 120);
    }
    else
    {
      if ( WORD1(v40) != 2 )
        goto LABEL_15;
      v29 = _mm_shuffle_epi32(v37, 180);
    }
  }
  else
  {
    v29 = _mm_shuffle_epi32(v37, 57);
  }
  v33 = v29;
LABEL_15:
  if ( WORD2(v40) )
  {
    if ( WORD2(v40) == 1 )
    {
      v30 = _mm_shuffle_epi32(v38, 120);
    }
    else
    {
      if ( WORD2(v40) != 2 )
        goto LABEL_22;
      v30 = _mm_shuffle_epi32(v38, 180);
    }
  }
  else
  {
    v30 = _mm_shuffle_epi32(v38, 57);
  }
  v34 = v30;
LABEL_22:
  if ( !HIWORD(v40) )
  {
    v31 = _mm_shuffle_epi32(v19, 57);
    goto LABEL_28;
  }
  if ( HIWORD(v40) == 1 )
  {
    v31 = _mm_shuffle_epi32(v19, 120);
    goto LABEL_28;
  }
  if ( HIWORD(v40) == 2 )
  {
    v31 = _mm_shuffle_epi32(v19, 180);
LABEL_28:
    v35 = v31;
  }
  *dst = ((_WORD)v40 << 15) | v32.m128i_i16[0] & 0x7FFF;
  dst[1] = ((_WORD)v40 << 14) ^ (v32.m128i_i16[2] ^ ((_WORD)v40 << 14)) & 0x7FFF;
  dst[2] = v32.m128i_i16[4] & 0x7FFF | ((src0->m_vec.m_quad.m128_f32[(unsigned __int16)v40] < 0.0) << 15);
  dst[3] = (WORD1(v40) << 15) | v33.m128i_i16[0] & 0x7FFF;
  dst[4] = (WORD1(v40) << 14) ^ (v33.m128i_i16[2] ^ (WORD1(v40) << 14)) & 0x7FFF;
  dst[5] = v33.m128i_i16[4] & 0x7FFF | ((src1->m_vec.m_quad.m128_f32[WORD1(v40)] < 0.0) << 15);
  dst[6] = (WORD2(v40) << 15) | v34.m128i_i16[0] & 0x7FFF;
  dst[7] = (WORD2(v40) << 14) ^ (v34.m128i_i16[2] ^ (WORD2(v40) << 14)) & 0x7FFF;
  dst[8] = v34.m128i_i16[4] & 0x7FFF | ((src2->m_vec.m_quad.m128_f32[WORD2(v40)] < 0.0) << 15);
  dst[9] = (HIWORD(v40) << 15) | v35.m128i_i16[0] & 0x7FFF;
  dst[10] = (HIWORD(v40) << 14) ^ (v35.m128i_i16[2] ^ (HIWORD(v40) << 14)) & 0x7FFF;
  dst[11] = v35.m128i_i16[4] & 0x7FFF | ((v4->m128_f32[HIWORD(v40)] < 0.0) << 15);
}

// File Line: 198
// RVA: 0xB43930
void __fastcall drop16BitSign(hkIntVector *a)
{
  a->m_quad = _mm_srli_epi16(_mm_slli_epi16(_mm_load_si128(&a->m_quad), 1u), 1u);
}

// File Line: 206
// RVA: 0xB43950
void __fastcall extract16BitSign(hkIntVector *a)
{
  a->m_quad = _mm_slli_epi16(_mm_srli_epi16(_mm_load_si128(&a->m_quad), 0xFu), 0xFu);
}

// File Line: 215
// RVA: 0xB43970
void __fastcall merge16to32(
        hkIntVector *dst0,
        hkIntVector *dst1,
        hkIntVector *dst2,
        hkIntVector *dst3,
        hkIntVector *src0,
        hkIntVector *src1)
{
  dst0->m_quad = _mm_unpacklo_epi16(_mm_load_si128(&src0->m_quad), (__m128i)0i64);
  dst1->m_quad = _mm_unpackhi_epi16(_mm_load_si128(&src0->m_quad), (__m128i)0i64);
  dst2->m_quad = _mm_unpacklo_epi16(_mm_load_si128(&src1->m_quad), (__m128i)0i64);
  dst3->m_quad = _mm_unpackhi_epi16(_mm_load_si128(&src1->m_quad), (__m128i)0i64);
}

// File Line: 235
// RVA: 0xB439C0
void __fastcall transposeStream(
        hkIntVector *x,
        hkIntVector *y,
        hkIntVector *z,
        hkIntVector *w,
        hkIntVector *src0,
        hkIntVector *src1,
        hkIntVector *src2,
        hkIntVector *src3)
{
  __m128i v8; // xmm5
  __m128i v9; // xmm4
  __m128i v10; // xmm3
  __m128i v11; // xmm1
  __m128i v12; // xmm0
  __m128i v13; // xmm4

  v8 = _mm_unpackhi_epi32(src0->m_quad, src2->m_quad);
  v9 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps((__m128)src1->m_quad, (__m128)src0->m_quad, 228), 147);
  v10 = _mm_unpacklo_epi32(src0->m_quad, src2->m_quad);
  v11 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps((__m128)src3->m_quad, (__m128)src2->m_quad, 228), 147);
  v12 = _mm_unpacklo_epi32(v9, v11);
  v13 = _mm_unpackhi_epi32(v9, v11);
  x->m_quad = _mm_unpacklo_epi32(v10, v12);
  y->m_quad = _mm_unpackhi_epi32(v10, v12);
  z->m_quad = _mm_unpacklo_epi32(v8, v13);
  w->m_quad = _mm_unpackhi_epi32(v8, v13);
}

// File Line: 283
// RVA: 0xB43A40
void __fastcall convertToFloat(
        hkVector4f *xOut,
        hkVector4f *yOut,
        hkVector4f *zOut,
        hkIntVector *ix,
        hkIntVector *iy,
        hkIntVector *iz)
{
  __m128i v6; // xmm1
  hkVector4f v7; // xmm4

  v6 = _mm_srli_epi16(_mm_slli_epi16(iz->m_quad, 1u), 1u);
  v7.m_quad = _mm_add_ps(
                _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(iy->m_quad, 1u), 1u)), SMALLEST_RNG_INV),
                SMALLEST_MIN);
  xOut->m_quad = _mm_add_ps(
                   _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(ix->m_quad, 1u), 1u)), SMALLEST_RNG_INV),
                   SMALLEST_MIN);
  *yOut = (hkVector4f)v7.m_quad;
  zOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v6), SMALLEST_RNG_INV), SMALLEST_MIN);
}

// File Line: 320
// RVA: 0xB43AB0
void __fastcall computeW(hkVector4f *wOut, hkVector4f *x, hkVector4f *y, hkVector4f *z, hkIntVector *iz)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2

  v5 = _mm_sub_ps(
         query.m_quad,
         _mm_add_ps(
           _mm_add_ps(_mm_mul_ps(y->m_quad, y->m_quad), _mm_mul_ps(x->m_quad, x->m_quad)),
           _mm_mul_ps(z->m_quad, z->m_quad)));
  v6 = _mm_rsqrt_ps(v5);
  wOut->m_quad = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               _mm_cmpeq_epi32(
                                 _mm_cmpeq_epi32(
                                   _mm_slli_epi16(_mm_srli_epi16(iz->m_quad, 0xFu), 0xFu),
                                   *(__m128i *)&g_intVectorConstants[0][0]),
                                 (__m128i)0i64),
                               0x1Fu),
                             0x1Fu),
                   _mm_mul_ps(
                     v5,
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5, v6), v6)),
                       _mm_mul_ps(*(__m128 *)_xmm, v6))));
}

// File Line: 347
// RVA: 0xB43B40
void __fastcall shuffleW(
        hkVector4f *xInOut,
        hkVector4f *yInOut,
        hkVector4f *zInOut,
        hkVector4f *wInOut,
        hkIntVector *ix,
        hkIntVector *iy)
{
  __m128 m_quad; // xmm3
  __m128 v7; // xmm4
  __m128i v8; // xmm1
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm9
  __m128 v13; // xmm10
  __m128 v14; // xmm2
  __m128 v15; // xmm0

  m_quad = xInOut->m_quad;
  v7 = yInOut->m_quad;
  v8 = _mm_or_si128(_mm_slli_epi16(_mm_srli_epi16(iy->m_quad, 0xFu), 1u), _mm_srli_epi16(ix->m_quad, 0xFu));
  v9 = zInOut->m_quad;
  v10 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)g_intVectorConstants), v8);
  v11 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&xmmword_141A720A0), v8);
  v12 = wInOut->m_quad;
  v13 = (__m128)_mm_cmpeq_epi32(_mm_load_si128(xmmword_141A720E0), v8);
  v14 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&xmmword_141A72090), v8);
  v15 = _mm_andnot_ps(v10, _mm_or_ps(_mm_andnot_ps(v14, yInOut->m_quad), _mm_and_ps(v14, wInOut->m_quad)));
  xInOut->m_quad = _mm_or_ps(_mm_and_ps(wInOut->m_quad, v10), _mm_andnot_ps(v10, xInOut->m_quad));
  yInOut->m_quad = _mm_or_ps(v15, _mm_and_ps(v10, m_quad));
  zInOut->m_quad = _mm_or_ps(
                     _mm_andnot_ps(v13, _mm_or_ps(_mm_andnot_ps(v11, v7), _mm_and_ps(v11, v12))),
                     _mm_and_ps(v9, v13));
  wInOut->m_quad = _mm_or_ps(_mm_andnot_ps(v13, v9), _mm_and_ps(v13, v12));
}

// File Line: 414
// RVA: 0xB436D0
void __fastcall hkaQuantizedQuaternion::unpackQuaternions48(
        hkVector4f *dst0,
        hkVector4f *dst1,
        hkVector4f *dst2,
        hkVector4f *dst3,
        const unsigned __int16 *qq)
{
  __m128i v5; // xmm2
  __m128 v6; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm10
  __m128 v9; // xmm0
  __m128i v10; // xmm10
  __m128i v11; // xmm3
  __m128i v12; // xmm0
  __m128i v13; // xmm4
  __m128i v14; // xmm1
  __m128i v15; // xmm10
  __m128i v16; // xmm9
  __m128i v17; // xmm0
  __m128 v18; // xmm8
  __m128 v19; // xmm6
  __m128i v20; // xmm9
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm10
  __m128 v26; // xmm2
  __m128i v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm9
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm4

  v5 = _mm_loadu_si128((const __m128i *)(qq + 6));
  v6 = (__m128)_mm_unpackhi_epi16(v5, (__m128i)0i64);
  v7 = _mm_unpacklo_epi16(v5, (__m128i)0i64);
  v8 = _mm_loadu_si128((const __m128i *)qq);
  v9 = (__m128)_mm_unpackhi_epi16(v8, (__m128i)0i64);
  v10 = _mm_unpacklo_epi16(v8, (__m128i)0i64);
  v11 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps(v9, (__m128)v10, 228), 147);
  v12 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps(v6, (__m128)v7, 228), 147);
  v13 = _mm_unpacklo_epi32(v10, v7);
  v14 = _mm_unpacklo_epi32(v11, v12);
  v15 = _mm_unpacklo_epi32(_mm_unpackhi_epi32(v10, v7), _mm_unpackhi_epi32(v11, v12));
  v16 = _mm_unpackhi_epi32(v13, v14);
  v17 = _mm_unpacklo_epi32(v13, v14);
  v18 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v17, 1u), 1u)), SMALLEST_RNG_INV),
          SMALLEST_MIN);
  v19 = _mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v16, 1u), 1u));
  v20 = _mm_or_si128(_mm_slli_epi16(_mm_srli_epi16(v16, 0xFu), 1u), _mm_srli_epi16(v17, 0xFu));
  v21 = _mm_add_ps(_mm_mul_ps(v19, SMALLEST_RNG_INV), SMALLEST_MIN);
  v22 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v15, 1u), 1u)), SMALLEST_RNG_INV),
          SMALLEST_MIN);
  v23 = _mm_sub_ps(
          query.m_quad,
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v21, v21), _mm_mul_ps(v18, v18)), _mm_mul_ps(v22, v22)));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      _mm_cmpeq_epi32(
                        _mm_cmpeq_epi32(
                          _mm_slli_epi16(_mm_srli_epi16(v15, 0xFu), 0xFu),
                          *(__m128i *)&g_intVectorConstants[0][0]),
                        (__m128i)0i64),
                      0x1Fu),
                    0x1Fu),
          _mm_mul_ps(
            v23,
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v24), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24))));
  v26 = (__m128)_mm_cmpeq_epi32(v20, *(__m128i *)&g_intVectorConstants[0][0]);
  v27 = v20;
  v28 = (__m128)_mm_cmpeq_epi32(v20, (__m128i)xmmword_141A720A0);
  v29 = (__m128)_mm_cmpeq_epi32(v20, (__m128i)xmmword_141A720E0);
  v30 = _mm_or_ps(_mm_and_ps(v26, v25), _mm_andnot_ps(v26, v18));
  v31 = (__m128)_mm_cmpeq_epi32(v27, (__m128i)xmmword_141A72090);
  v32 = _mm_or_ps(_mm_andnot_ps(v26, _mm_or_ps(_mm_and_ps(v31, v25), _mm_andnot_ps(v31, v21))), _mm_and_ps(v26, v18));
  v33 = _mm_shuffle_ps(v30, v32, 68);
  v34 = _mm_shuffle_ps(v30, v32, 238);
  v35 = _mm_or_ps(_mm_andnot_ps(v29, _mm_or_ps(_mm_andnot_ps(v28, v21), _mm_and_ps(v28, v25))), _mm_and_ps(v29, v22));
  v36 = _mm_or_ps(_mm_andnot_ps(v29, v22), _mm_and_ps(v29, v25));
  v37 = _mm_shuffle_ps(v35, v36, 68);
  v38 = _mm_shuffle_ps(v35, v36, 238);
  dst0->m_quad = _mm_shuffle_ps(v33, v37, 136);
  dst1->m_quad = _mm_shuffle_ps(v33, v37, 221);
  dst2->m_quad = _mm_shuffle_ps(v34, v38, 136);
  dst3->m_quad = _mm_shuffle_ps(v34, v38, 221);
}

