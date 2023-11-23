// File Line: 43
// RVA: 0xAB730
const char *__fastcall UFG::RigidBody::GetTypeName(UFG::RigidBody *this)
{
  return "RigidBody";
}

// File Line: 88
// RVA: 0xB6F80
void __fastcall UFG::SurfaceVelocityUtil::contactPointAddedCallback(
        UFG::SurfaceVelocityUtil *this,
        hkpContactPointAddedEvent *event)
{
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // r8
  hkpCdBody *m_bodyB; // rbp
  hkpCdBody *v7; // rcx
  hkpCdBody *j; // rax
  hkpEntity *v9; // r9
  hkpEntity *v10; // r10
  signed int m_shapeKey; // r11d
  hkpShape *m_shape; // rdx
  hkpShape *v13; // rbx
  unsigned __int64 m_userData; // rdx
  __int64 v15; // r8
  __int64 v16; // rcx
  __int64 v17; // rax
  unsigned __int64 v18; // rdx
  __int64 v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rax
  hkpDynamicsContactMgr *m_internalContactMgr; // rbx

  m_parent = event->m_bodyA->m_parent;
  for ( i = event->m_bodyA; m_parent; m_parent = m_parent->m_parent )
    i = m_parent;
  m_bodyB = event->m_bodyB;
  v7 = m_bodyB;
  for ( j = m_bodyB->m_parent; j; j = j->m_parent )
    v7 = j;
  v9 = 0i64;
  if ( LOBYTE(i[1].m_shapeKey) == 1 )
    v10 = (hkpEntity *)((char *)i + SLOBYTE(i[1].m_shape));
  else
    v10 = 0i64;
  if ( LOBYTE(v7[1].m_shapeKey) == 1 )
    v9 = (hkpEntity *)((char *)v7 + SLOBYTE(v7[1].m_shape));
  m_shapeKey = event->m_bodyA->m_shapeKey;
  m_shape = i->m_shape;
  v13 = v7->m_shape;
  if ( m_shapeKey != -1 && m_shape->m_type.m_storage == 9 )
  {
    m_userData = m_shape[2].m_userData;
    if ( m_userData )
    {
      if ( ((*(_BYTE *)(m_userData + 41) - 1) & 0xFD) == 0 )
      {
        v15 = (m_shapeKey & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(m_userData + 232));
        v16 = m_shapeKey < 0
            ? *(_QWORD *)(m_userData + 256) + 80i64 * (int)v15
            : *(_QWORD *)(m_userData + 240) + 144i64 * (int)v15;
        v17 = *(_QWORD *)(v16 + 16);
        if ( v17 )
        {
          if ( (*(_BYTE *)(v17 + 28) & 1) != 0 )
            goto LABEL_28;
        }
      }
    }
  }
  v15 = m_bodyB->m_shapeKey;
  if ( (_DWORD)v15 != -1 && v13->m_type.m_storage == 9 )
  {
    v18 = v13[2].m_userData;
    if ( v18 )
    {
      if ( ((*(_BYTE *)(v18 + 41) - 1) & 0xFD) == 0 )
      {
        v19 = ((unsigned int)v15 & 0x7FFFFFFF) >> (32 - *(_BYTE *)(v18 + 232));
        v20 = (int)v15 < 0 ? *(_QWORD *)(v18 + 256) + 80 * v19 : *(_QWORD *)(v18 + 240) + 144 * v19;
        v21 = *(_QWORD *)(v20 + 16);
        if ( v21 )
        {
          if ( (*(_BYTE *)(v21 + 28) & 1) != 0 )
          {
LABEL_28:
            m_internalContactMgr = event->m_internalContactMgr;
            if ( m_internalContactMgr || (m_internalContactMgr = hkpEntity::findContactMgrTo(v10, v9)) != 0i64 )
            {
              if ( ((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkBaseObjectVtbl *, __int64, hkpEntity *))m_internalContactMgr->vfptr[8].__vecDelDtor)(
                     m_internalContactMgr,
                     m_internalContactMgr->vfptr,
                     v15,
                     v9) )
              {
                hkpResponseModifier::setSurfaceVelocity(
                  m_internalContactMgr,
                  (hkpRigidBody *)this->hkpSurfaceVelocityUtil::hkpContactListener::vfptr,
                  event->m_collisionOutput->m_constraintOwner.m_storage,
                  (hkVector4f *)&this->m_rigidBody);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 147
// RVA: 0x99920
void __fastcall UFG::RigidBody::RigidBody(
        UFG::RigidBody *this,
        UFG::CollisionMeshData *mesh,
        UFG::CollisionInstanceData *instance,
        unsigned int flags)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int v9; // ecx
  unsigned int mBundleGuid; // r8d
  unsigned int mGeometryType; // ecx
  char *v12; // rax
  UFG::qReflectHandleBase v13; // [rsp+40h] [rbp-68h] BYREF

  UFG::SimComponent::SimComponent(this, instance->mInstanceGuid);
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBody::`vftable{for `UFG::SimComponent};
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBody::`vftable{for `UFG::BasePhysicsObject};
  UFG::qResourceHandle::qResourceHandle(&this->mCollisionMeshBundle);
  this->mCollisionMeshBundle.mOwner = 0i64;
  this->mCollisionMeshBundle.mUnloading = 0;
  this->mInstanceData = instance;
  this->mCollisionMeshData = mesh;
  this->mBody = 0i64;
  this->mWaterFloatingTrackerComponent = 0i64;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mRootTransformComponent);
  this->mWindAction = 0i64;
  this->mFractureState = 0i64;
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
  this->mFlags = flags;
  *(_QWORD *)&this->mCollisionLayerOverride = -1i64;
  UFG::SimComponent::AddType(this, UFG::RigidBody::_RigidBodyTypeUID, "RigidBody");
  this->mFlags |= 0x10u;
  UFG::qReflectHandleBase::qReflectHandleBase(&v13);
  v13.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v13, &mCollisionMeshData->mObjectProperties);
  v9 = (int)v13.mData[2].mBaseNode.mChildren[1];
  if ( v9 == 4 )
  {
    this->mFlags |= 0x100u;
  }
  else if ( v9 == 1 )
  {
    this->mFlags |= 0x40u;
  }
  else
  {
    this->mFlags |= 0x80u;
  }
  mBundleGuid = this->mCollisionMeshData->mBundleGuid;
  this->mCollisionMeshBundle.mOwner = &this->UFG::BasePhysicsObject;
  UFG::qResourceHandle::Init(&this->mCollisionMeshBundle, 0x1723EA91u, mBundleGuid);
  mGeometryType = this->mCollisionMeshData->mGeometryType;
  if ( mGeometryType == 3 || mGeometryType == 4 )
  {
    v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "BitArray256", 0i64, 1u);
    if ( v12 )
    {
      *(_QWORD *)v12 = 0i64;
      *((_QWORD *)v12 + 1) = 0i64;
      *((_QWORD *)v12 + 2) = 0i64;
      *((_QWORD *)v12 + 3) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    this->mFractureState = (BitArray256 *)v12;
  }
  ++UFG::RigidBody::mCount;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
}

// File Line: 183
// RVA: 0x9CED0
void __fastcall UFG::RigidBody::~RigidBody(UFG::RigidBody *this)
{
  UFG::BasePhysicsObject *v2; // r14
  UFG::CollisionMeshData *mCollisionMeshData; // rcx
  hkpRigidBody *mBody; // rdx
  BitArray256 *mFractureState; // rdx
  UFG::CollisionInstanceData *mInstanceData; // rdx
  UFG::WindAction *mWindAction; // rdx
  int v8; // r8d
  UFG::BasePhysicsSystem *v9; // r10
  __int64 v10; // r9
  __int64 v11; // rax
  hkpWorld *m_world; // rcx
  hkpRigidBody *v13; // rax
  UFG::WaterFloatingTrackerBaseComponent *mWaterFloatingTrackerComponent; // rax
  UFG::SimObject *m_pSimObject; // rdx
  UFG::WaterFloatingTrackerBaseComponent *v16; // rcx
  unsigned int i; // ebx
  __int64 v18; // rsi
  UFG::Constraint *m_pPointer; // rdx
  UFG::Constraint *v20; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // rcx
  UFG::Constraint **p_m_pPointer; // rbx
  UFG::CollisionMeshData *v23; // rbx
  hkReferencedObject *mShape; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v25; // rcx
  UFG::Constraint **v26; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  ArrayOfTuplesImplementation v32; // [rsp+28h] [rbp-50h] BYREF

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBody::`vftable{for `UFG::SimComponent};
  v2 = &this->UFG::BasePhysicsObject;
  this->UFG::BasePhysicsObject::vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBody::`vftable{for `UFG::BasePhysicsObject};
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
  {
    mBody = this->mBody;
    if ( mBody )
    {
      UFG::CollisionMeshData::UnmarkBreakableParts(mCollisionMeshData, mBody);
      UFG::CollisionMeshData::ResetFracture(this->mCollisionMeshData);
    }
  }
  mFractureState = this->mFractureState;
  if ( mFractureState )
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mFractureState);
  this->mInstanceData->mPhysicsComponent = 0i64;
  this->mCollisionMeshBundle.mOwner = 0i64;
  UFG::qResourceHandle::Close(&this->mCollisionMeshBundle);
  if ( (this->mFlags & 4) == 0 )
  {
    mInstanceData = this->mInstanceData;
    if ( mInstanceData )
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mInstanceData);
  }
  mWindAction = this->mWindAction;
  if ( mWindAction )
  {
    v8 = 0;
    v9 = UFG::BasePhysicsSystem::mInstance;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v10 = 0i64;
      do
      {
        if ( v9->mActionsToAdd.m_data[v10] == mWindAction )
        {
          v11 = --v9->mActionsToAdd.m_size;
          if ( (_DWORD)v11 != v8 )
            v9->mActionsToAdd.m_data[v10] = v9->mActionsToAdd.m_data[v11];
          --v8;
          --v10;
        }
        ++v8;
        ++v10;
      }
      while ( v8 < v9->mActionsToAdd.m_size );
    }
    m_world = mWindAction->m_world;
    if ( m_world )
      hkpWorld::removeAction(m_world, mWindAction);
    hkReferencedObject::removeReference(this->mWindAction);
    this->mWindAction = 0i64;
  }
  v13 = this->mBody;
  if ( v13 )
  {
    v13->m_userData = 0i64;
    UFG::RigidBody::RemoveFromWorld(this);
    mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
    if ( mWaterFloatingTrackerComponent )
    {
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        if ( mWaterFloatingTrackerComponent->m_pSimObject )
        {
          UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&v32, m_pSimObject, 1);
          ArrayOfTuplesImplementation::clear(&v32);
          UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v32);
          UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v32);
          v16 = this->mWaterFloatingTrackerComponent;
          if ( v16 )
            v16->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor(v16, 1u);
          this->mWaterFloatingTrackerComponent = 0i64;
        }
      }
    }
    for ( i = 0; i < this->mConstraints.size; ++i )
    {
      v18 = i;
      m_pPointer = this->mConstraints.p[v18].m_pPointer;
      if ( m_pPointer )
      {
        if ( m_pPointer->mConstraintInstance )
          UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, m_pPointer->mConstraintInstance);
        v20 = this->mConstraints.p[v18].m_pPointer;
        if ( v20 )
          v20->vfptr->__vecDelDtor(v20, 1u);
      }
    }
    p = this->mConstraints.p;
    if ( p )
    {
      p_m_pPointer = &p[-1].m_pPointer;
      `eh vector destructor iterator(
        p,
        0x18ui64,
        (int)p[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
      operator delete[](p_m_pPointer);
    }
    this->mConstraints.p = 0i64;
    *(_QWORD *)&this->mConstraints.size = 0i64;
    hkReferencedObject::removeReference(this->mBody);
  }
  v23 = this->mCollisionMeshData;
  if ( v23 && (v23->mFlags & 2) != 0 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::BasePhysicsSystem::mInstance->mCollisionModels,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v23);
    mShape = v23->mShape;
    if ( mShape )
      hkReferencedObject::removeReference(mShape);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v23->mObjectProperties);
    operator delete[](v23);
  }
  --UFG::RigidBody::mCount;
  v25 = this->mConstraints.p;
  if ( v25 )
  {
    v26 = &v25[-1].m_pPointer;
    `eh vector destructor iterator(
      v25,
      0x18ui64,
      (int)v25[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v26);
  }
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mRootTransformComponent);
  UFG::qResourceHandle::~qResourceHandle(&this->mCollisionMeshBundle);
  v2->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  p_simComponent = &v2->mUserData.simComponent;
  if ( v2->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = v2->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    v2->mUserData.simComponent.mNext = &v2->mUserData.simComponent;
  }
  v2->mUserData.simComponent.m_pPointer = 0i64;
  v30 = p_simComponent->mPrev;
  v31 = v2->mUserData.simComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_simComponent->mPrev = p_simComponent;
  v2->mUserData.simComponent.mNext = &v2->mUserData.simComponent;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 262
