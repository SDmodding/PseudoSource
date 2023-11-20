// File Line: 67
// RVA: 0x2AE40
void __fastcall UFG::RenderStageSpotShadow::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  char *v2; // rax

  v1 = render_context;
  v2 = UFG::qMalloc(0x500ui64, "RenderStageSpotShadow", 0i64);
  if ( v2 )
    UFG::RenderStageSpotShadow::RenderStageSpotShadow((UFG::RenderStageSpotShadow *)v2, v1);
}

// File Line: 78
// RVA: 0x2A710
void __fastcall UFG::RenderStageSpotShadow::RenderStageSpotShadow(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context)
{
  UFG::RenderContext *v2; // rsi
  UFG::RenderStageSpotShadow *v3; // rbp
  UFG::qResourceHandle *v4; // r14
  unsigned int v5; // eax
  Illusion::Material *v6; // rdi
  int v7; // ebx
  unsigned int v8; // ebx
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax

  v2 = render_context;
  v3 = this;
  v4 = (UFG::qResourceHandle *)&this->mRasterStateDoubleSidedDisableWriteHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRasterStateDoubleSidedDisableWriteHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRasterStateInvertCullingHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mAlphaStateNoColourWriteHandle.mPrev);
  v3->mNumShadowsRendered = 0;
  *(_WORD *)&v3->mRenderedSpotlightLightShaft = 0;
  v3->mSpotShadowViewSettings[0].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[0].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[1].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[1].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[2].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[2].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[3].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[3].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[4].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[4].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[5].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[5].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[6].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[6].mCullPixelDensityThreshold = 1045220557i64;
  v3->mSpotShadowViewSettings[7].mCullIndex = -1;
  *(_QWORD *)&v3->mSpotShadowViewSettings[7].mCullPixelDensityThreshold = 1045220557i64;
  v5 = UFG::qStringHashUpper32("DepthDownsample_SpotShadow", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewMaterial("DepthDownsample_SpotShadow", v5, 4u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLESHADOW", 0xFFFFFFFF);
  LOWORD(v6[1].mNode.mChild[0]) = 0;
  HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.mNode.mNext) = v7;
  v8 = v2->mSingleShadowTextureAliasDepth->mNode.mUID;
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
  v3->mMatDepthDownsampleSpotShadow = v6;
  v10 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v10;
  }
  UFG::qResourceHandle::Init(v4, 0x3BC715E0u, 0x418CAF43u, v10);
  v12 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mAlphaStateNoColourWriteHandle.mPrev,
    0x12C800F2u,
    0x91A2DD53,
    v12);
  v14 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mRasterStateInvertCullingHandle.mPrev,
    0x3BC715E0u,
    0xBC9FAF09,
    v14);
}

// File Line: 126
// RVA: 0x2B110
void __fastcall UFG::RenderStageSpotShadow::RegisterViews(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context)
{
  unsigned int *v2; // rbp
  int *v3; // rbx
  unsigned int v4; // edi
  Render::LightInstance *v5; // rdx
  Render::Light *v6; // r8
  float fFar; // xmm2_4
  float v8; // xmm3_4
  CullManager *v9; // rax
  unsigned int v10; // eax
  CullManager *v11; // rax
  CullManager::CullSettings view_settings; // [rsp+40h] [rbp-B8h]

  v2 = gSpotShadowIndices;
  v3 = &this->mSpotShadowViewSettings[0].mCullIndex;
  v4 = 0;
  do
  {
    if ( v4 >= gSpotShadowCount )
    {
      v11 = CullManager::Instance();
      CullManager::DeregisterView(v11, *v3);
      *v3 = -1;
    }
    else
    {
      v5 = &gCulledLights[*v2];
      v6 = gLights[v5->lightIndex];
      fFar = v6->mDecayRadius * v5->radScale;
      if ( fFar < 0.0099999998 )
        fFar = FLOAT_0_0099999998;
      v8 = v6->mShadowNear;
      if ( v6->mType == 5 )
      {
        if ( v8 <= (float)(v6->mAreaLightNearOffset * 0.5) )
          v8 = v6->mAreaLightNearOffset * 0.5;
        Render::BuildShadowSpotView(
          (UFG::qMatrix44 *)v3 - 2,
          (UFG::qMatrix44 *)v3 - 1,
          &v6->mTransform,
          v8,
          fFar,
          v6->mFovHalfInner * 2.0,
          v6->mAreaLightWidth / v6->mAreaLightHeight);
      }
      else
      {
        Render::BuildShadowSpotView(
          (UFG::qMatrix44 *)v3 - 2,
          (UFG::qMatrix44 *)v3 - 1,
          &v6->mTransform,
          v8,
          fFar,
          v6->mFovHalfOuter * 2.0,
          1.0);
      }
      *(_QWORD *)&view_settings.mViewFlags = 0i64;
      CullManager::CullSettings::SetFromViewSettings(&view_settings, (Render::ViewSettings *)(v3 - 32));
      v9 = CullManager::Instance();
      v10 = CullManager::RegisterView(v9, &view_settings);
      *v3 = v10;
      Illusion::eCastShadow::SetSpotShadowView(v10);
    }
    ++v4;
    ++v2;
    v3 += 36;
  }
  while ( v4 < 8 );
}

// File Line: 182
// RVA: 0x2CE10
UFG::qTaskGroup *__fastcall UFG::RenderStageSpotShadow::SubmitCullingTasks(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageSpotShadow *v2; // rsi
  __int64 v3; // rdi
  CullManager *v4; // rax
  UFG::qTaskGroup *result; // rax

  v2 = this;
  if ( gSpotShadowCount )
  {
    v3 = 0i64;
    if ( gSpotShadowCount )
    {
      do
      {
        v4 = CullManager::Instance();
        CullManager::BeginView(v4, v2->mSpotShadowViewSettings[v3].mCullIndex, 0i64);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < gSpotShadowCount );
    }
    result = CullManager::Instance()->mPrevCullingTask;
    v2->mNumShadowsRendered = 0;
  }
  else
  {
    this->mNumShadowsRendered = 0;
    result = 0i64;
  }
  return result;
}

