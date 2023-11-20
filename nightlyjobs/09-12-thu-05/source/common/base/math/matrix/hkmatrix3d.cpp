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
    && _mm_movemask_pd(_mm_cmpord_pd(this->m_col0.m_quad.zw, (__m128d)0i64)) & 1;
  v2 = v1 != 0;
  v3 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col1.m_quad.xy, (__m128d)0i64))
    && _mm_movemask_pd(_mm_cmpord_pd(this->m_col1.m_quad.zw, (__m128d)0i64)) & 1;
  v4 = v3 != 0;
  v5 = !_mm_movemask_pd(_mm_cmpunord_pd(this->m_col2.m_quad.xy, (__m128d)0i64))
    && _mm_movemask_pd(_mm_cmpord_pd(this->m_col2.m_quad.zw, (__m128d)0i64)) & 1;
  return v2 && v4 && v5;
}

// File Line: 37
// RVA: 0xC8B330
void __fastcall hkMatrix3d::transpose(hkMatrix3d *this)
{
  __m128d v1; // xmm1
  __m128d v2; // xmm3
  __m128d v3; // xmm0
  __m128d v4; // xmm0
  __m128d v5; // xmm3
  __m128d v6; // xmm1

  v1 = this->m_col1.m_quad.xy;
  v2 = this->m_col0.m_quad.zw;
  v3 = this->m_col0.m_quad.xy;
  this->m_col0.m_quad.xy = _mm_unpckl_pd(this->m_col0.m_quad.xy, v1);
  v4 = _mm_unpckh_pd(v3, v1);
  v5 = _mm_unpckl_pd(v2, this->m_col1.m_quad.zw);
  v6 = this->m_col2.m_quad.xy;
  this->m_col1.m_quad.xy = v4;
  this->m_col2.m_quad.zw = _mm_unpckl_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  this->m_col2.m_quad.xy = v5;
  this->m_col0.m_quad.zw = _mm_unpckl_pd(v6, (__m128d)0i64);
  this->m_col1.m_quad.zw = _mm_unpckh_pd(v6, (__m128d)0i64);
}

// File Line: 42
// RVA: 0xC8D190
void __fastcall hkMatrix3d_setMulMat3Mat3(hkMatrix3d *THIS, hkMatrix3d *aTb, hkMatrix3d *bTc)
{
  __m128d v3; // xmm7
  __m128d v4; // xmm8
  __m128d v5; // xmm9
  __m128d *v6; // rax
  signed __int64 v7; // rcx
  __m128d v8; // xmm10
  __m128d v9; // xmm11
  __m128d v10; // xmm12
  signed __int64 v11; // rdx
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm4
  __m128d v15; // xmm6
  __m128d v16; // xmm5

  v3 = aTb->m_col0.m_quad.xy;
  v4 = aTb->m_col0.m_quad.zw;
  v5 = aTb->m_col1.m_quad.xy;
  v6 = &bTc->m_col2.m_quad.xy;
  v7 = (char *)THIS - (char *)bTc;
  v8 = aTb->m_col1.m_quad.zw;
  v9 = aTb->m_col2.m_quad.xy;
  v10 = aTb->m_col2.m_quad.zw;
  v11 = 2i64;
  do
  {
    v12 = *v6;
    v13 = v6[1];
    v6 -= 2;
    --v11;
    v14 = _mm_unpckl_pd(v13, v13);
    v15 = _mm_unpckl_pd(v12, v12);
    v16 = _mm_unpckh_pd(v12, v12);
    *(__m128d *)((char *)v6 + v7 + 32) = _mm_add_pd(
                                           _mm_add_pd(_mm_mul_pd(v5, v16), _mm_mul_pd(v3, v15)),
                                           _mm_mul_pd(v9, v14));
    *(__m128d *)((char *)v6 + v7 + 48) = _mm_add_pd(
                                           _mm_add_pd(_mm_mul_pd(v8, v16), _mm_mul_pd(v4, v15)),
                                           _mm_mul_pd(v10, v14));
  }
  while ( v11 >= 0 );
}

// File Line: 49
// RVA: 0xC8D2A0
void __fastcall hkMatrix3d_invertSymmetric(hkMatrix3d *thisMatrix)
{
  hkMatrix3d::invertSymmetric(thisMatrix);
}

// File Line: 56
// RVA: 0xC8B3A0
void __fastcall hkMatrix3d::setTranspose(hkMatrix3d *this, hkMatrix3d *s)
{
  __m128d v2; // xmm3
  __m128d v3; // xmm6
  __m128d v4; // xmm2
  __m128d v5; // xmm0
  __m128d v6; // xmm5

  v2 = s->m_col2.m_quad.xy;
  v3 = _mm_unpckl_pd(s->m_col0.m_quad.zw, s->m_col1.m_quad.zw);
  v4 = _mm_unpckh_pd(s->m_col0.m_quad.xy, s->m_col1.m_quad.xy);
  v5 = _mm_unpckl_pd(s->m_col2.m_quad.xy, (__m128d)0i64);
  v6 = _mm_unpckl_pd(s->m_col2.m_quad.zw, (__m128d)0i64);
  this->m_col0.m_quad.xy = _mm_unpckl_pd(s->m_col0.m_quad.xy, s->m_col1.m_quad.xy);
  this->m_col2.m_quad.xy = v3;
  this->m_col0.m_quad.zw = v5;
  this->m_col1.m_quad.xy = v4;
  this->m_col2.m_quad.zw = v6;
  this->m_col1.m_quad.zw = _mm_unpckh_pd(v2, (__m128d)0i64);
}

// File Line: 62
// RVA: 0xC8B420
void __fastcall hkMatrix3d::setMul(hkMatrix3d *this, hkMatrix3d *aTb, hkMatrix3d *bTc)
{
  __m128d v3; // xmm7
  __m128d v4; // xmm8
  __m128d v5; // xmm9
  __m128d *v6; // rax
  signed __int64 v7; // rcx
  __m128d v8; // xmm10
  __m128d v9; // xmm11
  __m128d v10; // xmm12
  signed __int64 v11; // rdx
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm4
  __m128d v15; // xmm6
  __m128d v16; // xmm5

  v3 = aTb->m_col0.m_quad.xy;
  v4 = aTb->m_col0.m_quad.zw;
  v5 = aTb->m_col1.m_quad.xy;
  v6 = &bTc->m_col2.m_quad.xy;
  v7 = (char *)this - (char *)bTc;
  v8 = aTb->m_col1.m_quad.zw;
  v9 = aTb->m_col2.m_quad.xy;
  v10 = aTb->m_col2.m_quad.zw;
  v11 = 2i64;
  do
  {
    v12 = *v6;
    v13 = v6[1];
    v6 -= 2;
    --v11;
    v14 = _mm_unpckl_pd(v13, v13);
    v15 = _mm_unpckl_pd(v12, v12);
    v16 = _mm_unpckh_pd(v12, v12);
    *(__m128d *)((char *)v6 + v7 + 32) = _mm_add_pd(
                                           _mm_add_pd(_mm_mul_pd(v5, v16), _mm_mul_pd(v3, v15)),
                                           _mm_mul_pd(v9, v14));
    *(__m128d *)((char *)v6 + v7 + 48) = _mm_add_pd(
                                           _mm_add_pd(_mm_mul_pd(v8, v16), _mm_mul_pd(v4, v15)),
                                           _mm_mul_pd(v10, v14));
  }
  while ( v11 >= 0 );
}

// File Line: 68
// RVA: 0xC8BAF0
void __fastcall hkMatrix3d::changeBasis(hkMatrix3d *this, hkRotationd *r)
{
  hkRotationd *v2; // rbx
  hkMatrix3d *v3; // rdi
  hkMatrix3d bTc; // [rsp+40h] [rbp+0h]

  v2 = r;
  v3 = this;
  hkMatrix3d::setMulInverse((hkMatrix3d *)((unsigned __int64)&bTc & 0xFFFFFFFFFFFFFFE0ui64), this, r);
  hkMatrix3d::setMul(v3, (hkMatrix3d *)&v2->m_col0, (hkMatrix3d *)((unsigned __int64)&bTc & 0xFFFFFFFFFFFFFFE0ui64));
}

