// File Line: 77
// RVA: 0x31720
void __fastcall UFG::RenderStageEnvMap::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  UFG::RenderStageEnvMap *v2; // rax

  v1 = render_context;
  v2 = (UFG::RenderStageEnvMap *)UFG::qMalloc(0x48ui64, "RenderStageEnvMap", 0i64);
  if ( v2 )
    UFG::RenderStageEnvMap::RenderStageEnvMap(v2, v1);
}

// File Line: 86
// RVA: 0x31540
void __fastcall UFG::RenderStageEnvMap::RenderStageEnvMap(UFG::RenderStageEnvMap *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageEnvMap *v2; // rbx
  UFG::qResourceHandle *v3; // rdi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  v2 = this;
  v3 = (UFG::qResourceHandle *)&this->mEnvMapTextureHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mEnvMapTextureHandle.mPrev);
  v2->mEnvMapBlend = 0.0;
  v4 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Init(v3, 0x8B43FABF, 0xC0C0C0C0, v4);
  v2->mCustomEnvMapCellIndex = -1;
  *(_WORD *)&v2->mRenderEnvMap = 1;
  v2->mEnvMapSliceCount = 0;
  v2->mDrawDebugEnvMap = 0;
  v2->mEnvMapAmbientScale = 0.5;
  v2->mEnvMapDiffuseScale = 0.1;
  v2->mEnvMapSkySaturation = 1.0;
  v2->mInteriorBlend = 0.0;
}

