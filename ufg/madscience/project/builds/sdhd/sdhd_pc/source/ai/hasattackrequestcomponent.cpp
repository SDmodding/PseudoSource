// File Line: 34
// RVA: 0x3633A0
const char *__fastcall UFG::HasAttackRequestComponent::GetTypeName(UFG::HasAttackRequestComponent *this)
{
  return "HasAttackRequestComponent";
}

// File Line: 35
// RVA: 0x14AEB60
__int64 dynamic_initializer_for__UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList__);
}

// File Line: 39
// RVA: 0x32F770
void __fastcall UFG::HasAttackRequestComponent::HasAttackRequestComponent(
        UFG::HasAttackRequestComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  this->mNext = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HasAttackRequestComponent::`vftable;
  this->m_NodeList.mNode.mPrev = &this->m_NodeList.mNode;
  this->m_NodeList.mNode.mNext = &this->m_NodeList.mNode;
  this->m_AttackRightsScoreBonusTaskList.mNode.mPrev = &this->m_AttackRightsScoreBonusTaskList.mNode;
  this->m_AttackRightsScoreBonusTaskList.mNode.mNext = &this->m_AttackRightsScoreBonusTaskList.mNode;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  mPrev = UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev;
  UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList;
  UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::HasAttackRequestComponent::_HasAttackRequestComponentTypeUID,
    "HasAttackRequestComponent");
  this->m_DebugStringTimestamp = -1;
  *(_QWORD *)this->m_AttackCanceledUntilTime = 0xC7C34F80C7C34F80ui64;
  this->m_AttackCanceledUntilTime[2] = -99999.0;
}

// File Line: 52
// RVA: 0x338190
void __fastcall UFG::HasAttackRequestComponent::~HasAttackRequestComponent(UFG::HasAttackRequestComponent *this)
{
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *p_m_NodeList; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mNext; // rax
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v10; // rcx
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HasAttackRequestComponent::`vftable;
  p_m_NodeList = &this->m_NodeList;
  p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)&this->m_NodeList.mNode.mNext[-2].mNext;
  for ( i = &this->m_BoundComponentHandles.mNode.mNext;
        p_mNext != i;
        p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)&p_m_NodeList->mNode.mNext[-2].mNext )
  {
    v5 = p_mNext + 3;
    v6 = p_mNext[3];
    v7 = p_mNext[4];
    v6->mNext = v7;
    v7->mPrev = v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)24 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v5 - 3))(v5 - 3, 1i64);
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AttackRightsScoreBonusTaskList);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes(p_m_NodeList);
  mPrev = p_m_NodeList->mNode.mPrev;
  mNext = p_m_NodeList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_NodeList->mNode.mPrev = &p_m_NodeList->mNode;
  p_m_NodeList->mNode.mNext = &p_m_NodeList->mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  this->mNext = &this->UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 70
// RVA: 0x37EFF0
UFG::HasAttackRequestComponent *__fastcall UFG::HasAttackRequestComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x178ui64, "HasAttackRequestComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::HasAttackRequestComponent::HasAttackRequestComponent(
      (UFG::HasAttackRequestComponent *)v3,
      pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v7 = 35;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return (UFG::HasAttackRequestComponent *)v5;
}

// File Line: 79
// RVA: 0x378E20
void __fastcall UFG::HasAttackRequestComponent::OnAttach(
        UFG::HasAttackRequestComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIScriptInterfaceComponent,
    object);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHealthComponent,
    object);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pActionTreeComponent,
    object);
}

