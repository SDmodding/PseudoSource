// File Line: 14
// RVA: 0xC8BCE0
bool __fastcall hkMatrix3d::isOk(hkMatrix3d *this)
{
  BOOL v1; // eax
  bool v2; // r8
  BOOL v3; // eax
  bool v4; // dl
  BOOL v5; // eax

  v1 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col0.m_quad.xy, (__m128d)0i64))
    && (_mm_movemask_pd(_mm_cmpord_pd(this->m_col0.m_quad.zw, (__m128d)0i64)) & 1) != 0;
  v2 = v1;
  v3 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col1.m_quad.xy, (__m128d)0i64))
    && (_mm_movemask_pd(_mm_cmpord_pd(this->m_col1.m_quad.zw, (__m128d)0i64)) & 1) != 0;
  v4 = v3;
  v5 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col2.m_quad.xy, (__m128d)0i64))
    && (_mm_movemask_pd(_mm_cmpord_pd(this->m_col2.m_quad.zw, (__m128d)0i64)) & 1) != 0;
  return v2 && v4 && v5;
}

// File Line: 37
// RVA: 0xC8B330
void __fastcall hkMatrix3d::transpose(hkMatrix3d *this)
{
  __m128d xy; // xmm1
  __m128d zw; // xmm3
  __m128d v3; // xmm0
  __m128d v4; // xmm0
  __m128d v5; // xmm3
  __m128d v6; // xmm1

  xy = this->m_col1.m_quad.xy;
  zw = this->m_col0.m_quad.zw;
  v3 = this->m_col0.m_quad.xy;
  this->m_col0.m_quad.xy = _mm_unpacklo_pd(this->m_col0.m_quad.xy, xy);
  v4 = _mm_unpackhi_pd(v3, xy);
  v5 = _mm_unpacklo_pd(zw, this->m_col1.m_quad.zw);
  v6 = this->m_col2.m_quad.xy;
  this->m_col1.m_quad.xy = v4;
  this->m_col2.m_quad.zw = _mm_unpacklo_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  this->m_col2.m_quad.xy = v5;
  this->m_col0.m_quad.zw = _mm_unpacklo_pd(v6, (__m128d)0i64);
  this->m_col1.m_quad.zw = _mm_unpackhi_pd(v6, (__m128d)0i64);
}

// File Line: 42
// RVA: 0xC8D190
void __fastcall hkMatrix3d_setMulMat3Mat3(hkMatrix3d *THIS, hkMatrix3d *aTb, hkMatrix3d *bTc)
{
  __m128d xy; // xmm7
  __m128d zw; // xmm8
  __m128d v5; // xmm9
  hkVector4d *p_m_col2; // rax
  signed __int64 v7; // rcx
  __m128d v8; // xmm10
  __m128d v9; // xmm11
  __m128d v10; // xmm12
  __int64 v11; // rdx
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm4
  __m128d v15; // xmm6
  __m128d v16; // xmm5

  xy = aTb->m_col0.m_quad.xy;
  zw = aTb->m_col0.m_quad.zw;
  v5 = aTb->m_col1.m_quad.xy;
  p_m_col2 = &bTc->m_col2;
  v7 = (char *)THIS - (char *)bTc;
  v8 = aTb->m_col1.m_quad.zw;
  v9 = aTb->m_col2.m_quad.xy;
  v10 = aTb->m_col2.m_quad.zw;
  v11 = 2i64;
  do
  {
    v12 = p_m_col2->m_quad.xy;
    v13 = p_m_col2->m_quad.zw;
    --p_m_col2;
    --v11;
    v14 = _mm_unpacklo_pd(v13, v13);
    v15 = _mm_unpacklo_pd(v12, v12);
    v16 = _mm_unpackhi_pd(v12, v12);
    *(__m128d *)((char *)&p_m_col2[1].m_quad.xy + v7) = _mm_add_pd(
                                                          _mm_add_pd(_mm_mul_pd(v5, v16), _mm_mul_pd(xy, v15)),
                                                          _mm_mul_pd(v9, v14));
    *(__m128d *)((char *)&p_m_col2[1].m_quad.zw + v7) = _mm_add_pd(
                                                          _mm_add_pd(_mm_mul_pd(v8, v16), _mm_mul_pd(zw, v15)),
                                                          _mm_mul_pd(v10, v14));
  }
  while ( v11 >= 0 );
}

// File Line: 49
// RVA: 0xC8D2A0
// attributes: thunk
void __fastcall hkMatrix3d_invertSymmetric(hkMatrix3d *thisMatrix)
{
  hkMatrix3d::invertSymmetric(thisMatrix);
}

// File Line: 56
// RVA: 0xC8B3A0
void __fastcall hkMatrix3d::setTranspose(hkMatrix3d *this, hkMatrix3d *s)
{
  __m128d v2; // xmm6
  __m128d xy; // xmm0
  __m128d v4; // xmm2
  __m128d v5; // xmm5

  v2 = _mm_unpacklo_pd(s->m_col0.m_quad.zw, s->m_col1.m_quad.zw);
  xy = s->m_col2.m_quad.xy;
  v4 = _mm_unpackhi_pd(s->m_col0.m_quad.xy, s->m_col1.m_quad.xy);
  v5 = _mm_unpacklo_pd(s->m_col2.m_quad.zw, (__m128d)0i64);
  this->m_col0.m_quad.xy = _mm_unpacklo_pd(s->m_col0.m_quad.xy, s->m_col1.m_quad.xy);
  this->m_col2.m_quad.xy = v2;
  this->m_col0.m_quad.zw = _mm_unpacklo_pd(xy, (__m128d)0i64);
  this->m_col1.m_quad.xy = v4;
  this->m_col2.m_quad.zw = v5;
  this->m_col1.m_quad.zw = _mm_unpackhi_pd(xy, (__m128d)0i64);
}

// File Line: 62
// RVA: 0xC8B420
void __fastcall hkMatrix3d::setMul(hkMatrix3d *this, hkMatrix3d *aTb, hkMatrix3d *bTc)
{
  __m128d xy; // xmm7
  __m128d zw; // xmm8
  __m128d v5; // xmm9
  hkVector4d *p_m_col2; // rax
  signed __int64 v7; // rcx
  __m128d v8; // xmm10
  __m128d v9; // xmm11
  __m128d v10; // xmm12
  __int64 v11; // rdx
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm4
  __m128d v15; // xmm6
  __m128d v16; // xmm5

  xy = aTb->m_col0.m_quad.xy;
  zw = aTb->m_col0.m_quad.zw;
  v5 = aTb->m_col1.m_quad.xy;
  p_m_col2 = &bTc->m_col2;
  v7 = (char *)this - (char *)bTc;
  v8 = aTb->m_col1.m_quad.zw;
  v9 = aTb->m_col2.m_quad.xy;
  v10 = aTb->m_col2.m_quad.zw;
  v11 = 2i64;
  do
  {
    v12 = p_m_col2->m_quad.xy;
    v13 = p_m_col2->m_quad.zw;
    --p_m_col2;
    --v11;
    v14 = _mm_unpacklo_pd(v13, v13);
    v15 = _mm_unpacklo_pd(v12, v12);
    v16 = _mm_unpackhi_pd(v12, v12);
    *(__m128d *)((char *)&p_m_col2[1].m_quad.xy + v7) = _mm_add_pd(
                                                          _mm_add_pd(_mm_mul_pd(v5, v16), _mm_mul_pd(xy, v15)),
                                                          _mm_mul_pd(v9, v14));
    *(__m128d *)((char *)&p_m_col2[1].m_quad.zw + v7) = _mm_add_pd(
                                                          _mm_add_pd(_mm_mul_pd(v8, v16), _mm_mul_pd(zw, v15)),
                                                          _mm_mul_pd(v10, v14));
  }
  while ( v11 >= 0 );
}

