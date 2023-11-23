// File Line: 13
// RVA: 0xC87EA0
void __fastcall hkQuaterniond::setAxisAngle(hkQuaterniond *this, hkVector4d *axis, hkSimdDouble64 *angle)
{
  __m128i si128; // xmm6
  __m128d v4; // xmm9
  __m128i v5; // xmm7
  __m128d v6; // xmm3
  __m128i v7; // xmm6
  __m128d v8; // xmm2
  __m128d v9; // xmm5
  __m128d v10; // xmm4
  __m128d v11; // xmm2
  __m128d v12; // xmm3
  __m128d v13; // xmm1
  __m128d v14; // xmm3

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v4 = _mm_add_pd(_mm_mul_pd(angle->m_real, g_vectordConstants[17].xy), *(__m128d *)offset_0);
  v5 = _mm_add_epi32(si128, si128);
  v6 = _mm_andn_pd(*(__m128d *)_xmm, v4);
  v7 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(*(__m128d *)fourDivPi, v6)), si128));
  v8 = _mm_cvtepi32_pd(v7);
  v9 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v7, v5), (__m128i)0i64), 80);
  v10 = _mm_add_pd(
          _mm_add_pd(_mm_add_pd(_mm_mul_pd(v8, *(__m128d *)DP1), v6), _mm_mul_pd(v8, *(__m128d *)DP2_0)),
          _mm_mul_pd(v8, *(__m128d *)DP3_0));
  v11 = _mm_mul_pd(v10, v10);
  v12 = _mm_xor_pd(
          _mm_or_pd(
            _mm_andn_pd(
              v9,
              _mm_add_pd(
                _mm_sub_pd(
                  _mm_mul_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(v11, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                      v11),
                                    *(__m128d *)cosCoeff2),
                                  v11),
                                *(__m128d *)cosCoeff3),
                              v11),
                            *(__m128d *)cosCoeff4),
                          v11),
                        *(__m128d *)cosCoeff5),
                      v11),
                    v11),
                  _mm_mul_pd(v11, *(__m128d *)_xmm)),
                *(__m128d *)_xmm)),
            _mm_and_pd(
              _mm_add_pd(
                _mm_mul_pd(
                  _mm_mul_pd(
                    _mm_add_pd(
                      _mm_mul_pd(
                        _mm_add_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(_mm_mul_pd(*(__m128d *)sinCoeff0_0, v11), *(__m128d *)sinCoeff1),
                                    v11),
                                  *(__m128d *)sinCoeff2),
                                v11),
                              *(__m128d *)sinCoeff3),
                            v11),
                          *(__m128d *)sinCoeff4),
                        v11),
                      *(__m128d *)sinCoeff5),
                    v11),
                  v10),
                v10),
              v9)),
          _mm_xor_pd(
            (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v5, v5), v7), 0x1Du), 80),
            _mm_and_pd(*(__m128d *)_xmm, v4)));
  v13 = _mm_shuffle_pd(v12, v12, 0);
  v14 = _mm_shuffle_pd(v12, v12, 3);
  v11.m128d_f64[0] = axis->m_quad.zw.m128d_f64[0] * v13.m128d_f64[0];
  this->m_vec.m_quad.xy = _mm_mul_pd(axis->m_quad.xy, v13);
  v14.m128d_f64[0] = v11.m128d_f64[0];
  this->m_vec.m_quad.zw = v14;
}

// File Line: 24
// RVA: 0xC87E70
void __fastcall hkQuaterniond::setAxisAngle(hkQuaterniond *this, hkVector4d *axis, double angle)
{
  __m128d v3; // xmm0
  hkSimdDouble64 anglea; // [rsp+20h] [rbp-18h] BYREF

  v3.m128d_f64[0] = angle;
  anglea.m_real = _mm_shuffle_pd(v3, v3, 0);
  hkQuaterniond::setAxisAngle(this, axis, &anglea);
}

// File Line: 29
// RVA: 0xC88090
void __fastcall hkQuaterniond::setAxisAngle_Approximate(hkQuaterniond *this, hkVector4d *axis, hkSimdDouble64 *angle)
{
  __m128d v3; // xmm1
  __m128i v4; // xmm1
  __m128i v5; // xmm0
  __m128d v6; // xmm3
  __m128d v7; // xmm1
  __m128d v8; // xmm3

  v3 = _mm_add_pd(_mm_mul_pd(angle->m_real, g_vectordConstants[17].xy), *(__m128d *)offset_0);
  v4 = (__m128i)_mm_sub_pd(v3, _mm_and_pd(_mm_cmpnlt_pd(v3, *(__m128d *)pi), *(__m128d *)twopi_0));
  v5 = (__m128i)_mm_add_pd(
                  _mm_mul_pd(
                    _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v4, 1u), 1u), (__m128d)v4),
                    *(__m128d *)C_0),
                  _mm_mul_pd((__m128d)v4, *(__m128d *)fourDivPi));
  v6 = _mm_add_pd(
         _mm_mul_pd(
           _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v5, 1u), 1u), (__m128d)v5), (__m128d)v5),
           *(__m128d *)P),
         (__m128d)v5);
  v7 = _mm_shuffle_pd(v6, v6, 0);
  v8 = _mm_shuffle_pd(v6, v6, 3);
  v8.m128d_f64[0] = axis->m_quad.zw.m128d_f64[0] * v7.m128d_f64[0];
  this->m_vec.m_quad.xy = _mm_mul_pd(axis->m_quad.xy, v7);
  this->m_vec.m_quad.zw = v8;
}

