// File Line: 53
// RVA: 0x14AEA60
__int64 dynamic_initializer_for__UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList__);
}

// File Line: 54
// RVA: 0x363450
signed __int64 __fastcall UFG::AIScriptInterfaceComponent::GetTypeSize(UFG::AIScriptInterfaceComponent *this)
{
  return 2104i64;
}

// File Line: 58
// RVA: 0x32BD40
void __fastcall UFG::AIScriptInterfaceComponent::AIScriptInterfaceComponent(UFG::AIScriptInterfaceComponent *this, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::AIScriptInterfaceComponent *v3; // rdi
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v4; // rbx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v5; // rax

  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v4 = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIScriptInterfaceComponent::`vftable';
  `eh vector constructor iterator'(
    v3->m_ScriptArgument,
    0x48ui64,
    5,
    (void (__fastcall *)(void *))UFG::ScriptArgument::ScriptArgument);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v3->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v3->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v3->m_pTargetingSystemBaseComponent);
  v3->m_ActionRequestToHold.mBits[0] = 0i64;
  v3->m_ActionRequestToHold.mBits[1] = 0i64;
  v3->m_ActionRequestToHold.mBits[2] = 0i64;
  v3->m_ActionRequestToHold.mBits[3] = 0i64;
  v3->m_ActionRequestToHold.mBits[4] = 0i64;
  v3->m_ActionRequestToHold.mBits[5] = 0i64;
  v3->m_ActionRequestToHold.mBits[6] = 0i64;
  v3->m_ActionRequestToHold.mBits[7] = 0i64;
  v3->m_ActionRequestToHold.mBits[8] = 0i64;
  `eh vector constructor iterator'(
    v3->m_pFollower,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
  v5 = UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev;
  UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList;
  UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID,
    "AIScriptInterfaceComponent");
  UFG::AIScriptInterfaceComponent::Reset(v3);
}

// File Line: 67
// RVA: 0x334A10
void __fastcall UFG::AIScriptInterfaceComponent::~AIScriptInterfaceComponent(UFG::AIScriptInterfaceComponent *this)
{
  UFG::AIScriptInterfaceComponent *v1; // rdi
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v2; // rbx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v3; // rcx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v4; // rax
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v5; // rcx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIScriptInterfaceComponent::`vftable';
  if ( this == UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentpCurrentIterator )
    UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentpCurrentIterator = (UFG::AIScriptInterfaceComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  `eh vector destructor iterator'(
    v1->m_pFollower,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  `eh vector destructor iterator'(
    v1->m_ScriptArgument,
    0x48ui64,
    5,
    (void (__fastcall *)(void *))UFG::ScriptArgument::~ScriptArgument);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 73
// RVA: 0x37E950
UFG::qPropertySet *__fastcall UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::qPropertySet *v7; // r8
  UFG::AIScriptInterfaceComponent *v8; // rax
  UFG::AIScriptInterfaceComponent *v9; // rdi
  UFG::SimObject *v10; // rdx
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  if ( required )
    goto LABEL_17;
  v3 = pSceneObj->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             v3,
             (UFG::qSymbol *)&SimSymX_propset_componentAiScriptInterface.mUID,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_17:
    v5 = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(v5, 0x838ui64, "AIScriptInterfaceComponent", 0i64, 1u);
    if ( v6 )
    {
      v7 = v2->mpWritableProperties;
      if ( !v7 )
        v7 = v2->mpConstProperties;
      UFG::AIScriptInterfaceComponent::AIScriptInterfaceComponent(
        (UFG::AIScriptInterfaceComponent *)v6,
        v2->m_NameUID,
        v7);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = v2->m_pSimObject;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 )
      v12 = 5;
    else
      v12 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, v10, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, (UFG::SimComponent *)&v9->vfptr, v12);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    result = (UFG::qPropertySet *)v9;
  }
  return result;
}

// File Line: 88
// RVA: 0x382720
void __fastcall UFG::AIScriptInterfaceComponent::Reset(UFG::AIScriptInterfaceComponent *this)
{
  UFG::AIScriptInterfaceComponent *v1; // rdi
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::SimComponent *v4; // rsi
  unsigned __int8 v5; // cl
  signed __int64 v6; // rbx

  v1 = this;
  *(_QWORD *)&this->m_ScriptTaskRefCount = 0i64;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_Offset.x = UFG::qVector3::msZero.x;
  this->m_Offset.y = v2;
  this->m_Offset.z = v3;
  *((_BYTE *)this + 2096) |= 1u;
  this->m_NumScriptArguments = 0;
  this->m_DesiredEmotion = 0;
  this->m_ActionRequestToHold.mBits[0] = 0i64;
  this->m_ActionRequestToHold.mBits[1] = 0i64;
  this->m_ActionRequestToHold.mBits[2] = 0i64;
  this->m_ActionRequestToHold.mBits[3] = 0i64;
  this->m_ActionRequestToHold.mBits[4] = 0i64;
  this->m_ActionRequestToHold.mBits[5] = 0i64;
  this->m_ActionRequestToHold.mBits[6] = 0i64;
  this->m_ActionRequestToHold.mBits[7] = 0i64;
  this->m_ActionRequestToHold.mBits[8] = 0i64;
  *((_BYTE *)this + 2096) &= 0xF7u;
  UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride(this);
  v4 = v1->m_pTargetingSystemBaseComponent.m_pSimComponent;
  *((_BYTE *)v1 + 2096) &= 0x8Fu;
  v1->m_DesiredEmotion = 0;
  if ( v4 )
  {
    v5 = *(_BYTE *)(*(_QWORD *)&v4[1].m_Flags + 40i64);
    if ( v5 )
    {
      v6 = 56i64 * v5;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v6 + *(_QWORD *)&v4[1].m_TypeUID), 0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v6 + *(_QWORD *)&v4[1].m_TypeUID), 0);
    }
  }
  *((_BYTE *)v1 + 2096) &= 0x73u;
  *((_BYTE *)v1 + 2098) &= 0xFCu;
  *((_BYTE *)v1 + 2097) = 83;
  v1->m_DebugDrawFollowers = 0;
}

