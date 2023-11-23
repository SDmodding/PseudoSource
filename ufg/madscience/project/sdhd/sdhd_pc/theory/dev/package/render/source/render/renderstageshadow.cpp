// File Line: 131
// RVA: 0x383B0
void __fastcall UFG::RenderStageShadow::Create(UFG::RenderContext *render_context)
{
  char *v2; // rax

  v2 = UFG::qMalloc(0x580ui64, "RenderStageShadow", 0i64);
  if ( v2 )
    UFG::RenderStageShadow::RenderStageShadow((UFG::RenderStageShadow *)v2, render_context);
}

// File Line: 142
// RVA: 0x367D0
void __fastcall UFG::RenderStageShadow::RenderStageShadow(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context)
{
  Illusion::RasterStateHandle *p_mRasterStateCharacterShadowCollectorHandle; // r14
  unsigned int v5; // eax
  Illusion::Material *v6; // rdi
  int v7; // ebx
  unsigned int mUID; // ebx
  UFG::qResourceWarehouse *v9; // rax
  unsigned int v10; // eax
  Illusion::Material *v11; // rdi
  int v12; // ebx
  UFG::qResourceWarehouse *v13; // rax
  unsigned int v14; // eax
  Illusion::Material *v15; // rdi
  int v16; // ebx
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // eax
  Illusion::Material *v19; // rdi
  unsigned int v20; // ebx
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceData *v22; // rbx
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceData *v24; // rbx
  UFG::qResourceWarehouse *v25; // rax
  UFG::qResourceData *v26; // rbx
  UFG::qResourceWarehouse *v27; // rax
  UFG::qResourceData *v28; // rbx
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceData *v30; // rbx
  UFG::qResourceWarehouse *v31; // rax
  UFG::qResourceData *v32; // rbx
  UFG::qResourceWarehouse *v33; // rax
  UFG::qResourceData *v34; // rbx
  UFG::qResourceWarehouse *v35; // rax
  UFG::qResourceData *v36; // rbx
  UFG::qResourceWarehouse *v37; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v39; // rax
  UFG::qResourceInventory *v40; // rax
  UFG::qResourceWarehouse *v41; // rax
  UFG::qResourceInventory *v42; // rax
  UFG::qResourceWarehouse *v43; // rax
  UFG::qResourceInventory *v44; // rax
  UFG::qResourceWarehouse *v45; // rax
  UFG::qResourceInventory *v46; // rax
  UFG::qResourceWarehouse *v47; // rax
  UFG::qResourceInventory *v48; // rax
  UFG::qResourceWarehouse *v49; // rax
  UFG::qResourceInventory *v50; // rax
  UFG::qResourceWarehouse *v51; // rax
  UFG::qResourceInventory *v52; // rax
  UFG::qResourceWarehouse *v53; // rax
  UFG::qResourceInventory *v54; // rax
  UFG::qResourceWarehouse *v55; // rax
  UFG::qResourceInventory *v56; // rax
  UFG::qResourceWarehouse *v57; // rax
  unsigned int v58; // ebx
  UFG::qResourceInventory *v59; // rax
  UFG::qResourceWarehouse *v60; // rax

  p_mRasterStateCharacterShadowCollectorHandle = &this->mRasterStateCharacterShadowCollectorHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateCharacterShadowCollectorHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateDoubleSidedHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateInvertCullingHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateNormalHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mCharacterShadowCollectorAlphaStateHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mAlphaStateNoColourWriteHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mCharacterShadowCollectorShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mCharacterShadowCollectorLowShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mCharacterShadowCollectorHighShaderHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mNoiseTextureHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mCloudVolumePrimitiveVertexDecl);
  *(_QWORD *)&this->mNumShadowsRendered = 0i64;
  this->mShadowFOV = -1.0;
  this->mShadowNear = 16.0;
  this->mShadowFar = 1256.0;
  this->mShadowOffset = 1024.0;
  this->mMinShadowFOV = 90.0;
  *(_WORD *)&this->mDrawDebugShadowMap = 0;
  *(_WORD *)&this->mRenderingNISCharacterShadows = 0;
  this->mCascadeSplit[0] = 0.86000001;
  this->mCascadeSplit[1] = 1.1;
  this->mCascadeSplit[2] = 0.89999998;
  this->mCascadeSplit[3] = 0.86000001;
  this->mCascadeBias[0] = 1.0;
  this->mCascadeBias[1] = 1.0;
  this->mCascadeBias[2] = 1.0;
  this->mCascadeBias[3] = 1.0;
  this->mCascadeFilterWidth[0] = 0.00025000001;
  this->mCascadeFilterWidth[1] = 0.00030000001;
  this->mCascadeFilterWidth[2] = 0.00019999999;
  this->mCascadeFilterWidth[3] = 0.00025000001;
  this->mCascadeSplitHQ[0] = 0.95999998;
  this->mCascadeSplitHQ[1] = 1.3;
  this->mCascadeSplitHQ[2] = 1.5;
  this->mCascadeSplitHQ[3] = 0.95999998;
  this->mCascadeBiasHQ[0] = 1.0;
  this->mCascadeBiasHQ[1] = 1.0;
  this->mCascadeBiasHQ[2] = 1.0;
  this->mCascadeBiasHQ[3] = 1.0;
  this->mCascadeFilterWidthHQ[0] = 0.00017500001;
  this->mCascadeFilterWidthHQ[1] = 0.00021000001;
  this->mCascadeFilterWidthHQ[2] = 0.00013999999;
  this->mCascadeFilterWidthHQ[3] = 0.00017500001;
  UFG::qMemSet(this->mSplitPattern, 0, 0x10u);
  this->mBiases[0] = UFG::RenderStageShadow::DEFAULT_BIAS0;
  this->mBiases[1] = UFG::RenderStageShadow::DEFAULT_BIAS1;
  this->mBiases[2] = UFG::RenderStageShadow::DEFAULT_BIAS2;
  this->mBiases[3] = UFG::RenderStageShadow::DEFAULT_BIAS0;
  this->mSplits[0] = UFG::RenderStageShadow::DEFAULT_SPLIT0;
  this->mSplits[1] = UFG::RenderStageShadow::DEFAULT_SPLIT1;
  this->mSplits[2] = UFG::RenderStageShadow::DEFAULT_SPLIT2;
  this->mSplits[3] = UFG::RenderStageShadow::DEFAULT_SPLIT0;
  this->mShadowFilterWidth[0] = 0.00025000001;
  this->mShadowFilterWidth[1] = 0.00030000001;
  this->mShadowFilterWidth[2] = 0.00019999999;
  this->mShadowFilterWidth[3] = 0.00025000001;
  *(_QWORD *)&this->mShadowViewSettings[0].mCullPixelDensityThreshold = 1022739087i64;
  this->mShadowViewSettings[0].mCullIndex = -1;
  *(_QWORD *)&this->mShadowViewSettings[1].mCullPixelDensityThreshold = 1024416809i64;
  this->mShadowViewSettings[1].mCullIndex = -1;
  *(_QWORD *)&this->mShadowViewSettings[2].mCullPixelDensityThreshold = 1028443341i64;
  this->mShadowViewSettings[2].mCullIndex = -1;
  *(_QWORD *)&this->mShadowViewSettings[3].mCullPixelDensityThreshold = 1028443341i64;
  this->mShadowViewSettings[3].mCullIndex = -1;
  this->mCloudShadowCullDist = 250.0;
  this->mCloudShadowMinVolume = 16000.0;
  *(_WORD *)&this->mEnableCloudShadows = 256;
  this->mEnableAdjustedSunDir = 1;
  v5 = UFG::qStringHashUpper32("DepthDownsample_Shadow", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewMaterial("DepthDownsample_Shadow", v5, 4u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLESHADOW", 0xFFFFFFFF);
  LOWORD(v6[1].mNode.mChild[0]) = 0;
  HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v7;
  mUID = render_context->mCascadeShadowTextureAliasDepth->mNode.mUID;
  *(_WORD *)&v6[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v6[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = mUID;
  LOWORD(v6[1].mMaterialUser.mOffset) = 0;
  *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v6[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v6[2].mNode.mUID = -1851597485;
  LOWORD(v6[2].mTypeUID) = 0;
  HIDWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v6[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v6[2].mDebugName[28] = -119921445;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, v6);
  this->mMatDepthDownsampleShadow = v6;
  v10 = UFG::qStringHashUpper32("MatStencilWriteShadowNear", 0xFFFFFFFF);
  v11 = Illusion::Factory::NewMaterial("MatStencilWriteShadowNear", v10, 3u, 0i64, 0i64, 0i64);
  v12 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v11[1].mNode.mChild[0]) = 0;
  HIDWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11[1].mTypeUID = -1957338719;
  LODWORD(v11[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v12;
  *(_WORD *)&v11[1].mDebugName[12] = 0;
  *(_DWORD *)&v11[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v11[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v11[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v11[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v11[1].mMaterialUser.mOffset) = 0;
  *(&v11[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v11[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v11[2].mNode.mUID = 1522949938;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v11);
  this->mMatStencilWriteShadowNear = v11;
  v14 = UFG::qStringHashUpper32("MatStencilWriteShadowFar", 0xFFFFFFFF);
  v15 = Illusion::Factory::NewMaterial("MatStencilWriteShadowFar", v14, 3u, 0i64, 0i64, 0i64);
  v16 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v15[1].mNode.mChild[0]) = 0;
  HIDWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v15[1].mTypeUID = -1957338719;
  LODWORD(v15[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v16;
  *(_WORD *)&v15[1].mDebugName[12] = 0;
  *(_DWORD *)&v15[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v15[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v15[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v15[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v15[1].mMaterialUser.mOffset) = 0;
  *(&v15[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v15[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v15[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v15[2].mNode.mUID = -57444623;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, v15);
  this->mMatStencilWriteShadowFar = v15;
  v18 = UFG::qStringHashUpper32("CloudShadowVolumeMat", 0xFFFFFFFF);
  v19 = Illusion::Factory::NewMaterial("CloudShadowVolumeMat", v18, 5u, 0i64, 0i64, 0i64);
  LOWORD(v19[1].mNode.mChild[0]) = 0;
  HIDWORD(v19[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v19[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v19[1].mTypeUID = -1957338719;
  LODWORD(v19[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1941137269;
  v20 = render_context->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  *(_WORD *)&v19[1].mDebugName[12] = 0;
  *(_DWORD *)&v19[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v19[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v19[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v19[1].mStateBlockMask.mFlags[0]) = v20;
  LOWORD(v19[1].mMaterialUser.mOffset) = 0;
  *(&v19[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v19[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v19[2].mNode.mUID = -1053429752;
  LOWORD(v19[2].mTypeUID) = 0;
  HIDWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v19[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v19[2].mDebugName[28] = 1660426324;
  LOWORD(v19[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v19[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v19[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v19[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v19[3].mNode.mChild[0]) = 0;
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, v19);
  this->mMatCloudShadowVolume = v19;
  v22 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilWriteFar", 0xFC9376F1, 0i64, 0i64, 0i64);
  LODWORD(v22[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v22[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v22[1].mNode.mChild + 6) = 519;
  WORD2(v22[1].mNode.mChild[0]) = 511;
  v23 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v23, v22);
  v24 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestFar", 0x5000AC30u, 0i64, 0i64, 0i64);
  LODWORD(v24[1].mNode.mParent) = 33751041;
  HIWORD(v24[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v24[1].mNode.mChild + 6) = 2;
  WORD2(v24[1].mNode.mChild[0]) = 255;
  v25 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v25, v24);
  v26 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilWriteNear", 0x5AC65F32u, 0i64, 0i64, 0i64);
  LODWORD(v26[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v26[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v26[1].mNode.mChild + 6) = 519;
  WORD2(v26[1].mNode.mChild[0]) = 511;
  v27 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v27, v26);
  v28 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestNear", 0xD3F5358u, 0i64, 0i64, 0i64);
  LODWORD(v28[1].mNode.mParent) = 34013184;
  HIWORD(v28[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v28[1].mNode.mChild + 5) = 512;
  BYTE4(v28[1].mNode.mChild[0]) = -1;
  BYTE1(v28[1].mNode.mChild[1]) = 0;
  v29 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v29, v28);
  v30 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestFarDebug", 0xCCB67A58, 0i64, 0i64, 0i64);
  LODWORD(v30[1].mNode.mParent) = 458752;
  HIWORD(v30[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v30[1].mNode.mChild + 6) = 2;
  WORD2(v30[1].mNode.mChild[0]) = 255;
  v31 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v31, v30);
  v32 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestNearDebug", 0xC5AA9974, 0i64, 0i64, 0i64);
  LODWORD(v32[1].mNode.mParent) = 458752;
  HIWORD(v32[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v32[1].mNode.mChild + 5) = 512;
  BYTE4(v32[1].mNode.mChild[0]) = -1;
  BYTE1(v32[1].mNode.mChild[1]) = 0;
  v33 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v33, v32);
  v34 = Illusion::Factory::NewRasterState(
          "Collector.RasterState.CloudShadowStencilTestFar",
          0xE48814A0,
          0i64,
          0i64,
          0i64);
  LODWORD(v34[1].mNode.mParent) = 16973825;
  HIWORD(v34[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v34[1].mNode.mChild + 6) = 2;
  WORD2(v34[1].mNode.mChild[0]) = 255;
  v35 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v35, v34);
  v36 = Illusion::Factory::NewAlphaState("Collector.AlphaState.ShadowAlphaOnly", 0xC135F008, 0i64, 0i64, 0i64);
  LOWORD(v36[1].mNode.mParent) = 257;
  BYTE2(v36[1].mNode.mParent) = 1;
  LOWORD(v36[1].mNode.mChild[0]) = 257;
  BYTE2(v36[1].mNode.mChild[0]) = 1;
  BYTE4(v36[1].mNode.mParent) = 4;
  v37 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v37, v36);
  Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v39 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v39, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mRasterStateCharacterShadowCollectorHandle, 0x3BC715E0u, 0x455DCC70u, Inventory);
  v40 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v41 = UFG::qResourceWarehouse::Instance();
    v40 = UFG::qResourceWarehouse::GetInventory(v41, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v40;
  }
  UFG::qResourceHandle::Init(&this->mCharacterShadowCollectorShaderHandle, 0x8B5561A1, 0x17B8B4A8u, v40);
  v42 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v43 = UFG::qResourceWarehouse::Instance();
    v42 = UFG::qResourceWarehouse::GetInventory(v43, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v42;
  }
  UFG::qResourceHandle::Init(&this->mCharacterShadowCollectorLowShaderHandle, 0x8B5561A1, 0x2915C547u, v42);
  v44 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
  {
    v45 = UFG::qResourceWarehouse::Instance();
    v44 = UFG::qResourceWarehouse::GetInventory(v45, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v44;
  }
  UFG::qResourceHandle::Init(&this->mCharacterShadowCollectorHighShaderHandle, 0x8B5561A1, 0xD5D6A024, v44);
  v46 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v47 = UFG::qResourceWarehouse::Instance();
    v46 = UFG::qResourceWarehouse::GetInventory(v47, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v46;
  }
  UFG::qResourceHandle::Init(&this->mCharacterShadowCollectorAlphaStateHandle, 0x12C800F2u, 0x2782CCE6u, v46);
  v48 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v49 = UFG::qResourceWarehouse::Instance();
    v48 = UFG::qResourceWarehouse::GetInventory(v49, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v48;
  }
  UFG::qResourceHandle::Init(&this->mNoiseTextureHandle, 0x8B43FABF, 0x952102D8, v48);
  v50 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v51 = UFG::qResourceWarehouse::Instance();
    v50 = UFG::qResourceWarehouse::GetInventory(v51, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v50;
  }
  UFG::qResourceHandle::Init(&this->mAlphaStateNoColourWriteHandle, 0x12C800F2u, 0x91A2DD53, v50);
  v52 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v53 = UFG::qResourceWarehouse::Instance();
    v52 = UFG::qResourceWarehouse::GetInventory(v53, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v52;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateInvertCullingHandle, 0x3BC715E0u, 0xBC9FAF09, v52);
  v54 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v55 = UFG::qResourceWarehouse::Instance();
    v54 = UFG::qResourceWarehouse::GetInventory(v55, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v54;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateDoubleSidedHandle, 0x3BC715E0u, 0x940FB8EC, v54);
  v56 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v57 = UFG::qResourceWarehouse::Instance();
    v56 = UFG::qResourceWarehouse::GetInventory(v57, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v56;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateNormalHandle, 0x3BC715E0u, 0x20688F05u, v56);
  v58 = UFG::qStringHash32("VertexDecl.Slim", 0xFFFFFFFF);
  v59 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v60 = UFG::qResourceWarehouse::Instance();
    v59 = UFG::qResourceWarehouse::GetInventory(v60, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v59;
  }
  UFG::qResourceHandle::Init(&this->mCloudVolumePrimitiveVertexDecl, 0x3E5FDA3Eu, v58, v59);
}::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v60 = UFG::qResourceWarehouse::Instance();
    v59 = UFG::qResourceWarehouse::GetInventory(v60, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventor

// File Line: 550
// RVA: 0x38660
float __fastcall UFG::RenderStageShadow::GetCascadeShadowFOV(UFG::RenderStageShadow *this)
{
  float result; // xmm0_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  float v5; // xmm7_4
  float x; // xmm1_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float mShadowFOV; // xmm1_4

  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 )
    return FLOAT_2_0;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 )
  {
    v5 = FLOAT_3_1415927;
    x = p_mCamera->mProjection.v0.x;
    result = 0.0;
    v7 = FLOAT_0_0055555557;
    v8 = (float)(this->mMinShadowFOV * 3.1415927) * 0.0055555557;
    if ( x != 0.0 )
      result = atan2f(1.0, x) * 2.0;
    if ( result <= v8 )
      result = v8;
  }
  else
  {
    v5 = FLOAT_3_1415927;
    v7 = FLOAT_0_0055555557;
    result = (float)(this->mMinShadowFOV * 3.1415927) * 0.0055555557;
  }
  mShadowFOV = this->mShadowFOV;
  if ( mShadowFOV > -1.0 )
    return (float)(mShadowFOV * v5) * v7;
  return result;
}

// File Line: 588
// RVA: 0x3D600
void __fastcall UFG::RenderStageShadow::UpdateViews(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        float fRealTimeDelta)
{
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v6; // rax
  unsigned int v7; // esi
  float v8; // xmm10_4
  UFG::TimeOfDayManager *v9; // rax
  UFG::TimeOfDayManager *v10; // rax
  float mShadowOffset; // xmm9_4
  float cameraFov; // xmm7_4
  float z; // xmm1_4
  float mZBoundMin; // xmm6_4
  float cameraAspectRatio; // xmm0_4
  int *p_mCullIndex; // rbx
  unsigned int i; // edi
  CullManager *v18; // rax
  unsigned int v19; // eax
  UFG::qVector3 lightPos; // [rsp+60h] [rbp-88h] BYREF
  float v21; // [rsp+6Ch] [rbp-7Ch]
  UFG::qVector3 heightMapPos; // [rsp+70h] [rbp-78h] BYREF
  float v23; // [rsp+7Ch] [rbp-6Ch]
  UFG::qVector4 v24; // [rsp+88h] [rbp-60h] BYREF
  Render::RenderOutputParams outSettings; // [rsp+98h] [rbp-50h] BYREF
  CB_EnvironmentSettings envState; // [rsp+108h] [rbp+20h] BYREF
  float vars0; // [rsp+290h] [rbp+1A8h]

  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetEnvironmentSettings(Instance, &envState, &render_context->mMainViewSettings, 0i64);
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( outSettings.mShadowRes && UFG::TimeOfDayManager::GetInstance()->m_WeatherState <= 1.0 )
  {
    v6 = UFG::TimeOfDayManager::GetInstance();
    v7 = 1;
    if ( UFG::TimeOfDayManager::IsSunShining(v6, &envState) )
      v7 = 4;
  }
  else
  {
    v7 = 1;
  }
  render_context->mNumCascades = v7;
  v8 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(FLOAT_1_0001)).m128_f32[0];
  v9 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(v9, (UFG::qVector4 *)&heightMapPos.z, 1, 0);
  v10 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(v10, &v24, 1, 1);
  UFG::qInverseAffine((UFG::qMatrix44 *)&outSettings, &render_context->mMainViewSettings.mWorldView);
  mShadowOffset = this->mShadowOffset;
  v21 = *(float *)&outSettings.mMotionBlur + (float)(v23 * mShadowOffset);
  lightPos.y = *(float *)&outSettings.mMotionBlur + (float)(v24.y * mShadowOffset);
  heightMapPos.x = (float)((float)(v8 * 0.0) * mShadowOffset) + *(float *)&outSettings.mShadowFilter;
  heightMapPos.y = (float)((float)(v8 * 0.0099999998) * mShadowOffset) + *(float *)&outSettings.mMotionBlur;
  heightMapPos.z = (float)(v8 * mShadowOffset) + outSettings.mInterAxialDistance;
  lightPos.x = *(float *)&outSettings.mShadowFilter + (float)(v24.x * mShadowOffset);
  lightPos.z = outSettings.mInterAxialDistance + (float)(v24.z * mShadowOffset);
  cameraFov = UFG::RenderStageShadow::GetCascadeShadowFOV(this);
  UFG::RenderStageShadow::SetCascadeShadowParams(this, render_context);
  z = render_context->mMainViewSettings.mProjection.v2.z;
  if ( z == 0.0 || z == render_context->mMainViewSettings.mProjection.v2.w )
    mZBoundMin = vars0;
  else
    mZBoundMin = render_context->mMainViewSettings.mProjection.v3.z / z;
  if ( mZBoundMin <= this->mZBoundMin )
    mZBoundMin = this->mZBoundMin;
  cameraAspectRatio = Render::GetDisplayAspectRatio();
  UFG::RenderStageShadow::BuildCascadedShadowViews(
    this,
    render_context,
    (UFG::qMatrix44 *)&outSettings,
    mZBoundMin,
    cameraFov,
    cameraAspectRatio,
    (UFG::qVector3 *)&lightPos.z,
    &lightPos,
    &heightMapPos,
    (UFG::qVector3 *)&outSettings.mShadowFilter,
    this->mShadowNear,
    this->mShadowFar);
  p_mCullIndex = &this->mShadowViewSettings[0].mCullIndex;
  for ( i = 0; i < 4; ++i )
  {
    if ( i >= v7 )
    {
      *p_mCullIndex = -1;
    }
    else
    {
      *(_QWORD *)&outSettings.mLODSetting = 0i64;
      CullManager::CullSettings::SetFromViewSettings(
        (CullManager::CullSettings *)&outSettings,
        (Render::ViewSettings *)(p_mCullIndex - 32));
      v18 = CullManager::Instance();
      v19 = CullManager::RegisterView(v18, (CullManager::CullSettings *)&outSettings);
      *p_mCullIndex = v19;
      Illusion::eCastShadow::SetSunShadowView(v19);
    }
    p_mCullIndex += 36;
  }
}

// File Line: 666
// RVA: 0x3CC80
void __fastcall UFG::RenderStageShadow::SetCascadeShadowParams(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // eax
  float v8; // xmm0_4

  v2 = *(float *)&FLOAT_1_0;
  this->mZBoundMin = 0.0;
  if ( !render_context->mRenderFeatures.mForceLetterBox )
    v2 = (float)(Render::gScreenViewportScaleH + 1.0) * 0.5;
  if ( render_context->mRenderSettingsForFrame.mShadowRes == SHADOW_RES_HIGH )
  {
    this->mSplits[0] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT0 * this->mCascadeSplitHQ[0]) * v2;
    this->mSplits[1] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT1 * this->mCascadeSplitHQ[1]) * v2;
    this->mSplits[2] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT2 * this->mCascadeSplitHQ[2]) * v2;
    this->mBiases[0] = UFG::RenderStageShadow::DEFAULT_BIAS0 * this->mCascadeBiasHQ[0];
    this->mBiases[1] = UFG::RenderStageShadow::DEFAULT_BIAS1 * this->mCascadeBiasHQ[1];
    v3 = v2 * 0.0175;
    this->mBiases[2] = UFG::RenderStageShadow::DEFAULT_BIAS2 * this->mCascadeBiasHQ[2];
    v4 = v2;
    v5 = v2 * 0.025;
    this->mShadowFilterWidth[0] = this->mCascadeFilterWidthHQ[0];
    v6 = v4 * 0.015;
    this->mShadowFilterWidth[1] = this->mCascadeFilterWidthHQ[1];
    v7 = this->mCascadeFilterWidthHQ[2];
  }
  else
  {
    this->mSplits[0] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT0 * this->mCascadeSplit[0]) * v2;
    this->mSplits[1] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT1 * this->mCascadeSplit[1]) * v2;
    this->mSplits[2] = (float)(UFG::RenderStageShadow::DEFAULT_SPLIT2 * this->mCascadeSplit[2]) * v2;
    this->mBiases[0] = UFG::RenderStageShadow::DEFAULT_BIAS0 * this->mCascadeBias[0];
    this->mBiases[1] = UFG::RenderStageShadow::DEFAULT_BIAS1 * this->mCascadeBias[1];
    v3 = v2 * 0.035;
    this->mBiases[2] = UFG::RenderStageShadow::DEFAULT_BIAS2 * this->mCascadeBias[2];
    v8 = v2;
    v5 = v2 * 0.050000001;
    this->mShadowFilterWidth[0] = this->mCascadeFilterWidth[0];
    v6 = v8 * 0.029999999;
    this->mShadowFilterWidth[1] = this->mCascadeFilterWidth[1];
    v7 = this->mCascadeFilterWidth[2];
  }
  this->mShadowFilterWidth[2] = v7;
  this->mShadowViewSettings[2].mCullPixelDensityThreshold = v5;
  this->mShadowViewSettings[1].mCullPixelDensityThreshold = v3;
  this->mShadowViewSettings[0].mCullPixelDensityThreshold = v6;
}

// File Line: 711
// RVA: 0x3CFC0
UFG::qTaskGroup *__fastcall UFG::RenderStageShadow::SubmitCullingTasks(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context)
{
  unsigned int v4; // ebx
  int *p_mCullIndex; // rdi
  CullManager *v6; // rax
  UFG::qTaskGroup *result; // rax

  if ( render_context->mNumCascades )
  {
    v4 = 0;
    p_mCullIndex = &this->mShadowViewSettings[0].mCullIndex;
    do
    {
      v6 = CullManager::Instance();
      CullManager::BeginView(v6, *p_mCullIndex, 0i64);
      ++v4;
      p_mCullIndex += 36;
    }
    while ( v4 < render_context->mNumCascades );
    result = CullManager::Instance()->mPrevCullingTask;
    this->mNumShadowsRendered = 0;
  }
  else
  {
    this->mNumShadowsRendered = 0;
    return 0i64;
  }
  return result;
}

// File Line: 730
// RVA: 0x3D060
UFG::ShadowRenderQueueTaskResults *__fastcall UFG::RenderStageShadow::SubmitSceneryShadowTasks(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qTaskGroup *task_group_dep,
        CullLayer *cull_layer)
{
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r15
  unsigned int mNumCascades; // r13d
  unsigned int v11; // eax
  unsigned int v12; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v14; // rax
  unsigned int v15; // edi
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // ebp
  __int64 v19; // r14
  char *v20; // rax
  UFG::qTaskGroup *v21; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mTasks; // r15
  __int64 v25; // r12
  char *v26; // rbx
  UFG::qResourceData *mData; // rax
  BOOL v28; // eax
  UFG::qMatrix44 *v29; // rax
  UFG::qVector4 v30; // xmm2
  UFG::qVector4 v31; // xmm1
  UFG::qVector4 v32; // xmm0
  char *v33; // rax
  char *v34; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v40; // rax
  UFG::qMatrix44 *b; // [rsp+20h] [rbp-B8h]
  __int64 v43; // [rsp+28h] [rbp-B0h]
  UFG::qTaskGroup **v44; // [rsp+30h] [rbp-A8h]
  __int64 v45; // [rsp+38h] [rbp-A0h]
  UFG::qMatrix44 result; // [rsp+58h] [rbp-80h] BYREF
  bool mRenderRain; // [rsp+E8h] [rbp+10h]

  if ( !render_context->mNumCascades )
    return 0i64;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x340u, 0x20u);
  if ( v7 )
  {
    UFG::ShadowRenderQueueTaskResults::ShadowRenderQueueTaskResults((UFG::ShadowRenderQueueTaskResults *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v45 = v9;
  *(_DWORD *)(v9 + 800) = render_context->mNumCascades;
  mNumCascades = render_context->mNumCascades;
  mRenderRain = render_context->mRenderRain;
  v11 = _S1_8;
  if ( (_S1_8 & 1) == 0 )
  {
    _S1_8 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&simpleHandle_1);
    atexit(UFG::RenderStageShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandle__);
    v11 = _S1_8;
  }
  if ( (v11 & 2) == 0 )
  {
    _S1_8 = v11 | 2;
    UFG::qResourceHandle::qResourceHandle(&simpleHandleAlpha_0);
    atexit(UFG::RenderStageShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandleAlpha__);
  }
  if ( !simpleInit_1 )
  {
    v12 = UFG::qStringHashUpper32("DR_EMITDEPTH_ALPHA", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v14 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v14, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&simpleHandleAlpha_0, 0x8B5561A1, v12, Inventory);
    v15 = UFG::qStringHashUpper32("DR_EMITDEPTH", 0xFFFFFFFF);
    v16 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v17 = UFG::qResourceWarehouse::Instance();
      v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v16;
    }
    UFG::qResourceHandle::Init(&simpleHandle_1, 0x8B5561A1, v15, v16);
    simpleInit_1 = 1;
  }
  v18 = 0;
  if ( mNumCascades )
  {
    v44 = (UFG::qTaskGroup **)(v9 + 768);
    v19 = v9;
    v43 = v9 + 512;
    b = &this->mShadowViewSettings[0].mProjection;
    do
    {
      v20 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
      v21 = (UFG::qTaskGroup *)v20;
      if ( v20 )
        UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v20, "ShadowTaskGroup");
      mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
      mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
      mPrev->mNext = v21;
      v21->mPrev = mPrev;
      v21->mNext = &mSingleFrameTaskGroups->mNode;
      mSingleFrameTaskGroups->mNode.mPrev = v21;
      if ( task_group_dep )
        UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v21, task_group_dep);
      p_mTasks = &v21->mTasks;
      v25 = 4i64;
      do
      {
        v26 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
        *((_QWORD *)v26 + 15) = v19;
        *((_DWORD *)v26 + 32) = v18;
        *((_QWORD *)v26 + 9) = v43;
        *((_QWORD *)v26 + 10) = cull_layer;
        *((_QWORD *)v26 + 18) = simpleHandle_1.mData;
        *((_QWORD *)v26 + 12) = simpleHandleAlpha_0.mData;
        *((_QWORD *)v26 + 19) = this->mAlphaStateNoColourWriteHandle.mData;
        if ( mRenderRain || v18 == mNumCascades - 1 )
          mData = this->mRasterStateDoubleSidedHandle.mData;
        else
          mData = this->mRasterStateInvertCullingHandle.mData;
        *((_QWORD *)v26 + 20) = mData;
        *((_QWORD *)v26 + 21) = this->mRasterStateDoubleSidedHandle.mData;
        *((_DWORD *)v26 + 34) = Render::cbLocalProjectionState::sStateParamIndex;
        *((_QWORD *)v26 + 14) = Illusion::gEngine.FrameMemory;
        v28 = mRenderRain || v18 == mNumCascades - 1;
        *((_DWORD *)v26 + 26) = v28;
        *((_DWORD *)v26 + 33) = Illusion::gEngine.mFrameCount;
        *((_DWORD *)v26 + 16) = LODWORD(b[1].v0.x);
        v29 = UFG::qMatrix44::operator*(b - 1, &result, b);
        v30 = v29->v1;
        v31 = v29->v2;
        v32 = v29->v3;
        *(UFG::qVector4 *)v26 = v29->v0;
        *((UFG::qVector4 *)v26 + 1) = v30;
        *((UFG::qVector4 *)v26 + 2) = v31;
        *((UFG::qVector4 *)v26 + 3) = v32;
        v33 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
        v34 = v33;
        if ( v33 )
        {
          *(_QWORD *)v33 = v33;
          *((_QWORD *)v33 + 1) = v33;
          *((_QWORD *)v33 + 2) = v33 + 16;
          *((_QWORD *)v33 + 3) = v33 + 16;
          mSpuElf = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mSpuElf;
          mTaskFunctionSPU = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionSPU;
          mTaskFunctionPPU = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionPPU;
          mTaskFunctionOffload = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionOffload;
          if ( !gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mCurrentSPUEnabled )
          {
            mSpuElf = 0i64;
            mTaskFunctionSPU = 0i64;
            mTaskFunctionOffload = 0i64;
          }
          *((_QWORD *)v34 + 6) = v21;
          *((_DWORD *)v34 + 14) = 2;
          *((_QWORD *)v34 + 4) = 0i64;
          *((_QWORD *)v34 + 5) = 0i64;
          *((_QWORD *)v34 + 8) = &gTaskFunctionDeclData_FastShadowDrawTask_SceneDB;
          if ( mSpuElf )
            mAddress = mSpuElf->mAddress;
          else
            mAddress = 0i64;
          *((_QWORD *)v34 + 9) = mAddress;
          *((_QWORD *)v34 + 10) = mTaskFunctionSPU;
          *((_QWORD *)v34 + 11) = mTaskFunctionPPU;
          *((_QWORD *)v34 + 12) = v26;
          *((_QWORD *)v34 + 13) = 0i64;
          *((_QWORD *)v34 + 14) = 0i64;
          *((_QWORD *)v34 + 15) = 0i64;
          if ( mTaskFunctionOffload )
          {
            *((_DWORD *)v34 + 14) = 130;
            *((_DWORD *)v34 + 12) = 0;
          }
        }
        v40 = p_mTasks->mNode.mPrev;
        v40->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v34;
        *(_QWORD *)v34 = v40;
        *((_QWORD *)v34 + 1) = p_mTasks;
        p_mTasks->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v34;
        ++v21->mNumTasks;
        v19 += 32i64;
        --v25;
      }
      while ( v25 );
      UFG::qTaskManager::Queue(&UFG::gTaskManager, v21);
      *v44 = v21;
      task_group_dep = v21;
      ++v18;
      v43 += 64i64;
      ++v44;
      b = (UFG::qMatrix44 *)((char *)b + 144);
    }
    while ( v18 < mNumCascades );
    return (UFG::ShadowRenderQueueTaskResults *)v45;
  }
  return (UFG::ShadowRenderQueueTaskResults *)v9;
}

// File Line: 810
// RVA: 0x3D510
void __fastcall UFG::RenderStageShadow::UpdateCollectorMaterial(
        UFG::RenderStageShadow *this,
        Illusion::Material *sunmat,
        unsigned int csmSlice,
        bool bLowQuality,
        bool bHighQuality)
{
  unsigned int v6; // r8d
  __int64 mOffset; // rax
  unsigned int v8; // r8d
  __int64 v9; // rax
  unsigned int v10; // r8d
  __int64 v11; // rax

  if ( bHighQuality )
  {
    v6 = sunMats_high[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == v6 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v6);
    mOffset = sunmat->mMaterialUser.mOffset;
    if ( mOffset )
    {
      *(_WORD *)((char *)&sunmat->mMaterialUser.mOffset + mOffset) |= 0x20u;
      return;
    }
  }
  else if ( bLowQuality )
  {
    v8 = sunMats_low[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == v8 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v8);
    v9 = sunmat->mMaterialUser.mOffset;
    if ( v9 )
    {
      *(_WORD *)((char *)&sunmat->mMaterialUser.mOffset + v9) |= 0x20u;
      return;
    }
  }
  else
  {
    v10 = sunMats[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == v10 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v10);
    v11 = sunmat->mMaterialUser.mOffset;
    if ( v11 )
    {
      *(_WORD *)((char *)&sunmat->mMaterialUser.mOffset + v11) |= 0x20u;
      return;
    }
  }
  LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
}

// File Line: 856
// RVA: 0x3B9C0
void __fastcall UFG::RenderStageShadow::RenderShadowCollector(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        int shadowIdx,
        bool bFirst)
{
  __int64 v5; // r13
  Illusion::Target *mFullSizeScratchTargetA; // rdx
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r14
  unsigned __int16 Param; // ax
  Illusion::StateArgs *StateArgs; // r15
  unsigned int i; // r8d
  unsigned __int64 v17; // rcx
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm1
  UFG::qVector4 v20; // xmm0
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm1
  UFG::qVector4 v23; // xmm0
  unsigned __int16 v24; // ax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  float v39; // xmm0_4
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  float v42; // xmm0_4
  bool v43; // r14
  Render::eShadowFilter mShadowFilter; // eax
  bool v45; // r12
  Illusion::Material *v46; // rdi
  _WORD *v47; // rax
  UFG::qMatrix44 *p_local_world; // r8
  Illusion::Material *mShadowCollectorMaterial; // rdi
  _WORD *mOffset; // rax
  Illusion::Material *v51; // rdi
  _WORD *v52; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v55; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v56; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v57; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v58; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v59; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v60; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 local_world; // [rsp+A0h] [rbp-60h] BYREF
  Render::cbExternalViewTransformState arg; // [rsp+E0h] [rbp-20h] BYREF
  Render::cbShadowTransformState v65; // [rsp+120h] [rbp+20h] BYREF
  UFG::qMatrix44 mWorldView; // [rsp+180h] [rbp+80h] BYREF
  UFG::qMatrix44 m; // [rsp+1C0h] [rbp+C0h] BYREF
  Render::ViewSettings v68; // [rsp+200h] [rbp+100h] BYREF
  __int64 v69; // [rsp+290h] [rbp+190h]
  Render::View v70; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int128 v71[16]; // [rsp+430h] [rbp+330h] BYREF
  __int128 v72[16]; // [rsp+530h] [rbp+430h] BYREF
  RenderQueueLayer v73; // [rsp+630h] [rbp+530h] BYREF
  LayerSubmitContext ptr; // [rsp+710h] [rbp+610h] BYREF
  Render::Poly v75; // [rsp+13F0h] [rbp+12F0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+13F8h] [rbp+12F8h]

  v69 = -2i64;
  v5 = shadowIdx;
  RenderQueueLayer::RenderQueueLayer(&v73);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v73.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v73;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&v70, &render_context->mMainViewSettings, &ptr);
  if ( this->mRenderingNISCharacterShadows )
    mFullSizeScratchTargetA = render_context->mFullSizeScratchTargetA;
  else
    mFullSizeScratchTargetA = render_context->mDynamicRangeTarget;
  Render::View::BeginTarget(&v70, mFullSizeScratchTargetA, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
  if ( bFirst )
  {
    colour.r = 1.0;
    colour.g = 1.0;
    colour.b = 1.0;
    colour.a = 1.0;
    Render::View::Clear(&v70, &colour, 5u, 1.0, 0);
  }
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&v70);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  mSettings = v70.mSettings;
  p_mProjection = &v70.mSettings->mProjection;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldView = &mSettings->mWorldView;
  arg.mProjection = p_mProjection;
  arg.mCached_Remote.m_Stream = 0i64;
  StateArgs = Render::View::GetStateArgs(&v70);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  for ( i = 0; i < 4; ++i )
  {
    v17 = (unsigned __int64)i << 6;
    v18 = this->mShadowViewSettings[i].mWorldView.v1;
    v19 = this->mShadowViewSettings[i].mWorldView.v2;
    v20 = this->mShadowViewSettings[i].mWorldView.v3;
    *(__int128 *)((char *)v71 + v17) = (__int128)this->mShadowViewSettings[i].mWorldView.v0;
    *(__int128 *)((char *)&v71[1] + v17) = (__int128)v18;
    *(__int128 *)((char *)&v71[2] + v17) = (__int128)v19;
    *(__int128 *)((char *)&v71[3] + v17) = (__int128)v20;
    v21 = this->mShadowViewSettings[i].mProjection.v1;
    v22 = this->mShadowViewSettings[i].mProjection.v2;
    v23 = this->mShadowViewSettings[i].mProjection.v3;
    *(__int128 *)((char *)v72 + v17) = (__int128)this->mShadowViewSettings[i].mProjection.v0;
    *(__int128 *)((char *)&v72[1] + v17) = (__int128)v21;
    *(__int128 *)((char *)&v72[2] + v17) = (__int128)v22;
    *(__int128 *)((char *)&v72[3] + v17) = (__int128)v23;
  }
  v65.mPrev = &v65;
  v65.mNext = &v65;
  v65.mCallback = 0i64;
  v65.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v65.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v24;
    v65.mStateParamIndex = v24;
  }
  v65.mViewWorld = &v70.mViewWorld;
  v65.mWorldView = (UFG::qMatrix44 *)v71;
  v65.mProjection = (UFG::qMatrix44 *)v72;
  v65.mCutplanes = this->mCutplanes;
  v65.mBiases = this->mBiases;
  v65.mBlurWidths = this->mShadowFilterWidth;
  v65.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v65);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v75);
  y = this->mShadowViewSettings[v5].mWorldView.v0.y;
  z = this->mShadowViewSettings[v5].mWorldView.v0.z;
  w = this->mShadowViewSettings[v5].mWorldView.v0.w;
  m.v0.x = this->mShadowViewSettings[v5].mWorldView.v0.x;
  m.v0.y = y;
  m.v0.z = z;
  m.v0.w = w;
  v28 = this->mShadowViewSettings[v5].mWorldView.v1.y;
  v29 = this->mShadowViewSettings[v5].mWorldView.v1.z;
  v30 = this->mShadowViewSettings[v5].mWorldView.v1.w;
  m.v1.x = this->mShadowViewSettings[v5].mWorldView.v1.x;
  m.v1.y = v28;
  m.v1.z = v29;
  m.v1.w = v30;
  v31 = this->mShadowViewSettings[v5].mWorldView.v2.y;
  v32 = this->mShadowViewSettings[v5].mWorldView.v2.z;
  v33 = this->mShadowViewSettings[v5].mWorldView.v2.w;
  m.v2.x = this->mShadowViewSettings[v5].mWorldView.v2.x;
  m.v2.y = v31;
  m.v2.z = v32;
  m.v2.w = v33;
  v34 = this->mShadowViewSettings[v5].mWorldView.v3.y;
  v35 = this->mShadowViewSettings[v5].mWorldView.v3.z;
  v36 = this->mShadowViewSettings[v5].mWorldView.v3.w;
  m.v3.x = this->mShadowViewSettings[v5].mWorldView.v3.x;
  m.v3.y = v34;
  m.v3.z = v35;
  m.v3.w = v36;
  UFG::qInverseAffine(&d, &m);
  v37 = (__m128)(unsigned int)FLOAT_1_0;
  v37.m128_f32[0] = 1.0 / this->mShadowViewSettings[v5].mProjection.v0.x;
  d.v0 = (UFG::qVector4)_mm_mul_ps((__m128)d.v0, _mm_shuffle_ps(v37, v37, 0));
  v38 = (__m128)(unsigned int)FLOAT_1_0;
  v38.m128_f32[0] = 1.0 / this->mShadowViewSettings[v5].mProjection.v1.y;
  d.v1 = (UFG::qVector4)_mm_mul_ps((__m128)d.v1, _mm_shuffle_ps(v38, v38, 0));
  v39 = this->mShadowOffset * 0.5;
  d.v2.x = d.v2.x * v39;
  d.v2.y = d.v2.y * v39;
  d.v2.z = d.v2.z * v39;
  d.v2.w = d.v2.w * v39;
  d.v3.x = d.v3.x - (float)(d.v2.x * 2.0);
  d.v3.y = d.v3.y - (float)(d.v2.y * 2.0);
  d.v3.z = d.v3.z - (float)(d.v2.z * 2.0);
  d.v3.w = d.v3.w - (float)(d.v2.w * 2.0);
  if ( (int)v5 > 0 )
  {
    Render::ViewSettings::ViewSettings(&v68, (Render::ViewSettings *)&this->mCloudShadowCullDist + (int)v5);
    mWorldView = v68.mWorldView;
    UFG::qInverseAffine(&local_world, &mWorldView);
    v40 = (__m128)LODWORD(s_fCubeScalerConst);
    v41 = (__m128)LODWORD(s_fCubeScalerConst);
    v41.m128_f32[0] = s_fCubeScalerConst / v68.mProjection.v0.x;
    local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, _mm_shuffle_ps(v41, v41, 0));
    v40.m128_f32[0] = s_fCubeScalerConst / v68.mProjection.v1.y;
    local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, _mm_shuffle_ps(v40, v40, 0));
    v42 = this->mShadowOffset * 0.5;
    local_world.v2.x = local_world.v2.x * v42;
    local_world.v2.y = local_world.v2.y * v42;
    local_world.v2.z = local_world.v2.z * v42;
    local_world.v2.w = local_world.v2.w * v42;
    local_world.v3.x = local_world.v3.x - (float)(local_world.v2.x * 2.0);
    local_world.v3.y = local_world.v3.y - (float)(local_world.v2.y * 2.0);
    local_world.v3.z = local_world.v3.z - (float)(local_world.v2.z * 2.0);
    local_world.v3.w = local_world.v3.w - (float)(local_world.v2.w * 2.0);
  }
  v43 = 0;
  mShadowFilter = render_context->mRenderSettingsForFrame.mShadowFilter;
  v45 = mShadowFilter == SHADOW_FILTER_NORMAL;
  if ( render_context->mRenderSettingsForFrame.mShadowRes == SHADOW_RES_HIGH && mShadowFilter == SHADOW_FILTER_HIGH )
    v43 = render_context->mRenderSettingsForFrame.mFeatureLevel >= FEATURE_LEVEL_D3D11_0;
  if ( (_DWORD)v5 )
  {
    if ( (_DWORD)v5 == 1 )
    {
      Render::View::Draw(&v70, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowFar);
      UFG::RenderStageShadow::UpdateCollectorMaterial(this, render_context->mShadowCollectorMaterial, 1u, v45, v43);
      mShadowCollectorMaterial = render_context->mShadowCollectorMaterial;
      if ( *(_DWORD *)&mShadowCollectorMaterial[2].mDebugName[28] != 1342221360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mShadowCollectorMaterial[2].mDebugName[4],
          *((_DWORD *)&mShadowCollectorMaterial[2].UFG::qResourceData + 22),
          0x5000AC30u);
        mOffset = (_WORD *)mShadowCollectorMaterial->mMaterialUser.mOffset;
        if ( mOffset )
          mOffset = (_WORD *)((char *)mOffset + (_QWORD)mShadowCollectorMaterial + 120);
        *mOffset |= 0x20u;
      }
    }
    else
    {
      if ( (_DWORD)v5 != 2 )
        goto LABEL_36;
      Render::View::Draw(&v70, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowFar);
      UFG::RenderStageShadow::UpdateCollectorMaterial(this, render_context->mShadowCollectorMaterial, 2u, v45, v43);
      v51 = render_context->mShadowCollectorMaterial;
      if ( *(_DWORD *)&v51[2].mDebugName[28] != 1342221360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v51[2].mDebugName[4],
          *((_DWORD *)&v51[2].UFG::qResourceData + 22),
          0x5000AC30u);
        v52 = (_WORD *)v51->mMaterialUser.mOffset;
        if ( v52 )
          v52 = (_WORD *)((char *)v52 + (_QWORD)v51 + 120);
        *v52 |= 0x20u;
      }
    }
    p_local_world = &local_world;
  }
  else
  {
    Render::View::Draw(&v70, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowNear);
    UFG::RenderStageShadow::UpdateCollectorMaterial(this, render_context->mShadowCollectorMaterial, 0, v45, v43);
    v46 = render_context->mShadowCollectorMaterial;
    if ( *(_DWORD *)&v46[2].mDebugName[28] != 222253912 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v46[2].mDebugName[4],
        *((_DWORD *)&v46[2].UFG::qResourceData + 22),
        0xD3F5358u);
      v47 = (_WORD *)v46->mMaterialUser.mOffset;
      if ( v47 )
        v47 = (_WORD *)((char *)v47 + (_QWORD)v46 + 120);
      *v47 |= 0x20u;
    }
    p_local_world = &d;
  }
  Render::View::Draw(&v70, &gDeferredCube, p_local_world, 0, render_context->mShadowCollectorMaterial);
  *(_QWORD *)&colour.r = 0i64;
  *(_QWORD *)&colour.b = 0i64;
  Render::View::Clear(&v70, &colour, 4u, 1.0, 0);
LABEL_36:
  mPrev = v65.mPrev;
  mNext = v65.mNext;
  v65.mPrev->mNext = v65.mNext;
  mNext->mPrev = mPrev;
  v65.mPrev = &v65;
  v65.mNext = &v65;
  v65.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v65.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v65.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v65.mStateParamIndex >> 6] &= ~(1i64 << (v65.mStateParamIndex & 0x3F));
  v55 = arg.mPrev;
  v56 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v56->mPrev = v55;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v70);
  v57 = v65.mPrev;
  v58 = v65.mNext;
  v65.mPrev->mNext = v65.mNext;
  v58->mPrev = v57;
  v65.mPrev = &v65;
  v65.mNext = &v65;
  v59 = arg.mPrev;
  v60 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v60->mPrev = v59;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v73);
}

// File Line: 979
// RVA: 0x3AA80
void __fastcall UFG::RenderStageShadow::RenderCloudShadowsIntoCollector(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  Illusion::Target *mFullSizeScratchTargetA; // rdx
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  Illusion::StateArgs *StateArgs; // r15
  UFG::TimeOfDayManager *Instance; // rax
  float z; // xmm0_4
  float v15; // xmm7_4
  int v16; // xmm3_4
  int v17; // xmm4_4
  int v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float x; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm8_4
  float v24; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float v26; // xmm14_4
  float y; // xmm15_4
  unsigned int VolumetricEffects; // eax
  Render::VolumetricEffect **v29; // r13
  __int64 v30; // rsi
  Render::VolumetricEffect *v31; // rbx
  float fScale; // xmm10_4
  UFG::qVector4 v33; // xmm2
  UFG::qVector4 v34; // xmm1
  UFG::qVector4 v35; // xmm0
  float v36; // xmm9_4
  float v37; // xmm4_4
  float w; // xmm5_4
  float v39; // xmm8_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm9_4
  float v43; // xmm9_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  int v50; // r14d
  bool v51; // si
  __int64 v52; // rax
  float v53; // xmm0_4
  __int128 v54; // xmm2
  __int128 v55; // xmm1
  __int128 v56; // xmm0
  __int128 v57; // xmm2
  __int128 v58; // xmm1
  __int128 v59; // xmm0
  unsigned __int16 v60; // ax
  Illusion::Material *mMatCloudShadowVolume; // rbx
  _WORD *mOffset; // rax
  Illusion::Material *v63; // rbx
  __int64 v64; // rax
  _WORD *v65; // rax
  Illusion::Primitive *v66; // rbx
  float v67; // xmm9_4
  float v68; // xmm8_4
  float v69; // xmm7_4
  float v70; // xmm6_4
  UFG::qVector3 *v71; // rsi
  Illusion::Material *v72; // rsi
  __int64 v73; // rax
  _WORD *v74; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v77; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v78; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v79; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v80; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v81; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v82; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-B0h] BYREF
  float v84; // [rsp+60h] [rbp-A0h]
  float v85; // [rsp+64h] [rbp-9Ch]
  float v86; // [rsp+68h] [rbp-98h]
  float v87; // [rsp+6Ch] [rbp-94h]
  float distance_from_near_plane; // [rsp+70h] [rbp-90h] BYREF
  float v89; // [rsp+74h] [rbp-8Ch]
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-88h] BYREF
  UFG::qMatrix44 local_world; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v92; // [rsp+F0h] [rbp-10h]
  Render::cbShadowTransformState v93; // [rsp+100h] [rbp+0h] BYREF
  UFG::qVector3 pos; // [rsp+160h] [rbp+60h] BYREF
  UFG::qVector3 ray_pos; // [rsp+16Ch] [rbp+6Ch] BYREF
  int v96[4]; // [rsp+178h] [rbp+78h]
  UFG::qVector3 ray_dir; // [rsp+188h] [rbp+88h] BYREF
  UFG::qVector3 scale; // [rsp+194h] [rbp+94h] BYREF
  UFG::qColour v99; // [rsp+1A0h] [rbp+A0h] BYREF
  int v100[4]; // [rsp+1B0h] [rbp+B0h]
  __int64 v101[2]; // [rsp+1C0h] [rbp+C0h] BYREF
  UFG::qColour v102; // [rsp+1D0h] [rbp+D0h] BYREF
  UFG::qVector4 plane; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qMatrix44 v104; // [rsp+1F0h] [rbp+F0h] BYREF
  UFG::qMatrix44 v105; // [rsp+230h] [rbp+130h] BYREF
  UFG::qMatrix44 d; // [rsp+270h] [rbp+170h] BYREF
  __int64 v107; // [rsp+2B0h] [rbp+1B0h]
  __int128 v108[8]; // [rsp+2C0h] [rbp+1C0h] BYREF
  UFG::qVector4 dir; // [rsp+340h] [rbp+240h] BYREF
  UFG::qMatrix44 dest; // [rsp+350h] [rbp+250h] BYREF
  UFG::qMatrix44 v111; // [rsp+390h] [rbp+290h] BYREF
  Render::View v112; // [rsp+3D0h] [rbp+2D0h] BYREF
  RenderQueueLayer v113; // [rsp+560h] [rbp+460h] BYREF
  ClipCube v114; // [rsp+640h] [rbp+540h] BYREF
  LayerSubmitContext ptr; // [rsp+880h] [rbp+780h] BYREF
  Render::VolumetricEffect *pBuffer[512]; // [rsp+1500h] [rbp+1400h] BYREF
  Illusion::StateArgs *vertex_count; // [rsp+25E0h] [rbp+24E0h] BYREF
  float v118; // [rsp+25F8h] [rbp+24F8h]

  v107 = -2i64;
  if ( this->mEnableCloudShadows )
  {
    RenderQueueLayer::RenderQueueLayer(&v113);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v113.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v113;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&v112, &render_context->mMainViewSettings, &ptr);
    if ( this->mRenderingNISCharacterShadows )
      mFullSizeScratchTargetA = render_context->mFullSizeScratchTargetA;
    else
      mFullSizeScratchTargetA = render_context->mDynamicRangeTarget;
    Render::View::BeginTarget(&v112, mFullSizeScratchTargetA, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
    colour.r = 1.0;
    colour.g = 1.0;
    colour.b = 1.0;
    colour.a = 1.0;
    Render::View::Clear(&v112, &colour, 4u, 1.0, 0);
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(&v112);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mSettings = v112.mSettings;
    p_mProjection = &v112.mSettings->mProjection;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mWorldView = &mSettings->mWorldView;
    arg.mProjection = p_mProjection;
    arg.mCached_Remote.m_Stream = 0i64;
    StateArgs = Render::View::GetStateArgs(&v112);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    Instance = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetSunDir(Instance, &dir, 1, 0);
    UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
    z = render_context->mMainViewSettings.mProjection.v2.z;
    if ( z == 0.0 || z == render_context->mMainViewSettings.mProjection.v2.w )
      v15 = *(float *)&vertex_count;
    else
      v15 = render_context->mMainViewSettings.mProjection.v3.z / z;
    v118 = v15;
    v16 = LODWORD(d.v2.z) ^ _xmm[0];
    v17 = LODWORD(d.v2.y) ^ _xmm[0];
    v18 = LODWORD(d.v2.x) ^ _xmm[0];
    v19 = (float)((float)(*(float *)&v17 * *(float *)&v17) + (float)(*(float *)&v18 * *(float *)&v18))
        + (float)(*(float *)&v16 * *(float *)&v16);
    if ( v19 == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / fsqrt(v19);
    v87 = v20 * *(float *)&v16;
    v85 = v20 * *(float *)&v17;
    v84 = *(float *)&v18 * v20;
    x = render_context->mMainViewSettings.mProjection.v0.x;
    if ( x == 0.0 )
      v22 = 0.0;
    else
      v22 = atan2f(1.0, x) * 2.0;
    v23 = FLOAT_0_5;
    v24 = tanf(v22 * 0.5);
    DisplayAspectRatio = Render::GetDisplayAspectRatio();
    v26 = d.v3.x;
    y = d.v3.y;
    v86 = d.v3.z;
    v89 = fsqrt(
            (float)((float)((float)(v24 * v15) * (float)(v24 * v15))
                  + (float)((float)((float)(v24 / DisplayAspectRatio) * v15)
                          * (float)((float)(v24 / DisplayAspectRatio) * v15)))
          + (float)(v15 * v15));
    ClipCube::ClipCube(&v114);
    VolumetricEffects = Render::VolumetricEffectManager::GetVolumetricEffects(
                          &Render::gVolumetricEffectManager,
                          pBuffer,
                          0x200u);
    if ( VolumetricEffects )
    {
      v29 = pBuffer;
      v30 = VolumetricEffects;
      v92 = VolumetricEffects;
      while ( 1 )
      {
        v31 = *v29;
        fScale = (*v29)->fScale;
        if ( (float)((float)(fScale * fScale) * fScale) >= this->mCloudShadowMinVolume )
          break;
LABEL_69:
        ++v29;
        v92 = --v30;
        if ( !v30 )
          goto LABEL_70;
      }
      v33 = v31->mTransform.v1;
      v34 = v31->mTransform.v2;
      v35 = v31->mTransform.v3;
      local_world.v0 = v31->mTransform.v0;
      local_world.v1 = v33;
      local_world.v2 = v34;
      local_world.v3 = v35;
      v36 = this->mShadowOffset * v23;
      if ( fScale <= v36 )
        v37 = this->mShadowOffset * v23;
      else
        v37 = fScale;
      w = v31->mRotationMtx.v2.w;
      v39 = v31->mRotationMtx.v2.z;
      v40 = v31->mRotationMtx.v2.y;
      v41 = v31->mRotationMtx.v2.x;
      local_world.v2.x = v41 * v37;
      local_world.v2.y = v40 * v37;
      local_world.v2.z = v39 * v37;
      local_world.v2.w = w * v37;
      v42 = v36 - fScale;
      local_world.v3.x = local_world.v3.x + (float)(v41 * v42);
      local_world.v3.y = local_world.v3.y + (float)(v40 * v42);
      local_world.v3.z = local_world.v3.z + (float)(v39 * v42);
      local_world.v3.w = local_world.v3.w + (float)(w * v42);
      pos.x = v26;
      pos.y = y;
      v43 = v86;
      pos.z = v86;
      ray_dir.x = v41;
      ray_dir.y = v40;
      ray_dir.z = v39;
      v44 = v31->mTransform.v3.y;
      v45 = v31->mTransform.v3.z;
      ray_pos.x = v31->mTransform.v3.x;
      ray_pos.y = v44;
      ray_pos.z = v45;
      if ( UFG::qDistanceRayPoint(&ray_pos, &ray_dir, &pos) > this->mCloudShadowCullDist
        || (distance_from_near_plane = 0.0,
            !Render::View::IsInView(&v112, &gDeferredCube, &local_world, &distance_from_near_plane)) )
      {
LABEL_68:
        v23 = FLOAT_0_5;
        goto LABEL_69;
      }
      UFG::qInverse(&v104, &local_world);
      v46 = (float)((float)((float)(v104.v1.x * y) + (float)(v104.v0.x * v26)) + (float)(v104.v2.x * v43)) + v104.v3.x;
      v47 = (float)((float)((float)(v104.v1.y * y) + (float)(v104.v0.y * v26)) + (float)(v104.v2.y * v43)) + v104.v3.y;
      v48 = (float)((float)((float)(v104.v1.z * y) + (float)(v104.v0.z * v26)) + (float)(v104.v2.z * v43)) + v104.v3.z;
      v49 = (float)((float)((float)(v104.v1.w * y) + (float)(v104.v0.w * v26)) + (float)(v104.v2.w * v43)) + v104.v3.w;
      if ( v49 < 0.0 )
        LODWORD(v49) ^= _xmm[0];
      if ( v48 < 0.0 )
        LODWORD(v48) ^= _xmm[0];
      if ( v47 < 0.0 )
        LODWORD(v47) ^= _xmm[0];
      if ( v46 < 0.0 )
        LODWORD(v46) ^= _xmm[0];
      *(float *)v100 = v46;
      *(float *)&v100[1] = v47;
      *(float *)&v100[2] = v48;
      *(float *)&v100[3] = v49;
      *(float *)v96 = v89 / fScale;
      *(float *)&v96[1] = v89 / fScale;
      *(float *)&v96[2] = v89 / fScale;
      v50 = 1;
      v51 = 0;
      v52 = 0i64;
      while ( 1 )
      {
        v53 = *(float *)&v100[v52];
        if ( v53 > 1.0 )
          break;
        if ( ++v52 >= 3 )
          goto LABEL_38;
      }
      v51 = (float)(*(float *)&v96[v52] + 1.0) > v53;
      v50 = 2;
LABEL_38:
      v54 = (__int128)v31->mTransformInv.v1;
      v55 = (__int128)v31->mTransformInv.v2;
      v56 = (__int128)v31->mTransformInv.v3;
      v108[0] = (__int128)v31->mTransformInv.v0;
      v108[1] = v54;
      v108[2] = v55;
      v108[3] = v56;
      v57 = (__int128)v31->mRotationMtxInv.v1;
      v58 = (__int128)v31->mRotationMtxInv.v2;
      v59 = (__int128)v31->mRotationMtxInv.v3;
      v108[4] = (__int128)v31->mRotationMtxInv.v0;
      v108[5] = v57;
      v108[6] = v58;
      v108[7] = v59;
      scale.x = 1.0;
      scale.y = -1.0;
      scale.z = 0.5;
      UFG::qScaleMatrix(&dest, &scale);
      dest.v3.z = 0.5;
      colour.r = 2.0;
      colour.g = -2.0;
      colour.b = 1.0;
      UFG::qScaleMatrix(&v111, (UFG::qVector3 *)&colour);
      v111.v3.x = -0.5;
      v111.v3.y = -0.5;
      v101[0] = 0i64;
      v101[1] = 0i64;
      v93.mPrev = &v93;
      v93.mNext = &v93;
      v93.mCallback = 0i64;
      v93.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
      *(_WORD *)&v93.mFlags = 1;
      if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
      {
        v60 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
        Render::cbShadowTransformState::sStateParamIndex = v60;
        v93.mStateParamIndex = v60;
      }
      v93.mViewWorld = &v112.mViewWorld;
      v93.mWorldView = (UFG::qMatrix44 *)v108;
      v93.mProjection = &dest;
      v93.mCutplanes = 0i64;
      v93.mBiases = (const float *)v101;
      v93.mBlurWidths = 0i64;
      v93.mCached_Remote.m_Stream = 0i64;
      Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v93);
      mMatCloudShadowVolume = this->mMatCloudShadowVolume;
      if ( LODWORD(mMatCloudShadowVolume[3].mNode.mChild[0]) != Render::gCloudVolumeManager.mVolumeTextureUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mMatCloudShadowVolume[2].mNumParams,
          (unsigned int)mMatCloudShadowVolume[3].mNode.mChild[1],
          Render::gCloudVolumeManager.mVolumeTextureUID);
        mOffset = (_WORD *)mMatCloudShadowVolume->mMaterialUser.mOffset;
        if ( mOffset )
          mOffset = (_WORD *)((char *)mOffset + (_QWORD)mMatCloudShadowVolume + 120);
        *mOffset |= 0x20u;
      }
      if ( v50 == 1 )
      {
        *(_QWORD *)&v99.r = 0i64;
        *(_QWORD *)&v99.b = 0i64;
        Render::View::Clear(&v112, &v99, 4u, 1.0, 0);
        Render::View::Draw(&v112, &gDeferredCube, &local_world, 0, this->mMatStencilWriteShadowNear);
        v63 = this->mMatCloudShadowVolume;
        if ( *(_DWORD *)&v63[2].mDebugName[28] != 222253912 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v63[2].mDebugName[4],
            *((_DWORD *)&v63[2].UFG::qResourceData + 22),
            0xD3F5358u);
          v64 = v63->mMaterialUser.mOffset;
          if ( v64 )
            v65 = (_WORD *)((char *)&v63->mMaterialUser + v64);
          else
            v65 = 0i64;
          *v65 |= 0x20u;
        }
      }
      else
      {
        v66 = 0i64;
        if ( v51 )
        {
          v67 = v87;
          v68 = v85;
          v69 = v84;
          v70 = (float)((float)((float)((float)(v84 * 0.001) + (float)((float)(v84 * v118) + d.v3.x))
                              * COERCE_FLOAT(LODWORD(v84) ^ _xmm[0]))
                      + (float)((float)((float)(v85 * 0.001) + (float)((float)(v85 * v118) + d.v3.y))
                              * COERCE_FLOAT(LODWORD(v85) ^ _xmm[0])))
              + (float)((float)((float)(v87 * 0.001) + (float)((float)(v87 * v118) + d.v3.z))
                      * COERCE_FLOAT(LODWORD(v87) ^ _xmm[0]));
          UFG::qTranspose(&v105, &local_world);
          plane.x = (float)((float)((float)(v105.v1.x * v68) + (float)(v105.v0.x * v69)) + (float)(v105.v2.x * v67))
                  + (float)(v105.v3.x * v70);
          plane.y = (float)((float)((float)(v105.v1.y * v68) + (float)(v105.v0.y * v69)) + (float)(v105.v2.y * v67))
                  + (float)(v105.v3.y * v70);
          plane.z = (float)((float)((float)(v105.v1.z * v68) + (float)(v105.v0.z * v69)) + (float)(v105.v2.z * v67))
                  + (float)(v105.v3.z * v70);
          plane.w = (float)((float)((float)(v105.v1.w * v68) + (float)(v105.v0.w * v69)) + (float)(v105.v2.w * v67))
                  + (float)(v105.v3.w * v70);
          ClipCube::Reset(&v114);
          ClipCube::ClipToPlane(&v114, &plane);
          if ( ClipCube::GetClipCount(&v114) )
          {
            LODWORD(vertex_count) = 0;
            v71 = ClipCube::GenerateCube(&v114, (unsigned int *)&vertex_count);
            if ( (_DWORD)vertex_count )
            {
              v66 = Illusion::Primitive::Create("ClipCube");
              Illusion::Primitive::SetBuffers(
                v66,
                TRIANGLELIST,
                v71,
                (const int)vertex_count,
                (Illusion::VertexDecl *)this->mCloudVolumePrimitiveVertexDecl.mData,
                0i64,
                0,
                1);
            }
          }
        }
        *(_QWORD *)&v102.r = 0i64;
        *(_QWORD *)&v102.b = 0i64;
        Render::View::Clear(&v112, &v102, 4u, 1.0, 0);
        if ( v66 )
          Render::View::Draw(&v112, v66, this->mMatStencilWriteShadowFar, &local_world);
        else
          Render::View::Draw(&v112, &gDeferredCube, &local_world, 0, this->mMatStencilWriteShadowFar);
        v72 = this->mMatCloudShadowVolume;
        if ( *(_DWORD *)&v72[2].mDebugName[28] != -460843872 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v72[2].mDebugName[4],
            *((_DWORD *)&v72[2].UFG::qResourceData + 22),
            0xE48814A0);
          v73 = v72->mMaterialUser.mOffset;
          if ( v73 )
            v74 = (_WORD *)((char *)&v72->mMaterialUser + v73);
          else
            v74 = 0i64;
          *v74 |= 0x20u;
        }
        if ( v66 )
        {
          Render::View::Draw(&v112, v66, this->mMatCloudShadowVolume, &local_world);
LABEL_65:
          mPrev = v93.mPrev;
          mNext = v93.mNext;
          v93.mPrev->mNext = v93.mNext;
          mNext->mPrev = mPrev;
          v93.mPrev = &v93;
          v93.mNext = &v93;
          v93.mIsSet = 0;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v93.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v93.mStateParamIndex] )
            StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v93.mStateParamIndex >> 6] &= ~(1i64 << (v93.mStateParamIndex & 0x3F));
          v77 = v93.mPrev;
          v78 = v93.mNext;
          v93.mPrev->mNext = v93.mNext;
          v78->mPrev = v77;
          v93.mPrev = &v93;
          v93.mNext = &v93;
          v30 = v92;
          goto LABEL_68;
        }
      }
      Render::View::Draw(&v112, &gDeferredCube, &local_world, 0, this->mMatCloudShadowVolume);
      goto LABEL_65;
    }
LABEL_70:
    v79 = arg.mPrev;
    v80 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v80->mPrev = v79;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&v112);
    v81 = arg.mPrev;
    v82 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v82->mPrev = v81;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    vertex_count = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v113);
  }
}

// File Line: 1251
// RVA: 0x38400
void __fastcall UFG::RenderStageShadow::DownsampleShadows(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  _WORD *v6; // rbx
  unsigned int mUID; // r8d
  Illusion::Material *mMatDepthDownsampleShadow; // rdi
  __int64 mOffset; // rax
  _WORD *v10; // rax
  unsigned int v11; // r8d
  Illusion::Material *v12; // rdi
  __int64 v13; // rax
  Render::View v14; // [rsp+60h] [rbp-F08h] BYREF
  RenderQueueLayer v15; // [rsp+1F0h] [rbp-D78h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h] BYREF
  Render::Poly poly; // [rsp+F70h] [rbp+8h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+F78h] [rbp+10h]

  RenderQueueLayer::RenderQueueLayer(&v15);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v15.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v15;
  v6 = 0i64;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&v14, &render_context->mMainViewSettings, &ptr);
  Render::View::BeginTarget(&v14, render_context->mHalfSizeShadowTarget, "HalfSizeShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v14, &UFG::qColour::Black, 6u, 1.0, 0);
  mUID = render_context->mCascadeShadowTextureAliasDepth->mNode.mUID;
  mMatDepthDownsampleShadow = this->mMatDepthDownsampleShadow;
  if ( LODWORD(mMatDepthDownsampleShadow[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMatDepthDownsampleShadow[1].mDebugName[20],
      mMatDepthDownsampleShadow[1].mStateBlockMask.mFlags[1],
      mUID);
    mOffset = mMatDepthDownsampleShadow->mMaterialUser.mOffset;
    if ( mOffset )
      v10 = (_WORD *)((char *)&mMatDepthDownsampleShadow->mMaterialUser + mOffset);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v14, &poly, this->mMatDepthDownsampleShadow, 0i64);
  Render::View::EndTarget(&v14);
  Render::View::BeginTarget(&v14, render_context->mQuarterSizeShadowTarget, "QuarterSizeShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v14, &UFG::qColour::Black, 6u, 1.0, 0);
  v11 = render_context->mHalfSizeShadowTarget->mDepthTexture->mNode.mUID;
  v12 = this->mMatDepthDownsampleShadow;
  if ( LODWORD(v12[1].mStateBlockMask.mFlags[0]) != v11 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[1].mDebugName[20], v12[1].mStateBlockMask.mFlags[1], v11);
    v13 = v12->mMaterialUser.mOffset;
    if ( v13 )
      v6 = (_WORD *)((char *)&v12->mMaterialUser + v13);
    *v6 |= 0x20u;
  }
  Render::View::Draw(&v14, &poly, this->mMatDepthDownsampleShadow, 0i64);
  Render::View::EndTarget(&v14);
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v15);
}

// File Line: 1302
// RVA: 0x3C3F0
UFG::ShadowRenderQueueSimResults *__fastcall UFG::RenderStageShadow::RenderSunShadowsSim(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        CullLayer *simple_drawable_cull_layer,
        CullLayer *composite_cull_layer)
{
  CullLayer *v4; // r14
  UFG::RenderContext *v5; // r13
  UFG::RenderStageShadow *v6; // r15
  unsigned int mNumCascades; // ebx
  char *v8; // rax
  unsigned int v9; // edi
  __int64 v10; // rax
  __int64 v11; // r12
  bool v12; // si
  unsigned int v13; // r8d
  unsigned int mCullIndex; // ebx
  CullManager *v15; // rax
  Illusion::StateArgs *StateArgs; // rsi
  UFG::qMatrix44 *p_mProjection; // rbx
  unsigned __int16 Param; // ax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v21; // rbx
  Illusion::StateValues *StateValues; // rax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *v24; // rax
  __int64 v25; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rcx
  __int64 v27; // rbx
  unsigned int v28; // esi
  __int64 v29; // r14
  __int64 v30; // r8
  __int64 v31; // rdx
  float v32; // xmm1_4
  unsigned int LOD; // eax
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // rbx
  unsigned int v37; // esi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  unsigned int v42; // eax
  Illusion::RenderQueue **p_queues; // rsi
  int *p_mCullIndex; // r14
  __int64 v45; // r12
  __int64 v46; // r15
  char *v47; // rax
  char *v48; // rbx
  CullManager *v49; // rax
  __int64 v50; // r14
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v51; // rsi
  Illusion::Target **v52; // rbx
  CullManager *v53; // rax
  bool v55; // [rsp+50h] [rbp-B0h]
  unsigned int v56; // [rsp+54h] [rbp-ACh]
  unsigned int v57; // [rsp+58h] [rbp-A8h]
  unsigned int v58; // [rsp+58h] [rbp-A8h]
  unsigned int v59; // [rsp+60h] [rbp-A0h]
  Illusion::StateArgs *v60; // [rsp+68h] [rbp-98h]
  Render::cbViewTransformState arg; // [rsp+70h] [rbp-90h] BYREF
  __int64 v62; // [rsp+C0h] [rbp-40h]
  __int64 v63; // [rsp+C8h] [rbp-38h]
  const char *v64; // [rsp+D0h] [rbp-30h]
  __int64 v65; // [rsp+D8h] [rbp-28h]
  int v66; // [rsp+E0h] [rbp-20h]
  __int64 v67; // [rsp+E8h] [rbp-18h]
  __int64 v68; // [rsp+F0h] [rbp-10h]
  const char *v69; // [rsp+F8h] [rbp-8h]
  __int64 v70; // [rsp+100h] [rbp+0h]
  int v71; // [rsp+108h] [rbp+8h]
  __int64 v72; // [rsp+110h] [rbp+10h]
  __int64 v73[2]; // [rsp+118h] [rbp+18h] BYREF
  __int64 v74[4]; // [rsp+128h] [rbp+28h] BYREF
  int v75; // [rsp+148h] [rbp+48h]
  __int64 v76; // [rsp+150h] [rbp+50h]
  AMD_HD3D *v77; // [rsp+158h] [rbp+58h]
  Illusion::RenderQueue *queues; // [rsp+160h] [rbp+60h] BYREF
  Render::View view; // [rsp+180h] [rbp+80h] BYREF
  RenderQueueLayer v80; // [rsp+310h] [rbp+210h] BYREF
  ShadowSubmitContext ptr; // [rsp+3F0h] [rbp+2F0h] BYREF

  v76 = -2i64;
  v4 = simple_drawable_cull_layer;
  v5 = render_context;
  v6 = this;
  mNumCascades = render_context->mNumCascades;
  v56 = mNumCascades;
  if ( !mNumCascades )
    return 0i64;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x118u, 8u);
  v9 = 0;
  if ( v8 )
  {
    UFG::ShadowRenderQueueSimResults::ShadowRenderQueueSimResults((UFG::ShadowRenderQueueSimResults *)v8);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v62 = v11;
  *(_DWORD *)v11 = mNumCascades;
  v12 = !v5->mRenderRain;
  v55 = v12;
  if ( (UFG::RenderWorld::msIsNisPlaying
     || v6->mDebugEnableCharacterNISShadow
     || v5->mRenderSettingsForFrame.mShadowRes == SHADOW_RES_HIGH
     && UFG::RenderWorld::msStageEnvMap->mInteriorBlend > 0.000001)
    && !v5->mRenderRain
    && v5->mRenderFeatures.mLights
    && v5->mRenderFeatures.mWorld
    && v5->mRenderSun )
  {
    v6->mRenderingNISCharacterShadows = 1;
  }
  RenderQueueLayer::RenderQueueLayer(&v80);
  ShadowSubmitContext::ShadowSubmitContext(&ptr);
  v74[0] = 0i64;
  v74[1] = 0i64;
  v75 = 0;
  v74[3] = -1i64;
  v74[2] = -1i64;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v80;
  ptr.mRenderPass = Depth;
  ptr.mShaderSelector = (Illusion::ShaderSelector *)v74;
  v73[1] = (__int64)v6->mAlphaStateNoColourWriteHandle.mData;
  v73[0] = (__int64)v6->mRasterStateInvertCullingHandle.mData;
  ptr.mPerPhaseParams = (ShadowSubmitContext::PerPhaseParams *)v73;
  if ( !v12 )
    goto LABEL_52;
  if ( mNumCascades > 1 )
  {
    v13 = 0;
    v59 = 0;
    v57 = mNumCascades - 2;
    if ( mNumCascades != 2 )
    {
      do
      {
        v80.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 16i64 * v13 + 40);
        Render::View::View(&view, &v6->mShadowViewSettings[v13], &ptr);
        mCullIndex = view.mSettings->mCullIndex;
        v15 = CullManager::Instance();
        CullManager::EndView(v15, mCullIndex);
        Render::View::BeginTarget(&view, v5->mCascadeShadowTarget, "CascadeShadowTarget", 0, 0, 0i64, 1, 0, 1, 0);
        StateArgs = Render::View::GetStateArgs(&view);
        v60 = StateArgs;
        p_mProjection = &view.mSettings->mProjection;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
        {
          Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
          Render::cbViewTransformState::sStateParamIndex = Param;
          arg.mStateParamIndex = Param;
        }
        arg.mWorldViewProjection = &view.mWorldViewProjection;
        arg.mViewWorld = &view.mViewWorld;
        arg.mProjection = p_mProjection;
        arg.mScreenOffset = &Render::View::mScreenOffset;
        arg.mCached_Remote.m_Stream = 0i64;
        mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
        mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
        v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
        *(float *)v21 = mSimTime_Temp;
        *((float *)v21 + 1) = mSimTimeDelta;
        StateValues = Render::View::GetStateValues(&view);
        StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
        StateValues->mParamValues[13] = v21;
        mEnvState = v5->mEnvState;
        v24 = Render::View::GetStateValues(&view);
        v24->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
        v24->mParamValues[55] = mEnvState;
        Illusion::StateArgs::Set<Render::cbViewTransformState>(StateArgs, &arg);
        if ( composite_cull_layer )
        {
          v25 = view.mSettings->mCullIndex;
          if ( (int)v25 >= 0 && (int)v25 <= 16 && composite_cull_layer->mDrawEnabled )
            mHead = composite_cull_layer->mCullResultBuckets[v25].mHead;
          else
            mHead = 0i64;
          v63 = 0i64;
          v64 = "CullResultBucketIterator";
          v27 = (__int64)mHead;
          v65 = (__int64)mHead;
          v66 = 0;
          v28 = 0;
          v67 = 0i64;
          if ( mHead )
          {
            do
            {
              v29 = *(_QWORD *)(v27 + 8i64 * v28 + 24);
              if ( (*(_BYTE *)(v29 + 32) & 3) == 1 && !*(_BYTE *)(v29 + 1240) )
              {
                v30 = *(_QWORD *)(v29 + 1256);
                if ( v30 )
                {
                  v31 = v5->mMainViewSettings.mCullIndex;
                  if ( (int)v31 > 16 || (int)v31 < 0 || (unsigned __int8)(*(_BYTE *)(v31 + v30) - 4) > 1u )
                  {
                    if ( (int)v31 >= 6 )
                      v32 = *(float *)&FLOAT_1_0;
                    else
                      v32 = *(float *)(v30 + 4 * v31 + 40);
                    LOD = UFG::CompositeDrawableComponent::GetLOD(
                            *(UFG::CompositeDrawableComponent **)(v27 + 8i64 * v28 + 24),
                            v32);
                    UFG::CompositeDrawableComponent::Draw((UFG::CompositeDrawableComponent *)v29, &view, LOD);
                  }
                }
              }
              LODWORD(v67) = ++v28;
              if ( v28 == *(_DWORD *)(v27 + 8) )
              {
                v27 = *(_QWORD *)v27;
                v65 = v27;
                v28 = 0;
                LODWORD(v67) = 0;
              }
            }
            while ( v27 );
            HIDWORD(v67) = 0;
            v6 = this;
            v4 = simple_drawable_cull_layer;
          }
          else
          {
            v6 = this;
          }
        }
        if ( v4 )
        {
          v34 = view.mSettings->mCullIndex;
          if ( (int)v34 >= 0 && (int)v34 <= 16 && v4->mDrawEnabled )
            v35 = (__int64)v4->mCullResultBuckets[v34].mHead;
          else
            v35 = 0i64;
          v68 = 0i64;
          v69 = "CullResultBucketIterator";
          v36 = v35;
          v70 = v35;
          v71 = 0;
          v37 = 0;
          v72 = 0i64;
          if ( v35 )
          {
            do
            {
              Render::SimpleDrawableComponent::Draw(
                *(Render::SimpleDrawableComponent **)(v36 + 8i64 * v37++ + 24),
                &view);
              LODWORD(v72) = v37;
              if ( v37 == *(_DWORD *)(v36 + 8) )
              {
                v36 = *(_QWORD *)v36;
                v70 = v36;
                v37 = 0;
                LODWORD(v72) = 0;
              }
            }
            while ( v36 );
            HIDWORD(v72) = 0;
          }
          v4 = simple_drawable_cull_layer;
        }
        mPrev = arg.mPrev;
        mNext = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        mNext->mPrev = mPrev;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v60->mStateArgs[arg.mStateParamIndex].mNode.mNext == &v60->mStateArgs[arg.mStateParamIndex] )
          v60->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        RenderQueueLayer::SerializeRenderQueues(&v80);
        v40 = arg.mPrev;
        v41 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v41->mPrev = v40;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        v13 = v59 + 1;
        v59 = v13;
      }
      while ( v13 < v57 );
      mNumCascades = v56;
    }
LABEL_52:
    if ( mNumCascades > 1 && UFG::TimeOfDayManager::GetInstance()->m_WeatherState <= 1.0 )
    {
      v42 = mNumCascades - 2;
      v58 = mNumCascades - 2;
      if ( mNumCascades != 2 )
      {
        p_queues = &queues;
        p_mCullIndex = &v6->mShadowViewSettings[0].mCullIndex;
        v45 = v11 - (_QWORD)&queues;
        v46 = v42;
        do
        {
          v47 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
          v48 = v47;
          if ( v47 )
          {
            *(_QWORD *)v47 = v47;
            *((_QWORD *)v47 + 1) = v47;
            v77 = (AMD_HD3D *)(v47 + 16);
            *((_QWORD *)v47 + 2) = v47 + 16;
            *((_QWORD *)v47 + 3) = v47 + 16;
            UFG::qMemSet(v47 + 96, 0, 0x400u);
            *((_QWORD *)v48 + 11) = 0i64;
            *((_QWORD *)v48 + 10) = 0i64;
            *((_DWORD *)v48 + 8) = 0;
            *((_QWORD *)v48 + 5) = 0i64;
            *((_QWORD *)v48 + 6) = 0i64;
            *((_QWORD *)v48 + 7) = 0i64;
            *((_QWORD *)v48 + 8) = 0i64;
            *((_QWORD *)v48 + 9) = 0i64;
          }
          else
          {
            v48 = 0i64;
          }
          *p_queues = (Illusion::RenderQueue *)v48;
          if ( !v55 )
          {
            v49 = CullManager::Instance();
            CullManager::EndView(v49, (unsigned int)*p_mCullIndex);
          }
          *(Illusion::RenderQueue **)((char *)p_queues + v45 + 120) = *p_queues;
          ++p_queues;
          p_mCullIndex += 36;
          --v46;
        }
        while ( v46 );
        v5 = render_context;
        v42 = v58;
        v6 = this;
        v11 = v62;
        mNumCascades = v56;
      }
      FastShadowDraw_Dynamic(v6->mShadowViewSettings, v5->mMainViewSettings.mCullIndex, &queues, v42);
    }
  }
  v50 = mNumCascades - 1;
  if ( mNumCascades != 1 )
  {
    v51 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 152);
    v52 = (Illusion::Target **)(v11 + 8);
    do
    {
      *v52 = v5->mCascadeShadowTarget;
      if ( v5->mRenderSun && v5->mRenderFeatures.mLights && v5->mRenderFeatures.mWorld )
      {
        if ( v9 == v56 - 2 )
          UFG::RenderStageShadow::DownsampleShadows(
            v6,
            v5,
            (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 104));
        UFG::RenderStageShadow::RenderShadowCollector(v6, v5, v51, v9, v9 == 0);
      }
      ++v9;
      ++v52;
      ++v51;
    }
    while ( v9 < (unsigned int)v50 );
    mNumCascades = v56;
  }
  v53 = CullManager::Instance();
  CullManager::EndView(v53, (unsigned int)v6->mShadowViewSettings[mNumCascades - 1].mCullIndex);
  *(_QWORD *)(v11 + 8 * v50 + 8) = v5->mHeightmapTarget;
  if ( v5->mRenderSun )
    UFG::RenderStageShadow::RenderCloudShadowsIntoCollector(
      v6,
      v5,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 232));
  if ( v6->mRenderingNISCharacterShadows )
    UFG::RenderStageShadow::RenderCharacterShadows(
      v6,
      v5,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 216),
      composite_cull_layer);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v80);
  return (UFG::ShadowRenderQueueSimResults *)v11;
}