// RVA: 0xA2830
void __fastcall UFG::RigidBody::CommonConstruct(
        UFG::RigidBody *this,
        hkpRigidBodyCinfo *info,
        UFG::CollisionMeshData *mesh)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qReflectObject *mData; // r8
  int v8; // eax
  int mCollisionSystem; // eax
  unsigned int v10; // ecx
  unsigned int mCollisionLayerOverride; // eax
  unsigned int v12; // edx
  unsigned int v13; // r9d
  UFG::qTree64Base::BaseNode *v14; // r10
  UFG::qWiseSymbol *null; // rax
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm1_4
  hkpMotion::MotionType m_storage; // r15d
  __int64 v20; // rsi
  char v21; // dl
  char v22; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v24; // rax
  hkpRigidBody *v25; // rax
  char v26; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  hkpRigidBody *mBody; // rcx
  unsigned int v32; // r14d
  UFG::qReflectObject *i; // rax
  UFG::PhysicsObjectProperties::ConstraintProperty *v34; // rbx
  char *v35; // rax
  __int64 v36; // rax
  hkVector4f **v37; // rcx
  unsigned __int64 v38; // rax
  __int64 size; // r15
  unsigned int v40; // ebx
  unsigned int capacity; // edx
  unsigned int v42; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v43; // rdx
  UFG::Constraint *v44; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v47; // rax
  __m128 v48; // kr00_16
  unsigned __int64 *v49; // rax
  unsigned __int64 v50; // rcx
  hkMotionState *p_m_motionState; // rdx
  _QWORD **v52; // rax
  hkpSurfaceVelocityUtil *v53; // rax
  hkpSurfaceVelocityUtil *v54; // rbx
  hkpRigidBody *v55; // rcx
  hkVector4f surfaceVelocityWorld; // [rsp+8h] [rbp-79h] BYREF
  unsigned int check_null[4]; // [rsp+18h] [rbp-69h] BYREF
  hkVector4f b; // [rsp+28h] [rbp-59h] BYREF
  UFG::qReflectHandleBase v59; // [rsp+38h] [rbp-49h] BYREF
  UFG::qReflectHandleBase v60; // [rsp+60h] [rbp-21h] BYREF
  __m128 m_quad; // [rsp+88h] [rbp+7h]
  __int128 v62; // [rsp+98h] [rbp+17h]
  void *v63; // [rsp+E8h] [rbp+67h]
  float v64; // [rsp+F0h] [rbp+6Fh]

  v60.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)-2i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&v60);
  v59.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v59, &mCollisionMeshData->mObjectProperties);
  mData = v59.mData;
  switch ( LODWORD(v59.mData[2].mBaseNode.mChildren[1]) )
  {
    case 1:
      info->m_motionType.m_storage = 5;
      break;
    case 2:
      info->m_motionType.m_storage = 1;
      break;
    case 4:
      info->m_motionType.m_storage = 4;
      break;
    case 8:
      info->m_motionType.m_storage = 3;
      break;
  }
  v8 = HIDWORD(mData[2].mBaseNode.mChildren[0]);
  if ( v8 != -1 )
    info->m_qualityType.m_storage = v8;
  info->m_shape = mesh->mShape;
  mCollisionSystem = this->mCollisionSystem;
  if ( mCollisionSystem <= 0 )
  {
    mCollisionLayerOverride = this->mCollisionLayerOverride;
    if ( mCollisionLayerOverride == -1 )
      mCollisionLayerOverride = (unsigned int)mData[2].mBaseNode.mChildren[0];
  }
  else
  {
    v10 = this->mCollisionLayerOverride;
    if ( v10 == -1 )
      v10 = (unsigned int)mData[2].mBaseNode.mChildren[0];
    mCollisionLayerOverride = v10 | (mCollisionSystem << 16) | 0x420;
  }
  info->m_collisionFilterInfo = mCollisionLayerOverride;
  info->m_mass = mesh->mMass;
  info->m_linearDamping = *(float *)&mData[1].mBaseNode.mUID;
  info->m_angularDamping = *((float *)&mData[1].mBaseNode.mUID + 1);
  info->m_friction = *(float *)(mData[4].mBaseNode.mUID + 80);
  info->m_restitution = *(float *)(mData[4].mBaseNode.mUID + 84);
  info->m_numShapeKeysInContactPointProperties = mesh->mShapeKeyDepth;
  info->m_gravityFactor = *((float *)&mData[1].vfptr + 1);
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    AudioPropertyRolling.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertyRolling", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertyRolling.mUID);
    atexit(UFG::RigidBody::CommonConstruct_::_12_::_dynamic_atexit_destructor_for__AudioPropertyRolling__);
    mData = v59.mData;
  }
  v12 = 0;
  v13 = (unsigned int)mData[3].mBaseNode.mChildren[1];
  if ( v13 )
  {
    v14 = mData[3].mBaseNode.mChildren[0];
    while ( *((_DWORD *)&v14->mUID + 2 * v12) != AudioPropertyRolling.mUID )
    {
      if ( ++v12 >= v13 )
        goto LABEL_27;
    }
    null = (UFG::qWiseSymbol *)&v14->mUID + 2 * v12 + 1;
  }
  else
  {
LABEL_27:
    null = UFG::qWiseSymbol::get_null();
  }
  if ( null->mUID )
    info->m_contactPointCallbackDelay = 4;
  if ( info->m_motionType.m_storage != 5 )
  {
    *(hkVector4f *)&v60.mNext = (hkVector4f)transform.m_quad;
    *(hkVector4f *)&v60.mNameUID = (hkVector4f)direction.m_quad;
    m_quad = stru_141A71280.m_quad;
    v62 = 0i64;
    ((void (__fastcall *)(hkpShape *, UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **, UFG::qReflectObject *, hkVector4f *))mesh->mShape->vfptr[2].__vecDelDtor)(
      mesh->mShape,
      &v60.mNext,
      mData,
      &surfaceVelocityWorld);
    v16 = _mm_add_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)check_null), 1u), 1u),
            (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&surfaceVelocityWorld), 1u), 1u));
    v64 = fminf(v16.m128_f32[0], _mm_shuffle_ps(v16, v16, 85).m128_f32[0]);
    LODWORD(v63) = _mm_shuffle_ps(v16, v16, 170).m128_u32[0];
    v17 = fminf(v64, *(float *)&v63);
    if ( v17 >= 0.050000001 )
    {
      if ( v17 >= 0.5 )
      {
        v18 = FLOAT_0_1;
        goto LABEL_36;
      }
    }
    else
    {
      v17 = FLOAT_0_050000001;
    }
    v18 = v17 * 0.2;
