// File Line: 680
// RVA: 0x99BC80
void __fastcall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix4x4<float> *m1, Scaleform::Render::Matrix4x4<float> *m2)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm10

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m1->M[2][0];
  v6 = *(__m128 *)&m2->M[0][0];
  v7 = *(__m128 *)&m2->M[2][0];
  v8 = *(__m128 *)&m2->M[3][0];
  v9 = *(__m128 *)&m1->M[3][0];
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v7)),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 255), v8));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v6)),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v7)),
                                _mm_mul_ps(_mm_shuffle_ps(v3, v3, 255), v8));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v6)),
                                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v7)),
                                _mm_mul_ps(_mm_shuffle_ps(v5, v5, 255), v8));
  *(__m128 *)&this->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v6)),
                                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v7)),
                                _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), v8));
}

// File Line: 721
// RVA: 0x99C080
void __fastcall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix3x4<float> *m1, Scaleform::Render::Matrix4x4<float> *m2)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm4
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm1
  __m128 v10; // xmm0

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m2->M[0][0];
  v6 = *(__m128 *)&m2->M[2][0];
  v7 = *(__m128 *)&m2->M[3][0];
  v8 = *(__m128 *)&m1->M[2][0];
  v9 = _mm_shuffle_ps(*(__m128 *)&m1->M[1][0], v3, 170);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)&m2->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v6)),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 255), v7));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4), v10),
                                  _mm_mul_ps(v9, v6)),
                                _mm_mul_ps(_mm_shuffle_ps(v3, v3, 255), v7));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v5)),
                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v6)),
                                _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), v7));
  *(__m128 *)&this->M[3][0] = v7;
}

// File Line: 757
// RVA: 0x99BE90
void __fastcall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix4x4<float> *m1, Scaleform::Render::Matrix3x4<float> *m2)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm8
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  __m128 v10; // xmm0
  __m128 v11; // xmm1

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m1->M[2][0];
  v6 = *(__m128 *)&m2->M[0][0];
  v7 = *(__m128 *)&m2->M[2][0];
  v8 = *(__m128 *)&m1->M[3][0];
  v9 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
  v10 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)&m2->M[0][0]);
  v11 = _mm_shuffle_ps(*(__m128 *)&m1->M[1][0], v3, 170);
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v7)),
                                _mm_and_ps(
                                  *(__m128 *)&m1->M[0][0],
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4), v10),
                                  _mm_mul_ps(v11, v7)),
                                _mm_and_ps(v3, v9));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v6)),
                                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v7)),
                                _mm_and_ps(v5, v9));
  *(__m128 *)&this->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v4),
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v6)),
                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v7)),
                                _mm_and_ps(v8, v9));
}

// File Line: 799
// RVA: 0x99BFC0
void __fastcall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix2x4<float> *m1, Scaleform::Render::Matrix4x4<float> *m2)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm0

  v3 = *(__m128 *)&m2->M[1][0];
  v4 = *(__m128 *)&m2->M[3][0];
  v5 = *(__m128 *)&m2->M[2][0];
  v6 = *(__m128 *)&m1->M[1][0];
  v7 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[1][0], v6, 170), v5);
  v8 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), *(__m128 *)&m2->M[0][0]);
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v3),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v5)),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 255), v4));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v3), v8), v7),
                                _mm_mul_ps(_mm_shuffle_ps(v6, v6, 255), v4));
  *(__m128 *)&this->M[2][0] = v5;
  *(__m128 *)&this->M[3][0] = v4;
}

// File Line: 830
// RVA: 0x99BDC0
void __fastcall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Matrix4x4<float> *m1, Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm5
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm8

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m1->M[2][0];
  v5 = *(__m128 *)&m2->M[1][0];
  v6 = *(__m128 *)&m2->M[0][0];
  v7 = *(__m128 *)&m1->M[3][0];
  v8 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v;
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v5),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                    *(__m128 *)&m2->M[0][0])),
                                _mm_and_ps(
                                  *(__m128 *)&m1->M[0][0],
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v5),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v6)),
                                _mm_and_ps(v3, v8));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v5),
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v6)),
                                _mm_and_ps(v4, v8));
  *(__m128 *)&this->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v5),
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6)),
                                _mm_and_ps(v7, v8));
}

