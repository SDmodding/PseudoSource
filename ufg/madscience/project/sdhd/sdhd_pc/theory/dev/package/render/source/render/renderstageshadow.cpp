// File Line: 131
// RVA: 0x383B0
void __fastcall UFG::RenderStageShadow::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  char *v2; // rax

  v1 = render_context;
  v2 = UFG::qMalloc(0x580ui64, "RenderStageShadow", 0i64);
  if ( v2 )
    UFG::RenderStageShadow::RenderStageShadow((UFG::RenderStageShadow *)v2, v1);
}

// File Line: 142
// RVA: 0x367D0
void __fastcall UFG::RenderStageShadow::RenderStageShadow(UFG::RenderStageShadow *this, UFG::RenderContext *render_context)
{
  UFG::RenderContext *v2; // rsi
  UFG::RenderStageShadow *v3; // rbp
  UFG::qResourceHandle *v4; // r14
  unsigned int v5; // eax
  Illusion::Material *v6; // rdi
  int v7; // ebx
  unsigned int v8; // ebx
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
  Illusion::Material *v19; // rax
  Illusion::Material *v20; // rdi
  unsigned int v21; // ebx
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceData *v23; // rax
  UFG::qResourceData *v24; // rbx
  UFG::qResourceWarehouse *v25; // rax
  UFG::qResourceData *v26; // rax
  UFG::qResourceData *v27; // rbx
  UFG::qResourceWarehouse *v28; // rax
  UFG::qResourceData *v29; // rax
  UFG::qResourceData *v30; // rbx
  UFG::qResourceWarehouse *v31; // rax
  UFG::qResourceData *v32; // rax
  UFG::qResourceData *v33; // rbx
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceData *v35; // rax
  UFG::qResourceData *v36; // rbx
  UFG::qResourceWarehouse *v37; // rax
  UFG::qResourceData *v38; // rax
  UFG::qResourceData *v39; // rbx
  UFG::qResourceWarehouse *v40; // rax
  UFG::qResourceData *v41; // rax
  UFG::qResourceData *v42; // rbx
  UFG::qResourceWarehouse *v43; // rax
  UFG::qResourceData *v44; // rax
  UFG::qResourceData *v45; // rbx
  UFG::qResourceWarehouse *v46; // rax
  UFG::qResourceInventory *v47; // rax
  UFG::qResourceWarehouse *v48; // rax
  UFG::qResourceInventory *v49; // rax
  UFG::qResourceWarehouse *v50; // rax
  UFG::qResourceInventory *v51; // rax
  UFG::qResourceWarehouse *v52; // rax
  UFG::qResourceInventory *v53; // rax
  UFG::qResourceWarehouse *v54; // rax
  UFG::qResourceInventory *v55; // rax
  UFG::qResourceWarehouse *v56; // rax
  UFG::qResourceInventory *v57; // rax
  UFG::qResourceWarehouse *v58; // rax
  UFG::qResourceInventory *v59; // rax
  UFG::qResourceWarehouse *v60; // rax
  UFG::qResourceInventory *v61; // rax
  UFG::qResourceWarehouse *v62; // rax
  UFG::qResourceInventory *v63; // rax
  UFG::qResourceWarehouse *v64; // rax
  UFG::qResourceInventory *v65; // rax
  UFG::qResourceWarehouse *v66; // rax
  unsigned int v67; // ebx
  UFG::qResourceInventory *v68; // rax
  UFG::qResourceWarehouse *v69; // rax

  v2 = render_context;
  v3 = this;
  v4 = (UFG::qResourceHandle *)&this->mRasterStateCharacterShadowCollectorHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRasterStateCharacterShadowCollectorHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRasterStateDoubleSidedHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRasterStateInvertCullingHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRasterStateNormalHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCharacterShadowCollectorAlphaStateHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mAlphaStateNoColourWriteHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCharacterShadowCollectorShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCharacterShadowCollectorLowShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCharacterShadowCollectorHighShaderHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mNoiseTextureHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mCloudVolumePrimitiveVertexDecl.mPrev);
  *(_QWORD *)&v3->mNumShadowsRendered = 0i64;
  v3->mShadowFOV = -1.0;
  v3->mShadowNear = 16.0;
  v3->mShadowFar = 1256.0;
  v3->mShadowOffset = 1024.0;
  v3->mMinShadowFOV = 90.0;
  *(_WORD *)&v3->mDrawDebugShadowMap = 0;
  *(_WORD *)&v3->mRenderingNISCharacterShadows = 0;
  v3->mCascadeSplit[0] = 0.86000001;
  v3->mCascadeSplit[1] = 1.1;
  v3->mCascadeSplit[2] = 0.89999998;
  v3->mCascadeSplit[3] = 0.86000001;
  v3->mCascadeBias[0] = 1.0;
  v3->mCascadeBias[1] = 1.0;
  v3->mCascadeBias[2] = 1.0;
  v3->mCascadeBias[3] = 1.0;
  v3->mCascadeFilterWidth[0] = 0.00025000001;
  v3->mCascadeFilterWidth[1] = 0.00030000001;
  v3->mCascadeFilterWidth[2] = 0.00019999999;
  v3->mCascadeFilterWidth[3] = 0.00025000001;
  v3->mCascadeSplitHQ[0] = 0.95999998;
  v3->mCascadeSplitHQ[1] = 1.3;
  v3->mCascadeSplitHQ[2] = 1.5;
  v3->mCascadeSplitHQ[3] = 0.95999998;
  v3->mCascadeBiasHQ[0] = 1.0;
  v3->mCascadeBiasHQ[1] = 1.0;
  v3->mCascadeBiasHQ[2] = 1.0;
  v3->mCascadeBiasHQ[3] = 1.0;
  v3->mCascadeFilterWidthHQ[0] = 0.00017500001;
  v3->mCascadeFilterWidthHQ[1] = 0.00021000001;
  v3->mCascadeFilterWidthHQ[2] = 0.00013999999;
  v3->mCascadeFilterWidthHQ[3] = 0.00017500001;
  UFG::qMemSet(v3->mSplitPattern, 0, 0x10u);
  v3->mBiases[0] = UFG::RenderStageShadow::DEFAULT_BIAS0;
  v3->mBiases[1] = UFG::RenderStageShadow::DEFAULT_BIAS1;
  v3->mBiases[2] = UFG::RenderStageShadow::DEFAULT_BIAS2;
  v3->mBiases[3] = UFG::RenderStageShadow::DEFAULT_BIAS0;
  v3->mSplits[0] = UFG::RenderStageShadow::DEFAULT_SPLIT0;
  v3->mSplits[1] = UFG::RenderStageShadow::DEFAULT_SPLIT1;
  v3->mSplits[2] = UFG::RenderStageShadow::DEFAULT_SPLIT2;
  v3->mSplits[3] = UFG::RenderStageShadow::DEFAULT_SPLIT0;
  v3->mShadowFilterWidth[0] = 0.00025000001;
  v3->mShadowFilterWidth[1] = 0.00030000001;
  v3->mShadowFilterWidth[2] = 0.00019999999;
  v3->mShadowFilterWidth[3] = 0.00025000001;
  *(_QWORD *)&v3->mShadowViewSettings[0].mCullPixelDensityThreshold = 1022739087i64;
  v3->mShadowViewSettings[0].mCullIndex = -1;
  *(_QWORD *)&v3->mShadowViewSettings[1].mCullPixelDensityThreshold = 1024416809i64;
  v3->mShadowViewSettings[1].mCullIndex = -1;
  *(_QWORD *)&v3->mShadowViewSettings[2].mCullPixelDensityThreshold = 1028443341i64;
  v3->mShadowViewSettings[2].mCullIndex = -1;
  *(_QWORD *)&v3->mShadowViewSettings[3].mCullPixelDensityThreshold = 1028443341i64;
  v3->mShadowViewSettings[3].mCullIndex = -1;
  v3->mCloudShadowCullDist = 250.0;
  v3->mCloudShadowMinVolume = 16000.0;
  *(_WORD *)&v3->mEnableCloudShadows = 256;
  v3->mEnableAdjustedSunDir = 1;
  v5 = UFG::qStringHashUpper32("DepthDownsample_Shadow", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewMaterial("DepthDownsample_Shadow", v5, 4u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLESHADOW", 0xFFFFFFFF);
  LOWORD(v6[1].mNode.mChild[0]) = 0;
  HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.mNode.mNext) = v7;
  v8 = v2->mCascadeShadowTextureAliasDepth->mNode.mUID;
  *(_WORD *)&v6[1].mDebugName[12] = 0;
  *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v6[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v6[1].mStateBlockMask.mFlags[0]) = v8;
  LOWORD(v6[1].mMaterialUser.mOffset) = 0;
  *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v6[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.mNode.mPrev) = 315097330;
  v6[2].mNode.mUID = -1851597485;
  LOWORD(v6[2].mTypeUID) = 0;
  HIDWORD(v6[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v6[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v6[2].0 + 22) = 1002903008;
  *(_DWORD *)&v6[2].mDebugName[28] = -119921445;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, (UFG::qResourceData *)&v6->mNode);
  v3->mMatDepthDownsampleShadow = v6;
  v10 = UFG::qStringHashUpper32("MatStencilWriteShadowNear", 0xFFFFFFFF);
  v11 = Illusion::Factory::NewMaterial("MatStencilWriteShadowNear", v10, 3u, 0i64, 0i64, 0i64);
  v12 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v11[1].mNode.mChild[0]) = 0;
  HIDWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11[1].mTypeUID = -1957338719;
  LODWORD(v11[1].mResourceHandles.mNode.mNext) = v12;
  *(_WORD *)&v11[1].mDebugName[12] = 0;
  *(_DWORD *)&v11[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v11[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v11[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v11[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v11[1].mMaterialUser.mOffset) = 0;
  *(&v11[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v11[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v11[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v11[2].mNode.mUID = 1522949938;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, (UFG::qResourceData *)&v11->mNode);
  v3->mMatStencilWriteShadowNear = v11;
  v14 = UFG::qStringHashUpper32("MatStencilWriteShadowFar", 0xFFFFFFFF);
  v15 = Illusion::Factory::NewMaterial("MatStencilWriteShadowFar", v14, 3u, 0i64, 0i64, 0i64);
  v16 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v15[1].mNode.mChild[0]) = 0;
  HIDWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v15[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v15[1].mTypeUID = -1957338719;
  LODWORD(v15[1].mResourceHandles.mNode.mNext) = v16;
  *(_WORD *)&v15[1].mDebugName[12] = 0;
  *(_DWORD *)&v15[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v15[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v15[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v15[1].mStateBlockMask.mFlags[0]) = -1851597485;
  LOWORD(v15[1].mMaterialUser.mOffset) = 0;
  *(&v15[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v15[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v15[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v15[2].mNode.mUID = -57444623;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, (UFG::qResourceData *)&v15->mNode);
  v3->mMatStencilWriteShadowFar = v15;
  v18 = UFG::qStringHashUpper32("CloudShadowVolumeMat", 0xFFFFFFFF);
  v19 = Illusion::Factory::NewMaterial("CloudShadowVolumeMat", v18, 5u, 0i64, 0i64, 0i64);
  v20 = v19;
  LOWORD(v19[1].mNode.mChild[0]) = 0;
  HIDWORD(v19[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v20[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v20[1].mTypeUID = -1957338719;
  LODWORD(v20[1].mResourceHandles.mNode.mNext) = -1941137269;
  v21 = v2->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  *(_WORD *)&v20[1].mDebugName[12] = 0;
  *(_DWORD *)&v20[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v20[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v20[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v20[1].mStateBlockMask.mFlags[0]) = v21;
  LOWORD(v20[1].mMaterialUser.mOffset) = 0;
  *(&v20[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v20[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v20[2].mResourceHandles.mNode.mPrev) = 315097330;
  v20[2].mNode.mUID = -1053429752;
  LOWORD(v20[2].mTypeUID) = 0;
  HIDWORD(v20[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v20[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v20[2].0 + 22) = 1002903008;
  *(_DWORD *)&v20[2].mDebugName[28] = 1660426324;
  LOWORD(v20[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v20[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v20[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v20[3].mNode.mChild[0]) = 0;
  v22 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v22, (UFG::qResourceData *)&v20->mNode);
  v3->mMatCloudShadowVolume = v20;
  v23 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilWriteFar", 0xFC9376F1, 0i64, 0i64, 0i64);
  v24 = v23;
  LODWORD(v23[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v23[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v23[1].mNode.mChild + 6) = 519;
  WORD2(v23[1].mNode.mChild[0]) = 511;
  v25 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v25, v24);
  v26 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestFar", 0x5000AC30u, 0i64, 0i64, 0i64);
  v27 = v26;
  LODWORD(v26[1].mNode.mParent) = 33751041;
  HIWORD(v26[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v26[1].mNode.mChild + 6) = 2;
  WORD2(v26[1].mNode.mChild[0]) = 255;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, v27);
  v29 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilWriteNear", 0x5AC65F32u, 0i64, 0i64, 0i64);
  v30 = v29;
  LODWORD(v29[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v29[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v29[1].mNode.mChild + 6) = 519;
  WORD2(v29[1].mNode.mChild[0]) = 511;
  v31 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v31, v30);
  v32 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestNear", 0xD3F5358u, 0i64, 0i64, 0i64);
  v33 = v32;
  LODWORD(v32[1].mNode.mParent) = 34013184;
  HIWORD(v32[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v32[1].mNode.mChild + 5) = 512;
  BYTE4(v32[1].mNode.mChild[0]) = -1;
  BYTE1(v32[1].mNode.mChild[1]) = 0;
  v34 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v34, v33);
  v35 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestFarDebug", 0xCCB67A58, 0i64, 0i64, 0i64);
  v36 = v35;
  LODWORD(v35[1].mNode.mParent) = 458752;
  HIWORD(v35[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v35[1].mNode.mChild + 6) = 2;
  WORD2(v35[1].mNode.mChild[0]) = 255;
  v37 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v37, v36);
  v38 = Illusion::Factory::NewRasterState("Collector.RasterState.StencilTestNearDebug", 0xC5AA9974, 0i64, 0i64, 0i64);
  v39 = v38;
  LODWORD(v38[1].mNode.mParent) = 458752;
  HIWORD(v38[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v38[1].mNode.mChild + 5) = 512;
  BYTE4(v38[1].mNode.mChild[0]) = -1;
  BYTE1(v38[1].mNode.mChild[1]) = 0;
  v40 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v40, v39);
  v41 = Illusion::Factory::NewRasterState(
          "Collector.RasterState.CloudShadowStencilTestFar",
          0xE48814A0,
          0i64,
          0i64,
          0i64);
  v42 = v41;
  LODWORD(v41[1].mNode.mParent) = 16973825;
  HIWORD(v41[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v41[1].mNode.mChild + 6) = 2;
  WORD2(v41[1].mNode.mChild[0]) = 255;
  v43 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v43, v42);
  v44 = Illusion::Factory::NewAlphaState("Collector.AlphaState.ShadowAlphaOnly", 0xC135F008, 0i64, 0i64, 0i64);
  v45 = v44;
  LOWORD(v44[1].mNode.mParent) = 257;
  BYTE2(v44[1].mNode.mParent) = 1;
  LOWORD(v44[1].mNode.mChild[0]) = 257;
  BYTE2(v44[1].mNode.mChild[0]) = 1;
  BYTE4(v44[1].mNode.mParent) = 4;
  v46 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v46, v45);
  v47 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v48 = UFG::qResourceWarehouse::Instance();
    v47 = UFG::qResourceWarehouse::GetInventory(v48, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v47;
  }
  UFG::qResourceHandle::Init(v4, 0x3BC715E0u, 0x455DCC70u, v47);
  v49 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v50 = UFG::qResourceWarehouse::Instance();
    v49 = UFG::qResourceWarehouse::GetInventory(v50, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v49;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mCharacterShadowCollectorShaderHandle.mPrev,
    0x8B5561A1,
    0x17B8B4A8u,
    v49);
  v51 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v52 = UFG::qResourceWarehouse::Instance();
    v51 = UFG::qResourceWarehouse::GetInventory(v52, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v51;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mCharacterShadowCollectorLowShaderHandle.mPrev,
    0x8B5561A1,
    0x2915C547u,
    v51);
  v53 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
  {
    v54 = UFG::qResourceWarehouse::Instance();
    v53 = UFG::qResourceWarehouse::GetInventory(v54, 0x8B5561A1);
    `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v53;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mCharacterShadowCollectorHighShaderHandle.mPrev,
    0x8B5561A1,
    0xD5D6A024,
    v53);
  v55 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v56 = UFG::qResourceWarehouse::Instance();
    v55 = UFG::qResourceWarehouse::GetInventory(v56, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v55;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mCharacterShadowCollectorAlphaStateHandle.mPrev,
    0x12C800F2u,
    0x2782CCE6u,
    v55);
  v57 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
  {
    v58 = UFG::qResourceWarehouse::Instance();
    v57 = UFG::qResourceWarehouse::GetInventory(v58, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v57;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mNoiseTextureHandle.mPrev, 0x8B43FABF, 0x952102D8, v57);
  v59 = `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result )
  {
    v60 = UFG::qResourceWarehouse::Instance();
    v59 = UFG::qResourceWarehouse::GetInventory(v60, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>'::`2'::result = v59;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mAlphaStateNoColourWriteHandle.mPrev,
    0x12C800F2u,
    0x91A2DD53,
    v59);
  v61 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v62 = UFG::qResourceWarehouse::Instance();
    v61 = UFG::qResourceWarehouse::GetInventory(v62, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v61;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mRasterStateInvertCullingHandle.mPrev,
    0x3BC715E0u,
    0xBC9FAF09,
    v61);
  v63 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v64 = UFG::qResourceWarehouse::Instance();
    v63 = UFG::qResourceWarehouse::GetInventory(v64, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v63;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mRasterStateDoubleSidedHandle.mPrev,
    0x3BC715E0u,
    0x940FB8EC,
    v63);
  v65 = `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result )
  {
    v66 = UFG::qResourceWarehouse::Instance();
    v65 = UFG::qResourceWarehouse::GetInventory(v66, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>'::`2'::result = v65;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mRasterStateNormalHandle.mPrev, 0x3BC715E0u, 0x20688F05u, v65);
  v67 = UFG::qStringHash32("VertexDecl.Slim", 0xFFFFFFFF);
  v68 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v69 = UFG::qResourceWarehouse::Instance();
    v68 = UFG::qResourceWarehouse::GetInventory(v69, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v68;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mCloudVolumePrimitiveVertexDecl.mPrev, 0x3E5FDA3Eu, v67, v68);
}

// File Line: 550
// RVA: 0x38660
float __fastcall UFG::RenderStageShadow::GetCascadeShadowFOV(UFG::RenderStageShadow *this)
{
  UFG::RenderStageShadow *v1; // rbx
  float result; // xmm0_4
  UFG::BaseCameraComponent *v3; // rcx
  signed __int64 v4; // rcx
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float v9; // xmm1_4

  v1 = this;
  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 )
    return FLOAT_2_0;
  v3 = UFG::Director::Get()->mCurrentCamera;
  if ( v3 && (v4 = (signed __int64)&v3->mCamera) != 0 )
  {
    v5 = FLOAT_3_1415927;
    v6 = *(float *)(v4 + 192);
    result = 0.0;
    v7 = FLOAT_0_0055555557;
    v8 = (float)(v1->mMinShadowFOV * 3.1415927) * 0.0055555557;
    if ( v6 != 0.0 )
      result = atan2f(1.0, v6) * 2.0;
    if ( result <= v8 )
      result = v8;
  }
  else
  {
    v5 = FLOAT_3_1415927;
    v7 = FLOAT_0_0055555557;
    result = (float)(v1->mMinShadowFOV * 3.1415927) * 0.0055555557;
  }
  v9 = v1->mShadowFOV;
  if ( v9 > -1.0 )
    result = (float)(v9 * v5) * v7;
  return result;
}

// File Line: 588
// RVA: 0x3D600
void __fastcall UFG::RenderStageShadow::UpdateViews(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, float fRealTimeDelta)
{
  UFG::RenderContext *v3; // rbx
  UFG::RenderStageShadow *v4; // r14
  UFG::TimeOfDayManager *v5; // rax
  UFG::TimeOfDayManager *v6; // rax
  unsigned int v7; // esi
  float v8; // xmm10_4
  UFG::TimeOfDayManager *v9; // rax
  UFG::TimeOfDayManager *v10; // rax
  float v11; // xmm9_4
  float cameraFov; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float cameraAspectRatio; // xmm0_4
  _DWORD *v16; // rbx
  unsigned int v17; // edi
  CullManager *v18; // rax
  unsigned int v19; // eax
  UFG::qVector3 lightPos; // [rsp+60h] [rbp-88h]
  float v21; // [rsp+6Ch] [rbp-7Ch]
  UFG::qVector3 heightMapPos; // [rsp+70h] [rbp-78h]
  float v23; // [rsp+7Ch] [rbp-6Ch]
  UFG::qVector4 v24; // [rsp+88h] [rbp-60h]
  Render::RenderOutputParams outSettings; // [rsp+98h] [rbp-50h]
  CB_EnvironmentSettings envState; // [rsp+108h] [rbp+20h]
  float vars0; // [rsp+290h] [rbp+1A8h]

  v3 = render_context;
  v4 = this;
  v5 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetEnvironmentSettings(v5, &envState, &v3->mMainViewSettings, 0i64);
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
  v3->mNumCascades = v7;
  if ( v7 )
  {
    v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(FLOAT_1_0001)));
    v9 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetSunDir(v9, (UFG::qVector4 *)&heightMapPos.z, 1, 0);
    v10 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetSunDir(v10, &v24, 1, 1);
    UFG::qInverseAffine((UFG::qMatrix44 *)&outSettings, &v3->mMainViewSettings.mWorldView);
    v11 = v4->mShadowOffset;
    v21 = *(float *)&outSettings.mMotionBlur + (float)(v23 * v11);
    lightPos.y = *(float *)&outSettings.mMotionBlur + (float)(v24.y * v11);
    heightMapPos.x = (float)((float)(v8 * 0.0) * v11) + *(float *)&outSettings.mShadowFilter;
    heightMapPos.y = (float)((float)(v8 * 0.0099999998) * v11) + *(float *)&outSettings.mMotionBlur;
    heightMapPos.z = (float)(v8 * v11) + outSettings.mInterAxialDistance;
    lightPos.x = *(float *)&outSettings.mShadowFilter + (float)(v24.x * v11);
    lightPos.z = outSettings.mInterAxialDistance + (float)(v24.z * v11);
    cameraFov = UFG::RenderStageShadow::GetCascadeShadowFOV(v4);
    UFG::RenderStageShadow::SetCascadeShadowParams(v4, v3);
    v13 = v3->mMainViewSettings.mProjection.v2.z;
    if ( v13 == 0.0 || v13 == v3->mMainViewSettings.mProjection.v2.w )
      v14 = vars0;
    else
      v14 = v3->mMainViewSettings.mProjection.v3.z / v13;
    if ( v14 <= v4->mZBoundMin )
      v14 = v4->mZBoundMin;
    cameraAspectRatio = Render::GetDisplayAspectRatio();
    UFG::RenderStageShadow::BuildCascadedShadowViews(
      v4,
      v3,
      (UFG::qMatrix44 *)&outSettings,
      v14,
      cameraFov,
      cameraAspectRatio,
      (UFG::qVector3 *)((char *)&lightPos + 8),
      &lightPos,
      &heightMapPos,
      (UFG::qVector3 *)&outSettings.mShadowFilter,
      v4->mShadowNear,
      v4->mShadowFar);
  }
  v16 = &v4->mShadowViewSettings[0].mCullIndex;
  v17 = 0;
  do
  {
    if ( v17 >= v7 )
    {
      *v16 = -1;
    }
    else
    {
      *(_QWORD *)&outSettings.mLODSetting = 0i64;
      CullManager::CullSettings::SetFromViewSettings(
        (CullManager::CullSettings *)&outSettings,
        (Render::ViewSettings *)(v16 - 32));
      v18 = CullManager::Instance();
      v19 = CullManager::RegisterView(v18, (CullManager::CullSettings *)&outSettings);
      *v16 = v19;
      Illusion::eCastShadow::SetSunShadowView(v19);
    }
    ++v17;
    v16 += 36;
  }
  while ( v17 < 4 );
}llusion::eCastShadow::SetSunShadowView(v19);
    }
    ++v17;
    v16 += 36;
  }
  while ( v

// File Line: 666
// RVA: 0x3CC80
void __fastcall UFG::RenderStageShadow::SetCascadeShadowParams(UFG::RenderStageShadow *this, UFG::RenderContext *render_context)
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
  if ( render_context->mRenderSettingsForFrame.mShadowRes == 2 )
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
UFG::qTaskGroup *__fastcall UFG::RenderStageShadow::SubmitCullingTasks(UFG::RenderStageShadow *this, UFG::RenderContext *render_context)
{
  unsigned int v2; // eax
  UFG::RenderContext *v3; // rbp
  UFG::RenderStageShadow *v4; // rsi
  unsigned int v5; // ebx
  int *v6; // rdi
  CullManager *v7; // rax
  UFG::qTaskGroup *result; // rax

  v2 = render_context->mNumCascades;
  v3 = render_context;
  v4 = this;
  if ( v2 )
  {
    v5 = 0;
    if ( v2 )
    {
      v6 = &this->mShadowViewSettings[0].mCullIndex;
      do
      {
        v7 = CullManager::Instance();
        CullManager::BeginView(v7, *v6, 0i64);
        ++v5;
        v6 += 36;
      }
      while ( v5 < v3->mNumCascades );
    }
    result = CullManager::Instance()->mPrevCullingTask;
    v4->mNumShadowsRendered = 0;
  }
  else
  {
    this->mNumShadowsRendered = 0;
    result = 0i64;
  }
  return result;
}

// File Line: 730
// RVA: 0x3D060
UFG::ShadowRenderQueueTaskResults *__fastcall UFG::RenderStageShadow::SubmitSceneryShadowTasks(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qTaskGroup *task_group_dep, CullLayer *cull_layer)
{
  UFG::qTaskGroup *v4; // rbx
  UFG::RenderContext *v5; // rdi
  UFG::RenderStageShadow *v6; // rsi
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r15
  unsigned int v10; // er13
  unsigned int v11; // eax
  unsigned int v12; // edi
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  unsigned int v15; // edi
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // ebp
  __int64 v19; // r14
  char *v20; // rax
  UFG::qTaskGroup *v21; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v22; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v23; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v24; // r15
  signed __int64 v25; // r12
  char *v26; // rbx
  UFG::qResourceData *v27; // rax
  BOOL v28; // eax
  UFG::qMatrix44 *v29; // rax
  UFG::qVector4 v30; // xmm2
  UFG::qVector4 v31; // xmm1
  UFG::qVector4 v32; // xmm0
  char *v33; // rax
  char *v34; // rdx
  _QWORD *v35; // rcx
  UFG::qSpuElf *v36; // rax
  void (__fastcall *v37)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v38)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v39)(void *, void *, void *, void *); // r9
  char *v40; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v41; // rax
  UFG::qMatrix44 *b; // [rsp+20h] [rbp-B8h]
  signed __int64 v44; // [rsp+28h] [rbp-B0h]
  UFG::qTaskGroup **v45; // [rsp+30h] [rbp-A8h]
  __int64 v46; // [rsp+38h] [rbp-A0h]
  UFG::qMatrix44 result; // [rsp+58h] [rbp-80h]
  bool v48; // [rsp+E8h] [rbp+10h]
  CullLayer *v49; // [rsp+F8h] [rbp+20h]

  v49 = cull_layer;
  v4 = task_group_dep;
  v5 = render_context;
  v6 = this;
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
  v46 = v9;
  *(_DWORD *)(v9 + 800) = v5->mNumCascades;
  v10 = v5->mNumCascades;
  v48 = v5->mRenderRain;
  v11 = _S1_8;
  if ( !(_S1_8 & 1) )
  {
    _S1_8 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandle_1.mPrev);
    atexit(UFG::RenderStageShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandle__);
    v11 = _S1_8;
  }
  if ( !(v11 & 2) )
  {
    _S1_8 = v11 | 2;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandleAlpha_0.mPrev);
    atexit(UFG::RenderStageShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandleAlpha__);
  }
  if ( !simpleInit_1 )
  {
    v12 = UFG::qStringHashUpper32("DR_EMITDEPTH_ALPHA", 0xFFFFFFFF);
    v13 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v14 = UFG::qResourceWarehouse::Instance();
      v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v13;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandleAlpha_0.mPrev, 0x8B5561A1, v12, v13);
    v15 = UFG::qStringHashUpper32("DR_EMITDEPTH", 0xFFFFFFFF);
    v16 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v17 = UFG::qResourceWarehouse::Instance();
      v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v16;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandle_1.mPrev, 0x8B5561A1, v15, v16);
    simpleInit_1 = 1;
  }
  v18 = 0;
  if ( v10 )
  {
    v45 = (UFG::qTaskGroup **)(v9 + 768);
    v19 = v9;
    v44 = v9 + 512;
    b = &v6->mShadowViewSettings[0].mProjection;
    do
    {
      v20 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
      v21 = (UFG::qTaskGroup *)v20;
      if ( v20 )
        UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v20, "ShadowTaskGroup");
      v22 = UFG::gTaskManager.mSingleFrameTaskGroups;
      v23 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
      v23->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v21->mPrev;
      v21->mPrev = v23;
      v21->mNext = &v22->mNode;
      v22->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v21->mPrev;
      if ( v4 )
        UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v21, v4);
      v24 = &v21->mTasks;
      v25 = 4i64;
      do
      {
        v26 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
        *((_QWORD *)v26 + 15) = v19;
        *((_DWORD *)v26 + 32) = v18;
        *((_QWORD *)v26 + 9) = v44;
        *((_QWORD *)v26 + 10) = v49;
        *((_QWORD *)v26 + 18) = simpleHandle_1.mData;
        *((_QWORD *)v26 + 12) = simpleHandleAlpha_0.mData;
        *((_QWORD *)v26 + 19) = v6->mAlphaStateNoColourWriteHandle.mData;
        if ( v48 || v18 == v10 - 1 )
          v27 = v6->mRasterStateDoubleSidedHandle.mData;
        else
          v27 = v6->mRasterStateInvertCullingHandle.mData;
        *((_QWORD *)v26 + 20) = v27;
        *((_QWORD *)v26 + 21) = v6->mRasterStateDoubleSidedHandle.mData;
        *((_DWORD *)v26 + 34) = Render::cbLocalProjectionState::sStateParamIndex;
        *((_QWORD *)v26 + 14) = Illusion::gEngine.FrameMemory;
        v28 = v48 || v18 == v10 - 1;
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
          v35 = v33 + 16;
          *v35 = v35;
          v35[1] = v35;
          v36 = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mSpuElf;
          v37 = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionSPU;
          v38 = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionPPU;
          v39 = gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mTaskFunctionOffload;
          if ( !gTaskFunctionDeclData_FastShadowDrawTask_SceneDB.mCurrentSPUEnabled )
          {
            v36 = 0i64;
            v37 = 0i64;
            v39 = 0i64;
          }
          *((_QWORD *)v34 + 6) = v21;
          *((_DWORD *)v34 + 14) = 2;
          *((_QWORD *)v34 + 4) = 0i64;
          *((_QWORD *)v34 + 5) = 0i64;
          *((_QWORD *)v34 + 8) = &gTaskFunctionDeclData_FastShadowDrawTask_SceneDB;
          if ( v36 )
            v40 = v36->mAddress;
          else
            v40 = 0i64;
          *((_QWORD *)v34 + 9) = v40;
          *((_QWORD *)v34 + 10) = v37;
          *((_QWORD *)v34 + 11) = v38;
          *((_QWORD *)v34 + 12) = v26;
          *((_QWORD *)v34 + 13) = 0i64;
          *((_QWORD *)v34 + 14) = 0i64;
          *((_QWORD *)v34 + 15) = 0i64;
          if ( v39 )
          {
            *((_DWORD *)v34 + 14) = 130;
            *((_DWORD *)v34 + 12) = 0;
          }
        }
        v41 = v24->mNode.mPrev;
        v41->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v34;
        *(_QWORD *)v34 = v41;
        *((_QWORD *)v34 + 1) = v24;
        v24->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v34;
        ++v21->mNumTasks;
        v19 += 32i64;
        --v25;
      }
      while ( v25 );
      UFG::qTaskManager::Queue(&UFG::gTaskManager, v21);
      *v45 = v21;
      v4 = v21;
      ++v18;
      v44 += 64i64;
      ++v45;
      b = (UFG::qMatrix44 *)((char *)b + 144);
    }
    while ( v18 < v10 );
    v9 = v46;
  }
  return (UFG::ShadowRenderQueueTaskResults *)v9;
}

// File Line: 810
// RVA: 0x3D510
void __fastcall UFG::RenderStageShadow::UpdateCollectorMaterial(UFG::RenderStageShadow *this, Illusion::Material *sunmat, unsigned int csmSlice, bool bLowQuality, bool bHighQuality)
{
  Illusion::Material *v5; // rbx
  unsigned int v6; // er8
  __int64 v7; // rax
  unsigned int v8; // er8
  __int64 v9; // rax
  unsigned int v10; // er8
  __int64 v11; // rax

  v5 = sunmat;
  if ( bHighQuality )
  {
    v6 = sunMats_high[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.mNode.mNext) == v6 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v6);
    v7 = v5->mMaterialUser.mOffset;
    if ( v7 )
    {
      *(_WORD *)((char *)&v5->mMaterialUser.mOffset + v7) |= 0x20u;
      return;
    }
  }
  else if ( bLowQuality )
  {
    v8 = sunMats_low[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.mNode.mNext) == v8 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v8);
    v9 = v5->mMaterialUser.mOffset;
    if ( v9 )
    {
      *(_WORD *)((char *)&v5->mMaterialUser.mOffset + v9) |= 0x20u;
      return;
    }
  }
  else
  {
    v10 = sunMats[csmSlice];
    if ( LODWORD(sunmat[1].mResourceHandles.mNode.mNext) == v10 )
      return;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&sunmat[1].mNode.mChild[1], sunmat[1].mTypeUID, v10);
    v11 = v5->mMaterialUser.mOffset;
    if ( v11 )
    {
      *(_WORD *)((char *)&v5->mMaterialUser.mOffset + v11) |= 0x20u;
      return;
    }
  }
  LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
}

// File Line: 856
// RVA: 0x3B9C0
void __fastcall UFG::RenderStageShadow::RenderShadowCollector(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, int shadowIdx, bool bFirst)
{
  __int64 v5; // r13
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rbx
  UFG::RenderContext *v7; // rsi
  UFG::RenderStageShadow *v8; // rdi
  Illusion::Target *v9; // rdx
  CB_EnvironmentSettings *v10; // rbx
  Illusion::StateValues *v11; // rax
  Render::ViewSettings *v12; // rbx
  UFG::qMatrix44 *v13; // r14
  unsigned __int16 v14; // ax
  Illusion::StateArgs *v15; // r15
  signed int v16; // er8
  unsigned __int64 v17; // rcx
  __int128 v18; // xmm2
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm2
  __int128 v22; // xmm1
  __int128 v23; // xmm0
  unsigned __int16 v24; // ax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
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
  Render::eShadowFilter v44; // eax
  bool v45; // r12
  Illusion::Material *dest_mip_level; // ST20_8
  Illusion::Material *v47; // rdi
  _WORD *v48; // rax
  UFG::qMatrix44 *v49; // r8
  Illusion::Material *v50; // ST20_8
  Illusion::Material *v51; // rdi
  _WORD *v52; // rax
  Illusion::Material *v53; // ST20_8
  Illusion::Material *v54; // rdi
  _WORD *v55; // rax
  Illusion::Material *v56; // ST20_8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v57; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v58; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v59; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v60; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v61; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v62; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v64; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 local_world; // [rsp+A0h] [rbp-60h]
  Render::cbExternalViewTransformState arg; // [rsp+E0h] [rbp-20h]
  Render::cbShadowTransformState v69; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 v70; // [rsp+180h] [rbp+80h]
  UFG::qMatrix44 m; // [rsp+1C0h] [rbp+C0h]
  Render::ViewSettings v72; // [rsp+200h] [rbp+100h]
  __int64 v73; // [rsp+290h] [rbp+190h]
  Render::View v74; // [rsp+2A0h] [rbp+1A0h]
  __int128 v75; // [rsp+430h] [rbp+330h]
  __int128 v76; // [rsp+440h] [rbp+340h]
  __int128 v77; // [rsp+450h] [rbp+350h]
  __int128 v78; // [rsp+460h] [rbp+360h]
  __int128 v79; // [rsp+530h] [rbp+430h]
  __int128 v80; // [rsp+540h] [rbp+440h]
  __int128 v81; // [rsp+550h] [rbp+450h]
  __int128 v82; // [rsp+560h] [rbp+460h]
  RenderQueueLayer v83; // [rsp+630h] [rbp+530h]
  LayerSubmitContext ptr; // [rsp+710h] [rbp+610h]
  Render::Poly v85; // [rsp+13F0h] [rbp+12F0h]
  Illusion::StateArgs *v86; // [rsp+13F8h] [rbp+12F8h]

  v73 = -2i64;
  v5 = shadowIdx;
  v6 = serialization_list;
  v7 = render_context;
  v8 = this;
  RenderQueueLayer::RenderQueueLayer(&v83);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v83.mSerializationList = v6;
  ptr.mRenderQueueProvider = &v83;
  ptr.mQueueMode = 0;
  Render::View::View(&v74, &v7->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  if ( v8->mRenderingNISCharacterShadows )
    v9 = v7->mFullSizeScratchTargetA;
  else
    v9 = v7->mDynamicRangeTarget;
  Render::View::BeginTarget(&v74, v9, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
  if ( bFirst )
  {
    colour.r = 1.0;
    colour.g = 1.0;
    colour.b = 1.0;
    colour.a = 1.0;
    Render::View::Clear(&v74, &colour, 5u, 1.0, 0);
  }
  v10 = v7->mEnvState;
  v11 = Render::View::GetStateValues(&v74);
  v11->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v11->mParamValues[55] = v10;
  v12 = v74.mSettings;
  v13 = &v74.mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v14 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v14;
    arg.mStateParamIndex = v14;
  }
  arg.mWorldView = &v12->mWorldView;
  arg.mProjection = v13;
  arg.mCached_Remote.m_Stream = 0i64;
  v15 = Render::View::GetStateArgs(&v74);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v15, &arg);
  v16 = 0;
  do
  {
    v17 = (unsigned __int64)(unsigned int)v16 << 6;
    v18 = (__int128)v8->mShadowViewSettings[v16].mWorldView.v1;
    v19 = (__int128)v8->mShadowViewSettings[v16].mWorldView.v2;
    v20 = (__int128)v8->mShadowViewSettings[v16].mWorldView.v3;
    *(__int128 *)((char *)&v75 + v17) = (__int128)v8->mShadowViewSettings[v16].mWorldView.v0;
    *(__int128 *)((char *)&v76 + v17) = v18;
    *(__int128 *)((char *)&v77 + v17) = v19;
    *(__int128 *)((char *)&v78 + v17) = v20;
    v21 = (__int128)v8->mShadowViewSettings[v16].mProjection.v1;
    v22 = (__int128)v8->mShadowViewSettings[v16].mProjection.v2;
    v23 = (__int128)v8->mShadowViewSettings[v16].mProjection.v3;
    *(__int128 *)((char *)&v79 + v17) = (__int128)v8->mShadowViewSettings[v16].mProjection.v0;
    *(__int128 *)((char *)&v80 + v17) = v21;
    *(__int128 *)((char *)&v81 + v17) = v22;
    *(__int128 *)((char *)&v82 + v17) = v23;
    ++v16;
  }
  while ( (unsigned int)v16 < 4 );
  v69.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v69.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v69.mCallback = 0i64;
  v69.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v69.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v24;
    v69.mStateParamIndex = v24;
  }
  v69.mViewWorld = &v74.mViewWorld;
  v69.mWorldView = (UFG::qMatrix44 *)&v75;
  v69.mProjection = (UFG::qMatrix44 *)&v79;
  v69.mCutplanes = v8->mCutplanes;
  v69.mBiases = v8->mBiases;
  v69.mBlurWidths = v8->mShadowFilterWidth;
  v69.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v15, &v69);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v85);
  v25 = v8->mShadowViewSettings[v5].mWorldView.v0.y;
  v26 = v8->mShadowViewSettings[v5].mWorldView.v0.z;
  v27 = v8->mShadowViewSettings[v5].mWorldView.v0.w;
  m.v0.x = v8->mShadowViewSettings[v5].mWorldView.v0.x;
  m.v0.y = v25;
  m.v0.z = v26;
  m.v0.w = v27;
  v28 = v8->mShadowViewSettings[v5].mWorldView.v1.y;
  v29 = v8->mShadowViewSettings[v5].mWorldView.v1.z;
  v30 = v8->mShadowViewSettings[v5].mWorldView.v1.w;
  m.v1.x = v8->mShadowViewSettings[v5].mWorldView.v1.x;
  m.v1.y = v28;
  m.v1.z = v29;
  m.v1.w = v30;
  v31 = v8->mShadowViewSettings[v5].mWorldView.v2.y;
  v32 = v8->mShadowViewSettings[v5].mWorldView.v2.z;
  v33 = v8->mShadowViewSettings[v5].mWorldView.v2.w;
  m.v2.x = v8->mShadowViewSettings[v5].mWorldView.v2.x;
  m.v2.y = v31;
  m.v2.z = v32;
  m.v2.w = v33;
  v34 = v8->mShadowViewSettings[v5].mWorldView.v3.y;
  v35 = v8->mShadowViewSettings[v5].mWorldView.v3.z;
  v36 = v8->mShadowViewSettings[v5].mWorldView.v3.w;
  m.v3.x = v8->mShadowViewSettings[v5].mWorldView.v3.x;
  m.v3.y = v34;
  m.v3.z = v35;
  m.v3.w = v36;
  UFG::qInverseAffine(&d, &m);
  v37 = (__m128)(unsigned int)FLOAT_1_0;
  v37.m128_f32[0] = 1.0 / v8->mShadowViewSettings[v5].mProjection.v0.x;
  d.v0 = (UFG::qVector4)_mm_mul_ps((__m128)d.v0, _mm_shuffle_ps(v37, v37, 0));
  v38 = (__m128)(unsigned int)FLOAT_1_0;
  v38.m128_f32[0] = 1.0 / v8->mShadowViewSettings[v5].mProjection.v1.y;
  d.v1 = (UFG::qVector4)_mm_mul_ps((__m128)d.v1, _mm_shuffle_ps(v38, v38, 0));
  v39 = v8->mShadowOffset * 0.5;
  d.v2.x = d.v2.x * v39;
  d.v2.y = d.v2.y * v39;
  d.v2.z = d.v2.z * v39;
  d.v2.w = d.v2.w * v39;
  d.v3.x = d.v3.x - (float)(d.v2.x * 2.0);
  d.v3.y = d.v3.y - (float)(d.v2.y * 2.0);
  d.v3.z = d.v3.z - (float)(d.v2.z * 2.0);
  d.v3.w = d.v3.w - (float)(d.v2.w * 2.0);
  if ( (signed int)v5 > 0 )
  {
    Render::ViewSettings::ViewSettings(&v72, &v8->mShadowViewSettings[(signed int)v5 - 1]);
    v70.v0 = v72.mWorldView.v0;
    v70.v1 = v72.mWorldView.v1;
    v70.v2 = v72.mWorldView.v2;
    v70.v3 = v72.mWorldView.v3;
    UFG::qInverseAffine(&local_world, &v70);
    v40 = (__m128)LODWORD(s_fCubeScalerConst);
    v41 = (__m128)LODWORD(s_fCubeScalerConst);
    v41.m128_f32[0] = s_fCubeScalerConst / v72.mProjection.v0.x;
    local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, _mm_shuffle_ps(v41, v41, 0));
    v40.m128_f32[0] = s_fCubeScalerConst / v72.mProjection.v1.y;
    local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, _mm_shuffle_ps(v40, v40, 0));
    v42 = v8->mShadowOffset * 0.5;
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
  v44 = v7->mRenderSettingsForFrame.mShadowFilter;
  v45 = v44 == 0;
  if ( v7->mRenderSettingsForFrame.mShadowRes == 2 && v44 == 1 )
  {
    v43 = 0;
    if ( v7->mRenderSettingsForFrame.mFeatureLevel >= 2 )
      v43 = 1;
  }
  if ( (_DWORD)v5 )
  {
    if ( (_DWORD)v5 == 1 )
    {
      v50 = v8->mMatStencilWriteShadowFar;
      Render::View::Draw(&v74, &gDeferredCube, &d, 0);
      UFG::RenderStageShadow::UpdateCollectorMaterial(v8, v7->mShadowCollectorMaterial, 1u, v45, v43);
      v51 = v7->mShadowCollectorMaterial;
      if ( *(_DWORD *)&v51[2].mDebugName[28] != 1342221360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v51[2].mDebugName[4],
          *((_DWORD *)&v51[2].0 + 22),
          0x5000AC30u);
        v52 = (_WORD *)v51->mMaterialUser.mOffset;
        if ( v52 )
          v52 = (_WORD *)((char *)v52 + (_QWORD)v51 + 120);
        *v52 |= 0x20u;
      }
    }
    else
    {
      if ( (_DWORD)v5 != 2 )
        goto LABEL_37;
      v53 = v8->mMatStencilWriteShadowFar;
      Render::View::Draw(&v74, &gDeferredCube, &d, 0);
      UFG::RenderStageShadow::UpdateCollectorMaterial(v8, v7->mShadowCollectorMaterial, 2u, v45, v43);
      v54 = v7->mShadowCollectorMaterial;
      if ( *(_DWORD *)&v54[2].mDebugName[28] != 1342221360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v54[2].mDebugName[4],
          *((_DWORD *)&v54[2].0 + 22),
          0x5000AC30u);
        v55 = (_WORD *)v54->mMaterialUser.mOffset;
        if ( v55 )
          v55 = (_WORD *)((char *)v55 + (_QWORD)v54 + 120);
        *v55 |= 0x20u;
      }
    }
    v49 = &local_world;
  }
  else
  {
    dest_mip_level = v8->mMatStencilWriteShadowNear;
    Render::View::Draw(&v74, &gDeferredCube, &d, 0);
    UFG::RenderStageShadow::UpdateCollectorMaterial(v8, v7->mShadowCollectorMaterial, 0, v45, v43);
    v47 = v7->mShadowCollectorMaterial;
    if ( *(_DWORD *)&v47[2].mDebugName[28] != 222253912 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v47[2].mDebugName[4], *((_DWORD *)&v47[2].0 + 22), 0xD3F5358u);
      v48 = (_WORD *)v47->mMaterialUser.mOffset;
      if ( v48 )
        v48 = (_WORD *)((char *)v48 + (_QWORD)v47 + 120);
      *v48 |= 0x20u;
    }
    v49 = &d;
  }
  v56 = v7->mShadowCollectorMaterial;
  Render::View::Draw(&v74, &gDeferredCube, v49, 0);
  *(_QWORD *)&colour.r = 0i64;
  *(_QWORD *)&colour.b = 0i64;
  Render::View::Clear(&v74, &colour, 4u, 1.0, 0);
LABEL_37:
  v57 = v69.mPrev;
  v58 = v69.mNext;
  v69.mPrev->mNext = v69.mNext;
  v58->mPrev = v57;
  v69.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v69.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v69.mIsSet = 0;
  if ( (Illusion::StateArgs *)v15->mStateArgsCreateMask.mFlags[2 * (v69.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v15 + 16 * (v69.mStateParamIndex + 3i64)) )
    v15->mStateArgsCreateMask.mFlags[(unsigned int)v69.mStateParamIndex >> 6] &= ~(1i64 << (v69.mStateParamIndex & 0x3F));
  v59 = arg.mPrev;
  v60 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v60->mPrev = v59;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v15->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v15 + 16 * (arg.mStateParamIndex + 3i64)) )
    v15->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v74);
  v61 = v69.mPrev;
  v62 = v69.mNext;
  v69.mPrev->mNext = v69.mNext;
  v62->mPrev = v61;
  v69.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v69.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v69;
  v63 = arg.mPrev;
  v64 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v64->mPrev = v63;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v86 = &ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v83);
}

