// File Line: 14
// RVA: 0xC59820
bool __fastcall hkMatrix3f::isOk(hkMatrix3f *this)
{
  return !(_mm_movemask_ps(_mm_cmpunordps(this->m_col0.m_quad, this->m_col0.m_quad)) & 7)
      && !(_mm_movemask_ps(_mm_cmpunordps(this->m_col1.m_quad, this->m_col1.m_quad)) & 7)
      && !(_mm_movemask_ps(_mm_cmpunordps(this->m_col2.m_quad, this->m_col2.m_quad)) & 7);
}

// File Line: 37
// RVA: 0xC59350
void __fastcall hkMatrix3f::transpose(hkMatrix3f *this)
{
  hkVector4f v1; // xmm1
  __m128 v2; // xmm2
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm3

  v1.m_quad = (__m128)this->m_col2;
  v2 = _mm_unpacklo_ps(this->m_col0.m_quad, this->m_col1.m_quad);
  v3.m_quad = _mm_movelh_ps(v2, v1.m_quad);
  v4.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(this->m_col0.m_quad, this->m_col1.m_quad), v1.m_quad, 228);
  this->m_col0 = (hkVector4f)v3.m_quad;
  this->m_col2 = (hkVector4f)v4.m_quad;
  this->m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v3.m_quad, v2), v1.m_quad, 212);
}

// File Line: 42
// RVA: 0xC5A580
void __fastcall hkMatrix3f_setMulMat3Mat3(hkMatrix3f *THIS, hkMatrix3f *aTb, hkMatrix3f *bTc)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  signed __int64 v6; // rdx
  __m128 *v7; // rax
  signed __int64 v8; // rcx
  __m128 v9; // xmm1

  v3.m_quad = (__m128)aTb->m_col0;
  v4.m_quad = (__m128)aTb->m_col1;
  v5.m_quad = (__m128)aTb->m_col2;
  v6 = 2i64;
  v7 = &bTc->m_col2.m_quad;
  v8 = (char *)THIS - (char *)bTc;
  do
  {
    v9 = *v7;
    --v7;
    --v6;
    *(__m128 *)((char *)v7 + v8 + 16) = _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v4.m_quad),
                                            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v3.m_quad)),
                                          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v5.m_quad));
  }
  while ( v6 >= 0 );
}

// File Line: 49
// RVA: 0xC5A5E0
void __fastcall hkMatrix3f_invertSymmetric(hkMatrix3f *thisMatrix)
{
  hkMatrix3f::invertSymmetric(thisMatrix);
}

// File Line: 56
// RVA: 0xC59390
void __fastcall hkMatrix3f::setTranspose(hkMatrix3f *this, hkMatrix3f *s)
{
  hkVector4f v2; // xmm3
  __m128 v3; // xmm2
  hkVector4f v4; // xmm1

  v2.m_quad = (__m128)s->m_col2;
  v3 = _mm_unpacklo_ps(s->m_col0.m_quad, s->m_col1.m_quad);
  this->m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(s->m_col0.m_quad, s->m_col1.m_quad), v2.m_quad, 228);
  v4.m_quad = _mm_movelh_ps(v3, v2.m_quad);
  this->m_col0 = (hkVector4f)v4.m_quad;
  this->m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v4.m_quad, v3), v2.m_quad, 212);
}

// File Line: 62
// RVA: 0xC593D0
void __fastcall hkMatrix3f::setMul(hkMatrix3f *this, hkMatrix3f *aTb, hkMatrix3f *bTc)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  signed __int64 v6; // rdx
  __m128 *v7; // rax
  signed __int64 v8; // rcx
  __m128 v9; // xmm1

  v3.m_quad = (__m128)aTb->m_col0;
  v4.m_quad = (__m128)aTb->m_col1;
  v5.m_quad = (__m128)aTb->m_col2;
  v6 = 2i64;
  v7 = &bTc->m_col2.m_quad;
  v8 = (char *)this - (char *)bTc;
  do
  {
    v9 = *v7;
    --v7;
    --v6;
    *(__m128 *)((char *)v7 + v8 + 16) = _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v4.m_quad),
                                            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v3.m_quad)),
                                          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v5.m_quad));
  }
  while ( v6 >= 0 );
}

// File Line: 68
// RVA: 0xC59700
void __fastcall hkMatrix3f::changeBasis(hkMatrix3f *this, hkRotationf *r)
{
  hkRotationf *v2; // rbx
  hkMatrix3f *v3; // rdi
  hkMatrix3f bTc; // [rsp+20h] [rbp-38h]

  v2 = r;
  v3 = this;
  hkMatrix3f::setMulInverse(&bTc, this, r);
  hkMatrix3f::setMul(v3, (hkMatrix3f *)&v2->m_col0, &bTc);
}

// File Line: 75
// RVA: 0xC59430
void __fastcall hkMatrix3f::setMulInverse(hkMatrix3f *this, hkMatrix3f *aTb, hkRotationf *cTb)
{
  hkVector4f v3; // xmm5
  signed __int64 v4; // rax
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm3
  __m128 v7; // xmm1
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  __m128 v10; // [rsp+20h] [rbp-48h]
  hkVector4f v11; // [rsp+30h] [rbp-38h]
  __m128 v12; // [rsp+40h] [rbp-28h]
  __m128 v13; // [rsp+50h] [rbp-18h]
  __int64 v14; // [rsp+60h] [rbp-8h]

  v3.m_quad = (__m128)aTb->m_col2;
  v4 = 0i64;
  v10 = _mm_shuffle_ps(_mm_unpackhi_ps(cTb->m_col0.m_quad, cTb->m_col1.m_quad), cTb->m_col2.m_quad, 228);
  v5.m_quad = (__m128)aTb->m_col1;
  v6.m_quad = (__m128)aTb->m_col0;
  do
  {
    v7 = *(__m128 *)((char *)&v10 + v4);
    v4 -= 16i64;
    *(__m128 *)((char *)&v14 + v4) = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v5.m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v3.m_quad));
  }
  while ( v4 >= -32 );
  v8.m_quad = v12;
  this->m_col0 = (hkVector4f)v11.m_quad;
  v9.m_quad = v13;
  this->m_col1 = (hkVector4f)v8.m_quad;
  this->m_col2 = (hkVector4f)v9.m_quad;
}

