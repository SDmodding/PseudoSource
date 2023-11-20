// File Line: 36
// RVA: 0xD892E0
hkpSimulationIsland *__fastcall getAnyNonFixedIsland(hkpSimulationIsland *islandA, hkpSimulationIsland *islandB)
{
  if ( islandA->m_storageIndex == -1 && islandB->m_storageIndex != -1 )
    islandA = islandB;
  return islandA;
}

// File Line: 53
// RVA: 0xD88C60
hkpAgentNnEntry *__fastcall hkpWorldAgentUtil::addAgent(hkpLinkedCollidable *collA, hkpLinkedCollidable *collB, hkpProcessCollisionInput *input)
{
  hkpProcessCollisionInput *v3; // r13
  hkpEntity *v4; // rbx
  char *v5; // rbp
  hkpLinkedCollidable *v6; // rdi
  hkpLinkedCollidable *v7; // rsi
  hkpSimulationIsland *v8; // r14
  hkpShape *v9; // rax
  hkpCdBody *v10; // r15
  hkpCdBody *v11; // r12
  hkpLinkedCollidable *v12; // rcx
  hkpCdBody *v13; // rax
  hkpContactMgrFactory *v14; // rcx
  hkpContactMgr *mgr; // rax
  hkpCdBody v17; // [rsp+50h] [rbp-6B8h]
  hkpCdBody newCdBodies; // [rsp+D0h] [rbp-638h]
  hkMotionState newMotionStates; // [rsp+150h] [rbp-5B8h]
  hkMotionState v20; // [rsp+410h] [rbp-2F8h]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+710h] [rbp+8h]
  int isFlippedOut; // [rsp+718h] [rbp+10h]
  int agentTypeOut; // [rsp+720h] [rbp+18h]

  v3 = input;
  v4 = (hkpEntity *)((char *)collA + collA->m_ownerOffset);
  v5 = (char *)collB + collB->m_ownerOffset;
  v6 = collB;
  v7 = collA;
  if ( v4->m_motion.m_type.m_storage != 5
    && v5[352] != 5
    && v4->m_simulationIsland != (hkpSimulationIsland *)*((_QWORD *)v5 + 37) )
  {
    hkpWorldOperationUtil::mergeIslands(v4->m_world, v4, (hkpEntity *)((char *)collB + collB->m_ownerOffset));
  }
  v8 = v4->m_simulationIsland;
  if ( v8->m_storageIndex == -1 && *(_WORD *)(*((_QWORD *)v5 + 37) + 44i64) != -1 )
    v8 = (hkpSimulationIsland *)*((_QWORD *)v5 + 37);
  v9 = v7->m_shape;
  cdBodyHasTransformFlag.m_storage = 0;
  v10 = (hkpCdBody *)&v7->m_shape;
  v11 = (hkpCdBody *)&v6->m_shape;
  if ( v9->m_type.m_storage == 14 )
    v10 = hkAgentMachine_processTransformedShapes(
            (hkpCdBody *)&v7->m_shape,
            &newCdBodies,
            &newMotionStates,
            4,
            &cdBodyHasTransformFlag);
  if ( v6->m_shape->m_type.m_storage == 14 )
    v11 = hkAgentMachine_processTransformedShapes((hkpCdBody *)&v6->m_shape, &v17, &v20, 4, &cdBodyHasTransformFlag);
  hkAgentNnMachine_GetAgentType(v10, v11, v3, &agentTypeOut, &isFlippedOut);
  if ( isFlippedOut )
  {
    v12 = v7;
    v13 = v10;
    v7 = v6;
    v10 = v11;
    v6 = v12;
    v11 = v13;
  }
  v14 = v3->m_dispatcher.m_storage->m_contactMgrFactory[0][v5[200] + 8i64 * v4->m_material.m_responseType.m_storage];
  mgr = (hkpContactMgr *)((__int64 (__fastcall *)(hkpContactMgrFactory *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *))v14->vfptr[1].__first_virtual_table_function__)(
                           v14,
                           v7,
                           v6,
                           v3);
  return hkAgentNnMachine_CreateAgent(
           &v8->m_narrowphaseAgentTrack,
           v7,
           v10,
           v6,
           v11,
           cdBodyHasTransformFlag.m_storage,
           agentTypeOut,
           v3,
           mgr);
}

