// File Line: 87
// RVA: 0x14AE9C0
__int64 dynamic_initializer_for__UFG::AIActionTreeComponent::s_AIActionTreeComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIActionTreeComponent::s_AIActionTreeComponentList__);
}

// File Line: 88
// RVA: 0x3632A0
const char *__fastcall UFG::AIActionTreeComponent::GetTypeName(UFG::AIActionTreeComponent *this)
{
  return "AIActionTreeComponent";
}

// File Line: 98
// RVA: 0x37E720
UFG::AIActionTreeComponent *__fastcall UFG::AIActionTreeComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::AIActionTreeComponent *v6; // rdi
  UFG::AIActionTreeComponent *result; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::AIActionTreeComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_AIActionTree::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::AIActionTreeComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( v2 || result )
  {
    v8 = (char *)result->vfptr + (unsigned __int64)result;
    if ( !result->vfptr )
      v8 = 0i64;
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0x678ui64, "AIActionTreeComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::AIActionTreeComponent::AIActionTreeComponent((UFG::AIActionTreeComponent *)v10, v3->m_NameUID, v8);
      v6 = v11;
    }
    v12 = v3->m_pSimObject;
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
      v14 = 19;
    else
      v14 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
    UFG::SimObjectModifier::AttachComponent(&v15, (UFG::SimComponent *)&v6->vfptr, v14);
    UFG::SimObjectModifier::Close(&v15);
    UFG::SimObjectModifier::~SimObjectModifier(&v15);
    result = v6;
  }
  return result;
}

