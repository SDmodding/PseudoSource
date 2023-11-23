// File Line: 53
// RVA: 0x14AEA60
__int64 dynamic_initializer_for__UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList__);
}

// File Line: 54
// RVA: 0x363450
__int64 __fastcall UFG::AIScriptInterfaceComponent::GetTypeSize(UFG::AIScriptInterfaceComponent *this)
{
  return 2104i64;
}

// File Line: 58
// RVA: 0x32BD40
void __fastcall UFG::AIScriptInterfaceComponent::AIScriptInterfaceComponent(
        UFG::AIScriptInterfaceComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIScriptInterfaceComponent::`vftable;
  `eh vector constructor iterator(
    this->m_ScriptArgument,
    0x48ui64,
    5,
    (void (__fastcall *)(void *))UFG::ScriptArgument::ScriptArgument);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  this->m_ActionRequestToHold.mBits[0] = 0i64;
  this->m_ActionRequestToHold.mBits[1] = 0i64;
  this->m_ActionRequestToHold.mBits[2] = 0i64;
  this->m_ActionRequestToHold.mBits[3] = 0i64;
  this->m_ActionRequestToHold.mBits[4] = 0i64;
  this->m_ActionRequestToHold.mBits[5] = 0i64;
  this->m_ActionRequestToHold.mBits[6] = 0i64;
  this->m_ActionRequestToHold.mBits[7] = 0i64;
  this->m_ActionRequestToHold.mBits[8] = 0i64;
  `eh vector constructor iterator(
    this->m_pFollower,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
  mPrev = UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev;
  UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *)&UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList;
  UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID,
    "AIScriptInterfaceComponent");
  UFG::AIScriptInterfaceComponent::Reset(this);
}

// File Line: 67
// RVA: 0x334A10
void __fastcall UFG::AIScriptInterfaceComponent::~AIScriptInterfaceComponent(UFG::AIScriptInterfaceComponent *this)
{
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v2; // rbx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *mPrev; // rcx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *mNext; // rax
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v5; // rcx
  UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIScriptInterfaceComponent::`vftable;
  if ( this == UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentpCurrentIterator )
    UFG::AIScriptInterfaceComponent::s_AIScriptInterfaceComponentpCurrentIterator = (UFG::AIScriptInterfaceComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AIScriptInterfaceComponent,UFG::AIScriptInterfaceComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  `eh vector destructor iterator(
    this->m_pFollower,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
  `eh vector destructor iterator(
    this->m_ScriptArgument,
    0x48ui64,
    5,
    (void (__fastcall *)(void *))UFG::ScriptArgument::~ScriptArgument);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 73
// RVA: 0x37E950
UFG::qPropertySet *__fastcall UFG::AIScriptInterfaceComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::qPropertySet *mpConstProperties; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  if ( required )
    goto LABEL_5;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAiScriptInterface,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_5:
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x838ui64, "AIScriptInterfaceComponent", 0i64, 1u);
    if ( v6 )
    {
      mpConstProperties = pSceneObj->mpWritableProperties;
      if ( !mpConstProperties )
        mpConstProperties = pSceneObj->mpConstProperties;
      UFG::AIScriptInterfaceComponent::AIScriptInterfaceComponent(
        (UFG::AIScriptInterfaceComponent *)v6,
        pSceneObj->m_NameUID,
        mpConstProperties);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v12 = 5;
    else
      v12 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v13, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v13, v9, v12);
    UFG::SimObjectModifier::Close(&v13);
    UFG::SimObjectModifier::~SimObjectModifier(&v13);
    return (UFG::qPropertySet *)v9;
  }
  return result;
}

// File Line: 88
// RVA: 0x382720
void __fastcall UFG::AIScriptInterfaceComponent::Reset(UFG::AIScriptInterfaceComponent *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimComponent *m_pSimComponent; // rsi
  unsigned __int8 v5; // cl
  __int64 v6; // rbx

  *(_QWORD *)&this->m_ScriptTaskRefCount = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_Offset.x = UFG::qVector3::msZero.x;
  this->m_Offset.y = y;
  this->m_Offset.z = z;
  *((_BYTE *)this + 2096) |= 1u;
  this->m_NumScriptArguments = 0;
  this->m_DesiredEmotion = eAI_EMOTION_NONE;
  this->m_ActionRequestToHold.mBits[0] = 0i64;
  this->m_ActionRequestToHold.mBits[1] = 0i64;
  this->m_ActionRequestToHold.mBits[2] = 0i64;
  this->m_ActionRequestToHold.mBits[3] = 0i64;
  this->m_ActionRequestToHold.mBits[4] = 0i64;
  this->m_ActionRequestToHold.mBits[5] = 0i64;
  this->m_ActionRequestToHold.mBits[6] = 0i64;
  this->m_ActionRequestToHold.mBits[7] = 0i64;
  this->m_ActionRequestToHold.mBits[8] = 0i64;
  *((_BYTE *)this + 2096) &= ~8u;
  UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride(this);
  m_pSimComponent = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  *((_BYTE *)this + 2096) &= 0x8Fu;
  this->m_DesiredEmotion = eAI_EMOTION_NONE;
  if ( m_pSimComponent )
  {
    v5 = *(_BYTE *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 40i64);
    if ( v5 )
    {
      v6 = 56i64 * v5;
      UFG::TargetingSimObject::SetTarget(
        (UFG::TargetingSimObject *)(v6 + *(_QWORD *)&m_pSimComponent[1].m_TypeUID),
        0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v6 + *(_QWORD *)&m_pSimComponent[1].m_TypeUID), 0);
    }
  }
  *((_BYTE *)this + 2096) &= 0x73u;
  *((_BYTE *)this + 2098) &= 0xFCu;
  *((_BYTE *)this + 2097) = 83;
  this->m_DebugDrawFollowers = 0;
}

