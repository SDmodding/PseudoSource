// File Line: 14
// RVA: 0xC59820
bool __fastcall hkMatrix3f::isOk(hkMatrix3f *this)
{
  return (_mm_movemask_ps(_mm_cmpunord_ps(this->m_col0.m_quad, this->m_col0.m_quad)) & 7) == 0
      && (_mm_movemask_ps(_mm_cmpunord_ps(this->m_col1.m_quad, this->m_col1.m_quad)) & 7) == 0
      && (_mm_movemask_ps(_mm_cmpunord_ps(this->m_col2.m_quad, this->m_col2.m_quad)) & 7) == 0;
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
  __int64 v6; // rdx
  hkVector4f *p_m_col2; // rax
  signed __int64 v8; // rcx
  __m128 m_quad; // xmm1

  v3.m_quad = (__m128)aTb->m_col0;
  v4.m_quad = (__m128)aTb->m_col1;
  v5.m_quad = (__m128)aTb->m_col2;
  v6 = 2i64;
  p_m_col2 = &bTc->m_col2;
  v8 = (char *)THIS - (char *)bTc;
  do
  {
    m_quad = p_m_col2->m_quad;
    --p_m_col2;
    --v6;
    *(__m128 *)((char *)&p_m_col2[1].m_quad + v8) = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v4.m_quad),
                                                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v3.m_quad)),
                                                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v5.m_quad));
  }
  while ( v6 >= 0 );
}

// File Line: 49
// RVA: 0xC5A5E0
// attributes: thunk
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
  __int64 v6; // rdx
  hkVector4f *p_m_col2; // rax
  signed __int64 v8; // rcx
  __m128 m_quad; // xmm1

  v3.m_quad = (__m128)aTb->m_col0;
  v4.m_quad = (__m128)aTb->m_col1;
  v5.m_quad = (__m128)aTb->m_col2;
  v6 = 2i64;
  p_m_col2 = &bTc->m_col2;
  v8 = (char *)this - (char *)bTc;
  do
  {
    m_quad = p_m_col2->m_quad;
    --p_m_col2;
    --v6;
    *(__m128 *)((char *)&p_m_col2[1].m_quad + v8) = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v4.m_quad),
                                                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v3.m_quad)),
                                                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v5.m_quad));
  }
  while ( v6 >= 0 );
}

// File Line: 68
// RVA: 0xC59700
void __fastcall hkMatrix3f::changeBasis(hkMatrix3f *this, hkRotationf *r)
{
  hkMatrix3f bTc; // [rsp+20h] [rbp-38h] BYREF

  hkMatrix3f::setMulInverse(&bTc, this, r);
  hkMatrix3f::setMul(this, r, &bTc);
}

// File Line: 75
// RVA: 0xC59430
void __fastcall hkMatrix3f::setMulInverse(hkMatrix3f *this, hkMatrix3f *aTb, hkRotationf *cTb)
{
  hkVector4f v3; // xmm5
  __int64 v4; // rax
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm3
  __m128 v7; // xmm1
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  _QWORD v10[9]; // [rsp+20h] [rbp-48h]

  v3.m_quad = (__m128)aTb->m_col2;
  v4 = 0i64;
  *(__m128 *)v10 = _mm_shuffle_ps(_mm_unpackhi_ps(cTb->m_col0.m_quad, cTb->m_col1.m_quad), cTb->m_col2.m_quad, 228);
  v5.m_quad = (__m128)aTb->m_col1;
  v6.m_quad = (__m128)aTb->m_col0;
  do
  {
    v7 = *(__m128 *)&v10[v4];
    v4 -= 2i64;
    *(__m128 *)&v10[v4 + 8] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v5.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v3.m_quad));
  }
  while ( v4 >= -4 );
  v8.m_quad = *(__m128 *)&v10[4];
  this->m_col0 = *(hkVector4f *)&v10[2];
  v9.m_quad = *(__m128 *)&v10[6];
  this->m_col1 = (hkVector4f)v8.m_quad;
  this->m_col2 = (hkVector4f)v9.m_quad;
}

