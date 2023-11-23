// File Line: 45
// RVA: 0x157B8B0
__int64 dynamic_initializer_for__UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList__);
}

// File Line: 46
// RVA: 0x67A3F0
UFG::ComponentIDDesc *__fastcall UFG::VehicleDriverInterface::GetDesc(UFG::VehicleDriverInterface *this)
{
  return &UFG::VehicleDriverInterface::_TypeIDesc;
}

// File Line: 61
// RVA: 0x66ABE0
void __fastcall UFG::VehicleDriverInterface::VehicleDriverInterface(
        UFG::VehicleDriverInterface *this,
        unsigned int name_uid)
{
  UFG::TransformNodeComponent *v3; // rsi
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *mPrev; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::TransformNodeComponent *v7; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  this->mNext = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleDriverInterface::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleDriverInterface::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&this->mMoverComponent);
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>(&this->mRenderComponent);
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::RebindingComponentHandle<UFG::VehicleAudioComponent,0>(&this->mAudioComponent);
  this->mDriver.mPrev = &this->mDriver;
  this->mDriver.mNext = &this->mDriver;
  v3 = 0i64;
  this->mDriver.m_pPointer = 0i64;
  this->mState = UNINITIALIZED;
  *(_QWORD *)&this->mDesiredState = 1i64;
  this->mPropertySet = 0i64;
  this->mForceDock = 0;
  this->mBreakOnUpdate = 0;
  mPrev = UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev;
  UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList;
  UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  UFG::SimComponent::AddType(
    this,
    UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID,
    "VehicleDriverInterface");
  if ( (_S25_3 & 1) == 0 )
  {
    _S25_3 |= 1u;
    uidChaseSpawnTransform = UFG::qStringHash32("ChaseSpawnTransform", 0xFFFFFFFF);
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v6 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v6,
      uidChaseSpawnTransform,
      0i64,
      0);
    v3 = v7;
  }
  this->m_ChaseSpawnTransform = v3;
}

// File Line: 73
// RVA: 0x66D340
void __fastcall UFG::VehicleDriverInterface::~VehicleDriverInterface(UFG::VehicleDriverInterface *this)
{
  UFG::TransformNodeComponent *m_ChaseSpawnTransform; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v3; // rdi
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *mPrev; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v11; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v12; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleDriverInterface::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleDriverInterface::`vftable{for `UFG::UpdateInterface};
  m_ChaseSpawnTransform = this->m_ChaseSpawnTransform;
  if ( m_ChaseSpawnTransform )
    m_ChaseSpawnTransform->vfptr->__vecDelDtor(m_ChaseSpawnTransform, 1u);
  if ( this == UFG::VehicleDriverInterface::s_VehicleDriverInterfacepCurrentIterator )
    UFG::VehicleDriverInterface::s_VehicleDriverInterfacepCurrentIterator = (UFG::VehicleDriverInterface *)&this->mPrev[-5].mNext;
  v3 = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  this->mNext = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  p_mDriver = &this->mDriver;
  if ( this->mDriver.m_pPointer )
  {
    v7 = p_mDriver->mPrev;
    v8 = this->mDriver.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mDriver->mPrev = p_mDriver;
    this->mDriver.mNext = &this->mDriver;
  }
  this->mDriver.m_pPointer = 0i64;
  v9 = p_mDriver->mPrev;
  v10 = this->mDriver.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mDriver->mPrev = p_mDriver;
  this->mDriver.mNext = &this->mDriver;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAudioComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mRenderComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mMoverComponent);
  v11 = v3->mPrev;
  v12 = this->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v3->mPrev = v3;
  this->mNext = &this->UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 82