// File Line: 118
// RVA: 0x32A690
void __fastcall UFG::AIActionTreeComponent::AIActionTreeComponent(UFG::AIActionTreeComponent *this, unsigned int name_uid, const char *actName)
{
  const char *v3; // rsi
  UFG::AIActionTreeComponent *v4; // r14
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v5; // rdi
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v6; // rax
  UFG::Ticket *v7; // [rsp+68h] [rbp+20h]

  v3 = actName;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  v4->mAutoActivate = 1;
  v4->mAge = 0.0;
  v5 = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(
    (UFG::ActionTreeComponentBase *)&v4->vfptr,
    eACTION_TREE_TYPE_AI);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::StateInterface};
  v4->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::AIActionTreeComponent::`vftable;
  UFG::qSharedString::qSharedString(&v4->m_ActionTreeFileName);
  ActionController::ActionController(&v4->m_ActionController);
  v7 = &v4->m_Ticket;
  v7->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v4->m_Ticket.mTimestamp = 0i64;
  v4->m_Ticket.mActiveCallback.m_Closure.m_pthis = 0i64;
  v4->m_Ticket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v4->m_Ticket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v4->m_Ticket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  Intention::Intention(&v4->m_LastFrameIntentions);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&v4->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&v4->m_pNavComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v4->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0>::RebindingComponentHandle<UFG::FaceActionComponent,0>(&v4->m_pFaceActionComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&v4->m_pInterestPointUserComponent);
  v6 = UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev;
  UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&UFG::AIActionTreeComponent::s_AIActionTreeComponentList;
  UFG::AIActionTreeComponent::s_AIActionTreeComponentList.mNode.mPrev = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID,
    "AIActionTreeComponent");
  UFG::AIActionTreeComponent::SetActionTreeFileName(v4, v3);
  UFG::AIActionTreeComponent::Init(v4);
}

// File Line: 128
// RVA: 0x3651B0
void __fastcall UFG::AIActionTreeComponent::Init(UFG::AIActionTreeComponent *this)
{
  UFG::AIActionTreeComponent *v1; // rbx
  UFG::allocator::free_link *v2; // rax

  v1 = this;
  *(_WORD *)&this->m_DebugDisplay = 0;
  v2 = UFG::qMalloc(0xD8ui64, "AIAIActionTreeComponent::ActionContext", 0i64);
  if ( v2 )
    ActionContext::ActionContext((ActionContext *)v2);
  v1->m_pActionContext = (ActionContext *)v2;
  *(_WORD *)&v1->m_ActionController.m_BankTracksEnabled = 257;
  Intention::Clear(&v1->m_LastFrameIntentions);
  v1->m_LastFrameEmotion = 0;
  *(_WORD *)&v1->m_LastFrameHasDestination = 0;
  v1->m_TicketType = 10;
  v1->m_LastSimFrameUpdated = -1;
}

// File Line: 156
// RVA: 0x333710
void __fastcall UFG::AIActionTreeComponent::~AIActionTreeComponent(UFG::AIActionTreeComponent *this)
{
  UFG::AIActionTreeComponent *v1; // rbx
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v3; // rcx
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v4; // rax
  UEL::ParametersBase *v5; // rbp
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UEL::ParametersBase *v8; // rax
  ActionContext *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::Ticket *v14; // r8
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v15; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v16; // rax
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v17; // rcx
  UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIActionTreeComponent::`vftable{for `UFG::StateInterface};
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::AIActionTreeComponent::`vftable;
  if ( this == UFG::AIActionTreeComponent::s_AIActionTreeComponentpCurrentIterator )
    UFG::AIActionTreeComponent::s_AIActionTreeComponentpCurrentIterator = (UFG::AIActionTreeComponent *)&this->mPrev[-11].mNext;
  v2 = (UFG::qNode<UFG::AIActionTreeComponent,UFG::AIActionTreeComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = UEL::gCurrentParameters;
  v6 = v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
      else
        v8 = (UEL::ParametersBase *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v6,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v6,
                                                                                         UFG::UELComponent::_TypeUID));
    }
    else
    {
      v8 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
    }
    if ( v8 )
      UEL::gCurrentParameters = v8 + 88;
  }
  ActionController::Stop(&v1->m_ActionController);
  UEL::gCurrentParameters = v5;
  v9 = v1->m_pActionContext;
  if ( v9 )
  {
    if ( v9->mSimObject.m_pPointer )
    {
      v10 = v9->mSimObject.mPrev;
      v11 = v9->mSimObject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
      v9->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    }
    v9->mSimObject.m_pPointer = 0i64;
    v12 = v9->mSimObject.mPrev;
    v13 = v9->mSimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v9->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    v9->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    operator delete[](v9);
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pFaceActionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pNavComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAICharacterControllerBaseComponent);
  v14 = &v1->m_Ticket;
  v15 = v1->m_Ticket.mPrev;
  v16 = v1->m_Ticket.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v14->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v14->mPrev;
  ActionController::~ActionController(&v1->m_ActionController);
  UFG::qSharedString::~qSharedString(&v1->m_ActionTreeFileName);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase((UFG::ActionTreeComponentBase *)&v1->vfptr);
  v17 = v2->mPrev;
  v18 = v2->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (LOBYTE(v1->m_Flags) >> 2) & 1 )
  {
    v1->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AIActionTreeComponent *))v1->vfptr[16].__vecDelDtor)(v1);
    v1->m_Flags &= 0xFFFBu;
  }
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 191
// RVA: 0x382F90
void __fastcall UFG::AIActionTreeComponent::ResetDefaultTree(UFG::AIActionTreeComponent *this)
{
  UFG::AIActionTreeComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rdx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  char *v5; // rax
  const char *v6; // rdx

  v1 = this;
  ((void (*)(void))this->vfptr[18].__vecDelDtor)();
  v2 = v1->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v3,
         (UFG::qSymbol *)&component_AIActionTree::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = UFG::qPropertySet::GetMemImagePtr(v4);
    if ( v5 )
    {
      if ( *(_QWORD *)v5 )
        v6 = &v5[*(_QWORD *)v5];
      else
        v6 = 0i64;
      UFG::AIActionTreeComponent::SetActionTreeFileName(v1, v6);
    }
  }
  UFG::AIActionTreeComponent::InitActionTree(v1);
}

// File Line: 212
// RVA: 0x380B80
void __fastcall UFG::AIActionTreeComponent::ReleaseActionTree(UFG::AIActionTreeComponent *this)
{
  UEL::ParametersBase *v1; // rdi
  UFG::AIActionTreeComponent *v2; // rbx
  UFG::SimObject *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax

  v1 = UEL::gCurrentParameters;
  v2 = this;
  v3 = this->m_pSimObject;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p->m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v3->m_Components.p->m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v3, UFG::UELComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType(v3, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v5 = v3->m_Components.p->m_pComponent;
    }
    if ( v5 )
      UEL::gCurrentParameters = (UEL::ParametersBase *)&v5[1].m_TypeUID;
  }
  ActionController::Stop(&v2->m_ActionController);
  UEL::gCurrentParameters = v1;
}