// File Line: 865
// RVA: 0x970050
void __fastcall Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Rect<float> *pr, Scaleform::Render::Rect<float> *r)
{
  __m128 v3; // xmm9
  __m128 v4; // xmm10
  __m128 v5; // xmm11
  __m128 v6; // xmm15
  __m128 v7; // xmm14
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm13
  __m128 v16; // xmm12
  __m128 v17; // xmm3
  __m128 v18; // xmm13
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm15
  __m128 v35; // xmm1
  __m128 v36; // xmm4

  v3 = *(__m128 *)&this->M[1][0];
  v4 = *(__m128 *)&this->M[2][0];
  v5 = *(__m128 *)&this->M[3][0];
  v6 = _mm_shuffle_ps(*(__m128 *)r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 12);
  v7 = _mm_shuffle_ps(
         _mm_shuffle_ps(*(__m128 *)&this->M[0][0], v3, 255),
         _mm_shuffle_ps(*(__m128 *)&this->M[2][0], v5, 255),
         136);
  v8 = _mm_shuffle_ps(*(__m128 *)r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 4);
  v9 = _mm_shuffle_ps(*(__m128 *)r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 6);
  v10 = _mm_shuffle_ps(*(__m128 *)r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 14);
  v11 = _mm_mul_ps(v8, *(__m128 *)&this->M[0][0]);
  v12 = _mm_mul_ps(v8, v3);
  v13 = _mm_mul_ps(v8, v4);
  v14 = _mm_mul_ps(v8, v5);
  v15 = _mm_shuffle_ps(
          _mm_unpacklo_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170))),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)),
          4);
  v16 = _mm_shuffle_ps(v7, v7, 255);
  v17 = _mm_mul_ps(v9, v4);
  v18 = _mm_div_ps(
          _mm_add_ps(v15, v7),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)),
            v16));
  v19 = _mm_mul_ps(v9, v3);
  v20 = _mm_mul_ps(v9, *(__m128 *)&this->M[0][0]);
  v21 = _mm_mul_ps(v9, v5);
  v22 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_unpacklo_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170))),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            4),
          v7);
  v23 = _mm_mul_ps(v10, v3);
  v24 = _mm_mul_ps(v10, v4);
  v25 = _mm_div_ps(
          v22,
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170)),
            v16));
  v26 = v10;
  v27 = _mm_mul_ps(v10, v5);
  v28 = _mm_mul_ps(v26, *(__m128 *)&this->M[0][0]);
  v29 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_unpacklo_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                _mm_shuffle_ps(v23, v23, 170))),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
              _mm_shuffle_ps(v24, v24, 170)),
            4),
          v7);
  v30 = _mm_mul_ps(v6, v3);
  v31 = _mm_mul_ps(v6, v4);
  v32 = _mm_div_ps(
          v29,
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170)),
            v16));
  v33 = v6;
  v34 = _mm_mul_ps(v6, v5);
  v35 = _mm_mul_ps(v33, *(__m128 *)&this->M[0][0]);
  v36 = _mm_div_ps(
          _mm_add_ps(
            _mm_shuffle_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                  _mm_shuffle_ps(v35, v35, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                  _mm_shuffle_ps(v30, v30, 170))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170)),
              4),
            v7),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170)),
            v16));
  *(__m128 *)pr = _mm_shuffle_ps(
                    _mm_min_ps(_mm_min_ps(_mm_min_ps(v18, v25), v32), v36),
                    _mm_max_ps(_mm_max_ps(_mm_max_ps(v18, v25), v32), v36),
                    68);
}

