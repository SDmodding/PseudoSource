// File Line: 69
// RVA: 0x15143B0
__int64 dynamic_initializer_for__UFG::RigidBodyComponent::s_RigidBodyComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RigidBodyComponent::s_RigidBodyComponentList__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RigidBodyComponent::mAllocator__);
}

// File Line: 129
// RVA: 0x44D340
void __fastcall UFG::RigidBodyComponent::RigidBodyComponent(
        UFG::RigidBodyComponent *this,
        UFG::CollisionMeshData *mesh,
        UFG::CollisionInstanceData *instance,
        unsigned int flags,
        __int16 followBoneIndex)
{
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mPrev; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qReflectHandleBase v10; // [rsp+30h] [rbp-38h] BYREF

  UFG::RigidBody::RigidBody(this, mesh, instance, flags | 0x800);
  this->mPrev = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  this->mNext = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  this->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBodyComponent::`vftable{for `UFG::SimComponent};
  this->UFG::RigidBody::UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBodyComponent::`vftable{for `UFG::BasePhysicsObject};
  this->mParkourComponent.mPrev = &this->mParkourComponent;
  this->mParkourComponent.mNext = &this->mParkourComponent;
  this->mParkourComponent.m_pPointer = 0i64;
  this->mCoverComponent.mPrev = &this->mCoverComponent;
  this->mCoverComponent.mNext = &this->mCoverComponent;
  this->mCoverComponent.m_pPointer = 0i64;
  this->mRenderComponent.mPrev = &this->mRenderComponent;
  this->mRenderComponent.mNext = &this->mRenderComponent;
  this->mRenderComponent.m_pPointer = 0i64;
  this->mStateMachineComponent.mPrev = &this->mStateMachineComponent;
  this->mStateMachineComponent.mNext = &this->mStateMachineComponent;
  this->mStateMachineComponent.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->mAnimationComponent);
  this->mFollowBoneIndex = followBoneIndex;
  this->mRuntimeStateMachineDefinition = 0i64;
  this->mLifeSpan = -1.0;
  *(_QWORD *)&this->mTimeSinceAddedToWorld = -1082130432i64;
  mPrev = UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev;
  UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList;
  UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mPrev = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  UFG::SimComponent::AddType(this, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID, "RigidBodyComponent");
  UFG::qReflectHandleBase::qReflectHandleBase(&v10);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
  v10.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v10, &mCollisionMeshData->mObjectProperties);
  if ( HIBYTE(v10.mData[1].mHandles.mNode.mPrev) )
    this->mFlags |= 0x2000u;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v10);
}

// File Line: 150
// RVA: 0x450ED0
void __fastcall UFG::RigidBodyComponent::~RigidBodyComponent(UFG::RigidBodyComponent *this)
{
  unsigned int i; // ebx
  UFG::SimObject *m_pPointer; // rdx
  hkpRigidBody *mBody; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::StateMachineDefinition *mRuntimeStateMachineDefinition; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v9; // rbx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mPrev; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *p_mStateMachineComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsRenderHelper> *p_mRenderComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_mCoverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *p_mParkourComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v32; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v33; // rax

  this->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBodyComponent::`vftable{for `UFG::SimComponent};
  this->UFG::RigidBody::UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBodyComponent::`vftable{for `UFG::BasePhysicsObject};
  for ( i = 0; i < this->mInstanceData->mNumParts; ++i )
  {
    m_pPointer = this->mInstanceData->mParts[i].mSimObject.m_pPointer;
    if ( m_pPointer )
      UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
  }
  mBody = this->mBody;
  if ( mBody )
    mBody->m_userData = 0i64;
  if ( this->mRuntimeStateMachineDefinition )
  {
    v5 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
    v6 = UFG::qReflectWarehouse::Instance();
    Inventory = UFG::qReflectWarehouse::GetInventory(v6, v5);
    UFG::qReflectInventoryBase::Remove(Inventory, this->mRuntimeStateMachineDefinition);
    mRuntimeStateMachineDefinition = this->mRuntimeStateMachineDefinition;
    if ( mRuntimeStateMachineDefinition )
      mRuntimeStateMachineDefinition->vfptr->__vecDelDtor(mRuntimeStateMachineDefinition, 1u);
  }
  if ( this == UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator )
    UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator = (UFG::RigidBodyComponent *)&this->mPrev[-18].mNext;
  v9 = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  this->mNext = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAnimationComponent);
  p_mStateMachineComponent = &this->mStateMachineComponent;
  if ( this->mStateMachineComponent.m_pPointer )
  {
    v13 = p_mStateMachineComponent->mPrev;
    v14 = this->mStateMachineComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mStateMachineComponent->mPrev = p_mStateMachineComponent;
    this->mStateMachineComponent.mNext = &this->mStateMachineComponent;
  }
  this->mStateMachineComponent.m_pPointer = 0i64;
  v15 = p_mStateMachineComponent->mPrev;
  v16 = this->mStateMachineComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mStateMachineComponent->mPrev = p_mStateMachineComponent;
  this->mStateMachineComponent.mNext = &this->mStateMachineComponent;
  p_mRenderComponent = &this->mRenderComponent;
  if ( this->mRenderComponent.m_pPointer )
  {
    v18 = p_mRenderComponent->mPrev;
    v19 = this->mRenderComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_mRenderComponent->mPrev = p_mRenderComponent;
    this->mRenderComponent.mNext = &this->mRenderComponent;
  }
  this->mRenderComponent.m_pPointer = 0i64;
  v20 = p_mRenderComponent->mPrev;
  v21 = this->mRenderComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_mRenderComponent->mPrev = p_mRenderComponent;
  this->mRenderComponent.mNext = &this->mRenderComponent;
  p_mCoverComponent = &this->mCoverComponent;
  if ( this->mCoverComponent.m_pPointer )
  {
    v23 = p_mCoverComponent->mPrev;
    v24 = this->mCoverComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_mCoverComponent->mPrev = p_mCoverComponent;
    this->mCoverComponent.mNext = &this->mCoverComponent;
  }
  this->mCoverComponent.m_pPointer = 0i64;
  v25 = p_mCoverComponent->mPrev;
  v26 = this->mCoverComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_mCoverComponent->mPrev = p_mCoverComponent;
  this->mCoverComponent.mNext = &this->mCoverComponent;
  p_mParkourComponent = &this->mParkourComponent;
  if ( this->mParkourComponent.m_pPointer )
  {
    v28 = p_mParkourComponent->mPrev;
    v29 = this->mParkourComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    p_mParkourComponent->mPrev = p_mParkourComponent;
    this->mParkourComponent.mNext = &this->mParkourComponent;
  }
  this->mParkourComponent.m_pPointer = 0i64;
  v30 = p_mParkourComponent->mPrev;
  v31 = this->mParkourComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_mParkourComponent->mPrev = p_mParkourComponent;
  this->mParkourComponent.mNext = &this->mParkourComponent;
  v32 = v9->mPrev;
  v33 = this->mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  v9->mPrev = v9;
  this->mNext = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
  UFG::RigidBody::~RigidBody(this);
}

// File Line: 182
// RVA: 0x475560
void __fastcall UFG::RigidBodyComponent::SetStateMachineComponent(
        UFG::RigidBodyComponent *this,
        UFG::StateMachineComponent *smc)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *p_mStateMachineComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_mStateMachineComponent = &this->mStateMachineComponent;
  if ( this->mStateMachineComponent.m_pPointer )
  {
    mPrev = p_mStateMachineComponent->mPrev;
    mNext = this->mStateMachineComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mStateMachineComponent->mPrev = p_mStateMachineComponent;
    this->mStateMachineComponent.mNext = &this->mStateMachineComponent;
  }
  this->mStateMachineComponent.m_pPointer = smc;
  if ( smc )
  {
    v5 = smc->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_mStateMachineComponent;
    p_mStateMachineComponent->mPrev = v5;
    this->mStateMachineComponent.mNext = &smc->m_SafePointerList.mNode;
    smc->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mStateMachineComponent;
    this->mFlags |= 0x4000u;
  }
  else
  {
    this->mFlags &= ~0x4000u;
  }
}

// File Line: 197
// RVA: 0x467AF0
void __fastcall UFG::RigidBodyComponent::GetStateMachineDefinition(
        UFG::RigidBodyComponent *this,
        UFG::qReflectHandle<UFG::StateMachineDefinition> *h)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->mStateMachineComponent.m_pPointer;
  if ( m_pPointer )
    UFG::qReflectHandleBase::operator=(h, (UFG::qReflectHandleBase *)&m_pPointer[1].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 207
// RVA: 0x45FE90
void __fastcall UFG::RigidBodyComponent::CreateRuntimeStateMachineDefinition(
        UFG::RigidBodyComponent *this,
        UFG::StateMachineDefinition *definition)
{
  DNA::Database *v4; // rax
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rbx
  UFG::qReflectWarehouse *v7; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectHandleBase *m_pPointer; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::StateMachineComponent> *p_mStateMachineComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_m_Flags; // rdx
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *v18; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax

  DNA::Database::Instance();
  v5 = DNA::Database::GenUID(v4);
  definition->mBaseNode.mUID = v5;
  v6 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v7 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v7, v6);
  UFG::qReflectInventoryBase::Add(Inventory, definition);
  this->mRuntimeStateMachineDefinition = definition;
  m_pPointer = (UFG::qReflectHandleBase *)this->mStateMachineComponent.m_pPointer;
  if ( m_pPointer )
  {
    UFG::qReflectHandleBase::Init(m_pPointer + 3, m_pPointer[3].mTypeUID, v5);
  }
  else
  {
    v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::StateMachineComponent::StateMachineComponent(
        (UFG::StateMachineComponent *)v10,
        definition->mBaseNode.mUID,
        -1);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    p_mStateMachineComponent = &this->mStateMachineComponent;
    if ( this->mStateMachineComponent.m_pPointer )
    {
      mPrev = p_mStateMachineComponent->mPrev;
      mNext = this->mStateMachineComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mStateMachineComponent->mPrev = p_mStateMachineComponent;
      this->mStateMachineComponent.mNext = &this->mStateMachineComponent;
    }
    this->mStateMachineComponent.m_pPointer = v12;
    if ( v12 )
    {
      v16 = v12->m_SafePointerList.mNode.mPrev;
      v16->mNext = p_mStateMachineComponent;
      p_mStateMachineComponent->mPrev = v16;
      this->mStateMachineComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = p_mStateMachineComponent;
    }
    p_m_Flags = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mStateMachineComponent.m_pPointer[1].m_Flags;
    if ( this->mStateMachineComponent.m_pPointer[1].m_BoundComponentHandles.mNode.mPrev )
    {
      v18 = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)p_m_Flags->mPrev;
      m_pSimObject = this->mStateMachineComponent.m_pPointer[1].m_pSimObject;
      v18[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimObject> *, unsigned int))m_pSimObject;
      m_pSimObject->vfptr = v18;
      p_m_Flags->mPrev = p_m_Flags;
      p_m_Flags->mNext = p_m_Flags;
    }
    p_m_Flags[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)this;
    v20 = this->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v20->mNext = p_m_Flags;
    p_m_Flags->mPrev = v20;
    p_m_Flags->mNext = &this->m_SafePointerList.mNode;
    this->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_Flags;
    this->mFlags |= 0x4000u;
  }
}ointerNode<UFG::SimComponent>::mPrev = p_m_Flags;
    this->mFlags |= 0x40

// File Line: 231
// RVA: 0x468960
bool __fastcall UFG::RigidBodyComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRigidBody);
}