// File Line: 68
// RVA: 0xC8BAF0
void __fastcall hkMatrix3d::changeBasis(hkMatrix3d *this, hkRotationd *r)
{
  hkMatrix3d bTc; // [rsp+40h] [rbp+0h] BYREF

  hkMatrix3d::setMulInverse((hkMatrix3d *)((unsigned __int64)&bTc & 0xFFFFFFFFFFFFFFE0ui64), this, r);
  hkMatrix3d::setMul(this, r, (hkMatrix3d *)((unsigned __int64)&bTc & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 75
// RVA: 0xC8B530
void __fastcall hkMatrix3d::setMulInverse(hkMatrix3d *this, hkMatrix3d *aTb, hkRotationd *cTb)
{
  unsigned __int64 v3; // rbp
  __int64 v4; // rax
  __m128d v5; // xmm6
  __m128d xy; // xmm7
  __m128d zw; // xmm8
  __m128d v8; // xmm5
  __m128d v9; // xmm9
  __m128d v10; // xmm10
  __m128d v11; // xmm11
  __m128d v12; // xmm12
  __m128d v13; // xmm0
  __m128d v14; // xmm2
  __m128d v15; // xmm4
  __m128d v16; // xmm5
  __m128d v17; // xmm5
  __m128d v18; // xmm6
  __m128d v19; // xmm4
  __m128d v20; // xmm1
  __m128d v21; // xmm0
  __m128d v22; // xmm1
  __m128d v23; // xmm0
  __m128d v24; // xmm1
  __int128 v25; // [rsp+20h] [rbp+0h] BYREF

  v3 = (unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = -16i64;
  v5 = _mm_unpacklo_pd(cTb->m_col0.m_quad.zw, cTb->m_col1.m_quad.zw);
  xy = aTb->m_col0.m_quad.xy;
  zw = aTb->m_col0.m_quad.zw;
  v8 = _mm_unpacklo_pd(cTb->m_col2.m_quad.zw, (__m128d)0i64);
  v9 = aTb->m_col1.m_quad.xy;
  v10 = aTb->m_col1.m_quad.zw;
  v11 = aTb->m_col2.m_quad.xy;
  v12 = aTb->m_col2.m_quad.zw;
  v13 = cTb->m_col2.m_quad.xy;
  v14 = _mm_unpackhi_pd(cTb->m_col0.m_quad.xy, cTb->m_col1.m_quad.xy);
  *(__m128d *)v3 = _mm_unpacklo_pd(cTb->m_col0.m_quad.xy, cTb->m_col1.m_quad.xy);
  *(__m128d *)(v3 + 48) = _mm_unpackhi_pd(v13, (__m128d)0i64);
  *(__m128d *)(v3 + 64) = v5;
  *(__m128d *)(v3 + 32) = v14;
  *(__m128d *)(v3 + 16) = _mm_unpacklo_pd(v13, (__m128d)0i64);
  *(__m128d *)(v3 + 80) = v8;
  do
  {
    v15 = *(__m128d *)(v3 + 80 + v4);
    v16 = *(__m128d *)(v3 + 96 + v4);
    v4 -= 32i64;
    v17 = _mm_unpacklo_pd(v16, v16);
    v18 = _mm_unpacklo_pd(v15, v15);
    v19 = _mm_unpackhi_pd(v15, v15);
    *(__m128d *)(v3 + 208 + v4) = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v9, v19), _mm_mul_pd(xy, v18)), _mm_mul_pd(v11, v17));
    *(__m128d *)(v3 + 224 + v4) = _mm_add_pd(
                                    _mm_add_pd(_mm_mul_pd(v10, v19), _mm_mul_pd(zw, v18)),
                                    _mm_mul_pd(v12, v17));
  }
  while ( v4 >= -80 );
  v20 = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
  this->m_col0.m_quad.xy = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
  v21 = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80);
  this->m_col0.m_quad.zw = v20;
  v22 = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90);
  this->m_col1.m_quad.xy = v21;
  v23 = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0);
  this->m_col1.m_quad.zw = v22;
  v24 = *(__m128d *)(((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0);
  this->m_col2.m_quad.xy = v23;
  this->m_col2.m_quad.zw = v24;
}

// File Line: 80
// RVA: 0xC8B6D0
void __fastcall hkMatrix3d::setMulInverseMul(hkMatrix3d *this, hkRotationd *bTa, hkMatrix3d *bTc)
{
  signed __int64 v3; // r8
  __int64 v4; // rax
  __m128d v5; // xmm11
  __m128d xy; // xmm10
  __m128d v7; // xmm6
  __m128d v8; // xmm7
  __m128d v9; // xmm8
  __m128d v10; // xmm10
  __m128d v11; // xmm9
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm0
  __m128d v15; // xmm3
  __m128d v16; // xmm5

  v3 = (char *)bTc - (char *)this;
  v4 = 3i64;
  v5 = _mm_unpacklo_pd(bTa->m_col0.m_quad.zw, bTa->m_col1.m_quad.zw);
  xy = bTa->m_col2.m_quad.xy;
  v7 = _mm_unpacklo_pd(bTa->m_col0.m_quad.xy, bTa->m_col1.m_quad.xy);
  v8 = _mm_unpackhi_pd(xy, (__m128d)0i64);
  v9 = _mm_unpackhi_pd(bTa->m_col0.m_quad.xy, bTa->m_col1.m_quad.xy);
  v10 = _mm_unpacklo_pd(xy, (__m128d)0i64);
  v11 = _mm_unpacklo_pd(bTa->m_col2.m_quad.zw, (__m128d)0i64);
  do
  {
    v12 = *(__m128d *)((char *)&this->m_col0.m_quad.xy + v3);
    v13 = *(__m128d *)((char *)&this->m_col0.m_quad.zw + v3);
    this = (hkMatrix3d *)((char *)this + 32);
    v14 = _mm_unpacklo_pd(v13, v13);
    v15 = _mm_unpacklo_pd(v12, v12);
    v16 = _mm_unpackhi_pd(v12, v12);
    this[-1].m_col2.m_quad.xy = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v16, v9), _mm_mul_pd(v15, v7)), _mm_mul_pd(v14, v5));
    this[-1].m_col2.m_quad.zw = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v16, v8), _mm_mul_pd(v15, v10)), _mm_mul_pd(v14, v11));
    --v4;
  }
  while ( v4 );
}

// File Line: 89
// RVA: 0xC8B850
void __fastcall hkMatrix3d::setTransposeMul(hkMatrix3d *this, hkMatrix3d *a, hkMatrix3d *b)
{
  __m128d zw; // xmm0
  __m128d xy; // xmm8
  __m128d v5; // xmm13
  __m128d v6; // xmm12
  __m128d v7; // xmm11
  __m128d v8; // xmm14
  __m128d v9; // xmm4
  __m128d v10; // xmm2
  __m128d v11; // xmm14
  __m128d v12; // xmm5
  __m128d v13; // xmm3
  __m128d v14; // xmm0
  __m128d v15; // xmm6
  __m128d v16; // xmm12
  __m128d v17; // xmm5
  __m128d v18; // xmm10
  __m128d v19; // xmm0
  __m128d v20; // xmm15
  __m128d v21; // xmm8
  __m128d v22; // xmm0

  zw = b->m_col0.m_quad.zw;
  xy = a->m_col1.m_quad.xy;
  v5 = a->m_col2.m_quad.xy;
  v6 = a->m_col0.m_quad.zw;
  v7 = _mm_mul_pd(v5, b->m_col0.m_quad.xy);
  v8 = _mm_mul_pd(a->m_col0.m_quad.xy, b->m_col0.m_quad.xy);
  v9 = _mm_mul_pd(a->m_col2.m_quad.zw, zw);
  v10 = _mm_mul_pd(xy, b->m_col0.m_quad.xy);
  v11 = _mm_add_pd(
          _mm_add_pd(_mm_unpacklo_pd(v8, v10), _mm_unpackhi_pd(v8, v10)),
          _mm_unpacklo_pd(_mm_mul_pd(zw, v6), _mm_mul_pd(a->m_col1.m_quad.zw, zw)));
  v12 = _mm_mul_pd(b->m_col1.m_quad.xy, a->m_col0.m_quad.xy);
  v13 = _mm_unpacklo_pd(_mm_mul_pd(a->m_col2.m_quad.zw, b->m_col1.m_quad.zw), (__m128d)0i64);
  v14 = _mm_mul_pd(b->m_col1.m_quad.xy, xy);
  v15 = _mm_mul_pd(b->m_col1.m_quad.xy, v5);
  v16 = _mm_unpacklo_pd(_mm_mul_pd(v6, b->m_col2.m_quad.zw), _mm_mul_pd(a->m_col1.m_quad.zw, b->m_col2.m_quad.zw));
  v17 = _mm_add_pd(
          _mm_add_pd(_mm_unpacklo_pd(v12, v14), _mm_unpackhi_pd(v12, v14)),
          _mm_unpacklo_pd(
            _mm_mul_pd(a->m_col0.m_quad.zw, b->m_col1.m_quad.zw),
            _mm_mul_pd(a->m_col1.m_quad.zw, b->m_col1.m_quad.zw)));
  v18 = _mm_unpacklo_pd(_mm_mul_pd(a->m_col2.m_quad.zw, b->m_col2.m_quad.zw), (__m128d)0i64);
  v19 = b->m_col2.m_quad.xy;
  v20 = _mm_mul_pd(a->m_col0.m_quad.xy, v19);
  this->m_col0.m_quad.xy = v11;
  this->m_col1.m_quad.xy = v17;
  this->m_col0.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpackhi_pd(v7, (__m128d)0i64), _mm_unpacklo_pd(v7, (__m128d)0i64)),
                             _mm_unpacklo_pd(v9, (__m128d)0i64));
  v21 = _mm_mul_pd(xy, v19);
  v22 = _mm_mul_pd(v5, v19);
  this->m_col1.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpackhi_pd(v15, (__m128d)0i64), _mm_unpacklo_pd(v15, (__m128d)0i64)),
                             v13);
  this->m_col2.m_quad.xy = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v20, v21), _mm_unpackhi_pd(v20, v21)), v16);
  this->m_col2.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpackhi_pd(v22, (__m128d)0i64), _mm_unpacklo_pd(v22, (__m128d)0i64)),
                             v18);
}

