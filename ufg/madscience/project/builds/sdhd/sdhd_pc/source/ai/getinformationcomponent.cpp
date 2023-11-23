// File Line: 26
// RVA: 0x35D940
UFG::ComponentIDDesc *__fastcall UFG::GetInFormationComponent::GetDesc(UFG::GetInFormationComponent *this)
{
  return &UFG::GetInFormationComponent::_TypeIDesc;
}

// File Line: 27
// RVA: 0x14AEB00
__int64 dynamic_initializer_for__UFG::GetInFormationComponent::s_GetInFormationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GetInFormationComponent::s_GetInFormationComponentList__);
}

// File Line: 31
// RVA: 0x32EB20
void __fastcall UFG::GetInFormationComponent::GetInFormationComponent(
        UFG::GetInFormationComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  this->mNext = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInFormationComponent::`vftable;
  this->m_NodeList.mNode.mPrev = &this->m_NodeList.mNode;
  this->m_NodeList.mNode.mNext = &this->m_NodeList.mNode;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pSimObjectCharacterPropertiesComponent);
  mPrev = UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev;
  UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&UFG::GetInFormationComponent::s_GetInFormationComponentList;
  UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::GetInFormationComponent::_GetInFormationComponentTypeUID,
    "GetInFormationComponent");
  this->m_LockPositionToCurrentPosition = 0;
}

// File Line: 39
// RVA: 0x3372D0
void __fastcall UFG::GetInFormationComponent::~GetInFormationComponent(UFG::GetInFormationComponent *this)
{
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *p_m_NodeList; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **i; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mPrev; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *mNext; // rax
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v10; // rcx
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInFormationComponent::`vftable;
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
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSimObjectCharacterPropertiesComponent);
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
  this->mPrev = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  this->mNext = &this->UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 56
// RVA: 0x37EE30
UFG::GetInFormationComponent *__fastcall UFG::GetInFormationComponent::PropertiesOnActivateNew(
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

  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xC8ui64, "GetInFormationComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::GetInFormationComponent::GetInFormationComponent(
      (UFG::GetInFormationComponent *)v3,
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
    v8 = 32;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::GetInFormationComponent *)v6;
}

// File Line: 65
// RVA: 0x378C70
void __fastcall UFG::GetInFormationComponent::OnAttach(
        UFG::GetInFormationComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( p_m_pAIEntityComponent->m_pSimComponent )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
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
    v7 = p_m_pAIEntityComponent->mPrev;
    v8 = p_m_pAIEntityComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIEntityComponent->m_Changed = 1;
  p_m_pAIEntityComponent->m_pSimObject = object;
  p_m_pAIEntityComponent->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_m_pAIEntityComponent,
    object);
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v11 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_15;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v12 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v13 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = object;
  this->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->m_pSimObjectCharacterPropertiesComponent,
    object);
}

// File Line: 73
// RVA: 0x37A670
void __fastcall UFG::GetInFormationComponent::OnDetach(UFG::GetInFormationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *i; // rdx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v13; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v14; // rax

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
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  p_m_pAIEntityComponent->m_Changed = 1;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v8 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v9 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_15;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v10 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v11 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  for ( i = this->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)&this->m_BoundComponentHandles.mNode.mNext;
        i = this->m_NodeList.mNode.mNext )
  {
    v13 = i->mPrev;
    v14 = i->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **, __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}e> **, __int64))i[-2].mNext->mPrev)(


// File Line: 80
// RVA: 0x36D730
UFG::GetInFormationNode *__fastcall UFG::GetInFormationComponent::MakeNewNode(
        UFG::GetInFormationComponent *this,
        UFG::eFormationRangePreference range_preference,
        UFG::eAttackType attack_type,
        UFG::eTargetTypeEnum target_type)
{
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *mPrev; // rax

  v8 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x78ui64, "GetInFormationNode", 0i64, 1u);
  if ( v8 )
  {
    UFG::GetInFormationNode::GetInFormationNode(
      (UFG::GetInFormationNode *)v8,
      this,
      range_preference,
      attack_type,
      target_type);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  mPrev = this->m_NodeList.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)(v10 + 24);
  *(_QWORD *)(v10 + 24) = mPrev;
  *(_QWORD *)(v10 + 32) = &this->m_NodeList;
  this->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)(v10 + 24);
  return (UFG::GetInFormationNode *)v10;
}