// File Line: 80
// RVA: 0xC594E0
void __fastcall hkMatrix3f::setMulInverseMul(hkMatrix3f *this, hkRotationf *bTa, hkMatrix3f *bTc)
{
  hkVector4f v3; // xmm2
  signed __int64 v4; // r8
  signed __int64 v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm1

  v3.m_quad = (__m128)bTa->m_col2;
  v4 = (char *)bTc - (char *)this;
  v5 = 3i64;
  v6 = _mm_unpacklo_ps(bTa->m_col0.m_quad, bTa->m_col1.m_quad);
  v7 = _mm_shuffle_ps(_mm_unpackhi_ps(bTa->m_col0.m_quad, bTa->m_col1.m_quad), v3.m_quad, 228);
  v8 = _mm_movelh_ps(v6, v3.m_quad);
  v9 = _mm_shuffle_ps(_mm_movehl_ps(v8, v6), v3.m_quad, 212);
  do
  {
    v10 = *(__m128 *)((char *)&this->m_col0.m_quad + v4);
    this = (hkMatrix3f *)((char *)this + 16);
    this[-1].m_col2.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v9),
                                 _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v8)),
                               _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v7));
    --v5;
  }
  while ( v5 );
}

// File Line: 89
// RVA: 0xC59580
void __fastcall hkMatrix3f::setTransposeMul(hkMatrix3f *this, hkMatrix3f *a, hkMatrix3f *b)
{
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm7
  __m128 v5; // xmm14
  __m128 v6; // xmm13
  __m128 v7; // xmm12
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm11
  __m128 v12; // xmm9
  __m128 v13; // xmm0
  __m128 v14; // xmm10
  hkVector4f v15; // xmm14
  __m128 v16; // xmm1
  __m128 v17; // xmm12
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm2

  v3.m_quad = (__m128)a->m_col2;
  v4.m_quad = (__m128)a->m_col1;
  v5 = _mm_mul_ps(b->m_col0.m_quad, a->m_col0.m_quad);
  v6 = _mm_mul_ps(a->m_col2.m_quad, b->m_col0.m_quad);
  v7 = _mm_mul_ps(b->m_col1.m_quad, a->m_col0.m_quad);
  v8 = _mm_mul_ps(b->m_col2.m_quad, a->m_col0.m_quad);
  v9 = _mm_mul_ps(a->m_col1.m_quad, b->m_col0.m_quad);
  v10 = _mm_unpacklo_ps(v5, v9);
  v11 = _mm_movelh_ps(v10, v6);
  v12 = _mm_movehl_ps(v11, v10);
  v13 = _mm_mul_ps(b->m_col1.m_quad, v4.m_quad);
  v14 = _mm_mul_ps(b->m_col1.m_quad, v3.m_quad);
  v15.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v5, v9), v6, 228),
                 _mm_add_ps(v11, _mm_shuffle_ps(v12, v6, 212)));
  v16 = _mm_unpacklo_ps(v7, v13);
  v17 = _mm_unpackhi_ps(v7, v13);
  v18 = _mm_movelh_ps(v16, v14);
  v19 = _mm_mul_ps(b->m_col2.m_quad, v4.m_quad);
  v20 = _mm_mul_ps(b->m_col2.m_quad, v3.m_quad);
  v21 = _mm_movehl_ps(v18, v16);
  this->m_col0 = (hkVector4f)v15.m_quad;
  v22 = _mm_unpacklo_ps(v8, v19);
  v23 = _mm_movelh_ps(v22, v20);
  this->m_col1.m_quad = _mm_add_ps(_mm_shuffle_ps(v17, v14, 228), _mm_add_ps(v18, _mm_shuffle_ps(v21, v14, 212)));
  this->m_col2.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v8, v19), v20, 228),
                          _mm_add_ps(v23, _mm_shuffle_ps(_mm_movehl_ps(v23, v22), v20, 212)));
}

// File Line: 94
// RVA: 0xC597F0
void __fastcall hkMatrix3f::mul(hkMatrix3f *this, hkSimdFloat32 *scale)
{
  this->m_col0.m_quad = _mm_mul_ps(scale->m_real, this->m_col0.m_quad);
  this->m_col1.m_quad = _mm_mul_ps(this->m_col1.m_quad, scale->m_real);
  this->m_col2.m_quad = _mm_mul_ps(this->m_col2.m_quad, scale->m_real);
}

// File Line: 101
// RVA: 0xC59030
void __fastcall hkMatrix3f::setCrossSkewSymmetric(hkMatrix3f *this, hkVector4f *r)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm5
  __m128 v4; // xmm4
  __m128 v5; // xmm3

  v2 = r->m_quad;
  v3 = _mm_shuffle_ps(v2, v2, 85);
  v4 = _mm_shuffle_ps(r->m_quad, r->m_quad, 0);
  v5 = _mm_shuffle_ps(v2, v2, 170);
  this->m_col0.m_quad = _mm_movelh_ps(
                          _mm_unpacklo_ps((__m128)0i64, v5),
                          _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v3), (__m128)0i64));
  this->m_col1.m_quad = _mm_movelh_ps(
                          _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v5), (__m128)0i64),
                          _mm_unpacklo_ps(v4, (__m128)0i64));
  this->m_col2.m_quad = _mm_movelh_ps(
                          _mm_unpacklo_ps(v3, _mm_sub_ps((__m128)0i64, v4)),
                          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
}

// File Line: 119
// RVA: 0xC59550
void __fastcall hkMatrix3f::setMul(hkMatrix3f *this, hkSimdFloat32 *scale, hkMatrix3f *a)
{
  this->m_col0.m_quad = _mm_mul_ps(scale->m_real, a->m_col0.m_quad);
  this->m_col1.m_quad = _mm_mul_ps(a->m_col1.m_quad, scale->m_real);
  this->m_col2.m_quad = _mm_mul_ps(a->m_col2.m_quad, scale->m_real);
}

