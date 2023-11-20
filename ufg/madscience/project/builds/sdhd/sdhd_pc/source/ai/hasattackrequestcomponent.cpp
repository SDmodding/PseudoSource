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
  return atexit(dynamic_atexit_destructor_for__UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList__);
}

// File Line: 39
// RVA: 0x32F770
void __fastcall UFG::HasAttackRequestComponent::HasAttackRequestComponent(UFG::HasAttackRequestComponent *this, unsigned int name_uid)
{
  UFG::HasAttackRequestComponent *v2; // rdi
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v3; // rbx
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v4; // rax
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *v5; // [rsp+50h] [rbp+18h]
  UFG::qList<AttackRightsScoreBonusTask,HasAttackRequestComponentList,0,0> *v6; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HasAttackRequestComponent::`vftable;
  v5 = &v2->m_NodeList;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v6 = &v2->m_AttackRightsScoreBonusTaskList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v2->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&v2->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v2->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v2->m_pActionTreeComponent);
  v4 = UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev;
  UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList;
  UFG::HasAttackRequestComponent::s_HasAttackRequestComponentList.mNode.mPrev = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::HasAttackRequestComponent::_HasAttackRequestComponentTypeUID,
    "HasAttackRequestComponent");
  v2->m_DebugStringTimestamp = -1;
  *(_QWORD *)v2->m_AttackCanceledUntilTime = -4052307825177440384i64;
  v2->m_AttackCanceledUntilTime[2] = -99999.0;
}

// File Line: 52
// RVA: 0x338190
void __fastcall UFG::HasAttackRequestComponent::~HasAttackRequestComponent(UFG::HasAttackRequestComponent *this)
{
  UFG::HasAttackRequestComponent *v1; // rsi
  UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v4; // rdi
  _QWORD *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v8; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v9; // rax
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v10; // rdx
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v11; // rcx
  UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HasAttackRequestComponent::`vftable;
  v2 = &this->m_NodeList;
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
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AttackRightsScoreBonusTaskList);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = (UFG::qNode<UFG::HasAttackRequestComponent,UFG::HasAttackRequestComponent> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 70
// RVA: 0x37EFF0
UFG::SimComponent *__fastcall UFG::HasAttackRequestComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x178ui64, "HasAttackRequestComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::HasAttackRequestComponent::HasAttackRequestComponent((UFG::HasAttackRequestComponent *)v3, v2->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v2->m_pSimObject;
  if ( (v6->m_Flags >> 14) & 1 )
    v7 = 35;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return v5;
}

// File Line: 79
// RVA: 0x378E20
void __fastcall UFG::HasAttackRequestComponent::OnAttach(UFG::HasAttackRequestComponent *this, UFG::SimObject *object)
{
  UFG::HasAttackRequestComponent *v2; // rbx
  UFG::SimObjectCharacter *v3; // rdi

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)object;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTargetingSystemBaseComponent,
    (UFG::SimObjectCharacter *)object);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pAIScriptInterfaceComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pTransformNodeComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pHealthComponent, v3);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pActionTreeComponent,
    v3);
}