// File Line: 1478
// RVA: 0x38760
void __fastcall UFG::RenderStageShadow::GetLinearCascadeViews(
        UFG::RenderStageShadow *this,
        UFG::RenderStageShadow::LinearCascadeViews *views)
{
  __int64 v2; // r10
  unsigned __int64 v3; // rax
  Render::ViewSettings *v4; // r9
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  __int64 v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1

  v2 = 0i64;
  do
  {
    v3 = (unsigned __int64)(unsigned int)v2 << 6;
    v4 = &this->mShadowViewSettings[(int)v2];
    v5 = v4->mWorldView.v1;
    v6 = v4->mWorldView.v2;
    v7 = v4->mWorldView.v3;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v0 + v3) = v4->mWorldView.v0;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v1 + v3) = v5;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v2 + v3) = v6;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v3 + v3) = v7;
    v8 = v2 + 4;
    v2 = (unsigned int)(v2 + 1);
    v8 <<= 6;
    v9 = v4->mProjection.v1;
    v10 = v4->mProjection.v2;
    v11 = v4->mProjection.v3;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v0 + v8) = v4->mProjection.v0;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v1 + v8) = v9;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v2 + v8) = v10;
    *(UFG::qVector4 *)((char *)&views->mWorldView[0].v3 + v8) = v11;
  }
  while ( (unsigned int)v2 < 4 );
}