// File Line: 152
// RVA: 0x378690
void __fastcall UFG::AIScriptInterfaceComponent::OnAttach(UFG::AIScriptInterfaceComponent *this, UFG::SimObject *object)
{
  UFG::AIScriptInterfaceComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax

  v2 = this;
  v3 = &this->m_pAIEntityComponent;
  v4 = object;
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
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
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
  v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = v4;
  v2->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pSimObjectCharacterPropertiesComponent,
    v4);
  v14 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->m_pTargetingSystemBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v2->m_pTargetingSystemBaseComponent.m_pSimObject = v4;
  v2->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pTargetingSystemBaseComponent,
    v4);
  UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet(v2);
}

// File Line: 166
// RVA: 0x379D90
void __fastcall UFG::AIScriptInterfaceComponent::OnDetach(UFG::AIScriptInterfaceComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v1; // r8
  UFG::AIScriptInterfaceComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

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
  v12 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  }
  else
  {
    if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v12->mPrev != v12
       || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
    {
      v15 = v12->mPrev;
      v16 = v2->m_pTargetingSystemBaseComponent.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
      v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
      v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    }
    v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  }
}

// File Line: 178
// RVA: 0x388DE0
void __fastcall UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(UFG::AIScriptInterfaceComponent *this, const char *action_request_name)
{
  UFG::AIScriptInterfaceComponent *v2; // rbx
  unsigned int action_request; // [rsp+40h] [rbp+18h]

  v2 = this;
  action_request = gActionRequest_Action.m_EnumValue;
  if ( Intention::GetActionRequest(action_request_name, &action_request) )
  {
    v2->m_ActionRequestToHold.mBits[(signed __int64)(signed int)action_request >> 6] |= 1i64 << (action_request & 0x3F);
    *((_BYTE *)v2 + 2096) |= 8u;
  }
}

// File Line: 190
// RVA: 0x3891C0
void __fastcall UFG::AIScriptInterfaceComponent::StopHoldingActionRequest(UFG::AIScriptInterfaceComponent *this, const char *action_request_name)
{
  UFG::AIScriptInterfaceComponent *v2; // rbx
  int v3; // eax
  unsigned int v4; // er8
  unsigned __int64 v5; // rcx
  unsigned int action_request; // [rsp+40h] [rbp+18h]

  v2 = this;
  action_request = gActionRequest_Action.m_EnumValue;
  if ( Intention::GetActionRequest(action_request_name, &action_request) )
  {
    v2->m_ActionRequestToHold.mBits[(signed __int64)(signed int)action_request >> 6] &= ~(1i64 << (action_request & 0x3F));
    *((_BYTE *)v2 + 2096) &= 0xF7u;
    v3 = 0;
    v4 = (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0 ? 0 : (*gActionRequestEnum.m_enumLists.p)->m_enumName.size;
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = v2->m_ActionRequestToHold.mBits[(signed __int64)v3 >> 6];
        if ( _bittest64((const signed __int64 *)&v5, v3 & 0x3F) )
          break;
        if ( ++v3 >= v4 )
          return;
      }
      *((_BYTE *)v2 + 2096) |= 8u;
    }
  }
}

// File Line: 213
// RVA: 0x389280
void __fastcall UFG::AIScriptInterfaceComponent::StopHoldingAllActionRequests(UFG::AIScriptInterfaceComponent *this)
{
  this->m_ActionRequestToHold.mBits[0] = 0i64;
  this->m_ActionRequestToHold.mBits[1] = 0i64;
  this->m_ActionRequestToHold.mBits[2] = 0i64;
  this->m_ActionRequestToHold.mBits[3] = 0i64;
  this->m_ActionRequestToHold.mBits[4] = 0i64;
  this->m_ActionRequestToHold.mBits[5] = 0i64;
  this->m_ActionRequestToHold.mBits[6] = 0i64;
  this->m_ActionRequestToHold.mBits[7] = 0i64;
  this->m_ActionRequestToHold.mBits[8] = 0i64;
  *((_BYTE *)this + 2096) &= 0xF7u;
}

// File Line: 219
// RVA: 0x383F10
void __fastcall UFG::AIScriptInterfaceComponent::ScriptTaskIncrement(UFG::AIScriptInterfaceComponent *this)
{
  ++this->m_ScriptTaskRefCount;
}

