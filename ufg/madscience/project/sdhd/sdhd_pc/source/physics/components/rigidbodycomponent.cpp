// File Line: 69
// RVA: 0x15143B0
__int64 dynamic_initializer_for__UFG::RigidBodyComponent::s_RigidBodyComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RigidBodyComponent::s_RigidBodyComponentList__);
}

// File Line: 70
// RVA: 0x466450
UFG::ComponentIDDesc *__fastcall UFG::RigidBodyComponent::GetDesc(UFG::RigidBodyComponent *this)
{
  return &UFG::RigidBodyComponent::_TypeIDesc;
}

// File Line: 76
// RVA: 0x1513CC0
__int64 dynamic_initializer_for__UFG::RigidBodyComponent::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::RigidBodyComponent::mAllocator);
  return atexit(dynamic_atexit_destructor_for__UFG::RigidBodyComponent::mAllocator__);
}

// File Line: 129
// RVA: 0x44D340
void __fastcall UFG::RigidBodyComponent::RigidBodyComponent(UFG::RigidBodyComponent *this, UFG::CollisionMeshData *mesh, UFG::CollisionInstanceData *instance, unsigned int flags, int followBoneIndex)
{
  UFG::RigidBodyComponent *v5; // rdi
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v6; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *v7; // ST28_8
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v8; // ST28_8
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsRenderHelper> *v9; // ST28_8
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *v10; // ST28_8
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v11; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v12; // rcx
  const char *v13; // rax
  UFG::CollisionMeshData *v14; // rdx
  UFG::qReflectHandleBase v15; // [rsp+30h] [rbp-38h]

  v5 = this;
  UFG::RigidBody::RigidBody((UFG::RigidBody *)&this->vfptr, mesh, instance, flags | 0x800);
  v6 = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBodyComponent::`vftable'{for `UFG::SimComponent'};
  v5->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBodyComponent::`vftable'{for `UFG::BasePhysicsObject'};
  v7 = &v5->mParkourComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v5->mParkourComponent.m_pPointer = 0i64;
  v8 = &v5->mCoverComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v5->mCoverComponent.m_pPointer = 0i64;
  v9 = &v5->mRenderComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v5->mRenderComponent.m_pPointer = 0i64;
  v10 = &v5->mStateMachineComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v5->mStateMachineComponent.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v5->mAnimationComponent);
  v5->mFollowBoneIndex = followBoneIndex;
  v5->mRuntimeStateMachineDefinition = 0i64;
  v5->mLifeSpan = -1.0;
  *(_QWORD *)&v5->mTimeSinceAddedToWorld = -1082130432i64;
  v11 = UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev;
  UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v5->mPrev;
  v6->mPrev = v11;
  v5->mNext = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList;
  UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
    "RigidBodyComponent");
  UFG::qReflectHandleBase::qReflectHandleBase(&v15);
  v13 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v12);
  v15.mTypeUID = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
  v14 = v5->mCollisionMeshData;
  if ( v14 )
    UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)&v14->mObjectProperties.mPrev);
  if ( HIBYTE(v15.mData[1].mHandles.mNode.mPrev) )
    v5->mFlags |= 0x2000u;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
}

// File Line: 150
// RVA: 0x450ED0
void __fastcall UFG::RigidBodyComponent::~RigidBodyComponent(UFG::RigidBodyComponent *this)
{
  UFG::RigidBodyComponent *v1; // rdi
  unsigned int v2; // ebx
  UFG::SimObject *v3; // rdx
  hkpRigidBody *v4; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *v7; // rax
  UFG::StateMachineDefinition *v8; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v9; // rbx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v10; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsRenderHelper> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v32; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v33; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBodyComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBodyComponent::`vftable'{for `UFG::BasePhysicsObject'};
  v2 = 0;
  if ( this->mInstanceData->mNumParts )
  {
    do
    {
      v3 = v1->mInstanceData->mParts[v2].mSimObject.m_pPointer;
      if ( v3 )
        UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
      ++v2;
    }
    while ( v2 < v1->mInstanceData->mNumParts );
  }
  v4 = v1->mBody;
  if ( v4 )
    v4->m_userData = 0i64;
  if ( v1->mRuntimeStateMachineDefinition )
  {
    v5 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
    v6 = UFG::qReflectWarehouse::Instance();
    v7 = UFG::qReflectWarehouse::GetInventory(v6, v5);
    UFG::qReflectInventoryBase::Remove(v7, (UFG::qReflectObject *)&v1->mRuntimeStateMachineDefinition->vfptr);
    v8 = v1->mRuntimeStateMachineDefinition;
    if ( v8 )
      v8->vfptr->__vecDelDtor((UFG::qReflectObject *)&v8->vfptr, 1u);
  }
  if ( v1 == UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator )
    UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator = (UFG::RigidBodyComponent *)&v1->mPrev[-18].mNext;
  v9 = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAnimationComponent);
  v12 = &v1->mStateMachineComponent;
  if ( v1->mStateMachineComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mStateMachineComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mStateMachineComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mStateMachineComponent.mPrev;
  }
  v1->mStateMachineComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mStateMachineComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mStateMachineComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mStateMachineComponent.mPrev;
  v17 = &v1->mRenderComponent;
  if ( v1->mRenderComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->mRenderComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->mRenderComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mRenderComponent.mPrev;
  }
  v1->mRenderComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->mRenderComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->mRenderComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mRenderComponent.mPrev;
  v22 = &v1->mCoverComponent;
  if ( v1->mCoverComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->mCoverComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCoverComponent.mPrev;
  }
  v1->mCoverComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->mCoverComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mCoverComponent.mPrev;
  v27 = &v1->mParkourComponent;
  if ( v1->mParkourComponent.m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v1->mParkourComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v1->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mParkourComponent.mPrev;
  }
  v1->mParkourComponent.m_pPointer = 0i64;
  v30 = v27->mPrev;
  v31 = v1->mParkourComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
  v1->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mParkourComponent.mPrev;
  v32 = v9->mPrev;
  v33 = v1->mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  v9->mPrev = v9;
  v1->mNext = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v1->mPrev;
  UFG::RigidBody::~RigidBody((UFG::RigidBody *)&v1->vfptr);
}

// File Line: 182
// RVA: 0x475560
void __fastcall UFG::RigidBodyComponent::SetStateMachineComponent(UFG::RigidBodyComponent *this, UFG::StateMachineComponent *smc)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mStateMachineComponent.mPrev;
  if ( this->mStateMachineComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = this->mStateMachineComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    this->mStateMachineComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mStateMachineComponent.mPrev;
  }
  this->mStateMachineComponent.m_pPointer = (UFG::SimComponent *)&smc->vfptr;
  if ( smc )
  {
    v5 = smc->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    this->mStateMachineComponent.mNext = &smc->m_SafePointerList.mNode;
    smc->m_SafePointerList.mNode.mPrev = v2;
    this->mFlags |= 0x4000u;
  }
  else
  {
    this->mFlags &= 0xFFFFBFFF;
  }
}

// File Line: 197
// RVA: 0x467AF0
void __fastcall UFG::RigidBodyComponent::GetStateMachineDefinition(UFG::RigidBodyComponent *this, UFG::qReflectHandle<UFG::StateMachineDefinition> *h)
{
  UFG::qReflectHandle<UFG::StateMachineDefinition> *v2; // rax
  UFG::SimComponent *v3; // rdx

  v2 = h;
  v3 = this->mStateMachineComponent.m_pPointer;
  if ( v3 )
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&v2->mPrev,
      (UFG::qReflectHandleBase *)&v3[1].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 207
// RVA: 0x45FE90
void __fastcall UFG::RigidBodyComponent::CreateRuntimeStateMachineDefinition(UFG::RigidBodyComponent *this, UFG::StateMachineDefinition *definition)
{
  UFG::StateMachineDefinition *v2; // rsi
  UFG::RigidBodyComponent *v3; // rdi
  DNA::Database *v4; // rax
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rbx
  UFG::qReflectWarehouse *v7; // rax
  UFG::qReflectInventoryBase *v8; // rax
  UFG::qReflectHandleBase *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rdx
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *v18; // rcx
  UFG::SimObject *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax

  v2 = definition;
  v3 = this;
  DNA::Database::Instance();
  v5 = DNA::Database::GenUID(v4);
  v2->mBaseNode.mUID = v5;
  v6 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v7 = UFG::qReflectWarehouse::Instance();
  v8 = UFG::qReflectWarehouse::GetInventory(v7, v6);
  UFG::qReflectInventoryBase::Add(v8, (UFG::qReflectObject *)&v2->vfptr);
  v3->mRuntimeStateMachineDefinition = v2;
  v9 = (UFG::qReflectHandleBase *)v3->mStateMachineComponent.m_pPointer;
  if ( v9 )
  {
    UFG::qReflectHandleBase::Init(v9 + 3, v9[3].mTypeUID, v5);
  }
  else
  {
    v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::StateMachineComponent::StateMachineComponent((UFG::StateMachineComponent *)v10, v2->mBaseNode.mUID, -1);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = &v3->mStateMachineComponent;
    if ( v3->mStateMachineComponent.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v3->mStateMachineComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v3->mStateMachineComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mStateMachineComponent.mPrev;
    }
    v3->mStateMachineComponent.m_pPointer = v12;
    if ( v12 )
    {
      v16 = v12->m_SafePointerList.mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v16;
      v3->mStateMachineComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    v17 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mStateMachineComponent.m_pPointer[1].m_Flags;
    if ( v3->mStateMachineComponent.m_pPointer[1].m_BoundComponentHandles.mNode.mPrev )
    {
      v18 = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)v17->mPrev;
      v19 = v3->mStateMachineComponent.m_pPointer[1].m_pSimObject;
      v18[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimObject> *, unsigned int))v19;
      v19->vfptr = v18;
      v17->mPrev = v17;
      v17->mNext = v17;
    }
    v17[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3;
    v20 = v3->m_SafePointerList.mNode.mPrev;
    v20->mNext = v17;
    v17->mPrev = v20;
    v17->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = v17;
    v3->mFlags |= 0x4000u;
  }
}

// File Line: 231
// RVA: 0x468960
bool __fastcall UFG::RigidBodyComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentRigidBody.mUID);
}

// File Line: 237
// RVA: 0x470B70
UFG::RigidBodyComponent *__fastcall UFG::RigidBodyComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::RigidBodyComponent *v2; // rdi
  UFG::SimObject *v3; // rbp
  UFG::allocator::free_link *v4; // rax
  hkQuaternionf *v5; // rax
  hkQuaternionf *v6; // rsi
  UFG::TransformNodeComponent *v7; // rbx
  UFG::qBaseTreeRB *v8; // r8
  UFG::RigidBodyComponent *result; // rax
  char *v10; // rax
  __int64 depth; // [rsp+20h] [rbp-78h]
  hkTransformf v12; // [rsp+40h] [rbp-58h]
  UFG::allocator::free_link *v13; // [rsp+A0h] [rbp+8h]
  UFG::qSymbolUC v14; // [rsp+A8h] [rbp+10h]
  __int64 *v15; // [rsp+B0h] [rbp+18h]

  v1 = sceneObject;
  v2 = 0i64;
  v3 = sceneObject->m_pSimObject;
  v15 = (__int64 *)&v13;
  LODWORD(v13) = UFG::gNullQSymbolUC;
  PropertyUtils::GetWithDefault<UFG::qSymbolUC>(
    &v14,
    sceneObject,
    (UFG::qSymbol *)&SimSym_CollisionModelName.mUID,
    (__int64)&v13,
    DEPTH_RECURSE);
  v4 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
  v13 = v4;
  if ( v4 )
  {
    UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  LODWORD(v6[6].m_vec.m_quad.m128_f32[0]) = v14;
  v6[5].m_vec.m_quad.m128_i32[3] = v1->m_NameUID;
  v6[5].m_vec.m_quad.m128_i32[2] = 0;
  v6[4].m_vec.m_quad.m128_i32[2] = v3->m_Name.mUID;
  v7 = v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3->m_pTransformNodeComponent);
  hkTransformf::set4x4ColumnMajor(&v12, &v7->mWorldTransform.v0.x);
  hkQuaternionf::set(v6, &v12.m_rotation);
  v6[2] = (hkQuaternionf)v12.m_translation;
  v8 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v6[6].m_vec.m_quad.m128_u32[0]);
  if ( !v8 )
  {
    v10 = UFG::qSymbol::as_cstr_dbg(&v14);
    UFG::qPrintf("Error: No collision mesh loaded for %s\n", v10);
    goto LABEL_8;
  }
  LODWORD(depth) = 0;
  result = (UFG::RigidBodyComponent *)((__int64 (__fastcall *)(UFG::BasePhysicsSystem *, hkQuaternionf *, UFG::qBaseTreeRB *, signed __int64, __int64, UFG::SimObject *, signed __int64))UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld)(
                                        UFG::BasePhysicsSystem::mInstance,
                                        v6,
                                        v8,
                                        4i64,
                                        depth,
                                        v3,
                                        -2i64);
  v2 = result;
  if ( !result )
  {
LABEL_8:
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v6);
    result = v2;
  }
  return result;
}

