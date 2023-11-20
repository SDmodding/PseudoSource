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
  return atexit(dynamic_atexit_destructor_for__UFG::GetInFormationComponent::s_GetInFormationComponentList__);
}

// File Line: 31
// RVA: 0x32EB20
void __fastcall UFG::GetInFormationComponent::GetInFormationComponent(UFG::GetInFormationComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::GetInFormationComponent *v4; // rdi
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v5; // rbx
  UFG::qList<UFG::GetInFormationNode,UFG::GetInFormationNode,1,0> *v6; // ST28_8
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v7; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInFormationComponent::`vftable;
  v6 = &v4->m_NodeList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v4->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v4->m_pSimObjectCharacterPropertiesComponent);
  v7 = UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev;
  UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&v4->mPrev;
  v5->mPrev = v7;
  v4->mNext = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&UFG::GetInFormationComponent::s_GetInFormationComponentList;
  UFG::GetInFormationComponent::s_GetInFormationComponentList.mNode.mPrev = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::GetInFormationComponent::_GetInFormationComponentTypeUID,
    "GetInFormationComponent");
  v4->m_LockPositionToCurrentPosition = 0;
}

// File Line: 39
// RVA: 0x3372D0
void __fastcall UFG::GetInFormationComponent::~GetInFormationComponent(UFG::GetInFormationComponent *this)
{
  UFG::GetInFormationComponent *v1; // rsi
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v4; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v8; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v9; // rax
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v10; // rdx
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v11; // rcx
  UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInFormationComponent::`vftable;
  v2 = (UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&this->m_NodeList;
  v3 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)&this->m_NodeList.mNode.mNext[-2].mNext;
  v4 = &this->m_BoundComponentHandles.mNode.mNext;
  if ( v3 != &this->m_BoundComponentHandles.mNode.mNext )
  {
    do
    {
      v5 = v3 + 3;
      v6 = v3[3];
      v7 = v3[4];
      v6->mNext = v7;
      v7->mPrev = v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)24 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v5 - 3))(v5 - 3, 1i64);
      v3 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)&v2->mNode.mNext[-2].mNext;
    }
    while ( v3 != v4 );
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = (UFG::qNode<UFG::GetInFormationComponent,UFG::GetInFormationComponent> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 56
// RVA: 0x37EE30
UFG::SimComponent *__fastcall UFG::GetInFormationComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  char *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xC8ui64, "GetInFormationComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v2->mpWritableProperties;
    if ( !v4 )
      v4 = v2->mpConstProperties;
    UFG::GetInFormationComponent::GetInFormationComponent((UFG::GetInFormationComponent *)v3, v2->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v2->m_pSimObject;
  if ( (v7->m_Flags >> 14) & 1 )
    v8 = 32;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 65
// RVA: 0x378C70
void __fastcall UFG::GetInFormationComponent::OnAttach(UFG::GetInFormationComponent *this, UFG::SimObject *object)
{
  UFG::GetInFormationComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v3; // rcx
  UFG::SimObjectCharacter *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v2 = this;
  v3 = &this->m_pAIEntityComponent;
  v4 = (UFG::SimObjectCharacter *)object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(v3, v4);
  v9 = &v2->m_pSimObjectCharacterPropertiesComponent;
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pSimObjectCharacterPropertiesComponent.mNext != &v2->m_pSimObjectCharacterPropertiesComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v2->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v2->m_pSimObjectCharacterPropertiesComponent,
    v4);
}

// File Line: 73
// RVA: 0x37A670
void __fastcall UFG::GetInFormationComponent::OnDetach(UFG::GetInFormationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v1; // r8
  UFG::GetInFormationComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *i; // rdx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v13; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v14; // rax

  v1 = &this->m_pAIEntityComponent;
  v2 = this;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAIEntityComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pSimObjectCharacterPropertiesComponent;
  v1->m_Changed = 1;
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pSimObjectCharacterPropertiesComponent.mNext != &v2->m_pSimObjectCharacterPropertiesComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  for ( i = v2->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)&v2->m_BoundComponentHandles.mNode.mNext;
        i = v2->m_NodeList.mNode.mNext )
  {
    v13 = i->mPrev;
    v14 = i->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **, signed __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}

// File Line: 80
// RVA: 0x36D730
UFG::GetInFormationNode *__fastcall UFG::GetInFormationComponent::MakeNewNode(UFG::GetInFormationComponent *this, UFG::eFormationRangePreference range_preference, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type)
{
  UFG::eTargetTypeEnum v4; // edi
  UFG::eAttackType v5; // esi
  UFG::eFormationRangePreference v6; // ebp
  UFG::GetInFormationComponent *v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **v11; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v12; // rax

  v4 = target_type;
  v5 = attack_type;
  v6 = range_preference;
  v7 = this;
  v8 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x78ui64, "GetInFormationNode", 0i64, 1u);
  if ( v8 )
  {
    UFG::GetInFormationNode::GetInFormationNode((UFG::GetInFormationNode *)v8, v7, v6, v5, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)(v10 + 24);
  v12 = v7->m_NodeList.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)(v10 + 24);
  *v11 = v12;
  v11[1] = &v7->m_NodeList.mNode;
  v7->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)(v10 + 24);
  return (UFG::GetInFormationNode *)v10;
}

