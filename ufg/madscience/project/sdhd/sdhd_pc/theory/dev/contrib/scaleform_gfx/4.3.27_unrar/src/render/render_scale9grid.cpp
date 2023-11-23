// File Line: 34
// RVA: 0x159C470
__int64 dynamic_initializer_for__Scaleform::Render::Image9GridVertex::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::Image9GridVertex::Format__);
}

// File Line: 39
// RVA: 0x998F00
void __fastcall Scaleform::Render::Scale9GridData::MakeMeshKey(Scaleform::Render::Scale9GridData *this, float *keyData)
{
  float *v4; // rdx
  float x2; // eax
  Scaleform::Render::Matrix2x4<float> *p_ViewMtx; // rcx

  *keyData = this->S9Rect.x1;
  v4 = keyData + 8;
  *(v4 - 7) = this->S9Rect.y1;
  x2 = this->S9Rect.x2;
  p_ViewMtx = &this->ViewMtx;
  *(v4 - 6) = x2;
  *(v4 - 5) = p_ViewMtx[-3].M[0][3];
  *((Scaleform::Render::Rect<float> *)v4 - 1) = *(Scaleform::Render::Rect<float> *)&p_ViewMtx[-3].M[1][0];
  Scaleform::Render::MeshKey::CalcMatrixKey(p_ViewMtx, v4, 0i64);
  keyData[11] = this->ShapeMtx.M[0][3];
  keyData[12] = this->ShapeMtx.M[1][3];
}

// File Line: 61
// RVA: 0x941AF0
void __fastcall Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
        Scaleform::Render::Scale9GridInfo *this,
        Scaleform::Render::Rect<float> *s9Rect,
        Scaleform::Render::Matrix2x4<float> *s9gMtx,
        Scaleform::Render::Matrix2x4<float> *shapeMtx,
        Scaleform::Render::Rect<float> *bounds)
{
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  Scaleform::Render::Matrix2x4<float> v17; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::Render::Matrix2x4<float> v18; // [rsp+50h] [rbp-58h] BYREF

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
  y2 = s9Rect->y2;
  x2 = s9Rect->x2;
  y1 = s9Rect->y1;
  this->Scale9.x1 = s9Rect->x1;
  this->Scale9.y1 = y1;
  this->Scale9.x2 = x2;
  this->Scale9.y2 = y2;
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
  this->InverseMatrix = v17;
  *(_OWORD *)&v18.M[0][0] = _xmm;
  *(__m128 *)&v18.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v18, &this->ShapeMatrix);
  v12 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v13 = *(__m128 *)&this->InverseMatrix.M[0][0];
  v14 = *(__m128 *)&this->InverseMatrix.M[1][0];
  v15 = _mm_and_ps(
          *(__m128 *)&v18.M[1][0],
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v16 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 0), v13),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 85), v14));
  *(__m128 *)&this->InverseMatrix.M[0][0] = _mm_and_ps(
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
  *(__m128 *)&this->InverseMatrix.M[1][0] = _mm_and_ps(_mm_add_ps(v16, v15), v12);
  Scaleform::Render::Scale9GridInfo::Compute(this);
}

// File Line: 75
// RVA: 0x941F60
void __fastcall Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
        Scaleform::Render::Scale9GridInfo *this,
        Scaleform::Render::Scale9GridData *s9g,
        Scaleform::Render::Matrix2x4<float> *viewMtx)
{
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  __m128 v11; // xmm8
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  __m128 v14; // xmm8
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  Scaleform::Render::Matrix2x4<float> v17; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::Render::Matrix2x4<float> v18; // [rsp+50h] [rbp-58h] BYREF

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
  y2 = s9g->S9Rect.y2;
  x2 = s9g->S9Rect.x2;
  y1 = s9g->S9Rect.y1;
  this->Scale9.x1 = s9g->S9Rect.x1;
  this->Scale9.y1 = y1;
  this->Scale9.x2 = x2;
  this->Scale9.y2 = y2;
  this->S9gMatrix = s9g->Scale9Mtx;
  this->ShapeMatrix = s9g->ShapeMtx;
  v8 = s9g->Bounds.y2;
  v9 = s9g->Bounds.x2;
  v10 = s9g->Bounds.y1;
  this->Bounds.x1 = s9g->Bounds.x1;
  this->Bounds.y1 = v10;
  this->Bounds.x2 = v9;
  this->Bounds.y2 = v8;
  *(_OWORD *)&v17.M[0][0] = _xmm;
  *(__m128 *)&v17.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v17, &this->S9gMatrix);
  this->InverseMatrix = v17;
  *(_OWORD *)&v18.M[0][0] = _xmm;
  *(__m128 *)&v18.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v18, &this->ShapeMatrix);
  v11 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v12 = _mm_and_ps(
          *(__m128 *)&v18.M[1][0],
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v13 = _mm_add_ps(
          _mm_mul_ps(
            *(__m128 *)&this->InverseMatrix.M[1][0],
            _mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 85)),
          _mm_mul_ps(
            *(__m128 *)&this->InverseMatrix.M[0][0],
            _mm_shuffle_ps(*(__m128 *)&v18.M[1][0], *(__m128 *)&v18.M[1][0], 0)));
  *(__m128 *)&this->InverseMatrix.M[0][0] = _mm_and_ps(
                                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    *(__m128 *)&this->InverseMatrix.M[0][0],
                                                    _mm_shuffle_ps(*(__m128 *)&v18.M[0][0], *(__m128 *)&v18.M[0][0], 0)),
                                                  _mm_mul_ps(
                                                    *(__m128 *)&this->InverseMatrix.M[1][0],
                                                    _mm_shuffle_ps(*(__m128 *)&v18.M[0][0], *(__m128 *)&v18.M[0][0], 85))),
                                                _mm_and_ps(
                                                  *(__m128 *)&v18.M[0][0],
                                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)));
  *(__m128 *)&this->InverseMatrix.M[1][0] = _mm_and_ps(v11, _mm_add_ps(v13, v12));
  v14 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
  v15 = _mm_and_ps(
          *(__m128 *)&viewMtx->M[1][0],
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v16 = _mm_add_ps(
          _mm_mul_ps(
            *(__m128 *)&this->InverseMatrix.M[0][0],
            _mm_shuffle_ps(*(__m128 *)&viewMtx->M[1][0], *(__m128 *)&viewMtx->M[1][0], 0)),
          _mm_mul_ps(
            *(__m128 *)&this->InverseMatrix.M[1][0],
            _mm_shuffle_ps(*(__m128 *)&viewMtx->M[1][0], *(__m128 *)&viewMtx->M[1][0], 85)));
  *(__m128 *)&this->InverseMatrix.M[0][0] = _mm_and_ps(
                                              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v,
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    *(__m128 *)&this->InverseMatrix.M[0][0],
                                                    _mm_shuffle_ps(
                                                      *(__m128 *)&viewMtx->M[0][0],
                                                      *(__m128 *)&viewMtx->M[0][0],
                                                      0)),
                                                  _mm_mul_ps(
                                                    *(__m128 *)&this->InverseMatrix.M[1][0],
                                                    _mm_shuffle_ps(
                                                      *(__m128 *)&viewMtx->M[0][0],
                                                      *(__m128 *)&viewMtx->M[0][0],
                                                      85))),
                                                _mm_and_ps(
                                                  *(__m128 *)&viewMtx->M[0][0],
                                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)));
  *(__m128 *)&this->InverseMatrix.M[1][0] = _mm_and_ps(v14, _mm_add_ps(v16, v15));
  Scaleform::Render::Scale9GridInfo::Compute(this);
}