// File Line: 282
// RVA: 0x46E080
void __fastcall UFG::RigidBodyComponent::OnAttach(UFG::RigidBodyComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rdi
  UFG::RigidBodyComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::DynamicSceneryInstance *v10; // rcx

  v2 = object;
  v3 = this;
  UFG::RigidBody::OnAttach((UFG::RigidBody *)&this->vfptr, object);
  v4 = &v3->mAnimationComponent;
  if ( v3->mAnimationComponent.m_pSimComponent )
  {
    v5 = v3->mAnimationComponent.mNext;
    v6 = v4->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->mAnimationComponent.m_pSimObject = 0i64;
    v3->mAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mAnimationComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->mAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->mAnimationComponent.mNext != &v3->mAnimationComponent) )
  {
    v7 = v3->mAnimationComponent.mNext;
    v8 = v4->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->mAnimationComponent.m_Changed = 1;
  v3->mAnimationComponent.m_pSimObject = v2;
  v3->mAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(v4, v2);
  v9 = v3->mRenderComponent.m_pPointer;
  if ( v9 )
  {
    if ( v3->mFlags & 0x20 )
    {
      v10 = **(UFG::DynamicSceneryInstance ***)&v9[1].m_TypeUID;
      if ( v10 )
        UFG::DynamicSceneryInstance::ForceVisible(v10);
    }
  }
  if ( !(v3->mFlags & 0x400) )
    UFG::RigidBodyComponent::UpdateTransforms(v3);
}

// File Line: 303
// RVA: 0x46E890
void __fastcall UFG::RigidBodyComponent::OnDetach(UFG::RigidBodyComponent *this)
{
  UFG::RigidBodyComponent *v1; // rbx
  hkpRigidBody *v2; // rax

  v1 = this;
  if ( this->mAnimationComponent.m_pSimComponent )
    UFG::RebindingComponentHandleBase::Unbind((UFG::RebindingComponentHandleBase *)&this->mAnimationComponent.mPrev);
  v2 = v1->mBody;
  if ( v2 )
    v2->m_userData = 0i64;
  UFG::RigidBody::OnDetach((UFG::RigidBody *)&v1->vfptr);
}

// File Line: 321
// RVA: 0x468BD0
void __fastcall UFG::RigidBodyComponent::Inflate(UFG::RigidBodyComponent *this, bool addToWorld)
{
  UFG::RigidBodyComponent *v2; // rbx
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rcx

  v2 = this;
  if ( !(this->mFlags & 2) )
  {
    this->mTimeSinceAddedToWorld = 0.0;
    UFG::RigidBody::Inflate((UFG::RigidBody *)&this->vfptr, addToWorld);
    v3 = v2->mStateMachineComponent.m_pPointer;
    v2->mFlags |= 0x800u;
    if ( v3 )
      ((void (*)(void))v3->vfptr[9].__vecDelDtor)();
    v4 = v2->mParkourComponent.m_pPointer;
    if ( v4 )
      ((void (*)(void))v4->vfptr[9].__vecDelDtor)();
    v5 = v2->mCoverComponent.m_pPointer;
    if ( v5 )
      ((void (*)(void))v5->vfptr[9].__vecDelDtor)();
  }
}

// File Line: 355
// RVA: 0x4608B0
bool __fastcall UFG::RigidBodyComponent::Deflate(UFG::RigidBodyComponent *this)
{
  UFG::RigidBodyComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rcx
  bool result; // al

  v1 = this;
  this->mTimeSinceAddedToWorld = -1.0;
  v2 = this->mParkourComponent.m_pPointer;
  if ( v2 )
    ((void (*)(void))v2->vfptr[8].__vecDelDtor)();
  v3 = v1->mCoverComponent.m_pPointer;
  if ( v3 )
    ((void (*)(void))v3->vfptr[8].__vecDelDtor)();
  v4 = v1->mStateMachineComponent.m_pPointer;
  if ( v4 )
    ((void (*)(void))v4->vfptr[8].__vecDelDtor)();
  if ( v1->mLifeSpan >= 0.0 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v1->m_pSimObject);
  if ( v1->mFlags & 2 )
    result = UFG::RigidBody::Deflate((UFG::RigidBody *)&v1->vfptr);
  else
    result = 0;
  return result;
}

// File Line: 405
// RVA: 0x476A60
void __fastcall UFG::RigidBodyComponent::TeleportEventHandler(UFG::RigidBodyComponent *this, UFG::Event *event)
{
  bool v2; // zf
  float v3; // xmm1_4
  UFG::RigidBodyComponent *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::SimComponent *v19; // rax
  __int16 v20; // cx
  __int64 v21; // r8
  hkaPose *v22; // r8
  hkQsTransformf *v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  UFG::qMatrix44 *v28; // rdx
  hkpEntity *v29; // rbx
  hkpRigidBody *v30; // rbx
  UFG::qMatrix44 b; // [rsp+20h] [rbp-E0h]
  __int128 v32; // [rsp+60h] [rbp-A0h]
  hkQsTransformf v33; // [rsp+70h] [rbp-90h]
  UFG::qMatrix44 d; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h]

  v2 = this->mAnimationComponent.m_pSimComponent == 0i64;
  v3 = *((float *)&event[1].m_EventUID + 1);
  v4 = this;
  LODWORD(b.v0.x) = event[1].m_EventUID;
  v5 = *(float *)&event[1].m_NamePTR;
  b.v0.y = v3;
  v6 = *((float *)&event[1].m_NamePTR + 1);
  b.v0.z = v5;
  v7 = *(float *)&event[1].mUserData0;
  b.v0.w = v6;
  v8 = *((float *)&event[1].mUserData0 + 1);
  b.v1.x = v7;
  v9 = *(float *)&event[1].mUserData1;
  b.v1.y = v8;
  v10 = *((float *)&event[1].mUserData1 + 1);
  b.v1.z = v9;
  v11 = *(float *)&event[2].vfptr;
  b.v1.w = v10;
  v12 = *((float *)&event[2].vfptr + 1);
  b.v2.x = v11;
  v13 = *(float *)&event[2].mPrev;
  b.v2.y = v12;
  v14 = *((float *)&event[2].mPrev + 1);
  b.v2.z = v13;
  v15 = *(float *)&event[2].mNext;
  b.v2.w = v14;
  v16 = *((float *)&event[2].mNext + 1);
  b.v3.x = v15;
  v17 = *(float *)&event[2].m_EventUID;
  b.v3.y = v16;
  v18 = *((float *)&event[2].m_EventUID + 1);
  b.v3.z = v17;
  b.v3.w = v18;
  if ( v2
    || (v19 = this->mAnimationComponent.m_pSimComponent, !*(_QWORD *)&v19[1].m_Flags)
    || (v20 = this->mFollowBoneIndex, v20 == -1)
    || v4->mFlags & 0x1000 )
  {
    v28 = &b;
  }
  else
  {
    v21 = *(_QWORD *)&v19[2].m_TypeUID;
    if ( !v21 )
      goto LABEL_12;
    v22 = *(hkaPose **)(v21 + 488);
    if ( v22->m_boneFlags.m_data[v20] & 2 )
      v23 = hkaPose::calculateBoneModelSpace(v22, v20);
    else
      v23 = &v22->m_modelPose.m_data[v20];
    v33.m_translation = v23->m_translation;
    v33.m_rotation = v23->m_rotation;
    v24 = _mm_mul_ps(v33.m_rotation.m_vec.m_quad, v33.m_rotation.m_vec.m_quad);
    v33.m_scale = v23->m_scale;
    v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
    v27 = _mm_rsqrt_ps(v26);
    v33.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                    v33.m_rotation.m_vec.m_quad,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v27)));
    hkQsTransformf::get4x4ColumnMajor(&v33, &d.v0.x);
    UFG::qMatrix44::operator*(&d, &result, &b);
    v28 = &result;
  }
  UFG::RigidBody::SetTransform((UFG::RigidBody *)&v4->vfptr, v28);
LABEL_12:
  v29 = (hkpEntity *)&v4->mBody->vfptr;
  v32 = 0i64;
  if ( v29 )
  {
    hkpEntity::activate(v29);
    v29->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v29->m_motion.vfptr, (unsigned int)&v32);
    v30 = v4->mBody;
    hkpEntity::activate((hkpEntity *)&v4->mBody->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v30->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v30->m_motion,
      &v32);
  }
  v4->mFlags |= 0x800u;
}

// File Line: 450
// RVA: 0x466990
char __fastcall UFG::RigidBodyComponent::GetKeyframe(UFG::RigidBodyComponent *this, hkVector4f *nextPosition, hkQuaternionf *nextOrientation)
{
  Creature *v3; // r14
  hkQuaternionf *v4; // r12
  hkVector4f *v5; // r13
  UFG::RigidBodyComponent *v6; // r15
  UFG::SimComponent *v7; // rbx
  hkaSkeleton *v8; // rbp
  hkaPose *v9; // rsi
  bool pivotAtOrigin; // di
  hkQsTransformf *v11; // rax
  hkQsTransformf result; // [rsp+40h] [rbp-58h]

  v3 = (Creature *)this->mAnimationComponent.m_pSimComponent;
  v4 = nextOrientation;
  v5 = nextPosition;
  v6 = this;
  if ( v3 )
    v3 = (Creature *)v3->mLastSetPosition.m_scale.m_quad.m128_u64[1];
  if ( !v3 || this->mFollowBoneIndex == -1 )
    return 0;
  v7 = this->mRootTransformComponent.m_pSimComponent;
  v8 = v3->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent);
  v9 = v3->mPose.mHavokPose;
  pivotAtOrigin = (v6->mFlags >> 12) & 1;
  v11 = Creature::GetPositionhkQ(v3, &result);
  return UFG::MultiBody::GetKeyframe(v9, v8, v11, v6->mFollowBoneIndex, (UFG::qMatrix44 *)&v7[2], pivotAtOrigin, v5, v4);
}

