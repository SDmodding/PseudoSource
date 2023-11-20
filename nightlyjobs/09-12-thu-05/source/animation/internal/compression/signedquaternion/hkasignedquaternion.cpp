// File Line: 89
// RVA: 0xBAAB40
void __fastcall hkaSignedQuaternion::packSignedQuaternion16(hkQuaternionf *in, char *out)
{
  __m128 v2; // xmm0
  __m128i v3; // xmm3
  __m128i v4; // xmm2
  __m128i v5; // xmm2
  int v6; // [rsp+8h] [rbp+8h]

  v2 = _mm_mul_ps(in->m_vec.m_quad, (__m128)xmmword_141A71120);
  v3 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v2),
           _mm_cvttps_epi32(v2)),
         (__m128i)_xmm);
  v4 = _mm_or_si128(
         _mm_andnot_si128((__m128i)xmmword_141A4E970, _mm_slli_epi32(v3, 4u)),
         _mm_and_si128((__m128i)xmmword_141A4E970, v3));
  v5 = _mm_packs_epi32(v4, v4);
  v6 = (unsigned __int128)_mm_packus_epi16(v5, v5);
  *out = v6 | BYTE1(v6);
  out[1] = BYTE2(v6) | HIBYTE(v6);
}

// File Line: 145
// RVA: 0xBAABC0
void __fastcall hkaSignedQuaternion::packSignedQuaternion24(hkQuaternionf *in, char *out)
{
  char *v2; // r11
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  int v5; // er9
  __m128 v6; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm2
  int v9; // edx
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128i v12; // [rsp+0h] [rbp-18h]

  v2 = out;
  v3 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)in), 1u), 1u);
  v4 = _mm_max_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  v5 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_cmpleps(
                                                                _mm_max_ps(v4, _mm_shuffle_ps(v4, v4, 177)),
                                                                v3))];
  v6 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(FLOAT_89_095451), (__m128)LODWORD(FLOAT_89_095451), 0),
         in->m_vec.m_quad);
  v7 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
           _mm_cvttps_epi32(v6)),
         (__m128i)_xmm);
  v8 = _mm_packs_epi32(v7, v7);
  _mm_store_si128(&v12, _mm_packus_epi16(v8, v8));
  *out = v12.m128i_i8[v5 == 0];
  v9 = ((v5 == 0) + 1 == v5) + (v5 == 0) + 1;
  v2[1] = v12.m128i_i8[v9];
  LOBYTE(v9) = v12.m128i_i8[v9 + 1 + (v9 + 1 == v5)];
  v2[2] = v9;
  v10 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v5], in->m_vec.m_quad);
  *v2 |= (_BYTE)v5 << 7;
  v2[1] |= (v5 & 0xFE) << 6;
  v11 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v2[2] = v9 | ((COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v11, v11, 177) | v11.m128_i32[0]) < 0.0) << 7);
}