// File Line: 87
// RVA: 0x961A00
void __fastcall Scaleform::Render::Scale9GridInfo::Compute(Scaleform::Render::Scale9GridInfo *this)
{
  float x2; // xmm1_4
  float y2; // xmm2_4
  float y1; // xmm8_4
  float x1; // xmm11_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm1_4
  float v13; // xmm14_4
  float v14; // xmm4_4
  __m128 v15; // xmm2
  __m128 v16; // xmm15
  float v17; // xmm5_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  __m128 v21; // xmm13
  __m128 v22; // xmm3
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  float v25; // xmm14_4
  float v26; // xmm7_4
  __m128 v27; // xmm0
  float v28; // xmm5_4
  __m128 v29; // xmm1
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm15_4
  float v35; // xmm9_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm7_4
  float v39; // xmm5_4
  float v40; // xmm10_4
  float v41; // xmm3_4
  float v42; // xmm12_4
  float v43; // xmm13_4
  int v44; // xmm11_4
  int v45; // xmm14_4
  float v46; // xmm8_4
  float v47; // xmm4_4
  float v48; // xmm0_4
  float v49; // xmm6_4
  int v50; // xmm9_4
  int v51; // xmm7_4
  float v52; // xmm2_4
  float v53; // xmm15_4
  int v54; // xmm14_4
  float v55; // xmm11_4
  int v56; // xmm13_4
  float v57; // xmm10_4
  float v58; // xmm13_4
  float v59; // xmm10_4
  float v60; // xmm12_4
  float v61; // xmm8_4
  float v62; // xmm6_4
  int v63; // xmm8_4
  float v64; // xmm6_4
  int v65; // xmm9_4
  int v66; // xmm7_4
  float v67; // xmm12_4
  int v68; // xmm10_4
  float v69; // xmm10_4
  int v70; // xmm14_4
  float dst; // [rsp+20h] [rbp-D0h] BYREF
  float v72; // [rsp+24h] [rbp-CCh]
  float v73; // [rsp+28h] [rbp-C8h]
  float v74; // [rsp+2Ch] [rbp-C4h]
  float v75; // [rsp+30h] [rbp-C0h]
  float v76; // [rsp+34h] [rbp-BCh]
  float src; // [rsp+38h] [rbp-B8h] BYREF
  float v78; // [rsp+3Ch] [rbp-B4h]
  float v79; // [rsp+40h] [rbp-B0h]
  float v80; // [rsp+44h] [rbp-ACh]
  float v81; // [rsp+48h] [rbp-A8h]
  float v82; // [rsp+4Ch] [rbp-A4h]
  float v83; // [rsp+50h] [rbp-A0h]
  float v84; // [rsp+54h] [rbp-9Ch]
  float v85; // [rsp+58h] [rbp-98h]
  float v86; // [rsp+5Ch] [rbp-94h]
  float v87; // [rsp+60h] [rbp-90h]
  float v88; // [rsp+64h] [rbp-8Ch]
  float v89; // [rsp+68h] [rbp-88h]
  float v90; // [rsp+6Ch] [rbp-84h]
  float v91; // [rsp+70h] [rbp-80h]
  float v92; // [rsp+74h] [rbp-7Ch]
  float v93; // [rsp+78h] [rbp-78h]
  float v94; // [rsp+7Ch] [rbp-74h]
  float v95; // [rsp+80h] [rbp-70h]
  float v96; // [rsp+84h] [rbp-6Ch]
  float v97; // [rsp+88h] [rbp-68h]
  float v98; // [rsp+8Ch] [rbp-64h]
  float v99; // [rsp+90h] [rbp-60h]
  float v100; // [rsp+94h] [rbp-5Ch]
  float v101; // [rsp+98h] [rbp-58h]
  float v102; // [rsp+9Ch] [rbp-54h]
  float v103; // [rsp+A0h] [rbp-50h]
  float v104; // [rsp+A4h] [rbp-4Ch]
  float vars0; // [rsp+170h] [rbp+80h]
  void *retaddr; // [rsp+178h] [rbp+88h]
  int v107; // [rsp+180h] [rbp+90h]
  float v108; // [rsp+188h] [rbp+98h]

  x2 = this->Scale9.x2;
  y2 = this->Scale9.y2;
  y1 = this->Bounds.y1;
  *(float *)&v107 = x2;
  v85 = y2;
  x1 = this->Bounds.x1;
  v6 = this->Bounds.x2;
  v7 = this->Bounds.y2;
  v8 = this->Scale9.x1;
  v9 = this->Scale9.y1;
  *(float *)&retaddr = v8;
  vars0 = v9;
  v92 = y1;
  v91 = v6;
  v95 = v7;
  if ( x1 >= v8 )
  {
    x1 = v8 - 0.89999998;
    v91 = v8 - 0.89999998;
  }
  if ( y1 >= v9 )
  {
    y1 = v9 - 0.89999998;
    v92 = v9 - 0.89999998;
  }
  if ( v6 <= x2 )
  {
    v6 = v8 + 0.89999998;
    v91 = v8 + 0.89999998;
  }
  if ( v7 <= y2 )
  {
    v7 = v9 + 0.89999998;
    v95 = v9 + 0.89999998;
  }
  v10 = this->S9gMatrix.M[0][3];
  v11 = this->S9gMatrix.M[0][0];
  v12 = this->S9gMatrix.M[0][1] * y1;
  v13 = this->S9gMatrix.M[0][1] * v7;
  v14 = this->S9gMatrix.M[1][3];
  v15 = (__m128)LODWORD(this->S9gMatrix.M[1][0]);
  v16 = (__m128)LODWORD(this->S9gMatrix.M[1][1]);
  v17 = v15.m128_f32[0];
  v15.m128_f32[0] = v15.m128_f32[0] * v6;
  v18 = v17 * x1;
  v93 = (float)((float)(v11 * x1) + v12) + v10;
  v19 = v16.m128_f32[0];
  v16.m128_f32[0] = v16.m128_f32[0] * v7;
  v20 = v19 * y1;
  v108 = (float)(v18 + v20) + v14;
  v21 = v15;
  v90 = (float)((float)(v11 * v6) + v12) + v10;
  v21.m128_f32[0] = (float)(v15.m128_f32[0] + v20) + v14;
  v22 = v16;
  v86 = (float)(v13 + (float)(v11 * v6)) + v10;
  v22.m128_f32[0] = (float)(v16.m128_f32[0] + v15.m128_f32[0]) + v14;
  v23 = v21;
  v23.m128_f32[0] = v21.m128_f32[0] - v108;
  v24 = v23;
  v83 = v21.m128_f32[0] - v108;
  v25 = v93;
  v89 = v86 - v90;
  v26 = v90 - v93;
  v96 = v21.m128_f32[0];
  v92 = v22.m128_f32[0];
  v93 = (float)(v16.m128_f32[0] + v18) + v14;
  v87 = v26;
  v24.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v26 * v26);
  v27 = v22;
  v27.m128_f32[0] = v22.m128_f32[0] - v21.m128_f32[0];
  v28 = _mm_sqrt_ps(v24).m128_f32[0];
  v29 = v27;
  v94 = v22.m128_f32[0] - v21.m128_f32[0];
  v29.m128_f32[0] = (float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v89 * v89);
  LODWORD(v30) = _mm_sqrt_ps(v29).m128_u32[0];
  if ( v28 == 0.0 )
    v28 = FLOAT_0_001;
  if ( v30 == 0.0 )
    v30 = FLOAT_0_001;
  v31 = 1.0 / v30;
  v32 = (float)(v6 - *(float *)&v107) * (float)(1.0 / v28);
  v33 = (float)(*(float *)&retaddr - x1) * (float)(1.0 / v28);
  v34 = (float)(v9 - y1) * v31;
  v88 = v33;
  v84 = v32;
  v35 = (float)(v7 - v85) * v31;
  if ( (float)(v32 + v33) > 1.0 )
  {
    v36 = 1.0 / (float)((float)(v32 + v33) + 0.050000001);
    v33 = v33 * v36;
    v32 = v32 * v36;
    v88 = v33;
    v84 = v32;
  }
  if ( (float)(v35 + v34) > 1.0 )
  {
    v37 = 1.0 / (float)((float)(v35 + v34) + 0.050000001);
    v34 = v34 * v37;
    v35 = v35 * v37;
  }
  v38 = v26 * v33;
  v87 = v87 * v32;
  v39 = v83 * v33;
  v104 = v90 - v87;
  v83 = v83 * v32;
  v40 = v39 + v108;
  v41 = (float)(v89 * v34) + v90;
  v42 = v96 - v83;
  v102 = v41;
  v43 = v38 + v25;
  *(float *)&v44 = v92 - (float)(v94 * v35);
  *(float *)&v45 = v86 - (float)(v89 * v35);
  v46 = (float)((float)(v94 - v93) * v34) + v93;
  v47 = v94 - (float)((float)(v94 - v93) * v35);
  v94 = (float)(v94 * v34) + v96;
  v48 = (float)(v93 - v108) * v35;
  v49 = (float)((float)(v93 - v108) * v34) + v108;
  v89 = v38 + v46;
  *(float *)&v50 = v41 - v87;
  *(float *)&v51 = v94 - v83;
  v52 = v93 - v48;
  v99 = *(float *)&v45;
  v103 = *(float *)&v44;
  v101 = v47;
  v98 = v93 - v48;
  v97 = v39 + v49;
  v87 = (float)(v86 - v94) * v84;
  v83 = *(float *)&v45 - v87;
  v100 = (float)(v92 - v93) * v84;
  v84 = *(float *)&v44 - v100;
  v53 = (float)(v92 - v93) * v88;
  src = v91;
  v88 = (float)(v86 - v94) * v88;
  v79 = *(float *)&retaddr;
  dst = v93;
  v81 = *(float *)&retaddr;
  v72 = v108;
  v75 = v89;
  v73 = v43;
  v78 = v92;
  v80 = v92;
  v74 = v39 + v108;
  v76 = v39 + v49;
  v82 = vars0;
  *(float *)&v54 = v88 + v47;
  v55 = v53 + (float)(v93 - v48);
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(this->ResultingMatrices, &src, &dst);
  dst = v43;
  *(float *)&v56 = v92;
  LODWORD(src) = (_DWORD)retaddr;
  v72 = v40;
  v57 = v104;
  v79 = *(float *)&v107;
  v81 = *(float *)&v107;
  v73 = v104;
  v74 = v42;
  v82 = vars0;
  v75 = *(float *)&v50;
  v76 = *(float *)&v51;
  v78 = v92;
  v80 = v92;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[1], &src, &dst);
  v73 = v90;
  v78 = *(float *)&v56;
  v80 = *(float *)&v56;
  v58 = v91;
  v79 = v91;
  dst = v57;
  v59 = v94;
  v72 = v42;
  v60 = v102;
  v82 = vars0;
  v74 = v96;
  v75 = v102;
  v76 = v94;
  LODWORD(src) = v107;
  v81 = v91;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[2], &src, &dst);
  dst = v46;
  v61 = v89;
  v72 = v49;
  v62 = v97;
  v73 = v89;
  v74 = v97;
  src = v91;
  v75 = *(float *)&v54;
  v78 = vars0;
  v80 = vars0;
  v82 = v85;
  v76 = v53 + v52;
  v79 = *(float *)&retaddr;
  v81 = *(float *)&retaddr;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[3], &src, &dst);
  LODWORD(src) = (_DWORD)retaddr;
  dst = v61;
  *(float *)&v63 = v83;
  v78 = vars0;
  v80 = vars0;
  v72 = v62;
  v64 = v84;
  v82 = v85;
  v73 = *(float *)&v50;
  v74 = *(float *)&v51;
  v75 = v83;
  v76 = v84;
  v79 = *(float *)&v107;
  v81 = *(float *)&v107;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[4], &src, &dst);
  LODWORD(dst) = v50;
  *(float *)&v65 = v99;
  v72 = *(float *)&v51;
  *(float *)&v66 = v103;
  v73 = v60;
  v67 = vars0;
  v74 = v59;
  *(float *)&v68 = v85;
  v75 = v99;
  v76 = v103;
  v78 = vars0;
  v80 = vars0;
  v82 = v85;
  LODWORD(src) = v107;
  v79 = v58;
  v81 = v58;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[5], &src, &dst);
  v78 = *(float *)&v68;
  dst = v101;
  v76 = v53 + v93;
  v72 = v98;
  v80 = *(float *)&v68;
  v69 = v95;
  v75 = v88 + v94;
  v73 = *(float *)&v54;
  src = v91;
  v74 = v55;
  v79 = *(float *)&retaddr;
  v81 = *(float *)&retaddr;
  v82 = v95;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[6], &src, &dst);
  LODWORD(dst) = v54;
  *(float *)&v70 = v85;
  v72 = v55;
  v75 = v86 - v87;
  v76 = v92 - v100;
  v73 = *(float *)&v63;
  v74 = v64;
  LODWORD(src) = (_DWORD)retaddr;
  v78 = v85;
  v79 = *(float *)&v107;
  v80 = v85;
  v81 = *(float *)&v107;
  v82 = v69;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[7], &src, &dst);
  LODWORD(dst) = v63;
  v72 = v64;
  v75 = v86;
  v73 = *(float *)&v65;
  v76 = v92;
  v74 = *(float *)&v66;
  LODWORD(src) = v107;
  v78 = *(float *)&v70;
  v79 = v58;
  v80 = *(float *)&v70;
  v81 = v58;
  v82 = v69;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[8], &src, &dst);
  LODWORD(this->ResultingGrid.x1) = (_DWORD)retaddr;
  this->ResultingGrid.y1 = v67;
  this->ResultingGrid.x2 = *(float *)&v107;
  this->ResultingGrid.y2 = *(float *)&v70;
}