// File Line: 468
// RVA: 0x47E040
void __fastcall UFG::RigidBodyComponent::UpdateAll(float delta_sec)
{
  UFG::PhysicsSystem *v1; // rsi
  UFG::RigidBodyComponent *v2; // rcx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rbx

  v1 = (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance;
  v2 = (UFG::RigidBodyComponent *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v2->mNext[-18].mNext;
      if ( (v2->m_Flags & 3) == 1 )
        UFG::RigidBodyComponent::Update(v2, v1, &v1->mActiveRegionManager, delta_sec);
      v2 = (UFG::RigidBodyComponent *)v3;
    }
    while ( v3 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
}

// File Line: 509
// RVA: 0x47C710
void __fastcall UFG::RigidBodyComponent::Update(UFG::RigidBodyComponent *this, UFG::PhysicsSystem *ps, UFG::ActiveRegionManager *activeRegionManager, float delta_sec)
{
  float v4; // xmm8_4
  UFG::RigidBodyComponent *v5; // r13
  UFG::CollisionMeshData *v6; // rax
  UFG::FractureConnectivity *v7; // rdi
  UFG::CollisionMeshData *v8; // rax
  unsigned int v9; // ebx
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  unsigned int v16; // eax
  __int64 v17; // rsi
  unsigned int v18; // er14
  hkpRigidBody *v19; // rax
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm2
  hkVector4f v22; // xmm3
  UFG::CollisionMeshData *v23; // r12
  UFG::CollisionInstanceData *v24; // r15
  __int64 v25; // rbx
  __int64 v26; // rdi
  unsigned int v27; // edx
  __int64 v28; // r8
  signed int v29; // eax
  UFG::FractureConnectivity **v30; // rdi
  UFG::SimObjectGame *v31; // rcx
  unsigned __int16 v32; // dx
  unsigned int v33; // edx
  UFG::SimComponent *v34; // rax
  Render::SimpleDrawableComponent *v35; // r15
  UFG::SimComponent *v36; // rax
  UFG::SimComponent *v37; // rax
  bool v38; // zf
  unsigned int v39; // er13
  __int64 v40; // r12
  unsigned __int64 v41; // r15
  __int64 v42; // rax
  signed __int64 v43; // rcx
  __int64 v44; // r14
  unsigned int v45; // esi
  unsigned int v46; // ebx
  unsigned __int64 v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::allocator::free_link *v49; // rdi
  _DWORD *v50; // rcx
  __int64 v51; // r8
  unsigned __int64 v52; // rbx
  UFG::qMemoryPool *v53; // rax
  UFG::FractureConnectivity **v54; // rax
  __int64 v55; // rax
  __int64 v56; // rbx
  UFG::SimComponent *v57; // rdx
  UFG::SimObjectGame *v58; // rcx
  UFG::SimComponent *v59; // rsi
  unsigned __int16 v60; // dx
  UFG::SimComponent *v61; // rax
  UFG::RigResource *v62; // r14
  UFG::qMemoryPool *v63; // rax
  UFG::allocator::free_link *v64; // rax
  __int64 v65; // rax
  __int64 v66; // r15
  UFG::SimObject *v67; // rdx
  unsigned __int16 v68; // cx
  unsigned int v69; // ebx
  unsigned int v70; // ebx
  __int64 v71; // rdi
  UFG::FractureConnectivity **v72; // r13
  __int64 v73; // rax
  signed __int64 v74; // rcx
  unsigned int v75; // eax
  signed __int64 v76; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v77; // rdx
  UFG::qMemoryPool *v78; // rax
  UFG::allocator::free_link *v79; // rax
  UFG::SimComponent *v80; // rax
  UFG::SimComponent *v81; // rdi
  UFG::SimObject *v82; // rdx
  unsigned __int16 v83; // cx
  unsigned int v84; // ebx
  float v85; // xmm0_4
  float v86; // xmm0_4
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v87; // rcx
  const char *v88; // rax
  UFG::CollisionMeshData *v89; // rdx
  UFG::PhysicsRenderHelper *v90; // rcx
  UFG::PhysicsRenderHelper *v91; // rcx
  unsigned int v92; // eax
  hkpRigidBody *v93; // r9
  hkpRigidBody *v94; // rax
  __m128 v95; // xmm6
  hkpRigidBody *v96; // rax
  __int64 check_null; // [rsp+20h] [rbp-B8h]
  Render::SimpleDrawableComponent *v98; // [rsp+30h] [rbp-A8h]
  signed int v99; // [rsp+38h] [rbp-A0h]
  void *mem[2]; // [rsp+40h] [rbp-98h]
  UFG::qArray<UFG::FractureConnectivity *,0> subGraphs; // [rsp+50h] [rbp-88h]
  unsigned int v102; // [rsp+60h] [rbp-78h]
  hkQuaternionf currentOrientation; // [rsp+68h] [rbp-70h]
  UFG::SimObjectModifier v104; // [rsp+78h] [rbp-60h]
  __int128 v105; // [rsp+98h] [rbp-40h]
  __int128 v106; // [rsp+A8h] [rbp-30h]
  int v107; // [rsp+B8h] [rbp-20h]
  int v108; // [rsp+BCh] [rbp-1Ch]
  float v109; // [rsp+C0h] [rbp-18h]
  hkTransformf transform; // [rsp+C8h] [rbp-10h]
  UFG::SimObjectModifier v111; // [rsp+108h] [rbp+30h]
  UFG::SimObjectModifier v112; // [rsp+128h] [rbp+50h]
  __int64 v113; // [rsp+148h] [rbp+70h]
  UFG::RigidBodyComponent *v114; // [rsp+1B8h] [rbp+E0h]

  v113 = -2i64;
  v4 = delta_sec;
  v5 = this;
  if ( this->mFlags & 0x10008 )
    return;
  v6 = this->mCollisionMeshData;
  v7 = v6->mFractureConnectivity;
  if ( !v7 || !v7->mColorsDirty )
    goto LABEL_152;
  if ( (signed int)UFG::FractureConnectivity::ComputeNodeColors(v6->mFractureConnectivity) <= 1 )
    goto LABEL_149;
  subGraphs.p = 0i64;
  *(_QWORD *)&subGraphs.size = 0i64;
  UFG::FractureConnectivity::ExtractSubGraphs(v7, &subGraphs);
  v5->mCollisionMeshData->mFractureConnectivity = *subGraphs.p;
  v8 = v5->mCollisionMeshData;
  v7 = v8->mFractureConnectivity;
  currentOrientation.m_vec.m_quad.m128_u64[0] = (unsigned __int64)v8->mFractureConnectivity;
  v9 = 12;
  v99 = 12;
  v10 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, Render::SimpleDrawableComponent::_TypeUID);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, Render::SimpleDrawableComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, Render::SimpleDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, Render::SimpleDrawableComponent::_TypeUID);
    }
    else
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, Render::SimpleDrawableComponent::_TypeUID);
    }
    if ( v12 && v12 != (UFG::SimComponent *)24 )
    {
      v9 = 28;
LABEL_30:
      v99 = v9;
      goto LABEL_31;
    }
  }
  v13 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = v13->m_Components.p[14].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = v13->m_Components.p[9].m_pComponent;
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v15 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v13->vfptr,
                UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v15 = v13->m_Components.p[14].m_pComponent;
    }
    if ( v15 )
      v9 = 44;
    goto LABEL_30;
  }
LABEL_31:
  v16 = 1;
  v102 = 1;
  if ( subGraphs.size <= 1 )
    goto LABEL_146;
  currentOrientation.m_vec.m_quad.m128_i32[2] = v9 & 0x10;
  do
  {
    v17 = v16;
    v18 = subGraphs.p[v16]->mNodes.size;
    v19 = v5->mBody;
    v20.m_quad = (__m128)v19->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    v21.m_quad = (__m128)v19->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v22.m_quad = (__m128)v19->m_motion.m_motionState.m_transform.m_translation;
    transform.m_rotation.m_col0 = v19->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    transform.m_rotation.m_col1 = (hkVector4f)v20.m_quad;
    transform.m_rotation.m_col2 = (hkVector4f)v21.m_quad;
    transform.m_translation = (hkVector4f)v22.m_quad;
    v23 = UFG::CollisionMeshData::SplitMeshUsingConnectivity(subGraphs.p[v17], v5->mCollisionMeshData, &transform);
    currentOrientation.m_vec.m_quad.m128_u64[0] = (unsigned __int64)v23;
    v24 = UFG::CollisionInstanceData::SplitInstanceUsingConnectivity(subGraphs.p[v17], v5->mInstanceData, &transform);
    if ( v18 )
    {
      v25 = 0i64;
      v26 = v18;
      do
      {
        UFG::Destruction::RemovePart(
          UFG::Destruction::mInstance,
          (UFG::RigidBody *)&v5->vfptr,
          subGraphs.p[v17]->mNodes.p[v25]->partIdx);
        ++v25;
        --v26;
      }
      while ( v26 );
      v9 = v99;
    }
    v27 = 0;
    if ( v18 )
    {
      v28 = 0i64;
      do
      {
        subGraphs.p[v17]->mNodes.p[v28]->partIdx = v27++;
        ++v28;
      }
      while ( v27 < v18 );
    }
    v29 = 0;
    if ( v5->mFlags & 0x400 )
      v29 = 1024;
    LODWORD(check_null) = v29;
    v30 = (UFG::FractureConnectivity **)UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld(
                                          UFG::BasePhysicsSystem::mInstance,
                                          v24,
                                          v23,
                                          v9,
                                          check_null,
                                          0i64);
    subGraphs.p = v30;
    if ( currentOrientation.m_vec.m_quad.m128_i32[2] )
    {
      v31 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( !v31 )
        goto LABEL_57;
      v32 = v31->m_Flags;
      if ( (v32 >> 14) & 1 )
      {
        v33 = Render::SimpleDrawableComponent::_TypeUID;
      }
      else
      {
        if ( (v32 & 0x8000u) != 0 )
        {
          v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, Render::SimpleDrawableComponent::_TypeUID);
          if ( v36 )
          {
            v35 = (Render::SimpleDrawableComponent *)&v36[-1].m_pSimObject;
            goto LABEL_58;
          }
LABEL_57:
          v35 = 0i64;
          goto LABEL_58;
        }
        if ( (v32 >> 13) & 1 )
        {
          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, Render::SimpleDrawableComponent::_TypeUID);
          if ( v37 )
          {
            v35 = (Render::SimpleDrawableComponent *)&v37[-1].m_pSimObject;
            goto LABEL_58;
          }
          goto LABEL_57;
        }
        v38 = ((v32 >> 12) & 1) == 0;
        v33 = Render::SimpleDrawableComponent::_TypeUID;
        if ( v38 )
        {
          v34 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v31->vfptr,
                  Render::SimpleDrawableComponent::_TypeUID);
LABEL_47:
          if ( v34 )
          {
            v35 = (Render::SimpleDrawableComponent *)&v34[-1].m_pSimObject;
LABEL_58:
            v98 = v35;
            mem[1] = 0i64;
            mem[0] = 0i64;
            v39 = 0;
            if ( v23->mNumParts )
            {
              v40 = 0i64;
              v41 = currentOrientation.m_vec.m_quad.m128_u64[0];
              do
              {
                v42 = *(_QWORD *)(v41 + 160);
                if ( v42 )
                  v43 = v42 + v41 + 160;
                else
                  v43 = 0i64;
                currentOrientation.m_vec.m_quad.m128_i32[0] = *(_DWORD *)(v40 + v43 + 80);
                v44 = LODWORD(mem[0]);
                v45 = LODWORD(mem[0]) + 1;
                if ( (unsigned int)(LODWORD(mem[0]) + 1) <= HIDWORD(mem[0]) )
                  goto LABEL_185;
                if ( HIDWORD(mem[0]) )
                  v46 = 2 * HIDWORD(mem[0]);
                else
                  v46 = 1;
                for ( ; v46 < v45; v46 *= 2 )
                  ;
                if ( v46 <= 4 )
                  v46 = 4;
                if ( v46 - v45 > 0x10000 )
                  v46 = LODWORD(mem[0]) + 65537;
                if ( v46 == LODWORD(mem[0]) )
                {
LABEL_185:
                  v49 = (UFG::allocator::free_link *)mem[1];
                }
                else
                {
                  v47 = 4i64 * v46;
                  if ( !is_mul_ok(v46, 4ui64) )
                    v47 = -1i64;
                  v48 = UFG::qMalloc(v47, "qArray.Add", 0i64);
                  v49 = v48;
                  v50 = mem[1];
                  if ( mem[1] )
                  {
                    v51 = 0i64;
                    if ( LODWORD(mem[0]) )
                    {
                      do
                      {
                        *((_DWORD *)&v48->mNext + v51) = v50[v51];
                        v51 = (unsigned int)(v51 + 1);
                        v50 = mem[1];
                      }
                      while ( (unsigned int)v51 < LODWORD(mem[0]) );
                    }
                    operator delete[](v50);
                  }
                  mem[1] = v49;
                  HIDWORD(mem[0]) = v46;
                }
                LODWORD(mem[0]) = v45;
                *((_DWORD *)&v49->mNext + v44) = currentOrientation.m_vec.m_quad.m128_i32[0];
                ++v39;
                v40 += 96i64;
              }
              while ( v39 < *(_DWORD *)(v41 + 56) );
              v35 = v98;
              v30 = subGraphs.p;
            }
            v52 = UFG::UIHKPlayerObjective::GetObjective(v35)->mBaseNode.mUID;
            v53 = UFG::GetSimulationMemoryPool();
            v54 = (UFG::FractureConnectivity **)UFG::qMemoryPool::Allocate(v53, 0x100ui64, "SimComponent", 0i64, 1u);
            subGraphs.p = v54;
            if ( v54 )
            {
              Render::SimpleDrawableComponent::SimpleDrawableComponent(
                (Render::SimpleDrawableComponent *)v54,
                v52,
                (UFG::qArray<unsigned long,0> *)mem);
              v56 = v55;
            }
            else
            {
              v56 = 0i64;
            }
            UFG::SimObjectModifier::SimObjectModifier(&v112, (UFG::SimObject *)v30[5], 1);
            if ( v56 )
              v57 = (UFG::SimComponent *)(v56 + 24);
            else
              v57 = 0i64;
            UFG::SimObjectModifier::AttachComponent(&v112, v57, 0xFFFFFFFFi64);
            UFG::SimObjectModifier::Close(&v112);
            UFG::SimObjectModifier::~SimObjectModifier(&v112);
            if ( mem[1] )
              operator delete[](mem[1]);
            mem[1] = 0i64;
            mem[0] = 0i64;
            v5 = v114;
LABEL_143:
            v9 = v99;
            goto LABEL_144;
          }
          goto LABEL_57;
        }
      }
      v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, v33);
      goto LABEL_47;
    }
    if ( v9 & 0x20 )
    {
      v58 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( v58 )
      {
        v60 = v58->m_Flags;
        if ( (v60 >> 14) & 1 )
        {
          v59 = v58->m_Components.p[14].m_pComponent;
        }
        else if ( (v60 & 0x8000u) == 0 )
        {
          if ( (v60 >> 13) & 1 )
          {
            v59 = v58->m_Components.p[9].m_pComponent;
          }
          else
          {
            v61 = (v60 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v58,
                                      UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v58->vfptr,
                                                                                     UFG::CompositeDrawableComponent::_TypeUID);
            v59 = v61;
          }
        }
        else
        {
          v59 = v58->m_Components.p[14].m_pComponent;
        }
      }
      else
      {
        v59 = 0i64;
      }
      v62 = *(UFG::RigResource **)&v59[21].m_TypeUID;
      if ( v62 )
      {
        v63 = UFG::GetSimulationMemoryPool();
        v64 = UFG::qMemoryPool::Allocate(v63, 0x5E0ui64, "SimComponent", 0i64, 1u);
        if ( v64 )
        {
          UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v64, v62);
          v66 = v65;
        }
        else
        {
          v66 = 0i64;
        }
        v67 = (UFG::SimObject *)v30[5];
        v68 = v67->m_Flags;
        if ( (v68 >> 14) & 1 )
        {
          v69 = 14;
        }
        else if ( (v68 & 0x8000u) == 0 )
        {
          if ( (v68 >> 13) & 1 )
            v69 = 9;
          else
            v69 = -1;
        }
        else
        {
          v69 = 14;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v111, v67, 1);
        UFG::SimObjectModifier::AttachComponent(&v111, (UFG::SimComponent *)v66, v69);
        UFG::SimObjectModifier::Close(&v111);
        UFG::SimObjectModifier::~SimObjectModifier(&v111);
        v70 = 0;
        if ( v23->mNumParts )
        {
          v71 = 0i64;
          v72 = subGraphs.p;
          do
          {
            v73 = v23->mPartDetails.mOffset;
            if ( v73 )
              v74 = (signed __int64)&v23->mPartDetails + v73;
            else
              v74 = 0i64;
            v75 = Skeleton::GetBoneID(v62->mUFGSkeleton, *(_DWORD *)(v71 + v74 + 80));
            if ( v75 != -1 )
            {
              if ( !v70 )
                *((_WORD *)v72 + 220) = v75;
              v76 = (signed __int64)&v59[22].m_SafePointerList.mNode.mNext[6];
              v77 = v59[22].m_SafePointerList.mNode.mNext[6].mNext;
              if ( v77 != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v76 )
              {
                while ( LOWORD(v77[7].mPrev) != v75 )
                {
                  v77 = v77->mNext;
                  if ( v77 == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v76 )
                    goto LABEL_130;
                }
                ModelType::AddRigidModelBinding(
                  *(ModelType **)(v66 + 1424),
                  (Illusion::ModelProxy *)&v77[1].mNext,
                  v75,
                  &UFG::qMatrix44::msIdentity,
                  0);
              }
            }
LABEL_130:
            ++v70;
            v71 += 96i64;
          }
          while ( v70 < v23->mNumParts );
          v5 = v114;
        }
        v78 = UFG::GetSimulationMemoryPool();
        v79 = UFG::qMemoryPool::Allocate(v78, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        if ( v79 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v79, v62);
          v81 = v80;
        }
        else
        {
          v81 = 0i64;
        }
        v82 = (UFG::SimObject *)*((_QWORD *)subGraphs.p + 5);
        v83 = v82->m_Flags;
        if ( (v83 >> 14) & 1 )
        {
          v84 = 9;
        }
        else if ( (v83 & 0x8000u) == 0 )
        {
          if ( (v83 >> 13) & 1 )
            v84 = 8;
          else
            v84 = -1;
        }
        else
        {
          v84 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v104, v82, 1);
        UFG::SimObjectModifier::AttachComponent(&v104, v81, v84);
        UFG::SimObjectModifier::Close(&v104);
        UFG::SimObjectModifier::~SimObjectModifier(&v104);
        goto LABEL_143;
      }
    }