// File Line: 94
// RVA: 0xC8BC80
void __fastcall hkMatrix3d::mul(hkMatrix3d *this, hkSimdDouble64 *scale)
{
  __m128d zw; // xmm1
  __m128d v3; // xmm1
  __m128d v4; // xmm1

  zw = this->m_col0.m_quad.zw;
  this->m_col0.m_quad.xy = _mm_mul_pd(scale->m_real, this->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_mul_pd(zw, scale->m_real);
  v3 = this->m_col1.m_quad.zw;
  this->m_col1.m_quad.xy = _mm_mul_pd(this->m_col1.m_quad.xy, scale->m_real);
  this->m_col1.m_quad.zw = _mm_mul_pd(v3, scale->m_real);
  v4 = this->m_col2.m_quad.zw;
  this->m_col2.m_quad.xy = _mm_mul_pd(this->m_col2.m_quad.xy, scale->m_real);
  this->m_col2.m_quad.zw = _mm_mul_pd(v4, scale->m_real);
}

// File Line: 101
// RVA: 0xC8AD10
void __fastcall hkMatrix3d::setCrossSkewSymmetric(hkMatrix3d *this, hkVector4d *r)
{
  __m128d xy; // xmm4
  __m128d v3; // xmm2
  __m128d v4; // xmm3
  __m128d v5; // xmm4

  xy = r->m_quad.xy;
  v3 = _mm_unpacklo_pd(r->m_quad.zw, r->m_quad.zw);
  v4 = _mm_unpacklo_pd(xy, xy);
  v5 = _mm_unpackhi_pd(xy, xy);
  this->m_col0.m_quad.xy = _mm_unpacklo_pd((__m128d)0i64, v3);
  this->m_col0.m_quad.zw = _mm_unpacklo_pd(_mm_sub_pd((__m128d)0i64, v5), (__m128d)0i64);
  this->m_col1.m_quad.xy = _mm_unpacklo_pd(_mm_sub_pd((__m128d)0i64, v3), (__m128d)0i64);
  this->m_col1.m_quad.zw = _mm_unpacklo_pd(v4, (__m128d)0i64);
  this->m_col2.m_quad.xy = _mm_unpacklo_pd(v5, _mm_sub_pd((__m128d)0i64, v4));
  this->m_col2.m_quad.zw = _mm_unpacklo_pd((__m128d)0i64, (__m128d)0i64);
}

// File Line: 119
// RVA: 0xC8B7F0
void __fastcall hkMatrix3d::setMul(hkMatrix3d *this, hkSimdDouble64 *scale, hkMatrix3d *a)
{
  this->m_col0.m_quad.xy = _mm_mul_pd(scale->m_real, a->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_mul_pd(a->m_col0.m_quad.zw, scale->m_real);
  this->m_col1.m_quad.xy = _mm_mul_pd(scale->m_real, a->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_mul_pd(a->m_col1.m_quad.zw, scale->m_real);
  this->m_col2.m_quad.xy = _mm_mul_pd(scale->m_real, a->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_mul_pd(a->m_col2.m_quad.zw, scale->m_real);
}

// File Line: 129
// RVA: 0xC8BA70
void __fastcall hkMatrix3d::addMul(hkMatrix3d *this, hkSimdDouble64 *scale, hkMatrix3d *a)
{
  this->m_col0.m_quad.xy = _mm_add_pd(_mm_mul_pd(scale->m_real, a->m_col0.m_quad.xy), this->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_add_pd(_mm_mul_pd(a->m_col0.m_quad.zw, scale->m_real), this->m_col0.m_quad.zw);
  this->m_col1.m_quad.xy = _mm_add_pd(_mm_mul_pd(scale->m_real, a->m_col1.m_quad.xy), this->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_add_pd(_mm_mul_pd(a->m_col1.m_quad.zw, scale->m_real), this->m_col1.m_quad.zw);
  this->m_col2.m_quad.xy = _mm_add_pd(_mm_mul_pd(scale->m_real, a->m_col2.m_quad.xy), this->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_add_pd(_mm_mul_pd(a->m_col2.m_quad.zw, scale->m_real), this->m_col2.m_quad.zw);
}

// File Line: 134
// RVA: 0xC8AA50
// local variable allocation has failed, the output may be wrong!
bool __fastcall hkMatrix3d::isApproximatelyEqual(hkMatrix3d *this, hkMatrix3d *m, long double zero, long double a4)
{
  __m128d v4; // xmm3

  a4 = zero;
  v4 = _mm_shuffle_pd(*(__m128d *)&a4, *(__m128d *)&a4, 0);
  return (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col0.m_quad.xy, m->m_col0.m_quad.xy),
                                             1u),
                                           1u),
                                v4)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     this->m_col0.m_quad.zw,
                                                                                     m->m_col0.m_quad.zw),
                                                                          1u),
                                                                        1u),
                                                             v4)))) & 7) == 7
      && (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col1.m_quad.xy, m->m_col1.m_quad.xy),
                                             1u),
                                           1u),
                                v4)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     this->m_col1.m_quad.zw,
                                                                                     m->m_col1.m_quad.zw),
                                                                          1u),
                                                                        1u),
                                                             v4)))) & 7) == 7
      && (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col2.m_quad.xy, m->m_col2.m_quad.xy),
                                             1u),
                                           1u),
                                v4)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     this->m_col2.m_quad.zw,
                                                                                     m->m_col2.m_quad.zw),
                                                                          1u),
                                                                        1u),
                                                             v4)))) & 7) == 7;
}

// File Line: 145
// RVA: 0xC8AB60
bool __fastcall hkMatrix3d::isApproximatelyEqualSimd(hkMatrix3d *this, hkMatrix3d *m, hkSimdDouble64 *eps)
{
  __m128d m_real; // xmm2

  m_real = eps->m_real;
  return (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col0.m_quad.xy, m->m_col0.m_quad.xy),
                                             1u),
                                           1u),
                                eps->m_real)) | (unsigned __int8)(4
                                                                * _mm_movemask_pd(
                                                                    _mm_cmplt_pd(
                                                                      (__m128d)_mm_srli_epi64(
                                                                                 _mm_slli_epi64(
                                                                                   (__m128i)_mm_sub_pd(
                                                                                              this->m_col0.m_quad.zw,
                                                                                              m->m_col0.m_quad.zw),
                                                                                   1u),
                                                                                 1u),
                                                                      eps->m_real)))) & 7) == 7
      && (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col1.m_quad.xy, m->m_col1.m_quad.xy),
                                             1u),
                                           1u),
                                m_real)) | (unsigned __int8)(4
                                                           * _mm_movemask_pd(
                                                               _mm_cmplt_pd(
                                                                 (__m128d)_mm_srli_epi64(
                                                                            _mm_slli_epi64(
                                                                              (__m128i)_mm_sub_pd(
                                                                                         this->m_col1.m_quad.zw,
                                                                                         m->m_col1.m_quad.zw),
                                                                              1u),
                                                                            1u),
                                                                 m_real)))) & 7) == 7
      && (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col2.m_quad.xy, m->m_col2.m_quad.xy),
                                             1u),
                                           1u),
                                m_real)) | (unsigned __int8)(4
                                                           * _mm_movemask_pd(
                                                               _mm_cmplt_pd(
                                                                 (__m128d)_mm_srli_epi64(
                                                                            _mm_slli_epi64(
                                                                              (__m128i)_mm_sub_pd(
                                                                                         this->m_col2.m_quad.zw,
                                                                                         m->m_col2.m_quad.zw),
                                                                              1u),
                                                                            1u),
                                                                 m_real)))) & 7) == 7;
}

// File Line: 152
// RVA: 0xC8AC70
bool __fastcall hkMatrix3d::isSymmetric(hkMatrix3d *this, long double epsilon)
{
  unsigned __int64 v2; // rdx
  __m128d v3; // xmm6
  __m128d xy; // xmm0
  __m128d v5; // xmm3
  __m128d v6; // xmm2
  __m128d v7; // xmm5
  hkMatrix3d m; // [rsp+40h] [rbp+0h] BYREF

  v2 = (unsigned __int64)&m & 0xFFFFFFFFFFFFFFE0ui64;
  v3 = _mm_unpacklo_pd(this->m_col0.m_quad.zw, this->m_col1.m_quad.zw);
  xy = this->m_col2.m_quad.xy;
  v5 = _mm_unpackhi_pd(xy, (__m128d)0i64);
  v6 = _mm_unpackhi_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v7 = _mm_unpacklo_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  *(__m128d *)v2 = _mm_unpacklo_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  *(__m128d *)(v2 + 48) = v5;
  *(__m128d *)(v2 + 64) = v3;
  *(__m128d *)(v2 + 32) = v6;
  *(__m128d *)(v2 + 16) = _mm_unpacklo_pd(xy, (__m128d)0i64);
  *(__m128d *)(v2 + 80) = v7;
  return hkMatrix3d::isApproximatelyEqual(
           this,
           (hkMatrix3d *)((unsigned __int64)&m & 0xFFFFFFFFFFFFFFE0ui64),
           epsilon,
           v5.m128d_f64[0]);
}

// File Line: 159
// RVA: 0xC8AD90
hkResult *__fastcall hkMatrix3d::invert(hkMatrix3d *this, hkResult *result, double epsilon)
{
  unsigned __int64 v3; // rbp
  __m128d xy; // xmm5
  __m128d zw; // xmm7
  __m128d v6; // xmm11
  __m128d v9; // xmm13
  __m128d v10; // xmm10
  __m128d v11; // xmm12
  __m128d v12; // xmm4
  __m128d v13; // xmm6
  __m128d v14; // xmm3
  __m128d v15; // xmm2
  __m128d v16; // xmm9
  __m128d v17; // xmm8
  __m128d v18; // xmm15
  __m128d v19; // xmm1
  __m128d v20; // xmm0
  __m128d v21; // xmm15
  __m128d v22; // xmm1
  __m128d v23; // xmm2
  __m128d v24; // xmm5
  __m128d v25; // xmm1
  __m128d v26; // xmm4
  __m128d v27; // xmm6
  __m128d v28; // xmm3
  __m128d v29; // xmm0
  __m128d v30; // xmm10
  __m128d v31; // xmm5
  __m128d v32; // xmm7
  __m128d v33; // xmm4
  __m128d v34; // xmm12
  __m128d v35; // xmm8
  __m128d v36; // xmm2
  __m128d v37; // xmm1
  __int128 v39[2]; // [rsp+40h] [rbp+0h] BYREF

  v3 = (unsigned __int64)v39 & 0xFFFFFFFFFFFFFFE0ui64;
  xy = this->m_col2.m_quad.xy;
  zw = this->m_col2.m_quad.zw;
  v6 = this->m_col1.m_quad.xy;
  v9 = this->m_col1.m_quad.zw;
  v10 = this->m_col0.m_quad.xy;
  v11 = this->m_col0.m_quad.zw;
  v12 = _mm_shuffle_pd(xy, zw, 2);
  v13 = _mm_shuffle_pd(xy, zw, 1);
  v14 = _mm_shuffle_pd(this->m_col0.m_quad.xy, v11, 1);
  v15 = _mm_shuffle_pd(this->m_col0.m_quad.xy, v11, 2);
  v16 = _mm_shuffle_pd(v6, v9, 1);
  v17 = _mm_shuffle_pd(v6, v9, 2);
  v18 = _mm_sub_pd(_mm_mul_pd(v6, v13), _mm_mul_pd(v16, xy));
  v19 = _mm_sub_pd(_mm_mul_pd(v12, v9), _mm_mul_pd(v17, zw));
  v20 = _mm_shuffle_pd(v18, v19, 1);
  v21 = _mm_shuffle_pd(v18, v19, 2);
  *(__m128d *)(v3 + 32) = v20;
  v22 = _mm_mul_pd(v15, zw);
  v23 = _mm_mul_pd(v15, v9);
  *(__m128d *)v3 = _mm_mul_pd(v14, xy);
  v24 = _mm_sub_pd(*(__m128d *)((unsigned __int64)v39 & 0xFFFFFFFFFFFFFFE0ui64), _mm_mul_pd(v10, v13));
  v25 = _mm_sub_pd(v22, _mm_mul_pd(v11, v12));
  v26 = _mm_sub_pd(_mm_mul_pd(v10, v16), _mm_mul_pd(v14, v6));
  v27 = _mm_shuffle_pd(v24, v25, 1);
  v28 = *(__m128d *)(((unsigned __int64)v39 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  v29 = _mm_sub_pd(_mm_mul_pd(v11, v17), v23);
  v23.m128d_f64[0] = epsilon;
  v30 = _mm_mul_pd(v10, v28);
  v23.m128d_f64[0] = _mm_shuffle_pd(v23, v23, 0).m128d_f64[0];
  v31 = _mm_shuffle_pd(v24, v25, 2);
  v32 = _mm_shuffle_pd(v26, v29, 1);
  v33 = _mm_shuffle_pd(v26, v29, 2);
  v34 = _mm_mul_pd(v11, v21);
  v35 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v30, v30), _mm_unpackhi_pd(v30, v30)), _mm_unpacklo_pd(v34, v34));
  if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)&v35.m128d_f64[0]) >> 1) <= v23.m128d_f64[0]
                                                                                    * v23.m128d_f64[0]
                                                                                    * v23.m128d_f64[0] )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v36 = _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps(v35)));
    v37 = _mm_mul_pd(_mm_sub_pd(g_vectordConstants[3].xy, _mm_mul_pd(v36, v35)), v36);
    this->m_col0.m_quad.xy = _mm_mul_pd(v28, v37);
    this->m_col0.m_quad.zw = _mm_mul_pd(v21, v37);
    this->m_col1.m_quad.xy = _mm_mul_pd(v27, v37);
    this->m_col1.m_quad.zw = _mm_mul_pd(v31, v37);
    this->m_col2.m_quad.xy = _mm_mul_pd(v32, v37);
    this->m_col2.m_quad.zw = _mm_mul_pd(v33, v37);
    hkMatrix3d::transpose(this);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 182