// File Line: 80
// RVA: 0xC594E0
void __fastcall hkMatrix3f::setMulInverseMul(hkMatrix3f *this, hkRotationf *bTa, hkMatrix3f *bTc)
{
  hkVector4f v3; // xmm2
  signed __int64 v4; // r8
  __int64 v5; // rax
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
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm11
  __m128 v11; // xmm9
  __m128 v12; // xmm0
  __m128 v13; // xmm10
  hkVector4f v14; // xmm14
  __m128 v15; // xmm1
  __m128 v16; // xmm12
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm2

  v3.m_quad = (__m128)a->m_col2;
  v4.m_quad = (__m128)a->m_col1;
  v5 = _mm_mul_ps(b->m_col0.m_quad, a->m_col0.m_quad);
  v6 = _mm_mul_ps(v3.m_quad, b->m_col0.m_quad);
  v7 = _mm_mul_ps(b->m_col1.m_quad, a->m_col0.m_quad);
  v8 = _mm_mul_ps(v4.m_quad, b->m_col0.m_quad);
  v9 = _mm_unpacklo_ps(v5, v8);
  v10 = _mm_movelh_ps(v9, v6);
  v11 = _mm_movehl_ps(v10, v9);
  v12 = _mm_mul_ps(b->m_col1.m_quad, v4.m_quad);
  v13 = _mm_mul_ps(b->m_col1.m_quad, v3.m_quad);
  v14.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v5, v8), v6, 228),
                 _mm_add_ps(v10, _mm_shuffle_ps(v11, v6, 212)));
  v15 = _mm_unpacklo_ps(v7, v12);
  v16 = _mm_unpackhi_ps(v7, v12);
  v17 = _mm_movelh_ps(v15, v13);
  v18 = _mm_mul_ps(b->m_col2.m_quad, v4.m_quad);
  v19 = _mm_mul_ps(b->m_col2.m_quad, v3.m_quad);
  v20 = _mm_movehl_ps(v17, v15);
  v21 = _mm_mul_ps(b->m_col2.m_quad, a->m_col0.m_quad);
  this->m_col0 = (hkVector4f)v14.m_quad;
  v22 = _mm_unpackhi_ps(v21, v18);
  v23 = _mm_unpacklo_ps(v21, v18);
  v24 = _mm_movelh_ps(v23, v19);
  this->m_col1.m_quad = _mm_add_ps(_mm_shuffle_ps(v16, v13, 228), _mm_add_ps(v17, _mm_shuffle_ps(v20, v13, 212)));
  this->m_col2.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(v22, v19, 228),
                          _mm_add_ps(v24, _mm_shuffle_ps(_mm_movehl_ps(v24, v23), v19, 212)));
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
  __m128 m_quad; // xmm3
  __m128 v3; // xmm5
  __m128 v4; // xmm4
  __m128 v5; // xmm3

  m_quad = r->m_quad;
  v3 = _mm_shuffle_ps(m_quad, m_quad, 85);
  v4 = _mm_shuffle_ps(r->m_quad, r->m_quad, 0);
  v5 = _mm_shuffle_ps(m_quad, m_quad, 170);
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
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col0.m_quad, m->m_col0.m_quad), 1u), 1u),
              v3)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col1.m_quad, m->m_col1.m_quad), 1u), 1u),
              v3)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col2.m_quad, m->m_col2.m_quad), 1u), 1u),
              v3)) & 7) == 7;
}

// File Line: 145
// RVA: 0xC58F60
bool __fastcall hkMatrix3f::isApproximatelyEqualSimd(hkMatrix3f *this, hkMatrix3f *m, hkSimdFloat32 *eps)
{
  __m128 m_real; // xmm1

  m_real = eps->m_real;
  return (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col0.m_quad, m->m_col0.m_quad), 1u), 1u),
              eps->m_real)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col1.m_quad, m->m_col1.m_quad), 1u), 1u),
              m_real)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(this->m_col2.m_quad, m->m_col2.m_quad), 1u), 1u),
              m_real)) & 7) == 7;
}

// File Line: 152
// RVA: 0xC58FD0
bool __fastcall hkMatrix3f::isSymmetric(hkMatrix3f *this, float epsilon)
{
  hkVector4f v2; // xmm3
  __m128 v4; // xmm2
  hkVector4f v5; // xmm1
  hkMatrix3f m; // [rsp+20h] [rbp-38h] BYREF

  v2.m_quad = (__m128)this->m_col2;
  v4 = _mm_unpacklo_ps(this->m_col0.m_quad, this->m_col1.m_quad);
  m.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(this->m_col0.m_quad, this->m_col1.m_quad), v2.m_quad, 228);
  v5.m_quad = _mm_movelh_ps(v4, v2.m_quad);
  m.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v5.m_quad, v4), v2.m_quad, 212);
  m.m_col0 = (hkVector4f)v5.m_quad;
  return hkMatrix3f::isApproximatelyEqual(this, &m, epsilon);
}

