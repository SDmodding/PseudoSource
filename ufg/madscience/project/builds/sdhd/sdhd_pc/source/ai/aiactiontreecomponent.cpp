// File Line: 87
// RVA: 0x14AE9C0
__int64 dynamic_initializer_for__UFG::AIActionTreeComponent::s_AIActionTreeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIActionTreeComponent::s_AIActionTreeComponentList__);
}

// File Line: 88
// RVA: 0x3632A0
const char *__fastcall UFG::AIActionTreeComponent::GetTypeName(UFG::AIActionTreeComponent *this)
{
  return "AIActionTreeComponent";
}

// File Line: 98
// RVA: 0x37E720
UFG::AIActionTreeComponent *__fastcall UFG::AIActionTreeComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::AIActionTreeComponent *result; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_AIActionTree::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::AIActionTreeComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( required || result )
  {
    v8 = (char *)result->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr
       + (unsigned __int64)result;
    if ( !result->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr )
      v8 = 0i64;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x678ui64, "AIActionTreeComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::AIActionTreeComponent::AIActionTreeComponent((UFG::AIActionTreeComponent *)v10, pSceneObj->m_NameUID, v8);
      v6 = v11;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v14 = 19;
    else
      v14 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
    UFG::SimObjectModifier::Close(&v15);
    UFG::SimObjectModifier::~SimObjectModifier(&v15);
    return (UFG::AIActionTreeComponent *)v6;
  }
  return result;
}

