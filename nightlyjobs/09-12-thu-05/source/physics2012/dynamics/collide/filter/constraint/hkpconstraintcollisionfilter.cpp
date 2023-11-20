// File Line: 25
// RVA: 0xD792E0
void __fastcall hkpConstraintCollisionFilter::hkpConstraintCollisionFilter(hkpConstraintCollisionFilter *this, hkpCollisionFilter *childFilter)
{
  hkpConstraintCollisionFilter *v2; // rbx

  v2 = this;
  hkpPairCollisionFilter::hkpPairCollisionFilter((hkpPairCollisionFilter *)&this->vfptr, childFilter);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkReferencedObject'};
  v2->m_type.m_storage = 6;
  v2->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  v2->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  v2->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  v2->vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  v2->vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintCollisionFilter::`vftable';
}

// File Line: 30
// RVA: 0xD79350
void __fastcall hkpConstraintCollisionFilter::~hkpConstraintCollisionFilter(hkpConstraintCollisionFilter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstraintCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  this->vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable';
  hkpPairCollisionFilter::~hkpPairCollisionFilter((hkpPairCollisionFilter *)&this->vfptr);
}

// File Line: 39
// RVA: 0xD794E0
void __fastcall hkpConstraintCollisionFilter::init(hkpConstraintCollisionFilter *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // r9
  hkpWorld *v3; // rbx
  hkpConstraintCollisionFilter *v4; // r8
  hkpConstraintListener *v5; // r10
  __int64 v6; // r11
  int v7; // edx
  __int64 v8; // rcx
  hkpConstraintListener **v9; // rax

  v2 = 0i64;
  v3 = world;
  v4 = this;
  v5 = (hkpConstraintListener *)&this->vfptr;
  if ( !this )
    v5 = 0i64;
  v6 = world->m_constraintListeners.m_size;
  v7 = 0;
  v8 = 0i64;
  if ( v6 <= 0 )
    goto LABEL_9;
  v9 = v3->m_constraintListeners.m_data;
  while ( *v9 != v5 )
  {
    ++v8;
    ++v7;
    ++v9;
    if ( v8 >= v6 )
      goto LABEL_9;
  }
  if ( v7 < 0 )
  {
LABEL_9:
    if ( v4 )
      v2 = (hkpConstraintListener *)&v4->vfptr;
    hkpWorld::addConstraintListener(v3, v2);
  }
}

// File Line: 48
// RVA: 0xD793A0
void __fastcall hkpConstraintCollisionFilter::updateFromWorld(hkpConstraintCollisionFilter *this, hkpWorld *world)
{
  hkpWorld *v2; // rbx
  hkpConstraintCollisionFilter *v3; // rdi
  signed __int64 v4; // rax
  signed __int64 v5; // rdx
  int v6; // ecx
  __int64 v7; // rdx
  int v8; // er15
  __int64 v9; // r13
  __int64 v10; // r12
  hkpEntity *v11; // rbp
  int v12; // ebx
  int v13; // er14
  hkpConstraintListener *v14; // rsi
  hkpConstraintListenerVtbl *v15; // rdi
  hkpConstraintInstance *v16; // rax
  signed __int64 v17; // [rsp+20h] [rbp-58h]
  signed __int64 v18; // [rsp+28h] [rbp-50h]
  hkpConstraintCollisionFilter *v19; // [rsp+80h] [rbp+8h]
  int v20; // [rsp+88h] [rbp+10h]
  __int64 v21; // [rsp+90h] [rbp+18h]
  signed __int64 v22; // [rsp+98h] [rbp+20h]

  v19 = this;
  v2 = world;
  v3 = this;
  hkpPairCollisionFilter::clearAll((hkpPairCollisionFilter *)&this->vfptr);
  v4 = (signed __int64)&v2->m_activeSimulationIslands;
  v5 = 2i64;
  v22 = (signed __int64)&v2->m_activeSimulationIslands;
  v18 = (signed __int64)&v2->m_inactiveSimulationIslands;
  v17 = 2i64;
  do
  {
    v6 = 0;
    v20 = 0;
    if ( *(_DWORD *)(v4 + 8) > 0 )
    {
      v7 = 0i64;
      v21 = 0i64;
      do
      {
        v8 = 0;
        v9 = *(_QWORD *)(v7 + *(_QWORD *)v4);
        if ( *(_DWORD *)(v9 + 104) > 0 )
        {
          v10 = 0i64;
          do
          {
            v11 = *(hkpEntity **)(v10 + *(_QWORD *)(v9 + 96));
            v12 = 0;
            v13 = hkpEntity::getNumConstraints(v11);
            if ( v13 > 0 )
            {
              v14 = (hkpConstraintListener *)&v3->vfptr;
              do
              {
                v15 = v14->vfptr;
                v16 = hkpEntity::getConstraint(v11, v12);
                v15->constraintAddedCallback(v14, v16);
                ++v12;
              }
              while ( v12 < v13 );
              v3 = v19;
            }
            ++v8;
            v10 += 8i64;
          }
          while ( v8 < *(_DWORD *)(v9 + 104) );
          v6 = v20;
          v7 = v21;
        }
        v4 = v22;
        ++v6;
        v7 += 8i64;
        v20 = v6;
        v21 = v7;
      }
      while ( v6 < *(_DWORD *)(v22 + 8) );
      v5 = v17;
    }
    v4 = v18;
    --v5;
    v22 = v18;
    v17 = v5;
  }
  while ( v5 );
}

// File Line: 82
// RVA: 0xD79560
void __fastcall hkpConstraintCollisionFilter::constraintAddedCallback(hkpConstraintCollisionFilter *this, hkpConstraintInstance *constraint)
{
  hkpConstraintCollisionFilter *v2; // rsi
  hkpConstraintInstance *v3; // rbx
  hkpEntity *v4; // rdi
  hkpEntity *v5; // r8
  hkpAgentNnEntry *v6; // rax
  hkpWorld *v7; // rbx
  bool v8; // zf

  if ( constraint )
  {
    v2 = this;
    v3 = constraint;
    if ( ((unsigned int (*)(void))constraint->m_data->vfptr[1].__first_virtual_table_function__)() != 11 )
    {
      v4 = v3->m_entities[0];
      if ( v4->m_collidable.m_shape )
      {
        v5 = v3->m_entities[1];
        if ( v5->m_collidable.m_shape )
        {
          if ( (unsigned int)hkpPairCollisionFilter::disableCollisionsBetween(
                               (hkpPairCollisionFilter *)&v2[-1].m_memSizeAndFlags,
                               v3->m_entities[0],
                               v5) == 1 )
          {
            v6 = hkAgentNnMachine_FindAgent(&v3->m_entities[0]->m_collidable, &v3->m_entities[1]->m_collidable);
            if ( v6 )
            {
              v7 = v4->m_world;
              if ( v7 )
              {
                ++v7->m_criticalOperationsLockCount;
                hkpWorldAgentUtil::removeAgentAndItsToiEvents(v6);
                v8 = v7->m_criticalOperationsLockCount-- == 1;
                if ( v8 && !v7->m_blockExecutingPendingOperations.m_bool )
                {
                  if ( v7->m_pendingOperationsCount )
                    hkpWorld::internal_executePendingOperations(v7);
                  if ( v7->m_pendingOperationQueueCount == 1 )
                  {
                    if ( v7->m_pendingBodyOperationsCount )
                      hkpWorld::internal_executePendingBodyOperations(v7);
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
void __fastcall hkpConstraintCollisionFilter::constraintRemovedCallback(hkpConstraintCollisionFilter *this, hkpConstraintInstance *constraint)
{
  hkpConstraintCollisionFilter *v2; // rbp
  hkpConstraintInstance *v3; // rbx
  hkpEntity *v4; // rdi
  hkpEntity *v5; // rsi
  hkpConstraintListenerVtbl *v6; // rcx
  hkpWorld *v7; // rbx
  bool v8; // zf
  char v9; // [rsp+38h] [rbp+10h]

  if ( constraint )
  {
    v2 = this;
    v3 = constraint;
    if ( ((unsigned int (*)(void))constraint->m_data->vfptr[1].__first_virtual_table_function__)() != 11 )
    {
      v4 = v3->m_entities[0];
      if ( v4->m_collidable.m_shape )
      {
        v5 = v3->m_entities[1];
        if ( v5->m_collidable.m_shape )
        {
          if ( (signed int)hkpPairCollisionFilter::enableCollisionsBetween(
                             (hkpPairCollisionFilter *)&v2[-1].m_memSizeAndFlags,
                             v4,
                             v3->m_entities[1]) <= 0 )
          {
            v6 = v2[-1].vfptr;
            if ( !v6
              || *(_BYTE *)(*((__int64 (__fastcall **)(void (__fastcall **)(hkpConstraintListener *, hkpConstraintInstance *), char *, hkpLinkedCollidable *, hkpLinkedCollidable *))v6->constraintRemovedCallback
                            + 1))(
                             &v6->constraintRemovedCallback,
                             &v9,
                             &v4->m_collidable,
                             &v5->m_collidable) )
            {
              v7 = v4->m_world;
              if ( v7 )
              {
                ++v7->m_criticalOperationsLockCount;
                hkpWorld::reenableCollisionBetweenEntityPair(v7, v4, v5);
                v8 = v7->m_criticalOperationsLockCount-- == 1;
                if ( v8 && !v7->m_blockExecutingPendingOperations.m_bool )
                {
                  if ( v7->m_pendingOperationsCount )
                    hkpWorld::internal_executePendingOperations(v7);
                  if ( v7->m_pendingOperationQueueCount == 1 )
                  {
                    if ( v7->m_pendingBodyOperationsCount )
                      hkpWorld::internal_executePendingBodyOperations(v7);
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
void __fastcall hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(hkpConstraintCollisionFilter *this, hkpConstraintInstance *instance, hkBool constraintBroken)
{
  hkpConstraintListenerVtbl *v3; // rax
  hkpConstraintListener *v4; // rcx

  v3 = this->vfptr;
  v4 = (hkpConstraintListener *)&this->vfptr;
  if ( constraintBroken.m_bool )
    v3->constraintRemovedCallback(v4, instance);
  else
    v3->constraintAddedCallback(v4, instance);
}

// File Line: 161
// RVA: 0xD79750
void __fastcall hkpConstraintCollisionFilter::constraintBreakingCallback(hkpConstraintCollisionFilter *this, hkpConstraintBrokenEvent *event)
{
  hkpConstraintCollisionFilter *v2; // rax
  hkpWorld *v3; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  unsigned __int16 *v5; // [rsp+28h] [rbp-20h]
  hkpConstraintInstance *v6; // [rsp+30h] [rbp-18h]
  char v7; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = event->m_world;
  if ( event->m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 37;
    v7 = 1;
    v5 = &v2[-1].m_memSizeAndFlags;
    v6 = event->m_constraintInstance;
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
      (hkpConstraintCollisionFilter *)((char *)v2 - 96),
      event->m_constraintInstance,
      (hkBool)1);
  }
}

// File Line: 175
// RVA: 0xD797B0
void __fastcall hkpConstraintCollisionFilter::constraintRepairedCallback(hkpConstraintCollisionFilter *this, hkpConstraintRepairedEvent *event)
{
  hkpConstraintCollisionFilter *v2; // rax
  hkpWorld *v3; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  unsigned __int16 *v5; // [rsp+28h] [rbp-20h]
  hkpConstraintInstance *v6; // [rsp+30h] [rbp-18h]
  char v7; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = event->m_world;
  if ( event->m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 37;
    v7 = 0;
    v5 = &v2[-1].m_memSizeAndFlags;
    v6 = event->m_constraintInstance;
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
      (hkpConstraintCollisionFilter *)((char *)v2 - 96),
      event->m_constraintInstance,
      0);
  }
}