// File Line: 120
// RVA: 0x31F10
void __fastcall UFG::RenderEnvCubeMapView(Render::View *view, void *user_data1, void *user_data2)
{
  _QWORD *v3; // r13
  UFG::SceneryGroupComponent **v4; // rdi
  Render::View *v5; // rsi
  Illusion::SubmitContext *v6; // r15
  signed __int64 v7; // rbx
  Render::ViewSettings *v8; // r12
  char *v9; // rax
  UFG::qVector4 *v10; // r14
  _OWORD *v11; // rdx
  char *v12; // r8
  UFG::TimeOfDayManager *v13; // rax
  char *v14; // rbx
  Illusion::StateValues *v15; // rax
  Illusion::StateValues *v16; // rax
  void *v17; // rbx
  Illusion::StateValues *v18; // rax
  float v19; // xmm7_4
  float v20; // xmm6_4
  char *v21; // rbx
  Illusion::StateValues *v22; // rax
  __int64 v23; // rbx
  UFG::qResourceData *v24; // rbx
  Illusion::StateValues *v25; // rax
  unsigned int v26; // eax
  unsigned __int16 v27; // bx
  void *v28; // r12
  Illusion::StateValues *v29; // rax
  unsigned __int16 v30; // ax
  Illusion::StateArgs *v31; // rax
  UFG::TimeOfDayManager *v32; // rax
  Illusion::Texture *v33; // rbx
  Illusion::StateValues *v34; // rax
  void *v35; // rbx
  Illusion::StateValues *v36; // rax
  Illusion::StateArgs *v37; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  __int64 v42; // [rsp+8h] [rbp-61h]
  unsigned int stencil; // [rsp+28h] [rbp-41h]
  Render::cbExternalViewTransformState arg; // [rsp+30h] [rbp-39h]
  float distance_from_near_plane; // [rsp+D0h] [rbp+67h]
  float v46; // [rsp+D4h] [rbp+6Bh]
  Render::ViewSettings *v47; // [rsp+D8h] [rbp+6Fh]

  v3 = user_data2;
  v4 = (UFG::SceneryGroupComponent **)user_data1;
  v5 = view;
  v6 = view->mSubmitContext;
  v7 = 2i64;
  LODWORD(v6[1].mStateValues.mSetValueMask.mFlags[1]) = 2;
  v8 = view->mSettings;
  v47 = view->mSettings;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
  v10 = (UFG::qVector4 *)v9;
  v11 = (_OWORD *)*v3;
  v12 = v9;
  if ( ((unsigned __int8)v9 | (unsigned __int8)*v3) & 0xF )
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
  v13 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetViewSpaceSunDir(v13, v10, v8);
  stencil = 0;
  v6->mShaderSelector = (Illusion::ShaderSelector *)&v42;
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(_QWORD *)v14 = 0i64;
  *((_DWORD *)v14 + 2) = 0;
  *((_DWORD *)v14 + 3) = 1065353216;
  v15 = Render::View::GetStateValues(v5);
  v15->mSetValueMask.mFlags[0] |= 0x100000000ui64;
  v15->mParamValues[32] = v14;
  v16 = Render::View::GetStateValues(v5);
  v16->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v16->mParamValues[55] = v10;
  v17 = *(void **)(v3[3] + 552i64);
  v18 = Render::View::GetStateValues(v5);
  v18->mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  v18->mParamValues[61] = v17;
  v19 = UFG::Metrics::msInstance.mSimTimeDelta;
  v20 = UFG::Metrics::msInstance.mSimTime_Temp;
  v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  *(float *)v21 = v20;
  *((float *)v21 + 1) = v19;
  v22 = Render::View::GetStateValues(v5);
  v22->mSetValueMask.mFlags[0] |= 0x2000ui64;
  v22->mParamValues[13] = v21;
  v23 = *(_QWORD *)(v3[3] + 88i64);
  if ( v23 )
    v24 = *(UFG::qResourceData **)(v23 + 24);
  else
    v24 = gDefaultBlackTexture.mData;
  v25 = Render::View::GetStateValues(v5);
  v25->mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
  v25->mParamValues[58] = v24;
  if ( _S1_7 & 1 )
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
  v28 = (void *)v3[1];
  v29 = Render::View::GetStateValues(v5);
  if ( (unsigned int)(signed __int16)v27 >= 0x40 )
    v29->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v27 - 64);
  else
    v29->mSetValueMask.mFlags[0] |= 1i64 << v27;
  v29->mParamValues[(signed __int16)v27] = v28;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v30 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v30;
    arg.mStateParamIndex = v30;
  }
  arg.mWorldView = &v47->mWorldView;
  arg.mProjection = &v47->mProjection;
  arg.mCached_Remote.m_Stream = 0i64;
  v31 = Render::View::GetStateArgs(v5);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v31, &arg);
  Render::View::Clear(v5, &UFG::qColour::Black, 6u, 1.0, 0);
  v32 = UFG::TimeOfDayManager::GetInstance();
  v33 = UFG::TimeOfDayManager::GetFogTexture(v32);
  v34 = Render::View::GetStateValues(v5);
  v34->mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  v34->mParamValues[41] = v33;
  v46 = FLOAT_10_0;
  v6[1].vfptr = (Illusion::SubmitContextVtbl *)&distance_from_near_plane;
  for ( v6[1].mStateValues.mSetValueMask.mFlags[0] = 0i64; *v4; ++v4 )
  {
    if ( (unsigned int)Render::View::IsInView(
                         v5,
                         &(*v4)->mSceneryGroup->mAABBMin,
                         &(*v4)->mSceneryGroup->mAABBMax,
                         &distance_from_near_plane) )
      UFG::SceneryGroupComponent::Draw(*v4, v5);
  }
  v35 = (void *)v3[2];
  v36 = Render::View::GetStateValues(v5);
  v36->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v36->mParamValues[55] = v35;
  RenderQueueLayer::SerializeRenderQueues((RenderQueueLayer *)v6[1].mStateValues.mParamValues[0]);
  RenderQueueLayer::SerializeDeferredAlpha((RenderQueueLayer *)v6[1].mStateValues.mParamValues[0]);
  LODWORD(v6[1].mStateValues.mSetValueMask.mFlags[1]) = 1;
  Render::SkyMarshall::RenderFar(&Render::SkyMarshall::gSkyMarshall, v5, 0.16666667);
  Render::SkyMarshall::RenderCloudDome(&Render::SkyMarshall::gSkyMarshall, v5, 0.16666667);
  Render::FlareManager::Render(&Render::gFlareManager, v5, 0.0, 0, 1u);
  v37 = Render::View::GetStateArgs(v5);
  v38 = arg.mPrev;
  v39 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v39->mPrev = v38;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v37->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v37 + 16 * (arg.mStateParamIndex + 3i64)) )
    v37->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v6->mShaderSelector = 0i64;
  v40 = arg.mPrev;
  v41 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v41->mPrev = v40;
}

