// File Line: 77
// RVA: 0x31720
void __fastcall UFG::RenderStageEnvMap::Create(UFG::RenderContext *render_context)
{
  UFG::RenderStageEnvMap *v2; // rax

  v2 = (UFG::RenderStageEnvMap *)UFG::qMalloc(0x48ui64, "RenderStageEnvMap", 0i64);
  if ( v2 )
    UFG::RenderStageEnvMap::RenderStageEnvMap(v2, render_context);
}

// File Line: 86
// RVA: 0x31540
void __fastcall UFG::RenderStageEnvMap::RenderStageEnvMap(
        UFG::RenderStageEnvMap *this,
        UFG::RenderContext *render_context)
{
  Illusion::TextureHandle *p_mEnvMapTextureHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  p_mEnvMapTextureHandle = &this->mEnvMapTextureHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mEnvMapTextureHandle);
  this->mEnvMapBlend = 0.0;
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mEnvMapTextureHandle, 0x8B43FABF, 0xC0C0C0C0, Inventory);
  this->mCustomEnvMapCellIndex = -1;
  *(_WORD *)&this->mRenderEnvMap = 1;
  this->mEnvMapSliceCount = 0;
  this->mDrawDebugEnvMap = 0;
  this->mEnvMapAmbientScale = 0.5;
  this->mEnvMapDiffuseScale = 0.1;
  this->mEnvMapSkySaturation = 1.0;
  this->mInteriorBlend = 0.0;
}

