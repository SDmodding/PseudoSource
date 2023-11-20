// File Line: 13
// RVA: 0xC6A630
bool __fastcall hkMatrix4f::isOk(hkMatrix4f *this)
{
  return !_mm_movemask_ps(_mm_cmpunordps(this->m_col0.m_quad, this->m_col0.m_quad))
      && !_mm_movemask_ps(_mm_cmpunordps(this->m_col1.m_quad, this->m_col1.m_quad))
      && !_mm_movemask_ps(_mm_cmpunordps(this->m_col2.m_quad, this->m_col2.m_quad))
      && !_mm_movemask_ps(_mm_cmpunordps(this->m_col3.m_quad, this->m_col3.m_quad));
}

// File Line: 34
// RVA: 0xC6A530
hkResult *__fastcall hkMatrix4f::setInverse(hkMatrix4f *this, hkResult *result, hkMatrix4f *m, hkSimdFloat32 *eps)
{
  hkResult *v4; // rbx

  v4 = result;
  __hkMatrix4UtilAlgo::setInverse(result, m, this, eps);
  return v4;
}

// File Line: 39
// RVA: 0xC6A560
void __fastcall hkMatrix4f::transpose(hkMatrix4f *this)
{
  hkVector4f v1; // xmm2
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm1

  v1.m_quad = (__m128)this->m_col2;
  v2 = v1.m_quad;
  v3 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 238);
  v4 = _mm_shuffle_ps(v1.m_quad, this->m_col3.m_quad, 238);
  v5 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 68);
  v6 = _mm_shuffle_ps(v2, this->m_col3.m_quad, 68);
  this->m_col0.m_quad = _mm_shuffle_ps(v5, v6, 136);
  this->m_col1.m_quad = _mm_shuffle_ps(v5, v6, 221);
  this->m_col2.m_quad = _mm_shuffle_ps(v3, v4, 136);
  this->m_col3.m_quad = _mm_shuffle_ps(v3, v4, 221);
}

// File Line: 45
// RVA: 0xC6A5B0
void __fastcall hkMatrix4f::add(hkMatrix4f *this, hkMatrix4f *a)
{
  this->m_col0.m_quad = _mm_add_ps(a->m_col0.m_quad, this->m_col0.m_quad);
  this->m_col1.m_quad = _mm_add_ps(a->m_col1.m_quad, this->m_col1.m_quad);
  this->m_col2.m_quad = _mm_add_ps(a->m_col2.m_quad, this->m_col2.m_quad);
  this->m_col3.m_quad = _mm_add_ps(a->m_col3.m_quad, this->m_col3.m_quad);
}

// File Line: 53
// RVA: 0xC6A5F0
void __fastcall hkMatrix4f::sub(hkMatrix4f *this, hkMatrix4f *a)
{
  this->m_col0.m_quad = _mm_sub_ps(this->m_col0.m_quad, a->m_col0.m_quad);
  this->m_col1.m_quad = _mm_sub_ps(this->m_col1.m_quad, a->m_col1.m_quad);
  this->m_col2.m_quad = _mm_sub_ps(this->m_col2.m_quad, a->m_col2.m_quad);
  this->m_col3.m_quad = _mm_sub_ps(this->m_col3.m_quad, a->m_col3.m_quad);
}

// File Line: 64
// RVA: 0xC6A680
_BOOL8 __fastcall hkMatrix4f::isAffineTransformation(hkMatrix4f *this)
{
  return (_mm_movemask_ps(
            _mm_cmpeqps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_shuffle_ps(this->m_col0.m_quad, this->m_col0.m_quad, 255),
                  _mm_shuffle_ps(this->m_col1.m_quad, this->m_col1.m_quad, 255)),
                _mm_unpacklo_ps(
                  _mm_shuffle_ps(this->m_col2.m_quad, this->m_col2.m_quad, 255),
                  _mm_shuffle_ps(this->m_col3.m_quad, this->m_col3.m_quad, 255))),
              qi.m_vec.m_quad)) & 7) == 7;
}

// File Line: 80
// RVA: 0xC6A380
void __fastcall hkMatrix4f::get4x4RowMajor(hkMatrix4f *this, float *d)
{
  hkVector4f v2; // xmm2
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm3

  v2.m_quad = (__m128)this->m_col2;
  v3 = v2.m_quad;
  v4 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 238);
  v5 = _mm_shuffle_ps(v2.m_quad, this->m_col3.m_quad, 238);
  v6 = _mm_shuffle_ps(v3, this->m_col3.m_quad, 68);
  v7 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 68);
  *(__m128 *)d = _mm_shuffle_ps(v7, v6, 136);
  *((__m128 *)d + 1) = _mm_shuffle_ps(v7, v6, 221);
  *((__m128 *)d + 2) = _mm_shuffle_ps(v4, v5, 136);
  *((__m128 *)d + 3) = _mm_shuffle_ps(v4, v5, 221);
}