// File Line: 90
// RVA: 0x37A8E0
void __fastcall UFG::HasAttackRequestComponent::OnDetach(UFG::HasAttackRequestComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_m_pHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *i; // rdx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v28; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v29; // rax

  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = this->m_pTargetingSystemBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTargetingSystemBaseComponent->m_pSimObject = 0i64;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_8;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v5 = p_m_pTargetingSystemBaseComponent->mPrev;
    v6 = p_m_pTargetingSystemBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  p_m_pTargetingSystemBaseComponent->m_Changed = 1;
  if ( this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v8 = p_m_pAIScriptInterfaceComponent->mPrev;
    v9 = this->m_pAIScriptInterfaceComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    goto LABEL_15;
  }
  if ( this->m_pAIScriptInterfaceComponent.m_pSimObject
    && (p_m_pAIScriptInterfaceComponent->mPrev != p_m_pAIScriptInterfaceComponent
     || this->m_pAIScriptInterfaceComponent.mNext != &this->m_pAIScriptInterfaceComponent) )
  {
    v10 = p_m_pAIScriptInterfaceComponent->mPrev;
    v11 = this->m_pAIScriptInterfaceComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAIScriptInterfaceComponent.m_Changed = 1;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v13 = p_m_pTransformNodeComponent->mPrev;
    v14 = this->m_pTransformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pTransformNodeComponent.m_pSimObject = 0i64;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_22;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v15 = p_m_pTransformNodeComponent->mPrev;
    v16 = this->m_pTransformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pTransformNodeComponent.m_Changed = 1;
  p_m_pHealthComponent = &this->m_pHealthComponent;
  if ( this->m_pHealthComponent.m_pSimComponent )
  {
    v18 = p_m_pHealthComponent->mPrev;
    v19 = this->m_pHealthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pHealthComponent.m_pSimObject = 0i64;
    this->m_pHealthComponent.mNext = &this->m_pHealthComponent;
    p_m_pHealthComponent->mPrev = p_m_pHealthComponent;
    goto LABEL_29;
  }
  if ( this->m_pHealthComponent.m_pSimObject
    && (p_m_pHealthComponent->mPrev != p_m_pHealthComponent
     || this->m_pHealthComponent.mNext != &this->m_pHealthComponent) )
  {
    v20 = p_m_pHealthComponent->mPrev;
    v21 = this->m_pHealthComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pHealthComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v23 = p_m_pActionTreeComponent->mPrev;
    v24 = this->m_pActionTreeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_36;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v25 = p_m_pActionTreeComponent->mPrev;
    v26 = this->m_pActionTreeComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pActionTreeComponent.m_Changed = 1;
  for ( i = this->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)&this->m_BoundComponentHandles.mNode.mNext;
        i = this->m_NodeList.mNode.mNext )
  {
    v28 = i->mPrev;
    v29 = i->mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **, __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}

// File Line: 101
// RVA: 0x382BE0
void __fastcall UFG::HasAttackRequestComponent::Reset(UFG::HasAttackRequestComponent *this)
{
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // rdi
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v4; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mPrev; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *j; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v7; // rax
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v8; // rcx

  mNext = this->m_NodeList.mNode.mNext;
  for ( i = &this->m_BoundComponentHandles.mNode.mNext;
        &mNext[-2].mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)i;
        mNext = this->m_NodeList.mNode.mNext )
  {
    v4 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **, __int64))mNext[-2].mNext->mPrev)(
        &mNext[-2].mNext,
        1i64);
  }
  for ( j = this->m_AttackRightsScoreBonusTaskList.mNode.mNext;
        &j[-3].mNext != (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> **)&this->m_BoundComponentHandles.mNode.mNext;
        j = this->m_AttackRightsScoreBonusTaskList.mNode.mNext )
  {
    v7 = j->mNext;
    v8 = j->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    j->mPrev = j;
    j->mNext = j;
  }
}

// File Line: 131
// RVA: 0x36D860
UFG::HasAttackRequestNode *__fastcall UFG::HasAttackRequestComponent::MakeNewNode(
        UFG::HasAttackRequestComponent *this,
        ActionContext *action_context,
        HasAttackRequestCondition *has_attack_request_condition)
{
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // r8
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mPrev; // rax

  v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xE8ui64, "HasAttackRequestNode", 0i64, 1u);
  if ( v6 )
  {
    UFG::HasAttackRequestNode::HasAttackRequestNode(
      (UFG::HasAttackRequestNode *)v6,
      this,
      action_context,
      has_attack_request_condition);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  mPrev = this->m_NodeList.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)(v8 + 24);
  *(_QWORD *)(v8 + 24) = mPrev;
  *(_QWORD *)(v8 + 32) = &this->m_NodeList;
  this->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)(v8 + 24);
  return (UFG::HasAttackRequestNode *)v8;
}