// File Line: 979
// RVA: 0x3AA80
void __fastcall UFG::RenderStageShadow::RenderCloudShadowsIntoCollector(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rsi
  UFG::RenderStageShadow *v5; // rdi
  Illusion::Target *v6; // rdx
  CB_EnvironmentSettings *v7; // rbx
  Illusion::StateValues *v8; // rax
  Render::ViewSettings *v9; // rbx
  UFG::qMatrix44 *v10; // r15
  unsigned __int16 v11; // ax
  Illusion::StateArgs *v12; // r15
  UFG::TimeOfDayManager *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm7_4
  int v16; // xmm3_4
  int v17; // xmm4_4
  int v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm8_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  float v26; // xmm14_4
  float v27; // xmm15_4
  unsigned int v28; // eax
  Render::VolumetricEffect **v29; // r13
  __int64 v30; // rsi
  Render::VolumetricEffect *v31; // rbx
  float v32; // xmm10_4
  UFG::qVector4 v33; // xmm2
  UFG::qVector4 v34; // xmm1
  UFG::qVector4 v35; // xmm0
  float v36; // xmm9_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm3_4
  float v40; // xmm8_4
  float v41; // xmm2_4
  float v42; // xmm7_4
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm9_4
  float v46; // xmm9_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm5_4
  signed int v53; // er14
  char v54; // si
  signed __int64 v55; // rax
  float v56; // xmm0_4
  __int128 v57; // xmm2
  __int128 v58; // xmm1
  __int128 v59; // xmm0
  __int128 v60; // xmm2
  __int128 v61; // xmm1
  __int128 v62; // xmm0
  unsigned __int16 v63; // ax
  Illusion::Material *v64; // rbx
  _WORD *v65; // rax
  Illusion::Material *dest_mip_level; // ST20_8
  Illusion::Material *v67; // rbx
  __int64 v68; // rax
  _WORD *v69; // rax
  Illusion::Primitive *v70; // rbx
  float v71; // xmm9_4
  float v72; // xmm8_4
  float v73; // xmm7_4
  float v74; // xmm6_4
  UFG::qVector3 *v75; // rsi
  Illusion::Material *v76; // ST20_8
  Illusion::Material *v77; // rsi
  __int64 v78; // rax
  _WORD *v79; // rax
  Illusion::Material *v80; // ST20_8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v81; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v82; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v83; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v84; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v85; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v86; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v87; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v88; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-B0h]
  float v90; // [rsp+60h] [rbp-A0h]
  float v91; // [rsp+64h] [rbp-9Ch]
  float v92; // [rsp+68h] [rbp-98h]
  float v93; // [rsp+6Ch] [rbp-94h]
  float distance_from_near_plane; // [rsp+70h] [rbp-90h]
  float v95; // [rsp+74h] [rbp-8Ch]
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-88h]
  UFG::qMatrix44 local_world; // [rsp+B0h] [rbp-50h]
  __int64 v98; // [rsp+F0h] [rbp-10h]
  Render::cbShadowTransformState v99; // [rsp+100h] [rbp+0h]
  UFG::qVector3 pos; // [rsp+160h] [rbp+60h]
  UFG::qVector3 ray_pos; // [rsp+16Ch] [rbp+6Ch]
  float v102; // [rsp+178h] [rbp+78h]
  float v103; // [rsp+17Ch] [rbp+7Ch]
  float v104; // [rsp+180h] [rbp+80h]
  UFG::qVector3 ray_dir; // [rsp+188h] [rbp+88h]
  UFG::qVector3 scale; // [rsp+194h] [rbp+94h]
  UFG::qColour v107; // [rsp+1A0h] [rbp+A0h]
  float v108; // [rsp+1B0h] [rbp+B0h]
  float v109; // [rsp+1B4h] [rbp+B4h]
  float v110; // [rsp+1B8h] [rbp+B8h]
  float v111; // [rsp+1BCh] [rbp+BCh]
  __int64 v112; // [rsp+1C0h] [rbp+C0h]
  __int64 v113; // [rsp+1C8h] [rbp+C8h]
  UFG::qColour v114; // [rsp+1D0h] [rbp+D0h]
  UFG::qVector4 plane; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 v116; // [rsp+1F0h] [rbp+F0h]
  UFG::qMatrix44 v117; // [rsp+230h] [rbp+130h]
  UFG::qMatrix44 d; // [rsp+270h] [rbp+170h]
  __int64 v119; // [rsp+2B0h] [rbp+1B0h]
  UFG::qVector4 v120; // [rsp+2C0h] [rbp+1C0h]
  __int128 v121; // [rsp+2D0h] [rbp+1D0h]
  __int128 v122; // [rsp+2E0h] [rbp+1E0h]
  __int128 v123; // [rsp+2F0h] [rbp+1F0h]
  UFG::qVector4 v124; // [rsp+300h] [rbp+200h]
  __int128 v125; // [rsp+310h] [rbp+210h]
  __int128 v126; // [rsp+320h] [rbp+220h]
  __int128 v127; // [rsp+330h] [rbp+230h]
  UFG::qVector4 dir; // [rsp+340h] [rbp+240h]
  UFG::qMatrix44 dest; // [rsp+350h] [rbp+250h]
  UFG::qMatrix44 v130; // [rsp+390h] [rbp+290h]
  Render::View v131; // [rsp+3D0h] [rbp+2D0h]
  RenderQueueLayer v132; // [rsp+560h] [rbp+460h]
  ClipCube v133; // [rsp+640h] [rbp+540h]
  LayerSubmitContext ptr; // [rsp+880h] [rbp+780h]
  Render::VolumetricEffect *pBuffer; // [rsp+1500h] [rbp+1400h]
  unsigned int vertex_count; // [rsp+25E0h] [rbp+24E0h]
  float v137; // [rsp+25F8h] [rbp+24F8h]

  v119 = -2i64;
  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  if ( this->mEnableCloudShadows )
  {
    RenderQueueLayer::RenderQueueLayer(&v132);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v132.mSerializationList = v3;
    ptr.mRenderQueueProvider = &v132;
    ptr.mQueueMode = 0;
    Render::View::View(&v131, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    if ( v5->mRenderingNISCharacterShadows )
      v6 = v4->mFullSizeScratchTargetA;
    else
      v6 = v4->mDynamicRangeTarget;
    Render::View::BeginTarget(&v131, v6, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
    colour.r = 1.0;
    colour.g = 1.0;
    colour.b = 1.0;
    colour.a = 1.0;
    Render::View::Clear(&v131, &colour, 4u, 1.0, 0);
    v7 = v4->mEnvState;
    v8 = Render::View::GetStateValues(&v131);
    v8->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v8->mParamValues[55] = v7;
    v9 = v131.mSettings;
    v10 = &v131.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v11;
      arg.mStateParamIndex = v11;
    }
    arg.mWorldView = &v9->mWorldView;
    arg.mProjection = v10;
    arg.mCached_Remote.m_Stream = 0i64;
    v12 = Render::View::GetStateArgs(&v131);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v12, &arg);
    v13 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::GetSunDir(v13, &dir, 1, 0);
    UFG::qInverseAffine(&d, &v4->mMainViewSettings.mWorldView);
    v14 = v4->mMainViewSettings.mProjection.v2.z;
    if ( v14 == 0.0 || v14 == v4->mMainViewSettings.mProjection.v2.w )
      v15 = *(float *)&vertex_count;
    else
      v15 = v4->mMainViewSettings.mProjection.v3.z / v14;
    v137 = v15;
    v16 = LODWORD(d.v2.z) ^ _xmm[0];
    v17 = LODWORD(d.v2.y) ^ _xmm[0];
    v18 = LODWORD(d.v2.x) ^ _xmm[0];
    v19 = (float)((float)(*(float *)&v17 * *(float *)&v17) + (float)(*(float *)&v18 * *(float *)&v18))
        + (float)(*(float *)&v16 * *(float *)&v16);
    if ( v19 == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / fsqrt(v19);
    v93 = v20 * *(float *)&v16;
    v91 = v20 * *(float *)&v17;
    v90 = *(float *)&v18 * v20;
    v21 = v4->mMainViewSettings.mProjection.v0.x;
    if ( v21 == 0.0 )
      v22 = 0.0;
    else
      v22 = atan2f(1.0, v21) * 2.0;
    v23 = FLOAT_0_5;
    v24 = tanf(v22 * 0.5);
    v25 = Render::GetDisplayAspectRatio();
    v26 = d.v3.x;
    v27 = d.v3.y;
    v92 = d.v3.z;
    v95 = fsqrt(
            (float)((float)((float)(v24 * v15) * (float)(v24 * v15))
                  + (float)((float)((float)(v24 / v25) * v15) * (float)((float)(v24 / v25) * v15)))
          + (float)(v15 * v15));
    ClipCube::ClipCube(&v133);
    v28 = Render::VolumetricEffectManager::GetVolumetricEffects(&Render::gVolumetricEffectManager, &pBuffer, 0x200u);
    if ( v28 )
    {
      v29 = &pBuffer;
      v30 = v28;
      v98 = v28;
      while ( 1 )
      {
        v31 = *v29;
        v32 = (*v29)->fScale;
        if ( (float)((float)(v32 * v32) * v32) >= v5->mCloudShadowMinVolume )
          break;
LABEL_72:
        ++v29;
        v98 = --v30;
        if ( !v30 )
          goto LABEL_73;
      }
      v33 = v31->mTransform.v1;
      v34 = v31->mTransform.v2;
      v35 = v31->mTransform.v3;
      local_world.v0 = v31->mTransform.v0;
      local_world.v1 = v33;
      local_world.v2 = v34;
      local_world.v3 = v35;
      v36 = v5->mShadowOffset * v23;
      if ( v32 <= v36 )
        v37 = v5->mShadowOffset * v23;
      else
        v37 = v32;
      v38 = v31->mRotationMtx.v2.w;
      v39 = v31->mRotationMtx.v2.w * v37;
      v40 = v31->mRotationMtx.v2.z;
      v41 = v31->mRotationMtx.v2.z * v37;
      v42 = v31->mRotationMtx.v2.y;
      v43 = v31->mRotationMtx.v2.y * v37;
      v44 = v31->mRotationMtx.v2.x;
      local_world.v2.x = v31->mRotationMtx.v2.x * v37;
      local_world.v2.y = v43;
      local_world.v2.z = v41;
      local_world.v2.w = v39;
      v45 = v36 - v32;
      local_world.v3.x = local_world.v3.x + (float)(v44 * v45);
      local_world.v3.y = local_world.v3.y + (float)(v42 * v45);
      local_world.v3.z = local_world.v3.z + (float)(v40 * v45);
      local_world.v3.w = local_world.v3.w + (float)(v38 * v45);
      pos.x = v26;
      pos.y = v27;
      v46 = v92;
      pos.z = v92;
      ray_dir.x = v44;
      ray_dir.y = v42;
      ray_dir.z = v40;
      v47 = v31->mTransform.v3.y;
      v48 = v31->mTransform.v3.z;
      ray_pos.x = v31->mTransform.v3.x;
      ray_pos.y = v47;
      ray_pos.z = v48;
      if ( UFG::qDistanceRayPoint(&ray_pos, &ray_dir, &pos) > v5->mCloudShadowCullDist
        || (distance_from_near_plane = 0.0,
            !(unsigned int)Render::View::IsInView(&v131, &gDeferredCube, &local_world, &distance_from_near_plane)) )
      {
LABEL_71:
        v23 = FLOAT_0_5;
        goto LABEL_72;
      }
      UFG::qInverse(&v116, &local_world);
      v49 = (float)((float)((float)(v116.v1.x * v27) + (float)(v116.v0.x * v26)) + (float)(v116.v2.x * v46)) + v116.v3.x;
      v50 = (float)((float)((float)(v116.v1.y * v27) + (float)(v116.v0.y * v26)) + (float)(v116.v2.y * v46)) + v116.v3.y;
      v51 = (float)((float)((float)(v116.v1.z * v27) + (float)(v116.v0.z * v26)) + (float)(v116.v2.z * v46)) + v116.v3.z;
      v52 = (float)((float)((float)(v116.v1.w * v27) + (float)(v116.v0.w * v26)) + (float)(v116.v2.w * v46)) + v116.v3.w;
      if ( v52 < 0.0 )
        LODWORD(v52) ^= _xmm[0];
      if ( v51 < 0.0 )
        LODWORD(v51) ^= _xmm[0];
      if ( v50 < 0.0 )
        LODWORD(v50) ^= _xmm[0];
      if ( v49 < 0.0 )
        LODWORD(v49) ^= _xmm[0];
      v108 = v49;
      v109 = v50;
      v110 = v51;
      v111 = v52;
      v102 = v95 / v32;
      v103 = v95 / v32;
      v104 = v95 / v32;
      v53 = 1;
      v54 = 0;
      v55 = 0i64;
      while ( 1 )
      {
        v56 = *(float *)((char *)&v108 + v55);
        if ( v56 > 1.0 )
          break;
        v55 += 4i64;
        if ( v55 >= 12 )
          goto LABEL_40;
      }
      v54 = 0;
      if ( (float)(*(float *)((char *)&v102 + v55) + 1.0) > v56 )
        v54 = 1;
      v53 = 2;
LABEL_40:
      v57 = (__int128)v31->mTransformInv.v1;
      v58 = (__int128)v31->mTransformInv.v2;
      v59 = (__int128)v31->mTransformInv.v3;
      v120 = v31->mTransformInv.v0;
      v121 = v57;
      v122 = v58;
      v123 = v59;
      v60 = (__int128)v31->mRotationMtxInv.v1;
      v61 = (__int128)v31->mRotationMtxInv.v2;
      v62 = (__int128)v31->mRotationMtxInv.v3;
      v124 = v31->mRotationMtxInv.v0;
      v125 = v60;
      v126 = v61;
      v127 = v62;
      scale.x = 1.0;
      scale.y = -1.0;
      scale.z = 0.5;
      UFG::qScaleMatrix(&dest, &scale);
      dest.v3.z = 0.5;
      colour.r = 2.0;
      colour.g = -2.0;
      colour.b = 1.0;
      UFG::qScaleMatrix(&v130, (UFG::qVector3 *)&colour);
      v130.v3.x = -0.5;
      v130.v3.y = -0.5;
      v112 = 0i64;
      v113 = 0i64;
      v99.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v99.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v99.mCallback = 0i64;
      v99.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
      *(_WORD *)&v99.mFlags = 1;
      if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
      {
        v63 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
        Render::cbShadowTransformState::sStateParamIndex = v63;
        v99.mStateParamIndex = v63;
      }
      v99.mViewWorld = &v131.mViewWorld;
      v99.mWorldView = (UFG::qMatrix44 *)&v120;
      v99.mProjection = &dest;
      v99.mCutplanes = 0i64;
      v99.mBiases = (const float *)&v112;
      v99.mBlurWidths = 0i64;
      v99.mCached_Remote.m_Stream = 0i64;
      Illusion::StateArgs::Set<Render::cbShadowTransformState>(v12, &v99);
      v64 = v5->mMatCloudShadowVolume;
      if ( LODWORD(v64[3].mNode.mChild[0]) != Render::gCloudVolumeManager.mVolumeTextureUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v64[2].mNumParams,
          (unsigned int)v64[3].mNode.mChild[1],
          Render::gCloudVolumeManager.mVolumeTextureUID);
        v65 = (_WORD *)v64->mMaterialUser.mOffset;
        if ( v65 )
          v65 = (_WORD *)((char *)v65 + (_QWORD)v64 + 120);
        *v65 |= 0x20u;
      }
      if ( v53 == 1 )
      {
        *(_QWORD *)&v107.r = 0i64;
        *(_QWORD *)&v107.b = 0i64;
        Render::View::Clear(&v131, &v107, 4u, 1.0, 0);
        dest_mip_level = v5->mMatStencilWriteShadowNear;
        Render::View::Draw(&v131, &gDeferredCube, &local_world, 0);
        v67 = v5->mMatCloudShadowVolume;
        if ( *(_DWORD *)&v67[2].mDebugName[28] != 222253912 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v67[2].mDebugName[4],
            *((_DWORD *)&v67[2].0 + 22),
            0xD3F5358u);
          v68 = v67->mMaterialUser.mOffset;
          if ( v68 )
            v69 = (_WORD *)((char *)&v67->mMaterialUser + v68);
          else
            v69 = 0i64;
          *v69 |= 0x20u;
        }
LABEL_67:
        v80 = v5->mMatCloudShadowVolume;
        Render::View::Draw(&v131, &gDeferredCube, &local_world, 0);
        goto LABEL_68;
      }
      if ( v53 == 2 )
      {
        v70 = 0i64;
        if ( v54 )
        {
          v71 = v93;
          v72 = v91;
          v73 = v90;
          v74 = (float)((float)((float)((float)(v90 * 0.001) + (float)((float)(v90 * v137) + d.v3.x))
                              * COERCE_FLOAT(LODWORD(v90) ^ _xmm[0]))
                      + (float)((float)((float)(v91 * 0.001) + (float)((float)(v91 * v137) + d.v3.y))
                              * COERCE_FLOAT(LODWORD(v91) ^ _xmm[0])))
              + (float)((float)((float)(v93 * 0.001) + (float)((float)(v93 * v137) + d.v3.z))
                      * COERCE_FLOAT(LODWORD(v93) ^ _xmm[0]));
          UFG::qTranspose(&v117, &local_world);
          plane.x = (float)((float)((float)(v117.v1.x * v72) + (float)(v117.v0.x * v73)) + (float)(v117.v2.x * v71))
                  + (float)(v117.v3.x * v74);
          plane.y = (float)((float)((float)(v117.v1.y * v72) + (float)(v117.v0.y * v73)) + (float)(v117.v2.y * v71))
                  + (float)(v117.v3.y * v74);
          plane.z = (float)((float)((float)(v117.v1.z * v72) + (float)(v117.v0.z * v73)) + (float)(v117.v2.z * v71))
                  + (float)(v117.v3.z * v74);
          plane.w = (float)((float)((float)(v117.v1.w * v72) + (float)(v117.v0.w * v73)) + (float)(v117.v2.w * v71))
                  + (float)(v117.v3.w * v74);
          ClipCube::Reset(&v133);
          ClipCube::ClipToPlane(&v133, &plane);
          if ( ClipCube::GetClipCount(&v133) )
          {
            *(float *)&vertex_count = 0.0;
            v75 = ClipCube::GenerateCube(&v133, &vertex_count);
            if ( *(float *)&vertex_count != 0.0 )
            {
              v70 = Illusion::Primitive::Create("ClipCube");
              Illusion::Primitive::SetBuffers(
                v70,
                TRIANGLELIST,
                v75,
                vertex_count,
                (Illusion::VertexDecl *)v5->mCloudVolumePrimitiveVertexDecl.mData,
                0i64,
                0,
                1);
            }
          }
        }
        *(_QWORD *)&v114.r = 0i64;
        *(_QWORD *)&v114.b = 0i64;
        Render::View::Clear(&v131, &v114, 4u, 1.0, 0);
        if ( v70 )
        {
          Render::View::Draw(&v131, v70, v5->mMatStencilWriteShadowFar, &local_world);
        }
        else
        {
          v76 = v5->mMatStencilWriteShadowFar;
          Render::View::Draw(&v131, &gDeferredCube, &local_world, 0);
        }
        v77 = v5->mMatCloudShadowVolume;
        if ( *(_DWORD *)&v77[2].mDebugName[28] != -460843872 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v77[2].mDebugName[4],
            *((_DWORD *)&v77[2].0 + 22),
            0xE48814A0);
          v78 = v77->mMaterialUser.mOffset;
          if ( v78 )
            v79 = (_WORD *)((char *)&v77->mMaterialUser + v78);
          else
            v79 = 0i64;
          *v79 |= 0x20u;
        }
        if ( !v70 )
          goto LABEL_67;
        Render::View::Draw(&v131, v70, v5->mMatCloudShadowVolume, &local_world);
      }
