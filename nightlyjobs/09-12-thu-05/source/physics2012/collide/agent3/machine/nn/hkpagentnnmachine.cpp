// File Line: 43
// RVA: 0xD43130
hkpAgentNnEntry *__fastcall hkAgentNnMachine_getLastEntry(hkpAgentNnTrack *track, int forcePpuEntry)
{
  return (hkpAgentNnEntry *)((char *)track->m_sectors.m_data[track->m_sectors.m_size - 1]
                           + track->m_bytesUsedInLastSector
                           - 80 * (unsigned int)(unsigned __int8)track->m_nnTrackType.m_storage);
}

// File Line: 65
// RVA: 0xD43160
void __fastcall hkAgentNnMachine_RelinkEntry(hkpAgentNnEntry *entry)
{
  int v1; // r9d

  v1 = entry->m_agentIndexOnCollidable[1];
  entry->m_collidable[0]->m_collisionEntries.m_data[entry->m_agentIndexOnCollidable[0]].m_agentEntry = entry;
  entry->m_collidable[1]->m_collisionEntries.m_data[v1].m_agentEntry = entry;
}

// File Line: 80
// RVA: 0xD431A0
hkpAgentNnEntry *__fastcall hkAgentNnMachine_AllocateEntry(hkpAgentNnTrack *track, int forcePpuEntry)
{
  unsigned __int16 m_bytesUsedInLastSector; // r9
  hkpAgentNnEntry *result; // rax
  _QWORD **Value; // rax
  hkpAgentNnEntry *v6; // rsi

  m_bytesUsedInLastSector = track->m_bytesUsedInLastSector;
  if ( track->m_bytesUsedInLastSector >= 0x3C0u )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 960i64);
    if ( track->m_sectors.m_size == (track->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&track->m_sectors.m_data, 8);
    result = v6;
    track->m_sectors.m_data[track->m_sectors.m_size++] = (hkpAgentNnSector *)v6;
    track->m_bytesUsedInLastSector = 80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  }
  else
  {
    result = (hkpAgentNnEntry *)&track->m_sectors.m_data[track->m_sectors.m_size - 1]->m_data[m_bytesUsedInLastSector];
    track->m_bytesUsedInLastSector = m_bytesUsedInLastSector + 80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  }
  return result;
}

