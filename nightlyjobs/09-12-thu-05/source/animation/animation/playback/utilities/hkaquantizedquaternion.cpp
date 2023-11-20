// File Line: 46
// RVA: 0xB431B0
void __fastcall hkaQuantizedQuaternion::packQuaternions48(unsigned __int16 *dst, hkQuaternionf *src0, hkQuaternionf *src1, hkQuaternionf *src2)
{
  unsigned __int16 *v4; // r10
  __m128 v5; // xmm11
  __m128 v6; // xmm10
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128i v9; // xmm2
  __m128 v10; // xmm9
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  __m128i v15; // xmm1
  __m128 v16; // xmm11
  __m128i v17; // xmm2
  __m128i v18; // xmm5
  __m128i v19; // xmm0
  __m128i v20; // xmm0
  __m128i v21; // xmm0
  __m128i v22; // xmm0
  __int16 v23; // ax
  __int16 v24; // cx
  __int128 v25; // [rsp+0h] [rbp-E8h]
  __int128 v26; // [rsp+10h] [rbp-D8h]
  __int128 v27; // [rsp+20h] [rbp-C8h]
  __int128 v28; // [rsp+30h] [rbp-B8h]
  __m128i v29; // [rsp+40h] [rbp-A8h]
  __m128i v30; // [rsp+50h] [rbp-98h]
  __m128i v31; // [rsp+60h] [rbp-88h]
  __m128 *v32; // [rsp+138h] [rbp+50h]

  v4 = dst;
  v5 = *v32;
  v6 = _mm_add_ps(
         *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31,
         *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31);
  v7 = _mm_mul_ps(_mm_sub_ps(src0->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v8 = _mm_mul_ps(_mm_sub_ps(src1->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v9 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v7);
  v10 = _mm_mul_ps(_mm_sub_ps(src2->m_vec.m_quad, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v11 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v7, _mm_and_ps((__m128)v9, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v9, 0x1Fu)),
          (__m128i)_mm_cmpleps(v6, v7));
  v12 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v8);
  _mm_store_si128(&v29, v11);
  _mm_store_si128((__m128i *)&v25, v11);
  v13 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v8, _mm_and_ps((__m128)v12, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v12, 0x1Fu)),
          (__m128i)_mm_cmpleps(v6, v8));
  v14 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v10);
  _mm_store_si128(&v30, v13);
  _mm_store_si128((__m128i *)&v26, v13);
  v15 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v10, _mm_and_ps((__m128)v14, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v14, 0x1Fu)),
          (__m128i)_mm_cmpleps(v6, v10));
  _mm_store_si128(&v31, v15);
  _mm_store_si128((__m128i *)&v27, v15);
  v16 = _mm_mul_ps(_mm_sub_ps(v5, SMALLEST_MIN_REAL), SMALLEST_RNG_REAL);
  v17 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v16);
  v18 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v16, _mm_and_ps((__m128)v17, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v17, 0x1Fu)),
          (__m128i)_mm_cmpleps(v6, v16));
  _mm_store_si128((__m128i *)&v28, v18);
  if ( (_WORD)v32 )
  {
    if ( (unsigned __int16)v32 == 1 )
    {
      v19 = _mm_shuffle_epi32(v29, 120);
    }
    else
    {
      if ( (unsigned __int16)v32 != 2 )
        goto LABEL_8;
      v19 = _mm_shuffle_epi32(v29, 180);
    }
  }
  else
  {
    v19 = _mm_shuffle_epi32(v29, 57);
  }
  _mm_store_si128((__m128i *)&v25, v19);
LABEL_8:
  if ( WORD1(v32) )
  {
    if ( WORD1(v32) == 1 )
    {
      v20 = _mm_shuffle_epi32(v30, 120);
    }
    else
    {
      if ( WORD1(v32) != 2 )
        goto LABEL_15;
      v20 = _mm_shuffle_epi32(v30, 180);
    }
  }
  else
  {
    v20 = _mm_shuffle_epi32(v30, 57);
  }
  _mm_store_si128((__m128i *)&v26, v20);