// File Line: 129
// RVA: 0xC596C0
void __fastcall hkMatrix3f::addMul(hkMatrix3f *this, hkSimdFloat32 *scale, hkMatrix3f *a)
{
  this->m_col0.m_quad = _mm_add_ps(_mm_mul_ps(scale->m_real, a->m_col0.m_quad), this->m_col0.m_quad);
  this->m_col1.m_quad = _mm_add_ps(_mm_mul_ps(a->m_col1.m_quad, scale->m_real), this->m_col1.m_quad);
  this->m_col2.m_quad = _mm_add_ps(_mm_mul_ps(a->m_col2.m_quad, scale->m_real), this->m_col2.m_quad);
}

// File Line: 134
// RVA: 0xC58EE0
bool __fastcall hkMatrix3f::isApproximatelyEqual(hkMatrix3f *this, hkMatrix3f *m, float zero)
{
  __m128 v3; // xmm1

  v3 = _mm_shuffle_ps((__m128)LODWORD(zero), (__m128)LODWORD(zero), 0);
  return (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col0.m_quad, m->m_col0.m_quad), 1u), 1u),
              v3)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col1.m_quad, m->m_col1.m_quad), 1u), 1u),
              v3)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col2.m_quad, m->m_col2.m_quad), 1u), 1u),
              v3)) & 7) == 7;
}

// File Line: 145
// RVA: 0xC58F60
bool __fastcall hkMatrix3f::isApproximatelyEqualSimd(hkMatrix3f *this, hkMatrix3f *m, hkSimdFloat32 *eps)
{
  __m128 v3; // xmm1

  v3 = eps->m_real;
  return (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col0.m_quad, m->m_col0.m_quad), 1u), 1u),
              eps->m_real)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col1.m_quad, m->m_col1.m_quad), 1u), 1u),
              v3)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col2.m_quad, m->m_col2.m_quad), 1u), 1u),
              v3)) & 7) == 7;
}

// File Line: 152
// RVA: 0xC58FD0
bool __fastcall hkMatrix3f::isSymmetric(hkMatrix3f *this, float epsilon)
{
  hkVector4f v2; // xmm3
  float v3; // xmm5_4
  __m128 v4; // xmm2
  hkVector4f v5; // xmm1
  hkMatrix3f m; // [rsp+20h] [rbp-38h]

  v2.m_quad = (__m128)this->m_col2;
  v3 = epsilon;
  v4 = _mm_unpacklo_ps(this->m_col0.m_quad, this->m_col1.m_quad);
  m.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(this->m_col0.m_quad, this->m_col1.m_quad), v2.m_quad, 228);
  v5.m_quad = _mm_movelh_ps(v4, v2.m_quad);
  m.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v5.m_quad, v4), v2.m_quad, 212);
  m.m_col0 = (hkVector4f)v5.m_quad;
  return hkMatrix3f::isApproximatelyEqual(this, &m, v3);
}

// File Line: 159
// RVA: 0xC590A0
hkResult *__fastcall hkMatrix3f::invert(hkMatrix3f *this, hkResult *result, float epsilon)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm5
  hkResult *v5; // rbx
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm7
  __m128 v10; // xmm9
  __m128 v11; // xmm7
  __m128 v12; // xmm9
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm8
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v20; // [rsp+80h] [rbp+18h]

  v20 = epsilon;
  v3.m_quad = (__m128)this->m_col2;
  v4.m_quad = (__m128)this->m_col1;
  v5 = result;
  v6 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 201);
  v7 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col0.m_quad, 201);
  v8 = _mm_shuffle_ps(this->m_col1.m_quad, v4.m_quad, 201);
  v9 = _mm_sub_ps(_mm_mul_ps(v6, v4.m_quad), _mm_mul_ps(this->m_col2.m_quad, v8));
  v10 = _mm_sub_ps(_mm_mul_ps(this->m_col0.m_quad, v8), _mm_mul_ps(v7, v4.m_quad));
  v11 = _mm_shuffle_ps(v9, v9, 201);
  v12 = _mm_shuffle_ps(v10, v10, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(v7, v3.m_quad), _mm_mul_ps(this->m_col0.m_quad, v6));
  v14 = _mm_mul_ps(this->m_col0.m_quad, v11);
  v7.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0);
  v15 = _mm_shuffle_ps(v13, v13, 201);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v16.m128_i32[0]) >> 1) <= (float)((float)(v7.m128_f32[0] * v7.m128_f32[0])
                                                                       * v7.m128_f32[0]) )
  {
    result->m_enum = 1;
  }
  else
  {
    v17 = _mm_rcp_ps(v16);
    v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17);
    this->m_col0.m_quad = _mm_mul_ps(v18, v11);
    this->m_col1.m_quad = _mm_mul_ps(v18, v15);
    this->m_col2.m_quad = _mm_mul_ps(v18, v12);
    hkMatrix3f::transpose(this);
    v5->m_enum = 0;
  }
  return v5;
}

