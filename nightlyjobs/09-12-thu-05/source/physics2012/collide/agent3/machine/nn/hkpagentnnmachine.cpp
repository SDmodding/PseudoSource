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
  int v1; // er9

  v1 = entry->m_agentIndexOnCollidable[1];
  entry->m_collidable[0]->m_collisionEntries.m_data[entry->m_agentIndexOnCollidable[0]].m_agentEntry = entry;
  entry->m_collidable[1]->m_collisionEntries.m_data[v1].m_agentEntry = entry;
}

// File Line: 80
// RVA: 0xD431A0
hkpAgentNnEntry *__fastcall hkAgentNnMachine_AllocateEntry(hkpAgentNnTrack *track, int forcePpuEntry)
{
  unsigned __int16 v2; // r9
  hkpAgentNnTrack *v3; // rbx
  hkpAgentNnEntry *result; // rax
  _QWORD **v5; // rax
  hkpAgentNnEntry *v6; // rsi

  v2 = track->m_bytesUsedInLastSector;
  v3 = track;
  if ( track->m_bytesUsedInLastSector >= 0x3C0u )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkpAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 960i64);
    if ( v3->m_sectors.m_size == (v3->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_sectors, 8);
    result = v6;
    v3->m_sectors.m_data[v3->m_sectors.m_size++] = (hkpAgentNnSector *)v6;
    v3->m_bytesUsedInLastSector = 80 * (unsigned __int8)v3->m_nnTrackType.m_storage;
  }
  else
  {
    result = (hkpAgentNnEntry *)&track->m_sectors.m_data[track->m_sectors.m_size - 1]->m_data[v2];
    track->m_bytesUsedInLastSector = v2 + 80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  }
  return result;
}