// RVA: 0x6836A0
void __fastcall UFG::VehicleDriverInterface::OnAttach(UFG::VehicleDriverInterface *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *p_mMoverComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *p_mRenderComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *p_mAudioComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::SimComponent *m_pSimComponent; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v20; // [rsp+30h] [rbp-18h] BYREF

  p_mMoverComponent = &this->mMoverComponent;
  if ( p_mMoverComponent->m_pSimComponent )
  {
    mPrev = p_mMoverComponent->mPrev;
    mNext = p_mMoverComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mMoverComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mMoverComponent->m_pSimObject = 0i64;
    p_mMoverComponent->mNext = p_mMoverComponent;
    p_mMoverComponent->mPrev = p_mMoverComponent;
    goto LABEL_8;
  }
  if ( p_mMoverComponent->m_pSimObject
    && (p_mMoverComponent->mPrev != p_mMoverComponent || p_mMoverComponent->mNext != p_mMoverComponent) )
  {
    v7 = p_mMoverComponent->mPrev;
    v8 = p_mMoverComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mMoverComponent->m_Changed = 1;
  p_mMoverComponent->m_pSimObject = object;
  p_mMoverComponent->m_TypeUID = UFG::PhysicsMoverInterface::_TypeUID;
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::BindInternal<UFG::SimObject>(p_mMoverComponent, object);
  p_mRenderComponent = &this->mRenderComponent;
  if ( this->mRenderComponent.m_pSimComponent )
  {
    v10 = p_mRenderComponent->mPrev;
    v11 = this->mRenderComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mRenderComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mRenderComponent.m_pSimObject = 0i64;
    this->mRenderComponent.mNext = &this->mRenderComponent;
    p_mRenderComponent->mPrev = p_mRenderComponent;
    goto LABEL_15;
  }
  if ( this->mRenderComponent.m_pSimObject
    && (p_mRenderComponent->mPrev != p_mRenderComponent || this->mRenderComponent.mNext != &this->mRenderComponent) )
  {
    v12 = p_mRenderComponent->mPrev;
    v13 = this->mRenderComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mRenderComponent.m_Changed = 1;
  this->mRenderComponent.m_pSimObject = object;
  this->mRenderComponent.m_TypeUID = UFG::VehicleEffectsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(
    &this->mRenderComponent,
    object);
  p_mAudioComponent = &this->mAudioComponent;
  if ( this->mAudioComponent.m_pSimComponent )
  {
    v15 = p_mAudioComponent->mPrev;
    v16 = this->mAudioComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->mAudioComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mAudioComponent.m_pSimObject = 0i64;
    this->mAudioComponent.mNext = &this->mAudioComponent;
    p_mAudioComponent->mPrev = p_mAudioComponent;
    goto LABEL_22;
  }
  if ( this->mAudioComponent.m_pSimObject
    && (p_mAudioComponent->mPrev != p_mAudioComponent || this->mAudioComponent.mNext != &this->mAudioComponent) )
  {
    v17 = p_mAudioComponent->mPrev;
    v18 = this->mAudioComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->mAudioComponent.m_Changed = 1;
  this->mAudioComponent.m_pSimObject = object;
  this->mAudioComponent.m_TypeUID = UFG::VehicleAudioComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::BindInternal<UFG::SimObject>(
    &this->mAudioComponent,
    object);
  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    LODWORD(m_pSimComponent[1].m_pSimObject) &= 0xFFFFF9C0;
    *(_QWORD *)&m_pSimComponent[1].m_TypeUID = 0i64;
    *(_QWORD *)&m_pSimComponent[1].m_Flags = 0i64;
  }
  v20.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v20.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v20,
    UFG::gEventMountVehicle.mUID,
    UFG::gEventMountVehicle.mName,
    0);
  v20.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v20.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v20,
    UFG::gEventDisMountVehicle.mUID,
    UFG::gEventDisMountVehicle.mName,
    0);
}

