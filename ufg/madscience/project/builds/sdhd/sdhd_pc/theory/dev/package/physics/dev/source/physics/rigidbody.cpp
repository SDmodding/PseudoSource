// File Line: 43
// RVA: 0xAB730
const char *__fastcall UFG::RigidBody::GetTypeName(UFG::RigidBody *this)
{
  return "RigidBody";
}

// File Line: 88
// RVA: 0xB6F80
void __fastcall UFG::SurfaceVelocityUtil::contactPointAddedCallback(UFG::SurfaceVelocityUtil *this, hkpContactPointAddedEvent *event)
{
  hkpContactPointAddedEvent *v2; // rdi
  UFG::SurfaceVelocityUtil *v3; // r14
  hkpCdBody *v4; // rax
  hkpCdBody *i; // r8
  hkpCdBody *v6; // rbp
  hkpCdBody *v7; // rcx
  hkpCdBody *j; // rax
  hkpEntity *v9; // r9
  hkpEntity *v10; // r10
  signed int v11; // er11
  hkpShape *v12; // rdx
  hkpShape *v13; // rbx
  unsigned __int64 v14; // rdx
  __int64 v15; // r8
  signed __int64 v16; // rcx
  __int64 v17; // rax
  unsigned __int64 v18; // rdx
  __int64 v19; // rax
  signed __int64 v20; // rcx
  __int64 v21; // rax
  hkpDynamicsContactMgr *v22; // rbx

  v2 = event;
  v3 = this;
  v4 = event->m_bodyA->m_parent;
  for ( i = event->m_bodyA; v4; v4 = v4->m_parent )
    i = v4;
  v6 = event->m_bodyB;
  v7 = v6;
  for ( j = v6->m_parent; j; j = j->m_parent )
    v7 = j;
  v9 = 0i64;
  if ( LOBYTE(i[1].m_shapeKey) == 1 )
    v10 = (hkpEntity *)((char *)i + SLOBYTE(i[1].m_shape));
  else
    v10 = 0i64;
  if ( LOBYTE(v7[1].m_shapeKey) == 1 )
    v9 = (hkpEntity *)((char *)v7 + SLOBYTE(v7[1].m_shape));
  v11 = event->m_bodyA->m_shapeKey;
  v12 = i->m_shape;
  v13 = v7->m_shape;
  if ( v11 != -1 && v12->m_type.m_storage == 9 )
  {
    v14 = v12[2].m_userData;
    if ( v14 )
    {
      if ( !((*(_BYTE *)(v14 + 41) - 1) & 0xFD) )
      {
        v15 = (v11 & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(v14 + 232));
        v16 = v11 < 0 ? *(_QWORD *)(v14 + 256) + 80i64 * (signed int)v15 : *(_QWORD *)(v14 + 240)
                                                                         + 144i64 * (signed int)v15;
        v17 = *(_QWORD *)(v16 + 16);
        if ( v17 )
        {
          if ( *(_BYTE *)(v17 + 28) & 1 )
            goto LABEL_34;
        }
      }
    }
  }
  v15 = v6->m_shapeKey;
  if ( (_DWORD)v15 != -1 && v13->m_type.m_storage == 9 )
  {
    v18 = v13[2].m_userData;
    if ( v18 )
    {
      if ( !((*(_BYTE *)(v18 + 41) - 1) & 0xFD) )
      {
        v19 = (signed int)(((unsigned int)v15 & 0x7FFFFFFF) >> (32 - *(_BYTE *)(v18 + 232)));
        v20 = (signed int)v15 < 0 ? *(_QWORD *)(v18 + 256) + 80 * v19 : *(_QWORD *)(v18 + 240) + 144 * v19;
        v21 = *(_QWORD *)(v20 + 16);
        if ( v21 )
        {
          if ( *(_BYTE *)(v21 + 28) & 1 )
          {
LABEL_34:
            v22 = v2->m_internalContactMgr;
            if ( v22 || (v22 = hkpEntity::findContactMgrTo(v10, v9)) != 0i64 )
            {
              if ( ((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkBaseObjectVtbl *, __int64, hkpEntity *))v22->vfptr[8].__vecDelDtor)(
                     v22,
                     v22->vfptr,
                     v15,
                     v9) )
              {
                hkpResponseModifier::setSurfaceVelocity(
                  v22,
                  (hkpRigidBody *)v3->vfptr,
                  v2->m_collisionOutput->m_constraintOwner.m_storage,
                  (hkVector4f *)&v3->m_rigidBody);
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
void __fastcall UFG::RigidBody::RigidBody(UFG::RigidBody *this, UFG::CollisionMeshData *mesh, UFG::CollisionInstanceData *instance, unsigned int flags)
{
  unsigned int v4; // esi
  UFG::CollisionInstanceData *v5; // rbx
  UFG::CollisionMeshData *v6; // rdi
  UFG::RigidBody *v7; // r14
  UFG::BasePhysicsObject *v8; // r15
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v9; // ST38_8
  UFG::CollisionMeshData *v10; // rdx
  int v11; // ecx
  unsigned int v12; // er8
  unsigned int v13; // ecx
  char *v14; // rax
  UFG::qReflectHandleBase v15; // [rsp+40h] [rbp-68h]

  v4 = flags;
  v5 = instance;
  v6 = mesh;
  v7 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, instance->mInstanceGuid);
  v8 = (UFG::BasePhysicsObject *)&v7->vfptr;
  v8->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  v7->mUserData.isBoat = 0;
  v9 = &v7->mUserData.simComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v7->mUserData.simComponent.m_pPointer = 0i64;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBody::`vftable{for `UFG::SimComponent};
  v8->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBody::`vftable{for `UFG::BasePhysicsObject};
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7->mCollisionMeshBundle.mPrev);
  v7->mCollisionMeshBundle.mOwner = 0i64;
  v7->mCollisionMeshBundle.mUnloading = 0;
  v7->mInstanceData = v5;
  v7->mCollisionMeshData = v6;
  v7->mBody = 0i64;
  v7->mWaterFloatingTrackerComponent = 0i64;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v7->mRootTransformComponent);
  v7->mWindAction = 0i64;
  v7->mFractureState = 0i64;
  v7->mConstraints.p = 0i64;
  *(_QWORD *)&v7->mConstraints.size = 0i64;
  v7->mFlags = v4;
  *(_QWORD *)&v7->mCollisionLayerOverride = -1i64;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v7->vfptr, UFG::RigidBody::_RigidBodyTypeUID, "RigidBody");
  v7->mFlags |= 0x10u;
  UFG::qReflectHandleBase::qReflectHandleBase(&v15);
  v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v10 = v7->mCollisionMeshData;
  if ( v10 )
    UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)&v10->mObjectProperties.mPrev);
  v11 = (int)v15.mData[2].mBaseNode.mChildren[1];
  if ( v11 == 4 )
  {
    v7->mFlags |= 0x100u;
  }
  else if ( v11 == 1 )
  {
    v7->mFlags |= 0x40u;
  }
  else
  {
    v7->mFlags |= 0x80u;
  }
  v12 = v7->mCollisionMeshData->mBundleGuid;
  v7->mCollisionMeshBundle.mOwner = v8;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7->mCollisionMeshBundle.mPrev, 0x1723EA91u, v12);
  v13 = v7->mCollisionMeshData->mGeometryType;
  if ( v13 == 3 || v13 == 4 )
  {
    v14 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "BitArray256", 0i64, 1u);
    if ( v14 )
    {
      *(_QWORD *)v14 = 0i64;
      *((_QWORD *)v14 + 1) = 0i64;
      *((_QWORD *)v14 + 2) = 0i64;
      *((_QWORD *)v14 + 3) = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    v7->mFractureState = (BitArray256 *)v14;
  }
  ++UFG::RigidBody::mCount;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
}