// File Line: 152
// RVA: 0x378690
void __fastcall UFG::AIScriptInterfaceComponent::OnAttach(
        UFG::AIScriptInterfaceComponent *this,
        UFG::SimObject *object)
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
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax

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
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
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
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pSimObjectCharacterPropertiesComponent,
    object);
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v15 = p_m_pTargetingSystemBaseComponent->mPrev;
    v16 = this->m_pTargetingSystemBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_22;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v17 = p_m_pTargetingSystemBaseComponent->mPrev;
    v18 = this->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  this->m_pTargetingSystemBaseComponent.m_pSimObject = object;
  this->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet(this);
}

// File Line: 166
// RVA: 0x379D90
void __fastcall UFG::AIScriptInterfaceComponent::OnDetach(UFG::AIScriptInterfaceComponent *this)
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
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

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
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v13 = p_m_pTargetingSystemBaseComponent->mPrev;
    v14 = this->m_pTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  }
  else
  {
    if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
      && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
       || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
    {
      v15 = p_m_pTargetingSystemBaseComponent->mPrev;
      v16 = this->m_pTargetingSystemBaseComponent.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  }
}

// File Line: 178
// RVA: 0x388DE0
void __fastcall UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(
        UFG::AIScriptInterfaceComponent *this,
        const char *action_request_name)
{
  unsigned int action_request; // [rsp+40h] [rbp+18h] BYREF

  action_request = gActionRequest_Action.m_EnumValue;
  if ( Intention::GetActionRequest(action_request_name, &action_request) )
  {
    this->m_ActionRequestToHold.mBits[(__int64)(int)action_request >> 6] |= 1i64 << (action_request & 0x3F);
    *((_BYTE *)this + 2096) |= 8u;
  }
}

// File Line: 190
// RVA: 0x3891C0
void __fastcall UFG::AIScriptInterfaceComponent::StopHoldingActionRequest(
        UFG::AIScriptInterfaceComponent *this,
        const char *action_request_name)
{
  int v3; // eax
  unsigned int v4; // r8d
  unsigned __int64 v5; // rcx
  unsigned int action_request; // [rsp+40h] [rbp+18h] BYREF

  action_request = gActionRequest_Action.m_EnumValue;
  if ( Intention::GetActionRequest(action_request_name, &action_request) )
  {
    this->m_ActionRequestToHold.mBits[(__int64)(int)action_request >> 6] &= ~(1i64 << (action_request & 0x3F));
    *((_BYTE *)this + 2096) &= ~8u;
    v3 = 0;
    v4 = (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0
       ? 0
       : (*gActionRequestEnum.m_enumLists.p)->m_enumName.size;
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = this->m_ActionRequestToHold.mBits[(__int64)v3 >> 6];
        if ( _bittest64((const __int64 *)&v5, v3 & 0x3F) )
          break;
        if ( ++v3 >= v4 )
          return;
      }
      *((_BYTE *)this + 2096) |= 8u;
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
  *((_BYTE *)this + 2096) &= ~8u;
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
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eScriptCommand command)
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
      "WARNING: Cannot perform script command %s because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
  }
  return 0;
}

// File Line: 289
// RVA: 0x363880
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eScriptCommand command,
        UFG::qVector3 *vector)
{
  float y; // xmm0_4
  float z; // xmm1_4
  char result; // al

  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    if ( this->m_CurrentScriptCommand == eSCRIPT_COMMAND_NONE )
    {
      this->m_CurrentScriptCommand = command;
      y = vector->y;
      z = vector->z;
      this->m_ScriptArgument[0].m_Vector.x = vector->x;
      this->m_ScriptArgument[0].m_Vector.y = y;
      result = 1;
      this->m_ScriptArgument[0].m_Vector.z = z;
      this->m_ScriptArgument[0].m_Type = eSCRIPT_ARGUMENT_VECTOR;
      this->m_NumScriptArguments = 1;
      return result;
    }
  }
  else
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command %s because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
  }
  return 0;
}

