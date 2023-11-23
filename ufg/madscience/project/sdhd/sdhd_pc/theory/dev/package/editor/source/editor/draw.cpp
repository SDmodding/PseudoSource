// File Line: 39
// RVA: 0x206AD0
bool __fastcall UFG::Editor::DrawInterface::CullPointCloudWithFrustum(
        UFG::Editor::DrawInterface *this,
        UFG::qVector3 *points,
        int count,
        UFG::qMatrix44 *modelMat)
{
  UFG::Editor::View *mView; // rax
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  UFG::Editor::Camera *mCamera; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v16; // rcx
  __m128 *ViewProjection; // rax
  int v18; // xmm1_4
  UFG::Editor::Camera *v19; // rcx
  int v20; // xmm0_4
  float v21; // xmm13_4
  float v22; // xmm3_4
  __m128 v23; // xmm0
  float v24; // xmm7_4
  float v25; // xmm10_4
  __m128 v26; // xmm5
  float v27; // xmm2_4
  float v28; // xmm11_4
  float v29; // xmm8_4
  float v30; // xmm4_4
  float v31; // xmm6_4
  float v32; // xmm9_4
  float v33; // xmm1_4
  float v34; // xmm14_4
  float v35; // xmm15_4
  float v36; // xmm2_4
  __m128 v37; // xmm12
  float v38; // xmm3_4
  float v39; // xmm1_4
  __m128 v40; // xmm0
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm0
  int v45; // xmm3_4
  int v46; // xmm8_4
  int v47; // xmm7_4
  int v48; // xmm13_4
  int v49; // xmm11_4
  int v50; // xmm10_4
  int v51; // xmm15_4
  float v52; // xmm8_4
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  float v55; // xmm4_4
  float v56; // [rsp+20h] [rbp-E0h]
  float v57; // [rsp+24h] [rbp-DCh]
  int v58; // [rsp+24h] [rbp-DCh]
  float v59; // [rsp+28h] [rbp-D8h]
  unsigned int v60; // [rsp+28h] [rbp-D8h]
  float v61; // [rsp+2Ch] [rbp-D4h]
  float v62; // [rsp+30h] [rbp-D0h]
  int v63; // [rsp+30h] [rbp-D0h]
  float radius; // [rsp+34h] [rbp-CCh] BYREF
  UFG::qVector3 center; // [rsp+38h] [rbp-C8h] BYREF
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
  UFG::qVector4 planes; // [rsp+100h] [rbp+0h] BYREF
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
  UFG::qMatrix44 result; // [rsp+170h] [rbp+70h] BYREF

  UFG::Editor::Utility::FindMinimalBoundingSphere(&center, &radius, points, count);
  if ( radius <= 0.0 )
    return 1;
  mView = this->mView;
  v8 = center.y * modelMat->v1.z;
  v9 = center.y * modelMat->v1.y;
  v10 = center.x * modelMat->v0.y;
  v11 = center.x * modelMat->v0.z;
  center.x = (float)((float)((float)(center.y * modelMat->v1.x) + (float)(center.x * modelMat->v0.x))
                   + (float)(center.z * modelMat->v2.x))
           + modelMat->v3.x;
  v12 = (float)((float)(v8 + v11) + (float)(center.z * modelMat->v2.z)) + modelMat->v3.z;
  center.y = (float)((float)(v9 + v10) + (float)(center.z * modelMat->v2.y)) + modelMat->v3.y;
  center.z = v12;
  mCamera = mView->mCamera;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v16 = UFG::Director::Get()->mCurrentCamera;
    if ( v16 )
      ViewProjection = (__m128 *)UFG::Camera::GetViewProjection(&v16->mCamera);
    else
      ViewProjection = (__m128 *)UFG::Camera::GetViewProjection(0i64);
  }
  else
  {
    ViewProjection = (__m128 *)&mCamera->mProj;
  }
  v18 = ViewProjection->m128_i32[1];
  v19 = this->mView->mCamera;
  v72.m128_i32[0] = ViewProjection->m128_i32[0];
  *(unsigned __int64 *)((char *)v72.m128_u64 + 4) = __PAIR64__(ViewProjection->m128_i32[2], v18);
  v20 = ViewProjection[1].m128_i32[0];
  v72.m128_i32[3] = ViewProjection->m128_i32[3];
  v73.m128_u64[0] = __PAIR64__(ViewProjection[1].m128_i32[1], v20);
  v73.m128_u64[1] = ViewProjection[1].m128_u64[1];
  v74 = ViewProjection[2];
  v75 = ViewProjection[3];
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
  v61 = v71.m128_f32[0] + v69.m128_f32[0];
  v21 = v69.m128_f32[0] - v71.m128_f32[0];
  v22 = _mm_shuffle_ps(v71, v71, 85).m128_f32[0];
  v23 = _mm_shuffle_ps(v98, v98, 255);
  v24 = v98.m128_f32[0] + v23.m128_f32[0];
  v66 = v23;
  v68 = _mm_shuffle_ps(v76, v76, 255);
  v25 = v23.m128_f32[0] - v98.m128_f32[0];
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 0), v72), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 85), v73)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 170), v74)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 255), v75));
  v57 = v22 + v69.m128_f32[0];
  v27 = _mm_shuffle_ps(v76, v76, 85).m128_f32[0];
  v28 = v68.m128_f32[0] - v76.m128_f32[0];
  v29 = v76.m128_f32[0] + v68.m128_f32[0];
  v23.m128_f32[0] = _mm_shuffle_ps(v26, v26, 85).m128_f32[0];
  v70 = _mm_shuffle_ps(v26, v26, 255);
  v30 = v27 + v68.m128_f32[0];
  v31 = v26.m128_f32[0] + v70.m128_f32[0];
  v32 = v70.m128_f32[0] - v26.m128_f32[0];
  v33 = _mm_shuffle_ps(v98, v98, 85).m128_f32[0];
  v34 = v23.m128_f32[0] + v70.m128_f32[0];
  v35 = v33 + v66.m128_f32[0];
  v59 = v69.m128_f32[0] - v22;
  v62 = v68.m128_f32[0] - v27;
  v36 = v66.m128_f32[0] - v33;
  v26.m128_f32[0] = _mm_shuffle_ps(v26, v26, 170).m128_f32[0];
  v37 = _mm_shuffle_ps(v71, v71, 170);
  v38 = _mm_shuffle_ps(v98, v98, 170).m128_f32[0];
  v39 = v70.m128_f32[0] - v23.m128_f32[0];
  v40 = v69;
  v56 = v39;
  v40.m128_f32[0] = v69.m128_f32[0] - v37.m128_f32[0];
  v69 = v40;
  v41 = v68;
  v42 = _mm_shuffle_ps(v76, v76, 170);
  v41.m128_f32[0] = v68.m128_f32[0] - v42.m128_f32[0];
  v68 = v41;
  v43 = v66;
  v43.m128_f32[0] = v66.m128_f32[0] - v38;
  v66 = v43;
  v44 = v70;
  v44.m128_f32[0] = v70.m128_f32[0] - v26.m128_f32[0];
  v76 = _mm_xor_ps(v42, (__m128)(unsigned int)_xmm[0]);
  v67 = LODWORD(v36) ^ _xmm[0];
  v45 = LODWORD(v38) ^ _xmm[0];
  v58 = LODWORD(v57) ^ _xmm[0];
  v71 = _mm_xor_ps(v37, (__m128)(unsigned int)_xmm[0]);
  v46 = LODWORD(v29) ^ _xmm[0];
  v60 = LODWORD(v59) ^ _xmm[0];
  v47 = LODWORD(v24) ^ _xmm[0];
  v48 = LODWORD(v21) ^ _xmm[0];
  v49 = LODWORD(v28) ^ _xmm[0];
  v63 = LODWORD(v62) ^ _xmm[0];
  v50 = LODWORD(v25) ^ _xmm[0];
  v51 = LODWORD(v35) ^ _xmm[0];
  v69 = _mm_xor_ps(v69, (__m128)(unsigned int)_xmm[0]);
  v68 = _mm_xor_ps(v68, (__m128)(unsigned int)_xmm[0]);
  v66 = _mm_xor_ps(v66, (__m128)(unsigned int)_xmm[0]);
  v70 = _mm_xor_ps(v44, (__m128)(unsigned int)_xmm[0]);
  v44.m128_f32[0] = fsqrt(
                      (float)((float)(v76.m128_f32[0] * v76.m128_f32[0]) + (float)(v71.m128_f32[0] * v71.m128_f32[0]))
                    + (float)(*(float *)&v45 * *(float *)&v45));
  planes.x = v71.m128_f32[0] * (float)(1.0 / v44.m128_f32[0]);
  planes.y = v76.m128_f32[0] * (float)(1.0 / v44.m128_f32[0]);
  planes.z = *(float *)&v45 * (float)(1.0 / v44.m128_f32[0]);
  planes.w = COERCE_FLOAT(v26.m128_i32[0] ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v44.m128_f32[0] = fsqrt(
                      (float)((float)(*(float *)&v46 * *(float *)&v46)
                            + (float)(COERCE_FLOAT(LODWORD(v61) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v61) ^ _xmm[0])))
                    + (float)(*(float *)&v47 * *(float *)&v47));
  v81 = COERCE_FLOAT(LODWORD(v31) ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v37.m128_f32[0] = COERCE_FLOAT(LODWORD(v61) ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v52 = *(float *)&v46 * (float)(1.0 / v44.m128_f32[0]);
  v80 = *(float *)&v47 * (float)(1.0 / v44.m128_f32[0]);
  v44.m128_f32[0] = fsqrt(
                      (float)((float)(*(float *)&v49 * *(float *)&v49) + (float)(*(float *)&v48 * *(float *)&v48))
                    + (float)(*(float *)&v50 * *(float *)&v50));
  v78 = v37.m128_i32[0];
  v79 = v52;
  v53 = (__m128)(unsigned int)(LODWORD(v30) ^ _xmm[0]);
  v82 = *(float *)&v48 * (float)(1.0 / v44.m128_f32[0]);
  v83 = *(float *)&v49 * (float)(1.0 / v44.m128_f32[0]);
  v53.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(*(float *)&v58 * *(float *)&v58))
                  + (float)(*(float *)&v51 * *(float *)&v51);
  v84 = *(float *)&v50 * (float)(1.0 / v44.m128_f32[0]);
  v85 = COERCE_FLOAT(LODWORD(v32) ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v44.m128_f32[0] = _mm_sqrt_ps(v53).m128_f32[0];
  v54 = (__m128)v60;
  v87 = COERCE_FLOAT(LODWORD(v30) ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v86 = *(float *)&v58 * (float)(1.0 / v44.m128_f32[0]);
  v88 = *(float *)&v51 * (float)(1.0 / v44.m128_f32[0]);
  v89 = COERCE_FLOAT(LODWORD(v34) ^ _xmm[0]) * (float)(1.0 / v44.m128_f32[0]);
  v54.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(*(float *)&v63 * *(float *)&v63))
                  + (float)(*(float *)&v67 * *(float *)&v67);
  v44.m128_f32[0] = _mm_sqrt_ps(v54).m128_f32[0];
  v90 = *(float *)&v60 * (float)(1.0 / v44.m128_f32[0]);
  v92 = (float)(1.0 / v44.m128_f32[0]) * *(float *)&v67;
  v91 = (float)(1.0 / v44.m128_f32[0]) * *(float *)&v63;
  v93 = (float)(1.0 / v44.m128_f32[0]) * COERCE_FLOAT(LODWORD(v56) ^ _xmm[0]);
  v55 = 1.0
      / fsqrt(
          (float)((float)(v68.m128_f32[0] * v68.m128_f32[0]) + (float)(v69.m128_f32[0] * v69.m128_f32[0]))
        + (float)(v66.m128_f32[0] * v66.m128_f32[0]));
  v97 = v55 * v70.m128_f32[0];
  v94 = v55 * v69.m128_f32[0];
  v95 = v55 * v68.m128_f32[0];
  v96 = v55 * v66.m128_f32[0];
  return IntersectSphereFrustum(&planes, &center, radius) == 2;
}

// File Line: 121
// RVA: 0x208C70
void __fastcall UFG::Editor::DrawRenderI::Draw(
        UFG::Editor::DrawRenderI *this,
        UFG::Editor::DrawInterface::PrimMode mode,
        unsigned int vertDataFormat,
        UFG::qVector3 *data,
        int count,
        UFG::qMatrix44 *modelMat)
{
  Render::DebugDrawContext *Context; // r14
  float r; // xmm0_4
  float g; // xmm1_4
  UFG::Editor::DrawInterface::BlendMode mBlendMode; // ecx
  float b; // xmm0_4
  float a; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  __int32 v18; // ecx
  bool mDepthBias; // al
  int v20; // esi
  __int64 v21; // rdi
  UFG::DrawInfo info; // [rsp+30h] [rbp-58h] BYREF

  if ( this->mOverlay )
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  else
    Context = this->mView->mDrawCtx;
  r = this->mColour.r;
  g = this->mColour.g;
  mBlendMode = this->mBlendMode;
  info.mAlphaBlend = AlphaState_none;
  info.mColour1.r = r;
  b = this->mColour.b;
  info.mColour1.g = g;
  a = this->mColour.a;
  info.mColour1.b = b;
  info.mColour2.r = this->mColour.r;
  v15 = this->mColour.b;
  info.mColour1.a = a;
  v16 = this->mColour.g;
  info.mColour2.b = v15;
  info.mColour2.g = v16;
  v17 = this->mColour.a;
  LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
  info.mColour2.a = v17;
  if ( mBlendMode )
  {
    v18 = mBlendMode - 1;
    if ( v18 )
    {
      if ( v18 == 1 )
        info.mAlphaBlend = AlphaState_additive;
    }
    else
    {
      info.mAlphaBlend = AlphaState_modulated;
    }
  }
  else
  {
    info.mAlphaBlend = AlphaState_none;
  }
  info.mFaceCull = this->mBackfaceCull;
  info.mDepthBuffer = this->mDepthTest;
  mDepthBias = this->mDepthBias;
  info.mPreDrawCallback = 0i64;
  info.mDepthBias = mDepthBias;
  if ( !UFG::Editor::DrawInterface::CullPointCloudWithFrustum(this, data, count, modelMat) )
  {
    if ( mode )
    {
      v20 = mode - 1;
      if ( v20 )
      {
        if ( v20 == 2 )
          Render::DebugDrawContext::DrawTriStrip(Context, data, count, &info, modelMat, 0);
      }
      else
      {
        Render::DebugDrawContext::DrawLineStrip(Context, data, count, &info, modelMat);
      }
    }
    else if ( count >> 1 > 0 )
    {
      v21 = (unsigned int)(count >> 1);
      do
      {
        Render::DebugDrawContext::DrawLineStrip(Context, data, 2, &info, modelMat);
        data += 2;
        --v21;
      }
      while ( v21 );
    }
  }
}

// File Line: 160
// RVA: 0x208E20
void __fastcall UFG::Editor::DrawRenderI::DrawNDC(
        UFG::Editor::DrawRenderI *this,
        UFG::Editor::DrawInterface::PrimMode mode,
        unsigned int vertDataFormat,
        char *data,
        int count,
        UFG::qMatrix44 *mvp)
{
  Render::DebugDrawContext *mDrawCtx; // r14
  __int64 v8; // rsi
  float *v9; // rbp
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  Render::DebugDrawContext *v13; // rax
  float w; // xmm6_4
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
  UFG::qVector3 p1; // [rsp+40h] [rbp-E8h] BYREF
  UFG::qVector3 p0; // [rsp+4Ch] [rbp-DCh] BYREF
  float v30; // [rsp+130h] [rbp+8h]
  float v31; // [rsp+138h] [rbp+10h]

  if ( mode == PrimMode_LineStrip )
  {
    mDrawCtx = this->mView->mDrawCtx;
    v8 = count - 1;
    if ( count - 1 > 0 )
    {
      v9 = (float *)(data + 20);
      do
      {
        v10 = *(v9 - 5);
        v11 = *(v9 - 4);
        v12 = *(v9 - 3);
        v13 = this->mView->mDrawCtx;
        w = mvp->v1.w;
        v15 = mvp->v0.w;
        v16 = mvp->v2.w;
        v30 = (float)((float)((float)(mvp->v0.y * v10) + (float)(mvp->v1.y * v11)) + (float)(mvp->v2.y * v12))
            + mvp->v3.y;
        v17 = *(v9 - 2);
        v18 = 1.0 / (float)((float)((float)((float)(v15 * v10) + (float)(w * v11)) + (float)(v16 * v12)) + mvp->v3.w);
        v19 = *(v9 - 1);
        v20 = (float)((float)((float)((float)(mvp->v0.x * v10) + (float)(mvp->v1.x * v11)) + (float)(mvp->v2.x * v12))
                    + mvp->v3.x)
            * v18;
        v21 = v30 * v18;
        v22 = (float)((float)((float)(v15 * v17) + (float)(w * v19)) + (float)(v16 * *v9)) + mvp->v3.w;
        v23 = (float)((float)((float)((float)(mvp->v0.y * v17) + (float)(mvp->v1.y * v19)) + (float)(mvp->v2.y * *v9))
                    + mvp->v3.y)
            * (float)(1.0 / v22);
        v31 = (float)((float)((float)((float)(mvp->v0.x * v17) + (float)(mvp->v1.x * v19)) + (float)(mvp->v2.x * *v9))
                    + mvp->v3.x)
            * (float)(1.0 / v22);
        v24 = _mm_cvtsi32_si128(v13->mTargetHeight);
        v25 = _mm_cvtsi32_si128(v13->mTargetWidth);
        v26 = (float)((float)v13->mTargetWidth * (float)(v20 + 1.0)) * 0.5;
        p1.z = 0.0;
        p0.z = 0.0;
        v27 = (float)(int)(float)((float)(1.0 - (float)((float)(v23 + 1.0) * 0.5)) * (float)v13->mTargetHeight);
        p1.x = (float)(int)(float)((float)(_mm_cvtepi32_ps(v25).m128_f32[0] * (float)(v31 + 1.0)) * 0.5);
        p1.y = v27;
        p0.x = (float)(int)v26;
        p0.y = (float)(int)(float)((float)(1.0 - (float)((float)(v21 + 1.0) * 0.5)) * _mm_cvtepi32_ps(v24).m128_f32[0]);
        Render::DebugDrawContext::DrawLine(mDrawCtx, &p0, &p1, &this->mColour, 0i64, 0i64, 1);
        v9 += 3;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 197
// RVA: 0x2091C0
void __fastcall UFG::Editor::DrawRenderI::DrawSCR(
        UFG::Editor::DrawRenderI *this,
        UFG::Editor::DrawInterface::PrimMode mode,
        unsigned int vertDataFormat,
        UFG::qVector3 *data,
        int count)
{
  UFG::Editor::View *mView; // rax
  float r; // xmm0_4
  float g; // xmm1_4
  UFG::qColour *p_mColour; // rsi
  UFG::Editor::DrawInterface::BlendMode mBlendMode; // ecx
  Render::DebugDrawContext *mDrawCtx; // r14
  float b; // xmm0_4
  float a; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  __int32 v17; // ecx
  bool mDepthTest; // al
  int v19; // edx
  __int64 v20; // rdi
  float *p_y; // rbx
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  __m128i v25; // xmm1
  UFG::qVector3 p1; // [rsp+40h] [rbp-11h] BYREF
  UFG::qVector3 p0; // [rsp+4Ch] [rbp-5h] BYREF
  UFG::DrawInfo info; // [rsp+58h] [rbp+7h] BYREF

  mView = this->mView;
  r = this->mColour.r;
  g = this->mColour.g;
  p_mColour = &this->mColour;
  mBlendMode = this->mBlendMode;
  mDrawCtx = mView->mDrawCtx;
  info.mAlphaBlend = AlphaState_none;
  info.mColour1.r = r;
  b = p_mColour->b;
  info.mColour1.g = g;
  a = p_mColour->a;
  info.mColour1.b = b;
  info.mColour2.r = p_mColour->r;
  v14 = p_mColour->b;
  info.mColour1.a = a;
  v15 = p_mColour->g;
  info.mColour2.b = v14;
  info.mColour2.g = v15;
  v16 = p_mColour->a;
  LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
  info.mColour2.a = v16;
  if ( mBlendMode )
  {
    v17 = mBlendMode - 1;
    if ( v17 )
    {
      if ( v17 == 1 )
        info.mAlphaBlend = AlphaState_additive;
    }
    else
    {
      info.mAlphaBlend = AlphaState_modulated;
    }
  }
  else
  {
    info.mAlphaBlend = AlphaState_none;
  }
  info.mFaceCull = this->mBackfaceCull;
  mDepthTest = this->mDepthTest;
  info.mPreDrawCallback = 0i64;
  info.mDepthBuffer = mDepthTest;
  info.mDepthBias = this->mDepthBias;
  v19 = mode - 1;
  if ( v19 )
  {
    if ( v19 == 2 )
      Render::DebugDrawContext::DrawTriStrip(mDrawCtx, data, count, &info, 0i64, 1);
  }
  else
  {
    v20 = count - 1;
    if ( count - 1 > 0 )
    {
      p_y = &data->y;
      do
      {
        v22 = p_y[2];
        v23 = *(p_y - 1);
        v24 = *p_y;
        p_y += 3;
        p1.z = 0.0;
        p0.z = 0.0;
        v25 = _mm_cvtsi32_si128((int)*p_y);
        p1.x = (float)(int)v22;
        LODWORD(p1.y) = _mm_cvtepi32_ps(v25).m128_u32[0];
        p0.x = (float)(int)v23;
        p0.y = (float)(int)v24;
        Render::DebugDrawContext::DrawLine(mDrawCtx, &p0, &p1, p_mColour, 0i64, 0i64, 1);
        --v20;
      }
      while ( v20 );
    }
  }
}

