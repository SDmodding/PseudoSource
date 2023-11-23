// File Line: 66
// RVA: 0x2D580
void __fastcall UFG::RenderStageFrameCapture::Create(
        UFG::RenderContext *render_context,
        unsigned int width,
        unsigned int height)
{
  char *v6; // rax

  v6 = UFG::qMalloc(0x48ui64, "RenderStageFrameCapture", 0i64);
  if ( v6 )
    UFG::RenderStageFrameCapture::RenderStageFrameCapture(
      (UFG::RenderStageFrameCapture *)v6,
      render_context,
      width,
      height);
}

// File Line: 71
// RVA: 0x2D420
void __fastcall UFG::RenderStageFrameCapture::RenderStageFrameCapture(
        UFG::RenderStageFrameCapture *this,
        UFG::RenderContext *render_context,
        unsigned int width,
        unsigned int height)
{
  int v7; // edi
  Illusion::Target **mTarget; // rsi
  UFG::qString *v9; // rax
  UFG::qString v10; // [rsp+20h] [rbp-81h] BYREF
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
  UFG::qString result; // [rsp+B0h] [rbp+Fh] BYREF

  v21 = -2i64;
  this->mCurrTargetIndex = 0;
  this->mEnableCapture = 1;
  this->mWidth = width;
  this->mHeight = height;
  v7 = 0;
  mTarget = this->mTarget;
  do
  {
    v9 = UFG::qString::FormatEx(&result, "FrameCaptureTarget%d", (unsigned int)v7);
    UFG::qString::qString(&v10, v9->mData);
    *(_QWORD *)&v10.mLength = 1i64;
    v10.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)0x100000001i64;
    v10.mMagic = -1;
    HIDWORD(v10.mData) = 0;
    v10.mStringHash32 = 1;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0i64;
    v14 = 0i64;
    v15 = 0i64;
    v16 = 0i64;
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0;
    v20 = 0;
    UFG::qString::~qString(&result);
    LODWORD(v11) = width;
    HIDWORD(v10.mPrev) = height;
    LOBYTE(v10.mMagic) = 0;
    HIDWORD(v10.mData) = 0x4000;
    *mTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v10);
    UFG::qString::~qString(&v10);
    ++v7;
    ++mTarget;
  }
  while ( v7 < 5 );
  this->mFrameCaptureTextureAlias = Illusion::CreateTextureAlias(
                                      "FrameCaptureAlias",
                                      this->mTarget[0]->mTargetTexture[0],
                                      FORMAT_A8R8G8B8);
}

// File Line: 92
// RVA: 0x2D8A0
void __fastcall UFG::RenderStageFrameCapture::UpdateAlias(UFG::RenderStageFrameCapture *this)
{
  int GPUCount; // eax

  if ( this->mEnableCapture )
  {
    GPUCount = Render::GetGPUCount();
    Illusion::Texture::SwitchAliasTexture(
      this->mFrameCaptureTextureAlias,
      this->mTarget[(this->mCurrTargetIndex - GPUCount + 6) % 5]->mTargetTexture[0]);
  }
}

// File Line: 104
// RVA: 0x2D5F0
void __fastcall UFG::RenderStageFrameCapture::Render(
        UFG::RenderStageFrameCapture *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  __int64 v5; // r9
  Illusion::Target *v6; // rsi
  _WORD *v7; // rbx
  Render::ViewSettings *Identity; // rax
  char *v9; // rsi
  Illusion::Material *mMaterial; // rdi
  __int64 mOffset; // rax
  _WORD *v12; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v14; // rdi
  __int64 v15; // rax
  unsigned int mGaussianBlurStateBlockIndex_low; // ebx
  Illusion::StateValues *StateValues; // rax
  Illusion::TextureLockInfo info; // [rsp+58h] [rbp-F30h] BYREF
  RenderQueueLayer v19; // [rsp+70h] [rbp-F18h] BYREF
  Render::View v20; // [rsp+150h] [rbp-E38h] BYREF
  CompositeSubmitContext ptr; // [rsp+2E0h] [rbp-CA8h] BYREF
  Render::Poly poly; // [rsp+F90h] [rbp+8h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FA8h] [rbp+20h]

  if ( this->mEnableCapture )
  {
    v5 = (this->mCurrTargetIndex + 1) % 5;
    this->mCurrTargetIndex = (this->mCurrTargetIndex + 1) % 5;
    v6 = this->mTarget[v5];
    v7 = 0i64;
    if ( Illusion::ITexturePlat::Lock(v6->mTargetTexture[0], LOCK_READ, &info, 0, 0) )
    {
      VideoFrameManager::FrameDataCallback(info.mData, this->mWidth, this->mHeight);
      Illusion::ITexturePlat::Unlock(v6->mTargetTexture[0]);
    }
    RenderQueueLayer::RenderQueueLayer(&v19);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v19.mSerializationList = serialization_list;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v19;
    ptr.mQueueMode = QM_Single;
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v20, Identity, &ptr);
    Render::View::BeginTarget(&v20, v6, "FrameCaptureDownsample", 0, 0, 0i64, 1, 0, 0, 0);
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v9 = 1.0 / (float)(int)this->mWidth;
    *((float *)v9 + 1) = 1.0 / (float)(int)this->mHeight;
    *((_QWORD *)v9 + 1) = 0i64;
    mMaterial = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 206777675 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        0xC532D4Bu);
      mOffset = mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v12 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      else
        v12 = 0i64;
      *v12 |= 0x20u;
    }
    mUID = Render::GetBackBufferTarget()->mTargetTexture[0]->mNode.mUID;
    v14 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mDebugName[20],
        Render::gRenderUtilities.mMaterial[1].mStateBlockMask.mFlags[1],
        mUID);
      v15 = v14->mMaterialUser.mOffset;
      if ( v15 )
        v7 = (_WORD *)((char *)&v14->mMaterialUser + v15);
      *v7 |= 0x20u;
    }
    mGaussianBlurStateBlockIndex_low = SLOWORD(Render::gRenderUtilities.mGaussianBlurStateBlockIndex);
    StateValues = Render::View::GetStateValues(&v20);
    if ( mGaussianBlurStateBlockIndex_low >= 0x40 )
      StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mGaussianBlurStateBlockIndex_low - 64);
    else
      StateValues->mSetValueMask.mFlags[0] |= 1i64 << mGaussianBlurStateBlockIndex_low;
    StateValues->mParamValues[(__int16)mGaussianBlurStateBlockIndex_low] = v9;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v20, &poly, Render::gRenderUtilities.mMaterial, 0i64);
    Render::View::EndTarget(&v20);
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v19);
  }
}