// File Line: 75
// RVA: 0xC8B530
void __fastcall hkMatrix3d::setMulInverse(hkMatrix3d *this, hkMatrix3d *aTb, hkRotationd *cTb)
{
  unsigned __int64 v3; // rbp
  __m128d v4; // xmm3
  signed __int64 v5; // rax
  __m128d v6; // xmm6
  __m128d v7; // xmm7
  __m128d v8; // xmm8
  __m128d v9; // xmm5
  __m128d v10; // xmm9
  __m128d v11; // xmm10
  __m128d v12; // xmm11
  __m128d v13; // xmm12
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
  __int128 v25; // [rsp+20h] [rbp+0h]

  v3 = (unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = cTb->m_col2.m_quad.xy;
  v5 = -16i64;
  v6 = _mm_unpckl_pd(cTb->m_col0.m_quad.zw, cTb->m_col1.m_quad.zw);
  v7 = aTb->m_col0.m_quad.xy;
  v8 = aTb->m_col0.m_quad.zw;
  v9 = _mm_unpckl_pd(cTb->m_col2.m_quad.zw, (__m128d)0i64);
  v10 = aTb->m_col1.m_quad.xy;
  v11 = aTb->m_col1.m_quad.zw;
  v12 = aTb->m_col2.m_quad.xy;
  v13 = aTb->m_col2.m_quad.zw;
  v14 = _mm_unpckh_pd(cTb->m_col0.m_quad.xy, cTb->m_col1.m_quad.xy);
  *(__m128d *)v3 = _mm_unpckl_pd(cTb->m_col0.m_quad.xy, cTb->m_col1.m_quad.xy);
  *(__m128d *)(v3 + 48) = _mm_unpckh_pd(v4, (__m128d)0i64);
  *(__m128d *)(v3 + 64) = v6;
  *(__m128d *)(v3 + 32) = v14;
  *(__m128d *)(v3 + 16) = _mm_unpckl_pd(v4, (__m128d)0i64);
  *(__m128d *)(v3 + 80) = v9;
  do
  {
    v15 = *(__m128d *)(v3 + 80 + v5);
    v16 = *(__m128d *)(v3 + 96 + v5);
    v5 -= 32i64;
    v17 = _mm_unpckl_pd(v16, v16);
    v18 = _mm_unpckl_pd(v15, v15);
    v19 = _mm_unpckh_pd(v15, v15);
    *(__m128d *)(v3 + 208 + v5) = _mm_add_pd(
                                    _mm_add_pd(_mm_mul_pd(v10, v19), _mm_mul_pd(v7, v18)),
                                    _mm_mul_pd(v12, v17));
    *(__m128d *)(v3 + 224 + v5) = _mm_add_pd(
                                    _mm_add_pd(_mm_mul_pd(v11, v19), _mm_mul_pd(v8, v18)),
                                    _mm_mul_pd(v13, v17));
  }
  while ( v5 >= -80 );
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
  signed __int64 v4; // rax
  __m128d v5; // xmm11
  __m128d v6; // xmm10
  __m128d v7; // xmm6
  __m128d v8; // xmm7
  __m128d v9; // xmm8
  __m128d v10; // xmm10
  __m128d v11; // xmm9
  __m128d v12; // xmm5
  __m128d v13; // xmm4
  __m128d v14; // xmm4
  __m128d v15; // xmm3
  __m128d v16; // xmm5

  v3 = (char *)bTc - (char *)this;
  v4 = 3i64;
  v5 = _mm_unpckl_pd(bTa->m_col0.m_quad.zw, bTa->m_col1.m_quad.zw);
  v6 = bTa->m_col2.m_quad.xy;
  v7 = _mm_unpckl_pd(bTa->m_col0.m_quad.xy, bTa->m_col1.m_quad.xy);
  v8 = _mm_unpckh_pd(v6, (__m128d)0i64);
  v9 = _mm_unpckh_pd(bTa->m_col0.m_quad.xy, bTa->m_col1.m_quad.xy);
  v10 = _mm_unpckl_pd(v6, (__m128d)0i64);
  v11 = _mm_unpckl_pd(bTa->m_col2.m_quad.zw, (__m128d)0i64);
  do
  {
    v12 = *(__m128d *)((char *)&this->m_col0.m_quad.xy + v3);
    v13 = *(__m128d *)((char *)&this->m_col0.m_quad.zw + v3);
    this = (hkMatrix3d *)((char *)this + 32);
    v14 = _mm_unpckl_pd(v13, v13);
    v15 = _mm_unpckl_pd(v12, v12);
    v16 = _mm_unpckh_pd(v12, v12);
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
  __m128d v3; // xmm0
  __m128d v4; // xmm8
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
  __m128d v21; // xmm13
  __m128d v22; // xmm8

  v3 = b->m_col0.m_quad.zw;
  v4 = a->m_col1.m_quad.xy;
  v5 = a->m_col2.m_quad.xy;
  v6 = a->m_col0.m_quad.zw;
  v7 = _mm_mul_pd(a->m_col2.m_quad.xy, b->m_col0.m_quad.xy);
  v8 = _mm_mul_pd(a->m_col0.m_quad.xy, b->m_col0.m_quad.xy);
  v9 = _mm_mul_pd(a->m_col2.m_quad.zw, v3);
  v10 = _mm_mul_pd(a->m_col1.m_quad.xy, b->m_col0.m_quad.xy);
  v11 = _mm_add_pd(
          _mm_add_pd(_mm_unpckl_pd(v8, v10), _mm_unpckh_pd(v8, v10)),
          _mm_unpckl_pd(_mm_mul_pd(b->m_col0.m_quad.zw, v6), _mm_mul_pd(a->m_col1.m_quad.zw, v3)));
  v12 = _mm_mul_pd(b->m_col1.m_quad.xy, a->m_col0.m_quad.xy);
  v13 = _mm_unpckl_pd(_mm_mul_pd(a->m_col2.m_quad.zw, b->m_col1.m_quad.zw), (__m128d)0i64);
  v14 = _mm_mul_pd(b->m_col1.m_quad.xy, v4);
  v15 = _mm_mul_pd(b->m_col1.m_quad.xy, v5);
  v16 = _mm_unpckl_pd(_mm_mul_pd(v6, b->m_col2.m_quad.zw), _mm_mul_pd(a->m_col1.m_quad.zw, b->m_col2.m_quad.zw));
  v17 = _mm_add_pd(
          _mm_add_pd(_mm_unpckl_pd(v12, v14), _mm_unpckh_pd(v12, v14)),
          _mm_unpckl_pd(
            _mm_mul_pd(a->m_col0.m_quad.zw, b->m_col1.m_quad.zw),
            _mm_mul_pd(a->m_col1.m_quad.zw, b->m_col1.m_quad.zw)));
  v18 = _mm_unpckl_pd(_mm_mul_pd(a->m_col2.m_quad.zw, b->m_col2.m_quad.zw), (__m128d)0i64);
  v19 = b->m_col2.m_quad.xy;
  v20 = _mm_mul_pd(a->m_col0.m_quad.xy, v19);
  v21 = _mm_mul_pd(v5, v19);
  this->m_col0.m_quad.xy = v11;
  this->m_col1.m_quad.xy = v17;
  this->m_col0.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpckh_pd(v7, (__m128d)0i64), _mm_unpckl_pd(v7, (__m128d)0i64)),
                             _mm_unpckl_pd(v9, (__m128d)0i64));
  v22 = _mm_mul_pd(v4, v19);
  this->m_col1.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpckh_pd(v15, (__m128d)0i64), _mm_unpckl_pd(v15, (__m128d)0i64)),
                             v13);
  this->m_col2.m_quad.xy = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v20, v22), _mm_unpckh_pd(v20, v22)), v16);
  this->m_col2.m_quad.zw = _mm_add_pd(
                             _mm_add_pd(_mm_unpckh_pd(v21, (__m128d)0i64), _mm_unpckl_pd(v21, (__m128d)0i64)),
                             v18);
}

