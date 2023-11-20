// File Line: 32
// RVA: 0x1452B00
__int64 Render::_dynamic_initializer_for__gRenderUtilities__()
{
  return atexit(Render::_dynamic_atexit_destructor_for__gRenderUtilities__);
}

// File Line: 54
// RVA: 0x9E20
void __fastcall Render::RenderUtilities::Init(Render::RenderUtilities *this)
{
  Render::RenderUtilities *v1; // rdi
  unsigned int v2; // eax
  Illusion::Material *v3; // rax
  Illusion::Material *v4; // rbx
  int v5; // eax
  Illusion::Material *v6; // rbx
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

  v1 = this;
  v2 = UFG::qStringHash32("RENDERUTIL", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("RENDERUTIL", v2, 6u, 0i64, 0i64, 0i64);
  v1->mMaterial = v3;
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  v4 = v3;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.mNode.mNext) = 0;
  LODWORD(v4[1].mNode.mParent) = v5;
  v6 = v1->mMaterial;
  *(_WORD *)&v1->mMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v6[1].mDebugName[4] = v7;
  v8 = v1->mMaterial;
  LOWORD(v1->mMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.mNode.mPrev) = 315097330;
  v8[2].mNode.mUID = 662883558;
  v8[1].mNumParams = v9;
  v10 = v1->mMaterial;
  LOWORD(v1->mMaterial[2].mTypeUID) = 0;
  HIDWORD(v10[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v10[2].0 + 22) = 1002903008;
  *(_DWORD *)&v10[2].mDebugName[28] = 1660426324;
  LODWORD(v10[2].mResourceHandles.mNode.mNext) = v11;
  v12 = v1->mMaterial;
  LOWORD(v1->mMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v12[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v12[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v12[3].mNode.mChild[0]) = 0;
  LODWORD(v12[2].mStateBlockMask.mFlags[0]) = v13;
  v14 = v1->mMaterial;
  LOWORD(v1->mMaterial[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v14[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v14[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v14[3].mDebugName[12] = 0;
  v14[3].mNode.mUID = v15;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, (UFG::qResourceData *)&v1->mMaterial->mNode);
  v17 = UFG::qStringHash32("cbGaussianBlur", 0xFFFFFFFF);
  v1->mGaussianBlurStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                         &Illusion::gStateSystem,
                                                         v17,
                                                         "cbGaussianBlur",
                                                         0);
}

// File Line: 68
// RVA: 0x9C40
void __fastcall Render::RenderUtilities::GaussBlur3x3(Render::RenderUtilities *this, Illusion::Target *src_target, Illusion::Target *dest_target, unsigned int src_texture_index, Render::Poly *override_poly, unsigned int shader_uid)
{
  Render::RenderUtilities *v6; // rsi
  __int64 v7; // r12
  Illusion::Target *v8; // rdi
  Illusion::Target *v9; // r14
  Render::Poly *v10; // r15
  char *v11; // rax
  char *v12; // rbp
  _WORD *v13; // rbx
  __m128i v14; // xmm1
  Render::ViewSettings *v15; // rax
  Illusion::Material *v16; // rdi
  __int64 v17; // rax
  _WORD *v18; // rax
  Illusion::Material *v19; // rdi
  unsigned int v20; // er8
  __int64 v21; // rax
  unsigned int v22; // ebx
  Illusion::StateValues *v23; // rax
  Render::Poly v24; // [rsp+50h] [rbp-1B8h]
  Render::View v25; // [rsp+60h] [rbp-1A8h]

  v6 = this;
  v7 = src_texture_index;
  v8 = dest_target;
  v9 = src_target;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v24);
  v10 = &v24;
  if ( override_poly )
    v10 = override_poly;
  v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v12 = v11;
  if ( v11 )
  {
    v13 = 0i64;
    *(float *)v11 = 1.0 / (float)v9->mWidth;
    v14 = _mm_cvtsi32_si128(v9->mHeight);
    *((_QWORD *)v11 + 1) = 0i64;
    *((float *)v11 + 1) = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v14));
    v15 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v25, v15, v6->mSubmitContext);
    Render::View::BeginTarget(&v25, v8, "GaussBlur3x3", 0, 0, 0i64, 1, 0, 0, 0);
    v16 = v6->mMaterial;
    if ( LODWORD(v6->mMaterial[1].mResourceHandles.mNode.mNext) != shader_uid )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v16[1].mNode.mChild[1], v16[1].mTypeUID, shader_uid);
      v17 = v16->mMaterialUser.mOffset;
      if ( v17 )
        v18 = (_WORD *)((char *)&v16->mMaterialUser + v17);
      else
        v18 = 0i64;
      *v18 |= 0x20u;
    }
    v19 = v6->mMaterial;
    v20 = v9->mTargetTexture[v7]->mNode.mUID;
    if ( LODWORD(v6->mMaterial[1].mStateBlockMask.mFlags[0]) != v20 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v19[1].mDebugName[20], v19[1].mStateBlockMask.mFlags[1], v20);
      v21 = v19->mMaterialUser.mOffset;
      if ( v21 )
        v13 = (_WORD *)((char *)&v19->mMaterialUser + v21);
      *v13 |= 0x20u;
    }
    v22 = SLOWORD(v6->mGaussianBlurStateBlockIndex);
    v23 = Render::View::GetStateValues(&v25);
    if ( v22 >= 0x40 )
      v23->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v22 - 64);
    else
      v23->mSetValueMask.mFlags[0] |= 1i64 << v22;
    v23->mParamValues[(signed __int16)v22] = v12;
    Render::View::Draw(&v25, v10, v6->mMaterial, 0i64);
    Render::View::EndTarget(&v25);
  }
}

