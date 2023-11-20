// File Line: 15
// RVA: 0xC5B2E0
void __fastcall hkTransformf::get4x4ColumnMajor(hkTransformf *this, float *d)
{
  hkVector4f v2; // xmm1
  __m128i v3; // xmm3
  hkVector4f v4; // xmm2

  v2.m_quad = (__m128)this->m_translation;
  v3 = _mm_srli_si128(_mm_slli_si128((__m128i)this->m_rotation.m_col1.m_quad, 4), 4);
  v4.m_quad = (__m128)this->m_rotation.m_col2;
  *(__m128i *)d = _mm_srli_si128(_mm_slli_si128((__m128i)this->m_rotation.m_col0.m_quad, 4), 4);
  *((__m128i *)d + 1) = v3;
  *((__m128i *)d + 2) = _mm_srli_si128(_mm_slli_si128((__m128i)v4.m_quad, 4), 4);
  *((__m128 *)d + 3) = _mm_shuffle_ps(v2.m_quad, _mm_unpackhi_ps(v2.m_quad, query.m_quad), 196);
}

// File Line: 54
// RVA: 0xC5B340
void __fastcall hkTransformf::get4x4ColumnMajor(hkTransformf *this, long double *d)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm4
  __m128 v5; // xmm3

  v2 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)this->m_rotation.m_col0.m_quad, 4), 4);
  v3 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)this->m_rotation.m_col1.m_quad, 4), 4);
  v4 = _mm_shuffle_ps(this->m_translation.m_quad, _mm_unpackhi_ps(this->m_translation.m_quad, query.m_quad), 196);
  v5 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)this->m_rotation.m_col2.m_quad, 4), 4);
  *(__m128d *)d = _mm_cvtps_pd(v2);
  *((__m128d *)d + 1) = _mm_cvtps_pd(_mm_movehl_ps(v2, v2));
  *((__m128d *)d + 2) = _mm_cvtps_pd(v3);
  *((__m128d *)d + 3) = _mm_cvtps_pd(_mm_movehl_ps(v3, v3));
  *((__m128d *)d + 4) = _mm_cvtps_pd(v5);
  *((__m128d *)d + 5) = _mm_cvtps_pd(_mm_movehl_ps(v5, v5));
  *((__m128d *)d + 6) = _mm_cvtps_pd(v4);
  *((__m128d *)d + 7) = _mm_cvtps_pd(_mm_movehl_ps(v4, v4));
}

// File Line: 92
// RVA: 0xC5B3D0
void __fastcall hkTransformf::set4x4ColumnMajor(hkTransformf *this, const float *p)
{
  __m128 v2; // xmm1
  hkVector4f v3; // xmm3
  __m128i v4; // xmm2

  v2 = *(__m128 *)((char *)p + 48);
  v3.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)p + 16), 4), 4);
  v4 = *(__m128i *)((char *)p + 32);
  this->m_rotation.m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(*(__m128i *)p, 4), 4);
  this->m_rotation.m_col1 = (hkVector4f)v3.m_quad;
  this->m_rotation.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v4, 4), 4);
  this->m_translation.m_quad = _mm_shuffle_ps(v2, _mm_unpackhi_ps(v2, query.m_quad), 196);
}

// File Line: 130
// RVA: 0xC5B430
void __fastcall hkTransformf::set4x4ColumnMajor(hkTransformf *this, const long double *p)
{
  __m128 v2; // xmm1
  __m128i v3; // xmm3
  __m128 v4; // xmm0
  __m128i v5; // xmm2
  __m128 v6; // xmm1

  v2 = _mm_cvtpd_ps(*(__m128d *)((char *)p + 96));
  v3 = _mm_slli_si128(
         (__m128i)_mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)((char *)p + 32)), _mm_cvtpd_ps(*(__m128d *)((char *)p + 48))),
         4);
  v4 = _mm_cvtpd_ps(*(__m128d *)((char *)p + 112));
  v5 = _mm_slli_si128(
         (__m128i)_mm_movelh_ps(_mm_cvtpd_ps(*(__m128d *)((char *)p + 64)), _mm_cvtpd_ps(*(__m128d *)((char *)p + 80))),
         4);
  this->m_rotation.m_col0 = (hkVector4f)_mm_srli_si128(
                                          _mm_slli_si128(
                                            (__m128i)_mm_movelh_ps(
                                                       _mm_cvtpd_ps(*(__m128d *)p),
                                                       _mm_cvtpd_ps(*(__m128d *)((char *)p + 16))),
                                            4),
                                          4);
  v6 = _mm_movelh_ps(v2, v4);
  this->m_rotation.m_col1 = (hkVector4f)_mm_srli_si128(v3, 4);
  this->m_rotation.m_col2 = (hkVector4f)_mm_srli_si128(v5, 4);
  this->m_translation.m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, query.m_quad), 196);
}

