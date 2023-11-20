// File Line: 44
// RVA: 0x6E390
UFG::ComponentIDDesc *__fastcall UFG::HighlightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HighlightComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HighlightComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HighlightComponent::_TypeIDesc.mChildren = v0->mChildren;
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
  UFG::HighlightComponent *v1; // rdi
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v2; // rbx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v3; // rax

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightComponent::`vftable;
  v1->mHighlightParams.mColour.r = UFG::qColour::White.r;
  v1->mHighlightParams.mColour.g = UFG::qColour::White.g;
  v1->mHighlightParams.mColour.b = UFG::qColour::White.b;
  v1->mHighlightParams.mColour.a = UFG::qColour::White.a;
  *(_QWORD *)&v1->mHighlightParams.mOutlineStrength = 1065353216i64;
  v1->mHighlightParams.mIsDepthEnabled = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::HighlightComponent::_HighlightComponentTypeUID,
    "HighlightComponent");
  v3 = UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev;
  UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&v1->mPrev;
  v2->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&UFG::HighlightComponent::s_HighlightComponentList;
  UFG::HighlightComponent::s_HighlightComponentList.mNode.mPrev = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&v1->mPrev;
}

// File Line: 53
// RVA: 0x6E1F0
void __fastcall UFG::HighlightComponent::~HighlightComponent(UFG::HighlightComponent *this)
{
  UFG::HighlightComponent *v1; // r8
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v2; // rdx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v3; // rcx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v4; // rax
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v5; // rcx
  UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightComponent::`vftable;
  if ( this == UFG::HighlightComponent::s_HighlightComponentpCurrentIterator )
    UFG::HighlightComponent::s_HighlightComponentpCurrentIterator = (UFG::HighlightComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::HighlightComponent,UFG::HighlightComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
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
  return atexit(dynamic_atexit_destructor_for__UFG::HighlightComponent::s_HighlightComponentList__);
}