// File Line: 40
// RVA: 0xC881A0
void __fastcall hkQuaterniond::setFromEulerAngles(
        hkQuaterniond *this,
        hkSimdDouble64 *roll,
        hkSimdDouble64 *pitch,
        hkSimdDouble64 *yaw)
{
  _OWORD *v4; // rbp
  __m128i si128; // xmm3
  __m128d v6; // xmm6
  __m128i v7; // xmm4
  __m128d v8; // xmm8
  __m128d v9; // xmm2
  __m128i v10; // xmm5
  __m128d v11; // xmm4
  __m128d v12; // xmm0
  __m128d v13; // xmm3
  __m128d v14; // xmm2
  __m128d v15; // xmm7
  __m128d v16; // xmm0
  __m128i v17; // xmm4
  __m128d v18; // xmm7
  __m128d v19; // xmm2
  __m128i v20; // xmm6
  __m128d v21; // xmm1
  __m128d v22; // xmm5
  __m128d v23; // xmm4
  __m128d v24; // xmm2
  __m128d v25; // xmm0
  __m128i v26; // xmm4
  __m128d v27; // xmm3
  __m128d v28; // xmm8
  __m128d v29; // xmm7
  __m128d v30; // xmm8
  __m128d v31; // xmm7
  __m128d v32; // xmm6
  __m128d v33; // xmm2
  __m128i v34; // xmm0
  __m128i v35; // xmm0
  __m128d v36; // xmm4
  __m128d v37; // xmm0
  __m128d v38; // xmm3
  __m128d v39; // xmm2
  __m128i v40; // xmm0
  __m128d v41; // xmm5
  __m128d v42; // xmm0
  __m128d v43; // xmm5
  __m128d v44; // xmm2
  __m128d v45; // xmm0
  __m128d v46; // xmm7
  __m128d v47; // xmm8
  _BYTE v48[96]; // [rsp+88h] [rbp+88h] BYREF

  v4 = (_OWORD *)((unsigned __int64)v48 & 0xFFFFFFFFFFFFFFE0ui64);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v6 = _mm_add_pd(
         _mm_mul_pd(_mm_unpacklo_pd(pitch->m_real, pitch->m_real), g_vectordConstants[17].xy),
         *(__m128d *)offset_0);
  v7 = _mm_add_epi32(si128, si128);
  v8 = _mm_add_pd(
         _mm_mul_pd(_mm_unpacklo_pd(roll->m_real, roll->m_real), g_vectordConstants[17].zw),
         *(__m128d *)offset_0);
  v9 = _mm_andn_pd(*(__m128d *)_xmm, v6);
  *v4 = v7;
  v10 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(v9, *(__m128d *)fourDivPi)), si128));
  v11 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v10, v7), (__m128i)0i64), 80);
  v12 = _mm_cvtepi32_pd(v10);
  v13 = _mm_add_pd(
          _mm_add_pd(_mm_add_pd(_mm_mul_pd(v12, *(__m128d *)DP1), v9), _mm_mul_pd(v12, *(__m128d *)DP2_0)),
          _mm_mul_pd(v12, *(__m128d *)DP3_0));
  v14 = _mm_mul_pd(v13, v13);
  v15 = _mm_andn_pd(
          v11,
          _mm_add_pd(
            _mm_sub_pd(
              _mm_mul_pd(
                _mm_mul_pd(
                  _mm_add_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(_mm_mul_pd(v14, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                  v14),
                                *(__m128d *)cosCoeff2),
                              v14),
                            *(__m128d *)cosCoeff3),
                          v14),
                        *(__m128d *)cosCoeff4),
                      v14),
                    *(__m128d *)cosCoeff5),
                  v14),
                v14),
              _mm_mul_pd(v14, *(__m128d *)_xmm)),
            *(__m128d *)_xmm));
  v16 = _mm_and_pd(
          _mm_add_pd(
            _mm_mul_pd(
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(
                    _mm_add_pd(
                      _mm_mul_pd(
                        _mm_add_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(_mm_mul_pd(*(__m128d *)sinCoeff0_0, v14), *(__m128d *)sinCoeff1),
                                v14),
                              *(__m128d *)sinCoeff2),
                            v14),
                          *(__m128d *)sinCoeff3),
                        v14),
                      *(__m128d *)sinCoeff4),
                    v14),
                  *(__m128d *)sinCoeff5),
                v14),
              v13),
            v13),
          v11);
  v17 = _mm_load_si128((const __m128i *)((unsigned __int64)v48 & 0xFFFFFFFFFFFFFFE0ui64));
  v18 = _mm_xor_pd(
          _mm_or_pd(v15, v16),
          _mm_xor_pd(
            (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v17, v17), v10), 0x1Du), 80),
            _mm_and_pd(v6, *(__m128d *)_xmm)));
  v19 = _mm_andn_pd(*(__m128d *)_xmm, v8);
  v20 = _mm_andnot_si128(
          _mm_load_si128((const __m128i *)_xmm),
          _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(v19, *(__m128d *)fourDivPi)), *(__m128i *)_xmm));
  v21 = _mm_cvtepi32_pd(v20);
  v22 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v20, v17), (__m128i)0i64), 80);
  v23 = _mm_add_pd(
          _mm_add_pd(_mm_add_pd(_mm_mul_pd(v21, *(__m128d *)DP1), v19), _mm_mul_pd(v21, *(__m128d *)DP2_0)),
          _mm_mul_pd(v21, *(__m128d *)DP3_0));
  v24 = _mm_mul_pd(v23, v23);
  v25 = _mm_add_pd(
          _mm_mul_pd(
            _mm_mul_pd(
              _mm_add_pd(
                _mm_mul_pd(
                  _mm_add_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v24, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1), v24),
                            *(__m128d *)sinCoeff2),
                          v24),
                        *(__m128d *)sinCoeff3),
                      v24),
                    *(__m128d *)sinCoeff4),
                  v24),
                *(__m128d *)sinCoeff5),
              v24),
            v23),
          v23);
  v26 = _mm_load_si128((const __m128i *)((unsigned __int64)v48 & 0xFFFFFFFFFFFFFFE0ui64));
  v27 = _mm_xor_pd(
          _mm_or_pd(
            _mm_andn_pd(
              v22,
              _mm_add_pd(
                _mm_sub_pd(
                  _mm_mul_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(v24, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                      v24),
                                    *(__m128d *)cosCoeff2),
                                  v24),
                                *(__m128d *)cosCoeff3),
                              v24),
                            *(__m128d *)cosCoeff4),
                          v24),
                        *(__m128d *)cosCoeff5),
                      v24),
                    v24),
                  _mm_mul_pd(v24, *(__m128d *)_xmm)),
                *(__m128d *)_xmm)),
            _mm_and_pd(v25, v22)),
          _mm_xor_pd(
            (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v26, v26), v20), 0x1Du), 80),
            _mm_and_pd(v8, *(__m128d *)_xmm)));
  v28 = _mm_unpacklo_pd(v18, v18);
  v28.m128d_f64[0] = _mm_unpackhi_pd(v18, v18).m128d_f64[0];
  v29 = v28;
  v30 = _mm_mul_pd(v28, _mm_unpacklo_pd(v27, v27));
  v31 = _mm_mul_pd(v29, _mm_unpackhi_pd(v27, v27));
  v32 = _mm_add_pd(_mm_mul_pd(yaw->m_real, g_vectordConstants[17].xy), *(__m128d *)offset_0);
  v33 = _mm_andn_pd(*(__m128d *)_xmm, v32);
  v34 = _mm_load_si128((const __m128i *)_xmm);
  v35 = _mm_andnot_si128(v34, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(v33, *(__m128d *)fourDivPi)), v34));
  v4[1] = v35;
  v36 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v35, v26), (__m128i)0i64), 80);
  v37 = _mm_cvtepi32_pd(v35);
  v38 = _mm_add_pd(
          _mm_add_pd(_mm_add_pd(_mm_mul_pd(v37, *(__m128d *)DP1), v33), _mm_mul_pd(v37, *(__m128d *)DP2_0)),
          _mm_mul_pd(v37, *(__m128d *)DP3_0));
  v39 = _mm_mul_pd(v38, v38);
  v40 = _mm_load_si128((const __m128i *)((unsigned __int64)v48 & 0xFFFFFFFFFFFFFFE0ui64));
  v41 = _mm_xor_pd(
          _mm_or_pd(
            _mm_andn_pd(
              v36,
              _mm_add_pd(
                _mm_sub_pd(
                  _mm_mul_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(v39, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                      v39),
                                    *(__m128d *)cosCoeff2),
                                  v39),
                                *(__m128d *)cosCoeff3),
                              v39),
                            *(__m128d *)cosCoeff4),
                          v39),
                        *(__m128d *)cosCoeff5),
                      v39),
                    v39),
                  _mm_mul_pd(v39, *(__m128d *)_xmm)),
                *(__m128d *)_xmm)),
            _mm_and_pd(
              _mm_add_pd(
                _mm_mul_pd(
                  _mm_mul_pd(
                    _mm_add_pd(
                      _mm_mul_pd(
                        _mm_add_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(_mm_mul_pd(v39, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1),
                                    v39),
                                  *(__m128d *)sinCoeff2),
                                v39),
                              *(__m128d *)sinCoeff3),
                            v39),
                          *(__m128d *)sinCoeff4),
                        v39),
                      *(__m128d *)sinCoeff5),
                    v39),
                  v38),
                v38),
              v36)),
          _mm_xor_pd(
            (__m128d)_mm_shuffle_epi32(
                       _mm_slli_epi32(
                         _mm_and_si128(
                           _mm_add_epi32(v40, v40),
                           *(__m128i *)(((unsigned __int64)v48 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10)),
                         0x1Du),
                       80),
            _mm_and_pd(v32, *(__m128d *)_xmm)));
  v42 = _mm_shuffle_pd(v41, v41, 0);
  v43 = _mm_shuffle_pd(v41, v41, 3);
  v44 = _mm_mul_pd(v30, v42);
  v45 = _mm_xor_pd(
          (__m128d)_mm_slli_epi64(_mm_srli_epi64(*(__m128i *)hkVector4dComparison_maskToComparison_98, 0x3Fu), 0x3Fu),
          _mm_mul_pd(v31, v42));
  v46 = _mm_mul_pd(v31, v43);
  v47 = _mm_mul_pd(v30, v43);
  this->m_vec.m_quad.xy = _mm_add_pd(_mm_shuffle_pd(v47, v47, 1), v45);
  this->m_vec.m_quad.zw = _mm_add_pd(
                            _mm_shuffle_pd(v46, v46, 1),
                            _mm_xor_pd(
                              (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A74390, 0x3Fu), 0x3Fu),
                              v44));
}

// File Line: 84
// RVA: 0xC88150
// local variable allocation has failed, the output may be wrong!
void __fastcall hkQuaterniond::setFromEulerAngles(hkQuaterniond *this, double roll, double pitch, double yaw)
{
  __m128d v4; // xmm0
  __m128d v5; // xmm0
  hkSimdDouble64 yawa; // [rsp+20h] [rbp-38h] BYREF
  hkSimdDouble64 pitcha; // [rsp+30h] [rbp-28h] BYREF
  hkSimdDouble64 rolla; // [rsp+40h] [rbp-18h] BYREF

  v4.m128d_f64[0] = yaw;
  v5 = _mm_shuffle_pd(v4, v4, 0);
  pitcha.m_real = _mm_shuffle_pd(*(__m128d *)&pitch, *(__m128d *)&pitch, 0);
  yawa.m_real = v5;
  v5.m128d_f64[0] = roll;
  rolla.m_real = _mm_shuffle_pd(v5, v5, 0);
  hkQuaterniond::setFromEulerAngles(this, &rolla, &pitcha, &yawa);
}

// File Line: 89
// RVA: 0xC88720
void __fastcall hkQuaterniond::setFromEulerAngles_Approximate(
        hkQuaterniond *this,
        hkSimdDouble64 *roll,
        hkSimdDouble64 *pitch,
        hkSimdDouble64 *yaw)
{
  __m128d v4; // xmm1
  __m128d v5; // xmm2
  __m128d v6; // xmm9
  __m128i v7; // xmm1
  __m128i v8; // xmm0
  __m128d v9; // xmm10
  __m128i v10; // xmm2
  __m128i v11; // xmm0
  __m128d v12; // xmm2
  __m128d v13; // xmm6
  __m128i v14; // xmm9
  __m128d v15; // xmm5
  __m128i v16; // xmm0
  __m128d v17; // xmm1
  __m128d v18; // xmm6
  __m128d v19; // xmm5
  __m128d v20; // xmm0
  __m128d v21; // xmm10
  __m128d v22; // xmm2
  __m128d v23; // xmm6
  __m128d v24; // xmm3
  __m128d v25; // xmm5
  __m128d v26; // xmm1
  __m128d v27; // xmm0

  v4 = _mm_add_pd(_mm_mul_pd(yaw->m_real, g_vectordConstants[17].xy), *(__m128d *)offset_0);
  v5 = _mm_add_pd(
         _mm_mul_pd(_mm_unpacklo_pd(pitch->m_real, pitch->m_real), g_vectordConstants[17].xy),
         *(__m128d *)offset_0);
  v6 = _mm_add_pd(
         _mm_mul_pd(_mm_unpacklo_pd(roll->m_real, roll->m_real), g_vectordConstants[17].zw),
         *(__m128d *)offset_0);
  v7 = (__m128i)_mm_sub_pd(v4, _mm_and_pd(_mm_cmpnlt_pd(v4, *(__m128d *)pi), *(__m128d *)twopi_0));
  v8 = (__m128i)_mm_add_pd(
                  _mm_mul_pd(
                    _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v7, 1u), 1u), (__m128d)v7),
                    *(__m128d *)C_0),
                  _mm_mul_pd((__m128d)v7, *(__m128d *)fourDivPi));
  v9 = _mm_add_pd(
         _mm_mul_pd(
           _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v8, 1u), 1u), (__m128d)v8), (__m128d)v8),
           *(__m128d *)P),
         (__m128d)v8);
  v10 = (__m128i)_mm_sub_pd(v5, _mm_and_pd(_mm_cmpnlt_pd(v5, *(__m128d *)pi), *(__m128d *)twopi_0));
  v11 = (__m128i)_mm_add_pd(
                   _mm_mul_pd(
                     _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v10, 1u), 1u), (__m128d)v10),
                     *(__m128d *)C_0),
                   _mm_mul_pd((__m128d)v10, *(__m128d *)fourDivPi));
  v12 = _mm_add_pd(
          _mm_mul_pd(
            _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v11, 1u), 1u), (__m128d)v11), (__m128d)v11),
            *(__m128d *)P),
          (__m128d)v11);
  v13 = _mm_unpacklo_pd(v12, v12);
  v14 = (__m128i)_mm_sub_pd(v6, _mm_and_pd(_mm_cmpnlt_pd(v6, *(__m128d *)pi), *(__m128d *)twopi_0));
  v13.m128d_f64[0] = _mm_unpackhi_pd(v12, v12).m128d_f64[0];
  v15 = v13;
  v16 = (__m128i)_mm_add_pd(
                   _mm_mul_pd(
                     _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v14, 1u), 1u), (__m128d)v14),
                     *(__m128d *)C_0),
                   _mm_mul_pd((__m128d)v14, *(__m128d *)fourDivPi));
  v17 = _mm_add_pd(
          _mm_mul_pd(
            _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v16, 1u), 1u), (__m128d)v16), (__m128d)v16),
            *(__m128d *)P),
          (__m128d)v16);
  v18 = _mm_mul_pd(v13, _mm_unpacklo_pd(v17, v17));
  v19 = _mm_mul_pd(v15, _mm_unpackhi_pd(v17, v17));
  v20 = _mm_unpacklo_pd(v9, v9);
  v21 = _mm_unpackhi_pd(v9, v9);
  v22 = _mm_mul_pd(v18, v20);
  v23 = _mm_mul_pd(v18, v21);
  v24 = _mm_xor_pd(
          (__m128d)_mm_slli_epi64(_mm_srli_epi64(*(__m128i *)hkVector4dComparison_maskToComparison_98, 0x3Fu), 0x3Fu),
          _mm_mul_pd(v19, v20));
  v25 = _mm_mul_pd(v19, v21);
  v26 = _mm_unpacklo_pd(v23, v23);
  v27 = _mm_unpackhi_pd(v25, v25);
  v27.m128d_f64[0] = v25.m128d_f64[0];
  v26.m128d_f64[0] = _mm_unpackhi_pd(v23, v23).m128d_f64[0];
  this->m_vec.m_quad.zw = _mm_add_pd(
                            v27,
                            _mm_xor_pd(
                              (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A74390, 0x3Fu), 0x3Fu),
                              v22));
  this->m_vec.m_quad.xy = _mm_add_pd(v26, v24);
}

