// File Line: 25
// RVA: 0x3634A0
signed __int64 __fastcall Render::DynamicLightComponent::GetTypeSize(Render::DynamicLightComponent *this)
{
  return 240i64;
}

// File Line: 26
// RVA: 0x14AEB20
__int64 dynamic_initializer_for__UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList__);
}

// File Line: 30
// RVA: 0x32EF10
void __fastcall UFG::GetInPedFormationComponent::GetInPedFormationComponent(UFG::GetInPedFormationComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::GetInPedFormationComponent *v4; // rdi
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v5; // rbx
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0> *v6; // ST28_8
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v7; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInPedFormationComponent::`vftable';
  v6 = &v4->m_NodeList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v4->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v4->m_pHealthComponent);
  v7 = UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev;
  UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&v4->mPrev;
  v5->mPrev = v7;
  v4->mNext = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList;
  UFG::GetInPedFormationComponent::s_GetInPedFormationComponentList.mNode.mPrev = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::GetInPedFormationComponent::_GetInPedFormationComponentTypeUID,
    "GetInPedFormationComponent");
}

// File Line: 36
// RVA: 0x337820
void __fastcall UFG::GetInPedFormationComponent::~GetInPedFormationComponent(UFG::GetInPedFormationComponent *this)
{
  UFG::GetInPedFormationComponent *v1; // rsi
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v4; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v8; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v9; // rax
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v10; // rdx
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v11; // rcx
  UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GetInPedFormationComponent::`vftable';
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
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = (UFG::qNode<UFG::GetInPedFormationComponent,UFG::GetInPedFormationComponent> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 48
// RVA: 0x37EF10
UFG::SimComponent *__fastcall UFG::GetInPedFormationComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
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
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "GetInPedFormationComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v2->mpWritableProperties;
    if ( !v4 )
      v4 = v2->mpConstProperties;
    UFG::GetInPedFormationComponent::GetInPedFormationComponent(
      (UFG::GetInPedFormationComponent *)v3,
      v2->m_NameUID,
      v4,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v2->m_pSimObject;
  if ( (v7->m_Flags >> 14) & 1 )
    v8 = 34;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 62
// RVA: 0x378D70
void __fastcall UFG::GetInPedFormationComponent::OnAttach(UFG::GetInPedFormationComponent *this, UFG::SimObject *object)
{
  UFG::GetInPedFormationComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v3; // rcx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = this;
  v3 = &this->m_pAIEntityComponent;
  v4 = (UFG::SimObjectCharacter *)object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
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
    v7 = v3->mNext;
    v8 = v3->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(v3, v4);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pActionTreeComponent,
    v4);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pHealthComponent, v4);
}

// File Line: 71
// RVA: 0x37A780
void __fastcall UFG::GetInPedFormationComponent::OnDetach(UFG::GetInPedFormationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v1; // r8
  UFG::GetInPedFormationComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *i; // rdx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v18; // rcx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v19; // rax

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
  v7 = &v2->m_pActionTreeComponent;
  v1->m_Changed = 1;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActionTreeComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->m_pActionTreeComponent.mNext != &v2->m_pActionTreeComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pActionTreeComponent.m_Changed = 1;
  v12 = &v2->m_pHealthComponent;
  if ( v2->m_pHealthComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pHealthComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pHealthComponent.m_pSimObject = 0i64;
    v2->m_pHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pHealthComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v2->m_pHealthComponent.mNext != &v2->m_pHealthComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pHealthComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pHealthComponent.m_Changed = 1;
  for ( i = v2->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **)&v2->m_BoundComponentHandles.mNode.mNext;
        i = v2->m_NodeList.mNode.mNext )
  {
    v18 = i->mPrev;
    v19 = i->mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **, signed __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}

// File Line: 80
// RVA: 0x351EC0
void __fastcall UFG::GetInPedFormationComponent::DeleteList(UFG::GetInFormationComponent *this)
{
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v1; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v2; // rdi
  UFG::GetInFormationComponent *v3; // rbx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v4; // rcx
  UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *v5; // rdx

  v1 = this->m_NodeList.mNode.mNext;
  v2 = &this->m_BoundComponentHandles.mNode.mNext;
  v3 = this;
  if ( &v1[-2].mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)&this->m_BoundComponentHandles.mNode.mNext )
  {
    do
    {
      v4 = v1->mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mPrev = v1;
      v1->mNext = v1;
      if ( v1 != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> *)24 )
        ((void (__fastcall *)(UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **, signed __int64))v1[-2].mNext->mPrev)(
          &v1[-2].mNext,
          1i64);
      v1 = v3->m_NodeList.mNode.mNext;
    }
    while ( &v1[-2].mNext != (UFG::qNode<UFG::GetInFormationNode,UFG::GetInFormationNode> **)v2 );
  }
}

