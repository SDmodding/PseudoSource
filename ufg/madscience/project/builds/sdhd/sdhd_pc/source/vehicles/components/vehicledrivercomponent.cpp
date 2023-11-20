// File Line: 45
// RVA: 0x157B8B0
__int64 dynamic_initializer_for__UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList__);
}

// File Line: 46
// RVA: 0x67A3F0
UFG::ComponentIDDesc *__fastcall UFG::VehicleDriverInterface::GetDesc(UFG::VehicleDriverInterface *this)
{
  return &UFG::VehicleDriverInterface::_TypeIDesc;
}

// File Line: 61
// RVA: 0x66ABE0
void __fastcall UFG::VehicleDriverInterface::VehicleDriverInterface(UFG::VehicleDriverInterface *this, unsigned int name_uid)
{
  UFG::VehicleDriverInterface *v2; // rdi
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v3; // rbx
  UFG::TransformNodeComponent *v4; // rsi
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v5; // rax
  UFG::qMemoryPool *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::TransformNodeComponent *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable';
  v3 = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleDriverInterface::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleDriverInterface::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&v2->mMoverComponent);
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>(&v2->mRenderComponent);
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::RebindingComponentHandle<UFG::VehicleAudioComponent,0>(&v2->mAudioComponent);
  v9 = &v2->mDriver;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v4 = 0i64;
  v2->mDriver.m_pPointer = 0i64;
  v2->mState = 0;
  *(_QWORD *)&v2->mDesiredState = 1i64;
  v2->mPropertySet = 0i64;
  v2->mForceDock = 0;
  v2->mBreakOnUpdate = 0;
  v5 = UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev;
  UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev->mNext = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList;
  UFG::VehicleDriverInterface::s_VehicleDriverInterfaceList.mNode.mPrev = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID,
    "VehicleDriverInterface");
  if ( !(_S25_3 & 1) )
  {
    _S25_3 |= 1u;
    uidChaseSpawnTransform = UFG::qStringHash32("ChaseSpawnTransform", 0xFFFFFFFF);
  }
  v6 = UFG::GetSimulationMemoryPool();
  v7 = UFG::qMemoryPool::Allocate(v6, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v7,
      uidChaseSpawnTransform,
      0i64,
      0);
    v4 = v8;
  }
  v2->m_ChaseSpawnTransform = v4;
}

// File Line: 73
// RVA: 0x66D340
void __fastcall UFG::VehicleDriverInterface::~VehicleDriverInterface(UFG::VehicleDriverInterface *this)
{
  UFG::VehicleDriverInterface *v1; // rbx
  UFG::TransformNodeComponent *v2; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v3; // rdi
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v4; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v11; // rcx
  UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleDriverInterface::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::VehicleDriverInterface::`vftable'{for `UFG::UpdateInterface'};
  v2 = this->m_ChaseSpawnTransform;
  if ( v2 )
    v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 1u);
  if ( v1 == UFG::VehicleDriverInterface::s_VehicleDriverInterfacepCurrentIterator )
    UFG::VehicleDriverInterface::s_VehicleDriverInterfacepCurrentIterator = (UFG::VehicleDriverInterface *)&v1->mPrev[-5].mNext;
  v3 = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v6 = &v1->mDriver;
  if ( v1->mDriver.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mDriver.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDriver.mPrev;
  }
  v1->mDriver.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mDriver.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDriver.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAudioComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mRenderComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mMoverComponent);
  v11 = v3->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v3->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::VehicleDriverInterface,UFG::VehicleDriverInterface> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 82