// File Line: 237
// RVA: 0x470B70
UFG::RigidBodyComponent *__fastcall UFG::RigidBodyComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObject)
{
  UFG::RigidBodyComponent *v2; // rdi
  UFG::SimObject *m_pSimObject; // rbp
  UFG::allocator::free_link *v4; // rax
  hkQuaternionf *v5; // rax
  hkQuaternionf *v6; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qBaseTreeRB *CollisionModel; // r8
  UFG::RigidBodyComponent *result; // rax
  char *v10; // rax
  hkTransformf v11; // [rsp+40h] [rbp-58h] BYREF
  UFG::allocator::free_link *v12; // [rsp+A0h] [rbp+8h] BYREF
  UFG::qSymbolUC v13; // [rsp+A8h] [rbp+10h] BYREF
  __int64 *v14; // [rsp+B0h] [rbp+18h]

  v2 = 0i64;
  m_pSimObject = sceneObject->m_pSimObject;
  v14 = (__int64 *)&v12;
  LODWORD(v12) = UFG::gNullQSymbolUC;
  PropertyUtils::GetWithDefault<UFG::qSymbolUC>(
    &v13,
    sceneObject,
    (UFG::qArray<unsigned long,0> *)&SimSym_CollisionModelName,
    (unsigned int *)&v12,
    DEPTH_RECURSE);
  v4 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
  v12 = v4;
  if ( v4 )
  {
    UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  LODWORD(v6[6].m_vec.m_quad.m128_f32[0]) = (UFG::qSymbolUC)v13.mUID;
  v6[5].m_vec.m_quad.m128_i32[3] = sceneObject->m_NameUID;
  v6[5].m_vec.m_quad.m128_i32[2] = 0;
  v6[4].m_vec.m_quad.m128_i32[2] = m_pSimObject->m_Name.mUID;
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  hkTransformf::set4x4ColumnMajor(&v11, &m_pTransformNodeComponent->mWorldTransform.v0.x);
  hkQuaternionf::set(v6, &v11.m_rotation);
  v6[2] = (hkQuaternionf)v11.m_translation;
  CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                     UFG::BasePhysicsSystem::mInstance,
                     v6[6].m_vec.m_quad.m128_u32[0]);
  if ( !CollisionModel )
  {
    v10 = UFG::qSymbol::as_cstr_dbg(&v13);
    UFG::qPrintf("Error: No collision mesh loaded for %s\n", v10);
    goto LABEL_8;
  }
  result = (UFG::RigidBodyComponent *)((__int64 (__fastcall *)(UFG::BasePhysicsSystem *, hkQuaternionf *, UFG::qBaseTreeRB *, __int64, _DWORD, UFG::SimObject *, __int64))UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld)(
                                        UFG::BasePhysicsSystem::mInstance,
                                        v6,
                                        CollisionModel,
                                        4i64,
                                        0,
                                        m_pSimObject,
                                        -2i64);
  v2 = result;
  if ( !result )
  {
LABEL_8:
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)v6);
    return v2;
  }
  return result;
}

// File Line: 282
// RVA: 0x46E080
void __fastcall UFG::RigidBodyComponent::OnAttach(UFG::RigidBodyComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mAnimationComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::SimComponent *m_pPointer; // rax
  UFG::DynamicSceneryInstance *v10; // rcx

  UFG::RigidBody::OnAttach(this, object);
  p_mAnimationComponent = &this->mAnimationComponent;
  if ( this->mAnimationComponent.m_pSimComponent )
  {
    mNext = this->mAnimationComponent.mNext;
    mPrev = p_mAnimationComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mAnimationComponent.m_pSimObject = 0i64;
    this->mAnimationComponent.mNext = &this->mAnimationComponent;
    p_mAnimationComponent->mPrev = p_mAnimationComponent;
    goto LABEL_8;
  }
  if ( this->mAnimationComponent.m_pSimObject
    && (p_mAnimationComponent->mPrev != p_mAnimationComponent
     || this->mAnimationComponent.mNext != &this->mAnimationComponent) )
  {
    v7 = this->mAnimationComponent.mNext;
    v8 = p_mAnimationComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  this->mAnimationComponent.m_Changed = 1;
  this->mAnimationComponent.m_pSimObject = object;
  this->mAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    p_mAnimationComponent,
    object);
  m_pPointer = this->mRenderComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->mFlags & 0x20) != 0 )
    {
      v10 = **(UFG::DynamicSceneryInstance ***)&m_pPointer[1].m_TypeUID;
      if ( v10 )
        UFG::DynamicSceneryInstance::ForceVisible(v10);
    }
  }
  if ( (this->mFlags & 0x400) == 0 )
    UFG::RigidBodyComponent::UpdateTransforms(this);
}

// File Line: 303
// RVA: 0x46E890
void __fastcall UFG::RigidBodyComponent::OnDetach(UFG::RigidBodyComponent *this)
{
  hkpRigidBody *mBody; // rax

  if ( this->mAnimationComponent.m_pSimComponent )
    UFG::RebindingComponentHandleBase::Unbind(&this->mAnimationComponent);
  mBody = this->mBody;
  if ( mBody )
    mBody->m_userData = 0i64;
  UFG::RigidBody::OnDetach(this);
}

// File Line: 321
// RVA: 0x468BD0
void __fastcall UFG::RigidBodyComponent::Inflate(UFG::RigidBodyComponent *this, bool addToWorld)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rcx

  if ( (this->mFlags & 2) == 0 )
  {
    this->mTimeSinceAddedToWorld = 0.0;
    UFG::RigidBody::Inflate(this, addToWorld);
    m_pPointer = this->mStateMachineComponent.m_pPointer;
    this->mFlags |= 0x800u;
    if ( m_pPointer )
      ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[9].__vecDelDtor)(m_pPointer);
    v4 = this->mParkourComponent.m_pPointer;
    if ( v4 )
      ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[9].__vecDelDtor)(v4);
    v5 = this->mCoverComponent.m_pPointer;
    if ( v5 )
      ((void (__fastcall *)(UFG::SimComponent *))v5->vfptr[9].__vecDelDtor)(v5);
  }
}

// File Line: 355
// RVA: 0x4608B0
bool __fastcall UFG::RigidBodyComponent::Deflate(UFG::RigidBodyComponent *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rcx

  this->mTimeSinceAddedToWorld = -1.0;
  m_pPointer = this->mParkourComponent.m_pPointer;
  if ( m_pPointer )
    ((void (__fastcall *)(UFG::SimComponent *))m_pPointer->vfptr[8].__vecDelDtor)(m_pPointer);
  v3 = this->mCoverComponent.m_pPointer;
  if ( v3 )
    ((void (__fastcall *)(UFG::SimComponent *))v3->vfptr[8].__vecDelDtor)(v3);
  v4 = this->mStateMachineComponent.m_pPointer;
  if ( v4 )
    ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[8].__vecDelDtor)(v4);
  if ( this->mLifeSpan >= 0.0 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, this->m_pSimObject);
  return (this->mFlags & 2) != 0 && UFG::RigidBody::Deflate(this);
}

// File Line: 405
// RVA: 0x476A60
void __fastcall UFG::RigidBodyComponent::TeleportEventHandler(UFG::RigidBodyComponent *this, UFG::Event *event)
{
  bool v2; // zf
  float v3; // xmm1_4
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
  UFG::SimComponent *m_pSimComponent; // rax
  __int16 mFollowBoneIndex; // cx
  __int64 v21; // r8
  hkaPose *v22; // r8
  hkQsTransformf *v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  UFG::qMatrix44 *p_b; // rdx
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v30; // rbx
  UFG::qMatrix44 b; // [rsp+20h] [rbp-E0h] BYREF
  __int128 v32; // [rsp+60h] [rbp-A0h] BYREF
  hkQsTransformf v33; // [rsp+70h] [rbp-90h] BYREF
  UFG::qMatrix44 d; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-20h] BYREF

  v2 = this->mAnimationComponent.m_pSimComponent == 0i64;
  v3 = *((float *)&event[1].m_EventUID + 1);
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
    || (m_pSimComponent = this->mAnimationComponent.m_pSimComponent, !*(_QWORD *)&m_pSimComponent[1].m_Flags)
    || (mFollowBoneIndex = this->mFollowBoneIndex, mFollowBoneIndex == -1)
    || (this->mFlags & 0x1000) != 0 )
  {
    p_b = &b;
  }
  else
  {
    v21 = *(_QWORD *)&m_pSimComponent[2].m_TypeUID;
    if ( !v21 )
      goto LABEL_12;
    v22 = *(hkaPose **)(v21 + 488);
    if ( (v22->m_boneFlags.m_data[mFollowBoneIndex] & 2) != 0 )
      v23 = hkaPose::calculateBoneModelSpace(v22, mFollowBoneIndex);
    else
      v23 = &v22->m_modelPose.m_data[mFollowBoneIndex];
    v33 = *v23;
    v24 = _mm_mul_ps(v33.m_rotation.m_vec.m_quad, v33.m_rotation.m_vec.m_quad);
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
    p_b = &result;
  }
  UFG::RigidBody::SetTransform(this, p_b);
LABEL_12:
  mBody = this->mBody;
  v32 = 0i64;
  if ( mBody )
  {
    hkpEntity::activate(mBody);
    mBody->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&v32);
    v30 = this->mBody;
    hkpEntity::activate(v30);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v30->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
      &v30->m_motion,
      &v32);
  }
  this->mFlags |= 0x800u;
}