// File Line: 1491
// RVA: 0x3CE90
bool __fastcall UFG::RenderStageShadow::StateModifier_CharacterShadowCollector(
        Illusion::StateValues *state_values,
        _QWORD *override_params_Remote)
{
  UFG::qResourceData *mData; // r8
  UFG::qResourceData *v4; // r8
  void *v5; // r8
  void *v6; // rcx
  UFG::qResourceData *v7; // rcx
  void *v8; // rcx
  void *v9; // rax
  UFG::qResourceData *v10; // rcx
  void *v11; // rax
  bool result; // al
  UFG::qResourceData *v13; // rcx

  mData = UFG::RenderWorld::msStageShadow->mRasterStateCharacterShadowCollectorHandle.mData;
  state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
  state_values->mParamValues[10] = mData;
  v4 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorAlphaStateHandle.mData;
  state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
  state_values->mParamValues[9] = v4;
  v5 = *(void **)(override_params_Remote[22] + 24i64);
  state_values->mSetValueMask.mFlags[0] |= 0x800000ui64;
  state_values->mParamValues[23] = v5;
  v6 = *(void **)(override_params_Remote[1] + 72i64);
  state_values->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
  state_values->mParamValues[47] = v6;
  v7 = UFG::RenderWorld::msStageShadow->mNoiseTextureHandle.mData;
  state_values->mSetValueMask.mFlags[0] |= 0x40000000000ui64;
  state_values->mParamValues[42] = v7;
  v8 = *(void **)(override_params_Remote[19] + 24i64);
  state_values->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
  state_values->mParamValues[49] = v8;
  v9 = (void *)override_params_Remote[73];
  state_values->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  state_values->mParamValues[61] = v9;
  if ( *((_DWORD *)override_params_Remote + 83) == 2
    && *((_DWORD *)override_params_Remote + 84) == 1
    && *((int *)override_params_Remote + 89) >= 2 )
  {
    v10 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorHighShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    state_values->mParamValues[1] = v10;
    v11 = (void *)override_params_Remote[74];
    state_values->mSetValueMask.mFlags[0] |= 0x4000000000000000ui64;
    state_values->mParamValues[62] = v11;
    return 1;
  }
  else
  {
    v13 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorShaderHandle.mData;
    state_values->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    state_values->mParamValues[1] = v13;
  }
  return result;
}

