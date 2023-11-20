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
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulationIsland::`vftable';
  this->m_dirtyListIndex = -1;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = -32768;
  *(_QWORD *)&this->m_timeSinceLastHighFrequencyCheck = 0i64;
  this->m_actions.m_data = 0i64;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacityAndFlags = 2147483648;
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
  hkpSimulationIsland *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulationIsland::`vftable';
  v2 = this->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags;
  this->m_narrowphaseAgentTrack.m_sectors.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_narrowphaseAgentTrack.m_sectors.m_data,
      8 * v2);
  v1->m_narrowphaseAgentTrack.m_sectors.m_data = 0i64;
  v1->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags = 2147483648;
  v3 = v1->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags;
  v1->m_midphaseAgentTrack.m_sectors.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_midphaseAgentTrack.m_sectors.m_data,
      8 * v3);
  v1->m_midphaseAgentTrack.m_sectors.m_data = 0i64;
  v1->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags = 2147483648;
  v4 = v1->m_entities.m_capacityAndFlags;
  v1->m_entities.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_entities.m_data,
      8 * v4);
  v1->m_entities.m_data = 0i64;
  v1->m_entities.m_capacityAndFlags = 2147483648;
  v5 = v1->m_actions.m_capacityAndFlags;
  v1->m_actions.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_actions.m_data,
      8 * v5);
  v1->m_actions.m_data = 0i64;
  v1->m_actions.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 117