// File Line: 224
// RVA: 0x383F00
void __fastcall UFG::AIScriptInterfaceComponent::ScriptTaskDecrement(UFG::AIScriptInterfaceComponent *this)
{
  --this->m_ScriptTaskRefCount;
}

// File Line: 263
// RVA: 0x3493C0
void __fastcall UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(UFG::AIScriptInterfaceComponent *this)
{
  *((_BYTE *)this + 2096) &= 0xF9u;
}

// File Line: 274
// RVA: 0x363830
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(UFG::AIScriptInterfaceComponent *this, UFG::eScriptCommand command)
{
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    if ( this->m_CurrentScriptCommand == eSCRIPT_COMMAND_NONE )
    {
      this->m_CurrentScriptCommand = command;
      this->m_NumScriptArguments = 0;
      return 1;
    }
  }
  else
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command '%s' because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
  }
  return 0;
}

// File Line: 289
// RVA: 0x363880
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(UFG::AIScriptInterfaceComponent *this, UFG::eScriptCommand command, UFG::qVector3 *vector)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  char result; // al

  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    if ( this->m_CurrentScriptCommand == eSCRIPT_COMMAND_NONE )
    {
      this->m_CurrentScriptCommand = command;
      v3 = vector->y;
      v4 = vector->z;
      this->m_ScriptArgument[0].m_Vector.x = vector->x;
      this->m_ScriptArgument[0].m_Vector.y = v3;
      result = 1;
      this->m_ScriptArgument[0].m_Vector.z = v4;
      this->m_ScriptArgument[0].m_Type = 1;
      this->m_NumScriptArguments = 1;
      return result;
    }
  }
  else
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command '%s' because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command],
      vector);
  }
  return 0;
}

// File Line: 340
// RVA: 0x3638F0
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(UFG::AIScriptInterfaceComponent *this, UFG::eScriptCommand command, float floating_point)
{
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    if ( this->m_CurrentScriptCommand == eSCRIPT_COMMAND_NONE )
    {
      this->m_CurrentScriptCommand = command;
      this->m_ScriptArgument[0].m_Float = floating_point;
      this->m_ScriptArgument[0].m_Type = 4;
      this->m_NumScriptArguments = 1;
      return 1;
    }
  }
  else
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command '%s' because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
  }
  return 0;
}

// File Line: 357
// RVA: 0x363950
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(UFG::AIScriptInterfaceComponent *this, UFG::eScriptCommand command, UFG::TransformNodeComponent *transform_node_component)
{
  UFG::AIScriptInterfaceComponent *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  char result; // al

  v3 = this;
  if ( !this->m_pAIEntityComponent.m_pSimComponent )
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command '%s' because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command],
      transform_node_component,
      this);
    return 0;
  }
  if ( this->m_CurrentScriptCommand )
    return 0;
  this->m_CurrentScriptCommand = command;
  v4 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_ScriptArgument[0].m_pTransformNodeComponent.mPrev;
  if ( this->m_ScriptArgument[0].m_pTransformNodeComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)transform_node_component;
  if ( transform_node_component )
  {
    v7 = transform_node_component->m_SafePointerList.mNode.mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    v4->mNext = &transform_node_component->m_SafePointerList.mNode;
    transform_node_component->m_SafePointerList.mNode.mPrev = v4;
  }
  v3->m_ScriptArgument[0].m_Type = 6;
  result = 1;
  v3->m_NumScriptArguments = 1;
  return result;
}

// File Line: 389
// RVA: 0x33FF70
char __fastcall UFG::AIScriptInterfaceComponent::AddArgument(UFG::AIScriptInterfaceComponent *this, const char *string)
{
  __int64 v2; // rax
  UFG::AIScriptInterfaceComponent *v3; // rbx
  char result; // al

  v2 = this->m_NumScriptArguments;
  v3 = this;
  if ( (signed int)v2 >= 5 )
    return 0;
  UFG::qSharedString::operator=((UFG::qSharedString *)&(&this->vfptr)[v2 + 8 * v2 + 14], string);
  result = 1;
  v3->m_ScriptArgument[v3->m_NumScriptArguments++].m_Type = 2;
  return result;
}

// File Line: 404
// RVA: 0x33FF30
char __fastcall UFG::AIScriptInterfaceComponent::AddArgument(UFG::AIScriptInterfaceComponent *this, int integer)
{
  __int64 v2; // rax
  char result; // al

  v2 = this->m_NumScriptArguments;
  if ( (signed int)v2 >= 5 )
    return 0;
  this->m_ScriptArgument[v2].m_Int = integer;
  result = 1;
  this->m_ScriptArgument[this->m_NumScriptArguments++].m_Type = 3;
  return result;
}

// File Line: 419
// RVA: 0x33FFD0
char __fastcall UFG::AIScriptInterfaceComponent::AddArgument(UFG::AIScriptInterfaceComponent *this, __int64 symbol)
{
  __int64 v2; // rax
  char result; // al

  v2 = this->m_NumScriptArguments;
  if ( (signed int)v2 >= 5 )
    return 0;
  this->m_ScriptArgument[v2].m_Symbol.mUID = *(_DWORD *)symbol;
  result = 1;
  this->m_ScriptArgument[this->m_NumScriptArguments++].m_Type = 5;
  return result;
}