LABEL_36:
    info->m_allowedPenetrationDepth = v18;
  }
  m_storage = info->m_motionType.m_storage;
  if ( info->m_motionType.m_storage == 4 )
    info->m_motionType.m_storage = 1;
  v20 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v21 = ++*(_BYTE *)(v20 + 80);
  *(_DWORD *)(v20 + 4i64 * v21) = 0;
  *(_QWORD *)(v20 + 8i64 * v21 + 16) = "hkpRigidBody";
  *(_QWORD *)(v20 + 8i64 * v21 + 48) = 0i64;
  v22 = *(_BYTE *)(v20 + 81);
  if ( v21 > v22 )
    v22 = v21;
  *(_BYTE *)(v20 + 81) = v22;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
  v63 = v24;
  if ( v24 )
    hkpRigidBody::hkpRigidBody(v24, info);
  else
    v25 = 0i64;
  this->mBody = v25;
  v26 = *(_BYTE *)(v20 + 80);
  if ( v26 > 0 )
  {
    *(_BYTE *)(v20 + 80) = v26 - 1;
  }
  else
  {
    *(_BYTE *)(v20 + 80) = 0;
    *(_DWORD *)v20 = 3;
    *(_QWORD *)(v20 + 16) = 0i64;
    *(_QWORD *)(v20 + 48) = 0i64;
  }
  if ( m_storage != info->m_motionType.m_storage )
    hkpRigidBody::setMotionType(
      this->mBody,
      m_storage,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE,
      HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
  UFG::RigidBody::SetMotionType(this, this->mFlags & 0x3C0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(mesh->mPropertiesHandleGuid, this->mBody);
  UFG::CollisionMeshData::MarkBreakableParts(mesh, this, 1.0);
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = this;
  v30 = this->m_SafePointerList.mNode.mPrev;
  v30->mNext = p_simComponent;
  p_simComponent->mPrev = v30;
  this->mUserData.simComponent.mNext = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mPrev = p_simComponent;
  mBody = this->mBody;
  if ( mBody )
    mBody->m_userData = (unsigned __int64)&this->mUserData;
  v32 = 0;
  for ( i = v59.mData; v32 < LODWORD(v59.mData[3].mBaseNode.mNeighbours[1]); i = v59.mData )
  {
    v34 = (UFG::PhysicsObjectProperties::ConstraintProperty *)((char *)i[3].mBaseNode.mNeighbours[0] + 76 * v32);
    v35 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
    v63 = v35;
    if ( v35 )
      UFG::Constraint::Constraint((UFG::Constraint *)v35, v34, this->mBody);
    else
      v36 = 0i64;
    surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
    surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    *(_QWORD *)check_null = v36;
    if ( v36 )
    {
      v37 = (hkVector4f **)(v36 + 8);
      v38 = *(_QWORD *)(v36 + 8);
      *(_QWORD *)(v38 + 8) = &surfaceVelocityWorld;
      surfaceVelocityWorld.m_quad.m128_u64[0] = v38;
      surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)v37;
      *v37 = &surfaceVelocityWorld;
    }
    size = this->mConstraints.size;
    v40 = size + 1;
    capacity = this->mConstraints.capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v42 = 2 * capacity;
      else
        v42 = 1;
      for ( ; v42 < v40; v42 *= 2 )
        ;
      if ( v42 - v40 > 0x10000 )
        v42 = size + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        &this->mConstraints,
        v42,
        "qArray.Add");
    }
    this->mConstraints.size = v40;
    v43 = &this->mConstraints.p[size];
    v44 = *(UFG::Constraint **)check_null;
    if ( v43->m_pPointer )
    {
      v45 = v43->mPrev;
      v46 = v43->mNext;
      v45->mNext = v46;
      v46->mPrev = v45;
      v43->mPrev = v43;
      v43->mNext = v43;
    }
    v43->m_pPointer = v44;
    if ( v44 )
    {
      v47 = v44->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
      v47->mNext = v43;
      v43->mPrev = v47;
      v43->mNext = &v44->m_SafePointerList.mNode;
      v44->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = v43;
    }
    if ( *(_QWORD *)check_null )
    {
      v48 = surfaceVelocityWorld.m_quad;
      *(_QWORD *)(surfaceVelocityWorld.m_quad.m128_u64[0] + 8) = surfaceVelocityWorld.m_quad.m128_u64[1];
      *(_QWORD *)v48.m128_u64[1] = v48.m128_u64[0];
      surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
      surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    }
    *(_QWORD *)check_null = 0i64;
    v49 = (unsigned __int64 *)surfaceVelocityWorld.m_quad.m128_u64[1];
    v50 = surfaceVelocityWorld.m_quad.m128_u64[0];
    *(_QWORD *)(surfaceVelocityWorld.m_quad.m128_u64[0] + 8) = surfaceVelocityWorld.m_quad.m128_u64[1];
    *v49 = v50;
    surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
    surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    ++v32;
  }
  if ( (float)((float)((float)(*((float *)&i[2].mTypeUID + 1) * *((float *)&i[2].mTypeUID + 1))
                     + (float)(*(float *)&i[2].mHandles.mNode.mPrev * *(float *)&i[2].mHandles.mNode.mPrev))
             + (float)(*((float *)&i[2].mHandles.mNode.mPrev + 1) * *((float *)&i[2].mHandles.mNode.mPrev + 1))) > 0.0 )
  {
    p_m_motionState = &this->mBody->m_motion.m_motionState;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)HIDWORD(i[2].mTypeUID), (__m128)HIDWORD(i[2].mHandles.mNode.mPrev)),
                 _mm_unpacklo_ps((__m128)LODWORD(i[2].mHandles.mNode.mPrev), (__m128)0i64));
    hkVector4f::setTransformedPos(&surfaceVelocityWorld, &p_m_motionState->m_transform, &b);
    v52 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v53 = (hkpSurfaceVelocityUtil *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v52[11] + 8i64))(v52[11], 64i64);
    v54 = v53;
    v63 = v53;
    if ( v53 )
    {
      hkpSurfaceVelocityUtil::hkpSurfaceVelocityUtil(v53, this->mBody, &surfaceVelocityWorld);
      v54->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkReferencedObject};
      v54->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkpContactListener};
      v54->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkpEntityListener};
    }
    else
    {
      v54 = 0i64;
    }
    hkReferencedObject::removeReference(v54);
    i = v59.mData;
  }
  if ( (float)((float)((float)(*(float *)&i[2].mHandles.mNode.mNext * *(float *)&i[2].mHandles.mNode.mNext)
                     + (float)(*((float *)&i[2].mHandles.mNode.mNext + 1) * *((float *)&i[2].mHandles.mNode.mNext + 1)))
             + (float)(*(float *)&i[3].vfptr * *(float *)&i[3].vfptr)) > 0.0 )
  {
    v55 = this->mBody;
    b.m_quad = (__m128)v55->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
    b.m_quad = _mm_add_ps(
                 b.m_quad,
                 _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)LODWORD(i[2].mHandles.mNode.mNext), (__m128)LODWORD(i[3].vfptr)),
                   _mm_unpacklo_ps((__m128)HIDWORD(i[2].mHandles.mNode.mNext), (__m128)0i64)));
    hkpRigidBody::setCenterOfMassLocal(v55, &b);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v59);
}

