// File Line: 13
// RVA: 0xC57940
void __fastcall hkQuaternionf::setAxisAngle(hkQuaternionf *this, hkVector4f *axis, hkSimdFloat32 *angle)
{
  __m128i si128; // xmm6
  __m128 v4; // xmm9
  __m128i v5; // xmm8
  __m128 v6; // xmm2
  __m128i v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm1

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v4 = _mm_add_ps(_mm_mul_ps(angle->m_real, (__m128)xmmword_141A711B0), *(__m128 *)offset_1);
  v5 = _mm_add_epi32(si128, si128);
  v6 = _mm_andnot_ps(*(__m128 *)_xmm, v4);
  v7 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v6)), si128));
  v8 = _mm_cvtepi32_ps(v7);
  v9 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v7, v5), (__m128i)0i64);
  v10 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v8, *(__m128 *)DP1_0), v6), _mm_mul_ps(v8, *(__m128 *)DP2)),
          _mm_mul_ps(v8, *(__m128 *)DP3));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v9,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v11),
                        *(__m128 *)cosCoeff2_0),
                      v11),
                    v11),
                  _mm_mul_ps(v11, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v11),
                      *(__m128 *)sinCoeff2_0),
                    v11),
                  v10),
                v10),
              v9)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v5, v5), v7), 0x1Du),
            _mm_and_ps(v4, *(__m128 *)_xmm)));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), axis->m_quad);
  this->m_vec.m_quad = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, _mm_shuffle_ps(v12, v12, 85)), 196);
}

// File Line: 24
// RVA: 0xC57910
void __fastcall hkQuaternionf::setAxisAngle(hkQuaternionf *this, hkVector4f *axis, float angle)
{
  hkSimdFloat32 anglea; // [rsp+20h] [rbp-18h] BYREF

  anglea.m_real = _mm_shuffle_ps((__m128)LODWORD(angle), (__m128)LODWORD(angle), 0);
  hkQuaternionf::setAxisAngle(this, axis, &anglea);
}

// File Line: 29
// RVA: 0xC57AA0
void __fastcall hkQuaternionf::setAxisAngle_Approximate(hkQuaternionf *this, hkVector4f *axis, hkSimdFloat32 *angle)
{
  __m128 v3; // xmm1
  __m128i v4; // xmm1
  __m128i v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm1

  v3 = _mm_add_ps(_mm_mul_ps(angle->m_real, (__m128)xmmword_141A711B0), *(__m128 *)offset_1);
  v4 = (__m128i)_mm_sub_ps(v3, _mm_and_ps(_mm_cmpnlt_ps(v3, *(__m128 *)_xmm), *(__m128 *)twopi));
  v5 = (__m128i)_mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v4, 1u), 1u), (__m128)v4), *(__m128 *)C),
                  _mm_mul_ps((__m128)v4, *(__m128 *)_xmm));
  v6 = _mm_add_ps(
         _mm_mul_ps(
           _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u), (__m128)v5), (__m128)v5),
           *(__m128 *)_xmm),
         (__m128)v5);
  v7 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), axis->m_quad);
  this->m_vec.m_quad = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, _mm_shuffle_ps(v6, v6, 85)), 196);
}