// File Line: 201
// RVA: 0x2CE90
UFG::SpotShadowRenderQueueTaskResults *__fastcall UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, UFG::qTaskGroup *task_group_dep, CullLayer *cull_layer)
{
  UFG::qTaskGroup *v4; // rdi
  UFG::RenderStageSpotShadow *v5; // rsi
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // r15
  unsigned int v9; // eax
  unsigned int v10; // ebx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  unsigned int v13; // ebx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  int v16; // er13
  unsigned int *v17; // rax
  UFG::qTaskGroup **v18; // r12
  signed __int64 v19; // rdx
  char *v20; // rax
  UFG::qTaskGroup *v21; // rbx
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v22; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v23; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v24; // rsi
  signed __int64 v25; // rdi
  signed __int64 v26; // r14
  char *v27; // rax
  _OWORD *v28; // rbp
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
  int v43; // [rsp+20h] [rbp-B8h]
  unsigned int *v44; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 *b; // [rsp+38h] [rbp-A0h]
  __int64 v46; // [rsp+40h] [rbp-98h]
  UFG::qTaskGroup **v47; // [rsp+48h] [rbp-90h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-78h]
  UFG::RenderStageSpotShadow *v49; // [rsp+E0h] [rbp+8h]
  CullLayer *v50; // [rsp+F8h] [rbp+20h]

  v50 = cull_layer;
  v49 = this;
  v4 = task_group_dep;
  v5 = this;
  if ( !gSpotShadowCount )
    return 0i64;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x660u, 0x20u);
  if ( v6 )
  {
    UFG::SpotShadowRenderQueueTaskResults::SpotShadowRenderQueueTaskResults((UFG::SpotShadowRenderQueueTaskResults *)v6);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v46 = v8;
  *(_DWORD *)(v8 + 1600) = gSpotShadowCount;
  v9 = _S1_5;
  if ( !(_S1_5 & 1) )
  {
    _S1_5 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandle_0.mPrev);
    atexit(UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandle__);
    v9 = _S1_5;
  }
  if ( !(v9 & 2) )
  {
    _S1_5 = v9 | 2;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandleAlpha.mPrev);
    atexit(UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandleAlpha__);
  }
  if ( !simpleInit_0 )
  {
    v10 = UFG::qStringHashUpper32("DR_EmitDepthAlpha", 0xFFFFFFFF);
    v11 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v11;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandleAlpha.mPrev, 0x8B5561A1, v10, v11);
    v13 = UFG::qStringHashUpper32("DR_EmitDepthFBX", 0xFFFFFFFF);
    v14 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v14;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandle_0.mPrev, 0x8B5561A1, v13, v14);
    simpleInit_0 = 1;
  }
  v16 = 0;
  v43 = 0;
  if ( *(_DWORD *)(v8 + 1600) > 0 )
  {
    v17 = gSpotShadowIndices;
    v44 = gSpotShadowIndices;
    v18 = (UFG::qTaskGroup **)(v8 + 1536);
    v47 = (UFG::qTaskGroup **)(v8 + 1536);
    v19 = (signed __int64)&v5->mSpotShadowViewSettings[0].mProjection;
    b = &v5->mSpotShadowViewSettings[0].mProjection;
    do
    {
      if ( gLights[gCulledLights[*v17].lightIndex]->mShadowFlags & 2 )
      {
        v20 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
        v21 = (UFG::qTaskGroup *)v20;
        if ( v20 )
          UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v20, "SpotShadowTaskGroup");
        v22 = UFG::gTaskManager.mSingleFrameTaskGroups;
        v23 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v21->mPrev;
        v21->mPrev = v23;
        v21->mNext = &v22->mNode;
        v22->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v21->mPrev;
        if ( v4 )
          UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v21, v4);
        v24 = &v21->mTasks;
        v25 = v8 + ((signed __int64)v16 << 7);
        v26 = 4i64;
        do
        {
          v27 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
          v28 = v27;
          *((_QWORD *)v27 + 15) = v25;
          *((_DWORD *)v27 + 32) = 4;
          *((_QWORD *)v27 + 9) = v8 + ((v16 + 16i64) << 6);
          *((_QWORD *)v27 + 10) = v50;
          *((_QWORD *)v27 + 18) = simpleHandle_0.mData;
          *((_QWORD *)v27 + 12) = simpleHandleAlpha.mData;
          *((_QWORD *)v27 + 19) = v49->mAlphaStateNoColourWriteHandle.mData;
          *((_QWORD *)v27 + 20) = v49->mRasterStateInvertCullingHandle.mData;
          *((_QWORD *)v27 + 21) = v49->mRasterStateDoubleSidedDisableWriteHandle.mData;
          *((_DWORD *)v27 + 34) = Render::cbLocalProjectionState::sStateParamIndex;
          *((_QWORD *)v27 + 14) = Illusion::gEngine.FrameMemory;
          *((_DWORD *)v27 + 26) = 0;
          *((_DWORD *)v27 + 33) = Illusion::gEngine.mFrameCount;
          *((_DWORD *)v27 + 16) = LODWORD(b[1].v0.x);
          v29 = UFG::qMatrix44::operator*(b - 1, &result, b);
          v30 = v29->v1;
          v31 = v29->v2;
          v32 = v29->v3;
          *v28 = v29->v0;
          v28[1] = v30;
          v28[2] = v31;
          v28[3] = v32;
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
            *((_QWORD *)v34 + 12) = v28;
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
          v25 += 32i64;
          --v26;
        }
        while ( v26 );
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v21);
        v18 = v47;
        *v47 = v21;
        v4 = v21;
        v8 = v46;
        v16 = v43;
        v19 = (signed __int64)b;
      }
      else
      {
        *v18 = 0i64;
      }
      v43 = ++v16;
      ++v18;
      v47 = v18;
      v17 = v44 + 1;
      ++v44;
      v19 += 144i64;
      b = (UFG::qMatrix44 *)v19;
    }
    while ( v16 < *(_DWORD *)(v8 + 1600) );
  }
  return (UFG::SpotShadowRenderQueueTaskResults *)v8;
}

