// File Line: 25
// RVA: 0x3634A0
__int64 __fastcall Render::DynamicLightComponent::GetTypeSize(Render::DynamicLightComponent *this)
{
  return 240i64;
}

// File Line: 26
// RVA: 0x14AEB20
__int64 dynamic_initializer_for__UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList__);
}

// File Line: 30
// RVA: 0x32EF10
void __fastcall UFG::GetInPedFormationComponent::GetInPedFormationComponent(
        UFG::GetInPedFormationComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  this->mNext = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInPedFormationComponent::`vftable;
  this->m_NodeList.mNode.mPrev = &this->m_NodeList.mNode;
  this->m_NodeList.mNode.mNext = &this->m_NodeList.mNode;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->m_pHealthComponent);
  mPrev = UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev;
  UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList;
  UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::GetInPedFormationComponent::_GetInPedFormationComponentTypeUID,
    "GetInPedFormationComponent");
}

// File Line: 36
// RVA: 0x337820
void __fastcall UFG::GetInPedFormationComponent::~GetInPedFormationComponent(UFG::GetInPedFormationComponent *this)
{
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *p_m_NodeList; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mNext; // rax
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v10; // rcx
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInPedFormationComponent::`vftable;
  p_m_NodeList = (UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&this->m_NodeList;
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
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
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
  this->mPrev = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  this->mNext = &this->UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 48
// RVA: 0x37EF10
UFG::GetInPedFormationComponent *__fastcall UFG::GetInPedFormationComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  char *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "GetInPedFormationComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::GetInPedFormationComponent::GetInPedFormationComponent(
      (UFG::GetInPedFormationComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v8 = 34;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::GetInPedFormationComponent *)v6;
}

// File Line: 62
// RVA: 0x378D70
void __fastcall UFG::GetInPedFormationComponent::OnAttach(
        UFG::GetInPedFormationComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( p_m_pAIEntityComponent->m_pSimComponent )
  {
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev = p_m_pAIEntityComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIEntityComponent->m_pSimObject = 0i64;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_8;
  }
  if ( p_m_pAIEntityComponent->m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || p_m_pAIEntityComponent->mNext != p_m_pAIEntityComponent) )
  {
    v7 = p_m_pAIEntityComponent->mNext;
    v8 = p_m_pAIEntityComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIEntityComponent->m_Changed = 1;
  p_m_pAIEntityComponent->m_pSimObject = object;
  p_m_pAIEntityComponent->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_m_pAIEntityComponent,
    object);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pActionTreeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHealthComponent,
    object);
}

// File Line: 71
// RVA: 0x37A780
void __fastcall UFG::GetInPedFormationComponent::OnDetach(UFG::GetInPedFormationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_m_pHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *i; // rdx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v18; // rcx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v19; // rax

  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIEntityComponent->m_pSimObject = 0i64;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_8;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v5 = p_m_pAIEntityComponent->mPrev;
    v6 = p_m_pAIEntityComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  p_m_pAIEntityComponent->m_Changed = 1;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v8 = p_m_pActionTreeComponent->mPrev;
    v9 = this->m_pActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v10 = p_m_pActionTreeComponent->mPrev;
    v11 = this->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pHealthComponent = &this->m_pHealthComponent;
  if ( this->m_pHealthComponent.m_pSimComponent )
  {
    v13 = p_m_pHealthComponent->mPrev;
    v14 = this->m_pHealthComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pHealthComponent.m_pSimObject = 0i64;
    this->m_pHealthComponent.mNext = &this->m_pHealthComponent;
    p_m_pHealthComponent->mPrev = p_m_pHealthComponent;
    goto LABEL_22;
  }
  if ( this->m_pHealthComponent.m_pSimObject
    && (p_m_pHealthComponent->mPrev != p_m_pHealthComponent
     || this->m_pHealthComponent.mNext != &this->m_pHealthComponent) )
  {
    v15 = p_m_pHealthComponent->mPrev;
    v16 = this->m_pHealthComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pHealthComponent.m_Changed = 1;
  for ( i = this->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **)&this->m_BoundComponentHandles.mNode.mNext;
        i = this->m_NodeList.mNode.mNext )
  {
    v18 = i->mPrev;
    v19 = i->mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **, __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}

// File Line: 80
// RVA: 0x351EC0
void __fastcall UFG::GetInPedFormationComponent::DeleteList(UFG::GetInFormationComponent *this)
{
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // rdi
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v4; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *mPrev; // rdx

  mNext = this->m_NodeList.mNode.mNext;
  for ( i = &this->m_BoundComponentHandles.mNode.mNext;
        &mNext[-2].mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)i;
        mNext = this->m_NodeList.mNode.mNext )
  {
    v4 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **, __int64))mNext[-2].mNext->mPrev)(
        &mNext[-2].mNext,
        1i64);
  }
}