// File Line: 145
// RVA: 0xD43280
void __fastcall hkAgentNnMachine_DeallocateLastEntry(hkpAgentNnTrack *track, int ppuEntry)
{
  hkpAgentNnTrack *v2; // rdi
  __int16 v3; // ax
  bool v4; // zf
  __int64 v5; // r8
  hkpAgentNnSector *v6; // rbx
  _QWORD **v7; // rax
  int v8; // er8
  unsigned int v9; // ecx
  int requestedCapacity; // eax

  v2 = track;
  v3 = -80 * (unsigned __int8)track->m_nnTrackType.m_storage;
  v4 = v3 + track->m_bytesUsedInLastSector == 0;
  v2->m_bytesUsedInLastSector += v3;
  if ( v4 )
  {
    v5 = track->m_sectors.m_size;
    v6 = track->m_sectors.m_data[v5 - 1];
    track->m_sectors.m_size = v5 - 1;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgentNnSector *, signed __int64))(*v7[11] + 16i64))(v7[11], v6, 960i64);
    v2->m_bytesUsedInLastSector = 960;
  }
  v8 = v2->m_sectors.m_capacityAndFlags;
  if ( v8 >= 0 )
  {
    v9 = ((((((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 2) | ((((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3);
    requestedCapacity = (v9 | (v9 >> 1)) + 1;
    if ( requestedCapacity >= 1 )
    {
      if ( requestedCapacity < (v8 & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v2->m_sectors,
          8,
          0i64,
          requestedCapacity);
    }
    else
    {
      hkArrayUtil::_reduce(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_sectors,
        8,
        (char *)v2->m_sectors.m_storage,
        1);
    }
  }
}

// File Line: 201
// RVA: 0xD40F60
void __fastcall hkAgentNnMachine_GetAgentType(hkpCdBody *cdBodyA, hkpCdBody *cdBodyB, hkpProcessCollisionInput *input, int *agentTypeOut, int *isFlippedOut)
{
  hkpCollisionDispatcher *v5; // r10
  __int64 v6; // rcx
  int *v7; // rbx
  __int64 v8; // rdx
  hkpProcessCollisionInput *v9; // rdi
  __int64 v10; // r11
  unsigned __int8 *v11; // rcx
  int v12; // er9
  int v13; // er8
  signed __int64 v14; // rdx
  int v15; // eax

  v5 = input->m_dispatcher.m_storage;
  v6 = (unsigned __int8)cdBodyA->m_shape->m_type.m_storage;
  v7 = agentTypeOut;
  v8 = (unsigned __int8)cdBodyB->m_shape->m_type.m_storage;
  v9 = input;
  if ( input->m_createPredictiveAgents.m_storage )
  {
    v10 = (signed int)v6;
    v8 = (signed int)v8;
    v11 = (unsigned __int8 *)v5 + 35 * (signed int)v6 + (signed int)v8;
    v12 = v11[6944];
  }
  else
  {
    v10 = v6;
    v11 = (unsigned __int8 *)v5 + 35 * v6 + v8;
    v12 = v11[5712];
  }
  v13 = v5->m_agent3Func[v12].m_symmetric == 2;
  if ( v12 == 1 )
    v13 = v5->m_agent2Func[v11[688]].m_isFlipped.m_bool != 0;
  *isFlippedOut = v13;
  if ( v13 )
  {
    v14 = v10 + 35 * v8;
    if ( v9->m_createPredictiveAgents.m_storage )
      v15 = (unsigned __int8)v5->m_agent3TypesPred[0][v14];
    else
      v15 = (unsigned __int8)v5->m_agent3Types[0][v14];
    *v7 = v15;
  }
  else
  {
    *v7 = v12;
  }
}

// File Line: 226
// RVA: 0xD41050
hkpAgentNnEntry *__fastcall hkAgentNnMachine_CreateAgent(hkpAgentNnTrack *track, hkpLinkedCollidable *collA, hkpCdBody *firstNonTransformBodyA, hkpLinkedCollidable *collB, hkpCdBody *firstNonTransformBodyB, char cdBodyHasTransformFlag, int agentType, hkpProcessCollisionInput *input, hkpContactMgr *mgr)
{
  hkpLinkedCollidable *v9; // r14
  hkpCollisionDispatcher *v10; // r13
  hkpLinkedCollidable *v11; // rbp
  hkpAgentNnTrack *v12; // r15
  hkpAgentNnEntry *v13; // rax
  hkpAgentNnEntry *v14; // rbx
  hkpLinkedCollidable::CollisionEntry *v15; // rsi
  int v16; // eax
  __int64 v17; // rcx
  hkpLinkedCollidable::CollisionEntry *v18; // rcx
  hkTransformf *v19; // r8
  hkTransformf *v20; // rdx
  __int64 v21; // rcx
  char v22; // al
  signed __int64 v23; // r8
  hkpAgentNnEntry *result; // rax
  hkpCdBody *v25; // [rsp+20h] [rbp-98h]
  hkpCdBody *v26; // [rsp+28h] [rbp-90h]
  __int64 v27; // [rsp+30h] [rbp-88h]
  hkpProcessCollisionInput *v28; // [rsp+38h] [rbp-80h]
  hkpContactMgr *v29; // [rsp+40h] [rbp-78h]
  hkTransformf v30; // [rsp+50h] [rbp-68h]
  hkpCdBody *v31; // [rsp+D0h] [rbp+18h]

  v31 = firstNonTransformBodyA;
  v9 = collA;
  v10 = input->m_dispatcher.m_storage;
  v11 = collB;
  v12 = track;
  v13 = hkAgentNnMachine_AllocateEntry(track, 0);
  v13->m_contactMgr = mgr;
  v14 = v13;
  v13->m_nnTrackType.m_storage = v12->m_nnTrackType.m_storage;
  v13->m_collidable[0] = v9;
  v13->m_collidable[1] = v11;
  v13->m_agentIndexOnCollidable[0] = v9->m_collisionEntries.m_size;
  v13->m_agentIndexOnCollidable[1] = v11->m_collisionEntries.m_size;
  if ( v9->m_collisionEntries.m_size == (v9->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v9->m_collisionEntries,
      16);
  v15 = &v9->m_collisionEntries.m_data[v9->m_collisionEntries.m_size++];
  if ( v11->m_collisionEntries.m_size == (v11->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v11->m_collisionEntries,
      16);
  v16 = v11->m_collisionEntries.m_size;
  v17 = v11->m_collisionEntries.m_size;
  v25 = v31;
  v26 = firstNonTransformBodyB;
  v27 = 0i64;
  v28 = input;
  v18 = &v11->m_collisionEntries.m_data[v17];
  v11->m_collisionEntries.m_size = v16 + 1;
  v15->m_agentEntry = v14;
  v18->m_agentEntry = v14;
  v15->m_partner = v11;
  v18->m_partner = v9;
  v19 = (hkTransformf *)firstNonTransformBodyB->m_motion;
  v20 = (hkTransformf *)v31->m_motion;
  v29 = v14->m_contactMgr;
  hkTransformf::setMulInverseMul(&v30, v20, v19);
  v21 = input->m_dispatcher.m_storage->m_collisionQualityTable[v9->m_broadPhaseHandle.m_objectQualityType][v11->m_broadPhaseHandle.m_objectQualityType];
  v14->m_collisionQualityIndex = v21;
  input->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)((char *)input->m_dispatcher.m_storage
                                                                      + 64 * (v21 + 161));
  v14->m_agentType = agentType;
  if ( v10->m_agent3Func[agentType].m_sepNormalFunc )
  {
    v22 = cdBodyHasTransformFlag | 4;
    v14[1].0 = (hkpAgentEntry)-1082130432;
    v23 = (signed __int64)v14[1].m_collidable;
    *(_OWORD *)&v14[1].m_contactMgr = 0i64;
  }
  else
  {
    v22 = cdBodyHasTransformFlag | 2;
    v23 = (signed __int64)&v14[1].m_contactMgr;
  }
  v14->m_streamCommand = v22;
  ((void (__fastcall *)(hkpCdBody **, hkpAgentNnEntry *, signed __int64))(&v10->vfptr)[14
                                                                                     * ((unsigned __int8)agentType
                                                                                      + 73i64)])(
    &v25,
    v14,
    v23);
  result = v14;
  v14->m_size = 80 * v12->m_nnTrackType.m_storage;
  return result;
}

// File Line: 322
// RVA: 0xD41250
void __fastcall hkAgentNnMachine_DestroyAgent(hkpAgentNnTrack *track, hkpAgentNnEntry *entry, hkpCollisionDispatcher *dispatcher, hkpConstraintOwner *constraintOwner)
{
  hkpAgentNnEntry *v4; // rbx
  hkpAgentNnTrack *v5; // r14
  __int64 v6; // rax
  char *v7; // rdx
  unsigned __int16 *v8; // rdi
  hkpLinkedCollidable **v9; // rsi
  signed __int64 v10; // rbp
  hkpLinkedCollidable *v11; // r11
  __int64 v12; // r9
  signed __int64 v13; // rdx
  signed __int64 v14; // rax
  signed __int64 v15; // r8
  __int64 v16; // rcx
  hkpAgentNnEntry *v17; // rdx
  unsigned int v18; // ecx
  int requestedCapacity; // edx

  v4 = entry;
  v5 = track;
  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      v6 = (unsigned __int8)entry->m_agentType;
      v7 = (char *)&entry[1].m_contactMgr;
      goto LABEL_4;
    case 4:
    case 0xC:
      v6 = (unsigned __int8)entry->m_agentType;
      v7 = (char *)entry[1].m_collidable;
LABEL_4:
      dispatcher->m_agent3Func[v6].m_destroyFunc((hkpAgentEntry *)v4, v7, v4->m_contactMgr, constraintOwner, dispatcher);
      break;
    default:
      break;
  }
  v8 = v4->m_agentIndexOnCollidable;
  v9 = v4->m_collidable;
  v10 = 2i64;
  do
  {
    v11 = *v9;
    v12 = *v8;
    if ( --v11->m_collisionEntries.m_size != (_DWORD)v12 )
    {
      v13 = 2i64;
      v14 = (signed __int64)&v11->m_collisionEntries.m_data[(signed int)v12];
      v15 = (signed __int64)&v11->m_collisionEntries.m_data[v11->m_collisionEntries.m_size] - v14;
      do
      {
        v16 = *(_QWORD *)(v15 + v14);
        v14 += 8i64;
        *(_QWORD *)(v14 - 8) = v16;
        --v13;
      }
      while ( v13 );
    }
    if ( (signed int)v12 < v11->m_collisionEntries.m_size )
    {
      v17 = v11->m_collisionEntries.m_data[v12].m_agentEntry;
      v17->m_agentIndexOnCollidable[v17->m_collidable[0] != v11] = v12;
    }
    v18 = ((((((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 4) | ((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 2) | ((((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 4) | ((((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3)) >> 8) | ((unsigned int)(v11->m_collisionEntries.m_size + 3) >> 16) | (v11->m_collisionEntries.m_size + 3);
    requestedCapacity = (v18 | (v18 >> 1)) + 1;
    if ( requestedCapacity < (v11->m_collisionEntries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v11->m_collisionEntries,
        16,
        0i64,
        requestedCapacity);
    ++v9;
    ++v8;
    --v10;
  }
  while ( v10 );
  hkAgentNnMachine_InternalDeallocateEntry(v5, v4);
}

// File Line: 380
// RVA: 0xD42380
char __fastcall hkAgentNnMachine_IsEntryOnTrack(hkpAgentNnTrack *track, hkpAgentNnEntry *entry)
{
  __int64 v2; // rdi
  __int64 v3; // r10
  hkpAgentNnTrack *v4; // r11
  hkpAgentNnSector **v5; // r9
  signed int v6; // er8
  unsigned __int64 v7; // rcx
  int v8; // eax

  v2 = track->m_sectors.m_size;
  v3 = 0i64;
  v4 = track;
  if ( (signed int)v2 <= 0 )
    return 0;
  v5 = track->m_sectors.m_data;
  v6 = 1;
  while ( 1 )
  {
    v7 = (unsigned __int64)*v5;
    v8 = v6 == (_DWORD)v2 ? v4->m_bytesUsedInLastSector : 960;
    if ( v7 <= (unsigned __int64)entry && (unsigned __int64)entry < v7 + v8 )
      break;
    ++v3;
    ++v6;
    ++v5;
    if ( v3 >= v2 )
      return 0;
  }
  return 1;
}

// File Line: 396
// RVA: 0xD42400
void __fastcall hkAgentNnMachine_InternalDeallocateEntry(hkpAgentNnTrack *track, hkpAgentNnEntry *entry)
{
  char *v2; // rdi
  hkpAgentNnTrack *v3; // rsi
  hkpAgentNnEntry *v4; // r10
  int v5; // er11
  char *v6; // rax
  __int128 v7; // xmm0
  int v8; // er8
  __int16 v9; // ax
  bool v10; // zf
  __int64 v11; // r8
  __int64 v12; // rbx
  _QWORD **v13; // rax
  int v14; // edx
  unsigned int v15; // ecx
  int requestedCapacity; // eax

  v2 = (char *)&track->m_sectors;
  v3 = track;
  v4 = (hkpAgentNnEntry *)&track->m_sectors.m_data[track->m_sectors.m_size - 1]->m_data[track->m_bytesUsedInLastSector
                                                                                      - 80
                                                                                      * (unsigned __int8)track->m_nnTrackType.m_storage];
  if ( entry != v4 )
  {
    v5 = 5 * (unsigned __int8)track->m_nnTrackType.m_storage & 0xFFFFFFF;
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
    v11 = track->m_sectors.m_size;
    v12 = *(_QWORD *)(*(_QWORD *)v2 + 8 * v11 - 8);
    track->m_sectors.m_size = v11 - 1;
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v13[11] + 16i64))(v13[11], v12, 960i64);
    v3->m_bytesUsedInLastSector = 960;
  }
  v14 = *((_DWORD *)v2 + 3);
  if ( v14 >= 0 )
  {
    v15 = ((((((((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 8) | ((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 4) | ((((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 8) | ((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 2) | ((((((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 8) | ((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 4) | ((((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3)) >> 8) | ((unsigned int)(*((_DWORD *)v2 + 2) + 3) >> 16) | (*((_DWORD *)v2 + 2) + 3);
    requestedCapacity = (v15 | (v15 >> 1)) + 1;
    if ( requestedCapacity >= 1 )
    {
      if ( requestedCapacity < (v14 & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v2,
          8,
          0i64,
          requestedCapacity);
    }
    else
    {
      hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8, v2 + 16, 1);
    }
  }
}

// File Line: 420
// RVA: 0xD41580
void __usercall hkAgentNnMachine_UpdateShapeCollectionFilter(hkpAgentNnEntry *entry@<rcx>, hkpCollisionInput *input@<rdx>, hkpConstraintOwner *constraintOwner@<r8>, __int64 a4@<r12>)
{
  int v4; // edi
  hkpLinkedCollidable *v5; // rbp
  hkpLinkedCollidable *v6; // r14
  int v7; // eax
  hkpConstraintOwner *v8; // r15
  hkpCollisionInput *v9; // rsi
  hkpAgentNnEntry *v10; // rbx
  signed __int64 v11; // rdx
  void (__fastcall *v12)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r10
  hkpCdBody v13; // [rsp+40h] [rbp-6A8h]
  hkpCdBody newCdBodies; // [rsp+C0h] [rbp-628h]
  hkMotionState newMotionStates; // [rsp+140h] [rbp-5A8h]
  hkMotionState v16; // [rsp+400h] [rbp-2E8h]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+6F0h] [rbp+8h]
  __int64 v18; // [rsp+6F8h] [rbp+10h]

  v4 = (unsigned __int8)entry->m_streamCommand;
  v5 = entry->m_collidable[0];
  v6 = entry->m_collidable[1];
  v7 = v4 - 2;
  v8 = constraintOwner;
  v9 = input;
  v10 = entry;
  v18 = a4;
  while ( 2 )
  {
    switch ( v7 )
    {
      case 0:
      case 4:
        v11 = (signed __int64)&v10[1].m_contactMgr;
        goto $callChildAgent;
      case 2:
        v11 = (signed __int64)v10[1].m_collidable;
$callChildAgent:
        v12 = v9->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v10->m_agentType].m_updateFilterFunc;
        if ( v12 )
          v12(
            (hkpAgentEntry *)&v10->m_streamCommand,
            (void *)v11,
            (hkpCdBody *)&v5->m_shape,
            (hkpCdBody *)&v6->m_shape,
            v9,
            v10->m_contactMgr,
            v8);
        break;
      case 8:
      case 10:
      case 12:
        v5 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                      (hkpCdBody *)&v5->m_shape,
                                      &newCdBodies,
                                      &newMotionStates,
                                      4,
                                      &cdBodyHasTransformFlag);
        v4 &= 0xF7u;
        v6 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                      (hkpCdBody *)&v6->m_shape,
                                      &v13,
                                      &v16,
                                      4,
                                      &cdBodyHasTransformFlag);
        v7 = v4 - 2;
        if ( (unsigned int)(v4 - 2) <= 0xC )
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
  hkpAgentNnEntry *v2; // r9
  void (__fastcall *v3)(hkpAgentEntry *, void *, hkpCollisionInput *); // r11
  __int64 v4; // rcx
  void (__fastcall *v5)(hkpAgentEntry *, void *, hkpCollisionInput *); // r11

  v2 = entry;
  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      v3 = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_invalidateTimFunc;
      if ( v3 )
        v3((hkpAgentEntry *)&entry->m_streamCommand, &entry[1].m_contactMgr, input);
      break;
    case 4:
    case 0xC:
      v4 = (unsigned __int8)entry->m_agentType;
      v2[1].0 = (hkpAgentEntry)-1082130432;
      *(_OWORD *)&v2[1].m_contactMgr = 0i64;
      v5 = input->m_dispatcher.m_storage->m_agent3Func[v4].m_invalidateTimFunc;
      if ( v5 )
        v5((hkpAgentEntry *)&v2->m_streamCommand, v2[1].m_collidable, input);
      break;
    default:
      return;
  }
}

// File Line: 519
// RVA: 0xD42730
void __fastcall hkAgentNnMachine_WarpTimeInAgent(hkpAgentNnEntry *entry, float oldTime, float newTime, hkpCollisionInput *input)
{
  void (__fastcall *v4)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r10
  char *v5; // rdx

  switch ( entry->m_streamCommand )
  {
    case 2:
    case 6:
    case 0xA:
    case 0xE:
      v4 = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_warpTimeFunc;
      if ( v4 )
      {
        v5 = (char *)&entry[1].m_contactMgr;
        goto LABEL_8;
      }
      break;
    case 4:
    case 0xC:
      v5 = (char *)entry[1].m_collidable;
      if ( oldTime == *(float *)&entry[1].0 )
        *(float *)&entry[1].0 = newTime;
      else
        entry[1].0 = (hkpAgentEntry)-1082130432;
      v4 = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_warpTimeFunc;
      if ( v4 )
LABEL_8:
        ((void (__fastcall *)(hkpAgentNnEntry *, char *))v4)(entry, v5);
      break;
    default:
      return;
  }
}

// File Line: 571
// RVA: 0xD41410
void __fastcall hkAgentNnMachine_AppendTrack(hkpAgentNnTrack *track, hkpAgentNnTrack *appendee)
{
  hkpAgentNnTrack *v2; // rsi
  hkpAgentNnTrack *v3; // r14
  __int16 v4; // ax
  bool v5; // zf
  __int64 v6; // r8
  hkpAgentNnSector *v7; // rdi
  _QWORD **v8; // rax
  int v9; // edx
  unsigned int v10; // ecx
  int requestedCapacity; // eax

  v2 = appendee;
  v3 = track;
  while ( v3->m_bytesUsedInLastSector != 960 )
  {
    if ( !v2->m_sectors.m_size )
      break;
    hkAgentNnMachine_CopyAndRelinkAgentEntry(
      v3,
      (hkpAgentNnEntry *)&v2->m_sectors.m_data[v2->m_sectors.m_size - 1]->m_data[v2->m_bytesUsedInLastSector
                                                                               - 80
                                                                               * (unsigned __int8)v2->m_nnTrackType.m_storage]);
    v4 = -80 * (unsigned __int8)v2->m_nnTrackType.m_storage;
    v5 = v4 + v2->m_bytesUsedInLastSector == 0;
    v2->m_bytesUsedInLastSector += v4;
    if ( v5 )
    {
      v6 = v2->m_sectors.m_size;
      v7 = v2->m_sectors.m_data[v6 - 1];
      v2->m_sectors.m_size = v6 - 1;
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgentNnSector *, signed __int64))(*v8[11] + 16i64))(v8[11], v7, 960i64);
      v2->m_bytesUsedInLastSector = 960;
    }
    v9 = v2->m_sectors.m_capacityAndFlags;
    if ( v9 >= 0 )
    {
      v10 = ((((((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 2) | ((((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v2->m_sectors.m_size + 3) >> 16) | (v2->m_sectors.m_size + 3);
      requestedCapacity = (v10 | (v10 >> 1)) + 1;
      if ( requestedCapacity >= 1 )
      {
        if ( requestedCapacity < (v9 & 0x3FFFFFFF) )
          hkArrayUtil::_reduce(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v2->m_sectors,
            8,
            0i64,
            requestedCapacity);
      }
      else
      {
        hkArrayUtil::_reduce(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v2->m_sectors,
          8,
          (char *)v2->m_sectors.m_storage,
          1);
      }
    }
  }
  if ( v2->m_sectors.m_size )
  {
    hkArrayBase<hkpEntity *>::_insertAt(
      (hkArrayBase<hkProcess *> *)&v3->m_sectors,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v3->m_sectors.m_size,
      (hkProcess *const *)v2->m_sectors.m_data,
      v2->m_sectors.m_size);
    v3->m_bytesUsedInLastSector = v2->m_bytesUsedInLastSector;
    v2->m_sectors.m_size = 0;
    v2->m_bytesUsedInLastSector = 960;
  }
}

// File Line: 640
// RVA: 0xD42570
hkpAgentNnEntry *__fastcall hkAgentNnMachine_CopyAndRelinkAgentEntry(hkpAgentNnTrack *destTrack, hkpAgentNnEntry *entry)
{
  hkpAgentNnEntry *v2; // rbx
  hkpAgentNnTrack *v3; // rdi
  hkpAgentNnEntry *v4; // r9
  int v5; // edx
  signed __int64 v6; // rax
  __int128 v7; // xmm0
  int v8; // er8

  v2 = entry;
  v3 = destTrack;
  v4 = hkAgentNnMachine_AllocateEntry(destTrack, (unsigned __int8)entry->m_forceCollideOntoPpu);
  v5 = 5 * (unsigned __int8)v3->m_nnTrackType.m_storage & 0xFFFFFFF;
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
void __fastcall hkAgentNnMachine_DestroyTrack(hkpAgentNnTrack *track, hkpCollisionDispatcher *dispatcher, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v3; // rdi
  hkpCollisionDispatcher *v4; // rsi
  hkpAgentNnTrack *i; // rbx

  v3 = constraintOwner;
  v4 = dispatcher;
  for ( i = track;
        i->m_sectors.m_size;
        hkAgentNnMachine_DestroyAgent(
          i,
          (hkpAgentNnEntry *)&i->m_sectors.m_data[i->m_sectors.m_size - 1]->m_data[i->m_bytesUsedInLastSector
                                                                                 - 80
                                                                                 * (unsigned __int8)i->m_nnTrackType.m_storage],
          v4,
          v3) )
  {
    ;
  }
}

// File Line: 692
// RVA: 0xD416F0
void __usercall hkAgentNnMachine_ProcessAgent(hkpAgentNnEntry *entry@<rcx>, hkpProcessCollisionInput *input@<rdx>, hkpProcessCollisionOutput *output@<r8>, hkpContactMgr *mgr@<r9>, __int64 a5@<r12>)
{
  hkpAgentNnEntry *v5; // rbx
  hkpProcessCollisionOutput *v6; // r13
  hkpProcessCollisionInput *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // esi
  hkpCdBody *v14; // r14
  hkpCdBody *v15; // r15
  int v16; // eax
  __int64 v17; // rax
  hkTransformf *v18; // rdx
  hkTransformf *v19; // r8
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  signed __int64 v25; // r8
  hkVector4f *v26; // r9
  __int64 v27; // r8
  hkTransformf *v28; // rcx
  hkTransformf *v29; // r12
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  float v36; // xmm1_4
  bool v37; // zf
  __m128 v38; // xmm6
  __m128 *v39; // rsi
  __m128 v40; // xmm2
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // r8
  unsigned __int64 v44; // rax
  signed __int64 v45; // rcx
  int v46; // ecx
  int v47; // ecx
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  hkTransformf *v52; // [rsp+30h] [rbp-C8h]
  hkpCdBody *v53; // [rsp+40h] [rbp-B8h]
  hkpCdBody *v54; // [rsp+48h] [rbp-B0h]
  __int64 v55; // [rsp+50h] [rbp-A8h]
  hkpProcessCollisionInput *v56; // [rsp+58h] [rbp-A0h]
  __int64 v57; // [rsp+60h] [rbp-98h]
  hkTransformf v58; // [rsp+70h] [rbp-88h]
  __m128 v59; // [rsp+B8h] [rbp-40h]
  hkpShape *v60; // [rsp+C8h] [rbp-30h]
  int v61; // [rsp+D0h] [rbp-28h]
  hkTransformf *v62; // [rsp+D8h] [rbp-20h]
  hkpCdBody *v63; // [rsp+E0h] [rbp-18h]
  hkpShape *v64; // [rsp+E8h] [rbp-10h]
  int v65; // [rsp+F0h] [rbp-8h]
  hkTransformf *v66; // [rsp+F8h] [rbp+0h]
  hkpCdBody *v67; // [rsp+100h] [rbp+8h]
  hkTransformf transformOut; // [rsp+108h] [rbp+10h]
  hkTransformf bTc; // [rsp+148h] [rbp+50h]
  __int64 *v70; // [rsp+188h] [rbp+90h]
  __int64 *v71; // [rsp+190h] [rbp+98h]
  __int64 v72; // [rsp+198h] [rbp+A0h]
  hkpProcessCollisionInput *v73; // [rsp+1A0h] [rbp+A8h]
  __int64 v74; // [rsp+1A8h] [rbp+B0h]
  hkTransformf v75; // [rsp+1B8h] [rbp+C0h]
  hkpCdBody v76; // [rsp+1F8h] [rbp+100h]
  hkpCdBody newCdBodies; // [rsp+278h] [rbp+180h]
  hkMotionState newMotionStates; // [rsp+2F8h] [rbp+200h]
  hkMotionState v79; // [rsp+5B8h] [rbp+4C0h]
  __int64 v80; // [rsp+8A8h] [rbp+7B0h]
  void *cdBodyHasTransformFlag; // [rsp+8B8h] [rbp+7C0h]

  v5 = entry;
  v6 = output;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtProcessNnEntry";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (unsigned __int8)v5->m_streamCommand;
  v14 = (hkpCdBody *)&v5->m_collidable[0]->m_shape;
  v15 = (hkpCdBody *)&v5->m_collidable[1]->m_shape;
  v16 = v13 - 2;
  v80 = a5;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0:
        v17 = (__int64)v5->m_contactMgr;
        v53 = v14;
        v54 = v15;
        v56 = v7;
        v57 = v17;
        v55 = 0i64;
        v18 = (hkTransformf *)v14->m_motion;
        v19 = (hkTransformf *)v15->m_motion;
        v20 = v18[1].m_rotation.m_col1.m_quad;
        v21 = v19[1].m_rotation.m_col1.m_quad;
        v22 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
                0);
        v23 = _mm_mul_ps(_mm_shuffle_ps(v18[1].m_rotation.m_col1.m_quad, v20, 255), v22);
        v24 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v22);
        v59 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v18[1].m_rotation.m_col0.m_quad, v20), v23),
                _mm_mul_ps(_mm_sub_ps(v21, v19[1].m_rotation.m_col0.m_quad), v24));
        v59 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v18[2].m_rotation.m_col1.m_quad, v18[2].m_rotation.m_col1.m_quad, 255),
                        v23),
                      _mm_shuffle_ps(
                        (__m128)v18[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v18[2].m_rotation.m_col2.m_quad.m128_u32[0],
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
        hkTransformf::setMulInverseMul(&v58, v18, v19);
        v25 = (signed __int64)&v5[1].m_contactMgr;
        v26 = 0i64;
        goto LABEL_13;
      case 2:
        v27 = (__int64)v5->m_contactMgr;
        v53 = v14;
        v54 = v15;
        v56 = v7;
        v57 = v27;
        v55 = 0i64;
        v28 = (hkTransformf *)v15->m_motion;
        v29 = (hkTransformf *)v14->m_motion;
        v52 = v28;
        v30 = v29[1].m_rotation.m_col1.m_quad;
        v31 = v28[1].m_rotation.m_col1.m_quad;
        v32 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
                0);
        v33 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v32);
        v34 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v32);
        v35 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v31, v28[1].m_rotation.m_col0.m_quad), v33),
                _mm_mul_ps(_mm_sub_ps(v29[1].m_rotation.m_col0.m_quad, v30), v34));
        v59 = v35;
        v36 = v7->m_stepInfo.m_startTime.m_storage;
        v37 = v36 == *(float *)&v5[1].0;
        v38 = _mm_shuffle_ps(
                v35,
                _mm_unpackhi_ps(
                  v35,
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
        v59 = v38;
        if ( v37 )
          goto LABEL_18;
        if ( v7->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
        {
          v72 = 0i64;
          hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v14->m_motion + 64), v36, &transformOut);
          hkSweptTransformUtil::lerp2(
            (hkSweptTransformf *)((char *)v54->m_motion + 64),
            v56->m_stepInfo.m_startTime.m_storage,
            &bTc);
          v70 = (__int64 *)&v60;
          v71 = (__int64 *)&v64;
          v74 = v57;
          v73 = v56;
          v46 = v53->m_shapeKey;
          v60 = v53->m_shape;
          v61 = v46;
          v47 = v54->m_shapeKey;
          v64 = v54->m_shape;
          v62 = &transformOut;
          v63 = v53;
          v67 = v54;
          v65 = v47;
          v66 = &bTc;
          hkTransformf::setMulInverseMul(&v75, &transformOut, &bTc);
          v7->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_sepNormalFunc(
            (hkpAgent3Input *)&v70,
            (hkpAgentEntry *)&v5->m_streamCommand,
            v5[1].m_collidable,
            (hkVector4f *)&v5[1].m_contactMgr);
          v27 = v57;
          v28 = v52;
          v38 = v59;
LABEL_18:
          v48 = *(__m128 *)&v5[1].m_contactMgr;
          v39 = (__m128 *)&v5[1].m_contactMgr;
          v5[1].0 = (hkpAgentEntry)LODWORD(v7->m_stepInfo.m_endTime.m_storage);
          v49 = _mm_mul_ps(v38, v48);
          v50 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v38), 196);
          v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 78), v50);
          v40 = _mm_sub_ps(_mm_shuffle_ps(v48, v48, 255), _mm_add_ps(_mm_shuffle_ps(v51, v51, 177), v51));
          if ( v40.m128_f32[0] >= COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(v7->m_tolerance.m_storage),
                                      (__m128)LODWORD(v7->m_tolerance.m_storage),
                                      0)) )
          {
            v37 = v5->m_numContactPoints == 0;
            *v39 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v40), 196);
            if ( !v37 )
              v7->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_cleanupFunc(
                (hkpAgentEntry *)&v5->m_streamCommand,
                v5[1].m_collidable,
                (hkpContactMgr *)v27,
                v6->m_constraintOwner.m_storage);
            goto LABEL_14;
          }
        }
        else
        {
          v39 = (__m128 *)&v5[1].m_contactMgr;
          v5[1].0 = (hkpAgentEntry)LODWORD(v7->m_stepInfo.m_endTime.m_storage);
          v40.m128_i32[0] = xmmword_141A712F0;
          *(__m128 *)&v5[1].m_contactMgr = _mm_shuffle_ps(
                                             aabbOut.m_quad,
                                             _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                             196);
        }
        v58.m_translation.m_quad.m128_i32[2] = v40.m128_i32[0];
        hkTransformf::setMulInverseMul(&v58, v29, v28);
        v26 = (hkVector4f *)v39;
        v25 = (signed __int64)v5[1].m_collidable;
LABEL_13:
        v7->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_processFunc(
          (hkpAgent3ProcessInput *)&v53,
          (hkpAgentEntry *)&v5->m_streamCommand,
          (void *)v25,
          v26,
          v6);
LABEL_14:
        v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v42 = (_QWORD *)v41[1];
        v43 = v41;
        if ( (unsigned __int64)v42 < v41[3] )
        {
          *v42 = "Et";
          v44 = __rdtsc();
          v45 = (signed __int64)(v42 + 2);
          *(_DWORD *)(v45 - 8) = v44;
          v43[1] = v45;
        }
        return;
      case 4:
        ((void (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v5[1].m_contactMgr->vfptr[3].__vecDelDtor)(
          v5[1].m_contactMgr,
          v14,
          v15,
          v7,
          v6);
        goto LABEL_14;
      case 8:
      case 10:
      case 12:
        v14 = hkAgentMachine_processTransformedShapes(
                v14,
                &newCdBodies,
                &newMotionStates,
                4,
                (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v13 &= 0xF7u;
        v15 = hkAgentMachine_processTransformedShapes(
                v15,
                &v76,
                &v79,
                4,
                (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v16 = v13 - 2;
        if ( (unsigned int)(v13 - 2) <= 0xC )
          continue;
        goto LABEL_14;
      default:
        goto LABEL_14;
    }
  }
}C )
          continue;
        goto LABEL_14;
      default:
        goto LABEL_14;
    }
  }
}

// File Line: 699
// RVA: 0xD41C90
void __fastcall hkAgentNnMachine_ProcessTrack(hkpConstraintOwner *owner, hkpAgentNnTrack *agentTrack, hkpProcessCollisionInput *input)
{
  int v3; // edi
  hkpProcessCollisionInput *v4; // r15
  hkpAgentNnTrack *v5; // r8
  int v6; // ecx
  int v7; // edx
  __int64 v8; // r9
  unsigned __int64 v10; // r12
  __int64 v11; // r13
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  int v17; // edi
  hkpCdBody *v18; // rsi
  hkpCdBody *v19; // r14
  int v20; // eax
  __int64 v21; // rax
  hkTransformf *v22; // rdx
  hkTransformf *v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  signed __int64 v29; // r8
  hkVector4f *v30; // r9
  __int64 v31; // r8
  hkTransformf *v32; // rcx
  hkTransformf *v33; // rdx
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm6
  float v40; // xmm1_4
  bool v41; // zf
  __m128 v42; // xmm6
  __m128 *v43; // rdi
  __m128 v44; // xmm2
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  _QWORD *v49; // rax
  unsigned __int64 v50; // rcx
  signed __int64 v51; // rcx
  int v52; // ecx
  int v53; // ecx
  __m128 v54; // xmm3
  __m128 v55; // xmm2
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  int v58; // [rsp+30h] [rbp-D0h]
  __int64 v59; // [rsp+38h] [rbp-C8h]
  __int64 v60; // [rsp+40h] [rbp-C0h]
  hkTransformf *v61; // [rsp+48h] [rbp-B8h]
  hkTransformf *v62; // [rsp+50h] [rbp-B0h]
  hkpCdBody *v63; // [rsp+60h] [rbp-A0h]
  hkpCdBody *v64; // [rsp+68h] [rbp-98h]
  __int64 v65; // [rsp+70h] [rbp-90h]
  hkpProcessCollisionInput *v66; // [rsp+78h] [rbp-88h]
  __int64 v67; // [rsp+80h] [rbp-80h]
  hkTransformf v68; // [rsp+90h] [rbp-70h]
  int v69; // [rsp+D0h] [rbp-30h]
  __m128 v70; // [rsp+E0h] [rbp-20h]
  hkpShape *v71; // [rsp+F0h] [rbp-10h]
  int v72; // [rsp+F8h] [rbp-8h]
  hkTransformf *v73; // [rsp+100h] [rbp+0h]
  hkpCdBody *v74; // [rsp+108h] [rbp+8h]
  hkpShape *v75; // [rsp+110h] [rbp+10h]
  int v76; // [rsp+118h] [rbp+18h]
  hkTransformf *v77; // [rsp+120h] [rbp+20h]
  hkpCdBody *v78; // [rsp+128h] [rbp+28h]
  hkTransformf transformOut; // [rsp+130h] [rbp+30h]
  hkTransformf bTc; // [rsp+170h] [rbp+70h]
  __int64 *v81; // [rsp+1B0h] [rbp+B0h]
  __int64 *v82; // [rsp+1B8h] [rbp+B8h]
  __int64 v83; // [rsp+1C0h] [rbp+C0h]
  hkpProcessCollisionInput *v84; // [rsp+1C8h] [rbp+C8h]
  __int64 v85; // [rsp+1D0h] [rbp+D0h]
  hkTransformf v86; // [rsp+1E0h] [rbp+E0h]
  hkpCdBody newCdBodies; // [rsp+220h] [rbp+120h]
  hkpCdBody v88; // [rsp+2A0h] [rbp+1A0h]
  hkMotionState newMotionStates; // [rsp+320h] [rbp+220h]
  hkMotionState v90; // [rsp+5E0h] [rbp+4E0h]
  char *v91; // [rsp+8A0h] [rbp+7A0h]
  hkpConstraintOwner *v92; // [rsp+8A8h] [rbp+7A8h]
  char v93; // [rsp+8B0h] [rbp+7B0h]
  int v94; // [rsp+38D0h] [rbp+37D0h]
  __int64 v95; // [rsp+38F0h] [rbp+37F0h]
  __int64 v96; // [rsp+3930h] [rbp+3830h]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+3990h] [rbp+3890h]
  hkpAgentNnTrack *v98; // [rsp+3998h] [rbp+3898h]
  int v99; // [rsp+39A8h] [rbp+38A8h]

  v98 = agentTrack;
  v3 = 0;
  v4 = input;
  v5 = agentTrack;
  v92 = owner;
  v6 = agentTrack->m_sectors.m_size;
  v7 = 0;
  v99 = 0;
  v94 = 2139095022;
  v95 = 0i64;
  if ( v6 > 0 )
  {
    v8 = 0i64;
    do
    {
      ++v7;
      v8 += 8i64;
      _RBX = *(unsigned __int8 **)((char *)v5->m_sectors.m_data + v8 - 8);
      v60 = v8;
      v58 = v7;
      if ( v7 == v6 )
        v10 = (unsigned __int64)&_RBX[v5->m_bytesUsedInLastSector];
      else
        v10 = (unsigned __int64)(_RBX + 960);
      if ( (unsigned __int64)_RBX < v10 )
      {
        while ( 2 )
        {
          v11 = *((_QWORD *)_RBX + 3);
          v59 = *((_QWORD *)_RBX + 4);
          v91 = &v93;
          v94 = 2139095022;
          v96 = 0i64;
          _RAX = *((_QWORD *)_RBX + 1);
          __asm
          {
            prefetchnta byte ptr [rax]; Prefetch to L1 cache
            prefetchnta byte ptr [rbx+80h]; Prefetch to L1 cache
          }
          v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v14 = (_QWORD *)v13[1];
          if ( (unsigned __int64)v14 < v13[3] )
          {
            *v14 = "TtProcessNnEntry";
            v15 = __rdtsc();
            v16 = (signed __int64)(v14 + 2);
            *(_DWORD *)(v16 - 8) = v15;
            v13[1] = v16;
          }
          v17 = *_RBX;
          v18 = (hkpCdBody *)*((_QWORD *)_RBX + 3);
          v19 = (hkpCdBody *)*((_QWORD *)_RBX + 4);
          v20 = v17 - 2;
LABEL_10:
          switch ( v20 )
          {
            case 0:
              v21 = *((_QWORD *)_RBX + 1);
              v63 = v18;
              v64 = v19;
              v66 = v4;
              v67 = v21;
              v65 = 0i64;
              v22 = (hkTransformf *)v18->m_motion;
              v23 = (hkTransformf *)v19->m_motion;
              *(float *)&cdBodyHasTransformFlag.m_storage = v4->m_stepInfo.m_deltaTime.m_storage;
              v24 = v22[1].m_rotation.m_col1.m_quad;
              v25 = v23[1].m_rotation.m_col1.m_quad;
              v26 = _mm_shuffle_ps(
                      (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                      (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                      0);
              v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v26);
              v28 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 255), v26);
              v70 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v25, v23[1].m_rotation.m_col0.m_quad), v27),
                      _mm_mul_ps(_mm_sub_ps(v22[1].m_rotation.m_col0.m_quad, v24), v28));
              v70 = _mm_shuffle_ps(
                      v70,
                      _mm_unpackhi_ps(
                        v70,
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v22[2].m_rotation.m_col1.m_quad, v22[2].m_rotation.m_col1.m_quad, 255),
                              v28),
                            _mm_shuffle_ps(
                              (__m128)v22[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v22[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v23[2].m_rotation.m_col1.m_quad, v23[2].m_rotation.m_col1.m_quad, 255),
                              v27),
                            _mm_shuffle_ps(
                              (__m128)v23[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v23[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)))),
                      196);
              hkTransformf::setMulInverseMul(&v68, v22, v23);
              v29 = (signed __int64)(_RBX + 48);
              v30 = 0i64;
              goto LABEL_19;
            case 2:
              v31 = *((_QWORD *)_RBX + 1);
              v63 = v18;
              v64 = v19;
              v66 = v4;
              v67 = v31;
              v65 = 0i64;
              v32 = (hkTransformf *)v18->m_motion;
              v33 = (hkTransformf *)v19->m_motion;
              *(float *)&cdBodyHasTransformFlag.m_storage = v4->m_stepInfo.m_deltaTime.m_storage;
              v62 = v32;
              v61 = v33;
              v34 = v32[1].m_rotation.m_col1.m_quad;
              v35 = v33[1].m_rotation.m_col1.m_quad;
              v36 = _mm_shuffle_ps(
                      (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                      (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                      0);
              v37 = _mm_mul_ps(_mm_shuffle_ps(v32[1].m_rotation.m_col1.m_quad, v34, 255), v36);
              v38 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), v36);
              v39 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v32[1].m_rotation.m_col0.m_quad, v34), v37),
                      _mm_mul_ps(_mm_sub_ps(v35, v33[1].m_rotation.m_col0.m_quad), v38));
              v70 = v39;
              v40 = v4->m_stepInfo.m_startTime.m_storage;
              v41 = v40 == *((float *)_RBX + 10);
              v42 = _mm_shuffle_ps(
                      v39,
                      _mm_unpackhi_ps(
                        v39,
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v32[2].m_rotation.m_col1.m_quad, v32[2].m_rotation.m_col1.m_quad, 255),
                              v37),
                            _mm_shuffle_ps(
                              (__m128)v32[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v32[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v33[2].m_rotation.m_col1.m_quad, v33[2].m_rotation.m_col1.m_quad, 255),
                              v38),
                            _mm_shuffle_ps(
                              (__m128)v33[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              (__m128)v33[2].m_rotation.m_col2.m_quad.m128_u32[0],
                              0)))),
                      196);
              v70 = v42;
              if ( v41 )
                goto LABEL_33;
              if ( v4->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
              {
                v83 = 0i64;
                hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v18->m_motion + 64), v40, &transformOut);
                hkSweptTransformUtil::lerp2(
                  (hkSweptTransformf *)((char *)v64->m_motion + 64),
                  v66->m_stepInfo.m_startTime.m_storage,
                  &bTc);
                v81 = (__int64 *)&v71;
                v82 = (__int64 *)&v75;
                v85 = v67;
                v84 = v66;
                v52 = v63->m_shapeKey;
                v71 = v63->m_shape;
                v72 = v52;
                v53 = v64->m_shapeKey;
                v75 = v64->m_shape;
                v73 = &transformOut;
                v74 = v63;
                v78 = v64;
                v76 = v53;
                v77 = &bTc;
                hkTransformf::setMulInverseMul(&v86, &transformOut, &bTc);
                v4->m_dispatcher.m_storage->m_agent3Func[_RBX[1]].m_sepNormalFunc(
                  (hkpAgent3Input *)&v81,
                  (hkpAgentEntry *)_RBX,
                  _RBX + 64,
                  (hkVector4f *)_RBX + 3);
                v31 = v67;
                v32 = v62;
                v42 = v70;
                v33 = v61;
LABEL_33:
                v54 = *((__m128 *)_RBX + 3);
                v43 = (__m128 *)(_RBX + 48);
                *((_DWORD *)_RBX + 10) = LODWORD(v4->m_stepInfo.m_endTime.m_storage);
                v55 = _mm_mul_ps(v42, v54);
                v56 = _mm_shuffle_ps(v55, _mm_unpackhi_ps(v55, v42), 196);
                v57 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 78), v56);
                v44 = _mm_sub_ps(_mm_shuffle_ps(v54, v54, 255), _mm_add_ps(_mm_shuffle_ps(v57, v57, 177), v57));
                *(float *)&cdBodyHasTransformFlag.m_storage = v4->m_tolerance.m_storage;
                if ( v44.m128_f32[0] >= COERCE_FLOAT(
                                          _mm_shuffle_ps(
                                            (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                                            (__m128)*(unsigned int *)&cdBodyHasTransformFlag.m_storage,
                                            0)) )
                {
                  v41 = _RBX[2] == 0;
                  *v43 = _mm_shuffle_ps(v54, _mm_unpackhi_ps(v54, v44), 196);
                  if ( !v41 )
                    v4->m_dispatcher.m_storage->m_agent3Func[_RBX[1]].m_cleanupFunc(
                      (hkpAgentEntry *)_RBX,
                      _RBX + 64,
                      (hkpContactMgr *)v31,
                      v92);
                  v3 = v99++ + 1;
                  goto LABEL_21;
                }
              }
              else
              {
                v43 = (__m128 *)(_RBX + 48);
                *((_DWORD *)_RBX + 10) = LODWORD(v4->m_stepInfo.m_endTime.m_storage);
                v44.m128_i32[0] = xmmword_141A712F0;
                *((__m128 *)_RBX + 3) = _mm_shuffle_ps(
                                          aabbOut.m_quad,
                                          _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                          196);
              }
              v69 = v44.m128_i32[0];
              hkTransformf::setMulInverseMul(&v68, v32, v33);
              v30 = (hkVector4f *)v43;
              v29 = (signed __int64)(_RBX + 64);
LABEL_19:
              v4->m_dispatcher.m_storage->m_agent3Func[_RBX[1]].m_processFunc(
                (hkpAgent3ProcessInput *)&v63,
                (hkpAgentEntry *)_RBX,
                (void *)v29,
                v30,
                (hkpProcessCollisionOutput *)&v91);
LABEL_20:
              v3 = v99;
LABEL_21:
              v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
              v46 = (_QWORD *)v45[1];
              if ( (unsigned __int64)v46 < v45[3] )
              {
                *v46 = "Et";
                v47 = __rdtsc();
                v48 = (signed __int64)(v46 + 2);
                *(_DWORD *)(v48 - 8) = v47;
                v45[1] = v48;
              }
              if ( hkOutOfMemoryState == 1 )
                return;
              if ( v91 != &v93 )
                (*(void (__fastcall **)(_QWORD, __int64, __int64, hkpProcessCollisionInput *, char **))(**((_QWORD **)_RBX + 1) + 48i64))(
                  *((_QWORD *)_RBX + 1),
                  v11,
                  v59,
                  v4,
                  &v91);
              _RBX += _RBX[3];
              if ( (unsigned __int64)_RBX < v10 )
                continue;
              v7 = v58;
              v5 = v98;
              v8 = v60;
              break;
            case 4:
              (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, char **))(**((_QWORD **)_RBX + 6) + 48i64))(
                *((_QWORD *)_RBX + 6),
                v18,
                v19,
                v4,
                &v91);
              goto LABEL_20;
            case 8:
            case 10:
            case 12:
              v18 = hkAgentMachine_processTransformedShapes(
                      v18,
                      &newCdBodies,
                      &newMotionStates,
                      4,
                      &cdBodyHasTransformFlag);
              v17 &= 0xF7u;
              v19 = hkAgentMachine_processTransformedShapes(v19, &v88, &v90, 4, &cdBodyHasTransformFlag);
              v20 = v17 - 2;
              if ( (unsigned int)(v17 - 2) <= 0xC )
                goto LABEL_10;
              goto LABEL_20;
            default:
              goto LABEL_20;
          }
          break;
        }
      }
      v6 = v5->m_sectors.m_size;
    }
    while ( v7 < v6 );
  }
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = v49[1];
  if ( v50 < v49[3] )
  {
    v51 = v50 + 16;
    *(_QWORD *)(v51 - 16) = "MinumTim";
    *(float *)(v51 - 8) = (float)v3;
    v49[1] = v51;
  }
}

// File Line: 736
// RVA: 0xD42600
hkpAgentNnEntry *__fastcall hkAgentNnMachine_FindAgent(hkpLinkedCollidable *collA, hkpLinkedCollidable *collB)
{
  hkpLinkedCollidable *v2; // r8
  hkpLinkedCollidable *v3; // rax
  __int64 v4; // r9
  int v5; // edx
  __int64 v6; // rcx
  hkpLinkedCollidable::CollisionEntry *v7; // r10
  hkpLinkedCollidable **v8; // rax

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
  v4 = v3->m_collisionEntries.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
    return 0i64;
  v7 = v3->m_collisionEntries.m_data;
  v8 = &v7->m_partner;
  while ( *v8 != v2 )
  {
    ++v6;
    ++v5;
    v8 += 2;
    if ( v6 >= v4 )
      return 0i64;
  }
  return v7[v5].m_agentEntry;
}

// File Line: 771
// RVA: 0xD40EF0
void __fastcall hkAgentNnMachine_AssertTrackValidity(hkpAgentNnTrack *track)
{
  __int64 v1; // rbx
  int v2; // er8
  __int64 v3; // r10
  hkpAgentNnSector **v4; // r9
  hkpAgentNnSector *v5; // rax
  unsigned __int64 v6; // rdx

  v1 = track->m_sectors.m_size;
  v2 = 0;
  v3 = v1;
  if ( (signed int)v1 > 0 )
  {
    v4 = track->m_sectors.m_data;
    do
    {
      v5 = *v4;
      ++v2;
      ++v4;
      if ( v2 == (_DWORD)v1 )
        v6 = (unsigned __int64)&v5->m_data[track->m_bytesUsedInLastSector];
      else
        v6 = (unsigned __int64)&v5[1];
      for ( ; (unsigned __int64)v5 < v6; v5 = (hkpAgentNnSector *)((char *)v5 + (unsigned __int8)v5->m_data[3]) )
        ;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 822
// RVA: 0xD42810
hkpCdBody *__fastcall hkAgentMachine_processTransformedShapes(hkpCdBody *cdBody, hkpCdBody *newCdBodies, hkMotionState *newMotionStates, int numSlots, hkPadSpu<unsigned char> *cdBodyHasTransformFlag)
{
  hkpShape *v5; // r10
  hkpCdBody *v6; // r9
  hkQuaternionf *v7; // rbx
  hkQuaternionf *v8; // r11
  signed __int64 v9; // rcx
  __m128 *v10; // rax
  __m128 v11; // xmm3
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

  v5 = cdBody->m_shape;
  v6 = cdBody;
  if ( cdBody->m_shape->m_type.m_storage == 14 )
  {
    v7 = &newMotionStates->m_sweptTransform.m_rotation0;
    do
    {
      v8 = (hkQuaternionf *)v6->m_motion;
      v9 = 3i64;
      v10 = (__m128 *)&v5[4];
      v11 = v8->m_vec.m_quad;
      v12 = v8[1].m_vec.m_quad;
      v13 = v8[2].m_vec.m_quad;
      do
      {
        v14 = *v10;
        --v10;
        --v9;
        *(__m128 *)((char *)v10 + (char *)&v7[-6] - (char *)&v5[2].m_type + 16) = _mm_add_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_mul_ps(
                                                                                        _mm_shuffle_ps(v14, v14, 85),
                                                                                        v12),
                                                                                      _mm_mul_ps(
                                                                                        _mm_shuffle_ps(v14, v14, 0),
                                                                                        v11)),
                                                                                    _mm_mul_ps(
                                                                                      _mm_shuffle_ps(v14, v14, 170),
                                                                                      v13));
      }
      while ( v9 >= 0 );
      v7[-3].m_vec.m_quad = _mm_add_ps(v8[3].m_vec.m_quad, v7[-3].m_vec.m_quad);
      v7[-2] = (hkQuaternionf)v8[4].m_vec.m_quad;
      v7[-1] = (hkQuaternionf)v8[5].m_vec.m_quad;
      v15 = v8[6].m_vec.m_quad;
      v16 = *(__m128 *)&v5[2].vfptr;
      v17 = _mm_shuffle_ps(*(__m128 *)&v5[2].vfptr, *(__m128 *)&v5[2].vfptr, 255);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v19 = _mm_mul_ps(v16, v15);
      v20 = _mm_shuffle_ps(v8[6].m_vec.m_quad, v8[6].m_vec.m_quad, 255);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(*(__m128 *)&v5[2].vfptr, v20)),
              _mm_mul_ps(v17, v15));
      v7->m_vec.m_quad = _mm_shuffle_ps(
                           v21,
                           _mm_unpackhi_ps(
                             v21,
                             _mm_sub_ps(
                               _mm_mul_ps(v17, v20),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                 _mm_shuffle_ps(v19, v19, 170)))),
                           196);
      v22 = v8[7].m_vec.m_quad;
      v23 = *(__m128 *)&v5[2].vfptr;
      v24 = _mm_shuffle_ps(v8[7].m_vec.m_quad, v8[7].m_vec.m_quad, 255);
      v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
      v26 = _mm_shuffle_ps(*(__m128 *)&v5[2].vfptr, *(__m128 *)&v5[2].vfptr, 255);
      v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22);
      v28 = _mm_mul_ps(v22, v23);
      v29 = _mm_sub_ps(v27, v25);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(*(__m128 *)&v5[2].vfptr, v24)),
              _mm_mul_ps(v8[7].m_vec.m_quad, v26));
      v7[1].m_vec.m_quad = _mm_shuffle_ps(
                             v30,
                             _mm_unpackhi_ps(
                               v30,
                               _mm_sub_ps(
                                 _mm_mul_ps(v26, v24),
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                                   _mm_shuffle_ps(v28, v28, 170)))),
                             196);
      v31 = _mm_sub_ps(v8[8].m_vec.m_quad, *(__m128 *)&v5[4].vfptr);
      v32 = *(__m128 *)&v5[3].m_type.m_storage;
      v33 = _mm_unpacklo_ps(*(__m128 *)&v5[2].m_type.m_storage, *(__m128 *)&v5[3].vfptr);
      v34 = _mm_movelh_ps(v33, v32);
      v7[2].m_vec.m_quad = _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v31, v31, 85),
                                 _mm_shuffle_ps(_mm_movehl_ps(v34, v33), v32, 212)),
                               _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v34)),
                             _mm_mul_ps(
                               _mm_shuffle_ps(v31, v31, 170),
                               _mm_shuffle_ps(
                                 _mm_unpackhi_ps(*(__m128 *)&v5[2].m_type.m_storage, *(__m128 *)&v5[3].vfptr),
                                 v32,
                                 228)));
      v7[3] = (hkQuaternionf)v8[9].m_vec.m_quad;
      v7[4].m_vec.m_quad.m128_i32[0] = v8[10].m_vec.m_quad.m128_i32[0];
      if ( newCdBodies )
      {
        newCdBodies->m_parent = v6;
        newCdBodies->m_motion = &v7[-6];
      }
      v35 = *(hkpShape **)&v5[1].m_memSizeAndFlags;
      newCdBodies->m_shapeKey = 0;
      v6 = newCdBodies;
      newCdBodies->m_shape = v35;
      v5 = newCdBodies->m_shape;
      ++newCdBodies;
      v7 += 11;
      cdBodyHasTransformFlag->m_storage = 8;
    }
    while ( v5->m_type.m_storage == 14 );
  }
  return v6;
}

// File Line: 888
// RVA: 0xD42800
void __fastcall hkAgentNnMachine_TouchAgent(hkpAgentEntry *entry, hkpProcessCollisionInput *input)
{
  ;
}