LABEL_144:
    v16 = v102 + 1;
    v102 = v16;
  }
  while ( v16 < subGraphs.size );
  v7 = (UFG::FractureConnectivity *)currentOrientation.m_vec.m_quad.m128_u64[0];
LABEL_146:
  if ( subGraphs.p )
    operator delete[](subGraphs.p);
  subGraphs.p = 0i64;
  *(_QWORD *)&subGraphs.size = 0i64;
LABEL_149:
  if ( v7 && v7->mNodes.size <= 1 )
  {
    UFG::FractureConnectivity::~FractureConnectivity(v7);
    operator delete[](v7);
    v5->mCollisionMeshData->mFractureConnectivity = 0i64;
  }
LABEL_152:
  v85 = v5->mLifeSpan;
  if ( v85 >= 0.0 )
  {
    v86 = v85 - v4;
    v5->mLifeSpan = v86;
    if ( v86 < 0.0 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v104);
      v88 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v87);
      v104.mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)UFG::qStringHash64(v88, 0xFFFFFFFFFFFFFFFFui64);
      v89 = v5->mCollisionMeshData;
      if ( v89 )
        UFG::qReflectHandleBase::operator=(
          (UFG::qReflectHandleBase *)&v104,
          (UFG::qReflectHandleBase *)&v89->mObjectProperties.mPrev);
      if ( (_QWORD)v105 && *(_BYTE *)(v105 + 159) )
      {
        v90 = (UFG::PhysicsRenderHelper *)v5->mRenderComponent.m_pPointer;
        if ( v90 )
          UFG::PhysicsRenderHelper::SetToFadeOut(v90);
      }
      else
      {
        v5->mInstanceData->mFlags |= 2u;
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v5->m_pSimObject);
      }
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v104);
    }
  }
  v91 = (UFG::PhysicsRenderHelper *)v5->mRenderComponent.m_pPointer;
  if ( v91 && UFG::PhysicsRenderHelper::HasFadedOut(v91) )
  {
    v5->mInstanceData->mFlags |= 2u;
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v5->m_pSimObject);
  }
  v92 = v5->mFlags;
  if ( _bittest((const signed int *)&v92, 0xEu) && v92 & 2 )
    UFG::RigidBodyComponent::UpdateStateMachine(v5, v4);
  if ( v5->mAnimationComponent.m_pSimComponent
    && (v5->mBody || v5->mFlags & 0x800)
    && v4 > 0.0
    && !(v5->mFlags & 0xC0)
    && UFG::RigidBodyComponent::GetKeyframe(v5, (hkVector4f *)mem, (hkQuaternionf *)&subGraphs) )
  {
    if ( v5->mFlags & 0x100 )
    {
      v93 = v5->mBody;
      if ( v93 )
      {
        hkpKeyFrameUtility::applyHardKeyFrame((hkVector4f *)mem, (hkQuaternionf *)&subGraphs, 1.0 / v4, v93);
      }
      else
      {
        hkpKeyFrameUtility::KeyFrameInfo::setUsingPositionOrientationPair(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          &v5->mInstanceData->mPosition,
          &v5->mInstanceData->mOrientation,
          (hkVector4f *)mem,
          (hkQuaternionf *)&subGraphs,
          1.0 / v4);
        v5->mInstanceData->mPosition = *(hkVector4f *)mem;
        v5->mInstanceData->mOrientation = (hkQuaternionf)subGraphs;
      }
    }
    else
    {
      v94 = v5->mBody;
      if ( v94 )
      {
        *(UFG::qArray<UFG::FractureConnectivity *,0> *)((char *)&subGraphs + 8) = (UFG::qArray<UFG::FractureConnectivity *,0>)v94->m_motion.m_motionState.m_transform.m_translation;
        currentOrientation.m_vec.m_quad = (__m128)v94->m_motion.m_motionState.m_sweptTransform.m_rotation1;
        v95 = (__m128)(unsigned int)FLOAT_1_0;
        v95.m128_f32[0] = 1.0 / v4;
        hkpKeyFrameUtility::KeyFrameInfo::fastSetUsingPositionOrientationPair(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          (hkVector4f *)&subGraphs.p,
          &currentOrientation,
          (hkVector4f *)mem,
          (hkQuaternionf *)&subGraphs,
          1.0 / v4);
        hkpKeyFrameUtility::AccelerationInfo::AccelerationInfo((hkpKeyFrameUtility::AccelerationInfo *)&v104);
        *(__m128 *)&v104.mbOpen = _mm_unpacklo_ps(_mm_unpacklo_ps(v95, v95), _mm_unpacklo_ps(v95, (__m128)0i64));
        *(_OWORD *)&v104.mptrSimObject.mNext = *(_OWORD *)&v104.mbOpen;
        v105 = *(_OWORD *)&v104.mbOpen;
        v106 = *(_OWORD *)&v104.mbOpen;
        v107 = 1092616192;
        v108 = 1092616192;
        v109 = FLOAT_2_0;
        hkpKeyFrameUtility::applySoftKeyFrame(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          (hkpKeyFrameUtility::AccelerationInfo *)&v104,
          v4,
          1.0 / v4,
          v5->mBody);
      }
    }
  }
  v96 = v5->mBody;
  if ( v96 )
  {
    if ( v96->m_world )
      v5->mTimeSinceAddedToWorld = v4 + v5->mTimeSinceAddedToWorld;
  }
}

