// File Line: 101
// RVA: 0x154D980
__int64 dynamic_initializer_for__UFG::ActionTreeComponent::s_ActionTreeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionTreeComponent::s_ActionTreeComponentList__);
}

// File Line: 102
// RVA: 0x582A50
__int64 __fastcall UFG::ActionTreeComponent::GetTypeSize(UFG::ActionTreeComponent *this)
{
  return 1376i64;
}

// File Line: 124
// RVA: 0x57C1C0
void __fastcall UFG::ActionTreeComponent::ActionTreeComponent(
        UFG::ActionTreeComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        unsigned int name_uid,
        const char *actFileName)
{
  ActionContext *v7; // rbx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *mPrev; // rax
  UFG::allocator::free_link *v9; // rax
  ActionContext *v10; // rax
  UFG::qPropertySet *v11; // rax

  if ( pSceneObj )
    name_uid = pSceneObj->m_NameUID;
  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent>;
  this->mNext = &this->UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent>;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase, eACTION_TREE_TYPE_ACTION);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  v7 = 0i64;
  this->mActionTreeFileName = 0i64;
  ActionController::ActionController(&this->mActionController);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->mActiveAIEntityComponent);
  this->mPostAnimUpdateList.mNode.mPrev = &this->mPostAnimUpdateList.mNode;
  this->mPostAnimUpdateList.mNode.mNext = &this->mPostAnimUpdateList.mNode;
  Intention::Intention(&this->m_Intention);
  mPrev = UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev;
  UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&UFG::ActionTreeComponent::s_ActionTreeComponentList;
  UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent>;
  UFG::SimComponent::AddType(this, UFG::ActionTreeComponent::_ActionTreeComponentTypeUID, "ActionTreeComponent");
  once_4 = 0;
  this->mNisUpdated = 0;
  v9 = UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext", 0i64);
  if ( v9 )
  {
    ActionContext::ActionContext((ActionContext *)v9);
    v7 = v10;
  }
  this->mpActionContext = v7;
  if ( actFileName )
  {
    this->mActionTreeFileName = actFileName;
  }
  else if ( pSceneObj )
  {
    v11 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ActFileName);
    if ( v11 )
      this->mActionTreeFileName = (const char *)v11;
  }
  UFG::ActionTreeComponent::Reset(this);
}

// File Line: 250
// RVA: 0x57D390
void __fastcall UFG::ActionTreeComponent::~ActionTreeComponent(UFG::ActionTreeComponent *this)
{
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *mPrev; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *mNext; // rax
  UEL::ParametersBase *v5; // rbp
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  ActionContext *mpActionContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v14; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v15; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  if ( this == UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator )
    UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = (UFG::ActionTreeComponent *)&this->mPrev[-10].mNext;
  v2 = &this->UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = UEL::gCurrentParameters;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      else
        m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  ActionController::Stop(&this->mActionController);
  UEL::gCurrentParameters = v5;
  mpActionContext = this->mpActionContext;
  if ( mpActionContext )
  {
    if ( mpActionContext->mSimObject.m_pPointer )
    {
      v10 = mpActionContext->mSimObject.mPrev;
      v11 = mpActionContext->mSimObject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mpActionContext->mSimObject.mPrev = &mpActionContext->mSimObject;
      mpActionContext->mSimObject.mNext = &mpActionContext->mSimObject;
    }
    mpActionContext->mSimObject.m_pPointer = 0i64;
    v12 = mpActionContext->mSimObject.mPrev;
    v13 = mpActionContext->mSimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    mpActionContext->mSimObject.mPrev = &mpActionContext->mSimObject;
    mpActionContext->mSimObject.mNext = &mpActionContext->mSimObject;
    operator delete[](mpActionContext);
  }
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->mPostAnimUpdateList);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActiveAIEntityComponent);
  ActionController::~ActionController(&this->mActionController);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase);
  v14 = v2->mPrev;
  v15 = v2->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 277
// RVA: 0x588D40
UFG::ActionTreeComponent *__fastcall UFG::ActionTreeComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x560ui64, "ActionTreeComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v3, pSceneObj, 0, 0i64);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v8 = 7;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v8 = 6;
  }
  else
  {
    v8 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::ActionTreeComponent *)v5;
}