// File Line: 94
// RVA: 0xC8BC80
void __fastcall hkMatrix3d::mul(hkMatrix3d *this, hkSimdDouble64 *scale)
{
  __m128d v2; // xmm1
  __m128d v3; // xmm1
  __m128d v4; // xmm1

  v2 = this->m_col0.m_quad.zw;
  this->m_col0.m_quad.xy = _mm_mul_pd(scale->m_real, this->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_mul_pd(v2, scale->m_real);
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
  __m128d v2; // xmm4
  __m128d v3; // xmm2
  __m128d v4; // xmm3
  __m128d v5; // xmm4

  v2 = r->m_quad.xy;
  v3 = _mm_unpckl_pd(r->m_quad.zw, r->m_quad.zw);
  v4 = _mm_unpckl_pd(v2, v2);
  v5 = _mm_unpckh_pd(v2, v2);
  this->m_col0.m_quad.xy = _mm_unpckl_pd((__m128d)0i64, v3);
  this->m_col0.m_quad.zw = _mm_unpckl_pd(_mm_sub_pd((__m128d)0i64, v5), (__m128d)0i64);
  this->m_col1.m_quad.xy = _mm_unpckl_pd(_mm_sub_pd((__m128d)0i64, v3), (__m128d)0i64);
  this->m_col1.m_quad.zw = _mm_unpckl_pd(v4, (__m128d)0i64);
  this->m_col2.m_quad.xy = _mm_unpckl_pd(v5, _mm_sub_pd((__m128d)0i64, v4));
  this->m_col2.m_quad.zw = _mm_unpckl_pd((__m128d)0i64, (__m128d)0i64);
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
int hkMatrix3d::isApproximatelyEqual(...)
{
  __m128d v4; // xmm3

  a4.m128d_f64[0] = zero;
  v4 = _mm_shuffle_pd(a4, a4, 0);
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
  __m128d v3; // xmm2

  v3 = eps->m_real;
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
                                v3)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     this->m_col1.m_quad.zw,
                                                                                     m->m_col1.m_quad.zw),
                                                                          1u),
                                                                        1u),
                                                             v3)))) & 7) == 7
      && (((unsigned __int8)_mm_movemask_pd(
                              _mm_cmplt_pd(
                                (__m128d)_mm_srli_epi64(
                                           _mm_slli_epi64(
                                             (__m128i)_mm_sub_pd(this->m_col2.m_quad.xy, m->m_col2.m_quad.xy),
                                             1u),
                                           1u),
                                v3)) | (unsigned __int8)(4
                                                       * _mm_movemask_pd(
                                                           _mm_cmplt_pd(
                                                             (__m128d)_mm_srli_epi64(
                                                                        _mm_slli_epi64(
                                                                          (__m128i)_mm_sub_pd(
                                                                                     this->m_col2.m_quad.zw,
                                                                                     m->m_col2.m_quad.zw),
                                                                          1u),
                                                                        1u),
                                                             v3)))) & 7) == 7;
}

// File Line: 152
// RVA: 0xC8AC70
bool __fastcall hkMatrix3d::isSymmetric(hkMatrix3d *this, long double epsilon)
{
  __m128d v2; // xmm3
  unsigned __int64 v3; // rdx
  __m128d v4; // xmm6
  __m128d v5; // xmm2
  __m128d v6; // xmm0
  __m128d v7; // xmm5
  hkMatrix3d m; // [rsp+40h] [rbp+0h]

  v2 = this->m_col2.m_quad.xy;
  v3 = (unsigned __int64)&m & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = _mm_unpckl_pd(this->m_col0.m_quad.zw, this->m_col1.m_quad.zw);
  v5 = _mm_unpckh_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v6 = _mm_unpckl_pd(this->m_col2.m_quad.xy, (__m128d)0i64);
  v7 = _mm_unpckl_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  *(__m128d *)v3 = _mm_unpckl_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  *(__m128d *)(v3 + 48) = _mm_unpckh_pd(v2, (__m128d)0i64);
  *(__m128d *)(v3 + 64) = v4;
  *(__m128d *)(v3 + 32) = v5;
  *(__m128d *)(v3 + 16) = v6;
  *(__m128d *)(v3 + 80) = v7;
  return hkMatrix3d::isApproximatelyEqual(this, (hkMatrix3d *)((unsigned __int64)&m & 0xFFFFFFFFFFFFFFE0ui64), epsilon);
}

// File Line: 159
// RVA: 0xC8AD90
hkResult *__fastcall hkMatrix3d::invert(hkMatrix3d *this, hkResult *result, long double epsilon)
{
  unsigned __int64 v3; // rbp
  __m128d v4; // xmm5
  __m128d v5; // xmm7
  __m128d v6; // xmm11
  double v7; // xmm14_8
  hkResult *v8; // rbx
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
  __int128 v39; // [rsp+40h] [rbp+0h]

  v3 = (unsigned __int64)&v39 & 0xFFFFFFFFFFFFFFE0ui64;
  v4 = this->m_col2.m_quad.xy;
  v5 = this->m_col2.m_quad.zw;
  v6 = this->m_col1.m_quad.xy;
  v7 = epsilon;
  v8 = result;
  v9 = this->m_col1.m_quad.zw;
  v10 = this->m_col0.m_quad.xy;
  v11 = this->m_col0.m_quad.zw;
  v12 = _mm_shuffle_pd(this->m_col2.m_quad.xy, v5, 2);
  v13 = _mm_shuffle_pd(v4, v5, 1);
  v14 = _mm_shuffle_pd(this->m_col0.m_quad.xy, v11, 1);
  v15 = _mm_shuffle_pd(this->m_col0.m_quad.xy, v11, 2);
  v16 = _mm_shuffle_pd(this->m_col1.m_quad.xy, v9, 1);
  v17 = _mm_shuffle_pd(this->m_col1.m_quad.xy, v9, 2);
  v18 = _mm_sub_pd(_mm_mul_pd(v6, v13), _mm_mul_pd(v16, v4));
  v19 = _mm_sub_pd(_mm_mul_pd(v12, v9), _mm_mul_pd(v17, v5));
  v20 = _mm_shuffle_pd(v18, v19, 1);
  v21 = _mm_shuffle_pd(v18, v19, 2);
  *(__m128d *)(v3 + 32) = v20;
  v22 = _mm_mul_pd(v15, v5);
  v23 = _mm_mul_pd(v15, v9);
  *(__m128d *)v3 = _mm_mul_pd(v14, v4);
  v24 = _mm_sub_pd(*(__m128d *)((unsigned __int64)&v39 & 0xFFFFFFFFFFFFFFE0ui64), _mm_mul_pd(v10, v13));
  v25 = _mm_sub_pd(v22, _mm_mul_pd(v11, v12));
  v26 = _mm_sub_pd(_mm_mul_pd(v10, v16), _mm_mul_pd(v14, v6));
  v27 = _mm_shuffle_pd(v24, v25, 1);
  v28 = *(__m128d *)(((unsigned __int64)&v39 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  v29 = _mm_sub_pd(_mm_mul_pd(v11, v17), v23);
  v23.m128d_f64[0] = v7;
  v30 = _mm_mul_pd(v10, v28);
  *(_QWORD *)&v23.m128d_f64[0] = (unsigned __int128)_mm_shuffle_pd(v23, v23, 0);
  v31 = _mm_shuffle_pd(v24, v25, 2);
  v32 = _mm_shuffle_pd(v26, v29, 1);
  v33 = _mm_shuffle_pd(v26, v29, 2);
  v34 = _mm_mul_pd(v11, v21);
  v35 = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v30, v30), _mm_unpckh_pd(v30, v30)), _mm_unpckl_pd(v34, v34));
  if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)&v35.m128d_f64[0]) >> 1) <= v23.m128d_f64[0]
                                                                                    * v23.m128d_f64[0]
                                                                                    * v23.m128d_f64[0] )
  {
    result->m_enum = 1;
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
    v8->m_enum = 0;
  }
  return v8;
}