// File Line: 71
// RVA: 0x6E000
void __fastcall UFG::HighlightSubmitContext::HighlightSubmitContext(UFG::HighlightSubmitContext *this)
{
  UFG::HighlightSubmitContext *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  v1 = this;
  LayerSubmitContext::LayerSubmitContext((LayerSubmitContext *)&this->vfptr);
  v1->vfptr = (Illusion::SubmitContextVtbl *)&UFG::HighlightSubmitContext::`vftable;
  v1->mDiffuse2 = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mDepthEnabledRasterStateHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mDepthDisabledRasterStateHandle.mPrev);
  v2 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v2;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mDepthEnabledRasterStateHandle.mPrev,
    0x3BC715E0u,
    0x20688F05u,
    v2);
  v4 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mDepthDisabledRasterStateHandle.mPrev,
    0x3BC715E0u,
    0x62F81854u,
    v4);
}

// File Line: 83
// RVA: 0x6E6C0
Illusion::RenderQueue *__fastcall UFG::HighlightSubmitContext::OnPreSubmit(UFG::HighlightSubmitContext *this, UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream, UFG::BitFlags128 *already_called_funcs_mask)
{
  _QWORD *v3; // rax
  UFG::HighlightSubmitContext *v4; // rbx
  signed __int64 v5; // r9
  __int64 v6; // rcx
  UFG::BitFlags128 *v7; // rsi
  UFG::qMemoryStream<Illusion::Shader,1160> *v8; // rdi
  signed __int64 v9; // rcx
  __int64 v10; // rdx
  void *v11; // rcx
  UFG::qResourceData *v13; // rax
  signed __int64 v14; // rax
  void *v15; // rax
  Illusion::Texture *v16; // rax

  v3 = shader_stream->mMainMemoryAddress;
  v4 = this;
  v5 = 0i64;
  v6 = v3[13];
  v7 = already_called_funcs_mask;
  v8 = shader_stream;
  if ( v6 )
    v9 = (signed __int64)v3 + v6 + 104;
  else
    v9 = 0i64;
  v10 = v3[13];
  v11 = *(void **)(v9 + 144);
  if ( v10 )
    v5 = (signed __int64)v3 + v10 + 104;
  if ( !*(_BYTE *)(v5 + 192) )
  {
    if ( !v11 )
      return 0i64;
    goto LABEL_10;
  }
  if ( v11 )
  {
LABEL_10:
    v4->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
    v4->mStateValues.mParamValues[1] = v11;
    Illusion::SubmitContext::LoadShader((Illusion::SubmitContext *)&v4->vfptr, v8);
    v13 = Render::UberMaterial::GetCustomRenderPass()->mCustomRenderPass->mAlphaStateHandle.mData;
    v4->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
    v4->mStateValues.mParamValues[9] = v13;
  }
  v14 = (signed __int64)&v4->mDepthEnabledRasterStateHandle;
  if ( !v4->mIsDepthEnabled )
    v14 = (signed __int64)&v4->mDepthDisabledRasterStateHandle;
  v15 = *(void **)(v14 + 16);
  v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  v4->mStateValues.mParamValues[10] = v15;
  v16 = v4->mDiffuse2;
  v4->mStateValues.mSetValueMask.mFlags[0] |= 0x800000ui64;
  v4->mStateValues.mParamValues[23] = v16;
  Illusion::SubmitContext::ApplyShaderTemplate((Illusion::SubmitContext *)&v4->vfptr, v8);
  Illusion::SubmitContext::ApplyStateArgs((Illusion::SubmitContext *)&v4->vfptr, v8, v7);
  return LayerSubmitContext::ChooseRenderQueue((LayerSubmitContext *)&v4->vfptr, v8, v4->mCullMetrics);
}

// File Line: 127
// RVA: 0x1456F60
__int64 UFG::_dynamic_initializer_for__AlphaStateSourceRGBAlphaOne__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AlphaStateSourceRGBAlphaOne", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&AlphaStateSourceRGBAlphaOne, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__AlphaStateSourceRGBAlphaOne__);
}

// File Line: 132
// RVA: 0x6E400
UFG::ComponentIDDesc *__fastcall UFG::HighlightPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::HighlightPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::HighlightPostEffect::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::HighlightPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::HighlightPostEffect::_TypeIDesc.mChildren = 0;
    UFG::HighlightPostEffect::_DescInit = 1;
    UFG::HighlightPostEffect::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::HighlightPostEffect::_HighlightPostEffectTypeUID = v1 | (LOWORD(v3[0]) << 25);
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
  UFG::HighlightPostEffect *v1; // rdi
  char *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HighlightPostEffect::`vftable;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::HighlightPostEffect::_HighlightPostEffectTypeUID,
    "HighlightPostEffect");
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
void __fastcall UFG::HighlightPostEffect::SetHighlightParams(UFG::HighlightPostEffect *this, Render::View *view, UFG::HighlightParams *highlight_params)
{
  Render::View *v3; // rdi
  UFG::HighlightParams *v4; // rsi
  char *v5; // rax
  char *v6; // rbx
  Illusion::StateValues *v7; // rax

  v3 = view;
  v4 = highlight_params;
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *(float *)v5 = v4->mColour.r;
  v6 = v5;
  *((_DWORD *)v5 + 1) = LODWORD(v4->mColour.g);
  *((_DWORD *)v5 + 2) = LODWORD(v4->mColour.b);
  *((_DWORD *)v5 + 3) = LODWORD(v4->mColour.a);
  *((_DWORD *)v5 + 4) = LODWORD(v4->mXrayStrength);
  *((_DWORD *)v5 + 5) = LODWORD(v4->mOutlineStrength);
  v7 = Render::View::GetStateValues(v3);
  v7->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v7->mParamValues[15] = v6;
  LOBYTE(v3->mSubmitContext[1].mStateValues.mParamValues[10]) = v4->mIsDepthEnabled;
}