// RVA: 0x6836A0
void __fastcall UFG::VehicleDriverInterface::OnAttach(UFG::VehicleDriverInterface *this, UFG::SimObject *object)
{
  UFG::VehicleDriverInterface *v2; // rdi
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::SimComponent *v19; // rax
  hkSeekableStreamReader *v20; // [rsp+30h] [rbp-18h]
  void (__fastcall *v21)(UFG::VehicleDriverInterface *, UFG::Event *); // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = &this->mMoverComponent;
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
    && ((UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v3->mNext != v3) )
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
  v3->m_TypeUID = UFG::PhysicsMoverInterface::_TypeUID;
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = &v2->mRenderComponent;
  if ( v2->mRenderComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mRenderComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mRenderComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mRenderComponent.m_pSimObject = 0i64;
    v2->mRenderComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mRenderComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mRenderComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v2->mRenderComponent.mNext != &v2->mRenderComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mRenderComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mRenderComponent.m_Changed = 1;
  v2->mRenderComponent.m_pSimObject = v4;
  v2->mRenderComponent.m_TypeUID = UFG::VehicleEffectsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(&v2->mRenderComponent, v4);
  v14 = &v2->mAudioComponent;
  if ( v2->mAudioComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->mAudioComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->mAudioComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mAudioComponent.m_pSimObject = 0i64;
    v2->mAudioComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAudioComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->mAudioComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v2->mAudioComponent.mNext != &v2->mAudioComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->mAudioComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->mAudioComponent.m_Changed = 1;
  v2->mAudioComponent.m_pSimObject = v4;
  v2->mAudioComponent.m_TypeUID = UFG::VehicleAudioComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::BindInternal<UFG::SimObject>(&v2->mAudioComponent, v4);
  v19 = v2->mMoverComponent.m_pSimComponent;
  if ( v19 )
  {
    LODWORD(v19[1].m_pSimObject) &= 0xFFFFF9C0;
    *(_QWORD *)&v19[1].m_TypeUID = 0i64;
    *(_QWORD *)&v19[1].m_Flags = 0i64;
  }
  v20 = Assembly::GetRCX(v2);
  v21 = UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v20,
    UFG::gEventMountVehicle.mUID,
    UFG::gEventMountVehicle.mName,
    0);
  v20 = Assembly::GetRCX(v2);
  v21 = UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v20,
    UFG::gEventDisMountVehicle.mUID,
    UFG::gEventDisMountVehicle.mName,
    0);
}

// File Line: 99
// RVA: 0x684290
void __fastcall UFG::VehicleDriverInterface::OnDetach(UFG::VehicleDriverInterface *this)
{
  UFG::SimComponent *v1; // rax
  UFG::VehicleDriverInterface *v2; // rbx
  UFG::SimComponent *v3; // rax
  float v4; // xmm0_4
  signed int v5; // eax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *v6; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *v11; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *v16; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  hkSeekableStreamReader *v21; // [rsp+20h] [rbp-18h]
  void (__fastcall *v22)(UFG::VehicleDriverInterface *, UFG::Event *); // [rsp+28h] [rbp-10h]

  v1 = this->mMoverComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    LODWORD(v1[1].m_pSimObject) &= 0xFFFFF9C0;
    *(_QWORD *)&v1[1].m_TypeUID = 0i64;
    *(_QWORD *)&v1[1].m_Flags = 0i64;
  }
  v22 = UFG::VehicleDriverInterface::EventHandler;
  v21 = Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v21,
    UFG::gEventMountVehicle.mUID);
  v21 = Assembly::GetRCX(v2);
  v22 = UFG::VehicleDriverInterface::EventHandler;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v21,
    UFG::gEventDisMountVehicle.mUID);
  v3 = v2->mMoverComponent.m_pSimComponent;
  if ( v3 && !((_QWORD)v3[14].vfptr & 1) )
  {
    v4 = *((float *)&v3[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v5 = 1;
    if ( (float)(v4 * 3.5999999) > 30.0 )
      v5 = 5;
    v2->mDesiredState = v5;
    UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)((char *)v2 + 64), 0.0);
  }
  v6 = &v2->mMoverComponent;
  if ( v2->mMoverComponent.m_pSimComponent )
  {
    v7 = v6->mPrev;
    v8 = v2->mMoverComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v2->mMoverComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mMoverComponent.m_pSimObject = 0i64;
    v2->mMoverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mMoverComponent.mPrev;
    v6->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v6->mPrev;
    goto LABEL_15;
  }
  if ( v2->mMoverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v6->mPrev != v6
     || (UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v2->mMoverComponent.mNext != &v2->mMoverComponent) )
  {
    v9 = v6->mPrev;
    v10 = v2->mMoverComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    goto LABEL_14;
  }
