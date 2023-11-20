// File Line: 26
// RVA: 0xD673E0
void __fastcall hkpShapePhantom::hkpShapePhantom(hkpShapePhantom *this, hkpShape *shape, hkTransformf *transform)
{
  hkTransformf *v3; // rdi
  hkpShapePhantom *v4; // rsi
  hkQuaternionf rotation; // [rsp+20h] [rbp-18h]

  v3 = transform;
  v4 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, shape, BROAD_PHASE_PHANTOM);
  v4->m_overlapListeners.m_capacityAndFlags = 2147483648;
  v4->m_overlapListeners.m_data = 0i64;
  v4->m_overlapListeners.m_size = 0;
  v4->m_phantomListeners.m_data = 0i64;
  v4->m_phantomListeners.m_size = 0;
  v4->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v4->m_collidable.m_ownerOffset = -32;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpShapePhantom::`vftable';
  hkQuaternionf::set(&rotation, &v3->m_rotation);
  hkMotionState::initMotionState(&v4->m_motionState, &v3->m_translation, &rotation);
  v4->m_collidable.m_motion = &v4->m_motionState;
}

// File Line: 38
// RVA: 0xD676C0
hkMotionState *__fastcall hkpShapePhantom::getMotionState(hkpShapePhantom *this)
{
  return &this->m_motionState;
}

// File Line: 47
// RVA: 0xD67490
void __fastcall hkpShapePhantom::setTransform(hkpShapePhantom *this, hkTransformf *transform)
{
  hkpShapePhantom *v2; // rbx
  hkpWorld *v3; // rax
  float v4; // xmm2_4
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  v2 = this;
  this->m_motionState.m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  this->m_motionState.m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  this->m_motionState.m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  this->m_motionState.m_transform.m_translation = transform->m_translation;
  v3 = this->m_world;
  if ( v3 )
  {
    v4 = v3->m_collisionInput->m_tolerance.m_storage * 0.5;
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkBaseObjectVtbl *, hkAabb *))this->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
      this->m_collidable.m_shape,
      transform,
      this->m_collidable.m_shape->vfptr,
      &aabb);
    hkpPhantom::updateBroadPhase((hkpPhantom *)&v2->vfptr, &aabb);
  }
}

// File Line: 63
// RVA: 0xD67510
void __fastcall hkpShapePhantom::setPosition(hkpShapePhantom *this, hkVector4f *position, float extraTolerance)
{
  hkpWorld *v3; // rax
  hkpShapePhantom *v4; // rbx
  float v5; // xmm2_4
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  v3 = this->m_world;
  v4 = this;
  this->m_motionState.m_transform.m_translation = (hkVector4f)position->m_quad;
  if ( v3 )
  {
    v5 = (float)(v3->m_collisionInput->m_tolerance.m_storage * 0.5) + extraTolerance;
    ((void (__fastcall *)(hkpShape *, hkMotionState *, hkBaseObjectVtbl *, hkAabb *))this->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
      this->m_collidable.m_shape,
      &this->m_motionState,
      this->m_collidable.m_shape->vfptr,
      &aabb);
    hkpPhantom::updateBroadPhase((hkpPhantom *)&v4->vfptr, &aabb);
  }
}

// File Line: 79
// RVA: 0xD67680
void __fastcall hkpShapePhantom::calcAabb(hkpShapePhantom *this, hkAabb *aabb, __int64 a3)
{
  hkpWorld *v3; // rax
  float v4; // xmm2_4

  v3 = this->m_world;
  if ( v3 )
    v4 = v3->m_collisionInput->m_tolerance.m_storage * 0.5;
  ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, hkAabb *))this->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
    this->m_collidable.m_shape,
    &this->m_motionState,
    a3,
    aabb);
}

// File Line: 88
// RVA: 0xD676D0
void __fastcall hkpShapePhantom::deallocateInternalArrays(hkpShapePhantom *this)
{
  hkpPhantom::deallocateInternalArrays((hkpPhantom *)&this->vfptr);
}

// File Line: 98
// RVA: 0xD67580
signed __int64 __fastcall hkpShapePhantom::setShape(hkpShapePhantom *this, hkpShape *shape)
{
  hkpWorld *v2; // rax
  hkpShape *v3; // rdi
  hkpShapePhantom *v4; // rbx
  hkReferencedObject *v6; // rcx
  hkpWorld *v7; // rcx
  hkpWorld *v8; // rcx
  hkpWorld *v9; // rbx
  bool v10; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpShapePhantom *v12; // [rsp+28h] [rbp-20h]
  hkpShape *v13; // [rsp+30h] [rbp-18h]

  v2 = this->m_world;
  v3 = shape;
  v4 = this;
  if ( v2 )
  {
    if ( v2->m_criticalOperationsLockCount )
    {
      v13 = shape;
      v12 = this;
      operation.m_type.m_storage = 5;
      hkpWorld::queueOperation(v2, &operation);
      return 0i64;
    }
    if ( v2 )
    {
      ++v2->m_criticalOperationsLockCount;
      hkpWorldOperationUtil::removePhantomBP(this->m_world, (hkpPhantom *)&this->vfptr);
    }
  }
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v6 = (hkReferencedObject *)&v4->m_collidable.m_shape->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v7 = v4->m_world;
  v4->m_collidable.m_shape = v3;
  if ( v7 )
    hkpWorldCallbackUtil::firePhantomShapeSet(v7, (hkpPhantom *)&v4->vfptr);
  hkpPhantom::firePhantomShapeSet((hkpPhantom *)&v4->vfptr);
  v8 = v4->m_world;
  if ( v8 )
  {
    hkpWorldOperationUtil::addPhantomBP(v8, (hkpPhantom *)&v4->vfptr);
    v9 = v4->m_world;
    v10 = v9->m_criticalOperationsLockCount-- == 1;
    if ( v10 && !v9->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v9->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v9);
      if ( v9->m_pendingOperationQueueCount == 1 )
      {
        if ( v9->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v9);
      }
    }
  }
  return 1i64;
}