// File Line: 182
// RVA: 0xC8B020
void __fastcall hkMatrix3d::invertSymmetric(hkMatrix3d *this)
{
  __m128d v1; // xmm2
  __m128d v2; // xmm6
  __m128d v3; // xmm10
  __m128d v4; // xmm12
  __m128d v5; // xmm9
  __m128d v6; // xmm11
  __m128d v7; // xmm4
  __m128d v8; // xmm5
  __m128d v9; // xmm8
  __m128d v10; // xmm3
  __m128d v11; // xmm7
  __m128d v12; // xmm13
  __m128d v13; // xmm1
  __m128d v14; // xmm0
  __m128d v15; // xmm15
  __m128d v16; // xmm3
  __m128d v17; // xmm13
  __m128d v18; // xmm14
  __m128d v19; // xmm2
  __m128d v20; // xmm9
  __m128d v21; // xmm1
  __m128d v22; // xmm0
  __m128d v23; // xmm5
  __m128d v24; // xmm13
  __m128d v25; // xmm11
  __m128d v26; // xmm0
  __m128d v27; // xmm4
  __m128d v28; // xmm3
  __m128d v29; // xmm2
  __m128d v30; // xmm0
  __m128d v31; // xmm7
  __int128 v32; // [rsp+20h] [rbp+0h]

  v1 = this->m_col2.m_quad.xy;
  v2 = this->m_col2.m_quad.zw;
  v3 = this->m_col1.m_quad.xy;
  v4 = this->m_col1.m_quad.zw;
  v5 = this->m_col0.m_quad.xy;
  v6 = this->m_col0.m_quad.zw;
  v7 = _mm_shuffle_pd(this->m_col2.m_quad.xy, v2, 2);
  v8 = _mm_shuffle_pd(v1, v2, 1);
  v9 = _mm_shuffle_pd(this->m_col1.m_quad.xy, v4, 1);
  v10 = _mm_sub_pd(_mm_mul_pd(this->m_col1.m_quad.xy, v8), _mm_mul_pd(v9, v1));
  v11 = _mm_shuffle_pd(this->m_col1.m_quad.xy, v4, 2);
  v12 = _mm_mul_pd(this->m_col0.m_quad.xy, v9);
  v13 = _mm_sub_pd(_mm_mul_pd(v7, v4), _mm_mul_pd(v11, v2));
  v14 = _mm_mul_pd(this->m_col0.m_quad.xy, v8);
  v15 = _mm_shuffle_pd(v10, v13, 1);
  *(__m128d *)((unsigned __int64)&v32 & 0xFFFFFFFFFFFFFFE0ui64) = _mm_shuffle_pd(v10, v13, 2);
  v16 = _mm_shuffle_pd(v5, v6, 1);
  v17 = _mm_sub_pd(v12, _mm_mul_pd(v16, v3));
  v18 = _mm_sub_pd(_mm_mul_pd(v16, v1), v14);
  v19 = _mm_shuffle_pd(v5, v6, 2);
  v20 = _mm_mul_pd(v5, v15);
  v21 = _mm_sub_pd(_mm_mul_pd(v19, v2), _mm_mul_pd(v6, v7));
  v22 = _mm_sub_pd(_mm_mul_pd(v6, v11), _mm_mul_pd(v19, v4));
  v23 = _mm_shuffle_pd(v17, v22, 1);
  v24 = _mm_shuffle_pd(v17, v22, 2);
  v25 = _mm_mul_pd(v6, *(__m128d *)((unsigned __int64)&v32 & 0xFFFFFFFFFFFFFFE0ui64));
  v26 = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v20, v20), _mm_unpckh_pd(v20, v20)), _mm_unpckl_pd(v25, v25));
  v27 = _mm_cmplt_pd(
          _mm_mul_pd(_mm_mul_pd(g_vectordConstants[34].xy, g_vectordConstants[34].xy), g_vectordConstants[34].xy),
          v26);
  v28 = _mm_or_pd(_mm_and_pd(v27, v26), _mm_andn_pd(v27, g_vectordConstants[2].xy));
  v29 = _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps(v28)));
  v30 = _mm_and_pd(_mm_mul_pd(_mm_sub_pd(g_vectordConstants[3].xy, _mm_mul_pd(v28, v29)), v29), v27);
  v31 = _mm_mul_pd(*(__m128d *)((unsigned __int64)&v32 & 0xFFFFFFFFFFFFFFE0ui64), v30);
  this->m_col0.m_quad.xy = _mm_mul_pd(v15, v30);
  this->m_col0.m_quad.zw = v31;
  this->m_col1.m_quad.xy = _mm_mul_pd(_mm_shuffle_pd(v18, v21, 1), v30);
  this->m_col1.m_quad.zw = _mm_mul_pd(_mm_shuffle_pd(v18, v21, 2), v30);
  this->m_col2.m_quad.xy = _mm_mul_pd(v23, v30);
  this->m_col2.m_quad.zw = _mm_mul_pd(v24, v30);
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
  __m128d v2; // xmm1
  __m128d v3; // xmm1
  __m128d v4; // xmm1

  v2 = this->m_col0.m_quad.zw;
  this->m_col0.m_quad.xy = _mm_sub_pd(this->m_col0.m_quad.xy, a->m_col0.m_quad.xy);
  this->m_col0.m_quad.zw = _mm_sub_pd(v2, a->m_col0.m_quad.zw);
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
  hkMatrix3d *v2; // rbx
  __m128d v3; // xmm1
  __m128d v4; // xmm0
  __m128d v5; // xmm1
  __m128d v6; // xmm0
  __m128d v7; // xmm1
  hkMatrix3d v8; // [rsp+40h] [rbp+0h]

  v2 = this;
  hkMatrix3d::setMul((hkMatrix3d *)((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64), this, a);
  v3 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x10);
  v2->m_col0.m_quad.xy = *(__m128d *)((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64);
  v4 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  v2->m_col0.m_quad.zw = v3;
  v5 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
  v2->m_col1.m_quad.xy = v4;
  v6 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
  v2->m_col1.m_quad.zw = v5;
  v7 = *(__m128d *)(((unsigned __int64)&v8 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
  v2->m_col2.m_quad.xy = v6;
  v2->m_col2.m_quad.zw = v7;
}

// File Line: 230
// RVA: 0xC8BD90
hkSimdDouble64 *__fastcall hkMatrix3d::getDeterminant(hkMatrix3d *this, hkSimdDouble64 *result)
{
  __m128d v2; // xmm3
  hkSimdDouble64 *v3; // rax
  __m128d v4; // xmm7
  __m128d v5; // xmm2
  __m128d v6; // xmm4
  __m128d v7; // xmm5
  __m128d v8; // xmm3
  __m128d v9; // xmm6
  __m128d v10; // xmm7
  __m128d v11; // xmm1
  __m128d v12; // xmm6

  v2 = this->m_col2.m_quad.xy;
  v3 = result;
  v4 = _mm_unpckl_pd(this->m_col0.m_quad.zw, this->m_col1.m_quad.zw);
  v5 = _mm_unpckh_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy);
  v6 = _mm_unpckl_pd(this->m_col2.m_quad.zw, (__m128d)0i64);
  v7 = v2;
  v8 = _mm_unpckh_pd(v2, (__m128d)0i64);
  v9 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v4, v6, 1), v5), _mm_mul_pd(_mm_shuffle_pd(v5, v8, 1), v4));
  v10 = _mm_sub_pd(_mm_mul_pd(_mm_shuffle_pd(v4, v6, 2), v8), _mm_mul_pd(_mm_shuffle_pd(v5, v8, 2), v6));
  v11 = _mm_mul_pd(_mm_shuffle_pd(v9, v10, 1), _mm_unpckl_pd(this->m_col0.m_quad.xy, this->m_col1.m_quad.xy));
  v12 = _mm_mul_pd(_mm_shuffle_pd(v9, v10, 2), _mm_unpckl_pd(v7, (__m128d)0i64));
  result->m_real = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v11, v11), _mm_unpckh_pd(v11, v11)), _mm_unpckl_pd(v12, v12));
  return v3;
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
    v5 = &v4->xy.m128d_f64[p - 2 + 2i64];
  else
    v5 = &v4->xy.m128d_f64[p];
  v6 = *v5;
  if ( *v5 == 0.0 )
  {
    *(_QWORD *)&S->c = 4607182418800017408i64;
    *(_QWORD *)&S->p = 0i64;
  }
  else
  {
    if ( q >= 2 )
      v7 = &v4->xy.m128d_f64[q - 2 + 2i64];
    else
      v7 = &v4->xy.m128d_f64[q];
    v8 = &M->m_col0.m_quad + p;
    if ( p >= 2 )
      v9 = &v8->xy.m128d_f64[p - 2 + 2i64];
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
    v5 = &v4->xy.m128d_f64[p - 2 + 2i64];
  else
    v5 = &v4->xy.m128d_f64[p];
  v6 = *v5;
  if ( q >= 2 )
    v7 = &v4->xy.m128d_f64[q - 2 + 2i64];
  else
    v7 = &v4->xy.m128d_f64[q];
  v8 = &M->m_col0.m_quad + p;
  if ( p >= 2 )
    v9 = &v8->xy.m128d_f64[p - 2 + 2i64];
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
                       _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v3, v3), _mm_unpckh_pd(v3, v3)), _mm_unpckl_pd(v4, v4)),
                       _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v5, v5), _mm_unpckh_pd(v5, v5)), _mm_unpckl_pd(v8, v8))),
                     _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v6, v6), _mm_unpckh_pd(v6, v6)), _mm_unpckl_pd(v7, v7)));
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
                       _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v3, v3), _mm_unpckh_pd(v3, v3)), _mm_unpckl_pd(v4, v4)),
                       _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v5, v5), _mm_unpckh_pd(v5, v5)), _mm_unpckl_pd(v8, v8))),
                     _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v6, v6), _mm_unpckh_pd(v6, v6)), _mm_unpckl_pd(v7, v7)));
  return v2;
}

