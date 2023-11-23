// File Line: 47
// RVA: 0x4AFA0
void __fastcall ScreenShotState::DoRequestedScreenShot(ScreenShotState *this)
{
  bool v2; // r14
  bool v3; // r15
  Illusion::Target *BackBufferTarget; // rax
  int v5; // edi
  int v6; // ebx
  Render *v7; // rcx
  Illusion::CreateTargetParams v8; // [rsp+8h] [rbp-79h] BYREF
  __int64 v9; // [rsp+B8h] [rbp+37h]

  v9 = -2i64;
  v2 = gDrawDebugContext;
  v3 = gDrawUI;
  gDrawDebugContext = 0;
  gDrawUI = 0;
  BackBufferTarget = Render::GetBackBufferTarget();
  v5 = (int)(float)((float)BackBufferTarget->mTargetTexture[0]->mWidth * this->mScale);
  v6 = (int)(float)((float)BackBufferTarget->mTargetTexture[0]->mHeight * this->mScale);
  UFG::qString::qString(&v8.name, "DownSampleScreenShot");
  *(_QWORD *)&v8.num_mrt = 1i64;
  v8.depth = 1;
  v8.array_size = 1;
  *(_DWORD *)v8.mrt_formats = -256;
  v8.target_flags = 0;
  v8.num_mips = 1;
  memset(v8.textures, 0, 85);
  v8.width = v5;
  v8.height = v6;
  this->mTarget = Illusion::CreateTarget(&v8);
  Render::RenderFrame(0.0, v7);
  gDrawDebugContext = v2;
  gDrawUI = v3;
  gScreenShotState.mState = 2;
  UFG::qString::~qString(&v8.name);
}

// File Line: 81
// RVA: 0x5AED0
void __fastcall UFG::RenderWorld::RequestScreenShot(
        void (__fastcall *function_callback)(Illusion::Target *),
        float scale,
        Render::ImageFileFormat format)
{
  gScreenShotState.mScale = scale;
  gScreenShotState.mCallback = function_callback;
  gScreenShotState.mFormat = format;
  gScreenShotState.mState = 1;
}

// File Line: 90
// RVA: 0x5D3B0
void __fastcall UFG::RenderWorld::UpdateRenderScreenShot(
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Illusion::Target *source_target)
{
  unsigned int v4; // eax
  UFG::qVector4 texUV; // [rsp+40h] [rbp-D98h] BYREF
  __int64 v6; // [rsp+50h] [rbp-D88h]
  RenderQueueLayer v7; // [rsp+60h] [rbp-D78h] BYREF
  CompositeSubmitContext ptr; // [rsp+140h] [rbp-C98h] BYREF

  v6 = -2i64;
  if ( gScreenShotState.mState == 1 )
  {
    RenderQueueLayer::RenderQueueLayer(&v7);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v7.mSerializationList = serialization_list;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v7;
    ptr.mQueueMode = QM_Single;
    Render::gRenderUtilities.mSubmitContext = &ptr;
    texUV.x = 0.5 - (float)(Render::gScreenViewportScaleH * 0.5);
    texUV.y = 0.5 - (float)(Render::gScreenViewportScaleV * 0.5);
    texUV.z = Render::gScreenViewportScaleH;
    texUV.w = Render::gScreenViewportScaleV;
    v4 = UFG::qStringHash32("SIMPLEOPAQUE", 0xFFFFFFFF);
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      source_target,
      gScreenShotState.mTarget,
      v4,
      "PDACameraBlit",
      0,
      1,
      &texUV);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    `eh vector destructor iterator(
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

