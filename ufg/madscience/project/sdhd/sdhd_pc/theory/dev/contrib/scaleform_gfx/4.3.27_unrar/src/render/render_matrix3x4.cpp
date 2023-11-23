// File Line: 193
// RVA: 0x99BA40
void __fastcall Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix3x4<float> *m1,
        Scaleform::Render::Matrix3x4<float> *m2)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm8
  __m128 v8; // xmm9

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m2->M[0][0];
  v6 = *(__m128 *)&m2->M[2][0];
  v7 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v;
  v8 = *(__m128 *)&m1->M[2][0];
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v6)),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                  *(__m128 *)&m1->M[0][0]));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v5)),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v6)),
                                _mm_and_ps(v7, v3));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v5)),
                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v6)),
                                _mm_and_ps(v7, v8));
}

// File Line: 227
// RVA: 0x99BB30
void __fastcall Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix3x4<float> *m1,
        Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm5
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm7

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[0][0];
  v5 = *(__m128 *)&m2->M[1][0];
  v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v;
  v7 = *(__m128 *)&m1->M[2][0];
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v5),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                    *(__m128 *)&m2->M[0][0])),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>::`2::v,
                                  *(__m128 *)&m1->M[0][0]));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v5),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v4)),
                                _mm_and_ps(v6, v3));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v5),
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v4)),
                                _mm_and_ps(v6, v7));
}

// File Line: 256
// RVA: 0x99BBD0
void __fastcall Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix2x4<float> *m1,
        Scaleform::Render::Matrix3x4<float> *m2)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm4
  __m128 v5; // xmm7
  __m128 v6; // xmm8
  __m128 v7; // xmm6

  v3 = *(__m128 *)&m2->M[0][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m2->M[2][0];
  v6 = *(__m128 *)&m1->M[1][0];
  v7 = _mm_and_ps((__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v, v6);
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v5)),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v,
                                  *(__m128 *)&m1->M[0][0]));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v3)),
                                  _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), v5)),
                                v7);
  *(__m128 *)&this->M[2][0] = v5;
}