// File Line: 261
// RVA: 0x9BA660
__int64 __fastcall Scaleform::Render::Scale9GridInfo::Transform(
        Scaleform::Render::Scale9GridInfo *this,
        float *x,
        float *y)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  __int64 v9; // rdx
  __int64 result; // rax
  float *v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm2_4

  v3 = *x;
  v4 = *y;
  *x = (float)((float)(*y * this->ShapeMatrix.M[0][1]) + (float)(*x * this->ShapeMatrix.M[0][0]))
     + this->ShapeMatrix.M[0][3];
  v7 = (float)((float)(v4 * this->ShapeMatrix.M[1][1]) + (float)(v3 * this->ShapeMatrix.M[1][0]))
     + this->ShapeMatrix.M[1][3];
  *y = v7;
  v8 = *x;
  v9 = (*x > this->ResultingGrid.x2) | (2
                                      * ((v7 > this->ResultingGrid.y2) | (2
                                                                        * ((*x < this->ResultingGrid.x1) | (2 * (unsigned int)(v7 < this->ResultingGrid.y1))))));
  result = (unsigned int)v9;
  v11 = (float *)&this->ResultingMatrices[(unsigned __int8)codeToMtx[v9]];
  *x = (float)((float)(v7 * v11[1]) + (float)(v8 * *v11)) + v11[3];
  v12 = (float)((float)(v7 * v11[5]) + (float)(v8 * v11[4])) + v11[7];
  *y = v12;
  v13 = *x;
  *x = (float)((float)(v12 * this->InverseMatrix.M[0][1]) + (float)(*x * this->InverseMatrix.M[0][0]))
     + this->InverseMatrix.M[0][3];
  *y = (float)((float)(v12 * this->InverseMatrix.M[1][1]) + (float)(v13 * this->InverseMatrix.M[1][0]))
     + this->InverseMatrix.M[1][3];
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
  v3 = _mm_sqrt_ps(v1).m128_f32[0];
  v4 = (__m128)LODWORD(this->ResultingMatrices[1].M[1][1]);
  v5 = (float)(this->ResultingMatrices[1].M[0][1] + this->ResultingMatrices[1].M[0][0]) * 0.70710677;
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] + this->ResultingMatrices[1].M[1][0]) * 0.70710677)
                         * (float)((float)(v4.m128_f32[0] + this->ResultingMatrices[1].M[1][0]) * 0.70710677))
                 + (float)(v5 * v5);
  v6 = (float)(this->ResultingMatrices[2].M[0][1] + this->ResultingMatrices[2].M[0][0]) * 0.70710677;
  v7 = v3 + _mm_sqrt_ps(v4).m128_f32[0];
  v8 = (__m128)LODWORD(this->ResultingMatrices[2].M[1][1]);
  v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] + this->ResultingMatrices[2].M[1][0]) * 0.70710677)
                         * (float)((float)(v8.m128_f32[0] + this->ResultingMatrices[2].M[1][0]) * 0.70710677))
                 + (float)(v6 * v6);
  v9 = (float)(this->ResultingMatrices[3].M[0][1] + this->ResultingMatrices[3].M[0][0]) * 0.70710677;
  v10 = v7 + _mm_sqrt_ps(v8).m128_f32[0];
  v11 = (__m128)LODWORD(this->ResultingMatrices[3].M[1][1]);
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] + this->ResultingMatrices[3].M[1][0]) * 0.70710677)
                          * (float)((float)(v11.m128_f32[0] + this->ResultingMatrices[3].M[1][0]) * 0.70710677))
                  + (float)(v9 * v9);
  v12 = (float)(this->ResultingMatrices[4].M[0][1] + this->ResultingMatrices[4].M[0][0]) * 0.70710677;
  v13 = v10 + _mm_sqrt_ps(v11).m128_f32[0];
  v14 = (__m128)LODWORD(this->ResultingMatrices[4].M[1][1]);
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] + this->ResultingMatrices[4].M[1][0]) * 0.70710677)
                          * (float)((float)(v14.m128_f32[0] + this->ResultingMatrices[4].M[1][0]) * 0.70710677))
                  + (float)(v12 * v12);
  v15 = (float)(this->ResultingMatrices[5].M[0][1] + this->ResultingMatrices[5].M[0][0]) * 0.70710677;
  v16 = v13 + _mm_sqrt_ps(v14).m128_f32[0];
  v17 = (__m128)LODWORD(this->ResultingMatrices[5].M[1][1]);
  v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] + this->ResultingMatrices[5].M[1][0]) * 0.70710677)
                          * (float)((float)(v17.m128_f32[0] + this->ResultingMatrices[5].M[1][0]) * 0.70710677))
                  + (float)(v15 * v15);
  v18 = (float)(this->ResultingMatrices[6].M[0][1] + this->ResultingMatrices[6].M[0][0]) * 0.70710677;
  v19 = v16 + _mm_sqrt_ps(v17).m128_f32[0];
  v20 = (__m128)LODWORD(this->ResultingMatrices[6].M[1][1]);
  v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] + this->ResultingMatrices[6].M[1][0]) * 0.70710677)
                          * (float)((float)(v20.m128_f32[0] + this->ResultingMatrices[6].M[1][0]) * 0.70710677))
                  + (float)(v18 * v18);
  v21 = (float)(this->ResultingMatrices[7].M[0][1] + this->ResultingMatrices[7].M[0][0]) * 0.70710677;
  v22 = v19 + _mm_sqrt_ps(v20).m128_f32[0];
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
  return (float)((float)(v22 + _mm_sqrt_ps(v23).m128_f32[0]) + _mm_sqrt_ps(v24).m128_f32[0]) * 0.11111111;
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
  v2 = _mm_sqrt_ps(v1).m128_f32[0];
  v3 = (__m128)LODWORD(this->ResultingMatrices[1].M[0][0]);
  v3.m128_f32[0] = (float)(v3.m128_f32[0] * v3.m128_f32[0])
                 + (float)(this->ResultingMatrices[1].M[1][0] * this->ResultingMatrices[1].M[1][0]);
  v4 = v2 + _mm_sqrt_ps(v3).m128_f32[0];
  v5 = (__m128)LODWORD(this->ResultingMatrices[2].M[0][0]);
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0])
                 + (float)(this->ResultingMatrices[2].M[1][0] * this->ResultingMatrices[2].M[1][0]);
  return (float)(v4 + _mm_sqrt_ps(v5).m128_f32[0]) * 0.33333334;
}

// File Line: 312
// RVA: 0x9901A0
float __fastcall Scaleform::Render::Scale9GridInfo::GetYScale(Scaleform::Render::Scale9GridInfo *this)
{
  float v1; // xmm0_4
  float *v2; // rcx
  __int64 v3; // rax
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
    v1 = v1 + _mm_sqrt_ps(v4).m128_f32[0];
    --v3;
  }
  while ( v3 );
  return v1 * 0.33333334;
}