// File Line: 168
// RVA: 0xC5AF40
void __fastcall hkTransformf::setInverse(hkTransformf *this, hkTransformf *t)
{
  hkVector4f v2; // xmm2
  __m128 v3; // xmm1
  hkVector4f v4; // xmm5
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm3
  __m128 v7; // xmm2

  v2.m_quad = (__m128)t->m_rotation.m_col2;
  v3 = _mm_unpacklo_ps(t->m_rotation.m_col0.m_quad, t->m_rotation.m_col1.m_quad);
  v4.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(t->m_rotation.m_col0.m_quad, t->m_rotation.m_col1.m_quad), v2.m_quad, 228);
  this->m_rotation.m_col2 = (hkVector4f)v4.m_quad;
  v5.m_quad = _mm_movelh_ps(v3, v2.m_quad);
  this->m_rotation.m_col0 = (hkVector4f)v5.m_quad;
  v6.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v5.m_quad, v3), v2.m_quad, 212);
  this->m_rotation.m_col1 = (hkVector4f)v6.m_quad;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), t->m_translation.m_quad);
  this->m_translation.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v6.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v5.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v4.m_quad));
}

// File Line: 175
// RVA: 0xC5AFC0
void __fastcall hkTransformf::setMul(hkTransformf *this, hkTransformf *aTb, hkTransformf *bTc)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  signed __int64 v6; // r9
  __m128 *v7; // rax
  __m128 v8; // xmm1

  v3.m_quad = (__m128)aTb->m_rotation.m_col0;
  v4.m_quad = (__m128)aTb->m_rotation.m_col1;
  v5.m_quad = (__m128)aTb->m_rotation.m_col2;
  v6 = 3i64;
  v7 = &bTc->m_translation.m_quad;
  do
  {
    v8 = *v7;
    --v7;
    --v6;
    *(__m128 *)((char *)v7 + (char *)this - (char *)bTc + 16) = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v4.m_quad),
                                                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v3.m_quad)),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v5.m_quad));
  }
  while ( v6 >= 0 );
  this->m_translation.m_quad = _mm_add_ps(aTb->m_translation.m_quad, this->m_translation.m_quad);
}

// File Line: 180
// RVA: 0xC5B260
void __fastcall hkTransformf::setMulEq(hkTransformf *this, hkTransformf *bTc)
{
  hkVector4f v2; // xmm3
  hkVector4f v3; // xmm4
  hkVector4f v4; // xmm5
  signed __int64 v5; // r8
  __m128 *v6; // rax
  hkVector4f v7; // xmm6
  __m128 v8; // xmm1

  v2.m_quad = (__m128)this->m_rotation.m_col0;
  v3.m_quad = (__m128)this->m_rotation.m_col1;
  v4.m_quad = (__m128)this->m_rotation.m_col2;
  v5 = 3i64;
  v6 = &bTc->m_translation.m_quad;
  v7.m_quad = (__m128)this->m_translation;
  do
  {
    v8 = *v6;
    --v6;
    --v5;
    *(__m128 *)((char *)v6 + (char *)this - (char *)bTc + 16) = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v3.m_quad),
                                                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v2.m_quad)),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v4.m_quad));
  }
  while ( v5 >= 0 );
  this->m_translation.m_quad = _mm_add_ps(this->m_translation.m_quad, v7.m_quad);
}