// File Line: 90
// RVA: 0x37A8E0
void __fastcall UFG::HasAttackRequestComponent::OnDetach(UFG::HasAttackRequestComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v1; // r8
  UFG::HasAttackRequestComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *i; // rdx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v28; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v29; // rax

  v1 = &this->m_pTargetingSystemBaseComponent;
  v2 = this;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pTargetingSystemBaseComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pAIScriptInterfaceComponent;
  v1->m_Changed = 1;
  if ( v2->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAIScriptInterfaceComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v2->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIScriptInterfaceComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v2->m_pAIScriptInterfaceComponent.mNext != &v2->m_pAIScriptInterfaceComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pAIScriptInterfaceComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pAIScriptInterfaceComponent.m_Changed = 1;
  v12 = &v2->m_pTransformNodeComponent;
  if ( v2->m_pTransformNodeComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pTransformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pTransformNodeComponent.m_pSimObject = 0i64;
    v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTransformNodeComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v2->m_pTransformNodeComponent.mNext != &v2->m_pTransformNodeComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pTransformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pTransformNodeComponent.m_Changed = 1;
  v17 = &v2->m_pHealthComponent;
  if ( v2->m_pHealthComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pHealthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pHealthComponent.m_pSimObject = 0i64;
    v2->m_pHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pHealthComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v2->m_pHealthComponent.mNext != &v2->m_pHealthComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pHealthComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pHealthComponent.m_Changed = 1;
  v22 = &v2->m_pActionTreeComponent;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pActionTreeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActionTreeComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->m_pActionTreeComponent.mNext != &v2->m_pActionTreeComponent) )
  {
    v25 = v22->mPrev;
    v26 = v2->m_pActionTreeComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pActionTreeComponent.m_Changed = 1;
  for ( i = v2->m_NodeList.mNode.mNext;
        &i[-2].mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)&v2->m_BoundComponentHandles.mNode.mNext;
        i = v2->m_NodeList.mNode.mNext )
  {
    v28 = i->mPrev;
    v29 = i->mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **, signed __int64))i[-2].mNext->mPrev)(
        &i[-2].mNext,
        1i64);
  }
}

// File Line: 101
// RVA: 0x382BE0
void __fastcall UFG::HasAttackRequestComponent::Reset(UFG::HasAttackRequestComponent *this)
{
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v1; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v2; // rdi
  UFG::HasAttackRequestComponent *v3; // rbx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v4; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v5; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *i; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v7; // rax
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v8; // rcx

  v1 = this->m_NodeList.mNode.mNext;
  v2 = &this->m_BoundComponentHandles.mNode.mNext;
  v3 = this;
  if ( &v1[-2].mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)&this->m_BoundComponentHandles.mNode.mNext )
  {
    do
    {
      v4 = v1->mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mPrev = v1;
      v1->mNext = v1;
      if ( v1 != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)24 )
        ((void (__fastcall *)(UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **, signed __int64))v1[-2].mNext->mPrev)(
          &v1[-2].mNext,
          1i64);
      v1 = v3->m_NodeList.mNode.mNext;
    }
    while ( &v1[-2].mNext != (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)v2 );
  }
  for ( i = v3->m_AttackRightsScoreBonusTaskList.mNode.mNext;
        &i[-3].mNext != (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> **)&v3->m_BoundComponentHandles.mNode.mNext;
        i = v3->m_AttackRightsScoreBonusTaskList.mNode.mNext )
  {
    v7 = i->mNext;
    v8 = i->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    i->mPrev = i;
    i->mNext = i;
  }
}

// File Line: 131
// RVA: 0x36D860
UFG::HasAttackRequestNode *__fastcall UFG::HasAttackRequestComponent::MakeNewNode(UFG::HasAttackRequestComponent *this, ActionContext *action_context, HasAttackRequestCondition *has_attack_request_condition)
{
  HasAttackRequestCondition *v3; // rdi
  ActionContext *v4; // rsi
  UFG::HasAttackRequestComponent *v5; // rbx
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // r8
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **v9; // rcx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v10; // rax

  v3 = has_attack_request_condition;
  v4 = action_context;
  v5 = this;
  v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xE8ui64, "HasAttackRequestNode", 0i64, 1u);
  if ( v6 )
  {
    UFG::HasAttackRequestNode::HasAttackRequestNode((UFG::HasAttackRequestNode *)v6, v5, v4, v3);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> **)(v8 + 24);
  v10 = v5->m_NodeList.mNode.mPrev;
  v10->mNext = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)(v8 + 24);
  *v9 = v10;
  v9[1] = &v5->m_NodeList.mNode;
  v5->m_NodeList.mNode.mPrev = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)(v8 + 24);
  return (UFG::HasAttackRequestNode *)v8;
}