// File Line: 333
// RVA: 0x955290
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Scale9GridInfo::AdjustBounds(
        Scaleform::Render::Scale9GridInfo *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Rect<float> *bounds)
{
  float y1; // xmm5_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm10_4
  float x1; // xmm11_4
  float v9; // xmm9_4
  float v10; // xmm13_4
  float v11; // xmm12_4
  float v12; // xmm14_4
  float y2; // xmm15_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm3_4
  float x2; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm5_4
  float v24; // xmm1_4
  float *v25; // rax
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float *v30; // rax
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float *v36; // rcx
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm7_4
  float v41; // xmm9_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  float v48; // xmm4_4
  Scaleform::Render::Rect<float> *v49; // rax
  float v50; // [rsp+0h] [rbp-B8h]
  float v51; // [rsp+4h] [rbp-B4h]
  float v52; // [rsp+C0h] [rbp+8h]
  float v53; // [rsp+C8h] [rbp+10h]
  float v54; // [rsp+D0h] [rbp+18h]
  float v55; // [rsp+D8h] [rbp+20h]

  y1 = bounds->y1;
  v5 = this->InverseMatrix.M[0][3];
  v6 = this->InverseMatrix.M[1][1];
  v7 = this->ResultingGrid.y1;
  x1 = this->ResultingGrid.x1;
  v9 = this->InverseMatrix.M[0][1];
  v10 = this->ShapeMatrix.M[1][1];
  v11 = this->ShapeMatrix.M[1][3];
  v12 = this->ShapeMatrix.M[0][3];
  y2 = this->ResultingGrid.y2;
  v14 = this->InverseMatrix.M[1][3];
  v15 = (float)((float)(this->ShapeMatrix.M[0][0] * bounds->x1) + (float)(this->ShapeMatrix.M[0][1] * y1)) + v12;
  v16 = (float)((float)(this->ShapeMatrix.M[1][0] * bounds->x1) + (float)(v10 * y1)) + v11;
  v17 = (float *)&this->ResultingMatrices[(unsigned __int8)codeToMtx[(v15 > this->ResultingGrid.x2) | (unsigned __int64)(2 * ((v16 > y2) | (2 * ((x1 > v15) | (2 * (unsigned int)(v7 > v16))))))]];
  v18 = (float)((float)(v16 * v17[1]) + (float)(v15 * *v17)) + v17[3];
  v19 = (float)((float)(v16 * v17[5]) + (float)(v15 * v17[4])) + v17[7];
  v52 = (float)((float)(this->InverseMatrix.M[0][0] * v18) + (float)(v9 * v19)) + v5;
  x2 = bounds->x2;
  v53 = (float)((float)(this->InverseMatrix.M[1][0] * v18) + (float)(v6 * v19)) + v14;
  v21 = (float)(this->ShapeMatrix.M[0][0] * x2) + (float)(this->ShapeMatrix.M[0][1] * y1);
  v22 = v10 * y1;
  v23 = bounds->y2;
  v24 = (float)((float)(this->ShapeMatrix.M[1][0] * x2) + v22) + v11;
  v25 = (float *)&this->ResultingMatrices[(unsigned __int8)codeToMtx[((float)(v21 + v12) > this->ResultingGrid.x2) | (unsigned __int64)(2 * ((v24 > y2) | (2 * ((x1 > (float)(v21 + v12)) | (2 * (unsigned int)(v7 > v24))))))]];
  v26 = (float)((float)(v24 * v25[5]) + (float)((float)(v21 + v12) * v25[4])) + v25[7];
  v27 = (float)((float)(v24 * v25[1]) + (float)((float)(v21 + v12) * *v25)) + v25[3];
  v54 = (float)((float)(this->InverseMatrix.M[0][0] * v27) + (float)(v9 * v26)) + v5;
  v55 = (float)((float)(this->InverseMatrix.M[1][0] * v27) + (float)(v6 * v26)) + v14;
  v28 = (float)((float)(this->ShapeMatrix.M[0][0] * x2) + (float)(this->ShapeMatrix.M[0][1] * v23)) + v12;
  v29 = (float)((float)(this->ShapeMatrix.M[1][0] * x2) + (float)(v10 * v23)) + v11;
  v30 = (float *)&this->ResultingMatrices[(unsigned __int8)codeToMtx[(v28 > this->ResultingGrid.x2) | (unsigned __int64)(2 * ((v29 > y2) | (2 * ((x1 > v28) | (2 * (unsigned int)(v7 > v29))))))]];
  v31 = (float)((float)(v29 * v30[5]) + (float)(v28 * v30[4])) + v30[7];
  v32 = (float)((float)(v29 * v30[1]) + (float)(v28 * *v30)) + v30[3];
  v50 = (float)((float)(this->InverseMatrix.M[0][0] * v32) + (float)(v9 * v31)) + v5;
  v33 = (float)(this->InverseMatrix.M[1][0] * v32) + (float)(v6 * v31);
  v34 = (float)((float)(this->ShapeMatrix.M[1][0] * bounds->x1) + (float)(v10 * v23)) + v11;
  v51 = v33 + v14;
  v35 = (float)((float)(this->ShapeMatrix.M[0][0] * bounds->x1) + (float)(this->ShapeMatrix.M[0][1] * v23)) + v12;
  v36 = (float *)&this->ResultingMatrices[(unsigned __int8)codeToMtx[(v35 > this->ResultingGrid.x2) | (unsigned __int64)(2 * ((v34 > y2) | (2 * ((x1 > v35) | (2 * (unsigned int)(v7 > v34))))))]];
  v37 = (float)((float)(v34 * v36[1]) + (float)(v35 * *v36)) + v36[3];
  v38 = (float)((float)(v34 * v36[5]) + (float)(v35 * v36[4])) + v36[7];
  v39 = v53;
  v40 = v6 * v38;
  v41 = v9 * v38;
  v42 = v53;
  v43 = this->InverseMatrix.M[1][0] * v37;
  v44 = this->InverseMatrix.M[0][0] * v37;
  v45 = v52;
  v46 = v52;
  v47 = (float)(v44 + v41) + v5;
  v48 = (float)(v43 + v40) + v14;
  if ( v54 < v52 )
    v46 = v54;
  if ( v55 < v53 )
    v42 = v55;
  if ( v54 > v52 )
    v45 = v54;
  if ( v55 > v53 )
    v39 = v55;
  if ( v50 < v46 )
    v46 = v50;
  if ( v51 < v42 )
    v42 = v51;
  if ( v50 > v45 )
    v45 = v50;
  if ( v51 > v39 )
    v39 = v51;
  if ( v47 < v46 )
    v46 = v47;
  if ( v48 < v42 )
    v42 = v48;
  if ( v47 > v45 )
    v45 = v47;
  if ( v48 > v39 )
    v39 = v48;
  result->x1 = v46;
  result->y1 = v42;
  v49 = result;
  result->x2 = v45;
  result->y2 = v39;
  return v49;
}

// File Line: 396
// RVA: 0x9CB4E0
void __fastcall Scaleform::Render::Scale9GridTess::addVertices(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        Scaleform::Render::Matrix2x4<float> *toUV,
        float x,
        float y,
        unsigned int code1,
        unsigned int code2)
{
  unsigned int VerCount; // ecx
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float *p_x; // rax
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v18; // [rsp+30h] [rbp-58h] BYREF

  VerCount = this->VerCount;
  val.AreaCode = code1;
  v10 = x * toUV->M[0][0];
  v11 = x * toUV->M[1][0];
  val.VerIdx = VerCount;
  v18.VerIdx = VerCount;
  v12 = y * toUV->M[0][1];
  val.Slope = 0.0;
  v18.AreaCode = code2;
  v13 = (float)(v12 + v10) + toUV->M[0][3];
  v14 = y * toUV->M[1][1];
  v18.Slope = 0.0;
  v15 = (float)(v11 + v14) + toUV->M[1][3];
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v18);
  p_x = &this->Vertices[this->VerCount].x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = v13;
  p_x[3] = v15;
  ++this->VerCount;
}

// File Line: 423
// RVA: 0x9C66A0
void __fastcall Scaleform::Render::Scale9GridTess::addCorner(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        const float *c,
        float x,
        float y,
        Scaleform::Render::Matrix2x4<float> *toUV,
        unsigned int code1,
        unsigned int code2,
        unsigned int code3,
        unsigned int code4)
{
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v15; // xmm0_4
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
  char v29; // dl
  char v30; // cl
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  float *p_x; // rax
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [rsp+20h] [rbp-A8h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v37; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v38; // [rsp+40h] [rbp-88h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v39; // [rsp+50h] [rbp-78h] BYREF

  v10 = c[3];
  v11 = c[2];
  v12 = c[4];
  v15 = x - v11;
  v17 = c[5];
  v18 = (float)(v10 - c[1]) * v15;
  v19 = v17 - v10;
  v20 = y - v10;
  v21 = c[7];
  v22 = v18 - (float)((float)(v11 - *c) * v20);
  v23 = v12 - v11;
  v24 = c[6];
  v25 = (float)(v19 * (float)(x - v12)) - (float)(v23 * (float)(y - v17));
  v26 = (float)((float)(v21 - v17) * (float)(x - v24)) - (float)((float)(v24 - v12) * (float)(y - v21));
  v27 = (float)((float)(c[1] - v21) * (float)(x - *c)) - (float)((float)(*c - v24) * (float)(y - c[1]));
  v28 = v26 <= 0.0;
  v29 = v25 >= 0.0;
  v30 = v26 >= 0.0;
  if ( v22 <= 0.0 == v25 <= 0.0 && v25 <= 0.0 == v28 && v28 == v27 <= 0.0
    || v22 >= 0.0 == v29 && v29 == v30 && v30 == v27 >= 0.0 )
  {
    val.VerIdx = this->VerCount;
    v37.VerIdx = val.VerIdx;
    v38.VerIdx = val.VerIdx;
    v39.VerIdx = val.VerIdx;
    v31 = x * toUV->M[1][0];
    v32 = (float)((float)(y * toUV->M[0][1]) + (float)(x * toUV->M[0][0])) + toUV->M[0][3];
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
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v37);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v38);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v39);
    p_x = &this->Vertices[this->VerCount].x;
    *p_x = x;
    p_x[1] = y;
    p_x[2] = v32;
    p_x[3] = v34;
    ++this->VerCount;
  }
}

// File Line: 463
// RVA: 0x9F7450
void __fastcall Scaleform::Render::Scale9GridTess::transformVertex(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::Render::Scale9GridInfo *s9g,
        Scaleform::Render::Image9GridVertex *v)
{
  float y; // xmm0_4
  float x; // xmm2_4
  float *v5; // rcx
  float v6; // xmm3_4
  float v7; // xmm2_4

  y = v->y;
  x = v->x;
  v5 = (float *)&s9g->ResultingMatrices[(unsigned __int8)codeToMtx[(v->x > s9g->ResultingGrid.x2) | (unsigned __int64)(2 * ((y > s9g->ResultingGrid.y2) | (2 * ((v->x < s9g->ResultingGrid.x1) | (2 * (unsigned int)(y < s9g->ResultingGrid.y1))))))]];
  v->x = (float)((float)(y * v5[1]) + (float)(v->x * *v5)) + v5[3];
  v6 = (float)((float)(y * v5[5]) + (float)(x * v5[4])) + v5[7];
  v->y = v6;
  v7 = v->x;
  v->x = (float)((float)(v6 * s9g->InverseMatrix.M[0][1]) + (float)(v->x * s9g->InverseMatrix.M[0][0]))
       + s9g->InverseMatrix.M[0][3];
  v->y = (float)((float)(v6 * s9g->InverseMatrix.M[1][1]) + (float)(v7 * s9g->InverseMatrix.M[1][0]))
       + s9g->InverseMatrix.M[1][3];
}