// File Line: 183
// RVA: 0x9CED0
void __fastcall UFG::RigidBody::~RigidBody(UFG::RigidBody *this)
{
  UFG::RigidBody *v1; // rdi
  UFG::BasePhysicsObject *v2; // r14
  UFG::CollisionMeshData *v3; // rcx
  hkpEntity *v4; // rdx
  BitArray256 *v5; // rdx
  UFG::CollisionInstanceData *v6; // rdx
  hkpAction *v7; // rdx
  int v8; // er8
  UFG::BasePhysicsSystem *v9; // r10
  __int64 v10; // r9
  __int64 v11; // rax
  hkpWorld *v12; // rcx
  hkpRigidBody *v13; // rax
  UFG::WaterFloatingTrackerBaseComponent *v14; // rax
  UFG::SimObject *v15; // rdx
  UFG::WaterFloatingTrackerBaseComponent *v16; // rdx
  UFG::WaterFloatingTrackerBaseComponent *v17; // rcx
  unsigned int i; // ebx
  signed __int64 v19; // rsi
  UFG::Constraint *v20; // rdx
  UFG::Constraint *v21; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v22; // rcx
  UFG::Constraint **v23; // rbx
  UFG::CollisionMeshData *v24; // rbx
  hkReferencedObject *v25; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v26; // rcx
  UFG::Constraint **v27; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::SimObjectModifier v33; // [rsp+28h] [rbp-50h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RigidBody::`vftable{for `UFG::SimComponent};
  v2 = (UFG::BasePhysicsObject *)&this->vfptr;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::RigidBody::`vftable{for `UFG::BasePhysicsObject};
  v3 = this->mCollisionMeshData;
  if ( v3 )
  {
    v4 = (hkpEntity *)&v1->mBody->vfptr;
    if ( v4 )
    {
      UFG::CollisionMeshData::UnmarkBreakableParts(v3, v4);
      UFG::CollisionMeshData::ResetFracture(v1->mCollisionMeshData);
    }
  }
  v5 = v1->mFractureState;
  if ( v5 )
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v5);
  v1->mInstanceData->mPhysicsComponent = 0i64;
  v1->mCollisionMeshBundle.mOwner = 0i64;
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mCollisionMeshBundle.mPrev);
  if ( !(v1->mFlags & 4) )
  {
    v6 = v1->mInstanceData;
    if ( v6 )
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v6);
  }
  v7 = (hkpAction *)&v1->mWindAction->vfptr;
  if ( v7 )
  {
    v8 = 0;
    v9 = UFG::BasePhysicsSystem::mInstance;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v10 = 0i64;
      do
      {
        if ( v9->mActionsToAdd.m_data[v10] == v7 )
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
    v12 = v7->m_world;
    if ( v12 )
      hkpWorld::removeAction(v12, v7);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mWindAction->vfptr);
    v1->mWindAction = 0i64;
  }
  v13 = v1->mBody;
  if ( v13 )
  {
    v13->m_userData = 0i64;
    UFG::RigidBody::RemoveFromWorld(v1);
    v14 = v1->mWaterFloatingTrackerComponent;
    if ( v14 )
    {
      v15 = v1->m_pSimObject;
      if ( v15 )
      {
        if ( v14->m_pSimObject )
        {
          UFG::SimObjectModifier::SimObjectModifier(&v33, v15, 1);
          v16 = v1->mWaterFloatingTrackerComponent;
          ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v33);
          UFG::SimObjectModifier::Close(&v33);
          UFG::SimObjectModifier::~SimObjectModifier(&v33);
          v17 = v1->mWaterFloatingTrackerComponent;
          if ( v17 )
            v17->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v17->vfptr, 1u);
          v1->mWaterFloatingTrackerComponent = 0i64;
        }
      }
    }
    for ( i = 0; i < v1->mConstraints.size; ++i )
    {
      v19 = i;
      v20 = v1->mConstraints.p[v19].m_pPointer;
      if ( v20 )
      {
        if ( v20->mConstraintInstance )
          UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v20->mConstraintInstance);
        v21 = v1->mConstraints.p[v19].m_pPointer;
        if ( v21 )
          v21->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v21->vfptr, 1u);
      }
    }
    v22 = v1->mConstraints.p;
    if ( v22 )
    {
      v23 = &v22[-1].m_pPointer;
      `eh vector destructor iterator(
        v22,
        0x18ui64,
        (int)v22[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
      operator delete[](v23);
    }
    v1->mConstraints.p = 0i64;
    *(_QWORD *)&v1->mConstraints.size = 0i64;
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mBody->vfptr);
  }
  v24 = v1->mCollisionMeshData;
  if ( v24 && (v24->mFlags >> 1) & 1 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::BasePhysicsSystem::mInstance->mCollisionModels,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v24);
    v25 = (hkReferencedObject *)&v24->mShape->vfptr;
    if ( v25 )
      hkReferencedObject::removeReference(v25);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v24->mObjectProperties.mPrev);
    operator delete[](v24);
  }
  --UFG::RigidBody::mCount;
  v26 = v1->mConstraints.p;
  if ( v26 )
  {
    v27 = &v26[-1].m_pPointer;
    `eh vector destructor iterator(
      v26,
      0x18ui64,
      (int)v26[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v27);
  }
  v1->mConstraints.p = 0i64;
  *(_QWORD *)&v1->mConstraints.size = 0i64;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mRootTransformComponent);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mCollisionMeshBundle.mPrev);
  v2->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  v28 = &v2->mUserData.simComponent;
  if ( v2->mUserData.simComponent.m_pPointer )
  {
    v29 = v28->mPrev;
    v30 = v2->mUserData.simComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
    v2->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mUserData.simComponent.mPrev;
  }
  v2->mUserData.simComponent.m_pPointer = 0i64;
  v31 = v28->mPrev;
  v32 = v2->mUserData.simComponent.mNext;
  v31->mNext = v32;
  v32->mPrev = v31;
  v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
  v2->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mUserData.simComponent.mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 262
