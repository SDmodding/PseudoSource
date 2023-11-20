// File Line: 101
// RVA: 0x154D980
__int64 dynamic_initializer_for__UFG::ActionTreeComponent::s_ActionTreeComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ActionTreeComponent::s_ActionTreeComponentList__);
}

// File Line: 102
// RVA: 0x582A50
signed __int64 __fastcall UFG::ActionTreeComponent::GetTypeSize(UFG::ActionTreeComponent *this)
{
  return 1376i64;
}

// File Line: 124
// RVA: 0x57C1C0
void __fastcall UFG::ActionTreeComponent::ActionTreeComponent(UFG::ActionTreeComponent *this, UFG::SceneObjectProperties *pSceneObj, unsigned int name_uid, const char *actFileName)
{
  const char *v4; // r14
  UFG::SceneObjectProperties *v5; // rbp
  UFG::ActionTreeComponent *v6; // rsi
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v7; // rdi
  ActionContext *v8; // rbx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  ActionContext *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qList<PostAnimUpdateTask,PostAnimUpdateTaskList,0,0> *v13; // [rsp+58h] [rbp+10h]

  v4 = actFileName;
  v5 = pSceneObj;
  v6 = this;
  if ( pSceneObj )
    name_uid = pSceneObj->m_NameUID;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(
    (UFG::ActionTreeComponentBase *)&v6->vfptr,
    eACTION_TREE_TYPE_ACTION);
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeComponent::`vftable'{for `UFG::SimComponent'};
  v6->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponent::`vftable'{for `UFG::ActionTreeComponentBase'};
  v8 = 0i64;
  v6->mActionTreeFileName = 0i64;
  ActionController::ActionController(&v6->mActionController);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v6->mActiveAIEntityComponent);
  v13 = &v6->mPostAnimUpdateList;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  Intention::Intention(&v6->m_Intention);
  v9 = UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev;
  UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&v6->mPrev;
  v7->mPrev = v9;
  v6->mNext = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&UFG::ActionTreeComponent::s_ActionTreeComponentList;
  UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mPrev = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::ActionTreeComponent::_ActionTreeComponentTypeUID,
    "ActionTreeComponent");
  once_4 = 0;
  v6->mNisUpdated = 0;
  v10 = UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext", 0i64);
  if ( v10 )
  {
    ActionContext::ActionContext((ActionContext *)v10);
    v8 = v11;
  }
  v6->mpActionContext = v8;
  if ( v4 )
  {
    v6->mActionTreeFileName = v4;
  }
  else if ( v5 )
  {
    v12 = PropertyUtils::Get<char const *>(v5, (UFG::qSymbol *)&qSymbol_ActFileName.mUID);
    if ( v12 )
      v6->mActionTreeFileName = (const char *)v12;
  }
  UFG::ActionTreeComponent::Reset(v6);
}

// File Line: 250
// RVA: 0x57D390
void __fastcall UFG::ActionTreeComponent::~ActionTreeComponent(UFG::ActionTreeComponent *this)
{
  UFG::ActionTreeComponent *v1; // rbx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v3; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v4; // rax
  UEL::ParametersBase *v5; // rbp
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UEL::ParametersBase *v8; // rax
  ActionContext *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v14; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v15; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponent::`vftable'{for `UFG::ActionTreeComponentBase'};
  if ( this == UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator )
    UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = (UFG::ActionTreeComponent *)&this->mPrev[-10].mNext;
  v2 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)&this->mPrev;
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
  ActionController::Stop(&v1->mActionController);
  UEL::gCurrentParameters = v5;
  v9 = v1->mpActionContext;
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
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&v1->mPostAnimUpdateList);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActiveAIEntityComponent);
  ActionController::~ActionController(&v1->mActionController);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase((UFG::ActionTreeComponentBase *)&v1->vfptr);
  v14 = v2->mPrev;
  v15 = v2->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 277
// RVA: 0x588D40
UFG::SimComponent *__fastcall UFG::ActionTreeComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned __int16 v7; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x560ui64, "ActionTreeComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v3, v1, 0, 0i64);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->m_pSimObject;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 || (v7 & 0x8000u) != 0 )
  {
    v8 = 7;
  }
  else if ( (v7 >> 13) & 1 )
  {
    v8 = 6;
  }
  else
  {
    v8 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v10, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v5;
}