// File Line: 408
// RVA: 0xADA40
void __fastcall UFG::RigidBody::OnAttach(UFG::RigidBody *this, UFG::SimObject *object)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  hkpRigidBody *mBody; // rcx
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  hkpRigidBody *v11; // rdx
  UFG::WaterFloatingTrackerBaseComponent *v12; // rax
  UFG::qReflectHandleBase v13; // [rsp+38h] [rbp-70h] BYREF

  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = this;
  if ( this )
  {
    p_m_SafePointerList = &this->m_SafePointerList;
    v8 = p_m_SafePointerList->mNode.mPrev;
    v8->mNext = p_simComponent;
    p_simComponent->mPrev = v8;
    p_simComponent->mNext = &p_m_SafePointerList->mNode;
    p_m_SafePointerList->mNode.mPrev = p_simComponent;
  }
  mBody = this->mBody;
  if ( mBody )
    mBody->m_userData = (unsigned __int64)&this->mUserData;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mRootTransformComponent,
    object);
  UFG::qReflectHandleBase::qReflectHandleBase(&v13);
  v13.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v13, &mCollisionMeshData->mObjectProperties);
  if ( !this->mWaterFloatingTrackerComponent && *((float *)&v13.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
  {
    if ( object )
    {
      v11 = this->mBody;
      if ( v11 )
      {
        if ( UFG::RigidBody::mAcquireWaterFloatingTrackerFunc )
        {
          v12 = UFG::RigidBody::mAcquireWaterFloatingTrackerFunc(this->m_pSimObject, v11);
          this->mWaterFloatingTrackerComponent = v12;
          if ( v12 )
            ((void (__fastcall *)(UFG::WaterFloatingTrackerBaseComponent *))v12->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(v12);
        }
      }
    }
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
}

// File Line: 439
// RVA: 0xAE030
void __fastcall UFG::RigidBody::OnDetach(UFG::RigidBody *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mRootTransformComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_mRootTransformComponent = &this->mRootTransformComponent;
  if ( this->mRootTransformComponent.m_pSimComponent )
  {
    mNext = this->mRootTransformComponent.mNext;
    mPrev = p_mRootTransformComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRootTransformComponent->mNext = p_mRootTransformComponent;
    p_mRootTransformComponent->mPrev = p_mRootTransformComponent;
    p_mRootTransformComponent->m_Changed = 1;
    p_mRootTransformComponent->m_pSimComponent = 0i64;
    p_mRootTransformComponent->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mRootTransformComponent.m_pSimObject
      && (p_mRootTransformComponent->mPrev != p_mRootTransformComponent
       || this->mRootTransformComponent.mNext != &this->mRootTransformComponent) )
    {
      v4 = this->mRootTransformComponent.mNext;
      v5 = p_mRootTransformComponent->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_mRootTransformComponent->mNext = p_mRootTransformComponent;
      p_mRootTransformComponent->mPrev = p_mRootTransformComponent;
      p_mRootTransformComponent->m_pSimObject = 0i64;
    }
    p_mRootTransformComponent->m_Changed = 1;
  }
}

// File Line: 447
// RVA: 0xABAC0
void __fastcall UFG::RigidBody::Inflate(UFG::RigidBody *this, bool addToWorld)
{
  UFG::CollisionInstanceData *mInstanceData; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  unsigned int *v6; // rax
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  float v12; // xmm0_4
  UFG::CollisionMeshData *v13; // r8
  UFG::BasePhysicsSystem *v14; // r14
  UFG::WindAction *v15; // r15
  hkpRigidBody *mBody; // rsi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToAdd; // rdi
  unsigned int i; // esi
  hkpConstraintInstance *mConstraintInstance; // rbp
  UFG::WaterFloatingTrackerBaseComponent *mWaterFloatingTrackerComponent; // rcx
  UFG::qReflectObject *mData; // rax
  UFG::SimObject *m_pSimObject; // rcx
  hkpRigidBody *v23; // rdx
  UFG::WaterFloatingTrackerBaseComponent *v24; // rax
  _QWORD **Value; // rax
  UFG::WindAction *v26; // rax
  UFG::WindAction *v27; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  hkpRigidBody *v32; // rcx
  UFG::qReflectHandleBase v33; // [rsp+30h] [rbp-168h] BYREF
  __int64 v34; // [rsp+58h] [rbp-140h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+60h] [rbp-138h] BYREF

  v34 = -2i64;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
  mInstanceData = this->mInstanceData;
  bodyInfo.m_position = mInstanceData->mPosition;
  bodyInfo.m_rotation = mInstanceData->mOrientation;
  UFG::qReflectHandleBase::qReflectHandleBase(&v33);
  v33.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v33, &mCollisionMeshData->mObjectProperties);
  v6 = (unsigned int *)this->mCollisionMeshData;
  v7 = _mm_shuffle_ps(
         (__m128)HIDWORD(v33.mData[1].mBaseNode.mChildren[0]),
         (__m128)HIDWORD(v33.mData[1].mBaseNode.mChildren[0]),
         0);
  v8 = _mm_mul_ps(
         _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v6[27], (__m128)v6[29]), _mm_unpacklo_ps((__m128)v6[28], (__m128)0i64)),
         v7);
  v9 = _mm_mul_ps(
         _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v6[30], (__m128)v6[32]), _mm_unpacklo_ps((__m128)v6[31], (__m128)0i64)),
         v7);
  v10 = _mm_mul_ps(
          _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v6[33], (__m128)v6[35]),
            _mm_unpacklo_ps((__m128)v6[34], (__m128)0i64)),
          v7);
  v11 = _mm_unpacklo_ps(v8, v9);
  bodyInfo.m_inertiaTensor.m_col0.m_quad = _mm_movelh_ps(v11, v10);
  bodyInfo.m_inertiaTensor.m_col1.m_quad = _mm_shuffle_ps(
                                             _mm_movehl_ps(bodyInfo.m_inertiaTensor.m_col0.m_quad, v11),
                                             v10,
                                             212);
  bodyInfo.m_inertiaTensor.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v8, v9), v10, 228);
  v12 = *(float *)&v33.mData[1].mBaseNode.mChildren[1];
  if ( v12 != -1.0 )
    hkpInertiaTensorComputer::clipInertia(v12, &bodyInfo);
  v13 = this->mCollisionMeshData;
  bodyInfo.m_centerOfMass.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps(
                                       (__m128)LODWORD(v13->mCentreOfMass.x),
                                       (__m128)LODWORD(v13->mCentreOfMass.z)),
                                     _mm_unpacklo_ps((__m128)LODWORD(v13->mCentreOfMass.y), (__m128)0i64));
  UFG::RigidBody::CommonConstruct(this, &bodyInfo, v13);
  this->mFlags |= 2u;
  v14 = UFG::BasePhysicsSystem::mInstance;
  v15 = 0i64;
  if ( addToWorld )
  {
    mBody = this->mBody;
    p_mEntitiesToAdd = &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd;
    if ( UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size == (UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd,
        8);
    p_mEntitiesToAdd->m_data[v14->mEntitiesToAdd.m_size++] = mBody;
    for ( i = 0; i < this->mConstraints.size; ++i )
    {
      mConstraintInstance = this->mConstraints.p[i].m_pPointer->mConstraintInstance;
      if ( mConstraintInstance )
      {
        if ( v14->mConstraintsToAdd.m_size == (v14->mConstraintsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v14->mConstraintsToAdd, 8);
        v14->mConstraintsToAdd.m_data[v14->mConstraintsToAdd.m_size++] = mConstraintInstance;
        hkReferencedObject::addReference(mConstraintInstance);
      }
    }
  }
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
  {
    mWaterFloatingTrackerComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor(
      mWaterFloatingTrackerComponent,
      (unsigned int)this->mBody);
LABEL_22:
    mData = v33.mData;
    goto LABEL_23;
  }
  mData = v33.mData;
  if ( *((float *)&v33.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      v23 = this->mBody;
      if ( v23 )
      {
        if ( UFG::RigidBody::mAcquireWaterFloatingTrackerFunc )
        {
          v24 = UFG::RigidBody::mAcquireWaterFloatingTrackerFunc(m_pSimObject, v23);
          this->mWaterFloatingTrackerComponent = v24;
          if ( v24 )
            ((void (__fastcall *)(UFG::WaterFloatingTrackerBaseComponent *))v24->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(v24);
          goto LABEL_22;
        }
      }
    }
  }
LABEL_23:
  if ( BYTE5(mData[1].mHandles.mNode.mNext) )
  {
    if ( !this->mWindAction )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (UFG::WindAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
      if ( v26 )
      {
        UFG::WindAction::WindAction(v26, this->mBody, *(float *)v33.mData[1].mBaseNode.mNeighbours);
        v15 = v27;
      }
      this->mWindAction = v15;
    }
    UFG::BasePhysicsSystem::AddAction(v14, this->mWindAction);
    hkpRigidBody::enableDeactivation(this->mBody, 0);
  }
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = this;
  v31 = this->m_SafePointerList.mNode.mPrev;
  v31->mNext = p_simComponent;
  p_simComponent->mPrev = v31;
  this->mUserData.simComponent.mNext = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mPrev = p_simComponent;
  v32 = this->mBody;
  if ( v32 )
    v32->m_userData = (unsigned __int64)&this->mUserData;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v33);
}

// File Line: 541
// RVA: 0xA68C0
_BOOL8 __fastcall UFG::RigidBody::Deflate(UFG::RigidBody *this)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rcx
  UFG::WaterFloatingTrackerBaseComponent *mWaterFloatingTrackerComponent; // rcx
  UFG::WindAction *mWindAction; // rdx
  UFG::BasePhysicsSystem *v5; // r10
  int v6; // r8d
  __int64 v7; // r9
  __int64 v8; // rax
  hkpWorld *m_world; // rcx
  UFG::BasePhysicsSystem *v10; // rbp
  unsigned int i; // ebx
  __int64 v12; // rsi
  UFG::Constraint *m_pPointer; // rdx
  UFG::Constraint *v14; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // rcx
  UFG::Constraint **p_m_pPointer; // rbx
  hkpRigidBody *mBody; // rcx
  bool v18; // zf
  bool v19; // sf
  bool v20; // of
  bool v21; // bl

  this->mInstanceData->mPosition = this->mBody->m_motion.m_motionState.m_transform.m_translation;
  this->mInstanceData->mOrientation = this->mBody->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  UFG::RigidBody::RemoveFromWorld(this);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
  {
    UFG::CollisionMeshData::UnmarkBreakableParts(mCollisionMeshData, this->mBody);
    UFG::CollisionMeshData::ResetFracture(this->mCollisionMeshData);
  }
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
    ((void (__fastcall *)(UFG::WaterFloatingTrackerBaseComponent *))mWaterFloatingTrackerComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor)(mWaterFloatingTrackerComponent);
  mWindAction = this->mWindAction;
  if ( mWindAction )
  {
    v5 = UFG::BasePhysicsSystem::mInstance;
    v6 = 0;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        if ( v5->mActionsToAdd.m_data[v7] == mWindAction )
        {
          v8 = --v5->mActionsToAdd.m_size;
          if ( (_DWORD)v8 != v6 )
            v5->mActionsToAdd.m_data[v7] = v5->mActionsToAdd.m_data[v8];
          --v6;
          --v7;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v5->mActionsToAdd.m_size );
    }
    m_world = mWindAction->m_world;
    if ( m_world )
      hkpWorld::removeAction(m_world, mWindAction);
    hkReferencedObject::removeReference(this->mWindAction);
    this->mWindAction = 0i64;
  }
  v10 = UFG::BasePhysicsSystem::mInstance;
  for ( i = 0; i < this->mConstraints.size; ++i )
  {
    v12 = i;
    m_pPointer = this->mConstraints.p[v12].m_pPointer;
    if ( m_pPointer )
    {
      UFG::BasePhysicsSystem::RemoveConstraint(v10, m_pPointer->mConstraintInstance);
      v14 = this->mConstraints.p[v12].m_pPointer;
      if ( v14 )
        v14->vfptr->__vecDelDtor(v14, 1u);
    }
  }
  p = this->mConstraints.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](p_m_pPointer);
  }
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
  mBody = this->mBody;
  v20 = __OFSUB__(mBody->m_referenceCount, 1);
  v18 = mBody->m_referenceCount == 1;
  v19 = (__int16)(mBody->m_referenceCount - 1) < 0;
  mBody->m_userData = 0i64;
  v21 = !(v19 ^ v20 | v18);
  hkReferencedObject::removeReference(this->mBody);
  this->mFlags &= ~2u;
  this->mBody = 0i64;
  return v21;
}