// File Line: 215
// RVA: 0xBAACF0
void __fastcall hkaSignedQuaternion::packSignedQuaternion32(hkQuaternionf *in, char *out8)
{
  char *v2; // r8
  int v3; // er9
  __m128 v4; // xmm10
  __m128 v5; // xmm1
  __m128 v6; // xmm13
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm10
  __m128 v11; // xmm12
  __m128 v12; // xmm9
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm8
  __m128 v20; // xmm2
  signed int v21; // edx
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  int v33; // ecx
  __m128 v34; // xmm0

  v2 = out8;
  if ( (_mm_movemask_ps(_mm_cmpeqps((__m128)0i64, in->m_vec.m_quad)) & 7) == 7 )
  {
    *(_DWORD *)out8 = 0;
  }
  else
  {
    v3 = _mm_movemask_ps(_mm_cmpltps(in->m_vec.m_quad, (__m128)0i64)) << 28;
    *(_DWORD *)out8 = v3;
    v4 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)in), 1u), 1u);
    v5 = _mm_mul_ps(v4, v4);
    v6 = _mm_shuffle_ps(v4, v4, 255);
    v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
    v8 = _mm_rsqrt_ps(v7);
    v9 = _mm_rcp_ps((__m128)xmmword_141A713B0);
    v10 = _mm_mul_ps(
            v4,
            _mm_andnot_ps(
              _mm_cmpleps(v7, (__m128)0i64),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8))));
    v11 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)xmmword_141A713B0, v9)), v9),
            (__m128)xmmword_141A710D0);
    v12 = _mm_min_ps(
            _mm_max_ps(
              (__m128)(unsigned int)*(_OWORD *)&_mm_shuffle_ps(v10, v10, 170),
              *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v13 = _mm_andnot_ps(*(__m128 *)_xmm, v12);
    v14 = _mm_cmpltps(v13, *(__m128 *)_xmm);
    v15 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v13), *(__m128 *)_xmm);
    v16 = _mm_cmpltps(*(__m128 *)_xmm, v13);
    v17 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v15), v16), _mm_andnot_ps(v16, v13));
    v18 = _mm_or_ps(_mm_andnot_ps(v16, _mm_mul_ps(v13, v13)), _mm_and_ps(v16, v15));
    v19 = _mm_shuffle_ps(v10, v10, 85);
    v20 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, *(__m128 *)coeff4), *(__m128 *)coeff3), v18),
                          *(__m128 *)coeff2),
                        v18),
                      *(__m128 *)coeff1),
                    v18),
                  *(__m128 *)coeff0),
                v18),
              v17),
            v17);
    v20.m128_i32[0] = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                v14,
                                                _mm_or_ps(
                                                  _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v20, v20)), v16),
                                                  _mm_andnot_ps(v16, v20))) | v14.m128_i32[0] & v13.m128_i32[0]) ^ v12.m128_i32[0] & _xmm[0];
    v21 = _mm_cvtsi128_si32(
            _mm_cvttps_epi32(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      (__m128)COERCE_UNSIGNED_INT(1.5707964 - v20.m128_f32[0]),
                      (__m128)COERCE_UNSIGNED_INT(1.5707964 - v20.m128_f32[0]),
                      0),
                    v11),
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_511_0), (__m128)LODWORD(FLOAT_511_0), 0)),
                (__m128)xmmword_141A711B0)));
    v22 = _mm_rcp_ps(_mm_shuffle_ps(v10, v10, 0));
    v23 = _mm_mul_ps(v22, v19);
    v24 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v23), _mm_cmpltps(*(__m128 *)_xmm, v23));
    v25 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v23), v24), _mm_andnot_ps(v24, v23));
    v26 = _mm_mul_ps(v25, v25);
    v27 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(*(__m128 *)s0, v26)), *(__m128 *)t0),
                            _mm_add_ps(*(__m128 *)s1, v26))),
                        *(__m128 *)t1),
                      _mm_add_ps(*(__m128 *)s2, v26))),
                  *(__m128 *)t2),
                _mm_add_ps(*(__m128 *)s3, v26))),
            _mm_mul_ps(*(__m128 *)t3, v25));
    v28 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v25, *(__m128 *)_xmm), *(__m128 *)_xmm), v27), v24),
            _mm_andnot_ps(v24, v27));
    v29 = _mm_cmpleps((__m128)0i64, v22);
    v30 = _mm_or_ps(
            _mm_andnot_ps(v29, _mm_add_ps(_mm_or_ps(_mm_and_ps(v19, *(__m128 *)_xmm), *(__m128 *)_xmm), v28)),
            _mm_and_ps(v28, v29));
    if ( (_mm_movemask_ps(_mm_cmpeqps(v10, (__m128)0i64)) & 3) == 3 )
      v30 = 0i64;
    v31 = 0i64;
    v31.m128_f32[0] = (float)v21;
    v32 = _mm_shuffle_ps(v31, v31, 0);
    v33 = v3 | (v21 * v21
              + _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_mul_ps(_mm_add_ps(v32, v32), _mm_mul_ps(v11, v30)), (__m128)xmmword_141A711B0))));
    *(_DWORD *)v2 = v33;
    v34 = _mm_sub_ps(query.m_quad, v6);
    *(_DWORD *)v2 = v33 | (_mm_cvtsi128_si32(
                             _mm_cvttps_epi32(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)LODWORD(FLOAT_1023_0), (__m128)LODWORD(FLOAT_1023_0), 0),
                                   _mm_andnot_ps(_mm_cmpleps(v34, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v34), v34))),
                                 (__m128)xmmword_141A711B0))) << 18);
  }
}