// File Line: 464
// RVA: 0x386060
void __fastcall UFG::AIScriptInterfaceComponent::SetDesiredTarget(UFG::AIScriptInterfaceComponent *this, UFG::eTargetTypeEnum target_type, UFG::SimObject *prop_target)
{
  UFG::AIEntityComponent *v3; // r9
  bool v4; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  v3 = (UFG::AIEntityComponent *)this->m_pAIEntityComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = *((_QWORD *)&v3->m_SafePointerList.mNode.mNext + 3 * ((signed int)target_type + 81i64)) == 0i64;
    v5 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&(&v3->vfptr)[3 * ((signed int)target_type + 81i64)];
    if ( !v4 )
    {
      v6 = v5->mPrev;
      v7 = v5->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = v5;
      v5->mNext = v5;
    }
    v5[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)prop_target;
    if ( prop_target )
    {
      v8 = prop_target->m_SafePointerList.mNode.mPrev;
      v8->mNext = v5;
      v5->mPrev = v8;
      v5->mNext = &prop_target->m_SafePointerList.mNode;
      prop_target->m_SafePointerList.mNode.mPrev = v5;
    }
  }
}

// File Line: 532
// RVA: 0x385050
void __fastcall UFG::AIScriptInterfaceComponent::SetCollisionAvoidanceOverride(UFG::AIScriptInterfaceComponent *this, __int64 overRideType)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned int v3; // ebx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  UFG::NavComponent *v6; // rax
  bool v7; // zf
  UFG::NavComponent *v8; // rax

  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  v3 = overRideType;
  if ( !v2 )
  {
    UFG::NavComponent::SetCollisionAvoidanceType(0i64, overRideType);
    return;
  }
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    UFG::NavComponent::SetCollisionAvoidanceType((UFG::NavComponent *)v2->m_Components.p[36].m_pComponent, v3);
    return;
  }
  if ( (v4 & 0x8000u) != 0 || (v4 >> 13) & 1 )
  {
    v5 = UFG::NavComponent::_TypeUID;
LABEL_7:
    v6 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, v5);
    UFG::NavComponent::SetCollisionAvoidanceType(v6, v3);
    return;
  }
  v7 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::NavComponent::_TypeUID;
  if ( !v7 )
    goto LABEL_7;
  v8 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v2->vfptr,
                              UFG::NavComponent::_TypeUID);
  UFG::NavComponent::SetCollisionAvoidanceType(v8, v3);
}

// File Line: 541
// RVA: 0x34F100
void __fastcall UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride(UFG::AIScriptInterfaceComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::NavComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::NavComponent *)v1->m_Components.p[36].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::NavComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::NavComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v1->vfptr,
                                    UFG::NavComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::NavComponent::_TypeUID);
    }
    if ( v3 )
      UFG::NavComponent::SetCollisionAvoidanceType(v3, 0i64);
  }
}