// File Line: 120
// RVA: 0xC8A7B0
_BOOL8 __fastcall hkQuaterniond::isOk(hkQuaterniond *this, double epsilon)
{
  BOOL v3; // eax
  __m128d v4; // xmm2
  __m128d v5; // xmm0
  long double v6; // xmm1_8
  __m128d v7; // xmm0
  long double v8; // xmm1_8
  _BOOL8 result; // rax

  v3 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_vec.m_quad.xy, (__m128d)0i64))
    && !_mm_movemask_pd(_mm_cmpunord_pd(this->m_vec.m_quad.zw, (__m128d)0i64));
  v4 = _mm_mul_pd(this->m_vec.m_quad.xy, this->m_vec.m_quad.xy);
  v5 = _mm_mul_pd(this->m_vec.m_quad.zw, this->m_vec.m_quad.zw);
  result = 0;
  if ( v3 )
  {
    v6 = _mm_shuffle_pd(v5, v5, 1).m128d_f64[0] + v5.m128d_f64[0];
    v7 = _mm_add_pd(_mm_shuffle_pd(v4, v4, 1), v4);
    v8 = v6 + v7.m128d_f64[0];
    v7.m128d_f64[0] = epsilon;
    if ( COERCE_DOUBLE((unsigned __int64)(2 * COERCE__INT64(v8 - 1.0)) >> 1) < _mm_shuffle_pd(v7, v7, 0).m128d_f64[0] )
      return 1;
  }
  return result;
}

// File Line: 129
// RVA: 0xC88970
void __fastcall hkQuaterniond::set(hkQuaterniond *this, hkRotationd *r)
{
  double *v2; // rbp
  double v3; // xmm3_8
  double v4; // xmm2_8
  double v5; // xmm4_8
  double v7; // xmm1_8
  long double v8; // xmm0_8
  double v9; // xmm4_8
  long double v10; // xmm1_8
  double v11; // xmm0_8
  int v12; // edx
  __int64 v13; // r9
  __int64 v14; // rdi
  hkQuadDouble64 *v15; // r11
  __int64 v16; // rbx
  double *v17; // r12
  hkQuadDouble64 *v18; // r10
  double *v19; // r15
  hkQuadDouble64 *v20; // r8
  double *v21; // rax
  double v22; // xmm2_8
  double v23; // xmm3_8
  double *v24; // r15
  double *v25; // rax
  double *v26; // r9
  double *v27; // rax
  double *v28; // r9
  double *v29; // rax
  __m128d v30; // xmm1
  __int64 v31[4]; // [rsp+20h] [rbp+0h] BYREF

  v2 = (double *)((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64);
  v3 = r->m_col0.m_quad.xy.m128d_f64[0];
  v4 = r->m_col1.m_quad.xy.m128d_f64[1];
  v5 = r->m_col2.m_quad.zw.m128d_f64[0];
  v7 = r->m_col0.m_quad.xy.m128d_f64[0] + v4 + v5;
  if ( v7 <= 0.0 )
  {
    v12 = 0;
    *(_DWORD *)v2 = 1;
    if ( v4 > v3 )
      v12 = 1;
    *(_QWORD *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 4) = 2i64;
    if ( v5 > r->m_col0.m_quad.xy.m128d_f64[4 * v12 + v12] )
      v12 = 2;
    v13 = *((int *)v2 + v12);
    v14 = *((int *)v2 + v13);
    v15 = &r->m_col0.m_quad + v12;
    v16 = v13;
    if ( v12 >= 2 )
      v17 = &v15->xy.m128d_f64[v12];
    else
      v17 = &v15->xy.m128d_f64[v12];
    v18 = &r->m_col0.m_quad + v13;
    if ( (int)v13 >= 2 )
      v19 = &v18->xy.m128d_f64[(int)v13];
    else
      v19 = &v18->xy.m128d_f64[v13];
    v20 = &r->m_col0.m_quad + v14;
    if ( (int)v14 >= 2 )
      v21 = &v20->xy.m128d_f64[(int)v14];
    else
      v21 = &v20->xy.m128d_f64[v14];
    *v2 = *v17 - (*v21 + *v19) + 1.0;
    v22 = sqrt(*v2);
    v23 = 0.5 / v22;
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8i64 * v12) = v22 * 0.5;
    if ( (int)v14 >= 2 )
      v24 = &v18->xy.m128d_f64[(int)v14];
    else
      v24 = &v18->xy.m128d_f64[v14];
    if ( (int)v13 >= 2 )
      v25 = &v20->xy.m128d_f64[(int)v13];
    else
      v25 = &v20->xy.m128d_f64[v13];
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = (*v24 - *v25) * v23;
    if ( (int)v13 >= 2 )
      v13 = (int)v13 - 2 + 2i64;
    v26 = &v15->xy.m128d_f64[v13];
    if ( v12 >= 2 )
      v27 = &v18->xy.m128d_f64[v12];
    else
      v27 = &v18->xy.m128d_f64[v12];
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v16) = (*v27 + *v26) * v23;
    if ( (int)v14 >= 2 )
      v28 = &v15->xy.m128d_f64[(int)v14];
    else
      v28 = &v15->xy.m128d_f64[v14];
    if ( v12 >= 2 )
      v29 = &v20->xy.m128d_f64[v12];
    else
      v29 = &v20->xy.m128d_f64[v12];
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v14) = (*v28 + *v29) * v23;
  }
  else
  {
    v8 = r->m_col1.m_quad.zw.m128d_f64[0] - r->m_col2.m_quad.xy.m128d_f64[1];
    *v2 = v7 + 1.0;
    v9 = sqrt(*v2);
    v10 = r->m_col2.m_quad.xy.m128d_f64[0] - r->m_col0.m_quad.zw.m128d_f64[0];
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = v9 * 0.5;
    *(long double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v8 * (0.5 / v9);
    v11 = r->m_col0.m_quad.xy.m128d_f64[1];
    *(long double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x28) = v10 * (0.5 / v9);
    *(double *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = (v11 - r->m_col1.m_quad.xy.m128d_f64[0])
                                                                         * (0.5
                                                                          / v9);
  }
  v30 = *(__m128d *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  this->m_vec.m_quad.xy = *(__m128d *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  this->m_vec.m_quad.zw = v30;
}

// File Line: 134
// RVA: 0xC8A850
void __fastcall hkQuaterniond::setFlippedRotation(hkQuaterniond *this, hkVector4d *from)
{
  __m128d v2; // xmm9
  unsigned __int64 v3; // xmm8_8
  __m128d v4; // xmm5
  unsigned __int64 v5; // xmm7_8
  __m128d v6; // xmm6
  __m128d v7; // xmm2
  __m128d v8; // xmm0
  __m128d v9; // xmm1
  __m128d v10; // xmm3
  __m128d v11; // xmm4
  __m128d v12; // xmm0
  __m128d v13; // xmm5
  __m128d v14; // xmm1
  __m128d v15; // xmm6
  __m128d v16; // xmm0
  __m128d v17; // xmm3
  __m128d v18; // xmm2
  __m128d v19; // xmm4

  v2 = 0i64;
  v3 = *(unsigned __int64 *)&from->m_quad.zw.m128d_f64[0];
  v4 = _mm_shuffle_pd(from->m_quad.xy, from->m_quad.xy, 1);
  v5 = *(unsigned __int64 *)&from->m_quad.xy.m128d_f64[0];
  v6 = _mm_unpackhi_pd((__m128d)v3, (__m128d)v3);
  v7 = _mm_mul_pd((__m128d)v3, (__m128d)v3);
  v8 = _mm_mul_pd(v4, v4);
  v9 = _mm_mul_pd(v6, v6);
  v10 = _mm_mul_pd((__m128d)v5, (__m128d)v5);
  v11 = _mm_cmplt_pd(
          _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v8, v8), _mm_unpackhi_pd(v8, v8)), _mm_unpacklo_pd(v9, v9)),
          _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v7, v7), _mm_unpackhi_pd(v7, v7)), _mm_unpacklo_pd(v10, v10)));
  v12 = _mm_or_pd(_mm_andn_pd(v11, v4), _mm_and_pd((__m128d)v3, v11));
  v13 = _mm_or_pd(_mm_andn_pd(v11, v6), _mm_and_pd((__m128d)v5, v11));
  v14 = _mm_mul_pd(v13, v13);
  v15 = _mm_xor_pd((__m128d)_mm_insert_epi16((__m128i)0i64, 0x8000u, 3), v12);
  v16 = _mm_mul_pd(v15, v15);
  v17 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v16, v16), _mm_unpackhi_pd(v16, v16)), _mm_unpacklo_pd(v14, v14));
  v18 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v17)));
  v19 = _mm_andn_pd(
          _mm_cmple_pd(v17, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v18, v17), v18)),
            _mm_mul_pd(v18, g_vectordConstants[17].xy)));
  v2.m128d_f64[0] = v19.m128d_f64[0] * v13.m128d_f64[0];
  this->m_vec.m_quad.xy = _mm_mul_pd(v15, v19);
  this->m_vec.m_quad.zw = v2;
}