LABEL_15:
  if ( WORD2(v32) )
  {
    if ( WORD2(v32) == 1 )
    {
      v21 = _mm_shuffle_epi32(v31, 120);
    }
    else
    {
      if ( WORD2(v32) != 2 )
        goto LABEL_22;
      v21 = _mm_shuffle_epi32(v31, 180);
    }
  }
  else
  {
    v21 = _mm_shuffle_epi32(v31, 57);
  }
  _mm_store_si128((__m128i *)&v27, v21);
LABEL_22:
  if ( !HIWORD(v32) )
  {
    v22 = _mm_shuffle_epi32(v18, 57);
    goto LABEL_28;
  }
  if ( HIWORD(v32) == 1 )
  {
    v22 = _mm_shuffle_epi32(v18, 120);
    goto LABEL_28;
  }
  if ( HIWORD(v32) == 2 )
  {
    v22 = _mm_shuffle_epi32(v18, 180);
LABEL_28:
    _mm_store_si128((__m128i *)&v28, v22);
  }
  *dst = ((_WORD)v32 << 15) | v25 & 0x7FFF;
  v23 = WORD4(v25);
  dst[1] = ((_WORD)v32 << 14) ^ (WORD2(v25) ^ ((_WORD)v32 << 14)) & 0x7FFF;
  v24 = v26 & 0x7FFF;
  v4[2] = v23 & 0x7FFF | ((src0->m_vec.m_quad.m128_f32[(unsigned __int16)v32] < 0.0) << 15);
  v4[3] = (WORD1(v32) << 15) | v24;
  v4[4] = (WORD1(v32) << 14) ^ (WORD2(v26) ^ (WORD1(v32) << 14)) & 0x7FFF;
  v4[5] = WORD4(v26) & 0x7FFF | ((src1->m_vec.m_quad.m128_f32[WORD1(v32)] < 0.0) << 15);
  v4[6] = (WORD2(v32) << 15) | v27 & 0x7FFF;
  v4[7] = (WORD2(v32) << 14) ^ (WORD2(v27) ^ (WORD2(v32) << 14)) & 0x7FFF;
  v4[8] = WORD4(v27) & 0x7FFF | ((src2->m_vec.m_quad.m128_f32[WORD2(v32)] < 0.0) << 15);
  v4[9] = (HIWORD(v32) << 15) | v28 & 0x7FFF;
  v4[10] = (HIWORD(v32) << 14) ^ (WORD2(v28) ^ (HIWORD(v32) << 14)) & 0x7FFF;
  v4[11] = WORD4(v28) & 0x7FFF | ((*((float *)v32->m128_u64 + HIWORD(v32)) < 0.0) << 15);
}

// File Line: 198
// RVA: 0xB43930
void __fastcall drop16BitSign(hkIntVector *a)
{
  _mm_store_si128(&a->m_quad, _mm_srli_epi16(_mm_slli_epi16(_mm_load_si128(&a->m_quad), 1u), 1u));
}

// File Line: 206
// RVA: 0xB43950
void __fastcall extract16BitSign(hkIntVector *a)
{
  _mm_store_si128(&a->m_quad, _mm_slli_epi16(_mm_srli_epi16(_mm_load_si128(&a->m_quad), 0xFu), 0xFu));
}

// File Line: 215
// RVA: 0xB43970
void __fastcall merge16to32(hkIntVector *dst0, hkIntVector *dst1, hkIntVector *dst2, hkIntVector *dst3, hkIntVector *src0, hkIntVector *src1)
{
  _mm_store_si128(&dst0->m_quad, _mm_unpacklo_epi16(_mm_load_si128(&src0->m_quad), (__m128i)0i64));
  _mm_store_si128(&dst1->m_quad, _mm_unpackhi_epi16(_mm_load_si128(&src0->m_quad), (__m128i)0i64));
  _mm_store_si128(&dst2->m_quad, _mm_unpacklo_epi16(_mm_load_si128(&src1->m_quad), (__m128i)0i64));
  _mm_store_si128(&dst3->m_quad, _mm_unpackhi_epi16(_mm_load_si128(&src1->m_quad), (__m128i)0i64));
}