// File Line: 140
// RVA: 0x354650
// bad sp value at call has been detected, the output may be wrong!
void __fastcall UFG::HasAttackRequestComponent::DrawDebugString(
        UFG::HasAttackRequestComponent *this,
        Render::View *view)
{
  unsigned int v3; // r12d
  UFG::HasAttackRequestNode *p_mNext; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // r15
  UFG::AttackRightsComponent *AttackTarget; // rax
  UFG::AttackRightsComponent *v7; // r9
  int v8; // esi
  __int64 v9; // r8
  __int64 m_AttackType; // r10
  int v11; // edx
  int v12; // ebx
  char **v13; // rax
  UFG::qString *v14; // rax
  UFG::qString *v15; // rax
  const char *v16; // rdx
  CanAttackConditionGroup *m_pPointer; // rcx
  char v18; // al
  const char *v19; // rdx
  unsigned int v20; // eax
  const char *v21; // rdx
  float v22; // xmm6_4
  UFG::HasAttackRequestNode *v23; // rbx
  __int64 j; // rax
  float v25; // xmm0_4
  UFG::AttackRightsComponent *v26; // rax
  float AttackerScore; // xmm0_4
  UFG::qString *v28; // rax
  UFG::qString *v29; // rax
  UFG::SimComponent *m_pSimComponent; // rbx
  Render::DebugDrawContext *Context; // rax
  UFG::qString debug_string; // [rsp+0h] [rbp-59h] BYREF
  UFG::qString v33; // [rsp+28h] [rbp-31h] BYREF
  __int64 v34; // [rsp+50h] [rbp-9h]
  UFG::qString v35; // [rsp+58h] [rbp-1h] BYREF

  v34 = -2i64;
  v3 = UFG::Metrics::msFrameCount;
  if ( UFG::Metrics::msFrameCount != this->m_DebugStringTimestamp
    && this->m_pTransformNodeComponent.m_pSimComponent
    && this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    UFG::qString::qString(&debug_string);
    p_mNext = (UFG::HasAttackRequestNode *)&this->m_NodeList.mNode.mNext[-2].mNext;
    for ( i = &this->m_BoundComponentHandles.mNode.mNext;
          p_mNext != (UFG::HasAttackRequestNode *)i;
          p_mNext = (UFG::HasAttackRequestNode *)&p_mNext->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mNext[-2].mNext )
    {
      AttackTarget = UFG::HasAttackRequestNode::GetAttackTarget(p_mNext);
      v7 = AttackTarget;
      if ( AttackTarget && p_mNext )
      {
        v8 = 0;
        v9 = 0i64;
        m_AttackType = p_mNext->m_AttackType;
        v11 = AttackTarget->m_NumAttackSlots[m_AttackType];
        while ( 1 )
        {
          v12 = 0;
          if ( v11 > 0 )
            break;
LABEL_12:
          ++v8;
          if ( ++v9 >= 2 )
            goto LABEL_26;
        }
        v13 = (char **)(&v7->m_pAttackSlot[0][0][0].m_pPointer + 384 * m_AttackType + 192 * v9);
        while ( p_mNext != (UFG::HasAttackRequestNode *)*v13 )
        {
          ++v12;
          v13 += 3;
          if ( v12 >= v11 )
            goto LABEL_12;
        }
        UFG::qString::qString(&v35, "\n%s", "?");
        UFG::qString::operator+=(&debug_string, v14);
        UFG::qString::~qString(&v35);
        UFG::qString::qString(&v33, "\n%s: %d", UFG::AttackSlotListNames[v8], (unsigned int)v12);
        UFG::qString::operator+=(&debug_string, v15);
        UFG::qString::~qString(&v33);
        v16 = "\nScript can_gain_attack_rights(): true";
        if ( (BYTE1(this->m_pAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) & 0x10) == 0 )
          v16 = "\nScript can_gain_attack_rights(): FALSE";
        UFG::qString::operator+=(&debug_string, v16);
        m_pPointer = p_mNext->m_pCanAttackConditions.m_pPointer;
        if ( !m_pPointer
          || !p_mNext->m_pActionContextCopy
          || (v18 = ((__int64 (__fastcall *)(CanAttackConditionGroup *))m_pPointer->ConditionGroup::Condition::Expression::IMemberMap::vfptr[1].FindWithOldPath)(m_pPointer),
              v19 = "\nCondition group: true",
              !v18) )
        {
          v19 = "\nCondition group: FALSE";
        }
        UFG::qString::operator+=(&debug_string, v19);
        if ( UFG::Metrics::msInstance.mSimFrameCount )
          v20 = UFG::Metrics::msInstance.mSimFrameCount - 1;
        else
          v20 = -1;
        v21 = "\nCurrently polling condition";
        if ( p_mNext->m_LastFramePolled < v20 )
          v21 = "\nNOT currently polling condition";
        UFG::qString::operator+=(&debug_string, v21);
        UFG::qString::operator+=(&debug_string, "\n");
      }
LABEL_26:
      ;
    }
    UFG::qString::operator+=(&debug_string, "\n=====================================");
    v22 = FLOAT_N1_0;
    v23 = (UFG::HasAttackRequestNode *)&this->m_NodeList.mNode.mNext[-2].mNext;
    for ( j = (__int64)v23;
          (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)j != i;
          j = *(_QWORD *)(j + 32) - 24i64 )
    {
      v25 = *(float *)(j + 108);
      if ( v25 >= 0.0 && (v22 < 0.0 || v22 <= v25) )
        v22 = *(float *)(j + 108);
    }
    UFG::qString::Set(&debug_string, &customCaption);
    if ( v23 )
    {
      v26 = UFG::HasAttackRequestNode::GetAttackTarget(v23);
      if ( v26 )
      {
        AttackerScore = UFG::AttackRightsComponent::GetAttackerScore(v26, v23, &debug_string);
        UFG::qString::qString(&v33, "\nFinal score: %.1f", AttackerScore);
        UFG::qString::operator+=(&debug_string, v28);
        UFG::qString::~qString(&v33);
        UFG::qString::qString(&v33, "\n\nScore last time list was sorted: %.1f", v22);
        UFG::qString::operator+=(&debug_string, v29);
        UFG::qString::~qString(&v33);
      }
    }
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(
      Context,
      (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles,
      &UFG::qColour::White,
      debug_string.mData);
    this->m_DebugStringTimestamp = v3;
    UFG::qString::~qString(&debug_string);
  }
}

// File Line: 270
// RVA: 0x32F950
void __fastcall UFG::HasAttackRequestNode::HasAttackRequestNode(
        UFG::HasAttackRequestNode *this,
        UFG::HasAttackRequestComponent *owner,
        ActionContext *action_context,
        HasAttackRequestCondition *has_attack_request_condition)
{
  ActionContext *v8; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::HasAttackRequestComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::allocator::free_link *v13; // rax
  ActionContext *v14; // rax

  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>;
  UFG::qSafePointerNode<UFG::HasAttackRequestNode>::qSafePointerNode<UFG::HasAttackRequestNode>(this);
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)&UFG::HasAttackRequestNode::`vftable;
  this->m_pCanAttackConditions.mPrev = &this->m_pCanAttackConditions;
  this->m_pCanAttackConditions.mNext = &this->m_pCanAttackConditions;
  v8 = 0i64;
  this->m_pCanAttackConditions.m_pPointer = 0i64;
  this->m_pAttackeeRequest.mPrev = &this->m_pAttackeeRequest;
  this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  this->m_pSecondaryCharacterRequest.mPrev = &this->m_pSecondaryCharacterRequest;
  this->m_pSecondaryCharacterRequest.mNext = &this->m_pSecondaryCharacterRequest;
  this->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
  p_m_pOwner = &this->m_pOwner;
  this->m_pOwner.mPrev = &this->m_pOwner;
  this->m_pOwner.mNext = &this->m_pOwner;
  this->m_pOwner.m_pPointer = 0i64;
  if ( this->m_pOwner.m_pPointer )
  {
    mPrev = p_m_pOwner->mPrev;
    mNext = this->m_pOwner.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pOwner->mPrev = p_m_pOwner;
    this->m_pOwner.mNext = &this->m_pOwner;
  }
  this->m_pOwner.m_pPointer = owner;
  if ( owner )
  {
    v12 = owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v12->mNext = p_m_pOwner;
    p_m_pOwner->mPrev = v12;
    this->m_pOwner.mNext = &owner->m_SafePointerList.mNode;
    owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pOwner;
  }
  v13 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v13 )
  {
    ActionContext::ActionContext((ActionContext *)v13, action_context);
    v8 = v14;
  }
  this->m_pActionContextCopy = v8;
  UFG::HasAttackRequestNode::ReInit(this, action_context, has_attack_request_condition);
}

// File Line: 278
// RVA: 0x3383A0
void __fastcall UFG::HasAttackRequestNode::~HasAttackRequestNode(UFG::HasAttackRequestNode *this)
{
  ActionContext *m_pActionContextCopy; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::HasAttackRequestComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pSecondaryCharacterRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pAttackeeRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<CanAttackConditionGroup,CanAttackConditionGroup> *p_m_pCanAttackConditions; // rdx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v27; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v28; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v29; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v33; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v34; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)&UFG::HasAttackRequestNode::`vftable;
  m_pActionContextCopy = this->m_pActionContextCopy;
  if ( m_pActionContextCopy )
  {
    if ( m_pActionContextCopy->mSimObject.m_pPointer )
    {
      mPrev = m_pActionContextCopy->mSimObject.mPrev;
      mNext = m_pActionContextCopy->mSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      m_pActionContextCopy->mSimObject.mPrev = &m_pActionContextCopy->mSimObject;
      m_pActionContextCopy->mSimObject.mNext = &m_pActionContextCopy->mSimObject;
    }
    m_pActionContextCopy->mSimObject.m_pPointer = 0i64;
    v5 = m_pActionContextCopy->mSimObject.mPrev;
    v6 = m_pActionContextCopy->mSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    m_pActionContextCopy->mSimObject.mPrev = &m_pActionContextCopy->mSimObject;
    m_pActionContextCopy->mSimObject.mNext = &m_pActionContextCopy->mSimObject;
    operator delete[](m_pActionContextCopy);
  }
  this->m_pActionContextCopy = 0i64;
  p_m_pOwner = &this->m_pOwner;
  if ( this->m_pOwner.m_pPointer )
  {
    v8 = p_m_pOwner->mPrev;
    v9 = this->m_pOwner.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pOwner->mPrev = p_m_pOwner;
    this->m_pOwner.mNext = &this->m_pOwner;
  }
  this->m_pOwner.m_pPointer = 0i64;
  v10 = p_m_pOwner->mPrev;
  v11 = this->m_pOwner.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pOwner->mPrev = p_m_pOwner;
  this->m_pOwner.mNext = &this->m_pOwner;
  p_m_pSecondaryCharacterRequest = &this->m_pSecondaryCharacterRequest;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v13 = p_m_pSecondaryCharacterRequest->mPrev;
    v14 = this->m_pSecondaryCharacterRequest.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
    this->m_pSecondaryCharacterRequest.mNext = &this->m_pSecondaryCharacterRequest;
  }
  this->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
  v15 = p_m_pSecondaryCharacterRequest->mPrev;
  v16 = this->m_pSecondaryCharacterRequest.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
  this->m_pSecondaryCharacterRequest.mNext = &this->m_pSecondaryCharacterRequest;
  p_m_pAttackeeRequest = &this->m_pAttackeeRequest;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    v18 = p_m_pAttackeeRequest->mPrev;
    v19 = this->m_pAttackeeRequest.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
    this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  }
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  v20 = p_m_pAttackeeRequest->mPrev;
  v21 = this->m_pAttackeeRequest.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
  this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  p_m_pCanAttackConditions = &this->m_pCanAttackConditions;
  if ( this->m_pCanAttackConditions.m_pPointer )
  {
    v23 = p_m_pCanAttackConditions->mPrev;
    v24 = this->m_pCanAttackConditions.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pCanAttackConditions->mPrev = p_m_pCanAttackConditions;
    this->m_pCanAttackConditions.mNext = &this->m_pCanAttackConditions;
  }
  this->m_pCanAttackConditions.m_pPointer = 0i64;
  v25 = p_m_pCanAttackConditions->mPrev;
  v26 = this->m_pCanAttackConditions.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pCanAttackConditions->mPrev = p_m_pCanAttackConditions;
  this->m_pCanAttackConditions.mNext = &this->m_pCanAttackConditions;
  v27 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev;
  v28 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList>;
  v29 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev;
  v30 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)&UFG::qSafePointerNode<UFG::HasAttackRequestNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v31 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
  v32 = this->m_SafePointerList.mNode.mNext;
  v31->mNext = v32;
  v32->mPrev = v31;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v33 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mPrev;
  v34 = this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mPrev = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>;
  this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>::mNext = &this->UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>;
}

