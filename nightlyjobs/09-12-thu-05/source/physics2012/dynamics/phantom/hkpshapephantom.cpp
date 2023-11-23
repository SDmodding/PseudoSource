// File Line: 26
// RVA: 0xD673E0
void __fastcall hkpShapePhantom::hkpShapePhantom(hkpShapePhantom *this, hkpShape *shape, hkTransformf *transform)
{
  hkQuaternionf rotation; // [rsp+20h] [rbp-18h] BYREF

  hkpWorldObject::hkpWorldObject(this, shape, 2);
  this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  this->m_overlapListeners.m_data = 0i64;
  this->m_overlapListeners.m_size = 0;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->m_collidable.m_ownerOffset = -32;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapePhantom::`vftable;
  hkQuaternionf::set(&rotation, &transform->m_rotation);
  hkMotionState::initMotionState(&this->m_motionState, &transform->m_translation, &rotation);
  this->m_collidable.m_motion = &this->m_motionState;
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
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  this->m_motionState.m_transform = *transform;
  if ( this->m_world )
  {
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkBaseObjectVtbl *, hkAabb *))this->m_collidable.m_shape->hkpPhantom::hkpWorldObject::vfptr[2].__vecDelDtor)(
      this->m_collidable.m_shape,
      transform,
      this->m_collidable.m_shape->hkpPhantom::hkpWorldObject::vfptr,
      &aabb);
    hkpPhantom::updateBroadPhase(this, &aabb);
  }
}

// File Line: 63
// RVA: 0xD67510
void __fastcall hkpShapePhantom::setPosition(hkpShapePhantom *this, hkVector4f *position, float extraTolerance)
{
  hkpWorld *m_world; // rax
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  m_world = this->m_world;
  this->m_motionState.m_transform.m_translation = (hkVector4f)position->m_quad;
  if ( m_world )
  {
    ((void (__fastcall *)(hkpShape *, hkMotionState *, hkBaseObjectVtbl *, hkAabb *))this->m_collidable.m_shape->hkpPhantom::hkpWorldObject::vfptr[2].__vecDelDtor)(
      this->m_collidable.m_shape,
      &this->m_motionState,
      this->m_collidable.m_shape->hkpPhantom::hkpWorldObject::vfptr,
      &aabb);
    hkpPhantom::updateBroadPhase(this, &aabb);
  }
}

// File Line: 79
// RVA: 0xD67680
void __fastcall hkpShapePhantom::calcAabb(hkpShapePhantom *this, hkAabb *aabb, __int64 a3)
{
  ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, hkAabb *))this->m_collidable.m_shape->hkpPhantom::hkpWorldObject::vfptr[2].__vecDelDtor)(
    this->m_collidable.m_shape,
    &this->m_motionState,
    a3,
    aabb);
}

// File Line: 88
// RVA: 0xD676D0
// attributes: thunk
void __fastcall hkpShapePhantom::deallocateInternalArrays(hkpShapePhantom *this)
{
  hkpPhantom::deallocateInternalArrays(this);
}

// File Line: 98
// RVA: 0xD67580
__int64 __fastcall hkpShapePhantom::setShape(hkpShapePhantom *this, hkpShape *shape)
{
  hkpWorld *m_world; // rax
  hkpShape *m_shape; // rcx
  hkpWorld *v7; // rcx
  hkpWorld *v8; // rcx
  hkpWorld *v9; // rbx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpShapePhantom *v12; // [rsp+28h] [rbp-20h]
  hkpShape *v13; // [rsp+30h] [rbp-18h]

  m_world = this->m_world;
  if ( m_world )
  {
    if ( m_world->m_criticalOperationsLockCount )
    {
      v13 = shape;
      v12 = this;
      operation.m_type.m_storage = 5;
      hkpWorld::queueOperation(m_world, &operation);
      return 0i64;
    }
    ++m_world->m_criticalOperationsLockCount;
    hkpWorldOperationUtil::removePhantomBP(this->m_world, this);
  }
  hkReferencedObject::addReference(shape);
  m_shape = this->m_collidable.m_shape;
  if ( m_shape )
    hkReferencedObject::removeReference(m_shape);
  v7 = this->m_world;
  this->m_collidable.m_shape = shape;
  if ( v7 )
    hkpWorldCallbackUtil::firePhantomShapeSet(v7, this);
  hkpPhantom::firePhantomShapeSet(this);
  v8 = this->m_world;
  if ( v8 )
  {
    hkpWorldOperationUtil::addPhantomBP(v8, this);
    v9 = this->m_world;
    if ( v9->m_criticalOperationsLockCount-- == 1 && !v9->m_blockExecutingPendingOperations.m_bool )
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