LABEL_68:
      v81 = v99.mPrev;
      v82 = v99.mNext;
      v99.mPrev->mNext = v99.mNext;
      v82->mPrev = v81;
      v99.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v99.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v99.mIsSet = 0;
      if ( (Illusion::StateArgs *)v12->mStateArgsCreateMask.mFlags[2 * (v99.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v12 + 16 * (v99.mStateParamIndex + 3i64)) )
        v12->mStateArgsCreateMask.mFlags[(unsigned int)v99.mStateParamIndex >> 6] &= ~(1i64 << (v99.mStateParamIndex & 0x3F));
      v83 = v99.mPrev;
      v84 = v99.mNext;
      v99.mPrev->mNext = v99.mNext;
      v84->mPrev = v83;
      v99.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v99.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v99;
      v30 = v98;
      goto LABEL_71;
    }
LABEL_73:
    v85 = arg.mPrev;
    v86 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v86->mPrev = v85;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v12->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v12 + 16 * (arg.mStateParamIndex + 3i64)) )
      v12->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&v131);
    v87 = arg.mPrev;
    v88 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v88->mPrev = v87;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    *(_QWORD *)&vertex_count = (char *)&ptr + 1048;
    `eh vector destructor iterator'(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v132);
  }
}qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v132);
  }
}

// File Line: 1251
// RVA: 0x38400
void __fastcall UFG::RenderStageShadow::DownsampleShadows(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rbp
  UFG::RenderStageShadow *v5; // rsi
  _WORD *v6; // rbx
  unsigned int v7; // er8
  Illusion::Material *v8; // rdi
  __int64 v9; // rax
  _WORD *v10; // rax
  unsigned int v11; // er8
  Illusion::Material *v12; // rdi
  __int64 v13; // rax
  Render::View v14; // [rsp+60h] [rbp-F08h]
  RenderQueueLayer v15; // [rsp+1F0h] [rbp-D78h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C98h]
  Render::Poly poly; // [rsp+F70h] [rbp+8h]
  Illusion::StateArgs *v18; // [rsp+F78h] [rbp+10h]

  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  RenderQueueLayer::RenderQueueLayer(&v15);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v15.mSerializationList = v3;
  ptr.mRenderQueueProvider = &v15;
  v6 = 0i64;
  ptr.mQueueMode = 0;
  Render::View::View(&v14, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  Render::View::BeginTarget(&v14, v4->mHalfSizeShadowTarget, "HalfSizeShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v14, &UFG::qColour::Black, 6u, 1.0, 0);
  v7 = v4->mCascadeShadowTextureAliasDepth->mNode.mUID;
  v8 = v5->mMatDepthDownsampleShadow;
  if ( LODWORD(v8[1].mStateBlockMask.mFlags[0]) != v7 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[1].mDebugName[20], v8[1].mStateBlockMask.mFlags[1], v7);
    v9 = v8->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v8->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v14, &poly, v5->mMatDepthDownsampleShadow, 0i64);
  Render::View::EndTarget(&v14);
  Render::View::BeginTarget(&v14, v4->mQuarterSizeShadowTarget, "QuarterSizeShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v14, &UFG::qColour::Black, 6u, 1.0, 0);
  v11 = v4->mHalfSizeShadowTarget->mDepthTexture->mNode.mUID;
  v12 = v5->mMatDepthDownsampleShadow;
  if ( LODWORD(v12[1].mStateBlockMask.mFlags[0]) != v11 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[1].mDebugName[20], v12[1].mStateBlockMask.mFlags[1], v11);
    v13 = v12->mMaterialUser.mOffset;
    if ( v13 )
      v6 = (_WORD *)((char *)&v12->mMaterialUser + v13);
    *v6 |= 0x20u;
  }
  Render::View::Draw(&v14, &poly, v5->mMatDepthDownsampleShadow, 0i64);
  Render::View::EndTarget(&v14);
  v18 = &ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v15);
}

// File Line: 1302
// RVA: 0x3C3F0
UFG::ShadowRenderQueueSimResults *__fastcall UFG::RenderStageShadow::RenderSunShadowsSim(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, CullLayer *simple_drawable_cull_layer, CullLayer *composite_cull_layer)
{
  CullLayer *v4; // r14
  UFG::RenderContext *v5; // r13
  UFG::RenderStageShadow *v6; // r15
  unsigned int v7; // ebx
  char *v8; // rax
  unsigned int v9; // edi
  __int64 v10; // rax
  __int64 v11; // r12
  bool v12; // si
  unsigned int v13; // er8
  unsigned int v14; // ebx
  CullManager *v15; // rax
  Illusion::StateArgs *v16; // rsi
  UFG::qMatrix44 *v17; // rbx
  unsigned __int16 v18; // ax
  float v19; // xmm7_4
  float v20; // xmm6_4
  char *v21; // rbx
  Illusion::StateValues *v22; // rax
  CB_EnvironmentSettings *v23; // rbx
  Illusion::StateValues *v24; // rax
  __int64 v25; // rdx
  __int64 v26; // rcx
  __int64 v27; // rbx
  unsigned int v28; // esi
  __int64 v29; // r14
  __int64 v30; // r8
  __int64 v31; // rdx
  float v32; // xmm1_4
  int v33; // eax
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // rbx
  unsigned int v37; // esi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  unsigned int v42; // eax
  Illusion::RenderQueue **v43; // rsi
  int *v44; // r14
  __int64 v45; // r12
  __int64 v46; // r15
  char *v47; // rax
  char *v48; // rbx
  signed __int64 v49; // rcx
  CullManager *v50; // rax
  __int64 v51; // r14
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v52; // rsi
  Illusion::Target **v53; // rbx
  CullManager *v54; // rax
  bool v56; // [rsp+50h] [rbp-B0h]
  unsigned int v57; // [rsp+54h] [rbp-ACh]
  unsigned int v58; // [rsp+58h] [rbp-A8h]
  int v59; // [rsp+58h] [rbp-A8h]
  unsigned int v60; // [rsp+60h] [rbp-A0h]
  Illusion::StateArgs *v61; // [rsp+68h] [rbp-98h]
  Render::cbViewTransformState arg; // [rsp+70h] [rbp-90h]
  __int64 v63; // [rsp+C0h] [rbp-40h]
  __int64 v64; // [rsp+C8h] [rbp-38h]
  const char *v65; // [rsp+D0h] [rbp-30h]
  __int64 v66; // [rsp+D8h] [rbp-28h]
  int v67; // [rsp+E0h] [rbp-20h]
  __int64 v68; // [rsp+E8h] [rbp-18h]
  __int64 v69; // [rsp+F0h] [rbp-10h]
  const char *v70; // [rsp+F8h] [rbp-8h]
  __int64 v71; // [rsp+100h] [rbp+0h]
  int v72; // [rsp+108h] [rbp+8h]
  __int64 v73; // [rsp+110h] [rbp+10h]
  UFG::qResourceData *v74; // [rsp+118h] [rbp+18h]
  UFG::qResourceData *v75; // [rsp+120h] [rbp+20h]
  __int64 v76; // [rsp+128h] [rbp+28h]
  __int64 v77; // [rsp+130h] [rbp+30h]
  __int64 v78; // [rsp+138h] [rbp+38h]
  __int64 v79; // [rsp+140h] [rbp+40h]
  int v80; // [rsp+148h] [rbp+48h]
  __int64 v81; // [rsp+150h] [rbp+50h]
  AMD_HD3D *v82; // [rsp+158h] [rbp+58h]
  Illusion::RenderQueue *queues; // [rsp+160h] [rbp+60h]
  Render::View view; // [rsp+180h] [rbp+80h]
  RenderQueueLayer v85; // [rsp+310h] [rbp+210h]
  ShadowSubmitContext ptr; // [rsp+3F0h] [rbp+2F0h]
  UFG::RenderStageShadow *v87; // [rsp+10F0h] [rbp+FF0h]
  UFG::RenderContext *v88; // [rsp+10F8h] [rbp+FF8h]
  Illusion::StateArgs *v89; // [rsp+10F8h] [rbp+FF8h]
  CullLayer *v90; // [rsp+1100h] [rbp+1000h]
  CullLayer *composite_cull_layera; // [rsp+1108h] [rbp+1008h]

  composite_cull_layera = composite_cull_layer;
  v90 = simple_drawable_cull_layer;
  v88 = render_context;
  v87 = this;
  v81 = -2i64;
  v4 = simple_drawable_cull_layer;
  v5 = render_context;
  v6 = this;
  v7 = render_context->mNumCascades;
  v57 = v7;
  if ( !v7 )
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
  v63 = v11;
  *(_DWORD *)v11 = v7;
  v12 = v5->mRenderRain == 0;
  v56 = v5->mRenderRain == 0;
  if ( (UFG::RenderWorld::msIsNisPlaying
     || v6->mDebugEnableCharacterNISShadow
     || v5->mRenderSettingsForFrame.mShadowRes == 2 && UFG::RenderWorld::msStageEnvMap->mInteriorBlend > 0.000001)
    && !v5->mRenderRain
    && v5->mRenderFeatures.mLights
    && v5->mRenderFeatures.mWorld
    && v5->mRenderSun )
  {
    v6->mRenderingNISCharacterShadows = 1;
  }
  RenderQueueLayer::RenderQueueLayer(&v85);
  ShadowSubmitContext::ShadowSubmitContext(&ptr);
  v76 = 0i64;
  v77 = 0i64;
  v80 = 0;
  v79 = -1i64;
  v78 = -1i64;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v85;
  ptr.mRenderPass = 3;
  ptr.mShaderSelector = (Illusion::ShaderSelector *)&v76;
  v75 = v6->mAlphaStateNoColourWriteHandle.mData;
  v74 = v6->mRasterStateInvertCullingHandle.mData;
  ptr.mPerPhaseParams = (ShadowSubmitContext::PerPhaseParams *)&v74;
  if ( !v12 )
    goto LABEL_52;
  if ( v7 > 1 )
  {
    v13 = 0;
    v60 = 0;
    v58 = v7 - 2;
    if ( v7 != 2 )
    {
      do
      {
        v85.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 16i64 * v13 + 40);
        Render::View::View(&view, &v6->mShadowViewSettings[v13], (Illusion::SubmitContext *)&ptr.vfptr);
        v14 = view.mSettings->mCullIndex;
        v15 = CullManager::Instance();
        CullManager::EndView(v15, v14);
        Render::View::BeginTarget(&view, v5->mCascadeShadowTarget, "CascadeShadowTarget", 0, 0, 0i64, 1, 0, 1, 0);
        v16 = Render::View::GetStateArgs(&view);
        v61 = v16;
        v17 = &view.mSettings->mProjection;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
        {
          v18 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
          Render::cbViewTransformState::sStateParamIndex = v18;
          arg.mStateParamIndex = v18;
        }
        arg.mWorldViewProjection = &view.mWorldViewProjection;
        arg.mViewWorld = &view.mViewWorld;
        arg.mProjection = v17;
        arg.mScreenOffset = &Render::View::mScreenOffset;
        arg.mCached_Remote.m_Stream = 0i64;
        v19 = UFG::Metrics::msInstance.mSimTimeDelta;
        v20 = UFG::Metrics::msInstance.mSimTime_Temp;
        v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
        *(float *)v21 = v20;
        *((float *)v21 + 1) = v19;
        v22 = Render::View::GetStateValues(&view);
        v22->mSetValueMask.mFlags[0] |= 0x2000ui64;
        v22->mParamValues[13] = v21;
        v23 = v5->mEnvState;
        v24 = Render::View::GetStateValues(&view);
        v24->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
        v24->mParamValues[55] = v23;
        Illusion::StateArgs::Set<Render::cbViewTransformState>(v16, &arg);
        if ( composite_cull_layera )
        {
          v25 = view.mSettings->mCullIndex;
          if ( (signed int)v25 >= 0 && (signed int)v25 <= 16 && composite_cull_layera->mDrawEnabled )
            v26 = (__int64)composite_cull_layera->mCullResultBuckets[v25].mHead;
          else
            v26 = 0i64;
          v64 = 0i64;
          v65 = "CullResultBucketIterator";
          v27 = v26;
          v66 = v26;
          v67 = 0;
          v28 = 0;
          v68 = 0i64;
          if ( v26 )
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
                  if ( (signed int)v31 > 16 || (signed int)v31 < 0 || (unsigned __int8)(*(_BYTE *)(v31 + v30) - 4) > 1u )
                  {
                    if ( (signed int)v31 >= 6 )
                      v32 = *(float *)&FLOAT_1_0;
                    else
                      v32 = *(float *)(v30 + 4 * v31 + 40);
                    v33 = UFG::CompositeDrawableComponent::GetLOD(
                            *(UFG::CompositeDrawableComponent **)(v27 + 8i64 * v28 + 24),
                            v32);
                    UFG::CompositeDrawableComponent::Draw((UFG::CompositeDrawableComponent *)v29, &view, v33);
                  }
                }
              }
              LODWORD(v68) = ++v28;
              if ( v28 == *(_DWORD *)(v27 + 8) )
              {
                v27 = *(_QWORD *)v27;
                v66 = v27;
                v28 = 0;
                LODWORD(v68) = 0;
              }
            }
            while ( v27 );
            HIDWORD(v68) = 0;
            v6 = v87;
            v4 = v90;
          }
          else
          {
            v6 = v87;
          }
        }
        if ( v4 )
        {
          v34 = view.mSettings->mCullIndex;
          if ( (signed int)v34 >= 0 && (signed int)v34 <= 16 && v4->mDrawEnabled )
            v35 = (__int64)v4->mCullResultBuckets[v34].mHead;
          else
            v35 = 0i64;
          v69 = 0i64;
          v70 = "CullResultBucketIterator";
          v36 = v35;
          v71 = v35;
          v72 = 0;
          v37 = 0;
          v73 = 0i64;
          if ( v35 )
          {
            do
            {
              Render::SimpleDrawableComponent::Draw(
                *(Render::SimpleDrawableComponent **)(v36 + 8i64 * v37++ + 24),
                &view);
              LODWORD(v73) = v37;
              if ( v37 == *(_DWORD *)(v36 + 8) )
              {
                v36 = *(_QWORD *)v36;
                v71 = v36;
                v37 = 0;
                LODWORD(v73) = 0;
              }
            }
            while ( v36 );
            HIDWORD(v73) = 0;
          }
          v4 = v90;
        }
        v38 = arg.mPrev;
        v39 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v39->mPrev = v38;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v61->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v61 + 16 * (arg.mStateParamIndex + 3i64)) )
          v61->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        RenderQueueLayer::SerializeRenderQueues(&v85);
        v40 = arg.mPrev;
        v41 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v41->mPrev = v40;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        v13 = v60 + 1;
        v60 = v13;
      }
      while ( v13 < v58 );
      v7 = v57;
    }
LABEL_52:
    if ( v7 > 1 && UFG::TimeOfDayManager::GetInstance()->m_WeatherState <= 1.0 )
    {
      v42 = v7 - 2;
      v59 = v7 - 2;
      if ( v7 != 2 )
      {
        v43 = &queues;
        v44 = &v6->mShadowViewSettings[0].mCullIndex;
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
            v49 = (signed __int64)(v47 + 16);
            v82 = (AMD_HD3D *)v49;
            *(_QWORD *)v49 = v49;
            *(_QWORD *)(v49 + 8) = v49;
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
          *v43 = (Illusion::RenderQueue *)v48;
          if ( !v56 )
          {
            v50 = CullManager::Instance();
            CullManager::EndView(v50, (unsigned int)*v44);
          }
          *(Illusion::RenderQueue **)((char *)v43 + v45 + 120) = *v43;
          ++v43;
          v44 += 36;
          --v46;
        }
        while ( v46 );
        v5 = v88;
        v42 = v59;
        v6 = v87;
        v11 = v63;
        v7 = v57;
      }
      FastShadowDraw_Dynamic(v6->mShadowViewSettings, v5->mMainViewSettings.mCullIndex, &queues, v42);
    }
  }
  v51 = v7 - 1;
  if ( v7 != 1 )
  {
    v52 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 152);
    v53 = (Illusion::Target **)(v11 + 8);
    do
    {
      *v53 = v5->mCascadeShadowTarget;
      if ( v5->mRenderSun && v5->mRenderFeatures.mLights && v5->mRenderFeatures.mWorld )
      {
        if ( v9 == v57 - 2 )
          UFG::RenderStageShadow::DownsampleShadows(
            v6,
            v5,
            (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v11 + 104));
        UFG::RenderStageShadow::RenderShadowCollector(v6, v5, v52, v9, v9 == 0);
      }
      ++v9;
      ++v53;
      ++v52;
    }
    while ( v9 < (unsigned int)v51 );
    v7 = v57;
  }
  v54 = CullManager::Instance();
  CullManager::EndView(v54, (unsigned int)v6->mShadowViewSettings[v7 - 1].mCullIndex);
  *(_QWORD *)(v11 + 8 * v51 + 8) = v5->mHeightmapTarget;
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
      composite_cull_layera);
  v89 = &ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v85);
  return (UFG::ShadowRenderQueueSimResults *)v11;
}

// File Line: 1478
// RVA: 0x38760
void __fastcall UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderStageShadow *this, UFG::RenderStageShadow::LinearCascadeViews *views)
{
  __int64 v2; // r10
  unsigned __int64 v3; // rax
  Render::ViewSettings *v4; // r9
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  signed __int64 v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1

  v2 = 0i64;
  do
  {
    v3 = (unsigned __int64)(unsigned int)v2 << 6;
    v4 = &this->mShadowViewSettings[(signed int)v2];
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
char __fastcall UFG::RenderStageShadow::StateModifier_CharacterShadowCollector(Illusion::StateValues *state_values, void *override_params_Remote)
{
  Illusion::StateValues *v2; // r9
  UFG::qResourceData *v3; // r8
  UFG::qResourceData *v4; // r8
  void *v5; // r8
  void *v6; // rcx
  UFG::qResourceData *v7; // rcx
  void *v8; // rcx
  void *v9; // rax
  UFG::qResourceData *v10; // rcx
  void *v11; // rax
  char result; // al
  UFG::qResourceData *v13; // rcx

  v2 = state_values;
  v3 = UFG::RenderWorld::msStageShadow->mRasterStateCharacterShadowCollectorHandle.mData;
  state_values->mSetValueMask.mFlags[0] |= 0x400ui64;
  state_values->mParamValues[10] = v3;
  v4 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorAlphaStateHandle.mData;
  state_values->mSetValueMask.mFlags[0] |= 0x200ui64;
  state_values->mParamValues[9] = v4;
  v5 = *(void **)(*((_QWORD *)override_params_Remote + 22) + 24i64);
  state_values->mSetValueMask.mFlags[0] |= 0x800000ui64;
  state_values->mParamValues[23] = v5;
  v6 = *(void **)(*((_QWORD *)override_params_Remote + 1) + 72i64);
  v2->mSetValueMask.mFlags[0] |= 0x800000000000ui64;
  v2->mParamValues[47] = v6;
  v7 = UFG::RenderWorld::msStageShadow->mNoiseTextureHandle.mData;
  v2->mSetValueMask.mFlags[0] |= 0x40000000000ui64;
  v2->mParamValues[42] = v7;
  v8 = *(void **)(*((_QWORD *)override_params_Remote + 19) + 24i64);
  v2->mSetValueMask.mFlags[0] |= 0x2000000000000ui64;
  v2->mParamValues[49] = v8;
  v9 = (void *)*((_QWORD *)override_params_Remote + 73);
  v2->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v2->mParamValues[61] = v9;
  if ( *(_QWORD *)((char *)override_params_Remote + 332) != 4294967298i64
    || *((_DWORD *)override_params_Remote + 89) < 2 )
  {
    v13 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorShaderHandle.mData;
    v2->mSetValueMask.mFlags[0] |= 2ui64;
    result = 1;
    v2->mParamValues[1] = v13;
  }
  else
  {
    v10 = UFG::RenderWorld::msStageShadow->mCharacterShadowCollectorHighShaderHandle.mData;
    v2->mSetValueMask.mFlags[0] |= 2ui64;
    v2->mParamValues[1] = v10;
    v11 = (void *)*((_QWORD *)override_params_Remote + 74);
    v2->mSetValueMask.mFlags[0] |= 0x4000000000000000ui64;
    v2->mParamValues[62] = v11;
    result = 1;
  }
  return result;
}

// File Line: 1531
// RVA: 0x387F0
Illusion::RenderQueue *__fastcall UFG::CharacterCollectorSubmitContext::OnPreSubmit(UFG::CharacterCollectorSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::CharacterCollectorSubmitContext *v3; // rbx
  UFG::qMemoryStream<Illusion::Shader,1160> *v4; // rdi
  UFG::BitFlags128 *v5; // rsi

  v3 = this;
  v4 = shader_stream;
  v5 = already_called_funcs_mask;
  if ( !UFG::RenderStageShadow::StateModifier_CharacterShadowCollector(&this->mStateValues, this->mRenderContext) )
    return 0i64;
  Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v3->vfptr, v4);
  return LayerSubmitContext::OnPreSubmit((LayerSubmitContext *)&v3->vfptr, v4, v5);
}

// File Line: 1546
// RVA: 0x3A720
void __fastcall UFG::RenderStageShadow::RenderCharacterShadowsIntoCollector(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::CompositeDrawableComponent *component, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // rbx
  UFG::CompositeDrawableComponent *v5; // r14
  UFG::RenderContext *v6; // rdi
  UFG::RenderStageShadow *v7; // rsi
  CB_EnvironmentSettings *v8; // rbx
  Illusion::StateValues *v9; // rax
  Render::ViewSettings *v10; // rbx
  UFG::qMatrix44 *v11; // rdi
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // ax
  Illusion::StateArgs *v14; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  Render::cbShadowTransformState v25; // [rsp+90h] [rbp-70h]
  __int64 v26; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h]
  RenderQueueLayer v28; // [rsp+290h] [rbp+190h]
  LayerSubmitContext ptr; // [rsp+370h] [rbp+270h]
  UFG::RenderContext *v30; // [rsp+FF0h] [rbp+EF0h]
  Render::Poly v31; // [rsp+1030h] [rbp+F30h]
  Illusion::StateArgs *v32; // [rsp+1038h] [rbp+F38h]

  v26 = -2i64;
  v4 = serialization_list;
  v5 = component;
  v6 = render_context;
  v7 = this;
  RenderQueueLayer::RenderQueueLayer(&v28);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::CharacterCollectorSubmitContext::`vftable';
  v30 = v6;
  v28.mSerializationList = v4;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v28;
  Render::View::View(&view, &v6->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  Render::View::BeginTarget(&view, v6->mDynamicRangeTarget, "Collector", 0, 0, 0i64, 0, 0, 0, 0);
  v8 = v6->mEnvState;
  v9 = Render::View::GetStateValues(&view);
  v9->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v9->mParamValues[55] = v8;
  v10 = view.mSettings;
  v11 = &view.mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v12 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v12;
    arg.mStateParamIndex = v12;
  }
  arg.mWorldView = &v10->mWorldView;
  arg.mProjection = v11;
  arg.mCached_Remote.m_Stream = 0i64;
  v25.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mCallback = 0i64;
  v25.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v25.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v13;
    v25.mStateParamIndex = v13;
  }
  v25.mViewWorld = &view.mViewWorld;
  v25.mWorldView = &v7->mCSWorldShadow;
  v25.mProjection = &v7->mCSShadowProj;
  v25.mCutplanes = 0i64;
  _mm_store_si128((__m128i *)&v25.mBiases, (__m128i)0i64);
  v25.mCached_Remote.m_Stream = 0i64;
  v14 = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v14, &arg);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v14, &v25);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v31);
  UFG::CompositeDrawableComponent::Draw(v5, &view);
  v15 = v25.mPrev;
  v16 = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  v16->mPrev = v15;
  v25.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mIsSet = 0;
  if ( (Illusion::StateArgs *)v14->mStateArgsCreateMask.mFlags[2 * (v25.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v14 + 16 * (v25.mStateParamIndex + 3i64)) )
  {
    v17 = &v14->mStateArgsCreateMask.mFlags[(unsigned int)v25.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v25.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v14->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v14 + 16 * (arg.mStateParamIndex + 3i64)) )
    v14->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v20 = v25.mPrev;
  v21 = v25.mNext;
  v25.mPrev->mNext = v25.mNext;
  v21->mPrev = v20;
  v25.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v25.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v25;
  v22 = arg.mPrev;
  v23 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v23->mPrev = v22;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v32 = &ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v28);
}

