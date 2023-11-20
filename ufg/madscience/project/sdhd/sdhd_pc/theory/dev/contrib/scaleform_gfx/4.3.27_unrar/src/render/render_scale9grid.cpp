// File Line: 34
// RVA: 0x159C470
__int64 dynamic_initializer_for__Scaleform::Render::Image9GridVertex::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::Image9GridVertex::Format__);
}

// File Line: 39
// RVA: 0x998F00
void __fastcall Scaleform::Render::Scale9GridData::MakeMeshKey(Scaleform::Render::Scale9GridData *this, float *keyData)
{
  float *v2; // rdi
  Scaleform::Render::Scale9GridData *v3; // rbx
  float *v4; // rdx
  float v5; // eax
  Scaleform::Render::Matrix2x4<float> *v6; // rcx

  v2 = keyData;
  v3 = this;
  *keyData = this->S9Rect.x1;
  v4 = keyData + 8;
  *(v4 - 7) = this->S9Rect.y1;
  v5 = this->S9Rect.x2;
  v6 = &this->ViewMtx;
  *(v4 - 6) = v5;
  *(v4 - 5) = v6[-3].M[0][3];
  *(v4 - 4) = v6[-3].M[1][0];
  *(v4 - 3) = v6[-3].M[1][1];
  *(v4 - 2) = v6[-3].M[1][2];
  *(v4 - 1) = v6[-3].M[1][3];
  Scaleform::Render::MeshKey::CalcMatrixKey(v6, v4, 0i64);
  v2[11] = v3->ShapeMtx.M[0][3];
  v2[12] = v3->ShapeMtx.M[1][3];
}

// File Line: 61
// RVA: 0x941AF0
void __fastcall Scaleform::Render::Scale9GridInfo::Scale9GridInfo(Scaleform::Render::Scale9GridInfo *this, Scaleform::Render::Rect<float> *s9Rect, Scaleform::Render::Matrix2x4<float> *s9gMtx, Scaleform::Render::Matrix2x4<float> *shapeMtx, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Scale9GridInfo *v5; // rdi
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  Scaleform::Render::Matrix2x4<float> v17; // [rsp+30h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> v18; // [rsp+50h] [rbp-58h]

  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Scale9GridInfo,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Scale9GridInfo::`vftable;
  *(_QWORD *)&this->Scale9.x1 = 0i64;
  *(_QWORD *)&this->Scale9.x2 = 0i64;
  *(_OWORD *)&this->S9gMatrix.M[0][0] = 0x3F800000ui64;
  this->S9gMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->S9gMatrix.M[1][1] = 1065353216i64;
  this->S9gMatrix.M[1][3] = 0.0;
  *(_OWORD *)&this->ShapeMatrix.M[0][0] = 0x3F800000ui64;
  this->ShapeMatrix.M[1][0] = 0.0;
  *(_OWORD *)&this->ShapeMatrix.M[1][1] = 0x3F800000ui64;
  *(_QWORD *)&this->Bounds.y1 = 0i64;
  *(_QWORD *)&this->Bounds.y2 = 0i64;
  *(_QWORD *)&this->ResultingGrid.y1 = 0i64;
  this->ResultingGrid.y2 = 0.0;
  *(_OWORD *)&this->InverseMatrix.M[0][0] = 0x3F800000ui64;
  this->InverseMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->InverseMatrix.M[1][1] = 1065353216i64;
  this->InverseMatrix.M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[0].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[0].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[0].M[1][1] = 1065353216i64;
  this->ResultingMatrices[0].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[1].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[1].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[1].M[1][1] = 1065353216i64;
  this->ResultingMatrices[1].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[2].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[2].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[2].M[1][1] = 1065353216i64;
  this->ResultingMatrices[2].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[3].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[3].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[3].M[1][1] = 1065353216i64;
  this->ResultingMatrices[3].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[4].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[4].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[4].M[1][1] = 1065353216i64;
  this->ResultingMatrices[4].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[5].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[5].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[5].M[1][1] = 1065353216i64;
  this->ResultingMatrices[5].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[6].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[6].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[6].M[1][1] = 1065353216i64;
  this->ResultingMatrices[6].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[7].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[7].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[7].M[1][1] = 1065353216i64;
  this->ResultingMatrices[7].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[8].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[8].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[8].M[1][1] = 1065353216i64;
  this->ResultingMatrices[8].M[1][3] = 0.0;
  v6 = s9Rect->y2;
  v7 = s9Rect->x2;
  v8 = s9Rect->y1;
  this->Scale9.x1 = s9Rect->x1;
  this->Scale9.y1 = v8;
  this->Scale9.x2 = v7;
  this->Scale9.y2 = v6;
  this->S9gMatrix = *s9gMtx;
  this->ShapeMatrix = *shapeMtx;
  v9 = bounds->y2;
  v10 = bounds->x2;
  v11 = bounds->y1;
  this->Bounds.x1 = bounds->x1;
  this->Bounds.y1 = v11;
  this->Bounds.x2 = v10;
  this->Bounds.y2 = v9;
  *(_OWORD *)&v17.M[0][0] = _xmm;
  *(__m128 *)&v17.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v17, &this->S9gMatrix);
  *(_OWORD *)&v5->InverseMatrix.M[0][0] = *(_OWORD *)&v17.M[0][0];
  *(_OWORD *)&v5->InverseMatrix.M[1][0] = *(_OWORD *)&v17.M[1][0];
  *(_OWORD *)&v18.M[0][0] = _xmm;
  *(__m128 *)&v18.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v18, &v5->ShapeMatrix);
  v12 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v13 = *(__m128 *)&v5->InverseMatrix.M[0][0];
  v14 = *(__m128 *)&v5->InverseMatrix.M[1][0];
  v15 = _mm_and_ps(
          *(__m128 *)&v18.M[1][0],
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v16 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 0), v13),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 85), v14));
  *(__m128 *)&v5->InverseMatrix.M[0][0] = _mm_and_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(*(__m128 *)&v18.M[0][0], *(__m128 *)&v18.M[0][0], 0),
                                                  v13),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(*(__m128 *)&v18.M[0][0], *(__m128 *)&v18.M[0][0], 85),
                                                  v14)),
                                              _mm_and_ps(
                                                *(__m128 *)&v18.M[0][0],
                                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  *(__m128 *)&v5->InverseMatrix.M[1][0] = _mm_and_ps(_mm_add_ps(v16, v15), v12);
  Scaleform::Render::Scale9GridInfo::Compute(v5);
}

// File Line: 75
// RVA: 0x941F60
void __fastcall Scaleform::Render::Scale9GridInfo::Scale9GridInfo(Scaleform::Render::Scale9GridInfo *this, Scaleform::Render::Scale9GridData *s9g, Scaleform::Render::Matrix2x4<float> *viewMtx)
{
  __m128 *v3; // rdi
  Scaleform::Render::Scale9GridData *v4; // r9
  Scaleform::Render::Scale9GridInfo *v5; // rsi
  Scaleform::Render::Matrix2x4<float> *v6; // rdx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  __m128 v16; // xmm8
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+30h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> v20; // [rsp+50h] [rbp-58h]

  v3 = (__m128 *)viewMtx;
  v4 = s9g;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Scale9GridInfo,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Scale9GridInfo::`vftable;
  *(_QWORD *)&this->Scale9.x1 = 0i64;
  *(_QWORD *)&this->Scale9.x2 = 0i64;
  v6 = &this->S9gMatrix;
  *(_QWORD *)&v6->M[0][0] = 1065353216i64;
  *(_QWORD *)&v6->M[0][2] = 0i64;
  v6->M[1][0] = 0.0;
  *(_QWORD *)&v6->M[1][1] = 1065353216i64;
  v6->M[1][3] = 0.0;
  *(_OWORD *)&this->ShapeMatrix.M[0][0] = 0x3F800000ui64;
  this->ShapeMatrix.M[1][0] = 0.0;
  *(_OWORD *)&this->ShapeMatrix.M[1][1] = 0x3F800000ui64;
  *(_QWORD *)&this->Bounds.y1 = 0i64;
  *(_QWORD *)&this->Bounds.y2 = 0i64;
  *(_QWORD *)&this->ResultingGrid.y1 = 0i64;
  this->ResultingGrid.y2 = 0.0;
  *(_OWORD *)&this->InverseMatrix.M[0][0] = 0x3F800000ui64;
  this->InverseMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->InverseMatrix.M[1][1] = 1065353216i64;
  this->InverseMatrix.M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[0].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[0].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[0].M[1][1] = 1065353216i64;
  this->ResultingMatrices[0].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[1].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[1].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[1].M[1][1] = 1065353216i64;
  this->ResultingMatrices[1].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[2].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[2].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[2].M[1][1] = 1065353216i64;
  this->ResultingMatrices[2].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[3].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[3].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[3].M[1][1] = 1065353216i64;
  this->ResultingMatrices[3].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[4].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[4].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[4].M[1][1] = 1065353216i64;
  this->ResultingMatrices[4].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[5].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[5].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[5].M[1][1] = 1065353216i64;
  this->ResultingMatrices[5].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[6].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[6].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[6].M[1][1] = 1065353216i64;
  this->ResultingMatrices[6].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[7].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[7].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[7].M[1][1] = 1065353216i64;
  this->ResultingMatrices[7].M[1][3] = 0.0;
  *(_OWORD *)&this->ResultingMatrices[8].M[0][0] = 0x3F800000ui64;
  this->ResultingMatrices[8].M[1][0] = 0.0;
  *(_QWORD *)&this->ResultingMatrices[8].M[1][1] = 1065353216i64;
  this->ResultingMatrices[8].M[1][3] = 0.0;
  v7 = v4->S9Rect.y2;
  v8 = v4->S9Rect.x2;
  v9 = v4->S9Rect.y1;
  this->Scale9.x1 = v4->S9Rect.x1;
  this->Scale9.y1 = v9;
  this->Scale9.x2 = v8;
  this->Scale9.y2 = v7;
  v6->M[0][0] = v4->Scale9Mtx.M[0][0];
  v6->M[0][1] = v4->Scale9Mtx.M[0][1];
  v6->M[0][2] = v4->Scale9Mtx.M[0][2];
  v6->M[0][3] = v4->Scale9Mtx.M[0][3];
  v6->M[1][0] = v4->Scale9Mtx.M[1][0];
  v6->M[1][1] = v4->Scale9Mtx.M[1][1];
  v6->M[1][2] = v4->Scale9Mtx.M[1][2];
  v6->M[1][3] = v4->Scale9Mtx.M[1][3];
  *(_OWORD *)&this->ShapeMatrix.M[0][0] = *(_OWORD *)&v4->ShapeMtx.M[0][0];
  *(_OWORD *)&this->ShapeMatrix.M[1][0] = *(_OWORD *)&v4->ShapeMtx.M[1][0];
  v10 = v4->Bounds.y2;
  v11 = v4->Bounds.x2;
  v12 = v4->Bounds.y1;
  this->Bounds.x1 = v4->Bounds.x1;
  this->Bounds.y1 = v12;
  this->Bounds.x2 = v11;
  this->Bounds.y2 = v10;
  *(_OWORD *)&v19.M[0][0] = _xmm;
  *(__m128 *)&v19.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v19, &this->S9gMatrix);
  *(_OWORD *)&v5->InverseMatrix.M[0][0] = *(_OWORD *)&v19.M[0][0];
  *(_OWORD *)&v5->InverseMatrix.M[1][0] = *(_OWORD *)&v19.M[1][0];
  *(_OWORD *)&v20.M[0][0] = _xmm;
  *(__m128 *)&v20.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v20, &v5->ShapeMatrix);
  v13 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v14 = _mm_and_ps(
          *(__m128 *)&v20.M[1][0],
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v15 = _mm_add_ps(
          _mm_mul_ps(
            *(__m128 *)&v5->InverseMatrix.M[1][0],
            _mm_shuffle_ps(*(__m128 *)&v20.M[1][0], *(__m128 *)&v20.M[1][0], 85)),
          _mm_mul_ps(
            *(__m128 *)&v5->InverseMatrix.M[0][0],
            _mm_shuffle_ps(*(__m128 *)&v20.M[1][0], *(__m128 *)&v20.M[1][0], 0)));
  *(__m128 *)&v5->InverseMatrix.M[0][0] = _mm_and_ps(
                                            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  *(__m128 *)&v5->InverseMatrix.M[0][0],
                                                  _mm_shuffle_ps(*(__m128 *)&v20.M[0][0], *(__m128 *)&v20.M[0][0], 0)),
                                                _mm_mul_ps(
                                                  *(__m128 *)&v5->InverseMatrix.M[1][0],
                                                  _mm_shuffle_ps(*(__m128 *)&v20.M[0][0], *(__m128 *)&v20.M[0][0], 85))),
                                              _mm_and_ps(
                                                *(__m128 *)&v20.M[0][0],
                                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)));
  *(__m128 *)&v5->InverseMatrix.M[1][0] = _mm_and_ps(v13, _mm_add_ps(v15, v14));
  v16 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v17 = _mm_and_ps(v3[1], (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v18 = _mm_add_ps(
          _mm_mul_ps(*(__m128 *)&v5->InverseMatrix.M[0][0], _mm_shuffle_ps(v3[1], v3[1], 0)),
          _mm_mul_ps(*(__m128 *)&v5->InverseMatrix.M[1][0], _mm_shuffle_ps(v3[1], v3[1], 85)));
  *(__m128 *)&v5->InverseMatrix.M[0][0] = _mm_and_ps(
                                            (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  *(__m128 *)&v5->InverseMatrix.M[0][0],
                                                  _mm_shuffle_ps(*v3, *v3, 0)),
                                                _mm_mul_ps(
                                                  *(__m128 *)&v5->InverseMatrix.M[1][0],
                                                  _mm_shuffle_ps(*v3, *v3, 85))),
                                              _mm_and_ps(
                                                *v3,
                                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)));
  *(__m128 *)&v5->InverseMatrix.M[1][0] = _mm_and_ps(v16, _mm_add_ps(v18, v17));
  Scaleform::Render::Scale9GridInfo::Compute(v5);
}