// File Line: 285
// RVA: 0x37F5A0
void __fastcall UFG::HasAttackRequestNode::ReInit(
        UFG::HasAttackRequestNode *this,
        ActionContext *action_context,
        HasAttackRequestCondition *has_attack_request_condition)
{
  __int64 mOffset; // rax
  CanAttackConditionGroup *v6; // r8
  UFG::qSafePointer<CanAttackConditionGroup,CanAttackConditionGroup> *p_m_pCanAttackConditions; // rdx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v10; // rax

  this->m_AttackType = (unsigned __int8)has_attack_request_condition->m_AttackType.mValue;
  this->m_AttackerType = (unsigned __int8)has_attack_request_condition->m_AttackerType.mValue;
  this->m_TargetType = (unsigned __int8)has_attack_request_condition->m_TargetType.mValue;
  this->m_InCoverType = (unsigned __int8)has_attack_request_condition->m_InCoverType.mValue;
  this->m_CopySecondaryCharacterToTargetType = (unsigned __int8)has_attack_request_condition->m_CopySecondaryCharacterToTargetType.mValue;
  mOffset = has_attack_request_condition->m_pCanAttackConditions.mOffset;
  if ( mOffset )
    v6 = (CanAttackConditionGroup *)((char *)&has_attack_request_condition->m_pCanAttackConditions + mOffset);
  else
    v6 = 0i64;
  p_m_pCanAttackConditions = &this->m_pCanAttackConditions;
  if ( this->m_pCanAttackConditions.m_pPointer )
  {
    mPrev = p_m_pCanAttackConditions->mPrev;
    mNext = p_m_pCanAttackConditions->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCanAttackConditions->mPrev = p_m_pCanAttackConditions;
    p_m_pCanAttackConditions->mNext = p_m_pCanAttackConditions;
  }
  p_m_pCanAttackConditions->m_pPointer = v6;
  if ( v6 )
  {
    v10 = v6->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pCanAttackConditions;
    p_m_pCanAttackConditions->mPrev = v10;
    p_m_pCanAttackConditions->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pCanAttackConditions;
  }
  ActionContext::operator=(this->m_pActionContextCopy, action_context);
  this->m_LastTimePolled = -99999.0;
  this->m_LastFramePolled = 0;
  this->m_CurrentlyAttacking = 0;
  this->m_TimeFinishedAttacking = -99999.0;
  this->m_Registrator = 0i64;
  this->m_Score = -1.0;
}

