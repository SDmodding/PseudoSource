// File Line: 13
// RVA: 0xC83140
bool __fastcall hkMatrix4d::isOk(hkMatrix4d *this)
{
  BOOL v1; // eax
  bool v2; // r9
  BOOL v3; // eax
  bool v4; // r8
  BOOL v5; // eax
  bool v6; // dl
  BOOL v7; // eax

  v1 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col0.m_quad.xy, (__m128d)0i64))
    && !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col0.m_quad.zw, (__m128d)0i64));
  v2 = v1;
  v3 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col1.m_quad.xy, (__m128d)0i64))
    && !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col1.m_quad.zw, (__m128d)0i64));
  v4 = v3;
  v5 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col2.m_quad.xy, (__m128d)0i64))
    && !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col2.m_quad.zw, (__m128d)0i64));
  v6 = v5;
  v7 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col3.m_quad.xy, (__m128d)0i64))
    && !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col3.m_quad.zw, (__m128d)0i64));
  return v2 && v4 && v6 && v7;
}

// File Line: 34
// RVA: 0xC82F80
hkResult *__fastcall hkMatrix4d::setInverse(hkMatrix4d *this, hkResult *result, hkMatrix4d *m, hkSimdDouble64 *eps)
{
  __hkMatrix4UtilAlgo::setInverse(result, m, this, eps);
  return result;
}