// File Line: 291
// RVA: 0x2B450
UFG::SpotShadowRenderQueueSimResults *__fastcall UFG::RenderStageSpotShadow::RenderSpotShadowsSim(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, CullLayer *simple_drawable_cull_layer, CullLayer *composite_cull_layer)
{
  CullLayer *v4; // rdi
  CullLayer *v5; // rsi
  UFG::RenderContext *v6; // r13
  UFG::RenderStageSpotShadow *v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r15
  unsigned int v11; // er14
  unsigned int v12; // ebx
  CullManager *v13; // rax
  Illusion::StateArgs *v14; // r12
  UFG::qMatrix44 *v15; // rbx
  unsigned __int16 v16; // ax
  float v17; // xmm7_4
  float v18; // xmm6_4
  char *v19; // rbx
  Illusion::StateValues *v20; // rax
  CB_WaterOffset *v21; // rbx
  Illusion::StateValues *v22; // rax
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rbx
  unsigned int v26; // edi
  int v27; // er14
  __int64 v28; // rsi
  __int64 v29; // r8
  __int64 v30; // rdx
  float v31; // xmm1_4
  int v32; // eax
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // rbx
  unsigned int v37; // edi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  char *v40; // rax
  char *v41; // rbx
  Illusion::StateArgs *v42; // rcx
  __int64 v43; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v44; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v45; // rax
  int i; // [rsp+50h] [rbp-B0h]
  Render::cbViewTransformState arg; // [rsp+60h] [rbp-A0h]
  __int64 v49; // [rsp+B0h] [rbp-50h]
  const char *v50; // [rsp+B8h] [rbp-48h]
  __int64 v51; // [rsp+C0h] [rbp-40h]
  int v52; // [rsp+C8h] [rbp-38h]
  __int64 v53; // [rsp+D0h] [rbp-30h]
  __int64 v54; // [rsp+D8h] [rbp-28h]
  const char *v55; // [rsp+E0h] [rbp-20h]
  __int64 v56; // [rsp+E8h] [rbp-18h]
  int v57; // [rsp+F0h] [rbp-10h]
  __int64 v58; // [rsp+F8h] [rbp-8h]
  char *v59; // [rsp+100h] [rbp+0h]
  Illusion::StateArgs *v60; // [rsp+108h] [rbp+8h]
  UFG::qResourceData *v61; // [rsp+110h] [rbp+10h]
  UFG::qResourceData *v62; // [rsp+118h] [rbp+18h]
  __int64 v63; // [rsp+120h] [rbp+20h]
  Render::View view; // [rsp+130h] [rbp+30h]
  RenderQueueLayer v65; // [rsp+2C0h] [rbp+1C0h]
  ShadowSubmitContext ptr; // [rsp+3A0h] [rbp+2A0h]
  UFG::RenderStageSpotShadow *v67; // [rsp+10A0h] [rbp+FA0h]
  CullLayer *v68; // [rsp+10B0h] [rbp+FB0h]
  CullLayer *v69; // [rsp+10B8h] [rbp+FB8h]

  v69 = composite_cull_layer;
  v68 = simple_drawable_cull_layer;
  v67 = this;
  v63 = -2i64;
  v4 = composite_cull_layer;
  v5 = simple_drawable_cull_layer;
  v6 = render_context;
  v7 = this;
  if ( !gSpotShadowCount )
    return 0i64;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x108u, 8u);
  v59 = v8;
  if ( v8 )
  {
    UFG::SpotShadowRenderQueueSimResults::SpotShadowRenderQueueSimResults((UFG::SpotShadowRenderQueueSimResults *)v8);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_DWORD *)v10 = gSpotShadowCount;
  RenderQueueLayer::RenderQueueLayer(&v65);
  ShadowSubmitContext::ShadowSubmitContext(&ptr);
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v65;
  v62 = v7->mAlphaStateNoColourWriteHandle.mData;
  v61 = v7->mRasterStateInvertCullingHandle.mData;
  ptr.mPerPhaseParams = (ShadowSubmitContext::PerPhaseParams *)&v61;
  v11 = 0;
  for ( i = 0; v11 < *(_DWORD *)v10; v7 = v67 )
  {
    v65.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v10 + 16i64 * v11 + 72);
    Render::View::View(&view, &v7->mSpotShadowViewSettings[v11], (Illusion::SubmitContext *)&ptr.vfptr);
    v12 = view.mSettings->mCullIndex;
    v13 = CullManager::Instance();
    CullManager::EndView(v13, v12);
    Render::View::BeginTarget(&view, v6->mSingleShadowTarget, "SpotShadowTarget", 0, 0, 0i64, 1, 0, 0, 0);
    v14 = Render::View::GetStateArgs(&view);
    v15 = &view.mSettings->mProjection;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
    {
      v16 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
      Render::cbViewTransformState::sStateParamIndex = v16;
      arg.mStateParamIndex = v16;
    }
    arg.mWorldViewProjection = &view.mWorldViewProjection;
    arg.mViewWorld = &view.mViewWorld;
    arg.mProjection = v15;
    arg.mScreenOffset = &Render::View::mScreenOffset;
    arg.mCached_Remote.m_Stream = 0i64;
    v17 = UFG::Metrics::msInstance.mSimTimeDelta;
    v18 = UFG::Metrics::msInstance.mSimTime_Temp;
    v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v19 = v18;
    *((float *)v19 + 1) = v17;
    v20 = Render::View::GetStateValues(&view);
    v20->mSetValueMask.mFlags[0] |= 0x2000ui64;
    v20->mParamValues[13] = v19;
    v21 = UFG::Water::GetWaterSettings();
    v22 = Render::View::GetStateValues(&view);
    v22->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
    v22->mParamValues[45] = v21;
    Illusion::StateArgs::Set<Render::cbViewTransformState>(v14, &arg);
    if ( v4 )
    {
      v23 = view.mSettings->mCullIndex;
      if ( (signed int)v23 >= 0 && (signed int)v23 <= 16 && v4->mDrawEnabled )
        v24 = (__int64)v4->mCullResultBuckets[v23].mHead;
      else
        v24 = 0i64;
      v49 = 0i64;
      v50 = "CullResultBucketIterator";
      v25 = v24;
      v51 = v24;
      v52 = 0;
      v26 = 0;
      v53 = 0i64;
      v27 = 0;
      if ( v24 )
      {
        do
        {
          v28 = *(_QWORD *)(v25 + 8i64 * v26 + 24);
          if ( (*(_BYTE *)(v28 + 32) & 3) == 1 && !*(_BYTE *)(v28 + 1240) )
          {
            v29 = *(_QWORD *)(v28 + 1256);
            if ( v29 )
            {
              v30 = v6->mMainViewSettings.mCullIndex;
              if ( v6->mMainViewSettings.mCullIndex > 16
                || v6->mMainViewSettings.mCullIndex < 0
                || (unsigned __int8)(*(_BYTE *)(v30 + v29) - 4) > 1u )
              {
                if ( (signed int)v30 >= 6 )
                  v31 = *(float *)&FLOAT_1_0;
                else
                  v31 = *(float *)(v29 + 4 * v30 + 40);
                v32 = UFG::CompositeDrawableComponent::GetLOD(
                        *(UFG::CompositeDrawableComponent **)(v25 + 8i64 * v26 + 24),
                        v31);
                UFG::CompositeDrawableComponent::Draw((UFG::CompositeDrawableComponent *)v28, &view, v32);
              }
            }
          }
          LODWORD(v53) = ++v26;
          if ( v26 == *(_DWORD *)(v25 + 8) )
          {
            v25 = *(_QWORD *)v25;
            v51 = v25;
            v26 = 0;
            LODWORD(v53) = 0;
          }
        }
        while ( v25 );
        HIDWORD(v53) = v27;
        v5 = v68;
        v11 = i;
      }
      else
      {
        v11 = i;
      }
    }
    if ( v5 )
    {
      v34 = view.mSettings->mCullIndex;
      if ( (signed int)v34 >= 0 && (signed int)v34 <= 16 && v5->mDrawEnabled )
        v35 = (__int64)v5->mCullResultBuckets[v34].mHead;
      else
        v35 = 0i64;
      v54 = 0i64;
      v55 = "CullResultBucketIterator";
      v36 = v35;
      v56 = v35;
      v57 = 0;
      v37 = 0;
      v58 = 0i64;
      if ( v35 )
      {
        do
        {
          Render::SimpleDrawableComponent::Draw(*(Render::SimpleDrawableComponent **)(v36 + 8i64 * v37++ + 24), &view);
          LODWORD(v58) = v37;
          if ( v37 == *(_DWORD *)(v36 + 8) )
          {
            v36 = *(_QWORD *)v36;
            v56 = v36;
            v37 = 0;
            LODWORD(v58) = 0;
          }
        }
        while ( v36 );
        HIDWORD(v58) = 0;
        v11 = i;
      }
      v5 = v68;
    }
    v38 = arg.mPrev;
    v39 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v39->mPrev = v38;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v14->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v14 + 16 * (arg.mStateParamIndex + 3i64)) )
      v14->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    RenderQueueLayer::SerializeRenderQueues(&v65);
    v40 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v41 = v40;
    v59 = v40;
    if ( v40 )
    {
      *(_QWORD *)v40 = v40;
      *((_QWORD *)v40 + 1) = v40;
      v42 = (Illusion::StateArgs *)(v40 + 16);
      v60 = v42;
      v42->mStateArgsCreateMask.mFlags[0] = (unsigned __int64)v42;
      v42->mStateArgsCreateMask.mFlags[1] = (unsigned __int64)v42;
      UFG::qMemSet(v40 + 96, 0, 0x400u);
      *((_QWORD *)v41 + 11) = 0i64;
      *((_QWORD *)v41 + 10) = 0i64;
      *((_DWORD *)v41 + 8) = 0;
      *((_QWORD *)v41 + 5) = 0i64;
      *((_QWORD *)v41 + 6) = 0i64;
      *((_QWORD *)v41 + 7) = 0i64;
      *((_QWORD *)v41 + 8) = 0i64;
      *((_QWORD *)v41 + 9) = 0i64;
    }
    else
    {
      v41 = 0i64;
    }
    v43 = v11;
    *(_QWORD *)(v10 + 8 * v43 + 200) = v41;
    *(_QWORD *)(v10 + 8 * v43 + 8) = v6->mSingleShadowTarget;
    v44 = arg.mPrev;
    v45 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v45->mPrev = v44;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    i = ++v11;
    v4 = v69;
  }
  FastShadowDraw_Dynamic(
    v7->mSpotShadowViewSettings,
    v6->mMainViewSettings.mCullIndex,
    (Illusion::RenderQueue **)(v10 + 200),
    *(_DWORD *)v10);
  v60 = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v65);
  return (UFG::SpotShadowRenderQueueSimResults *)v10;
}

