// File Line: 18
// RVA: 0xD75DB0
void __fastcall hkpConstraintChainInstance::hkpConstraintChainInstance(hkpConstraintChainInstance *this, hkpConstraintChainData *data)
{
  hkpConstraintChainData *v2; // rbx
  hkpConstraintChainInstance *v3; // rdi
  _QWORD **v4; // rax
  __int64 v5; // rax
  hkpConstraintChainInstanceAction *v6; // rbx

  v2 = data;
  v3 = this;
  hkpConstraintInstance::hkpConstraintInstance((hkpConstraintInstance *)&this->vfptr, PRIORITY_PSI);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstance::`vftable';
  v3->m_chainedEntities.m_data = 0i64;
  v3->m_chainedEntities.m_size = 0;
  v3->m_chainedEntities.m_capacityAndFlags = 2147483648;
  v3->m_data = (hkpConstraintData *)&v2->vfptr;
  hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v3->m_entities[0] = 0i64;
  v3->m_entities[1] = 0i64;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 56i64);
  v6 = (hkpConstraintChainInstanceAction *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 24) = 0i64;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_QWORD *)v5 = &hkpAction::`vftable';
    hkStringPtr::hkStringPtr((hkStringPtr *)(v5 + 40));
    v6->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstanceAction::`vftable';
    v6->m_constraintInstance = v3;
  }
  else
  {
    v6 = 0i64;
  }
  v3->m_action = v6;
  v3->m_chainConnectedness = 0i64;
}

// File Line: 34
// RVA: 0xD75FC0
void __fastcall hkpConstraintChainInstance::addEntity(hkpConstraintChainInstance *this, hkpEntity *entity)
{
  __int64 v2; // rax
  hkpEntity *v3; // rdi
  hkpConstraintChainInstance *v4; // rbx

  v2 = this->m_chainedEntities.m_size;
  v3 = entity;
  v4 = this;
  if ( (signed int)v2 < 2 && !this->m_entities[v2] )
  {
    this->m_entities[v2] = entity;
    hkReferencedObject::addReference((hkReferencedObject *)&entity->vfptr);
  }
  if ( v4->m_chainedEntities.m_size == (v4->m_chainedEntities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_chainedEntities, 8);
  v4->m_chainedEntities.m_data[v4->m_chainedEntities.m_size++] = v3;
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 53
// RVA: 0xD75E90
void __fastcall hkpConstraintChainInstance::~hkpConstraintChainInstance(hkpConstraintChainInstance *this)
{
  int v1; // esi
  hkpConstraintChainInstance *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstance::`vftable';
  v2 = this;
  if ( this->m_chainedEntities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_chainedEntities.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_chainedEntities.m_size );
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_action->vfptr);
  v4 = v2->m_chainedEntities.m_capacityAndFlags;
  v2->m_chainedEntities.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_chainedEntities.m_data,
      8 * v4);
  v2->m_chainedEntities.m_data = 0i64;
  v2->m_chainedEntities.m_capacityAndFlags = 2147483648;
  hkpConstraintInstance::~hkpConstraintInstance((hkpConstraintInstance *)&v2->vfptr);
}

// File Line: 64
// RVA: 0xD75F40
void __fastcall hkpConstraintChainInstance::entityRemovedCallback(hkpConstraintChainInstance *this, hkpEntity *entity)
{
  hkpWorld *v2; // rdi
  hkpConstraintChainInstance *v3; // rbx
  bool v4; // zf

  v2 = entity->m_world;
  v3 = this;
  ++v2->m_criticalOperationsLockCount;
  hkpWorld::removeActionImmediately(v2, (hkpAction *)&this->m_action->vfptr);
  hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(v2, (hkpConstraintInstance *)&v3->vfptr);
  v4 = v2->m_criticalOperationsLockCount-- == 1;
  if ( v4 && !v2->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v2->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v2);
    if ( v2->m_pendingOperationQueueCount == 1 )
    {
      if ( v2->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v2);
    }
  }
}