// File Line: 182
// RVA: 0xC591D0
void __fastcall hkMatrix3f::invertSymmetric(hkMatrix3f *this)
{
  hkVector4f v1; // xmm3
  hkVector4f v2; // xmm5
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm9
  __m128 v7; // xmm7
  __m128 v8; // xmm9
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1

  v1.m_quad = (__m128)this->m_col2;
  v2.m_quad = (__m128)this->m_col1;
  v3 = _mm_shuffle_ps(v1.m_quad, v1.m_quad, 201);
  v4 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col0.m_quad, 201);
  v5 = _mm_shuffle_ps(this->m_col1.m_quad, v2.m_quad, 201);
  v6 = _mm_sub_ps(_mm_mul_ps(v3, v2.m_quad), _mm_mul_ps(this->m_col2.m_quad, v5));
  v7 = _mm_sub_ps(_mm_mul_ps(this->m_col0.m_quad, v5), _mm_mul_ps(v4, v2.m_quad));
  v8 = _mm_shuffle_ps(v6, v6, 201);
  v9 = _mm_sub_ps(_mm_mul_ps(v4, v1.m_quad), _mm_mul_ps(this->m_col0.m_quad, v3));
  v10 = _mm_mul_ps(this->m_col0.m_quad, v8);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_cmpltps(_mm_mul_ps(_mm_mul_ps(*(__m128 *)&epsilon, *(__m128 *)&epsilon), *(__m128 *)&epsilon), v11);
  v13 = _mm_or_ps(_mm_and_ps(v12, v11), _mm_andnot_ps(v12, query.m_quad));
  v14 = _mm_rcp_ps(v13);
  v15 = _mm_and_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v14)), v14), v12);
  this->m_col0.m_quad = _mm_mul_ps(v15, v8);
  this->m_col2.m_quad = _mm_mul_ps(v15, _mm_shuffle_ps(v7, v7, 201));
  this->m_col1.m_quad = _mm_mul_ps(v15, _mm_shuffle_ps(v9, v9, 201));
}

// File Line: 208
// RVA: 0xC59750
void __fastcall hkMatrix3f::add(hkMatrix3f *this, hkMatrix3f *a)
{
  this->m_col0.m_quad = _mm_add_ps(a->m_col0.m_quad, this->m_col0.m_quad);
  this->m_col1.m_quad = _mm_add_ps(a->m_col1.m_quad, this->m_col1.m_quad);
  this->m_col2.m_quad = _mm_add_ps(a->m_col2.m_quad, this->m_col2.m_quad);
}

// File Line: 215
// RVA: 0xC59780
void __fastcall hkMatrix3f::sub(hkMatrix3f *this, hkMatrix3f *a)
{
  this->m_col0.m_quad = _mm_sub_ps(this->m_col0.m_quad, a->m_col0.m_quad);
  this->m_col1.m_quad = _mm_sub_ps(this->m_col1.m_quad, a->m_col1.m_quad);
  this->m_col2.m_quad = _mm_sub_ps(this->m_col2.m_quad, a->m_col2.m_quad);
}

// File Line: 222
// RVA: 0xC597B0
void __fastcall hkMatrix3f::mul(hkMatrix3f *this, hkMatrix3f *a)
{
  hkMatrix3f *v2; // rbx
  hkVector4f v3; // xmm1
  hkVector4f v4; // xmm0
  hkMatrix3f v5; // [rsp+20h] [rbp-38h]

  v2 = this;
  hkMatrix3f::setMul(&v5, this, a);
  v3.m_quad = (__m128)v5.m_col1;
  v2->m_col0 = v5.m_col0;
  v4.m_quad = (__m128)v5.m_col2;
  v2->m_col1 = (hkVector4f)v3.m_quad;
  v2->m_col2 = (hkVector4f)v4.m_quad;
}

// File Line: 230
// RVA: 0xC59860
hkSimdFloat32 *__fastcall hkMatrix3f::getDeterminant(hkMatrix3f *this, hkSimdFloat32 *result)
{
  hkVector4f v2; // xmm2
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm2

  v2.m_quad = (__m128)this->m_col2;
  v3 = result;
  v4 = _mm_unpacklo_ps(this->m_col0.m_quad, this->m_col1.m_quad);
  v5 = _mm_shuffle_ps(_mm_unpackhi_ps(this->m_col0.m_quad, this->m_col1.m_quad), v2.m_quad, 228);
  v6 = _mm_movelh_ps(v4, v2.m_quad);
  v7 = _mm_shuffle_ps(_mm_movehl_ps(v6, v4), v2.m_quad, 212);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v5));
  v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v6);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                     _mm_shuffle_ps(v9, v9, 170));
  return v3;
}

// File Line: 251
// RVA: 0xC5A5F0
void __fastcall constructSchurMatrix(hkMatrix3f *M, int p, int q, SchurMatrix *S)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm1_4

  S->q = q;
  S->p = p;
  v4 = M->m_col0.m_quad.m128_f32[p + 4i64 * q];
  if ( v4 == 0.0 )
  {
    *(_QWORD *)&S->c = 1065353216i64;
  }
  else
  {
    v5 = (float)(M->m_col0.m_quad.m128_f32[5 * q] - M->m_col0.m_quad.m128_f32[5 * p]) / (float)(v4 * 2.0);
    v6 = fsqrt((float)(v5 * v5) + 1.0);
    if ( v5 < 0.0 )
      v7 = 1.0 / (float)(v5 - v6);
    else
      v7 = 1.0 / (float)(v6 + v5);
    v8 = fsqrt((float)(v7 * v7) + 1.0);
    S->c = 1.0 / v8;
    S->s = (float)(1.0 / v8) * v7;
  }
}

// File Line: 272
// RVA: 0xC5A6B0
void __fastcall constructSchurMatrixUnchecked(hkMatrix3f *M, int p, int q, SchurMatrix *S)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm1_4

  S->q = q;
  S->p = p;
  v4 = (float)(M->m_col0.m_quad.m128_f32[5 * q] - M->m_col0.m_quad.m128_f32[5 * p])
     / (float)(M->m_col0.m_quad.m128_f32[p + 4i64 * q] * 2.0);
  v5 = fsqrt((float)(v4 * v4) + 1.0);
  if ( v4 < 0.0 )
    v6 = 1.0 / (float)(v4 - v5);
  else
    v6 = 1.0 / (float)(v5 + v4);
  v7 = fsqrt((float)(v6 * v6) + 1.0);
  S->c = 1.0 / v7;
  S->s = (float)(1.0 / v7) * v6;
}