// File Line: 140
// RVA: 0x354650
void __fastcall UFG::HasAttackRequestComponent::DrawDebugString(UFG::HasAttackRequestComponent *this, Render::View *view)
{
  UFG::HasAttackRequestComponent *v2; // r14
  unsigned int v3; // er12
  signed __int64 v4; // rdi
  signed __int64 i; // r15
  UFG::AttackRightsComponent *v6; // rax
  UFG::AttackRightsComponent *v7; // r9
  int v8; // esi
  __int64 v9; // r8
  __int64 v10; // r10
  int v11; // edx
  int v12; // ebx
  UFG::HasAttackRequestNode **v13; // rax
  UFG::qString *v14; // rax
  UFG::qString *v15; // rax
  const char *v16; // rdx
  __int64 v17; // rcx
  char v18; // al
  const char *v19; // rdx
  unsigned int v20; // eax
  const char *v21; // rdx
  float v22; // xmm6_4
  UFG::HasAttackRequestNode *v23; // rbx
  signed __int64 j; // rax
  float v25; // xmm0_4
  UFG::AttackRightsComponent *v26; // rax
  float v27; // xmm0_4
  UFG::qString *v28; // rax
  UFG::qString *v29; // rax
  UFG::SimComponent *v30; // rbx
  Render::DebugDrawContext *v31; // rax
  UFG::qString debug_string; // [rsp+0h] [rbp-59h]
  UFG::qString v33; // [rsp+28h] [rbp-31h]
  __int64 v34; // [rsp+50h] [rbp-9h]
  UFG::qString v35; // [rsp+58h] [rbp-1h]

  v34 = -2i64;
  v2 = this;
  v3 = UFG::Metrics::msFrameCount;
  if ( UFG::Metrics::msFrameCount != this->m_DebugStringTimestamp
    && this->m_pTransformNodeComponent.m_pSimComponent
    && this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    UFG::qString::qString(&debug_string);
    v4 = (signed __int64)&v2->m_NodeList.mNode.mNext[-2].mNext;
    for ( i = (signed __int64)&v2->m_BoundComponentHandles.mNode.mNext; v4 != i; v4 = *(_QWORD *)(v4 + 32) - 24i64 )
    {
      v6 = UFG::HasAttackRequestNode::GetAttackTarget((UFG::HasAttackRequestNode *)v4);
      v7 = v6;
      if ( v6 && v4 )
      {
        v8 = 0;
        v9 = 0i64;
        v10 = *(signed int *)(v4 + 72);
        v11 = v6->m_NumAttackSlots[v10];
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
        v13 = &v7->m_pAttackSlot[0][0][0].m_pPointer + 192 * (v9 + 2 * v10);
        while ( (UFG::HasAttackRequestNode *)v4 != *v13 )
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
        if ( !(BYTE1(v2->m_pAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) & 0x10) )
          v16 = "\nScript can_gain_attack_rights(): FALSE";
        UFG::qString::operator+=(&debug_string, v16);
        v17 = *(_QWORD *)(v4 + 136);
        if ( !v17
          || !*(_QWORD *)(v4 + 112)
          || (v18 = (*(__int64 (**)(void))(*(_QWORD *)v17 + 80i64))(), v19 = "\nCondition group: true", !v18) )
        {
          v19 = "\nCondition group: FALSE";
        }
        UFG::qString::operator+=(&debug_string, v19);
        if ( UFG::Metrics::msInstance.mSimFrameCount )
          v20 = UFG::Metrics::msInstance.mSimFrameCount - 1;
        else
          v20 = -1;
        v21 = "\nCurrently polling condition";
        if ( *(_DWORD *)(v4 + 96) < v20 )
          v21 = "\nNOT currently polling condition";
        UFG::qString::operator+=(&debug_string, v21);
        UFG::qString::operator+=(&debug_string, "\n");
      }
LABEL_26:
      ;
    }
    UFG::qString::operator+=(&debug_string, "\n=====================================");
    v22 = FLOAT_N1_0;
    v23 = (UFG::HasAttackRequestNode *)&v2->m_NodeList.mNode.mNext[-2].mNext;
    for ( j = (signed __int64)v23; j != i; j = *(_QWORD *)(j + 32) - 24i64 )
    {
      v25 = *(float *)(j + 108);
      if ( v25 >= 0.0 && (v22 < 0.0 || v22 <= v25) )
        v22 = *(float *)(j + 108);
    }
    UFG::qString::Set(&debug_string, &customWorldMapCaption);
    if ( v23 )
    {
      v26 = UFG::HasAttackRequestNode::GetAttackTarget(v23);
      if ( v26 )
      {
        v27 = UFG::AttackRightsComponent::GetAttackerScore(v26, v23, &debug_string);
        UFG::qString::qString(&v33, "\nFinal score: %.1f", v27);
        UFG::qString::operator+=(&debug_string, v28);
        UFG::qString::~qString(&v33);
        UFG::qString::qString(&v33, "\n\nScore last time list was sorted: %.1f", v22);
        UFG::qString::operator+=(&debug_string, v29);
        UFG::qString::~qString(&v33);
      }
    }
    v30 = v2->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
    v31 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(
      v31,
      (UFG::qVector3 *)&v30[2].m_BoundComponentHandles,
      &UFG::qColour::White,
      debug_string.mData);
    v2->m_DebugStringTimestamp = v3;
    UFG::qString::~qString(&debug_string);
  }
}

