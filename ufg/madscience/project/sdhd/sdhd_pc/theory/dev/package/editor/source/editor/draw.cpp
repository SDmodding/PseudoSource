// File Line: 39
// RVA: 0x206AD0
bool __fastcall UFG::Editor::DrawInterface::CullPointCloudWithFrustum(UFG::Editor::DrawInterface *this, UFG::qVector3 *points, int count, UFG::qMatrix44 *modelMat)
{
  UFG::qMatrix44 *v4; // rbx
  UFG::Editor::DrawInterface *v5; // rdi
  UFG::Editor::View *v7; // rax
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  UFG::qMatrix44 *v13; // rbx
  UFG::BaseCameraComponent *v14; // rax
  signed __int64 v15; // rax
  UFG::BaseCameraComponent *v16; // rcx
  UFG::qMatrix44 *v17; // rax
  float v18; // xmm1_4
  UFG::Editor::Camera *v19; // rcx
  float v20; // xmm0_4
  float v21; // ST2C_4
  float v22; // xmm13_4
  float v23; // xmm3_4
  __m128 v24; // xmm0
  float v25; // xmm7_4
  float v26; // xmm10_4
  __m128 v27; // xmm5
  float v28; // ST24_4
  float v29; // xmm2_4
  float v30; // xmm11_4
  float v31; // xmm8_4
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm9_4
  float v35; // xmm1_4
  float v36; // xmm14_4
  float v37; // xmm15_4
  float v38; // ST28_4
  float v39; // ST30_4
  float v40; // xmm2_4
  __m128 v41; // xmm12
  float v42; // xmm3_4
  float v43; // xmm1_4
  __m128 v44; // xmm0
  float v45; // ST20_4
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm0
  int v50; // xmm3_4
  int v51; // ST24_4
  int v52; // xmm8_4
  unsigned int v53; // ST28_4
  int v54; // xmm7_4
  int v55; // xmm13_4
  int v56; // xmm11_4
  int v57; // ST30_4
  int v58; // xmm10_4
  int v59; // xmm15_4
  float v60; // xmm8_4
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  float v63; // xmm4_4
  float radius; // [rsp+34h] [rbp-CCh]
  UFG::qVector3 center; // [rsp+38h] [rbp-C8h]
  __m128 v66; // [rsp+50h] [rbp-B0h]
  int v67; // [rsp+60h] [rbp-A0h]
  __m128 v68; // [rsp+70h] [rbp-90h]
  __m128 v69; // [rsp+80h] [rbp-80h]
  __m128 v70; // [rsp+90h] [rbp-70h]
  __m128 v71; // [rsp+A0h] [rbp-60h]
  __m128 v72; // [rsp+B0h] [rbp-50h]
  __m128 v73; // [rsp+C0h] [rbp-40h]
  __m128 v74; // [rsp+D0h] [rbp-30h]
  __m128 v75; // [rsp+E0h] [rbp-20h]
  __m128 v76; // [rsp+F0h] [rbp-10h]
  UFG::qVector4 planes; // [rsp+100h] [rbp+0h]
  int v78; // [rsp+110h] [rbp+10h]
  float v79; // [rsp+114h] [rbp+14h]
  float v80; // [rsp+118h] [rbp+18h]
  float v81; // [rsp+11Ch] [rbp+1Ch]
  float v82; // [rsp+120h] [rbp+20h]
  float v83; // [rsp+124h] [rbp+24h]
  float v84; // [rsp+128h] [rbp+28h]
  float v85; // [rsp+12Ch] [rbp+2Ch]
  float v86; // [rsp+130h] [rbp+30h]
  float v87; // [rsp+134h] [rbp+34h]
  float v88; // [rsp+138h] [rbp+38h]
  float v89; // [rsp+13Ch] [rbp+3Ch]
  float v90; // [rsp+140h] [rbp+40h]
  float v91; // [rsp+144h] [rbp+44h]
  float v92; // [rsp+148h] [rbp+48h]
  float v93; // [rsp+14Ch] [rbp+4Ch]
  float v94; // [rsp+150h] [rbp+50h]
  float v95; // [rsp+154h] [rbp+54h]
  float v96; // [rsp+158h] [rbp+58h]
  float v97; // [rsp+15Ch] [rbp+5Ch]
  __m128 v98; // [rsp+160h] [rbp+60h]
  UFG::qMatrix44 result; // [rsp+170h] [rbp+70h]

  v4 = modelMat;
  v5 = this;
  UFG::Editor::Utility::FindMinimalBoundingSphere(&center, &radius, points, count);
  if ( radius <= 0.0 )
    return 1;
  v7 = v5->mView;
  v8 = center.y * v4->v1.z;
  v9 = center.y * v4->v1.y;
  v10 = center.x * v4->v0.y;
  v11 = center.x * v4->v0.z;
  center.x = (float)((float)((float)(center.y * v4->v1.x) + (float)(center.x * v4->v0.x)) + (float)(center.z * v4->v2.x))
           + v4->v3.x;
  v12 = (float)((float)(v8 + v11) + (float)(center.z * v4->v2.z)) + v4->v3.z;
  center.y = (float)((float)(v9 + v10) + (float)(center.z * v4->v2.y)) + v4->v3.y;
  center.z = v12;
  v13 = (UFG::qMatrix44 *)v7->mCamera;
  v14 = UFG::Director::Get()->mCurrentCamera;
  if ( v14 && (v15 = (signed __int64)&v14->mCamera) != 0 && !*(_BYTE *)(v15 + 256) )
  {
    v16 = UFG::Director::Get()->mCurrentCamera;
    if ( v16 )
      v17 = UFG::Camera::GetViewProjection(&v16->mCamera);
    else
      v17 = UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    v17 = v13 + 3;
  }
  v18 = v17->v0.y;
  v19 = v5->mView->mCamera;
  v72.m128_i32[0] = LODWORD(v17->v0.x);
  *(unsigned __int64 *)((char *)v72.m128_u64 + 4) = __PAIR__(LODWORD(v17->v0.z), LODWORD(v18));
  v20 = v17->v1.x;
  v72.m128_i32[3] = LODWORD(v17->v0.w);
  v73.m128_u64[0] = __PAIR__(LODWORD(v17->v1.y), LODWORD(v20));
  v73.m128_u64[1] = *(_QWORD *)&v17->v1.z;
  v74 = (__m128)v17->v2;
  v75 = (__m128)v17->v3;
  UFG::Editor::Camera::GetMatView(v19, &result);
  v71 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 0), v72), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 85), v73)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 170), v74)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 255), v75));
  v76 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 255), v75),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 0), v72), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 85), v73)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 170), v74)));
  v98 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 0), v72), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 85), v73)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 170), v74)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 255), v75));
  v69 = _mm_shuffle_ps(v71, v71, 255);
  v21 = v71.m128_f32[0] + v69.m128_f32[0];
  v22 = v69.m128_f32[0] - v71.m128_f32[0];
  LODWORD(v23) = (unsigned __int128)_mm_shuffle_ps(v71, v71, 85);
  v24 = _mm_shuffle_ps(v98, v98, 255);
  v25 = v98.m128_f32[0] + v24.m128_f32[0];
  v66 = v24;
  v68 = _mm_shuffle_ps(v76, v76, 255);
  v26 = v24.m128_f32[0] - v98.m128_f32[0];
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 0), v72), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 85), v73)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 170), v74)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 255), v75));
  v28 = v23 + v69.m128_f32[0];
  LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps(v76, v76, 85);
  v30 = v68.m128_f32[0] - v76.m128_f32[0];
  v31 = v76.m128_f32[0] + v68.m128_f32[0];
  v24.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v27, v27, 85);
  v70 = _mm_shuffle_ps(v27, v27, 255);
  v32 = v29 + v68.m128_f32[0];
  v33 = v27.m128_f32[0] + v70.m128_f32[0];
  v34 = v70.m128_f32[0] - v27.m128_f32[0];
  LODWORD(v35) = (unsigned __int128)_mm_shuffle_ps(v98, v98, 85);
  v36 = v24.m128_f32[0] + v70.m128_f32[0];
  v37 = v35 + v66.m128_f32[0];
  v38 = v69.m128_f32[0] - v23;
  v39 = v68.m128_f32[0] - v29;
  v40 = v66.m128_f32[0] - v35;
  v27.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v27, v27, 170);
  v41 = _mm_shuffle_ps(v71, v71, 170);
  LODWORD(v42) = (unsigned __int128)_mm_shuffle_ps(v98, v98, 170);
  v43 = v70.m128_f32[0] - v24.m128_f32[0];
  v44 = v69;
  v45 = v43;
  v44.m128_f32[0] = v69.m128_f32[0] - v41.m128_f32[0];
  v69 = v44;
  v46 = v68;
  v47 = _mm_shuffle_ps(v76, v76, 170);
  v46.m128_f32[0] = v68.m128_f32[0] - v47.m128_f32[0];
  v68 = v46;
  v48 = v66;
  v48.m128_f32[0] = v66.m128_f32[0] - v42;
  v66 = v48;
  v49 = v70;
  v49.m128_f32[0] = v70.m128_f32[0] - v27.m128_f32[0];
  v76 = _mm_xor_ps(v47, (__m128)(unsigned int)_xmm[0]);
  v67 = LODWORD(v40) ^ _xmm[0];
  v50 = LODWORD(v42) ^ _xmm[0];
  v51 = LODWORD(v28) ^ _xmm[0];
  v71 = _mm_xor_ps(v41, (__m128)(unsigned int)_xmm[0]);
  v52 = LODWORD(v31) ^ _xmm[0];
  v53 = LODWORD(v38) ^ _xmm[0];
  v54 = LODWORD(v25) ^ _xmm[0];
  v55 = LODWORD(v22) ^ _xmm[0];
  v56 = LODWORD(v30) ^ _xmm[0];
  v57 = LODWORD(v39) ^ _xmm[0];
  v58 = LODWORD(v26) ^ _xmm[0];
  v59 = LODWORD(v37) ^ _xmm[0];
  v69 = _mm_xor_ps(v69, (__m128)(unsigned int)_xmm[0]);
  v68 = _mm_xor_ps(v68, (__m128)(unsigned int)_xmm[0]);
  v66 = _mm_xor_ps(v66, (__m128)(unsigned int)_xmm[0]);
  v70 = _mm_xor_ps(v49, (__m128)(unsigned int)_xmm[0]);
  v49.m128_f32[0] = fsqrt(
                      (float)((float)(v76.m128_f32[0] * v76.m128_f32[0]) + (float)(v71.m128_f32[0] * v71.m128_f32[0]))
                    + (float)(*(float *)&v50 * *(float *)&v50));
  planes.x = v71.m128_f32[0] * (float)(1.0 / v49.m128_f32[0]);
  planes.y = v76.m128_f32[0] * (float)(1.0 / v49.m128_f32[0]);
  planes.z = *(float *)&v50 * (float)(1.0 / v49.m128_f32[0]);
  planes.w = COERCE_FLOAT(v27.m128_i32[0] ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v49.m128_f32[0] = fsqrt(
                      (float)((float)(*(float *)&v52 * *(float *)&v52)
                            + (float)(COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0])))
                    + (float)(*(float *)&v54 * *(float *)&v54));
  v81 = COERCE_FLOAT(LODWORD(v33) ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v41.m128_f32[0] = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v60 = *(float *)&v52 * (float)(1.0 / v49.m128_f32[0]);
  v80 = *(float *)&v54 * (float)(1.0 / v49.m128_f32[0]);
  v49.m128_f32[0] = fsqrt(
                      (float)((float)(*(float *)&v56 * *(float *)&v56) + (float)(*(float *)&v55 * *(float *)&v55))
                    + (float)(*(float *)&v58 * *(float *)&v58));
  v78 = v41.m128_i32[0];
  v79 = v60;
  v61 = (__m128)(unsigned int)(LODWORD(v32) ^ _xmm[0]);
  v82 = *(float *)&v55 * (float)(1.0 / v49.m128_f32[0]);
  v83 = *(float *)&v56 * (float)(1.0 / v49.m128_f32[0]);
  v61.m128_f32[0] = (float)((float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(*(float *)&v51 * *(float *)&v51))
                  + (float)(*(float *)&v59 * *(float *)&v59);
  v84 = *(float *)&v58 * (float)(1.0 / v49.m128_f32[0]);
  v85 = COERCE_FLOAT(LODWORD(v34) ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v49.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v61);
  v62 = (__m128)v53;
  v87 = COERCE_FLOAT(LODWORD(v32) ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v86 = *(float *)&v51 * (float)(1.0 / v49.m128_f32[0]);
  v88 = *(float *)&v59 * (float)(1.0 / v49.m128_f32[0]);
  v89 = COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]) * (float)(1.0 / v49.m128_f32[0]);
  v62.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(*(float *)&v57 * *(float *)&v57))
                  + (float)(*(float *)&v67 * *(float *)&v67);
  v49.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v62);
  v90 = *(float *)&v53 * (float)(1.0 / v49.m128_f32[0]);
  v92 = (float)(1.0 / v49.m128_f32[0]) * *(float *)&v67;
  v91 = (float)(1.0 / v49.m128_f32[0]) * *(float *)&v57;
  v93 = (float)(1.0 / v49.m128_f32[0]) * COERCE_FLOAT(LODWORD(v45) ^ _xmm[0]);
  v63 = 1.0
      / fsqrt(
          (float)((float)(v68.m128_f32[0] * v68.m128_f32[0]) + (float)(v69.m128_f32[0] * v69.m128_f32[0]))
        + (float)(v66.m128_f32[0] * v66.m128_f32[0]));
  v97 = v63 * v70.m128_f32[0];
  v94 = v63 * v69.m128_f32[0];
  v95 = v63 * v68.m128_f32[0];
  v96 = v63 * v66.m128_f32[0];
  return IntersectSphereFrustum(&planes, &center, radius) == 2;
}