// File Line: 235
// RVA: 0xB439C0
void __fastcall transposeStream(hkIntVector *x, hkIntVector *y, hkIntVector *z, hkIntVector *w, hkIntVector *src0, hkIntVector *src1, hkIntVector *src2, hkIntVector *src3)
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
  _mm_store_si128(&x->m_quad, _mm_unpacklo_epi32(v10, v12));
  _mm_store_si128(&y->m_quad, _mm_unpackhi_epi32(v10, v12));
  _mm_store_si128(&z->m_quad, _mm_unpacklo_epi32(v8, v13));
  _mm_store_si128(&w->m_quad, _mm_unpackhi_epi32(v8, v13));
}

// File Line: 283
// RVA: 0xB43A40
void __fastcall convertToFloat(hkVector4f *xOut, hkVector4f *yOut, hkVector4f *zOut, hkIntVector *ix, hkIntVector *iy, hkIntVector *iz)
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
void __fastcall shuffleW(hkVector4f *xInOut, hkVector4f *yInOut, hkVector4f *zInOut, hkVector4f *wInOut, hkIntVector *ix, hkIntVector *iy)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128i v8; // xmm1
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm5
  __m128 v13; // xmm9
  __m128 v14; // xmm10
  __m128 v15; // xmm0

  v6 = xInOut->m_quad;
  v7 = yInOut->m_quad;
  v8 = _mm_or_si128(_mm_slli_epi16(_mm_srli_epi16(iy->m_quad, 0xFu), 1u), _mm_srli_epi16(ix->m_quad, 0xFu));
  v9 = zInOut->m_quad;
  v10 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)g_intVectorConstants), v8);
  v11 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&xmmword_141A720A0), v8);
  v12 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&xmmword_141A72090), v8);
  v13 = wInOut->m_quad;
  v14 = (__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&xmmword_141A720E0), v8);
  v15 = _mm_andnot_ps(v10, _mm_or_ps(_mm_andnot_ps(v12, yInOut->m_quad), _mm_and_ps(v12, wInOut->m_quad)));
  xInOut->m_quad = _mm_or_ps(_mm_and_ps(wInOut->m_quad, v10), _mm_andnot_ps(v10, xInOut->m_quad));
  yInOut->m_quad = _mm_or_ps(v15, _mm_and_ps(v10, v6));
  zInOut->m_quad = _mm_or_ps(
                     _mm_andnot_ps(v14, _mm_or_ps(_mm_andnot_ps(v11, v7), _mm_and_ps(v11, v13))),
                     _mm_and_ps(v9, v14));
  wInOut->m_quad = _mm_or_ps(_mm_andnot_ps(v14, v9), _mm_and_ps(v14, v13));
}