// File Line: 604
// RVA: 0xAF9E0
void __fastcall UFG::RigidBody::RemoveFromWorld(UFG::RigidBody *this)
{
  UFG::WindAction *mWindAction; // rdx
  UFG::BasePhysicsSystem *v2; // rbx
  int v3; // esi
  int v5; // r8d
  __int64 v6; // r9
  __int64 v7; // rax
  hkpWorld *m_world; // rcx
  unsigned int i; // edi
  UFG::Constraint *m_pPointer; // rdx
  hkpRigidBody *mBody; // rdi
  __int64 m_size; // rdx
  __int64 v13; // rcx
  hkpEntity **m_data; // rax
  __int64 v15; // rax
  hkpWorld *v16; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToRemove; // rbx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  mWindAction = this->mWindAction;
  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = 0;
  if ( mWindAction )
  {
    v5 = 0;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        if ( v2->mActionsToAdd.m_data[v6] == mWindAction )
        {
          v7 = --v2->mActionsToAdd.m_size;
          if ( (_DWORD)v7 != v5 )
            v2->mActionsToAdd.m_data[v6] = v2->mActionsToAdd.m_data[v7];
          --v5;
          --v6;
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v2->mActionsToAdd.m_size );
    }
    m_world = mWindAction->m_world;
    if ( m_world )
      hkpWorld::removeAction(m_world, mWindAction);
  }
  for ( i = 0; i < this->mConstraints.size; ++i )
  {
    m_pPointer = this->mConstraints.p[i].m_pPointer;
    if ( m_pPointer )
      UFG::BasePhysicsSystem::RemoveConstraint(v2, m_pPointer->mConstraintInstance);
  }
  mBody = this->mBody;
  if ( mBody )
  {
    m_size = v2->mEntitiesToAdd.m_size;
    v13 = 0i64;
    if ( m_size > 0 )
    {
      m_data = v2->mEntitiesToAdd.m_data;
      while ( *m_data != mBody )
      {
        ++v13;
        ++v3;
        ++m_data;
        if ( v13 >= m_size )
          goto LABEL_23;
      }
      v15 = --v2->mEntitiesToAdd.m_size;
      if ( (_DWORD)v15 != v3 )
        v2->mEntitiesToAdd.m_data[v3] = v2->mEntitiesToAdd.m_data[v15];
    }
LABEL_23:
    v16 = mBody->m_world;
    if ( v16 )
    {
      if ( v2->mForceRemoveEntitiesToBeBatched )
      {
        p_mEntitiesToRemove = &v2->mEntitiesToRemove;
        if ( p_mEntitiesToRemove->m_size == (p_mEntitiesToRemove->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mEntitiesToRemove, 8);
        p_mEntitiesToRemove->m_data[p_mEntitiesToRemove->m_size++] = mBody;
        hkReferencedObject::addReference(mBody);
      }
      else
      {
        hkpWorld::removeEntity(v16, &result, mBody);
      }
    }
  }
}

// File Line: 629
// RVA: 0xB0380
void __fastcall UFG::RigidBody::ResourceUnloaded(UFG::RigidBody *this, UFG::PhysicsResourceHandle *res)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdi

  mPrev = this->mCollisionMeshBundle.mPrev;
  this->mRootTransformComponent.m_TypeUID |= 8u;
  *(_QWORD *)&this->mUserData.isBoat = 0i64;
  if ( mPrev )
  {
    if ( ((__int64 (__fastcall *)(UFG::SimObject **, UFG::PhysicsResourceHandle *))this[-1].mRootTransformComponent.m_pSimObject[1].vfptr)(
           &this[-1].mRootTransformComponent.m_pSimObject,
           res) )
    {
      mPrev[2].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)UFG::BasePhysicsSystem::mDummyShape;
    }
    this->mUserData.simComponent.m_pPointer = 0i64;
  }
  else
  {
    this->mUserData.simComponent.m_pPointer = 0i64;
  }
}

// File Line: 672
// RVA: 0xAAC10
__int64 __fastcall UFG::RigidBody::GetNumFracturableParts(UFG::RigidBody *this)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  __int64 mOffset; // rax

  mCollisionMeshData = this->mCollisionMeshData;
  mOffset = mCollisionMeshData->mPartDetails.mOffset;
  if ( mOffset
    && (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
  {
    return mCollisionMeshData->mNumParts;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 680
// RVA: 0xACCD0
__int64 __fastcall UFG::RigidBody::IsPartFractured(UFG::RigidBody *this, unsigned int index)
{
  BitArray256 *mFractureState; // r8

  mFractureState = this->mFractureState;
  if ( mFractureState )
    return mFractureState->mBits[(unsigned __int64)index >> 5] & (1 << (index & 0x1F));
  else
    return 0i64;
}

// File Line: 687
// RVA: 0xABA60
char __fastcall UFG::RigidBody::HasFracturedParts(UFG::RigidBody *this)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rax
  BitArray256 *mFractureState; // r9
  unsigned int mNumParts; // r8d
  unsigned int v4; // eax
  unsigned int v5; // ecx

  mCollisionMeshData = this->mCollisionMeshData;
  if ( !mCollisionMeshData )
    return 0;
  mFractureState = this->mFractureState;
  if ( !mFractureState )
    return 0;
  mNumParts = mCollisionMeshData->mNumParts;
  v4 = 0;
  if ( !mNumParts )
    return 0;
  while ( 1 )
  {
    v5 = mFractureState->mBits[(unsigned __int64)v4 >> 5];
    if ( _bittest((const int *)&v5, v4 & 0x1F) )
      break;
    if ( ++v4 >= mNumParts )
      return 0;
  }
  return 1;
}

// File Line: 706
// RVA: 0xA7C50
void __fastcall UFG::RigidBody::EnableFractureParts(UFG::RigidBody *this, UFG::RigidBody::FractureStrength strength)
{
  UFG::CollisionMeshData *mCollisionMeshData; // r8
  __int64 mOffset; // rax
  UFG::Destruction *v6; // r13
  unsigned int v7; // esi
  __int64 mNumParts; // r14
  __int64 v9; // rbp
  __int64 v10; // rdi
  UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *p_mPartDetails; // rax
  __int64 v12; // rcx
  float v13; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *p_mParts; // rax
  char *v15; // r8
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-60h] BYREF

  if ( this->mBody )
  {
    mCollisionMeshData = this->mCollisionMeshData;
    if ( mCollisionMeshData )
    {
      mOffset = mCollisionMeshData->mPartDetails.mOffset;
      if ( mOffset )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails
                                                                     + mOffset) )
        {
          v6 = UFG::Destruction::mInstance;
          v7 = 0;
          mNumParts = mCollisionMeshData->mNumParts;
          if ( mCollisionMeshData->mNumParts )
          {
            v9 = 0i64;
            v10 = 0i64;
            do
            {
              p_mPartDetails = &this->mCollisionMeshData->mPartDetails;
              v12 = p_mPartDetails->mOffset;
              if ( p_mPartDetails->mOffset )
                v12 += (__int64)p_mPartDetails;
              if ( v10 + v12 )
              {
                v13 = *(float *)(v10 + v12 + 68);
                if ( v13 > 0.0 )
                {
                  if ( strength == FRACTURE_STRENGTH_ALTERNATE )
                  {
                    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
                    v16.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                    p_mParts = &this->mCollisionMeshData->mParts;
                    if ( p_mParts->mOffset )
                      v15 = (char *)p_mParts + p_mParts->mOffset;
                    else
                      v15 = 0i64;
                    UFG::qReflectHandleBase::Init(&v16, v16.mTypeUID, *(_QWORD *)&v15[v9 + 16]);
                    if ( v16.mData )
                    {
                      if ( *(float *)v16.mData[1].mBaseNode.mChildren > 0.0 )
                        v13 = *(float *)v16.mData[1].mBaseNode.mChildren;
                    }
                    UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
                  }
                  hkpBreakOffPartsUtil::markPieceBreakable(v6->mBreakOffPartsUtil, this->mBody, v7, v13);
                }
              }
              ++v7;
              v10 += 96i64;
              v9 += 48i64;
              --mNumParts;
            }
            while ( mNumParts );
          }
        }
      }
    }
  }
}

// File Line: 739
// RVA: 0xA7670
void __fastcall UFG::RigidBody::DisableFractureParts(UFG::RigidBody *this)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  __int64 mOffset; // rax
  __int64 mNumParts; // rbp
  unsigned int v5; // edi
  __int64 v6; // rbx
  UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *p_mPartDetails; // rax
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v9; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( this->mBody )
  {
    mCollisionMeshData = this->mCollisionMeshData;
    if ( mCollisionMeshData )
    {
      mOffset = mCollisionMeshData->mPartDetails.mOffset;
      if ( mOffset )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails
                                                                     + mOffset) )
        {
          mNumParts = mCollisionMeshData->mNumParts;
          v5 = 0;
          if ( mCollisionMeshData->mNumParts )
          {
            v6 = 0i64;
            do
            {
              p_mPartDetails = &this->mCollisionMeshData->mPartDetails;
              v8 = p_mPartDetails->mOffset;
              if ( p_mPartDetails->mOffset )
                v8 += (__int64)p_mPartDetails;
              if ( v6 + v8 && *(float *)(v6 + v8 + 68) > 0.0 )
              {
                v9 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((unsigned __int64)this->mBody->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
                if ( v9 )
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                    v9 + 3,
                    &result,
                    v5);
              }
              ++v5;
              v6 += 96i64;
              --mNumParts;
            }
            while ( mNumParts );
          }
        }
      }
    }
  }
}