// File Line: 285
// RVA: 0xC5A760
hkSimdFloat32 *__fastcall frobeniusNormSqr(hkSimdFloat32 *result, hkMatrix3f *M)
{
  hkSimdFloat32 *v2; // rax
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm4

  v2 = result;
  v3 = _mm_mul_ps(M->m_col0.m_quad, M->m_col0.m_quad);
  v4 = _mm_mul_ps(M->m_col1.m_quad, M->m_col1.m_quad);
  v5 = _mm_mul_ps(M->m_col2.m_quad, M->m_col2.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)),
                         _mm_shuffle_ps(v3, v3, 170)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                         _mm_shuffle_ps(v4, v4, 170))),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)),
                       _mm_shuffle_ps(v5, v5, 170)));
  return v2;
}

// File Line: 290
// RVA: 0xC592E0
hkSimdFloat32 *__fastcall hkMatrix3f::frobeniusNormSqr(hkMatrix3f *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rax
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm4

  v2 = result;
  v3 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v4 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v5 = _mm_mul_ps(this->m_col2.m_quad, this->m_col2.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)),
                         _mm_shuffle_ps(v3, v3, 170)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                         _mm_shuffle_ps(v4, v4, 170))),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)),
                       _mm_shuffle_ps(v5, v5, 170)));
  return v2;
}

// File Line: 296
// RVA: 0xC5A7D0
hkSimdFloat32 *__fastcall offDiagNormSqr(hkSimdFloat32 *result, hkMatrix3f *M)
{
  hkVector4f v2; // xmm1
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm1

  v2.m_quad = (__m128)M->m_col2;
  v3 = result;
  v4 = _mm_shuffle_ps(M->m_col1.m_quad, M->m_col1.m_quad, 0);
  v5 = _mm_shuffle_ps(v2.m_quad, v2.m_quad, 0);
  v6 = _mm_shuffle_ps(v2.m_quad, v2.m_quad, 85);
  result->m_real = _mm_mul_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v5, v5), _mm_mul_ps(v4, v4)), _mm_mul_ps(v6, v6)),
                     (__m128)xmmword_141A710D0);
  return v3;
}

// File Line: 305
// RVA: 0xC5A810
float __fastcall findLargestOffDiagEntry(hkMatrix3f *M, int *p, int *q)
{
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm2_4
  float result; // xmm0_4

  *p = 0;
  *q = 1;
  LODWORD(v3) = (unsigned int)(2 * M->m_col1.m_quad.m128_i32[0]) >> 1;
  LODWORD(v4) = (unsigned int)(2 * M->m_col2.m_quad.m128_i32[0]) >> 1;
  LODWORD(v5) = (unsigned int)(2 * M->m_col2.m_quad.m128_i32[1]) >> 1;
  if ( v4 > v3 )
  {
    *p = 0;
    v3 = v4;
    *q = 2;
  }
  if ( v5 <= v3 )
    return v3;
  *p = 1;
  result = v5;
  *q = 2;
  return result;
}

// File Line: 324
// RVA: 0xC5A8A0
void __fastcall constructJacobiRotation_0_(hkMatrix3f *J, SchurMatrix *S)
{
  J->m_col0 = (hkVector4f)transform.m_quad;
  J->m_col1 = (hkVector4f)direction.m_quad;
  J->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  J->m_col0.m_quad.m128_i32[5 * S->p] = LODWORD(S->c);
  J->m_col0.m_quad.m128_i32[S->p + 4i64 * S->q] = LODWORD(S->s);
  J->m_col0.m_quad.m128_i32[S->q + 4i64 * S->p] = LODWORD(S->s) ^ _xmm[0];
  J->m_col0.m_quad.m128_i32[5 * S->q] = LODWORD(S->c);
}