// RVA: 0xD82930
void __fastcall hkpSimulationIsland::internalAddEntity(hkpSimulationIsland *this, hkpEntity *entity)
{
  hkInplaceArray<hkpEntity *,1,hkContainerHeapAllocator> *v2; // rbx
  hkpEntity *v3; // rdi

  entity->m_simulationIsland = this;
  v2 = &this->m_entities;
  entity->m_storageIndex = this->m_entities.m_size;
  v3 = entity;
  if ( this->m_entities.m_size == (this->m_entities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
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
  *((_BYTE *)this + 49) &= 0xFDu;
  *((_BYTE *)this + 49) |= 1u;
}

// File Line: 157
// RVA: 0xD82A50
void __fastcall hkpSimulationIsland::addAction(hkpSimulationIsland *this, hkpAction *act)
{
  hkpAction *v2; // rdi
  hkpSimulationIsland *v3; // rsi

  v2 = act;
  v3 = this;
  if ( this->m_actions.m_size == (this->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_actions, 8);
  v3->m_actions.m_data[v3->m_actions.m_size++] = v2;
  v2->m_island = v3;
}

// File Line: 167
// RVA: 0xD82AC0
void __fastcall hkpSimulationIsland::removeAction(hkpSimulationIsland *this, hkpAction *act)
{
  hkpSimulationIsland *v2; // r10
  __int64 v3; // rcx
  signed int v4; // er9
  __int64 v5; // r8
  hkpAction **v6; // rax

  v2 = this;
  v3 = this->m_actions.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_5:
    v4 = -1;
  }
  else
  {
    v6 = v2->m_actions.m_data;
    while ( *v6 != act )
    {
      ++v5;
      ++v4;
      ++v6;
      if ( v5 >= v3 )
        goto LABEL_5;
    }
  }
  v2->m_actions.m_data[v4] = 0i64;
  act->m_island = 0i64;
  *((_BYTE *)v2 + 49) &= 0xDDu;
  *((_BYTE *)v2 + 49) |= 0x11u;
}

// File Line: 182
// RVA: 0xD82620
_BOOL8 __fastcall hkpSimulationIsland::isFullyConnected(hkpSimulationIsland *this)
{
  int v1; // edi
  hkpSimulationIsland *v2; // rbx
  hkLifoAllocator *v3; // rax
  int *v4; // r9
  int v5; // edx
  char *v6; // r8
  int v7; // er8
  bool v8; // al
  int *v9; // rdi
  bool v10; // si
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // er8
  _BOOL8 result; // rax
  hkFixedArray<int> parents; // [rsp+20h] [rbp-38h]
  hkUnionFind checkConnectivityOut; // [rsp+30h] [rbp-28h]

  v1 = this->m_entities.m_size;
  v2 = this;
  v3 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (int *)v3->m_cur;
  v5 = (4 * v1 + 127) & 0xFFFFFF80;
  v6 = (char *)v4 + v5;
  if ( v5 > v3->m_slabSize || v6 > v3->m_end )
    v4 = (int *)hkLifoAllocator::allocateFromNewSlab(v3, v5);
  else
    v3->m_cur = v6;
  v7 = v2->m_entities.m_size;
  parents.m_data.m_storage = v4;
  parents.m_size.m_storage = v1;
  hkUnionFind::hkUnionFind(&checkConnectivityOut, &parents, v7);
  v8 = hkpSimulationIsland::isFullyConnected(v2, &checkConnectivityOut);
  v9 = parents.m_data.m_storage;
  v10 = v8;
  v11 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || (char *)v9 + v13 != v12->m_cur || v12->m_firstNonLifoEnd == v9 )
  {
    hkLifoAllocator::slowBlockFree(v12, v9, v13);
    result = v10;
  }
  else
  {
    v12->m_cur = v9;
    result = v10;
  }
  return result;
}

// File Line: 195
// RVA: 0xD82B20
bool __fastcall hkpSimulationIsland::isFullyConnected(hkpSimulationIsland *this, hkUnionFind *checkConnectivityOut)
{
  hkUnionFind *v2; // r14
  hkpSimulationIsland *v3; // r13
  int v4; // ebp
  __int64 v5; // r15
  int v6; // ebx
  hkpEntity *v7; // rsi
  __int64 v8; // rdi
  hkpLinkedCollidable *v9; // rcx
  hkpLinkedCollidable *v10; // rax
  int v11; // ebp
  __int64 v12; // r15
  signed int v13; // edi
  hkpEntity *v14; // rsi
  __int64 v15; // rbx
  hkConstraintInternal *v16; // rax
  hkpEntity *v17; // rdx
  hkpEntity *v18; // rcx
  char *v19; // rdx
  signed int v20; // er8
  int v21; // ebp
  __int64 v22; // r15
  hkpAction **v23; // rax
  int v24; // ecx
  int v25; // ebx
  signed __int64 v26; // rsi
  signed __int64 v27; // rdi
  signed __int64 v28; // rsi
  __int64 v29; // rax
  char *v31; // [rsp+20h] [rbp-88h]
  int v32; // [rsp+28h] [rbp-80h]
  int v33; // [rsp+2Ch] [rbp-7Ch]
  char v34; // [rsp+30h] [rbp-78h]

  v2 = checkConnectivityOut;
  v3 = this;
  checkConnectivityOut->m_isCollapsed = 0;
  v4 = 0;
  if ( this->m_entities.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0;
      v7 = v3->m_entities.m_data[v5];
      if ( v7->m_collidable.m_collisionEntries.m_size > 0 )
      {
        v8 = 0i64;
        do
        {
          v9 = v7->m_collidable.m_collisionEntries.m_data[v8].m_partner;
          v10 = (hkpLinkedCollidable *)((char *)v9 + v9->m_ownerOffset);
          if ( LOBYTE(v10[2].m_boundingVolumeData.m_childShapeKeys) != 5 )
          {
            hkUnionFind::addEdge(v2, v4, WORD2(v10[1].m_collisionEntries.m_data));
            if ( *v2->m_parents->m_data.m_storage == -v2->m_numNodes )
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
    while ( v4 < v3->m_entities.m_size );
  }
  v11 = 0;
  if ( v3->m_entities.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = 0;
      v14 = v3->m_entities.m_data[v12];
      if ( v14->m_constraintsMaster.m_size > 0u )
      {
        v15 = 0i64;
        do
        {
          v16 = v14->m_constraintsMaster.m_data;
          v17 = v16[v15].m_entities[0];
          if ( v17->m_motion.m_type.m_storage != 5 )
          {
            v18 = v16[v15].m_entities[1];
            if ( v18->m_motion.m_type.m_storage != 5 )
            {
              hkUnionFind::addEdge(v2, v17->m_storageIndex, v18->m_storageIndex);
              if ( *v2->m_parents->m_data.m_storage == -v2->m_numNodes )
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
    while ( v11 < v3->m_entities.m_size );
  }
  v19 = &v34;
  v20 = -2147483638;
  v32 = 0;
  v21 = 0;
  v31 = &v34;
  v33 = -2147483638;
  if ( v3->m_actions.m_size <= 0 )
    goto LABEL_34;
  v22 = 0i64;
  while ( 1 )
  {
    v23 = v3->m_actions.m_data;
    if ( v23[v22] )
    {
      v32 = 0;
      v23[v22]->vfptr[2].__vecDelDtor((hkBaseObject *)&v23[v22]->vfptr, (unsigned int)&v31);
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
    if ( v21 >= v3->m_actions.m_size )
    {
      v20 = v33;
LABEL_34:
      v32 = 0;
      if ( v20 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v19,
          8 * v20);
      return *v2->m_parents->m_data.m_storage == -v2->m_numNodes;
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
  hkUnionFind::addEdge(v2, *(unsigned __int16 *)(*(_QWORD *)&v19[8 * v27] + 244i64), *(unsigned __int16 *)(v29 + 244));
  if ( *v2->m_parents->m_data.m_storage != -v2->m_numNodes )
  {
    v24 = v32;
    v19 = v31;
    goto LABEL_31;
  }
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v31,
      8 * v33);
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
void __fastcall hkpSimulationIsland::addConstraintToCriticalLockedIsland(hkpSimulationIsland *this, hkpConstraintInstance *constraint)
{
  hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(constraint->m_entities[0]->m_world, constraint);
}

// File Line: 594
// RVA: 0xD82A20
void __fastcall hkpSimulationIsland::removeConstraintFromCriticalLockedIsland(hkpSimulationIsland *this, hkpConstraintInstance *constraint)
{
  hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(constraint->m_entities[0]->m_world, constraint);
}

// File Line: 599
// RVA: 0xD82A40
void __fastcall hkpSimulationIsland::addCallbackRequest(hkpSimulationIsland *this, hkpConstraintInstance *constraint, int request)
{
  constraint->m_internal->m_callbackRequest |= request;
}

// File Line: 607
// RVA: 0xD82E30
void __fastcall hkpSimulationIsland::mergeConstraintInfo(hkpSimulationIsland *this, hkpSimulationIsland *other)
{
  int v2; // er8

  v2 = other->m_constraintInfo.m_maxSizeOfSchema;
  if ( this->m_constraintInfo.m_maxSizeOfSchema > v2 )
    v2 = this->m_constraintInfo.m_maxSizeOfSchema;
  this->m_constraintInfo.m_maxSizeOfSchema = v2;
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