// File Line: 340
// RVA: 0x3638F0
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eScriptCommand command,
        float floating_point)
{
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    if ( this->m_CurrentScriptCommand == eSCRIPT_COMMAND_NONE )
    {
      this->m_CurrentScriptCommand = command;
      this->m_ScriptArgument[0].m_Float = floating_point;
      this->m_ScriptArgument[0].m_Type = eSCRIPT_ARGUMENT_FLOAT;
      this->m_NumScriptArguments = 1;
      return 1;
    }
  }
  else
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command %s because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
  }
  return 0;
}

// File Line: 357
// RVA: 0x363950
char __fastcall UFG::AIScriptInterfaceComponent::GiveCommand(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eScriptCommand command,
        UFG::TransformNodeComponent *transform_node_component)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  char result; // al

  if ( !this->m_pAIEntityComponent.m_pSimComponent )
  {
    UFG::qPrintf(
      "WARNING: Cannot perform script command %s because no AIEntityComponent\n",
      UFG::ScriptCommandNames[command]);
    return 0;
  }
  if ( this->m_CurrentScriptCommand )
    return 0;
  this->m_CurrentScriptCommand = command;
  p_m_pTransformNodeComponent = &this->m_ScriptArgument[0].m_pTransformNodeComponent;
  if ( this->m_ScriptArgument[0].m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = p_m_pTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  }
  p_m_pTransformNodeComponent->m_pPointer = transform_node_component;
  if ( transform_node_component )
  {
    v7 = transform_node_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v7;
    p_m_pTransformNodeComponent->mNext = &transform_node_component->m_SafePointerList.mNode;
    transform_node_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTransformNodeComponent;
  }
  this->m_ScriptArgument[0].m_Type = eSCRIPT_ARGUMENT_TRANSFORM_NODE;
  result = 1;
  this->m_NumScriptArguments = 1;
  return result;
}

// File Line: 389
// RVA: 0x33FF70
char __fastcall UFG::AIScriptInterfaceComponent::AddArgument(UFG::AIScriptInterfaceComponent *this, const char *string)
{
  __int64 m_NumScriptArguments; // rax
  char result; // al

  m_NumScriptArguments = this->m_NumScriptArguments;
  if ( (int)m_NumScriptArguments >= 5 )
    return 0;
  UFG::qSharedString::operator=(
    &this->m_ScriptArgument[0].m_String + 8 * m_NumScriptArguments + m_NumScriptArguments,
    string);
  result = 1;
  this->m_ScriptArgument[this->m_NumScriptArguments++].m_Type = eSCRIPT_ARGUMENT_STRING;
  return result;
}

// File Line: 404
// RVA: 0x33FF30
bool __fastcall UFG::AIScriptInterfaceComponent::AddArgument(UFG::AIScriptInterfaceComponent *this, int integer)
{
  __int64 m_NumScriptArguments; // rax
  bool result; // al

  m_NumScriptArguments = this->m_NumScriptArguments;
  if ( (int)m_NumScriptArguments >= 5 )
    return 0;
  this->m_ScriptArgument[m_NumScriptArguments].m_Int = integer;
  result = 1;
  this->m_ScriptArgument[this->m_NumScriptArguments++].m_Type = eSCRIPT_ARGUMENT_INT;
  return result;
}

// File Line: 419
// RVA: 0x33FFD0
bool __fastcall UFG::AIScriptInterfaceComponent::AddArgument(
        UFG::AIScriptInterfaceComponent *this,
        unsigned int *symbol)
{
  __int64 m_NumScriptArguments; // rax
  bool result; // al

  m_NumScriptArguments = this->m_NumScriptArguments;
  if ( (int)m_NumScriptArguments >= 5 )
    return 0;
  this->m_ScriptArgument[m_NumScriptArguments].m_Symbol.mUID = *symbol;
  result = 1;
  this->m_ScriptArgument[this->m_NumScriptArguments++].m_Type = eSCRIPT_ARGUMENT_SYMBOL;
  return result;
}

// File Line: 464
// RVA: 0x386060
void __fastcall UFG::AIScriptInterfaceComponent::SetDesiredTarget(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eTargetTypeEnum target_type,
        UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *prop_target)
{
  UFG::AIEntityComponent *m_pSimComponent; // r9
  bool v4; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  m_pSimComponent = (UFG::AIEntityComponent *)this->m_pAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v4 = *((_QWORD *)&m_pSimComponent[1].m_WanderData.mGoals[0].mpDestinationNode.mData + 3 * target_type + 2) == 0i64;
    v5 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(&m_pSimComponent[1].m_WanderData.mGoals[0].mpDestinationNode.mData
                                                                                       + 3 * target_type);
    if ( !v4 )
    {
      mPrev = v5->mPrev;
      mNext = v5->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v5->mPrev = v5;
      v5->mNext = v5;
    }
    v5[1].mPrev = prop_target;
    if ( prop_target )
    {
      v8 = prop_target->mNext;
      v8->mNext = v5;
      v5->mPrev = v8;
      v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&prop_target->mNext;
      prop_target->mNext = v5;
    }
  }
}

