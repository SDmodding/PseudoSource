// File Line: 73
// RVA: 0x15D21E0
void dynamic_initializer_for__hkpSimulationIslandClass__()
{
  hkClass::hkClass(
    &hkpSimulationIslandClass,
    "hkpSimulationIsland",
    &hkReferencedObjectClass,
    184,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 90
// RVA: 0xD82720
void __fastcall hkpSimulationIsland::hkpSimulationIsland(hkpSimulationIsland *this, hkpWorld *world)
{
  *((_BYTE *)this + 49) &= 0xCCu;
  this->m_world = world;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *((_BYTE *)this + 50) = 5;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulationIsland::`vftable;
  this->m_dirtyListIndex = -1;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  *(_QWORD *)&this->m_timeSinceLastHighFrequencyCheck = 0i64;
  this->m_actions.m_data = 0i64;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacityAndFlags = 0x80000000;
  this->m_timeOfDeactivation = -10.0;
  this->m_entities.m_size = 0;
  this->m_entities.m_capacityAndFlags = -2147483647;
  this->m_entities.m_data = this->m_entities.m_storage;
  this->m_midphaseAgentTrack.m_sectors.m_size = 0;
  this->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags = -2147483647;
  this->m_midphaseAgentTrack.m_sectors.m_data = this->m_midphaseAgentTrack.m_sectors.m_storage;
  this->m_midphaseAgentTrack.m_bytesUsedInLastSector = 960;
  this->m_midphaseAgentTrack.m_nnTrackType.m_storage = 1;
  this->m_narrowphaseAgentTrack.m_sectors.m_size = 0;
  this->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags = -2147483647;
  this->m_narrowphaseAgentTrack.m_sectors.m_data = this->m_narrowphaseAgentTrack.m_sectors.m_storage;
  this->m_narrowphaseAgentTrack.m_bytesUsedInLastSector = 960;
  this->m_narrowphaseAgentTrack.m_nnTrackType.m_storage = 2;
  *((_BYTE *)this + 49) &= 0x3Fu;
  *(_QWORD *)&this->m_constraintInfo.m_maxSizeOfSchema = 0i64;
  *(_QWORD *)&this->m_constraintInfo.m_numSolverResults = 0i64;
  *((_BYTE *)this + 49) &= 0xF3u;
  this->m_numConstraints = 0;
}

// File Line: 105
// RVA: 0xD82800
void __fastcall hkpSimulationIsland::~hkpSimulationIsland(hkpSimulationIsland *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulationIsland::`vftable;
  m_capacityAndFlags = this->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags;
  this->m_narrowphaseAgentTrack.m_sectors.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_narrowphaseAgentTrack.m_sectors.m_data,
      8 * m_capacityAndFlags);
  this->m_narrowphaseAgentTrack.m_sectors.m_data = 0i64;
  this->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags = 0x80000000;
  v3 = this->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags;
  this->m_midphaseAgentTrack.m_sectors.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_midphaseAgentTrack.m_sectors.m_data,
      8 * v3);
  this->m_midphaseAgentTrack.m_sectors.m_data = 0i64;
  this->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags = 0x80000000;
  v4 = this->m_entities.m_capacityAndFlags;
  this->m_entities.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_entities.m_data,
      8 * v4);
  this->m_entities.m_data = 0i64;
  this->m_entities.m_capacityAndFlags = 0x80000000;
  v5 = this->m_actions.m_capacityAndFlags;
  this->m_actions.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_actions.m_data, 8 * v5);
  this->m_actions.m_data = 0i64;
  this->m_actions.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 117
