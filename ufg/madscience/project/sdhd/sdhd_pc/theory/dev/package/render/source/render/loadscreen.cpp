// File Line: 104
// RVA: 0x46D70
void __fastcall Render::DisplayTrack::Draw(Render::DisplayTrack *this, Render::View *view, float t, float track_alpha)
{
  Illusion::Texture *mTexture; // rdi
  float v7; // xmm15_4
  float v8; // xmm7_4
  float mTrackLength; // xmm1_4
  float mTrackLoopPoint; // xmm6_4
  UFG::qVector2 *Value; // rax
  UFG::LinearGraph<UFG::qVector3> *mColour; // rcx
  UFG::qVector3 *v13; // rax
  float v14; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::LinearGraph<float> *mAlpha; // rcx
  UFG::LinearGraph<float> *mRotation; // rcx
  UFG::LinearGraph<UFG::qVector2> *mScale; // rcx
  UFG::qVector2 *v20; // rax
  SB_TextureAnim *mTexAnimation; // rax
  float mWidth; // xmm9_4
  float mHeight; // xmm10_4
  bool v24; // zf
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm14_4
  float v28; // xmm13_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  Illusion::Target *BackBufferTarget; // rax
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
  Illusion::Material *mMaterial; // r8
  float v46; // [rsp+30h] [rbp-B8h]
  float v47; // [rsp+34h] [rbp-B4h]
  float X; // [rsp+38h] [rbp-B0h]
  Render::Poly poly; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qColour colour; // [rsp+48h] [rbp-A0h] BYREF
  UFG::qVector3 v51; // [rsp+58h] [rbp-90h] BYREF
  UFG::qVector2 p0; // [rsp+68h] [rbp-80h] BYREF
  UFG::qVector2 p1; // [rsp+70h] [rbp-78h] BYREF
  UFG::qVector2 p2; // [rsp+78h] [rbp-70h] BYREF
  UFG::qVector2 result; // [rsp+138h] [rbp+50h] BYREF
  float v56; // [rsp+150h] [rbp+68h]

  mTexture = this->mTexture;
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
  if ( __PAIR128__(this->mMaterial, (unsigned __int64)mTexture) != 0 )
  {
    mTrackLength = this->mTrackLength;
    if ( t > mTrackLength )
    {
      mTrackLoopPoint = this->mTrackLoopPoint;
      v8 = fmodf(t - mTrackLoopPoint, mTrackLength - mTrackLoopPoint) + mTrackLoopPoint;
    }
    if ( this->mPosition )
    {
      Value = UFG::LinearGraph<UFG::qVector2>::GetValue(this->mPosition, &result, v8);
      v46 = Value->x;
      result.x = Value->y;
    }
    mColour = this->mColour;
    if ( mColour )
    {
      v13 = UFG::LinearGraph<UFG::qVector3>::GetValue(mColour, &v51, v8);
      v14 = v13->x;
      y = v13->y;
      z = v13->z;
      colour.a = 1.0;
      colour.r = v14;
      colour.g = y;
      colour.b = z;
    }
    mAlpha = this->mAlpha;
    if ( mAlpha )
      colour.a = UFG::LinearGraph<float>::GetValue(mAlpha, v8) * track_alpha;
    mRotation = this->mRotation;
    if ( mRotation )
      X = UFG::LinearGraph<float>::GetValue(mRotation, v8);
    mScale = this->mScale;
    if ( mScale )
    {
      v20 = UFG::LinearGraph<UFG::qVector2>::GetValue(mScale, (UFG::qVector2 *)&v51, v8);
      v7 = v20->x;
      v56 = v20->y;
    }
    mTexAnimation = this->mTexAnimation;
    mWidth = (float)mTexture->mWidth;
    mHeight = (float)mTexture->mHeight;
    if ( mTexAnimation )
    {
      mWidth = mWidth / mTexAnimation->UVSpeedAndUVNumPages[2];
      mHeight = mHeight / mTexAnimation->UVSpeedAndUVNumPages[3];
    }
    v24 = this->mCentre == 0;
    v47 = 0.0;
    v51.x = 0.0;
    if ( !v24 )
    {
      v25 = mWidth * 0.5;
      mWidth = mWidth - (float)(mWidth * 0.5);
      v26 = mHeight * 0.5;
      LODWORD(v47) = LODWORD(v25) ^ _xmm[0];
      mHeight = mHeight - (float)(mHeight * 0.5);
      LODWORD(v51.x) = LODWORD(v26) ^ _xmm[0];
    }
    v27 = 1.0 / (float)Render::GetBackBufferTarget()->mHeight;
    v28 = 1.0 / (float)Render::GetBackBufferTarget()->mWidth;
    if ( Render::GetRenderFeatures()->mForceLetterBox )
    {
      v29 = Render::gScreenViewportScaleV;
      v30 = (float)Render::GetBackBufferTarget()->mHeight * v29;
      v31 = Render::gScreenViewportScaleH;
      BackBufferTarget = Render::GetBackBufferTarget();
      v27 = 1.0 / v30;
      v33 = Render::gScreenViewportScaleH;
      v34 = (float)BackBufferTarget->mWidth * v31;
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
    v42 = v37 * mHeight;
    v43 = v41 * mWidth;
    p1.x = (float)((float)((float)(v43 - (float)(v38 * v51.x)) * v7) * v28) + v46;
    p2.x = (float)((float)((float)(v43 - (float)(v38 * mHeight)) * v7) * v28) + v46;
    p1.y = (float)((float)((float)((float)(v38 * mWidth) + v40) * v56) * v27) + result.x;
    p0.x = (float)((float)((float)(v39 - (float)(v38 * mHeight)) * v7) * v28) + v46;
    p2.y = (float)((float)((float)(v42 + (float)(v38 * mWidth)) * v56) * v27) + result.x;
    p0.y = (float)((float)((float)(v42 + (float)(v38 * v47)) * v56) * v27) + result.x;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::Poly::SetScreenPos(&poly, &p0, &p1, &p2, &p0, 0.0);
    Render::Poly::SetColour(&poly, &colour);
    v44 = this->mTexAnimation;
    if ( v44 )
      Render::Poly::SetUVs(&poly, 0.0, 0.0, 1.0 / v44->UVSpeedAndUVNumPages[2], 1.0 / v44->UVSpeedAndUVNumPages[3]);
    mMaterial = this->mMaterial;
    if ( mMaterial )
      Render::View::Draw(view, &poly, mMaterial, 0i64);
    else
      Render::View::Draw(view, &poly, this->mTexture->mNode.mUID, 0i64, 0x62F81854u, this->mAlphaStateUID);
  }
}

// File Line: 251
// RVA: 0x47770
void Render::LoadScreen::InitBackgroundImages(void)
{
  __int64 v0; // rcx
  Illusion::Material *v1; // rdi
  unsigned int mBackgroundImage; // r8d
  __int64 mOffset; // rax
  Illusion::Material *v4; // rbx
  __int64 v5; // rax

  v0 = 7i64 * (unsigned int)(__int16)Render::LoadScreen::mBackgroundMaterialTexParamIndex;
  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    v1 = Render::LoadScreen::mBackgroundMaterial;
    mBackgroundImage = Render::LoadScreen::mBackgroundImages->mBackgroundImage;
    if ( *(_DWORD *)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext
                   + v0 * 8) != mBackgroundImage )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v0 + 1],
        *((_DWORD *)&Render::LoadScreen::mBackgroundMaterial[1].mNode + 2 * v0 + 12),
        mBackgroundImage);
      mOffset = v1->mMaterialUser.mOffset;
      if ( mOffset )
      {
        *(_WORD *)((char *)&v1->mMaterialUser.mOffset + mOffset) |= 0x20u;
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
    if ( *(_DWORD *)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext
                   + v0 * 8) != -1 )
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
  __int64 v0; // rax
  unsigned __int64 Ticks; // rax
  __int64 v2; // rcx

  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    if ( Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mDisplayStartTicks )
    {
      Ticks = UFG::qGetTicks();
      if ( UFG::qGetTickTime(
             Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mDisplayStartTicks,
             Ticks) >= Render::LoadScreen::mBackgroundImages[Render::LoadScreen::mBackgroundImageIndex].mRequiredTimeLength )
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
      if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev
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
  Render::ViewSettings *Identity; // rax
  Illusion::Target *BackBufferTarget; // rbx
  char *vp_scissor; // r14
  Illusion::Target *v8; // rax
  char *v9; // rax
  char *v10; // r9
  float v11; // xmm6_4
  float *v12; // rbx
  Illusion::StateValues *StateValues; // rax
  __int64 v14; // rax
  float v15; // xmm2_4
  Render::DisplayTrack **v16; // rbx
  Render::View view; // [rsp+60h] [rbp-78h] BYREF
  __int64 v18; // [rsp+5E0h] [rbp+508h] BYREF
  char ptr[2088]; // [rsp+610h] [rbp+538h] BYREF
  int v20; // [rsp+E38h] [rbp+D60h]
  RenderQueueLayer *v21; // [rsp+E40h] [rbp+D68h]
  bool is_full_screen; // [rsp+EA8h] [rbp+DD0h] BYREF
  Render::Poly poly; // [rsp+EB8h] [rbp+DE0h] BYREF
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
    *((_QWORD *)v2 + 2) = v2 + 16;
    *((_QWORD *)v2 + 3) = v2 + 16;
    *((_QWORD *)v2 + 4) = 0i64;
  }
  Render::LoadScreen::mRenderLayer.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 16);
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)&view.mViewWorld.v2.z);
  v20 = 1;
  v21 = &Render::LoadScreen::mRenderLayer;
  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&view, Identity, (Illusion::SubmitContext *)&view.mViewWorld.v2.z);
  Render::View::GetStateValues(&view);
  BackBufferTarget = Render::GetBackBufferTarget();
  if ( !g_Fullscreen )
    BackBufferTarget = Render::GetPresentBufferTarget();
  vp_scissor = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  Render::GetBackBufferViewportScissor((Illusion::ViewportScissorState *)vp_scissor, &is_full_screen);
  if ( !is_full_screen )
  {
    Render::View::BeginTarget(&view, BackBufferTarget, "LoadScreen", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 0xFFu, 1.0, 0);
  }
  Render::View::BeginTarget(
    &view,
    BackBufferTarget,
    "LoadScreen",
    0,
    0,
    (Illusion::ViewportScissorState *)vp_scissor,
    1,
    0,
    0,
    0);
  Render::View::Clear(&view, &UFG::qColour::Black, 0xFFu, 1.0, 1u);
  if ( g_enable3D && g_Fullscreen )
  {
    Render::View::EndTarget(&view);
    v8 = Render::Get3DTarget(gCurrentEye);
    Render::View::BeginTarget(&view, v8, "FinalPresent", 0, 0, (Illusion::ViewportScissorState *)vp_scissor, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 1u, 1.0, 0);
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    v10 = v9;
    poly.mVertices = (Render::vDynamic *)v9;
    if ( v9 )
    {
      *(_QWORD *)v9 = gCurrentEye;
      *((_QWORD *)v9 + 1) = Render::ConvergeFunction;
    }
    else
    {
      v10 = 0i64;
    }
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&view.mViewWorld.v2.z, 17, 0, v10);
  }
  `Render::LoadScreen::RenderCallback::`10::elapsed_time = `Render::LoadScreen::RenderCallback::`10::elapsed_time
                                                           + delta_ms;
  v11 = `Render::LoadScreen::RenderCallback::`10::elapsed_time;
  v12 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *v12 = v11;
  v12[1] = delta_ms;
  StateValues = Render::View::GetStateValues(&view);
  StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
  StateValues->mParamValues[13] = v12;
  Render::LoadScreen::UpdateBackgroundImages();
  v14 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
  if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev
                                                                 + v14 * 8)
    && !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v14 + 1]) )
  {
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&view, &poly, Render::LoadScreen::mBackgroundMaterial, 0i64);
  }
  v15 = Render::LoadScreen::mTrackTime + delta_ms;
  Render::LoadScreen::mTrackTime = Render::LoadScreen::mTrackTime + delta_ms;
  if ( Render::LoadScreen::mDrawTracks && Render::LoadScreen::mNumDisplayTracks > 0 )
  {
    v16 = Render::LoadScreen::mDisplayTrack;
    while ( 1 )
    {
      Render::DisplayTrack::Draw(*v16, &view, v15, 1.0);
      ++v4;
      ++v16;
      if ( v4 >= Render::LoadScreen::mNumDisplayTracks )
        break;
      v15 = Render::LoadScreen::mTrackTime;
    }
  }
  Render::View::EndTarget(&view);
  RenderQueueLayer::SerializeRenderQueues(&Render::LoadScreen::mRenderLayer);
  Illusion::RenderQueueSystem::FlushRenderPhase(v3, 1u, 0, 0i64, 0);
  poly.mVertices = (Render::vDynamic *)&v18;
  `eh vector destructor iterator(
    ptr,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

// File Line: 397
// RVA: 0x472D0
void __fastcall Render::LoadScreen::DrawLoadScreen(Render *param)
{
  __int128 v1; // xmm6
  Render *v2; // rcx
  __int64 v3; // rax
  __int128 v4; // xmm0
  unsigned __int64 Ticks; // rbx
  Render *v6; // rcx
  unsigned __int64 v7; // rax

  v1 = LODWORD(FLOAT_0_16);
  Render::LoadScreen::mDrawLoadScreen = SEPARATE_THREAD;
  Render::AcquireDeferredContextForThread(param);
  for ( ; Render::LoadScreen::mDrawLoadScreen == SEPARATE_THREAD; v1 = v4 )
  {
    v3 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
    if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev
                                                                   + v3 * 8) )
      UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v3 + 1]);
    v4 = v1;
    Ticks = UFG::qGetTicks();
    Render::RenderFrame(*(float *)&v1, v6);
    v7 = UFG::qGetTicks();
    *(float *)&v4 = UFG::qGetTickTime(Ticks, v7);
  }
  Render::ReleaseDeferredContextForThread(v2);
}

// File Line: 434
// RVA: 0x1454770
__int64 dynamic_initializer_for__Render::LoadScreen::mThread__()
{
  UFG::qThread::qThread(&Render::LoadScreen::mThread, "DrawLoadScreen");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::LoadScreen::mThread__);
}

// File Line: 435
// RVA: 0x1454750
__int64 dynamic_initializer_for__Render::LoadScreen::mRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&Render::LoadScreen::mRenderLayer);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::LoadScreen::mRenderLayer__);
}

// File Line: 461
// RVA: 0x47850
void __fastcall Render::InitLoadScreen(Render::LoadScreenInitParams *params)
{
  unsigned int v2; // eax
  Illusion::Material *v3; // rdi
  int v4; // ebx
  UFG::qResourceWarehouse *v5; // rax
  unsigned int v6; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  unsigned int v9; // ecx
  int v10; // ecx
  char *mData; // rdi
  unsigned int v12; // ebp
  UFG::qResourceData *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  float *p_mNext; // rbx
  int v16; // xmm0_4
  Illusion::Material *v17; // rdi
  int v18; // ebx
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // eax
  int v21; // ebx
  int v22; // r9d
  unsigned int i; // edx
  __int64 v24; // rax
  int v25; // r8d
  int v26; // ecx

  v2 = UFG::qStringHashUpper32("LoadingBackground", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("LoadingBackground", v2, 4u, 0i64, 0i64, 0i64);
  v4 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v3[1].mTypeUID = -1957338719;
  LODWORD(v3[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v4;
  *(_WORD *)&v3[1].mDebugName[12] = 0;
  *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v3[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v3[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v3[1].mStateBlockMask.mFlags[0]) = 0;
  LOWORD(v3[1].mMaterialUser.mOffset) = 0;
  *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v3[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v3[2].mNode.mUID = 662883558;
  LOWORD(v3[2].mTypeUID) = 0;
  HIDWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v3[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v3[2].mDebugName[28] = 1660426324;
  v5 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v5, v3);
  Render::LoadScreen::mBackgroundMaterial = v3;
  Render::LoadScreen::mBackgroundMaterialTexParamIndex = 1;
  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&StaticImageTexture);
    atexit(Render::InitLoadScreen_::_4_::_dynamic_atexit_destructor_for__StaticImageTexture__);
  }
  v6 = UFG::qStringHashUpper32(params->mBackgroundName.mData, 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&StaticImageTexture, 0x8B43FABF, v6, Inventory);
  v9 = _S1_9;
  if ( (_S1_9 & 2) == 0 )
  {
    v9 = _S1_9 | 2;
    _S1_9 |= 2u;
    StaticImageTrack.mTexture = (Illusion::Texture *)StaticImageTexture.mData;
    StaticImageTrack.mAlphaStateUID = -1551679522;
    StaticImageTrack.mTrackLoopPoint = 0.0;
    *(_QWORD *)&StaticImageTrack.mTrackLength = 0x40000000i64;
    StaticImageTrack.mMaterial = 0i64;
    *(_OWORD *)&StaticImageTrack.mPosition = 0i64;
    StaticImageTrack.mRotation = 0i64;
    StaticImageTrack.mScale = 0i64;
    StaticImageTrack.mAlpha = 0i64;
    StaticImageTrack.mTexAnimation = 0i64;
  }
  if ( (v9 & 4) == 0 )
  {
    v9 |= 4u;
    _S1_9 = v9;
    StaticBgScale[0].x = params->mBackgroundScale;
    dword_142135754 = LODWORD(StaticBgScale[0].x);
  }
  if ( (v9 & 8) == 0 )
  {
    v9 |= 8u;
    _S1_9 = v9;
    position_graph.nData = 1;
    position_graph.fDomain = x_axis_keyframes;
    position_graph.tRange = StaticBgPosition;
  }
  if ( (v9 & 0x10) == 0 )
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
  Render::LoadScreen::mDisplayTrack[Render::LoadScreen::mNumDisplayTracks] = &StaticImageTrack;
  Render::LoadScreen::mNumDisplayTracks = v10 + 1;
  mData = params->mAnimationName.mData;
  v12 = UFG::qStringHashUpper32(mData, 0xFFFFFFFF);
  v13 = (UFG::qResourceData *)Illusion::Factory::NewStateBlock(mData, v12, 1u, 0x20u, 0i64, 0i64, 0i64);
  v14 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v14, v13);
  p_mNext = (float *)&v13[1].mResourceHandles.mNode.mNext;
  UFG::qMemSet(p_mNext, 0, 0x20u);
  *p_mNext = params->mFlipbookHorizSpeed;
  p_mNext[1] = params->mFlipbookVertSpeed;
  p_mNext[2] = (float)params->mNumFlipbookPagesHoriz;
  p_mNext[3] = (float)params->mNumFlipbookPagesVert;
  if ( params->mFlipbookEnabled )
    v16 = (int)FLOAT_1_0;
  else
    v16 = 0;
  *((_DWORD *)p_mNext + 4) = v16;
  v17 = Illusion::Factory::NewMaterial(mData, v12, 5u, 0i64, 0i64, 0i64);
  v18 = UFG::qStringHash32("LOADSPINNER", 0xFFFFFFFF);
  LOWORD(v17[1].mNode.mChild[0]) = 0;
  HIDWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v17[1].mTypeUID = -1957338719;
  LODWORD(v17[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v18;
  *(_WORD *)&v17[1].mDebugName[12] = 0;
  *(_DWORD *)&v17[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v17[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v17[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v17[1].mStateBlockMask.mFlags[0]) = v12;
  LOWORD(v17[1].mMaterialUser.mOffset) = 0;
  *(&v17[1].mNumParams + 1) = UFG::qStringHash32("sbTextureAnim", 0xFFFFFFFF);
  v17[1].mNumParams = UFG::qStringHash32("sbTextureAnim", 0xFFFFFFFF);
  LODWORD(v17[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1292158962;
  v17[2].mNode.mUID = v12;
  LOWORD(v17[2].mTypeUID) = 0;
  HIDWORD(v17[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v17[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v17[2].UFG::qResourceData + 22) = 315097330;
  *(_DWORD *)&v17[2].mDebugName[28] = -1551679522;
  LOWORD(v17[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v17[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v17[3].mNode.mChild[0]) = 1660426324;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, v17);
  v20 = _S1_9;
  if ( (_S1_9 & 0x20) == 0 )
  {
    _S1_9 |= 0x20u;
    StaticImageTrack_0.mTexture = 0i64;
    StaticImageTrack_0.mMaterial = v17;
    StaticImageTrack_0.mTexAnimation = 0i64;
    *(_QWORD *)&StaticImageTrack_0.mAlphaStateUID = 0i64;
    *(_QWORD *)&StaticImageTrack_0.mTrackLength = 0x40000000i64;
    *(_OWORD *)&StaticImageTrack_0.mPosition = 0i64;
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
        StaticImageTrack_0.mTexture = *(Illusion::Texture **)((char *)&StaticImageTrack_0.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev
                                                            + v24);
      }
      else if ( v25 == v22 )
      {
        StaticImageTrack_0.mTexAnimation = (SB_TextureAnim *)&(*(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&StaticImageTrack_0.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev + v24))[8];
      }
    }
    v20 = _S1_9;
  }
  if ( (v20 & 0x40) == 0 )
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
    StaticScale[0].x = params->mAnimationScale;
    dword_1421357EC = LODWORD(StaticScale[0].x);
  }
  if ( (v20 & 0x100) == 0 )
  {
    v20 |= 0x100u;
    _S1_9 = v20;
    position_graph_0.nData = 1;
    position_graph_0.fDomain = x_axis_keyframes_0;
    position_graph_0.tRange = SpinnerPosition;
  }
  if ( (v20 & 0x200) == 0 )
  {
    v20 |= 0x200u;
    _S1_9 = v20;
    rotation_graph.nData = 2;
    rotation_graph.fDomain = x_axis_keyframes_0;
    rotation_graph.tRange = rotation_values;
  }
  if ( (v20 & 0x400) == 0 )
  {
    v20 |= 0x400u;
    _S1_9 = v20;
    scale_graph_0.nData = 1;
    scale_graph_0.fDomain = x_axis_keyframes_0;
    scale_graph_0.tRange = StaticScale;
  }
  if ( (v20 & 0x800) == 0 )
  {
    _S1_9 = v20 | 0x800;
    colour_graph.nData = 1;
    colour_graph.fDomain = x_axis_keyframes_0;
    colour_graph.tRange = StaticSpinnerColour;
  }
  StaticImageTrack_0.mPosition = &position_graph_0;
  if ( params->mRotationEnabled == 0.0 )
    StaticImageTrack_0.mRotation = 0i64;
  else
    StaticImageTrack_0.mRotation = &rotation_graph;
  StaticImageTrack_0.mScale = &scale_graph_0;
  StaticImageTrack_0.mColour = &colour_graph;
  StaticImageTrack_0.mCentre = 1;
  v26 = Render::LoadScreen::mNumDisplayTracks;
  Render::LoadScreen::mDisplayTrack[Render::LoadScreen::mNumDisplayTracks] = &StaticImageTrack_0;
  Render::LoadScreen::mNumDisplayTracks = v26 + 1;
  Render::LoadScreen::mEnable = 1;
}

// File Line: 545
// RVA: 0x484D0
void __fastcall Render::StartLoadScreen(Render::LoadScreenParams *pParams)
{
  Render::RenderCallbacks *RenderCallbacks; // rax

  if ( Render::LoadScreen::mEnable && Render::LoadScreen::mDrawLoadScreen == DONT_DRAW )
  {
    Render::LoadScreen::mSavedNumDisplayTracks = Render::LoadScreen::mNumDisplayTracks;
    SpinnerPosition[0] = *(UFG::qVector2 *)&pParams->mSpinnerPosX;
    StaticImagePosition[0] = *(UFG::qVector2 *)&pParams->mSpinnerPosX;
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
    if ( pParams->mbThreadedRender )
    {
      RenderCallbacks = Render::GetRenderCallbacks();
      Render::LoadScreen::mSavedRenderFunc = RenderCallbacks->mRenderWorldFunc;
      RenderCallbacks->mRenderWorldFunc = Render::LoadScreen::RenderCallback;
      UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&Render::LoadScreen::mThread, 0x4000u);
      UFG::qThread::Start(
        &Render::LoadScreen::mThread,
        (void (__fastcall *)(void *))Render::LoadScreen::DrawLoadScreen,
        0i64);
    }
    else
    {
      Render::LoadScreen::mDrawLoadScreen = SAME_THREAD;
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
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  int v8; // ebx
  Render::DisplayTrack **v9; // rdi
  float v10; // xmm6_4
  float *v11; // rbx
  Illusion::StateValues *StateValues; // rax
  __int64 v13; // rax
  float v14; // xmm2_4
  int v15; // eax
  int v16; // ebx
  Render::DisplayTrack **v17; // rdi
  Render::DisplayTrack *v18; // rcx
  Render::Poly poly; // [rsp+60h] [rbp+18h] BYREF

  v2 = delta_ms;
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
            Render::DisplayTrack::Draw(*v9, view, v5, v7);
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
  if ( Render::LoadScreen::mDrawLoadScreen == SAME_THREAD || Render::LoadScreen::mEmergencyEnable )
  {
    elapsed_time = elapsed_time + v2;
    v10 = elapsed_time;
    v11 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *v11 = v10;
    v11[1] = v2;
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
    StateValues->mParamValues[13] = v11;
    Render::LoadScreen::UpdateBackgroundImages();
    v13 = 7i64 * Render::LoadScreen::mBackgroundMaterialTexParamIndex;
    if ( *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)((char *)&Render::LoadScreen::mBackgroundMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mPrev
                                                                   + v13 * 8)
      && !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&Render::LoadScreen::mBackgroundMaterial[1].mNode.mChild[v13 + 1]) )
    {
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      Render::View::Draw(view, &poly, Render::LoadScreen::mBackgroundMaterial, 0i64);
    }
    v14 = Render::LoadScreen::mTrackTime + v2;
    Render::LoadScreen::mTrackTime = Render::LoadScreen::mTrackTime + v2;
    if ( Render::LoadScreen::mDrawTracks )
    {
      v15 = Render::LoadScreen::mNumDisplayTracks;
      v16 = 0;
      if ( Render::LoadScreen::mNumDisplayTracks > 0 )
      {
        v17 = Render::LoadScreen::mDisplayTrack;
        do
        {
          v18 = *v17;
          if ( *v17 && v18->mTexture )
          {
            Render::DisplayTrack::Draw(v18, view, v14, 1.0);
            v14 = Render::LoadScreen::mTrackTime;
            v15 = Render::LoadScreen::mNumDisplayTracks;
          }
          ++v16;
          ++v17;
        }
        while ( v16 < v15 );
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
    v1 = Render::LoadScreen::mDrawLoadScreen == SEPARATE_THREAD;
    Render::LoadScreen::mDrawLoadScreen = DONT_DRAW;
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
  unsigned __int64 Ticks; // rax
  float TickTime; // xmm0_4

  v0 = Render::LoadScreen::mBackgroundImageCount;
  v1 = 0;
  v2 = 0;
  if ( Render::LoadScreen::mBackgroundImageCount )
  {
    v3 = Render::LoadScreen::mBackgroundImages;
    do
    {
      if ( v3[v2].mDisplayStartTicks )
      {
        Ticks = UFG::qGetTicks();
        TickTime = UFG::qGetTickTime(Render::LoadScreen::mBackgroundImages[v2].mDisplayStartTicks, Ticks);
        v3 = Render::LoadScreen::mBackgroundImages;
        v0 = Render::LoadScreen::mBackgroundImageCount;
        v1 |= TickTime <= Render::LoadScreen::mBackgroundImages[v2].mRequiredTimeLength;
      }
      else if ( v3[v2].mRequiredTimeLength > 0.0 )
      {
        v1 = 1;
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
  float g; // xmm1_4
  float b; // xmm2_4

  g = tint->g;
  b = tint->b;
  StaticSpinnerColour[0].x = tint->r;
  dword_142022FE4 = LODWORD(g);
  dword_142022FE8 = LODWORD(b);
}