// File Line: 202
// RVA: 0x31770
__int64 __fastcall UFG::GetEnvMapSceneryGroups(Render::ViewSettings *main_view_settings, UFG::SceneryGroupComponent **components)
{
  UFG::SceneryGroupComponent **v2; // rbx
  UFG::SceneryGroupComponent *v3; // rdi
  unsigned int v4; // esi
  UFG::SceneryGroup *v5; // rax
  UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *v6; // rbp
  float *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::qVector3 vmin; // [rsp+20h] [rbp-1C8h]
  UFG::qVector3 vmax; // [rsp+30h] [rbp-1B8h]
  Render::View v15; // [rsp+40h] [rbp-1A8h]
  float distance_from_near_plane; // [rsp+200h] [rbp+18h]
  int v17; // [rsp+204h] [rbp+1Ch]

  v2 = components;
  Render::View::View(&v15, main_view_settings, 0i64);
  v3 = (UFG::SceneryGroupComponent *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  v4 = 0;
  if ( &UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent> **)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList - 88) )
  {
    do
    {
      v5 = v3->mSceneryGroup;
      v6 = (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)&v3->mNext[-6].mNext;
      if ( !(v5->mFlags & 1) && v5->mSceneryLayer == 1 )
      {
        if ( UFG::SectionChooser::IsSectionVisible_VisIndex(v5->mSectionVisIndex, SCENERY_LAYER_STD, 0) )
          goto LABEL_11;
        v7 = (float *)v3->mSceneryGroup;
        v17 = 1092616192;
        v8 = v7[37];
        v9 = v7[36];
        vmin.z = v7[38];
        vmin.x = v9;
        vmin.y = v8;
        v10 = v7[40];
        v11 = v7[39];
        vmin.z = -1000.0;
        vmax.z = 1000.0;
        vmax.x = v11;
        vmax.y = v10;
        if ( (unsigned int)Render::View::IsInView(&v15, &vmin, &vmax, &distance_from_near_plane) )
        {
LABEL_11:
          ++v4;
          *v2 = v3;
          ++v2;
        }
      }
      v3 = (UFG::SceneryGroupComponent *)v6;
    }
    while ( v6 != (UFG::qList<UFG::SceneryGroupComponent,UFG::SceneryGroupComponent,1,0> *)((char *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList
                                                                                          - 88) );
  }
  return v4;
}