// File Line: 118
// RVA: 0x32A690
void __fastcall UFG::AIActionTreeComponent::AIActionTreeComponent(
        UFG::AIActionTreeComponent *this,
        unsigned int name_uid,
        const char *actName)
{
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  this->mAutoActivate = 1;
  this->mAge = 0.0;
  this->mPrev = &this->UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent>;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase, eACTION_TREE_TYPE_AI);
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::StateInterface};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::AIActionTreeComponent::`vftable;
  UFG::qSharedString::qSharedString(&this->m_ActionTreeFileName);
  ActionController::ActionController(&this->m_ActionController);
  this->m_Ticket.mPrev = &this->m_Ticket;
  this->m_Ticket.mNext = &this->m_Ticket;
  this->m_Ticket.mTimestamp = 0i64;
  this->m_Ticket.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->m_Ticket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_Ticket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->m_Ticket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  Intention::Intention(&this->m_LastFrameIntentions);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&this->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&this->m_pNavComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0>::RebindingComponentHandle<UFG::FaceActionComponent,0>(&this->m_pFaceActionComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&this->m_pInterestPointUserComponent);
  mPrev = UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev;
  UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&UFG::AIActionTreeComponent::s_AIActionTreeComponentList;
  UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent>;
  UFG::SimComponent::AddType(this, UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID, "AIActionTreeComponent");
  UFG::AIActionTreeComponent::SetActionTreeFileName(this, actName);
  UFG::AIActionTreeComponent::Init(this);
}

// File Line: 128
// RVA: 0x3651B0
void __fastcall UFG::AIActionTreeComponent::Init(UFG::AIActionTreeComponent *this)
{
  UFG::allocator::free_link *v2; // rax

  *(_WORD *)&this->m_DebugDisplay = 0;
  v2 = UFG::qMalloc(0xD8ui64, "AIAIActionTreeComponent::ActionContext", 0i64);
  if ( v2 )
    ActionContext::ActionContext((ActionContext *)v2);
  this->m_pActionContext = (ActionContext *)v2;
  *(_WORD *)&this->m_ActionController.m_BankTracksEnabled = 257;
  Intention::Clear(&this->m_LastFrameIntentions);
  this->m_LastFrameEmotion = eAI_EMOTION_NONE;
  *(_WORD *)&this->m_LastFrameHasDestination = 0;
  this->m_TicketType = NUM_TICKETBOOTHS;
  this->m_LastSimFrameUpdated = -1;
}

// File Line: 156
// RVA: 0x333710
void __fastcall UFG::AIActionTreeComponent::~AIActionTreeComponent(UFG::AIActionTreeComponent *this)
{
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *mPrev; // rcx
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *mNext; // rax
  UEL::ParametersBase *v5; // rbp
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  ActionContext *m_pActionContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v14; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v15; // rax
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v16; // rcx
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v17; // rax

  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::StateInterface};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::AIActionTreeComponent::`vftable;
  if ( this == UFG::AIActionTreeComponent::s_AIActionTreeComponentpCurrentIterator )
    UFG::AIActionTreeComponent::s_AIActionTreeComponentpCurrentIterator = (UFG::AIActionTreeComponent *)&this->mPrev[-11].mNext;
  v2 = &this->UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent>;
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
  ActionController::Stop(&this->m_ActionController);
  UEL::gCurrentParameters = v5;
  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    if ( m_pActionContext->mSimObject.m_pPointer )
    {
      v10 = m_pActionContext->mSimObject.mPrev;
      v11 = m_pActionContext->mSimObject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      m_pActionContext->mSimObject.mPrev = &m_pActionContext->mSimObject;
      m_pActionContext->mSimObject.mNext = &m_pActionContext->mSimObject;
    }
    m_pActionContext->mSimObject.m_pPointer = 0i64;
    v12 = m_pActionContext->mSimObject.mPrev;
    v13 = m_pActionContext->mSimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    m_pActionContext->mSimObject.mPrev = &m_pActionContext->mSimObject;
    m_pActionContext->mSimObject.mNext = &m_pActionContext->mSimObject;
    operator delete[](m_pActionContext);
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pFaceActionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pNavComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAICharacterControllerBaseComponent);
  v14 = this->m_Ticket.mPrev;
  v15 = this->m_Ticket.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->m_Ticket.mPrev = &this->m_Ticket;
  this->m_Ticket.mNext = &this->m_Ticket;
  ActionController::~ActionController(&this->m_ActionController);
  UFG::qSharedString::~qSharedString(&this->m_ActionTreeFileName);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase);
  v16 = v2->mPrev;
  v17 = v2->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (this->m_Flags & 4) != 0 )
  {
    this->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AIActionTreeComponent *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
    this->m_Flags &= ~4u;
  }
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 191
// RVA: 0x382F90
void __fastcall UFG::AIActionTreeComponent::ResetDefaultTree(UFG::AIActionTreeComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v4; // rax
  char *MemImagePtr; // rax
  const char *v6; // rdx

  ((void (__fastcall *)(UFG::AIActionTreeComponent *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[18].__vecDelDtor)(this);
  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_AIActionTree::sPropertyName,
         DEPTH_RECURSE);
  if ( v4 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v4);
    if ( MemImagePtr )
    {
      if ( *(_QWORD *)MemImagePtr )
        v6 = &MemImagePtr[*(_QWORD *)MemImagePtr];
      else
        v6 = 0i64;
      UFG::AIActionTreeComponent::SetActionTreeFileName(this, v6);
    }
  }
  UFG::AIActionTreeComponent::InitActionTree(this);
}

// File Line: 212
// RVA: 0x380B80
void __fastcall UFG::AIActionTreeComponent::ReleaseActionTree(UFG::AIActionTreeComponent *this)
{
  UEL::ParametersBase *v1; // rdi
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  v1 = UEL::gCurrentParameters;
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
  ActionController::Stop(&this->m_ActionController);
  UEL::gCurrentParameters = v1;
}

