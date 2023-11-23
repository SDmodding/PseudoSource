// File Line: 67
// RVA: 0x2AE40
void __fastcall UFG::RenderStageSpotShadow::Create(UFG::RenderContext *render_context)
{
  char *v2; // rax

  v2 = UFG::qMalloc(0x500ui64, "RenderStageSpotShadow", 0i64);
  if ( v2 )
    UFG::RenderStageSpotShadow::RenderStageSpotShadow((UFG::RenderStageSpotShadow *)v2, render_context);
}

// File Line: 78
// RVA: 0x2A710
void __fastcall UFG::RenderStageSpotShadow::RenderStageSpotShadow(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context)
{
  Illusion::RasterStateHandle *p_mRasterStateDoubleSidedDisableWriteHandle; // r14
  unsigned int v5; // eax
  Illusion::Material *v6; // rdi
  int v7; // ebx
  unsigned int mUID; // ebx
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax

  p_mRasterStateDoubleSidedDisableWriteHandle = &this->mRasterStateDoubleSidedDisableWriteHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateDoubleSidedDisableWriteHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mRasterStateInvertCullingHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mAlphaStateNoColourWriteHandle);
  this->mNumShadowsRendered = 0;
  *(_WORD *)&this->mRenderedSpotlightLightShaft = 0;
  this->mSpotShadowViewSettings[0].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[0].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[1].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[1].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[2].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[2].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[3].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[3].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[4].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[4].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[5].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[5].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[6].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[6].mCullPixelDensityThreshold = 1045220557i64;
  this->mSpotShadowViewSettings[7].mCullIndex = -1;
  *(_QWORD *)&this->mSpotShadowViewSettings[7].mCullPixelDensityThreshold = 1045220557i64;
  v5 = UFG::qStringHashUpper32("DepthDownsample_SpotShadow", 0xFFFFFFFF);
  v6 = Illusion::Factory::NewMaterial("DepthDownsample_SpotShadow", v5, 4u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLESHADOW", 0xFFFFFFFF);
  LOWORD(v6[1].mNode.mChild[0]) = 0;
  HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6[1].mTypeUID = -1957338719;
  LODWORD(v6[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v7;
  mUID = render_context->mSingleShadowTextureAliasDepth->mNode.mUID;
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
  this->mMatDepthDownsampleSpotShadow = v6;
  Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mRasterStateDoubleSidedDisableWriteHandle, 0x3BC715E0u, 0x418CAF43u, Inventory);
  v12 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(&this->mAlphaStateNoColourWriteHandle, 0x12C800F2u, 0x91A2DD53, v12);
  v14 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(&this->mRasterStateInvertCullingHandle, 0x3BC715E0u, 0xBC9FAF09, v14);
}

// File Line: 126
// RVA: 0x2B110
void __fastcall UFG::RenderStageSpotShadow::RegisterViews(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context)
{
  unsigned int *v2; // rbp
  int *p_mCullIndex; // rbx
  unsigned int i; // edi
  Render::LightInstance *v5; // rdx
  Render::Light *v6; // r8
  float fFar; // xmm2_4
  float mShadowNear; // xmm3_4
  CullManager *v9; // rax
  unsigned int v10; // eax
  CullManager *v11; // rax
  CullManager::CullSettings view_settings; // [rsp+40h] [rbp-B8h] BYREF

  v2 = gSpotShadowIndices;
  p_mCullIndex = &this->mSpotShadowViewSettings[0].mCullIndex;
  for ( i = 0; i < 8; ++i )
  {
    if ( i >= gSpotShadowCount )
    {
      v11 = CullManager::Instance();
      CullManager::DeregisterView(v11, *p_mCullIndex);
      *p_mCullIndex = -1;
    }
    else
    {
      v5 = &gCulledLights[*v2];
      v6 = gLights[v5->lightIndex];
      fFar = v6->mDecayRadius * v5->radScale;
      if ( fFar < 0.0099999998 )
        fFar = FLOAT_0_0099999998;
      mShadowNear = v6->mShadowNear;
      if ( v6->mType == 5 )
      {
        if ( mShadowNear <= (float)(v6->mAreaLightNearOffset * 0.5) )
          mShadowNear = v6->mAreaLightNearOffset * 0.5;
        Render::BuildShadowSpotView(
          (UFG::qMatrix44 *)p_mCullIndex - 2,
          (UFG::qMatrix44 *)p_mCullIndex - 1,
          &v6->mTransform,
          mShadowNear,
          fFar,
          v6->mFovHalfInner * 2.0,
          v6->mAreaLightWidth / v6->mAreaLightHeight);
      }
      else
      {
        Render::BuildShadowSpotView(
          (UFG::qMatrix44 *)p_mCullIndex - 2,
          (UFG::qMatrix44 *)p_mCullIndex - 1,
          &v6->mTransform,
          mShadowNear,
          fFar,
          v6->mFovHalfOuter * 2.0,
          1.0);
      }
      *(_QWORD *)&view_settings.mViewFlags = 0i64;
      CullManager::CullSettings::SetFromViewSettings(&view_settings, (Render::ViewSettings *)(p_mCullIndex - 32));
      v9 = CullManager::Instance();
      v10 = CullManager::RegisterView(v9, &view_settings);
      *p_mCullIndex = v10;
      Illusion::eCastShadow::SetSpotShadowView(v10);
    }
    ++v2;
    p_mCullIndex += 36;
  }
}

// File Line: 182
// RVA: 0x2CE10
UFG::qTaskGroup *__fastcall UFG::RenderStageSpotShadow::SubmitCullingTasks(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context)
{
  __int64 i; // rdi
  CullManager *v4; // rax
  UFG::qTaskGroup *result; // rax

  if ( gSpotShadowCount )
  {
    for ( i = 0i64; (unsigned int)i < gSpotShadowCount; i = (unsigned int)(i + 1) )
    {
      v4 = CullManager::Instance();
      CullManager::BeginView(v4, this->mSpotShadowViewSettings[i].mCullIndex, 0i64);
    }
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

// File Line: 201
// RVA: 0x2CE90
UFG::SpotShadowRenderQueueTaskResults *__fastcall UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        UFG::qTaskGroup *task_group_dep,
        CullLayer *cull_layer)
{
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // r15
  unsigned int v9; // eax
  unsigned int v10; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  unsigned int v13; // ebx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  int v16; // r13d
  unsigned int *v17; // rax
  UFG::qTaskGroup **v18; // r12
  UFG::qMatrix44 *p_mProjection; // rdx
  char *v20; // rax
  UFG::qTaskGroup *v21; // rbx
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mTasks; // rsi
  __int64 v25; // rdi
  __int64 v26; // r14
  char *v27; // rbp
  UFG::qMatrix44 *v28; // rax
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm1
  UFG::qVector4 v31; // xmm0
  char *v32; // rax
  char *v33; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v39; // rax
  int v41; // [rsp+20h] [rbp-B8h]
  unsigned int *v42; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 *b; // [rsp+38h] [rbp-A0h]
  __int64 v44; // [rsp+40h] [rbp-98h]
  UFG::qTaskGroup **v45; // [rsp+48h] [rbp-90h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-78h] BYREF

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
  v44 = v8;
  *(_DWORD *)(v8 + 1600) = gSpotShadowCount;
  v9 = _S1_5;
  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&simpleHandle_0);
    atexit(UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandle__);
    v9 = _S1_5;
  }
  if ( (v9 & 2) == 0 )
  {
    _S1_5 = v9 | 2;
    UFG::qResourceHandle::qResourceHandle(&simpleHandleAlpha);
    atexit(UFG::RenderStageSpotShadow::SubmitSceneryShadowTasks_::_5_::_dynamic_atexit_destructor_for__simpleHandleAlpha__);
  }
  if ( !simpleInit_0 )
  {
    v10 = UFG::qStringHashUpper32("DR_EmitDepthAlpha", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&simpleHandleAlpha, 0x8B5561A1, v10, Inventory);
    v13 = UFG::qStringHashUpper32("DR_EmitDepthFBX", 0xFFFFFFFF);
    v14 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v14;
    }
    UFG::qResourceHandle::Init(&simpleHandle_0, 0x8B5561A1, v13, v14);
    simpleInit_0 = 1;
  }
  v16 = 0;
  v41 = 0;
  if ( *(int *)(v8 + 1600) > 0 )
  {
    v17 = gSpotShadowIndices;
    v42 = gSpotShadowIndices;
    v18 = (UFG::qTaskGroup **)(v8 + 1536);
    v45 = (UFG::qTaskGroup **)(v8 + 1536);
    p_mProjection = &this->mSpotShadowViewSettings[0].mProjection;
    b = &this->mSpotShadowViewSettings[0].mProjection;
    do
    {
      if ( (gLights[gCulledLights[*v17].lightIndex]->mShadowFlags & 2) != 0 )
      {
        v20 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
        v21 = (UFG::qTaskGroup *)v20;
        if ( v20 )
          UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v20, "SpotShadowTaskGroup");
        mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
        mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
        mPrev->mNext = v21;
        v21->mPrev = mPrev;
        v21->mNext = &mSingleFrameTaskGroups->mNode;
        mSingleFrameTaskGroups->mNode.mPrev = v21;
        if ( task_group_dep )
          UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v21, task_group_dep);
        p_mTasks = &v21->mTasks;
        v25 = v8 + ((__int64)v16 << 7);
        v26 = 4i64;
        do
        {
          v27 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
          *((_QWORD *)v27 + 15) = v25;
          *((_DWORD *)v27 + 32) = 4;
          *((_QWORD *)v27 + 9) = v8 + ((v16 + 16i64) << 6);
          *((_QWORD *)v27 + 10) = cull_layer;
          *((_QWORD *)v27 + 18) = simpleHandle_0.mData;
          *((_QWORD *)v27 + 12) = simpleHandleAlpha.mData;
          *((_QWORD *)v27 + 19) = this->mAlphaStateNoColourWriteHandle.mData;
          *((_QWORD *)v27 + 20) = this->mRasterStateInvertCullingHandle.mData;
          *((_QWORD *)v27 + 21) = this->mRasterStateDoubleSidedDisableWriteHandle.mData;
          *((_DWORD *)v27 + 34) = Render::cbLocalProjectionState::sStateParamIndex;
          *((_QWORD *)v27 + 14) = Illusion::gEngine.FrameMemory;
          *((_DWORD *)v27 + 26) = 0;
          *((_DWORD *)v27 + 33) = Illusion::gEngine.mFrameCount;
          *((_DWORD *)v27 + 16) = LODWORD(b[1].v0.x);
          v28 = UFG::qMatrix44::operator*(b - 1, &result, b);
          v29 = v28->v1;
          v30 = v28->v2;
          v31 = v28->v3;
          *(UFG::qVector4 *)v27 = v28->v0;
          *((UFG::qVector4 *)v27 + 1) = v29;
          *((UFG::qVector4 *)v27 + 2) = v30;
          *((UFG::qVector4 *)v27 + 3) = v31;
          v32 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
          v33 = v32;
          if ( v32 )
          {
            *(_QWORD *)v32 = v32;
            *((_QWORD *)v32 + 1) = v32;
            *((_QWORD *)v32 + 2) = v32 + 16;
            *((_QWORD *)v32 + 3) = v32 + 16;
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
            *((_QWORD *)v33 + 6) = v21;
            *((_DWORD *)v33 + 14) = 2;
            *((_QWORD *)v33 + 4) = 0i64;
            *((_QWORD *)v33 + 5) = 0i64;
            *((_QWORD *)v33 + 8) = &gTaskFunctionDeclData_FastShadowDrawTask_SceneDB;
            if ( mSpuElf )
              mAddress = mSpuElf->mAddress;
            else
              mAddress = 0i64;
            *((_QWORD *)v33 + 9) = mAddress;
            *((_QWORD *)v33 + 10) = mTaskFunctionSPU;
            *((_QWORD *)v33 + 11) = mTaskFunctionPPU;
            *((_QWORD *)v33 + 12) = v27;
            *((_QWORD *)v33 + 13) = 0i64;
            *((_QWORD *)v33 + 14) = 0i64;
            *((_QWORD *)v33 + 15) = 0i64;
            if ( mTaskFunctionOffload )
            {
              *((_DWORD *)v33 + 14) = 130;
              *((_DWORD *)v33 + 12) = 0;
            }
          }
          v39 = p_mTasks->mNode.mPrev;
          v39->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v33;
          *(_QWORD *)v33 = v39;
          *((_QWORD *)v33 + 1) = p_mTasks;
          p_mTasks->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v33;
          ++v21->mNumTasks;
          v25 += 32i64;
          --v26;
        }
        while ( v26 );
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v21);
        v18 = v45;
        *v45 = v21;
        task_group_dep = v21;
        v8 = v44;
        v16 = v41;
        p_mProjection = b;
      }
      else
      {
        *v18 = 0i64;
      }
      v41 = ++v16;
      v45 = ++v18;
      v17 = ++v42;
      p_mProjection = (UFG::qMatrix44 *)((char *)p_mProjection + 144);
      b = p_mProjection;
    }
    while ( v16 < *(_DWORD *)(v8 + 1600) );
  }
  return (UFG::SpotShadowRenderQueueTaskResults *)v8;
}

