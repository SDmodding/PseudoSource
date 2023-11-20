// File Line: 12
// RVA: 0xC86F50
void __fastcall hkRotationd::set(hkRotationd *this, hkQuaterniond *qi)
{
  __m128d v2; // xmm4
  __m128d v3; // xmm8
  __m128d v4; // xmm7
  long double v5; // xmm5_8
  __m128d v6; // xmm7
  __m128d v7; // xmm2
  __m128d v8; // xmm7
  __m128d v9; // xmm3
  __m128d v10; // xmm6
  __m128d v11; // xmm8
  __m128d v12; // xmm4
  __m128d v13; // xmm0
  __m128d v14; // xmm3
  __m128d v15; // xmm1
  __m128d v16; // xmm8
  __m128d v17; // xmm7
  __m128d v18; // xmm8

  v2 = qi->m_vec.m_quad.zw;
  v3 = _mm_add_pd(qi->m_vec.m_quad.xy, qi->m_vec.m_quad.xy);
  v4 = _mm_add_pd(v2, v2);
  v5 = COERCE_DOUBLE(*(_OWORD *)&qi->m_vec.m_quad.xy) * v3.m128d_f64[0];
  v6 = _mm_unpckl_pd(v4, v4);
  v7 = v6;
  v8 = _mm_xor_pd(
         _mm_mul_pd(v6, v2),
         (__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskX);
  v9 = _mm_mul_pd(_mm_shuffle_pd(qi->m_vec.m_quad.xy, qi->m_vec.m_quad.xy, 1), _mm_unpckh_pd(v3, v3));
  v10.m128d_f64[1] = g_vectordConstants[28].xy.m128d_f64[1];
  v8.m128d_f64[0] = v8.m128d_f64[0] + 1.0;
  v11 = _mm_mul_pd(_mm_shuffle_pd(v3, v3, 1), _mm_unpckh_pd(v2, v2));
  v10.m128d_f64[0] = 1.0 - v5 - v9.m128d_f64[0];
  v11.m128d_f64[0] = -v11.m128d_f64[0];
  v11.m128d_f64[1] = -v11.m128d_f64[1];
  v12 = _mm_xor_pd((__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskY, v9);
  v13 = _mm_sub_pd(v8, v12);
  v12.m128d_f64[0] = v5;
  v14 = _mm_xor_pd(*(__m128d *)_xmm, _mm_mul_pd(v7, qi->m_vec.m_quad.xy));
  this->m_col0.m_quad.xy = v13;
  v15 = _mm_sub_pd(v11, v14);
  this->m_col0.m_quad.zw = v15;
  v11.m128d_f64[0] = -v11.m128d_f64[0];
  v11.m128d_f64[1] = -v11.m128d_f64[1];
  v16 = _mm_sub_pd(v11, v14);
  v17 = _mm_sub_pd(
          _mm_xor_pd(v8, (__m128d)`hkVector4UtilImpl<double>::convertQuaternionToRotation::`2::negateMaskY),
          v12);
  v18 = _mm_shuffle_pd(v16, v16, 1);
  this->m_col1.m_quad.xy = _mm_shuffle_pd(v17, v17, 1);
  this->m_col1.m_quad.zw = v18;
  this->m_col2.m_quad.xy = _mm_unpckh_pd(v18, v15);
  this->m_col2.m_quad.zw = v10;
}

// File Line: 18
// RVA: 0xC87080
void __fastcall hkRotationd::setAxisAngle(hkRotationd *this, hkVector4d *axis, long double angle)
{
  hkRotationd *v3; // rbx
  hkQuaterniond qi; // [rsp+40h] [rbp+0h]

  v3 = this;
  hkQuaterniond::setAxisAngle((hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64), axis, angle);
  hkRotationd::set(v3, (hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 25
// RVA: 0xC870C0
void __fastcall hkRotationd::setAxisAngle(hkRotationd *this, hkVector4d *axis, hkSimdDouble64 *angle)
{
  hkRotationd *v3; // rbx
  hkQuaterniond qi; // [rsp+40h] [rbp+0h]

  v3 = this;
  hkQuaterniond::setAxisAngle((hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64), axis, angle);
  hkRotationd::set(v3, (hkQuaterniond *)((unsigned __int64)&qi & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 32
// RVA: 0xC87100
int hkRotationd::isOrthonormal(...)
{
  __m128d v4; // xmm6
  __m128d v5; // xmm8
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
  __m128d v18; // xmm1
  __m128d v19; // xmm4

  v4 = this->m_col0.m_quad.xy;
  v5 = this->m_col0.m_quad.zw;
  a4.m128d_f64[0] = epsilon;
  v6 = _mm_shuffle_pd(a4, a4, 0);
  v7 = _mm_mul_pd(v4, v4);
  v8 = _mm_mul_pd(v5, v5);
  if ( COERCE_DOUBLE(_mm_unpckl_pd(v7, v7))
     + COERCE_DOUBLE(_mm_unpckh_pd(v7, v7))
     + COERCE_DOUBLE(_mm_unpckl_pd(v8, v8))
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v10 = this->m_col1.m_quad.xy;
  v11 = this->m_col1.m_quad.zw;
  v12 = _mm_mul_pd(v10, v10);
  v13 = _mm_mul_pd(v11, v11);
  if ( COERCE_DOUBLE(_mm_unpckl_pd(v12, v12))
     + COERCE_DOUBLE(_mm_unpckh_pd(v12, v12))
     + COERCE_DOUBLE(_mm_unpckl_pd(v13, v13))
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v14 = this->m_col2.m_quad.xy;
  v15 = this->m_col2.m_quad.zw;
  v16 = _mm_mul_pd(v14, v14);
  v17 = _mm_mul_pd(v15, v15);
  if ( COERCE_DOUBLE(_mm_unpckl_pd(v16, v16))
     + COERCE_DOUBLE(_mm_unpckh_pd(v16, v16))
     + COERCE_DOUBLE(_mm_unpckl_pd(v17, v17))
     - 1.0 > v6.m128d_f64[0] )
    return 0;
  v18 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v10, v11, 1), v4), _mm_mul_pd(_mm_shuffle_pd(v4, v5, 1), v10));
  v19 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v10, v11, 2), v5), _mm_mul_pd(_mm_shuffle_pd(v4, v5, 2), v11));
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
bool __fastcall hkRotationd::isOk(hkRotationd *this)
{
  hkRotationd *v1; // rbx

  v1 = this;
  return hkRotationd::isOrthonormal(this, 0.000009999999747378752) && hkMatrix3d::isOk((hkMatrix3d *)&v1->m_col0);
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
  signed int v10; // edx
  hkQuadDouble64 *v11; // r9
  double *v12; // rax
  signed __int64 v13; // r9
  __int64 v14; // r10
  hkQuadDouble64 *v15; // rbx
  __int64 v16; // rsi
  double *v17; // r13
  hkQuadDouble64 *v18; // r11
  double *v19; // r12
  hkQuadDouble64 *v20; // rdi
  double *v21; // rax
  double v22; // xmm2_8
  double v23; // xmm3_8
  double *v24; // r12
  double *v25; // rax
  double *v26; // r9
  double *v27; // rax
  double *v28; // r9
  double *v29; // rax
  __m128d v30; // xmm5
  __m128d v31; // xmm4
  __m128d v32; // xmm0
  __m128d v33; // xmm1
  __m128d v34; // xmm3
  __m128d v35; // xmm2
  __m128d v36; // xmm1
  __int64 v37; // [rsp+40h] [rbp+0h]

  v1 = (hkQuaterniond *)((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64);
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
    *(_QWORD *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 4) = 2i64;
    v11 = &this->m_col0.m_quad + v10;
    if ( v10 >= 2 )
      v12 = &v11->xy.m128d_f64[v10 - 2 + 2i64];
    else
      v12 = &v11->xy.m128d_f64[v10];
    if ( v4 > *v12 )
      v10 = 2;
    v13 = *((signed int *)v1->m_vec.m_quad.xy.m128d_f64 + v10);
    v14 = *((signed int *)v1->m_vec.m_quad.xy.m128d_f64 + v13);
    v15 = &this->m_col0.m_quad + v10;
    v16 = *((signed int *)v1->m_vec.m_quad.xy.m128d_f64 + v10);
    if ( v10 >= 2 )
      v17 = &v15->xy.m128d_f64[v10 - 2 + 2i64];
    else
      v17 = &v15->xy.m128d_f64[v10];
    v18 = &this->m_col0.m_quad + v13;
    if ( (signed int)v13 >= 2 )
      v19 = &v18->xy.m128d_f64[(signed int)v13 - 2 + 2i64];
    else
      v19 = &v18->xy.m128d_f64[v13];
    v20 = &this->m_col0.m_quad + v14;
    if ( (signed int)v14 >= 2 )
      v21 = &v20->xy.m128d_f64[(signed int)v14 - 2 + 2i64];
    else
      v21 = &v20->xy.m128d_f64[v14];
    v1->m_vec.m_quad.xy.m128d_f64[0] = *v17 - (*v19 + *v21) + 1.0;
    v22 = sqrt(v1->m_vec.m_quad.xy.m128d_f64[0]);
    v23 = 0.5 / v22;
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8i64 * v10) = v22 * 0.5;
    if ( (signed int)v14 >= 2 )
      v24 = &v18->xy.m128d_f64[(signed int)v14 - 2 + 2i64];
    else
      v24 = &v18->xy.m128d_f64[v14];
    if ( (signed int)v13 >= 2 )
      v25 = &v20->xy.m128d_f64[(signed int)v13 - 2 + 2i64];
    else
      v25 = &v20->xy.m128d_f64[v13];
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = (*v24 - *v25) * v23;
    if ( (signed int)v13 >= 2 )
      v13 = (signed int)v13 - 2 + 2i64;
    v26 = &v15->xy.m128d_f64[v13];
    if ( v10 >= 2 )
      v27 = &v18->xy.m128d_f64[v10 - 2 + 2i64];
    else
      v27 = &v18->xy.m128d_f64[v10];
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v16) = (*v27 + *v26) * v23;
    if ( (signed int)v14 >= 2 )
      v28 = &v15->xy.m128d_f64[(signed int)v14 - 2 + 2i64];
    else
      v28 = &v15->xy.m128d_f64[v14];
    if ( v10 >= 2 )
      v29 = &v20->xy.m128d_f64[v10 - 2 + 2i64];
    else
      v29 = &v20->xy.m128d_f64[v10];
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8 * v14) = (*v29 + *v28) * v23;
  }
  else
  {
    v6 = this->m_col1.m_quad.zw.m128d_f64[0] - this->m_col2.m_quad.xy.m128d_f64[1];
    v1->m_vec.m_quad.xy.m128d_f64[0] = v5 + 1.0;
    v7 = sqrt(v1->m_vec.m_quad.xy.m128d_f64[0]);
    v8 = this->m_col2.m_quad.xy.m128d_f64[0] - this->m_col0.m_quad.zw.m128d_f64[0];
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = v7 * 0.5;
    *(long double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v6 * (0.5 / v7);
    v9 = this->m_col0.m_quad.xy.m128d_f64[1];
    *(long double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x28) = v8 * (0.5 / v7);
    *(double *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = (v9 - this->m_col1.m_quad.xy.m128d_f64[0])
                                                                          * (0.5
                                                                           / v7);
  }
  v30 = *(__m128d *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  v31 = *(__m128d *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  v32 = _mm_mul_pd(v30, v30);
  v33 = _mm_mul_pd(v31, v31);
  v34 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v32, v32, 1), v32), _mm_add_pd(_mm_shuffle_pd(v33, v33, 1), v33));
  v35 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v34)));
  v36 = _mm_mul_pd(
          _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v35, v34), v35)),
          _mm_mul_pd(v35, g_vectordConstants[17].xy));
  *(__m128d *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = _mm_mul_pd(v31, v36);
  *(__m128d *)(((unsigned __int64)&v37 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = _mm_mul_pd(v30, v36);
  hkRotationd::set(this, v1 + 1);
}

