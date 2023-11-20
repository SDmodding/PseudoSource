// File Line: 104
// RVA: 0x46D70
void __fastcall Render::DisplayTrack::Draw(Render::DisplayTrack *this, Render::View *view, const float t, float track_alpha)
{
  Illusion::Texture *v4; // rdi
  Render::View *v5; // rsi
  Render::DisplayTrack *v6; // rbx
  float v7; // xmm15_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  UFG::qVector2 *v11; // rax
  UFG::LinearGraph<UFG::qVector3> *v12; // rcx
  UFG::qVector3 *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::LinearGraph<float> *v17; // rcx
  UFG::LinearGraph<float> *v18; // rcx
  UFG::LinearGraph<UFG::qVector2> *v19; // rcx
  UFG::qVector2 *v20; // rax
  SB_TextureAnim *v21; // rax
  float v22; // xmm9_4
  float v23; // xmm10_4
  bool v24; // zf
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm14_4
  float v28; // xmm13_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  Illusion::Target *v32; // rax
  float v33; // xmm7_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm8_4
  float v37; // xmm8_4
  float v38; // xmm0_4
  float v39; // xmm7_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  float v42; // xmm8_4
  float v43; // xmm4_4
  SB_TextureAnim *v44; // rax
  Illusion::Material *v45; // r8
  float v46; // [rsp+30h] [rbp-B8h]
  float v47; // [rsp+34h] [rbp-B4h]
  float X; // [rsp+38h] [rbp-B0h]
  Render::Poly poly; // [rsp+40h] [rbp-A8h]
  UFG::qColour colour; // [rsp+48h] [rbp-A0h]
  UFG::qVector3 v51; // [rsp+58h] [rbp-90h]
  UFG::qVector2 p0; // [rsp+68h] [rbp-80h]
  UFG::qVector2 p1; // [rsp+70h] [rbp-78h]
  UFG::qVector2 p2; // [rsp+78h] [rbp-70h]
  UFG::qVector2 result; // [rsp+138h] [rbp+50h]
  float v56; // [rsp+150h] [rbp+68h]

  v4 = this->mTexture;
  v5 = view;
  v6 = this;
  colour.r = 1.0;
  colour.g = 1.0;
  colour.b = 1.0;
  v7 = FLOAT_1_2;
  v56 = FLOAT_1_2;
  v46 = 0.0;
  result.x = 0.0;
  v8 = t;
  X = 0.0;
  colour.a = track_alpha;
  if ( v4 || this->mMaterial )
  {
    v9 = this->mTrackLength;
    if ( t > v9 )
    {
      v10 = this->mTrackLoopPoint;
      v8 = fmodf(t - v10, v9 - v10) + v10;
    }
    if ( v6->mPosition )
    {
      v11 = UFG::LinearGraph<UFG::qVector2>::GetValue(v6->mPosition, &result, v8);
      v46 = v11->x;
      result.x = v11->y;
    }
    v12 = v6->mColour;
    if ( v12 )
    {
      v13 = UFG::LinearGraph<UFG::qVector3>::GetValue(v12, &v51, v8);
      v14 = v13->x;
      v15 = v13->y;
      v16 = v13->z;
      colour.a = 1.0;
      colour.r = v14;
      colour.g = v15;
      colour.b = v16;
    }
    v17 = v6->mAlpha;
    if ( v17 )
      colour.a = UFG::LinearGraph<float>::GetValue(v17, v8) * track_alpha;
    v18 = v6->mRotation;
    if ( v18 )
      X = UFG::LinearGraph<float>::GetValue(v18, v8);
    v19 = v6->mScale;
    if ( v19 )
    {
      v20 = UFG::LinearGraph<UFG::qVector2>::GetValue(v19, (UFG::qVector2 *)&v51, v8);
      v7 = v20->x;
      v56 = v20->y;
    }
    v21 = v6->mTexAnimation;
    v22 = (float)v4->mWidth;
    v23 = (float)v4->mHeight;
    if ( v21 )
    {
      v22 = v22 / v21->UVSpeedAndUVNumPages[2];
      v23 = v23 / v21->UVSpeedAndUVNumPages[3];
    }
    v24 = v6->mCentre == 0;
    v47 = 0.0;
    v51.x = 0.0;
    if ( !v24 )
    {
      v25 = v22 * 0.5;
      v22 = v22 - (float)(v22 * 0.5);
      v26 = v23 * 0.5;
      LODWORD(v47) = LODWORD(v25) ^ _xmm[0];
      v23 = v23 - (float)(v23 * 0.5);
      LODWORD(v51.x) = LODWORD(v26) ^ _xmm[0];
    }
    v27 = 1.0 / (float)Render::GetBackBufferTarget()->mHeight;
    v28 = 1.0 / (float)Render::GetBackBufferTarget()->mWidth;
    if ( Render::GetRenderFeatures()->mForceLetterBox )
    {
      v29 = Render::gScreenViewportScaleV;
      v30 = (float)Render::GetBackBufferTarget()->mHeight * v29;
      v31 = Render::gScreenViewportScaleH;
      v32 = Render::GetBackBufferTarget();
      v27 = 1.0 / v30;
      v33 = Render::gScreenViewportScaleH;
      v34 = (float)v32->mWidth * v31;
      v35 = Render::gScreenViewportScaleV;
      v28 = 1.0 / v34;
      v36 = (float)((float)Render::GetBackBufferTarget()->mHeight * v35) * 0.00092592591;
      v7 = v7 * (float)((float)((float)Render::GetBackBufferTarget()->mWidth * v33) * 0.00052083336);
      v56 = v56 * v36;
    }
    v37 = cosf(X);
    v38 = sinf(X);
    v39 = v37 * v47;
    v40 = v37 * v51.x;
    v41 = v37;
    v42 = v37 * v23;
    v43 = v41 * v22;
    p1.x = (float)((float)((float)(v43 - (float)(v38 * v51.x)) * v7) * v28) + v46;
    p2.x = (float)((float)((float)(v43 - (float)(v38 * v23)) * v7) * v28) + v46;
    p1.y = (float)((float)((float)((float)(v38 * v22) + v40) * v56) * v27) + result.x;
    p0.x = (float)((float)((float)(v39 - (float)(v38 * v23)) * v7) * v28) + v46;
    p2.y = (float)((float)((float)(v42 + (float)(v38 * v22)) * v56) * v27) + result.x;
    p0.y = (float)((float)((float)(v42 + (float)(v38 * v47)) * v56) * v27) + result.x;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::Poly::SetScreenPos(&poly, &p0, &p1, &p2, &p0, 0.0);
    Render::Poly::SetColour(&poly, &colour);
    v44 = v6->mTexAnimation;
    if ( v44 )
      Render::Poly::SetUVs(&poly, 0.0, 0.0, 1.0 / v44->UVSpeedAndUVNumPages[2], 1.0 / v44->UVSpeedAndUVNumPages[3]);
    v45 = v6->mMaterial;
    if ( v45 )
      Render::View::Draw(v5, &poly, v45, 0i64);
    else
      Render::View::Draw(v5, &poly, v6->mTexture->mNode.mUID, 0i64, 0x62F81854u, v6->mAlphaStateUID);
  }
}

