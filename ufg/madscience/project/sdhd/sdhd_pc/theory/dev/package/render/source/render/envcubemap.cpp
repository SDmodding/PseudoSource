// File Line: 59
// RVA: 0x1452AA0
__int64 Render::_dynamic_initializer_for__kCubeToSphericalUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CUBETOSPHERICAL", 0xFFFFFFFF);
  kCubeToSphericalUID = result;
  return result;
}

// File Line: 68
// RVA: 0x93C0
void __fastcall Render::EnvCubeMap::Init(Render::EnvCubeMap *this, Illusion::Target *target)
{
  this->mTarget = target;
  this->mSideTarget = 0i64;
  this->mMSAADownsampleMaterial = 0i64;
  this->mViewSettings[0].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[0].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[0] = 0i64;
  this->mViewSettings[1].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[1].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[1] = 0i64;
  this->mViewSettings[2].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[2].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[2] = 0i64;
  this->mViewSettings[3].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[3].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[3] = 0i64;
  this->mViewSettings[4].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[4].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[4] = 0i64;
  this->mViewSettings[5].mCullIndex = -1;
  *(_QWORD *)&this->mViewSettings[5].mCullPixelDensityThreshold = 1034147594i64;
  this->mDebugOverlay[5] = 0i64;
}

// File Line: 90
// RVA: 0x9990
void __fastcall Render::EnvCubeMap::UpdateMatrices(Render::EnvCubeMap *this, UFG::qVector3 *position, float near_plane, float far_plane)
{
  Render::EnvCubeMap *v4; // rsi
  UFG::qVector3 *v5; // rbp
  UFG::qVector3 *v6; // r14
  float *v7; // rdi
  signed __int64 v8; // rbx
  signed __int64 v9; // r15
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::qVector4 v12; // xmm1
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  UFG::qVector3 target; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-98h]
  __int128 v19; // [rsp+80h] [rbp-58h]
  __int128 v20; // [rsp+90h] [rbp-48h]
  __int128 v21; // [rsp+A0h] [rbp-38h]
  __int128 v22; // [rsp+B0h] [rbp-28h]

  v4 = this;
  v5 = position;
  UFG::qPerspectiveMatrix((UFG::qMatrix44 *)&v19, 1.5707964, 1.0, near_plane, far_plane);
  v6 = Render::gCubeMapUpOffset;
  v7 = &Render::gCubeMapLookatOffset[0].z;
  v8 = (signed __int64)&v4->mViewSettings[0].mWorldView.v2;
  v9 = 6i64;
  do
  {
    v10 = v5->y - *(v7 - 1);
    target.x = v5->x - *(v7 - 2);
    v11 = v5->z;
    target.y = v10;
    target.z = v11 - *v7;
    UFG::qLookAtMatrix(&dest, v5, &target, v6);
    v12 = dest.v1;
    v8 += 144i64;
    ++v6;
    v7 += 3;
    *(UFG::qVector4 *)(v8 - 176) = dest.v0;
    *(UFG::qVector4 *)(v8 - 160) = v12;
    v13 = v19;
    *(UFG::qVector4 *)(v8 - 144) = dest.v2;
    *(UFG::qVector4 *)(v8 - 128) = dest.v3;
    v14 = v20;
    *(_OWORD *)(v8 - 112) = v13;
    v15 = v21;
    *(_OWORD *)(v8 - 96) = v14;
    v16 = v22;
    *(_OWORD *)(v8 - 80) = v15;
    *(_OWORD *)(v8 - 64) = v16;
    --v9;
  }
  while ( v9 );
  *(_QWORD *)&v4->mFrameTime = 0i64;
}

// File Line: 114
// RVA: 0x9480
void __fastcall Render::EnvCubeMap::Render(Render::EnvCubeMap *this, void (__fastcall *render_scene_callback)(Render::View *, void *, void *), unsigned int side_num, Illusion::SubmitContext *submit_context, void *user_data1, void *user_data2)
{
  Illusion::SubmitContext *v6; // r15
  unsigned int v7; // edi
  void (__fastcall *v8)(Render::View *, void *, void *); // r12
  Render::EnvCubeMap *v9; // rbx
  unsigned int v10; // er14
  const char **v11; // rsi
  Render::ViewSettings *v12; // rbp
  Illusion::Target *v13; // rdx
  unsigned int v14; // er9
  const char *v15; // r8
  float v16; // xmm0_4
  bool v17; // zf
  Render::ViewSettings *v18; // rax
  Render::Poly poly; // [rsp+50h] [rbp-358h]
  Render::View v20; // [rsp+60h] [rbp-348h]
  Render::View v21; // [rsp+1F0h] [rbp-1B8h]

  v6 = submit_context;
  v7 = side_num;
  v8 = render_scene_callback;
  v9 = this;
  if ( side_num == -1 )
  {
    v7 = 0;
    v10 = 6;
  }
  else
  {
    v10 = side_num + 1;
  }
  if ( v7 < v10 )
  {
    v11 = (const char **)(&this->mTarget + v7 + 4i64 * v7 + 121);
    v12 = &this->mViewSettings[v7];
    do
    {
      Render::View::View(&v20, v12, v6);
      v13 = v9->mSideTarget;
      if ( v13 )
      {
        v14 = 0;
        v15 = "EnvMapMSAASide";
      }
      else
      {
        v15 = *v11;
        v13 = v9->mTarget;
        v14 = v7;
      }
      Render::View::BeginTarget(&v20, v13, v15, v14, 0, 0i64, 1, 0, 0, 0);
      v8(&v20, user_data1, user_data2);
      Render::View::EndTarget(&v20);
      v16 = v20.mViewMetrics.mTargetTiming + v9->mFrameTime;
      v9->mNumDrawCalls += v20.mViewMetrics.mNumMeshsRendered;
      v17 = v9->mSideTarget == 0i64;
      v9->mFrameTime = v16;
      if ( !v17 )
      {
        v18 = Render::ViewSettings::GetIdentity();
        Render::View::View(&v21, v18, v6);
        Render::View::BeginTarget(&v21, v9->mTarget, *v11, v7, 0, 0i64, 1, 0, 0, 0);
        Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
        Render::View::Draw(&v21, &poly, v9->mMSAADownsampleMaterial, 0i64);
        Render::View::EndTarget(&v21);
      }
      ++v7;
      ++v12;
      v11 += 5;
    }
    while ( v7 < v10 );
  }
}