// File Line: 532
// RVA: 0x385050
void __fastcall UFG::AIScriptInterfaceComponent::SetCollisionAvoidanceOverride(
        UFG::AIScriptInterfaceComponent *this,
        __int64 overRideType)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  unsigned int v3; // ebx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  UFG::NavComponent *ComponentOfTypeHK; // rax
  bool v7; // zf
  UFG::NavComponent *ComponentOfType; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v3 = overRideType;
  if ( !m_pSimObject )
  {
    UFG::NavComponent::SetCollisionAvoidanceType(0i64, overRideType);
    return;
  }
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    UFG::NavComponent::SetCollisionAvoidanceType((UFG::NavComponent *)m_pSimObject->m_Components.p[36].m_pComponent, v3);
    return;
  }
  if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::NavComponent::_TypeUID;
LABEL_7:
    ComponentOfTypeHK = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, v5);
    UFG::NavComponent::SetCollisionAvoidanceType(ComponentOfTypeHK, v3);
    return;
  }
  v7 = (m_Flags & 0x1000) == 0;
  v5 = UFG::NavComponent::_TypeUID;
  if ( !v7 )
    goto LABEL_7;
  ComponentOfType = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
  UFG::NavComponent::SetCollisionAvoidanceType(ComponentOfType, v3);
}

// File Line: 541
// RVA: 0x34F100
void __fastcall UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride(UFG::AIScriptInterfaceComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::NavComponent *m_pComponent; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pSimObject->m_Components.p[36].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            m_pSimObject,
                                            UFG::NavComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::NavComponent::SetCollisionAvoidanceType(m_pComponent, 0i64);
  }
}