// RVA: 0xC8B020
void __fastcall hkMatrix3d::invertSymmetric(hkMatrix3d *this)
{
  __m128d xy; // xmm2
  __m128d zw; // xmm6
  __m128d v3; // xmm10
  __m128d v4; // xmm12
  __m128d v5; // xmm9
  __m128d v6; // xmm11
  __m128d v7; // xmm4
  __m128d v8; // xmm5
  __m128d v9; // xmm8
  __m128d v10; // xmm15
  __m128d v11; // xmm7
  __m128d v12; // xmm13
  __m128d v13; // xmm1
  __m128d v14; // xmm0
  __m128d v15; // xmm3
  __m128d v16; // xmm15
  __m128d v17; // xmm14
  __m128d v18; // xmm13
  __m128d v19; // xmm14
  __m128d v20; // xmm2
  __m128d v21; // xmm9
  __m128d v22; // xmm1
  __m128d v23; // xmm0
  __m128d v24; // xmm5
  __m128d v25; // xmm13
  __m128d v26; // xmm11
  __m128d v27; // xmm0
  __m128d v28; // xmm4
  __m128d v29; // xmm3
  __m128d v30; // xmm2
  __m128d v31; // xmm0
  __m128d v32; // xmm7
  __int128 v33; // [rsp+20h] [rbp+0h] BYREF

  xy = this->m_col2.m_quad.xy;
  zw = this->m_col2.m_quad.zw;
  v3 = this->m_col1.m_quad.xy;
  v4 = this->m_col1.m_quad.zw;
  v5 = this->m_col0.m_quad.xy;
  v6 = this->m_col0.m_quad.zw;
  v7 = _mm_shuffle_pd(xy, zw, 2);
  v8 = _mm_shuffle_pd(xy, zw, 1);
  v9 = _mm_shuffle_pd(v3, v4, 1);
  v10 = _mm_sub_pd(_mm_mul_pd(v3, v8), _mm_mul_pd(v9, xy));
  v11 = _mm_shuffle_pd(v3, v4, 2);
  v12 = _mm_mul_pd(this->m_col0.m_quad.xy, v9);
  v13 = _mm_sub_pd(_mm_mul_pd(v7, v4), _mm_mul_pd(v11, zw));
  v14 = _mm_mul_pd(this->m_col0.m_quad.xy, v8);
  v15 = _mm_shuffle_pd(v10, v13, 2);
  v16 = _mm_shuffle_pd(v10, v13, 1);
  *(__m128d *)((unsigned __int64)&v33 & 0xFFFFFFFFFFFFFFE0ui64) = v15;
  v17 = _mm_shuffle_pd(v5, v6, 1);
  v18 = _mm_sub_pd(v12, _mm_mul_pd(v17, v3));
  v19 = _mm_sub_pd(_mm_mul_pd(v17, xy), v14);
  v20 = _mm_shuffle_pd(v5, v6, 2);
  v21 = _mm_mul_pd(v5, v16);
  v22 = _mm_sub_pd(_mm_mul_pd(v20, zw), _mm_mul_pd(v6, v7));
  v23 = _mm_sub_pd(_mm_mul_pd(v6, v11), _mm_mul_pd(v20, v4));
  v24 = _mm_shuffle_pd(v18, v23, 1);
  v25 = _mm_shuffle_pd(v18, v23, 2);
  v26 = _mm_mul_pd(v6, *(__m128d *)((unsigned __int64)&v33 & 0xFFFFFFFFFFFFFFE0ui64));
  v27 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v21, v21), _mm_unpackhi_pd(v21, v21)), _mm_unpacklo_pd(v26, v26));
  v28 = _mm_cmplt_pd(
          _mm_mul_pd(_mm_mul_pd(g_vectordConstants[34].xy, g_vectordConstants[34].xy), g_vectordConstants[34].xy),
          v27);
  v29 = _mm_or_pd(_mm_and_pd(v28, v27), _mm_andn_pd(v28, g_vectordConstants[2].xy));
  v30 = _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps(v29)));
  v31 = _mm_and_pd(_mm_mul_pd(_mm_sub_pd(g_vectordConstants[3].xy, _mm_mul_pd(v29, v30)), v30), v28);
  v32 = _mm_mul_pd(*(__m128d *)((unsigned __int64)&v33 & 0xFFFFFFFFFFFFFFE0ui64), v31);
  this->m_col0.m_quad.xy = _mm_mul_pd(v16, v31);
  this->m_col0.m_quad.zw = v32;
  this->m_col1.m_quad.xy = _mm_mul_pd(_mm_shuffle_pd(v19, v22, 1), v31);
  this->m_col1.m_quad.zw = _mm_mul_pd(_mm_shuffle_pd(v19, v22, 2), v31);
  this->m_col2.m_quad.xy = _mm_mul_pd(v24, v31);
  this->m_col2.m_quad.zw = _mm_mul_pd(v25, v31);
}