// File Line: 304
// RVA: 0x582D80
void __fastcall UFG::ActionTreeComponent::InitActionTree(UFG::ActionTreeComponent *this)
{
  UFG::ActionTreeComponent *v1; // rbx
  const char *v2; // rcx
  ActionContext *v3; // rdx
  char *v4; // rax
  ActionContext *v5; // rax
  ActionNode *v6; // rcx
  ActionNodeRoot *v7; // rdi
  UFG::SimObject *v8; // rcx
  UEL::ParametersBase *v9; // rdi
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax

  v1 = this;
  ActionContext::Reset(this->mpActionContext, eACTION_TREE_TYPE_ACTION, this->m_pSimObject);
  UFG::ActionTreeComponentBase::ResetMemory((UFG::ActionTreeComponentBase *)&v1->vfptr);
  v2 = v1->mActionTreeFileName;
  if ( v2 )
  {
    if ( *v2 )
    {
      v3 = v1->mpActionContext;
      v1->mpActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(v2);
      if ( !v1->mpActionContext->m_OpeningBranch )
      {
        v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
        UFG::qPrintf(
          "WARNING: ActionTreeComponent::InitActionTree: Could Not Find Opening Branch: '%s' for SimObject: '%s'\n",
          v1->mActionTreeFileName,
          v4);
      }
    }
  }
  v5 = v1->mpActionContext;
  v1->mActionController.m_OnEnterExitCallbacksEnabled = 1;
  v1->mActionController.m_Context = v5;
  v5->mActionController = &v1->mActionController;
  v6 = v1->mpActionContext->m_OpeningBranch;
  if ( v6 )
  {
    v7 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *))v6->vfptr[1].GetResourceOwner)(v6);
    if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v1->vfptr, v7) )
      ActionNodeRoot::Init(v7, v1->mpActionContext);
    v8 = v1->m_pSimObject;
    v9 = UEL::gCurrentParameters;
    if ( v8 )
    {
      v10 = v8->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = v8->m_Components.p->m_pComponent;
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = v8->m_Components.p->m_pComponent;
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v8, UFG::UELComponent::_TypeUID);
        }
        else
        {
          v11 = UFG::SimObject::GetComponentOfType(v8, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        v11 = v8->m_Components.p->m_pComponent;
      }
      if ( v11 )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&v11[1].m_TypeUID;
    }
    ActionController::Play(&v1->mActionController, v1->mpActionContext->m_OpeningBranch, 0);
    UEL::gCurrentParameters = v9;
  }
}

// File Line: 358
// RVA: 0x585F80
void __fastcall UFG::ActionTreeComponent::OnAttach(UFG::ActionTreeComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rsi
  UFG::ActionTreeComponent *v3; // rdi
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v8; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::allocator::free_link *v13; // [rsp+40h] [rbp+8h]

  v2 = object;
  v3 = this;
  v4 = this->m_pSimObject;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p->m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = v4->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v4, UFG::UELComponent::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType(v4, UFG::UELComponent::_TypeUID);
        v6 = v7;
      }
    }
    else
    {
      v6 = v4->m_Components.p->m_pComponent;
    }
    if ( v6 )
    {
      v13 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v6[2].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v13;
      v13->mNext = (UFG::allocator::free_link *)&v3->m_Intention.mMotionIntentionDirection;
      v6[2].m_BoundComponentHandles.mNode.mNext->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_Intention.mMotionIntentionSpeed;
      v6[2].m_BoundComponentHandles.mNode.mNext[1].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_Intention.mActionRequests;
    }
  }
  UFG::ActionTreeComponent::InitActionTree(v3);
  v8 = &v3->mActiveAIEntityComponent;
  if ( v3->mActiveAIEntityComponent.m_pSimComponent )
  {
    v9 = v8->mPrev;
    v10 = v3->mActiveAIEntityComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v3->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_20:
    v3->mActiveAIEntityComponent.m_pSimObject = 0i64;
    v3->mActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mActiveAIEntityComponent.mPrev;
    v8->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v8->mPrev;
    goto LABEL_21;
  }
  if ( v3->mActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v8->mPrev != v8
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->mActiveAIEntityComponent.mNext != &v3->mActiveAIEntityComponent) )
  {
    v11 = v8->mPrev;
    v12 = v3->mActiveAIEntityComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_20;
  }
LABEL_21:
  v3->mActiveAIEntityComponent.m_Changed = 1;
  v3->mActiveAIEntityComponent.m_pSimObject = v2;
  v3->mActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &v3->mActiveAIEntityComponent,
    v2);
}

