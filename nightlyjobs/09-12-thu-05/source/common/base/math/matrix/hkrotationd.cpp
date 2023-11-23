// File Line: 12
// RVA: 0xC86F50
void __fastcall hkRotationd::set(hkRotationd *this, hkQuaterniond *qi)
{
  __m128d zw; // xmm4
  __m128d v3; // xmm8
  __m128d v4; // xmm7
  long double v5; // xmm5_8
  __m128d v6; // xmm2
  __m128d v7; // xmm7
  __m128d v8; // xmm3
  __m128d v9; // xmm6
  __m128d v10; // xmm8
  __m128d v11; // xmm4
  __m128d v12; // xmm0
  __m128d v13; // xmm3
  __m128d v14; // xmm1
  __m128d v15; // xmm8
  __m128d v16; // xmm7
  __m128d v17; // xmm8

  zw = qi->m_vec.m_quad.zw;
  v3 = _mm_add_pd(qi->m_vec.m_quad.xy, qi->m_vec.m_quad.xy);
  v4 = _mm_add_pd(zw, zw);
  v5 = qi->m_vec.m_quad.xy.m128d_f64[0] * v3.m128d_f64[0];
  v6 = _mm_unpacklo_pd(v4, v4);
  v7 = _mm_xor_pd(
         _mm_mul_pd(v6, zw),
         (__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskX);
  v8 = _mm_mul_pd(_mm_shuffle_pd(qi->m_vec.m_quad.xy, qi->m_vec.m_quad.xy, 1), _mm_unpackhi_pd(v3, v3));
  v9.m128d_f64[1] = g_vectordConstants[28].xy.m128d_f64[1];
  v7.m128d_f64[0] = v7.m128d_f64[0] + 1.0;
  v10 = _mm_mul_pd(_mm_shuffle_pd(v3, v3, 1), _mm_unpackhi_pd(zw, zw));
  v9.m128d_f64[0] = 1.0 - v5 - v8.m128d_f64[0];
  v10.m128d_f64[0] = -v10.m128d_f64[0];
  v10.m128d_f64[1] = -v10.m128d_f64[1];
  v11 = _mm_xor_pd((__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskY, v8);
  v12 = _mm_sub_pd(v7, v11);
  v11.m128d_f64[0] = v5;
  v13 = _mm_xor_pd(*(__m128d *)_xmm, _mm_mul_pd(v6, qi->m_vec.m_quad.xy));
  this->m_col0.m_quad.xy = v12;
  v14 = _mm_sub_pd(v10, v13);
  this->m_col0.m_quad.zw = v14;
  v10.m128d_f64[0] = -v10.m128d_f64[0];
  v10.m128d_f64[1] = -v10.m128d_f64[1];
  v15 = _mm_sub_pd(v10, v13);
  v16 = _mm_sub_pd(
          _mm_xor_pd(v7, (__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskY),
          v11);
  v17 = _mm_shuffle_pd(v15, v15, 1);
  this->m_col1.m_quad.xy = _mm_shuffle_pd(v16, v16, 1);
  this->m_col1.m_quad.zw = v17;
  this->m_col2.m_quad.xy = _mm_unpackhi_pd(v17, v14);
  this->m_col2.m_quad.zw = v9;
}

// File Line: 18
// RVA: 0xC87080
void __fastcall hkRotationd::setAxisAngle(hkRotationd *this, hkVector4d *axis, long double angle)
{
  hkQuaterniond qi; // [rsp+40h] [rbp+0h] BYREF

  hkQuaterniond::setAxisAngle((hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64), axis, angle);
  hkRotationd::set(this, (hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 25
// RVA: 0xC870C0
void __fastcall hkRotationd::setAxisAngle(hkRotationd *this, hkVector4d *axis, hkSimdDouble64 *angle)
{
  hkQuaterniond qi; // [rsp+40h] [rbp+0h] BYREF

  hkQuaterniond::setAxisAngle((hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64), axis, angle);
  hkRotationd::set(this, (hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 32
// RVA: 0xC87100
// local variable allocation has failed, the output may be wrong!
bool __fastcall hkRotationd::isOrthonormal(hkRotationd *this, long double epsilon, __int64 a3, long double a4)
{
  __m128d xy; // xmm6
  __m128d zw; // xmm8
  __m128d v6; // xmm3
  __m128d v7; // xmm0
  __m128d v8; // xmm1
  __m128d v10; // xmm4
  __m128d v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  __m128d v14; // xmm9
  __m128d v15; // xmm10
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  __m128d v18; // xmm0
  __m128d v19; // xmm4

  xy = this->m_col0.m_quad.xy;
  zw = this->m_col0.m_quad.zw;
  a4 = epsilon;
  v6 = _mm_shuffle_pd(*(__m128d *)&a4, *(__m128d *)&a4, 0);
  v7 = _mm_mul_pd(xy, xy);
  v8 = _mm_mul_pd(zw, zw);
  if ( _mm_unpacklo_pd(v7, v7).m128d_f64[0]
     + _mm_unpackhi_pd(v7, v7).m128d_f64[0]
     + _mm_unpacklo_pd(v8, v8).m128d_f64[0]
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v10 = this->m_col1.m_quad.xy;
  v11 = this->m_col1.m_quad.zw;
  v12 = _mm_mul_pd(v10, v10);
  v13 = _mm_mul_pd(v11, v11);
  if ( _mm_unpacklo_pd(v12, v12).m128d_f64[0]
     + _mm_unpackhi_pd(v12, v12).m128d_f64[0]
     + _mm_unpacklo_pd(v13, v13).m128d_f64[0]
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v14 = this->m_col2.m_quad.xy;
  v15 = this->m_col2.m_quad.zw;
  v16 = _mm_mul_pd(v14, v14);
  v17 = _mm_mul_pd(v15, v15);
  if ( _mm_unpacklo_pd(v16, v16).m128d_f64[0]
     + _mm_unpackhi_pd(v16, v16).m128d_f64[0]
     + _mm_unpacklo_pd(v17, v17).m128d_f64[0]
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v18 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v10, v11, 1), xy), _mm_mul_pd(_mm_shuffle_pd(xy, zw, 1), v10));
  v19 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v10, v11, 2), zw), _mm_mul_pd(_mm_shuffle_pd(xy, zw, 2), v11));
  return (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64((__m128i)_mm_sub_pd(_mm_shuffle_pd(v18, v19, 1), v14), 1u),
                                           1u),
                                v6)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     _mm_shuffle_pd(v18, v19, 2),
                                                                                     v15),
                                                                          1u),
                                                                        1u),
                                                             v6)))) & 7) == 7;
}