// File Line: 242
// RVA: 0x366A20
void __fastcall UFG::AIActionTreeComponent::InitActionTree(UFG::AIActionTreeComponent *this)
{
  UFG::AIActionTreeComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::GetInFormationComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::HasAttackRequestComponent *v11; // rax
  ActionContext *v12; // rax
  ActionNode *v13; // rcx
  ActionNodeRoot *v14; // rbx
  UFG::SimObject *v15; // rcx
  UEL::ParametersBase *v16; // rbx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[11].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::StimulusReceiverComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::StimulusReceiverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
      v4 = v5;
    }
    else
    {
      v4 = v2->m_Components.p[11].m_pComponent;
    }
    if ( v4 )
    {
      UFG::StimulusReceiverComponent::UnrequestAllStimuli((UFG::StimulusReceiverComponent *)v4);
      UFG::StimulusReceiverComponent::DeregisterCallbacks((UFG::StimulusReceiverComponent *)v4);
      *(_QWORD *)&v4[1].m_Flags = 0i64;
      v4[1].m_pSimObject = 0i64;
      UFG::qMemSet(&v4[1].m_BoundComponentHandles, 0, 0x3A0u);
      *(_DWORD *)(&v4[16].m_SimObjIndex + 1) = -943501440;
    }
  }
  v6 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::GetInFormationComponent *)v6->m_Components.p[32].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UFG::GetInFormationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v6,
                                               UFG::GetInFormationComponent::_TypeUID);
      else
        v8 = (UFG::GetInFormationComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v6,
                                                                 UFG::GetInFormationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::GetInFormationComponent::_TypeUID));
    }
    else
    {
      v8 = (UFG::GetInFormationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::GetInFormationComponent::_TypeUID);
    }
    if ( v8 )
      UFG::GetInPedFormationComponent::DeleteList(v8);
  }
  v9 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = (UFG::HasAttackRequestComponent *)v9->m_Components.p[35].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v11 = (UFG::HasAttackRequestComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v9,
                                                  UFG::HasAttackRequestComponent::_TypeUID);
      else
        v11 = (UFG::HasAttackRequestComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v9,
                                                                     UFG::HasAttackRequestComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::HasAttackRequestComponent::_TypeUID));
    }
    else
    {
      v11 = (UFG::HasAttackRequestComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v9,
                                                UFG::HasAttackRequestComponent::_TypeUID);
    }
    if ( v11 )
      UFG::HasAttackRequestComponent::Reset(v11);
  }
  UFG::ActionTreeComponentBase::ResetMemory((UFG::ActionTreeComponentBase *)&v1->vfptr);
  ActionContext::Reset(v1->m_pActionContext, eACTION_TREE_TYPE_AI, v1->m_pSimObject);
  v1->m_pActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(v1->m_ActionTreeFileName.mText);
  v12 = v1->m_pActionContext;
  v1->m_ActionController.m_Context = v12;
  v12->mActionController = &v1->m_ActionController;
  v13 = v1->m_pActionContext->m_OpeningBranch;
  if ( v13 )
  {
    v14 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *))v13->vfptr[1].GetResourceOwner)(v13);
    if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v1->vfptr, v14) )
      ActionNodeRoot::Init(v14, v1->m_pActionContext);
    v15 = v1->m_pSimObject;
    v16 = UEL::gCurrentParameters;
    if ( v15 )
    {
      v17 = v15->m_Flags;
      if ( (v17 >> 14) & 1 )
      {
        v18 = v15->m_Components.p->m_pComponent;
      }
      else if ( (v17 & 0x8000u) == 0 )
      {
        if ( (v17 >> 13) & 1 )
        {
          v18 = v15->m_Components.p->m_pComponent;
        }
        else if ( (v17 >> 12) & 1 )
        {
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v15, UFG::UELComponent::_TypeUID);
        }
        else
        {
          v18 = UFG::SimObject::GetComponentOfType(v15, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        v18 = v15->m_Components.p->m_pComponent;
      }
      if ( v18 )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&v18[1].m_TypeUID;
    }
    ActionController::Play(&v1->m_ActionController, v1->m_pActionContext->m_OpeningBranch, 0);
    UEL::gCurrentParameters = v16;
  }
}