// File Line: 99
// RVA: 0x684290
void __fastcall UFG::VehicleDriverInterface::OnDetach(UFG::VehicleDriverInterface *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimComponent *v3; // rax
  float v4; // xmm0_4
  UFG::VehicleState v5; // eax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *p_mMoverComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *p_mRenderComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *p_mAudioComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v21; // [rsp+20h] [rbp-18h] BYREF

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    LODWORD(m_pSimComponent[1].m_pSimObject) &= 0xFFFFF9C0;
    *(_QWORD *)&m_pSimComponent[1].m_TypeUID = 0i64;
    *(_QWORD *)&m_pSimComponent[1].m_Flags = 0i64;
  }
  v21.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::VehicleDriverInterface::EventHandler;
  v21.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v21, UFG::gEventMountVehicle.mUID);
  v21.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v21.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v21, UFG::gEventDisMountVehicle.mUID);
  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 && ((__int64)v3[14].vfptr & 1) == 0 )
  {
    v4 = *((float *)&v3[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v5 = 1;
    if ( (float)(v4 * 3.5999999) > 30.0 )
      v5 = 5;
    this->mDesiredState = v5;
    UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)&this->UFG::UpdateInterface, 0.0);
  }
  p_mMoverComponent = &this->mMoverComponent;
  if ( this->mMoverComponent.m_pSimComponent )
  {
    mPrev = p_mMoverComponent->mPrev;
    mNext = this->mMoverComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mMoverComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mMoverComponent.m_pSimObject = 0i64;
    this->mMoverComponent.mNext = &this->mMoverComponent;
    p_mMoverComponent->mPrev = p_mMoverComponent;
    goto LABEL_15;
  }
  if ( this->mMoverComponent.m_pSimObject
    && (p_mMoverComponent->mPrev != p_mMoverComponent || this->mMoverComponent.mNext != &this->mMoverComponent) )
  {
    v9 = p_mMoverComponent->mPrev;
    v10 = this->mMoverComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    goto LABEL_14;
  }
LABEL_15:
  this->mMoverComponent.m_Changed = 1;
  p_mRenderComponent = &this->mRenderComponent;
  if ( this->mRenderComponent.m_pSimComponent )
  {
    v12 = p_mRenderComponent->mPrev;
    v13 = this->mRenderComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    this->mRenderComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mRenderComponent.m_pSimObject = 0i64;
    this->mRenderComponent.mNext = &this->mRenderComponent;
    p_mRenderComponent->mPrev = p_mRenderComponent;
    goto LABEL_22;
  }
  if ( this->mRenderComponent.m_pSimObject
    && (p_mRenderComponent->mPrev != p_mRenderComponent || this->mRenderComponent.mNext != &this->mRenderComponent) )
  {
    v14 = p_mRenderComponent->mPrev;
    v15 = this->mRenderComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    goto LABEL_21;
  }
LABEL_22:
  this->mRenderComponent.m_Changed = 1;
  p_mAudioComponent = &this->mAudioComponent;
  if ( this->mAudioComponent.m_pSimComponent )
  {
    v17 = p_mAudioComponent->mPrev;
    v18 = this->mAudioComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    this->mAudioComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->mAudioComponent.m_pSimObject = 0i64;
    this->mAudioComponent.mNext = &this->mAudioComponent;
    p_mAudioComponent->mPrev = p_mAudioComponent;
    goto LABEL_29;
  }
  if ( this->mAudioComponent.m_pSimObject
    && (p_mAudioComponent->mPrev != p_mAudioComponent || this->mAudioComponent.mNext != &this->mAudioComponent) )
  {
    v19 = p_mAudioComponent->mPrev;
    v20 = this->mAudioComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    goto LABEL_28;
  }
LABEL_29:
  this->mAudioComponent.m_Changed = 1;
}

// File Line: 116
// RVA: 0x676B40
void __fastcall UFG::VehicleDriverInterface::DismountAndUpdate(UFG::VehicleDriverInterface *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  float v2; // xmm0_4
  int v3; // eax
  UFG::UpdateInterface *v4; // rcx

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent && ((__int64)m_pSimComponent[14].vfptr & 1) == 0 )
  {
    v2 = *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v3 = 1;
    if ( (float)(v2 * 3.5999999) > 30.0 )
      v3 = 5;
    v4 = &this->UFG::UpdateInterface;
    HIDWORD(v4[24].vfptr) = v3;
    UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)v4, 0.0);
  }
}

// File Line: 135
// RVA: 0x68A6A0
void __fastcall UFG::VehicleDriverInterface::SetDesiredState(
        UFG::VehicleDriverInterface *this,
        UFG::VehicleState state)
{
  this->mDesiredState = state;
}