// File Line: 550
// RVA: 0x37F670
void __fastcall UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet(UFG::AIScriptInterfaceComponent *this)
{
  UFG::AIScriptInterfaceComponent *v1; // rdi
  UFG::SimObject *v2; // rax
  UFG::SceneObjectProperties *v3; // rdx
  UFG::qPropertySet *v4; // r15
  UFG::qPropertySet *v5; // rax
  object_physical_character_stats_BaseAttackParameters *v6; // rax
  signed __int64 v7; // rbp
  signed __int64 v8; // r11
  signed __int64 v9; // r9
  signed __int64 v10; // rbx
  signed __int64 v11; // r10
  _DWORD *v12; // rcx
  _DWORD *v13; // rdx
  signed __int64 v14; // r8
  float (*v15)[2][2][2]; // rcx
  signed __int64 v16; // r9
  signed __int64 v17; // r8
  signed __int64 v18; // rdx
  bool *v19; // rax
  char *v20; // rcx
  char v21; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 || !v2->m_pSceneObj )
  {
    v4 = 0i64;
LABEL_6:
    if ( !v4 )
      return;
    goto LABEL_7;
  }
  v3 = v2->m_pSceneObj;
  v4 = v3->mpWritableProperties;
  if ( !v4 )
  {
    v4 = v3->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&object_physical_character_stats_BaseAttackParameters::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
  {
    v6 = (object_physical_character_stats_BaseAttackParameters *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v6 )
    {
      v1->m_InitialAttackTimeMin[0][0][0][0][0] = v6->InitialAttackTimeMinMeleeVSHumanAsEnemy;
      v1->m_InitialAttackTimeMax[0][0][0][0][0] = v6->InitialAttackTimeMaxMeleeVSHumanAsEnemy;
      v1->m_AttackTimeMin[0][0][0][0][0] = v6->AttackTimeMinMeleeVSHumanAsEnemy;
      v1->m_AttackTimeMax[0][0][0][0][0] = v6->AttackTimeMaxMeleeVSHumanAsEnemy;
      v1->m_AttackTimeMinDowned[0][0][0][0][0] = v6->AttackTimeMinMeleeDownedVSHumanAsEnemy;
      v1->m_AttackTimeMaxDowned[0][0][0][0][0] = v6->AttackTimeMaxMeleeDownedVSHumanAsEnemy;
      v1->m_InitialAttackTimeMin[0][0][0][1][0] = v6->InitialAttackTimeMinMeleeVSAIAsEnemy;
      v1->m_InitialAttackTimeMax[0][0][0][1][0] = v6->InitialAttackTimeMaxMeleeVSAIAsEnemy;
      v1->m_AttackTimeMin[0][0][0][1][0] = v6->AttackTimeMinMeleeVSAIAsEnemy;
      v1->m_AttackTimeMax[0][0][0][1][0] = v6->AttackTimeMaxMeleeVSAIAsEnemy;
      v1->m_AttackTimeMinDowned[0][0][0][1][0] = v6->AttackTimeMinMeleeDownedVSAIAsEnemy;
      v1->m_AttackTimeMaxDowned[0][0][0][1][0] = v6->AttackTimeMaxMeleeDownedVSAIAsEnemy;
      v1->m_InitialAttackTimeMin[0][0][1][1][0] = v6->InitialAttackTimeMinMeleeVSAIAsAlly;
      v1->m_InitialAttackTimeMax[0][0][1][1][0] = v6->InitialAttackTimeMaxMeleeVSAIAsAlly;
      v1->m_AttackTimeMin[0][0][1][1][0] = v6->AttackTimeMinMeleeVSAIAsAlly;
      v1->m_AttackTimeMax[0][0][1][1][0] = v6->AttackTimeMaxMeleeVSAIAsAlly;
      v1->m_AttackTimeMinDowned[0][0][1][1][0] = v6->AttackTimeMinMeleeDownedVSAIAsAlly;
      v1->m_AttackTimeMaxDowned[0][0][1][1][0] = v6->AttackTimeMaxMeleeDownedVSAIAsAlly;
      v1->m_InitialAttackTimeMin[0][1][0][0][0] = v6->InitialAttackTimeMinRangedVSHumanAsEnemy;
      v1->m_InitialAttackTimeMax[0][1][0][0][0] = v6->InitialAttackTimeMaxRangedVSHumanAsEnemy;
      v1->m_AttackTimeMin[0][1][0][0][0] = v6->AttackTimeMinRangedVSHumanAsEnemy;
      v1->m_AttackTimeMax[0][1][0][0][0] = v6->AttackTimeMaxRangedVSHumanAsEnemy;
      v1->m_AttackTimeMinDowned[0][1][0][0][0] = v6->AttackTimeMinRangedDownedVSHumanAsEnemy;
      v1->m_AttackTimeMaxDowned[0][1][0][0][0] = v6->AttackTimeMaxRangedDownedVSHumanAsEnemy;
      v1->m_InitialAttackTimeMin[0][1][0][1][0] = v6->InitialAttackTimeMinRangedVSAIAsEnemy;
      v1->m_InitialAttackTimeMax[0][1][0][1][0] = v6->InitialAttackTimeMaxRangedVSAIAsEnemy;
      v1->m_AttackTimeMin[0][1][0][1][0] = v6->AttackTimeMinRangedVSAIAsEnemy;
      v1->m_AttackTimeMax[0][1][0][1][0] = v6->AttackTimeMaxRangedVSAIAsEnemy;
      v1->m_AttackTimeMinDowned[0][1][0][1][0] = v6->AttackTimeMinRangedDownedVSAIAsEnemy;
      v1->m_AttackTimeMaxDowned[0][1][0][1][0] = v6->AttackTimeMaxRangedDownedVSAIAsEnemy;
      v1->m_InitialAttackTimeMin[0][2][0][0][0] = v6->InitialAttackTimeMinDirectFollowersVSHumanAsEnemy;
      v1->m_InitialAttackTimeMax[0][2][0][0][0] = v6->InitialAttackTimeMaxDirectFollowersVSHumanAsEnemy;
      v1->m_AttackTimeMin[0][2][0][0][0] = v6->AttackTimeMinDirectFollowersVSHumanAsEnemy;
      v1->m_AttackTimeMax[0][2][0][0][0] = v6->AttackTimeMaxDirectFollowersVSHumanAsEnemy;
      v1->m_AttackTimeMinDowned[0][2][0][0][0] = v6->AttackTimeMinDirectFollowersDownedVSHumanAsEnemy;
      v1->m_AttackTimeMaxDowned[0][2][0][0][0] = v6->AttackTimeMaxDirectFollowersDownedVSHumanAsEnemy;
      v1->m_InitialAttackTimeMin[0][2][0][1][0] = v6->InitialAttackTimeMinDirectFollowersVSAIAsEnemy;
      v1->m_InitialAttackTimeMax[0][2][0][1][0] = v6->InitialAttackTimeMaxDirectFollowersVSAIAsEnemy;
      v1->m_AttackTimeMin[0][2][0][1][0] = v6->AttackTimeMinDirectFollowersVSAIAsEnemy;
      v1->m_AttackTimeMax[0][2][0][1][0] = v6->AttackTimeMaxDirectFollowersVSAIAsEnemy;
      v1->m_AttackTimeMinDowned[0][2][0][1][0] = v6->AttackTimeMinDirectFollowersDownedVSAIAsEnemy;
      v1->m_AttackTimeMaxDowned[0][2][0][1][0] = v6->AttackTimeMaxDirectFollowersDownedVSAIAsEnemy;
      v1->m_InitialAttackTimeMin[0][1][1][1][0] = v6->InitialAttackTimeMinRangedVSAIAsAlly;
      v1->m_InitialAttackTimeMax[0][1][1][1][0] = v6->InitialAttackTimeMaxRangedVSAIAsAlly;
      v1->m_AttackTimeMin[0][1][1][1][0] = v6->AttackTimeMinRangedVSAIAsAlly;
      v1->m_AttackTimeMax[0][1][1][1][0] = v6->AttackTimeMaxRangedVSAIAsAlly;
      v1->m_AttackTimeMinDowned[0][1][1][1][0] = v6->AttackTimeMinRangedDownedVSAIAsAlly;
      v1->m_AttackTimeMaxDowned[0][1][1][1][0] = v6->AttackTimeMaxRangedDownedVSAIAsAlly;
      v1->m_InitialAttackTimeMin[0][2][1][1][0] = v6->InitialAttackTimeMinDirectFollowersVSAIAsAlly;
      v1->m_InitialAttackTimeMax[0][2][1][1][0] = v6->InitialAttackTimeMaxDirectFollowersVSAIAsAlly;
      v1->m_AttackTimeMin[0][2][1][1][0] = v6->AttackTimeMinDirectFollowersVSAIAsAlly;
      v1->m_AttackTimeMax[0][2][1][1][0] = v6->AttackTimeMaxDirectFollowersVSAIAsAlly;
      v1->m_AttackTimeMinDowned[0][2][1][1][0] = v6->AttackTimeMinDirectFollowersDownedVSAIAsAlly;
      v1->m_AttackTimeMaxDowned[0][2][1][1][0] = v6->AttackTimeMaxDirectFollowersDownedVSAIAsAlly;
      v7 = 3i64;
      v8 = 4i64;
      do
      {
        v9 = (signed __int64)v1->m_InitialAttackTimeMax;
        v10 = 3i64;
        do
        {
          v11 = 2i64;
          do
          {
            v12 = (_DWORD *)v9;
            v13 = (_DWORD *)(v8 + v9);
            v14 = 2i64;
            do
            {
              *(v13 - 48) = *(v12 - 48);
              *v13 = *v12;
              v13[48] = v12[48];
              v13[96] = v12[96];
              v13[144] = v12[144];
              v13[192] = v12[192];
              v12 += 2;
              v13 += 2;
              --v14;
            }
            while ( v14 );
            v9 += 16i64;
            --v11;
          }
          while ( v11 );
          --v10;
        }
        while ( v10 );
        v8 += 96i64;
      }
      while ( v8 < 196 );
      v1->m_InitialAttackTimeMin[0][1][0][0][1] = v6->InitialAttackTimeMinRangedInCoverVSHumanAsEnemy;
      v1->m_InitialAttackTimeMax[0][1][0][0][1] = v6->InitialAttackTimeMaxRangedInCoverVSHumanAsEnemy;
      v1->m_AttackTimeMin[0][1][0][0][1] = v6->AttackTimeMinRangedInCoverVSHumanAsEnemy;
      v1->m_AttackTimeMax[0][1][0][0][1] = v6->AttackTimeMaxRangedInCoverVSHumanAsEnemy;
      v1->m_AttackTimeMinDowned[0][1][0][0][1] = v6->AttackTimeMinRangedInCoverDownedVSHumanAsEnemy;
      v1->m_AttackTimeMaxDowned[0][1][0][0][1] = v6->AttackTimeMaxRangedInCoverDownedVSHumanAsEnemy;
      v1->m_InitialAttackTimeMin[0][1][0][1][1] = v6->InitialAttackTimeMinRangedInCoverVSAIAsEnemy;
      v1->m_InitialAttackTimeMax[0][1][0][1][1] = v6->InitialAttackTimeMaxRangedInCoverVSAIAsEnemy;
      v1->m_AttackTimeMin[0][1][0][1][1] = v6->AttackTimeMinRangedInCoverVSAIAsEnemy;
      v1->m_AttackTimeMax[0][1][0][1][1] = v6->AttackTimeMaxRangedInCoverVSAIAsEnemy;
      v1->m_AttackTimeMinDowned[0][1][0][1][1] = v6->AttackTimeMinRangedInCoverDownedVSAIAsEnemy;
      v1->m_AttackTimeMaxDowned[0][1][0][1][1] = v6->AttackTimeMaxRangedInCoverDownedVSAIAsEnemy;
      v1->m_InitialAttackTimeMin[0][1][0][1][1] = v6->InitialAttackTimeMinRangedInCoverVSAIAsAlly;
      v1->m_InitialAttackTimeMax[0][1][0][1][1] = v6->InitialAttackTimeMaxRangedInCoverVSAIAsAlly;
      v1->m_AttackTimeMin[0][1][0][1][1] = v6->AttackTimeMinRangedInCoverVSAIAsAlly;
      v1->m_AttackTimeMax[0][1][0][1][1] = v6->AttackTimeMaxRangedInCoverVSAIAsAlly;
      v1->m_AttackTimeMinDowned[0][1][0][1][1] = v6->AttackTimeMinRangedInCoverDownedVSAIAsAlly;
      v1->m_AttackTimeMaxDowned[0][1][0][1][1] = v6->AttackTimeMaxRangedInCoverDownedVSAIAsAlly;
      v15 = v1->m_InitialAttackTimeMin[1];
      do
      {
        v16 = 2i64;
        do
        {
          v17 = 2i64;
          do
          {
            v18 = 2i64;
            do
            {
              *(float *)v15 = (*v15)[-6][0][0];
              (*v15)[12][0][0] = (*v15)[6][0][0];
              (*v15)[24][0][0] = (*v15)[18][0][0];
              (*v15)[36][0][0] = (*v15)[30][0][0];
              (*v15)[48][0][0] = (*v15)[42][0][0];
              (*v15)[60][0][0] = (*v15)[54][0][0];
              v15 = (float (*)[2][2][2])((char *)v15 + 4);
              --v18;
            }
            while ( v18 );
            --v17;
          }
          while ( v17 );
          --v16;
        }
        while ( v16 );
        --v7;
      }
      while ( v7 );
      v1->m_AttackTimeMin[1][0][0][0][0] = v6->AttackTimeMinMeleeVSHumanAsEnemyMobBattle;
      v1->m_AttackTimeMin[1][0][0][0][1] = v6->AttackTimeMinMeleeVSHumanAsEnemyMobBattle;
      v1->m_AttackTimeMax[1][0][0][0][0] = v6->AttackTimeMaxMeleeVSHumanAsEnemyMobBattle;
      v1->m_AttackTimeMax[1][0][0][0][1] = v6->AttackTimeMaxMeleeVSHumanAsEnemyMobBattle;
      if ( !(_S27_0 & 1) )
      {
        _S27_0 |= 1u;
        UFG::qSymbol::create_from_string(&AllowedToSprintDuringCombatSymbol, "AllowedToSprintDuringCombat");
        atexit(UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet_::_28_::_dynamic_atexit_destructor_for__AllowedToSprintDuringCombatSymbol__);
      }
      v21 = 0;
      v19 = UFG::qPropertySet::Get<bool>(v4, &AllowedToSprintDuringCombatSymbol, DEPTH_RECURSE);
      v20 = &v21;
      if ( v19 )
        v20 = (char *)v19;
      *((_BYTE *)v1 + 2097) ^= (*((_BYTE *)v1 + 2097) ^ (*v20 << 6)) & 0x40;
    }
  }
}

