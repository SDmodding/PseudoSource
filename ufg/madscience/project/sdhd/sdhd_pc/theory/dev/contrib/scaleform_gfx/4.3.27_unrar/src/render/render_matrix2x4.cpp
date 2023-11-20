// File Line: 397
// RVA: 0x96FFE0
void __fastcall Scaleform::Render::Matrix2x4<float>::EncloseTransform(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Rect<float> *pr, Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm3

  v3 = *r;
  v4 = _mm_unpacklo_ps(*(__m128 *)&this->M[0][0], *(__m128 *)&this->M[1][0]);
  v5 = _mm_shuffle_ps(*(__m128 *)&this->M[0][0], *(__m128 *)&this->M[1][0], 255);
  v6 = _mm_mul_ps(_mm_unpacklo_ps((__m128)v3, (__m128)v3), v4);
  v7 = _mm_mul_ps(_mm_unpackhi_ps((__m128)v3, (__m128)v3), v4);
  v8 = v6;
  v9 = _mm_unpackhi_ps(v6, v7);
  v10 = _mm_unpacklo_ps(v8, v7);
  v11 = _mm_add_ps(v9, v10);
  v12 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 177), v9);
  v13 = _mm_min_ps(v11, v12);
  v14 = _mm_max_ps(v11, v12);
  *(__m128 *)pr = _mm_add_ps(
                    _mm_shuffle_ps(
                      _mm_min_ps(v13, _mm_shuffle_ps(v13, v13, 177)),
                      _mm_max_ps(v14, _mm_shuffle_ps(v14, v14, 177)),
                      136),
                    _mm_shuffle_ps(v5, v5, 136));
}

// File Line: 435
// RVA: 0x9B4E20
void __fastcall Scaleform::Render::Matrix2x4<float>::SetToAppend(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m0, Scaleform::Render::Matrix2x4<float> *m1)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm3
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm0

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m0->M[1][0];
  v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
  v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  v7 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)&m0->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m0->M[0][0])),
                                  _mm_and_ps(
                                    *(__m128 *)&m1->M[0][0],
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4), v7),
                                  _mm_and_ps(v3, v5)),
                                v6);
}

// File Line: 459
// RVA: 0x9B4D30
void __fastcall Scaleform::Render::Matrix2x4<float>::SetToAppend(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m0, Scaleform::Render::Matrix2x4<float> *m1, Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v4; // xmm7
  __m128 v5; // xmm9
  __m128 v6; // xmm10
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm0

  v4 = *(__m128 *)&m0->M[1][0];
  v5 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
  v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[0][0], *(__m128 *)&m2->M[0][0], 85), *(__m128 *)&m1->M[1][0]),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[0][0], *(__m128 *)&m2->M[0][0], 0), *(__m128 *)&m1->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m2->M[0][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[1][0], *(__m128 *)&m2->M[1][0], 85), *(__m128 *)&m1->M[1][0]),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[1][0], *(__m128 *)&m2->M[1][0], 0), *(__m128 *)&m1->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m2->M[1][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), *(__m128 *)&m0->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&m0->M[0][0])),
                                  _mm_and_ps(
                                    v7,
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v4), v9),
                                  _mm_and_ps(v8, v5)),
                                v6);
}

// File Line: 500
// RVA: 0x9588E0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Matrix2x4<float>::Append(Scaleform::Render::Matrix2x4<float> *this, Scaleform::Render::Matrix2x4<float> *m)
{
  __m128 v2; // xmm5
  Scaleform::Render::Matrix2x4<float> *result; // rax
  __m128 v4; // xmm7
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm0

  v2 = *(__m128 *)&m->M[1][0];
  result = this;
  v4 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  v5 = _mm_shuffle_ps(v2, v2, 0);
  v6 = _mm_shuffle_ps(*(__m128 *)&m->M[1][0], v2, 85);
  v7 = _mm_and_ps(v2, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
  v8 = _mm_mul_ps(v5, *(__m128 *)&this->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0], 85),
                                      *(__m128 *)&this->M[1][0]),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0], 0),
                                      *(__m128 *)&this->M[0][0])),
                                  _mm_and_ps(
                                    *(__m128 *)&m->M[0][0],
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v6, *(__m128 *)&this->M[1][0]), v8), v7), v4);
  return result;
}

