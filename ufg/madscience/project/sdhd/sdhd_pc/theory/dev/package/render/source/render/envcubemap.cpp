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
void __fastcall Render::EnvCubeMap::UpdateMatrices(
        Render::EnvCubeMap *this,
        UFG::qVector3 *position,
        float near_plane,
        float far_plane)
{
  UFG::qVector3 *v6; // r14
  float *p_z; // rdi
  UFG::qVector4 *v8; // rbx
  __int64 v9; // r15
  float v10; // xmm1_4
  float z; // xmm0_4
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qVector3 target; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-98h] BYREF
  UFG::qMatrix44 v19; // [rsp+80h] [rbp-58h] BYREF

  UFG::qPerspectiveMatrix(&v19, 1.5707964, 1.0, near_plane, far_plane);
  v6 = Render::gCubeMapUpOffset;
  p_z = &Render::gCubeMapLookatOffset[0].z;
  v8 = &this->mViewSettings[0].mWorldView.v2;
  v9 = 6i64;
  do
  {
    v10 = position->y - *(p_z - 1);
    target.x = position->x - *(p_z - 2);
    z = position->z;
    target.y = v10;
    target.z = z - *p_z;
    UFG::qLookAtMatrix(&dest, position, &target, v6);
    v12 = dest.v1;
    v8 += 9;
    ++v6;
    p_z += 3;
    v8[-11] = dest.v0;
    v8[-10] = v12;
    v13 = v19.v0;
    v8[-9] = dest.v2;
    v8[-8] = dest.v3;
    v14 = v19.v1;
    v8[-7] = v13;
    v15 = v19.v2;
    v8[-6] = v14;
    v16 = v19.v3;
    v8[-5] = v15;
    v8[-4] = v16;
    --v9;
  }
  while ( v9 );
  *(_QWORD *)&this->mFrameTime = 0i64;
}

// File Line: 114
// RVA: 0x9480
void __fastcall Render::EnvCubeMap::Render(
        Render::EnvCubeMap *this,
        void (__fastcall *render_scene_callback)(Render::View *, void *, void *),
        unsigned int side_num,
        Illusion::SubmitContext *submit_context,
        void *user_data1,
        void *user_data2)
{
  unsigned int v7; // edi
  unsigned int v10; // r14d
  const char **v11; // rsi
  Render::ViewSettings *v12; // rbp
  Illusion::Target *mSideTarget; // rdx
  unsigned int v14; // r9d
  const char *v15; // r8
  float v16; // xmm0_4
  bool v17; // zf
  Render::ViewSettings *Identity; // rax
  Render::Poly poly; // [rsp+50h] [rbp-358h] BYREF
  Render::View v20; // [rsp+60h] [rbp-348h] BYREF
  Render::View v21; // [rsp+1F0h] [rbp-1B8h] BYREF

  v7 = side_num;
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
    v11 = (const char **)(&this->mFaceName[0].mData + 4 * v7 + v7);
    v12 = &this->mViewSettings[v7];
    do
    {
      Render::View::View(&v20, v12, submit_context);
      mSideTarget = this->mSideTarget;
      if ( mSideTarget )
      {
        v14 = 0;
        v15 = "EnvMapMSAASide";
      }
      else
      {
        v15 = *v11;
        mSideTarget = this->mTarget;
        v14 = v7;
      }
      Render::View::BeginTarget(&v20, mSideTarget, v15, v14, 0, 0i64, 1, 0, 0, 0);
      render_scene_callback(&v20, user_data1, user_data2);
      Render::View::EndTarget(&v20);
      v16 = v20.mViewMetrics.mTargetTiming + this->mFrameTime;
      this->mNumDrawCalls += v20.mViewMetrics.mNumMeshsRendered;
      v17 = this->mSideTarget == 0i64;
      this->mFrameTime = v16;
      if ( !v17 )
      {
        Identity = Render::ViewSettings::GetIdentity();
        Render::View::View(&v21, Identity, submit_context);
        Render::View::BeginTarget(&v21, this->mTarget, *v11, v7, 0, 0i64, 1, 0, 0, 0);
        Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
        Render::View::Draw(&v21, &poly, this->mMSAADownsampleMaterial, 0i64);
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
void __fastcall Render::EnvCubeMap::RenderSphericalMap(
        Render::EnvCubeMap *this,
        Illusion::Target *spherical_target,
        Illusion::SubmitContext *submit_context,
        float blend_amount)
{
  unsigned int v4; // ebp
  Render::ViewSettings *Identity; // rax
  _WORD *v9; // rsi
  Illusion::Material *mMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v12; // rax
  unsigned int mUID; // r8d
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 v16; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rbx
  __int64 v19; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-1C8h] BYREF
  Render::View v21; // [rsp+60h] [rbp-1B8h] BYREF
  Render::Poly poly; // [rsp+220h] [rbp+8h] BYREF

  v4 = 662883558;
  if ( blend_amount < 1.0 )
    v4 = -1551679522;
  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v21, Identity, submit_context);
  v9 = 0i64;
  Render::View::BeginTarget(&v21, spherical_target, "EnvToSphericalMap", 0, 0, 0i64, 1, 0, 0, 0);
  mMaterial = Render::gRenderUtilities.mMaterial;
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != kCubeToSphericalUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      kCubeToSphericalUID);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v12 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
    mMaterial = Render::gRenderUtilities.mMaterial;
  }
  mUID = this->mTarget->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
      mMaterial[1].mStateBlockMask.mFlags[1],
      mUID);
    v14 = mMaterial->mMaterialUser.mOffset;
    if ( v14 )
      v15 = (_WORD *)((char *)&mMaterial->mMaterialUser + v14);
    else
      v15 = 0i64;
    *v15 |= 0x20u;
    mMaterial = Render::gRenderUtilities.mMaterial;
  }
  if ( mMaterial[2].mNode.mUID != v4 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[2],
      (unsigned int)mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      v4);
    v16 = mMaterial->mMaterialUser.mOffset;
    if ( v16 )
      v17 = (_WORD *)((char *)&mMaterial->mMaterialUser + v16);
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
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v19 = v18->mMaterialUser.mOffset;
    if ( v19 )
      v9 = (_WORD *)((char *)&v18->mMaterialUser + v19);
    *v9 |= 0x20u;
  }
}

// File Line: 182
// RVA: 0x9660
void __fastcall Render::EnvCubeMap::RenderDebugOverlay(
        Render::EnvCubeMap *this,
        Render::View *view,
        int x,
        int y,
        int size)
{
  int *v6; // rbx
  signed __int64 v7; // rbp
  __int64 v8; // rdi
  __int64 v9; // rax
  UFG::qColour v10; // [rsp+50h] [rbp-18h] BYREF

  if ( (_S1 & 1) == 0 )
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
      Render::View::DrawIcon(view, *(_DWORD *)(v9 + 24), *(v6 - 1), *v6, size, size, &v10, 0x2782CCE6u);
    }
    v6 += 2;
    --v8;
  }
  while ( v8 );
}