// File Line: 120
// RVA: 0x31F10
void __fastcall UFG::RenderEnvCubeMapView(
        Render::View *view,
        UFG::SceneryGroupComponent **user_data1,
        _QWORD *user_data2)
{
  Illusion::SubmitContext *mSubmitContext; // r15
  __int64 v7; // rbx
  Render::ViewSettings *mSettings; // r12
  char *v9; // rax
  UFG::qVector4 *v10; // r14
  _OWORD *v11; // rdx
  char *v12; // r8
  UFG::TimeOfDayManager *Instance; // rax
  char *v14; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::StateValues *v16; // rax
  void *v17; // rbx
  Illusion::StateValues *v18; // rax
  float mSimTimeDelta; // xmm7_4
  float mSimTime_Temp; // xmm6_4
  char *v21; // rbx
  Illusion::StateValues *v22; // rax
  __int64 v23; // rbx
  UFG::qResourceData *mData; // rbx
  Illusion::StateValues *v25; // rax
  unsigned int v26; // eax
  unsigned __int16 v27; // bx
  void *v28; // r12
  Illusion::StateValues *v29; // rax
  unsigned __int16 Param; // ax
  Illusion::StateArgs *StateArgs; // rax
  UFG::TimeOfDayManager *v32; // rax
  Illusion::Texture *FogTexture; // rbx
  Illusion::StateValues *v34; // rax
  void *v35; // rbx
  Illusion::StateValues *v36; // rax
  Illusion::StateArgs *v37; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  __int64 v42; // [rsp+8h] [rbp-61h] BYREF
  unsigned int stencil; // [rsp+28h] [rbp-41h]
  Render::cbExternalViewTransformState arg; // [rsp+30h] [rbp-39h] BYREF
  float distance_from_near_plane[2]; // [rsp+D0h] [rbp+67h] BYREF
  Render::ViewSettings *v46; // [rsp+D8h] [rbp+6Fh]

  mSubmitContext = view->mSubmitContext;
  v7 = 2i64;
  LODWORD(mSubmitContext[1].mStateValues.mSetValueMask.mFlags[1]) = 2;
  mSettings = view->mSettings;
  v46 = view->mSettings;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
  v10 = (UFG::qVector4 *)v9;
  v11 = (_OWORD *)*user_data2;
  v12 = v9;
  if ( (((unsigned __int8)v9 | (unsigned __int8)*user_data2) & 0xF) != 0 )
  {
    memmove(v9, v11, 0x100ui64);
  }
  else
  {
    do
    {
      *(_OWORD *)v12 = *v11;
      *((_OWORD *)v12 + 1) = v11[1];
      *((_OWORD *)v12 + 2) = v11[2];
      *((_OWORD *)v12 + 3) = v11[3];
      *((_OWORD *)v12 + 4) = v11[4];
      *((_OWORD *)v12 + 5) = v11[5];
      *((_OWORD *)v12 + 6) = v11[6];
      v12 += 128;
      *((_OWORD *)v12 - 1) = v11[7];
      v11 += 8;
      --v7;
    }
    while ( v7 );
  }
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetViewSpaceSunDir(Instance, v10, mSettings);
  stencil = 0;
  mSubmitContext->mShaderSelector = (Illusion::ShaderSelector *)&v42;
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(_QWORD *)v14 = 0i64;
  *((_DWORD *)v14 + 2) = 0;
  *((_DWORD *)v14 + 3) = 1065353216;
  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x100000000ui64;
  StateValues->mParamValues[32] = v14;
  v16 = Render::View::GetStateValues(view);
  v16->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v16->mParamValues[55] = v10;
  v17 = *(void **)(user_data2[3] + 552i64);
  v18 = Render::View::GetStateValues(view);
  v18->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v18->mParamValues[61] = v17;
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v21 = mSimTime_Temp;
  *((float *)v21 + 1) = mSimTimeDelta;
  v22 = Render::View::GetStateValues(view);
  v22->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v22->mParamValues[13] = v21;
  v23 = *(_QWORD *)(user_data2[3] + 88i64);
  if ( v23 )
    mData = *(UFG::qResourceData **)(v23 + 24);
  else
    mData = gDefaultBlackTexture.mData;
  v25 = Render::View::GetStateValues(view);
  v25->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
  v25->mParamValues[58] = mData;
  if ( (_S1_7 & 1) != 0 )
  {
    v27 = skySettingsIndex;
  }
  else
  {
    _S1_7 |= 1u;
    v26 = UFG::qStringHash32("cbSkySettings", 0xFFFFFFFF);
    v27 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v26, "cbSkySettings", 0);
    skySettingsIndex = v27;
  }
  v28 = (void *)user_data2[1];
  v29 = Render::View::GetStateValues(view);
  if ( (unsigned int)(__int16)v27 >= 0x40 )
    v29->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v27 - 64);
  else
    v29->mSetValueMask.mFlags[0] |= 1i64 << v27;
  v29->mParamValues[(__int16)v27] = v28;
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
  arg.mWorldView = &v46->mWorldView;
  arg.mProjection = &v46->mProjection;
  arg.mCached_Remote.m_Stream = 0i64;
  StateArgs = Render::View::GetStateArgs(view);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  Render::View::Clear(view, &UFG::qColour::Black, 6u, 1.0, 0);
  v32 = UFG::TimeOfDayManager::GetInstance();
  FogTexture = UFG::TimeOfDayManager::GetFogTexture(v32);
  v34 = Render::View::GetStateValues(view);
  v34->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  v34->mParamValues[41] = FogTexture;
  distance_from_near_plane[1] = FLOAT_10_0;
  mSubmitContext[1].vfptr = (Illusion::SubmitContextVtbl *)distance_from_near_plane;
  for ( mSubmitContext[1].mStateValues.mSetValueMask.mFlags[0] = 0i64; *user_data1; ++user_data1 )
  {
    if ( Render::View::IsInView(
           view,
           &(*user_data1)->mSceneryGroup->mAABBMin,
           &(*user_data1)->mSceneryGroup->mAABBMax,
           distance_from_near_plane) )
    {
      UFG::SceneryGroupComponent::Draw(*user_data1, view);
    }
  }
  v35 = (void *)user_data2[2];
  v36 = Render::View::GetStateValues(view);
  v36->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v36->mParamValues[55] = v35;
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)mSubmitContext[1].mStateValues.mParamValues[0]);
  RenderQueueLayer::SerializeDeferredAlpha((RenderQueueLayer *)mSubmitContext[1].mStateValues.mParamValues[0]);
  LODWORD(mSubmitContext[1].mStateValues.mSetValueMask.mFlags[1]) = 1;
  Render::SkyMarshall::RenderFar(&Render::SkyMarshall::gSkyMarshall, view, 0.16666667);
  Render::SkyMarshall::RenderCloudDome(&Render::SkyMarshall::gSkyMarshall, view, 0.16666667);
  Render::FlareManager::Render(&Render::gFlareManager, view, 0.0, FLAREQUEUE_FORWARD_LOW_QUALITY, 1u);
  v37 = Render::View::GetStateArgs(view);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v37->mStateArgs[arg.mStateParamIndex].mNode.mNext == &v37->mStateArgs[arg.mStateParamIndex] )
    v37->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  mSubmitContext->mShaderSelector = 0i64;
  v40 = arg.mPrev;
  v41 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v41->mPrev = v40;
}