// RVA: 0xA2830
void __fastcall UFG::RigidBody::CommonConstruct(UFG::RigidBody *this, hkpRigidBodyCinfo *info, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionMeshData *v3; // r14
  hkpRigidBodyCinfo *v4; // rbx
  UFG::RigidBody *v5; // rdi
  UFG::CollisionMeshData *v6; // rdx
  UFG::qReflectObject *v7; // r8
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // er9
  UFG::qTree64Base::BaseNode *v14; // r10
  UFG::qWiseSymbol *v15; // rax
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm1_4
  hkpMotion::MotionType v19; // er15
  signed __int64 v20; // rsi
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  _QWORD **v24; // rax
  hkpRigidBody *v25; // rax
  hkpRigidBody *v26; // rax
  char v27; // al
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  hkpRigidBody *v32; // rcx
  unsigned int v33; // er14
  UFG::qReflectObject *i; // rax
  UFG::PhysicsObjectProperties::ConstraintProperty *v35; // rbx
  char *v36; // rax
  __int64 v37; // rax
  hkVector4f **v38; // rcx
  unsigned __int64 v39; // rax
  __int64 v40; // r15
  unsigned int v41; // ebx
  unsigned int v42; // edx
  unsigned int v43; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v44; // rdx
  UFG::Constraint *v45; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v48; // rax
  __m128 v49; // kr00_16
  unsigned __int64 *v50; // rax
  unsigned __int64 v51; // rcx
  hkTransformf *v52; // rdx
  _QWORD **v53; // rax
  hkpSurfaceVelocityUtil *v54; // rax
  hkpSurfaceVelocityUtil *v55; // rbx
  hkpRigidBody *v56; // rcx
  hkVector4f surfaceVelocityWorld; // [rsp+8h] [rbp-79h]
  unsigned int check_null[4]; // [rsp+18h] [rbp-69h]
  hkVector4f b; // [rsp+28h] [rbp-59h]
  UFG::qReflectHandleBase v60; // [rsp+38h] [rbp-49h]
  __int64 v61; // [rsp+60h] [rbp-21h]
  __m128 v62; // [rsp+68h] [rbp-19h]
  __m128 v63; // [rsp+78h] [rbp-9h]
  __m128 v64; // [rsp+88h] [rbp+7h]
  __int128 v65; // [rsp+98h] [rbp+17h]
  void *v66; // [rsp+E8h] [rbp+67h]
  float v67; // [rsp+F0h] [rbp+6Fh]

  v61 = -2i64;
  v3 = mesh;
  v4 = info;
  v5 = this;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v61);
  v60.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v6 = v5->mCollisionMeshData;
  if ( v6 )
    UFG::qReflectHandleBase::operator=(&v60, (UFG::qReflectHandleBase *)&v6->mObjectProperties.mPrev);
  v7 = v60.mData;
  switch ( LODWORD(v60.mData[2].mBaseNode.mChildren[1]) )
  {
    case 1:
      v4->m_motionType.m_storage = 5;
      break;
    case 2:
      v4->m_motionType.m_storage = 1;
      break;
    case 4:
      v4->m_motionType.m_storage = 4;
      break;
    case 8:
      v4->m_motionType.m_storage = 3;
      break;
  }
  v8 = HIDWORD(v7[2].mBaseNode.mChildren[0]);
  if ( v8 != -1 )
    v4->m_qualityType.m_storage = v8;
  v4->m_shape = v3->mShape;
  v9 = v5->mCollisionSystem;
  if ( v9 <= 0 )
  {
    v11 = v5->mCollisionLayerOverride;
    if ( v11 == -1 )
      v11 = (int)v7[2].mBaseNode.mChildren[0];
  }
  else
  {
    v10 = v5->mCollisionLayerOverride;
    if ( v10 == -1 )
      v10 = (unsigned int)v7[2].mBaseNode.mChildren[0];
    v11 = v10 | (v9 << 16) | 0x420;
  }
  v4->m_collisionFilterInfo = v11;
  v4->m_mass = v3->mMass;
  v4->m_linearDamping = *(float *)&v7[1].mBaseNode.mUID;
  v4->m_angularDamping = *((float *)&v7[1].mBaseNode.mUID + 1);
  v4->m_friction = *(float *)(v7[4].mBaseNode.mUID + 80);
  v4->m_restitution = *(float *)(v7[4].mBaseNode.mUID + 84);
  v4->m_numShapeKeysInContactPointProperties = v3->mShapeKeyDepth;
  v4->m_gravityFactor = *((float *)&v7[1].vfptr + 1);
  if ( !(_S8 & 1) )
  {
    _S8 |= 1u;
    AudioPropertyRolling.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertyRolling", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertyRolling.mUID);
    atexit(UFG::RigidBody::CommonConstruct_::_12_::_dynamic_atexit_destructor_for__AudioPropertyRolling__);
    v7 = v60.mData;
  }
  v12 = 0;
  v13 = (unsigned int)v7[3].mBaseNode.mChildren[1];
  if ( v13 )
  {
    v14 = v7[3].mBaseNode.mChildren[0];
    while ( *((_DWORD *)&v14->mUID + 2 * v12) != AudioPropertyRolling.mUID )
    {
      if ( ++v12 >= v13 )
        goto LABEL_27;
    }
    v15 = (UFG::qWiseSymbol *)((char *)&v14->mUID + 8 * v12 + 4);
  }
  else
  {
LABEL_27:
    v15 = UFG::qWiseSymbol::get_null();
  }
  if ( v15->mUID )
    v4->m_contactPointCallbackDelay = 4;
  if ( v4->m_motionType.m_storage != 5 )
  {
    v62 = transform.m_quad;
    v63 = direction.m_quad;
    v64 = stru_141A71280.m_quad;
    v65 = 0i64;
    ((void (__fastcall *)(hkpShape *, __m128 *, UFG::qReflectObject *, hkVector4f *))v3->mShape->vfptr[2].__vecDelDtor)(
      v3->mShape,
      &v62,
      v7,
      &surfaceVelocityWorld);
    v16 = _mm_add_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)check_null), 1u), 1u),
            (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&surfaceVelocityWorld), 1u), 1u));
    v67 = fminf(v16.m128_f32[0], COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)));
    LODWORD(v66) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 170);
    v17 = fminf(v67, *(float *)&v66);
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
    v4->m_allowedPenetrationDepth = v18;
  }
  v19 = v4->m_motionType.m_storage;
  if ( v4->m_motionType.m_storage == 4 )
    v4->m_motionType.m_storage = 1;
  v20 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v21 = ++*(_BYTE *)(v20 + 80);
  v22 = v21;
  *(_DWORD *)(v20 + 4 * v22) = 0;
  *(_QWORD *)(v20 + 8 * v22 + 16) = "hkpRigidBody";
  *(_QWORD *)(v20 + 8 * v22 + 48) = 0i64;
  v23 = *(_BYTE *)(v20 + 81);
  if ( v21 > v23 )
    v23 = v21;
  *(_BYTE *)(v20 + 81) = v23;
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 720i64);
  v66 = v25;
  if ( v25 )
    hkpRigidBody::hkpRigidBody(v25, v4);
  else
    v26 = 0i64;
  v5->mBody = v26;
  v27 = *(_BYTE *)(v20 + 80);
  if ( v27 > 0 )
  {
    *(_BYTE *)(v20 + 80) = v27 - 1;
  }
  else
  {
    *(_BYTE *)(v20 + 80) = 0;
    *(_DWORD *)v20 = 3;
    *(_QWORD *)(v20 + 16) = 0i64;
    *(_QWORD *)(v20 + 48) = 0i64;
  }
  if ( v19 != v4->m_motionType.m_storage )
    hkpRigidBody::setMotionType(v5->mBody, v19, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
  UFG::RigidBody::SetMotionType(v5, v5->mFlags & 0x3C0);
  UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
    v3->mPropertiesHandleGuid,
    (hkpWorldObject *)&v5->mBody->vfptr);
  UFG::CollisionMeshData::MarkBreakableParts(v3, v5, 1.0);
  v28 = &v5->mUserData.simComponent;
  if ( v5->mUserData.simComponent.m_pPointer )
  {
    v29 = v28->mPrev;
    v30 = v5->mUserData.simComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
    v5->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mUserData.simComponent.mPrev;
  }
  v5->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  v31 = v5->m_SafePointerList.mNode.mPrev;
  v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
  v28->mPrev = v31;
  v5->mUserData.simComponent.mNext = &v5->m_SafePointerList.mNode;
  v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
  v32 = v5->mBody;
  if ( v32 )
    v32->m_userData = (unsigned __int64)&v5->mUserData;
  v33 = 0;
  for ( i = v60.mData; v33 < LODWORD(v60.mData[3].mBaseNode.mNeighbours[1]); i = v60.mData )
  {
    v35 = (UFG::PhysicsObjectProperties::ConstraintProperty *)((char *)i[3].mBaseNode.mNeighbours[0] + 76 * v33);
    v36 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
    v66 = v36;
    if ( v36 )
      UFG::Constraint::Constraint((UFG::Constraint *)v36, v35, v5->mBody);
    else
      v37 = 0i64;
    surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
    surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    *(_QWORD *)check_null = v37;
    if ( v37 )
    {
      v38 = (hkVector4f **)(v37 + 8);
      v39 = *(_QWORD *)(v37 + 8);
      *(_QWORD *)(v39 + 8) = &surfaceVelocityWorld;
      surfaceVelocityWorld.m_quad.m128_u64[0] = v39;
      surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)v38;
      *v38 = &surfaceVelocityWorld;
    }
    v40 = v5->mConstraints.size;
    v41 = v40 + 1;
    v42 = v5->mConstraints.capacity;
    if ( (signed int)v40 + 1 > v42 )
    {
      if ( v42 )
        v43 = 2 * v42;
      else
        v43 = 1;
      for ( ; v43 < v41; v43 *= 2 )
        ;
      if ( v43 - v41 > 0x10000 )
        v43 = v40 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        &v5->mConstraints,
        v43,
        "qArray.Add");
    }
    v5->mConstraints.size = v41;
    v44 = &v5->mConstraints.p[v40];
    v45 = *(UFG::Constraint **)check_null;
    if ( v44->m_pPointer )
    {
      v46 = v44->mPrev;
      v47 = v44->mNext;
      v46->mNext = v47;
      v47->mPrev = v46;
      v44->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v44->mPrev;
      v44->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v44->mPrev;
    }
    v44->m_pPointer = v45;
    if ( v45 )
    {
      v48 = v45->m_SafePointerList.mNode.mPrev;
      v48->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v44->mPrev;
      v44->mPrev = v48;
      v44->mNext = &v45->m_SafePointerList.mNode;
      v45->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v44->mPrev;
    }
    if ( *(_QWORD *)check_null )
    {
      v49 = surfaceVelocityWorld.m_quad;
      *(_QWORD *)(surfaceVelocityWorld.m_quad.m128_u64[0] + 8) = surfaceVelocityWorld.m_quad.m128_u64[1];
      *(_QWORD *)v49.m128_u64[1] = v49.m128_u64[0];
      surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
      surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    }
    *(_QWORD *)check_null = 0i64;
    v50 = (unsigned __int64 *)surfaceVelocityWorld.m_quad.m128_u64[1];
    v51 = surfaceVelocityWorld.m_quad.m128_u64[0];
    *(_QWORD *)(surfaceVelocityWorld.m_quad.m128_u64[0] + 8) = surfaceVelocityWorld.m_quad.m128_u64[1];
    *v50 = v51;
    surfaceVelocityWorld.m_quad.m128_u64[0] = (unsigned __int64)&surfaceVelocityWorld;
    surfaceVelocityWorld.m_quad.m128_u64[1] = (unsigned __int64)&surfaceVelocityWorld;
    ++v33;
  }
  if ( (float)((float)((float)(*((float *)&i[2].mTypeUID + 1) * *((float *)&i[2].mTypeUID + 1))
                     + (float)(*(float *)&i[2].mHandles.mNode.mPrev * *(float *)&i[2].mHandles.mNode.mPrev))
             + (float)(*((float *)&i[2].mHandles.mNode.mPrev + 1) * *((float *)&i[2].mHandles.mNode.mPrev + 1))) > 0.0 )
  {
    v52 = &v5->mBody->m_motion.m_motionState.m_transform;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)HIDWORD(i[2].mTypeUID), (__m128)HIDWORD(i[2].mHandles.mNode.mPrev)),
                 _mm_unpacklo_ps((__m128)LODWORD(i[2].mHandles.mNode.mPrev), (__m128)0i64));
    hkVector4f::setTransformedPos(&surfaceVelocityWorld, v52, &b);
    v53 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v54 = (hkpSurfaceVelocityUtil *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v53[11] + 8i64))(
                                      v53[11],
                                      64i64);
    v55 = v54;
    v66 = v54;
    if ( v54 )
    {
      hkpSurfaceVelocityUtil::hkpSurfaceVelocityUtil(v54, v5->mBody, &surfaceVelocityWorld);
      v55->vfptr = (hkBaseObjectVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkReferencedObject};
      v55->vfptr = (hkpContactListenerVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkpContactListener};
      v55->vfptr = (hkpEntityListenerVtbl *)&UFG::SurfaceVelocityUtil::`vftable{for `hkpEntityListener};
    }
    else
    {
      v55 = 0i64;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v55->vfptr);
    i = v60.mData;
  }
  if ( (float)((float)((float)(*(float *)&i[2].mHandles.mNode.mNext * *(float *)&i[2].mHandles.mNode.mNext)
                     + (float)(*((float *)&i[2].mHandles.mNode.mNext + 1) * *((float *)&i[2].mHandles.mNode.mNext + 1)))
             + (float)(*(float *)&i[3].vfptr * *(float *)&i[3].vfptr)) > 0.0 )
  {
    v56 = v5->mBody;
    b.m_quad = (__m128)v56->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
    b.m_quad = _mm_add_ps(
                 b.m_quad,
                 _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)LODWORD(i[2].mHandles.mNode.mNext), (__m128)LODWORD(i[3].vfptr)),
                   _mm_unpacklo_ps((__m128)HIDWORD(i[2].mHandles.mNode.mNext), (__m128)0i64)));
    hkpRigidBody::setCenterOfMassLocal(v56, &b);
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v60);
}