// File Line: 388
// RVA: 0x2AF70
void __fastcall UFG::RenderStageSpotShadow::DownsampleShadows_Spotlight(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rdi
  UFG::RenderStageSpotShadow *v5; // rsi
  _WORD *v6; // rbx
  unsigned int v7; // er8
  Illusion::Material *v8; // rdi
  __int64 v9; // rax
  RenderQueueLayer v10; // [rsp+60h] [rbp-EF8h]
  Render::View v11; // [rsp+140h] [rbp-E18h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h]
  Render::Poly poly; // [rsp+F60h] [rbp+8h]
  Illusion::StateArgs *v14; // [rsp+F68h] [rbp+10h]

  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  RenderQueueLayer::RenderQueueLayer(&v10);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v10.mSerializationList = v3;
  ptr.mRenderQueueProvider = &v10;
  v6 = 0i64;
  ptr.mQueueMode = 0;
  Render::View::View(&v11, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  Render::View::BeginTarget(&v11, v4->mHalfSizeSingleShadowTarget, "SpotShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v11, &UFG::qColour::Black, 6u, 1.0, 0);
  v7 = v4->mSingleShadowTextureAliasDepth->mNode.mUID;
  v8 = v5->mMatDepthDownsampleSpotShadow;
  if ( LODWORD(v8[1].mStateBlockMask.mFlags[0]) != v7 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[1].mDebugName[20], v8[1].mStateBlockMask.mFlags[1], v7);
    v9 = v8->mMaterialUser.mOffset;
    if ( v9 )
      v6 = (_WORD *)((char *)&v8->mMaterialUser + v9);
    *v6 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v11, &poly, v5->mMatDepthDownsampleSpotShadow, 0i64);
  Render::View::EndTarget(&v11);
  RenderQueueLayer::SerializeRenderQueues(&v10);
  v14 = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v10);
}