// File Line: 253
// RVA: 0xC89600
void __fastcall hkQuaterniond::setBarycentric(hkQuaterniond *this, hkQuaterniond *qVerts, hkVector4d *vLambda)
{
  __m128d *v3; // rbp
  __m128d zw; // xmm0
  __m128d v7; // xmm2
  __m128d v8; // xmm4
  __m128d v9; // xmm5
  __m128i v10; // xmm10
  __m128i v11; // xmm6
  __m128d v12; // xmm2
  __m128d v13; // xmm1
  __m128d v14; // xmm0
  __int64 v15; // r8
  __m128i v16; // xmm10
  __m128d v17; // xmm4
  __m128d xy; // xmm6
  __m128d v19; // xmm7
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rdx
  __m128d v23; // xmm9
  __m128d v24; // xmm2
  __m128d v25; // xmm0
  __m128d v26; // xmm13
  __m128d v27; // xmm4
  __m128d v28; // xmm1
  __m128d v29; // xmm13
  __m128d v30; // xmm0
  __m128d v31; // xmm0
  __m128d v32; // xmm11
  __m128d v33; // xmm1
  __m128d v34; // xmm0
  __m128d v35; // xmm1
  __m128d v36; // xmm8
  __m128d v37; // xmm12
  __m128d v38; // xmm8
  __m128d v39; // xmm7
  __m128d v40; // xmm1
  __m128d v41; // xmm5
  __m128d v42; // xmm2
  __m128d v43; // xmm3
  __m128d v44; // xmm4
  __m128d v45; // xmm1
  __m128d v46; // xmm1
  __m128d v47; // xmm2
  __m128d v48; // xmm9
  __m128d v49; // xmm3
  __m128d v50; // xmm0
  __m128i si128; // xmm2
  __m128d v52; // xmm8
  __m128i v53; // xmm7
  __m128d v54; // xmm0
  __m128d v55; // xmm8
  __m128d v56; // xmm9
  __m128d v57; // xmm3
  __m128i v58; // xmm6
  __m128d v59; // xmm2
  __m128d v60; // xmm5
  __m128d v61; // xmm4
  __m128d v62; // xmm2
  __m128d v63; // xmm3
  __m128d v64; // xmm14
  __m128d v65; // xmm3
  __m128d v66; // xmm14
  __m128d v67; // xmm0
  __m128d v68; // xmm5
  __m128d v69; // xmm14
  __m128d v70; // xmm0
  __m128d v71; // xmm1
  __m128d v72; // xmm3
  __m128d v73; // xmm4
  __m128d v74; // xmm2
  __m128d v75; // xmm0
  __m128d v76; // xmm3
  __m128d v77; // xmm1
  __m128d v78; // xmm0
  __m128d v79; // xmm4
  __m128d v80; // xmm1
  __m128d v81; // xmm5
  __m128d v82; // xmm14
  __m128d v83; // xmm12
  __m128d v84; // xmm11
  __m128d v85; // xmm12
  __m128d v86; // xmm0
  __m128d v87; // xmm1
  __m128d v88; // xmm2
  __m128d v89; // xmm1
  __m128d v90; // xmm8
  __m128d v91; // xmm7
  __m128d v92; // xmm1
  __m128d v93; // xmm5
  __m128d v94; // xmm2
  __m128d v95; // xmm3
  __m128d v96; // xmm4
  __m128d v97; // xmm1
  __m128d v98; // xmm1
  __m128d v99; // xmm3
  __m128d v100; // xmm9
  __m128d v101; // xmm2
  __m128d v102; // xmm0
  __m128d v103; // xmm3
  __m128i v104; // xmm2
  __m128d v105; // xmm8
  __m128i v106; // xmm7
  __m128d v107; // xmm0
  __m128d v108; // xmm9
  __m128d v109; // xmm3
  __m128i v110; // xmm6
  __m128d v111; // xmm2
  __m128d v112; // xmm5
  __m128d v113; // xmm4
  __m128d v114; // xmm2
  __m128d v115; // xmm10
  __m128d v116; // xmm1
  __m128d v117; // xmm10
  __m128d v118; // xmm0
  __m128d v119; // xmm0
  __m128d v120; // xmm1
  __m128d v121; // xmm11
  __m128d v122; // xmm12
  __m128d v123; // xmm0
  __m128d v124; // xmm1
  __m128d v125; // xmm3
  __m128d v126; // xmm2
  __m128d v127; // xmm4
  __m128d v128; // xmm11
  __m128d v129; // xmm12
  __m128d v130; // xmm0
  __m128d v131; // xmm1
  __m128d v132; // xmm9
  __m128d v133; // xmm8
  __m128d v134; // xmm9
  __m128d v135; // xmm0
  __m128d v136; // xmm1
  __m128d v137; // xmm14
  __m128d v138; // xmm10
  __m128d v139; // xmm14
  __m128d v140; // xmm7
  __m128d v141; // xmm1
  __m128d v142; // xmm2
  __m128d v143; // xmm0
  __m128d v144; // xmm5
  __m128d v145; // xmm4
  __m128d v146; // xmm1
  __m128d v147; // xmm5
  __m128d v148; // xmm0
  __m128d v149; // xmm3
  __m128d v150; // xmm1
  __m128d v151; // xmm15
  __m128d v152; // xmm2
  __m128d v153; // xmm0
  __m128i v154; // xmm15
  __m128i v155; // xmm6
  __m128d v156; // xmm7
  __m128d v157; // xmm0
  __m128d v158; // xmm7
  __m128d v159; // xmm14
  __m128d v160; // xmm3
  __m128i v161; // xmm15
  __m128d v162; // xmm2
  __m128d v163; // xmm5
  __m128d v164; // xmm4
  __m128d v165; // xmm2
  __m128d v166; // xmm13
  __m128d v167; // xmm15
  __m128d v168; // xmm15
  __m128d v169; // xmm10
  __m128d v170; // xmm8
  __m128d v171; // xmm9
  __m128d v172; // xmm0
  __m128d v173; // xmm1
  __m128d v174; // xmm3
  __m128d v175; // xmm2
  __m128d v176; // xmm4
  __int128 v177[2]; // [rsp+20h] [rbp+0h] BYREF

  v3 = (__m128d *)((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64);
  zw = vLambda->m_quad.zw;
  v7.m128d_f64[1] = vLambda->m_quad.zw.m128d_f64[1];
  v7.m128d_f64[0] = vLambda->m_quad.xy.m128d_f64[0];
  v8 = _mm_unpacklo_pd(zw, vLambda->m_quad.xy);
  v9 = _mm_unpackhi_pd(vLambda->m_quad.xy, zw);
  v10 = (__m128i)_mm_add_pd(v8, _mm_shuffle_pd(vLambda->m_quad.xy, zw, 1));
  v11 = (__m128i)_mm_add_pd(v9, v7);
  v12 = (__m128d)_mm_srli_epi64(_mm_slli_epi64(v10, 1u), 1u);
  v13 = (__m128d)_mm_srli_epi64(_mm_slli_epi64(v11, 1u), 1u);
  v14 = _mm_max_pd(_mm_unpacklo_pd(v13, v13), _mm_max_pd(_mm_shuffle_pd(v12, v12, 1), v12));
  v15 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_pd(
                                                               _mm_and_pd(
                                                                 _mm_cmple_pd(v14, v12),
                                                                 (__m128d)xmmword_141A74390)) | (unsigned __int64)(4 * _mm_movemask_pd(_mm_and_pd(_mm_cmple_pd(v14, v13), (__m128d)xmmword_141A74370)))];
  switch ( (_DWORD)v15 )
  {
    case 1:
      v16 = (__m128i)_mm_unpackhi_pd((__m128d)v10, (__m128d)v10);
      break;
    case 2:
      v16 = (__m128i)_mm_unpacklo_pd((__m128d)v11, (__m128d)v11);
      break;
    case 3:
      v16 = (__m128i)_mm_unpackhi_pd((__m128d)v11, (__m128d)v11);
      break;
    default:
      v16 = (__m128i)_mm_unpacklo_pd((__m128d)v10, (__m128d)v10);
      break;
  }
  switch ( (_DWORD)v15 )
  {
    case 1:
      v17 = _mm_unpackhi_pd(v8, v8);
      break;
    case 2:
      v17 = _mm_unpacklo_pd(v9, v9);
      break;
    case 3:
      v17 = _mm_unpackhi_pd(v9, v9);
      break;
    default:
      v17 = _mm_unpacklo_pd(v8, v8);
      break;
  }
  xy = g_vectordConstants[4].xy;
  v19 = 0i64;
  v20 = (1 << v15) & 3;
  v21 = v15;
  v22 = (1 << ((1 << v15) & 3)) & 3;
  v23 = qVerts[v22].m_vec.m_quad.xy;
  v24 = _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps((__m128d)v16)));
  *v3 = v23;
  v25 = _mm_cmplt_pd(g_vectordConstants[34].xy, (__m128d)_mm_srli_epi64(_mm_slli_epi64(v16, 1u), 1u));
  v26 = _mm_mul_pd(_mm_mul_pd(_mm_sub_pd(g_vectordConstants[3].xy, _mm_mul_pd(v24, (__m128d)v16)), v24), v17);
  v27 = qVerts[v20].m_vec.m_quad.xy;
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v27;
  v28 = _mm_mul_pd(v27, qVerts[v15].m_vec.m_quad.xy);
  v29 = _mm_or_pd(_mm_and_pd(v26, v25), _mm_andn_pd(v25, (__m128d)0i64));
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = qVerts[v22].m_vec.m_quad.zw;
  v30 = _mm_mul_pd(qVerts[v20].m_vec.m_quad.zw, qVerts[v15].m_vec.m_quad.zw);
  v31 = (__m128d)_mm_slli_epi64(
                   _mm_srli_epi64(
                     (__m128i)_mm_add_pd(
                                _mm_add_pd(_mm_shuffle_pd(v30, v30, 1), v30),
                                _mm_add_pd(_mm_shuffle_pd(v28, v28, 1), v28)),
                     0x3Fu),
                   0x3Fu);
  v32 = _mm_xor_pd(v31, qVerts[v15].m_vec.m_quad.zw);
  v33 = _mm_xor_pd(v31, qVerts[v15].m_vec.m_quad.xy);
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v33;
  v34 = _mm_mul_pd(v32, qVerts[v20].m_vec.m_quad.zw);
  v35 = _mm_mul_pd(v33, v27);
  v36 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v34, v34, 1), v34), _mm_add_pd(_mm_shuffle_pd(v35, v35, 1), v35));
  v37 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)_mm_cmplt_pd(v36, (__m128d)0i64), 0x3Fu), 0x3Fu);
  v38 = _mm_xor_pd(v36, v37);
  if ( v38.m128d_f64[0] >= _mm_shuffle_pd(
                             (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                             (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                             0).m128d_f64[0] )
  {
    v65 = (__m128d)v16;
    v66 = _mm_sub_pd(g_vectordConstants[2].xy, (__m128d)v16);
  }
  else
  {
    v39 = _mm_andn_pd(*(__m128d *)_xmm, v38);
    v40 = _mm_sub_pd(*(__m128d *)_xmm, v39);
    v41 = _mm_cmplt_pd(*(__m128d *)limit, v39);
    v42 = _mm_mul_pd(v39, v39);
    v43 = _mm_sqrt_pd(_mm_add_pd(v40, v40));
    v44 = _mm_div_pd(
            _mm_mul_pd(
              _mm_add_pd(
                _mm_mul_pd(
                  _mm_add_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v40, *(__m128d *)R0), *(__m128d *)R1), v40),
                        *(__m128d *)R2),
                      v40),
                    *(__m128d *)R3),
                  v40),
                *(__m128d *)R4),
              v40),
            _mm_add_pd(
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_add_pd(v40, *(__m128d *)S1), v40), *(__m128d *)S2), v40),
                  *(__m128d *)S3),
                v40),
              *(__m128d *)S4));
    v45 = _mm_cmplt_pd(v39, *(__m128d *)linearLimit);
    v46 = _mm_xor_pd(
            _mm_or_pd(
              _mm_andn_pd(
                v45,
                _mm_or_pd(
                  _mm_andn_pd(
                    v41,
                    _mm_add_pd(
                      _mm_mul_pd(
                        _mm_div_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(
                                      _mm_mul_pd(
                                        _mm_add_pd(
                                          _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)P0, v42), *(__m128d *)P1), v42),
                                          *(__m128d *)P2),
                                        v42),
                                      *(__m128d *)P3),
                                    v42),
                                  *(__m128d *)P4),
                                v42),
                              *(__m128d *)P5),
                            v42),
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)Q1, v42), v42), *(__m128d *)Q2),
                                      v42),
                                    *(__m128d *)Q3),
                                  v42),
                                *(__m128d *)Q4),
                              v42),
                            *(__m128d *)Q5)),
                        v39),
                      v39)),
                  _mm_and_pd(
                    _mm_add_pd(
                      _mm_sub_pd(
                        _mm_sub_pd(*(__m128d *)piover4, v43),
                        _mm_sub_pd(_mm_mul_pd(v44, v43), *(__m128d *)morebits)),
                      *(__m128d *)piover4),
                    v41))),
              _mm_and_pd(v45, v39)),
            _mm_and_pd(v38, *(__m128d *)_xmm));
    v47 = _mm_sub_pd(g_vectordConstants[2].xy, _mm_mul_pd(v38, v38));
    v48 = _mm_sub_pd(*(__m128d *)piover2, v46);
    v49 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v47)));
    v50 = _mm_mul_pd(v49, v47);
    si128 = _mm_load_si128((const __m128i *)_xmm);
    v52 = _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(v50, v49));
    v53 = _mm_add_epi32(si128, si128);
    v54 = _mm_mul_pd(v48, (__m128d)v16);
    v55 = _mm_mul_pd(v52, _mm_mul_pd(v49, g_vectordConstants[17].xy));
    v56 = _mm_unpacklo_pd(_mm_sub_pd(v48, v54), v54);
    v57 = _mm_andn_pd(*(__m128d *)_xmm, v56);
    v58 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(*(__m128d *)fourDivPi, v57)), si128));
    v59 = _mm_cvtepi32_pd(v58);
    v60 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v58, v53), (__m128i)0i64), 80);
    v61 = _mm_add_pd(
            _mm_add_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)DP1, v59), v57), _mm_mul_pd(*(__m128d *)DP2_0, v59)),
            _mm_mul_pd(*(__m128d *)DP3_0, v59));
    v62 = _mm_mul_pd(v61, v61);
    v63 = _mm_xor_pd(
            _mm_or_pd(
              _mm_andn_pd(
                v60,
                _mm_add_pd(
                  _mm_sub_pd(
                    _mm_mul_pd(
                      _mm_mul_pd(
                        _mm_add_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(
                                      _mm_mul_pd(
                                        _mm_add_pd(_mm_mul_pd(v62, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                        v62),
                                      *(__m128d *)cosCoeff2),
                                    v62),
                                  *(__m128d *)cosCoeff3),
                                v62),
                              *(__m128d *)cosCoeff4),
                            v62),
                          *(__m128d *)cosCoeff5),
                        v62),
                      v62),
                    _mm_mul_pd(v62, *(__m128d *)_xmm)),
                  *(__m128d *)_xmm)),
              _mm_and_pd(
                _mm_add_pd(
                  _mm_mul_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(v62, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1),
                                      v62),
                                    *(__m128d *)sinCoeff2),
                                  v62),
                                *(__m128d *)sinCoeff3),
                              v62),
                            *(__m128d *)sinCoeff4),
                          v62),
                        *(__m128d *)sinCoeff5),
                      v62),
                    v61),
                  v61),
                v60)),
            _mm_xor_pd(
              (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v53, v53), v58), 0x1Du), 80),
              _mm_and_pd(v56, *(__m128d *)_xmm)));
    xy = g_vectordConstants[4].xy;
    v23 = *v3;
    v27 = *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v64 = _mm_unpacklo_pd(v63, v63);
    v19 = 0i64;
    v65 = _mm_mul_pd(_mm_unpackhi_pd(v63, v63), v55);
    v66 = _mm_mul_pd(v64, v55);
  }
  v67 = _mm_xor_pd(v65, v37);
  v68 = _mm_add_pd(
          _mm_mul_pd(v66, *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40)),
          _mm_mul_pd(v67, v27));
  v69 = _mm_add_pd(_mm_mul_pd(v66, v32), _mm_mul_pd(v67, qVerts[v20].m_vec.m_quad.zw));
  v70 = _mm_mul_pd(v69, v69);
  v71 = _mm_mul_pd(v68, v68);
  v72 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v70, v70, 1), v70), _mm_add_pd(_mm_shuffle_pd(v71, v71, 1), v71));
  v73 = _mm_cmple_pd(v72, v19);
  v74 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v72)));
  v75 = _mm_mul_pd(v74, v72);
  v76 = qVerts[v22].m_vec.m_quad.zw;
  v77 = _mm_sub_pd(xy, _mm_mul_pd(v75, v74));
  v78 = _mm_mul_pd(v76, qVerts[v21].m_vec.m_quad.zw);
  v79 = _mm_andn_pd(v73, _mm_mul_pd(v77, _mm_mul_pd(v74, g_vectordConstants[17].xy)));
  v80 = _mm_mul_pd(v23, qVerts[v21].m_vec.m_quad.xy);
  v81 = _mm_mul_pd(v68, v79);
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v81;
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v81;
  v82 = _mm_mul_pd(v69, v79);
  v83 = (__m128d)_mm_slli_epi64(
                   _mm_srli_epi64(
                     (__m128i)_mm_add_pd(
                                _mm_add_pd(_mm_shuffle_pd(v78, v78, 1), v78),
                                _mm_add_pd(_mm_shuffle_pd(v80, v80, 1), v80)),
                     0x3Fu),
                   0x3Fu);
  v84 = _mm_xor_pd(v83, qVerts[v21].m_vec.m_quad.zw);
  v85 = _mm_xor_pd(v83, qVerts[v21].m_vec.m_quad.xy);
  v86 = _mm_mul_pd(v84, v76);
  v87 = _mm_mul_pd(v85, v23);
  v88 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v86, v86, 1), v86), _mm_add_pd(_mm_shuffle_pd(v87, v87, 1), v87));
  v89 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)_mm_cmplt_pd(v88, v19), 0x3Fu), 0x3Fu);
  *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v89;
  v90 = _mm_xor_pd(v89, v88);
  if ( v90.m128d_f64[0] >= _mm_shuffle_pd(
                             (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                             (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                             0).m128d_f64[0] )
  {
    v119 = _mm_sub_pd(g_vectordConstants[2].xy, (__m128d)v16);
  }
  else
  {
    v91 = _mm_andn_pd(*(__m128d *)_xmm, v90);
    v92 = _mm_sub_pd(*(__m128d *)_xmm, v91);
    v93 = _mm_cmplt_pd(*(__m128d *)limit, v91);
    v94 = _mm_mul_pd(v91, v91);
    v95 = _mm_sqrt_pd(_mm_add_pd(v92, v92));
    v96 = _mm_div_pd(
            _mm_mul_pd(
              _mm_add_pd(
                _mm_mul_pd(
                  _mm_add_pd(
                    _mm_mul_pd(
                      _mm_add_pd(
                        _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v92, *(__m128d *)R0), *(__m128d *)R1), v92),
                        *(__m128d *)R2),
                      v92),
                    *(__m128d *)R3),
                  v92),
                *(__m128d *)R4),
              v92),
            _mm_add_pd(
              _mm_mul_pd(
                _mm_add_pd(
                  _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_add_pd(v92, *(__m128d *)S1), v92), *(__m128d *)S2), v92),
                  *(__m128d *)S3),
                v92),
              *(__m128d *)S4));
    v97 = _mm_cmplt_pd(v91, *(__m128d *)linearLimit);
    v98 = _mm_xor_pd(
            _mm_or_pd(
              _mm_andn_pd(
                v97,
                _mm_or_pd(
                  _mm_andn_pd(
                    v93,
                    _mm_add_pd(
                      _mm_mul_pd(
                        _mm_div_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(
                                      _mm_mul_pd(
                                        _mm_add_pd(
                                          _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)P0, v94), *(__m128d *)P1), v94),
                                          *(__m128d *)P2),
                                        v94),
                                      *(__m128d *)P3),
                                    v94),
                                  *(__m128d *)P4),
                                v94),
                              *(__m128d *)P5),
                            v94),
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(
                                    _mm_mul_pd(
                                      _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)Q1, v94), v94), *(__m128d *)Q2),
                                      v94),
                                    *(__m128d *)Q3),
                                  v94),
                                *(__m128d *)Q4),
                              v94),
                            *(__m128d *)Q5)),
                        v91),
                      v91)),
                  _mm_and_pd(
                    _mm_add_pd(
                      _mm_sub_pd(
                        _mm_sub_pd(*(__m128d *)piover4, v95),
                        _mm_sub_pd(_mm_mul_pd(v96, v95), *(__m128d *)morebits)),
                      *(__m128d *)piover4),
                    v93))),
              _mm_and_pd(v97, v91)),
            _mm_and_pd(*(__m128d *)_xmm, v90));
    v99 = _mm_sub_pd(g_vectordConstants[2].xy, _mm_mul_pd(v90, v90));
    v100 = _mm_sub_pd(*(__m128d *)piover2, v98);
    v101 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v99)));
    v102 = _mm_mul_pd(g_vectordConstants[17].xy, v101);
    v103 = _mm_mul_pd(_mm_mul_pd(v99, v101), v101);
    v104 = _mm_load_si128((const __m128i *)_xmm);
    v105 = _mm_mul_pd(_mm_sub_pd(g_vectordConstants[4].xy, v103), v102);
    v106 = _mm_add_epi32(v104, v104);
    v107 = _mm_mul_pd(v100, (__m128d)v16);
    v108 = _mm_unpacklo_pd(_mm_sub_pd(v100, v107), v107);
    v109 = _mm_andn_pd(*(__m128d *)_xmm, v108);
    v110 = _mm_andnot_si128(v104, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(*(__m128d *)fourDivPi, v109)), v104));
    v111 = _mm_cvtepi32_pd(v110);
    v112 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v110, v106), (__m128i)0i64), 80);
    v113 = _mm_add_pd(
             _mm_add_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)DP1, v111), v109), _mm_mul_pd(*(__m128d *)DP2_0, v111)),
             _mm_mul_pd(*(__m128d *)DP3_0, v111));
    v114 = _mm_mul_pd(v113, v113);
    v115 = _mm_or_pd(
             _mm_andn_pd(
               v112,
               _mm_add_pd(
                 _mm_sub_pd(
                   _mm_mul_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(*(__m128d *)cosCoeff0, v114), *(__m128d *)cosCoeff1_0),
                                       v114),
                                     *(__m128d *)cosCoeff2),
                                   v114),
                                 *(__m128d *)cosCoeff3),
                               v114),
                             *(__m128d *)cosCoeff4),
                           v114),
                         *(__m128d *)cosCoeff5),
                       v114),
                     v114),
                   _mm_mul_pd(*(__m128d *)_xmm, v114)),
                 *(__m128d *)_xmm)),
             _mm_and_pd(
               _mm_add_pd(
                 _mm_mul_pd(
                   _mm_mul_pd(
                     _mm_add_pd(
                       _mm_mul_pd(
                         _mm_add_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(_mm_mul_pd(*(__m128d *)sinCoeff0_0, v114), *(__m128d *)sinCoeff1),
                                     v114),
                                   *(__m128d *)sinCoeff2),
                                 v114),
                               *(__m128d *)sinCoeff3),
                             v114),
                           *(__m128d *)sinCoeff4),
                         v114),
                       *(__m128d *)sinCoeff5),
                     v114),
                   v113),
                 v113),
               v112));
    v116 = _mm_xor_pd(
             (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v106, v106), v110), 0x1Du), 80),
             _mm_and_pd(*(__m128d *)_xmm, v108));
    v81 = *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    xy = g_vectordConstants[4].xy;
    v23 = *v3;
    v117 = _mm_xor_pd(v115, v116);
    v19 = 0i64;
    v89 = *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    v76 = *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    v118 = _mm_unpacklo_pd(v117, v117);
    v16 = (__m128i)_mm_mul_pd(_mm_unpackhi_pd(v117, v117), v105);
    v119 = _mm_mul_pd(v118, v105);
  }
  v120 = _mm_xor_pd(v89, (__m128d)v16);
  v121 = _mm_add_pd(_mm_mul_pd(v84, v119), _mm_mul_pd(v76, v120));
  v122 = _mm_add_pd(_mm_mul_pd(v85, v119), _mm_mul_pd(v23, v120));
  v123 = _mm_mul_pd(v121, v121);
  v124 = _mm_mul_pd(v122, v122);
  v125 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v123, v123, 1), v123), _mm_add_pd(_mm_shuffle_pd(v124, v124, 1), v124));
  v126 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v125)));
  v127 = _mm_andn_pd(
           _mm_cmple_pd(v125, v19),
           _mm_mul_pd(
             _mm_sub_pd(xy, _mm_mul_pd(_mm_mul_pd(v126, v125), v126)),
             _mm_mul_pd(g_vectordConstants[17].xy, v126)));
  v128 = _mm_mul_pd(v121, v127);
  v129 = _mm_mul_pd(v122, v127);
  v130 = _mm_mul_pd(v128, v82);
  v131 = _mm_mul_pd(v129, v81);
  v132 = (__m128d)_mm_slli_epi64(
                    _mm_srli_epi64(
                      (__m128i)_mm_add_pd(
                                 _mm_add_pd(_mm_shuffle_pd(v130, v130, 1), v130),
                                 _mm_add_pd(_mm_shuffle_pd(v131, v131, 1), v131)),
                      0x3Fu),
                    0x3Fu);
  v133 = _mm_xor_pd(v132, v82);
  v134 = _mm_xor_pd(v132, v81);
  v135 = _mm_mul_pd(v133, v128);
  v136 = _mm_mul_pd(v134, v129);
  v137 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v135, v135, 1), v135), _mm_add_pd(_mm_shuffle_pd(v136, v136, 1), v136));
  v138 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)_mm_cmplt_pd(v137, v19), 0x3Fu), 0x3Fu);
  v139 = _mm_xor_pd(v137, v138);
  if ( v139.m128d_f64[0] >= _mm_shuffle_pd(
                              (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                              (__m128d)*(unsigned __int64 *)&DOUBLE_0_9989999999525025,
                              0).m128d_f64[0] )
  {
    v168 = _mm_sub_pd(g_vectordConstants[2].xy, v29);
  }
  else
  {
    v140 = _mm_andn_pd(*(__m128d *)_xmm, v139);
    v141 = _mm_sub_pd(*(__m128d *)_xmm, v140);
    v142 = _mm_cmplt_pd(*(__m128d *)limit, v140);
    *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = v142;
    v143 = _mm_add_pd(
             _mm_mul_pd(
               _mm_add_pd(
                 _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_add_pd(v141, *(__m128d *)S1), v141), *(__m128d *)S2), v141),
                 *(__m128d *)S3),
               v141),
             *(__m128d *)S4);
    v144 = _mm_mul_pd(
             _mm_add_pd(
               _mm_mul_pd(
                 _mm_add_pd(
                   _mm_mul_pd(
                     _mm_add_pd(
                       _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v141, *(__m128d *)R0), *(__m128d *)R1), v141),
                       *(__m128d *)R2),
                     v141),
                   *(__m128d *)R3),
                 v141),
               *(__m128d *)R4),
             v141);
    v145 = _mm_sqrt_pd(_mm_add_pd(v141, v141));
    v146 = _mm_mul_pd(v140, v140);
    v147 = _mm_sub_pd(_mm_mul_pd(_mm_div_pd(v144, v143), v145), *(__m128d *)morebits);
    v148 = _mm_add_pd(
             _mm_mul_pd(
               _mm_add_pd(
                 _mm_mul_pd(
                   _mm_add_pd(
                     _mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_add_pd(v146, *(__m128d *)Q1), v146), *(__m128d *)Q2), v146),
                     *(__m128d *)Q3),
                   v146),
                 *(__m128d *)Q4),
               v146),
             *(__m128d *)Q5);
    v149 = _mm_mul_pd(
             _mm_add_pd(
               _mm_mul_pd(
                 _mm_add_pd(
                   _mm_mul_pd(
                     _mm_add_pd(
                       _mm_mul_pd(
                         _mm_add_pd(
                           _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v146, *(__m128d *)P0), *(__m128d *)P1), v146),
                           *(__m128d *)P2),
                         v146),
                       *(__m128d *)P3),
                     v146),
                   *(__m128d *)P4),
                 v146),
               *(__m128d *)P5),
             v146);
    v150 = _mm_cmplt_pd(v140, *(__m128d *)linearLimit);
    v151 = _mm_sub_pd(g_vectordConstants[2].xy, _mm_mul_pd(v139, v139));
    *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = _mm_sub_pd(
                                                                               *(__m128d *)piover2,
                                                                               _mm_xor_pd(
                                                                                 _mm_or_pd(
                                                                                   _mm_andn_pd(
                                                                                     v150,
                                                                                     _mm_or_pd(
                                                                                       _mm_andn_pd(
                                                                                         v142,
                                                                                         _mm_add_pd(
                                                                                           _mm_mul_pd(
                                                                                             _mm_div_pd(v149, v148),
                                                                                             v140),
                                                                                           v140)),
                                                                                       _mm_and_pd(
                                                                                         _mm_add_pd(
                                                                                           _mm_sub_pd(
                                                                                             _mm_sub_pd(
                                                                                               *(__m128d *)piover4,
                                                                                               v145),
                                                                                             v147),
                                                                                           *(__m128d *)piover4),
                                                                                         *(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60)))),
                                                                                   _mm_and_pd(v150, v140)),
                                                                                 _mm_and_pd(v139, *(__m128d *)_xmm)));
    v152 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v151)));
    v153 = _mm_mul_pd(v152, v151);
    v154 = _mm_load_si128((const __m128i *)_xmm);
    v155 = _mm_add_epi32(v154, v154);
    v156 = _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(v153, v152));
    v157 = _mm_mul_pd(*(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60), v29);
    v158 = _mm_mul_pd(v156, _mm_mul_pd(v152, g_vectordConstants[17].xy));
    v159 = _mm_unpacklo_pd(
             _mm_sub_pd(*(__m128d *)(((unsigned __int64)v177 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60), v157),
             v157);
    v160 = _mm_andn_pd(*(__m128d *)_xmm, v159);
    v161 = _mm_andnot_si128(v154, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(v160, *(__m128d *)fourDivPi)), v154));
    v162 = _mm_cvtepi32_pd(v161);
    v163 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v161, v155), (__m128i)0i64), 80);
    v164 = _mm_add_pd(
             _mm_add_pd(_mm_add_pd(_mm_mul_pd(v162, *(__m128d *)DP1), v160), _mm_mul_pd(v162, *(__m128d *)DP2_0)),
             _mm_mul_pd(v162, *(__m128d *)DP3_0));
    v165 = _mm_mul_pd(v164, v164);
    v166 = _mm_xor_pd(
             _mm_or_pd(
               _mm_andn_pd(
                 v163,
                 _mm_add_pd(
                   _mm_sub_pd(
                     _mm_mul_pd(
                       _mm_mul_pd(
                         _mm_add_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(
                                       _mm_mul_pd(
                                         _mm_add_pd(_mm_mul_pd(v165, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                         v165),
                                       *(__m128d *)cosCoeff2),
                                     v165),
                                   *(__m128d *)cosCoeff3),
                                 v165),
                               *(__m128d *)cosCoeff4),
                             v165),
                           *(__m128d *)cosCoeff5),
                         v165),
                       v165),
                     _mm_mul_pd(v165, *(__m128d *)_xmm)),
                   *(__m128d *)_xmm)),
               _mm_and_pd(
                 _mm_add_pd(
                   _mm_mul_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(v165, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1),
                                       v165),
                                     *(__m128d *)sinCoeff2),
                                   v165),
                                 *(__m128d *)sinCoeff3),
                               v165),
                             *(__m128d *)sinCoeff4),
                           v165),
                         *(__m128d *)sinCoeff5),
                       v165),
                     v164),
                   v164),
                 v163)),
             _mm_xor_pd(
               (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v155, v155), v161), 0x1Du), 80),
               _mm_and_pd(v159, *(__m128d *)_xmm)));
    xy = g_vectordConstants[4].xy;
    v167 = _mm_unpacklo_pd(v166, v166);
    v29 = _mm_mul_pd(_mm_unpackhi_pd(v166, v166), v158);
    v168 = _mm_mul_pd(v167, v158);
    v19 = 0i64;
  }
  v169 = _mm_xor_pd(v138, v29);
  v170 = _mm_add_pd(_mm_mul_pd(v133, v168), _mm_mul_pd(v128, v169));
  v171 = _mm_add_pd(_mm_mul_pd(v134, v168), _mm_mul_pd(v129, v169));
  v172 = _mm_mul_pd(v170, v170);
  v173 = _mm_mul_pd(v171, v171);
  v174 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v172, v172, 1), v172), _mm_add_pd(_mm_shuffle_pd(v173, v173, 1), v173));
  v175 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v174)));
  v176 = _mm_andn_pd(
           _mm_cmple_pd(v174, v19),
           _mm_mul_pd(
             _mm_sub_pd(xy, _mm_mul_pd(_mm_mul_pd(v175, v174), v175)),
             _mm_mul_pd(v175, g_vectordConstants[17].xy)));
  this->m_vec.m_quad.xy = _mm_mul_pd(v171, v176);
  this->m_vec.m_quad.zw = _mm_mul_pd(v170, v176);
}xy = _mm_mul_pd(v171, v176);
  this->m_vec.m_quad.zw = _mm_mul_pd(v170, v176);
}