// File Line: 242
// RVA: 0x366A20
void __fastcall UFG::AIActionTreeComponent::InitActionTree(UFG::AIActionTreeComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::GetInFormationComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::HasAttackRequestComponent *v11; // rax
  ActionContext *m_pActionContext; // rax
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v14; // rbx
  UFG::SimObjectGame *v15; // rcx
  UEL::ParametersBase *v16; // rbx
  __int16 v17; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[11].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::StimulusReceiverComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StimulusReceiverComponent::_TypeUID);
      m_pComponent = v5;
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[11].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::StimulusReceiverComponent::UnrequestAllStimuli((UFG::StimulusReceiverComponent *)m_pComponent);
      UFG::StimulusReceiverComponent::DeregisterCallbacks((UFG::StimulusReceiverComponent *)m_pComponent);
      *(_QWORD *)&m_pComponent[1].m_Flags = 0i64;
      m_pComponent[1].m_pSimObject = 0i64;
      UFG::qMemSet(&m_pComponent[1].m_BoundComponentHandles, 0, 0x3A0u);
      *(_DWORD *)(&m_pComponent[16].m_SimObjIndex + 1) = -943501440;
    }
  }
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 & 0x4000) != 0 )
      v8 = (UFG::GetInFormationComponent *)v6->m_Components.p[32].m_pComponent;
    else
      v8 = (UFG::GetInFormationComponent *)(v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v6,
                                              UFG::GetInFormationComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              v6,
                                              UFG::GetInFormationComponent::_TypeUID));
    if ( v8 )
      UFG::GetInPedFormationComponent::DeleteList(v8);
  }
  v9 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 )
      v11 = (UFG::HasAttackRequestComponent *)v9->m_Components.p[35].m_pComponent;
    else
      v11 = (UFG::HasAttackRequestComponent *)(v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v9,
                                                 UFG::HasAttackRequestComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v9,
                                                 UFG::HasAttackRequestComponent::_TypeUID));
    if ( v11 )
      UFG::HasAttackRequestComponent::Reset(v11);
  }
  UFG::ActionTreeComponentBase::ResetMemory(&this->UFG::ActionTreeComponentBase);
  ActionContext::Reset(this->m_pActionContext, eACTION_TREE_TYPE_AI, (UFG::SimObjectGame *)this->m_pSimObject);
  this->m_pActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(this->m_ActionTreeFileName.mText);
  m_pActionContext = this->m_pActionContext;
  this->m_ActionController.m_Context = m_pActionContext;
  m_pActionContext->mActionController = &this->m_ActionController;
  m_OpeningBranch = this->m_pActionContext->m_OpeningBranch;
  if ( m_OpeningBranch )
  {
    v14 = (ActionNodeRoot *)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch);
    if ( UFG::ActionTreeComponentBase::AllocateFor(&this->UFG::ActionTreeComponentBase, v14) )
      ActionNodeRoot::Init(v14, this->m_pActionContext);
    v15 = (UFG::SimObjectGame *)this->m_pSimObject;
    v16 = UEL::gCurrentParameters;
    if ( v15 )
    {
      v17 = v15->m_Flags;
      if ( (v17 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = v15->m_Components.p->m_pComponent;
      }
      else if ( v17 >= 0 )
      {
        if ( (v17 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = v15->m_Components.p->m_pComponent;
        }
        else if ( (v17 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::UELComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = v15->m_Components.p->m_pComponent;
      }
      if ( ComponentOfTypeHK )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&ComponentOfTypeHK[1].m_TypeUID;
    }
    ActionController::Play(&this->m_ActionController, (ActionNodePlayable *)this->m_pActionContext->m_OpeningBranch, 0);
    UEL::gCurrentParameters = v16;
  }
}

// File Line: 347
// RVA: 0x384DD0
void __fastcall UFG::AIActionTreeComponent::SetActionTreeFileName(UFG::AIActionTreeComponent *this, char *filename)
{
  char v2; // al
  const char *v3; // rsi
  const char *v4; // rdi
  const char *v7; // rbx
  char dest[128]; // [rsp+20h] [rbp-108h] BYREF
  char str[128]; // [rsp+A0h] [rbp-88h] BYREF

  v2 = *filename;
  v3 = 0i64;
  v4 = 0i64;
  v7 = filename;
  if ( !*filename )
    goto LABEL_11;
  do
  {
    if ( v2 == / || v2 == \\ )
    {
      v3 = v7;
      v4 = 0i64;
    }
    else if ( v2 == . && !v4 )
    {
      v4 = v7;
    }
    v2 = *++v7;
  }
  while ( v2 );
  if ( v3 )
  {
    UFG::qSharedString::operator=(&this->m_ActionTreeFileName, filename);
  }
  else
  {
LABEL_11:
    UFG::qSPrintf(dest, "Data\\Global\\Act\\AI\\%s", filename);
    UFG::qSharedString::operator=(&this->m_ActionTreeFileName, dest);
    v3 = filename - 1;
  }
  if ( !v4 )
    LODWORD(v4) = (_DWORD)v7;
  UFG::qStringCopy(str, 128, (char *)v3 + 1, (_DWORD)v4 - (_DWORD)v3 - 1);
  this->m_ActionTreeFileNameStrippedHash = UFG::qStringHashUpper32(str, -1);
}

// File Line: 403
// RVA: 0x377E00
void __fastcall UFG::AIActionTreeComponent::OnAttach(UFG::AIActionTreeComponent *this, UFG::SimObjectCharacter *object)
{
  signed __int16 m_Flags; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  BOOL v6; // ebx
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *p_m_pNavComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pActiveAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *p_m_pFaceActionComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *p_m_pInterestPointUserComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  fastdelegate::FastDelegate0<void> v32; // [rsp+30h] [rbp-28h] BYREF
  fastdelegate::FastDelegate1<float,void> v33; // [rsp+40h] [rbp-18h] BYREF

  UFG::AIActionTreeComponent::InitActionTree(this);
  Intention::Clear(&this->m_LastFrameIntentions);
  this->m_LastFrameEmotion = eAI_EMOTION_NONE;
  *(_WORD *)&this->m_LastFrameHasDestination = 0;
  if ( object
    && ((m_Flags = object->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(object))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             object,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             object,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    if ( ComponentOfTypeHK->m_eFactionClass == FACTION_INNOCENT )
    {
      this->m_TicketType = TICKETBOOTH_NON_CRITICAL_AIACTIONTREEUPDATE;
      this->m_PreserveLastFrameInformation = 1;
      v32.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AIActionTreeComponent::InactiveTicketUpdate;
      v32.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
      v33.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) SSClassDescBase::`vcall{8,{flat}};
      v33.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(&this->UFG::StateInterface);
      UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 2, &this->m_Ticket, &v33, &v32);
    }
    else
    {
      v6 = object != LocalPlayer;
      v33.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) SSClassDescBase::`vcall{8,{flat}};
      this->m_TicketType = v6;
      v33.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(&this->UFG::StateInterface);
      UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, v6, &this->m_Ticket, &v33);
    }
  }
  else
  {
    this->m_TicketType = TICKETBOOTH_VEHICLE_AIACTIONTREEUPDATE;
    v33.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) SSClassDescBase::`vcall{8,{flat}};
    v33.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(&this->UFG::StateInterface);
    UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 3, &this->m_Ticket, &v33);
  }
  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    mPrev = p_m_pAICharacterControllerBaseComponent->mPrev;
    mNext = this->m_pAICharacterControllerBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_20:
    this->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerBaseComponent.mNext = &this->m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_21;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v10 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v11 = this->m_pAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_20;
  }
LABEL_21:
  this->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  this->m_pAICharacterControllerBaseComponent.m_pSimObject = object;
  this->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAICharacterControllerBaseComponent,
    object);
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pSimComponent )
  {
    v13 = p_m_pNavComponent->mPrev;
    v14 = this->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pNavComponent.m_pSimComponent = 0i64;
LABEL_27:
    this->m_pNavComponent.m_pSimObject = 0i64;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    goto LABEL_28;
  }
  if ( this->m_pNavComponent.m_pSimObject
    && (p_m_pNavComponent->mPrev != p_m_pNavComponent || this->m_pNavComponent.mNext != &this->m_pNavComponent) )
  {
    v15 = p_m_pNavComponent->mPrev;
    v16 = this->m_pNavComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_27;
  }
LABEL_28:
  this->m_pNavComponent.m_Changed = 1;
  this->m_pNavComponent.m_pSimObject = object;
  this->m_pNavComponent.m_TypeUID = UFG::NavComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::BindInternal<UFG::SimObject>(&this->m_pNavComponent, object);
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  if ( this->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v18 = p_m_pActiveAIEntityComponent->mPrev;
    v19 = this->m_pActiveAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_34:
    this->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    goto LABEL_35;
  }
  if ( this->m_pActiveAIEntityComponent.m_pSimObject
    && (p_m_pActiveAIEntityComponent->mPrev != p_m_pActiveAIEntityComponent
     || this->m_pActiveAIEntityComponent.mNext != &this->m_pActiveAIEntityComponent) )
  {
    v20 = p_m_pActiveAIEntityComponent->mPrev;
    v21 = this->m_pActiveAIEntityComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_34;
  }
LABEL_35:
  this->m_pActiveAIEntityComponent.m_Changed = 1;
  this->m_pActiveAIEntityComponent.m_pSimObject = object;
  this->m_pActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pActiveAIEntityComponent,
    object);
  p_m_pFaceActionComponent = &this->m_pFaceActionComponent;
  if ( this->m_pFaceActionComponent.m_pSimComponent )
  {
    v23 = p_m_pFaceActionComponent->mPrev;
    v24 = this->m_pFaceActionComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pFaceActionComponent.m_pSimComponent = 0i64;
LABEL_41:
    this->m_pFaceActionComponent.m_pSimObject = 0i64;
    this->m_pFaceActionComponent.mNext = &this->m_pFaceActionComponent;
    p_m_pFaceActionComponent->mPrev = p_m_pFaceActionComponent;
    goto LABEL_42;
  }
  if ( this->m_pFaceActionComponent.m_pSimObject
    && (p_m_pFaceActionComponent->mPrev != p_m_pFaceActionComponent
     || this->m_pFaceActionComponent.mNext != &this->m_pFaceActionComponent) )
  {
    v25 = p_m_pFaceActionComponent->mPrev;
    v26 = this->m_pFaceActionComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_41;
  }
LABEL_42:
  this->m_pFaceActionComponent.m_Changed = 1;
  this->m_pFaceActionComponent.m_pSimObject = object;
  this->m_pFaceActionComponent.m_TypeUID = UFG::FaceActionComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pFaceActionComponent,
    object);
  p_m_pInterestPointUserComponent = &this->m_pInterestPointUserComponent;
  if ( this->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v28 = p_m_pInterestPointUserComponent->mPrev;
    v29 = this->m_pInterestPointUserComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_48:
    this->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    this->m_pInterestPointUserComponent.mNext = &this->m_pInterestPointUserComponent;
    p_m_pInterestPointUserComponent->mPrev = p_m_pInterestPointUserComponent;
    goto LABEL_49;
  }
  if ( this->m_pInterestPointUserComponent.m_pSimObject
    && (p_m_pInterestPointUserComponent->mPrev != p_m_pInterestPointUserComponent
     || this->m_pInterestPointUserComponent.mNext != &this->m_pInterestPointUserComponent) )
  {
    v30 = p_m_pInterestPointUserComponent->mPrev;
    v31 = this->m_pInterestPointUserComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_48;
  }
LABEL_49:
  this->m_pInterestPointUserComponent.m_Changed = 1;
  this->m_pInterestPointUserComponent.m_pSimObject = object;
  this->m_pInterestPointUserComponent.m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pInterestPointUserComponent,
    object);
}PointUserComponent.m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::BindIntern

// File Line: 442
// RVA: 0x379620
void __fastcall UFG::AIActionTreeComponent::OnDetach(UFG::AIActionTreeComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *p_m_pFaceActionComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *p_m_pInterestPointUserComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v28; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    mPrev = p_m_pAICharacterControllerBaseComponent->mPrev;
    mNext = this->m_pAICharacterControllerBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAICharacterControllerBaseComponent->m_pSimObject = 0i64;
    p_m_pAICharacterControllerBaseComponent->mNext = p_m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_8;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v5 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v6 = p_m_pAICharacterControllerBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pNavComponent = &this->m_pNavComponent;
  p_m_pAICharacterControllerBaseComponent->m_Changed = 1;
  if ( this->m_pNavComponent.m_pSimComponent )
  {
    v8 = p_m_pNavComponent->mPrev;
    v9 = this->m_pNavComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pNavComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pNavComponent.m_pSimObject = 0i64;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    goto LABEL_15;
  }
  if ( this->m_pNavComponent.m_pSimObject
    && (p_m_pNavComponent->mPrev != p_m_pNavComponent || this->m_pNavComponent.mNext != &this->m_pNavComponent) )
  {
    v10 = p_m_pNavComponent->mPrev;
    v11 = this->m_pNavComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pNavComponent.m_Changed = 1;
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  if ( this->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v13 = p_m_pActiveAIEntityComponent->mPrev;
    v14 = this->m_pActiveAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    goto LABEL_22;
  }
  if ( this->m_pActiveAIEntityComponent.m_pSimObject
    && (p_m_pActiveAIEntityComponent->mPrev != p_m_pActiveAIEntityComponent
     || this->m_pActiveAIEntityComponent.mNext != &this->m_pActiveAIEntityComponent) )
  {
    v15 = p_m_pActiveAIEntityComponent->mPrev;
    v16 = this->m_pActiveAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pActiveAIEntityComponent.m_Changed = 1;
  p_m_pFaceActionComponent = &this->m_pFaceActionComponent;
  if ( this->m_pFaceActionComponent.m_pSimComponent )
  {
    v18 = p_m_pFaceActionComponent->mPrev;
    v19 = this->m_pFaceActionComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pFaceActionComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pFaceActionComponent.m_pSimObject = 0i64;
    this->m_pFaceActionComponent.mNext = &this->m_pFaceActionComponent;
    p_m_pFaceActionComponent->mPrev = p_m_pFaceActionComponent;
    goto LABEL_29;
  }
  if ( this->m_pFaceActionComponent.m_pSimObject
    && (p_m_pFaceActionComponent->mPrev != p_m_pFaceActionComponent
     || this->m_pFaceActionComponent.mNext != &this->m_pFaceActionComponent) )
  {
    v20 = p_m_pFaceActionComponent->mPrev;
    v21 = this->m_pFaceActionComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pFaceActionComponent.m_Changed = 1;
  p_m_pInterestPointUserComponent = &this->m_pInterestPointUserComponent;
  if ( this->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v23 = p_m_pInterestPointUserComponent->mPrev;
    v24 = this->m_pInterestPointUserComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    this->m_pInterestPointUserComponent.mNext = &this->m_pInterestPointUserComponent;
    p_m_pInterestPointUserComponent->mPrev = p_m_pInterestPointUserComponent;
    goto LABEL_36;
  }
  if ( this->m_pInterestPointUserComponent.m_pSimObject
    && (p_m_pInterestPointUserComponent->mPrev != p_m_pInterestPointUserComponent
     || this->m_pInterestPointUserComponent.mNext != &this->m_pInterestPointUserComponent) )
  {
    v25 = p_m_pInterestPointUserComponent->mPrev;
    v26 = this->m_pInterestPointUserComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::TicketBoothManager::Unregister(UFG::TicketBoothManager::mpSingleton, this->m_TicketType, &this->m_Ticket);
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v28 = UEL::gCurrentParameters;
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
  ActionController::Stop(&this->m_ActionController);
  UEL::gCurrentParameters = v28;
}

// File Line: 481
// RVA: 0x365100
void __fastcall UFG::AIActionTreeComponent::InactiveTicketUpdate(UFG::AIActionTreeComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimComponent *v3; // rcx
  UFG::NavComponent *v4; // rcx
  UFG::SimComponent *v5; // rcx

  if ( (this->m_Flags & 2) == 0 )
  {
    m_pSimComponent = this->m_pInterestPointUserComponent.m_pSimComponent;
    if ( m_pSimComponent
      && LODWORD(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) == UFG::Metrics::msInstance.mSimFrameCount )
    {
      ((void (__fastcall *)(UFG::AIActionTreeComponent *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor)(this);
    }
    else
    {
      v3 = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
      if ( v3 )
      {
        Intention::operator=((Intention *)&v3[2], &this->m_LastFrameIntentions);
        LOBYTE(this->m_pAICharacterControllerBaseComponent.m_pSimComponent[15].m_SafePointerList.mNode.mPrev) = 1;
      }
      v4 = (UFG::NavComponent *)this->m_pNavComponent.m_pSimComponent;
      if ( v4 && this->m_LastFrameHasDestination )
        UFG::NavComponent::PreserveDestination(v4);
      v5 = this->m_pActiveAIEntityComponent.m_pSimComponent;
      if ( v5 )
        HIDWORD(v5[64].m_BoundComponentHandles.mNode.mNext) = this->m_LastFrameEmotion;
    }
  }
}

// File Line: 520
// RVA: 0x37BC60
void __fastcall UFG::AIActionTreeComponent::OnUpdate(UFG::AIActionTreeComponent *this, float delta_sec)
{
  UFG::SimObject *m_pSimObject; // rcx
  UEL::ParametersBase *v4; // rdi
  __int16 m_Flags; // dx
  UFG::UELComponent *m_pComponent; // rax
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::NavComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::FaceActionComponent *v10; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && (this->m_Flags & 2) == 0 )
  {
    v4 = UEL::gCurrentParameters;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::UELComponent *)m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = (UFG::UELComponent *)m_pSimObject->m_Components.p->m_pComponent;
        else
          m_pComponent = (UFG::UELComponent *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
      }
      else
      {
        m_pComponent = (UFG::UELComponent *)m_pSimObject->m_Components.p->m_pComponent;
      }
      if ( m_pComponent )
        UEL::gCurrentParameters = &m_pComponent->mParameters;
    }
    ActionController::Update(&this->m_ActionController, delta_sec);
    UEL::gCurrentParameters = v4;
    if ( this->m_PreserveLastFrameInformation )
    {
      m_pSimComponent = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
      if ( m_pSimComponent )
        Intention::operator=(&this->m_LastFrameIntentions, (Intention *)&m_pSimComponent[2]);
      v8 = (UFG::NavComponent *)this->m_pNavComponent.m_pSimComponent;
      if ( v8 )
        this->m_LastFrameHasDestination = UFG::NavComponent::HasDestination(v8);
      v9 = this->m_pActiveAIEntityComponent.m_pSimComponent;
      if ( v9 )
        this->m_LastFrameEmotion = HIDWORD(v9[64].m_BoundComponentHandles.mNode.mNext);
    }
    v10 = (UFG::FaceActionComponent *)this->m_pFaceActionComponent.m_pSimComponent;
    if ( v10 )
      UFG::FaceActionComponent::SetFrameAITreeUpdated(v10);
  }
}

// File Line: 688
// RVA: 0x355910
void __fastcall UFG::AIActionTreeComponent::EnsureTicketBoothCriticalPriority(UFG::AIActionTreeComponent *this)
{
  UFG::eTicketBoothEnum m_TicketType; // edx
  fastdelegate::FastDelegate1<float,void> v3; // [rsp+20h] [rbp-18h] BYREF

  m_TicketType = this->m_TicketType;
  if ( m_TicketType != TICKETBOOTH_CRITICAL_AIACTIONTREEUPDATE && m_TicketType != NUM_TICKETBOOTHS )
  {
    UFG::TicketBoothManager::Unregister(UFG::TicketBoothManager::mpSingleton, m_TicketType, &this->m_Ticket);
    this->m_TicketType = TICKETBOOTH_CRITICAL_AIACTIONTREEUPDATE;
    v3.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) SSClassDescBase::`vcall{8,{flat}};
    v3.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(&this->UFG::StateInterface);
    UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 1, &this->m_Ticket, &v3);
  }
}

