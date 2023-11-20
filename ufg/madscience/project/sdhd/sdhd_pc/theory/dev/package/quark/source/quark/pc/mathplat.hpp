// File Line: 404
// RVA: 0x378F0
UFG::qMatrix44 *__fastcall UFG::qMatrix44::operator*=(UFG::qMatrix44 *this, UFG::qMatrix44 *b)
{
  UFG::qVector4 v2; // xmm4
  UFG::qVector4 v3; // xmm5
  UFG::qMatrix44 *result; // rax
  UFG::qVector4 v5; // xmm6
  UFG::qVector4 v6; // xmm11
  UFG::qVector4 v7; // xmm7
  UFG::qVector4 v8; // xmm8
  UFG::qVector4 v9; // xmm9
  __m128 v10; // xmm1
  UFG::qVector4 v11; // xmm3

  v2 = this->v1;
  v3 = this->v2;
  result = this;
  v5 = b->v0;
  v6 = this->v3;
  v7 = b->v1;
  v8 = b->v2;
  v9 = b->v3;
  v10 = _mm_shuffle_ps((__m128)this->v1, (__m128)v2, 170);
  v11 = this->v1;
  this->v0 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 0), (__m128)b->v0),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 85), (__m128)v7)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 170), (__m128)v8)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 255), (__m128)v9));
  this->v1 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v11, (__m128)v2, 0), (__m128)v5),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v2, (__m128)v2, 85), (__m128)v7)),
                                _mm_mul_ps(v10, (__m128)v8)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v2, (__m128)v2, 255), (__m128)v9));
  this->v2 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 0), (__m128)v5),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 85), (__m128)v7)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 170), (__m128)v8)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 255), (__m128)v9));
  this->v3 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 0), (__m128)v5),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 85), (__m128)v7)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 170), (__m128)v8)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 255), (__m128)v9));
  return result;
}

// File Line: 410
// RVA: 0x29C0
UFG::qMatrix44 *__fastcall UFG::qMatrix44::operator*(UFG::qMatrix44 *this, UFG::qMatrix44 *result, UFG::qMatrix44 *b)
{
  UFG::qVector4 v3; // xmm4
  UFG::qVector4 v4; // xmm5
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm11
  UFG::qVector4 v7; // xmm6
  UFG::qVector4 v8; // xmm7
  UFG::qVector4 v9; // xmm8
  UFG::qVector4 v10; // xmm10
  __m128 v11; // xmm1

  v3 = this->v1;
  v4 = this->v2;
  v5 = result;
  v6 = this->v3;
  v7 = b->v0;
  v8 = b->v1;
  v9 = b->v2;
  v10 = b->v3;
  v11 = _mm_shuffle_ps((__m128)this->v1, (__m128)v3, 170);
  result->v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 0), (__m128)b->v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 85), (__m128)v8)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 170), (__m128)v9)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)this->v0, (__m128)this->v0, 255), (__m128)v10));
  result->v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 0), (__m128)v7),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 85), (__m128)v8)),
                                  _mm_mul_ps(v11, (__m128)v9)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v3, (__m128)v3, 255), (__m128)v10));
  result->v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v4, (__m128)v4, 0), (__m128)v7),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v4, (__m128)v4, 85), (__m128)v8)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v4, (__m128)v4, 170), (__m128)v9)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v4, (__m128)v4, 255), (__m128)v10));
  result->v3 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 0), (__m128)v7),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 85), (__m128)v8)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 170), (__m128)v9)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 255), (__m128)v10));
  return v5;
}

// File Line: 429
// RVA: 0xD0C0
UFG::qVector4 *__fastcall UFG::operator*(UFG::qVector4 *result, UFG::qVector4 *row_vec4, UFG::qMatrix44 *matrix44)
{
  float v3; // xmm4_4
  float v4; // xmm5_4
  UFG::qVector4 *v5; // rax
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4

  v3 = row_vec4->y;
  v4 = row_vec4->z;
  v5 = result;
  v6 = row_vec4->x;
  v7 = row_vec4->w;
  v8 = row_vec4->x * matrix44->v0.y;
  v9 = row_vec4->z * matrix44->v2.y;
  v10 = row_vec4->y;
  result->x = (float)((float)((float)(row_vec4->y * matrix44->v1.x) + (float)(row_vec4->x * matrix44->v0.x))
                    + (float)(row_vec4->z * matrix44->v2.x))
            + (float)(row_vec4->w * matrix44->v3.x);
  v11 = v6;
  v12 = v6 * matrix44->v0.w;
  v13 = v11 * matrix44->v0.z;
  v14 = (float)(v8 + (float)(v10 * matrix44->v1.y)) + v9;
  v15 = v4;
  v16 = v4 * matrix44->v2.w;
  v17 = v15 * matrix44->v2.z;
  result->y = v14 + (float)(v7 * matrix44->v3.y);
  v18 = v13 + (float)(v3 * matrix44->v1.z);
  v19 = v7 * matrix44->v3.z;
  result->w = (float)((float)(v12 + (float)(v3 * matrix44->v1.w)) + v16) + (float)(v7 * matrix44->v3.w);
  result->z = (float)(v18 + v17) + v19;
  return v5;
}

// File Line: 459
// RVA: 0xC2D0
float __fastcall UFG::qRSqrt(float a)
{
  return 1.0 / fsqrt(a);
}

// File Line: 476
// RVA: 0x6C9C0
void __fastcall UFG::qASin(float sine)
{
  if ( sine <= -1.0 )
  {
    sine = FLOAT_N1_0;
  }
  else if ( sine >= 1.0 )
  {
    asinf(1.0);
    return;
  }
  asinf(sine);
}

// File Line: 478
// RVA: 0x6C990
void __fastcall UFG::qACos(float cosine)
{
  if ( cosine <= -1.0 )
  {
    cosine = FLOAT_N1_0;
  }
  else if ( cosine >= 1.0 )
  {
    acosf(1.0);
    return;
  }
  acosf(cosine);
}