// File Line: 796
// RVA: 0x4805B0
void __fastcall UFG::RigidBodyComponent::UpdateTransforms(UFG::RigidBodyComponent *this)
{
  unsigned int v1; // esi
  UFG::RigidBodyComponent *v2; // rdi
  unsigned int v3; // esi
  UFG::SimObject *v4; // rbx
  UFG::TransformNodeComponent *v5; // rbx
  char v6; // al
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  signed __int64 v10; // rax
  hkpRigidBody *v11; // rax
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm2
  hkVector4f v14; // xmm3
  __int128 v15; // xmm0
  UFG::CollisionInstanceData *v16; // rbx
  UFG::PhysicsRenderHelper *v17; // rcx
  UFG::CollisionMeshData *v18; // rdx
  __int16 v19; // cx
  UFG::qMatrix44 *v20; // rdx
  unsigned int v21; // edx
  __int64 v22; // rsi
  UFG::TransformNodeComponent *v23; // rbx
  __int64 v24; // r14
  __m128 v25; // xmm2
  __m128i v26; // xmm0
  __m128 v27; // xmm14
  __m128 v28; // xmm15
  __m128 v29; // xmm7
  __m128 v30; // xmm6
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm8
  __m128 v34; // xmm3
  __m128 v35; // xmm11
  __m128 v36; // xmm3
  __m128 v37; // xmm11
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm9
  __m128 v41; // xmm7
  __m128 v42; // xmm9
  __m128 v43; // xmm9
  __m128 v44; // xmm6
  __m128 v45; // xmm4
  __m128 *v46; // rcx
  __m128 v47; // xmm5
  __m128 v48; // xmm0
  __m128 v49; // xmm4
  __m128 v50; // xmm12
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm10
  __m128 v54; // xmm0
  __m128 v55; // xmm10
  __m128 v56; // xmm1
  __m128 v57; // xmm11
  __m128 v58; // xmm5
  __m128 v59; // xmm11
  __m128 v60; // xmm11
  __m128 v61; // xmm11
  hkaPose *v62; // rsi
  __int64 v63; // r9
  __int64 v64; // rdx
  int v65; // eax
  __int64 v66; // r8
  __int64 v67; // r14
  signed __int64 v68; // r15
  __int64 v69; // rdx
  unsigned int *v70; // rcx
  hkQsTransformf *v71; // r12
  hkQsTransformf *v72; // r13
  hkQsTransformf *v73; // rdi
  __m128 v74; // xmm3
  __m128 v75; // xmm0
  __m128 v76; // xmm8
  __m128 v77; // xmm1
  __m128 v78; // xmm7
  __m128 v79; // xmm5
  __m128 v80; // xmm4
  __m128i v81; // xmm9
  __m128 v82; // xmm1
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __m128 v85; // xmm2
  __m128 v86; // xmm2
  __m128 v87; // xmm4
  __m128 v88; // xmm8
  __m128 v89; // xmm3
  __m128 v90; // xmm4
  __m128 v91; // xmm4
  hkQsTransformf *v92; // rax
  __int64 i; // rcx
  unsigned int *v94; // rdx
  unsigned int v95; // eax
  __m128 *v96; // rax
  __int64 v97; // r8
  hkQsTransformf *v98; // rax
  hkVector4f v99; // xmm1
  float *v100; // rax
  float v101; // xmm1_4
  float v102; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-E0h]
  float d[4]; // [rsp+30h] [rbp-D0h]
  __m128 v105; // [rsp+40h] [rbp-C0h]
  __m128 v106; // [rsp+50h] [rbp-B0h]
  hkVector4f v107; // [rsp+60h] [rbp-A0h]
  hkRotationf v108; // [rsp+70h] [rbp-90h]
  __int128 v109; // [rsp+A0h] [rbp-60h]
  hkQsTransformf v110; // [rsp+B0h] [rbp-50h]
  hkQsTransformf v111; // [rsp+E0h] [rbp-20h]
  hkTransformf transform; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 m; // [rsp+160h] [rbp+60h]
  int v114; // [rsp+280h] [rbp+180h]
  __int64 v115; // [rsp+288h] [rbp+188h]
  __int64 v116; // [rsp+290h] [rbp+190h]

  v1 = this->mFlags;
  v2 = this;
  if ( !(v1 & 0x20008) )
  {
    v3 = this->mFlags & 0x800;
    if ( !this->mBody )
    {
      if ( this->mAnimationComponent.m_pSimComponent )
      {
        v4 = this->m_pSimObject;
        if ( v4 )
        {
          v5 = v4->m_pTransformNodeComponent;
          if ( v5 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v5);
            v2->mInstanceData->mPosition.m_quad = _mm_unpacklo_ps(
                                                    _mm_unpacklo_ps(
                                                      (__m128)LODWORD(v5->mWorldTransform.v3.x),
                                                      (__m128)LODWORD(v5->mWorldTransform.v3.z)),
                                                    _mm_unpacklo_ps(
                                                      (__m128)LODWORD(v5->mWorldTransform.v3.y),
                                                      (__m128)0i64));
          }
        }
      }
    }
    if ( UFG::RigidBody::IsSleeping((UFG::RigidBody *)&v2->vfptr) || (v6 = v2->m_Flags & 3, v6 != 1) )
      v6 = 0;
    if ( v2->mAnimationComponent.m_pSimComponent || v3 || v6 )
    {
      v7 = (UFG::SimObjectGame *)v2->m_pSimObject;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, Render::SimpleDrawableComponent::_TypeUID);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, Render::SimpleDrawableComponent::_TypeUID);
          else
            v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v7,
                                    Render::SimpleDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v7->vfptr,
                                                                                   Render::SimpleDrawableComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, Render::SimpleDrawableComponent::_TypeUID);
        }
        if ( v9 )
        {
          v10 = (signed __int64)&v9[-1].m_pSimObject;
          if ( v10 )
            *(_DWORD *)(v10 + 120) |= 4u;
        }
      }
      v11 = v2->mBody;
      v2->mFlags &= 0xFFFFF7FF;
      if ( v11 )
      {
        v12.m_quad = (__m128)v11->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v108.m_col0 = v11->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v13.m_quad = (__m128)v11->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v108.m_col1 = v11->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v14.m_quad = (__m128)v11->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v108.m_col2 = v11->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v15 = (__int128)v11->m_motion.m_motionState.m_transform.m_translation;
      }
      else
      {
        v16 = v2->mInstanceData;
        hkRotationf::set(&v108, &v2->mInstanceData->mOrientation);
        v15 = (__int128)v16->mPosition;
        v14.m_quad = (__m128)v108.m_col2;
        v13.m_quad = (__m128)v108.m_col1;
        v12.m_quad = (__m128)v108.m_col0;
      }
      v17 = (UFG::PhysicsRenderHelper *)v2->mRenderComponent.m_pPointer;
      v109 = v15;
      if ( v17 )
      {
        v18 = v2->mCollisionMeshData;
        *(hkVector4f *)d = (hkVector4f)v12.m_quad;
        v105 = v13.m_quad;
        v106 = v14.m_quad;
        v107.m_quad = (__m128)v15;
        UFG::PhysicsRenderHelper::UpdateTransforms(v17, v18, (hkTransformf *)d);
      }
      v19 = v2->mFollowBoneIndex;
      if ( v19 == -1 )
      {
        hkTransformf::get4x4ColumnMajor((hkTransformf *)&v108, d);
        v20 = (UFG::qMatrix44 *)d;
LABEL_63:
        UFG::TransformNodeComponent::SetWorldTransform(
          (UFG::TransformNodeComponent *)v2->mRootTransformComponent.m_pSimComponent,
          v20);
        UFG::RigidBody::GetVelocity((UFG::RigidBody *)&v2->vfptr, &result);
        v100 = (float *)v2->mRootTransformComponent.m_pSimComponent;
        v101 = result.y;
        v102 = result.x;
        v100[66] = result.z;
        v100[65] = v101;
        v100[64] = v102;
        return;
      }
      v21 = v2->mFlags;
      if ( !_bittest((const signed int *)&v21, 8u) )
      {
        v22 = *(_QWORD *)&v2->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
        if ( v22 )
        {
          if ( !_bittest((const signed int *)&v21, 0xDu) )
          {
            v97 = *(_QWORD *)(v22 + 488);
            if ( *(_BYTE *)(*(_QWORD *)(v97 + 40) + 4i64 * v19) & 2 )
              v98 = hkaPose::calculateBoneModelSpace(*(hkaPose **)(v22 + 488), v19);
            else
              v98 = (hkQsTransformf *)(*(_QWORD *)(v97 + 24) + 48i64 * v19);
            v110.m_translation = v98->m_translation;
            v110.m_rotation = v98->m_rotation;
            v99.m_quad = (__m128)v98->m_scale;
            v107.m_quad = (__m128)v110.m_translation;
            v110.m_scale = (hkVector4f)v99.m_quad;
            hkRotationf::set((hkRotationf *)d, &v110.m_rotation);
            hkTransformf::setInverse(&transform, (hkTransformf *)d);
            hkTransformf::setMul((hkTransformf *)&v111, (hkTransformf *)&v108, &transform);
            hkTransformf::get4x4ColumnMajor((hkTransformf *)&v111, &m.v0.x);
            v20 = &m;
            goto LABEL_63;
          }
          v23 = (UFG::TransformNodeComponent *)v2->mRootTransformComponent.m_pSimComponent;
          v24 = *(_QWORD *)(*(_QWORD *)(v22 + 480) + 8i64);
          UFG::TransformNodeComponent::UpdateWorldTransform(v23);
          hkTransformf::set4x4ColumnMajor(&transform, &v23->mWorldTransform.v0.x);
          hkQsTransformf::setFromTransformNoScale(&v111, &transform);
          hkQsTransformf::setFromTransformNoScale(&v110, (hkTransformf *)&v108);
          hkVector4f::setRotatedInverseDir((hkVector4f *)d, &v111.m_rotation, &v111.m_translation);
          v25 = _mm_rcp_ps(v111.m_scale.m_quad);
          v26 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v27 = (__m128)_mm_shuffle_epi32(v26, 0);
          v28 = (__m128)_mm_shuffle_epi32(v26, 64);
          v29 = _mm_xor_ps(v28, v111.m_rotation.m_vec.m_quad);
          v30 = _mm_shuffle_ps(v29, v29, 255);
          v31 = _mm_mul_ps(v110.m_translation.m_quad, v29);
          v32 = _mm_shuffle_ps(v29, v29, 201);
          v33 = (__m128)_mm_srli_si128(
                          _mm_slli_si128(
                            (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v111.m_scale.m_quad)), v25),
                            4),
                          4);
          v34 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v110.m_translation.m_quad, v110.m_translation.m_quad, 201), v29),
                  _mm_mul_ps(v32, v110.m_translation.m_quad));
          v35 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                        _mm_shuffle_ps(v31, v31, 170)),
                      v29),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v30, v30), (__m128)xmmword_141A711B0), v110.m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v30));
          v36 = _mm_shuffle_ps(v110.m_rotation.m_vec.m_quad, v110.m_rotation.m_vec.m_quad, 255);
          v37 = _mm_add_ps(_mm_add_ps(v35, v35), _mm_xor_ps(v27, *(__m128 *)d));
          v38 = _mm_mul_ps(v36, v29);
          v39 = _mm_mul_ps(v110.m_rotation.m_vec.m_quad, v29);
          v40 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v110.m_rotation.m_vec.m_quad, v110.m_rotation.m_vec.m_quad, 201), v29),
                  _mm_mul_ps(v32, v110.m_rotation.m_vec.m_quad));
          v41 = _mm_mul_ps(v110.m_scale.m_quad, v33);
          v42 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v40, v40, 201), _mm_mul_ps(v30, v110.m_rotation.m_vec.m_quad)),
                  v38);
          v43 = _mm_shuffle_ps(
                  v42,
                  _mm_unpackhi_ps(
                    v42,
                    _mm_sub_ps(
                      _mm_mul_ps(v36, v30),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                        _mm_shuffle_ps(v39, v39, 170)))),
                  196);
          if ( v2->mFlags & 0x1000 )
          {
            v44 = _mm_shuffle_ps(v43, v43, 255);
            v45 = _mm_shuffle_ps(v43, v43, 201);
            v46 = (__m128 *)(*(_QWORD *)(v24 + 56) + 48i64 * v2->mFollowBoneIndex);
            v47 = v46[1];
            v48 = _mm_mul_ps(v45, *v46);
            v49 = _mm_mul_ps(v45, v47);
            v50 = _mm_mul_ps(v46[2], v41);
            v51 = _mm_mul_ps(*v46, v43);
            v52 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v46, *v46, 201), v43), v48);
            v53 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                          _mm_shuffle_ps(v51, v51, 170)),
                        v43),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v44, v44), (__m128)xmmword_141A711B0), *v46)),
                    _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v44));
            v54 = _mm_mul_ps(v44, v47);
            v55 = _mm_add_ps(_mm_add_ps(v53, v53), v37);
            v56 = _mm_shuffle_ps(v46[1], v47, 255);
            v57 = _mm_shuffle_ps(v46[1], v47, 201);
            v58 = _mm_mul_ps(v47, v43);
            v59 = _mm_sub_ps(_mm_mul_ps(v57, v43), v49);
            v60 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v59, v59, 201), v54), _mm_mul_ps(v56, v43));
            v61 = _mm_shuffle_ps(
                    v60,
                    _mm_unpackhi_ps(
                      v60,
                      _mm_sub_ps(
                        _mm_mul_ps(v56, v44),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                          _mm_shuffle_ps(v58, v58, 170)))),
                    196);
          }
          else
          {
            v55 = v37;
            v50 = v41;
            v61 = v43;
          }
          v62 = *(hkaPose **)(v22 + 488);
          v63 = v2->mFollowBoneIndex;
          v116 = v2->mFollowBoneIndex;
          v64 = v62->m_skeleton->m_bones.m_size;
          v62->m_boneFlags.m_data[v63] |= 4u;
          v65 = v63 + 1;
          v66 = v64;
          v67 = (signed int)v63 + 1;
          v114 = v63 + 1;
          v115 = v64;
          if ( v67 < v64 )
          {
            v68 = v65;
            do
            {
              LOWORD(v69) = v62->m_skeleton->m_parentIndices.m_data[v67];
              if ( (_WORD)v69 != -1 )
              {
                v70 = v62->m_boneFlags.m_data;
                if ( v70[(signed __int16)v69] & 4 )
                {
                  if ( v70[v67] & 1 )
                  {
                    v71 = v62->m_modelPose.m_data;
                    if ( (_WORD)v69 == -1 )
                    {
                      v92 = v62->m_localPose.m_data;
                      v92[v68].m_translation = v71[v68].m_translation;
                      v92[v68].m_rotation = v71[v68].m_rotation;
                      v92[v68].m_scale = v71[v68].m_scale;
                    }
                    else
                    {
                      v69 = (signed __int16)v69;
                      if ( v70[(signed __int16)v69] & 2 )
                        v72 = hkaPose::calculateBoneModelSpace(v62, v69);
                      else
                        v72 = &v71[v69];
                      v73 = v62->m_localPose.m_data;
                      hkVector4f::setRotatedInverseDir((hkVector4f *)d, &v72->m_rotation, &v72->m_translation);
                      v74 = v71[v68].m_translation.m_quad;
                      v75 = v72->m_scale.m_quad;
                      v76 = _mm_xor_ps(v28, v72->m_rotation.m_vec.m_quad);
                      v77 = _mm_rcp_ps(v75);
                      v78 = _mm_shuffle_ps(v76, v76, 255);
                      v79 = _mm_shuffle_ps(v76, v76, 201);
                      v80 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v76), _mm_mul_ps(v79, v74));
                      v81 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v75, v77)), v77), 4);
                      v82 = _mm_mul_ps(v76, v74);
                      v83 = _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                              _mm_shuffle_ps(v82, v82, 170));
                      v84 = v76;
                      v85 = _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(v83, v76),
                                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v78, v78), (__m128)xmmword_141A711B0), v74)),
                              _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v78));
                      v73[v68].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v85, v85), _mm_xor_ps(v27, *(__m128 *)d));
                      v86 = v71[v68].m_rotation.m_vec.m_quad;
                      v87 = _mm_mul_ps(_mm_shuffle_ps(v86, v86, 201), v76);
                      v88 = _mm_mul_ps(v76, v86);
                      v89 = _mm_shuffle_ps(v71[v68].m_rotation.m_vec.m_quad, v86, 255);
                      v90 = _mm_sub_ps(v87, _mm_mul_ps(v79, v86));
                      v91 = _mm_add_ps(
                              _mm_add_ps(
                                _mm_shuffle_ps(v90, v90, 201),
                                _mm_mul_ps(v71[v68].m_rotation.m_vec.m_quad, v78)),
                              _mm_mul_ps(v84, v89));
                      v73[v68].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                           v91,
                                                           _mm_unpackhi_ps(
                                                             v91,
                                                             _mm_sub_ps(
                                                               _mm_mul_ps(v89, v78),
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_shuffle_ps(v88, v88, 85),
                                                                   _mm_shuffle_ps(v88, v88, 0)),
                                                                 _mm_shuffle_ps(v88, v88, 170)))),
                                                           196);
                      v73[v68].m_scale.m_quad = _mm_mul_ps(v71[v68].m_scale.m_quad, (__m128)_mm_srli_si128(v81, 4));
                      v66 = v115;
                    }
                    v62->m_boneFlags.m_data[v67] &= 0xFFFFFFFE;
                  }
                  v62->m_boneFlags.m_data[v67] |= 4u;
                  v62->m_modelInSync.m_bool = 0;
                }
              }
              ++v67;
              ++v68;
            }
            while ( v67 < v66 );
            v63 = v116;
            v65 = v114;
          }
          for ( i = v65; i < v66; ++i )
          {
            v94 = v62->m_boneFlags.m_data;
            v95 = v94[i];
            if ( v95 & 4 )
              v94[i] = v95 & 0xFFFFFFFB | 2;
          }
          v96 = &v62->m_modelPose.m_data[v63].m_translation.m_quad;
          *v96 = v55;
          v96[1] = v61;
          v96[2] = v50;
          v62->m_boneFlags.m_data[v63] = 1;
          v62->m_localInSync.m_bool = 0;
        }
      }
    }
  }
}