// File Line: 92
// RVA: 0x32EC50
void __fastcall UFG::GetInFormationNode::GetInFormationNode(
        UFG::GetInFormationNode *this,
        UFG::GetInFormationComponent *owner,
        UFG::eFormationRangePreference range_preference,
        UFG::eAttackType attack_type,
        UFG::eTargetTypeEnum target_type)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInFormationComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  this->mPrev = &this->UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode>;
  this->mNext = &this->UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode>;
  UFG::qSafePointerNode<UFG::GetInFormationNode>::qSafePointerNode<UFG::GetInFormationNode>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInFormationNode>Vtbl *)&UFG::GetInFormationNode::`vftable;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mPrev = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
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
    v13 = owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v13->mNext = p_m_pOwner;
    p_m_pOwner->mPrev = v13;
    this->m_pOwner.mNext = &owner->m_SafePointerList.mNode;
    owner->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pOwner;
  }
  *(_WORD *)&this->m_JustGotToRangePreference = 256;
  this->m_PrevIsAtRangePreference = 0;
  this->m_RangePreference = range_preference;
  this->m_AttackType = attack_type;
  this->m_TargetType = target_type;
  this->m_Registrator = 0i64;
  UFG::GetInFormationNode::UnregisterFromFormationManager(this);
  *(_QWORD *)&this->m_RangeIndex = -1i64;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v14 = p_m_pTargetFormationManagerComponent->mPrev;
    v15 = this->m_pTargetFormationManagerComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  }
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 99
// RVA: 0x337490
void __fastcall UFG::GetInFormationNode::~GetInFormationNode(UFG::GetInFormationNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInFormationComponent> *p_m_pOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v14; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v15; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::GetInFormationNode>Vtbl *)&UFG::GetInFormationNode::`vftable;
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
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v8 = p_m_pTargetFormationManagerComponent->mPrev;
    v9 = this->m_pTargetFormationManagerComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  }
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetFormationManagerComponent->mPrev;
  v11 = this->m_pTargetFormationManagerComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInFormationNode>Vtbl *)&UFG::qSafePointerNode<UFG::GetInFormationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v12 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev;
  v13 = this->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v14 = this->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mPrev = &this->UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode>;
  this->mNext = &this->UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode>;
}

// File Line: 104
// RVA: 0x37F530
void __fastcall UFG::GetInFormationNode::ReInit(
        UFG::GetInFormationNode *this,
        UFG::eFormationRangePreference range_preference,
        UFG::eAttackType attack_type,
        UFG::eTargetTypeEnum target_type)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  *(_WORD *)&this->m_JustGotToRangePreference = 256;
  this->m_PrevIsAtRangePreference = 0;
  this->m_RangePreference = range_preference;
  this->m_AttackType = attack_type;
  this->m_TargetType = target_type;
  this->m_Registrator = 0i64;
  UFG::GetInFormationNode::UnregisterFromFormationManager(this);
  *(_QWORD *)&this->m_RangeIndex = -1i64;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( p_m_pTargetFormationManagerComponent->m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
}

// File Line: 190
// RVA: 0x38A900
void __fastcall UFG::GetInFormationNode::UnregisterFromFormationManager(UFG::GetInFormationNode *this)
{
  UFG::FormationManagerComponent *m_pPointer; // rcx
  __int64 m_RangeIndex; // rdx
  __int64 m_SlotIndex; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer;
  if ( m_pPointer )
  {
    m_RangeIndex = this->m_RangeIndex;
    m_SlotIndex = this->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && m_pPointer->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == this )
    {
      UFG::FormationManagerComponent::Unregister(m_pPointer, m_RangeIndex, m_SlotIndex);
    }
  }
  *(_QWORD *)&this->m_RangeIndex = -1i64;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( p_m_pTargetFormationManagerComponent->m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
}

// File Line: 207
// RVA: 0x369F20
char __fastcall UFG::GetInFormationNode::IsAtRangePreference(UFG::GetInFormationNode *this)
{
  UFG::SimComponent *m_pPointer; // r8
  int m_RangeIndex; // edx
  UFG::eFormationRangePreference m_RangePreference; // ecx
  __int32 v4; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx

  m_pPointer = this->m_pTargetFormationManagerComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_RangeIndex = this->m_RangeIndex;
  if ( m_RangeIndex == -1 )
    return 0;
  m_RangePreference = this->m_RangePreference;
  if ( m_RangePreference )
  {
    v4 = m_RangePreference - 1;
    if ( !v4 )
      return m_RangeIndex == 0;
    v5 = v4 - 1;
    if ( !v5 )
      return m_RangeIndex == LODWORD(m_pPointer[5].m_SafePointerList.mNode.mPrev) - 2;
    v6 = v5 - 1;
    if ( !v6 )
      return m_RangeIndex != 0;
    if ( v6 != 1 )
      return 0;
  }
  return 1;
}

// File Line: 219
// RVA: 0x387D10
void __fastcall UFG::GetInFormationNode::SetTargetFormationManagerComponent(
        UFG::GetInFormationNode *this,
        UFG::FormationManagerComponent *target_formation_manager_component)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = target_formation_manager_component;
  if ( target_formation_manager_component )
  {
    v5 = target_formation_manager_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mPrev = v5;
    p_m_pTargetFormationManagerComponent->mNext = &target_formation_manager_component->m_SafePointerList.mNode;
    target_formation_manager_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTargetFormationManagerComponent;
  }
}

