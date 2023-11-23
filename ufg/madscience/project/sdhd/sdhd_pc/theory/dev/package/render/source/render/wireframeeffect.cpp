// File Line: 44
// RVA: 0x6EFE0
UFG::ComponentIDDesc *__fastcall UFG::WireframeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::WireframeComponent::_DescInit )
  {
    UFG::WireframeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::WireframeComponent::_DescInit = 1;
    UFG::WireframeComponent::_TypeUID = UFG::WireframeComponent::_TypeIDesc.mChildBitMask | (UFG::WireframeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WireframeComponent::_WireframeComponentTypeUID = UFG::WireframeComponent::_TypeIDesc.mChildBitMask | (UFG::WireframeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WireframeComponent::_TypeIDesc;
}

// File Line: 59
// RVA: 0x1456FE0
__int64 dynamic_initializer_for__UFG::WireframeComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::WireframeComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::WireframeComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::WireframeComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::WireframeComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 60
// RVA: 0x1457040
__int64 dynamic_initializer_for__UFG::WireframeComponent::s_WireframeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WireframeComponent::s_WireframeComponentList__);
}

// File Line: 74
// RVA: 0x6F190
Illusion::RenderQueue *__fastcall UFG::WireframeSubmitContext::OnPreSubmit(
        UFG::WireframeSubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::SubmitContext::ApplyShaderTemplate(this, shader_stream);
  Illusion::SubmitContext::ApplyStateArgs(this, shader_stream, already_called_funcs_mask);
  return LayerSubmitContext::ChooseRenderQueue(this, shader_stream, this->mCullMetrics);
}

// File Line: 107
// RVA: 0x14570A0
__int64 UFG::_dynamic_initializer_for__ShaderWireframe__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("WIREFRAME", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&ShaderWireframe, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ShaderWireframe__);
}

// File Line: 108
// RVA: 0x1457060
__int64 UFG::_dynamic_initializer_for__RasterStateWireframe__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RasterStateWireframe", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RasterStateWireframe, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RasterStateWireframe__);
}

// File Line: 113
// RVA: 0x6F050
UFG::ComponentIDDesc *__fastcall UFG::WireframePostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::WireframePostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::WireframePostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::WireframePostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::WireframePostEffect::_TypeIDesc.mChildren = 0;
    UFG::WireframePostEffect::_DescInit = 1;
    UFG::WireframePostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::WireframePostEffect::_WireframePostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::WireframePostEffect::_TypeIDesc;
}

// File Line: 126
// RVA: 0x6F170
UFG::ComponentIDDesc *__fastcall UFG::WireframePostEffect::GetDesc(UFG::WireframePostEffect *this)
{
  return &UFG::WireframePostEffect::_TypeIDesc;
}