// File Line: 384
// RVA: 0x586860
void __fastcall UFG::ActionTreeComponent::OnDetach(UFG::ActionTreeComponent *this)
{
  UEL::ParametersBase *v1; // rbx
  UFG::ActionTreeComponent *v2; // rdi
  UFG::SimObject *v3; // rcx
  unsigned __int16 v4; // dx
  UEL::ParametersBase *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v10; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax

  v1 = UEL::gCurrentParameters;
  v2 = this;
  v3 = this->m_pSimObject;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
      else
        v5 = (UEL::ParametersBase *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v3,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v3,
                                                                                         UFG::UELComponent::_TypeUID));
    }
    else
    {
      v5 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
    }
    if ( v5 )
      UEL::gCurrentParameters = v5 + 88;
  }
  ActionController::Stop(&v2->mActionController);
  UEL::gCurrentParameters = v1;
  v6 = v2->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v6->m_Components.p->m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = v6->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (v7 >> 12) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v6, UFG::UELComponent::_TypeUID);
        else
          v9 = UFG::SimObject::GetComponentOfType(v6, UFG::UELComponent::_TypeUID);
        v8 = v9;
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
  v10 = &v2->mActiveAIEntityComponent;
  if ( v2->mActiveAIEntityComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v2->mActiveAIEntityComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v2->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_32:
    v2->mActiveAIEntityComponent.m_pSimObject = 0i64;
    v2->mActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mActiveAIEntityComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_33;
  }
  if ( v2->mActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v2->mActiveAIEntityComponent.mNext != &v2->mActiveAIEntityComponent) )
  {
    v13 = v10->mPrev;
    v14 = v2->mActiveAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_32;
  }
LABEL_33:
  v2->mActiveAIEntityComponent.m_Changed = 1;
}

// File Line: 434
// RVA: 0x58B060
void __fastcall UFG::ActionTreeComponent::Reset(UFG::ActionTreeComponent *this)
{
  UFG::ActionTreeComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  UEL::ParametersBase *v3; // rdi
  unsigned __int16 v4; // dx
  UEL::ParametersBase *v5; // rax
  ActionContext *v6; // rcx
  ActionNode *v7; // rcx
  ActionNodeRoot *v8; // rsi
  UFG::SimObject *v9; // rcx
  UEL::ParametersBase *v10; // rdi
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax

  v1 = this;
  Intention::Clear(&this->m_Intention);
  v2 = v1->m_pSimObject;
  v3 = UEL::gCurrentParameters;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UEL::ParametersBase *)v2->m_Components.p->m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UEL::ParametersBase *)v2->m_Components.p->m_pComponent;
      else
        v5 = (UEL::ParametersBase *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v2,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v2,
                                                                                         UFG::UELComponent::_TypeUID));
    }
    else
    {
      v5 = (UEL::ParametersBase *)v2->m_Components.p->m_pComponent;
    }
    if ( v5 )
      UEL::gCurrentParameters = v5 + 88;
  }
  ActionController::Stop(&v1->mActionController);
  UEL::gCurrentParameters = v3;
  UFG::ActionTreeComponentBase::ResetMemory((UFG::ActionTreeComponentBase *)&v1->vfptr);
  v6 = v1->mpActionContext;
  if ( v6 )
  {
    v7 = v6->m_OpeningBranch;
    if ( v7 )
    {
      v8 = (ActionNodeRoot *)((__int64 (*)(void))v7->vfptr[1].GetResourceOwner)();
      if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v1->vfptr, v8) )
        ActionNodeRoot::Init(v8, v1->mpActionContext);
      v9 = v1->m_pSimObject;
      v10 = UEL::gCurrentParameters;
      if ( v9 )
      {
        v11 = v9->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = v9->m_Components.p->m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = v9->m_Components.p->m_pComponent;
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v9, UFG::UELComponent::_TypeUID);
          }
          else
          {
            v12 = UFG::SimObject::GetComponentOfType(v9, UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v12 = v9->m_Components.p->m_pComponent;
        }
        if ( v12 )
          UEL::gCurrentParameters = (UEL::ParametersBase *)&v12[1].m_TypeUID;
      }
      ActionController::Play(&v1->mActionController, v1->mpActionContext->m_OpeningBranch, 0);
      UEL::gCurrentParameters = v10;
    }
  }
  v1->m_Flags &= 0xFFFDu;
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
  __m128 v3; // xmm4
  float v4; // xmm2_4
  float v5; // xmm6_4
  __m128 v6; // xmm3
  float v7; // xmm6_4
  float v8; // xmm4_4
  float v9; // xmm5_4

  v2 = *((float *)&this_event[1].m_EventUID + 1);
  v3 = (__m128)this_event[1].m_EventUID;
  v6 = v3;
  v4 = 0.0;
  v5 = *(float *)&this_event[1].m_NamePTR;
  v6.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v2 * v2)) + (float)(v5 * v5);
  if ( v6.m128_f32[0] != 0.0 )
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  v7 = v5 * v4;
  v8 = v3.m128_f32[0] * v4;
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
  if ( this->mNisUpdated == 1 )
    ((void (*)(void))this->vfptr[18].__vecDelDtor)();
}