// File Line: 145
// RVA: 0xD43280
void __fastcall hkAgentNnMachine_DeallocateLastEntry(hkpAgentNnTrack *track, int ppuEntry)
{
  __int16 v3; // ax
  bool v4; // zf
  __int64 m_size; // r8
  hkpAgentNnSector *v6; // rbx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *p_m_sectors; // rdx
  unsigned int v10; // ecx
  int requestedCapacity; // eax

  v3 = -80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  v4 = v3 + track->m_bytesUsedInLastSector == 0;
  track->m_bytesUsedInLastSector += v3;
  if ( v4 )
  {
    m_size = track->m_sectors.m_size;
    v6 = track->m_sectors.m_data[m_size - 1];
    track->m_sectors.m_size = m_size - 1;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgentNnSector *, __int64))(*Value[11] + 16i64))(Value[11], v6, 960i64);
    track->m_bytesUsedInLastSector = 960;
  }
  m_capacityAndFlags = track->m_sectors.m_capacityAndFlags;
  p_m_sectors = &track->m_sectors;
  if ( m_capacityAndFlags >= 0 )
  {
    v10 = ((((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 2) | ((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3);
    requestedCapacity = (v10 | (v10 >> 1)) + 1;
    if ( requestedCapacity >= 1 )
    {
      if ( requestedCapacity < (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_sectors->m_data,
          8,
          0i64,
          requestedCapacity);
    }
    else
    {
      hkArrayUtil::_reduce(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&track->m_sectors.m_data,
        8,
        (char *)track->m_sectors.m_storage,
        1);
    }
  }
}

// File Line: 201
// RVA: 0xD40F60
void __fastcall hkAgentNnMachine_GetAgentType(
        hkpCdBody *cdBodyA,
        hkpCdBody *cdBodyB,
        hkpProcessCollisionInput *input,
        int *agentTypeOut,
        int *isFlippedOut)
{
  hkpCollisionDispatcher *m_storage; // r10
  __int64 v6; // rcx
  __int64 v8; // rdx
  __int64 v10; // r11
  unsigned __int8 *v11; // rcx
  int v12; // r9d
  BOOL v13; // r8d
  __int64 v14; // rdx
  int v15; // eax

  m_storage = input->m_dispatcher.m_storage;
  v6 = (unsigned __int8)cdBodyA->m_shape->m_type.m_storage;
  v8 = (unsigned __int8)cdBodyB->m_shape->m_type.m_storage;
  if ( input->m_createPredictiveAgents.m_storage )
  {
    v10 = (int)v6;
    v8 = (int)v8;
    v11 = (unsigned __int8 *)m_storage + 35 * (int)v6 + (int)v8;
    v12 = v11[6944];
  }
  else
  {
    v10 = v6;
    v11 = (unsigned __int8 *)m_storage + 35 * v6 + v8;
    v12 = v11[5712];
  }
  v13 = m_storage->m_agent3Func[v12].m_symmetric == IS_NOT_SYMMETRIC_AND_FLIPPED;
  if ( v12 == 1 )
    v13 = m_storage->m_agent2Func[v11[688]].m_isFlipped.m_bool != 0;
  *isFlippedOut = v13;
  if ( v13 )
  {
    v14 = v10 + 35 * v8;
    if ( input->m_createPredictiveAgents.m_storage )
      v15 = (unsigned __int8)m_storage->m_agent3TypesPred[0][v14];
    else
      v15 = (unsigned __int8)m_storage->m_agent3Types[0][v14];
    *agentTypeOut = v15;
  }
  else
  {
    *agentTypeOut = v12;
  }
}

// File Line: 226
// RVA: 0xD41050
hkpAgentNnEntry *__fastcall hkAgentNnMachine_CreateAgent(
        hkpAgentNnTrack *track,
        hkpLinkedCollidable *collA,
        hkpCdBody *firstNonTransformBodyA,
        hkpLinkedCollidable *collB,
        hkpCdBody *firstNonTransformBodyB,
        char cdBodyHasTransformFlag,
        int agentType,
        hkpProcessCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpCollisionDispatcher *m_storage; // r13
  hkpAgentNnEntry *Entry; // rax
  hkpAgentNnEntry *v14; // rbx
  hkpLinkedCollidable::CollisionEntry *v15; // rsi
  int m_size; // eax
  hkpLinkedCollidable::CollisionEntry *v17; // rcx
  hkTransformf *m_motion; // r8
  hkTransformf *v19; // rdx
  __int64 v20; // rcx
  char v21; // al
  void *m_collidable; // r8
  hkpAgentNnEntry *result; // rax
  __int64 v24[6]; // [rsp+20h] [rbp-98h] BYREF
  hkTransformf v25; // [rsp+50h] [rbp-68h] BYREF

  m_storage = input->m_dispatcher.m_storage;
  Entry = hkAgentNnMachine_AllocateEntry(track, 0);
  Entry->m_contactMgr = mgr;
  v14 = Entry;
  Entry->m_nnTrackType.m_storage = track->m_nnTrackType.m_storage;
  Entry->m_collidable[0] = collA;
  Entry->m_collidable[1] = collB;
  Entry->m_agentIndexOnCollidable[0] = collA->m_collisionEntries.m_size;
  Entry->m_agentIndexOnCollidable[1] = collB->m_collisionEntries.m_size;
  if ( collA->m_collisionEntries.m_size == (collA->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collA->m_collisionEntries.m_data, 16);
  v15 = &collA->m_collisionEntries.m_data[collA->m_collisionEntries.m_size++];
  if ( collB->m_collisionEntries.m_size == (collB->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collB->m_collisionEntries.m_data, 16);
  m_size = collB->m_collisionEntries.m_size;
  v24[0] = (__int64)firstNonTransformBodyA;
  v24[1] = (__int64)firstNonTransformBodyB;
  v24[2] = 0i64;
  v24[3] = (__int64)input;
  v17 = &collB->m_collisionEntries.m_data[m_size];
  collB->m_collisionEntries.m_size = m_size + 1;
  v15->m_agentEntry = v14;
  v17->m_agentEntry = v14;
  v15->m_partner = collB;
  v17->m_partner = collA;
  m_motion = (hkTransformf *)firstNonTransformBodyB->m_motion;
  v19 = (hkTransformf *)firstNonTransformBodyA->m_motion;
  v24[4] = (__int64)v14->m_contactMgr;
  hkTransformf::setMulInverseMul(&v25, v19, m_motion);
  v20 = input->m_dispatcher.m_storage->m_collisionQualityTable[collA->m_broadPhaseHandle.m_objectQualityType][collB->m_broadPhaseHandle.m_objectQualityType];
  v14->m_collisionQualityIndex = v20;
  input->m_collisionQualityInfo.m_storage = &input->m_dispatcher.m_storage->m_collisionQualityInfo[v20];
  v14->m_agentType = agentType;
  if ( m_storage->m_agent3Func[agentType].m_sepNormalFunc )
  {
    v21 = cdBodyHasTransformFlag | 4;
    v14[1].hkpAgentEntry = (hkpAgentEntry)-1082130432;
    m_collidable = v14[1].m_collidable;
    *(_OWORD *)&v14[1].m_contactMgr = 0i64;
  }
  else
  {
    v21 = cdBodyHasTransformFlag | 2;
    m_collidable = &v14[1].m_contactMgr;
  }
  v14->m_streamCommand = v21;
  m_storage->m_agent3Func[(unsigned __int8)agentType].m_createFunc((hkpAgent3Input *)v24, v14, m_collidable);
  result = v14;
  v14->m_size = 80 * track->m_nnTrackType.m_storage;
  return result;
}

// File Line: 322
// RVA: 0xD41250
void __fastcall hkAgentNnMachine_DestroyAgent(
        hkpAgentNnTrack *track,
        hkpAgentNnEntry *entry,
        hkpCollisionDispatcher *dispatcher,
        hkpConstraintOwner *constraintOwner)
{
  __int64 m_agentType; // rax
  char *p_m_contactMgr; // rdx
  unsigned __int16 *m_agentIndexOnCollidable; // rdi
  hkpLinkedCollidable **m_collidable; // rsi
  __int64 v10; // rbp
  hkpLinkedCollidable *v11; // r11
  __int64 v12; // r9
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // r8
  __int64 v16; // rcx
  hkpAgentNnEntry *m_agentEntry; // rdx
  unsigned int v18; // ecx
  int requestedCapacity; // edx

  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      m_agentType = (unsigned __int8)entry->m_agentType;
      p_m_contactMgr = (char *)&entry[1].m_contactMgr;
      goto LABEL_4;
    case 4:
    case 0xC:
      m_agentType = (unsigned __int8)entry->m_agentType;
      p_m_contactMgr = (char *)entry[1].m_collidable;
LABEL_4:
      dispatcher->m_agent3Func[m_agentType].m_destroyFunc(
        entry,
        p_m_contactMgr,
        entry->m_contactMgr,
        constraintOwner,
        dispatcher);
      break;
    default:
      break;
  }
  m_agentIndexOnCollidable = entry->m_agentIndexOnCollidable;
  m_collidable = entry->m_collidable;
  v10 = 2i64;
  do
  {
    v11 = *m_collidable;
    v12 = *m_agentIndexOnCollidable;
    if ( --v11->m_collisionEntries.m_size != (_DWORD)v12 )
    {
      v13 = 2i64;
      v14 = (__int64)&v11->m_collisionEntries.m_data[(int)v12];
      v15 = (__int64)&v11->m_collisionEntries.m_data[v11->m_collisionEntries.m_size] - v14;
      do
      {
        v16 = *(_QWORD *)(v15 + v14);
        v14 += 8i64;
        *(_QWORD *)(v14 - 8) = v16;
        --v13;
      }
      while ( v13 );
    }
    if ( (int)v12 < v11->m_collisionEntries.m_size )
    {
      m_agentEntry = v11->m_collisionEntries.m_data[v12].m_agentEntry;
      m_agentEntry->m_agentIndexOnCollidable[m_agentEntry->m_collidable[0] != v11] = v12;
    }
    v18 = ((((((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 4) | ((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 2) | ((((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 4) | ((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3);
    requestedCapacity = (v18 | (v18 >> 1)) + 1;
    if ( requestedCapacity < (v11->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v11->m_collisionEntries.m_data,
        16,
        0i64,
        requestedCapacity);
    ++m_collidable;
    ++m_agentIndexOnCollidable;
    --v10;
  }
  while ( v10 );
  hkAgentNnMachine_InternalDeallocateEntry(track, entry);
}

// File Line: 380
// RVA: 0xD42380
char __fastcall hkAgentNnMachine_IsEntryOnTrack(hkpAgentNnTrack *track, hkpAgentNnEntry *entry)
{
  __int64 m_size; // rdi
  __int64 v3; // r10
  hkpAgentNnSector **m_data; // r9
  int i; // r8d
  unsigned __int64 v7; // rcx
  int v8; // eax

  m_size = track->m_sectors.m_size;
  v3 = 0i64;
  if ( (int)m_size <= 0 )
    return 0;
  m_data = track->m_sectors.m_data;
  for ( i = 1; ; ++i )
  {
    v7 = (unsigned __int64)*m_data;
    v8 = i == (_DWORD)m_size ? track->m_bytesUsedInLastSector : 960;
    if ( v7 <= (unsigned __int64)entry && (unsigned __int64)entry < v7 + v8 )
      break;
    ++v3;
    ++m_data;
    if ( v3 >= m_size )
      return 0;
  }
  return 1;
}

// File Line: 396
// RVA: 0xD42400
void __fastcall hkAgentNnMachine_InternalDeallocateEntry(hkpAgentNnTrack *track, hkpAgentNnEntry *entry)
{
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *p_m_sectors; // rdi
  hkpAgentNnEntry *v4; // r10
  int v5; // r11d
  char *v6; // rax
  __int128 v7; // xmm0
  int v8; // r8d
  __int16 v9; // ax
  bool v10; // zf
  __int64 m_size; // r8
  hkpAgentNnSector *v12; // rbx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // edx
  unsigned int v15; // ecx
  int requestedCapacity; // eax

  p_m_sectors = &track->m_sectors;
  v4 = (hkpAgentNnEntry *)&track->m_sectors.m_data[track->m_sectors.m_size - 1]->m_data[track->m_bytesUsedInLastSector
                                                                                      - 80
                                                                                      * (unsigned __int8)track->m_nnTrackType.m_storage];
  if ( entry != v4 )
  {
    v5 = (5 * (unsigned __int8)track->m_nnTrackType.m_storage) & 0xFFFFFFF;
    v6 = (char *)((char *)entry - (char *)v4);
    do
    {
      v7 = *(_OWORD *)&v4->m_streamCommand;
      --v5;
      v4 = (hkpAgentNnEntry *)((char *)v4 + 16);
      *(_OWORD *)((char *)v4 + (_QWORD)v6 - 16) = v7;
    }
    while ( v5 > 0 );
    v8 = entry->m_agentIndexOnCollidable[1];
    entry->m_collidable[0]->m_collisionEntries.m_data[entry->m_agentIndexOnCollidable[0]].m_agentEntry = entry;
    entry->m_collidable[1]->m_collisionEntries.m_data[v8].m_agentEntry = entry;
  }
  v9 = -80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  v10 = v9 + track->m_bytesUsedInLastSector == 0;
  track->m_bytesUsedInLastSector += v9;
  if ( v10 )
  {
    m_size = track->m_sectors.m_size;
    v12 = p_m_sectors->m_data[m_size - 1];
    track->m_sectors.m_size = m_size - 1;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgentNnSector *, __int64))(*Value[11] + 16i64))(Value[11], v12, 960i64);
    track->m_bytesUsedInLastSector = 960;
  }
  m_capacityAndFlags = p_m_sectors->m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
  {
    v15 = ((((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 2) | ((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3);
    requestedCapacity = (v15 | (v15 >> 1)) + 1;
    if ( requestedCapacity >= 1 )
    {
      if ( requestedCapacity < (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_sectors->m_data,
          8,
          0i64,
          requestedCapacity);
    }
    else
    {
      hkArrayUtil::_reduce(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_sectors->m_data,
        8,
        (char *)p_m_sectors->m_storage,
        1);
    }
  }
}

// File Line: 420
// RVA: 0xD41580
void __fastcall hkAgentNnMachine_UpdateShapeCollectionFilter(
        hkpAgentNnEntry *entry,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  __int64 v3; // r12
  int m_streamCommand; // edi
  hkpLinkedCollidable *v5; // rbp
  hkpLinkedCollidable *v6; // r14
  int v7; // eax
  char *p_m_contactMgr; // rdx
  void (__fastcall *m_updateFilterFunc)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r10
  hkpCdBody v13; // [rsp+40h] [rbp-6A8h] BYREF
  hkpCdBody newCdBodies; // [rsp+C0h] [rbp-628h] BYREF
  hkMotionState newMotionStates; // [rsp+140h] [rbp-5A8h] BYREF
  hkMotionState v16; // [rsp+400h] [rbp-2E8h] BYREF
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+6F0h] [rbp+8h] BYREF
  __int64 v18; // [rsp+6F8h] [rbp+10h]

  m_streamCommand = (unsigned __int8)entry->m_streamCommand;
  v5 = entry->m_collidable[0];
  v6 = entry->m_collidable[1];
  v7 = m_streamCommand - 2;
  v18 = v3;
  while ( 2 )
  {
    switch ( v7 )
    {
      case 0:
      case 4:
        p_m_contactMgr = (char *)&entry[1].m_contactMgr;
        goto $callChildAgent;
      case 2:
        p_m_contactMgr = (char *)entry[1].m_collidable;
$callChildAgent:
        m_updateFilterFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_updateFilterFunc;
        if ( m_updateFilterFunc )
          m_updateFilterFunc(entry, p_m_contactMgr, v5, v6, input, entry->m_contactMgr, constraintOwner);
        break;
      case 8:
      case 10:
      case 12:
        v5 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                      v5,
                                      &newCdBodies,
                                      &newMotionStates,
                                      4,
                                      &cdBodyHasTransformFlag);
        m_streamCommand &= 0xF7u;
        v6 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(v6, &v13, &v16, 4, &cdBodyHasTransformFlag);
        v7 = m_streamCommand - 2;
        if ( (unsigned int)(m_streamCommand - 2) <= 0xC )
          continue;
        break;
      default:
        return;
    }
    break;
  }
}

// File Line: 477
// RVA: 0xD42660
void __fastcall hkAgentNnMachine_InvalidateTimInAgent(hkpAgentNnEntry *entry, hkpCollisionInput *input)
{
  void (__fastcall *m_invalidateTimFunc)(hkpAgentEntry *, void *, hkpCollisionInput *); // r11
  __int64 m_agentType; // rcx
  void (__fastcall *v5)(hkpAgentEntry *, void *, hkpCollisionInput *); // r11

  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      m_invalidateTimFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_invalidateTimFunc;
      if ( m_invalidateTimFunc )
        m_invalidateTimFunc(entry, &entry[1].m_contactMgr, input);
      break;
    case 4:
    case 0xC:
      m_agentType = (unsigned __int8)entry->m_agentType;
      entry[1].hkpAgentEntry = (hkpAgentEntry)-1082130432;
      *(_OWORD *)&entry[1].m_contactMgr = 0i64;
      v5 = input->m_dispatcher.m_storage->m_agent3Func[m_agentType].m_invalidateTimFunc;
      if ( v5 )
        v5(entry, entry[1].m_collidable, input);
      break;
    default:
      return;
  }
}

// File Line: 519
// RVA: 0xD42730
void __fastcall hkAgentNnMachine_WarpTimeInAgent(
        hkpAgentNnEntry *entry,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  void (__fastcall *m_warpTimeFunc)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r10
  char *p_m_contactMgr; // rdx

  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      m_warpTimeFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_warpTimeFunc;
      if ( m_warpTimeFunc )
      {
        p_m_contactMgr = (char *)&entry[1].m_contactMgr;
        goto LABEL_8;
      }
      break;
    case 4:
    case 0xC:
      p_m_contactMgr = (char *)entry[1].m_collidable;
      if ( oldTime == *(float *)&entry[1].hkpAgentEntry )
        *(float *)&entry[1].hkpAgentEntry = newTime;
      else
        entry[1].hkpAgentEntry = (hkpAgentEntry)-1082130432;
      m_warpTimeFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_warpTimeFunc;
      if ( m_warpTimeFunc )
LABEL_8:
        ((void (__fastcall *)(hkpAgentNnEntry *, char *))m_warpTimeFunc)(entry, p_m_contactMgr);
      break;
    default:
      return;
  }
}

// File Line: 571
// RVA: 0xD41410
void __fastcall hkAgentNnMachine_AppendTrack(hkpAgentNnTrack *track, hkpAgentNnTrack *appendee)
{
  __int16 v4; // ax
  bool v5; // zf
  __int64 m_size; // r8
  hkpAgentNnSector *v7; // rdi
  _QWORD **Value; // rax
  int m_capacityAndFlags; // edx
  unsigned int v10; // ecx
  int requestedCapacity; // eax

  while ( track->m_bytesUsedInLastSector != 960 )
  {
    if ( !appendee->m_sectors.m_size )
      break;
    hkAgentNnMachine_CopyAndRelinkAgentEntry(
      track,
      (hkpAgentNnEntry *)&appendee->m_sectors.m_data[appendee->m_sectors.m_size - 1]->m_data[appendee->m_bytesUsedInLastSector
                                                                                           - 80
                                                                                           * (unsigned __int8)appendee->m_nnTrackType.m_storage]);
    v4 = -80 * (unsigned __int8)appendee->m_nnTrackType.m_storage;
    v5 = v4 + appendee->m_bytesUsedInLastSector == 0;
    appendee->m_bytesUsedInLastSector += v4;
    if ( v5 )
    {
      m_size = appendee->m_sectors.m_size;
      v7 = appendee->m_sectors.m_data[m_size - 1];
      appendee->m_sectors.m_size = m_size - 1;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgentNnSector *, __int64))(*Value[11] + 16i64))(Value[11], v7, 960i64);
      appendee->m_bytesUsedInLastSector = 960;
    }
    m_capacityAndFlags = appendee->m_sectors.m_capacityAndFlags;
    if ( m_capacityAndFlags >= 0 )
    {
      v10 = ((((((((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 2) | ((((((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(appendee->m_sectors.m_size + 3) >> 16) | (appendee->m_sectors.m_size + 3);
      requestedCapacity = (v10 | (v10 >> 1)) + 1;
      if ( requestedCapacity >= 1 )
      {
        if ( requestedCapacity < (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reduce(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&appendee->m_sectors.m_data,
            8,
            0i64,
            requestedCapacity);
      }
      else
      {
        hkArrayUtil::_reduce(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&appendee->m_sectors.m_data,
          8,
          (char *)appendee->m_sectors.m_storage,
          1);
      }
    }
  }
  if ( appendee->m_sectors.m_size )
  {
    hkArrayBase<hkpEntity *>::_insertAt(
      (hkArrayBase<hkProcess *> *)&track->m_sectors,
      &hkContainerHeapAllocator::s_alloc,
      track->m_sectors.m_size,
      (hkProcess *const *)appendee->m_sectors.m_data,
      appendee->m_sectors.m_size);
    track->m_bytesUsedInLastSector = appendee->m_bytesUsedInLastSector;
    appendee->m_sectors.m_size = 0;
    appendee->m_bytesUsedInLastSector = 960;
  }
}

// File Line: 640
// RVA: 0xD42570
hkpAgentNnEntry *__fastcall hkAgentNnMachine_CopyAndRelinkAgentEntry(
        hkpAgentNnTrack *destTrack,
        hkpAgentNnEntry *entry)
{
  hkpAgentNnEntry *v2; // rbx
  hkpAgentNnEntry *v4; // r9
  int v5; // edx
  signed __int64 v6; // rax
  __int128 v7; // xmm0
  int v8; // r8d

  v2 = entry;
  v4 = hkAgentNnMachine_AllocateEntry(destTrack, (unsigned __int8)entry->m_forceCollideOntoPpu);
  v5 = (5 * (unsigned __int8)destTrack->m_nnTrackType.m_storage) & 0xFFFFFFF;
  v6 = (char *)v4 - (char *)v2;
  do
  {
    v7 = *(_OWORD *)&v2->m_streamCommand;
    --v5;
    v2 = (hkpAgentNnEntry *)((char *)v2 + 16);
    *(_OWORD *)((char *)v2 + v6 - 16) = v7;
  }
  while ( v5 > 0 );
  v8 = v4->m_agentIndexOnCollidable[1];
  v4->m_collidable[0]->m_collisionEntries.m_data[v4->m_agentIndexOnCollidable[0]].m_agentEntry = v4;
  v4->m_collidable[1]->m_collisionEntries.m_data[v8].m_agentEntry = v4;
  return v4;
}

// File Line: 660
// RVA: 0xD43370
void __fastcall hkAgentNnMachine_DestroyTrack(
        hkpAgentNnTrack *track,
        hkpCollisionDispatcher *dispatcher,
        hkpConstraintOwner *constraintOwner)
{
  while ( track->m_sectors.m_size )
    hkAgentNnMachine_DestroyAgent(
      track,
      (hkpAgentNnEntry *)&track->m_sectors.m_data[track->m_sectors.m_size - 1]->m_data[track->m_bytesUsedInLastSector
                                                                                     - 80
                                                                                     * (unsigned __int8)track->m_nnTrackType.m_storage],
      dispatcher,
      constraintOwner);
}

// File Line: 692
// RVA: 0xD416F0
void __fastcall hkAgentNnMachine_ProcessAgent(
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        hkpContactMgr *mgr)
{
  __int64 v4; // r12
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int m_streamCommand; // esi
  hkpLinkedCollidable *v14; // r14
  hkpLinkedCollidable *v15; // r15
  int v16; // eax
  hkpContactMgr *m_contactMgr; // rax
  hkTransformf *m_motion; // rdx
  hkTransformf *v19; // r8
  __m128 m_quad; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  char *p_m_contactMgr; // r8
  hkVector4f *v26; // r9
  hkpContactMgr *v27; // r8
  hkTransformf *v28; // rcx
  hkTransformf *v29; // r12
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  __m128 v34; // xmm5
  float m_storage; // xmm1_4
  bool v36; // zf
  __m128 v37; // xmm6
  __m128 *v38; // rsi
  __m128 v39; // xmm2
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  int m_shapeKey; // ecx
  int v46; // ecx
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  hkTransformf *v51; // [rsp+30h] [rbp-C8h]
  hkpLinkedCollidable *v52; // [rsp+40h] [rbp-B8h] BYREF
  hkpLinkedCollidable *v53; // [rsp+48h] [rbp-B0h]
  __int64 v54; // [rsp+50h] [rbp-A8h]
  hkpProcessCollisionInput *v55; // [rsp+58h] [rbp-A0h]
  hkpContactMgr *v56; // [rsp+60h] [rbp-98h]
  hkTransformf v57; // [rsp+70h] [rbp-88h] BYREF
  __m128 v58; // [rsp+B8h] [rbp-40h]
  hkpShape *m_shape; // [rsp+C8h] [rbp-30h] BYREF
  int v60; // [rsp+D0h] [rbp-28h]
  hkTransformf *p_transformOut; // [rsp+D8h] [rbp-20h]
  hkpLinkedCollidable *v62; // [rsp+E0h] [rbp-18h]
  hkpShape *v63; // [rsp+E8h] [rbp-10h] BYREF
  int v64; // [rsp+F0h] [rbp-8h]
  hkTransformf *p_bTc; // [rsp+F8h] [rbp+0h]
  hkpLinkedCollidable *v66; // [rsp+100h] [rbp+8h]
  hkTransformf transformOut; // [rsp+108h] [rbp+10h] BYREF
  hkTransformf bTc; // [rsp+148h] [rbp+50h] BYREF
  __int64 v69[6]; // [rsp+188h] [rbp+90h] BYREF
  hkTransformf v70; // [rsp+1B8h] [rbp+C0h] BYREF
  hkpCdBody v71; // [rsp+1F8h] [rbp+100h] BYREF
  hkpCdBody newCdBodies; // [rsp+278h] [rbp+180h] BYREF
  hkMotionState newMotionStates; // [rsp+2F8h] [rbp+200h] BYREF
  hkMotionState v74; // [rsp+5B8h] [rbp+4C0h] BYREF
  __int64 v75; // [rsp+8A8h] [rbp+7B0h]
  void *cdBodyHasTransformFlag; // [rsp+8B8h] [rbp+7C0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtProcessNnEntry";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_streamCommand = (unsigned __int8)entry->m_streamCommand;
  v14 = entry->m_collidable[0];
  v15 = entry->m_collidable[1];
  v16 = m_streamCommand - 2;
  v75 = v4;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0:
        m_contactMgr = entry->m_contactMgr;
        v52 = v14;
        v53 = v15;
        v55 = input;
        v56 = m_contactMgr;
        v54 = 0i64;
        m_motion = (hkTransformf *)v14->m_motion;
        v19 = (hkTransformf *)v15->m_motion;
        m_quad = m_motion[1].m_rotation.m_col1.m_quad;
        v21 = v19[1].m_rotation.m_col1.m_quad;
        v22 = _mm_shuffle_ps(
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                0);
        v23 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v22);
        v24 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v22);
        v58 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(m_motion[1].m_rotation.m_col0.m_quad, m_quad), v23),
                _mm_mul_ps(_mm_sub_ps(v21, v19[1].m_rotation.m_col0.m_quad), v24));
        v58 = _mm_shuffle_ps(
                v58,
                _mm_unpackhi_ps(
                  v58,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(m_motion[2].m_rotation.m_col1.m_quad, m_motion[2].m_rotation.m_col1.m_quad, 255),
                        v23),
                      _mm_shuffle_ps(
                        (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v19[2].m_rotation.m_col1.m_quad, v19[2].m_rotation.m_col1.m_quad, 255),
                        v24),
                      _mm_shuffle_ps(
                        (__m128)v19[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v19[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)))),
                196);
        hkTransformf::setMulInverseMul(&v57, m_motion, v19);
        p_m_contactMgr = (char *)&entry[1].m_contactMgr;
        v26 = 0i64;
        goto LABEL_13;
      case 2:
        v27 = entry->m_contactMgr;
        v52 = v14;
        v53 = v15;
        v55 = input;
        v56 = v27;
        v54 = 0i64;
        v28 = (hkTransformf *)v15->m_motion;
        v29 = (hkTransformf *)v14->m_motion;
        v51 = v28;
        v30 = v29[1].m_rotation.m_col1.m_quad;
        v31 = v28[1].m_rotation.m_col1.m_quad;
        v32 = _mm_shuffle_ps(
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                0);
        v33 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v32);
        v34 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v32);
        v58 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v31, v28[1].m_rotation.m_col0.m_quad), v33),
                _mm_mul_ps(_mm_sub_ps(v29[1].m_rotation.m_col0.m_quad, v30), v34));
        m_storage = input->m_stepInfo.m_startTime.m_storage;
        v36 = m_storage == *(float *)&entry[1].hkpAgentEntry;
        v37 = _mm_shuffle_ps(
                v58,
                _mm_unpackhi_ps(
                  v58,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v28[2].m_rotation.m_col1.m_quad, v28[2].m_rotation.m_col1.m_quad, 255),
                        v33),
                      _mm_shuffle_ps(
                        (__m128)v28[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v28[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v29[2].m_rotation.m_col1.m_quad, v29[2].m_rotation.m_col1.m_quad, 255),
                        v34),
                      _mm_shuffle_ps(
                        (__m128)v29[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v29[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)))),
                196);
        v58 = v37;
        if ( v36 )
          goto LABEL_18;
        if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
        {
          v69[2] = 0i64;
          hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v14->m_motion + 64), m_storage, &transformOut);
          hkSweptTransformUtil::lerp2(
            (hkSweptTransformf *)((char *)v53->m_motion + 64),
            v55->m_stepInfo.m_startTime.m_storage,
            &bTc);
          v69[0] = (__int64)&m_shape;
          v69[1] = (__int64)&v63;
          v69[4] = (__int64)v56;
          v69[3] = (__int64)v55;
          m_shapeKey = v52->m_shapeKey;
          m_shape = v52->m_shape;
          v60 = m_shapeKey;
          v46 = v53->m_shapeKey;
          v63 = v53->m_shape;
          p_transformOut = &transformOut;
          v62 = v52;
          v66 = v53;
          v64 = v46;
          p_bTc = &bTc;
          hkTransformf::setMulInverseMul(&v70, &transformOut, &bTc);
          input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_sepNormalFunc(
            (hkpAgent3Input *)v69,
            entry,
            entry[1].m_collidable,
            (hkVector4f *)&entry[1].m_contactMgr);
          v27 = v56;
          v28 = v51;
          v37 = v58;
LABEL_18:
          v47 = *(__m128 *)&entry[1].m_contactMgr;
          v38 = (__m128 *)&entry[1].m_contactMgr;
          entry[1].hkpAgentEntry = (hkpAgentEntry)LODWORD(input->m_stepInfo.m_endTime.m_storage);
          v48 = _mm_mul_ps(v37, v47);
          v49 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v37), 196);
          v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
          v39 = _mm_sub_ps(_mm_shuffle_ps(v47, v47, 255), _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50));
          if ( v39.m128_f32[0] >= _mm_shuffle_ps(
                                    (__m128)LODWORD(input->m_tolerance.m_storage),
                                    (__m128)LODWORD(input->m_tolerance.m_storage),
                                    0).m128_f32[0] )
          {
            v36 = entry->m_numContactPoints == 0;
            *v38 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v39), 196);
            if ( !v36 )
              input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_cleanupFunc(
                entry,
                entry[1].m_collidable,
                v27,
                output->m_constraintOwner.m_storage);
            goto LABEL_14;
          }
        }
        else
        {
          v38 = (__m128 *)&entry[1].m_contactMgr;
          entry[1].hkpAgentEntry = (hkpAgentEntry)LODWORD(input->m_stepInfo.m_endTime.m_storage);
          v39.m128_i32[0] = -8388626;
          *(__m128 *)&entry[1].m_contactMgr = _mm_shuffle_ps(
                                                aabbOut.m_quad,
                                                _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                                196);
        }
        v57.m_translation.m_quad.m128_i32[2] = v39.m128_i32[0];
        hkTransformf::setMulInverseMul(&v57, v29, v28);
        v26 = (hkVector4f *)v38;
        p_m_contactMgr = (char *)entry[1].m_collidable;
LABEL_13:
        input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_processFunc(
          (hkpAgent3ProcessInput *)&v52,
          entry,
          p_m_contactMgr,
          v26,
          output);
LABEL_14:
        v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v41 = (_QWORD *)v40[1];
        v42 = v40;
        if ( (unsigned __int64)v41 < v40[3] )
        {
          *v41 = "Et";
          v43 = __rdtsc();
          v44 = v41 + 2;
          *((_DWORD *)v44 - 2) = v43;
          v42[1] = v44;
        }
        return;
      case 4:
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))entry[1].m_contactMgr->vfptr[3].__vecDelDtor)(
          entry[1].m_contactMgr,
          v14,
          v15,
          input,
          output);
        goto LABEL_14;
      case 8:
      case 10:
      case 12:
        v14 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                       v14,
                                       &newCdBodies,
                                       &newMotionStates,
                                       4,
                                       (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        m_streamCommand &= 0xF7u;
        v15 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                       v15,
                                       &v71,
                                       &v74,
                                       4,
                                       (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v16 = m_streamCommand - 2;
        if ( (unsigned int)(m_streamCommand - 2) <= 0xC )
          continue;
        goto LABEL_14;
      default:
        goto LABEL_14;
    }
  }
}                      4,
                                       (hkPad

// File Line: 699
// RVA: 0xD41C90
void __fastcall hkAgentNnMachine_ProcessTrack(
        hkpConstraintOwner *owner,
        hkpAgentNnTrack *agentTrack,
        hkpProcessCollisionInput *input)
{
  int v3; // edi
  hkpAgentNnTrack *v5; // r8
  int m_size; // ecx
  int v7; // edx
  __int64 v8; // r9
  unsigned __int8 *v9; // rbx
  unsigned __int8 *v10; // r12
  __int64 v11; // r13
  _QWORD *Value; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  int v16; // edi
  hkpCdBody *v17; // rsi
  hkpCdBody *v18; // r14
  int v19; // eax
  __int64 v20; // rax
  hkTransformf *m_motion; // rdx
  hkTransformf *v22; // r8
  __m128 m_quad; // xmm1
  __m128 v24; // xmm6
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  void *v28; // r8
  hkVector4f *v29; // r9
  hkpContactMgr *v30; // r8
  hkTransformf *v31; // rcx
  hkTransformf *v32; // rdx
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm5
  float m_storage; // xmm1_4
  bool v39; // zf
  __m128 v40; // xmm6
  __m128 *v41; // rdi
  __m128 v42; // xmm2
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  _QWORD *v47; // rax
  unsigned __int64 v48; // rcx
  unsigned __int64 v49; // rcx
  int m_shapeKey; // ecx
  int v51; // ecx
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  int v56; // [rsp+30h] [rbp-D0h]
  __int64 v57; // [rsp+38h] [rbp-C8h]
  __int64 v58; // [rsp+40h] [rbp-C0h]
  hkTransformf *v59; // [rsp+48h] [rbp-B8h]
  hkTransformf *v60; // [rsp+50h] [rbp-B0h]
  hkpCdBody *v61; // [rsp+60h] [rbp-A0h] BYREF
  hkpCdBody *v62; // [rsp+68h] [rbp-98h]
  __int64 v63; // [rsp+70h] [rbp-90h]
  hkpProcessCollisionInput *v64; // [rsp+78h] [rbp-88h]
  hkpContactMgr *v65; // [rsp+80h] [rbp-80h]
  hkTransformf v66; // [rsp+90h] [rbp-70h] BYREF
  int v67; // [rsp+D0h] [rbp-30h]
  __m128 v68; // [rsp+E0h] [rbp-20h]
  hkpShape *m_shape; // [rsp+F0h] [rbp-10h] BYREF
  int v70; // [rsp+F8h] [rbp-8h]
  hkTransformf *p_transformOut; // [rsp+100h] [rbp+0h]
  hkpCdBody *v72; // [rsp+108h] [rbp+8h]
  hkpShape *v73; // [rsp+110h] [rbp+10h] BYREF
  int v74; // [rsp+118h] [rbp+18h]
  hkTransformf *p_bTc; // [rsp+120h] [rbp+20h]
  hkpCdBody *v76; // [rsp+128h] [rbp+28h]
  hkTransformf transformOut; // [rsp+130h] [rbp+30h] BYREF
  hkTransformf bTc; // [rsp+170h] [rbp+70h] BYREF
  __int64 v79[6]; // [rsp+1B0h] [rbp+B0h] BYREF
  hkTransformf v80; // [rsp+1E0h] [rbp+E0h] BYREF
  hkpCdBody newCdBodies; // [rsp+220h] [rbp+120h] BYREF
  hkpCdBody v82; // [rsp+2A0h] [rbp+1A0h] BYREF
  hkMotionState newMotionStates; // [rsp+320h] [rbp+220h] BYREF
  hkMotionState v84; // [rsp+5E0h] [rbp+4E0h] BYREF
  char *v85; // [rsp+8A0h] [rbp+7A0h] BYREF
  hkpConstraintOwner *v86; // [rsp+8A8h] [rbp+7A8h]
  char v87[12320]; // [rsp+8B0h] [rbp+7B0h] BYREF
  int v88; // [rsp+38D0h] [rbp+37D0h]
  __int64 v89; // [rsp+38F0h] [rbp+37F0h]
  __int64 v90; // [rsp+3930h] [rbp+3830h]
  float cdBodyHasTransformFlag; // [rsp+3990h] [rbp+3890h] BYREF
  hkpAgentNnTrack *v92; // [rsp+3998h] [rbp+3898h]
  int v93; // [rsp+39A8h] [rbp+38A8h]

  v92 = agentTrack;
  v3 = 0;
  v5 = agentTrack;
  v86 = owner;
  m_size = agentTrack->m_sectors.m_size;
  v7 = 0;
  v93 = 0;
  v88 = 2139095022;
  v89 = 0i64;
  if ( m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      ++v7;
      v8 += 8i64;
      v9 = *(unsigned __int8 **)((char *)v5->m_sectors.m_data + v8 - 8);
      v58 = v8;
      v56 = v7;
      if ( v7 == m_size )
        v10 = &v9[v5->m_bytesUsedInLastSector];
      else
        v10 = v9 + 960;
      if ( v9 < v10 )
      {
        while ( 2 )
        {
          v11 = *((_QWORD *)v9 + 3);
          v57 = *((_QWORD *)v9 + 4);
          v85 = v87;
          v88 = 2139095022;
          v90 = 0i64;
          _mm_prefetch(*((const char **)v9 + 1), 0);
          _mm_prefetch((const char *)v9 + 128, 0);
          Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v13 = (_QWORD *)Value[1];
          if ( (unsigned __int64)v13 < Value[3] )
          {
            *v13 = "TtProcessNnEntry";
            v14 = __rdtsc();
            v15 = v13 + 2;
            *((_DWORD *)v15 - 2) = v14;
            Value[1] = v15;
          }
          v16 = *v9;
          v17 = (hkpCdBody *)*((_QWORD *)v9 + 3);
          v18 = (hkpCdBody *)*((_QWORD *)v9 + 4);
          v19 = v16 - 2;
LABEL_10:
          switch ( v19 )
          {
            case 0:
              v20 = *((_QWORD *)v9 + 1);
              v61 = v17;
              v62 = v18;
              v64 = input;
              v65 = (hkpContactMgr *)v20;
              v63 = 0i64;
              m_motion = (hkTransformf *)v17->m_motion;
              v22 = (hkTransformf *)v18->m_motion;
              cdBodyHasTransformFlag = input->m_stepInfo.m_deltaTime.m_storage;
              m_quad = m_motion[1].m_rotation.m_col1.m_quad;
              v24 = v22[1].m_rotation.m_col1.m_quad;
              v25 = _mm_shuffle_ps((__m128)LODWORD(cdBodyHasTransformFlag), (__m128)LODWORD(cdBodyHasTransformFlag), 0);
              v26 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 255), v25);
              v27 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v25);
              v68 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v24, v22[1].m_rotation.m_col0.m_quad), v26),
                      _mm_mul_ps(_mm_sub_ps(m_motion[1].m_rotation.m_col0.m_quad, m_quad), v27));
              v68 = _mm_shuffle_ps(
                      v68,
                      _mm_unpackhi_ps(
                        v68,
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(
                                m_motion[2].m_rotation.m_col1.m_quad,
                                m_motion[2].m_rotation.m_col1.m_quad,
                                255),
                              v27),
                            _mm_shuffle_ps(
                              (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v22[2].m_rotation.m_col1.m_quad, v22[2].m_rotation.m_col1.m_quad, 255),
                              v26),
                            _mm_shuffle_ps(
                              (__m128)v22[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v22[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)))),
                      196);
              hkTransformf::setMulInverseMul(&v66, m_motion, v22);
              v28 = v9 + 48;
              v29 = 0i64;
              goto LABEL_19;
            case 2:
              v30 = (hkpContactMgr *)*((_QWORD *)v9 + 1);
              v61 = v17;
              v62 = v18;
              v64 = input;
              v65 = v30;
              v63 = 0i64;
              v31 = (hkTransformf *)v17->m_motion;
              v32 = (hkTransformf *)v18->m_motion;
              cdBodyHasTransformFlag = input->m_stepInfo.m_deltaTime.m_storage;
              v60 = v31;
              v59 = v32;
              v33 = v31[1].m_rotation.m_col1.m_quad;
              v34 = v32[1].m_rotation.m_col1.m_quad;
              v35 = _mm_shuffle_ps((__m128)LODWORD(cdBodyHasTransformFlag), (__m128)LODWORD(cdBodyHasTransformFlag), 0);
              v36 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), v35);
              v37 = _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), v35);
              v68 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v31[1].m_rotation.m_col0.m_quad, v33), v36),
                      _mm_mul_ps(_mm_sub_ps(v34, v32[1].m_rotation.m_col0.m_quad), v37));
              m_storage = input->m_stepInfo.m_startTime.m_storage;
              v39 = m_storage == *((float *)v9 + 10);
              v40 = _mm_shuffle_ps(
                      v68,
                      _mm_unpackhi_ps(
                        v68,
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v31[2].m_rotation.m_col1.m_quad, v31[2].m_rotation.m_col1.m_quad, 255),
                              v36),
                            _mm_shuffle_ps(
                              (__m128)v31[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v31[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v32[2].m_rotation.m_col1.m_quad, v32[2].m_rotation.m_col1.m_quad, 255),
                              v37),
                            _mm_shuffle_ps(
                              (__m128)v32[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v32[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)))),
                      196);
              v68 = v40;
              if ( v39 )
                goto LABEL_33;
              if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
              {
                v79[2] = 0i64;
                hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v17->m_motion + 64), m_storage, &transformOut);
                hkSweptTransformUtil::lerp2(
                  (hkSweptTransformf *)((char *)v62->m_motion + 64),
                  v64->m_stepInfo.m_startTime.m_storage,
                  &bTc);
                v79[0] = (__int64)&m_shape;
                v79[1] = (__int64)&v73;
                v79[4] = (__int64)v65;
                v79[3] = (__int64)v64;
                m_shapeKey = v61->m_shapeKey;
                m_shape = v61->m_shape;
                v70 = m_shapeKey;
                v51 = v62->m_shapeKey;
                v73 = v62->m_shape;
                p_transformOut = &transformOut;
                v72 = v61;
                v76 = v62;
                v74 = v51;
                p_bTc = &bTc;
                hkTransformf::setMulInverseMul(&v80, &transformOut, &bTc);
                input->m_dispatcher.m_storage->m_agent3Func[v9[1]].m_sepNormalFunc(
                  (hkpAgent3Input *)v79,
                  (hkpAgentEntry *)v9,
                  v9 + 64,
                  (hkVector4f *)(v9 + 48));
                v30 = v65;
                v31 = v60;
                v40 = v68;
                v32 = v59;