LABEL_15:
  v2->mMoverComponent.m_Changed = 1;
  v11 = &v2->mRenderComponent;
  if ( v2->mRenderComponent.m_pSimComponent )
  {
    v12 = v11->mPrev;
    v13 = v2->mRenderComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v2->mRenderComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mRenderComponent.m_pSimObject = 0i64;
    v2->mRenderComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mRenderComponent.mPrev;
    v11->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v11->mPrev;
    goto LABEL_22;
  }
  if ( v2->mRenderComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v11->mPrev != v11
     || (UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v2->mRenderComponent.mNext != &v2->mRenderComponent) )
  {
    v14 = v11->mPrev;
    v15 = v2->mRenderComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    goto LABEL_21;
  }
LABEL_22:
  v2->mRenderComponent.m_Changed = 1;
  v16 = &v2->mAudioComponent;
  if ( v2->mAudioComponent.m_pSimComponent )
  {
    v17 = v16->mPrev;
    v18 = v2->mAudioComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v2->mAudioComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->mAudioComponent.m_pSimObject = 0i64;
    v2->mAudioComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAudioComponent.mPrev;
    v16->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v16->mPrev;
    goto LABEL_29;
  }
  if ( v2->mAudioComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v16->mPrev != v16
     || (UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v2->mAudioComponent.mNext != &v2->mAudioComponent) )
  {
    v19 = v16->mPrev;
    v20 = v2->mAudioComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    goto LABEL_28;
  }
LABEL_29:
  v2->mAudioComponent.m_Changed = 1;
}

// File Line: 116
// RVA: 0x676B40
void __fastcall UFG::VehicleDriverInterface::DismountAndUpdate(UFG::VehicleDriverInterface *this)
{
  UFG::SimComponent *v1; // rax
  float v2; // xmm0_4
  signed int v3; // eax
  UFG::UpdateInterface *v4; // rcx

  v1 = this->mMoverComponent.m_pSimComponent;
  if ( v1 && !((_QWORD)v1[14].vfptr & 1) )
  {
    v2 = *((float *)&v1[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v3 = 1;
    if ( (float)(v2 * 3.5999999) > 30.0 )
      v3 = 5;
    v4 = (UFG::UpdateInterface *)&this->vfptr;
    HIDWORD(v4[24].vfptr) = v3;
    UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)v4, 0.0);
  }
}

// File Line: 135
// RVA: 0x68A6A0
void __fastcall UFG::VehicleDriverInterface::SetDesiredState(UFG::VehicleDriverInterface *this, UFG::VehicleState state)
{
  this->mDesiredState = state;
}

// File Line: 142
// RVA: 0x678270
void __fastcall UFG::VehicleDriverInterface::EventHandler(UFG::VehicleDriverInterface *this, UFG::Event *evt)
{
  unsigned int v2; // eax

  v2 = evt->m_EventUID;
  if ( UFG::gEventDisMountVehicle.mUID == v2 )
  {
    if ( evt[1].mNext == (UFG::qNode<UFG::Event,UFG::Event> *)this->mDriver.m_pPointer )
      UFG::VehicleDriverInterface::DismountAndUpdate(this);
  }
  else if ( UFG::gEventMountVehicle.mUID == v2 && this->mDriver.m_pPointer == (UFG::SimObject *)evt[1].mNext )
  {
    this->mDesiredState = 2;
  }
}