// File Line: 328
// RVA: 0xBAB0F0
void __fastcall hkaSignedQuaternion::packSignedQuaternion40(hkQuaternionf *in, char *out)
{
  __m128i v2; // xmm3
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  int v5; // er10
  __m128 v6; // xmm1
  __m128i v7; // xmm2
  int v8; // ecx
  __int16 v9; // r8
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128i v13; // [rsp+0h] [rbp-18h]
  __int16 v14; // [rsp+20h] [rbp+8h]

  v2 = _mm_load_si128((const __m128i *)in);
  v3 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v2, 1u), 1u);
  v4 = _mm_max_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  v5 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_cmpleps(
                                                                _mm_max_ps(v4, _mm_shuffle_ps(v4, v4, 177)),
                                                                v3))];
  v6 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_2894_8953), (__m128)LODWORD(FLOAT_2894_8953), 0), (__m128)v2);
  v7 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
           _mm_cvttps_epi32(v6)),
         (__m128i)_xmm);
  _mm_store_si128(&v13, _mm_packs_epi32(v7, v7));
  v14 = v13.m128i_i16[v5 == 0];
  v8 = ((v5 == 0) + 1 == v5) + (v5 == 0) + 1;
  v9 = v13.m128i_i16[v8];
  LOWORD(v8) = v13.m128i_i16[v8 + 1 + (unsigned __int64)(v8 + 1 == v5)];
  v10 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v5];
  *out = v14;
  v11 = _mm_and_ps(v10, (__m128)v2);
  out[3] = v8;
  out[2] = v9 >> 4;
  v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  out[1] = 16 * v9 | HIBYTE(v14);
  out[4] = BYTE1(v8) | 16
                     * (v5 | 4
                           * (COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v12, v12, 177) | v12.m128_i32[0]) < 0.0));
}

// File Line: 398
// RVA: 0xBAB240
void __fastcall hkaSignedQuaternion::packSignedQuaternion48(hkQuaternionf *in, char *out8)
{
  __m128i v2; // xmm3
  char *v3; // rbx
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  int v6; // er11
  __m128 v7; // xmm1
  __m128i v8; // xmm2
  int v9; // edx
  __int16 v10; // r9
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128i v14; // [rsp+0h] [rbp-18h]

  v2 = _mm_load_si128((const __m128i *)in);
  v3 = out8;
  v4 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v2, 1u), 1u);
  v5 = _mm_max_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  v6 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_cmpleps(
                                                                _mm_max_ps(v5, _mm_shuffle_ps(v5, v5, 177)),
                                                                v4))];
  v7 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_23169_061), (__m128)LODWORD(FLOAT_23169_061), 0), (__m128)v2);
  v8 = _mm_add_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v7),
           _mm_cvttps_epi32(v7)),
         (__m128i)_xmm);
  _mm_store_si128(&v14, _mm_packs_epi32(v8, v8));
  v9 = ((v6 == 0) + 1 == v6) + (v6 == 0) + 1;
  v10 = v14.m128i_i16[v9];
  v11 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v6];
  *(_WORD *)v3 = v14.m128i_i16[v6 == 0] | ((_WORD)v6 << 15);
  *((_WORD *)v3 + 1) = v10 | ((v6 & 0xFFFE) << 14);
  v12 = _mm_and_ps(v11, (__m128)v2);
  v13 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  *((_WORD *)v3 + 2) = v14.m128i_i16[v9 + 1 + (unsigned __int64)(v9 + 1 == v6)] | ((COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v13, v13, 177) | v13.m128_i32[0]) < 0.0) << 15);
}

// File Line: 465
// RVA: 0xBAB380
void __fastcall hkaSignedQuaternion::packSignedQuaternion128(hkQuaternionf *in, char *out8)
{
  *(hkQuaternionf *)out8 = (hkQuaternionf)in->m_vec.m_quad;
}