// File Line: 40
// RVA: 0xC57B90
void __fastcall hkQuaternionf::setFromEulerAngles(
        hkQuaternionf *this,
        hkSimdFloat32 *roll,
        hkSimdFloat32 *pitch,
        hkSimdFloat32 *yaw)
{
  __m128i si128; // xmm3
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128i v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128i v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm6
  __m128i v18; // xmm0
  __m128 v19; // xmm5
  __m128 v20; // xmm0
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128i v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128i v26; // [rsp+0h] [rbp-48h] BYREF
  __m128i v27; // [rsp+10h] [rbp-38h]
  __m128 v28; // [rsp+20h] [rbp-28h]

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v5 = _mm_mul_ps(
         _mm_movelh_ps(_mm_unpacklo_ps(pitch->m_real, pitch->m_real), _mm_unpacklo_ps(roll->m_real, roll->m_real)),
         (__m128)xmmword_141A711B0);
  v26 = _mm_add_epi32(si128, si128);
  v27 = (__m128i)_mm_add_ps(v5, *(__m128 *)offset_1);
  v6 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)v27);
  v7 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v6, *(__m128 *)_xmm)), si128));
  v8 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v7, v26), (__m128i)0i64);
  v9 = _mm_cvtepi32_ps(v7);
  v10 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v9, *(__m128 *)DP1_0), v6), _mm_mul_ps(v9, *(__m128 *)DP2)),
          _mm_mul_ps(v9, *(__m128 *)DP3));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v11),
                *(__m128 *)sinCoeff2_0),
              v11),
            v10),
          v10);
  v13 = _mm_load_si128(&v26);
  v14 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v8,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v11),
                        *(__m128 *)cosCoeff2_0),
                      v11),
                    v11),
                  _mm_mul_ps(v11, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(v12, v8)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v13, v13), v7), 0x1Du),
            _mm_and_ps((__m128)v27, *(__m128 *)_xmm)));
  v15 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, yaw->m_real), *(__m128 *)offset_1);
  v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
  v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 175), _mm_shuffle_ps(v14, v14, 17));
  v28 = v15;
  v18 = _mm_load_si128((const __m128i *)_xmm);
  v27 = _mm_andnot_si128(v18, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v16, *(__m128 *)_xmm)), v18));
  v19 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v27, v13), (__m128i)0i64);
  v20 = _mm_cvtepi32_ps(v27);
  v21 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, *(__m128 *)DP1_0), v16), _mm_mul_ps(v20, *(__m128 *)DP2)),
          _mm_mul_ps(v20, *(__m128 *)DP3));
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_load_si128(&v26);
  v24 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v19,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v22, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v22),
                        *(__m128 *)cosCoeff2_0),
                      v22),
                    v22),
                  _mm_mul_ps(v22, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v22, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v22),
                      *(__m128 *)sinCoeff2_0),
                    v22),
                  v21),
                v21),
              v19)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v23, v23), v27), 0x1Du),
            _mm_and_ps(v28, *(__m128 *)_xmm)));
  v25 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v17);
  this->m_vec.m_quad = _mm_add_ps(
                         _mm_xor_ps(
                           (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A6FCD0, 0x1Fu), 0x1Fu),
                           _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17)),
                         _mm_shuffle_ps(v25, v25, 27));
}

// File Line: 84
// RVA: 0xC57B30
void __fastcall hkQuaternionf::setFromEulerAngles(hkQuaternionf *this, float roll, float pitch, float yaw)
{
  hkSimdFloat32 v4; // [rsp+20h] [rbp-38h] BYREF
  hkSimdFloat32 v5; // [rsp+30h] [rbp-28h] BYREF
  hkSimdFloat32 v6; // [rsp+40h] [rbp-18h] BYREF

  v4.m_real = _mm_shuffle_ps((__m128)LODWORD(yaw), (__m128)LODWORD(yaw), 0);
  v5.m_real = _mm_shuffle_ps((__m128)LODWORD(pitch), (__m128)LODWORD(pitch), 0);
  v6.m_real = _mm_shuffle_ps((__m128)LODWORD(roll), (__m128)LODWORD(roll), 0);
  hkQuaternionf::setFromEulerAngles(this, &v6, &v5, &v4);
}

// File Line: 89
// RVA: 0xC57E20
void __fastcall hkQuaternionf::setFromEulerAngles_Approximate(
        hkQuaternionf *this,
        hkSimdFloat32 *roll,
        hkSimdFloat32 *pitch,
        hkSimdFloat32 *yaw)
{
  __m128 v4; // xmm1
  __m128i v5; // xmm1
  __m128i v6; // xmm0
  __m128 v7; // xmm10
  __m128 v8; // xmm2
  __m128i v9; // xmm2
  __m128i v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1

  v4 = _mm_add_ps(_mm_mul_ps(yaw->m_real, (__m128)xmmword_141A711B0), *(__m128 *)offset_1);
  v5 = (__m128i)_mm_sub_ps(v4, _mm_and_ps(_mm_cmpnlt_ps(v4, *(__m128 *)_xmm), *(__m128 *)twopi));
  v6 = (__m128i)_mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u), (__m128)v5), *(__m128 *)C),
                  _mm_mul_ps((__m128)v5, *(__m128 *)_xmm));
  v7 = _mm_add_ps(
         _mm_mul_ps(
           _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u), (__m128)v6), (__m128)v6),
           *(__m128 *)_xmm),
         (__m128)v6);
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_movelh_ps(_mm_unpacklo_ps(pitch->m_real, pitch->m_real), _mm_unpacklo_ps(roll->m_real, roll->m_real)),
           (__m128)xmmword_141A711B0),
         *(__m128 *)offset_1);
  v9 = (__m128i)_mm_sub_ps(v8, _mm_and_ps(_mm_cmpnlt_ps(v8, *(__m128 *)_xmm), *(__m128 *)twopi));
  v10 = (__m128i)_mm_add_ps(
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u), (__m128)v9), *(__m128 *)C),
                   _mm_mul_ps((__m128)v9, *(__m128 *)_xmm));
  v11 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v10, 1u), 1u), (__m128)v10), (__m128)v10),
            *(__m128 *)_xmm),
          (__m128)v10);
  v12 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 175), _mm_shuffle_ps(v11, v11, 17));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v12);
  this->m_vec.m_quad = _mm_add_ps(
                         _mm_xor_ps(
                           (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A6FCD0, 0x1Fu), 0x1Fu),
                           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v12)),
                         _mm_shuffle_ps(v13, v13, 75));
}