// File Line: 172
// RVA: 0x68A6B0
void __fastcall UFG::VehicleDriverInterface::SetDriver(UFG::VehicleDriverInterface *this, UFG::SimObject *driver)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mDriver.mPrev;
  if ( this->mDriver.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)driver;
  if ( driver )
  {
    v5 = driver->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &driver->m_SafePointerList.mNode;
    driver->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 183
// RVA: 0x694520
void __fastcall UFG::VehicleDriverInterface::Update(UFG::VehicleDriverInterface *this, float deltaTime)
{
  __int64 v2; // rax
  UFG::VehicleDriverInterface *v3; // rdi
  int v4; // eax
  int v5; // ecx
  UFG::PhysicsVehicle *v6; // rcx
  hkgpIndexedMeshDefinitions::Edge *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rbx
  UFG::SimObjectGame *v9; // rdi
  UFG::SimComponent *v10; // rax
  unsigned __int16 v11; // cx
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v2 = *(_QWORD *)&this[-1].mForceDock;
  v3 = this;
  if ( !v2 || !((*(_WORD *)(v2 + 0x4C) >> 10) & 1) )
  {
    v4 = HIDWORD(this->mAudioComponent.mNext);
    v5 = (int)this->mAudioComponent.mNext;
    if ( v4 != v5 )
    {
      LODWORD(v3->mAudioComponent.mNext) = v4;
      if ( v5 == 4 )
      {
        v6 = (UFG::PhysicsVehicle *)v3->m_BoundComponentHandles.mNode.mPrev[40].mNext;
        if ( v6 )
          UFG::PhysicsVehicle::RestoreSuperStopDrag(v6);
      }
      if ( LODWORD(v3->mAudioComponent.mNext) == 1 )
      {
        UFG::VehicleDriverInterface::Parked(
          (UFG::VehicleDriverInterface *)((char *)v3 - 64),
          (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)(LODWORD(v3->mAudioComponent.mNext) - 1));
      }
      else if ( LODWORD(v3->mAudioComponent.mNext) == 2 )
      {
        UFG::VehicleDriverInterface::Driving((UFG::VehicleDriverInterface *)((char *)v3 - 64));
      }
      else
      {
        v7 = (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)(LODWORD(v3->mAudioComponent.mNext) - 3);
        if ( LODWORD(v3->mAudioComponent.mNext) != 3 && (_DWORD)v7 == 2 )
          UFG::VehicleDriverInterface::Uncontrolled((UFG::VehicleDriverInterface *)((char *)v3 - 64), v7);
      }
    }
    v8 = v3->m_BoundComponentHandles.mNode.mPrev;
    v9 = *(UFG::SimObjectGame **)&v3[-1].mForceDock;
    if ( v9 )
    {
      v11 = v9->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::StimulusEmitterComponent::_TypeUID);
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::StimulusEmitterComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::StimulusEmitterComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v9->vfptr,
                  UFG::StimulusEmitterComponent::_TypeUID);
        }
      }
      else
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::StimulusEmitterComponent::_TypeUID);
      }
    }
    else
    {
      v10 = 0i64;
    }
    if ( (_QWORD)v8[6].mNext & 0x20 )
    {
      if ( !v10 )
      {
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusEmissionType = 1;
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_VEHICLE_BURNOUT,
          &stimulus_parameters,
          (UFG::SimObject *)&v9->vfptr);
      }
    }
    else if ( v10 )
    {
      UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_VEHICLE_BURNOUT,
        (UFG::SimObject *)&v9->vfptr);
    }
    LODWORD(v8[6].mNext) &= 0xFFFFF9C0;
    v8[5].mNext = 0i64;
    v8[6].mPrev = 0i64;
  }
}

// File Line: 272
// RVA: 0x677360
void __fastcall UFG::VehicleDriverInterface::Driving(UFG::VehicleDriverInterface *this)
{
  UFG::VehicleDriverInterface *v1; // rbx
  UFG::SimComponent *v2; // rcx
  UFG::VehicleEffectsComponent *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  v1 = this;
  v2 = this->mMoverComponent.m_pSimComponent;
  if ( v2 )
    ((void (*)(void))v2->vfptr[17].__vecDelDtor)();
  v3 = (UFG::VehicleEffectsComponent *)v1->mRenderComponent.m_pSimComponent;
  if ( v3 )
    UFG::VehicleEffectsComponent::TurnOnExhaust(v3);
  v4 = (UFG::VehicleAudioComponent *)v1->mAudioComponent.m_pSimComponent;
  if ( v4 && v4->m_bIsInitialized && v4->m_bVehicleIsInitialized && v4->m_eDriverType == eDriverType_Player )
    UFG::ConversationManager::ResumePlayerConversations(eInterruptType_GetOutOfVehicle);
}