// File Line: 761
// RVA: 0xA7920
__int64 __fastcall UFG::RigidBody::EnableFracturePartByGuid(
        UFG::RigidBody *this,
        unsigned int nodeId,
        UFG::RigidBody::FractureStrength strength)
{
  unsigned __int8 v6; // r9
  UFG::CollisionMeshData *mCollisionMeshData; // r10
  __int64 mOffset; // rax
  UFG::Destruction *v9; // r13
  unsigned int v10; // esi
  __int64 mNumParts; // r14
  __int64 v12; // rbp
  __int64 v13; // rdi
  UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *p_mPartDetails; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  float v17; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *p_mParts; // rax
  char *v19; // r8
  UFG::qReflectHandleBase v21; // [rsp+28h] [rbp-70h] BYREF

  v6 = 0;
  if ( this->mBody )
  {
    mCollisionMeshData = this->mCollisionMeshData;
    if ( mCollisionMeshData )
    {
      mOffset = mCollisionMeshData->mPartDetails.mOffset;
      if ( mOffset )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails
                                                                     + mOffset) )
        {
          v9 = UFG::Destruction::mInstance;
          v10 = 0;
          mNumParts = mCollisionMeshData->mNumParts;
          if ( mCollisionMeshData->mNumParts )
          {
            v12 = 0i64;
            v13 = 0i64;
            do
            {
              p_mPartDetails = &this->mCollisionMeshData->mPartDetails;
              v15 = p_mPartDetails->mOffset;
              if ( p_mPartDetails->mOffset )
                v15 += (__int64)p_mPartDetails;
              v16 = v13 + v15;
              if ( v13 + v15 )
              {
                if ( *(_DWORD *)(v16 + 88) == nodeId )
                {
                  v17 = *(float *)(v16 + 68);
                  if ( v17 > 0.0 )
                  {
                    if ( strength == FRACTURE_STRENGTH_ALTERNATE )
                    {
                      UFG::qReflectHandleBase::qReflectHandleBase(&v21);
                      v21.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                      p_mParts = &this->mCollisionMeshData->mParts;
                      if ( p_mParts->mOffset )
                        v19 = (char *)p_mParts + p_mParts->mOffset;
                      else
                        v19 = 0i64;
                      UFG::qReflectHandleBase::Init(&v21, v21.mTypeUID, *(_QWORD *)&v19[v12 + 16]);
                      if ( v21.mData && *(float *)v21.mData[1].mBaseNode.mChildren > 0.0 )
                        v17 = *(float *)v21.mData[1].mBaseNode.mChildren;
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v21);
                    }
                    hkpBreakOffPartsUtil::markPieceBreakable(v9->mBreakOffPartsUtil, this->mBody, v10, v17);
                    v6 = 1;
                  }
                }
              }
              ++v10;
              v13 += 96i64;
              v12 += 48i64;
              --mNumParts;
            }
            while ( mNumParts );
          }
        }
      }
    }
  }
  return v6;
}

// File Line: 798
// RVA: 0xA7AE0
char __fastcall UFG::RigidBody::EnableFracturePartByIndex(
        UFG::RigidBody *this,
        unsigned int index,
        UFG::RigidBody::FractureStrength strength)
{
  __int64 v3; // rsi
  UFG::CollisionMeshData *mCollisionMeshData; // r9
  __int64 mOffset; // rax
  UFG::Destruction *v7; // rbp
  __int64 v8; // rax
  char *v9; // rdi
  __int64 v10; // rdx
  __int64 v11; // rcx
  float v12; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *p_mParts; // rax
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-50h] BYREF

  v3 = index;
  if ( !this->mBody )
    return 0;
  mCollisionMeshData = this->mCollisionMeshData;
  if ( !mCollisionMeshData )
    return 0;
  mOffset = mCollisionMeshData->mPartDetails.mOffset;
  if ( !mOffset
    || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
  {
    return 0;
  }
  v7 = UFG::Destruction::mInstance;
  v8 = mCollisionMeshData->mPartDetails.mOffset;
  v9 = 0i64;
  v10 = v8 ? (__int64)&mCollisionMeshData->mPartDetails + v8 : 0i64;
  v11 = v10 + 96i64 * (int)v3;
  if ( !v11 )
    return 0;
  v12 = *(float *)(v11 + 68);
  if ( v12 <= 0.0 )
    return 0;
  if ( strength == FRACTURE_STRENGTH_ALTERNATE )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v15);
    v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    p_mParts = &this->mCollisionMeshData->mParts;
    if ( p_mParts->mOffset )
      v9 = (char *)p_mParts + p_mParts->mOffset;
    UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, *(_QWORD *)&v9[48 * v3 + 16]);
    if ( v15.mData )
    {
      if ( *(float *)v15.mData[1].mBaseNode.mChildren > 0.0 )
        v12 = *(float *)v15.mData[1].mBaseNode.mChildren;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
  }
  hkpBreakOffPartsUtil::markPieceBreakable(v7->mBreakOffPartsUtil, this->mBody, v3, v12);
  return 1;
}

// File Line: 832
// RVA: 0xA74B0
__int64 __fastcall UFG::RigidBody::DisableFracturePartByGuid(UFG::RigidBody *this, unsigned int nodeId)
{
  unsigned __int8 v2; // r8
  UFG::CollisionMeshData *mCollisionMeshData; // r9
  __int64 mOffset; // rax
  __int64 mNumParts; // rbp
  unsigned int v8; // edi
  UFG::Destruction *v9; // r15
  __int64 v10; // rbx
  UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *p_mPartDetails; // rax
  __int64 v12; // rcx
  __int64 v13; // rax

  v2 = 0;
  if ( !this->mBody )
    return 0i64;
  mCollisionMeshData = this->mCollisionMeshData;
  if ( !mCollisionMeshData )
    return 0i64;
  mOffset = mCollisionMeshData->mPartDetails.mOffset;
  if ( !mOffset
    || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
  {
    return 0i64;
  }
  mNumParts = mCollisionMeshData->mNumParts;
  v8 = 0;
  v9 = UFG::Destruction::mInstance;
  if ( !mCollisionMeshData->mNumParts )
    return 0i64;
  v10 = 0i64;
  do
  {
    p_mPartDetails = &this->mCollisionMeshData->mPartDetails;
    v12 = p_mPartDetails->mOffset;
    if ( p_mPartDetails->mOffset )
      v12 += (__int64)p_mPartDetails;
    v13 = v10 + v12;
    if ( v10 + v12 && *(_DWORD *)(v13 + 88) == nodeId && *(float *)(v13 + 68) > 0.0 )
    {
      hkpBreakOffPartsUtil::unmarkPieceBreakable(v9->mBreakOffPartsUtil, this->mBody, v8);
      v2 = 1;
    }
    ++v8;
    v10 += 96i64;
    --mNumParts;
  }
  while ( mNumParts );
  return v2;
}

// File Line: 858
// RVA: 0xA75D0
char __fastcall UFG::RigidBody::DisableFracturePartByIndex(UFG::RigidBody *this, int index)
{
  hkpRigidBody *mBody; // r9
  __int64 v3; // r10
  UFG::CollisionMeshData *mCollisionMeshData; // rcx
  __int64 mOffset; // rax
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8

  mBody = this->mBody;
  v3 = index;
  if ( !mBody )
    return 0;
  mCollisionMeshData = this->mCollisionMeshData;
  if ( !mCollisionMeshData )
    return 0;
  mOffset = mCollisionMeshData->mPartDetails.mOffset;
  if ( !mOffset
    || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
  {
    return 0;
  }
  v6 = mCollisionMeshData->mPartDetails.mOffset;
  v7 = v6 ? (__int64)&mCollisionMeshData->mPartDetails + v6 : 0i64;
  v8 = v7 + 96 * v3;
  if ( !v8 || *(float *)(v8 + 68) <= 0.0 )
    return 0;
  hkpBreakOffPartsUtil::unmarkPieceBreakable(UFG::Destruction::mInstance->mBreakOffPartsUtil, mBody, v3);
  return 1;
}

// File Line: 882
// RVA: 0xAB1C0
float __fastcall UFG::RigidBody::GetPercentFractured(UFG::RigidBody *this)
{
  hkpShape *mShape; // rbx

  mShape = this->mCollisionMeshData->mShape;
  if ( mShape->m_type.m_storage == 8 )
    return (float)WORD1(mShape[2].vfptr)
         / (float)((float)WORD1(mShape[2].vfptr)
                 + (float)((int (__fastcall *)(hkpShape *))mShape[1].vfptr->__first_virtual_table_function__)(&mShape[1]));
  else
    return 0.0;
}

// File Line: 908
// RVA: 0xAB650
void __fastcall UFG::RigidBody::GetTransform(UFG::RigidBody *this, UFG::qMatrix44 *mat)
{
  hkpRigidBody *mBody; // rcx
  UFG::CollisionInstanceData *mInstanceData; // rdx
  hkTransformf v6; // [rsp+20h] [rbp-48h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    hkTransformf::get4x4ColumnMajor(&mBody->m_motion.m_motionState.m_transform, &mat->v0.x);
  }
  else
  {
    mInstanceData = this->mInstanceData;
    v6.m_translation = mInstanceData->mPosition;
    hkRotationf::set(&v6.m_rotation, &mInstanceData->mOrientation);
    hkTransformf::get4x4ColumnMajor(&v6, &mat->v0.x);
  }
}

// File Line: 926
// RVA: 0xB2630
void __fastcall UFG::RigidBody::SetTransform(UFG::RigidBody *this, UFG::qMatrix44 *mat)
{
  hkpRigidBody *mBody; // rcx
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  hkTransformf::set4x4ColumnMajor(&transform, &mat->v0.x);
  mBody = this->mBody;
  if ( mBody )
  {
    hkpRigidBody::setTransform(mBody, &transform);
  }
  else
  {
    hkQuaternionf::set(&this->mInstanceData->mOrientation, &transform.m_rotation);
    this->mInstanceData->mPosition = transform.m_translation;
  }
}

// File Line: 946
// RVA: 0xAB970
UFG::qVector3 *__fastcall UFG::RigidBody::GetVelocity(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *mBody; // r8
  float y; // xmm1_4
  float z; // xmm0_4

  mBody = this->mBody;
  y = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  if ( mBody )
    *result = *(UFG::qVector3 *)mBody->m_motion.m_linearVelocity.m_quad.m128_i8;
  return result;
}

// File Line: 961
// RVA: 0xA9550
UFG::qVector3 *__fastcall UFG::RigidBody::GetAngularVelocity(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *mBody; // r8
  float y; // xmm1_4
  float z; // xmm0_4

  mBody = this->mBody;
  y = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  z = UFG::qVector3::msZero.z;
  result->y = y;
  result->z = z;
  if ( mBody )
    *result = *(UFG::qVector3 *)mBody->m_motion.m_angularVelocity.m_quad.m128_i8;
  return result;
}

// File Line: 976
// RVA: 0xB2850
void __fastcall UFG::RigidBody::SetVelocity(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate(v3);
    mBody->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&mBody->m_motion, (unsigned int)&v4);
  }
}