// File Line: 481
// RVA: 0xBAB390
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion16(const char *in, hkQuaternionf *out)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm0
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm2

  v2 = _mm_mul_ps(
         _mm_sub_ps(
           _mm_cvtepi32_ps(
             _mm_unpacklo_epi32(
               _mm_unpacklo_epi32(_mm_cvtsi32_si128(*in & 0xF), _mm_cvtsi32_si128(in[1] & 0xF)),
               _mm_unpacklo_epi32(
                 _mm_cvtsi32_si128((unsigned int)*(unsigned __int8 *)in >> 4),
                 _mm_cvtsi32_si128((unsigned int)*((unsigned __int8 *)in + 1) >> 4)))),
           (__m128)xmmword_141A71120),
         (__m128)xmmword_141A71200);
  v3 = _mm_mul_ps(v2, v2);
  v4 = _mm_add_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 177), v4);
  v6 = _mm_rsqrt_ps(v5);
  out->m_vec.m_quad = _mm_mul_ps(
                        v2,
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)),
                          _mm_mul_ps(*(__m128 *)_xmm, v6)));
}

// File Line: 527
// RVA: 0xBAB430
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion24(const char *in, hkQuaternionf *out)
{
  const char *v2; // r8
  unsigned int v3; // ecx
  char v4; // di
  char v5; // bl
  hkQuaternionf *v6; // rsi
  int v7; // er10
  unsigned int v8; // edi
  int v9; // edx
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128i v15; // [rsp+0h] [rbp-18h]

  v2 = in;
  v3 = *(unsigned __int8 *)in;
  v4 = v2[1];
  v5 = v2[2];
  v6 = out;
  _mm_store_si128(&v15, _mm_load_si128((const __m128i *)&_xmm));
  v7 = v4 & 0x7F;
  v8 = ((v3 >> 1) | v4 & 0x80) >> 6;
  v15.m128i_i32[v8 == 0] = v3 & 0x7F;
  v9 = ((v8 == 0) + 1 == v8) + (v8 == 0) + 1;
  v15.m128i_i32[v9] = v7;
  v15.m128i_i32[v9 + 1 + (unsigned __int64)(v9 + 1 == v8)] = v5 & 0x7F;
  v10 = _mm_mul_ps(
          _mm_sub_ps(_mm_cvtepi32_ps(v15), _mm_shuffle_ps((__m128)LODWORD(FLOAT_63_0), (__m128)LODWORD(FLOAT_63_0), 0)),
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_011223917), (__m128)LODWORD(FLOAT_0_011223917), 0));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v13 = _mm_sub_ps(query.m_quad, _mm_add_ps(_mm_shuffle_ps(v12, v12, 177), v12));
  v14 = _mm_andnot_ps(_mm_cmpleps(v13, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v13), v13));
  if ( v5 < 0 )
    v14 = _mm_sub_ps((__m128)0i64, v14);
  v6->m_vec.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v8], v10),
                       _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v8], v14));
}