// File Line: 92
// RVA: 0x32EC50
void __fastcall UFG::GetInFormationNode::GetInFormationNode(UFG::GetInFormationNode *this, UFG::GetInFormationComponent *owner, UFG::eFormationRangePreference range_preference, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type)
{
  UFG::eAttackType v5; // ebp
  UFG::eFormationRangePreference v6; // er14
  UFG::GetInFormationComponent *v7; // rsi
  UFG::GetInFormationNode *v8; // rbx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v10; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInFormationComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  v5 = attack_type;
  v6 = range_preference;
  v7 = owner;
  v8 = this;
  v9 = (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  UFG::qSafePointerNode<UFG::GetInFormationNode>::qSafePointerNode<UFG::GetInFormationNode>((UFG::qSafePointerNode<UFG::GetInFormationNode> *)&this->vfptr);
  v8->vfptr = (UFG::qSafePointerNode<UFG::GetInFormationNode>Vtbl *)&UFG::GetInFormationNode::`vftable;
  v10 = &v8->m_pTargetFormationManagerComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v8->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  v11 = &v8->m_pOwner;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v8->m_pOwner.m_pPointer = 0i64;
  if ( v8->m_pOwner.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v8->m_pOwner.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v8->m_pOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->m_pOwner.mPrev;
  }
  v8->m_pOwner.m_pPointer = (UFG::SimComponent *)&v7->vfptr;
  if ( v7 )
  {
    v14 = v7->m_SafePointerList.mNode.mPrev;
    v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mPrev = v14;
    v8->m_pOwner.mNext = &v7->m_SafePointerList.mNode;
    v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
  *(_WORD *)&v8->m_JustGotToRangePreference = 256;
  v8->m_PrevIsAtRangePreference = 0;
  v8->m_RangePreference = v6;
  v8->m_AttackType = v5;
  v8->m_TargetType = target_type;
  v8->m_Registrator = 0i64;
  UFG::GetInFormationNode::UnregisterFromFormationManager(v8);
  *(_QWORD *)&v8->m_RangeIndex = -1i64;
  if ( v8->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v15 = v10->mPrev;
    v16 = v8->m_pTargetFormationManagerComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v8->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->m_pTargetFormationManagerComponent.mPrev;
  }
  v8->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 99
// RVA: 0x337490
void __fastcall UFG::GetInFormationNode::~GetInFormationNode(UFG::GetInFormationNode *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInFormationComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v14; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v16; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInFormationNode>Vtbl *)&UFG::GetInFormationNode::`vftable;
  v2 = &this->m_pOwner;
  if ( this->m_pOwner.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1[2].m_SafePointerList.mNode.mNext;
  if ( v1[3].m_SafePointerList.mNode.mPrev )
  {
    v8 = *v7;
    v9 = v1[3].vfptr;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v9;
    v9->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v8;
    *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7;
    v1[3].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[2].m_SafePointerList.mNode.mNext;
  }
  v1[3].m_SafePointerList.mNode.mPrev = 0i64;
  v10 = *v7;
  v11 = v1[3].vfptr;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v11;
  v11->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v10;
  *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7;
  v1[3].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[2].m_SafePointerList.mNode.mNext;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::GetInFormationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v12 = v1->m_SafePointerList.mNode.mPrev;
  v13 = v1->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v14 = v1 + 1;
  v15 = v1[1].vfptr;
  v16 = v1[1].m_SafePointerList.mNode.mPrev;
  v15[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v16;
  v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v15;
  v14->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v14;
  v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v14;
}

// File Line: 104
// RVA: 0x37F530
void __fastcall UFG::GetInFormationNode::ReInit(UFG::GetInFormationNode *this, UFG::eFormationRangePreference range_preference, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type)
{
  UFG::GetInFormationNode *v4; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v4 = this;
  *(_WORD *)&this->m_JustGotToRangePreference = 256;
  this->m_PrevIsAtRangePreference = 0;
  this->m_RangePreference = range_preference;
  this->m_AttackType = attack_type;
  this->m_TargetType = target_type;
  this->m_Registrator = 0i64;
  UFG::GetInFormationNode::UnregisterFromFormationManager(this);
  *(_QWORD *)&v4->m_RangeIndex = -1i64;
  v5 = &v4->m_pTargetFormationManagerComponent;
  if ( v5->m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
}

// File Line: 190
// RVA: 0x38A900
void __fastcall UFG::GetInFormationNode::UnregisterFromFormationManager(UFG::GetInFormationNode *this)
{
  UFG::GetInFormationNode *v1; // rbx
  UFG::FormationManagerComponent *v2; // rcx
  __int64 v3; // rdx
  __int64 v4; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  v2 = (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer;
  if ( v2 )
  {
    v3 = v1->m_RangeIndex;
    v4 = v1->m_SlotIndex;
    if ( (_DWORD)v3 != -1
      && (_DWORD)v4 != -1
      && v2->mStateVariables.m_FormationSlot[0][v4 + 8 * v3].m_pMember.m_pPointer == v1 )
    {
      UFG::FormationManagerComponent::Unregister(v2, v3, v4);
    }
  }
  *(_QWORD *)&v1->m_RangeIndex = -1i64;
  v5 = &v1->m_pTargetFormationManagerComponent;
  if ( v5->m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
}

// File Line: 207
// RVA: 0x369F20
char __fastcall UFG::GetInFormationNode::IsAtRangePreference(UFG::GetInFormationNode *this)
{
  UFG::SimComponent *v1; // r8
  int v2; // edx
  UFG::eFormationRangePreference v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  v1 = this->m_pTargetFormationManagerComponent.m_pPointer;
  if ( !v1 )
    return 0;
  v2 = this->m_RangeIndex;
  if ( v2 == -1 )
    return 0;
  v3 = this->m_RangePreference;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( !v4 )
      return v2 == 0;
    v5 = v4 - 1;
    if ( !v5 )
      return v2 == LODWORD(v1[5].m_SafePointerList.mNode.mPrev) - 2;
    v6 = v5 - 1;
    if ( !v6 )
      return v2 != 0;
    if ( v6 != 1 )
      return 0;
  }
  return 1;
}

// File Line: 219
// RVA: 0x387D10
void __fastcall UFG::GetInFormationNode::SetTargetFormationManagerComponent(UFG::GetInFormationNode *this, UFG::FormationManagerComponent *target_formation_manager_component)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pTargetFormationManagerComponent.mPrev;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)target_formation_manager_component;
  if ( target_formation_manager_component )
  {
    v5 = target_formation_manager_component->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &target_formation_manager_component->m_SafePointerList.mNode;
    target_formation_manager_component->m_SafePointerList.mNode.mPrev = v2;
  }
}