// File Line: 450
// RVA: 0x466990
bool __fastcall UFG::RigidBodyComponent::GetKeyframe(
        UFG::RigidBodyComponent *this,
        hkVector4f *nextPosition,
        hkQuaternionf *nextOrientation)
{
  Creature *m_pSimComponent; // r14
  UFG::TransformNodeComponent *v7; // rbx
  hkaSkeleton *mhkaSkeleton; // rbp
  hkaPose *mHavokPose; // rsi
  bool pivotAtOrigin; // di
  hkQsTransformf *PositionhkQ; // rax
  hkQsTransformf result; // [rsp+40h] [rbp-58h] BYREF

  m_pSimComponent = (Creature *)this->mAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent = (Creature *)m_pSimComponent->mLastSetPosition.m_scale.m_quad.m128_u64[1];
  if ( !m_pSimComponent || this->mFollowBoneIndex == -1 )
    return 0;
  v7 = (UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent;
  mhkaSkeleton = m_pSimComponent->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton;
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  mHavokPose = m_pSimComponent->mPose.mHavokPose;
  pivotAtOrigin = (this->mFlags & 0x1000) != 0;
  PositionhkQ = Creature::GetPositionhkQ(m_pSimComponent, &result);
  return UFG::MultiBody::GetKeyframe(
           mHavokPose,
           mhkaSkeleton,
           PositionhkQ,
           this->mFollowBoneIndex,
           &v7->mWorldTransform,
           pivotAtOrigin,
           nextPosition,
           nextOrientation);
}

// File Line: 468
// RVA: 0x47E040
void __fastcall UFG::RigidBodyComponent::UpdateAll(float delta_sec)
{
  UFG::PhysicsSystem *v1; // rsi
  UFG::RigidBodyComponent *p_mNext; // rcx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rbx

  v1 = (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance;
  p_mNext = (UFG::RigidBodyComponent *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext->mNext[-18].mNext;
      if ( (p_mNext->m_Flags & 3) == 1 )
        UFG::RigidBodyComponent::Update(p_mNext, v1, &v1->mActiveRegionManager, delta_sec);
      p_mNext = (UFG::RigidBodyComponent *)v3;
    }
    while ( v3 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
}

// File Line: 509
// RVA: 0x47C710
void __fastcall UFG::RigidBodyComponent::Update(
        UFG::RigidBodyComponent *this,
        UFG::PhysicsSystem *ps,
        UFG::ActiveRegionManager *activeRegionManager,
        float delta_sec)
{
  UFG::RigidBodyComponent *v5; // r13
  UFG::CollisionMeshData *mCollisionMeshData; // rax
  UFG::FractureConnectivity *mFractureConnectivity; // rdi
  unsigned int v8; // ebx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v15; // eax
  __int64 v16; // rsi
  unsigned int v17; // r14d
  hkpRigidBody *mBody; // rax
  hkVector4f v19; // xmm1
  hkVector4f v20; // xmm2
  hkVector4f v21; // xmm3
  UFG::CollisionMeshData *v22; // r12
  UFG::CollisionInstanceData *v23; // r15
  __int64 v24; // rbx
  __int64 v25; // rdi
  unsigned int v26; // edx
  __int64 v27; // r8
  unsigned int v28; // eax
  UFG::RigidBody *v29; // rdi
  UFG::SimObjectGame *v30; // rcx
  __int16 v31; // dx
  unsigned int v32; // edx
  UFG::SimComponent *ComponentOfType; // rax
  Render::SimpleDrawableComponent *p_m_pSimObject; // r15
  UFG::SimComponent *v35; // rax
  UFG::SimComponent *v36; // rax
  bool v37; // zf
  unsigned int v38; // r13d
  __int64 v39; // r12
  unsigned __int64 v40; // r15
  __int64 v41; // rax
  __int64 v42; // rcx
  __int64 v43; // r14
  unsigned int v44; // esi
  unsigned int v45; // ebx
  unsigned __int64 v46; // rax
  UFG::allocator::free_link *v47; // rax
  UFG::allocator::free_link *v48; // rdi
  _DWORD *v49; // rcx
  __int64 i; // r8
  unsigned __int64 mUID; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v53; // rax
  __int64 v54; // rax
  __int64 v55; // rbx
  UFG::SimComponent *v56; // rdx
  UFG::SimObjectGame *v57; // rcx
  UFG::SimComponent *v58; // rsi
  __int16 v59; // dx
  UFG::SimComponent *v60; // rax
  UFG::RigResource *v61; // r14
  UFG::qMemoryPool *v62; // rax
  UFG::allocator::free_link *v63; // rax
  __int64 v64; // rax
  __int64 v65; // r15
  UFG::SimObject *v66; // rdx
  __int16 v67; // cx
  unsigned int v68; // ebx
  unsigned int v69; // ebx
  __int64 v70; // rdi
  __int64 v71; // r13
  __int64 mOffset; // rax
  char *v73; // rcx
  unsigned int BoneID; // eax
  __int64 v75; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rdx
  UFG::qMemoryPool *v77; // rax
  UFG::allocator::free_link *v78; // rax
  UFG::SimComponent *v79; // rax
  UFG::SimComponent *v80; // rdi
  UFG::SimObject *v81; // rdx
  __int16 v82; // cx
  unsigned int v83; // ebx
  float mLifeSpan; // xmm0_4
  float v85; // xmm0_4
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v86; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *v88; // rdx
  UFG::PhysicsRenderHelper *m_pPointer; // rcx
  UFG::PhysicsRenderHelper *v90; // rcx
  unsigned int mFlags; // eax
  hkpRigidBody *v92; // r9
  hkpRigidBody *v93; // rax
  __m128 v94; // xmm6
  hkpRigidBody *v95; // rax
  Render::SimpleDrawableComponent *v96; // [rsp+30h] [rbp-A8h]
  int v97; // [rsp+38h] [rbp-A0h]
  void *mem[2]; // [rsp+40h] [rbp-98h] BYREF
  _BYTE subGraphs[24]; // [rsp+50h] [rbp-88h] BYREF
  hkQuaternionf currentOrientation; // [rsp+68h] [rbp-70h] BYREF
  hkpKeyFrameUtility::AccelerationInfo v101; // [rsp+78h] [rbp-60h] BYREF
  hkTransformf transform; // [rsp+C8h] [rbp-10h] BYREF
  UFG::SimObjectModifier v103; // [rsp+108h] [rbp+30h] BYREF
  UFG::SimObjectModifier v104; // [rsp+128h] [rbp+50h] BYREF
  __int64 v105; // [rsp+148h] [rbp+70h]
  UFG::RigidBodyComponent *v106; // [rsp+1B8h] [rbp+E0h]

  v105 = -2i64;
  v5 = this;
  if ( (this->mFlags & 0x10008) != 0 )
    return;
  mCollisionMeshData = this->mCollisionMeshData;
  mFractureConnectivity = mCollisionMeshData->mFractureConnectivity;
  if ( !mFractureConnectivity || !mFractureConnectivity->mColorsDirty )
    goto LABEL_150;
  if ( (int)UFG::FractureConnectivity::ComputeNodeColors(mCollisionMeshData->mFractureConnectivity) <= 1 )
    goto LABEL_147;
  *(_QWORD *)&subGraphs[8] = 0i64;
  *(_QWORD *)subGraphs = 0i64;
  UFG::FractureConnectivity::ExtractSubGraphs(
    mFractureConnectivity,
    (UFG::qArray<UFG::qReflectInventoryBase *,0> *)subGraphs);
  v5->mCollisionMeshData->mFractureConnectivity = **(UFG::FractureConnectivity ***)&subGraphs[8];
  mFractureConnectivity = v5->mCollisionMeshData->mFractureConnectivity;
  currentOrientation.m_vec.m_quad.m128_u64[0] = (unsigned __int64)mFractureConnectivity;
  v8 = 12;
  v97 = 12;
  m_pSimObject = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pSimObject,
                            Render::SimpleDrawableComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, Render::SimpleDrawableComponent::_TypeUID);
    if ( ComponentOfTypeHK && ComponentOfTypeHK != (UFG::SimComponent *)24 )
    {
      v8 = 28;
LABEL_28:
      v97 = v8;
      goto LABEL_29;
    }
  }
  v12 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      m_pComponent = v12->m_Components.p[14].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 )
      {
        m_pComponent = v12->m_Components.p[9].m_pComponent;
      }
      else if ( (v13 & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v12, UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v12->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
      v8 = 44;
    goto LABEL_28;
  }
LABEL_29:
  v15 = 1;
  *(_DWORD *)&subGraphs[16] = 1;
  if ( *(_DWORD *)subGraphs <= 1u )
    goto LABEL_144;
  currentOrientation.m_vec.m_quad.m128_i32[2] = v8 & 0x10;
  do
  {
    v16 = v15;
    v17 = **(_DWORD **)(*(_QWORD *)&subGraphs[8] + 8i64 * v15);
    mBody = v5->mBody;
    v19.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
    v20.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
    v21.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
    transform.m_rotation.m_col0 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
    transform.m_rotation.m_col1 = (hkVector4f)v19.m_quad;
    transform.m_rotation.m_col2 = (hkVector4f)v20.m_quad;
    transform.m_translation = (hkVector4f)v21.m_quad;
    v22 = UFG::CollisionMeshData::SplitMeshUsingConnectivity(
            *(UFG::FractureConnectivity **)(*(_QWORD *)&subGraphs[8] + 8 * v16),
            v5->mCollisionMeshData,
            &transform);
    currentOrientation.m_vec.m_quad.m128_u64[0] = (unsigned __int64)v22;
    v23 = UFG::CollisionInstanceData::SplitInstanceUsingConnectivity(
            *(UFG::FractureConnectivity **)(*(_QWORD *)&subGraphs[8] + 8 * v16),
            v5->mInstanceData,
            &transform);
    if ( v17 )
    {
      v24 = 0i64;
      v25 = v17;
      do
      {
        UFG::Destruction::RemovePart(
          UFG::Destruction::mInstance,
          v5,
          **(_DWORD **)(v24 + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&subGraphs[8] + 8 * v16) + 8i64)));
        v24 += 8i64;
        --v25;
      }
      while ( v25 );
      v8 = v97;
    }
    v26 = 0;
    if ( v17 )
    {
      v27 = 0i64;
      do
      {
        **(_DWORD **)(v27 + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&subGraphs[8] + 8 * v16) + 8i64)) = v26++;
        v27 += 8i64;
      }
      while ( v26 < v17 );
    }
    v28 = 0;
    if ( (v5->mFlags & 0x400) != 0 )
      v28 = 1024;
    v29 = UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld(
            UFG::BasePhysicsSystem::mInstance,
            v23,
            v22,
            v8,
            v28,
            0i64);
    *(_QWORD *)&subGraphs[8] = v29;
    if ( currentOrientation.m_vec.m_quad.m128_i32[2] )
    {
      v30 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( !v30 )
        goto LABEL_55;
      v31 = v30->m_Flags;
      if ( (v31 & 0x4000) != 0 )
      {
        v32 = Render::SimpleDrawableComponent::_TypeUID;
      }
      else
      {
        if ( v31 < 0 )
        {
          v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v30, Render::SimpleDrawableComponent::_TypeUID);
          if ( v35 )
          {
            p_m_pSimObject = (Render::SimpleDrawableComponent *)&v35[-1].m_pSimObject;
            goto LABEL_56;
          }
LABEL_55:
          p_m_pSimObject = 0i64;
          goto LABEL_56;
        }
        if ( (v31 & 0x2000) != 0 )
        {
          v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v30, Render::SimpleDrawableComponent::_TypeUID);
          if ( v36 )
          {
            p_m_pSimObject = (Render::SimpleDrawableComponent *)&v36[-1].m_pSimObject;
            goto LABEL_56;
          }
          goto LABEL_55;
        }
        v37 = (v31 & 0x1000) == 0;
        v32 = Render::SimpleDrawableComponent::_TypeUID;
        if ( v37 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v30, Render::SimpleDrawableComponent::_TypeUID);
LABEL_45:
          if ( ComponentOfType )
          {
            p_m_pSimObject = (Render::SimpleDrawableComponent *)&ComponentOfType[-1].m_pSimObject;
LABEL_56:
            v96 = p_m_pSimObject;
            mem[1] = 0i64;
            mem[0] = 0i64;
            v38 = 0;
            if ( v22->mNumParts )
            {
              v39 = 0i64;
              v40 = currentOrientation.m_vec.m_quad.m128_u64[0];
              do
              {
                v41 = *(_QWORD *)(v40 + 160);
                if ( v41 )
                  v42 = v41 + v40 + 160;
                else
                  v42 = 0i64;
                currentOrientation.m_vec.m_quad.m128_i32[0] = *(_DWORD *)(v39 + v42 + 80);
                v43 = LODWORD(mem[0]);
                v44 = LODWORD(mem[0]) + 1;
                if ( (unsigned int)(LODWORD(mem[0]) + 1) <= HIDWORD(mem[0]) )
                  goto LABEL_79;
                if ( HIDWORD(mem[0]) )
                  v45 = 2 * HIDWORD(mem[0]);
                else
                  v45 = 1;
                for ( ; v45 < v44; v45 *= 2 )
                  ;
                if ( v45 <= 4 )
                  v45 = 4;
                if ( v45 - v44 > 0x10000 )
                  v45 = LODWORD(mem[0]) + 65537;
                if ( v45 == LODWORD(mem[0]) )
                {
LABEL_79:
                  v48 = (UFG::allocator::free_link *)mem[1];
                }
                else
                {
                  v46 = 4i64 * v45;
                  if ( !is_mul_ok(v45, 4ui64) )
                    v46 = -1i64;
                  v47 = UFG::qMalloc(v46, "qArray.Add", 0i64);
                  v48 = v47;
                  v49 = mem[1];
                  if ( mem[1] )
                  {
                    for ( i = 0i64; (unsigned int)i < LODWORD(mem[0]); v49 = mem[1] )
                    {
                      *((_DWORD *)&v47->mNext + i) = v49[i];
                      i = (unsigned int)(i + 1);
                    }
                    operator delete[](v49);
                  }
                  mem[1] = v48;
                  HIDWORD(mem[0]) = v45;
                }
                LODWORD(mem[0]) = v44;
                *((_DWORD *)&v48->mNext + v43) = currentOrientation.m_vec.m_quad.m128_i32[0];
                ++v38;
                v39 += 96i64;
              }
              while ( v38 < *(_DWORD *)(v40 + 56) );
              p_m_pSimObject = v96;
              v29 = *(UFG::RigidBody **)&subGraphs[8];
            }
            mUID = UFG::UIHKPlayerObjective::GetObjective(p_m_pSimObject)->mBaseNode.mUID;
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v53 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x100ui64, "SimComponent", 0i64, 1u);
            *(_QWORD *)&subGraphs[8] = v53;
            if ( v53 )
            {
              Render::SimpleDrawableComponent::SimpleDrawableComponent(
                (Render::SimpleDrawableComponent *)v53,
                mUID,
                (UFG::qArray<unsigned long,0> *)mem);
              v55 = v54;
            }
            else
            {
              v55 = 0i64;
            }
            UFG::SimObjectModifier::SimObjectModifier(&v104, v29->m_pSimObject, 1);
            if ( v55 )
              v56 = (UFG::SimComponent *)(v55 + 24);
            else
              v56 = 0i64;
            UFG::SimObjectModifier::AttachComponent(&v104, v56, 0xFFFFFFFFi64);
            UFG::SimObjectModifier::Close(&v104);
            UFG::SimObjectModifier::~SimObjectModifier(&v104);
            if ( mem[1] )
              operator delete[](mem[1]);
            mem[1] = 0i64;
            mem[0] = 0i64;
            v5 = v106;