// File Line: 304
// RVA: 0x582D80
void __fastcall UFG::ActionTreeComponent::InitActionTree(UFG::ActionTreeComponent *this)
{
  const char *mActionTreeFileName; // rcx
  char *v3; // rax
  ActionContext *mpActionContext; // rax
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v6; // rdi
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v8; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  ActionContext::Reset(this->mpActionContext, eACTION_TREE_TYPE_ACTION, (UFG::SimObjectGame *)this->m_pSimObject);
  UFG::ActionTreeComponentBase::ResetMemory(&this->UFG::ActionTreeComponentBase);
  mActionTreeFileName = this->mActionTreeFileName;
  if ( mActionTreeFileName )
  {
    if ( *mActionTreeFileName )
    {
      this->mpActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(mActionTreeFileName);
      if ( !this->mpActionContext->m_OpeningBranch )
      {
        v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
        UFG::qPrintf(
          "WARNING: ActionTreeComponent::InitActionTree: Could Not Find Opening Branch: %s for SimObject: %s\n",
          this->mActionTreeFileName,
          v3);
      }
    }
  }
  mpActionContext = this->mpActionContext;
  this->mActionController.m_OnEnterExitCallbacksEnabled = 1;
  this->mActionController.m_Context = mpActionContext;
  mpActionContext->mActionController = &this->mActionController;
  m_OpeningBranch = this->mpActionContext->m_OpeningBranch;
  if ( m_OpeningBranch )
  {
    v6 = (ActionNodeRoot *)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch);
    if ( UFG::ActionTreeComponentBase::AllocateFor(&this->UFG::ActionTreeComponentBase, v6) )
      ActionNodeRoot::Init(v6, this->mpActionContext);
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    v8 = UEL::gCurrentParameters;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::UELComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      if ( m_pComponent )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&m_pComponent[1].m_TypeUID;
    }
    ActionController::Play(&this->mActionController, (ActionNodePlayable *)this->mpActionContext->m_OpeningBranch, 0);
    UEL::gCurrentParameters = v8;
  }
}

// File Line: 358
// RVA: 0x585F80
void __fastcall UFG::ActionTreeComponent::OnAttach(UFG::ActionTreeComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::allocator::free_link *v13; // [rsp+40h] [rbp+8h]

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::UELComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      v13 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      m_pComponent[2].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v13;
      v13->mNext = (UFG::allocator::free_link *)&this->m_Intention.mMotionIntentionDirection;
      m_pComponent[2].m_BoundComponentHandles.mNode.mNext->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->m_Intention.mMotionIntentionSpeed;
      m_pComponent[2].m_BoundComponentHandles.mNode.mNext[1].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->m_Intention.mActionRequests;
    }
  }
  UFG::ActionTreeComponent::InitActionTree(this);
  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_mActiveAIEntityComponent->mPrev;
    mNext = this->mActiveAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_20:
    this->mActiveAIEntityComponent.m_pSimObject = 0i64;
    this->mActiveAIEntityComponent.mNext = &this->mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_21;
  }
  if ( this->mActiveAIEntityComponent.m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || this->mActiveAIEntityComponent.mNext != &this->mActiveAIEntityComponent) )
  {
    v11 = p_mActiveAIEntityComponent->mPrev;
    v12 = this->mActiveAIEntityComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_20;
  }
LABEL_21:
  this->mActiveAIEntityComponent.m_Changed = 1;
  this->mActiveAIEntityComponent.m_pSimObject = object;
  this->mActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &this->mActiveAIEntityComponent,
    object);
}

