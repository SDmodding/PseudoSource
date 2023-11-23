// File Line: 32
// RVA: 0x1452B00
__int64 Render::_dynamic_initializer_for__gRenderUtilities__()
{
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gRenderUtilities__);
}

// File Line: 54
// RVA: 0x9E20
void __fastcall Render::RenderUtilities::Init(Render::RenderUtilities *this)
{
  unsigned int v2; // eax
  Illusion::Material *v3; // rax
  Illusion::Material *v4; // rbx
  int v5; // eax
  Illusion::Material *mMaterial; // rbx
  int v7; // eax
  Illusion::Material *v8; // rbx
  unsigned int v9; // eax
  Illusion::Material *v10; // rbx
  int v11; // eax
  Illusion::Material *v12; // rbx
  int v13; // eax
  Illusion::Material *v14; // rbx
  unsigned int v15; // eax
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // eax

  v2 = UFG::qStringHash32("RENDERUTIL", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("RENDERUTIL", v2, 6u, 0i64, 0i64, 0i64);
  this->mMaterial = v3;
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  v4 = v3;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 0;
  LODWORD(v4[1].mNode.mParent) = v5;
  mMaterial = this->mMaterial;
  *(_WORD *)&this->mMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&mMaterial[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(mMaterial[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&mMaterial[1].mDebugName[4] = v7;
  v8 = this->mMaterial;
  LOWORD(this->mMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v8[2].mNode.mUID = 662883558;
  v8[1].mNumParams = v9;
  v10 = this->mMaterial;
  LOWORD(this->mMaterial[2].mTypeUID) = 0;
  HIDWORD(v10[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v10[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v10[2].mDebugName[28] = 1660426324;
  LODWORD(v10[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v11;
  v12 = this->mMaterial;
  LOWORD(this->mMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v12[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v12[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v12[3].mNode.mChild[0]) = 0;
  LODWORD(v12[2].mStateBlockMask.mFlags[0]) = v13;
  v14 = this->mMaterial;
  LOWORD(this->mMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v14[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v14[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v14[3].mDebugName[12] = 0;
  v14[3].mNode.mUID = v15;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, this->mMaterial);
  v17 = UFG::qStringHash32("cbGaussianBlur", 0xFFFFFFFF);
  this->mGaussianBlurStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                           &Illusion::gStateSystem,
                                                           v17,
                                                           "cbGaussianBlur",
                                                           0);
}

// File Line: 68
// RVA: 0x9C40
void __fastcall Render::RenderUtilities::GaussBlur3x3(
        Render::RenderUtilities *this,
        Illusion::Target *src_target,
        Illusion::Target *dest_target,
        unsigned int src_texture_index,
        Render::Poly *override_poly,
        unsigned int shader_uid)
{
  __int64 v7; // r12
  Render::Poly *v10; // r15
  char *v11; // rax
  char *v12; // rbp
  _WORD *v13; // rbx
  __m128i v14; // xmm1
  Render::ViewSettings *Identity; // rax
  Illusion::Material *mMaterial; // rdi
  __int64 mOffset; // rax
  _WORD *v18; // rax
  Illusion::Material *v19; // rdi
  unsigned int mUID; // r8d
  __int64 v21; // rax
  unsigned int mGaussianBlurStateBlockIndex_low; // ebx
  Illusion::StateValues *StateValues; // rax
  Render::Poly v24; // [rsp+50h] [rbp-1B8h] BYREF
  Render::View v25; // [rsp+60h] [rbp-1A8h] BYREF

  v7 = src_texture_index;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v24);
  v10 = &v24;
  if ( override_poly )
    v10 = override_poly;
  v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v12 = v11;
  if ( v11 )
  {
    v13 = 0i64;
    *(float *)v11 = 1.0 / (float)src_target->mWidth;
    v14 = _mm_cvtsi32_si128(src_target->mHeight);
    *((_QWORD *)v11 + 1) = 0i64;
    *((float *)v11 + 1) = 1.0 / _mm_cvtepi32_ps(v14).m128_f32[0];
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v25, Identity, this->mSubmitContext);
    Render::View::BeginTarget(&v25, dest_target, "GaussBlur3x3", 0, 0, 0i64, 1, 0, 0, 0);
    mMaterial = this->mMaterial;
    if ( LODWORD(this->mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != shader_uid )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
        mMaterial[1].mTypeUID,
        shader_uid);
      mOffset = mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v18 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      else
        v18 = 0i64;
      *v18 |= 0x20u;
    }
    v19 = this->mMaterial;
    mUID = src_target->mTargetTexture[v7]->mNode.mUID;
    if ( LODWORD(this->mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v19[1].mDebugName[20], v19[1].mStateBlockMask.mFlags[1], mUID);
      v21 = v19->mMaterialUser.mOffset;
      if ( v21 )
        v13 = (_WORD *)((char *)&v19->mMaterialUser + v21);
      *v13 |= 0x20u;
    }
    mGaussianBlurStateBlockIndex_low = SLOWORD(this->mGaussianBlurStateBlockIndex);
    StateValues = Render::View::GetStateValues(&v25);
    if ( mGaussianBlurStateBlockIndex_low >= 0x40 )
      StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mGaussianBlurStateBlockIndex_low - 64);
    else
      StateValues->mSetValueMask.mFlags[0] |= 1i64 << mGaussianBlurStateBlockIndex_low;
    StateValues->mParamValues[(__int16)mGaussianBlurStateBlockIndex_low] = v12;
    Render::View::Draw(&v25, v10, this->mMaterial, 0i64);
    Render::View::EndTarget(&v25);
  }
}

// File Line: 104
// RVA: 0x9AD0
void __fastcall Render::RenderUtilities::Blit(
        Render::RenderUtilities *this,
        Illusion::Target *src_target,
        Illusion::Target *dest_target,
        unsigned int shaderId,
        const char *desc,
        unsigned int target_slice,
        bool clearOnResolve,
        UFG::qVector4 *texUV)
{
  Render::ViewSettings *Identity; // rax
  const char *v13; // r8
  _WORD *v14; // rbx
  Illusion::Material *mMaterial; // rdi
  __int64 mOffset; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rdi
  unsigned int mUID; // r8d
  __int64 v20; // rax
  Render::View v21; // [rsp+50h] [rbp-1A8h] BYREF
  Render::Poly poly; // [rsp+200h] [rbp+8h] BYREF

  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  if ( texUV )
    Render::Poly::SetUVs(&poly, texUV->x, texUV->y, texUV->z, texUV->w);
  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v21, Identity, this->mSubmitContext);
  v13 = "<Blit>";
  if ( desc )
    v13 = desc;
  v14 = 0i64;
  Render::View::BeginTarget(&v21, dest_target, v13, target_slice, 0, 0i64, clearOnResolve, 0, 0, 0);
  mMaterial = this->mMaterial;
  if ( LODWORD(this->mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != shaderId )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1], mMaterial[1].mTypeUID, shaderId);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v17 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
    else
      v17 = 0i64;
    *v17 |= 0x20u;
  }
  v18 = this->mMaterial;
  mUID = src_target->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(this->mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v18[1].mDebugName[20], v18[1].mStateBlockMask.mFlags[1], mUID);
    v20 = v18->mMaterialUser.mOffset;
    if ( v20 )
      v14 = (_WORD *)((char *)&v18->mMaterialUser + v20);
    *v14 |= 0x20u;
  }
  Render::View::Draw(&v21, &poly, this->mMaterial, 0i64);
  Render::View::EndTarget(&v21);
}

// File Line: 124
// RVA: 0xA2F0
void __fastcall Render::RenderUtilities::SeparableGaussBlur5x5(
        Render::RenderUtilities *this,
        Illusion::Target *src_target,
        Illusion::Target *dest_target,
        bool is_horizontial,
        unsigned int shader_uid)
{
  char *v9; // rax
  char *v10; // rdi
  _WORD *v11; // rbx
  __m128i v12; // xmm0
  Render::ViewSettings *Identity; // rax
  const char *v14; // r8
  Illusion::Material *mMaterial; // rsi
  __int64 mOffset; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rsi
  unsigned int mUID; // r8d
  __int64 v20; // rax
  unsigned int mGaussianBlurStateBlockIndex_low; // ebx
  Illusion::StateValues *StateValues; // rax
  Render::Poly poly; // [rsp+50h] [rbp-1B8h] BYREF
  Render::View v24; // [rsp+60h] [rbp-1A8h] BYREF

  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v10 = v9;
  if ( v9 )
  {
    v11 = 0i64;
    if ( is_horizontial )
    {
      v12 = _mm_cvtsi32_si128(dest_target->mWidth);
      *((_DWORD *)v9 + 1) = 0;
      *(float *)v9 = 1.0 / _mm_cvtepi32_ps(v12).m128_f32[0];
    }
    else
    {
      *(_DWORD *)v9 = 0;
      *((float *)v9 + 1) = 1.0 / (float)dest_target->mHeight;
    }
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v24, Identity, this->mSubmitContext);
    v14 = "GaussBlur5x5_Vert";
    if ( is_horizontial )
      v14 = "GaussBlur5x5_Horz";
    Render::View::BeginTarget(&v24, dest_target, v14, 0, 0, 0i64, 1, 0, 0, 0);
    mMaterial = this->mMaterial;
    if ( LODWORD(this->mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != shader_uid )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mNode.mChild[1],
        mMaterial[1].mTypeUID,
        shader_uid);
      mOffset = mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v17 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    v18 = this->mMaterial;
    mUID = src_target->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(this->mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v18[1].mDebugName[20], v18[1].mStateBlockMask.mFlags[1], mUID);
      v20 = v18->mMaterialUser.mOffset;
      if ( v20 )
        v11 = (_WORD *)((char *)&v18->mMaterialUser + v20);
      *v11 |= 0x20u;
    }
    mGaussianBlurStateBlockIndex_low = SLOWORD(this->mGaussianBlurStateBlockIndex);
    StateValues = Render::View::GetStateValues(&v24);
    if ( mGaussianBlurStateBlockIndex_low >= 0x40 )
      StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mGaussianBlurStateBlockIndex_low - 64);
    else
      StateValues->mSetValueMask.mFlags[0] |= 1i64 << mGaussianBlurStateBlockIndex_low;
    StateValues->mParamValues[(__int16)mGaussianBlurStateBlockIndex_low] = v10;
    Render::View::Draw(&v24, &poly, this->mMaterial, 0i64);
    Render::View::EndTarget(&v24);
  }
}

// File Line: 160
// RVA: 0xA060
void __fastcall Render::RenderUtilities::RenderMips(
        Render::RenderUtilities *this,
        Illusion::Target *src_target,
        int num_mips,
        unsigned int shader_uid)
{
  float mWidth; // xmm6_4
  float mHeight; // xmm7_4
  float v9; // xmm0_4
  int v10; // ebx
  Render::ViewSettings *Identity; // rax
  unsigned int v12; // r15d
  char *v13; // rax
  char *v14; // rdi
  Illusion::Material *mMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v17; // rax
  unsigned int mUID; // r8d
  __int64 v19; // rax
  _WORD *v20; // rax
  unsigned int mGaussianBlurStateBlockIndex_low; // ebx
  Illusion::StateValues *StateValues; // rax
  Render::View v23; // [rsp+50h] [rbp-1F8h] BYREF
  Render::Poly poly; // [rsp+258h] [rbp+10h] BYREF

  mWidth = (float)src_target->mTargetTexture[0]->mWidth;
  mHeight = (float)src_target->mTargetTexture[0]->mHeight;
  v9 = (float)num_mips;
  if ( (float)num_mips >= (float)((unsigned __int8)src_target->mTargetTexture[0]->mNumMipMaps - 1) )
    v9 = (float)((unsigned __int8)src_target->mTargetTexture[0]->mNumMipMaps - 1);
  v10 = 0;
  if ( (int)v9 )
  {
    do
    {
      mWidth = mWidth * 0.5;
      mHeight = mHeight * 0.5;
      Identity = Render::ViewSettings::GetIdentity();
      Render::View::View(&v23, Identity, this->mSubmitContext);
      v12 = v10 + 1;
      Render::View::BeginTarget(&v23, src_target, "RenderMip", 0, v10 + 1, 0i64, 1, 0, 0, 0);
      v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *((_DWORD *)v13 + 2) = 0;
      v14 = v13;
      *(float *)v13 = 1.0 / mWidth;
      *((float *)v13 + 1) = 1.0 / mHeight;
      *((float *)v13 + 3) = (float)v10;
      mMaterial = Render::gRenderUtilities.mMaterial;
      if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != shader_uid )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
          Render::gRenderUtilities.mMaterial[1].mTypeUID,
          shader_uid);
        mOffset = mMaterial->mMaterialUser.mOffset;
        if ( mOffset )
          v17 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
        else
          v17 = 0i64;
        *v17 |= 0x20u;
        mMaterial = Render::gRenderUtilities.mMaterial;
      }
      mUID = src_target->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
          mMaterial[1].mStateBlockMask.mFlags[1],
          mUID);
        v19 = mMaterial->mMaterialUser.mOffset;
        if ( v19 )
          v20 = (_WORD *)((char *)&mMaterial->mMaterialUser + v19);
        else
          v20 = 0i64;
        *v20 |= 0x20u;
      }
      mGaussianBlurStateBlockIndex_low = SLOWORD(Render::gRenderUtilities.mGaussianBlurStateBlockIndex);
      StateValues = Render::View::GetStateValues(&v23);
      if ( mGaussianBlurStateBlockIndex_low >= 0x40 )
        StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mGaussianBlurStateBlockIndex_low - 64);
      else
        StateValues->mSetValueMask.mFlags[0] |= 1i64 << mGaussianBlurStateBlockIndex_low;
      StateValues->mParamValues[(__int16)mGaussianBlurStateBlockIndex_low] = v14;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v23, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      Render::View::EndTarget(&v23);
      v10 = v12;
    }
    while ( v12 < (int)v9 );
  }
}