// File Line: 159
// RVA: 0xC590A0
hkResult *__fastcall hkMatrix3f::invert(hkMatrix3f *this, hkResult *result, float epsilon)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm8
  __m128 v8; // xmm4
  __m128 v9; // xmm7
  __m128 v10; // xmm9
  __m128 v11; // xmm7
  __m128 v12; // xmm9
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  float v15; // xmm2_4
  __m128 v16; // xmm8
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm1

  v3.m_quad = (__m128)this->m_col2;
  v4.m_quad = (__m128)this->m_col1;
  v6 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 201);
  v7 = _mm_shuffle_ps(this->m_col0.m_quad, this->m_col0.m_quad, 201);
  v8 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 201);
  v9 = _mm_sub_ps(_mm_mul_ps(v6, v4.m_quad), _mm_mul_ps(v3.m_quad, v8));
  v10 = _mm_sub_ps(_mm_mul_ps(this->m_col0.m_quad, v8), _mm_mul_ps(v7, v4.m_quad));
  v11 = _mm_shuffle_ps(v9, v9, 201);
  v12 = _mm_shuffle_ps(v10, v10, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(v7, v3.m_quad), _mm_mul_ps(this->m_col0.m_quad, v6));
  v14 = _mm_mul_ps(this->m_col0.m_quad, v11);
  v15 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0).m128_f32[0];
  v16 = _mm_shuffle_ps(v13, v13, 201);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v17.m128_i32[0]) >> 1) <= (float)((float)(v15 * v15) * v15) )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v18 = _mm_rcp_ps(v17);
    v19 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18);
    this->m_col0.m_quad = _mm_mul_ps(v19, v11);
    this->m_col1.m_quad = _mm_mul_ps(v19, v16);
    this->m_col2.m_quad = _mm_mul_ps(v19, v12);
    hkMatrix3f::transpose(this);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 182
// RVA: 0xC591D0
void __fastcall hkMatrix3f::invertSymmetric(hkMatrix3f *this)
{
  hkVector4f v1; // xmm3
  hkVector4f v2; // xmm5
  __m128 v3; // xmm1
  __m128 v4; // xmm8
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
  v5 = _mm_shuffle_ps(v2.m_quad, v2.m_quad, 201);
  v6 = _mm_sub_ps(_mm_mul_ps(v3, v2.m_quad), _mm_mul_ps(v1.m_quad, v5));
  v7 = _mm_sub_ps(_mm_mul_ps(this->m_col0.m_quad, v5), _mm_mul_ps(v4, v2.m_quad));
  v8 = _mm_shuffle_ps(v6, v6, 201);
  v9 = _mm_sub_ps(_mm_mul_ps(v4, v1.m_quad), _mm_mul_ps(this->m_col0.m_quad, v3));
  v10 = _mm_mul_ps(this->m_col0.m_quad, v8);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_cmplt_ps(_mm_mul_ps(_mm_mul_ps(*(__m128 *)&epsilon, *(__m128 *)&epsilon), *(__m128 *)&epsilon), v11);
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
  hkVector4f v3; // xmm1
  hkVector4f v4; // xmm0
  hkMatrix3f v5; // [rsp+20h] [rbp-38h] BYREF

  hkMatrix3f::setMul(&v5, this, a);
  v3.m_quad = (__m128)v5.m_col1;
  this->m_col0 = v5.m_col0;
  v4.m_quad = (__m128)v5.m_col2;
  this->m_col1 = (hkVector4f)v3.m_quad;
  this->m_col2 = (hkVector4f)v4.m_quad;
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
  v4 = M->m_col0.m_quad.m128_f32[4 * q + p];
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
     / (float)(M->m_col0.m_quad.m128_f32[4 * q + p] * 2.0);
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
  J->m_col0.m_quad.m128_i32[4 * S->q + S->p] = LODWORD(S->s);
  J->m_col0.m_quad.m128_i32[4 * S->p + S->q] = LODWORD(S->s) ^ _xmm[0];
  J->m_col0.m_quad.m128_i32[5 * S->q] = LODWORD(S->c);
}