// File Line: 398
// RVA: 0x359D80
UFG::AttackRightsComponent *__fastcall UFG::HasAttackRequestNode::GetAttackTarget(UFG::HasAttackRequestNode *this)
{
  UFG::SimComponent *m_pPointer; // rax
  __int64 v2; // r9
  UFG::SimObject *v3; // r9
  __int16 m_Flags; // cx
  unsigned int v6; // edx
  UFG::SimObjectGame *v7; // rcx
  bool v8; // zf

  m_pPointer = this->m_pOwner.m_pPointer;
  if ( m_pPointer )
  {
    v2 = *(_QWORD *)&m_pPointer[2].m_TypeUID;
    if ( v2 )
    {
      v3 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->m_TargetType + *(_QWORD *)(v2 + 96) + 8i64)
                              + *(_QWORD *)(v2 + 88)
                              + 40);
      if ( v3 )
      {
        m_Flags = v3->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
          return (UFG::AttackRightsComponent *)v3->m_Components.p[46].m_pComponent;
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
        {
          v6 = UFG::AttackRightsComponent::_TypeUID;
          v7 = (UFG::SimObjectGame *)v3;
        }
        else
        {
          v6 = UFG::AttackRightsComponent::_TypeUID;
          v8 = (m_Flags & 0x1000) == 0;
          v7 = (UFG::SimObjectGame *)v3;
          if ( v8 )
            return (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                   v3,
                                                   UFG::AttackRightsComponent::_TypeUID);
        }
        return (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, v6);
      }
    }
  }
  return 0i64;
}