// File Line: 296
// RVA: 0xC8D5D0
hkSimdDouble64 *__fastcall offDiagNormSqr_0(hkSimdDouble64 *result, hkMatrix3d *M)
{
  __m128d v2; // xmm1
  hkSimdDouble64 *v3; // rax
  __m128d v4; // xmm0
  __m128d v5; // xmm2
  __m128d v6; // xmm1

  v2 = M->m_col2.m_quad.xy;
  v3 = result;
  v4 = _mm_unpckl_pd(M->m_col1.m_quad.xy, M->m_col1.m_quad.xy);
  v5 = _mm_unpckl_pd(v2, v2);
  v6 = _mm_unpckh_pd(v2, v2);
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
  hkMatrix3d *v2; // r9
  __int64 v3; // rax
  hkQuadDouble64 *v4; // r8
  char *v5; // rcx
  __int64 v6; // rax
  signed __int64 v7; // r8
  _QWORD *v8; // rcx
  __int64 v9; // rax
  signed __int64 v10; // r8
  double *v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // r8

  v2 = J;
  J->m_col0.m_quad.xy = g_vectordConstants[28].xy;
  J->m_col0.m_quad.zw = g_vectordConstants[28].zw;
  J->m_col1.m_quad.xy = g_vectordConstants[29].xy;
  J->m_col1.m_quad.zw = g_vectordConstants[29].zw;
  J->m_col2.m_quad.xy = g_vectordConstants[30].xy;
  J->m_col2.m_quad.zw = g_vectordConstants[30].zw;
  v3 = SLODWORD(S[1].c);
  v4 = &J->m_col0.m_quad + v3;
  if ( (signed int)v3 >= 2 )
    v5 = (char *)&v4->xy.m128d_f64[(signed int)v3 - 2 + 2i64];
  else
    v5 = (char *)&v4->xy.m128d_f64[v3];
  *(_QWORD *)v5 = *(_QWORD *)&S->c;
  v6 = SLODWORD(S[1].c);
  v7 = (signed __int64)v2 + 32 * SLODWORD(S[1].s);
  if ( (signed int)v6 >= 2 )
    v8 = (_QWORD *)(v7 + 8 * ((signed int)v6 - 2 + 2i64));
  else
    v8 = (_QWORD *)(v7 + 8 * v6);
  *v8 = *(_QWORD *)&S->p;
  v9 = SLODWORD(S[1].s);
  v10 = (signed __int64)v2 + 32 * SLODWORD(S[1].c);
  if ( (signed int)v9 >= 2 )
    v11 = (double *)(v10 + 8 * ((signed int)v9 - 2 + 2i64));
  else
    v11 = (double *)(v10 + 8 * v9);
  *v11 = -*(double *)&S->p;
  v12 = SLODWORD(S[1].s);
  v13 = (signed __int64)v2 + 32 * v12;
  if ( (signed int)v12 >= 2 )
    *(_QWORD *)(v13 + 8i64 * ((signed int)v12 - 2) + 16) = *(_QWORD *)&S->c;
  else
    *(_QWORD *)(v13 + 8i64 * SLODWORD(S[1].s)) = *(_QWORD *)&S->c;
}

// File Line: 343
// RVA: 0xC8BE70
hkResult *__fastcall hkMatrix3d::diagonalizeSymmetric(hkMatrix3d *this, hkResult *result, hkRotationd *eigenVec, hkVector4d *eigenVal, int maxIter, long double epsilon)
{
  unsigned __int64 v6; // rbp
  __m128d v7; // xmm7
  __m128d v8; // xmm8
  int v9; // er14
  hkVector4d *v10; // rax
  hkRotationd *v11; // r13
  hkResult *v12; // r12
  double v13; // xmm6_8
  __m128d v14; // xmm10
  __m128d v15; // xmm9
  __m128d v16; // xmm0
  __m128d v17; // xmm0
  __m128d v18; // xmm2
  __m128d v19; // xmm1
  __m128d v20; // xmm4
  __m128d v21; // xmm3
  double v22; // xmm12_8
  __m128d v23; // xmm5
  long double v24; // xmm12_8
  double v25; // xmm12_8
  double v26; // xmm2_8
  double v27; // xmm0_8
  signed int v28; // edx
  signed int v29; // er8
  double v30; // xmm1_8
  double v31; // xmm1_8
  double v32; // xmm0_8
  signed __int64 v33; // r11
  signed __int64 v34; // r10
  double *v35; // rcx
  double *v36; // rbx
  signed __int64 v37; // r10
  double *v38; // rax
  double v39; // xmm1_8
  double v40; // xmm3_8
  double v41; // xmm2_8
  double v42; // xmm3_8
  double v43; // xmm4_8
  signed __int64 v44; // rsi
  signed __int64 v45; // rdi
  double *v46; // rax
  signed __int64 v47; // rbx
  double *v48; // rax
  __int64 *v49; // rax
  double *v50; // rax
  signed __int64 v51; // rbx
  double *v52; // rax
  signed __int64 v53; // r11
  __int64 *v54; // rax
  double *v55; // rax
  double *v56; // rax
  double v57; // xmm2_8
  double v58; // xmm1_8
  double v59; // xmm0_8
  hkResult *v60; // rax
  __int64 v61; // [rsp+40h] [rbp+0h]
  hkVector4d *v62; // [rsp+238h] [rbp+1F8h]

  v62 = eigenVal;
  v6 = (unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64;
  v7 = this->m_col2.m_quad.xy;
  v8 = this->m_col1.m_quad.xy;
  v9 = 0;
  v10 = eigenVal;
  v11 = eigenVec;
  v12 = result;
  *(_QWORD *)&v13 = (unsigned __int128)_mm_shuffle_pd(
                                         (__m128d)*(unsigned __int64 *)&epsilon,
                                         (__m128d)*(unsigned __int64 *)&epsilon,
                                         0);
  v14 = this->m_col0.m_quad.xy;
  v15 = this->m_col2.m_quad.zw;
  *(__m128d *)(v6 + 48) = this->m_col0.m_quad.zw;
  v16 = this->m_col1.m_quad.zw;
  *(__m128d *)(v6 + 32) = v14;
  *(__m128d *)(v6 + 64) = v8;
  *(__m128d *)(v6 + 80) = v16;
  *(__m128d *)(v6 + 96) = v7;
  eigenVec->m_col0.m_quad.xy = g_vectordConstants[28].xy;
  *(__m128d *)(v6 + 112) = v15;
  eigenVec->m_col0.m_quad.zw = g_vectordConstants[28].zw;
  eigenVec->m_col1.m_quad.xy = g_vectordConstants[29].xy;
  eigenVec->m_col1.m_quad.zw = g_vectordConstants[29].zw;
  eigenVec->m_col2.m_quad.xy = g_vectordConstants[30].xy;
  eigenVec->m_col2.m_quad.zw = g_vectordConstants[30].zw;
  v17 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v18 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v19 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v20 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v21 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  v22 = COERCE_DOUBLE(_mm_unpckl_pd(v17, v17))
      + COERCE_DOUBLE(_mm_unpckh_pd(v17, v17))
      + COERCE_DOUBLE(_mm_unpckl_pd(v19, v19));
  v17.m128d_f64[0] = COERCE_DOUBLE(_mm_unpckl_pd(v18, v18)) + COERCE_DOUBLE(_mm_unpckh_pd(v18, v18));
  v23 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  *(_QWORD *)&v18.m128d_f64[0] = (unsigned __int128)_mm_unpckl_pd(v7, v7);
  v24 = v22 + v17.m128d_f64[0] + COERCE_DOUBLE(_mm_unpckl_pd(v21, v21));
  *(_QWORD *)&v17.m128d_f64[0] = (unsigned __int128)_mm_unpckh_pd(v7, v7);
  *(_QWORD *)&v19.m128d_f64[0] = (unsigned __int128)_mm_unpckl_pd(v8, v8);
  v25 = (v24
       + COERCE_DOUBLE(_mm_unpckl_pd(v20, v20))
       + COERCE_DOUBLE(_mm_unpckh_pd(v20, v20))
       + COERCE_DOUBLE(_mm_unpckl_pd(v23, v23)))
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
      *(long double *)v6 = v7.m128d_f64[0];
      v28 = 0;
      v29 = 1;
      v30 = *(double *)v6;
      *(_QWORD *)v6 = (unsigned __int128)_mm_unpckh_pd(v7, v7);
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
      v35 = (double *)(v28 >= 2 ? v34 + 8 * (v28 - 2 + 2i64) : v34 + 8i64 * v28);
      if ( *v35 == 0.0 )
      {
        v42 = DOUBLE_1_0;
        v43 = 0.0;
      }
      else
      {
        v36 = (double *)(v29 >= 2 ? v34 + 8 * (v29 - 2 + 2i64) : v34 + 8i64 * v29);
        v37 = 32i64 * v28 + v6 + 32;
        v38 = (double *)(v28 >= 2 ? v37 + 8 * (v28 - 2 + 2i64) : v37 + 8i64 * v28);
        v39 = (*v36 - *v38) / (*v35 * 2.0);
        *(double *)v6 = v39 * v39 + 1.0;
        v40 = sqrt(*(double *)v6);
        v41 = v39 < 0.0 ? 1.0 / (v39 - v40) : 1.0 / (v40 + v39);
        *(double *)v6 = v41 * v41 + 1.0;
        v42 = *(double *)_xmm / sqrt(*(double *)v6);
        v43 = v42 * v41;
      }
      v44 = 32i64 * v28;
      v45 = v44 + v6 + 128;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = g_vectordConstants[30].zw;
      v46 = (double *)(v28 >= 2 ? v45 + 8 * (v28 - 2 + 2i64) : v45 + 8i64 * v28);
      *v46 = v42;
      v47 = v33 + v6 + 128;
      v48 = (double *)(v28 >= 2 ? v47 + 8 * (v28 - 2 + 2i64) : v47 + 8i64 * v28);
      *v48 = v43;
      v49 = (__int64 *)(v29 >= 2 ? v45 + 8 * (v29 - 2 + 2i64) : v45 + 8i64 * v29);
      *v49 = *(_QWORD *)&v43 ^ _xmm[0];
      v50 = (double *)(v29 >= 2 ? v47 + 8 * (v29 - 2 + 2i64) : v47 + 8i64 * v29);
      *v50 = v42;
      v51 = v44 + v6 + 224;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x110) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130) = g_vectordConstants[30].zw;
      v52 = (double *)(v28 >= 2 ? v51 + 8 * (v28 - 2 + 2i64) : v51 + 8i64 * v28);
      *v52 = v42;
      v53 = v6 + 224 + v33;
      v54 = (__int64 *)(v28 >= 2 ? v53 + 8 * (v28 - 2 + 2i64) : v53 + 8i64 * v28);
      *v54 = *(_QWORD *)&v43 ^ _xmm[0];
      v55 = (double *)(v29 >= 2 ? v51 + 8 * (v29 - 2 + 2i64) : v51 + 8i64 * v29);
      *v55 = v43;
      v56 = (double *)(v29 >= 2 ? v53 + 8 * (v29 - 2 + 2i64) : v53 + 8i64 * v29);
      *v56 = v42;
      hkMatrix3d::mul((hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 128));
      hkMatrix3d::setMul((hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32));
      hkMatrix3d::mul((hkMatrix3d *)&v11->m_col0, (hkMatrix3d *)(v6 + 128));
      ++v9;
      v7 = *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
      v8 = *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
      *(_QWORD *)&v57 = (unsigned __int128)_mm_unpckl_pd(v7, v7);
      *(_QWORD *)&v58 = (unsigned __int128)_mm_unpckl_pd(v8, v8);
      *(_QWORD *)&v59 = (unsigned __int128)_mm_unpckh_pd(
                                             *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60),
                                             v7);
      v26 = (v57 * v57 + v58 * v58 + v59 * v59) * 2.0;
    }
    while ( v26 > v25 );
    v15 = *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    v14 = *(__m128d *)(((unsigned __int64)&v61 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v10 = v62;
  }
  v10->m_quad.xy = _mm_unpckl_pd(_mm_unpckl_pd(v14, v14), _mm_unpckh_pd(v8, v8));
  v10->m_quad.zw = _mm_unpckl_pd(v15, v15);
  v60 = v12;
  v12->m_enum = v26 > v25;
  return v60;
}