// File Line: 343
// RVA: 0xC598D0
hkResult *__fastcall hkMatrix3f::diagonalizeSymmetric(
        hkMatrix3f *this,
        hkResult *result,
        hkRotationf *eigenVec,
        hkVector4f *eigenVal,
        int maxIter,
        float epsilon)
{
  int v6; // edi
  __m128 m_quad; // xmm5
  float v8; // xmm4_4
  int v9; // ebx
  __m128 v11; // xmm6
  __m128 v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  hkVector4f v17; // xmm3
  __m128 v18; // xmm3
  float v19; // xmm10_4
  float v20; // xmm0_4
  float v21; // xmm10_4
  float v22; // xmm2_4
  __int64 v23; // rcx
  int v24; // r8d
  __int64 v25; // rdx
  int v26; // r10d
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  __int64 v34; // rcx
  __int64 v35; // rdx
  __int64 v36; // r8
  __int64 v37; // r9
  __int64 v38; // rax
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  __m128 v42; // xmm5
  hkResult *v43; // rax
  hkMatrix3f bTc; // [rsp+20h] [rbp-D0h] BYREF
  hkMatrix3f a; // [rsp+50h] [rbp-A0h] BYREF
  __m128 v46; // [rsp+80h] [rbp-70h]
  __m128 v47; // [rsp+90h] [rbp-60h]
  float vars0; // [rsp+120h] [rbp+30h]
  unsigned int v49; // [rsp+148h] [rbp+58h]

  m_quad = this->m_col2.m_quad;
  v8 = _mm_shuffle_ps((__m128)v49, (__m128)v49, 0).m128_f32[0];
  v9 = 0;
  v11 = this->m_col0.m_quad;
  v14 = this->m_col1.m_quad;
  eigenVec->m_col0 = (hkVector4f)transform.m_quad;
  eigenVec->m_col1 = (hkVector4f)direction.m_quad;
  eigenVec->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v15 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v16 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v17.m_quad = (__m128)this->m_col2;
  bTc.m_col0.m_quad = v11;
  bTc.m_col1.m_quad = v14;
  bTc.m_col2.m_quad = m_quad;
  v18 = _mm_mul_ps(v17.m_quad, v17.m_quad);
  v19 = (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
              + _mm_shuffle_ps(v16, v16, 170).m128_f32[0])
      + (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
              + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]);
  v16.m128_f32[0] = _mm_shuffle_ps(v14, v14, 0).m128_f32[0];
  v20 = _mm_shuffle_ps(m_quad, m_quad, 85).m128_f32[0];
  v15.m128_f32[0] = _mm_shuffle_ps(m_quad, m_quad, 0).m128_f32[0];
  v21 = (float)(v19
              + (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                      + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]))
      * (float)(v8 * v8);
  v22 = (float)((float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16.m128_f32[0] * v16.m128_f32[0]))
              + (float)(v20 * v20))
      * 2.0;
  if ( v22 > v21 )
  {
    do
    {
      if ( v9 >= v6 )
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
      v28 = bTc.m_col0.m_quad.m128_f32[4 * v23 + v25];
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
      hkMatrix3f::setMul(&bTc, (hkMatrix3f *)&a.m_col2, &bTc);
      hkMatrix3f::mul(eigenVec, &a);
      ++v9;
      m_quad = bTc.m_col2.m_quad;
      v14 = bTc.m_col1.m_quad;
      v39 = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 0).m128_f32[0];
      v40 = _mm_shuffle_ps(bTc.m_col1.m_quad, bTc.m_col1.m_quad, 0).m128_f32[0];
      v41 = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 85).m128_f32[0];
      v22 = (float)((float)((float)(v39 * v39) + (float)(v40 * v40)) + (float)(v41 * v41)) * 2.0;
    }
    while ( v22 > v21 );
    v11 = bTc.m_col0.m_quad;
  }
  v42 = _mm_shuffle_ps(m_quad, m_quad, 170);
  v43 = result;
  eigenVal->m_quad = _mm_movelh_ps(
                       _mm_unpacklo_ps(_mm_shuffle_ps(v11, v11, 0), _mm_shuffle_ps(v14, v14, 85)),
                       _mm_unpacklo_ps(v42, v42));
  result->m_enum = v22 > v21;
  return v43;
}