// File Line: 550
// RVA: 0x37F670
void __fastcall UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet(UFG::AIScriptInterfaceComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // r15
  UFG::qPropertySet *v5; // rax
  object_physical_character_stats_BaseAttackParameters *MemImagePtr; // rax
  __int64 v7; // rbp
  __int64 i; // r11
  float (*m_InitialAttackTimeMax)[3][2][2][2]; // r9
  __int64 v10; // rbx
  __int64 v11; // r10
  float (*v12)[3][2][2][2]; // rcx
  _DWORD *v13; // rdx
  __int64 v14; // r8
  float (*v15)[2][2][2]; // rcx
  __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // rdx
  bool *v19; // rax
  char *v20; // rcx
  char v21; // [rsp+50h] [rbp+8h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || !m_pSimObject->m_pSceneObj )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      return;
    goto LABEL_7;
  }
  m_pSceneObj = m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&object_physical_character_stats_BaseAttackParameters::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = (object_physical_character_stats_BaseAttackParameters *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
    {
      this->m_InitialAttackTimeMin[0][0][0][0][0] = MemImagePtr->InitialAttackTimeMinMeleeVSHumanAsEnemy;
      this->m_InitialAttackTimeMax[0][0][0][0][0] = MemImagePtr->InitialAttackTimeMaxMeleeVSHumanAsEnemy;
      this->m_AttackTimeMin[0][0][0][0][0] = MemImagePtr->AttackTimeMinMeleeVSHumanAsEnemy;
      this->m_AttackTimeMax[0][0][0][0][0] = MemImagePtr->AttackTimeMaxMeleeVSHumanAsEnemy;
      this->m_AttackTimeMinDowned[0][0][0][0][0] = MemImagePtr->AttackTimeMinMeleeDownedVSHumanAsEnemy;
      this->m_AttackTimeMaxDowned[0][0][0][0][0] = MemImagePtr->AttackTimeMaxMeleeDownedVSHumanAsEnemy;
      this->m_InitialAttackTimeMin[0][0][0][1][0] = MemImagePtr->InitialAttackTimeMinMeleeVSAIAsEnemy;
      this->m_InitialAttackTimeMax[0][0][0][1][0] = MemImagePtr->InitialAttackTimeMaxMeleeVSAIAsEnemy;
      this->m_AttackTimeMin[0][0][0][1][0] = MemImagePtr->AttackTimeMinMeleeVSAIAsEnemy;
      this->m_AttackTimeMax[0][0][0][1][0] = MemImagePtr->AttackTimeMaxMeleeVSAIAsEnemy;
      this->m_AttackTimeMinDowned[0][0][0][1][0] = MemImagePtr->AttackTimeMinMeleeDownedVSAIAsEnemy;
      this->m_AttackTimeMaxDowned[0][0][0][1][0] = MemImagePtr->AttackTimeMaxMeleeDownedVSAIAsEnemy;
      this->m_InitialAttackTimeMin[0][0][1][1][0] = MemImagePtr->InitialAttackTimeMinMeleeVSAIAsAlly;
      this->m_InitialAttackTimeMax[0][0][1][1][0] = MemImagePtr->InitialAttackTimeMaxMeleeVSAIAsAlly;
      this->m_AttackTimeMin[0][0][1][1][0] = MemImagePtr->AttackTimeMinMeleeVSAIAsAlly;
      this->m_AttackTimeMax[0][0][1][1][0] = MemImagePtr->AttackTimeMaxMeleeVSAIAsAlly;
      this->m_AttackTimeMinDowned[0][0][1][1][0] = MemImagePtr->AttackTimeMinMeleeDownedVSAIAsAlly;
      this->m_AttackTimeMaxDowned[0][0][1][1][0] = MemImagePtr->AttackTimeMaxMeleeDownedVSAIAsAlly;
      this->m_InitialAttackTimeMin[0][1][0][0][0] = MemImagePtr->InitialAttackTimeMinRangedVSHumanAsEnemy;
      this->m_InitialAttackTimeMax[0][1][0][0][0] = MemImagePtr->InitialAttackTimeMaxRangedVSHumanAsEnemy;
      this->m_AttackTimeMin[0][1][0][0][0] = MemImagePtr->AttackTimeMinRangedVSHumanAsEnemy;
      this->m_AttackTimeMax[0][1][0][0][0] = MemImagePtr->AttackTimeMaxRangedVSHumanAsEnemy;
      this->m_AttackTimeMinDowned[0][1][0][0][0] = MemImagePtr->AttackTimeMinRangedDownedVSHumanAsEnemy;
      this->m_AttackTimeMaxDowned[0][1][0][0][0] = MemImagePtr->AttackTimeMaxRangedDownedVSHumanAsEnemy;
      this->m_InitialAttackTimeMin[0][1][0][1][0] = MemImagePtr->InitialAttackTimeMinRangedVSAIAsEnemy;
      this->m_InitialAttackTimeMax[0][1][0][1][0] = MemImagePtr->InitialAttackTimeMaxRangedVSAIAsEnemy;
      this->m_AttackTimeMin[0][1][0][1][0] = MemImagePtr->AttackTimeMinRangedVSAIAsEnemy;
      this->m_AttackTimeMax[0][1][0][1][0] = MemImagePtr->AttackTimeMaxRangedVSAIAsEnemy;
      this->m_AttackTimeMinDowned[0][1][0][1][0] = MemImagePtr->AttackTimeMinRangedDownedVSAIAsEnemy;
      this->m_AttackTimeMaxDowned[0][1][0][1][0] = MemImagePtr->AttackTimeMaxRangedDownedVSAIAsEnemy;
      this->m_InitialAttackTimeMin[0][2][0][0][0] = MemImagePtr->InitialAttackTimeMinDirectFollowersVSHumanAsEnemy;
      this->m_InitialAttackTimeMax[0][2][0][0][0] = MemImagePtr->InitialAttackTimeMaxDirectFollowersVSHumanAsEnemy;
      this->m_AttackTimeMin[0][2][0][0][0] = MemImagePtr->AttackTimeMinDirectFollowersVSHumanAsEnemy;
      this->m_AttackTimeMax[0][2][0][0][0] = MemImagePtr->AttackTimeMaxDirectFollowersVSHumanAsEnemy;
      this->m_AttackTimeMinDowned[0][2][0][0][0] = MemImagePtr->AttackTimeMinDirectFollowersDownedVSHumanAsEnemy;
      this->m_AttackTimeMaxDowned[0][2][0][0][0] = MemImagePtr->AttackTimeMaxDirectFollowersDownedVSHumanAsEnemy;
      this->m_InitialAttackTimeMin[0][2][0][1][0] = MemImagePtr->InitialAttackTimeMinDirectFollowersVSAIAsEnemy;
      this->m_InitialAttackTimeMax[0][2][0][1][0] = MemImagePtr->InitialAttackTimeMaxDirectFollowersVSAIAsEnemy;
      this->m_AttackTimeMin[0][2][0][1][0] = MemImagePtr->AttackTimeMinDirectFollowersVSAIAsEnemy;
      this->m_AttackTimeMax[0][2][0][1][0] = MemImagePtr->AttackTimeMaxDirectFollowersVSAIAsEnemy;
      this->m_AttackTimeMinDowned[0][2][0][1][0] = MemImagePtr->AttackTimeMinDirectFollowersDownedVSAIAsEnemy;
      this->m_AttackTimeMaxDowned[0][2][0][1][0] = MemImagePtr->AttackTimeMaxDirectFollowersDownedVSAIAsEnemy;
      this->m_InitialAttackTimeMin[0][1][1][1][0] = MemImagePtr->InitialAttackTimeMinRangedVSAIAsAlly;
      this->m_InitialAttackTimeMax[0][1][1][1][0] = MemImagePtr->InitialAttackTimeMaxRangedVSAIAsAlly;
      this->m_AttackTimeMin[0][1][1][1][0] = MemImagePtr->AttackTimeMinRangedVSAIAsAlly;
      this->m_AttackTimeMax[0][1][1][1][0] = MemImagePtr->AttackTimeMaxRangedVSAIAsAlly;
      this->m_AttackTimeMinDowned[0][1][1][1][0] = MemImagePtr->AttackTimeMinRangedDownedVSAIAsAlly;
      this->m_AttackTimeMaxDowned[0][1][1][1][0] = MemImagePtr->AttackTimeMaxRangedDownedVSAIAsAlly;
      this->m_InitialAttackTimeMin[0][2][1][1][0] = MemImagePtr->InitialAttackTimeMinDirectFollowersVSAIAsAlly;
      this->m_InitialAttackTimeMax[0][2][1][1][0] = MemImagePtr->InitialAttackTimeMaxDirectFollowersVSAIAsAlly;
      this->m_AttackTimeMin[0][2][1][1][0] = MemImagePtr->AttackTimeMinDirectFollowersVSAIAsAlly;
      this->m_AttackTimeMax[0][2][1][1][0] = MemImagePtr->AttackTimeMaxDirectFollowersVSAIAsAlly;
      this->m_AttackTimeMinDowned[0][2][1][1][0] = MemImagePtr->AttackTimeMinDirectFollowersDownedVSAIAsAlly;
      this->m_AttackTimeMaxDowned[0][2][1][1][0] = MemImagePtr->AttackTimeMaxDirectFollowersDownedVSAIAsAlly;
      v7 = 3i64;
      for ( i = 1i64; i < 49; i += 24i64 )
      {
        m_InitialAttackTimeMax = this->m_InitialAttackTimeMax;
        v10 = 3i64;
        do
        {
          v11 = 2i64;
          do
          {
            v12 = m_InitialAttackTimeMax;
            v13 = (_DWORD *)&(*m_InitialAttackTimeMax)[0][0][0][i];
            v14 = 2i64;
            do
            {
              *(v13 - 48) = LODWORD((*v12)[-6][0][0][0]);
              *v13 = *(_DWORD *)v12;
              v13[48] = LODWORD((*v12)[6][0][0][0]);
              v13[96] = LODWORD((*v12)[12][0][0][0]);
              v13[144] = LODWORD((*v12)[18][0][0][0]);
              v13[192] = LODWORD((*v12)[24][0][0][0]);
              v12 = (float (*)[3][2][2][2])((char *)v12 + 8);
              v13 += 2;
              --v14;
            }
            while ( v14 );
            m_InitialAttackTimeMax = (float (*)[3][2][2][2])((char *)m_InitialAttackTimeMax + 16);
            --v11;
          }
          while ( v11 );
          --v10;
        }
        while ( v10 );
      }
      this->m_InitialAttackTimeMin[0][1][0][0][1] = MemImagePtr->InitialAttackTimeMinRangedInCoverVSHumanAsEnemy;
      this->m_InitialAttackTimeMax[0][1][0][0][1] = MemImagePtr->InitialAttackTimeMaxRangedInCoverVSHumanAsEnemy;
      this->m_AttackTimeMin[0][1][0][0][1] = MemImagePtr->AttackTimeMinRangedInCoverVSHumanAsEnemy;
      this->m_AttackTimeMax[0][1][0][0][1] = MemImagePtr->AttackTimeMaxRangedInCoverVSHumanAsEnemy;
      this->m_AttackTimeMinDowned[0][1][0][0][1] = MemImagePtr->AttackTimeMinRangedInCoverDownedVSHumanAsEnemy;
      this->m_AttackTimeMaxDowned[0][1][0][0][1] = MemImagePtr->AttackTimeMaxRangedInCoverDownedVSHumanAsEnemy;
      this->m_InitialAttackTimeMin[0][1][0][1][1] = MemImagePtr->InitialAttackTimeMinRangedInCoverVSAIAsEnemy;
      this->m_InitialAttackTimeMax[0][1][0][1][1] = MemImagePtr->InitialAttackTimeMaxRangedInCoverVSAIAsEnemy;
      this->m_AttackTimeMin[0][1][0][1][1] = MemImagePtr->AttackTimeMinRangedInCoverVSAIAsEnemy;
      this->m_AttackTimeMax[0][1][0][1][1] = MemImagePtr->AttackTimeMaxRangedInCoverVSAIAsEnemy;
      this->m_AttackTimeMinDowned[0][1][0][1][1] = MemImagePtr->AttackTimeMinRangedInCoverDownedVSAIAsEnemy;
      this->m_AttackTimeMaxDowned[0][1][0][1][1] = MemImagePtr->AttackTimeMaxRangedInCoverDownedVSAIAsEnemy;
      this->m_InitialAttackTimeMin[0][1][0][1][1] = MemImagePtr->InitialAttackTimeMinRangedInCoverVSAIAsAlly;
      this->m_InitialAttackTimeMax[0][1][0][1][1] = MemImagePtr->InitialAttackTimeMaxRangedInCoverVSAIAsAlly;
      this->m_AttackTimeMin[0][1][0][1][1] = MemImagePtr->AttackTimeMinRangedInCoverVSAIAsAlly;
      this->m_AttackTimeMax[0][1][0][1][1] = MemImagePtr->AttackTimeMaxRangedInCoverVSAIAsAlly;
      this->m_AttackTimeMinDowned[0][1][0][1][1] = MemImagePtr->AttackTimeMinRangedInCoverDownedVSAIAsAlly;
      this->m_AttackTimeMaxDowned[0][1][0][1][1] = MemImagePtr->AttackTimeMaxRangedInCoverDownedVSAIAsAlly;
      v15 = this->m_InitialAttackTimeMin[1];
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
      this->m_AttackTimeMin[1][0][0][0][0] = MemImagePtr->AttackTimeMinMeleeVSHumanAsEnemyMobBattle;
      this->m_AttackTimeMin[1][0][0][0][1] = MemImagePtr->AttackTimeMinMeleeVSHumanAsEnemyMobBattle;
      this->m_AttackTimeMax[1][0][0][0][0] = MemImagePtr->AttackTimeMaxMeleeVSHumanAsEnemyMobBattle;
      this->m_AttackTimeMax[1][0][0][0][1] = MemImagePtr->AttackTimeMaxMeleeVSHumanAsEnemyMobBattle;
      if ( (_S27_0 & 1) == 0 )
      {
        _S27_0 |= 1u;
        UFG::qSymbol::create_from_string(&AllowedToSprintDuringCombatSymbol, "AllowedToSprintDuringCombat");
        atexit(UFG::AIScriptInterfaceComponent::ReadParametersFromPropertySet_::_28_::_dynamic_atexit_destructor_for__AllowedToSprintDuringCombatSymbol__);
      }
      v21 = 0;
      v19 = UFG::qPropertySet::Get<bool>(
              mpWritableProperties,
              (UFG::qArray<unsigned long,0> *)&AllowedToSprintDuringCombatSymbol,
              DEPTH_RECURSE);
      v20 = &v21;
      if ( v19 )
        v20 = (char *)v19;
      *((_BYTE *)this + 2097) ^= (*((_BYTE *)this + 2097) ^ (*v20 << 6)) & 0x40;
    }
  }
}

