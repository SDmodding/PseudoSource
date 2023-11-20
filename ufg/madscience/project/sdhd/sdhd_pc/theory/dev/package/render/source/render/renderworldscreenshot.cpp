// File Line: 47
// RVA: 0x4AFA0
void __fastcall ScreenShotState::DoRequestedScreenShot(ScreenShotState *this)
{
  ScreenShotState *v1; // rsi
  bool v2; // r14
  bool v3; // r15
  Illusion::Target *v4; // rax
  signed int v5; // edi
  signed int v6; // ebx
  Render *v7; // rcx
  UFG::qString v8; // [rsp+8h] [rbp-79h]
  unsigned __int64 v9; // [rsp+30h] [rbp-51h]
  int v10; // [rsp+38h] [rbp-49h]
  int v11; // [rsp+3Ch] [rbp-45h]
  int v12; // [rsp+40h] [rbp-41h]
  __int64 v13; // [rsp+44h] [rbp-3Dh]
  int v14; // [rsp+4Ch] [rbp-35h]
  int v15; // [rsp+50h] [rbp-31h]
  __int128 v16; // [rsp+58h] [rbp-29h]
  __int128 v17; // [rsp+68h] [rbp-19h]
  __int64 v18; // [rsp+78h] [rbp-9h]
  __int64 v19; // [rsp+80h] [rbp-1h]
  __int64 v20; // [rsp+88h] [rbp+7h]
  __int64 v21; // [rsp+90h] [rbp+Fh]
  __int64 v22; // [rsp+98h] [rbp+17h]
  __int64 v23; // [rsp+A0h] [rbp+1Fh]
  int v24; // [rsp+A8h] [rbp+27h]
  char v25; // [rsp+ACh] [rbp+2Bh]
  __int64 v26; // [rsp+B8h] [rbp+37h]

  v26 = -2i64;
  v1 = this;
  v2 = gDrawDebugContext;
  v3 = gDrawUI;
  gDrawDebugContext = 0;
  gDrawUI = 0;
  v4 = Render::GetBackBufferTarget();
  v5 = (signed int)(float)((float)v4->mTargetTexture[0]->mWidth * v1->mScale);
  v6 = (signed int)(float)((float)v4->mTargetTexture[0]->mHeight * v1->mScale);
  UFG::qString::qString(&v8, "DownSampleScreenShot");
  v13 = 1i64;
  v9 = 0i64;
  v10 = 1;
  v11 = 1;
  v12 = -1;
  v14 = 0;
  v15 = 1;
  _mm_store_si128((__m128i *)&v16, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v17, (__m128i)0i64);
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0i64;
  v24 = 0;
  v25 = 0;
  v9 = __PAIR__(v6, v5);
  LOBYTE(v12) = 0;
  v1->mTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v8);
  Render::RenderFrame(0.0, v7);
  gDrawDebugContext = v2;
  gDrawUI = v3;
  gScreenShotState.mState = 2;
  UFG::qString::~qString(&v8);
}

// File Line: 81
// RVA: 0x5AED0
void __fastcall UFG::RenderWorld::RequestScreenShot(void (__fastcall *function_callback)(Illusion::Target *), float scale, Render::ImageFileFormat format)
{
  gScreenShotState.mScale = scale;
  gScreenShotState.mCallback = function_callback;
  gScreenShotState.mFormat = format;
  gScreenShotState.mState = 1;
}

// File Line: 90
// RVA: 0x5D3B0
void __fastcall UFG::RenderWorld::UpdateRenderScreenShot(UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Illusion::Target *source_target)
{
  Illusion::Target *v2; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rdi
  unsigned int v4; // eax
  UFG::qVector4 texUV; // [rsp+40h] [rbp-D98h]
  __int64 v6; // [rsp+50h] [rbp-D88h]
  RenderQueueLayer v7; // [rsp+60h] [rbp-D78h]
  CompositeSubmitContext ptr; // [rsp+140h] [rbp-C98h]

  v6 = -2i64;
  v2 = source_target;
  v3 = serialization_list;
  if ( gScreenShotState.mState == 1 )
  {
    RenderQueueLayer::RenderQueueLayer(&v7);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v7.mSerializationList = v3;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v7;
    ptr.mQueueMode = 0;
    Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    texUV.x = 0.5 - (float)(Render::gScreenViewportScaleH * 0.5);
    texUV.y = 0.5 - (float)(Render::gScreenViewportScaleV * 0.5);
    texUV.z = Render::gScreenViewportScaleH;
    texUV.w = Render::gScreenViewportScaleV;
    v4 = UFG::qStringHash32("SIMPLEOPAQUE", 0xFFFFFFFF);
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      v2,
      gScreenShotState.mTarget,
      v4,
      "PDACameraBlit",
      0,
      1,
      &texUV);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    `eh vector destructor iterator'(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v7);
  }
}

// File Line: 112
// RVA: 0x5D510
void UFG::RenderWorld::UpdateScreenShot(void)
{
  if ( gScreenShotState.mState == 1 )
  {
    ScreenShotState::DoRequestedScreenShot(&gScreenShotState);
  }
  else if ( gScreenShotState.mState == 2 )
  {
    gScreenShotState.mCallback(gScreenShotState.mTarget);
    gScreenShotState.mState = 0;
  }
}