// File Line: 300
// RVA: 0x68EC70
void __fastcall UFG::VehicleDriverInterface::Uncontrolled(UFG::VehicleDriverInterface *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleDriverInterface *v2; // rdi
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rbx
  int v5; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::VehicleEffectsComponent *v7; // rcx
  UFG::VehicleEffectsComponent *v8; // rbx
  UFG::VehicleAudioComponent *v9; // rcx

  v2 = this;
  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[18].__vecDelDtor)();
    v4 = v2->mMoverComponent.m_pSimComponent;
    v5 = (int)v4[14].vfptr;
    if ( !(v5 & 1) && !(v5 & 8) )
    {
      UFG::OnlineManager::Instance();
      ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[9].__vecDelDtor)(v4);
      v6 = v4[10].m_SafePointerList.mNode.mPrev;
      if ( v6 )
        LODWORD(v6[34].mPrev) = 3;
      UFG::PhysicsMoverInterface::ActivateTargetSpheres((UFG::PhysicsMoverInterface *)v4);
      LODWORD(v4[13].vfptr) = 1092616192;
      HIDWORD(v4[12].m_BoundComponentHandles.mNode.mNext) = 1;
    }
  }
  v7 = (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent;
  if ( v7 )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(v7);
    UFG::VehicleEffectsComponent::TurnOffLightEffects(
      (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent,
      FX_BRAKELIGHTS);
    v8 = (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent;
    UFG::VehicleEffectsComponent::TurnOffEffect_New(
      (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent,
      FX_AIEXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, FX_AIEXHAUST_DIRTY);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, FX_EXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v8, FX_EXHAUST_DIRTY);
  }
  v9 = (UFG::VehicleAudioComponent *)v2->mAudioComponent.m_pSimComponent;
  if ( v9 )
    UFG::VehicleAudioComponent::OnDriverComponentUncontrolled(v9, a2);
}

// File Line: 321
// RVA: 0x685E60
void __fastcall UFG::VehicleDriverInterface::Parked(UFG::VehicleDriverInterface *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleDriverInterface *v2; // rdi
  UFG::VehicleEffectsComponent *v3; // rcx
  UFG::VehicleEffectsComponent *v4; // rbx
  UFG::VehicleAudioComponent *v5; // rcx

  v2 = this;
  v3 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.m_pSimComponent;
  if ( v3 )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(v3);
    UFG::VehicleEffectsComponent::TurnOffLightEffects(
      (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent,
      FX_BRAKELIGHTS);
    v4 = (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent;
    UFG::VehicleEffectsComponent::TurnOffEffect_New(
      (UFG::VehicleEffectsComponent *)v2->mRenderComponent.m_pSimComponent,
      FX_AIEXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_AIEXHAUST_DIRTY);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_EXHAUST_CLEAN);
    UFG::VehicleEffectsComponent::TurnOffEffect_New(v4, FX_EXHAUST_DIRTY);
  }
  v5 = (UFG::VehicleAudioComponent *)v2->mAudioComponent.m_pSimComponent;
  if ( v5 )
    UFG::VehicleAudioComponent::OnDriverComponentParked(v5, a2);
}

// File Line: 347
// RVA: 0x6773D0
void __fastcall UFG::VehicleDriverInterface::EjectDriver(UFG::VehicleDriverInterface *this)
{
  UFG::VehicleDriverInterface *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::HitReactionComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::HitReactionComponent *v12; // rbx
  UFG::SimComponent *v13; // rax
  UFG::HitRecord hitrecord; // [rsp+30h] [rbp-138h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mDriver.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::HitReactionComponent *)v2->m_Components.p[15].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID);
      v4 = (UFG::HitReactionComponent *)v5;
    }
    else
    {
      v4 = (UFG::HitReactionComponent *)v2->m_Components.p[15].m_pComponent;
    }
    if ( v4 )
    {
      UFG::HitRecord::HitRecord(&hitrecord);
      hitrecord.mDamage = 100;
      hitrecord.mAttackTypeID = gAttackCollisionRemoveDriver.m_EnumValue;
      UFG::HitReactionComponent::HandleHitReaction(v4, &hitrecord);
      UFG::HitRecord::~HitRecord(&hitrecord);
    }
  }
  v6 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v6->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = v6->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + 13i64)
                                   + *(_QWORD *)&v8[1].m_TypeUID
                                   + 40);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = (UFG::HitReactionComponent *)v10->m_Components.p[15].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
          }
          else
          {
            v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::HitReactionComponent::_TypeUID);
          }
          v12 = (UFG::HitReactionComponent *)v13;
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
UFG::TransformNodeComponent *__fastcall UFG::VehicleDriverInterface::GetChaseSpawnTransform(UFG::VehicleDriverInterface *this, float distance_behind)
{
  int v2; // ebp
  UFG::VehicleDriverInterface *v3; // r15
  UFG::SimObjectGame *v4; // rcx
  UFG::TransformNodeComponent *v5; // rdi
  UFG::SimComponent *v6; // rsi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  int v9; // er12
  int v10; // eax
  float *v11; // rbx
  int v12; // er14
  __int128 v13; // xmm4
  float v14; // xmm5_4
  float v15; // xmm6_4
  __m128 v16; // xmm2
  float v17; // xmm7_4
  int v18; // er12
  int v19; // eax
  int v20; // ecx
  __int64 v21; // rcx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  __int64 v26; // rbx
  int v27; // eax
  float *v28; // rbx
  float *v29; // rcx
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  __m128 v34; // xmm10
  float v35; // xmm9_4
  float v36; // xmm8_4
  __m128 v37; // xmm2
  float v38; // xmm7_4
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  float v42; // xmm10_4
  float v43; // xmm8_4
  float v44; // xmm9_4
  signed __int64 v45; // rcx
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  UFG::TransformNodeComponent *v49; // rcx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h]

  v2 = 0;
  v3 = this;
  v4 = (UFG::SimObjectGame *)this->m_pSimObject;
  v5 = 0i64;
  if ( v4 )
    v5 = v4->m_pTransformNodeComponent;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[24].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = v4->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v5 || !v6 )
    return v3->m_ChaseSpawnTransform;
  v9 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
  if ( v9 <= 0 )
    return v3->m_ChaseSpawnTransform;
  v10 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
  if ( v9 > 0 )
    v10 = 0;
  v11 = (float *)&v6[30].m_SafePointerList.mNode.mPrev[2
                                                     * (signed int)UFG::qSignedMod(
                                                                     LODWORD(v6[29].m_BoundComponentHandles.mNode.mNext)
                                                                   - v10,
                                                                     (int)v6[30].vfptr)];
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v12 = 0;
  v13 = LODWORD(v5->mWorldTransform.v3.x);
  *(float *)&v13 = *(float *)&v13 - *v11;
  v14 = v5->mWorldTransform.v3.y - v11[1];
  v15 = v5->mWorldTransform.v3.z - v11[2];
  v16 = (__m128)v13;
  v16.m128_f32[0] = (float)((float)(*(float *)&v13 * *(float *)&v13) + (float)(v14 * v14)) + (float)(v15 * v15);
  LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v16);
  if ( v17 < distance_behind )
  {
    v18 = v9 - 1;
    do
    {
      if ( v12 >= v18 )
        break;
      v19 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
      v20 = 0;
      if ( v12 > 0 )
        v20 = v12;
      if ( v20 < v19 )
        v19 = v20;
      v21 = (signed int)UFG::qSignedMod(LODWORD(v6[29].m_BoundComponentHandles.mNode.mNext) - v19, (int)v6[30].vfptr);
      v22 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
      v17 = v17 + *((float *)&v6[30].m_SafePointerList.mNode.mPrev[2 * v21].mNext + 1);
      v23 = 0;
      if ( v12 + 1 > 0 )
        v23 = v12 + 1;
      if ( v23 < v22 )
        v22 = v23;
      v24 = UFG::qSignedMod(LODWORD(v6[29].m_BoundComponentHandles.mNode.mNext) - v22, (int)v6[30].vfptr);
      v25 = 0;
      v26 = v24;
      v27 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
      v28 = (float *)&v6[30].m_SafePointerList.mNode.mPrev[2 * v26];
      if ( v12 > 0 )
        v25 = v12;
      if ( v25 < v27 )
        v27 = v25;
      ++v12;
      v29 = (float *)&v6[30].m_SafePointerList.mNode.mPrev[2
                                                         * (signed int)UFG::qSignedMod(
                                                                         LODWORD(v6[29].m_BoundComponentHandles.mNode.mNext)
                                                                       - v27,
                                                                         (int)v6[30].vfptr)];
      v13 = *(unsigned int *)v29;
      *(float *)&v13 = *(float *)&v13 - *v28;
      v14 = v29[1] - v28[1];
      v15 = v29[2] - v28[2];
    }
    while ( v17 < distance_behind );
  }
  v30 = (__m128)v13;
  v30.m128_f32[0] = (float)((float)(*(float *)&v13 * *(float *)&v13) + (float)(v14 * v14)) + (float)(v15 * v15);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  *(float *)&v13 = *(float *)&v13 * v31;
  v32 = v14 * v31;
  v33 = v15 * v31;
  v34 = (__m128)v13;
  v34.m128_f32[0] = *(float *)&v13 - (float)(v33 * 0.0);
  v35 = (float)(v33 * 0.0) - v32;
  v37 = v34;
  v36 = (float)(v32 * 0.0) - (float)(*(float *)&v13 * 0.0);
  v37.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v35 * v35)) + (float)(v36 * v36);
  if ( v37.m128_f32[0] == 0.0 )
    v38 = 0.0;
  else
    v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
  v39 = HIDWORD(v6[29].m_BoundComponentHandles.mNode.mNext);
  v40 = (int)v6[29].m_BoundComponentHandles.mNode.mNext;
  v41 = (int)v6[30].vfptr;
  v42 = v34.m128_f32[0] * v38;
  v43 = v36 * v38;
  v44 = v35 * v38;
  LODWORD(m.v0.x) = v13;
  m.v0.y = v32;
  m.v0.z = v33;
  m.v2.w = 0.0;
  m.v1.w = 0.0;
  m.v1.x = v44;
  m.v1.y = v42;
  m.v1.z = v43;
  m.v0.w = 0.0;
  if ( v12 > 0 )
    v2 = v12;
  m.v2.x = (float)(v43 * v32) - (float)(v42 * v33);
  if ( v2 < v39 )
    v39 = v2;
  m.v2.y = (float)(v44 * v33) - (float)(v43 * *(float *)&v13);
  m.v2.z = (float)(v42 * *(float *)&v13) - (float)(v44 * v32);
  v45 = (signed __int64)&v6[30].m_SafePointerList.mNode.mPrev[2 * (signed int)UFG::qSignedMod(v40 - v39, v41)];
  v46 = *(float *)v45;
  v47 = *(float *)(v45 + 4);
  v48 = *(float *)(v45 + 8);
  v49 = v3->m_ChaseSpawnTransform;
  m.v3.w = 1.0;
  m.v3.x = v46;
  m.v3.y = v47;
  m.v3.z = v48;
  UFG::TransformNodeComponent::SetWorldTransform(v49, &m);
  return v3->m_ChaseSpawnTransform;
}

// File Line: 422
// RVA: 0x68C320
void __fastcall UFG::VehicleDriverInterface::StartEngineAudio(UFG::VehicleDriverInterface *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::SimComponent *v2; // rbx
  UFG::VehicleDriverInterface *v3; // rdi
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  char v6; // al
  UFG::SimComponent *v7; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx

  v2 = this->mAudioComponent.m_pSimComponent;
  v3 = this;
  if ( v2 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      v6 = BYTE4(v2[9].m_BoundComponentHandles.mNode.mNext);
      if ( !(v6 & 2) )
        BYTE4(v2[9].m_BoundComponentHandles.mNode.mNext) = v6 | 2;
    }
    v7 = v3->mAudioComponent.m_pSimComponent;
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
    {
      v8 = v7[8].m_BoundComponentHandles.mNode.mNext;
      if ( v8 )
      {
        if ( (_QWORD)v8[21].mNext & 4 )
          ((void (*)(void))v8->mPrev[8].mNext)();
      }
    }
  }
}