// File Line: 87
// RVA: 0x961A00
void __fastcall Scaleform::Render::Scale9GridInfo::Compute(Scaleform::Render::Scale9GridInfo *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  Scaleform::Render::Scale9GridInfo *v3; // rbx
  float v4; // xmm8_4
  float v5; // xmm11_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm14_4
  float v16; // xmm4_4
  __m128 v17; // xmm2
  __m128 v18; // xmm15
  float v19; // xmm5_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  __m128 v23; // xmm13
  float v24; // xmm0_4
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  float v28; // xmm14_4
  float v29; // xmm7_4
  __m128 v30; // xmm0
  float v31; // xmm5_4
  __m128 v32; // xmm1
  float v33; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm4_4
  float v36; // xmm3_4
  float v37; // xmm15_4
  float v38; // xmm9_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm7_4
  float v42; // xmm2_4
  float v43; // xmm5_4
  float v44; // xmm10_4
  float v45; // xmm3_4
  float v46; // xmm12_4
  float v47; // xmm13_4
  int v48; // xmm11_4
  int v49; // xmm14_4
  float v50; // xmm8_4
  float v51; // xmm4_4
  float v52; // xmm0_4
  float v53; // xmm6_4
  int v54; // xmm9_4
  int v55; // xmm7_4
  float v56; // xmm2_4
  float v57; // xmm15_4
  int v58; // xmm14_4
  float v59; // xmm11_4
  int v60; // xmm13_4
  float v61; // xmm10_4
  float v62; // xmm13_4
  float v63; // xmm10_4
  float v64; // xmm12_4
  float v65; // xmm8_4
  float v66; // xmm6_4
  int v67; // xmm8_4
  float v68; // xmm6_4
  int v69; // xmm9_4
  int v70; // xmm7_4
  int v71; // xmm12_4
  int v72; // xmm10_4
  float v73; // xmm10_4
  int v74; // xmm14_4
  float dst; // [rsp+20h] [rbp-D0h]
  float v76; // [rsp+24h] [rbp-CCh]
  float v77; // [rsp+28h] [rbp-C8h]
  float v78; // [rsp+2Ch] [rbp-C4h]
  float v79; // [rsp+30h] [rbp-C0h]
  float v80; // [rsp+34h] [rbp-BCh]
  float src; // [rsp+38h] [rbp-B8h]
  float v82; // [rsp+3Ch] [rbp-B4h]
  float v83; // [rsp+40h] [rbp-B0h]
  float v84; // [rsp+44h] [rbp-ACh]
  float v85; // [rsp+48h] [rbp-A8h]
  float v86; // [rsp+4Ch] [rbp-A4h]
  float v87; // [rsp+50h] [rbp-A0h]
  float v88; // [rsp+54h] [rbp-9Ch]
  float v89; // [rsp+58h] [rbp-98h]
  float v90; // [rsp+5Ch] [rbp-94h]
  float v91; // [rsp+60h] [rbp-90h]
  float v92; // [rsp+64h] [rbp-8Ch]
  float v93; // [rsp+68h] [rbp-88h]
  float v94; // [rsp+6Ch] [rbp-84h]
  float v95; // [rsp+70h] [rbp-80h]
  float v96; // [rsp+74h] [rbp-7Ch]
  float v97; // [rsp+78h] [rbp-78h]
  float v98; // [rsp+7Ch] [rbp-74h]
  float v99; // [rsp+80h] [rbp-70h]
  float v100; // [rsp+84h] [rbp-6Ch]
  float v101; // [rsp+88h] [rbp-68h]
  float v102; // [rsp+8Ch] [rbp-64h]
  float v103; // [rsp+90h] [rbp-60h]
  float v104; // [rsp+94h] [rbp-5Ch]
  float v105; // [rsp+98h] [rbp-58h]
  float v106; // [rsp+9Ch] [rbp-54h]
  float v107; // [rsp+A0h] [rbp-50h]
  float v108; // [rsp+A4h] [rbp-4Ch]
  float vars0; // [rsp+170h] [rbp+80h]
  float retaddr; // [rsp+178h] [rbp+88h]
  float v111; // [rsp+180h] [rbp+90h]
  float v112; // [rsp+188h] [rbp+98h]

  v1 = this->Scale9.x2;
  v2 = this->Scale9.y2;
  v3 = this;
  v4 = this->Bounds.y1;
  v111 = this->Scale9.x2;
  v89 = this->Scale9.y2;
  v5 = this->Bounds.x1;
  v6 = this->Bounds.x2;
  v7 = this->Bounds.y2;
  v8 = this->Scale9.x1;
  v9 = this->Scale9.y1;
  retaddr = this->Scale9.x1;
  vars0 = this->Scale9.y1;
  v96 = v4;
  v95 = v6;
  v99 = v7;
  if ( v5 >= v8 )
  {
    v5 = v8 - 0.89999998;
    v95 = v8 - 0.89999998;
  }
  if ( v4 >= v9 )
  {
    v4 = v9 - 0.89999998;
    v96 = v9 - 0.89999998;
  }
  if ( v6 <= v1 )
  {
    v6 = v8 + 0.89999998;
    v95 = v8 + 0.89999998;
  }
  if ( v7 <= v2 )
  {
    v7 = v9 + 0.89999998;
    v99 = v9 + 0.89999998;
  }
  v10 = this->S9gMatrix.M[0][3];
  v11 = this->S9gMatrix.M[0][0];
  v12 = v11;
  v13 = v11 * v6;
  v14 = this->S9gMatrix.M[0][1] * v4;
  v15 = this->S9gMatrix.M[0][1] * v7;
  v16 = this->S9gMatrix.M[1][3];
  v17 = (__m128)LODWORD(this->S9gMatrix.M[1][0]);
  v18 = (__m128)LODWORD(this->S9gMatrix.M[1][1]);
  v19 = v17.m128_f32[0];
  v17.m128_f32[0] = v17.m128_f32[0] * v6;
  v20 = v19 * v5;
  v97 = (float)((float)(v12 * v5) + v14) + v10;
  v21 = v18.m128_f32[0];
  v18.m128_f32[0] = v18.m128_f32[0] * v7;
  v22 = v21 * v4;
  v112 = (float)(v20 + v22) + v16;
  v23 = v17;
  v23.m128_f32[0] = v17.m128_f32[0] + v22;
  v94 = (float)(v13 + v14) + v10;
  v24 = v15 + v13;
  v23.m128_f32[0] = v23.m128_f32[0] + v16;
  v25 = v18;
  v90 = v24 + v10;
  v25.m128_f32[0] = (float)(v18.m128_f32[0] + v17.m128_f32[0]) + v16;
  v26 = v23;
  v26.m128_f32[0] = v23.m128_f32[0] - v112;
  v27 = v26;
  v87 = v23.m128_f32[0] - v112;
  v28 = v97;
  v93 = v90 - v94;
  v29 = v94 - v97;
  v100 = v23.m128_f32[0];
  v96 = (float)(v18.m128_f32[0] + v17.m128_f32[0]) + v16;
  v97 = (float)(v18.m128_f32[0] + v20) + v16;
  v91 = v29;
  v27.m128_f32[0] = (float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v29 * v29);
  v30 = v25;
  v30.m128_f32[0] = v25.m128_f32[0] - v23.m128_f32[0];
  LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v27);
  v32 = v30;
  v98 = v25.m128_f32[0] - v23.m128_f32[0];
  v32.m128_f32[0] = (float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v93 * v93);
  LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v32);
  if ( v31 == 0.0 )
    v31 = FLOAT_0_001;
  if ( v33 == 0.0 )
    v33 = FLOAT_0_001;
  v34 = 1.0 / v33;
  v35 = (float)(v6 - v111) * (float)(1.0 / v31);
  v36 = (float)(retaddr - v5) * (float)(1.0 / v31);
  v37 = (float)(v9 - v4) * v34;
  v92 = v36;
  v88 = v35;
  v38 = (float)(v7 - v89) * v34;
  if ( (float)(v35 + v36) > 1.0 )
  {
    v39 = 1.0 / (float)((float)(v35 + v36) + 0.050000001);
    v36 = v36 * v39;
    v35 = v35 * v39;
    v92 = v36;
    v88 = v35;
  }
  if ( (float)(v38 + v37) > 1.0 )
  {
    v40 = 1.0 / (float)((float)(v38 + v37) + 0.050000001);
    v37 = v37 * v40;
    v38 = v38 * v40;
  }
  v41 = v29 * v36;
  v42 = v87 * v35;
  v91 = v91 * v35;
  v43 = v87 * v36;
  v108 = v94 - v91;
  v44 = (float)(v87 * v36) + v112;
  v45 = (float)(v93 * v37) + v94;
  v46 = v100 - (float)(v87 * v35);
  v106 = (float)(v93 * v37) + v94;
  v47 = v41 + v28;
  *(float *)&v48 = v96 - (float)(v98 * v38);
  *(float *)&v49 = v90 - (float)(v93 * v38);
  v50 = (float)((float)(v98 - v97) * v37) + v97;
  v51 = v98 - (float)((float)(v98 - v97) * v38);
  v98 = (float)(v98 * v37) + v100;
  v52 = (float)(v97 - v112) * v38;
  v53 = (float)((float)(v97 - v112) * v37) + v112;
  v93 = v41 + v50;
  *(float *)&v54 = v45 - v91;
  *(float *)&v55 = v98 - v42;
  v56 = v97 - v52;
  v103 = *(float *)&v49;
  v107 = *(float *)&v48;
  v105 = v51;
  v102 = v97 - v52;
  v101 = v43 + v53;
  v91 = (float)(v90 - v98) * v88;
  v87 = *(float *)&v49 - v91;
  v104 = (float)(v96 - v97) * v88;
  v88 = *(float *)&v48 - v104;
  v57 = (float)(v96 - v97) * v92;
  src = v95;
  v92 = (float)(v90 - v98) * v92;
  v83 = retaddr;
  dst = v97;
  v85 = retaddr;
  v76 = v112;
  v79 = v93;
  v77 = v47;
  v82 = v96;
  v84 = v96;
  v78 = v43 + v112;
  v80 = v43 + v53;
  v86 = vars0;
  *(float *)&v58 = v92 + v51;
  v59 = v57 + (float)(v97 - v52);
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(this->ResultingMatrices, &src, &dst);
  dst = v47;
  *(float *)&v60 = v96;
  src = retaddr;
  v76 = v44;
  v61 = v108;
  v83 = v111;
  v85 = v111;
  v77 = v108;
  v78 = v46;
  v86 = vars0;
  v79 = *(float *)&v54;
  v80 = *(float *)&v55;
  v82 = v96;
  v84 = v96;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[1], &src, &dst);
  v77 = v94;
  v82 = *(float *)&v60;
  v84 = *(float *)&v60;
  v62 = v95;
  v83 = v95;
  dst = v61;
  v63 = v98;
  v76 = v46;
  v64 = v106;
  v86 = vars0;
  v78 = v100;
  v79 = v106;
  v80 = v98;
  src = v111;
  v85 = v95;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[2], &src, &dst);
  dst = v50;
  v65 = v93;
  v76 = v53;
  v66 = v101;
  v77 = v93;
  v78 = v101;
  src = v95;
  v79 = *(float *)&v58;
  v82 = vars0;
  v84 = vars0;
  v86 = v89;
  v80 = v57 + v56;
  v83 = retaddr;
  v85 = retaddr;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[3], &src, &dst);
  src = retaddr;
  dst = v65;
  *(float *)&v67 = v87;
  v82 = vars0;
  v84 = vars0;
  v76 = v66;
  v68 = v88;
  v86 = v89;
  v77 = *(float *)&v54;
  v78 = *(float *)&v55;
  v79 = v87;
  v80 = v88;
  v83 = v111;
  v85 = v111;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[4], &src, &dst);
  dst = *(float *)&v54;
  *(float *)&v69 = v103;
  v76 = *(float *)&v55;
  *(float *)&v70 = v107;
  v77 = v64;
  v71 = LODWORD(vars0);
  v78 = v63;
  *(float *)&v72 = v89;
  v79 = v103;
  v80 = v107;
  v82 = vars0;
  v84 = vars0;
  v86 = v89;
  src = v111;
  v83 = v62;
  v85 = v62;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[5], &src, &dst);
  v82 = *(float *)&v72;
  dst = v105;
  v80 = v57 + v97;
  v76 = v102;
  v84 = *(float *)&v72;
  v73 = v99;
  v79 = v92 + v98;
  v77 = *(float *)&v58;
  src = v95;
  v78 = v59;
  v83 = retaddr;
  v85 = retaddr;
  v86 = v99;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[6], &src, &dst);
  dst = *(float *)&v58;
  *(float *)&v74 = v89;
  v76 = v59;
  v79 = v90 - v91;
  v80 = v96 - v104;
  v77 = *(float *)&v67;
  v78 = v68;
  src = retaddr;
  v82 = v89;
  v83 = v111;
  v84 = v89;
  v85 = v111;
  v86 = v73;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[7], &src, &dst);
  dst = *(float *)&v67;
  v76 = v68;
  v79 = v90;
  v77 = *(float *)&v69;
  v80 = v96;
  v78 = *(float *)&v70;
  src = v111;
  v82 = *(float *)&v74;
  v83 = v62;
  v84 = *(float *)&v74;
  v85 = v62;
  v86 = v73;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v3->ResultingMatrices[8], &src, &dst);
  v3->ResultingGrid.x1 = retaddr;
  LODWORD(v3->ResultingGrid.y1) = v71;
  v3->ResultingGrid.x2 = v111;
  v3->ResultingGrid.y2 = *(float *)&v74;
}

