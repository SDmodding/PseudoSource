// File Line: 165
// RVA: 0x1454ED0
__int64 dynamic_initializer_for__AlphaStateNoneHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&AlphaStateNoneHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__AlphaStateNoneHandle__);
}

// File Line: 166
// RVA: 0x1454EA0
__int64 dynamic_initializer_for__AlphaStateNoColourWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&AlphaStateNoColourWriteHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__AlphaStateNoColourWriteHandle__);
}

// File Line: 167
// RVA: 0x1454E70
__int64 dynamic_initializer_for__AlphaStateDeferredPunchThroughHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&AlphaStateDeferredPunchThroughHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__AlphaStateDeferredPunchThroughHandle__);
}

// File Line: 168
// RVA: 0x1454FF0
__int64 dynamic_initializer_for__RasterStateNormalHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateNormalHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateNormalHandle__);
}

// File Line: 169
// RVA: 0x1454F90
__int64 dynamic_initializer_for__RasterStateInvertCullingHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateInvertCullingHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateInvertCullingHandle__);
}

// File Line: 170
// RVA: 0x1454FC0
__int64 dynamic_initializer_for__RasterStateNormalDisableWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateNormalDisableWriteHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateNormalDisableWriteHandle__);
}

// File Line: 171
// RVA: 0x1454F60
__int64 dynamic_initializer_for__RasterStateInverseDisableWriteHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateInverseDisableWriteHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateInverseDisableWriteHandle__);
}

// File Line: 172
// RVA: 0x1454F30
__int64 dynamic_initializer_for__RasterStateDoubleSidedHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateDoubleSidedHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateDoubleSidedHandle__);
}

// File Line: 173
// RVA: 0x1454F00
__int64 dynamic_initializer_for__RasterStateDoubleSidedAlphaHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&RasterStateDoubleSidedAlphaHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__RasterStateDoubleSidedAlphaHandle__);
}

// File Line: 271
// RVA: 0x1456370
__int64 dynamic_initializer_for__gScenerySelector_Name__()
{
  UFG::qString::qString(&gScenerySelector_Name);
  return atexit(dynamic_atexit_destructor_for__gScenerySelector_Name__);
}

// File Line: 274
// RVA: 0x1456310
__int64 dynamic_initializer_for__gReflectionFadeCube__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gReflectionFadeCube.mPrev);
  return atexit(dynamic_atexit_destructor_for__gReflectionFadeCube__);
}

// File Line: 275
// RVA: 0x1455F50
__int64 dynamic_initializer_for__gDefaultBlackTexture__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDefaultBlackTexture.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDefaultBlackTexture__);
}

// File Line: 276
// RVA: 0x1455F80
__int64 dynamic_initializer_for__gDefaultWhiteTexture__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDefaultWhiteTexture.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDefaultWhiteTexture__);
}

// File Line: 277
// RVA: 0x1455FB0
__int64 dynamic_initializer_for__gDefaultZeroTexture__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDefaultZeroTexture.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDefaultZeroTexture__);
}

// File Line: 278
// RVA: 0x1455EA0
__int64 dynamic_initializer_for__gArcTanTexture__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gArcTanTexture.mPrev);
  return atexit(dynamic_atexit_destructor_for__gArcTanTexture__);
}

// File Line: 280
// RVA: 0x1455F20
__int64 dynamic_initializer_for__gDebugFontHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDebugFontHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDebugFontHandle__);
}

// File Line: 317
// RVA: 0x1456390
__int64 dynamic_initializer_for__gSimpleDrawableCullLayer__()
{
  CullLayer::CullLayer(&gSimpleDrawableCullLayer, 0, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__gSimpleDrawableCullLayer__);
}

// File Line: 318
// RVA: 0x1455EF0
__int64 dynamic_initializer_for__gCompositeDrawableCullLayer__()
{
  CullLayer::CullLayer(&gCompositeDrawableCullLayer, 0, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__gCompositeDrawableCullLayer__);
}

// File Line: 347
// RVA: 0x48D80
void __fastcall SimRenderQueueResults::SimRenderQueueResults(SimRenderQueueResults *this)
{
  SimRenderQueueResults *v1; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // [rsp+48h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // [rsp+48h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  RenderQueueLayer::RenderQueueLayer(&this->mRenderSimLayer);
  RenderQueueLayer::RenderQueueLayer(&v1->mFXLayer);
  v2 = &v1->mTerrainQueues;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v3 = &v1->mImposterQueues;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v1->mDecalQueues;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 376
// RVA: 0x48CD0
void __fastcall SceneryTaskRenderQueueResults::SceneryTaskRenderQueueResults(SceneryTaskRenderQueueResults *this)
{
  SceneryTaskRenderQueueResults *v1; // rdi
  Render::ViewMetrics *v2; // rbx
  signed int v3; // esi

  v1 = this;
  this->mSceneryBucketIndex = 0;
  `eh vector constructor iterator(
    this->mSceneryLayer,
    0xE0ui64,
    5,
    (void (__fastcall *)(void *))RenderQueueLayer::RenderQueueLayer);
  v2 = v1->mSceneryViewMetrics;
  v3 = 4;
  do
  {
    Render::ViewMetrics::Reset(v2);
    ++v2;
    --v3;
  }
  while ( v3 >= 0 );
  v1->mSceneryTaskGroup = 0i64;
  v1->mSceneryTaskParams[0] = 0i64;
  v1->mSceneryTaskParams[1] = 0i64;
  v1->mSceneryTaskParams[2] = 0i64;
  v1->mSceneryTaskParams[3] = 0i64;
  v1->mSceneryTaskParams[4] = 0i64;
}

// File Line: 553
// RVA: 0x59390
void RenderWorldChangeLODSettings(void)
{
  float v0; // xmm6_4
  float v1; // xmm7_4
  Illusion::Target *v2; // rbx
  float v3; // xmm2_4
  float v4; // xmm1_4
  BOOL v5; // ebx
  UFG::TimeOfDayManager *v6; // rax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-98h]

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  v0 = *(float *)&FLOAT_1_0;
  if ( outSettings.mLODSetting >= 2 )
    v1 = *(float *)&FLOAT_1_0;
  else
    v1 = FLOAT_3_0;
  UFG::CompositeDrawableComponent::ScalePixelCoverageToLOD(v1);
  v2 = Render::GetBackBufferTarget();
  v3 = FLOAT_0_1;
  v4 = (float)(921600.0 / (float)(v2->mHeight * Render::GetBackBufferTarget()->mWidth)) * 0.1;
  if ( v4 <= 0.1 )
    v3 = v4;
  if ( outSettings.mAAQuality )
    v0 = FLOAT_0_5;
  v5 = outSettings.mLODSetting <= 1;
  gMainView_CullPixelDensityThreshold = (float)(v0 * v3) * v1;
  v6 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetFogSlicingMode(v6, v5 + 1);
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
  void (__fastcall *v4)(Render::RenderOutputParams *); // rax
  Render::RenderCallbacks *v5; // rax
  UFG::RenderContext *v6; // rbx
  char *v7; // rax
  void *v8; // rax
  void *v9; // rbx
  Render::DebugDrawManager *v10; // rdi
  int v11; // ebx
  Illusion::Target *v12; // rax
  int *v13; // rax
  UFG::DUIContext *v14; // rax
  UFG::DUIRect rect; // [rsp+60h] [rbp-A8h]
  __int64 v16; // [rsp+70h] [rbp-98h]
  Render::RenderOutputParams outSettings; // [rsp+80h] [rbp-88h]

  v16 = -2i64;
  Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
  reflection_width = Render::GetBackBufferTarget()->mWidth;
  reflection_height = Render::GetBackBufferTarget()->mHeight;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  aaQuality = outSettings.mAAQuality;
  RenderWorldChangeLODSettings();
  bLightMRT = outSettings.mSSAO == 1;
  if ( UFG::UIScreenManager::s_instance )
  {
    v4 = UFG::UIScreenManager::s_instance->m_DisplayChangeCallback;
    if ( v4 )
      v4(&outSettings);
  }
  v5 = Render::GetRenderCallbacks();
  v6 = (UFG::RenderContext *)v5->mRenderParam;
  if ( v6 )
  {
    UFG::RenderContext::DeleteTargets((UFG::RenderContext *)v5->mRenderParam);
    UFG::RenderContext::CreateTargets(
      v6,
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
  v11 = Render::GetBackBufferTarget()->mHeight;
  v12 = Render::GetBackBufferTarget();
  Render::DebugDrawManager::SetContextsTargetSize(v10, v12->mWidth, v11, 2u, 0);
  if ( gTheoryOverlay )
  {
    v13 = (int *)((__int64 (*)(void))gTheoryOverlay->vfptr->GetContext)();
    rect.mX = v13[176];
    rect.mY = v13[177];
    rect.mW = v13[178];
    LODWORD(v13) = v13[179];
    rect.mW = reflection_width;
    rect.mH = reflection_height;
    v14 = (UFG::DUIContext *)((__int64 (*)(void))gTheoryOverlay->vfptr->GetContext)();
    UFG::DUIContext::SetOverallRect(v14, &rect);
    gTheoryOverlay->mWidth = rect.mW;
    gTheoryOverlay->mHeight = rect.mH;
  }
}

// File Line: 692
// RVA: 0x5AEC0
void RenderWorldResizeShadows(void)
{
  RenderWorldResize();
}

// File Line: 699
// RVA: 0x59510
void RenderWorldChangeTexturePack(void)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h]

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  gIsHDWorldTextures = outSettings.mTextureDetailLevel == 2;
  UFG::SectionChooser::BeginFlush(1);
}

// File Line: 710
// RVA: 0x58FE0
void UFG::RenderWorld::RenderThreadSyncUpdate(void)
{
  JUMPOUT(UFG::RenderWorld::msStageFrameCapture, 0i64, UFG::RenderStageFrameCapture::UpdateAlias);
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
  LODWORD(v2[1].mResourceHandles.mNode.mNext) = v3;
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
  LODWORD(v7[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v7[2].mNode.mUID = 543723269;
  v7[1].mNumParams = v8;
  v9 = sPresentMaterial;
  LOWORD(sPresentMaterial[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].0 + 22) = -1958479169;
  LODWORD(v9[2].mResourceHandles.mNode.mNext) = v10;
  *(_DWORD *)&v9[2].mDebugName[28] = 0;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, (UFG::qResourceData *)&sPresentMaterial->mNode);
}

// File Line: 765
// RVA: 0x4FD10
void UFG::RenderWorld::Init(void)
{
  UFG::qResourceHandle *v0; // rsi
  UFG::qResourceInventory *v1; // rax
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
  UFG::qMemoryPool *v21; // rax
  char *v22; // rdi
  UFG::qSymbol *v23; // rax
  UFG::SimObject *v24; // rax
  UFG::RenderContext *v25; // rbp
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
  UFG::qResourceData *v40; // rax
  UFG::qResourceData *v41; // rbx
  UFG::qResourceWarehouse *v42; // rax
  unsigned int v43; // eax
  UFG::qResourceData *v44; // rax
  UFG::qResourceData *v45; // rbx
  UFG::qResourceWarehouse *v46; // rax
  unsigned int v47; // eax
  UFG::qResourceData *v48; // rax
  UFG::qResourceData *v49; // rbx
  UFG::qResourceWarehouse *v50; // rax
  unsigned int v51; // eax
  UFG::qResourceData *v52; // rax
  UFG::qResourceData *v53; // rbx
  UFG::qResourceWarehouse *v54; // rax
  unsigned int v55; // eax
  UFG::qResourceData *v56; // rax
  UFG::qResourceData *v57; // rbx
  UFG::qResourceWarehouse *v58; // rax
  unsigned int v59; // eax
  UFG::qResourceData *v60; // rax
  UFG::qResourceData *v61; // rbx
  UFG::qResourceWarehouse *v62; // rax
  unsigned int v63; // eax
  UFG::qResourceData *v64; // rax
  UFG::qResourceData *v65; // rbx
  UFG::qResourceWarehouse *v66; // rax
  unsigned int v67; // eax
  UFG::qResourceData *v68; // rax
  UFG::qResourceData *v69; // rbx
  UFG::qResourceWarehouse *v70; // rax
  unsigned int v71; // eax
  UFG::qResourceData *v72; // rax
  UFG::qResourceData *v73; // rbx
  UFG::qResourceWarehouse *v74; // rax
  unsigned int v75; // eax
  UFG::qResourceData *v76; // rax
  UFG::qResourceData *v77; // rbx
  UFG::qResourceWarehouse *v78; // rax
  unsigned int v79; // eax
  UFG::qResourceData *v80; // rax
  UFG::qResourceData *v81; // rbx
  UFG::qResourceWarehouse *v82; // rax
  unsigned int v83; // eax
  UFG::qResourceData *v84; // rax
  UFG::qResourceData *v85; // rbx
  UFG::qResourceWarehouse *v86; // rax
  unsigned int v87; // eax
  UFG::qResourceData *v88; // rax
  UFG::qResourceData *v89; // rbx
  UFG::qResourceWarehouse *v90; // rax
  unsigned int v91; // eax
  UFG::qResourceData *v92; // rax
  UFG::qResourceData *v93; // rbx
  UFG::qResourceWarehouse *v94; // rax
  unsigned int v95; // eax
  UFG::qResourceData *v96; // rax
  UFG::qResourceData *v97; // rbx
  UFG::qResourceWarehouse *v98; // rax
  unsigned int v99; // eax
  UFG::qResourceData *v100; // rax
  UFG::qResourceData *v101; // rbx
  UFG::qResourceWarehouse *v102; // rax
  unsigned int v103; // ebx
  UFG::qResourceInventory *v104; // rax
  UFG::qResourceWarehouse *v105; // rax
  UFG::qResourceInventory *v106; // rax
  UFG::qResourceWarehouse *v107; // rax
  UFG::qResourceInventory *v108; // rax
  UFG::qResourceWarehouse *v109; // rax
  UFG::qResourceInventory *v110; // rax
  UFG::qResourceWarehouse *v111; // rax
  unsigned int v112; // ebx
  UFG::qResourceInventory *v113; // rax
  UFG::qResourceWarehouse *v114; // rax
  UFG::qResourceWarehouse *v115; // rax
  UFG::qResourceInventory *v116; // rax
  UFG::qResourceInventory *v117; // rbx
  UFG::qResourceInventoryVtbl *v118; // rdi
  unsigned int v119; // eax
  __int64 v120; // rax
  __int64 v121; // rcx
  __int64 v122; // rax
  UFG::qResourceInventory *v123; // rax
  UFG::qResourceWarehouse *v124; // rax
  unsigned int alpha_state_out_uids; // [rsp+40h] [rbp-78h]
  int v126; // [rsp+44h] [rbp-74h]
  int v127; // [rsp+48h] [rbp-70h]
  int v128; // [rsp+4Ch] [rbp-6Ch]
  int v129; // [rsp+50h] [rbp-68h]
  int v130; // [rsp+54h] [rbp-64h]
  int v131; // [rsp+58h] [rbp-60h]
  int v132; // [rsp+5Ch] [rbp-5Ch]
  int v133; // [rsp+60h] [rbp-58h]
  unsigned int alpha_state_in_uids; // [rsp+68h] [rbp-50h]
  int v135; // [rsp+6Ch] [rbp-4Ch]
  int v136; // [rsp+70h] [rbp-48h]
  int v137; // [rsp+74h] [rbp-44h]
  int v138; // [rsp+78h] [rbp-40h]
  int v139; // [rsp+7Ch] [rbp-3Ch]
  int v140; // [rsp+80h] [rbp-38h]
  int v141; // [rsp+84h] [rbp-34h]
  int v142; // [rsp+88h] [rbp-30h]
  char *result; // [rsp+C0h] [rbp+8h]
  char *v144; // [rsp+C8h] [rbp+10h]

  v0 = 0i64;
  v1 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v2, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v1;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&AlphaStateNoneHandle.mPrev, 0x12C800F2u, 0x2782CCE6u, v1);
  v3 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&AlphaStateNoColourWriteHandle.mPrev, 0x12C800F2u, 0x91A2DD53, v3);
  v5 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v5;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&RasterStateNormalHandle.mPrev, 0x3BC715E0u, 0x20688F05u, v5);
  v7 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&RasterStateInvertCullingHandle.mPrev, 0x3BC715E0u, 0xBC9FAF09, v7);
  v9 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v9;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&RasterStateNormalDisableWriteHandle.mPrev,
    0x3BC715E0u,
    0xF05AB9A5,
    v9);
  v11 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v11;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&RasterStateInverseDisableWriteHandle.mPrev,
    0x3BC715E0u,
    0x4B6C82C0u,
    v11);
  v13 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v13;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&RasterStateDoubleSidedHandle.mPrev, 0x3BC715E0u, 0x940FB8EC, v13);
  v15 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v15;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&AlphaStateDeferredPunchThroughHandle.mPrev,
    0x12C800F2u,
    0x80EA5501,
    v15);
  v17 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v17;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&RasterStateDoubleSidedAlphaHandle.mPrev,
    0x3BC715E0u,
    0x418CAF43u,
    v17);
  v19 = UFG::qMalloc(0x100ui64, "gSceneryCullLayer", 0x8000ui64);
  result = v19;
  if ( v19 )
    CullLayer::CullLayer((CullLayer *)v19, 0, "Scenery Cull Layer");
  else
    v20 = 0i64;
  gSceneryCullLayer = v20;
  Render::SimpleDrawableComponent::mDefaultCullLayer = &gSimpleDrawableCullLayer;
  UFG::CompositeDrawableComponent::mDefaultCullLayer = &gCompositeDrawableCullLayer;
  v21 = UFG::GetSimulationMemoryPool();
  v22 = UFG::qMemoryPool::Allocate(v21, 0x80ui64, "SimObject", 0i64, 1u);
  v144 = v22;
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
  v25 = (UFG::RenderContext *)Render::GetRenderCallbacks()->mRenderParam;
  Render::GetRenderCallbacks()->mResizeRenderBuffersFunc = (void (__fastcall *)())RenderWorldResize;
  Render::GetRenderCallbacks()->mResizeShadowsFunc = (void (__fastcall *)())RenderWorldResizeShadows;
  if ( !Render::GetRenderCallbacks()->mChangeTexturePackFunc )
    Render::GetRenderCallbacks()->mChangeTexturePackFunc = (void (__fastcall *)())RenderWorldChangeTexturePack;
  Render::GetRenderCallbacks()->mChangeLODSettingFunc = (void (__fastcall *)())RenderWorldChangeLODSettings;
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
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDebugFontHandle.mPrev, 0x69FCCB4Cu, v26, v27);
  UFG::RenderStageAO::Create(v25);
  UFG::RenderWorld::msStageAO = v29;
  UFG::RenderStageShadow::Create(v25);
  UFG::RenderWorld::msStageShadow = v30;
  UFG::RenderStageSpotShadow::Create(v25);
  UFG::RenderWorld::msStageSpotShadow = v31;
  UFG::RenderStageHairSkin::Create(v25);
  UFG::RenderWorld::msStageHairSkin = v32;
  UFG::RenderStageExposureMetering::Create(v25);
  UFG::RenderWorld::msExposureMetering = v33;
  UFG::RenderStageEnvMap::Create(v25);
  UFG::RenderWorld::msStageEnvMap = v34;
  UFG::RenderStageFrameCapture::Create(v25, UFG::RenderStageFrameCapture::sWidth, UFG::RenderStageFrameCapture::sHeight);
  UFG::RenderWorld::msStageFrameCapture = v35;
  UFG::RenderStageImposters::Create(v25);
  UFG::RenderWorld::msStageImposters = v36;
  UFG::RenderStageTerrain::Create(v25);
  UFG::RenderWorld::msStageTerrain = v37;
  InitDeferredRendering(v25);
  CullManager::Instance()->mPixelDensityDynamicBias = 3;
  v38 = UFG::qStringHash32("COLOURCUBEBLEND", 0xFFFFFFFF);
  UFG::ColourCubeMgr::Init(v38);
  InitIrradianceCaptureSystem();
  v39 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  v40 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMask_000", v39, 0i64, 0i64, 0i64);
  v41 = v40;
  WORD2(v40[1].mNode.mChild[0]) = 0;
  v42 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v42, v41);
  v43 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_125", 0xFFFFFFFF);
  v44 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_125", v43, 0i64, 0i64, 0i64);
  v45 = v44;
  WORD2(v44[1].mNode.mChild[0]) = 1;
  v46 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v46, v45);
  v47 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_25", 0xFFFFFFFF);
  v48 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_25", v47, 0i64, 0i64, 0i64);
  v49 = v48;
  WORD2(v48[1].mNode.mChild[0]) = 2;
  v50 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v50, v49);
  v51 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_375", 0xFFFFFFFF);
  v52 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_375", v51, 0i64, 0i64, 0i64);
  v53 = v52;
  WORD2(v52[1].mNode.mChild[0]) = 3;
  v54 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v54, v53);
  v55 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_50", 0xFFFFFFFF);
  v56 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_50", v55, 0i64, 0i64, 0i64);
  v57 = v56;
  WORD2(v56[1].mNode.mChild[0]) = 4;
  v58 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v58, v57);
  v59 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_625", 0xFFFFFFFF);
  v60 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_625", v59, 0i64, 0i64, 0i64);
  v61 = v60;
  WORD2(v60[1].mNode.mChild[0]) = 5;
  v62 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v62, v61);
  v63 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_75", 0xFFFFFFFF);
  v64 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_75", v63, 0i64, 0i64, 0i64);
  v65 = v64;
  WORD2(v64[1].mNode.mChild[0]) = 6;
  v66 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v66, v65);
  v67 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_875", 0xFFFFFFFF);
  v68 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskIn_875", v67, 0i64, 0i64, 0i64);
  v69 = v68;
  WORD2(v68[1].mNode.mChild[0]) = 7;
  v70 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v70, v69);
  v71 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_125", 0xFFFFFFFF);
  v72 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_125", v71, 0i64, 0i64, 0i64);
  v73 = v72;
  WORD2(v72[1].mNode.mChild[0]) = 8;
  v74 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v74, v73);
  v75 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_25", 0xFFFFFFFF);
  v76 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_25", v75, 0i64, 0i64, 0i64);
  v77 = v76;
  WORD2(v76[1].mNode.mChild[0]) = 9;
  v78 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v78, v77);
  v79 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_375", 0xFFFFFFFF);
  v80 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_375", v79, 0i64, 0i64, 0i64);
  v81 = v80;
  WORD2(v80[1].mNode.mChild[0]) = 10;
  v82 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v82, v81);
  v83 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_50", 0xFFFFFFFF);
  v84 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_50", v83, 0i64, 0i64, 0i64);
  v85 = v84;
  WORD2(v84[1].mNode.mChild[0]) = 11;
  v86 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v86, v85);
  v87 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_625", 0xFFFFFFFF);
  v88 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_625", v87, 0i64, 0i64, 0i64);
  v89 = v88;
  WORD2(v88[1].mNode.mChild[0]) = 12;
  v90 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v90, v89);
  v91 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_75", 0xFFFFFFFF);
  v92 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_75", v91, 0i64, 0i64, 0i64);
  v93 = v92;
  WORD2(v92[1].mNode.mChild[0]) = 13;
  v94 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v94, v93);
  v95 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_875", 0xFFFFFFFF);
  v96 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMaskOut_875", v95, 0i64, 0i64, 0i64);
  v97 = v96;
  WORD2(v96[1].mNode.mChild[0]) = 14;
  v98 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v98, v97);
  v99 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  v100 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.DitherMask_1000", v99, 0i64, 0i64, 0i64);
  v101 = v100;
  WORD2(v100[1].mNode.mChild[0]) = 15;
  v102 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v102, v101);
  alpha_state_in_uids = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  v135 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_125", 0xFFFFFFFF);
  v136 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_25", 0xFFFFFFFF);
  v137 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_375", 0xFFFFFFFF);
  v138 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_50", 0xFFFFFFFF);
  v139 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_625", 0xFFFFFFFF);
  v140 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_75", 0xFFFFFFFF);
  v141 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskIn_875", 0xFFFFFFFF);
  v142 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  alpha_state_out_uids = UFG::qStringHash32("Deferred.AlphaState.DitherMask_000", 0xFFFFFFFF);
  v126 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_125", 0xFFFFFFFF);
  v127 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_25", 0xFFFFFFFF);
  v128 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_375", 0xFFFFFFFF);
  v129 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_50", 0xFFFFFFFF);
  v130 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_625", 0xFFFFFFFF);
  v131 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_75", 0xFFFFFFFF);
  v132 = UFG::qStringHash32("Deferred.AlphaState.DitherMaskOut_875", 0xFFFFFFFF);
  v133 = UFG::qStringHash32("Deferred.AlphaState.DitherMask_1000", 0xFFFFFFFF);
  Render::TransparencySystem::Init(&alpha_state_in_uids, &alpha_state_out_uids, 9);
  UFG::Water::Init(0x200u, 6u);
  Render::Skinning::gSkinning.mRenderMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::Mesh *, UFG::qMatrix44 *, Illusion::Material *, UFG::BitFlags128, const char *))SubmitSkinnedMesh;
  Render::Skinning::gSkinning.mRenderRMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::rMesh *, UFG::qMatrix44 *, Illusion::rMaterial *, UFG::BitFlags128, const char *))SubmitSkinnedRMesh;
  Render::Skinning::gSkinning.mRenderDecalFunc = Render::DefaultRenderDecalFunc;
  Render::Skinning::gSkinning.mEnablePersistentCache = 0;
  _((AMD_HD3D *)&Render::gSoftbody);
  v103 = UFG::qStringHashUpper32("ReflectionFadeCube", 0xFFFFFFFF);
  v104 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v105 = UFG::qResourceWarehouse::Instance();
    v104 = UFG::qResourceWarehouse::GetInventory(v105, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v104;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gReflectionFadeCube.mPrev, 0x8B43FABF, v103, v104);
  v106 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v107 = UFG::qResourceWarehouse::Instance();
    v106 = UFG::qResourceWarehouse::GetInventory(v107, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v106;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDefaultBlackTexture.mPrev, 0x8B43FABF, 0x3218EEB7u, v106);
  v108 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v109 = UFG::qResourceWarehouse::Instance();
    v108 = UFG::qResourceWarehouse::GetInventory(v109, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v108;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDefaultWhiteTexture.mPrev, 0x8B43FABF, 0xB11369EB, v108);
  v110 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v111 = UFG::qResourceWarehouse::Instance();
    v110 = UFG::qResourceWarehouse::GetInventory(v111, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v110;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDefaultZeroTexture.mPrev, 0x8B43FABF, 0x1C63FB41u, v110);
  v112 = UFG::qStringHash32("ATAN2", 0xFFFFFFFF);
  v113 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v114 = UFG::qResourceWarehouse::Instance();
    v113 = UFG::qResourceWarehouse::GetInventory(v114, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v113;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gArcTanTexture.mPrev, 0x8B43FABF, v112, v113);
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
  v115 = UFG::qResourceWarehouse::Instance();
  v116 = UFG::qResourceWarehouse::GetInventory(v115, 0x8B43FABF);
  v117 = v116;
  v118 = v116->vfptr;
  v119 = UFG::qStringHashUpper32(gDepthVolumeTexture, 0xFFFFFFFF);
  v120 = (__int64)v118->Get(v117, v119);
  v121 = v120;
  if ( v120 )
  {
    v122 = *(_QWORD *)(v120 + 112);
    if ( v122 )
      v0 = (UFG::qResourceHandle *)(v122 + v121 + 112);
    v123 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v124 = UFG::qResourceWarehouse::Instance();
      v123 = UFG::qResourceWarehouse::GetInventory(v124, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v123;
    }
    UFG::qResourceHandle::Init(v0 + 1, 0x3BC715E0u, 0x20688F05u, v123);
  }
  Render::CloudVolumeManager::Init(&Render::gCloudVolumeManager, v25);
  InitBackBufferToPresentBuffer();
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]] = UFG::TestDynamicSceneryForDecals;
  ++dword_14203EF28[0];
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]] = UFG::TestSceneryGroupForDecals;
  ++dword_14203EF28[0];
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]] = UFG::TestCompositeDrawableForDecals;
  ++dword_14203EF28[0];
  Render::gDecalManager.mTestSceneryCallback[dword_14203EF28[0]] = Render::TestSimpleDrawableForDecals;
  ++dword_14203EF28[0];
}

// File Line: 1025
// RVA: 0x56A70
void __fastcall RenderMouse(Render::View *view)
{
  Render::View *v1; // rdi
  unsigned int v2; // eax
  unsigned int v3; // ebx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::Controller *v6; // rcx
  UFG::WayFinderClient *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  float v11; // xmm9_4
  UFG::WayGraph *v12; // rdx
  signed __int16 v13; // ax
  float v14; // xmm14_4
  float v15; // xmm0_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  UFG::qVector2 p1; // [rsp+30h] [rbp-B8h]
  UFG::qVector2 p0; // [rsp+38h] [rbp-B0h]
  __int64 v20; // [rsp+40h] [rbp-A8h]
  Render::Poly poly; // [rsp+F8h] [rbp+10h]
  UFG::qVector2 p3; // [rsp+100h] [rbp+18h]
  UFG::qVector2 p2; // [rsp+108h] [rbp+20h]

  v20 = -2i64;
  v1 = view;
  v2 = _S15;
  if ( !(_S15 & 1) )
  {
    _S15 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gCursorTextureHandle.mPrev);
    atexit(RenderMouse_::_2_::_dynamic_atexit_destructor_for__gCursorTextureHandle__);
    v2 = _S15;
  }
  if ( !gCursorTextureHandleInitialized )
  {
    if ( v2 & 2 )
    {
      v3 = uidDefaultCursor;
    }
    else
    {
      _S15 = v2 | 2;
      v3 = UFG::qStringHashUpper32("DefaultCursor", 0xFFFFFFFF);
      uidDefaultCursor = v3;
    }
    v4 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v4;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gCursorTextureHandle.mPrev, 0x8B43FABF, v3, v4);
  }
  if ( gCursorTextureHandle.mData )
  {
    v6 = UFG::gInputSystem->mControllers[0];
    if ( v6 )
    {
      v7 = (UFG::WayFinderClient *)&v6->mInputState;
      if ( UFG::InputState::IsMouseVisible(&v6->mInputState) )
      {
        Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
        v8 = (float)Render::GetBackBufferTarget()->mWidth;
        v9 = (float)Render::GetBackBufferTarget()->mHeight;
        v10 = (float)WORD2(gCursorTextureHandle.mData[1].mNode.mChild[0]);
        v11 = (float)HIWORD(gCursorTextureHandle.mData[1].mNode.mChild[0]);
        v13 = UFG::WayFinderClient::GetWayEdge(v7, v12);
        v14 = (float)v13 * (float)(1.0 / v8);
        v15 = (float)(signed __int16)UFG::WayFinderClient::GetWayNode(v7, (UFG::WayGraph *)(unsigned int)v13)
            * (float)(1.0 / v9);
        v16 = (float)(1.0 / v8) * v10;
        v17 = (float)(1.0 / v9) * v11;
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
          Render::View::Draw(v1, &poly, gCursorTextureHandle.mNameUID, 0i64, 0x62F81854u, 0);
        }
      }
    }
  }
}

// File Line: 1160
// RVA: 0x56E30
void __fastcall RenderPlanarReflectionDebug(Render::View *view, UFG::RenderContext *render_context)
{
  UFG::Reflection *v2; // r15
  Render::View *v3; // r12
  Render::DebugDrawContext *v4; // rdi
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::qVector3 world_position; // [rsp+48h] [rbp-19h]
  UFG::qVector3 p1; // [rsp+58h] [rbp-9h]
  UFG::DrawInfo info; // [rsp+68h] [rbp+7h]

  v2 = render_context->mReflection;
  v3 = view;
  if ( gShowPlanarReflectionDbg )
  {
    if ( v2 )
    {
      v4 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
      v5 = v2->mVolume.mPosMinWorld.z + (float)((float)(v2->mVolume.mPosMaxWorld.z - v2->mVolume.mPosMinWorld.z) * 0.5);
      v6 = v2->mVolume.mPosMaxWorld.y;
      v7 = v2->mVolume.mPosMinWorld.z;
      v8 = v2->mVolume.mPosMinWorld.y + (float)((float)(v2->mVolume.mPosMaxWorld.y - v2->mVolume.mPosMinWorld.y) * 0.5);
      v9 = v2->mVolume.mPosMaxWorld.x;
      world_position.x = v2->mVolume.mPosMinWorld.x
                       + (float)((float)(v2->mVolume.mPosMaxWorld.x - v2->mVolume.mPosMinWorld.x) * 0.5);
      v10 = v2->mVolume.mPosMaxWorld.z;
      world_position.z = v5;
      v11 = v2->mVolume.mPosMinWorld.y;
      world_position.y = v8;
      v12 = v2->mVolume.mPosMinWorld.x;
      *(double *)&world_position.z = v10;
      *(double *)&world_position.x = v6;
      Render::DebugDrawContext::DrawText(
        v4,
        &world_position,
        &UFG::qColour::White,
        "Planar reflection: %s\nAABB: %f,%f,%f - %f,%f,%f",
        v2->mName,
        v12,
        v11,
        v7,
        v9,
        v6,
        v10);
      Render::DebugDrawContext::DrawTextA(v4, 5, 5, &UFG::qColour::White, "Planar reflection %s", v2->mName);
      info.mAlphaBlend = -1551679522;
      *(_WORD *)&info.mDepthBuffer = 256;
      info.mDepthBias = 0;
      info.mPreDrawCallback = 0i64;
      info.mColour1 = UFG::qColour::White;
      LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
      info.mColour2 = UFG::qColour::White;
      Render::View::DrawBox(
        v3,
        &v2->mVolume.mPosMinWorld,
        &v2->mVolume.mPosMaxWorld,
        &info,
        &UFG::qMatrix44::msIdentity);
      v13 = v2->mPlane.mPosition.y + v2->mPlane.mNormal.y;
      p1.x = v2->mPlane.mNormal.x + v2->mPlane.mPosition.x;
      v14 = v2->mPlane.mPosition.z + v2->mPlane.mNormal.z;
      p1.y = v13;
      p1.z = v14;
      Render::View::DrawArrow(v3, &v2->mPlane.mPosition, &p1, &info, &UFG::qMatrix44::msIdentity);
    }
  }
}

// File Line: 1375
// RVA: 0x53C40
void __fastcall RenderDebugOverlay(UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::RenderContext *v3; // rsi
  AMD_HD3D *v4; // rax
  __int64 v5; // r8
  unsigned int v6; // ebx
  UFG::PartCompositeBuilder *v7; // rax
  unsigned int v8; // ebx
  Render::Poly poly; // [rsp+70h] [rbp+8h]

  v2 = view;
  v3 = render_context;
  v4 = (AMD_HD3D *)CullManager::Instance();
  v5 = (unsigned int)v3->mMainViewSettings.mCullIndex;
  _(v4);
  if ( g_renderMouse && !UFG::InputSystem::msShouldHideCursor )
    RenderMouse(v2);
  UFG::RenderStageEnvMap::RenderDebugOverlay(UFG::RenderWorld::msStageEnvMap, v3, v2);
  if ( UFG::RenderWorld::msStageShadow->mDrawDebugShadowMap && v3->mRenderFeatures.mWorld )
    UFG::RenderStageShadow::RenderDebugOverlay(UFG::RenderWorld::msStageShadow, v3, v2, 20, 20, 250);
  if ( UFG::RenderWorld::msStageSpotShadow->mDrawDebugSpotShadowMap && v3->mRenderFeatures.mWorld )
    UFG::RenderStageSpotShadow::RenderDebugSpotShadowOverlay(UFG::RenderWorld::msStageSpotShadow, v3, v2, 20, 20, 250);
  if ( UFG::RenderWorld::msCalibrationDisplay )
  {
    v6 = UFG::qStringHash32("CALIBRATION", 0xFFFFFFFF);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(v2, &poly, v6, 0i64, 0, 0);
  }
  RenderPlanarReflectionDebug(v2, v3);
  v7 = UFG::PartCompositeBuilder::Instance();
  UFG::PartCompositeBuilder::RenderDebugOverlay(v7, v2);
  if ( gDebugTextureUID )
  {
    Render::Poly::Poly(&poly, 0.0, 0.0, 0.140625, 0.25, 0.0);
    Render::View::Draw(v2, &poly, gDebugTextureUID, 0i64, 0, 0);
  }
  if ( gDebugVolumeTextureUID )
  {
    Render::View::SetSimpleMaterialShader(0x53F37232u);
    Render::Poly::Poly(&poly, 0.1, 0.1, 0.140625, 0.25, 0.0);
    Render::View::Draw(v2, &poly, gDebugVolumeTextureUID, 0i64, 0, 0);
    Render::View::SetSimpleMaterialShader(0x3141335Cu);
  }
  v8 = Render::gCloudVolumeManager.mVolumeTextureUID;
  if ( (unsigned int)UFG::qStringHashUpper32("cloudvolumetex", 0xFFFFFFFF) != v8 )
  {
    Render::View::SetSimpleMaterialShader(0x53F37232u);
    Render::Poly::Poly(&poly, 0.1, 0.80000001, 0.1, 0.17777778, 0.0);
    Render::View::Draw(v2, &poly, Render::gCloudVolumeManager.mVolumeTextureUID, 0i64, 0, 0);
    Render::View::SetSimpleMaterialShader(0x3141335Cu);
  }
  UFG::RenderStageExposureMetering::RenderDebug(UFG::RenderWorld::msExposureMetering, v3, v2);
}

// File Line: 1542
// RVA: 0x58600
void __fastcall RenderScaleformCallback(unsigned int *param)
{
  Scaleform::Ptr<Scaleform::Render::Renderer2D> *v1; // rax
  Scaleform::Ptr<Scaleform::Render::Renderer2D> *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // [rsp+48h] [rbp+10h]

  v1 = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
         (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
         (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v3);
  Scaleform::Render::Renderer2D::BeginFrame(v1->pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->render)();
  v2 = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
         (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
         (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v3);
  Scaleform::Render::Renderer2D::EndFrame(v2->pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
}

// File Line: 1558
// RVA: 0x56D80
void __fastcall RenderMoviesOffscreen(UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v1; // rbx
  RenderQueueLayer v2; // [rsp+30h] [rbp-D68h]
  LayerSubmitContext ptr; // [rsp+110h] [rbp-C88h]

  v1 = serialization_list;
  RenderQueueLayer::RenderQueueLayer(&v2);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v2.mSerializationList = v1;
  ptr.mRenderQueueProvider = &v2;
  ptr.mQueueMode = 0;
  UFG::MovieHandler::RenderOffScreen(&UFG::TheMovieHandler, (Illusion::SubmitContext *)&ptr.vfptr);
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
  UFG::qVector3 *v1; // rbx
  UFG::qBaseNodeRB *v2; // r8
  unsigned int v3; // er10
  unsigned int v4; // edx
  UFG::qBaseNodeRB *v5; // r9
  float v6; // xmm1_4
  __int64 v7; // rcx
  signed __int64 v8; // rax
  UFG::Reflection *result; // rax
  float v10; // xmm0_4
  float v11; // xmm0_4

  v1 = camPos;
  v2 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9760);
  if ( !v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = v2[2].mUID;
    v4 = 0;
    if ( v3 )
      break;
LABEL_14:
    v2 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9760, v2);
    if ( !v2 )
      return 0i64;
  }
  v5 = v2[3].mParent;
  v6 = v1->x;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (signed __int64)(v5 ? (UFG::qBaseNodeRB *)((char *)&v2[3] + (_QWORD)v5) : 0i64);
    result = (UFG::Reflection *)(v7 + v8);
    if ( v6 >= result->mVolume.mPosMinWorld.x && v6 <= result->mVolume.mPosMaxWorld.x )
    {
      v10 = v1->y;
      if ( v10 >= result->mVolume.mPosMinWorld.y && v10 <= result->mVolume.mPosMaxWorld.y )
      {
        v11 = v1->z;
        if ( v11 >= result->mVolume.mPosMinWorld.z && v11 <= result->mVolume.mPosMaxWorld.z )
          return result;
      }
    }
    ++v4;
    v7 += 224i64;
    if ( v4 >= v3 )
      goto LABEL_14;
  }
}

// File Line: 1602
// RVA: 0x570A0
void __fastcall RenderPlanarReflectionMap(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  UFG::RenderContext *v3; // r14
  UFG::Reflection *v4; // rsi
  float v5; // xmm10_4
  int v6; // xmm2_4
  float v7; // xmm9_4
  int v8; // xmm1_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  UFG::qMatrix44 *v15; // rax
  UFG::qMatrix44 *v16; // rax
  int v17; // xmm9_4
  int v18; // xmm8_4
  int v19; // xmm6_4
  float v20; // xmm7_4
  UFG::qMatrix44 *v21; // rax
  float v22; // xmm11_4
  float v23; // xmm12_4
  float v24; // xmm13_4
  float v25; // xmm14_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  char *v29; // rdi
  int v30; // xmm7_4
  int v31; // xmm3_4
  int v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm8_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm6_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  Illusion::StateArgs *v49; // rax
  char *v50; // rbx
  char *v51; // r15
  char *v52; // r12
  unsigned __int16 v53; // ax
  Illusion::StateArgs *v54; // rax
  UFG::qResourceData *v55; // rbx
  Illusion::StateValues *v56; // rax
  Illusion::Texture *v57; // rbx
  Illusion::StateValues *v58; // rax
  Illusion::StateValues *v59; // rax
  float v60; // xmm7_4
  float v61; // xmm6_4
  char *v62; // rbx
  Illusion::StateValues *v63; // rax
  UFG::qResourceData *v64; // rbx
  Illusion::StateValues *v65; // rax
  Illusion::Texture *v66; // rbx
  Illusion::StateValues *v67; // rax
  Illusion::Texture *v68; // rbx
  Illusion::StateValues *v69; // rax
  CB_WaterOffset *v70; // rbx
  Illusion::StateValues *v71; // rax
  char *v72; // rbx
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float v78; // xmm3_4
  float v79; // xmm1_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm3_4
  Illusion::StateValues *v85; // rax
  UFG::qResourceWarehouse *v86; // rax
  UFG::qResourceInventory *v87; // rbx
  UFG::qResourceInventoryVtbl *v88; // rdi
  unsigned int v89; // eax
  __int64 v90; // rbx
  Illusion::StateValues *v91; // rax
  float *v92; // rax
  float *v93; // rbx
  Illusion::StateValues *v94; // rax
  char *v95; // rax
  unsigned int v96; // ebx
  UFG::qResourceInventory *v97; // rax
  UFG::qResourceWarehouse *v98; // rax
  UFG::qResourceInventory *v99; // rax
  UFG::qResourceWarehouse *v100; // rax
  UFG::DynamicSceneryInstance *v101; // rcx
  Render::ViewSettings *v102; // rdx
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v103; // rbx
  __int64 v104; // rax
  float v105; // xmm0_4
  float v106; // xmm0_4
  float v107; // xmm0_4
  UFG::CompositeDrawableComponent *v108; // rbx
  UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *v109; // rdi
  CullResults *v110; // rcx
  __int64 v111; // rax
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  CullInfo *v115; // rax
  int v116; // eax
  Illusion::StateArgs *v117; // r8
  __int64 v118; // rdx
  _QWORD *v119; // rcx
  Illusion::StateArgs *v120; // r8
  __int64 v121; // rdx
  _QWORD *v122; // rcx
  __int64 v123; // rcx
  _QWORD *v124; // rax
  __int64 v125; // rcx
  _QWORD *v126; // rax
  char *v127; // rax
  UFG::qMatrix44 v128; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 b; // [rsp+90h] [rbp-70h]
  UFG::qMatrix44 v130; // [rsp+D0h] [rbp-30h]
  char *v131; // [rsp+110h] [rbp+10h]
  char *v132; // [rsp+118h] [rbp+18h]
  __int64 v133; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 v134; // [rsp+130h] [rbp+30h]
  UFG::qMatrix44 dest; // [rsp+170h] [rbp+70h]
  UFG::qResourceData *v136; // [rsp+1B0h] [rbp+B0h]
  UFG::qResourceData *v137; // [rsp+1B8h] [rbp+B8h]
  __int64 v138; // [rsp+1C0h] [rbp+C0h]
  Render::ViewSettings settings; // [rsp+1D0h] [rbp+D0h]
  Render::View view; // [rsp+260h] [rbp+160h]
  UFG::qMatrix44 v141; // [rsp+3F0h] [rbp+2F0h]
  UFG::qMatrix44 m; // [rsp+430h] [rbp+330h]
  RenderQueueLayer v143; // [rsp+470h] [rbp+370h]
  UFG::qMatrix44 d; // [rsp+550h] [rbp+450h]
  UFG::qMatrix44 result; // [rsp+590h] [rbp+490h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+5D0h] [rbp+4D0h]
  ForwardReflectedSubmitContext ptr; // [rsp+7D0h] [rbp+6D0h]
  Render::CullMetrics cull_metrics; // [rsp+1530h] [rbp+1430h]

  v138 = -2i64;
  v2 = serialization_list;
  v3 = render_context;
  if ( render_context->mReflection && gRenderPlanarReflections )
  {
    RenderQueueLayer::RenderQueueLayer(&v143);
    ForwardReflectedSubmitContext::ForwardReflectedSubmitContext(&ptr);
    v143.mSerializationList = v2;
    ptr.mRenderQueueProvider = &v143;
    v137 = AlphaStateNoneHandle.mData;
    v136 = RasterStateNormalHandle.mData;
    ptr.mPerPhaseParams = (ForwardReflectedSubmitContext::PerPhaseParams *)&v136;
    ptr.mQueueMode = 2;
    UFG::qInverseAffine(&d, &v3->mMainViewSettings.mWorldView);
    v4 = v3->mReflection;
    v128.v0 = UFG::qMatrix44::msIdentity.v0;
    v128.v1 = UFG::qMatrix44::msIdentity.v1;
    v128.v2.x = UFG::qMatrix44::msIdentity.v2.x;
    v128.v2.y = UFG::qMatrix44::msIdentity.v2.y;
    v128.v2.z = UFG::qMatrix44::msIdentity.v2.z;
    v128.v2.w = UFG::qMatrix44::msIdentity.v2.w;
    v5 = v4->mPlane.mPosition.z;
    v6 = LODWORD(v4->mPlane.mPosition.z) ^ _xmm[0];
    v7 = v4->mPlane.mPosition.y;
    v8 = LODWORD(v4->mPlane.mPosition.y) ^ _xmm[0];
    v9 = v4->mPlane.mPosition.x;
    LODWORD(v128.v3.x) = LODWORD(v4->mPlane.mPosition.x) ^ _xmm[0];
    LODWORD(v128.v3.y) = v8;
    LODWORD(v128.v3.z) = v6;
    v128.v3.w = 1.0;
    v10 = v4->mPlane.mNormal.y;
    v11 = v4->mPlane.mNormal.x;
    v12 = v11 * v11;
    v13 = v4->mPlane.mNormal.z;
    b.v0.x = (float)((float)(v10 * v10) - (float)(v11 * v11)) + (float)(v13 * v13);
    v14 = v11 * -2.0;
    b.v0.y = v14 * v10;
    b.v0.z = v14 * v13;
    b.v0.w = 0.0;
    b.v1.x = v14 * v10;
    b.v1.y = (float)(v12 - (float)(v10 * v10)) + (float)(v13 * v13);
    b.v1.z = (float)(v10 * -2.0) * v13;
    b.v1.w = 0.0;
    b.v2.x = v14 * v13;
    b.v2.y = (float)(v10 * -2.0) * v13;
    b.v2.z = (float)(v12 + (float)(v10 * v10)) - (float)(v13 * v13);
    b.v2.w = 0.0;
    *(UFG::qVector3 *)&b.v3.x = UFG::qVector3::msZero;
    b.v3.w = 1.0;
    v134.v0 = UFG::qMatrix44::msIdentity.v0;
    v134.v1 = UFG::qMatrix44::msIdentity.v1;
    v134.v2.x = UFG::qMatrix44::msIdentity.v2.x;
    v134.v2.y = UFG::qMatrix44::msIdentity.v2.y;
    v134.v2.z = UFG::qMatrix44::msIdentity.v2.z;
    v134.v2.w = UFG::qMatrix44::msIdentity.v2.w;
    v134.v3.x = v9;
    v134.v3.y = v7;
    v134.v3.z = v5;
    v134.v3.w = 1.0;
    v15 = UFG::qMatrix44::operator*(&v128, &result, &b);
    v16 = UFG::qMatrix44::operator*(v15, &v130, &v134);
    UFG::qMatrix44::operator*(v16, &v128, &v3->mMainViewSettings.mWorldView);
    v17 = LODWORD(v4->mPlane.mNormal.z) ^ _xmm[0];
    v18 = LODWORD(v4->mPlane.mNormal.y) ^ _xmm[0];
    v19 = LODWORD(v4->mPlane.mNormal.x) ^ _xmm[0];
    LODWORD(v20) = COERCE_UNSIGNED_INT(
                     (float)((float)(*(float *)&v18 * v4->mPlane.mPosition.y)
                           + (float)(*(float *)&v19 * v4->mPlane.mPosition.x))
                   + (float)(*(float *)&v17 * v4->mPlane.mPosition.z)) ^ _xmm[0];
    v21 = UFG::qMatrix44::operator*(&v3->mMainViewSettings.mWorldView, &v130, &v3->mMainViewSettings.mProjection);
    UFG::qInverse(&m, v21);
    UFG::qTranspose(&dest, &m);
    v22 = (float)((float)((float)(dest.v0.x * *(float *)&v19) + (float)(*(float *)&v18 * dest.v1.x))
                + (float)(*(float *)&v17 * dest.v2.x))
        + (float)(dest.v3.x * v20);
    v23 = (float)((float)((float)(dest.v0.y * *(float *)&v19) + (float)(*(float *)&v18 * dest.v1.y))
                + (float)(*(float *)&v17 * dest.v2.y))
        + (float)(dest.v3.y * v20);
    v24 = (float)((float)((float)(dest.v0.z * *(float *)&v19) + (float)(*(float *)&v18 * dest.v1.z))
                + (float)(*(float *)&v17 * dest.v2.z))
        + (float)(dest.v3.z * v20);
    v25 = (float)((float)((float)(dest.v0.w * *(float *)&v19) + (float)(*(float *)&v18 * dest.v1.w))
                + (float)(*(float *)&v17 * dest.v2.w))
        + (float)(dest.v3.w * v20);
    v26 = (float)v3->mReflectionTarget->mWidth / (float)v3->mReflectionTarget->mHeight;
    v27 = v3->mMainViewSettings.mProjection.v0.x;
    if ( v27 == 0.0 )
      v28 = 0.0;
    else
      v28 = atan2f(1.0, v27) * 2.0;
    UFG::qPerspectiveMatrix(&v141, v28, v26, 0.30000001, 50.0);
    settings.mWorldView = v128;
    settings.mProjection = v141;
    settings.mCullIndex = -1;
    settings.mCullPixelDensityThreshold = v3->mMainViewSettings.mCullPixelDensityThreshold;
    settings.mCullPixelDistanceBias = v3->mMainViewSettings.mCullPixelDistanceBias;
    Render::View::View(&view, &settings, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&view, v3->mReflectionTarget, "PlanarReflection", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 3u, 1.0, 0);
    if ( gReflectionFadeCube.mData )
    {
      *(_QWORD *)&v134.v0.x = 0i64;
      *(_QWORD *)&v134.v0.z = 0i64;
      v134.v2.x = 0.0;
      *(_QWORD *)&v134.v1.z = -1i64;
      *(_QWORD *)&v134.v1.x = -34360000513i64;
      ptr.mShaderSelector = (Illusion::ShaderSelector *)&v134;
      v29 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
      UFG::qMemCopy(v29, v3->mEnvState, 0x100u);
      if ( v4->mFlags & 1 )
      {
        v30 = SLODWORD(v4->mLightDirectionOverride.x);
        v31 = SLODWORD(v4->mLightDirectionOverride.y);
        v32 = SLODWORD(v4->mLightDirectionOverride.z);
      }
      else
      {
        v32 = *((_DWORD *)v29 + 6) ^ _xmm[0];
        v31 = *((_DWORD *)v29 + 5) ^ _xmm[0];
        v30 = *((_DWORD *)v29 + 4) ^ _xmm[0];
      }
      v33 = (float)((float)(*(float *)&v31 * *(float *)&v31) + (float)(*(float *)&v30 * *(float *)&v30))
          + (float)(*(float *)&v32 * *(float *)&v32);
      if ( v33 == 0.0 )
        v34 = 0.0;
      else
        v34 = 1.0 / fsqrt(v33);
      v35 = v34 * *(float *)&v32;
      v36 = v34 * *(float *)&v31;
      v37 = *(float *)&v30 * v34;
      v38 = (float)((float)((float)(v34 * *(float *)&v31) * b.v1.x) + (float)(v37 * b.v0.x))
          + (float)((float)(v34 * *(float *)&v32) * b.v2.x);
      v39 = (float)((float)((float)(v34 * *(float *)&v31) * b.v1.y) + (float)(v37 * b.v0.y)) + (float)(v35 * b.v2.y);
      v40 = (float)((float)(v36 * b.v1.z) + (float)(v37 * b.v0.z)) + (float)(v35 * b.v2.z);
      *((float *)v29 + 4) = v38;
      *((float *)v29 + 5) = v39;
      *((float *)v29 + 6) = v40;
      *((_DWORD *)v29 + 7) = 0;
      v41 = (float)((float)((float)(v36 * view.mSettings->mWorldView.v1.x)
                          + (float)(v37 * view.mSettings->mWorldView.v0.x))
                  + (float)(v35 * view.mSettings->mWorldView.v2.x))
          + (float)(view.mSettings->mWorldView.v3.x * 0.0);
      v42 = (float)((float)((float)(v36 * view.mSettings->mWorldView.v1.y)
                          + (float)(v37 * view.mSettings->mWorldView.v0.y))
                  + (float)(v35 * view.mSettings->mWorldView.v2.y))
          + (float)(view.mSettings->mWorldView.v3.y * 0.0);
      v43 = (float)((float)((float)(v36 * view.mSettings->mWorldView.v1.z)
                          + (float)(v37 * view.mSettings->mWorldView.v0.z))
                  + (float)(v35 * view.mSettings->mWorldView.v2.z))
          + (float)(view.mSettings->mWorldView.v3.z * 0.0);
      v44 = (float)((float)((float)(v36 * view.mSettings->mWorldView.v1.w)
                          + (float)(v37 * view.mSettings->mWorldView.v0.w))
                  + (float)(v35 * view.mSettings->mWorldView.v2.w))
          + (float)(view.mSettings->mWorldView.v3.w * 0.0);
      *(float *)v29 = v41;
      *((float *)v29 + 1) = v42;
      *((float *)v29 + 2) = v43;
      *((float *)v29 + 3) = v44;
      if ( v4->mFlags & 2 )
      {
        v45 = v4->mLightColorOverride.y;
        v46 = v4->mLightColorOverride.z;
        *((_DWORD *)v29 + 8) = LODWORD(v4->mLightColorOverride.x);
        *((float *)v29 + 9) = v45;
        *((float *)v29 + 10) = v46;
        *((_DWORD *)v29 + 11) = 0;
      }
      v47 = v4->mAmbientColor.y;
      v48 = v4->mAmbientColor.z;
      *((_DWORD *)v29 + 12) = LODWORD(v4->mAmbientColor.x);
      *((float *)v29 + 13) = v47;
      *((float *)v29 + 14) = v48;
      *((_DWORD *)v29 + 15) = 1065353216;
      *((_DWORD *)v29 + 40) = 0;
      *((float *)v29 + 41) = gPlanarFogEnd;
      Render::cbExternalViewTransformState::cbExternalViewTransformState(
        (Render::cbExternalViewTransformState *)&v128,
        &view.mSettings->mWorldView,
        &view.mSettings->mProjection);
      v49 = Render::View::GetStateArgs(&view);
      Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v49, (Render::cbExternalViewTransformState *)&v128);
      UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
      v50 = (char *)UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
      v51 = (char *)UFG::RenderWorld::msStageShadow->mBiases;
      v52 = (char *)UFG::RenderWorld::msStageShadow->mCutplanes;
      *(_QWORD *)&v130.v0.x = &v130;
      *(_QWORD *)&v130.v0.z = &v130;
      *(_QWORD *)&v130.v1.x = 0i64;
      LOWORD(v130.v1.z) = Render::cbShadowTransformState::sStateParamIndex;
      HIWORD(v130.v1.z) = 1;
      if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
      {
        v53 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
        Render::cbShadowTransformState::sStateParamIndex = v53;
        LOWORD(v130.v1.z) = v53;
      }
      *(_QWORD *)&v130.v2.x = (char *)&view + 320;
      *(_QWORD *)&v130.v2.z = &views;
      *(_QWORD *)&v130.v3.x = (char *)&views + 256;
      *(_QWORD *)&v130.v3.z = v52;
      v131 = v51;
      v132 = v50;
      v133 = 0i64;
      v54 = Render::View::GetStateArgs(&view);
      Illusion::StateArgs::Set<Render::cbShadowTransformState>(v54, (Render::cbShadowTransformState *)&v130);
      v55 = gReflectionFadeCube.mData;
      v56 = Render::View::GetStateValues(&view);
      v56->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
      v56->mParamValues[41] = v55;
      v57 = v3->mEnvCubeMap->mTarget->mTargetTexture[0];
      v58 = Render::View::GetStateValues(&view);
      v58->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
      v58->mParamValues[40] = v57;
      v59 = Render::View::GetStateValues(&view);
      v59->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
      v59->mParamValues[55] = v29;
      v60 = UFG::Metrics::msInstance.mSimTimeDelta;
      v61 = UFG::Metrics::msInstance.mSimTime_Temp;
      v62 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *(float *)v62 = v61;
      *((float *)v62 + 1) = v60;
      v63 = Render::View::GetStateValues(&view);
      v63->mSetValueMask.mFlags[0] |= 0x2000ui64;
      v63->mParamValues[13] = v62;
      v64 = gArcTanTexture.mData;
      v65 = Render::View::GetStateValues(&view);
      v65->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
      v65->mParamValues[43] = v64;
      v66 = v3->mHalfSizeShadowAliasTexture;
      v67 = Render::View::GetStateValues(&view);
      v67->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
      v67->mParamValues[61] = v66;
      v68 = UFG::Water::GetRippleMap(1);
      v69 = Render::View::GetStateValues(&view);
      v69->mSetValueMask.mFlags[0] |= 0x800000000000000ui64;
      v69->mParamValues[59] = v68;
      v70 = UFG::Water::GetWaterSettings();
      v71 = Render::View::GetStateValues(&view);
      v71->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
      v71->mParamValues[45] = v70;
      v72 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      v73 = UFG::qVector4::msOne.y;
      v74 = UFG::qVector4::msOne.z;
      v75 = UFG::qVector4::msOne.w;
      *(float *)v72 = UFG::qVector4::msOne.x;
      *((float *)v72 + 1) = v73;
      *((float *)v72 + 2) = v74;
      *((float *)v72 + 3) = v75;
      v76 = UFG::qVector4::msOne.y;
      v77 = UFG::qVector4::msOne.z;
      v78 = UFG::qVector4::msOne.w;
      *((_DWORD *)v72 + 4) = LODWORD(UFG::qVector4::msOne.x);
      *((float *)v72 + 5) = v76;
      *((float *)v72 + 6) = v77;
      *((float *)v72 + 7) = v78;
      v79 = UFG::qVector4::msZero.y;
      v80 = UFG::qVector4::msZero.z;
      v81 = UFG::qVector4::msZero.w;
      *((_DWORD *)v72 + 12) = LODWORD(UFG::qVector4::msZero.x);
      *((float *)v72 + 13) = v79;
      *((float *)v72 + 14) = v80;
      *((float *)v72 + 15) = v81;
      v82 = UFG::qVector4::msZero.y;
      v83 = UFG::qVector4::msZero.z;
      v84 = UFG::qVector4::msZero.w;
      *((_DWORD *)v72 + 8) = LODWORD(UFG::qVector4::msZero.x);
      *((float *)v72 + 9) = v82;
      *((float *)v72 + 10) = v83;
      *((float *)v72 + 11) = v84;
      v85 = Render::View::GetStateValues(&view);
      v85->mSetValueMask.mFlags[0] |= 0x400000000ui64;
      v85->mParamValues[34] = v72;
      v86 = UFG::qResourceWarehouse::Instance();
      v87 = UFG::qResourceWarehouse::GetInventory(v86, 0x8B43FABF);
      v88 = v87->vfptr;
      v89 = UFG::qStringHashUpper32(v3->mReflection->mName, 0xFFFFFFFF);
      v90 = (__int64)v88->Get(v87, v89);
      if ( !v90 )
        v90 = (__int64)v3->mSphericalEnvMapTarget->mTargetTexture[0];
      v91 = Render::View::GetStateValues(&view);
      v91->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
      v91->mParamValues[58] = (void *)v90;
      v92 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      v93 = v92;
      *v92 = v22;
      v92[1] = v23;
      v92[2] = v24;
      v92[3] = v25;
      v94 = Render::View::GetStateValues(&view);
      v94->mSetValueMask.mFlags[0] |= 0x100000000ui64;
      v94->mParamValues[32] = v93;
      v95 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x64u, 4u);
      cull_metrics = (Render::CullMetrics)v95;
      if ( v95 )
        *(_DWORD *)v95 = 1;
      else
        v95 = 0i64;
      *((float *)v95 + 1) = v22;
      *((float *)v95 + 2) = v23;
      *((float *)v95 + 3) = v24;
      *((float *)v95 + 4) = v25;
      LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&ptr.vfptr, 24, 0, v95);
      if ( v4->mSceneryGroupUID )
      {
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&b);
        v96 = v4->mSceneryGroupUID;
        v97 = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
        {
          v98 = UFG::qResourceWarehouse::Instance();
          v97 = UFG::qResourceWarehouse::GetInventory(v98, 0xF0A07244);
          `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = v97;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&b, 0xF0A07244, v96, v97);
        if ( *(_QWORD *)&b.v1.x )
          UFG::SceneryGroupComponent::Draw(*(UFG::SceneryGroupComponent **)(*(_QWORD *)&b.v1.x + 136i64), &view);
        v99 = `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result )
        {
          v100 = UFG::qResourceWarehouse::Instance();
          v99 = UFG::qResourceWarehouse::GetInventory(v100, 0xF0A07244);
          `UFG::qGetResourceInventory<UFG::SceneryGroup>::`2::result = v99;
        }
        UFG::qResourceHandle::Close((UFG::qResourceHandle *)&b, v99);
        UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&b);
      }
      v101 = (UFG::DynamicSceneryInstance *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
      v102 = view.mSettings;
      if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
      {
        do
        {
          v103 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&v101->mNext[-6].mNext;
          if ( (v101->m_Flags & 3) == 1 )
          {
            v104 = v102->mCullIndex;
            if ( (signed int)v104 >= 6
              || v101->mCullResults->mDistance[v104] < 20.0
              || (v105 = v101->mLocalWorld.v3.x, v105 >= v4->mVolume.mPosMinWorld.x)
              && v105 <= v4->mVolume.mPosMaxWorld.x
              && (v106 = v101->mLocalWorld.v3.y, v106 >= v4->mVolume.mPosMinWorld.y)
              && v106 <= v4->mVolume.mPosMaxWorld.y
              && (v107 = v101->mLocalWorld.v3.z, v107 >= v4->mVolume.mPosMinWorld.z)
              && v107 <= v4->mVolume.mPosMaxWorld.z )
            {
              if ( (float)((float)((float)((float)(v101->mLocalWorld.v3.y - v4->mPlane.mPosition.y)
                                         * v4->mPlane.mNormal.y)
                                 + (float)((float)(v101->mLocalWorld.v3.x - v4->mPlane.mPosition.x)
                                         * v4->mPlane.mNormal.x))
                         + (float)((float)(v101->mLocalWorld.v3.z - v4->mPlane.mPosition.z) * v4->mPlane.mNormal.z)) > -0.050000001 )
              {
                UFG::DynamicSceneryInstance::Draw(v101, &view);
                v102 = view.mSettings;
              }
            }
          }
          v101 = (UFG::DynamicSceneryInstance *)v103;
        }
        while ( v103 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                                  - 88) );
      }
      v108 = (UFG::CompositeDrawableComponent *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
      {
        do
        {
          v109 = (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)&v108->mNext[-6].mNext;
          if ( (v108->m_Flags & 3) == 1 && !v108->mIsHidden )
          {
            v110 = v108->mCullResults;
            if ( v110 )
            {
              v111 = v102->mCullIndex;
              if ( (signed int)v111 >= 6
                || v110->mDistance[v111] < 20.0
                || (v112 = v108->mPoseRootMatrix.v3.x, v112 >= v4->mVolume.mPosMinWorld.x)
                && v112 <= v4->mVolume.mPosMaxWorld.x
                && (v113 = v108->mPoseRootMatrix.v3.y, v113 >= v4->mVolume.mPosMinWorld.y)
                && v113 <= v4->mVolume.mPosMaxWorld.y
                && (v114 = v108->mPoseRootMatrix.v3.z, v114 >= v4->mVolume.mPosMinWorld.z)
                && v114 <= v4->mVolume.mPosMaxWorld.z )
              {
                if ( (float)((float)((float)((float)(v108->mPoseRootMatrix.v3.y - v4->mPlane.mPosition.y)
                                           * v4->mPlane.mNormal.y)
                                   + (float)((float)(v108->mPoseRootMatrix.v3.x - v4->mPlane.mPosition.x)
                                           * v4->mPlane.mNormal.x))
                           + (float)((float)(v108->mPoseRootMatrix.v3.z - v4->mPlane.mPosition.z) * v4->mPlane.mNormal.z)) > -0.050000001 )
                {
                  v115 = v108->mCullInfo;
                  if ( v115 )
                  {
                    if ( Render::GetCullResultsAABB(
                           &view.mWorldViewProjection,
                           view.mExtractedFarPlane,
                           v102->mCullPixelDensityThreshold,
                           v102->mCullPixelDistanceBias,
                           v115,
                           &cull_metrics) <= 1 )
                    {
                      v116 = UFG::CompositeDrawableComponent::GetLOD(v108, cull_metrics.mPixelCoverage);
                      UFG::CompositeDrawableComponent::Draw(v108, &view, v116);
                    }
                    v102 = view.mSettings;
                  }
                }
              }
            }
          }
          v108 = (UFG::CompositeDrawableComponent *)v109;
        }
        while ( v109 != (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) );
      }
      ptr.mShaderSelector = 0i64;
      v117 = Render::View::GetStateArgs(&view);
      v118 = *(_QWORD *)&v128.v0.x;
      v119 = *(_QWORD **)&v128.v0.z;
      *(_QWORD *)(*(_QWORD *)&v128.v0.x + 8i64) = *(_QWORD *)&v128.v0.z;
      *v119 = v118;
      *(_QWORD *)&v128.v0.x = &v128;
      *(_QWORD *)&v128.v0.z = &v128;
      HIBYTE(v128.v1.z) = 0;
      if ( (Illusion::StateArgs *)v117->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v128.v1.z) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v117 + 16 * (SLOWORD(v128.v1.z) + 3i64)) )
        v117->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v128.v1.z) >> 6] &= ~(1i64 << (LOBYTE(v128.v1.z) & 0x3F));
      v120 = Render::View::GetStateArgs(&view);
      v121 = *(_QWORD *)&v130.v0.x;
      v122 = *(_QWORD **)&v130.v0.z;
      *(_QWORD *)(*(_QWORD *)&v130.v0.x + 8i64) = *(_QWORD *)&v130.v0.z;
      *v122 = v121;
      *(_QWORD *)&v130.v0.x = &v130;
      *(_QWORD *)&v130.v0.z = &v130;
      HIBYTE(v130.v1.z) = 0;
      if ( (Illusion::StateArgs *)v120->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v130.v1.z) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v120 + 16 * (SLOWORD(v130.v1.z) + 3i64)) )
        v120->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v130.v1.z) >> 6] &= ~(1i64 << (LOBYTE(v130.v1.z) & 0x3F));
      v123 = *(_QWORD *)&v130.v0.x;
      v124 = *(_QWORD **)&v130.v0.z;
      *(_QWORD *)(*(_QWORD *)&v130.v0.x + 8i64) = *(_QWORD *)&v130.v0.z;
      *v124 = v123;
      *(_QWORD *)&v130.v0.x = &v130;
      *(_QWORD *)&v130.v0.z = &v130;
      v125 = *(_QWORD *)&v128.v0.x;
      v126 = *(_QWORD **)&v128.v0.z;
      *(_QWORD *)(*(_QWORD *)&v128.v0.x + 8i64) = *(_QWORD *)&v128.v0.z;
      *v126 = v125;
      *(_QWORD *)&v128.v0.x = &v128;
      *(_QWORD *)&v128.v0.z = &v128;
    }
    RenderQueueLayer::SerializeRenderQueues(&v143);
    RenderQueueLayer::SerializeDeferredAlpha(&v143);
    Render::View::EndTarget(&view);
    v127 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x64u, 4u);
    cull_metrics = (Render::CullMetrics)v127;
    if ( v127 )
      *(_DWORD *)v127 = 0;
    else
      v127 = 0i64;
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&ptr.vfptr, 24, 0, v127);
    Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    Render::RenderUtilities::Blit(
      &Render::gRenderUtilities,
      v3->mReflectionTarget,
      v3->mReflectionMipTarget,
      0x3141335Cu,
      "<Blit>",
      0,
      1,
      0i64);
    Render::RenderUtilities::RenderMips(&Render::gRenderUtilities, v3->mReflectionMipTarget, 6u, 0xC532D4Bu);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    Render::ViewMetrics::Accumulate(&v3->mRenderStats, &view.mViewMetrics);
    cull_metrics = (Render::CullMetrics)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v143);
  }
}::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v143);
  }
}

// File Line: 1877
// RVA: 0x5D550
void __fastcall UFG::RenderWorld::UpdateViews(float fRealTimeDelta)
{
  Render::ViewSettings *v1; // rdi
  UFG::BaseCameraComponent *v2; // rsi
  Render::DepthOfField::Focus *v3; // rdx
  signed __int64 v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qMatrix44 *v9; // rax
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1
  CullManager *v13; // rax
  Render::RenderCallbacks *v14; // rax
  float v15; // xmm6_4
  UFG::TimeOfDayManager *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  UFG::TimeOfDayManager *v20; // rax
  UFG::qMatrix44 *v21; // rax
  UFG::qVector4 v22; // xmm3
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1
  UFG::qMatrix44 d; // [rsp+30h] [rbp-D8h]
  CullManager::CullSettings view_settings; // [rsp+70h] [rbp-98h]

  v1 = (Render::ViewSettings *)Render::GetRenderCallbacks()->mRenderParam;
  v2 = UFG::Director::Get()->mCurrentCamera;
  if ( v2 )
    v2 = (UFG::BaseCameraComponent *)((char *)v2 + 0x50);
  if ( !gDoFarGroundCapture && v2 )
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
    if ( HIBYTE(v1[6].mWorldView.v0.x) )
    {
      v3 = (Render::DepthOfField::Focus *)&v2->m_NameUID;
    }
    else
    {
      if ( !(_S17 & 1) )
      {
        _S17 |= 1u;
        Render::DepthOfField::Focus::Focus(&defaultFocus);
        atexit(UFG::RenderWorld::UpdateViews_::_13_::_dynamic_atexit_destructor_for__defaultFocus__);
      }
      v3 = &defaultFocus;
    }
    Render::DepthOfField::Set(&Render::gDepthOfField, v3);
  }
  v4 = (signed __int64)&v1[7];
  *(float *)(v4 + 136) = gMainView_CullPixelDistanceBias;
  *(float *)(v4 + 132) = gMainView_CullPixelDensityThreshold;
  v5 = UFG::Camera::GetWorldView((UFG::Camera *)v2);
  v6 = v5->v1;
  v7 = v5->v2;
  v8 = v5->v3;
  *(UFG::qVector4 *)v4 = v5->v0;
  v1[7].mWorldView.v1 = v6;
  v1[7].mWorldView.v2 = v7;
  v1[7].mWorldView.v3 = v8;
  v9 = UFG::Camera::GetViewProjection((UFG::Camera *)v2);
  v10 = v9->v1;
  v11 = v9->v2;
  v12 = v9->v3;
  v1[7].mProjection.v0 = v9->v0;
  v1[7].mProjection.v1 = v10;
  v1[7].mProjection.v2 = v11;
  v1[7].mProjection.v3 = v12;
  *(_QWORD *)&view_settings.mViewFlags = 1i64;
  CullManager::CullSettings::SetFromViewSettings(&view_settings, v1 + 7);
  v13 = CullManager::Instance();
  v1[7].mCullIndex = CullManager::RegisterView(v13, &view_settings);
  if ( UFG::RenderWorld::msRenderWorld )
  {
    v14 = Render::GetRenderCallbacks();
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)((char *)v14->mRenderParam + 1008));
    UFG::RenderStageExposureMetering::Update(UFG::RenderWorld::msExposureMetering, fRealTimeDelta);
    v15 = UFG::RenderWorld::msExposureMetering->mCurrentExposureEV;
    UFG::TimeOfDayManager::GetInstance()->mMeteringEV = v15;
    v16 = UFG::TimeOfDayManager::GetInstance();
    v17 = d.v3.y;
    v18 = d.v3.z;
    v16->mCameraPosition.x = d.v3.x;
    v16->mCameraPosition.y = v17;
    v16->mCameraPosition.z = v18;
    v19 = UFG::Metrics::msInstance.mSimTimeDelta * gTOD_Speedhack;
    v20 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::Update(v20, v19);
  }
  if ( *((_BYTE *)&v1[5].mCullPixelDistanceBias + 4) )
  {
    UFG::RenderStageEnvMap::UpdateViews(UFG::RenderWorld::msStageEnvMap, (UFG::RenderContext *)v1, fRealTimeDelta);
    UFG::RenderStageShadow::UpdateViews(UFG::RenderWorld::msStageShadow, (UFG::RenderContext *)v1, fRealTimeDelta);
    UFG::RenderStageImposters::UpdateViews(UFG::RenderWorld::msStageImposters, (UFG::RenderContext *)v1, fRealTimeDelta);
    _((AMD_HD3D *)UFG::RenderWorld::msStageTerrain);
  }
  else
  {
    v1[8].mWorldView.v1.z = 0.0;
  }
  v21 = UFG::Camera::GetWorldView((UFG::Camera *)v2);
  v22 = v21->v1;
  v23 = v21->v2;
  v24 = v21->v3;
  Render::DebugProbes::msWorldView.v0 = v21->v0;
  Render::DebugProbes::msWorldView.v1 = v22;
  Render::DebugProbes::msWorldView.v2 = v23;
  Render::DebugProbes::msWorldView.v3 = v24;
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
  float *v4; // rsi
  Render::View *v5; // rdi
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v6; // rcx
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v7; // rbx
  UFG::SimComponent *v8; // rax
  float v9; // xmm6_4
  UFG::BaseCameraComponent *v10; // rcx
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h]

  LODWORD(Render::DisplayCalibration::msGamma) = (_DWORD)FLOAT_1_0;
  v1 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v2 = (MovieUpdateTask *)v1;
  if ( v1 )
  {
    v3 = v1 + 8;
    *v3 = v3;
    v3[1] = v3;
    v2->vfptr = (Illusion::AsyncCommandBuilderVtbl *)&Illusion::AsyncCommandBuilder::`vftable;
    v4 = 0i64;
    v2->mTask = 0i64;
    v2->mCommandList = 0i64;
    v2->vfptr = (Illusion::AsyncCommandBuilderVtbl *)&MovieUpdateTask::`vftable;
  }
  else
  {
    v4 = 0i64;
    v2 = 0i64;
  }
  movie_update_task = v2;
  Illusion::AsyncCommandBuilder::BeginAsyncCommandBuilding((Illusion::AsyncCommandBuilder *)&v2->vfptr);
  if ( UFG::RenderWorld::msRenderWorld )
  {
    v5 = (Render::View *)Render::GetRenderCallbacks()->mRenderParam;
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)&v5[2].mViewMetrics.mNumShadowsRendered);
    Render::SkyMarshall::Update(&Render::SkyMarshall::gSkyMarshall, UFG::Metrics::msInstance.mSimTimeDelta);
    Render::RainManager::Update(
      &Render::RainManager::gRainManager,
      UFG::Metrics::msInstance.mSimTimeDelta,
      (UFG::qMatrix44 *)&v5[2].mViewMetrics.mNumShadowsRendered);
    Render::CloudVolumeManager::Update(
      &Render::gCloudVolumeManager,
      UFG::Metrics::msInstance.mSimTimeDelta,
      (UFG::qVector3 *)&d.v3);
    Render::gFXManager.mCurrentTimeOfDay = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
    Render::FXManager::Update(
      &Render::gFXManager,
      &d,
      LODWORD(v5[2].mViewWorld.v1.x),
      UFG::Metrics::msInstance.mSimTime_Temp);
    v6 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
    if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
    {
      do
      {
        v7 = (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&v6[4].mNext[-4];
        ((void (__cdecl *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *))v6->mPrev[8].mNext)(v6);
        v6 = &v7->mNode;
      }
      while ( v7 != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 );
    }
    if ( UFG::RenderWorld::msRenderStagePlugin )
    {
      v8 = UFG::SimObject::GetComponentOfType(
             UFG::RenderWorld::msRenderStagePlugin,
             UFG::VisualTreatmentPostEffect::_TypeUID);
      if ( v8 )
      {
        if ( LOBYTE(v8[1].m_TypeUID) )
        {
          v9 = *(float *)&v8[1].m_NameUID;
          v10 = UFG::Director::Get()->mCurrentCamera;
          if ( v10 )
            v4 = &v10->mCamera.mFOVOffset;
          *v4 = (float)(v9 * 3.1415927) * 0.0055555557;
        }
      }
    }
  }
}

// File Line: 2087
// RVA: 0x49130
void __fastcall SerializationList::~SerializationList(SerializationList *this)
{
  SerializationList *v1; // rdi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v3; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v4; // rax
  UFG::qNode<SerializationList,SerializationList> *v5; // rcx
  UFG::qNode<SerializationList,SerializationList> *v6; // rax

  v1 = this;
  v2 = &this->mList;
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&this->mList);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<SerializationList,SerializationList> *)&v1->mPrev;
}

// File Line: 2102
// RVA: 0x49BE0
void __fastcall SerializationList::AddTaskGroupSync(SerializationList *this, UFG::qTaskGroup *task_group)
{
  UFG::qTaskGroup *v2; // rbx
  SerializationList *v3; // rdi
  char *v4; // rax

  if ( task_group )
  {
    v2 = task_group;
    v3 = this;
    if ( task_group->mNumTasks )
    {
      v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
      if ( v4 )
      {
        *(_QWORD *)v4 = v2;
        *((_QWORD *)v4 + 1) = SerializationList::SyncTaskGroupCallback;
      }
      SerializationList::AddCommand(v3, 17, v4);
    }
  }
}

// File Line: 2111
// RVA: 0x498D0
void __fastcall SerializationList::AddCommand(SerializationList *this, __int16 command, void *data)
{
  void *v3; // rdi
  __int16 v4; // si
  SerializationList *v5; // rbx
  Illusion::RenderQueue *v6; // rbx
  Illusion::QueueCommandBucket *v7; // rcx
  __int64 v8; // r8
  signed __int64 v9; // rax
  char *v10; // rax
  char *v11; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v12; // rax
  Illusion::QueueCommandBucket *v13; // rax

  v3 = data;
  v4 = command;
  v5 = this;
  SerializationList::BeginCommandQueue(this);
  v6 = v5->mCommandQueue;
  v7 = v6->mFreeBucket;
  if ( v7 )
  {
    v8 = v7->mNumCommands;
    if ( (unsigned int)v8 < 0x7E )
    {
      v7->mNumCommands = v8 + 1;
      v9 = (signed __int64)v7 + 16 * (v8 + 2);
      goto LABEL_10;
    }
    if ( v7 )
    {
      v6->mCommandCount += v7->mNumCommands;
      v6->mFreeBucket = 0i64;
    }
  }
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v11 = v10;
  if ( v10 )
  {
    *(_QWORD *)v10 = v10;
    *((_QWORD *)v10 + 1) = v10;
    *((_QWORD *)v10 + 2) = 0i64;
    *((_DWORD *)v10 + 6) = 0;
    v12 = v6->mBuckets.mNode.mPrev;
    v12->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v11;
    *(_QWORD *)v11 = v12;
    *((_QWORD *)v11 + 1) = (char *)v6 + 16;
    v6->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v11;
    v6->mFreeBucket = (Illusion::QueueCommandBucket *)v11;
  }
  v13 = v6->mFreeBucket;
  if ( v13 )
  {
    v13->mNumCommands = 1;
    v9 = (signed __int64)v6->mFreeBucket->mCommands;
LABEL_10:
    if ( v9 )
    {
      *(_WORD *)v9 = v4;
      *(_WORD *)(v9 + 2) = 0;
      *(_QWORD *)(v9 + 8) = v3;
    }
  }
}

// File Line: 2133
// RVA: 0x49C70
void __fastcall SerializationList::BeginCommandQueue(SerializationList *this)
{
  SerializationList *v1; // rdi
  char *v2; // rax
  char *v3; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v4; // rax
  _QWORD *v5; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( !this->mCommandQueue )
  {
    v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v3 = v2;
    if ( v2 )
    {
      *(_QWORD *)v2 = v2;
      *((_QWORD *)v2 + 1) = v2;
      v5 = v2 + 16;
      *v5 = v5;
      v5[1] = v5;
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
    v1->mCommandQueue = (Illusion::RenderQueue *)v3;
    v4 = v1->mList.mNode.mPrev;
    v4->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
    *(_QWORD *)v3 = v4;
    *((_QWORD *)v3 + 1) = (char *)v1 + 16;
    v1->mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
  }
}

// File Line: 2151
// RVA: 0x5CED0
void __fastcall SerializationList::SyncTaskGroupCallback(unsigned int *param)
{
  UFG::qTaskManager::Sync(&UFG::gTaskManager, (UFG::qTaskGroup *)param);
}

// File Line: 2174
// RVA: 0x491A0
void __fastcall SerializationListBuilder::~SerializationListBuilder(SerializationListBuilder *this)
{
  UFG::qList<SerializationList,SerializationList,1,0> *v1; // rbx
  UFG::qNode<SerializationList,SerializationList> *v2; // rcx
  UFG::qNode<SerializationList,SerializationList> *v3; // rax

  v1 = &this->mSerializationLists;
  UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes(&this->mSerializationLists);
  v2 = v1->mNode.mPrev;
  v3 = v1->mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 2177
// RVA: 0x49AD0
void __fastcall SerializationListBuilder::AddTail(SerializationListBuilder *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *render_queues, unsigned int primitive_count_mask)
{
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v3; // rbx
  unsigned int v4; // esi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v5; // rdi
  SerializationListBuilder *i; // rbp
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v7; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v8; // rax
  SerializationList *v9; // rax
  Illusion::RenderQueue *v10; // rdx
  Illusion::QueueCommandBucket *v11; // rcx
  unsigned int v12; // ecx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v13; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v14; // rax

  v3 = render_queues->mNode.mNext;
  v4 = primitive_count_mask;
  v5 = render_queues;
  for ( i = this; v3 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v5; v3 = v5->mNode.mNext )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v3->mPrev = v3;
    v3->mNext = v3;
    v9 = SerializationListBuilder::GetListAndAccumulate(i, (unsigned int)v3[4].mNext, v4 & HIDWORD(v3[4].mNext));
    v10 = v9->mCommandQueue;
    if ( v10 )
    {
      v11 = v10->mFreeBucket;
      if ( v11 )
      {
        v12 = v11->mNumCommands;
        v10->mFreeBucket = 0i64;
        v10->mCommandCount += v12;
      }
      v9->mCommandQueue = 0i64;
    }
    v13 = &v9->mList;
    v14 = v9->mList.mNode.mPrev;
    v14->mNext = v3;
    v3->mPrev = v14;
    v3->mNext = &v13->mNode;
    v13->mNode.mPrev = v3;
  }
}

// File Line: 2222
// RVA: 0x4F940
SerializationList *__fastcall SerializationListBuilder::GetListAndAccumulate(SerializationListBuilder *this, unsigned int command_count, unsigned int primitive_count)
{
  unsigned int v3; // edi
  unsigned int v4; // esi
  SerializationListBuilder *v5; // rbx
  SerializationList *v6; // rdx
  Illusion::RenderQueue *v7; // rcx
  Illusion::QueueCommandBucket *v8; // rax
  char *v9; // rax
  char *v10; // rdx
  _QWORD *v11; // ST28_8
  UFG::qNode<SerializationList,SerializationList> *v12; // rax

  v3 = primitive_count;
  v4 = command_count;
  v5 = this;
  if ( (float)((float)((float)(signed int)(primitive_count + this->mCurrentPrimitiveCount)
                     * this->mOneOverMaxPrimitivesPerList)
             + (float)((float)(signed int)(command_count + this->mCurrentCommandCount) * this->mOneOverMaxCommandsPerList)) > 1.0 )
  {
    v6 = this->mCurrentList;
    if ( v6 )
    {
      v7 = v6->mCommandQueue;
      if ( v7 )
      {
        v8 = v7->mFreeBucket;
        if ( v8 )
        {
          v7->mCommandCount += v8->mNumCommands;
          v7->mFreeBucket = 0i64;
        }
        v6->mCommandQueue = 0i64;
      }
      v5->mCurrentList = 0i64;
    }
    *(_QWORD *)&v5->mCurrentCommandCount = 0i64;
  }
  if ( !v5->mCurrentList )
  {
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v10 = v9;
    if ( v9 )
    {
      *(_QWORD *)v9 = v9;
      *((_QWORD *)v9 + 1) = v9;
      v11 = v9 + 16;
      *v11 = v11;
      v11[1] = v11;
      *((_QWORD *)v9 + 4) = 0i64;
    }
    else
    {
      v10 = 0i64;
    }
    v5->mCurrentList = (SerializationList *)v10;
    v12 = v5->mSerializationLists.mNode.mPrev;
    v12->mNext = (UFG::qNode<SerializationList,SerializationList> *)v10;
    *(_QWORD *)v10 = v12;
    *((_QWORD *)v10 + 1) = (char *)v5 + 24;
    v5->mSerializationLists.mNode.mPrev = (UFG::qNode<SerializationList,SerializationList> *)v10;
  }
  v5->mCurrentCommandCount += v4;
  v5->mCurrentPrimitiveCount += v3;
  return v5->mCurrentList;
}

// File Line: 2260
// RVA: 0x4E9A0
void __fastcall GenerateGBufferPreScenerySerializationList(SerializationList *serialization_list, FlushContext *flush_context, MainViewTargetParams *main_view_target_params)
{
  MainViewTargetParams *v3; // rbx
  SerializationList *v4; // rdi
  int v5; // ebx
  char *v6; // rax
  char *v7; // r8

  v3 = main_view_target_params;
  v4 = serialization_list;
  SerializationList::AddCommand(serialization_list, 22, &UFG::RenderWorld::msGpuTimer_GBuffer);
  SerializationList::AddCommand(v4, 14, v3->gbuffer_target_params);
  SerializationList::AddCommand(v4, 9, v3->gbuffer_viewport);
  v5 = (gDoColorClears != 0) | 0x16;
  if ( v5 )
  {
    v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
    v7 = v6;
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *((_DWORD *)v6 + 2) = LODWORD(UFG::qColour::Zero.r);
      *((_DWORD *)v6 + 3) = LODWORD(UFG::qColour::Zero.g);
      *((_DWORD *)v6 + 4) = LODWORD(UFG::qColour::Zero.b);
      *((_DWORD *)v6 + 5) = LODWORD(UFG::qColour::Zero.a);
      *((_DWORD *)v6 + 6) = v5;
      *((_DWORD *)v6 + 7) = 1065353216;
      *((_DWORD *)v6 + 8) = 1;
    }
    else
    {
      v7 = 0i64;
    }
    SerializationList::AddCommand(v4, 16, v7);
  }
}

// File Line: 2277
// RVA: 0x4E700
void __fastcall GenerateGBufferPostScenerySerializationList(SerializationList *serialization_list, FlushContext *flush_context, MainViewTargetParams *main_view_target_params)
{
  MainViewTargetParams *v3; // r14
  FlushContext *v4; // rbx
  SerializationList *v5; // rdi
  RenderQueueLayer *v6; // rbx
  Illusion::RenderQueue *v7; // rcx
  Illusion::QueueCommandBucket *v8; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v9; // rsi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v10; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // rcx
  RenderQueueLayer *v13; // rdx
  Illusion::RenderQueue *v14; // rcx
  Illusion::QueueCommandBucket *v15; // rax
  UFG::qBaseNodeRB *v16; // r8
  UFG::qBaseNodeRB *v17; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v18; // rcx
  UFG::qBaseNodeRB *v19; // rdx
  Illusion::RenderQueue *v20; // rcx
  Illusion::QueueCommandBucket *v21; // rax
  UFG::qBaseNodeRB *v22; // r8
  UFG::qBaseNodeRB *v23; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  unsigned int *v25; // rdx
  Illusion::RenderQueue *v26; // rcx
  Illusion::QueueCommandBucket *v27; // rax
  UFG::qBaseNodeRB *v28; // r8
  UFG::qBaseNodeRB *v29; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v30; // rcx
  Illusion::RenderQueue *v31; // rcx
  Illusion::QueueCommandBucket *v32; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v33; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v34; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v35; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v36; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v37; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v38; // [rsp+28h] [rbp-18h]

  v3 = main_view_target_params;
  v4 = flush_context;
  v5 = serialization_list;
  v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  SerializationList::AddTaskGroupSync(serialization_list, flush_context->mSkinningGroups[1]);
  v6 = &v4->mSimResults->mRenderSimLayer;
  v6->mSerializationList = &v38;
  RenderQueueLayer::SerializeRenderQueues(v6);
  v6->mSerializationList = 0i64;
  v7 = v5->mCommandQueue;
  if ( v7 )
  {
    v8 = v7->mFreeBucket;
    if ( v8 )
    {
      v7->mCommandCount += v8->mNumCommands;
      v7->mFreeBucket = 0i64;
    }
    v5->mCommandQueue = 0i64;
  }
  v9 = &v5->mList;
  v10 = v38.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v38.mNode.mNext != &v38 )
  {
    v11 = v9->mNode.mPrev;
    v12 = v38.mNode.mPrev;
    v11->mNext = v38.mNode.mNext;
    v10->mPrev = v11;
    v12->mNext = &v9->mNode;
    v9->mNode.mPrev = v12;
    v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
    v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  }
  v13 = v6 + 2;
  v14 = v5->mCommandQueue;
  if ( v14 )
  {
    v15 = v14->mFreeBucket;
    if ( v15 )
    {
      v14->mCommandCount += v15->mNumCommands;
      v14->mFreeBucket = 0i64;
    }
    v5->mCommandQueue = 0i64;
  }
  v16 = v6[2].mTreeLayer0.mTree.mRoot.mParent;
  if ( v16 != (UFG::qBaseNodeRB *)v13 )
  {
    v17 = (UFG::qBaseNodeRB *)v9->mNode.mPrev;
    v18 = v13->mSerializationList;
    v17->mChild[0] = v16;
    v16->mParent = v17;
    v18->mNode.mNext = &v9->mNode;
    v9->mNode.mPrev = &v18->mNode;
    v13->mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v13;
    v6[2].mTreeLayer0.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)&v6[2];
  }
  v19 = (UFG::qBaseNodeRB *)((char *)&v6[2].mTreeLayer0.mTree.mRoot + 8);
  v20 = v5->mCommandQueue;
  if ( v20 )
  {
    v21 = v20->mFreeBucket;
    if ( v21 )
    {
      v20->mCommandCount += v21->mNumCommands;
      v20->mFreeBucket = 0i64;
    }
    v5->mCommandQueue = 0i64;
  }
  v22 = v6[2].mTreeLayer0.mTree.mRoot.mChild[1];
  if ( v22 != v19 )
  {
    v23 = (UFG::qBaseNodeRB *)v9->mNode.mPrev;
    v24 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v19->mParent;
    v23->mChild[0] = v22;
    v22->mParent = v23;
    v24->mNext = &v9->mNode;
    v9->mNode.mPrev = v24;
    v19->mParent = v19;
    v6[2].mTreeLayer0.mTree.mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v6[2].mTreeLayer0.mTree.mRoot + 8);
  }
  v25 = &v6[2].mTreeLayer0.mTree.mRoot.mUID;
  v26 = v5->mCommandQueue;
  if ( v26 )
  {
    v27 = v26->mFreeBucket;
    if ( v27 )
    {
      v26->mCommandCount += v27->mNumCommands;
      v26->mFreeBucket = 0i64;
    }
    v5->mCommandQueue = 0i64;
  }
  v28 = v6[2].mTreeLayer0.mTree.mNULL.mParent;
  if ( v28 != (UFG::qBaseNodeRB *)v25 )
  {
    v29 = (UFG::qBaseNodeRB *)v9->mNode.mPrev;
    v30 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)v25;
    v29->mChild[0] = v28;
    v28->mParent = v29;
    v30->mNext = &v9->mNode;
    v9->mNode.mPrev = v30;
    *(_QWORD *)v25 = v25;
    v6[2].mTreeLayer0.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((char *)&v6[2].mTreeLayer0.mTree.mRoot + 24);
  }
  SerializationList::AddCommand(v5, 22, &UFG::RenderWorld::msGpuTimer_FXDeferred);
  v6[1].mSerializationList = &v38;
  RenderQueueLayer::SerializeRenderQueues(v6 + 1);
  v6[1].mSerializationList = 0i64;
  v31 = v5->mCommandQueue;
  if ( v31 )
  {
    v32 = v31->mFreeBucket;
    if ( v32 )
    {
      v31->mCommandCount += v32->mNumCommands;
      v31->mFreeBucket = 0i64;
    }
    v5->mCommandQueue = 0i64;
  }
  v33 = v38.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v38.mNode.mNext != &v38 )
  {
    v34 = v9->mNode.mPrev;
    v35 = v38.mNode.mPrev;
    v34->mNext = v38.mNode.mNext;
    v33->mPrev = v34;
    v35->mNext = &v9->mNode;
    v9->mNode.mPrev = v35;
    v38.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
    v38.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v38;
  }
  SerializationList::AddCommand(v5, 23, &UFG::RenderWorld::msGpuTimer_FXDeferred);
  SerializationList::AddCommand(v5, 15, v3->gbuffer_target_params);
  SerializationList::AddCommand(v5, 23, &UFG::RenderWorld::msGpuTimer_GBuffer);
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v38);
  v36 = v38.mNode.mPrev;
  v37 = v38.mNode.mNext;
  v38.mNode.mPrev->mNext = v38.mNode.mNext;
  v37->mPrev = v36;
}

// File Line: 2333
// RVA: 0x4E520
void __fastcall GenerateGBufferAlphaSerializationList(SerializationList *serialization_list, FlushContext *flush_context, MainViewTargetParams *main_view_target_params)
{
  FlushContext *v3; // rsi
  SerializationList *v4; // rdi
  SceneryTaskRenderQueueResults *v5; // rbx
  Illusion::RenderQueue *v6; // rcx
  Illusion::QueueCommandBucket *v7; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v8; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v9; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v10; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  RenderQueueLayer *v12; // rbx
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
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v26; // [rsp+28h] [rbp-18h]

  v3 = flush_context;
  v4 = serialization_list;
  v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
  v5 = flush_context->mSceneryTaskResults;
  if ( v5 )
  {
    v5->mSceneryLayer[0].mSerializationList = &v26;
    RenderQueueLayer::SerializeDeferredAlpha(v5->mSceneryLayer);
    v5->mSceneryLayer[0].mSerializationList = 0i64;
    v6 = v4->mCommandQueue;
    if ( v6 )
    {
      v7 = v6->mFreeBucket;
      if ( v7 )
      {
        v6->mCommandCount += v7->mNumCommands;
        v6->mFreeBucket = 0i64;
      }
      v4->mCommandQueue = 0i64;
    }
    v8 = &v4->mList;
    v9 = v26.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v26.mNode.mNext != &v26 )
    {
      v10 = v8->mNode.mPrev;
      v11 = v26.mNode.mPrev;
      v10->mNext = v26.mNode.mNext;
      v9->mPrev = v10;
      v11->mNext = &v8->mNode;
      v8->mNode.mPrev = v11;
      v26.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
      v26.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v26;
    }
  }
  v12 = &v3->mSimResults->mRenderSimLayer;
  v12->mSerializationList = &v26;
  RenderQueueLayer::SerializeDeferredAlpha(v12);
  v12->mSerializationList = 0i64;
  v13 = v4->mCommandQueue;
  if ( v13 )
  {
    v14 = v13->mFreeBucket;
    if ( v14 )
    {
      v13->mCommandCount += v14->mNumCommands;
      v13->mFreeBucket = 0i64;
    }
    v4->mCommandQueue = 0i64;
  }
  v15 = &v4->mList;
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
  v12[1].mSerializationList = &v26;
  RenderQueueLayer::SerializeDeferredAlpha(v12 + 1);
  v12[1].mSerializationList = 0i64;
  v19 = v4->mCommandQueue;
  if ( v19 )
  {
    v20 = v19->mFreeBucket;
    if ( v20 )
    {
      v19->mCommandCount += v20->mNumCommands;
      v19->mFreeBucket = 0i64;
    }
    v4->mCommandQueue = 0i64;
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
void __fastcall GenerateShadowSerializationLists(SerializationListBuilder *serialization_list_builder, FlushContext *flush_context, bool render_sun)
{
  SerializationListBuilder *v3; // rdi
  UFG::ShadowRenderQueueSimResults *v4; // rsi
  char v5; // r13
  unsigned int v6; // er15
  Illusion::Target *v7; // rbp
  char *v8; // rax
  char *v9; // r14
  SerializationList *v10; // rax
  char *v11; // rbx
  SerializationList *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  SerializationList *v15; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v16; // rbx
  signed __int64 v17; // rbp
  UFG::qTaskGroup *v18; // rbx
  SerializationList *v19; // rbp
  char *v20; // rax
  Illusion::RenderQueue *v21; // rbx
  SerializationList *v22; // rax
  Illusion::RenderQueue *v23; // rdx
  Illusion::QueueCommandBucket *v24; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v25; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v26; // rax
  SerializationList *v27; // rax
  FlushContext *v28; // [rsp+88h] [rbp+10h]
  bool v29; // [rsp+90h] [rbp+18h]
  UFG::ShadowRenderQueueTaskResults *v30; // [rsp+98h] [rbp+20h]

  v29 = render_sun;
  v28 = flush_context;
  v3 = serialization_list_builder;
  v30 = flush_context->mShadowTaskResults;
  v4 = flush_context->mShadowSimResults;
  if ( v4 )
  {
    if ( render_sun )
      SerializationListBuilder::AddTail(serialization_list_builder, &v4->mPreShadowPass, 0xFFFFFFFF);
    v5 = 0;
    v6 = 0;
    if ( v4->mNumCascades )
    {
      do
      {
        v7 = v4->mCascadeTargets[v6];
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
        v10 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
        SerializationList::AddCommand(v10, 14, v9);
        v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
        Illusion::SetFullscreenViewportScissor(v7, (Illusion::ViewportScissorState *)v11, 0);
        v12 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
        SerializationList::AddCommand(v12, 9, v11);
        v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
        v14 = v13;
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *((_DWORD *)v13 + 2) = LODWORD(UFG::qColour::Zero.r);
          *((_DWORD *)v13 + 3) = LODWORD(UFG::qColour::Zero.g);
          *((_DWORD *)v13 + 4) = LODWORD(UFG::qColour::Zero.b);
          *((_DWORD *)v13 + 5) = LODWORD(UFG::qColour::Zero.a);
          *((_DWORD *)v13 + 6) = 6;
          *((_DWORD *)v13 + 7) = 1065353216;
          *((_DWORD *)v13 + 8) = 1;
        }
        else
        {
          v14 = 0i64;
        }
        v15 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
        SerializationList::AddCommand(v15, 16, v14);
        if ( v30 )
        {
          v16 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v30->mRenderQueueResults[(unsigned __int64)v6];
          v17 = 4i64;
          do
          {
            SerializationListBuilder::AddTail(v3, v16, 0xFFFFFFFF);
            v16 += 2;
            --v17;
          }
          while ( v17 );
        }
        if ( !v5 && v6 < v4->mNumCascades - 2 )
        {
          v18 = v28->mSkinningGroups[2];
          v19 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
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
        if ( v6 < v4->mNumCascades - 2 )
        {
          SerializationListBuilder::AddTail(v3, &v4->mCompositeDrawableCascades[v6], 0);
          v21 = v4->mDynamicInstances[v6];
          if ( v21 )
          {
            v22 = SerializationListBuilder::GetListAndAccumulate(v3, v21->mCommandCount, v21->mPrimitiveCount);
            v23 = v22->mCommandQueue;
            if ( v23 )
            {
              v24 = v23->mFreeBucket;
              if ( v24 )
              {
                v23->mCommandCount += v24->mNumCommands;
                v23->mFreeBucket = 0i64;
              }
              v22->mCommandQueue = 0i64;
            }
            v25 = &v22->mList;
            v26 = v22->mList.mNode.mPrev;
            v26->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v21->mPrev;
            v21->mPrev = v26;
            v21->mNext = &v25->mNode;
            v25->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v21->mPrev;
          }
        }
        v27 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
        SerializationList::AddCommand(v27, 15, v9);
        if ( v29 )
        {
          if ( v6 == v4->mNumCascades - 2 )
            SerializationListBuilder::AddTail(v3, &v4->mDownsampleShadows, 0xFFFFFFFF);
          SerializationListBuilder::AddTail(v3, &v4->mCollector[v6], 0xFFFFFFFF);
        }
        ++v6;
      }
      while ( v6 < v4->mNumCascades );
    }
    if ( v29 )
    {
      SerializationListBuilder::AddTail(v3, &v4->mCloudShadows, 0xFFFFFFFF);
      SerializationListBuilder::AddTail(v3, &v4->mCharacterShadows, 0xFFFFFFFF);
      SerializationListBuilder::AddTail(v3, &v4->mPostShadowPass, 0xFFFFFFFF);
    }
  }
}

// File Line: 2461
// RVA: 0x4F250
void __fastcall GenerateSpotShadowSerializationLists(SerializationListBuilder *serialization_list_builder, FlushContext *flush_context, unsigned int spot_shadow_index)
{
  SerializationListBuilder *v3; // r15
  UFG::SpotShadowRenderQueueTaskResults *v4; // r14
  UFG::SpotShadowRenderQueueSimResults *v5; // r12
  __int64 v6; // rdi
  Illusion::Target *v7; // r13
  char *v8; // rax
  char *v9; // rsi
  SerializationList *v10; // rax
  char *v11; // rbx
  SerializationList *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  SerializationList *v15; // rax
  unsigned int v16; // ebx
  Illusion::RenderQueue *v17; // rbx
  SerializationList *v18; // rax
  Illusion::RenderQueue *v19; // rdx
  Illusion::QueueCommandBucket *v20; // rcx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v21; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // rax
  SerializationList *v23; // rax

  v3 = serialization_list_builder;
  v4 = flush_context->mSpotShadowTaskResults;
  v5 = flush_context->mSpotShadowSimResults;
  if ( v5 )
  {
    v6 = spot_shadow_index;
    v7 = v5->mSpotShadowTargets[spot_shadow_index];
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
    v10 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
    SerializationList::AddCommand(v10, 14, v9);
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(v7, (Illusion::ViewportScissorState *)v11, 0);
    v12 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
    SerializationList::AddCommand(v12, 9, v11);
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v14 = v13;
    if ( v13 )
    {
      *(_QWORD *)v13 = 0i64;
      *((_DWORD *)v13 + 2) = LODWORD(UFG::qColour::Zero.r);
      *((_DWORD *)v13 + 3) = LODWORD(UFG::qColour::Zero.g);
      *((_DWORD *)v13 + 4) = LODWORD(UFG::qColour::Zero.b);
      *((_DWORD *)v13 + 5) = LODWORD(UFG::qColour::Zero.a);
      *((_DWORD *)v13 + 6) = 6;
      *((_DWORD *)v13 + 7) = 1065353216;
      *((_DWORD *)v13 + 8) = 1;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
    SerializationList::AddCommand(v15, 16, v14);
    if ( v4 )
    {
      v16 = 0;
      do
      {
        if ( v4->mSpotShadowTaskGroups[v6] )
          SerializationListBuilder::AddTail(
            v3,
            (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v4 + 2 * (v16 + 4 * v6),
            0xFFFFFFFF);
        ++v16;
      }
      while ( v16 < 4 );
    }
    SerializationListBuilder::AddTail(v3, &v5->mCompositeDrawableSpotShadows[v6], 0);
    v17 = v5->mDynamicInstances[v6];
    if ( v17 )
    {
      v18 = SerializationListBuilder::GetListAndAccumulate(v3, v17->mCommandCount, v17->mPrimitiveCount);
      v19 = v18->mCommandQueue;
      if ( v19 )
      {
        v20 = v19->mFreeBucket;
        if ( v20 )
        {
          v19->mCommandCount += v20->mNumCommands;
          v19->mFreeBucket = 0i64;
        }
        v18->mCommandQueue = 0i64;
      }
      v21 = &v18->mList;
      v22 = v18->mList.mNode.mPrev;
      v22->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v17->mPrev;
      v17->mPrev = v22;
      v17->mNext = &v21->mNode;
      v21->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v17->mPrev;
    }
    v23 = SerializationListBuilder::GetListAndAccumulate(v3, 1u, 0);
    SerializationList::AddCommand(v23, 15, v9);
  }
}

// File Line: 2533
// RVA: 0x499C0
void __fastcall FlushJobQueue::AddFlushJob(FlushJobQueue *this, SerializationList *serialization_list, unsigned int task_count, unsigned int task_dbg_id, bool flush_to_new_submission_thread)
{
  unsigned int v5; // esi
  unsigned int v6; // ebp
  FlushJobQueue *v7; // rdi
  Illusion::RenderQueue *v8; // r10
  Illusion::QueueCommandBucket *v9; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v10; // rbx
  char *v11; // rax
  Illusion::RenderPhase *v12; // rcx
  _QWORD *v13; // ST40_8
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v14; // r9
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v15; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rdx
  UFG::qTaskGroup *v18; // rax

  v5 = task_dbg_id;
  v6 = task_count;
  v7 = this;
  v8 = serialization_list->mCommandQueue;
  if ( v8 )
  {
    v9 = v8->mFreeBucket;
    if ( v9 )
    {
      v8->mCommandCount += v9->mNumCommands;
      v8->mFreeBucket = 0i64;
    }
    serialization_list->mCommandQueue = 0i64;
  }
  v10 = &serialization_list->mList;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)serialization_list->mList.mNode.mNext != &serialization_list->mList )
  {
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
    v12 = (Illusion::RenderPhase *)v11;
    if ( v11 )
    {
      *(_QWORD *)v11 = v11;
      *((_QWORD *)v11 + 1) = v11;
      v13 = v11 + 16;
      *v13 = v13;
      v13[1] = v13;
      *((_QWORD *)v11 + 4) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    v14 = &v12->mQueues;
    v15 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v10->mNode.mNext;
    if ( v15 != v10 )
    {
      v16 = v14->mNode.mPrev;
      v17 = v10->mNode.mPrev;
      v16->mNext = &v15->mNode;
      v15->mNode.mPrev = v16;
      v17->mNext = &v14->mNode;
      v14->mNode.mPrev = v17;
      v10->mNode.mPrev = &v10->mNode;
      v10->mNode.mNext = &v10->mNode;
    }
    v18 = Illusion::RenderQueueSystem::FlushRenderPhase(v12, v6, v5, v7->mRunningTask, flush_to_new_submission_thread);
    if ( v18 )
      v7->mRunningTask = &v18->mEndTask;
  }
}

// File Line: 2559
// RVA: 0x49B80
void __fastcall FlushJobQueue::AddTaskGroup(FlushJobQueue *this, UFG::qTaskGroup *task_group)
{
  UFG::qTaskGroup *v2; // rbx
  FlushJobQueue *v3; // rdi

  if ( task_group )
  {
    v2 = task_group;
    v3 = this;
    if ( task_group->mNumTasks )
    {
      if ( !task_group->mStartTask.mSyncVars.v.mState )
      {
        if ( this->mRunningTask )
          UFG::qTaskManager::AddDependent(&UFG::gTaskManager, task_group, this->mRunningTask);
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v2);
        v3->mRunningTask = &v2->mEndTask;
      }
    }
  }
}

// File Line: 2584
// RVA: 0x4D430
void __fastcall EarlyFlushSetup(FlushContext *flush_context, FlushJobQueue *job_queue, bool render_world, bool draw_scenery)
{
  bool v4; // si
  bool v5; // r15
  FlushJobQueue *v6; // r12
  FlushContext *v7; // rbp
  char *v8; // rax
  char *v9; // rdi
  _QWORD *v10; // ST28_8
  char *v11; // rax
  EarlyFlushRenderPhaseTaskParams *v12; // r14
  _QWORD *v13; // ST28_8
  RenderSceneryTaskParams *v14; // rcx
  RenderSceneryTaskParams *v15; // rcx
  RenderSceneryTaskParams *v16; // rcx
  RenderSceneryTaskParams *v17; // rcx
  RenderSceneryTaskParams *v18; // rcx
  char *v19; // rax
  UFG::qTask *v20; // rdi
  _QWORD *v21; // rax
  UFG::qSpuElf *v22; // rax
  void (__fastcall *v23)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *v24)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v25)(void *, void *, void *, void *); // r8
  char *v26; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v27; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v28; // rax
  char *v29; // rax
  UFG::qTask *v30; // rsi
  _QWORD *v31; // rcx
  UFG::qSpuElf *v32; // rax
  void (__fastcall *v33)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *v34)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v35)(void *, void *, void *, void *); // r8
  char *v36; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v37; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v38; // rax

  v4 = draw_scenery;
  v5 = render_world;
  v6 = job_queue;
  v7 = flush_context;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    v10 = v8 + 16;
    *v10 = v10;
    v10[1] = v10;
    *((_QWORD *)v8 + 4) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x70u, 0x10u);
  v12 = (EarlyFlushRenderPhaseTaskParams *)v11;
  if ( v11 )
  {
    v13 = v11 + 16;
    *v13 = v13;
    v13[1] = v13;
    *((_QWORD *)v11 + 9) = 0i64;
    *((_QWORD *)v11 + 4) = 0i64;
    *((_QWORD *)v11 + 10) = 0i64;
    *((_QWORD *)v11 + 5) = 0i64;
    *((_QWORD *)v11 + 11) = 0i64;
    *((_QWORD *)v11 + 6) = 0i64;
    *((_QWORD *)v11 + 12) = 0i64;
    *((_QWORD *)v11 + 7) = 0i64;
    *((_QWORD *)v11 + 13) = 0i64;
    *((_QWORD *)v11 + 8) = 0i64;
  }
  else
  {
    v12 = 0i64;
  }
  v12->render_world = v5;
  v12->draw_scenery = v4;
  v12->render_phase = (Illusion::RenderPhase *)v9;
  if ( v5 && v4 )
  {
    v14 = v7->mSceneryTaskResults->mSceneryTaskParams[0];
    v12->scenery_results[0] = v14->mMainMemRenderQueueResults;
    v12->scenery_layers[0] = (RenderQueueLayer *)v14->mRenderQueueLayer_Remote;
    v15 = v7->mSceneryTaskResults->mSceneryTaskParams[1];
    v12->scenery_results[1] = v15->mMainMemRenderQueueResults;
    v12->scenery_layers[1] = (RenderQueueLayer *)v15->mRenderQueueLayer_Remote;
    v16 = v7->mSceneryTaskResults->mSceneryTaskParams[2];
    v12->scenery_results[2] = v16->mMainMemRenderQueueResults;
    v12->scenery_layers[2] = (RenderQueueLayer *)v16->mRenderQueueLayer_Remote;
    v17 = v7->mSceneryTaskResults->mSceneryTaskParams[3];
    v12->scenery_results[3] = v17->mMainMemRenderQueueResults;
    v12->scenery_layers[3] = (RenderQueueLayer *)v17->mRenderQueueLayer_Remote;
    v18 = v7->mSceneryTaskResults->mSceneryTaskParams[4];
    v12->scenery_results[4] = v18->mMainMemRenderQueueResults;
    v12->scenery_layers[4] = (RenderQueueLayer *)v18->mRenderQueueLayer_Remote;
  }
  v19 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v20 = (UFG::qTask *)v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = v19;
    *((_QWORD *)v19 + 1) = v19;
    v21 = v19 + 16;
    *v21 = v21;
    v21[1] = v21;
    v22 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mSpuElf;
    v23 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionSPU;
    v24 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionPPU;
    v25 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_EarlyFlushRenderPhaseTask.mCurrentSPUEnabled )
    {
      v22 = 0i64;
      v23 = 0i64;
      v25 = 0i64;
    }
    v20->mTaskGroup = 0i64;
    v20->mFlags = 2;
    v20->mSyncVars.i64 = 0i64;
    v20->mSyncVars.v.mDependents = 0i64;
    v20->mFunctionDeclData = &gTaskFunctionDeclData_EarlyFlushRenderPhaseTask;
    if ( v22 )
      v26 = v22->mAddress;
    else
      v26 = 0i64;
    v20->mSPUElfAddress = v26;
    v20->mSPUFunction = v23;
    v20->mPPUFunction = v24;
    v20->mParam0 = v12;
    v20->mParam1 = 0i64;
    v20->mParam2 = 0i64;
    v20->mParam3 = 0i64;
    if ( v25 )
    {
      v20->mFlags = 130;
      v20->mOffloadThread = 0;
    }
  }
  v27 = UFG::gTaskManager.mSingleFrameTasks;
  v28 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v28->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v20->mPrev;
  v20->mPrev = v28;
  v20->mNext = &v27->mNode;
  v27->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v20->mPrev;
  v29 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v30 = (UFG::qTask *)v29;
  if ( v29 )
  {
    *(_QWORD *)v29 = v29;
    *((_QWORD *)v29 + 1) = v29;
    v31 = v29 + 16;
    *v31 = v31;
    v31[1] = v31;
    v32 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mSpuElf;
    v33 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionSPU;
    v34 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionPPU;
    v35 = gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask.mCurrentSPUEnabled )
    {
      v32 = 0i64;
      v33 = 0i64;
      v35 = 0i64;
    }
    v30->mTaskGroup = 0i64;
    v30->mFlags = 2;
    v30->mSyncVars.i64 = 0i64;
    v30->mSyncVars.v.mDependents = 0i64;
    v30->mFunctionDeclData = &gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask;
    if ( v32 )
      v36 = v32->mAddress;
    else
      v36 = 0i64;
    v30->mSPUElfAddress = v36;
    v30->mSPUFunction = v33;
    v30->mPPUFunction = v34;
    v30->mParam0 = 0i64;
    v30->mParam1 = 0i64;
    v30->mParam2 = 0i64;
    v30->mParam3 = 0i64;
    if ( v35 )
    {
      v30->mFlags = 130;
      v30->mOffloadThread = 0;
    }
  }
  v37 = UFG::gTaskManager.mSingleFrameTasks;
  v38 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v38->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v30->mPrev;
  v30->mPrev = v38;
  v30->mNext = &v37->mNode;
  v37->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v30->mPrev;
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v20, v30);
  if ( v6->mRunningTask )
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v20, v6->mRunningTask);
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v20);
  v6->mRunningTask = v20;
  v7->mEarlyFlushTaskParams = v12;
  v7->mEarlyFlushTask = v20;
  v7->mEarlyFlushTaskTriggerTask = v30;
}

// File Line: 2634
// RVA: 0x4D7E0
void __fastcall EarlyFlushToIllusionTrigger(FlushContext *flush_context, MainViewTargetParams *main_view_target_params)
{
  MainViewTargetParams *v2; // rsi
  FlushContext *v3; // rbx
  Illusion::RenderQueue *v4; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v7; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v8; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v9; // rdx
  UFG::qTaskGroup *v10; // rdi
  char *v11; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v12; // r8
  Illusion::QueueCommandBucket *v13; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v14; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v15; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v16; // r8
  Illusion::QueueCommandBucket *v17; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v19; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v20; // r8
  Illusion::QueueCommandBucket *v21; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v23; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v24; // r8
  Illusion::QueueCommandBucket *v25; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v26; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v27; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v28; // r8
  Illusion::QueueCommandBucket *v29; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v30; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v31; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v32; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v33; // rax
  UFG::qNode<SerializationList,SerializationList> *v34; // rcx
  UFG::qNode<SerializationList,SerializationList> *v35; // rax
  SerializationList serialization_list; // [rsp+28h] [rbp-28h]

  v2 = main_view_target_params;
  v3 = flush_context;
  serialization_list.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list;
  serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
  serialization_list.mList.mNode.mNext = &serialization_list.mList.mNode;
  serialization_list.mCommandQueue = 0i64;
  v4 = 0i64;
  v7 = v3->mRenderQueues[0].mNode.mNext;
  if ( v7 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3 )
  {
    v9 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v8 = serialization_list.mList.mNode.mPrev;
    v9 = v3->mRenderQueues[0].mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = v7;
    v7->mPrev = v8;
    v9->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v9;
    v3->mRenderQueues[0].mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
    v3->mRenderQueues[0].mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v3;
    v4 = serialization_list.mCommandQueue;
  }
  v10 = v3->mSkinningGroups[0];
  if ( v10 && v10->mNumTasks )
  {
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    if ( v11 )
    {
      *(_QWORD *)v11 = v10;
      *((_QWORD *)v11 + 1) = SerializationList::SyncTaskGroupCallback;
    }
    else
    {
      v11 = 0i64;
    }
    SerializationList::AddCommand(&serialization_list, 17, v11);
    v4 = serialization_list.mCommandQueue;
    v9 = serialization_list.mList.mNode.mPrev;
  }
  v12 = &v3->mRenderQueues[1].mNode.mPrev;
  if ( v4 )
  {
    v13 = v4->mFreeBucket;
    if ( v13 )
    {
      v4->mCommandCount += v13->mNumCommands;
      v4->mFreeBucket = 0i64;
      v9 = serialization_list.mList.mNode.mPrev;
    }
    v4 = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v14 = v3->mRenderQueues[1].mNode.mNext;
  if ( v14 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v12 )
  {
    v15 = *v12;
    v9->mNext = v14;
    v14->mPrev = v9;
    v15->mNext = &serialization_list.mList.mNode;
    v9 = v15;
    serialization_list.mList.mNode.mPrev = v15;
    *v12 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v12;
    v3->mRenderQueues[1].mNode.mNext = &v3->mRenderQueues[1].mNode;
    v4 = serialization_list.mCommandQueue;
  }
  v16 = &v3->mRenderQueues[2].mNode.mPrev;
  if ( v4 )
  {
    v17 = v4->mFreeBucket;
    if ( v17 )
    {
      v4->mCommandCount += v17->mNumCommands;
      v4->mFreeBucket = 0i64;
      v9 = serialization_list.mList.mNode.mPrev;
    }
    v4 = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v18 = v3->mRenderQueues[2].mNode.mNext;
  if ( v18 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v16 )
  {
    v19 = *v16;
    v9->mNext = v18;
    v18->mPrev = v9;
    v19->mNext = &serialization_list.mList.mNode;
    v9 = v19;
    serialization_list.mList.mNode.mPrev = v19;
    *v16 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v16;
    v3->mRenderQueues[2].mNode.mNext = &v3->mRenderQueues[2].mNode;
    v4 = serialization_list.mCommandQueue;
  }
  v20 = &v3->mRenderQueues[3].mNode.mPrev;
  if ( v4 )
  {
    v21 = v4->mFreeBucket;
    if ( v21 )
    {
      v4->mCommandCount += v21->mNumCommands;
      v4->mFreeBucket = 0i64;
      v9 = serialization_list.mList.mNode.mPrev;
    }
    v4 = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v22 = v3->mRenderQueues[3].mNode.mNext;
  if ( v22 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v20 )
  {
    v23 = *v20;
    v9->mNext = v22;
    v22->mPrev = v9;
    v23->mNext = &serialization_list.mList.mNode;
    v9 = v23;
    serialization_list.mList.mNode.mPrev = v23;
    *v20 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v20;
    v3->mRenderQueues[3].mNode.mNext = &v3->mRenderQueues[3].mNode;
    v4 = serialization_list.mCommandQueue;
  }
  v24 = &v3->mRenderQueues[4].mNode.mPrev;
  if ( v4 )
  {
    v25 = v4->mFreeBucket;
    if ( v25 )
    {
      v4->mCommandCount += v25->mNumCommands;
      v4->mFreeBucket = 0i64;
      v9 = serialization_list.mList.mNode.mPrev;
    }
    v4 = 0i64;
    serialization_list.mCommandQueue = 0i64;
  }
  v26 = v3->mRenderQueues[4].mNode.mNext;
  if ( v26 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v24 )
  {
    v27 = *v24;
    v9->mNext = v26;
    v26->mPrev = v9;
    v27->mNext = &serialization_list.mList.mNode;
    v9 = v27;
    serialization_list.mList.mNode.mPrev = v27;
    *v24 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v24;
    v3->mRenderQueues[4].mNode.mNext = &v3->mRenderQueues[4].mNode;
    v4 = serialization_list.mCommandQueue;
  }
  if ( v3->mEarlyFlushTaskParams->render_world )
  {
    GenerateGBufferPreScenerySerializationList(&serialization_list, v3, v2);
    v4 = serialization_list.mCommandQueue;
    v9 = serialization_list.mList.mNode.mPrev;
  }
  v28 = &v3->mEarlyFlushTaskParams->pre_scenery_queues;
  if ( v4 )
  {
    v29 = v4->mFreeBucket;
    if ( v29 )
    {
      v4->mCommandCount += v29->mNumCommands;
      v4->mFreeBucket = 0i64;
      v9 = serialization_list.mList.mNode.mPrev;
    }
    serialization_list.mCommandQueue = 0i64;
  }
  v30 = serialization_list.mList.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)serialization_list.mList.mNode.mNext != &serialization_list.mList )
  {
    v31 = v28->mNode.mPrev;
    v31->mNext = serialization_list.mList.mNode.mNext;
    v30->mPrev = v31;
    v9->mNext = &v28->mNode;
    v28->mNode.mPrev = v9;
    serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mNext = &serialization_list.mList.mNode;
  }
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v3->mEarlyFlushTaskTriggerTask);
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&serialization_list.mList);
  v32 = serialization_list.mList.mNode.mPrev;
  v33 = serialization_list.mList.mNode.mNext;
  serialization_list.mList.mNode.mPrev->mNext = serialization_list.mList.mNode.mNext;
  v33->mPrev = v32;
  v34 = serialization_list.mPrev;
  v35 = serialization_list.mNext;
  serialization_list.mPrev->mNext = serialization_list.mNext;
  v35->mPrev = v34;
}

// File Line: 2668
// RVA: 0x51A60
void __fastcall LateFlushToIllusion(FlushContext *flush_context, UFG::RenderContext *render_context, float fTime, MainViewTargetParams *main_view_target_params)
{
  MainViewTargetParams *v4; // r15
  UFG::RenderContext *v5; // r13
  FlushContext *v6; // rdi
  signed __int64 v7; // rbx
  signed __int64 v8; // rsi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v14; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v15; // rdx
  __int64 v16; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // rax
  FlushJobQueue *v19; // r14
  UFG::qTaskGroup *v20; // rbx
  UFG::ShadowRenderQueueTaskResults *v21; // rcx
  SerializationList *v22; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *i; // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v24; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rax
  SerializationList *v26; // rax
  Illusion::RenderQueue *v27; // rdx
  Illusion::QueueCommandBucket *v28; // rcx
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
  UFG::SpotShadowRenderQueueTaskResults *v39; // r8
  int v40; // edx
  __int64 v41; // rax
  UFG::qTaskGroup **v42; // rcx
  UFG::qTaskGroup *v43; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v47; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v48; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v49; // rcx
  unsigned int v50; // ebx
  SerializationList *k; // rdx
  UFG::qNode<SerializationList,SerializationList> *v52; // rcx
  UFG::qNode<SerializationList,SerializationList> *v53; // rax
  signed __int64 v54; // rdx
  __int64 v55; // rcx
  __int64 v56; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v57; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v58; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v59; // r8
  signed __int64 v60; // rdx
  __int64 v61; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v62; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v63; // rax
  UFG::qNode<SerializationList,SerializationList> *v64; // rcx
  UFG::qNode<SerializationList,SerializationList> *v65; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v66; // rdx
  __int64 v67; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v68; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v69; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v70; // rcx
  UFG::qTaskGroup *v71; // rbx
  char *v72; // rbx
  char *v73; // rax
  _QWORD *v74; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v75; // rax
  __int64 v76; // rdx
  __int64 v77; // rax
  signed __int64 v78; // rcx
  char *v79; // rax
  char *v80; // rdx
  __int64 v81; // rax
  __int64 v82; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v83; // rdx
  char *v84; // rbx
  __int64 v85; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v86; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v87; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v88; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v89; // rdx
  __int64 v90; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v91; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v92; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v93; // rdx
  __int64 v94; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v95; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v96; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v97; // rdx
  __int64 v98; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v99; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v100; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v101; // rdx
  __int64 v102; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v103; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v104; // rax
  char *v105; // rax
  _QWORD *v106; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v107; // rax
  __int64 v108; // rdx
  __int64 v109; // rax
  signed __int64 v110; // rcx
  char *v111; // rax
  char *v112; // rdx
  __int64 v113; // rax
  __int64 v114; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v115; // r8
  char *v116; // rbx
  __int64 v117; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v118; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v119; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v120; // rcx
  char *v121; // rax
  _QWORD *v122; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v123; // rax
  __int64 v124; // rdx
  __int64 v125; // rax
  signed __int64 v126; // rcx
  char *v127; // rax
  char *v128; // rdx
  __int64 v129; // rax
  __int64 v130; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v131; // r8
  char *v132; // rcx
  __int64 v133; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v134; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v135; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v136; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v137; // r8
  __int64 v138; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v139; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v140; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v141; // r8
  __int64 v142; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v143; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v144; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v145; // r8
  __int64 v146; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v147; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v148; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v149; // r8
  __int64 v150; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v151; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v152; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v153; // r8
  __int64 v154; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v155; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v156; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v157; // r8
  __int64 v158; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v159; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v160; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v161; // r8
  __int64 v162; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v163; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v164; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v165; // r8
  __int64 v166; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v167; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v168; // rax
  signed __int64 v169; // rdi
  __int64 v170; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v171; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v172; // rax
  UFG::TimeOfDayManager *v173; // rax
  UFG::qTask *v174; // rax
  UFG::qNode<SerializationList,SerializationList> *v175; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v176; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v177; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v178; // ST10_8
  UFG::qNode<SerializationList,SerializationList> *v179; // rcx
  UFG::qNode<SerializationList,SerializationList> *v180; // rax
  __int64 v181; // [rsp+18h] [rbp-71h]
  __int64 v182; // [rsp+18h] [rbp-71h]
  __int64 v183; // [rsp+18h] [rbp-71h]
  __int64 v184; // [rsp+18h] [rbp-71h]
  char *v185; // [rsp+18h] [rbp-71h]
  bool flush_to_new_submission_thread[4]; // [rsp+20h] [rbp-69h]
  float v187; // [rsp+24h] [rbp-65h]
  __int64 v188; // [rsp+28h] [rbp-61h]
  SerializationList serialization_list; // [rsp+30h] [rbp-59h]
  __int64 v190; // [rsp+58h] [rbp-31h]
  UFG::qList<SerializationList,SerializationList,1,0> v191; // [rsp+60h] [rbp-29h]
  _QWORD *v192; // [rsp+70h] [rbp-19h]
  __int64 v193; // [rsp+78h] [rbp-11h]
  void *v194; // [rsp+E8h] [rbp+5Fh]
  UFG::qList<SerializationList,SerializationList,1,0> *v195; // [rsp+F0h] [rbp+67h]
  FlushJobQueue *v196; // [rsp+108h] [rbp+7Fh]

  v193 = -2i64;
  v4 = main_view_target_params;
  v5 = render_context;
  v6 = flush_context;
  serialization_list.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list;
  v194 = &serialization_list.mList;
  serialization_list.mList.mNode.mPrev = &serialization_list.mList.mNode;
  UFG::qTaskManager::Sync(&UFG::gTaskManager, flush_context->mEarlyFlushTask);
  if ( v5->mRenderFeatures.mWorld )
  {
    if ( v5->mRenderFeatures.mScenery )
    {
      v7 = 1i64;
      v8 = 4i64;
      do
      {
        Render::ViewMetrics::Accumulate(&v5->mRenderStats, &v6->mSceneryTaskResults->mSceneryViewMetrics[v7]);
        ++v7;
        --v8;
      }
      while ( v8 );
    }
    GenerateGBufferPostScenerySerializationList(&serialization_list, v6, v4);
  }
  v9 = &v6->mRenderQueues[5].mNode.mPrev;
  v10 = v181;
  if ( v181 )
  {
    v11 = *(_QWORD *)(v181 + 40);
    if ( v11 )
    {
      *(_DWORD *)(v181 + 72) += *(_DWORD *)(v11 + 24);
      *(_QWORD *)(v181 + 40) = 0i64;
    }
    v10 = 0i64;
    v181 = 0i64;
  }
  v12 = v6->mRenderQueues[5].mNode.mNext;
  if ( v12 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9 )
  {
    v14 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v13 = serialization_list.mList.mNode.mPrev;
    v14 = *v9;
    serialization_list.mList.mNode.mPrev->mNext = v12;
    v12->mPrev = v13;
    v14->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v14;
    *v9 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
    v6->mRenderQueues[5].mNode.mNext = &v6->mRenderQueues[5].mNode;
    v10 = v181;
  }
  v15 = &v6->mRenderQueues[8].mNode.mPrev;
  if ( v10 )
  {
    v16 = *(_QWORD *)(v10 + 40);
    if ( v16 )
    {
      *(_DWORD *)(v10 + 72) += *(_DWORD *)(v16 + 24);
      *(_QWORD *)(v10 + 40) = 0i64;
      v14 = serialization_list.mList.mNode.mPrev;
    }
  }
  v17 = v6->mRenderQueues[8].mNode.mNext;
  if ( v17 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v15 )
  {
    v18 = *v15;
    v14->mNext = v17;
    v17->mPrev = v14;
    v18->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v18;
    *v15 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v15;
    v6->mRenderQueues[8].mNode.mNext = &v6->mRenderQueues[8].mNode;
  }
  v19 = v196;
  FlushJobQueue::AddFlushJob(v196, &serialization_list, 5u, 0x7C00u, 0);
  if ( v5->mRenderFeatures.mWorld )
  {
    v20 = v6->mSkinningGroups[1];
    if ( v20 )
    {
      if ( v20->mNumTasks && !v20->mStartTask.mSyncVars.v.mState )
      {
        if ( v19->mRunningTask )
          UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v6->mSkinningGroups[1], v19->mRunningTask);
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v20);
        v19->mRunningTask = &v20->mEndTask;
      }
    }
  }
  v21 = v6->mShadowTaskResults;
  if ( v21 )
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v21->mCascadeTaskGroups[v21->mNumCascades - 1]);
  *(float *)flush_to_new_submission_thread = 1.0 / (float)(signed int)(5 * gShadowsRenderPhase_MaxCommands);
  v187 = 1.0 / (float)(signed int)(5 * gShadowsRenderPhase_MaxPrimitives);
  v188 = 0i64;
  serialization_list.mPrev = 0i64;
  v194 = &serialization_list.mNext;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list.mNext;
  serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&serialization_list.mNext;
  v22 = SerializationListBuilder::GetListAndAccumulate(
          (SerializationListBuilder *)flush_to_new_submission_thread,
          1u,
          0);
  SerializationList::AddCommand(v22, 22, &UFG::RenderWorld::msGpuTimer_Lighting_Shadows);
  GenerateShadowSerializationLists((SerializationListBuilder *)flush_to_new_submission_thread, v6, v5->mRenderSun);
  for ( i = v6->mRenderQueues[9].mNode.mNext;
        i != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v6->mRenderQueues[9];
        i = v6->mRenderQueues[9].mNode.mNext )
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
    v27 = v26->mCommandQueue;
    if ( v27 )
    {
      v28 = v27->mFreeBucket;
      if ( v28 )
      {
        v27->mCommandCount += v28->mNumCommands;
        v27->mFreeBucket = 0i64;
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
    j->mPrev = (UFG::qNode<SerializationList,SerializationList> *)&j->mPrev;
    j->mNext = (UFG::qNode<SerializationList,SerializationList> *)&j->mPrev;
    FlushJobQueue::AddFlushJob(v19, j, 5u, 0x7C1Fu, v32);
    v32 = 0;
  }
  v36 = v6->mSkinningGroups[2];
  if ( v36 && v36->mNumTasks && !v36->mStartTask.mSyncVars.v.mState )
  {
    if ( v19->mRunningTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v6->mSkinningGroups[2], v19->mRunningTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v36);
    v19->mRunningTask = &v36->mEndTask;
  }
  v37 = v6->mSkinningGroups[3];
  if ( v37 && v37->mNumTasks )
  {
    v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 8u);
    v194 = v38;
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v38;
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
  v39 = v6->mSpotShadowTaskResults;
  if ( v39 )
  {
    v40 = v39->mNumActiveSpotShadows - 1;
    v41 = v40;
    if ( !v39->mSpotShadowTaskGroups[v40] )
    {
      v42 = &v39->mSpotShadowTaskGroups[v40];
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
    v43 = v39->mSpotShadowTaskGroups[v40];
    if ( v43 )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v43);
  }
  v44 = &v6->mRenderQueues[12].mNode.mPrev;
  v45 = v182;
  if ( v182 )
  {
    v46 = *(_QWORD *)(v182 + 40);
    if ( v46 )
    {
      *(_DWORD *)(v182 + 72) += *(_DWORD *)(v46 + 24);
      *(_QWORD *)(v182 + 40) = 0i64;
    }
    v45 = 0i64;
    v182 = 0i64;
  }
  v47 = v6->mRenderQueues[12].mNode.mNext;
  if ( v47 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v44 )
  {
    v48 = serialization_list.mList.mNode.mPrev;
    v49 = *v44;
    serialization_list.mList.mNode.mPrev->mNext = v47;
    v47->mPrev = v48;
    v49->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v49;
    *v44 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v44;
    v6->mRenderQueues[12].mNode.mNext = &v6->mRenderQueues[12].mNode;
    v45 = v182;
  }
  if ( gSpotShadowCount )
  {
    v50 = 0;
    v194 = &v191;
    v195 = &v191;
    do
    {
      *(float *)&serialization_list.mList.mNode.mNext = 1.0 / (float)(signed int)(5 * gShadowsRenderPhase_MaxCommands);
      *((float *)&serialization_list.mList.mNode.mNext + 1) = 1.0
                                                            / (float)(signed int)(5 * gShadowsRenderPhase_MaxPrimitives);
      serialization_list.mCommandQueue = 0i64;
      v190 = 0i64;
      v191.mNode.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v191;
      v191.mNode.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v191;
      GenerateSpotShadowSerializationLists((SerializationListBuilder *)&serialization_list.mList.mNode.mNext, v6, v50);
      for ( k = (SerializationList *)v191.mNode.mNext;
            (UFG::qList<SerializationList,SerializationList,1,0> *)v191.mNode.mNext != &v191;
            k = (SerializationList *)v191.mNode.mNext )
      {
        v52 = k->mPrev;
        v53 = k->mNext;
        v52->mNext = v53;
        v53->mPrev = v52;
        k->mPrev = (UFG::qNode<SerializationList,SerializationList> *)&k->mPrev;
        k->mNext = (UFG::qNode<SerializationList,SerializationList> *)&k->mPrev;
        FlushJobQueue::AddFlushJob(v19, k, 5u, 0x7C1Fu, 0);
      }
      v54 = (signed __int64)&v6->mRenderQueues[v50 + 13];
      v55 = v183;
      if ( v183 )
      {
        v56 = *(_QWORD *)(v183 + 40);
        if ( v56 )
        {
          *(_DWORD *)(v183 + 72) += *(_DWORD *)(v56 + 24);
          *(_QWORD *)(v183 + 40) = 0i64;
        }
        v55 = 0i64;
        v183 = 0i64;
      }
      v57 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)(v54 + 8);
      if ( v57 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v54 )
      {
        v59 = serialization_list.mList.mNode.mPrev;
      }
      else
      {
        v58 = serialization_list.mList.mNode.mPrev;
        v59 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)v54;
        serialization_list.mList.mNode.mPrev->mNext = v57;
        v57->mPrev = v58;
        v59->mNext = &serialization_list.mList.mNode;
        serialization_list.mList.mNode.mPrev = v59;
        *(_QWORD *)v54 = v54;
        *(_QWORD *)(v54 + 8) = v54;
        v55 = v183;
      }
      v60 = (signed __int64)&v6->mRenderQueues[v50 + 21];
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
      v62 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)(v60 + 8);
      if ( v62 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v60 )
      {
        v63 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)v60;
        v59->mNext = v62;
        v62->mPrev = v59;
        v63->mNext = &serialization_list.mList.mNode;
        serialization_list.mList.mNode.mPrev = v63;
        *(_QWORD *)v60 = v60;
        *(_QWORD *)(v60 + 8) = v60;
      }
      FlushJobQueue::AddFlushJob(v19, &serialization_list, 2u, 0x7FE0u, 0);
      UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes(&v191);
      v64 = v191.mNode.mPrev;
      v65 = v191.mNode.mNext;
      v191.mNode.mPrev->mNext = v191.mNode.mNext;
      v65->mPrev = v64;
      v191.mNode.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v191;
      v191.mNode.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v191;
      ++v50;
    }
    while ( v50 < gSpotShadowCount );
    v45 = v184;
  }
  v66 = &v6->mRenderQueues[29].mNode.mPrev;
  if ( v45 )
  {
    v67 = *(_QWORD *)(v45 + 40);
    if ( v67 )
    {
      *(_DWORD *)(v45 + 72) += *(_DWORD *)(v67 + 24);
      *(_QWORD *)(v45 + 40) = 0i64;
    }
  }
  v68 = v6->mRenderQueues[29].mNode.mNext;
  if ( v68 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v66 )
  {
    v69 = serialization_list.mList.mNode.mPrev;
    v70 = *v66;
    serialization_list.mList.mNode.mPrev->mNext = v68;
    v68->mPrev = v69;
    v70->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v70;
    *v66 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v66;
    v6->mRenderQueues[29].mNode.mNext = &v6->mRenderQueues[29].mNode;
  }
  FlushJobQueue::AddFlushJob(v19, &serialization_list, 2u, 0x7FE0u, 0);
  v71 = v6->mSkinningGroups[3];
  if ( v71 && v71->mNumTasks && !v71->mStartTask.mSyncVars.v.mState )
  {
    if ( v19->mRunningTask )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v6->mSkinningGroups[3], v19->mRunningTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v71);
    v19->mRunningTask = &v71->mEndTask;
  }
  v72 = v185;
  if ( !v185 )
  {
    v73 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v72 = v73;
    v194 = v73;
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v73;
    if ( v73 )
    {
      *(_QWORD *)v73 = v73;
      *((_QWORD *)v73 + 1) = v73;
      v74 = v73 + 16;
      v192 = v74;
      *v74 = v74;
      v74[1] = v74;
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
    v185 = v72;
    v75 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v72;
    *(_QWORD *)v72 = v75;
    *((_QWORD *)v72 + 1) = (char *)&serialization_list + 16;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v72;
  }
  v76 = *((_QWORD *)v72 + 5);
  if ( v76 )
  {
    v77 = *(unsigned int *)(v76 + 24);
    if ( (unsigned int)v77 < 0x7E )
    {
      v78 = v76 + 16 * (v77 + 2);
      *(_DWORD *)(v76 + 24) = v77 + 1;
      goto LABEL_103;
    }
    if ( v76 )
    {
      *((_DWORD *)v72 + 18) += *(_DWORD *)(v76 + 24);
      *((_QWORD *)v72 + 5) = 0i64;
    }
  }
  v79 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v80 = v79;
  v194 = v79;
  if ( v79 )
  {
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v79;
    *(_QWORD *)v79 = v79;
    *((_QWORD *)v79 + 1) = v79;
    *((_QWORD *)v79 + 2) = 0i64;
    *((_DWORD *)v79 + 6) = 0;
    v81 = *((_QWORD *)v72 + 2);
    *(_QWORD *)(v81 + 8) = v80;
    *(_QWORD *)v80 = v81;
    *((_QWORD *)v80 + 1) = v72 + 16;
    *((_QWORD *)v72 + 2) = v80;
    *((_QWORD *)v72 + 5) = v80;
  }
  v82 = *((_QWORD *)v72 + 5);
  if ( v82 )
  {
    *(_DWORD *)(v82 + 24) = 1;
    v78 = *((_QWORD *)v72 + 5) + 32i64;
LABEL_103:
    if ( v78 )
    {
      *(_DWORD *)v78 = 22;
      *(_QWORD *)(v78 + 8) = &UFG::RenderWorld::msGpuTimer_PostFX;
    }
  }
  v83 = &v6->mRenderQueues[10].mNode.mPrev;
  v84 = v185;
  if ( v185 )
  {
    v85 = *((_QWORD *)v185 + 5);
    if ( v85 )
    {
      *((_DWORD *)v185 + 18) += *(_DWORD *)(v85 + 24);
      *((_QWORD *)v185 + 5) = 0i64;
    }
    v84 = 0i64;
    v185 = 0i64;
  }
  v86 = v6->mRenderQueues[10].mNode.mNext;
  if ( v86 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v83 )
  {
    v88 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v87 = serialization_list.mList.mNode.mPrev;
    v88 = *v83;
    serialization_list.mList.mNode.mPrev->mNext = v86;
    v86->mPrev = v87;
    v88->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v88;
    *v83 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v83;
    v6->mRenderQueues[10].mNode.mNext = &v6->mRenderQueues[10].mNode;
    v84 = v185;
  }
  v89 = &v6->mRenderQueues[11].mNode.mPrev;
  if ( v84 )
  {
    v90 = *((_QWORD *)v84 + 5);
    if ( v90 )
    {
      *((_DWORD *)v84 + 18) += *(_DWORD *)(v90 + 24);
      *((_QWORD *)v84 + 5) = 0i64;
      v88 = serialization_list.mList.mNode.mPrev;
    }
    v84 = 0i64;
    v185 = 0i64;
  }
  v91 = v6->mRenderQueues[11].mNode.mNext;
  if ( v91 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v89 )
  {
    v92 = *v89;
    v88->mNext = v91;
    v91->mPrev = v88;
    v92->mNext = &serialization_list.mList.mNode;
    v88 = v92;
    serialization_list.mList.mNode.mPrev = v92;
    *v89 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v89;
    v6->mRenderQueues[11].mNode.mNext = &v6->mRenderQueues[11].mNode;
    v84 = v185;
  }
  v93 = &v6->mRenderQueues[30].mNode.mPrev;
  if ( v84 )
  {
    v94 = *((_QWORD *)v84 + 5);
    if ( v94 )
    {
      *((_DWORD *)v84 + 18) += *(_DWORD *)(v94 + 24);
      *((_QWORD *)v84 + 5) = 0i64;
      v88 = serialization_list.mList.mNode.mPrev;
    }
    v84 = 0i64;
    v185 = 0i64;
  }
  v95 = v6->mRenderQueues[30].mNode.mNext;
  if ( v95 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v93 )
  {
    v96 = *v93;
    v88->mNext = v95;
    v95->mPrev = v88;
    v96->mNext = &serialization_list.mList.mNode;
    v88 = v96;
    serialization_list.mList.mNode.mPrev = v96;
    *v93 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v93;
    v6->mRenderQueues[30].mNode.mNext = &v6->mRenderQueues[30].mNode;
    v84 = v185;
  }
  if ( v5->mRenderFeatures.mWorld )
  {
    GenerateGBufferAlphaSerializationList(&serialization_list, v6, v4);
    v84 = v185;
    v88 = serialization_list.mList.mNode.mPrev;
  }
  v97 = &v6->mRenderQueues[31].mNode.mPrev;
  if ( v84 )
  {
    v98 = *((_QWORD *)v84 + 5);
    if ( v98 )
    {
      *((_DWORD *)v84 + 18) += *(_DWORD *)(v98 + 24);
      *((_QWORD *)v84 + 5) = 0i64;
      v88 = serialization_list.mList.mNode.mPrev;
    }
    v84 = 0i64;
    v185 = 0i64;
  }
  v99 = v6->mRenderQueues[31].mNode.mNext;
  if ( v99 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v97 )
  {
    v100 = *v97;
    v88->mNext = v99;
    v99->mPrev = v88;
    v100->mNext = &serialization_list.mList.mNode;
    v88 = v100;
    serialization_list.mList.mNode.mPrev = v100;
    *v97 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v97;
    v6->mRenderQueues[31].mNode.mNext = &v6->mRenderQueues[31].mNode;
    v84 = v185;
  }
  v101 = &v6->mRenderQueues[32].mNode.mPrev;
  if ( v84 )
  {
    v102 = *((_QWORD *)v84 + 5);
    if ( v102 )
    {
      *((_DWORD *)v84 + 18) += *(_DWORD *)(v102 + 24);
      *((_QWORD *)v84 + 5) = 0i64;
      v88 = serialization_list.mList.mNode.mPrev;
    }
    v84 = 0i64;
    v185 = 0i64;
  }
  v103 = v6->mRenderQueues[32].mNode.mNext;
  if ( v103 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v101 )
  {
    v104 = *v101;
    v88->mNext = v103;
    v103->mPrev = v88;
    v104->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v104;
    *v101 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v101;
    v6->mRenderQueues[32].mNode.mNext = &v6->mRenderQueues[32].mNode;
    v84 = v185;
  }
  if ( !v84 )
  {
    v105 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v84 = v105;
    v194 = v105;
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v105;
    if ( v105 )
    {
      *(_QWORD *)v105 = v105;
      *((_QWORD *)v105 + 1) = v105;
      v106 = v105 + 16;
      v192 = v106;
      *v106 = v106;
      v106[1] = v106;
      UFG::qMemSet(v105 + 96, 0, 0x400u);
      *((_QWORD *)v84 + 11) = 0i64;
      *((_QWORD *)v84 + 10) = 0i64;
      *((_DWORD *)v84 + 8) = 0;
      *((_QWORD *)v84 + 5) = 0i64;
      *((_QWORD *)v84 + 6) = 0i64;
      *((_QWORD *)v84 + 7) = 0i64;
      *((_QWORD *)v84 + 8) = 0i64;
      *((_QWORD *)v84 + 9) = 0i64;
    }
    else
    {
      v84 = 0i64;
    }
    v185 = v84;
    v107 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v84;
    *(_QWORD *)v84 = v107;
    *((_QWORD *)v84 + 1) = (char *)&serialization_list + 16;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v84;
  }
  v108 = *((_QWORD *)v84 + 5);
  if ( v108 )
  {
    v109 = *(unsigned int *)(v108 + 24);
    if ( (unsigned int)v109 < 0x7E )
    {
      v110 = v108 + 16 * (v109 + 2);
      *(_DWORD *)(v108 + 24) = v109 + 1;
      goto LABEL_152;
    }
    if ( v108 )
    {
      *((_DWORD *)v84 + 18) += *(_DWORD *)(v108 + 24);
      *((_QWORD *)v84 + 5) = 0i64;
    }
  }
  v111 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v112 = v111;
  v194 = v111;
  if ( v111 )
  {
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v111;
    *(_QWORD *)v111 = v111;
    *((_QWORD *)v111 + 1) = v111;
    *((_QWORD *)v111 + 2) = 0i64;
    *((_DWORD *)v111 + 6) = 0;
    v113 = *((_QWORD *)v84 + 2);
    *(_QWORD *)(v113 + 8) = v112;
    *(_QWORD *)v112 = v113;
    *((_QWORD *)v112 + 1) = v84 + 16;
    *((_QWORD *)v84 + 2) = v112;
    *((_QWORD *)v84 + 5) = v112;
  }
  v114 = *((_QWORD *)v84 + 5);
  if ( v114 )
  {
    *(_DWORD *)(v114 + 24) = 1;
    v110 = *((_QWORD *)v84 + 5) + 32i64;
LABEL_152:
    if ( v110 )
    {
      *(_DWORD *)v110 = 22;
      *(_QWORD *)(v110 + 8) = &UFG::RenderWorld::msGpuTimer_DOF;
    }
  }
  v115 = &v6->mRenderQueues[33].mNode.mPrev;
  v116 = v185;
  if ( v185 )
  {
    v117 = *((_QWORD *)v185 + 5);
    if ( v117 )
    {
      *((_DWORD *)v185 + 18) += *(_DWORD *)(v117 + 24);
      *((_QWORD *)v185 + 5) = 0i64;
    }
    v116 = 0i64;
    v185 = 0i64;
  }
  v118 = v6->mRenderQueues[33].mNode.mNext;
  if ( v118 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v115 )
  {
    v119 = serialization_list.mList.mNode.mPrev;
    v120 = *v115;
    serialization_list.mList.mNode.mPrev->mNext = v118;
    v118->mPrev = v119;
    v120->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v120;
    *v115 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v115;
    v6->mRenderQueues[33].mNode.mNext = &v6->mRenderQueues[33].mNode;
    v116 = v185;
  }
  if ( !v116 )
  {
    v121 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v116 = v121;
    v194 = v121;
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v121;
    if ( v121 )
    {
      *(_QWORD *)v121 = v121;
      *((_QWORD *)v121 + 1) = v121;
      v122 = v121 + 16;
      v192 = v122;
      *v122 = v122;
      v122[1] = v122;
      UFG::qMemSet(v121 + 96, 0, 0x400u);
      *((_QWORD *)v116 + 11) = 0i64;
      *((_QWORD *)v116 + 10) = 0i64;
      *((_DWORD *)v116 + 8) = 0;
      *((_QWORD *)v116 + 5) = 0i64;
      *((_QWORD *)v116 + 6) = 0i64;
      *((_QWORD *)v116 + 7) = 0i64;
      *((_QWORD *)v116 + 8) = 0i64;
      *((_QWORD *)v116 + 9) = 0i64;
    }
    else
    {
      v116 = 0i64;
    }
    v185 = v116;
    v123 = serialization_list.mList.mNode.mPrev;
    serialization_list.mList.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v116;
    *(_QWORD *)v116 = v123;
    *((_QWORD *)v116 + 1) = (char *)&serialization_list + 16;
    serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v116;
  }
  v124 = *((_QWORD *)v116 + 5);
  if ( v124 )
  {
    v125 = *(unsigned int *)(v124 + 24);
    if ( (unsigned int)v125 < 0x7E )
    {
      v126 = v124 + 16 * (v125 + 2);
      *(_DWORD *)(v124 + 24) = v125 + 1;
      goto LABEL_174;
    }
    if ( v124 )
    {
      *((_DWORD *)v116 + 18) += *(_DWORD *)(v124 + 24);
      *((_QWORD *)v116 + 5) = 0i64;
    }
  }
  v127 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v128 = v127;
  v194 = v127;
  if ( v127 )
  {
    v195 = (UFG::qList<SerializationList,SerializationList,1,0> *)v127;
    *(_QWORD *)v127 = v127;
    *((_QWORD *)v127 + 1) = v127;
    *((_QWORD *)v127 + 2) = 0i64;
    *((_DWORD *)v127 + 6) = 0;
    v129 = *((_QWORD *)v116 + 2);
    *(_QWORD *)(v129 + 8) = v128;
    *(_QWORD *)v128 = v129;
    *((_QWORD *)v128 + 1) = v116 + 16;
    *((_QWORD *)v116 + 2) = v128;
    *((_QWORD *)v116 + 5) = v128;
  }
  v130 = *((_QWORD *)v116 + 5);
  if ( v130 )
  {
    *(_DWORD *)(v130 + 24) = 1;
    v126 = *((_QWORD *)v116 + 5) + 32i64;
LABEL_174:
    if ( v126 )
    {
      *(_DWORD *)v126 = 23;
      *(_QWORD *)(v126 + 8) = &UFG::RenderWorld::msGpuTimer_DOF;
    }
  }
  v131 = &v6->mRenderQueues[34].mNode.mPrev;
  v132 = v185;
  if ( v185 )
  {
    v133 = *((_QWORD *)v185 + 5);
    if ( v133 )
    {
      *((_DWORD *)v185 + 18) += *(_DWORD *)(v133 + 24);
      *((_QWORD *)v185 + 5) = 0i64;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v134 = v6->mRenderQueues[34].mNode.mNext;
  if ( v134 == (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v131 )
  {
    v136 = serialization_list.mList.mNode.mPrev;
  }
  else
  {
    v135 = serialization_list.mList.mNode.mPrev;
    v136 = *v131;
    serialization_list.mList.mNode.mPrev->mNext = v134;
    v134->mPrev = v135;
    v136->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v136;
    *v131 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v131;
    v6->mRenderQueues[34].mNode.mNext = &v6->mRenderQueues[34].mNode;
    v132 = v185;
  }
  v137 = &v6->mRenderQueues[35].mNode.mPrev;
  if ( v132 )
  {
    v138 = *((_QWORD *)v132 + 5);
    if ( v138 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v138 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v139 = v6->mRenderQueues[35].mNode.mNext;
  if ( v139 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v137 )
  {
    v140 = *v137;
    v136->mNext = v139;
    v139->mPrev = v136;
    v140->mNext = &serialization_list.mList.mNode;
    v136 = v140;
    serialization_list.mList.mNode.mPrev = v140;
    *v137 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v137;
    v6->mRenderQueues[35].mNode.mNext = &v6->mRenderQueues[35].mNode;
    v132 = v185;
  }
  v141 = &v6->mRenderQueues[36].mNode.mPrev;
  if ( v132 )
  {
    v142 = *((_QWORD *)v132 + 5);
    if ( v142 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v142 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v143 = v6->mRenderQueues[36].mNode.mNext;
  if ( v143 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v141 )
  {
    v144 = *v141;
    v136->mNext = v143;
    v143->mPrev = v136;
    v144->mNext = &serialization_list.mList.mNode;
    v136 = v144;
    serialization_list.mList.mNode.mPrev = v144;
    *v141 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v141;
    v6->mRenderQueues[36].mNode.mNext = &v6->mRenderQueues[36].mNode;
    v132 = v185;
  }
  v145 = &v6->mRenderQueues[38].mNode.mPrev;
  if ( v132 )
  {
    v146 = *((_QWORD *)v132 + 5);
    if ( v146 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v146 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v147 = v6->mRenderQueues[38].mNode.mNext;
  if ( v147 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v145 )
  {
    v148 = *v145;
    v136->mNext = v147;
    v147->mPrev = v136;
    v148->mNext = &serialization_list.mList.mNode;
    v136 = v148;
    serialization_list.mList.mNode.mPrev = v148;
    *v145 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v145;
    v6->mRenderQueues[38].mNode.mNext = &v6->mRenderQueues[38].mNode;
    v132 = v185;
  }
  v149 = &v6->mRenderQueues[37].mNode.mPrev;
  if ( v132 )
  {
    v150 = *((_QWORD *)v132 + 5);
    if ( v150 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v150 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v151 = v6->mRenderQueues[37].mNode.mNext;
  if ( v151 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v149 )
  {
    v152 = *v149;
    v136->mNext = v151;
    v151->mPrev = v136;
    v152->mNext = &serialization_list.mList.mNode;
    v136 = v152;
    serialization_list.mList.mNode.mPrev = v152;
    *v149 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v149;
    v6->mRenderQueues[37].mNode.mNext = &v6->mRenderQueues[37].mNode;
    v132 = v185;
  }
  v153 = &v6->mRenderQueues[39].mNode.mPrev;
  if ( v132 )
  {
    v154 = *((_QWORD *)v132 + 5);
    if ( v154 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v154 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v155 = v6->mRenderQueues[39].mNode.mNext;
  if ( v155 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v153 )
  {
    v156 = *v153;
    v136->mNext = v155;
    v155->mPrev = v136;
    v156->mNext = &serialization_list.mList.mNode;
    v136 = v156;
    serialization_list.mList.mNode.mPrev = v156;
    *v153 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v153;
    v6->mRenderQueues[39].mNode.mNext = &v6->mRenderQueues[39].mNode;
    v132 = v185;
  }
  v157 = &v6->mRenderQueues[43].mNode.mPrev;
  if ( v132 )
  {
    v158 = *((_QWORD *)v132 + 5);
    if ( v158 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v158 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v159 = v6->mRenderQueues[43].mNode.mNext;
  if ( v159 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v157 )
  {
    v160 = *v157;
    v136->mNext = v159;
    v159->mPrev = v136;
    v160->mNext = &serialization_list.mList.mNode;
    v136 = v160;
    serialization_list.mList.mNode.mPrev = v160;
    *v157 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v157;
    v6->mRenderQueues[43].mNode.mNext = &v6->mRenderQueues[43].mNode;
    v132 = v185;
  }
  v161 = &v6->mRenderQueues[40].mNode.mPrev;
  if ( v132 )
  {
    v162 = *((_QWORD *)v132 + 5);
    if ( v162 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v162 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v163 = v6->mRenderQueues[40].mNode.mNext;
  if ( v163 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v161 )
  {
    v164 = *v161;
    v136->mNext = v163;
    v163->mPrev = v136;
    v164->mNext = &serialization_list.mList.mNode;
    v136 = v164;
    serialization_list.mList.mNode.mPrev = v164;
    *v161 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v161;
    v6->mRenderQueues[40].mNode.mNext = &v6->mRenderQueues[40].mNode;
    v132 = v185;
  }
  v165 = &v6->mRenderQueues[41].mNode.mPrev;
  if ( v132 )
  {
    v166 = *((_QWORD *)v132 + 5);
    if ( v166 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v166 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
    v132 = 0i64;
    v185 = 0i64;
  }
  v167 = v6->mRenderQueues[41].mNode.mNext;
  if ( v167 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v165 )
  {
    v168 = *v165;
    v136->mNext = v167;
    v167->mPrev = v136;
    v168->mNext = &serialization_list.mList.mNode;
    v136 = v168;
    serialization_list.mList.mNode.mPrev = v168;
    *v165 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v165;
    v6->mRenderQueues[41].mNode.mNext = &v6->mRenderQueues[41].mNode;
    v132 = v185;
  }
  v169 = (signed __int64)&v6->mRenderQueues[42];
  if ( v132 )
  {
    v170 = *((_QWORD *)v132 + 5);
    if ( v170 )
    {
      *((_DWORD *)v132 + 18) += *(_DWORD *)(v170 + 24);
      *((_QWORD *)v132 + 5) = 0i64;
      v136 = serialization_list.mList.mNode.mPrev;
    }
  }
  v171 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)(v169 + 8);
  if ( v171 != (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v169 )
  {
    v172 = *(UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **)v169;
    v136->mNext = v171;
    v171->mPrev = v136;
    v172->mNext = &serialization_list.mList.mNode;
    serialization_list.mList.mNode.mPrev = v172;
    *(_QWORD *)v169 = v169;
    *(_QWORD *)(v169 + 8) = v169;
  }
  SerializationList::AddCommand(&serialization_list, 23, &UFG::RenderWorld::msGpuTimer_PostFX);
  FlushJobQueue::AddFlushJob(v19, &serialization_list, 5u, 0x7FFFu, 0);
  if ( v5->mRenderFeatures.mWorld && gUpdateFog && fTime > 0.0 )
  {
    v173 = UFG::TimeOfDayManager::GetInstance();
    v174 = UFG::TimeOfDayManager::UpdateFog(v173, v5->mEnvState, 0, v5->mRenderFeatures.mAlternateGradientBackground);
    FlushJobQueue::AddTaskGroup(v19, (UFG::qTaskGroup *)v174);
  }
  v194 = &serialization_list.mNext;
  UFG::qList<SerializationList,SerializationList,1,0>::DeleteNodes((UFG::qList<SerializationList,SerializationList,1,0> *)&serialization_list.mNext);
  v175 = serialization_list.mNext;
  v176 = serialization_list.mList.mNode.mPrev;
  serialization_list.mNext->mNext = (UFG::qNode<SerializationList,SerializationList> *)serialization_list.mList.mNode.mPrev;
  v176->mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v175;
  serialization_list.mNext = (UFG::qNode<SerializationList,SerializationList> *)&serialization_list.mNext;
  serialization_list.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&serialization_list.mNext;
  v194 = &serialization_list.mList;
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&serialization_list.mList);
  v177 = serialization_list.mList.mNode.mPrev;
  serialization_list.mList.mNode.mPrev->mNext = v178;
  v178->mPrev = v177;
  v179 = serialization_list.mPrev;
  v180 = serialization_list.mNext;
  serialization_list.mPrev->mNext = serialization_list.mNext;
  v180->mPrev = v179;
}rialization_list.mPrev->mNext = serialization_list.mNext;
  v180->mPrev = v179;
}

// File Line: 2845
// RVA: 0x4FA40
MainViewTargetParams *__fastcall GetMainViewTargets(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rsi
  char *v2; // rax
  _QWORD *v3; // rdi
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax

  v1 = render_context;
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
    *(_QWORD *)v4 = v1->mGBufferTarget;
    *((_QWORD *)v4 + 1) = 0i64;
    *((_DWORD *)v4 + 4) = 5;
    *((_QWORD *)v4 + 3) = "GBuffer";
  }
  *v3 = v4;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  v3[3] = v5;
  Illusion::SetFullscreenViewportScissor(v1->mGBufferTarget, (Illusion::ViewportScissorState *)v5, 0);
  if ( v1->mGBufferDepthTarget )
  {
    v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    if ( v6 )
    {
      *(_QWORD *)v6 = v1->mGBufferDepthTarget;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_DWORD *)v6 + 4) = 5;
      *((_QWORD *)v6 + 3) = "GBufferDepth";
    }
    v3[1] = v6;
  }
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  if ( v7 )
  {
    *(_QWORD *)v7 = v1->mDynamicRangeTarget;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_DWORD *)v7 + 4) = 0;
    *((_QWORD *)v7 + 3) = "GBufferAlpha";
  }
  v3[2] = v7;
  return (MainViewTargetParams *)v3;
}

// File Line: 2897
// RVA: 0x5BC60
SceneryTaskRenderQueueResults *__fastcall SubmitRenderSceneryTasks(UFG::qTaskGroup *task_group_dep, UFG::RenderContext *render_context, MainViewTargetParams *main_view_target_params, int cull_index)
{
  UFG::RenderContext *v4; // rdi
  UFG::qTaskGroup *v5; // rbx
  const float *v6; // rsi
  const float *v7; // r14
  const float *v8; // r15
  unsigned __int16 v9; // ax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm8_4
  char *v13; // rax
  char *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r15
  char *v17; // rax
  UFG::qTaskGroup *v18; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v19; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v20; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v21; // r14
  char **v22; // r12
  signed __int64 v23; // r13
  int v24; // xmm10_4
  char *v25; // rax
  char *v26; // rbx
  Render::EnvCubeMap *v27; // rax
  UFG::qResourceData *v28; // rcx
  UFG::TimeOfDayManager *v29; // rax
  UFG::qResourceData *v30; // rcx
  Illusion::Target *v31; // rax
  Illusion::Texture *v32; // rcx
  Illusion::Target *v33; // rax
  UFG::qResourceData *v34; // rcx
  _QWORD *v35; // rcx
  float v36; // xmm7_4
  float v37; // xmm6_4
  char *v38; // rax
  UFG::qResourceData *v39; // rax
  UFG::qVector4 *v40; // rax
  char *v41; // rax
  float v42; // xmm1_4
  UFG::qVector4 v43; // xmm2
  UFG::qVector4 v44; // xmm1
  UFG::qVector4 v45; // xmm0
  UFG::qVector4 v46; // xmm2
  UFG::qVector4 v47; // xmm1
  UFG::qVector4 v48; // xmm0
  int v49; // er9
  _QWORD *v50; // rdx
  _DWORD *v51; // r8
  __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  _QWORD *v55; // rcx
  UFG::qSpuElf *v56; // rax
  void (__fastcall *v57)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v58)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v59)(void *, void *, void *, void *); // r9
  char *v60; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v61; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v62; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rax
  signed __int64 v65; // [rsp+20h] [rbp-A8h]
  Render::cbShadowTransformState v66; // [rsp+30h] [rbp-98h]
  UFG::qMatrix44 d; // [rsp+88h] [rbp-40h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+C8h] [rbp+0h]
  Illusion::StateValues state_values; // [rsp+2C8h] [rbp+200h]
  char *v70; // [rsp+770h] [rbp+6A8h]
  _QWORD *v71; // [rsp+778h] [rbp+6B0h]
  int v72; // [rsp+780h] [rbp+6B8h]
  int v73; // [rsp+788h] [rbp+6C0h]

  v66.mBlurWidths = (const float *)-2i64;
  v4 = render_context;
  v5 = task_group_dep;
  if ( !render_context->mRenderFeatures.mWorld || !render_context->mRenderFeatures.mScenery )
    return 0i64;
  UFG::qMemSet(state_values.mParamValues, 0, 0x400u);
  state_values.mSetValueMask.mFlags[1] = 0i64;
  state_values.mSetValueMask.mFlags[0] = 0i64;
  UFG::qInverseAffine(&d, &v4->mMainViewSettings.mWorldView);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  v6 = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  v7 = UFG::RenderWorld::msStageShadow->mBiases;
  v8 = UFG::RenderWorld::msStageShadow->mCutplanes;
  v66.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mCallback = 0i64;
  v66.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v66.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v9;
    v66.mStateParamIndex = v9;
  }
  v66.mViewWorld = &d;
  v66.mWorldView = (UFG::qMatrix44 *)&views;
  v66.mProjection = views.mProjection;
  v66.mCutplanes = v8;
  v66.mBiases = v7;
  v66.mBlurWidths = v6;
  *(_QWORD *)&v66.mStateParamIndex = 0i64;
  Render::cbShadowTransformState::SetStateBlock(&v66, &state_values);
  v66.mProjection = (UFG::qMatrix44 *)state_values.mParamValues[64];
  v10 = v4->mMainViewSettings.mProjection.v2.z;
  v11 = v4->mMainViewSettings.mProjection.v2.w;
  if ( v10 == 0.0 || v10 == v11 )
    v12 = *(float *)&v70;
  else
    v12 = (float)(v4->mMainViewSettings.mProjection.v3.z - v4->mMainViewSettings.mProjection.v3.w) / (float)(v10 - v11);
  v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v66.mBiases = (const float *)v13;
  *(_QWORD *)v13 = 0i64;
  *((_DWORD *)v13 + 2) = 0;
  *((_DWORD *)v13 + 3) = 1065353216;
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x740u, 0x20u);
  v70 = v14;
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
  v70 = v17;
  if ( v17 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v17, "RenderScenery");
  v19 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v20 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v20->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v18->mPrev;
  v18->mPrev = v20;
  v18->mNext = &v19->mNode;
  v19->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v18->mPrev;
  if ( v5 )
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v18, v5);
  v21 = &v18->mTasks;
  v22 = (char **)(v16 + 40);
  v70 = (char *)(v16 + 1200);
  v23 = v16 + 80;
  v65 = 5i64;
  v24 = v73;
  do
  {
    v25 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x330u, 0x10u);
    v26 = v25;
    *v22 = v25;
    *(_DWORD *)v25 = 1;
    *((_QWORD *)v25 + 1) = gSceneryCullLayer;
    *((_QWORD *)v25 + 2) = v16;
    *((_DWORD *)v25 + 6) = gSceneryTaskMaxRQPrimCount;
    *((_QWORD *)v25 + 4) = Render::GetViewStateBlockParams();
    *((_QWORD *)v26 + 5) = v23;
    *((_DWORD *)v26 + 12) = Illusion::gEngine.mFrameCount;
    *((_QWORD *)v26 + 7) = v4->mEnvState;
    *((_DWORD *)v26 + 39) = Render::TransparencySystem::msTransparencyFrameCounter;
    v27 = v4->mEnvCubeMap;
    if ( v27 )
      v28 = (UFG::qResourceData *)&v27->mTarget->mTargetTexture[0]->mNode;
    else
      v28 = gDefaultBlackTexture.mData;
    *((_QWORD *)v26 + 8) = v28;
    v29 = UFG::TimeOfDayManager::GetInstance();
    *((_QWORD *)v26 + 9) = UFG::TimeOfDayManager::GetFogTexture(v29);
    if ( v4->mReflection )
      v30 = (UFG::qResourceData *)&v4->mReflectionMipTarget->mTargetTexture[0]->mNode;
    else
      v30 = gDefaultBlackTexture.mData;
    *((_QWORD *)v26 + 10) = v30;
    *((_QWORD *)v26 + 11) = gArcTanTexture.mData;
    if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherSurfaceWetness != 0.0
      && (v31 = v4->mSphericalEnvMapTarget) != 0i64 )
    {
      v32 = v31->mTargetTexture[0];
    }
    else
    {
      v32 = 0i64;
    }
    *((_QWORD *)v26 + 12) = v32;
    v33 = v4->mSphericalEnvMapTarget;
    if ( v33 )
      v34 = (UFG::qResourceData *)&v33->mTargetTexture[0]->mNode;
    else
      v34 = gDefaultBlackTexture.mData;
    *((_QWORD *)v26 + 13) = v34;
    *((_QWORD *)v26 + 14) = UFG::Water::GetRippleMap(0);
    *((_QWORD *)v26 + 97) = v4->mHalfSizeShadowAliasTexture;
    *((_QWORD *)v26 + 98) = v66.mProjection;
    *((_DWORD *)v26 + 60) = gSceneryTaskMaxRQCmdCount;
    v35 = v71;
    *((_QWORD *)v26 + 15) = *v71;
    *((_QWORD *)v26 + 16) = v35[2];
    *((_DWORD *)v26 + 34) = v72;
    *((_QWORD *)v26 + 18) = v70;
    *((_DWORD *)v26 + 38) = v24;
    *((_QWORD *)v26 + 20) = Illusion::gEngine.FrameMemory;
    v36 = UFG::Metrics::msInstance.mSimTimeDelta;
    v37 = UFG::Metrics::msInstance.mSimTime_Temp;
    v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v38 = v37;
    *((float *)v38 + 1) = v36;
    *((_QWORD *)v26 + 21) = v38;
    *((_QWORD *)v26 + 22) = AlphaStateNoneHandle.mData;
    *((_QWORD *)v26 + 23) = AlphaStateNoneHandle.mData;
    *((_QWORD *)v26 + 24) = RasterStateNormalHandle.mData;
    v39 = 0i64;
    if ( v4->mRenderFeatures.mForceSceneryDoubleSided )
      v39 = RasterStateDoubleSidedHandle.mData;
    *((_QWORD *)v26 + 25) = v39;
    v40 = 0i64;
    if ( v4->mRenderFeatures.mForceSceneryDoubleSided )
      v40 = &UFG::qVector4::msZero;
    *((_QWORD *)v26 + 26) = v40;
    *((_DWORD *)v26 + 54) = Render::TransparencySystem::msNumTransparencyStateHandles;
    v41 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x620u, 0x20u);
    v66.mWorldView = (UFG::qMatrix44 *)v41;
    v66.mCutplanes = (const float *)v41;
    if ( v41 )
      RenderQueueResults::RenderQueueResults((RenderQueueResults *)v41);
    *((_QWORD *)v26 + 28) = v41;
    *((_QWORD *)v26 + 29) = UFG::Water::GetWaterSettings();
    v42 = Render::View::mScreenOffset.y;
    *((_DWORD *)v26 + 61) = LODWORD(Render::View::mScreenOffset.x);
    *((float *)v26 + 62) = v42;
    v43 = v4->mMainViewSettings.mWorldView.v1;
    v44 = v4->mMainViewSettings.mWorldView.v2;
    v45 = v4->mMainViewSettings.mWorldView.v3;
    *((_OWORD *)v26 + 16) = v4->mMainViewSettings.mWorldView.v0;
    *((UFG::qVector4 *)v26 + 17) = v43;
    *((UFG::qVector4 *)v26 + 18) = v44;
    *((UFG::qVector4 *)v26 + 19) = v45;
    v46 = v4->mMainViewSettings.mProjection.v1;
    v47 = v4->mMainViewSettings.mProjection.v2;
    v48 = v4->mMainViewSettings.mProjection.v3;
    *((_OWORD *)v26 + 20) = v4->mMainViewSettings.mProjection.v0;
    *((UFG::qVector4 *)v26 + 21) = v46;
    *((UFG::qVector4 *)v26 + 22) = v47;
    *((UFG::qVector4 *)v26 + 23) = v48;
    *((_QWORD *)v26 + 99) = v66.mBiases;
    *((float *)v26 + 200) = v12;
    *((_DWORD *)v26 + 201) = UFG::RenderWorld::msEnableWater;
    *((float *)v26 + 202) = gSceneryThresholdLodB;
    v49 = 0;
    if ( *((_DWORD *)v26 + 54) > 0 )
    {
      v50 = v26 + 648;
      v51 = v26 + 452;
      v52 = 0i64;
      do
      {
        *(v51 - 16) = *(_DWORD *)(v52 + 5403479832i64);
        *(v50 - 16) = *(_QWORD *)(v52 + 5403479824i64);
        *v51 = *(_DWORD *)(v52 + 5403480344i64);
        *v50 = *(_QWORD *)(v52 + 5403480336i64);
        ++v49;
        ++v51;
        ++v50;
        v52 += 32i64;
      }
      while ( v49 < *((_DWORD *)v26 + 54) );
    }
    v53 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v54 = v53;
    v66.mCutplanes = (const float *)v53;
    v66.mWorldView = (UFG::qMatrix44 *)v53;
    if ( v53 )
    {
      *(_QWORD *)v53 = v53;
      *((_QWORD *)v53 + 1) = v53;
      v55 = v53 + 16;
      *v55 = v55;
      v55[1] = v55;
      v56 = gTaskFunctionDeclData_RenderSceneryTask.mSpuElf;
      v57 = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionSPU;
      v58 = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionPPU;
      v59 = gTaskFunctionDeclData_RenderSceneryTask.mTaskFunctionOffload;
      if ( !gTaskFunctionDeclData_RenderSceneryTask.mCurrentSPUEnabled )
      {
        v56 = 0i64;
        v57 = 0i64;
        v59 = 0i64;
      }
      *((_QWORD *)v54 + 6) = v18;
      *((_DWORD *)v54 + 14) = 2;
      *((_QWORD *)v54 + 4) = 0i64;
      *((_QWORD *)v54 + 5) = 0i64;
      *((_QWORD *)v54 + 8) = &gTaskFunctionDeclData_RenderSceneryTask;
      if ( v56 )
        v60 = v56->mAddress;
      else
        v60 = 0i64;
      *((_QWORD *)v54 + 9) = v60;
      *((_QWORD *)v54 + 10) = v57;
      *((_QWORD *)v54 + 11) = v58;
      *((_QWORD *)v54 + 12) = v26;
      *((_QWORD *)v54 + 13) = 0i64;
      *((_QWORD *)v54 + 14) = 0i64;
      *((_QWORD *)v54 + 15) = 0i64;
      if ( v59 )
      {
        *((_DWORD *)v54 + 14) = 130;
        *((_DWORD *)v54 + 12) = 0;
      }
    }
    v61 = v21->mNode.mPrev;
    v61->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v54;
    *(_QWORD *)v54 = v61;
    *((_QWORD *)v54 + 1) = v21;
    v21->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v54;
    ++v18->mNumTasks;
    v23 += 224i64;
    v70 += 128;
    ++v22;
    --v65;
  }
  while ( v65 );
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v18);
  *(_QWORD *)(v16 + 1840) = v18;
  v62 = v66.mPrev;
  v63 = v66.mNext;
  v66.mPrev->mNext = v66.mNext;
  v63->mPrev = v62;
  v66.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  return (SceneryTaskRenderQueueResults *)v16;
}

// File Line: 3033
// RVA: 0x58680
SimRenderQueueResults *__fastcall RenderSimMain(UFG::RenderContext *render_context, MainViewTargetParams *main_view_target_params, Render::RenderPassCollector *render_pass_collector)
{
  Render::RenderPassCollector *v3; // r13
  __int64 *v4; // r15
  UFG::RenderContext *v5; // rsi
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  bool v10; // cl
  UFG::qResourceData *v11; // rax
  UFG::qVector4 *v12; // rax
  Illusion::StateValues *v13; // rdi
  __int64 v14; // rcx
  void *v15; // rcx
  unsigned __int16 v16; // ax
  char *v17; // rax
  Illusion::ShaderSelector *v18; // rbx
  Render::EnvCubeMap *v19; // rax
  UFG::qResourceData *v20; // rcx
  UFG::TimeOfDayManager *v21; // rax
  Illusion::Texture *v22; // rax
  UFG::qResourceData *v23; // rcx
  UFG::qResourceData *v24; // rax
  CB_EnvironmentSettings *v25; // rax
  float v26; // xmm7_4
  float v27; // xmm6_4
  char *v28; // rax
  Illusion::Texture *v29; // rax
  Illusion::Texture *v30; // rax
  Illusion::Target *v31; // rax
  UFG::qResourceData *v32; // rax
  CB_WaterOffset *v33; // rax
  Illusion::Target *v34; // rax
  UFG::qResourceData *v35; // rax
  char *v36; // rax
  const float *v37; // rdi
  const float *v38; // r15
  const float *v39; // r12
  unsigned __int16 v40; // ax
  Illusion::StateArgs *v41; // rax
  Illusion::StateValues *v42; // rax
  Render::ViewSettings *v43; // rdi
  UFG::qMatrix44 *v44; // r15
  unsigned __int16 v45; // ax
  Illusion::StateArgs *v46; // rax
  Render::RenderCallbacks *v47; // rax
  Illusion::StateArgs *v48; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v49; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rcx
  Illusion::StateArgs *v51; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v54; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v55; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v56; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v57; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v58; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v59; // rax
  Render::cbExternalViewTransformState v60; // [rsp+30h] [rbp-D0h]
  Render::cbShadowTransformState arg; // [rsp+70h] [rbp-90h]
  Render::cbViewTransformState v62; // [rsp+D0h] [rbp-30h]
  Render::FXManagerAuxBuffers auxBuffers; // [rsp+120h] [rbp+20h]
  UFG::qResourceData *v64; // [rsp+148h] [rbp+48h]
  UFG::qResourceData *v65; // [rsp+150h] [rbp+50h]
  UFG::qResourceData *v66; // [rsp+158h] [rbp+58h]
  UFG::qVector4 *v67; // [rsp+160h] [rbp+60h]
  UFG::qResourceData *v68; // [rsp+168h] [rbp+68h]
  __int64 v69; // [rsp+170h] [rbp+70h]
  __int64 v70; // [rsp+178h] [rbp+78h]
  __int64 v71; // [rsp+180h] [rbp+80h]
  Render::View view; // [rsp+190h] [rbp+90h]
  RenderQueueLayer v73; // [rsp+320h] [rbp+220h]
  UFG::qMatrix44 result; // [rsp+400h] [rbp+300h]
  UFG::qMatrix44 d; // [rsp+440h] [rbp+340h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+480h] [rbp+380h]
  LayerSubmitContext ptr; // [rsp+680h] [rbp+580h]
  GBufferSubmitContext v78; // [rsp+1300h] [rbp+1200h]
  char *v79; // [rsp+1FF0h] [rbp+1EF0h]
  char *v80; // [rsp+1FF0h] [rbp+1EF0h]
  Illusion::StateArgs *v81; // [rsp+1FF0h] [rbp+1EF0h]
  char *v82; // [rsp+2008h] [rbp+1F08h]
  char *v83; // [rsp+2008h] [rbp+1F08h]

  v71 = -2i64;
  v3 = render_pass_collector;
  v4 = (__int64 *)main_view_target_params;
  v5 = render_context;
  if ( !render_context->mRenderFeatures.mWorld )
    return 0i64;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1F0u, 0x10u);
  v79 = v7;
  v82 = v7;
  if ( v7 )
  {
    SimRenderQueueResults::SimRenderQueueResults((SimRenderQueueResults *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  GBufferSubmitContext::GBufferSubmitContext(&v78);
  v68 = AlphaStateNoneHandle.mData;
  v64 = AlphaStateDeferredPunchThroughHandle.mData;
  v65 = RasterStateNormalHandle.mData;
  v10 = v5->mRenderFeatures.mForceSceneryDoubleSided;
  v11 = 0i64;
  if ( v10 )
    v11 = RasterStateDoubleSidedHandle.mData;
  v66 = v11;
  v12 = 0i64;
  if ( v10 )
    v12 = &UFG::qVector4::msZero;
  v67 = v12;
  v70 = v4[2];
  v69 = *v4;
  v78.mPerPhaseParams = (GBufferSubmitContext::PerPhaseParams *)&v64;
  Render::View::View(&view, &v5->mMainViewSettings, (Illusion::SubmitContext *)&v78.vfptr);
  v13 = Render::View::GetStateValues(&view);
  UFG::qMemSet(v13->mParamValues, 0, 0x400u);
  v13->mSetValueMask.mFlags[1] = 0i64;
  v13->mSetValueMask.mFlags[0] = 0i64;
  Render::View::Metric_BeginTarget(&view);
  v14 = *v4;
  v13->mSetValueMask.mFlags[0] |= 0x800ui64;
  v13->mParamValues[11] = (void *)v14;
  v15 = (void *)v4[3];
  v13->mSetValueMask.mFlags[0] |= 0x1000ui64;
  v13->mParamValues[12] = v15;
  UFG::qMatrix44::operator*(&v5->mMainViewSettings.mWorldView, &result, &v5->mMainViewSettings.mProjection);
  UFG::qInverseAffine(&d, &v5->mMainViewSettings.mWorldView);
  v62.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v62;
  v62.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v62;
  v62.mCallback = 0i64;
  v62.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v62.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
  {
    v16 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = v16;
    v62.mStateParamIndex = v16;
  }
  v62.mWorldViewProjection = &result;
  v62.mViewWorld = &d;
  v62.mProjection = &v5->mMainViewSettings.mProjection;
  v62.mScreenOffset = &Render::View::mScreenOffset;
  v62.mCached_Remote.m_Stream = 0i64;
  Render::cbViewTransformState::SetStateBlock(&v62, v13);
  v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
  v18 = (Illusion::ShaderSelector *)v17;
  v80 = v17;
  v83 = v17;
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
  v78.mShaderSelector = v18;
  v19 = v5->mEnvCubeMap;
  if ( v19 )
    v20 = (UFG::qResourceData *)&v19->mTarget->mTargetTexture[0]->mNode;
  else
    v20 = gDefaultBlackTexture.mData;
  v13->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
  v13->mParamValues[40] = v20;
  v21 = UFG::TimeOfDayManager::GetInstance();
  v22 = UFG::TimeOfDayManager::GetFogTexture(v21);
  v13->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  v13->mParamValues[41] = v22;
  if ( v5->mReflection )
    v23 = (UFG::qResourceData *)&v5->mReflectionMipTarget->mTargetTexture[0]->mNode;
  else
    v23 = gDefaultBlackTexture.mData;
  v13->mSetValueMask.mFlags[0] |= 0x20000000000000ui64;
  v13->mParamValues[53] = v23;
  v24 = gArcTanTexture.mData;
  v13->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
  v13->mParamValues[43] = v24;
  v25 = v5->mEnvState;
  v13->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v13->mParamValues[55] = v25;
  v26 = UFG::Metrics::msInstance.mSimTimeDelta;
  v27 = UFG::Metrics::msInstance.mSimTime_Temp;
  v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v28 = v27;
  *((float *)v28 + 1) = v26;
  v13->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v13->mParamValues[13] = v28;
  v29 = v5->mHalfSizeShadowAliasTexture;
  v13->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v13->mParamValues[61] = v29;
  v30 = UFG::Water::GetRippleMap(1);
  v13->mSetValueMask.mFlags[0] |= 0x800000000000000ui64;
  v13->mParamValues[59] = v30;
  v31 = v5->mSphericalEnvMapTarget;
  if ( v31 )
    v32 = (UFG::qResourceData *)&v31->mTargetTexture[0]->mNode;
  else
    v32 = gDefaultBlackTexture.mData;
  v13->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
  v13->mParamValues[58] = v32;
  v33 = UFG::Water::GetWaterSettings();
  v13->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
  v13->mParamValues[45] = v33;
  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherSurfaceWetness != 0.0 )
  {
    v34 = v5->mSphericalEnvMapTarget;
    if ( v34 )
      v35 = (UFG::qResourceData *)&v34->mTargetTexture[0]->mNode;
    else
      v35 = gDefaultBlackTexture.mData;
    v13->mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
    v13->mParamValues[57] = v35;
  }
  v36 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(_QWORD *)v36 = 0i64;
  *((_DWORD *)v36 + 2) = 0;
  *((_DWORD *)v36 + 3) = 1065353216;
  v13->mSetValueMask.mFlags[0] |= 0x100000000ui64;
  v13->mParamValues[32] = v36;
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  v37 = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  v38 = UFG::RenderWorld::msStageShadow->mBiases;
  v39 = UFG::RenderWorld::msStageShadow->mCutplanes;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v40 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v40;
    arg.mStateParamIndex = v40;
  }
  arg.mViewWorld = &view.mViewWorld;
  arg.mWorldView = (UFG::qMatrix44 *)&views;
  arg.mProjection = views.mProjection;
  arg.mCutplanes = v39;
  arg.mBiases = v38;
  arg.mBlurWidths = v37;
  arg.mCached_Remote.m_Stream = 0i64;
  v41 = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v41, &arg);
  v42 = Render::View::GetStateValues(&view);
  Render::cbShadowTransformState::SetStateBlock(&arg, v42);
  v43 = view.mSettings;
  v44 = &view.mSettings->mProjection;
  v60.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v60.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v60.mCallback = 0i64;
  v60.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v60.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v45 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v45;
    v60.mStateParamIndex = v45;
  }
  v60.mWorldView = &v43->mWorldView;
  v60.mProjection = v44;
  v60.mCached_Remote.m_Stream = 0i64;
  v46 = Render::View::GetStateArgs(&view);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v46, &v60);
  Render::View::SetSimpleMaterialShader(0x192E0D6u);
  if ( v5->mRenderFeatures.mScenery )
  {
    v78.mRenderQueueProvider = (RenderQueueLayer *)v9;
    if ( Render::GetRenderCallbacks()->mRenderSim )
    {
      v47 = Render::GetRenderCallbacks();
      v47->mRenderSim(v5, &view);
    }
    Render::RenderPassSystem::DrawRenderPass(v3, &view, 0);
  }
  _mm_store_si128((__m128i *)&v78.mCullMetrics, (__m128i)0i64);
  if ( gRenderFX )
  {
    v78.mRenderQueueProvider = (RenderQueueLayer *)(v9 + 224);
    auxBuffers.scrDepth = 0i64;
    auxBuffers.scrDiffuse = 0i64;
    auxBuffers.texShadowAtlas = 0i64;
    auxBuffers.texHeightmap = 0i64;
    auxBuffers.texHeightmapShadow = 0i64;
    Render::FXManager::Render(&Render::gFXManager, &view, UFG::Metrics::msInstance.mSimTime_Temp, 0, &auxBuffers);
    Render::DecalManager::Render(&Render::gDecalManager, &view, UFG::Metrics::msInstance.mSimTime_Temp, 0);
  }
  v48 = Render::View::GetStateArgs(&view);
  v49 = v60.mPrev;
  v50 = v60.mNext;
  v60.mPrev->mNext = v60.mNext;
  v50->mPrev = v49;
  v60.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v60.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v60.mIsSet = 0;
  if ( (Illusion::StateArgs *)v48->mStateArgsCreateMask.mFlags[2 * (v60.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v48 + 16 * (v60.mStateParamIndex + 3i64)) )
    v48->mStateArgsCreateMask.mFlags[(unsigned int)v60.mStateParamIndex >> 6] &= ~(1i64 << (v60.mStateParamIndex & 0x3F));
  v51 = Render::View::GetStateArgs(&view);
  v52 = arg.mPrev;
  v53 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v53->mPrev = v52;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v51->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v51 + 16 * (arg.mStateParamIndex + 3i64)) )
    v51->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::SetSimpleMaterialShader(0x3141335Cu);
  if ( v5->mRenderFeatures.mScenery )
  {
    RenderQueueLayer::RenderQueueLayer(&v73);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    ptr.mRenderQueueProvider = &v73;
    ptr.mQueueMode = 0;
    ptr.mShaderSelector = v18;
    v18->mAddState.mFlags[0] |= 0x800000000ui64;
    view.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    v73.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 448);
    UFG::RenderStageTerrain::Render(UFG::RenderWorld::msStageTerrain, v5, &view);
    RenderQueueLayer::SerializeRenderQueues(&v73);
    v73.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 464);
    UFG::RenderStageImposters::Render(UFG::RenderWorld::msStageImposters, v5, &view);
    RenderQueueLayer::SerializeRenderQueues(&v73);
    v73.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v9 + 480);
    Render::RenderPassSystem::DrawRenderPass(v3, &view, Decal);
    RenderQueueLayer::SerializeRenderQueues(&v73);
    v81 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v73);
  }
  Render::View::Metric_EndTarget(&view);
  Render::ViewMetrics::Accumulate(&v5->mRenderStats, &view.mViewMetrics);
  v54 = v60.mPrev;
  v55 = v60.mNext;
  v60.mPrev->mNext = v60.mNext;
  v55->mPrev = v54;
  v60.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v60.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v60;
  v56 = arg.mPrev;
  v57 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v57->mPrev = v56;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v58 = v62.mPrev;
  v59 = v62.mNext;
  v62.mPrev->mNext = v62.mNext;
  v59->mPrev = v58;
  v62.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v62;
  v62.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v62;
  `eh vector destructor iterator(
    v78.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  return (SimRenderQueueResults *)v9;
}

// File Line: 3214
// RVA: 0x56440
void __fastcall RenderHalfSizeDepthBuffer(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  UFG::RenderContext *v3; // rdi
  _WORD *v4; // rbx
  Illusion::StateArgs *v5; // r14
  Render::ViewSettings *v6; // rsi
  UFG::qMatrix44 *v7; // r15
  unsigned __int16 v8; // ax
  unsigned int v9; // er8
  Illusion::Material *v10; // rsi
  __int64 v11; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  __int64 v18; // [rsp+88h] [rbp-78h]
  RenderQueueLayer v19; // [rsp+90h] [rbp-70h]
  Render::View v20; // [rsp+170h] [rbp+70h]
  LayerSubmitContext ptr; // [rsp+300h] [rbp+200h]
  Render::Poly poly; // [rsp+FB0h] [rbp+EB0h]
  Illusion::StateArgs *v23; // [rsp+FC0h] [rbp+EC0h]

  v18 = -2i64;
  v2 = serialization_list;
  v3 = render_context;
  if ( render_context->mRenderFeatures.mWorld )
  {
    LayerSubmitContext::LayerSubmitContext(&ptr);
    RenderQueueLayer::RenderQueueLayer(&v19);
    v19.mSerializationList = v2;
    ptr.mRenderQueueProvider = &v19;
    v4 = 0i64;
    ptr.mQueueMode = 0;
    Render::View::View(&v20, &v3->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v5 = Render::View::GetStateArgs(&v20);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v20, v3->mHalfSizeLinearDepthTarget, "HalfSizeDepth", 0, 0, 0i64, 0, 0, 0, 0);
    v6 = v20.mSettings;
    v7 = &v20.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v8 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v8;
      arg.mStateParamIndex = v8;
    }
    arg.mWorldView = &v6->mWorldView;
    arg.mProjection = v7;
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v5, &arg);
    v9 = v3->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
    v10 = v3->mDownsampleDepthMaterial;
    if ( LODWORD(v10[1].mStateBlockMask.mFlags[0]) != v9 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10[1].mDebugName[20], v10[1].mStateBlockMask.mFlags[1], v9);
      v11 = v10->mMaterialUser.mOffset;
      if ( v11 )
        v4 = (_WORD *)((char *)&v10->mMaterialUser + v11);
      *v4 |= 0x20u;
    }
    Render::View::Draw(&v20, &poly, v3->mDownsampleDepthMaterial, 0i64);
    v12 = arg.mPrev;
    v13 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v13->mPrev = v12;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (arg.mStateParamIndex + 3i64)) )
    {
      v14 = &v5->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v14 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v20);
    RenderQueueLayer::SerializeRenderQueues(&v19);
    v15 = arg.mPrev;
    v16 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v16->mPrev = v15;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    RenderQueueLayer::~RenderQueueLayer(&v19);
    v23 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 3259
// RVA: 0x58380
void __fastcall RenderQuarterSizeDepthBuffer(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  UFG::RenderContext *v3; // rdi
  _WORD *v4; // rbx
  Illusion::StateArgs *v5; // r14
  Render::ViewSettings *v6; // rsi
  UFG::qMatrix44 *v7; // r15
  unsigned __int16 v8; // ax
  unsigned int v9; // er8
  Illusion::Material *v10; // rsi
  __int64 v11; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  __int64 v18; // [rsp+88h] [rbp-78h]
  RenderQueueLayer v19; // [rsp+90h] [rbp-70h]
  Render::View v20; // [rsp+170h] [rbp+70h]
  LayerSubmitContext ptr; // [rsp+300h] [rbp+200h]
  Render::Poly poly; // [rsp+FB0h] [rbp+EB0h]
  Illusion::StateArgs *v23; // [rsp+FC0h] [rbp+EC0h]

  v18 = -2i64;
  v2 = serialization_list;
  v3 = render_context;
  if ( render_context->mQuarterSizeLinearDepthTarget )
  {
    LayerSubmitContext::LayerSubmitContext(&ptr);
    RenderQueueLayer::RenderQueueLayer(&v19);
    v19.mSerializationList = v2;
    ptr.mRenderQueueProvider = &v19;
    v4 = 0i64;
    ptr.mQueueMode = 0;
    Render::View::View(&v20, &v3->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v5 = Render::View::GetStateArgs(&v20);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v20, v3->mQuarterSizeLinearDepthTarget, "QuarterSizeDepth", 0, 0, 0i64, 0, 0, 0, 0);
    v6 = v20.mSettings;
    v7 = &v20.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v8 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v8;
      arg.mStateParamIndex = v8;
    }
    arg.mWorldView = &v6->mWorldView;
    arg.mProjection = v7;
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v5, &arg);
    v9 = v3->mHalfSizeLinearDepthTarget->mDepthTextureCopy->mNode.mUID;
    v10 = v3->mDownsampleDepthMaterial;
    if ( LODWORD(v10[1].mStateBlockMask.mFlags[0]) != v9 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10[1].mDebugName[20], v10[1].mStateBlockMask.mFlags[1], v9);
      v11 = v10->mMaterialUser.mOffset;
      if ( v11 )
        v4 = (_WORD *)((char *)&v10->mMaterialUser + v11);
      *v4 |= 0x20u;
    }
    Render::View::Draw(&v20, &poly, v3->mDownsampleDepthMaterial, 0i64);
    v12 = arg.mPrev;
    v13 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v13->mPrev = v12;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (arg.mStateParamIndex + 3i64)) )
    {
      v14 = &v5->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v14 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    Render::View::EndTarget(&v20);
    RenderQueueLayer::SerializeRenderQueues(&v19);
    v15 = arg.mPrev;
    v16 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v16->mPrev = v15;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    RenderQueueLayer::~RenderQueueLayer(&v19);
    v23 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 3303
// RVA: 0x53EF0
void __fastcall RenderDeferredLights_1(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, int num_lights)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rsi
  _WORD *v5; // r14
  bool v6; // al
  Illusion::StateArgs *v7; // rdi
  Render::ViewSettings *v8; // rbx
  UFG::qMatrix44 *v9; // r15
  unsigned __int16 v10; // ax
  CB_EnvironmentSettings *v11; // rbx
  Illusion::StateValues *v12; // rax
  float v13; // xmm7_4
  float v14; // xmm6_4
  char *v15; // rbx
  Illusion::StateValues *v16; // rax
  int v17; // er8
  bool v18; // r13
  float v19; // xmm7_4
  Illusion::Material *v20; // r15
  unsigned int v21; // er9
  unsigned int v22; // er8
  __int64 v23; // rax
  _WORD *v24; // rax
  float *v25; // rdi
  Render::ViewSettings *v26; // rbx
  UFG::TimeOfDayManager *v27; // rax
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
  UFG::qResourceData *dest_mip_level; // ST20_8
  unsigned int v42; // er8
  __int64 v43; // rax
  _WORD *v44; // rax
  Illusion::Material *v45; // ST20_8
  Illusion::Material *v46; // rbx
  unsigned int v47; // er8
  Illusion::Material *v48; // ST20_8
  __int64 v49; // rax
  _WORD *v50; // rax
  unsigned int v51; // eax
  unsigned int v52; // eax
  __int64 v53; // rax
  __int64 v54; // rcx
  _QWORD *v55; // rax
  __int64 v56; // rcx
  _QWORD *v57; // rax
  bool d3d_disable_depth_copy[16]; // [rsp+48h] [rbp-80h]
  UFG::qMatrix44 local_world; // [rsp+58h] [rbp-70h]
  __int64 v60; // [rsp+98h] [rbp-30h]
  __int64 v61; // [rsp+A0h] [rbp-28h]
  Render::View view; // [rsp+A8h] [rbp-20h]
  RenderQueueLayer v63; // [rsp+238h] [rbp+170h]
  LayerSubmitContext ptr; // [rsp+318h] [rbp+250h]
  Illusion::StateArgs *v65; // [rsp+FF8h] [rbp+F30h]
  Render::Poly poly; // [rsp+1010h] [rbp+F48h]

  v61 = -2i64;
  v3 = serialization_list;
  v4 = render_context;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v63);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v63.mSerializationList = v3;
    ptr.mRenderQueueProvider = &v63;
    v5 = 0i64;
    ptr.mQueueMode = 0;
    Render::View::View(&view, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v6 = UFG::RenderWorld::msStageHairSkin->mEnableSSS == 1
      && (UFG::RenderWorld::msIsNisPlaying || UFG::RenderWorld::msStageHairSkin->mEnableSSSOutsideNIS);
    v4->mRenderSkinSS = v6;
    v7 = Render::View::GetStateArgs(&view);
    v65 = v7;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&view, v4->mLightBufferTarget, "LightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
    v8 = view.mSettings;
    v9 = &view.mSettings->mProjection;
    *(_QWORD *)&local_world.v1.x = (char *)&local_world + 16;
    *(_QWORD *)&local_world.v1.z = (char *)&local_world + 16;
    *(_QWORD *)&local_world.v2.x = 0i64;
    LOWORD(local_world.v2.z) = Render::cbExternalViewTransformState::sStateParamIndex;
    HIWORD(local_world.v2.z) = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v10;
      LOWORD(local_world.v2.z) = v10;
    }
    *(_QWORD *)&local_world.v3.x = v8;
    *(_QWORD *)&local_world.v3.z = v9;
    v60 = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(
      v7,
      (Render::cbExternalViewTransformState *)&local_world.v1);
    v11 = v4->mEnvState;
    v12 = Render::View::GetStateValues(&view);
    v12->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v12->mParamValues[55] = v11;
    v13 = UFG::Metrics::msInstance.mSimTimeDelta;
    v14 = UFG::Metrics::msInstance.mSimTime_Temp;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v15 = v14;
    *((float *)v15 + 1) = v13;
    v16 = Render::View::GetStateValues(&view);
    v16->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v16->mParamValues[13] = v15;
    Render::View::Clear(&view, &UFG::qColour::Zero, 5u, 1.0, 0);
    v17 = v4->mLightWithIrradianceVolumesType;
    if ( v17 )
      DrawIrradianceVolumes(v4, &view, v17);
    UFG::Director::Get();
    v18 = !UFG::RenderWorld::msExposureMetering->mInsideNoSkyVisibleVolume
       && v4->mRenderSun
       && v4->mCombineAmbientSpecAndSun;
    v19 = gAmbientWithSpecDistance;
    if ( UFG::RenderWorld::msIsNisPlaying )
      v19 = gAmbientWithSpecDistance * 2.0;
    if ( !UFG::RenderWorld::msExposureMetering->mInsideNoSkyVisibleVolume )
    {
      v20 = v4->mSkyAmbientMaterial;
      if ( v4->mRenderSettingsForFrame.mSSAO == 1 && v4->mLightBufferTarget->mTargetTexture[1] )
      {
        if ( v18 )
          v21 = v4->mAmbientSpecWithSunShader_DOUID;
        else
          v21 = v4->mAmbientSpecShaderUID;
        Illusion::Material::UpdateParam(v4->mSkyAmbientMaterial, 0, 0x8B5561A1, v21);
      }
      else
      {
        if ( v18 )
          v22 = v4->mAmbientSpecWithSunShaderUID;
        else
          v22 = v4->mAmbientSpecShaderUID;
        if ( LODWORD(v20[1].mResourceHandles.mNode.mNext) != v22 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v20[1].mNode.mChild[1], v20[1].mTypeUID, v22);
          v23 = v20->mMaterialUser.mOffset;
          if ( v23 )
            v24 = (_WORD *)((char *)&v20->mMaterialUser + v23);
          else
            v24 = 0i64;
          *v24 |= 0x20u;
        }
      }
      v25 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
      v26 = view.mSettings;
      v27 = UFG::TimeOfDayManager::GetInstance();
      v28 = (float)((float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.y)
                  + (float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.y))
          + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.y);
      v29 = (float)((float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.z)
                  + (float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.z))
          + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.z);
      *v25 = (float)((float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.x)
                   + (float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.x))
           + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.x);
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
      v25[7] = (float)((float)((float)(v4->mEnvState->AmbientColorHorizon[1] * 0.71539998)
                             + (float)(v4->mEnvState->AmbientColorHorizon[0] * 0.21250001))
                     + (float)(v4->mEnvState->AmbientColorHorizon[2] * 0.072099999))
             * 1.3;
      v38 = Render::View::GetStateValues(&view);
      v38->mSetValueMask.mFlags[0] |= 0x8000ui64;
      v38->mParamValues[15] = v25;
      *(UFG::qVector4 *)&local_world.v1.z = UFG::qMatrix44::msIdentity.v1;
      *(UFG::qVector4 *)d3d_disable_depth_copy = UFG::qMatrix44::msIdentity.v2;
      local_world.v1.x = UFG::qMatrix44::msIdentity.v0.z * v19;
      local_world.v1.y = UFG::qMatrix44::msIdentity.v0.w * v19;
      local_world.v1.z = UFG::qMatrix44::msIdentity.v1.x * v19;
      local_world.v1.w = local_world.v1.w * v19;
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
      dest_mip_level = v40->mData;
      Render::View::Draw(&view, &gDeferredCube, (UFG::qMatrix44 *)((char *)&local_world + 8), 0);
      v42 = 1537965747;
      if ( gClearStencil )
        v42 = -1835606658;
      if ( *(_DWORD *)&v20[3].mDebugName[12] != v42 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v20[3].mResourceHandles.mNode.mNext,
          *(_DWORD *)&v20[3].mDebugName[20],
          v42);
        v43 = v20->mMaterialUser.mOffset;
        if ( v43 )
          v44 = (_WORD *)((char *)&v20->mMaterialUser + v43);
        else
          v44 = 0i64;
        *v44 |= 0x20u;
      }
      v45 = v4->mSkyAmbientMaterial;
      Render::View::Draw(&view, &gDeferredCube, (UFG::qMatrix44 *)((char *)&local_world + 8), 0);
      v7 = v65;
    }
    if ( v4->mRenderSun )
    {
      v46 = v4->mSunUsingCollectorMaterial;
      v47 = 1660426324;
      if ( v18 )
      {
        if ( gClearStencil )
        {
          *(_QWORD *)&d3d_disable_depth_copy[8] = 0i64;
          *(_QWORD *)&local_world.v0.x = 0i64;
          Render::View::Clear(&view, (UFG::qColour *)&d3d_disable_depth_copy[8], 4u, 1.0, 0);
        }
        v48 = v4->mSunAfterAmbientSpecMarkMaterial;
        Render::View::Draw(&view, &gDeferredCube, (UFG::qMatrix44 *)((char *)&local_world + 8), 0);
        if ( gClearStencil )
          v47 = v4->mSunAfterAmbientSpecTestRasterStateUID;
        else
          v47 = v4->mSunAfterAmbientSpecTestNoClearRasterStateUID;
      }
      if ( *(_DWORD *)&v46[3].mDebugName[12] != v47 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v46[3].mResourceHandles.mNode.mNext,
          *(_DWORD *)&v46[3].mDebugName[20],
          v47);
        v49 = v46->mMaterialUser.mOffset;
        if ( v49 )
          v50 = (_WORD *)((char *)&v46->mMaterialUser + v49);
        else
          v50 = 0i64;
        *v50 |= 0x20u;
      }
      if ( v4->mRenderSettingsForFrame.mSSAO == 1 && v4->mLightBufferTarget->mTargetTexture[1] )
      {
        v51 = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR_DO", 0xFFFFFFFF);
        Illusion::Material::UpdateParam(v46, 0, 0x8B5561A1, v51);
      }
      else
      {
        v52 = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR", 0xFFFFFFFF);
        if ( LODWORD(v46[1].mResourceHandles.mNode.mNext) != v52 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v46[1].mNode.mChild[1], v46[1].mTypeUID, v52);
          v53 = v46->mMaterialUser.mOffset;
          if ( v53 )
            v5 = (_WORD *)((char *)&v46->mMaterialUser + v53);
          *v5 |= 0x20u;
        }
      }
      Render::View::Draw(&view, &poly, v46, 0i64);
    }
    v54 = *(_QWORD *)&local_world.v1.x;
    v55 = *(_QWORD **)&local_world.v1.z;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.x + 8i64) = *(_QWORD *)&local_world.v1.z;
    *v55 = v54;
    *(_QWORD *)&local_world.v1.x = (char *)&local_world + 16;
    *(_QWORD *)&local_world.v1.z = (char *)&local_world + 16;
    HIBYTE(local_world.v2.z) = 0;
    if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (SLOWORD(local_world.v2.z) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (SLOWORD(local_world.v2.z) + 3i64)) )
      v7->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(local_world.v2.z) >> 6] &= ~(1i64 << (LOBYTE(local_world.v2.z) & 0x3F));
    Render::View::EndTarget(&view);
    RenderQueueLayer::SerializeRenderQueues(&v63);
    v56 = *(_QWORD *)&local_world.v1.x;
    v57 = *(_QWORD **)&local_world.v1.z;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.x + 8i64) = *(_QWORD *)&local_world.v1.z;
    *v57 = v56;
    *(_QWORD *)&local_world.v1.x = (char *)&local_world + 16;
    *(_QWORD *)&local_world.v1.z = (char *)&local_world + 16;
    v65 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v63);
  }
}

// File Line: 3452
// RVA: 0x550A0
void __fastcall RenderDeferredShadowedSpotlights(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, int spot_shadow_index)
{
  __int64 v3; // r12
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // rsi
  UFG::RenderContext *v5; // rdi
  Illusion::StateArgs *v6; // r14
  CB_EnvironmentSettings *v7; // rbx
  Illusion::StateValues *v8; // rax
  float v9; // xmm7_4
  float v10; // xmm6_4
  char *v11; // rax
  char *v12; // rbx
  Illusion::StateValues *v13; // rax
  Illusion::Target *v14; // r15
  char *v15; // rax
  char *v16; // rbx
  Illusion::RenderQueue *v17; // rcx
  Illusion::QueueCommandBucket *v18; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v19; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rcx
  void (__fastcall *v22)(Illusion::StateArg *, Illusion::StateValues *); // rbx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v23; // rsi
  unsigned __int16 v24; // ax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v25; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v26; // rax
  UFG::qNode<SerializationList,SerializationList> *v27; // rcx
  UFG::qNode<SerializationList,SerializationList> *v28; // rax
  SerializationList v29; // [rsp+50h] [rbp-78h]
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-50h]
  RenderQueueLayer v31; // [rsp+218h] [rbp+150h]
  LayerSubmitContext ptr; // [rsp+2F8h] [rbp+230h]
  void *v33; // [rsp+FD8h] [rbp+F10h]
  char *v34; // [rsp+FF0h] [rbp+F28h]

  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)-2i64;
  v3 = spot_shadow_index;
  v4 = serialization_list;
  v5 = render_context;
  if ( render_context->mRenderFeatures.mWorld && render_context->mRenderFeatures.mLights )
  {
    RenderQueueLayer::RenderQueueLayer(&v31);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v31.mSerializationList = v4;
    ptr.mRenderQueueProvider = &v31;
    ptr.mQueueMode = 0;
    Render::View::View((Render::View *)&arg.mCallback, &v5->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v6 = Render::View::GetStateArgs((Render::View *)&arg.mCallback);
    Render::View::BeginTarget(
      (Render::View *)&arg.mCallback,
      v5->mLightBufferTarget,
      "LightBuffer",
      0,
      0,
      0i64,
      0,
      0,
      0,
      0);
    v7 = v5->mEnvState;
    v8 = Render::View::GetStateValues((Render::View *)&arg.mCallback);
    v8->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v8->mParamValues[55] = v7;
    v9 = UFG::Metrics::msInstance.mSimTimeDelta;
    v10 = UFG::Metrics::msInstance.mSimTime_Temp;
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    v12 = v11;
    *(float *)v11 = v10;
    *((float *)v11 + 1) = v9;
    v13 = Render::View::GetStateValues((Render::View *)&arg.mCallback);
    v13->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v13->mParamValues[13] = v12;
    v29.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v29;
    v29.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v29;
    v33 = &v29.mList;
    v29.mList.mNode.mPrev = &v29.mList.mNode;
    v29.mList.mNode.mNext = &v29.mList.mNode;
    v29.mCommandQueue = 0i64;
    v14 = v5->mLightBufferTarget;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    v33 = v15;
    v34 = v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = v14;
      *((_QWORD *)v15 + 1) = 0i64;
      *((_DWORD *)v15 + 4) = 0;
      *((_QWORD *)v15 + 3) = "LightBufferPhase2";
    }
    else
    {
      v15 = 0i64;
    }
    SerializationList::AddCommand(&v29, 14, v15);
    v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(v14, (Illusion::ViewportScissorState *)v16, 0);
    SerializationList::AddCommand(&v29, 9, v16);
    v17 = v29.mCommandQueue;
    if ( v29.mCommandQueue )
    {
      v18 = v29.mCommandQueue->mFreeBucket;
      if ( v18 )
      {
        v29.mCommandQueue->mCommandCount += v18->mNumCommands;
        v17->mFreeBucket = 0i64;
      }
      v29.mCommandQueue = 0i64;
    }
    v19 = v29.mList.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v29.mList.mNode.mNext != &v29.mList )
    {
      v20 = v4->mNode.mPrev;
      v21 = v29.mList.mNode.mPrev;
      v20->mNext = v29.mList.mNode.mNext;
      v19->mPrev = v20;
      v21->mNext = &v4->mNode;
      v4->mNode.mPrev = v21;
      v29.mList.mNode.mPrev = &v29.mList.mNode;
      v29.mList.mNode.mNext = &v29.mList.mNode;
    }
    v22 = arg.mCallback;
    v23 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)((char *)arg.mCallback + 64);
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v29.mPrev = 0i64;
    LOWORD(v29.mNext) = Render::cbExternalViewTransformState::sStateParamIndex;
    WORD1(v29.mNext) = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v24;
      LOWORD(v29.mNext) = v24;
    }
    v29.mList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v22;
    v29.mList.mNode.mNext = v23;
    v29.mCommandQueue = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v6, &arg);
    DrawShadowedSpotLights(v5, (Render::View *)&arg.mCallback, &gSpotShadowIndices[v3], 1u);
    arg.mPrev->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    BYTE3(v29.mNext) = 0;
    if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v29.mNext) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (SLOWORD(v29.mNext) + 3i64)) )
      v6->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v29.mNext) >> 6] &= ~(1i64 << ((_QWORD)v29.mNext & 0x3F));
    Render::View::EndTarget((Render::View *)&arg.mCallback);
    arg.mPrev->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v33 = &v29.mList;
    UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v29.mList);
    v25 = v29.mList.mNode.mPrev;
    v26 = v29.mList.mNode.mNext;
    v29.mList.mNode.mPrev->mNext = v29.mList.mNode.mNext;
    v26->mPrev = v25;
    v29.mList.mNode.mPrev = &v29.mList.mNode;
    v29.mList.mNode.mNext = &v29.mList.mNode;
    v27 = v29.mPrev;
    v28 = v29.mNext;
    v29.mPrev->mNext = v29.mNext;
    v28->mPrev = v27;
    v29.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v29;
    v29.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v29;
    v33 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v31);
  }
}

// File Line: 3513
// RVA: 0x54850
void __fastcall RenderDeferredLights_2(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, int num_lights)
{
  int v3; // er13
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // r12
  UFG::RenderContext *v5; // rsi
  _WORD *v6; // rdi
  Illusion::StateArgs *v7; // r14
  CB_EnvironmentSettings *v8; // rbx
  Illusion::StateValues *v9; // rax
  float v10; // xmm7_4
  float v11; // xmm6_4
  char *v12; // rax
  char *v13; // rbx
  Illusion::StateValues *v14; // rax
  Illusion::Target *v15; // r15
  char *v16; // rax
  char *v17; // rbx
  Illusion::RenderQueue *v18; // rcx
  Illusion::QueueCommandBucket *v19; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // rcx
  Render::ViewSettings *v23; // rbx
  UFG::qMatrix44 *v24; // r15
  unsigned __int16 v25; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rax
  Illusion::Target *v28; // rdx
  unsigned int v29; // er8
  Illusion::Material *v30; // rbx
  __int64 v31; // rax
  _WORD *v32; // rax
  unsigned int v33; // er8
  Illusion::Material *v34; // rbx
  __int64 v35; // rax
  _WORD *v36; // rax
  unsigned __int16 v37; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  Illusion::Material *v42; // rbx
  __int64 v43; // rax
  _WORD *v44; // rax
  unsigned int v45; // er8
  __int64 v46; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v47; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v48; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v49; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v53; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v54; // rax
  UFG::qNode<SerializationList,SerializationList> *v55; // rcx
  UFG::qNode<SerializationList,SerializationList> *v56; // rax
  SerializationList v57; // [rsp+50h] [rbp-B0h]
  Render::cbExternalViewTransformState arg; // [rsp+78h] [rbp-88h]
  Render::cbLocalProjectionState v59; // [rsp+B0h] [rbp-50h]
  __int64 v60; // [rsp+E8h] [rbp-18h]
  char *v61; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h]
  UFG::qMatrix44 result; // [rsp+290h] [rbp+190h]
  RenderQueueLayer v64; // [rsp+2D0h] [rbp+1D0h]
  LayerSubmitContext ptr; // [rsp+3B0h] [rbp+2B0h]
  Render::Poly poly; // [rsp+1090h] [rbp+F90h]
  void *v67; // [rsp+10A8h] [rbp+FA8h]

  v60 = -2i64;
  v3 = num_lights;
  v4 = serialization_list;
  v5 = render_context;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v64);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v64.mSerializationList = v4;
    ptr.mRenderQueueProvider = &v64;
    v6 = 0i64;
    ptr.mQueueMode = 0;
    Render::View::View(&view, &v5->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v7 = Render::View::GetStateArgs(&view);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&view, v5->mLightBufferTarget, "LightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
    v8 = v5->mEnvState;
    v9 = Render::View::GetStateValues(&view);
    v9->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v9->mParamValues[55] = v8;
    v10 = UFG::Metrics::msInstance.mSimTimeDelta;
    v11 = UFG::Metrics::msInstance.mSimTime_Temp;
    v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    v13 = v12;
    *(float *)v12 = v11;
    *((float *)v12 + 1) = v10;
    v14 = Render::View::GetStateValues(&view);
    v14->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v14->mParamValues[13] = v13;
    v57.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v57;
    v57.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v57;
    v67 = &v57.mList;
    v57.mList.mNode.mPrev = &v57.mList.mNode;
    v57.mList.mNode.mNext = &v57.mList.mNode;
    v57.mCommandQueue = 0i64;
    v15 = v5->mLightBufferTarget;
    v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    v67 = v16;
    v61 = v16;
    if ( v16 )
    {
      *(_QWORD *)v16 = v15;
      *((_QWORD *)v16 + 1) = 0i64;
      *((_DWORD *)v16 + 4) = 0;
      *((_QWORD *)v16 + 3) = "LightBufferPhase2";
    }
    else
    {
      v16 = 0i64;
    }
    SerializationList::AddCommand(&v57, 14, v16);
    v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(v15, (Illusion::ViewportScissorState *)v17, 0);
    SerializationList::AddCommand(&v57, 9, v17);
    v18 = v57.mCommandQueue;
    if ( v57.mCommandQueue )
    {
      v19 = v57.mCommandQueue->mFreeBucket;
      if ( v19 )
      {
        v57.mCommandQueue->mCommandCount += v19->mNumCommands;
        v18->mFreeBucket = 0i64;
      }
      v57.mCommandQueue = 0i64;
    }
    v20 = v57.mList.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v57.mList.mNode.mNext != &v57.mList )
    {
      v21 = v4->mNode.mPrev;
      v22 = v57.mList.mNode.mPrev;
      v21->mNext = v57.mList.mNode.mNext;
      v20->mPrev = v21;
      v22->mNext = &v4->mNode;
      v4->mNode.mPrev = v22;
      v57.mList.mNode.mPrev = &v57.mList.mNode;
      v57.mList.mNode.mNext = &v57.mList.mNode;
    }
    v23 = view.mSettings;
    v24 = &view.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v25 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v25;
      arg.mStateParamIndex = v25;
    }
    arg.mWorldView = &v23->mWorldView;
    arg.mProjection = v24;
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v7, &arg);
    v5->mRenderStats.mNumLightsProcessed += v3;
    SyncFlushDrawLightingTask(v5, &view);
    v26 = arg.mPrev;
    v27 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v27->mPrev = v26;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (arg.mStateParamIndex + 3i64)) )
      v7->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    if ( v5->mRenderSettingsForFrame.mSSAO == 1 )
    {
      v28 = v5->mDirectionalOcclusionTarget;
      if ( v28 )
      {
        Render::View::BeginTarget(&view, v28, "DirectionalOcclusionTarget", 0, 0, 0i64, 0, 0, 0, 0);
        v29 = v5->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
        v30 = v5->mSSDOMaterial;
        if ( *(_DWORD *)&v30[2].mDebugName[28] != v29 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v30[2].mDebugName[4], *((_DWORD *)&v30[2].0 + 22), v29);
          v31 = v30->mMaterialUser.mOffset;
          if ( v31 )
            v32 = (_WORD *)((char *)&v30->mMaterialUser + v31);
          else
            v32 = 0i64;
          *v32 |= 0x20u;
        }
        v33 = v5->mLightBufferTarget->mTargetTexture[1]->mNode.mUID;
        v34 = v5->mSSDOMaterial;
        if ( LODWORD(v34[3].mMaterialUser.mOffset) != v33 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v34[3].mStateBlockMask,
            (unsigned int)v34[4].mNode.mParent,
            v33);
          v35 = v34->mMaterialUser.mOffset;
          if ( v35 )
            v36 = (_WORD *)((char *)&v34->mMaterialUser + v35);
          else
            v36 = 0i64;
          *v36 |= 0x20u;
        }
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v7, &arg);
        if ( !(_S18 & 1) )
        {
          _S18 |= 1u;
          viewCorrector.v0 = (UFG::qVector4)_xmm;
          viewCorrector.v1 = (UFG::qVector4)_xmm;
          viewCorrector.v2 = (UFG::qVector4)_xmm;
          viewCorrector.v3 = (UFG::qVector4)_xmm;
        }
        UFG::qMatrix44::operator*(&view.mWorldViewProjection, &result, &viewCorrector);
        v59.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
        v59.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
        v59.mCallback = 0i64;
        v59.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
        *(_WORD *)&v59.mFlags = 1;
        if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
        {
          v37 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
          Render::cbLocalProjectionState::sStateParamIndex = v37;
          v59.mStateParamIndex = v37;
        }
        v59.mCached_Remote.m_Stream = 0i64;
        v59.mWorldViewProjection = &result;
        v59.mLocalWorld = &view.mViewWorld;
        Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v7, &v59);
        Render::View::Draw(&view, &poly, v5->mSSDOMaterial, 0i64);
        v38 = arg.mPrev;
        v39 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v39->mPrev = v38;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (arg.mStateParamIndex + 3i64)) )
          v7->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v40 = v59.mPrev;
        v41 = v59.mNext;
        v59.mPrev->mNext = v59.mNext;
        v41->mPrev = v40;
        v59.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
        v59.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
        v59.mIsSet = 0;
        if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (v59.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (v59.mStateParamIndex + 3i64)) )
          v7->mStateArgsCreateMask.mFlags[(unsigned int)v59.mStateParamIndex >> 6] &= ~(1i64 << (v59.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&view);
        Render::View::BeginTarget(&view, v5->mLightBufferTarget, "DOtoLightBuffer", 0, 0, 0i64, 0, 0, 0, 0);
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v7, &arg);
        v42 = Render::gRenderUtilities.mMaterial;
        if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != 826356572 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
            Render::gRenderUtilities.mMaterial[1].mTypeUID,
            0x3141335Cu);
          v43 = v42->mMaterialUser.mOffset;
          if ( v43 )
            v44 = (_WORD *)((char *)&v42->mMaterialUser + v43);
          else
            v44 = 0i64;
          *v44 |= 0x20u;
          v42 = Render::gRenderUtilities.mMaterial;
        }
        v45 = v5->mDirectionalOcclusionTarget->mTargetTexture[0]->mNode.mUID;
        if ( LODWORD(v42[1].mStateBlockMask.mFlags[0]) != v45 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v42[1].mDebugName[20],
            v42[1].mStateBlockMask.mFlags[1],
            v45);
          v46 = v42->mMaterialUser.mOffset;
          if ( v46 )
            v6 = (_WORD *)((char *)&v42->mMaterialUser + v46);
          *v6 |= 0x20u;
          v42 = Render::gRenderUtilities.mMaterial;
        }
        Render::View::Draw(&view, &poly, v42, 0i64);
        v47 = arg.mPrev;
        v48 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v48->mPrev = v47;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (arg.mStateParamIndex + 3i64)) )
          v7->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&view);
        v49 = v59.mPrev;
        v50 = v59.mNext;
        v59.mPrev->mNext = v59.mNext;
        v50->mPrev = v49;
        v59.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
        v59.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v59;
      }
    }
    if ( v5->mRenderSkinSS || UFG::RenderWorld::msStageHairSkin->mEnableHairLighting )
      UFG::RenderStageHairSkin::Render(UFG::RenderWorld::msStageHairSkin, v5, v4, &gCompositeDrawableCullLayer);
    v51 = arg.mPrev;
    v52 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v52->mPrev = v51;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v67 = &v57.mList;
    UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v57.mList);
    v53 = v57.mList.mNode.mPrev;
    v54 = v57.mList.mNode.mNext;
    v57.mList.mNode.mPrev->mNext = v57.mList.mNode.mNext;
    v54->mPrev = v53;
    v57.mList.mNode.mPrev = &v57.mList.mNode;
    v57.mList.mNode.mNext = &v57.mList.mNode;
    v55 = v57.mPrev;
    v56 = v57.mNext;
    v57.mPrev->mNext = v57.mNext;
    v56->mPrev = v55;
    v57.mPrev = (UFG::qNode<SerializationList,SerializationList> *)&v57;
    v57.mNext = (UFG::qNode<SerializationList,SerializationList> *)&v57;
    v67 = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v64);
  }
}

// File Line: 3660
// RVA: 0x5AFC0
void __fastcall SetRainState(Render::View *view)
{
  Render::View *v1; // rsi
  char *v2; // rdi
  UFG::qMatrix44 *v3; // rax
  unsigned int v4; // eax
  unsigned __int16 v5; // bx
  Illusion::StateValues *v6; // rax
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+B0h] [rbp-48h]

  v1 = view;
  v2 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x140u, 0x140u);
  if ( !(_S19 & 1) )
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
  if ( _S19 & 2 )
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
  v6 = Render::View::GetStateValues(v1);
  if ( (unsigned int)(signed __int16)v5 >= 0x40 )
    v6->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v5 - 64);
  else
    v6->mSetValueMask.mFlags[0] |= 1i64 << v5;
  v6->mParamValues[(signed __int16)v5] = v2;
}

// File Line: 3694
// RVA: 0x55690
void __fastcall RenderFXHalfsize(Render::View *view, UFG::RenderContext *render_context)
{
  UFG::RenderContext *v2; // rbx
  Render::View *v3; // rdi
  Illusion::StateArgs *v4; // rsi
  Illusion::SubmitContext *v5; // r14
  const float *v6; // r15
  const float *v7; // r12
  const float *v8; // r13
  unsigned __int16 v9; // ax
  const float *v10; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rax
  Render::cbShadowTransformState arg; // [rsp+30h] [rbp-A8h]
  Illusion::Texture *v16; // [rsp+88h] [rbp-50h]
  __int64 v17; // [rsp+90h] [rbp-48h]
  __int64 v18; // [rsp+98h] [rbp-40h]
  __int64 v19; // [rsp+A0h] [rbp-38h]
  __int64 v20; // [rsp+A8h] [rbp-30h]
  int v21; // [rsp+B0h] [rbp-28h]
  __int64 v22; // [rsp+B8h] [rbp-20h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+C8h] [rbp-10h]

  v22 = -2i64;
  v2 = render_context;
  v3 = view;
  v4 = Render::View::GetStateArgs(view);
  if ( gRenderFX )
  {
    v5 = v3->mSubmitContext;
    v17 = 0i64;
    v18 = 0i64;
    v21 = 0;
    v20 = -1i64;
    v19 = -1i64;
    v5->mShaderSelector = (Illusion::ShaderSelector *)&v17;
    UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
    v6 = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
    v7 = UFG::RenderWorld::msStageShadow->mBiases;
    v8 = UFG::RenderWorld::msStageShadow->mCutplanes;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
    {
      v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v9;
      arg.mStateParamIndex = v9;
    }
    arg.mViewWorld = &v3->mViewWorld;
    arg.mProjection = views.mProjection;
    arg.mCutplanes = v8;
    arg.mBiases = v7;
    arg.mBlurWidths = v6;
    arg.mWorldView = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(v4, &arg);
    SetRainState(v3);
    arg.mCutplanes = (const float *)v2->mHalfSizeLinearDepthTarget->mDepthTextureCopy;
    arg.mBiases = (const float *)v2->mDynamicRangeTarget->mTargetTexture[0];
    if ( v2->mRenderSun )
      v10 = (const float *)v2->mHalfSizeShadowAliasTexture;
    else
      v10 = 0i64;
    arg.mBlurWidths = v10;
    arg.mCached_Remote.m_Stream = v2->mHeightmapTarget->mDepthTexture;
    v16 = v2->mHeightmapShadowTextureAlias;
    Render::FXManager::Render(
      &Render::gFXManager,
      v3,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_LOW_QUALITY,
      (Render::FXManagerAuxBuffers *)&arg.mCutplanes);
    v11 = arg.mPrev;
    v12 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v12->mPrev = v11;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v4->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v4 + 16 * (arg.mStateParamIndex + 3i64)) )
      v4->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v5->mShaderSelector = 0i64;
    v13 = arg.mPrev;
    v14 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v14->mPrev = v13;
  }
}

// File Line: 3733
// RVA: 0x560D0
void __fastcall RenderHalfSizeBuffer(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::RenderContext *v3; // r14
  Illusion::StateArgs *v4; // rsi
  CB_EnvironmentSettings *v5; // rbx
  Illusion::StateValues *v6; // rax
  float v7; // xmm7_4
  float v8; // xmm6_4
  char *v9; // rbx
  Illusion::StateValues *v10; // rax
  Render::ViewSettings *v11; // rbx
  UFG::qMatrix44 *v12; // r15
  unsigned __int16 v13; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h]
  Render::View view; // [rsp+158h] [rbp+80h]
  ForwardSubmitContext ptr; // [rsp+2E8h] [rbp+210h]
  Render::Poly v21; // [rsp+FC8h] [rbp+EF0h]
  Illusion::StateArgs *v22; // [rsp+FD8h] [rbp+F00h]

  arg.mWorldView = (UFG::qMatrix44 *)-2i64;
  v2 = (UFG::qMatrix44 *)serialization_list;
  v3 = render_context;
  if ( render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&arg.mProjection);
    ForwardSubmitContext::ForwardSubmitContext(&ptr);
    *(_QWORD *)&arg.mStateParamIndex = AlphaStateNoneHandle.mData;
    arg.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))RasterStateNormalHandle.mData;
    arg.mProjection = v2;
    ptr.mPerPhaseParams = (ForwardSubmitContext::PerPhaseParams *)&arg.mCallback;
    ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mProjection;
    ptr.mQueueMode = 0;
    Render::View::View(&view, &v3->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    v4 = Render::View::GetStateArgs(&view);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v21);
    Render::View::BeginTarget(&view, v3->mHalfSizeTarget, "HalfSizeEffects", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Zero, 1u, 1.0, 0);
    v5 = v3->mEnvState;
    v6 = Render::View::GetStateValues(&view);
    v6->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v6->mParamValues[55] = v5;
    v7 = UFG::Metrics::msInstance.mSimTimeDelta;
    v8 = UFG::Metrics::msInstance.mSimTime_Temp;
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v9 = v8;
    *((float *)v9 + 1) = v7;
    v10 = Render::View::GetStateValues(&view);
    v10->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v10->mParamValues[13] = v9;
    v11 = view.mSettings;
    v12 = &view.mSettings->mProjection;
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
    arg.mNext = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v4, &arg);
    if ( gCurrentEye == STEREO_EYE_LEFT && gEnableClouds )
    {
      Render::View::DrawSegment(&view, &UFG::qVector3::msZero, &UFG::qVector3::msZero, &UFG::DrawInfo::msDefault);
      RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mProjection);
      Render::SkyMarshall::SyncFlushDrawCloudTask(
        &Render::SkyMarshall::gSkyMarshall,
        (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)arg.mProjection);
    }
    RenderFXHalfsize(&view, v3);
    v14 = arg.mPrev;
    v15 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v15->mPrev = v14;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v4->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v4 + 16 * (arg.mStateParamIndex + 3i64)) )
      v4->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mProjection);
    v16 = arg.mPrev;
    v17 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v17->mPrev = v16;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v22 = &ptr.mStateArgs;
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
void __fastcall RenderVolumetrics(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // rbx
  UFG::RenderContext *v3; // r15
  char v4; // di
  Illusion::StateArgs *v5; // r14
  CB_EnvironmentSettings *v6; // rbx
  Illusion::StateValues *v7; // rax
  Render::ViewSettings *v8; // rbx
  UFG::qMatrix44 *v9; // rdi
  unsigned __int16 v10; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h]
  __int64 v16; // [rsp+90h] [rbp-48h]
  Render::View v17; // [rsp+148h] [rbp+70h]
  ForwardSubmitContext ptr; // [rsp+2D8h] [rbp+200h]
  Render::Poly poly; // [rsp+F98h] [rbp+EC0h]
  Illusion::StateArgs *v20; // [rsp+FA0h] [rbp+EC8h]

  arg.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))-2i64;
  v2 = serialization_list;
  v3 = render_context;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v16);
  ForwardSubmitContext::ForwardSubmitContext(&ptr);
  *(_QWORD *)&arg.mStateParamIndex = v2;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&arg.mStateParamIndex;
  ptr.mQueueMode = 0;
  v4 = Render::CloudVolumeManager::RenderCloudVolumeFog(&Render::gCloudVolumeManager, v3, v2, 1);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  Render::CloudVolumeManager::RenderCloudVolumeFog(&Render::gCloudVolumeManager, v3, v2, 0);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  Render::View::View(&v17, &v3->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  v5 = Render::View::GetStateArgs(&v17);
  Render::View::BeginTarget(&v17, v3->mHalfSizeVolumetricTarget, "VolumetricCloudsUpsample", 0, 0, 0i64, 1, 0, 0, 0);
  if ( !v4 )
    Render::View::Clear(&v17, &UFG::qColour::Zero, 1u, 1.0, 0);
  v6 = v3->mEnvState;
  v7 = Render::View::GetStateValues(&v17);
  v7->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v7->mParamValues[55] = v6;
  v8 = v17.mSettings;
  v9 = &v17.mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v10;
    arg.mStateParamIndex = v10;
  }
  arg.mWorldView = &v8->mWorldView;
  arg.mProjection = v9;
  arg.mNext = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v5, &arg);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v17, &poly, v3->mMatBlendVolumesIntoHalfSize, 0i64);
  v11 = arg.mPrev;
  v12 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v12->mPrev = v11;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (arg.mStateParamIndex + 3i64)) )
    v5->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v17);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&arg.mStateParamIndex);
  v13 = arg.mPrev;
  v14 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v14->mPrev = v13;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v20 = &ptr.mStateArgs;
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
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMarkSkyRasterStateHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMarkSkyRasterStateHandle__);
}

// File Line: 3899
// RVA: 0x4A3C0
void __fastcall CompositeLightsAndEffects(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *postfx_1_serialization_list, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *postfx_2_serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // r13
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // rbx
  UFG::RenderContext *v5; // rdi
  _WORD *v6; // rsi
  Illusion::StateArgs *v7; // r14
  Render::ViewSettings *v8; // rbx
  UFG::qMatrix44 *v9; // r15
  unsigned __int16 v10; // ax
  unsigned int v11; // eax
  CB_EnvironmentSettings *v12; // rbx
  Illusion::StateValues *v13; // rax
  float v14; // xmm7_4
  float v15; // xmm6_4
  char *v16; // rax
  char *v17; // rbx
  Illusion::StateValues *v18; // rax
  CB_SkySettings *v19; // r12
  unsigned int v20; // ebx
  Illusion::StateValues *v21; // rax
  const float *v22; // rbx
  const float *v23; // r12
  unsigned __int16 v24; // ax
  float *v25; // r12
  Render::ViewSettings *v26; // rbx
  UFG::TimeOfDayManager *v27; // rax
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
  Illusion::Material *v38; // rbx
  __int64 v39; // rax
  _WORD *v40; // rax
  Illusion::Target *v41; // rax
  unsigned int v42; // er8
  Illusion::Material *v43; // rbx
  __int64 v44; // rax
  _WORD *v45; // rax
  unsigned int v46; // er8
  Illusion::Material *v47; // rbx
  __int64 v48; // rax
  _WORD *v49; // rax
  Illusion::StateValues *v50; // rax
  Render::EnvCubeMap *v51; // rax
  UFG::qResourceData *v52; // rbx
  Illusion::StateValues *v53; // rax
  UFG::TimeOfDayManager *v54; // rax
  Illusion::Texture *v55; // rbx
  Illusion::StateValues *v56; // rax
  Illusion::Texture *v57; // rbx
  Illusion::StateValues *v58; // rax
  UFG::qResourceData *v59; // rbx
  Illusion::StateValues *v60; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v61; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v62; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v64; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v65; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v66; // rax
  unsigned int v67; // er8
  UFG::qResourceData *v68; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v69; // rax
  _WORD *v70; // rax
  unsigned int v71; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v72; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v73; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v74; // rax
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v75; // rcx
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v76; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v77; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v78; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v79; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v80; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  Render::cbShadowTransformState v82; // [rsp+90h] [rbp-70h]
  __int64 v83; // [rsp+F0h] [rbp-10h]
  __int64 v84; // [rsp+F8h] [rbp-8h]
  __int64 v85; // [rsp+100h] [rbp+0h]
  __int64 v86; // [rsp+108h] [rbp+8h]
  int v87; // [rsp+110h] [rbp+10h]
  __int64 v88; // [rsp+118h] [rbp+18h]
  Render::View pView; // [rsp+120h] [rbp+20h]
  RenderQueueLayer v90; // [rsp+2B0h] [rbp+1B0h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+390h] [rbp+290h]
  CompositeSubmitContext ptr; // [rsp+590h] [rbp+490h]
  Render::Poly v93; // [rsp+1280h] [rbp+1180h]
  Illusion::StateArgs *v94; // [rsp+1288h] [rbp+1188h]
  Render::Poly poly; // [rsp+1290h] [rbp+1190h]

  v88 = -2i64;
  v3 = postfx_2_serialization_list;
  v4 = postfx_1_serialization_list;
  v5 = render_context;
  RenderQueueLayer::RenderQueueLayer(&v90);
  CompositeSubmitContext::CompositeSubmitContext(&ptr);
  v90.mSerializationList = v4;
  ptr.mRenderQueueProvider = &v90;
  v6 = 0i64;
  ptr.mQueueMode = 0;
  ptr.mOverrideMode = 0;
  Render::View::View(&pView, &v5->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  v7 = Render::View::GetStateArgs(&pView);
  v8 = pView.mSettings;
  v9 = &pView.mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v10;
    arg.mStateParamIndex = v10;
  }
  arg.mWorldView = &v8->mWorldView;
  arg.mProjection = v9;
  arg.mCached_Remote.m_Stream = 0i64;
  Render::View::BeginTarget(&pView, v5->mDynamicRangeTarget, "CompositeLightsAndEffects", 0, 0, 0i64, 0, 0, 0, 0);
  Render::View::Clear(&pView, &UFG::qColour::Zero, 4u, 1.0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v7, &arg);
  if ( !(_S20 & 1) )
  {
    _S20 |= 1u;
    v11 = UFG::qStringHash32("cbSkySettings", 0xFFFFFFFF);
    skySettingsIndex_0 = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             v11,
                                             "cbSkySettings",
                                             0);
  }
  v12 = v5->mEnvState;
  v13 = Render::View::GetStateValues(&pView);
  v13->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v13->mParamValues[55] = v12;
  v14 = UFG::Metrics::msInstance.mSimTimeDelta;
  v15 = UFG::Metrics::msInstance.mSimTime_Temp;
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v17 = v16;
  *(float *)v16 = v15;
  *((float *)v16 + 1) = v14;
  v18 = Render::View::GetStateValues(&pView);
  v18->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v18->mParamValues[13] = v17;
  v19 = v5->mSkyState;
  v20 = (signed __int16)skySettingsIndex_0;
  v21 = Render::View::GetStateValues(&pView);
  if ( v20 >= 0x40 )
    v21->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v20 - 64);
  else
    v21->mSetValueMask.mFlags[0] |= 1i64 << v20;
  v21->mParamValues[(signed __int16)v20] = v19;
  v83 = 0i64;
  v84 = 0i64;
  v87 = 0;
  v86 = -1i64;
  v85 = -1i64;
  ptr.mShaderSelector = (Illusion::ShaderSelector *)&v83;
  ptr.mOverrideMode = 1;
  Render::SkyMarshall::RenderFar(&Render::SkyMarshall::gSkyMarshall, &pView, 1.0);
  Render::SkyMarshall::RenderCloudDome(&Render::SkyMarshall::gSkyMarshall, &pView, 1.0);
  ptr.mShaderSelector = 0i64;
  ptr.mOverrideMode = 0;
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  v22 = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  v23 = UFG::RenderWorld::msStageShadow->mBiases;
  v94 = (Illusion::StateArgs *)UFG::RenderWorld::msStageShadow->mCutplanes;
  v82.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v82.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v82.mCallback = 0i64;
  v82.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v82.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v24;
    v82.mStateParamIndex = v24;
  }
  v82.mViewWorld = &pView.mViewWorld;
  v82.mWorldView = (UFG::qMatrix44 *)&views;
  v82.mProjection = views.mProjection;
  v82.mCutplanes = (const float *)v94;
  v82.mBiases = v23;
  v82.mBlurWidths = v22;
  v82.mCached_Remote.m_Stream = 0i64;
  v25 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  v26 = pView.mSettings;
  v27 = UFG::TimeOfDayManager::GetInstance();
  v28 = (float)((float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.y)
              + (float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.y))
      + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.y);
  v29 = (float)((float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.z)
              + (float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.z))
      + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.z);
  v25[4] = (float)((float)(v27->mAmbientSkyDirection[0].y * v26->mWorldView.v1.x)
                 + (float)(v27->mAmbientSkyDirection[0].x * v26->mWorldView.v0.x))
         + (float)(v27->mAmbientSkyDirection[0].z * v26->mWorldView.v2.x);
  v25[5] = v28;
  v25[6] = v29;
  v30 = pView.mSettings;
  v31 = UFG::TimeOfDayManager::GetInstance();
  v32 = (float)((float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.y)
              + (float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.y))
      + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.y);
  v33 = (float)((float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.z)
              + (float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.z))
      + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.z);
  v25[8] = (float)((float)(v31->mAmbientSkyDirection[1].y * v30->mWorldView.v1.x)
                 + (float)(v31->mAmbientSkyDirection[1].x * v30->mWorldView.v0.x))
         + (float)(v31->mAmbientSkyDirection[1].z * v30->mWorldView.v2.x);
  v25[9] = v32;
  v25[10] = v33;
  v34 = pView.mSettings;
  v35 = (float *)UFG::TimeOfDayManager::GetInstance();
  v36 = (float)((float)(v35[45] * v34->mWorldView.v0.y) + (float)(v35[46] * v34->mWorldView.v1.y))
      + (float)(v35[47] * v34->mWorldView.v2.y);
  v37 = (float)((float)(v35[45] * v34->mWorldView.v0.z) + (float)(v35[46] * v34->mWorldView.v1.z))
      + (float)(v35[47] * v34->mWorldView.v2.z);
  v25[12] = (float)((float)(v35[46] * v34->mWorldView.v1.x) + (float)(v35[45] * v34->mWorldView.v0.x))
          + (float)(v35[47] * v34->mWorldView.v2.x);
  v25[13] = v36;
  v25[14] = v37;
  v38 = v5->mCompositeLightingMaterial;
  if ( LODWORD(v38[1].mResourceHandles.mNode.mNext) != 443851384 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v38[1].mNode.mChild[1], v38[1].mTypeUID, 0x1A74A278u);
    v39 = v38->mMaterialUser.mOffset;
    if ( v39 )
      v40 = (_WORD *)((char *)&v38->mMaterialUser + v39);
    else
      v40 = 0i64;
    *v40 |= 0x20u;
  }
  if ( v5->mRenderSun )
    v41 = v5->mFullSizeScratchTargetA;
  else
    v41 = v5->mAmbientOcclusionAliasTarget;
  v42 = v41->mTargetTexture[0]->mNode.mUID;
  v43 = v5->mCompositeLightingMaterial;
  if ( LODWORD(v43[5].mResourceHandles.mNode.mPrev) != v42 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v43[5].mNode.mChild,
      (unsigned int)v43[5].mResourceHandles.mNode.mNext,
      v42);
    v44 = v43->mMaterialUser.mOffset;
    if ( v44 )
      v45 = (_WORD *)((char *)&v43->mMaterialUser + v44);
    else
      v45 = 0i64;
    *v45 |= 0x20u;
  }
  v46 = v5->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
  v47 = v5->mCompositeLightingMaterial;
  if ( v47[2].mNode.mUID != v46 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v47[2], (unsigned int)v47[2].mResourceHandles.mNode.mPrev, v46);
    v48 = v47->mMaterialUser.mOffset;
    if ( v48 )
      v49 = (_WORD *)((char *)&v47->mMaterialUser + v48);
    else
      v49 = 0i64;
    *v49 |= 0x20u;
  }
  v50 = Render::View::GetStateValues(&pView);
  v50->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v50->mParamValues[15] = v25;
  v51 = v5->mEnvCubeMap;
  if ( v51 )
    v52 = (UFG::qResourceData *)&v51->mTarget->mTargetTexture[0]->mNode;
  else
    v52 = gDefaultBlackTexture.mData;
  v53 = Render::View::GetStateValues(&pView);
  v53->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
  v53->mParamValues[40] = v52;
  v54 = UFG::TimeOfDayManager::GetInstance();
  v55 = UFG::TimeOfDayManager::GetFogTexture(v54);
  v56 = Render::View::GetStateValues(&pView);
  v56->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  v56->mParamValues[41] = v55;
  v57 = v5->mHalfSizeShadowAliasTexture;
  v58 = Render::View::GetStateValues(&pView);
  v58->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v58->mParamValues[61] = v57;
  v59 = gArcTanTexture.mData;
  v60 = Render::View::GetStateValues(&pView);
  v60->mSetValueMask.mFlags[0] |= 0x80000000000ui64;
  v60->mParamValues[43] = v59;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v7, &v82);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&pView, &poly, v5->mCompositeLightingMaterial, 0i64);
  if ( v5->mRenderSun && UFG::RenderWorld::msStageShadow->mDrawDebugCascadeCoverage )
    UFG::RenderStageShadow::RenderCascadeDebug(UFG::RenderWorld::msStageShadow, &pView, v5);
  v61 = arg.mPrev;
  v62 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v62->mPrev = v61;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (arg.mStateParamIndex + 3i64)) )
    v7->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v63 = v82.mPrev;
  v64 = v82.mNext;
  v82.mPrev->mNext = v82.mNext;
  v64->mPrev = v63;
  v82.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v82.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v82.mIsSet = 0;
  if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (v82.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (v82.mStateParamIndex + 3i64)) )
    v7->mStateArgsCreateMask.mFlags[(unsigned int)v82.mStateParamIndex >> 6] &= ~(1i64 << (v82.mStateParamIndex & 0x3F));
  RenderQueueLayer::SerializeRenderQueues(&v90);
  v90.mSerializationList = v3;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v7, &arg);
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v93);
  Render::View::Draw(&pView, &v93, v5->mPostCompLightshaftMaterial, 0i64);
  v65 = arg.mPrev;
  v66 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v66->mPrev = v65;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (arg.mStateParamIndex + 3i64)) )
    v7->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  if ( UFG::RenderWorld::msEnableHalfsizeAA || (v67 = -633875363, UFG::RenderWorld::msIsNisPlaying) )
    v67 = 0x11567331;
  v68 = gMatBlit.mData;
  if ( *(_DWORD *)&gMatBlit.mData[1].mDebugName[28] != v67 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&gMatBlit.mData[1].mDebugName[4],
      (unsigned int)gMatBlit.mData[2].mNode.mParent,
      v67);
    v69 = v68[1].mResourceHandles.mNode.mPrev;
    if ( v69 )
      v70 = (_WORD *)((char *)&v69[7].mNext + (_QWORD)v68);
    else
      v70 = 0i64;
    *v70 |= 0x20u;
    v68 = gMatBlit.mData;
  }
  v71 = v5->mHalfSizeTarget->mTargetTexture[0]->mNode.mUID;
  if ( v68[2].mTypeUID != v71 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v68[2].mNode.mUID, *(_DWORD *)&v68[2].mDebugName[4], v71);
    v72 = v68[1].mResourceHandles.mNode.mPrev;
    if ( v72 )
      v6 = (_WORD *)((char *)&v72[7].mNext + (_QWORD)v68);
    *v6 |= 0x20u;
    v68 = gMatBlit.mData;
  }
  Render::View::Draw(&pView, &v93, (Illusion::Material *)v68, 0i64);
  if ( gRenderFX && v5->mRenderFeatures.mWorld )
  {
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(v7, &v82);
    Render::RainManager::Draw(&Render::RainManager::gRainManager, v5, &pView, UFG::Metrics::msInstance.mSimTimeDelta);
    v73 = v82.mPrev;
    v74 = v82.mNext;
    v82.mPrev->mNext = v82.mNext;
    v74->mPrev = v73;
    v82.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
    v82.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
    v82.mIsSet = 0;
    if ( (Illusion::StateArgs *)v7->mStateArgsCreateMask.mFlags[2 * (v82.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v7 + 16 * (v82.mStateParamIndex + 3i64)) )
      v7->mStateArgsCreateMask.mFlags[(unsigned int)v82.mStateParamIndex >> 6] &= ~(1i64 << (v82.mStateParamIndex & 0x3F));
    Render::DecalManager::Render(
      &Render::gDecalManager,
      &pView,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_HIGH_QUALITY);
  }
  v75 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
  {
    do
    {
      v76 = (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&v75[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, Render::View *, UFG::RenderContext *))v75->mPrev[7].mPrev)(
        v75,
        &pView,
        v5);
      v75 = &v76->mNode;
    }
    while ( v76 != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 );
  }
  Render::View::EndTarget(&pView);
  v77 = v82.mPrev;
  v78 = v82.mNext;
  v82.mPrev->mNext = v82.mNext;
  v78->mPrev = v77;
  v82.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v82.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v82;
  v79 = arg.mPrev;
  v80 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v80->mPrev = v79;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v94 = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v90);
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
void __fastcall RenderHDRBloom(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Illusion::Target *current_target)
{
  Illusion::Target *v3; // rdi
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // rbx
  UFG::RenderContext *v5; // r13
  unsigned int v6; // er8
  Illusion::Material *v7; // rbx
  __int64 v8; // rax
  _WORD *v9; // rax
  float *v10; // rbx
  Illusion::Target *v11; // rax
  Render::ViewSettings *v12; // rax
  unsigned int v13; // er8
  Illusion::Material *v14; // rdi
  __int64 v15; // rax
  _WORD *v16; // rax
  Illusion::StateValues *v17; // rax
  __int64 d3d_disable_depth_copy; // ST48_8
  unsigned int v19; // er14
  float v20; // xmm0_4
  float v21; // xmm1_4
  Illusion::Material *v22; // rbx
  __int64 v23; // rax
  _WORD *v24; // rax
  __int64 *v25; // r15
  Render::ViewSettings *v26; // rax
  __int64 v27; // rax
  unsigned int v28; // esi
  signed int *v29; // rbx
  unsigned int v30; // er12
  char *v31; // rdi
  Illusion::Material *v32; // rbx
  _WORD *v33; // rax
  _WORD *v34; // rax
  _WORD *v35; // rax
  Illusion::StateValues *v36; // rax
  Illusion::Target *v37; // [rsp+50h] [rbp-78h]
  Illusion::Target *v38; // [rsp+58h] [rbp-70h]
  Illusion::Target *v39; // [rsp+60h] [rbp-68h]
  Illusion::Target *v40; // [rsp+68h] [rbp-60h]
  __int64 v41; // [rsp+70h] [rbp-58h]
  Illusion::Target *v42; // [rsp+78h] [rbp-50h]
  Render::View v43; // [rsp+88h] [rbp-40h]
  RenderQueueLayer v44; // [rsp+218h] [rbp+150h]
  LayerSubmitContext ptr; // [rsp+2F8h] [rbp+230h]
  Render::Poly poly; // [rsp+FC8h] [rbp+F00h]
  Render::Poly v47; // [rsp+FD0h] [rbp+F08h]

  v42 = (Illusion::Target *)-2i64;
  v3 = current_target;
  v4 = serialization_list;
  v5 = render_context;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)((char *)&v44 + 56));
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v44.mSerializationList = v4;
  ptr.mRenderQueueProvider = &v44;
  ptr.mQueueMode = 0;
  Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
  v6 = v5->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID;
  v7 = v5->mCompositeFinalMaterial;
  if ( v7[2].mNode.mUID != v6 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7[2], (unsigned int)v7[2].mResourceHandles.mNode.mPrev, v6);
    v8 = v7->mMaterialUser.mOffset;
    if ( v8 )
      v9 = (_WORD *)((char *)&v7->mMaterialUser + v8);
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
    v11 = v5->mDynamicRangeTarget;
    v10[8] = 1.0 / (float)v5->mDynamicRangeTarget->mWidth;
    v10[9] = 1.0 / (float)v11->mHeight;
    v12 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v43, v12, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v43, v5->mHalfSizeScratchTargetB, "BloomThreshold", 0, 0, 0i64, 1, 0, 0, 0);
    v13 = v3->mTargetTexture[0]->mNode.mUID;
    v14 = v5->mBloomThresholdMaterial;
    if ( LODWORD(v14[1].mStateBlockMask.mFlags[0]) != v13 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v14[1].mDebugName[20], v14[1].mStateBlockMask.mFlags[1], v13);
      v15 = v14->mMaterialUser.mOffset;
      if ( v15 )
        v16 = (_WORD *)((char *)&v14->mMaterialUser + v15);
      else
        v16 = 0i64;
      *v16 |= 0x20u;
    }
    v17 = Render::View::GetStateValues(&v43);
    v17->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v17->mParamValues[15] = v10;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v43, &poly, v5->mBloomThresholdMaterial, 0i64);
    Render::View::EndTarget(&v43);
  }
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    v5->mHalfSizeScratchTargetB,
    v5->mQuarterSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mQuarterSizeScratchTargetA,
    v5->mQuarterSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mQuarterSizeScratchTargetB,
    v5->mQuarterSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    v5->mQuarterSizeScratchTargetA,
    v5->mEighthSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mEighthSizeScratchTargetA,
    v5->mEighthSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mEighthSizeScratchTargetB,
    v5->mEighthSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    v5->mEighthSizeScratchTargetA,
    v5->mSixteenthSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mSixteenthSizeScratchTargetA,
    v5->mSixteenthSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mSixteenthSizeScratchTargetB,
    v5->mSixteenthSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    v5->mSixteenthSizeScratchTargetA,
    v5->mThrityTwoSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mThrityTwoSizeScratchTargetA,
    v5->mThrityTwoSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mThrityTwoSizeScratchTargetB,
    v5->mThrityTwoSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::GaussBlur3x3(
    &Render::gRenderUtilities,
    v5->mThrityTwoSizeScratchTargetA,
    v5->mSixtyFourSizeScratchTargetA,
    0,
    0i64,
    kGaussBlur3x3UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mSixtyFourSizeScratchTargetA,
    v5->mSixtyFourSizeScratchTargetB,
    1,
    kGaussBlur5x5UID_10);
  Render::RenderUtilities::SeparableGaussBlur5x5(
    &Render::gRenderUtilities,
    v5->mSixtyFourSizeScratchTargetB,
    v5->mSixtyFourSizeScratchTargetA,
    0,
    kGaussBlur5x5UID_10);
  v37 = v5->mThrityTwoSizeScratchTargetB;
  v38 = v5->mThrityTwoSizeScratchTargetA;
  v39 = v5->mSixtyFourSizeScratchTargetA;
  v40 = v5->mSixteenthSizeScratchTargetB;
  v41 = (__int64)v5->mSixteenthSizeScratchTargetA;
  v42 = v37;
  d3d_disable_depth_copy = (__int64)v5->mEighthSizeScratchTargetB;
  v37 = v5->mEighthSizeScratchTargetA;
  v38 = v40;
  v39 = v5->mHDRBloomTarget;
  v40 = v5->mQuarterSizeScratchTargetA;
  v41 = d3d_disable_depth_copy;
  v19 = kBloomComposite;
  v20 = *(float *)&FLOAT_1_0;
  v21 = UFG::TimeOfDayManager::GetInstance()->m_WeatherState - 1.0;
  if ( v21 <= 0.0 )
  {
    v21 = 0.0;
    goto LABEL_17;
  }
  if ( v21 < 1.0 )
LABEL_17:
    v20 = v21;
  v22 = Render::gRenderUtilities.mMaterial;
  if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
      (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v23 = v22->mMaterialUser.mOffset;
    if ( v23 )
      v24 = (_WORD *)((char *)&v22->mMaterialUser + v23);
    else
      v24 = 0i64;
    *v24 |= 0x20u;
  }
  v25 = (__int64 *)&v39;
  poly.mVertices = (Render::vDynamic *)4;
  do
  {
    v26 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v43, v26, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v43, (Illusion::Target *)*(v25 - 2), "BloomComposite", 0, 0, 0i64, 1, 0, 0, 0);
    v27 = *(v25 - 1);
    if ( v27 )
      v28 = *(_DWORD *)(*(_QWORD *)(v27 + 24) + 24i64);
    else
      v28 = 840494775;
    v29 = (signed int *)*v25;
    v30 = *(_DWORD *)(*(_QWORD *)(*v25 + 24) + 24i64);
    if ( v28 == v5->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID )
      v19 = kBloomCompositeVignette;
    v31 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    *(float *)v31 = 1.0 / (float)*v29;
    *((float *)v31 + 1) = 1.0 / (float)v29[1];
    *((float *)v31 + 2) = 0.82999998 - (float)(v20 * 0.079999983);
    *((_DWORD *)v31 + 3) = 0;
    v32 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != v19 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        v19);
      v33 = (_WORD *)v32->mMaterialUser.mOffset;
      if ( v33 )
        v33 = (_WORD *)((char *)v33 + (_QWORD)v32 + 120);
      *v33 |= 0x20u;
      v32 = Render::gRenderUtilities.mMaterial;
    }
    if ( LODWORD(v32[1].mStateBlockMask.mFlags[0]) != v30 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v32[1].mDebugName[20], v32[1].mStateBlockMask.mFlags[1], v30);
      v34 = (_WORD *)v32->mMaterialUser.mOffset;
      if ( v34 )
        v34 = (_WORD *)((char *)v34 + (_QWORD)v32 + 120);
      *v34 |= 0x20u;
      v32 = Render::gRenderUtilities.mMaterial;
    }
    if ( *(_DWORD *)&v32[3].mDebugName[12] != v28 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v32[3].mResourceHandles.mNode.mNext,
        *(_DWORD *)&v32[3].mDebugName[20],
        v28);
      v35 = (_WORD *)v32->mMaterialUser.mOffset;
      if ( v35 )
        v35 = (_WORD *)((char *)v35 + (_QWORD)v32 + 120);
      *v35 |= 0x20u;
    }
    v36 = Render::View::GetStateValues(&v43);
    v36->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v36->mParamValues[15] = v31;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v47);
    Render::View::Draw(&v43, &v47, Render::gRenderUtilities.mMaterial, 0i64);
    Render::View::EndTarget(&v43);
    v25 += 3;
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
void __fastcall RenderMotionBlur(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  Illusion::Target **v4; // r15
  Illusion::Target **v5; // r14
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rsi
  UFG::RenderContext *v7; // rdi
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  float v12; // xmm6_4
  char *v13; // rbx
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm3
  Illusion::StateValues *v17; // rax
  Illusion::StateArgs *v18; // rsi
  unsigned int v19; // er9
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  Illusion::Target *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 b; // [rsp+90h] [rbp-70h]
  __int64 v27; // [rsp+D0h] [rbp-30h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h]
  UFG::qMatrix44 d; // [rsp+120h] [rbp+20h]
  RenderQueueLayer v30; // [rsp+160h] [rbp+60h]
  Render::View v31; // [rsp+240h] [rbp+140h]
  LayerSubmitContext ptr; // [rsp+3D0h] [rbp+2D0h]
  Render::Poly poly; // [rsp+1080h] [rbp+F80h]

  v27 = -2i64;
  v4 = scratch_target;
  v5 = curr_target;
  v6 = serialization_list;
  v7 = render_context;
  if ( !(_S21 & 1) )
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
  if ( v7->mRenderFeatures.mWorld
    && v7->mRenderFeatures.mMotionBlur
    && v7->mMotionBlurStrength > 0.050000001
    && v7->mRenderSettingsForFrame.mMotionBlur )
  {
    RenderQueueLayer::RenderQueueLayer(&v30);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v30.mSerializationList = v6;
    ptr.mRenderQueueProvider = &v30;
    ptr.mQueueMode = 0;
    Render::View::View(&v31, &v7->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v31, *v4, "MotionBlur", 0, 0, 0i64, 1, 0, 0, 0);
    UFG::qInverseAffine(&d, &v7->mMainViewSettings.mWorldView);
    UFG::qMatrix44::operator*(&d, &result, &b);
    v12 = v7->mMotionBlurStrength;
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
    v14 = result.v1;
    v15 = result.v2;
    v16 = result.v3;
    *(UFG::qVector4 *)v13 = result.v0;
    *((UFG::qVector4 *)v13 + 1) = v14;
    *((UFG::qVector4 *)v13 + 2) = v15;
    *((UFG::qVector4 *)v13 + 3) = v16;
    *((float *)v13 + 16) = v12;
    *(_QWORD *)(v13 + 68) = 1065353216i64;
    *((_DWORD *)v13 + 19) = 0;
    v17 = Render::View::GetStateValues(&v31);
    v17->mSetValueMask.mFlags[0] |= 0x4000000000000ui64;
    v17->mParamValues[50] = v13;
    Render::cbExternalViewTransformState::cbExternalViewTransformState(
      &arg,
      &v31.mSettings->mWorldView,
      &v31.mSettings->mProjection);
    v18 = Render::View::GetStateArgs(&v31);
    v19 = 417247388;
    if ( v7->mRenderSettingsForFrame.mMotionBlur != 2 )
      v19 = 1194509180;
    Illusion::Material::UpdateParam(v7->mCameraBlurMaterial, 0, 0x8B5561A1, v19);
    Illusion::Material::UpdateParam(v7->mCameraBlurMaterial, 1, 0x8B43FABF, (*v5)->mTargetTexture[0]->mNode.mUID);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v18, &arg);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v31, &poly, v7->mCameraBlurMaterial, 0i64);
    v20 = arg.mPrev;
    v21 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v21->mPrev = v20;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v18->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v18 + 16 * (arg.mStateParamIndex + 3i64)) )
      v18->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&v31);
    v22 = *v5;
    *v5 = *v4;
    *v4 = v22;
    v23 = arg.mPrev;
    v24 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v24->mPrev = v23;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
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
void __fastcall RenderFX(UFG::RenderContext *render_context, Illusion::Target *current_target, Illusion::Target *distortion_target, Render::View *view)
{
  Render::View *v4; // rdi
  Illusion::Target *v5; // r14
  UFG::RenderContext *v6; // rsi
  Illusion::SubmitContext *v7; // rbp
  CB_EnvironmentSettings *v8; // rbx
  Illusion::StateValues *v9; // rax
  Render::EnvCubeMap *v10; // rax
  UFG::qResourceData *v11; // rbx
  Illusion::StateValues *v12; // rax
  float v13; // xmm7_4
  float v14; // xmm6_4
  char *v15; // rbx
  Illusion::StateValues *v16; // rax
  Illusion::Texture *v17; // rcx
  Illusion::Texture *v18; // rax
  Illusion::Target *v19; // rax
  Illusion::Texture *v20; // rcx
  __int64 v21; // [rsp+30h] [rbp-88h]
  __int64 v22; // [rsp+38h] [rbp-80h]
  __int64 v23; // [rsp+40h] [rbp-78h]
  __int64 v24; // [rsp+48h] [rbp-70h]
  int v25; // [rsp+50h] [rbp-68h]
  Render::FXManagerAuxBuffers auxBuffers; // [rsp+58h] [rbp-60h]

  v4 = view;
  v5 = distortion_target;
  v6 = render_context;
  if ( gRenderFX )
  {
    v7 = view->mSubmitContext;
    v21 = 0i64;
    v22 = 0i64;
    v25 = 0;
    v24 = -1i64;
    v23 = -1i64;
    v7->mShaderSelector = (Illusion::ShaderSelector *)&v21;
    LODWORD(v7[1].mStateValues.mParamValues[1]) = 1;
    v8 = render_context->mEnvState;
    v9 = Render::View::GetStateValues(view);
    v9->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v9->mParamValues[55] = v8;
    v10 = v6->mEnvCubeMap;
    if ( v10 )
      v11 = (UFG::qResourceData *)&v10->mTarget->mTargetTexture[0]->mNode;
    else
      v11 = gDefaultBlackTexture.mData;
    v12 = Render::View::GetStateValues(v4);
    v12->mSetValueMask.mFlags[0] |= 0x10000000000ui64;
    v12->mParamValues[40] = v11;
    v13 = UFG::Metrics::msInstance.mSimTimeDelta;
    v14 = UFG::Metrics::msInstance.mSimTime_Temp;
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v15 = v14;
    *((float *)v15 + 1) = v13;
    v16 = Render::View::GetStateValues(v4);
    v16->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v16->mParamValues[13] = v15;
    v17 = v6->mGBufferTarget->mDepthTextureCopy;
    v18 = v5->mTargetTexture[0];
    auxBuffers.texShadowAtlas = 0i64;
    auxBuffers.scrDiffuse = v18;
    v19 = v6->mHeightmapTarget;
    auxBuffers.scrDepth = v17;
    v20 = v19->mDepthTexture;
    auxBuffers.texHeightmapShadow = v6->mHeightmapShadowTextureAlias;
    auxBuffers.texHeightmap = v20;
    Render::FXManager::Render(
      &Render::gFXManager,
      v4,
      UFG::Metrics::msInstance.mSimTime_Temp,
      FXDRAWPASS_FORWARD_HIGH_QUALITY,
      &auxBuffers);
    v7->mShaderSelector = 0i64;
    LODWORD(v7[1].mStateValues.mParamValues[1]) = 0;
  }
}

// File Line: 4400
// RVA: 0x53230
void __fastcall RenderAntiAlias(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Render::RenderPassCollector *render_pass_collector, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  Illusion::Target **v5; // r15
  Render::RenderPassCollector *v6; // r13
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v7; // rbx
  UFG::RenderContext *v8; // rdi
  Illusion::StateArgs *v9; // r14
  Illusion::Target **v10; // r12
  Render::ViewSettings *v11; // rbx
  UFG::qMatrix44 *v12; // rsi
  unsigned __int16 v13; // ax
  Illusion::Material *v14; // rbx
  unsigned int v15; // er8
  _WORD *v16; // rax
  Illusion::Material *v17; // rbx
  _WORD *v18; // rax
  unsigned int v19; // er8
  Illusion::Material *v20; // rbx
  signed __int64 v21; // rcx
  _WORD *v22; // rax
  _WORD *v23; // rax
  unsigned int v24; // er8
  Illusion::Material *v25; // rbx
  _WORD *v26; // rax
  unsigned int v27; // er8
  Illusion::Material *v28; // rbx
  _WORD *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rax
  unsigned __int64 *v32; // rdx
  Illusion::Target *v33; // rcx
  Illusion::Texture *v34; // rbx
  Illusion::StateValues *v35; // rax
  Illusion::Texture *v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rax
  unsigned __int64 *v39; // rdx
  Illusion::Target *v40; // r13
  Render::ViewSettings *v41; // rax
  Illusion::Material *v42; // rbx
  _WORD *v43; // rax
  unsigned int v44; // er8
  Illusion::Material *v45; // rbx
  _WORD *v46; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v47; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v48; // rax
  Illusion::Target *v49; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  Illusion::StateArgs *v53; // [rsp+88h] [rbp-78h]
  Render::Poly v54; // [rsp+90h] [rbp-70h]
  __int64 v55; // [rsp+98h] [rbp-68h]
  Render::View view; // [rsp+A0h] [rbp-60h]
  RenderQueueLayer v57; // [rsp+230h] [rbp+130h]
  RenderQueueLayer v58; // [rsp+310h] [rbp+210h]
  Render::View v59; // [rsp+3F0h] [rbp+2F0h]
  CompositeSubmitContext v60; // [rsp+580h] [rbp+480h]
  LayerSubmitContext ptr; // [rsp+1210h] [rbp+1110h]
  Render::Poly poly; // [rsp+1EC0h] [rbp+1DC0h]

  v55 = -2i64;
  v5 = curr_target;
  v6 = render_pass_collector;
  v7 = serialization_list;
  v8 = render_context;
  if ( render_context->mAntiAliasState != 1 )
    return;
  RenderQueueLayer::RenderQueueLayer(&v58);
  CompositeSubmitContext::CompositeSubmitContext(&v60);
  v58.mSerializationList = v7;
  v60.mOverrideMode = 0;
  v60.mRenderQueueProvider = &v58;
  v60.mQueueMode = 0;
  Render::View::View(&view, &v8->mMainViewSettings, (Illusion::SubmitContext *)&v60.vfptr);
  v9 = Render::View::GetStateArgs(&view);
  v10 = scratch_target;
  Render::View::BeginTarget(&view, *scratch_target, "AntiAlias", 0, 0, 0i64, 1, 1, 0, 0);
  v11 = view.mSettings;
  v12 = &view.mSettings->mProjection;
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
  arg.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v9, &arg);
  v14 = v8->mAntiAliasMaterial;
  if ( v8->mRenderSettingsForFrame.mAAQuality == AA_QUALITY_NORMAL )
  {
    if ( LODWORD(v14[1].mResourceHandles.mNode.mNext) != 1650486829 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v14[1].mNode.mChild[1], v14[1].mTypeUID, 0x62606E2Du);
      v22 = (_WORD *)v14->mMaterialUser.mOffset;
      if ( v22 )
        v22 = (_WORD *)((char *)v22 + (_QWORD)v14 + 120);
      *v22 |= 0x20u;
    }
    v20 = v8->mAntiAliasMaterial;
    if ( *(_DWORD *)&v20[2].mDebugName[28] == 1660426324 )
      goto LABEL_28;
    v21 = (signed __int64)&v20[2].mDebugName[4];
    v19 = 1660426324;
    goto LABEL_25;
  }
  if ( v8->mRenderSettingsForFrame.mDeviceType == 1 )
  {
    if ( LODWORD(v14[1].mResourceHandles.mNode.mNext) != -1507565517 )
    {
      v15 = -1507565517;
LABEL_10:
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v14[1].mNode.mChild[1], v14[1].mTypeUID, v15);
      v16 = (_WORD *)v14->mMaterialUser.mOffset;
      if ( v16 )
        v16 = (_WORD *)((char *)v16 + (_QWORD)v14 + 120);
      *v16 |= 0x20u;
      goto LABEL_13;
    }
  }
  else if ( LODWORD(v14[1].mResourceHandles.mNode.mNext) != 1165395818 )
  {
    v15 = 1165395818;
    goto LABEL_10;
  }
LABEL_13:
  v17 = v8->mAntiAliasMaterial;
  if ( *(_DWORD *)&v17[2].mDebugName[28] != 304454940 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v17[2].mDebugName[4], *((_DWORD *)&v17[2].0 + 22), 0x12259D1Cu);
    v18 = (_WORD *)v17->mMaterialUser.mOffset;
    if ( v18 )
      v18 = (_WORD *)((char *)v18 + (_QWORD)v17 + 120);
    *v18 |= 0x20u;
  }
  v19 = v8->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  v20 = v8->mAntiAliasMaterial;
  if ( LODWORD(v20[3].mNode.mChild[0]) == v19 )
    goto LABEL_28;
  v21 = (signed __int64)&v20[2].mNumParams;
LABEL_25:
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)v21, *(_DWORD *)(v21 + 32), v19);
  v23 = (_WORD *)v20->mMaterialUser.mOffset;
  if ( v23 )
    v23 = (_WORD *)((char *)v23 + (_QWORD)v20 + 120);
  *v23 |= 0x20u;
LABEL_28:
  v24 = (*v5)->mTargetTexture[0]->mNode.mUID;
  v25 = v8->mAntiAliasMaterial;
  if ( LODWORD(v25[1].mStateBlockMask.mFlags[0]) != v24 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v25[1].mDebugName[20], v25[1].mStateBlockMask.mFlags[1], v24);
    v26 = (_WORD *)v25->mMaterialUser.mOffset;
    if ( v26 )
      v26 = (_WORD *)((char *)v26 + (_QWORD)v25 + 120);
    *v26 |= 0x20u;
  }
  if ( Render::DepthOfField::IsEnabled(&Render::gDepthOfField) )
    v27 = v8->mHalfSizeScratchTargetC->mTargetTexture[0]->mNode.mUID;
  else
    v27 = 0x1C63FB41;
  v28 = v8->mAntiAliasMaterial;
  if ( *(_DWORD *)&v28[3].mDebugName[12] != v27 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v28[3].mResourceHandles.mNode.mNext,
      *(_DWORD *)&v28[3].mDebugName[20],
      v27);
    v29 = (_WORD *)v28->mMaterialUser.mOffset;
    if ( v29 )
      v29 = (_WORD *)((char *)v29 + (_QWORD)v28 + 120);
    *v29 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&view, &poly, v8->mAntiAliasMaterial, 0i64);
  v30 = arg.mPrev;
  v31 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v31->mPrev = v30;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
  {
    v32 = &v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v32 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  Render::View::EndTarget(&view);
  v33 = *v5;
  *v5 = *v10;
  *v10 = v33;
  Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&v60;
  Render::RenderUtilities::Blit(&Render::gRenderUtilities, *v5, *v10, 0x3141335Cu, "<Blit>", 0, 1, 0i64);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  Render::View::BeginTarget(&view, *v10, "HairBlur", 0, 0, 0i64, 1, 1, 0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v9, &arg);
  v34 = (*v5)->mTargetTexture[0];
  v35 = Render::View::GetStateValues(&view);
  v35->mSetValueMask.mFlags[0] |= 0x800000ui64;
  v35->mParamValues[23] = v34;
  Render::RenderPassSystem::DrawRenderPass(v6, &view, FeatherPunchThru);
  if ( Render::gDepthOfField.mNearBlurRendered )
    v36 = v8->mQuarterSizeScratchTargetA->mTargetTexture[0];
  UFG::RenderStageHairSkin::RenderHairBlur(UFG::RenderWorld::msStageHairSkin, v8, &view, (*v5)->mTargetTexture[0]);
  v37 = arg.mPrev;
  v38 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v38->mPrev = v37;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
  {
    v39 = &v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v39 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  Render::View::EndTarget(&view);
  v40 = v8->mHalfSizeScratchTargetA;
  RenderQueueLayer::RenderQueueLayer(&v57);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v57.mSerializationList = v60.mRenderQueueProvider->mSerializationList;
  ptr.mRenderQueueProvider = &v57;
  ptr.mQueueMode = 0;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&v54);
  v41 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v59, v41, (Illusion::SubmitContext *)&ptr.vfptr);
  Render::View::BeginTarget(&v59, v40, "distortion blit", 0, 0, 0i64, 1, 0, 0, 0);
  v42 = v8->mDistortionMaterial;
  if ( LODWORD(v42[1].mResourceHandles.mNode.mNext) != 826356572 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v42[1].mNode.mChild[1], v42[1].mTypeUID, 0x3141335Cu);
    v43 = (_WORD *)v42->mMaterialUser.mOffset;
    if ( v43 )
      v43 = (_WORD *)((char *)v43 + (_QWORD)v42 + 120);
    *v43 |= 0x20u;
  }
  v44 = (*v10)->mTargetTexture[0]->mNode.mUID;
  v45 = v8->mDistortionMaterial;
  if ( LODWORD(v45[1].mStateBlockMask.mFlags[0]) != v44 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v45[1].mDebugName[20], v45[1].mStateBlockMask.mFlags[1], v44);
    v46 = (_WORD *)v45->mMaterialUser.mOffset;
    if ( v46 )
      v46 = (_WORD *)((char *)v46 + (_QWORD)v45 + 120);
    *v46 |= 0x20u;
  }
  Render::View::Draw(&v59, &v54, v8->mDistortionMaterial, 0i64);
  Render::View::EndTarget(&v59);
  v53 = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v57);
  Render::View::BeginTarget(&view, *v10, "AntiAliasFX", 0, 0, 0i64, 1, 1, 0, 0);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v9, &arg);
  SetRainState(&view);
  RenderFX(v8, *v5, v40, &view);
  v47 = arg.mPrev;
  v48 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v48->mPrev = v47;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
    v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v49 = *v5;
  *v5 = *v10;
  *v10 = v49;
  v50 = arg.mPrev;
  v51 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v51->mPrev = v50;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  v53 = &v60.mStateArgs;
  `eh vector destructor iterator(
    v60.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v58);
}rg;
  v53 = &v60.mStateArgs;
  `eh 

// File Line: 4530
// RVA: 0x49D30
void __fastcall CompositeFinalAndDrawUI(UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Illusion::Target *curr_target)
{
  Illusion::Target *v3; // r14
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // rbx
  UFG::RenderContext *v5; // rdi
  char *vp_scissor; // r15
  Illusion::Target *v7; // rax
  Illusion::Target *v8; // rbx
  char *v9; // rsi
  UFG::TimeOfDayManager *v10; // rbx
  __int128 v11; // xmm6
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  Illusion::StateValues *v15; // rax
  CB_EnvironmentSettings *v16; // rbx
  Illusion::StateValues *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm6_4
  char *v20; // rbx
  Illusion::StateValues *v21; // rax
  Illusion::Material *v22; // rbx
  __int64 v23; // rax
  _WORD *v24; // rax
  unsigned int v25; // er8
  Illusion::Material *v26; // rbx
  __int64 v27; // rax
  _WORD *v28; // rax
  Illusion::Target *v29; // rax
  char *v30; // rax
  char *v31; // r9
  Illusion::Target *v32; // rbx
  char *v33; // rax
  Render::RenderCallbacks *v34; // rax
  Render::View view; // [rsp+60h] [rbp-68h]
  __int64 v36; // [rsp+1F0h] [rbp+128h]
  CompositeSubmitContext ptr; // [rsp+298h] [rbp+1D0h]
  bool is_full_screen; // [rsp+F98h] [rbp+ED0h]
  Render::Poly poly; // [rsp+FA0h] [rbp+ED8h]
  char *v40; // [rsp+FA8h] [rbp+EE0h]

  v3 = curr_target;
  v4 = serialization_list;
  v5 = render_context;
  RenderQueueLayer::RenderQueueLayer((RenderQueueLayer *)&v36);
  CompositeSubmitContext::CompositeSubmitContext(&ptr);
  *(_QWORD *)&view.mViewWorld.v1.z = v4;
  ptr.mOverrideMode = 0;
  ptr.mRenderQueueProvider = (RenderQueueLayer *)&view.mViewWorld.v1.z;
  ptr.mQueueMode = 0;
  Render::View::View(&view, &v5->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  vp_scissor = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
  Render::GetBackBufferViewportScissor((Illusion::ViewportScissorState *)vp_scissor, &is_full_screen);
  v7 = Render::GetBackBufferTarget();
  v8 = v7;
  if ( !is_full_screen )
  {
    Render::View::BeginTarget(&view, v7, "FinalComposition", 0, 0, 0i64, 1, 0, 0, 0);
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
  v10 = UFG::TimeOfDayManager::GetInstance();
  v11 = LODWORD(UFG::TimeOfDayManager::GetInstance()->mBloomNearThreshold);
  if ( *(float *)&v11 <= v10->mBloomFarThreshold )
    *(float *)&v11 = v10->mBloomFarThreshold;
  *(float *)v9 = (float)(Render::DepthOfField::IsEnabled(&Render::gDepthOfField) != 0);
  v12 = *(float *)&v11 - 0.0040000002;
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
  v15 = Render::View::GetStateValues(&view);
  v15->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v15->mParamValues[15] = v9;
  v16 = v5->mEnvState;
  v17 = Render::View::GetStateValues(&view);
  v17->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v17->mParamValues[55] = v16;
  v18 = UFG::Metrics::msInstance.mSimTimeDelta;
  v19 = UFG::Metrics::msInstance.mSimTime_Temp;
  v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v20 = v19;
  *((float *)v20 + 1) = v18;
  v21 = Render::View::GetStateValues(&view);
  v21->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v21->mParamValues[13] = v20;
  v22 = v5->mCompositeFinalMaterial;
  if ( LODWORD(v22[1].mResourceHandles.mNode.mNext) != -1067196633 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v22[1].mNode.mChild[1], v22[1].mTypeUID, 0xC063DF27);
    v23 = v22->mMaterialUser.mOffset;
    if ( v23 )
      v24 = (_WORD *)((char *)&v22->mMaterialUser + v23);
    else
      v24 = 0i64;
    *v24 |= 0x20u;
  }
  v25 = v3->mTargetTexture[0]->mNode.mUID;
  v26 = v5->mCompositeFinalMaterial;
  if ( LODWORD(v26[1].mStateBlockMask.mFlags[0]) != v25 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v26[1].mDebugName[20], v26[1].mStateBlockMask.mFlags[1], v25);
    v27 = v26->mMaterialUser.mOffset;
    if ( v27 )
      v28 = (_WORD *)((char *)&v26->mMaterialUser + v27);
    else
      v28 = 0i64;
    *v28 |= 0x20u;
  }
  if ( v5->mRenderFeatures.mWorld )
  {
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&view, &poly, v5->mCompositeFinalMaterial, 0i64);
    Render::ScreenParticleEmitterManager::Render(
      &Render::gScreenParticleEmitterManager,
      &view,
      v3->mTargetTexture[0]->mNode.mUID,
      v5->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID);
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
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&ptr.vfptr, 17, 0, v31);
  }
  UFG::MovieHandler::RenderFullScreen(&UFG::TheMovieHandler, &view, 0);
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)&view.mViewWorld.v1.z);
  if ( UFG::UIScreenManager::s_instance )
  {
    UFG::UIScreenManager::s_instance->m_renderUI = v5->mRenderFeatures.mUI;
    UFG::UIScreenManagerBase::customPreRender(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      &view);
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
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&ptr.vfptr, 17, 0, v33);
    LayerSubmitContext::AddRenderCommand((LayerSubmitContext *)&ptr.vfptr, 27, 0, 0i64);
    UFG::UIScreenManagerBase::customPostRender(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      &view);
    UFG::UIScreenManagerBase::advance(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UFG::Metrics::msRealTimeDelta_Accurate);
  }
  UFG::MovieHandler::RenderFullScreen(&UFG::TheMovieHandler, &view, 1);
  Render::UpdateRenderLoadScreen(&view, UFG::Metrics::msRealTimeDelta_Accurate);
  if ( gDrawDebugContext )
  {
    RenderDebugOverlay(v5, &view);
    if ( Render::GetRenderCallbacks()->mRenderSimDebugOverlay )
    {
      v34 = Render::GetRenderCallbacks();
      v34->mRenderSimDebugOverlay(v5, &view);
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
void __fastcall RenderBackBufferToPresentBufferAndApplyBlackLevel(UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v1; // rdi
  Illusion::Target *v2; // rbp
  Illusion::Target *v3; // rbx
  _WORD *v4; // rsi
  Render::ViewSettings *v5; // rax
  Illusion::Material *v6; // rdi
  char *v7; // rbx
  __int64 v8; // rax
  _WORD *v9; // rax
  unsigned int v10; // er8
  __int64 v11; // rax
  Illusion::StateValues *v12; // rax
  RenderQueueLayer v13; // [rsp+60h] [rbp-F18h]
  Render::View v14; // [rsp+140h] [rbp-E38h]
  CompositeSubmitContext ptr; // [rsp+2D0h] [rbp-CA8h]
  Render::Poly poly; // [rsp+F88h] [rbp+10h]
  Illusion::StateArgs *v17; // [rsp+F90h] [rbp+18h]

  v1 = serialization_list;
  if ( !g_Fullscreen )
  {
    v2 = Render::GetBackBufferTarget();
    v3 = Render::GetPresentBufferTarget();
    RenderQueueLayer::RenderQueueLayer(&v13);
    CompositeSubmitContext::CompositeSubmitContext(&ptr);
    v13.mSerializationList = v1;
    v4 = 0i64;
    ptr.mOverrideMode = 0;
    ptr.mRenderQueueProvider = &v13;
    ptr.mQueueMode = 0;
    v5 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v14, v5, (Illusion::SubmitContext *)&ptr.vfptr);
    v6 = sPresentMaterial;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::BeginTarget(&v14, v3, "PresentBuffer", 0, 0, 0i64, 1, 0, 0, 0);
    v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    *(float *)v7 = (float)(Render::DisplayCalibration::msBrightness - 1.0) * Render::DisplayCalibration::BlackLevel1.r;
    if ( LODWORD(v6[1].mResourceHandles.mNode.mNext) != 2032804782 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6[1].mNode.mChild[1], v6[1].mTypeUID, 0x792A23AEu);
      v8 = v6->mMaterialUser.mOffset;
      if ( v8 )
        v9 = (_WORD *)((char *)&v6->mMaterialUser + v8);
      else
        v9 = 0i64;
      *v9 |= 0x20u;
    }
    v10 = v2->mTargetTexture[0]->mNode.mUID;
    if ( *(_DWORD *)&v6[2].mDebugName[28] != v10 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6[2].mDebugName[4], *((_DWORD *)&v6[2].0 + 22), v10);
      v11 = v6->mMaterialUser.mOffset;
      if ( v11 )
        v4 = (_WORD *)((char *)&v6->mMaterialUser + v11);
      *v4 |= 0x20u;
    }
    v12 = Render::View::GetStateValues(&v14);
    v12->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v12->mParamValues[15] = v7;
    Render::View::Draw(&v14, &poly, v6, 0i64);
    Render::View::EndTarget(&v14);
    v17 = &ptr.mStateArgs;
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
  UFG::RenderContext *v3; // rdi
  float v4; // xmm10_4
  char *v5; // rax
  char *v6; // r15
  char *v7; // rbx
  signed __int64 v8; // r13
  UFG::TimeOfDayManager *v9; // rax
  UFG::TimeOfDayManager *v10; // rax
  bool v11; // si
  bool v12; // r14
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm9_4
  unsigned int v19; // eax
  float v20; // xmm3_4
  float v21; // xmm1_4
  UFG::Reflection *v22; // rax
  int v23; // ebx
  MainViewTargetParams *v24; // r14
  UFG::TimeOfDayManager *v25; // rax
  int pDtor; // ST20_4
  int v27; // ebx
  Render::SimpleDrawableComponent *v28; // rcx
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *v29; // rbx
  CullManager *v30; // rax
  CullManager *v31; // rax
  UFG::qTaskGroup *v32; // rbx
  UFG::qTaskGroup *v33; // rax
  __int128 v34; // xmm0
  __int128 v35; // xmm1
  SceneryTaskRenderQueueResults *v36; // rax
  UFG::ShadowRenderQueueTaskResults *v37; // rax
  int v38; // edx
  int v39; // er8
  bool v40; // al
  char *v41; // rax
  UFG::qTaskGroup *v42; // rbx
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v43; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v44; // rax
  UFG::qTask *v45; // rbx
  UFG::qTaskGroup *v46; // rax
  CullManager *v47; // rax
  __int64 v48; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v49; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v50; // rsi
  unsigned int v51; // er14
  __int64 v52; // rdx
  bool v53; // r8
  UFG::qSNode<CullResultBucket,CullResultBucket> *v54; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v55; // rsi
  unsigned int v56; // er14
  UFG::CompositeDrawableComponent *v57; // r15
  UFG::SimObject *v58; // rax
  UFG::ICompositeLook *v59; // rcx
  __int64 v60; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v61; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v62; // rsi
  unsigned int v63; // er14
  UFG::CompositeDrawableComponent *v64; // r15
  UFG::SimObject *v65; // rax
  UFG::ICompositeLook *v66; // rcx
  UFG::qTaskGroup *v67; // rax
  unsigned __int64 v68; // r13
  unsigned __int64 v69; // r15
  MainViewTargetParams *v70; // r14
  char *v71; // rax
  UFG::qTaskGroup *v72; // rsi
  _QWORD *v73; // rax
  UFG::qTask *v74; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v75; // rax
  UFG::qTask *v76; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v77; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v78; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v79; // rax
  char *v80; // rax
  UFG::qTaskGroup *v81; // rsi
  _QWORD *v82; // rcx
  signed __int64 v83; // rcx
  _QWORD *v84; // rax
  UFG::qTask *v85; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v86; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v87; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v88; // rax
  char *v89; // rax
  UFG::qTaskGroup *v90; // r14
  _QWORD *v91; // rcx
  signed __int64 v92; // rcx
  _QWORD *v93; // rax
  UFG::qTask *v94; // rcx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v95; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v96; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v97; // rax
  unsigned __int64 v98; // r12
  unsigned int v99; // esi
  unsigned int *v100; // r15
  Render::Light *v101; // r9
  unsigned __int64 v102; // rsi
  float v103; // xmm6_4
  Illusion::Target *v104; // rcx
  float v105; // xmm1_4
  float v106; // xmm6_4
  Illusion::Target *v107; // rax
  UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *v108; // rsi
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v109; // rcx
  signed __int64 v110; // rbx
  UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *v111; // rcx
  signed __int64 v112; // rbx
  UFG::PartCompositeBuilder *v113; // rax
  bool v114; // bl
  CullManager *v115; // rax
  UFG::qTaskGroup **v116; // rbx
  signed __int64 v117; // rdi
  UFG::qTaskGroup *v118; // rdx
  FlushJobQueue job_queue; // [rsp+50h] [rbp+0h]
  __int64 v120; // [rsp+1260h] [rbp+1210h]

  v120 = -2i64;
  v2 = (unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64;
  v3 = render_context;
  v4 = fTime;
  Render::GetCurrentDisplaySettings(&render_context->mRenderSettingsForFrame);
  Render::ViewMetrics::Reset(&v3->mRenderStats);
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
  v6 = v5;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v5;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
  v8 = (signed __int64)&v3->mMainViewSettings;
  v9 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetEnvironmentSettings(
    v9,
    (CB_EnvironmentSettings *)v6,
    &v3->mMainViewSettings,
    (CB_SkySettings *)v7);
  v10 = UFG::TimeOfDayManager::GetInstance();
  v11 = UFG::TimeOfDayManager::IsSunShining(v10, (CB_EnvironmentSettings *)v6);
  v12 = 1.0 < UFG::TimeOfDayManager::GetInstance()->m_WeatherState;
  ++Render::TransparencySystem::msTransparencyFrameCounter;
  UFG::qInverseAffine(
    (UFG::qMatrix44 *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 192),
    &v3->mMainViewSettings.mWorldView);
  v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF0);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = v13;
  v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF4);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24) = v14;
  v15 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xF8);
  *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28) = v15;
  LODWORD(v16) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE8) ^ _xmm[0];
  LODWORD(v17) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE4) ^ _xmm[0];
  LODWORD(v18) = *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xE0) ^ _xmm[0];
  v19 = _S22;
  if ( !(_S22 & 1) )
  {
    v19 = _S22 | 1;
    _S22 |= 1u;
    v15 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28);
    v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24);
    v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  }
  if ( !(v19 & 2) )
  {
    _S22 = v19 | 2;
    v15 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x28);
    v14 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x24);
    v13 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
  }
  v20 = (float)((float)(sPrevCameraDirFront.x * v18) + (float)(v17 * sPrevCameraDirFront.y))
      + (float)(v16 * sPrevCameraDirFront.z);
  v21 = (float)((float)((float)(v13 - sPrevCameraPosition.x) * (float)(v13 - sPrevCameraPosition.x))
              + (float)((float)(v14 - sPrevCameraPosition.y) * (float)(v14 - sPrevCameraPosition.y)))
      + (float)((float)(v15 - sPrevCameraPosition.z) * (float)(v15 - sPrevCameraPosition.z));
  sPrevCameraDirFront.x = v18;
  sPrevCameraDirFront.y = v17;
  sPrevCameraDirFront.z = v16;
  sPrevCameraPosition.x = v13;
  sPrevCameraPosition.y = v14;
  sPrevCameraPosition.z = v15;
  if ( v20 < 0.69999999 || v21 > 4.0 )
    ++Render::TransparencySystem::msTransparencyFrameCounter;
  if ( (unsigned int)Render::IsLoadScreenRendering() )
    ++Render::TransparencySystem::msTransparencyFrameCounter;
  v3->mRenderSun = v11;
  v3->mRenderRain = v12;
  v3->mEnvState = (CB_EnvironmentSettings *)v6;
  v3->mSkyState = (CB_SkySettings *)v7;
  if ( v3->mReflectionTarget )
    v22 = FindPlanarReflection((UFG::qVector3 *)(v2 + 32));
  else
    v22 = 0i64;
  v3->mReflection = v22;
  v3->mAOOpacity = 1.0;
  v23 = 0;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8) = 0;
  if ( v3->mRenderFeatures.mWorld && UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler) )
  {
    v3->mRenderFeatures.mWorld = 0;
    v3->mNumCascades = 0;
  }
  `eh vector constructor iterator(
    (void *)(v2 + 256),
    0x10ui64,
    44,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  _mm_store_si128((__m128i *)(v2 + 992), (__m128i)0i64);
  _mm_store_si128((__m128i *)(v2 + 1008), (__m128i)0i64);
  UFG::qMemSet((void *)(v2 + 960), 0, 0x20u);
  v24 = GetMainViewTargets(v3);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58) = v24;
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
      &v3->mMainViewSettings,
      UFG::Metrics::msInstance.mSimTime_Temp,
      UFG::Metrics::msInstance.mSimTimeDelta,
      0);
  }
  v25 = UFG::TimeOfDayManager::GetInstance();
  Render::UpdateInventoryLights(v25->m_SecondsSinceMidnight);
  if ( v3->mRenderFeatures.mWorld && v3->mRenderFeatures.mLights )
  {
    v23 = GatherLights(gLights, gLightGroups);
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8) = v23;
  }
  pDtor = *((_DWORD *)v6 + 31);
  SubmitUpdateLightingTask(&v3->mMainViewSettings, v23, gLights, gCulledLights);
  v27 = v3->mMainViewSettings.mCullIndex;
  UFG::SceneryGroupComponent::GenerateCullInfoAll(gSceneryCullLayer);
  GenerateLightCullingInfo(v27);
  v28 = (Render::SimpleDrawableComponent *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> **)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) )
  {
    do
    {
      v29 = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&v28->mNext[-6].mNext;
      Render::SimpleDrawableComponent::UpdateCullInfo(v28);
      v28 = (Render::SimpleDrawableComponent *)v29;
    }
    while ( v29 != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) );
  }
  v30 = CullManager::Instance();
  CullManager::BeginFrame(v30);
  if ( gCurrentEye == STEREO_EYE_LEFT )
    UFG::qBaseTreeRB::~qBaseTreeRB(&Render::Skinning::gSkinning);
  v31 = CullManager::Instance();
  CullManager::BeginView(v31, v3->mMainViewSettings.mCullIndex, 0i64);
  v32 = CullManager::Instance()->mPrevCullingTask;
  v33 = UFG::RenderStageShadow::SubmitCullingTasks(UFG::RenderWorld::msStageShadow, v3);
  if ( v33 )
    v32 = v33;
  v34 = LODWORD(v3->mMainViewSettings.mCullPixelDistanceBias);
  v35 = LODWORD(v3->mMainViewSettings.mCullPixelDensityThreshold);
  v36 = SubmitRenderSceneryTasks(v32, v3, v24, v3->mMainViewSettings.mCullIndex);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3E0) = v36;
  if ( v36 )
    v32 = v36->mSceneryTaskGroup;
  v37 = UFG::RenderStageShadow::SubmitSceneryShadowTasks(UFG::RenderWorld::msStageShadow, v3, v32, gSceneryCullLayer);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3F0) = v37;
  if ( v37 )
    v32 = (UFG::qTaskGroup *)*((_QWORD *)&v37->mShadowsBucketIndices[3].do_not_remove + v37->mNumCascades + 3);
  if ( v32 )
    *(_QWORD *)v2 = (char *)v32 + 192;
  else
    *(_QWORD *)v2 = 0i64;
  if ( movie_update_task )
  {
    Illusion::AsyncCommandBuilder::FinalizeAsyncCommandBuilding((Illusion::AsyncCommandBuilder *)&movie_update_task->vfptr);
    movie_update_task = 0i64;
  }
  else
  {
    v40 = Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
            (hkGeometryUtils::IVertices *)movie_update_task,
            v38,
            v39);
    UFG::MovieHandler::Update(&UFG::TheMovieHandler, v40);
    UFG::MovieHandler::PostUpdate(&UFG::TheMovieHandler);
  }
  EarlyFlushSetup(
    (FlushContext *)(v2 + 256),
    (FlushJobQueue *)((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64),
    v3->mRenderFeatures.mWorld,
    v3->mRenderFeatures.mScenery);
  if ( gCurrentEye == STEREO_EYE_LEFT )
    UFG::RenderStageEnvMap::Render(
      UFG::RenderWorld::msStageEnvMap,
      v3,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 256));
  v41 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v42 = (UFG::qTaskGroup *)v41;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = v41;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v41;
  if ( v41 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v41, "PlanarReflectionSkinning");
  v43 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v44 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v44->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v42->mPrev;
  v42->mPrev = v44;
  v42->mNext = &v43->mNode;
  v43->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v42->mPrev;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v42);
  RenderPlanarReflectionMap(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 272));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3C0) = v42;
  if ( !v42->mNumTasks || v42->mStartTask.mSyncVars.v.mState )
  {
    v45 = *(UFG::qTask **)v2;
  }
  else
  {
    if ( *(_QWORD *)v2 )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v42, *(UFG::qTask **)v2);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v42);
    v45 = &v42->mEndTask;
    *(_QWORD *)v2 = v45;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  v46 = Illusion::RenderQueueSystem::FlushRenderPhase(
          *(Illusion::RenderPhase **)(*(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x410) + 8i64),
          5u,
          0x7C00u,
          v45,
          0);
  if ( v46 )
  {
    v45 = &v46->mEndTask;
    *(_QWORD *)v2 = (char *)v46 + 192;
  }
  if ( gCurrentEye == STEREO_EYE_LEFT )
  {
    UFG::Water::UpdateRippleMap(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 288));
    if ( gCurrentEye == STEREO_EYE_LEFT )
      RenderMoviesOffscreen((UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 320));
  }
  v47 = CullManager::Instance();
  CullManager::EndView(v47, (unsigned int)v3->mMainViewSettings.mCullIndex);
  Render::RenderPassCollector::RenderPassCollector((Render::RenderPassCollector *)(v2 + 1072));
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x48) = 0;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x4C) = 1;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = 2;
  v48 = v3->mMainViewSettings.mCullIndex;
  if ( (signed int)v48 >= 0 && (signed int)v48 <= 16 && gSimpleDrawableCullLayer.mDrawEnabled )
    v49 = gSimpleDrawableCullLayer.mCullResultBuckets[v48].mHead;
  else
    v49 = 0i64;
  v50 = v49;
  v51 = 0;
  if ( v49 )
  {
    do
    {
      Render::RenderPassSystem::RegisterComponent(
        (Render::RenderPassCollector *)(v2 + 1072),
        (Render::SimpleDrawableComponent *)v50[v51 + 3].mNext,
        *((float *)&v50[17].mNext + v51),
        *((float *)&v50[20].mNext + v51 + 1),
        (Illusion::eRenderPass::Enum *)(v2 + 72),
        3);
      if ( ++v51 == LODWORD(v50[1].mNext) )
      {
        v50 = v50->mNext;
        v51 = 0;
      }
    }
    while ( v50 );
    v8 = (signed __int64)&v3->mMainViewSettings;
  }
  v52 = v3->mMainViewSettings.mCullIndex;
  v53 = gCompositeDrawableCullLayer.mDrawEnabled;
  if ( (signed int)v52 >= 0 && (signed int)v52 <= 16 && gCompositeDrawableCullLayer.mDrawEnabled )
    v54 = gCompositeDrawableCullLayer.mCullResultBuckets[v52].mHead;
  else
    v54 = 0i64;
  v55 = v54;
  v56 = 0;
  if ( v54 )
  {
    do
    {
      v57 = (UFG::CompositeDrawableComponent *)v55[v56 + 3].mNext;
      v58 = v57->m_pSimObject;
      if ( !v58 || !((v58->m_Flags >> 13) & 1) )
      {
        Render::RenderPassSystem::RegisterComponent(
          (Render::RenderPassCollector *)(v2 + 1072),
          v57,
          *((float *)&v55[17].mNext + v56),
          *((float *)&v55[20].mNext + v56 + 1),
          (Illusion::eRenderPass::Enum *)(v2 + 72),
          3);
        v59 = v57->mCompositeLook;
        if ( v59 )
          v59->vfptr->OnUpdateCullResults(v59, v57, (Render::ViewSettings *)v8);
      }
      if ( ++v56 == LODWORD(v55[1].mNext) )
      {
        v55 = v55->mNext;
        v56 = 0;
      }
    }
    while ( v55 );
    v53 = gCompositeDrawableCullLayer.mDrawEnabled;
  }
  v60 = v3->mMainViewSettings.mCullIndex;
  if ( (signed int)v60 >= 0 && (signed int)v60 <= 16 && v53 )
    v61 = gCompositeDrawableCullLayer.mCullResultBuckets[v60].mHead;
  else
    v61 = 0i64;
  v62 = v61;
  v63 = 0;
  while ( v62 )
  {
    v64 = (UFG::CompositeDrawableComponent *)v62[v63 + 3].mNext;
    v65 = v64->m_pSimObject;
    if ( v65 )
    {
      if ( (v65->m_Flags >> 13) & 1 )
      {
        Render::RenderPassSystem::RegisterComponent(
          (Render::RenderPassCollector *)(v2 + 1072),
          v64,
          *((float *)&v62[17].mNext + v63),
          *((float *)&v62[20].mNext + v63 + 1),
          (Illusion::eRenderPass::Enum *)(v2 + 72),
          3);
        v66 = v64->mCompositeLook;
        if ( v66 )
          v66->vfptr->OnUpdateCullResults(v66, v64, (Render::ViewSettings *)v8);
      }
    }
    if ( ++v63 == LODWORD(v62[1].mNext) )
    {
      v62 = v62->mNext;
      v63 = 0;
    }
  }
  GatherShadowedSpotLights(v3);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x400) = 0i64;
  if ( gSpotShadowCount )
  {
    UFG::RenderStageSpotShadow::RegisterViews(UFG::RenderWorld::msStageSpotShadow, v3);
    v67 = UFG::RenderStageSpotShadow::SubmitCullingTasks(UFG::RenderWorld::msStageSpotShadow, v3);
    if ( v67 )
      *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x400) = UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks(
                                                                                       UFG::RenderWorld::msStageSpotShadow,
                                                                                       v3,
                                                                                       v67,
                                                                                       gSceneryCullLayer);
  }
  v68 = UFG::qGetTicks();
  SubmitDrawLightingTask(v3);
  v69 = UFG::qGetTicks();
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60) = v69;
  if ( gCurrentEye == STEREO_EYE_LEFT )
  {
    if ( gEnableClouds && v3->mRenderFeatures.mWorld )
      Render::SkyMarshall::SubmitCloudTask(
        &Render::SkyMarshall::gSkyMarshall,
        v3,
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
  v70 = *(MainViewTargetParams **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58);
  EarlyFlushToIllusionTrigger(
    (FlushContext *)(v2 + 256),
    *(MainViewTargetParams **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58));
  v71 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v72 = (UFG::qTaskGroup *)v71;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v71;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v71;
  if ( v71 )
  {
    *(_QWORD *)v71 = v71;
    *((_QWORD *)v71 + 1) = v71;
    v73 = v71 + 16;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v73;
    *v73 = v73;
    v73[1] = v73;
    v72->mNumTasks = 0;
    v74 = &v72->mStartTask;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = (char *)v72 + 64;
    v74->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v74->mPrev;
    v74->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v74->mPrev;
    v75 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v72->mStartTask.mPrev;
    v75->mPrev = v75;
    v75->mNext = v75;
    v72->mStartTask.mTaskGroup = 0i64;
    v72->mStartTask.mFlags = 2;
    v72->mStartTask.mSyncVars.i64 = 0i64;
    v72->mStartTask.mSyncVars.v.mDependents = 0i64;
    v72->mStartTask.mFunctionDeclData = 0i64;
    v72->mStartTask.mSPUElfAddress = 0i64;
    v72->mStartTask.mSPUFunction = 0i64;
    v72->mStartTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-1i64;
    v72->mStartTask.mParam0 = 0i64;
    v72->mStartTask.mParam1 = 0i64;
    v72->mStartTask.mParam2 = 0i64;
    v72->mStartTask.mParam3 = 0i64;
    v76 = &v72->mEndTask;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = (char *)v72 + 192;
    v76->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v76->mPrev;
    v76->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v76->mPrev;
    v77 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v72->mEndTask.mPrev;
    v77->mPrev = v77;
    v77->mNext = v77;
    v72->mEndTask.mTaskGroup = 0i64;
    v72->mEndTask.mFlags = 2;
    v72->mEndTask.mSyncVars.i64 = 0i64;
    v72->mEndTask.mSyncVars.v.mDependents = 0i64;
    v72->mEndTask.mFunctionDeclData = 0i64;
    v72->mEndTask.mSPUElfAddress = 0i64;
    v72->mEndTask.mSPUFunction = 0i64;
    v72->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
    v72->mEndTask.mParam0 = 0i64;
    v72->mEndTask.mParam1 = 0i64;
    v72->mEndTask.mParam2 = 0i64;
    v72->mEndTask.mParam3 = 0i64;
    v72->mStartTask.mTaskGroup = v72;
    v72->mEndTask.mTaskGroup = v72;
  }
  v78 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v79 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v79->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v72->mPrev;
  v72->mPrev = v79;
  v72->mNext = &v78->mNode;
  v78->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v72->mPrev;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v72);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3E8) = RenderSimMain(
                                                                                   v3,
                                                                                   v70,
                                                                                   (Render::RenderPassCollector *)(v2 + 1072));
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3C8) = v72;
  if ( v72->mNumTasks && !v72->mStartTask.mSyncVars.v.mState )
  {
    if ( v45 )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v72, v45);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v72);
    v45 = &v72->mEndTask;
    *(_QWORD *)v2 = (char *)v72 + 192;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  RenderHalfSizeDepthBuffer(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 336));
  RenderQuarterSizeDepthBuffer(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 336));
  v80 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v81 = (UFG::qTaskGroup *)v80;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v80;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v80;
  if ( v80 )
  {
    *(_QWORD *)v80 = v80;
    *((_QWORD *)v80 + 1) = v80;
    v82 = v80 + 16;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v80 + 16;
    *v82 = v82;
    v82[1] = v82;
    *((_DWORD *)v80 + 8) = 0;
    v83 = (signed __int64)(v80 + 64);
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v80 + 64;
    *(_QWORD *)v83 = v83;
    *(_QWORD *)(v83 + 8) = v83;
    v84 = v80 + 80;
    *v84 = v84;
    v84[1] = v84;
    *(_QWORD *)(v83 + 48) = 0i64;
    *(_DWORD *)(v83 + 56) = 2;
    *(_QWORD *)(v83 + 32) = 0i64;
    *(_QWORD *)(v83 + 40) = 0i64;
    *(_QWORD *)(v83 + 64) = 0i64;
    *(_QWORD *)(v83 + 72) = 0i64;
    *(_QWORD *)(v83 + 80) = 0i64;
    *(_QWORD *)(v83 + 88) = -1i64;
    *(_QWORD *)(v83 + 96) = 0i64;
    *(_QWORD *)(v83 + 104) = 0i64;
    *(_QWORD *)(v83 + 112) = 0i64;
    *(_QWORD *)(v83 + 120) = 0i64;
    v85 = &v81->mEndTask;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = (char *)v81 + 192;
    v85->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v85->mPrev;
    v85->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v85->mPrev;
    v86 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v81->mEndTask.mPrev;
    v86->mPrev = v86;
    v86->mNext = v86;
    v81->mEndTask.mTaskGroup = 0i64;
    v81->mEndTask.mFlags = 2;
    v81->mEndTask.mSyncVars.i64 = 0i64;
    v81->mEndTask.mSyncVars.v.mDependents = 0i64;
    v81->mEndTask.mFunctionDeclData = 0i64;
    v81->mEndTask.mSPUElfAddress = 0i64;
    v81->mEndTask.mSPUFunction = 0i64;
    v81->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
    v81->mEndTask.mParam0 = 0i64;
    v81->mEndTask.mParam1 = 0i64;
    v81->mEndTask.mParam2 = 0i64;
    v81->mEndTask.mParam3 = 0i64;
    v81->mStartTask.mTaskGroup = v81;
    v81->mEndTask.mTaskGroup = v81;
  }
  v87 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v88 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v88->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v81->mPrev;
  v81->mPrev = v88;
  v81->mNext = &v87->mNode;
  v87->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v81->mPrev;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v81);
  UFG::RenderStageShadow::RenderBeforeSunShadows(
    UFG::RenderWorld::msStageShadow,
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  UFG::RenderStageSpotShadow::RenderBeforeSunShadows(
    UFG::RenderWorld::msStageSpotShadow,
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  UFG::RenderStageAO::RenderAmbientOcclusion(
    UFG::RenderWorld::msStageAO,
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 384));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3F8) = UFG::RenderStageShadow::RenderSunShadowsSim(
                                                                                   UFG::RenderWorld::msStageShadow,
                                                                                   v3,
                                                                                   &gSimpleDrawableCullLayer,
                                                                                   &gCompositeDrawableCullLayer);
  UFG::RenderStageShadow::RenderAfterSunShadows(
    UFG::RenderWorld::msStageShadow,
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 400));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3D0) = v81;
  if ( v81->mNumTasks && !v81->mStartTask.mSyncVars.v.mState )
  {
    if ( v45 )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v81, v45);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v81);
    v45 = &v81->mEndTask;
    *(_QWORD *)v2 = (char *)v81 + 192;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  v89 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v90 = (UFG::qTaskGroup *)v89;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v89;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v89;
  if ( v89 )
  {
    *(_QWORD *)v89 = v89;
    *((_QWORD *)v89 + 1) = v89;
    v91 = v89 + 16;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v89 + 16;
    *v91 = v91;
    v91[1] = v91;
    *((_DWORD *)v89 + 8) = 0;
    v92 = (signed __int64)(v89 + 64);
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = v89 + 64;
    *(_QWORD *)v92 = v92;
    *(_QWORD *)(v92 + 8) = v92;
    v93 = v89 + 80;
    *v93 = v93;
    v93[1] = v93;
    *(_QWORD *)(v92 + 48) = 0i64;
    *(_DWORD *)(v92 + 56) = 2;
    *(_QWORD *)(v92 + 32) = 0i64;
    *(_QWORD *)(v92 + 40) = 0i64;
    *(_QWORD *)(v92 + 64) = 0i64;
    *(_QWORD *)(v92 + 72) = 0i64;
    *(_QWORD *)(v92 + 80) = 0i64;
    *(_QWORD *)(v92 + 88) = -1i64;
    *(_QWORD *)(v92 + 96) = 0i64;
    *(_QWORD *)(v92 + 104) = 0i64;
    *(_QWORD *)(v92 + 112) = 0i64;
    *(_QWORD *)(v92 + 120) = 0i64;
    v94 = &v90->mEndTask;
    *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x10) = (char *)v90 + 192;
    v94->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v94->mPrev;
    v94->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v94->mPrev;
    v95 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v90->mEndTask.mPrev;
    v95->mPrev = v95;
    v95->mNext = v95;
    v90->mEndTask.mTaskGroup = 0i64;
    v90->mEndTask.mFlags = 2;
    v90->mEndTask.mSyncVars.i64 = 0i64;
    v90->mEndTask.mSyncVars.v.mDependents = 0i64;
    v90->mEndTask.mFunctionDeclData = 0i64;
    v90->mEndTask.mSPUElfAddress = 0i64;
    v90->mEndTask.mSPUFunction = 0i64;
    v90->mEndTask.mPPUFunction = (void (__fastcall *)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *))-2i64;
    v90->mEndTask.mParam0 = 0i64;
    v90->mEndTask.mParam1 = 0i64;
    v90->mEndTask.mParam2 = 0i64;
    v90->mEndTask.mParam3 = 0i64;
    v90->mStartTask.mTaskGroup = v90;
    v90->mEndTask.mTaskGroup = v90;
  }
  v96 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v97 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v97->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v90->mPrev;
  v90->mPrev = v97;
  v90->mNext = &v96->mNode;
  v96->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v90->mPrev;
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, v90);
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x408) = UFG::RenderStageSpotShadow::RenderSpotShadowsSim(
                                                                                   UFG::RenderWorld::msStageSpotShadow,
                                                                                   v3,
                                                                                   &gSimpleDrawableCullLayer,
                                                                                   &gCompositeDrawableCullLayer);
  v98 = UFG::qGetTicks();
  RenderDeferredLights_1(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 448),
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8));
  if ( gSpotShadowCount )
  {
    v99 = 0;
    if ( gSpotShadowCount )
    {
      v100 = gSpotShadowIndices;
      do
      {
        if ( v3->mRenderFeatures.mWorld )
        {
          if ( v3->mRenderFeatures.mLights )
          {
            v101 = gLights[gCulledLights[*v100].lightIndex];
            if ( v101->mType == 4 )
              UFG::RenderStageSpotShadow::RenderSpotlightLightShafts(
                UFG::RenderWorld::msStageSpotShadow,
                v3,
                (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(16i64 * (v99 + 13) + v2 + 256),
                v101,
                &gCulledLights[*v100]);
          }
        }
        RenderDeferredShadowedSpotlights(
          v3,
          (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(16i64 * (v99 + 21) + v2 + 256),
          v99);
        ++v99;
        ++v100;
      }
      while ( v99 < gSpotShadowCount );
      v69 = *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    }
  }
  RenderDeferredLights_2(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 720),
    *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8));
  v102 = UFG::qGetTicks();
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x3D8) = v90;
  if ( v90->mNumTasks && !v90->mStartTask.mSyncVars.v.mState )
  {
    if ( v45 )
      UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v90, v45);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v90);
    *(_QWORD *)v2 = (char *)v90 + 192;
  }
  Render::Skinning::SetCurrentTaskGroup(&Render::Skinning::gSkinning, 0i64);
  v3->mRenderStats.mNumShadowsRendered += UFG::RenderWorld::msStageSpotShadow->mNumShadowsRendered
                                        + UFG::RenderWorld::msStageShadow->mNumShadowsRendered;
  v103 = UFG::qGetTickTime(v68, v69);
  v3->mRenderStats.mDrawLights = (float)(v103 + UFG::qGetTickTime(v98, v102)) + v3->mRenderStats.mDrawLights;
  _((AMD_HD3D *)&Render::Skinning::gSkinning);
  RenderVolumetrics(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 416));
  RenderHalfSizeBuffer(v3, (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 432));
  CompositeLightsAndEffects(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 736),
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 752));
  if ( v3->mRenderFeatures.mWorld )
    UFG::RenderStageExposureMetering::Render(
      UFG::RenderWorld::msExposureMetering,
      v3,
      (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 768));
  v104 = v3->mDynamicRangeTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18) = v104;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = v3->mFullSizeScratchTargetA;
  *(_DWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x80) = UFG::RenderWorld::msIsNisPlaying != 0;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x88) = v104;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x90) = v3->mHalfSizeScratchTargetC;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x98) = v3->mHalfSizeLinearDepthTarget->mDepthTextureCopy;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xA0) = v3->mHalfSizeScratchTargetA;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xA8) = v3->mQuarterSizeScratchTargetA;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xB0) = v3->mQuarterSizeScratchTargetB;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0xB8) = v3->mNearBlur;
  v105 = v3->mMainViewSettings.mProjection.v2.z;
  if ( v105 == 0.0 || v105 == v3->mMainViewSettings.mProjection.v2.w )
    v106 = *(float *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 8);
  else
    v106 = v3->mMainViewSettings.mProjection.v3.z / v105;
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
    v106);
  RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = ((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64)
                                                                              + 2472;
  `eh vector destructor iterator(
    (void *)(v2 + 2520),
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  v107 = *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38);
  if ( v3->mAAResultTarget )
    v107 = v3->mAAResultTarget;
  *(_QWORD *)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x38) = v107;
  RenderAntiAlias(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 800),
    (Render::RenderPassCollector *)(v2 + 1072),
    (Illusion::Target **)(v2 + 24),
    (Illusion::Target **)(v2 + 56));
  v108 = &UFG::RenderStagePlugin::s_RenderStagePluginList - 4;
  v109 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != &UFG::RenderStagePlugin::s_RenderStagePluginList - 4 )
  {
    do
    {
      v110 = (signed __int64)&v109[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, unsigned __int64, UFG::RenderContext *))v109->mPrev[7].mNext)(
        v109,
        v2 + 816,
        v3);
      v109 = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)v110;
    }
    while ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)v110 != v108 );
  }
  RenderHDRBloom(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 832),
    *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18));
  RenderMotionBlur(
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 864),
    (Illusion::Target **)(v2 + 24),
    (Illusion::Target **)(v2 + 56));
  v111 = UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)&UFG::RenderStagePlugin::s_RenderStagePluginList.mNode.mNext[-4] != v108 )
  {
    do
    {
      v112 = (signed __int64)&v111[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *, unsigned __int64, UFG::RenderContext *))v111->mPrev[8].mPrev)(
        v111,
        v2 + 848,
        v3);
      v111 = (UFG::qNode<UFG::RenderStagePlugin,UFG::RenderStagePlugin> *)v112;
    }
    while ( (UFG::qList<UFG::RenderStagePlugin,UFG::RenderStagePlugin,1,0> *)v112 != v108 );
  }
  CompositeFinalAndDrawUI(
    v3,
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
    v113 = UFG::PartCompositeBuilder::Instance();
    v114 = UFG::PartCompositeBuilder::RenderComposites(v113, (Illusion::SubmitContext *)(v2 + 1424));
    RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)(v2 + 1200));
    RenderQueueLayer::~RenderQueueLayer((RenderQueueLayer *)(v2 + 1200));
    `eh vector destructor iterator(
      (void *)(v2 + 2520),
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
  while ( v114 );
  RenderBackBufferToPresentBufferAndApplyBlackLevel((UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 896));
  UFG::RenderWorld::UpdateRenderScreenShot(
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 912),
    *(Illusion::Target **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x18));
  UFG::RenderStageFrameCapture::Render(
    UFG::RenderWorld::msStageFrameCapture,
    v3,
    (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v2 + 928));
  v115 = CullManager::Instance();
  CullManager::EndFrame(v115);
  LateFlushToIllusion(
    (FlushContext *)(v2 + 256),
    v3,
    v4,
    *(MainViewTargetParams **)(((unsigned __int64)&job_queue & 0xFFFFFFFFFFFFFFE0ui64) + 0x58));
  v116 = (UFG::qTaskGroup **)(v2 + 960);
  v117 = 4i64;
  do
  {
    v118 = *v116;
    if ( *v116 && v118->mNumTasks )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v118);
    ++v116;
    --v117;
  }
  while ( v117 );
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
  Render::ViewSettings *v2; // rax
  Illusion::Target *v3; // rax
  char *v4; // rax
  Illusion::RenderPhase *v5; // rcx
  _QWORD *v6; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v7; // r10
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v8; // r9
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v9; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v10; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v12; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v13; // [rsp+50h] [rbp-B0h]
  _QWORD *v14; // [rsp+60h] [rbp-A0h]
  __int64 v15; // [rsp+68h] [rbp-98h]
  RenderQueueLayer v16; // [rsp+70h] [rbp-90h]
  Render::View v17; // [rsp+150h] [rbp+50h]
  LayerSubmitContext ptr; // [rsp+2E0h] [rbp+1E0h]
  char *v19; // [rsp+F80h] [rbp+E80h]
  char *v20; // [rsp+F88h] [rbp+E88h]

  v15 = -2i64;
  v13.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
  v13.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v13;
  RenderQueueLayer::RenderQueueLayer(&v16);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v16.mSerializationList = &v13;
  ptr.mRenderQueueProvider = &v16;
  ptr.mQueueMode = 0;
  v2 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v17, v2, (Illusion::SubmitContext *)&ptr.vfptr);
  v3 = Render::GetBackBufferTarget();
  Render::View::BeginTarget(&v17, v3, "LoadScreen", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v17, &UFG::qColour::Black, 0xFFu, 1.0, 1u);
  Render::View::EndTarget(&v17);
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v5 = (Illusion::RenderPhase *)v4;
  v19 = v4;
  v20 = v4;
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
  v7 = &v5->mQueues;
  v8 = v13.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v13.mNode.mNext != &v13 )
  {
    v9 = v7->mNode.mPrev;
    v10 = v13.mNode.mPrev;
    v9->mNext = v13.mNode.mNext;
    v8->mPrev = v9;
    v10->mNext = &v7->mNode;
    v7->mNode.mPrev = v10;
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
void __fastcall UFG::RenderWorld::RenderWorldCallback(float fTime, void *render_param)
{
  UFG::RenderContext *v2; // rbx
  UFG::BaseCameraComponent *v3; // rcx
  bool v4; // al

  v2 = (UFG::RenderContext *)render_param;
  if ( g_enable3D && gCurrentEye == 1 )
    UFG::RenderWorld::UpdateViews(fTime);
  v3 = UFG::Director::Get()->mCurrentCamera;
  if ( v3 )
    v3 = (UFG::BaseCameraComponent *)((char *)v3 + 80);
  v2->mMotionBlurStrength = *((float *)&v3->vfptr + 1);
  *(_QWORD *)&v2->mRenderFeatures.mWorld = *(_QWORD *)&gRenderFrameFeatures.mWorld;
  *(_DWORD *)&v2->mRenderFeatures.mAO = *(_DWORD *)&gRenderFrameFeatures.mAO;
  v2->mRenderFeatures.mWorld &= UFG::RenderWorld::msRenderWorld;
  v2->mRenderFeatures.mScenery &= gDrawScenery;
  v4 = gDrawUI;
  v2->mRenderFeatures.mDOF &= 1u;
  v2->mRenderFeatures.mUI &= v4;
  v2->mRenderFeatures.mLights &= 1u;
  v2->mRenderFeatures.mAO &= 1u;
  v2->mRenderFeatures.mMotionBlur &= 1u;
  RenderWorldDeferred(fTime, v2);
}

// File Line: 5490
// RVA: 0x1454CF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Main__()
{
  UFG::RenderWorld::msGpuTimer_Main.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  UFG::RenderWorld::msGpuTimer_Main.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Main.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Main__);
}

// File Line: 5491
// RVA: 0x1454AF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXLow__()
{
  UFG::RenderWorld::msGpuTimer_FXLow.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  UFG::RenderWorld::msGpuTimer_FXLow.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXLow.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXLow__);
}

// File Line: 5492
// RVA: 0x1454A70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXHigh__()
{
  UFG::RenderWorld::msGpuTimer_FXHigh.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  UFG::RenderWorld::msGpuTimer_FXHigh.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXHigh.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXHigh__);
}

// File Line: 5493
// RVA: 0x14549F0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_FXDeferred__()
{
  UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  UFG::RenderWorld::msGpuTimer_FXDeferred.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_FXDeferred.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_FXDeferred__);
}

// File Line: 5494
// RVA: 0x1454B70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_GBuffer__()
{
  UFG::RenderWorld::msGpuTimer_GBuffer.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  UFG::RenderWorld::msGpuTimer_GBuffer.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_GBuffer.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_GBuffer__);
}

// File Line: 5495
// RVA: 0x1454C70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Lighting_Shadows__()
{
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Shadows.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Lighting_Shadows__);
}

// File Line: 5496
// RVA: 0x1454BF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Lighting_Lights__()
{
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  UFG::RenderWorld::msGpuTimer_Lighting_Lights.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Lighting_Lights.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Lighting_Lights__);
}

// File Line: 5497
// RVA: 0x1454870
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_Bloom__()
{
  UFG::RenderWorld::msGpuTimer_Bloom.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  UFG::RenderWorld::msGpuTimer_Bloom.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_Bloom.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_Bloom__);
}

// File Line: 5498
// RVA: 0x14548F0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_DOF__()
{
  UFG::RenderWorld::msGpuTimer_DOF.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  UFG::RenderWorld::msGpuTimer_DOF.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_DOF.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_DOF__);
}

// File Line: 5499
// RVA: 0x1454970
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_EnvMap__()
{
  UFG::RenderWorld::msGpuTimer_EnvMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  UFG::RenderWorld::msGpuTimer_EnvMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_EnvMap.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_EnvMap__);
}

// File Line: 5500
// RVA: 0x1454DF0
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_ReflMap__()
{
  UFG::RenderWorld::msGpuTimer_ReflMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  UFG::RenderWorld::msGpuTimer_ReflMap.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_ReflMap.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_ReflMap__);
}

// File Line: 5501
// RVA: 0x1454D70
__int64 dynamic_initializer_for__UFG::RenderWorld::msGpuTimer_PostFX__()
{
  UFG::RenderWorld::msGpuTimer_PostFX.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedCpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveCpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerUsedGpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mPrev = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  UFG::RenderWorld::msGpuTimer_PostFX.mNext = (UFG::qNode<Illusion::iTimer,Illusion::iTimerActiveGpuNode> *)&UFG::RenderWorld::msGpuTimer_PostFX.mPrev;
  return atexit(dynamic_atexit_destructor_for__UFG::RenderWorld::msGpuTimer_PostFX__);
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
  UFG::DamagePostEffect *v1; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v1 = (UFG::DamagePostEffect *)UFG::SimObject::GetComponentOfType(
                                    UFG::RenderWorld::msRenderStagePlugin,
                                    UFG::DamagePostEffect::_TypeUID);
    if ( v1 )
      UFG::DamagePostEffect::OnDamage(v1, magnitude);
  }
}

// File Line: 5535
// RVA: 0x4FCB0
void __fastcall UFG::RenderWorld::GunRecoilPostEffect_TriggerRecoil(float intensity, float falloff_scale)
{
  UFG::SimComponent *v2; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::GunRecoilPostEffect::_TypeUID);
    if ( v2 )
    {
      *(float *)&v2[1].m_SafePointerList.mNode.mNext = intensity;
      *((float *)&v2[1].m_SafePointerList.mNode.mNext + 1) = falloff_scale * 0.050000001;
    }
  }
}

// File Line: 5544
// RVA: 0x49800
void __fastcall UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(bool value)
{
  bool v1; // bl
  UFG::SimComponent *v2; // rax

  v1 = value;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(
           UFG::RenderWorld::msRenderStagePlugin,
           UFG::AccumulationBufferPostEffect::_TypeUID);
    if ( v2 )
      *(float *)&v2[1].m_SafePointerList.mNode.mNext = (float)v1;
  }
}

// File Line: 5553
// RVA: 0x5D830
unsigned int __fastcall UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(int index, bool isAdditive, int priority)
{
  int v3; // esi
  int v4; // ebx
  bool v5; // di
  UFG::VisualTreatmentPostEffect *v6; // rax
  unsigned int result; // eax

  v3 = index;
  v4 = priority;
  v5 = isAdditive;
  if ( UFG::RenderWorld::msRenderStagePlugin
    && (v6 = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                                 UFG::RenderWorld::msRenderStagePlugin,
                                                 UFG::VisualTreatmentPostEffect::_TypeUID)) != 0i64 )
  {
    result = UFG::VisualTreatmentPostEffect::StartVisualTreatment(v6, v3, v5, v4);
  }
  else
  {
    result = -1;
  }
  return result;
}

// File Line: 5563
// RVA: 0x5D8E0
void __fastcall UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(unsigned int treatmentId, float fade_duration)
{
  unsigned int v2; // ebx
  UFG::VisualTreatmentPostEffect *v3; // rax

  v2 = treatmentId;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v3 = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                             UFG::RenderWorld::msRenderStagePlugin,
                                             UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( v3 )
      UFG::VisualTreatmentPostEffect::StopVisualTreatment(v3, v2, fade_duration);
  }
}

// File Line: 5572
// RVA: 0x5D8A0
void UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments(void)
{
  UFG::VisualTreatmentPostEffect *v0; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v0 = (UFG::VisualTreatmentPostEffect *)UFG::SimObject::GetComponentOfType(
                                             UFG::RenderWorld::msRenderStagePlugin,
                                             UFG::VisualTreatmentPostEffect::_TypeUID);
    if ( v0 )
      UFG::VisualTreatmentPostEffect::StopAllVisualTreatments(v0);
  }
}

// File Line: 5591
// RVA: 0x4E1F0
void __fastcall UFG::RenderWorld::FrontEndPauseEffect_Start(unsigned int visual_treatment_uid)
{
  unsigned int v1; // ebx
  UFG::FrontEndPauseEffect *v2; // rax

  v1 = visual_treatment_uid;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = (UFG::FrontEndPauseEffect *)UFG::SimObject::GetComponentOfType(
                                       UFG::RenderWorld::msRenderStagePlugin,
                                       UFG::FrontEndPauseEffect::_TypeUID);
    if ( v2 )
      UFG::FrontEndPauseEffect::Start(v2, v1);
  }
}

// File Line: 5600
// RVA: 0x4E1B0
void __fastcall UFG::RenderWorld::FrontEndPauseEffect_End(bool fade)
{
  bool v1; // bl
  UFG::FrontEndPauseEffect *v2; // rax

  v1 = fade;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = (UFG::FrontEndPauseEffect *)UFG::SimObject::GetComponentOfType(
                                       UFG::RenderWorld::msRenderStagePlugin,
                                       UFG::FrontEndPauseEffect::_TypeUID);
    if ( v2 )
      UFG::FrontEndPauseEffect::End(v2, v1);
  }
}

// File Line: 5618
// RVA: 0x5B140
void __fastcall Render::SetRenderFeatures(Render::RenderFrameFeatures *features)
{
  *(_QWORD *)&gRenderFrameFeatures.mWorld = *(_QWORD *)&features->mWorld;
  *(_DWORD *)&gRenderFrameFeatures.mAO = *(_DWORD *)&features->mAO;
}

// File Line: 5623
// RVA: 0x4FBF0
Render::RenderFrameFeatures *__fastcall Render::GetRenderFeatures()
{
  return &gRenderFrameFeatures;
}