// File Line: 291
// RVA: 0x2B450
UFG::SpotShadowRenderQueueSimResults *__fastcall UFG::RenderStageSpotShadow::RenderSpotShadowsSim(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        CullLayer *simple_drawable_cull_layer,
        CullLayer *composite_cull_layer)
{
  CullLayer *v4; // rdi
  CullLayer *v5; // rsi
  UFG::RenderStageSpotShadow *v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r15
  unsigned int v11; // r14d
  unsigned int mCullIndex; // ebx
  CullManager *v13; // rax
  Illusion::StateArgs *StateArgs; // r12
  UFG::qMatrix44 *p_mProjection; // rbx
  unsigned __int16 Param; // ax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v19; // rbx
  Illusion::StateValues *StateValues; // rax
  CB_WaterOffset *WaterSettings; // rbx
  Illusion::StateValues *v22; // rax
  __int64 v23; // rdx
  __int64 mHead; // rcx
  __int64 v25; // rbx
  unsigned int v26; // edi
  __int64 v27; // rsi
  __int64 v28; // r8
  __int64 v29; // rdx
  float v30; // xmm1_4
  unsigned int LOD; // eax
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // rbx
  unsigned int v35; // edi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  char *v38; // rax
  char *v39; // rbx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  int i; // [rsp+50h] [rbp-B0h]
  Render::cbViewTransformState arg; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v45; // [rsp+B0h] [rbp-50h]
  const char *v46; // [rsp+B8h] [rbp-48h]
  __int64 v47; // [rsp+C0h] [rbp-40h]
  int v48; // [rsp+C8h] [rbp-38h]
  __int64 v49; // [rsp+D0h] [rbp-30h]
  __int64 v50; // [rsp+D8h] [rbp-28h]
  const char *v51; // [rsp+E0h] [rbp-20h]
  __int64 v52; // [rsp+E8h] [rbp-18h]
  int v53; // [rsp+F0h] [rbp-10h]
  __int64 v54; // [rsp+F8h] [rbp-8h]
  char *v55; // [rsp+100h] [rbp+0h]
  Illusion::StateArgs *p_mStateArgs; // [rsp+108h] [rbp+8h]
  __int64 v57[4]; // [rsp+110h] [rbp+10h] BYREF
  Render::View view; // [rsp+130h] [rbp+30h] BYREF
  RenderQueueLayer v59; // [rsp+2C0h] [rbp+1C0h] BYREF
  ShadowSubmitContext ptr; // [rsp+3A0h] [rbp+2A0h] BYREF

  v57[2] = -2i64;
  v4 = composite_cull_layer;
  v5 = simple_drawable_cull_layer;
  v7 = this;
  if ( !gSpotShadowCount )
    return 0i64;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x108u, 8u);
  v55 = v8;
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
  RenderQueueLayer::RenderQueueLayer(&v59);
  ShadowSubmitContext::ShadowSubmitContext(&ptr);
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v59;
  v57[1] = (__int64)v7->mAlphaStateNoColourWriteHandle.mData;
  v57[0] = (__int64)v7->mRasterStateInvertCullingHandle.mData;
  ptr.mPerPhaseParams = (ShadowSubmitContext::PerPhaseParams *)v57;
  v11 = 0;
  for ( i = 0; v11 < *(_DWORD *)v10; v7 = this )
  {
    v59.mSerializationList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)(v10 + 16i64 * v11 + 72);
    Render::View::View(&view, &v7->mSpotShadowViewSettings[v11], &ptr);
    mCullIndex = view.mSettings->mCullIndex;
    v13 = CullManager::Instance();
    CullManager::EndView(v13, mCullIndex);
    Render::View::BeginTarget(&view, render_context->mSingleShadowTarget, "SpotShadowTarget", 0, 0, 0i64, 1, 0, 0, 0);
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
    mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *(float *)v19 = mSimTime_Temp;
    *((float *)v19 + 1) = mSimTimeDelta;
    StateValues = Render::View::GetStateValues(&view);
    StateValues->mSetValueMask.mFlags[0] |= 0x2000ui64;
    StateValues->mParamValues[13] = v19;
    WaterSettings = UFG::Water::GetWaterSettings();
    v22 = Render::View::GetStateValues(&view);
    v22->mSetValueMask.mFlags[0] |= 0x200000000000ui64;
    v22->mParamValues[45] = WaterSettings;
    Illusion::StateArgs::Set<Render::cbViewTransformState>(StateArgs, &arg);
    if ( v4 )
    {
      v23 = view.mSettings->mCullIndex;
      if ( (int)v23 >= 0 && (int)v23 <= 16 && v4->mDrawEnabled )
        mHead = (__int64)v4->mCullResultBuckets[v23].mHead;
      else
        mHead = 0i64;
      v45 = 0i64;
      v46 = "CullResultBucketIterator";
      v25 = mHead;
      v47 = mHead;
      v48 = 0;
      v26 = 0;
      v49 = 0i64;
      if ( mHead )
      {
        do
        {
          v27 = *(_QWORD *)(v25 + 8i64 * v26 + 24);
          if ( (*(_BYTE *)(v27 + 32) & 3) == 1 && !*(_BYTE *)(v27 + 1240) )
          {
            v28 = *(_QWORD *)(v27 + 1256);
            if ( v28 )
            {
              v29 = render_context->mMainViewSettings.mCullIndex;
              if ( (int)v29 > 16 || (int)v29 < 0 || (unsigned __int8)(*(_BYTE *)(v29 + v28) - 4) > 1u )
              {
                if ( (int)v29 >= 6 )
                  v30 = *(float *)&FLOAT_1_0;
                else
                  v30 = *(float *)(v28 + 4 * v29 + 40);
                LOD = UFG::CompositeDrawableComponent::GetLOD(
                        *(UFG::CompositeDrawableComponent **)(v25 + 8i64 * v26 + 24),
                        v30);
                UFG::CompositeDrawableComponent::Draw((UFG::CompositeDrawableComponent *)v27, &view, LOD);
              }
            }
          }
          LODWORD(v49) = ++v26;
          if ( v26 == *(_DWORD *)(v25 + 8) )
          {
            v25 = *(_QWORD *)v25;
            v47 = v25;
            v26 = 0;
            LODWORD(v49) = 0;
          }
        }
        while ( v25 );
        HIDWORD(v49) = 0;
        v5 = simple_drawable_cull_layer;
        v11 = i;
      }
      else
      {
        v11 = i;
      }
    }
    if ( v5 )
    {
      v32 = view.mSettings->mCullIndex;
      if ( (int)v32 >= 0 && (int)v32 <= 16 && v5->mDrawEnabled )
        v33 = (__int64)v5->mCullResultBuckets[v32].mHead;
      else
        v33 = 0i64;
      v50 = 0i64;
      v51 = "CullResultBucketIterator";
      v34 = v33;
      v52 = v33;
      v53 = 0;
      v35 = 0;
      v54 = 0i64;
      if ( v33 )
      {
        do
        {
          Render::SimpleDrawableComponent::Draw(*(Render::SimpleDrawableComponent **)(v34 + 8i64 * v35++ + 24), &view);
          LODWORD(v54) = v35;
          if ( v35 == *(_DWORD *)(v34 + 8) )
          {
            v34 = *(_QWORD *)v34;
            v52 = v34;
            v35 = 0;
            LODWORD(v54) = 0;
          }
        }
        while ( v34 );
        HIDWORD(v54) = 0;
        v11 = i;
      }
      v5 = simple_drawable_cull_layer;
    }
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    RenderQueueLayer::SerializeRenderQueues(&v59);
    v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
    v39 = v38;
    v55 = v38;
    if ( v38 )
    {
      *(_QWORD *)v38 = v38;
      *((_QWORD *)v38 + 1) = v38;
      p_mStateArgs = (Illusion::StateArgs *)(v38 + 16);
      *((_QWORD *)v38 + 2) = v38 + 16;
      *((_QWORD *)v38 + 3) = v38 + 16;
      UFG::qMemSet(v38 + 96, 0, 0x400u);
      *((_QWORD *)v39 + 11) = 0i64;
      *((_QWORD *)v39 + 10) = 0i64;
      *((_DWORD *)v39 + 8) = 0;
      *((_QWORD *)v39 + 5) = 0i64;
      *((_QWORD *)v39 + 6) = 0i64;
      *((_QWORD *)v39 + 7) = 0i64;
      *((_QWORD *)v39 + 8) = 0i64;
      *((_QWORD *)v39 + 9) = 0i64;
    }
    else
    {
      v39 = 0i64;
    }
    *(_QWORD *)(v10 + 8i64 * v11 + 200) = v39;
    *(_QWORD *)(v10 + 8i64 * v11 + 8) = render_context->mSingleShadowTarget;
    v40 = arg.mPrev;
    v41 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v41->mPrev = v40;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    i = ++v11;
    v4 = composite_cull_layer;
  }
  FastShadowDraw_Dynamic(
    v7->mSpotShadowViewSettings,
    render_context->mMainViewSettings.mCullIndex,
    (Illusion::RenderQueue **)(v10 + 200),
    *(_DWORD *)v10);
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v59);
  return (UFG::SpotShadowRenderQueueSimResults *)v10;
}