// File Line: 607
// RVA: 0xBAB570
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion32(const char *in8, hkQuaternionf *out)
{
  unsigned int v2; // er9
  __m128i v3; // xmm6
  __m128 v4; // xmm0
  __m128 v5; // xmm3
  __m128i v6; // xmm8
  __m128 v7; // xmm0
  __m128 v8; // xmm12
  __m128 v9; // xmm0
  __m128 v10; // xmm0
  signed int v11; // ecx
  __m128 v12; // xmm3
  __m128 v13; // xmm9
  __m128i v14; // xmm3
  __m128 v15; // xmm9
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  __m128i v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm10
  __m128 v33; // xmm2

  v2 = *(_DWORD *)in8;
  v3 = _mm_load_si128((const __m128i *)_xmm);
  v4 = 0i64;
  v5 = 0i64;
  v4.m128_f32[0] = (float)((*(_DWORD *)in8 >> 18) & 0x3FF);
  v6 = _mm_add_epi32(v3, v3);
  v7 = _mm_mul_ps(
         _mm_shuffle_ps(v4, v4, 0),
         _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_00097751711), (__m128)LODWORD(FLOAT_0_00097751711), 0));
  v8 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v7, v7));
  v9 = 0i64;
  v9.m128_f32[0] = (float)(*(_DWORD *)in8 & 0x3FFFF);
  v10 = _mm_shuffle_ps(v9, v9, 0);
  v11 = _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_andnot_ps(_mm_cmpleps(v10, (__m128)0i64), _mm_sqrt_ps(v10))));
  v5.m128_f32[0] = (float)v11;
  v12 = _mm_shuffle_ps(v5, v5, 0);
  v13 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0019569471), (__m128)LODWORD(FLOAT_0_0019569471), 0), v12);
  v14 = (__m128i)_mm_add_ps(v12, v12);
  v15 = _mm_mul_ps(v13, (__m128)xmmword_141A713C0);
  v16 = _mm_rcp_ps((__m128)v14);
  v17 = _mm_cmpeqps((__m128)v14, (__m128)0i64);
  v18 = _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v14, 0x1Fu), 0x1Fu), (__m128)_xmm), v17);
  v19 = _mm_andnot_ps(v17, v16);
  v20 = 0i64;
  v20.m128_f32[0] = (float)(signed int)((v2 & 0x3FFFF) - v11 * v11);
  v21 = _mm_or_ps(v18, v19);
  v22 = _mm_andnot_ps(
          _mm_cmpeqps(v21, (__m128)0i64),
          _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v21), (__m128)xmmword_141A713C0));
  v23 = _mm_add_ps(_mm_movelh_ps(_mm_unpacklo_ps(v15, v15), _mm_unpacklo_ps(v22, v22)), *(__m128 *)offset_1);
  v24 = _mm_andnot_ps(*(__m128 *)_xmm, v23);
  v25 = _mm_andnot_si128(v3, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v24, *(__m128 *)_xmm)), v3));
  v26 = _mm_cvtepi32_ps(v25);
  v27 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v25, v6), (__m128i)0i64);
  v28 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, *(__m128 *)DP1_0), v24), _mm_mul_ps(v26, *(__m128 *)DP2)),
          _mm_mul_ps(v26, *(__m128 *)DP3));
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v27,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v29, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v29),
                        *(__m128 *)cosCoeff2_0),
                      v29),
                    v29),
                  _mm_mul_ps(v29, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v29, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v29),
                      *(__m128 *)sinCoeff2_0),
                    v29),
                  v28),
                v28),
              v27)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v6, v6), v25), 0x1Du),
            _mm_and_ps(v23, *(__m128 *)_xmm)));
  v31 = _mm_shuffle_ps(v30, v30, 0);
  v32 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v8, v8));
  v33 = _mm_mul_ps(
          _mm_movelh_ps(
            _mm_unpacklo_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v31),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v31)),
            _mm_unpacklo_ps(_mm_shuffle_ps(v30, v30, 85), query.m_quad)),
          _mm_andnot_ps(_mm_cmpleps(v32, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v32), v32)));
  out->m_vec.m_quad = _mm_xor_ps(
                        (__m128)_mm_slli_epi32(
                                  _mm_srli_epi32(
                                    *(__m128i *)((char *)hkVector4fComparison_maskToComparison_112
                                               + 4 * (signed int)(4 * (v2 >> 28))),
                                    0x1Fu),
                                  0x1Fu),
                        _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v8), 196));
}