// File Line: 85
// RVA: 0x36D7E0
UFG::GetInPedFormationNode *__fastcall UFG::GetInPedFormationComponent::MakeNewNode(UFG::GetInPedFormationComponent *this)
{
  UFG::GetInPedFormationComponent *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // r8
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **v5; // rcx
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v6; // rax

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "GetInPedFormationNode", 0i64, 1u);
  if ( v2 )
  {
    UFG::GetInPedFormationNode::GetInPedFormationNode((UFG::GetInPedFormationNode *)v2, v1);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> **)(v4 + 24);
  v6 = v1->m_NodeList.mNode.mPrev;
  v6->mNext = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)(v4 + 24);
  *v5 = v6;
  v5[1] = &v1->m_NodeList.mNode;
  v1->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)(v4 + 24);
  return (UFG::GetInPedFormationNode *)v4;
}

// File Line: 96
// RVA: 0x32F040
void __fastcall UFG::GetInPedFormationNode::GetInPedFormationNode(UFG::GetInPedFormationNode *this, UFG::GetInPedFormationComponent *owner)
{
  UFG::GetInPedFormationComponent *v2; // rsi
  UFG::GetInPedFormationNode *v3; // rdi
  UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v5; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInPedFormationComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  v2 = owner;
  v3 = this;
  v4 = (UFG::qNode<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  UFG::qSafePointerNode<UFG::GetInPedFormationNode>::qSafePointerNode<UFG::GetInPedFormationNode>((UFG::qSafePointerNode<UFG::GetInPedFormationNode> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::GetInPedFormationNode::`vftable';
  v5 = &v3->m_pTargetPedFormationManagerComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
  v6 = &v3->m_pOwner;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v3->m_pOwner.m_pPointer = 0i64;
  if ( v3->m_pOwner.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v3->m_pOwner.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->m_pOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pOwner.mPrev;
  }
  v3->m_pOwner.m_pPointer = (UFG::SimComponent *)&v2->vfptr;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v3->m_pOwner.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v3->m_Registrator = 0i64;
  UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(v3);
  v3->m_SlotIndex = -1;
  if ( v3->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    v10 = v5->mPrev;
    v11 = v3->m_pTargetPedFormationManagerComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->m_pTargetPedFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetPedFormationManagerComponent.mPrev;
  }
  v3->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 102
// RVA: 0x3379E0
void __fastcall UFG::GetInPedFormationNode::~GetInPedFormationNode(UFG::GetInPedFormationNode *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::GetInPedFormationComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v14; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v16; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::GetInPedFormationNode::`vftable';
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
  v7 = v1 + 2;
  if ( v1[2].m_SafePointerList.mNode.mNext )
  {
    v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7->vfptr;
    v9 = v1[2].m_SafePointerList.mNode.mPrev;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v7;
    v1[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[2];
  }
  v1[2].m_SafePointerList.mNode.mNext = 0i64;
  v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7->vfptr;
  v11 = v1[2].m_SafePointerList.mNode.mPrev;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v7;
  v1[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[2];
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::GetInPedFormationNode>::`vftable';
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

// File Line: 175
// RVA: 0x38A980
void __fastcall UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(UFG::GetInPedFormationNode *this)
{
  UFG::PedFormationManagerComponent *v1; // rdi
  UFG::GetInPedFormationNode *v2; // rsi
  __int64 v3; // rbx
  UFG::GetInPedFormationNode *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    if ( v1->m_Slots.size )
    {
      do
      {
        v4 = v1->m_Slots.p[v3].m_pMember.m_pPointer;
        if ( v4 && v2 == v4 )
          UFG::PedFormationManagerComponent::UnregisterSlot(v1, v3);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v1->m_Slots.size );
    }
  }
  v5 = &v2->m_pTargetPedFormationManagerComponent;
  v2->m_SlotIndex = -1;
  if ( v2->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v2->m_pTargetPedFormationManagerComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v2->m_pTargetPedFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetPedFormationManagerComponent.mPrev;
  }
  v2->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 192
// RVA: 0x387D60
void __fastcall UFG::GetInPedFormationNode::SetTargetPedFormationManagerComponent(UFG::GetInPedFormationNode *this, UFG::PedFormationManagerComponent *target_formation_manager_component)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pTargetPedFormationManagerComponent.mPrev;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
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