// File Line: 418
// RVA: 0x2BAC0
void __fastcall UFG::RenderStageSpotShadow::RenderSpotlightLightShafts(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, Render::Light *lightShaftLight, Render::LightInstance *lightShaftLightInstance)
{
  Render::Light *v5; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // rdi
  UFG::RenderContext *v7; // r14
  UFG::RenderStageSpotShadow *v8; // r13
  Render::LightInstance *v9; // r15
  float v10; // xmm6_4
  float fAspectRatio; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  float v22; // xmm12_4
  float v23; // xmm13_4
  float v24; // xmm14_4
  float v25; // xmm15_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  Illusion::StateArgs *v29; // rsi
  Render::ViewSettings *v30; // rdi
  unsigned __int16 v31; // ax
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  float v38; // xmm0_4
  Render::ViewSettings *v39; // rdi
  UFG::qMatrix44 *v40; // r12
  unsigned __int16 v41; // ax
  unsigned __int16 v42; // ax
  float *v43; // rdi
  UFG::qMatrix44 *v44; // rax
  float v45; // xmm7_4
  float v46; // xmm11_4
  float v47; // xmm3_4
  float v48; // xmm6_4
  float v49; // xmm10_4
  float v50; // xmm2_4
  float v51; // xmm5_4
  float v52; // xmm9_4
  float v53; // xmm1_4
  float v54; // xmm4_4
  float v55; // xmm8_4
  float v56; // xmm7_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm2_4
  float v60; // xmm5_4
  float v61; // xmm1_4
  float v62; // xmm3_4
  float v63; // xmm5_4
  __m128 v64; // xmm3
  float v65; // xmm4_4
  __m128 v66; // xmm2
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm5_4
  __m128 v70; // xmm3
  float v71; // xmm4_4
  __m128 v72; // xmm2
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm5_4
  __m128 v76; // xmm3
  float v77; // xmm4_4
  __m128 v78; // xmm2
  float v79; // xmm0_4
  float v80; // xmm1_4
  __m128 v81; // xmm5
  float v82; // xmm4_4
  __m128 v83; // xmm2
  float v84; // xmm0_4
  float v85; // xmm1_4
  float v86; // xmm7_4
  float v87; // xmm8_4
  float v88; // xmm4_4
  float v89; // xmm2_4
  float v90; // xmm6_4
  float v91; // xmm3_4
  float v92; // xmm2_4
  float v93; // xmm6_4
  float v94; // xmm4_4
  bool v95; // zf
  Illusion::Material *v96; // r15
  unsigned int v97; // er8
  __int64 v98; // rax
  _WORD *v99; // rax
  unsigned int v100; // eax
  Illusion::Material *v101; // rbx
  __int64 v102; // rax
  _WORD *v103; // rax
  Illusion::Material *v104; // rbx
  __int64 v105; // rax
  _WORD *v106; // rax
  Illusion::Material *v107; // rbx
  __int64 v108; // rax
  _WORD *v109; // rax
  Illusion::StateValues *v110; // rax
  float v111; // xmm7_4
  float v112; // xmm6_4
  char *v113; // rbx
  Illusion::StateValues *v114; // rax
  Illusion::Material *fFar; // ST20_8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v116; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v117; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v118; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v119; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v120; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v121; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v122; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v123; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v124; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v125; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v126; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v127; // rax
  Render::cbExternalViewTransformState v128; // [rsp+50h] [rbp-B0h]
  Render::cbDeferredLightState arg; // [rsp+90h] [rbp-70h]
  Render::cbShadowTransformState v130; // [rsp+100h] [rbp+0h]
  UFG::qMatrix44 local_world; // [rsp+160h] [rbp+60h]
  UFG::qMatrix44 v132; // [rsp+1A0h] [rbp+A0h]
  __int64 v133; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 shadowProjection; // [rsp+1F0h] [rbp+F0h]
  UFG::qMatrix44 shadowWorldView; // [rsp+230h] [rbp+130h]
  Render::View v136; // [rsp+270h] [rbp+170h]
  RenderQueueLayer v137; // [rsp+400h] [rbp+300h]
  UFG::qMatrix44 result; // [rsp+4E0h] [rbp+3E0h]
  LayerSubmitContext ptr; // [rsp+520h] [rbp+420h]
  float v140; // [rsp+1270h] [rbp+1170h]
  float v141; // [rsp+1290h] [rbp+1190h]

  v133 = -2i64;
  v5 = lightShaftLight;
  v6 = serialization_list;
  v7 = render_context;
  v8 = this;
  v9 = lightShaftLightInstance;
  v10 = lightShaftLight->mDecayRadius * lightShaftLightInstance->radScale;
  v140 = lightShaftLight->mDecayRadius * lightShaftLightInstance->radScale;
  fAspectRatio = *(float *)&FLOAT_1_0;
  v12 = lightShaftLight->mShadowNear;
  if ( lightShaftLight->mType == 5 )
  {
    if ( v12 <= (float)(lightShaftLight->mAreaLightNearOffset * 0.5) )
      v12 = lightShaftLight->mAreaLightNearOffset * 0.5;
    fAspectRatio = lightShaftLight->mAreaLightWidth / lightShaftLight->mAreaLightHeight;
    v13 = lightShaftLight->mFovHalfInner;
  }
  else
  {
    v13 = lightShaftLight->mFovHalfOuter;
  }
  Render::BuildShadowSpotView(
    &shadowWorldView,
    &shadowProjection,
    &lightShaftLight->mTransform,
    v12,
    v10,
    v13 * 2.0,
    fAspectRatio);
  if ( lightShaftLightInstance->flags & 2 )
    UFG::RenderStageSpotShadow::DownsampleShadows_Spotlight(v8, v7, v6);
  v141 = tanf(v5->mFovHalfOuter) * v10;
  v14 = v5->mTransform.v0.x;
  v15 = v5->mTransform.v0.y;
  v16 = v5->mTransform.v0.z;
  v17 = v5->mTransform.v0.w;
  v18 = v5->mTransform.v1.x;
  v19 = v5->mTransform.v1.y;
  v20 = v5->mTransform.v1.z;
  v21 = v5->mTransform.v1.w;
  v22 = v5->mTransform.v2.x;
  v23 = v5->mTransform.v2.y;
  v24 = v5->mTransform.v2.z;
  v25 = v5->mTransform.v2.w;
  v26 = v5->mTransform.v3.y;
  v27 = v5->mTransform.v3.z;
  v28 = v5->mTransform.v3.w;
  local_world.v3.x = v5->mTransform.v3.x;
  local_world.v3.y = v26;
  local_world.v3.z = v27;
  local_world.v3.w = v28;
  local_world.v0.x = v14 * v141;
  local_world.v0.y = v15 * v141;
  local_world.v0.z = v16 * v141;
  local_world.v0.w = v17 * v141;
  local_world.v1.x = v18 * v141;
  local_world.v1.y = v19 * v141;
  local_world.v1.z = v20 * v141;
  local_world.v1.w = v21 * v141;
  local_world.v2.x = v22 * v140;
  local_world.v2.y = v23 * v140;
  local_world.v2.z = v24 * v140;
  local_world.v2.w = v25 * v140;
  RenderQueueLayer::RenderQueueLayer(&v137);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v137.mSerializationList = v6;
  ptr.mRenderQueueProvider = &v137;
  ptr.mQueueMode = 0;
  Render::View::View(&v136, &v7->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  v29 = Render::View::GetStateArgs(&v136);
  Render::View::BeginTarget(&v136, v7->mQuarterSizeVolumetricTarget, "LightShaftSpotlight", 0, 0, 0i64, 0, 0, 0, 0);
  v30 = v136.mSettings;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbDeferredLightState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == -1 )
  {
    v31 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
    Render::cbDeferredLightState::sStateParamIndex = v31;
    arg.mStateParamIndex = v31;
  }
  arg.mWorldView = &v30->mWorldView;
  v32 = v9->colorFade * v5->mColor.z;
  v33 = v9->colorFade * v5->mColor.y;
  v34 = v9->colorFade * v5->mColor.x;
  arg.mColor.x = v34 * v34;
  arg.mColor.y = v33 * v33;
  arg.mColor.z = v32 * v32;
  v35 = v5->mTransform.v3.y;
  v36 = v5->mTransform.v3.z;
  arg.mPosition.x = v5->mTransform.v3.x;
  arg.mPosition.y = v35;
  arg.mPosition.z = v36;
  arg.mDecayRadius = v140;
  arg.mDecayPower = v5->mDecayPower;
  arg.mShadowFade = v9->shadowFade;
  v37 = cosf(v5->mFovHalfOuter);
  arg.mFovInner = cosf(v5->mFovHalfInner);
  arg.mFovOuter = v37;
  if ( v5->mTexDistAttenUID == -1 )
    v38 = FLOAT_N1_0;
  else
    v38 = v5->mTexDistAttenV;
  arg.mTexDistAttenV = v38;
  Illusion::StateArgs::Set<Render::cbDeferredLightState>(v29, &arg);
  v39 = v136.mSettings;
  v40 = &v136.mSettings->mProjection;
  v128.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v128.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v128.mCallback = 0i64;
  v128.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v128.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v41 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v41;
    v128.mStateParamIndex = v41;
  }
  v128.mWorldView = &v39->mWorldView;
  v128.mProjection = v40;
  v128.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v29, &v128);
  v130.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v130.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v130.mCallback = 0i64;
  v130.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v130.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v42 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v42;
    v130.mStateParamIndex = v42;
  }
  v130.mViewWorld = &v136.mViewWorld;
  v130.mWorldView = &shadowWorldView;
  v130.mProjection = &shadowProjection;
  v130.mCutplanes = 0i64;
  _mm_store_si128((__m128i *)&v130.mBiases, (__m128i)0i64);
  v130.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v29, &v130);
  v43 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x80u);
  v44 = UFG::qMatrix44::operator*(&v136.mViewWorld, &result, &shadowWorldView);
  UFG::qMatrix44::operator*(v44, &v132, &shadowProjection);
  v45 = v132.v3.x;
  v46 = v132.v3.w;
  v47 = v132.v3.x + v132.v3.w;
  v48 = v132.v2.x;
  v49 = v132.v2.w;
  v50 = v132.v2.x + v132.v2.w;
  v51 = v132.v1.x;
  v52 = v132.v1.w;
  v53 = v132.v1.x + v132.v1.w;
  v54 = v132.v0.x;
  v55 = v132.v0.w;
  *v43 = v132.v0.x + v132.v0.w;
  v43[1] = v53;
  v43[2] = v50;
  v43[3] = v47;
  v43[4] = v55 - v54;
  v43[5] = v52 - v51;
  v43[6] = v49 - v48;
  v43[7] = v46 - v45;
  v56 = v132.v3.y;
  v57 = v46 - v132.v3.y;
  v58 = v132.v2.y;
  v59 = v49 - v132.v2.y;
  v60 = v132.v1.y;
  v61 = v52 - v132.v1.y;
  v62 = v132.v0.y;
  v43[8] = v55 - v132.v0.y;
  v43[9] = v61;
  v43[10] = v59;
  v43[11] = v57;
  v43[12] = v62 + v55;
  v43[13] = v60 + v52;
  v43[14] = v58 + v49;
  v43[15] = v56 + v46;
  v63 = v43[1];
  v64 = (__m128)*(unsigned int *)v43;
  v65 = v43[2];
  v66 = v64;
  v66.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)(v63 * v63)) + (float)(v65 * v65);
  LODWORD(v67) = (unsigned __int128)_mm_sqrt_ps(v66);
  v68 = (float)(1.0 / v67) * v43[3];
  *v43 = v64.m128_f32[0] * (float)(1.0 / v67);
  v43[1] = v63 * (float)(1.0 / v67);
  v43[2] = v65 * (float)(1.0 / v67);
  v43[3] = v68;
  v69 = v43[5];
  v70 = (__m128)*((unsigned int *)v43 + 4);
  v71 = v43[6];
  v72 = v70;
  v72.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v69 * v69)) + (float)(v71 * v71);
  LODWORD(v73) = (unsigned __int128)_mm_sqrt_ps(v72);
  v74 = (float)(1.0 / v73) * v43[7];
  v43[4] = v70.m128_f32[0] * (float)(1.0 / v73);
  v43[5] = v69 * (float)(1.0 / v73);
  v43[6] = v71 * (float)(1.0 / v73);
  v43[7] = v74;
  v75 = v43[9];
  v76 = (__m128)*((unsigned int *)v43 + 8);
  v77 = v43[10];
  v78 = v76;
  v78.m128_f32[0] = (float)((float)(v76.m128_f32[0] * v76.m128_f32[0]) + (float)(v75 * v75)) + (float)(v77 * v77);
  LODWORD(v79) = (unsigned __int128)_mm_sqrt_ps(v78);
  v80 = (float)(1.0 / v79) * v43[11];
  v43[8] = v76.m128_f32[0] * (float)(1.0 / v79);
  v43[9] = v75 * (float)(1.0 / v79);
  v43[10] = v77 * (float)(1.0 / v79);
  v43[11] = v80;
  v81 = (__m128)*((unsigned int *)v43 + 13);
  v76.m128_f32[0] = v43[12];
  v82 = v43[14];
  v83 = v81;
  v83.m128_f32[0] = (float)((float)(v81.m128_f32[0] * v81.m128_f32[0]) + (float)(v76.m128_f32[0] * v76.m128_f32[0]))
                  + (float)(v82 * v82);
  LODWORD(v84) = (unsigned __int128)_mm_sqrt_ps(v83);
  v85 = (float)(1.0 / v84) * v43[15];
  v43[12] = v76.m128_f32[0] * (float)(1.0 / v84);
  v43[13] = v81.m128_f32[0] * (float)(1.0 / v84);
  v43[14] = v82 * (float)(1.0 / v84);
  v43[15] = v85;
  LODWORD(v86) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v5->mTransform.v3.y * v136.mSettings->mWorldView.v1.x)
                                 + (float)(v5->mTransform.v3.x * v136.mSettings->mWorldView.v0.x))
                         + (float)(v5->mTransform.v3.z * v136.mSettings->mWorldView.v2.x))
                 + v136.mSettings->mWorldView.v3.x) ^ _xmm[0];
  LODWORD(v87) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v5->mTransform.v3.y * v136.mSettings->mWorldView.v1.y)
                                 + (float)(v5->mTransform.v3.x * v136.mSettings->mWorldView.v0.y))
                         + (float)(v5->mTransform.v3.z * v136.mSettings->mWorldView.v2.y))
                 + v136.mSettings->mWorldView.v3.y) ^ _xmm[0];
  LODWORD(v88) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v5->mTransform.v3.y * v136.mSettings->mWorldView.v1.z)
                                 + (float)(v5->mTransform.v3.x * v136.mSettings->mWorldView.v0.z))
                         + (float)(v5->mTransform.v3.z * v136.mSettings->mWorldView.v2.z))
                 + v136.mSettings->mWorldView.v3.z) ^ _xmm[0];
  v89 = (float)((float)(v87 * v87) + (float)(v86 * v86)) + (float)(v88 * v88);
  if ( v89 == 0.0 )
    v90 = 0.0;
  else
    v90 = 1.0 / fsqrt(v89);
  v91 = v90 * v88;
  v92 = v90 * v87;
  v93 = v90 * v86;
  v94 = s_clipThreshold;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v92 * v43[1]) + (float)(*v43 * v93)) + (float)(v91 * v43[2])) ^ _xmm[0]) <= s_clipThreshold )
  {
    *v43 = 1.0;
    v43[1] = 1.0;
    *((_QWORD *)v43 + 1) = 1065353216i64;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v92 * v43[5]) + (float)(v43[4] * v93)) + (float)(v91 * v43[6])) ^ _xmm[0]) <= v94 )
  {
    v43[4] = 1.0;
    v43[5] = 1.0;
    *((_QWORD *)v43 + 3) = 1065353216i64;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v92 * v43[9]) + (float)(v43[8] * v93)) + (float)(v91 * v43[10])) ^ _xmm[0]) <= v94 )
  {
    v43[8] = 1.0;
    v43[9] = 1.0;
    *((_QWORD *)v43 + 5) = 1065353216i64;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v43[12] * v93) + (float)(v92 * v43[13])) + (float)(v91 * v43[14])) ^ _xmm[0]) <= v94 )
  {
    v43[12] = 1.0;
    v43[13] = 1.0;
    *((_QWORD *)v43 + 7) = 1065353216i64;
  }
  v95 = (v9->flags & 2) == 0;
  v96 = v7->mLightShaftSpotLightMaterial;
  if ( v95 )
  {
    if ( LODWORD(v96[3].mNode.mChild[0]) == -1324127765 )
      goto LABEL_37;
    v97 = -1324127765;
  }
  else
  {
    v97 = v7->mHalfSizeSingleShadowAliasTexture->mNode.mUID;
    if ( LODWORD(v96[3].mNode.mChild[0]) == v97 )
      goto LABEL_37;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v96[2].mNumParams, (unsigned int)v96[3].mNode.mChild[1], v97);
  v98 = v96->mMaterialUser.mOffset;
  if ( v98 )
    v99 = (_WORD *)((char *)&v96->mMaterialUser + v98);
  else
    v99 = 0i64;
  *v99 |= 0x20u;
