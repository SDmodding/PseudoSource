// File Line: 25
// RVA: 0xD792E0
void __fastcall hkpConstraintCollisionFilter::hkpConstraintCollisionFilter(
        hkpConstraintCollisionFilter *this,
        hkpCollisionFilter *childFilter)
{
  hkpPairCollisionFilter::hkpPairCollisionFilter(this, childFilter);
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkReferencedObject};
  this->m_type.m_storage = 6;
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintCollisionFilter::`vftable;
}

// File Line: 30
// RVA: 0xD79350
void __fastcall hkpConstraintCollisionFilter::~hkpConstraintCollisionFilter(hkpConstraintCollisionFilter *this)
{
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpPairCollisionFilter::hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable;
  hkpPairCollisionFilter::~hkpPairCollisionFilter(this);
}

// File Line: 39
// RVA: 0xD794E0
void __fastcall hkpConstraintCollisionFilter::init(hkpConstraintCollisionFilter *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // r9
  hkpConstraintListener *v5; // r10
  __int64 m_size; // r11
  int v7; // edx
  __int64 v8; // rcx
  hkpConstraintListener **m_data; // rax

  v2 = 0i64;
  v5 = &this->hkpConstraintListener;
  if ( !this )
    v5 = 0i64;
  m_size = world->m_constraintListeners.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_9;
  m_data = world->m_constraintListeners.m_data;
  while ( *m_data != v5 )
  {
    ++v8;
    ++v7;
    ++m_data;
    if ( v8 >= m_size )
      goto LABEL_9;
  }
  if ( v7 < 0 )
  {
LABEL_9:
    if ( this )
      v2 = &this->hkpConstraintListener;
    hkpWorld::addConstraintListener(world, v2);
  }
}

// File Line: 48
// RVA: 0xD793A0
void __fastcall hkpConstraintCollisionFilter::updateFromWorld(hkpConstraintCollisionFilter *this, hkpWorld *world)
{
  hkpConstraintCollisionFilter *v3; // rdi
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // rax
  __int64 v5; // rdx
  int v6; // ecx
  __int64 v7; // rdx
  int v8; // r15d
  __int64 v9; // r13
  __int64 v10; // r12
  hkpEntity *v11; // rbp
  int v12; // ebx
  int NumConstraints; // r14d
  hkpConstraintListener *v14; // rsi
  hkpConstraintListenerVtbl *vfptr; // rdi
  hkpConstraintInstance *Constraint; // rax
  __int64 v17; // [rsp+20h] [rbp-58h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_inactiveSimulationIslands; // [rsp+28h] [rbp-50h]
  int v20; // [rsp+88h] [rbp+10h]
  __int64 v21; // [rsp+90h] [rbp+18h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v22; // [rsp+98h] [rbp+20h]

  v3 = this;
  hkpPairCollisionFilter::clearAll(this);
  p_m_activeSimulationIslands = &world->m_activeSimulationIslands;
  v5 = 2i64;
  v22 = &world->m_activeSimulationIslands;
  p_m_inactiveSimulationIslands = &world->m_inactiveSimulationIslands;
  v17 = 2i64;
  do
  {
    v6 = 0;
    v20 = 0;
    if ( p_m_activeSimulationIslands->m_size > 0 )
    {
      v7 = 0i64;
      v21 = 0i64;
      do
      {
        v8 = 0;
        v9 = *(__int64 *)((char *)p_m_activeSimulationIslands->m_data + v7);
        if ( *(int *)(v9 + 104) > 0 )
        {
          v10 = 0i64;
          do
          {
            v11 = *(hkpEntity **)(v10 + *(_QWORD *)(v9 + 96));
            v12 = 0;
            NumConstraints = hkpEntity::getNumConstraints(v11);
            if ( NumConstraints > 0 )
            {
              v14 = &v3->hkpConstraintListener;
              do
              {
                vfptr = v14->vfptr;
                Constraint = hkpEntity::getConstraint(v11, v12);
                vfptr->constraintAddedCallback(v14, Constraint);
                ++v12;
              }
              while ( v12 < NumConstraints );
              v3 = this;
            }
            ++v8;
            v10 += 8i64;
          }
          while ( v8 < *(_DWORD *)(v9 + 104) );
          v6 = v20;
          v7 = v21;
        }
        p_m_activeSimulationIslands = v22;
        ++v6;
        v7 += 8i64;
        v20 = v6;
        v21 = v7;
      }
      while ( v6 < v22->m_size );
      v5 = v17;
    }
    p_m_activeSimulationIslands = p_m_inactiveSimulationIslands;
    --v5;
    v22 = p_m_inactiveSimulationIslands;
    v17 = v5;
  }
  while ( v5 );
}

// File Line: 82
// RVA: 0xD79560
void __fastcall hkpConstraintCollisionFilter::constraintAddedCallback(
        hkpConstraintCollisionFilter *this,
        hkpConstraintInstance *constraint)
{
  hkpEntity *v4; // rdi
  hkpEntity *v5; // r8
  hkpAgentNnEntry *Agent; // rax
  hkpWorld *m_world; // rbx

  if ( constraint )
  {
    if ( ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) != 11 )
    {
      v4 = constraint->m_entities[0];
      if ( v4->m_collidable.m_shape )
      {
        v5 = constraint->m_entities[1];
        if ( v5->m_collidable.m_shape )
        {
          if ( (unsigned int)hkpPairCollisionFilter::disableCollisionsBetween(
                               (hkpConstraintCollisionFilter *)((char *)this - 96),
                               constraint->m_entities[0],
                               v5) == 1 )
          {
            Agent = hkAgentNnMachine_FindAgent(
                      &constraint->m_entities[0]->m_collidable,
                      &constraint->m_entities[1]->m_collidable);
            if ( Agent )
            {
              m_world = v4->m_world;
              if ( m_world )
              {
                ++m_world->m_criticalOperationsLockCount;
                hkpWorldAgentUtil::removeAgentAndItsToiEvents(Agent);
                if ( m_world->m_criticalOperationsLockCount-- == 1 && !m_world->m_blockExecutingPendingOperations.m_bool )
                {
                  if ( m_world->m_pendingOperationsCount )
                    hkpWorld::internal_executePendingOperations(m_world);
                  if ( m_world->m_pendingOperationQueueCount == 1 )
                  {
                    if ( m_world->m_pendingBodyOperationsCount )
                      hkpWorld::internal_executePendingBodyOperations(m_world);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 116
// RVA: 0xD79640
void __fastcall hkpConstraintCollisionFilter::constraintRemovedCallback(
        hkpConstraintCollisionFilter *this,
        hkpConstraintInstance *constraint)
{
  hkpEntity *v4; // rdi
  hkpEntity *v5; // rsi
  hkpConstraintListenerVtbl *vfptr; // rcx
  hkpWorld *m_world; // rbx
  char v9; // [rsp+38h] [rbp+10h] BYREF

  if ( constraint )
  {
    if ( ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) != 11 )
    {
      v4 = constraint->m_entities[0];
      if ( v4->m_collidable.m_shape )
      {
        v5 = constraint->m_entities[1];
        if ( v5->m_collidable.m_shape )
        {
          if ( (int)hkpPairCollisionFilter::enableCollisionsBetween(
                      (hkpConstraintCollisionFilter *)((char *)this - 96),
                      v4,
                      constraint->m_entities[1]) <= 0 )
          {
            vfptr = this[-1].hkpConstraintListener::vfptr;
            if ( !vfptr
              || *(_BYTE *)(*((__int64 (__fastcall **)(void (__fastcall **)(hkpConstraintListener *, hkpConstraintInstance *), char *, hkpLinkedCollidable *, hkpLinkedCollidable *))vfptr->constraintRemovedCallback
                            + 1))(
                             &vfptr->constraintRemovedCallback,
                             &v9,
                             &v4->m_collidable,
                             &v5->m_collidable) )
            {
              m_world = v4->m_world;
              if ( m_world )
              {
                ++m_world->m_criticalOperationsLockCount;
                hkpWorld::reenableCollisionBetweenEntityPair(m_world, v4, v5);
                if ( m_world->m_criticalOperationsLockCount-- == 1 && !m_world->m_blockExecutingPendingOperations.m_bool )
                {
                  if ( m_world->m_pendingOperationsCount )
                    hkpWorld::internal_executePendingOperations(m_world);
                  if ( m_world->m_pendingOperationQueueCount == 1 )
                  {
                    if ( m_world->m_pendingBodyOperationsCount )
                      hkpWorld::internal_executePendingBodyOperations(m_world);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 147
// RVA: 0xD79810
void __fastcall hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
        hkpConstraintCollisionFilter *this,
        hkpConstraintInstance *instance,
        hkBool constraintBroken)
{
  hkpConstraintListenerVtbl *vfptr; // rax
  hkpConstraintListener *v4; // rcx

  vfptr = this->hkpConstraintListener::vfptr;
  v4 = &this->hkpConstraintListener;
  if ( constraintBroken.m_bool )
    vfptr->constraintRemovedCallback(v4, instance);
  else
    vfptr->constraintAddedCallback(v4, instance);
}

// File Line: 161
// RVA: 0xD79750
void __fastcall hkpConstraintCollisionFilter::constraintBreakingCallback(
        hkpConstraintCollisionFilter *this,
        hkpConstraintBrokenEvent *event)
{
  hkpWorld *m_world; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int16 *p_m_memSizeAndFlags; // [rsp+28h] [rbp-20h]
  hkpConstraintInstance *m_constraintInstance; // [rsp+30h] [rbp-18h]
  char v7; // [rsp+38h] [rbp-10h]

  m_world = event->m_world;
  if ( event->m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 37;
    v7 = 1;
    p_m_memSizeAndFlags = &this[-1].m_memSizeAndFlags;
    m_constraintInstance = event->m_constraintInstance;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
      (hkpConstraintCollisionFilter *)((char *)this - 96),
      event->m_constraintInstance,
      (hkBool)1);
  }
}

// File Line: 175
// RVA: 0xD797B0
void __fastcall hkpConstraintCollisionFilter::constraintRepairedCallback(
        hkpConstraintCollisionFilter *this,
        hkpConstraintRepairedEvent *event)
{
  hkpWorld *m_world; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int16 *p_m_memSizeAndFlags; // [rsp+28h] [rbp-20h]
  hkpConstraintInstance *m_constraintInstance; // [rsp+30h] [rbp-18h]
  char v7; // [rsp+38h] [rbp-10h]

  m_world = event->m_world;
  if ( event->m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 37;
    v7 = 0;
    p_m_memSizeAndFlags = &this[-1].m_memSizeAndFlags;
    m_constraintInstance = event->m_constraintInstance;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
      (hkpConstraintCollisionFilter *)((char *)this - 96),
      event->m_constraintInstance,
      0);
  }
}