// File Line: 129
// RVA: 0x6EEB0
void __fastcall UFG::WireframePostEffect::WireframePostEffect(UFG::WireframePostEffect *this)
{
  char *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WireframePostEffect::`vftable;
  UFG::SimComponent::AddType(this, UFG::WireframePostEffect::_WireframePostEffectTypeUID, "WireframePostEffect");
  this->mDefaultColour.r = UFG::qColour::Grey.r;
  this->mDefaultColour.g = UFG::qColour::Grey.g;
  this->mDefaultColour.b = UFG::qColour::Grey.b;
  this->mDefaultColour.a = 0.5;
  if ( !sIsStaticInit_3 )
  {
    v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&RasterStateWireframe);
    v3 = Illusion::Factory::NewRasterState(v2, RasterStateWireframe.mUID, 0i64, 0i64, 0i64);
    LOWORD(v3[1].mNode.mParent) = 1;
    BYTE3(v3[1].mNode.mParent) = 0;
    BYTE2(v3[1].mNode.mUID) = 1;
    v4 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v4, v3);
    sIsStaticInit_3 = 1;
  }
}

// File Line: 160
// RVA: 0x6F500
void __fastcall UFG::WireframePostEffect::RenderWireframeObject(
        UFG::WireframePostEffect *this,
        Render::View *view,
        UFG::SimObject *sim_object)
{
  UFG::CompositeDrawableComponent *ComponentOfType; // rax
  UFG::CompositeDrawableComponent *v7; // rbx
  unsigned int MainViewLOD; // eax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rax
  unsigned int v11; // ebx
  UFG::DynamicSceneryInstance *p_m_pSimObject; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::SimObject *ChildAsSimObject; // rax

  if ( sim_object )
  {
    UFG::SimObject::GetComponentOfType(sim_object, UFG::WireframeComponent::_TypeUID);
    ComponentOfType = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                           sim_object,
                                                           UFG::CompositeDrawableComponent::_TypeUID);
    v7 = ComponentOfType;
    if ( ComponentOfType )
    {
      MainViewLOD = (unsigned int)UFG::CompositeDrawableComponent::GetMainViewLOD(ComponentOfType);
      UFG::CompositeDrawableComponent::Draw(v7, view, MainViewLOD);
    }
    v9 = UFG::SimObject::GetComponentOfType(sim_object, Render::SimpleDrawableComponent::_TypeUID);
    if ( v9 && v9 != (UFG::SimComponent *)24 )
      Render::SimpleDrawableComponent::Draw((Render::SimpleDrawableComponent *)&v9[-1].m_pSimObject, view);
    v10 = UFG::SimObject::GetComponentOfType(sim_object, UFG::DynamicSceneryInstance::_TypeUID);
    v11 = 0;
    if ( v10 )
    {
      p_m_pSimObject = (UFG::DynamicSceneryInstance *)&v10[-1].m_pSimObject;
      if ( v10 != (UFG::SimComponent *)24
        && (view->mSettings->mCullIndex < 0
         || p_m_pSimObject->mCullResults->mViewResult[view->mSettings->mCullIndex] <= 1u) )
      {
        UFG::DynamicSceneryInstance::Draw(p_m_pSimObject, view);
      }
    }
    m_pSceneObj = sim_object->m_pSceneObj;
  }
  else
  {
    v11 = 0;
    m_pSceneObj = 0i64;
  }
  if ( m_pSceneObj && m_pSceneObj->mChildren.mCount )
  {
    do
    {
      ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject(m_pSceneObj, v11);
      UFG::WireframePostEffect::RenderWireframeObject(this, view, ChildAsSimObject);
      ++v11;
    }
    while ( v11 < m_pSceneObj->mChildren.mCount );
  }
}

// File Line: 193
// RVA: 0x6F1E0
void __fastcall UFG::WireframePostEffect::RenderCompositePass(
        UFG::WireframePostEffect *this,
        Render::View *view,
        UFG::RenderContext *render_context)
{
  UFG::qList<UFG::WireframeComponent,UFG::WireframeComponent,1,0> *v6; // r15
  Illusion::SubmitContext *mSubmitContext; // r12
  Illusion::eRenderPass::StaticPassData *CustomRenderPass; // rax
  Illusion::eRenderPass::StaticPassData *v9; // rax
  char *v10; // rbx
  Illusion::StateValues *StateValues; // rax
  __int64 mCullIndex; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v14; // rbx
  unsigned int v15; // edi
  __int64 v16; // rdx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v17; // rcx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v18; // rbx
  unsigned int v19; // edi
  UFG::qNode<UFG::WireframeComponent,UFG::WireframeComponent> *v20; // rbp
  __int64 v21; // rdi
  char *v22; // rbx
  Illusion::StateValues *v23; // rax
  Illusion::eRenderPass::CustomRenderPass v24; // [rsp+40h] [rbp-D88h] BYREF
  Illusion::eRenderPass::CustomRenderPass v25; // [rsp+B0h] [rbp-D18h] BYREF
  LayerSubmitContext ptr; // [rsp+120h] [rbp-CA8h] BYREF

  v6 = &UFG::WireframeComponent::s_WireframeComponentList - 4;
  if ( (UFG::qList<UFG::WireframeComponent,UFG::WireframeComponent,1,0> *)&UFG::WireframeComponent::s_WireframeComponentList.mNode.mNext[-4] != &UFG::WireframeComponent::s_WireframeComponentList - 4
    || render_context->mRenderFeatures.mWireframeScenery )
  {
    mSubmitContext = view->mSubmitContext;
    LayerSubmitContext::LayerSubmitContext(&ptr);
    ptr.vfptr = (Illusion::SubmitContextVtbl *)&UFG::WireframeSubmitContext::`vftable;
    ptr.mQueueMode = QM_Single;
    ptr.mRenderPass = Custom;
    ptr.mRenderQueueProvider = (RenderQueueLayer *)mSubmitContext[1].mStateValues.mParamValues[0];
    view->mSubmitContext = &ptr;
    CustomRenderPass = Render::UberMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
      &v25,
      CustomRenderPass,
      ShaderWireframe.mUID,
      0xA3833FDE,
      RasterStateWireframe.mUID);
    v9 = Render::CharacterMaterial::GetCustomRenderPass();
    Illusion::eRenderPass::CustomRenderPass::CustomRenderPass(
      &v24,
      v9,
      ShaderWireframe.mUID,
      0xA3833FDE,
      RasterStateWireframe.mUID);
    v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    UFG::qMemCopy(v10, &this->mDefaultColour, 0x10u);
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
    StateValues->mParamValues[15] = v10;
    if ( render_context->mRenderFeatures.mWireframeScenery )
    {
      mCullIndex = render_context->mMainViewSettings.mCullIndex;
      if ( (int)mCullIndex >= 0
        && (int)mCullIndex <= 16
        && Render::SimpleDrawableComponent::mDefaultCullLayer->mDrawEnabled )
      {
        mHead = Render::SimpleDrawableComponent::mDefaultCullLayer->mCullResultBuckets[mCullIndex].mHead;
      }
      else
      {
        mHead = 0i64;
      }
      v14 = mHead;
      v15 = 0;
      while ( v14 )
      {
        UFG::WireframePostEffect::RenderWireframeObject(this, view, (UFG::SimObject *)v14[v15++ + 3].mNext[8].mNext);
        if ( v15 == LODWORD(v14[1].mNext) )
        {
          v14 = v14->mNext;
          v15 = 0;
        }
      }
      v16 = render_context->mMainViewSettings.mCullIndex;
      if ( (int)v16 >= 0 && (int)v16 <= 16 && UFG::CompositeDrawableComponent::mDefaultCullLayer->mDrawEnabled )
        v17 = UFG::CompositeDrawableComponent::mDefaultCullLayer->mCullResultBuckets[v16].mHead;
      else
        v17 = 0i64;
      v18 = v17;
      v19 = 0;
      while ( v18 )
      {
        UFG::WireframePostEffect::RenderWireframeObject(this, view, (UFG::SimObject *)v18[v19++ + 3].mNext[5].mNext);
        if ( v19 == LODWORD(v18[1].mNext) )
        {
          v18 = v18->mNext;
          v19 = 0;
        }
      }
    }
    else
    {
      v20 = UFG::WireframeComponent::s_WireframeComponentList.mNode.mNext - 4;
      if ( (UFG::qList<UFG::WireframeComponent,UFG::WireframeComponent,1,0> *)&UFG::WireframeComponent::s_WireframeComponentList.mNode.mNext[-4] != v6 )
      {
        do
        {
          v21 = (__int64)&v20[4].mNext[-4];
          v22 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
          UFG::qMemCopy(v22, &v20[5], 0x10u);
          v23 = Render::View::GetStateValues(view);
          v23->mSetValueMask.mFlags[0] |= 0x8000ui64;
          v23->mParamValues[15] = v22;
          UFG::WireframePostEffect::RenderWireframeObject(this, view, (UFG::SimObject *)v20[2].mNext);
          v20 = (UFG::qNode<UFG::WireframeComponent,UFG::WireframeComponent> *)v21;
        }
        while ( (UFG::qList<UFG::WireframeComponent,UFG::WireframeComponent,1,0> *)v21 != v6 );
      }
    }
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v24);
    Illusion::eRenderPass::CustomRenderPass::~CustomRenderPass(&v25);
    view->mSubmitContext = mSubmitContext;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 251
// RVA: 0x6F0E0
void __fastcall UFG::CreateWireframePlugin(UFG *this)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v2; // rax
  UFG::SimObjectModifier v3; // [rsp+38h] [rbp-30h] BYREF

  UFG::SimObjectModifier::SimObjectModifier(&v3, UFG::RenderWorld::msRenderStagePlugin, 1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v2 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x60ui64, "WireframePostEffect", 0i64, 1u);
  if ( v2 )
    UFG::WireframePostEffect::WireframePostEffect((UFG::WireframePostEffect *)v2);
  UFG::SimObjectModifier::AttachComponent(&v3, (UFG::SimComponent *)v2, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v3);
  UFG::SimObjectModifier::~SimObjectModifier(&v3);
}

// File Line: 275
// RVA: 0x6F620
void __fastcall UFG::UnWireframeSimObject(UFG::SimObject *sim_object)
{
  UFG::SimComponent *ComponentOfType; // rdi
  ArrayOfTuplesImplementation v3; // [rsp+28h] [rbp-30h] BYREF

  if ( sim_object )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::WireframeComponent::_TypeUID);
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