// File Line: 717
// RVA: 0xBAB850
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion40(const char *in, hkQuaternionf *out)
{
  __m128i v2; // xmm6
  hkQuaternionf *v3; // r8
  signed __int64 v4; // rdx
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  __int64 v7; // rax
  char v8; // cl
  __int64 v9; // rax
  char v10; // cl
  __int64 v11; // rax
  char v12; // cl
  __int64 v13; // rax
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  int v18; // eax
  __m128 v19; // xmm5
  __m128 v20; // xmm0
  __m128 v21; // xmm0
  __int128 v22; // [rsp+0h] [rbp-38h]
  __m128i v23; // [rsp+10h] [rbp-28h]

  v2 = _mm_loadl_epi64((const __m128i *)in);
  v3 = out;
  v4 = 0i64;
  _mm_store_si128((__m128i *)&v22, v2);
  v5 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_2047_0), (__m128)LODWORD(FLOAT_2047_0), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_00034543566), (__m128)LODWORD(FLOAT_0_00034543566), 0);
  do
  {
    v7 = (unsigned __int8)permBytes[v4];
    v4 += 4i64;
    v8 = *((_BYTE *)&v22 + v7);
    v9 = (unsigned __int8)permBytes[v4 - 3];
    *((_BYTE *)&v22 + v4 + 12) = v8;
    v10 = *((_BYTE *)&v22 + v9);
    v11 = (unsigned __int8)permBytes[v4 - 2];
    *((_BYTE *)&v22 + v4 + 13) = v10;
    v12 = *((_BYTE *)&v22 + v11);
    v13 = (unsigned __int8)permBytes[v4 - 1];
    *((_BYTE *)&v22 + v4 + 14) = v12;
    *((_BYTE *)&v22 + v4 + 15) = *((_BYTE *)&v22 + v13);
  }
  while ( v4 < 16 );
  v14 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_cvtepi32_ps(
              _mm_or_si128(
                _mm_and_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_srli_epi32(_mm_load_si128(&v23), 4u), (__m128i)xmmword_141A4E940),
                    _mm_andnot_si128((__m128i)xmmword_141A4E940, v23)),
                  *(__m128i *)mask_1),
                *(__m128i *)constant)),
            v5),
          v6);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_sub_ps(query.m_quad, _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16));
  v18 = _mm_cvtsi128_si32(_mm_shuffle_epi32(_mm_and_si128(v2, *(__m128i *)signmask2), 85));
  v19 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      _mm_cmpeq_epi32(
                        _mm_shuffle_epi32(_mm_and_si128(v2, *(__m128i *)signmask), 85),
                        *(__m128i *)signmask),
                      0x1Fu),
                    0x1Fu),
          _mm_andnot_ps(_mm_cmpleps(v17, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v17), v17)));
  if ( v18 )
  {
    switch ( v18 )
    {
      case 16:
        v21 = _mm_shuffle_ps(v14, v14, 156);
        v3->m_vec.m_quad = _mm_shuffle_ps(_mm_unpacklo_ps(v21, v19), v21, 228);
        return;
      case 32:
        v20 = _mm_shuffle_ps(v14, v14, 180);
        v3->m_vec.m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v19), 180);
        return;
      case 48:
        v3->m_vec.m_quad = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v19), 196);
        return;
    }
  }
  else
  {
    v14 = _mm_shuffle_ps(v14, v14, 147);
    v14.m128_f32[0] = v19.m128_f32[0];
  }
  *v3 = (hkQuaternionf)v14;
}

// File Line: 1169
// RVA: 0xBABA20
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion48(const char *in8, hkQuaternionf *out)
{
  __int16 v2; // di
  __int16 v3; // bx
  hkQuaternionf *v4; // rsi
  unsigned int v5; // eax
  __int16 v6; // r11
  unsigned int v7; // edi
  int v8; // edx
  __m128 v9; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128i v14; // [rsp+0h] [rbp-18h]

  v2 = *((_WORD *)in8 + 1);
  v3 = *((_WORD *)in8 + 2);
  v4 = out;
  v5 = *(unsigned __int16 *)in8;
  v6 = v2 & 0x7FFF;
  _mm_store_si128(&v14, _mm_load_si128((const __m128i *)&_xmm));
  v7 = ((v5 >> 1) | v2 & 0x8000) >> 14;
  v14.m128i_i32[v7 == 0] = v5 & 0x7FFF;
  v8 = ((v7 == 0) + 1 == v7) + (v7 == 0) + 1;
  v14.m128i_i32[v8] = v6;
  v14.m128i_i32[v8 + 1 + (unsigned __int64)(v8 + 1 == v7)] = v3 & 0x7FFF;
  v9 = _mm_mul_ps(
         _mm_sub_ps(
           _mm_cvtepi32_ps(v14),
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_16383_0), (__m128)LODWORD(FLOAT_16383_0), 0)),
         _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000043161006), (__m128)LODWORD(FLOAT_0_000043161006), 0));
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_sub_ps(query.m_quad, _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11));
  v13 = _mm_andnot_ps(_mm_cmpleps(v12, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v12), v12));
  if ( v3 < 0 )
    v13 = _mm_sub_ps((__m128)0i64, v13);
  v4->m_vec.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v7], v9),
                       _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v7], v13));
}

// File Line: 1253
// RVA: 0xBABB70
void __fastcall hkaSignedQuaternion::unpackSignedQuaternion128(const char *in8, hkQuaternionf *out)
{
  *out = *(hkQuaternionf *)in8;
}