// File Line: 388
// RVA: 0x2AF70
void __fastcall UFG::RenderStageSpotShadow::DownsampleShadows_Spotlight(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  _WORD *v6; // rbx
  unsigned int mUID; // r8d
  Illusion::Material *mMatDepthDownsampleSpotShadow; // rdi
  __int64 mOffset; // rax
  RenderQueueLayer v10; // [rsp+60h] [rbp-EF8h] BYREF
  Render::View v11; // [rsp+140h] [rbp-E18h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h] BYREF
  Render::Poly poly; // [rsp+F60h] [rbp+8h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+F68h] [rbp+10h]

  RenderQueueLayer::RenderQueueLayer(&v10);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v10.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v10;
  v6 = 0i64;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&v11, &render_context->mMainViewSettings, &ptr);
  Render::View::BeginTarget(&v11, render_context->mHalfSizeSingleShadowTarget, "SpotShadow", 0, 0, 0i64, 1, 0, 0, 0);
  Render::View::Clear(&v11, &UFG::qColour::Black, 6u, 1.0, 0);
  mUID = render_context->mSingleShadowTextureAliasDepth->mNode.mUID;
  mMatDepthDownsampleSpotShadow = this->mMatDepthDownsampleSpotShadow;
  if ( LODWORD(mMatDepthDownsampleSpotShadow[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMatDepthDownsampleSpotShadow[1].mDebugName[20],
      mMatDepthDownsampleSpotShadow[1].mStateBlockMask.mFlags[1],
      mUID);
    mOffset = mMatDepthDownsampleSpotShadow->mMaterialUser.mOffset;
    if ( mOffset )
      v6 = (_WORD *)((char *)&mMatDepthDownsampleSpotShadow->mMaterialUser + mOffset);
    *v6 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(&v11, &poly, this->mMatDepthDownsampleSpotShadow, 0i64);
  Render::View::EndTarget(&v11);
  RenderQueueLayer::SerializeRenderQueues(&v10);
  p_mStateArgs = &ptr.mStateArgs;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v10);
}

