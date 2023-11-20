// File Line: 66
// RVA: 0x2D580
void __fastcall UFG::RenderStageFrameCapture::Create(UFG::RenderContext *render_context, unsigned int width, unsigned int height)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  UFG::RenderContext *v5; // rsi
  char *v6; // rax

  v3 = height;
  v4 = width;
  v5 = render_context;
  v6 = UFG::qMalloc(0x48ui64, "RenderStageFrameCapture", 0i64);
  if ( v6 )
    UFG::RenderStageFrameCapture::RenderStageFrameCapture((UFG::RenderStageFrameCapture *)v6, v5, v4, v3);
}

// File Line: 71
// RVA: 0x2D420
void __fastcall UFG::RenderStageFrameCapture::RenderStageFrameCapture(UFG::RenderStageFrameCapture *this, UFG::RenderContext *render_context, unsigned int width, unsigned int height)
{
  unsigned int v4; // er14
  unsigned int v5; // er15
  UFG::RenderStageFrameCapture *v6; // rbx
  signed int v7; // edi
  Illusion::Target **v8; // rsi
  UFG::qString *v9; // rax
  UFG::qString v10; // [rsp+20h] [rbp-81h]
  __int128 v11; // [rsp+48h] [rbp-59h]
  __int128 v12; // [rsp+58h] [rbp-49h]
  __int64 v13; // [rsp+68h] [rbp-39h]
  __int64 v14; // [rsp+70h] [rbp-31h]
  __int64 v15; // [rsp+78h] [rbp-29h]
  __int64 v16; // [rsp+80h] [rbp-21h]
  __int64 v17; // [rsp+88h] [rbp-19h]
  __int64 v18; // [rsp+90h] [rbp-11h]
  int v19; // [rsp+98h] [rbp-9h]
  char v20; // [rsp+9Ch] [rbp-5h]
  __int64 v21; // [rsp+A8h] [rbp+7h]
  UFG::qString result; // [rsp+B0h] [rbp+Fh]

  v21 = -2i64;
  v4 = height;
  v5 = width;
  v6 = this;
  this->mCurrTargetIndex = 0;
  this->mEnableCapture = 1;
  this->mWidth = width;
  this->mHeight = height;
  v7 = 0;
  v8 = this->mTarget;
  do
  {
    v9 = UFG::qString::FormatEx(&result, "FrameCaptureTarget%d", (unsigned int)v7);
    UFG::qString::qString(&v10, v9->mData);
    *(_QWORD *)&v10.mLength = 1i64;
    *(_QWORD *)&v11 = 0i64;
    v10.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)4294967297i64;
    v10.mMagic = -1;
    HIDWORD(v10.mData) = 0;
    v10.mStringHash32 = 1;
    _mm_store_si128((__m128i *)&v11, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v12, (__m128i)0i64);
    v13 = 0i64;
    v14 = 0i64;
    v15 = 0i64;
    v16 = 0i64;
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0;
    v20 = 0;
    UFG::qString::~qString(&result);
    LODWORD(v11) = v5;
    HIDWORD(v10.mPrev) = v4;
    LOBYTE(v10.mMagic) = 0;
    HIDWORD(v10.mData) = 0x4000;
    *v8 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v10);
    UFG::qString::~qString(&v10);
    ++v7;
    ++v8;
  }
  while ( v7 < 5 );
  v6->mFrameCaptureTextureAlias = Illusion::CreateTextureAlias(
                                    "FrameCaptureAlias",
                                    v6->mTarget[0]->mTargetTexture[0],
                                    0);
}

// File Line: 92
// RVA: 0x2D8A0
void __fastcall UFG::RenderStageFrameCapture::UpdateAlias(UFG::RenderStageFrameCapture *this)
{
  UFG::RenderStageFrameCapture *v1; // rbx
  int v2; // eax

  v1 = this;
  if ( this->mEnableCapture )
  {
    v2 = Render::GetGPUCount();
    Illusion::Texture::SwitchAliasTexture(
      v1->mFrameCaptureTextureAlias,
      v1->mTarget[(v1->mCurrTargetIndex - v2 + 6) % 5]->mTargetTexture[0]);
  }
}