// File Line: 389
// RVA: 0xC59CD0
hkResult *__fastcall hkMatrix3f::diagonalizeSymmetricWarmStart(
        hkMatrix3f *this,
        hkResult *result,
        hkMatrix3f *eigenVec,
        hkVector4f *eigenVal,
        int maxIter,
        float epsilon)
{
  int v6; // edi
  unsigned int v7; // r14d
  hkVector4f v8; // xmm1
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  float v18; // xmm4_4
  hkVector4f v19; // xmm3
  hkVector4f v20; // xmm11
  int v21; // ebx
  __m128 v22; // xmm3
  float v23; // xmm9_4
  float v24; // xmm12_4
  float v25; // xmm12_4
  float i; // xmm9_4
  __int64 v27; // rcx
  int v28; // r8d
  __int64 v29; // rdx
  int v30; // r9d
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
  hkVector4f v45; // xmm5
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  hkVector4f v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  hkVector4f v53; // xmm0
  hkResult *v54; // rax
  hkMatrix3f aTb; // [rsp+20h] [rbp-D0h] BYREF
  hkMatrix3f bTc; // [rsp+50h] [rbp-A0h] BYREF
  hkVector4f v57; // [rsp+80h] [rbp-70h]
  hkVector4f v58; // [rsp+90h] [rbp-60h]
  float vars0; // [rsp+140h] [rbp+50h]
  unsigned int v60; // [rsp+168h] [rbp+78h]

  v8.m_quad = (__m128)this->m_col1;
  v60 = v7;
  bTc.m_col2 = this->m_col0;
  v58.m_quad = (__m128)this->m_col2;
  aTb.m_col0 = eigenVec->m_col0;
  v13.m_quad = (__m128)eigenVec->m_col2;
  v57.m_quad = v8.m_quad;
  v14.m_quad = (__m128)eigenVec->m_col1;
  aTb.m_col2 = (hkVector4f)v13.m_quad;
  aTb.m_col1 = (hkVector4f)v14.m_quad;
  hkMatrix3f::transpose(&aTb);
  hkMatrix3f::setMul(&bTc, &aTb, (hkMatrix3f *)&bTc.m_col2);
  hkMatrix3f::mul(&bTc, eigenVec);
  v15.m_quad = (__m128)bTc.m_col2;
  v16 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v17 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v18 = _mm_shuffle_ps((__m128)v60, (__m128)v60, 0).m128_f32[0];
  v19.m_quad = (__m128)this->m_col2;
  v20.m_quad = (__m128)bTc.m_col1;
  v21 = 0;
  v22 = _mm_mul_ps(v19.m_quad, v19.m_quad);
  v23 = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 0).m128_f32[0];
  v24 = (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
              + _mm_shuffle_ps(v16, v16, 170).m128_f32[0])
      + (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
              + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]);
  v16.m128_f32[0] = _mm_shuffle_ps(bTc.m_col1.m_quad, bTc.m_col1.m_quad, 0).m128_f32[0];
  v13.m_quad.m128_f32[0] = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 85).m128_f32[0];
  v25 = (float)(v24
              + (float)((float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
                      + _mm_shuffle_ps(v22, v22, 170).m128_f32[0]))
      * (float)(v18 * v18);
  for ( i = (float)((float)((float)(v23 * v23) + (float)(v16.m128_f32[0] * v16.m128_f32[0]))
                  + (float)(v13.m_quad.m128_f32[0] * v13.m_quad.m128_f32[0]))
          * 2.0; i >= v25; i = (float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40)) * 2.0 )
  {
    if ( v21 >= v6 )
      break;
    v27 = 1i64;
    v28 = 0;
    v29 = 0i64;
    v30 = 1;
    vars0 = bTc.m_col2.m_quad.m128_f32[1];
    LODWORD(v31) = (unsigned int)(2 * bTc.m_col1.m_quad.m128_i32[0]) >> 1;
    if ( COERCE_FLOAT((unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[0]) >> 1) > v31 )
    {
      v27 = 2i64;
      LODWORD(v31) = (unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[0]) >> 1;
      v30 = 2;
    }
    if ( COERCE_FLOAT((unsigned int)(2 * bTc.m_col2.m_quad.m128_i32[1]) >> 1) > v31 )
    {
      v29 = 1i64;
      v27 = 2i64;
      v28 = 1;
      v30 = 2;
    }
    v32 = bTc.m_col0.m_quad.m128_f32[4 * v27 + v29];
    if ( v32 == 0.0 )
    {
      v36 = *(float *)&FLOAT_1_0;
      v37 = 0.0;
    }
    else
    {
      v33 = (float)(bTc.m_col0.m_quad.m128_f32[5 * v27] - bTc.m_col0.m_quad.m128_f32[5 * v29]) / (float)(v32 * 2.0);
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
    aTb.m_col0.m_quad.m128_f32[4 * v30 + v28] = v37;
    aTb.m_col0.m_quad.m128_i32[4 * v28 + v30] = LODWORD(v37) ^ _xmm[0];
    aTb.m_col0.m_quad.m128_f32[5 * v30] = v36;
    bTc.m_col2 = aTb.m_col0;
    v57.m_quad = (__m128)aTb.m_col1;
    v58.m_quad = (__m128)aTb.m_col2;
    hkMatrix3f::transpose((hkMatrix3f *)&bTc.m_col2);
    hkMatrix3f::mul(&bTc, &aTb);
    hkMatrix3f::setMul(&bTc, (hkMatrix3f *)&bTc.m_col2, &bTc);
    hkMatrix3f::mul(eigenVec, &aTb);
    ++v21;
    v15.m_quad = (__m128)bTc.m_col2;
    v20.m_quad = (__m128)bTc.m_col1;
    v38 = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 0).m128_f32[0];
    v39 = _mm_shuffle_ps(bTc.m_col1.m_quad, bTc.m_col1.m_quad, 0).m128_f32[0];
    v40 = _mm_shuffle_ps(bTc.m_col2.m_quad, bTc.m_col2.m_quad, 85).m128_f32[0];
  }
  v41 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 170);
  v42 = _mm_mul_ps(eigenVec->m_col0.m_quad, eigenVec->m_col0.m_quad);
  v43 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v44 = _mm_rsqrt_ps(v43);
  eigenVec->m_col0.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v43, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                                  _mm_mul_ps(v44, *(__m128 *)_xmm))),
                              eigenVec->m_col0.m_quad);
  v45.m_quad = (__m128)eigenVec->m_col1;
  v46 = _mm_mul_ps(v45.m_quad, v45.m_quad);
  v47 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)), _mm_shuffle_ps(v46, v46, 170));
  v48 = _mm_rsqrt_ps(v47);
  eigenVec->m_col1.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v47, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                  _mm_mul_ps(v48, *(__m128 *)_xmm))),
                              v45.m_quad);
  v49.m_quad = (__m128)eigenVec->m_col2;
  v50 = _mm_mul_ps(v49.m_quad, v49.m_quad);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v52 = _mm_rsqrt_ps(v51);
  v53.m_quad = _mm_movelh_ps(
                 _mm_unpacklo_ps(
                   _mm_shuffle_ps(bTc.m_col0.m_quad, bTc.m_col0.m_quad, 0),
                   _mm_shuffle_ps(v20.m_quad, v20.m_quad, 85)),
                 _mm_unpacklo_ps(v41, v41));
  eigenVec->m_col2.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v51, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                                  _mm_mul_ps(v52, *(__m128 *)_xmm))),
                              v49.m_quad);
  *eigenVal = (hkVector4f)v53.m_quad;
  v54 = result;
  result->m_enum = i > v25;
  return v54;
}