LABEL_33:
                v52 = *((__m128 *)v9 + 3);
                v41 = (__m128 *)(v9 + 48);
                *((_DWORD *)v9 + 10) = LODWORD(input->m_stepInfo.m_endTime.m_storage);
                v53 = _mm_mul_ps(v40, v52);
                v54 = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, v40), 196);
                v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 78), v54);
                v42 = _mm_sub_ps(_mm_shuffle_ps(v52, v52, 255), _mm_add_ps(_mm_shuffle_ps(v55, v55, 177), v55));
                cdBodyHasTransformFlag = input->m_tolerance.m_storage;
                if ( v42.m128_f32[0] >= _mm_shuffle_ps(
                                          (__m128)LODWORD(cdBodyHasTransformFlag),
                                          (__m128)LODWORD(cdBodyHasTransformFlag),
                                          0).m128_f32[0] )
                {
                  v39 = v9[2] == 0;
                  *v41 = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, v42), 196);
                  if ( !v39 )
                    input->m_dispatcher.m_storage->m_agent3Func[v9[1]].m_cleanupFunc(
                      (hkpAgentEntry *)v9,
                      v9 + 64,
                      v30,
                      v86);
                  v3 = ++v93;
                  goto LABEL_21;
                }
              }
              else
              {
                v41 = (__m128 *)(v9 + 48);
                *((_DWORD *)v9 + 10) = LODWORD(input->m_stepInfo.m_endTime.m_storage);
                v42.m128_i32[0] = -8388626;
                *((__m128 *)v9 + 3) = _mm_shuffle_ps(
                                        aabbOut.m_quad,
                                        _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                        196);
              }
              v67 = v42.m128_i32[0];
              hkTransformf::setMulInverseMul(&v66, v31, v32);
              v29 = (hkVector4f *)v41;
              v28 = v9 + 64;