// File Line: 535
// RVA: 0x5925A0
void __fastcall UFG::ActionTreeComponent::update(UFG::ActionTreeComponent *this, const float delta_sec)
{
  UFG::ActionTreeComponent *v2; // rdi
  UFG::SimObject *v3; // rcx
  UEL::ParametersBase *v4; // rsi
  unsigned __int16 v5; // dx
  UEL::ParametersBase *v6; // rax
  UFG::SimComponent *v7; // rax

  v2 = this;
  v3 = this->m_pSimObject;
  if ( !v3 || !((v3->m_Flags >> 10) & 1) )
  {
    v4 = UEL::gCurrentParameters;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
        else
          v6 = (UEL::ParametersBase *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)v3,
                                                          UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           v3,
                                                                                           UFG::UELComponent::_TypeUID));
      }
      else
      {
        v6 = (UEL::ParametersBase *)v3->m_Components.p->m_pComponent;
      }
      if ( v6 )
        UEL::gCurrentParameters = v6 + 0x58;
    }
    ActionController::Update(&v2->mActionController, delta_sec);
    v7 = v2->mActiveAIEntityComponent.m_pSimComponent;
    if ( v7 && (*((_BYTE *)&v7[65].m_SimObjIndex + 5) || LOBYTE(v7[65].m_pSimObject)) )
      ActionController::Update(&v2->mActionController, 0.0);
    UEL::gCurrentParameters = v4;
  }
}

// File Line: 792
// RVA: 0x58D960
void __fastcall UFG::ActionTreeComponent::UpdateAll(float deltaTime)
{
  unsigned __int64 v1; // rdi
  UFG::ActionTreeComponent *v2; // rcx
  unsigned __int64 v3; // rax

  v1 = UFG::qGetTicks();
  v2 = (UFG::ActionTreeComponent *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  for ( UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = (UFG::ActionTreeComponent *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
        v2 != (UFG::ActionTreeComponent *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152);
        UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = v2 )
  {
    if ( (v2->m_Flags & 3) == 1 && !v2->mNisUpdated )
    {
      ((void (*)(void))v2->vfptr[18].__vecDelDtor)();
      v2 = UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator;
    }
    v2 = (UFG::ActionTreeComponent *)&v2->mNext[-10].mNext;
  }
  UFG::ActionTreeComponent::s_ActionTreeComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(v1, v3);
}

// File Line: 805
// RVA: 0x57EF20
void __fastcall UFG::ActionTreeComponent::AddPostAnimUpdateTask(UFG::ActionTreeComponent *this, PostAnimUpdateTask *postAnimUpdateTask)
{
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v2; // rdx
  UFG::qList<PostAnimUpdateTask,PostAnimUpdateTaskList,0,0> *v3; // rcx
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v4; // rax

  v2 = (UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *)&postAnimUpdateTask->mPrev;
  v3 = &this->mPostAnimUpdateList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

// File Line: 812
// RVA: 0x588770
void __fastcall UFG::ActionTreeComponent::PostAnimUpdate(UFG::ActionTreeComponent *this, float delta_sec)
{
  UEL::ParametersBase *v2; // rsi
  UFG::ActionTreeComponent *v3; // rbx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UEL::ParametersBase *v6; // rax
  signed __int64 v7; // rdi
  signed __int64 v8; // rcx
  signed __int64 v9; // rbx

  v2 = UEL::gCurrentParameters;
  v3 = this;
  v4 = this->m_pSimObject;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
      else
        v6 = (UEL::ParametersBase *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v4,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v4,
                                                                                         UFG::UELComponent::_TypeUID));
    }
    else
    {
      v6 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
    }
    if ( v6 )
      UEL::gCurrentParameters = v6 + 88;
  }
  v7 = (signed __int64)&v3->mActiveAIEntityComponent.m_Changed;
  v8 = (signed __int64)&v3->mPostAnimUpdateList.mNode.mNext[-1].mNext;
  if ( (unsigned int *)v8 != &v3->mActiveAIEntityComponent.m_Changed )
  {
    do
    {
      v9 = *(_QWORD *)(v8 + 16) - 8i64;
      (**(void (***)(void))v8)();
      v8 = v9;
    }
    while ( v9 != v7 );
  }
  UEL::gCurrentParameters = v2;
}

