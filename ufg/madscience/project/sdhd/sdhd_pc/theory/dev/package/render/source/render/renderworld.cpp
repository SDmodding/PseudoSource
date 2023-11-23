// File Line: 165
// RVA: 0x1454ED0
__int64 dynamic_initializer_for__AlphaStateNoneHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&AlphaStateNoneHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AlphaStateNoneHandle__);
}

// File Line: 166
// RVA: 0x1454EA0
__int64 dynamic_initializer_for__AlphaStateNoColourWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&AlphaStateNoColourWriteHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AlphaStateNoColourWriteHandle__);
}

// File Line: 167
// RVA: 0x1454E70
__int64 dynamic_initializer_for__AlphaStateDeferredPunchThroughHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&AlphaStateDeferredPunchThroughHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AlphaStateDeferredPunchThroughHandle__);
}

// File Line: 168
// RVA: 0x1454FF0
__int64 dynamic_initializer_for__RasterStateNormalHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateNormalHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateNormalHandle__);
}

// File Line: 169
// RVA: 0x1454F90
__int64 dynamic_initializer_for__RasterStateInvertCullingHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateInvertCullingHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateInvertCullingHandle__);
}

// File Line: 170
// RVA: 0x1454FC0
__int64 dynamic_initializer_for__RasterStateNormalDisableWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateNormalDisableWriteHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateNormalDisableWriteHandle__);
}

// File Line: 171
// RVA: 0x1454F60
__int64 dynamic_initializer_for__RasterStateInverseDisableWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateInverseDisableWriteHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateInverseDisableWriteHandle__);
}

// File Line: 172
// RVA: 0x1454F30
__int64 dynamic_initializer_for__RasterStateDoubleSidedHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateDoubleSidedHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateDoubleSidedHandle__);
}

// File Line: 173
// RVA: 0x1454F00
__int64 dynamic_initializer_for__RasterStateDoubleSidedAlphaHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&RasterStateDoubleSidedAlphaHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__RasterStateDoubleSidedAlphaHandle__);
}

// File Line: 271
// RVA: 0x1456370
__int64 dynamic_initializer_for__gScenerySelector_Name__()
{
  UFG::qString::qString(&gScenerySelector_Name);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gScenerySelector_Name__);
}

// File Line: 274
// RVA: 0x1456310
__int64 dynamic_initializer_for__gReflectionFadeCube__()
{
  UFG::qResourceHandle::qResourceHandle(&gReflectionFadeCube);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gReflectionFadeCube__);
}

// File Line: 275
// RVA: 0x1455F50
__int64 dynamic_initializer_for__gDefaultBlackTexture__()
{
  UFG::qResourceHandle::qResourceHandle(&gDefaultBlackTexture);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDefaultBlackTexture__);
}

// File Line: 276
// RVA: 0x1455F80
__int64 dynamic_initializer_for__gDefaultWhiteTexture__()
{
  UFG::qResourceHandle::qResourceHandle(&gDefaultWhiteTexture);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDefaultWhiteTexture__);
}

// File Line: 277
// RVA: 0x1455FB0
__int64 dynamic_initializer_for__gDefaultZeroTexture__()
{
  UFG::qResourceHandle::qResourceHandle(&gDefaultZeroTexture);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDefaultZeroTexture__);
}

// File Line: 278
// RVA: 0x1455EA0
__int64 dynamic_initializer_for__gArcTanTexture__()
{
  UFG::qResourceHandle::qResourceHandle(&gArcTanTexture);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gArcTanTexture__);
}

// File Line: 280
// RVA: 0x1455F20
__int64 dynamic_initializer_for__gDebugFontHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&gDebugFontHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDebugFontHandle__);
}

// File Line: 317
// RVA: 0x1456390
__int64 dynamic_initializer_for__gSimpleDrawableCullLayer__()
{
  CullLayer::CullLayer(&gSimpleDrawableCullLayer, TYPE_CULL, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSimpleDrawableCullLayer__);
}

// File Line: 318
// RVA: 0x1455EF0
__int64 dynamic_initializer_for__gCompositeDrawableCullLayer__()
{
  CullLayer::CullLayer(&gCompositeDrawableCullLayer, TYPE_CULL, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gCompositeDrawableCullLayer__);
}

// File Line: 347
// RVA: 0x48D80
void __fastcall SimRenderQueueResults::SimRenderQueueResults(SimRenderQueueResults *this)
{
  RenderQueueLayer::RenderQueueLayer(&this->mRenderSimLayer);
  RenderQueueLayer::RenderQueueLayer(&this->mFXLayer);
  this->mTerrainQueues.mNode.mPrev = &this->mTerrainQueues.mNode;
  this->mTerrainQueues.mNode.mNext = &this->mTerrainQueues.mNode;
  this->mImposterQueues.mNode.mPrev = &this->mImposterQueues.mNode;
  this->mImposterQueues.mNode.mNext = &this->mImposterQueues.mNode;
  this->mDecalQueues.mNode.mPrev = &this->mDecalQueues.mNode;
  this->mDecalQueues.mNode.mNext = &this->mDecalQueues.mNode;
}

// File Line: 376
// RVA: 0x48CD0
void __fastcall SceneryTaskRenderQueueResults::SceneryTaskRenderQueueResults(SceneryTaskRenderQueueResults *this)
{
  Render::ViewMetrics *mSceneryViewMetrics; // rbx
  int i; // esi

  this->mSceneryBucketIndex = 0;
  `eh vector constructor iterator(
    this->mSceneryLayer,
    0xE0ui64,
    5,
    (void (__fastcall *)(void *))RenderQueueLayer::RenderQueueLayer);
  mSceneryViewMetrics = this->mSceneryViewMetrics;
  for ( i = 4; i >= 0; --i )
    Render::ViewMetrics::Reset(mSceneryViewMetrics++);
  this->mSceneryTaskGroup = 0i64;
  this->mSceneryTaskParams[0] = 0i64;
  this->mSceneryTaskParams[1] = 0i64;
  this->mSceneryTaskParams[2] = 0i64;
  this->mSceneryTaskParams[3] = 0i64;
  this->mSceneryTaskParams[4] = 0i64;
}

// File Line: 553
// RVA: 0x59390
void RenderWorldChangeLODSettings(void)
{
  float v0; // xmm6_4
  float v1; // xmm7_4
  Illusion::Target *BackBufferTarget; // rbx
  float v3; // xmm2_4
  float v4; // xmm1_4
  BOOL v5; // ebx
  UFG::TimeOfDayManager *Instance; // rax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-98h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  v0 = *(float *)&FLOAT_1_0;
  if ( outSettings.mLODSetting >= LOD_SETTING_HIGH )
    v1 = *(float *)&FLOAT_1_0;
  else
    v1 = FLOAT_3_0;
  UFG::CompositeDrawableComponent::ScalePixelCoverageToLOD(v1);
  BackBufferTarget = Render::GetBackBufferTarget();
  v3 = FLOAT_0_1;
  v4 = (float)(921600.0 / (float)(BackBufferTarget->mHeight * Render::GetBackBufferTarget()->mWidth)) * 0.1;
  if ( v4 <= 0.1 )
    v3 = v4;
  if ( outSettings.mAAQuality )
    v0 = FLOAT_0_5;
  v5 = outSettings.mLODSetting <= LOD_SETTING_NORMAL;
  gMainView_CullPixelDensityThreshold = (float)(v0 * v3) * v1;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetFogSlicingMode(Instance, v5 + 1);
  gExtendedMidground = outSettings.mLODSetting > LOD_SETTING_NORMAL;
  if ( outSettings.mLODSetting <= LOD_SETTING_NORMAL )
    gSceneryThresholdLodB = FLOAT_0_25;
  else
    gSceneryThresholdLodB = 1.0;
  if ( outSettings.mLODSetting )
  {
    gFadeThreshold = FLOAT_20_0;
    gClipThreshold = FLOAT_30_0;
    gShadowClipThreshold = FLOAT_12_0;
    gShadowFadeThreshold = FLOAT_8_0;
  }
  else
  {
    gFadeThreshold = 5.0;
    gClipThreshold = 10.0;
    gShadowFadeThreshold = 5.0;
    gShadowClipThreshold = 10.0;
  }
}

// File Line: 592
// RVA: 0x5AC90
void RenderWorldResize(void)
{
  int reflection_width; // esi
  int reflection_height; // ebp
  Render::eAAQuality aaQuality; // edi
  bool bLightMRT; // r14
  void (__fastcall *m_DisplayChangeCallback)(Render::RenderOutputParams *); // rax
  Render::RenderCallbacks *RenderCallbacks; // rax
  UFG::RenderContext *mRenderParam; // rbx
  char *v7; // rax
  void *v8; // rax
  void *v9; // rbx
  Render::DebugDrawManager *v10; // rdi
  int mHeight; // ebx
  Illusion::Target *BackBufferTarget; // rax
  UFG::DUIContext *v13; // rax
  UFG::DUIContext *v14; // rax
  UFG::DUIRect rect; // [rsp+60h] [rbp-A8h] BYREF
  __int64 v16; // [rsp+70h] [rbp-98h]
  Render::RenderOutputParams outSettings; // [rsp+80h] [rbp-88h] BYREF

  v16 = -2i64;
  Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
  reflection_width = Render::GetBackBufferTarget()->mWidth;
  reflection_height = Render::GetBackBufferTarget()->mHeight;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  aaQuality = outSettings.mAAQuality;
  RenderWorldChangeLODSettings();
  bLightMRT = outSettings.mSSAO == SSAO_HIGH;
  if ( UFG::UIScreenManager::s_instance )
  {
    m_DisplayChangeCallback = UFG::UIScreenManager::s_instance->m_DisplayChangeCallback;
    if ( m_DisplayChangeCallback )
      m_DisplayChangeCallback(&outSettings);
  }
  RenderCallbacks = Render::GetRenderCallbacks();
  mRenderParam = (UFG::RenderContext *)RenderCallbacks->mRenderParam;
  if ( mRenderParam )
  {
    UFG::RenderContext::DeleteTargets((UFG::RenderContext *)RenderCallbacks->mRenderParam);
    UFG::RenderContext::CreateTargets(
      mRenderParam,
      "Main",
      reflection_width,
      reflection_height,
      reflection_width,
      reflection_height,
      0x400u,
      0,
      bLightMRT,
      aaQuality);
  }
  else
  {
    v7 = UFG::qMalloc(0x4D0ui64, "RenderContext", 0i64);
    if ( v7 )
    {
      UFG::RenderContext::RenderContext(
        (UFG::RenderContext *)v7,
        "Main",
        reflection_width,
        reflection_height,
        reflection_width,
        reflection_height,
        0x400u,
        0,
        bLightMRT,
        aaQuality,
        AASTATE_SEPERATE_PASS);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    Render::GetRenderCallbacks()->mRenderParam = v9;
  }
  Render::DebugDrawManager::SetContextsTargetSize(
    Render::DebugDrawManager::mInstance,
    reflection_width,
    reflection_height,
    2u,
    2u);
  v10 = Render::DebugDrawManager::mInstance;
  mHeight = Render::GetBackBufferTarget()->mHeight;
  BackBufferTarget = Render::GetBackBufferTarget();
  Render::DebugDrawManager::SetContextsTargetSize(v10, BackBufferTarget->mWidth, mHeight, 2u, 0);
  if ( gTheoryOverlay )
  {
    v13 = gTheoryOverlay->vfptr->GetContext(gTheoryOverlay);
    rect.mX = v13->mRect.mX;
    rect.mY = v13->mRect.mY;
    rect.mW = reflection_width;
    rect.mH = reflection_height;
    v14 = gTheoryOverlay->vfptr->GetContext(gTheoryOverlay);
    UFG::DUIContext::SetOverallRect(v14, &rect);
    gTheoryOverlay->mWidth = rect.mW;
    gTheoryOverlay->mHeight = rect.mH;
  }
}

// File Line: 692
// RVA: 0x5AEC0
// attributes: thunk
void RenderWorldResizeShadows(void)
{
  RenderWorldResize();
}

// File Line: 699
// RVA: 0x59510
void RenderWorldChangeTexturePack(void)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  gIsHDWorldTextures = outSettings.mTextureDetailLevel == TEXTURE_DETAIL_HIGH;
  UFG::SectionChooser::BeginFlush(1);
}

// File Line: 710
// RVA: 0x58FE0
void UFG::RenderWorld::RenderThreadSyncUpdate(void)
{
  if ( UFG::RenderWorld::msStageFrameCapture )
    UFG::RenderStageFrameCapture::UpdateAlias(UFG::RenderWorld::msStageFrameCapture);
}

// File Line: 734
// RVA: 0x50B50
void InitBackBufferToPresentBuffer(void)
{
  unsigned int v0; // eax
  int v1; // eax
  Illusion::Material *v2; // rbx
  int v3; // edi
  int v4; // eax
  Illusion::Material *v5; // rbx
  int v6; // eax
  Illusion::Material *v7; // rbx
  unsigned int v8; // eax
  Illusion::Material *v9; // rbx
  int v10; // eax
  UFG::qResourceWarehouse *v11; // rax

  v0 = UFG::qStringHashUpper32("BackBufferToPresentMaterial", 0xFFFFFFFF);
  sPresentMaterial = Illusion::Factory::NewMaterial("BackBufferToPresentMaterial", v0, 4u, 0i64, 0i64, 0i64);
  v1 = UFG::qStringHashUpper32("DRFARGROUNDIMPOSTERS", 0xFFFFFFFF);
  v2 = sPresentMaterial;
  v3 = v1;
  LOWORD(sPresentMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(v2[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v2[1].mTypeUID = -1957338719;
  LODWORD(v2[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v3;
  LODWORD(v2[1].mNode.mParent) = v4;
  v5 = sPresentMaterial;
  *(_WORD *)&sPresentMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v5[1].mDebugName[4] = v6;
  v7 = sPresentMaterial;
  LOWORD(sPresentMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v7[2].mNode.mUID = 543723269;
  v7[1].mNumParams = v8;
  v9 = sPresentMaterial;
  LOWORD(sPresentMaterial[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].UFG::qResourceData + 22) = -1958479169;
  LODWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v10;
  *(_DWORD *)&v9[2].mDebugName[28] = 0;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, sPresentMaterial);
}

// File Line: 765
// RVA: 0x4FD10
void UFG::RenderWorld::Init(void)
{
  UFG::qResourceHandle *v0; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  char *v19; // rax
  CullLayer *v20; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v22; // rdi
  UFG::qSymbol *v23; // rax
  UFG::SimObject *v24; // rax
  UFG::RenderContext *mRenderParam; // rbp
  unsigned int v26; // ebx
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  UFG::RenderStageAO *v29; // rax
  UFG::RenderStageShadow *v30; // rax
  UFG::RenderStageSpotShadow *v31; // rax
  UFG::RenderStageHairSkin *v32; // rax
  UFG::RenderStageExposureMetering *v33; // rax
  UFG::RenderStageEnvMap *v34; // rax
  UFG::RenderStageFrameCapture *v35; // rax
  UFG::RenderStageImposters *v36; // rax
  UFG::RenderStageTerrain *v37; // rax
  unsigned int v38; // eax
  unsigned int v39; // eax
  UFG::qResourceData *v40; // rbx
  UFG::qResourceWarehouse *v41; // rax
  unsigned int v42; // eax
  UFG::qResourceData *v43; // rbx
  UFG::qResourceWarehouse *v44; // rax
  unsigned int v45; // eax
  UFG::qResourceData *v46; // rbx
  UFG::qResourceWarehouse *v47; // rax
  unsigned int v48; // eax
  UFG::qResourceData *v49; // rbx
  UFG::qResourceWarehouse *v50; // rax
  unsigned int v51; // eax
  UFG::qResourceData *v52; // rbx
  UFG::qResourceWarehouse *v53; // rax
  unsigned int v54; // eax
  UFG::qResourceData *v55; // rbx
  UFG::qResourceWarehouse *v56; // rax
  unsigned int v57; // eax
  UFG::qResourceData *v58; // rbx
  UFG::qResourceWarehouse *v59; // rax
  unsigned int v60; // eax
  UFG::qResourceData *v61; // rbx
  UFG::qResourceWarehouse *v62; // rax
  unsigned int v63; // eax
  UFG::qResourceData *v64; // rbx
  UFG::qResourceWarehouse *v65; // rax
  unsigned int v66; // eax
  UFG::qResourceData *v67; // rbx
  UFG::qResourceWarehouse *v68; // rax
  unsigned int v69; // eax
  UFG::qResourceData *v70; // rbx
  UFG::qResourceWarehouse *v71; // rax
  unsigned int v72; // eax
  UFG::qResourceData *v73; // rbx
  UFG::qResourceWarehouse *v74; // rax
  unsigned int v75; // eax
  UFG::qResourceData *v76; // rbx
  UFG::qResourceWarehouse *v77; // rax
  unsigned int v78; // eax
  UFG::qResourceData *v79; // rbx
  UFG::qResourceWarehouse *v80; // rax
  unsigned int v81; // eax
  UFG::qResourceData *v82; // rbx
  UFG::qResourceWarehouse *v83; // rax
  unsigned int v84; // eax
  UFG::qResourceData *v85; // rbx
  UFG::qResourceWarehouse *v86; // rax
  unsigned int v87; // ebx
  UFG::qResourceInventory *v88; // rax
  UFG::qResourceWarehouse *v89; // rax
  UFG::qResourceInventory *v90; // rax
  UFG::qResourceWarehouse *v91; // rax
  UFG::qResourceInventory *v92; // rax
  UFG::qResourceWarehouse *v93; // rax
  UFG::qResourceInventory *v94; // rax
  UFG::qResourceWarehouse *v95; // rax
  unsigned int v96; // ebx
  UFG::qResourceInventory *v97; // rax
  UFG::qResourceWarehouse *v98; // rax
  UFG::qResourceWarehouse *v99; // rax
  UFG::qResourceInventory *v100; // rbx
  UFG::qResourceInventoryVtbl *vfptr; // rdi
  unsigned int v102; // eax
  __int64 v103; // rax
  __int64 v104; // rcx
  __int64 v105; // rax
  UFG::qResourceInventory *v106; // rax
  UFG::qResourceWarehouse *v107; // rax
  unsigned int alpha_state_out_uids[10]; // [rsp+40h] [rbp-78h] BYREF
  unsigned int alpha_state_in_uids[20]; // [rsp+68h] [rbp-50h] BYREF
  char *result; // [rsp+C0h] [rbp+8h] BYREF
  char *v111; // [rsp+C8h] [rbp+10h]

  v0 = 0i64;
  Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&AlphaStateNoneHandle, 0x12C800F2u, 0x2782CCE6u, Inventory);
  v3 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v3;
  }
  UFG::qResourceHandle::Init(&AlphaStateNoColourWriteHandle, 0x12C800F2u, 0x91A2DD53, v3);
  v5 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v5;
  }
  UFG::qResourceHandle::Init(&RasterStateNormalHandle, 0x3BC715E0u, 0x20688F05u, v5);
  v7 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v7;
  }
  UFG::qResourceHandle::Init(&RasterStateInvertCullingHandle, 0x3BC715E0u, 0xBC9FAF09, v7);
  v9 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v9;
  }
  UFG::qResourceHandle::Init(&RasterStateNormalDisableWriteHandle, 0x3BC715E0u, 0xF05AB9A5, v9);
  v11 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v11;
  }
  UFG::qResourceHandle::Init(&RasterStateInverseDisableWriteHandle, 0x3BC715E0u, 0x4B6C82C0u, v11);
  v13 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v13;
  }
  UFG::qResourceHandle::Init(&RasterStateDoubleSidedHandle, 0x3BC715E0u, 0x940FB8EC, v13);
  v15 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v15;
  }
  UFG::qResourceHandle::Init(&AlphaStateDeferredPunchThroughHandle, 0x12C800F2u, 0x80EA5501, v15);
  v17 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v17;
  }
  UFG::qResourceHandle::Init(&RasterStateDoubleSidedAlphaHandle, 0x3BC715E0u, 0x418CAF43u, v17);
  v19 = UFG::qMalloc(0x100ui64, "gSceneryCullLayer", 0x8000ui64);
  result = v19;
  if ( v19 )
    CullLayer::CullLayer((CullLayer *)v19, TYPE_CULL, "Scenery Cull Layer");
  else
    v20 = 0i64;
  gSceneryCullLayer = v20;
  Render::SimpleDrawableComponent::mDefaultCullLayer = &gSimpleDrawableCullLayer;
  UFG::CompositeDrawableComponent::mDefaultCullLayer = &gCompositeDrawableCullLayer;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v22 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x80ui64, "SimObject", 0i64, 1u);
  v111 = v22;
  if ( v22 )
  {
    v23 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "RenderWorld::msRenderStagePlugin");
    UFG::SimObject::SimObject((UFG::SimObject *)v22, v23);
  }
  else
  {
    v24 = 0i64;
  }
  UFG::RenderWorld::msRenderStagePlugin = v24;
  Render::GetRenderCallbacks()->mRenderParam = 0i64;
  RenderWorldResize();
  mRenderParam = (UFG::RenderContext *)Render::GetRenderCallbacks()->mRenderParam;
  Render::GetRenderCallbacks()->mResizeRenderBuffersFunc = RenderWorldResize;
  Render::GetRenderCallbacks()->mResizeShadowsFunc = RenderWorldResizeShadows;
  if ( !Render::GetRenderCallbacks()->mChangeTexturePackFunc )
    Render::GetRenderCallbacks()->mChangeTexturePackFunc = RenderWorldChangeTexturePack;
  Render::GetRenderCallbacks()->mChangeLODSettingFunc = RenderWorldChangeLODSettings;
  Render::RenderUtilities::Init(&Render::gRenderUtilities);
  Render::DepthOfField::Init(&Render::gDepthOfField);
  Render::RenderUtilities::Init(&Render::gRenderUtilities);
  Render::DebugProbes::Init();
  v26 = UFG::qStringHash32("Calibri", 0xFFFFFFFF);
  v27 = `UFG::qGetResourceInventory<Render::Font>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    v27 = UFG::qResourceWarehouse::GetInventory(v28, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>::`2::result = v27;
  }
  UFG::qResourceHandle::Init(&gDebugFontHandle, 0x69FCCB4Cu, v26, v27);
  UFG::RenderStageAO::Create(mRenderParam);
  UFG::RenderWorld::msStageAO = v29;
  UFG::RenderStageShadow::Create(mRenderParam);
  UFG::RenderWorld::msStageShadow = v30;
  UFG::RenderStageSpotShadow::Create(mRenderParam);
  UFG::RenderWorld::msStageSpotShadow = v31;
  UFG::RenderStageHairSkin::Create(mRenderParam);
  UFG::RenderWorld::msStageHairSkin = v32;
  UFG::RenderStageExposureMetering::Create(mRenderParam);
  UFG::RenderWorld::msExposureMetering = v33;
  UFG::RenderStageEnvMap::Create(mRenderParam);
  UFG::RenderWorld::msStageEnvMap = v34;
  UFG::RenderStageFrameCapture::Create(
    mRenderParam,
    UFG::RenderStageFrameCapture::sWidth,
    UFG::RenderStageFrameCapture::sHeight);
  UFG::RenderWorld::msStageFrameCapture = v35;
  UFG::RenderStageImposters::Create(mRenderParam);
  UFG::RenderWorld::msStageImposters = v36;
  UFG::RenderStageTerrain::Create(mRenderParam);
  UFG::RenderWorld::msStageTerrain = v37;
  InitDeferredRendering(mRenderParam);
  CullManager::Instance()->mPixelDensityDynamicBias = 3;
  v38 = UFG::qStringHash32("COLOURCUBEBLEND", 0xFFFFFFFF);
  UFG::ColourCubeMgr::Init(v38);
  InitIrradianceCaptureSystem();
  v39 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  v40 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMask_000", v39, 0i64, 0i64, 0i64);
  WORD2(v40[1].mNode.mChild[0]) = 0;
  v41 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v41, v40);
  v42 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_125", 0xFFFFFFFF);
  v43 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_125", v42, 0i64, 0i64, 0i64);
  WORD2(v43[1].mNode.mChild[0]) = 1;
  v44 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v44, v43);
  v45 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_25", 0xFFFFFFFF);
  v46 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_25", v45, 0i64, 0i64, 0i64);
  WORD2(v46[1].mNode.mChild[0]) = 2;
  v47 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v47, v46);
  v48 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_375", 0xFFFFFFFF);
  v49 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_375", v48, 0i64, 0i64, 0i64);
  WORD2(v49[1].mNode.mChild[0]) = 3;
  v50 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v50, v49);
  v51 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_50", 0xFFFFFFFF);
  v52 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_50", v51, 0i64, 0i64, 0i64);
  WORD2(v52[1].mNode.mChild[0]) = 4;
  v53 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v53, v52);
  v54 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_625", 0xFFFFFFFF);
  v55 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_625", v54, 0i64, 0i64, 0i64);
  WORD2(v55[1].mNode.mChild[0]) = 5;
  v56 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v56, v55);
  v57 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_75", 0xFFFFFFFF);
  v58 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_75", v57, 0i64, 0i64, 0i64);
  WORD2(v58[1].mNode.mChild[0]) = 6;
  v59 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v59, v58);
  v60 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_875", 0xFFFFFFFF);
  v61 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_875", v60, 0i64, 0i64, 0i64);
  WORD2(v61[1].mNode.mChild[0]) = 7;
  v62 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v62, v61);
  v63 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_125", 0xFFFFFFFF);
  v64 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_125", v63, 0i64, 0i64, 0i64);
  WORD2(v64[1].mNode.mChild[0]) = 8;
  v65 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v65, v64);
  v66 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_25", 0xFFFFFFFF);
  v67 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_25", v66, 0i64, 0i64, 0i64);
  WORD2(v67[1].mNode.mChild[0]) = 9;
  v68 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v68, v67);
  v69 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_375", 0xFFFFFFFF);
  v70 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_375", v69, 0i64, 0i64, 0i64);
  WORD2(v70[1].mNode.mChild[0]) = 10;
  v71 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v71, v70);
  v72 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_50", 0xFFFFFFFF);
  v73 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_50", v72, 0i64, 0i64, 0i64);
  WORD2(v73[1].mNode.mChild[0]) = 11;
  v74 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v74, v73);
  v75 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_625", 0xFFFFFFFF);
  v76 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_625", v75, 0i64, 0i64, 0i64);
  WORD2(v76[1].mNode.mChild[0]) = 12;
  v77 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v77, v76);
  v78 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_75", 0xFFFFFFFF);
  v79 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_75", v78, 0i64, 0i64, 0i64);
  WORD2(v79[1].mNode.mChild[0]) = 13;
  v80 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v80, v79);
  v81 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_875", 0xFFFFFFFF);
  v82 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_875", v81, 0i64, 0i64, 0i64);
  WORD2(v82[1].mNode.mChild[0]) = 14;
  v83 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v83, v82);
  v84 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  v85 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMask_1000", v84, 0i64, 0i64, 0i64);
  WORD2(v85[1].mNode.mChild[0]) = 15;
  v86 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v86, v85);
  alpha_state_in_uids[0] = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  alpha_state_in_uids[1] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_125", 0xFFFFFFFF);
  alpha_state_in_uids[2] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_25", 0xFFFFFFFF);
  alpha_state_in_uids[3] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_375", 0xFFFFFFFF);
  alpha_state_in_uids[4] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_50", 0xFFFFFFFF);
  alpha_state_in_uids[5] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_625", 0xFFFFFFFF);
  alpha_state_in_uids[6] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_75", 0xFFFFFFFF);
  alpha_state_in_uids[7] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_875", 0xFFFFFFFF);
  alpha_state_in_uids[8] = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  alpha_state_out_uids[0] = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  alpha_state_out_uids[1] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_125", 0xFFFFFFFF);
  alpha_state_out_uids[2] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_25", 0xFFFFFFFF);
  alpha_state_out_uids[3] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_375", 0xFFFFFFFF);
  alpha_state_out_uids[4] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_50", 0xFFFFFFFF);
  alpha_state_out_uids[5] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_625", 0xFFFFFFFF);
  alpha_state_out_uids[6] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_75", 0xFFFFFFFF);
  alpha_state_out_uids[7] = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_875", 0xFFFFFFFF);
  alpha_state_out_uids[8] = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  Render::TransparencySystem::Init((char *)alpha_state_in_uids, (char *)alpha_state_out_uids, 9);
  UFG::Water::Init(0x200u, 6u);
  Render::Skinning::gSkinning.mRenderMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::Mesh *, UFG::qMatrix44 *, Illusion::Material *, UFG::BitFlags128, const char *))SubmitSkinnedMesh;
  Render::Skinning::gSkinning.mRenderRMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::rMesh *, UFG::qMatrix44 *, Illusion::rMaterial *, UFG::BitFlags128, const char *))SubmitSkinnedRMesh;
  Render::Skinning::gSkinning.mRenderDecalFunc = Render::DefaultRenderDecalFunc;
  Render::Skinning::gSkinning.mEnablePersistentCache = 0;
  _((AMD_HD3D *)&Render::gSoftbody);
  v87 = UFG::qStringHashUpper32("ReflectionFadeCube", 0xFFFFFFFF);
  v88 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v89 = UFG::qResourceWarehouse::Instance();
    v88 = UFG::qResourceWarehouse::GetInventory(v89, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v88;
  }
  UFG::qResourceHandle::Init(&gReflectionFadeCube, 0x8B43FABF, v87, v88);
  v90 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v91 = UFG::qResourceWarehouse::Instance();
    v90 = UFG::qResourceWarehouse::GetInventory(v91, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v90;
  }
  UFG::qResourceHandle::Init(&gDefaultBlackTexture, 0x8B43FABF, 0x3218EEB7u, v90);
  v92 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v93 = UFG::qResourceWarehouse::Instance();
    v92 = UFG::qResourceWarehouse::GetInventory(v93, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v92;
  }
  UFG::qResourceHandle::Init(&gDefaultWhiteTexture, 0x8B43FABF, 0xB11369EB, v92);
  v94 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v95 = UFG::qResourceWarehouse::Instance();
    v94 = UFG::qResourceWarehouse::GetInventory(v95, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v94;
  }
  UFG::qResourceHandle::Init(&gDefaultZeroTexture, 0x8B43FABF, 0x1C63FB41u, v94);
  v96 = UFG::qStringHash32("ATAN2", 0xFFFFFFFF);
  v97 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v98 = UFG::qResourceWarehouse::Instance();
    v97 = UFG::qResourceWarehouse::GetInventory(v98, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v97;
  }
  UFG::qResourceHandle::Init(&gArcTanTexture, 0x8B43FABF, v96, v97);
  Illusion::Texture::SetSamplerFilter((Illusion::Texture *)gArcTanTexture.mData, 2u);
  Render::cbLocalTransformState::sStateParamIndex = Illusion::StateSystem::GetParam(
                                                      &Illusion::gStateSystem,
                                                      "cbLocalTransform");
  Render::cbLocalTransformInverseState::sStateParamIndex = Illusion::StateSystem::GetParam(
                                                             &Illusion::gStateSystem,
                                                             "cbLocalTransformInverse");
  Render::cbLocalProjectionState::sStateParamIndex = Illusion::StateSystem::GetParam(
                                                       &Illusion::gStateSystem,
                                                       "cbLocalProjection");
  v99 = UFG::qResourceWarehouse::Instance();
  v100 = UFG::qResourceWarehouse::GetInventory(v99, 0x8B43FABF);
  vfptr = v100->vfptr;
  v102 = UFG::qStringHashUpper32(gDepthVolumeTexture, 0xFFFFFFFF);
  v103 = (__int64)vfptr->Get(v100, v102);
  v104 = v103;
  if ( v103 )
  {
    v105 = *(_QWORD *)(v103 + 112);
    if ( v105 )
      v0 = (UFG::qResourceHandle *)(v105 + v104 + 112);
    v106 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v107 = UFG::qResourceWarehouse::Instance();
      v106 = UFG::qResourceWarehouse::GetInventory(v107, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v106;
    }
    UFG::qResourceHandle::Init(v0 + 1, 0x3BC715E0u, 0x20688F05u, v106);
  }
  Render::CloudVolumeManager::Init(&Render::gCloudVolumeManager, mRenderParam);
  InitBackBufferToPresentBuffer();
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]++] = UFG::TestDynamicSceneryForDecals;
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]++] = UFG::TestSceneryGroupForDecals;
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]++] = UFG::TestCompositeDrawableForDecals;
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]++] = Render::TestSimpleDrawableForDecals;
}

// File Line: 1025
// RVA: 0x56A70
void __fastcall RenderMouse(Render::View *view)
{
  unsigned int v2; // eax
  unsigned int v3; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::Controller *v6; // rcx
  UFG::WayFinderClient *p_mInputState; // rbx
  float mWidth; // xmm6_4
  float mHeight; // xmm7_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  UFG::WayGraph *v12; // rdx
  signed __int16 WayEdge; // ax
  float v14; // xmm14_4
  float v15; // xmm0_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  UFG::qVector2 p1; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector2 p0; // [rsp+38h] [rbp-B0h] BYREF
  __int64 v20; // [rsp+40h] [rbp-A8h]
  Render::Poly poly; // [rsp+F8h] [rbp+10h] BYREF
  UFG::qVector2 p3; // [rsp+100h] [rbp+18h] BYREF
  UFG::qVector2 p2; // [rsp+108h] [rbp+20h] BYREF

  v20 = -2i64;
  v2 = _S15;
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&gCursorTextureHandle);
    atexit(RenderMouse_::_2_::_dynamic_atexit_destructor_for__gCursorTextureHandle__);
    v2 = _S15;
  }
  if ( !gCursorTextureHandleInitialized )
  {
    if ( (v2 & 2) != 0 )
    {
      v3 = uidDefaultCursor;
    }
    else
    {
      _S15 = v2 | 2;
      v3 = UFG::qStringHashUpper32("DefaultCursor", 0xFFFFFFFF);
      uidDefaultCursor = v3;
    }
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&gCursorTextureHandle, 0x8B43FABF, v3, Inventory);
  }
  if ( gCursorTextureHandle.mData )
  {
    v6 = UFG::gInputSystem->mControllers[0];
    if ( v6 )
    {
      p_mInputState = (UFG::WayFinderClient *)&v6->mInputState;
      if ( UFG::InputState::IsMouseVisible(&v6->mInputState) )
      {
        Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
        mWidth = (float)Render::GetBackBufferTarget()->mWidth;
        mHeight = (float)Render::GetBackBufferTarget()->mHeight;
        v10 = (float)WORD2(gCursorTextureHandle.mData[1].mNode.mChild[0]);
        v11 = (float)HIWORD(gCursorTextureHandle.mData[1].mNode.mChild[0]);
        WayEdge = UFG::WayFinderClient::GetWayEdge(p_mInputState, v12);
        v14 = (float)WayEdge * (float)(1.0 / mWidth);
        v15 = (float)(__int16)UFG::WayFinderClient::GetWayNode(p_mInputState, (UFG::WayGraph *)(unsigned int)WayEdge)
            * (float)(1.0 / mHeight);
        v16 = (float)(1.0 / mWidth) * v10;
        v17 = (float)(1.0 / mHeight) * v11;
        if ( v14 >= 0.0 )
        {
          p0.x = v14;
          p0.y = v15;
          p1.x = v16 + v14;
          p1.y = v15;
          p2.x = v16 + v14;
          p2.y = v17 + v15;
          p3.x = v14;
          p3.y = v17 + v15;
          Render::Poly::SetScreenPos(&poly, &p0, &p1, &p2, &p3, 0.0);
          Render::Poly::SetUVs(
            &poly,
            (float)(1.0 / v10) * 0.5,
            (float)(1.0 / v11) * 0.5,
            (float)(1.0 - (float)((float)(1.0 / v10) * 0.5)) - (float)((float)(1.0 / v10) * 0.5),
            (float)(1.0 - (float)((float)(1.0 / v11) * 0.5)) - (float)((float)(1.0 / v11) * 0.5));
          Render::View::Draw(view, &poly, gCursorTextureHandle.mNameUID, 0i64, 0x62F81854u, 0);
        }
      }
    }
  }
}

// File Line: 1160
// RVA: 0x56E30
void __fastcall RenderPlanarReflectionDebug(Render::View *view, UFG::RenderContext *render_context)
{
  UFG::Reflection *mReflection; // r15
  Render::DebugDrawContext *Context; // rdi
  float v5; // xmm4_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v8; // xmm5_4
  float x; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  double world_position; // [rsp+48h] [rbp-19h] BYREF
  double world_position_8; // [rsp+50h] [rbp-11h]
  UFG::qVector3 p1; // [rsp+58h] [rbp-9h] BYREF
  UFG::DrawInfo info; // [rsp+68h] [rbp+7h] BYREF

  mReflection = render_context->mReflection;
  if ( gShowPlanarReflectionDbg )
  {
    if ( mReflection )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              3u);
      v5 = mReflection->mVolume.mPosMinWorld.z
         + (float)((float)(mReflection->mVolume.mPosMaxWorld.z - mReflection->mVolume.mPosMinWorld.z) * 0.5);
      y = mReflection->mVolume.mPosMaxWorld.y;
      z = mReflection->mVolume.mPosMinWorld.z;
      v8 = mReflection->mVolume.mPosMinWorld.y + (float)((float)(y - mReflection->mVolume.mPosMinWorld.y) * 0.5);
      x = mReflection->mVolume.mPosMaxWorld.x;
      *(float *)&world_position = mReflection->mVolume.mPosMinWorld.x
                                + (float)((float)(x - mReflection->mVolume.mPosMinWorld.x) * 0.5);
      v10 = mReflection->mVolume.mPosMaxWorld.z;
      *(float *)&world_position_8 = v5;
      v11 = mReflection->mVolume.mPosMinWorld.y;
      *((float *)&world_position + 1) = v8;
      v12 = mReflection->mVolume.mPosMinWorld.x;
      world_position_8 = v10;
      world_position = y;
      Render::DebugDrawContext::DrawText(
        Context,
        (UFG::qVector3 *)&world_position,
        &UFG::qColour::White,
        "Planar reflection: %s\nAABB: %f,%f,%f - %f,%f,%f",
        mReflection->mName,
        v12,
        v11,
        z,
        x);
      Render::DebugDrawContext::DrawTextA(
        Context,
        5,
        5,
        &UFG::qColour::White,
        "Planar reflection %s",
        mReflection->mName);
      info.mAlphaBlend = AlphaState_modulated;
      *(_WORD *)&info.mDepthBuffer = 256;
      info.mDepthBias = 0;
      info.mPreDrawCallback = 0i64;
      info.mColour1 = UFG::qColour::White;
      LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
      info.mColour2 = UFG::qColour::White;
      Render::View::DrawBox(
        view,
        &mReflection->mVolume.mPosMinWorld,
        &mReflection->mVolume.mPosMaxWorld,
        &info,
        &UFG::qMatrix44::msIdentity);
      v13 = mReflection->mPlane.mPosition.y + mReflection->mPlane.mNormal.y;
      p1.x = mReflection->mPlane.mNormal.x + mReflection->mPlane.mPosition.x;
      v14 = mReflection->mPlane.mPosition.z + mReflection->mPlane.mNormal.z;
      p1.y = v13;
      p1.z = v14;
      Render::View::DrawArrow(view, &mReflection->mPlane.mPosition, &p1, &info, &UFG::qMatrix44::msIdentity);
    }
  }
}

// File Line: 1375
// RVA: 0x53C40
void __fastcall RenderDebugOverlay(UFG::RenderContext *render_context, Render::View *view)
{
  AMD_HD3D *v4; // rax
  unsigned int v5; // ebx
  UFG::PartCompositeBuilder *v6; // rax
  unsigned int mVolumeTextureUID; // ebx
  Render::Poly poly; // [rsp+70h] [rbp+8h] BYREF

  v4 = (AMD_HD3D *)CullManager::Instance();
  _(v4);
  if ( g_renderMouse && !UFG::InputSystem::msShouldHideCursor )
    RenderMouse(view);
  UFG::RenderStageEnvMap::RenderDebugOverlay(UFG::RenderWorld::msStageEnvMap, render_context, view);
  if ( UFG::RenderWorld::msStageShadow->mDrawDebugShadowMap && render_context->mRenderFeatures.mWorld )
    UFG::RenderStageShadow::RenderDebugOverlay(UFG::RenderWorld::msStageShadow, render_context, view, 20, 20, 250);
  if ( UFG::RenderWorld::msStageSpotShadow->mDrawDebugSpotShadowMap && render_context->mRenderFeatures.mWorld )
    UFG::RenderStageSpotShadow::RenderDebugSpotShadowOverlay(
      UFG::RenderWorld::msStageSpotShadow,
      render_context,
      view,
      20,
      20,
      250);
  if ( UFG::RenderWorld::msCalibrationDisplay )
  {
    v5 = UFG::qStringHash32("CALIBRATION", 0xFFFFFFFF);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(view, &poly, v5, 0i64, 0, 0);
  }
  RenderPlanarReflectionDebug(view, render_context);
  v6 = UFG::PartCompositeBuilder::Instance();
  UFG::PartCompositeBuilder::RenderDebugOverlay(v6, view);
  if ( gDebugTextureUID )
  {
    Render::Poly::Poly(&poly, 0.0, 0.0, 0.140625, 0.25, 0.0);
    Render::View::Draw(view, &poly, gDebugTextureUID, 0i64, 0, 0);
  }
  if ( gDebugVolumeTextureUID )
  {
    Render::View::SetSimpleMaterialShader(0x53F37232u);
    Render::Poly::Poly(&poly, 0.1, 0.1, 0.140625, 0.25, 0.0);
    Render::View::Draw(view, &poly, gDebugVolumeTextureUID, 0i64, 0, 0);
    Render::View::SetSimpleMaterialShader(0x3141335Cu);
  }
  mVolumeTextureUID = Render::gCloudVolumeManager.mVolumeTextureUID;
  if ( (unsigned int)UFG::qStringHashUpper32("cloudvolumetex", 0xFFFFFFFF) != mVolumeTextureUID )
  {
    Render::View::SetSimpleMaterialShader(0x53F37232u);
    Render::Poly::Poly(&poly, 0.1, 0.80000001, 0.1, 0.17777778, 0.0);
    Render::View::Draw(view, &poly, Render::gCloudVolumeManager.mVolumeTextureUID, 0i64, 0, 0);
    Render::View::SetSimpleMaterialShader(0x3141335Cu);
  }
  UFG::RenderStageExposureMetering::RenderDebug(UFG::RenderWorld::msExposureMetering, render_context, view);
}

// File Line: 1542
// RVA: 0x58600
void __fastcall RenderScaleformCallback(unsigned int *param)
{
  Scaleform::Ptr<Scaleform::Render::Renderer2D> *v1; // rax
  Scaleform::Ptr<Scaleform::Render::Renderer2D> *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // [rsp+48h] [rbp+10h] BYREF

  v1 = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(UFG::UIScreenManager::s_instance, &v3);
  Scaleform::Render::Renderer2D::BeginFrame(v1->pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  UFG::UIScreenManager::s_instance->vfptr->render(UFG::UIScreenManager::s_instance);
  v2 = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(UFG::UIScreenManager::s_instance, &v3);
  Scaleform::Render::Renderer2D::EndFrame(v2->pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
}

// File Line: 1558
// RVA: 0x56D80
void __fastcall RenderMoviesOffscreen(UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  RenderQueueLayer v2; // [rsp+30h] [rbp-D68h] BYREF
  LayerSubmitContext ptr; // [rsp+110h] [rbp-C88h] BYREF

  RenderQueueLayer::RenderQueueLayer(&v2);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v2.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v2;
  ptr.mQueueMode = QM_Single;
  UFG::MovieHandler::RenderOffScreen(&UFG::TheMovieHandler, &ptr);
  RenderQueueLayer::SerializeRenderQueues(&v2);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v2);
}

// File Line: 1581
// RVA: 0x4DB40
UFG::Reflection *__fastcall FindPlanarReflection(UFG::qVector3 *camPos)
{
  UFG::qBaseNodeRB *Head; // r8
  unsigned int mUID; // r10d
  unsigned int v4; // edx
  UFG::qBaseNodeRB *mParent; // r9
  float x; // xmm1_4
  __int64 v7; // rcx
  __int64 v8; // rax
  UFG::Reflection *result; // rax
  float y; // xmm0_4
  float z; // xmm0_4

  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9760);
  if ( !Head )
    return 0i64;
  while ( 1 )
  {
    mUID = Head[2].mUID;
    v4 = 0;
    if ( mUID )
      break;
LABEL_14:
    Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9760, Head);
    if ( !Head )
      return 0i64;
  }
  mParent = Head[3].mParent;
  x = camPos->x;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = mParent ? (__int64)&Head[3] + (_QWORD)mParent : 0i64;
    result = (UFG::Reflection *)(v7 + v8);
    if ( x >= result->mVolume.mPosMinWorld.x && x <= result->mVolume.mPosMaxWorld.x )
    {
      y = camPos->y;
      if ( y >= result->mVolume.mPosMinWorld.y && y <= result->mVolume.mPosMaxWorld.y )
      {
        z = camPos->z;
        if ( z >= result->mVolume.mPosMinWorld.z && z <= result->mVolume.mPosMaxWorld.z )
          return result;
      }
    }
    ++v4;
    v7 += 224i64;
    if ( v4 >= mUID )
      goto LABEL_14;
  }
}

// File Line: 1602
// RVA: 0x570A0
void __fastcall RenderPlanarReflectionMap(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::Reflection *mReflection; // rsi
  float z; // xmm10_4
  float y; // xmm9_4
  float x; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  UFG::qMatrix44 *v13; // rax
  UFG::qMatrix44 *v14; // rax
  int v15; // xmm9_4
  int v16; // xmm8_4
  int v17; // xmm6_4
  float v18; // xmm7_4
  UFG::qMatrix44 *v19; // rax
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm13_4
  float v23; // xmm14_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  char *v27; // rdi
  int x_low; // xmm7_4
  int y_low; // xmm3_4
  int z_low; // xmm4_4
  float v31; // xmm2_4
  float v32; // xmm8_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm4_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm6_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  Illusion::StateArgs *StateArgs; // rax
  float *mShadowFilterWidth; // rbx
  float *mBiases; // r15
  float *mCutplanes; // r12
  unsigned __int16 Param; // ax
  Illusion::StateArgs *v52; // rax
  UFG::qResourceData *mData; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::Texture *v55; // rbx
  Illusion::StateValues *v56; // rax
  Illusion::StateValues *v57; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v60; // rbx
  Illusion::StateValues *v61; // rax
  UFG::qResourceData *v62; // rbx
  Illusion::StateValues *v63; // rax
  Illusion::Texture *mHalfSizeShadowAliasTexture; // rbx
  Illusion::StateValues *v65; // rax
  Illusion::Texture *RippleMap; // rbx
  Illusion::StateValues *v67; // rax
  CB_WaterOffset *WaterSettings; // rbx
  Illusion::StateValues *v69; // rax
  char *v70; // rbx
  float v71; // xmm1_4
  float v72; // xmm2_4
  float w; // xmm3_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm3_4
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm3_4
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm3_4
  Illusion::StateValues *v83; // rax
  UFG::qResourceWarehouse *v84; // rax
  UFG::qResourceInventory *Inventory; // rbx
  UFG::qResourceInventoryVtbl *vfptr; // rdi
  unsigned int v87; // eax
  Illusion::Texture *v88; // rbx
  Illusion::StateValues *v89; // rax
  float *v90; // rbx
  Illusion::StateValues *v91; // rax
  char *v92; // rax
  unsigned int mSceneryGroupUID; // ebx
  UFG::qResourceInventory *v94; // rax
  UFG::qResourceWarehouse *v95; // rax
  UFG::qResourceInventory *v96; // rax
  UFG::qResourceWarehouse *v97; // rax
  UFG::DynamicSceneryInstance *p_mNext; // rcx
  Render::ViewSettings *mSettings; // rdx
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v100; // rbx
  __int64 mCullIndex; // rax
  float v102; // xmm0_4
  float v103; // xmm0_4
  float v104; // xmm0_4
  UFG::CompositeDrawableComponent *v105; // rbx
  UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *v106; // rdi
  CullResults *mCullResults; // rcx
  __int64 v108; // rax
  float v109; // xmm0_4
  float v110; // xmm0_4
  float v111; // xmm0_4
  CullInfo *mCullInfo; // rax
  unsigned int LOD; // eax
  Illusion::StateArgs *v114; // r8
  __int64 v115; // rdx
  _QWORD *v116; // rcx
  Illusion::StateArgs *v117; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v120; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v121; // rax
  __int64 v122; // rcx
  _QWORD *v123; // rax
  char *v124; // rax
  UFG::qMatrix44 v125; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 b; // [rsp+90h] [rbp-70h] BYREF
  Render::cbShadowTransformState v127; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qMatrix44 v128; // [rsp+130h] [rbp+30h] BYREF
  UFG::qMatrix44 dest; // [rsp+170h] [rbp+70h] BYREF
  __int64 v130[4]; // [rsp+1B0h] [rbp+B0h] BYREF
  Render::ViewSettings settings; // [rsp+1D0h] [rbp+D0h] BYREF
  Render::View view; // [rsp+260h] [rbp+160h] BYREF
  UFG::qMatrix44 v133; // [rsp+3F0h] [rbp+2F0h] BYREF
  UFG::qMatrix44 m; // [rsp+430h] [rbp+330h] BYREF
  RenderQueueLayer v135; // [rsp+470h] [rbp+370h] BYREF
  UFG::qMatrix44 d; // [rsp+550h] [rbp+450h] BYREF
  UFG::qMatrix44 result; // [rsp+590h] [rbp+490h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+5D0h] [rbp+4D0h] BYREF
  ForwardReflectedSubmitContext ptr; // [rsp+7D0h] [rbp+6D0h] BYREF
  Render::CullMetrics cull_metrics; // [rsp+1530h] [rbp+1430h] BYREF

  v130[2] = -2i64;
  if ( render_context->mReflection && gRenderPlanarReflections )
  {
    RenderQueueLayer::RenderQueueLayer(&v135);
    ForwardReflectedSubmitContext::ForwardReflectedSubmitContext(&ptr);
    v135.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v135;
    v130[1] = (__int64)AlphaStateNoneHandle.mData;
    v130[0] = (__int64)RasterStateNormalHandle.mData;
    ptr.mPerPhaseParams = (ForwardReflectedSubmitContext::PerPhaseParams *)v130;
    ptr.mQueueMode = QM_GBuffer;
    UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
    mReflection = render_context->mReflection;
    v125.v0 = UFG::qMatrix44::msIdentity.v0;
    v125.v1 = UFG::qMatrix44::msIdentity.v1;
    v125.v2 = UFG::qMatrix44::msIdentity.v2;
    z = mReflection->mPlane.mPosition.z;
    y = mReflection->mPlane.mPosition.y;
    x = mReflection->mPlane.mPosition.x;
    LODWORD(v125.v3.x) = LODWORD(x) ^ _xmm[0];
    LODWORD(v125.v3.y) = LODWORD(y) ^ _xmm[0];
    LODWORD(v125.v3.z) = LODWORD(z) ^ _xmm[0];
    v125.v3.w = 1.0;
    v8 = mReflection->mPlane.mNormal.y;
    v9 = mReflection->mPlane.mNormal.x;
    v10 = v9 * v9;
    v11 = mReflection->mPlane.mNormal.z;
    b.v0.x = (float)((float)(v8 * v8) - (float)(v9 * v9)) + (float)(v11 * v11);
    v12 = v9 * -2.0;
    b.v0.y = v12 * v8;
    b.v0.z = v12 * v11;
    b.v0.w = 0.0;
    b.v1.x = v12 * v8;
    b.v1.y = (float)(v10 - (float)(v8 * v8)) + (float)(v11 * v11);
    b.v1.z = (float)(v8 * -2.0) * v11;
    b.v1.w = 0.0;
    b.v2.x = v12 * v11;
    b.v2.y = b.v1.z;
    b.v2.z = (float)(v10 + (float)(v8 * v8)) - (float)(v11 * v11);
    b.v2.w = 0.0;
    b.v3.x = UFG::qVector3::msZero.x;
    b.v3.y = UFG::qVector3::msZero.y;
    b.v3.z = UFG::qVector3::msZero.z;
    b.v3.w = 1.0;
    v128.v0 = UFG::qMatrix44::msIdentity.v0;
    v128.v1 = UFG::qMatrix44::msIdentity.v1;
    v128.v2 = UFG::qMatrix44::msIdentity.v2;
    v128.v3.x = x;
    v128.v3.y = y;
    v128.v3.z = z;
    v128.v3.w = 1.0;
    v13 = UFG::qMatrix44::operator*(&v125, &result, &b);
    v14 = UFG::qMatrix44::operator*(v13, (UFG::qMatrix44 *)&v127, &v128);
    UFG::qMatrix44::operator*(v14, &v125, &render_context->mMainViewSettings.mWorldView);
    v15 = LODWORD(mReflection->mPlane.mNormal.z) ^ _xmm[0];
    v16 = LODWORD(mReflection->mPlane.mNormal.y) ^ _xmm[0];
    v17 = LODWORD(mReflection->mPlane.mNormal.x) ^ _xmm[0];
    LODWORD(v18) = COERCE_UNSIGNED_INT(
                     (float)((float)(*(float *)&v16 * mReflection->mPlane.mPosition.y)
                           + (float)(*(float *)&v17 * mReflection->mPlane.mPosition.x))
                   + (float)(*(float *)&v15 * mReflection->mPlane.mPosition.z)) ^ _xmm[0];
    v19 = UFG::qMatrix44::operator*(
            &render_context->mMainViewSettings.mWorldView,
            (UFG::qMatrix44 *)&v127,
            &render_context->mMainViewSettings.mProjection);
    UFG::qInverse(&m, v19);
    UFG::qTranspose(&dest, &m);
    v20 = (float)((float)((float)(dest.v0.x * *(float *)&v17) + (float)(*(float *)&v16 * dest.v1.x))
                + (float)(*(float *)&v15 * dest.v2.x))
        + (float)(dest.v3.x * v18);
    v21 = (float)((float)((float)(dest.v0.y * *(float *)&v17) + (float)(*(float *)&v16 * dest.v1.y))
                + (float)(*(float *)&v15 * dest.v2.y))
        + (float)(dest.v3.y * v18);
    v22 = (float)((float)((float)(dest.v0.z * *(float *)&v17) + (float)(*(float *)&v16 * dest.v1.z))
                + (float)(*(float *)&v15 * dest.v2.z))
        + (float)(dest.v3.z * v18);
    v23 = (float)((float)((float)(dest.v0.w * *(float *)&v17) + (float)(*(float *)&v16 * dest.v1.w))
                + (float)(*(float *)&v15 * dest.v2.w))
        + (float)(dest.v3.w * v18);
    v24 = (float)render_context->mReflectionTarget->mWidth / (float)render_context->mReflectionTarget->mHeight;
    v25 = render_context->mMainViewSettings.mProjection.v0.x;
    if ( v25 == 0.0 )
      v26 = 0.0;
    else
      v26 = atan2f(1.0, v25) * 2.0;
    UFG::qPerspectiveMatrix(&v133, v26, v24, 0.30000001, 50.0);
    settings.mWorldView = v125;
    settings.mProjection = v133;
    settings.mCullIndex = -1;
    settings.mCullPixelDensityThreshold = render_context->mMainViewSettings.mCullPixelDensityThreshold;
    settings.mCullPixelDistanceBias = render_context->mMainViewSettings.mCullPixelDistanceBias;
    Render::View::View(&view, &settings, &ptr);
    Render::View::BeginTarget(&view, render_context->mReflectionTarget, "PlanarReflection", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 3u, 1.0, 0);
    if ( gReflectionFadeCube.mData )
    {
      *(_QWORD *)&v128.v0.x = 0i64;
      *(_QWORD *)&v128.v0.z = 0i64;
      v128.v2.x = 0.0;
      *(_QWORD *)&v128.v1.z = -1i64;
      *(_QWORD *)&v128.v1.x = 0xFFFFFFF7FFFBFFFFui64;
      ptr.mShaderSelector = (Illusion::ShaderSelector *)&v128;
      v27 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
      UFG::qMemCopy(v27, render_context->mEnvState, 0x100u);
      if ( (mReflection->mFlags & 1) != 0 )
      {
        x_low = SLODWORD(mReflection->mLightDirectionOverride.x);
        y_low = SLODWORD(mReflection->mLightDirectionOverride.y);
        z_low = SLODWORD(mReflection->mLightDirectionOverride.z);
      }
      else
      {
        z_low = *((_DWORD *)v27 + 6) ^ _xmm[0];
        y_low = *((_DWORD *)v27 + 5) ^ _xmm[0];
        x_low = *((_DWORD *)v27 + 4) ^ _xmm[0];
      }
      v31 = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(*(float *)&x_low * *(float *)&x_low))
          + (float)(*(float *)&z_low * *(float *)&z_low);
      if ( v31 == 0.0 )
        v32 = 0.0;
      else
        v32 = 1.0 / fsqrt(v31);
      v33 = v32 * *(float *)&z_low;
      v34 = v32 * *(float *)&y_low;
      v35 = *(float *)&x_low * v32;
      v36 = (float)((float)((float)(v32 * *(float *)&y_low) * b.v1.x) + (float)(v35 * b.v0.x))
          + (float)((float)(v32 * *(float *)&z_low) * b.v2.x);
      v37 = (float)((float)((float)(v32 * *(float *)&y_low) * b.v1.y) + (float)(v35 * b.v0.y)) + (float)(v33 * b.v2.y);
      v38 = (float)((float)(v34 * b.v1.z) + (float)(v35 * b.v0.z)) + (float)(v33 * b.v2.z);
      *((float *)v27 + 4) = v36;
      *((float *)v27 + 5) = v37;
      *((float *)v27 + 6) = v38;
      *((_DWORD *)v27 + 7) = 0;
      v39 = (float)((float)((float)(v34 * view.mSettings->mWorldView.v1.x)
                          + (float)(v35 * view.mSettings->mWorldView.v0.x))
                  + (float)(v33 * view.mSettings->mWorldView.v2.x))
          + (float)(view.mSettings->mWorldView.v3.x * 0.0);
      v40 = (float)((float)((float)(v34 * view.mSettings->mWorldView.v1.y)
                          + (float)(v35 * view.mSettings->mWorldView.v0.y))
                  + (float)(v33 * view.mSettings->mWorldView.v2.y))
          + (float)(view.mSettings->mWorldView.v3.y * 0.0);
      v41 = (float)((float)((float)(v34 * view.mSettings->mWorldView.v1.z)
                          + (float)(v35 * view.mSettings->mWorldView.v0.z))
                  + (float)(v33 * view.mSettings->mWorldView.v2.z))
          + (float)(view.mSettings->mWorldView.v3.z * 0.0);
      v42 = (float)((float)((float)(v34 * view.mSettings->mWorldView.v1.w)
                          + (float)(v35 * view.mSettings->mWorldView.v0.w))
                  + (float)(v33 * view.mSettings->mWorldView.v2.w))
          + (float)(view.mSettings->mWorldView.v3.w * 0.0);
      *(float *)v27 = v39;
      *((float *)v27 + 1) = v40;
      *((float *)v27 + 2) = v41;
      *((float *)v27 + 3) = v42;
      if ( (mReflection->mFlags & 2) != 0 )
      {
        v43 = mReflection->mLightColorOverride.y;
        v44 = mReflection->mLightColorOverride.z;
        *((_DWORD *)v27 + 8) = LODWORD(mReflection->mLightColorOverride.x);
        *((float *)v27 + 9) = v43;
        *((float *)v27 + 10) = v44;
        *((_DWORD *)v27 + 11) = 0;
      }
      v45 = mReflection->mAmbientColor.y;
      v46 = mReflection->mAmbientColor.z;
      *((_DWORD *)v27 + 12) = LODWORD(mReflection->mAmbientColor.x);
      *((float *)v27 + 13) = v45;
      *((float *)v27 + 14) = v46;
      *((_DWORD *)v27 + 15) = 1065353216;
      *((_DWORD *)v27 + 40) = 0;
      *((float *)v27 + 41) = gPlanarFogEnd;
      Render::cbExternalViewTransformState::cbExternalViewTransformState(
        (Render::cbExternalViewTransformState *)&v125,
        &view.mSettings->mWorldView,
        &view.mSettings->mProjection);
      StateArgs = Render::View::GetStateArgs(&view);
      Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(
        StateArgs,
        (Render::cbExternalViewTransformState *)&v125);
      UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
      mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
      mBiases = UFG::RenderWorld::msStageShadow->mBiases;
      mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
      v127.mPrev = &v127;
      v127.mNext = &v127;
      v127.mCallback = 0i64;
      v127.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
      *(_WORD *)&v127.mFlags = 1;
      if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
      {
        Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
        Render::cbShadowTransformState::sStateParamIndex = Param;
        v127.mStateParamIndex = Param;
      }
      v127.mViewWorld = &view.mViewWorld;
      v127.mWorldView = (UFG::qMatrix44 *)&views;
      v127.mProjection = views.mProjection;
      v127.mCutplanes = mCutplanes;
      v127.mBiases = mBiases;
      v127.mBlurWidths = mShadowFilterWidth;
      v127.mCached_Remote.m_Stream = 0i64;
      v52 = Render::View::GetStateArgs(&view);
      Illusion::StateArgs::Set<Render::cbShadowTransformState>(v52, &v127);
      mData = gReflectionFadeCube.mData;
      StateValues = Render::View::GetStateValues(&view);
      StateValues->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
      StateValues->mParamValues[41] = mData;
      v55 = render_context->mEnvCubeMap->mTarget->mTargetTexture[0];
      v56 = Render::View::GetStateValues(&view);
      v56->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
      v56->mParamValues[40] = v55;
      v57 = Render::View::GetStateValues(&view);
      v57->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
      v57->mParamValues[55] = v27;
      mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
      mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
      v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *(float *)v60 = mSimTime_Temp;
      *((float *)v60 + 1) = mSimTimeDelta;
      v61 = Render::View::GetStateValues(&view);
      v61->mSetValueMask.mFlags[0] |= 0x2000ui64;
      v61->mParamValues[13] = v60;
      v62 = gArcTanTexture.mData;
      v63 = Render::View::GetStateValues(&view);
      v63->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
      v63->mParamValues[43] = v62;
      mHalfSizeShadowAliasTexture = render_context->mHalfSizeShadowAliasTexture;
      v65 = Render::View::GetStateValues(&view);
      v65->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
      v65->mParamValues[61] = mHalfSizeShadowAliasTexture;
      RippleMap = UFG::Water::GetRippleMap(1);
      v67 = Render::View::GetStateValues(&view);
      v67->mSetValueMask.mFlags[0] |= 0x800000000000000ui64;
      v67->mParamValues[59] = RippleMap;
      WaterSettings = UFG::Water::GetWaterSettings();
      v69 = Render::View::GetStateValues(&view);
      v69->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
      v69->mParamValues[45] = WaterSettings;
      v70 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      v71 = UFG::qVector4::msOne.y;
      v72 = UFG::qVector4::msOne.z;
      w = UFG::qVector4::msOne.w;
      *(float *)v70 = UFG::qVector4::msOne.x;
      *((float *)v70 + 1) = v71;
      *((float *)v70 + 2) = v72;
      *((float *)v70 + 3) = w;
      v74 = UFG::qVector4::msOne.y;
      v75 = UFG::qVector4::msOne.z;
      v76 = UFG::qVector4::msOne.w;
      *((_DWORD *)v70 + 4) = LODWORD(UFG::qVector4::msOne.x);
      *((float *)v70 + 5) = v74;
      *((float *)v70 + 6) = v75;
      *((float *)v70 + 7) = v76;
      v77 = UFG::qVector4::msZero.y;
      v78 = UFG::qVector4::msZero.z;
      v79 = UFG::qVector4::msZero.w;
      *((_DWORD *)v70 + 12) = LODWORD(UFG::qVector4::msZero.x);
      *((float *)v70 + 13) = v77;
      *((float *)v70 + 14) = v78;
      *((float *)v70 + 15) = v79;
      v80 = UFG::qVector4::msZero.y;
      v81 = UFG::qVector4::msZero.z;
      v82 = UFG::qVector4::msZero.w;
      *((_DWORD *)v70 + 8) = LODWORD(UFG::qVector4::msZero.x);
      *((float *)v70 + 9) = v80;
      *((float *)v70 + 10) = v81;
      *((float *)v70 + 11) = v82;
      v83 = Render::View::GetStateValues(&view);
      v83->mSetValueMask.mFlags[0] |= 0x400000000ui64;
      v83->mParamValues[34] = v70;
      v84 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v84, 0x8B43FABF);
      vfptr = Inventory->vfptr;
      v87 = UFG::qStringHashUpper32(render_context->mReflection->mName, 0xFFFFFFFF);
      v88 = (Illusion::Texture *)vfptr->Get(Inventory, v87);
      if ( !v88 )
        v88 = render_context->mSphericalEnvMapTarget->mTargetTexture[0];
      v89 = Render::View::GetStateValues(&view);
      v89->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
      v89->mParamValues[58] = v88;
      v90 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *v90 = v20;
      v90[1] = v21;
      v90[2] = v22;
      v90[3] = v23;
      v91 = Render::View::GetStateValues(&view);
      v91->mSetValueMask.mFlags[0] |= 0x100000000ui64;
      v91->mParamValues[32] = v90;
      v92 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x64u, 4u);
      cull_metrics = (Render::CullMetrics)v92;
      if ( v92 )
        *(_DWORD *)v92 = 1;
      else
        v92 = 0i64;
      *((float *)v92 + 1) = v20;
      *((float *)v92 + 2) = v21;
      *((float *)v92 + 3) = v22;
      *((float *)v92 + 4) = v23;
      LayerSubmitContext::AddRenderCommand(&ptr, 24, 0, v92);
      if ( mReflection->mSceneryGroupUID )
      {
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&b);
        mSceneryGroupUID = mReflection->mSceneryGroupUID;
        v94 = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
        {
          v95 = UFG::qResourceWarehouse::Instance();
          v94 = UFG::qResourceWarehouse::GetInventory(v95, 0xF0A07244);
          `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = v94;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&b, 0xF0A07244, mSceneryGroupUID, v94);
        if ( *(_QWORD *)&b.v1.x )
          UFG::SceneryGroupComponent::Draw(*(UFG::SceneryGroupComponent **)(*(_QWORD *)&b.v1.x + 136i64), &view);
        v96 = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
        {
          v97 = UFG::qResourceWarehouse::Instance();
          v96 = UFG::qResourceWarehouse::GetInventory(v97, 0xF0A07244);
          `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = v96;
        }
        UFG::qResourceHandle::Close((UFG::qResourceHandle *)&b, v96);
        UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&b);
      }
      p_mNext = (UFG::DynamicSceneryInstance *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
      mSettings = view.mSettings;
      if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
      {
        do
        {
          v100 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&p_mNext->mNext[-6].mNext;
          if ( (p_mNext->m_Flags & 3) == 1 )
          {
            mCullIndex = mSettings->mCullIndex;
            if ( (int)mCullIndex >= 6
              || p_mNext->mCullResults->mDistance[mCullIndex] < 20.0
              || (v102 = p_mNext->mLocalWorld.v3.x, v102 >= mReflection->mVolume.mPosMinWorld.x)
              && v102 <= mReflection->mVolume.mPosMaxWorld.x
              && (v103 = p_mNext->mLocalWorld.v3.y, v103 >= mReflection->mVolume.mPosMinWorld.y)
              && v103 <= mReflection->mVolume.mPosMaxWorld.y
              && (v104 = p_mNext->mLocalWorld.v3.z, v104 >= mReflection->mVolume.mPosMinWorld.z)
              && v104 <= mReflection->mVolume.mPosMaxWorld.z )
            {
              if ( (float)((float)((float)((float)(p_mNext->mLocalWorld.v3.y - mReflection->mPlane.mPosition.y)
                                         * mReflection->mPlane.mNormal.y)
                                 + (float)((float)(p_mNext->mLocalWorld.v3.x - mReflection->mPlane.mPosition.x)
                                         * mReflection->mPlane.mNormal.x))
                         + (float)((float)(p_mNext->mLocalWorld.v3.z - mReflection->mPlane.mPosition.z)
                                 * mReflection->mPlane.mNormal.z)) > -0.050000001 )
              {
                UFG::DynamicSceneryInstance::Draw(p_mNext, &view);
                mSettings = view.mSettings;
              }
            }
          }
          p_mNext = (UFG::DynamicSceneryInstance *)v100;
        }
        while ( v100 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                                  - 88) );
      }
      v105 = (UFG::CompositeDrawableComponent *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
      {
        do
        {
          v106 = (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)&v105->mNext[-6].mNext;
          if ( (v105->m_Flags & 3) == 1 && !v105->mIsHidden )
          {
            mCullResults = v105->mCullResults;
            if ( mCullResults )
            {
              v108 = mSettings->mCullIndex;
              if ( (int)v108 >= 6
                || mCullResults->mDistance[v108] < 20.0
                || (v109 = v105->mPoseRootMatrix.v3.x, v109 >= mReflection->mVolume.mPosMinWorld.x)
                && v109 <= mReflection->mVolume.mPosMaxWorld.x
                && (v110 = v105->mPoseRootMatrix.v3.y, v110 >= mReflection->mVolume.mPosMinWorld.y)
                && v110 <= mReflection->mVolume.mPosMaxWorld.y
                && (v111 = v105->mPoseRootMatrix.v3.z, v111 >= mReflection->mVolume.mPosMinWorld.z)
                && v111 <= mReflection->mVolume.mPosMaxWorld.z )
              {
                if ( (float)((float)((float)((float)(v105->mPoseRootMatrix.v3.y - mReflection->mPlane.mPosition.y)
                                           * mReflection->mPlane.mNormal.y)
                                   + (float)((float)(v105->mPoseRootMatrix.v3.x - mReflection->mPlane.mPosition.x)
                                           * mReflection->mPlane.mNormal.x))
                           + (float)((float)(v105->mPoseRootMatrix.v3.z - mReflection->mPlane.mPosition.z)
                                   * mReflection->mPlane.mNormal.z)) > -0.050000001 )
                {
                  mCullInfo = v105->mCullInfo;
                  if ( mCullInfo )
                  {
                    if ( Render::GetCullResultsAABB(
                           &view.mWorldViewProjection,
                           view.mExtractedFarPlane,
                           mSettings->mCullPixelDensityThreshold,
                           mSettings->mCullPixelDistanceBias,
                           mCullInfo,
                           &cull_metrics) <= 1 )
                    {
                      LOD = UFG::CompositeDrawableComponent::GetLOD(v105, cull_metrics.mPixelCoverage);
                      UFG::CompositeDrawableComponent::Draw(v105, &view, LOD);
                    }
                    mSettings = view.mSettings;
                  }
                }
              }
            }
          }
          v105 = (UFG::CompositeDrawableComponent *)v106;
        }
        while ( v106 != (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) );
      }
      ptr.mShaderSelector = 0i64;
      v114 = Render::View::GetStateArgs(&view);
      v115 = *(_QWORD *)&v125.v0.x;
      v116 = *(_QWORD **)&v125.v0.z;
      *(_QWORD *)(*(_QWORD *)&v125.v0.x + 8i64) = *(_QWORD *)&v125.v0.z;
      *v116 = v115;
      *(_QWORD *)&v125.v0.x = &v125;
      *(_QWORD *)&v125.v0.z = &v125;
      HIBYTE(v125.v1.z) = 0;
      if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v114->mStateArgs[SLOWORD(v125.v1.z)].mNode.mNext == &v114->mStateArgs[SLOWORD(v125.v1.z)] )
        v114->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v125.v1.z) >> 6] &= ~(1i64 << (LOBYTE(v125.v1.z) & 0x3F));
      v117 = Render::View::GetStateArgs(&view);
      mPrev = v127.mPrev;
      mNext = v127.mNext;
      v127.mPrev->mNext = v127.mNext;
      mNext->mPrev = mPrev;
      v127.mPrev = &v127;
      v127.mNext = &v127;
      v127.mIsSet = 0;
      if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v117->mStateArgs[v127.mStateParamIndex].mNode.mNext == &v117->mStateArgs[v127.mStateParamIndex] )
        v117->mStateArgsCreateMask.mFlags[(unsigned int)v127.mStateParamIndex >> 6] &= ~(1i64 << (v127.mStateParamIndex & 0x3F));
      v120 = v127.mPrev;
      v121 = v127.mNext;
      v127.mPrev->mNext = v127.mNext;
      v121->mPrev = v120;
      v127.mPrev = &v127;
      v127.mNext = &v127;
      v122 = *(_QWORD *)&v125.v0.x;
      v123 = *(_QWORD **)&v125.v0.z;
      *(_QWORD *)(*(_QWORD *)&v125.v0.x + 8i64) = *(_QWORD *)&v125.v0.z;
      *v123 = v122;
      *(_QWORD *)&v125.v0.x = &v125;
      *(_QWORD *)&v125.v0.z = &v125;
    }
    RenderQueueLayer::SerializeRenderQueues(&v135);
    RenderQueueLayer::SerializeDeferredAlpha(&v135);
    Render::View::EndTarget(&view);
    v124 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x64u, 4u);
    cull_metrics = (Render::CullMetrics)v124;
    if ( v124 )
      *(_DWORD *)v124 = 0;
    else
      v124 = 0i64;
    LayerSubmitContext::AddRenderCommand(&ptr, 24, 0, v124);
    Render::gRenderUtilities.mSubmitContext = &ptr;
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      render_context->mReflectionTarget,
      render_context->mReflectionMipTarget,
      0x3141335Cu,
      "<Blit>",
      0,
      1,
      0i64);
    Render::RenderUtilities::RenderMips(&Render::gRenderUtilities, render_context->mReflectionMipTarget, 6, 0xC532D4Bu);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    Render::ViewMetrics::Accumulate(&render_context->mRenderStats, &view.mViewMetrics);
    cull_metrics = (Render::CullMetrics)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v135);
  }
}
      0i64);
    Render::RenderUtilities::RenderMips(&Render::

// File Line: 1877
// RVA: 0x5D550
void __fastcall UFG::RenderWorld::UpdateViews(float fRealTimeDelta)
{
  UFG::RenderContext *mRenderParam; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rsi
  Render::DepthOfField::Focus *p_m_NameUID; // rdx
  UFG::qMatrix44 *WorldView; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qMatrix44 *ViewProjection; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  CullManager *v12; // rax
  Render::RenderCallbacks *RenderCallbacks; // rax
  float mCurrentExposureEV; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v18; // xmm6_4
  UFG::TimeOfDayManager *v19; // rax
  UFG::qMatrix44 *v20; // rax
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qMatrix44 d; // [rsp+30h] [rbp-D8h] BYREF
  CullManager::CullSettings view_settings; // [rsp+70h] [rbp-98h] BYREF

  mRenderParam = (UFG::RenderContext *)Render::GetRenderCallbacks()->mRenderParam;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 0x50);
  if ( !gDoFarGroundCapture && mCurrentCamera )
  {
    if ( gRenderFrameFeatures.mForceLetterBox )
    {
      UFG::gUIViewportScaleH = 1.0;
      UFG::gUIViewportScaleV = 1.0;
    }
    else
    {
      UFG::gUIViewportScaleH = Render::gScreenViewportScaleH;
      UFG::gUIViewportScaleV = Render::gScreenViewportScaleV;
    }
    if ( mRenderParam->mRenderFeatures.mDOF )
    {
      p_m_NameUID = (Render::DepthOfField::Focus *)&mCurrentCamera->m_NameUID;
    }
    else
    {
      if ( (_S17 & 1) == 0 )
      {
        _S17 |= 1u;
        Render::DepthOfField::Focus::Focus(&defaultFocus);
        atexit(UFG::RenderWorld::UpdateViews_::_13_::_dynamic_atexit_destructor_for__defaultFocus__);
      }
      p_m_NameUID = &defaultFocus;
    }
    Render::DepthOfField::Set(&Render::gDepthOfField, p_m_NameUID);
  }
  mRenderParam->mMainViewSettings.mCullPixelDistanceBias = gMainView_CullPixelDistanceBias;
  mRenderParam->mMainViewSettings.mCullPixelDensityThreshold = gMainView_CullPixelDensityThreshold;
  WorldView = UFG::Camera::GetWorldView((UFG::Camera *)mCurrentCamera);
  v5 = WorldView->v1;
  v6 = WorldView->v2;
  v7 = WorldView->v3;
  mRenderParam->mMainViewSettings.mWorldView.v0 = WorldView->v0;
  mRenderParam->mMainViewSettings.mWorldView.v1 = v5;
  mRenderParam->mMainViewSettings.mWorldView.v2 = v6;
  mRenderParam->mMainViewSettings.mWorldView.v3 = v7;
  ViewProjection = UFG::Camera::GetViewProjection((UFG::Camera *)mCurrentCamera);
  v9 = ViewProjection->v1;
  v10 = ViewProjection->v2;
  v11 = ViewProjection->v3;
  mRenderParam->mMainViewSettings.mProjection.v0 = ViewProjection->v0;
  mRenderParam->mMainViewSettings.mProjection.v1 = v9;
  mRenderParam->mMainViewSettings.mProjection.v2 = v10;
  mRenderParam->mMainViewSettings.mProjection.v3 = v11;
  *(_QWORD *)&view_settings.mViewFlags = 1i64;
  CullManager::CullSettings::SetFromViewSettings(&view_settings, &mRenderParam->mMainViewSettings);
  v12 = CullManager::Instance();
  mRenderParam->mMainViewSettings.mCullIndex = CullManager::RegisterView(v12, &view_settings);
  if ( UFG::RenderWorld::msRenderWorld )
  {
    RenderCallbacks = Render::GetRenderCallbacks();
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)((char *)RenderCallbacks->mRenderParam + 1008));
    UFG::RenderStageExposureMetering::Update(UFG::RenderWorld::msExposureMetering, fRealTimeDelta);
    mCurrentExposureEV = UFG::RenderWorld::msExposureMetering->mCurrentExposureEV;
    UFG::TimeOfDayManager::GetInstance()->mMeteringEV = mCurrentExposureEV;
    Instance = UFG::TimeOfDayManager::GetInstance();
    y = d.v3.y;
    z = d.v3.z;
    Instance->mCameraPosition.x = d.v3.x;
    Instance->mCameraPosition.y = y;
    Instance->mCameraPosition.z = z;
    v18 = UFG::Metrics::msInstance.mSimTimeDelta * gTOD_Speedhack;
    v19 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::Update(v19, v18);
  }
  if ( mRenderParam->mRenderFeatures.mWorld )
  {
    UFG::RenderStageEnvMap::UpdateViews(UFG::RenderWorld::msStageEnvMap, mRenderParam, fRealTimeDelta);
    UFG::RenderStageShadow::UpdateViews(UFG::RenderWorld::msStageShadow, mRenderParam, fRealTimeDelta);
    UFG::RenderStageImposters::UpdateViews(UFG::RenderWorld::msStageImposters, mRenderParam, fRealTimeDelta);
    _((AMD_HD3D *)UFG::RenderWorld::msStageTerrain);
  }
  else
  {
    mRenderParam->mNumCascades = 0;
  }
  v20 = UFG::Camera::GetWorldView((UFG::Camera *)mCurrentCamera);
  v21 = v20->v1;
  v22 = v20->v2;
  v23 = v20->v3;
  Render::DebugProbes::msWorldView.v0 = v20->v0;
  Render::DebugProbes::msWorldView.v1 = v21;
  Render::DebugProbes::msWorldView.v2 = v22;
  Render::DebugProbes::msWorldView.v3 = v23;
}

// File Line: 1975
// RVA: 0x4AF80
void __fastcall MovieUpdateTask::DoCommandBuilding(MovieUpdateTask *this, void *context, int a3)
{
  bool v3; // al

  v3 = Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)context,
         a3);
  UFG::MovieHandler::Update(&UFG::TheMovieHandler, v3);
}

// File Line: 1980
// RVA: 0x530E0
void __fastcall MovieUpdateTask::PostSyncCommandList(MovieUpdateTask *this)
{
  UFG::MovieHandler::PostUpdate(&UFG::TheMovieHandler);
}

// File Line: 1997
// RVA: 0x5CEE0
void __fastcall UFG::RenderWorld::Update(float fRealTimeDelta)
{
  char *v1; // rax
  MovieUpdateTask *v2; // rcx
  _QWORD *v3; // rax
  float *p_mFOVOffset; // rsi
  Render::View *mRenderParam; // rdi
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *p_mNode; // rcx
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v7; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  float v9; // xmm6_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h] BYREF

  LODWORD(Render::DisplayCalibration::msGamma) = (_DWORD)FLOAT_1_0;
  v1 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v2 = (MovieUpdateTask *)v1;
  if ( v1 )
  {
    v3 = v1 + 8;
    *v3 = v3;
    v3[1] = v3;
    v2->vfptr = (Illusion::AsyncCommandBuilderVtbl *)&Illusion::AsyncCommandBuilder::`vftable;
    p_mFOVOffset = 0i64;
    v2->mTask = 0i64;
    v2->mCommandList = 0i64;
    v2->vfptr = (Illusion::AsyncCommandBuilderVtbl *)&MovieUpdateTask::`vftable;
  }
  else
  {
    p_mFOVOffset = 0i64;
    v2 = 0i64;
  }
  movie_update_task = v2;
  Illusion::AsyncCommandBuilder::BeginAsyncCommandBuilding(v2);
  if ( UFG::RenderWorld::msRenderWorld )
  {
    mRenderParam = (Render::View *)Render::GetRenderCallbacks()->mRenderParam;
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)&mRenderParam[2].mViewMetrics.mNumShadowsRendered);
    Render::SkyMarshall::Update(&Render::SkyMarshall::gSkyMarshall, UFG::Metrics::msInstance.mSimTimeDelta);
    Render::RainManager::Update(
      &Render::RainManager::gRainManager,
      UFG::Metrics::msInstance.mSimTimeDelta,
      (UFG::qMatrix44 *)&mRenderParam[2].mViewMetrics.mNumShadowsRendered);
    Render::CloudVolumeManager::Update(
      &Render::gCloudVolumeManager,
      UFG::Metrics::msInstance.mSimTimeDelta,
      (UFG::qVector3 *)&d.v3);
    Render::gFXManager.mCurrentTimeOfDay = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
    Render::FXManager::Update(
      &Render::gFXManager,
      &d,
      LODWORD(mRenderParam[2].mViewWorld.v1.x),
      UFG::Metrics::msInstance.mSimTime_Temp);
    p_mNode = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
    if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
    {
      do
      {
        v7 = (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&p_mNode[4].mNext[-4];
        ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *))p_mNode->mPrev[8].mNext)(p_mNode);
        p_mNode = &v7->mNode;
      }
      while ( v7 != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 );
    }
    if ( UFG::RenderWorld::msRenderStagePlugin )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(
                          UFG::RenderWorld::msRenderStagePlugin,
                          UFG::VisualTreatmentPostEffect::_TypeUID);
      if ( ComponentOfType )
      {
        if ( LOBYTE(ComponentOfType[1].m_TypeUID) )
        {
          v9 = *(float *)&ComponentOfType[1].m_NameUID;
          mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
          if ( mCurrentCamera )
            p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
          *p_mFOVOffset = (float)(v9 * 3.1415927) * 0.0055555557;
        }
      }
    }
  }
}

// File Line: 2087
// RVA: 0x49130
void __fastcall SerializationList::~SerializationList(SerializationList *this)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rax
  UFG::qNode<SerializationList,SerializationList> *v5; // rcx
  UFG::qNode<SerializationList,SerializationList> *v6; // rax

  p_mList = &this->mList;
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&this->mList);
  mPrev = p_mList->mNode.mPrev;
  mNext = p_mList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mList->mNode.mPrev = &p_mList->mNode;
  p_mList->mNode.mNext = &p_mList->mNode;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 2102
// RVA: 0x49BE0
void __fastcall SerializationList::AddTaskGroupSync(SerializationList *this, UFG::qTaskGroup *task_group)
{
  char *v4; // rax

  if ( task_group && task_group->mNumTasks )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    if ( v4 )
    {
      *(_QWORD *)v4 = task_group;
      *((_QWORD *)v4 + 1) = SerializationList::SyncTaskGroupCallback;
    }
    SerializationList::AddCommand(this, 17, v4);
  }
}

// File Line: 2111
// RVA: 0x498D0
void __fastcall SerializationList::AddCommand(SerializationList *this, __int16 command, void *data)
{
  Illusion::RenderQueue *mCommandQueue; // rbx
  Illusion::QueueCommandBucket *mFreeBucket; // rcx
  __int64 mNumCommands; // r8
  __int64 mCommands; // rax
  char *v10; // rax
  Illusion::QueueCommandBucket *v11; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mPrev; // rax
  Illusion::QueueCommandBucket *v13; // rax

  SerializationList::BeginCommandQueue(this);
  mCommandQueue = this->mCommandQueue;
  mFreeBucket = mCommandQueue->mFreeBucket;
  if ( mFreeBucket )
  {
    mNumCommands = mFreeBucket->mNumCommands;
    if ( (unsigned int)mNumCommands < 0x7E )
    {
      mFreeBucket->mNumCommands = mNumCommands + 1;
      mCommands = (__int64)&mFreeBucket->mCommands[mNumCommands];
      goto LABEL_9;
    }
    mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
    mCommandQueue->mFreeBucket = 0i64;
  }
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v11 = (Illusion::QueueCommandBucket *)v10;
  if ( v10 )
  {
    *(_QWORD *)v10 = v10;
    *((_QWORD *)v10 + 1) = v10;
    *((_QWORD *)v10 + 2) = 0i64;
    *((_DWORD *)v10 + 6) = 0;
    mPrev = mCommandQueue->mBuckets.mNode.mPrev;
    mPrev->mNext = v11;
    v11->mPrev = mPrev;
    v11->mNext = &mCommandQueue->mBuckets.mNode;
    mCommandQueue->mBuckets.mNode.mPrev = v11;
    mCommandQueue->mFreeBucket = v11;
  }
  v13 = mCommandQueue->mFreeBucket;
  if ( v13 )
  {
    v13->mNumCommands = 1;
    mCommands = (__int64)mCommandQueue->mFreeBucket->mCommands;
LABEL_9:
    if ( mCommands )
    {
      *(_WORD *)mCommands = command;
      *(_WORD *)(mCommands + 2) = 0;
      *(_QWORD *)(mCommands + 8) = data;
    }
  }
}

// File Line: 2133
// RVA: 0x49C70
void __fastcall SerializationList::BeginCommandQueue(SerializationList *this)
{
  char *v2; // rax
  char *v3; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax

  if ( !this->mCommandQueue )
  {
    v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v3 = v2;
    if ( v2 )
    {
      *(_QWORD *)v2 = v2;
      *((_QWORD *)v2 + 1) = v2;
      *((_QWORD *)v2 + 2) = v2 + 16;
      *((_QWORD *)v2 + 3) = v2 + 16;
      UFG::qMemSet(v2 + 96, 0, 0x400u);
      *((_QWORD *)v3 + 11) = 0i64;
      *((_QWORD *)v3 + 10) = 0i64;
      *((_DWORD *)v3 + 8) = 0;
      *((_QWORD *)v3 + 5) = 0i64;
      *((_QWORD *)v3 + 6) = 0i64;
      *((_QWORD *)v3 + 7) = 0i64;
      *((_QWORD *)v3 + 8) = 0i64;
      *((_QWORD *)v3 + 9) = 0i64;
    }
    else
    {
      v3 = 0i64;
    }
    this->mCommandQueue = (Illusion::RenderQueue *)v3;
    mPrev = this->mList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
    *(_QWORD *)v3 = mPrev;
    *((_QWORD *)v3 + 1) = &this->mList;
    this->mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
  }
}

// File Line: 2151
// RVA: 0x5CED0
void __fastcall SerializationList::SyncTaskGroupCallback(UFG::qTaskGroup *param)
{
  UFG::qTaskManager::Sync(&UFG::gTaskManager, param);
}

// File Line: 2174
// RVA: 0x491A0
void __fastcall SerializationListBuilder::~SerializationListBuilder(SerializationListBuilder *this)
{
  UFG::qList<SerializationList,SerializationList,1,0> *p_mSerializationLists; // rbx
  UFG::qNode<SerializationList,SerializationList> *mPrev; // rcx
  UFG::qNode<SerializationList,SerializationList> *mNext; // rax

  p_mSerializationLists = &this->mSerializationLists;
  UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes(&this->mSerializationLists);
  mPrev = p_mSerializationLists->mNode.mPrev;
  mNext = p_mSerializationLists->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mSerializationLists->mNode.mPrev = &p_mSerializationLists->mNode;
  p_mSerializationLists->mNode.mNext = &p_mSerializationLists->mNode;
}

// File Line: 2177
// RVA: 0x49AD0
void __fastcall SerializationListBuilder::AddTail(
        SerializationListBuilder *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *render_queues,
        unsigned int primitive_count_mask)
{
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *i; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rax
  SerializationList *ListAndAccumulate; // rax
  Illusion::RenderQueue *mCommandQueue; // rdx
  Illusion::QueueCommandBucket *mFreeBucket; // rcx
  unsigned int mNumCommands; // ecx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v14; // rax

  for ( i = render_queues->mNode.mNext;
        i != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)render_queues;
        i = render_queues->mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    ListAndAccumulate = SerializationListBuilder::GetListAndAccumulate(
                          this,
                          (unsigned int)i[4].mNext,
                          primitive_count_mask & HIDWORD(i[4].mNext));
    mCommandQueue = ListAndAccumulate->mCommandQueue;
    if ( mCommandQueue )
    {
      mFreeBucket = mCommandQueue->mFreeBucket;
      if ( mFreeBucket )
      {
        mNumCommands = mFreeBucket->mNumCommands;
        mCommandQueue->mFreeBucket = 0i64;
        mCommandQueue->mCommandCount += mNumCommands;
      }
      ListAndAccumulate->mCommandQueue = 0i64;
    }
    p_mList = &ListAndAccumulate->mList;
    v14 = ListAndAccumulate->mList.mNode.mPrev;
    v14->mNext = i;
    i->mPrev = v14;
    i->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = i;
  }
}

// File Line: 2222
// RVA: 0x4F940
SerializationList *__fastcall SerializationListBuilder::GetListAndAccumulate(
        SerializationListBuilder *this,
        unsigned int command_count,
        unsigned int primitive_count)
{
  SerializationList *mCurrentList; // rdx
  Illusion::RenderQueue *mCommandQueue; // rcx
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  char *v9; // rax
  SerializationList *v10; // rdx
  UFG::qNode<SerializationList,SerializationList> *mPrev; // rax

  if ( (float)((float)((float)(int)(primitive_count + this->mCurrentPrimitiveCount) * this->mOneOverMaxPrimitivesPerList)
             + (float)((float)(int)(command_count + this->mCurrentCommandCount) * this->mOneOverMaxCommandsPerList)) > 1.0 )
  {
    mCurrentList = this->mCurrentList;
    if ( mCurrentList )
    {
      mCommandQueue = mCurrentList->mCommandQueue;
      if ( mCommandQueue )
      {
        mFreeBucket = mCommandQueue->mFreeBucket;
        if ( mFreeBucket )
        {
          mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
          mCommandQueue->mFreeBucket = 0i64;
        }
        mCurrentList->mCommandQueue = 0i64;
      }
      this->mCurrentList = 0i64;
    }
    *(_QWORD *)&this->mCurrentCommandCount = 0i64;
  }
  if ( !this->mCurrentList )
  {
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v10 = (SerializationList *)v9;
    if ( v9 )
    {
      *(_QWORD *)v9 = v9;
      *((_QWORD *)v9 + 1) = v9;
      *((_QWORD *)v9 + 2) = v9 + 16;
      *((_QWORD *)v9 + 3) = v9 + 16;
      *((_QWORD *)v9 + 4) = 0i64;
    }
    else
    {
      v10 = 0i64;
    }
    this->mCurrentList = v10;
    mPrev = this->mSerializationLists.mNode.mPrev;
    mPrev->mNext = v10;
    v10->mPrev = mPrev;
    v10->mNext = &this->mSerializationLists.mNode;
    this->mSerializationLists.mNode.mPrev = v10;
  }
  this->mCurrentCommandCount += command_count;
  this->mCurrentPrimitiveCount += primitive_count;
  return this->mCurrentList;
}

// File Line: 2260
// RVA: 0x4E9A0
void __fastcall GenerateGBufferPreScenerySerializationList(
        SerializationList *serialization_list,
        FlushContext *flush_context,
        MainViewTargetParams *main_view_target_params)
{
  int v5; // ebx
  char *v6; // rax
  char *v7; // r8

  SerializationList::AddCommand(serialization_list, 22, &UFG::RenderWorld::msGpuTimer_GBuffer);
  SerializationList::AddCommand(serialization_list, 14, main_view_target_params->gbuffer_target_params);
  SerializationList::AddCommand(serialization_list, 9, main_view_target_params->gbuffer_viewport);
  v5 = (gDoColorClears != 0) | 0x16;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = 0i64;
    *(UFG::qColour *)(v6 + 8) = UFG::qColour::Zero;
    *((_DWORD *)v6 + 6) = v5;
    *((_DWORD *)v6 + 7) = 1065353216;
    *((_DWORD *)v6 + 8) = 1;
  }
  else
  {
    v7 = 0i64;
  }
  SerializationList::AddCommand(serialization_list, 16, v7);
}

// File Line: 2277
// RVA: 0x4E700
void __fastcall GenerateGBufferPostScenerySerializationList(
        SerializationList *serialization_list,
        FlushContext *flush_context,
        MainViewTargetParams *main_view_target_params)
{
  SimRenderQueueResults *mSimResults; // rbx
  Illusion::RenderQueue *mCommandQueue; // rcx
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rsi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mTerrainQueues; // rdx
  Illusion::RenderQueue *v14; // rcx
  Illusion::QueueCommandBucket *v15; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mImposterQueues; // rdx
  Illusion::RenderQueue *v20; // rcx
  Illusion::QueueCommandBucket *v21; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v23; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mDecalQueues; // rdx
  Illusion::RenderQueue *v26; // rcx
  Illusion::QueueCommandBucket *v27; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v28; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v29; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v30; // rcx
  Illusion::RenderQueue *v31; // rcx
  Illusion::QueueCommandBucket *v32; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v33; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v34; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v35; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v36; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v37; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v38; // [rsp+28h] [rbp-18h] BYREF

  v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  SerializationList::AddTaskGroupSync(serialization_list, flush_context->mSkinningGroups[1]);
  mSimResults = flush_context->mSimResults;
  mSimResults->mRenderSimLayer.mSerializationList = &v38;
  RenderQueueLayer::SerializeRenderQueues(&mSimResults->mRenderSimLayer);
  mSimResults->mRenderSimLayer.mSerializationList = 0i64;
  mCommandQueue = serialization_list->mCommandQueue;
  if ( mCommandQueue )
  {
    mFreeBucket = mCommandQueue->mFreeBucket;
    if ( mFreeBucket )
    {
      mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  p_mList = &serialization_list->mList;
  mNext = v38.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v38.mNode.mNext != &v38 )
  {
    mPrev = p_mList->mNode.mPrev;
    v12 = v38.mNode.mPrev;
    mPrev->mNext = v38.mNode.mNext;
    mNext->mPrev = mPrev;
    v12->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = v12;
    v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
    v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  }
  p_mTerrainQueues = &mSimResults->mTerrainQueues;
  v14 = serialization_list->mCommandQueue;
  if ( v14 )
  {
    v15 = v14->mFreeBucket;
    if ( v15 )
    {
      v14->mCommandCount += v15->mNumCommands;
      v14->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v16 = mSimResults->mTerrainQueues.mNode.mNext;
  if ( v16 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)p_mTerrainQueues )
  {
    v17 = p_mList->mNode.mPrev;
    v18 = p_mTerrainQueues->mNode.mPrev;
    v17->mNext = v16;
    v16->mPrev = v17;
    v18->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = v18;
    p_mTerrainQueues->mNode.mPrev = &p_mTerrainQueues->mNode;
    mSimResults->mTerrainQueues.mNode.mNext = &mSimResults->mTerrainQueues.mNode;
  }
  p_mImposterQueues = &mSimResults->mImposterQueues;
  v20 = serialization_list->mCommandQueue;
  if ( v20 )
  {
    v21 = v20->mFreeBucket;
    if ( v21 )
    {
      v20->mCommandCount += v21->mNumCommands;
      v20->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v22 = mSimResults->mImposterQueues.mNode.mNext;
  if ( v22 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)p_mImposterQueues )
  {
    v23 = p_mList->mNode.mPrev;
    v24 = p_mImposterQueues->mNode.mPrev;
    v23->mNext = v22;
    v22->mPrev = v23;
    v24->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = v24;
    p_mImposterQueues->mNode.mPrev = &p_mImposterQueues->mNode;
    mSimResults->mImposterQueues.mNode.mNext = &mSimResults->mImposterQueues.mNode;
  }
  p_mDecalQueues = &mSimResults->mDecalQueues;
  v26 = serialization_list->mCommandQueue;
  if ( v26 )
  {
    v27 = v26->mFreeBucket;
    if ( v27 )
    {
      v26->mCommandCount += v27->mNumCommands;
      v26->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v28 = mSimResults->mDecalQueues.mNode.mNext;
  if ( v28 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)p_mDecalQueues )
  {
    v29 = p_mList->mNode.mPrev;
    v30 = p_mDecalQueues->mNode.mPrev;
    v29->mNext = v28;
    v28->mPrev = v29;
    v30->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = v30;
    p_mDecalQueues->mNode.mPrev = &p_mDecalQueues->mNode;
    mSimResults->mDecalQueues.mNode.mNext = &mSimResults->mDecalQueues.mNode;
  }
  SerializationList::AddCommand(serialization_list, 22, &UFG::RenderWorld::msGpuTimer_FXDeferred);
  mSimResults->mFXLayer.mSerializationList = &v38;
  RenderQueueLayer::SerializeRenderQueues(&mSimResults->mFXLayer);
  mSimResults->mFXLayer.mSerializationList = 0i64;
  v31 = serialization_list->mCommandQueue;
  if ( v31 )
  {
    v32 = v31->mFreeBucket;
    if ( v32 )
    {
      v31->mCommandCount += v32->mNumCommands;
      v31->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v33 = v38.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v38.mNode.mNext != &v38 )
  {
    v34 = p_mList->mNode.mPrev;
    v35 = v38.mNode.mPrev;
    v34->mNext = v38.mNode.mNext;
    v33->mPrev = v34;
    v35->mNext = &p_mList->mNode;
    p_mList->mNode.mPrev = v35;
    v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
    v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  }
  SerializationList::AddCommand(serialization_list, 23, &UFG::RenderWorld::msGpuTimer_FXDeferred);
  SerializationList::AddCommand(serialization_list, 15, main_view_target_params->gbuffer_target_params);
  SerializationList::AddCommand(serialization_list, 23, &UFG::RenderWorld::msGpuTimer_GBuffer);
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v38);
  v36 = v38.mNode.mPrev;
  v37 = v38.mNode.mNext;
  v38.mNode.mPrev->mNext = v38.mNode.mNext;
  v37->mPrev = v36;
}

// File Line: 2333
// RVA: 0x4E520
void __fastcall GenerateGBufferAlphaSerializationList(
        SerializationList *serialization_list,
        FlushContext *flush_context,
        MainViewTargetParams *main_view_target_params)
{
  SceneryTaskRenderQueueResults *mSceneryTaskResults; // rbx
  Illusion::RenderQueue *mCommandQueue; // rcx
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  SimRenderQueueResults *mSimResults; // rbx
  Illusion::RenderQueue *v13; // rcx
  Illusion::QueueCommandBucket *v14; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v15; // rsi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // rcx
  Illusion::RenderQueue *v19; // rcx
  Illusion::QueueCommandBucket *v20; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v23; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v26; // [rsp+28h] [rbp-18h] BYREF

  v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  mSceneryTaskResults = flush_context->mSceneryTaskResults;
  if ( mSceneryTaskResults )
  {
    mSceneryTaskResults->mSceneryLayer[0].mSerializationList = &v26;
    RenderQueueLayer::SerializeDeferredAlpha(mSceneryTaskResults->mSceneryLayer);
    mSceneryTaskResults->mSceneryLayer[0].mSerializationList = 0i64;
    mCommandQueue = serialization_list->mCommandQueue;
    if ( mCommandQueue )
    {
      mFreeBucket = mCommandQueue->mFreeBucket;
      if ( mFreeBucket )
      {
        mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
        mCommandQueue->mFreeBucket = 0i64;
      }
      serialization_list->mCommandQueue = 0i64;
    }
    p_mList = &serialization_list->mList;
    mNext = v26.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v26.mNode.mNext != &v26 )
    {
      mPrev = p_mList->mNode.mPrev;
      v11 = v26.mNode.mPrev;
      mPrev->mNext = v26.mNode.mNext;
      mNext->mPrev = mPrev;
      v11->mNext = &p_mList->mNode;
      p_mList->mNode.mPrev = v11;
      v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
      v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
    }
  }
  mSimResults = flush_context->mSimResults;
  mSimResults->mRenderSimLayer.mSerializationList = &v26;
  RenderQueueLayer::SerializeDeferredAlpha(&mSimResults->mRenderSimLayer);
  mSimResults->mRenderSimLayer.mSerializationList = 0i64;
  v13 = serialization_list->mCommandQueue;
  if ( v13 )
  {
    v14 = v13->mFreeBucket;
    if ( v14 )
    {
      v13->mCommandCount += v14->mNumCommands;
      v13->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v15 = &serialization_list->mList;
  v16 = v26.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v26.mNode.mNext != &v26 )
  {
    v17 = v15->mNode.mPrev;
    v18 = v26.mNode.mPrev;
    v17->mNext = v26.mNode.mNext;
    v16->mPrev = v17;
    v18->mNext = &v15->mNode;
    v15->mNode.mPrev = v18;
    v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
    v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  }
  mSimResults->mFXLayer.mSerializationList = &v26;
  RenderQueueLayer::SerializeDeferredAlpha(&mSimResults->mFXLayer);
  mSimResults->mFXLayer.mSerializationList = 0i64;
  v19 = serialization_list->mCommandQueue;
  if ( v19 )
  {
    v20 = v19->mFreeBucket;
    if ( v20 )
    {
      v19->mCommandCount += v20->mNumCommands;
      v19->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v21 = v26.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v26.mNode.mNext != &v26 )
  {
    v22 = v15->mNode.mPrev;
    v23 = v26.mNode.mPrev;
    v22->mNext = v26.mNode.mNext;
    v21->mPrev = v22;
    v23->mNext = &v15->mNode;
    v15->mNode.mPrev = v23;
    v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
    v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  }
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v26);
  v24 = v26.mNode.mPrev;
  v25 = v26.mNode.mNext;
  v26.mNode.mPrev->mNext = v26.mNode.mNext;
  v25->mPrev = v24;
}

// File Line: 2377
// RVA: 0x4EEA0
void __fastcall GenerateShadowSerializationLists(
        SerializationListBuilder *serialization_list_builder,
        FlushContext *flush_context,
        bool render_sun)
{
  UFG::ShadowRenderQueueSimResults *mShadowSimResults; // rsi
  char v5; // r13
  unsigned int i; // r15d
  Illusion::Target *v7; // rbp
  char *v8; // rax
  char *v9; // r14
  SerializationList *ListAndAccumulate; // rax
  char *v11; // rbx
  SerializationList *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  SerializationList *v15; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mPendingShadowQueues; // rbx
  __int64 v17; // rbp
  UFG::qTaskGroup *v18; // rbx
  SerializationList *v19; // rbp
  char *v20; // rax
  Illusion::RenderQueue *v21; // rbx
  SerializationList *v22; // rax
  Illusion::RenderQueue *mCommandQueue; // rdx
  Illusion::QueueCommandBucket *mFreeBucket; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  SerializationList *v27; // rax
  UFG::ShadowRenderQueueTaskResults *mShadowTaskResults; // [rsp+98h] [rbp+20h]

  mShadowTaskResults = flush_context->mShadowTaskResults;
  mShadowSimResults = flush_context->mShadowSimResults;
  if ( mShadowSimResults )
  {
    if ( render_sun )
      SerializationListBuilder::AddTail(serialization_list_builder, &mShadowSimResults->mPreShadowPass, 0xFFFFFFFF);
    v5 = 0;
    for ( i = 0; i < mShadowSimResults->mNumCascades; ++i )
    {
      v7 = mShadowSimResults->mCascadeTargets[i];
      v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      v9 = v8;
      if ( v8 )
      {
        *(_QWORD *)v8 = v7;
        *((_QWORD *)v8 + 1) = 0i64;
        *((_DWORD *)v8 + 4) = 5;
        *((_QWORD *)v8 + 3) = "ShadowCascade";
      }
      else
      {
        v9 = 0i64;
      }
      ListAndAccumulate = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
      SerializationList::AddCommand(ListAndAccumulate, 14, v9);
      v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
      Illusion::SetFullscreenViewportScissor(v7, (Illusion::ViewportScissorState *)v11, 0);
      v12 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
      SerializationList::AddCommand(v12, 9, v11);
      v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
      v14 = v13;
      if ( v13 )
      {
        *(_QWORD *)v13 = 0i64;
        *(UFG::qColour *)(v13 + 8) = UFG::qColour::Zero;
        *((_DWORD *)v13 + 6) = 6;
        *((_DWORD *)v13 + 7) = 1065353216;
        *((_DWORD *)v13 + 8) = 1;
      }
      else
      {
        v14 = 0i64;
      }
      v15 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
      SerializationList::AddCommand(v15, 16, v14);
      if ( mShadowTaskResults )
      {
        p_mPendingShadowQueues = &mShadowTaskResults->mRenderQueueResults[(unsigned __int64)i][0].mPendingShadowQueues;
        v17 = 4i64;
        do
        {
          SerializationListBuilder::AddTail(serialization_list_builder, p_mPendingShadowQueues, 0xFFFFFFFF);
          p_mPendingShadowQueues += 2;
          --v17;
        }
        while ( v17 );
      }
      if ( !v5 && i < mShadowSimResults->mNumCascades - 2 )
      {
        v18 = flush_context->mSkinningGroups[2];
        v19 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
        if ( v18 && v18->mNumTasks )
        {
          v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
          if ( v20 )
          {
            *(_QWORD *)v20 = v18;
            *((_QWORD *)v20 + 1) = SerializationList::SyncTaskGroupCallback;
          }
          SerializationList::AddCommand(v19, 17, v20);
        }
        v5 = 1;
      }
      if ( i < mShadowSimResults->mNumCascades - 2 )
      {
        SerializationListBuilder::AddTail(
          serialization_list_builder,
          &mShadowSimResults->mCompositeDrawableCascades[i],
          0);
        v21 = mShadowSimResults->mDynamicInstances[i];
        if ( v21 )
        {
          v22 = SerializationListBuilder::GetListAndAccumulate(
                  serialization_list_builder,
                  v21->mCommandCount,
                  v21->mPrimitiveCount);
          mCommandQueue = v22->mCommandQueue;
          if ( mCommandQueue )
          {
            mFreeBucket = mCommandQueue->mFreeBucket;
            if ( mFreeBucket )
            {
              mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
              mCommandQueue->mFreeBucket = 0i64;
            }
            v22->mCommandQueue = 0i64;
          }
          p_mList = &v22->mList;
          mPrev = v22->mList.mNode.mPrev;
          mPrev->mNext = v21;
          v21->mPrev = mPrev;
          v21->mNext = &p_mList->mNode;
          p_mList->mNode.mPrev = v21;
        }
      }
      v27 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
      SerializationList::AddCommand(v27, 15, v9);
      if ( render_sun )
      {
        if ( i == mShadowSimResults->mNumCascades - 2 )
          SerializationListBuilder::AddTail(
            serialization_list_builder,
            &mShadowSimResults->mDownsampleShadows,
            0xFFFFFFFF);
        SerializationListBuilder::AddTail(serialization_list_builder, &mShadowSimResults->mCollector[i], 0xFFFFFFFF);
      }
    }
    if ( render_sun )
    {
      SerializationListBuilder::AddTail(serialization_list_builder, &mShadowSimResults->mCloudShadows, 0xFFFFFFFF);
      SerializationListBuilder::AddTail(serialization_list_builder, &mShadowSimResults->mCharacterShadows, 0xFFFFFFFF);
      SerializationListBuilder::AddTail(serialization_list_builder, &mShadowSimResults->mPostShadowPass, 0xFFFFFFFF);
    }
  }
}

// File Line: 2461
// RVA: 0x4F250
void __fastcall GenerateSpotShadowSerializationLists(
        SerializationListBuilder *serialization_list_builder,
        FlushContext *flush_context,
        unsigned int spot_shadow_index)
{
  UFG::SpotShadowRenderQueueTaskResults *mSpotShadowTaskResults; // r14
  UFG::SpotShadowRenderQueueSimResults *mSpotShadowSimResults; // r12
  __int64 v6; // rdi
  Illusion::Target *v7; // r13
  char *v8; // rax
  char *v9; // rsi
  SerializationList *ListAndAccumulate; // rax
  char *v11; // rbx
  SerializationList *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  SerializationList *v15; // rax
  unsigned int i; // ebx
  Illusion::RenderQueue *v17; // rbx
  SerializationList *v18; // rax
  Illusion::RenderQueue *mCommandQueue; // rdx
  Illusion::QueueCommandBucket *mFreeBucket; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  SerializationList *v23; // rax

  mSpotShadowTaskResults = flush_context->mSpotShadowTaskResults;
  mSpotShadowSimResults = flush_context->mSpotShadowSimResults;
  if ( mSpotShadowSimResults )
  {
    v6 = spot_shadow_index;
    v7 = mSpotShadowSimResults->mSpotShadowTargets[spot_shadow_index];
    v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = v7;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_DWORD *)v8 + 4) = 1;
      *((_QWORD *)v8 + 3) = "SpotShadow";
    }
    else
    {
      v9 = 0i64;
    }
    ListAndAccumulate = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
    SerializationList::AddCommand(ListAndAccumulate, 14, v9);
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(v7, (Illusion::ViewportScissorState *)v11, 0);
    v12 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
    SerializationList::AddCommand(v12, 9, v11);
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v14 = v13;
    if ( v13 )
    {
      *(_QWORD *)v13 = 0i64;
      *(UFG::qColour *)(v13 + 8) = UFG::qColour::Zero;
      *((_DWORD *)v13 + 6) = 6;
      *((_DWORD *)v13 + 7) = 1065353216;
      *((_DWORD *)v13 + 8) = 1;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
    SerializationList::AddCommand(v15, 16, v14);
    if ( mSpotShadowTaskResults )
    {
      for ( i = 0; i < 4; ++i )
      {
        if ( mSpotShadowTaskResults->mSpotShadowTaskGroups[v6] )
          SerializationListBuilder::AddTail(
            serialization_list_builder,
            &mSpotShadowTaskResults->mRenderQueueResults[v6][i].mPendingShadowQueues,
            0xFFFFFFFF);
      }
    }
    SerializationListBuilder::AddTail(
      serialization_list_builder,
      &mSpotShadowSimResults->mCompositeDrawableSpotShadows[v6],
      0);
    v17 = mSpotShadowSimResults->mDynamicInstances[v6];
    if ( v17 )
    {
      v18 = SerializationListBuilder::GetListAndAccumulate(
              serialization_list_builder,
              v17->mCommandCount,
              v17->mPrimitiveCount);
      mCommandQueue = v18->mCommandQueue;
      if ( mCommandQueue )
      {
        mFreeBucket = mCommandQueue->mFreeBucket;
        if ( mFreeBucket )
        {
          mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
          mCommandQueue->mFreeBucket = 0i64;
        }
        v18->mCommandQueue = 0i64;
      }
      p_mList = &v18->mList;
      mPrev = v18->mList.mNode.mPrev;
      mPrev->mNext = v17;
      v17->mPrev = mPrev;
      v17->mNext = &p_mList->mNode;
      p_mList->mNode.mPrev = v17;
    }
    v23 = SerializationListBuilder::GetListAndAccumulate(serialization_list_builder, 1u, 0);
    SerializationList::AddCommand(v23, 15, v9);
  }
}

// File Line: 2533
// RVA: 0x499C0
void __fastcall FlushJobQueue::AddFlushJob(
        FlushJobQueue *this,
        SerializationList *serialization_list,
        unsigned int task_count,
        unsigned int task_dbg_id,
        bool flush_to_new_submission_thread)
{
  Illusion::RenderQueue *mCommandQueue; // r10
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mList; // rbx
  char *v11; // rax
  Illusion::RenderPhase *v12; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mQueues; // r9
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *mNext; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // rdx
  UFG::qTaskGroup *v17; // rax

  mCommandQueue = serialization_list->mCommandQueue;
  if ( mCommandQueue )
  {
    mFreeBucket = mCommandQueue->mFreeBucket;
    if ( mFreeBucket )
    {
      mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  p_mList = &serialization_list->mList;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)serialization_list->mList.mNode.mNext != &serialization_list->mList )
  {
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v12 = (Illusion::RenderPhase *)v11;
    if ( v11 )
    {
      *(_QWORD *)v11 = v11;
      *((_QWORD *)v11 + 1) = v11;
      *((_QWORD *)v11 + 2) = v11 + 16;
      *((_QWORD *)v11 + 3) = v11 + 16;
      *((_QWORD *)v11 + 4) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    p_mQueues = &v12->mQueues;
    mNext = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)p_mList->mNode.mNext;
    if ( mNext != p_mList )
    {
      mPrev = p_mQueues->mNode.mPrev;
      v16 = p_mList->mNode.mPrev;
      mPrev->mNext = &mNext->mNode;
      mNext->mNode.mPrev = mPrev;
      v16->mNext = &p_mQueues->mNode;
      p_mQueues->mNode.mPrev = v16;
      p_mList->mNode.mPrev = &p_mList->mNode;
      p_mList->mNode.mNext = &p_mList->mNode;
    }
    v17 = Illusion::RenderQueueSystem::FlushRenderPhase(
            v12,
            task_count,
            task_dbg_id,
            this->mRunningTask,
            flush_to_new_submission_thread);
    if ( v17 )
      this->mRunningTask = &v17->mEndTask;
  }
}

// File Line: 2559
// RVA: 0x49B80
void __fastcall FlushJobQueue::AddTaskGroup(FlushJobQueue *this, UFG::qTaskGroup *task_group)
{
  if ( task_group && task_group->mNumTasks && !task_group->mStartTask.mSyncVars.v.mState )
  {
    if ( this->mRunningTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, task_group, this->mRunningTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, task_group);
    this->mRunningTask = &task_group->mEndTask;
  }
}

// File Line: 2584
// RVA: 0x4D430
void __fastcall EarlyFlushSetup(
        FlushContext *flush_context,
        FlushJobQueue *job_queue,
        bool render_world,
        bool draw_scenery)
{
  char *v8; // rax
  char *v9; // rdi
  char *v10; // rax
  EarlyFlushRenderPhaseTaskParams *v11; // r14
  RenderSceneryTaskParams *v12; // rcx
  RenderSceneryTaskParams *v13; // rcx
  RenderSceneryTaskParams *v14; // rcx
  RenderSceneryTaskParams *v15; // rcx
  RenderSceneryTaskParams *v16; // rcx
  char *v17; // rax
  UFG::qTask *v18; // rdi
  _QWORD *v19; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r8
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax
  char *v27; // rax
  UFG::qTask *v28; // rsi
  UFG::qSpuElf *v29; // rax
  void (__fastcall *v30)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *v31)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v32)(void *, void *, void *, void *); // r8
  char *v33; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v34; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v35; // rax

  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    *((_QWORD *)v8 + 2) = v8 + 16;
    *((_QWORD *)v8 + 3) = v8 + 16;
    *((_QWORD *)v8 + 4) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x70u, 0x10u);
  v11 = (EarlyFlushRenderPhaseTaskParams *)v10;
  if ( v10 )
  {
    *((_QWORD *)v10 + 2) = v10 + 16;
    *((_QWORD *)v10 + 3) = v10 + 16;
    *((_QWORD *)v10 + 9) = 0i64;
    *((_QWORD *)v10 + 4) = 0i64;
    *((_QWORD *)v10 + 10) = 0i64;
    *((_QWORD *)v10 + 5) = 0i64;
    *((_QWORD *)v10 + 11) = 0i64;
    *((_QWORD *)v10 + 6) = 0i64;
    *((_QWORD *)v10 + 12) = 0i64;
    *((_QWORD *)v10 + 7) = 0i64;
    *((_QWORD *)v10 + 13) = 0i64;
    *((_QWORD *)v10 + 8) = 0i64;
  }
  else
  {
    v11 = 0i64;
  }
  v11->render_world = render_world;
  v11->draw_scenery = draw_scenery;
  v11->render_phase = (Illusion::RenderPhase *)v9;
  if ( render_world && draw_scenery )
  {
    v12 = flush_context->mSceneryTaskResults->mSceneryTaskParams[0];
    v11->scenery_results[0] = v12->mMainMemRenderQueueResults;
    v11->scenery_layers[0] = (RenderQueueLayer *)v12->mRenderQueueLayer_Remote;
    v13 = flush_context->mSceneryTaskResults->mSceneryTaskParams[1];
    v11->scenery_results[1] = v13->mMainMemRenderQueueResults;
    v11->scenery_layers[1] = (RenderQueueLayer *)v13->mRenderQueueLayer_Remote;
    v14 = flush_context->mSceneryTaskResults->mSceneryTaskParams[2];
    v11->scenery_results[2] = v14->mMainMemRenderQueueResults;
    v11->scenery_layers[2] = (RenderQueueLayer *)v14->mRenderQueueLayer_Remote;
    v15 = flush_context->mSceneryTaskResults->mSceneryTaskParams[3];
    v11->scenery_results[3] = v15->mMainMemRenderQueueResults;
    v11->scenery_layers[3] = (RenderQueueLayer *)v15->mRenderQueueLayer_Remote;
    v16 = flush_context->mSceneryTaskResults->mSceneryTaskParams[4];
    v11->scenery_results[4] = v16->mMainMemRenderQueueResults;
    v11->scenery_layers[4] = (RenderQueueLayer *)v16->mRenderQueueLayer_Remote;
  }
  v17 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v18 = (UFG::qTask *)v17;
  if ( v17 )
  {
    *(_QWORD *)v17 = v17;
    *((_QWORD *)v17 + 1) = v17;
    v19 = v17 + 16;
    *v19 = v19;
    v19[1] = v19;
    mSpuElf = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mSpuElf;
    mTaskFunctionSPU = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionSPU;
    mTaskFunctionPPU = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionPPU;
    mTaskFunctionOffload = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v18->mTaskGroup = 0i64;
    v18->mFlags = 2;
    v18->mSyncVars.i64 = 0i64;
    v18->mSyncVars.v.mDependents = 0i64;
    v18->mFunctionDeclData = &gTaskFunctionDeclData_EarlyFlushRenderPhaseTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v18->mSPUElfAddress = mAddress;
    v18->mSPUFunction = mTaskFunctionSPU;
    v18->mPPUFunction = mTaskFunctionPPU;
    v18->mParam0 = v11;
    v18->mParam1 = 0i64;
    v18->mParam2 = 0i64;
    v18->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v18->mFlags = 130;
      v18->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v18;
  v18->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v18->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v18;
  v27 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v28 = (UFG::qTask *)v27;
  if ( v27 )
  {
    *(_QWORD *)v27 = v27;
    *((_QWORD *)v27 + 1) = v27;
    *((_QWORD *)v27 + 2) = v27 + 16;
    *((_QWORD *)v27 + 3) = v27 + 16;
    v29 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mSpuElf;
    v30 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionSPU;
    v31 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionPPU;
    v32 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mCurrentSPUEnabled )
    {
      v29 = 0i64;
      v30 = 0i64;
      v32 = 0i64;
    }
    v28->mTaskGroup = 0i64;
    v28->mFlags = 2;
    v28->mSyncVars.i64 = 0i64;
    v28->mSyncVars.v.mDependents = 0i64;
    v28->mFunctionDeclData = &gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask;
    if ( v29 )
      v33 = v29->mAddress;
    else
      v33 = 0i64;
    v28->mSPUElfAddress = v33;
    v28->mSPUFunction = v30;
    v28->mPPUFunction = v31;
    v28->mParam0 = 0i64;
    v28->mParam1 = 0i64;
    v28->mParam2 = 0i64;
    v28->mParam3 = 0i64;
    if ( v32 )
    {
      v28->mFlags = 130;
      v28->mOffloadThread = 0;
    }
  }
  v34 = UFG::gTaskManager.mSingleFrameTasks;
  v35 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v35->mNext = v28;
  v28->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v35;
  v28->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &v34->mNode;
  v34->mNode.mPrev = v28;
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v18, v28);
  if ( job_queue->mRunningTask )
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v18, job_queue->mRunningTask);
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v18);
  job_queue->mRunningTask = v18;
  flush_context->mEarlyFlushTaskParams = v11;
  flush_context->mEarlyFlushTask = v18;
  flush_context->mEarlyFlushTaskTriggerTask = v28;
}

// File Line: 2634
// RVA: 0x4D7E0
void __fastcall EarlyFlushToIllusionTrigger(FlushContext *flush_context, MainViewTargetParams *main_view_target_params)
{
  Illusion::RenderQueue *mCommandQueue; // rcx
  FlushContext *mNext; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v6; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rdx
  UFG::qTaskGroup *v8; // rdi
  char *v9; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v10; // r8
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v14; // r8
  Illusion::QueueCommandBucket *v15; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v18; // r8
  Illusion::QueueCommandBucket *v19; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v22; // r8
  Illusion::QueueCommandBucket *v23; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_pre_scenery_queues; // r8
  Illusion::QueueCommandBucket *v27; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v28; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v29; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v30; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v31; // rax
  UFG::qNode<SerializationList,SerializationList> *v32; // rcx
  UFG::qNode<SerializationList,SerializationList> *v33; // rax
  SerializationList serialization_list; // [rsp+28h] [rbp-28h] BYREF

  serialization_list.mPrev = &serialization_list;
  serialization_list.mNext = &serialization_list;
  serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
  serialization_list.mList.mNode.mNext = &serialization_list.mList.mNode;
  serialization_list.mCommandQueue = 0i64;
  mCommandQueue = 0i64;
  mNext = (FlushContext *)flush_context->mRenderQueues[0].mNode.mNext;
  if ( mNext == flush_context )
  {
    mPrev = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v6 = serialization_list.mList.mNode.mPrev;
    mPrev = flush_context->mRenderQueues[0].mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)mNext;
    mNext->mRenderQueues[0].mNode.mPrev = v6;
    mPrev->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = mPrev;
    flush_context->mRenderQueues[0].mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)flush_context;
    flush_context->mRenderQueues[0].mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)flush_context;
    mCommandQueue = serialization_list.mCommandQueue;
  }
  v8 = flush_context->mSkinningGroups[0];
  if ( v8 && v8->mNumTasks )
  {
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    if ( v9 )
    {
      *(_QWORD *)v9 = v8;
      *((_QWORD *)v9 + 1) = SerializationList::SyncTaskGroupCallback;
    }
    else
    {
      v9 = 0i64;
    }
    SerializationList::AddCommand(&serialization_list, 17, v9);
    mCommandQueue = serialization_list.mCommandQueue;
    mPrev = serialization_list.mList.mNode.mPrev;
  }
  v10 = &flush_context->mRenderQueues[1];
  if ( mCommandQueue )
  {
    mFreeBucket = mCommandQueue->mFreeBucket;
    if ( mFreeBucket )
    {
      mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
    mCommandQueue = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v12 = flush_context->mRenderQueues[1].mNode.mNext;
  if ( v12 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v10 )
  {
    v13 = v10->mNode.mPrev;
    mPrev->mNext = v12;
    v12->mPrev = mPrev;
    v13->mNext = &serialization_list.mList.mNode;
    mPrev = v13;
    serialization_list.mList.mNode.mPrev = v13;
    v10->mNode.mPrev = &v10->mNode;
    flush_context->mRenderQueues[1].mNode.mNext = &flush_context->mRenderQueues[1].mNode;
    mCommandQueue = serialization_list.mCommandQueue;
  }
  v14 = &flush_context->mRenderQueues[2];
  if ( mCommandQueue )
  {
    v15 = mCommandQueue->mFreeBucket;
    if ( v15 )
    {
      mCommandQueue->mCommandCount += v15->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
    mCommandQueue = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v16 = flush_context->mRenderQueues[2].mNode.mNext;
  if ( v16 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v14 )
  {
    v17 = v14->mNode.mPrev;
    mPrev->mNext = v16;
    v16->mPrev = mPrev;
    v17->mNext = &serialization_list.mList.mNode;
    mPrev = v17;
    serialization_list.mList.mNode.mPrev = v17;
    v14->mNode.mPrev = &v14->mNode;
    flush_context->mRenderQueues[2].mNode.mNext = &flush_context->mRenderQueues[2].mNode;
    mCommandQueue = serialization_list.mCommandQueue;
  }
  v18 = &flush_context->mRenderQueues[3];
  if ( mCommandQueue )
  {
    v19 = mCommandQueue->mFreeBucket;
    if ( v19 )
    {
      mCommandQueue->mCommandCount += v19->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
    mCommandQueue = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v20 = flush_context->mRenderQueues[3].mNode.mNext;
  if ( v20 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v18 )
  {
    v21 = v18->mNode.mPrev;
    mPrev->mNext = v20;
    v20->mPrev = mPrev;
    v21->mNext = &serialization_list.mList.mNode;
    mPrev = v21;
    serialization_list.mList.mNode.mPrev = v21;
    v18->mNode.mPrev = &v18->mNode;
    flush_context->mRenderQueues[3].mNode.mNext = &flush_context->mRenderQueues[3].mNode;
    mCommandQueue = serialization_list.mCommandQueue;
  }
  v22 = &flush_context->mRenderQueues[4];
  if ( mCommandQueue )
  {
    v23 = mCommandQueue->mFreeBucket;
    if ( v23 )
    {
      mCommandQueue->mCommandCount += v23->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
    mCommandQueue = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v24 = flush_context->mRenderQueues[4].mNode.mNext;
  if ( v24 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v22 )
  {
    v25 = v22->mNode.mPrev;
    mPrev->mNext = v24;
    v24->mPrev = mPrev;
    v25->mNext = &serialization_list.mList.mNode;
    mPrev = v25;
    serialization_list.mList.mNode.mPrev = v25;
    v22->mNode.mPrev = &v22->mNode;
    flush_context->mRenderQueues[4].mNode.mNext = &flush_context->mRenderQueues[4].mNode;
    mCommandQueue = serialization_list.mCommandQueue;
  }
  if ( flush_context->mEarlyFlushTaskParams->render_world )
  {
    GenerateGBufferPreScenerySerializationList(&serialization_list, flush_context, main_view_target_params);
    mCommandQueue = serialization_list.mCommandQueue;
    mPrev = serialization_list.mList.mNode.mPrev;
  }
  p_pre_scenery_queues = &flush_context->mEarlyFlushTaskParams->pre_scenery_queues;
  if ( mCommandQueue )
  {
    v27 = mCommandQueue->mFreeBucket;
    if ( v27 )
    {
      mCommandQueue->mCommandCount += v27->mNumCommands;
      mCommandQueue->mFreeBucket = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
    serialization_list.mCommandQueue = 0i64;
  }
  v28 = serialization_list.mList.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)serialization_list.mList.mNode.mNext != &serialization_list.mList )
  {
    v29 = p_pre_scenery_queues->mNode.mPrev;
    v29->mNext = serialization_list.mList.mNode.mNext;
    v28->mPrev = v29;
    mPrev->mNext = &p_pre_scenery_queues->mNode;
    p_pre_scenery_queues->mNode.mPrev = mPrev;
    serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mNext = &serialization_list.mList.mNode;
  }
  UFG::qTaskManager::Queue(&UFG::gTaskManager, flush_context->mEarlyFlushTaskTriggerTask);
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&serialization_list.mList);
  v30 = serialization_list.mList.mNode.mPrev;
  v31 = serialization_list.mList.mNode.mNext;
  serialization_list.mList.mNode.mPrev->mNext = serialization_list.mList.mNode.mNext;
  v31->mPrev = v30;
  v32 = serialization_list.mPrev;
  v33 = serialization_list.mNext;
  serialization_list.mPrev->mNext = serialization_list.mNext;
  v33->mPrev = v32;
}

// File Line: 2668
// RVA: 0x51A60
void __fastcall LateFlushToIllusion(
        FlushContext *flush_context,
        UFG::RenderContext *render_context,
        float fTime,
        MainViewTargetParams *main_view_target_params)
{
  __int64 v7; // rbx
  __int64 v8; // rsi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // r8
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v15; // rdx
  __int64 v16; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // rax
  FlushJobQueue *v19; // r14
  UFG::qTaskGroup *v20; // rbx
  UFG::ShadowRenderQueueTaskResults *mShadowTaskResults; // rcx
  SerializationList *ListAndAccumulate; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *i; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rax
  SerializationList *v26; // rax
  Illusion::RenderQueue *mCommandQueue; // rdx
  Illusion::QueueCommandBucket *mFreeBucket; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v29; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v30; // rax
  SerializationList *v31; // rax
  bool v32; // r8
  SerializationList *j; // rdx
  UFG::qNode<SerializationList,SerializationList> *v34; // rcx
  UFG::qNode<SerializationList,SerializationList> *v35; // rax
  UFG::qTaskGroup *v36; // rbx
  UFG::qTaskGroup *v37; // rbx
  char *v38; // rax
  UFG::SpotShadowRenderQueueTaskResults *mSpotShadowTaskResults; // r8
  int v40; // edx
  __int64 v41; // rax
  UFG::qTaskGroup **v42; // rcx
  UFG::qTaskGroup *v43; // rdx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v47; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v48; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v49; // rcx
  unsigned int v50; // ebx
  SerializationList *k; // rdx
  UFG::qNode<SerializationList,SerializationList> *v52; // rcx
  UFG::qNode<SerializationList,SerializationList> *v53; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v54; // rdx
  __int64 v55; // rcx
  __int64 v56; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v57; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v58; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v59; // r8
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v60; // rdx
  __int64 v61; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v62; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v63; // rax
  UFG::qNode<SerializationList,SerializationList> *v64; // rcx
  UFG::qNode<SerializationList,SerializationList> *v65; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v66; // rdx
  __int64 v67; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v68; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v69; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v70; // rcx
  UFG::qTaskGroup *v71; // rbx
  char *v72; // rbx
  char *v73; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v74; // rax
  __int64 v75; // rdx
  __int64 v76; // rax
  __int64 v77; // rcx
  char *v78; // rax
  char *v79; // rdx
  __int64 v80; // rax
  __int64 v81; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v82; // rdx
  char *v83; // rbx
  __int64 v84; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v85; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v86; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v87; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v88; // rdx
  __int64 v89; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v90; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v91; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v92; // rdx
  FlushContext *v93; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v94; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v95; // rdx
  __int64 v96; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v97; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v98; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v99; // rdx
  __int64 v100; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v101; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v102; // rax
  char *v103; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v104; // rax
  __int64 v105; // rdx
  __int64 v106; // rax
  __int64 v107; // rcx
  char *v108; // rax
  char *v109; // rdx
  __int64 v110; // rax
  __int64 v111; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v112; // r8
  char *v113; // rbx
  __int64 v114; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v115; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v116; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v117; // rcx
  char *v118; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v119; // rax
  __int64 v120; // rdx
  __int64 v121; // rax
  __int64 v122; // rcx
  char *v123; // rax
  char *v124; // rdx
  __int64 v125; // rax
  __int64 v126; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v127; // r8
  char *v128; // rcx
  __int64 v129; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v130; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v131; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v132; // rdx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v133; // r8
  __int64 v134; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v135; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v136; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v137; // r8
  FlushContext *v138; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v139; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v140; // r8
  FlushContext *v141; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v142; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v143; // r8
  FlushContext *v144; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v145; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v146; // r8
  FlushContext *v147; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v148; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v149; // r8
  FlushContext *v150; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v151; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v152; // r8
  FlushContext *v153; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v154; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v155; // r8
  FlushContext *v156; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v157; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v158; // rdi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v159; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v160; // rax
  UFG::TimeOfDayManager *Instance; // rax
  UFG::qTask *updated; // rax
  UFG::qNode<SerializationList,SerializationList> *v163; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v164; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v165; // rcx
  UFG::qNode<SerializationList,SerializationList> *v166; // rcx
  UFG::qNode<SerializationList,SerializationList> *v167; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v168; // [rsp+10h] [rbp-79h]
  __int64 v169; // [rsp+18h] [rbp-71h]
  __int64 v170; // [rsp+18h] [rbp-71h]
  __int64 v171; // [rsp+18h] [rbp-71h]
  __int64 v172; // [rsp+18h] [rbp-71h]
  char *v173; // [rsp+18h] [rbp-71h]
  bool flush_to_new_submission_thread[4]; // [rsp+20h] [rbp-69h] BYREF
  float v175; // [rsp+24h] [rbp-65h]
  __int64 v176; // [rsp+28h] [rbp-61h]
  SerializationList serialization_list; // [rsp+30h] [rbp-59h] BYREF
  __int64 v178; // [rsp+58h] [rbp-31h]
  UFG::qList<SerializationList,SerializationList,1,0> v179; // [rsp+60h] [rbp-29h] BYREF
  char *v180; // [rsp+70h] [rbp-19h]
  __int64 v181; // [rsp+78h] [rbp-11h]
  void *p_mList; // [rsp+E8h] [rbp+5Fh]
  UFG::qList<SerializationList,SerializationList,1,0> *v183; // [rsp+F0h] [rbp+67h]
  FlushJobQueue *v184; // [rsp+108h] [rbp+7Fh]

  v181 = -2i64;
  serialization_list.mPrev = &serialization_list;
  serialization_list.mNext = &serialization_list;
  p_mList = &serialization_list.mList;
  serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
  UFG::qTaskManager::Sync(&UFG::gTaskManager, flush_context->mEarlyFlushTask);
  if ( render_context->mRenderFeatures.mWorld )
  {
    if ( render_context->mRenderFeatures.mScenery )
    {
      v7 = 1i64;
      v8 = 4i64;
      do
      {
        Render::ViewMetrics::Accumulate(
          &render_context->mRenderStats,
          &flush_context->mSceneryTaskResults->mSceneryViewMetrics[v7++]);
        --v8;
      }
      while ( v8 );
    }
    GenerateGBufferPostScenerySerializationList(&serialization_list, flush_context, main_view_target_params);
  }
  v9 = &flush_context->mRenderQueues[5];
  v10 = v169;
  if ( v169 )
  {
    v11 = *(_QWORD *)(v169 + 40);
    if ( v11 )
    {
      *(_DWORD *)(v169 + 72) += *(_DWORD *)(v11 + 24);
      *(_QWORD *)(v169 + 40) = 0i64;
    }
    v10 = 0i64;
    v169 = 0i64;
  }
  mNext = flush_context->mRenderQueues[5].mNode.mNext;
  if ( mNext == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9 )
  {
    mPrev = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v13 = serialization_list.mList.mNode.mPrev;
    mPrev = v9->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = mNext;
    mNext->mPrev = v13;
    mPrev->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = mPrev;
    v9->mNode.mPrev = &v9->mNode;
    flush_context->mRenderQueues[5].mNode.mNext = &flush_context->mRenderQueues[5].mNode;
    v10 = v169;
  }
  v15 = &flush_context->mRenderQueues[8];
  if ( v10 )
  {
    v16 = *(_QWORD *)(v10 + 40);
    if ( v16 )
    {
      *(_DWORD *)(v10 + 72) += *(_DWORD *)(v16 + 24);
      *(_QWORD *)(v10 + 40) = 0i64;
      mPrev = serialization_list.mList.mNode.mPrev;
    }
  }
  v17 = flush_context->mRenderQueues[8].mNode.mNext;
  if ( v17 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v15 )
  {
    v18 = v15->mNode.mPrev;
    mPrev->mNext = v17;
    v17->mPrev = mPrev;
    v18->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v18;
    v15->mNode.mPrev = &v15->mNode;
    flush_context->mRenderQueues[8].mNode.mNext = &flush_context->mRenderQueues[8].mNode;
  }
  v19 = v184;
  FlushJobQueue::AddFlushJob(v184, &serialization_list, 5u, 0x7C00u, 0);
  if ( render_context->mRenderFeatures.mWorld )
  {
    v20 = flush_context->mSkinningGroups[1];
    if ( v20 )
    {
      if ( v20->mNumTasks && !v20->mStartTask.mSyncVars.v.mState )
      {
        if ( v19->mRunningTask )
          UFG::qTaskManager::AddDependent(&UFG::gTaskManager, flush_context->mSkinningGroups[1], v19->mRunningTask);
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v20);
        v19->mRunningTask = &v20->mEndTask;
      }
    }
  }
  mShadowTaskResults = flush_context->mShadowTaskResults;
  if ( mShadowTaskResults )
    UFG::qTaskManager::Sync(
      &UFG::gTaskManager,
      *((UFG::qTaskGroup **)&mShadowTaskResults->mShadowsBucketIndices[3].do_not_remove
      + mShadowTaskResults->mNumCascades
      + 3));
  *(float *)flush_to_new_submission_thread = 1.0 / (float)(int)(5 * gShadowsRenderPhase_MaxCommands);
  v175 = 1.0 / (float)(int)(5 * gShadowsRenderPhase_MaxPrimitives);
  v176 = 0i64;
  serialization_list.mPrev = 0i64;
  p_mList = &serialization_list.mNext;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list.mNext;
  serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&serialization_list.mNext;
  ListAndAccumulate = SerializationListBuilder::GetListAndAccumulate(
                        (SerializationListBuilder *)flush_to_new_submission_thread,
                        1u,
                        0);
  SerializationList::AddCommand(ListAndAccumulate, 22, &UFG::RenderWorld::msGpuTimer_Lighting_Shadows);
  GenerateShadowSerializationLists(
    (SerializationListBuilder *)flush_to_new_submission_thread,
    flush_context,
    render_context->mRenderSun);
  for ( i = flush_context->mRenderQueues[9].mNode.mNext;
        i != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&flush_context->mRenderQueues[9];
        i = flush_context->mRenderQueues[9].mNode.mNext )
  {
    v24 = i->mPrev;
    v25 = i->mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    i->mPrev = i;
    i->mNext = i;
    v26 = SerializationListBuilder::GetListAndAccumulate(
            (SerializationListBuilder *)flush_to_new_submission_thread,
            (unsigned int)i[4].mNext,
            HIDWORD(i[4].mNext));
    mCommandQueue = v26->mCommandQueue;
    if ( mCommandQueue )
    {
      mFreeBucket = mCommandQueue->mFreeBucket;
      if ( mFreeBucket )
      {
        mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
        mCommandQueue->mFreeBucket = 0i64;
      }
      v26->mCommandQueue = 0i64;
    }
    v29 = &v26->mList;
    v30 = v26->mList.mNode.mPrev;
    v30->mNext = i;
    i->mPrev = v30;
    i->mNext = &v29->mNode;
    v29->mNode.mPrev = i;
  }
  v31 = SerializationListBuilder::GetListAndAccumulate(
          (SerializationListBuilder *)flush_to_new_submission_thread,
          1u,
          0);
  SerializationList::AddCommand(v31, 23, &UFG::RenderWorld::msGpuTimer_Lighting_Shadows);
  v32 = 1;
  for ( j = (SerializationList *)serialization_list.mList.mNode.mPrev;
        (UFG::qNode<SerializationList,SerializationList> **)serialization_list.mList.mNode.mPrev != &serialization_list.mNext;
        j = (SerializationList *)serialization_list.mList.mNode.mPrev )
  {
    v34 = j->mPrev;
    v35 = j->mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    j->mPrev = j;
    j->mNext = j;
    FlushJobQueue::AddFlushJob(v19, j, 5u, 0x7C1Fu, v32);
    v32 = 0;
  }
  v36 = flush_context->mSkinningGroups[2];
  if ( v36 && v36->mNumTasks && !v36->mStartTask.mSyncVars.v.mState )
  {
    if ( v19->mRunningTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, flush_context->mSkinningGroups[2], v19->mRunningTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v36);
    v19->mRunningTask = &v36->mEndTask;
  }
  v37 = flush_context->mSkinningGroups[3];
  if ( v37 && v37->mNumTasks )
  {
    v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    p_mList = v38;
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v38;
    if ( v38 )
    {
      *(_QWORD *)v38 = v37;
      *((_QWORD *)v38 + 1) = SerializationList::SyncTaskGroupCallback;
    }
    else
    {
      v38 = 0i64;
    }
    SerializationList::AddCommand(&serialization_list, 17, v38);
  }
  mSpotShadowTaskResults = flush_context->mSpotShadowTaskResults;
  if ( mSpotShadowTaskResults )
  {
    v40 = mSpotShadowTaskResults->mNumActiveSpotShadows - 1;
    v41 = v40;
    if ( !mSpotShadowTaskResults->mSpotShadowTaskGroups[v40] )
    {
      v42 = &mSpotShadowTaskResults->mSpotShadowTaskGroups[v40];
      do
      {
        if ( v41 <= 0 )
          break;
        --v40;
        --v41;
        --v42;
      }
      while ( !*v42 );
    }
    v43 = mSpotShadowTaskResults->mSpotShadowTaskGroups[v40];
    if ( v43 )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v43);
  }
  v44 = &flush_context->mRenderQueues[12];
  v45 = v170;
  if ( v170 )
  {
    v46 = *(_QWORD *)(v170 + 40);
    if ( v46 )
    {
      *(_DWORD *)(v170 + 72) += *(_DWORD *)(v46 + 24);
      *(_QWORD *)(v170 + 40) = 0i64;
    }
    v45 = 0i64;
    v170 = 0i64;
  }
  v47 = flush_context->mRenderQueues[12].mNode.mNext;
  if ( v47 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v44 )
  {
    v48 = serialization_list.mList.mNode.mPrev;
    v49 = v44->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v47;
    v47->mPrev = v48;
    v49->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v49;
    v44->mNode.mPrev = &v44->mNode;
    flush_context->mRenderQueues[12].mNode.mNext = &flush_context->mRenderQueues[12].mNode;
    v45 = v170;
  }
  if ( gSpotShadowCount )
  {
    v50 = 0;
    p_mList = &v179;
    v183 = &v179;
    do
    {
      *(float *)&serialization_list.mList.mNode.mNext = 1.0 / (float)(int)(5 * gShadowsRenderPhase_MaxCommands);
      *((float *)&serialization_list.mList.mNode.mNext + 1) = 1.0 / (float)(int)(5 * gShadowsRenderPhase_MaxPrimitives);
      serialization_list.mCommandQueue = 0i64;
      v178 = 0i64;
      v179.mNode.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v179;
      v179.mNode.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v179;
      GenerateSpotShadowSerializationLists(
        (SerializationListBuilder *)&serialization_list.mList.mNode.mNext,
        flush_context,
        v50);
      for ( k = (SerializationList *)v179.mNode.mNext;
            (UFG::qList<SerializationList,SerializationList,1,0> *)v179.mNode.mNext != &v179;
            k = (SerializationList *)v179.mNode.mNext )
      {
        v52 = k->mPrev;
        v53 = k->mNext;
        v52->mNext = v53;
        v53->mPrev = v52;
        k->mPrev = k;
        k->mNext = k;
        FlushJobQueue::AddFlushJob(v19, k, 5u, 0x7C1Fu, 0);
      }
      v54 = &flush_context->mRenderQueues[v50 + 13];
      v55 = v171;
      if ( v171 )
      {
        v56 = *(_QWORD *)(v171 + 40);
        if ( v56 )
        {
          *(_DWORD *)(v171 + 72) += *(_DWORD *)(v56 + 24);
          *(_QWORD *)(v171 + 40) = 0i64;
        }
        v55 = 0i64;
        v171 = 0i64;
      }
      v57 = v54->mNode.mNext;
      if ( v57 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v54 )
      {
        v59 = serialization_list.mList.mNode.mPrev;
      }
      else
      {
        v58 = serialization_list.mList.mNode.mPrev;
        v59 = v54->mNode.mPrev;
        serialization_list.mList.mNode.mPrev->mNext = v57;
        v57->mPrev = v58;
        v59->mNext = &serialization_list.mList.mNode;
        serialization_list.mList.mNode.mPrev = v59;
        v54->mNode.mPrev = &v54->mNode;
        v54->mNode.mNext = &v54->mNode;
        v55 = v171;
      }
      v60 = &flush_context->mRenderQueues[v50 + 21];
      if ( v55 )
      {
        v61 = *(_QWORD *)(v55 + 40);
        if ( v61 )
        {
          *(_DWORD *)(v55 + 72) += *(_DWORD *)(v61 + 24);
          *(_QWORD *)(v55 + 40) = 0i64;
          v59 = serialization_list.mList.mNode.mPrev;
        }
      }
      v62 = v60->mNode.mNext;
      if ( v62 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v60 )
      {
        v63 = v60->mNode.mPrev;
        v59->mNext = v62;
        v62->mPrev = v59;
        v63->mNext = &serialization_list.mList.mNode;
        serialization_list.mList.mNode.mPrev = v63;
        v60->mNode.mPrev = &v60->mNode;
        v60->mNode.mNext = &v60->mNode;
      }
      FlushJobQueue::AddFlushJob(v19, &serialization_list, 2u, 0x7FE0u, 0);
      UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes(&v179);
      v64 = v179.mNode.mPrev;
      v65 = v179.mNode.mNext;
      v179.mNode.mPrev->mNext = v179.mNode.mNext;
      v65->mPrev = v64;
      v179.mNode.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v179;
      v179.mNode.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v179;
      ++v50;
    }
    while ( v50 < gSpotShadowCount );
    v45 = v172;
  }
  v66 = &flush_context->mRenderQueues[29];
  if ( v45 )
  {
    v67 = *(_QWORD *)(v45 + 40);
    if ( v67 )
    {
      *(_DWORD *)(v45 + 72) += *(_DWORD *)(v67 + 24);
      *(_QWORD *)(v45 + 40) = 0i64;
    }
  }
  v68 = flush_context->mRenderQueues[29].mNode.mNext;
  if ( v68 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v66 )
  {
    v69 = serialization_list.mList.mNode.mPrev;
    v70 = v66->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v68;
    v68->mPrev = v69;
    v70->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v70;
    v66->mNode.mPrev = &v66->mNode;
    flush_context->mRenderQueues[29].mNode.mNext = &flush_context->mRenderQueues[29].mNode;
  }
  FlushJobQueue::AddFlushJob(v19, &serialization_list, 2u, 0x7FE0u, 0);
  v71 = flush_context->mSkinningGroups[3];
  if ( v71 && v71->mNumTasks && !v71->mStartTask.mSyncVars.v.mState )
  {
    if ( v19->mRunningTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, flush_context->mSkinningGroups[3], v19->mRunningTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v71);
    v19->mRunningTask = &v71->mEndTask;
  }
  v72 = v173;
  if ( !v173 )
  {
    v73 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v72 = v73;
    p_mList = v73;
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v73;
    if ( v73 )
    {
      *(_QWORD *)v73 = v73;
      *((_QWORD *)v73 + 1) = v73;
      v180 = v73 + 16;
      *((_QWORD *)v73 + 2) = v73 + 16;
      *((_QWORD *)v73 + 3) = v73 + 16;
      UFG::qMemSet(v73 + 96, 0, 0x400u);
      *((_QWORD *)v72 + 11) = 0i64;
      *((_QWORD *)v72 + 10) = 0i64;
      *((_DWORD *)v72 + 8) = 0;
      *((_QWORD *)v72 + 5) = 0i64;
      *((_QWORD *)v72 + 6) = 0i64;
      *((_QWORD *)v72 + 7) = 0i64;
      *((_QWORD *)v72 + 8) = 0i64;
      *((_QWORD *)v72 + 9) = 0i64;
    }
    else
    {
      v72 = 0i64;
    }
    v173 = v72;
    v74 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v72;
    *(_QWORD *)v72 = v74;
    *((_QWORD *)v72 + 1) = &serialization_list.mList;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v72;
  }
  v75 = *((_QWORD *)v72 + 5);
  if ( v75 )
  {
    v76 = *(unsigned int *)(v75 + 24);
    if ( (unsigned int)v76 < 0x7E )
    {
      v77 = v75 + 16 * (v76 + 2);
      *(_DWORD *)(v75 + 24) = v76 + 1;
      goto LABEL_102;
    }
    *((_DWORD *)v72 + 18) += *(_DWORD *)(v75 + 24);
    *((_QWORD *)v72 + 5) = 0i64;
  }
  v78 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v79 = v78;
  p_mList = v78;
  if ( v78 )
  {
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v78;
    *(_QWORD *)v78 = v78;
    *((_QWORD *)v78 + 1) = v78;
    *((_QWORD *)v78 + 2) = 0i64;
    *((_DWORD *)v78 + 6) = 0;
    v80 = *((_QWORD *)v72 + 2);
    *(_QWORD *)(v80 + 8) = v79;
    *(_QWORD *)v79 = v80;
    *((_QWORD *)v79 + 1) = v72 + 16;
    *((_QWORD *)v72 + 2) = v79;
    *((_QWORD *)v72 + 5) = v79;
  }
  v81 = *((_QWORD *)v72 + 5);
  if ( v81 )
  {
    *(_DWORD *)(v81 + 24) = 1;
    v77 = *((_QWORD *)v72 + 5) + 32i64;
LABEL_102:
    if ( v77 )
    {
      *(_DWORD *)v77 = 22;
      *(_QWORD *)(v77 + 8) = &UFG::RenderWorld::msGpuTimer_PostFX;
    }
  }
  v82 = &flush_context->mRenderQueues[10];
  v83 = v173;
  if ( v173 )
  {
    v84 = *((_QWORD *)v173 + 5);
    if ( v84 )
    {
      *((_DWORD *)v173 + 18) += *(_DWORD *)(v84 + 24);
      *((_QWORD *)v173 + 5) = 0i64;
    }
    v83 = 0i64;
    v173 = 0i64;
  }
  v85 = flush_context->mRenderQueues[10].mNode.mNext;
  if ( v85 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v82 )
  {
    v87 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v86 = serialization_list.mList.mNode.mPrev;
    v87 = v82->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v85;
    v85->mPrev = v86;
    v87->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v87;
    v82->mNode.mPrev = &v82->mNode;
    flush_context->mRenderQueues[10].mNode.mNext = &flush_context->mRenderQueues[10].mNode;
    v83 = v173;
  }
  v88 = &flush_context->mRenderQueues[11];
  if ( v83 )
  {
    v89 = *((_QWORD *)v83 + 5);
    if ( v89 )
    {
      *((_DWORD *)v83 + 18) += *(_DWORD *)(v89 + 24);
      *((_QWORD *)v83 + 5) = 0i64;
      v87 = serialization_list.mList.mNode.mPrev;
    }
    v83 = 0i64;
    v173 = 0i64;
  }
  v90 = flush_context->mRenderQueues[11].mNode.mNext;
  if ( v90 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v88 )
  {
    v91 = v88->mNode.mPrev;
    v87->mNext = v90;
    v90->mPrev = v87;
    v91->mNext = &serialization_list.mList.mNode;
    v87 = v91;
    serialization_list.mList.mNode.mPrev = v91;
    v88->mNode.mPrev = &v88->mNode;
    flush_context->mRenderQueues[11].mNode.mNext = &flush_context->mRenderQueues[11].mNode;
    v83 = v173;
  }
  v92 = &flush_context->mRenderQueues[30];
  v93 = (FlushContext *)flush_context->mRenderQueues[30].mNode.mNext;
  if ( v93 != (FlushContext *)&flush_context->mRenderQueues[30] )
  {
    v94 = v92->mNode.mPrev;
    v87->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v93;
    v93->mRenderQueues[0].mNode.mPrev = v87;
    v94->mNext = &serialization_list.mList.mNode;
    v87 = v94;
    serialization_list.mList.mNode.mPrev = v94;
    v92->mNode.mPrev = &v92->mNode;
    flush_context->mRenderQueues[30].mNode.mNext = &flush_context->mRenderQueues[30].mNode;
    v83 = v173;
  }
  if ( render_context->mRenderFeatures.mWorld )
  {
    GenerateGBufferAlphaSerializationList(&serialization_list, flush_context, main_view_target_params);
    v83 = v173;
    v87 = serialization_list.mList.mNode.mPrev;
  }
  v95 = &flush_context->mRenderQueues[31];
  if ( v83 )
  {
    v96 = *((_QWORD *)v83 + 5);
    if ( v96 )
    {
      *((_DWORD *)v83 + 18) += *(_DWORD *)(v96 + 24);
      *((_QWORD *)v83 + 5) = 0i64;
      v87 = serialization_list.mList.mNode.mPrev;
    }
    v83 = 0i64;
    v173 = 0i64;
  }
  v97 = flush_context->mRenderQueues[31].mNode.mNext;
  if ( v97 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v95 )
  {
    v98 = v95->mNode.mPrev;
    v87->mNext = v97;
    v97->mPrev = v87;
    v98->mNext = &serialization_list.mList.mNode;
    v87 = v98;
    serialization_list.mList.mNode.mPrev = v98;
    v95->mNode.mPrev = &v95->mNode;
    flush_context->mRenderQueues[31].mNode.mNext = &flush_context->mRenderQueues[31].mNode;
    v83 = v173;
  }
  v99 = &flush_context->mRenderQueues[32];
  if ( v83 )
  {
    v100 = *((_QWORD *)v83 + 5);
    if ( v100 )
    {
      *((_DWORD *)v83 + 18) += *(_DWORD *)(v100 + 24);
      *((_QWORD *)v83 + 5) = 0i64;
      v87 = serialization_list.mList.mNode.mPrev;
    }
    v83 = 0i64;
    v173 = 0i64;
  }
  v101 = flush_context->mRenderQueues[32].mNode.mNext;
  if ( v101 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v99 )
  {
    v102 = v99->mNode.mPrev;
    v87->mNext = v101;
    v101->mPrev = v87;
    v102->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v102;
    v99->mNode.mPrev = &v99->mNode;
    flush_context->mRenderQueues[32].mNode.mNext = &flush_context->mRenderQueues[32].mNode;
    v83 = v173;
  }
  if ( !v83 )
  {
    v103 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v83 = v103;
    p_mList = v103;
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v103;
    if ( v103 )
    {
      *(_QWORD *)v103 = v103;
      *((_QWORD *)v103 + 1) = v103;
      v180 = v103 + 16;
      *((_QWORD *)v103 + 2) = v103 + 16;
      *((_QWORD *)v103 + 3) = v103 + 16;
      UFG::qMemSet(v103 + 96, 0, 0x400u);
      *((_QWORD *)v83 + 11) = 0i64;
      *((_QWORD *)v83 + 10) = 0i64;
      *((_DWORD *)v83 + 8) = 0;
      *((_QWORD *)v83 + 5) = 0i64;
      *((_QWORD *)v83 + 6) = 0i64;
      *((_QWORD *)v83 + 7) = 0i64;
      *((_QWORD *)v83 + 8) = 0i64;
      *((_QWORD *)v83 + 9) = 0i64;
    }
    else
    {
      v83 = 0i64;
    }
    v173 = v83;
    v104 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v83;
    *(_QWORD *)v83 = v104;
    *((_QWORD *)v83 + 1) = &serialization_list.mList;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v83;
  }
  v105 = *((_QWORD *)v83 + 5);
  if ( v105 )
  {
    v106 = *(unsigned int *)(v105 + 24);
    if ( (unsigned int)v106 < 0x7E )
    {
      v107 = v105 + 16 * (v106 + 2);
      *(_DWORD *)(v105 + 24) = v106 + 1;
      goto LABEL_146;
    }
    *((_DWORD *)v83 + 18) += *(_DWORD *)(v105 + 24);
    *((_QWORD *)v83 + 5) = 0i64;
  }
  v108 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v109 = v108;
  p_mList = v108;
  if ( v108 )
  {
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v108;
    *(_QWORD *)v108 = v108;
    *((_QWORD *)v108 + 1) = v108;
    *((_QWORD *)v108 + 2) = 0i64;
    *((_DWORD *)v108 + 6) = 0;
    v110 = *((_QWORD *)v83 + 2);
    *(_QWORD *)(v110 + 8) = v109;
    *(_QWORD *)v109 = v110;
    *((_QWORD *)v109 + 1) = v83 + 16;
    *((_QWORD *)v83 + 2) = v109;
    *((_QWORD *)v83 + 5) = v109;
  }
  v111 = *((_QWORD *)v83 + 5);
  if ( v111 )
  {
    *(_DWORD *)(v111 + 24) = 1;
    v107 = *((_QWORD *)v83 + 5) + 32i64;
LABEL_146:
    if ( v107 )
    {
      *(_DWORD *)v107 = 22;
      *(_QWORD *)(v107 + 8) = &UFG::RenderWorld::msGpuTimer_DOF;
    }
  }
  v112 = &flush_context->mRenderQueues[33];
  v113 = v173;
  if ( v173 )
  {
    v114 = *((_QWORD *)v173 + 5);
    if ( v114 )
    {
      *((_DWORD *)v173 + 18) += *(_DWORD *)(v114 + 24);
      *((_QWORD *)v173 + 5) = 0i64;
    }
    v113 = 0i64;
    v173 = 0i64;
  }
  v115 = flush_context->mRenderQueues[33].mNode.mNext;
  if ( v115 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v112 )
  {
    v116 = serialization_list.mList.mNode.mPrev;
    v117 = v112->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v115;
    v115->mPrev = v116;
    v117->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v117;
    v112->mNode.mPrev = &v112->mNode;
    flush_context->mRenderQueues[33].mNode.mNext = &flush_context->mRenderQueues[33].mNode;
    v113 = v173;
  }
  if ( !v113 )
  {
    v118 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v113 = v118;
    p_mList = v118;
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v118;
    if ( v118 )
    {
      *(_QWORD *)v118 = v118;
      *((_QWORD *)v118 + 1) = v118;
      v180 = v118 + 16;
      *((_QWORD *)v118 + 2) = v118 + 16;
      *((_QWORD *)v118 + 3) = v118 + 16;
      UFG::qMemSet(v118 + 96, 0, 0x400u);
      *((_QWORD *)v113 + 11) = 0i64;
      *((_QWORD *)v113 + 10) = 0i64;
      *((_DWORD *)v113 + 8) = 0;
      *((_QWORD *)v113 + 5) = 0i64;
      *((_QWORD *)v113 + 6) = 0i64;
      *((_QWORD *)v113 + 7) = 0i64;
      *((_QWORD *)v113 + 8) = 0i64;
      *((_QWORD *)v113 + 9) = 0i64;
    }
    else
    {
      v113 = 0i64;
    }
    v173 = v113;
    v119 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v113;
    *(_QWORD *)v113 = v119;
    *((_QWORD *)v113 + 1) = &serialization_list.mList;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v113;
  }
  v120 = *((_QWORD *)v113 + 5);
  if ( v120 )
  {
    v121 = *(unsigned int *)(v120 + 24);
    if ( (unsigned int)v121 < 0x7E )
    {
      v122 = v120 + 16 * (v121 + 2);
      *(_DWORD *)(v120 + 24) = v121 + 1;
      goto LABEL_167;
    }
    *((_DWORD *)v113 + 18) += *(_DWORD *)(v120 + 24);
    *((_QWORD *)v113 + 5) = 0i64;
  }
  v123 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v124 = v123;
  p_mList = v123;
  if ( v123 )
  {
    v183 = (UFG::qList<SerializationList,SerializationList,1,0> *)v123;
    *(_QWORD *)v123 = v123;
    *((_QWORD *)v123 + 1) = v123;
    *((_QWORD *)v123 + 2) = 0i64;
    *((_DWORD *)v123 + 6) = 0;
    v125 = *((_QWORD *)v113 + 2);
    *(_QWORD *)(v125 + 8) = v124;
    *(_QWORD *)v124 = v125;
    *((_QWORD *)v124 + 1) = v113 + 16;
    *((_QWORD *)v113 + 2) = v124;
    *((_QWORD *)v113 + 5) = v124;
  }
  v126 = *((_QWORD *)v113 + 5);
  if ( v126 )
  {
    *(_DWORD *)(v126 + 24) = 1;
    v122 = *((_QWORD *)v113 + 5) + 32i64;
LABEL_167:
    if ( v122 )
    {
      *(_DWORD *)v122 = 23;
      *(_QWORD *)(v122 + 8) = &UFG::RenderWorld::msGpuTimer_DOF;
    }
  }
  v127 = &flush_context->mRenderQueues[34];
  v128 = v173;
  if ( v173 )
  {
    v129 = *((_QWORD *)v173 + 5);
    if ( v129 )
    {
      *((_DWORD *)v173 + 18) += *(_DWORD *)(v129 + 24);
      *((_QWORD *)v173 + 5) = 0i64;
    }
    v128 = 0i64;
    v173 = 0i64;
  }
  v130 = flush_context->mRenderQueues[34].mNode.mNext;
  if ( v130 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v127 )
  {
    v132 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v131 = serialization_list.mList.mNode.mPrev;
    v132 = v127->mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v130;
    v130->mPrev = v131;
    v132->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v132;
    v127->mNode.mPrev = &v127->mNode;
    flush_context->mRenderQueues[34].mNode.mNext = &flush_context->mRenderQueues[34].mNode;
    v128 = v173;
  }
  v133 = &flush_context->mRenderQueues[35];
  if ( v128 )
  {
    v134 = *((_QWORD *)v128 + 5);
    if ( v134 )
    {
      *((_DWORD *)v128 + 18) += *(_DWORD *)(v134 + 24);
      *((_QWORD *)v128 + 5) = 0i64;
      v132 = serialization_list.mList.mNode.mPrev;
    }
  }
  v135 = flush_context->mRenderQueues[35].mNode.mNext;
  if ( v135 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v133 )
  {
    v136 = v133->mNode.mPrev;
    v132->mNext = v135;
    v135->mPrev = v132;
    v136->mNext = &serialization_list.mList.mNode;
    v132 = v136;
    serialization_list.mList.mNode.mPrev = v136;
    v133->mNode.mPrev = &v133->mNode;
    flush_context->mRenderQueues[35].mNode.mNext = &flush_context->mRenderQueues[35].mNode;
  }
  v137 = &flush_context->mRenderQueues[36];
  v138 = (FlushContext *)flush_context->mRenderQueues[36].mNode.mNext;
  if ( v138 != (FlushContext *)&flush_context->mRenderQueues[36] )
  {
    v139 = v137->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v138;
    v138->mRenderQueues[0].mNode.mPrev = v132;
    v139->mNext = &serialization_list.mList.mNode;
    v132 = v139;
    serialization_list.mList.mNode.mPrev = v139;
    v137->mNode.mPrev = &v137->mNode;
    flush_context->mRenderQueues[36].mNode.mNext = &flush_context->mRenderQueues[36].mNode;
  }
  v140 = &flush_context->mRenderQueues[38];
  v141 = (FlushContext *)flush_context->mRenderQueues[38].mNode.mNext;
  if ( v141 != (FlushContext *)&flush_context->mRenderQueues[38] )
  {
    v142 = v140->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v141;
    v141->mRenderQueues[0].mNode.mPrev = v132;
    v142->mNext = &serialization_list.mList.mNode;
    v132 = v142;
    serialization_list.mList.mNode.mPrev = v142;
    v140->mNode.mPrev = &v140->mNode;
    flush_context->mRenderQueues[38].mNode.mNext = &flush_context->mRenderQueues[38].mNode;
  }
  v143 = &flush_context->mRenderQueues[37];
  v144 = (FlushContext *)flush_context->mRenderQueues[37].mNode.mNext;
  if ( v144 != (FlushContext *)&flush_context->mRenderQueues[37] )
  {
    v145 = v143->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v144;
    v144->mRenderQueues[0].mNode.mPrev = v132;
    v145->mNext = &serialization_list.mList.mNode;
    v132 = v145;
    serialization_list.mList.mNode.mPrev = v145;
    v143->mNode.mPrev = &v143->mNode;
    flush_context->mRenderQueues[37].mNode.mNext = &flush_context->mRenderQueues[37].mNode;
  }
  v146 = &flush_context->mRenderQueues[39];
  v147 = (FlushContext *)flush_context->mRenderQueues[39].mNode.mNext;
  if ( v147 != (FlushContext *)&flush_context->mRenderQueues[39] )
  {
    v148 = v146->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v147;
    v147->mRenderQueues[0].mNode.mPrev = v132;
    v148->mNext = &serialization_list.mList.mNode;
    v132 = v148;
    serialization_list.mList.mNode.mPrev = v148;
    v146->mNode.mPrev = &v146->mNode;
    flush_context->mRenderQueues[39].mNode.mNext = &flush_context->mRenderQueues[39].mNode;
  }
  v149 = &flush_context->mRenderQueues[43];
  v150 = (FlushContext *)flush_context->mRenderQueues[43].mNode.mNext;
  if ( v150 != (FlushContext *)&flush_context->mRenderQueues[43] )
  {
    v151 = v149->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v150;
    v150->mRenderQueues[0].mNode.mPrev = v132;
    v151->mNext = &serialization_list.mList.mNode;
    v132 = v151;
    serialization_list.mList.mNode.mPrev = v151;
    v149->mNode.mPrev = &v149->mNode;
    flush_context->mRenderQueues[43].mNode.mNext = &flush_context->mRenderQueues[43].mNode;
  }
  v152 = &flush_context->mRenderQueues[40];
  v153 = (FlushContext *)flush_context->mRenderQueues[40].mNode.mNext;
  if ( v153 != (FlushContext *)&flush_context->mRenderQueues[40] )
  {
    v154 = v152->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v153;
    v153->mRenderQueues[0].mNode.mPrev = v132;
    v154->mNext = &serialization_list.mList.mNode;
    v132 = v154;
    serialization_list.mList.mNode.mPrev = v154;
    v152->mNode.mPrev = &v152->mNode;
    flush_context->mRenderQueues[40].mNode.mNext = &flush_context->mRenderQueues[40].mNode;
  }
  v155 = &flush_context->mRenderQueues[41];
  v156 = (FlushContext *)flush_context->mRenderQueues[41].mNode.mNext;
  if ( v156 != (FlushContext *)&flush_context->mRenderQueues[41] )
  {
    v157 = v155->mNode.mPrev;
    v132->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v156;
    v156->mRenderQueues[0].mNode.mPrev = v132;
    v157->mNext = &serialization_list.mList.mNode;
    v132 = v157;
    serialization_list.mList.mNode.mPrev = v157;
    v155->mNode.mPrev = &v155->mNode;
    flush_context->mRenderQueues[41].mNode.mNext = &flush_context->mRenderQueues[41].mNode;
  }
  v158 = &flush_context->mRenderQueues[42];
  v159 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v158->mNode.mNext;
  if ( v159 != v158 )
  {
    v160 = v158->mNode.mPrev;
    v132->mNext = &v159->mNode;
    v159->mNode.mPrev = v132;
    v160->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v160;
    v158->mNode.mPrev = &v158->mNode;
    v158->mNode.mNext = &v158->mNode;
  }
  SerializationList::AddCommand(&serialization_list, 23, &UFG::RenderWorld::msGpuTimer_PostFX);
  FlushJobQueue::AddFlushJob(v19, &serialization_list, 5u, 0x7FFFu, 0);
  if ( render_context->mRenderFeatures.mWorld && gUpdateFog && fTime > 0.0 )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    updated = UFG::TimeOfDayManager::UpdateFog(
                Instance,
                render_context->mEnvState,
                0,
                render_context->mRenderFeatures.mAlternateGradientBackground);
    FlushJobQueue::AddTaskGroup(v19, (UFG::qTaskGroup *)updated);
  }
  p_mList = &serialization_list.mNext;
  UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes((UFG::qList<SerializationList,SerializationList,1,0> *)&serialization_list.mNext);
  v163 = serialization_list.mNext;
  v164 = serialization_list.mList.mNode.mPrev;
  serialization_list.mNext->mNext = (UFG::qNode<SerializationList,SerializationList> *)serialization_list.mList.mNode.mPrev;
  v164->mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v163;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list.mNext;
  serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&serialization_list.mNext;
  p_mList = &serialization_list.mList;
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&serialization_list.mList);
  v165 = serialization_list.mList.mNode.mPrev;
  serialization_list.mList.mNode.mPrev->mNext = v168;
  v168->mPrev = v165;
  v166 = serialization_list.mPrev;
  v167 = serialization_list.mNext;
  serialization_list.mPrev->mNext = serialization_list.mNext;
  v167->mPrev = v166;
}

// File Line: 2845
// RVA: 0x4FA40
MainViewTargetParams *__fastcall GetMainViewTargets(UFG::RenderContext *render_context)
{
  char *v2; // rax
  _QWORD *v3; // rdi
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 8u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = 0i64;
    *((_QWORD *)v2 + 1) = 0i64;
    *((_QWORD *)v2 + 2) = 0i64;
    *((_QWORD *)v2 + 3) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  if ( v4 )
  {
    *(_QWORD *)v4 = render_context->mGBufferTarget;
    *((_QWORD *)v4 + 1) = 0i64;
    *((_DWORD *)v4 + 4) = 5;
    *((_QWORD *)v4 + 3) = "GBuffer";
  }
  *v3 = v4;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  v3[3] = v5;
  Illusion::SetFullscreenViewportScissor(render_context->mGBufferTarget, (Illusion::ViewportScissorState *)v5, 0);
  if ( render_context->mGBufferDepthTarget )
  {
    v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    if ( v6 )
    {
      *(_QWORD *)v6 = render_context->mGBufferDepthTarget;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_DWORD *)v6 + 4) = 5;
      *((_QWORD *)v6 + 3) = "GBufferDepth";
    }
    v3[1] = v6;
  }
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  if ( v7 )
  {
    *(_QWORD *)v7 = render_context->mDynamicRangeTarget;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_DWORD *)v7 + 4) = 0;
    *((_QWORD *)v7 + 3) = "GBufferAlpha";
  }
  v3[2] = v7;
  return (MainViewTargetParams *)v3;
}

// File Line: 2897
// RVA: 0x5BC60
SceneryTaskRenderQueueResults *__fastcall SubmitRenderSceneryTasks(
        UFG::qTaskGroup *task_group_dep,
        UFG::RenderContext *render_context,
        MainViewTargetParams *main_view_target_params,
        int cull_index)
{
  float *mShadowFilterWidth; // rsi
  float *mBiases; // r14
  float *mCutplanes; // r15
  unsigned __int16 Param; // ax
  float z; // xmm0_4
  float w; // xmm1_4
  float v12; // xmm8_4
  char *v13; // rax
  char *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r15
  char *v17; // rax
  UFG::qTaskGroup *v18; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mTasks; // r14
  char **v22; // r12
  __int64 v23; // r13
  int v24; // xmm10_4
  char *v25; // rbx
  Render::EnvCubeMap *mEnvCubeMap; // rax
  UFG::qResourceData *mData; // rcx
  UFG::TimeOfDayManager *Instance; // rax
  Illusion::Texture *v29; // rcx
  Illusion::Target *mSphericalEnvMapTarget; // rax
  Illusion::Texture *v31; // rcx
  Illusion::Target *v32; // rax
  UFG::qResourceData *v33; // rcx
  _QWORD *v34; // rcx
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v37; // rax
  UFG::qResourceData *v38; // rax
  UFG::qVector4 *v39; // rax
  char *v40; // rax
  float y; // xmm1_4
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  UFG::qVector4 v45; // xmm2
  UFG::qVector4 v46; // xmm1
  UFG::qVector4 v47; // xmm0
  int v48; // r9d
  _QWORD *v49; // rdx
  _DWORD *v50; // r8
  __int64 v51; // rcx
  char *v52; // rax
  char *v53; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v59; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v60; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  __int64 v63; // [rsp+20h] [rbp-A8h]
  Render::cbShadowTransformState v64; // [rsp+30h] [rbp-98h] BYREF
  UFG::qMatrix44 d; // [rsp+88h] [rbp-40h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+C8h] [rbp+0h] BYREF
  Illusion::StateValues state_values; // [rsp+2C8h] [rbp+200h] BYREF
  char *v68; // [rsp+770h] [rbp+6A8h]
  _QWORD *v69; // [rsp+778h] [rbp+6B0h]
  int v70; // [rsp+780h] [rbp+6B8h]
  int v71; // [rsp+788h] [rbp+6C0h]

  v64.mBlurWidths = (const float *)-2i64;
  if ( !render_context->mRenderFeatures.mWorld || !render_context->mRenderFeatures.mScenery )
    return 0i64;
  UFG::qMemSet(state_values.mParamValues, 0, 0x400u);
  state_values.mSetValueMask.mFlags[1] = 0i64;
  state_values.mSetValueMask.mFlags[0] = 0i64;
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  mBiases = UFG::RenderWorld::msStageShadow->mBiases;
  mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
  v64.mPrev = &v64;
  v64.mNext = &v64;
  v64.mCallback = 0i64;
  v64.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v64.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = Param;
    v64.mStateParamIndex = Param;
  }
  v64.mViewWorld = &d;
  v64.mWorldView = (UFG::qMatrix44 *)&views;
  v64.mProjection = views.mProjection;
  v64.mCutplanes = mCutplanes;
  v64.mBiases = mBiases;
  v64.mBlurWidths = mShadowFilterWidth;
  *(_QWORD *)&v64.mStateParamIndex = 0i64;
  Render::cbShadowTransformState::SetStateBlock(&v64, &state_values);
  v64.mProjection = (UFG::qMatrix44 *)state_values.mParamValues[64];
  z = render_context->mMainViewSettings.mProjection.v2.z;
  w = render_context->mMainViewSettings.mProjection.v2.w;
  if ( z == 0.0 || z == w )
    v12 = *(float *)&v68;
  else
    v12 = (float)(render_context->mMainViewSettings.mProjection.v3.z - render_context->mMainViewSettings.mProjection.v3.w)
        / (float)(z - w);
  v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v64.mBiases = (const float *)v13;
  *(_QWORD *)v13 = 0i64;
  *((_DWORD *)v13 + 2) = 0;
  *((_DWORD *)v13 + 3) = 1065353216;
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x740u, 0x20u);
  v68 = v14;
  if ( v14 )
  {
    SceneryTaskRenderQueueResults::SceneryTaskRenderQueueResults((SceneryTaskRenderQueueResults *)v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v18 = (UFG::qTaskGroup *)v17;
  v68 = v17;
  if ( v17 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v17, "RenderScenery");
  mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
  mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  mPrev->mNext = v18;
  v18->mPrev = mPrev;
  v18->mNext = &mSingleFrameTaskGroups->mNode;
  mSingleFrameTaskGroups->mNode.mPrev = v18;
  if ( task_group_dep )
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v18, task_group_dep);
  p_mTasks = &v18->mTasks;
  v22 = (char **)(v16 + 40);
  v68 = (char *)(v16 + 1200);
  v23 = v16 + 80;
  v63 = 5i64;
  v24 = v71;
  do
  {
    v25 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x330u, 0x10u);
    *v22 = v25;
    *(_DWORD *)v25 = 1;
    *((_QWORD *)v25 + 1) = gSceneryCullLayer;
    *((_QWORD *)v25 + 2) = v16;
    *((_DWORD *)v25 + 6) = gSceneryTaskMaxRQPrimCount;
    *((_QWORD *)v25 + 4) = Render::GetViewStateBlockParams();
    *((_QWORD *)v25 + 5) = v23;
    *((_DWORD *)v25 + 12) = Illusion::gEngine.mFrameCount;
    *((_QWORD *)v25 + 7) = render_context->mEnvState;
    *((_DWORD *)v25 + 39) = Render::TransparencySystem::msTransparencyFrameCounter;
    mEnvCubeMap = render_context->mEnvCubeMap;
    if ( mEnvCubeMap )
      mData = &mEnvCubeMap->mTarget->mTargetTexture[0]->UFG::qResourceData;
    else
      mData = gDefaultBlackTexture.mData;
    *((_QWORD *)v25 + 8) = mData;
    Instance = UFG::TimeOfDayManager::GetInstance();
    *((_QWORD *)v25 + 9) = UFG::TimeOfDayManager::GetFogTexture(Instance);
    if ( render_context->mReflection )
      v29 = render_context->mReflectionMipTarget->mTargetTexture[0];
    else
      v29 = (Illusion::Texture *)gDefaultBlackTexture.mData;
    *((_QWORD *)v25 + 10) = v29;
    *((_QWORD *)v25 + 11) = gArcTanTexture.mData;
    if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherSurfaceWetness == 0.0
      || (mSphericalEnvMapTarget = render_context->mSphericalEnvMapTarget) == 0i64 )
    {
      v31 = 0i64;
    }
    else
    {
      v31 = mSphericalEnvMapTarget->mTargetTexture[0];
    }
    *((_QWORD *)v25 + 12) = v31;
    v32 = render_context->mSphericalEnvMapTarget;
    if ( v32 )
      v33 = &v32->mTargetTexture[0]->UFG::qResourceData;
    else
      v33 = gDefaultBlackTexture.mData;
    *((_QWORD *)v25 + 13) = v33;
    *((_QWORD *)v25 + 14) = UFG::Water::GetRippleMap(0);
    *((_QWORD *)v25 + 97) = render_context->mHalfSizeShadowAliasTexture;
    *((_QWORD *)v25 + 98) = v64.mProjection;
    *((_DWORD *)v25 + 60) = gSceneryTaskMaxRQCmdCount;
    v34 = v69;
    *((_QWORD *)v25 + 15) = *v69;
    *((_QWORD *)v25 + 16) = v34[2];
    *((_DWORD *)v25 + 34) = v70;
    *((_QWORD *)v25 + 18) = v68;
    *((_DWORD *)v25 + 38) = v24;
    *((_QWORD *)v25 + 20) = Illusion::gEngine.FrameMemory;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v37 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v37 = mSimTime_Temp;
    *((float *)v37 + 1) = mSimTimeDelta;
    *((_QWORD *)v25 + 21) = v37;
    *((_QWORD *)v25 + 22) = AlphaStateNoneHandle.mData;
    *((_QWORD *)v25 + 23) = AlphaStateNoneHandle.mData;
    *((_QWORD *)v25 + 24) = RasterStateNormalHandle.mData;
    v38 = 0i64;
    if ( render_context->mRenderFeatures.mForceSceneryDoubleSided )
      v38 = RasterStateDoubleSidedHandle.mData;
    *((_QWORD *)v25 + 25) = v38;
    v39 = 0i64;
    if ( render_context->mRenderFeatures.mForceSceneryDoubleSided )
      v39 = &UFG::qVector4::msZero;
    *((_QWORD *)v25 + 26) = v39;
    *((_DWORD *)v25 + 54) = Render::TransparencySystem::msNumTransparencyStateHandles;
    v40 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x620u, 0x20u);
    v64.mWorldView = (UFG::qMatrix44 *)v40;
    v64.mCutplanes = (const float *)v40;
    if ( v40 )
      RenderQueueResults::RenderQueueResults((RenderQueueResults *)v40);
    *((_QWORD *)v25 + 28) = v40;
    *((_QWORD *)v25 + 29) = UFG::Water::GetWaterSettings();
    y = Render::View::mScreenOffset.y;
    *((_DWORD *)v25 + 61) = LODWORD(Render::View::mScreenOffset.x);
    *((float *)v25 + 62) = y;
    v42 = render_context->mMainViewSettings.mWorldView.v1;
    v43 = render_context->mMainViewSettings.mWorldView.v2;
    v44 = render_context->mMainViewSettings.mWorldView.v3;
    *((_OWORD *)v25 + 16) = render_context->mMainViewSettings.mWorldView.v0;
    *((UFG::qVector4 *)v25 + 17) = v42;
    *((UFG::qVector4 *)v25 + 18) = v43;
    *((UFG::qVector4 *)v25 + 19) = v44;
    v45 = render_context->mMainViewSettings.mProjection.v1;
    v46 = render_context->mMainViewSettings.mProjection.v2;
    v47 = render_context->mMainViewSettings.mProjection.v3;
    *((_OWORD *)v25 + 20) = render_context->mMainViewSettings.mProjection.v0;
    *((UFG::qVector4 *)v25 + 21) = v45;
    *((UFG::qVector4 *)v25 + 22) = v46;
    *((UFG::qVector4 *)v25 + 23) = v47;
    *((_QWORD *)v25 + 99) = v64.mBiases;
    *((float *)v25 + 200) = v12;
    *((_DWORD *)v25 + 201) = UFG::RenderWorld::msEnableWater;
    *((float *)v25 + 202) = gSceneryThresholdLodB;
    v48 = 0;
    if ( *((int *)v25 + 54) > 0 )
    {
      v49 = v25 + 648;
      v50 = v25 + 452;
      v51 = 0i64;
      do
      {
        *(v50 - 16) = *(unsigned int *)((char *)&Render::TransparencySystem::msAlphaStateInHandle[0].mNameUID + v51);
        *(v49 - 16) = *(UFG::qResourceData **)((char *)&Render::TransparencySystem::msAlphaStateInHandle[0].mData + v51);
        *v50 = *(unsigned int *)((char *)&Render::TransparencySystem::msAlphaStateOutHandle[0].mNameUID + v51);
        *v49 = *(UFG::qResourceData **)((char *)&Render::TransparencySystem::msAlphaStateOutHandle[0].mData + v51);
        ++v48;
        ++v50;
        ++v49;
        v51 += 32i64;
      }
      while ( v48 < *((_DWORD *)v25 + 54) );
    }
    v52 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v53 = v52;
    v64.mCutplanes = (const float *)v52;
    v64.mWorldView = (UFG::qMatrix44 *)v52;
    if ( v52 )
    {
      *(_QWORD *)v52 = v52;
      *((_QWORD *)v52 + 1) = v52;
      *((_QWORD *)v52 + 2) = v52 + 16;
      *((_QWORD *)v52 + 3) = v52 + 16;
      mSpuElf = gTaskFunctionDeclData_RenderSceneryTask.mSpuElf;
      mTaskFunctionSPU = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionSPU;
      mTaskFunctionPPU = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionPPU;
      mTaskFunctionOffload = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionOffload;
      if ( !gTaskFunctionDeclData_RenderSceneryTask.mCurrentSPUEnabled )
      {
        mSpuElf = 0i64;
        mTaskFunctionSPU = 0i64;
        mTaskFunctionOffload = 0i64;
      }
      *((_QWORD *)v53 + 6) = v18;
      *((_DWORD *)v53 + 14) = 2;
      *((_QWORD *)v53 + 4) = 0i64;
      *((_QWORD *)v53 + 5) = 0i64;
      *((_QWORD *)v53 + 8) = &gTaskFunctionDeclData_RenderSceneryTask;
      if ( mSpuElf )
        mAddress = mSpuElf->mAddress;
      else
        mAddress = 0i64;
      *((_QWORD *)v53 + 9) = mAddress;
      *((_QWORD *)v53 + 10) = mTaskFunctionSPU;
      *((_QWORD *)v53 + 11) = mTaskFunctionPPU;
      *((_QWORD *)v53 + 12) = v25;
      *((_QWORD *)v53 + 13) = 0i64;
      *((_QWORD *)v53 + 14) = 0i64;
      *((_QWORD *)v53 + 15) = 0i64;
      if ( mTaskFunctionOffload )
      {
        *((_DWORD *)v53 + 14) = 130;
        *((_DWORD *)v53 + 12) = 0;
      }
    }
    v59 = p_mTasks->mNode.mPrev;
    v59->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v53;
    *(_QWORD *)v53 = v59;
    *((_QWORD *)v53 + 1) = p_mTasks;
    p_mTasks->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v53;
    ++v18->mNumTasks;
    v23 += 224i64;
    v68 += 128;
    ++v22;
    --v63;
  }
  while ( v63 );
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v18);
  *(_QWORD *)(v16 + 1840) = v18;
  v60 = v64.mPrev;
  mNext = v64.mNext;
  v64.mPrev->mNext = v64.mNext;
  mNext->mPrev = v60;
  v64.mPrev = &v64;
  v64.mNext = &v64;
  return (SceneryTaskRenderQueueResults *)v16;
}

// File Line: 3033
// RVA: 0x58680
SimRenderQueueResults *__fastcall RenderSimMain(
        UFG::RenderContext *render_context,
        MainViewTargetParams *main_view_target_params,
        Render::RenderPassCollector *render_pass_collector)
{
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  bool mForceSceneryDoubleSided; // cl
  UFG::qResourceData *mData; // rax
  UFG::qVector4 *v12; // rax
  Illusion::StateValues *StateValues; // rdi
  Illusion::BeginTargetCommandParams *gbuffer_target_params; // rcx
  Illusion::ViewportScissorState *gbuffer_viewport; // rcx
  unsigned __int16 Param; // ax
  char *v17; // rax
  Illusion::ShaderSelector *v18; // rbx
  Render::EnvCubeMap *mEnvCubeMap; // rax
  UFG::qResourceData *v20; // rcx
  UFG::TimeOfDayManager *Instance; // rax
  Illusion::Texture *FogTexture; // rax
  Illusion::Texture *v23; // rcx
  UFG::qResourceData *v24; // rax
  CB_EnvironmentSettings *mEnvState; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v28; // rax
  Illusion::Texture *mHalfSizeShadowAliasTexture; // rax
  Illusion::Texture *RippleMap; // rax
  Illusion::Target *mSphericalEnvMapTarget; // rax
  UFG::qResourceData *v32; // rax
  CB_WaterOffset *WaterSettings; // rax
  Illusion::Target *v34; // rax
  UFG::qResourceData *v35; // rax
  char *v36; // rax
  float *mShadowFilterWidth; // rdi
  float *mBiases; // r15
  float *mCutplanes; // r12
  unsigned __int16 v40; // ax
  Illusion::StateArgs *StateArgs; // rax
  Illusion::StateValues *v42; // rax
  Render::ViewSettings *mSettings; // rdi
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 v45; // ax
  Illusion::StateArgs *v46; // rax
  Render::RenderCallbacks *RenderCallbacks; // rax
  Illusion::StateArgs *v48; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  Illusion::StateArgs *v51; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v54; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v55; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v56; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v57; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v58; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v59; // rax
  Render::cbExternalViewTransformState v60; // [rsp+30h] [rbp-D0h] BYREF
  Render::cbShadowTransformState arg; // [rsp+70h] [rbp-90h] BYREF
  Render::cbViewTransformState v62; // [rsp+D0h] [rbp-30h] BYREF
  Render::FXManagerAuxBuffers auxBuffers; // [rsp+120h] [rbp+20h] BYREF
  __int64 v64[9]; // [rsp+148h] [rbp+48h] BYREF
  Render::View view; // [rsp+190h] [rbp+90h] BYREF
  RenderQueueLayer v66; // [rsp+320h] [rbp+220h] BYREF
  UFG::qMatrix44 result; // [rsp+400h] [rbp+300h] BYREF
  UFG::qMatrix44 d; // [rsp+440h] [rbp+340h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+480h] [rbp+380h] BYREF
  LayerSubmitContext ptr; // [rsp+680h] [rbp+580h] BYREF
  GBufferSubmitContext v71; // [rsp+1300h] [rbp+1200h] BYREF

  v64[7] = -2i64;
  if ( !render_context->mRenderFeatures.mWorld )
    return 0i64;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1F0u, 0x10u);
  if ( v7 )
  {
    SimRenderQueueResults::SimRenderQueueResults((SimRenderQueueResults *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  GBufferSubmitContext::GBufferSubmitContext(&v71);
  v64[4] = (__int64)AlphaStateNoneHandle.mData;
  v64[0] = (__int64)AlphaStateDeferredPunchThroughHandle.mData;
  v64[1] = (__int64)RasterStateNormalHandle.mData;
  mForceSceneryDoubleSided = render_context->mRenderFeatures.mForceSceneryDoubleSided;
  mData = 0i64;
  if ( mForceSceneryDoubleSided )
    mData = RasterStateDoubleSidedHandle.mData;
  v64[2] = (__int64)mData;
  v12 = 0i64;
  if ( mForceSceneryDoubleSided )
    v12 = &UFG::qVector4::msZero;
  v64[3] = (__int64)v12;
  v64[6] = (__int64)main_view_target_params->composite_target_params;
  v64[5] = (__int64)main_view_target_params->gbuffer_target_params;
  v71.mPerPhaseParams = (GBufferSubmitContext::PerPhaseParams *)v64;
  Render::View::View(&view, &render_context->mMainViewSettings, &v71);
  StateValues = Render::View::GetStateValues(&view);
  UFG::qMemSet(StateValues->mParamValues, 0, 0x400u);
  StateValues->mSetValueMask.mFlags[1] = 0i64;
  StateValues->mSetValueMask.mFlags[0] = 0i64;
  Render::View::Metric_BeginTarget(&view);
  gbuffer_target_params = main_view_target_params->gbuffer_target_params;
  StateValues->mSetValueMask.mFlags[0] |= 0x800ui64;
  StateValues->mParamValues[11] = gbuffer_target_params;
  gbuffer_viewport = main_view_target_params->gbuffer_viewport;
  StateValues->mSetValueMask.mFlags[0] |= 0x1000ui64;
  StateValues->mParamValues[12] = gbuffer_viewport;
  UFG::qMatrix44::operator*(
    &render_context->mMainViewSettings.mWorldView,
    &result,
    &render_context->mMainViewSettings.mProjection);
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  v62.mPrev = &v62;
  v62.mNext = &v62;
  v62.mCallback = 0i64;
  v62.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v62.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = Param;
    v62.mStateParamIndex = Param;
  }
  v62.mWorldViewProjection = &result;
  v62.mViewWorld = &d;
  v62.mProjection = &render_context->mMainViewSettings.mProjection;
  v62.mScreenOffset = &Render::View::mScreenOffset;
  v62.mCached_Remote.m_Stream = 0i64;
  Render::cbViewTransformState::SetStateBlock(&v62, StateValues);
  v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
  v18 = (Illusion::ShaderSelector *)v17;
  if ( v17 )
  {
    *(_QWORD *)v17 = 0i64;
    *((_QWORD *)v17 + 1) = 0i64;
    *((_DWORD *)v17 + 8) = 0;
    *((_QWORD *)v17 + 3) = -1i64;
    *((_QWORD *)v17 + 2) = -1i64;
  }
  else
  {
    v18 = 0i64;
  }
  v71.mShaderSelector = v18;
  mEnvCubeMap = render_context->mEnvCubeMap;
  if ( mEnvCubeMap )
    v20 = &mEnvCubeMap->mTarget->mTargetTexture[0]->UFG::qResourceData;
  else
    v20 = gDefaultBlackTexture.mData;
  StateValues->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
  StateValues->mParamValues[40] = v20;
  Instance = UFG::TimeOfDayManager::GetInstance();
  FogTexture = UFG::TimeOfDayManager::GetFogTexture(Instance);
  StateValues->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  StateValues->mParamValues[41] = FogTexture;
  if ( render_context->mReflection )
    v23 = render_context->mReflectionMipTarget->mTargetTexture[0];
  else
    v23 = (Illusion::Texture *)gDefaultBlackTexture.mData;
  StateValues->mSetValueMask.mFlags[0] |= 0x20000000000000ui64;
  StateValues->mParamValues[53] = v23;
  v24 = gArcTanTexture.mData;
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
  StateValues->mParamValues[43] = v24;
  mEnvState = render_context->mEnvState;
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v28 = mSimTime_Temp;
  *((float *)v28 + 1) = mSimTimeDelta;
  StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
  StateValues->mParamValues[13] = v28;
  mHalfSizeShadowAliasTexture = render_context->mHalfSizeShadowAliasTexture;
  StateValues->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  StateValues->mParamValues[61] = mHalfSizeShadowAliasTexture;
  RippleMap = UFG::Water::GetRippleMap(1);
  StateValues->mSetValueMask.mFlags[0] |= 0x800000000000000ui64;
  StateValues->mParamValues[59] = RippleMap;
  mSphericalEnvMapTarget = render_context->mSphericalEnvMapTarget;
  if ( mSphericalEnvMapTarget )
    v32 = &mSphericalEnvMapTarget->mTargetTexture[0]->UFG::qResourceData;
  else
    v32 = gDefaultBlackTexture.mData;
  StateValues->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
  StateValues->mParamValues[58] = v32;
  WaterSettings = UFG::Water::GetWaterSettings();
  StateValues->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
  StateValues->mParamValues[45] = WaterSettings;
  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherSurfaceWetness != 0.0 )
  {
    v34 = render_context->mSphericalEnvMapTarget;
    if ( v34 )
      v35 = &v34->mTargetTexture[0]->UFG::qResourceData;
    else
      v35 = gDefaultBlackTexture.mData;
    StateValues->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
    StateValues->mParamValues[57] = v35;
  }
  v36 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(_QWORD *)v36 = 0i64;
  *((_DWORD *)v36 + 2) = 0;
  *((_DWORD *)v36 + 3) = 1065353216;
  StateValues->mSetValueMask.mFlags[0] |= 0x100000000ui64;
  StateValues->mParamValues[32] = v36;
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  mBiases = UFG::RenderWorld::msStageShadow->mBiases;
  mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v40 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v40;
    arg.mStateParamIndex = v40;
  }
  arg.mViewWorld = &view.mViewWorld;
  arg.mWorldView = (UFG::qMatrix44 *)&views;
  arg.mProjection = views.mProjection;
  arg.mCutplanes = mCutplanes;
  arg.mBiases = mBiases;
  arg.mBlurWidths = mShadowFilterWidth;
  arg.mCached_Remote.m_Stream = 0i64;
  StateArgs = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &arg);
  v42 = Render::View::GetStateValues(&view);
  Render::cbShadowTransformState::SetStateBlock(&arg, v42);
  mSettings = view.mSettings;
  p_mProjection = &view.mSettings->mProjection;
  v60.mPrev = &v60;
  v60.mNext = &v60;
  v60.mCallback = 0i64;
  v60.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v60.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    v45 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v45;
    v60.mStateParamIndex = v45;
  }
  v60.mWorldView = &mSettings->mWorldView;
  v60.mProjection = p_mProjection;
  v60.mCached_Remote.m_Stream = 0i64;
  v46 = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v46, &v60);
  Render::View::SetSimpleMaterialShader(0x192E0D6u);
  if ( render_context->mRenderFeatures.mScenery )
  {
    v71.mRenderQueueProvider = (RenderQueueLayer *)v9;
    if ( Render::GetRenderCallbacks()->mRenderSim )
    {
      RenderCallbacks = Render::GetRenderCallbacks();
      RenderCallbacks->mRenderSim(render_context, &view);
    }
    Render::RenderPassSystem::DrawRenderPass(render_pass_collector, &view, Solid);
  }
  *(_OWORD *)&v71.mCullMetrics = 0i64;
  if ( gRenderFX )
  {
    v71.mRenderQueueProvider = (RenderQueueLayer *)(v9 + 224);
    memset(&auxBuffers, 0, sizeof(auxBuffers));
    Render::FXManager::Render(
      &Render::gFXManager,
      &view,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_DEFERRED,
      &auxBuffers);
    Render::DecalManager::Render(
      &Render::gDecalManager,
      &view,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_DEFERRED);
  }
  v48 = Render::View::GetStateArgs(&view);
  mPrev = v60.mPrev;
  mNext = v60.mNext;
  v60.mPrev->mNext = v60.mNext;
  mNext->mPrev = mPrev;
  v60.mPrev = &v60;
  v60.mNext = &v60;
  v60.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v48->mStateArgs[v60.mStateParamIndex].mNode.mNext == &v48->mStateArgs[v60.mStateParamIndex] )
    v48->mStateArgsCreateMask.mFlags[(unsigned int)v60.mStateParamIndex >> 6] &= ~(1i64 << (v60.mStateParamIndex & 0x3F));
  v51 = Render::View::GetStateArgs(&view);
  v52 = arg.mPrev;
  v53 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v53->mPrev = v52;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v51->mStateArgs[arg.mStateParamIndex].mNode.mNext == &v51->mStateArgs[arg.mStateParamIndex] )
    v51->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::SetSimpleMaterialShader(0x3141335Cu);
  if ( render_context->mRenderFeatures.mScenery )
  {
    RenderQueueLayer::RenderQueueLayer(&v66);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    ptr.mRenderQueueProvider = &v66;
    ptr.mQueueMode = QM_Single;
    ptr.mShaderSelector = v18;
    v18->mAddState.mFlags[0] |= 0x800000000ui64;
    view.mSubmitContext = &ptr;
    v66.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 448);
    UFG::RenderStageTerrain::Render(UFG::RenderWorld::msStageTerrain, render_context, &view);
    RenderQueueLayer::SerializeRenderQueues(&v66);
    v66.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 464);
    UFG::RenderStageImposters::Render(UFG::RenderWorld::msStageImposters, render_context, &view);
    RenderQueueLayer::SerializeRenderQueues(&v66);
    v66.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 480);
    Render::RenderPassSystem::DrawRenderPass(render_pass_collector, &view, Decal);
    RenderQueueLayer::SerializeRenderQueues(&v66);
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v66);
  }
  Render::View::Metric_EndTarget(&view);
  Render::ViewMetrics::Accumulate(&render_context->mRenderStats, &view.mViewMetrics);
  v54 = v60.mPrev;
  v55 = v60.mNext;
  v60.mPrev->mNext = v60.mNext;
  v55->mPrev = v54;
  v60.mPrev = &v60;
  v60.mNext = &v60;
  v56 = arg.mPrev;
  v57 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v57->mPrev = v56;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  v58 = v62.mPrev;
  v59 = v62.mNext;
  v62.mPrev->mNext = v62.mNext;
  v59->mPrev = v58;
  v62.mPrev = &v62;
  v62.mNext = &v62;
  `eh vector destructor iterator(
    v71.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  return (SimRenderQueueResults *)v9;
}

// File Line: 3214
// RVA: 0x56440
void __fastcall RenderHalfSizeDepthBuffer(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  _WORD *v4; // rbx
  Illusion::StateArgs *StateArgs; // r14
  Render::ViewSettings *mSettings; // rsi
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  unsigned int mUID; // r8d
  Illusion::Material *mDownsampleDepthMaterial; // rsi
  __int64 mOffset; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v18; // [rsp+88h] [rbp-78h]
  RenderQueueLayer v19; // [rsp+90h] [rbp-70h] BYREF
  Render::View v20; // [rsp+170h] [rbp+70h] BYREF
  LayerSubmitContext ptr; // [rsp+300h] [rbp+200h] BYREF
  Render::Poly poly; // [rsp+FB0h] [rbp+EB0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FC0h] [rbp+EC0h]

  v18 = -2i64;
  if ( render_context->mRenderFeatures.mWorld )
  {
    LayerSubmitContext::LayerSubmitContext(&ptr);
    RenderQueueLayer::RenderQueueLayer(&v19);
    v19.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v19;
    v4 = 0i64;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&v20, &render_context->mMainViewSettings, &ptr);
    StateArgs = Render::View::GetStateArgs(&v20);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v20, render_context->mHalfSizeLinearDepthTarget, "HalfSizeDepth", 0, 0, 0i64, 0, 0, 0, 0);
    mSettings = v20.mSettings;
    p_mProjection = &v20.mSettings->mProjection;
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
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    mUID = render_context->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
    mDownsampleDepthMaterial = render_context->mDownsampleDepthMaterial;
    if ( LODWORD(mDownsampleDepthMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mDownsampleDepthMaterial[1].mDebugName[20],
        mDownsampleDepthMaterial[1].mStateBlockMask.mFlags[1],
        mUID);
      mOffset = mDownsampleDepthMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v4 = (_WORD *)((char *)&mDownsampleDepthMaterial->mMaterialUser + mOffset);
      *v4 |= 0x20u;
    }
    Render::View::Draw(&v20, &poly, render_context->mDownsampleDepthMaterial, 0i64);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    {
      v14 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v14 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v20);
    RenderQueueLayer::SerializeRenderQueues(&v19);
    v15 = arg.mPrev;
    v16 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v16->mPrev = v15;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    RenderQueueLayer::~RenderQueueLayer(&v19);
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 3259
// RVA: 0x58380
void __fastcall RenderQuarterSizeDepthBuffer(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  _WORD *v4; // rbx
  Illusion::StateArgs *StateArgs; // r14
  Render::ViewSettings *mSettings; // rsi
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  unsigned int mUID; // r8d
  Illusion::Material *mDownsampleDepthMaterial; // rsi
  __int64 mOffset; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v18; // [rsp+88h] [rbp-78h]
  RenderQueueLayer v19; // [rsp+90h] [rbp-70h] BYREF
  Render::View v20; // [rsp+170h] [rbp+70h] BYREF
  LayerSubmitContext ptr; // [rsp+300h] [rbp+200h] BYREF
  Render::Poly poly; // [rsp+FB0h] [rbp+EB0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FC0h] [rbp+EC0h]

  v18 = -2i64;
  if ( render_context->mQuarterSizeLinearDepthTarget )
  {
    LayerSubmitContext::LayerSubmitContext(&ptr);
    RenderQueueLayer::RenderQueueLayer(&v19);
    v19.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v19;
    v4 = 0i64;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&v20, &render_context->mMainViewSettings, &ptr);
    StateArgs = Render::View::GetStateArgs(&v20);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(
      &v20,
      render_context->mQuarterSizeLinearDepthTarget,
      "QuarterSizeDepth",
      0,
      0,
      0i64,
      0,
      0,
      0,
      0);
    mSettings = v20.mSettings;
    p_mProjection = &v20.mSettings->mProjection;
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
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    mUID = render_context->mHalfSizeLinearDepthTarget->mDepthTextureCopy->mNode.mUID;
    mDownsampleDepthMaterial = render_context->mDownsampleDepthMaterial;
    if ( LODWORD(mDownsampleDepthMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mDownsampleDepthMaterial[1].mDebugName[20],
        mDownsampleDepthMaterial[1].mStateBlockMask.mFlags[1],
        mUID);
      mOffset = mDownsampleDepthMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v4 = (_WORD *)((char *)&mDownsampleDepthMaterial->mMaterialUser + mOffset);
      *v4 |= 0x20u;
    }
    Render::View::Draw(&v20, &poly, render_context->mDownsampleDepthMaterial, 0i64);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    {
      v14 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v14 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v20);
    RenderQueueLayer::SerializeRenderQueues(&v19);
    v15 = arg.mPrev;
    v16 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v16->mPrev = v15;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    RenderQueueLayer::~RenderQueueLayer(&v19);
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 3303
// RVA: 0x53EF0
void __fastcall RenderDeferredLights_1(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        int num_lights)
{
  _WORD *v5; // r14
  bool v6; // al
  Illusion::StateArgs *StateArgs; // rdi
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v15; // rbx
  Illusion::StateValues *v16; // rax
  int mLightWithIrradianceVolumesType; // r8d
  bool v18; // r13
  float v19; // xmm7_4
  Illusion::Material *mSkyAmbientMaterial; // r15
  unsigned int mAmbientSpecWithSunShader_DOUID; // r9d
  unsigned int mAmbientSpecWithSunShaderUID; // r8d
  __int64 mOffset; // rax
  _WORD *v24; // rax
  float *v25; // rdi
  Render::ViewSettings *v26; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  float v28; // xmm2_4
  float v29; // xmm6_4
  Render::ViewSettings *v30; // rbx
  UFG::TimeOfDayManager *v31; // rax
  float v32; // xmm2_4
  float v33; // xmm6_4
  Render::ViewSettings *v34; // rbx
  float *v35; // rax
  float v36; // xmm2_4
  float v37; // xmm6_4
  Illusion::StateValues *v38; // rax
  int v39; // ecx
  Illusion::MaterialHandle *v40; // rax
  unsigned int v41; // r8d
  __int64 v42; // rax
  _WORD *v43; // rax
  Illusion::Material *mSunUsingCollectorMaterial; // rbx
  unsigned int mSunAfterAmbientSpecTestRasterStateUID; // r8d
  __int64 v46; // rax
  _WORD *v47; // rax
  unsigned int v48; // eax
  unsigned int v49; // eax
  __int64 v50; // rax
  __int64 v51; // rcx
  _QWORD *v52; // rax
  __int64 v53; // rcx
  _QWORD *v54; // rax
  bool d3d_disable_depth_copy[16]; // [rsp+48h] [rbp-80h] BYREF
  UFG::qMatrix44 local_world; // [rsp+58h] [rbp-70h] BYREF
  __int64 v57; // [rsp+98h] [rbp-30h]
  __int64 v58; // [rsp+A0h] [rbp-28h]
  Render::View view; // [rsp+A8h] [rbp-20h] BYREF
  RenderQueueLayer v60; // [rsp+238h] [rbp+170h] BYREF
  LayerSubmitContext ptr; // [rsp+318h] [rbp+250h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FF8h] [rbp+F30h]
  Render::Poly poly; // [rsp+1010h] [rbp+F48h] BYREF

  v58 = -2i64;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v60);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v60.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v60;
    v5 = 0i64;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
    v6 = UFG::RenderWorld::msStageHairSkin->mEnableSSS
      && (UFG::RenderWorld::msIsNisPlaying || UFG::RenderWorld::msStageHairSkin->mEnableSSSOutsideNIS);
    render_context->mRenderSkinSS = v6;
    StateArgs = Render::View::GetStateArgs(&view);
    p_mStateArgs = StateArgs;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&view, render_context->mLightBufferTarget, "LightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
    mSettings = view.mSettings;
    p_mProjection = &view.mSettings->mProjection;
    *(_QWORD *)&local_world.v1.x = &local_world.v1;
    *(_QWORD *)&local_world.v1.z = &local_world.v1;
    *(_QWORD *)&local_world.v2.x = 0i64;
    LOWORD(local_world.v2.z) = Render::cbExternalViewTransformState::sStateParamIndex;
    HIWORD(local_world.v2.z) = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = Param;
      LOWORD(local_world.v2.z) = Param;
    }
    *(_QWORD *)&local_world.v3.x = mSettings;
    *(_QWORD *)&local_world.v3.z = p_mProjection;
    v57 = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(
      StateArgs,
      (Render::cbExternalViewTransformState *)&local_world.v1);
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(&view);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v15 = mSimTime_Temp;
    *((float *)v15 + 1) = mSimTimeDelta;
    v16 = Render::View::GetStateValues(&view);
    v16->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v16->mParamValues[13] = v15;
    Render::View::Clear(&view, &UFG::qColour::Zero, 5u, 1.0, 0);
    mLightWithIrradianceVolumesType = render_context->mLightWithIrradianceVolumesType;
    if ( mLightWithIrradianceVolumesType )
      DrawIrradianceVolumes(render_context, &view, mLightWithIrradianceVolumesType);
    UFG::Director::Get();
    v18 = !UFG::RenderWorld::msExposureMetering->mInsideNoSkyVisibleVolume
       && render_context->mRenderSun
       && render_context->mCombineAmbientSpecAndSun;
    v19 = gAmbientWithSpecDistance;
    if ( UFG::RenderWorld::msIsNisPlaying )
      v19 = gAmbientWithSpecDistance * 2.0;
    if ( !UFG::RenderWorld::msExposureMetering->mInsideNoSkyVisibleVolume )
    {
      mSkyAmbientMaterial = render_context->mSkyAmbientMaterial;
      if ( render_context->mRenderSettingsForFrame.mSSAO == SSAO_HIGH
        && render_context->mLightBufferTarget->mTargetTexture[1] )
      {
        if ( v18 )
          mAmbientSpecWithSunShader_DOUID = render_context->mAmbientSpecWithSunShader_DOUID;
        else
          mAmbientSpecWithSunShader_DOUID = render_context->mAmbientSpecShaderUID;
        Illusion::Material::UpdateParam(
          render_context->mSkyAmbientMaterial,
          0,
          0x8B5561A1,
          mAmbientSpecWithSunShader_DOUID);
      }
      else
      {
        if ( v18 )
          mAmbientSpecWithSunShaderUID = render_context->mAmbientSpecWithSunShaderUID;
        else
          mAmbientSpecWithSunShaderUID = render_context->mAmbientSpecShaderUID;
        if ( LODWORD(mSkyAmbientMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != mAmbientSpecWithSunShaderUID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mSkyAmbientMaterial[1].mNode.mChild[1],
            mSkyAmbientMaterial[1].mTypeUID,
            mAmbientSpecWithSunShaderUID);
          mOffset = mSkyAmbientMaterial->mMaterialUser.mOffset;
          if ( mOffset )
            v24 = (_WORD *)((char *)&mSkyAmbientMaterial->mMaterialUser + mOffset);
          else
            v24 = 0i64;
          *v24 |= 0x20u;
        }
      }
      v25 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      v26 = view.mSettings;
      Instance = UFG::TimeOfDayManager::GetInstance();
      v28 = (float)((float)(Instance->mAmbientSkyDirection[0].x * v26->mWorldView.v0.y)
                  + (float)(Instance->mAmbientSkyDirection[0].y * v26->mWorldView.v1.y))
          + (float)(Instance->mAmbientSkyDirection[0].z * v26->mWorldView.v2.y);
      v29 = (float)((float)(Instance->mAmbientSkyDirection[0].x * v26->mWorldView.v0.z)
                  + (float)(Instance->mAmbientSkyDirection[0].y * v26->mWorldView.v1.z))
          + (float)(Instance->mAmbientSkyDirection[0].z * v26->mWorldView.v2.z);
      *v25 = (float)((float)(Instance->mAmbientSkyDirection[0].y * v26->mWorldView.v1.x)
                   + (float)(Instance->mAmbientSkyDirection[0].x * v26->mWorldView.v0.x))
           + (float)(Instance->mAmbientSkyDirection[0].z * v26->mWorldView.v2.x);
      v25[1] = v28;
      v25[2] = v29;
      v30 = view.mSettings;
      v31 = UFG::TimeOfDayManager::GetInstance();
      v32 = (float)((float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.y)
                  + (float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.y))
          + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.y);
      v33 = (float)((float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.z)
                  + (float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.z))
          + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.z);
      v25[4] = (float)((float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.x)
                     + (float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.x))
             + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.x);
      v25[5] = v32;
      v25[6] = v33;
      v34 = view.mSettings;
      v35 = (float *)UFG::TimeOfDayManager::GetInstance();
      v36 = (float)((float)(v35[45] * v34->mWorldView.v0.y) + (float)(v35[46] * v34->mWorldView.v1.y))
          + (float)(v35[47] * v34->mWorldView.v2.y);
      v37 = (float)((float)(v35[45] * v34->mWorldView.v0.z) + (float)(v35[46] * v34->mWorldView.v1.z))
          + (float)(v35[47] * v34->mWorldView.v2.z);
      v25[8] = (float)((float)(v35[46] * v34->mWorldView.v1.x) + (float)(v35[45] * v34->mWorldView.v0.x))
             + (float)(v35[47] * v34->mWorldView.v2.x);
      v25[9] = v36;
      v25[10] = v37;
      v25[3] = v19;
      v25[7] = (float)((float)((float)(render_context->mEnvState->AmbientColorHorizon[1] * 0.71539998)
                             + (float)(render_context->mEnvState->AmbientColorHorizon[0] * 0.21250001))
                     + (float)(render_context->mEnvState->AmbientColorHorizon[2] * 0.072099999))
             * 1.3;
      v38 = Render::View::GetStateValues(&view);
      v38->mSetValueMask.mFlags[0] |= 0x8000ui64;
      v38->mParamValues[15] = v25;
      local_world.v1.x = UFG::qMatrix44::msIdentity.v0.z * v19;
      local_world.v1.y = UFG::qMatrix44::msIdentity.v0.w * v19;
      local_world.v1.z = UFG::qMatrix44::msIdentity.v1.x * v19;
      local_world.v1.w = UFG::qMatrix44::msIdentity.v1.y * v19;
      local_world.v2.x = UFG::qMatrix44::msIdentity.v1.z * v19;
      local_world.v2.y = UFG::qMatrix44::msIdentity.v1.w * v19;
      *(float *)&d3d_disable_depth_copy[8] = UFG::qMatrix44::msIdentity.v2.z * v19;
      *(float *)&d3d_disable_depth_copy[12] = UFG::qMatrix44::msIdentity.v2.w * v19;
      local_world.v0.x = view.mViewWorld.v3.x;
      local_world.v0.y = view.mViewWorld.v3.y;
      local_world.v0.z = view.mViewWorld.v3.z;
      local_world.v0.w = 1.0;
      v39 = gClearStencil;
      if ( gClearStencil )
      {
        *(_QWORD *)&d3d_disable_depth_copy[8] = 0i64;
        *(_QWORD *)&local_world.v0.x = 0i64;
        Render::View::Clear(&view, (UFG::qColour *)&d3d_disable_depth_copy[8], 4u, 1.0, 0);
        v39 = gClearStencil;
      }
      v40 = &gMatStencilNearNoClear;
      if ( v39 )
        v40 = &gMatStencilNear;
      Render::View::Draw(
        &view,
        &gDeferredCube,
        (UFG::qMatrix44 *)&local_world.v0.z,
        0,
        (Illusion::Material *)v40->mData);
      v41 = 1537965747;
      if ( gClearStencil )
        v41 = -1835606658;
      if ( *(_DWORD *)&mSkyAmbientMaterial[3].mDebugName[12] != v41 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mSkyAmbientMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
          *(_DWORD *)&mSkyAmbientMaterial[3].mDebugName[20],
          v41);
        v42 = mSkyAmbientMaterial->mMaterialUser.mOffset;
        if ( v42 )
          v43 = (_WORD *)((char *)&mSkyAmbientMaterial->mMaterialUser + v42);
        else
          v43 = 0i64;
        *v43 |= 0x20u;
      }
      Render::View::Draw(
        &view,
        &gDeferredCube,
        (UFG::qMatrix44 *)&local_world.v0.z,
        0,
        render_context->mSkyAmbientMaterial);
      StateArgs = p_mStateArgs;
    }
    if ( render_context->mRenderSun )
    {
      mSunUsingCollectorMaterial = render_context->mSunUsingCollectorMaterial;
      mSunAfterAmbientSpecTestRasterStateUID = 1660426324;
      if ( v18 )
      {
        if ( gClearStencil )
        {
          *(_QWORD *)&d3d_disable_depth_copy[8] = 0i64;
          *(_QWORD *)&local_world.v0.x = 0i64;
          Render::View::Clear(&view, (UFG::qColour *)&d3d_disable_depth_copy[8], 4u, 1.0, 0);
        }
        Render::View::Draw(
          &view,
          &gDeferredCube,
          (UFG::qMatrix44 *)&local_world.v0.z,
          0,
          render_context->mSunAfterAmbientSpecMarkMaterial);
        if ( gClearStencil )
          mSunAfterAmbientSpecTestRasterStateUID = render_context->mSunAfterAmbientSpecTestRasterStateUID;
        else
          mSunAfterAmbientSpecTestRasterStateUID = render_context->mSunAfterAmbientSpecTestNoClearRasterStateUID;
      }
      if ( *(_DWORD *)&mSunUsingCollectorMaterial[3].mDebugName[12] != mSunAfterAmbientSpecTestRasterStateUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mSunUsingCollectorMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
          *(_DWORD *)&mSunUsingCollectorMaterial[3].mDebugName[20],
          mSunAfterAmbientSpecTestRasterStateUID);
        v46 = mSunUsingCollectorMaterial->mMaterialUser.mOffset;
        if ( v46 )
          v47 = (_WORD *)((char *)&mSunUsingCollectorMaterial->mMaterialUser + v46);
        else
          v47 = 0i64;
        *v47 |= 0x20u;
      }
      if ( render_context->mRenderSettingsForFrame.mSSAO == SSAO_HIGH
        && render_context->mLightBufferTarget->mTargetTexture[1] )
      {
        v48 = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR_DO", 0xFFFFFFFF);
        Illusion::Material::UpdateParam(mSunUsingCollectorMaterial, 0, 0x8B5561A1, v48);
      }
      else
      {
        v49 = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR", 0xFFFFFFFF);
        if ( LODWORD(mSunUsingCollectorMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != v49 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mSunUsingCollectorMaterial[1].mNode.mChild[1],
            mSunUsingCollectorMaterial[1].mTypeUID,
            v49);
          v50 = mSunUsingCollectorMaterial->mMaterialUser.mOffset;
          if ( v50 )
            v5 = (_WORD *)((char *)&mSunUsingCollectorMaterial->mMaterialUser + v50);
          *v5 |= 0x20u;
        }
      }
      Render::View::Draw(&view, &poly, mSunUsingCollectorMaterial, 0i64);
    }
    v51 = *(_QWORD *)&local_world.v1.x;
    v52 = *(_QWORD **)&local_world.v1.z;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.x + 8i64) = *(_QWORD *)&local_world.v1.z;
    *v52 = v51;
    *(_QWORD *)&local_world.v1.x = &local_world.v1;
    *(_QWORD *)&local_world.v1.z = &local_world.v1;
    HIBYTE(local_world.v2.z) = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(local_world.v2.z)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(local_world.v2.z)] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(local_world.v2.z) >> 6] &= ~(1i64 << (LOBYTE(local_world.v2.z) & 0x3F));
    Render::View::EndTarget(&view);
    RenderQueueLayer::SerializeRenderQueues(&v60);
    v53 = *(_QWORD *)&local_world.v1.x;
    v54 = *(_QWORD **)&local_world.v1.z;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.x + 8i64) = *(_QWORD *)&local_world.v1.z;
    *v54 = v53;
    *(_QWORD *)&local_world.v1.x = &local_world.v1;
    *(_QWORD *)&local_world.v1.z = &local_world.v1;
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v60);
  }
}

// File Line: 3452
// RVA: 0x550A0
void __fastcall RenderDeferredShadowedSpotlights(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        int spot_shadow_index)
{
  __int64 v3; // r12
  Illusion::StateArgs *StateArgs; // r14
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v11; // rbx
  Illusion::StateValues *v12; // rax
  Illusion::Target *mLightBufferTarget; // r15
  char *v14; // rax
  char *v15; // rbx
  Illusion::RenderQueue *mCommandQueue; // rcx
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rcx
  void (__fastcall *mCallback)(Illusion::StateArg *, Illusion::StateValues *); // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // rsi
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rax
  UFG::qNode<SerializationList,SerializationList> *v26; // rcx
  UFG::qNode<SerializationList,SerializationList> *v27; // rax
  SerializationList v28; // [rsp+50h] [rbp-78h] BYREF
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-50h] BYREF
  RenderQueueLayer v30; // [rsp+218h] [rbp+150h] BYREF
  LayerSubmitContext ptr; // [rsp+2F8h] [rbp+230h] BYREF
  void *p_mList; // [rsp+FD8h] [rbp+F10h]
  char *v33; // [rsp+FF0h] [rbp+F28h]

  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)-2i64;
  v3 = spot_shadow_index;
  if ( render_context->mRenderFeatures.mWorld && render_context->mRenderFeatures.mLights )
  {
    RenderQueueLayer::RenderQueueLayer(&v30);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v30.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v30;
    ptr.mQueueMode = QM_Single;
    Render::View::View((Render::View *)&arg.mCallback, &render_context->mMainViewSettings, &ptr);
    StateArgs = Render::View::GetStateArgs((Render::View *)&arg.mCallback);
    Render::View::BeginTarget(
      (Render::View *)&arg.mCallback,
      render_context->mLightBufferTarget,
      "LightBuffer",
      0,
      0,
      0i64,
      0,
      0,
      0,
      0);
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues((Render::View *)&arg.mCallback);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v11 = mSimTime_Temp;
    *((float *)v11 + 1) = mSimTimeDelta;
    v12 = Render::View::GetStateValues((Render::View *)&arg.mCallback);
    v12->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v12->mParamValues[13] = v11;
    v28.mPrev = &v28;
    v28.mNext = &v28;
    p_mList = &v28.mList;
    v28.mList.mNode.mPrev = &v28.mList.mNode;
    v28.mList.mNode.mNext = &v28.mList.mNode;
    v28.mCommandQueue = 0i64;
    mLightBufferTarget = render_context->mLightBufferTarget;
    v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    p_mList = v14;
    v33 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = mLightBufferTarget;
      *((_QWORD *)v14 + 1) = 0i64;
      *((_DWORD *)v14 + 4) = 0;
      *((_QWORD *)v14 + 3) = "LightBufferPhase2";
    }
    else
    {
      v14 = 0i64;
    }
    SerializationList::AddCommand(&v28, 14, v14);
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(mLightBufferTarget, (Illusion::ViewportScissorState *)v15, 0);
    SerializationList::AddCommand(&v28, 9, v15);
    mCommandQueue = v28.mCommandQueue;
    if ( v28.mCommandQueue )
    {
      mFreeBucket = v28.mCommandQueue->mFreeBucket;
      if ( mFreeBucket )
      {
        v28.mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
        mCommandQueue->mFreeBucket = 0i64;
      }
      v28.mCommandQueue = 0i64;
    }
    mNext = v28.mList.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v28.mList.mNode.mNext != &v28.mList )
    {
      mPrev = serialization_list->mNode.mPrev;
      v20 = v28.mList.mNode.mPrev;
      mPrev->mNext = v28.mList.mNode.mNext;
      mNext->mPrev = mPrev;
      v20->mNext = &serialization_list->mNode;
      serialization_list->mNode.mPrev = v20;
      v28.mList.mNode.mPrev = &v28.mList.mNode;
      v28.mList.mNode.mNext = &v28.mList.mNode;
    }
    mCallback = arg.mCallback;
    v22 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)((char *)arg.mCallback + 64);
    arg.mPrev = &arg;
    v28.mPrev = 0i64;
    LOWORD(v28.mNext) = Render::cbExternalViewTransformState::sStateParamIndex;
    WORD1(v28.mNext) = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = Param;
      LOWORD(v28.mNext) = Param;
    }
    v28.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)mCallback;
    v28.mList.mNode.mNext = v22;
    v28.mCommandQueue = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    DrawShadowedSpotLights(render_context, (Render::View *)&arg.mCallback, &gSpotShadowIndices[v3], 1u);
    arg.mPrev->mNext = &arg;
    arg.mPrev = &arg;
    BYTE3(v28.mNext) = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(v28.mNext)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(v28.mNext)] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v28.mNext) >> 6] &= ~(1i64 << ((__int64)v28.mNext & 0x3F));
    Render::View::EndTarget((Render::View *)&arg.mCallback);
    arg.mPrev->mNext = &arg;
    arg.mPrev = &arg;
    p_mList = &v28.mList;
    UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v28.mList);
    v24 = v28.mList.mNode.mPrev;
    v25 = v28.mList.mNode.mNext;
    v28.mList.mNode.mPrev->mNext = v28.mList.mNode.mNext;
    v25->mPrev = v24;
    v28.mList.mNode.mPrev = &v28.mList.mNode;
    v28.mList.mNode.mNext = &v28.mList.mNode;
    v26 = v28.mPrev;
    v27 = v28.mNext;
    v28.mPrev->mNext = v28.mNext;
    v27->mPrev = v26;
    v28.mPrev = &v28;
    v28.mNext = &v28;
    p_mList = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v30);
  }
}

// File Line: 3513
// RVA: 0x54850
void __fastcall RenderDeferredLights_2(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        int num_lights)
{
  _WORD *v6; // rdi
  Illusion::StateArgs *StateArgs; // r14
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v12; // rbx
  Illusion::StateValues *v13; // rax
  Illusion::Target *mLightBufferTarget; // r15
  char *v15; // rax
  char *v16; // rbx
  Illusion::RenderQueue *mCommandQueue; // rcx
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rcx
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rax
  Illusion::Target *mDirectionalOcclusionTarget; // rdx
  unsigned int mUID; // r8d
  Illusion::Material *mSSDOMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v31; // rax
  unsigned int v32; // r8d
  Illusion::Material *v33; // rbx
  __int64 v34; // rax
  _WORD *v35; // rax
  unsigned __int16 v36; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rax
  Illusion::Material *mMaterial; // rbx
  __int64 v42; // rax
  _WORD *v43; // rax
  unsigned int v44; // r8d
  __int64 v45; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v46; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v47; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v48; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v49; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v52; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v53; // rax
  UFG::qNode<SerializationList,SerializationList> *v54; // rcx
  UFG::qNode<SerializationList,SerializationList> *v55; // rax
  SerializationList v56; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-88h] BYREF
  Render::cbLocalProjectionState v58; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v59; // [rsp+E8h] [rbp-18h]
  char *v60; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h] BYREF
  UFG::qMatrix44 result; // [rsp+290h] [rbp+190h] BYREF
  RenderQueueLayer v63; // [rsp+2D0h] [rbp+1D0h] BYREF
  LayerSubmitContext ptr; // [rsp+3B0h] [rbp+2B0h] BYREF
  Render::Poly poly; // [rsp+1090h] [rbp+F90h] BYREF
  void *p_mList; // [rsp+10A8h] [rbp+FA8h]

  v59 = -2i64;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v63);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v63.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v63;
    v6 = 0i64;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
    StateArgs = Render::View::GetStateArgs(&view);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&view, render_context->mLightBufferTarget, "LightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(&view);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v12 = mSimTime_Temp;
    *((float *)v12 + 1) = mSimTimeDelta;
    v13 = Render::View::GetStateValues(&view);
    v13->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v13->mParamValues[13] = v12;
    v56.mPrev = &v56;
    v56.mNext = &v56;
    p_mList = &v56.mList;
    v56.mList.mNode.mPrev = &v56.mList.mNode;
    v56.mList.mNode.mNext = &v56.mList.mNode;
    v56.mCommandQueue = 0i64;
    mLightBufferTarget = render_context->mLightBufferTarget;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    p_mList = v15;
    v60 = v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = mLightBufferTarget;
      *((_QWORD *)v15 + 1) = 0i64;
      *((_DWORD *)v15 + 4) = 0;
      *((_QWORD *)v15 + 3) = "LightBufferPhase2";
    }
    else
    {
      v15 = 0i64;
    }
    SerializationList::AddCommand(&v56, 14, v15);
    v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(mLightBufferTarget, (Illusion::ViewportScissorState *)v16, 0);
    SerializationList::AddCommand(&v56, 9, v16);
    mCommandQueue = v56.mCommandQueue;
    if ( v56.mCommandQueue )
    {
      mFreeBucket = v56.mCommandQueue->mFreeBucket;
      if ( mFreeBucket )
      {
        v56.mCommandQueue->mCommandCount += mFreeBucket->mNumCommands;
        mCommandQueue->mFreeBucket = 0i64;
      }
      v56.mCommandQueue = 0i64;
    }
    mNext = v56.mList.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v56.mList.mNode.mNext != &v56.mList )
    {
      mPrev = serialization_list->mNode.mPrev;
      v21 = v56.mList.mNode.mPrev;
      mPrev->mNext = v56.mList.mNode.mNext;
      mNext->mPrev = mPrev;
      v21->mNext = &serialization_list->mNode;
      serialization_list->mNode.mPrev = v21;
      v56.mList.mNode.mPrev = &v56.mList.mNode;
      v56.mList.mNode.mNext = &v56.mList.mNode;
    }
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
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    render_context->mRenderStats.mNumLightsProcessed += num_lights;
    SyncFlushDrawLightingTask(render_context, &view);
    v25 = arg.mPrev;
    v26 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v26->mPrev = v25;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    if ( render_context->mRenderSettingsForFrame.mSSAO == SSAO_HIGH )
    {
      mDirectionalOcclusionTarget = render_context->mDirectionalOcclusionTarget;
      if ( mDirectionalOcclusionTarget )
      {
        Render::View::BeginTarget(
          &view,
          mDirectionalOcclusionTarget,
          "DirectionalOcclusionTarget",
          0,
          0,
          0i64,
          0,
          0,
          0,
          0);
        mUID = render_context->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
        mSSDOMaterial = render_context->mSSDOMaterial;
        if ( *(_DWORD *)&mSSDOMaterial[2].mDebugName[28] != mUID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mSSDOMaterial[2].mDebugName[4],
            *((_DWORD *)&mSSDOMaterial[2].UFG::qResourceData + 22),
            mUID);
          mOffset = mSSDOMaterial->mMaterialUser.mOffset;
          if ( mOffset )
            v31 = (_WORD *)((char *)&mSSDOMaterial->mMaterialUser + mOffset);
          else
            v31 = 0i64;
          *v31 |= 0x20u;
        }
        v32 = render_context->mLightBufferTarget->mTargetTexture[1]->mNode.mUID;
        v33 = render_context->mSSDOMaterial;
        if ( LODWORD(v33[3].mMaterialUser.mOffset) != v32 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v33[3].mStateBlockMask,
            (unsigned int)v33[4].mNode.mParent,
            v32);
          v34 = v33->mMaterialUser.mOffset;
          if ( v34 )
            v35 = (_WORD *)((char *)&v33->mMaterialUser + v34);
          else
            v35 = 0i64;
          *v35 |= 0x20u;
        }
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
        if ( (_S18 & 1) == 0 )
        {
          _S18 |= 1u;
          viewCorrector.v0 = (UFG::qVector4)_xmm;
          viewCorrector.v1 = (UFG::qVector4)_xmm;
          viewCorrector.v2 = (UFG::qVector4)_xmm;
          viewCorrector.v3 = (UFG::qVector4)_xmm;
        }
        UFG::qMatrix44::operator*(&view.mWorldViewProjection, &result, &viewCorrector);
        v58.mPrev = &v58;
        v58.mNext = &v58;
        v58.mCallback = 0i64;
        v58.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
        *(_WORD *)&v58.mFlags = 1;
        if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
        {
          v36 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
          Render::cbLocalProjectionState::sStateParamIndex = v36;
          v58.mStateParamIndex = v36;
        }
        v58.mCached_Remote.m_Stream = 0i64;
        v58.mWorldViewProjection = &result;
        v58.mLocalWorld = &view.mViewWorld;
        Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v58);
        Render::View::Draw(&view, &poly, render_context->mSSDOMaterial, 0i64);
        v37 = arg.mPrev;
        v38 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v38->mPrev = v37;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
          StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v39 = v58.mPrev;
        v40 = v58.mNext;
        v58.mPrev->mNext = v58.mNext;
        v40->mPrev = v39;
        v58.mPrev = &v58;
        v58.mNext = &v58;
        v58.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v58.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v58.mStateParamIndex] )
          StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v58.mStateParamIndex >> 6] &= ~(1i64 << (v58.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&view);
        Render::View::BeginTarget(&view, render_context->mLightBufferTarget, "DOtoLightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
        mMaterial = Render::gRenderUtilities.mMaterial;
        if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 826356572 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
            Render::gRenderUtilities.mMaterial[1].mTypeUID,
            0x3141335Cu);
          v42 = mMaterial->mMaterialUser.mOffset;
          if ( v42 )
            v43 = (_WORD *)((char *)&mMaterial->mMaterialUser + v42);
          else
            v43 = 0i64;
          *v43 |= 0x20u;
          mMaterial = Render::gRenderUtilities.mMaterial;
        }
        v44 = render_context->mDirectionalOcclusionTarget->mTargetTexture[0]->mNode.mUID;
        if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != v44 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
            mMaterial[1].mStateBlockMask.mFlags[1],
            v44);
          v45 = mMaterial->mMaterialUser.mOffset;
          if ( v45 )
            v6 = (_WORD *)((char *)&mMaterial->mMaterialUser + v45);
          *v6 |= 0x20u;
          mMaterial = Render::gRenderUtilities.mMaterial;
        }
        Render::View::Draw(&view, &poly, mMaterial, 0i64);
        v46 = arg.mPrev;
        v47 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v47->mPrev = v46;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
          StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&view);
        v48 = v58.mPrev;
        v49 = v58.mNext;
        v58.mPrev->mNext = v58.mNext;
        v49->mPrev = v48;
        v58.mPrev = &v58;
        v58.mNext = &v58;
      }
    }
    if ( render_context->mRenderSkinSS || UFG::RenderWorld::msStageHairSkin->mEnableHairLighting )
      UFG::RenderStageHairSkin::Render(
        UFG::RenderWorld::msStageHairSkin,
        render_context,
        serialization_list,
        &gCompositeDrawableCullLayer);
    v50 = arg.mPrev;
    v51 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v51->mPrev = v50;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    p_mList = &v56.mList;
    UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v56.mList);
    v52 = v56.mList.mNode.mPrev;
    v53 = v56.mList.mNode.mNext;
    v56.mList.mNode.mPrev->mNext = v56.mList.mNode.mNext;
    v53->mPrev = v52;
    v56.mList.mNode.mPrev = &v56.mList.mNode;
    v56.mList.mNode.mNext = &v56.mList.mNode;
    v54 = v56.mPrev;
    v55 = v56.mNext;
    v56.mPrev->mNext = v56.mNext;
    v55->mPrev = v54;
    v56.mPrev = &v56;
    v56.mNext = &v56;
    p_mList = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v63);
  }
}

// File Line: 3660
// RVA: 0x5AFC0
void __fastcall SetRainState(Render::View *view)
{
  char *v2; // rdi
  UFG::qMatrix44 *v3; // rax
  unsigned int v4; // eax
  unsigned __int16 v5; // bx
  Illusion::StateValues *StateValues; // rax
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qMatrix44 d; // [rsp+70h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+B0h] [rbp-48h] BYREF

  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x140u, 0x140u);
  if ( (_S19 & 1) == 0 )
  {
    _S19 |= 1u;
    viewCorrector_0.v0 = (UFG::qVector4)_xmm;
    viewCorrector_0.v1 = (UFG::qVector4)_xmm;
    viewCorrector_0.v2 = (UFG::qVector4)_xmm;
    viewCorrector_0.v3 = (UFG::qVector4)_xmm;
  }
  v3 = UFG::qMatrix44::operator*(
         &UFG::RenderWorld::msStageShadow->mShadowViewSettings[3].mWorldView,
         &result,
         &UFG::RenderWorld::msStageShadow->mShadowViewSettings[3].mProjection);
  UFG::qMatrix44::operator*(v3, &m, &viewCorrector_0);
  UFG::qInverse(&d, &m);
  UFG::qMemCopy(v2, &m, 0x40u);
  UFG::qMemCopy(v2 + 64, &d, 0x40u);
  if ( (_S19 & 2) != 0 )
  {
    v5 = rainSettingsParamIndex;
  }
  else
  {
    _S19 |= 2u;
    v4 = UFG::qStringHash32("cbRainSettings", 0xFFFFFFFF);
    v5 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v4, "cbRainSettings", 0);
    rainSettingsParamIndex = v5;
  }
  StateValues = Render::View::GetStateValues(view);
  if ( (unsigned int)(__int16)v5 >= 0x40 )
    StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v5 - 64);
  else
    StateValues->mSetValueMask.mFlags[0] |= 1i64 << v5;
  StateValues->mParamValues[(__int16)v5] = v2;
}

// File Line: 3694
// RVA: 0x55690
void __fastcall RenderFXHalfsize(Render::View *view, UFG::RenderContext *render_context)
{
  Illusion::StateArgs *StateArgs; // rsi
  Illusion::SubmitContext *mSubmitContext; // r14
  float *mShadowFilterWidth; // r15
  float *mBiases; // r12
  float *mCutplanes; // r13
  unsigned __int16 Param; // ax
  Illusion::Texture *mHalfSizeShadowAliasTexture; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rax
  Render::cbShadowTransformState arg; // [rsp+30h] [rbp-A8h] BYREF
  Illusion::Texture *mHeightmapShadowTextureAlias; // [rsp+88h] [rbp-50h]
  __int64 v17[4]; // [rsp+90h] [rbp-48h] BYREF
  int v18; // [rsp+B0h] [rbp-28h]
  __int64 v19; // [rsp+B8h] [rbp-20h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+C8h] [rbp-10h] BYREF

  v19 = -2i64;
  StateArgs = Render::View::GetStateArgs(view);
  if ( gRenderFX )
  {
    mSubmitContext = view->mSubmitContext;
    v17[0] = 0i64;
    v17[1] = 0i64;
    v18 = 0;
    v17[3] = -1i64;
    v17[2] = -1i64;
    mSubmitContext->mShaderSelector = (Illusion::ShaderSelector *)v17;
    UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
    mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
    mBiases = UFG::RenderWorld::msStageShadow->mBiases;
    mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
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
    arg.mViewWorld = &view->mViewWorld;
    arg.mProjection = views.mProjection;
    arg.mCutplanes = mCutplanes;
    arg.mBiases = mBiases;
    arg.mBlurWidths = mShadowFilterWidth;
    arg.mWorldView = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &arg);
    SetRainState(view);
    arg.mCutplanes = (const float *)render_context->mHalfSizeLinearDepthTarget->mDepthTextureCopy;
    arg.mBiases = (const float *)render_context->mDynamicRangeTarget->mTargetTexture[0];
    if ( render_context->mRenderSun )
      mHalfSizeShadowAliasTexture = render_context->mHalfSizeShadowAliasTexture;
    else
      mHalfSizeShadowAliasTexture = 0i64;
    arg.mBlurWidths = (const float *)mHalfSizeShadowAliasTexture;
    arg.mCached_Remote.m_Stream = render_context->mHeightmapTarget->mDepthTexture;
    mHeightmapShadowTextureAlias = render_context->mHeightmapShadowTextureAlias;
    Render::FXManager::Render(
      &Render::gFXManager,
      view,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_LOW_QUALITY,
      (Render::FXManagerAuxBuffers *)&arg.mCutplanes);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    mSubmitContext->mShaderSelector = 0i64;
    v13 = arg.mPrev;
    v14 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v14->mPrev = v13;
  }
}

// File Line: 3733
// RVA: 0x560D0
void __fastcall RenderHalfSizeBuffer(UFG::RenderContext *render_context, UFG::qMatrix44 *serialization_list)
{
  Illusion::StateArgs *StateArgs; // rsi
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v9; // rbx
  Illusion::StateValues *v10; // rax
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h] BYREF
  Render::View view; // [rsp+158h] [rbp+80h] BYREF
  ForwardSubmitContext ptr; // [rsp+2E8h] [rbp+210h] BYREF
  Render::Poly v21; // [rsp+FC8h] [rbp+EF0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FD8h] [rbp+F00h]

  arg.mWorldView = (UFG::qMatrix44 *)-2i64;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
    ForwardSubmitContext::ForwardSubmitContext(&ptr);
    *(_QWORD *)&arg.mStateParamIndex = AlphaStateNoneHandle.mData;
    arg.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))RasterStateNormalHandle.mData;
    arg.mProjection = serialization_list;
    ptr.mPerPhaseParams = (ForwardSubmitContext::PerPhaseParams *)&arg.mCallback;
    ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mProjection;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
    StateArgs = Render::View::GetStateArgs(&view);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v21);
    Render::View::BeginTarget(&view, render_context->mHalfSizeTarget, "HalfSizeEffects", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 1u, 1.0, 0);
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(&view);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v9 = mSimTime_Temp;
    *((float *)v9 + 1) = mSimTimeDelta;
    v10 = Render::View::GetStateValues(&view);
    v10->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v10->mParamValues[13] = v9;
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
    arg.mNext = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    if ( gCurrentEye == STEREO_EYE_LEFT && gEnableClouds )
    {
      Render::View::DrawSegment(&view, &UFG::qVector3::msZero, &UFG::qVector3::msZero, &UFG::DrawInfo::msDefault);
      RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mProjection);
      Render::SkyMarshall::SyncFlushDrawCloudTask(
        &Render::SkyMarshall::gSkyMarshall,
        (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)arg.mProjection);
    }
    RenderFXHalfsize(&view, render_context);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mProjection);
    v16 = arg.mPrev;
    v17 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v17->mPrev = v16;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
  }
}

// File Line: 3808
// RVA: 0x59000
void __fastcall RenderVolumetrics(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  char v4; // di
  Illusion::StateArgs *StateArgs; // r14
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // rdi
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h] BYREF
  __int64 v16; // [rsp+90h] [rbp-48h] BYREF
  Render::View v17; // [rsp+148h] [rbp+70h] BYREF
  ForwardSubmitContext ptr; // [rsp+2D8h] [rbp+200h] BYREF
  Render::Poly poly; // [rsp+F98h] [rbp+EC0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+FA0h] [rbp+EC8h]

  arg.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))-2i64;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v16);
  ForwardSubmitContext::ForwardSubmitContext(&ptr);
  *(_QWORD *)&arg.mStateParamIndex = serialization_list;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mStateParamIndex;
  ptr.mQueueMode = QM_Single;
  v4 = Render::CloudVolumeManager::RenderCloudVolumeFog(
         &Render::gCloudVolumeManager,
         render_context,
         serialization_list,
         1);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  Render::CloudVolumeManager::RenderCloudVolumeFog(&Render::gCloudVolumeManager, render_context, serialization_list, 0);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  Render::View::View(&v17, &render_context->mMainViewSettings, &ptr);
  StateArgs = Render::View::GetStateArgs(&v17);
  Render::View::BeginTarget(
    &v17,
    render_context->mHalfSizeVolumetricTarget,
    "VolumetricCloudsUpsample",
    0,
    0,
    0i64,
    1,
    0,
    0,
    0);
  if ( !v4 )
    Render::View::Clear(&v17, &UFG::qColour::Zero, 1u, 1.0, 0);
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&v17);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  mSettings = v17.mSettings;
  p_mProjection = &v17.mSettings->mProjection;
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
  arg.mNext = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v17, &poly, render_context->mMatBlendVolumesIntoHalfSize, 0i64);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v17);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  v13 = arg.mPrev;
  v14 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v14->mPrev = v13;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)&arg.mStateParamIndex);
}

// File Line: 3861
// RVA: 0x1456190
__int64 dynamic_initializer_for__gMarkSkyRasterStateHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&gMarkSkyRasterStateHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMarkSkyRasterStateHandle__);
}

// File Line: 3899
// RVA: 0x4A3C0
void __fastcall CompositeLightsAndEffects(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *postfx_1_serialization_list,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *postfx_2_serialization_list)
{
  _WORD *v6; // rsi
  Illusion::StateArgs *StateArgs; // r14
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  unsigned int v11; // eax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v16; // rbx
  Illusion::StateValues *v17; // rax
  CB_SkySettings *mSkyState; // r12
  unsigned int v19; // ebx
  Illusion::StateValues *v20; // rax
  float *mShadowFilterWidth; // rbx
  float *mBiases; // r12
  unsigned __int16 v23; // ax
  float *v24; // r12
  Render::ViewSettings *v25; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  float v27; // xmm2_4
  float v28; // xmm6_4
  Render::ViewSettings *v29; // rbx
  UFG::TimeOfDayManager *v30; // rax
  float v31; // xmm2_4
  float v32; // xmm6_4
  Render::ViewSettings *v33; // rbx
  float *v34; // rax
  float v35; // xmm2_4
  float v36; // xmm6_4
  Illusion::Material *mCompositeLightingMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v39; // rax
  Illusion::Target *mFullSizeScratchTargetA; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v42; // rbx
  __int64 v43; // rax
  _WORD *v44; // rax
  unsigned int v45; // r8d
  Illusion::Material *v46; // rbx
  __int64 v47; // rax
  _WORD *v48; // rax
  Illusion::StateValues *v49; // rax
  Render::EnvCubeMap *mEnvCubeMap; // rax
  UFG::qResourceData *mData; // rbx
  Illusion::StateValues *v52; // rax
  UFG::TimeOfDayManager *v53; // rax
  Illusion::Texture *FogTexture; // rbx
  Illusion::StateValues *v55; // rax
  Illusion::Texture *mHalfSizeShadowAliasTexture; // rbx
  Illusion::StateValues *v57; // rax
  UFG::qResourceData *v58; // rbx
  Illusion::StateValues *v59; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v62; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v64; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v65; // rax
  unsigned int v66; // r8d
  UFG::qResourceData *v67; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v68; // rax
  _WORD *v69; // rax
  unsigned int v70; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v71; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v72; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v73; // rax
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *p_mNode; // rcx
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v75; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v76; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v77; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v78; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v79; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbShadowTransformState v81; // [rsp+90h] [rbp-70h] BYREF
  __int64 v82[4]; // [rsp+F0h] [rbp-10h] BYREF
  int v83; // [rsp+110h] [rbp+10h]
  __int64 v84; // [rsp+118h] [rbp+18h]
  Render::View pView; // [rsp+120h] [rbp+20h] BYREF
  RenderQueueLayer v86; // [rsp+2B0h] [rbp+1B0h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+390h] [rbp+290h] BYREF
  CompositeSubmitContext ptr; // [rsp+590h] [rbp+490h] BYREF
  Render::Poly v89; // [rsp+1280h] [rbp+1180h] BYREF
  Illusion::StateArgs *mCutplanes; // [rsp+1288h] [rbp+1188h]
  Render::Poly poly; // [rsp+1290h] [rbp+1190h] BYREF

  v84 = -2i64;
  RenderQueueLayer::RenderQueueLayer(&v86);
  CompositeSubmitContext::CompositeSubmitContext(&ptr);
  v86.mSerializationList = postfx_1_serialization_list;
  ptr.mRenderQueueProvider = &v86;
  v6 = 0i64;
  ptr.mQueueMode = QM_Single;
  ptr.mOverrideMode = 0;
  Render::View::View(&pView, &render_context->mMainViewSettings, &ptr);
  StateArgs = Render::View::GetStateArgs(&pView);
  mSettings = pView.mSettings;
  p_mProjection = &pView.mSettings->mProjection;
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
  Render::View::BeginTarget(
    &pView,
    render_context->mDynamicRangeTarget,
    "CompositeLightsAndEffects",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  Render::View::Clear(&pView, &UFG::qColour::Zero, 4u, 1.0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  if ( (_S20 & 1) == 0 )
  {
    _S20 |= 1u;
    v11 = UFG::qStringHash32("cbSkySettings", 0xFFFFFFFF);
    skySettingsIndex_0 = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             v11,
                                             "cbSkySettings",
                                             0);
  }
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&pView);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v16 = mSimTime_Temp;
  *((float *)v16 + 1) = mSimTimeDelta;
  v17 = Render::View::GetStateValues(&pView);
  v17->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v17->mParamValues[13] = v16;
  mSkyState = render_context->mSkyState;
  v19 = (__int16)skySettingsIndex_0;
  v20 = Render::View::GetStateValues(&pView);
  if ( v19 >= 0x40 )
    v20->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v19 - 64);
  else
    v20->mSetValueMask.mFlags[0] |= 1i64 << v19;
  v20->mParamValues[(__int16)v19] = mSkyState;
  v82[0] = 0i64;
  v82[1] = 0i64;
  v83 = 0;
  v82[3] = -1i64;
  v82[2] = -1i64;
  ptr.mShaderSelector = (Illusion::ShaderSelector *)v82;
  ptr.mOverrideMode = None;
  Render::SkyMarshall::RenderFar(&Render::SkyMarshall::gSkyMarshall, &pView, 1.0);
  Render::SkyMarshall::RenderCloudDome(&Render::SkyMarshall::gSkyMarshall, &pView, 1.0);
  ptr.mShaderSelector = 0i64;
  ptr.mOverrideMode = 0;
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  mBiases = UFG::RenderWorld::msStageShadow->mBiases;
  mCutplanes = (Illusion::StateArgs *)UFG::RenderWorld::msStageShadow->mCutplanes;
  v81.mPrev = &v81;
  v81.mNext = &v81;
  v81.mCallback = 0i64;
  v81.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v81.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v23 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v23;
    v81.mStateParamIndex = v23;
  }
  v81.mViewWorld = &pView.mViewWorld;
  v81.mWorldView = (UFG::qMatrix44 *)&views;
  v81.mProjection = views.mProjection;
  v81.mCutplanes = (const float *)mCutplanes;
  v81.mBiases = mBiases;
  v81.mBlurWidths = mShadowFilterWidth;
  v81.mCached_Remote.m_Stream = 0i64;
  v24 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  v25 = pView.mSettings;
  Instance = UFG::TimeOfDayManager::GetInstance();
  v27 = (float)((float)(Instance->mAmbientSkyDirection[0].x * v25->mWorldView.v0.y)
              + (float)(Instance->mAmbientSkyDirection[0].y * v25->mWorldView.v1.y))
      + (float)(Instance->mAmbientSkyDirection[0].z * v25->mWorldView.v2.y);
  v28 = (float)((float)(Instance->mAmbientSkyDirection[0].x * v25->mWorldView.v0.z)
              + (float)(Instance->mAmbientSkyDirection[0].y * v25->mWorldView.v1.z))
      + (float)(Instance->mAmbientSkyDirection[0].z * v25->mWorldView.v2.z);
  v24[4] = (float)((float)(Instance->mAmbientSkyDirection[0].y * v25->mWorldView.v1.x)
                 + (float)(Instance->mAmbientSkyDirection[0].x * v25->mWorldView.v0.x))
         + (float)(Instance->mAmbientSkyDirection[0].z * v25->mWorldView.v2.x);
  v24[5] = v27;
  v24[6] = v28;
  v29 = pView.mSettings;
  v30 = UFG::TimeOfDayManager::GetInstance();
  v31 = (float)((float)(v30->mAmbientSkyDirection[1].x * v29->mWorldView.v0.y)
              + (float)(v30->mAmbientSkyDirection[1].y * v29->mWorldView.v1.y))
      + (float)(v30->mAmbientSkyDirection[1].z * v29->mWorldView.v2.y);
  v32 = (float)((float)(v30->mAmbientSkyDirection[1].x * v29->mWorldView.v0.z)
              + (float)(v30->mAmbientSkyDirection[1].y * v29->mWorldView.v1.z))
      + (float)(v30->mAmbientSkyDirection[1].z * v29->mWorldView.v2.z);
  v24[8] = (float)((float)(v30->mAmbientSkyDirection[1].y * v29->mWorldView.v1.x)
                 + (float)(v30->mAmbientSkyDirection[1].x * v29->mWorldView.v0.x))
         + (float)(v30->mAmbientSkyDirection[1].z * v29->mWorldView.v2.x);
  v24[9] = v31;
  v24[10] = v32;
  v33 = pView.mSettings;
  v34 = (float *)UFG::TimeOfDayManager::GetInstance();
  v35 = (float)((float)(v34[45] * v33->mWorldView.v0.y) + (float)(v34[46] * v33->mWorldView.v1.y))
      + (float)(v34[47] * v33->mWorldView.v2.y);
  v36 = (float)((float)(v34[45] * v33->mWorldView.v0.z) + (float)(v34[46] * v33->mWorldView.v1.z))
      + (float)(v34[47] * v33->mWorldView.v2.z);
  v24[12] = (float)((float)(v34[46] * v33->mWorldView.v1.x) + (float)(v34[45] * v33->mWorldView.v0.x))
          + (float)(v34[47] * v33->mWorldView.v2.x);
  v24[13] = v35;
  v24[14] = v36;
  mCompositeLightingMaterial = render_context->mCompositeLightingMaterial;
  if ( LODWORD(mCompositeLightingMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 443851384 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mCompositeLightingMaterial[1].mNode.mChild[1],
      mCompositeLightingMaterial[1].mTypeUID,
      0x1A74A278u);
    mOffset = mCompositeLightingMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v39 = (_WORD *)((char *)&mCompositeLightingMaterial->mMaterialUser + mOffset);
    else
      v39 = 0i64;
    *v39 |= 0x20u;
  }
  if ( render_context->mRenderSun )
    mFullSizeScratchTargetA = render_context->mFullSizeScratchTargetA;
  else
    mFullSizeScratchTargetA = render_context->mAmbientOcclusionAliasTarget;
  mUID = mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  v42 = render_context->mCompositeLightingMaterial;
  if ( LODWORD(v42[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v42[5].mNode.mChild,
      (unsigned int)v42[5].mResourceHandles.UFG::qResourceData::mNode.mNext,
      mUID);
    v43 = v42->mMaterialUser.mOffset;
    if ( v43 )
      v44 = (_WORD *)((char *)&v42->mMaterialUser + v43);
    else
      v44 = 0i64;
    *v44 |= 0x20u;
  }
  v45 = render_context->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
  v46 = render_context->mCompositeLightingMaterial;
  if ( v46[2].mNode.mUID != v45 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v46[2],
      (unsigned int)v46[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      v45);
    v47 = v46->mMaterialUser.mOffset;
    if ( v47 )
      v48 = (_WORD *)((char *)&v46->mMaterialUser + v47);
    else
      v48 = 0i64;
    *v48 |= 0x20u;
  }
  v49 = Render::View::GetStateValues(&pView);
  v49->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v49->mParamValues[15] = v24;
  mEnvCubeMap = render_context->mEnvCubeMap;
  if ( mEnvCubeMap )
    mData = &mEnvCubeMap->mTarget->mTargetTexture[0]->UFG::qResourceData;
  else
    mData = gDefaultBlackTexture.mData;
  v52 = Render::View::GetStateValues(&pView);
  v52->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
  v52->mParamValues[40] = mData;
  v53 = UFG::TimeOfDayManager::GetInstance();
  FogTexture = UFG::TimeOfDayManager::GetFogTexture(v53);
  v55 = Render::View::GetStateValues(&pView);
  v55->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  v55->mParamValues[41] = FogTexture;
  mHalfSizeShadowAliasTexture = render_context->mHalfSizeShadowAliasTexture;
  v57 = Render::View::GetStateValues(&pView);
  v57->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v57->mParamValues[61] = mHalfSizeShadowAliasTexture;
  v58 = gArcTanTexture.mData;
  v59 = Render::View::GetStateValues(&pView);
  v59->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
  v59->mParamValues[43] = v58;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v81);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&pView, &poly, render_context->mCompositeLightingMaterial, 0i64);
  if ( render_context->mRenderSun && UFG::RenderWorld::msStageShadow->mDrawDebugCascadeCoverage )
    UFG::RenderStageShadow::RenderCascadeDebug(UFG::RenderWorld::msStageShadow, &pView, render_context);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v62 = v81.mPrev;
  v63 = v81.mNext;
  v81.mPrev->mNext = v81.mNext;
  v63->mPrev = v62;
  v81.mPrev = &v81;
  v81.mNext = &v81;
  v81.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v81.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v81.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v81.mStateParamIndex >> 6] &= ~(1i64 << (v81.mStateParamIndex & 0x3F));
  RenderQueueLayer::SerializeRenderQueues(&v86);
  v86.mSerializationList = postfx_2_serialization_list;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v89);
  Render::View::Draw(&pView, &v89, render_context->mPostCompLightshaftMaterial, 0i64);
  v64 = arg.mPrev;
  v65 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v65->mPrev = v64;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  if ( UFG::RenderWorld::msEnableHalfsizeAA || (v66 = -633875363, UFG::RenderWorld::msIsNisPlaying) )
    v66 = 0x11567331;
  v67 = gMatBlit.mData;
  if ( *(_DWORD *)&gMatBlit.mData[1].mDebugName[28] != v66 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&gMatBlit.mData[1].mDebugName[4],
      (unsigned int)gMatBlit.mData[2].mNode.mParent,
      v66);
    v68 = v67[1].mResourceHandles.mNode.mPrev;
    if ( v68 )
      v69 = (_WORD *)((char *)&v68[7].mNext + (_QWORD)v67);
    else
      v69 = 0i64;
    *v69 |= 0x20u;
    v67 = gMatBlit.mData;
  }
  v70 = render_context->mHalfSizeTarget->mTargetTexture[0]->mNode.mUID;
  if ( v67[2].mTypeUID != v70 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v67[2].mNode.mUID, *(_DWORD *)&v67[2].mDebugName[4], v70);
    v71 = v67[1].mResourceHandles.mNode.mPrev;
    if ( v71 )
      v6 = (_WORD *)((char *)&v71[7].mNext + (_QWORD)v67);
    *v6 |= 0x20u;
    v67 = gMatBlit.mData;
  }
  Render::View::Draw(&pView, &v89, (Illusion::Material *)v67, 0i64);
  if ( gRenderFX && render_context->mRenderFeatures.mWorld )
  {
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v81);
    Render::RainManager::Draw(
      &Render::RainManager::gRainManager,
      render_context,
      &pView,
      UFG::Metrics::msInstance.mSimTimeDelta);
    v72 = v81.mPrev;
    v73 = v81.mNext;
    v81.mPrev->mNext = v81.mNext;
    v73->mPrev = v72;
    v81.mPrev = &v81;
    v81.mNext = &v81;
    v81.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v81.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v81.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v81.mStateParamIndex >> 6] &= ~(1i64 << (v81.mStateParamIndex & 0x3F));
    Render::DecalManager::Render(
      &Render::gDecalManager,
      &pView,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_HIGH_QUALITY);
  }
  p_mNode = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
  {
    do
    {
      v75 = (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&p_mNode[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, Render::View *, UFG::RenderContext *))p_mNode->mPrev[7].mPrev)(
        p_mNode,
        &pView,
        render_context);
      p_mNode = &v75->mNode;
    }
    while ( v75 != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 );
  }
  Render::View::EndTarget(&pView);
  v76 = v81.mPrev;
  v77 = v81.mNext;
  v81.mPrev->mNext = v81.mNext;
  v77->mPrev = v76;
  v81.mPrev = &v81;
  v81.mNext = &v81;
  v78 = arg.mPrev;
  v79 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v79->mPrev = v78;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  mCutplanes = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v86);
}

// File Line: 4131
// RVA: 0x1456400
__int64 dynamic_initializer_for__kBloomThreshold__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BLOOMTHRESHOLD", 0xFFFFFFFF);
  kBloomThreshold = result;
  return result;
}

// File Line: 4132
// RVA: 0x14563C0
__int64 dynamic_initializer_for__kBloomComposite__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BLOOMCOMPOSITE", 0xFFFFFFFF);
  kBloomComposite = result;
  return result;
}

// File Line: 4133
// RVA: 0x14563E0
__int64 dynamic_initializer_for__kBloomCompositeVignette__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BLOOMCOMPOSITEVIGNETTE", 0xFFFFFFFF);
  kBloomCompositeVignette = result;
  return result;
}

// File Line: 4136
// RVA: 0x558F0
void __fastcall RenderHDRBloom(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Illusion::Target *current_target)
{
  unsigned int mUID; // r8d
  Illusion::Material *mCompositeFinalMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v9; // rax
  float *v10; // rbx
  Illusion::Target *mDynamicRangeTarget; // rax
  Render::ViewSettings *Identity; // rax
  unsigned int v13; // r8d
  Illusion::Material *mBloomThresholdMaterial; // rdi
  __int64 v15; // rax
  _WORD *v16; // rax
  Illusion::StateValues *StateValues; // rax
  unsigned int v18; // r14d
  float v19; // xmm0_4
  float v20; // xmm1_4
  Illusion::Material *mMaterial; // rbx
  __int64 v22; // rax
  _WORD *v23; // rax
  Illusion::Target **p_mSixtyFourSizeScratchTargetA; // r15
  Render::ViewSettings *v25; // rax
  __int64 v26; // rax
  unsigned int v27; // esi
  int *v28; // rbx
  unsigned int v29; // r12d
  char *v30; // rdi
  Illusion::Material *v31; // rbx
  _WORD *v32; // rax
  _WORD *v33; // rax
  _WORD *v34; // rax
  Illusion::StateValues *v35; // rax
  Illusion::Target *d3d_disable_depth_copy; // [rsp+48h] [rbp-80h]
  Illusion::Target *mThrityTwoSizeScratchTargetB; // [rsp+50h] [rbp-78h]
  Illusion::Target *mThrityTwoSizeScratchTargetA; // [rsp+58h] [rbp-70h]
  Illusion::Target *mSixtyFourSizeScratchTargetA; // [rsp+60h] [rbp-68h] BYREF
  Illusion::Target *mSixteenthSizeScratchTargetB; // [rsp+68h] [rbp-60h]
  Illusion::Target *mSixteenthSizeScratchTargetA; // [rsp+70h] [rbp-58h]
  __int64 v42; // [rsp+78h] [rbp-50h]
  Render::View v43; // [rsp+88h] [rbp-40h] BYREF
  RenderQueueLayer v44; // [rsp+218h] [rbp+150h] BYREF
  LayerSubmitContext ptr; // [rsp+2F8h] [rbp+230h] BYREF
  Render::Poly poly; // [rsp+FC8h] [rbp+F00h] BYREF
  Render::Poly v47; // [rsp+FD0h] [rbp+F08h] BYREF

  v42 = -2i64;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v44.mTreeLayer0.mTree.mNULL.mChild[1]);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v44.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v44;
  ptr.mQueueMode = QM_Single;
  Render::gRenderUtilities.mSubmitContext = &ptr;
  mUID = render_context->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID;
  mCompositeFinalMaterial = render_context->mCompositeFinalMaterial;
  if ( mCompositeFinalMaterial[2].mNode.mUID != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mCompositeFinalMaterial[2],
      (unsigned int)mCompositeFinalMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      mUID);
    mOffset = mCompositeFinalMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v9 = (_WORD *)((char *)&mCompositeFinalMaterial->mMaterialUser + mOffset);
    else
      v9 = 0i64;
    *v9 |= 0x20u;
  }
  v10 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  if ( v10 )
  {
    *v10 = UFG::TimeOfDayManager::GetInstance()->mBloomNearThreshold;
    v10[1] = UFG::TimeOfDayManager::GetInstance()->mBloomBoost;
    v10[2] = UFG::TimeOfDayManager::GetInstance()->mBloomFarThreshold;
    v10[3] = 1.0 / UFG::TimeOfDayManager::GetInstance()->mBloomFarDistance;
    v10[4] = 1.0 - UFG::TimeOfDayManager::GetInstance()->mBloomSaturation;
    v10[5] = UFG::TimeOfDayManager::GetInstance()->mBloomNearDistance;
    mDynamicRangeTarget = render_context->mDynamicRangeTarget;
    v10[8] = 1.0 / (float)mDynamicRangeTarget->mWidth;
    v10[9] = 1.0 / (float)mDynamicRangeTarget->mHeight;
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v43, Identity, &ptr);
    Render::View::BeginTarget(&v43, render_context->mHalfSizeScratchTargetB, "BloomThreshold", 0, 0, 0i64, 1, 0, 0, 0);
    v13 = current_target->mTargetTexture[0]->mNode.mUID;
    mBloomThresholdMaterial = render_context->mBloomThresholdMaterial;
    if ( LODWORD(mBloomThresholdMaterial[1].mStateBlockMask.mFlags[0]) != v13 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mBloomThresholdMaterial[1].mDebugName[20],
        mBloomThresholdMaterial[1].mStateBlockMask.mFlags[1],
        v13);
      v15 = mBloomThresholdMaterial->mMaterialUser.mOffset;
      if ( v15 )
        v16 = (_WORD *)((char *)&mBloomThresholdMaterial->mMaterialUser + v15);
      else
        v16 = 0i64;
      *v16 |= 0x20u;
    }
    StateValues = Render::View::GetStateValues(&v43);
    StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
    StateValues->mParamValues[15] = v10;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v43, &poly, render_context->mBloomThresholdMaterial, 0i64);
    Render::View::EndTarget(&v43);
  }
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    render_context->mHalfSizeScratchTargetB,
    render_context->mQuarterSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mQuarterSizeScratchTargetA,
    render_context->mQuarterSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mQuarterSizeScratchTargetB,
    render_context->mQuarterSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    render_context->mQuarterSizeScratchTargetA,
    render_context->mEighthSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mEighthSizeScratchTargetA,
    render_context->mEighthSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mEighthSizeScratchTargetB,
    render_context->mEighthSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    render_context->mEighthSizeScratchTargetA,
    render_context->mSixteenthSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mSixteenthSizeScratchTargetA,
    render_context->mSixteenthSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mSixteenthSizeScratchTargetB,
    render_context->mSixteenthSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    render_context->mSixteenthSizeScratchTargetA,
    render_context->mThrityTwoSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mThrityTwoSizeScratchTargetA,
    render_context->mThrityTwoSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mThrityTwoSizeScratchTargetB,
    render_context->mThrityTwoSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    render_context->mThrityTwoSizeScratchTargetA,
    render_context->mSixtyFourSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mSixtyFourSizeScratchTargetA,
    render_context->mSixtyFourSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    render_context->mSixtyFourSizeScratchTargetB,
    render_context->mSixtyFourSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  mThrityTwoSizeScratchTargetB = render_context->mThrityTwoSizeScratchTargetB;
  mThrityTwoSizeScratchTargetA = render_context->mThrityTwoSizeScratchTargetA;
  mSixtyFourSizeScratchTargetA = render_context->mSixtyFourSizeScratchTargetA;
  mSixteenthSizeScratchTargetB = render_context->mSixteenthSizeScratchTargetB;
  mSixteenthSizeScratchTargetA = render_context->mSixteenthSizeScratchTargetA;
  v42 = (__int64)mThrityTwoSizeScratchTargetB;
  d3d_disable_depth_copy = render_context->mEighthSizeScratchTargetB;
  mThrityTwoSizeScratchTargetB = render_context->mEighthSizeScratchTargetA;
  mThrityTwoSizeScratchTargetA = mSixteenthSizeScratchTargetB;
  mSixtyFourSizeScratchTargetA = render_context->mHDRBloomTarget;
  mSixteenthSizeScratchTargetB = render_context->mQuarterSizeScratchTargetA;
  mSixteenthSizeScratchTargetA = d3d_disable_depth_copy;
  v18 = kBloomComposite;
  v19 = *(float *)&FLOAT_1_0;
  v20 = UFG::TimeOfDayManager::GetInstance()->m_WeatherState - 1.0;
  if ( v20 <= 0.0 )
  {
    v20 = 0.0;
    goto LABEL_17;
  }
  if ( v20 < 1.0 )
LABEL_17:
    v19 = v20;
  mMaterial = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v22 = mMaterial->mMaterialUser.mOffset;
    if ( v22 )
      v23 = (_WORD *)((char *)&mMaterial->mMaterialUser + v22);
    else
      v23 = 0i64;
    *v23 |= 0x20u;
  }
  p_mSixtyFourSizeScratchTargetA = &mSixtyFourSizeScratchTargetA;
  poly.mVertices = (Render::vDynamic *)4;
  do
  {
    v25 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v43, v25, &ptr);
    Render::View::BeginTarget(&v43, *(p_mSixtyFourSizeScratchTargetA - 2), "BloomComposite", 0, 0, 0i64, 1, 0, 0, 0);
    v26 = (__int64)*(p_mSixtyFourSizeScratchTargetA - 1);
    if ( v26 )
      v27 = *(_DWORD *)(*(_QWORD *)(v26 + 24) + 24i64);
    else
      v27 = 840494775;
    v28 = (int *)*p_mSixtyFourSizeScratchTargetA;
    v29 = (*p_mSixtyFourSizeScratchTargetA)->mTargetTexture[0]->mNode.mUID;
    if ( v27 == render_context->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID )
      v18 = kBloomCompositeVignette;
    v30 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    *(float *)v30 = 1.0 / (float)*v28;
    *((float *)v30 + 1) = 1.0 / (float)v28[1];
    *((float *)v30 + 2) = 0.82999998 - (float)(v19 * 0.079999983);
    *((_DWORD *)v30 + 3) = 0;
    v31 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != v18 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        v18);
      v32 = (_WORD *)v31->mMaterialUser.mOffset;
      if ( v32 )
        v32 = (_WORD *)((char *)v32 + (_QWORD)v31 + 120);
      *v32 |= 0x20u;
      v31 = Render::gRenderUtilities.mMaterial;
    }
    if ( LODWORD(v31[1].mStateBlockMask.mFlags[0]) != v29 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v31[1].mDebugName[20], v31[1].mStateBlockMask.mFlags[1], v29);
      v33 = (_WORD *)v31->mMaterialUser.mOffset;
      if ( v33 )
        v33 = (_WORD *)((char *)v33 + (_QWORD)v31 + 120);
      *v33 |= 0x20u;
      v31 = Render::gRenderUtilities.mMaterial;
    }
    if ( *(_DWORD *)&v31[3].mDebugName[12] != v27 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v31[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
        *(_DWORD *)&v31[3].mDebugName[20],
        v27);
      v34 = (_WORD *)v31->mMaterialUser.mOffset;
      if ( v34 )
        v34 = (_WORD *)((char *)v34 + (_QWORD)v31 + 120);
      *v34 |= 0x20u;
    }
    v35 = Render::View::GetStateValues(&v43);
    v35->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v35->mParamValues[15] = v30;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v47);
    Render::View::Draw(&v43, &v47, Render::gRenderUtilities.mMaterial, 0i64);
    Render::View::EndTarget(&v43);
    p_mSixtyFourSizeScratchTargetA += 3;
    --poly.mVertices;
  }
  while ( poly.mVertices );
  Render::gRenderUtilities.mSubmitContext = 0i64;
  poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v44);
}

// File Line: 4269
// RVA: 0x566C0
void __fastcall RenderMotionBlur(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  float mMotionBlurStrength; // xmm6_4
  char *v13; // rbx
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm3
  Illusion::StateValues *StateValues; // rax
  Illusion::StateArgs *StateArgs; // rsi
  unsigned int v19; // r9d
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  Illusion::Target *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 b; // [rsp+90h] [rbp-70h] BYREF
  __int64 v27; // [rsp+D0h] [rbp-30h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qMatrix44 d; // [rsp+120h] [rbp+20h] BYREF
  RenderQueueLayer v30; // [rsp+160h] [rbp+60h] BYREF
  Render::View v31; // [rsp+240h] [rbp+140h] BYREF
  LayerSubmitContext ptr; // [rsp+3D0h] [rbp+2D0h] BYREF
  Render::Poly poly; // [rsp+1080h] [rbp+F80h] BYREF

  v27 = -2i64;
  if ( (_S21 & 1) == 0 )
    _S21 |= 1u;
  b = msPreviousTransform;
  v8 = UFG::qMatrix44::operator*(
         &render_context->mMainViewSettings.mWorldView,
         &result,
         &render_context->mMainViewSettings.mProjection);
  v9 = v8->v1;
  v10 = v8->v2;
  v11 = v8->v3;
  msPreviousTransform.v0 = v8->v0;
  msPreviousTransform.v1 = v9;
  msPreviousTransform.v2 = v10;
  msPreviousTransform.v3 = v11;
  if ( render_context->mRenderFeatures.mWorld
    && render_context->mRenderFeatures.mMotionBlur
    && render_context->mMotionBlurStrength > 0.050000001
    && render_context->mRenderSettingsForFrame.mMotionBlur )
  {
    RenderQueueLayer::RenderQueueLayer(&v30);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v30.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v30;
    ptr.mQueueMode = QM_Single;
    Render::View::View(&v31, &render_context->mMainViewSettings, &ptr);
    Render::View::BeginTarget(&v31, *scratch_target, "MotionBlur", 0, 0, 0i64, 1, 0, 0, 0);
    UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
    UFG::qMatrix44::operator*(&d, &result, &b);
    mMotionBlurStrength = render_context->mMotionBlurStrength;
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
    v14 = result.v1;
    v15 = result.v2;
    v16 = result.v3;
    *(UFG::qVector4 *)v13 = result.v0;
    *((UFG::qVector4 *)v13 + 1) = v14;
    *((UFG::qVector4 *)v13 + 2) = v15;
    *((UFG::qVector4 *)v13 + 3) = v16;
    *((float *)v13 + 16) = mMotionBlurStrength;
    *(_QWORD *)(v13 + 68) = 1065353216i64;
    *((_DWORD *)v13 + 19) = 0;
    StateValues = Render::View::GetStateValues(&v31);
    StateValues->mSetValueMask.mFlags[0] |= 0x4000000000000ui64;
    StateValues->mParamValues[50] = v13;
    Render::cbExternalViewTransformState::cbExternalViewTransformState(
      &arg,
      &v31.mSettings->mWorldView,
      &v31.mSettings->mProjection);
    StateArgs = Render::View::GetStateArgs(&v31);
    v19 = 417247388;
    if ( render_context->mRenderSettingsForFrame.mMotionBlur != MOTION_BLUR_HIGH )
      v19 = 1194509180;
    Illusion::Material::UpdateParam(render_context->mCameraBlurMaterial, 0, 0x8B5561A1, v19);
    Illusion::Material::UpdateParam(
      render_context->mCameraBlurMaterial,
      1,
      0x8B43FABF,
      (*curr_target)->mTargetTexture[0]->mNode.mUID);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v31, &poly, render_context->mCameraBlurMaterial, 0i64);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&v31);
    v22 = *curr_target;
    *curr_target = *scratch_target;
    *scratch_target = v22;
    v23 = arg.mPrev;
    v24 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v24->mPrev = v23;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v30);
  }
}

// File Line: 4364
// RVA: 0x554E0
void __fastcall RenderFX(
        UFG::RenderContext *render_context,
        Illusion::Target *current_target,
        Illusion::Target *distortion_target,
        Render::View *view)
{
  Illusion::SubmitContext *mSubmitContext; // rbp
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::EnvCubeMap *mEnvCubeMap; // rax
  UFG::qResourceData *mData; // rbx
  Illusion::StateValues *v12; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v15; // rbx
  Illusion::StateValues *v16; // rax
  Illusion::Texture *mDepthTextureCopy; // rcx
  Illusion::Texture *v18; // rax
  Illusion::Target *mHeightmapTarget; // rax
  Illusion::Texture *mDepthTexture; // rcx
  __int64 v21[4]; // [rsp+30h] [rbp-88h] BYREF
  int v22; // [rsp+50h] [rbp-68h]
  Render::FXManagerAuxBuffers auxBuffers; // [rsp+58h] [rbp-60h] BYREF

  if ( gRenderFX )
  {
    mSubmitContext = view->mSubmitContext;
    v21[0] = 0i64;
    v21[1] = 0i64;
    v22 = 0;
    v21[3] = -1i64;
    v21[2] = -1i64;
    mSubmitContext->mShaderSelector = (Illusion::ShaderSelector *)v21;
    LODWORD(mSubmitContext[1].mStateValues.mParamValues[1]) = 1;
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    mEnvCubeMap = render_context->mEnvCubeMap;
    if ( mEnvCubeMap )
      mData = &mEnvCubeMap->mTarget->mTargetTexture[0]->UFG::qResourceData;
    else
      mData = gDefaultBlackTexture.mData;
    v12 = Render::View::GetStateValues(view);
    v12->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
    v12->mParamValues[40] = mData;
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v15 = mSimTime_Temp;
    *((float *)v15 + 1) = mSimTimeDelta;
    v16 = Render::View::GetStateValues(view);
    v16->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v16->mParamValues[13] = v15;
    mDepthTextureCopy = render_context->mGBufferTarget->mDepthTextureCopy;
    v18 = distortion_target->mTargetTexture[0];
    auxBuffers.texShadowAtlas = 0i64;
    auxBuffers.scrDiffuse = v18;
    mHeightmapTarget = render_context->mHeightmapTarget;
    auxBuffers.scrDepth = mDepthTextureCopy;
    mDepthTexture = mHeightmapTarget->mDepthTexture;
    auxBuffers.texHeightmapShadow = render_context->mHeightmapShadowTextureAlias;
    auxBuffers.texHeightmap = mDepthTexture;
    Render::FXManager::Render(
      &Render::gFXManager,
      view,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_HIGH_QUALITY,
      &auxBuffers);
    mSubmitContext->mShaderSelector = 0i64;
    LODWORD(mSubmitContext[1].mStateValues.mParamValues[1]) = 0;
  }
}

// File Line: 4400
// RVA: 0x53230
void __fastcall RenderAntiAlias(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Render::RenderPassCollector *render_pass_collector,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  Illusion::StateArgs *StateArgs; // r14
  Illusion::Target **v10; // r12
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // rsi
  unsigned __int16 Param; // ax
  Illusion::Material *mAntiAliasMaterial; // rbx
  unsigned int v15; // r8d
  _WORD *v16; // rax
  Illusion::Material *v17; // rbx
  _WORD *v18; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v20; // rbx
  unsigned int *p_mNumParams; // rcx
  _WORD *mOffset; // rax
  _WORD *v23; // rax
  unsigned int v24; // r8d
  Illusion::Material *v25; // rbx
  _WORD *v26; // rax
  unsigned int v27; // r8d
  Illusion::Material *v28; // rbx
  _WORD *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v32; // rdx
  Illusion::Target *v33; // rcx
  Illusion::Texture *v34; // rbx
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rax
  unsigned __int64 *v38; // rdx
  Illusion::Target *mHalfSizeScratchTargetA; // r13
  Render::ViewSettings *Identity; // rax
  Illusion::Material *mDistortionMaterial; // rbx
  _WORD *v42; // rax
  unsigned int v43; // r8d
  Illusion::Material *v44; // rbx
  _WORD *v45; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v46; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v47; // rax
  Illusion::Target *v48; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v49; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+88h] [rbp-78h]
  Render::Poly v53; // [rsp+90h] [rbp-70h] BYREF
  __int64 v54; // [rsp+98h] [rbp-68h]
  Render::View view; // [rsp+A0h] [rbp-60h] BYREF
  RenderQueueLayer v56; // [rsp+230h] [rbp+130h] BYREF
  RenderQueueLayer v57; // [rsp+310h] [rbp+210h] BYREF
  Render::View v58; // [rsp+3F0h] [rbp+2F0h] BYREF
  CompositeSubmitContext v59; // [rsp+580h] [rbp+480h] BYREF
  LayerSubmitContext ptr; // [rsp+1210h] [rbp+1110h] BYREF
  Render::Poly poly; // [rsp+1EC0h] [rbp+1DC0h] BYREF

  v54 = -2i64;
  if ( render_context->mAntiAliasState != AASTATE_SEPERATE_PASS )
    return;
  RenderQueueLayer::RenderQueueLayer(&v57);
  CompositeSubmitContext::CompositeSubmitContext(&v59);
  v57.mSerializationList = serialization_list;
  v59.mOverrideMode = 0;
  v59.mRenderQueueProvider = &v57;
  v59.mQueueMode = QM_Single;
  Render::View::View(&view, &render_context->mMainViewSettings, &v59);
  StateArgs = Render::View::GetStateArgs(&view);
  v10 = scratch_target;
  Render::View::BeginTarget(&view, *scratch_target, "AntiAlias", 0, 0, 0i64, 1, 1, 0, 0);
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
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  mAntiAliasMaterial = render_context->mAntiAliasMaterial;
  if ( render_context->mRenderSettingsForFrame.mAAQuality == AA_QUALITY_NORMAL )
  {
    if ( LODWORD(mAntiAliasMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 1650486829 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mAntiAliasMaterial[1].mNode.mChild[1],
        mAntiAliasMaterial[1].mTypeUID,
        0x62606E2Du);
      mOffset = (_WORD *)mAntiAliasMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        mOffset = (_WORD *)((char *)mOffset + (_QWORD)mAntiAliasMaterial + 120);
      *mOffset |= 0x20u;
    }
    v20 = render_context->mAntiAliasMaterial;
    if ( *(_DWORD *)&v20[2].mDebugName[28] == 1660426324 )
      goto LABEL_28;
    p_mNumParams = (unsigned int *)&v20[2].mDebugName[4];
    mUID = 1660426324;
    goto LABEL_25;
  }
  if ( render_context->mRenderSettingsForFrame.mDeviceType == DEVICE_TYPE_LEGACY_ATI )
  {
    if ( LODWORD(mAntiAliasMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -1507565517 )
    {
      v15 = -1507565517;
LABEL_10:
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mAntiAliasMaterial[1].mNode.mChild[1],
        mAntiAliasMaterial[1].mTypeUID,
        v15);
      v16 = (_WORD *)mAntiAliasMaterial->mMaterialUser.mOffset;
      if ( v16 )
        v16 = (_WORD *)((char *)v16 + (_QWORD)mAntiAliasMaterial + 120);
      *v16 |= 0x20u;
    }
  }
  else if ( LODWORD(mAntiAliasMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 1165395818 )
  {
    v15 = 1165395818;
    goto LABEL_10;
  }
  v17 = render_context->mAntiAliasMaterial;
  if ( *(_DWORD *)&v17[2].mDebugName[28] != 304454940 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v17[2].mDebugName[4],
      *((_DWORD *)&v17[2].UFG::qResourceData + 22),
      0x12259D1Cu);
    v18 = (_WORD *)v17->mMaterialUser.mOffset;
    if ( v18 )
      v18 = (_WORD *)((char *)v18 + (_QWORD)v17 + 120);
    *v18 |= 0x20u;
  }
  mUID = render_context->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  v20 = render_context->mAntiAliasMaterial;
  if ( LODWORD(v20[3].mNode.mChild[0]) == mUID )
    goto LABEL_28;
  p_mNumParams = &v20[2].mNumParams;
LABEL_25:
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)p_mNumParams, p_mNumParams[8], mUID);
  v23 = (_WORD *)v20->mMaterialUser.mOffset;
  if ( v23 )
    v23 = (_WORD *)((char *)v23 + (_QWORD)v20 + 120);
  *v23 |= 0x20u;
LABEL_28:
  v24 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
  v25 = render_context->mAntiAliasMaterial;
  if ( LODWORD(v25[1].mStateBlockMask.mFlags[0]) != v24 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v25[1].mDebugName[20], v25[1].mStateBlockMask.mFlags[1], v24);
    v26 = (_WORD *)v25->mMaterialUser.mOffset;
    if ( v26 )
      v26 = (_WORD *)((char *)v26 + (_QWORD)v25 + 120);
    *v26 |= 0x20u;
  }
  if ( Render::DepthOfField::IsEnabled(&Render::gDepthOfField) )
    v27 = render_context->mHalfSizeScratchTargetC->mTargetTexture[0]->mNode.mUID;
  else
    v27 = 0x1C63FB41;
  v28 = render_context->mAntiAliasMaterial;
  if ( *(_DWORD *)&v28[3].mDebugName[12] != v27 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v28[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
      *(_DWORD *)&v28[3].mDebugName[20],
      v27);
    v29 = (_WORD *)v28->mMaterialUser.mOffset;
    if ( v29 )
      v29 = (_WORD *)((char *)v29 + (_QWORD)v28 + 120);
    *v29 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&view, &poly, render_context->mAntiAliasMaterial, 0i64);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
  {
    v32 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v32 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  Render::View::EndTarget(&view);
  v33 = *curr_target;
  *curr_target = *v10;
  *v10 = v33;
  Render::gRenderUtilities.mSubmitContext = &v59;
  Render::RenderUtilities::Blit(&Render::gRenderUtilities, *curr_target, *v10, 0x3141335Cu, "<Blit>", 0, 1, 0i64);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  Render::View::BeginTarget(&view, *v10, "HairBlur", 0, 0, 0i64, 1, 1, 0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  v34 = (*curr_target)->mTargetTexture[0];
  StateValues = Render::View::GetStateValues(&view);
  StateValues->mSetValueMask.mFlags[0] |= 0x800000ui64;
  StateValues->mParamValues[23] = v34;
  Render::RenderPassSystem::DrawRenderPass(render_pass_collector, &view, FeatherPunchThru);
  UFG::RenderStageHairSkin::RenderHairBlur(
    UFG::RenderWorld::msStageHairSkin,
    render_context,
    &view,
    (*curr_target)->mTargetTexture[0]);
  v36 = arg.mPrev;
  v37 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v37->mPrev = v36;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
  {
    v38 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v38 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  Render::View::EndTarget(&view);
  mHalfSizeScratchTargetA = render_context->mHalfSizeScratchTargetA;
  RenderQueueLayer::RenderQueueLayer(&v56);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v56.mSerializationList = v59.mRenderQueueProvider->mSerializationList;
  ptr.mRenderQueueProvider = &v56;
  ptr.mQueueMode = QM_Single;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v53);
  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v58, Identity, &ptr);
  Render::View::BeginTarget(&v58, mHalfSizeScratchTargetA, "distortion blit", 0, 0, 0i64, 1, 0, 0, 0);
  mDistortionMaterial = render_context->mDistortionMaterial;
  if ( LODWORD(mDistortionMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 826356572 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mDistortionMaterial[1].mNode.mChild[1],
      mDistortionMaterial[1].mTypeUID,
      0x3141335Cu);
    v42 = (_WORD *)mDistortionMaterial->mMaterialUser.mOffset;
    if ( v42 )
      v42 = (_WORD *)((char *)v42 + (_QWORD)mDistortionMaterial + 120);
    *v42 |= 0x20u;
  }
  v43 = (*v10)->mTargetTexture[0]->mNode.mUID;
  v44 = render_context->mDistortionMaterial;
  if ( LODWORD(v44[1].mStateBlockMask.mFlags[0]) != v43 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v44[1].mDebugName[20], v44[1].mStateBlockMask.mFlags[1], v43);
    v45 = (_WORD *)v44->mMaterialUser.mOffset;
    if ( v45 )
      v45 = (_WORD *)((char *)v45 + (_QWORD)v44 + 120);
    *v45 |= 0x20u;
  }
  Render::View::Draw(&v58, &v53, render_context->mDistortionMaterial, 0i64);
  Render::View::EndTarget(&v58);
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v56);
  Render::View::BeginTarget(&view, *v10, "AntiAliasFX", 0, 0, 0i64, 1, 1, 0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  SetRainState(&view);
  RenderFX(render_context, *curr_target, mHalfSizeScratchTargetA, &view);
  v46 = arg.mPrev;
  v47 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v47->mPrev = v46;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v48 = *curr_target;
  *curr_target = *v10;
  *v10 = v48;
  v49 = arg.mPrev;
  v50 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v50->mPrev = v49;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  p_mStateArgs = &v59.mStateArgs;
  `eh vector destructor iterator(
    v59.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v57);
}

// File Line: 4530
// RVA: 0x49D30
void __fastcall CompositeFinalAndDrawUI(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Illusion::Target *curr_target)
{
  char *vp_scissor; // r15
  Illusion::Target *BackBufferTarget; // rax
  Illusion::Target *v8; // rbx
  char *v9; // rsi
  UFG::TimeOfDayManager *Instance; // rbx
  float mBloomNearThreshold; // xmm6_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  Illusion::StateValues *StateValues; // rax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *v17; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v20; // rbx
  Illusion::StateValues *v21; // rax
  Illusion::Material *mCompositeFinalMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v24; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v26; // rbx
  __int64 v27; // rax
  _WORD *v28; // rax
  Illusion::Target *v29; // rax
  char *v30; // rax
  char *v31; // r9
  Illusion::Target *v32; // rbx
  char *v33; // rax
  Render::RenderCallbacks *RenderCallbacks; // rax
  Render::View view; // [rsp+60h] [rbp-68h] BYREF
  __int64 v36; // [rsp+1F0h] [rbp+128h] BYREF
  CompositeSubmitContext ptr; // [rsp+298h] [rbp+1D0h] BYREF
  bool is_full_screen; // [rsp+F98h] [rbp+ED0h] BYREF
  Render::Poly poly; // [rsp+FA0h] [rbp+ED8h] BYREF
  char *v40; // [rsp+FA8h] [rbp+EE0h]

  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v36);
  CompositeSubmitContext::CompositeSubmitContext(&ptr);
  *(_QWORD *)&view.mViewWorld.v1.z = serialization_list;
  ptr.mOverrideMode = 0;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&view.mViewWorld.v1.z;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
  vp_scissor = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  Render::GetBackBufferViewportScissor((Illusion::ViewportScissorState *)vp_scissor, &is_full_screen);
  BackBufferTarget = Render::GetBackBufferTarget();
  v8 = BackBufferTarget;
  if ( !is_full_screen )
  {
    Render::View::BeginTarget(&view, BackBufferTarget, "FinalComposition", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 0xFFu, 1.0, 0);
  }
  Render::View::BeginTarget(
    &view,
    v8,
    "FinalComposition",
    0,
    0,
    (Illusion::ViewportScissorState *)vp_scissor,
    1,
    0,
    0,
    0);
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  Instance = UFG::TimeOfDayManager::GetInstance();
  mBloomNearThreshold = UFG::TimeOfDayManager::GetInstance()->mBloomNearThreshold;
  if ( mBloomNearThreshold <= Instance->mBloomFarThreshold )
    mBloomNearThreshold = Instance->mBloomFarThreshold;
  *(float *)v9 = (float)Render::DepthOfField::IsEnabled(&Render::gDepthOfField);
  v12 = mBloomNearThreshold - 0.0040000002;
  v13 = 0.0;
  if ( v12 >= 0.0 )
    v13 = v12;
  v14 = (v13 * 6.2 + 0.5) * v13 / ((v13 * 6.2 + 1.7) * v13 + 0.06);
  *((float *)v9 + 1) = v14;
  *((float *)v9 + 2) = (float)(Render::DisplayCalibration::msBrightness - 1.0)
                     * Render::DisplayCalibration::BlackLevel1.r;
  if ( g_Fullscreen )
    *((_DWORD *)v9 + 3) = 1065353216;
  else
    *((float *)v9 + 3) = Render::DisplayCalibration::msGamma;
  StateValues = Render::View::GetStateValues(&view);
  StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
  StateValues->mParamValues[15] = v9;
  mEnvState = render_context->mEnvState;
  v17 = Render::View::GetStateValues(&view);
  v17->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v17->mParamValues[55] = mEnvState;
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v20 = mSimTime_Temp;
  *((float *)v20 + 1) = mSimTimeDelta;
  v21 = Render::View::GetStateValues(&view);
  v21->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v21->mParamValues[13] = v20;
  mCompositeFinalMaterial = render_context->mCompositeFinalMaterial;
  if ( LODWORD(mCompositeFinalMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -1067196633 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mCompositeFinalMaterial[1].mNode.mChild[1],
      mCompositeFinalMaterial[1].mTypeUID,
      0xC063DF27);
    mOffset = mCompositeFinalMaterial->mMaterialUser.mOffset;
    if ( mOffset )
      v24 = (_WORD *)((char *)&mCompositeFinalMaterial->mMaterialUser + mOffset);
    else
      v24 = 0i64;
    *v24 |= 0x20u;
  }
  mUID = curr_target->mTargetTexture[0]->mNode.mUID;
  v26 = render_context->mCompositeFinalMaterial;
  if ( LODWORD(v26[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v26[1].mDebugName[20], v26[1].mStateBlockMask.mFlags[1], mUID);
    v27 = v26->mMaterialUser.mOffset;
    if ( v27 )
      v28 = (_WORD *)((char *)&v26->mMaterialUser + v27);
    else
      v28 = 0i64;
    *v28 |= 0x20u;
  }
  if ( render_context->mRenderFeatures.mWorld )
  {
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&view, &poly, render_context->mCompositeFinalMaterial, 0i64);
    Render::ScreenParticleEmitterManager::Render(
      &Render::gScreenParticleEmitterManager,
      &view,
      curr_target->mTargetTexture[0]->mNode.mUID,
      render_context->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID);
  }
  else
  {
    Render::View::Clear(&view, &UFG::qColour::Zero, 0xFFu, 1.0, 0);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&view, &poly, UFG::RenderWorld::msClearUITextureId, 0i64, 0, 0);
  }
  if ( g_enable3D && g_Fullscreen )
  {
    Render::View::EndTarget(&view);
    v29 = Render::Get3DTarget(gCurrentEye);
    Render::View::BeginTarget(
      &view,
      v29,
      "FinalPresent",
      0,
      0,
      (Illusion::ViewportScissorState *)vp_scissor,
      1,
      0,
      0,
      0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 1u, 1.0, 0);
    v30 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    v31 = v30;
    poly.mVertices = (Render::vDynamic *)v30;
    if ( v30 )
    {
      *(_QWORD *)v30 = gCurrentEye;
      *((_QWORD *)v30 + 1) = Render::ConvergeFunction;
    }
    else
    {
      v31 = 0i64;
    }
    LayerSubmitContext::AddRenderCommand(&ptr, 17, 0, v31);
  }
  UFG::MovieHandler::RenderFullScreen(&UFG::TheMovieHandler, &view, 0);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&view.mViewWorld.v1.z);
  if ( UFG::UIScreenManager::s_instance )
  {
    UFG::UIScreenManager::s_instance->m_renderUI = render_context->mRenderFeatures.mUI;
    UFG::UIScreenManagerBase::customPreRender(UFG::UIScreenManager::s_instance, &view);
    v32 = Render::GetBackBufferTarget();
    v33 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    poly.mVertices = (Render::vDynamic *)v33;
    v40 = v33;
    if ( v33 )
    {
      *(_QWORD *)v33 = v32;
      *((_QWORD *)v33 + 1) = RenderScaleformCallback;
    }
    else
    {
      v33 = 0i64;
    }
    LayerSubmitContext::AddRenderCommand(&ptr, 17, 0, v33);
    LayerSubmitContext::AddRenderCommand(&ptr, 27, 0, 0i64);
    UFG::UIScreenManagerBase::customPostRender(UFG::UIScreenManager::s_instance, &view);
    UFG::UIScreenManagerBase::advance(UFG::UIScreenManager::s_instance, UFG::Metrics::msRealTimeDelta_Accurate);
  }
  UFG::MovieHandler::RenderFullScreen(&UFG::TheMovieHandler, &view, 1);
  Render::UpdateRenderLoadScreen(&view, UFG::Metrics::msRealTimeDelta_Accurate);
  if ( gDrawDebugContext )
  {
    RenderDebugOverlay(render_context, &view);
    if ( Render::GetRenderCallbacks()->mRenderSimDebugOverlay )
    {
      RenderCallbacks = Render::GetRenderCallbacks();
      RenderCallbacks->mRenderSimDebugOverlay(render_context, &view);
    }
    Render::DebugDrawManager::FlushContexts(Render::DebugDrawManager::mInstance, &view, 2u, 0);
  }
  else
  {
    Render::DebugDrawManager::ClearContexts(Render::DebugDrawManager::mInstance, 0, 0);
  }
  Render::View::EndTarget(&view);
  poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)&view.mViewWorld.v1.z);
}

// File Line: 4716
// RVA: 0x53A30
void __fastcall RenderBackBufferToPresentBufferAndApplyBlackLevel(
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  Illusion::Target *BackBufferTarget; // rbp
  Illusion::Target *PresentBufferTarget; // rbx
  _WORD *v4; // rsi
  Render::ViewSettings *Identity; // rax
  Illusion::Material *v6; // rdi
  char *v7; // rbx
  __int64 mOffset; // rax
  _WORD *v9; // rax
  unsigned int mUID; // r8d
  __int64 v11; // rax
  Illusion::StateValues *StateValues; // rax
  RenderQueueLayer v13; // [rsp+60h] [rbp-F18h] BYREF
  Render::View v14; // [rsp+140h] [rbp-E38h] BYREF
  CompositeSubmitContext ptr; // [rsp+2D0h] [rbp-CA8h] BYREF
  Render::Poly poly; // [rsp+F88h] [rbp+10h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+F90h] [rbp+18h]

  if ( !g_Fullscreen )
  {
    BackBufferTarget = Render::GetBackBufferTarget();
    PresentBufferTarget = Render::GetPresentBufferTarget();
    RenderQueueLayer::RenderQueueLayer(&v13);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v13.mSerializationList = serialization_list;
    v4 = 0i64;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v13;
    ptr.mQueueMode = QM_Single;
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v14, Identity, &ptr);
    v6 = sPresentMaterial;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v14, PresentBufferTarget, "PresentBuffer", 0, 0, 0i64, 1, 0, 0, 0);
    v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    *(float *)v7 = (float)(Render::DisplayCalibration::msBrightness - 1.0) * Render::DisplayCalibration::BlackLevel1.r;
    if ( LODWORD(v6[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 2032804782 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6[1].mNode.mChild[1], v6[1].mTypeUID, 0x792A23AEu);
      mOffset = v6->mMaterialUser.mOffset;
      if ( mOffset )
        v9 = (_WORD *)((char *)&v6->mMaterialUser + mOffset);
      else
        v9 = 0i64;
      *v9 |= 0x20u;
    }
    mUID = BackBufferTarget->mTargetTexture[0]->mNode.mUID;
    if ( *(_DWORD *)&v6[2].mDebugName[28] != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v6[2].mDebugName[4],
        *((_DWORD *)&v6[2].UFG::qResourceData + 22),
        mUID);
      v11 = v6->mMaterialUser.mOffset;
      if ( v11 )
        v4 = (_WORD *)((char *)&v6->mMaterialUser + v11);
      *v4 |= 0x20u;
    }
    StateValues = Render::View::GetStateValues(&v14);
    StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
    StateValues->mParamValues[15] = v7;
    Render::View::Draw(&v14, &poly, v6, 0i64);
    Render::View::EndTarget(&v14);
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v13);
  }
}

// File Line: 4792
// RVA: 0x59750
void __fastcall RenderWorldDeferred(float fTime, UFG::RenderContext *render_context)
{
  unsigned __int64 v2; // rbp
  char *v5; // r15
  char *v6; // rbx
  Render::ViewSettings *p_mMainViewSettings; // r13
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v9; // rax
  bool IsSunShining; // si
  bool v11; // r14
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm9_4
  unsigned int v18; // eax
  float v19; // xmm3_4
  float v20; // xmm1_4
  UFG::Reflection *PlanarReflection; // rax
  int v22; // ebx
  MainViewTargetParams *MainViewTargets; // r14
  UFG::TimeOfDayManager *v24; // rax
  int mCullIndex; // ebx
  Render::SimpleDrawableComponent *p_mNext; // rcx
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *v27; // rbx
  CullManager *v28; // rax
  CullManager *v29; // rax
  UFG::qTaskGroup *mPrevCullingTask; // rbx
  UFG::qTaskGroup *v31; // rax
  SceneryTaskRenderQueueResults *v32; // rax
  UFG::ShadowRenderQueueTaskResults *v33; // rax
  int v34; // edx
  int v35; // r8d
  bool v36; // al
  char *v37; // rax
  UFG::qTaskGroup *v38; // rbx
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qTask *p_mEndTask; // rbx
  UFG::qTaskGroup *v42; // rax
  CullManager *v43; // rax
  __int64 v44; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v46; // rsi
  unsigned int v47; // r14d
  __int64 v48; // rdx
  bool mDrawEnabled; // r8
  UFG::qSNode<CullResultBucket,CullResultBucket> *v50; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v51; // rsi
  unsigned int v52; // r14d
  UFG::CompositeDrawableComponent *mNext; // r15
  UFG::SimObject *m_pSimObject; // rax
  UFG::ICompositeLook *mCompositeLook; // rcx
  __int64 v56; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v57; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v58; // rsi
  unsigned int v59; // r14d
  UFG::CompositeDrawableComponent *v60; // r15
  UFG::SimObject *v61; // rax
  UFG::ICompositeLook *v62; // rcx
  UFG::qTaskGroup *v63; // rax
  unsigned __int64 Ticks; // r13
  unsigned __int64 v65; // r15
  MainViewTargetParams *v66; // r14
  char *v67; // rax
  UFG::qTaskGroup *v68; // rsi
  _QWORD *v69; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v70; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v71; // rax
  char *v72; // rax
  UFG::qTaskGroup *v73; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v74; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v75; // rax
  char *v76; // rax
  UFG::qTaskGroup *v77; // r14
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v78; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v79; // rax
  unsigned __int64 v80; // r12
  unsigned int v81; // esi
  unsigned int *v82; // r15
  Render::Light *v83; // r9
  unsigned __int64 v84; // rsi
  float TickTime; // xmm6_4
  Illusion::Target *mDynamicRangeTarget; // rcx
  float z; // xmm1_4
  float v88; // xmm6_4
  Illusion::Target *mAAResultTarget; // rax
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v90; // rsi
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v91; // rcx
  __int64 v92; // rbx
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v93; // rcx
  __int64 v94; // rbx
  UFG::PartCompositeBuilder *v95; // rax
  bool v96; // bl
  CullManager *v97; // rax
  UFG::qTaskGroup **v98; // rbx
  __int64 v99; // rdi
  UFG::qTaskGroup *v100; // rdx
  FlushJobQueue job_queue; // [rsp+50h] [rbp+0h] BYREF
  __int64 v102; // [rsp+1260h] [rbp+1210h]

  v102 = -2i64;
  v2 = (unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64;
  Render::GetCurrentDisplaySettings(&render_context->mRenderSettingsForFrame);
  Render::ViewMetrics::Reset(&render_context->mRenderStats);
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v5;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
  p_mMainViewSettings = &render_context->mMainViewSettings;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetEnvironmentSettings(
    Instance,
    (CB_EnvironmentSettings *)v5,
    &render_context->mMainViewSettings,
    (CB_SkySettings *)v6);
  v9 = UFG::TimeOfDayManager::GetInstance();
  IsSunShining = UFG::TimeOfDayManager::IsSunShining(v9, (CB_EnvironmentSettings *)v5);
  v11 = UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0;
  ++Render::TransparencySystem::msTransparencyFrameCounter;
  UFG::qInverseAffine(
    (UFG::qMatrix44 *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 192),
    &render_context->mMainViewSettings.mWorldView);
  v12 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v12;
  v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF4);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24) = v13;
  v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF8);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28) = v14;
  LODWORD(v15) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE8) ^ _xmm[0];
  LODWORD(v16) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE4) ^ _xmm[0];
  LODWORD(v17) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) ^ _xmm[0];
  v18 = _S22;
  if ( (_S22 & 1) == 0 )
  {
    v18 = _S22 | 1;
    _S22 |= 1u;
    v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28);
    v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24);
    v12 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  }
  if ( (v18 & 2) == 0 )
  {
    _S22 = v18 | 2;
    v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28);
    v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24);
    v12 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  }
  v19 = (float)((float)(sPrevCameraDirFront.x * v17) + (float)(v16 * sPrevCameraDirFront.y))
      + (float)(v15 * sPrevCameraDirFront.z);
  v20 = (float)((float)((float)(v12 - sPrevCameraPosition.x) * (float)(v12 - sPrevCameraPosition.x))
              + (float)((float)(v13 - sPrevCameraPosition.y) * (float)(v13 - sPrevCameraPosition.y)))
      + (float)((float)(v14 - sPrevCameraPosition.z) * (float)(v14 - sPrevCameraPosition.z));
  sPrevCameraDirFront.x = v17;
  sPrevCameraDirFront.y = v16;
  sPrevCameraDirFront.z = v15;
  sPrevCameraPosition.x = v12;
  sPrevCameraPosition.y = v13;
  sPrevCameraPosition.z = v14;
  if ( v19 < 0.69999999 || v20 > 4.0 )
    ++Render::TransparencySystem::msTransparencyFrameCounter;
  if ( Render::IsLoadScreenRendering() )
    ++Render::TransparencySystem::msTransparencyFrameCounter;
  render_context->mRenderSun = IsSunShining;
  render_context->mRenderRain = v11;
  render_context->mEnvState = (CB_EnvironmentSettings *)v5;
  render_context->mSkyState = (CB_SkySettings *)v6;
  if ( render_context->mReflectionTarget )
    PlanarReflection = FindPlanarReflection((UFG::qVector3 *)(v2 + 32));
  else
    PlanarReflection = 0i64;
  render_context->mReflection = PlanarReflection;
  render_context->mAOOpacity = 1.0;
  v22 = 0;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8) = 0;
  if ( render_context->mRenderFeatures.mWorld && UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler) )
  {
    render_context->mRenderFeatures.mWorld = 0;
    render_context->mNumCascades = 0;
  }
  `eh vector constructor iterator(
    (void *)(v2 + 256),
    0x10ui64,
    44,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  *(_OWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3E0) = 0i64;
  *(_OWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3F0) = 0i64;
  UFG::qMemSet((void *)(v2 + 960), 0, 0x20u);
  MainViewTargets = GetMainViewTargets(render_context);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58) = MainViewTargets;
  if ( gCurrentEye == STEREO_EYE_LEFT && gRenderFX )
  {
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x68) = gCulledLights;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x70) = gLights;
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x78) = gNumNearLights
                                                                                + gNumStencilLights
                                                                                + gNumFarLights;
    Render::ParticleEmitterManager::StartTasks(
      &Render::gParticleEmitterManager,
      UFG::Metrics::msInstance.mSimTime_Temp,
      UFG::Metrics::msInstance.mSimTimeDelta,
      (Render::FXManagerLights *)(v2 + 104));
    Render::LightningManager::StartSPUTasks(
      &Render::gLightningManager,
      &render_context->mMainViewSettings,
      UFG::Metrics::msInstance.mSimTime_Temp,
      UFG::Metrics::msInstance.mSimTimeDelta,
      0);
  }
  v24 = UFG::TimeOfDayManager::GetInstance();
  Render::UpdateInventoryLights(v24->m_SecondsSinceMidnight);
  if ( render_context->mRenderFeatures.mWorld && render_context->mRenderFeatures.mLights )
  {
    v22 = GatherLights(gLights, gLightGroups);
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8) = v22;
  }
  SubmitUpdateLightingTask(&render_context->mMainViewSettings, v22, gLights, gCulledLights);
  mCullIndex = render_context->mMainViewSettings.mCullIndex;
  UFG::SceneryGroupComponent::GenerateCullInfoAll(gSceneryCullLayer);
  GenerateLightCullingInfo(mCullIndex);
  p_mNext = (Render::SimpleDrawableComponent *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> **)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) )
  {
    do
    {
      v27 = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&p_mNext->mNext[-6].mNext;
      Render::SimpleDrawableComponent::UpdateCullInfo(p_mNext);
      p_mNext = (Render::SimpleDrawableComponent *)v27;
    }
    while ( v27 != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) );
  }
  v28 = CullManager::Instance();
  CullManager::BeginFrame(v28);
  if ( gCurrentEye == STEREO_EYE_LEFT )
    UFG::qBaseTreeRB::~qBaseTreeRB(&Render::Skinning::gSkinning);
  v29 = CullManager::Instance();
  CullManager::BeginView(v29, render_context->mMainViewSettings.mCullIndex, 0i64);
  mPrevCullingTask = CullManager::Instance()->mPrevCullingTask;
  v31 = UFG::RenderStageShadow::SubmitCullingTasks(UFG::RenderWorld::msStageShadow, render_context);
  if ( v31 )
    mPrevCullingTask = v31;
  v32 = SubmitRenderSceneryTasks(
          mPrevCullingTask,
          render_context,
          MainViewTargets,
          render_context->mMainViewSettings.mCullIndex);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3E0) = v32;
  if ( v32 )
    mPrevCullingTask = v32->mSceneryTaskGroup;
  v33 = UFG::RenderStageShadow::SubmitSceneryShadowTasks(
          UFG::RenderWorld::msStageShadow,
          render_context,
          mPrevCullingTask,
          gSceneryCullLayer);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3F0) = v33;
  if ( v33 )
    mPrevCullingTask = (UFG::qTaskGroup *)*((_QWORD *)&v33->mShadowsBucketIndices[3].do_not_remove
                                          + v33->mNumCascades
                                          + 3);
  if ( mPrevCullingTask )
    *(_QWORD *)v2 = &mPrevCullingTask->mEndTask;
  else
    *(_QWORD *)v2 = 0i64;
  if ( movie_update_task )
  {
    Illusion::AsyncCommandBuilder::FinalizeAsyncCommandBuilding(movie_update_task);
    movie_update_task = 0i64;
  }
  else
  {
    v36 = Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
            (hkGeometryUtils::IVertices *)movie_update_task,
            v34,
            v35);
    UFG::MovieHandler::Update(&UFG::TheMovieHandler, v36);
    UFG::MovieHandler::PostUpdate(&UFG::TheMovieHandler);
  }
  EarlyFlushSetup(
    (FlushContext *)(v2 + 256),
    (FlushJobQueue *)((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64),
    render_context->mRenderFeatures.mWorld,
    render_context->mRenderFeatures.mScenery);
  if ( gCurrentEye == STEREO_EYE_LEFT )
    UFG::RenderStageEnvMap::Render(
      UFG::RenderWorld::msStageEnvMap,
      render_context,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 256));
  v37 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v38 = (UFG::qTaskGroup *)v37;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = v37;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v37;
  if ( v37 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v37, "PlanarReflectionSkinning");
  mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
  mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  mPrev->mNext = v38;
  v38->mPrev = mPrev;
  v38->mNext = &mSingleFrameTaskGroups->mNode;
  mSingleFrameTaskGroups->mNode.mPrev = v38;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v38);
  RenderPlanarReflectionMap(render_context, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 272));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3C0) = v38;
  if ( !v38->mNumTasks || v38->mStartTask.mSyncVars.v.mState )
  {
    p_mEndTask = *(UFG::qTask **)v2;
  }
  else
  {
    if ( *(_QWORD *)v2 )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v38, *(UFG::qTask **)v2);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v38);
    p_mEndTask = &v38->mEndTask;
    *(_QWORD *)v2 = p_mEndTask;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  v42 = Illusion::RenderQueueSystem::FlushRenderPhase(
          *(Illusion::RenderPhase **)(*(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x410) + 8i64),
          5u,
          0x7C00u,
          p_mEndTask,
          0);
  if ( v42 )
  {
    p_mEndTask = &v42->mEndTask;
    *(_QWORD *)v2 = &v42->mEndTask;
  }
  if ( gCurrentEye == STEREO_EYE_LEFT )
  {
    UFG::Water::UpdateRippleMap(
      render_context,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 288));
    if ( gCurrentEye == STEREO_EYE_LEFT )
      RenderMoviesOffscreen((UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 320));
  }
  v43 = CullManager::Instance();
  CullManager::EndView(v43, (unsigned int)render_context->mMainViewSettings.mCullIndex);
  Render::RenderPassCollector::RenderPassCollector((Render::RenderPassCollector *)(v2 + 1072));
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x48) = 0;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x4C) = 1;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = 2;
  v44 = render_context->mMainViewSettings.mCullIndex;
  if ( (int)v44 >= 0 && (int)v44 <= 16 && gSimpleDrawableCullLayer.mDrawEnabled )
    mHead = gSimpleDrawableCullLayer.mCullResultBuckets[v44].mHead;
  else
    mHead = 0i64;
  v46 = mHead;
  v47 = 0;
  if ( mHead )
  {
    do
    {
      Render::RenderPassSystem::RegisterComponent(
        (Render::RenderPassCollector *)(v2 + 1072),
        (Render::SimpleDrawableComponent *)v46[v47 + 3].mNext,
        *((float *)&v46[17].mNext + v47),
        *((float *)&v46[20].mNext + v47 + 1),
        (Illusion::eRenderPass::Enum *)(v2 + 72),
        3);
      if ( ++v47 == LODWORD(v46[1].mNext) )
      {
        v46 = v46->mNext;
        v47 = 0;
      }
    }
    while ( v46 );
    p_mMainViewSettings = &render_context->mMainViewSettings;
  }
  v48 = render_context->mMainViewSettings.mCullIndex;
  mDrawEnabled = gCompositeDrawableCullLayer.mDrawEnabled;
  if ( (int)v48 >= 0 && (int)v48 <= 16 && gCompositeDrawableCullLayer.mDrawEnabled )
    v50 = gCompositeDrawableCullLayer.mCullResultBuckets[v48].mHead;
  else
    v50 = 0i64;
  v51 = v50;
  v52 = 0;
  if ( v50 )
  {
    do
    {
      mNext = (UFG::CompositeDrawableComponent *)v51[v52 + 3].mNext;
      m_pSimObject = mNext->m_pSimObject;
      if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x2000) == 0 )
      {
        Render::RenderPassSystem::RegisterComponent(
          (Render::RenderPassCollector *)(v2 + 1072),
          mNext,
          *((float *)&v51[17].mNext + v52),
          *((float *)&v51[20].mNext + v52 + 1),
          (Illusion::eRenderPass::Enum *)(v2 + 72),
          3);
        mCompositeLook = mNext->mCompositeLook;
        if ( mCompositeLook )
          mCompositeLook->vfptr->OnUpdateCullResults(mCompositeLook, mNext, p_mMainViewSettings);
      }
      if ( ++v52 == LODWORD(v51[1].mNext) )
      {
        v51 = v51->mNext;
        v52 = 0;
      }
    }
    while ( v51 );
    mDrawEnabled = gCompositeDrawableCullLayer.mDrawEnabled;
  }
  v56 = render_context->mMainViewSettings.mCullIndex;
  if ( (int)v56 >= 0 && (int)v56 <= 16 && mDrawEnabled )
    v57 = gCompositeDrawableCullLayer.mCullResultBuckets[v56].mHead;
  else
    v57 = 0i64;
  v58 = v57;
  v59 = 0;
  while ( v58 )
  {
    v60 = (UFG::CompositeDrawableComponent *)v58[v59 + 3].mNext;
    v61 = v60->m_pSimObject;
    if ( v61 )
    {
      if ( (v61->m_Flags & 0x2000) != 0 )
      {
        Render::RenderPassSystem::RegisterComponent(
          (Render::RenderPassCollector *)(v2 + 1072),
          v60,
          *((float *)&v58[17].mNext + v59),
          *((float *)&v58[20].mNext + v59 + 1),
          (Illusion::eRenderPass::Enum *)(v2 + 72),
          3);
        v62 = v60->mCompositeLook;
        if ( v62 )
          v62->vfptr->OnUpdateCullResults(v62, v60, p_mMainViewSettings);
      }
    }
    if ( ++v59 == LODWORD(v58[1].mNext) )
    {
      v58 = v58->mNext;
      v59 = 0;
    }
  }
  GatherShadowedSpotLights(render_context);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x400) = 0i64;
  if ( gSpotShadowCount )
  {
    UFG::RenderStageSpotShadow::RegisterViews(UFG::RenderWorld::msStageSpotShadow, render_context);
    v63 = UFG::RenderStageSpotShadow::SubmitCullingTasks(UFG::RenderWorld::msStageSpotShadow, render_context);
    if ( v63 )
      *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x400) = UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks(
                                                                                       UFG::RenderWorld::msStageSpotShadow,
                                                                                       render_context,
                                                                                       v63,
                                                                                       gSceneryCullLayer);
  }
  Ticks = UFG::qGetTicks();
  SubmitDrawLightingTask(render_context);
  v65 = UFG::qGetTicks();
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = v65;
  if ( gCurrentEye == STEREO_EYE_LEFT )
  {
    if ( gEnableClouds && render_context->mRenderFeatures.mWorld )
      Render::SkyMarshall::SubmitCloudTask(
        &Render::SkyMarshall::gSkyMarshall,
        render_context,
        *(CB_EnvironmentSettings **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10));
    if ( gRenderFX )
    {
      Render::ParticleEmitterManager::SyncTasks(&Render::gParticleEmitterManager);
      Render::LightningManager::SyncTasks(&Render::gLightningManager);
      Render::FXManager::ResumeAndSuspendBasedOnCullResults(
        &Render::gFXManager,
        (UFG::qVector3 *)(v2 + 32),
        UFG::Metrics::msInstance.mSimTime_Temp);
    }
  }
  v66 = *(MainViewTargetParams **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58);
  EarlyFlushToIllusionTrigger((FlushContext *)(v2 + 256), v66);
  v67 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v68 = (UFG::qTaskGroup *)v67;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v67;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v67;
  if ( v67 )
  {
    *(_QWORD *)v67 = v67;
    *((_QWORD *)v67 + 1) = v67;
    v69 = v67 + 16;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v69;
    *v69 = v69;
    v69[1] = v69;
    v68->mNumTasks = 0;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = &v68->mStartTask;
    v68->mStartTask.mPrev = &v68->mStartTask;
    v68->mStartTask.mNext = &v68->mStartTask;
    v68->mStartTask.mPrev = &v68->mStartTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    v68->mStartTask.mNext = &v68->mStartTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    v68->mStartTask.mTaskGroup = 0i64;
    v68->mStartTask.mFlags = 2;
    v68->mStartTask.mSyncVars.i64 = 0i64;
    v68->mStartTask.mSyncVars.v.mDependents = 0i64;
    v68->mStartTask.mFunctionDeclData = 0i64;
    v68->mStartTask.mSPUElfAddress = 0i64;
    v68->mStartTask.mSPUFunction = 0i64;
    v68->mStartTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64;
    v68->mStartTask.mParam0 = 0i64;
    v68->mStartTask.mParam1 = 0i64;
    v68->mStartTask.mParam2 = 0i64;
    v68->mStartTask.mParam3 = 0i64;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = &v68->mEndTask;
    v68->mEndTask.mPrev = &v68->mEndTask;
    v68->mEndTask.mNext = &v68->mEndTask;
    v68->mEndTask.mPrev = &v68->mEndTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    v68->mEndTask.mNext = &v68->mEndTask.UFG::qNode<UFG::qTask,UFG::TaskPlat>;
    v68->mEndTask.mTaskGroup = 0i64;
    v68->mEndTask.mFlags = 2;
    v68->mEndTask.mSyncVars.i64 = 0i64;
    v68->mEndTask.mSyncVars.v.mDependents = 0i64;
    v68->mEndTask.mFunctionDeclData = 0i64;
    v68->mEndTask.mSPUElfAddress = 0i64;
    v68->mEndTask.mSPUFunction = 0i64;
    v68->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
    v68->mEndTask.mParam0 = 0i64;
    v68->mEndTask.mParam1 = 0i64;
    v68->mEndTask.mParam2 = 0i64;
    v68->mEndTask.mParam3 = 0i64;
    v68->mStartTask.mTaskGroup = v68;
    v68->mEndTask.mTaskGroup = v68;
  }
  v70 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v71 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v71->mNext = v68;
  v68->mPrev = v71;
  v68->mNext = &v70->mNode;
  v70->mNode.mPrev = v68;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v68);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3E8) = RenderSimMain(
                                                                                   render_context,
                                                                                   v66,
                                                                                   (Render::RenderPassCollector *)(v2 + 1072));
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3C8) = v68;
  if ( v68->mNumTasks && !v68->mStartTask.mSyncVars.v.mState )
  {
    if ( p_mEndTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v68, p_mEndTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v68);
    p_mEndTask = &v68->mEndTask;
    *(_QWORD *)v2 = &v68->mEndTask;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  RenderHalfSizeDepthBuffer(render_context, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 336));
  RenderQuarterSizeDepthBuffer(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 336));
  v72 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v73 = (UFG::qTaskGroup *)v72;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v72;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v72;
  if ( v72 )
  {
    *(_QWORD *)v72 = v72;
    *((_QWORD *)v72 + 1) = v72;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v72 + 16;
    *((_QWORD *)v72 + 2) = v72 + 16;
    *((_QWORD *)v72 + 3) = v72 + 16;
    *((_DWORD *)v72 + 8) = 0;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v72 + 64;
    *((_QWORD *)v72 + 8) = v72 + 64;
    *((_QWORD *)v72 + 9) = v72 + 64;
    *((_QWORD *)v72 + 10) = v72 + 80;
    *((_QWORD *)v72 + 11) = v72 + 80;
    *((_QWORD *)v72 + 14) = 0i64;
    *((_DWORD *)v72 + 30) = 2;
    *((_QWORD *)v72 + 12) = 0i64;
    *((_QWORD *)v72 + 13) = 0i64;
    *((_QWORD *)v72 + 16) = 0i64;
    *((_QWORD *)v72 + 17) = 0i64;
    *((_QWORD *)v72 + 18) = 0i64;
    *((_QWORD *)v72 + 19) = -1i64;
    *((_QWORD *)v72 + 20) = 0i64;
    *((_QWORD *)v72 + 21) = 0i64;
    *((_QWORD *)v72 + 22) = 0i64;
    *((_QWORD *)v72 + 23) = 0i64;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v72 + 192;
    *((_QWORD *)v72 + 24) = v72 + 192;
    *((_QWORD *)v72 + 25) = v72 + 192;
    *((_QWORD *)v72 + 26) = v72 + 208;
    *((_QWORD *)v72 + 27) = v72 + 208;
    *((_QWORD *)v72 + 30) = 0i64;
    *((_DWORD *)v72 + 62) = 2;
    *((_QWORD *)v72 + 28) = 0i64;
    *((_QWORD *)v72 + 29) = 0i64;
    *((_QWORD *)v72 + 32) = 0i64;
    *((_QWORD *)v72 + 33) = 0i64;
    *((_QWORD *)v72 + 34) = 0i64;
    *((_QWORD *)v72 + 35) = -2i64;
    *((_QWORD *)v72 + 36) = 0i64;
    *((_QWORD *)v72 + 37) = 0i64;
    *((_QWORD *)v72 + 38) = 0i64;
    *((_QWORD *)v72 + 39) = 0i64;
    *((_QWORD *)v72 + 14) = v72;
    *((_QWORD *)v72 + 30) = v72;
  }
  v74 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v75 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v75->mNext = v73;
  v73->mPrev = v75;
  v73->mNext = &v74->mNode;
  v74->mNode.mPrev = v73;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v73);
  UFG::RenderStageShadow::RenderBeforeSunShadows(
    UFG::RenderWorld::msStageShadow,
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  UFG::RenderStageSpotShadow::RenderBeforeSunShadows(
    UFG::RenderWorld::msStageSpotShadow,
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  UFG::RenderStageAO::RenderAmbientOcclusion(
    UFG::RenderWorld::msStageAO,
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3F8) = UFG::RenderStageShadow::RenderSunShadowsSim(
                                                                                   UFG::RenderWorld::msStageShadow,
                                                                                   render_context,
                                                                                   &gSimpleDrawableCullLayer,
                                                                                   &gCompositeDrawableCullLayer);
  UFG::RenderStageShadow::RenderAfterSunShadows(
    UFG::RenderWorld::msStageShadow,
    render_context,
    (UFG::qMatrix44 *)(v2 + 400));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3D0) = v73;
  if ( v73->mNumTasks && !v73->mStartTask.mSyncVars.v.mState )
  {
    if ( p_mEndTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v73, p_mEndTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v73);
    p_mEndTask = &v73->mEndTask;
    *(_QWORD *)v2 = &v73->mEndTask;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  v76 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v77 = (UFG::qTaskGroup *)v76;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v76;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v76;
  if ( v76 )
  {
    *(_QWORD *)v76 = v76;
    *((_QWORD *)v76 + 1) = v76;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v76 + 16;
    *((_QWORD *)v76 + 2) = v76 + 16;
    *((_QWORD *)v76 + 3) = v76 + 16;
    *((_DWORD *)v76 + 8) = 0;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v76 + 64;
    *((_QWORD *)v76 + 8) = v76 + 64;
    *((_QWORD *)v76 + 9) = v76 + 64;
    *((_QWORD *)v76 + 10) = v76 + 80;
    *((_QWORD *)v76 + 11) = v76 + 80;
    *((_QWORD *)v76 + 14) = 0i64;
    *((_DWORD *)v76 + 30) = 2;
    *((_QWORD *)v76 + 12) = 0i64;
    *((_QWORD *)v76 + 13) = 0i64;
    *((_QWORD *)v76 + 16) = 0i64;
    *((_QWORD *)v76 + 17) = 0i64;
    *((_QWORD *)v76 + 18) = 0i64;
    *((_QWORD *)v76 + 19) = -1i64;
    *((_QWORD *)v76 + 20) = 0i64;
    *((_QWORD *)v76 + 21) = 0i64;
    *((_QWORD *)v76 + 22) = 0i64;
    *((_QWORD *)v76 + 23) = 0i64;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v76 + 192;
    *((_QWORD *)v76 + 24) = v76 + 192;
    *((_QWORD *)v76 + 25) = v76 + 192;
    *((_QWORD *)v76 + 26) = v76 + 208;
    *((_QWORD *)v76 + 27) = v76 + 208;
    *((_QWORD *)v76 + 30) = 0i64;
    *((_DWORD *)v76 + 62) = 2;
    *((_QWORD *)v76 + 28) = 0i64;
    *((_QWORD *)v76 + 29) = 0i64;
    *((_QWORD *)v76 + 32) = 0i64;
    *((_QWORD *)v76 + 33) = 0i64;
    *((_QWORD *)v76 + 34) = 0i64;
    *((_QWORD *)v76 + 35) = -2i64;
    *((_QWORD *)v76 + 36) = 0i64;
    *((_QWORD *)v76 + 37) = 0i64;
    *((_QWORD *)v76 + 38) = 0i64;
    *((_QWORD *)v76 + 39) = 0i64;
    *((_QWORD *)v76 + 14) = v76;
    *((_QWORD *)v76 + 30) = v76;
  }
  v78 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v79 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v79->mNext = v77;
  v77->mPrev = v79;
  v77->mNext = &v78->mNode;
  v78->mNode.mPrev = v77;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v77);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x408) = UFG::RenderStageSpotShadow::RenderSpotShadowsSim(
                                                                                   UFG::RenderWorld::msStageSpotShadow,
                                                                                   render_context,
                                                                                   &gSimpleDrawableCullLayer,
                                                                                   &gCompositeDrawableCullLayer);
  v80 = UFG::qGetTicks();
  RenderDeferredLights_1(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 448),
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8));
  if ( gSpotShadowCount )
  {
    v81 = 0;
    if ( gSpotShadowCount )
    {
      v82 = gSpotShadowIndices;
      do
      {
        if ( render_context->mRenderFeatures.mWorld && render_context->mRenderFeatures.mLights )
        {
          v83 = gLights[gCulledLights[*v82].lightIndex];
          if ( v83->mType == 4 )
            UFG::RenderStageSpotShadow::RenderSpotlightLightShafts(
              UFG::RenderWorld::msStageSpotShadow,
              render_context,
              (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(16i64 * (v81 + 13) + v2 + 256),
              v83,
              &gCulledLights[*v82]);
        }
        RenderDeferredShadowedSpotlights(
          render_context,
          (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(16i64 * (v81 + 21) + v2 + 256),
          v81);
        ++v81;
        ++v82;
      }
      while ( v81 < gSpotShadowCount );
      v65 = *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    }
  }
  RenderDeferredLights_2(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 720),
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8));
  v84 = UFG::qGetTicks();
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3D8) = v77;
  if ( v77->mNumTasks && !v77->mStartTask.mSyncVars.v.mState )
  {
    if ( p_mEndTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v77, p_mEndTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v77);
    *(_QWORD *)v2 = &v77->mEndTask;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  render_context->mRenderStats.mNumShadowsRendered += UFG::RenderWorld::msStageSpotShadow->mNumShadowsRendered
                                                    + UFG::RenderWorld::msStageShadow->mNumShadowsRendered;
  TickTime = UFG::qGetTickTime(Ticks, v65);
  render_context->mRenderStats.mDrawLights = (float)(TickTime + UFG::qGetTickTime(v80, v84))
                                           + render_context->mRenderStats.mDrawLights;
  _((AMD_HD3D *)&Render::Skinning::gSkinning);
  RenderVolumetrics(render_context, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 416));
  RenderHalfSizeBuffer(render_context, (UFG::qMatrix44 *)(v2 + 432));
  CompositeLightsAndEffects(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 736),
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 752));
  if ( render_context->mRenderFeatures.mWorld )
    UFG::RenderStageExposureMetering::Render(
      UFG::RenderWorld::msExposureMetering,
      render_context,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 768));
  mDynamicRangeTarget = render_context->mDynamicRangeTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18) = mDynamicRangeTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = render_context->mFullSizeScratchTargetA;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = UFG::RenderWorld::msIsNisPlaying;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x88) = mDynamicRangeTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = render_context->mHalfSizeScratchTargetC;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x98) = render_context->mHalfSizeLinearDepthTarget->mDepthTextureCopy;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = render_context->mHalfSizeScratchTargetA;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xA8) = render_context->mQuarterSizeScratchTargetA;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = render_context->mQuarterSizeScratchTargetB;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xB8) = render_context->mNearBlur;
  z = render_context->mMainViewSettings.mProjection.v2.z;
  if ( z == 0.0 || z == render_context->mMainViewSettings.mProjection.v2.w )
    v88 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8);
  else
    v88 = render_context->mMainViewSettings.mProjection.v3.z / z;
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)(v2 + 1424));
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x4B0) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                               + 784;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x1208) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                                + 1200;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x1200) = 0;
  Render::DepthOfField::Render(
    &Render::gDepthOfField,
    (Render::DepthOfField::RenderContext *)(v2 + 128),
    (Illusion::SubmitContext *)(v2 + 1424),
    v88);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                              + 2472;
  `eh vector destructor iterator(
    (void *)(v2 + 2520),
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  mAAResultTarget = *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38);
  if ( render_context->mAAResultTarget )
    mAAResultTarget = render_context->mAAResultTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = mAAResultTarget;
  RenderAntiAlias(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 800),
    (Render::RenderPassCollector *)(v2 + 1072),
    (Illusion::Target **)(v2 + 24),
    (Illusion::Target **)(v2 + 56));
  v90 = &UFG::RenderStagePlugin::s_RenderStagePluginList - 4;
  v91 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
  {
    do
    {
      v92 = (__int64)&v91[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, unsigned __int64, UFG::RenderContext *))v91->mPrev[7].mNext)(
        v91,
        v2 + 816,
        render_context);
      v91 = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)v92;
    }
    while ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)v92 != v90 );
  }
  RenderHDRBloom(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 832),
    *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18));
  RenderMotionBlur(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 864),
    (Illusion::Target **)(v2 + 24),
    (Illusion::Target **)(v2 + 56));
  v93 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != v90 )
  {
    do
    {
      v94 = (__int64)&v93[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, unsigned __int64, UFG::RenderContext *))v93->mPrev[8].mPrev)(
        v93,
        v2 + 848,
        render_context);
      v93 = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)v94;
    }
    while ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)v94 != v90 );
  }
  CompositeFinalAndDrawUI(
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 880),
    *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                              + 2472;
  do
  {
    LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)(v2 + 1424));
    RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x1208) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                                  + 1200;
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x1200) = 0;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x4B0) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                                 + 944;
    v95 = UFG::PartCompositeBuilder::Instance();
    v96 = UFG::PartCompositeBuilder::RenderComposites(v95, (Illusion::SubmitContext *)(v2 + 1424));
    RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)(v2 + 1200));
    RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
    `eh vector destructor iterator(
      (void *)(v2 + 2520),
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
  while ( v96 );
  RenderBackBufferToPresentBufferAndApplyBlackLevel((UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 896));
  UFG::RenderWorld::UpdateRenderScreenShot(
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 912),
    *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18));
  UFG::RenderStageFrameCapture::Render(
    UFG::RenderWorld::msStageFrameCapture,
    render_context,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 928));
  v97 = CullManager::Instance();
  CullManager::EndFrame(v97);
  LateFlushToIllusion(
    (FlushContext *)(v2 + 256),
    render_context,
    fTime,
    *(MainViewTargetParams **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58));
  v98 = (UFG::qTaskGroup **)(v2 + 960);
  v99 = 4i64;
  do
  {
    v100 = *v98;
    if ( *v98 && v100->mNumTasks )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v100);
    ++v98;
    --v99;
  }
  while ( v99 );
  `eh vector destructor iterator(
    (void *)(v2 + 1072),
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Render::RenderPassComponents::~RenderPassComponents);
  `eh vector destructor iterator(
    (void *)(v2 + 256),
    0x10ui64,
    44,
    (void (__fastcall *)(void *))UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::~qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>);
}

// File Line: 5410
// RVA: 0x59550
void __fastcall UFG::RenderWorld::RenderWorldClearScreen(float fTime, void *param)
{
  Render::ViewSettings *Identity; // rax
  Illusion::Target *BackBufferTarget; // rax
  char *v4; // rax
  Illusion::RenderPhase *v5; // rcx
  _QWORD *v6; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *p_mQueues; // r10
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v10; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v13; // [rsp+50h] [rbp-B0h] BYREF
  _QWORD *v14; // [rsp+60h] [rbp-A0h]
  __int64 v15; // [rsp+68h] [rbp-98h]
  RenderQueueLayer v16; // [rsp+70h] [rbp-90h] BYREF
  Render::View v17; // [rsp+150h] [rbp+50h] BYREF
  LayerSubmitContext ptr; // [rsp+2E0h] [rbp+1E0h] BYREF

  v15 = -2i64;
  v13.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
  v13.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
  RenderQueueLayer::RenderQueueLayer(&v16);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v16.mSerializationList = &v13;
  ptr.mRenderQueueProvider = &v16;
  ptr.mQueueMode = QM_Single;
  Identity = Render::ViewSettings::GetIdentity();
  Render::View::View(&v17, Identity, &ptr);
  BackBufferTarget = Render::GetBackBufferTarget();
  Render::View::BeginTarget(&v17, BackBufferTarget, "LoadScreen", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v17, &UFG::qColour::Black, 0xFFu, 1.0, 1u);
  Render::View::EndTarget(&v17);
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v5 = (Illusion::RenderPhase *)v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    v6 = v4 + 16;
    v14 = v6;
    *v6 = v6;
    v6[1] = v6;
    v5->mFlushTaskDependency = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  p_mQueues = &v5->mQueues;
  mNext = v13.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v13.mNode.mNext != &v13 )
  {
    mPrev = p_mQueues->mNode.mPrev;
    v10 = v13.mNode.mPrev;
    mPrev->mNext = v13.mNode.mNext;
    mNext->mPrev = mPrev;
    v10->mNext = &p_mQueues->mNode;
    p_mQueues->mNode.mPrev = v10;
    v13.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
    v13.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
  }
  Illusion::RenderQueueSystem::FlushRenderPhase(v5, 1u, 0, 0i64, 0);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v16);
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v13);
  v11 = v13.mNode.mPrev;
  v12 = v13.mNode.mNext;
  v13.mNode.mPrev->mNext = v13.mNode.mNext;
  v12->mPrev = v11;
}

// File Line: 5435
// RVA: 0x592D0
void __fastcall UFG::RenderWorld::RenderWorldCallback(float fTime, UFG::RenderContext *render_param)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  bool v4; // al

  if ( g_enable3D && gCurrentEye == STEREO_EYE_RIGHT )
    UFG::RenderWorld::UpdateViews(fTime);
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  render_param->mMotionBlurStrength = *((float *)&mCurrentCamera->vfptr + 1);
  render_param->mRenderFeatures = gRenderFrameFeatures;
  render_param->mRenderFeatures.mWorld &= UFG::RenderWorld::msRenderWorld;
  render_param->mRenderFeatures.mScenery &= gDrawScenery;
  v4 = gDrawUI;
  render_param->mRenderFeatures.mDOF &= 1u;
  render_param->mRenderFeatures.mUI &= v4;
  render_param->mRenderFeatures.mLights &= 1u;
  render_param->mRenderFeatures.mAO &= 1u;
  render_param->mRenderFeatures.mMotionBlur &= 1u;
  RenderWorldDeferred(fTime, render_param);
}

// File Line: 5490
// RVA: 0x1454CF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Main__()
{
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Main.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Main__);
}

// File Line: 5491
// RVA: 0x1454AF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXLow__()
{
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXLow.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXLow__);
}

// File Line: 5492
// RVA: 0x1454A70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXHigh__()
{
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXHigh.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXHigh__);
}

// File Line: 5493
// RVA: 0x14549F0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXDeferred__()
{
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_FXDeferred.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXDeferred__);
}

// File Line: 5494
// RVA: 0x1454B70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_GBuffer__()
{
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_GBuffer.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_GBuffer__);
}

// File Line: 5495
// RVA: 0x1454C70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Lighting_Shadows__()
{
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Shadows.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Lighting_Shadows__);
}

// File Line: 5496
// RVA: 0x1454BF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Lighting_Lights__()
{
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Lighting_Lights.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Lighting_Lights__);
}

// File Line: 5497
// RVA: 0x1454870
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Bloom__()
{
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_Bloom.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Bloom__);
}

// File Line: 5498
// RVA: 0x14548F0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_DOF__()
{
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_DOF.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_DOF__);
}

// File Line: 5499
// RVA: 0x1454970
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_EnvMap__()
{
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_EnvMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_EnvMap__);
}

// File Line: 5500
// RVA: 0x1454DF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_ReflMap__()
{
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_ReflMap.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_ReflMap__);
}

// File Line: 5501
// RVA: 0x1454D70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_PostFX__()
{
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mPrev = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>::mNext = &UFG::RenderWorld::msGpuTimer_PostFX.UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode>;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_PostFX__);
}

// File Line: 5510
// RVA: 0x5B160
void __fastcall UFG::RenderWorld::SetRenderWorld(bool bEnable)
{
  UFG::RenderWorld::msRenderWorld = bEnable;
}

// File Line: 5515
// RVA: 0x5AF20
void __fastcall UFG::RenderWorld::SetFlags(unsigned int flags)
{
  UFG::RenderWorld::msFlags = flags;
}

// File Line: 5525
// RVA: 0x4AE90
void __fastcall UFG::RenderWorld::DamagePostEffect_OnDamage(float magnitude)
{
  UFG::DamagePostEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = (UFG::DamagePostEffect *)UFG::SimObject::GetComponentOfType(
                                                 UFG::RenderWorld::msRenderStagePlugin,
                                                 UFG::DamagePostEffect::_TypeUID);
    if ( ComponentOfType )
      UFG::DamagePostEffect::OnDamage(ComponentOfType, magnitude);
  }
}

// File Line: 5535
// RVA: 0x4FCB0
void __fastcall UFG::RenderWorld::GunRecoilPostEffect_TriggerRecoil(float intensity, float falloff_scale)
{
  UFG::SimComponent *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::GunRecoilPostEffect::_TypeUID);
    if ( ComponentOfType )
    {
      *(float *)&ComponentOfType[1].m_SafePointerList.mNode.mNext = intensity;
      *((float *)&ComponentOfType[1].m_SafePointerList.mNode.mNext + 1) = falloff_scale * 0.050000001;
    }
  }
}

// File Line: 5544
// RVA: 0x49800
void __fastcall UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(bool value)
{
  UFG::SimComponent *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AccumulationBufferPostEffect::_TypeUID);
    if ( ComponentOfType )
      *(float *)&ComponentOfType[1].m_SafePointerList.mNode.mNext = (float)value;
  }
}

// File Line: 5553
// RVA: 0x5D830
unsigned int __fastcall UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(
        int index,
        bool isAdditive,
        int priority)
{
  UFG::VisualTreatmentPostEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin
    && (ComponentOfType = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                              UFG::RenderWorld::msRenderStagePlugin,
                                                              UFG::VisualTreatmentPostEffect::_TypeUID)) != 0i64 )
  {
    return UFG::VisualTreatmentPostEffect::StartVisualTreatment(ComponentOfType, index, isAdditive, priority);
  }
  else
  {
    return -1;
  }
}

// File Line: 5563
// RVA: 0x5D8E0
void __fastcall UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(
        unsigned int treatmentId,
        float fade_duration)
{
  UFG::VisualTreatmentPostEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                          UFG::RenderWorld::msRenderStagePlugin,
                                                          UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( ComponentOfType )
      UFG::VisualTreatmentPostEffect::StopVisualTreatment(ComponentOfType, treatmentId, fade_duration);
  }
}

// File Line: 5572
// RVA: 0x5D8A0
void UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments(void)
{
  UFG::VisualTreatmentPostEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                          UFG::RenderWorld::msRenderStagePlugin,
                                                          UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( ComponentOfType )
      UFG::VisualTreatmentPostEffect::StopAllVisualTreatments(ComponentOfType);
  }
}

// File Line: 5591
// RVA: 0x4E1F0
void __fastcall UFG::RenderWorld::FrontEndPauseEffect_Start(unsigned int visual_treatment_uid)
{
  UFG::FrontEndPauseEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = (UFG::FrontEndPauseEffect *)UFG::SimObject::GetComponentOfType(
                                                    UFG::RenderWorld::msRenderStagePlugin,
                                                    UFG::FrontEndPauseEffect::_TypeUID);
    if ( ComponentOfType )
      UFG::FrontEndPauseEffect::Start(ComponentOfType, visual_treatment_uid);
  }
}

// File Line: 5600
// RVA: 0x4E1B0
void __fastcall UFG::RenderWorld::FrontEndPauseEffect_End(bool fade)
{
  UFG::FrontEndPauseEffect *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = (UFG::FrontEndPauseEffect *)UFG::SimObject::GetComponentOfType(
                                                    UFG::RenderWorld::msRenderStagePlugin,
                                                    UFG::FrontEndPauseEffect::_TypeUID);
    if ( ComponentOfType )
      UFG::FrontEndPauseEffect::End(ComponentOfType, fade);
  }
}

// File Line: 5618
// RVA: 0x5B140
void __fastcall Render::SetRenderFeatures(Render::RenderFrameFeatures *features)
{
  gRenderFrameFeatures = *features;
}

// File Line: 5623
// RVA: 0x4FBF0
Render::RenderFrameFeatures *__fastcall Render::GetRenderFeatures()
{
  return &gRenderFrameFeatures;
}