// File Line: 261
// RVA: 0x9BA660
__int64 __fastcall Scaleform::Render::Scale9GridInfo::Transform(Scaleform::Render::Scale9GridInfo *this, float *x, float *y)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float *v5; // r10
  float *v6; // r9
  float v7; // xmm3_4
  float v8; // xmm2_4
  __int64 v9; // rdx
  __int64 result; // rax
  float *v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm2_4

  v3 = *x;
  v4 = *y;
  v5 = (float *)this;
  v6 = x;
  *x = (float)((float)(*y * this->ShapeMatrix.M[0][1]) + (float)(*x * this->ShapeMatrix.M[0][0]))
     + this->ShapeMatrix.M[0][3];
  v7 = (float)((float)(v4 * this->ShapeMatrix.M[1][1]) + (float)(v3 * this->ShapeMatrix.M[1][0]))
     + this->ShapeMatrix.M[1][3];
  *y = v7;
  v8 = *x;
  v9 = (*x > this->ResultingGrid.x2) | 2
                                     * ((v7 > this->ResultingGrid.y2) | 2
                                                                      * ((*x < v5[28]) | 2 * (unsigned int)(v7 < v5[29])));
  result = (unsigned int)v9;
  v11 = (float *)((char *)this + 32 * ((unsigned __int8)codeToMtx[v9] + 5i64));
  *v6 = (float)((float)(v7 * v11[1]) + (float)(v8 * *v11)) + v11[3];
  v12 = (float)((float)(v7 * v11[5]) + (float)(v8 * v11[4])) + v11[7];
  *y = v12;
  v13 = *v6;
  *v6 = (float)((float)(v12 * v5[33]) + (float)(*v6 * v5[32])) + v5[35];
  *y = (float)((float)(v12 * v5[37]) + (float)(v13 * v5[36])) + v5[39];
  return result;
}

// File Line: 292
// RVA: 0x98B260
float __fastcall Scaleform::Render::Scale9GridInfo::GetScale(Scaleform::Render::Scale9GridInfo *this)
{
  __m128 v1; // xmm0
  float v2; // xmm1_4
  float v3; // xmm3_4
  __m128 v4; // xmm0
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  __m128 v8; // xmm0
  float v9; // xmm1_4
  float v10; // xmm3_4
  __m128 v11; // xmm0
  float v12; // xmm1_4
  float v13; // xmm3_4
  __m128 v14; // xmm0
  float v15; // xmm1_4
  float v16; // xmm3_4
  __m128 v17; // xmm0
  float v18; // xmm1_4
  float v19; // xmm3_4
  __m128 v20; // xmm0
  float v21; // xmm1_4
  float v22; // xmm3_4
  __m128 v23; // xmm0
  __m128 v24; // xmm1

  v1 = (__m128)LODWORD(this->ResultingMatrices[0].M[1][1]);
  v2 = (float)(this->ResultingMatrices[0].M[0][1] + this->ResultingMatrices[0].M[0][0]) * 0.70710677;
  v1.m128_f32[0] = (float)((float)((float)(v1.m128_f32[0] + this->ResultingMatrices[0].M[1][0]) * 0.70710677)
                         * (float)((float)(v1.m128_f32[0] + this->ResultingMatrices[0].M[1][0]) * 0.70710677))
                 + (float)(v2 * v2);
  LODWORD(v3) = (unsigned __int128)_mm_sqrt_ps(v1);
  v4 = (__m128)LODWORD(this->ResultingMatrices[1].M[1][1]);
  v5 = (float)(this->ResultingMatrices[1].M[0][1] + this->ResultingMatrices[1].M[0][0]) * 0.70710677;
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] + this->ResultingMatrices[1].M[1][0]) * 0.70710677)
                         * (float)((float)(v4.m128_f32[0] + this->ResultingMatrices[1].M[1][0]) * 0.70710677))
                 + (float)(v5 * v5);
  v6 = (float)(this->ResultingMatrices[2].M[0][1] + this->ResultingMatrices[2].M[0][0]) * 0.70710677;
  v7 = v3 + COERCE_FLOAT(_mm_sqrt_ps(v4));
  v8 = (__m128)LODWORD(this->ResultingMatrices[2].M[1][1]);
  v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] + this->ResultingMatrices[2].M[1][0]) * 0.70710677)
                         * (float)((float)(v8.m128_f32[0] + this->ResultingMatrices[2].M[1][0]) * 0.70710677))
                 + (float)(v6 * v6);
  v9 = (float)(this->ResultingMatrices[3].M[0][1] + this->ResultingMatrices[3].M[0][0]) * 0.70710677;
  v10 = v7 + COERCE_FLOAT(_mm_sqrt_ps(v8));
  v11 = (__m128)LODWORD(this->ResultingMatrices[3].M[1][1]);
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] + this->ResultingMatrices[3].M[1][0]) * 0.70710677)
                          * (float)((float)(v11.m128_f32[0] + this->ResultingMatrices[3].M[1][0]) * 0.70710677))
                  + (float)(v9 * v9);
  v12 = (float)(this->ResultingMatrices[4].M[0][1] + this->ResultingMatrices[4].M[0][0]) * 0.70710677;
  v13 = v10 + COERCE_FLOAT(_mm_sqrt_ps(v11));
  v14 = (__m128)LODWORD(this->ResultingMatrices[4].M[1][1]);
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] + this->ResultingMatrices[4].M[1][0]) * 0.70710677)
                          * (float)((float)(v14.m128_f32[0] + this->ResultingMatrices[4].M[1][0]) * 0.70710677))
                  + (float)(v12 * v12);
  v15 = (float)(this->ResultingMatrices[5].M[0][1] + this->ResultingMatrices[5].M[0][0]) * 0.70710677;
  v16 = v13 + COERCE_FLOAT(_mm_sqrt_ps(v14));
  v17 = (__m128)LODWORD(this->ResultingMatrices[5].M[1][1]);
  v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] + this->ResultingMatrices[5].M[1][0]) * 0.70710677)
                          * (float)((float)(v17.m128_f32[0] + this->ResultingMatrices[5].M[1][0]) * 0.70710677))
                  + (float)(v15 * v15);
  v18 = (float)(this->ResultingMatrices[6].M[0][1] + this->ResultingMatrices[6].M[0][0]) * 0.70710677;
  v19 = v16 + COERCE_FLOAT(_mm_sqrt_ps(v17));
  v20 = (__m128)LODWORD(this->ResultingMatrices[6].M[1][1]);
  v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] + this->ResultingMatrices[6].M[1][0]) * 0.70710677)
                          * (float)((float)(v20.m128_f32[0] + this->ResultingMatrices[6].M[1][0]) * 0.70710677))
                  + (float)(v18 * v18);
  v21 = (float)(this->ResultingMatrices[7].M[0][1] + this->ResultingMatrices[7].M[0][0]) * 0.70710677;
  v22 = v19 + COERCE_FLOAT(_mm_sqrt_ps(v20));
  v23 = (__m128)LODWORD(this->ResultingMatrices[7].M[1][1]);
  v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] + this->ResultingMatrices[7].M[1][0]) * 0.70710677)
                          * (float)((float)(v23.m128_f32[0] + this->ResultingMatrices[7].M[1][0]) * 0.70710677))
                  + (float)(v21 * v21);
  v24 = (__m128)LODWORD(this->ResultingMatrices[8].M[1][1]);
  v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] + this->ResultingMatrices[8].M[1][0]) * 0.70710677)
                          * (float)((float)(v24.m128_f32[0] + this->ResultingMatrices[8].M[1][0]) * 0.70710677))
                  + (float)((float)((float)(this->ResultingMatrices[8].M[0][1] + this->ResultingMatrices[8].M[0][0])
                                  * 0.70710677)
                          * (float)((float)(this->ResultingMatrices[8].M[0][1] + this->ResultingMatrices[8].M[0][0])
                                  * 0.70710677));
  return (float)((float)(v22 + COERCE_FLOAT(_mm_sqrt_ps(v23))) + COERCE_FLOAT(_mm_sqrt_ps(v24))) * 0.11111111;
}

// File Line: 302
// RVA: 0x990120
float __fastcall Scaleform::Render::Scale9GridInfo::GetXScale(Scaleform::Render::Scale9GridInfo *this)
{
  __m128 v1; // xmm1
  float v2; // xmm3_4
  __m128 v3; // xmm1
  float v4; // xmm3_4
  __m128 v5; // xmm1

  v1 = (__m128)LODWORD(this->ResultingMatrices[0].M[0][0]);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0])
                 + (float)(this->ResultingMatrices[0].M[1][0] * this->ResultingMatrices[0].M[1][0]);
  LODWORD(v2) = (unsigned __int128)_mm_sqrt_ps(v1);
  v3 = (__m128)LODWORD(this->ResultingMatrices[1].M[0][0]);
  v3.m128_f32[0] = (float)(v3.m128_f32[0] * v3.m128_f32[0])
                 + (float)(this->ResultingMatrices[1].M[1][0] * this->ResultingMatrices[1].M[1][0]);
  v4 = v2 + COERCE_FLOAT(_mm_sqrt_ps(v3));
  v5 = (__m128)LODWORD(this->ResultingMatrices[2].M[0][0]);
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0])
                 + (float)(this->ResultingMatrices[2].M[1][0] * this->ResultingMatrices[2].M[1][0]);
  return (float)(v4 + COERCE_FLOAT(_mm_sqrt_ps(v5))) * 0.33333334;
}