// File Line: 202
// RVA: 0x31770
__int64 __fastcall UFG::GetEnvMapSceneryGroups(
        Render::ViewSettings *main_view_settings,
        UFG::SceneryGroupComponent **components)
{
  UFG::SceneryGroupComponent *p_mNext; // rdi
  unsigned int v4; // esi
  UFG::SceneryGroup *mSceneryGroup; // rax
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *v6; // rbp
  UFG::SceneryGroup *v7; // rax
  float y; // xmm1_4
  float x; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::qVector3 vmin; // [rsp+20h] [rbp-1C8h] BYREF
  UFG::qVector3 vmax; // [rsp+30h] [rbp-1B8h] BYREF
  Render::View v15; // [rsp+40h] [rbp-1A8h] BYREF
  float distance_from_near_plane; // [rsp+200h] [rbp+18h] BYREF
  int v17; // [rsp+204h] [rbp+1Ch]

  Render::View::View(&v15, main_view_settings, 0i64);
  p_mNext = (UFG::SceneryGroupComponent *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  v4 = 0;
  if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
  {
    do
    {
      mSceneryGroup = p_mNext->mSceneryGroup;
      v6 = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&p_mNext->mNext[-6].mNext;
      if ( (mSceneryGroup->mFlags & 1) == 0 && mSceneryGroup->mSceneryLayer == 1 )
      {
        if ( UFG::SectionChooser::IsSectionVisible_VisIndex(mSceneryGroup->mSectionVisIndex, SCENERY_LAYER_STD, 0) )
          goto LABEL_6;
        v7 = p_mNext->mSceneryGroup;
        v17 = 1092616192;
        y = v7->mAABBMin.y;
        x = v7->mAABBMin.x;
        vmin.z = v7->mAABBMin.z;
        vmin.x = x;
        vmin.y = y;
        v10 = v7->mAABBMax.y;
        v11 = v7->mAABBMax.x;
        vmin.z = -1000.0;
        vmax.z = 1000.0;
        vmax.x = v11;
        vmax.y = v10;
        if ( Render::View::IsInView(&v15, &vmin, &vmax, &distance_from_near_plane) )
        {
LABEL_6:
          ++v4;
          *components++ = p_mNext;
        }
      }
      p_mNext = (UFG::SceneryGroupComponent *)v6;
    }
    while ( v6 != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList
                                                                                          - 88) );
  }
  return v4;
}