// File Line: 188
// RVA: 0xC5B030
void __fastcall hkTransformf::setMul(hkTransformf *this, hkQsTransformf *aTb, hkTransformf *bTc)
{
  hkTransformf *v3; // rsi
  hkQsTransformf *v4; // rdi
  hkTransformf *v5; // rbx
  __m128 v6; // xmm2
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm5
  hkVector4f v9; // xmm4
  hkVector4f v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  hkMatrix3f v17; // [rsp+20h] [rbp-98h]
  hkMatrix3f bTca; // [rsp+50h] [rbp-68h]
  hkRotationf v19; // [rsp+80h] [rbp-38h]

  v3 = this;
  v4 = aTb;
  v5 = bTc;
  hkRotationf::set(&v19, &aTb->m_rotation);
  v6 = v4->m_scale.m_quad;
  v7.m_quad = _mm_mul_ps(v4->m_scale.m_quad, direction.m_quad);
  bTca.m_col2.m_quad = _mm_mul_ps(v6, stru_141A71280.m_quad);
  bTca.m_col0.m_quad = _mm_mul_ps(v6, transform.m_quad);
  bTca.m_col1 = (hkVector4f)v7.m_quad;
  hkMatrix3f::setMul(&v17, (hkMatrix3f *)&v19.m_col0, &bTca);
  v8.m_quad = (__m128)v17.m_col1;
  v9.m_quad = (__m128)v17.m_col0;
  v10.m_quad = (__m128)v17.m_col2;
  v11 = v5->m_rotation.m_col1.m_quad;
  v3->m_rotation.m_col0.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v5->m_rotation.m_col0.m_quad, v5->m_rotation.m_col0.m_quad, 85),
                                       v17.m_col1.m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v5->m_rotation.m_col0.m_quad, v5->m_rotation.m_col0.m_quad, 0),
                                       v17.m_col0.m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v5->m_rotation.m_col0.m_quad, v5->m_rotation.m_col0.m_quad, 170),
                                     v17.m_col2.m_quad));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v8.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v9.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v10.m_quad));
  v13 = v5->m_rotation.m_col2.m_quad;
  v3->m_rotation.m_col1.m_quad = v12;
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v8.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v9.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v10.m_quad));
  v15 = v5->m_translation.m_quad;
  v3->m_rotation.m_col2.m_quad = v14;
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v8.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v9.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v10.m_quad));
  v3->m_translation.m_quad = v16;
  v3->m_translation.m_quad = _mm_add_ps(v16, v4->m_translation.m_quad);
}

// File Line: 338
// RVA: 0xC5B180
void __fastcall hkTransformf::setMulInverseMul(hkTransformf *this, hkTransformf *bTa, hkTransformf *bTc)
{
  hkVector4f v3; // xmm2
  hkTransformf *v4; // r9
  hkTransformf *v5; // r10
  hkTransformf *v6; // rax
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  signed __int64 v9; // rdx
  signed __int64 v10; // rcx
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm2

  v3.m_quad = (__m128)bTa->m_rotation.m_col2;
  v4 = bTa;
  v5 = this;
  v6 = this;
  v7 = _mm_unpacklo_ps(bTa->m_rotation.m_col0.m_quad, bTa->m_rotation.m_col1.m_quad);
  v8 = _mm_shuffle_ps(_mm_unpackhi_ps(bTa->m_rotation.m_col0.m_quad, bTa->m_rotation.m_col1.m_quad), v3.m_quad, 228);
  v9 = (char *)bTc - (char *)this;
  v10 = 3i64;
  v11 = _mm_movelh_ps(v7, v3.m_quad);
  v12 = _mm_shuffle_ps(_mm_movehl_ps(v11, v7), v3.m_quad, 212);
  do
  {
    v13 = *(__m128 *)((char *)&v6->m_rotation.m_col0.m_quad + v9);
    v6 = (hkTransformf *)((char *)v6 + 16);
    v6[-1].m_translation.m_quad = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v12),
                                      _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v11)),
                                    _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v8));
    --v10;
  }
  while ( v10 );
  v14 = v4->m_rotation.m_col2.m_quad;
  v15 = _mm_sub_ps(bTc->m_translation.m_quad, v4->m_translation.m_quad);
  v16 = _mm_unpacklo_ps(v4->m_rotation.m_col0.m_quad, v4->m_rotation.m_col1.m_quad);
  v17 = _mm_movelh_ps(v16, v14);
  v5->m_translation.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(v15, v15, 85),
                                   _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v14, 212)),
                                 _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v17)),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v15, v15, 170),
                                 _mm_shuffle_ps(
                                   _mm_unpackhi_ps(v4->m_rotation.m_col0.m_quad, v4->m_rotation.m_col1.m_quad),
                                   v14,
                                   228)));
}