// File Line: 864
// RVA: 0x360770
float __fastcall UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMin(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::TargetingSystemBaseComponent *v13; // rdx
  UFG::SimObjectCharacter *m_pPointer; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = (UFG::TargetingSystemBaseComponent *)this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13 && v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer )
  {
    m_pPointer = (UFG::SimObjectCharacter *)v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer;
    v4 = !m_pPointer || m_pPointer != LocalPlayer;
  }
  return this->m_InitialAttackTimeMin[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 873
// RVA: 0x360670
float __fastcall UFG::AIScriptInterfaceComponent::GetInitialAttackTimeMax(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return this->m_InitialAttackTimeMax[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 882
// RVA: 0x35A140
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMin(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return this->m_AttackTimeMin[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 891
// RVA: 0x359F40
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMax(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return this->m_AttackTimeMax[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 900
// RVA: 0x35A240
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMinDowned(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return this->m_AttackTimeMinDowned[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 909
// RVA: 0x35A040
float __fastcall UFG::AIScriptInterfaceComponent::GetAttackTimeMaxDowned(
        UFG::AIScriptInterfaceComponent *this,
        UFG::eAttackType attack_type,
        unsigned int target_type,
        UFG::eInCoverType in_cover_type)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 m_CurrentBattleType; // r12
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v8; // rbp
  __int64 v9; // r15
  int v11; // r10d
  __int64 mPrev_low; // rbx
  UFG::SimComponent *v13; // rdx
  UFG::SimObjectCharacter *v14; // rdx

  v4 = -1;
  v5 = in_cover_type;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v8 = target_type;
  v9 = attack_type;
  v11 = -1;
  if ( m_pSimComponent )
  {
    mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
    v11 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] == FACTIONSTANDING_ALLIED;
  }
  v13 = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v13
    && *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8) + *(_QWORD *)&v13[1].m_TypeUID + 40) )
  {
    v14 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + v8 + 8)
                                      + *(_QWORD *)&v13[1].m_TypeUID
                                      + 40);
    v4 = !v14 || v14 != LocalPlayer;
  }
  return this->m_AttackTimeMaxDowned[m_CurrentBattleType][v9][v11][v4][v5];
}

// File Line: 918
// RVA: 0x34F6B0
void __fastcall UFG::AIScriptInterfaceComponent::ClearPositionToDefend(UFG::AIScriptInterfaceComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  unsigned __int8 v2; // cl
  __int64 v3; // rbx

  m_pSimComponent = this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  *((_BYTE *)this + 2096) &= ~0x40u;
  if ( m_pSimComponent )
  {
    v2 = *(_BYTE *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + 40i64);
    if ( v2 )
    {
      v3 = 56i64 * v2;
      UFG::TargetingSimObject::SetTarget(
        (UFG::TargetingSimObject *)(v3 + *(_QWORD *)&m_pSimComponent[1].m_TypeUID),
        0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v3 + *(_QWORD *)&m_pSimComponent[1].m_TypeUID), 0);
    }
  }
}

// File Line: 929
// RVA: 0x387A40
void __fastcall UFG::AIScriptInterfaceComponent::SetPositionToDefend(
        UFG::AIScriptInterfaceComponent *this,
        UFG::SimObject *marker_to_defend,
        float radius,
        bool crouch,
        bool abandon_when_compromised,
        bool abandon_when_no_gun)
{
  UFG::TargetingSystemBaseComponent *m_pSimComponent; // rcx
  char v9; // al

  m_pSimComponent = (UFG::TargetingSystemBaseComponent *)this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::TargetingSystemBaseComponent::SetTarget(m_pSimComponent, eTARGET_TYPE_SCRIPTED_MARKER, marker_to_defend);
  v9 = *((_BYTE *)this + 2096);
  *((_BYTE *)this + 2097) &= 0xFCu;
  this->m_RadiusToDefend = radius;
  *((_BYTE *)this + 2096) = (crouch << 7) | v9 & 0x3F | 0x40;
  *((_BYTE *)this + 2097) |= abandon_when_compromised | (unsigned __int8)(2 * abandon_when_no_gun);
}

// File Line: 943
// RVA: 0x362270
UFG::qVector3 *__fastcall UFG::AIScriptInterfaceComponent::GetPositionToDefend(UFG::AIScriptInterfaceComponent *this)
{
  UFG::TransformNodeComponent *mNext; // rbx

  mNext = *(UFG::TransformNodeComponent **)(56i64
                                          * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                               + 40i64)
                                          + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                          + 40);
  if ( mNext )
    mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
  if ( !mNext )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  return (UFG::qVector3 *)&mNext->mWorldTransform.v3;
}