// File Line: 202
// RVA: 0x6E7E0
void __fastcall UFG::HighlightPostEffect::RenderHighlightObject(UFG::HighlightPostEffect *this, Render::View *view, UFG::SimObject *sim_object, UFG::HighlightComponent *highlight_component)
{
  UFG::HighlightComponent *v4; // rbp
  UFG::SimObject *v5; // rdi
  Render::View *v6; // rsi
  UFG::SimComponent *v7; // rax
  unsigned int v8; // ebx
  int v9; // eax
  UFG::SimComponent *v10; // rax
  Render::SimpleDrawableComponent *v11; // rbp
  UFG::SimComponent *v12; // rax
  UFG::DynamicSceneryInstance *v13; // rbp
  UFG::SceneObjectProperties *v14; // rdi
  UFG::SimObject *v15; // rax
  UFG::HighlightPostEffect *v16; // [rsp+40h] [rbp+8h]
  UFG::CompositeDrawableComponent *v17; // [rsp+50h] [rbp+18h]
  UFG::HighlightComponent *highlight_componenta; // [rsp+58h] [rbp+20h]

  highlight_componenta = highlight_component;
  v16 = this;
  v4 = highlight_component;
  v5 = sim_object;
  v6 = view;
  if ( sim_object )
  {
    v7 = UFG::SimObject::GetComponentOfType(sim_object, UFG::CompositeDrawableComponent::_TypeUID);
    v8 = 0;
    v17 = (UFG::CompositeDrawableComponent *)v7;
    if ( v7
      && (v6->mSettings->mCullIndex < 0 || *((_BYTE *)&v7[19].m_pSimObject->vfptr + v6->mSettings->mCullIndex) <= 1u) )
    {
      UFG::HighlightPostEffect::SetHighlightParams(v16, v6, &v4->mHighlightParams);
      v9 = UFG::CompositeDrawableComponent::GetMainViewLOD(v17);
      UFG::CompositeDrawableComponent::Draw(v17, v6, v9);
    }
    v10 = UFG::SimObject::GetComponentOfType(v5, Render::SimpleDrawableComponent::_TypeUID);
    if ( v10 )
    {
      v11 = (Render::SimpleDrawableComponent *)&v10[-1].m_pSimObject;
      if ( v10 != (UFG::SimComponent *)24
        && (v6->mSettings->mCullIndex < 0 || v11->mCullResults->mViewResult[v6->mSettings->mCullIndex] <= 1u) )
      {
        UFG::HighlightPostEffect::SetHighlightParams(v16, v6, &highlight_componenta->mHighlightParams);
        Render::SimpleDrawableComponent::Draw(v11, v6);
      }
    }
    v12 = UFG::SimObject::GetComponentOfType(v5, UFG::DynamicSceneryInstance::_TypeUID);
    if ( v12 )
    {
      v13 = (UFG::DynamicSceneryInstance *)&v12[-1].m_pSimObject;
      if ( v12 != (UFG::SimComponent *)24
        && (v6->mSettings->mCullIndex < 0 || v13->mCullResults->mViewResult[v6->mSettings->mCullIndex] <= 1u) )
      {
        UFG::HighlightPostEffect::SetHighlightParams(v16, v6, &highlight_componenta->mHighlightParams);
        UFG::DynamicSceneryInstance::Draw(v13, v6);
      }
    }
    v14 = v5->m_pSceneObj;
    v4 = highlight_componenta;
  }
  else
  {
    v8 = 0;
    v14 = 0i64;
  }
  if ( v14 && v14->mChildren.mCount )
  {
    do
    {
      v15 = UFG::SceneObjectProperties::GetChildAsSimObject(v14, v8);
      UFG::HighlightPostEffect::RenderHighlightObject(v16, v6, v15, v4);
      ++v8;
    }
    while ( v8 < v14->mChildren.mCount );
  }
}