// File Line: 104
// RVA: 0x9AD0
void __fastcall Render::RenderUtilities::Blit(Render::RenderUtilities *this, Illusion::Target *src_target, Illusion::Target *dest_target, unsigned int shaderId, const char *desc, const unsigned int target_slice, bool clearOnResolve, UFG::qVector4 *texUV)
{
  Render::RenderUtilities *v8; // rsi
  unsigned int v9; // ebp
  Illusion::Target *v10; // rdi
  Illusion::Target *v11; // r14
  Render::ViewSettings *v12; // rax
  const char *v13; // r8
  _WORD *v14; // rbx
  Illusion::Material *v15; // rdi
  __int64 v16; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rdi
  unsigned int v19; // er8
  __int64 v20; // rax
  Render::View v21; // [rsp+50h] [rbp-1A8h]
  Render::Poly poly; // [rsp+200h] [rbp+8h]

  v8 = this;
  v9 = shaderId;
  v10 = dest_target;
  v11 = src_target;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  if ( texUV )
    Render::Poly::SetUVs(&poly, texUV->x, texUV->y, texUV->z, texUV->w);
  v12 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v21, v12, v8->mSubmitContext);
  v13 = "<Blit>";
  if ( desc )
    v13 = desc;
  v14 = 0i64;
  Render::View::BeginTarget(&v21, v10, v13, target_slice, 0, 0i64, clearOnResolve, 0, 0, 0);
  v15 = v8->mMaterial;
  if ( LODWORD(v8->mMaterial[1].mResourceHandles.mNode.mNext) != v9 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v15[1].mNode.mChild[1], v15[1].mTypeUID, v9);
    v16 = v15->mMaterialUser.mOffset;
    if ( v16 )
      v17 = (_WORD *)((char *)&v15->mMaterialUser + v16);
    else
      v17 = 0i64;
    *v17 |= 0x20u;
  }
  v18 = v8->mMaterial;
  v19 = v11->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(v8->mMaterial[1].mStateBlockMask.mFlags[0]) != v19 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v18[1].mDebugName[20], v18[1].mStateBlockMask.mFlags[1], v19);
    v20 = v18->mMaterialUser.mOffset;
    if ( v20 )
      v14 = (_WORD *)((char *)&v18->mMaterialUser + v20);
    *v14 |= 0x20u;
  }
  Render::View::Draw(&v21, &poly, v8->mMaterial, 0i64);
  Render::View::EndTarget(&v21);
}

// File Line: 124
// RVA: 0xA2F0
void __fastcall Render::RenderUtilities::SeparableGaussBlur5x5(Render::RenderUtilities *this, Illusion::Target *src_target, Illusion::Target *dest_target, bool is_horizontial, unsigned int shader_uid)
{
  Render::RenderUtilities *v5; // r14
  bool v6; // bp
  Illusion::Target *v7; // rsi
  Illusion::Target *v8; // r15
  char *v9; // rax
  char *v10; // rdi
  _WORD *v11; // rbx
  __m128i v12; // xmm0
  Render::ViewSettings *v13; // rax
  const char *v14; // r8
  Illusion::Material *v15; // rsi
  __int64 v16; // rax
  _WORD *v17; // rax
  Illusion::Material *v18; // rsi
  unsigned int v19; // er8
  __int64 v20; // rax
  unsigned int v21; // ebx
  Illusion::StateValues *v22; // rax
  Render::Poly poly; // [rsp+50h] [rbp-1B8h]
  Render::View v24; // [rsp+60h] [rbp-1A8h]

  v5 = this;
  v6 = is_horizontial;
  v7 = dest_target;
  v8 = src_target;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v10 = v9;
  if ( v9 )
  {
    v11 = 0i64;
    if ( v6 )
    {
      v12 = _mm_cvtsi32_si128(v7->mWidth);
      *((_DWORD *)v9 + 1) = 0;
      *(float *)v9 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v12));
    }
    else
    {
      *(_DWORD *)v9 = 0;
      *((float *)v9 + 1) = 1.0 / (float)v7->mHeight;
    }
    v13 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v24, v13, v5->mSubmitContext);
    v14 = "GaussBlur5x5_Vert";
    if ( v6 )
      v14 = "GaussBlur5x5_Horz";
    Render::View::BeginTarget(&v24, v7, v14, 0, 0, 0i64, 1, 0, 0, 0);
    v15 = v5->mMaterial;
    if ( LODWORD(v5->mMaterial[1].mResourceHandles.mNode.mNext) != shader_uid )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v15[1].mNode.mChild[1], v15[1].mTypeUID, shader_uid);
      v16 = v15->mMaterialUser.mOffset;
      if ( v16 )
        v17 = (_WORD *)((char *)&v15->mMaterialUser + v16);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    v18 = v5->mMaterial;
    v19 = v8->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(v5->mMaterial[1].mStateBlockMask.mFlags[0]) != v19 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v18[1].mDebugName[20], v18[1].mStateBlockMask.mFlags[1], v19);
      v20 = v18->mMaterialUser.mOffset;
      if ( v20 )
        v11 = (_WORD *)((char *)&v18->mMaterialUser + v20);
      *v11 |= 0x20u;
    }
    v21 = SLOWORD(v5->mGaussianBlurStateBlockIndex);
    v22 = Render::View::GetStateValues(&v24);
    if ( v21 >= 0x40 )
      v22->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v21 - 64);
    else
      v22->mSetValueMask.mFlags[0] |= 1i64 << v21;
    v22->mParamValues[(signed __int16)v21] = v10;
    Render::View::Draw(&v24, &poly, v5->mMaterial, 0i64);
    Render::View::EndTarget(&v24);
  }
}