// File Line: 389
// RVA: 0xC8C4B0
hkResult *__fastcall hkMatrix3d::diagonalizeSymmetricWarmStart(hkMatrix3d *this, hkResult *result, hkMatrix3d *eigenVec, hkVector4d *eigenVal, int maxIter, long double epsilon)
{
  unsigned __int64 v6; // rbp
  __m128d v7; // xmm1
  hkMatrix3d *v8; // rbx
  hkVector4d *v9; // r13
  hkMatrix3d *v10; // r14
  hkResult *v11; // r12
  __m128d v12; // xmm0
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
  double v27; // xmm10_8
  __m128d v28; // xmm4
  __m128d v29; // xmm3
  __m128d v30; // xmm5
  __m128d v31; // xmm2
  double v32; // xmm6_8
  double v33; // xmm8_8
  double v34; // xmm10_8
  double i; // xmm8_8
  double v36; // xmm0_8
  signed int v37; // edx
  signed int v38; // er8
  double v39; // xmm1_8
  double v40; // xmm1_8
  double v41; // xmm0_8
  signed __int64 v42; // r11
  signed __int64 v43; // r9
  double *v44; // rcx
  double *v45; // r10
  signed __int64 v46; // r9
  double *v47; // rax
  double v48; // xmm1_8
  double v49; // xmm3_8
  double v50; // xmm2_8
  double v51; // xmm4_8
  double v52; // xmm3_8
  signed __int64 v53; // r10
  double *v54; // rax
  signed __int64 v55; // r9
  double *v56; // rax
  __int64 *v57; // rax
  double *v58; // rax
  __int128 v59; // xmm1
  __int128 v60; // xmm0
  __int128 v61; // xmm1
  __int128 v62; // xmm0
  __int128 v63; // xmm1
  double v64; // xmm8_8
  __m128d v65; // xmm5
  __m128d v66; // xmm0
  __m128d v67; // xmm1
  __m128d v68; // xmm3
  __m128d v69; // xmm2
  __m128d v70; // xmm4
  __m128d v71; // xmm0
  __m128d v72; // xmm6
  __m128d v73; // xmm5
  __m128d v74; // xmm0
  __m128d v75; // xmm1
  __m128d v76; // xmm3
  __m128d v77; // xmm2
  __m128d v78; // xmm4
  __m128d v79; // xmm6
  __m128d v80; // xmm5
  __m128d v81; // xmm0
  __m128d v82; // xmm1
  __m128d v83; // xmm3
  __m128d v84; // xmm2
  hkResult *v85; // rax
  __m128d v86; // xmm4
  __int64 v87; // [rsp+40h] [rbp+0h]

  v6 = (unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64;
  v7 = this->m_col0.m_quad.zw;
  v8 = this;
  v9 = eigenVal;
  v10 = eigenVec;
  v11 = result;
  *(__m128d *)(v6 + 128) = this->m_col0.m_quad.xy;
  v12 = this->m_col1.m_quad.xy;
  *(__m128d *)(v6 + 144) = v7;
  v13 = this->m_col1.m_quad.zw;
  *(__m128d *)(v6 + 160) = v12;
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
  hkMatrix3d::transpose((hkMatrix3d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 32));
  hkMatrix3d::setMul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32), (hkMatrix3d *)(v6 + 128));
  hkMatrix3d::mul((hkMatrix3d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 224), v10);
  v22 = 0;
  v23 = _mm_mul_pd(v8->m_col1.m_quad.xy, v8->m_col1.m_quad.xy);
  v24 = _mm_mul_pd(v8->m_col1.m_quad.zw, v8->m_col1.m_quad.zw);
  v25 = _mm_mul_pd(v8->m_col0.m_quad.xy, v8->m_col0.m_quad.xy);
  v26 = *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100);
  v27 = COERCE_DOUBLE(_mm_unpckl_pd(v23, v23))
      + COERCE_DOUBLE(_mm_unpckh_pd(v23, v23))
      + COERCE_DOUBLE(_mm_unpckl_pd(v24, v24));
  v28 = _mm_mul_pd(v8->m_col2.m_quad.xy, v8->m_col2.m_quad.xy);
  v29 = _mm_mul_pd(v8->m_col0.m_quad.zw, v8->m_col0.m_quad.zw);
  v30 = _mm_mul_pd(v8->m_col2.m_quad.zw, v8->m_col2.m_quad.zw);
  v23.m128d_f64[0] = COERCE_DOUBLE(_mm_unpckl_pd(v25, v25)) + COERCE_DOUBLE(_mm_unpckh_pd(v25, v25));
  v31 = *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120);
  *(_QWORD *)&v32 = (unsigned __int128)_mm_shuffle_pd(
                                         (__m128d)*(unsigned __int64 *)&epsilon,
                                         (__m128d)*(unsigned __int64 *)&epsilon,
                                         0);
  *(_QWORD *)&v33 = (unsigned __int128)_mm_unpckl_pd(v31, v31);
  *(_QWORD *)&v24.m128d_f64[0] = (unsigned __int128)_mm_unpckl_pd(v26, v26);
  v34 = (v27
       + v23.m128d_f64[0]
       + COERCE_DOUBLE(_mm_unpckl_pd(v29, v29))
       + COERCE_DOUBLE(_mm_unpckl_pd(v28, v28))
       + COERCE_DOUBLE(_mm_unpckh_pd(v28, v28))
       + COERCE_DOUBLE(_mm_unpckl_pd(v30, v30)))
      * (v32
       * v32);
  *(_QWORD *)&v23.m128d_f64[0] = (unsigned __int128)_mm_unpckh_pd(
                                                      *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64)
                                                                 + 0x120),
                                                      v31);
  for ( i = (v33 * v33 + v24.m128d_f64[0] * v24.m128d_f64[0] + v23.m128d_f64[0] * v23.m128d_f64[0]) * 2.0;
        i >= v34;
        i = (v64 * v64 + *(double *)&v63 * *(double *)&v63 + *(double *)&v62 * *(double *)&v62) * 2.0 )
  {
    if ( v22 >= maxIter )
      break;
    *(long double *)v6 = v26.m128d_f64[0];
    v36 = *(double *)v6;
    *(long double *)v6 = v31.m128d_f64[0];
    v37 = 0;
    v38 = 1;
    v39 = *(double *)v6;
    *(_QWORD *)v6 = (unsigned __int128)_mm_unpckh_pd(v31, v31);
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
    v44 = (double *)(v37 >= 2 ? v43 + 8 * (v37 - 2 + 2i64) : v43 + 8i64 * v37);
    if ( *v44 == 0.0 )
    {
      v51 = DOUBLE_1_0;
      v52 = 0.0;
    }
    else
    {
      v45 = (double *)(v38 >= 2 ? v43 + 8 * (v38 - 2 + 2i64) : v43 + 8i64 * v38);
      v46 = 32i64 * v37 + v6 + 224;
      v47 = (double *)(v37 >= 2 ? v46 + 8 * (v37 - 2 + 2i64) : v46 + 8i64 * v37);
      v48 = (*v45 - *v47) / (*v44 * 2.0);
      *(double *)v6 = v48 * v48 + 1.0;
      v49 = sqrt(*(double *)v6);
      v50 = v48 < 0.0 ? 1.0 / (v48 - v49) : 1.0 / (v49 + v48);
      *(double *)v6 = v50 * v50 + 1.0;
      v51 = *(double *)_xmm / sqrt(*(double *)v6);
      v52 = v51 * v50;
    }
    v53 = 32i64 * v37 + v6 + 32;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = g_vectordConstants[28].xy;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = g_vectordConstants[28].zw;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = g_vectordConstants[29].xy;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = g_vectordConstants[29].zw;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = g_vectordConstants[30].xy;
    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70) = g_vectordConstants[30].zw;
    v54 = (double *)(v37 >= 2 ? v53 + 8 * (v37 - 2 + 2i64) : v53 + 8i64 * v37);
    *v54 = v51;
    v55 = v42 + v6 + 32;
    v56 = (double *)(v37 >= 2 ? v55 + 8 * (v37 - 2 + 2i64) : v55 + 8i64 * v37);
    *v56 = v52;
    v57 = (__int64 *)(v38 >= 2 ? v53 + 8 * (v38 - 2 + 2i64) : v53 + 8i64 * v38);
    *v57 = *(_QWORD *)&v52 ^ _xmm[0];
    v58 = (double *)(v38 >= 2 ? v55 + 8 * (v38 - 2 + 2i64) : v55 + 8i64 * v38);
    *v58 = v51;
    v59 = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64)
                                                                                      + 0x20);
    v60 = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = v59;
    v61 = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = v60;
    v62 = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = v61;
    v63 = *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = v62;
    *(_OWORD *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = v63;
    hkMatrix3d::transpose((hkMatrix3d *)(v6 + 128));
    hkMatrix3d::mul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 32));
    hkMatrix3d::setMul((hkMatrix3d *)(v6 + 224), (hkMatrix3d *)(v6 + 128), (hkMatrix3d *)(v6 + 224));
    hkMatrix3d::mul(v10, (hkMatrix3d *)(v6 + 32));
    ++v22;
    v31 = *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120);
    v26 = *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100);
    *(_QWORD *)&v64 = (unsigned __int128)_mm_unpckl_pd(v31, v31);
    *(_QWORD *)&v63 = (unsigned __int128)_mm_unpckl_pd(v26, v26);
    *(_QWORD *)&v62 = (unsigned __int128)_mm_unpckh_pd(
                                           *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120),
                                           v31);
  }
  v65 = v10->m_col0.m_quad.zw;
  v66 = _mm_mul_pd(v10->m_col0.m_quad.xy, v10->m_col0.m_quad.xy);
  v67 = _mm_mul_pd(v65, v65);
  v68 = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v66, v66), _mm_unpckh_pd(v66, v66)), _mm_unpckl_pd(v67, v67));
  v69 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v68)));
  v70 = _mm_andn_pd(
          _mm_cmple_pd(v68, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v69, v68), v69)),
            _mm_mul_pd(v69, g_vectordConstants[17].xy)));
  v71 = _mm_mul_pd(v70, v10->m_col0.m_quad.xy);
  v10->m_col0.m_quad.zw = _mm_mul_pd(v70, v65);
  v10->m_col0.m_quad.xy = v71;
  v72 = v10->m_col1.m_quad.xy;
  v73 = v10->m_col1.m_quad.zw;
  v74 = _mm_mul_pd(v72, v72);
  v75 = _mm_mul_pd(v73, v73);
  v76 = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v74, v74), _mm_unpckh_pd(v74, v74)), _mm_unpckl_pd(v75, v75));
  v77 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v76)));
  v78 = _mm_andn_pd(
          _mm_cmple_pd(v76, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v77, v76), v77)),
            _mm_mul_pd(v77, g_vectordConstants[17].xy)));
  v10->m_col1.m_quad.zw = _mm_mul_pd(v78, v73);
  v10->m_col1.m_quad.xy = _mm_mul_pd(v78, v72);
  v79 = v10->m_col2.m_quad.xy;
  v80 = v10->m_col2.m_quad.zw;
  v81 = _mm_mul_pd(v79, v79);
  v82 = _mm_mul_pd(v80, v80);
  v83 = _mm_add_pd(_mm_add_pd(_mm_unpckl_pd(v81, v81), _mm_unpckh_pd(v81, v81)), _mm_unpckl_pd(v82, v82));
  v84 = _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(v83)));
  v85 = v11;
  v86 = _mm_andn_pd(
          _mm_cmple_pd(v83, (__m128d)0i64),
          _mm_mul_pd(
            _mm_sub_pd(g_vectordConstants[4].xy, _mm_mul_pd(_mm_mul_pd(v84, v83), v84)),
            _mm_mul_pd(v84, g_vectordConstants[17].xy)));
  v10->m_col2.m_quad.zw = _mm_mul_pd(v86, v80);
  v10->m_col2.m_quad.xy = _mm_mul_pd(v86, v79);
  v9->m_quad.xy = _mm_unpckl_pd(
                    _mm_unpckl_pd(
                      *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0),
                      *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0)),
                    _mm_unpckh_pd(v26, v26));
  v9->m_quad.zw = _mm_unpckl_pd(
                    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130),
                    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130));
  v11->m_enum = i > v34;
  return v85;
}kh_pd(v26, v26));
  v9->m_quad.zw = _mm_unpckl_pd(
                    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130),
                    *(__m128d *)(((unsigned __int64)&v87 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130));
  v1