// File Line: 270
// RVA: 0x32F950
void __fastcall UFG::HasAttackRequestNode::HasAttackRequestNode(UFG::HasAttackRequestNode *this, UFG::HasAttackRequestComponent *owner, ActionContext *action_context, HasAttackRequestCondition *has_attack_request_condition)
{
  HasAttackRequestCondition *v4; // r14
  ActionContext *v5; // rbp
  UFG::HasAttackRequestComponent *v6; // rdi
  UFG::HasAttackRequestNode *v7; // rbx
  UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v8; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *v9; // rax
  UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *v10; // rax
  ActionContext *v11; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::HasAttackRequestComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::allocator::free_link *v16; // rax
  ActionContext *v17; // rax
  UFG::qSafePointer<CanAttackConditionGroup,CanAttackConditionGroup> *v18; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v19; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v20; // [rsp+58h] [rbp+10h]

  v4 = has_attack_request_condition;
  v5 = action_context;
  v6 = owner;
  v7 = this;
  v8 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *)&this->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  UFG::qSafePointerNode<UFG::HasAttackRequestNode>::qSafePointerNode<UFG::HasAttackRequestNode>((UFG::qSafePointerNode<UFG::HasAttackRequestNode> *)&this->vfptr);
  v9 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::AttackRightsList> *)&v7->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v10 = (UFG::qNode<UFG::HasAttackRequestNode,UFG::FollowerAttackRightsList> *)&v7->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  v7->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)&UFG::HasAttackRequestNode::`vftable;
  v18 = &v7->m_pCanAttackConditions;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v18->mNext = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v11 = 0i64;
  v7->m_pCanAttackConditions.m_pPointer = 0i64;
  v19 = &v7->m_pAttackeeRequest;
  v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  v7->m_pAttackeeRequest.m_pPointer = 0i64;
  v20 = &v7->m_pSecondaryCharacterRequest;
  v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v7->m_pSecondaryCharacterRequest.m_pPointer = 0i64;
  v12 = &v7->m_pOwner;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v7->m_pOwner.m_pPointer = 0i64;
  if ( v7->m_pOwner.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v7->m_pOwner.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v7->m_pOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->m_pOwner.mPrev;
  }
  v7->m_pOwner.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v15 = v6->m_SafePointerList.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v12->mPrev = v15;
    v7->m_pOwner.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  }
  v16 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v16 )
  {
    ActionContext::ActionContext((ActionContext *)v16, v5);
    v11 = v17;
  }
  v7->m_pActionContextCopy = v11;
  UFG::HasAttackRequestNode::ReInit(v7, v5, v4);
}

// File Line: 278
// RVA: 0x3383A0
void __fastcall UFG::HasAttackRequestNode::~HasAttackRequestNode(UFG::HasAttackRequestNode *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  ActionContext *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v35; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v37; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::HasAttackRequestNode>Vtbl *)&UFG::HasAttackRequestNode::`vftable;
  v2 = this->m_pActionContextCopy;
  if ( v2 )
  {
    if ( v2->mSimObject.m_pPointer )
    {
      v3 = v2->mSimObject.mPrev;
      v4 = v2->mSimObject.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
      v2->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    }
    v2->mSimObject.m_pPointer = 0i64;
    v5 = v2->mSimObject.mPrev;
    v6 = v2->mSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    v2->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    operator delete[](v2);
  }
  v1[4].m_SafePointerList.mNode.mNext = 0i64;
  v7 = &v1[8].m_SafePointerList;
  if ( v1[9].vfptr )
  {
    v8 = v7->mNode.mPrev;
    v9 = v1[8].m_SafePointerList.mNode.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mNode.mPrev = &v7->mNode;
    v1[8].m_SafePointerList.mNode.mNext = &v1[8].m_SafePointerList.mNode;
  }
  v1[9].vfptr = 0i64;
  v10 = v7->mNode.mPrev;
  v11 = v1[8].m_SafePointerList.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mNode.mPrev = &v7->mNode;
  v1[8].m_SafePointerList.mNode.mNext = &v1[8].m_SafePointerList.mNode;
  v12 = v1 + 7;
  if ( v1[7].m_SafePointerList.mNode.mNext )
  {
    v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v12->vfptr;
    v14 = v1[7].m_SafePointerList.mNode.mPrev;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v12;
    v1[7].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[7];
  }
  v1[7].m_SafePointerList.mNode.mNext = 0i64;
  v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v12->vfptr;
  v16 = v1[7].m_SafePointerList.mNode.mPrev;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v12;
  v1[7].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[7];
  v17 = v1 + 6;
  if ( v1[6].m_SafePointerList.mNode.mNext )
  {
    v18 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v17->vfptr;
    v19 = v1[6].m_SafePointerList.mNode.mPrev;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v17;
    v1[6].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[6];
  }
  v1[6].m_SafePointerList.mNode.mNext = 0i64;
  v20 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v17->vfptr;
  v21 = v1[6].m_SafePointerList.mNode.mPrev;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v17;
  v1[6].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[6];
  v22 = v1 + 5;
  if ( v1[5].m_SafePointerList.mNode.mNext )
  {
    v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v22->vfptr;
    v24 = v1[5].m_SafePointerList.mNode.mPrev;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v22;
    v1[5].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[5];
  }
  v1[5].m_SafePointerList.mNode.mNext = 0i64;
  v25 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v22->vfptr;
  v26 = v1[5].m_SafePointerList.mNode.mPrev;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v22;
  v1[5].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[5];
  v27 = &v1[2].m_SafePointerList;
  v28 = v1[2].m_SafePointerList.mNode.mPrev;
  v29 = v1[2].m_SafePointerList.mNode.mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v27->mNode.mPrev = &v27->mNode;
  v27->mNode.mNext = &v27->mNode;
  v30 = &v1[1].m_SafePointerList.mNode.mNext;
  v31 = v1[1].m_SafePointerList.mNode.mNext;
  v32 = v1[2].vfptr;
  v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v32;
  v32->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v31;
  *v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v30;
  v30[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v30;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::HasAttackRequestNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v33 = v1->m_SafePointerList.mNode.mPrev;
  v34 = v1->m_SafePointerList.mNode.mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v35 = v1 + 1;
  v36 = v1[1].vfptr;
  v37 = v1[1].m_SafePointerList.mNode.mPrev;
  v36[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v37;
  v37->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v36;
  v35->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v35;
  v35->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v35;
}

// File Line: 285
// RVA: 0x37F5A0
void __fastcall UFG::HasAttackRequestNode::ReInit(UFG::HasAttackRequestNode *this, ActionContext *action_context, HasAttackRequestCondition *has_attack_request_condition)
{
  ActionContext *v3; // r9
  UFG::HasAttackRequestNode *v4; // rbx
  __int64 v5; // rax
  CanAttackConditionGroup *v6; // r8
  UFG::qSafePointer<CanAttackConditionGroup,CanAttackConditionGroup> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *v10; // rax

  v3 = action_context;
  v4 = this;
  this->m_AttackType = (unsigned __int8)has_attack_request_condition->m_AttackType.mValue;
  this->m_AttackerType = (unsigned __int8)has_attack_request_condition->m_AttackerType.mValue;
  this->m_TargetType = (unsigned __int8)has_attack_request_condition->m_TargetType.mValue;
  this->m_InCoverType = (unsigned __int8)has_attack_request_condition->m_InCoverType.mValue;
  this->m_CopySecondaryCharacterToTargetType = (unsigned __int8)has_attack_request_condition->m_CopySecondaryCharacterToTargetType.mValue;
  v5 = has_attack_request_condition->m_pCanAttackConditions.mOffset;
  if ( v5 )
    v6 = (CanAttackConditionGroup *)((char *)&has_attack_request_condition->m_pCanAttackConditions + v5);
  else
    v6 = 0i64;
  v7 = &this->m_pCanAttackConditions;
  if ( this->m_pCanAttackConditions.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v7->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v7->m_pPointer = v6;
  if ( v6 )
  {
    v10 = v6->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v7->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  ActionContext::operator=(v4->m_pActionContextCopy, v3);
  v4->m_LastTimePolled = -99999.0;
  v4->m_LastFramePolled = 0;
  v4->m_CurrentlyAttacking = 0;
  v4->m_TimeFinishedAttacking = -99999.0;
  v4->m_Registrator = 0i64;
  v4->m_Score = -1.0;
}

// File Line: 398
// RVA: 0x359D80
UFG::SimComponent *__fastcall UFG::HasAttackRequestNode::GetAttackTarget(UFG::HasAttackRequestNode *this)
{
  UFG::SimComponent *v1; // rax
  __int64 v2; // r9
  UFG::SimObject *v3; // r9
  unsigned __int16 v4; // cx
  unsigned int v6; // edx
  UFG::SimObjectGame *v7; // rcx
  bool v8; // zf

  v1 = this->m_pOwner.m_pPointer;
  if ( v1 )
  {
    v2 = *(_QWORD *)&v1[2].m_TypeUID;
    if ( v2 )
    {
      v3 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->m_TargetType + *(_QWORD *)(v2 + 96) + 8i64)
                              + *(_QWORD *)(v2 + 88)
                              + 40);
      if ( v3 )
      {
        v4 = v3->m_Flags;
        if ( (v4 >> 14) & 1 )
          return v3->m_Components.p[46].m_pComponent;
        if ( (v4 & 0x8000u) != 0 || (v4 >> 13) & 1 )
        {
          v6 = UFG::AttackRightsComponent::_TypeUID;
          v7 = (UFG::SimObjectGame *)v3;
        }
        else
        {
          v6 = UFG::AttackRightsComponent::_TypeUID;
          v8 = ((v4 >> 12) & 1) == 0;
          v7 = (UFG::SimObjectGame *)v3;
          if ( v8 )
            return UFG::SimObject::GetComponentOfType(v3, UFG::AttackRightsComponent::_TypeUID);
        }
        return UFG::SimObjectGame::GetComponentOfTypeHK(v7, v6);
      }
    }
  }
  return 0i64;
}

// File Line: 409
// RVA: 0x3821A0
void __fastcall UFG::HasAttackRequestNode::RequestAttack(UFG::HasAttackRequestNode *this, UFG::AttackRightsComponent *attackee, UFG::HasAttackRequestNode *secondary_character)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // r10
  UFG::HasAttackRequestNode *v4; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::TargetingSystemBaseComponent *v13; // rcx
  UFG::SimComponent *v14; // rax

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pAttackeeRequest.mPrev;
  v4 = this;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = this->m_pAttackeeRequest.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = v3;
    this->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pAttackeeRequest.mPrev;
  }
  this->m_pAttackeeRequest.m_pPointer = (UFG::SimComponent *)&attackee->vfptr;
  if ( attackee )
  {
    v7 = attackee->m_SafePointerList.mNode.mPrev;
    v7->mNext = v3;
    v3->mPrev = v7;
    this->m_pAttackeeRequest.mNext = &attackee->m_SafePointerList.mNode;
    attackee->m_SafePointerList.mNode.mPrev = v3;
  }
  v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&this->m_pSecondaryCharacterRequest.mPrev;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v4->m_pSecondaryCharacterRequest.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = v8;
    v4->m_pSecondaryCharacterRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v4->m_pSecondaryCharacterRequest.mPrev;
  }
  v4->m_pSecondaryCharacterRequest.m_pPointer = secondary_character;
  if ( secondary_character )
  {
    v11 = secondary_character->m_SafePointerList.mNode.mPrev;
    v11->mNext = v8;
    v8->mPrev = v11;
    v4->m_pSecondaryCharacterRequest.mNext = &secondary_character->m_SafePointerList.mNode;
    secondary_character->m_SafePointerList.mNode.mPrev = v8;
  }
  v12 = v4->m_pOwner.m_pPointer;
  v4->m_AttackeeRequestTime = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v12 )
  {
    v13 = *(UFG::TargetingSystemBaseComponent **)&v12[2].m_TypeUID;
    if ( v13 )
    {
      if ( secondary_character )
      {
        v14 = secondary_character->m_pOwner.m_pPointer;
        if ( v14 )
          UFG::TargetingSystemBaseComponent::SetTarget(v13, v4->m_CopySecondaryCharacterToTargetType, v14->m_pSimObject);
        else
          UFG::TargetingSystemBaseComponent::SetTarget(v13, v4->m_CopySecondaryCharacterToTargetType, 0i64);
      }
    }
  }
}

