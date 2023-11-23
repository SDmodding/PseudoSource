// File Line: 62
// RVA: 0x32C40
void __fastcall UFG::RenderStageExposureMetering::Create(UFG::RenderContext *render_context)
{
  char *v2; // rax

  v2 = UFG::qMalloc(0xA8ui64, "RenderStageExposureMetering", 0i64);
  if ( v2 )
    UFG::RenderStageExposureMetering::RenderStageExposureMetering(
      (UFG::RenderStageExposureMetering *)v2,
      render_context);
}

// File Line: 67
// RVA: 0x32790
void __fastcall UFG::RenderStageExposureMetering::RenderStageExposureMetering(
        UFG::RenderStageExposureMetering *this,
        UFG::RenderContext *render_context)
{
  Illusion::StateBlockHandle *p_mStateBlockHandle; // r14
  int v4; // ebx
  Illusion::Target **mTarget; // rdi
  UFG::qString *v6; // rax
  unsigned int v7; // eax
  Illusion::Material *v8; // rdi
  int v9; // ebx
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v13; // rax
  Illusion::CreateTargetParams v14; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v15; // [rsp+E0h] [rbp-20h]
  UFG::qString result; // [rsp+E8h] [rbp-18h] BYREF

  v15 = -2i64;
  p_mStateBlockHandle = &this->mStateBlockHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mStateBlockHandle);
  this->mCurrTargetIndex = 0;
  *(_QWORD *)&this->mTargetExposureEV = 0i64;
  this->mSkyIrradValue = 1.0;
  *(_WORD *)&this->mEnableMetering = 1;
  this->mExposureEVRate = 0.15000001;
  this->mNumCameraIrradVol = 0;
  UFG::qMemSet(this->mCameraIrradVol, 0, 0x30u);
  this->mEnableSkyIrradBlend = 1.0;
  this->mInsideNoSkyVisibleVolume = 0;
  v4 = 0;
  mTarget = this->mTarget;
  do
  {
    v6 = UFG::qString::FormatEx(&result, "MeteringTarget%d", (unsigned int)v4);
    UFG::qString::qString(&v14.name, v6->mData);
    *(_QWORD *)&v14.num_mrt = 1i64;
    *(_QWORD *)&v14.width = 0i64;
    v14.depth = 1;
    v14.array_size = 1;
    *(_DWORD *)v14.mrt_formats = -1;
    v14.target_flags = 0;
    v14.num_mips = 1;
    memset(v14.textures, 0, 85);
    UFG::qString::~qString(&result);
    *(_QWORD *)&v14.width = 0x2000000020i64;
    v14.mrt_formats[0] = 0;
    v14.target_flags = 0x4000;
    *mTarget = Illusion::CreateTarget(&v14);
    UFG::qString::~qString(&v14.name);
    ++v4;
    ++mTarget;
  }
  while ( v4 < 5 );
  v7 = UFG::qStringHashUpper32("IrradianceSkyMetering", 0xFFFFFFFF);
  v8 = Illusion::Factory::NewMaterial("IrradianceSkyMetering", v7, 6u, 0i64, 0i64, 0i64);
  v9 = UFG::qStringHash32("DRIRRADIANCESKYMETER", 0xFFFFFFFF);
  LOWORD(v8[1].mNode.mChild[0]) = 0;
  HIDWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v8[1].mTypeUID = -1957338719;
  LODWORD(v8[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v9;
  *(_WORD *)&v8[1].mDebugName[12] = 0;
  *(_DWORD *)&v8[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v8[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v8[1].mStateBlockMask.mFlags[0]) = 662883558;
  LOWORD(v8[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v8[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v8[2].mNode.mUID = 1660426324;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v8[2].mDebugName[28] = 0;
  LOWORD(v8[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  LODWORD(v8[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v8[3].mNode.mChild[0]) = 0;
  LOWORD(v8[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v8[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v8[3].mNode.mUID = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  *(_DWORD *)&v8[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v8[3].mDebugName[12] = 0;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v8);
  this->mMaterial = v8;
  v11 = UFG::qStringHashUpper32("ed80cbf8-430b-4546-962c-6ca13242c855", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v13, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mStateBlockHandle, 0x4D04C7F2u, v11, Inventory);
}

// File Line: 122
// RVA: 0x33850
void __fastcall UFG::RenderStageExposureMetering::Update(UFG::RenderStageExposureMetering *this, float realtime_delta)
{
  UFG::qResourceData *mData; // rdx
  float mSkyIrradValue; // xmm1_4
  float v6; // xmm0_4
  float mCurrentExposureEV; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm0_4

  mData = this->mStateBlockHandle.mData;
  if ( mData )
  {
    mSkyIrradValue = this->mSkyIrradValue;
    this->mExposureEVRate = *(float *)((char *)&mData[1].mResourceHandles.mNode.mNext
                                     + *(unsigned __int16 *)((char *)&mData[1].mResourceHandles.mNode.mNext
                                                           + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)));
    v6 = Illusion::StateBlockCurve::EvaluateCurve(
           (Illusion::StateBlockCurve *)((char *)&mData[1].mResourceHandles.mNode.mNext
                                       + *(unsigned __int16 *)((char *)&mData[1].mResourceHandles.mNode.mNext
                                                             + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
                                                             + 4)),
           mSkyIrradValue);
    mCurrentExposureEV = this->mCurrentExposureEV;
    v8 = realtime_delta * this->mExposureEVRate;
    v9 = v6 * this->mEnableSkyIrradBlend;
    this->mTargetExposureEV = v9;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(mCurrentExposureEV - v9) & _xmm) >= v8 )
    {
      if ( mCurrentExposureEV <= v9 )
      {
        if ( mCurrentExposureEV < v9 )
          this->mCurrentExposureEV = mCurrentExposureEV + v8;
      }
      else
      {
        this->mCurrentExposureEV = mCurrentExposureEV - v8;
      }
    }
    else
    {
      this->mCurrentExposureEV = v9;
    }
  }
}

// File Line: 148
// RVA: 0x33830
void __fastcall UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(
        UFG::RenderStageExposureMetering *this,
        Render::IrradianceVolume *irradiance_volume)
{
  __int64 mNumCameraIrradVol; // rax

  if ( irradiance_volume->mType == 2 )
  {
    mNumCameraIrradVol = this->mNumCameraIrradVol;
    if ( (unsigned int)mNumCameraIrradVol < 6 )
    {
      this->mCameraIrradVol[mNumCameraIrradVol] = irradiance_volume;
      ++this->mNumCameraIrradVol;
    }
  }
}

// File Line: 157
// RVA: 0x33690
void __fastcall UFG::RenderStageExposureMetering::RenderDebug(
        UFG::RenderStageExposureMetering *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  Render::DebugDrawContext *Context; // rbx

  if ( this->mDebugDisplay )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawTextA(
      Context,
      text_x,
      text_y,
      &UFG::qColour::White,
      "SkyIrrad       %1.3f",
      this->mSkyIrradValue);
    Render::DebugDrawContext::DrawTextA(
      Context,
      text_x,
      text_y + text_height,
      &UFG::qColour::White,
      "Exposure EV    %1.3f | %1.3f",
      this->mCurrentExposureEV,
      this->mTargetExposureEV);
    Render::DebugDrawContext::DrawTextA(
      Context,
      text_x,
      text_y + 2 * text_height,
      &UFG::qColour::White,
      "Exposure Rate  %1.3f/sec",
      this->mExposureEVRate);
    Render::DebugDrawContext::DrawTextA(
      Context,
      text_x,
      text_y + 2 * text_height + text_height,
      &UFG::qColour::White,
      "TOD Sky Blend  %1.3f",
      this->mEnableSkyIrradBlend);
    Render::DebugDrawContext::DrawTextA(
      Context,
      text_x,
      text_y + 4 * text_height,
      &UFG::qColour::White,
      "Final Exposure %1.3f",
      render_context->mEnvState->DisplayDebug[1]);
  }
}

// File Line: 174
// RVA: 0x32D10
void __fastcall UFG::RenderStageExposureMetering::Render(
        UFG::RenderStageExposureMetering *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  float v6; // xmm0_4
  unsigned int mNumCameraIrradVol; // r9d
  Render::IrradianceVolume *v8; // rbx
  float v9; // xmm3_4
  unsigned int v10; // r10d
  __int64 v11; // r11
  Render::IrradianceVolume **v12; // rdx
  unsigned int v13; // eax
  __int64 v14; // r8
  Render::IrradianceVolume *v15; // rcx
  Render::IrradianceVolume **v16; // rdx
  __int64 v17; // r8
  __int64 v18; // rcx
  Illusion::Target *v19; // rsi
  int v20; // xmm9_4
  unsigned int v21; // r8d
  Illusion::Material *mMaterial; // rsi
  __int64 mOffset; // rax
  _WORD *v24; // rax
  unsigned int v25; // r8d
  Illusion::Material *v26; // rsi
  __int64 v27; // rax
  _WORD *v28; // rax
  Illusion::StateArgs *StateArgs; // rsi
  __int128 v30; // xmm2
  __int128 v31; // xmm1
  __int128 v32; // xmm0
  __int128 v33; // xmm2
  __int128 v34; // xmm1
  __int128 v35; // xmm0
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  char *v38; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::TimeOfDayManager *v42; // rax
  float v43; // xmm1_4
  float v44; // xmm2_4
  UFG::TimeOfDayManager *v45; // rax
  float v46; // xmm1_4
  float v47; // xmm2_4
  Illusion::StateValues *v48; // rax
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rax
  UFG::qVector3 scale; // [rsp+50h] [rbp-B0h] BYREF
  Illusion::TextureLockInfo info; // [rsp+60h] [rbp-A0h] BYREF
  Render::cbShadowTransformState arg; // [rsp+70h] [rbp-90h] BYREF
  int v57[4]; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v58[3]; // [rsp+E0h] [rbp-20h] BYREF
  float x; // [rsp+110h] [rbp+10h]
  float v60; // [rsp+114h] [rbp+14h]
  float v61; // [rsp+118h] [rbp+18h]
  float w; // [rsp+11Ch] [rbp+1Ch]
  __int64 v63; // [rsp+120h] [rbp+20h]
  __int128 v64[8]; // [rsp+130h] [rbp+30h] BYREF
  Render::View v65; // [rsp+1B0h] [rbp+B0h] BYREF
  UFG::qMatrix44 dest; // [rsp+340h] [rbp+240h] BYREF
  UFG::qMatrix44 v67; // [rsp+380h] [rbp+280h] BYREF
  RenderQueueLayer v68; // [rsp+3C0h] [rbp+2C0h] BYREF
  LayerSubmitContext ptr; // [rsp+4A0h] [rbp+3A0h] BYREF
  Render::Poly poly; // [rsp+1190h] [rbp+1090h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+1198h] [rbp+1098h]

  v63 = -2i64;
  v6 = render_context->mEnvState->AmbientColorHorizon[3];
  if ( v6 <= 0.0 )
  {
    v6 = 0.0;
  }
  else if ( v6 >= 1.0 )
  {
    v6 = *(float *)&FLOAT_1_0;
  }
  this->mEnableSkyIrradBlend = v6;
  mNumCameraIrradVol = this->mNumCameraIrradVol;
  this->mNumCameraIrradVol = 0;
  if ( this->mEnableMetering )
  {
    if ( mNumCameraIrradVol )
    {
      v8 = this->mCameraIrradVol[0];
      v9 = FLOAT_1000_0;
      if ( mNumCameraIrradVol > 1 )
      {
        v10 = 0;
        v11 = 0i64;
        if ( (int)mNumCameraIrradVol >= 4 )
        {
          v12 = &this->mCameraIrradVol[1];
          v13 = ((mNumCameraIrradVol - 4) >> 2) + 1;
          v14 = v13;
          v10 = 4 * v13;
          v11 = 4i64 * v13;
          do
          {
            if ( (float)((float)((float)((*(v12 - 1))->mScale.y / (float)(*(v12 - 1))->mImageDimensions[1])
                               * (float)((*(v12 - 1))->mScale.x / (float)(*(v12 - 1))->mImageDimensions[0]))
                       * (float)((*(v12 - 1))->mScale.z / (float)(*(v12 - 1))->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)((*(v12 - 1))->mScale.y / (float)(*(v12 - 1))->mImageDimensions[1])
                         * (float)((*(v12 - 1))->mScale.x / (float)(*(v12 - 1))->mImageDimensions[0]))
                 * (float)((*(v12 - 1))->mScale.z / (float)(*(v12 - 1))->mImageDimensions[2]);
              v8 = *(v12 - 1);
            }
            if ( (float)((float)((float)((*v12)->mScale.y / (float)(*v12)->mImageDimensions[1])
                               * (float)((*v12)->mScale.x / (float)(*v12)->mImageDimensions[0]))
                       * (float)((*v12)->mScale.z / (float)(*v12)->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)((*v12)->mScale.y / (float)(*v12)->mImageDimensions[1])
                         * (float)((*v12)->mScale.x / (float)(*v12)->mImageDimensions[0]))
                 * (float)((*v12)->mScale.z / (float)(*v12)->mImageDimensions[2]);
              v8 = *v12;
            }
            if ( (float)((float)((float)(v12[1]->mScale.y / (float)v12[1]->mImageDimensions[1])
                               * (float)(v12[1]->mScale.x / (float)v12[1]->mImageDimensions[0]))
                       * (float)(v12[1]->mScale.z / (float)v12[1]->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)(v12[1]->mScale.y / (float)v12[1]->mImageDimensions[1])
                         * (float)(v12[1]->mScale.x / (float)v12[1]->mImageDimensions[0]))
                 * (float)(v12[1]->mScale.z / (float)v12[1]->mImageDimensions[2]);
              v8 = v12[1];
            }
            v15 = v12[2];
            if ( (float)((float)((float)(v15->mScale.y / (float)v15->mImageDimensions[1])
                               * (float)(v15->mScale.x / (float)v15->mImageDimensions[0]))
                       * (float)(v15->mScale.z / (float)v15->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)(v15->mScale.y / (float)v12[2]->mImageDimensions[1])
                         * (float)(v15->mScale.x / (float)v12[2]->mImageDimensions[0]))
                 * (float)(v15->mScale.z / (float)v15->mImageDimensions[2]);
              v8 = v12[2];
            }
            v12 += 4;
            --v14;
          }
          while ( v14 );
        }
        if ( v10 < mNumCameraIrradVol )
        {
          v16 = &this->mCameraIrradVol[v11];
          v17 = mNumCameraIrradVol - v10;
          do
          {
            if ( (float)((float)((float)((*v16)->mScale.y / (float)(*v16)->mImageDimensions[1])
                               * (float)((*v16)->mScale.x / (float)(*v16)->mImageDimensions[0]))
                       * (float)((*v16)->mScale.z / (float)(*v16)->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)((*v16)->mScale.y / (float)(*v16)->mImageDimensions[1])
                         * (float)((*v16)->mScale.x / (float)(*v16)->mImageDimensions[0]))
                 * (float)((*v16)->mScale.z / (float)(*v16)->mImageDimensions[2]);
              v8 = *v16;
            }
            ++v16;
            --v17;
          }
          while ( v17 );
        }
      }
      this->mInsideNoSkyVisibleVolume = 0;
      if ( v8 )
      {
        v18 = (this->mCurrTargetIndex + 1) % 5;
        this->mCurrTargetIndex = v18;
        v19 = this->mTarget[v18];
        if ( (v8->mFlags & 1) != 0 )
        {
          this->mSkyIrradValue = 0.0;
          this->mInsideNoSkyVisibleVolume = 1;
        }
        else if ( Illusion::ITexturePlat::Lock(v19->mTargetTexture[0], LOCK_READ, &info, 0, 0) )
        {
          this->mSkyIrradValue = (float)(unsigned __int8)*info.mData * 0.0039215689;
          Illusion::ITexturePlat::Unlock(v19->mTargetTexture[0]);
        }
        RenderQueueLayer::RenderQueueLayer(&v68);
        LayerSubmitContext::LayerSubmitContext(&ptr);
        v68.mSerializationList = serialization_list;
        ptr.mRenderQueueProvider = &v68;
        ptr.mQueueMode = QM_Single;
        Render::View::View(&v65, &render_context->mMainViewSettings, &ptr);
        if ( (v8->mFlags & 4) != 0 )
          v20 = (int)FLOAT_1_0;
        else
          v20 = 0;
        Render::View::BeginTarget(&v65, v19, "ExposureMetering", 0, 0, 0i64, 1, 0, 0, 0);
        v21 = v8->mTextureUID[1];
        if ( !v21 )
          v21 = -1324127765;
        mMaterial = this->mMaterial;
        if ( LODWORD(mMaterial[3].mNode.mChild[0]) != v21 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mMaterial[2].mNumParams,
            (unsigned int)mMaterial[3].mNode.mChild[1],
            v21);
          mOffset = mMaterial->mMaterialUser.mOffset;
          if ( mOffset )
            v24 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
          else
            v24 = 0i64;
          *v24 |= 0x20u;
        }
        v25 = v8->mTextureUID[2];
        if ( !v25 )
          v25 = -1324127765;
        v26 = this->mMaterial;
        if ( *(_DWORD *)&v26[3].mDebugName[12] != v25 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v26[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
            *(_DWORD *)&v26[3].mDebugName[20],
            v25);
          v27 = v26->mMaterialUser.mOffset;
          if ( v27 )
            v28 = (_WORD *)((char *)&v26->mMaterialUser + v27);
          else
            v28 = 0i64;
          *v28 |= 0x20u;
        }
        StateArgs = Render::View::GetStateArgs(&v65);
        v30 = (__int128)v8->mTransformInv.v1;
        v31 = (__int128)v8->mTransformInv.v2;
        v32 = (__int128)v8->mTransformInv.v3;
        v64[0] = (__int128)v8->mTransformInv.v0;
        v64[1] = v30;
        v64[2] = v31;
        v64[3] = v32;
        v33 = (__int128)v8->mRotationMtxInv.v1;
        v34 = (__int128)v8->mRotationMtxInv.v2;
        v35 = (__int128)v8->mRotationMtxInv.v3;
        v64[4] = (__int128)v8->mRotationMtxInv.v0;
        v64[5] = v33;
        v64[6] = v34;
        v64[7] = v35;
        scale.x = 1.0;
        scale.y = FLOAT_N1_0;
        scale.z = 0.5;
        if ( (v8->mFlags & 4) != 0 )
          scale.y = 1.0;
        UFG::qScaleMatrix(&dest, &scale);
        dest.v3.z = 0.5;
        *(float *)&info.mData = scale.x * 2.0;
        *((float *)&info.mData + 1) = scale.y * 2.0;
        *(float *)&info.mLinePitch = scale.z * 2.0;
        UFG::qScaleMatrix(&v67, (UFG::qVector3 *)&info);
        v67.v3.x = -0.5;
        v67.v3.y = -0.5;
        *(float *)v57 = (float)(v8->mScale.x / (float)((float)v8->mImageDimensions[0] - 1.0))
                      / (float)(v8->mScale.x * 2.0);
        *(float *)&v57[1] = (float)(v8->mScale.y / (float)((float)v8->mImageDimensions[1] - 1.0))
                          / (float)(v8->mScale.y * 2.0);
        *(float *)&v57[2] = (float)(v8->mScale.z / (float)((float)v8->mImageDimensions[2] - 1.0))
                          / (float)(v8->mScale.z * 2.0);
        v57[3] = 0;
        mEnvState = render_context->mEnvState;
        StateValues = Render::View::GetStateValues(&v65);
        StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
        StateValues->mParamValues[55] = mEnvState;
        v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
        Instance = UFG::TimeOfDayManager::GetInstance();
        y = Instance->mAmbientSkyDirection[0].y;
        z = Instance->mAmbientSkyDirection[0].z;
        *(float *)v38 = Instance->mAmbientSkyDirection[0].x;
        *((float *)v38 + 1) = y;
        *((float *)v38 + 2) = z;
        v42 = UFG::TimeOfDayManager::GetInstance();
        v43 = v42->mAmbientSkyDirection[1].y;
        v44 = v42->mAmbientSkyDirection[1].z;
        *((_DWORD *)v38 + 4) = LODWORD(v42->mAmbientSkyDirection[1].x);
        *((float *)v38 + 5) = v43;
        *((float *)v38 + 6) = v44;
        v45 = UFG::TimeOfDayManager::GetInstance();
        v46 = v45->mAmbientSkyDirection[2].y;
        v47 = v45->mAmbientSkyDirection[2].z;
        *((_DWORD *)v38 + 8) = LODWORD(v45->mAmbientSkyDirection[2].x);
        *((float *)v38 + 9) = v46;
        *((float *)v38 + 10) = v47;
        *((_DWORD *)v38 + 12) = v20;
        v48 = Render::View::GetStateValues(&v65);
        v48->mSetValueMask.mFlags[0] |= 0x8000ui64;
        v48->mParamValues[15] = v38;
        v58[0] = (__int128)v65.mViewWorld.v0;
        v58[1] = (__int128)v65.mViewWorld.v1;
        v58[2] = (__int128)v65.mViewWorld.v2;
        x = v65.mViewWorld.v3.x;
        v60 = v65.mViewWorld.v3.y;
        w = v65.mViewWorld.v3.w;
        v61 = v65.mViewWorld.v3.z + 0.5;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
        {
          Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
          Render::cbShadowTransformState::sStateParamIndex = Param;
          arg.mStateParamIndex = Param;
        }
        arg.mViewWorld = (UFG::qMatrix44 *)v58;
        arg.mWorldView = (UFG::qMatrix44 *)v64;
        arg.mProjection = &dest;
        arg.mCutplanes = 0i64;
        arg.mBiases = (const float *)v57;
        arg.mBlurWidths = 0i64;
        arg.mCached_Remote.m_Stream = 0i64;
        Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &arg);
        Render::Poly::Poly(&poly, 0.0, 0.0, 0.0625, 0.0625, 0.0);
        Render::View::Draw(&v65, &poly, this->mMaterial, 0i64);
        mPrev = arg.mPrev;
        mNext = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        mNext->mPrev = mPrev;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
          StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&v65);
        v52 = arg.mPrev;
        v53 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v53->mPrev = v52;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        p_mStateArgs = &ptr.mStateArgs;
        `eh vector destructor iterator(
          ptr.mStateArgs.mStateArgs,
          0x10ui64,
          128,
          (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
        RenderQueueLayer::~RenderQueueLayer(&v68);
      }
    }
    else
    {
      this->mSkyIrradValue = 1.0;
    }
  }
  else
  {
    this->mCurrentExposureEV = 0.0;
  }
}