// File Line: 384
// RVA: 0x586860
void __fastcall UFG::ActionTreeComponent::OnDetach(UFG::ActionTreeComponent *this)
{
  UEL::ParametersBase *v1; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::SimComponent *v8; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax

  v1 = UEL::gCurrentParameters;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      else
        m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  ActionController::Stop(&this->mActionController);
  UEL::gCurrentParameters = v1;
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      v8 = v6->m_Components.p->m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 )
      {
        v8 = v6->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (v7 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::UELComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, UFG::UELComponent::_TypeUID);
        v8 = ComponentOfTypeHK;
      }
    }
    else
    {
      v8 = v6->m_Components.p->m_pComponent;
    }
    if ( v8 )
    {
      operator delete[](v8[2].m_BoundComponentHandles.mNode.mNext);
      v8[2].m_BoundComponentHandles.mNode.mNext = 0i64;
    }
  }
  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_mActiveAIEntityComponent->mPrev;
    mNext = this->mActiveAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_32:
    this->mActiveAIEntityComponent.m_pSimObject = 0i64;
    this->mActiveAIEntityComponent.mNext = &this->mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_33;
  }
  if ( this->mActiveAIEntityComponent.m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || this->mActiveAIEntityComponent.mNext != &this->mActiveAIEntityComponent) )
  {
    v13 = p_mActiveAIEntityComponent->mPrev;
    v14 = this->mActiveAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_32;
  }
LABEL_33:
  this->mActiveAIEntityComponent.m_Changed = 1;
}

// File Line: 434
// RVA: 0x58B060
void __fastcall UFG::ActionTreeComponent::Reset(UFG::ActionTreeComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v3; // rdi
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  ActionContext *mpActionContext; // rcx
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v8; // rsi
  UFG::SimObjectGame *v9; // rcx
  UEL::ParametersBase *v10; // rdi
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  Intention::Clear(&this->m_Intention);
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v3 = UEL::gCurrentParameters;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      else
        m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  ActionController::Stop(&this->mActionController);
  UEL::gCurrentParameters = v3;
  UFG::ActionTreeComponentBase::ResetMemory(&this->UFG::ActionTreeComponentBase);
  mpActionContext = this->mpActionContext;
  if ( mpActionContext )
  {
    m_OpeningBranch = mpActionContext->m_OpeningBranch;
    if ( m_OpeningBranch )
    {
      v8 = (ActionNodeRoot *)((__int64 (*)(void))m_OpeningBranch->vfptr[1].GetResourceOwner)();
      if ( UFG::ActionTreeComponentBase::AllocateFor(&this->UFG::ActionTreeComponentBase, v8) )
        ActionNodeRoot::Init(v8, this->mpActionContext);
      v9 = (UFG::SimObjectGame *)this->m_pSimObject;
      v10 = UEL::gCurrentParameters;
      if ( v9 )
      {
        v11 = v9->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = v9->m_Components.p->m_pComponent;
        }
        else if ( v11 >= 0 )
        {
          if ( (v11 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = v9->m_Components.p->m_pComponent;
          }
          else if ( (v11 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::UELComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfTypeHK = v9->m_Components.p->m_pComponent;
        }
        if ( ComponentOfTypeHK )
          UEL::gCurrentParameters = (UEL::ParametersBase *)&ComponentOfTypeHK[1].m_TypeUID;
      }
      ActionController::Play(&this->mActionController, (ActionNodePlayable *)this->mpActionContext->m_OpeningBranch, 0);
      UEL::gCurrentParameters = v10;
    }
  }
  this->m_Flags &= ~2u;
}

// File Line: 475
// RVA: 0x57F450
void __fastcall UFG::ActionTreeComponent::BeginFrame(UFG::ActionTreeComponent *this)
{
  Intention::Clear(&this->m_Intention);
  UFG::ActionTreeComponent::sDebugDisplayCount = 0;
}

// File Line: 482
// RVA: 0x58C9B0
void __fastcall UFG::ActionTreeComponent::TeleportEventHandler(UFG::ActionTreeComponent *this, UFG::Event *this_event)
{
  float v2; // xmm5_4
  __m128 m_EventUID; // xmm4
  float v4; // xmm2_4
  float v5; // xmm6_4
  __m128 v6; // xmm3
  float v7; // xmm6_4
  float v8; // xmm4_4
  float v9; // xmm5_4

  v2 = *((float *)&this_event[1].m_EventUID + 1);
  m_EventUID = (__m128)this_event[1].m_EventUID;
  v6 = m_EventUID;
  v4 = 0.0;
  v5 = *(float *)&this_event[1].m_NamePTR;
  v6.m128_f32[0] = (float)((float)(m_EventUID.m128_f32[0] * m_EventUID.m128_f32[0]) + (float)(v2 * v2))
                 + (float)(v5 * v5);
  if ( v6.m128_f32[0] != 0.0 )
    v4 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  v7 = v5 * v4;
  v8 = m_EventUID.m128_f32[0] * v4;
  v9 = v2 * v4;
  this->m_Intention.mFacingIntentionDirection.z = v7;
  this->m_Intention.mFacingIntentionDirection.x = v8;
  this->m_Intention.mFacingIntentionDirection.y = v9;
  this->m_Intention.mMotionIntentionDirection.z = v7;
  this->m_Intention.mMotionIntentionDirection.x = v8;
  this->m_Intention.mMotionIntentionDirection.y = v9;
}

// File Line: 528
// RVA: 0x5909C0
void __fastcall UFG::ActionTreeComponent::UpdateNIS(UFG::ActionTreeComponent *this, float delta_sec)
{
  if ( this->mNisUpdated )
    ((void (__fastcall *)(UFG::ActionTreeComponent *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[18].__vecDelDtor)(this);
}

// File Line: 535
// RVA: 0x5925A0
void __fastcall UFG::ActionTreeComponent::update(UFG::ActionTreeComponent *this, float delta_sec)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v4; // rsi
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    v4 = UEL::gCurrentParameters;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
        else
          m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pSimObject,
                                                   UFG::UELComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   m_pSimObject,
                                                   UFG::UELComponent::_TypeUID));
      }
      else
      {
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      }
      if ( m_pComponent )
        UEL::gCurrentParameters = m_pComponent + 0x58;
    }
    ActionController::Update(&this->mActionController, delta_sec);
    m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
    if ( m_pSimComponent
      && (*((_BYTE *)&m_pSimComponent[65].m_SimObjIndex + 5) || LOBYTE(m_pSimComponent[65].m_pSimObject)) )
    {
      ActionController::Update(&this->mActionController, 0.0);
    }
    UEL::gCurrentParameters = v4;
  }
}