// File Line: 421
// RVA: 0x34EEB0
void __fastcall UFG::HasAttackRequestNode::ClearAttackRequest(UFG::HasAttackRequestNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = &this->m_pAttackeeRequest;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->m_pAttackeeRequest.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pAttackeeRequest.mPrev;
  }
  v4 = &this->m_pSecondaryCharacterRequest;
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 427
// RVA: 0x3582C0
void __fastcall UFG::HasAttackRequestNode::FinishedAttacking(UFG::HasAttackRequestNode *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v1; // r8
  UFG::HasAttackRequestNode *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::AttackRightsComponent *v8; // rax

  v1 = &this->m_pAttackeeRequest;
  v2 = this;
  if ( this->m_pAttackeeRequest.m_pPointer )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAttackeeRequest.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pAttackeeRequest.mPrev;
  }
  v5 = &this->m_pSecondaryCharacterRequest;
  this->m_pAttackeeRequest.m_pPointer = 0i64;
  if ( this->m_pSecondaryCharacterRequest.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
  v8 = UFG::HasAttackRequestNode::GetAttackTarget(v2);
  if ( v8 )
    UFG::AttackRightsComponent::FinishedAttacking(v8, v2);
}

// File Line: 526
// RVA: 0x362600
UFG::SimObject *__fastcall UFG::HasAttackRequestNode::GetSimObject(UFG::HasAttackRequestNode *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_pOwner.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