// File Line: 104
// RVA: 0x2D5F0
void __fastcall UFG::RenderStageFrameCapture::Render(UFG::RenderStageFrameCapture *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbp
  UFG::RenderStageFrameCapture *v4; // rdi
  __int64 v5; // r9
  Illusion::Target *v6; // rsi
  _WORD *v7; // rbx
  Render::ViewSettings *v8; // rax
  char *v9; // rsi
  Illusion::Material *v10; // rdi
  __int64 v11; // rax
  _WORD *v12; // rax
  unsigned int v13; // er8
  Illusion::Material *v14; // rdi
  __int64 v15; // rax
  unsigned int v16; // ebx
  Illusion::StateValues *v17; // rax
  Illusion::TextureLockInfo info; // [rsp+58h] [rbp-F30h]
  RenderQueueLayer v19; // [rsp+70h] [rbp-F18h]
  Render::View v20; // [rsp+150h] [rbp-E38h]
  CompositeSubmitContext ptr; // [rsp+2E0h] [rbp-CA8h]
  Render::Poly poly; // [rsp+F90h] [rbp+8h]
  Illusion::StateArgs *v23; // [rsp+FA8h] [rbp+20h]

  v3 = serialization_list;
  v4 = this;
  if ( this->mEnableCapture )
  {
    v5 = (this->mCurrTargetIndex + 1) % 5;
    this->mCurrTargetIndex = (this->mCurrTargetIndex + 1) % 5;
    v6 = this->mTarget[v5];
    v7 = 0i64;
    if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)v6->mTargetTexture[0], 0, &info, 0, 0) )
    {
      VideoFrameManager::FrameDataCallback(info.mData, v4->mWidth, v4->mHeight);
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v6->mTargetTexture[0]);
    }
    RenderQueueLayer::RenderQueueLayer(&v19);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v19.mSerializationList = v3;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v19;
    ptr.mQueueMode = 0;
    v8 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v20, v8, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v20, v6, "FrameCaptureDownsample", 0, 0, 0i64, 1, 0, 0, 0);
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v9 = 1.0 / (float)(signed int)v4->mWidth;
    *((float *)v9 + 1) = 1.0 / (float)(signed int)v4->mHeight;
    *((_QWORD *)v9 + 1) = 0i64;
    v10 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != 206777675 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        0xC532D4Bu);
      v11 = v10->mMaterialUser.mOffset;
      if ( v11 )
        v12 = (_WORD *)((char *)&v10->mMaterialUser + v11);
      else
        v12 = 0i64;
      *v12 |= 0x20u;
    }
    v13 = Render::GetBackBufferTarget()->mTargetTexture[0]->mNode.mUID;
    v14 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mStateBlockMask.mFlags[0]) != v13 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mDebugName[20],
        Render::gRenderUtilities.mMaterial[1].mStateBlockMask.mFlags[1],
        v13);
      v15 = v14->mMaterialUser.mOffset;
      if ( v15 )
        v7 = (_WORD *)((char *)&v14->mMaterialUser + v15);
      *v7 |= 0x20u;
    }
    v16 = SLOWORD(Render::gRenderUtilities.mGaussianBlurStateBlockIndex);
    v17 = Render::View::GetStateValues(&v20);
    if ( v16 >= 0x40 )
      v17->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v16 - 64);
    else
      v17->mSetValueMask.mFlags[0] |= 1i64 << v16;
    v17->mParamValues[(signed __int16)v16] = v9;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v20, &poly, Render::gRenderUtilities.mMaterial, 0i64);
    Render::View::EndTarget(&v20);
    v23 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v19);
  }
}List<Render::Decal,Ren