// File Line: 1643
// RVA: 0x390A0
void __fastcall UFG::RenderStageShadow::RenderCharacterShadows(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, CullLayer *composite_cull_layer)
{
  CullLayer *v4; // rdi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v5; // rbx
  UFG::RenderContext *v6; // r13
  UFG::RenderStageShadow *v7; // rsi
  Illusion::Material *v8; // rbx
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  signed int v13; // eax
  float v14; // xmm7_4
  UFG::TimeOfDayManager *v15; // rax
  float v16; // xmm8_4
  float v17; // xmm12_4
  float v18; // xmm9_4
  float v19; // xmm10_4
  float v20; // xmm11_4
  float v21; // xmm0_4
  int v22; // xmm9_4
  int v23; // xmm10_4
  int v24; // xmm11_4
  __int64 v25; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v26; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v27; // r15
  unsigned int v28; // er12
  UFG::CompositeDrawableComponent *v29; // r14
  __int64 v30; // rax
  float v31; // xmm6_4
  int v32; // eax
  unsigned int v33; // edx
  int v34; // eax
  float v35; // xmm3_4
  float v36; // xmm12_4
  float v37; // xmm13_4
  float v38; // xmm8_4
  float v39; // xmm6_4
  float v40; // xmm7_4
  CullInfo *v41; // rbx
  UFG::qMatrix44 *v42; // r8
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
  signed __int64 v92; // r9
  float v93; // xmm7_4
  signed __int64 v94; // rcx
  __int64 v95; // rax
  float v96; // xmm4_4
  float v97; // xmm5_4
  float v98; // xmm6_4
  float v99; // xmm3_4
  float v100; // xmm2_4
  float v101; // xmm4_4
  float v102; // xmm5_4
  float v103; // xmm4_4
  float v104; // xmm5_4
  float v105; // xmm6_4
  float v106; // xmm0_4
  float v107; // xmm2_4
  float v108; // xmm1_4
  float v109; // xmm10_4
  float v110; // xmm9_4
  float v111; // xmm8_4
  float v112; // xmm7_4
  float *v113; // rax
  signed __int64 v114; // rcx
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
  signed int v126; // eax
  __m128 v127; // xmm4
  __m128 v128; // xmm5
  __m128 v129; // xmm4
  float v130; // xmm1_4
  signed int v131; // ecx
  float v132; // xmm2_4
  signed int v133; // ecx
  Illusion::StateArgs *v134; // rdi
  UFG::qMatrix44 *v135; // rbx
  unsigned __int16 v136; // ax
  float v137; // xmm7_4
  float v138; // xmm6_4
  char *v139; // rbx
  Illusion::StateValues *v140; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v141; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v142; // rax
  UFG::qVector4 v143; // xmm1
  UFG::qVector4 v144; // xmm2
  UFG::qVector4 v145; // xmm3
  UFG::qVector4 v146; // xmm1
  UFG::qVector4 v147; // xmm2
  UFG::qVector4 v148; // xmm3
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v149; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v150; // rax
  float v151; // [rsp+50h] [rbp-B0h]
  float v152; // [rsp+50h] [rbp-B0h]
  signed int v153; // [rsp+54h] [rbp-ACh]
  signed int v154; // [rsp+5Ch] [rbp-A4h]
  int v155; // [rsp+60h] [rbp-A0h]
  int v156; // [rsp+64h] [rbp-9Ch]
  int v157; // [rsp+68h] [rbp-98h]
  int v158; // [rsp+6Ch] [rbp-94h]
  int v159; // [rsp+70h] [rbp-90h]
  int v160; // [rsp+74h] [rbp-8Ch]
  int v161; // [rsp+78h] [rbp-88h]
  int v162; // [rsp+7Ch] [rbp-84h]
  int v163; // [rsp+80h] [rbp-80h]
  int v164; // [rsp+84h] [rbp-7Ch]
  int v165; // [rsp+88h] [rbp-78h]
  int v166; // [rsp+8Ch] [rbp-74h]
  int v167; // [rsp+90h] [rbp-70h]
  int v168; // [rsp+94h] [rbp-6Ch]
  int v169; // [rsp+98h] [rbp-68h]
  int v170; // [rsp+9Ch] [rbp-64h]
  int v171; // [rsp+A0h] [rbp-60h]
  int v172; // [rsp+A4h] [rbp-5Ch]
  int v173; // [rsp+A8h] [rbp-58h]
  int v174; // [rsp+ACh] [rbp-54h]
  int v175; // [rsp+B0h] [rbp-50h]
  int v176; // [rsp+B4h] [rbp-4Ch]
  int v177; // [rsp+B8h] [rbp-48h]
  int v178; // [rsp+BCh] [rbp-44h]
  int v179; // [rsp+C0h] [rbp-40h]
  int v180; // [rsp+C4h] [rbp-3Ch]
  float near_plane; // [rsp+C8h] [rbp-38h]
  float v182; // [rsp+CCh] [rbp-34h]
  int v183; // [rsp+D0h] [rbp-30h]
  float v184; // [rsp+D4h] [rbp-2Ch]
  float v185; // [rsp+D8h] [rbp-28h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h]
  UFG::qVector3 up; // [rsp+120h] [rbp+20h]
  UFG::qVector3 target; // [rsp+130h] [rbp+30h]
  Render::cbViewTransformState arg; // [rsp+140h] [rbp+40h]
  UFG::qVector3 eye; // [rsp+190h] [rbp+90h]
  UFG::qVector3 v191; // [rsp+19Ch] [rbp+9Ch]
  UFG::qVector4 v192; // [rsp+1A8h] [rbp+A8h]
  UFG::qVector4 v193; // [rsp+1B8h] [rbp+B8h]
  UFG::qVector4 v194; // [rsp+1C8h] [rbp+C8h]
  UFG::qVector4 v195; // [rsp+1D8h] [rbp+D8h]
  UFG::qMatrix44 dest; // [rsp+1F0h] [rbp+F0h]
  UFG::qVector4 v197; // [rsp+230h] [rbp+130h]
  UFG::qVector4 row_vec4; // [rsp+240h] [rbp+140h]
  UFG::qVector4 v199; // [rsp+250h] [rbp+150h]
  UFG::qVector4 v200; // [rsp+260h] [rbp+160h]
  int v201; // [rsp+270h] [rbp+170h]
  int v202; // [rsp+274h] [rbp+174h]
  int v203; // [rsp+278h] [rbp+178h]
  int v204; // [rsp+27Ch] [rbp+17Ch]
  int v205; // [rsp+280h] [rbp+180h]
  int v206; // [rsp+284h] [rbp+184h]
  int v207; // [rsp+288h] [rbp+188h]
  int v208; // [rsp+28Ch] [rbp+18Ch]
  UFG::qMatrix44 v209; // [rsp+290h] [rbp+190h]
  UFG::qVector4 dir; // [rsp+2D0h] [rbp+1D0h]
  UFG::qMatrix44 b; // [rsp+2E0h] [rbp+1E0h]
  UFG::qResourceData *v212; // [rsp+320h] [rbp+220h]
  UFG::qResourceData *v213; // [rsp+328h] [rbp+228h]
  __int64 v214; // [rsp+330h] [rbp+230h]
  Render::ViewSettings settings; // [rsp+340h] [rbp+240h]
  UFG::qMatrix44 matrixWS; // [rsp+3D0h] [rbp+2D0h]
  UFG::qVector4 v217; // [rsp+410h] [rbp+310h]
  UFG::qVector4 v218; // [rsp+420h] [rbp+320h]
  UFG::qVector4 v219; // [rsp+430h] [rbp+330h]
  UFG::qVector4 v220; // [rsp+440h] [rbp+340h]
  UFG::qVector4 v221; // [rsp+450h] [rbp+350h]
  UFG::qVector4 v222; // [rsp+460h] [rbp+360h]
  UFG::qVector4 v223; // [rsp+470h] [rbp+370h]
  UFG::qMatrix44 d; // [rsp+480h] [rbp+380h]
  UFG::qVector4 v225; // [rsp+4C0h] [rbp+3C0h]
  Render::View view; // [rsp+4D0h] [rbp+3D0h]
  RenderQueueLayer v227; // [rsp+660h] [rbp+560h]
  ShadowFrontFaceSubmitContext ptr; // [rsp+740h] [rbp+640h]
  LayerSubmitContext v229; // [rsp+13D0h] [rbp+12D0h]
  float v230; // [rsp+2140h] [rbp+2040h]
  float v231; // [rsp+2148h] [rbp+2048h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_lista; // [rsp+2150h] [rbp+2050h]
  float v233; // [rsp+2158h] [rbp+2058h]

  serialization_lista = serialization_list;
  v214 = -2i64;
  v4 = composite_cull_layer;
  v5 = serialization_list;
  v6 = render_context;
  v7 = this;
  RenderQueueLayer::RenderQueueLayer(&v227);
  LayerSubmitContext::LayerSubmitContext(&v229);
  v227.mSerializationList = v5;
  v229.mRenderQueueProvider = &v227;
  v229.mQueueMode = 0;
  Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&v229;
  v8 = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v9 = v8->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v8->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
    v8 = Render::gRenderUtilities.mMaterial;
  }
  if ( *(_DWORD *)&v8[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[2].mDebugName[4], *((_DWORD *)&v8[2].0 + 22), 0x62F81854u);
    v11 = v8->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&v8->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  Render::RenderUtilities::Blit(
    &Render::gRenderUtilities,
    v6->mFullSizeScratchTargetA,
    v6->mDynamicRangeTarget,
    0x3141335Cu,
    "BlitForCharacterNISShadows",
    0,
    1,
    0i64);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  v13 = 4;
  v153 = 4;
  if ( v6->mRenderSettingsForFrame.mShadowFilter == 1 )
  {
    if ( v6->mRenderSettingsForFrame.mShadowRes == 2 )
      v13 = 16;
    v153 = v13;
  }
  v154 = 0;
  *(_QWORD *)&up.x = 0i64;
  v14 = *(float *)&FLOAT_1_0;
  up.z = 1.0;
  v15 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetSunDir(v15, &dir, 1, 0);
  ShadowFrontFaceSubmitContext::ShadowFrontFaceSubmitContext(&ptr);
  v213 = v7->mAlphaStateNoColourWriteHandle.mData;
  v212 = v7->mRasterStateNormalHandle.mData;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v227;
  ptr.mPerPhaseParams = (ShadowFrontFaceSubmitContext::PerPhaseParams *)&v212;
  UFG::qInverseAffine(&d, &v6->mMainViewSettings.mWorldView);
  v230 = d.v3.x;
  v16 = d.v3.y;
  v231 = d.v3.y;
  v17 = d.v3.z;
  v233 = d.v3.z;
  UFG::qMatrix44::operator*(&v6->mMainViewSettings.mWorldView, &result, &v6->mMainViewSettings.mProjection);
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  v21 = fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20));
  *(float *)&v22 = v18 * (float)(1.0 / v21);
  v179 = v22;
  *(float *)&v23 = v19 * (float)(1.0 / v21);
  v180 = v23;
  *(float *)&v24 = v20 * (float)(1.0 / v21);
  v183 = v24;
  v184 = COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v3.y + result.v3.w) ^ _xmm[0]) * (float)(1.0 / v21);
  if ( v4 )
  {
    v25 = v6->mMainViewSettings.mCullIndex;
    v26 = (unsigned __int8)((signed int)v25 >= 0 && (signed int)v25 <= 16) & v4->mDrawEnabled ? v4->mCullResultBuckets[v25].mHead : 0i64;
    v27 = v26;
    v28 = 0;
    while ( v27 )
    {
      v29 = (UFG::CompositeDrawableComponent *)v27[v28 + 3].mNext;
      v30 = v6->mMainViewSettings.mCullIndex;
      if ( (signed int)v30 >= 6 )
        v31 = v14;
      else
        v31 = v29->mCullResults->mPixelCoverage[v30];
      v32 = UFG::CompositeDrawableComponent::GetLOD((UFG::CompositeDrawableComponent *)v27[v28 + 3].mNext, v31);
      if ( v29->mPose->mRigHandle.mData && !v32 && v31 > 8.0 )
      {
        if ( _S2_0 & 1 )
        {
          v33 = s_uSpineJoinNameUID;
        }
        else
        {
          _S2_0 |= 1u;
          v33 = UFG::qStringHashUpper32("Bip01 Spine", 0xFFFFFFFF);
          s_uSpineJoinNameUID = v33;
        }
        v34 = Skeleton::GetBoneID(v29->mPose->mRigHandle.mUFGSkeleton, v33);
        if ( v34 >= 0 )
        {
          SkeletalPose::GetPositionWS(v29->mPose, v34, &matrixWS);
          v35 = (float)(sThreshold / (float)(v14 / v6->mMainViewSettings.mProjection.v0.x))
              * (float)(sThreshold / (float)(v14 / v6->mMainViewSettings.mProjection.v0.x));
          v151 = matrixWS.v3.z;
          v182 = matrixWS.v3.y;
          if ( (float)((float)((float)((float)(matrixWS.v3.y - v16) * (float)(matrixWS.v3.y - v16))
                             + (float)((float)(matrixWS.v3.x - v230) * (float)(matrixWS.v3.x - v230)))
                     + (float)((float)(matrixWS.v3.z - v17) * (float)(matrixWS.v3.z - v17))) <= v35 )
          {
            if ( v154 >= v153 )
              break;
            ++v154;
            v36 = (float)(dir.z * 25.0) + v233;
            v37 = (float)(dir.y * 25.0) + v231;
            v38 = (float)(dir.x * 25.0) + v230;
            v39 = v7->mShadowNear;
            near_plane = v7->mShadowNear;
            v40 = (float)((float)(v14 - COERCE_FLOAT(LODWORD(dir.z) & _xmm)) * sfSunAngleFit) + 0.64999998;
            v185 = v40;
            target = *(UFG::qVector3 *)&matrixWS.v3.x;
            if ( v7->mTightenCharacterShadows )
            {
              v41 = v29->mCullInfo;
              v42 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v42 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v43 = inflate_0;
              v44 = v41->mAABBMin[2] - inflate_0;
              v45 = v41->mAABBMin[1] - inflate_0;
              row_vec4.x = v41->mAABBMin[0] - inflate_0;
              row_vec4.y = v45;
              row_vec4.z = v44;
              row_vec4.w = 1.0;
              v46 = (int *)UFG::operator*(&v218, &row_vec4, v42);
              v47 = v46[1];
              v48 = v46[2];
              v155 = *v46;
              v156 = v47;
              v157 = v48;
              v49 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v49 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v50 = v41->mAABBMin[2] - v43;
              v51 = v41->mAABBMin[1] - v43;
              v200.x = v43 + v41->mAABBMax[0];
              v200.y = v51;
              v200.z = v50;
              v200.w = 1.0;
              v52 = (int *)UFG::operator*(&v219, &v200, v49);
              v53 = v52[1];
              v54 = v52[2];
              v158 = *v52;
              v159 = v53;
              v160 = v54;
              v55 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v55 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v56 = v41->mAABBMin[2] - v43;
              v57 = v43 + v41->mAABBMax[1];
              v195.x = v43 + v41->mAABBMax[0];
              v195.y = v57;
              v195.z = v56;
              v195.w = 1.0;
              v58 = (int *)UFG::operator*(&v221, &v195, v55);
              v59 = v58[1];
              v60 = v58[2];
              v161 = *v58;
              v162 = v59;
              v163 = v60;
              v61 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v61 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v62 = v41->mAABBMin[2] - v43;
              v63 = v43 + v41->mAABBMax[1];
              v193.x = v41->mAABBMin[0] - v43;
              v193.y = v63;
              v193.z = v62;
              v193.w = 1.0;
              v64 = (int *)UFG::operator*(&v225, &v193, v61);
              v65 = v64[1];
              v66 = v64[2];
              v164 = *v64;
              v165 = v65;
              v166 = v66;
              v67 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v67 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v68 = v43 + v41->mAABBMax[2];
              v69 = v41->mAABBMin[1] - v43;
              v194.x = v41->mAABBMin[0] - v43;
              v194.y = v69;
              v194.z = v68;
              v194.w = 1.0;
              v70 = (int *)UFG::operator*(&v220, &v194, v67);
              v71 = v70[1];
              v72 = v70[2];
              v167 = *v70;
              v168 = v71;
              v169 = v72;
              v73 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v73 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v74 = v43 + v41->mAABBMax[2];
              v75 = v41->mAABBMin[1] - v43;
              v199.x = v43 + v41->mAABBMax[0];
              v199.y = v75;
              v199.z = v74;
              v199.w = 1.0;
              v76 = (int *)UFG::operator*(&v223, &v199, v73);
              v77 = v76[1];
              v78 = v76[2];
              v170 = *v76;
              v171 = v77;
              v172 = v78;
              v79 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v79 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v80 = v43 + v41->mAABBMax[2];
              v81 = v43 + v41->mAABBMax[1];
              v197.x = v43 + v41->mAABBMax[0];
              v197.y = v81;
              v197.z = v80;
              v197.w = 1.0;
              v82 = (int *)UFG::operator*(&v222, &v197, v79);
              v83 = v82[1];
              v84 = v82[2];
              v173 = *v82;
              v174 = v83;
              v175 = v84;
              v85 = &UFG::qMatrix44::msIdentity;
              if ( v41->mpLocalWorld )
                v85 = (UFG::qMatrix44 *)v41->mpLocalWorld;
              v86 = v43 + v41->mAABBMax[2];
              v87 = v43 + v41->mAABBMax[1];
              v192.x = v41->mAABBMin[0] - v43;
              v192.y = v87;
              v192.z = v86;
              v192.w = 1.0;
              v88 = (int *)UFG::operator*(&v217, &v192, v85);
              v89 = v88[1];
              v90 = v88[2];
              v176 = *v88;
              v177 = v89;
              v178 = v90;
              v201 = 0;
              v202 = 4;
              v203 = 1;
              v204 = 5;
              v205 = 2;
              v206 = 6;
              v207 = 3;
              v208 = 7;
              v91 = &v202;
              v92 = 4i64;
              v93 = v184;
              do
              {
                v94 = 3i64 * (unsigned int)*(v91 - 1);
                v95 = (unsigned int)*v91;
                v96 = *((float *)&v157 + 3 * v95) - *((float *)&v157 + 3 * (unsigned int)*(v91 - 1));
                v97 = *((float *)&v156 + 3 * v95) - *((float *)&v156 + 3 * (unsigned int)*(v91 - 1));
                v98 = *((float *)&v155 + 3 * v95) - *((float *)&v155 + 3 * (unsigned int)*(v91 - 1));
                v99 = (float)((float)(v97 * *(float *)&v23) + (float)(*(float *)&v22 * v98))
                    + (float)(v96 * *(float *)&v24);
                if ( v99 <= 0.0 )
                {
                  v103 = *((float *)&v157 + 3 * v95) - *((float *)&v157 + 3 * (unsigned int)*(v91 - 1));
                  v104 = *((float *)&v156 + 3 * v95) - *((float *)&v156 + 3 * (unsigned int)*(v91 - 1));
                  v105 = *((float *)&v155 + 3 * v95) - *((float *)&v155 + 3 * (unsigned int)*(v91 - 1));
                  if ( (float)((float)((float)(v104 * *(float *)&v23) + (float)(*(float *)&v22 * v105))
                             + (float)(v103 * *(float *)&v24)) != 0.0 )
                  {
                    v106 = (float)(-1.0
                                 / (float)((float)((float)(COERCE_FLOAT(LODWORD(v104) ^ _xmm[0]) * *(float *)&v23)
                                                 + (float)(COERCE_FLOAT(LODWORD(v105) ^ _xmm[0]) * *(float *)&v22))
                                         + (float)(COERCE_FLOAT(LODWORD(v103) ^ _xmm[0]) * *(float *)&v24)))
                         * (float)((float)((float)((float)(*(float *)&v23 * *((float *)&v156 + 3 * v95))
                                                 + (float)(*(float *)&v22 * *((float *)&v155 + 3 * v95)))
                                         + (float)(*(float *)&v24 * *((float *)&v157 + 3 * v95)))
                                 + v93);
                    if ( v106 > 0.0 && v106 < 1.0 )
                    {
                      v107 = *((float *)&v157 + 3 * v95) - (float)(v103 * v106);
                      v108 = *((float *)&v156 + 3 * v95) - (float)(v104 * v106);
                      *((float *)&v155 + 3 * (unsigned int)*(v91 - 1)) = *((float *)&v155 + 3 * v95)
                                                                       - (float)(v105 * v106);
                      *((float *)&v156 + v94) = v108;
                      *((float *)&v157 + v94) = v107;
                    }
                  }
                }
                else
                {
                  v100 = (float)((float)((float)((float)(*(float *)&v23
                                                       * *((float *)&v156 + 3 * (unsigned int)*(v91 - 1)))
                                               + (float)(*(float *)&v22
                                                       * *((float *)&v155 + 3 * (unsigned int)*(v91 - 1))))
                                       + (float)(*(float *)&v24 * *((float *)&v157 + 3 * (unsigned int)*(v91 - 1))))
                               + v93)
                       * (float)(-1.0 / v99);
                  if ( v100 > 0.0 && v100 < 1.0 )
                  {
                    v101 = (float)(v96 * v100) + *((float *)&v157 + 3 * (unsigned int)*(v91 - 1));
                    v102 = (float)(v97 * v100) + *((float *)&v156 + 3 * (unsigned int)*(v91 - 1));
                    *((float *)&v155 + 3 * v95) = (float)(v98 * v100) + *((float *)&v155 + 3 * (unsigned int)*(v91 - 1));
                    *((float *)&v156 + 3 * v95) = v102;
                    *((float *)&v157 + 3 * v95) = v101;
                  }
                }
                v91 += 2;
                --v92;
              }
              while ( v92 );
              eye.x = (float)(v38 - v230) + matrixWS.v3.x;
              eye.y = (float)(v37 - v231) + v182;
              eye.z = (float)(v36 - v233) + v151;
              UFG::qLookAtMatrix(&result, &eye, &target, &up);
              UFG::qOrthographicMatrix(&dest, v185 * 6.0, v185 * 6.0, near_plane, 50.0);
              UFG::qMatrix44::operator*(&result, &v209, &dest);
              v109 = FLOAT_10000_0;
              v110 = FLOAT_10000_0;
              v111 = FLOAT_N10000_0;
              v112 = FLOAT_N10000_0;
              v113 = (float *)&v157;
              v114 = 2i64;
              do
              {
                v115 = (float)((float)((float)(v209.v1.x * *(v113 - 1)) + (float)(v209.v0.x * *(v113 - 2)))
                             + (float)(v209.v2.x * *v113))
                     + v209.v3.x;
                v116 = (float)((float)((float)(v209.v1.y * *(v113 - 1)) + (float)(v209.v0.y * *(v113 - 2)))
                             + (float)(v209.v2.y * *v113))
                     + v209.v3.y;
                if ( v109 >= v115 )
                  v109 = (float)((float)((float)(v209.v1.x * *(v113 - 1)) + (float)(v209.v0.x * *(v113 - 2)))
                               + (float)(v209.v2.x * *v113))
                       + v209.v3.x;
                if ( v110 >= v116 )
                  v110 = (float)((float)((float)(v209.v1.y * *(v113 - 1)) + (float)(v209.v0.y * *(v113 - 2)))
                               + (float)(v209.v2.y * *v113))
                       + v209.v3.y;
                if ( v111 <= v115 )
                  v111 = (float)((float)((float)(v209.v1.x * *(v113 - 1)) + (float)(v209.v0.x * *(v113 - 2)))
                               + (float)(v209.v2.x * *v113))
                       + v209.v3.x;
                if ( v112 <= v116 )
                  v112 = (float)((float)((float)(v209.v1.y * *(v113 - 1)) + (float)(v209.v0.y * *(v113 - 2)))
                               + (float)(v209.v2.y * *v113))
                       + v209.v3.y;
                v117 = (float)((float)((float)(v209.v1.x * v113[2]) + (float)(v209.v0.x * v113[1]))
                             + (float)(v209.v2.x * v113[3]))
                     + v209.v3.x;
                v118 = (float)((float)((float)(v209.v1.y * v113[2]) + (float)(v209.v0.y * v113[1]))
                             + (float)(v209.v2.y * v113[3]))
                     + v209.v3.y;
                if ( v109 >= v117 )
                  v109 = (float)((float)((float)(v209.v1.x * v113[2]) + (float)(v209.v0.x * v113[1]))
                               + (float)(v209.v2.x * v113[3]))
                       + v209.v3.x;
                if ( v110 >= v118 )
                  v110 = (float)((float)((float)(v209.v1.y * v113[2]) + (float)(v209.v0.y * v113[1]))
                               + (float)(v209.v2.y * v113[3]))
                       + v209.v3.y;
                if ( v111 <= v117 )
                  v111 = (float)((float)((float)(v209.v1.x * v113[2]) + (float)(v209.v0.x * v113[1]))
                               + (float)(v209.v2.x * v113[3]))
                       + v209.v3.x;
                if ( v112 <= v118 )
                  v112 = (float)((float)((float)(v209.v1.y * v113[2]) + (float)(v209.v0.y * v113[1]))
                               + (float)(v209.v2.y * v113[3]))
                       + v209.v3.y;
                v119 = (float)((float)((float)(v209.v1.x * v113[5]) + (float)(v209.v0.x * v113[4]))
                             + (float)(v209.v2.x * v113[6]))
                     + v209.v3.x;
                v120 = (float)((float)((float)(v209.v1.y * v113[5]) + (float)(v209.v0.y * v113[4]))
                             + (float)(v209.v2.y * v113[6]))
                     + v209.v3.y;
                if ( v109 >= v119 )
                  v109 = (float)((float)((float)(v209.v1.x * v113[5]) + (float)(v209.v0.x * v113[4]))
                               + (float)(v209.v2.x * v113[6]))
                       + v209.v3.x;
                if ( v110 >= v120 )
                  v110 = (float)((float)((float)(v209.v1.y * v113[5]) + (float)(v209.v0.y * v113[4]))
                               + (float)(v209.v2.y * v113[6]))
                       + v209.v3.y;
                if ( v111 <= v119 )
                  v111 = (float)((float)((float)(v209.v1.x * v113[5]) + (float)(v209.v0.x * v113[4]))
                               + (float)(v209.v2.x * v113[6]))
                       + v209.v3.x;
                if ( v112 <= v120 )
                  v112 = (float)((float)((float)(v209.v1.y * v113[5]) + (float)(v209.v0.y * v113[4]))
                               + (float)(v209.v2.y * v113[6]))
                       + v209.v3.y;
                v121 = (float)((float)((float)(v113[7] * v209.v0.x) + (float)(v113[8] * v209.v1.x))
                             + (float)(v209.v2.x * v113[9]))
                     + v209.v3.x;
                v122 = (float)((float)((float)(v113[7] * v209.v0.y) + (float)(v113[8] * v209.v1.y))
                             + (float)(v209.v2.y * v113[9]))
                     + v209.v3.y;
                if ( v109 >= v121 )
                  v109 = (float)((float)((float)(v113[7] * v209.v0.x) + (float)(v113[8] * v209.v1.x))
                               + (float)(v209.v2.x * v113[9]))
                       + v209.v3.x;
                if ( v110 >= v122 )
                  v110 = (float)((float)((float)(v113[7] * v209.v0.y) + (float)(v113[8] * v209.v1.y))
                               + (float)(v209.v2.y * v113[9]))
                       + v209.v3.y;
                if ( v111 <= v121 )
                  v111 = (float)((float)((float)(v113[7] * v209.v0.x) + (float)(v113[8] * v209.v1.x))
                               + (float)(v209.v2.x * v113[9]))
                       + v209.v3.x;
                if ( v112 <= v122 )
                  v112 = (float)((float)((float)(v113[7] * v209.v0.y) + (float)(v113[8] * v209.v1.y))
                               + (float)(v209.v2.y * v113[9]))
                       + v209.v3.y;
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
              b.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v125, (__m128)v125, 21);
              b.v0.x = 2.0 / v123;
              b.v1.y = 2.0 / v124;
              b.v3.x = (float)((float)(v111 + v109) * -0.5) * (float)(2.0 / v123);
              b.v3.y = (float)((float)(v112 + v110) * -0.5) * (float)(2.0 / v124);
              UFG::qMatrix44::operator*=(&dest, &b);
            }
            else
            {
              v191.x = (float)(v38 - v230) + matrixWS.v3.x;
              v191.y = matrixWS.v3.y + (float)(v37 - v231);
              v191.z = matrixWS.v3.z + (float)(v36 - v233);
              UFG::qLookAtMatrix(&result, &v191, &target, &up);
              UFG::qOrthographicMatrix(&dest, v40 * 2.0, v40 * 2.0, v39, 50.0);
            }
            if ( _S2_0 & 2 )
            {
              v152 = HALF_DIM;
            }
            else
            {
              _S2_0 |= 2u;
              v126 = v6->mCharacterShadowSize;
              v152 = (float)v126 * 0.5;
              HALF_DIM = (float)v126 * 0.5;
            }
            v127 = _mm_add_ps(
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
            v128 = v127;
            v128.m128_f32[0] = v127.m128_f32[0] * v152;
            v129 = _mm_shuffle_ps(v127, v127, 85);
            v129.m128_f32[0] = v129.m128_f32[0] * v152;
            v130 = v128.m128_f32[0];
            v131 = (signed int)v128.m128_f32[0];
            if ( (signed int)v128.m128_f32[0] != 0x80000000 && (float)v131 != v128.m128_f32[0] )
              v130 = (float)(v131 - (_mm_movemask_ps(_mm_unpacklo_ps(v128, v128)) & 1));
            v132 = v129.m128_f32[0];
            v133 = (signed int)v129.m128_f32[0];
            if ( (signed int)v129.m128_f32[0] != 0x80000000 && (float)v133 != v129.m128_f32[0] )
              v132 = (float)(v133 - (_mm_movemask_ps(_mm_unpacklo_ps(v129, v129)) & 1));
            dest.v3.x = dest.v3.x + (float)((float)(v130 - v128.m128_f32[0]) * (float)(1.0 / v152));
            dest.v3.y = dest.v3.y + (float)((float)(v132 - v129.m128_f32[0]) * (float)(1.0 / v152));
            settings.mCullIndex = -1;
            *(_QWORD *)&settings.mCullPixelDensityThreshold = 0i64;
            settings.mWorldView = result;
            settings.mProjection = dest;
            Render::View::View(&view, &settings, (Illusion::SubmitContext *)&ptr.vfptr);
            Render::View::BeginTarget(
              &view,
              v6->mCharacterShadowTarget,
              "ShadowTarget_Character",
              0,
              0,
              0i64,
              1,
              0,
              0,
              0);
            Render::View::Clear(&view, &UFG::qColour::Black, 6u, 1.0, 0);
            v134 = Render::View::GetStateArgs(&view);
            v135 = &view.mSettings->mProjection;
            arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            arg.mCallback = 0i64;
            arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
            *(_WORD *)&arg.mFlags = 1;
            if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
            {
              v136 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
              Render::cbViewTransformState::sStateParamIndex = v136;
              arg.mStateParamIndex = v136;
            }
            arg.mWorldViewProjection = &view.mWorldViewProjection;
            arg.mViewWorld = &view.mViewWorld;
            arg.mProjection = v135;
            arg.mScreenOffset = &Render::View::mScreenOffset;
            arg.mCached_Remote.m_Stream = 0i64;
            Illusion::StateArgs::Set<Render::cbViewTransformState>(v134, &arg);
            v137 = UFG::Metrics::msInstance.mSimTimeDelta;
            v138 = UFG::Metrics::msInstance.mSimTime_Temp;
            v139 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
            *(float *)v139 = v138;
            *((float *)v139 + 1) = v137;
            v140 = Render::View::GetStateValues(&view);
            v140->mSetValueMask.mFlags[0] |= 0x2000ui64;
            v140->mParamValues[13] = v139;
            UFG::CompositeDrawableComponent::Draw(v29, &view, 0);
            v141 = arg.mPrev;
            v142 = arg.mNext;
            arg.mPrev->mNext = arg.mNext;
            v142->mPrev = v141;
            arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            arg.mIsSet = 0;
            if ( (Illusion::StateArgs *)v134->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v134 + 16 * (arg.mStateParamIndex + 3i64)) )
              v134->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
            Render::View::EndTarget(&view);
            v143 = result.v1;
            v144 = result.v2;
            v145 = result.v3;
            v7->mCSWorldShadow.v0 = result.v0;
            v7->mCSWorldShadow.v1 = v143;
            v7->mCSWorldShadow.v2 = v144;
            v7->mCSWorldShadow.v3 = v145;
            v146 = dest.v1;
            v147 = dest.v2;
            v148 = dest.v3;
            v7->mCSShadowProj.v0 = dest.v0;
            v7->mCSShadowProj.v1 = v146;
            v7->mCSShadowProj.v2 = v147;
            v7->mCSShadowProj.v3 = v148;
            UFG::RenderStageShadow::RenderCharacterShadowsIntoCollector(v7, v6, v29, serialization_lista);
            v149 = arg.mPrev;
            v150 = arg.mNext;
            arg.mPrev->mNext = arg.mNext;
            v150->mPrev = v149;
            arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
            v22 = v179;
            v23 = v180;
            v24 = v183;
            v14 = *(float *)&FLOAT_1_0;
            v16 = v231;
            v17 = v233;
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
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  `eh vector destructor iterator'(
    v229.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v227);
}

// File Line: 1900
// RVA: 0x38870
void __fastcall UFG::RenderStageShadow::RenderBeforeSunShadows(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  this->mRenderingNISCharacterShadows = 0;
}

// File Line: 1905
// RVA: 0x38860
void __fastcall UFG::RenderStageShadow::RenderAfterSunShadows(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  JUMPOUT(render_context->mRenderSun, 0, UFG::RenderStageShadow::BlurCollector);
}

// File Line: 1922
// RVA: 0x37A50
void __fastcall UFG::RenderStageShadow::BlurCollector(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qMatrix44 *v3; // rdi
  UFG::RenderContext *v4; // rbx
  Illusion::Material *v5; // rdi
  __int64 v6; // rax
  _WORD *v7; // rax
  Illusion::Material *v8; // rdi
  __int64 v9; // rax
  _WORD *v10; // rax
  Render::ViewSettings *v11; // rdi
  UFG::qMatrix44 *v12; // rsi
  unsigned __int16 v13; // ax
  Illusion::StateArgs *v14; // rdi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-98h]
  Render::View v21; // [rsp+158h] [rbp+70h]
  LayerSubmitContext ptr; // [rsp+2E8h] [rbp+200h]
  Render::Poly poly; // [rsp+F90h] [rbp+EA8h]

  arg.mWorldView = (UFG::qMatrix44 *)-2i64;
  v3 = (UFG::qMatrix44 *)serialization_list;
  v4 = render_context;
  if ( !(_S3_0 & 1) )
  {
    _S3_0 |= 1u;
    uidBILATERALBLUR = UFG::qStringHashUpper32("BILATERALBLUR", 0xFFFFFFFF);
  }
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  arg.mProjection = v3;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mProjection;
  if ( v4->mRenderSettingsForFrame.mShadowRes )
  {
    Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      v4->mDynamicRangeTarget,
      v4->mFullSizeScratchTargetA,
      uidBILATERALBLUR,
      "BilateralBlur",
      0,
      0,
      0i64);
    Render::gRenderUtilities.mSubmitContext = 0i64;
  }
  else
  {
    Render::View::View(&v21, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v21, v4->mFullSizeScratchTargetA, "BlankCollector", 0, 0, 0i64, 0, 0, 0, 0);
    v5 = v4->mShadowCollectorMaterial;
    if ( LODWORD(v5[1].mResourceHandles.mNode.mNext) != 127664167 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5[1].mNode.mChild[1], v5[1].mTypeUID, 0x79C0027u);
      v6 = v5->mMaterialUser.mOffset;
      if ( v6 )
        v7 = (_WORD *)((char *)&v5->mMaterialUser + v6);
      else
        v7 = 0i64;
      *v7 |= 0x20u;
    }
    v8 = v4->mShadowCollectorMaterial;
    if ( *(_DWORD *)&v8[2].mDebugName[28] != 1660426324 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[2].mDebugName[4], *((_DWORD *)&v8[2].0 + 22), 0x62F81854u);
      v9 = v8->mMaterialUser.mOffset;
      if ( v9 )
        v10 = (_WORD *)((char *)&v8->mMaterialUser + v9);
      else
        v10 = 0i64;
      *v10 |= 0x20u;
    }
    v11 = v21.mSettings;
    v12 = &v21.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v13;
      arg.mStateParamIndex = v13;
    }
    arg.mWorldView = &v11->mWorldView;
    arg.mProjection = v12;
    *(_QWORD *)&arg.mStateParamIndex = 0i64;
    v14 = Render::View::GetStateArgs(&v21);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v14, &arg);
    Render::View::Draw(&v21, &poly, v4->mShadowCollectorMaterial, 0i64);
    v15 = arg.mPrev;
    v16 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v16->mPrev = v15;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v14->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v14 + 16 * (arg.mStateParamIndex + 3i64)) )
    {
      v17 = &v14->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v17 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v21);
    v18 = arg.mPrev;
    v19 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v19->mPrev = v18;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  }
  poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
}

// File Line: 1970
// RVA: 0x38880
void __fastcall UFG::RenderStageShadow::RenderCascadeDebug(UFG::RenderStageShadow *this, Render::View *view, UFG::RenderContext *render_context)
{
  Render::View *v3; // rdi
  _WORD *v4; // rsi
  UFG::RenderStageShadow *v5; // r15
  Illusion::Material *v6; // rbx
  __int64 v7; // rax
  _WORD *v8; // rax
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  signed __int64 v13; // r14
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
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
  Illusion::Material *stencil; // ST20_8
  Illusion::Material *v54; // rbx
  __int64 v55; // rax
  _WORD *v56; // rax
  UFG::qColour *v57; // rdx
  Illusion::Material *v58; // ST20_8
  Illusion::Material *v59; // rbx
  __int64 v60; // rax
  _WORD *v61; // rax
  Illusion::Material *v62; // ST20_8
  Illusion::Material *v63; // rbx
  __int64 v64; // rax
  _WORD *v65; // rax
  Illusion::Material *v66; // rbx
  __int64 v67; // rax
  _WORD *v68; // rax
  __int64 v69; // rax
  UFG::qMatrix44 d; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 v71; // [rsp+70h] [rbp-68h]
  __int64 v72; // [rsp+B0h] [rbp-28h]
  UFG::qColour colour; // [rsp+B8h] [rbp-20h]
  UFG::qColour v74; // [rsp+C8h] [rbp-10h]
  UFG::qColour v75; // [rsp+D8h] [rbp+0h]
  UFG::qColour v76; // [rsp+E8h] [rbp+10h]
  UFG::qMatrix44 m; // [rsp+F8h] [rbp+20h]
  UFG::qMatrix44 v78; // [rsp+138h] [rbp+60h]
  Render::Poly poly; // [rsp+1F0h] [rbp+118h]

  v3 = view;
  v4 = 0i64;
  v5 = this;
  Render::View::Clear(view, &UFG::qColour::Zero, 4u, 1.0, 0);
  v6 = Render::gRenderUtilities.mMaterial;
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != 826356572 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      0x3141335Cu);
    v7 = v6->mMaterialUser.mOffset;
    if ( v7 )
      v8 = (_WORD *)((char *)&v6->mMaterialUser + v7);
    else
      v8 = 0i64;
    *v8 |= 0x20u;
    v6 = Render::gRenderUtilities.mMaterial;
  }
  if ( LODWORD(v6[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v6[1].mDebugName[20],
      v6[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v9 = v6->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v6->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
    v6 = Render::gRenderUtilities.mMaterial;
  }
  if ( v6[2].mNode.mUID != -1551679522 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v6[2],
      (unsigned int)v6[2].mResourceHandles.mNode.mPrev,
      0xA3833FDE);
    v11 = v6->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&v6->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  v13 = 2i64;
  do
  {
    v14 = v5->mShadowViewSettings[v13].mWorldView.v0.y;
    m.v0.x = v5->mShadowViewSettings[v13].mWorldView.v0.x;
    v15 = v5->mShadowViewSettings[v13].mWorldView.v0.z;
    m.v0.y = v14;
    v16 = v5->mShadowViewSettings[v13].mWorldView.v0.w;
    m.v0.z = v15;
    v17 = v5->mShadowViewSettings[v13].mWorldView.v1.x;
    m.v0.w = v16;
    v18 = v5->mShadowViewSettings[v13].mWorldView.v1.y;
    m.v1.x = v17;
    v19 = v5->mShadowViewSettings[v13].mWorldView.v1.z;
    m.v1.y = v18;
    v20 = v5->mShadowViewSettings[v13].mWorldView.v1.w;
    m.v1.z = v19;
    v21 = v5->mShadowViewSettings[v13].mWorldView.v2.x;
    m.v1.w = v20;
    v22 = v5->mShadowViewSettings[v13].mWorldView.v2.y;
    m.v2.x = v21;
    v23 = v5->mShadowViewSettings[v13].mWorldView.v2.z;
    m.v2.y = v22;
    v24 = v5->mShadowViewSettings[v13].mWorldView.v2.w;
    m.v2.z = v23;
    v25 = v5->mShadowViewSettings[v13].mWorldView.v3.x;
    m.v2.w = v24;
    v26 = v5->mShadowViewSettings[v13].mWorldView.v3.y;
    m.v3.x = v25;
    v27 = v5->mShadowViewSettings[v13].mWorldView.v3.z;
    m.v3.y = v26;
    v28 = v5->mShadowViewSettings[v13].mWorldView.v3.w;
    m.v3.z = v27;
    m.v3.w = v28;
    UFG::qInverseAffine(&d, &m);
    v29 = (__m128)(unsigned int)FLOAT_1_0;
    v29.m128_f32[0] = 1.0 / v5->mShadowViewSettings[v13].mProjection.v0.x;
    v30 = (UFG::qVector4)_mm_mul_ps((__m128)d.v0, _mm_shuffle_ps(v29, v29, 0));
    v31 = (__m128)(unsigned int)FLOAT_1_0;
    v31.m128_f32[0] = 1.0 / v5->mShadowViewSettings[v13].mProjection.v1.y;
    d.v0 = v30;
    d.v1 = (UFG::qVector4)_mm_mul_ps((__m128)d.v1, _mm_shuffle_ps(v31, v31, 0));
    v30.x = v5->mShadowOffset * 0.5;
    d.v2.x = d.v2.x * v30.x;
    d.v2.y = d.v2.y * v30.x;
    d.v2.z = d.v2.z * v30.x;
    d.v2.w = d.v2.w * v30.x;
    d.v3.x = d.v3.x - (float)(d.v2.x * 2.0);
    d.v3.y = d.v3.y - (float)(d.v2.y * 2.0);
    d.v3.z = d.v3.z - (float)(d.v2.z * 2.0);
    d.v3.w = d.v3.w - (float)(d.v2.w * 2.0);
    v32 = v13 == 0;
    if ( v13 > 0 )
    {
      v33 = *(&v5->mCloudShadowMinVolume + 36 * v13);
      v78.v0.x = *(&v5->mCloudShadowCullDist + 36 * v13);
      v34 = *((float *)&v5->mEnableCloudShadows + 36 * v13);
      v78.v0.y = v33;
      v35 = *((float *)&v5->mDrawDebugCascadeCoverage + 36 * v13);
      v78.v0.z = v34;
      v36 = *((float *)&v5->mMatDepthDownsampleShadow + 36 * v13);
      v78.v0.w = v35;
      v37 = *((float *)&v5->mMatDepthDownsampleShadow + 36 * v13 + 1);
      v78.v1.x = v36;
      v38 = *((float *)&v5->mMatStencilWriteShadowNear + 36 * v13);
      v78.v1.y = v37;
      v39 = *((float *)&v5->mMatStencilWriteShadowNear + 36 * v13 + 1);
      v78.v1.z = v38;
      v40 = *((float *)&v5->mMatStencilWriteShadowFar + 36 * v13);
      v78.v1.w = v39;
      v41 = *((float *)&v5->mMatStencilWriteShadowFar + 36 * v13 + 1);
      v78.v2.x = v40;
      v42 = v5->mBoundingSphere[9 * v13].x;
      v78.v2.y = v41;
      v43 = v5->mBoundingSphere[9 * v13].y;
      v78.v2.z = v42;
      v44 = v5->mBoundingSphere[9 * v13].z;
      v78.v2.w = v43;
      v45 = v5->mBoundingSphere[9 * v13].w;
      v78.v3.x = v44;
      v46 = v5->mBoundingSphere[9 * v13 + 1].x;
      v78.v3.y = v45;
      v47 = v5->mBoundingSphere[9 * v13 + 1].y;
      v78.v3.z = v46;
      v78.v3.w = v47;
      UFG::qInverseAffine(&v71, &v78);
      v48 = (__m128)(unsigned int)FLOAT_1_0;
      v32 = v13 == 0;
      v49 = v71.v0.x;
      v50 = v71.v0.y;
      v48.m128_f32[0] = 1.0 / v5->mBoundingSphere[9 * v13 + 1].z;
      v51 = (UFG::qVector4)_mm_mul_ps((__m128)v71.v0, _mm_shuffle_ps(v48, v48, 0));
      v52 = (__m128)(unsigned int)FLOAT_1_0;
      v52.m128_f32[0] = 1.0 / v5->mBoundingSphere[9 * v13 + 2].w;
      v71.v0 = v51;
      *(__m128 *)&d.v2.z = _mm_mul_ps(*(__m128 *)&d.v2.z, _mm_shuffle_ps(v52, v52, 0));
      v51.x = v5->mShadowOffset * 0.5;
      d.v3.z = d.v3.z * v51.x;
      d.v3.w = d.v3.w * v51.x;
      v71.v0.x = v49 * v51.x;
      v71.v0.y = v50 * v51.x;
      v71.v0.z = v71.v0.z - (float)(d.v3.z * 2.0);
      v71.v0.w = v71.v0.w - (float)(d.v3.w * 2.0);
      v71.v1.x = v71.v1.x - (float)((float)(v49 * v51.x) * 2.0);
      v71.v1.y = v71.v1.y - (float)((float)(v50 * v51.x) * 2.0);
    }
    if ( v32 )
    {
      stencil = v5->mMatStencilWriteShadowNear;
      Render::View::Draw(v3, &gDeferredCube, &d, 0);
      v54 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -978675340 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].0 + 22),
          0xC5AA9974);
        v55 = v54->mMaterialUser.mOffset;
        if ( v55 )
          v56 = (_WORD *)((char *)&v54->mMaterialUser + v55);
        else
          v56 = 0i64;
        *v56 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      *(_QWORD *)&colour.r = 1056964608i64;
      colour.b = 0.0;
      colour.a = 0.5;
      Render::Poly::SetColour(&poly, &colour);
      Render::View::Draw(v3, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v71.v3.z = 0i64;
      v72 = 0i64;
      v57 = (UFG::qColour *)&v71.v3.z;
    }
    else if ( v13 == 1 )
    {
      v58 = v5->mMatStencilWriteShadowFar;
      Render::View::Draw(v3, &gDeferredCube, &d, 0);
      v59 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -860456360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].0 + 22),
          0xCCB67A58);
        v60 = v59->mMaterialUser.mOffset;
        if ( v60 )
          v61 = (_WORD *)((char *)&v59->mMaterialUser + v60);
        else
          v61 = 0i64;
        *v61 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>((Render::Poly *)&v71.v2);
      v74.r = 0.0;
      *(_QWORD *)&v74.g = 1056964608i64;
      v74.a = 0.5;
      Render::Poly::SetColour((Render::Poly *)&v71.v2, &v74);
      Render::View::Draw(v3, (Render::Poly *)&v71.v2, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v71.v2.z = 0i64;
      *(_QWORD *)&v71.v3.x = 0i64;
      v57 = (UFG::qColour *)&v71.v2.z;
    }
    else
    {
      if ( v13 != 2 )
        goto LABEL_41;
      v62 = v5->mMatStencilWriteShadowFar;
      Render::View::Draw(v3, &gDeferredCube, &d, 0);
      v63 = Render::gRenderUtilities.mMaterial;
      if ( *(_DWORD *)&Render::gRenderUtilities.mMaterial[2].mDebugName[28] != -860456360 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2].mDebugName[4],
          *((_DWORD *)&Render::gRenderUtilities.mMaterial[2].0 + 22),
          0xCCB67A58);
        v64 = v63->mMaterialUser.mOffset;
        if ( v64 )
          v65 = (_WORD *)((char *)&v63->mMaterialUser + v64);
        else
          v65 = 0i64;
        *v65 |= 0x20u;
      }
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>((Render::Poly *)&v71.v1.z);
      *(_QWORD *)&v76.r = 0i64;
      v76.b = 0.5;
      v76.a = 0.5;
      Render::Poly::SetColour((Render::Poly *)&v71.v1.z, &v76);
      Render::View::Draw(v3, (Render::Poly *)&v71.v1.z, Render::gRenderUtilities.mMaterial, 0i64);
      *(_QWORD *)&v75.r = 0i64;
      *(_QWORD *)&v75.b = 0i64;
      v57 = &v75;
    }
    Render::View::Clear(v3, v57, 4u, 1.0, 0);
LABEL_41:
    --v13;
  }
  while ( v13 >= 0 );
  v66 = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v67 = v66->mMaterialUser.mOffset;
    if ( v67 )
      v68 = (_WORD *)((char *)&v66->mMaterialUser + v67);
    else
      v68 = 0i64;
    *v68 |= 0x20u;
    v66 = Render::gRenderUtilities.mMaterial;
  }
  if ( *(_DWORD *)&v66[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v66[2].mDebugName[4], *((_DWORD *)&v66[2].0 + 22), 0x62F81854u);
    v69 = v66->mMaterialUser.mOffset;
    if ( v69 )
      v4 = (_WORD *)((char *)&v66->mMaterialUser + v69);
    *v4 |= 0x20u;
  }
}ities.mMaterial;
  }
  if ( *(_DWORD *)&v66[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v66[2].mDebugName[4], *

// File Line: 2068
// RVA: 0x37D90
void __fastcall UFG::RenderStageShadow::BuildCascadedShadowViews(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qMatrix44 *cameraWorld, float cameraNear, float cameraFov, float cameraAspectRatio, UFG::qVector3 *lightPos, UFG::qVector3 *lightPosQuant, UFG::qVector3 *heightMapPos, UFG::qVector3 *lightTarget, float lightNear, float lightMaxFar)
{
  UFG::RenderStageShadow *v12; // rbx
  UFG::qMatrix44 *v13; // r15
  float v14; // xmm0_4
  UFG::RenderContext *v15; // rbp
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  signed int cascade; // edi
  _DWORD *v20; // rsi
  float *v21; // r14
  UFG::qVector4 v22; // xmm3
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm3
  float v28; // eax
  signed __int64 v29; // rcx
  UFG::qMatrix44 *worldShadow; // r8
  UFG::qMatrix44 *shadowProj; // rax
  UFG::qVector3 *light; // rcx
  Render::RenderOutputParams outSettings; // [rsp+70h] [rbp-E8h]

  this->mSplitPattern[0] = cameraNear;
  v12 = this;
  v13 = cameraWorld;
  v14 = cameraNear + this->mSplits[0];
  v15 = render_context;
  v16 = cameraNear;
  v17 = cameraNear + this->mSplits[2];
  v18 = v16 + this->mSplits[1];
  this->mSplitPattern[1] = v14;
  this->mSplitPattern[3] = v17;
  this->mSplitPattern[2] = v18;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  cascade = 0;
  v20 = (_DWORD *)v12->mCutplanes;
  v21 = &v12->mBoundingSphere[0].z;
  do
  {
    *v20 = v20[159];
    if ( cascade == 3 )
    {
      UFG::RenderStageShadow::CalculateCSMTransforms(
        v12,
        v15,
        v13,
        2.0,
        cameraAspectRatio,
        &v12->mShadowViewSettings[3].mWorldView,
        &v12->mShadowViewSettings[3].mProjection,
        &v12->mBoundingSphere[3],
        heightMapPos,
        lightTarget,
        lightNear,
        lightMaxFar,
        3u);
      if ( v15->mNumCascades == 1 )
      {
        v22 = v12->mShadowViewSettings[3].mWorldView.v1;
        v23 = v12->mShadowViewSettings[3].mWorldView.v2;
        v24 = v12->mShadowViewSettings[3].mWorldView.v3;
        v12->mShadowViewSettings[0].mWorldView.v0 = v12->mShadowViewSettings[3].mWorldView.v0;
        v12->mShadowViewSettings[0].mWorldView.v1 = v22;
        v12->mShadowViewSettings[0].mWorldView.v2 = v23;
        v12->mShadowViewSettings[0].mWorldView.v3 = v24;
        v25 = v12->mShadowViewSettings[3].mProjection.v2;
        v26 = v12->mShadowViewSettings[3].mProjection.v3;
        v27 = v12->mShadowViewSettings[3].mProjection.v1;
        v12->mShadowViewSettings[0].mProjection.v0 = v12->mShadowViewSettings[3].mProjection.v0;
        v12->mShadowViewSettings[0].mProjection.v1 = v27;
        v12->mShadowViewSettings[0].mProjection.v2 = v25;
        v12->mShadowViewSettings[0].mProjection.v3 = v26;
        v26.x = *v21;
        v28 = *(v21 - 2);
        v25.x = v21[1];
        v12->mBoundingSphere[0].y = *(v21 - 1);
        v12->mBoundingSphere[0].z = v26.x;
        v12->mBoundingSphere[0].x = v28;
        v12->mBoundingSphere[0].w = v25.x;
      }
    }
    else
    {
      v29 = cascade;
      worldShadow = &v12->mShadowViewSettings[v29].mWorldView;
      shadowProj = &v12->mShadowViewSettings[v29].mProjection;
      light = lightPosQuant;
      if ( !v12->mEnableAdjustedSunDir )
        light = lightPos;
      UFG::RenderStageShadow::CalculateCSMTransforms(
        v12,
        v15,
        v13,
        cameraFov,
        cameraAspectRatio,
        worldShadow,
        shadowProj,
        &v12->mBoundingSphere[cascade],
        light,
        lightTarget,
        lightNear,
        lightMaxFar,
        cascade);
    }
    ++cascade;
    ++v20;
    v21 += 4;
  }
  while ( cascade < 4 );
}

// File Line: 2163
// RVA: 0x38070
void __fastcall UFG::RenderStageShadow::CalculateCSMTransforms(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, UFG::qMatrix44 *camTransform, float FOV, float aspect, UFG::qMatrix44 *worldShadow, UFG::qMatrix44 *shadowProj, UFG::qVector4 *bounding, UFG::qVector3 *light, UFG::qVector3 *target, float lightNear, float lightMaxFar, unsigned int cascade)
{
  UFG::qMatrix44 *v13; // rbx
  UFG::RenderContext *v14; // rdi
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
  signed int v27; // eax
  float v28; // xmm6_4
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  float v31; // xmm9_4
  float v32; // xmm1_4
  signed int v33; // ecx
  float v34; // xmm1_4
  signed int v35; // ecx
  UFG::qVector3 up; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 v37; // [rsp+48h] [rbp-B0h]
  UFG::qVector3 eye; // [rsp+58h] [rbp-A0h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-88h]

  v13 = camTransform;
  v14 = render_context;
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
  LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v16);
  v22 = v13->v3.z - (float)(v20 * v13->v2.z);
  v23 = v13->v3.y - (float)(v20 * v13->v2.y);
  v24 = v13->v3.x - (float)(v20 * v13->v2.x);
  v37.x = v24;
  *(_QWORD *)&v37.y = __PAIR__(LODWORD(v22), LODWORD(v23));
  bounding->x = v24;
  bounding->y = v23;
  bounding->z = v22;
  bounding->w = v21 * v21;
  v25 = (float)(light->z - target->z) + v22;
  v26 = (float)(light->y - target->y) + v23;
  eye.x = (float)(light->x - target->x) + v24;
  eye.y = v26;
  eye.z = v25;
  UFG::qLookAtMatrix(worldShadow, &eye, &v37, &up);
  UFG::qOrthographicMatrix(shadowProj, v21 * 2.0, v21 * 2.0, lightNear, lightMaxFar);
  if ( _S4_0 & 1 )
  {
    v28 = QUANT_DIM;
  }
  else
  {
    _S4_0 |= 1u;
    v27 = v14->mCascadeShadowSize;
    v28 = (float)v27 * 0.125;
    QUANT_DIM = (float)v27 * 0.125;
  }
  UFG::qMatrix44::operator*(worldShadow, &result, shadowProj);
  v29 = (__m128)LODWORD(result.v3.x);
  v29.m128_f32[0] = result.v3.x * v28;
  v30 = (__m128)LODWORD(result.v3.y);
  v30.m128_f32[0] = result.v3.y * v28;
  v31 = 1.0 / v28;
  v32 = result.v3.x * v28;
  v33 = (signed int)(float)(result.v3.x * v28);
  if ( v33 != 0x80000000 && (float)v33 != v29.m128_f32[0] )
    v32 = (float)(v33 - (_mm_movemask_ps(_mm_unpacklo_ps(v29, v29)) & 1));
  shadowProj->v3.x = (float)((float)(v32 - v29.m128_f32[0]) * v31) + shadowProj->v3.x;
  v34 = v30.m128_f32[0];
  v35 = (signed int)v30.m128_f32[0];
  if ( (signed int)v30.m128_f32[0] != 0x80000000 && (float)v35 != v30.m128_f32[0] )
    v34 = (float)(v35 - (_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1));
  shadowProj->v3.y = (float)((float)(v34 - v30.m128_f32[0]) * v31) + shadowProj->v3.y;
}

// File Line: 2236
// RVA: 0x3B960
void __fastcall UFG::RenderStageShadow::RenderDebugOverlay(UFG::RenderStageShadow *this, UFG::RenderContext *render_context, Render::View *view, int x, int y, int size)
{
  Illusion::Texture *v6; // rcx
  UFG::qColour v7; // [rsp+40h] [rbp-18h]

  v6 = render_context->mHalfSizeShadowTarget->mDepthTextureCopy;
  v7 = UFG::qColour::White;
  Render::View::DrawIcon(view, v6->mNode.mUID, x, y, size, size, &v7, 0xA3833FDE);
}