// File Line: 1265
// RVA: 0xBABB80
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion24(char *dataInOut)
{
  ;
}

// File Line: 1274
// RVA: 0xBABB90
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion16(char *dataInOut)
{
  ;
}

// File Line: 1282
// RVA: 0xBABBA0
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion32(char *dataInOut)
{
  char v1; // dl
  char v2; // dl

  v1 = *dataInOut;
  *dataInOut = dataInOut[3];
  dataInOut[3] = v1;
  v2 = dataInOut[1];
  dataInOut[1] = dataInOut[2];
  dataInOut[2] = v2;
}

// File Line: 1291
// RVA: 0xBABBD0
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion40(char *dataInOut)
{
  ;
}

// File Line: 1299
// RVA: 0xBABBE0
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion48(char *dataInOut)
{
  char v1; // dl
  char *v2; // r8
  char v3; // dl
  char v4; // al
  char v5; // cl

  v1 = *dataInOut;
  v2 = dataInOut;
  *dataInOut = dataInOut[1];
  dataInOut[1] = v1;
  v3 = dataInOut[2];
  dataInOut[2] = dataInOut[3];
  dataInOut[3] = v3;
  v4 = dataInOut[5];
  v5 = dataInOut[4];
  v2[4] = v4;
  v2[5] = v5;
}

// File Line: 1309
// RVA: 0xBABC20
void __fastcall hkaSignedQuaternion::handleEndianSignedQuaternion128(char *dataInOut)
{
  char v1; // dl
  char *v2; // r8
  char v3; // dl
  char v4; // cl
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char v9; // cl

  v1 = *dataInOut;
  v2 = dataInOut;
  *dataInOut = dataInOut[3];
  dataInOut[3] = v1;
  v3 = dataInOut[1];
  dataInOut[1] = dataInOut[2];
  dataInOut[2] = v3;
  v4 = dataInOut[4];
  v2[4] = v2[7];
  v2[7] = v4;
  v5 = v2[5];
  v2[5] = v2[6];
  v2[6] = v5;
  v6 = v2[8];
  v2[8] = v2[11];
  v2[11] = v6;
  v7 = v2[9];
  v2[9] = v2[10];
  v2[10] = v7;
  v8 = v2[12];
  v2[12] = v2[15];
  v2[15] = v8;
  v9 = v2[13];
  v2[13] = v2[14];
  v2[14] = v9;
}

// File Line: 1326
// RVA: 0xBABCB0
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion16()
{
  return FLOAT_0_25;
}

// File Line: 1332
// RVA: 0xBABCC0
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion24()
{
  return FLOAT_0_03125;
}

// File Line: 1338
// RVA: 0xBABCD0
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion32()
{
  return FLOAT_0_0078125;
}

// File Line: 1344
// RVA: 0xBABCE0
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion40()
{
  return FLOAT_0_0009765625;
}

// File Line: 1350
// RVA: 0xBABCF0
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion48()
{
  return FLOAT_0_00012207031;
}

// File Line: 1356
// RVA: 0xBABD00
float __fastcall hkaSignedQuaternion::getApproximateAccuracySignedQuaternion128()
{
  return FLOAT_2_3841858eN7;
}

// File Line: 1364
// RVA: 0xBAAAC0
const char *__fastcall hkaCompression::computePackedNurbsOffsets(const char *base, const unsigned int *m_blockOffsets, unsigned int block, unsigned int maskAndQuantizationSize)
{
  unsigned int v4; // ebx
  __int64 v5; // rdi
  const unsigned int *v6; // rsi
  const char *v7; // r14
  __int64 v9; // rax

  v4 = maskAndQuantizationSize;
  v5 = block;
  v6 = m_blockOffsets;
  v7 = base;
  if ( !HK_flyingcolors_animation.m_bool )
  {
    hkaCheckKeycode();
    hkaProcessFlyingColors(&HK_flyingcolors_animation);
    if ( !HK_flyingcolors_animation.m_bool )
      return 0i64;
  }
  v9 = v4;
  LODWORD(v9) = v4 & 0x7FFFFFFF;
  return &v7[v6[v5] + v9];
}