// RVA: 0xD82930
void __fastcall hkpSimulationIsland::internalAddEntity(hkpSimulationIsland *this, hkpEntity *entity)
{
  hkInplaceArray<hkpEntity *,1,hkContainerHeapAllocator> *p_m_entities; // rbx

  entity->m_simulationIsland = this;
  p_m_entities = &this->m_entities;
  entity->m_storageIndex = this->m_entities.m_size;
  if ( this->m_entities.m_size == (this->m_entities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_entities->m_data, 8);
  p_m_entities->m_data[p_m_entities->m_size++] = entity;
}

// File Line: 129
// RVA: 0xD829A0
void __fastcall hkpSimulationIsland::internalRemoveEntity(hkpSimulationIsland *this, hkpEntity *entity)
{
  this->m_entities.m_data[entity->m_storageIndex] = this->m_entities.m_data[this->m_entities.m_size - 1];
  this->m_entities.m_data[entity->m_storageIndex]->m_storageIndex = entity->m_storageIndex;
  --this->m_entities.m_size;
  entity->m_simulationIsland = 0i64;
  entity->m_storageIndex = -1;
  *((_BYTE *)this + 49) &= ~2u;
  *((_BYTE *)this + 49) |= 1u;
}

// File Line: 157
// RVA: 0xD82A50
void __fastcall hkpSimulationIsland::addAction(hkpSimulationIsland *this, hkpAction *act)
{
  if ( this->m_actions.m_size == (this->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_actions.m_data, 8);
  this->m_actions.m_data[this->m_actions.m_size++] = act;
  act->m_island = this;
}

// File Line: 167
// RVA: 0xD82AC0
void __fastcall hkpSimulationIsland::removeAction(hkpSimulationIsland *this, hkpAction *act)
{
  __int64 m_size; // rcx
  int v4; // r9d
  __int64 v5; // r8
  hkpAction **m_data; // rax

  m_size = this->m_actions.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v4 = -1;
  }
  else
  {
    m_data = this->m_actions.m_data;
    while ( *m_data != act )
    {
      ++v5;
      ++v4;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_actions.m_data[v4] = 0i64;
  act->m_island = 0i64;
  *((_BYTE *)this + 49) &= 0xDDu;
  *((_BYTE *)this + 49) |= 0x11u;
}

// File Line: 182
// RVA: 0xD82620
_BOOL8 __fastcall hkpSimulationIsland::isFullyConnected(hkpSimulationIsland *this)
{
  int m_size; // edi
  hkLifoAllocator *Value; // rax
  int *m_cur; // r9
  int v5; // edx
  char *v6; // r8
  int v7; // r8d
  bool isFullyConnected; // al
  int *m_storage; // rdi
  bool v10; // si
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // r8d
  hkFixedArray<int> parents; // [rsp+20h] [rbp-38h] BYREF
  hkUnionFind checkConnectivityOut; // [rsp+30h] [rbp-28h] BYREF

  m_size = this->m_entities.m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v5 = (4 * m_size + 127) & 0xFFFFFF80;
  v6 = (char *)m_cur + v5;
  if ( v5 > Value->m_slabSize || v6 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v5);
  else
    Value->m_cur = v6;
  v7 = this->m_entities.m_size;
  parents.m_data.m_storage = m_cur;
  parents.m_size.m_storage = m_size;
  hkUnionFind::hkUnionFind(&checkConnectivityOut, &parents, v7);
  isFullyConnected = hkpSimulationIsland::isFullyConnected(this, &checkConnectivityOut);
  m_storage = parents.m_data.m_storage;
  v10 = isFullyConnected;
  v11 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || (char *)m_storage + v13 != v12->m_cur || v12->m_firstNonLifoEnd == m_storage )
  {
    hkLifoAllocator::slowBlockFree(v12, (char *)m_storage, v13);
    return v10;
  }
  else
  {
    v12->m_cur = m_storage;
    return v10;
  }
}

// File Line: 195
// RVA: 0xD82B20
bool __fastcall hkpSimulationIsland::isFullyConnected(hkpSimulationIsland *this, hkUnionFind *checkConnectivityOut)
{
  int v4; // ebp
  __int64 v5; // r15
  int v6; // ebx
  hkpEntity *v7; // rsi
  __int64 v8; // rdi
  hkpLinkedCollidable *m_partner; // rcx
  char *v10; // rax
  int v11; // ebp
  __int64 v12; // r15
  int v13; // edi
  hkpEntity *v14; // rsi
  __int64 v15; // rbx
  hkConstraintInternal *m_data; // rax
  hkpEntity *v17; // rdx
  hkpEntity *v18; // rcx
  char *v19; // rdx
  int v20; // r8d
  int v21; // ebp
  __int64 v22; // r15
  hkpAction **v23; // rax
  int v24; // ecx
  int v25; // ebx
  __int64 v26; // rsi
  __int64 v27; // rdi
  __int64 v28; // rsi
  __int64 v29; // rax
  char *v31; // [rsp+20h] [rbp-88h] BYREF
  int v32; // [rsp+28h] [rbp-80h]
  int v33; // [rsp+2Ch] [rbp-7Ch]
  char v34[80]; // [rsp+30h] [rbp-78h] BYREF

  checkConnectivityOut->m_isCollapsed = 0;
  v4 = 0;
  if ( this->m_entities.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0;
      v7 = this->m_entities.m_data[v5];
      if ( v7->m_collidable.m_collisionEntries.m_size > 0 )
      {
        v8 = 0i64;
        do
        {
          m_partner = v7->m_collidable.m_collisionEntries.m_data[v8].m_partner;
          v10 = (char *)m_partner + m_partner->m_ownerOffset;
          if ( v10[352] != 5 )
          {
            hkUnionFind::addEdge(checkConnectivityOut, v4, *((unsigned __int16 *)v10 + 122));
            if ( *checkConnectivityOut->m_parents->m_data.m_storage == -checkConnectivityOut->m_numNodes )
              return 1;
          }
          ++v6;
          ++v8;
        }
        while ( v6 < v7->m_collidable.m_collisionEntries.m_size );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_entities.m_size );
  }
  v11 = 0;
  if ( this->m_entities.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = 0;
      v14 = this->m_entities.m_data[v12];
      if ( v14->m_constraintsMaster.m_size )
      {
        v15 = 0i64;
        do
        {
          m_data = v14->m_constraintsMaster.m_data;
          v17 = m_data[v15].m_entities[0];
          if ( v17->m_motion.m_type.m_storage != 5 )
          {
            v18 = m_data[v15].m_entities[1];
            if ( v18->m_motion.m_type.m_storage != 5 )
            {
              hkUnionFind::addEdge(checkConnectivityOut, v17->m_storageIndex, v18->m_storageIndex);
              if ( *checkConnectivityOut->m_parents->m_data.m_storage == -checkConnectivityOut->m_numNodes )
                return 1;
            }
          }
          ++v13;
          ++v15;
        }
        while ( v13 < v14->m_constraintsMaster.m_size );
      }
      ++v11;
      ++v12;
    }
    while ( v11 < this->m_entities.m_size );
  }
  v19 = v34;
  v20 = -2147483638;
  v32 = 0;
  v21 = 0;
  v31 = v34;
  v33 = -2147483638;
  if ( this->m_actions.m_size <= 0 )
    goto LABEL_34;
  v22 = 0i64;
  while ( 1 )
  {
    v23 = this->m_actions.m_data;
    if ( v23[v22] )
    {
      v32 = 0;
      v23[v22]->vfptr[2].__vecDelDtor(v23[v22], (unsigned int)&v31);
      v24 = v32;
      v19 = v31;
      v25 = 0;
      v26 = 0i64;
      v27 = -1i64;
      do
      {
        if ( v25 >= v32 )
          goto LABEL_32;
        if ( *(_BYTE *)(*(_QWORD *)&v31[8 * v26] + 352i64) != 5 )
          v27 = v26;
        ++v25;
        ++v26;
      }
      while ( v27 == -1 );
      if ( v25 < v32 )
        break;
    }
LABEL_32:
    ++v21;
    ++v22;
    if ( v21 >= this->m_actions.m_size )
    {
      v20 = v33;
LABEL_34:
      v32 = 0;
      if ( v20 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v19, 8 * v20);
      return *checkConnectivityOut->m_parents->m_data.m_storage == -checkConnectivityOut->m_numNodes;
    }
  }
  v28 = 8 * v26;
  while ( 1 )
  {
    v29 = *(_QWORD *)&v19[v28];
    if ( *(_BYTE *)(v29 + 352) != 5 )
      break;
LABEL_31:
    ++v25;
    v28 += 8i64;
    if ( v25 >= v24 )
      goto LABEL_32;
  }
  hkUnionFind::addEdge(
    checkConnectivityOut,
    *(unsigned __int16 *)(*(_QWORD *)&v19[8 * v27] + 244i64),
    *(unsigned __int16 *)(v29 + 244));
  if ( *checkConnectivityOut->m_parents->m_data.m_storage != -checkConnectivityOut->m_numNodes )
  {
    v24 = v32;
    v19 = v31;
    goto LABEL_31;
  }
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v31, 8 * v33);
  return 1;
}