// File Line: 988
// RVA: 0xB05D0
void __fastcall UFG::RigidBody::SetAngularVelocity(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate(v3);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))mBody->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
      &mBody->m_motion,
      &v4);
  }
}

// File Line: 1007
// RVA: 0xA0EA0
void __fastcall UFG::RigidBody::ApplyForce(
        UFG::RigidBody *this,
        float timeDelta,
        UFG::qVector3 *force,
        UFG::qVector3 *point)
{
  hkpRigidBody *mBody; // rbx
  __m128 v5; // xmm3
  __int64 v6; // rdx
  __m128 v7; // [rsp+20h] [rbp-38h] BYREF
  __m128 v8; // [rsp+30h] [rbp-28h] BYREF

  mBody = this->mBody;
  v5 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(point->x), (__m128)LODWORD(point->z)),
         _mm_unpacklo_ps((__m128)LODWORD(point->y), (__m128)(unsigned int)FLOAT_1_0));
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(force->x), (__m128)LODWORD(force->z)),
         _mm_unpacklo_ps((__m128)LODWORD(force->y), (__m128)(unsigned int)FLOAT_1_0));
  v7 = v5;
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, __m128 *))mBody->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
    &mBody->m_motion,
    v6,
    &v8,
    &v7);
}

// File Line: 1018
// RVA: 0xA1080
void __fastcall UFG::RigidBody::ApplyLinearImpulse(UFG::RigidBody *this, UFG::qVector3 *impulse)
{
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
           _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    hkpEntity::activate(v3);
    mBody->m_motion.hkpEntity::vfptr[11].__vecDelDtor(&mBody->m_motion, (unsigned int)&v4);
  }
}

// File Line: 1030
// RVA: 0xA1000
void __fastcall UFG::RigidBody::ApplyLinearImpulse(UFG::RigidBody *this, UFG::qVector3 *impulse, UFG::qVector3 *point)
{
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v4; // rcx
  __m128 z_low; // xmm0
  __m128 y_low; // xmm2
  __m128 v7; // [rsp+20h] [rbp-28h] BYREF
  __m128 v8; // [rsp+30h] [rbp-18h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    v4 = this->mBody;
    z_low = (__m128)LODWORD(point->z);
    y_low = (__m128)LODWORD(point->y);
    v8 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
           _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    v7 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(point->x), z_low), _mm_unpacklo_ps(y_low, (__m128)0i64));
    hkpEntity::activate(v4);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))mBody->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
      &mBody->m_motion,
      &v8,
      &v7);
  }
}

// File Line: 1043
// RVA: 0xA0BC0
void __fastcall UFG::RigidBody::ApplyAngularImpulse(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *mBody; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate(v3);
    mBody->m_motion.hkpEntity::vfptr[12].__vecDelDtor(&mBody->m_motion, (unsigned int)&v4);
  }
}

// File Line: 1055
// RVA: 0xB13D0
void __fastcall UFG::RigidBody::SetLinearDamping(UFG::RigidBody *this, float d)
{
  hkpRigidBody *mBody; // rdx
  float v3; // [rsp+8h] [rbp+8h]

  mBody = this->mBody;
  if ( mBody )
  {
    v3 = d * 1.0039062;
    mBody->m_motion.m_motionState.m_linearDamping.m_value = HIWORD(v3);
  }
}

// File Line: 1079
// RVA: 0xACD30
bool __fastcall UFG::RigidBody::IsSleeping(UFG::RigidBody *this)
{
  hkpRigidBody *mBody; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  mBody = this->mBody;
  return !mBody || hkpEntity::isActive(mBody, &result)->m_bool == 0;
}

// File Line: 1086
// RVA: 0xAA990
double __fastcall UFG::RigidBody::GetMass(UFG::RigidBody *this)
{
  hkpRigidBody *mBody; // rax
  double result; // xmm0_8

  mBody = this->mBody;
  if ( mBody )
    *(float *)&result = hkpMotion::getMass(&mBody->m_motion);
  else
    *(_QWORD *)&result = LODWORD(this->mCollisionMeshData->mMass);
  return result;
}

// File Line: 1103
// RVA: 0xA9730
UFG::qVector3 *__fastcall UFG::RigidBody::GetCentreOfMass(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *mBody; // r8
  UFG::CollisionInstanceData *mInstanceData; // rcx

  mBody = this->mBody;
  if ( mBody )
  {
    *result = *(UFG::qVector3 *)mBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_i8;
  }
  else
  {
    mInstanceData = this->mInstanceData;
    LODWORD(result->x) = mInstanceData->mPosition.m_quad.m128_i32[0];
    LODWORD(result->y) = mInstanceData->mPosition.m_quad.m128_i32[1];
    LODWORD(result->z) = mInstanceData->mPosition.m_quad.m128_i32[2];
  }
  return result;
}

// File Line: 1123
// RVA: 0xA0300
void __fastcall UFG::RigidBody::AddConstraint(UFG::RigidBody *this, UFG::Constraint *constraint)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int64 size; // rsi
  unsigned int v5; // ebx
  unsigned int capacity; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *p_mPrev; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+30h] [rbp-10h]
  UFG::Constraint *v19; // [rsp+38h] [rbp-8h]

  v17 = (__int64 *)&v17;
  p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = constraint;
  if ( constraint )
  {
    mPrev = constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)mPrev;
    p_m_SafePointerList = &constraint->m_SafePointerList;
    constraint->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
  }
  size = this->mConstraints.size;
  v5 = size + 1;
  capacity = this->mConstraints.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
      &this->mConstraints,
      v7,
      "qArray.Add");
  }
  this->mConstraints.size = v5;
  v8 = &this->mConstraints.p[size];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    mNext = v8->mNext;
    v10->mNext = mNext;
    mNext->mPrev = v10;
    v8->mPrev = v8;
    v8->mNext = v8;
  }
  v8->m_pPointer = (UFG::Constraint *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = v8;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    p_mPrev = &p_m_SafePointerList->mNode.mPrev;
    v17[1] = (__int64)p_m_SafePointerList;
    *p_mPrev = v13;
    v17 = (__int64 *)&v17;
    p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &p_m_SafePointerList->mNode.mPrev;
  v17[1] = (__int64)p_m_SafePointerList;
  *v16 = v15;
}

// File Line: 1130
// RVA: 0xAF6C0
void __fastcall UFG::RigidBody::RemoveConstraint(UFG::RigidBody *this, UFG::Constraint *constraint)
{
  unsigned int size; // r10d
  __int64 v3; // r8
  UFG::Constraint **i; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // rdx
  bool v7; // zf
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // r8
  UFG::Constraint *m_pPointer; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  unsigned int v13; // eax

  size = this->mConstraints.size;
  v3 = 0i64;
  if ( size )
  {
    for ( i = &this->mConstraints.p->m_pPointer; constraint != *i; i += 3 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= size )
        return;
    }
    p = this->mConstraints.p;
    v7 = p[v3].m_pPointer == 0i64;
    v8 = &p[v3];
    m_pPointer = p[size - 1].m_pPointer;
    if ( !v7 )
    {
      mPrev = v8->mPrev;
      mNext = v8->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v8->mPrev = v8;
      v8->mNext = v8;
    }
    v8->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v12 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev;
      v12->mNext = v8;
      v8->mPrev = v12;
      v8->mNext = &m_pPointer->m_SafePointerList.mNode;
      m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Constraint>::mPrev = v8;
    }
    v13 = this->mConstraints.size;
    if ( v13 > 1 )
      this->mConstraints.size = v13 - 1;
    else
      this->mConstraints.size = 0;
  }
}

// File Line: 1145
// RVA: 0xA9900
UFG::Constraint *__fastcall UFG::RigidBody::GetConstraintByIndex(UFG::RigidBody *this, unsigned int index)
{
  if ( index >= this->mConstraints.size )
    return 0i64;
  else
    return this->mConstraints.p[index].m_pPointer;
}

// File Line: 1157
// RVA: 0xA9920
UFG::Constraint *__fastcall UFG::RigidBody::GetConstraintByName(UFG::RigidBody *this, int *name)
{
  unsigned int size; // r9d
  __int64 v3; // r8
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // r10
  int v5; // edx
  UFG::Constraint **i; // rcx

  size = this->mConstraints.size;
  v3 = 0i64;
  if ( !size )
    return 0i64;
  p = this->mConstraints.p;
  v5 = *name;
  for ( i = &p->m_pPointer; (*i)->mName.mUID != v5; i += 3 )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= size )
      return 0i64;
  }
  return p[v3].m_pPointer;
}

// File Line: 1173
// RVA: 0xA77E0
void __fastcall UFG::RigidBody::EnableAllConstraints(UFG::RigidBody *this)
{
  __int64 i; // rbx
  UFG::Constraint *m_pPointer; // rdi
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  for ( i = 0i64; (unsigned int)i < this->mConstraints.size; i = (unsigned int)(i + 1) )
  {
    m_pPointer = this->mConstraints.p[i].m_pPointer;
    if ( m_pPointer )
    {
      if ( !hkpConstraintInstance::isEnabled(m_pPointer->mConstraintInstance, &result)->m_bool )
        hkpConstraintInstance::enable(m_pPointer->mConstraintInstance);
    }
  }
}