// File Line: 251
// RVA: 0x47770
void Render::LoadScreen::InitBackgroundImages(void)
{
  signed __int64 v0; // rcx
  Illusion::Material *v1; // rdi
  unsigned int v2; // er8
  __int64 v3; // rax
  Illusion::Material *v4; // rbx
  __int64 v5; // rax

  v0 = 7i64 * (unsigned int)(signed __int16)Render::LoadScreen::mBackgroundMaterialTexParamIndex;
  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    v1 = Render::LoadScreen::mBackgroundMaterial;
    v2 = Render::LoadScreen::mBackgroundImages->mBackgroundImage;
    if ( *(_DWORD *)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mNext + v0 * 8) != v2 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v0 + 1],
        *((_DWORD *)&Render::LoadScreen::mBackgroundMaterial[1].mNode + 2 * v0 + 12),
        v2);
      v3 = v1->mMaterialUser.mOffset;
      if ( v3 )
      {
        *(_WORD *)((char *)&v1->mMaterialUser.mOffset + v3) |= 0x20u;
        Render::LoadScreen::mBackgroundImageIndex = 0;
        return;
      }
      LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
    }
    Render::LoadScreen::mBackgroundImageIndex = 0;
  }
  else
  {
    v4 = Render::LoadScreen::mBackgroundMaterial;
    if ( *(_DWORD *)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mNext + v0 * 8) != -1 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v0 + 1],
        *((_DWORD *)&Render::LoadScreen::mBackgroundMaterial[1].mNode + 2 * v0 + 12),
        0xFFFFFFFF);
      v5 = v4->mMaterialUser.mOffset;
      if ( v5 )
        *(_WORD *)((char *)&v4->mMaterialUser.mOffset + v5) |= 0x20u;
      else
        LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
    }
  }
}