// File Line: 343
// RVA: 0xC598D0
hkResult *__usercall hkMatrix3f::diagonalizeSymmetric@<rax>(hkMatrix3f *this@<rcx>, hkResult *result@<rdx>, hkRotationf *eigenVec@<r8>, hkVector4f *eigenVal@<r9>, int a5@<edi>, int maxIter, float epsilon)
{
  __m128 v7; // xmm5
  float v8; // xmm4_4
  int v9; // ebx
  hkVector4f *v10; // r15
  __m128 v11; // xmm6
  hkRotationf *v12; // r14
  hkResult *v13; // rsi
  __m128 v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  hkVector4f v17; // xmm3
  __m128 v18; // xmm3
  float v19; // xmm10_4
  float v20; // xmm0_4
  float v21; // xmm10_4
  float v22; // xmm2_4
  signed __int64 v23; // rcx
  signed int v24; // er8
  signed __int64 v25; // rdx
  signed int v26; // er10
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  __int64 v34; // rcx
  signed __int64 v35; // rdx
  signed __int64 v36; // r8
  signed __int64 v37; // r9
  signed __int64 v38; // rax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  __m128 v42; // xmm5
  hkResult *v43; // rax
  hkMatrix3f bTc; // [rsp+20h] [rbp-D0h]
  hkMatrix3f a; // [rsp+50h] [rbp-A0h]
  __m128 v46; // [rsp+80h] [rbp-70h]
  __m128 v47; // [rsp+90h] [rbp-60h]
  float vars0; // [rsp+120h] [rbp+30h]
  unsigned int v49; // [rsp+148h] [rbp+58h]

  v7 = this->m_col2.m_quad;
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps((__m128)v49, (__m128)v49, 0);
  v9 = 0;
  v10 = eigenVal;
  v11 = this->m_col0.m_quad;
  v12 = eigenVec;
  v13 = result;
  v14 = this->m_col1.m_quad;
  eigenVec->m_col0 = (hkVector4f)transform.m_quad;
  eigenVec->m_col1 = (hkVector4f)direction.m_quad;
  eigenVec->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v15 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v16 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v17.m_quad = (__m128)this->m_col2;
  bTc.m_col0.m_quad = v11;
  bTc.m_col1.m_quad = v14;
  bTc.m_col2.m_quad = v7;
  v18 = _mm_mul_ps(v17.m_quad, v17.m_quad);
  v19 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170)))
      + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)));
  v16.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v14, v14, 0);
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(v7, v7, 85);
  v15.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v7, v7, 0);
  v21 = (float)(v19
              + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))))
      * (float)(v8 * v8);
  v22 = (float)((float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16.m128_f32[0] * v16.m128_f32[0]))
              + (float)(v20 * v20))
      * 2.0;
  if ( v22 > v21 )
  {
    do
    {
      if ( v9 >= a5 )
        break;
      v23 = 1i64;
      v24 = 0;
      v25 = 0i64;
      v26 = 1;
      vars0 = bTc.m_col2.m_quad.m128_f32[1];
      LODWORD(v27) = (unsigned int)(2 * bTc.m_col1.m_quad.m128_i32[0]) >> 1;
      if ( COERCE_FLOAT((unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[0]) >> 1) > v27 )
      {
        v23 = 2i64;
        LODWORD(v27) = (unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[0]) >> 1;
        v26 = 2;
      }
      if ( COERCE_FLOAT((unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[1]) >> 1) > v27 )
      {
        v25 = 1i64;
        v23 = 2i64;
        v24 = 1;
        v26 = 2;
      }
      v28 = bTc.m_col0.m_quad.m128_f32[v25 + 4 * v23];
      if ( v28 == 0.0 )
      {
        v32 = *(float *)&FLOAT_1_0;
        v33 = 0.0;
      }
      else
      {
        v29 = (float)(bTc.m_col0.m_quad.m128_f32[5 * v23] - bTc.m_col0.m_quad.m128_f32[5 * v25]) / (float)(v28 * 2.0);
        vars0 = (float)(v29 * v29) + 1.0;
        v30 = fsqrt(vars0);
        v31 = v29 < 0.0 ? 1.0 / (float)(v29 - v30) : 1.0 / (float)(v30 + v29);
        vars0 = (float)(v31 * v31) + 1.0;
        v32 = 1.0 / fsqrt(vars0);
        v33 = v31 * v32;
      }
      v34 = v24;
      v35 = v26 + 4i64 * v24;
      v36 = v24 + 4i64 * v26;
      v37 = 5 * v34;
      v38 = 5i64 * v26;
      a.m_col0 = (hkVector4f)transform.m_quad;
      a.m_col1 = (hkVector4f)direction.m_quad;
      a.m_col0.m_quad.m128_f32[v37] = v32;
      a.m_col0.m_quad.m128_f32[v36] = v33;
      a.m_col2 = (hkVector4f)transform.m_quad;
      v46 = direction.m_quad;
      v47 = stru_141A71280.m_quad;
      a.m_col2.m_quad.m128_f32[v37] = v32;
      a.m_col2.m_quad.m128_i32[v36] = LODWORD(v33) ^ _xmm[0];
      a.m_col0.m_quad.m128_i32[v35] = LODWORD(v33) ^ _xmm[0];
      a.m_col2.m_quad.m128_f32[v35] = v33;
      a.m_col0.m_quad.m128_f32[v38] = v32;
      a.m_col2.m_quad.m128_f32[v38] = v32;
      hkMatrix3f::mul(&bTc, &a);
      hkMatrix3f::setMul(&bTc, (hkMatrix3f *)((char *)&a + 32), &bTc);
      hkMatrix3f::mul((hkMatrix3f *)&v12->m_col0, &a);
      ++v9;
      v7 = bTc.m_col2.m_quad;
      v14 = bTc.m_col1.m_quad;
      LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 0);
      LODWORD(v40) = (unsigned __int128)_mm_shuffle_ps(bTc.m_col1.m_quad, bTc.m_col1.m_quad, 0);
      LODWORD(v41) = (unsigned __int128)_mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 85);
      v22 = (float)((float)((float)(v39 * v39) + (float)(v40 * v40)) + (float)(v41 * v41)) * 2.0;
    }
    while ( v22 > v21 );
    v11 = bTc.m_col0.m_quad;
  }
  v42 = _mm_shuffle_ps(v7, v7, 170);
  v43 = v13;
  v10->m_quad = _mm_movelh_ps(
                  _mm_unpacklo_ps(_mm_shuffle_ps(v11, v11, 0), _mm_shuffle_ps(v14, v14, 85)),
                  _mm_unpacklo_ps(v42, v42));
  v13->m_enum = v22 > v21;
  return v43;
}