// File Line: 418
// RVA: 0x2BAC0
void __fastcall UFG::RenderStageSpotShadow::RenderSpotlightLightShafts(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Render::Light *lightShaftLight,
        Render::LightInstance *lightShaftLightInstance)
{
  float fFar; // xmm6_4
  float fAspectRatio; // xmm1_4
  float mShadowNear; // xmm3_4
  float mFovHalfInner; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float w; // xmm7_4
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
  Illusion::StateArgs *StateArgs; // rsi
  Render::ViewSettings *mSettings; // rdi
  unsigned __int16 Param; // ax
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  float mTexDistAttenV; // xmm0_4
  Render::ViewSettings *v39; // rdi
  UFG::qMatrix44 *p_mProjection; // r12
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
  Illusion::Material *mLightShaftSpotLightMaterial; // r15
  unsigned int mUID; // r8d
  __int64 mOffset; // rax
  _WORD *v99; // rax
  unsigned int mTextureUID; // eax
  Illusion::Material *v101; // rbx
  __int64 v102; // rax
  _WORD *v103; // rax
  Illusion::Material *v104; // rbx
  __int64 v105; // rax
  _WORD *v106; // rax
  Illusion::Material *v107; // rbx
  __int64 v108; // rax
  _WORD *v109; // rax
  Illusion::StateValues *StateValues; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v113; // rbx
  Illusion::StateValues *v114; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v117; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v118; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v119; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v120; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v121; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v122; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v123; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v124; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v125; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v126; // rax
  Render::cbExternalViewTransformState v127; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbDeferredLightState arg; // [rsp+90h] [rbp-70h] BYREF
  Render::cbShadowTransformState v129; // [rsp+100h] [rbp+0h] BYREF
  UFG::qMatrix44 local_world; // [rsp+160h] [rbp+60h] BYREF
  UFG::qMatrix44 v131; // [rsp+1A0h] [rbp+A0h] BYREF
  __int64 v132; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 shadowProjection; // [rsp+1F0h] [rbp+F0h] BYREF
  UFG::qMatrix44 shadowWorldView; // [rsp+230h] [rbp+130h] BYREF
  Render::View v135; // [rsp+270h] [rbp+170h] BYREF
  RenderQueueLayer v136; // [rsp+400h] [rbp+300h] BYREF
  UFG::qMatrix44 result; // [rsp+4E0h] [rbp+3E0h] BYREF
  LayerSubmitContext ptr; // [rsp+520h] [rbp+420h] BYREF
  float v139; // [rsp+1270h] [rbp+1170h]
  float v140; // [rsp+1290h] [rbp+1190h]

  v132 = -2i64;
  fFar = lightShaftLight->mDecayRadius * lightShaftLightInstance->radScale;
  v139 = fFar;
  fAspectRatio = *(float *)&FLOAT_1_0;
  mShadowNear = lightShaftLight->mShadowNear;
  if ( lightShaftLight->mType == 5 )
  {
    if ( mShadowNear <= (float)(lightShaftLight->mAreaLightNearOffset * 0.5) )
      mShadowNear = lightShaftLight->mAreaLightNearOffset * 0.5;
    fAspectRatio = lightShaftLight->mAreaLightWidth / lightShaftLight->mAreaLightHeight;
    mFovHalfInner = lightShaftLight->mFovHalfInner;
  }
  else
  {
    mFovHalfInner = lightShaftLight->mFovHalfOuter;
  }
  Render::BuildShadowSpotView(
    &shadowWorldView,
    &shadowProjection,
    &lightShaftLight->mTransform,
    mShadowNear,
    fFar,
    mFovHalfInner * 2.0,
    fAspectRatio);
  if ( (lightShaftLightInstance->flags & 2) != 0 )
    UFG::RenderStageSpotShadow::DownsampleShadows_Spotlight(this, render_context, serialization_list);
  v140 = tanf(lightShaftLight->mFovHalfOuter) * fFar;
  x = lightShaftLight->mTransform.v0.x;
  y = lightShaftLight->mTransform.v0.y;
  z = lightShaftLight->mTransform.v0.z;
  w = lightShaftLight->mTransform.v0.w;
  v18 = lightShaftLight->mTransform.v1.x;
  v19 = lightShaftLight->mTransform.v1.y;
  v20 = lightShaftLight->mTransform.v1.z;
  v21 = lightShaftLight->mTransform.v1.w;
  v22 = lightShaftLight->mTransform.v2.x;
  v23 = lightShaftLight->mTransform.v2.y;
  v24 = lightShaftLight->mTransform.v2.z;
  v25 = lightShaftLight->mTransform.v2.w;
  v26 = lightShaftLight->mTransform.v3.y;
  v27 = lightShaftLight->mTransform.v3.z;
  v28 = lightShaftLight->mTransform.v3.w;
  local_world.v3.x = lightShaftLight->mTransform.v3.x;
  local_world.v3.y = v26;
  local_world.v3.z = v27;
  local_world.v3.w = v28;
  local_world.v0.x = x * v140;
  local_world.v0.y = y * v140;
  local_world.v0.z = z * v140;
  local_world.v0.w = w * v140;
  local_world.v1.x = v18 * v140;
  local_world.v1.y = v19 * v140;
  local_world.v1.z = v20 * v140;
  local_world.v1.w = v21 * v140;
  local_world.v2.x = v22 * v139;
  local_world.v2.y = v23 * v139;
  local_world.v2.z = v24 * v139;
  local_world.v2.w = v25 * v139;
  RenderQueueLayer::RenderQueueLayer(&v136);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v136.mSerializationList = serialization_list;
  ptr.mRenderQueueProvider = &v136;
  ptr.mQueueMode = QM_Single;
  Render::View::View(&v135, &render_context->mMainViewSettings, &ptr);
  StateArgs = Render::View::GetStateArgs(&v135);
  Render::View::BeginTarget(
    &v135,
    render_context->mQuarterSizeVolumetricTarget,
    "LightShaftSpotlight",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  mSettings = v135.mSettings;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbDeferredLightState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
    Render::cbDeferredLightState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldView = &mSettings->mWorldView;
  v32 = lightShaftLightInstance->colorFade * lightShaftLight->mColor.z;
  v33 = lightShaftLightInstance->colorFade * lightShaftLight->mColor.y;
  v34 = lightShaftLightInstance->colorFade * lightShaftLight->mColor.x;
  arg.mColor.x = v34 * v34;
  arg.mColor.y = v33 * v33;
  arg.mColor.z = v32 * v32;
  v35 = lightShaftLight->mTransform.v3.y;
  v36 = lightShaftLight->mTransform.v3.z;
  arg.mPosition.x = lightShaftLight->mTransform.v3.x;
  arg.mPosition.y = v35;
  arg.mPosition.z = v36;
  arg.mDecayRadius = v139;
  arg.mDecayPower = lightShaftLight->mDecayPower;
  arg.mShadowFade = lightShaftLightInstance->shadowFade;
  v37 = cosf(lightShaftLight->mFovHalfOuter);
  arg.mFovInner = cosf(lightShaftLight->mFovHalfInner);
  arg.mFovOuter = v37;
  if ( lightShaftLight->mTexDistAttenUID == -1 )
    mTexDistAttenV = FLOAT_N1_0;
  else
    mTexDistAttenV = lightShaftLight->mTexDistAttenV;
  arg.mTexDistAttenV = mTexDistAttenV;
  Illusion::StateArgs::Set<Render::cbDeferredLightState>(StateArgs, &arg);
  v39 = v135.mSettings;
  p_mProjection = &v135.mSettings->mProjection;
  v127.mPrev = &v127;
  v127.mNext = &v127;
  v127.mCallback = 0i64;
  v127.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v127.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    v41 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v41;
    v127.mStateParamIndex = v41;
  }
  v127.mWorldView = &v39->mWorldView;
  v127.mProjection = p_mProjection;
  v127.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &v127);
  v129.mPrev = &v129;
  v129.mNext = &v129;
  v129.mCallback = 0i64;
  v129.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v129.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v42 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v42;
    v129.mStateParamIndex = v42;
  }
  v129.mViewWorld = &v135.mViewWorld;
  v129.mWorldView = &shadowWorldView;
  v129.mProjection = &shadowProjection;
  memset(&v129.mCutplanes, 0, 32);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v129);
  v43 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x80u);
  v44 = UFG::qMatrix44::operator*(&v135.mViewWorld, &result, &shadowWorldView);
  UFG::qMatrix44::operator*(v44, &v131, &shadowProjection);
  v45 = v131.v3.x;
  v46 = v131.v3.w;
  v47 = v131.v3.x + v131.v3.w;
  v48 = v131.v2.x;
  v49 = v131.v2.w;
  v50 = v131.v2.x + v131.v2.w;
  v51 = v131.v1.x;
  v52 = v131.v1.w;
  v53 = v131.v1.x + v131.v1.w;
  v54 = v131.v0.x;
  v55 = v131.v0.w;
  *v43 = v131.v0.x + v131.v0.w;
  v43[1] = v53;
  v43[2] = v50;
  v43[3] = v47;
  v43[4] = v55 - v54;
  v43[5] = v52 - v51;
  v43[6] = v49 - v48;
  v43[7] = v46 - v45;
  v56 = v131.v3.y;
  v57 = v46 - v131.v3.y;
  v58 = v131.v2.y;
  v59 = v49 - v131.v2.y;
  v60 = v131.v1.y;
  v61 = v52 - v131.v1.y;
  v62 = v131.v0.y;
  v43[8] = v55 - v131.v0.y;
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
  v67 = _mm_sqrt_ps(v66).m128_f32[0];
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
  v73 = _mm_sqrt_ps(v72).m128_f32[0];
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
  v79 = _mm_sqrt_ps(v78).m128_f32[0];
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
  v84 = _mm_sqrt_ps(v83).m128_f32[0];
  v85 = (float)(1.0 / v84) * v43[15];
  v43[12] = v76.m128_f32[0] * (float)(1.0 / v84);
  v43[13] = v81.m128_f32[0] * (float)(1.0 / v84);
  v43[14] = v82 * (float)(1.0 / v84);
  v43[15] = v85;
  LODWORD(v86) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(lightShaftLight->mTransform.v3.y * v135.mSettings->mWorldView.v1.x)
                                 + (float)(lightShaftLight->mTransform.v3.x * v135.mSettings->mWorldView.v0.x))
                         + (float)(lightShaftLight->mTransform.v3.z * v135.mSettings->mWorldView.v2.x))
                 + v135.mSettings->mWorldView.v3.x) ^ _xmm[0];
  LODWORD(v87) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(lightShaftLight->mTransform.v3.y * v135.mSettings->mWorldView.v1.y)
                                 + (float)(lightShaftLight->mTransform.v3.x * v135.mSettings->mWorldView.v0.y))
                         + (float)(lightShaftLight->mTransform.v3.z * v135.mSettings->mWorldView.v2.y))
                 + v135.mSettings->mWorldView.v3.y) ^ _xmm[0];
  LODWORD(v88) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(lightShaftLight->mTransform.v3.y * v135.mSettings->mWorldView.v1.z)
                                 + (float)(lightShaftLight->mTransform.v3.x * v135.mSettings->mWorldView.v0.z))
                         + (float)(lightShaftLight->mTransform.v3.z * v135.mSettings->mWorldView.v2.z))
                 + v135.mSettings->mWorldView.v3.z) ^ _xmm[0];
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
  v95 = (lightShaftLightInstance->flags & 2) == 0;
  mLightShaftSpotLightMaterial = render_context->mLightShaftSpotLightMaterial;
  if ( v95 )
  {
    if ( LODWORD(mLightShaftSpotLightMaterial[3].mNode.mChild[0]) == -1324127765 )
      goto LABEL_37;
    mUID = -1324127765;
  }
  else
  {
    mUID = render_context->mHalfSizeSingleShadowAliasTexture->mNode.mUID;
    if ( LODWORD(mLightShaftSpotLightMaterial[3].mNode.mChild[0]) == mUID )
      goto LABEL_37;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&mLightShaftSpotLightMaterial[2].mNumParams,
    (unsigned int)mLightShaftSpotLightMaterial[3].mNode.mChild[1],
    mUID);
  mOffset = mLightShaftSpotLightMaterial->mMaterialUser.mOffset;
  if ( mOffset )
    v99 = (_WORD *)((char *)&mLightShaftSpotLightMaterial->mMaterialUser + mOffset);
  else
    v99 = 0i64;
  *v99 |= 0x20u;