LABEL_141:
            v8 = v97;
            goto LABEL_142;
          }
          goto LABEL_55;
        }
      }
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v30, v32);
      goto LABEL_45;
    }
    if ( (v8 & 0x20) != 0 )
    {
      v57 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( v57 )
      {
        v59 = v57->m_Flags;
        if ( (v59 & 0x4000) != 0 )
        {
          v58 = v57->m_Components.p[14].m_pComponent;
        }
        else if ( v59 >= 0 )
        {
          if ( (v59 & 0x2000) != 0 )
          {
            v58 = v57->m_Components.p[9].m_pComponent;
          }
          else
          {
            v60 = (v59 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v57, UFG::CompositeDrawableComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v57, UFG::CompositeDrawableComponent::_TypeUID);
            v58 = v60;
          }
        }
        else
        {
          v58 = v57->m_Components.p[14].m_pComponent;
        }
      }
      else
      {
        v58 = 0i64;
      }
      v61 = *(UFG::RigResource **)&v58[21].m_TypeUID;
      if ( v61 )
      {
        v62 = UFG::GetSimulationMemoryPool();
        v63 = UFG::qMemoryPool::Allocate(v62, 0x5E0ui64, "SimComponent", 0i64, 1u);
        if ( v63 )
        {
          UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v63, v61);
          v65 = v64;
        }
        else
        {
          v65 = 0i64;
        }
        v66 = v29->m_pSimObject;
        v67 = v66->m_Flags;
        if ( (v67 & 0x4000) != 0 )
        {
          v68 = 14;
        }
        else if ( v67 >= 0 )
        {
          if ( (v67 & 0x2000) != 0 )
            v68 = 9;
          else
            v68 = -1;
        }
        else
        {
          v68 = 14;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v103, v66, 1);
        UFG::SimObjectModifier::AttachComponent(&v103, (UFG::SimComponent *)v65, v68);
        UFG::SimObjectModifier::Close(&v103);
        UFG::SimObjectModifier::~SimObjectModifier(&v103);
        v69 = 0;
        if ( v22->mNumParts )
        {
          v70 = 0i64;
          v71 = *(_QWORD *)&subGraphs[8];
          do
          {
            mOffset = v22->mPartDetails.mOffset;
            if ( mOffset )
              v73 = (char *)&v22->mPartDetails + mOffset;
            else
              v73 = 0i64;
            BoneID = Skeleton::GetBoneID(v61->mUFGSkeleton, *(_DWORD *)&v73[v70 + 80]);
            if ( BoneID != -1 )
            {
              if ( !v69 )
                *(_WORD *)(v71 + 440) = BoneID;
              v75 = (__int64)&v58[22].m_SafePointerList.mNode.mNext[6];
              mNext = v58[22].m_SafePointerList.mNode.mNext[6].mNext;
              if ( mNext != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v75 )
              {
                while ( LOWORD(mNext[7].mPrev) != BoneID )
                {
                  mNext = mNext->mNext;
                  if ( mNext == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v75 )
                    goto LABEL_128;
                }
                ModelType::AddRigidModelBinding(
                  *(ModelType **)(v65 + 1424),
                  (Illusion::ModelProxy *)&mNext[1].mNext,
                  BoneID,
                  &UFG::qMatrix44::msIdentity,
                  0);
              }
            }
LABEL_128:
            ++v69;
            v70 += 96i64;
          }
          while ( v69 < v22->mNumParts );
          v5 = v106;
        }
        v77 = UFG::GetSimulationMemoryPool();
        v78 = UFG::qMemoryPool::Allocate(v77, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
        if ( v78 )
        {
          UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v78, v61);
          v80 = v79;
        }
        else
        {
          v80 = 0i64;
        }
        v81 = *(UFG::SimObject **)(*(_QWORD *)&subGraphs[8] + 40i64);
        v82 = v81->m_Flags;
        if ( (v82 & 0x4000) != 0 )
        {
          v83 = 9;
        }
        else if ( v82 >= 0 )
        {
          if ( (v82 & 0x2000) != 0 )
            v83 = 8;
          else
            v83 = -1;
        }
        else
        {
          v83 = 9;
        }
        UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v101, v81, 1);
        UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&v101, v80, v83);
        UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v101);
        UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v101);
        goto LABEL_141;
      }
    }
LABEL_142:
    v15 = *(_DWORD *)&subGraphs[16] + 1;
    *(_DWORD *)&subGraphs[16] = v15;
  }
  while ( v15 < *(_DWORD *)subGraphs );
  mFractureConnectivity = (UFG::FractureConnectivity *)currentOrientation.m_vec.m_quad.m128_u64[0];
LABEL_144:
  if ( *(_QWORD *)&subGraphs[8] )
    operator delete[](*(void **)&subGraphs[8]);
  *(_QWORD *)&subGraphs[8] = 0i64;
  *(_QWORD *)subGraphs = 0i64;
LABEL_147:
  if ( mFractureConnectivity && mFractureConnectivity->mNodes.size <= 1 )
  {
    UFG::FractureConnectivity::~FractureConnectivity(mFractureConnectivity);
    operator delete[](mFractureConnectivity);
    v5->mCollisionMeshData->mFractureConnectivity = 0i64;
  }
LABEL_150:
  mLifeSpan = v5->mLifeSpan;
  if ( mLifeSpan >= 0.0 )
  {
    v85 = mLifeSpan - delta_sec;
    v5->mLifeSpan = v85;
    if ( v85 < 0.0 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v101);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v86);
      v101.m_angularPositionFactor.m_quad.m128_u64[0] = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      v88 = v5->mCollisionMeshData;
      if ( v88 )
        UFG::qReflectHandleBase::operator=((UFG::qReflectHandleBase *)&v101, &v88->mObjectProperties);
      if ( v101.m_linearVelocityFactor.m_quad.m128_u64[0]
        && *(_BYTE *)(v101.m_linearVelocityFactor.m_quad.m128_u64[0] + 159) )
      {
        m_pPointer = (UFG::PhysicsRenderHelper *)v5->mRenderComponent.m_pPointer;
        if ( m_pPointer )
          UFG::PhysicsRenderHelper::SetToFadeOut(m_pPointer);
      }
      else
      {
        v5->mInstanceData->UFG::RigidBody::mFlags |= 2u;
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v5->m_pSimObject);
      }
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v101);
    }
  }
  v90 = (UFG::PhysicsRenderHelper *)v5->mRenderComponent.m_pPointer;
  if ( v90 && UFG::PhysicsRenderHelper::HasFadedOut(v90) )
  {
    v5->mInstanceData->UFG::RigidBody::mFlags |= 2u;
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v5->m_pSimObject);
  }
  mFlags = v5->mFlags;
  if ( (mFlags & 0x4000) != 0 && (mFlags & 2) != 0 )
    UFG::RigidBodyComponent::UpdateStateMachine(v5, delta_sec);
  if ( v5->mAnimationComponent.m_pSimComponent
    && (v5->mBody || (v5->mFlags & 0x800) != 0)
    && delta_sec > 0.0
    && (v5->mFlags & 0xC0) == 0
    && UFG::RigidBodyComponent::GetKeyframe(v5, (hkVector4f *)mem, (hkQuaternionf *)subGraphs) )
  {
    if ( (v5->mFlags & 0x100) != 0 )
    {
      v92 = v5->mBody;
      if ( v92 )
      {
        hkpKeyFrameUtility::applyHardKeyFrame((hkVector4f *)mem, (hkQuaternionf *)subGraphs, 1.0 / delta_sec, v92);
      }
      else
      {
        hkpKeyFrameUtility::KeyFrameInfo::setUsingPositionOrientationPair(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          &v5->mInstanceData->mPosition,
          &v5->mInstanceData->mOrientation,
          (hkVector4f *)mem,
          (hkQuaternionf *)subGraphs,
          1.0 / delta_sec);
        v5->mInstanceData->mPosition = *(hkVector4f *)mem;
        v5->mInstanceData->mOrientation = *(hkQuaternionf *)subGraphs;
      }
    }
    else
    {
      v93 = v5->mBody;
      if ( v93 )
      {
        *(hkVector4f *)&subGraphs[8] = v93->m_motion.m_motionState.m_transform.m_translation;
        currentOrientation.m_vec.m_quad = (__m128)v93->m_motion.m_motionState.m_sweptTransform.m_rotation1;
        v94 = (__m128)(unsigned int)FLOAT_1_0;
        v94.m128_f32[0] = 1.0 / delta_sec;
        hkpKeyFrameUtility::KeyFrameInfo::fastSetUsingPositionOrientationPair(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          (hkVector4f *)&subGraphs[8],
          &currentOrientation,
          (hkVector4f *)mem,
          (hkQuaternionf *)subGraphs,
          1.0 / delta_sec);
        hkpKeyFrameUtility::AccelerationInfo::AccelerationInfo(&v101);
        v101.m_linearPositionFactor.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps(v94, v94),
                                               _mm_unpacklo_ps(v94, (__m128)0i64));
        v101.m_angularPositionFactor = v101.m_linearPositionFactor;
        v101.m_linearVelocityFactor = v101.m_linearPositionFactor;
        v101.m_angularVelocityFactor = v101.m_linearPositionFactor;
        v101.m_maxLinearAcceleration = 10.0;
        v101.m_maxAngularAcceleration = 10.0;
        v101.m_maxAllowedDistance = FLOAT_2_0;
        hkpKeyFrameUtility::applySoftKeyFrame(
          (hkpKeyFrameUtility::KeyFrameInfo *)&transform,
          &v101,
          delta_sec,
          1.0 / delta_sec,
          v5->mBody);
      }
    }
  }
  v95 = v5->mBody;
  if ( v95 )
  {
    if ( v95->m_world )
      v5->mTimeSinceAddedToWorld = delta_sec + v5->mTimeSinceAddedToWorld;
  }
}