// File Line: 142
// RVA: 0x678270
void __fastcall UFG::VehicleDriverInterface::EventHandler(UFG::VehicleDriverInterface *this, UFG::Event *evt)
{
  unsigned int m_EventUID; // eax

  m_EventUID = evt->m_EventUID;
  if ( UFG::gEventDisMountVehicle.mUID == m_EventUID )
  {
    if ( evt[1].mNext == (UFG::qNode<UFG::Event,UFG::Event> *)this->mDriver.m_pPointer )
      UFG::VehicleDriverInterface::DismountAndUpdate(this);
  }
  else if ( UFG::gEventMountVehicle.mUID == m_EventUID && this->mDriver.m_pPointer == (UFG::SimObject *)evt[1].mNext )
  {
    this->mDesiredState = 2;
  }
}

// File Line: 172
// RVA: 0x68A6B0
void __fastcall UFG::VehicleDriverInterface::SetDriver(UFG::VehicleDriverInterface *this, UFG::SimObject *driver)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mDriver; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mDriver = &this->mDriver;
  if ( this->mDriver.m_pPointer )
  {
    mPrev = p_mDriver->mPrev;
    mNext = p_mDriver->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mDriver->mPrev = p_mDriver;
    p_mDriver->mNext = p_mDriver;
  }
  p_mDriver->m_pPointer = driver;
  if ( driver )
  {
    v5 = driver->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mDriver;
    p_mDriver->mPrev = v5;
    p_mDriver->mNext = &driver->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    driver->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mDriver;
  }
}

// File Line: 183
// RVA: 0x694520
void __fastcall UFG::VehicleDriverInterface::Update(UFG::VehicleDriverInterface *this, float deltaTime)
{
  __int64 v2; // rax
  int mNext_high; // eax
  int mNext; // ecx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  UFG::SimObjectGame *v8; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // cx
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  v2 = *(_QWORD *)&this[-1].mForceDock;
  if ( !v2 || (*(_WORD *)(v2 + 0x4C) & 0x400) == 0 )
  {
    mNext_high = HIDWORD(this->mAudioComponent.mNext);
    mNext = (int)this->mAudioComponent.mNext;
    if ( mNext_high != mNext )
    {
      LODWORD(this->mAudioComponent.mNext) = mNext_high;
      if ( mNext == 4 )
      {
        v6 = this->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev[40].mNext;
        if ( v6 )
          UFG::PhysicsVehicle::RestoreSuperStopDrag((UFG::PhysicsVehicle *)v6);
      }
      switch ( LODWORD(this->mAudioComponent.mNext) )
      {
        case 1:
          UFG::VehicleDriverInterface::Parked(
            (UFG::VehicleDriverInterface *)((char *)this - 64),
            (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)(LODWORD(this->mAudioComponent.mNext) - 1));
          break;
        case 2:
          UFG::VehicleDriverInterface::Driving((UFG::VehicleDriverInterface *)((char *)this - 64));
          break;
        case 5:
          UFG::VehicleDriverInterface::Uncontrolled(
            (UFG::VehicleDriverInterface *)((char *)this - 64),
            (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)(LODWORD(this->mAudioComponent.mNext) - 3));
          break;
      }
    }
    mPrev = this->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev;
    v8 = *(UFG::SimObjectGame **)&this[-1].mForceDock;
    if ( v8 )
    {
      m_Flags = v8->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::StimulusEmitterComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::StimulusEmitterComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    if ( ((__int64)mPrev[6].mNext & 0x20) != 0 )
    {
      if ( !ComponentOfTypeHK )
      {
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_VEHICLE_BURNOUT,
          &stimulus_parameters,
          v8);
      }
    }
    else if ( ComponentOfTypeHK )
    {
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_VEHICLE_BURNOUT, v8);
    }
    LODWORD(mPrev[6].mNext) &= 0xFFFFF9C0;
    mPrev[5].mNext = 0i64;
    mPrev[6].mPrev = 0i64;
  }
}

