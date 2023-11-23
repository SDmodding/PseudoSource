// File Line: 36
// RVA: 0xD892E0
hkpSimulationIsland *__fastcall getAnyNonFixedIsland(hkpSimulationIsland *islandA, hkpSimulationIsland *islandB)
{
  if ( islandA->m_storageIndex == 0xFFFF && islandB->m_storageIndex != 0xFFFF )
    return islandB;
  return islandA;
}

// File Line: 53
// RVA: 0xD88C60
hkpAgentNnEntry *__fastcall hkpWorldAgentUtil::addAgent(
        hkpLinkedCollidable *collA,
        hkpLinkedCollidable *collB,
        hkpProcessCollisionInput *input)
{
  hkpEntity *v4; // rbx
  char *v5; // rbp
  hkpLinkedCollidable *v6; // rdi
  hkpLinkedCollidable *v7; // rsi
  hkpSimulationIsland *m_simulationIsland; // r14
  hkpShape *m_shape; // rax
  hkpCdBody *v10; // r15
  hkpCdBody *v11; // r12
  hkpLinkedCollidable *v12; // rcx
  hkpCdBody *v13; // rax
  hkpContactMgrFactory *v14; // rcx
  hkpContactMgr *mgr; // rax
  hkpCdBody v17; // [rsp+50h] [rbp-6B8h] BYREF
  hkpCdBody newCdBodies; // [rsp+D0h] [rbp-638h] BYREF
  hkMotionState newMotionStates; // [rsp+150h] [rbp-5B8h] BYREF
  hkMotionState v20; // [rsp+410h] [rbp-2F8h] BYREF
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+710h] [rbp+8h] BYREF
  int isFlippedOut; // [rsp+718h] [rbp+10h] BYREF
  int agentTypeOut; // [rsp+720h] [rbp+18h] BYREF

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
  m_simulationIsland = v4->m_simulationIsland;
  if ( m_simulationIsland->m_storageIndex == 0xFFFF && *(_WORD *)(*((_QWORD *)v5 + 37) + 44i64) != 0xFFFF )
    m_simulationIsland = (hkpSimulationIsland *)*((_QWORD *)v5 + 37);
  m_shape = v7->m_shape;
  cdBodyHasTransformFlag.m_storage = 0;
  v10 = v7;
  v11 = v6;
  if ( m_shape->m_type.m_storage == 14 )
    v10 = hkAgentMachine_processTransformedShapes(v7, &newCdBodies, &newMotionStates, 4, &cdBodyHasTransformFlag);
  if ( v6->m_shape->m_type.m_storage == 14 )
    v11 = hkAgentMachine_processTransformedShapes(v6, &v17, &v20, 4, &cdBodyHasTransformFlag);
  hkAgentNnMachine_GetAgentType(v10, v11, input, &agentTypeOut, &isFlippedOut);
  if ( isFlippedOut )
  {
    v12 = v7;
    v13 = v10;
    v7 = v6;
    v10 = v11;
    v6 = v12;
    v11 = v13;
  }
  v14 = input->m_dispatcher.m_storage->m_contactMgrFactory[v4->m_material.m_responseType.m_storage][v5[200]];
  mgr = (hkpContactMgr *)((__int64 (__fastcall *)(hkpContactMgrFactory *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *))v14->vfptr[1].__first_virtual_table_function__)(
                           v14,
                           v7,
                           v6,
                           input);
  return hkAgentNnMachine_CreateAgent(
           &m_simulationIsland->m_narrowphaseAgentTrack,
           v7,
           v10,
           v6,
           v11,
           cdBodyHasTransformFlag.m_storage,
           agentTypeOut,
           input,
           mgr);
}