// File Line: 994
// RVA: 0x474070
void __fastcall UFG::RigidBodyComponent::RestoreCollisionFilter(UFG::RigidBodyComponent *this)
{
  UFG::RigidBodyComponent *v1; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v2; // rcx
  const char *v3; // rax
  UFG::CollisionMeshData *v4; // rdx
  unsigned int v5; // ecx
  hkpRigidBody *v6; // rax
  hkpEntity *v7; // rdx
  hkpWorld *v8; // rcx
  UFG::qReflectHandleBase v9; // [rsp+28h] [rbp-30h]

  v1 = this;
  this->mCollisionLayerOverride = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(&v9);
  v3 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v2);
  v9.mTypeUID = UFG::qStringHash64(v3, 0xFFFFFFFFFFFFFFFFui64);
  v4 = v1->mCollisionMeshData;
  if ( v4 )
    UFG::qReflectHandleBase::operator=(&v9, (UFG::qReflectHandleBase *)&v4->mObjectProperties.mPrev);
  v5 = (unsigned int)v9.mData[2].mBaseNode.mChildren[0];
  v6 = v1->mBody;
  if ( v6 )
  {
    if ( v6->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v5 )
    {
      v6->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v5;
      v7 = (hkpEntity *)&v1->mBody->vfptr;
      v8 = v7->m_world;
      if ( v8 )
        hkpWorld::updateCollisionFilterOnEntity(v8, v7, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    }
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v9);
}

// File Line: 1045
// RVA: 0x46D870
void __fastcall UFG::RigidBodyComponent::NotifyProxyModeChanged(UFG::RigidBodyComponent *this, UFG::SimObject::eProxyMode proxyMode)
{
  UFG::RigidBodyComponent *v2; // rbx

  v2 = this;
  if ( proxyMode == 2 )
  {
    if ( LODWORD(this->mCollisionMeshData->mObjectProperties.mData[2].mBaseNode.mChildren[1]) == 2 )
      UFG::RigidBody::SetMotionType((UFG::RigidBody *)&this->vfptr, 256u);
    UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)&v2->vfptr, 1u, -1, -1, -1);
  }
  else
  {
    UFG::RigidBody::SetMotionType((UFG::RigidBody *)&this->vfptr, 128u);
    UFG::RigidBodyComponent::RestoreCollisionFilter(v2);
  }
}

// File Line: 1065
// RVA: 0x4609B0
void __fastcall UFG::RigidBodyComponent::Delete(UFG::RigidBodyComponent *this)
{
  UFG::RigidBodyComponent *v1; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v2; // rcx
  const char *v3; // rax
  UFG::CollisionMeshData *v4; // rdx
  UFG::SimObject *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::PhysicsRenderHelper *v11; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v12; // rdx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v13; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v14; // rax
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v15);
  v3 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v2);
  v15.mTypeUID = UFG::qStringHash64(v3, 0xFFFFFFFFFFFFFFFFui64);
  v4 = v1->mCollisionMeshData;
  if ( v4 )
    UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)&v4->mObjectProperties.mPrev);
  v1->mInstanceData->mFlags |= 2u;
  v5 = v1->m_pSimObject;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[9].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = v5->m_Components.p[8].m_pComponent;
      }
      else
      {
        v8 = ((v6 >> 12) & 1) == 0;
        v9 = (UFG::SimObjectGame *)v1->m_pSimObject;
        v7 = v8 ? UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v9->vfptr,
                    UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v9,
                                                               UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v7 = v5->m_Components.p[9].m_pComponent;
    }
    if ( v7 )
    {
      v10 = v7[2].m_SafePointerList.mNode.mNext;
      if ( v10 )
        LODWORD(v10[5].mPrev) |= 1u;
    }
  }
  if ( HIBYTE(v15.mData[1].mHandles.mNode.mNext)
    && (v11 = (UFG::PhysicsRenderHelper *)v1->mRenderComponent.m_pPointer) != 0i64 )
  {
    UFG::PhysicsRenderHelper::SetToFadeOut(v11);
  }
  else
  {
    if ( v1 == UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator )
      UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator = (UFG::RigidBodyComponent *)&v1->mPrev[-18].mNext;
    v12 = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&v1->mPrev;
    v13 = v1->mPrev;
    v14 = v1->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = v12;
    v12->mNext = v12;
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v5);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
}

// File Line: 1096
// RVA: 0x47FF20
void __fastcall UFG::RigidBodyComponent::UpdateStateMachine(UFG::RigidBodyComponent *this, float deltaTime)
{
  UFG::RigidBodyComponent *v2; // rbx
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-58h]

  v2 = this;
  if ( this->mStateMachineComponent.m_pPointer )
  {
    UFG::RigidBody::GetTransform((UFG::RigidBody *)&this->vfptr, &mat);
    if ( (unsigned __int8)UFG::StateMachineComponent::Update(
                            (UFG::StateMachineComponent *)v2->mStateMachineComponent.m_pPointer,
                            &mat,
                            deltaTime) )
      UFG::RigidBodyComponent::Delete(v2);
  }
  if ( v2->mBody )
    v2->mFlags &= 0xFFFFFFCF;
}