// File Line: 68
// RVA: 0xC872B0
bool __fastcall hkRotationd::isOk(hkRotationd *this, __int64 a2, __int64 a3, long double a4)
{
  return hkRotationd::isOrthonormal(this, 0.000009999999747378752, a3, a4) && hkMatrix3d::isOk(this);
}

// File Line: 73
// RVA: 0xC872F0
void __fastcall hkRotationd::renormalize(hkRotationd *this)
{
  hkQuaterniond *v1; // rbp
  double v2; // xmm3_8
  double v3; // xmm2_8
  double v4; // xmm4_8
  double v5; // xmm1_8
  long double v6; // xmm0_8
  double v7; // xmm4_8
  long double v8; // xmm1_8
  double v9; // xmm0_8
  int v10; // edx
  __int64 v11; // r9
  __int64 v12; // r10
  hkQuadDouble64 *v13; // rbx
  __int64 v14; // rsi
  double *v15; // r13
  hkQuadDouble64 *v16; // r11
  double *v17; // r12
  hkQuadDouble64 *v18; // rdi
  double *v19; // rax
  double v20; // xmm2_8
  double v21; // xmm3_8
  double *v22; // r12
  double *v23; // rax
  double *v24; // r9
  double *v25; // rax
  double *v26; // r9
  double *v27; // rax
  __m128d v28; // xmm5
  __m128d v29; // xmm4
  __m128d v30; // xmm0
  __m128d v31; // xmm1
  __m128d v32; // xmm3
  __m128d v33; // xmm2
  __m128d v34; // xmm1
  __int64 v35[4]; // [rsp+40h] [rbp+0h] BYREF

  v1 = (hkQuaterniond *)((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64);
  v2 = this->m_col0.m_quad.xy.m128d_f64[0];
  v3 = this->m_col1.m_quad.xy.m128d_f64[1];
  v4 = this->m_col2.m_quad.zw.m128d_f64[0];
  v5 = this->m_col0.m_quad.xy.m128d_f64[0] + v3 + v4;
  if ( v5 <= 0.0 )
  {
    v10 = 0;
    LODWORD(v1->m_vec.m_quad.xy.m128d_f64[0]) = 1;
    if ( v3 > v2 )
      v10 = 1;
    *(_QWORD *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 4) = 2i64;
    if ( v4 > this->m_col0.m_quad.xy.m128d_f64[4 * v10 + v10] )
      v10 = 2;
    v11 = *((int *)v1->m_vec.m_quad.xy.m128d_f64 + v10);
    v12 = *((int *)v1->m_vec.m_quad.xy.m128d_f64 + v11);
    v13 = &this->m_col0.m_quad + v10;
    v14 = v11;
    if ( v10 >= 2 )
      v15 = &v13->xy.m128d_f64[v10];
    else
      v15 = &v13->xy.m128d_f64[v10];
    v16 = &this->m_col0.m_quad + v11;
    if ( (int)v11 >= 2 )
      v17 = &v16->xy.m128d_f64[(int)v11];
    else
      v17 = &v16->xy.m128d_f64[v11];
    v18 = &this->m_col0.m_quad + v12;
    if ( (int)v12 >= 2 )
      v19 = &v18->xy.m128d_f64[(int)v12];
    else
      v19 = &v18->xy.m128d_f64[v12];
    v1->m_vec.m_quad.xy.m128d_f64[0] = *v15 - (*v17 + *v19) + 1.0;
    v20 = sqrt(v1->m_vec.m_quad.xy.m128d_f64[0]);
    v21 = 0.5 / v20;
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8i64 * v10) = v20 * 0.5;
    if ( (int)v12 >= 2 )
      v22 = &v16->xy.m128d_f64[(int)v12];
    else
      v22 = &v16->xy.m128d_f64[v12];
    if ( (int)v11 >= 2 )
      v23 = &v18->xy.m128d_f64[(int)v11];
    else
      v23 = &v18->xy.m128d_f64[v11];
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = (*v22 - *v23) * v21;
    if ( (int)v11 >= 2 )
      v11 = (int)v11 - 2 + 2i64;
    v24 = &v13->xy.m128d_f64[v11];
    if ( v10 >= 2 )
      v25 = &v16->xy.m128d_f64[v10];
    else
      v25 = &v16->xy.m128d_f64[v10];
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v14) = (*v25 + *v24) * v21;
    if ( (int)v12 >= 2 )
      v26 = &v13->xy.m128d_f64[(int)v12];
    else
      v26 = &v13->xy.m128d_f64[v12];
    if ( v10 >= 2 )
      v27 = &v18->xy.m128d_f64[v10];
    else
      v27 = &v18->xy.m128d_f64[v10];
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v12) = (*v27 + *v26) * v21;
  }
  else
  {
    v6 = this->m_col1.m_quad.zw.m128d_f64[0] - this->m_col2.m_quad.xy.m128d_f64[1];
    v1->m_vec.m_quad.xy.m128d_f64[0] = v5 + 1.0;
    v7 = sqrt(v1->m_vec.m_quad.xy.m128d_f64[0]);
    v8 = this->m_col2.m_quad.xy.m128d_f64[0] - this->m_col0.m_quad.zw.m128d_f64[0];
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = v7 * 0.5;
    *(long double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v6 * (0.5 / v7);
    v9 = this->m_col0.m_quad.xy.m128d_f64[1];
    *(long double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x28) = v8 * (0.5 / v7);
    *(double *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = (v9 - this->m_col1.m_quad.xy.m128d_f64[0])
                                                                         * (0.5
                                                                          / v7);
  }
  v28 = *(__m128d *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  v29 = *(__m128d *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  v30 = _mm_mul_pd(v28, v28);
  v31 = _mm_mul_pd(v29, v29);
  v32 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v30, v30, 1), v30), _mm_add_pd(_mm_shuffle_pd(v31, v31, 1), v31));
  v33 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v32)));
  v34 = _mm_mul_pd(
          _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v33, v32), v33)),
          _mm_mul_pd(v33, g_vectordConstants[17].xy));
  *(__m128d *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = _mm_mul_pd(v29, v34);
  *(__m128d *)(((unsigned __int64)v35 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = _mm_mul_pd(v28, v34);
  hkRotationd::set(this, v1 + 1);
}