// File Line: 135
// RVA: 0xD88E30
void __fastcall hkpWorldAgentUtil::removeAgent(hkpAgentNnEntry *agent)
{
  char *v2; // rcx
  __int64 v3; // rbx
  char *v4; // rsi
  hkpSimulationIsland *IslandFromAgentEntry; // rax
  hkpAgentNnTrack *p_m_narrowphaseAgentTrack; // rcx
  hkpContactMgr *m_contactMgr; // rbx

  v2 = (char *)agent->m_collidable[0] + agent->m_collidable[0]->m_ownerOffset;
  v3 = *((_QWORD *)v2 + 37);
  v4 = (char *)agent->m_collidable[1] + agent->m_collidable[1]->m_ownerOffset;
  IslandFromAgentEntry = (hkpSimulationIsland *)*((_QWORD *)v4 + 37);
  if ( (hkpSimulationIsland *)v3 == IslandFromAgentEntry )
  {
    *(_BYTE *)(v3 + 49) &= ~2u;
    *(_BYTE *)(v3 + 49) |= 1u;
    IslandFromAgentEntry = (hkpSimulationIsland *)v3;
  }
  else if ( v2[352] != 5 )
  {
    if ( v4[352] == 5 )
    {
      IslandFromAgentEntry = (hkpSimulationIsland *)*((_QWORD *)v2 + 37);
    }
    else
    {
      IslandFromAgentEntry = hkpWorldAgentUtil::getIslandFromAgentEntry(
                               agent,
                               *((hkpSimulationIsland **)v2 + 37),
                               *((hkpSimulationIsland **)v4 + 37));
      *(_BYTE *)(v3 + 49) &= ~2u;
      *(_BYTE *)(v3 + 49) |= 1u;
      *(_BYTE *)(*((_QWORD *)v4 + 37) + 49i64) = *(_BYTE *)(*((_QWORD *)v4 + 37) + 49i64) & 0xFC | 1;
    }
  }
  p_m_narrowphaseAgentTrack = &IslandFromAgentEntry->m_narrowphaseAgentTrack;
  if ( agent->m_nnTrackType.m_storage != 2 )
    p_m_narrowphaseAgentTrack = &IslandFromAgentEntry->m_midphaseAgentTrack;
  m_contactMgr = agent->m_contactMgr;
  hkAgentNnMachine_DestroyAgent(
    p_m_narrowphaseAgentTrack,
    agent,
    IslandFromAgentEntry->m_world->m_collisionDispatcher,
    IslandFromAgentEntry);
  m_contactMgr->vfptr[4].__first_virtual_table_function__(m_contactMgr);
}

// File Line: 191
// RVA: 0xD88F10
void __fastcall hkpWorldAgentUtil::removeAgentAndItsToiEvents(hkpAgentNnEntry *agent)
{
  __int64 v3; // rcx

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(&agent->m_collidable[0][2].m_broadPhaseHandle.m_type
                                         + agent->m_collidable[0]->m_ownerOffset)
                             + 32i64)
                 + 16i64);
  (*(void (__fastcall **)(__int64, hkpAgentNnEntry *))(*(_QWORD *)v3 + 112i64))(v3, agent);
  hkpWorldAgentUtil::removeAgent(agent);
}

// File Line: 199
// RVA: 0xD88F50
hkpSimulationIsland *__fastcall hkpWorldAgentUtil::getIslandFromAgentEntry(
        hkpAgentNnSector *entry,
        hkpSimulationIsland *candidateA,
        hkpSimulationIsland *candidateB)
{
  hkpSimulationIsland *v4; // r11
  hkpAgentNnTrack *p_m_narrowphaseAgentTrack; // rdx
  hkpAgentNnTrack *p_m_midphaseAgentTrack; // r8
  bool v8; // cl
  char v9; // al
  __int64 v10; // r9
  __int64 m_size; // rbx
  hkpAgentNnSector **m_data; // r8

  v4 = candidateA;
  if ( entry->m_data[18] == 2 )
  {
    p_m_narrowphaseAgentTrack = &candidateA->m_narrowphaseAgentTrack;
    p_m_midphaseAgentTrack = &candidateB->m_narrowphaseAgentTrack;
  }
  else
  {
    p_m_narrowphaseAgentTrack = &candidateA->m_midphaseAgentTrack;
    p_m_midphaseAgentTrack = &candidateB->m_midphaseAgentTrack;
  }
  v8 = p_m_narrowphaseAgentTrack->m_sectors.m_size <= p_m_midphaseAgentTrack->m_sectors.m_size;
  v9 = 0;
  if ( p_m_narrowphaseAgentTrack->m_sectors.m_size <= p_m_midphaseAgentTrack->m_sectors.m_size )
    p_m_midphaseAgentTrack = p_m_narrowphaseAgentTrack;
  v10 = 0i64;
  m_size = p_m_midphaseAgentTrack->m_sectors.m_size;
  if ( m_size > 0 )
  {
    m_data = p_m_midphaseAgentTrack->m_sectors.m_data;
    while ( *m_data > entry || entry >= &(*m_data)[1] )
    {
      ++v10;
      ++m_data;
      if ( v10 >= m_size )
        goto LABEL_13;
    }
    v9 = 1;
  }
LABEL_13:
  if ( v8 != (v9 != 0) )
    return candidateB;
  return v4;
}

// File Line: 234
// RVA: 0xD89300
hkpContactMgr **__fastcall getAgentData(hkpAgentNnEntry *entry)
{
  hkpContactMgr **result; // rax

  result = (hkpContactMgr **)entry[1].m_collidable;
  if ( entry->m_streamCommand != 4 )
    return &entry[1].m_contactMgr;
  return result;
}