// File Line: 864
// RVA: 0x360770
float __fastcall UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMin(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::TargetingSystemBaseComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = (UFG::TargetingSystemBaseComponent *)v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13 && v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer )
  {
    v14 = (UFG::SimObjectCharacter *)v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer;
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 22 + 3 * v6))));
}

// File Line: 873
// RVA: 0x360670
float __fastcall UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMax(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 28 + 3 * v6))));
}

// File Line: 882
// RVA: 0x35A140
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMin(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 34 + 3 * v6))));
}

// File Line: 891
// RVA: 0x359F40
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMax(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 40 + 3 * v6))));
}

// File Line: 900
// RVA: 0x35A240
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMinDowned(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 46 + 3 * v6))));
}

// File Line: 909
// RVA: 0x35A040
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMaxDowned(UFG::AIScriptInterfaceComponent *this, UFG::eAttackType attack_type, UFG::eTargetTypeEnum target_type, UFG::eInCoverType in_cover_type)
{
  signed int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r12
  UFG::SimComponent *v7; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  UFG::AIScriptInterfaceComponent *v10; // rsi
  signed int v11; // er10
  __int64 v12; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  v6 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v7 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = (unsigned int)target_type;
  v9 = (signed int)attack_type;
  v10 = this;
  v11 = -1;
  if ( v7 )
  {
    v12 = SLODWORD(v7[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v12][2] == 0;
  }
  v13 = v10->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return *((float *)&v10->vfptr + v5 + 2 * (v4 + 2 * (v11 + 2 * (v9 + 52 + 3 * v6))));
}

// File Line: 918
// RVA: 0x34F6B0
void __fastcall UFG::AIScriptInterfaceComponent::ClearPositionToDefend(UFG::AIScriptInterfaceComponent *this)
{
  UFG::SimComponent *v1; // rdi
  unsigned __int8 v2; // cl
  signed __int64 v3; // rbx

  v1 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  *((_BYTE *)this + 2096) &= 0xBFu;
  if ( v1 )
  {
    v2 = *(_BYTE *)(*(_QWORD *)&v1[1].m_Flags + 40i64);
    if ( v2 )
    {
      v3 = 56i64 * v2;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v3 + *(_QWORD *)&v1[1].m_TypeUID), 0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v3 + *(_QWORD *)&v1[1].m_TypeUID), 0);
    }
  }
}