LABEL_37:
  mTextureUID = lightShaftLight->mTextureUID;
  if ( mTextureUID == -1 )
    mTextureUID = UFG::qStringHashUpper32("LS_SPOT", 0xFFFFFFFF);
  v101 = render_context->mLightShaftSpotLightMaterial;
  if ( *(_DWORD *)&v101[3].mDebugName[12] != mTextureUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v101[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
      *(_DWORD *)&v101[3].mDebugName[20],
      mTextureUID);
    v102 = v101->mMaterialUser.mOffset;
    if ( v102 )
      v103 = (_WORD *)((char *)&v101->mMaterialUser + v102);
    else
      v103 = 0i64;
    *v103 |= 0x20u;
  }
  v104 = render_context->mLightShaftSpotLightMaterial;
  if ( v104[2].mNode.mUID != -89056095 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v104[2],
      (unsigned int)v104[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0xFAB11CA1);
    v105 = v104->mMaterialUser.mOffset;
    if ( v105 )
      v106 = (_WORD *)((char *)&v104->mMaterialUser + v105);
    else
      v106 = 0i64;
    *v106 |= 0x20u;
  }
  v107 = render_context->mLightShaftSpotLightMaterial;
  if ( *(_DWORD *)&v107[2].mDebugName[28] != -652645828 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v107[2].mDebugName[4],
      *((_DWORD *)&v107[2].UFG::qResourceData + 22),
      0xD9196A3C);
    v108 = v107->mMaterialUser.mOffset;
    if ( v108 )
      v109 = (_WORD *)((char *)&v107->mMaterialUser + v108);
    else
      v109 = 0i64;
    *v109 |= 0x20u;
  }
  StateValues = Render::View::GetStateValues(&v135);
  StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
  StateValues->mParamValues[15] = v43;
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v113 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v113 = mSimTime_Temp;
  *((float *)v113 + 1) = mSimTimeDelta;
  v114 = Render::View::GetStateValues(&v135);
  v114->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v114->mParamValues[13] = v113;
  Render::View::Draw(&v135, &gDeferredCone, &local_world, 0, render_context->mLightShaftSpotLightMaterial);
  mPrev = v127.mPrev;
  mNext = v127.mNext;
  v127.mPrev->mNext = v127.mNext;
  mNext->mPrev = mPrev;
  v127.mPrev = &v127;
  v127.mNext = &v127;
  v127.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v127.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v127.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v127.mStateParamIndex >> 6] &= ~(1i64 << (v127.mStateParamIndex & 0x3F));
  v117 = v129.mPrev;
  v118 = v129.mNext;
  v129.mPrev->mNext = v129.mNext;
  v118->mPrev = v117;
  v129.mPrev = &v129;
  v129.mNext = &v129;
  v129.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v129.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v129.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v129.mStateParamIndex >> 6] &= ~(1i64 << (v129.mStateParamIndex & 0x3F));
  v119 = arg.mPrev;
  v120 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v120->mPrev = v119;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&v135);
  this->mRenderedSpotlightLightShaft = 1;
  v121 = v129.mPrev;
  v122 = v129.mNext;
  v129.mPrev->mNext = v129.mNext;
  v122->mPrev = v121;
  v129.mPrev = &v129;
  v129.mNext = &v129;
  v123 = v127.mPrev;
  v124 = v127.mNext;
  v127.mPrev->mNext = v127.mNext;
  v124->mPrev = v123;
  v127.mPrev = &v127;
  v127.mNext = &v127;
  v125 = arg.mPrev;
  v126 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v126->mPrev = v125;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v136);
} v123 = v127.mPrev;
  v124 = v127.mNext;
  v127.mPrev->m

