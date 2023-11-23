// File Line: 44
// RVA: 0x6E390
UFG::ComponentIDDesc *__fastcall UFG::HighlightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HighlightComponent::_DescInit )
  {
    UFG::HighlightComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HighlightComponent::_DescInit = 1;
    UFG::HighlightComponent::_TypeUID = UFG::HighlightComponent::_TypeIDesc.mChildBitMask | (UFG::HighlightComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HighlightComponent::_HighlightComponentTypeUID = UFG::HighlightComponent::_TypeIDesc.mChildBitMask | (UFG::HighlightComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HighlightComponent::_TypeIDesc;
}

// File Line: 48
// RVA: 0x6DE80
void __fastcall UFG::HighlightComponent::HighlightComponent(UFG::HighlightComponent *this)
{
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent>;
  this->mNext = &this->UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightComponent::`vftable;
  this->mHighlightParams.mColour = UFG::qColour::White;
  *(_QWORD *)&this->mHighlightParams.mOutlineStrength = 1065353216i64;
  this->mHighlightParams.mIsDepthEnabled = 0;
  UFG::SimComponent::AddType(this, UFG::HighlightComponent::_HighlightComponentTypeUID, "HighlightComponent");
  mPrev = UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev;
  UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&UFG::HighlightComponent::s_HighlightComponentList;
  UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent>;
}

// File Line: 53
// RVA: 0x6E1F0
void __fastcall UFG::HighlightComponent::~HighlightComponent(UFG::HighlightComponent *this)
{
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v2; // rdx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *mPrev; // rcx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *mNext; // rax
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v5; // rcx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightComponent::`vftable;
  if ( this == UFG::HighlightComponent::s_HighlightComponentpCurrentIterator )
    UFG::HighlightComponent::s_HighlightComponentpCurrentIterator = (UFG::HighlightComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 58
// RVA: 0x1456EE0
__int64 dynamic_initializer_for__UFG::HighlightComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::HighlightComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::HighlightComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::HighlightComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::HighlightComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 59
// RVA: 0x1456F40
__int64 dynamic_initializer_for__UFG::HighlightComponent::s_HighlightComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HighlightComponent::s_HighlightComponentList__);
}

// File Line: 71
// RVA: 0x6E000
void __fastcall UFG::HighlightSubmitContext::HighlightSubmitContext(UFG::HighlightSubmitContext *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  LayerSubmitContext::LayerSubmitContext(this);
  this->vfptr = (Illusion::SubmitContextVtbl *)&UFG::HighlightSubmitContext::`vftable;
  this->mDiffuse2 = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mDepthEnabledRasterStateHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mDepthDisabledRasterStateHandle);
  Inventory = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mDepthEnabledRasterStateHandle, 0x3BC715E0u, 0x20688F05u, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(&this->mDepthDisabledRasterStateHandle, 0x3BC715E0u, 0x62F81854u, v4);
}

// File Line: 83
// RVA: 0x6E6C0
Illusion::RenderQueue *__fastcall UFG::HighlightSubmitContext::OnPreSubmit(
        UFG::HighlightSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  _QWORD *mMainMemoryAddress; // rax
  char *v5; // r9
  __int64 v6; // rcx
  char *v9; // rcx
  __int64 v10; // rdx
  void *v11; // rcx
  UFG::qResourceData *mData; // rax
  Illusion::RasterStateHandle *p_mDepthEnabledRasterStateHandle; // rax
  UFG::qResourceData *v15; // rax
  Illusion::Texture *mDiffuse2; // rax

  mMainMemoryAddress = shader_stream->mMainMemoryAddress;
  v5 = 0i64;
  v6 = mMainMemoryAddress[13];
  if ( v6 )
    v9 = (char *)mMainMemoryAddress + v6 + 104;
  else
    v9 = 0i64;
  v10 = mMainMemoryAddress[13];
  v11 = (void *)*((_QWORD *)v9 + 18);
  if ( v10 )
    v5 = (char *)mMainMemoryAddress + v10 + 104;
  if ( !v5[192] )
  {
    if ( !v11 )
      return 0i64;
    goto LABEL_10;
  }
  if ( v11 )
  {
LABEL_10:
    this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
    this->mStateValues.mParamValues[1] = v11;
    Illusion::SubmitContext::LoadShader(this, shader_stream);
    mData = Render::UberMaterial::GetCustomRenderPass()->mCustomRenderPass->mAlphaStateHandle.mData;
    this->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    this->mStateValues.mParamValues[9] = mData;
  }
  p_mDepthEnabledRasterStateHandle = &this->mDepthEnabledRasterStateHandle;
  if ( !this->mIsDepthEnabled )
    p_mDepthEnabledRasterStateHandle = &this->mDepthDisabledRasterStateHandle;
  v15 = p_mDepthEnabledRasterStateHandle->mData;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  this->mStateValues.mParamValues[10] = v15;
  mDiffuse2 = this->mDiffuse2;
  this->mStateValues.mSetValueMask.mFlags[0] |= 0x800000ui64;
  this->mStateValues.mParamValues[23] = mDiffuse2;
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  return LayerSubmitContext::ChooseRenderQueue(this, shader_stream, this->mCullMetrics);
}

// File Line: 127
// RVA: 0x1456F60
__int64 UFG::_dynamic_initializer_for__AlphaStateSourceRGBAlphaOne__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AlphaStateSourceRGBAlphaOne", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&AlphaStateSourceRGBAlphaOne, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__AlphaStateSourceRGBAlphaOne__);
}

// File Line: 132
// RVA: 0x6E400
UFG::ComponentIDDesc *__fastcall UFG::HighlightPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::HighlightPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::HighlightPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::HighlightPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::HighlightPostEffect::_TypeIDesc.mChildren = 0;
    UFG::HighlightPostEffect::_DescInit = 1;
    UFG::HighlightPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::HighlightPostEffect::_HighlightPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::HighlightPostEffect::_TypeIDesc;
}

// File Line: 144
// RVA: 0x6E530
UFG::ComponentIDDesc *__fastcall UFG::HighlightPostEffect::GetDesc(UFG::HighlightPostEffect *this)
{
  return &UFG::HighlightPostEffect::_TypeIDesc;
}

// File Line: 147
// RVA: 0x6DF30
void __fastcall UFG::HighlightPostEffect::HighlightPostEffect(UFG::HighlightPostEffect *this)
{
  char *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightPostEffect::`vftable;
  UFG::SimComponent::AddType(this, UFG::HighlightPostEffect::_HighlightPostEffectTypeUID, "HighlightPostEffect");
  if ( !sIsStaticInit_2 )
  {
    *(UFG::qColour *)twkShaderParams.Value0 = UFG::qColour::White;
    twkShaderParams.Value1[0] = 1.0;
    twkShaderParams.Value1[1] = 1.0;
    v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&AlphaStateSourceRGBAlphaOne);
    v3 = Illusion::Factory::NewAlphaState(v2, AlphaStateSourceRGBAlphaOne.mUID, 0i64, 0i64, 0i64);
    LOWORD(v3[1].mNode.mParent) = 257;
    BYTE2(v3[1].mNode.mParent) = 0;
    LOWORD(v3[1].mNode.mChild[0]) = 257;
    BYTE2(v3[1].mNode.mChild[0]) = 0;
    v4 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v4, v3);
    sIsStaticInit_2 = 1;
  }
}