// File Line: 120
// RVA: 0xC58CC0
_BOOL8 __fastcall hkQuaternionf::isOk(hkQuaternionf *this, const float epsilon)
{
  __m128 m_quad; // xmm1
  __m128 v3; // xmm0
  __m128 v4; // xmm2

  m_quad = this->m_vec.m_quad;
  v3 = _mm_mul_ps(m_quad, m_quad);
  v4 = _mm_add_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  return !_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad))
      && COERCE_FLOAT((unsigned int)(2
                                   * COERCE_INT((float)(_mm_shuffle_ps(v4, v4, 177).m128_f32[0] + v4.m128_f32[0]) - 1.0)) >> 1) < _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0).m128_f32[0];
}

// File Line: 129
// RVA: 0xC57F60
void __fastcall hkQuaternionf::set(hkQuaternionf *this, hkRotationf *r)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  int v11; // edx
  __int64 v12; // r8
  __int64 v13; // r9
  float v14; // xmm2_4
  float v15; // xmm0_4
  hkQuaternionf v16; // [rsp+0h] [rbp-18h]

  v2 = r->m_col0.m_quad.m128_f32[0];
  v3 = r->m_col1.m_quad.m128_f32[1];
  v4 = r->m_col2.m_quad.m128_f32[2];
  v6 = (float)(r->m_col0.m_quad.m128_f32[0] + v3) + v4;
  if ( v6 <= 0.0 )
  {
    v11 = 0;
    v16.m_vec.m_quad.m128_i32[0] = 1;
    if ( v3 > v2 )
      v11 = 1;
    *(unsigned __int64 *)((char *)v16.m_vec.m_quad.m128_u64 + 4) = 2i64;
    if ( v4 > r->m_col0.m_quad.m128_f32[5 * v11] )
      v11 = 2;
    v12 = v16.m_vec.m_quad.m128_i32[v11];
    v13 = v16.m_vec.m_quad.m128_i32[v12];
    v14 = fsqrt(
            (float)(r->m_col0.m_quad.m128_f32[5 * v11]
                  - (float)(r->m_col0.m_quad.m128_f32[5 * v13] + r->m_col0.m_quad.m128_f32[5 * v12]))
          + 1.0);
    v15 = r->m_col0.m_quad.m128_f32[4 * v12 + v13] - r->m_col0.m_quad.m128_f32[4 * v13 + v12];
    v16.m_vec.m_quad.m128_f32[v11] = v14 * 0.5;
    v16.m_vec.m_quad.m128_f32[3] = v15 * (float)(0.5 / v14);
    v16.m_vec.m_quad.m128_f32[v12] = (float)(r->m_col0.m_quad.m128_f32[4 * v11 + v12]
                                           + r->m_col0.m_quad.m128_f32[4 * v12 + v11])
                                   * (float)(0.5 / v14);
    v16.m_vec.m_quad.m128_f32[v13] = (float)(r->m_col0.m_quad.m128_f32[4 * v13 + v11]
                                           + r->m_col0.m_quad.m128_f32[4 * v11 + v13])
                                   * (float)(0.5 / v14);
    *this = (hkQuaternionf)v16.m_vec.m_quad;
  }
  else
  {
    v7 = r->m_col1.m_quad.m128_f32[2] - r->m_col2.m_quad.m128_f32[1];
    v8 = fsqrt(v6 + 1.0);
    v9 = r->m_col2.m_quad.m128_f32[0] - r->m_col0.m_quad.m128_f32[2];
    v16.m_vec.m_quad.m128_f32[3] = v8 * 0.5;
    v16.m_vec.m_quad.m128_f32[0] = v7 * (float)(0.5 / v8);
    v10 = r->m_col0.m_quad.m128_f32[1];
    v16.m_vec.m_quad.m128_f32[1] = v9 * (float)(0.5 / v8);
    v16.m_vec.m_quad.m128_f32[2] = (float)(v10 - r->m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v8);
    *this = (hkQuaternionf)v16.m_vec.m_quad;
  }
}