// File Line: 135
// RVA: 0xD88E30
void __fastcall hkpWorldAgentUtil::removeAgent(hkpAgentNnEntry *agent)
{
  hkpAgentNnEntry *v1; // rdi
  char *v2; // rcx
  __int64 v3; // rbx
  char *v4; // rsi
  hkpSimulationIsland *v5; // rax
  hkpAgentNnTrack *v6; // rcx
  hkpContactMgr *v7; // rbx

  v1 = agent;
  v2 = (char *)agent->m_collidable[0] + agent->m_collidable[0]->m_ownerOffset;
  v3 = *((_QWORD *)v2 + 37);
  v4 = (char *)v1->m_collidable[1] + v1->m_collidable[1]->m_ownerOffset;
  v5 = (hkpSimulationIsland *)*((_QWORD *)v4 + 37);
  if ( (hkpSimulationIsland *)v3 == v5 )
  {
    *(_BYTE *)(v3 + 49) &= 0xFDu;
    *(_BYTE *)(v3 + 49) |= 1u;
    v5 = (hkpSimulationIsland *)v3;
  }
  else if ( v2[352] != 5 )
  {
    if ( v4[352] == 5 )
    {
      v5 = (hkpSimulationIsland *)*((_QWORD *)v2 + 37);
    }
    else
    {
      v5 = hkpWorldAgentUtil::getIslandFromAgentEntry(
             v1,
             *((hkpSimulationIsland **)v2 + 37),
             *((hkpSimulationIsland **)v4 + 37));
      *(_BYTE *)(v3 + 49) &= 0xFDu;
      *(_BYTE *)(v3 + 49) |= 1u;
      *(_BYTE *)(*((_QWORD *)v4 + 37) + 49i64) = *(_BYTE *)(*((_QWORD *)v4 + 37) + 49i64) & 0xFD | 1;
    }
  }
  v6 = &v5->m_narrowphaseAgentTrack;
  if ( v1->m_nnTrackType.m_storage != 2 )
    v6 = &v5->m_midphaseAgentTrack;
  v7 = v1->m_contactMgr;
  hkAgentNnMachine_DestroyAgent(v6, v1, v5->m_world->m_collisionDispatcher, (hkpConstraintOwner *)&v5->vfptr);
  v7->vfptr[4].__first_virtual_table_function__((hkBaseObject *)&v7->vfptr);
}

// File Line: 191
// RVA: 0xD88F10
void __fastcall hkpWorldAgentUtil::removeAgentAndItsToiEvents(hkpAgentNnEntry *agent)
{
  hkpAgentNnEntry *v1; // rbx
  hkpAgentNnEntry *v2; // rdx
  __int64 v3; // rcx

  v1 = agent;
  v2 = agent;
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(&agent->m_collidable[0][2].m_broadPhaseHandle.m_type
                                         + agent->m_collidable[0]->m_ownerOffset)
                             + 32i64)
                 + 16i64);
  (*(void (__fastcall **)(__int64, hkpAgentNnEntry *))(*(_QWORD *)v3 + 112i64))(v3, v2);
  hkpWorldAgentUtil::removeAgent(v1);
}

// File Line: 199
// RVA: 0xD88F50
hkpSimulationIsland *__fastcall hkpWorldAgentUtil::getIslandFromAgentEntry(hkpAgentNnEntry *entry, hkpSimulationIsland *candidateA, hkpSimulationIsland *candidateB)
{
  hkpSimulationIsland *v3; // rdi
  hkpSimulationIsland *v4; // r11
  hkpAgentNnEntry *v5; // r10
  hkpAgentNnTrack *v6; // rdx
  hkpAgentNnTrack *v7; // r8
  bool v8; // cl
  char v9; // al
  __int64 v10; // r9
  __int64 v11; // rbx
  hkpAgentNnSector **v12; // r8

  v3 = candidateB;
  v4 = candidateA;
  v5 = entry;
  if ( entry->m_nnTrackType.m_storage == 2 )
  {
    v6 = &candidateA->m_narrowphaseAgentTrack;
    v7 = &candidateB->m_narrowphaseAgentTrack;
  }
  else
  {
    v6 = &candidateA->m_midphaseAgentTrack;
    v7 = &candidateB->m_midphaseAgentTrack;
  }
  v8 = v6->m_sectors.m_size <= v7->m_sectors.m_size;
  v9 = 0;
  if ( v8 )
    v7 = v6;
  v10 = 0i64;
  v11 = v7->m_sectors.m_size;
  if ( v11 > 0 )
  {
    v12 = v7->m_sectors.m_data;
    while ( *v12 > (hkpAgentNnSector *)v5 || v5 >= (hkpAgentNnEntry *)&(*v12)[1] )
    {
      ++v10;
      ++v12;
      if ( v10 >= v11 )
        goto LABEL_13;
    }
    v9 = 1;
  }
LABEL_13:
  if ( (v8 != 0) ^ (v9 != 0) )
    v4 = v3;
  return v4;
}

// File Line: 234
// RVA: 0xD89300
void *__fastcall getAgentData(hkpAgentNnEntry *entry)
{
  void *result; // rax

  result = entry[1].m_collidable;
  if ( entry->m_streamCommand != 4 )
    result = &entry[1].m_contactMgr;
  return result;
}