// File Line: 112
// RVA: 0xC6A3D0
void __fastcall hkMatrix4f::get4x4RowMajor(hkMatrix4f *this, long double *d)
{
  hkVector4f v2; // xmm2
  __m128 v3; // xmm0
  __m128 v4; // xmm5
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm5

  v2.m_quad = (__m128)this->m_col2;
  v3 = v2.m_quad;
  v4 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 238);
  v5 = _mm_shuffle_ps(v2.m_quad, this->m_col3.m_quad, 238);
  v6 = _mm_shuffle_ps(v3, this->m_col3.m_quad, 68);
  v7 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col1.m_quad, 68);
  v8 = _mm_shuffle_ps(v4, v5, 136);
  v9 = _mm_shuffle_ps(v7, v6, 136);
  v10 = _mm_shuffle_ps(v7, v6, 221);
  v11 = _mm_shuffle_ps(v4, v5, 221);
  *(__m128d *)d = _mm_cvtps_pd(v9);
  *((__m128d *)d + 1) = _mm_cvtps_pd(_mm_movehl_ps(v9, v9));
  *((__m128d *)d + 2) = _mm_cvtps_pd(v10);
  *((__m128d *)d + 3) = _mm_cvtps_pd(_mm_movehl_ps(v10, v10));
  *((__m128d *)d + 4) = _mm_cvtps_pd(v8);
  *((__m128d *)d + 5) = _mm_cvtps_pd(_mm_movehl_ps(v8, v8));
  *((__m128d *)d + 6) = _mm_cvtps_pd(v11);
  *((__m128d *)d + 7) = _mm_cvtps_pd(_mm_movehl_ps(v11, v11));
}

// File Line: 144
// RVA: 0xC6A460
void __fastcall hkMatrix4f::set4x4RowMajor(hkMatrix4f *this, const float *p)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  __m128 v7; // xmm2

  v2 = *(__m128 *)((char *)p + 32);
  v3 = v2;
  v4 = _mm_shuffle_ps(*(__m128 *)p, *(__m128 *)((char *)p + 16), 238);
  v5 = _mm_shuffle_ps(v2, *(__m128 *)((char *)p + 48), 238);
  v6 = _mm_shuffle_ps(v3, *(__m128 *)((char *)p + 48), 68);
  v7 = _mm_shuffle_ps(*(__m128 *)p, *(__m128 *)((char *)p + 16), 68);
  this->m_col0.m_quad = _mm_shuffle_ps(v7, v6, 136);
  this->m_col1.m_quad = _mm_shuffle_ps(v7, v6, 221);
  this->m_col2.m_quad = _mm_shuffle_ps(v4, v5, 136);
  this->m_col3.m_quad = _mm_shuffle_ps(v4, v5, 221);
}

// File Line: 176
// RVA: 0xC6A4B0
void __fastcall hkMatrix4f::set4x4RowMajor(hkMatrix4f *this, const long double *p)
{
  __m128 v2; // xmm5
  __m128 v3; // xmm3
  __m128 v4; // xmm2
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm4

  v2 = _mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)p), _mm_cvtpd_ps(*(__m128d *)((char *)p + 16)));
  v3 = _mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)((char *)p + 32)), _mm_cvtpd_ps(*(__m128d *)((char *)p + 48)));
  v4 = _mm_shuffle_ps(v2, v3, 68);
  v5 = _mm_shuffle_ps(v2, v3, 238);
  v6 = _mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)((char *)p + 64)), _mm_cvtpd_ps(*(__m128d *)((char *)p + 80)));
  v7 = _mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)((char *)p + 96)), _mm_cvtpd_ps(*(__m128d *)((char *)p + 112)));
  v8 = _mm_shuffle_ps(v6, v7, 68);
  v9 = _mm_shuffle_ps(v6, v7, 238);
  this->m_col0.m_quad = _mm_shuffle_ps(v4, v8, 136);
  this->m_col1.m_quad = _mm_shuffle_ps(v4, v8, 221);
  this->m_col2.m_quad = _mm_shuffle_ps(v5, v9, 136);
  this->m_col3.m_quad = _mm_shuffle_ps(v5, v9, 221);
}

// File Line: 208
// RVA: 0xC6A260
void __fastcall hkMatrix4f::get4x4ColumnMajor(hkMatrix4f *this, float *d)
{
  hkVector4f v2; // xmm1
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1

  v2.m_quad = (__m128)this->m_col1;
  *(hkVector4f *)d = this->m_col0;
  v3.m_quad = (__m128)this->m_col2;
  *((hkVector4f *)d + 1) = (hkVector4f)v2.m_quad;
  v4.m_quad = (__m128)this->m_col3;
  *((hkVector4f *)d + 2) = (hkVector4f)v3.m_quad;
  *((hkVector4f *)d + 3) = (hkVector4f)v4.m_quad;
}