// File Line: 181
// RVA: 0x6EDA0
void __fastcall UFG::HighlightPostEffect::SetHighlightParams(
        UFG::HighlightPostEffect *this,
        Render::View *view,
        UFG::HighlightParams *highlight_params)
{
  float *v5; // rax
  float *v6; // rbx
  Illusion::StateValues *StateValues; // rax

  v5 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *v5 = highlight_params->mColour.r;
  v6 = v5;
  v5[1] = highlight_params->mColour.g;
  v5[2] = highlight_params->mColour.b;
  v5[3] = highlight_params->mColour.a;
  v5[4] = highlight_params->mXrayStrength;
  v5[5] = highlight_params->mOutlineStrength;
  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
  StateValues->mParamValues[15] = v6;
  LOBYTE(view->mSubmitContext[1].mStateValues.mParamValues[10]) = highlight_params->mIsDepthEnabled;
}

// File Line: 202
// RVA: 0x6E7E0
void __fastcall UFG::HighlightPostEffect::RenderHighlightObject(
        UFG::HighlightPostEffect *this,
        Render::View *view,
        UFG::SimObject *sim_object,
        UFG::HighlightComponent *highlight_component)
{
  UFG::HighlightComponent *v4; // rbp
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v8; // ebx
  unsigned int MainViewLOD; // eax
  UFG::SimComponent *v10; // rax
  Render::SimpleDrawableComponent *p_m_pSimObject; // rbp
  UFG::SimComponent *v12; // rax
  UFG::DynamicSceneryInstance *v13; // rbp
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::SimObject *ChildAsSimObject; // rax
  UFG::CompositeDrawableComponent *v17; // [rsp+50h] [rbp+18h]

  v4 = highlight_component;
  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::CompositeDrawableComponent::_TypeUID);
    v8 = 0;
    v17 = (UFG::CompositeDrawableComponent *)ComponentOfType;
    if ( ComponentOfType
      && (view->mSettings->mCullIndex < 0
       || *((_BYTE *)&ComponentOfType[19].m_pSimObject->vfptr + view->mSettings->mCullIndex) <= 1u) )
    {
      UFG::HighlightPostEffect::SetHighlightParams(this, view, &v4->mHighlightParams);
      MainViewLOD = (unsigned int)UFG::CompositeDrawableComponent::GetMainViewLOD(v17);
      UFG::CompositeDrawableComponent::Draw(v17, view, MainViewLOD);
    }
    v10 = UFG::SimObject::GetComponentOfType(sim_object, Render::SimpleDrawableComponent::_TypeUID);
    if ( v10 )
    {
      p_m_pSimObject = (Render::SimpleDrawableComponent *)&v10[-1].m_pSimObject;
      if ( v10 != (UFG::SimComponent *)24
        && (view->mSettings->mCullIndex < 0
         || p_m_pSimObject->mCullResults->mViewResult[view->mSettings->mCullIndex] <= 1u) )
      {
        UFG::HighlightPostEffect::SetHighlightParams(this, view, &highlight_component->mHighlightParams);
        Render::SimpleDrawableComponent::Draw(p_m_pSimObject, view);
      }
    }
    v12 = UFG::SimObject::GetComponentOfType(sim_object, UFG::DynamicSceneryInstance::_TypeUID);
    if ( v12 )
    {
      v13 = (UFG::DynamicSceneryInstance *)&v12[-1].m_pSimObject;
      if ( v12 != (UFG::SimComponent *)24
        && (view->mSettings->mCullIndex < 0 || v13->mCullResults->mViewResult[view->mSettings->mCullIndex] <= 1u) )
      {
        UFG::HighlightPostEffect::SetHighlightParams(this, view, &highlight_component->mHighlightParams);
        UFG::DynamicSceneryInstance::Draw(v13, view);
      }
    }
    m_pSceneObj = sim_object->m_pSceneObj;
    v4 = highlight_component;
  }
  else
  {
    v8 = 0;
    m_pSceneObj = 0i64;
  }
  if ( m_pSceneObj && m_pSceneObj->mChildren.mCount )
  {
    do
    {
      ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject(m_pSceneObj, v8);
      UFG::HighlightPostEffect::RenderHighlightObject(this, view, ChildAsSimObject, v4);
      ++v8;
    }
    while ( v8 < m_pSceneObj->mChildren.mCount );
  }
}