// File Line: 929
// RVA: 0x387A40
void __fastcall UFG::AIScriptInterfaceComponent::SetPositionToDefend(UFG::AIScriptInterfaceComponent *this, UFG::SimObject *marker_to_defend, float radius, bool crouch, bool abandon_when_compromised, bool abandon_when_no_gun)
{
  UFG::AIScriptInterfaceComponent *v6; // rbx
  UFG::TargetingSystemBaseComponent *v7; // rcx
  char v8; // di
  char v9; // al

  v6 = this;
  v7 = (UFG::TargetingSystemBaseComponent *)this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  v8 = crouch;
  if ( v7 )
    UFG::TargetingSystemBaseComponent::SetTarget(v7, eTARGET_TYPE_SCRIPTED_MARKER, marker_to_defend);
  v9 = *((_BYTE *)v6 + 2096);
  *((_BYTE *)v6 + 2097) &= 0xFCu;
  v6->m_RadiusToDefend = radius;
  *((_BYTE *)v6 + 2096) = (v8 << 7) | v9 & 0x3F | 0x40;
  *((_BYTE *)v6 + 2097) |= abandon_when_compromised | (unsigned __int8)(2 * abandon_when_no_gun);
}

// File Line: 943
// RVA: 0x362270
UFG::qVector3 *__fastcall UFG::AIScriptInterfaceComponent::GetPositionToDefend(UFG::AIScriptInterfaceComponent *this)
{
  UFG::TransformNodeComponent *v1; // rbx

  v1 = *(UFG::TransformNodeComponent **)(56i64
                                       * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                            + 40i64)
                                       + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                       + 40);
  if ( v1 )
    v1 = (UFG::TransformNodeComponent *)v1->mChildren.mNode.mNext;
  if ( !v1 )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform(v1);
  return (UFG::qVector3 *)&v1->mWorldTransform.v3;
}