// File Line: 1531
// RVA: 0x387F0
Illusion::RenderQueue *__fastcall UFG::CharacterCollectorSubmitContext::OnPreSubmit(
        UFG::CharacterCollectorSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  if ( !UFG::RenderStageShadow::StateModifier_CharacterShadowCollector(&this->mStateValues, this->mRenderContext) )
    return 0i64;
  Illusion::SubmitContext::LoadShader(this, shader_stream);
  return LayerSubmitContext::OnPreSubmit(this, shader_stream, already_called_funcs_mask);
}

// File Line: 1546
// RVA: 0x3A720
void __fastcall UFG::RenderStageShadow::RenderCharacterShadowsIntoCollector(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::CompositeDrawableComponent *component,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // rdi
  unsigned __int16 Param; // ax
  unsigned __int16 v13; // ax
  Illusion::StateArgs *StateArgs; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbShadowTransformState v25; // [rsp+90h] [rbp-70h] BYREF
  __int64 v26; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h] BYREF
  RenderQueueLayer v28; // [rsp+290h] [rbp+190h] BYREF
  LayerSubmitContext ptr; // [rsp+370h] [rbp+270h] BYREF
  UFG::RenderContext *v30; // [rsp+FF0h] [rbp+EF0h]
  Render::Poly v31; // [rsp+1030h] [rbp+F30h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+1038h] [rbp+F38h]

  v26 = -2i64;
  RenderQueueLayer::RenderQueueLayer(&v28);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::CharacterCollectorSubmitContext::`vftable;
  v30 = render_context;
  v28.mSerializationList = serialization_list;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v28;
  Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
  Render::View::BeginTarget(&view, render_context->mDynamicRangeTarget, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&view);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  mSettings = view.mSettings;
  p_mProjection = &view.mSettings->mProjection;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldView = &mSettings->mWorldView;
  arg.mProjection = p_mProjection;
  arg.mCached_Remote.m_Stream = 0i64;
  v25.mPrev = &v25;
  v25.mNext = &v25;
  v25.mCallback = 0i64;
  v25.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v25.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v13;
    v25.mStateParamIndex = v13;
  }
  v25.mViewWorld = &view.mViewWorld;
  v25.mWorldView = &this->mCSWorldShadow;
  v25.mProjection = &this->mCSShadowProj;
  memset(&v25.mCutplanes, 0, 32);
  StateArgs = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v25);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v31);
  UFG::CompositeDrawableComponent::Draw(component, &view);
  mPrev = v25.mPrev;
  mNext = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  mNext->mPrev = mPrev;
  v25.mPrev = &v25;
  v25.mNext = &v25;
  v25.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v25.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v25.mStateParamIndex] )
  {
    v17 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v25.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v25.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v20 = v25.mPrev;
  v21 = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  v21->mPrev = v20;
  v25.mPrev = &v25;
  v25.mNext = &v25;
  v22 = arg.mPrev;
  v23 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v23->mPrev = v22;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v28);
}

// File Line: 1643
// RVA: 0x390A0
void __fastcall UFG::RenderStageShadow::RenderCharacterShadows(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        CullLayer *composite_cull_layer)
{
  Illusion::Material *mMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  int v13; // eax
  float v14; // xmm7_4
  UFG::TimeOfDayManager *Instance; // rax
  float y; // xmm8_4
  float z; // xmm12_4
  float v18; // xmm9_4
  float v19; // xmm10_4
  float v20; // xmm11_4
  float v21; // xmm0_4
  int v22; // xmm9_4
  int v23; // xmm10_4
  int v24; // xmm11_4
  __int64 mCullIndex; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v26; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v27; // r15
  unsigned int v28; // r12d
  UFG::CompositeDrawableComponent *mNext; // r14
  __int64 v30; // rax
  float v31; // xmm6_4
  int LOD; // eax
  unsigned int v33; // edx
  int BoneID; // eax
  float v35; // xmm3_4
  float v36; // xmm12_4
  float v37; // xmm13_4
  float v38; // xmm8_4
  float mShadowNear; // xmm6_4
  float v40; // xmm7_4
  CullInfo *mCullInfo; // rbx
  UFG::qMatrix44 *mpLocalWorld; // r8
  float v43; // xmm6_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  int *v46; // rax
  int v47; // xmm1_4
  int v48; // xmm2_4
  UFG::qMatrix44 *v49; // r8
  float v50; // xmm2_4
  float v51; // xmm1_4
  int *v52; // rax
  int v53; // xmm1_4
  int v54; // xmm2_4
  UFG::qMatrix44 *v55; // r8
  float v56; // xmm2_4
  float v57; // xmm1_4
  int *v58; // rax
  int v59; // xmm1_4
  int v60; // xmm2_4
  UFG::qMatrix44 *v61; // r8
  float v62; // xmm2_4
  float v63; // xmm1_4
  int *v64; // rax
  int v65; // xmm1_4
  int v66; // xmm2_4
  UFG::qMatrix44 *v67; // r8
  float v68; // xmm2_4
  float v69; // xmm1_4
  int *v70; // rax
  int v71; // xmm1_4
  int v72; // xmm2_4
  UFG::qMatrix44 *v73; // r8
  float v74; // xmm2_4
  float v75; // xmm1_4
  int *v76; // rax
  int v77; // xmm1_4
  int v78; // xmm2_4
  UFG::qMatrix44 *v79; // r8
  float v80; // xmm2_4
  float v81; // xmm1_4
  int *v82; // rax
  int v83; // xmm1_4
  int v84; // xmm2_4
  UFG::qMatrix44 *v85; // r8
  float v86; // xmm2_4
  float v87; // xmm1_4
  int *v88; // rax
  int v89; // xmm1_4
  int v90; // xmm2_4
  int *v91; // r8
  __int64 v92; // r9
  float v93; // xmm7_4
  __int64 v94; // rcx
  __int64 v95; // rax
  float v96; // xmm4_4
  float v97; // xmm5_4
  float v98; // xmm6_4
  float v99; // xmm3_4
  float v100; // xmm2_4
  int v101; // xmm4_4
  int v102; // xmm5_4
  float v103; // xmm4_4
  float v104; // xmm5_4
  float v105; // xmm6_4
  float v106; // xmm0_4
  int v107; // xmm2_4
  int v108; // xmm1_4
  float v109; // xmm10_4
  float v110; // xmm9_4
  float v111; // xmm8_4
  float v112; // xmm7_4
  float *v113; // rax
  __int64 v114; // rcx
  float v115; // xmm6_4
  float v116; // xmm5_4
  float v117; // xmm6_4
  float v118; // xmm5_4
  float v119; // xmm6_4
  float v120; // xmm5_4
  float v121; // xmm5_4
  float v122; // xmm4_4
  float v123; // xmm0_4
  float v124; // xmm1_4
  UFG::qVector4 v125; // xmm3
  __m128 v126; // xmm4
  __m128 v127; // xmm5
  __m128 v128; // xmm4
  float v129; // xmm1_4
  int v130; // ecx
  float v131; // xmm2_4
  int v132; // ecx
  Illusion::StateArgs *StateArgs; // rdi
  UFG::qMatrix44 *p_mProjection; // rbx
  unsigned __int16 Param; // ax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v138; // rbx
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v141; // rax
  UFG::qVector4 v142; // xmm1
  UFG::qVector4 v143; // xmm2
  UFG::qVector4 v144; // xmm3
  UFG::qVector4 v145; // xmm1
  UFG::qVector4 v146; // xmm2
  UFG::qVector4 v147; // xmm3
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v148; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v149; // rax
  float v150; // [rsp+50h] [rbp-B0h]
  float v151; // [rsp+50h] [rbp-B0h]
  int v152; // [rsp+54h] [rbp-ACh]
  int v153; // [rsp+5Ch] [rbp-A4h]
  int v154; // [rsp+60h] [rbp-A0h]
  int v155; // [rsp+64h] [rbp-9Ch]
  int v156[22]; // [rsp+68h] [rbp-98h] BYREF
  int v157; // [rsp+C0h] [rbp-40h]
  int v158; // [rsp+C4h] [rbp-3Ch]
  float near_plane; // [rsp+C8h] [rbp-38h]
  float v160; // [rsp+CCh] [rbp-34h]
  int v161; // [rsp+D0h] [rbp-30h]
  float v162; // [rsp+D4h] [rbp-2Ch]
  float v163; // [rsp+D8h] [rbp-28h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qVector3 up; // [rsp+120h] [rbp+20h] BYREF
  UFG::qVector3 target; // [rsp+130h] [rbp+30h] BYREF
  Render::cbViewTransformState arg; // [rsp+140h] [rbp+40h] BYREF
  UFG::qVector3 eye; // [rsp+190h] [rbp+90h] BYREF
  UFG::qVector3 v169; // [rsp+19Ch] [rbp+9Ch] BYREF
  UFG::qVector4 v170; // [rsp+1A8h] [rbp+A8h] BYREF
  UFG::qVector4 v171; // [rsp+1B8h] [rbp+B8h] BYREF
  UFG::qVector4 v172; // [rsp+1C8h] [rbp+C8h] BYREF
  UFG::qVector4 v173; // [rsp+1D8h] [rbp+D8h] BYREF
  UFG::qMatrix44 dest; // [rsp+1F0h] [rbp+F0h] BYREF
  UFG::qVector4 v175; // [rsp+230h] [rbp+130h] BYREF
  UFG::qVector4 row_vec4; // [rsp+240h] [rbp+140h] BYREF
  UFG::qVector4 v177; // [rsp+250h] [rbp+150h] BYREF
  UFG::qVector4 v178; // [rsp+260h] [rbp+160h] BYREF
  int v179; // [rsp+270h] [rbp+170h]
  int v180[7]; // [rsp+274h] [rbp+174h] BYREF
  UFG::qMatrix44 v181; // [rsp+290h] [rbp+190h] BYREF
  UFG::qVector4 dir; // [rsp+2D0h] [rbp+1D0h] BYREF
  UFG::qMatrix44 b; // [rsp+2E0h] [rbp+1E0h] BYREF
  __int64 v184[4]; // [rsp+320h] [rbp+220h] BYREF
  Render::ViewSettings settings; // [rsp+340h] [rbp+240h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+3D0h] [rbp+2D0h] BYREF
  UFG::qVector4 v187; // [rsp+410h] [rbp+310h] BYREF
  UFG::qVector4 v188; // [rsp+420h] [rbp+320h] BYREF
  UFG::qVector4 v189; // [rsp+430h] [rbp+330h] BYREF
  UFG::qVector4 v190; // [rsp+440h] [rbp+340h] BYREF
  UFG::qVector4 v191; // [rsp+450h] [rbp+350h] BYREF
  UFG::qVector4 v192; // [rsp+460h] [rbp+360h] BYREF
  UFG::qVector4 v193; // [rsp+470h] [rbp+370h] BYREF
  UFG::qMatrix44 d; // [rsp+480h] [rbp+380h] BYREF
  UFG::qVector4 v195; // [rsp+4C0h] [rbp+3C0h] BYREF
  Render::View view; // [rsp+4D0h] [rbp+3D0h] BYREF
  RenderQueueLayer v197; // [rsp+660h] [rbp+560h] BYREF
  ShadowFrontFaceSubmitContext ptr; // [rsp+740h] [rbp+640h] BYREF
  LayerSubmitContext v199; // [rsp+13D0h] [rbp+12D0h] BYREF
  float x; // [rsp+2140h] [rbp+2040h]
  float v201; // [rsp+2148h] [rbp+2048h]
  float v203; // [rsp+2158h] [rbp+2058h]

  v184[2] = -2i64;
  RenderQueueLayer::RenderQueueLayer(&v197);
  LayerSubmitContext::LayerSubmitContext(&v199);
  v197.mSerializationList = serialization_list;
  v199.mRenderQueueProvider = &v197;
  v199.mQueueMode = QM_Single;
  Render::gRenderUtilities.mSubmitContext = &v199;
  mMaterial = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v10 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
    mMaterial = Render::gRenderUtilities.mMaterial;
  }
  if ( *(_DWORD *)&mMaterial[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[2].mDebugName[4],
      *((_DWORD *)&mMaterial[2].UFG::qResourceData + 22),
      0x62F81854u);
    v11 = mMaterial->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&mMaterial->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  Render::RenderUtilities::Blit(
    &Render::gRenderUtilities,
    render_context->mFullSizeScratchTargetA,
    render_context->mDynamicRangeTarget,
    0x3141335Cu,
    "BlitForCharacterNISShadows",
    0,
    1,
    0i64);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  v13 = 4;
  v152 = 4;
  if ( render_context->mRenderSettingsForFrame.mShadowFilter == SHADOW_FILTER_HIGH )
  {
    if ( render_context->mRenderSettingsForFrame.mShadowRes == SHADOW_RES_HIGH )
      v13 = 16;
    v152 = v13;
  }
  v153 = 0;
  *(_QWORD *)&up.x = 0i64;
  v14 = *(float *)&FLOAT_1_0;
  up.z = 1.0;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(Instance, &dir, 1, 0);
  ShadowFrontFaceSubmitContext::ShadowFrontFaceSubmitContext(&ptr);
  v184[1] = (__int64)this->mAlphaStateNoColourWriteHandle.mData;
  v184[0] = (__int64)this->mRasterStateNormalHandle.mData;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v197;
  ptr.mPerPhaseParams = (ShadowFrontFaceSubmitContext::PerPhaseParams *)v184;
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  x = d.v3.x;
  y = d.v3.y;
  v201 = d.v3.y;
  z = d.v3.z;
  v203 = d.v3.z;
  UFG::qMatrix44::operator*(
    &render_context->mMainViewSettings.mWorldView,
    &result,
    &render_context->mMainViewSettings.mProjection);
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  v21 = fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20));
  *(float *)&v22 = v18 * (float)(1.0 / v21);
  v157 = v22;
  *(float *)&v23 = v19 * (float)(1.0 / v21);
  v158 = v23;
  *(float *)&v24 = v20 * (float)(1.0 / v21);
  v161 = v24;
  v162 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v21);
  if ( composite_cull_layer )
  {
    mCullIndex = render_context->mMainViewSettings.mCullIndex;
    v26 = (int)mCullIndex >= 0 && (int)mCullIndex <= 16 && composite_cull_layer->mDrawEnabled
        ? composite_cull_layer->mCullResultBuckets[mCullIndex].mHead
        : 0i64;
    v27 = v26;
    v28 = 0;
    while ( v27 )
    {
      mNext = (UFG::CompositeDrawableComponent *)v27[v28 + 3].mNext;
      v30 = render_context->mMainViewSettings.mCullIndex;
      if ( (int)v30 >= 6 )
        v31 = v14;
      else
        v31 = mNext->mCullResults->mPixelCoverage[v30];
      LOD = UFG::CompositeDrawableComponent::GetLOD((UFG::CompositeDrawableComponent *)v27[v28 + 3].mNext, v31);
      if ( mNext->mPose->mRigHandle.mData && !LOD && v31 > 8.0 )
      {
        if ( (_S2_0 & 1) != 0 )
        {
          v33 = s_uSpineJoinNameUID;
        }
        else
        {
          _S2_0 |= 1u;
          v33 = UFG::qStringHashUpper32("Bip01 Spine", 0xFFFFFFFF);
          s_uSpineJoinNameUID = v33;
        }
        BoneID = Skeleton::GetBoneID(mNext->mPose->mRigHandle.mUFGSkeleton, v33);
        if ( BoneID >= 0 )
        {
          SkeletalPose::GetPositionWS(mNext->mPose, BoneID, &matrixWS);
          v35 = (float)(sThreshold / (float)(v14 / render_context->mMainViewSettings.mProjection.v0.x))
              * (float)(sThreshold / (float)(v14 / render_context->mMainViewSettings.mProjection.v0.x));
          v150 = matrixWS.v3.z;
          v160 = matrixWS.v3.y;
          if ( (float)((float)((float)((float)(matrixWS.v3.y - y) * (float)(matrixWS.v3.y - y))
                             + (float)((float)(matrixWS.v3.x - x) * (float)(matrixWS.v3.x - x)))
                     + (float)((float)(matrixWS.v3.z - z) * (float)(matrixWS.v3.z - z))) <= v35 )
          {
            if ( v153 >= v152 )
              break;
            ++v153;
            v36 = (float)(dir.z * 25.0) + v203;
            v37 = (float)(dir.y * 25.0) + v201;
            v38 = (float)(dir.x * 25.0) + x;
            mShadowNear = this->mShadowNear;
            near_plane = mShadowNear;
            v40 = (float)((float)(v14 - COERCE_FLOAT(LODWORD(dir.z) & _xmm)) * sfSunAngleFit) + 0.64999998;
            v163 = v40;
            target.x = matrixWS.v3.x;
            target.y = matrixWS.v3.y;
            target.z = matrixWS.v3.z;
            if ( this->mTightenCharacterShadows )
            {
              mCullInfo = mNext->mCullInfo;
              mpLocalWorld = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                mpLocalWorld = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v43 = inflate_0;
              v44 = mCullInfo->mAABBMin[2] - inflate_0;
              v45 = mCullInfo->mAABBMin[1] - inflate_0;
              row_vec4.x = mCullInfo->mAABBMin[0] - inflate_0;
              row_vec4.y = v45;
              row_vec4.z = v44;
              row_vec4.w = 1.0;
              v46 = (int *)UFG::operator*(&v188, &row_vec4, mpLocalWorld);
              v47 = v46[1];
              v48 = v46[2];
              v154 = *v46;
              v155 = v47;
              v156[0] = v48;
              v49 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v49 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v50 = mCullInfo->mAABBMin[2] - v43;
              v51 = mCullInfo->mAABBMin[1] - v43;
              v178.x = v43 + mCullInfo->mAABBMax[0];
              v178.y = v51;
              v178.z = v50;
              v178.w = 1.0;
              v52 = (int *)UFG::operator*(&v189, &v178, v49);
              v53 = v52[1];
              v54 = v52[2];
              v156[1] = *v52;
              v156[2] = v53;
              v156[3] = v54;
              v55 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v55 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v56 = mCullInfo->mAABBMin[2] - v43;
              v57 = v43 + mCullInfo->mAABBMax[1];
              v173.x = v43 + mCullInfo->mAABBMax[0];
              v173.y = v57;
              v173.z = v56;
              v173.w = 1.0;
              v58 = (int *)UFG::operator*(&v191, &v173, v55);
              v59 = v58[1];
              v60 = v58[2];
              v156[4] = *v58;
              v156[5] = v59;
              v156[6] = v60;
              v61 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v61 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v62 = mCullInfo->mAABBMin[2] - v43;
              v63 = v43 + mCullInfo->mAABBMax[1];
              v171.x = mCullInfo->mAABBMin[0] - v43;
              v171.y = v63;
              v171.z = v62;
              v171.w = 1.0;
              v64 = (int *)UFG::operator*(&v195, &v171, v61);
              v65 = v64[1];
              v66 = v64[2];
              v156[7] = *v64;
              v156[8] = v65;
              v156[9] = v66;
              v67 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v67 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v68 = v43 + mCullInfo->mAABBMax[2];
              v69 = mCullInfo->mAABBMin[1] - v43;
              v172.x = mCullInfo->mAABBMin[0] - v43;
              v172.y = v69;
              v172.z = v68;
              v172.w = 1.0;
              v70 = (int *)UFG::operator*(&v190, &v172, v67);
              v71 = v70[1];
              v72 = v70[2];
              v156[10] = *v70;
              v156[11] = v71;
              v156[12] = v72;
              v73 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v73 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v74 = v43 + mCullInfo->mAABBMax[2];
              v75 = mCullInfo->mAABBMin[1] - v43;
              v177.x = v43 + mCullInfo->mAABBMax[0];
              v177.y = v75;
              v177.z = v74;
              v177.w = 1.0;
              v76 = (int *)UFG::operator*(&v193, &v177, v73);
              v77 = v76[1];
              v78 = v76[2];
              v156[13] = *v76;
              v156[14] = v77;
              v156[15] = v78;
              v79 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v79 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v80 = v43 + mCullInfo->mAABBMax[2];
              v81 = v43 + mCullInfo->mAABBMax[1];
              v175.x = v43 + mCullInfo->mAABBMax[0];
              v175.y = v81;
              v175.z = v80;
              v175.w = 1.0;
              v82 = (int *)UFG::operator*(&v192, &v175, v79);
              v83 = v82[1];
              v84 = v82[2];
              v156[16] = *v82;
              v156[17] = v83;
              v156[18] = v84;
              v85 = &UFG::qMatrix44::msIdentity;
              if ( mCullInfo->mpLocalWorld )
                v85 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
              v86 = v43 + mCullInfo->mAABBMax[2];
              v87 = v43 + mCullInfo->mAABBMax[1];
              v170.x = mCullInfo->mAABBMin[0] - v43;
              v170.y = v87;
              v170.z = v86;
              v170.w = 1.0;
              v88 = (int *)UFG::operator*(&v187, &v170, v85);
              v89 = v88[1];
              v90 = v88[2];
              v156[19] = *v88;
              v156[20] = v89;
              v156[21] = v90;
              v179 = 0;
              v180[0] = 4;
              v180[1] = 1;
              v180[2] = 5;
              v180[3] = 2;
              v180[4] = 6;
              v180[5] = 3;
              v180[6] = 7;
              v91 = v180;
              v92 = 4i64;
              v93 = v162;
              do
              {
                v94 = 3i64 * (unsigned int)*(v91 - 1);
                v95 = (unsigned int)*v91;
                v96 = *(float *)&v156[3 * v95] - *(float *)&v156[3 * *(v91 - 1)];
                v97 = *(float *)&v156[3 * v95 - 1] - *(float *)&v156[3 * *(v91 - 1) - 1];
                v98 = *((float *)&v154 + 3 * v95) - *((float *)&v154 + 3 * (unsigned int)*(v91 - 1));
                v99 = (float)((float)(v97 * *(float *)&v23) + (float)(*(float *)&v22 * v98))
                    + (float)(v96 * *(float *)&v24);
                if ( v99 <= 0.0 )
                {
                  v103 = *(float *)&v156[3 * v95] - *(float *)&v156[3 * *(v91 - 1)];
                  v104 = *(float *)&v156[3 * v95 - 1] - *(float *)&v156[3 * *(v91 - 1) - 1];
                  v105 = *((float *)&v154 + 3 * v95) - *((float *)&v154 + 3 * (unsigned int)*(v91 - 1));
                  if ( (float)((float)((float)(v104 * *(float *)&v23) + (float)(*(float *)&v22 * v105))
                             + (float)(v103 * *(float *)&v24)) != 0.0 )
                  {
                    v106 = (float)(-1.0
                                 / (float)((float)((float)(COERCE_FLOAT(LODWORD(v104) ^ _xmm[0]) * *(float *)&v23)
                                                 + (float)(COERCE_FLOAT(LODWORD(v105) ^ _xmm[0]) * *(float *)&v22))
                                         + (float)(COERCE_FLOAT(LODWORD(v103) ^ _xmm[0]) * *(float *)&v24)))
                         * (float)((float)((float)((float)(*(float *)&v23 * *(float *)&v156[3 * v95 - 1])
                                                 + (float)(*(float *)&v22 * *((float *)&v154 + 3 * v95)))
                                         + (float)(*(float *)&v24 * *(float *)&v156[3 * v95]))
                                 + v93);
                    if ( v106 > 0.0 && v106 < 1.0 )
                    {
                      *(float *)&v107 = *(float *)&v156[3 * v95] - (float)(v103 * v106);
                      *(float *)&v108 = *(float *)&v156[3 * v95 - 1] - (float)(v104 * v106);
                      *((float *)&v154 + 3 * (unsigned int)*(v91 - 1)) = *((float *)&v154 + 3 * v95)
                                                                       - (float)(v105 * v106);
                      v156[v94 - 1] = v108;
                      v156[v94] = v107;
                    }
                  }
                }
                else
                {
                  v100 = (float)((float)((float)((float)(*(float *)&v23 * *(float *)&v156[3 * *(v91 - 1) - 1])
                                               + (float)(*(float *)&v22
                                                       * *((float *)&v154 + 3 * (unsigned int)*(v91 - 1))))
                                       + (float)(*(float *)&v24 * *(float *)&v156[3 * *(v91 - 1)]))
                               + v93)
                       * (float)(-1.0 / v99);
                  if ( v100 > 0.0 && v100 < 1.0 )
                  {
                    *(float *)&v101 = (float)(v96 * v100) + *(float *)&v156[3 * *(v91 - 1)];
                    *(float *)&v102 = (float)(v97 * v100) + *(float *)&v156[3 * *(v91 - 1) - 1];
                    *((float *)&v154 + 3 * v95) = (float)(v98 * v100) + *((float *)&v154 + 3 * (unsigned int)*(v91 - 1));
                    v156[3 * v95 - 1] = v102;
                    v156[3 * v95] = v101;
                  }
                }
                v91 += 2;
                --v92;
              }
              while ( v92 );
              eye.x = (float)(v38 - x) + matrixWS.v3.x;
              eye.y = (float)(v37 - v201) + v160;
              eye.z = (float)(v36 - v203) + v150;
              UFG::qLookAtMatrix(&result, &eye, &target, &up);
              UFG::qOrthographicMatrix(&dest, v163 * 6.0, v163 * 6.0, near_plane, 50.0);
              UFG::qMatrix44::operator*(&result, &v181, &dest);
              v109 = FLOAT_10000_0;
              v110 = FLOAT_10000_0;
              v111 = FLOAT_N10000_0;
              v112 = FLOAT_N10000_0;
              v113 = (float *)v156;
              v114 = 2i64;
              do
              {
                v115 = (float)((float)((float)(v181.v1.x * *(v113 - 1)) + (float)(v181.v0.x * *(v113 - 2)))
                             + (float)(v181.v2.x * *v113))
                     + v181.v3.x;
                v116 = (float)((float)((float)(v181.v1.y * *(v113 - 1)) + (float)(v181.v0.y * *(v113 - 2)))
                             + (float)(v181.v2.y * *v113))
                     + v181.v3.y;
                if ( v109 >= v115 )
                  v109 = (float)((float)((float)(v181.v1.x * *(v113 - 1)) + (float)(v181.v0.x * *(v113 - 2)))
                               + (float)(v181.v2.x * *v113))
                       + v181.v3.x;
                if ( v110 >= v116 )
                  v110 = (float)((float)((float)(v181.v1.y * *(v113 - 1)) + (float)(v181.v0.y * *(v113 - 2)))
                               + (float)(v181.v2.y * *v113))
                       + v181.v3.y;
                if ( v111 <= v115 )
                  v111 = (float)((float)((float)(v181.v1.x * *(v113 - 1)) + (float)(v181.v0.x * *(v113 - 2)))
                               + (float)(v181.v2.x * *v113))
                       + v181.v3.x;
                if ( v112 <= v116 )
                  v112 = (float)((float)((float)(v181.v1.y * *(v113 - 1)) + (float)(v181.v0.y * *(v113 - 2)))
                               + (float)(v181.v2.y * *v113))
                       + v181.v3.y;
                v117 = (float)((float)((float)(v181.v1.x * v113[2]) + (float)(v181.v0.x * v113[1]))
                             + (float)(v181.v2.x * v113[3]))
                     + v181.v3.x;
                v118 = (float)((float)((float)(v181.v1.y * v113[2]) + (float)(v181.v0.y * v113[1]))
                             + (float)(v181.v2.y * v113[3]))
                     + v181.v3.y;
                if ( v109 >= v117 )
                  v109 = (float)((float)((float)(v181.v1.x * v113[2]) + (float)(v181.v0.x * v113[1]))
                               + (float)(v181.v2.x * v113[3]))
                       + v181.v3.x;
                if ( v110 >= v118 )
                  v110 = (float)((float)((float)(v181.v1.y * v113[2]) + (float)(v181.v0.y * v113[1]))
                               + (float)(v181.v2.y * v113[3]))
                       + v181.v3.y;
                if ( v111 <= v117 )
                  v111 = (float)((float)((float)(v181.v1.x * v113[2]) + (float)(v181.v0.x * v113[1]))
                               + (float)(v181.v2.x * v113[3]))
                       + v181.v3.x;
                if ( v112 <= v118 )
                  v112 = (float)((float)((float)(v181.v1.y * v113[2]) + (float)(v181.v0.y * v113[1]))
                               + (float)(v181.v2.y * v113[3]))
                       + v181.v3.y;
                v119 = (float)((float)((float)(v181.v1.x * v113[5]) + (float)(v181.v0.x * v113[4]))
                             + (float)(v181.v2.x * v113[6]))
                     + v181.v3.x;
                v120 = (float)((float)((float)(v181.v1.y * v113[5]) + (float)(v181.v0.y * v113[4]))
                             + (float)(v181.v2.y * v113[6]))
                     + v181.v3.y;
                if ( v109 >= v119 )
                  v109 = (float)((float)((float)(v181.v1.x * v113[5]) + (float)(v181.v0.x * v113[4]))
                               + (float)(v181.v2.x * v113[6]))
                       + v181.v3.x;
                if ( v110 >= v120 )
                  v110 = (float)((float)((float)(v181.v1.y * v113[5]) + (float)(v181.v0.y * v113[4]))
                               + (float)(v181.v2.y * v113[6]))
                       + v181.v3.y;
                if ( v111 <= v119 )
                  v111 = (float)((float)((float)(v181.v1.x * v113[5]) + (float)(v181.v0.x * v113[4]))
                               + (float)(v181.v2.x * v113[6]))
                       + v181.v3.x;
                if ( v112 <= v120 )
                  v112 = (float)((float)((float)(v181.v1.y * v113[5]) + (float)(v181.v0.y * v113[4]))
                               + (float)(v181.v2.y * v113[6]))
                       + v181.v3.y;
                v121 = (float)((float)((float)(v113[7] * v181.v0.x) + (float)(v113[8] * v181.v1.x))
                             + (float)(v181.v2.x * v113[9]))
                     + v181.v3.x;
                v122 = (float)((float)((float)(v113[7] * v181.v0.y) + (float)(v113[8] * v181.v1.y))
                             + (float)(v181.v2.y * v113[9]))
                     + v181.v3.y;
                if ( v109 >= v121 )
                  v109 = (float)((float)((float)(v113[7] * v181.v0.x) + (float)(v113[8] * v181.v1.x))
                               + (float)(v181.v2.x * v113[9]))
                       + v181.v3.x;
                if ( v110 >= v122 )
                  v110 = (float)((float)((float)(v113[7] * v181.v0.y) + (float)(v113[8] * v181.v1.y))
                               + (float)(v181.v2.y * v113[9]))
                       + v181.v3.y;
                if ( v111 <= v121 )
                  v111 = (float)((float)((float)(v113[7] * v181.v0.x) + (float)(v113[8] * v181.v1.x))
                               + (float)(v181.v2.x * v113[9]))
                       + v181.v3.x;
                if ( v112 <= v122 )
                  v112 = (float)((float)((float)(v113[7] * v181.v0.y) + (float)(v113[8] * v181.v1.y))
                               + (float)(v181.v2.y * v113[9]))
                       + v181.v3.y;
                v113 += 12;
                --v114;
              }
              while ( v114 );
              v123 = (float)(v111 - v109) * 1.1;
              if ( v123 <= 0.000001 )
                v123 = FLOAT_0_000001;
              v124 = (float)(v112 - v110) * 1.1;
              if ( v124 <= 0.000001 )
                v124 = FLOAT_0_000001;
              v125 = 0i64;
              v125.x = (float)1;
              b.v0 = v125;
              b.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v125, (__m128)v125, 81);
              b.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v125, (__m128)v125, 69);
              *(_QWORD *)&b.v3.z = *(unsigned __int128 *)&_mm_shuffle_ps((__m128)v125, (__m128)v125, 21) >> 64;
              b.v0.x = 2.0 / v123;
              b.v1.y = 2.0 / v124;
              b.v3.x = (float)((float)(v111 + v109) * -0.5) * (float)(2.0 / v123);
              b.v3.y = (float)((float)(v112 + v110) * -0.5) * (float)(2.0 / v124);
              UFG::qMatrix44::operator*=(&dest, &b);
            }
            else
            {
              v169.x = (float)(v38 - x) + matrixWS.v3.x;
              v169.y = matrixWS.v3.y + (float)(v37 - v201);
              v169.z = matrixWS.v3.z + (float)(v36 - v203);
              UFG::qLookAtMatrix(&result, &v169, &target, &up);
              UFG::qOrthographicMatrix(&dest, v40 * 2.0, v40 * 2.0, mShadowNear, 50.0);
            }
            if ( (_S2_0 & 2) != 0 )
            {
              v151 = HALF_DIM;
            }
            else
            {
              _S2_0 |= 2u;
              v151 = (float)(int)render_context->mCharacterShadowSize * 0.5;
              HALF_DIM = v151;
            }
            v126 = _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 255), (__m128)dest.v3),
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           (__m128)0i64,
                           _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 0), (__m128)dest.v0)),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 85), (__m128)dest.v1)),
                       _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 170), (__m128)dest.v2)));
            b.v0 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 0),
                                            (__m128)dest.v0),
                                          (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 85),
                                          (__m128)dest.v1)),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 170),
                                        (__m128)dest.v2)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 255),
                                      (__m128)dest.v3));
            b.v1 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 0),
                                            (__m128)dest.v0),
                                          (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 85),
                                          (__m128)dest.v1)),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 170),
                                        (__m128)dest.v2)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 255),
                                      (__m128)dest.v3));
            b.v2 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 0),
                                            (__m128)dest.v0),
                                          (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 85),
                                          (__m128)dest.v1)),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 170),
                                        (__m128)dest.v2)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 255),
                                      (__m128)dest.v3));
            v127 = v126;
            v127.m128_f32[0] = v126.m128_f32[0] * v151;
            v128 = _mm_shuffle_ps(v126, v126, 85);
            v128.m128_f32[0] = v128.m128_f32[0] * v151;
            v129 = v127.m128_f32[0];
            v130 = (int)v127.m128_f32[0];
            if ( (int)v127.m128_f32[0] != 0x80000000 && (float)v130 != v127.m128_f32[0] )
              v129 = (float)(v130 - (_mm_movemask_ps(_mm_unpacklo_ps(v127, v127)) & 1));
            v131 = v128.m128_f32[0];
            v132 = (int)v128.m128_f32[0];
            if ( (int)v128.m128_f32[0] != 0x80000000 && (float)v132 != v128.m128_f32[0] )
              v131 = (float)(v132 - (_mm_movemask_ps(_mm_unpacklo_ps(v128, v128)) & 1));
            dest.v3.x = dest.v3.x + (float)((float)(v129 - v127.m128_f32[0]) * (float)(1.0 / v151));
            dest.v3.y = dest.v3.y + (float)((float)(v131 - v128.m128_f32[0]) * (float)(1.0 / v151));
            settings.mCullIndex = -1;
            *(_QWORD *)&settings.mCullPixelDensityThreshold = 0i64;
            settings.mWorldView = result;
            settings.mProjection = dest;
            Render::View::View(&view, &settings, &ptr);
            Render::View::BeginTarget(
              &view,
              render_context->mCharacterShadowTarget,
              "ShadowTarget_Character",
              0,
              0,
              0i64,
              1,
              0,
              0,
              0);
            Render::View::Clear(&view, &UFG::qColour::Black, 6u, 1.0, 0);
            StateArgs = Render::View::GetStateArgs(&view);
            p_mProjection = &view.mSettings->mProjection;
            arg.mPrev = &arg;
            arg.mNext = &arg;
            arg.mCallback = 0i64;
            arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
            *(_WORD *)&arg.mFlags = 1;
            if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
            {
              Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
              Render::cbViewTransformState::sStateParamIndex = Param;
              arg.mStateParamIndex = Param;
            }
            arg.mWorldViewProjection = &view.mWorldViewProjection;
            arg.mViewWorld = &view.mViewWorld;
            arg.mProjection = p_mProjection;
            arg.mScreenOffset = &Render::View::mScreenOffset;
            arg.mCached_Remote.m_Stream = 0i64;
            Illusion::StateArgs::Set<Render::cbViewTransformState>(StateArgs, &arg);
            mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
            mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
            v138 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
            *(float *)v138 = mSimTime_Temp;
            *((float *)v138 + 1) = mSimTimeDelta;
            StateValues = Render::View::GetStateValues(&view);
            StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
            StateValues->mParamValues[13] = v138;
            UFG::CompositeDrawableComponent::Draw(mNext, &view, 0);
            mPrev = arg.mPrev;
            v141 = arg.mNext;
            arg.mPrev->mNext = arg.mNext;
            v141->mPrev = mPrev;
            arg.mPrev = &arg;
            arg.mNext = &arg;
            arg.mIsSet = 0;
            if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
              StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
            Render::View::EndTarget(&view);
            v142 = result.v1;
            v143 = result.v2;
            v144 = result.v3;
            this->mCSWorldShadow.v0 = result.v0;
            this->mCSWorldShadow.v1 = v142;
            this->mCSWorldShadow.v2 = v143;
            this->mCSWorldShadow.v3 = v144;
            v145 = dest.v1;
            v146 = dest.v2;
            v147 = dest.v3;
            this->mCSShadowProj.v0 = dest.v0;
            this->mCSShadowProj.v1 = v145;
            this->mCSShadowProj.v2 = v146;
            this->mCSShadowProj.v3 = v147;
            UFG::RenderStageShadow::RenderCharacterShadowsIntoCollector(this, render_context, mNext, serialization_list);
            v148 = arg.mPrev;
            v149 = arg.mNext;
            arg.mPrev->mNext = arg.mNext;
            v149->mPrev = v148;
            arg.mPrev = &arg;
            arg.mNext = &arg;
            v22 = v157;
            v23 = v158;
            v24 = v161;
            v14 = *(float *)&FLOAT_1_0;
            y = v201;
            z = v203;
          }
        }
      }
      if ( ++v28 == LODWORD(v27[1].mNext) )
      {
        v27 = v27->mNext;
        v28 = 0;
      }
    }
  }
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  `eh vector destructor iterator(
    v199.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v197);
}