// File Line: 450
// RVA: 0xC8CC20
void __fastcall hkMatrix3d::diagonalizeSymmetricApproximation(hkMatrix3d *this, hkRotationd *eigenVec, hkVector4d *eigenVal, int maxIter)
{
  unsigned __int64 v4; // rbp
  __m128d v5; // xmm1
  __m128d v6; // xmm9
  int v7; // er14
  int v8; // er12
  hkVector4d *v9; // r13
  hkRotationd *v10; // r15
  __m128d v11; // xmm7
  __m128d v12; // xmm8
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
  signed int v23; // edx
  signed int v24; // er8
  double v25; // xmm3_8
  double v26; // xmm2_8
  double v27; // xmm3_8
  double v28; // xmm1_8
  signed __int64 v29; // r11
  signed __int64 v30; // r9
  double *v31; // rcx
  double *v32; // rsi
  signed __int64 v33; // rbx
  signed __int64 v34; // rdi
  double *v35; // rax
  double v36; // xmm1_8
  double v37; // xmm3_8
  double v38; // xmm2_8
  signed __int64 v39; // rsi
  double v40; // xmm4_8
  double v41; // xmm3_8
  double v42; // xmm4_8
  double *v43; // rax
  signed __int64 v44; // rdi
  double *v45; // rax
  __int64 *v46; // rax
  double *v47; // rax
  signed __int64 v48; // rbx
  double *v49; // rax
  signed __int64 v50; // r11
  __int64 *v51; // rax
  double *v52; // rax
  double *v53; // rax
  __int64 v54; // [rsp+40h] [rbp+0h]

  v4 = (unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64;
  v5 = this->m_col2.m_quad.xy;
  v6 = this->m_col0.m_quad.xy;
  v7 = 0;
  v8 = maxIter;
  v9 = eigenVal;
  v10 = eigenVec;
  v11 = this->m_col1.m_quad.xy;
  v12 = this->m_col2.m_quad.zw;
  *(__m128d *)(v4 + 48) = this->m_col0.m_quad.zw;
  v13 = this->m_col1.m_quad.zw;
  *(__m128d *)(v4 + 96) = v5;
  *(__m128d *)(v4 + 32) = v6;
  *(__m128d *)(v4 + 80) = v13;
  *(__m128d *)(v4 + 64) = v11;
  eigenVec->m_col0.m_quad.xy = g_vectordConstants[28].xy;
  *(__m128d *)(v4 + 112) = v12;
  eigenVec->m_col0.m_quad.zw = g_vectordConstants[28].zw;
  eigenVec->m_col1.m_quad.xy = g_vectordConstants[29].xy;
  eigenVec->m_col1.m_quad.zw = g_vectordConstants[29].zw;
  eigenVec->m_col2.m_quad.xy = g_vectordConstants[30].xy;
  eigenVec->m_col2.m_quad.zw = g_vectordConstants[30].zw;
  v14 = _mm_mul_pd(this->m_col1.m_quad.xy, this->m_col1.m_quad.xy);
  v15 = _mm_mul_pd(this->m_col0.m_quad.xy, this->m_col0.m_quad.xy);
  v16 = _mm_mul_pd(this->m_col1.m_quad.zw, this->m_col1.m_quad.zw);
  v17 = _mm_mul_pd(this->m_col2.m_quad.xy, this->m_col2.m_quad.xy);
  v18 = _mm_mul_pd(this->m_col0.m_quad.zw, this->m_col0.m_quad.zw);
  v19 = _mm_mul_pd(this->m_col2.m_quad.zw, this->m_col2.m_quad.zw);
  *(double *)v4 = COERCE_DOUBLE(_mm_unpckl_pd(v14, v14))
                + COERCE_DOUBLE(_mm_unpckh_pd(v14, v14))
                + COERCE_DOUBLE(_mm_unpckl_pd(v16, v16))
                + COERCE_DOUBLE(_mm_unpckl_pd(v15, v15))
                + COERCE_DOUBLE(_mm_unpckh_pd(v15, v15))
                + COERCE_DOUBLE(_mm_unpckl_pd(v18, v18))
                + COERCE_DOUBLE(_mm_unpckl_pd(v17, v17))
                + COERCE_DOUBLE(_mm_unpckh_pd(v17, v17))
                + COERCE_DOUBLE(_mm_unpckl_pd(v19, v19));
  v20 = *(double *)((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) * 4.930380657631324e-32;
  if ( maxIter > 0 )
  {
    do
    {
      v21 = *(_QWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
      *(long double *)v4 = v11.m128d_f64[0];
      v22 = *(double *)v4;
      v23 = 0;
      v24 = 1;
      *(_QWORD *)v4 = v21;
      v25 = *(double *)v4;
      *(_QWORD *)v4 = *(_QWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x68);
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
      v31 = (double *)(v23 >= 2 ? v30 + 8 * (v23 - 2 + 2i64) : v30 + 8i64 * v23);
      v32 = (double *)(v24 >= 2 ? v30 + 8 * (v24 - 2 + 2i64) : v30 + 8i64 * v24);
      v33 = 32i64 * v23;
      v34 = v33 + v4 + 32;
      v35 = (double *)(v23 >= 2 ? v34 + 8 * (v23 - 2 + 2i64) : v34 + 8i64 * v23);
      v36 = (*v32 - *v35) / (*v31 * 2.0);
      *(double *)v4 = v36 * v36 + 1.0;
      v37 = sqrt(*(double *)v4);
      v38 = v36 < 0.0 ? 1.0 / (v36 - v37) : 1.0 / (v37 + v36);
      v39 = v33 + v4 + 128;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = g_vectordConstants[28].zw;
      *(double *)v4 = v38 * v38 + 1.0;
      v40 = sqrt(*(double *)v4);
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xD0) = g_vectordConstants[30].zw;
      v41 = *(double *)_xmm / v40;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xC0) = g_vectordConstants[30].xy;
      v42 = *(double *)_xmm / v40 * v38;
      v43 = (double *)(v23 >= 2 ? v39 + 8 * (v23 - 2 + 2i64) : v39 + 8i64 * v23);
      *v43 = v41;
      v44 = v29 + v4 + 128;
      v45 = (double *)(v23 >= 2 ? v44 + 8 * (v23 - 2 + 2i64) : v44 + 8i64 * v23);
      *v45 = v42;
      v46 = (__int64 *)(v24 >= 2 ? v39 + 8 * (v24 - 2 + 2i64) : v39 + 8i64 * v24);
      *v46 = *(_QWORD *)&v42 ^ _xmm[0];
      v47 = (double *)(v24 >= 2 ? v44 + 8 * (v24 - 2 + 2i64) : v44 + 8i64 * v24);
      *v47 = v41;
      v48 = v4 + 224 + v33;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) = g_vectordConstants[28].xy;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0) = g_vectordConstants[28].zw;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x100) = g_vectordConstants[29].xy;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x110) = g_vectordConstants[29].zw;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x120) = g_vectordConstants[30].xy;
      *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x130) = g_vectordConstants[30].zw;
      v49 = (double *)(v23 >= 2 ? v48 + 8 * (v23 - 2 + 2i64) : v48 + 8i64 * v23);
      *v49 = v41;
      v50 = v4 + 224 + v29;
      v51 = (__int64 *)(v23 >= 2 ? v50 + 8 * (v23 - 2 + 2i64) : v50 + 8i64 * v23);
      *v51 = *(_QWORD *)&v42 ^ _xmm[0];
      v52 = (double *)(v24 >= 2 ? v48 + 8 * (v24 - 2 + 2i64) : v48 + 8i64 * v24);
      *v52 = v42;
      v53 = (double *)(v24 >= 2 ? v50 + 8 * (v24 - 2 + 2i64) : v50 + 8i64 * v24);
      *v53 = v41;
      hkMatrix3d::mul((hkMatrix3d *)(v4 + 32), (hkMatrix3d *)(v4 + 128));
      hkMatrix3d::setMul((hkMatrix3d *)(v4 + 32), (hkMatrix3d *)(v4 + 224), (hkMatrix3d *)(v4 + 32));
      hkMatrix3d::mul((hkMatrix3d *)&v10->m_col0, (hkMatrix3d *)(v4 + 128));
      ++v7;
      v11 = *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    }
    while ( v7 < v8 );
    v6 = *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v12 = *(__m128d *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
  }
  v9->m_quad.zw = _mm_unpckl_pd(v12, v12);
  v9->m_quad.xy = _mm_unpckl_pd(_mm_unpckl_pd(v6, v6), _mm_unpckh_pd(v11, v11));
}