// File Line: 312
// RVA: 0x9901A0
float __fastcall Scaleform::Render::Scale9GridInfo::GetYScale(Scaleform::Render::Scale9GridInfo *this)
{
  float v1; // xmm0_4
  float *v2; // rcx
  signed __int64 v3; // rax
  __m128 v4; // xmm2
  float v5; // xmm1_4

  v1 = 0.0;
  v2 = &this->ResultingMatrices[0].M[0][1];
  v3 = 3i64;
  do
  {
    v4 = (__m128)*((unsigned int *)v2 + 4);
    v5 = *v2;
    v2 += 24;
    v4.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v5 * v5);
    v1 = v1 + COERCE_FLOAT(_mm_sqrt_ps(v4));
    --v3;
  }
  while ( v3 );
  return v1 * 0.33333334;
}

// File Line: 333
// RVA: 0x955290
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Scale9GridInfo::AdjustBounds(Scaleform::Render::Scale9GridInfo *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Scale9GridInfo *v3; // r9
  float v4; // xmm5_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm9_4
  float v10; // xmm13_4
  float v11; // xmm12_4
  float v12; // xmm14_4
  float v13; // xmm15_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm5_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float *v26; // rax
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float *v32; // rax
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float *v38; // rcx
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm7_4
  float v43; // xmm9_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  Scaleform::Render::Rect<float> *v51; // rax
  float v52; // [rsp+0h] [rbp-B8h]
  float v53; // [rsp+4h] [rbp-B4h]
  float v54; // [rsp+C0h] [rbp+8h]
  float v55; // [rsp+C8h] [rbp+10h]
  float v56; // [rsp+D0h] [rbp+18h]
  float v57; // [rsp+D8h] [rbp+20h]

  v3 = this;
  v4 = bounds->y1;
  v5 = this->InverseMatrix.M[0][3];
  v6 = this->InverseMatrix.M[1][1];
  v7 = this->ResultingGrid.y1;
  v8 = this->ResultingGrid.x1;
  v9 = this->InverseMatrix.M[0][1];
  v10 = this->ShapeMatrix.M[1][1];
  v11 = this->ShapeMatrix.M[1][3];
  v12 = this->ShapeMatrix.M[0][3];
  v13 = this->ResultingGrid.y2;
  v14 = this->InverseMatrix.M[1][3];
  v15 = (float)((float)(this->ShapeMatrix.M[0][0] * bounds->x1) + (float)(this->ShapeMatrix.M[0][1] * v4)) + v12;
  v16 = (float)((float)(this->ShapeMatrix.M[1][0] * bounds->x1) + (float)(v10 * v4)) + v11;
  v17 = (float *)((char *)v3
                + 32
                * ((unsigned __int8)codeToMtx[(v15 > v3->ResultingGrid.x2) | (unsigned __int64)(2
                                                                                              * ((v16 > v13) | 2 * ((v8 > v15) | 2 * (unsigned int)(v7 > v16))))]
                 + 5i64));
  v18 = (float)((float)(v16 * v17[1]) + (float)(v15 * *v17)) + v17[3];
  v19 = (float)((float)(v16 * v17[5]) + (float)(v15 * v17[4])) + v17[7];
  v54 = (float)((float)(this->InverseMatrix.M[0][0] * v18) + (float)(v9 * v19)) + v5;
  v20 = bounds->x2;
  v55 = (float)((float)(this->InverseMatrix.M[1][0] * v18) + (float)(v6 * v19)) + v14;
  v21 = (float)((float)(this->ShapeMatrix.M[0][0] * v20) + (float)(this->ShapeMatrix.M[0][1] * v4)) + v12;
  v22 = v10 * v4;
  v23 = bounds->y2;
  v24 = (float)((float)(this->ShapeMatrix.M[1][0] * v20) + v22) + v11;
  v25 = v24;
  v26 = (float *)((char *)v3
                + 32
                * ((unsigned __int8)codeToMtx[(v21 > v3->ResultingGrid.x2) | (unsigned __int64)(2
                                                                                              * ((v24 > v13) | 2 * ((v8 > v21) | 2 * (unsigned int)(v7 > v24))))]
                 + 5i64));
  v27 = (float)((float)(v24 * v26[5]) + (float)(v21 * v26[4])) + v26[7];
  v28 = (float)((float)(v25 * v26[1]) + (float)(v21 * *v26)) + v26[3];
  v56 = (float)((float)(this->InverseMatrix.M[0][0] * v28) + (float)(v9 * v27)) + v5;
  v57 = (float)((float)(this->InverseMatrix.M[1][0] * v28) + (float)(v6 * v27)) + v14;
  v29 = (float)((float)(this->ShapeMatrix.M[0][0] * v20) + (float)(this->ShapeMatrix.M[0][1] * v23)) + v12;
  v30 = (float)((float)(this->ShapeMatrix.M[1][0] * v20) + (float)(v10 * v23)) + v11;
  v31 = v30;
  v32 = (float *)((char *)v3
                + 32
                * ((unsigned __int8)codeToMtx[(v29 > v3->ResultingGrid.x2) | (unsigned __int64)(2
                                                                                              * ((v30 > v13) | 2 * ((v8 > v29) | 2 * (unsigned int)(v7 > v30))))]
                 + 5i64));
  v33 = (float)((float)(v30 * v32[5]) + (float)(v29 * v32[4])) + v32[7];
  v34 = (float)((float)(v31 * v32[1]) + (float)(v29 * *v32)) + v32[3];
  v52 = (float)((float)(this->InverseMatrix.M[0][0] * v34) + (float)(v9 * v33)) + v5;
  v35 = (float)(this->InverseMatrix.M[1][0] * v34) + (float)(v6 * v33);
  v36 = (float)((float)(this->ShapeMatrix.M[1][0] * bounds->x1) + (float)(v10 * v23)) + v11;
  v53 = v35 + v14;
  v37 = (float)((float)(this->ShapeMatrix.M[0][0] * bounds->x1) + (float)(this->ShapeMatrix.M[0][1] * v23)) + v12;
  v38 = (float *)((char *)this
                + 32
                * ((unsigned __int8)codeToMtx[(v37 > this->ResultingGrid.x2) | (unsigned __int64)(2
                                                                                                * ((v36 > v13) | 2 * ((v8 > v37) | 2 * (unsigned int)(v7 > v36))))]
                 + 5i64));
  v39 = (float)((float)(v36 * v38[1]) + (float)(v37 * *v38)) + v38[3];
  v40 = (float)((float)(v36 * v38[5]) + (float)(v37 * v38[4])) + v38[7];
  v41 = v55;
  v42 = v6 * v40;
  v43 = v9 * v40;
  v44 = v55;
  v45 = v3->InverseMatrix.M[1][0] * v39;
  v46 = v3->InverseMatrix.M[0][0] * v39;
  v47 = v54;
  v48 = v54;
  v49 = (float)(v46 + v43) + v5;
  v50 = (float)(v45 + v42) + v14;
  if ( v56 < v54 )
    v48 = v56;
  if ( v57 < v55 )
    v44 = v57;
  if ( v56 > v54 )
    v47 = v56;
  if ( v57 > v55 )
    v41 = v57;
  if ( v52 < v48 )
    v48 = v52;
  if ( v53 < v44 )
    v44 = v53;
  if ( v52 > v47 )
    v47 = v52;
  if ( v53 > v41 )
    v41 = v53;
  if ( v49 < v48 )
    v48 = v49;
  if ( v50 < v44 )
    v44 = v50;
  if ( v49 > v47 )
    v47 = v49;
  if ( v50 > v41 )
    v41 = v50;
  result->x1 = v48;
  result->y1 = v44;
  v51 = result;
  result->x2 = v47;
  result->y2 = v41;
  return v51;
}

// File Line: 396
// RVA: 0x9CB4E0
void __fastcall Scaleform::Render::Scale9GridTess::addVertices(Scaleform::Render::Scale9GridTess *this, Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver, Scaleform::Render::Matrix2x4<float> *toUV, float x, float y, unsigned int code1, unsigned int code2)
{
  Scaleform::Render::Scale9GridTess *v7; // rdi
  unsigned int v8; // ecx
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float *v16; // rax
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [rsp+20h] [rbp-68h]
  Scaleform::Render::Scale9GridTess::TmpVertexType v18; // [rsp+30h] [rbp-58h]

  v7 = this;
  v8 = this->VerCount;
  v9 = ver;
  val.AreaCode = code1;
  v10 = x * toUV->M[0][0];
  v11 = x * toUV->M[1][0];
  val.VerIdx = v8;
  v18.VerIdx = v8;
  v12 = y * toUV->M[0][1];
  val.Slope = 0.0;
  v18.AreaCode = code2;
  v13 = (float)(v12 + v10) + toUV->M[0][3];
  v14 = y * toUV->M[1][1];
  v18.Slope = 0.0;
  v15 = (float)(v11 + v14) + toUV->M[1][3];
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(v9, &v18);
  v16 = &v7->Vertices[v7->VerCount].x;
  *v16 = x;
  v16[1] = y;
  v16[2] = v13;
  v16[3] = v15;
  ++v7->VerCount;
}

// File Line: 423
// RVA: 0x9C66A0
void __fastcall Scaleform::Render::Scale9GridTess::addCorner(Scaleform::Render::Scale9GridTess *this, Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver, const float *c, float x, float y, Scaleform::Render::Matrix2x4<float> *toUV, unsigned int code1, unsigned int code2, unsigned int code3, unsigned int code4)
{
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *v13; // rdi
  Scaleform::Render::Scale9GridTess *v14; // rbx
  float v15; // xmm0_4
  float v16; // xmm11_4
  float v17; // xmm3_4
  float v18; // xmm10_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm10_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  bool v28; // r8
  bool v29; // dl
  bool v30; // cl
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  float *v35; // rax
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [rsp+20h] [rbp-A8h]
  Scaleform::Render::Scale9GridTess::TmpVertexType v37; // [rsp+30h] [rbp-98h]
  Scaleform::Render::Scale9GridTess::TmpVertexType v38; // [rsp+40h] [rbp-88h]
  Scaleform::Render::Scale9GridTess::TmpVertexType v39; // [rsp+50h] [rbp-78h]

  v10 = c[3];
  v11 = c[2];
  v12 = c[4];
  v13 = ver;
  v14 = this;
  v15 = x - v11;
  v16 = x;
  v17 = c[5];
  v18 = (float)(c[3] - c[1]) * v15;
  v19 = c[5] - v10;
  v20 = y - v10;
  v21 = c[7];
  v22 = v18 - (float)((float)(c[2] - *c) * v20);
  v23 = c[4] - v11;
  v24 = c[6];
  v25 = (float)(v19 * (float)(v16 - v12)) - (float)(v23 * (float)(y - v17));
  v26 = (float)((float)(c[7] - v17) * (float)(v16 - v24)) - (float)((float)(c[6] - v12) * (float)(y - v21));
  v27 = (float)((float)(c[1] - v21) * (float)(v16 - *c)) - (float)((float)(*c - v24) * (float)(y - c[1]));
  v28 = v26 <= 0.0;
  v29 = v25 >= 0.0;
  v30 = v26 >= 0.0;
  if ( v22 <= 0.0 == v25 <= 0.0 && v25 <= 0.0 == v28 && v28 == v27 <= 0.0
    || v22 >= 0.0 == v29 && v29 == v30 && v30 == v27 >= 0.0 )
  {
    val.VerIdx = v14->VerCount;
    v37.VerIdx = val.VerIdx;
    v38.VerIdx = val.VerIdx;
    v39.VerIdx = val.VerIdx;
    v31 = v16 * toUV->M[1][0];
    v32 = (float)((float)(y * toUV->M[0][1]) + (float)(v16 * toUV->M[0][0])) + toUV->M[0][3];
    val.Slope = 0.0;
    v33 = y * toUV->M[1][1];
    v37.Slope = 0.0;
    v38.Slope = 0.0;
    v39.Slope = 0.0;
    v34 = (float)(v31 + v33) + toUV->M[1][3];
    val.AreaCode = code1;
    v37.AreaCode = code2;
    v38.AreaCode = code3;
    v39.AreaCode = code4;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(v13, &val);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(v13, &v37);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(v13, &v38);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(v13, &v39);
    v35 = &v14->Vertices[v14->VerCount].x;
    *v35 = v16;
    v35[1] = y;
    v35[2] = v32;
    v35[3] = v34;
    ++v14->VerCount;
  }
}