// File Line: 156
// RVA: 0x9790
void __fastcall Render::EnvCubeMap::RenderSphericalMap(Render::EnvCubeMap *this, Illusion::Target *spherical_target, Illusion::SubmitContext *submit_context, float blend_amount)
{
  unsigned int v4; // ebp
  Illusion::SubmitContext *v5; // rbx
  Illusion::Target *v6; // rdi
  Render::EnvCubeMap *v7; // r14
  Render::ViewSettings *v8; // rax
  _WORD *v9; // rsi
  Illusion::Material *v10; // rbx
  __int64 v11; // rax
  _WORD *v12; // rax
  unsigned int v13; // er8
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 v16; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rbx
  __int64 v19; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-1C8h]
  Render::View v21; // [rsp+60h] [rbp-1B8h]
  Render::Poly poly; // [rsp+220h] [rbp+8h]

  v4 = 662883558;
  v5 = submit_context;
  v6 = spherical_target;
  v7 = this;
  if ( blend_amount < 1.0 )
    v4 = -1551679522;
  v8 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v21, v8, v5);
  v9 = 0i64;
  Render::View::BeginTarget(&v21, v6, "EnvToSphericalMap", 0, 0, 0i64, 1, 0, 0, 0);
  v10 = Render::gRenderUtilities.mMaterial;
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != kCubeToSphericalUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      kCubeToSphericalUID);
    v11 = v10->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&v10->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
    v10 = Render::gRenderUtilities.mMaterial;
  }
  v13 = v7->mTarget->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(v10[1].mStateBlockMask.mFlags[0]) != v13 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10[1].mDebugName[20], v10[1].mStateBlockMask.mFlags[1], v13);
    v14 = v10->mMaterialUser.mOffset;
    if ( v14 )
      v15 = (_WORD *)((char *)&v10->mMaterialUser + v14);
    else
      v15 = 0i64;
    *v15 |= 0x20u;
    v10 = Render::gRenderUtilities.mMaterial;
  }
  if ( v10[2].mNode.mUID != v4 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10[2], (unsigned int)v10[2].mResourceHandles.mNode.mPrev, v4);
    v16 = v10->mMaterialUser.mOffset;
    if ( v16 )
      v17 = (_WORD *)((char *)&v10->mMaterialUser + v16);
    else
      v17 = 0i64;
    *v17 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  colour.a = blend_amount;
  colour.r = 1.0;
  colour.g = 1.0;
  colour.b = 1.0;
  Render::Poly::SetColour(&poly, &colour);
  Render::View::Draw(&v21, &poly, Render::gRenderUtilities.mMaterial, 0i64);
  Render::View::EndTarget(&v21);
  v18 = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v19 = v18->mMaterialUser.mOffset;
    if ( v19 )
      v9 = (_WORD *)((char *)&v18->mMaterialUser + v19);
    *v9 |= 0x20u;
  }
}

// File Line: 182
// RVA: 0x9660
void __fastcall Render::EnvCubeMap::RenderDebugOverlay(Render::EnvCubeMap *this, Render::View *view, int x, int y, int size)
{
  Render::View *v5; // r14
  int *v6; // rbx
  signed __int64 v7; // rbp
  signed __int64 v8; // rdi
  __int64 v9; // rax
  UFG::qColour v10; // [rsp+50h] [rbp-18h]

  v5 = view;
  if ( !(_S1 & 1) )
  {
    _S1 |= 1u;
    placement_table[0][0] = 2 * size + x;
    dword_14212938C = y + size;
    dword_142129390 = x;
    dword_142129394 = y + size;
    dword_142129398 = x + size;
    dword_14212939C = y;
    dword_1421293A0 = x + size;
    dword_1421293A4 = 2 * size + y;
    dword_1421293A8 = x + size;
    dword_1421293AC = y + size;
    dword_1421293B0 = size + x + 2 * size;
    dword_1421293B4 = y + size;
  }
  v6 = &dword_14212938C;
  v7 = (char *)this - (char *)&dword_14212938C;
  v8 = 6i64;
  do
  {
    v9 = *(_QWORD *)((char *)v6 + v7 + 896);
    if ( v9 )
    {
      v10 = UFG::qColour::White;
      Render::View::DrawIcon(v5, *(_DWORD *)(v9 + 24), *(v6 - 1), *v6, size, size, &v10, 0x2782CCE6u);
    }
    v6 += 2;
    --v8;
  }
  while ( v8 );
}