// File Line: 1900
// RVA: 0x38870
void __fastcall UFG::RenderStageShadow::RenderBeforeSunShadows(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  this->mRenderingNISCharacterShadows = 0;
}

// File Line: 1905
// RVA: 0x38860
void __fastcall UFG::RenderStageShadow::RenderAfterSunShadows(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qMatrix44 *serialization_list)
{
  if ( render_context->mRenderSun )
    UFG::RenderStageShadow::BlurCollector(this, render_context, serialization_list);
}

// File Line: 1922
// RVA: 0x37A50
void __fastcall UFG::RenderStageShadow::BlurCollector(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qMatrix44 *serialization_list)
{
  Illusion::Material *mShadowCollectorMaterial; // rdi
  __int64 mOffset; // rax
  _WORD *v7; // rax
  Illusion::Material *v8; // rdi
  __int64 v9; // rax
  _WORD *v10; // rax
  Render::ViewSettings *mSettings; // rdi
  UFG::qMatrix44 *p_mProjection; // rsi
  unsigned __int16 Param; // ax
  Illusion::StateArgs *StateArgs; // rdi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-98h] BYREF
  Render::View v21; // [rsp+158h] [rbp+70h] BYREF
  LayerSubmitContext ptr; // [rsp+2E8h] [rbp+200h] BYREF
  Render::Poly poly; // [rsp+F90h] [rbp+EA8h] BYREF

  arg.mWorldView = (UFG::qMatrix44 *)-2i64;
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    uidBILATERALBLUR = UFG::qStringHashUpper32("BILATERALBLUR", 0xFFFFFFFF);
  }
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  arg.mProjection = serialization_list;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mProjection;
  if ( render_context->mRenderSettingsForFrame.mShadowRes )
  {
    Render::gRenderUtilities.mSubmitContext = &ptr;
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      render_context->mDynamicRangeTarget,
      render_context->mFullSizeScratchTargetA,
      uidBILATERALBLUR,
      "BilateralBlur",
      0,
      0,
      0i64);
    Render::gRenderUtilities.mSubmitContext = 0i64;
  }
  else
  {
    Render::View::View(&v21, &render_context->mMainViewSettings, &ptr);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v21, render_context->mFullSizeScratchTargetA, "BlankCollector", 0, 0, 0i64, 0, 0, 0, 0);
    mShadowCollectorMaterial = render_context->mShadowCollectorMaterial;
    if ( LODWORD(mShadowCollectorMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 127664167 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mShadowCollectorMaterial[1].mNode.mChild[1],
        mShadowCollectorMaterial[1].mTypeUID,
        0x79C0027u);
      mOffset = mShadowCollectorMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v7 = (_WORD *)((char *)&mShadowCollectorMaterial->mMaterialUser + mOffset);
      else
        v7 = 0i64;
      *v7 |= 0x20u;
    }
    v8 = render_context->mShadowCollectorMaterial;
    if ( *(_DWORD *)&v8[2].mDebugName[28] != 1660426324 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v8[2].mDebugName[4],
        *((_DWORD *)&v8[2].UFG::qResourceData + 22),
        0x62F81854u);
      v9 = v8->mMaterialUser.mOffset;
      if ( v9 )
        v10 = (_WORD *)((char *)&v8->mMaterialUser + v9);
      else
        v10 = 0i64;
      *v10 |= 0x20u;
    }
    mSettings = v21.mSettings;
    p_mProjection = &v21.mSettings->mProjection;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mWorldView = &mSettings->mWorldView;
    arg.mProjection = p_mProjection;
    *(_QWORD *)&arg.mStateParamIndex = 0i64;
    StateArgs = Render::View::GetStateArgs(&v21);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    Render::View::Draw(&v21, &poly, render_context->mShadowCollectorMaterial, 0i64);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    {
      v17 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v17 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v21);
    v18 = arg.mPrev;
    v19 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v19->mPrev = v18;
    arg.mPrev = &arg;
    arg.mNext = &arg;
  }
  poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
}