// File Line: 796
// RVA: 0x4805B0
void __fastcall UFG::RigidBodyComponent::UpdateTransforms(UFG::RigidBodyComponent *this)
{
  unsigned int v2; // esi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  char v5; // al
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject **p_m_pSimObject; // rax
  hkpRigidBody *mBody; // rax
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm2
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm0
  UFG::CollisionInstanceData *mInstanceData; // rbx
  UFG::PhysicsRenderHelper *m_pPointer; // rcx
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  __int16 mFollowBoneIndex; // cx
  UFG::qMatrix44 *p_d; // rdx
  unsigned int mFlags; // edx
  __int64 v21; // rsi
  UFG::TransformNodeComponent *v22; // rbx
  __int64 v23; // r14
  __m128 v24; // xmm2
  __m128i inserted; // xmm0
  __m128 v26; // xmm14
  __m128 v27; // xmm15
  __m128 v28; // xmm7
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm8
  __m128 v33; // xmm3
  __m128 v34; // xmm11
  __m128 v35; // xmm3
  __m128 v36; // xmm11
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm9
  __m128 v40; // xmm7
  __m128 v41; // xmm9
  __m128 v42; // xmm9
  __m128 v43; // xmm6
  __m128 v44; // xmm4
  __int64 v45; // rcx
  __m128 v46; // xmm5
  __m128 v47; // xmm0
  __m128 v48; // xmm4
  __m128 v49; // xmm12
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm10
  __m128 v53; // xmm0
  __m128 v54; // xmm10
  __m128 v55; // xmm1
  __m128 v56; // xmm11
  __m128 v57; // xmm5
  __m128 v58; // xmm11
  __m128 v59; // xmm11
  __m128 v60; // xmm11
  hkaPose *v61; // rsi
  __int64 v62; // r9
  __int64 m_size; // rdx
  int v64; // eax
  __int64 v65; // r8
  __int64 v66; // r14
  __int64 v67; // r15
  __int64 v68; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v70; // r12
  hkQsTransformf *v71; // r13
  hkQsTransformf *v72; // rdi
  __m128 m_quad; // xmm3
  __m128 v74; // xmm0
  __m128 v75; // xmm8
  __m128 v76; // xmm1
  __m128 v77; // xmm7
  __m128 v78; // xmm5
  __m128 v79; // xmm4
  __m128i v80; // xmm9
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  __m128 v84; // xmm2
  __m128 v85; // xmm2
  __m128 v86; // xmm4
  __m128 v87; // xmm8
  __m128 v88; // xmm3
  __m128 v89; // xmm4
  __m128 v90; // xmm4
  __int64 i; // rcx
  unsigned int *v92; // rdx
  unsigned int v93; // eax
  __m128 *p_m_quad; // rax
  __int64 v95; // r8
  hkQsTransformf *v96; // rax
  hkVector4f v97; // xmm1
  UFG::SimComponent *m_pSimComponent; // rax
  float y; // xmm1_4
  float x; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-E0h] BYREF
  hkTransformf d; // [rsp+30h] [rbp-D0h] BYREF
  hkTransformf v103; // [rsp+70h] [rbp-90h] BYREF
  hkQsTransformf v104; // [rsp+B0h] [rbp-50h] BYREF
  hkTransformf v105; // [rsp+E0h] [rbp-20h] BYREF
  hkTransformf transform; // [rsp+120h] [rbp+20h] BYREF
  UFG::qMatrix44 m; // [rsp+160h] [rbp+60h] BYREF
  int v108; // [rsp+280h] [rbp+180h]
  __int64 v109; // [rsp+288h] [rbp+188h]
  __int64 v110; // [rsp+290h] [rbp+190h]

  if ( (this->mFlags & 0x20008) == 0 )
  {
    v2 = this->mFlags & 0x800;
    if ( !this->mBody )
    {
      if ( this->mAnimationComponent.m_pSimComponent )
      {
        m_pSimObject = this->m_pSimObject;
        if ( m_pSimObject )
        {
          m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
          if ( m_pTransformNodeComponent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            this->mInstanceData->mPosition.m_quad = _mm_unpacklo_ps(
                                                      _mm_unpacklo_ps(
                                                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.x),
                                                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.z)),
                                                      _mm_unpacklo_ps(
                                                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y),
                                                        (__m128)0i64));
          }
        }
      }
    }
    if ( UFG::RigidBody::IsSleeping(this) || (v5 = this->m_Flags & 3, v5 != 1) )
      v5 = 0;
    if ( this->mAnimationComponent.m_pSimComponent || v2 || v5 )
    {
      v6 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v6 )
      {
        m_Flags = v6->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v6, Render::SimpleDrawableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, Render::SimpleDrawableComponent::_TypeUID);
        if ( ComponentOfTypeHK )
        {
          p_m_pSimObject = &ComponentOfTypeHK[-1].m_pSimObject;
          if ( p_m_pSimObject )
            *((_DWORD *)p_m_pSimObject + 30) |= 4u;
        }
      }
      mBody = this->mBody;
      this->mFlags &= ~0x800u;
      if ( mBody )
      {
        v11.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v103.m_rotation.m_col0 = (hkVector4f)v11.m_quad;
        v12.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v103.m_rotation.m_col1 = (hkVector4f)v12.m_quad;
        v13.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v103.m_rotation.m_col2 = (hkVector4f)v13.m_quad;
        v14.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
      }
      else
      {
        mInstanceData = this->mInstanceData;
        hkRotationf::set(&v103.m_rotation, &mInstanceData->mOrientation);
        v14.m_quad = (__m128)mInstanceData->mPosition;
        v13.m_quad = (__m128)v103.m_rotation.m_col2;
        v12.m_quad = (__m128)v103.m_rotation.m_col1;
        v11.m_quad = (__m128)v103.m_rotation.m_col0;
      }
      m_pPointer = (UFG::PhysicsRenderHelper *)this->mRenderComponent.m_pPointer;
      v103.m_translation = (hkVector4f)v14.m_quad;
      if ( m_pPointer )
      {
        mCollisionMeshData = this->mCollisionMeshData;
        d.m_rotation.m_col0 = (hkVector4f)v11.m_quad;
        d.m_rotation.m_col1 = (hkVector4f)v12.m_quad;
        d.m_rotation.m_col2 = (hkVector4f)v13.m_quad;
        d.m_translation = (hkVector4f)v14.m_quad;
        UFG::PhysicsRenderHelper::UpdateTransforms(m_pPointer, mCollisionMeshData, &d);
      }
      mFollowBoneIndex = this->mFollowBoneIndex;
      if ( mFollowBoneIndex == -1 )
      {
        hkTransformf::get4x4ColumnMajor(&v103, d.m_rotation.m_col0.m_quad.m128_f32);
        p_d = (UFG::qMatrix44 *)&d;
LABEL_58:
        UFG::TransformNodeComponent::SetWorldTransform(
          (UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent,
          p_d);
        UFG::RigidBody::GetVelocity(this, &result);
        m_pSimComponent = this->mRootTransformComponent.m_pSimComponent;
        y = result.y;
        x = result.x;
        *(float *)&m_pSimComponent[4].m_SafePointerList.mNode.mPrev = result.z;
        *((float *)&m_pSimComponent[4].vfptr + 1) = y;
        *(float *)&m_pSimComponent[4].vfptr = x;
        return;
      }
      mFlags = this->mFlags;
      if ( (mFlags & 0x100) == 0 )
      {
        v21 = *(_QWORD *)&this->mAnimationComponent.m_pSimComponent[2].m_TypeUID;
        if ( v21 )
        {
          if ( (mFlags & 0x2000) == 0 )
          {
            v95 = *(_QWORD *)(v21 + 488);
            if ( (*(_BYTE *)(*(_QWORD *)(v95 + 40) + 4i64 * mFollowBoneIndex) & 2) != 0 )
              v96 = hkaPose::calculateBoneModelSpace(*(hkaPose **)(v21 + 488), mFollowBoneIndex);
            else
              v96 = (hkQsTransformf *)(*(_QWORD *)(v95 + 24) + 48i64 * mFollowBoneIndex);
            v104.m_translation = v96->m_translation;
            v104.m_rotation = v96->m_rotation;
            v97.m_quad = (__m128)v96->m_scale;
            d.m_translation = v104.m_translation;
            v104.m_scale = (hkVector4f)v97.m_quad;
            hkRotationf::set(&d.m_rotation, &v104.m_rotation);
            hkTransformf::setInverse(&transform, &d);
            hkTransformf::setMul(&v105, &v103, &transform);
            hkTransformf::get4x4ColumnMajor(&v105, &m.v0.x);
            p_d = &m;
            goto LABEL_58;
          }
          v22 = (UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent;
          v23 = *(_QWORD *)(*(_QWORD *)(v21 + 480) + 8i64);
          UFG::TransformNodeComponent::UpdateWorldTransform(v22);
          hkTransformf::set4x4ColumnMajor(&transform, &v22->mWorldTransform.v0.x);
          hkQsTransformf::setFromTransformNoScale((hkQsTransformf *)&v105, &transform);
          hkQsTransformf::setFromTransformNoScale(&v104, &v103);
          hkVector4f::setRotatedInverseDir(
            &d.m_rotation.m_col0,
            (hkQuaternionf *)&v105.m_rotation.m_col1,
            &v105.m_rotation.m_col0);
          v24 = _mm_rcp_ps(v105.m_rotation.m_col2.m_quad);
          inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v26 = (__m128)_mm_shuffle_epi32(inserted, 0);
          v27 = (__m128)_mm_shuffle_epi32(inserted, 64);
          v28 = _mm_xor_ps(v27, v105.m_rotation.m_col1.m_quad);
          v29 = _mm_shuffle_ps(v28, v28, 255);
          v30 = _mm_mul_ps(v104.m_translation.m_quad, v28);
          v31 = _mm_shuffle_ps(v28, v28, 201);
          v32 = (__m128)_mm_srli_si128(
                          _mm_slli_si128(
                            (__m128i)_mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v105.m_rotation.m_col2.m_quad)),
                                       v24),
                            4),
                          4);
          v33 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v104.m_translation.m_quad, v104.m_translation.m_quad, 201), v28),
                  _mm_mul_ps(v31, v104.m_translation.m_quad));
          v34 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                        _mm_shuffle_ps(v30, v30, 170)),
                      v28),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v29, v29), (__m128)xmmword_141A711B0), v104.m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v29));
          v35 = _mm_shuffle_ps(v104.m_rotation.m_vec.m_quad, v104.m_rotation.m_vec.m_quad, 255);
          v36 = _mm_add_ps(_mm_add_ps(v34, v34), _mm_xor_ps(v26, d.m_rotation.m_col0.m_quad));
          v37 = _mm_mul_ps(v35, v28);
          v38 = _mm_mul_ps(v104.m_rotation.m_vec.m_quad, v28);
          v39 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v104.m_rotation.m_vec.m_quad, v104.m_rotation.m_vec.m_quad, 201), v28),
                  _mm_mul_ps(v31, v104.m_rotation.m_vec.m_quad));
          v40 = _mm_mul_ps(v104.m_scale.m_quad, v32);
          v41 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 201), _mm_mul_ps(v29, v104.m_rotation.m_vec.m_quad)),
                  v37);
          v42 = _mm_shuffle_ps(
                  v41,
                  _mm_unpackhi_ps(
                    v41,
                    _mm_sub_ps(
                      _mm_mul_ps(v35, v29),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                        _mm_shuffle_ps(v38, v38, 170)))),
                  196);
          if ( (this->mFlags & 0x1000) != 0 )
          {
            v43 = _mm_shuffle_ps(v42, v42, 255);
            v44 = _mm_shuffle_ps(v42, v42, 201);
            v45 = *(_QWORD *)(v23 + 56) + 48i64 * this->mFollowBoneIndex;
            v46 = *(__m128 *)(v45 + 16);
            v47 = _mm_mul_ps(v44, *(__m128 *)v45);
            v48 = _mm_mul_ps(v44, v46);
            v49 = _mm_mul_ps(*(__m128 *)(v45 + 32), v40);
            v50 = _mm_mul_ps(*(__m128 *)v45, v42);
            v51 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v45, *(__m128 *)v45, 201), v42), v47);
            v52 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                          _mm_shuffle_ps(v50, v50, 170)),
                        v42),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v43, v43), (__m128)xmmword_141A711B0), *(__m128 *)v45)),
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v43));
            v53 = _mm_mul_ps(v43, v46);
            v54 = _mm_add_ps(_mm_add_ps(v52, v52), v36);
            v55 = _mm_shuffle_ps(v46, v46, 255);
            v56 = _mm_shuffle_ps(v46, v46, 201);
            v57 = _mm_mul_ps(v46, v42);
            v58 = _mm_sub_ps(_mm_mul_ps(v56, v42), v48);
            v59 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v58, v58, 201), v53), _mm_mul_ps(v55, v42));
            v60 = _mm_shuffle_ps(
                    v59,
                    _mm_unpackhi_ps(
                      v59,
                      _mm_sub_ps(
                        _mm_mul_ps(v55, v43),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                          _mm_shuffle_ps(v57, v57, 170)))),
                    196);
          }
          else
          {
            v54 = v36;
            v49 = v40;
            v60 = v42;
          }
          v61 = *(hkaPose **)(v21 + 488);
          v62 = this->mFollowBoneIndex;
          v110 = v62;
          m_size = v61->m_skeleton->m_bones.m_size;
          v61->m_boneFlags.m_data[v62] |= 4u;
          v64 = v62 + 1;
          v65 = m_size;
          v66 = (int)v62 + 1;
          v108 = v62 + 1;
          v109 = m_size;
          if ( v66 < m_size )
          {
            v67 = v64;
            do
            {
              LOWORD(v68) = v61->m_skeleton->m_parentIndices.m_data[v66];
              if ( (_WORD)v68 != 0xFFFF )
              {
                m_data = v61->m_boneFlags.m_data;
                if ( (m_data[(__int16)v68] & 4) != 0 )
                {
                  if ( (m_data[v66] & 1) != 0 )
                  {
                    v70 = v61->m_modelPose.m_data;
                    v68 = (__int16)v68;
                    if ( (m_data[(__int16)v68] & 2) != 0 )
                      v71 = hkaPose::calculateBoneModelSpace(v61, v68);
                    else
                      v71 = &v70[v68];
                    v72 = v61->m_localPose.m_data;
                    hkVector4f::setRotatedInverseDir(&d.m_rotation.m_col0, &v71->m_rotation, &v71->m_translation);
                    m_quad = v70[v67].m_translation.m_quad;
                    v74 = v71->m_scale.m_quad;
                    v75 = _mm_xor_ps(v27, v71->m_rotation.m_vec.m_quad);
                    v76 = _mm_rcp_ps(v74);
                    v77 = _mm_shuffle_ps(v75, v75, 255);
                    v78 = _mm_shuffle_ps(v75, v75, 201);
                    v79 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v75), _mm_mul_ps(v78, m_quad));
                    v80 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v74, v76)), v76), 4);
                    v81 = _mm_mul_ps(v75, m_quad);
                    v82 = _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                            _mm_shuffle_ps(v81, v81, 170));
                    v83 = v75;
                    v84 = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(v82, v75),
                              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v77, v77), (__m128)xmmword_141A711B0), m_quad)),
                            _mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v77));
                    v72[v67].m_translation.m_quad = _mm_add_ps(
                                                      _mm_add_ps(v84, v84),
                                                      _mm_xor_ps(v26, d.m_rotation.m_col0.m_quad));
                    v85 = v70[v67].m_rotation.m_vec.m_quad;
                    v86 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v75);
                    v87 = _mm_mul_ps(v75, v85);
                    v88 = _mm_shuffle_ps(v85, v85, 255);
                    v89 = _mm_sub_ps(v86, _mm_mul_ps(v78, v85));
                    v90 = _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v89, v89, 201), _mm_mul_ps(v85, v77)),
                            _mm_mul_ps(v83, v88));
                    v72[v67].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                         v90,
                                                         _mm_unpackhi_ps(
                                                           v90,
                                                           _mm_sub_ps(
                                                             _mm_mul_ps(v88, v77),
                                                             _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_shuffle_ps(v87, v87, 85),
                                                                 _mm_shuffle_ps(v87, v87, 0)),
                                                               _mm_shuffle_ps(v87, v87, 170)))),
                                                         196);
                    v72[v67].m_scale.m_quad = _mm_mul_ps(v70[v67].m_scale.m_quad, (__m128)_mm_srli_si128(v80, 4));
                    v65 = v109;
                    v61->m_boneFlags.m_data[v66] &= ~1u;
                  }
                  v61->m_boneFlags.m_data[v66] |= 4u;
                  v61->m_modelInSync.m_bool = 0;
                }
              }
              ++v66;
              ++v67;
            }
            while ( v66 < v65 );
            v62 = v110;
            v64 = v108;
          }
          for ( i = v64; i < v65; ++i )
          {
            v92 = v61->m_boneFlags.m_data;
            v93 = v92[i];
            if ( (v93 & 4) != 0 )
              v92[i] = v93 & 0xFFFFFFF9 | 2;
          }
          p_m_quad = &v61->m_modelPose.m_data[v62].m_translation.m_quad;
          *p_m_quad = v54;
          p_m_quad[1] = v60;
          p_m_quad[2] = v49;
          v61->m_boneFlags.m_data[v62] = 1;
          v61->m_localInSync.m_bool = 0;
        }
      }
    }
  }
}