// File Line: 493
// RVA: 0x9F5E80
void __fastcall Scaleform::Render::Scale9GridTess::tessellateArea(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        unsigned int i1,
        unsigned int i2)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r15
  unsigned int v8; // r10d
  __int64 v9; // rsi
  unsigned __int64 v10; // r11
  float v11; // xmm3_4
  float v12; // xmm4_4
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // rax
  unsigned int *p_VerIdx; // r8
  unsigned int *v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rax
  unsigned int *v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  unsigned int v21; // r9d
  __int64 v22; // r10
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  __int64 v26; // rcx
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
  __int64 v53; // rcx
  __int64 v54; // rdx
  Scaleform::Render::Scale9GridTess::TmpVertexType *v55; // r8
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm1_4
  __int64 v61; // rdi
  __int64 v62; // rbp
  Scaleform::ArrayStaticBuffPOD<unsigned short,72,2> *p_Indices; // rsi
  __int64 v64; // rbx
  unsigned __int16 val; // [rsp+A0h] [rbp+18h] BYREF

  v4 = i1;
  v5 = i2;
  if ( i1 + 3 <= i2 )
  {
    v8 = i1;
    v9 = i1;
    v10 = i1;
    v11 = 0.0;
    v12 = 0.0;
    if ( i1 < i2 )
    {
      if ( (int)(i2 - i1) >= 4 )
      {
        Data = ver->Data;
        p_VerIdx = &Data[i1].VerIdx;
        v15 = &Data[v4 + 2].VerIdx;
        LODWORD(Data) = ((i2 - (unsigned int)v4 - 4) >> 2) + 1;
        v16 = (unsigned int)Data;
        v8 = v4 + 4 * (_DWORD)Data;
        v10 = v4 + 4i64 * (unsigned int)Data;
        do
        {
          v17 = *p_VerIdx;
          p_VerIdx += 12;
          v15 += 12;
          v17 *= 2i64;
          v11 = (float)((float)((float)(v11 + *(&this->Vertices[0].x + 2 * v17)) + this->Vertices[*(v15 - 15)].x)
                      + this->Vertices[*(v15 - 12)].x)
              + this->Vertices[*(v15 - 9)].x;
          v12 = (float)((float)((float)(v12 + *(&this->Vertices[0].y + 2 * v17)) + this->Vertices[*(v15 - 15)].y)
                      + this->Vertices[*(v15 - 12)].y)
              + this->Vertices[*(v15 - 9)].y;
          --v16;
        }
        while ( v16 );
      }
      if ( v8 < i2 )
      {
        v18 = &ver->Data->VerIdx + 2 * v10 + v10;
        v19 = (int)(i2 - v8);
        do
        {
          v20 = *v18;
          v18 += 3;
          v20 *= 2i64;
          v11 = v11 + *(&this->Vertices[0].x + 2 * v20);
          v12 = v12 + *(&this->Vertices[0].y + 2 * v20);
          --v19;
        }
        while ( v19 );
      }
    }
    v21 = v4;
    v22 = v4;
    v23 = 1.0 / (float)((int)v5 - (int)v4);
    v24 = v11 * v23;
    v25 = v12 * v23;
    if ( (unsigned int)v4 < (unsigned int)v5 )
    {
      if ( (int)v5 - (int)v4 >= 4 )
      {
        v26 = v4;
        v27 = ((unsigned int)(v5 - v4 - 4) >> 2) + 1;
        v28 = v27;
        v21 = v4 + 4 * v27;
        v22 = v4 + 4i64 * v27;
        do
        {
          v29 = ver->Data;
          v30 = this->Vertices[v29[v26].VerIdx].x - v24;
          v31 = this->Vertices[v29[v26].VerIdx].y - v25;
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
          v35 = ver->Data;
          v36 = this->Vertices[v35[v26 + 1].VerIdx].x - v24;
          v37 = this->Vertices[v35[v26 + 1].VerIdx].y - v25;
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
          v41 = ver->Data;
          v42 = this->Vertices[v41[v26 + 2].VerIdx].x - v24;
          v43 = this->Vertices[v41[v26 + 2].VerIdx].y - v25;
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
          v47 = ver->Data;
          v48 = this->Vertices[v47[v26 + 3].VerIdx].x - v24;
          v49 = this->Vertices[v47[v26 + 3].VerIdx].y - v25;
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
        v54 = (int)(v5 - v21);
        do
        {
          v55 = ver->Data;
          v56 = this->Vertices[v55[v53].VerIdx].x - v24;
          v57 = this->Vertices[v55[v53].VerIdx].y - v25;
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
          v55[v53++].Slope = v59;
          --v54;
        }
        while ( v54 );
      }
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (*)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
      ver,
      v4,
      v5,
      (unsigned __int8 (__fastcall *)(Scaleform::Render::Scale9GridTess::TmpVertexType *))UFG::SectionChooser::fnSectionStreamPriority);
    v61 = (unsigned int)(v4 + 2);
    if ( (unsigned int)v61 < (unsigned int)v5 )
    {
      v62 = v9;
      p_Indices = &this->Indices;
      v64 = v61;
      do
      {
        val = ver->Data[v62].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, &val);
        val = ver->Data[(unsigned int)(v61 - 1)].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, &val);
        val = ver->Data[v64].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, &val);
        LODWORD(v61) = v61 + 1;
        ++v64;
      }
      while ( (unsigned int)v61 < (unsigned int)v5 );
    }
  }
}ices, &val);
        val = ver->Data[v64].VerIdx;
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, &val);
        LODWORD(v61)