// File Line: 237
// RVA: 0x6E990
void __fastcall UFG::HighlightPostEffect::RenderPostEffect(UFG::HighlightPostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  UFG::RenderContext *v6; // r14
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v7; // rbx
  UFG::HighlightPostEffect *v8; // rsi
  UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *v9; // rdi
  Illusion::eRenderPass::StaticPassData *v10; // rax
  Illusion::eRenderPass::StaticPassData *v11; // rax
  UFG::HighlightComponent *v12; // r8
  signed __int64 v13; // rbx
  Illusion::eRenderPass::StaticPassData *v14; // rax
  Illusion::eRenderPass::StaticPassData *v15; // rax
  UFG::HighlightComponent *v16; // r8
  signed __int64 v17; // rbx
  Illusion::Target *v18; // rcx
  Render::Poly poly; // [rsp+50h] [rbp-B0h]
  __int64 v20; // [rsp+58h] [rbp-A8h]
  Illusion::eRenderPass::CustomRenderPass v21; // [rsp+60h] [rbp-A0h]
  Illusion::eRenderPass::CustomRenderPass v22; // [rsp+D0h] [rbp-30h]
  RenderQueueLayer v23; // [rsp+140h] [rbp+40h]
  Render::View v24; // [rsp+220h] [rbp+120h]
  Render::View view; // [rsp+3B0h] [rbp+2B0h]
  LayerSubmitContext ptr; // [rsp+540h] [rbp+440h]
  UFG::HighlightSubmitContext v27; // [rsp+11C0h] [rbp+10C0h]

  v20 = -2i64;
  v6 = render_context;
  v7 = serialization_list;
  v8 = this;
  v9 = &UFG::HighlightComponent::s_HighlightComponentList - 4;
  if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != &UFG::HighlightComponent::s_HighlightComponentList - 4
    && render_context->mRenderFeatures.mWorld )
  {
    RenderQueueLayer::RenderQueueLayer(&v23);
    v23.mSerializationList = v7;
    UFG::HighlightSubmitContext::HighlightSubmitContext(&v27);
    v27.mRenderQueueProvider = &v23;
    v27.mQueueMode = 0;
    v27.mRenderPass = -1;
    v27.mDiffuse2 = (*curr_target)->mTargetTexture[0];
    LayerSubmitContext::LayerSubmitContext(&ptr);
    ptr.mRenderQueueProvider = &v23;
    ptr.mQueueMode = 0;
    v10 = Render::UberMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
      &v22,
      v10,
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
    Render::View::View(&view, &v6->mMainViewSettings, (Illusion::SubmitContext *)&v27.vfptr);
    Render::View::BeginTarget(&view, *scratch_target, "Outline", 0, 0, 0i64, 1, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::Black, 1u, 1.0, 1u);
    v12 = (UFG::HighlightComponent *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4];
    if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != v9 )
    {
      do
      {
        v13 = (signed __int64)&v12->mNext[-4];
        UFG::HighlightPostEffect::RenderHighlightObject(v8, &view, v12->m_pSimObject, v12);
        v12 = (UFG::HighlightComponent *)v13;
      }
      while ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)v13 != v9 );
    }
    Render::View::EndTarget(&view);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v21);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v22);
    Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
    Render::RenderUtilities::GaussBlur3x3(
      &Render::gRenderUtilities,
      *scratch_target,
      v6->mHalfSizeScratchTargetB,
      0,
      0i64,
      kGaussBlur3x3UID_15);
    Render::View::View(&v24, &v6->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v24, *scratch_target, "Highlight", 0, 0, 0i64, 1, 0, 0, 0);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v24, &poly, (*curr_target)->mTargetTexture[0]->mNode.mUID, 0i64, 0x62F81854u, 0x2782CCE6u);
    v24.mSubmitContext = (Illusion::SubmitContext *)&v27;
    v27.mDiffuse2 = v6->mHalfSizeScratchTargetB->mTargetTexture[0];
    ptr.mRenderPass = -1;
    v14 = Render::UberMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(&v21, v14, 0x70ADE623u, 0xA3833FDE, 0x62F81854u);
    v15 = Render::CharacterMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(&v22, v15, 0x9E92E2C2, 0xA3833FDE, 0x62F81854u);
    v16 = (UFG::HighlightComponent *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4];
    if ( (UFG::qList<UFG::HighlightComponent,UFG::HighlightComponent,1,0> *)&UFG::HighlightComponent::s_HighlightComponentList.mNode.mNext[-4] != v9 )
    {
      do
      {
        v17 = (signed __int64)&v16->mNext[-4];
        UFG::HighlightPostEffect::RenderHighlightObject(v8, &v24, v16->m_pSimObject, v16);
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
  UFG::qMemoryPool *v1; // rax
  char *v2; // rax
  UFG::SimObjectModifier v3; // [rsp+38h] [rbp-30h]

  UFG::SimObjectModifier::SimObjectModifier(&v3, UFG::RenderWorld::msRenderStagePlugin, 1);
  v1 = UFG::GetSimulationMemoryPool();
  v2 = UFG::qMemoryPool::Allocate(v1, 0x50ui64, "HighlightPostEffect", 0i64, 1u);
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
  bool result; // al

  if ( sim_object )
    result = UFG::SimObject::GetComponentOfType(sim_object, UFG::HighlightComponent::_TypeUID) != 0i64;
  else
    result = 0;
  return result;
}

// File Line: 327
// RVA: 0x6E560
void __fastcall UFG::HighlightSimObject(UFG::SimObject *sim_object, UFG::HighlightParams *highlight_params)
{
  UFG::HighlightParams *v2; // rsi
  UFG::SimObject *v3; // rdi
  UFG::HighlightComponent *v4; // rbx
  UFG::qMemoryPool *v5; // rax
  char *v6; // rax
  UFG::HighlightComponent *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v2 = highlight_params;
  v3 = sim_object;
  if ( !sim_object
    || (v4 = (UFG::HighlightComponent *)UFG::SimObject::GetComponentOfType(
                                          sim_object,
                                          UFG::HighlightComponent::_TypeUID)) == 0i64 )
  {
    v5 = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(v5, 0x70ui64, "HighlightComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::HighlightComponent::HighlightComponent((UFG::HighlightComponent *)v6);
      v4 = v7;
    }
    else
    {
      v4 = 0i64;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v11, v3, 1);
    UFG::SimObjectModifier::AttachComponent(&v11, (UFG::SimComponent *)&v4->vfptr, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v11);
    UFG::SimObjectModifier::~SimObjectModifier(&v11);
  }
  v4->mHighlightParams.mColour.r = v2->mColour.r;
  v4->mHighlightParams.mColour.g = v2->mColour.g;
  v4->mHighlightParams.mColour.b = v2->mColour.b;
  v4->mHighlightParams.mColour.a = v2->mColour.a;
  v4->mHighlightParams.mOutlineStrength = v2->mOutlineStrength;
  v4->mHighlightParams.mXrayStrength = v2->mXrayStrength;
  *(_DWORD *)&v4->mHighlightParams.mIsDepthEnabled = *(_DWORD *)&v2->mIsDepthEnabled;
  v8 = v4->mHighlightParams.mColour.g * v4->mHighlightParams.mColour.g;
  v9 = v4->mHighlightParams.mColour.b * v4->mHighlightParams.mColour.b;
  v10 = v4->mHighlightParams.mColour.a;
  v4->mHighlightParams.mColour.r = v4->mHighlightParams.mColour.r * v4->mHighlightParams.mColour.r;
  v4->mHighlightParams.mColour.g = v8;
  v4->mHighlightParams.mColour.b = v9;
  v4->mHighlightParams.mColour.a = v10;
}

// File Line: 342
// RVA: 0x6EE30
void __fastcall UFG::UnHighlightSimObject(UFG::SimObject *sim_object)
{
  UFG::SimObject *v1; // rbx
  UFG::SimComponent *v2; // rdi
  UFG::SimObjectModifier v3; // [rsp+28h] [rbp-30h]

  if ( sim_object )
  {
    v1 = sim_object;
    v2 = UFG::SimObject::GetComponentOfType(sim_object, UFG::HighlightComponent::_TypeUID);
    if ( v2 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v3, v1, 1);
      ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v3);
      UFG::SimObjectModifier::Close(&v3);
      UFG::SimObjectModifier::~SimObjectModifier(&v3);
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v2);
    }
  }
}