// File Line: 134
// RVA: 0xC58D20
void __fastcall hkQuaternionf::setFlippedRotation(hkQuaternionf *this, hkVector4f *from)
{
  __m128 v2; // xmm7
  __m128 v3; // xmm5
  __m128 v4; // xmm7
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  __m128 v8; // xmm7
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2

  v2 = _mm_shuffle_ps(from->m_quad, _mm_unpackhi_ps(from->m_quad, (__m128)0i64), 196);
  v3 = _mm_shuffle_ps(v2, v2, 241);
  v4 = _mm_shuffle_ps(v2, v2, 206);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_mul_ps(v3, v3);
  v7 = _mm_cmplt_ps(
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)),
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)));
  v8 = _mm_xor_ps(
         _mm_or_ps(_mm_and_ps(v4, v7), _mm_andnot_ps(v7, v3)),
         (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  *(__m128i *)this = _mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v10, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v11))),
                                    v8),
                         4),
                       4);
}

// File Line: 191
// RVA: 0xC58710
void __fastcall hkQuaternionf::setSlerp(hkQuaternionf *this, hkQuaternionf *q0, hkQuaternionf *q1, hkSimdFloat32 *t)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128 v7; // xmm12
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm14
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128i si128; // xmm6
  __m128i v24; // xmm8
  __m128 v25; // xmm10
  __m128 v26; // xmm9
  __m128 v27; // xmm0
  __m128 v28; // xmm10
  __m128 v29; // xmm3
  __m128i v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm11
  __m128 v36; // xmm14
  __m128 m_real; // xmm11
  __m128 v38; // xmm14
  __m128 v39; // xmm11
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm3

  v4 = _mm_mul_ps(q1->m_vec.m_quad, q0->m_vec.m_quad);
  v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5);
  v7 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v6, (__m128)0i64), 0x1Fu), 0x1Fu);
  v8 = _mm_xor_ps(v7, v6);
  if ( v8.m128_f32[0] >= _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99900001), (__m128)LODWORD(FLOAT_0_99900001), 0).m128_f32[0] )
  {
    m_real = t->m_real;
    v38 = _mm_sub_ps(query.m_quad, t->m_real);
  }
  else
  {
    v9 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
    v10 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v9), *(__m128 *)_xmm);
    v11 = _mm_cmplt_ps(*(__m128 *)_xmm, v9);
    v12 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v10), v11), _mm_andnot_ps(v11, v9));
    v13 = _mm_or_ps(_mm_andnot_ps(v11, _mm_mul_ps(v9, v9)), _mm_and_ps(v11, v10));
    v14 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v13, *(__m128 *)coeff4), *(__m128 *)coeff3), v13),
                          *(__m128 *)coeff2),
                        v13),
                      *(__m128 *)coeff1),
                    v13),
                  *(__m128 *)coeff0),
                v13),
              v12),
            v12);
    v15 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v14, v14)), v11);
    v16 = _mm_andnot_ps(v11, v14);
    v17 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v8, v8));
    v18 = _mm_cmplt_ps(v9, *(__m128 *)_xmm);
    v19 = _mm_and_ps(v18, v9);
    v20 = _mm_andnot_ps(v18, _mm_or_ps(v15, v16));
    v21 = _mm_rsqrt_ps(v17);
    v22 = _mm_or_ps(v20, v19);
    si128 = _mm_load_si128((const __m128i *)_xmm);
    v24 = _mm_add_epi32(si128, si128);
    v25 = _mm_sub_ps(*(__m128 *)_xmm, _mm_xor_ps(v22, _mm_and_ps(v8, *(__m128 *)_xmm)));
    v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v21), v21)), _mm_mul_ps(*(__m128 *)_xmm, v21));
    v27 = _mm_mul_ps(t->m_real, v25);
    v28 = _mm_movelh_ps(_mm_unpacklo_ps(_mm_sub_ps(v25, v27), v27), _mm_unpacklo_ps(v27, v27));
    v29 = _mm_andnot_ps(*(__m128 *)_xmm, v28);
    v30 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v29, *(__m128 *)_xmm)), si128));
    v31 = _mm_cvtepi32_ps(v30);
    v32 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v30, v24), (__m128i)0i64);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, *(__m128 *)DP1_0), v29), _mm_mul_ps(*(__m128 *)DP2, v31)),
            _mm_mul_ps(*(__m128 *)DP3, v31));
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_xor_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v32,
                _mm_add_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)cosCoeff0_0, v34), *(__m128 *)cosCoeff1), v34),
                          *(__m128 *)cosCoeff2_0),
                        v34),
                      v34),
                    _mm_mul_ps(*(__m128 *)_xmm, v34)),
                  *(__m128 *)_xmm)),
              _mm_and_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)sinCoeff0, v34), *(__m128 *)sinCoeff1_0), v34),
                        *(__m128 *)sinCoeff2_0),
                      v34),
                    v33),
                  v33),
                v32)),
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v24, v24), v30), 0x1Du),
              _mm_and_ps(v28, *(__m128 *)_xmm)));
    v36 = _mm_shuffle_ps(v35, v35, 0);
    m_real = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v26);
    v38 = _mm_mul_ps(v36, v26);
  }
  v39 = _mm_add_ps(_mm_mul_ps(_mm_xor_ps(m_real, v7), q1->m_vec.m_quad), _mm_mul_ps(q0->m_vec.m_quad, v38));
  v40 = _mm_mul_ps(v39, v39);
  v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40);
  v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 177), v41);
  v43 = _mm_rsqrt_ps(v42);
  this->m_vec.m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v42, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                             _mm_mul_ps(*(__m128 *)_xmm, v43))),
                         v39);
}