// File Line: 272
// RVA: 0x677360
void __fastcall UFG::VehicleDriverInterface::Driving(UFG::VehicleDriverInterface *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::VehicleEffectsComponent *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    ((void (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[17].__vecDelDtor)(m_pSimComponent);
  v3 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
  if ( v3 )
    UFG::VehicleEffectsComponent::TurnOnExhaust(v3);
  v4 = (UFG::VehicleAudioComponent *)this->mAudioComponent.m_pSimComponent;
  if ( v4 && v4->m_bIsInitialized && v4->m_bVehicleIsInitialized && v4->m_eDriverType == eDriverType_Player )
    UFG::ConversationManager::ResumePlayerConversations(eInterruptType_GetOutOfVehicle);
}

// File Line: 300
// RVA: 0x68EC70
void __fastcall UFG::VehicleDriverInterface::Uncontrolled(
        UFG::VehicleDriverInterface *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimComponent *v4; // rbx
  int vfptr; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::VehicleEffectsComponent *v7; // rcx
  UFG::VehicleEffectsComponent *v8; // rbx
  UFG::VehicleAudioComponent *v9; // rcx

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    ((void (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    v4 = this->mMoverComponent.m_pSimComponent;
    vfptr = (int)v4[14].vfptr;
    if ( (vfptr & 1) == 0 && (vfptr & 8) == 0 )
    {
      UFG::OnlineManager::Instance();
      ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[9].__vecDelDtor)(v4);
      mPrev = v4[10].m_SafePointerList.mNode.mPrev;
      if ( mPrev )
        LODWORD(mPrev[34].mPrev) = 3;
      UFG::PhysicsMoverInterface::ActivateTargetSpheres((UFG::PhysicsMoverInterface *)v4);
      LODWORD(v4[13].vfptr) = 1092616192;
      HIDWORD(v4[12].m_BoundComponentHandles.mNode.mNext) = 1;
    }
  }
  v7 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
  if ( v7 )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(v7);
    UFG::VehicleEffectsComponent::TurnOffLightEffects(
      (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent,
      FX_BRAKELIGHTS);
    v8 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, 10);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, 11);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, 8);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, 9);
  }
  v9 = (UFG::VehicleAudioComponent *)this->mAudioComponent.m_pSimComponent;
  if ( v9 )
    UFG::VehicleAudioComponent::OnDriverComponentUncontrolled(v9, a2);
}

// File Line: 321
// RVA: 0x685E60
void __fastcall UFG::VehicleDriverInterface::Parked(
        UFG::VehicleDriverInterface *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleEffectsComponent *m_pSimComponent; // rcx
  UFG::VehicleEffectsComponent *v4; // rbx
  UFG::VehicleAudioComponent *v5; // rcx

  m_pSimComponent = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(m_pSimComponent);
    UFG::VehicleEffectsComponent::TurnOffLightEffects(
      (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent,
      FX_BRAKELIGHTS);
    v4 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_AIEXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_AIEXHAUST_DIRTY);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_EXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_EXHAUST_DIRTY);
  }
  v5 = (UFG::VehicleAudioComponent *)this->mAudioComponent.m_pSimComponent;
  if ( v5 )
    UFG::VehicleAudioComponent::OnDriverComponentParked(v5, a2);
}