// File Line: 1120
// RVA: 0x465580
UFG::SimObject *__usercall UFG::RigidBodyComponent::FracturePart@<rax>(UFG::RigidBodyComponent *this@<rcx>, unsigned int index@<edx>, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *a3@<rsi>)
{
  unsigned int v3; // edi
  UFG::RigidBodyComponent *v4; // r13
  BitArray256 *v5; // r8
  UFG::CollisionMeshData *v6; // rbx
  __int64 v7; // rax
  __int64 v8; // r9
  unsigned int v9; // ecx
  unsigned int v10; // edx
  float v11; // xmm1_4
  UFG::SimComponent *v12; // rax
  float v13; // xmm0_4
  hkpRigidBody *v14; // rax
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm2
  hkVector4f v17; // xmm3
  UFG::SimComponent *v18; // r12
  UFG::ParkourContainer *v19; // r12
  int v20; // edi
  int v21; // esi
  __int64 v22; // rbx
  hkVector4f v23; // xmm6
  hkVector4f v24; // xmm7
  UFG::ParkourComponent *v25; // r15
  UFG::ParkourData *v26; // r14
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  UFG::qBaseNodeRB *v29; // r13
  __int64 v30; // r12
  UFG::ParkourComponent *v31; // rsi
  UFG::ParkourContainer *v32; // rax
  int v33; // edi
  int v34; // er14
  __int64 v35; // rbx
  hkVector4f v36; // xmm6
  hkVector4f v37; // xmm7
  UFG::ParkourData *v38; // r15
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  UFG::CollisionInstanceData *v41; // rax
  UFG::CollisionInstanceData::Part *v42; // rbx
  UFG::StateMachineComponent *v43; // rcx
  UFG::SimObject *v44; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v46; // rax
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> output; // [rsp+30h] [rbp-D0h]
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> v49; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 queryAabbMin; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 queryAabbMax; // [rsp+60h] [rbp-A0h]
  hkAabb aabbOut; // [rsp+70h] [rbp-90h]
  UFG::qVector3 v0; // [rsp+90h] [rbp-70h]
  __int64 v54; // [rsp+A0h] [rbp-60h]
  hkTransformf localToWorld; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 mat; // [rsp+F0h] [rbp-10h]
  UFG::RigidBodyComponent *v57; // [rsp+1B0h] [rbp+B0h]
  int subPartIndex; // [rsp+1B8h] [rbp+B8h]
  UFG::qBaseNodeRB *v59; // [rsp+1C0h] [rbp+C0h]
  UFG::ParkourContainer *v60; // [rsp+1C8h] [rbp+C8h]

  subPartIndex = index;
  v57 = this;
  v54 = -2i64;
  v3 = index;
  v4 = this;
  v5 = this->mFractureState;
  if ( !v5 )
    return 0i64;
  v6 = this->mCollisionMeshData;
  if ( !v6 )
    return 0i64;
  v7 = v6->mPartDetails.mOffset;
  if ( !v7 )
    return 0i64;
  if ( !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v6->mPartDetails + v7) )
    return 0i64;
  v8 = index >> 5;
  v9 = index & 0x1F;
  v10 = v5->mBits[v8];
  if ( _bittest((const signed int *)&v10, v9) )
    return 0i64;
  v5->mBits[v8] |= 1 << v9;
  v11 = (float)(1.0 / (float)(signed int)UFG::RigidBody::GetNumFracturableParts((UFG::RigidBody *)&v4->vfptr))
      + 0.0099999998;
  v12 = v4->mStateMachineComponent.m_pPointer;
  if ( v12 )
  {
    if ( v11 > 0.0 )
    {
      if ( *(_QWORD *)&v12[2].m_TypeUID )
      {
        v13 = *((float *)&v12[4].m_SafePointerList.mNode.mPrev + 1) - v11;
        *((float *)&v12[4].m_SafePointerList.mNode.mPrev + 1) = v13;
        if ( v13 < 0.0 )
          HIDWORD(v12[4].m_SafePointerList.mNode.mPrev) = 0;
      }
    }
  }
  if ( !(_S15_0 & 1) )
  {
    _S15_0 |= 1u;
    worldStaticDestructable = UFG::qStringHashUpper32("WorldStaticDestructable", 0xFFFFFFFF);
  }
  v14 = v4->mBody;
  v15.m_quad = (__m128)v14->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v16.m_quad = (__m128)v14->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v17.m_quad = (__m128)v14->m_motion.m_motionState.m_transform.m_translation;
  localToWorld.m_rotation.m_col0 = v14->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  localToWorld.m_rotation.m_col1 = (hkVector4f)v15.m_quad;
  localToWorld.m_rotation.m_col2 = (hkVector4f)v16.m_quad;
  localToWorld.m_translation = (hkVector4f)v17.m_quad;
  UFG::GetAabbFromShapeKey(&aabbOut, &localToWorld, v6->mShape, v3);
  aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, (__m128)_xmm);
  aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, (__m128)_xmm);
  LODWORD(queryAabbMin.x) = aabbOut.m_min.m_quad.m128_i32[0];
  LODWORD(queryAabbMin.y) = (unsigned __int128)_mm_shuffle_ps(aabbOut.m_min.m_quad, aabbOut.m_min.m_quad, 85);
  LODWORD(queryAabbMin.z) = (unsigned __int128)_mm_shuffle_ps(aabbOut.m_min.m_quad, aabbOut.m_min.m_quad, 170);
  queryAabbMax.x = aabbOut.m_max.m_quad.m128_f32[0];
  LODWORD(queryAabbMax.y) = (unsigned __int128)_mm_shuffle_ps(aabbOut.m_max.m_quad, aabbOut.m_max.m_quad, 85);
  LODWORD(queryAabbMax.z) = (unsigned __int128)_mm_shuffle_ps(aabbOut.m_max.m_quad, aabbOut.m_max.m_quad, 170);
  UFG::RigidBody::GetTransform((UFG::RigidBody *)&v4->vfptr, &mat);
  v18 = v4->mParkourComponent.m_pPointer;
  if ( v18 )
  {
    v19 = *(UFG::ParkourContainer **)&v18[1].m_Flags;
    output.m_data = 0i64;
    output.m_size = 0;
    output.m_capacityAndFlags = 2147483648;
    UFG::ParkourContainer::Query(
      v19,
      (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer,
      &queryAabbMin,
      &queryAabbMax,
      a3,
      &output);
    v20 = 0;
    v21 = output.m_size;
    if ( output.m_size > 0 )
    {
      v22 = 0i64;
      v23.m_quad = (__m128)aabbOut.m_max;
      v24.m_quad = (__m128)aabbOut.m_min;
      do
      {
        v25 = (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer;
        v26 = output.m_data[v22];
        UFG::ParkourContainer::GetVerts(
          v19,
          (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer,
          &mat,
          output.m_data[v22],
          &queryAabbMin,
          &queryAabbMax);
        v27 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMin.x), (__m128)LODWORD(queryAabbMin.z)),
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMin.y), (__m128)(unsigned int)FLOAT_1_0));
        v28 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMax.x), (__m128)LODWORD(queryAabbMax.z)),
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMax.y), (__m128)(unsigned int)FLOAT_1_0));
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, v23.m_quad), _mm_cmpleps(v24.m_quad, v27))) & 7) == 7
          && (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v28, v23.m_quad), _mm_cmpleps(v24.m_quad, v28))) & 7) == 7 )
        {
          UFG::ParkourComponent::Disable(v25, v26);
          UFG::ParkourQueryManager::RemoveCachedHandle(
            UFG::ParkourQueryManager::mInstance,
            (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer,
            output.m_data[v22]);
          v23.m_quad = (__m128)aabbOut.m_max;
          v24.m_quad = (__m128)aabbOut.m_min;
          v21 = output.m_size;
        }
        ++v20;
        ++v22;
      }
      while ( v20 < v21 );
    }
    output.m_size = 0;
    if ( output.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        output.m_data,
        8 * output.m_capacityAndFlags);
    output.m_data = 0i64;
    output.m_capacityAndFlags = 2147483648;
    v3 = subPartIndex;
  }
  else if ( HIDWORD(v6->mObjectProperties.mData[4].mBaseNode.mParent) == worldStaticDestructable )
  {
    v29 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gParkourInstanceInventory->mResourceDatas);
    v59 = v29;
    if ( v29 )
    {
      do
      {
        v30 = 0i64;
        if ( v29[2].mUID )
        {
          do
          {
            v31 = (UFG::ParkourComponent *)*((_QWORD *)&v29[3].mParent[2].mParent + 10 * v30);
            v32 = (UFG::ParkourContainer *)v31->mParkourContainer.mData;
            v60 = (UFG::ParkourContainer *)v31->mParkourContainer.mData;
            v49.m_data = 0i64;
            v49.m_size = 0;
            v49.m_capacityAndFlags = 2147483648;
            UFG::ParkourContainer::Query(
              v32,
              v31,
              &queryAabbMin,
              &queryAabbMax,
              (hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *)v31,
              &v49);
            v33 = 0;
            v34 = v49.m_size;
            if ( v49.m_size > 0 )
            {
              v35 = 0i64;
              v36.m_quad = (__m128)aabbOut.m_max;
              v37.m_quad = (__m128)aabbOut.m_min;
              do
              {
                v38 = v49.m_data[v35];
                UFG::ParkourContainer::GetVerts(v60, v31, &mat, v49.m_data[v35], &v0, (UFG::qVector3 *)&output);
                v39 = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(v0.x), (__m128)LODWORD(v0.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(v0.y), (__m128)(unsigned int)FLOAT_1_0));
                v40 = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(output.m_data), (__m128)(unsigned int)output.m_size),
                        _mm_unpacklo_ps((__m128)HIDWORD(output.m_data), (__m128)(unsigned int)FLOAT_1_0));
                if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v39, v36.m_quad), _mm_cmpleps(v37.m_quad, v39))) & 7) == 7
                  && (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v40, v36.m_quad), _mm_cmpleps(v37.m_quad, v40))) & 7) == 7 )
                {
                  UFG::ParkourComponent::Disable(v31, v38);
                  UFG::ParkourQueryManager::RemoveCachedHandle(
                    UFG::ParkourQueryManager::mInstance,
                    v31,
                    v49.m_data[v35]);
                  v36.m_quad = (__m128)aabbOut.m_max;
                  v37.m_quad = (__m128)aabbOut.m_min;
                  v34 = v49.m_size;
                }
                ++v33;
                ++v35;
              }
              while ( v33 < v34 );
              v29 = v59;
            }
            v49.m_size = 0;
            if ( v49.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v49.m_data,
                8 * v49.m_capacityAndFlags);
            v49.m_data = 0i64;
            v49.m_capacityAndFlags = 2147483648;
            v30 = (unsigned int)(v30 + 1);
          }
          while ( (unsigned int)v30 < v29[2].mUID );
        }
        v29 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(&UFG::gParkourInstanceInventory->mResourceDatas.mTree, v29);
        v59 = v29;
      }
      while ( v29 );
      v3 = subPartIndex;
    }
    v4 = v57;
  }
  v41 = v4->mInstanceData;
  if ( !v41->mNumParts )
    return 0i64;
  v42 = &v41->mParts[v3];
  v43 = (UFG::StateMachineComponent *)v4->mStateMachineComponent.m_pPointer;
  if ( v43 )
    UFG::StateMachineComponent::DeleteChildMachine(v43, v3);
  v44 = v42->mSimObject.m_pPointer;
  if ( !v44 )
    return 0i64;
  v45 = v42->mSimObject.mPrev;
  v46 = v42->mSimObject.mNext;
  v45->mNext = v46;
  v46->mPrev = v45;
  v42->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mSimObject.mPrev;
  v42->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v42->mSimObject.mPrev;
  v42->mSimObject.m_pPointer = 0i64;
  return v44;
}