// File Line: 1190
// RVA: 0xA7220
void __fastcall UFG::RigidBody::DisableAllConstraints(UFG::RigidBody *this)
{
  __int64 i; // rbx
  UFG::Constraint *m_pPointer; // rdi
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  for ( i = 0i64; (unsigned int)i < this->mConstraints.size; i = (unsigned int)(i + 1) )
  {
    m_pPointer = this->mConstraints.p[i].m_pPointer;
    if ( m_pPointer )
    {
      if ( hkpConstraintInstance::isEnabled(m_pPointer->mConstraintInstance, &result)->m_bool )
        hkpConstraintInstance::disable(m_pPointer->mConstraintInstance);
    }
  }
}

// File Line: 1207
// RVA: 0xA6B70
void __fastcall UFG::RigidBody::DeleteAllConstraints(UFG::RigidBody *this)
{
  __int64 i; // rbx
  UFG::Constraint *m_pPointer; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *p; // rcx
  UFG::Constraint **p_m_pPointer; // rbx

  for ( i = 0i64; (unsigned int)i < this->mConstraints.size; i = (unsigned int)(i + 1) )
  {
    m_pPointer = this->mConstraints.p[i].m_pPointer;
    if ( m_pPointer )
      m_pPointer->vfptr->__vecDelDtor(m_pPointer, 1u);
  }
  p = this->mConstraints.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](p_m_pPointer);
  }
  this->mConstraints.p = 0i64;
  *(_QWORD *)&this->mConstraints.size = 0i64;
}

// File Line: 1219
// RVA: 0xB1500
void __fastcall UFG::RigidBody::SetMotionType(UFG::RigidBody *this, unsigned int mode)
{
  unsigned int mFlags; // ecx
  hkpRigidBody *mBody; // rcx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  hkpMotion::MotionType v8; // edx
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int v10; // ecx
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  mFlags = this->mFlags;
  if ( (mFlags & 960) != mode )
  {
    this->mFlags = mode | mFlags & 0xFFFFFC3F;
    mBody = this->mBody;
    if ( mBody )
    {
      v5 = mode - 0x40;
      if ( !v5 )
      {
        v8 = MOTION_FIXED;
        goto LABEL_18;
      }
      v6 = v5 - 0x40;
      if ( v6 )
      {
        v7 = v6 - 128;
        if ( !v7 )
        {
          v8 = MOTION_KEYFRAMED;
          goto LABEL_18;
        }
        if ( v7 != 256 )
        {
          v8 = MOTION_INVALID;
LABEL_18:
          hkpRigidBody::setMotionType(
            mBody,
            v8,
            HK_ENTITY_ACTIVATION_DO_ACTIVATE,
            HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
          return;
        }
      }
      if ( (unsigned int)(unsigned __int8)mBody->m_motion.m_type.m_storage - 4 > 1
        || hkpRigidBody::getStoredDynamicMotion(mBody) )
      {
        hkpRigidBody::setMotionType(
          this->mBody,
          MOTION_DYNAMIC,
          HK_ENTITY_ACTIVATION_DO_ACTIVATE,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
        UFG::qReflectHandleBase::qReflectHandleBase(&v11);
        v11.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        mCollisionMeshData = this->mCollisionMeshData;
        if ( mCollisionMeshData )
          UFG::qReflectHandleBase::operator=(&v11, &mCollisionMeshData->mObjectProperties);
        if ( v11.mData )
        {
          v10 = HIDWORD(v11.mData[2].mBaseNode.mChildren[0]);
          if ( v10 != -1 )
            this->mBody->m_collidable.m_broadPhaseHandle.m_objectQualityType = v10;
        }
        hkpEntity::activate(this->mBody);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
      }
    }
  }
}

// File Line: 1291
// RVA: 0xAA9C0
__int64 __fastcall UFG::RigidBody::GetMotionType(UFG::RigidBody *this)
{
  return this->mFlags & 0x3C0;
}

// File Line: 1299
// RVA: 0xB0670
void __fastcall UFG::RigidBody::SetCollisionLayer(
        UFG::RigidBody *this,
        unsigned int layerNum,
        int systemNum,
        int subSystemNum,
        int subSystemNumDisable)
{
  hkpRigidBody *mBody; // rax
  int v6; // r10d
  int v7; // r11d
  int v8; // r8d
  int v9; // r11d
  int v10; // r11d
  unsigned int v11; // r11d
  hkpRigidBody *v12; // rdx
  hkpWorld *m_world; // rcx

  mBody = this->mBody;
  v6 = 0;
  v7 = 0;
  if ( systemNum != -1 )
    v7 = systemNum;
  v8 = 0;
  v9 = v7 << 6;
  if ( subSystemNumDisable != -1 )
    v8 = subSystemNumDisable;
  v10 = 32 * (v8 | v9);
  if ( subSystemNum != -1 )
    v6 = subSystemNum;
  v11 = layerNum | (32 * (v6 | v10));
  this->mCollisionLayerOverride = v11;
  if ( mBody && mBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v11 )
  {
    mBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v11;
    v12 = this->mBody;
    m_world = v12->m_world;
    if ( m_world )
      hkpWorld::updateCollisionFilterOnEntity(
        m_world,
        v12,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
}

// File Line: 1342
// RVA: 0xA9810
__int64 __fastcall UFG::RigidBody::GetCollisionLayer(UFG::RigidBody *this)
{
  hkpRigidBody *mBody; // rax
  unsigned int m_collisionFilterInfo; // eax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  unsigned int v6; // ebx
  UFG::qReflectHandleBase v7; // [rsp+28h] [rbp-30h] BYREF

  mBody = this->mBody;
  if ( mBody )
  {
    m_collisionFilterInfo = mBody->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
    return m_collisionFilterInfo & 0x1F;
  }
  m_collisionFilterInfo = this->mCollisionLayerOverride;
  if ( m_collisionFilterInfo != -1 )
    return m_collisionFilterInfo & 0x1F;
  UFG::qReflectHandleBase::qReflectHandleBase(&v7);
  v7.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  mCollisionMeshData = this->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&v7, &mCollisionMeshData->mObjectProperties);
  if ( v7.mData )
    v6 = (unsigned int)v7.mData[2].mBaseNode.mChildren[0];
  else
    v6 = 0;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v7);
  return v6;
}

// File Line: 1372
// RVA: 0xA93B0
bool __fastcall UFG::RigidBody::GetAabb(
        UFG::RigidBody *this,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax,
        UFG::RigidBody::AabbTypes aabbType)
{
  __int64 v8; // r8
  __int128 m_translation; // xmm1
  hkpRigidBody *mBody; // rax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v17[8]; // [rsp+20h] [rbp-148h] BYREF
  __m128 m_quad; // [rsp+40h] [rbp-128h] BYREF
  __m128 v19; // [rsp+50h] [rbp-118h]
  __m128 v20; // [rsp+60h] [rbp-108h]
  __int128 v21; // [rsp+70h] [rbp-F8h]
  hkpRigidBodyCinfo info; // [rsp+80h] [rbp-E8h] BYREF

  if ( !this->mBody )
    return this->mBody != 0i64;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  hkpRigidBody::getCinfo(this->mBody, &info);
  if ( aabbType == LOCAL_AABB )
  {
    m_quad = transform.m_quad;
    v19 = direction.m_quad;
    m_translation = 0i64;
    v20 = stru_141A71280.m_quad;
LABEL_6:
    v21 = m_translation;
    ((void (__fastcall *)(hkpShape *, __m128 *, __int64, int *))info.m_shape->vfptr[2].__vecDelDtor)(
      info.m_shape,
      &m_quad,
      v8,
      v17);
    v11 = *(float *)&v17[1];
    LODWORD(aabbMin->x) = v17[0];
    v12 = *(float *)&v17[2];
    aabbMin->y = v11;
    v13 = *(float *)&v17[4];
    aabbMin->z = v12;
    v14 = *(float *)&v17[5];
    aabbMax->x = v13;
    v15 = *(float *)&v17[6];
    aabbMax->y = v14;
    aabbMax->z = v15;
    return this->mBody != 0i64;
  }
  if ( aabbType == WORLD_AABB )
  {
    mBody = this->mBody;
    m_quad = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
    v19 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
    v20 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
    m_translation = (__int128)mBody->m_motion.m_motionState.m_transform.m_translation;
    goto LABEL_6;
  }
  return 0;
}

// File Line: 1414
// RVA: 0xAAE30
float __fastcall UFG::GetOneOverApparentMass(hkpRigidBody *body, hkVector4f *pos, hkVector4f *dir)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm5
  __m128 v14[3]; // [rsp+20h] [rbp-38h] BYREF

  body->m_motion.hkpEntity::vfptr[6].__vecDelDtor(&body->m_motion, (unsigned int)v14);
  v6 = _mm_sub_ps(pos->m_quad, body->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(dir->m_quad, dir->m_quad, 201), v6), _mm_mul_ps(v7, dir->m_quad));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v14[1]), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v14[0])),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v14[2]));
  v11 = _mm_sub_ps(_mm_mul_ps(v7, v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v6));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), dir->m_quad);
  return body->m_motion.m_inertiaAndMassInv.m_quad.m128_f32[3]
       + (float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
               + _mm_shuffle_ps(v12, v12, 170).m128_f32[0]);
}

// File Line: 1437
// RVA: 0xA7F30
float __fastcall UFG::EstimateImpulseMagnitude(
        hkpRigidBody *rb0,
        hkpRigidBody *rb1,
        hkVector4f *pos,
        hkVector4f *normal,
        float normalSpeed,
        float coeffRestitution)
{
  float OneOverApparentMass; // xmm6_4
  float result; // xmm0_4

  OneOverApparentMass = UFG::GetOneOverApparentMass(rb0, pos, normal);
  LODWORD(result) = (COERCE_UNSIGNED_INT(
                       (float)((float)(coeffRestitution + 1.0) * normalSpeed)
                     / (float)(UFG::GetOneOverApparentMass(rb1, pos, normal) + OneOverApparentMass)) ^ _xmm[0]) & _xmm;
  return result;
}