// File Line: 264
// RVA: 0x48670
void Render::LoadScreen::UpdateBackgroundImages(void)
{
  signed __int64 v0; // rax
  unsigned __int64 v1; // rax
  __int64 v2; // rcx

  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    if ( Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mDisplayStartTicks )
    {
      v1 = UFG::qGetTicks();
      if ( UFG::qGetTickTime(
             Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mDisplayStartTicks,
             v1) >= Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mRequiredTimeLength )
      {
        v2 = Render::LoadScreen::mBackgroundImageCount - 1;
        if ( Render::LoadScreen::mBackgroundImageIndex < (unsigned int)v2 )
        {
          if ( Render::LoadScreen::mBackgroundImageIndex + 1 < (unsigned int)v2 )
            v2 = Render::LoadScreen::mBackgroundImageIndex + 1;
          Render::LoadScreen::mBackgroundImageIndex = v2;
          Illusion::Material::UpdateParam(
            Render::LoadScreen::mBackgroundMaterial,
            Render::LoadScreen::mBackgroundMaterialTexParamIndex,
            0x8B43FABF,
            Render::LoadScreen::mBackgroundImages[v2].mBackgroundImage);
        }
      }
    }
    else
    {
      v0 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
      if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mPrev
                                                                     + v0 * 8) )
      {
        if ( !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v0 + 1]) )
          Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mDisplayStartTicks = UFG::qGetTicks();
      }
    }
  }
}