// File Line: 347
// RVA: 0x6773D0
void __fastcall UFG::VehicleDriverInterface::EjectDriver(UFG::VehicleDriverInterface *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::HitReactionComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::HitReactionComponent *v12; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::HitRecord hitrecord; // [rsp+30h] [rbp-138h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mDriver.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::HitReactionComponent *)m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      m_pComponent = (UFG::HitReactionComponent *)v5;
    }
    else
    {
      m_pComponent = (UFG::HitReactionComponent *)m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::HitRecord::HitRecord(&hitrecord);
      hitrecord.mDamage = 100;
      hitrecord.mAttackTypeID = gAttackCollisionRemoveDriver.m_EnumValue;
      UFG::HitReactionComponent::HandleHitReaction(m_pComponent, &hitrecord);
      UFG::HitRecord::~HitRecord(&hitrecord);
    }
  }
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    v7 = m_pSimObject->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      v8 = m_pSimObject->m_Components.p[20].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      v9 = (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = m_pSimObject->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + 13i64)
                                   + *(_QWORD *)&v8[1].m_TypeUID
                                   + 40);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          v12 = (UFG::HitReactionComponent *)v10->m_Components.p[15].m_pComponent;
        }
        else if ( v11 >= 0 )
        {
          if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::HitReactionComponent::_TypeUID);
          v12 = (UFG::HitReactionComponent *)ComponentOfTypeHK;
        }
        else
        {
          v12 = (UFG::HitReactionComponent *)v10->m_Components.p[15].m_pComponent;
        }
        if ( v12 )
        {
          UFG::HitRecord::HitRecord(&hitrecord);
          hitrecord.mDamage = 100;
          hitrecord.mAttackTypeID = gAttackCollisionRemoveDriver.m_EnumValue;
          UFG::HitReactionComponent::HandleHitReaction(v12, &hitrecord);
          UFG::HitRecord::~HitRecord(&hitrecord);
        }
      }
    }
  }
}