// File Line: 994
// RVA: 0x474070
void __fastcall UFG::RigidBodyComponent::RestoreCollisionFilter(UFG::RigidBodyComponent *this)
{
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v2; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  unsigned int v5; // ecx
  hkpRigidBody *mBody; // rax
  hkpRigidBody *v7; // rdx
  hkpWorld *m_world; // rcx
  UFG::qReflectHandleBase v9; // [rsp+28h] [rbp-30h] BYREF

  this->mCollisionLayerOverride = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(&v9);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v2);
  v9.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v9, &mCollisionMeshData->mObjectProperties);
  v5 = (unsigned int)v9.mData[2].mBaseNode.mChildren[0];
  mBody = this->mBody;
  if ( mBody )
  {
    if ( mBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v5 )
    {
      mBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v5;
      v7 = this->mBody;
      m_world = v7->m_world;
      if ( m_world )
        hkpWorld::updateCollisionFilterOnEntity(
          m_world,
          v7,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
    }
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v9);
}

// File Line: 1045
// RVA: 0x46D870
void __fastcall UFG::RigidBodyComponent::NotifyProxyModeChanged(
        UFG::RigidBodyComponent *this,
        UFG::SimObject::eProxyMode proxyMode)
{
  if ( proxyMode == ePM_PROXY_REMOTE_PHYSICS )
  {
    if ( LODWORD(this->mCollisionMeshData->mObjectProperties.mData[2].mBaseNode.mChildren[1]) == 2 )
      UFG::RigidBody::SetMotionType(this, 256u);
    UFG::RigidBody::SetCollisionLayer(this, 1u, -1, -1, -1);
  }
  else
  {
    UFG::RigidBody::SetMotionType(this, 128u);
    UFG::RigidBodyComponent::RestoreCollisionFilter(this);
  }
}

// File Line: 1065
// RVA: 0x4609B0
void __fastcall UFG::RigidBodyComponent::Delete(UFG::RigidBodyComponent *this)
{
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v2; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::PhysicsRenderHelper *m_pPointer; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mPrev; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v13; // rax
  UFG::qReflectHandleBase v14; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v14);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v2);
  v14.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v14, &mCollisionMeshData->mObjectProperties);
  this->mInstanceData->UFG::RigidBody::mFlags |= 2u;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[8].m_pComponent;
      }
      else
      {
        v8 = (m_Flags & 0x1000) == 0;
        v9 = (UFG::SimObjectGame *)this->m_pSimObject;
        m_pComponent = v8
                     ? UFG::SimObject::GetComponentOfType(v9, UFG::BaseAnimationComponent::_TypeUID)
                     : UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
    if ( m_pComponent )
    {
      mNext = m_pComponent[2].m_SafePointerList.mNode.mNext;
      if ( mNext )
        LODWORD(mNext[5].mPrev) |= 1u;
    }
  }
  if ( HIBYTE(v14.mData[1].mHandles.mNode.mNext)
    && (m_pPointer = (UFG::PhysicsRenderHelper *)this->mRenderComponent.m_pPointer) != 0i64 )
  {
    UFG::PhysicsRenderHelper::SetToFadeOut(m_pPointer);
  }
  else
  {
    if ( this == UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator )
      UFG::RigidBodyComponent::s_RigidBodyComponentpCurrentIterator = (UFG::RigidBodyComponent *)&this->mPrev[-18].mNext;
    mPrev = this->mPrev;
    v13 = this->mNext;
    mPrev->mNext = v13;
    v13->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
    this->mNext = &this->UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent>;
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pSimObject);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v14);
}

// File Line: 1096
// RVA: 0x47FF20
void __fastcall UFG::RigidBodyComponent::UpdateStateMachine(UFG::RigidBodyComponent *this, float deltaTime)
{
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-58h] BYREF

  if ( this->mStateMachineComponent.m_pPointer )
  {
    UFG::RigidBody::GetTransform(this, &mat);
    if ( UFG::StateMachineComponent::Update(
           (UFG::StateMachineComponent *)this->mStateMachineComponent.m_pPointer,
           &mat,
           deltaTime) )
    {
      UFG::RigidBodyComponent::Delete(this);
    }
  }
  if ( this->mBody )
    this->mFlags &= 0xFFFFFFCF;
}