// File Line: 535
// RVA: 0x942470
void __fastcall Scaleform::Render::Scale9GridTess::Scale9GridTess(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::Scale9GridInfo *s9g,
        Scaleform::Render::Rect<float> *imgRect)
{
  float x1; // xmm8_4
  float y1; // xmm1_4
  float x2; // xmm3_4
  float y2; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm11_4
  float v13; // xmm5_4
  float v14; // xmm10_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float *v17; // rax
  float x; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  __m128 si128; // xmm8
  __m128 v23; // xmm9
  __m128 v24; // xmm7
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm10_4
  float v30; // xmm5_4
  float v31; // xmm12_4
  float v32; // xmm13_4
  float v33; // xmm14_4
  __m128 v34; // xmm7
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm6_4
  float v40; // xmm11_4
  float v41; // xmm10_4
  float v42; // xmm12_4
  Scaleform::Render::Image9GridVertex *v43; // rax
  unsigned int v44; // edx
  float v45; // xmm6_4
  float v46; // xmm7_4
  Scaleform::Render::Image9GridVertex *v47; // rax
  unsigned int v48; // edx
  float v49; // xmm9_4
  float v50; // xmm8_4
  float v51; // xmm6_4
  Scaleform::Render::Image9GridVertex *v52; // rax
  unsigned int v53; // edx
  float v54; // xmm6_4
  float v55; // xmm10_4
  Scaleform::Render::Image9GridVertex *v56; // rax
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
  bool v84; // cf
  float v85; // xmm11_4
  float v86; // xmm1_4
  float v87; // xmm3_4
  float v88; // xmm3_4
  float v89; // xmm2_4
  float v90; // xmm4_4
  float v91; // xmm3_4
  float v92; // xmm4_4
  float v93; // xmm3_4
  float v94; // xmm2_4
  float v95; // xmm4_4
  float v96; // xmm3_4
  float v97; // xmm1_4
  float v98; // xmm5_4
  float v99; // xmm3_4
  float v100; // xmm2_4
  float v101; // xmm3_4
  float v102; // xmm2_4
  float v103; // xmm14_4
  float v104; // xmm15_4
  float v105; // xmm5_4
  float v106; // xmm4_4
  float v107; // xmm15_4
  float v108; // xmm14_4
  int v109; // xmm1_4
  float v110; // xmm3_4
  float v111; // xmm2_4
  float v112; // xmm14_4
  float v113; // xmm3_4
  float v114; // xmm2_4
  float v115; // xmm10_4
  float v116; // xmm2_4
  float v117; // xmm3_4
  float v118; // xmm2_4
  float v119; // xmm5_4
  float v120; // xmm3_4
  float v121; // xmm2_4
  float v122; // xmm3_4
  float v123; // xmm2_4
  float v124; // xmm3_4
  float v125; // xmm2_4
  float v126; // xmm3_4
  float v127; // xmm2_4
  float v128; // xmm1_4
  float v129; // xmm10_4
  float v130; // xmm11_4
  float v131; // xmm3_4
  int v132; // xmm2_4
  float v133; // xmm4_4
  float v134; // xmm3_4
  float v135; // xmm2_4
  float v136; // xmm5_4
  float v137; // xmm3_4
  float v138; // xmm4_4
  float v139; // xmm3_4
  float v140; // xmm2_4
  float v141; // xmm4_4
  int v142; // xmm3_4
  float v143; // xmm2_4
  float v144; // xmm3_4
  float v145; // xmm2_4
  float v146; // xmm1_4
  float v147; // xmm2_4
  float v148; // xmm3_4
  float v149; // xmm2_4
  unsigned int v150; // edi
  unsigned int v151; // r8d
  unsigned __int64 Size; // r10
  __int64 v153; // rdx
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // r9
  unsigned int i; // edi
  float v156; // [rsp+50h] [rbp-88h]
  float v157; // [rsp+50h] [rbp-88h]
  float v158; // [rsp+50h] [rbp-88h]
  float v159; // [rsp+54h] [rbp-84h]
  float v160; // [rsp+54h] [rbp-84h]
  float v161; // [rsp+54h] [rbp-84h]
  float v162; // [rsp+54h] [rbp-84h]
  float v163; // [rsp+58h] [rbp-80h]
  float v164; // [rsp+58h] [rbp-80h]
  float v165; // [rsp+58h] [rbp-80h]
  float v166; // [rsp+5Ch] [rbp-7Ch]
  float v167; // [rsp+5Ch] [rbp-7Ch]
  float v168; // [rsp+5Ch] [rbp-7Ch]
  float v169; // [rsp+5Ch] [rbp-7Ch]
  float v170; // [rsp+60h] [rbp-78h]
  float v171; // [rsp+60h] [rbp-78h]
  float v172; // [rsp+60h] [rbp-78h]
  float v173; // [rsp+60h] [rbp-78h]
  Scaleform::Render::Matrix2x4<float> toUV; // [rsp+68h] [rbp-70h] BYREF
  float v175; // [rsp+88h] [rbp-50h]
  float dst[4]; // [rsp+98h] [rbp-40h] BYREF
  __m128 v177; // [rsp+A8h] [rbp-30h]
  float v178; // [rsp+B8h] [rbp-20h]
  float src[10]; // [rsp+C0h] [rbp-18h] BYREF
  __m128 v180; // [rsp+E8h] [rbp+10h]
  __m128 v181; // [rsp+F8h] [rbp+20h]
  __int64 v182; // [rsp+108h] [rbp+30h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> ver; // [rsp+118h] [rbp+40h] BYREF
  float v184; // [rsp+570h] [rbp+498h]
  float v185; // [rsp+578h] [rbp+4A0h]
  float vars0; // [rsp+580h] [rbp+4A8h]
  float *retaddr; // [rsp+588h] [rbp+4B0h]
  float v188; // [rsp+590h] [rbp+4B8h]
  float v189; // [rsp+590h] [rbp+4B8h]

  v182 = -2i64;
  this->VerCount = 0;
  this->Indices.pHeap = heap;
  this->Indices.Size = 0i64;
  this->Indices.Reserved = 72i64;
  this->Indices.Data = this->Indices.Static;
  x1 = imgRect->x1;
  y1 = imgRect->y1;
  x2 = imgRect->x2;
  y2 = imgRect->y2;
  v11 = s9g->ShapeMatrix.M[0][1];
  v12 = s9g->ShapeMatrix.M[0][0];
  v13 = s9g->ShapeMatrix.M[0][3];
  v175 = (float)((float)(v12 * imgRect->x1) + (float)(v11 * y1)) + v13;
  src[0] = v175;
  v14 = s9g->ShapeMatrix.M[1][1];
  v15 = s9g->ShapeMatrix.M[1][0];
  v16 = s9g->ShapeMatrix.M[1][3];
  v156 = (float)((float)(v15 * x1) + (float)(v14 * y1)) + v16;
  src[1] = v156;
  vars0 = (float)((float)(v12 * x2) + (float)(v11 * y1)) + v13;
  src[2] = vars0;
  v184 = (float)((float)(v15 * x2) + (float)(v14 * y1)) + v16;
  src[3] = v184;
  toUV.M[1][1] = (float)((float)(v12 * x2) + (float)(v11 * y2)) + v13;
  src[4] = toUV.M[1][1];
  v185 = (float)((float)(v15 * x2) + (float)(v14 * y2)) + v16;
  src[5] = v185;
  toUV.M[1][0] = (float)((float)(v12 * x1) + (float)(v11 * y2)) + v13;
  src[6] = toUV.M[1][0];
  v178 = (float)((float)(v14 * y2) + (float)(x1 * v15)) + v16;
  src[7] = v178;
  v17 = retaddr;
  *(float *)&retaddr = retaddr[3];
  v163 = v17[7];
  x = this->Vertices[0].x;
  toUV.M[0][0] = x;
  v19 = this->Vertices[0].y;
  *(_QWORD *)&toUV.M[0][1] = *(_QWORD *)&this->Vertices[0].y;
  v20 = this->Vertices[1].x;
  toUV.M[1][0] = v20;
  v21 = this->Vertices[1].y;
  *(_QWORD *)&toUV.M[1][1] = *(_QWORD *)&this->Vertices[1].y;
  *(_QWORD *)dst = 1065353216i64;
  dst[2] = 0.0;
  v177.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)v177.m128_u64 + 4) = 1065353216i64;
  if ( x > -0.0000099999997 )
  {
    if ( x >= 0.0000099999997 )
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
  v177.m128_i32[3] = -1090519040;
  si128 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
  v23 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
  v24 = _mm_add_ps(
          _mm_mul_ps(*(__m128 *)dst, _mm_shuffle_ps(*(__m128 *)&toUV.M[1][0], *(__m128 *)&toUV.M[1][0], 0)),
          _mm_mul_ps(v177, _mm_shuffle_ps(*(__m128 *)&toUV.M[1][0], *(__m128 *)&toUV.M[1][0], 85)));
  *(__m128 *)dst = _mm_and_ps(
                     v23,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           *(__m128 *)dst,
                           _mm_shuffle_ps(*(__m128 *)&toUV.M[0][0], *(__m128 *)&toUV.M[0][0], 0)),
                         _mm_mul_ps(v177, _mm_shuffle_ps(*(__m128 *)&toUV.M[0][0], *(__m128 *)&toUV.M[0][0], 85))),
                       _mm_and_ps(*(__m128 *)&toUV.M[0][0], si128)));
  v177 = _mm_and_ps(v23, _mm_add_ps(_mm_and_ps(*(__m128 *)&toUV.M[1][0], si128), v24));
  v25 = _mm_shuffle_ps(*(__m128 *)dst, *(__m128 *)dst, 255).m128_f32[0] + 0.5;
  v26 = _mm_shuffle_ps(v177, v177, 255).m128_f32[0] + 0.5;
  v27 = v17[1];
  v28 = *v17;
  v180.m128_f32[0] = (float)(v177.m128_f32[0] * v27) + (float)(dst[0] * *v17);
  v29 = v180.m128_f32[0];
  v30 = v17[5];
  v24.m128_f32[0] = v17[4];
  v31 = (float)(v177.m128_f32[0] * v30) + (float)(dst[0] * v24.m128_f32[0]);
  v181.m128_f32[0] = v31;
  v32 = (float)(v177.m128_f32[1] * v27) + (float)(v28 * dst[1]);
  v180.m128_f32[1] = v32;
  v33 = (float)(v177.m128_f32[1] * v30) + (float)(v24.m128_f32[0] * dst[1]);
  v181.m128_f32[1] = v33;
  v181.m128_i32[2] = 0;
  v180.m128_i32[2] = 0;
  *(float *)&retaddr = *(float *)&retaddr + (float)((float)(v27 * v26) + (float)(v28 * v25));
  v180.m128_i32[3] = (int)retaddr;
  v181.m128_f32[3] = v163 + (float)((float)(v30 * v26) + (float)(v24.m128_f32[0] * v25));
  *(_OWORD *)&toUV.M[0][0] = _xmm;
  *(__m128 *)&toUV.M[1][0] = _xmm;
  *(_QWORD *)dst = 0i64;
  *(_QWORD *)&dst[2] = 1065353216i64;
  v177.m128_u64[0] = 0x3F8000003F800000i64;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&toUV, src, dst);
  v34 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v181, v181, 85), *(__m128 *)&toUV.M[1][0]),
          _mm_mul_ps(_mm_shuffle_ps(v181, v181, 0), *(__m128 *)&toUV.M[0][0]));
  *(__m128 *)&toUV.M[0][0] = _mm_and_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v180, v180, 85), *(__m128 *)&toUV.M[1][0]),
                                   _mm_mul_ps(_mm_shuffle_ps(v180, v180, 0), *(__m128 *)&toUV.M[0][0])),
                                 _mm_and_ps(v180, si128)),
                               v23);
  *(__m128 *)&toUV.M[1][0] = _mm_and_ps(_mm_add_ps(v34, _mm_and_ps(v181, si128)), v23);
  v35 = s9g->ResultingGrid.y2;
  v164 = v35;
  toUV.M[0][2] = s9g->ResultingGrid.x2;
  v188 = s9g->ResultingGrid.y1;
  v36 = s9g->ResultingGrid.x1;
  v170 = v36;
  ver.pHeap = heap;
  ver.Size = 0i64;
  ver.Reserved = 72i64;
  ver.Data = ver.Static;
  v37 = v29 * 0.0;
  v34.m128_f32[0] = (float)((float)(v29 * 0.0) + (float)(v32 * 0.0)) + *(float *)&retaddr;
  v38 = v31 * 0.0;
  v39 = (float)((float)(v31 * 0.0) + (float)(v33 * 0.0)) + v35;
  v23.m128_f32[0] = (float)(v29 + (float)(v32 * 0.0)) + *(float *)&retaddr;
  si128.m128_f32[0] = (float)(v31 + (float)(v33 * 0.0)) + v35;
  v40 = (float)(v32 + v29) + *(float *)&retaddr;
  v41 = (float)(v33 + v31) + v35;
  v42 = toUV.M[0][2];
  LODWORD(dst[0]) = (v175 > toUV.M[0][2]) | (2 * ((v156 > v35) | (2 * ((v36 > v175) | (2 * (v188 > v156))))));
  dst[1] = *(float *)&this->VerCount;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v43 = &this->Vertices[this->VerCount];
  v43->x = v175;
  v43->y = v156;
  LODWORD(v43->u) = v34.m128_i32[0];
  v43->v = v39;
  v44 = ++this->VerCount;
  v45 = vars0;
  v46 = v164;
  LODWORD(dst[0]) = (vars0 > v42) | (2 * ((v184 > v164) | (2 * ((v170 > vars0) | (2 * (v188 > v184))))));
  LODWORD(dst[1]) = v44;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v47 = &this->Vertices[this->VerCount];
  v47->x = v45;
  v47->y = v184;
  LODWORD(v47->u) = v23.m128_i32[0];
  LODWORD(v47->v) = si128.m128_i32[0];
  v48 = ++this->VerCount;
  v49 = v188;
  v50 = v170;
  v51 = toUV.M[1][1];
  LODWORD(dst[0]) = (toUV.M[1][1] > v42) | (2 * ((v185 > v164) | (2 * ((v170 > toUV.M[1][1]) | (2 * (v188 > v185))))));
  LODWORD(dst[1]) = v48;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v52 = &this->Vertices[this->VerCount];
  v52->x = v51;
  v52->y = v185;
  v52->u = v40;
  v52->v = v41;
  v53 = ++this->VerCount;
  v54 = v178;
  v55 = toUV.M[1][0];
  LODWORD(dst[0]) = (toUV.M[1][0] > v42) | (2 * ((v178 > v164) | (2 * ((v170 > toUV.M[1][0]) | (2 * (v188 > v178))))));
  LODWORD(dst[1]) = v53;
  dst[2] = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
    &ver,
    (Scaleform::Render::Scale9GridTess::TmpVertexType *)dst);
  v56 = &this->Vertices[this->VerCount];
  v56->x = v55;
  v56->y = v54;
  v56->u = (float)(v32 + v37) + *(float *)&retaddr;
  v56->v = (float)(v33 + v38) + v164;
  ++this->VerCount;
  v57 = (float)(v42 - v170) * 0.5;
  *(float *)&retaddr = v57;
  v165 = v164 - v188;
  v58 = v165;
  v189 = v165 * 0.5;
  toUV.M[0][3] = v156 - v49;
  v60 = v175;
  v159 = v175 - v170;
  toUV.M[0][2] = (float)((float)(v156 - v49) * (float)(v42 - v50)) - (float)(0.0 * (float)(v175 - v50));
  v61 = vars0 - v175;
  v171 = vars0 - v175;
  v166 = (float)((float)(vars0 - v175) * 0.0) - (float)((float)(v184 - v156) * (float)(v42 - v50));
  if ( COERCE_FLOAT(LODWORD(v166) & _xmm) >= 0.001 )
  {
    v62 = toUV.M[0][2] / v166;
    if ( (float)(toUV.M[0][2] / v166) >= -0.0000099999997 && v62 <= 1.00001 )
    {
      v63 = (float)(v62 * v61) + v175;
      toUV.M[0][2] = (float)(v62 * v166) + v156;
      v59 = v165 * 0.5;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v63,
        toUV.M[0][2],
        (v63 > v42) | (2
                     * (((float)(toUV.M[0][2] + v59) > v46) | (2
                                                             * ((v50 > v63) | (2 * (v49 > (float)(toUV.M[0][2] + v59))))))),
        (v63 > v42) | (2
                     * (((float)(toUV.M[0][2] - v59) > v46) | (2
                                                             * ((v50 > v63) | (2 * (v49 > (float)(toUV.M[0][2] - v59))))))));
      v57 = *(float *)&retaddr;
      v58 = v165;
      v61 = v171;
    }
  }
  v167 = v60 - v42;
  v64 = (float)(0.0 * toUV.M[0][3]) - (float)((float)(v60 - v42) * v58);
  toUV.M[0][3] = (float)(v61 * v58) - (float)(0.0 * (float)(v60 - v42));
  v65 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(toUV.M[0][3]) & _xmm) >= 0.001 )
  {
    v66 = v64 / toUV.M[0][3];
    if ( v66 >= -0.0000099999997 && v66 <= 1.00001 )
    {
      v67 = (float)(v66 * v61) + v60;
      y = (float)(v66 * v167) + v156;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v67,
        y,
        ((float)(v67 + v57) > v42) | (2 * ((y > v46) | (2 * ((2 * (v49 > y)) | (v50 > (float)(v67 + v57)))))),
        ((float)(v67 - v57) > v42) | (2 * ((y > v46) | (2 * ((2 * (v49 > y)) | (v50 > (float)(v67 - v57)))))));
      v65 = FLOAT_0_001;
      v61 = v171;
    }
  }
  toUV.M[0][2] = v50 - v42;
  toUV.M[0][3] = 0.0 * v61;
  v69 = v60 - v42;
  v70 = (float)(0.0 * v61) - (float)((float)(v50 - v42) * v167);
  if ( COERCE_FLOAT(LODWORD(v70) & _xmm) >= v65 )
  {
    v71 = (float)((float)((float)(v50 - v42) * (float)(v156 - v46)) - (float)(0.0 * v167)) / v70;
    if ( v71 >= -0.0000099999997 && v71 <= 1.00001 )
    {
      v72 = (float)(v71 * v61) + v60;
      v73 = (float)(v71 * v167) + v156;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v72,
        v73,
        (v72 > v42) | (2 * (((float)(v73 + v189) > v46) | (2 * ((v50 > v72) | (2 * (v49 > (float)(v73 + v189))))))),
        (v72 > v42) | (2 * (((float)(v73 - v189) > v46) | (2 * ((v50 > v72) | (2 * (v49 > (float)(v73 - v189))))))));
      v61 = v156 - v46;
      v69 = v60 - v42;
    }
  }
  v74 = (float)((float)(v49 - v46) * v61) - (float)(0.0 * v69);
  v75 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(v74) & _xmm) >= 0.001 )
  {
    v76 = (float)((float)(0.0 * (float)(v49 - v46)) - (float)((float)(v49 - v46) * v159)) / v74;
    if ( v76 >= -0.0000099999997 && v76 <= 1.00001 )
    {
      v77 = (float)(v61 * v76) + v60;
      v78 = (float)(v69 * v76) + v156;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v77,
        v78,
        ((float)(v77 + *(float *)&retaddr) > v42) | (2
                                                   * ((v78 > v46) | (2
                                                                   * ((2 * (v49 > v78)) | (v50 > (float)(v77 + *(float *)&retaddr)))))),
        ((float)(v77 - *(float *)&retaddr) > v42) | (2
                                                   * ((v78 > v46) | (2
                                                                   * ((2 * (v49 > v78)) | (v50 > (float)(v77 - *(float *)&retaddr)))))));
      v75 = FLOAT_0_001;
    }
  }
  v79 = v184;
  v80 = v184 - v49;
  v172 = v184 - v49;
  v81 = vars0;
  toUV.M[0][3] = vars0 - v50;
  v82 = toUV.M[1][1] - vars0;
  v83 = v185 - v184;
  v168 = (float)((float)(toUV.M[1][1] - vars0) * 0.0) - (float)((float)(v185 - v184) * v165);
  v84 = COERCE_FLOAT(LODWORD(v168) & _xmm) < v75;
  v85 = v156;
  v86 = FLOAT_1_00001;
  if ( !v84 )
  {
    v87 = (float)((float)((float)(v184 - v49) * v165) - (float)((float)(vars0 - v50) * 0.0)) / v168;
    v160 = v87;
    if ( v87 >= -0.0000099999997 && v87 <= 1.00001 )
    {
      v88 = (float)(v82 * v87) + vars0;
      v89 = (float)(v83 * v160) + v184;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v88,
        v89,
        (v88 > v42) | (2 * (((float)(v89 + v189) > v46) | (2 * ((v50 > v88) | (2 * (v49 > (float)(v89 + v189))))))),
        (v88 > v42) | (2 * (((float)(v89 - v189) > v46) | (2 * ((v50 > v88) | (2 * (v49 > (float)(v89 - v189))))))));
      v86 = FLOAT_1_00001;
      v80 = v172;
      v81 = vars0;
      v79 = v184;
    }
  }
  v157 = v81 - v42;
  v90 = (float)(v80 * 0.0) - (float)(v165 * (float)(v81 - v42));
  v91 = (float)(v82 * v165) - (float)(v83 * 0.0);
  if ( COERCE_FLOAT(LODWORD(v91) & _xmm) >= 0.001 )
  {
    v92 = v90 / v91;
    if ( v92 >= -0.0000099999997 && v92 <= v86 )
    {
      v93 = (float)(v82 * v92) + v81;
      v94 = (float)(v83 * v92) + v79;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v93,
        v94,
        ((float)(v93 + *(float *)&retaddr) > v42) | (2
                                                   * ((v94 > v46) | (2
                                                                   * ((2 * (v49 > v94)) | (v50 > (float)(v93 + *(float *)&retaddr)))))),
        ((float)(v93 - *(float *)&retaddr) > v42) | (2
                                                   * ((v94 > v46) | (2
                                                                   * ((2 * (v49 > v94)) | (v50 > (float)(v93 - *(float *)&retaddr)))))));
      v81 = vars0;
    }
  }
  v95 = v184;
  v161 = v184 - v46;
  v96 = (float)(v82 * 0.0) - (float)(v83 * toUV.M[0][2]);
  v97 = FLOAT_1_00001;
  if ( COERCE_FLOAT(LODWORD(v96) & _xmm) >= 0.001 )
  {
    v98 = (float)((float)(toUV.M[0][2] * (float)(v184 - v46)) - (float)(0.0 * v157)) / v96;
    if ( v98 >= -0.0000099999997 && v98 <= 1.00001 )
    {
      v99 = (float)(v82 * v98) + v81;
      v100 = (float)(v83 * v98) + v184;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v99,
        v100,
        (v99 > v42) | (2 * (((float)(v100 + v189) > v46) | (2 * ((v50 > v99) | (2 * (v49 > (float)(v100 + v189))))))),
        (v99 > v42) | (2 * (((float)(v100 - v189) > v46) | (2 * ((v50 > v99) | (2 * (v49 > (float)(v100 - v189))))))));
      v97 = FLOAT_1_00001;
      v95 = v184;
    }
  }
  v101 = (float)(v82 * v172) - (float)(v83 * 0.0);
  if ( COERCE_FLOAT(LODWORD(v101) & _xmm) >= 0.001 )
  {
    v102 = (float)((float)(0.0 * v161) - (float)(toUV.M[0][3] * v172)) / v101;
    if ( v102 >= -0.0000099999997 && v102 <= v97 )
    {
      v103 = (float)(v82 * v102) + vars0;
      v104 = (float)(v83 * v102) + v95;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v103,
        v104,
        ((float)(v103 + *(float *)&retaddr) > v42) | (2
                                                    * ((v104 > v46) | (2
                                                                     * ((2 * (v49 > v104)) | (v50 > (float)(v103 + *(float *)&retaddr)))))),
        ((float)(v103 - *(float *)&retaddr) > v42) | (2
                                                    * ((v104 > v46) | (2
                                                                     * ((2 * (v49 > v104)) | (v50 > (float)(v103 - *(float *)&retaddr)))))));
    }
  }
  v105 = v185;
  v162 = v185 - v49;
  v106 = toUV.M[1][1];
  v169 = toUV.M[1][1] - v50;
  v184 = toUV.M[1][0] - toUV.M[1][1];
  v107 = v178;
  vars0 = v178 - v185;
  v108 = (float)(0.0 * (float)(toUV.M[1][0] - toUV.M[1][1])) - (float)(v165 * (float)(v178 - v185));
  v109 = _xmm;
  v110 = FLOAT_0_001;
  if ( COERCE_FLOAT(LODWORD(v108) & _xmm) < 0.001 )
  {
    v112 = FLOAT_1_00001;
  }
  else
  {
    v111 = (float)((float)(v165 * (float)(v185 - v49)) - (float)(0.0 * (float)(toUV.M[1][1] - v50))) / v108;
    v112 = FLOAT_1_00001;
    if ( v111 >= -0.0000099999997 && v111 <= 1.00001 )
    {
      v113 = (float)(v111 * v184) + toUV.M[1][1];
      v114 = (float)(v111 * vars0) + v185;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v113,
        v114,
        (v113 > v42) | (2 * (((float)(v114 + v189) > v46) | (2 * ((v50 > v113) | (2 * (v49 > (float)(v114 + v189))))))),
        (v113 > v42) | (2 * (((float)(v114 - v189) > v46) | (2 * ((v50 > v113) | (2 * (v49 > (float)(v114 - v189))))))));
      v109 = _xmm;
      v110 = FLOAT_0_001;
      v106 = toUV.M[1][1];
      v105 = v185;
    }
  }
  v173 = v106 - v42;
  v158 = (float)(v165 * v184) - (float)(0.0 * vars0);
  v115 = v175;
  if ( COERCE_FLOAT(LODWORD(v158) & v109) >= v110 )
  {
    v116 = (float)((float)(0.0 * v162) - (float)(v165 * (float)(v106 - v42))) / v158;
    if ( v116 >= -0.0000099999997 && v116 <= v112 )
    {
      v117 = (float)(v116 * v184) + v106;
      v118 = (float)(v116 * vars0) + v105;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v117,
        v118,
        ((float)(v117 + *(float *)&retaddr) > v42) | (2
                                                    * ((v118 > v46) | (2
                                                                     * ((2 * (v49 > v118)) | (v50 > (float)(v117 + *(float *)&retaddr)))))),
        ((float)(v117 - *(float *)&retaddr) > v42) | (2
                                                    * ((v118 > v46) | (2
                                                                     * ((2 * (v49 > v118)) | (v50 > (float)(v117 - *(float *)&retaddr)))))));
      v109 = _xmm;
      v106 = toUV.M[1][1];
    }
  }
  v119 = v185;
  toUV.M[0][3] = v185 - v46;
  v120 = (float)(0.0 * v184) - (float)(toUV.M[0][2] * vars0);
  if ( COERCE_FLOAT(LODWORD(v120) & v109) >= 0.001 )
  {
    v121 = (float)((float)(toUV.M[0][2] * (float)(v185 - v46)) - (float)(0.0 * v173)) / v120;
    if ( v121 >= -0.0000099999997 && v121 <= v112 )
    {
      v122 = (float)(v121 * v184) + v106;
      v123 = (float)(v121 * vars0) + v185;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v122,
        v123,
        (v122 > v42) | (2 * (((float)(v123 + v189) > v46) | (2 * ((v50 > v122) | (2 * (v49 > (float)(v123 + v189))))))),
        (v122 > v42) | (2 * (((float)(v123 - v189) > v46) | (2 * ((v50 > v122) | (2 * (v49 > (float)(v123 - v189))))))));
      v119 = v185;
    }
  }
  v124 = (float)(v173 * v184) - (float)(0.0 * vars0);
  if ( COERCE_FLOAT(LODWORD(v124) & _xmm) >= 0.001 )
  {
    v125 = (float)((float)(0.0 * toUV.M[0][3]) - (float)(v173 * v169)) / v124;
    if ( v125 >= -0.0000099999997 && v125 <= v112 )
    {
      v126 = (float)(v125 * v184) + toUV.M[1][1];
      v127 = (float)(v125 * vars0) + v119;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v126,
        v127,
        ((float)(v126 + *(float *)&retaddr) > v42) | (2
                                                    * ((v127 > v46) | (2
                                                                     * ((2 * (v49 > v127)) | (v50 > (float)(v126 + *(float *)&retaddr)))))),
        ((float)(v126 - *(float *)&retaddr) > v42) | (2
                                                    * ((v127 > v46) | (2
                                                                     * ((2 * (v49 > v127)) | (v50 > (float)(v126 - *(float *)&retaddr)))))));
    }
  }
  v184 = v107 - v49;
  v128 = toUV.M[1][0];
  vars0 = toUV.M[1][0] - v50;
  v129 = v115 - toUV.M[1][0];
  v130 = v85 - v107;
  v131 = (float)(0.0 * v129) - (float)(v165 * v130);
  v132 = _xmm;
  if ( COERCE_FLOAT(LODWORD(v131) & _xmm) >= 0.001 )
  {
    v133 = (float)((float)(v165 * (float)(v107 - v49)) - (float)(0.0 * (float)(toUV.M[1][0] - v50))) / v131;
    if ( v133 >= -0.0000099999997 && v133 <= v112 )
    {
      v134 = (float)(v129 * v133) + toUV.M[1][0];
      v135 = (float)(v130 * v133) + v107;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v134,
        v135,
        (v134 > v42) | (2 * (((float)(v135 + v189) > v46) | (2 * ((v50 > v134) | (2 * (v49 > (float)(v135 + v189))))))),
        (v134 > v42) | (2 * (((float)(v135 - v189) > v46) | (2 * ((v50 > v134) | (2 * (v49 > (float)(v135 - v189))))))));
      v128 = toUV.M[1][0];
      v132 = _xmm;
    }
  }
  v136 = v128 - v42;
  v185 = v128 - v42;
  v137 = (float)(v165 * v129) - (float)(0.0 * v130);
  if ( COERCE_FLOAT(LODWORD(v137) & v132) >= 0.001 )
  {
    v138 = (float)((float)(0.0 * v184) - (float)(v165 * (float)(v128 - v42))) / v137;
    if ( v138 >= -0.0000099999997 && v138 <= v112 )
    {
      v139 = (float)(v138 * v129) + v128;
      v140 = (float)(v130 * v138) + v107;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v139,
        v140,
        ((float)(v139 + *(float *)&retaddr) > v42) | (2
                                                    * ((v140 > v46) | (2
                                                                     * ((2 * (v49 > v140)) | (v50 > (float)(v139 + *(float *)&retaddr)))))),
        ((float)(v139 - *(float *)&retaddr) > v42) | (2
                                                    * ((v140 > v46) | (2
                                                                     * ((2 * (v49 > v140)) | (v50 > (float)(v139 - *(float *)&retaddr)))))));
      v128 = toUV.M[1][0];
      v136 = v185;
    }
  }
  v184 = v107 - v46;
  v141 = (float)(0.0 * v129) - (float)(toUV.M[0][2] * v130);
  v142 = _xmm;
  if ( COERCE_FLOAT(LODWORD(v141) & _xmm) >= 0.001 )
  {
    v143 = (float)((float)(toUV.M[0][2] * (float)(v107 - v46)) - (float)(0.0 * v136)) / v141;
    if ( v143 >= -0.0000099999997 && v143 <= v112 )
    {
      v144 = (float)(v143 * v129) + v128;
      v145 = (float)(v143 * v130) + v107;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v144,
        v145,
        (v144 > v42) | (2 * (((float)(v145 + v189) > v46) | (2 * ((v50 > v144) | (2 * (v49 > (float)(v145 + v189))))))),
        (v144 > v42) | (2 * (((float)(v145 - v189) > v46) | (2 * ((v50 > v144) | (2 * (v49 > (float)(v145 - v189))))))));
      v142 = _xmm;
    }
  }
  v146 = (float)(v173 * v129) - (float)(0.0 * v130);
  if ( COERCE_FLOAT(LODWORD(v146) & v142) >= 0.001 )
  {
    v147 = (float)((float)(0.0 * v184) - (float)(v173 * vars0)) / v146;
    if ( v147 >= -0.0000099999997 && v147 <= v112 )
    {
      v148 = (float)(v147 * v129) + toUV.M[1][0];
      v149 = (float)(v147 * v130) + v107;
      Scaleform::Render::Scale9GridTess::addVertices(
        this,
        &ver,
        &toUV,
        v148,
        v149,
        ((float)(v148 + *(float *)&retaddr) > v42) | (2
                                                    * ((v149 > v46) | (2
                                                                     * ((2 * (v49 > v149)) | (v50 > (float)(v148 + *(float *)&retaddr)))))),
        ((float)(v148 - *(float *)&retaddr) > v42) | (2
                                                    * ((v149 > v46) | (2
                                                                     * ((2 * (v49 > v149)) | (v50 > (float)(v148 - *(float *)&retaddr)))))));
    }
  }
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, src, v50, v49, &toUV, 0, 4u, 0xCu, 8u);
  v150 = 1;
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, src, v42, v49, &toUV, 1u, 0, 8u, 9u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, src, v42, v46, &toUV, 3u, 2u, 0, 1u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, src, v50, v46, &toUV, 2u, 6u, 4u, 0);
  Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (*)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
    &ver,
    0i64,
    ver.Size,
    (unsigned __int8 (__fastcall *)(Scaleform::Render::Scale9GridTess::TmpVertexType *))BlendTreeDataBase::UIDSort);
  v151 = 0;
  Size = ver.Size;
  if ( ver.Size > 1 )
  {
    v153 = 1i64;
    Data = ver.Data;
    do
    {
      if ( Data[v153].AreaCode != Data[v151].AreaCode )
      {
        Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, v151, v150);
        v151 = v150;
        Data = ver.Data;
        Size = ver.Size;
      }
      v153 = ++v150;
    }
    while ( v150 < Size );
  }
  Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, v151, v150);
  for ( i = 0; i < this->VerCount; ++i )
    Scaleform::Render::Scale9GridTess::transformVertex(this, s9g, &this->Vertices[i]);
  if ( ver.Data != ver.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