// File Line: 247
// RVA: 0xD88FF0
void __fastcall hkpWorldAgentUtil::updateEntityShapeCollectionFilter(hkpEntity *entity, hkpCollisionInput *collisionInput)
{
  hkpCollisionInput *v2; // rsi
  int v3; // er8
  int v4; // ebx
  __int64 v5; // rdi
  hkpAgentNnEntry *v6; // rcx
  void (__fastcall *v7)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r11
  hkpLinkedCollidable *v8; // r8
  __int64 v9; // rax
  __int64 v10; // r10
  __int64 v11; // r10
  signed __int64 v12; // rdx
  hkpContactMgr *v13; // ST28_8
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+40h] [rbp-18h]

  v2 = collisionInput;
  entries.m_data = 0i64;
  entries.m_size = 0;
  entries.m_capacityAndFlags = 2147483648;
  hkpLinkedCollidable::getCollisionEntriesSorted(&entity->m_collidable, &entries);
  v3 = entries.m_size;
  v4 = 0;
  if ( entries.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = entries.m_data[v5].m_agentEntry;
      v7 = v2->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v6->m_agentType].m_updateFilterFunc;
      if ( v7 )
      {
        v8 = v6->m_collidable[0];
        v9 = v8->m_ownerOffset;
        if ( *((_BYTE *)&v8[2].m_boundingVolumeData.m_childShapeKeys + v9) == 5 )
          v10 = *(_QWORD *)(&v6->m_collidable[1][2].m_broadPhaseHandle.m_type + v6->m_collidable[1]->m_ownerOffset);
        else
          v11 = *(_QWORD *)(&v8[2].m_broadPhaseHandle.m_type + v9);
        v12 = (signed __int64)v6[1].m_collidable;
        if ( v6->m_streamCommand != 4 )
          v12 = (signed __int64)&v6[1].m_contactMgr;
        v13 = v6->m_contactMgr;
        ((void (__fastcall *)(hkpAgentNnEntry *, signed __int64))v7)(v6, v12);
        v3 = entries.m_size;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3 );
  }
  entries.m_size = 0;
  if ( entries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entries.m_data,
      16 * entries.m_capacityAndFlags);
}

// File Line: 274
// RVA: 0xD89120
void __fastcall hkpWorldAgentUtil::invalidateTim(hkpEntity *entity, hkpCollisionInput *collisionInput)
{
  int v2; // ebx
  hkpCollisionInput *v3; // rbp
  hkpEntity *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = collisionInput;
  v4 = entity;
  if ( entity->m_collidable.m_collisionEntries.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkAgentNnMachine_InvalidateTimInAgent(v4->m_collidable.m_collisionEntries.m_data[v5].m_agentEntry, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_collidable.m_collisionEntries.m_size );
  }
}

// File Line: 286
// RVA: 0xD89190
void __fastcall hkpWorldAgentUtil::warpTime(hkpSimulationIsland *island, float oldTime, float newTime, hkpCollisionInput *collisionInput)
{
  int v4; // er15
  hkpSimulationIsland *v5; // rsi
  int v6; // ecx
  hkpCollisionInput *v7; // rbp
  int v8; // er14
  __int64 v9; // r12
  hkpAgentNnEntry *v10; // rbx
  unsigned __int64 v11; // rdi
  int v12; // ecx
  __int64 v13; // r14
  hkpAgentNnEntry *v14; // rbx
  unsigned __int64 v15; // rdi

  v4 = 0;
  v5 = island;
  v6 = island->m_narrowphaseAgentTrack.m_sectors.m_size;
  v7 = collisionInput;
  v8 = 0;
  if ( v6 > 0 )
  {
    v9 = 0i64;
    do
    {
      ++v8;
      ++v9;
      v10 = (hkpAgentNnEntry *)v5->m_narrowphaseAgentTrack.m_sectors.m_data[v9 - 1];
      if ( v8 == v6 )
        v11 = (unsigned __int64)v10 + v5->m_narrowphaseAgentTrack.m_bytesUsedInLastSector;
      else
        v11 = (unsigned __int64)&v10[24];
      for ( ; (unsigned __int64)v10 < v11; v10 = (hkpAgentNnEntry *)((char *)v10 + (unsigned __int8)v10->m_size) )
        hkAgentNnMachine_WarpTimeInAgent(v10, oldTime, newTime, v7);
      v6 = v5->m_narrowphaseAgentTrack.m_sectors.m_size;
    }
    while ( v8 < v6 );
  }
  v12 = v5->m_midphaseAgentTrack.m_sectors.m_size;
  if ( v12 > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v4;
      ++v13;
      v14 = (hkpAgentNnEntry *)v5->m_midphaseAgentTrack.m_sectors.m_data[v13 - 1];
      if ( v4 == v12 )
        v15 = (unsigned __int64)v14 + v5->m_midphaseAgentTrack.m_bytesUsedInLastSector;
      else
        v15 = (unsigned __int64)&v14[24];
      for ( ; (unsigned __int64)v14 < v15; v14 = (hkpAgentNnEntry *)((char *)v14 + (unsigned __int8)v14->m_size) )
        hkAgentNnMachine_WarpTimeInAgent(v14, oldTime, newTime, v7);
      v12 = v5->m_midphaseAgentTrack.m_sectors.m_size;
    }
    while ( v4 < v12 );
  }
}