// File Line: 208
// RVA: 0xC8BB50
void __fastcall hkMatrix3d::add(hkMatrix3d *this, hkMatrix3d *a)
{
  this->m_col0.m_quad.xy = _mm_add_pd(a->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_add_pd(a->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  this->m_col1.m_quad.xy = _mm_add_pd(this->m_col1.m_quad.xy, a->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_add_pd(a->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  this->m_col2.m_quad.xy = _mm_add_pd(this->m_col2.m_quad.xy, a->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_add_pd(a->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
}

// File Line: 215
// RVA: 0xC8BBB0
void __fastcall hkMatrix3d::sub(hkMatrix3d *this, hkMatrix3d *a)
{
  __m128d zw; // xmm1
  __m128d v3; // xmm1
  __m128d v4; // xmm1

  zw = this->m_col0.m_quad.zw;
  this->m_col0.m_quad.xy = _mm_sub_pd(this->m_col0.m_quad.xy, a->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_sub_pd(zw, a->m_col0.m_quad.zw);
  v3 = this->m_col1.m_quad.zw;
  this->m_col1.m_quad.xy = _mm_sub_pd(this->m_col1.m_quad.xy, a->m_col1.m_quad.xy);
  this->m_col1.m_quad.zw = _mm_sub_pd(v3, a->m_col1.m_quad.zw);
  v4 = this->m_col2.m_quad.zw;
  this->m_col2.m_quad.xy = _mm_sub_pd(this->m_col2.m_quad.xy, a->m_col2.m_quad.xy);
  this->m_col2.m_quad.zw = _mm_sub_pd(v4, a->m_col2.m_quad.zw);
}

// File Line: 222
// RVA: 0xC8BC10
void __fastcall hkMatrix3d::mul(hkMatrix3d *this, hkMatrix3d *a)
{
  __m128d v3; // xmm1
  __m128d v4; // xmm0
  __m128d v5; // xmm1
  __m128d v6; // xmm0
  __m128d v7; // xmm1
  hkMatrix3d v8; // [rsp+40h] [rbp+0h] BYREF

  hkMatrix3d::setMul((hkMatrix3d *)((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64), this, a);
  v3 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10);
  this->m_col0.m_quad.xy = *(__m128d *)((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64);
  v4 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  this->m_col0.m_quad.zw = v3;
  v5 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  this->m_col1.m_quad.xy = v4;
  v6 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
  this->m_col1.m_quad.zw = v5;
  v7 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
  this->m_col2.m_quad.xy = v6;
  this->m_col2.m_quad.zw = v7;
}

// File Line: 230
// RVA: 0xC8BD90
hkSimdDouble64 *__fastcall hkMatrix3d::getDeterminant(hkMatrix3d *this, hkSimdDouble64 *result)
{
  hkSimdDouble64 *v2; // rax
  __m128d v3; // xmm7
  __m128d v4; // xmm2
  __m128d v5; // xmm4
  __m128d xy; // xmm5
  __m128d v7; // xmm3
  __m128d v8; // xmm6
  __m128d v9; // xmm7
  __m128d v10; // xmm1
  __m128d v11; // xmm6

  v2 = result;
  v3 = _mm_unpacklo_pd(this->m_col0.m_quad.zw, this->m_col1.m_quad.zw);
  v4 = _mm_unpackhi_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v5 = _mm_unpacklo_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  xy = this->m_col2.m_quad.xy;
  v7 = _mm_unpackhi_pd(xy, (__m128d)0i64);
  v8 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v3, v5, 1), v4), _mm_mul_pd(_mm_shuffle_pd(v4, v7, 1), v3));
  v9 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v3, v5, 2), v7), _mm_mul_pd(_mm_shuffle_pd(v4, v7, 2), v5));
  v10 = _mm_mul_pd(_mm_shuffle_pd(v8, v9, 1), _mm_unpacklo_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy));
  v11 = _mm_mul_pd(_mm_shuffle_pd(v8, v9, 2), _mm_unpacklo_pd(xy, (__m128d)0i64));
  result->m_real = _mm_add_pd(
                     _mm_add_pd(_mm_unpacklo_pd(v10, v10), _mm_unpackhi_pd(v10, v10)),
                     _mm_unpacklo_pd(v11, v11));
  return v2;
}

// File Line: 251
// RVA: 0xC8D2B0
void __fastcall constructSchurMatrix_0(hkMatrix3d *M, int p, int q, SchurMatrix *S)
{
  hkQuadDouble64 *v4; // r10
  double *v5; // r11
  double v6; // xmm0_8
  double *v7; // r11
  hkQuadDouble64 *v8; // r8
  double *v9; // rax
  double v10; // xmm1_8
  double v11; // xmm3_8
  double v12; // xmm2_8
  double v13; // xmm5_8

  LODWORD(S[1].c) = p;
  LODWORD(S[1].s) = q;
  v4 = &M->m_col0.m_quad + q;
  if ( p >= 2 )
    v5 = &v4->xy.m128d_f64[p];
  else
    v5 = &v4->xy.m128d_f64[p];
  v6 = *v5;
  if ( *v5 == 0.0 )
  {
    *(_QWORD *)&S->c = 0x3FF0000000000000i64;
    *(_QWORD *)&S->p = 0i64;
  }
  else
  {
    if ( q >= 2 )
      v7 = &v4->xy.m128d_f64[q];
    else
      v7 = &v4->xy.m128d_f64[q];
    v8 = &M->m_col0.m_quad + p;
    if ( p >= 2 )
      v9 = &v8->xy.m128d_f64[p];
    else
      v9 = &v8->xy.m128d_f64[p];
    v10 = (*v7 - *v9) / (v6 * 2.0);
    v11 = sqrt(v10 * v10 + 1.0);
    if ( v10 < 0.0 )
      v12 = 1.0 / (v10 - v11);
    else
      v12 = 1.0 / (v11 + v10);
    v13 = sqrt(v12 * v12 + 1.0);
    *(double *)&S->c = *(double *)_xmm / v13;
    *(double *)&S->p = *(double *)_xmm / v13 * v12;
  }
}

// File Line: 272
// RVA: 0xC8D400
void __fastcall constructSchurMatrixUnchecked_0(hkMatrix3d *M, int p, int q, SchurMatrix *S)
{
  hkQuadDouble64 *v4; // r10
  double *v5; // r11
  double v6; // xmm0_8
  double *v7; // r11
  hkQuadDouble64 *v8; // r8
  double *v9; // rax
  double v10; // xmm1_8
  double v11; // xmm3_8
  double v12; // xmm2_8
  double v13; // xmm5_8

  LODWORD(S[1].c) = p;
  LODWORD(S[1].s) = q;
  v4 = &M->m_col0.m_quad + q;
  if ( p >= 2 )
    v5 = &v4->xy.m128d_f64[p];
  else
    v5 = &v4->xy.m128d_f64[p];
  v6 = *v5;
  if ( q >= 2 )
    v7 = &v4->xy.m128d_f64[q];
  else
    v7 = &v4->xy.m128d_f64[q];
  v8 = &M->m_col0.m_quad + p;
  if ( p >= 2 )
    v9 = &v8->xy.m128d_f64[p];
  else
    v9 = &v8->xy.m128d_f64[p];
  v10 = (*v7 - *v9) / (v6 * 2.0);
  v11 = sqrt(v10 * v10 + 1.0);
  if ( v10 < 0.0 )
    v12 = 1.0 / (v10 - v11);
  else
    v12 = 1.0 / (v11 + v10);
  v13 = sqrt(v12 * v12 + 1.0);
  *(double *)&S->c = *(double *)_xmm / v13;
  *(double *)&S->p = *(double *)_xmm / v13 * v12;
}

// File Line: 285
// RVA: 0xC8D520
hkSimdDouble64 *__fastcall frobeniusNormSqr_0(hkSimdDouble64 *result, hkMatrix3d *M)
{
  hkSimdDouble64 *v2; // rax
  __m128d v3; // xmm0
  __m128d v4; // xmm1
  __m128d v5; // xmm2
  __m128d v6; // xmm5
  __m128d v7; // xmm6
  __m128d v8; // xmm3

  v2 = result;
  v3 = _mm_mul_pd(M->m_col0.m_quad.xy, M->m_col0.m_quad.xy);
  v4 = _mm_mul_pd(M->m_col0.m_quad.zw, M->m_col0.m_quad.zw);
  v5 = _mm_mul_pd(M->m_col1.m_quad.xy, M->m_col1.m_quad.xy);
  v6 = _mm_mul_pd(M->m_col2.m_quad.xy, M->m_col2.m_quad.xy);
  v7 = _mm_mul_pd(M->m_col2.m_quad.zw, M->m_col2.m_quad.zw);
  v8 = _mm_mul_pd(M->m_col1.m_quad.zw, M->m_col1.m_quad.zw);
  result->m_real = _mm_add_pd(
                     _mm_add_pd(
                       _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v3, v3), _mm_unpackhi_pd(v3, v3)), _mm_unpacklo_pd(v4, v4)),
                       _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v5, v5), _mm_unpackhi_pd(v5, v5)), _mm_unpacklo_pd(v8, v8))),
                     _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v6, v6), _mm_unpackhi_pd(v6, v6)), _mm_unpacklo_pd(v7, v7)));
  return v2;
}

// File Line: 290
// RVA: 0xC8B280
hkSimdDouble64 *__fastcall hkMatrix3d::frobeniusNormSqr(hkMatrix3d *this, hkSimdDouble64 *result)
{
  hkSimdDouble64 *v2; // rax
  __m128d v3; // xmm0
  __m128d v4; // xmm1
  __m128d v5; // xmm2
  __m128d v6; // xmm5
  __m128d v7; // xmm6
  __m128d v8; // xmm3

  v2 = result;
  v3 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v4 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v5 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v6 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v7 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  v8 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  result->m_real = _mm_add_pd(
                     _mm_add_pd(
                       _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v3, v3), _mm_unpackhi_pd(v3, v3)), _mm_unpacklo_pd(v4, v4)),
                       _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v5, v5), _mm_unpackhi_pd(v5, v5)), _mm_unpacklo_pd(v8, v8))),
                     _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v6, v6), _mm_unpackhi_pd(v6, v6)), _mm_unpacklo_pd(v7, v7)));
  return v2;
}

// File Line: 296
// RVA: 0xC8D5D0
hkSimdDouble64 *__fastcall offDiagNormSqr_0(hkSimdDouble64 *result, hkMatrix3d *M)
{
  __m128d xy; // xmm1
  hkSimdDouble64 *v3; // rax
  __m128d v4; // xmm0
  __m128d v5; // xmm2
  __m128d v6; // xmm1

  xy = M->m_col2.m_quad.xy;
  v3 = result;
  v4 = _mm_unpacklo_pd(M->m_col1.m_quad.xy, M->m_col1.m_quad.xy);
  v5 = _mm_unpacklo_pd(xy, xy);
  v6 = _mm_unpackhi_pd(xy, xy);
  result->m_real = _mm_mul_pd(
                     _mm_add_pd(_mm_add_pd(_mm_mul_pd(v5, v5), _mm_mul_pd(v4, v4)), _mm_mul_pd(v6, v6)),
                     g_vectordConstants[3].xy);
  return v3;
}