// File Line: 1248
// RVA: 0x46EDB0
UFG::RigidBody *__usercall UFG::RigidBodyComponent::OnRemovePart@<rax>(UFG::RigidBodyComponent *this@<rcx>, UFG::BreakoffPart *breakOffPart@<rdx>, UFG::CollisionMeshData::PartDetails *partDetails@<r8>, unsigned int instanceGuid@<r9d>, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *a5@<rsi>)
{
  unsigned int v5; // er15
  UFG::CollisionMeshData::PartDetails *v6; // r13
  UFG::BreakoffPart *v7; // r12
  UFG::RigidBodyComponent *v8; // r14
  bool v9; // bl
  UFG::SimObject *v10; // rax
  UFG::SimObject *v11; // rsi
  UFG::SimComponent *v12; // rdi
  UFG::PhysicsRenderHelper *v13; // rcx
  UFG::SimObjectGame *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::CompositeDrawableComponent *v19; // rax
  ModelType *v20; // rcx
  UFG::StateMachineComponent *v21; // rcx
  UFG::RigidBody *v22; // r13
  UFG::qBaseTreeRB *v23; // r15
  UFG::allocator::free_link *v24; // rax
  UFG::CollisionInstanceData *v25; // rax
  UFG::CollisionInstanceData *v26; // rbx
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  hkpShape *v31; // rcx
  UFG::SimObject *v32; // ST28_8
  char v33; // si
  UFG::SimObjectGame *v34; // rcx
  unsigned __int16 v35; // dx
  UFG::SimComponent *v36; // rax
  Render::SimpleDrawableComponent *v37; // rsi
  unsigned int v38; // ebx
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  unsigned int *v41; // r12
  unsigned int *v42; // rcx
  unsigned int i; // er8
  unsigned __int64 v44; // rbx
  UFG::qMemoryPool *v45; // rax
  UFG::allocator::free_link *v46; // rax
  __int64 v47; // rax
  __int64 v48; // rbx
  UFG::SimObject *v49; // rdx
  unsigned __int16 v50; // cx
  UFG::SimComponent *v51; // rdx
  UFG::SimObjectGame *v52; // rcx
  UFG::SimComponent *v53; // rbx
  unsigned __int16 v54; // dx
  UFG::SimComponent *v55; // rax
  UFG::RigResource *v56; // r15
  unsigned int v57; // eax
  unsigned int v58; // esi
  UFG::allocator::free_link *v59; // rax
  UFG::SimComponent *v60; // rax
  UFG::SimObject *v61; // rdx
  unsigned __int16 v62; // cx
  unsigned int v63; // er12
  unsigned int v64; // er15
  signed __int64 v65; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v66; // rdx
  UFG::allocator::free_link *v67; // rax
  UFG::SimComponent *v68; // rax
  UFG::SimObject *v69; // rdx
  unsigned __int16 v70; // cx
  hkpRigidBody *v71; // rbx
  hkpEntity *v72; // rdi
  hkpRigidBody *v73; // rbx
  UFG::FractureConnectivity *v74; // rcx
  __int64 check_null; // [rsp+20h] [rbp-E0h]
  UFG::qArray<unsigned long,0> nameUidFilter; // [rsp+30h] [rbp-D0h]
  UFG::allocator::free_link *v78; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 pos; // [rsp+48h] [rbp-B8h]
  UFG::SimObjectModifier v80; // [rsp+58h] [rbp-A8h]
  hkMassProperties massProperties; // [rsp+80h] [rbp-80h]
  __int64 v82; // [rsp+D0h] [rbp-30h]
  hkTransformf v83; // [rsp+E0h] [rbp-20h]
  hkTransformf transformOut; // [rsp+120h] [rbp+20h]
  UFG::SimComponent *component; // [rsp+1B0h] [rbp+B0h]
  UFG::BreakoffPart *v86; // [rsp+1B8h] [rbp+B8h]
  UFG::CollisionMeshData::PartDetails *v87; // [rsp+1C0h] [rbp+C0h]
  unsigned int v88; // [rsp+1C8h] [rbp+C8h]

  v88 = instanceGuid;
  v87 = partDetails;
  v86 = breakOffPart;
  v82 = -2i64;
  v5 = instanceGuid;
  v6 = partDetails;
  v7 = breakOffPart;
  v8 = this;
  LODWORD(v78) = 10;
  v9 = breakOffPart->newRigidBody != 0i64;
  UFG::GetTransformFromShapeKey(&transformOut, this->mCollisionMeshData->mShape, breakOffPart->shapeKey);
  hkTransformf::setMul(&v83, &v7->breakingRigidBody->m_motion.m_motionState.m_transform, &transformOut);
  v8->mFlags |= 0x20u;
  v10 = UFG::RigidBodyComponent::FracturePart(v8, v7->shapeKey, a5);
  v11 = v10;
  v12 = 0i64;
  if ( v10 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v10);
    v11 = 0i64;
  }
  v13 = (UFG::PhysicsRenderHelper *)v8->mRenderComponent.m_pPointer;
  if ( v13 )
  {
    UFG::PhysicsRenderHelper::DisableDynamicScenery(v13, v5);
  }
  else
  {
    v14 = (UFG::SimObjectGame *)v8->m_pSimObject;
    if ( v14
      && ((v15 = v14->m_Flags, !((v15 >> 14) & 1)) ? ((v15 & 0x8000u) == 0 ? (!((v15 >> 13) & 1) ? (!((v15 >> 12) & 1) ? (v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, Render::SimpleDrawableComponent::_TypeUID)) : (v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, Render::SimpleDrawableComponent::_TypeUID))) : (v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, Render::SimpleDrawableComponent::_TypeUID))) : (v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, Render::SimpleDrawableComponent::_TypeUID))) : (v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, Render::SimpleDrawableComponent::_TypeUID)),
          v16 && v16 != (UFG::SimComponent *)24) )
    {
      Render::SimpleDrawableComponent::SetVisibility(
        (Render::SimpleDrawableComponent *)&v16[-1].m_pSimObject,
        v6->mRenderModelGuid,
        0);
      LODWORD(v78) = 26;
    }
    else
    {
      v17 = (UFG::SimObjectGame *)v8->m_pSimObject;
      if ( v17
        && ((v18 = v17->m_Flags, !((v18 >> 14) & 1)) ? ((v18 & 0x8000u) == 0 ? (!((v18 >> 13) & 1) ? (!((v18 >> 12) & 1) ? (v19 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::CompositeDrawableComponent::_TypeUID)) : (v19 = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::CompositeDrawableComponent::_TypeUID))) : (v19 = (UFG::CompositeDrawableComponent *)v17->m_Components.p[9].m_pComponent)) : (v19 = (UFG::CompositeDrawableComponent *)v17->m_Components.p[14].m_pComponent)) : (v19 = (UFG::CompositeDrawableComponent *)v17->m_Components.p[14].m_pComponent),
            v19) )
      {
        if ( v8->mFollowBoneIndex == -1 )
        {
          UFG::CompositeDrawableComponent::SetIsHidden(v19, 1);
        }
        else
        {
          v20 = v19->mModelType[0];
          if ( v20 )
            ModelType::SetRigidModelVisibilityOnBone(v20, v6->mRenderModelGuid, 0);
        }
        LODWORD(v78) = 42;
      }
      else
      {
        pos = *(UFG::qVector3 *)v83.m_translation.m_quad.m128_f32;
        UFG::PhysicsSystem::DisableStaticSceneryInstance(
          (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
          v5,
          &pos);
      }
    }
  }
  if ( v9 )
  {
    v21 = (UFG::StateMachineComponent *)v8->mStateMachineComponent.m_pPointer;
    if ( v21 )
      UFG::StateMachineComponent::FractureNotification(v21, v6->mSceneNodeNameUC.mUID);
  }
  v22 = 0i64;
  if ( v9 )
  {
    v23 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v87->mCollisionModelUid);
    v24 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
    if ( v24 )
    {
      UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v24);
      v26 = v25;
    }
    else
    {
      v26 = 0i64;
    }
    v26->mCollisionModelGuid = v87->mCollisionModelUid;
    v26->mFlags = 0;
    hkQuaternionf::set(&v26->mOrientation, &v83.m_rotation);
    v27 = _mm_mul_ps(v26->mOrientation.m_vec.m_quad, v26->mOrientation.m_vec.m_quad);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
    v30 = _mm_rsqrt_ps(v29);
    v26->mOrientation.m_vec.m_quad = _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v30)),
                                       v26->mOrientation.m_vec.m_quad);
    v26->mPosition = v83.m_translation;
    v26->mInstanceGuid = v88;
    v26->mSimObjectName.mUID = (unsigned int)v23[3].mRoot.mParent;
    if ( !v23[2].mNULL.mChild[1] )
    {
      v31 = v7->newRigidBody->m_collidable.m_shape;
      if ( v31->m_type.m_storage == 11 )
        v31 = *(hkpShape **)&v31[1].m_type.m_storage;
      v23[2].mNULL.mChild[1] = (UFG::qBaseNodeRB *)v31;
    }
    v32 = v11;
    LODWORD(check_null) = v8->mFlags & 0x400;
    v33 = (char)v78;
    v22 = UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld(
            UFG::BasePhysicsSystem::mInstance,
            v26,
            (UFG::CollisionMeshData *)v23,
            (unsigned int)v78,
            check_null,
            v32);
    if ( (unsigned __int8)v78 & 0x10 )
    {
      v34 = (UFG::SimObjectGame *)v8->m_pSimObject;
      if ( !v34
        || ((v35 = v34->m_Flags, !((v35 >> 14) & 1)) ? ((v35 & 0x8000u) == 0 ? (!((v35 >> 13) & 1) ? (!((v35 >> 12) & 1) ? (v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v34->vfptr, Render::SimpleDrawableComponent::_TypeUID)) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, Render::SimpleDrawableComponent::_TypeUID))) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, Render::SimpleDrawableComponent::_TypeUID))) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, Render::SimpleDrawableComponent::_TypeUID))) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, Render::SimpleDrawableComponent::_TypeUID)),
            v37 = (Render::SimpleDrawableComponent *)&v36[-1].m_pSimObject,
            !v36) )
      {
        v37 = 0i64;
      }
      nameUidFilter.p = 0i64;
      *(_QWORD *)&nameUidFilter.size = 0i64;
      pos.x = *((float *)&v23[1].mRoot.mParent + 1);
      v38 = 1;
      if ( v38 <= 4 )
        v38 = 4;
      if ( v38 - 1 > 0x10000 )
        v38 = 65537;
      if ( v38 )
      {
        v39 = 4i64 * v38;
        if ( !is_mul_ok(v38, 4ui64) )
          v39 = -1i64;
        v40 = UFG::qMalloc(v39, "qArray.Add", 0i64);
        v41 = (unsigned int *)v40;
        v42 = nameUidFilter.p;
        if ( nameUidFilter.p )
        {
          for ( i = 0; i < nameUidFilter.size; v42 = nameUidFilter.p )
          {
            *((_DWORD *)&v40->mNext + i) = v42[i];
            ++i;
          }
          operator delete[](v42);
        }
        nameUidFilter.p = v41;
        nameUidFilter.capacity = v38;
      }
      else
      {
        v41 = nameUidFilter.p;
      }
      nameUidFilter.size = 1;
      *v41 = LODWORD(pos.x);
      v44 = UFG::UIHKPlayerObjective::GetObjective(v37)->mBaseNode.mUID;
      v45 = UFG::GetSimulationMemoryPool();
      v46 = UFG::qMemoryPool::Allocate(v45, 0x100ui64, "SimComponent", 0i64, 1u);
      if ( v46 )
      {
        Render::SimpleDrawableComponent::SimpleDrawableComponent(
          (Render::SimpleDrawableComponent *)v46,
          v44,
          &nameUidFilter);
        v48 = v47;
      }
      else
      {
        v48 = 0i64;
      }
      v49 = v22->m_pSimObject;
      v50 = v49->m_Flags;
      UFG::SimObjectModifier::SimObjectModifier(&v80, v49, 1);
      v51 = (UFG::SimComponent *)(v48 + 24);
      if ( !v48 )
        v51 = 0i64;
      UFG::SimObjectModifier::AttachComponent(&v80, v51, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v80);
      UFG::SimObjectModifier::~SimObjectModifier(&v80);
      if ( nameUidFilter.p )
        operator delete[](nameUidFilter.p);
      nameUidFilter.p = 0i64;
      *(_QWORD *)&nameUidFilter.size = 0i64;
      v7 = v86;
      v33 = (char)v78;
    }
    if ( v33 & 0x20 )
    {
      v52 = (UFG::SimObjectGame *)v8->m_pSimObject;
      if ( v52 )
      {
        v54 = v52->m_Flags;
        if ( (v54 >> 14) & 1 )
        {
          v53 = v52->m_Components.p[14].m_pComponent;
        }
        else if ( (v54 & 0x8000u) == 0 )
        {
          if ( (v54 >> 13) & 1 )
          {
            v53 = v52->m_Components.p[9].m_pComponent;
          }
          else
          {
            v55 = (v54 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v52,
                                      UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v52->vfptr,
                                                                                     UFG::CompositeDrawableComponent::_TypeUID);
            v53 = v55;
          }
        }
        else
        {
          v53 = v52->m_Components.p[14].m_pComponent;
        }
      }
      else
      {
        v53 = 0i64;
      }
      v56 = *(UFG::RigResource **)&v53[21].m_TypeUID;
      *(_QWORD *)&pos.x = v56;
      if ( v56 )
      {
        v57 = Skeleton::GetBoneID(v56->mUFGSkeleton, v87->mRenderModelGuid);
        v58 = v57;
        if ( v57 != -1 )
        {
          LOWORD(v22[1].mCollisionMeshData) = v57;
          v59 = UFG::SimComponent::operator new(0x5E0ui64);
          v78 = v59;
          if ( v59 )
          {
            UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v59, v56);
            component = v60;
          }
          else
          {
            component = 0i64;
          }
          v61 = v22->m_pSimObject;
          v62 = v61->m_Flags;
          v63 = 9;
          if ( (v62 >> 14) & 1 )
          {
            v64 = 14;
          }
          else if ( (v62 & 0x8000u) == 0 )
          {
            if ( (v62 >> 13) & 1 )
              v64 = 9;
            else
              v64 = -1;
          }
          else
          {
            v64 = 14;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v80, v61, 1);
          UFG::SimObjectModifier::AttachComponent(&v80, component, v64);
          UFG::SimObjectModifier::Close(&v80);
          UFG::SimObjectModifier::~SimObjectModifier(&v80);
          v65 = (signed __int64)&v53[22].m_SafePointerList.mNode.mNext[6];
          v66 = v53[22].m_SafePointerList.mNode.mNext[6].mNext;
          if ( v66 != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v65 )
          {
            while ( LOWORD(v66[7].mPrev) != v58 )
            {
              v66 = v66->mNext;
              if ( v66 == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v65 )
                goto LABEL_112;
            }
            ModelType::AddRigidModelBinding(
              (ModelType *)component[22].m_SafePointerList.mNode.mNext,
              (Illusion::ModelProxy *)&v66[1].mNext,
              v58,
              &UFG::qMatrix44::msIdentity,
              0);
          }
LABEL_112:
          v67 = UFG::CharacterAnimationComponent::operator new(0xE8ui64);
          if ( v67 )
          {
            UFG::CharacterAnimationComponent::CharacterAnimationComponent(
              (UFG::CharacterAnimationComponent *)v67,
              *(UFG::RigResource **)&pos.x);
            v12 = v68;
          }
          v69 = v22->m_pSimObject;
          v70 = v69->m_Flags;
          if ( !((v70 >> 14) & 1) && (v70 & 0x8000u) == 0 )
          {
            if ( (v70 >> 13) & 1 )
              v63 = 8;
            else
              v63 = -1;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v80, v69, 1);
          UFG::SimObjectModifier::AttachComponent(&v80, v12, v63);
          UFG::SimObjectModifier::Close(&v80);
          UFG::SimObjectModifier::~SimObjectModifier(&v80);
          v7 = v86;
        }
      }
    }
    UFG::RigidBody::SetMotionType(v22, 0x80u);
    if ( (unsigned __int8)(v7->breakingRigidBody->m_motion.m_type.m_storage - 4) > 1u )
    {
      *(_QWORD *)&massProperties.m_volume = 0i64;
      massProperties.m_centerOfMass = 0i64;
      massProperties.m_inertiaTensor.m_col0 = 0i64;
      massProperties.m_inertiaTensor.m_col1 = 0i64;
      massProperties.m_inertiaTensor.m_col2 = 0i64;
      if ( UFG::CollisionMeshData::ComputeMassProperties(v8->mCollisionMeshData, &massProperties, v8->mFractureState) )
      {
        hkpRigidBody::setCenterOfMassLocal(v8->mBody, &massProperties.m_centerOfMass);
        hkpRigidBody::setMass(v8->mBody, massProperties.m_mass);
        hkpRigidBody::setInertiaLocal(v8->mBody, &massProperties.m_inertiaTensor);
      }
    }
    v71 = v7->newRigidBody;
    if ( v71 )
    {
      v72 = (hkpEntity *)&v22->mBody->vfptr;
      hkpEntity::activate((hkpEntity *)&v22->mBody->vfptr);
      v72->m_motion.vfptr[9].__vecDelDtor(
        (hkBaseObject *)&v72->m_motion.vfptr,
        (unsigned int)&v71->m_motion.m_linearVelocity);
      v73 = v7->newRigidBody;
      hkpEntity::activate(v72);
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v72->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v72->m_motion,
        &v73->m_motion.m_angularVelocity);
    }
  }
  v74 = v8->mCollisionMeshData->mFractureConnectivity;
  if ( v74 )
    UFG::FractureConnectivity::DeleteNodeByPartIndex(v74, v7->shapeKey);
  return v22;
}