// File Line: 1120
// RVA: 0x465580
UFG::SimObject *__fastcall UFG::RigidBodyComponent::FracturePart(UFG::RigidBodyComponent *this, unsigned int index)
{
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v2; // rsi
  unsigned int v3; // edi
  UFG::RigidBodyComponent *v4; // r13
  BitArray256 *mFractureState; // r8
  UFG::CollisionMeshData *mCollisionMeshData; // rbx
  __int64 mOffset; // rax
  __int64 v8; // r9
  unsigned int v9; // ecx
  unsigned int v10; // edx
  float v11; // xmm1_4
  UFG::SimComponent *m_pPointer; // rax
  float v13; // xmm0_4
  hkpRigidBody *mBody; // rax
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm2
  hkVector4f v17; // xmm3
  UFG::SimComponent *v18; // r12
  UFG::ParkourContainer *v19; // r12
  int v20; // edi
  int m_size; // esi
  __int64 v22; // rbx
  hkVector4f v23; // xmm6
  hkVector4f v24; // xmm7
  UFG::ParkourComponent *v25; // r15
  UFG::ParkourData *v26; // r14
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  UFG::qBaseNodeRB *Head; // r13
  __int64 i; // r12
  UFG::ParkourComponent *v31; // rsi
  UFG::ParkourContainer *mData; // rax
  int v33; // edi
  int v34; // r14d
  __int64 v35; // rbx
  hkVector4f v36; // xmm6
  hkVector4f v37; // xmm7
  UFG::ParkourData *v38; // r15
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  UFG::CollisionInstanceData *mInstanceData; // rax
  UFG::CollisionInstanceData::Part *v42; // rbx
  UFG::StateMachineComponent *v43; // rcx
  UFG::SimObject *v44; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> output; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> v49; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 queryAabbMin; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 queryAabbMax; // [rsp+60h] [rbp-A0h] BYREF
  hkAabb aabbOut; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 v0; // [rsp+90h] [rbp-70h] BYREF
  __int64 v54; // [rsp+A0h] [rbp-60h]
  hkTransformf localToWorld; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qMatrix44 mat; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qBaseNodeRB *v59; // [rsp+1C0h] [rbp+C0h]
  UFG::ParkourContainer *v60; // [rsp+1C8h] [rbp+C8h]

  v54 = -2i64;
  v3 = index;
  v4 = this;
  mFractureState = this->mFractureState;
  if ( !mFractureState )
    return 0i64;
  mCollisionMeshData = this->mCollisionMeshData;
  if ( !mCollisionMeshData )
    return 0i64;
  mOffset = mCollisionMeshData->mPartDetails.mOffset;
  if ( !mOffset )
    return 0i64;
  if ( !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
    return 0i64;
  v8 = index >> 5;
  v9 = index & 0x1F;
  v10 = mFractureState->mBits[v8];
  if ( _bittest((const int *)&v10, v9) )
    return 0i64;
  mFractureState->mBits[v8] |= 1 << v9;
  v11 = (float)(1.0 / (float)(int)UFG::RigidBody::GetNumFracturableParts(v4)) + 0.0099999998;
  m_pPointer = v4->mStateMachineComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( v11 > 0.0 )
    {
      if ( *(_QWORD *)&m_pPointer[2].m_TypeUID )
      {
        v13 = *((float *)&m_pPointer[4].m_SafePointerList.mNode.mPrev + 1) - v11;
        *((float *)&m_pPointer[4].m_SafePointerList.mNode.mPrev + 1) = v13;
        if ( v13 < 0.0 )
          HIDWORD(m_pPointer[4].m_SafePointerList.mNode.mPrev) = 0;
      }
    }
  }
  if ( (_S15_0 & 1) == 0 )
  {
    _S15_0 |= 1u;
    worldStaticDestructable = UFG::qStringHashUpper32("WorldStaticDestructable", -1);
  }
  mBody = v4->mBody;
  v15.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v16.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v17.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
  localToWorld.m_rotation.m_col0 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  localToWorld.m_rotation.m_col1 = (hkVector4f)v15.m_quad;
  localToWorld.m_rotation.m_col2 = (hkVector4f)v16.m_quad;
  localToWorld.m_translation = (hkVector4f)v17.m_quad;
  UFG::GetAabbFromShapeKey(&aabbOut, &localToWorld, mCollisionMeshData->mShape, v3);
  aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, (__m128)_xmm);
  aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, (__m128)_xmm);
  LODWORD(queryAabbMin.x) = aabbOut.m_min.m_quad.m128_i32[0];
  LODWORD(queryAabbMin.y) = _mm_shuffle_ps(aabbOut.m_min.m_quad, aabbOut.m_min.m_quad, 85).m128_u32[0];
  LODWORD(queryAabbMin.z) = _mm_shuffle_ps(aabbOut.m_min.m_quad, aabbOut.m_min.m_quad, 170).m128_u32[0];
  LODWORD(queryAabbMax.x) = aabbOut.m_max.m_quad.m128_i32[0];
  LODWORD(queryAabbMax.y) = _mm_shuffle_ps(aabbOut.m_max.m_quad, aabbOut.m_max.m_quad, 85).m128_u32[0];
  LODWORD(queryAabbMax.z) = _mm_shuffle_ps(aabbOut.m_max.m_quad, aabbOut.m_max.m_quad, 170).m128_u32[0];
  UFG::RigidBody::GetTransform(v4, &mat);
  v18 = v4->mParkourComponent.m_pPointer;
  if ( v18 )
  {
    v19 = *(UFG::ParkourContainer **)&v18[1].m_Flags;
    output.m_data = 0i64;
    output.m_size = 0;
    output.m_capacityAndFlags = 0x80000000;
    UFG::ParkourContainer::Query(
      v19,
      (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer,
      &queryAabbMin,
      &queryAabbMax,
      v2,
      &output);
    v20 = 0;
    m_size = output.m_size;
    if ( output.m_size > 0 )
    {
      v22 = 0i64;
      v23.m_quad = (__m128)aabbOut.m_max;
      v24.m_quad = (__m128)aabbOut.m_min;
      do
      {
        v25 = (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer;
        v26 = output.m_data[v22];
        UFG::ParkourContainer::GetVerts(v19, v25, &mat, v26, &queryAabbMin, &queryAabbMax);
        v27 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMin.x), (__m128)LODWORD(queryAabbMin.z)),
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMin.y), (__m128)(unsigned int)FLOAT_1_0));
        v28 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMax.x), (__m128)LODWORD(queryAabbMax.z)),
                _mm_unpacklo_ps((__m128)LODWORD(queryAabbMax.y), (__m128)(unsigned int)FLOAT_1_0));
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, v23.m_quad), _mm_cmple_ps(v24.m_quad, v27))) & 7) == 7
          && (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v28, v23.m_quad), _mm_cmple_ps(v24.m_quad, v28))) & 7) == 7 )
        {
          UFG::ParkourComponent::Disable(v25, v26);
          UFG::ParkourQueryManager::RemoveCachedHandle(
            UFG::ParkourQueryManager::mInstance,
            (UFG::ParkourComponent *)v4->mParkourComponent.m_pPointer,
            output.m_data[v22]);
          v23.m_quad = (__m128)aabbOut.m_max;
          v24.m_quad = (__m128)aabbOut.m_min;
          m_size = output.m_size;
        }
        ++v20;
        ++v22;
      }
      while ( v20 < m_size );
    }
    output.m_size = 0;
    if ( output.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        output.m_data,
        8 * output.m_capacityAndFlags);
    output.m_data = 0i64;
    output.m_capacityAndFlags = 0x80000000;
    v3 = index;
  }
  else if ( HIDWORD(mCollisionMeshData->mObjectProperties.mData[4].mBaseNode.mParent) == worldStaticDestructable )
  {
    Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gParkourInstanceInventory->mResourceDatas);
    v59 = Head;
    if ( Head )
    {
      do
      {
        for ( i = 0i64; (unsigned int)i < Head[2].mUID; i = (unsigned int)(i + 1) )
        {
          v31 = (UFG::ParkourComponent *)*((_QWORD *)&Head[3].mParent[2].mParent + 10 * i);
          mData = (UFG::ParkourContainer *)v31->mParkourContainer.mData;
          v60 = mData;
          v49.m_data = 0i64;
          v49.m_size = 0;
          v49.m_capacityAndFlags = 0x80000000;
          UFG::ParkourContainer::Query(
            mData,
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
              UFG::ParkourContainer::GetVerts(v60, v31, &mat, v38, &v0, (UFG::qVector3 *)&output);
              v39 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(v0.x), (__m128)LODWORD(v0.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(v0.y), (__m128)(unsigned int)FLOAT_1_0));
              v40 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(output.m_data), (__m128)(unsigned int)output.m_size),
                      _mm_unpacklo_ps((__m128)HIDWORD(output.m_data), (__m128)(unsigned int)FLOAT_1_0));
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v39, v36.m_quad), _mm_cmple_ps(v37.m_quad, v39))) & 7) == 7
                && (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v40, v36.m_quad), _mm_cmple_ps(v37.m_quad, v40))) & 7) == 7 )
              {
                UFG::ParkourComponent::Disable(v31, v38);
                UFG::ParkourQueryManager::RemoveCachedHandle(UFG::ParkourQueryManager::mInstance, v31, v49.m_data[v35]);
                v36.m_quad = (__m128)aabbOut.m_max;
                v37.m_quad = (__m128)aabbOut.m_min;
                v34 = v49.m_size;
              }
              ++v33;
              ++v35;
            }
            while ( v33 < v34 );
            Head = v59;
          }
          v49.m_size = 0;
          if ( v49.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v49.m_data,
              8 * v49.m_capacityAndFlags);
          v49.m_data = 0i64;
          v49.m_capacityAndFlags = 0x80000000;
        }
        Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(
                                     &UFG::gParkourInstanceInventory->mResourceDatas.mTree,
                                     Head);
        v59 = Head;
      }
      while ( Head );
      v3 = index;
    }
    v4 = this;
  }
  mInstanceData = v4->mInstanceData;
  if ( !mInstanceData->mNumParts )
    return 0i64;
  v42 = &mInstanceData->mParts[v3];
  v43 = (UFG::StateMachineComponent *)v4->mStateMachineComponent.m_pPointer;
  if ( v43 )
    UFG::StateMachineComponent::DeleteChildMachine(v43, v3);
  v44 = v42->mSimObject.m_pPointer;
  if ( !v44 )
    return 0i64;
  mPrev = v42->mSimObject.mPrev;
  mNext = v42->mSimObject.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v42->mSimObject.mPrev = &v42->mSimObject;
  v42->mSimObject.mNext = &v42->mSimObject;
  v42->mSimObject.m_pPointer = 0i64;
  return v44;
}