// File Line: 305
// RVA: 0xC8D620
long double __fastcall findLargestOffDiagEntry_0(hkMatrix3d *M, int *p, int *q)
{
  double v3; // xmm1_8
  double v4; // xmm3_8
  double v5; // xmm2_8
  long double result; // xmm0_8

  *p = 0;
  *q = 1;
  *(_QWORD *)&v3 = (unsigned __int64)(2i64 * *(_QWORD *)&M->m_col1.m_quad.xy.m128d_f64[0]) >> 1;
  *(_QWORD *)&v4 = (unsigned __int64)(2i64 * *(_QWORD *)&M->m_col2.m_quad.xy.m128d_f64[0]) >> 1;
  *(_QWORD *)&v5 = (unsigned __int64)(2i64 * *(_QWORD *)&M->m_col2.m_quad.xy.m128d_f64[1]) >> 1;
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
// RVA: 0xC8D6B0
void __fastcall constructJacobiRotation_0__0(hkMatrix3d *J, SchurMatrix *S)
{
  __int64 c_low; // rax
  hkQuadDouble64 *v4; // r8
  char *v5; // rcx
  __int64 v6; // rax
  hkQuadDouble64 *v7; // r8
  char *v8; // rcx
  __int64 s_low; // rax
  hkQuadDouble64 *v10; // r8
  double *v11; // rcx
  __int64 v12; // rax
  hkQuadDouble64 *v13; // r8

  J->m_col0.m_quad = g_vectordConstants[28];
  J->m_col1.m_quad = g_vectordConstants[29];
  J->m_col2.m_quad = g_vectordConstants[30];
  c_low = SLODWORD(S[1].c);
  v4 = &J->m_col0.m_quad + c_low;
  if ( (int)c_low >= 2 )
    v5 = (char *)&v4->xy.m128d_f64[(int)c_low];
  else
    v5 = (char *)&v4->xy.m128d_f64[c_low];
  *(_QWORD *)v5 = *(_QWORD *)&S->c;
  v6 = SLODWORD(S[1].c);
  v7 = &J->m_col0.m_quad + SLODWORD(S[1].s);
  if ( (int)v6 >= 2 )
    v8 = (char *)&v7->xy.m128d_f64[(int)v6];
  else
    v8 = (char *)&v7->xy.m128d_f64[v6];
  *(_QWORD *)v8 = *(_QWORD *)&S->p;
  s_low = SLODWORD(S[1].s);
  v10 = &J->m_col0.m_quad + SLODWORD(S[1].c);
  if ( (int)s_low >= 2 )
    v11 = &v10->xy.m128d_f64[(int)s_low];
  else
    v11 = &v10->xy.m128d_f64[s_low];
  *v11 = -*(double *)&S->p;
  v12 = SLODWORD(S[1].s);
  v13 = &J->m_col0.m_quad + v12;
  if ( (int)v12 >= 2 )
    v13->xy.m128d_f64[(int)v12] = *(long double *)&S->c;
  else
    v13->xy.m128d_f64[SLODWORD(S[1].s)] = *(long double *)&S->c;
}

// File Line: 343
// RVA: 0xC8BE70
hkResult *__fastcall hkMatrix3d::diagonalizeSymmetric(
        hkMatrix3d *this,
        hkResult *result,
        hkRotationd *eigenVec,
        hkVector4d *eigenVal,
        int maxIter,
        unsigned __int64 epsilon)
{
  unsigned __int64 v6; // rbp
  __m128d xy; // xmm7
  __m128d v8; // xmm8
  int v9; // r14d
  hkVector4d *v10; // rax
  double v13; // xmm6_8
  __m128d v14; // xmm10
  __m128d zw; // xmm9
  __m128d v16; // xmm0
  __m128d v17; // xmm0
  __m128d v18; // xmm2
  __m128d v19; // xmm1
  __m128d v20; // xmm4
  __m128d v21; // xmm3
  long double v22; // xmm12_8
  __m128d v23; // xmm5
  long double v24; // xmm12_8
  double v25; // xmm12_8
  double v26; // xmm2_8
  double v27; // xmm0_8
  int v28; // edx
  int v29; // r8d
  double v30; // xmm1_8
  double v31; // xmm1_8
  double v32; // xmm0_8
  __int64 v33; // r11
  unsigned __int64 v34; // r10
  double *v35; // rcx
  double *v36; // rbx
  double v37; // xmm1_8
  double v38; // xmm3_8
  double v39; // xmm2_8
  double v40; // xmm3_8
  double v41; // xmm4_8
  __int64 v42; // rsi
  unsigned __int64 v43; // rdi
  unsigned __int64 v44; // rbx
  __int64 *v45; // rax
  double *v46; // rax
  unsigned __int64 v47; // rbx
  unsigned __int64 v48; // r11
  double *v49; // rax
  double *v50; // rax
  double v51; // xmm2_8
  double v52; // xmm1_8
  double v53; // xmm0_8
  hkResult *v54; // rax
  __int64 v55[4]; // [rsp+40h] [rbp+0h] BYREF

  v6 = (unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64;
  xy = this->m_col2.m_quad.xy;
  v8 = this->m_col1.m_quad.xy;
  v9 = 0;
  v10 = eigenVal;
  v13 = _mm_shuffle_pd((__m128d)epsilon, (__m128d)epsilon, 0).m128d_f64[0];
  v14 = this->m_col0.m_quad.xy;
  zw = this->m_col2.m_quad.zw;
  *(__m128d *)(v6 + 48) = this->m_col0.m_quad.zw;
  v16 = this->m_col1.m_quad.zw;
  *(__m128d *)(v6 + 32) = v14;
  *(__m128d *)(v6 + 64) = v8;
  *(__m128d *)(v6 + 80) = v16;
  *(__m128d *)(v6 + 96) = xy;
  eigenVec->m_col0.m_quad.xy = g_vectordConstants[28].xy;
  *(__m128d *)(v6 + 112) = zw;
  eigenVec->m_col0.m_quad.zw = g_vectordConstants[28].zw;
  eigenVec->m_col1.m_quad = g_vectordConstants[29];
  eigenVec->m_col2.m_quad = g_vectordConstants[30];
  v17 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v18 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v19 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v20 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v21 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  v22 = _mm_unpacklo_pd(v17, v17).m128d_f64[0]
      + _mm_unpackhi_pd(v17, v17).m128d_f64[0]
      + _mm_unpacklo_pd(v19, v19).m128d_f64[0];
  v17.m128d_f64[0] = _mm_unpacklo_pd(v18, v18).m128d_f64[0] + _mm_unpackhi_pd(v18, v18).m128d_f64[0];
  v23 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  v18.m128d_f64[0] = _mm_unpacklo_pd(xy, xy).m128d_f64[0];
  v24 = v22 + v17.m128d_f64[0] + _mm_unpacklo_pd(v21, v21).m128d_f64[0];
  v17.m128d_f64[0] = _mm_unpackhi_pd(xy, xy).m128d_f64[0];
  v19.m128d_f64[0] = _mm_unpacklo_pd(v8, v8).m128d_f64[0];
  v25 = (v24
       + _mm_unpacklo_pd(v20, v20).m128d_f64[0]
       + _mm_unpackhi_pd(v20, v20).m128d_f64[0]
       + _mm_unpacklo_pd(v23, v23).m128d_f64[0])
      * (v13
       * v13);
  v26 = (v18.m128d_f64[0] * v18.m128d_f64[0] + v19.m128d_f64[0] * v19.m128d_f64[0] + v17.m128d_f64[0] * v17.m128d_f64[0])
      * 2.0;
  if ( v26 > v25 )
  {
    do
    {
      if ( v9 >= maxIter )
        break;
      *(long double *)v6 = v8.m128d_f64[0];
      v27 = *(double *)v6;
      *(long double *)v6 = xy.m128d_f64[0];
      v28 = 0;
      v29 = 1;
      v30 = *(double *)v6;
      *(_QWORD *)v6 = *(_OWORD *)&_mm_unpackhi_pd(xy, xy);
      *(_QWORD *)&v31 = (unsigned __int64)(2i64 * *(_QWORD *)&v30) >> 1;
      *(_QWORD *)&v32 = (unsigned __int64)(2i64 * *(_QWORD *)&v27) >> 1;
      if ( v31 > v32 )
      {
        v29 = 2;
        v32 = v31;
      }
      if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)v6) >> 1) > v32 )
      {
        v28 = 1;
        v29 = 2;
      }
      v33 = 32i64 * v29;
      v34 = v33 + v6 + 32;
      v35 = (double *)(v34 + 8i64 * v28);
      if ( *v35 == 0.0 )
      {
        v40 = DOUBLE_1_0;
        v41 = 0.0;
      }
      else
      {
        v36 = (double *)(v29 >= 2 ? v34 + 8 * (v29 - 2 + 2i64) : v34 + 8i64 * v29);
        v37 = (*v36 - *(double *)(32i64 * v28 + ((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20 + 8i64 * v28))
            / (*v35
             * 2.0);
        *(double *)v6 = v37 * v37 + 1.0;
        v38 = sqrt(*(double *)v6);
        v39 = v37 < 0.0 ? 1.0 / (v37 - v38) : 1.0 / (v38 + v37);
        *(double *)v6 = v39 * v39 + 1.0;
        v40 = *(double *)_xmm / sqrt(*(double *)v6);
        v41 = v40 * v39;
      }
      v42 = 32i64 * v28;
      v43 = v42 + v6 + 128;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = g_vectordConstants[30].zw;
      *(double *)(v43 + 8i64 * v28) = v40;
      v44 = v33 + v6 + 128;
      *(double *)(v44 + 8i64 * v28) = v41;
      v45 = (__int64 *)(v29 >= 2 ? v43 + 8 * (v29 - 2 + 2i64) : v43 + 8i64 * v29);
      *v45 = *(_QWORD *)&v41 ^ _xmm[0];
      v46 = (double *)(v29 >= 2 ? v44 + 8 * (v29 - 2 + 2i64) : v44 + 8i64 * v29);
      *v46 = v40;
      v47 = v42 + v6 + 224;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x110) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130) = g_vectordConstants[30].zw;
      *(double *)(v47 + 8i64 * v28) = v40;
      v48 = v6 + 224 + v33;
      *(_QWORD *)(v48 + 8i64 * v28) = *(_QWORD *)&v41 ^ _xmm[0];
      v49 = (double *)(v29 >= 2 ? v47 + 8 * (v29 - 2 + 2i64) : v47 + 8i64 * v29);
      *v49 = v41;
      v50 = (double *)(v29 >= 2 ? v48 + 8 * (v29 - 2 + 2i64) : v48 + 8i64 * v29);
      *v50 = v40;
      hkMatrix3d::mul((hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 128));
      hkMatrix3d::setMul((hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32));
      hkMatrix3d::mul(eigenVec, (hkMatrix3d *)(v6 + 128));
      ++v9;
      xy = *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
      v8 = *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
      v51 = _mm_unpacklo_pd(xy, xy).m128d_f64[0];
      v52 = _mm_unpacklo_pd(v8, v8).m128d_f64[0];
      v53 = _mm_unpackhi_pd(xy, xy).m128d_f64[0];
      v26 = (v51 * v51 + v52 * v52 + v53 * v53) * 2.0;
    }
    while ( v26 > v25 );
    zw = *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    v14 = *(__m128d *)(((unsigned __int64)v55 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v10 = eigenVal;
  }
  v10->m_quad.xy = _mm_unpacklo_pd(_mm_unpacklo_pd(v14, v14), _mm_unpackhi_pd(v8, v8));
  v10->m_quad.zw = _mm_unpacklo_pd(zw, zw);
  v54 = result;
  result->m_enum = v26 > v25;
  return v54;
}