// File Line: 408
// RVA: 0xADA40
void __fastcall UFG::RigidBody::OnAttach(UFG::RigidBody *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rdi
  UFG::RigidBody *v3; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  hkpRigidBody *v9; // rcx
  UFG::CollisionMeshData *v10; // rdx
  hkpRigidBody *v11; // rdx
  __int128 v12; // xmm8
  __int128 v13; // xmm9
  UFG::WaterFloatingTrackerBaseComponent *v14; // rax
  UFG::qReflectHandleBase v15; // [rsp+38h] [rbp-70h]

  v2 = object;
  v3 = this;
  v4 = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = this->mUserData.simComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    this->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  }
  this->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&this->vfptr;
  if ( this )
  {
    v7 = &this->m_SafePointerList;
    v8 = v7->mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v8;
    v4->mNext = &v7->mNode;
    v7->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v9 = v3->mBody;
  if ( v9 )
    v9->m_userData = (unsigned __int64)&v3->mUserData;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &v3->mRootTransformComponent,
    object);
  UFG::qReflectHandleBase::qReflectHandleBase(&v15);
  v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v10 = v3->mCollisionMeshData;
  if ( v10 )
    UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)&v10->mObjectProperties.mPrev);
  if ( !v3->mWaterFloatingTrackerComponent && *((float *)&v15.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
  {
    if ( v2 )
    {
      v11 = v3->mBody;
      if ( v11 )
      {
        v12 = HIDWORD(v15.mData[1].mBaseNode.mNeighbours[0]);
        v13 = LODWORD(v15.mData[1].mBaseNode.mNeighbours[1]);
        if ( UFG::RigidBody::mAcquireWaterFloatingTrackerFunc )
        {
          v14 = UFG::RigidBody::mAcquireWaterFloatingTrackerFunc(v3->m_pSimObject, v11);
          v3->mWaterFloatingTrackerComponent = v14;
          if ( v14 )
            ((void (__fastcall *)(UFG::WaterFloatingTrackerBaseComponent *))v14->vfptr[14].__vecDelDtor)(v14);
        }
      }
    }
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
}

// File Line: 439
// RVA: 0xAE030
void __fastcall UFG::RigidBody::OnDetach(UFG::RigidBody *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->mRootTransformComponent;
  if ( this->mRootTransformComponent.m_pSimComponent )
  {
    v2 = this->mRootTransformComponent.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mRootTransformComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->mRootTransformComponent.mNext != &this->mRootTransformComponent) )
    {
      v4 = this->mRootTransformComponent.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 447
// RVA: 0xABAC0
void __fastcall UFG::RigidBody::Inflate(UFG::RigidBody *this, bool addToWorld)
{
  bool v2; // di
  UFG::RigidBody *v3; // rbx
  hkQuaternionf *v4; // rax
  UFG::CollisionMeshData *v5; // rdx
  unsigned int *v6; // rax
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  hkVector4f v12; // xmm0
  float v13; // xmm0_4
  UFG::CollisionMeshData *v14; // r8
  UFG::BasePhysicsSystem *v15; // r14
  UFG::WindAction *v16; // r15
  hkpRigidBody *v17; // rsi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v18; // rdi
  unsigned int i; // esi
  hkReferencedObject *v20; // rbp
  UFG::WaterFloatingTrackerBaseComponent *v21; // rcx
  UFG::qReflectObject *v22; // rax
  UFG::SimObject *v23; // rcx
  hkpRigidBody *v24; // rdx
  __int128 v25; // xmm8
  __int128 v26; // xmm9
  UFG::WaterFloatingTrackerBaseComponent *v27; // rax
  _QWORD **v28; // rax
  UFG::WindAction *v29; // rax
  UFG::WindAction *v30; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  hkpRigidBody *v35; // rcx
  UFG::qReflectHandleBase v36; // [rsp+30h] [rbp-168h]
  __int64 v37; // [rsp+58h] [rbp-140h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+60h] [rbp-138h]

  v37 = -2i64;
  v2 = addToWorld;
  v3 = this;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
  v4 = &v3->mInstanceData->mOrientation;
  bodyInfo.m_position = (hkVector4f)v4[2].m_vec.m_quad;
  bodyInfo.m_rotation = (hkQuaternionf)v4->m_vec.m_quad;
  UFG::qReflectHandleBase::qReflectHandleBase(&v36);
  v36.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v5 = v3->mCollisionMeshData;
  if ( v5 )
    UFG::qReflectHandleBase::operator=(&v36, (UFG::qReflectHandleBase *)&v5->mObjectProperties.mPrev);
  v6 = (unsigned int *)v3->mCollisionMeshData;
  v7 = _mm_shuffle_ps(
         (__m128)HIDWORD(v36.mData[1].mBaseNode.mChildren[0]),
         (__m128)HIDWORD(v36.mData[1].mBaseNode.mChildren[0]),
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
  v12.m_quad = _mm_movelh_ps(v11, v10);
  bodyInfo.m_inertiaTensor.m_col0 = (hkVector4f)v12.m_quad;
  bodyInfo.m_inertiaTensor.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v12.m_quad, v11), v10, 212);
  bodyInfo.m_inertiaTensor.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v8, v9), v10, 228);
  v13 = *(float *)&v36.mData[1].mBaseNode.mChildren[1];
  if ( v13 != -1.0 )
    hkpInertiaTensorComputer::clipInertia(v13, &bodyInfo);
  v14 = v3->mCollisionMeshData;
  bodyInfo.m_centerOfMass.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps(
                                       (__m128)LODWORD(v14->mCentreOfMass.x),
                                       (__m128)LODWORD(v14->mCentreOfMass.z)),
                                     _mm_unpacklo_ps((__m128)LODWORD(v14->mCentreOfMass.y), (__m128)0i64));
  UFG::RigidBody::CommonConstruct(v3, &bodyInfo, v14);
  v3->mFlags |= 2u;
  v15 = UFG::BasePhysicsSystem::mInstance;
  v16 = 0i64;
  if ( v2 )
  {
    v17 = v3->mBody;
    v18 = &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd;
    if ( UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size == (UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd,
        8);
    v18->m_data[v15->mEntitiesToAdd.m_size++] = (hkpEntity *)&v17->vfptr;
    for ( i = 0; i < v3->mConstraints.size; ++i )
    {
      v20 = (hkReferencedObject *)&v3->mConstraints.p[i].m_pPointer->mConstraintInstance->vfptr;
      if ( v20 )
      {
        if ( v15->mConstraintsToAdd.m_size == (v15->mConstraintsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v15->mConstraintsToAdd,
            8);
        v15->mConstraintsToAdd.m_data[v15->mConstraintsToAdd.m_size++] = (hkpConstraintInstance *)v20;
        hkReferencedObject::addReference(v20);
      }
    }
  }
  v21 = v3->mWaterFloatingTrackerComponent;
  if ( v21 )
  {
    v21->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v21->vfptr, (unsigned int)v3->mBody);
LABEL_22:
    v22 = v36.mData;
    goto LABEL_23;
  }
  v22 = v36.mData;
  if ( *((float *)&v36.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
  {
    v23 = v3->m_pSimObject;
    if ( v23 )
    {
      v24 = v3->mBody;
      if ( v24 )
      {
        v25 = HIDWORD(v36.mData[1].mBaseNode.mNeighbours[0]);
        v26 = LODWORD(v36.mData[1].mBaseNode.mNeighbours[1]);
        if ( UFG::RigidBody::mAcquireWaterFloatingTrackerFunc )
        {
          v27 = UFG::RigidBody::mAcquireWaterFloatingTrackerFunc(v23, v24);
          v3->mWaterFloatingTrackerComponent = v27;
          if ( v27 )
            ((void (__fastcall *)(UFG::WaterFloatingTrackerBaseComponent *))v27->vfptr[14].__vecDelDtor)(v27);
          goto LABEL_22;
        }
      }
    }
  }
LABEL_23:
  if ( BYTE5(v22[1].mHandles.mNode.mNext) )
  {
    if ( !v3->mWindAction )
    {
      v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v29 = (UFG::WindAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(v28[11], 96i64);
      if ( v29 )
      {
        UFG::WindAction::WindAction(v29, v3->mBody, *(float *)v36.mData[1].mBaseNode.mNeighbours);
        v16 = v30;
      }
      v3->mWindAction = v16;
    }
    UFG::BasePhysicsSystem::AddAction(v15, (hkpAction *)&v3->mWindAction->vfptr);
    hkpRigidBody::enableDeactivation(v3->mBody, 0);
  }
  v31 = &v3->mUserData.simComponent;
  if ( v3->mUserData.simComponent.m_pPointer )
  {
    v32 = v31->mPrev;
    v33 = v3->mUserData.simComponent.mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
    v3->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mUserData.simComponent.mPrev;
  }
  v3->mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v3->vfptr;
  v34 = v3->m_SafePointerList.mNode.mPrev;
  v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
  v31->mPrev = v34;
  v3->mUserData.simComponent.mNext = &v3->m_SafePointerList.mNode;
  v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
  v35 = v3->mBody;
  if ( v35 )
    v35->m_userData = (unsigned __int64)&v3->mUserData;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v36);
}

// File Line: 541
// RVA: 0xA68C0
__int64 __fastcall UFG::RigidBody::Deflate(UFG::RigidBody *this)
{
  UFG::RigidBody *v1; // rdi
  UFG::CollisionMeshData *v2; // rcx
  UFG::WaterFloatingTrackerBaseComponent *v3; // rcx
  hkpAction *v4; // rdx
  UFG::BasePhysicsSystem *v5; // r10
  int v6; // er8
  __int64 v7; // r9
  __int64 v8; // rax
  hkpWorld *v9; // rcx
  UFG::BasePhysicsSystem *v10; // rbp
  unsigned int i; // ebx
  signed __int64 v12; // rsi
  UFG::Constraint *v13; // rdx
  UFG::Constraint *v14; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v15; // rcx
  UFG::Constraint **v16; // rbx
  hkpRigidBody *v17; // rcx
  bool v18; // zf
  bool v19; // sf
  unsigned __int8 v20; // of
  unsigned __int8 v21; // bl

  v1 = this;
  this->mInstanceData->mPosition = this->mBody->m_motion.m_motionState.m_transform.m_translation;
  this->mInstanceData->mOrientation = this->mBody->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  UFG::RigidBody::RemoveFromWorld(this);
  v2 = v1->mCollisionMeshData;
  if ( v2 )
  {
    UFG::CollisionMeshData::UnmarkBreakableParts(v2, (hkpEntity *)&v1->mBody->vfptr);
    UFG::CollisionMeshData::ResetFracture(v1->mCollisionMeshData);
  }
  v3 = v1->mWaterFloatingTrackerComponent;
  if ( v3 )
    ((void (*)(void))v3->vfptr[15].__vecDelDtor)();
  v4 = (hkpAction *)&v1->mWindAction->vfptr;
  if ( v4 )
  {
    v5 = UFG::BasePhysicsSystem::mInstance;
    v6 = 0;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        if ( v5->mActionsToAdd.m_data[v7] == v4 )
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
    v9 = v4->m_world;
    if ( v9 )
      hkpWorld::removeAction(v9, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mWindAction->vfptr);
    v1->mWindAction = 0i64;
  }
  v10 = UFG::BasePhysicsSystem::mInstance;
  for ( i = 0; i < v1->mConstraints.size; ++i )
  {
    v12 = i;
    v13 = v1->mConstraints.p[v12].m_pPointer;
    if ( v13 )
    {
      UFG::BasePhysicsSystem::RemoveConstraint(v10, v13->mConstraintInstance);
      v14 = v1->mConstraints.p[v12].m_pPointer;
      if ( v14 )
        v14->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v14->vfptr, 1u);
    }
  }
  v15 = v1->mConstraints.p;
  if ( v15 )
  {
    v16 = &v15[-1].m_pPointer;
    `eh vector destructor iterator(
      v15,
      0x18ui64,
      (int)v15[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v16);
  }
  v1->mConstraints.p = 0i64;
  *(_QWORD *)&v1->mConstraints.size = 0i64;
  v17 = v1->mBody;
  v20 = __OFSUB__(v17->m_referenceCount, 1);
  v18 = v17->m_referenceCount == 1;
  v19 = (signed __int16)(v17->m_referenceCount - 1) < 0;
  v17->m_userData = 0i64;
  v21 = 0;
  if ( !((unsigned __int8)(v19 ^ v20) | v18) )
    v21 = 1;
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mBody->vfptr);
  v1->mFlags &= 0xFFFFFFFD;
  v1->mBody = 0i64;
  return v21;
}

// File Line: 604
// RVA: 0xAF9E0
void __fastcall UFG::RigidBody::RemoveFromWorld(UFG::RigidBody *this)
{
  UFG::WindAction *v1; // rdx
  UFG::BasePhysicsSystem *v2; // rbx
  int v3; // esi
  UFG::RigidBody *v4; // rbp
  int v5; // er8
  __int64 v6; // r9
  __int64 v7; // rax
  hkpWorld *v8; // rcx
  unsigned int i; // edi
  UFG::Constraint *v10; // rdx
  hkpEntity *v11; // rdi
  __int64 v12; // rdx
  __int64 v13; // rcx
  hkpEntity **v14; // rax
  __int64 v15; // rax
  hkpWorld *v16; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v17; // rbx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this->mWindAction;
  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = 0;
  v4 = this;
  if ( v1 )
  {
    v5 = 0;
    if ( UFG::BasePhysicsSystem::mInstance->mActionsToAdd.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        if ( (UFG::WindAction *)v2->mActionsToAdd.m_data[v6] == v1 )
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
    v8 = v1->m_world;
    if ( v8 )
      hkpWorld::removeAction(v8, (hkpAction *)&v1->vfptr);
  }
  for ( i = 0; i < v4->mConstraints.size; ++i )
  {
    v10 = v4->mConstraints.p[i].m_pPointer;
    if ( v10 )
      UFG::BasePhysicsSystem::RemoveConstraint(v2, v10->mConstraintInstance);
  }
  v11 = (hkpEntity *)&v4->mBody->vfptr;
  if ( v11 )
  {
    v12 = v2->mEntitiesToAdd.m_size;
    v13 = 0i64;
    if ( v12 > 0 )
    {
      v14 = v2->mEntitiesToAdd.m_data;
      while ( *v14 != v11 )
      {
        ++v13;
        ++v3;
        ++v14;
        if ( v13 >= v12 )
          goto LABEL_23;
      }
      v15 = --v2->mEntitiesToAdd.m_size;
      if ( (_DWORD)v15 != v3 )
        v2->mEntitiesToAdd.m_data[v3] = v2->mEntitiesToAdd.m_data[v15];
    }
LABEL_23:
    v16 = v11->m_world;
    if ( v16 )
    {
      if ( v2->mForceRemoveEntitiesToBeBatched )
      {
        v17 = &v2->mEntitiesToRemove;
        if ( v17->m_size == (v17->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v17, 8);
        v17->m_data[v17->m_size++] = v11;
        hkReferencedObject::addReference((hkReferencedObject *)&v11->vfptr);
      }
      else
      {
        hkpWorld::removeEntity(v16, &result, v11);
      }
    }
  }
}

// File Line: 629
// RVA: 0xB0380
void __fastcall UFG::RigidBody::ResourceUnloaded(UFG::RigidBody *this, UFG::PhysicsResourceHandle *res)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v2; // rdi
  UFG::RigidBody *v3; // rbx

  v2 = this->mCollisionMeshBundle.mPrev;
  this->mRootTransformComponent.m_TypeUID |= 8u;
  v3 = this;
  *(_QWORD *)&this->mUserData.isBoat = 0i64;
  if ( v2 )
  {
    if ( ((__int64 (__fastcall *)(UFG::SimObject **, UFG::PhysicsResourceHandle *))this[-1].mRootTransformComponent.m_pSimObject[1].vfptr)(
           &this[-1].mRootTransformComponent.m_pSimObject,
           res) )
    {
      v2[2].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)UFG::BasePhysicsSystem::mDummyShape;
    }
    v3->mUserData.simComponent.m_pPointer = 0i64;
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
  UFG::CollisionMeshData *v1; // rdx
  __int64 v2; // rax
  __int64 result; // rax

  v1 = this->mCollisionMeshData;
  v2 = v1->mPartDetails.mOffset;
  if ( v2 && (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v1->mPartDetails + v2) )
    result = v1->mNumParts;
  else
    result = 0i64;
  return result;
}

// File Line: 680
// RVA: 0xACCD0
__int64 __fastcall UFG::RigidBody::IsPartFractured(UFG::RigidBody *this, unsigned int index)
{
  BitArray256 *v2; // r8
  __int64 result; // rax

  v2 = this->mFractureState;
  if ( v2 )
    result = v2->mBits[(unsigned __int64)index >> 5] & (1 << (index & 0x1F));
  else
    result = 0i64;
  return result;
}

// File Line: 687
// RVA: 0xABA60
char __fastcall UFG::RigidBody::HasFracturedParts(UFG::RigidBody *this)
{
  UFG::CollisionMeshData *v1; // rax
  BitArray256 *v2; // r9
  unsigned int v3; // er8
  unsigned int v4; // eax
  unsigned int v5; // ecx

  v1 = this->mCollisionMeshData;
  if ( !v1 )
    return 0;
  v2 = this->mFractureState;
  if ( !v2 )
    return 0;
  v3 = v1->mNumParts;
  v4 = 0;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v5 = v2->mBits[(unsigned __int64)v4 >> 5];
    if ( _bittest((const signed int *)&v5, v4 & 0x1F) )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return 1;
}

// File Line: 706
// RVA: 0xA7C50
void __fastcall UFG::RigidBody::EnableFractureParts(UFG::RigidBody *this, UFG::RigidBody::FractureStrength strength)
{
  UFG::RigidBody::FractureStrength v2; // er15
  UFG::RigidBody *v3; // rbx
  UFG::CollisionMeshData *v4; // r8
  __int64 v5; // rax
  UFG::Destruction *v6; // r13
  unsigned int v7; // esi
  __int64 v8; // r14
  __int64 v9; // rbp
  __int64 v10; // rdi
  signed __int64 v11; // rax
  __int64 v12; // rcx
  float v13; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *v14; // rax
  char *v15; // r8
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-60h]

  v2 = strength;
  v3 = this;
  if ( this->mBody )
  {
    v4 = this->mCollisionMeshData;
    if ( v4 )
    {
      v5 = v4->mPartDetails.mOffset;
      if ( v5 )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v4->mPartDetails + v5) )
        {
          v6 = UFG::Destruction::mInstance;
          v7 = 0;
          v8 = v4->mNumParts;
          if ( v8 > 0 )
          {
            v9 = 0i64;
            v10 = 0i64;
            do
            {
              v11 = (signed __int64)&v3->mCollisionMeshData->mPartDetails;
              v12 = *(_QWORD *)v11;
              if ( *(_QWORD *)v11 )
                v12 += v11;
              if ( v10 + v12 )
              {
                v13 = *(float *)(v10 + v12 + 68);
                if ( v13 > 0.0 )
                {
                  if ( v2 == 1 )
                  {
                    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
                    v16.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                    v14 = &v3->mCollisionMeshData->mParts;
                    if ( v14->mOffset )
                      v15 = (char *)v14 + v14->mOffset;
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
                  hkpBreakOffPartsUtil::markPieceBreakable(
                    v6->mBreakOffPartsUtil,
                    (hkpEntity *)&v3->mBody->vfptr,
                    v7,
                    v13);
                }
              }
              ++v7;
              v10 += 96i64;
              v9 += 48i64;
              --v8;
            }
            while ( v8 );
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
  UFG::RigidBody *v1; // rsi
  UFG::CollisionMeshData *v2; // rdx
  __int64 v3; // rax
  __int64 v4; // rbp
  unsigned int v5; // edi
  __int64 v6; // rbx
  signed __int64 v7; // rax
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v9; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->mBody )
  {
    v2 = this->mCollisionMeshData;
    if ( v2 )
    {
      v3 = v2->mPartDetails.mOffset;
      if ( v3 )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v2->mPartDetails + v3) )
        {
          v4 = v2->mNumParts;
          v5 = 0;
          if ( v4 > 0 )
          {
            v6 = 0i64;
            do
            {
              v7 = (signed __int64)&v1->mCollisionMeshData->mPartDetails;
              v8 = *(_QWORD *)v7;
              if ( *(_QWORD *)v7 )
                v8 += v7;
              if ( v6 + v8 && *(float *)(v6 + v8 + 68) > 0.0 )
              {
                v9 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((_QWORD)v1->mBody->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
                if ( v9 )
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                    v9 + 3,
                    &result,
                    v5);
              }
              ++v5;
              v6 += 96i64;
              --v4;
            }
            while ( v4 );
          }
        }
      }
    }
  }
}

// File Line: 761
// RVA: 0xA7920
__int64 __fastcall UFG::RigidBody::EnableFracturePartByGuid(UFG::RigidBody *this, unsigned int nodeId, UFG::RigidBody::FractureStrength strength)
{
  UFG::RigidBody::FractureStrength v3; // er15
  unsigned int v4; // er12
  UFG::RigidBody *v5; // rbx
  unsigned __int8 v6; // r9
  UFG::CollisionMeshData *v7; // r10
  __int64 v8; // rax
  UFG::Destruction *v9; // r13
  unsigned int v10; // esi
  __int64 v11; // r14
  __int64 v12; // rbp
  __int64 v13; // rdi
  signed __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  float v17; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *v18; // rax
  char *v19; // r8
  UFG::qReflectHandleBase v21; // [rsp+28h] [rbp-70h]

  v3 = strength;
  v4 = nodeId;
  v5 = this;
  v6 = 0;
  if ( this->mBody )
  {
    v7 = this->mCollisionMeshData;
    if ( v7 )
    {
      v8 = v7->mPartDetails.mOffset;
      if ( v8 )
      {
        if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v7->mPartDetails + v8) )
        {
          v9 = UFG::Destruction::mInstance;
          v10 = 0;
          v11 = v7->mNumParts;
          if ( v11 > 0 )
          {
            v12 = 0i64;
            v13 = 0i64;
            do
            {
              v14 = (signed __int64)&v5->mCollisionMeshData->mPartDetails;
              v15 = *(_QWORD *)v14;
              if ( *(_QWORD *)v14 )
                v15 += v14;
              v16 = v13 + v15;
              if ( v13 + v15 )
              {
                if ( *(_DWORD *)(v16 + 88) == v4 )
                {
                  v17 = *(float *)(v16 + 68);
                  if ( v17 > 0.0 )
                  {
                    if ( v3 == 1 )
                    {
                      UFG::qReflectHandleBase::qReflectHandleBase(&v21);
                      v21.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                      v18 = &v5->mCollisionMeshData->mParts;
                      if ( v18->mOffset )
                        v19 = (char *)v18 + v18->mOffset;
                      else
                        v19 = 0i64;
                      UFG::qReflectHandleBase::Init(&v21, v21.mTypeUID, *(_QWORD *)&v19[v12 + 16]);
                      if ( v21.mData && *(float *)v21.mData[1].mBaseNode.mChildren > 0.0 )
                        v17 = *(float *)v21.mData[1].mBaseNode.mChildren;
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v21);
                    }
                    hkpBreakOffPartsUtil::markPieceBreakable(
                      v9->mBreakOffPartsUtil,
                      (hkpEntity *)&v5->mBody->vfptr,
                      v10,
                      v17);
                    v6 = 1;
                  }
                }
              }
              ++v10;
              v13 += 96i64;
              v12 += 48i64;
              --v11;
            }
            while ( v11 );
          }
        }
      }
    }
  }
  return v6;
}

// File Line: 798
// RVA: 0xA7AE0
char __fastcall UFG::RigidBody::EnableFracturePartByIndex(UFG::RigidBody *this, unsigned int index, UFG::RigidBody::FractureStrength strength)
{
  __int64 v3; // rsi
  UFG::RigidBody *v4; // rbx
  UFG::CollisionMeshData *v5; // r9
  __int64 v6; // rax
  UFG::Destruction *v7; // rbp
  __int64 v8; // rax
  char *v9; // rdi
  signed __int64 v10; // rdx
  signed __int64 v11; // rcx
  float v12; // xmm6_4
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *v13; // rax
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-50h]

  v3 = index;
  v4 = this;
  if ( !this->mBody )
    return 0;
  v5 = this->mCollisionMeshData;
  if ( !v5 )
    return 0;
  v6 = v5->mPartDetails.mOffset;
  if ( !v6 || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v5->mPartDetails + v6) )
    return 0;
  v7 = UFG::Destruction::mInstance;
  v8 = v5->mPartDetails.mOffset;
  v9 = 0i64;
  v10 = (signed __int64)(v8 ? (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v5->mPartDetails + v8) : 0i64);
  v11 = v10 + 96i64 * (signed int)v3;
  if ( !v11 )
    return 0;
  v12 = *(float *)(v11 + 68);
  if ( v12 <= 0.0 )
    return 0;
  if ( strength == 1 )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v15);
    v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    v13 = &v4->mCollisionMeshData->mParts;
    if ( v13->mOffset )
      v9 = (char *)v13 + v13->mOffset;
    UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, *(_QWORD *)&v9[48 * v3 + 16]);
    if ( v15.mData )
    {
      if ( *(float *)v15.mData[1].mBaseNode.mChildren > 0.0 )
        v12 = *(float *)v15.mData[1].mBaseNode.mChildren;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
  }
  hkpBreakOffPartsUtil::markPieceBreakable(v7->mBreakOffPartsUtil, (hkpEntity *)&v4->mBody->vfptr, v3, v12);
  return 1;
}

// File Line: 832
// RVA: 0xA74B0
__int64 __fastcall UFG::RigidBody::DisableFracturePartByGuid(UFG::RigidBody *this, unsigned int nodeId)
{
  unsigned __int8 v2; // r8
  unsigned int v3; // er14
  UFG::RigidBody *v4; // rsi
  UFG::CollisionMeshData *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rbp
  unsigned int v8; // edi
  UFG::Destruction *v9; // r15
  __int64 v10; // rbx
  signed __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rax

  v2 = 0;
  v3 = nodeId;
  v4 = this;
  if ( !this->mBody )
    return 0i64;
  v5 = this->mCollisionMeshData;
  if ( !v5 )
    return 0i64;
  v6 = v5->mPartDetails.mOffset;
  if ( !v6 || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v5->mPartDetails + v6) )
    return 0i64;
  v7 = v5->mNumParts;
  v8 = 0;
  v9 = UFG::Destruction::mInstance;
  if ( v7 <= 0 )
    return 0i64;
  v10 = 0i64;
  do
  {
    v11 = (signed __int64)&v4->mCollisionMeshData->mPartDetails;
    v12 = *(_QWORD *)v11;
    if ( *(_QWORD *)v11 )
      v12 += v11;
    v13 = v10 + v12;
    if ( v10 + v12 && *(_DWORD *)(v13 + 88) == v3 && *(float *)(v13 + 68) > 0.0 )
    {
      hkpBreakOffPartsUtil::unmarkPieceBreakable(v9->mBreakOffPartsUtil, (hkpEntity *)&v4->mBody->vfptr, v8);
      v2 = 1;
    }
    ++v8;
    v10 += 96i64;
    --v7;
  }
  while ( v7 );
  return v2;
}

// File Line: 858
// RVA: 0xA75D0
char __fastcall UFG::RigidBody::DisableFracturePartByIndex(UFG::RigidBody *this, unsigned int index)
{
  hkpRigidBody *v2; // r9
  __int64 v3; // r10
  UFG::CollisionMeshData *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rdx
  signed __int64 v8; // r8

  v2 = this->mBody;
  v3 = (signed int)index;
  if ( !v2 )
    return 0;
  v4 = this->mCollisionMeshData;
  if ( !v4 )
    return 0;
  v5 = v4->mPartDetails.mOffset;
  if ( !v5 || !(UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v4->mPartDetails + v5) )
    return 0;
  v6 = v4->mPartDetails.mOffset;
  v7 = (signed __int64)(v6 ? (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v4->mPartDetails + v6) : 0i64);
  v8 = v7 + 96 * v3;
  if ( !v8 || *(float *)(v8 + 68) <= 0.0 )
    return 0;
  hkpBreakOffPartsUtil::unmarkPieceBreakable(
    UFG::Destruction::mInstance->mBreakOffPartsUtil,
    (hkpEntity *)&v2->vfptr,
    v3);
  return 1;
}

// File Line: 882
// RVA: 0xAB1C0
float __fastcall UFG::RigidBody::GetPercentFractured(UFG::RigidBody *this)
{
  hkpShape *v1; // rbx
  float result; // xmm0_4

  v1 = this->mCollisionMeshData->mShape;
  if ( v1->m_type.m_storage == 8 )
    result = (float)WORD1(v1[2].vfptr)
           / (float)((float)WORD1(v1[2].vfptr)
                   + (float)((signed int (__fastcall *)(hkpShape *))v1[1].vfptr->__first_virtual_table_function__)(&v1[1]));
  else
    result = 0.0;
  return result;
}

// File Line: 908
// RVA: 0xAB650
void __fastcall UFG::RigidBody::GetTransform(UFG::RigidBody *this, UFG::qMatrix44 *mat)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::RigidBody *v3; // rdx
  hkpRigidBody *v4; // rcx
  UFG::CollisionInstanceData *v5; // rdx
  hkRotationf v6; // [rsp+20h] [rbp-48h]
  hkVector4f v7; // [rsp+50h] [rbp-18h]

  v2 = mat;
  v3 = this;
  v4 = this->mBody;
  if ( v4 )
  {
    hkTransformf::get4x4ColumnMajor(&v4->m_motion.m_motionState.m_transform, &v2->v0.x);
  }
  else
  {
    v5 = v3->mInstanceData;
    v7.m_quad = (__m128)v5->mPosition;
    hkRotationf::set(&v6, &v5->mOrientation);
    hkTransformf::get4x4ColumnMajor((hkTransformf *)&v6, &v2->v0.x);
  }
}

// File Line: 926
// RVA: 0xB2630
void __fastcall UFG::RigidBody::SetTransform(UFG::RigidBody *this, UFG::qMatrix44 *mat)
{
  UFG::RigidBody *v2; // rbx
  hkpRigidBody *v3; // rcx
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v2 = this;
  hkTransformf::set4x4ColumnMajor(&transform, &mat->v0.x);
  v3 = v2->mBody;
  if ( v3 )
  {
    hkpRigidBody::setTransform(v3, &transform);
  }
  else
  {
    hkQuaternionf::set(&v2->mInstanceData->mOrientation, &transform.m_rotation);
    v2->mInstanceData->mPosition = transform.m_translation;
  }
}

// File Line: 946
// RVA: 0xAB970
UFG::qVector3 *__fastcall UFG::RigidBody::GetVelocity(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *v2; // r8
  float v3; // xmm1_4
  float v4; // xmm0_4

  v2 = this->mBody;
  v3 = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  v4 = UFG::qVector3::msZero.z;
  result->y = v3;
  result->z = v4;
  if ( v2 )
  {
    result->x = v2->m_motion.m_linearVelocity.m_quad.m128_f32[0];
    result->y = v2->m_motion.m_linearVelocity.m_quad.m128_f32[1];
    result->z = v2->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  }
  return result;
}

// File Line: 961
// RVA: 0xA9550
UFG::qVector3 *__fastcall UFG::RigidBody::GetAngularVelocity(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *v2; // r8
  float v3; // xmm1_4
  float v4; // xmm0_4

  v2 = this->mBody;
  v3 = UFG::qVector3::msZero.y;
  result->x = UFG::qVector3::msZero.x;
  v4 = UFG::qVector3::msZero.z;
  result->y = v3;
  result->z = v4;
  if ( v2 )
  {
    result->x = v2->m_motion.m_angularVelocity.m_quad.m128_f32[0];
    result->y = v2->m_motion.m_angularVelocity.m_quad.m128_f32[1];
    result->z = v2->m_motion.m_angularVelocity.m_quad.m128_f32[2];
  }
  return result;
}

// File Line: 976
// RVA: 0xB2850
void __fastcall UFG::RigidBody::SetVelocity(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *v2; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h]

  v2 = this->mBody;
  if ( v2 )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    v2->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)&v4);
  }
}

// File Line: 988
// RVA: 0xB05D0
void __fastcall UFG::RigidBody::SetAngularVelocity(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *v2; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h]

  v2 = this->mBody;
  if ( v2 )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v2->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v2->m_motion,
      &v4);
  }
}

// File Line: 1007
// RVA: 0xA0EA0
void __fastcall UFG::RigidBody::ApplyForce(UFG::RigidBody *this, float timeDelta, UFG::qVector3 *force, UFG::qVector3 *point)
{
  hkpRigidBody *v4; // rbx
  __m128 v5; // xmm3
  __int64 v6; // rdx
  __m128 v7; // [rsp+20h] [rbp-38h]
  __m128 v8; // [rsp+30h] [rbp-28h]

  v4 = this->mBody;
  v5 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(point->x), (__m128)LODWORD(point->z)),
         _mm_unpacklo_ps((__m128)LODWORD(point->y), (__m128)(unsigned int)FLOAT_1_0));
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(force->x), (__m128)LODWORD(force->z)),
         _mm_unpacklo_ps((__m128)LODWORD(force->y), (__m128)(unsigned int)FLOAT_1_0));
  v7 = v5;
  hkpEntity::activate((hkpEntity *)&v4->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, __m128 *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v4->m_motion.vfptr[12].__first_virtual_table_function__)(
    &v4->m_motion,
    v6,
    &v8,
    &v7,
    v5.m128_u64[0],
    v5.m128_u64[1],
    v8.m128_u64[0],
    v8.m128_u64[1]);
}

// File Line: 1018
// RVA: 0xA1080
void __fastcall UFG::RigidBody::ApplyLinearImpulse(UFG::RigidBody *this, UFG::qVector3 *impulse)
{
  hkpRigidBody *v2; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h]

  v2 = this->mBody;
  if ( v2 )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
           _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    v2->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)&v4);
  }
}

// File Line: 1030
// RVA: 0xA1000
void __fastcall UFG::RigidBody::ApplyLinearImpulse(UFG::RigidBody *this, UFG::qVector3 *impulse, UFG::qVector3 *point)
{
  hkpRigidBody *v3; // rbx
  hkpRigidBody *v4; // rcx
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // [rsp+20h] [rbp-28h]
  __m128 v8; // [rsp+30h] [rbp-18h]

  v3 = this->mBody;
  if ( v3 )
  {
    v4 = this->mBody;
    v5 = (__m128)LODWORD(point->z);
    v6 = (__m128)LODWORD(point->y);
    v8 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(impulse->x), (__m128)LODWORD(impulse->z)),
           _mm_unpacklo_ps((__m128)LODWORD(impulse->y), (__m128)0i64));
    v7 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(point->x), v5), _mm_unpacklo_ps(v6, (__m128)0i64));
    hkpEntity::activate((hkpEntity *)&v4->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v3->m_motion.vfptr[11].__first_virtual_table_function__)(
      &v3->m_motion,
      &v8,
      &v7);
  }
}

// File Line: 1043
// RVA: 0xA0BC0
void __fastcall UFG::RigidBody::ApplyAngularImpulse(UFG::RigidBody *this, UFG::qVector3 *vel)
{
  hkpRigidBody *v2; // rbx
  hkpRigidBody *v3; // rcx
  __m128 v4; // [rsp+20h] [rbp-18h]

  v2 = this->mBody;
  if ( v2 )
  {
    v3 = this->mBody;
    v4 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(vel->x), (__m128)LODWORD(vel->z)),
           _mm_unpacklo_ps((__m128)LODWORD(vel->y), (__m128)0i64));
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    v2->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)&v4);
  }
}

// File Line: 1055
// RVA: 0xB13D0
void __fastcall UFG::RigidBody::SetLinearDamping(UFG::RigidBody *this, float d)
{
  hkpRigidBody *v2; // rdx
  float v3; // [rsp+8h] [rbp+8h]

  v2 = this->mBody;
  if ( v2 )
  {
    v3 = d * 1.0039062;
    v2->m_motion.m_motionState.m_linearDamping.m_value = HIWORD(v3);
  }
}

// File Line: 1079
// RVA: 0xACD30
bool __fastcall UFG::RigidBody::IsSleeping(UFG::RigidBody *this)
{
  hkpRigidBody *v1; // rcx
  bool v2; // al
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this->mBody;
  if ( v1 )
    v2 = hkpEntity::isActive((hkpEntity *)&v1->vfptr, &result)->m_bool == 0;
  else
    v2 = 1;
  return v2;
}

// File Line: 1086
// RVA: 0xAA990
void __fastcall UFG::RigidBody::GetMass(UFG::RigidBody *this)
{
  hkpRigidBody *v1; // rax
  __int128 v2; // xmm0

  v1 = this->mBody;
  if ( v1 )
    hkpMotion::getMass((hkpMotion *)&v1->m_motion.vfptr);
  else
    v2 = LODWORD(this->mCollisionMeshData->mMass);
}

// File Line: 1103
// RVA: 0xA9730
UFG::qVector3 *__fastcall UFG::RigidBody::GetCentreOfMass(UFG::RigidBody *this, UFG::qVector3 *result)
{
  hkpRigidBody *v2; // r8
  UFG::CollisionInstanceData *v4; // rcx

  v2 = this->mBody;
  if ( v2 )
  {
    result->x = v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[0];
    result->y = v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[1];
    result->z = v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[2];
  }
  else
  {
    v4 = this->mInstanceData;
    result->x = v4->mPosition.m_quad.m128_f32[0];
    result->y = v4->mPosition.m_quad.m128_f32[1];
    result->z = v4->mPosition.m_quad.m128_f32[2];
  }
  return result;
}

// File Line: 1123
// RVA: 0xA0300
void __fastcall UFG::RigidBody::AddConstraint(UFG::RigidBody *this, UFG::Constraint *constraint)
{
  UFG::RigidBody *v2; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v3; // rax
  __int64 v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // rdx
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  __int64 *v13; // rcx
  _QWORD *v14; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax
  __int64 *v17; // [rsp+28h] [rbp-18h]
  UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *v18; // [rsp+30h] [rbp-10h]
  UFG::Constraint *v19; // [rsp+38h] [rbp-8h]

  v2 = this;
  v17 = (__int64 *)&v17;
  v18 = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  v19 = constraint;
  if ( constraint )
  {
    v3 = constraint->m_SafePointerList.mNode.mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
    v17 = (__int64 *)v3;
    v18 = &constraint->m_SafePointerList;
    constraint->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v17;
  }
  v4 = this->mConstraints.size;
  v5 = v4 + 1;
  v6 = this->mConstraints.capacity;
  if ( (signed int)v4 + 1 > v6 )
  {
    if ( v6 )
      v7 = 2 * v6;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
      &this->mConstraints,
      v7,
      "qArray.Add");
  }
  v2->mConstraints.size = v5;
  v8 = &v2->mConstraints.p[v4];
  v9 = (__int64)v19;
  if ( v8->m_pPointer )
  {
    v10 = v8->mPrev;
    v11 = v8->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v8->m_pPointer = (UFG::Constraint *)v9;
  if ( v9 )
  {
    v12 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v9 + 8);
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v12;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v8;
  }
  if ( v19 )
  {
    v13 = v17;
    v14 = &v18->mNode.mPrev;
    v17[1] = (__int64)v18;
    *v14 = v13;
    v17 = (__int64 *)&v17;
    v18 = (UFG::qList<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList,1,0> *)&v17;
  }
  v15 = v17;
  v16 = &v18->mNode.mPrev;
  v17[1] = (__int64)v18;
  *v16 = v15;
}

// File Line: 1130
// RVA: 0xAF6C0
void __fastcall UFG::RigidBody::RemoveConstraint(UFG::RigidBody *this, UFG::Constraint *constraint)
{
  unsigned int v2; // er10
  __int64 v3; // r8
  UFG::RigidBody *v4; // r9
  UFG::Constraint **v5; // rax
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v6; // rdx
  bool v7; // zf
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v8; // r8
  UFG::Constraint *v9; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v12; // rax
  unsigned int v13; // eax

  v2 = this->mConstraints.size;
  v3 = 0i64;
  v4 = this;
  if ( v2 )
  {
    v5 = &this->mConstraints.p->m_pPointer;
    while ( constraint != *v5 )
    {
      v3 = (unsigned int)(v3 + 1);
      v5 += 3;
      if ( (unsigned int)v3 >= v2 )
        return;
    }
    v6 = this->mConstraints.p;
    v7 = v6[v3].m_pPointer == 0i64;
    v8 = &v6[v3];
    v9 = v6[v2 - 1].m_pPointer;
    if ( !v7 )
    {
      v10 = v8->mPrev;
      v11 = v8->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v8->m_pPointer = v9;
    if ( v9 )
    {
      v12 = v9->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v12;
      v8->mNext = &v9->m_SafePointerList.mNode;
      v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v13 = v4->mConstraints.size;
    if ( v13 > 1 )
      v4->mConstraints.size = v13 - 1;
    else
      v4->mConstraints.size = 0;
  }
}

// File Line: 1145
// RVA: 0xA9900
UFG::Constraint *__fastcall UFG::RigidBody::GetConstraintByIndex(UFG::RigidBody *this, unsigned int index)
{
  UFG::Constraint *result; // rax

  if ( index >= this->mConstraints.size )
    result = 0i64;
  else
    result = this->mConstraints.p[index].m_pPointer;
  return result;
}

// File Line: 1157
// RVA: 0xA9920
UFG::Constraint *__fastcall UFG::RigidBody::GetConstraintByName(UFG::RigidBody *this, __int64 name)
{
  unsigned int v2; // er9
  __int64 v3; // r8
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v4; // r10
  int v5; // edx
  signed __int64 v6; // rcx

  v2 = this->mConstraints.size;
  v3 = 0i64;
  if ( !v2 )
    return 0i64;
  v4 = this->mConstraints.p;
  v5 = *(_DWORD *)name;
  v6 = (signed __int64)&v4->m_pPointer;
  while ( *(_DWORD *)(*(_QWORD *)v6 + 48i64) != v5 )
  {
    v3 = (unsigned int)(v3 + 1);
    v6 += 24i64;
    if ( (unsigned int)v3 >= v2 )
      return 0i64;
  }
  return v4[v3].m_pPointer;
}

// File Line: 1173
// RVA: 0xA77E0
void __fastcall UFG::RigidBody::EnableAllConstraints(UFG::RigidBody *this)
{
  __int64 v1; // rbx
  UFG::RigidBody *v2; // rsi
  UFG::Constraint *v3; // rdi
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = 0i64;
  v2 = this;
  if ( this->mConstraints.size )
  {
    do
    {
      v3 = v2->mConstraints.p[v1].m_pPointer;
      if ( v3 )
      {
        if ( !hkpConstraintInstance::isEnabled(v3->mConstraintInstance, &result)->m_bool )
          hkpConstraintInstance::enable(v3->mConstraintInstance);
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mConstraints.size );
  }
}

// File Line: 1190
// RVA: 0xA7220
void __fastcall UFG::RigidBody::DisableAllConstraints(UFG::RigidBody *this)
{
  __int64 v1; // rbx
  UFG::RigidBody *v2; // rsi
  UFG::Constraint *v3; // rdi
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = 0i64;
  v2 = this;
  if ( this->mConstraints.size )
  {
    do
    {
      v3 = v2->mConstraints.p[v1].m_pPointer;
      if ( v3 )
      {
        if ( hkpConstraintInstance::isEnabled(v3->mConstraintInstance, &result)->m_bool )
          hkpConstraintInstance::disable(v3->mConstraintInstance);
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mConstraints.size );
  }
}

// File Line: 1207
// RVA: 0xA6B70
void __fastcall UFG::RigidBody::DeleteAllConstraints(UFG::RigidBody *this)
{
  __int64 v1; // rbx
  UFG::RigidBody *v2; // rdi
  UFG::Constraint *v3; // rcx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v4; // rcx
  UFG::Constraint **v5; // rbx

  v1 = 0i64;
  v2 = this;
  if ( this->mConstraints.size )
  {
    do
    {
      v3 = v2->mConstraints.p[v1].m_pPointer;
      if ( v3 )
        v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v3->vfptr, 1u);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mConstraints.size );
  }
  v4 = v2->mConstraints.p;
  if ( v4 )
  {
    v5 = &v4[-1].m_pPointer;
    `eh vector destructor iterator(
      v4,
      0x18ui64,
      (int)v4[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v5);
  }
  v2->mConstraints.p = 0i64;
  *(_QWORD *)&v2->mConstraints.size = 0i64;
}

// File Line: 1219
// RVA: 0xB1500
void __fastcall UFG::RigidBody::SetMotionType(UFG::RigidBody *this, unsigned int mode)
{
  UFG::RigidBody *v2; // rbx
  unsigned int v3; // ecx
  hkpRigidBody *v4; // rcx
  unsigned int v5; // edx
  int v6; // edx
  int v7; // edx
  hkpMotion::MotionType v8; // edx
  UFG::CollisionMeshData *v9; // rdx
  int v10; // ecx
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = this->mFlags;
  if ( (v3 & 960) != mode )
  {
    v2->mFlags = mode | v3 & 0xFFFFFC3F;
    v4 = v2->mBody;
    if ( v4 )
    {
      v5 = mode - 0x40;
      if ( !v5 )
      {
        v8 = 5;
        goto LABEL_18;
      }
      v6 = v5 - 0x40;
      if ( v6 )
      {
        v7 = v6 - 128;
        if ( !v7 )
        {
          v8 = 4;
          goto LABEL_18;
        }
        if ( v7 != 256 )
        {
          v8 = 0;
LABEL_18:
          hkpRigidBody::setMotionType(v4, v8, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
          return;
        }
      }
      if ( (unsigned int)(unsigned __int8)v4->m_motion.m_type.m_storage - 4 > 1
        || hkpRigidBody::getStoredDynamicMotion(v4) )
      {
        hkpRigidBody::setMotionType(v2->mBody, MOTION_DYNAMIC, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
        UFG::qReflectHandleBase::qReflectHandleBase(&v11);
        v11.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        v9 = v2->mCollisionMeshData;
        if ( v9 )
          UFG::qReflectHandleBase::operator=(&v11, (UFG::qReflectHandleBase *)&v9->mObjectProperties.mPrev);
        if ( v11.mData )
        {
          v10 = HIDWORD(v11.mData[2].mBaseNode.mChildren[0]);
          if ( v10 != -1 )
            v2->mBody->m_collidable.m_broadPhaseHandle.m_objectQualityType = v10;
        }
        hkpEntity::activate((hkpEntity *)&v2->mBody->vfptr);
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
void __fastcall UFG::RigidBody::SetCollisionLayer(UFG::RigidBody *this, unsigned int layerNum, int systemNum, int subSystemNum, int subSystemNumDisable)
{
  hkpRigidBody *v5; // rax
  int v6; // er10
  int v7; // er11
  int v8; // er8
  int v9; // er11
  int v10; // er11
  unsigned int v11; // er11
  hkpRigidBody *v12; // rdx
  hkpWorld *v13; // rcx

  v5 = this->mBody;
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
  v11 = layerNum | 32 * (v6 | v10);
  this->mCollisionLayerOverride = v11;
  if ( v5 && v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v11 )
  {
    v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v11;
    v12 = this->mBody;
    v13 = v12->m_world;
    if ( v13 )
      hkpWorld::updateCollisionFilterOnEntity(
        v13,
        (hkpEntity *)&v12->vfptr,
        0,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
}

// File Line: 1342
// RVA: 0xA9810
__int64 __fastcall UFG::RigidBody::GetCollisionLayer(UFG::RigidBody *this)
{
  UFG::RigidBody *v1; // rbx
  hkpRigidBody *v2; // rax
  unsigned int v3; // eax
  UFG::CollisionMeshData *v5; // rdx
  unsigned int v6; // ebx
  UFG::qReflectHandleBase v7; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->mBody;
  if ( v2 )
  {
    v3 = v2->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
    return v3 & 0x1F;
  }
  v3 = this->mCollisionLayerOverride;
  if ( v3 != -1 )
    return v3 & 0x1F;
  UFG::qReflectHandleBase::qReflectHandleBase(&v7);
  v7.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v5 = v1->mCollisionMeshData;
  if ( v5 )
    UFG::qReflectHandleBase::operator=(&v7, (UFG::qReflectHandleBase *)&v5->mObjectProperties.mPrev);
  if ( v7.mData )
    v6 = (unsigned int)v7.mData[2].mBaseNode.mChildren[0];
  else
    v6 = 0;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v7);
  return v6;
}

// File Line: 1372
// RVA: 0xA93B0
bool __fastcall UFG::RigidBody::GetAabb(UFG::RigidBody *this, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax, UFG::RigidBody::AabbTypes aabbType)
{
  UFG::RigidBody::AabbTypes v4; // edi
  UFG::qVector3 *v5; // rsi
  UFG::qVector3 *v6; // rbp
  UFG::RigidBody *v7; // rbx
  __int64 v8; // r8
  __int128 v9; // xmm1
  __m128 *v10; // rax
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  float v17; // [rsp+20h] [rbp-148h]
  int v18; // [rsp+24h] [rbp-144h]
  int v19; // [rsp+28h] [rbp-140h]
  int v20; // [rsp+30h] [rbp-138h]
  int v21; // [rsp+34h] [rbp-134h]
  int v22; // [rsp+38h] [rbp-130h]
  __m128 v23; // [rsp+40h] [rbp-128h]
  __m128 v24; // [rsp+50h] [rbp-118h]
  __m128 v25; // [rsp+60h] [rbp-108h]
  __int128 v26; // [rsp+70h] [rbp-F8h]
  hkpRigidBodyCinfo info; // [rsp+80h] [rbp-E8h]

  v4 = aabbType;
  v5 = aabbMax;
  v6 = aabbMin;
  v7 = this;
  if ( !this->mBody )
    return v7->mBody != 0i64;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  hkpRigidBody::getCinfo(v7->mBody, &info);
  if ( v4 == 1 )
  {
    v23 = transform.m_quad;
    v24 = direction.m_quad;
    v9 = 0i64;
    v25 = stru_141A71280.m_quad;
LABEL_6:
    v26 = v9;
    ((void (__fastcall *)(hkpShape *, __m128 *, __int64, float *))info.m_shape->vfptr[2].__vecDelDtor)(
      info.m_shape,
      &v23,
      v8,
      &v17);
    v11 = v18;
    v6->x = v17;
    v12 = v19;
    LODWORD(v6->y) = v11;
    v13 = v20;
    LODWORD(v6->z) = v12;
    v14 = v21;
    LODWORD(v5->x) = v13;
    v15 = v22;
    LODWORD(v5->y) = v14;
    LODWORD(v5->z) = v15;
    return v7->mBody != 0i64;
  }
  if ( v4 == 2 )
  {
    v10 = (__m128 *)v7->mBody;
    v23 = v10[23];
    v24 = v10[24];
    v25 = v10[25];
    v9 = (__int128)v10[26];
    goto LABEL_6;
  }
  return 0;
}

// File Line: 1414
// RVA: 0xAAE30
float __fastcall UFG::GetOneOverApparentMass(hkpRigidBody *body, hkVector4f *pos, hkVector4f *dir)
{
  hkpRigidBody *v3; // rsi
  hkVector4f *v4; // rbx
  hkVector4f *v5; // rdi
  __m128 v6; // xmm3
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm5
  __m128 v14; // [rsp+20h] [rbp-38h]
  __m128 v15; // [rsp+30h] [rbp-28h]
  __m128 v16; // [rsp+40h] [rbp-18h]

  v3 = body;
  v4 = pos;
  v5 = dir;
  body->m_motion.vfptr[6].__vecDelDtor((hkBaseObject *)&body->m_motion, (unsigned int)&v14);
  v6 = _mm_sub_ps(v4->m_quad, v3->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 201), v6), _mm_mul_ps(v7, v5->m_quad));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v15), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v16));
  v11 = _mm_sub_ps(_mm_mul_ps(v7, v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v6));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v5->m_quad);
  return v3->m_motion.m_inertiaAndMassInv.m_quad.m128_f32[3]
       + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)));
}

// File Line: 1437
// RVA: 0xA7F30
float __fastcall UFG::EstimateImpulseMagnitude(hkpRigidBody *rb0, hkpRigidBody *rb1, hkVector4f *pos, hkVector4f *normal, float normalSpeed, float coeffRestitution)
{
  hkVector4f *v6; // rdi
  hkpRigidBody *v7; // rsi
  hkVector4f *v8; // rbx
  float v9; // xmm6_4
  float result; // xmm0_4

  v6 = pos;
  v7 = rb1;
  v8 = normal;
  v9 = UFG::GetOneOverApparentMass(rb0, pos, normal);
  LODWORD(result) = (COERCE_UNSIGNED_INT(
                       (float)((float)(coeffRestitution + 1.0) * normalSpeed)
                     / (float)(UFG::GetOneOverApparentMass(v7, v6, v8) + v9)) ^ _xmm[0]) & _xmm;
  return result;
}