// File Line: 121
// RVA: 0x208C70
void __fastcall UFG::Editor::DrawRenderI::Draw(UFG::Editor::DrawRenderI *this, UFG::Editor::DrawInterface::PrimMode mode, unsigned int vertDataFormat, void *data, int count, UFG::qMatrix44 *modelMat)
{
  UFG::qVector3 *v6; // rbx
  UFG::Editor::DrawInterface::PrimMode v7; // esi
  UFG::Editor::DrawRenderI *v8; // rdi
  Render::DebugDrawContext *v9; // r14
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::Editor::DrawInterface::BlendMode v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  int v18; // ecx
  bool v19; // al
  int v20; // esi
  __int64 v21; // rdi
  UFG::DrawInfo info; // [rsp+30h] [rbp-58h]

  v6 = (UFG::qVector3 *)data;
  v7 = mode;
  v8 = this;
  if ( this->mOverlay == 1 )
    v9 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  else
    v9 = this->mView->mDrawCtx;
  v10 = v8->mColour.r;
  v11 = v8->mColour.g;
  v12 = v8->mBlendMode;
  info.mAlphaBlend = 662883558;
  info.mColour1.r = v10;
  v13 = v8->mColour.b;
  info.mColour1.g = v11;
  v14 = v8->mColour.a;
  info.mColour1.b = v13;
  info.mColour2.r = v8->mColour.r;
  v15 = v8->mColour.b;
  info.mColour1.a = v14;
  v16 = v8->mColour.g;
  info.mColour2.b = v15;
  info.mColour2.g = v16;
  v17 = v8->mColour.a;
  LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
  info.mColour2.a = v17;
  if ( v12 )
  {
    v18 = v12 - 1;
    if ( v18 )
    {
      if ( v18 == 1 )
        info.mAlphaBlend = 1775952593;
    }
    else
    {
      info.mAlphaBlend = -1551679522;
    }
  }
  else
  {
    info.mAlphaBlend = 662883558;
  }
  info.mFaceCull = v8->mBackfaceCull;
  info.mDepthBuffer = v8->mDepthTest;
  v19 = v8->mDepthBias;
  info.mPreDrawCallback = 0i64;
  info.mDepthBias = v19;
  if ( !UFG::Editor::DrawInterface::CullPointCloudWithFrustum(
          (UFG::Editor::DrawInterface *)&v8->vfptr,
          v6,
          count,
          modelMat) )
  {
    if ( v7 )
    {
      v20 = v7 - 1;
      if ( v20 )
      {
        if ( v20 == 2 )
          Render::DebugDrawContext::DrawTriStrip(v9, v6, count, &info, modelMat, 0);
      }
      else
      {
        Render::DebugDrawContext::DrawLineStrip(v9, v6, count, &info, modelMat);
      }
    }
    else if ( count >> 1 > 0 )
    {
      v21 = (unsigned int)(count >> 1);
      do
      {
        Render::DebugDrawContext::DrawLineStrip(v9, v6, 2, &info, modelMat);
        v6 += 2;
        --v21;
      }
      while ( v21 );
    }
  }
}