// File Line: 792
// RVA: 0x58D960
void __fastcall UFG::ActionTreeComponent::UpdateAll(float deltaTime)
{
  unsigned __int64 Ticks; // rdi
  UFG::ActionTreeComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::ActionTreeComponent *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  for ( UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = (UFG::ActionTreeComponent *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
        p_mNext != (UFG::ActionTreeComponent *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152);
        UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 && !p_mNext->mNisUpdated )
    {
      ((void (__fastcall *)(UFG::ActionTreeComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[18].__vecDelDtor)(p_mNext);
      p_mNext = UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator;
    }
    p_mNext = (UFG::ActionTreeComponent *)&p_mNext->mNext[-10].mNext;
  }
  UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 805
// RVA: 0x57EF20
void __fastcall UFG::ActionTreeComponent::AddPostAnimUpdateTask(
        UFG::ActionTreeComponent *this,
        PostAnimUpdateTask *postAnimUpdateTask)
{
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v2; // rdx
  UFG::qList<PostAnimUpdateTask,PostAnimUpdateTaskList,0,0> *p_mPostAnimUpdateList; // rcx
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *mPrev; // rax

  v2 = &postAnimUpdateTask->UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>;
  p_mPostAnimUpdateList = &this->mPostAnimUpdateList;
  mPrev = p_mPostAnimUpdateList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_mPostAnimUpdateList->mNode;
  p_mPostAnimUpdateList->mNode.mPrev = v2;
}

// File Line: 812
// RVA: 0x588770
void __fastcall UFG::ActionTreeComponent::PostAnimUpdate(UFG::ActionTreeComponent *this, float delta_sec)
{
  UEL::ParametersBase *v2; // rsi
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  unsigned int *p_m_Changed; // rdi
  UFG::ActionTreeComponent *p_mNext; // rcx
  __int64 v9; // rbx

  v2 = UEL::gCurrentParameters;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      else
        m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  p_m_Changed = &this->mActiveAIEntityComponent.m_Changed;
  p_mNext = (UFG::ActionTreeComponent *)&this->mPostAnimUpdateList.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::ActionTreeComponent *)&this->mActiveAIEntityComponent.m_Changed )
  {
    do
    {
      v9 = (__int64)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
      ((void (__fastcall *)(UFG::ActionTreeComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor)(p_mNext);
      p_mNext = (UFG::ActionTreeComponent *)v9;
    }
    while ( (unsigned int *)v9 != p_m_Changed );
  }
  UEL::gCurrentParameters = v2;
}