// File Line: 1970
// RVA: 0x38880
void __fastcall UFG::RenderStageShadow::RenderCascadeDebug(
        UFG::RenderStageShadow *this,
        Render::View *view,
        UFG::RenderContext *render_context)
{
  _WORD *v4; // rsi
  Illusion::Material *mMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v8; // rax
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  __int64 i; // r14
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float x; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  __m128 v29; // xmm2
  UFG::qVector4 v30; // xmm0
  __m128 v31; // xmm2
  bool v32; // zf
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  __m128 v48; // xmm2
  float v49; // xmm3_4
  float v50; // xmm4_4
  UFG::qVector4 v51; // xmm0
  __m128 v52; // xmm2
  Illusion::Material *v53; // rbx
  __int64 v54; // rax
  _WORD *v55; // rax
  UFG::qColour *p_z; // rdx
  Illusion::Material *v57; // rbx
  __int64 v58; // rax
  _WORD *v59; // rax
  Illusion::Material *v60; // rbx
  __int64 v61; // rax
  _WORD *v62; // rax
  Illusion::Material *v63; // rbx
  __int64 v64; // rax
  _WORD *v65; // rax
  __int64 v66; // rax
  UFG::qMatrix44 d; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qMatrix44 v68; // [rsp+70h] [rbp-68h] BYREF
  __int64 v69; // [rsp+B0h] [rbp-28h]
  UFG::qColour colour; // [rsp+B8h] [rbp-20h] BYREF
  UFG::qColour v71; // [rsp+C8h] [rbp-10h] BYREF
  UFG::qColour v72; // [rsp+D8h] [rbp+0h] BYREF
  UFG::qColour v73; // [rsp+E8h] [rbp+10h] BYREF
  UFG::qMatrix44 m; // [rsp+F8h] [rbp+20h] BYREF
  UFG::qMatrix44 v75; // [rsp+138h] [rbp+60h] BYREF
  Render::Poly poly; // [rsp+1F0h] [rbp+118h] BYREF

  v4 = 0i64;
  Render::View::Clear(view, &UFG::qColour::Zero, 4u, 1.0, 0);
  mMaterial = Render::gRenderUtilities.mMaterial;
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 826356572 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      0x3141335Cu);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v8 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
    else
      v8 = 0i64;
    *v8 |= 0x20u;
    mMaterial = Render::gRenderUtilities.mMaterial;
  }
  if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
      mMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v9 = mMaterial->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&mMaterial->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
    mMaterial = Render::gRenderUtilities.mMaterial;
  }
  if ( mMaterial[2].mNode.mUID != -1551679522 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[2],
      (unsigned int)mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0xA3833FDE);
    v11 = mMaterial->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&mMaterial->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  for ( i = 2i64; i >= 0; --i )
  {
    y = this->mShadowViewSettings[i].mWorldView.v0.y;
    m.v0.x = this->mShadowViewSettings[i].mWorldView.v0.x;
    z = this->mShadowViewSettings[i].mWorldView.v0.z;
    m.v0.y = y;
    w = this->mShadowViewSettings[i].mWorldView.v0.w;
    m.v0.z = z;
    x = this->mShadowViewSettings[i].mWorldView.v1.x;
    m.v0.w = w;
    v18 = this->mShadowViewSettings[i].mWorldView.v1.y;
    m.v1.x = x;
    v19 = this->mShadowViewSettings[i].mWorldView.v1.z;
    m.v1.y = v18;
    v20 = this->mShadowViewSettings[i].mWorldView.v1.w;
    m.v1.z = v19;
    v21 = this->mShadowViewSettings[i].mWorldView.v2.x;
    m.v1.w = v20;
    v22 = this->mShadowViewSettings[i].mWorldView.v2.y;
    m.v2.x = v21;
    v23 = this->mShadowViewSettings[i].mWorldView.v2.z;
    m.v2.y = v22;
    v24 = this->mShadowViewSettings[i].mWorldView.v2.w;
    m.v2.z = v23;
    v25 = this->mShadowViewSettings[i].mWorldView.v3.x;
    m.v2.w = v24;
    v26 = this->mShadowViewSettings[i].mWorldView.v3.y;
    m.v3.x = v25;
    v27 = this->mShadowViewSettings[i].mWorldView.v3.z;
    m.v3.y = v26;
    v28 = this->mShadowViewSettings[i].mWorldView.v3.w;
    m.v3.z = v27;
    m.v3.w = v28;
    UFG::qInverseAffine(&d, &m);
    v29 = (__m128)(unsigned int)FLOAT_1_0;
    v29.m128_f32[0] = 1.0 / this->mShadowViewSettings[i].mProjection.v0.x;
    v30 = (UFG::qVector4)_mm_mul_ps((__m128)d.v0, _mm_shuffle_ps(v29, v29, 0));
    v31 = (__m128)(unsigned int)FLOAT_1_0;
    v31.m128_f32[0] = 1.0 / this->mShadowViewSettings[i].mProjection.v1.y;
    d.v0 = v30;
    d.v1 = (UFG::qVector4)_mm_mul_ps((__m128)d.v1, _mm_shuffle_ps(v31, v31, 0));
    v30.x = this->mShadowOffset * 0.5;
    d.v2.x = d.v2.x * v30.x;
    d.v2.y = d.v2.y * v30.x;
    d.v2.z = d.v2.z * v30.x;
    d.v2.w = d.v2.w * v30.x;
    d.v3.x = d.v3.x - (float)(d.v2.x * 2.0);
    d.v3.y = d.v3.y - (float)(d.v2.y * 2.0);
    d.v3.z = d.v3.z - (float)(d.v2.z * 2.0);
    d.v3.w = d.v3.w - (float)(d.v2.w * 2.0);
    v32 = i == 0;
    if ( i > 0 )
    {
      v33 = *(&this->mCloudShadowMinVolume + 36 * i);
      v75.v0.x = *(&this->mCloudShadowCullDist + 36 * i);
      v34 = *((float *)&this->mEnableCloudShadows + 36 * i);
      v75.v0.y = v33;
      v35 = *((float *)&this->mDrawDebugCascadeCoverage + 36 * i);
      v75.v0.z = v34;
      v36 = *((float *)&this->mMatDepthDownsampleShadow + 36 * i);
      v75.v0.w = v35;
      v37 = *((float *)&this->mMatDepthDownsampleShadow + 36 * i + 1);
      v75.v1.x = v36;
      v38 = *((float *)&this->mMatStencilWriteShadowNear + 36 * i);
      v75.v1.y = v37;
      v39 = *((float *)&this->mMatStencilWriteShadowNear + 36 * i + 1);
      v75.v1.z = v38;
      v40 = *((float *)&this->mMatStencilWriteShadowFar + 36 * i);
      v75.v1.w = v39;
      v41 = *((float *)&this->mMatStencilWriteShadowFar + 36 * i + 1);
      v75.v2.x = v40;
      v42 = this->mBoundingSphere[9 * i].x;
      v75.v2.y = v41;
      v43 = this->mBoundingSphere[9 * i].y;
      v75.v2.z = v42;
      v44 = this->mBoundingSphere[9 * i].z;
      v75.v2.w = v43;
      v45 = this->mBoundingSphere[9 * i].w;
      v75.v3.x = v44;
      v46 = this->mBoundingSphere[9 * i + 1].x;
      v75.v3.y = v45;
      v47 = this->mBoundingSphere[9 * i + 1].y;
      v75.v3.z = v46;
      v75.v3.w = v47;
      UFG::qInverseAffine(&v68, &v75);
      v48 = (__m128)(unsigned int)FLOAT_1_0;
      v32 = i == 0;
      v49 = v68.v0.x;
      v50 = v68.v0.y;
      v48.m128_f32[0] = 1.0 / this->mBoundingSphere[9 * i + 1].z;
      v51 = (UFG::qVector4)_mm_mul_ps((__m128)v68.v0, _mm_shuffle_ps(v48, v48, 0));
      v52 = (__m128)(unsigned int)FLOAT_1_0;
      v52.m128_f32[0] = 1.0 / this->mBoundingSphere[9 * i + 2].w;
      v68.v0 = v51;
      *(__m128 *)&d.v2.z = _mm_mul_ps(*(__m128 *)&d.v2.z, _mm_shuffle_ps(v52, v52, 0));
      v51.x = this->mShadowOffset * 0.5;
      d.v3.z = d.v3.z * v51.x;
      d.v3.w = d.v3.w * v51.x;
      v68.v0.x = v49 * v51.x;
      v68.v0.y = v50 * v51.x;
      v68.v0.z = v68.v0.z - (float)(d.v3.z * 2.0);
      v68.v0.w = v68.v0.w - (float)(d.v3.w * 2.0);
      v68.v1.x = v68.v1.x - (float)((float)(v49 * v51.x) * 2.0);
      v68.v1.y = v68.v1.y - (float)((float)(v50 * v51.x) * 2.0);
    }
    if ( v32 )
    {
      Render::View::Draw(view, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowNear);
      v53 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -978675340 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].UFG::qResourceData + 22),
          0xC5AA9974);
        v54 = v53->mMaterialUser.mOffset;
        if ( v54 )
          v55 = (_WORD *)((char *)&v53->mMaterialUser + v54);
        else
          v55 = 0i64;
        *v55 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      *(_QWORD *)&colour.r = 1056964608i64;
      colour.b = 0.0;
      colour.a = 0.5;
      Render::Poly::SetColour(&poly, &colour);
      Render::View::Draw(view, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v68.v3.z = 0i64;
      v69 = 0i64;
      p_z = (UFG::qColour *)&v68.v3.z;
    }
    else if ( i == 1 )
    {
      Render::View::Draw(view, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowFar);
      v57 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -860456360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].UFG::qResourceData + 22),
          0xCCB67A58);
        v58 = v57->mMaterialUser.mOffset;
        if ( v58 )
          v59 = (_WORD *)((char *)&v57->mMaterialUser + v58);
        else
          v59 = 0i64;
        *v59 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>((Render::Poly *)&v68.v2);
      v71.r = 0.0;
      *(_QWORD *)&v71.g = 1056964608i64;
      v71.a = 0.5;
      Render::Poly::SetColour((Render::Poly *)&v68.v2, &v71);
      Render::View::Draw(view, (Render::Poly *)&v68.v2, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v68.v2.z = 0i64;
      *(_QWORD *)&v68.v3.x = 0i64;
      p_z = (UFG::qColour *)&v68.v2.z;
    }
    else
    {
      if ( i != 2 )
        continue;
      Render::View::Draw(view, &gDeferredCube, &d, 0, this->mMatStencilWriteShadowFar);
      v60 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -860456360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].UFG::qResourceData + 22),
          0xCCB67A58);
        v61 = v60->mMaterialUser.mOffset;
        if ( v61 )
          v62 = (_WORD *)((char *)&v60->mMaterialUser + v61);
        else
          v62 = 0i64;
        *v62 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>((Render::Poly *)&v68.v1.z);
      *(_QWORD *)&v73.r = 0i64;
      v73.b = 0.5;
      v73.a = 0.5;
      Render::Poly::SetColour((Render::Poly *)&v68.v1.z, &v73);
      Render::View::Draw(view, (Render::Poly *)&v68.v1.z, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v72.r = 0i64;
      *(_QWORD *)&v72.b = 0i64;
      p_z = &v72;
    }
    Render::View::Clear(view, p_z, 4u, 1.0, 0);
  }
  v63 = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v64 = v63->mMaterialUser.mOffset;
    if ( v64 )
      v65 = (_WORD *)((char *)&v63->mMaterialUser + v64);
    else
      v65 = 0i64;
    *v65 |= 0x20u;
    v63 = Render::gRenderUtilities.mMaterial;
  }
  if ( *(_DWORD *)&v63[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v63[2].mDebugName[4],
      *((_DWORD *)&v63[2].UFG::qResourceData + 22),
      0x62F81854u);
    v66 = v63->mMaterialUser.mOffset;
    if ( v66 )
      v4 = (_WORD *)((char *)&v63->mMaterialUser + v66);
    *v4 |= 0x20u;
  }
}].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v63