// File Line: 160
// RVA: 0x208E20
void __fastcall UFG::Editor::DrawRenderI::DrawNDC(UFG::Editor::DrawRenderI *this, UFG::Editor::DrawInterface::PrimMode mode, unsigned int vertDataFormat, void *data, int count, UFG::qMatrix44 *mvp)
{
  UFG::Editor::DrawRenderI *v6; // rbx
  Render::DebugDrawContext *v7; // r14
  __int64 v8; // rsi
  float *v9; // rbp
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  Render::DebugDrawContext *v13; // rax
  float v14; // xmm6_4
  float v15; // xmm13_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm13_4
  float v23; // xmm12_4
  __m128i v24; // xmm0
  __m128i v25; // xmm2
  float v26; // xmm4_4
  float v27; // xmm1_4
  UFG::qVector3 p1; // [rsp+40h] [rbp-E8h]
  UFG::qVector3 p0; // [rsp+4Ch] [rbp-DCh]
  float v30; // [rsp+130h] [rbp+8h]
  float v31; // [rsp+138h] [rbp+10h]

  if ( mode == 1 )
  {
    v6 = this;
    v7 = this->mView->mDrawCtx;
    v8 = count - 1;
    if ( count - 1 > 0 )
    {
      v9 = (float *)((char *)data + 20);
      do
      {
        v10 = *(v9 - 5);
        v11 = *(v9 - 4);
        v12 = *(v9 - 3);
        v13 = v6->mView->mDrawCtx;
        v14 = mvp->v1.w;
        v15 = mvp->v0.w;
        v16 = mvp->v2.w;
        v30 = (float)((float)((float)(mvp->v0.y * v10) + (float)(mvp->v1.y * v11)) + (float)(mvp->v2.y * v12))
            + mvp->v3.y;
        v17 = *(v9 - 2);
        v18 = 1.0 / (float)((float)((float)((float)(v15 * v10) + (float)(v14 * v11)) + (float)(v16 * v12)) + mvp->v3.w);
        v19 = *(v9 - 1);
        v20 = (float)((float)((float)((float)(mvp->v0.x * v10) + (float)(mvp->v1.x * v11)) + (float)(mvp->v2.x * v12))
                    + mvp->v3.x)
            * v18;
        v21 = v30 * v18;
        v22 = (float)((float)((float)(v15 * v17) + (float)(v14 * v19)) + (float)(v16 * *v9)) + mvp->v3.w;
        v23 = (float)((float)((float)((float)(mvp->v0.y * v17) + (float)(mvp->v1.y * v19)) + (float)(mvp->v2.y * *v9))
                    + mvp->v3.y)
            * (float)(1.0 / v22);
        v31 = (float)((float)((float)((float)(mvp->v0.x * v17) + (float)(mvp->v1.x * v19)) + (float)(mvp->v2.x * *v9))
                    + mvp->v3.x)
            * (float)(1.0 / v22);
        v24 = _mm_cvtsi32_si128(v13->mTargetHeight);
        v25 = _mm_cvtsi32_si128(v13->mTargetWidth);
        v26 = (float)((float)v6->mView->mDrawCtx->mTargetWidth * (float)(v20 + 1.0)) * 0.5;
        p1.z = 0.0;
        p0.z = 0.0;
        v27 = (float)(signed int)(float)((float)(1.0 - (float)((float)(v23 + 1.0) * 0.5)) * (float)v13->mTargetHeight);
        p1.x = (float)(signed int)(float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v25)) * (float)(v31 + 1.0)) * 0.5);
        p1.y = v27;
        p0.x = (float)(signed int)v26;
        p0.y = (float)(signed int)(float)((float)(1.0 - (float)((float)(v21 + 1.0) * 0.5))
                                        * COERCE_FLOAT(_mm_cvtepi32_ps(v24)));
        Render::DebugDrawContext::DrawLine(v7, &p0, &p1, &v6->mColour, 0i64, 0i64, 1);
        v9 += 3;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 197
// RVA: 0x2091C0
void __fastcall UFG::Editor::DrawRenderI::DrawSCR(UFG::Editor::DrawRenderI *this, UFG::Editor::DrawInterface::PrimMode mode, unsigned int vertDataFormat, void *data, int count)
{
  UFG::Editor::View *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4
  UFG::qColour *v8; // rsi
  UFG::Editor::DrawRenderI *v9; // r8
  UFG::Editor::DrawInterface::BlendMode v10; // ecx
  Render::DebugDrawContext *v11; // r14
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // ecx
  bool v18; // al
  __int32 v19; // edx
  __int64 v20; // rdi
  float *v21; // rbx
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  __m128i v25; // xmm1
  UFG::qVector3 p1; // [rsp+40h] [rbp-11h]
  UFG::qVector3 p0; // [rsp+4Ch] [rbp-5h]
  UFG::DrawInfo info; // [rsp+58h] [rbp+7h]

  v5 = this->mView;
  v6 = this->mColour.r;
  v7 = this->mColour.g;
  v8 = &this->mColour;
  v9 = this;
  v10 = this->mBlendMode;
  v11 = v5->mDrawCtx;
  info.mAlphaBlend = 662883558;
  info.mColour1.r = v6;
  v12 = v8->b;
  info.mColour1.g = v7;
  v13 = v8->a;
  info.mColour1.b = v12;
  info.mColour2.r = v8->r;
  v14 = v8->b;
  info.mColour1.a = v13;
  v15 = v8->g;
  info.mColour2.b = v14;
  info.mColour2.g = v15;
  v16 = v8->a;
  LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
  info.mColour2.a = v16;
  if ( v10 )
  {
    v17 = v10 - 1;
    if ( v17 )
    {
      if ( v17 == 1 )
        info.mAlphaBlend = 1775952593;
    }
    else
    {
      info.mAlphaBlend = -1551679522;
    }
  }
  else
  {
    info.mAlphaBlend = 662883558;
  }
  info.mFaceCull = v9->mBackfaceCull;
  v18 = v9->mDepthTest;
  info.mPreDrawCallback = 0i64;
  info.mDepthBuffer = v18;
  info.mDepthBias = v9->mDepthBias;
  v19 = mode - 1;
  if ( v19 )
  {
    if ( v19 == 2 )
      Render::DebugDrawContext::DrawTriStrip(v11, (UFG::qVector3 *)data, count, &info, 0i64, 1);
  }
  else
  {
    v20 = count - 1;
    if ( count - 1 > 0 )
    {
      v21 = (float *)((char *)data + 4);
      do
      {
        v22 = v21[2];
        v23 = *(v21 - 1);
        v24 = *v21;
        v21 += 3;
        p1.z = 0.0;
        p0.z = 0.0;
        v25 = _mm_cvtsi32_si128((signed int)*v21);
        p1.x = (float)(signed int)v22;
        LODWORD(p1.y) = (unsigned __int128)_mm_cvtepi32_ps(v25);
        p0.x = (float)(signed int)v23;
        p0.y = (float)(signed int)v24;
        Render::DebugDrawContext::DrawLine(v11, &p0, &p1, v8, 0i64, 0i64, 1);
        --v20;
      }
      while ( v20 );
    }
  }
}

