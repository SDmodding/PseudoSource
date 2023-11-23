// File Line: 18
// RVA: 0xD75DB0
void __fastcall hkpConstraintChainInstance::hkpConstraintChainInstance(
        hkpConstraintChainInstance *this,
        hkpConstraintChainData *data)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkpConstraintChainInstanceAction *v6; // rbx

  hkpConstraintInstance::hkpConstraintInstance(this, PRIORITY_PSI);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstance::`vftable;
  this->m_chainedEntities.m_data = 0i64;
  this->m_chainedEntities.m_size = 0;
  this->m_chainedEntities.m_capacityAndFlags = 0x80000000;
  this->m_data = data;
  hkReferencedObject::addReference(data);
  this->m_entities[0] = 0i64;
  this->m_entities[1] = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v6 = (hkpConstraintChainInstanceAction *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 24) = 0i64;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_QWORD *)v5 = &hkpAction::`vftable;
    hkStringPtr::hkStringPtr((hkStringPtr *)(v5 + 40));
    v6->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstanceAction::`vftable;
    v6->m_constraintInstance = this;
  }
  else
  {
    v6 = 0i64;
  }
  this->m_action = v6;
  this->m_chainConnectedness = 0i64;
}

// File Line: 34
// RVA: 0xD75FC0
void __fastcall hkpConstraintChainInstance::addEntity(hkpConstraintChainInstance *this, hkpEntity *entity)
{
  __int64 m_size; // rax

  m_size = this->m_chainedEntities.m_size;
  if ( (int)m_size < 2 && !this->m_entities[m_size] )
  {
    this->m_entities[m_size] = entity;
    hkReferencedObject::addReference(entity);
  }
  if ( this->m_chainedEntities.m_size == (this->m_chainedEntities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_chainedEntities.m_data, 8);
  this->m_chainedEntities.m_data[this->m_chainedEntities.m_size++] = entity;
  hkReferencedObject::addReference(entity);
}

// File Line: 53
// RVA: 0xD75E90
void __fastcall hkpConstraintChainInstance::~hkpConstraintChainInstance(hkpConstraintChainInstance *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintChainInstance::`vftable;
  if ( this->m_chainedEntities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_chainedEntities.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_chainedEntities.m_size );
  }
  hkReferencedObject::removeReference(this->m_action);
  m_capacityAndFlags = this->m_chainedEntities.m_capacityAndFlags;
  this->m_chainedEntities.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_chainedEntities.m_data,
      8 * m_capacityAndFlags);
  this->m_chainedEntities.m_data = 0i64;
  this->m_chainedEntities.m_capacityAndFlags = 0x80000000;
  hkpConstraintInstance::~hkpConstraintInstance(this);
}

// File Line: 64
// RVA: 0xD75F40
void __fastcall hkpConstraintChainInstance::entityRemovedCallback(hkpConstraintChainInstance *this, hkpEntity *entity)
{
  hkpWorld *m_world; // rdi
  bool v4; // zf

  m_world = entity->m_world;
  ++m_world->m_criticalOperationsLockCount;
  hkpWorld::removeActionImmediately(m_world, this->m_action);
  hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(m_world, this);
  v4 = m_world->m_criticalOperationsLockCount-- == 1;
  if ( v4 && !m_world->m_blockExecutingPendingOperations.m_bool )
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