// File Line: 259
// RVA: 0xC58A90
void __fastcall hkQuaternionf::setBarycentric(hkQuaternionf *this, hkQuaternionf *qVerts, hkVector4f *vLambda)
{
  __m128 m_quad; // xmm4
  __m128 v5; // xmm5
  __m128i v6; // xmm4
  __m128 v7; // xmm3
  int v8; // eax
  __m128 v9; // xmm7
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  __m128 v24; // xmm0
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  hkQuaternionf v27; // [rsp+20h] [rbp-78h] BYREF
  hkQuaternionf q0; // [rsp+30h] [rbp-68h] BYREF
  hkSimdFloat32 t; // [rsp+40h] [rbp-58h] BYREF
  hkQuaternionf q1; // [rsp+50h] [rbp-48h] BYREF
  hkSimdFloat32 v31; // [rsp+60h] [rbp-38h] BYREF

  m_quad = vLambda->m_quad;
  v5 = _mm_shuffle_ps(m_quad, m_quad, 210);
  v6 = (__m128i)_mm_add_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v5);
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u);
  v8 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_and_ps(
                                                                _mm_cmple_ps(
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(v7, v7, 170),
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(v7, v7, 85),
                                                                      _mm_shuffle_ps(v7, v7, 0))),
                                                                  v7),
                                                                (__m128)xmmword_141A6FC80))];
  v9 = qVerts[v8].m_vec.m_quad;
  v10 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v8];
  v11 = _mm_and_ps(v10, v5);
  v12 = _mm_and_ps(v10, (__m128)v6);
  v13 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v14 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  t.m_real = _mm_or_ps(_mm_shuffle_ps(v13, v13, 177), v13);
  v15 = _mm_rcp_ps(t.m_real);
  v16 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, t.m_real)), v15),
          _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14));
  v17 = _mm_cmplt_ps(*(__m128 *)&epsilon, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)t.m_real, 1u), 1u));
  v18 = _mm_or_ps(_mm_and_ps(v16, v17), _mm_andnot_ps(v17, (__m128)0i64));
  v19 = qVerts[(1 << v8) & 3].m_vec.m_quad;
  v20 = qVerts[(1 << ((1 << v8) & 3)) & 3].m_vec.m_quad;
  v31.m_real = v18;
  v21 = _mm_mul_ps(v9, v19);
  q1.m_vec.m_quad = v20;
  q0.m_vec.m_quad = v19;
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
  v27.m_vec.m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22), 0x1Fu),
                                 0x1Fu),
                       v9);
  hkQuaternionf::setSlerp(&v27, &v27, &q0, &t);
  v23 = _mm_mul_ps(v20, v9);
  v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
  q0.m_vec.m_quad = _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24), 0x1Fu),
                                0x1Fu),
                      v9);
  hkQuaternionf::setSlerp(&q0, &q0, &q1, &t);
  v25 = _mm_mul_ps(q0.m_vec.m_quad, v27.m_vec.m_quad);
  v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v27.m_vec.m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26), 0x1Fu),
                                 0x1Fu),
                       v27.m_vec.m_quad);
  hkQuaternionf::setSlerp(this, &v27, &q0, &v31);
}