// File Line: 409
// RVA: 0x3821A0
void __fastcall UFG::HasAttackRequestNode::RequestAttack(
        UFG::HasAttackRequestNode *this,
        UFG::AttackRightsComponent *attackee,
        UFG::HasAttackRequestNode *secondary_character)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pAttackeeRequest; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pSecondaryCharacterRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *m_pPointer; // rax
  UFG::TargetingSystemBaseComponent *v13; // rcx
  UFG::SimComponent *v14; // rax

  p_m_pAttackeeRequest = &this->m_pAttackeeRequest;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    mPrev = p_m_pAttackeeRequest->mPrev;
    mNext = this->m_pAttackeeRequest.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
    this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  }
  this->m_pAttackeeRequest.m_pPointer = attackee;
  if ( attackee )
  {
    v7 = attackee->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_m_pAttackeeRequest;
    p_m_pAttackeeRequest->mPrev = v7;
    this->m_pAttackeeRequest.mNext = &attackee->m_SafePointerList.mNode;
    attackee->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pAttackeeRequest;
  }
  p_m_pSecondaryCharacterRequest = &this->m_pSecondaryCharacterRequest;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v9 = p_m_pSecondaryCharacterRequest->mPrev;
    v10 = this->m_pSecondaryCharacterRequest.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
    this->m_pSecondaryCharacterRequest.mNext = &this->m_pSecondaryCharacterRequest;
  }
  this->m_pSecondaryCharacterRequest.m_pPointer = secondary_character;
  if ( secondary_character )
  {
    v11 = secondary_character->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev;
    v11->mNext = p_m_pSecondaryCharacterRequest;
    p_m_pSecondaryCharacterRequest->mPrev = v11;
    this->m_pSecondaryCharacterRequest.mNext = &secondary_character->m_SafePointerList.mNode;
    secondary_character->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::HasAttackRequestNode>::mPrev = p_m_pSecondaryCharacterRequest;
  }
  m_pPointer = this->m_pOwner.m_pPointer;
  this->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( m_pPointer )
  {
    v13 = *(UFG::TargetingSystemBaseComponent **)&m_pPointer[2].m_TypeUID;
    if ( v13 )
    {
      if ( secondary_character )
      {
        v14 = secondary_character->m_pOwner.m_pPointer;
        if ( v14 )
          UFG::TargetingSystemBaseComponent::SetTarget(
            v13,
            this->m_CopySecondaryCharacterToTargetType,
            v14->m_pSimObject);
        else
          UFG::TargetingSystemBaseComponent::SetTarget(v13, this->m_CopySecondaryCharacterToTargetType, 0i64);
      }
    }
  }
}