// File Line: 287
// RVA: 0xC88C30
void __fastcall hkQuaterniond::removeAxisComponent(hkQuaterniond *this, hkVector4d *axis)
{
  hkSimdDouble64 *v2; // rbp
  __m128d zw; // xmm4
  __m128d xy; // xmm12
  __m128d v5; // xmm13
  __m128d v6; // xmm14
  __m128d v7; // xmm5
  __m128d v8; // xmm1
  __m128d v9; // xmm0
  __m128d v10; // xmm15
  __m128d v11; // xmm9
  __m128d v12; // xmm10
  __m128d v13; // xmm0
  __m128d v14; // xmm2
  __m128d v15; // xmm9
  __m128d v16; // xmm10
  __m128d v17; // xmm3
  __m128d v18; // xmm2
  __m128d v19; // xmm0
  __m128d v20; // xmm1
  double v21; // xmm3_8
  __m128d v22; // xmm9
  __m128d v23; // xmm10
  __m128d v24; // xmm9
  __m128d v25; // xmm10
  __m128d v26; // xmm0
  __m128d v27; // xmm1
  __m128d v28; // xmm11
  __m128d v29; // xmm8
  __m128d v30; // xmm7
  __m128d v31; // xmm5
  __m128d v32; // xmm2
  __m128d v33; // xmm6
  __m128d v34; // xmm0
  __m128d v35; // xmm1
  __m128d v36; // xmm3
  __m128d v37; // xmm4
  __m128d v38; // xmm5
  __m128d v39; // xmm8
  __m128d v40; // xmm0
  __m128d v41; // xmm1
  __m128d v42; // xmm3
  __m128d v43; // xmm2
  __m128d v44; // xmm4
  __m128d v45; // xmm0
  __m128d v46; // xmm7
  __m128d v47; // xmm1
  __m128d v48; // xmm5
  __m128d v49; // xmm2
  __m128d v50; // xmm3
  __m128d v51; // xmm2
  __m128d v52; // xmm1
  __m128d v53; // xmm6
  __m128d v54; // xmm9
  __m128d v55; // xmm5
  __m128d v56; // xmm6
  __m128d v57; // xmm0
  __m128d v58; // xmm1
  __m128d v59; // xmm3
  __m128d v60; // xmm2
  __m128d v61; // xmm4
  hkVector4d axisa; // [rsp+40h] [rbp+0h] BYREF

  v2 = (hkSimdDouble64 *)((unsigned __int64)&axisa & 0xFFFFFFFFFFFFFFE0ui64);
  zw = this->m_vec.m_quad.zw;
  xy = axis->m_quad.xy;
  v5 = axis->m_quad.zw;
  v6 = 0i64;
  v7 = _mm_unpackhi_pd(zw, zw);
  v8 = _mm_mul_pd(zw, v5);
  v9 = _mm_sub_pd(_mm_mul_pd(v7, v7), g_vectordConstants[17].xy);
  v10 = _mm_shuffle_pd(axis->m_quad.xy, v5, 1);
  v11 = _mm_mul_pd(axis->m_quad.xy, v9);
  v12 = _mm_mul_pd(v5, v9);
  v13 = _mm_mul_pd(this->m_vec.m_quad.xy, axis->m_quad.xy);
  v14 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v13, v13), _mm_unpackhi_pd(v13, v13)), _mm_unpacklo_pd(v8, v8));
  v15 = _mm_add_pd(v11, _mm_mul_pd(this->m_vec.m_quad.xy, v14));
  v16 = _mm_add_pd(v12, _mm_mul_pd(zw, v14));
  v17 = _mm_mul_pd(_mm_shuffle_pd(this->m_vec.m_quad.xy, zw, 2), v5);
  v18 = _mm_sub_pd(
          _mm_mul_pd(this->m_vec.m_quad.xy, v10),
          _mm_mul_pd(_mm_shuffle_pd(this->m_vec.m_quad.xy, zw, 1), axis->m_quad.xy));
  v19 = _mm_shuffle_pd(axis->m_quad.xy, v5, 2);
  *(__m128d *)((unsigned __int64)&axisa & 0xFFFFFFFFFFFFFFE0ui64) = v19;
  v20 = _mm_sub_pd(_mm_mul_pd(zw, v19), v17);
  v21 = _mm_shuffle_pd(
          (__m128d)*(unsigned __int64 *)&DOUBLE_0_001000000047497451,
          (__m128d)*(unsigned __int64 *)&DOUBLE_0_001000000047497451,
          0).m128d_f64[0];
  v22 = _mm_add_pd(v15, _mm_mul_pd(_mm_shuffle_pd(v18, v20, 1), v7));
  v23 = _mm_add_pd(v16, _mm_mul_pd(_mm_shuffle_pd(v18, v20, 2), v7));
  v24 = _mm_add_pd(v22, v22);
  v25 = _mm_add_pd(v23, v23);
  v26 = _mm_mul_pd(v24, xy);
  v27 = _mm_mul_pd(v25, v5);
  v28 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v26, v26), _mm_unpackhi_pd(v26, v26)), _mm_unpacklo_pd(v27, v27));
  if ( v28.m128d_f64[0] - 1.0 <= 0.0 - v21 )
  {
    if ( v28.m128d_f64[0] + 1.0 >= v21 )
    {
      v46 = _mm_andn_pd(*(__m128d *)_xmm, v28);
      v47 = _mm_sub_pd(*(__m128d *)_xmm, v46);
      v48 = _mm_cmplt_pd(*(__m128d *)limit, v46);
      v49 = _mm_mul_pd(v46, v46);
      v50 = _mm_sqrt_pd(_mm_add_pd(v47, v47));
      v51 = _mm_or_pd(
              _mm_andn_pd(
                v48,
                _mm_add_pd(
                  _mm_mul_pd(
                    _mm_div_pd(
                      _mm_mul_pd(
                        _mm_add_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(
                                      _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)P0, v49), *(__m128d *)P1), v49),
                                      *(__m128d *)P2),
                                    v49),
                                  *(__m128d *)P3),
                                v49),
                              *(__m128d *)P4),
                            v49),
                          *(__m128d *)P5),
                        v49),
                      _mm_add_pd(
                        _mm_mul_pd(
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)Q1, v49), v49), *(__m128d *)Q2),
                                  v49),
                                *(__m128d *)Q3),
                              v49),
                            *(__m128d *)Q4),
                          v49),
                        *(__m128d *)Q5)),
                    v46),
                  v46)),
              _mm_and_pd(
                _mm_add_pd(
                  _mm_sub_pd(
                    _mm_sub_pd(*(__m128d *)piover4, v50),
                    _mm_sub_pd(
                      _mm_mul_pd(
                        _mm_div_pd(
                          _mm_mul_pd(
                            _mm_add_pd(
                              _mm_mul_pd(
                                _mm_add_pd(
                                  _mm_mul_pd(
                                    _mm_add_pd(
                                      _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v47, *(__m128d *)R0), *(__m128d *)R1), v47),
                                      *(__m128d *)R2),
                                    v47),
                                  *(__m128d *)R3),
                                v47),
                              *(__m128d *)R4),
                            v47),
                          _mm_add_pd(
                            _mm_mul_pd(
                              _mm_add_pd(
                                _mm_mul_pd(
                                  _mm_add_pd(_mm_mul_pd(_mm_add_pd(v47, *(__m128d *)S1), v47), *(__m128d *)S2),
                                  v47),
                                *(__m128d *)S3),
                              v47),
                            *(__m128d *)S4)),
                        v50),
                      *(__m128d *)morebits)),
                  *(__m128d *)piover4),
                v48));
      v52 = _mm_cmplt_pd(v46, *(__m128d *)linearLimit);
      *(__m128d *)(((unsigned __int64)&axisa & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = _mm_sub_pd(
                                                                                   *(__m128d *)piover2,
                                                                                   _mm_xor_pd(
                                                                                     _mm_or_pd(
                                                                                       _mm_andn_pd(v52, v51),
                                                                                       _mm_and_pd(v52, v46)),
                                                                                     _mm_and_pd(v28, *(__m128d *)_xmm)));
      v53 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v24, v25, 1), xy), _mm_mul_pd(v24, v10));
      v54 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v24, v25, 2), v5), _mm_mul_pd(v25, v2->m_real));
      v55 = _mm_shuffle_pd(v53, v54, 1);
      v56 = _mm_shuffle_pd(v53, v54, 2);
      v57 = _mm_mul_pd(v55, v55);
      v58 = _mm_mul_pd(v56, v56);
      v59 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v57, v57), _mm_unpackhi_pd(v57, v57)), _mm_unpacklo_pd(v58, v58));
      v60 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v59)));
      v61 = _mm_andn_pd(
              _mm_cmple_pd(v59, (__m128d)0i64),
              _mm_mul_pd(
                _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v60, v59), v60)),
                _mm_mul_pd(v60, g_vectordConstants[17].xy)));
      v2->m_real = _mm_mul_pd(v55, v61);
      *(__m128d *)(((unsigned __int64)&axisa & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = _mm_mul_pd(v56, v61);
      hkQuaterniond::setAxisAngle(this, (hkVector4d *)((unsigned __int64)&axisa & 0xFFFFFFFFFFFFFFE0ui64), v2 + 2);
    }
    else
    {
      v29.m128d_f64[1] = 0.0;
      v29.m128d_f64[0] = v5.m128d_f64[0];
      v30.m128d_f64[1] = 0.0;
      v31 = _mm_shuffle_pd(xy, xy, 1);
      v30.m128d_f64[0] = xy.m128d_f64[0];
      v32 = _mm_mul_pd(v29, v29);
      v33 = _mm_unpackhi_pd(v29, v29);
      v34 = _mm_mul_pd(v31, v31);
      v35 = _mm_mul_pd(v33, v33);
      v36 = _mm_mul_pd(v30, v30);
      v37 = _mm_cmplt_pd(
              _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v34, v34), _mm_unpackhi_pd(v34, v34)), _mm_unpacklo_pd(v35, v35)),
              _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v32, v32), _mm_unpackhi_pd(v32, v32)), _mm_unpacklo_pd(v36, v36)));
      v38 = _mm_xor_pd(
              (__m128d)_mm_insert_epi16((__m128i)0i64, 0x8000u, 3),
              _mm_or_pd(_mm_andn_pd(v37, v31), _mm_and_pd(v29, v37)));
      v39 = _mm_or_pd(_mm_andn_pd(v37, v33), _mm_and_pd(v30, v37));
      v40 = _mm_mul_pd(v38, v38);
      v41 = _mm_mul_pd(v39, v39);
      v42 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v40, v40), _mm_unpackhi_pd(v40, v40)), _mm_unpacklo_pd(v41, v41));
      v43 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v42)));
      v44 = _mm_andn_pd(
              _mm_cmple_pd(v42, (__m128d)0i64),
              _mm_mul_pd(
                _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v43, v42), v43)),
                _mm_mul_pd(v43, g_vectordConstants[17].xy)));
      this->m_vec.m_quad.xy = _mm_mul_pd(v38, v44);
      v45 = _mm_mul_pd(v39, v44);
      this->m_vec.m_quad.zw = v45;
      v6.m128d_f64[0] = v45.m128d_f64[0];
      this->m_vec.m_quad.zw = v6;
    }
  }
  else
  {
    *(hkQuadDouble64 *)this = g_vectordConstants[31];
  }
}