// File Line: 296
// RVA: 0x48070
void __fastcall Render::LoadScreen::RenderCallback(float delta_ms, void *param)
{
  char *v2; // rax
  Illusion::RenderPhase *v3; // rsi
  int v4; // edi
  _QWORD *v5; // ST50_8
  Render::ViewSettings *v6; // rax
  Illusion::Target *v7; // rbx
  char *vp_scissor; // r14
  Illusion::Target *v9; // rax
  char *v10; // rax
  char *v11; // r9
  float v12; // xmm6_4
  float *v13; // rax
  float *v14; // rbx
  Illusion::StateValues *v15; // rax
  signed __int64 v16; // rax
  float v17; // xmm2_4
  Render::DisplayTrack **v18; // rbx
  Render::View view; // [rsp+60h] [rbp-78h]
  __int64 v20; // [rsp+5E0h] [rbp+508h]
  char ptr; // [rsp+610h] [rbp+538h]
  int v22; // [rsp+E38h] [rbp+D60h]
  RenderQueueLayer *v23; // [rsp+E40h] [rbp+D68h]
  bool is_full_screen; // [rsp+EA8h] [rbp+DD0h]
  Render::Poly poly; // [rsp+EB8h] [rbp+DE0h]
  char *vars0; // [rsp+EC0h] [rbp+DE8h]

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v3 = (Illusion::RenderPhase *)v2;
  poly.mVertices = (Render::vDynamic *)v2;
  vars0 = v2;
  v4 = 0;
  if ( v2 )
  {
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    v5 = v2 + 16;
    *v5 = v5;
    v5[1] = v5;
    *((_QWORD *)v2 + 4) = 0i64;
  }
  Render::LoadScreen::mRenderLayer.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 16);
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)&view.mViewWorld.v2.z);
  v22 = 1;
  v23 = &Render::LoadScreen::mRenderLayer;
  v6 = Render::ViewSettings::GetIdentity();
  Render::View::View(&view, v6, (Illusion::SubmitContext *)&view.mViewWorld.v2.z);
  Render::View::GetStateValues(&view);
  v7 = Render::GetBackBufferTarget();
  if ( !g_Fullscreen )
    v7 = Render::GetPresentBufferTarget();
  vp_scissor = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  Render::GetBackBufferViewportScissor((Illusion::ViewportScissorState *)vp_scissor, &is_full_screen);
  if ( !is_full_screen )
  {
    Render::View::BeginTarget(&view, v7, "LoadScreen", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 0xFFu, 1.0, 0);
  }
  Render::View::BeginTarget(&view, v7, "LoadScreen", 0, 0, (Illusion::ViewportScissorState *)vp_scissor, 1, 0, 0, 0);
  Render::View::Clear(&view, &UFG::qColour::Black, 0xFFu, 1.0, 1u);
  if ( g_enable3D && g_Fullscreen )
  {
    Render::View::EndTarget(&view);
    v9 = Render::Get3DTarget(gCurrentEye);
    Render::View::BeginTarget(&view, v9, "FinalPresent", 0, 0, (Illusion::ViewportScissorState *)vp_scissor, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 1u, 1.0, 0);
    v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    v11 = v10;
    poly.mVertices = (Render::vDynamic *)v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = gCurrentEye;
      *((_QWORD *)v10 + 1) = Render::ConvergeFunction;
    }
    else
    {
      v11 = 0i64;
    }
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&view.mViewWorld.v2.z, 17, 0, v11);
  }
  `Render::LoadScreen::RenderCallback'::`10'::elapsed_time = `Render::LoadScreen::RenderCallback'::`10'::elapsed_time
                                                           + delta_ms;
  v12 = `Render::LoadScreen::RenderCallback'::`10'::elapsed_time;
  v13 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v14 = v13;
  *v13 = v12;
  v13[1] = delta_ms;
  v15 = Render::View::GetStateValues(&view);
  v15->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v15->mParamValues[13] = v14;
  Render::LoadScreen::UpdateBackgroundImages();
  v16 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
  if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mPrev
                                                                 + v16 * 8)
    && !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v16 + 1]) )
  {
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&view, &poly, Render::LoadScreen::mBackgroundMaterial, 0i64);
  }
  v17 = Render::LoadScreen::mTrackTime + delta_ms;
  Render::LoadScreen::mTrackTime = Render::LoadScreen::mTrackTime + delta_ms;
  if ( Render::LoadScreen::mDrawTracks && Render::LoadScreen::mNumDisplayTracks > 0 )
  {
    v18 = Render::LoadScreen::mDisplayTrack;
    while ( 1 )
    {
      Render::DisplayTrack::Draw(*v18, &view, v17, 1.0);
      ++v4;
      ++v18;
      if ( v4 >= Render::LoadScreen::mNumDisplayTracks )
        break;
      v17 = Render::LoadScreen::mTrackTime;
    }
  }
  Render::View::EndTarget(&view);
  RenderQueueLayer::SerializeRenderQueues(&Render::LoadScreen::mRenderLayer);
  Illusion::RenderQueueSystem::FlushRenderPhase(v3, 1u, 0, 0i64, 0);
  poly.mVertices = (Render::vDynamic *)&v20;
  `eh vector destructor iterator'(
    &ptr,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

// File Line: 397
// RVA: 0x472D0
void __fastcall Render::LoadScreen::DrawLoadScreen(void *param)
{
  __int128 v1; // xmm6
  Render *v2; // rcx
  signed __int64 v3; // rax
  __int128 v4; // xmm0
  unsigned __int64 v5; // rbx
  Render *v6; // rcx
  unsigned __int64 v7; // rax

  v1 = LODWORD(FLOAT_0_16);
  Render::LoadScreen::mDrawLoadScreen = 2;
  Render::AcquireDeferredContextForThread((Render *)param);
  for ( ; Render::LoadScreen::mDrawLoadScreen == 2; v1 = v4 )
  {
    v3 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
    if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mPrev
                                                                   + v3 * 8) )
      UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v3 + 1]);
    v4 = v1;
    v5 = UFG::qGetTicks();
    Render::RenderFrame(*(float *)&v1, v6);
    v7 = UFG::qGetTicks();
    *(float *)&v4 = UFG::qGetTickTime(v5, v7);
  }
  Render::ReleaseDeferredContextForThread(v2);
}

// File Line: 434
// RVA: 0x1454770
__int64 dynamic_initializer_for__Render::LoadScreen::mThread__()
{
  UFG::qThread::qThread(&Render::LoadScreen::mThread, "DrawLoadScreen");
  return atexit(dynamic_atexit_destructor_for__Render::LoadScreen::mThread__);
}

// File Line: 435
// RVA: 0x1454750
__int64 dynamic_initializer_for__Render::LoadScreen::mRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&Render::LoadScreen::mRenderLayer);
  return atexit(dynamic_atexit_destructor_for__Render::LoadScreen::mRenderLayer__);
}

// File Line: 461
// RVA: 0x47850
void __fastcall Render::InitLoadScreen(Render::LoadScreenInitParams *params)
{
  Render::LoadScreenInitParams *v1; // rsi
  unsigned int v2; // eax
  Illusion::Material *v3; // rdi
  int v4; // ebx
  UFG::qResourceWarehouse *v5; // rax
  unsigned int v6; // ebx
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  unsigned int v9; // ecx
  __int64 v10; // rcx
  const char *v11; // rdi
  unsigned int v12; // ebp
  UFG::qResourceData *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **v15; // rbx
  int v16; // xmm0_4
  Illusion::Material *v17; // rdi
  int v18; // ebx
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // eax
  int v21; // ebx
  int v22; // er9
  unsigned int i; // edx
  signed __int64 v24; // rax
  int v25; // er8
  __int64 v26; // rcx

  v1 = params;
  v2 = UFG::qStringHashUpper32("LoadingBackground", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("LoadingBackground", v2, 4u, 0i64, 0i64, 0i64);
  v4 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v3[1].mTypeUID = -1957338719;
  LODWORD(v3[1].mResourceHandles.mNode.mNext) = v4;
  *(_WORD *)&v3[1].mDebugName[12] = 0;
  *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v3[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v3[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v3[1].mStateBlockMask.mFlags[0]) = 0;
  LOWORD(v3[1].mMaterialUser.mOffset) = 0;
  *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v3[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.mNode.mPrev) = 315097330;
  v3[2].mNode.mUID = 662883558;
  LOWORD(v3[2].mTypeUID) = 0;
  HIDWORD(v3[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v3[2].0 + 22) = 1002903008;
  *(_DWORD *)&v3[2].mDebugName[28] = 1660426324;
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v5, (UFG::qResourceData *)&v3->mNode);
  Render::LoadScreen::mBackgroundMaterial = v3;
  Render::LoadScreen::mBackgroundMaterialTexParamIndex = 1;
  if ( !(_S1_9 & 1) )
  {
    _S1_9 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&StaticImageTexture.mPrev);
    atexit(Render::InitLoadScreen_::_4_::_dynamic_atexit_destructor_for__StaticImageTexture__);
  }
  v6 = UFG::qStringHashUpper32(v1->mBackgroundName.mData, 0xFFFFFFFF);
  v7 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&StaticImageTexture.mPrev, 0x8B43FABF, v6, v7);
  v9 = _S1_9;
  if ( !(_S1_9 & 2) )
  {
    v9 = _S1_9 | 2;
    _S1_9 |= 2u;
    StaticImageTrack.mTexture = (Illusion::Texture *)StaticImageTexture.mData;
    StaticImageTrack.mAlphaStateUID = -1551679522;
    StaticImageTrack.mTrackLoopPoint = 0.0;
    *(_QWORD *)&StaticImageTrack.mTrackLength = 0x40000000i64;
    StaticImageTrack.mMaterial = 0i64;
    _mm_store_si128((__m128i *)&StaticImageTrack, (__m128i)0i64);
    StaticImageTrack.mRotation = 0i64;
    StaticImageTrack.mScale = 0i64;
    StaticImageTrack.mAlpha = 0i64;
    StaticImageTrack.mTexAnimation = 0i64;
  }
  if ( !(v9 & 4) )
  {
    v9 |= 4u;
    _S1_9 = v9;
    StaticBgScale[0].x = v1->mBackgroundScale;
    dword_142135754 = LODWORD(StaticBgScale[0].x);
  }
  if ( !(v9 & 8) )
  {
    v9 |= 8u;
    _S1_9 = v9;
    position_graph.nData = 1;
    position_graph.fDomain = x_axis_keyframes;
    position_graph.tRange = StaticBgPosition;
  }
  if ( !(v9 & 0x10) )
  {
    _S1_9 = v9 | 0x10;
    scale_graph.nData = 1;
    scale_graph.fDomain = x_axis_keyframes;
    scale_graph.tRange = StaticBgScale;
  }
  StaticImageTrack.mPosition = &position_graph;
  StaticImageTrack.mScale = &scale_graph;
  StaticImageTrack.mCentre = 1;
  v10 = Render::LoadScreen::mNumDisplayTracks;
  Render::LoadScreen::mDisplayTrack[v10] = &StaticImageTrack;
  Render::LoadScreen::mNumDisplayTracks = v10 + 1;
  v11 = v1->mAnimationName.mData;
  v12 = UFG::qStringHashUpper32(v1->mAnimationName.mData, 0xFFFFFFFF);
  v13 = (UFG::qResourceData *)Illusion::Factory::NewStateBlock(v11, v12, 1u, 0x20u, 0i64, 0i64, 0i64);
  v14 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v14, v13);
  v15 = &v13[1].mResourceHandles.mNode.mNext;
  UFG::qMemSet(v15, 0, 0x20u);
  *(float *)v15 = v1->mFlipbookHorizSpeed;
  *((_DWORD *)v15 + 1) = LODWORD(v1->mFlipbookVertSpeed);
  *((float *)v15 + 2) = (float)v1->mNumFlipbookPagesHoriz;
  *((float *)v15 + 3) = (float)v1->mNumFlipbookPagesVert;
  if ( v1->mFlipbookEnabled )
    v16 = (signed int)FLOAT_1_0;
  else
    v16 = 0;
  *((_DWORD *)v15 + 4) = v16;
  v17 = Illusion::Factory::NewMaterial(v11, v12, 5u, 0i64, 0i64, 0i64);
  v18 = UFG::qStringHash32("LOADSPINNER", 0xFFFFFFFF);
  LOWORD(v17[1].mNode.mChild[0]) = 0;
  HIDWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v17[1].mTypeUID = -1957338719;
  LODWORD(v17[1].mResourceHandles.mNode.mNext) = v18;
  *(_WORD *)&v17[1].mDebugName[12] = 0;
  *(_DWORD *)&v17[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v17[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v17[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v17[1].mStateBlockMask.mFlags[0]) = v12;
  LOWORD(v17[1].mMaterialUser.mOffset) = 0;
  *(&v17[1].mNumParams + 1) = UFG::qStringHash32("sbTextureAnim", 0xFFFFFFFF);
  v17[1].mNumParams = UFG::qStringHash32("sbTextureAnim", 0xFFFFFFFF);
  LODWORD(v17[2].mResourceHandles.mNode.mPrev) = 1292158962;
  v17[2].mNode.mUID = v12;
  LOWORD(v17[2].mTypeUID) = 0;
  HIDWORD(v17[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v17[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v17[2].0 + 22) = 315097330;
  *(_DWORD *)&v17[2].mDebugName[28] = -1551679522;
  LOWORD(v17[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v17[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v17[3].mNode.mChild[0]) = 1660426324;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v17->mNode);
  v20 = _S1_9;
  if ( !(_S1_9 & 0x20) )
  {
    _S1_9 |= 0x20u;
    StaticImageTrack_0.mTexture = 0i64;
    *(_OWORD *)&StaticImageTrack_0.mMaterial = (unsigned __int64)v17;
    *(_QWORD *)&StaticImageTrack_0.mAlphaStateUID = 0i64;
    *(_QWORD *)&StaticImageTrack_0.mTrackLength = 0x40000000i64;
    _mm_store_si128((__m128i *)&StaticImageTrack_0, (__m128i)0i64);
    StaticImageTrack_0.mRotation = 0i64;
    StaticImageTrack_0.mScale = 0i64;
    StaticImageTrack_0.mAlpha = 0i64;
    v21 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
    v22 = UFG::qStringHash32("sbTextureAnim", 0xFFFFFFFF);
    for ( i = 0; i < StaticImageTrack_0.mMaterial->mNumParams; ++i )
    {
      v24 = 56i64 * i;
      v25 = *(_DWORD *)((char *)&StaticImageTrack_0.mMaterial[1].mNode.mParent + v24);
      if ( v25 == v21 )
      {
        StaticImageTrack_0.mTexture = *(Illusion::Texture **)((char *)&StaticImageTrack_0.mMaterial[1].mResourceHandles.mNode.mPrev
                                                            + v24);
      }
      else if ( v25 == v22 )
      {
        StaticImageTrack_0.mTexAnimation = (SB_TextureAnim *)&(*(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&StaticImageTrack_0.mMaterial[1].mResourceHandles.mNode.mPrev + v24))[8];
      }
    }
    v20 = _S1_9;
  }
  if ( !(v20 & 0x40) )
  {
    v20 |= 0x40u;
    _S1_9 = v20;
    rotation_values[0] = 0.0;
    dword_1421357E4 = LODWORD(FLOAT_6_2831855);
  }
  if ( (v20 & 0x80u) == 0 )
  {
    v20 |= 0x80u;
    _S1_9 = v20;
    StaticScale[0].x = v1->mAnimationScale;
    dword_1421357EC = LODWORD(StaticScale[0].x);
  }
  if ( !_bittest((const signed int *)&v20, 8u) )
  {
    v20 |= 0x100u;
    _S1_9 = v20;
    position_graph_0.nData = 1;
    position_graph_0.fDomain = x_axis_keyframes_0;
    position_graph_0.tRange = SpinnerPosition;
  }
  if ( !_bittest((const signed int *)&v20, 9u) )
  {
    v20 |= 0x200u;
    _S1_9 = v20;
    rotation_graph.nData = 2;
    rotation_graph.fDomain = x_axis_keyframes_0;
    rotation_graph.tRange = rotation_values;
  }
  if ( !_bittest((const signed int *)&v20, 0xAu) )
  {
    v20 |= 0x400u;
    _S1_9 = v20;
    scale_graph_0.nData = 1;
    scale_graph_0.fDomain = x_axis_keyframes_0;
    scale_graph_0.tRange = StaticScale;
  }
  if ( !_bittest((const signed int *)&v20, 0xBu) )
  {
    _S1_9 = v20 | 0x800;
    colour_graph.nData = 1;
    colour_graph.fDomain = x_axis_keyframes_0;
    colour_graph.tRange = StaticSpinnerColour;
  }
  StaticImageTrack_0.mPosition = &position_graph_0;
  if ( 0.0 == v1->mRotationEnabled )
    StaticImageTrack_0.mRotation = 0i64;
  else
    StaticImageTrack_0.mRotation = &rotation_graph;
  StaticImageTrack_0.mScale = &scale_graph_0;
  StaticImageTrack_0.mColour = &colour_graph;
  StaticImageTrack_0.mCentre = 1;
  v26 = Render::LoadScreen::mNumDisplayTracks;
  Render::LoadScreen::mDisplayTrack[v26] = &StaticImageTrack_0;
  Render::LoadScreen::mNumDisplayTracks = v26 + 1;
  Render::LoadScreen::mEnable = 1;
}

// File Line: 545
// RVA: 0x484D0
void __fastcall Render::StartLoadScreen(Render::LoadScreenParams *pParams)
{
  Render::LoadScreenParams *v1; // rbx
  Render::RenderCallbacks *v2; // rax

  v1 = pParams;
  if ( Render::LoadScreen::mEnable && Render::LoadScreen::mDrawLoadScreen == DONT_DRAW )
  {
    Render::LoadScreen::mSavedNumDisplayTracks = Render::LoadScreen::mNumDisplayTracks;
    SpinnerPosition[0].x = pParams->mSpinnerPosX;
    dword_1421356B4 = LODWORD(pParams->mSpinnerPosY);
    StaticImagePosition[0].x = pParams->mSpinnerPosX;
    dword_1421356BC = LODWORD(pParams->mSpinnerPosY);
    StaticBgPosition[0].x = pParams->mSpinnerPosX - 0.050000001;
    *(float *)&dword_1421356C4 = pParams->mSpinnerPosY - 0.145;
    if ( Render::LoadScreen::mFadeOutTime <= 0.0 )
      Render::LoadScreen::mTrackTime = 0.0;
    Render::LoadScreen::mFadeOutRange = 0.0;
    Render::LoadScreen::mFadeOutTime = 0.0;
    Render::LoadScreen::mBackgroundImages = pParams->mBackgroundImages;
    Render::LoadScreen::mBackgroundImageCount = pParams->mBackgroundImageCount;
    Render::LoadScreen::mDrawTracks = pParams->mDrawSpinner;
    Render::LoadScreen::InitBackgroundImages();
    if ( v1->mbThreadedRender )
    {
      v2 = Render::GetRenderCallbacks();
      Render::LoadScreen::mSavedRenderFunc = v2->mRenderWorldFunc;
      v2->mRenderWorldFunc = Render::LoadScreen::RenderCallback;
      UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&Render::LoadScreen::mThread, 0x4000u);
      UFG::qThread::Start(&Render::LoadScreen::mThread, Render::LoadScreen::DrawLoadScreen, 0i64);
    }
    else
    {
      Render::LoadScreen::mDrawLoadScreen = 1;
    }
  }
}

// File Line: 598
// RVA: 0x48050
_BOOL8 __fastcall Render::IsLoadScreenRendering()
{
  return Render::LoadScreen::mDrawLoadScreen || Render::LoadScreen::mEmergencyEnable;
}

// File Line: 603
// RVA: 0x48780
void __fastcall Render::UpdateRenderLoadScreen(Render::View *view, float delta_ms)
{
  float v2; // xmm7_4
  Render::View *v3; // rsi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  int v8; // ebx
  Render::DisplayTrack **v9; // rdi
  float v10; // xmm6_4
  float *v11; // rax
  float *v12; // rbx
  Illusion::StateValues *v13; // rax
  signed __int64 v14; // rax
  float v15; // xmm2_4
  int v16; // eax
  int v17; // ebx
  Render::DisplayTrack **v18; // rdi
  Render::DisplayTrack *v19; // rcx
  Render::Poly poly; // [rsp+60h] [rbp+18h]

  v2 = delta_ms;
  v3 = view;
  if ( delta_ms >= 0.033333335 )
    v2 = FLOAT_0_033333335;
  v4 = Render::LoadScreen::mFadeOutTime - v2;
  Render::LoadScreen::mFadeOutTime = Render::LoadScreen::mFadeOutTime - v2;
  if ( Render::LoadScreen::mFadeOutTime > 0.0 )
  {
    v5 = Render::LoadScreen::mTrackTime + v2;
    Render::LoadScreen::mTrackTime = Render::LoadScreen::mTrackTime + v2;
    if ( !Render::LoadScreen::mDrawTracks )
      return;
    v6 = v4 / Render::LoadScreen::mFadeOutRange;
    if ( v6 <= 0.0 )
    {
      v6 = 0.0;
    }
    else
    {
      v7 = *(float *)&FLOAT_1_0;
      if ( v6 >= 1.0 )
      {
LABEL_10:
        v8 = 0;
        if ( Render::LoadScreen::mNumDisplayTracks > 0 )
        {
          v9 = Render::LoadScreen::mDisplayTrack;
          while ( 1 )
          {
            Render::DisplayTrack::Draw(*v9, v3, v5, v7);
            ++v8;
            ++v9;
            if ( v8 >= Render::LoadScreen::mNumDisplayTracks )
              break;
            v5 = Render::LoadScreen::mTrackTime;
          }
        }
        return;
      }
    }
    v7 = v6;
    goto LABEL_10;
  }
  if ( Render::LoadScreen::mDrawLoadScreen == 1 || Render::LoadScreen::mEmergencyEnable )
  {
    elapsed_time = elapsed_time + v2;
    v10 = elapsed_time;
    v11 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    v12 = v11;
    *v11 = v10;
    v11[1] = v2;
    v13 = Render::View::GetStateValues(v3);
    v13->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v13->mParamValues[13] = v12;
    Render::LoadScreen::UpdateBackgroundImages();
    v14 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
    if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.mNode.mPrev
                                                                   + v14 * 8)
      && !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v14 + 1]) )
    {
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(v3, &poly, Render::LoadScreen::mBackgroundMaterial, 0i64);
    }
    v15 = Render::LoadScreen::mTrackTime + v2;
    Render::LoadScreen::mTrackTime = Render::LoadScreen::mTrackTime + v2;
    if ( Render::LoadScreen::mDrawTracks )
    {
      v16 = Render::LoadScreen::mNumDisplayTracks;
      v17 = 0;
      if ( Render::LoadScreen::mNumDisplayTracks > 0 )
      {
        v18 = Render::LoadScreen::mDisplayTrack;
        do
        {
          v19 = *v18;
          if ( *v18 && v19->mTexture )
          {
            Render::DisplayTrack::Draw(v19, v3, v15, 1.0);
            v15 = Render::LoadScreen::mTrackTime;
            v16 = Render::LoadScreen::mNumDisplayTracks;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < v16 );
      }
    }
  }
  else
  {
    Render::LoadScreen::mFadeOutRange = 0.0;
    Render::LoadScreen::mFadeOutTime = 0.0;
  }
}

// File Line: 654
// RVA: 0x48620
void __fastcall Render::StopLoadScreen(Render *this)
{
  bool v1; // zf

  if ( Render::LoadScreen::mEnable )
  {
    v1 = Render::LoadScreen::mDrawLoadScreen == 2;
    Render::LoadScreen::mDrawLoadScreen = 0;
    Render::LoadScreen::mNumDisplayTracks = Render::LoadScreen::mSavedNumDisplayTracks;
    if ( v1 )
    {
      UFG::qThread::WaitForCompletion(&Render::LoadScreen::mThread);
      Render::GetRenderCallbacks()->mRenderWorldFunc = Render::LoadScreen::mSavedRenderFunc;
    }
  }
}

// File Line: 674
// RVA: 0x484C0
void __fastcall Render::StartEmergencyLoadScreen(Render *this)
{
  Render::LoadScreen::mEmergencyEnable = 1;
}

// File Line: 679
// RVA: 0x48610
void __fastcall Render::StopEmergencyLoadScreen(Render *this)
{
  Render::LoadScreen::mEmergencyEnable = 0;
}

// File Line: 684
// RVA: 0x47370
void __fastcall Render::FadeLoadScreen(float fade_out_secs)
{
  Render::LoadScreen::mFadeOutTime = fade_out_secs;
  LODWORD(Render::LoadScreen::mFadeOutRange) = (_DWORD)FLOAT_1_0;
}

// File Line: 691
// RVA: 0x476B0
bool __fastcall Render::HasMinLoadScreenTimeExpired()
{
  unsigned int v0; // edx
  char v1; // di
  unsigned int v2; // ebx
  Render::BackgroundImage *v3; // rcx
  unsigned __int64 v4; // rax
  float v5; // xmm0_4

  v0 = Render::LoadScreen::mBackgroundImageCount;
  v1 = 0;
  v2 = 0;
  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    v3 = Render::LoadScreen::mBackgroundImages;
    do
    {
      if ( v3[v2].mDisplayStartTicks <= 0 )
      {
        if ( v3[v2].mRequiredTimeLength > 0.0 )
          v1 = 1;
      }
      else
      {
        v4 = UFG::qGetTicks();
        v5 = UFG::qGetTickTime(Render::LoadScreen::mBackgroundImages[v2].mDisplayStartTicks, v4);
        v3 = Render::LoadScreen::mBackgroundImages;
        v0 = Render::LoadScreen::mBackgroundImageCount;
        v1 |= v5 <= Render::LoadScreen::mBackgroundImages[v2].mRequiredTimeLength;
      }
      ++v2;
    }
    while ( v2 < v0 );
  }
  return v1 == 0;
}

// File Line: 709
// RVA: 0x48490
void __fastcall Render::SetLoadScreenSpinnerTint(UFG::qColour *tint)
{
  float v1; // xmm1_4
  float v2; // xmm2_4

  v1 = tint->g;
  v2 = tint->b;
  StaticSpinnerColour[0].x = tint->r;
  dword_142022FE4 = LODWORD(v1);
  dword_142022FE8 = LODWORD(v2);
}