// File Line: 607
// RVA: 0x2B2C0
void __fastcall UFG::RenderStageSpotShadow::RenderBeforeSunShadows(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  RenderQueueLayer v6; // [rsp+60h] [rbp-EF8h] BYREF
  Render::View v7; // [rsp+140h] [rbp-E18h] BYREF
  LayerSubmitContext ptr; // [rsp+2D0h] [rbp-C88h] BYREF

  RenderQueueLayer::RenderQueueLayer(&v6);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v6.mSerializationList = serialization_list;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v6;
  Render::View::View(&v7, &render_context->mMainViewSettings, &ptr);
  Render::View::BeginTarget(
    &v7,
    render_context->mQuarterSizeVolumetricTarget,
    "VolumetricTargetClear",
    0,
    0,
    0i64,
    1,
    0,
    0,
    0);
  Render::View::Clear(&v7, &UFG::qColour::Zero, 1u, 1.0, 0);
  Render::View::EndTarget(&v7);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v6);
  this->mRenderedSpotlightLightShaft = 0;
}

// File Line: 633
// RVA: 0x2B3F0
void __fastcall UFG::RenderStageSpotShadow::RenderDebugSpotShadowOverlay(
        UFG::RenderStageSpotShadow *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        int x,
        int y,
        int size)
{
  Illusion::Texture *mDepthTexture; // rcx
  UFG::qColour v7; // [rsp+40h] [rbp-18h] BYREF

  mDepthTexture = render_context->mSingleShadowTarget->mDepthTexture;
  v7 = UFG::qColour::White;
  Render::View::DrawIcon(view, mDepthTexture->mNode.mUID, x, y, size, size, &v7, 0xA3833FDE);
}