// File Line: 336
// RVA: 0xC89200
void __fastcall hkQuaterniond::decomposeRestAxis(
        hkQuaterniond *this,
        hkVector4d *axis,
        hkQuaterniond *restOut,
        hkSimdDouble64 *angleOut)
{
  __m128d zw; // xmm3
  __m128d v9; // xmm4
  __m128d v10; // xmm6
  __m128d v11; // xmm1
  __m128d v12; // xmm5
  __m128d v13; // xmm12
  __m128d v14; // xmm1
  __m128d v15; // xmm12
  __m128d v16; // xmm4
  __m128d v17; // xmm1
  __m128d v18; // xmm12
  long double v19; // xmm0_8
  __m128d v20; // xmm1
  __m128d v21; // xmm11
  __m128d v22; // xmm0
  __m128d v23; // xmm3
  __m128d v24; // xmm2
  __m128d v25; // xmm1
  __m128d v26; // xmm11
  __m128d v27; // xmm12
  __m128i v28; // xmm10
  __m128d v29; // xmm9
  __m128d v30; // xmm7
  __m128d v31; // xmm1
  __m128d xy; // xmm1
  __m128d v33; // xmm1
  __m128d v34; // xmm0
  __int64 v35[16]; // [rsp+40h] [rbp+0h] BYREF

  *restOut = *this;
  hkQuaterniond::removeAxisComponent(restOut, axis);
  zw = restOut->m_vec.m_quad.zw;
  v9 = this->m_vec.m_quad.zw;
  v10 = _mm_sub_pd(
          _mm_mul_pd(_mm_shuffle_pd(restOut->m_vec.m_quad.xy, zw, 1), this->m_vec.m_quad.xy),
          _mm_mul_pd(_mm_shuffle_pd(this->m_vec.m_quad.xy, v9, 1), restOut->m_vec.m_quad.xy));
  v11 = _mm_sub_pd(
          _mm_mul_pd(_mm_shuffle_pd(restOut->m_vec.m_quad.xy, zw, 2), v9),
          _mm_mul_pd(_mm_shuffle_pd(this->m_vec.m_quad.xy, v9, 2), zw));
  v12 = _mm_mul_pd(this->m_vec.m_quad.xy, restOut->m_vec.m_quad.xy);
  v13 = _mm_shuffle_pd(v10, v11, 1);
  v10.m128d_f64[0] = _mm_shuffle_pd(v10, v11, 2).m128d_f64[0];
  v14 = _mm_unpackhi_pd(zw, zw);
  v15 = _mm_add_pd(v13, _mm_mul_pd(this->m_vec.m_quad.xy, v14));
  v16 = _mm_mul_pd(v9, zw);
  v10.m128d_f64[0] = v10.m128d_f64[0] + this->m_vec.m_quad.zw.m128d_f64[0] * v14.m128d_f64[0];
  v17 = _mm_unpackhi_pd(this->m_vec.m_quad.zw, this->m_vec.m_quad.zw);
  v18 = _mm_sub_pd(v15, _mm_mul_pd(v17, restOut->m_vec.m_quad.xy));
  v19 = restOut->m_vec.m_quad.zw.m128d_f64[0] * v17.m128d_f64[0];
  v20 = _mm_mul_pd(v18, v18);
  v21 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v16, v16, 1), v16), _mm_add_pd(_mm_shuffle_pd(v12, v12, 1), v12));
  v21.m128d_f64[0] = v10.m128d_f64[0] - v19;
  v22 = _mm_mul_pd(v21, v21);
  v23 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v22, v22, 1), v22), _mm_add_pd(_mm_shuffle_pd(v20, v20, 1), v20));
  v24 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v23)));
  v25 = _mm_mul_pd(
          _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v24, v23), v24)),
          _mm_mul_pd(v24, g_vectordConstants[17].xy));
  v26 = _mm_mul_pd(v21, v25);
  v27 = _mm_mul_pd(v18, v25);
  v28 = (__m128i)_mm_unpackhi_pd(v26, v26);
  v29 = (__m128d)_mm_srli_epi64(_mm_slli_epi64(v28, 1u), 1u);
  v30 = _mm_andn_pd(*(__m128d *)_xmm, v29);
  v31 = _mm_sub_pd(*(__m128d *)_xmm, v30);
  v12.m128d_f64[0] = _mm_cmplt_pd(*(__m128d *)limit, v30).m128d_f64[0];
  v10.m128d_f64[0] = _mm_cmplt_pd(v30, *(__m128d *)linearLimit).m128d_f64[0];
  v23.m128d_f64[0] = _mm_sqrt_pd(_mm_add_pd(v31, v31)).m128d_f64[0];
  v22.m128d_f64[0] = *(double *)piover2
                   - COERCE_DOUBLE((~*(_QWORD *)&v10.m128d_f64[0] & (~*(_QWORD *)&v12.m128d_f64[0] & COERCE_UNSIGNED_INT64((((((*(double *)P0 * (v30.m128d_f64[0] * v30.m128d_f64[0]) + 7.6302029431072077711e2164) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + *(double *)P2) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + -2.8031751084802239661e-3662) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + *(double *)P4) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + -3.2677991205366821308e-1246) * (v30.m128d_f64[0] * v30.m128d_f64[0]) / (((((v30.m128d_f64[0] * v30.m128d_f64[0] + 5.8844746227918545146e-3802) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + *(double *)Q2) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + 4.3460921100359587363e4226) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + *(double *)Q4) * (v30.m128d_f64[0] * v30.m128d_f64[0]) + 4.2191477218605945177e-4341) * v30.m128d_f64[0] + v30.m128d_f64[0]) | COERCE_UNSIGNED_INT64(*(double *)piover4 - v23.m128d_f64[0] - (((((v31.m128d_f64[0] * *(double *)R0 + 3.3704805741073978875e-1768) * v31.m128d_f64[0] + *(double *)R2) * v31.m128d_f64[0] + -2.8021571109118165302e-1587) * v31.m128d_f64[0] + *(double *)R4) * v31.m128d_f64[0] / ((((v31.m128d_f64[0] + 2.9409311987439929599e2277) * v31.m128d_f64[0] + *(double *)S2) * v31.m128d_f64[0] + 2.2494704961851719142e2769) * v31.m128d_f64[0] + *(double *)S4) * v23.m128d_f64[0] - *(double *)morebits) + *(double *)piover4) & *(_QWORD *)&v12.m128d_f64[0]) | *(_QWORD *)&v10.m128d_f64[0] & *(_QWORD *)&v30.m128d_f64[0]) ^ *(_QWORD *)&v29.m128d_f64[0] & _xmm[0]);
  xy = axis->m_quad.xy;
  *(double *)((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) = v22.m128d_f64[0] * 2.0;
  v33 = _mm_mul_pd(xy, v27);
  v34 = _mm_mul_pd(axis->m_quad.zw, v26);
  angleOut->m_real = _mm_xor_pd(
                       (__m128d)_mm_slli_epi64(
                                  _mm_srli_epi64(
                                    (__m128i)_mm_mul_pd(
                                               _mm_add_pd(
                                                 _mm_add_pd(_mm_unpacklo_pd(v33, v33), _mm_unpackhi_pd(v33, v33)),
                                                 _mm_unpacklo_pd(v34, v34)),
                                               (__m128d)v28),
                                    0x3Fu),
                                  0x3Fu),
                       _mm_shuffle_pd(
                         (__m128d)*(unsigned __int64 *)((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64),
                         (__m128d)*(unsigned __int64 *)((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64),
                         0));
}