// File Line: 237
// RVA: 0x6E990
void __fastcall UFG::HighlightPostEffect::RenderPostEffect(
        UFG::HighlightPostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        UFG::RenderContext *render_context,
        float delta_time,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *v9; // rdi
  Illusion::eRenderPass::StaticPassData *CustomRenderPass; // rax
  Illusion::eRenderPass::StaticPassData *v11; // rax
  UFG::HighlightComponent *v12; // r8
  __int64 v13; // rbx
  Illusion::eRenderPass::StaticPassData *v14; // rax
  Illusion::eRenderPass::StaticPassData *v15; // rax
  UFG::HighlightComponent *v16; // r8
  __int64 v17; // rbx
  Illusion::Target *v18; // rcx
  Render::Poly poly; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v20; // [rsp+58h] [rbp-A8h]
  Illusion::eRenderPass::CustomRenderPass v21; // [rsp+60h] [rbp-A0h] BYREF
  Illusion::eRenderPass::CustomRenderPass v22; // [rsp+D0h] [rbp-30h] BYREF
  RenderQueueLayer v23; // [rsp+140h] [rbp+40h] BYREF
  Render::View v24; // [rsp+220h] [rbp+120h] BYREF
  Render::View view; // [rsp+3B0h] [rbp+2B0h] BYREF
  LayerSubmitContext ptr; // [rsp+540h] [rbp+440h] BYREF
  UFG::HighlightSubmitContext v27; // [rsp+11C0h] [rbp+10C0h] BYREF

  v20 = -2i64;
  v9 = &UFG::HighlightComponent::s_HighlightComponentList - 4;
  if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != &UFG::HighlightComponent::s_HighlightComponentList - 4
    && render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v23);
    v23.mSerializationList = serialization_list;
    UFG::HighlightSubmitContext::HighlightSubmitContext(&v27);
    v27.mRenderQueueProvider = &v23;
    v27.mQueueMode = QM_Single;
    v27.mRenderPass = Custom;
    v27.mDiffuse2 = (*curr_target)->mTargetTexture[0];
    LayerSubmitContext::LayerSubmitContext(&ptr);
    ptr.mRenderQueueProvider = &v23;
    ptr.mQueueMode = QM_Single;
    CustomRenderPass = Render::UberMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
      &v22,
      CustomRenderPass,
      0x70ADE623u,
      AlphaStateSourceRGBAlphaOne.mUID,
      0x62F81854u);
    v11 = Render::CharacterMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
      &v21,
      v11,
      0x9E92E2C2,
      AlphaStateSourceRGBAlphaOne.mUID,
      0x62F81854u);
    Render::View::View(&view, &render_context->mMainViewSettings, &v27);
    Render::View::BeginTarget(&view, *scratch_target, "Outline", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Black, 1u, 1.0, 1u);
    v12 = (UFG::HighlightComponent *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4];
    if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != v9 )
    {
      do
      {
        v13 = (__int64)&v12->mNext[-4];
        UFG::HighlightPostEffect::RenderHighlightObject(this, &view, v12->m_pSimObject, v12);
        v12 = (UFG::HighlightComponent *)v13;
      }
      while ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)v13 != v9 );
    }
    Render::View::EndTarget(&view);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v21);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v22);
    Render::gRenderUtilities.mSubmitContext = &ptr;
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      *scratch_target,
      render_context->mHalfSizeScratchTargetB,
      0,
      0i64,
      kGaussBlur3x3UID_15);
    Render::View::View(&v24, &render_context->mMainViewSettings, &ptr);
    Render::View::BeginTarget(&v24, *scratch_target, "Highlight", 0, 0, 0i64, 1, 0, 0, 0);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v24, &poly, (*curr_target)->mTargetTexture[0]->mNode.mUID, 0i64, 0x62F81854u, 0x2782CCE6u);
    v24.mSubmitContext = &v27;
    v27.mDiffuse2 = render_context->mHalfSizeScratchTargetB->mTargetTexture[0];
    ptr.mRenderPass = Custom;
    v14 = Render::UberMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(&v21, v14, 0x70ADE623u, 0xA3833FDE, 0x62F81854u);
    v15 = Render::CharacterMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(&v22, v15, 0x9E92E2C2, 0xA3833FDE, 0x62F81854u);
    v16 = (UFG::HighlightComponent *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4];
    if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != v9 )
    {
      do
      {
        v17 = (__int64)&v16->mNext[-4];
        UFG::HighlightPostEffect::RenderHighlightObject(this, &v24, v16->m_pSimObject, v16);
        v16 = (UFG::HighlightComponent *)v17;
      }
      while ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)v17 != v9 );
    }
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v22);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v21);
    Render::View::EndTarget(&v24);
    v18 = *curr_target;
    *curr_target = *scratch_target;
    *scratch_target = v18;
    poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    UFG::HighlightSubmitContext::~HighlightSubmitContext(&v27);
    RenderQueueLayer::~RenderQueueLayer(&v23);
  }
}