// File Line: 389
// RVA: 0xC8C4B0
hkResult *__fastcall hkMatrix3d::diagonalizeSymmetricWarmStart(
        hkMatrix3d *this,
        hkResult *result,
        hkMatrix3d *eigenVec,
        hkVector4d *eigenVal,
        int maxIter,
        unsigned __int64 epsilon)
{
  unsigned __int64 v6; // rbp
  __m128d zw; // xmm1
  __m128d xy; // xmm0
  __m128d v13; // xmm1
  __m128d v14; // xmm0
  __m128d v15; // xmm1
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  __m128d v18; // xmm0
  __m128d v19; // xmm1
  __m128d v20; // xmm0
  __m128d v21; // xmm1
  int v22; // esi
  __m128d v23; // xmm0
  __m128d v24; // xmm1
  __m128d v25; // xmm2
  __m128d v26; // xmm9
  long double v27; // xmm10_8
  __m128d v28; // xmm4
  __m128d v29; // xmm3
  __m128d v30; // xmm5
  __m128d v31; // xmm2
  double v32; // xmm6_8
  double v33; // xmm8_8
  double v34; // xmm10_8
  double i; // xmm8_8
  double v36; // xmm0_8
  int v37; // edx
  int v38; // r8d
  double v39; // xmm1_8
  double v40; // xmm1_8
  double v41; // xmm0_8
  __int64 v42; // r11
  unsigned __int64 v43; // r9
  double *v44; // rcx
  double *v45; // r10
  double v46; // xmm1_8
  double v47; // xmm3_8
  double v48; // xmm2_8
  double v49; // xmm4_8
  double v50; // xmm3_8
  __int64 v51; // r10
  unsigned __int64 v52; // r9
  __int64 *v53; // rax
  double *v54; // rax
  __int128 v55; // xmm1
  __int128 v56; // xmm0
  __int128 v57; // xmm1
  __int128 v58; // xmm0
  __int128 v59; // xmm1
  double v60; // xmm8_8
  __m128d v61; // xmm5
  __m128d v62; // xmm0
  __m128d v63; // xmm1
  __m128d v64; // xmm3
  __m128d v65; // xmm2
  __m128d v66; // xmm0
  __m128d v67; // xmm4
  __m128d v68; // xmm0
  __m128d v69; // xmm6
  __m128d v70; // xmm5
  __m128d v71; // xmm0
  __m128d v72; // xmm1
  __m128d v73; // xmm3
  __m128d v74; // xmm2
  __m128d v75; // xmm0
  __m128d v76; // xmm6
  __m128d v77; // xmm5
  __m128d v78; // xmm0
  __m128d v79; // xmm1
  __m128d v80; // xmm3
  __m128d v81; // xmm2
  hkResult *v82; // rax
  __m128d v83; // xmm0
  __int64 v84[4]; // [rsp+40h] [rbp+0h] BYREF

  v6 = (unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64;
  zw = this->m_col0.m_quad.zw;
  *(__m128d *)(v6 + 128) = this->m_col0.m_quad.xy;
  xy = this->m_col1.m_quad.xy;
  *(__m128d *)(v6 + 144) = zw;
  v13 = this->m_col1.m_quad.zw;
  *(__m128d *)(v6 + 160) = xy;
  v14 = this->m_col2.m_quad.xy;
  *(__m128d *)(v6 + 176) = v13;
  v15 = this->m_col2.m_quad.zw;
  *(__m128d *)(v6 + 192) = v14;
  v16 = eigenVec->m_col0.m_quad.xy;
  *(__m128d *)(v6 + 208) = v15;
  v17 = eigenVec->m_col0.m_quad.zw;
  *(__m128d *)(v6 + 32) = v16;
  v18 = eigenVec->m_col1.m_quad.xy;
  *(__m128d *)(v6 + 48) = v17;
  v19 = eigenVec->m_col1.m_quad.zw;
  *(__m128d *)(v6 + 64) = v18;
  v20 = eigenVec->m_col2.m_quad.xy;
  *(__m128d *)(v6 + 80) = v19;
  v21 = eigenVec->m_col2.m_quad.zw;
  *(__m128d *)(v6 + 96) = v20;
  *(__m128d *)(v6 + 112) = v21;
  hkMatrix3d::transpose((hkMatrix3d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 32));
  hkMatrix3d::setMul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 128));
  hkMatrix3d::mul((hkMatrix3d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 224), eigenVec);
  v22 = 0;
  v23 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v24 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v25 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v26 = *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100);
  v27 = _mm_unpacklo_pd(v23, v23).m128d_f64[0]
      + _mm_unpackhi_pd(v23, v23).m128d_f64[0]
      + _mm_unpacklo_pd(v24, v24).m128d_f64[0];
  v28 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v29 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  v30 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  v23.m128d_f64[0] = _mm_unpacklo_pd(v25, v25).m128d_f64[0] + _mm_unpackhi_pd(v25, v25).m128d_f64[0];
  v31 = *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120);
  v32 = _mm_shuffle_pd((__m128d)epsilon, (__m128d)epsilon, 0).m128d_f64[0];
  v33 = _mm_unpacklo_pd(v31, v31).m128d_f64[0];
  v24.m128d_f64[0] = _mm_unpacklo_pd(v26, v26).m128d_f64[0];
  v34 = (v27
       + v23.m128d_f64[0]
       + _mm_unpacklo_pd(v29, v29).m128d_f64[0]
       + _mm_unpacklo_pd(v28, v28).m128d_f64[0]
       + _mm_unpackhi_pd(v28, v28).m128d_f64[0]
       + _mm_unpacklo_pd(v30, v30).m128d_f64[0])
      * (v32
       * v32);
  v23.m128d_f64[0] = _mm_unpackhi_pd(v31, v31).m128d_f64[0];
  for ( i = (v33 * v33 + v24.m128d_f64[0] * v24.m128d_f64[0] + v23.m128d_f64[0] * v23.m128d_f64[0]) * 2.0;
        i >= v34;
        i = (v60 * v60 + *(double *)&v59 * *(double *)&v59 + *(double *)&v58 * *(double *)&v58) * 2.0 )
  {
    if ( v22 >= maxIter )
      break;
    *(long double *)v6 = v26.m128d_f64[0];
    v36 = *(double *)v6;
    *(long double *)v6 = v31.m128d_f64[0];
    v37 = 0;
    v38 = 1;
    v39 = *(double *)v6;
    *(_QWORD *)v6 = *(_OWORD *)&_mm_unpackhi_pd(v31, v31);
    *(_QWORD *)&v40 = (unsigned __int64)(2i64 * *(_QWORD *)&v39) >> 1;
    *(_QWORD *)&v41 = (unsigned __int64)(2i64 * *(_QWORD *)&v36) >> 1;
    if ( v40 > v41 )
    {
      v38 = 2;
      v41 = v40;
    }
    if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)v6) >> 1) > v41 )
    {
      v37 = 1;
      v38 = 2;
    }
    v42 = 32i64 * v38;
    v43 = v42 + v6 + 224;
    v44 = (double *)(v43 + 8i64 * v37);
    if ( *v44 == 0.0 )
    {
      v49 = DOUBLE_1_0;
      v50 = 0.0;
    }
    else
    {
      v45 = (double *)(v38 >= 2 ? v43 + 8 * (v38 - 2 + 2i64) : v43 + 8i64 * v38);
      v46 = (*v45 - *(double *)(32i64 * v37 + ((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0 + 8i64 * v37))
          / (*v44
           * 2.0);
      *(double *)v6 = v46 * v46 + 1.0;
      v47 = sqrt(*(double *)v6);
      v48 = v46 < 0.0 ? 1.0 / (v46 - v47) : 1.0 / (v47 + v46);
      *(double *)v6 = v48 * v48 + 1.0;
      v49 = *(double *)_xmm / sqrt(*(double *)v6);
      v50 = v49 * v48;
    }
    v51 = 32i64 * v37 + v6 + 32;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = g_vectordConstants[28].xy;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = g_vectordConstants[28].zw;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = g_vectordConstants[29].xy;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = g_vectordConstants[29].zw;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = g_vectordConstants[30].xy;
    *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70) = g_vectordConstants[30].zw;
    *(double *)(v51 + 8i64 * v37) = v49;
    v52 = v42 + v6 + 32;
    *(double *)(v52 + 8i64 * v37) = v50;
    v53 = (__int64 *)(v38 >= 2 ? v51 + 8 * (v38 - 2 + 2i64) : v51 + 8i64 * v38);
    *v53 = *(_QWORD *)&v50 ^ _xmm[0];
    v54 = (double *)(v38 >= 2 ? v52 + 8 * (v38 - 2 + 2i64) : v52 + 8i64 * v38);
    *v54 = v49;
    v55 = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64)
                                                                                     + 0x20);
    v56 = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = v55;
    v57 = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = v56;
    v58 = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = v57;
    v59 = *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = v58;
    *(_OWORD *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = v59;
    hkMatrix3d::transpose((hkMatrix3d *)(v6 + 128));
    hkMatrix3d::mul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32));
    hkMatrix3d::setMul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 128), (hkMatrix3d *)(v6 + 224));
    hkMatrix3d::mul(eigenVec, (hkMatrix3d *)(v6 + 32));
    ++v22;
    v31 = *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120);
    v26 = *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100);
    v60 = _mm_unpacklo_pd(v31, v31).m128d_f64[0];
    *(double *)&v59 = _mm_unpacklo_pd(v26, v26).m128d_f64[0];
    *(double *)&v58 = _mm_unpackhi_pd(v31, v31).m128d_f64[0];
  }
  v61 = eigenVec->m_col0.m_quad.zw;
  v62 = _mm_mul_pd(eigenVec->m_col0.m_quad.xy, eigenVec->m_col0.m_quad.xy);
  v63 = _mm_mul_pd(v61, v61);
  v64 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v62, v62), _mm_unpackhi_pd(v62, v62)), _mm_unpacklo_pd(v63, v63));
  v65 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v64)));
  v66 = _mm_andn_pd(
          _mm_cmple_pd(v64, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v65, v64), v65)),
            _mm_mul_pd(v65, g_vectordConstants[17].xy)));
  v67 = _mm_mul_pd(v66, v61);
  v68 = _mm_mul_pd(v66, eigenVec->m_col0.m_quad.xy);
  eigenVec->m_col0.m_quad.zw = v67;
  eigenVec->m_col0.m_quad.xy = v68;
  v69 = eigenVec->m_col1.m_quad.xy;
  v70 = eigenVec->m_col1.m_quad.zw;
  v71 = _mm_mul_pd(v69, v69);
  v72 = _mm_mul_pd(v70, v70);
  v73 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v71, v71), _mm_unpackhi_pd(v71, v71)), _mm_unpacklo_pd(v72, v72));
  v74 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v73)));
  v75 = _mm_andn_pd(
          _mm_cmple_pd(v73, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v74, v73), v74)),
            _mm_mul_pd(v74, g_vectordConstants[17].xy)));
  eigenVec->m_col1.m_quad.zw = _mm_mul_pd(v75, v70);
  eigenVec->m_col1.m_quad.xy = _mm_mul_pd(v75, v69);
  v76 = eigenVec->m_col2.m_quad.xy;
  v77 = eigenVec->m_col2.m_quad.zw;
  v78 = _mm_mul_pd(v76, v76);
  v79 = _mm_mul_pd(v77, v77);
  v80 = _mm_add_pd(_mm_add_pd(_mm_unpacklo_pd(v78, v78), _mm_unpackhi_pd(v78, v78)), _mm_unpacklo_pd(v79, v79));
  v81 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v80)));
  v82 = result;
  v83 = _mm_andn_pd(
          _mm_cmple_pd(v80, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v81, v80), v81)),
            _mm_mul_pd(v81, g_vectordConstants[17].xy)));
  eigenVec->m_col2.m_quad.zw = _mm_mul_pd(v83, v77);
  eigenVec->m_col2.m_quad.xy = _mm_mul_pd(v83, v76);
  eigenVal->m_quad.xy = _mm_unpacklo_pd(
                          _mm_unpacklo_pd(
                            *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0),
                            *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0)),
                          _mm_unpackhi_pd(v26, v26));
  eigenVal->m_quad.zw = _mm_unpacklo_pd(
                          *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130),
                          *(__m128d *)(((unsigned __int64)v84 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130));
  result->m_enum = i > v34;
  return v82;
}