// File Line: 39
// RVA: 0xC82FB0
void __fastcall hkMatrix4d::transpose(hkMatrix4d *this)
{
  __m128d xy; // xmm1
  __m128d zw; // xmm3
  __m128d v3; // xmm4
  __m128d v4; // xmm2
  __m128d v5; // xmm0
  __m128d v6; // xmm1
  __m128d v7; // xmm2
  __m128d v8; // xmm0
  __m128d v9; // xmm1
  __m128d v10; // xmm0
  __m128d v11; // xmm3
  __m128d v12; // xmm0
  __m128d v13; // xmm2

  xy = this->m_col1.m_quad.xy;
  zw = this->m_col3.m_quad.zw;
  v3 = this->m_col0.m_quad.zw;
  v4 = _mm_unpacklo_pd(this->m_col0.m_quad.xy, xy);
  v5 = _mm_unpackhi_pd(this->m_col0.m_quad.xy, xy);
  v6 = this->m_col2.m_quad.zw;
  this->m_col1.m_quad.xy = v5;
  this->m_col0.m_quad.xy = v4;
  v7 = this->m_col2.m_quad.xy;
  v8 = v6;
  v9 = _mm_unpacklo_pd(v6, zw);
  v10 = _mm_unpackhi_pd(v8, zw);
  v11 = this->m_col1.m_quad.zw;
  this->m_col3.m_quad.zw = v10;
  v12 = v7;
  v13 = _mm_unpackhi_pd(v7, this->m_col3.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_unpacklo_pd(v12, this->m_col3.m_quad.xy);
  this->m_col2.m_quad.zw = v9;
  this->m_col1.m_quad.zw = v13;
  this->m_col3.m_quad.xy = _mm_unpackhi_pd(v3, v11);
  this->m_col2.m_quad.xy = _mm_unpacklo_pd(v3, v11);
}

// File Line: 44
// RVA: 0xC83040
void __fastcall hkMatrix4d::add(hkMatrix4d *this, hkMatrix4d *a)
{
  this->m_col0.m_quad.xy = _mm_add_pd(a->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_add_pd(a->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  this->m_col1.m_quad.xy = _mm_add_pd(this->m_col1.m_quad.xy, a->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_add_pd(a->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  this->m_col2.m_quad.xy = _mm_add_pd(this->m_col2.m_quad.xy, a->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_add_pd(a->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  this->m_col3.m_quad.xy = _mm_add_pd(this->m_col3.m_quad.xy, a->m_col3.m_quad.xy);
  this->m_col3.m_quad.zw = _mm_add_pd(a->m_col3.m_quad.zw, this->m_col3.m_quad.zw);
}

// File Line: 52
// RVA: 0xC830C0
void __fastcall hkMatrix4d::sub(hkMatrix4d *this, hkMatrix4d *a)
{
  __m128d zw; // xmm1
  __m128d v3; // xmm1
  __m128d v4; // xmm1
  __m128d v5; // xmm1

  zw = this->m_col0.m_quad.zw;
  this->m_col0.m_quad.xy = _mm_sub_pd(this->m_col0.m_quad.xy, a->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_sub_pd(zw, a->m_col0.m_quad.zw);
  v3 = this->m_col1.m_quad.zw;
  this->m_col1.m_quad.xy = _mm_sub_pd(this->m_col1.m_quad.xy, a->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_sub_pd(v3, a->m_col1.m_quad.zw);
  v4 = this->m_col2.m_quad.zw;
  this->m_col2.m_quad.xy = _mm_sub_pd(this->m_col2.m_quad.xy, a->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_sub_pd(v4, a->m_col2.m_quad.zw);
  v5 = this->m_col3.m_quad.zw;
  this->m_col3.m_quad.xy = _mm_sub_pd(this->m_col3.m_quad.xy, a->m_col3.m_quad.xy);
  this->m_col3.m_quad.zw = _mm_sub_pd(v5, a->m_col3.m_quad.zw);
}

// File Line: 63
// RVA: 0xC83230
_BOOL8 __fastcall hkMatrix4d::isAffineTransformation(hkMatrix4d *this)
{
  return (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmpeq_pd(
                                _mm_unpacklo_pd(
                                  _mm_unpackhi_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw),
                                  _mm_unpackhi_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw)),
                                g_vectordConstants[31].xy)) | (unsigned __int8)(4
                                                                              * _mm_movemask_pd(
                                                                                  _mm_cmpeq_pd(
                                                                                    _mm_unpacklo_pd(
                                                                                      _mm_unpackhi_pd(
                                                                                        this->m_col2.m_quad.zw,
                                                                                        this->m_col2.m_quad.zw),
                                                                                      _mm_unpackhi_pd(
                                                                                        this->m_col3.m_quad.zw,
                                                                                        this->m_col3.m_quad.zw)),
                                                                                    g_vectordConstants[31].zw)))) & 7) == 7;
}

// File Line: 79
// RVA: 0xC82C60
void __fastcall hkMatrix4d::get4x4RowMajor(hkMatrix4d *this, __m128 *d)
{
  __m128d zw; // xmm9
  __m128d xy; // xmm0
  __m128d v4; // xmm3
  __m128d v5; // xmm5
  __m128d v6; // xmm2
  __m128d v7; // xmm8
  __m128d v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128d v11; // xmm9

  zw = this->m_col0.m_quad.zw;
  xy = this->m_col2.m_quad.xy;
  v4 = _mm_unpackhi_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v5 = this->m_col2.m_quad.zw;
  v6 = _mm_unpacklo_pd(zw, this->m_col1.m_quad.zw);
  v7 = _mm_unpacklo_pd(v5, this->m_col3.m_quad.zw);
  v8 = _mm_unpackhi_pd(v5, this->m_col3.m_quad.zw);
  v9 = _mm_movelh_ps(
         _mm_cvtpd_ps(_mm_unpacklo_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy)),
         _mm_cvtpd_ps(_mm_unpacklo_pd(xy, this->m_col3.m_quad.xy)));
  v10 = _mm_cvtpd_ps(_mm_unpackhi_pd(xy, this->m_col3.m_quad.xy));
  *d = v9;
  v11 = _mm_unpackhi_pd(zw, this->m_col1.m_quad.zw);
  d[1] = _mm_movelh_ps(_mm_cvtpd_ps(v4), v10);
  d[2] = _mm_movelh_ps(_mm_cvtpd_ps(v6), _mm_cvtpd_ps(v7));
  d[3] = _mm_movelh_ps(_mm_cvtpd_ps(v11), _mm_cvtpd_ps(v8));
}

// File Line: 111
// RVA: 0xC82D30
void __fastcall hkMatrix4d::get4x4RowMajor(hkMatrix4d *this, __m128d *d)
{
  __m128d zw; // xmm9
  __m128d v3; // xmm7
  __m128d xy; // xmm0
  __m128d v5; // xmm6
  __m128d v6; // xmm0
  __m128d v7; // xmm3
  __m128d v8; // xmm4
  __m128d v9; // xmm1
  __m128d v10; // xmm7
  __m128d v11; // xmm9

  zw = this->m_col0.m_quad.zw;
  v3 = this->m_col2.m_quad.zw;
  xy = this->m_col2.m_quad.xy;
  v5 = _mm_unpackhi_pd(xy, this->m_col3.m_quad.xy);
  v6 = _mm_unpacklo_pd(xy, this->m_col3.m_quad.xy);
  v7 = _mm_unpackhi_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  *d = _mm_unpacklo_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v8 = v3;
  v9 = _mm_unpacklo_pd(zw, this->m_col1.m_quad.zw);
  v10 = _mm_unpacklo_pd(v3, this->m_col3.m_quad.zw);
  v11 = _mm_unpackhi_pd(zw, this->m_col1.m_quad.zw);
  d[1] = v6;
  d[2] = v7;
  d[3] = v5;
  d[4] = v9;
  d[5] = v10;
  d[6] = v11;
  d[7] = _mm_unpackhi_pd(v8, this->m_col3.m_quad.zw);
}

// File Line: 143
// RVA: 0xC82DF0
void __fastcall hkMatrix4d::set4x4RowMajor(hkMatrix4d *this, const float *p)
{
  __m128d v2; // xmm8
  __m128d v3; // xmm9
  __m128 v4; // xmm0
  __m128d v5; // xmm3
  __m128d v6; // xmm5
  __m128 v7; // xmm0
  __m128d v8; // xmm6
  __m128d v9; // xmm7
  __m128 v10; // xmm0
  __m128d v11; // xmm2
  __m128d v12; // xmm1

  v2 = _mm_cvtps_pd(*(__m128 *)p);
  v3 = _mm_cvtps_pd(_mm_shuffle_ps(*(__m128 *)p, *(__m128 *)p, 78));
  v4 = *(__m128 *)(p + 4);
  v5 = _mm_cvtps_pd(v4);
  v6 = _mm_cvtps_pd(_mm_shuffle_ps(v4, v4, 78));
  v7 = *(__m128 *)(p + 8);
  v8 = _mm_cvtps_pd(v7);
  v9 = _mm_cvtps_pd(_mm_shuffle_ps(v7, v7, 78));
  v10 = *(__m128 *)(p + 12);
  this->m_col0.m_quad.xy = _mm_unpacklo_pd(v2, v5);
  v11 = _mm_cvtps_pd(v10);
  this->m_col1.m_quad.xy = _mm_unpackhi_pd(v2, v5);
  v12 = _mm_cvtps_pd(_mm_shuffle_ps(v10, v10, 78));
  this->m_col3.m_quad.xy = _mm_unpackhi_pd(v3, v6);
  this->m_col0.m_quad.zw = _mm_unpacklo_pd(v8, v11);
  this->m_col1.m_quad.zw = _mm_unpackhi_pd(v8, v11);
  this->m_col2.m_quad.xy = _mm_unpacklo_pd(v3, v6);
  this->m_col2.m_quad.zw = _mm_unpacklo_pd(v9, v12);
  this->m_col3.m_quad.zw = _mm_unpackhi_pd(v9, v12);
}

// File Line: 175
// RVA: 0xC82EC0
void __fastcall hkMatrix4d::set4x4RowMajor(hkMatrix4d *this, const long double *p)
{
  __m128d v2; // xmm1
  __m128d v3; // xmm8
  __m128d v4; // xmm9
  __m128d v5; // xmm4
  __m128d v6; // xmm1
  __m128d v7; // xmm7
  __m128d v8; // xmm4
  __m128d v9; // xmm0
  __m128d v10; // xmm6

  v2 = (__m128d)*((_OWORD *)p + 1);
  v3 = _mm_unpacklo_pd(*(__m128d *)p, *(__m128d *)(p + 4));
  v4 = _mm_unpackhi_pd(v2, *(__m128d *)(p + 6));
  v5 = (__m128d)*((_OWORD *)p + 5);
  v6 = _mm_unpacklo_pd(v2, *(__m128d *)(p + 6));
  v7 = _mm_unpacklo_pd(v5, *(__m128d *)(p + 14));
  v8 = _mm_unpackhi_pd(v5, *(__m128d *)(p + 14));
  v9 = _mm_unpacklo_pd(*(__m128d *)(p + 8), *(__m128d *)(p + 12));
  v10 = _mm_unpackhi_pd(*(__m128d *)(p + 8), *(__m128d *)(p + 12));
  this->m_col1.m_quad.xy = _mm_unpackhi_pd(*(__m128d *)p, *(__m128d *)(p + 4));
  this->m_col2.m_quad.xy = v6;
  this->m_col0.m_quad.xy = v3;
  this->m_col3.m_quad.xy = v4;
  this->m_col1.m_quad.zw = v10;
  this->m_col2.m_quad.zw = v7;
  this->m_col0.m_quad.zw = v9;
  this->m_col3.m_quad.zw = v8;
}

// File Line: 207
// RVA: 0xC82AE0
void __fastcall hkMatrix4d::get4x4ColumnMajor(hkMatrix4d *this, __m128 *d)
{
  *d = _mm_movelh_ps(_mm_cvtpd_ps(this->m_col0.m_quad.xy), _mm_cvtpd_ps(this->m_col0.m_quad.zw));
  d[1] = _mm_movelh_ps(_mm_cvtpd_ps(this->m_col1.m_quad.xy), _mm_cvtpd_ps(this->m_col1.m_quad.zw));
  d[2] = _mm_movelh_ps(_mm_cvtpd_ps(this->m_col2.m_quad.xy), _mm_cvtpd_ps(this->m_col2.m_quad.zw));
  d[3] = _mm_movelh_ps(_mm_cvtpd_ps(this->m_col3.m_quad.xy), _mm_cvtpd_ps(this->m_col3.m_quad.zw));
}

// File Line: 215
// RVA: 0xC82B90
void __fastcall hkMatrix4d::set4x4ColumnMajor(hkMatrix4d *this, const float *p)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm1
  __m128 v4; // xmm1
  __m128 v5; // xmm1

  v2 = _mm_shuffle_ps(*(__m128 *)p, *(__m128 *)p, 78);
  this->m_col0.m_quad.xy = _mm_cvtps_pd(*(__m128 *)p);
  this->m_col0.m_quad.zw = _mm_cvtps_pd(v2);
  v3 = *(__m128 *)(p + 4);
  this->m_col1.m_quad.xy = _mm_cvtps_pd(v3);
  this->m_col1.m_quad.zw = _mm_cvtps_pd(_mm_shuffle_ps(v3, v3, 78));
  v4 = *(__m128 *)(p + 8);
  this->m_col2.m_quad.xy = _mm_cvtps_pd(v4);
  this->m_col2.m_quad.zw = _mm_cvtps_pd(_mm_shuffle_ps(v4, v4, 78));
  v5 = *(__m128 *)(p + 12);
  this->m_col3.m_quad.xy = _mm_cvtps_pd(v5);
  this->m_col3.m_quad.zw = _mm_cvtps_pd(_mm_shuffle_ps(v5, v5, 78));
}

// File Line: 223
// RVA: 0xC82B30
void __fastcall hkMatrix4d::get4x4ColumnMajor(hkMatrix4d *this, __m128d *d)
{
  __m128d zw; // xmm1
  __m128d xy; // xmm0
  __m128d v4; // xmm1
  __m128d v5; // xmm0
  __m128d v6; // xmm1
  __m128d v7; // xmm0
  __m128d v8; // xmm1

  zw = this->m_col0.m_quad.zw;
  *d = this->m_col0.m_quad.xy;
  xy = this->m_col1.m_quad.xy;
  d[1] = zw;
  v4 = this->m_col1.m_quad.zw;
  d[2] = xy;
  v5 = this->m_col2.m_quad.xy;
  d[3] = v4;
  v6 = this->m_col2.m_quad.zw;
  d[4] = v5;
  v7 = this->m_col3.m_quad.xy;
  d[5] = v6;
  v8 = this->m_col3.m_quad.zw;
  d[6] = v7;
  d[7] = v8;
}

// File Line: 231
// RVA: 0xC82C00
void __fastcall hkMatrix4d::set4x4ColumnMajor(hkMatrix4d *this, const long double *p)
{
  *this = *(hkMatrix4d *)p;
}

// File Line: 243
// RVA: 0xC82910
void __fastcall hkMatrix4d::set(hkMatrix4d *this, hkQTransformd *qt)
{
  __m128d xy; // xmm2
  __m128d zw; // xmm3
  __m128d v6; // xmm1
  __m128d v7; // xmm0
  __m128d v8; // xmm1
  __m128d v9; // xmm0
  __m128d v10; // xmm1
  __m128d v11; // xmm3
  hkRotationd v12; // [rsp+40h] [rbp+0h] BYREF

  hkRotationd::set((hkRotationd *)((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64), &qt->m_rotation);
  xy = qt->m_translation.m_quad.xy;
  zw = qt->m_translation.m_quad.zw;
  v6 = *(__m128d *)(((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10);
  this->m_col0.m_quad.xy = *(__m128d *)((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64);
  v7 = *(__m128d *)(((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  this->m_col0.m_quad.zw = v6;
  v8 = *(__m128d *)(((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  this->m_col3.m_quad.xy = xy;
  this->m_col1.m_quad.xy = v7;
  v9 = *(__m128d *)(((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
  this->m_col1.m_quad.zw = v8;
  v10 = *(__m128d *)(((unsigned __int64)&v12 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
  this->m_col3.m_quad.zw = zw;
  this->m_col2.m_quad.xy = v9;
  v11 = 0i64;
  this->m_col2.m_quad.zw = v10;
  this->m_col0.m_quad.zw = (__m128d)COERCE_UNSIGNED_INT64(this->m_col0.m_quad.zw.m128d_f64[0]);
  this->m_col1.m_quad.zw = (__m128d)COERCE_UNSIGNED_INT64(this->m_col1.m_quad.zw.m128d_f64[0]);
  v11.m128d_f64[0] = this->m_col2.m_quad.zw.m128d_f64[0];
  this->m_col2.m_quad.zw = v11;
  v10.m128d_f64[1] = g_vectordConstants[2].xy.m128d_f64[1];
  v10.m128d_f64[0] = this->m_col3.m_quad.zw.m128d_f64[0];
  this->m_col3.m_quad.zw = v10;
}

// File Line: 254
// RVA: 0xC829E0
void __fastcall hkMatrix4d::set(hkMatrix4d *this, hkQsTransformd *qst)
{
  __m128d xy; // xmm1
  __int128 v5; // xmm4
  __m128d v6; // xmm3
  __m128d v7; // xmm2
  __m128d v8; // xmm0
  __m128d v9; // xmm1
  __m128d v10; // xmm6
  unsigned __int64 v11; // xmm7_8
  __m128d v12; // xmm5
  __m128d zw; // xmm0
  __m128d v14; // xmm0
  __m128d v15; // xmm1
  hkRotationd v16; // [rsp+40h] [rbp+0h] BYREF

  hkRotationd::set((hkRotationd *)((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64), &qst->m_rotation);
  xy = qst->m_scale.m_quad.xy;
  v5 = *(_OWORD *)(((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  v6 = *(__m128d *)(((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
  v7 = *(__m128d *)(((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
  v8 = _mm_unpacklo_pd(xy, xy);
  v9 = _mm_unpackhi_pd(xy, xy);
  v10 = _mm_mul_pd(*(__m128d *)((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64), v8);
  *(double *)&v11 = *(double *)(((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) * v8.m128d_f64[0];
  v12 = _mm_mul_pd(*(__m128d *)(((unsigned __int64)&v16 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20), v9);
  zw = qst->m_scale.m_quad.zw;
  this->m_col0.m_quad.xy = v10;
  v14 = _mm_unpacklo_pd(zw, zw);
  *(double *)&v5 = *(double *)&v5 * v9.m128d_f64[0];
  v15 = 0i64;
  this->m_col0.m_quad.zw = (__m128d)v11;
  this->m_col1.m_quad.xy = v12;
  v15.m128d_f64[0] = v7.m128d_f64[0] * v14.m128d_f64[0];
  this->m_col1.m_quad.zw = (__m128d)(unsigned __int64)v5;
  this->m_col2.m_quad.xy = _mm_mul_pd(v6, v14);
  this->m_col2.m_quad.zw = v15;
  v7.m128d_f64[1] = g_vectordConstants[2].xy.m128d_f64[1];
  this->m_col3.m_quad.xy = qst->m_translation.m_quad.xy;
  v7.m128d_f64[0] = qst->m_translation.m_quad.zw.m128d_f64[0];
  this->m_col3.m_quad.zw = v7;
}