// File Line: 317
// RVA: 0x6E490
void __fastcall UFG::CreateHighlightPlugin(UFG *this)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v2; // rax
  UFG::SimObjectModifier v3; // [rsp+38h] [rbp-30h] BYREF

  UFG::SimObjectModifier::SimObjectModifier(&v3, UFG::RenderWorld::msRenderStagePlugin, 1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v2 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x50ui64, "HighlightPostEffect", 0i64, 1u);
  if ( v2 )
    UFG::HighlightPostEffect::HighlightPostEffect((UFG::HighlightPostEffect *)v2);
  UFG::SimObjectModifier::AttachComponent(&v3, (UFG::SimComponent *)v2, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v3);
  UFG::SimObjectModifier::~SimObjectModifier(&v3);
}

// File Line: 322
// RVA: 0x6E680
bool __fastcall UFG::IsHighlightSimObject(UFG::SimObject *sim_object)
{
  return sim_object && UFG::SimObject::GetComponentOfType(sim_object, UFG::HighlightComponent::_TypeUID) != 0i64;
}

// File Line: 327
// RVA: 0x6E560
void __fastcall UFG::HighlightSimObject(UFG::SimObject *sim_object, UFG::HighlightParams *highlight_params)
{
  UFG::HighlightComponent *ComponentOfType; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v6; // rax
  UFG::HighlightComponent *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float a; // xmm0_4
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  if ( !sim_object
    || (ComponentOfType = (UFG::HighlightComponent *)UFG::SimObject::GetComponentOfType(
                                                       sim_object,
                                                       UFG::HighlightComponent::_TypeUID)) == 0i64 )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x70ui64, "HighlightComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::HighlightComponent::HighlightComponent((UFG::HighlightComponent *)v6);
      ComponentOfType = v7;
    }
    else
    {
      ComponentOfType = 0i64;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v11, sim_object, 1);
    UFG::SimObjectModifier::AttachComponent(&v11, ComponentOfType, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v11);
    UFG::SimObjectModifier::~SimObjectModifier(&v11);
  }
  ComponentOfType->mHighlightParams = *highlight_params;
  v8 = ComponentOfType->mHighlightParams.mColour.g * ComponentOfType->mHighlightParams.mColour.g;
  v9 = ComponentOfType->mHighlightParams.mColour.b * ComponentOfType->mHighlightParams.mColour.b;
  a = ComponentOfType->mHighlightParams.mColour.a;
  ComponentOfType->mHighlightParams.mColour.r = ComponentOfType->mHighlightParams.mColour.r
                                              * ComponentOfType->mHighlightParams.mColour.r;
  ComponentOfType->mHighlightParams.mColour.g = v8;
  ComponentOfType->mHighlightParams.mColour.b = v9;
  ComponentOfType->mHighlightParams.mColour.a = a;
}

// File Line: 342
// RVA: 0x6EE30
void __fastcall UFG::UnHighlightSimObject(UFG::SimObject *sim_object)
{
  UFG::SimComponent *ComponentOfType; // rdi
  ArrayOfTuplesImplementation v3; // [rsp+28h] [rbp-30h] BYREF

  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::HighlightComponent::_TypeUID);
    if ( ComponentOfType )
    {
      UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v3, sim_object, 1);
      ArrayOfTuplesImplementation::clear(&v3);
      UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v3);
      UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v3);
      UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
    }
  }
}