// File Line: 383
// RVA: 0x679CC0
UFG::TransformNodeComponent *__fastcall UFG::VehicleDriverInterface::GetChaseSpawnTransform(
        UFG::VehicleDriverInterface *this,
        float distance_behind)
{
  int v2; // ebp
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int mNext_high; // r12d
  float *v10; // rbx
  int v11; // r14d
  __int128 x_low; // xmm4
  float v13; // xmm5_4
  float v14; // xmm6_4
  __m128 v15; // xmm2
  float v16; // xmm7_4
  int v17; // r12d
  int v18; // eax
  int v19; // ecx
  __int64 v20; // rcx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  __int64 v25; // rbx
  int v26; // eax
  float *v27; // rbx
  float *v28; // rcx
  __m128 v29; // xmm2
  float v30; // xmm1_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  __m128 v33; // xmm10
  float v34; // xmm9_4
  float v35; // xmm8_4
  __m128 v36; // xmm2
  float v37; // xmm7_4
  int v38; // eax
  int mNext; // ecx
  int vfptr; // edx
  float v41; // xmm10_4
  float v42; // xmm8_4
  float v43; // xmm9_4
  __int64 v44; // rcx
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  UFG::TransformNodeComponent *m_ChaseSpawnTransform; // rcx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h] BYREF

  v2 = 0;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  m_pTransformNodeComponent = 0i64;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !m_pTransformNodeComponent || !m_pComponent )
    return this->m_ChaseSpawnTransform;
  mNext_high = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
  if ( mNext_high <= 0 )
    return this->m_ChaseSpawnTransform;
  v10 = (float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2
                                                               * (int)UFG::qSignedMod(
                                                                        (int)m_pComponent[29].m_BoundComponentHandles.mNode.mNext,
                                                                        (int)m_pComponent[30].vfptr)];
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v11 = 0;
  x_low = LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.x);
  *(float *)&x_low = *(float *)&x_low - *v10;
  v13 = m_pTransformNodeComponent->mWorldTransform.v3.y - v10[1];
  v14 = m_pTransformNodeComponent->mWorldTransform.v3.z - v10[2];
  v15 = (__m128)x_low;
  v15.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(v13 * v13)) + (float)(v14 * v14);
  v16 = _mm_sqrt_ps(v15).m128_f32[0];
  if ( v16 < distance_behind )
  {
    v17 = mNext_high - 1;
    do
    {
      if ( v11 >= v17 )
        break;
      v18 = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
      v19 = 0;
      if ( v11 > 0 )
        v19 = v11;
      if ( v19 < v18 )
        v18 = v19;
      v20 = (int)UFG::qSignedMod(
                   LODWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext) - v18,
                   (int)m_pComponent[30].vfptr);
      v21 = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
      v16 = v16 + *((float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2 * v20].mNext + 1);
      v22 = 0;
      if ( v11 + 1 > 0 )
        v22 = v11 + 1;
      if ( v22 < v21 )
        v21 = v22;
      v23 = UFG::qSignedMod(
              LODWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext) - v21,
              (int)m_pComponent[30].vfptr);
      v24 = 0;
      v25 = v23;
      v26 = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
      v27 = (float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2 * v25];
      if ( v11 > 0 )
        v24 = v11;
      if ( v24 < v26 )
        v26 = v24;
      ++v11;
      v28 = (float *)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2
                                                                   * (int)UFG::qSignedMod(
                                                                            LODWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext)
                                                                          - v26,
                                                                            (int)m_pComponent[30].vfptr)];
      x_low = *(unsigned int *)v28;
      *(float *)&x_low = *(float *)&x_low - *v27;
      v13 = v28[1] - v27[1];
      v14 = v28[2] - v27[2];
    }
    while ( v16 < distance_behind );
  }
  v29 = (__m128)x_low;
  v29.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(v13 * v13)) + (float)(v14 * v14);
  if ( v29.m128_f32[0] == 0.0 )
    v30 = 0.0;
  else
    v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
  *(float *)&x_low = *(float *)&x_low * v30;
  v31 = v13 * v30;
  v32 = v14 * v30;
  v33 = (__m128)x_low;
  v33.m128_f32[0] = *(float *)&x_low - (float)(v32 * 0.0);
  v34 = (float)(v32 * 0.0) - v31;
  v36 = v33;
  v35 = (float)(v31 * 0.0) - (float)(*(float *)&x_low * 0.0);
  v36.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v34 * v34)) + (float)(v35 * v35);
  if ( v36.m128_f32[0] == 0.0 )
    v37 = 0.0;
  else
    v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
  v38 = HIDWORD(m_pComponent[29].m_BoundComponentHandles.mNode.mNext);
  mNext = (int)m_pComponent[29].m_BoundComponentHandles.mNode.mNext;
  vfptr = (int)m_pComponent[30].vfptr;
  v41 = v33.m128_f32[0] * v37;
  v42 = v35 * v37;
  v43 = v34 * v37;
  LODWORD(m.v0.x) = x_low;
  m.v0.y = v31;
  m.v0.z = v32;
  m.v2.w = 0.0;
  m.v1.w = 0.0;
  m.v1.x = v43;
  m.v1.y = v41;
  m.v1.z = v42;
  m.v0.w = 0.0;
  if ( v11 > 0 )
    v2 = v11;
  m.v2.x = (float)(v42 * v31) - (float)(v41 * v32);
  if ( v2 < v38 )
    v38 = v2;
  m.v2.y = (float)(v43 * v32) - (float)(v42 * *(float *)&x_low);
  m.v2.z = (float)(v41 * *(float *)&x_low) - (float)(v43 * v31);
  v44 = (__int64)&m_pComponent[30].m_SafePointerList.mNode.mPrev[2 * (int)UFG::qSignedMod(mNext - v38, vfptr)];
  v45 = *(float *)v44;
  v46 = *(float *)(v44 + 4);
  v47 = *(float *)(v44 + 8);
  m_ChaseSpawnTransform = this->m_ChaseSpawnTransform;
  m.v3.w = 1.0;
  m.v3.x = v45;
  m.v3.y = v46;
  m.v3.z = v47;
  UFG::TransformNodeComponent::SetWorldTransform(m_ChaseSpawnTransform, &m);
  return this->m_ChaseSpawnTransform;
}

// File Line: 422
// RVA: 0x68C320
void __fastcall UFG::VehicleDriverInterface::StartEngineAudio(
        UFG::VehicleDriverInterface *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  char v6; // al
  UFG::SimComponent *v7; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx

  m_pSimComponent = this->mAudioComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      v6 = BYTE4(m_pSimComponent[9].m_BoundComponentHandles.mNode.mNext);
      if ( (v6 & 2) == 0 )
        BYTE4(m_pSimComponent[9].m_BoundComponentHandles.mNode.mNext) = v6 | 2;
    }
    v7 = this->mAudioComponent.m_pSimComponent;
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
    {
      mNext = v7[8].m_BoundComponentHandles.mNode.mNext;
      if ( mNext )
      {
        if ( ((__int64)mNext[21].mNext & 4) != 0 )
          ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))mNext->mPrev[8].mNext)(mNext);
      }
    }
  }
}