// File Line: 293
// RVA: 0xC58100
void __fastcall hkQuaternionf::removeAxisComponent(hkQuaternionf *this, hkVector4f *axis)
{
  __m128 m_quad; // xmm9
  __m128 v3; // xmm4
  __m128 v4; // xmm12
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm10
  __m128 v8; // xmm10
  __m128 v9; // xmm1
  __m128 v10; // xmm11
  float v11; // xmm3_4
  __m128 v12; // xmm9
  __m128 v13; // xmm4
  __m128 v14; // xmm9
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm9
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  hkQuaternionf v22; // xmm4
  __m128 v23; // xmm7
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128 v34; // xmm5
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  hkSimdFloat32 angle; // [rsp+20h] [rbp-A8h] BYREF
  hkVector4f axisa; // [rsp+30h] [rbp-98h] BYREF

  m_quad = axis->m_quad;
  v3 = _mm_shuffle_ps(this->m_vec.m_quad, this->m_vec.m_quad, 255);
  v4 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v5 = _mm_mul_ps(axis->m_quad, this->m_vec.m_quad);
  v6 = _mm_sub_ps(
         _mm_mul_ps(v4, this->m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(this->m_vec.m_quad, this->m_vec.m_quad, 201), axis->m_quad));
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
             this->m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v3, v3), (__m128)xmmword_141A711B0), axis->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v3));
  v8 = _mm_add_ps(v7, v7);
  v9 = _mm_mul_ps(axis->m_quad, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0];
  if ( (float)(v10.m128_f32[0] - 1.0) <= (float)(0.0 - v11) )
  {
    if ( (float)(v10.m128_f32[0] + 1.0) >= v11 )
    {
      v23 = _mm_andnot_ps(*(__m128 *)_xmm, v10);
      v24 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v23), *(__m128 *)_xmm);
      v25 = _mm_cmplt_ps(*(__m128 *)_xmm, v23);
      v26 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v24), v25), _mm_andnot_ps(v25, v23));
      v27 = _mm_or_ps(_mm_andnot_ps(v25, _mm_mul_ps(v23, v23)), _mm_and_ps(v25, v24));
      v28 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)coeff4), *(__m128 *)coeff3), v27),
                            *(__m128 *)coeff2),
                          v27),
                        *(__m128 *)coeff1),
                      v27),
                    *(__m128 *)coeff0),
                  v27),
                v26),
              v26);
      v29 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v28, v28)), v25);
      v30 = _mm_andnot_ps(v25, v28);
      v31 = _mm_cmplt_ps(v23, *(__m128 *)_xmm);
      v32 = _mm_and_ps(v31, v23);
      v33 = _mm_andnot_ps(v31, _mm_or_ps(v29, v30));
      v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad), _mm_mul_ps(v8, v4));
      v35 = _mm_shuffle_ps(v34, v34, 201);
      angle.m_real = _mm_sub_ps(*(__m128 *)_xmm, _mm_xor_ps(_mm_or_ps(v33, v32), _mm_and_ps(v10, *(__m128 *)_xmm)));
      v36 = _mm_mul_ps(v35, v35);
      v37 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
              _mm_shuffle_ps(v36, v36, 170));
      v38 = _mm_rsqrt_ps(v37);
      axisa.m_quad = _mm_mul_ps(
                       v35,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v37, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                           _mm_mul_ps(*(__m128 *)_xmm, v38))));
      hkQuaternionf::setAxisAngle(this, &axisa, &angle);
    }
    else
    {
      v12 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
      v13 = _mm_shuffle_ps(v12, v12, 241);
      v14 = _mm_shuffle_ps(v12, v12, 206);
      v15 = _mm_mul_ps(v13, v13);
      v16 = _mm_mul_ps(v14, v14);
      v17 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170)));
      v18 = _mm_xor_ps(
              _mm_or_ps(_mm_and_ps(v14, v17), _mm_andnot_ps(v17, v13)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      v22.m_vec.m_quad = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v20, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                               _mm_mul_ps(*(__m128 *)_xmm, v21))),
                           v18);
      *this = (hkQuaternionf)v22.m_vec.m_quad;
      *(__m128i *)this = _mm_srli_si128(_mm_slli_si128((__m128i)v22.m_vec.m_quad, 4), 4);
    }
  }
  else
  {
    *this = (hkQuaternionf)qi.m_vec.m_quad;
  }
}