// File Line: 450
// RVA: 0xC8CC20
void __fastcall hkMatrix3d::diagonalizeSymmetricApproximation(
        hkMatrix3d *this,
        hkRotationd *eigenVec,
        hkVector4d *eigenVal,
        int maxIter)
{
  unsigned __int64 v4; // rbp
  __m128d xy; // xmm1
  __m128d v6; // xmm9
  int v7; // r14d
  __m128d v11; // xmm7
  __m128d zw; // xmm8
  __m128d v13; // xmm0
  __m128d v14; // xmm0
  __m128d v15; // xmm2
  __m128d v16; // xmm1
  __m128d v17; // xmm5
  __m128d v18; // xmm3
  __m128d v19; // xmm6
  double v20; // xmm11_8
  __int64 v21; // xmm0_8
  double v22; // xmm2_8
  int v23; // edx
  int v24; // r8d
  double v25; // xmm3_8
  double v26; // xmm2_8
  double v27; // xmm3_8
  double v28; // xmm1_8
  __int64 v29; // r11
  unsigned __int64 v30; // r9
  double *v31; // rsi
  __int64 v32; // rbx
  double v33; // xmm1_8
  double v34; // xmm3_8
  double v35; // xmm2_8
  unsigned __int64 v36; // rsi
  double v37; // xmm4_8
  double v38; // xmm3_8
  double v39; // xmm4_8
  unsigned __int64 v40; // rdi
  __int64 *v41; // rax
  double *v42; // rax
  unsigned __int64 v43; // rbx
  unsigned __int64 v44; // r11
  double *v45; // rax
  double *v46; // rax
  __int64 v47[4]; // [rsp+40h] [rbp+0h] BYREF

  v4 = (unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64;
  xy = this->m_col2.m_quad.xy;
  v6 = this->m_col0.m_quad.xy;
  v7 = 0;
  v11 = this->m_col1.m_quad.xy;
  zw = this->m_col2.m_quad.zw;
  *(__m128d *)(v4 + 48) = this->m_col0.m_quad.zw;
  v13 = this->m_col1.m_quad.zw;
  *(__m128d *)(v4 + 96) = xy;
  *(__m128d *)(v4 + 32) = v6;
  *(__m128d *)(v4 + 80) = v13;
  *(__m128d *)(v4 + 64) = v11;
  eigenVec->m_col0.m_quad.xy = g_vectordConstants[28].xy;
  *(__m128d *)(v4 + 112) = zw;
  eigenVec->m_col0.m_quad.zw = g_vectordConstants[28].zw;
  eigenVec->m_col1.m_quad = g_vectordConstants[29];
  eigenVec->m_col2.m_quad = g_vectordConstants[30];
  v14 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v15 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v16 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v17 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v18 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  v19 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  *(double *)v4 = _mm_unpacklo_pd(v14, v14).m128d_f64[0]
                + _mm_unpackhi_pd(v14, v14).m128d_f64[0]
                + _mm_unpacklo_pd(v16, v16).m128d_f64[0]
                + _mm_unpacklo_pd(v15, v15).m128d_f64[0]
                + _mm_unpackhi_pd(v15, v15).m128d_f64[0]
                + _mm_unpacklo_pd(v18, v18).m128d_f64[0]
                + _mm_unpacklo_pd(v17, v17).m128d_f64[0]
                + _mm_unpackhi_pd(v17, v17).m128d_f64[0]
                + _mm_unpacklo_pd(v19, v19).m128d_f64[0];
  v20 = *(double *)((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) * 4.930380657631324e-32;
  if ( maxIter > 0 )
  {
    do
    {
      v21 = *(_QWORD *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
      *(long double *)v4 = v11.m128d_f64[0];
      v22 = *(double *)v4;
      v23 = 0;
      v24 = 1;
      *(_QWORD *)v4 = v21;
      v25 = *(double *)v4;
      *(_QWORD *)v4 = *(_QWORD *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x68);
      *(_QWORD *)&v26 = (unsigned __int64)(2i64 * *(_QWORD *)&v22) >> 1;
      *(_QWORD *)&v27 = (unsigned __int64)(2i64 * *(_QWORD *)&v25) >> 1;
      *(_QWORD *)&v28 = (unsigned __int64)(2i64 * *(_QWORD *)v4) >> 1;
      if ( v27 > v26 )
      {
        v24 = 2;
        v26 = v27;
      }
      if ( v28 <= v26 )
      {
        v28 = v26;
      }
      else
      {
        v23 = 1;
        v24 = 2;
      }
      if ( v28 * v28 < v20 )
        break;
      v29 = 32i64 * v24;
      v30 = v29 + v4 + 32;
      v31 = (double *)(v24 >= 2 ? v30 + 8 * (v24 - 2 + 2i64) : v30 + 8i64 * v24);
      v32 = 32i64 * v23;
      v33 = (*v31 - *(double *)(v32 + v4 + 32 + 8i64 * v23)) / (*(double *)(v30 + 8i64 * v23) * 2.0);
      *(double *)v4 = v33 * v33 + 1.0;
      v34 = sqrt(*(double *)v4);
      v35 = v33 < 0.0 ? 1.0 / (v33 - v34) : 1.0 / (v34 + v33);
      v36 = v32 + v4 + 128;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = g_vectordConstants[28].zw;
      *(double *)v4 = v35 * v35 + 1.0;
      v37 = sqrt(*(double *)v4);
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = g_vectordConstants[30].zw;
      v38 = *(double *)_xmm / v37;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = g_vectordConstants[30].xy;
      v39 = *(double *)_xmm / v37 * v35;
      *(double *)(v36 + 8i64 * v23) = v38;
      v40 = v29 + v4 + 128;
      *(double *)(v40 + 8i64 * v23) = v39;
      v41 = (__int64 *)(v24 >= 2 ? v36 + 8 * (v24 - 2 + 2i64) : v36 + 8i64 * v24);
      *v41 = *(_QWORD *)&v39 ^ _xmm[0];
      v42 = (double *)(v24 >= 2 ? v40 + 8 * (v24 - 2 + 2i64) : v40 + 8i64 * v24);
      *v42 = v38;
      v43 = v4 + 224 + v32;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x110) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130) = g_vectordConstants[30].zw;
      *(double *)(v43 + 8i64 * v23) = v38;
      v44 = v4 + 224 + v29;
      *(_QWORD *)(v44 + 8i64 * v23) = *(_QWORD *)&v39 ^ _xmm[0];
      v45 = (double *)(v24 >= 2 ? v43 + 8 * (v24 - 2 + 2i64) : v43 + 8i64 * v24);
      *v45 = v39;
      v46 = (double *)(v24 >= 2 ? v44 + 8 * (v24 - 2 + 2i64) : v44 + 8i64 * v24);
      *v46 = v38;
      hkMatrix3d::mul((hkMatrix3d *)(v4 + 32), (hkMatrix3d *)(v4 + 128));
      hkMatrix3d::setMul((hkMatrix3d *)(v4 + 32), (hkMatrix3d *)(v4 + 224), (hkMatrix3d *)(v4 + 32));
      hkMatrix3d::mul(eigenVec, (hkMatrix3d *)(v4 + 128));
      ++v7;
      v11 = *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    }
    while ( v7 < maxIter );
    v6 = *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    zw = *(__m128d *)(((unsigned __int64)v47 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
  }
  eigenVal->m_quad.zw = _mm_unpacklo_pd(zw, zw);
  eigenVal->m_quad.xy = _mm_unpacklo_pd(_mm_unpacklo_pd(v6, v6), _mm_unpackhi_pd(v11, v11));
}