// File Line: 463
// RVA: 0x9F7450
void __fastcall Scaleform::Render::Scale9GridTess::transformVertex(Scaleform::Render::Scale9GridTess *this, Scaleform::Render::Scale9GridInfo *s9g, Scaleform::Render::Image9GridVertex *v)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float *v5; // rcx
  float v6; // xmm3_4
  float v7; // xmm2_4

  v3 = v->y;
  v4 = v->x;
  v5 = (float *)((char *)s9g
               + 32
               * ((unsigned __int8)codeToMtx[(v->x > s9g->ResultingGrid.x2) | (unsigned __int64)(2
                                                                                               * ((v3 > s9g->ResultingGrid.y2) | 2 * ((v->x < s9g->ResultingGrid.x1) | 2 * (unsigned int)(v3 < s9g->ResultingGrid.y1))))]
                + 5i64));
  v->x = (float)((float)(v->y * v5[1]) + (float)(v->x * *v5)) + v5[3];
  v6 = (float)((float)(v3 * v5[5]) + (float)(v4 * v5[4])) + v5[7];
  v->y = v6;
  v7 = v->x;
  v->x = (float)((float)(v6 * s9g->InverseMatrix.M[0][1]) + (float)(v->x * s9g->InverseMatrix.M[0][0]))
       + s9g->InverseMatrix.M[0][3];
  v->y = (float)((float)(v6 * s9g->InverseMatrix.M[1][1]) + (float)(v7 * s9g->InverseMatrix.M[1][0]))
       + s9g->InverseMatrix.M[1][3];
}

// File Line: 493
// RVA: 0x9F5E80
void __fastcall Scaleform::Render::Scale9GridTess::tessellateArea(Scaleform::Render::Scale9GridTess *this, Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver, unsigned int i1, unsigned int i2)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r15
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *v6; // r14
  Scaleform::Render::Scale9GridTess *v7; // rbx
  unsigned int v8; // er10
  signed __int64 v9; // rsi
  signed __int64 v10; // r11
  float v11; // xmm3_4
  float v12; // xmm4_4
  Scaleform::Render::Scale9GridTess::TmpVertexType *v13; // rax
  unsigned int *v14; // r8
  signed __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rax
  unsigned int *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  unsigned int v21; // er9
  signed __int64 v22; // r10
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  signed __int64 v26; // rcx
  unsigned int v27; // eax
  __int64 v28; // r8
  Scaleform::Render::Scale9GridTess::TmpVertexType *v29; // rdx
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  Scaleform::Render::Scale9GridTess::TmpVertexType *v35; // rdx
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  Scaleform::Render::Scale9GridTess::TmpVertexType *v41; // rdx
  float v42; // xmm5_4
  float v43; // xmm6_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm1_4
  Scaleform::Render::Scale9GridTess::TmpVertexType *v47; // rdx
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm1_4
  signed __int64 v53; // rcx
  __int64 v54; // rdx
  Scaleform::Render::Scale9GridTess::TmpVertexType *v55; // r8
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm1_4
  signed __int64 v61; // rdi
  signed __int64 v62; // rbp
  Scaleform::ArrayStaticBuffPOD<unsigned short,72,2> *v63; // rsi
  signed __int64 v64; // rbx
  unsigned __int16 val; // [rsp+A0h] [rbp+18h]

  v4 = i1;
  v5 = i2;
  v6 = ver;
  v7 = this;
  if ( i1 + 3 <= i2 )
  {
    v8 = i1;
    v9 = i1;
    v10 = i1;
    v11 = 0.0;
    v12 = 0.0;
    if ( i1 < i2 )
    {
      if ( (signed int)(i2 - i1) >= 4 )
      {
        v13 = ver->Data;
        v14 = &v13[i1].VerIdx;
        v15 = (signed __int64)v13 + 4 * (3 * v4 + 7);
        LODWORD(v13) = ((i2 - (unsigned int)v4 - 4) >> 2) + 1;
        v16 = (unsigned int)v13;
        v8 = v4 + 4 * (_DWORD)v13;
        v10 = v4 + 4i64 * (unsigned int)v13;
        do
        {
          v17 = *v14;
          v14 += 12;
          v15 += 48i64;
          v17 *= 2i64;
          v11 = (float)((float)((float)(v11 + *(&v7->Vertices[0].x + 2 * v17))
                              + v7->Vertices[*(unsigned int *)(v15 - 60)].x)
                      + v7->Vertices[*(unsigned int *)(v15 - 48)].x)
              + v7->Vertices[*(unsigned int *)(v15 - 36)].x;
          v12 = (float)((float)((float)(v12 + *(&v7->Vertices[0].y + 2 * v17))
                              + v7->Vertices[*(unsigned int *)(v15 - 60)].y)
                      + v7->Vertices[*(unsigned int *)(v15 - 48)].y)
              + v7->Vertices[*(unsigned int *)(v15 - 36)].y;
          --v16;
        }
        while ( v16 );
      }
      if ( v8 < i2 )
      {
        v18 = &v6->Data->AreaCode + v10 + 2 * v10 + 1;
        v19 = (signed int)(i2 - v8);
        do
        {
          v20 = *v18;
          v18 += 3;
          v20 *= 2i64;
          v11 = v11 + *(&v7->Vertices[0].x + 2 * v20);
          v12 = v12 + *(&v7->Vertices[0].y + 2 * v20);
          --v19;
        }
        while ( v19 );
      }
    }
    v21 = v4;
    v22 = v4;
    v23 = 1.0 / (float)((signed int)v5 - (signed int)v4);
    v24 = v11 * v23;
    v25 = v12 * v23;
    if ( (unsigned int)v4 < (unsigned int)v5 )
    {
      if ( (signed int)v5 - (signed int)v4 >= 4 )
      {
        v26 = v4;
        v27 = ((unsigned int)(v5 - v4 - 4) >> 2) + 1;
        v28 = v27;
        v21 = v4 + 4 * v27;
        v22 = v4 + 4i64 * v27;
        do
        {
          v29 = v6->Data;
          v30 = v7->Vertices[v29[v26].VerIdx].x - v24;
          v31 = v7->Vertices[v29[v26].VerIdx].y - v25;
          v32 = (float)((float)(v31 * v31) + (float)(v30 * v30)) * 2.0;
          if ( v32 == 0.0 )
          {
            v33 = 0.0;
          }
          else
          {
            v34 = (float)(v30 * v30) / v32;
            if ( v30 < 0.0 )
              LODWORD(v34) ^= _xmm[0];
            if ( v31 > 0.0 )
              v34 = 1.0 - v34;
            v33 = v34 - 0.5;
          }
          v29[v26].Slope = v33;
          v35 = v6->Data;
          v36 = v7->Vertices[v35[v26 + 1].VerIdx].x - v24;
          v37 = v7->Vertices[v35[v26 + 1].VerIdx].y - v25;
          v38 = (float)((float)(v37 * v37) + (float)(v36 * v36)) * 2.0;
          if ( v38 == 0.0 )
          {
            v39 = 0.0;
          }
          else
          {
            v40 = (float)(v36 * v36) / v38;
            if ( v36 < 0.0 )
              LODWORD(v40) ^= _xmm[0];
            if ( v37 > 0.0 )
              v40 = 1.0 - v40;
            v39 = v40 - 0.5;
          }
          v35[v26 + 1].Slope = v39;
          v41 = v6->Data;
          v42 = v7->Vertices[v41[v26 + 2].VerIdx].x - v24;
          v43 = v7->Vertices[v41[v26 + 2].VerIdx].y - v25;
          v44 = (float)((float)(v43 * v43) + (float)(v42 * v42)) * 2.0;
          if ( v44 == 0.0 )
          {
            v45 = 0.0;
          }
          else
          {
            v46 = (float)(v42 * v42) / v44;
            if ( v42 < 0.0 )
              LODWORD(v46) ^= _xmm[0];
            if ( v43 > 0.0 )
              v46 = 1.0 - v46;
            v45 = v46 - 0.5;
          }
          v41[v26 + 2].Slope = v45;
          v47 = v6->Data;
          v48 = v7->Vertices[v47[v26 + 3].VerIdx].x - v24;
          v49 = v7->Vertices[v47[v26 + 3].VerIdx].y - v25;
          v50 = (float)((float)(v49 * v49) + (float)(v48 * v48)) * 2.0;
          if ( v50 == 0.0 )
          {
            v51 = 0.0;
          }
          else
          {
            v52 = (float)(v48 * v48) / v50;
            if ( v48 < 0.0 )
              LODWORD(v52) ^= _xmm[0];
            if ( v49 > 0.0 )
              v52 = 1.0 - v52;
            v51 = v52 - 0.5;
          }
          v47[v26 + 3].Slope = v51;
          v26 += 4i64;
          --v28;
        }
        while ( v28 );
      }
      if ( v21 < (unsigned int)v5 )
      {
        v53 = v22;
        v54 = (signed int)(v5 - v21);
        do
        {
          v55 = v6->Data;
          v56 = v7->Vertices[v55[v53].VerIdx].x - v24;
          v57 = v7->Vertices[v55[v53].VerIdx].y - v25;
          v58 = (float)((float)(v57 * v57) + (float)(v56 * v56)) * 2.0;
          if ( v58 == 0.0 )
          {
            v59 = 0.0;
          }
          else
          {
            v60 = (float)(v56 * v56) / v58;
            if ( v56 < 0.0 )
              LODWORD(v60) ^= _xmm[0];
            if ( v57 > 0.0 )
              v60 = 1.0 - v60;
            v59 = v60 - 0.5;
          }
          v55[v53].Slope = v59;
          ++v53;
          --v54;
        }
        while ( v54 );
      }
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (*)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
      v6,
      v4,
      v5,
      (bool (__fastcall *)(Scaleform::Render::Scale9GridTess::TmpVertexType *, Scaleform::Render::Scale9GridTess::TmpVertexType *))UFG::SectionChooser::fnSectionStreamPriority);
    v61 = (unsigned int)(v4 + 2);
    if ( (unsigned int)v61 < (unsigned int)v5 )
    {
      v62 = v9;
      v63 = &v7->Indices;
      v64 = v61;
      do
      {
        val = v6->Data[v62].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(v63, &val);
        val = v6->Data[(unsigned int)(v61 - 1)].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(v63, &val);
        val = v6->Data[v64].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(v63, &val);
        LODWORD(v61) = v61 + 1;
        ++v64;
      }
      while ( (unsigned int)v61 < (unsigned int)v5 );
    }
  }
}