// File Line: 945
// RVA: 0x9BA9C0
void __fastcall Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(Scaleform::Render::Matrix4x4<float> *this, Scaleform::Render::Rect<float> *bounds, float sx, float sy, float *dest)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm15
  __m128 v9; // xmm13
  __m128 v10; // xmm9
  __m128 v11; // ST20_16
  __m128 v12; // ST30_16
  __m128 v13; // xmm12
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm11
  __m128 v17; // ST00_16
  __m128 v18; // xmm14
  __m128 v19; // xmm15
  __m128 v20; // xmm6
  __m128 v21; // ST10_16
  __m128 v22; // xmm8
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  __m128 v25; // xmm13
  __m128 v26; // xmm2
  __m128 v27; // xmm14
  __m128 v28; // xmm7
  __m128 v29; // xmm3
  __m128 v30; // xmm8
  __m128 v31; // [rsp+10h] [rbp-D8h]

  v5 = *(__m128 *)&this->M[2][0];
  v6 = *(__m128 *)&this->M[3][0];
  v31.m128_u64[0] = __PAIR__(LODWORD(sy), LODWORD(sx));
  v7 = *(__m128 *)&this->M[1][0];
  v8 = _mm_shuffle_ps(*(__m128 *)bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 14);
  v9 = _mm_shuffle_ps(*(__m128 *)bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 6);
  v10 = _mm_shuffle_ps(*(__m128 *)bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 4);
  v11 = _mm_shuffle_ps(_mm_shuffle_ps(*(__m128 *)&this->M[0][0], v7, 255), _mm_shuffle_ps(v5, v6, 255), 136);
  v12 = _mm_shuffle_ps(v11, v11, 255);
  v13 = _mm_mul_ps(v8, *(__m128 *)&this->M[0][0]);
  v14 = _mm_mul_ps(v10, *(__m128 *)&this->M[0][0]);
  v15 = _mm_mul_ps(v10, v5);
  v16 = _mm_mul_ps(v9, v5);
  v17 = _mm_mul_ps(v8, v6);
  v18 = v8;
  v19 = _mm_mul_ps(v8, v5);
  v20 = _mm_mul_ps(v10, v7);
  v21 = _mm_mul_ps(
          _mm_shuffle_ps(v31, v31, 68),
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1056964608,1056964608,1056964608,1056964608>'::`2'::v);
  v22 = _mm_mul_ps(v9, *(__m128 *)&this->M[0][0]);
  v23 = _mm_mul_ps(v10, v6);
  v24 = _mm_mul_ps(v9, v7);
  v25 = _mm_mul_ps(v9, v6);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v27 = _mm_mul_ps(v18, v7);
  v28 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,3212836864,1065353216,3212836864>'::`2'::v;
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v30 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,1065353216,1065353216,1065353216>'::`2'::v;
  *(__m128 *)dest = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            _mm_div_ps(
                              _mm_add_ps(
                                _mm_shuffle_ps(
                                  _mm_unpacklo_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                                      _mm_shuffle_ps(v14, v14, 170)),
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                                      _mm_shuffle_ps(v20, v20, 170))),
                                  v26,
                                  4),
                                v11),
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                  _mm_shuffle_ps(v23, v23, 170)),
                                v12)),
                            _mm_div_ps(
                              _mm_add_ps(
                                _mm_shuffle_ps(
                                  _mm_unpacklo_ps(
                                    v29,
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                      _mm_shuffle_ps(v24, v24, 170))),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                                    _mm_shuffle_ps(v16, v16, 170)),
                                  4),
                                v11),
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                                  _mm_shuffle_ps(v25, v25, 170)),
                                v12)),
                            68),
                          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,3212836864,1065353216,3212836864>'::`2'::v),
                        (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,1065353216,1065353216,1065353216>'::`2'::v),
                      v21);
  *((__m128 *)dest + 1) = _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_div_ps(
                                  _mm_add_ps(
                                    _mm_shuffle_ps(
                                      _mm_unpacklo_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                                          _mm_shuffle_ps(v13, v13, 170)),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                                          _mm_shuffle_ps(v27, v27, 170))),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                        _mm_shuffle_ps(v19, v19, 170)),
                                      4),
                                    v11),
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                                      _mm_shuffle_ps(v17, v17, 170)),
                                    v12)),
                                v28),
                              v30),
                            v21);
}