// File Line: 2068
// RVA: 0x37D90
void __fastcall UFG::RenderStageShadow::BuildCascadedShadowViews(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qMatrix44 *cameraWorld,
        float cameraNear,
        float cameraFov,
        float cameraAspectRatio,
        UFG::qVector3 *lightPos,
        UFG::qVector3 *lightPosQuant,
        UFG::qVector3 *heightMapPos,
        UFG::qVector3 *lightTarget,
        float lightNear,
        float lightMaxFar)
{
  float v14; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  signed int cascade; // edi
  float *mCutplanes; // rsi
  float *p_z; // r14
  UFG::qVector4 v22; // xmm3
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm3
  float v28; // eax
  __int64 v29; // rcx
  Render::ViewSettings *worldShadow; // r8
  UFG::qMatrix44 *shadowProj; // rax
  UFG::qVector3 *light; // rcx
  Render::RenderOutputParams outSettings; // [rsp+70h] [rbp-E8h] BYREF

  this->mSplitPattern[0] = cameraNear;
  v14 = cameraNear + this->mSplits[0];
  v17 = cameraNear + this->mSplits[2];
  v18 = cameraNear + this->mSplits[1];
  this->mSplitPattern[1] = v14;
  this->mSplitPattern[3] = v17;
  this->mSplitPattern[2] = v18;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  cascade = 0;
  mCutplanes = this->mCutplanes;
  p_z = &this->mBoundingSphere[0].z;
  do
  {
    *mCutplanes = mCutplanes[159];
    if ( cascade == 3 )
    {
      UFG::RenderStageShadow::CalculateCSMTransforms(
        this,
        render_context,
        cameraWorld,
        2.0,
        cameraAspectRatio,
        &this->mShadowViewSettings[3].mWorldView,
        &this->mShadowViewSettings[3].mProjection,
        &this->mBoundingSphere[3],
        heightMapPos,
        lightTarget,
        lightNear,
        lightMaxFar,
        3u);
      if ( render_context->mNumCascades == 1 )
      {
        v22 = this->mShadowViewSettings[3].mWorldView.v1;
        v23 = this->mShadowViewSettings[3].mWorldView.v2;
        v24 = this->mShadowViewSettings[3].mWorldView.v3;
        this->mShadowViewSettings[0].mWorldView.v0 = this->mShadowViewSettings[3].mWorldView.v0;
        this->mShadowViewSettings[0].mWorldView.v1 = v22;
        this->mShadowViewSettings[0].mWorldView.v2 = v23;
        this->mShadowViewSettings[0].mWorldView.v3 = v24;
        v25 = this->mShadowViewSettings[3].mProjection.v2;
        v26 = this->mShadowViewSettings[3].mProjection.v3;
        v27 = this->mShadowViewSettings[3].mProjection.v1;
        this->mShadowViewSettings[0].mProjection.v0 = this->mShadowViewSettings[3].mProjection.v0;
        this->mShadowViewSettings[0].mProjection.v1 = v27;
        this->mShadowViewSettings[0].mProjection.v2 = v25;
        this->mShadowViewSettings[0].mProjection.v3 = v26;
        v26.x = *p_z;
        v28 = *(p_z - 2);
        v25.x = p_z[1];
        this->mBoundingSphere[0].y = *(p_z - 1);
        this->mBoundingSphere[0].z = v26.x;
        this->mBoundingSphere[0].x = v28;
        this->mBoundingSphere[0].w = v25.x;
      }
    }
    else
    {
      v29 = cascade;
      worldShadow = &this->mShadowViewSettings[v29];
      shadowProj = &this->mShadowViewSettings[v29].mProjection;
      light = lightPosQuant;
      if ( !this->mEnableAdjustedSunDir )
        light = lightPos;
      UFG::RenderStageShadow::CalculateCSMTransforms(
        this,
        render_context,
        cameraWorld,
        cameraFov,
        cameraAspectRatio,
        &worldShadow->mWorldView,
        shadowProj,
        &this->mBoundingSphere[cascade],
        light,
        lightTarget,
        lightNear,
        lightMaxFar,
        cascade);
    }
    ++cascade;
    ++mCutplanes;
    p_z += 4;
  }
  while ( cascade < 4 );
}