// File Line: 347
// RVA: 0xC5B590
bool __fastcall hkTransformf::isOk(hkTransformf *this)
{
  return !(_mm_movemask_ps(_mm_cmpunordps(this->m_translation.m_quad, this->m_translation.m_quad)) & 7)
      && hkRotationf::isOk(&this->m_rotation);
}

// File Line: 352
// RVA: 0xC5B4B0
void __fastcall hkTransformf::setMulMulInverse(hkTransformf *this, hkTransformf *wTa, hkTransformf *wTb)
{
  hkVector4f v3; // xmm5
  signed __int64 v4; // rax
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm3
  __m128 v7; // xmm1
  hkVector4f v8; // xmm3
  hkVector4f v9; // xmm4
  hkVector4f v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  hkVector4f v15; // xmm0
  __m128 v16; // [rsp+20h] [rbp-48h]
  hkVector4f v17; // [rsp+30h] [rbp-38h]
  __m128 v18; // [rsp+40h] [rbp-28h]
  __m128 v19; // [rsp+50h] [rbp-18h]
  __int64 v20; // [rsp+60h] [rbp-8h]

  v3.m_quad = (__m128)wTa->m_rotation.m_col2;
  v4 = 0i64;
  v16 = _mm_shuffle_ps(
          _mm_unpackhi_ps(wTb->m_rotation.m_col0.m_quad, wTb->m_rotation.m_col1.m_quad),
          wTb->m_rotation.m_col2.m_quad,
          228);
  v5.m_quad = (__m128)wTa->m_rotation.m_col1;
  v6.m_quad = (__m128)wTa->m_rotation.m_col0;
  do
  {
    v7 = *(__m128 *)((char *)&v16 + v4);
    v4 -= 16i64;
    *(__m128 *)((char *)&v20 + v4) = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v5.m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v3.m_quad));
  }
  while ( v4 >= -32 );
  v8.m_quad = (__m128)wTb->m_translation;
  v9.m_quad = v18;
  v10.m_quad = v19;
  v11 = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 85);
  v12 = _mm_shuffle_ps(wTb->m_translation.m_quad, v8.m_quad, 0);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 170), v19);
  v14 = _mm_add_ps(_mm_mul_ps(v11, v18), _mm_mul_ps(v12, v17.m_quad));
  v15.m_quad = (__m128)wTa->m_translation;
  this->m_rotation.m_col0 = (hkVector4f)v17.m_quad;
  this->m_rotation.m_col1 = (hkVector4f)v9.m_quad;
  this->m_rotation.m_col2 = (hkVector4f)v10.m_quad;
  this->m_translation.m_quad = _mm_sub_ps(v15.m_quad, _mm_add_ps(v14, v13));
}

// File Line: 357
// RVA: 0xC5AE50
bool __fastcall hkTransformf::isApproximatelyEqual(hkTransformf *this, hkTransformf *t, float zero)
{
  hkTransformf *v3; // rbx
  hkTransformf *v4; // rdi
  hkSimdFloat32 eps; // [rsp+20h] [rbp-18h]

  v3 = t;
  v4 = this;
  eps.m_real = _mm_shuffle_ps((__m128)LODWORD(zero), (__m128)LODWORD(zero), 0);
  return hkMatrix3f::isApproximatelyEqualSimd(
           (hkMatrix3f *)&this->m_rotation.m_col0,
           (hkMatrix3f *)&t->m_rotation.m_col0,
           &eps)
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(v4->m_translation.m_quad, v3->m_translation.m_quad), 1u),
                        1u),
              eps.m_real)) & 7) == 7;
}

// File Line: 364
// RVA: 0xC5AED0
bool __fastcall hkTransformf::isApproximatelyEqualSimd(hkTransformf *this, hkTransformf *t, hkSimdFloat32 *sZ)
{
  hkSimdFloat32 *v3; // rbx
  hkTransformf *v4; // rdi
  hkTransformf *v5; // rsi

  v3 = sZ;
  v4 = t;
  v5 = this;
  return hkMatrix3f::isApproximatelyEqualSimd(
           (hkMatrix3f *)&this->m_rotation.m_col0,
           (hkMatrix3f *)&t->m_rotation.m_col0,
           sZ)
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(v5->m_translation.m_quad, v4->m_translation.m_quad), 1u),
                        1u),
              v3->m_real)) & 7) == 7;
}