// File Line: 421
// RVA: 0x34EEB0
void __fastcall UFG::HasAttackRequestNode::ClearAttackRequest(UFG::HasAttackRequestNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pAttackeeRequest; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pSecondaryCharacterRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rax

  p_m_pAttackeeRequest = &this->m_pAttackeeRequest;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    mPrev = p_m_pAttackeeRequest->mPrev;
    mNext = this->m_pAttackeeRequest.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
    this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  }
  p_m_pSecondaryCharacterRequest = &this->m_pSecondaryCharacterRequest;
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v5 = p_m_pSecondaryCharacterRequest->mPrev;
    v6 = p_m_pSecondaryCharacterRequest->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
    p_m_pSecondaryCharacterRequest->mNext = p_m_pSecondaryCharacterRequest;
  }
  p_m_pSecondaryCharacterRequest->m_pPointer = 0i64;
}

// File Line: 427
// RVA: 0x3582C0
void __fastcall UFG::HasAttackRequestNode::FinishedAttacking(UFG::HasAttackRequestNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pAttackeeRequest; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *p_m_pSecondaryCharacterRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::AttackRightsComponent *AttackTarget; // rax

  p_m_pAttackeeRequest = &this->m_pAttackeeRequest;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    mPrev = p_m_pAttackeeRequest->mPrev;
    mNext = this->m_pAttackeeRequest.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
    this->m_pAttackeeRequest.mNext = &this->m_pAttackeeRequest;
  }
  p_m_pSecondaryCharacterRequest = &this->m_pSecondaryCharacterRequest;
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v6 = p_m_pSecondaryCharacterRequest->mPrev;
    v7 = p_m_pSecondaryCharacterRequest->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pSecondaryCharacterRequest->mPrev = p_m_pSecondaryCharacterRequest;
    p_m_pSecondaryCharacterRequest->mNext = p_m_pSecondaryCharacterRequest;
  }
  p_m_pSecondaryCharacterRequest->m_pPointer = 0i64;
  AttackTarget = UFG::HasAttackRequestNode::GetAttackTarget(this);
  if ( AttackTarget )
    UFG::AttackRightsComponent::FinishedAttacking(AttackTarget, this);
}

// File Line: 526
// RVA: 0x362600
UFG::qBaseNodeRB *__fastcall UFG::HasAttackRequestNode::GetSimObject(UFG::HasAttackRequestNode *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_pOwner.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