LABEL_19:
              input->m_dispatcher.m_storage->m_agent3Func[v9[1]].m_processFunc(
                (hkpAgent3ProcessInput *)&v61,
                (hkpAgentEntry *)v9,
                v28,
                v29,
                (hkpProcessCollisionOutput *)&v85);
LABEL_20:
              v3 = v93;
LABEL_21:
              v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
              v44 = (_QWORD *)v43[1];
              if ( (unsigned __int64)v44 < v43[3] )
              {
                *v44 = "Et";
                v45 = __rdtsc();
                v46 = v44 + 2;
                *((_DWORD *)v46 - 2) = v45;
                v43[1] = v46;
              }
              if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
                return;
              if ( v85 != v87 )
                (*(void (__fastcall **)(_QWORD, __int64, __int64, hkpProcessCollisionInput *, char **))(**((_QWORD **)v9 + 1) + 48i64))(
                  *((_QWORD *)v9 + 1),
                  v11,
                  v57,
                  input,
                  &v85);
              v9 += v9[3];
              if ( v9 < v10 )
                continue;
              v7 = v56;
              v5 = v92;
              v8 = v58;
              break;
            case 4:
              (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, char **))(**((_QWORD **)v9 + 6) + 48i64))(
                *((_QWORD *)v9 + 6),
                v17,
                v18,
                input,
                &v85);
              goto LABEL_20;
            case 8:
            case 10:
            case 12:
              v17 = hkAgentMachine_processTransformedShapes(
                      v17,
                      &newCdBodies,
                      &newMotionStates,
                      4,
                      (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
              v16 &= 0xF7u;
              v18 = hkAgentMachine_processTransformedShapes(
                      v18,
                      &v82,
                      &v84,
                      4,
                      (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
              v19 = v16 - 2;
              if ( (unsigned int)(v16 - 2) <= 0xC )
                goto LABEL_10;
              goto LABEL_20;
            default:
              goto LABEL_20;
          }
          break;
        }
      }
      m_size = v5->m_sectors.m_size;
    }
    while ( v7 < m_size );
  }
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = v47[1];
  if ( v48 < v47[3] )
  {
    v49 = v48 + 16;
    *(_QWORD *)(v49 - 16) = "MinumTim";
    *(float *)(v49 - 8) = (float)v3;
    v47[1] = v49;
  }
}