// File Line: 450
// RVA: 0xC5A230
void __fastcall hkMatrix3f::diagonalizeSymmetricApproximation(
        hkMatrix3f *this,
        hkRotationf *eigenVec,
        hkVector4f *eigenVal,
        int maxIter)
{
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  int v6; // ebx
  hkVector4f v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  hkVector4f v13; // xmm3
  __m128 v14; // xmm3
  float v15; // xmm7_4
  int v16; // r10d
  int v17; // r9d
  __int64 v18; // rdx
  __int64 v19; // r8
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  __int64 v25; // rdx
  __int64 v26; // r8
  __int64 v27; // r9
  __int64 v28; // rax
  float v29; // xmm5_4
  unsigned int v30; // xmm0_4
  __m128 v31; // xmm5
  char bTc[56]; // [rsp+20h] [rbp-81h] BYREF
  __m128 m_quad; // [rsp+58h] [rbp-49h]
  hkMatrix3f aTb; // [rsp+68h] [rbp-39h] BYREF

  v4.m_quad = (__m128)this->m_col0;
  v5.m_quad = (__m128)this->m_col2;
  v6 = 0;
  v10.m_quad = (__m128)this->m_col1;
  eigenVec->m_col0 = (hkVector4f)transform.m_quad;
  *(hkVector4f *)bTc = (hkVector4f)v4.m_quad;
  eigenVec->m_col1 = (hkVector4f)direction.m_quad;
  *(hkVector4f *)&bTc[16] = (hkVector4f)v10.m_quad;
  eigenVec->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v11 = _mm_mul_ps(this->m_col0.m_quad, this->m_col0.m_quad);
  v12 = _mm_mul_ps(this->m_col1.m_quad, this->m_col1.m_quad);
  v13.m_quad = (__m128)this->m_col2;
  *(hkVector4f *)&bTc[8] = (hkVector4f)v5.m_quad;
  v14 = _mm_mul_ps(v13.m_quad, v13.m_quad);
  v15 = (float)((float)((float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                              + _mm_shuffle_ps(v11, v11, 170).m128_f32[0])
                      + (float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                              + _mm_shuffle_ps(v12, v12, 170).m128_f32[0]))
              + (float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
                      + _mm_shuffle_ps(v14, v14, 170).m128_f32[0]))
      * 1.4210855e-14;
  if ( maxIter > 0 )
  {
    do
    {
      v16 = 1;
      v17 = 0;
      v18 = 0i64;
      v19 = 1i64;
      LODWORD(v20) = (unsigned int)(2 * *(_DWORD *)&bTc[16]) >> 1;
      LODWORD(v21) = (unsigned int)(2 * *(_DWORD *)&bTc[12]) >> 1;
      if ( COERCE_FLOAT((unsigned int)(2 * *(_DWORD *)&bTc[8]) >> 1) > v20 )
      {
        v16 = 2;
        LODWORD(v20) = (unsigned int)(2 * *(_DWORD *)&bTc[8]) >> 1;
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
      v22 = (float)(*(float *)&bTc[20 * v19] - *(float *)&bTc[20 * v18])
          / (float)(*(float *)&bTc[16 * v19 + 4 * v18] * 2.0);
      v23 = fsqrt((float)(v22 * v22) + 1.0);
      v24 = v22 < 0.0 ? 1.0 / (float)(v22 - v23) : 1.0 / (float)(v23 + v22);
      v25 = v16 + 4i64 * v17;
      v26 = v17 + 4i64 * v16;
      v27 = 5i64 * v17;
      v28 = 5i64 * v16;
      *(hkVector4f *)&bTc[40] = (hkVector4f)direction.m_quad;
      aTb.m_col1 = (hkVector4f)direction.m_quad;
      v29 = 1.0 / fsqrt((float)(v24 * v24) + 1.0);
      m_quad = stru_141A71280.m_quad;
      aTb.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      *(hkVector4f *)&bTc[24] = (hkVector4f)transform.m_quad;
      aTb.m_col0 = (hkVector4f)transform.m_quad;
      *(float *)&bTc[4 * v27 + 24] = v29;
      aTb.m_col0.m_quad.m128_f32[v27] = v29;
      *(float *)&bTc[4 * v26 + 24] = v29 * v24;
      v30 = COERCE_UNSIGNED_INT(v29 * v24) ^ _xmm[0];
      aTb.m_col0.m_quad.m128_i32[v26] = v30;
      aTb.m_col0.m_quad.m128_f32[v25] = v29 * v24;
      *(_DWORD *)&bTc[4 * v25 + 24] = v30;
      *(float *)&bTc[4 * v28 + 24] = v29;
      aTb.m_col0.m_quad.m128_f32[v28] = v29;
      hkMatrix3f::mul((hkMatrix3f *)bTc, (hkMatrix3f *)&bTc[24]);
      hkMatrix3f::setMul((hkMatrix3f *)bTc, &aTb, (hkMatrix3f *)bTc);
      hkMatrix3f::mul(eigenVec, (hkMatrix3f *)&bTc[24]);
      ++v6;
    }
    while ( v6 < maxIter );
    v5.m_quad = *(__m128 *)&bTc[8];
    v10.m_quad = *(__m128 *)&bTc[16];
    v4.m_quad = *(__m128 *)bTc;
  }
  v31 = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170);
  eigenVal->m_quad = _mm_movelh_ps(
                       _mm_unpacklo_ps(
                         _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                         _mm_shuffle_ps(v10.m_quad, v10.m_quad, 85)),
                       _mm_unpacklo_ps(v31, v31));
}