// File Line: 535
// RVA: 0x942470
void __fastcall Scaleform::Render::Scale9GridTess::Scale9GridTess(Scaleform::Render::Scale9GridTess *this, Scaleform::MemoryHeap *heap, Scaleform::Render::Scale9GridInfo *s9g, Scaleform::Render::Rect<float> *imgRect)
{
  Scaleform::Render::Scale9GridInfo *v4; // rsi
  Scaleform::MemoryHeap *v5; // rdi
  Scaleform::Render::Scale9GridTess *v6; // rbx
  float v7; // xmm8_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm11_4
  float v13; // xmm5_4
  float v14; // xmm10_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float *v17; // rax
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  __m128 v22; // xmm8
  __m128 v23; // xmm9
  __m128 v24; // xmm7
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm10_4
  float v30; // xmm5_4
  float v31; // xmm12_4
  float v32; // xmm13_4
  float v33; // xmm14_4
  __m128 v34; // xmm7
  float v35; // xmm4_4
  float v36; // ST58_4
  float v37; // xmm5_4
  float v38; // ST60_4
  float v39; // xmm6_4
  float v40; // xmm11_4
  float v41; // xmm10_4
  float v42; // xmm12_4
  signed __int64 v43; // rax
  float v44; // edx
  float v45; // xmm6_4
  float v46; // xmm7_4
  signed __int64 v47; // rax
  float v48; // edx
  float v49; // xmm9_4
  float v50; // xmm8_4
  float v51; // xmm6_4
  signed __int64 v52; // rax
  float v53; // edx
  float v54; // xmm6_4
  float v55; // xmm10_4
  signed __int64 v56; // rax
  float v57; // xmm4_4
  float v58; // xmm3_4
  float v59; // xmm2_4
  float v60; // xmm10_4
  float v61; // xmm5_4
  float v62; // xmm1_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float y; // xmm2_4
  float v69; // xmm4_4
  float v70; // xmm3_4
  float v71; // xmm2_4
  float v72; // xmm3_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm4_4
  float v81; // xmm2_4
  float v82; // xmm14_4
  float v83; // xmm15_4
  float v84; // xmm11_4
  bool v85; // cf
  float v86; // xmm11_4
  float v87; // xmm1_4
  float v88; // xmm3_4
  float v89; // xmm3_4
  float v90; // xmm2_4
  float v91; // xmm4_4
  float v92; // xmm3_4
  float v93; // xmm4_4
  float v94; // xmm3_4
  float v95; // xmm2_4
  float v96; // xmm4_4
  float v97; // xmm3_4
  float v98; // xmm1_4
  float v99; // xmm5_4
  float v100; // xmm3_4
  float v101; // xmm2_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm14_4
  float v105; // xmm15_4
  float v106; // xmm5_4
  float v107; // xmm4_4
  float v108; // xmm15_4
  float v109; // xmm14_4
  int v110; // xmm1_4
  float v111; // xmm3_4
  float v112; // xmm2_4
  float v113; // xmm14_4
  float v114; // xmm3_4
  float v115; // xmm2_4
  float v116; // xmm10_4
  int v117; // xmm0_4
  float v118; // xmm10_4
  float v119; // xmm2_4
  float v120; // xmm3_4
  float v121; // xmm2_4
  float v122; // xmm5_4
  float v123; // xmm3_4
  float v124; // xmm2_4
  float v125; // xmm3_4
  float v126; // xmm2_4
  float v127; // xmm3_4
  float v128; // xmm2_4
  float v129; // xmm3_4
  float v130; // xmm2_4
  float v131; // xmm1_4
  float v132; // xmm10_4
  float v133; // xmm11_4
  float v134; // xmm3_4
  int v135; // xmm2_4
  float v136; // xmm4_4
  float v137; // xmm3_4
  float v138; // xmm2_4
  float v139; // xmm5_4
  float v140; // xmm3_4
  float v141; // xmm4_4
  float v142; // xmm3_4
  float v143; // xmm2_4
  float v144; // xmm4_4
  int v145; // xmm3_4
  float v146; // xmm2_4
  float v147; // xmm3_4
  float v148; // xmm2_4
  float v149; // xmm1_4
  float v150; // xmm2_4
  float v151; // xmm3_4
  float v152; // xmm2_4
  unsigned int v153; // edi
  unsigned int v154; // er8
  unsigned __int64 v155; // r10
  signed __int64 v156; // rdx
  Scaleform::Render::Scale9GridTess::TmpVertexType *v157; // r9
  unsigned int i; // edi
  float v159; // [rsp+50h] [rbp-88h]
  float v160; // [rsp+50h] [rbp-88h]
  float v161; // [rsp+50h] [rbp-88h]
  float v162; // [rsp+54h] [rbp-84h]
  float v163; // [rsp+54h] [rbp-84h]
  float v164; // [rsp+54h] [rbp-84h]
  float v165; // [rsp+54h] [rbp-84h]
  float v166; // [rsp+58h] [rbp-80h]
  float v167; // [rsp+58h] [rbp-80h]
  float v168; // [rsp+5Ch] [rbp-7Ch]
  float v169; // [rsp+5Ch] [rbp-7Ch]
  float v170; // [rsp+5Ch] [rbp-7Ch]
  float v171; // [rsp+5Ch] [rbp-7Ch]
  float v172; // [rsp+60h] [rbp-78h]
  float v173; // [rsp+60h] [rbp-78h]
  float v174; // [rsp+60h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> toUV; // [rsp+68h] [rbp-70h]
  float v176; // [rsp+88h] [rbp-50h]
  float dst[4]; // [rsp+98h] [rbp-40h]
  __m128 v178; // [rsp+A8h] [rbp-30h]
  float v179; // [rsp+B8h] [rbp-20h]
  float src; // [rsp+C0h] [rbp-18h]
  float v181; // [rsp+C4h] [rbp-14h]
  float v182; // [rsp+C8h] [rbp-10h]
  float v183; // [rsp+CCh] [rbp-Ch]
  float v184; // [rsp+D0h] [rbp-8h]
  float v185; // [rsp+D4h] [rbp-4h]
  float v186; // [rsp+D8h] [rbp+0h]
  float v187; // [rsp+DCh] [rbp+4h]
  __m128 v188; // [rsp+E8h] [rbp+10h]
  __m128 v189; // [rsp+F8h] [rbp+20h]
  __int64 v190; // [rsp+108h] [rbp+30h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> ver; // [rsp+118h] [rbp+40h]
  float v192; // [rsp+570h] [rbp+498h]
  float v193; // [rsp+578h] [rbp+4A0h]
  float vars0; // [rsp+580h] [rbp+4A8h]
  float *retaddr; // [rsp+588h] [rbp+4B0h]
  float v196; // [rsp+590h] [rbp+4B8h]
  float v197; // [rsp+590h] [rbp+4B8h]

  v190 = -2i64;
  v4 = s9g;
  v5 = heap;
  v6 = this;
  this->VerCount = 0;
  this->Indices.pHeap = heap;
  this->Indices.Size = 0i64;
  this->Indices.Reserved = 72i64;
  this->Indices.Data = this->Indices.Static;
  v7 = imgRect->x1;
  v8 = imgRect->y1;
  v9 = imgRect->x2;
  v10 = imgRect->y2;
  v11 = s9g->ShapeMatrix.M[0][1];
  v12 = s9g->ShapeMatrix.M[0][0];
  v13 = s9g->ShapeMatrix.M[0][3];
  v176 = (float)((float)(s9g->ShapeMatrix.M[0][0] * imgRect->x1) + (float)(s9g->ShapeMatrix.M[0][1] * v8)) + v13;
  src = v176;
  v14 = s9g->ShapeMatrix.M[1][1];
  v15 = s9g->ShapeMatrix.M[1][0];
  v16 = s9g->ShapeMatrix.M[1][3];
  v159 = (float)((float)(s9g->ShapeMatrix.M[1][0] * v7) + (float)(s9g->ShapeMatrix.M[1][1] * v8)) + v16;
  v181 = (float)((float)(s9g->ShapeMatrix.M[1][0] * v7) + (float)(s9g->ShapeMatrix.M[1][1] * v8)) + v16;
  vars0 = (float)((float)(v12 * v9) + (float)(v11 * v8)) + v13;
  v182 = (float)((float)(v12 * v9) + (float)(v11 * v8)) + v13;
  v192 = (float)((float)(v15 * v9) + (float)(v14 * v8)) + v16;
  v183 = (float)((float)(v15 * v9) + (float)(v14 * v8)) + v16;
  toUV.M[1][1] = (float)((float)(v12 * v9) + (float)(v11 * v10)) + v13;
  v184 = (float)((float)(v12 * v9) + (float)(v11 * v10)) + v13;
  v193 = (float)((float)(v15 * v9) + (float)(v14 * v10)) + v16;
  v185 = (float)((float)(v15 * v9) + (float)(v14 * v10)) + v16;
  toUV.M[1][0] = (float)((float)(v12 * v7) + (float)(v11 * v10)) + v13;
  v186 = (float)((float)(v12 * v7) + (float)(v11 * v10)) + v13;
  v179 = (float)((float)(v14 * v10) + (float)(v7 * v15)) + v16;
  v187 = (float)((float)(v14 * v10) + (float)(v7 * v15)) + v16;
  v17 = retaddr;
  *(float *)&retaddr = retaddr[3];
  v166 = v17[7];
  v18 = this->Vertices[0].x;
  toUV.M[0][0] = v18;
  v19 = this->Vertices[0].y;
  *(_QWORD *)&toUV.M[0][1] = *(_QWORD *)&this->Vertices[0].y;
  v20 = this->Vertices[1].x;
  toUV.M[1][0] = this->Vertices[1].x;
  v21 = this->Vertices[1].y;
  *(_QWORD *)&toUV.M[1][1] = *(_QWORD *)&this->Vertices[1].y;
  *(_QWORD *)dst = 1065353216i64;
  dst[2] = 0.0;
  v178.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)v178.m128_u64 + 4) = 1065353216i64;
  if ( v18 > -0.0000099999997 )
  {
    if ( v18 >= 0.0000099999997 )
      toUV.M[0][0] = 1.0;
  }
  else
  {
    toUV.M[0][0] = -1.0;
  }
  if ( v21 > -0.0000099999997 )
  {
    if ( v21 >= 0.0000099999997 )
      toUV.M[1][1] = 1.0;
  }
  else
  {
    toUV.M[1][1] = -1.0;
  }
  if ( v19 > -0.0000099999997 )
  {
    if ( v19 >= 0.0000099999997 )
      toUV.M[0][1] = 1.0;
  }
  else
  {
    toUV.M[0][1] = -1.0;
  }
  if ( v20 > -0.0000099999997 )
  {
    if ( v20 >= 0.0000099999997 )
      toUV.M[1][0] = 1.0;
  }
  else
  {
    toUV.M[1][0] = -1.0;
  }
  toUV.M[0][3] = 0.0;
  toUV.M[1][3] = 0.0;
  dst[3] = -0.5;
  v178.m128_i32[3] = -1090519040;
  v22 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v23 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  v24 = _mm_add_ps(
          _mm_mul_ps(*(__m128 *)dst, _mm_shuffle_ps(*(__m128 *)&toUV.M[1][0], *(__m128 *)&toUV.M[1][0], 0)),
          _mm_mul_ps(v178, _mm_shuffle_ps(*(__m128 *)&toUV.M[1][0], *(__m128 *)&toUV.M[1][0], 85)));
  v25 = _mm_and_ps(
          v23,
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(*(__m128 *)dst, _mm_shuffle_ps(*(__m128 *)&toUV.M[0][0], *(__m128 *)&toUV.M[0][0], 0)),
              _mm_mul_ps(v178, _mm_shuffle_ps(*(__m128 *)&toUV.M[0][0], *(__m128 *)&toUV.M[0][0], 85))),
            _mm_and_ps(*(__m128 *)&toUV.M[0][0], v22)));
  *(__m128 *)dst = v25;
  v26 = _mm_and_ps(v23, _mm_add_ps(_mm_and_ps(*(__m128 *)&toUV.M[1][0], v22), v24));
  v178 = v26;
  v25.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 255)) + 0.5;
  v26.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 255)) + 0.5;
  v27 = v17[1];
  v28 = *v17;
  v188.m128_f32[0] = (float)(v178.m128_f32[0] * v27) + (float)(dst[0] * *v17);
  v29 = v188.m128_f32[0];
  v30 = v17[5];
  v24.m128_f32[0] = v17[4];
  v31 = (float)(v178.m128_f32[0] * v30) + (float)(dst[0] * v24.m128_f32[0]);
  v189.m128_f32[0] = (float)(v178.m128_f32[0] * v30) + (float)(dst[0] * v24.m128_f32[0]);
  v32 = (float)(v178.m128_f32[1] * v27) + (float)(v28 * dst[1]);
  v188.m128_f32[1] = (float)(v178.m128_f32[1] * v27) + (float)(v28 * dst[1]);
  v33 = (float)(v178.m128_f32[1] * v30) + (float)(v24.m128_f32[0] * dst[1]);
  v189.m128_f32[1] = (float)(v178.m128_f32[1] * v30) + (float)(v24.m128_f32[0] * dst[1]);
  v189.m128_i32[2] = 0;
  v188.m128_i32[2] = 0;
  *(float *)&retaddr = *(float *)&retaddr + (float)((float)(v27 * v26.m128_f32[0]) + (float)(v28 * v25.m128_f32[0]));
  v188.m128_i32[3] = (signed int)retaddr;
  v189.m128_f32[3] = v166 + (float)((float)(v30 * v26.m128_f32[0]) + (float)(v24.m128_f32[0] * v25.m128_f32[0]));
  *(_OWORD *)&toUV.M[0][0] = _xmm;
  *(__m128 *)&toUV.M[1][0] = _xmm;
  *(_QWORD *)dst = 0i64;
  *(_QWORD *)&dst[2] = 1065353216i64;
  v178.m128_u64[0] = 4575657222473777152i64;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&toUV, &src, dst);
  v34 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v189, v189, 85), *(__m128 *)&toUV.M[1][0]),
          _mm_mul_ps(_mm_shuffle_ps(v189, v189, 0), *(__m128 *)&toUV.M[0][0]));
  *(__m128 *)&toUV.M[0][0] = _mm_and_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v188, v188, 85), *(__m128 *)&toUV.M[1][0]),
                                   _mm_mul_ps(_mm_shuffle_ps(v188, v188, 0), *(__m128 *)&toUV.M[0][0])),
                                 _mm_and_ps(v188, v22)),
                               v23);
  *(__m128 *)&toUV.M[1][0] = _mm_and_ps(_mm_add_ps(v34, _mm_and_ps(v189, v22)), v23);
  v35 = v4->ResultingGrid.y2;
  v36 = v4->ResultingGrid.y2;
  toUV.M[0][2] = v4->ResultingGrid.x2;
  v196 = v4->ResultingGrid.y1;
  v37 = v4->ResultingGrid.x1;
  v38 = v4->ResultingGrid.x1;
  ver.pHeap = v5;
  ver.Size = 0i64;
  ver.Reserved = 72i64;
  ver.Data = ver.Static;
  v25.m128_f32[0] = v29 * 0.0;
  v34.m128_f32[0] = (float)((float)(v29 * 0.0) + (float)(v32 * 0.0)) + *(float *)&retaddr;
  v26.m128_f32[0] = v31 * 0.0;
  v39 = (float)((float)(v31 * 0.0) + (float)(v33 * 0.0)) + v36;
  v23.m128_f32[0] = (float)(v29 + (float)(v32 * 0.0)) + *(float *)&retaddr;
  v22.m128_f32[0] = (float)(v31 + (float)(v33 * 0.0)) + v36;
  v40 = (float)(v32 + v29) + *(float *)&retaddr;
  v41 = (float)(v33 + v31) + v36;
  v42 = toUV.M[0][2];
  LODWORD(dst[0]) = (v176 > toUV.M[0][2]) | 2 * ((v159 > v35) | 2 * ((v37 > v176) | 2 * (v196 > v159)));
  dst[1] = *(float *)&v6->VerCount;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v43 = (signed __int64)&v6->Vertices[v6->VerCount];
  *(float *)v43 = v176;
  *(float *)(v43 + 4) = v159;
  *(_DWORD *)(v43 + 8) = v34.m128_i32[0];
  *(float *)(v43 + 12) = v39;
  ++v6->VerCount;
  v44 = *(float *)&v6->VerCount;
  v45 = vars0;
  v46 = v36;
  LODWORD(dst[0]) = (vars0 > v42) | 2 * ((v192 > v36) | 2 * ((v38 > vars0) | 2 * (v196 > v192)));
  dst[1] = v44;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v47 = (signed __int64)&v6->Vertices[v6->VerCount];
  *(float *)v47 = v45;
  *(float *)(v47 + 4) = v192;
  *(_DWORD *)(v47 + 8) = v23.m128_i32[0];
  *(_DWORD *)(v47 + 12) = v22.m128_i32[0];
  ++v6->VerCount;
  v48 = *(float *)&v6->VerCount;
  v49 = v196;
  v50 = v38;
  v51 = toUV.M[1][1];
  LODWORD(dst[0]) = (toUV.M[1][1] > v42) | 2 * ((v193 > v36) | 2 * ((v38 > toUV.M[1][1]) | 2 * (v196 > v193)));
  dst[1] = v48;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v52 = (signed __int64)&v6->Vertices[v6->VerCount];
  *(float *)v52 = v51;
  *(float *)(v52 + 4) = v193;
  *(float *)(v52 + 8) = v40;
  *(float *)(v52 + 12) = v41;
  ++v6->VerCount;
  v53 = *(float *)&v6->VerCount;
  v54 = v179;
  v55 = toUV.M[1][0];
  LODWORD(dst[0]) = (toUV.M[1][0] > v42) | 2 * ((v179 > v36) | 2 * ((v38 > toUV.M[1][0]) | 2 * (v196 > v179)));
  dst[1] = v53;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v56 = (signed __int64)&v6->Vertices[v6->VerCount];
  *(float *)v56 = v55;
  *(float *)(v56 + 4) = v54;
  *(float *)(v56 + 8) = (float)(v32 + v25.m128_f32[0]) + *(float *)&retaddr;
  *(float *)(v56 + 12) = (float)(v33 + v26.m128_f32[0]) + v36;
  ++v6->VerCount;
  v57 = (float)(v42 - v38) * 0.5;
  *(float *)&retaddr = (float)(v42 - v38) * 0.5;
  v58 = v36 - v196;
  v167 = v36 - v196;
  v197 = v167 * 0.5;
  toUV.M[0][3] = v159 - v49;
  v60 = v176;
  v162 = v176 - v38;
  toUV.M[0][2] = (float)((float)(v159 - v49) * (float)(v42 - v50)) - (float)(0.0 * (float)(v176 - v50));
  v61 = vars0 - v176;
  v172 = vars0 - v176;
  v168 = (float)((float)(vars0 - v176) * 0.0) - (float)((float)(v192 - v159) * (float)(v42 - v50));
  if ( COERCE_FLOAT(LODWORD(v168) & _xmm) >= 0.001 )
  {
    v62 = toUV.M[0][2] / v168;
    if ( (float)(toUV.M[0][2] / v168) >= -0.0000099999997 && v62 <= 1.00001 )
    {
      v63 = (float)(v62 * v61) + v176;
      toUV.M[0][2] = (float)(v62 * v168) + v159;
      v59 = v167 * 0.5;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v63,
        toUV.M[0][2],
        (v63 > v42) | 2
                    * (((float)(toUV.M[0][2] + v59) > v46) | 2 * ((v50 > v63) | 2 * (v49 > (float)(toUV.M[0][2] + v59)))),
        (v63 > v42) | 2
                    * (((float)(toUV.M[0][2] - v59) > v46) | 2 * ((v50 > v63) | 2 * (v49 > (float)(toUV.M[0][2] - v59)))));
      v57 = *(float *)&retaddr;
      v58 = v167;
      v61 = v172;
    }
  }
  v169 = v60 - v42;
  v64 = (float)(0.0 * toUV.M[0][3]) - (float)((float)(v60 - v42) * v58);
  toUV.M[0][3] = (float)(v61 * v58) - (float)(0.0 * (float)(v60 - v42));
  v65 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(toUV.M[0][3]) & _xmm) >= 0.001 )
  {
    v66 = v64 / toUV.M[0][3];
    if ( v66 >= -0.0000099999997 && v66 <= 1.00001 )
    {
      v67 = (float)(v66 * v61) + v60;
      y = (float)(v66 * v169) + v159;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v67,
        y,
        ((float)(v67 + v57) > v42) | 2 * ((y > v46) | 2 * (2 * (v49 > y) | (v50 > (float)(v67 + v57)))),
        ((float)(v67 - v57) > v42) | 2 * ((y > v46) | 2 * (2 * (v49 > y) | (v50 > (float)(v67 - v57)))));
      v65 = FLOAT_0_001;
      v61 = v172;
    }
  }
  toUV.M[0][2] = v50 - v42;
  toUV.M[0][3] = 0.0 * v61;
  v69 = v60 - v42;
  v70 = (float)(0.0 * v61) - (float)((float)(v50 - v42) * v169);
  if ( COERCE_FLOAT(LODWORD(v70) & _xmm) >= v65 )
  {
    v71 = (float)((float)((float)(v50 - v42) * (float)(v159 - v46)) - (float)(0.0 * v169)) / v70;
    if ( v71 >= -0.0000099999997 && v71 <= 1.00001 )
    {
      v72 = (float)(v71 * v61) + v60;
      v73 = (float)(v71 * v169) + v159;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v72,
        v73,
        (v72 > v42) | 2 * (((float)(v73 + v197) > v46) | 2 * ((v50 > v72) | 2 * (v49 > (float)(v73 + v197)))),
        (v72 > v42) | 2 * (((float)(v73 - v197) > v46) | 2 * ((v50 > v72) | 2 * (v49 > (float)(v73 - v197)))));
      v61 = v159 - v46;
      v69 = v60 - v42;
    }
  }
  v74 = (float)((float)(v49 - v46) * v61) - (float)(0.0 * v69);
  v75 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(v74) & _xmm) >= 0.001 )
  {
    v76 = (float)((float)(0.0 * (float)(v49 - v46)) - (float)((float)(v49 - v46) * v162)) / v74;
    if ( v76 >= -0.0000099999997 && v76 <= 1.00001 )
    {
      v77 = (float)(v61 * v76) + v60;
      v78 = (float)(v69 * v76) + v159;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v77,
        v78,
        ((float)(v77 + *(float *)&retaddr) > v42) | 2
                                                  * ((v78 > v46) | 2
                                                                 * (2 * (v49 > v78) | (v50 > (float)(v77 + *(float *)&retaddr)))),
        ((float)(v77 - *(float *)&retaddr) > v42) | 2
                                                  * ((v78 > v46) | 2
                                                                 * (2 * (v49 > v78) | (v50 > (float)(v77 - *(float *)&retaddr)))));
      v75 = FLOAT_0_001;
    }
  }
  v79 = v192;
  v80 = v192 - v49;
  v173 = v192 - v49;
  v81 = vars0;
  toUV.M[0][3] = vars0 - v50;
  v82 = toUV.M[1][1] - vars0;
  v83 = v193 - v192;
  v84 = (float)((float)(toUV.M[1][1] - vars0) * 0.0) - (float)((float)(v193 - v192) * v167);
  v170 = v84;
  v85 = COERCE_FLOAT(LODWORD(v84) & _xmm) < v75;
  v86 = v159;
  v87 = FLOAT_1_00001;
  if ( !v85 )
  {
    v88 = (float)((float)((float)(v192 - v49) * v167) - (float)((float)(vars0 - v50) * 0.0)) / v170;
    v163 = v88;
    if ( v88 >= -0.0000099999997 && v88 <= 1.00001 )
    {
      v89 = (float)(v82 * v88) + vars0;
      v90 = (float)(v83 * v163) + v192;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v89,
        v90,
        (v89 > v42) | 2 * (((float)(v90 + v197) > v46) | 2 * ((v50 > v89) | 2 * (v49 > (float)(v90 + v197)))),
        (v89 > v42) | 2 * (((float)(v90 - v197) > v46) | 2 * ((v50 > v89) | 2 * (v49 > (float)(v90 - v197)))));
      v87 = FLOAT_1_00001;
      v80 = v173;
      v81 = vars0;
      v79 = v192;
    }
  }
  v160 = v81 - v42;
  v91 = (float)(v80 * 0.0) - (float)(v167 * (float)(v81 - v42));
  v92 = (float)(v82 * v167) - (float)(v83 * 0.0);
  if ( COERCE_FLOAT(LODWORD(v92) & _xmm) >= 0.001 )
  {
    v93 = v91 / v92;
    if ( v93 >= -0.0000099999997 && v93 <= v87 )
    {
      v94 = (float)(v82 * v93) + v81;
      v95 = (float)(v83 * v93) + v79;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v94,
        v95,
        ((float)(v94 + *(float *)&retaddr) > v42) | 2
                                                  * ((v95 > v46) | 2
                                                                 * (2 * (v49 > v95) | (v50 > (float)(v94 + *(float *)&retaddr)))),
        ((float)(v94 - *(float *)&retaddr) > v42) | 2
                                                  * ((v95 > v46) | 2
                                                                 * (2 * (v49 > v95) | (v50 > (float)(v94 - *(float *)&retaddr)))));
      v81 = vars0;
    }
  }
  v96 = v192;
  v164 = v192 - v46;
  v97 = (float)(v82 * 0.0) - (float)(v83 * toUV.M[0][2]);
  v98 = FLOAT_1_00001;
  if ( COERCE_FLOAT(LODWORD(v97) & _xmm) >= 0.001 )
  {
    v99 = (float)((float)(toUV.M[0][2] * (float)(v192 - v46)) - (float)(0.0 * v160)) / v97;
    if ( v99 >= -0.0000099999997 && v99 <= 1.00001 )
    {
      v100 = (float)(v82 * v99) + v81;
      v101 = (float)(v83 * v99) + v192;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v100,
        v101,
        (v100 > v42) | 2 * (((float)(v101 + v197) > v46) | 2 * ((v50 > v100) | 2 * (v49 > (float)(v101 + v197)))),
        (v100 > v42) | 2 * (((float)(v101 - v197) > v46) | 2 * ((v50 > v100) | 2 * (v49 > (float)(v101 - v197)))));
      v98 = FLOAT_1_00001;
      v96 = v192;
    }
  }
  v102 = (float)(v82 * v173) - (float)(v83 * 0.0);
  if ( COERCE_FLOAT(LODWORD(v102) & _xmm) >= 0.001 )
  {
    v103 = (float)((float)(0.0 * v164) - (float)(toUV.M[0][3] * v173)) / v102;
    if ( v103 >= -0.0000099999997 && v103 <= v98 )
    {
      v104 = (float)(v82 * v103) + vars0;
      v105 = (float)(v83 * v103) + v96;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v104,
        v105,
        ((float)(v104 + *(float *)&retaddr) > v42) | 2
                                                   * ((v105 > v46) | 2
                                                                   * (2 * (v49 > v105) | (v50 > (float)(v104 + *(float *)&retaddr)))),
        ((float)(v104 - *(float *)&retaddr) > v42) | 2
                                                   * ((v105 > v46) | 2
                                                                   * (2 * (v49 > v105) | (v50 > (float)(v104 - *(float *)&retaddr)))));
    }
  }
  v106 = v193;
  v165 = v193 - v49;
  v107 = toUV.M[1][1];
  v171 = toUV.M[1][1] - v50;
  v192 = toUV.M[1][0] - toUV.M[1][1];
  v108 = v179;
  vars0 = v179 - v193;
  v109 = (float)(0.0 * (float)(toUV.M[1][0] - toUV.M[1][1])) - (float)(v167 * (float)(v179 - v193));
  v110 = _xmm;
  v111 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(v109) & _xmm) < 0.001 )
  {
    v113 = FLOAT_1_00001;
  }
  else
  {
    v112 = (float)((float)(v167 * (float)(v193 - v49)) - (float)(0.0 * (float)(toUV.M[1][1] - v50))) / v109;
    v113 = FLOAT_1_00001;
    if ( v112 >= -0.0000099999997 && v112 <= 1.00001 )
    {
      v114 = (float)(v112 * v192) + toUV.M[1][1];
      v115 = (float)(v112 * vars0) + v193;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v114,
        v115,
        (v114 > v42) | 2 * (((float)(v115 + v197) > v46) | 2 * ((v50 > v114) | 2 * (v49 > (float)(v115 + v197)))),
        (v114 > v42) | 2 * (((float)(v115 - v197) > v46) | 2 * ((v50 > v114) | 2 * (v49 > (float)(v115 - v197)))));
      v110 = _xmm;
      v111 = FLOAT_0_001;
      v107 = toUV.M[1][1];
      v106 = v193;
    }
  }
  v174 = v107 - v42;
  v116 = (float)(v167 * v192) - (float)(0.0 * vars0);
  v161 = v116;
  v117 = LODWORD(v116) & v110;
  v118 = v176;
  if ( *(float *)&v117 >= v111 )
  {
    v119 = (float)((float)(0.0 * v165) - (float)(v167 * (float)(v107 - v42))) / v161;
    if ( v119 >= -0.0000099999997 && v119 <= v113 )
    {
      v120 = (float)(v119 * v192) + v107;
      v121 = (float)(v119 * vars0) + v106;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v120,
        v121,
        ((float)(v120 + *(float *)&retaddr) > v42) | 2
                                                   * ((v121 > v46) | 2
                                                                   * (2 * (v49 > v121) | (v50 > (float)(v120 + *(float *)&retaddr)))),
        ((float)(v120 - *(float *)&retaddr) > v42) | 2
                                                   * ((v121 > v46) | 2
                                                                   * (2 * (v49 > v121) | (v50 > (float)(v120 - *(float *)&retaddr)))));
      v110 = _xmm;
      v107 = toUV.M[1][1];
    }
  }
  v122 = v193;
  toUV.M[0][3] = v193 - v46;
  v123 = (float)(0.0 * v192) - (float)(toUV.M[0][2] * vars0);
  if ( COERCE_FLOAT(LODWORD(v123) & v110) >= 0.001 )
  {
    v124 = (float)((float)(toUV.M[0][2] * (float)(v193 - v46)) - (float)(0.0 * v174)) / v123;
    if ( v124 >= -0.0000099999997 && v124 <= v113 )
    {
      v125 = (float)(v124 * v192) + v107;
      v126 = (float)(v124 * vars0) + v193;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v125,
        v126,
        (v125 > v42) | 2 * (((float)(v126 + v197) > v46) | 2 * ((v50 > v125) | 2 * (v49 > (float)(v126 + v197)))),
        (v125 > v42) | 2 * (((float)(v126 - v197) > v46) | 2 * ((v50 > v125) | 2 * (v49 > (float)(v126 - v197)))));
      v122 = v193;
    }
  }
  v127 = (float)(v174 * v192) - (float)(0.0 * vars0);
  if ( COERCE_FLOAT(LODWORD(v127) & _xmm) >= 0.001 )
  {
    v128 = (float)((float)(0.0 * toUV.M[0][3]) - (float)(v174 * v171)) / v127;
    if ( v128 >= -0.0000099999997 && v128 <= v113 )
    {
      v129 = (float)(v128 * v192) + toUV.M[1][1];
      v130 = (float)(v128 * vars0) + v122;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v129,
        v130,
        ((float)(v129 + *(float *)&retaddr) > v42) | 2
                                                   * ((v130 > v46) | 2
                                                                   * (2 * (v49 > v130) | (v50 > (float)(v129 + *(float *)&retaddr)))),
        ((float)(v129 - *(float *)&retaddr) > v42) | 2
                                                   * ((v130 > v46) | 2
                                                                   * (2 * (v49 > v130) | (v50 > (float)(v129 - *(float *)&retaddr)))));
    }
  }
  v192 = v108 - v49;
  v131 = toUV.M[1][0];
  vars0 = toUV.M[1][0] - v50;
  v132 = v118 - toUV.M[1][0];
  v133 = v86 - v108;
  v134 = (float)(0.0 * v132) - (float)(v167 * v133);
  v135 = _xmm;
  if ( COERCE_FLOAT(LODWORD(v134) & _xmm) >= 0.001 )
  {
    v136 = (float)((float)(v167 * (float)(v108 - v49)) - (float)(0.0 * (float)(toUV.M[1][0] - v50))) / v134;
    if ( v136 >= -0.0000099999997 && v136 <= v113 )
    {
      v137 = (float)(v132 * v136) + toUV.M[1][0];
      v138 = (float)(v133 * v136) + v108;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v137,
        v138,
        (v137 > v42) | 2 * (((float)(v138 + v197) > v46) | 2 * ((v50 > v137) | 2 * (v49 > (float)(v138 + v197)))),
        (v137 > v42) | 2 * (((float)(v138 - v197) > v46) | 2 * ((v50 > v137) | 2 * (v49 > (float)(v138 - v197)))));
      v131 = toUV.M[1][0];
      v135 = _xmm;
    }
  }
  v139 = v131 - v42;
  v193 = v131 - v42;
  v140 = (float)(v167 * v132) - (float)(0.0 * v133);
  if ( COERCE_FLOAT(LODWORD(v140) & v135) >= 0.001 )
  {
    v141 = (float)((float)(0.0 * v192) - (float)(v167 * (float)(v131 - v42))) / v140;
    if ( v141 >= -0.0000099999997 && v141 <= v113 )
    {
      v142 = (float)(v141 * v132) + v131;
      v143 = (float)(v133 * v141) + v108;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v142,
        v143,
        ((float)(v142 + *(float *)&retaddr) > v42) | 2
                                                   * ((v143 > v46) | 2
                                                                   * (2 * (v49 > v143) | (v50 > (float)(v142 + *(float *)&retaddr)))),
        ((float)(v142 - *(float *)&retaddr) > v42) | 2
                                                   * ((v143 > v46) | 2
                                                                   * (2 * (v49 > v143) | (v50 > (float)(v142 - *(float *)&retaddr)))));
      v131 = toUV.M[1][0];
      v139 = v193;
    }
  }
  v192 = v108 - v46;
  v144 = (float)(0.0 * v132) - (float)(toUV.M[0][2] * v133);
  v145 = _xmm;
  if ( COERCE_FLOAT(LODWORD(v144) & _xmm) >= 0.001 )
  {
    v146 = (float)((float)(toUV.M[0][2] * (float)(v108 - v46)) - (float)(0.0 * v139)) / v144;
    if ( v146 >= -0.0000099999997 && v146 <= v113 )
    {
      v147 = (float)(v146 * v132) + v131;
      v148 = (float)(v146 * v133) + v108;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v147,
        v148,
        (v147 > v42) | 2 * (((float)(v148 + v197) > v46) | 2 * ((v50 > v147) | 2 * (v49 > (float)(v148 + v197)))),
        (v147 > v42) | 2 * (((float)(v148 - v197) > v46) | 2 * ((v50 > v147) | 2 * (v49 > (float)(v148 - v197)))));
      v145 = _xmm;
    }
  }
  v149 = (float)(v174 * v132) - (float)(0.0 * v133);
  if ( COERCE_FLOAT(LODWORD(v149) & v145) >= 0.001 )
  {
    v150 = (float)((float)(0.0 * v192) - (float)(v174 * vars0)) / v149;
    if ( v150 >= -0.0000099999997 && v150 <= v113 )
    {
      v151 = (float)(v150 * v132) + toUV.M[1][0];
      v152 = (float)(v150 * v133) + v108;
      Scaleform::Render::Scale9GridTess::addVertices(
        v6,
        &ver,
        &toUV,
        v151,
        v152,
        ((float)(v151 + *(float *)&retaddr) > v42) | 2
                                                   * ((v152 > v46) | 2
                                                                   * (2 * (v49 > v152) | (v50 > (float)(v151 + *(float *)&retaddr)))),
        ((float)(v151 - *(float *)&retaddr) > v42) | 2
                                                   * ((v152 > v46) | 2
                                                                   * (2 * (v49 > v152) | (v50 > (float)(v151 - *(float *)&retaddr)))));
    }
  }
  Scaleform::Render::Scale9GridTess::addCorner(v6, &ver, &src, v50, v49, &toUV, 0, 4u, 0xCu, 8u);
  v153 = 1;
  Scaleform::Render::Scale9GridTess::addCorner(v6, &ver, &src, v42, v49, &toUV, 1u, 0, 8u, 9u);
  Scaleform::Render::Scale9GridTess::addCorner(v6, &ver, &src, v42, v46, &toUV, 3u, 2u, 0, 1u);
  Scaleform::Render::Scale9GridTess::addCorner(v6, &ver, &src, v50, v46, &toUV, 2u, 6u, 4u, 0);
  Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (*)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
    &ver,
    0i64,
    ver.Size,
    (bool (__fastcall *)(Scaleform::Render::Scale9GridTess::TmpVertexType *, Scaleform::Render::Scale9GridTess::TmpVertexType *))BlendTreeDataBase::UIDSort);
  v154 = 0;
  v155 = ver.Size;
  if ( ver.Size > 1 )
  {
    v156 = 1i64;
    v157 = ver.Data;
    do
    {
      if ( v157[v156].AreaCode != v157[v154].AreaCode )
      {
        Scaleform::Render::Scale9GridTess::tessellateArea(v6, &ver, v154, v153);
        v154 = v153;
        v157 = ver.Data;
        v155 = ver.Size;
      }
      v156 = ++v153;
    }
    while ( v153 < v155 );
  }
  Scaleform::Render::Scale9GridTess::tessellateArea(v6, &ver, v154, v153);
  for ( i = 0; i < v6->VerCount; ++i )
    Scaleform::Render::Scale9GridTess::transformVertex(v6, v4, &v6->Vertices[i]);
  if ( ver.Data != ver.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}ver.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