// File Line: 736
// RVA: 0xD42600
hkpAgentNnEntry *__fastcall hkAgentNnMachine_FindAgent(hkpLinkedCollidable *collA, hkpLinkedCollidable *collB)
{
  hkpLinkedCollidable *v2; // r8
  hkpLinkedCollidable *v3; // rax
  __int64 m_size; // r9
  int v5; // edx
  __int64 v6; // rcx
  hkpLinkedCollidable::CollisionEntry *m_data; // r10
  hkpLinkedCollidable **i; // rax

  v2 = collB;
  if ( collA->m_collisionEntries.m_size > collB->m_collisionEntries.m_size )
  {
    v3 = collB;
    v2 = collA;
  }
  else
  {
    v3 = collA;
  }
  m_size = v3->m_collisionEntries.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  m_data = v3->m_collisionEntries.m_data;
  for ( i = &m_data->m_partner; *i != v2; i += 2 )
  {
    ++v6;
    ++v5;
    if ( v6 >= m_size )
      return 0i64;
  }
  return m_data[v5].m_agentEntry;
}

// File Line: 771
// RVA: 0xD40EF0
void __fastcall hkAgentNnMachine_AssertTrackValidity(hkpAgentNnTrack *track)
{
  __int64 m_size; // rbx
  int v2; // r8d
  __int64 v3; // r10
  hkpAgentNnSector **m_data; // r9
  hkpAgentNnSector *v5; // rax
  hkpAgentNnSector *v6; // rdx

  m_size = track->m_sectors.m_size;
  v2 = 0;
  v3 = m_size;
  if ( (int)m_size > 0 )
  {
    m_data = track->m_sectors.m_data;
    do
    {
      v5 = *m_data;
      ++v2;
      ++m_data;
      if ( v2 == (_DWORD)m_size )
        v6 = (hkpAgentNnSector *)((char *)v5 + track->m_bytesUsedInLastSector);
      else
        v6 = v5 + 1;
      for ( ; v5 < v6; v5 = (hkpAgentNnSector *)((char *)v5 + (unsigned __int8)v5->m_data[3]) )
        ;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 822
// RVA: 0xD42810
hkpCdBody *__fastcall hkAgentMachine_processTransformedShapes(
        hkpCdBody *cdBody,
        hkpCdBody *newCdBodies,
        hkMotionState *newMotionStates,
        int numSlots,
        hkPadSpu<unsigned char> *cdBodyHasTransformFlag)
{
  hkpShape *m_shape; // r10
  hkpCdBody *v6; // r9
  hkQuaternionf *p_m_rotation0; // rbx
  hkQuaternionf *m_motion; // r11
  __int64 v9; // rcx
  __m128 *v10; // rax
  __m128 m_quad; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm3
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm6
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  hkpShape *v35; // rax

  m_shape = cdBody->m_shape;
  v6 = cdBody;
  if ( cdBody->m_shape->m_type.m_storage == 14 )
  {
    p_m_rotation0 = &newMotionStates->m_sweptTransform.m_rotation0;
    do
    {
      m_motion = (hkQuaternionf *)v6->m_motion;
      v9 = 3i64;
      v10 = (__m128 *)&m_shape[4];
      m_quad = m_motion->m_vec.m_quad;
      v12 = m_motion[1].m_vec.m_quad;
      v13 = m_motion[2].m_vec.m_quad;
      do
      {
        v14 = *v10--;
        --v9;
        *(__m128 *)((char *)v10 + (char *)&p_m_rotation0[-6] - (char *)&m_shape[2].m_type + 16) = _mm_add_ps(
                                                                                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v12), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), m_quad)),
                                                                                                    _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v13));
      }
      while ( v9 >= 0 );
      p_m_rotation0[-3].m_vec.m_quad = _mm_add_ps(m_motion[3].m_vec.m_quad, p_m_rotation0[-3].m_vec.m_quad);
      p_m_rotation0[-2] = (hkQuaternionf)m_motion[4].m_vec.m_quad;
      p_m_rotation0[-1] = (hkQuaternionf)m_motion[5].m_vec.m_quad;
      v15 = m_motion[6].m_vec.m_quad;
      v16 = (__m128)m_shape[2].hkReferencedObject;
      v17 = _mm_shuffle_ps(v16, v16, 255);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v19 = _mm_mul_ps(v16, v15);
      v20 = _mm_shuffle_ps(v15, v15, 255);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps((__m128)m_shape[2].hkReferencedObject, v20)),
              _mm_mul_ps(v17, v15));
      p_m_rotation0->m_vec.m_quad = _mm_shuffle_ps(
                                      v21,
                                      _mm_unpackhi_ps(
                                        v21,
                                        _mm_sub_ps(
                                          _mm_mul_ps(v17, v20),
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                            _mm_shuffle_ps(v19, v19, 170)))),
                                      196);
      v22 = m_motion[7].m_vec.m_quad;
      v23 = (__m128)m_shape[2].hkReferencedObject;
      v24 = _mm_shuffle_ps(v22, v22, 255);
      v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
      v26 = _mm_shuffle_ps(v23, v23, 255);
      v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22);
      v28 = _mm_mul_ps(v22, v23);
      v29 = _mm_sub_ps(v27, v25);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v23, v24)),
              _mm_mul_ps(m_motion[7].m_vec.m_quad, v26));
      p_m_rotation0[1].m_vec.m_quad = _mm_shuffle_ps(
                                        v30,
                                        _mm_unpackhi_ps(
                                          v30,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v26, v24),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                                              _mm_shuffle_ps(v28, v28, 170)))),
                                        196);
      v31 = _mm_sub_ps(m_motion[8].m_vec.m_quad, (__m128)m_shape[4].hkReferencedObject);
      v32 = *(__m128 *)&m_shape[3].m_type.m_storage;
      v33 = _mm_unpacklo_ps(*(__m128 *)&m_shape[2].m_type.m_storage, (__m128)m_shape[3].hkReferencedObject);
      v34 = _mm_movelh_ps(v33, v32);
      p_m_rotation0[2].m_vec.m_quad = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(v31, v31, 85),
                                            _mm_shuffle_ps(_mm_movehl_ps(v34, v33), v32, 212)),
                                          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v34)),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(v31, v31, 170),
                                          _mm_shuffle_ps(
                                            _mm_unpackhi_ps(
                                              *(__m128 *)&m_shape[2].m_type.m_storage,
                                              (__m128)m_shape[3].hkReferencedObject),
                                            v32,
                                            228)));
      p_m_rotation0[3] = (hkQuaternionf)m_motion[9].m_vec.m_quad;
      p_m_rotation0[4].m_vec.m_quad.m128_i32[0] = m_motion[10].m_vec.m_quad.m128_i32[0];
      if ( newCdBodies )
      {
        newCdBodies->m_parent = v6;
        newCdBodies->m_motion = &p_m_rotation0[-6];
      }
      v35 = *(hkpShape **)&m_shape[1].m_memSizeAndFlags;
      newCdBodies->m_shapeKey = 0;
      v6 = newCdBodies;
      newCdBodies->m_shape = v35;
      m_shape = newCdBodies->m_shape;
      ++newCdBodies;
      p_m_rotation0 += 11;
      cdBodyHasTransformFlag->m_storage = 8;
    }
    while ( m_shape->m_type.m_storage == 14 );
  }
  return v6;
}

// File Line: 888
// RVA: 0xD42800
void __fastcall hkAgentNnMachine_TouchAgent(hkpAgentEntry *entry, hkpProcessCollisionInput *input)
{
  ;
}