// File Line: 342
// RVA: 0xC584A0
void __fastcall hkQuaternionf::decomposeRestAxis(
        hkQuaternionf *this,
        hkVector4f *axis,
        hkQuaternionf *restOut,
        hkSimdFloat32 *angleOut)
{
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm11
  __m128 v11; // xmm0
  __m128 v12; // xmm11
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm11
  __m128i v18; // xmm10
  __m128 v19; // xmm9
  __m128 v20; // xmm7
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm3

  *restOut = (hkQuaternionf)this->m_vec.m_quad;
  hkQuaternionf::removeAxisComponent(restOut, axis);
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(restOut->m_vec.m_quad, restOut->m_vec.m_quad, 201), this->m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(this->m_vec.m_quad, this->m_vec.m_quad, 201), restOut->m_vec.m_quad));
  v9 = _mm_mul_ps(restOut->m_vec.m_quad, this->m_vec.m_quad);
  v10 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(restOut->m_vec.m_quad, restOut->m_vec.m_quad, 255), this->m_vec.m_quad),
            _mm_shuffle_ps(v8, v8, 201)),
          _mm_mul_ps(_mm_shuffle_ps(this->m_vec.m_quad, this->m_vec.m_quad, 255), restOut->m_vec.m_quad));
  v11 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11)), 196);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          v12,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)), _mm_mul_ps(*(__m128 *)_xmm, v16)));
  v18 = (__m128i)_mm_shuffle_ps(v17, v17, 255);
  v19 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v18, 1u), 1u);
  v20 = _mm_andnot_ps(*(__m128 *)_xmm, v19);
  v21 = _mm_cmplt_ps(v20, *(__m128 *)_xmm);
  v22 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v20), *(__m128 *)_xmm);
  v23 = _mm_cmplt_ps(*(__m128 *)_xmm, v20);
  v24 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v22), v23), _mm_andnot_ps(v23, v20));
  v25 = _mm_or_ps(_mm_andnot_ps(v23, _mm_mul_ps(v20, v20)), _mm_and_ps(v23, v22));
  v26 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v25, *(__m128 *)coeff4), *(__m128 *)coeff3), v25),
                        *(__m128 *)coeff2),
                      v25),
                    *(__m128 *)coeff1),
                  v25),
                *(__m128 *)coeff0),
              v25),
            v24),
          v24);
  v27 = _mm_mul_ps(axis->m_quad, v17);
  v28 = (__m128)COERCE_UNSIGNED_INT(
                  (float)(1.5707964
                        - COERCE_FLOAT((_mm_andnot_ps(
                                          v21,
                                          _mm_or_ps(
                                            _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v26, v26)), v23),
                                            _mm_andnot_ps(v23, v26))).m128_u32[0] | v21.m128_i32[0] & v20.m128_i32[0]) ^ v19.m128_i32[0] & _xmm[0]))
                * 2.0);
  angleOut->m_real = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32(
                                   (__m128i)_mm_mul_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                                                _mm_shuffle_ps(v27, v27, 170)),
                                              (__m128)v18),
                                   0x1Fu),
                                 0x1Fu),
                       _mm_shuffle_ps(v28, v28, 0));
}                             0x1Fu),
                       _