// File Line: 347
// RVA: 0x384DD0
void __fastcall UFG::AIActionTreeComponent::SetActionTreeFileName(UFG::AIActionTreeComponent *this, const char *filename)
{
  char v2; // al
  signed __int64 v3; // rsi
  const char *v4; // rdi
  const char *v5; // r14
  UFG::AIActionTreeComponent *v6; // rbp
  const char *v7; // rbx
  char dest; // [rsp+20h] [rbp-108h]
  char str; // [rsp+A0h] [rbp-88h]

  v2 = *filename;
  v3 = 0i64;
  v4 = 0i64;
  v5 = filename;
  v6 = this;
  v7 = filename;
  if ( !*filename )
    goto LABEL_17;
  do
  {
    if ( v2 == / || v2 == \\ )
    {
      v3 = (signed __int64)v7;
      v4 = 0i64;
    }
    else if ( v2 == . && !v4 )
    {
      v4 = v7;
    }
    v2 = (v7++)[1];
  }
  while ( v2 );
  if ( v3 )
  {
    UFG::qSharedString::operator=(&this->m_ActionTreeFileName, filename);
  }
  else
  {
LABEL_17:
    UFG::qSPrintf(&dest, "Data\\Global\\Act\\AI\\%s", filename);
    UFG::qSharedString::operator=(&v6->m_ActionTreeFileName, &dest);
    v3 = (signed __int64)(v5 - 1);
  }
  if ( !v4 )
    LODWORD(v4) = (_DWORD)v7;
  UFG::qStringCopy(&str, 128, (const char *)(v3 + 1), (_DWORD)v4 - v3 - 1);
  v6->m_ActionTreeFileNameStrippedHash = UFG::qStringHashUpper32(&str, 0xFFFFFFFF);
}