// File Line: 160
// RVA: 0xA060
void __fastcall Render::RenderUtilities::RenderMips(Render::RenderUtilities *this, Illusion::Target *src_target, unsigned int num_mips, unsigned int shader_uid)
{
  unsigned int v4; // ebp
  Illusion::Target *v5; // rsi
  Render::RenderUtilities *v6; // r13
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  signed int v10; // ebx
  Render::ViewSettings *v11; // rax
  unsigned int v12; // er15
  char *v13; // rax
  char *v14; // rdi
  Illusion::Material *v15; // rbx
  __int64 v16; // rax
  _WORD *v17; // rax
  unsigned int v18; // er8
  __int64 v19; // rax
  _WORD *v20; // rax
  unsigned int v21; // ebx
  Illusion::StateValues *v22; // rax
  Render::View v23; // [rsp+50h] [rbp-1F8h]
  Render::Poly poly; // [rsp+258h] [rbp+10h]

  v4 = shader_uid;
  v5 = src_target;
  v6 = this;
  v7 = (float)src_target->mTargetTexture[0]->mWidth;
  v8 = (float)src_target->mTargetTexture[0]->mHeight;
  v9 = (float)(signed int)num_mips;
  if ( (float)(signed int)num_mips >= (float)((unsigned __int8)src_target->mTargetTexture[0]->mNumMipMaps - 1) )
    v9 = (float)((unsigned __int8)src_target->mTargetTexture[0]->mNumMipMaps - 1);
  v10 = 0;
  if ( (signed int)v9 )
  {
    do
    {
      v7 = v7 * 0.5;
      v8 = v8 * 0.5;
      v11 = Render::ViewSettings::GetIdentity();
      Render::View::View(&v23, v11, v6->mSubmitContext);
      v12 = v10 + 1;
      Render::View::BeginTarget(&v23, v5, "RenderMip", 0, v10 + 1, 0i64, 1, 0, 0, 0);
      v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *((_DWORD *)v13 + 2) = 0;
      v14 = v13;
      *(float *)v13 = 1.0 / v7;
      *((float *)v13 + 1) = 1.0 / v8;
      *((float *)v13 + 3) = (float)v10;
      v15 = Render::gRenderUtilities.mMaterial;
      if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != v4 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
          Render::gRenderUtilities.mMaterial[1].mTypeUID,
          v4);
        v16 = v15->mMaterialUser.mOffset;
        if ( v16 )
          v17 = (_WORD *)((char *)&v15->mMaterialUser + v16);
        else
          v17 = 0i64;
        *v17 |= 0x20u;
        v15 = Render::gRenderUtilities.mMaterial;
      }
      v18 = v5->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v15[1].mStateBlockMask.mFlags[0]) != v18 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v15[1].mDebugName[20],
          v15[1].mStateBlockMask.mFlags[1],
          v18);
        v19 = v15->mMaterialUser.mOffset;
        if ( v19 )
          v20 = (_WORD *)((char *)&v15->mMaterialUser + v19);
        else
          v20 = 0i64;
        *v20 |= 0x20u;
      }
      v21 = SLOWORD(Render::gRenderUtilities.mGaussianBlurStateBlockIndex);
      v22 = Render::View::GetStateValues(&v23);
      if ( v21 >= 0x40 )
        v22->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v21 - 64);
      else
        v22->mSetValueMask.mFlags[0] |= 1i64 << v21;
      v22->mParamValues[(signed __int16)v21] = v14;
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(&v23, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      Render::View::EndTarget(&v23);
      v10 = v12;
    }
    while ( v12 < (signed int)v9 );
  }
}