// File Line: 389
// RVA: 0xC59CD0
hkResult *__usercall hkMatrix3f::diagonalizeSymmetricWarmStart@<rax>(hkMatrix3f *this@<rcx>, hkResult *result@<rdx>, hkMatrix3f *eigenVec@<r8>, hkVector4f *eigenVal@<r9>, int a5@<edi>, __int64 a6@<r14>, int maxIter, float epsilon)
{
  hkVector4f v8; // xmm1
  hkMatrix3f *v9; // rbx
  hkVector4f *v10; // r15
  hkMatrix3f *v11; // r14
  hkResult *v12; // rsi
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  float v18; // xmm4_4
  __m128 v19; // xmm3
  __m128 v20; // xmm11
  int v21; // ebx
  __m128 v22; // xmm3
  float v23; // xmm9_4
  float v24; // xmm12_4
  float v25; // xmm12_4
  float i; // xmm9_4
  signed __int64 v27; // rcx
  signed int v28; // er8
  signed __int64 v29; // rdx
  signed int v30; // er9
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm9_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  __m128 v41; // xmm10
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm5
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  hkResult *v54; // rax
  hkMatrix3f aTb; // [rsp+20h] [rbp-D0h]
  char bTc[80]; // [rsp+50h] [rbp-A0h]
  float vars0; // [rsp+140h] [rbp+50h]
  __int64 v58; // [rsp+168h] [rbp+78h]

  v8.m_quad = (__m128)this->m_col1;
  v58 = a6;
  v9 = this;
  v10 = eigenVal;
  v11 = eigenVec;
  v12 = result;
  *(hkVector4f *)&bTc[32] = this->m_col0;
  *(hkVector4f *)&bTc[64] = this->m_col2;
  aTb.m_col0 = eigenVec->m_col0;
  v13.m_quad = (__m128)eigenVec->m_col2;
  *(hkVector4f *)&bTc[48] = (hkVector4f)v8.m_quad;
  v14.m_quad = (__m128)eigenVec->m_col1;
  aTb.m_col2 = (hkVector4f)v13.m_quad;
  aTb.m_col1 = (hkVector4f)v14.m_quad;
  hkMatrix3f::transpose(&aTb);
  hkMatrix3f::setMul((hkMatrix3f *)bTc, &aTb, (hkMatrix3f *)&bTc[32]);
  hkMatrix3f::mul((hkMatrix3f *)bTc, v11);
  v15 = *(__m128 *)&bTc[32];
  v16 = _mm_mul_ps(v9->m_col1.m_quad, v9->m_col1.m_quad);
  v17 = _mm_mul_ps(v9->m_col0.m_quad, v9->m_col0.m_quad);
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps((__m128)(unsigned int)v58, (__m128)(unsigned int)v58, 0);
  v19 = v9->m_col2.m_quad;
  v20 = *(__m128 *)&bTc[16];
  v21 = 0;
  v22 = _mm_mul_ps(v19, v19);
  LODWORD(v23) = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[32], *(__m128 *)&bTc[32], 0);
  v24 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170)))
      + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170)));
  v16.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[16], *(__m128 *)&bTc[16], 0);
  v13.m_quad.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[32], *(__m128 *)&bTc[32], 85);
  v25 = (float)(v24
              + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170))))
      * (float)(v18 * v18);
  for ( i = (float)((float)((float)(v23 * v23) + (float)(v16.m128_f32[0] * v16.m128_f32[0]))
                  + (float)(v13.m_quad.m128_f32[0] * v13.m_quad.m128_f32[0]))
          * 2.0; i >= v25; i = (float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40)) * 2.0 )
  {
    if ( v21 >= a5 )
      break;
    v27 = 1i64;
    v28 = 0;
    v29 = 0i64;
    v30 = 1;
    vars0 = *(float *)&bTc[36];
    LODWORD(v31) = (unsigned int)(2 * *(_DWORD *)&bTc[16]) >> 1;
    if ( COERCE_FLOAT((unsigned int)(2 * *(_DWORD *)&bTc[32]) >> 1) > v31 )
    {
      v27 = 2i64;
      LODWORD(v31) = (unsigned int)(2 * *(_DWORD *)&bTc[32]) >> 1;
      v30 = 2;
    }
    if ( COERCE_FLOAT((unsigned int)(2 * *(_DWORD *)&bTc[36]) >> 1) > v31 )
    {
      v29 = 1i64;
      v27 = 2i64;
      v28 = 1;
      v30 = 2;
    }
    v32 = *(float *)&bTc[4 * (v29 + 4 * v27)];
    if ( v32 == 0.0 )
    {
      v36 = *(float *)&FLOAT_1_0;
      v37 = 0.0;
    }
    else
    {
      v33 = (float)(*(float *)&bTc[20 * v27] - *(float *)&bTc[20 * v29]) / (float)(v32 * 2.0);
      vars0 = (float)(v33 * v33) + 1.0;
      v34 = fsqrt(vars0);
      v35 = v33 < 0.0 ? 1.0 / (float)(v33 - v34) : 1.0 / (float)(v34 + v33);
      vars0 = (float)(v35 * v35) + 1.0;
      v36 = 1.0 / fsqrt(vars0);
      v37 = v35 * v36;
    }
    aTb.m_col0 = (hkVector4f)transform.m_quad;
    aTb.m_col1 = (hkVector4f)direction.m_quad;
    aTb.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    aTb.m_col0.m_quad.m128_f32[5 * v28] = v36;
    aTb.m_col0.m_quad.m128_f32[v28 + 4i64 * v30] = v37;
    aTb.m_col0.m_quad.m128_i32[v30 + 4i64 * v28] = LODWORD(v37) ^ _xmm[0];
    aTb.m_col0.m_quad.m128_f32[5 * v30] = v36;
    *(hkMatrix3f *)&bTc[32] = aTb;
    hkMatrix3f::transpose((hkMatrix3f *)&bTc[32]);
    hkMatrix3f::mul((hkMatrix3f *)bTc, &aTb);
    hkMatrix3f::setMul((hkMatrix3f *)bTc, (hkMatrix3f *)&bTc[32], (hkMatrix3f *)bTc);
    hkMatrix3f::mul(v11, &aTb);
    ++v21;
    v15 = *(__m128 *)&bTc[32];
    v20 = *(__m128 *)&bTc[16];
    LODWORD(v38) = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[32], *(__m128 *)&bTc[32], 0);
    LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[16], *(__m128 *)&bTc[16], 0);
    LODWORD(v40) = (unsigned __int128)_mm_shuffle_ps(*(__m128 *)&bTc[32], *(__m128 *)&bTc[32], 85);
  }
  v41 = _mm_shuffle_ps(v15, v15, 170);
  v42 = _mm_mul_ps(v11->m_col0.m_quad, v11->m_col0.m_quad);
  v43 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v44 = _mm_rsqrt_ps(v43);
  v11->m_col0.m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v43, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                             _mm_mul_ps(v44, *(__m128 *)_xmm))),
                         v11->m_col0.m_quad);
  v45 = v11->m_col1.m_quad;
  v46 = _mm_mul_ps(v45, v45);
  v47 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)), _mm_shuffle_ps(v46, v46, 170));
  v48 = _mm_rsqrt_ps(v47);
  v11->m_col1.m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v47, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                             _mm_mul_ps(v48, *(__m128 *)_xmm))),
                         v45);
  v49 = v11->m_col2.m_quad;
  v50 = _mm_mul_ps(v49, v49);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v52 = _mm_rsqrt_ps(v51);
  v53 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_shuffle_ps(*(__m128 *)bTc, *(__m128 *)bTc, 0), _mm_shuffle_ps(v20, v20, 85)),
          _mm_unpacklo_ps(v41, v41));
  v11->m_col2.m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v51, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                             _mm_mul_ps(v52, *(__m128 *)_xmm))),
                         v49);
  *v10 = (hkVector4f)v53;
  v54 = v12;
  v12->m_enum = i > v25;
  return v54;
}