// File Line: 958
// RVA: 0x340760
void __fastcall UFG::AIScriptInterfaceComponent::AddFollower(
        UFG::AIScriptInterfaceComponent *this,
        UFG::ActiveAIEntityComponent *follower)
{
  int v2; // r9d
  UFG::SimComponent **p_m_pPointer; // rax
  __int64 v5; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = 0;
  p_m_pPointer = &this->m_pFollower[0].m_pPointer;
  v5 = 0i64;
  while ( *p_m_pPointer )
  {
    ++v5;
    ++v2;
    p_m_pPointer += 3;
    if ( v5 >= 10 )
      return;
  }
  v6 = &this->m_pFollower[v2];
  if ( this->m_pFollower[v2].m_pPointer )
  {
    mPrev = v6->mPrev;
    mNext = v6->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v6->mPrev = v6;
    v6->mNext = v6;
  }
  v6->m_pPointer = follower;
  if ( follower )
  {
    v9 = follower->m_SafePointerList.mNode.UFG::AIEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v9->mNext = v6;
    v6->mPrev = v9;
    v6->mNext = &follower->m_SafePointerList.mNode;
    follower->m_SafePointerList.mNode.UFG::AIEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v6;
  }
}

// File Line: 973
// RVA: 0x3539F0
void __fastcall UFG::AIScriptInterfaceComponent::DrawDebugInfo(
        UFG::AIScriptInterfaceComponent *this,
        Render::View *view)
{
  UFG::SimObject *m_pSimObject; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  UFG::SimComponent **p_m_pPointer; // rbx
  __int64 v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::TransformNodeComponent *v9; // rdi
  UFG::qColour v10; // xmm6
  UFG::TransformNodeComponent *v11; // rdx
  float y; // xmm1_4
  float z; // xmm0_4
  Render::DebugDrawContext *Context; // rax
  const char *v15; // rbx
  Render::DebugDrawContext *v16; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-68h] BYREF
  UFG::qColour v18; // [rsp+40h] [rbp-58h] BYREF
  UFG::qColour colour; // [rsp+50h] [rbp-48h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( this->m_DebugDrawFollowers && m_pTransformNodeComponent )
  {
    p_m_pPointer = &this->m_pFollower[0].m_pPointer;
    v6 = 10i64;
    do
    {
      v7 = *p_m_pPointer;
      if ( *p_m_pPointer )
      {
        v8 = v7[6].m_pSimObject;
        v9 = *(UFG::TransformNodeComponent **)&v7[1].m_TypeUID;
        if ( v8 )
        {
          if ( v9 )
          {
            v10 = UFG::qColour::Green;
            if ( BYTE4(v8->m_UnboundComponentHandles.mNode.mPrev) )
              v10 = UFG::qColour::Red;
            v11 = *(UFG::TransformNodeComponent **)&v7[1].m_TypeUID;
            v18 = v10;
            UFG::DrawLine(m_pTransformNodeComponent, v11, &v18, 0.5);
            colour = v10;
            UFG::TransformNodeComponent::UpdateWorldTransform(v9);
            y = v9->mWorldTransform.v3.y;
            point.x = v9->mWorldTransform.v3.x;
            z = v9->mWorldTransform.v3.z;
            point.y = y;
            point.z = z + 0.5;
            Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    1u);
            Render::DebugDrawContext::DrawPoint(Context, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
          }
        }
      }
      p_m_pPointer += 3;
      --v6;
    }
    while ( v6 );
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v15 = UFG::ScriptCommandNames[this->m_CurrentScriptCommand];
    v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawText(
      v16,
      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
      &UFG::qColour::Red,
      v15);
  }
}