// File Line: 247
// RVA: 0xD88FF0
void __fastcall hkpWorldAgentUtil::updateEntityShapeCollectionFilter(
        hkpEntity *entity,
        hkpCollisionInput *collisionInput)
{
  int m_size; // r8d
  int v4; // ebx
  __int64 v5; // rdi
  hkpAgentNnEntry *m_agentEntry; // rcx
  void (__fastcall *m_updateFilterFunc)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r11
  char *m_collidable; // rdx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+40h] [rbp-18h] BYREF

  entries.m_data = 0i64;
  entries.m_size = 0;
  entries.m_capacityAndFlags = 0x80000000;
  hkpLinkedCollidable::getCollisionEntriesSorted(&entity->m_collidable, &entries);
  m_size = entries.m_size;
  v4 = 0;
  if ( entries.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_agentEntry = entries.m_data[v5].m_agentEntry;
      m_updateFilterFunc = collisionInput->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)m_agentEntry->m_agentType].m_updateFilterFunc;
      if ( m_updateFilterFunc )
      {
        m_collidable = (char *)m_agentEntry[1].m_collidable;
        if ( m_agentEntry->m_streamCommand != 4 )
          m_collidable = (char *)&m_agentEntry[1].m_contactMgr;
        ((void (__fastcall *)(hkpAgentNnEntry *, char *))m_updateFilterFunc)(m_agentEntry, m_collidable);
        m_size = entries.m_size;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < m_size );
  }
  entries.m_size = 0;
  if ( entries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entries.m_data,
      16 * entries.m_capacityAndFlags);
}

// File Line: 274
// RVA: 0xD89120
void __fastcall hkpWorldAgentUtil::invalidateTim(hkpEntity *entity, hkpCollisionInput *collisionInput)
{
  int v2; // ebx
  __int64 v5; // rdi

  v2 = 0;
  if ( entity->m_collidable.m_collisionEntries.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkAgentNnMachine_InvalidateTimInAgent(
        entity->m_collidable.m_collisionEntries.m_data[v5].m_agentEntry,
        collisionInput);
      ++v2;
      ++v5;
    }
    while ( v2 < entity->m_collidable.m_collisionEntries.m_size );
  }
}

// File Line: 286
// RVA: 0xD89190
void __fastcall hkpWorldAgentUtil::warpTime(
        hkpSimulationIsland *island,
        float oldTime,
        float newTime,
        hkpCollisionInput *collisionInput)
{
  int v4; // r15d
  int m_size; // ecx
  int v8; // r14d
  __int64 v9; // r12
  hkpAgentNnEntry *v10; // rbx
  hkpAgentNnEntry *v11; // rdi
  int v12; // ecx
  __int64 v13; // r14
  hkpAgentNnEntry *v14; // rbx
  hkpAgentNnEntry *v15; // rdi

  v4 = 0;
  m_size = island->m_narrowphaseAgentTrack.m_sectors.m_size;
  v8 = 0;
  if ( m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      ++v8;
      v10 = (hkpAgentNnEntry *)island->m_narrowphaseAgentTrack.m_sectors.m_data[v9++];
      if ( v8 == m_size )
        v11 = (hkpAgentNnEntry *)((char *)v10 + island->m_narrowphaseAgentTrack.m_bytesUsedInLastSector);
      else
        v11 = v10 + 24;
      for ( ; v10 < v11; v10 = (hkpAgentNnEntry *)((char *)v10 + (unsigned __int8)v10->m_size) )
        hkAgentNnMachine_WarpTimeInAgent(v10, oldTime, newTime, collisionInput);
      m_size = island->m_narrowphaseAgentTrack.m_sectors.m_size;
    }
    while ( v8 < m_size );
  }
  v12 = island->m_midphaseAgentTrack.m_sectors.m_size;
  if ( v12 > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v4;
      v14 = (hkpAgentNnEntry *)island->m_midphaseAgentTrack.m_sectors.m_data[v13++];
      if ( v4 == v12 )
        v15 = (hkpAgentNnEntry *)((char *)v14 + island->m_midphaseAgentTrack.m_bytesUsedInLastSector);
      else
        v15 = v14 + 24;
      for ( ; v14 < v15; v14 = (hkpAgentNnEntry *)((char *)v14 + (unsigned __int8)v14->m_size) )
        hkAgentNnMachine_WarpTimeInAgent(v14, oldTime, newTime, collisionInput);
      v12 = island->m_midphaseAgentTrack.m_sectors.m_size;
    }
    while ( v4 < v12 );
  }
}