// File Line: 450
// RVA: 0xC5A230
void __fastcall hkMatrix3f::diagonalizeSymmetricApproximation(hkMatrix3f *this, hkRotationf *eigenVec, hkVector4f *eigenVal, int maxIter)
{
  __m128 v4; // xmm4
  hkVector4f v5; // xmm5
  int v6; // ebx
  int v7; // esi
  hkVector4f *v8; // r14
  hkRotationf *v9; // rdi
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  hkVector4f v13; // xmm3
  __m128 v14; // xmm3
  float v15; // xmm7_4
  signed int v16; // er10
  signed int v17; // er9
  signed __int64 v18; // rdx
  signed __int64 v19; // r8
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  signed __int64 v25; // rdx
  signed __int64 v26; // r8
  signed __int64 v27; // r9
  signed __int64 v28; // rax
  float v29; // xmm5_4
  unsigned int v30; // xmm0_4
  __m128 v31; // xmm5
  hkMatrix3f bTc; // [rsp+20h] [rbp-81h]
  __m128 v33; // [rsp+58h] [rbp-49h]
  hkMatrix3f aTb; // [rsp+68h] [rbp-39h]

  v4 = this->m_col0.m_quad;
  v5.m_quad = (__m128)this->m_col2;
  v6 = 0;
  v7 = maxIter;
  v8 = eigenVal;
  v9 = eigenVec;
  v10 = this->m_col1.m_quad;
  eigenVec->m_col0 = (hkVector4f)transform.m_quad;
  bTc.m_col0.m_quad = v4;
  eigenVec->m_col1 = (hkVector4f)direction.m_quad;
  bTc.m_col1.m_quad = v10;
  eigenVec->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v11 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v12 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v13.m_quad = (__m128)this->m_col2;
  *(hkVector4f *)((char *)&bTc.m_col0 + 8) = (hkVector4f)v5.m_quad;
  v14 = _mm_mul_ps(v13.m_quad, v13.m_quad);
  v15 = (float)((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                              + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170)))
                      + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                              + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170))))
              + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170))))
      * 1.4210855e-14;
  if ( maxIter > 0 )
  {
    do
    {
      v16 = 1;
      v17 = 0;
      v18 = 0i64;
      v19 = 1i64;
      LODWORD(v20) = (unsigned int)(2 * bTc.m_col1.m_quad.m128_i32[0]) >> 1;
      LODWORD(v21) = (unsigned int)(2 * bTc.m_col0.m_quad.m128_i32[3]) >> 1;
      if ( COERCE_FLOAT((unsigned int)(2 * bTc.m_col0.m_quad.m128_i32[2]) >> 1) > v20 )
      {
        v16 = 2;
        LODWORD(v20) = (unsigned int)(2 * bTc.m_col0.m_quad.m128_i32[2]) >> 1;
        v19 = 2i64;
      }
      if ( v21 <= v20 )
      {
        v21 = v20;
      }
      else
      {
        v18 = 1i64;
        v16 = 2;
        v17 = 1;
        v19 = 2i64;
      }
      if ( (float)(v21 * v21) < v15 )
        break;
      v22 = (float)(bTc.m_col0.m_quad.m128_f32[5 * v19] - bTc.m_col0.m_quad.m128_f32[5 * v18])
          / (float)(bTc.m_col0.m_quad.m128_f32[v18 + 4 * v19] * 2.0);
      v23 = fsqrt((float)(v22 * v22) + 1.0);
      v24 = v22 < 0.0 ? 1.0 / (float)(v22 - v23) : 1.0 / (float)(v23 + v22);
      v25 = v16 + 4i64 * v17;
      v26 = v17 + 4i64 * v16;
      v27 = 5i64 * v17;
      v28 = 5i64 * v16;
      *(hkVector4f *)((char *)&bTc.m_col2 + 8) = (hkVector4f)direction.m_quad;
      aTb.m_col1 = (hkVector4f)direction.m_quad;
      v29 = 1.0 / fsqrt((float)(v24 * v24) + 1.0);
      v33 = stru_141A71280.m_quad;
      aTb.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      *(hkVector4f *)((char *)&bTc.m_col1 + 8) = (hkVector4f)transform.m_quad;
      aTb.m_col0 = (hkVector4f)transform.m_quad;
      bTc.m_col1.m_quad.m128_f32[v27 + 2] = v29;
      aTb.m_col0.m_quad.m128_f32[v27] = v29;
      bTc.m_col1.m_quad.m128_f32[v26 + 2] = v29 * v24;
      v30 = COERCE_UNSIGNED_INT(v29 * v24) ^ _xmm[0];
      aTb.m_col0.m_quad.m128_i32[v26] = v30;
      aTb.m_col0.m_quad.m128_f32[v25] = v29 * v24;
      bTc.m_col1.m_quad.m128_i32[v25 + 2] = v30;
      bTc.m_col1.m_quad.m128_f32[v28 + 2] = v29;
      aTb.m_col0.m_quad.m128_f32[v28] = v29;
      hkMatrix3f::mul(&bTc, (hkMatrix3f *)((char *)&bTc + 24));
      hkMatrix3f::setMul(&bTc, &aTb, &bTc);
      hkMatrix3f::mul((hkMatrix3f *)&v9->m_col0, (hkMatrix3f *)((char *)&bTc + 24));
      ++v6;
    }
    while ( v6 < v7 );
    v5.m_quad = *(__m128 *)((char *)&bTc.m_col0 + 8);
    v10 = bTc.m_col1.m_quad;
    v4 = bTc.m_col0.m_quad;
  }
  v31 = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170);
  v8->m_quad = _mm_movelh_ps(
                 _mm_unpacklo_ps(_mm_shuffle_ps(v4, v4, 0), _mm_shuffle_ps(v10, v10, 85)),
                 _mm_unpacklo_ps(v31, v31));
}