// File Line: 403
// RVA: 0x377E00
void __fastcall UFG::AIActionTreeComponent::OnAttach(UFG::AIActionTreeComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectCVBase *v2; // rdi
  UFG::AIActionTreeComponent *v3; // rsi
  unsigned __int16 v4; // cx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax
  BOOL v6; // ebx
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v7; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *v12; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v17; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *v22; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v27; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  hkSeekableStreamReader *v32; // [rsp+30h] [rbp-28h]
  void (__fastcall *v33)(UFG::AIActionTreeComponent *); // [rsp+38h] [rbp-20h]
  hkSeekableStreamReader *v34; // [rsp+40h] [rbp-18h]
  __int64 (__fastcall *v35)(__int64); // [rsp+48h] [rbp-10h]

  v2 = (UFG::SimObjectCVBase *)object;
  v3 = this;
  UFG::AIActionTreeComponent::InitActionTree(this);
  Intention::Clear(&v3->m_LastFrameIntentions);
  v3->m_LastFrameEmotion = 0;
  *(_WORD *)&v3->m_LastFrameHasDestination = 0;
  if ( v2
    && ((v4 = v2->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2)),
        v5) )
  {
    if ( v5->m_eFactionClass == FACTION_INNOCENT )
    {
      v3->m_TicketType = TICKETBOOTH_NON_CRITICAL_AIACTIONTREEUPDATE;
      v3->m_PreserveLastFrameInformation = 1;
      v33 = UFG::AIActionTreeComponent::InactiveTicketUpdate;
      v32 = Assembly::GetRCX(v3);
      v35 =  SSClassDescBase::`vcall{8,{flat}};
      v34 = Assembly::GetRCX(&v3->vfptr);
      UFG::TicketBoothManager::Register(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_NON_CRITICAL_AIACTIONTREEUPDATE,
        &v3->m_Ticket,
        (fastdelegate::FastDelegate1<float,void> *)&v34,
        (fastdelegate::FastDelegate0<void> *)&v32);
    }
    else
    {
      v6 = v2 != (UFG::SimObjectCVBase *)LocalPlayer;
      v35 =  SSClassDescBase::`vcall{8,{flat}};
      v3->m_TicketType = v6;
      v34 = Assembly::GetRCX(&v3->vfptr);
      UFG::TicketBoothManager::Register(
        UFG::TicketBoothManager::mpSingleton,
        (UFG::eTicketBoothEnum)v6,
        &v3->m_Ticket,
        (fastdelegate::FastDelegate1<float,void> *)&v34);
    }
  }
  else
  {
    v3->m_TicketType = TICKETBOOTH_VEHICLE_AIACTIONTREEUPDATE;
    v35 =  SSClassDescBase::`vcall{8,{flat}};
    v34 = Assembly::GetRCX(&v3->vfptr);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_VEHICLE_AIACTIONTREEUPDATE,
      &v3->m_Ticket,
      (fastdelegate::FastDelegate1<float,void> *)&v34);
  }
  v7 = &v3->m_pAICharacterControllerBaseComponent;
  if ( v3->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v3->m_pAICharacterControllerBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v3->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_22:
    v3->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v3->m_pAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAICharacterControllerBaseComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_23;
  }
  if ( v3->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v3->m_pAICharacterControllerBaseComponent.mNext != &v3->m_pAICharacterControllerBaseComponent) )
  {
    v10 = v7->mPrev;
    v11 = v3->m_pAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_22;
  }
LABEL_23:
  v3->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  v3->m_pAICharacterControllerBaseComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAICharacterControllerBaseComponent,
    (UFG::SimObject *)&v2->vfptr);
  v12 = &v3->m_pNavComponent;
  if ( v3->m_pNavComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v3->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v3->m_pNavComponent.m_pSimComponent = 0i64;
LABEL_29:
    v3->m_pNavComponent.m_pSimObject = 0i64;
    v3->m_pNavComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pNavComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_30;
  }
  if ( v3->m_pNavComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v3->m_pNavComponent.mNext != &v3->m_pNavComponent) )
  {
    v15 = v12->mPrev;
    v16 = v3->m_pNavComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_29;
  }
LABEL_30:
  v3->m_pNavComponent.m_Changed = 1;
  v3->m_pNavComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pNavComponent.m_TypeUID = UFG::NavComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pNavComponent,
    (UFG::SimObject *)&v2->vfptr);
  v17 = &v3->m_pActiveAIEntityComponent;
  if ( v3->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v3->m_pActiveAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v3->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_36:
    v3->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    v3->m_pActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pActiveAIEntityComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_37;
  }
  if ( v3->m_pActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->m_pActiveAIEntityComponent.mNext != &v3->m_pActiveAIEntityComponent) )
  {
    v20 = v17->mPrev;
    v21 = v3->m_pActiveAIEntityComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_36;
  }
LABEL_37:
  v3->m_pActiveAIEntityComponent.m_Changed = 1;
  v3->m_pActiveAIEntityComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pActiveAIEntityComponent,
    (UFG::SimObject *)&v2->vfptr);
  v22 = &v3->m_pFaceActionComponent;
  if ( v3->m_pFaceActionComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v3->m_pFaceActionComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v3->m_pFaceActionComponent.m_pSimComponent = 0i64;
LABEL_43:
    v3->m_pFaceActionComponent.m_pSimObject = 0i64;
    v3->m_pFaceActionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pFaceActionComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_44;
  }
  if ( v3->m_pFaceActionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *)v3->m_pFaceActionComponent.mNext != &v3->m_pFaceActionComponent) )
  {
    v25 = v22->mPrev;
    v26 = v3->m_pFaceActionComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_43;
  }
LABEL_44:
  v3->m_pFaceActionComponent.m_Changed = 1;
  v3->m_pFaceActionComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pFaceActionComponent.m_TypeUID = UFG::FaceActionComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pFaceActionComponent,
    (UFG::SimObject *)&v2->vfptr);
  v27 = &v3->m_pInterestPointUserComponent;
  if ( v3->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v3->m_pInterestPointUserComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v3->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_50:
    v3->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    v3->m_pInterestPointUserComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pInterestPointUserComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_51;
  }
  if ( v3->m_pInterestPointUserComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v3->m_pInterestPointUserComponent.mNext != &v3->m_pInterestPointUserComponent) )
  {
    v30 = v27->mPrev;
    v31 = v3->m_pInterestPointUserComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_50;
  }
LABEL_51:
  v3->m_pInterestPointUserComponent.m_Changed = 1;
  v3->m_pInterestPointUserComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_pInterestPointUserComponent.m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::BindInternal<UFG::SimObject>(
    v27,
    (UFG::SimObject *)&v2->vfptr);
}

// File Line: 442
// RVA: 0x379620
void __fastcall UFG::AIActionTreeComponent::OnDetach(UFG::AIActionTreeComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v1; // r8
  UFG::AIActionTreeComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::SimObject *v27; // rcx
  UEL::ParametersBase *v28; // rdi
  unsigned __int16 v29; // dx
  UFG::SimComponent *v30; // rax

  v1 = &this->m_pAICharacterControllerBaseComponent;
  v2 = this;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAICharacterControllerBaseComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pNavComponent;
  v1->m_Changed = 1;
  if ( v2->m_pNavComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pNavComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pNavComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pNavComponent.m_pSimObject = 0i64;
    v2->m_pNavComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pNavComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pNavComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v2->m_pNavComponent.mNext != &v2->m_pNavComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pNavComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pNavComponent.m_Changed = 1;
  v12 = &v2->m_pActiveAIEntityComponent;
  if ( v2->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pActiveAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    v2->m_pActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActiveAIEntityComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v2->m_pActiveAIEntityComponent.mNext != &v2->m_pActiveAIEntityComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pActiveAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pActiveAIEntityComponent.m_Changed = 1;
  v17 = &v2->m_pFaceActionComponent;
  if ( v2->m_pFaceActionComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pFaceActionComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pFaceActionComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pFaceActionComponent.m_pSimObject = 0i64;
    v2->m_pFaceActionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pFaceActionComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pFaceActionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::FaceActionComponent,0> *)v2->m_pFaceActionComponent.mNext != &v2->m_pFaceActionComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pFaceActionComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pFaceActionComponent.m_Changed = 1;
  v22 = &v2->m_pInterestPointUserComponent;
  if ( v2->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pInterestPointUserComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    v2->m_pInterestPointUserComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pInterestPointUserComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pInterestPointUserComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v2->m_pInterestPointUserComponent.mNext != &v2->m_pInterestPointUserComponent) )
  {
    v25 = v22->mPrev;
    v26 = v2->m_pInterestPointUserComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::TicketBoothManager::Unregister(UFG::TicketBoothManager::mpSingleton, v2->m_TicketType, &v2->m_Ticket);
  v27 = v2->m_pSimObject;
  v28 = UEL::gCurrentParameters;
  if ( v27 )
  {
    v29 = v27->m_Flags;
    if ( (v29 >> 14) & 1 )
    {
      v30 = v27->m_Components.p->m_pComponent;
    }
    else if ( (v29 & 0x8000u) == 0 )
    {
      if ( (v29 >> 13) & 1 )
      {
        v30 = v27->m_Components.p->m_pComponent;
      }
      else if ( (v29 >> 12) & 1 )
      {
        v30 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v27, UFG::UELComponent::_TypeUID);
      }
      else
      {
        v30 = UFG::SimObject::GetComponentOfType(v27, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v30 = v27->m_Components.p->m_pComponent;
    }
    if ( v30 )
      UEL::gCurrentParameters = (UEL::ParametersBase *)&v30[1].m_TypeUID;
  }
  ActionController::Stop(&v2->m_ActionController);
  UEL::gCurrentParameters = v28;
}

// File Line: 481
// RVA: 0x365100
void __fastcall UFG::AIActionTreeComponent::InactiveTicketUpdate(UFG::AIActionTreeComponent *this)
{
  UFG::AIActionTreeComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx
  UFG::SimComponent *v3; // rcx
  UFG::NavComponent *v4; // rcx
  UFG::SimComponent *v5; // rcx

  v1 = this;
  if ( !((LOBYTE(this->m_Flags) >> 1) & 1) )
  {
    v2 = this->m_pInterestPointUserComponent.m_pSimComponent;
    if ( v2 && LODWORD(v2[8].m_BoundComponentHandles.mNode.mPrev) == UFG::Metrics::msInstance.mSimFrameCount )
    {
      ((void (__fastcall *)(UFG::AIActionTreeComponent *))v1->vfptr[15].__vecDelDtor)(v1);
    }
    else
    {
      v3 = v1->m_pAICharacterControllerBaseComponent.m_pSimComponent;
      if ( v3 )
      {
        Intention::operator=((Intention *)&v3[2], &v1->m_LastFrameIntentions);
        LOBYTE(v1->m_pAICharacterControllerBaseComponent.m_pSimComponent[15].m_SafePointerList.mNode.mPrev) = 1;
      }
      v4 = (UFG::NavComponent *)v1->m_pNavComponent.m_pSimComponent;
      if ( v4 && v1->m_LastFrameHasDestination )
        UFG::NavComponent::PreserveDestination(v4);
      v5 = v1->m_pActiveAIEntityComponent.m_pSimComponent;
      if ( v5 )
        HIDWORD(v5[64].m_BoundComponentHandles.mNode.mNext) = v1->m_LastFrameEmotion;
    }
  }
}

// File Line: 520
// RVA: 0x37BC60
void __fastcall UFG::AIActionTreeComponent::OnUpdate(UFG::AIActionTreeComponent *this, float delta_sec)
{
  UFG::AIActionTreeComponent *v2; // rbx
  UFG::SimObject *v3; // rcx
  UEL::ParametersBase *v4; // rdi
  unsigned __int16 v5; // dx
  UFG::UELComponent *v6; // rax
  UFG::SimComponent *v7; // rdx
  UFG::NavComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::FaceActionComponent *v10; // rcx

  v2 = this;
  v3 = this->m_pSimObject;
  if ( (!v3 || !((v3->m_Flags >> 10) & 1)) && !((LOBYTE(v2->m_Flags) >> 1) & 1) )
  {
    v4 = UEL::gCurrentParameters;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UFG::UELComponent *)v3->m_Components.p->m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = (UFG::UELComponent *)v3->m_Components.p->m_pComponent;
        else
          v6 = (UFG::UELComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v3,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v3,
                                                                                         UFG::UELComponent::_TypeUID));
      }
      else
      {
        v6 = (UFG::UELComponent *)v3->m_Components.p->m_pComponent;
      }
      if ( v6 )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&v6->mParameters;
    }
    ActionController::Update(&v2->m_ActionController, delta_sec);
    UEL::gCurrentParameters = v4;
    if ( v2->m_PreserveLastFrameInformation )
    {
      v7 = v2->m_pAICharacterControllerBaseComponent.m_pSimComponent;
      if ( v7 )
        Intention::operator=(&v2->m_LastFrameIntentions, (Intention *)&v7[2]);
      v8 = (UFG::NavComponent *)v2->m_pNavComponent.m_pSimComponent;
      if ( v8 )
        v2->m_LastFrameHasDestination = UFG::NavComponent::HasDestination(v8);
      v9 = v2->m_pActiveAIEntityComponent.m_pSimComponent;
      if ( v9 )
        v2->m_LastFrameEmotion = HIDWORD(v9[64].m_BoundComponentHandles.mNode.mNext);
    }
    v10 = (UFG::FaceActionComponent *)v2->m_pFaceActionComponent.m_pSimComponent;
    if ( v10 )
      UFG::FaceActionComponent::SetFrameAITreeUpdated(v10);
  }
}

// File Line: 688
// RVA: 0x355910
void __fastcall UFG::AIActionTreeComponent::EnsureTicketBoothCriticalPriority(UFG::AIActionTreeComponent *this)
{
  UFG::eTicketBoothEnum v1; // edx
  UFG::AIActionTreeComponent *v2; // rdi
  hkSeekableStreamReader *v3; // [rsp+20h] [rbp-18h]
  __int64 (__fastcall *v4)(__int64); // [rsp+28h] [rbp-10h]

  v1 = this->m_TicketType;
  v2 = this;
  if ( v1 != 1 && v1 != 10 )
  {
    UFG::TicketBoothManager::Unregister(UFG::TicketBoothManager::mpSingleton, v1, &this->m_Ticket);
    v2->m_TicketType = 1;
    v4 =  SSClassDescBase::`vcall{8,{flat}};
    v3 = Assembly::GetRCX(&v2->vfptr);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_CRITICAL_AIACTIONTREEUPDATE,
      &v2->m_Ticket,
      (fastdelegate::FastDelegate1<float,void> *)&v3);
  }
}