// File Line: 216
// RVA: 0xC6A300
void __fastcall hkMatrix4f::set4x4ColumnMajor(hkMatrix4f *this, const float *p)
{
  this->m_col0 = *(hkVector4f *)p;
  this->m_col1 = (hkVector4f)*((_OWORD *)p + 1);
  this->m_col2 = (hkVector4f)*((_OWORD *)p + 2);
  this->m_col3 = (hkVector4f)*((_OWORD *)p + 3);
}

// File Line: 224
// RVA: 0xC6A290
void __fastcall hkMatrix4f::get4x4ColumnMajor(hkMatrix4f *this, long double *d)
{
  __m128 v2; // xmm1
  __m128d v3; // xmm0
  hkVector4f v4; // xmm1
  __m128d v5; // xmm0
  hkVector4f v6; // xmm1
  __m128d v7; // xmm0
  hkVector4f v8; // xmm1

  v2 = _mm_movehl_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  *(__m128d *)d = _mm_cvtps_pd(this->m_col0.m_quad);
  v3 = _mm_cvtps_pd(v2);
  v4.m_quad = (__m128)this->m_col1;
  *((__m128d *)d + 1) = v3;
  *((__m128d *)d + 2) = _mm_cvtps_pd(v4.m_quad);
  v5 = _mm_cvtps_pd(_mm_movehl_ps(v4.m_quad, v4.m_quad));
  v6.m_quad = (__m128)this->m_col2;
  *((__m128d *)d + 3) = v5;
  *((__m128d *)d + 4) = _mm_cvtps_pd(v6.m_quad);
  v7 = _mm_cvtps_pd(_mm_movehl_ps(v6.m_quad, v6.m_quad));
  v8.m_quad = (__m128)this->m_col3;
  *((__m128d *)d + 5) = v7;
  *((__m128d *)d + 6) = _mm_cvtps_pd(v8.m_quad);
  *((__m128d *)d + 7) = _mm_cvtps_pd(_mm_movehl_ps(v8.m_quad, v8.m_quad));
}

// File Line: 232
// RVA: 0xC6A330
void __fastcall hkMatrix4f::set4x4ColumnMajor(hkMatrix4f *this, const long double *p)
{
  this->m_col0.m_quad = _mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)p), _mm_cvtpd_ps(*(__m128d *)((char *)p + 16)));
  this->m_col1.m_quad = _mm_movelh_ps(
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 32)),
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 48)));
  this->m_col2.m_quad = _mm_movelh_ps(
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 64)),
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 80)));
  this->m_col3.m_quad = _mm_movelh_ps(
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 96)),
                          _mm_cvtpd_ps(*(__m128d *)((char *)p + 112)));
}

// File Line: 244
// RVA: 0xC6A120
void __fastcall hkMatrix4f::set(hkMatrix4f *this, hkQTransformf *qt)
{
  hkMatrix4f *v2; // rdi
  hkQTransformf *v3; // rbx
  __m128 v4; // xmm2
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  __m128i v7; // xmm0
  hkRotationf v8; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = qt;
  hkRotationf::set(&v8, &qt->m_rotation);
  v4 = v3->m_translation.m_quad;
  v5.m_quad = (__m128)v8.m_col1;
  v2->m_col0 = v8.m_col0;
  v6.m_quad = (__m128)v8.m_col2;
  v2->m_col1 = (hkVector4f)v5.m_quad;
  v2->m_col2 = (hkVector4f)v6.m_quad;
  v7 = _mm_load_si128((const __m128i *)v2);
  v2->m_col3.m_quad = v4;
  _mm_store_si128((__m128i *)v2, _mm_srli_si128(_mm_slli_si128(v7, 4), 4));
  _mm_store_si128(
    (__m128i *)&v2->m_col2,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v2->m_col2), 4), 4));
  _mm_store_si128((__m128i *)&v2->m_col1, _mm_srli_si128(_mm_slli_si128((__m128i)v5.m_quad, 4), 4));
  v2->m_col3.m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, query.m_quad), 196);
}

// File Line: 255
// RVA: 0xC6A1C0
void __fastcall hkMatrix4f::set(hkMatrix4f *this, hkQsTransformf *qst)
{
  hkMatrix4f *v2; // rdi
  hkQsTransformf *v3; // rbx
  __m128 v4; // xmm4
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  hkRotationf v8; // [rsp+20h] [rbp-38h]

  v2 = this;
  v3 = qst;
  hkRotationf::set(&v8, &qst->m_rotation);
  v4 = v3->m_scale.m_quad;
  v5 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v8.m_col0.m_quad);
  v6 = _mm_mul_ps(_mm_shuffle_ps(v3->m_scale.m_quad, v4, 85), v8.m_col1.m_quad);
  v7 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v8.m_col2.m_quad);
  v2->m_col0.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, (__m128)0i64), 196);
  v2->m_col1.m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, (__m128)0i64), 196);
  v2->m_col2.m_quad = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 196);
  v2->m_col3.m_quad = _mm_shuffle_ps(
                        v3->m_translation.m_quad,
                        _mm_unpackhi_ps(v3->m_translation.m_quad, query.m_quad),
                        196);
}