// File Line: 245
// RVA: 0x31960
void __fastcall UFG::RenderStageEnvMap::Render(UFG::RenderStageEnvMap *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // rbx
  UFG::RenderContext *v4; // rdi
  UFG::RenderStageEnvMap *v5; // rsi
  UFG::qResourceData *v6; // r14
  unsigned int v7; // ebx
  Render::ViewSettings *v8; // rax
  float v9; // xmm0_4
  CB_EnvironmentSettings *v10; // rbx
  float v11; // xmm6_4
  UFG::TimeOfDayManager *v12; // rax
  bool v13; // cl
  unsigned int v14; // ecx
  UFG::qColour colour; // [rsp+50h] [rbp-B0h]
  int v16; // [rsp+60h] [rbp-A0h]
  int v17; // [rsp+64h] [rbp-9Ch]
  CB_EnvironmentSettings *user_data2; // [rsp+68h] [rbp-98h]
  CB_SkySettings *v19; // [rsp+70h] [rbp-90h]
  CB_EnvironmentSettings *v20; // [rsp+78h] [rbp-88h]
  UFG::RenderContext *v21; // [rsp+80h] [rbp-80h]
  UFG::qResourceData *v22; // [rsp+88h] [rbp-78h]
  UFG::qResourceData *v23; // [rsp+90h] [rbp-70h]
  __int64 v24; // [rsp+98h] [rbp-68h]
  Render::View user_data1; // [rsp+A0h] [rbp-60h]
  RenderQueueLayer v26; // [rsp+2A0h] [rbp+1A0h]
  ForwardEnvMapSubmitContext ptr; // [rsp+380h] [rbp+280h]
  Render::Poly poly; // [rsp+1048h] [rbp+F48h]

  v24 = -2i64;
  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  if ( render_context->mRenderFeatures.mWorld && this->mRenderEnvMap && render_context->mEnvCubeMap )
  {
    RenderQueueLayer::RenderQueueLayer(&v26);
    ForwardEnvMapSubmitContext::ForwardEnvMapSubmitContext(&ptr);
    v26.mSerializationList = v3;
    ptr.mRenderQueueProvider = &v26;
    v23 = AlphaStateNoneHandle.mData;
    v22 = RasterStateNormalHandle.mData;
    ptr.mPerPhaseParams = (ForwardEnvMapSubmitContext::PerPhaseParams *)&v22;
    v6 = 0i64;
    if ( !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&v5->mEnvMapTextureHandle.mPrev) )
      v6 = v5->mEnvMapTextureHandle.mData;
    if ( v6 && gEnableCustomEnvMaps )
    {
      ptr.mQueueMode = 1;
      v7 = 662883558;
      if ( v5->mEnvMapBlend < 1.0 )
        v7 = -1551679522;
      v8 = Render::ViewSettings::GetIdentity();
      Render::View::View(&user_data1, v8, (Illusion::SubmitContext *)&ptr.vfptr);
      Render::View::BeginTarget(&user_data1, v4->mSphericalEnvMapTarget, "SphericalMap_Blend", 0, 0, 0i64, 1, 0, 0, 0);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 0, 0x8B5561A1, 0x3141335Cu);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 1, 0x8B43FABF, v6->mNode.mUID);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 2, 0x12C800F2u, v7);
      Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
      v9 = v5->mEnvMapBlend;
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 1.0;
      colour.a = v9;
      Render::Poly::SetColour(&poly, &colour);
      Render::View::Draw(&user_data1, &poly, Render::gRenderUtilities.mMaterial, 0i64);
      Render::View::EndTarget(&user_data1);
      Illusion::Material::UpdateParam(Render::gRenderUtilities.mMaterial, 2, 0x12C800F2u, 0x2782CCE6u);
    }
    else
    {
      *((_QWORD *)&user_data1.mSettings
      + (unsigned int)UFG::GetEnvMapSceneryGroups(&v4->mMainViewSettings, (UFG::SceneryGroupComponent **)&user_data1)) = 0i64;
      v10 = (CB_EnvironmentSettings *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
      v11 = v5->mEnvMapSkySaturation;
      UFG::TimeOfDayManager::GetInstance()->mSkySaturation = v11;
      v12 = UFG::TimeOfDayManager::GetInstance();
      UFG::TimeOfDayManager::GetEnvironmentSettings(v12, v10, 0i64, 0i64);
      v10->AmbientColorHorizon[0] = v5->mEnvMapAmbientScale * v10->AmbientColorHorizon[0];
      v10->AmbientColorHorizon[1] = v5->mEnvMapAmbientScale * v10->AmbientColorHorizon[1];
      v10->AmbientColorHorizon[2] = v5->mEnvMapAmbientScale * v10->AmbientColorHorizon[2];
      v10->SunColor[0] = v10->SunColor[0] * v5->mEnvMapDiffuseScale;
      v10->SunColor[1] = v5->mEnvMapDiffuseScale * v10->SunColor[1];
      v10->SunColor[2] = v5->mEnvMapDiffuseScale * v10->SunColor[2];
      v13 = !v5->mTimeSliceRenderEnvMap || UFG::RenderWorld::msIsNisPlaying;
      user_data2 = v10;
      v19 = v4->mSkyState;
      v20 = v4->mEnvState;
      v21 = v4;
      if ( v13 )
      {
        Render::EnvCubeMap::Render(
          v4->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          0xFFFFFFFF,
          (Illusion::SubmitContext *)&ptr.vfptr,
          &user_data1,
          &user_data2);
        Render::EnvCubeMap::RenderSphericalMap(
          v4->mEnvCubeMap,
          v4->mSphericalEnvMapTarget,
          (Illusion::SubmitContext *)&ptr.vfptr,
          v5->mEnvMapBlend);
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
          v4->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + v5->mEnvMapSliceCount),
          (Illusion::SubmitContext *)&ptr.vfptr,
          &user_data1,
          &user_data2);
        Render::EnvCubeMap::Render(
          v4->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + v5->mEnvMapSliceCount + 1),
          (Illusion::SubmitContext *)&ptr.vfptr,
          &user_data1,
          &user_data2);
        Render::EnvCubeMap::Render(
          v4->mEnvCubeMap,
          UFG::RenderEnvCubeMapView,
          *((_DWORD *)&colour.r + v5->mEnvMapSliceCount + 2),
          (Illusion::SubmitContext *)&ptr.vfptr,
          &user_data1,
          &user_data2);
        v14 = (v5->mEnvMapSliceCount + 3) % 6;
        v5->mEnvMapSliceCount = v14;
        if ( v14 )
        {
LABEL_20:
          UFG::TimeOfDayManager::GetInstance()->mSkySaturation = 1.0;
          poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
          `eh vector destructor iterator'(
            ptr.mStateArgs.mStateArgs,
            0x10ui64,
            128,
            (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
          RenderQueueLayer::~RenderQueueLayer(&v26);
          return;
        }
        Render::EnvCubeMap::RenderSphericalMap(
          v4->mEnvCubeMap,
          v4->mSphericalEnvMapTarget,
          (Illusion::SubmitContext *)&ptr.vfptr,
          v5->mEnvMapBlend);
        v5->mEnvMapSliceCount = 0;
      }
    }
    ptr.mQueueMode = 1;
    Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    Render::RenderUtilities::RenderMips(&Render::gRenderUtilities, v4->mSphericalEnvMapTarget, 7u, 0xC532D4Bu);
    Render::gRenderUtilities.mSubmitContext = 0i64;
    goto LABEL_20;
  }
}

// File Line: 368
// RVA: 0x32420
void __fastcall UFG::RenderStageEnvMap::UpdateViews(UFG::RenderStageEnvMap *this, UFG::RenderContext *render_context, float fRealTimeDelta)
{
  UFG::RenderContext *v3; // rbp
  UFG::RenderStageEnvMap *v4; // rdi
  float v5; // xmm6_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  char v8; // r14
  float *v9; // rsi
  unsigned int v10; // eax
  signed __int64 v11; // r15
  bool v12; // r12
  unsigned int v13; // eax
  char *v14; // rax
  UFG::BaseCameraComponent *v15; // rcx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  UFG::qVector3 position; // [rsp+20h] [rbp-E8h]
  UFG::qMatrix44 d; // [rsp+30h] [rbp-D8h]
  UFG::qMatrix44 v21; // [rsp+70h] [rbp-98h]
  float far_plane; // [rsp+110h] [rbp+8h]

  v3 = render_context;
  v4 = this;
  if ( !this->mRenderEnvMap || !render_context->mEnvCubeMap )
    return;
  UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
  v5 = *(float *)&FLOAT_1_0;
  position.y = d.v3.y;
  v6 = v4->mEnvMapBlend;
  position.x = d.v3.x;
  position.z = d.v3.z;
  if ( v6 >= 0.30000001 )
  {
    v4->mEnvMapBlend = 1.0;
  }
  else
  {
    v7 = (float)(fRealTimeDelta * 0.1) + v6;
    if ( v7 <= 0.0 )
    {
      v7 = 0.0;
    }
    else if ( v7 >= 1.0 )
    {
      LODWORD(v4->mEnvMapBlend) = (_DWORD)FLOAT_1_0;
      goto LABEL_10;
    }
    v4->mEnvMapBlend = v7;
  }
LABEL_10:
  v8 = 0;
  v9 = 0i64;
  if ( UFG::SectionChooser::GetBSP() )
  {
    UFG::qInverseAffine(&v21, &v3->mMainViewSettings.mWorldView);
    v10 = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
    if ( v10 != v4->mCustomEnvMapCellIndex )
    {
      v4->mCustomEnvMapCellIndex = v10;
      v11 = UFG::SectionLayout::GetSectionFromCellIndex(v10);
      if ( v11 )
      {
        v12 = UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&v4->mEnvMapTextureHandle.mPrev);
        v13 = UFG::qStringHashUpper32((const char *)(v11 + 16), 0xFFFFFFFF);
        UFG::qTypedResourceHandle<2336488127,Illusion::Texture>::Init(
          (UFG::qTypedResourceHandle<2336488127,Illusion::Texture> *)&v4->mEnvMapTextureHandle.mPrev,
          v13);
        if ( UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&v4->mEnvMapTextureHandle.mPrev) && v12 )
        {
          v4->mEnvMapBlend = 1.0;
          v8 = 1;
        }
        else
        {
          v4->mEnvMapBlend = 0.0;
        }
      }
    }
  }
  if ( !UFG::qResourceHandle::IsDefault((UFG::qResourceHandle *)&v4->mEnvMapTextureHandle.mPrev)
    && v4->mEnvMapTextureHandle.mData )
  {
    v5 = 0.0;
  }
  UFG::qApproach(&v4->mInteriorBlend, v5, 0.2, fRealTimeDelta);
  if ( v8 )
    v4->mInteriorBlend = 1.0;
  v14 = UFG::SectionLayout::GetSectionNameFromCellIndex(v4->mCustomEnvMapCellIndex);
  if ( !UFG::qStringCompareInsensitive("NP_FreeRun_02", v14, -1) )
    v4->mInteriorBlend = 1.0;
  v15 = UFG::Director::Get()->mCurrentCamera;
  if ( v15 )
    v9 = &v15->mCamera.mFOVOffset;
  v16 = v9[58];
  v17 = v9[59];
  if ( v16 == 0.0 || v16 == v17 )
    v18 = far_plane;
  else
    v18 = (float)(v9[62] - v9[63]) / (float)(v16 - v17);
  Render::EnvCubeMap::UpdateMatrices(v3->mEnvCubeMap, &position, 0.1, v18);
}

// File Line: 432
// RVA: 0x31E80
void __fastcall UFG::RenderStageEnvMap::RenderDebugOverlay(UFG::RenderStageEnvMap *this, UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v3; // rbx
  UFG::RenderContext *v4; // rdi
  Illusion::Texture *v5; // rcx
  UFG::qColour v6; // [rsp+40h] [rbp-18h]

  v3 = view;
  v4 = render_context;
  if ( this->mDrawDebugEnvMap )
  {
    Render::EnvCubeMap::RenderDebugOverlay(render_context->mEnvCubeMap, view, 20, 20, 150);
    v5 = v4->mSphericalEnvMapTarget->mTargetTexture[0];
    v6 = UFG::qColour::White;
    Render::View::DrawIcon(v3, v5->mNode.mUID, 20, 300, 400, 200, &v6, 0xA3833FDE);
  }
}