// File Line: 1248
// RVA: 0x46EDB0
UFG::RigidBody *__fastcall UFG::RigidBodyComponent::OnRemovePart(
        UFG::RigidBodyComponent *this,
        UFG::BreakoffPart *breakOffPart,
        UFG::CollisionMeshData::PartDetails *partDetails,
        unsigned int instanceGuid)
{
  UFG::BreakoffPart *v6; // r12
  bool v8; // bl
  UFG::SimObject *v9; // rax
  UFG::SimObject *v10; // rsi
  UFG::SimComponent *v11; // rdi
  UFG::PhysicsRenderHelper *m_pPointer; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v16; // rcx
  __int16 m_Flags; // dx
  UFG::CompositeDrawableComponent *ComponentOfType; // rax
  ModelType *v19; // rcx
  UFG::StateMachineComponent *v20; // rcx
  UFG::RigidBody *v21; // r13
  UFG::qBaseTreeRB *CollisionModel; // r15
  UFG::allocator::free_link *v23; // rax
  UFG::CollisionInstanceData *v24; // rax
  UFG::CollisionInstanceData *v25; // rbx
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  hkpShape *m_shape; // rcx
  char v31; // si
  UFG::SimObjectGame *v32; // rcx
  __int16 v33; // dx
  UFG::SimComponent *v34; // rax
  Render::SimpleDrawableComponent *p_m_pSimObject; // rsi
  unsigned __int64 v36; // rax
  unsigned __int64 mUID; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v39; // rax
  __int64 v40; // rax
  __int64 v41; // rbx
  UFG::SimComponent *v42; // rdx
  UFG::SimObjectGame *v43; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 v45; // dx
  UFG::SimComponent *v46; // rax
  UFG::RigResource *v47; // r15
  unsigned int BoneID; // eax
  unsigned int v49; // esi
  UFG::allocator::free_link *v50; // rax
  UFG::SimComponent *v51; // rax
  UFG::SimObject *v52; // rdx
  __int16 v53; // cx
  unsigned int v54; // r12d
  unsigned int v55; // r15d
  __int64 v56; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rdx
  UFG::allocator::free_link *v58; // rax
  UFG::SimComponent *v59; // rax
  UFG::SimObject *v60; // rdx
  __int16 v61; // cx
  hkpRigidBody *newRigidBody; // rbx
  hkpEntity *mBody; // rdi
  hkpRigidBody *v64; // rbx
  UFG::FractureConnectivity *mFractureConnectivity; // rcx
  UFG::SimObject *v67; // [rsp+28h] [rbp-D8h]
  UFG::qArray<unsigned long,0> nameUidFilter; // [rsp+30h] [rbp-D0h] BYREF
  UFG::allocator::free_link *v69; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 pos; // [rsp+48h] [rbp-B8h] BYREF
  UFG::SimObjectModifier v71; // [rsp+58h] [rbp-A8h] BYREF
  hkMassProperties massProperties; // [rsp+80h] [rbp-80h] BYREF
  __int64 v73; // [rsp+D0h] [rbp-30h]
  hkTransformf v74; // [rsp+E0h] [rbp-20h] BYREF
  hkTransformf transformOut; // [rsp+120h] [rbp+20h] BYREF
  UFG::SimComponent *component; // [rsp+1B0h] [rbp+B0h]

  v73 = -2i64;
  v6 = breakOffPart;
  LODWORD(v69) = 10;
  v8 = breakOffPart->newRigidBody != 0i64;
  UFG::GetTransformFromShapeKey(&transformOut, this->mCollisionMeshData->mShape, breakOffPart->shapeKey);
  hkTransformf::setMul(&v74, &v6->breakingRigidBody->m_motion.m_motionState.m_transform, &transformOut);
  this->mFlags |= 0x20u;
  v9 = UFG::RigidBodyComponent::FracturePart(this, v6->shapeKey);
  v10 = v9;
  v11 = 0i64;
  if ( v9 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v9);
    v10 = 0i64;
  }
  m_pPointer = (UFG::PhysicsRenderHelper *)this->mRenderComponent.m_pPointer;
  if ( m_pPointer )
  {
    UFG::PhysicsRenderHelper::DisableDynamicScenery(m_pPointer, instanceGuid);
  }
  else
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject
      && ((v14 = m_pSimObject->m_Flags, (v14 & 0x4000) == 0) && v14 >= 0 && (v14 & 0x2000) == 0 && (v14 & 0x1000) == 0
        ? (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pSimObject,
                                 Render::SimpleDrawableComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pSimObject,
                                 Render::SimpleDrawableComponent::_TypeUID)),
          ComponentOfTypeHK && ComponentOfTypeHK != (UFG::SimComponent *)24) )
    {
      Render::SimpleDrawableComponent::SetVisibility(
        (Render::SimpleDrawableComponent *)&ComponentOfTypeHK[-1].m_pSimObject,
        partDetails->mRenderModelGuid,
        0);
      LODWORD(v69) = 26;
    }
    else
    {
      v16 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v16
        && ((m_Flags = v16->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v16,
                                                                       UFG::CompositeDrawableComponent::_TypeUID))
             : (ComponentOfType = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v16,
                                                                       UFG::CompositeDrawableComponent::_TypeUID)))
            : (ComponentOfType = (UFG::CompositeDrawableComponent *)v16->m_Components.p[9].m_pComponent))
           : (ComponentOfType = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent))
          : (ComponentOfType = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent),
            ComponentOfType) )
      {
        if ( this->mFollowBoneIndex == -1 )
        {
          UFG::CompositeDrawableComponent::SetIsHidden(ComponentOfType, 1);
        }
        else
        {
          v19 = ComponentOfType->mModelType[0];
          if ( v19 )
            ModelType::SetRigidModelVisibilityOnBone(v19, partDetails->mRenderModelGuid, 0);
        }
        LODWORD(v69) = 42;
      }
      else
      {
        *(_QWORD *)&pos.x = v74.m_translation.m_quad.m128_u64[0];
        LODWORD(pos.z) = v74.m_translation.m_quad.m128_i32[2];
        UFG::PhysicsSystem::DisableStaticSceneryInstance(
          (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
          instanceGuid,
          &pos);
      }
    }
  }
  if ( v8 )
  {
    v20 = (UFG::StateMachineComponent *)this->mStateMachineComponent.m_pPointer;
    if ( v20 )
      UFG::StateMachineComponent::FractureNotification(v20, partDetails->mSceneNodeNameUC.mUID);
  }
  v21 = 0i64;
  if ( v8 )
  {
    CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                       UFG::BasePhysicsSystem::mInstance,
                       partDetails->mCollisionModelUid);
    v23 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
    if ( v23 )
    {
      UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v23);
      v25 = v24;
    }
    else
    {
      v25 = 0i64;
    }
    v25->mCollisionModelGuid = partDetails->mCollisionModelUid;
    v25->mFlags = 0;
    hkQuaternionf::set(&v25->mOrientation, &v74.m_rotation);
    v26 = _mm_mul_ps(v25->mOrientation.m_vec.m_quad, v25->mOrientation.m_vec.m_quad);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
    v29 = _mm_rsqrt_ps(v28);
    v25->mOrientation.m_vec.m_quad = _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v29)),
                                       v25->mOrientation.m_vec.m_quad);
    v25->mPosition = v74.m_translation;
    v25->mInstanceGuid = instanceGuid;
    v25->mSimObjectName.mUID = (unsigned int)CollisionModel[3].mRoot.mParent;
    if ( !CollisionModel[2].mNULL.mChild[1] )
    {
      m_shape = v6->newRigidBody->m_collidable.m_shape;
      if ( m_shape->m_type.m_storage == 11 )
        m_shape = *(hkpShape **)&m_shape[1].m_type.m_storage;
      CollisionModel[2].mNULL.mChild[1] = (UFG::qBaseNodeRB *)m_shape;
    }
    v67 = v10;
    v31 = (char)v69;
    v21 = UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceAddedToWorld(
            UFG::BasePhysicsSystem::mInstance,
            v25,
            CollisionModel,
            (unsigned int)v69,
            this->mFlags & 0x400,
            v67);
    if ( ((unsigned __int8)v69 & 0x10) != 0 )
    {
      v32 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( !v32
        || ((v33 = v32->m_Flags, (v33 & 0x4000) == 0) && v33 >= 0 && (v33 & 0x2000) == 0 && (v33 & 0x1000) == 0
          ? (v34 = UFG::SimObject::GetComponentOfType(v32, Render::SimpleDrawableComponent::_TypeUID))
          : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v32, Render::SimpleDrawableComponent::_TypeUID)),
            p_m_pSimObject = (Render::SimpleDrawableComponent *)&v34[-1].m_pSimObject,
            !v34) )
      {
        p_m_pSimObject = 0i64;
      }
      nameUidFilter.p = 0i64;
      *(_QWORD *)&nameUidFilter.size = 0i64;
      pos.x = *((float *)&CollisionModel[1].mRoot.mParent + 1);
      v36 = 16i64;
      if ( !is_mul_ok(4ui64, 4ui64) )
        v36 = -1i64;
      nameUidFilter.p = (unsigned int *)UFG::qMalloc(v36, "qArray.Add", 0i64);
      nameUidFilter.capacity = 4;
      nameUidFilter.size = 1;
      *nameUidFilter.p = LODWORD(pos.x);
      mUID = UFG::UIHKPlayerObjective::GetObjective(p_m_pSimObject)->mBaseNode.mUID;
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v39 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x100ui64, "SimComponent", 0i64, 1u);
      if ( v39 )
      {
        Render::SimpleDrawableComponent::SimpleDrawableComponent(
          (Render::SimpleDrawableComponent *)v39,
          mUID,
          &nameUidFilter);
        v41 = v40;
      }
      else
      {
        v41 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v71, v21->m_pSimObject, 1);
      v42 = (UFG::SimComponent *)(v41 + 24);
      if ( !v41 )
        v42 = 0i64;
      UFG::SimObjectModifier::AttachComponent(&v71, v42, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v71);
      UFG::SimObjectModifier::~SimObjectModifier(&v71);
      if ( nameUidFilter.p )
        operator delete[](nameUidFilter.p);
      nameUidFilter.p = 0i64;
      *(_QWORD *)&nameUidFilter.size = 0i64;
      v6 = breakOffPart;
      v31 = (char)v69;
    }
    if ( (v31 & 0x20) != 0 )
    {
      v43 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v43 )
      {
        v45 = v43->m_Flags;
        if ( (v45 & 0x4000) != 0 )
        {
          m_pComponent = v43->m_Components.p[14].m_pComponent;
        }
        else if ( v45 >= 0 )
        {
          if ( (v45 & 0x2000) != 0 )
          {
            m_pComponent = v43->m_Components.p[9].m_pComponent;
          }
          else
          {
            v46 = (v45 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::CompositeDrawableComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v43, UFG::CompositeDrawableComponent::_TypeUID);
            m_pComponent = v46;
          }
        }
        else
        {
          m_pComponent = v43->m_Components.p[14].m_pComponent;
        }
      }
      else
      {
        m_pComponent = 0i64;
      }
      v47 = *(UFG::RigResource **)&m_pComponent[21].m_TypeUID;
      *(_QWORD *)&pos.x = v47;
      if ( v47 )
      {
        BoneID = Skeleton::GetBoneID(v47->mUFGSkeleton, partDetails->mRenderModelGuid);
        v49 = BoneID;
        if ( BoneID != -1 )
        {
          LOWORD(v21[1].mCollisionMeshData) = BoneID;
          v50 = UFG::SimComponent::operator new(0x5E0ui64);
          v69 = v50;
          if ( v50 )
          {
            UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v50, v47);
            component = v51;
          }
          else
          {
            component = 0i64;
          }
          v52 = v21->m_pSimObject;
          v53 = v52->m_Flags;
          v54 = 9;
          if ( (v53 & 0x4000) != 0 )
          {
            v55 = 14;
          }
          else if ( v53 >= 0 )
          {
            if ( (v53 & 0x2000) != 0 )
              v55 = 9;
            else
              v55 = -1;
          }
          else
          {
            v55 = 14;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v71, v52, 1);
          UFG::SimObjectModifier::AttachComponent(&v71, component, v55);
          UFG::SimObjectModifier::Close(&v71);
          UFG::SimObjectModifier::~SimObjectModifier(&v71);
          v56 = (__int64)&m_pComponent[22].m_SafePointerList.mNode.mNext[6];
          mNext = m_pComponent[22].m_SafePointerList.mNode.mNext[6].mNext;
          if ( mNext != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v56 )
          {
            while ( LOWORD(mNext[7].mPrev) != v49 )
            {
              mNext = mNext->mNext;
              if ( mNext == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v56 )
                goto LABEL_95;
            }
            ModelType::AddRigidModelBinding(
              (ModelType *)component[22].m_SafePointerList.mNode.mNext,
              (Illusion::ModelProxy *)&mNext[1].mNext,
              v49,
              &UFG::qMatrix44::msIdentity,
              0);
          }
LABEL_95:
          v58 = UFG::CharacterAnimationComponent::operator new(0xE8ui64);
          if ( v58 )
          {
            UFG::CharacterAnimationComponent::CharacterAnimationComponent(
              (UFG::CharacterAnimationComponent *)v58,
              *(UFG::RigResource **)&pos.x);
            v11 = v59;
          }
          v60 = v21->m_pSimObject;
          v61 = v60->m_Flags;
          if ( (v61 & 0x4000) == 0 && v61 >= 0 )
          {
            if ( (v61 & 0x2000) != 0 )
              v54 = 8;
            else
              v54 = -1;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v71, v60, 1);
          UFG::SimObjectModifier::AttachComponent(&v71, v11, v54);
          UFG::SimObjectModifier::Close(&v71);
          UFG::SimObjectModifier::~SimObjectModifier(&v71);
          v6 = breakOffPart;
        }
      }
    }
    UFG::RigidBody::SetMotionType(v21, 0x80u);
    if ( (unsigned __int8)(v6->breakingRigidBody->m_motion.m_type.m_storage - 4) > 1u )
    {
      *(_QWORD *)&massProperties.m_volume = 0i64;
      memset(&massProperties.m_centerOfMass, 0, 64);
      if ( UFG::CollisionMeshData::ComputeMassProperties(
             this->mCollisionMeshData,
             &massProperties,
             this->mFractureState) )
      {
        hkpRigidBody::setCenterOfMassLocal(this->mBody, &massProperties.m_centerOfMass);
        hkpRigidBody::setMass(this->mBody, massProperties.m_mass);
        hkpRigidBody::setInertiaLocal(this->mBody, &massProperties.m_inertiaTensor);
      }
    }
    newRigidBody = v6->newRigidBody;
    if ( newRigidBody )
    {
      mBody = v21->mBody;
      hkpEntity::activate(mBody);
      mBody->m_motion.vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&newRigidBody->m_motion.m_linearVelocity);
      v64 = v6->newRigidBody;
      hkpEntity::activate(mBody);
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))mBody->m_motion.vfptr[9].__first_virtual_table_function__)(
        &mBody->m_motion,
        &v64->m_motion.m_angularVelocity);
    }
  }
  mFractureConnectivity = this->mCollisionMeshData->mFractureConnectivity;
  if ( mFractureConnectivity )
    UFG::FractureConnectivity::DeleteNodeByPartIndex(mFractureConnectivity, v6->shapeKey);
  return v21;
}FG::FractureConnectivity::DeleteNodeByPartIndex(mFractureConnectivity, v6->shapeKey);
  return v21;
}