// File Line: 85
// RVA: 0x36D7E0
UFG::GetInPedFormationNode *__fastcall UFG::GetInPedFormationComponent::MakeNewNode(
        UFG::GetInPedFormationComponent *this)
{
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // r8
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *mPrev; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "GetInPedFormationNode", 0i64, 1u);
  if ( v2 )
  {
    UFG::GetInPedFormationNode::GetInPedFormationNode((UFG::GetInPedFormationNode *)v2, this);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  mPrev = this->m_NodeList.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)(v4 + 24);
  *(_QWORD *)(v4 + 24) = mPrev;
  *(_QWORD *)(v4 + 32) = &this->m_NodeList;
  this->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)(v4 + 24);
  return (UFG::GetInPedFormationNode *)v4;
}

// File Line: 96
// RVA: 0x32F040
void __fastcall UFG::GetInPedFormationNode::GetInPedFormationNode(
        UFG::GetInPedFormationNode *this,
        UFG::GetInPedFormationComponent *owner)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInPedFormationComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  this->mPrev = &this->UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>;
  this->mNext = &this->UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>;
  UFG::qSafePointerNode<UFG::GetInPedFormationNode>::qSafePointerNode<UFG::GetInPedFormationNode>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::GetInPedFormationNode::`vftable;
  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.mPrev = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
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
    v8 = owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v8->mNext = p_m_pOwner;
    p_m_pOwner->mPrev = v8;
    this->m_pOwner.mNext = &owner->m_SafePointerList.mNode;
    owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pOwner;
  }
  this->m_Registrator = 0i64;
  UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(this);
  this->m_SlotIndex = -1;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    v9 = p_m_pTargetPedFormationManagerComponent->mPrev;
    v10 = this->m_pTargetPedFormationManagerComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  }
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 102
// RVA: 0x3379E0
void __fastcall UFG::GetInPedFormationNode::~GetInPedFormationNode(UFG::GetInPedFormationNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInPedFormationComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v14; // rcx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v15; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::GetInPedFormationNode::`vftable;
  p_m_pOwner = &this->m_pOwner;
  if ( this->m_pOwner.m_pPointer )
  {
    mPrev = p_m_pOwner->mPrev;
    mNext = p_m_pOwner->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pOwner->mPrev = p_m_pOwner;
    p_m_pOwner->mNext = p_m_pOwner;
  }
  p_m_pOwner->m_pPointer = 0i64;
  v5 = p_m_pOwner->mPrev;
  v6 = p_m_pOwner->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pOwner->mPrev = p_m_pOwner;
  p_m_pOwner->mNext = p_m_pOwner;
  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    v8 = p_m_pTargetPedFormationManagerComponent->mPrev;
    v9 = this->m_pTargetPedFormationManagerComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  }
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetPedFormationManagerComponent->mPrev;
  v11 = this->m_pTargetPedFormationManagerComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::qSafePointerNode<UFG::GetInPedFormationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v12 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev;
  v13 = this->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v14 = this->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mPrev = &this->UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>;
  this->mNext = &this->UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>;
}G::qNode<UFG::GetInPedFormationNode,UFG::GetInPedForm

// File Line: 175
// RVA: 0x38A980
void __fastcall UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(UFG::GetInPedFormationNode *this)
{
  UFG::PedFormationManagerComponent *m_pPointer; // rdi
  __int64 i; // rbx
  UFG::GetInPedFormationNode *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer;
  if ( m_pPointer )
  {
    for ( i = 0i64; (unsigned int)i < m_pPointer->m_Slots.size; i = (unsigned int)(i + 1) )
    {
      v4 = m_pPointer->m_Slots.p[i].m_pMember.m_pPointer;
      if ( v4 && this == v4 )
        UFG::PedFormationManagerComponent::UnregisterSlot(m_pPointer, i);
    }
  }
  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  this->m_SlotIndex = -1;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetPedFormationManagerComponent->mPrev;
    mNext = this->m_pTargetPedFormationManagerComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  }
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 192
// RVA: 0x387D60
void __fastcall UFG::GetInPedFormationNode::SetTargetPedFormationManagerComponent(
        UFG::GetInPedFormationNode *this,
        UFG::PedFormationManagerComponent *target_formation_manager_component)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetPedFormationManagerComponent->mPrev;
    mNext = p_m_pTargetPedFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    p_m_pTargetPedFormationManagerComponent->mNext = p_m_pTargetPedFormationManagerComponent;
  }
  p_m_pTargetPedFormationManagerComponent->m_pPointer = target_formation_manager_component;
  if ( target_formation_manager_component )
  {
    v5 = target_formation_manager_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_m_pTargetPedFormationManagerComponent;
    p_m_pTargetPedFormationManagerComponent->mPrev = v5;
    p_m_pTargetPedFormationManagerComponent->mNext = &target_formation_manager_component->m_SafePointerList.mNode;
    target_formation_manager_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTargetPedFormationManagerComponent;
  }
}