// File Line: 2163
// RVA: 0x38070
void __fastcall UFG::RenderStageShadow::CalculateCSMTransforms(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        UFG::qMatrix44 *camTransform,
        float FOV,
        float aspect,
        UFG::qMatrix44 *worldShadow,
        UFG::qMatrix44 *shadowProj,
        UFG::qVector4 *bounding,
        UFG::qVector3 *light,
        UFG::qVector3 *target,
        float lightNear,
        float lightMaxFar,
        unsigned int cascade)
{
  float v15; // xmm6_4
  __m128 v16; // xmm10
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  float v30; // xmm9_4
  float v31; // xmm1_4
  int v32; // ecx
  float v33; // xmm1_4
  int v34; // ecx
  UFG::qVector3 up; // [rsp+38h] [rbp-C0h] BYREF
  UFG::qVector3 v36; // [rsp+48h] [rbp-B0h] BYREF
  UFG::qVector3 eye; // [rsp+58h] [rbp-A0h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-88h] BYREF

  *(_QWORD *)&up.x = 0i64;
  up.z = 1.0;
  v15 = this->mSplitPattern[cascade];
  v16 = (__m128)LODWORD(this->mSplitPattern[cascade + 1]);
  if ( cascade == 2 )
  {
    v15 = 0.0;
  }
  else if ( cascade == 3 )
  {
    v15 = this->mSplitPattern[0];
    v16 = (__m128)LODWORD(this->mSplitPattern[1]);
  }
  v17 = tanf(FOV * 0.5);
  v18 = (float)(v17 * v16.m128_f32[0]) * (float)(v17 * v16.m128_f32[0]);
  v19 = (float)((float)(v17 / aspect) * v16.m128_f32[0]) * (float)((float)(v17 / aspect) * v16.m128_f32[0]);
  v20 = (float)((float)((float)((float)((float)((float)((float)(v17 * v15) * (float)(v17 * v15)) - v18)
                                      + (float)((float)((float)(v17 / aspect) * v15)
                                              * (float)((float)(v17 / aspect) * v15)))
                              - v19)
                      + (float)(v15 * v15))
              - (float)(v16.m128_f32[0] * v16.m128_f32[0]))
      / (float)((float)(v15 * 2.0) - (float)(v16.m128_f32[0] * 2.0));
  v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] - v20) * (float)(v16.m128_f32[0] - v20)) + (float)(v19 + v18);
  v21 = _mm_sqrt_ps(v16).m128_f32[0];
  v22 = camTransform->v3.z - (float)(v20 * camTransform->v2.z);
  v23 = camTransform->v3.y - (float)(v20 * camTransform->v2.y);
  v24 = camTransform->v3.x - (float)(v20 * camTransform->v2.x);
  v36.x = v24;
  v36.y = v23;
  v36.z = v22;
  bounding->x = v24;
  bounding->y = v23;
  bounding->z = v22;
  bounding->w = v21 * v21;
  v25 = (float)(light->z - target->z) + v22;
  v26 = (float)(light->y - target->y) + v23;
  eye.x = (float)(light->x - target->x) + v24;
  eye.y = v26;
  eye.z = v25;
  UFG::qLookAtMatrix(worldShadow, &eye, &v36, &up);
  UFG::qOrthographicMatrix(shadowProj, v21 * 2.0, v21 * 2.0, lightNear, lightMaxFar);
  if ( (_S4_0 & 1) != 0 )
  {
    v27 = QUANT_DIM;
  }
  else
  {
    _S4_0 |= 1u;
    v27 = (float)(int)render_context->mCascadeShadowSize * 0.125;
    QUANT_DIM = v27;
  }
  UFG::qMatrix44::operator*(worldShadow, &result, shadowProj);
  x_low = (__m128)LODWORD(result.v3.x);
  x_low.m128_f32[0] = result.v3.x * v27;
  y_low = (__m128)LODWORD(result.v3.y);
  y_low.m128_f32[0] = result.v3.y * v27;
  v30 = 1.0 / v27;
  v31 = result.v3.x * v27;
  v32 = (int)(float)(result.v3.x * v27);
  if ( v32 != 0x80000000 && (float)v32 != x_low.m128_f32[0] )
    v31 = (float)(v32 - (_mm_movemask_ps(_mm_unpacklo_ps(x_low, x_low)) & 1));
  shadowProj->v3.x = (float)((float)(v31 - x_low.m128_f32[0]) * v30) + shadowProj->v3.x;
  v33 = y_low.m128_f32[0];
  v34 = (int)y_low.m128_f32[0];
  if ( (int)y_low.m128_f32[0] != 0x80000000 && (float)v34 != y_low.m128_f32[0] )
    v33 = (float)(v34 - (_mm_movemask_ps(_mm_unpacklo_ps(y_low, y_low)) & 1));
  shadowProj->v3.y = (float)((float)(v33 - y_low.m128_f32[0]) * v30) + shadowProj->v3.y;
}

// File Line: 2236
// RVA: 0x3B960
void __fastcall UFG::RenderStageShadow::RenderDebugOverlay(
        UFG::RenderStageShadow *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        int x,
        int y,
        int size)
{
  Illusion::Texture *mDepthTextureCopy; // rcx
  UFG::qColour v7; // [rsp+40h] [rbp-18h] BYREF

  mDepthTextureCopy = render_context->mHalfSizeShadowTarget->mDepthTextureCopy;
  v7 = UFG::qColour::White;
  Render::View::DrawIcon(view, mDepthTextureCopy->mNode.mUID, x, y, size, size, &v7, 0xA3833FDE);
}