// File Line: 366
// RVA: 0xD82E20
void __fastcall hkpSimulationIsland::isValid(hkpSimulationIsland *this)
{
  ;
}

// File Line: 589
// RVA: 0xD82A00
void __fastcall hkpSimulationIsland::addConstraintToCriticalLockedIsland(
        hkpSimulationIsland *this,
        hkpConstraintInstance *constraint)
{
  hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(constraint->m_entities[0]->m_world, constraint);
}

// File Line: 594
// RVA: 0xD82A20
void __fastcall hkpSimulationIsland::removeConstraintFromCriticalLockedIsland(
        hkpSimulationIsland *this,
        hkpConstraintInstance *constraint)
{
  hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(constraint->m_entities[0]->m_world, constraint);
}

// File Line: 599
// RVA: 0xD82A40
void __fastcall hkpSimulationIsland::addCallbackRequest(
        hkpSimulationIsland *this,
        hkpConstraintInstance *constraint,
        char request)
{
  constraint->m_internal->m_callbackRequest |= request;
}

// File Line: 607
// RVA: 0xD82E30
void __fastcall hkpSimulationIsland::mergeConstraintInfo(hkpSimulationIsland *this, hkpSimulationIsland *other)
{
  int m_maxSizeOfSchema; // r8d

  m_maxSizeOfSchema = other->m_constraintInfo.m_maxSizeOfSchema;
  if ( this->m_constraintInfo.m_maxSizeOfSchema > m_maxSizeOfSchema )
    m_maxSizeOfSchema = this->m_constraintInfo.m_maxSizeOfSchema;
  this->m_constraintInfo.m_maxSizeOfSchema = m_maxSizeOfSchema;
  this->m_constraintInfo.m_sizeOfSchemas += other->m_constraintInfo.m_sizeOfSchemas;
  this->m_constraintInfo.m_numSolverResults += other->m_constraintInfo.m_numSolverResults;
  this->m_constraintInfo.m_numSolverElemTemps += other->m_constraintInfo.m_numSolverElemTemps;
}

// File Line: 612
// RVA: 0xD82E10
void __fastcall hkpSimulationIsland::markForWrite(hkpSimulationIsland *this)
{
  ;
}