LABEL_37:
  v100 = v5->mTextureUID;
  if ( v100 == -1 )
    v100 = UFG::qStringHashUpper32("LS_SPOT", 0xFFFFFFFF);
  v101 = v7->mLightShaftSpotLightMaterial;
  if ( *(_DWORD *)&v101[3].mDebugName[12] != v100 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v101[3].mResourceHandles.mNode.mNext,
      *(_DWORD *)&v101[3].mDebugName[20],
      v100);
    v102 = v101->mMaterialUser.mOffset;
    if ( v102 )
      v103 = (_WORD *)((char *)&v101->mMaterialUser + v102);
    else
      v103 = 0i64;
    *v103 |= 0x20u;
  }
  v104 = v7->mLightShaftSpotLightMaterial;
  if ( v104[2].mNode.mUID != -89056095 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v104[2],
      (unsigned int)v104[2].mResourceHandles.mNode.mPrev,
      0xFAB11CA1);
    v105 = v104->mMaterialUser.mOffset;
    if ( v105 )
      v106 = (_WORD *)((char *)&v104->mMaterialUser + v105);
    else
      v106 = 0i64;
    *v106 |= 0x20u;
  }
  v107 = v7->mLightShaftSpotLightMaterial;
  if ( *(_DWORD *)&v107[2].mDebugName[28] != -652645828 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v107[2].mDebugName[4], *((_DWORD *)&v107[2].0 + 22), 0xD9196A3C);
    v108 = v107->mMaterialUser.mOffset;
    if ( v108 )
      v109 = (_WORD *)((char *)&v107->mMaterialUser + v108);
    else
      v109 = 0i64;
    *v109 |= 0x20u;
  }
  v110 = Render::View::GetStateValues(&v136);
  v110->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v110->mParamValues[15] = v43;
  v111 = UFG::Metrics::msInstance.mSimTimeDelta;
  v112 = UFG::Metrics::msInstance.mSimTime_Temp;
  v113 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v113 = v112;
  *((float *)v113 + 1) = v111;
  v114 = Render::View::GetStateValues(&v136);
  v114->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v114->mParamValues[13] = v113;
  fFar = v7->mLightShaftSpotLightMaterial;
  Render::View::Draw(&v136, &gDeferredCone, &local_world, 0);
  v116 = v128.mPrev;
  v117 = v128.mNext;
  v128.mPrev->mNext = v128.mNext;
  v117->mPrev = v116;
  v128.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v128.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v128.mIsSet = 0;
  if ( (Illusion::StateArgs *)v29->mStateArgsCreateMask.mFlags[2 * (v128.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v29 + 16 * (v128.mStateParamIndex + 3i64)) )
    v29->mStateArgsCreateMask.mFlags[(unsigned int)v128.mStateParamIndex >> 6] &= ~(1i64 << (v128.mStateParamIndex & 0x3F));
  v118 = v130.mPrev;
  v119 = v130.mNext;
  v130.mPrev->mNext = v130.mNext;
  v119->mPrev = v118;
  v130.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v130.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v130.mIsSet = 0;
  if ( (Illusion::StateArgs *)v29->mStateArgsCreateMask.mFlags[2 * (v130.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v29 + 16 * (v130.mStateParamIndex + 3i64)) )
    v29->mStateArgsCreateMask.mFlags[(unsigned int)v130.mStateParamIndex >> 6] &= ~(1i64 << (v130.mStateParamIndex & 0x3F));
  v120 = arg.mPrev;
  v121 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v121->mPrev = v120;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v29->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v29 + 16 * (arg.mStateParamIndex + 3i64)) )
    v29->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v136);
  v8->mRenderedSpotlightLightShaft = 1;
  v122 = v130.mPrev;
  v123 = v130.mNext;
  v130.mPrev->mNext = v130.mNext;
  v123->mPrev = v122;
  v130.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v130.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v130;
  v124 = v128.mPrev;
  v125 = v128.mNext;
  v128.mPrev->mNext = v128.mNext;
  v125->mPrev = v124;
  v128.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v128.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v128;
  v126 = arg.mPrev;
  v127 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v127->mPrev = v126;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v137);
}Arg,Illusio