// File Line: 245
// RVA: 0x31960
void __fastcall UFG::RenderStageEnvMap::Render(
        UFG::RenderStageEnvMap *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qResourceData *mData; // r14
  unsigned int v7; // ebx
  Render::ViewSettings *Identity; // rax
  float mEnvMapBlend; // xmm0_4
  CB_EnvironmentSettings *v10; // rbx
  float mEnvMapSkySaturation; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  bool v13; // cl
  unsigned int v14; // ecx
  UFG::qColour colour; // [rsp+50h] [rbp-B0h] BYREF
  int v16; // [rsp+60h] [rbp-A0h]
  int v17; // [rsp+64h] [rbp-9Ch]
  __int64 user_data2[4]; // [rsp+68h] [rbp-98h] BYREF
  __int64 v19[3]; // [rsp+88h] [rbp-78h] BYREF
  Render::View user_data1; // [rsp+A0h] [rbp-60h] BYREF
  RenderQueueLayer v21; // [rsp+2A0h] [rbp+1A0h] BYREF
  ForwardEnvMapSubmitContext ptr; // [rsp+380h] [rbp+280h] BYREF
  Render::Poly poly; // [rsp+1048h] [rbp+F48h] BYREF

  v19[2] = -2i64;
  if ( render_context->mRenderFeatures.mWorld && this->mRenderEnvMap && render_context->mEnvCubeMap )
  {
    RenderQueueLayer::RenderQueueLayer(&v21);
    ForwardEnvMapSubmitContext::ForwardEnvMapSubmitContext(&ptr);
    v21.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v21;
    v19[1] = (__int64)AlphaStateNoneHandle.mData;
    v19[0] = (__int64)RasterStateNormalHandle.mData;
    ptr.mPerPhaseParams = (ForwardEnvMapSubmitContext::PerPhaseParams *)v19;
    mData = 0i64;
    if ( !UFG::qResourceHandle::IsDefault(&this->mEnvMapTextureHandle) )
      mData = this->mEnvMapTextureHandle.mData;
    if ( mData && gEnableCustomEnvMaps )
    {
      ptr.mQueueMode = QM_Default;
      v7 = 662883558;
      if ( this->mEnvMapBlend < 1.0 )
        v7 = -1551679522;
      Identity = Render::ViewSettings::GetIdentity();
      Render::View::View(&user_data1, Identity, &ptr);
      Render::View::BeginTarget(
        &user_data1,
        render_context->mSphericalEnvMapTarget,
        "SphericalMap_Blend",
        0,
        0,
        0i64,
        1,
        0,
        0,
        0);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 0, 0x8B5561A1, 0x3141335Cu);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 1, 0x8B43FABF, mData->mNode.mUID);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 2, 0x12C800F2u, v7);
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      mEnvMapBlend = this->mEnvMapBlend;
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 1.0;
      colour.a = mEnvMapBlend;
      Render::Poly::SetColour(&poly, &colour);
      Render::View::Draw(&user_data1, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      Render::View::EndTarget(&user_data1);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 2, 0x12C800F2u, 0x2782CCE6u);
    }
    else
    {
      *((_QWORD *)&user_data1.mSettings
      + (unsigned int)UFG::GetEnvMapSceneryGroups(
                        &render_context->mMainViewSettings,
                        (UFG::SceneryGroupComponent **)&user_data1)) = 0i64;
      v10 = (CB_EnvironmentSettings *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
      mEnvMapSkySaturation = this->mEnvMapSkySaturation;
      UFG::TimeOfDayManager::GetInstance()->mSkySaturation = mEnvMapSkySaturation;
      Instance = UFG::TimeOfDayManager::GetInstance();
      UFG::TimeOfDayManager::GetEnvironmentSettings(Instance, v10, 0i64, 0i64);
      v10->AmbientColorHorizon[0] = this->mEnvMapAmbientScale * v10->AmbientColorHorizon[0];
      v10->AmbientColorHorizon[1] = this->mEnvMapAmbientScale * v10->AmbientColorHorizon[1];
      v10->AmbientColorHorizon[2] = this->mEnvMapAmbientScale * v10->AmbientColorHorizon[2];
      v10->SunColor[0] = v10->SunColor[0] * this->mEnvMapDiffuseScale;
      v10->SunColor[1] = this->mEnvMapDiffuseScale * v10->SunColor[1];
      v10->SunColor[2] = this->mEnvMapDiffuseScale * v10->SunColor[2];
      v13 = !this->mTimeSliceRenderEnvMap || UFG::RenderWorld::msIsNisPlaying;
      user_data2[0] = (__int64)v10;
      user_data2[1] = (__int64)render_context->mSkyState;
      user_data2[2] = (__int64)render_context->mEnvState;
      user_data2[3] = (__int64)render_context;
      if ( v13 )
      {
        Render::EnvCubeMap::Render(
          render_context->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          0xFFFFFFFF,
          &ptr,
          &user_data1,
          user_data2);
        Render::EnvCubeMap::RenderSphericalMap(
          render_context->mEnvCubeMap,
          render_context->mSphericalEnvMapTarget,
          &ptr,
          this->mEnvMapBlend);
      }
      else
      {
        colour.r = 0.0;
        LODWORD(colour.g) = 1;
        LODWORD(colour.b) = 5;
        LODWORD(colour.a) = 2;
        v16 = 3;
        v17 = 4;
        Render::EnvCubeMap::Render(
          render_context->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + this->mEnvMapSliceCount),
          &ptr,
          &user_data1,
          user_data2);
        Render::EnvCubeMap::Render(
          render_context->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + this->mEnvMapSliceCount + 1),
          &ptr,
          &user_data1,
          user_data2);
        Render::EnvCubeMap::Render(
          render_context->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + this->mEnvMapSliceCount + 2),
          &ptr,
          &user_data1,
          user_data2);
        v14 = (this->mEnvMapSliceCount + 3) % 6;
        this->mEnvMapSliceCount = v14;
        if ( v14 )
        {
LABEL_20:
          UFG::TimeOfDayManager::GetInstance()->mSkySaturation = 1.0;
          poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
          `eh vector destructor iterator(
            ptr.mStateArgs.mStateArgs,
            0x10ui64,
            128,
            (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
          RenderQueueLayer::~RenderQueueLayer(&v21);
          return;
        }
        Render::EnvCubeMap::RenderSphericalMap(
          render_context->mEnvCubeMap,
          render_context->mSphericalEnvMapTarget,
          &ptr,
          this->mEnvMapBlend);
        this->mEnvMapSliceCount = 0;
      }
    }
    ptr.mQueueMode = QM_Default;
    Render::gRenderUtilities.mSubmitContext = &ptr;
    Render::RenderUtilities::RenderMips(
      &Render::gRenderUtilities,
      render_context->mSphericalEnvMapTarget,
      7,
      0xC532D4Bu);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    goto LABEL_20;
  }
}

// File Line: 368
// RVA: 0x32420
void __fastcall UFG::RenderStageEnvMap::UpdateViews(
        UFG::RenderStageEnvMap *this,
        UFG::RenderContext *render_context,
        float fRealTimeDelta)
{
  float v5; // xmm6_4
  float mEnvMapBlend; // xmm1_4
  float v7; // xmm0_4
  char v8; // r14
  float *p_mFOVOffset; // rsi
  unsigned int CellIndexAtPosition; // eax
  signed __int64 SectionFromCellIndex; // r15
  bool IsDefault; // r12
  unsigned int v13; // eax
  char *SectionNameFromCellIndex; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  UFG::qVector3 position; // [rsp+20h] [rbp-E8h] BYREF
  UFG::qMatrix44 d; // [rsp+30h] [rbp-D8h] BYREF
  UFG::qMatrix44 v21; // [rsp+70h] [rbp-98h] BYREF
  float far_plane; // [rsp+110h] [rbp+8h]

  if ( !this->mRenderEnvMap || !render_context->mEnvCubeMap )
    return;
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  v5 = *(float *)&FLOAT_1_0;
  position.y = d.v3.y;
  mEnvMapBlend = this->mEnvMapBlend;
  position.x = d.v3.x;
  position.z = d.v3.z;
  if ( mEnvMapBlend >= 0.30000001 )
  {
    this->mEnvMapBlend = 1.0;
  }
  else
  {
    v7 = (float)(fRealTimeDelta * 0.1) + mEnvMapBlend;
    if ( v7 <= 0.0 )
    {
      v7 = 0.0;
    }
    else if ( v7 >= 1.0 )
    {
      LODWORD(this->mEnvMapBlend) = (_DWORD)FLOAT_1_0;
      goto LABEL_10;
    }
    this->mEnvMapBlend = v7;
  }
LABEL_10:
  v8 = 0;
  p_mFOVOffset = 0i64;
  if ( UFG::SectionChooser::GetBSP() )
  {
    UFG::qInverseAffine(&v21, &render_context->mMainViewSettings.mWorldView);
    CellIndexAtPosition = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
    if ( CellIndexAtPosition != this->mCustomEnvMapCellIndex )
    {
      this->mCustomEnvMapCellIndex = CellIndexAtPosition;
      SectionFromCellIndex = UFG::SectionLayout::GetSectionFromCellIndex(CellIndexAtPosition);
      if ( SectionFromCellIndex )
      {
        IsDefault = UFG::qResourceHandle::IsDefault(&this->mEnvMapTextureHandle);
        v13 = UFG::qStringHashUpper32((const char *)(SectionFromCellIndex + 16), 0xFFFFFFFF);
        UFG::qTypedResourceHandle<2336488127,Illusion::Texture>::Init(&this->mEnvMapTextureHandle, v13);
        if ( UFG::qResourceHandle::IsDefault(&this->mEnvMapTextureHandle) && IsDefault )
        {
          this->mEnvMapBlend = 1.0;
          v8 = 1;
        }
        else
        {
          this->mEnvMapBlend = 0.0;
        }
      }
    }
  }
  if ( !UFG::qResourceHandle::IsDefault(&this->mEnvMapTextureHandle) && this->mEnvMapTextureHandle.mData )
    v5 = 0.0;
  UFG::qApproach(&this->mInteriorBlend, v5, 0.2, fRealTimeDelta);
  if ( v8 )
    this->mInteriorBlend = 1.0;
  SectionNameFromCellIndex = UFG::SectionLayout::GetSectionNameFromCellIndex(this->mCustomEnvMapCellIndex);
  if ( !UFG::qStringCompareInsensitive("NP_FreeRun_02", SectionNameFromCellIndex, -1) )
    this->mInteriorBlend = 1.0;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
  v16 = p_mFOVOffset[58];
  v17 = p_mFOVOffset[59];
  if ( v16 == 0.0 || v16 == v17 )
    v18 = far_plane;
  else
    v18 = (float)(p_mFOVOffset[62] - p_mFOVOffset[63]) / (float)(v16 - v17);
  Render::EnvCubeMap::UpdateMatrices(render_context->mEnvCubeMap, &position, 0.1, v18);
}

// File Line: 432
// RVA: 0x31E80
void __fastcall UFG::RenderStageEnvMap::RenderDebugOverlay(
        UFG::RenderStageEnvMap *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  Illusion::Texture *v5; // rcx
  UFG::qColour v6; // [rsp+40h] [rbp-18h] BYREF

  if ( this->mDrawDebugEnvMap )
  {
    Render::EnvCubeMap::RenderDebugOverlay(render_context->mEnvCubeMap, view, 20, 20, 150);
    v5 = render_context->mSphericalEnvMapTarget->mTargetTexture[0];
    v6 = UFG::qColour::White;
    Render::View::DrawIcon(view, v5->mNode.mUID, 20, 300, 400, 200, &v6, 0xA3833FDE);
  }
}