// File Line: 958
// RVA: 0x340760
void __fastcall UFG::AIScriptInterfaceComponent::AddFollower(UFG::AIScriptInterfaceComponent *this, UFG::ActiveAIEntityComponent *follower)
{
  int v2; // er9
  UFG::ActiveAIEntityComponent *v3; // r10
  UFG::SimComponent **v4; // rax
  signed __int64 v5; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = 0;
  v3 = follower;
  v4 = &this->m_pFollower[0].m_pPointer;
  v5 = 0i64;
  while ( *v4 )
  {
    ++v5;
    ++v2;
    v4 += 3;
    if ( v5 >= 10 )
      return;
  }
  v6 = &this->m_pFollower[v2];
  if ( this->m_pFollower[v2].m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v6->m_pPointer = (UFG::SimComponent *)&v3->vfptr;
  if ( v3 )
  {
    v9 = v3->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v6->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

// File Line: 973
// RVA: 0x3539F0
void __fastcall UFG::AIScriptInterfaceComponent::DrawDebugInfo(UFG::AIScriptInterfaceComponent *this, Render::View *view)
{
  UFG::SimObject *v2; // rbp
  UFG::AIScriptInterfaceComponent *v3; // r14
  UFG::TransformNodeComponent *v4; // rbp
  UFG::SimComponent **v5; // rbx
  signed __int64 v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::TransformNodeComponent *v9; // rdi
  __m128i v10; // xmm6
  UFG::TransformNodeComponent *v11; // rdx
  float v12; // xmm1_4
  float v13; // xmm0_4
  Render::DebugDrawContext *v14; // rax
  const char *v15; // rbx
  Render::DebugDrawContext *v16; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-68h]
  __int128 v18; // [rsp+40h] [rbp-58h]
  UFG::qColour colour; // [rsp+50h] [rbp-48h]

  v2 = this->m_pSimObject;
  v3 = this;
  if ( v2 )
    v4 = v2->m_pTransformNodeComponent;
  else
    v4 = 0i64;
  if ( this->m_DebugDrawFollowers && v4 )
  {
    v5 = &this->m_pFollower[0].m_pPointer;
    v6 = 10i64;
    do
    {
      v7 = *v5;
      if ( *v5 )
      {
        v8 = v7[6].m_pSimObject;
        v9 = *(UFG::TransformNodeComponent **)&v7[1].m_TypeUID;
        if ( v8 )
        {
          if ( v9 )
          {
            v10 = (__m128i)UFG::qColour::Green;
            if ( BYTE4(v8->m_UnboundComponentHandles.mNode.mPrev) )
              v10 = (__m128i)UFG::qColour::Red;
            v11 = *(UFG::TransformNodeComponent **)&v7[1].m_TypeUID;
            _mm_store_si128((__m128i *)&v18, v10);
            UFG::DrawLine(v4, v11, (UFG::qColour *)&v18, 0.5);
            _mm_store_si128((__m128i *)&colour, v10);
            UFG::TransformNodeComponent::UpdateWorldTransform(v9);
            v12 = v9->mWorldTransform.v3.y;
            point.x = v9->mWorldTransform.v3.x;
            v13 = v9->mWorldTransform.v3.z;
            point.y = v12;
            point.z = v13 + 0.5;
            v14 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                1u);
            Render::DebugDrawContext::DrawPoint(v14, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
          }
        }
      }
      v5 += 3;
      --v6;
    }
    while ( v6 );
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v15 = UFG::ScriptCommandNames[v3->m_CurrentScriptCommand];
    v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawText(v16, (UFG::qVector3 *)&v4->mWorldTransform.v3, &UFG::qColour::Red, v15);
  }
}