// File Line: 607
// RVA: 0x2B2C0
void __fastcall UFG::RenderStageSpotShadow::RenderBeforeSunShadows(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rdi
  UFG::RenderStageSpotShadow *v5; // rsi
  RenderQueueLayer v6; // [rsp+60h] [rbp-EF8h]
  Render::View v7; // [rsp+140h] [rbp-E18h]
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h]

  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  RenderQueueLayer::RenderQueueLayer(&v6);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v6.mSerializationList = v3;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v6;
  Render::View::View(&v7, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  Render::View::BeginTarget(&v7, v4->mQuarterSizeVolumetricTarget, "VolumetricTargetClear", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v7, &UFG::qColour::Zero, 1u, 1.0, 0);
  Render::View::EndTarget(&v7);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v6);
  v5->mRenderedSpotlightLightShaft = 0;
}

// File Line: 633
// RVA: 0x2B3F0
void __fastcall UFG::RenderStageSpotShadow::RenderDebugSpotShadowOverlay(UFG::RenderStageSpotShadow *this, UFG::RenderContext *render_context, Render::View *view, int x, int y, int size)
{
  Illusion::Texture *v6; // rcx
  UFG::qColour v7; // [rsp+40h] [rbp-18h]

  v6 = render_context->mSingleShadowTarget->mDepthTexture;
  v7 = UFG::qColour::White;
  Render::View::DrawIcon(view, v6->mNode.mUID, x, y, size, size, &v7, 0xA3833FDE);
}