// File Line: 414
// RVA: 0xB436D0
void __fastcall hkaQuantizedQuaternion::unpackQuaternions48(hkVector4f *dst0, hkVector4f *dst1, hkVector4f *dst2, hkVector4f *dst3, const unsigned __int16 *qq)
{
  __m128i v5; // xmm0
  __m128i v6; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm10
  __m128i v9; // xmm9
  __m128i v10; // xmm3
  __m128i v11; // xmm0
  __m128i v12; // xmm4
  __m128i v13; // xmm1
  __m128i v14; // xmm10
  __m128i v15; // xmm9
  __m128i v16; // xmm4
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128i v19; // xmm9
  __m128 v20; // xmm6
  __m128 v21; // xmm7
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm10
  __m128 v25; // xmm2
  __m128i v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm9
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm4

  v5 = _mm_loadu_si128((const __m128i *)qq);
  v6 = _mm_loadu_si128((const __m128i *)(qq + 6));
  v7 = _mm_unpacklo_epi16(v6, (__m128i)0i64);
  v8 = _mm_unpacklo_epi16(v5, (__m128i)0i64);
  v9 = _mm_unpacklo_epi32(v8, v7);
  v10 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps((__m128)_mm_unpackhi_epi16(v5, (__m128i)0i64), (__m128)v8, 228), 147);
  v11 = _mm_shuffle_epi32((__m128i)_mm_shuffle_ps((__m128)_mm_unpackhi_epi16(v6, (__m128i)0i64), (__m128)v7, 228), 147);
  v12 = v9;
  v13 = _mm_unpacklo_epi32(v10, v11);
  v14 = _mm_unpacklo_epi32(_mm_unpackhi_epi32(v8, v7), _mm_unpackhi_epi32(v10, v11));
  v15 = _mm_unpackhi_epi32(v9, v13);
  v16 = _mm_unpacklo_epi32(v12, v13);
  v17 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v16, 1u), 1u)), SMALLEST_RNG_INV),
          SMALLEST_MIN);
  v18 = _mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v15, 1u), 1u));
  v19 = _mm_or_si128(_mm_slli_epi16(_mm_srli_epi16(v15, 0xFu), 1u), _mm_srli_epi16(v16, 0xFu));
  v20 = _mm_add_ps(_mm_mul_ps(v18, SMALLEST_RNG_INV), SMALLEST_MIN);
  v21 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi16(_mm_slli_epi16(v14, 1u), 1u)), SMALLEST_RNG_INV),
          SMALLEST_MIN);
  v22 = _mm_sub_ps(
          query.m_quad,
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, v20), _mm_mul_ps(v17, v17)), _mm_mul_ps(v21, v21)));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      _mm_cmpeq_epi32(
                        _mm_cmpeq_epi32(
                          _mm_slli_epi16(_mm_srli_epi16(v14, 0xFu), 0xFu),
                          *(__m128i *)&g_intVectorConstants[0][0]),
                        (__m128i)0i64),
                      0x1Fu),
                    0x1Fu),
          _mm_mul_ps(
            v22,
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v23), v23)),
              _mm_mul_ps(*(__m128 *)_xmm, v23))));
  v25 = (__m128)_mm_cmpeq_epi32(v19, *(__m128i *)&g_intVectorConstants[0][0]);
  v26 = v19;
  v27 = (__m128)_mm_cmpeq_epi32(v19, (__m128i)xmmword_141A720A0);
  v28 = (__m128)_mm_cmpeq_epi32(v19, (__m128i)xmmword_141A720E0);
  v29 = (__m128)_mm_cmpeq_epi32(v26, (__m128i)xmmword_141A72090);
  v30 = _mm_or_ps(_mm_and_ps(v25, v24), _mm_andnot_ps(v25, v17));
  v31 = _mm_or_ps(_mm_andnot_ps(v25, _mm_or_ps(_mm_and_ps(v29, v24), _mm_andnot_ps(v29, v20))), _mm_and_ps(v25, v17));
  v32 = _mm_shuffle_ps(v30, v31, 68);
  v33 = _mm_shuffle_ps(v30, v31, 238);
  v34 = _mm_or_ps(_mm_andnot_ps(v28, _mm_or_ps(_mm_andnot_ps(v27, v20), _mm_and_ps(v27, v24))), _mm_and_ps(v28, v21));
  v35 = _mm_or_ps(_mm_andnot_ps(v28, v21), _mm_and_ps(v28, v24));
  v36 = _mm_shuffle_ps(v34, v35, 68);
  v37 = _mm_shuffle_ps(v34, v35, 238);
  dst0->m_quad = _mm_shuffle_ps(v32, v36, 136);
  dst1->m_quad = _mm_shuffle_ps(v32, v36, 221);
  dst2->m_quad = _mm_shuffle_ps(v33, v37, 136);
  dst3->m_quad = _mm_shuffle_ps(v33, v37, 221);
}

