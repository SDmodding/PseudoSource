// File Line: 43
// RVA: 0xE20DD0
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(hkpSaveContactPointsUtil::SavePointsInput *input, hkpWorld *world, hkpPhysicsSystemWithContacts *sys)
{
  int v3; // eax
  hkProcess **v4; // r9
  hkpPhysicsSystemWithContacts *v5; // r15
  hkpWorld *v6; // r13
  __int64 v7; // r8
  hkpSimulationIsland **v8; // r10
  __int64 v9; // rcx
  hkProcess *v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rcx
  signed __int64 v13; // rax
  unsigned __int16 *v14; // r14
  int v15; // ebp
  int v16; // ecx
  __int64 v17; // r12
  hkpAgentNnEntry *v18; // rdi
  unsigned __int64 v19; // rsi
  _QWORD **v20; // rax
  hkpSerializedAgentNnEntry *v21; // rax
  hkpSerializedAgentNnEntry *v22; // rax
  hkpSerializedAgentNnEntry *v23; // rbx
  signed __int64 v24; // [rsp+30h] [rbp-78h]
  __int64 v25; // [rsp+38h] [rbp-70h]
  unsigned __int16 *v26; // [rsp+40h] [rbp-68h]
  hkArrayBase<hkProcess *> v27; // [rsp+48h] [rbp-60h]
  __int64 v28; // [rsp+58h] [rbp-50h]
  __int64 v29; // [rsp+60h] [rbp-48h]
  hkpSaveContactPointsUtil::SavePointsInput *inputa; // [rsp+B0h] [rbp+8h]
  int v31; // [rsp+B8h] [rbp+10h]
  hkResult result; // [rsp+C8h] [rbp+20h]

  inputa = input;
  v3 = world->m_activeSimulationIslands.m_size;
  v4 = 0i64;
  v27.m_data = 0i64;
  v27.m_size = 0;
  v5 = sys;
  v6 = world;
  v27.m_capacityAndFlags = 2147483648;
  if ( v3 > 0 )
  {
    v31 = 8 * v3;
    v4 = (hkProcess **)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, hkpPhysicsSystemWithContacts *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                         &hkContainerHeapAllocator::s_alloc,
                         &v31,
                         sys,
                         0i64);
    v27.m_data = v4;
    v27.m_capacityAndFlags = v31 / 8;
  }
  v7 = v6->m_activeSimulationIslands.m_size;
  v8 = v6->m_activeSimulationIslands.m_data;
  v9 = 0i64;
  v27.m_size = v7;
  if ( (signed int)v7 > 0 )
  {
    do
    {
      v10 = (hkProcess *)v8[v9++];
      v4[v9 - 1] = v10;
    }
    while ( v9 < v7 );
    LODWORD(v7) = v27.m_size;
  }
  hkArrayBase<hkpEntity *>::_insertAt(
    &v27,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v7,
    (hkProcess *const *)v6->m_inactiveSimulationIslands.m_data,
    v6->m_inactiveSimulationIslands.m_size);
  v31 = 0;
  if ( v27.m_size > 0 )
  {
    v11 = 0i64;
    v25 = 0i64;
    do
    {
      v12 = *(__int64 *)((char *)v27.m_data + v11);
      v28 = v12 + 152;
      v29 = v12 + 120;
      v13 = 0i64;
      v24 = 0i64;
      do
      {
        v14 = (unsigned __int16 *)*(&v28 + v13);
        v15 = 0;
        v16 = *((_DWORD *)v14 + 4);
        v26 = (unsigned __int16 *)*(&v28 + v13);
        if ( v16 > 0 )
        {
          v17 = 0i64;
          do
          {
            ++v15;
            v17 += 8i64;
            v18 = *(hkpAgentNnEntry **)(v17 + *((_QWORD *)v14 + 1) - 8);
            if ( v15 == v16 )
              v19 = (unsigned __int64)v18 + *v14;
            else
              v19 = (unsigned __int64)&v18[24];
            if ( (unsigned __int64)v18 < v19 )
            {
              do
              {
                v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v21 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(
                                                     v20[11],
                                                     400i64);
                if ( v21 )
                {
                  hkpSerializedAgentNnEntry::hkpSerializedAgentNnEntry(v21);
                  v23 = v22;
                }
                else
                {
                  v23 = 0i64;
                }
                if ( hkpSaveContactPointsUtil::serializeCollisionEntry(&result, inputa, v18, v6->m_collisionInput, v23)->m_enum == HK_SUCCESS )
                  hkpPhysicsSystemWithContacts::addContact(v5, v23);
                hkReferencedObject::removeReference((hkReferencedObject *)&v23->vfptr);
                v18 = (hkpAgentNnEntry *)((char *)v18 + (unsigned __int8)v18->m_size);
              }
              while ( (unsigned __int64)v18 < v19 );
              v14 = v26;
            }
            v16 = *((_DWORD *)v14 + 4);
          }
          while ( v15 < v16 );
          v13 = v24;
        }
        v24 = ++v13;
      }
      while ( v13 < 2 );
      v11 = v25 + 8;
      ++v31;
      v25 += 8i64;
    }
    while ( v31 < v27.m_size );
  }
  v27.m_size = 0;
  if ( v27.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v27.m_data,
      8 * v27.m_capacityAndFlags);
}

// File Line: 74
// RVA: 0xE210A0
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(hkpSaveContactPointsUtil::SavePointsInput *input, hkpEntity **entities, int numEntities, hkpPhysicsSystemWithContacts *sys)
{
  __int64 v4; // rsi
  hkpPhysicsSystemWithContacts *v5; // r15
  hkpWorld *v6; // r13
  __int64 v7; // rbx
  hkpEntity **v8; // rdi
  hkpSaveContactPointsUtil::SavePointsInput *v9; // r12
  __int64 v10; // rbp
  hkpLinkedCollidable *v11; // rcx
  int v12; // edi
  hkpLinkedCollidable::CollisionEntry *v13; // r14
  int v14; // eax
  _QWORD **v15; // rax
  hkpSerializedAgentNnEntry *v16; // rax
  hkpSerializedAgentNnEntry *v17; // rax
  hkpSerializedAgentNnEntry *serializedEntryOut; // rbx
  __int64 i; // [rsp+30h] [rbp-68h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+38h] [rbp-60h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v21; // [rsp+48h] [rbp-50h]
  hkpEntity **v22; // [rsp+A8h] [rbp+10h]
  hkResult result; // [rsp+B0h] [rbp+18h]

  v22 = entities;
  v4 = 0i64;
  v5 = sys;
  v6 = (*entities)->m_world;
  v7 = numEntities;
  v8 = entities;
  v21.m_elem = 0i64;
  v21.m_numElems = 0;
  v21.m_hashMod = -1;
  v9 = input;
  if ( numEntities )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v21,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      numEntities);
  v10 = 0i64;
  for ( i = v7; v10 < v7; entries.m_capacityAndFlags = 2147483648 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v21,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)&v8[v10]->m_collidable,
      0i64);
    v11 = &v8[v10]->m_collidable;
    entries.m_data = 0i64;
    entries.m_size = 0;
    entries.m_capacityAndFlags = 2147483648;
    hkpLinkedCollidable::getCollisionEntriesSorted(v11, &entries);
    v12 = 0;
    if ( entries.m_size > 0 )
    {
      do
      {
        v13 = entries.m_data;
        v14 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v21,
                                  (unsigned __int64)entries.m_data[v4].m_partner);
        if ( v14 > v21.m_hashMod )
        {
          v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v16 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                               v15[11],
                                               400i64);
          if ( v16 )
          {
            hkpSerializedAgentNnEntry::hkpSerializedAgentNnEntry(v16);
            serializedEntryOut = v17;
          }
          else
          {
            serializedEntryOut = 0i64;
          }
          if ( hkpSaveContactPointsUtil::serializeCollisionEntry(
                 &result,
                 v9,
                 v13[v4].m_agentEntry,
                 v6->m_collisionInput,
                 serializedEntryOut)->m_enum == HK_SUCCESS )
            hkpPhysicsSystemWithContacts::addContact(v5, serializedEntryOut);
          hkReferencedObject::removeReference((hkReferencedObject *)&serializedEntryOut->vfptr);
        }
        ++v12;
        ++v4;
      }
      while ( v12 < entries.m_size );
      v7 = i;
      v4 = 0i64;
    }
    entries.m_size = 0;
    if ( entries.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * entries.m_capacityAndFlags);
    v8 = v22;
    ++v10;
    entries.m_data = 0i64;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v21,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v21);
}

// File Line: 109
// RVA: 0xE21280
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(hkpSaveContactPointsUtil::SavePointsInput *input, hkpAgentNnEntry **entries, int numEntries, hkpPhysicsSystemWithContacts *sys)
{
  hkpPhysicsSystemWithContacts *v4; // rbp
  hkpAgentNnEntry **v5; // r14
  hkpLinkedCollidable *v6; // r10
  hkpSaveContactPointsUtil::SavePointsInput *v7; // r12
  char *v8; // rax
  __int64 v9; // r15
  __int64 v10; // rdi
  __int64 v11; // rsi
  _QWORD **v12; // rax
  hkpSerializedAgentNnEntry *v13; // rax
  hkpSerializedAgentNnEntry *v14; // rax
  hkpSerializedAgentNnEntry *serializedEntryOut; // rbx
  hkResult result; // [rsp+70h] [rbp+18h]

  v4 = sys;
  v5 = entries;
  v6 = (*entries)->m_collidable[0];
  v7 = input;
  if ( v6->m_broadPhaseHandle.m_type == 1 )
    v8 = (char *)v6 + v6->m_ownerOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 2);
  v10 = 0i64;
  v11 = numEntries;
  if ( numEntries > 0 )
  {
    do
    {
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                           v12[11],
                                           400i64);
      if ( v13 )
      {
        hkpSerializedAgentNnEntry::hkpSerializedAgentNnEntry(v13);
        serializedEntryOut = v14;
      }
      else
      {
        serializedEntryOut = 0i64;
      }
      if ( hkpSaveContactPointsUtil::serializeCollisionEntry(
             &result,
             v7,
             v5[v10],
             *(hkpProcessCollisionInput **)(v9 + 184),
             serializedEntryOut)->m_enum == HK_SUCCESS )
        hkpPhysicsSystemWithContacts::addContact(v4, serializedEntryOut);
      hkReferencedObject::removeReference((hkReferencedObject *)&serializedEntryOut->vfptr);
      ++v10;
    }
    while ( v10 < v11 );
  }
}

// File Line: 152
// RVA: 0xE22B90
unsigned __int64 __fastcall `anonymous namespace'::hkEntitySelectorListed::isEntityOk(hkEntitySelectorListed *this, hkpEntity *entity)
{
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_map.m_elem,
           (unsigned __int64)entity,
           0i64);
}

// File Line: 164
// RVA: 0xE22BA0
void __fastcall hkpSaveContactPointsUtil::loadContactPointsInternal(hkpSaveContactPointsUtil::LoadPointsInput *input, hkpPhysicsSystemWithContacts *sys, hkpWorld *world, hkpSaveContactPointsUtil::EntitySelector *selector)
{
  hkpSaveContactPointsUtil::EntitySelector *v4; // r13
  hkpWorld *v5; // rsi
  int v6; // er15
  hkpPhysicsSystemWithContacts *v7; // rdi
  hkpSaveContactPointsUtil::LoadPointsInput *v8; // r14
  __int64 i; // r12
  hkpSerializedAgentNnEntry *v10; // rbx
  hkpEntity *v11; // rbp
  __int64 v12; // r14
  hkpAgentNnEntry *entry; // r13
  hkpEntity *entityB; // ST20_8
  __int64 v15; // rax
  bool v16; // zf
  hkpSaveContactPointsUtil::LoadPointsInput *inputa; // [rsp+80h] [rbp+8h]
  hkResult result; // [rsp+88h] [rbp+10h]
  hkpSaveContactPointsUtil::EntitySelector *v19; // [rsp+98h] [rbp+20h]

  v19 = selector;
  inputa = input;
  ++world->m_criticalOperationsLockCount;
  v4 = selector;
  v5 = world;
  v6 = sys->m_contacts.m_size - 1;
  v7 = sys;
  v8 = input;
  for ( i = v6; i >= 0; --i )
  {
    v10 = v7->m_contacts.m_data[i];
    if ( v10->m_useEntityIds.m_bool )
    {
      v11 = v8->m_getEntityFromId(v10->m_bodyAId);
      v12 = (__int64)v8->m_getEntityFromId(v10->m_bodyBId);
    }
    else
    {
      v11 = v10->m_bodyA;
      v12 = (__int64)v10->m_bodyB;
    }
    if ( v11 && v12 && (v4->vfptr->isEntityOk(v4, v11) || v4->vfptr->isEntityOk(v4, (hkpEntity *)v12)) )
    {
      entry = hkAgentNnMachine_FindAgent(&v11->m_collidable, (hkpLinkedCollidable *)(v12 + 32));
      if ( entry )
      {
        if ( *(_DWORD *)v10->m_endianCheckBuffer != 259 )
          hkpSaveContactPointsEndianUtil::swapEndianTypeInCollisionEntry(v5->m_collisionInput, v10);
        entityB = (hkpEntity *)v12;
        v8 = inputa;
        hkpSaveContactPointsUtil::deserializeCollisionEntry(
          &result,
          inputa,
          v10,
          v11,
          entityB,
          v5->m_collisionInput,
          entry);
        if ( inputa->m_removeSerializedAgentsWhenLoaded && result.m_enum == 1 )
        {
          hkReferencedObject::removeReference((hkReferencedObject *)&v7->m_contacts.m_data[i]->vfptr);
          v15 = --v7->m_contacts.m_size;
          v4 = v19;
          if ( (_DWORD)v15 != v6 )
            v7->m_contacts.m_data[i] = v7->m_contacts.m_data[v15];
        }
        else
        {
          v4 = v19;
        }
        goto LABEL_18;
      }
      v4 = v19;
    }
    v8 = inputa;
LABEL_18:
    --v6;
  }
  v16 = v5->m_criticalOperationsLockCount-- == 1;
  if ( v16 && !v5->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v5->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v5);
    if ( v5->m_pendingOperationQueueCount == 1 )
    {
      if ( v5->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v5);
    }
  }
}

// File Line: 222
// RVA: 0xE21360
void __fastcall hkpSaveContactPointsUtil::loadContactPoints(hkpSaveContactPointsUtil::LoadPointsInput *input, hkpPhysicsSystemWithContacts *sys, hkpWorld *world)
{
  hkpSaveContactPointsUtil::EntitySelector selector; // [rsp+48h] [rbp+20h]

  selector.vfptr = (hkpSaveContactPointsUtil::EntitySelectorVtbl *)&`anonymous namespace'::hkEntitySelectorAll::`vftable';
  hkpSaveContactPointsUtil::loadContactPointsInternal(input, sys, world, &selector);
}

// File Line: 228
// RVA: 0xE21390
void __fastcall hkpSaveContactPointsUtil::loadContactPoints(hkpSaveContactPointsUtil::LoadPointsInput *input, hkpPhysicsSystemWithContacts *sys, hkpEntity **entities, int numEntities)
{
  hkpSaveContactPointsUtil::LoadPointsInput *v4; // r14
  __int64 v5; // rbx
  hkpWorld *v6; // r15
  __int64 v7; // rdi
  hkpEntity **v8; // rsi
  hkpPhysicsSystemWithContacts *v9; // rbp
  hkpSaveContactPointsUtil::EntitySelector selector; // [rsp+20h] [rbp-38h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v11; // [rsp+28h] [rbp-30h]

  v4 = input;
  v5 = 0i64;
  v6 = (*entities)->m_world;
  selector.vfptr = (hkpSaveContactPointsUtil::EntitySelectorVtbl *)&`anonymous namespace'::hkEntitySelectorListed::`vftable';
  v7 = numEntities;
  v8 = entities;
  v9 = sys;
  v11.m_elem = 0i64;
  v11.m_numElems = 0;
  v11.m_hashMod = -1;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&v11);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v11,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v7);
  if ( v7 > 0 )
  {
    do
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v11,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v8[v5++],
        1ui64);
    while ( v5 < v7 );
  }
  hkpSaveContactPointsUtil::loadContactPointsInternal(v4, v9, v6, &selector);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v11,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v11);
}

// File Line: 239
// RVA: 0xE21470
hkResult *__fastcall hkpSaveContactPointsUtil::serializeCollisionEntry(hkResult *result, hkpSaveContactPointsUtil::SavePointsInput *input, hkpAgentNnEntry *entry, hkpProcessCollisionInput *collisionInput, hkpSerializedAgentNnEntry *serializedEntryOut)
{
  hkResult *v5; // rdi
  hkpProcessCollisionInput *v6; // rsi
  hkpAgentNnEntry *v7; // rbp
  hkpSaveContactPointsUtil::SavePointsInput *v8; // r13
  hkpSerializedAgentNnEntry *v9; // rbx
  int v10; // er8
  hkpContactMgr *v11; // r14
  int v12; // er15
  int v13; // eax
  int v14; // eax
  int v15; // er9
  __int64 v16; // rdx
  int v17; // er8
  char v18; // al
  __int64 v19; // rsi
  int v20; // er15
  int v21; // eax
  int v22; // eax
  int v23; // er9
  int v24; // er15
  int v25; // eax
  int v26; // eax
  int v27; // er9
  __int64 v28; // rcx
  hkpLinkedCollidable *v29; // rax
  hkReferencedObject *v30; // rcx
  hkpLinkedCollidable *v31; // rax
  hkpEntity *v32; // rsi
  bool v33; // al
  hkResult *v34; // rax
  int n; // [rsp+40h] [rbp-38h]
  hkResult resulta; // [rsp+44h] [rbp-34h]
  hkpAgent1nTrack *agent1nTrackOut; // [rsp+48h] [rbp-30h]
  hkpSerializedAgentNnEntry::SerializedAgentType agentTypeOut; // [rsp+90h] [rbp+18h]

  v5 = result;
  v6 = collisionInput;
  v7 = entry;
  v8 = input;
  if ( ((unsigned int (*)(void))entry->m_contactMgr->vfptr[6].__first_virtual_table_function__)()
    || !*(_WORD *)(*(_QWORD *)&v7->m_contactMgr[4].m_memSizeAndFlags + 4i64) )
  {
    v5->m_enum = 1;
    v34 = v5;
  }
  else
  {
    v9 = serializedEntryOut;
    n = -1;
    agentTypeOut = 0;
    if ( hkpSaveContactPointsUtil::serializeEntry(
           &resulta,
           (hkpAgentEntry *)&v7->m_streamCommand,
           (hkBool)1,
           v6,
           &n,
           &agentTypeOut,
           &agent1nTrackOut,
           &serializedEntryOut->m_trackInfo)->m_enum )
    {
      v5->m_enum = 1;
    }
    else
    {
      v10 = n;
      v9->m_agentType.m_storage = agentTypeOut;
      if ( v10 )
        hkString::memCpy(v9->m_nnEntryData, v7, v10);
      v11 = v7->m_contactMgr;
      v12 = (int)v11[3].vfptr;
      v13 = v9->m_cpIdMgr.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v13 < v12 )
      {
        v14 = 2 * v13;
        v15 = (int)v11[3].vfptr;
        if ( v12 < v14 )
          v15 = v14;
        hkArrayUtil::_reserve(
          (hkResult *)&agentTypeOut,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v9->m_cpIdMgr,
          v15,
          1);
      }
      v16 = 0i64;
      v17 = 0;
      for ( v9->m_cpIdMgr.m_size = v12; v17 < v9->m_cpIdMgr.m_size; v9->m_cpIdMgr.m_data[v16 - 1] = v18 )
      {
        ++v17;
        v18 = *(_BYTE *)(v16++ + *(_QWORD *)&v11[2].m_type);
      }
      v19 = *(_QWORD *)&v11[4].m_memSizeAndFlags;
      v20 = *(unsigned __int16 *)(v19 + 4) * *(unsigned __int8 *)(v19 + 10);
      v21 = v9->m_propertiesStream.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v21 < v20 )
      {
        v22 = 2 * v21;
        v23 = *(unsigned __int16 *)(v19 + 4) * *(unsigned __int8 *)(v19 + 10);
        if ( v20 < v22 )
          v23 = v22;
        hkArrayUtil::_reserve(
          (hkResult *)&agentTypeOut,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v9->m_propertiesStream,
          v23,
          1);
      }
      v9->m_propertiesStream.m_size = v20;
      hkString::memCpy(
        v9->m_propertiesStream.m_data,
        (const void *)(32i64 * *(unsigned __int16 *)(v19 + 6) + v19 + 48),
        *(unsigned __int16 *)(v19 + 4) * *(unsigned __int8 *)(v19 + 10));
      v24 = *(unsigned __int16 *)(v19 + 4);
      v25 = v9->m_contactPoints.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v25 < v24 )
      {
        v26 = 2 * v25;
        v27 = *(unsigned __int16 *)(v19 + 4);
        if ( v24 < v26 )
          v27 = v26;
        hkArrayUtil::_reserve(
          (hkResult *)&agentTypeOut,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v9->m_contactPoints,
          v27,
          32);
      }
      v9->m_contactPoints.m_size = v24;
      hkString::memCpy(v9->m_contactPoints.m_data, (const void *)(v19 + 48), 32 * *(unsigned __int16 *)(v19 + 4));
      v28 = *(_QWORD *)&v11[4].m_memSizeAndFlags;
      v9->m_atom.m_type.m_storage = *(_WORD *)v28;
      v9->m_atom.m_sizeOfAllAtoms = *(_WORD *)(v28 + 2);
      v9->m_atom.m_numContactPoints = *(_WORD *)(v28 + 4);
      v9->m_atom.m_numReservedContactPoints = *(_WORD *)(v28 + 6);
      v9->m_atom.m_numUserDatasForBodyA = *(_BYTE *)(v28 + 8);
      v9->m_atom.m_numUserDatasForBodyB = *(_BYTE *)(v28 + 9);
      v9->m_atom.m_contactPointPropertiesStriding = *(_BYTE *)(v28 + 10);
      v9->m_atom.m_maxNumContactPoints = *(_WORD *)(v28 + 12);
      v9->m_atom.m_info.m_flags = *(_WORD *)(v28 + 16);
      v9->m_atom.m_info.m_biNormalAxis = *(_WORD *)(v28 + 18);
      v9->m_atom.m_info.m_rollingFrictionMultiplier.m_value = *(_WORD *)(v28 + 20);
      v9->m_atom.m_info.m_internalData1.m_value = *(_WORD *)(v28 + 22);
      v9->m_atom.m_info.m_rhsRolling[0].m_value = *(_WORD *)(v28 + 24);
      v9->m_atom.m_info.m_rhsRolling[1].m_value = *(_WORD *)(v28 + 26);
      v9->m_atom.m_info.m_contactRadius = *(float *)(v28 + 28);
      v9->m_atom.m_info.m_data[0] = *(float *)(v28 + 32);
      v9->m_atom.m_info.m_data[1] = *(float *)(v28 + 36);
      v9->m_atom.m_info.m_data[2] = *(float *)(v28 + 40);
      v9->m_atom.m_info.m_data[3] = *(float *)(v28 + 44);
      v29 = v7->m_collidable[0];
      if ( v29->m_broadPhaseHandle.m_type == 1 )
        v30 = (hkReferencedObject *)((char *)v29 + v29->m_ownerOffset);
      else
        v30 = 0i64;
      v31 = v7->m_collidable[1];
      if ( v31->m_broadPhaseHandle.m_type == 1 )
        v32 = (hkpEntity *)((char *)v31 + v31->m_ownerOffset);
      else
        v32 = 0i64;
      v33 = v8->m_useEntityIds;
      v9->m_useEntityIds.m_bool = v8->m_useEntityIds;
      if ( v33 )
      {
        v9->m_bodyAId = v8->m_getIdForEntity((hkpEntity *)v30);
        v9->m_bodyBId = v8->m_getIdForEntity(v32);
      }
      else
      {
        v9->m_bodyA = (hkpEntity *)v30;
        v9->m_bodyB = v32;
        hkReferencedObject::addReference(v30);
        hkReferencedObject::addReference((hkReferencedObject *)&v9->m_bodyB->vfptr);
      }
      v5->m_enum = 0;
    }
    v34 = v5;
  }
  return v34;
}

// File Line: 321
// RVA: 0xE217F0
hkResult *__fastcall hkpSaveContactPointsUtil::deserializeCollisionEntry(hkResult *result, hkpSaveContactPointsUtil::LoadPointsInput *input, hkpSerializedAgentNnEntry *serializedEntryIn, hkpEntity *entityA, hkpEntity *entityB, hkpProcessCollisionInput *collisionInput, hkpAgentNnEntry *entry)
{
  hkpEntity *v7; // r15
  hkpAgentNnEntry *nnEntry; // rbx
  hkpSimulationIsland *constraintOwner; // rax
  hkpContactMgr *v10; // rsi
  hkpSerializedAgentNnEntry *v11; // r13
  hkpSimulationIsland *v12; // r8
  hkpEntity *v13; // r14
  hkResult *v14; // r12
  hkpProcessCollisionInput *v15; // rdi
  hkpLinkedCollidable *v16; // rcx
  hkpEntity *v17; // rax
  unsigned __int16 v18; // cx
  hkBaseObjectVtbl *v19; // rcx
  hkBaseObjectVtbl *v20; // rdx
  void (__fastcall *v21)(hkBaseObject *); // rcx
  int v22; // er12
  int v23; // eax
  int v24; // eax
  int v25; // er9
  int v26; // er12
  __int64 v27; // rdx
  int i; // er8
  char v29; // al
  hkpLinkedCollidable *v30; // rax
  char *v31; // rbx
  hkpWorld *v32; // rbx
  __int64 v33; // r10
  signed int v34; // ecx
  int v35; // er8
  int v36; // er9
  int v37; // edx
  hkBaseObjectVtbl *v38; // rcx
  _DWORD *v39; // rax
  hkBaseObjectVtbl *v40; // rcx
  __int64 v41; // rdi
  unsigned int v42; // ebx
  _QWORD **v43; // rax
  int v44; // ebx
  hkpSimpleContactConstraintAtom *v45; // rax
  __int64 v46; // rcx
  hkBaseObjectVtbl *v47; // rcx
  __int64 v48; // r8
  signed int v49; // ecx
  int v50; // er9
  int v51; // er10
  int v52; // edx
  int v53; // er11
  _DWORD *v54; // r8
  int v55; // eax
  hkBaseObjectVtbl *v56; // rcx
  int v57; // ecx
  __int64 v58; // r8
  hkpSaveContactPointsUtil::LoadPointsInput *v59; // rbx
  __int64 v60; // rcx
  signed __int64 v61; // rdx
  unsigned int v62; // eax
  hkBaseObjectVtbl *v63; // rax
  int v64; // eax
  __int64 v65; // r13
  bool v66; // zf
  unsigned __int16 v67; // di
  hkpContactPointProperties *v68; // rbx
  hkContactPoint *v69; // rax
  __int64 v70; // rdi
  __int64 v71; // r13
  unsigned __int16 v72; // r12
  __int64 v73; // rbx
  hkpGskCache *v74; // rax
  hkpWorld *v75; // rcx
  int v76; // er8
  hkResult *v77; // rax
  int v78; // [rsp+34h] [rbp-CCh]
  __int16 v79; // [rsp+34h] [rbp-CCh]
  __int16 v80; // [rsp+38h] [rbp-C8h]
  __int16 v81; // [rsp+38h] [rbp-C8h]
  __int16 v82; // [rsp+3Ch] [rbp-C4h]
  __int16 v83; // [rsp+3Ch] [rbp-C4h]
  _WORD *v84; // [rsp+40h] [rbp-C0h]
  int v85; // [rsp+48h] [rbp-B8h]
  int v86; // [rsp+4Ch] [rbp-B4h]
  hkpContactPointAddedEvent event; // [rsp+50h] [rbp-B0h]
  __int64 v88; // [rsp+A8h] [rbp-58h]
  __int64 v89; // [rsp+B0h] [rbp-50h]
  char v90; // [rsp+C0h] [rbp-40h]
  __int64 v91; // [rsp+C8h] [rbp-38h]
  int v92; // [rsp+30F0h] [rbp+2FF0h]
  __int64 v93; // [rsp+3110h] [rbp+3010h]
  hkResult *v94; // [rsp+31B0h] [rbp+30B0h]
  hkpSaveContactPointsUtil::LoadPointsInput *v95; // [rsp+31B8h] [rbp+30B8h]
  hkpCdBody *v96; // [rsp+31C0h] [rbp+30C0h]

  v95 = input;
  v94 = result;
  v7 = entityB;
  nnEntry = entry;
  constraintOwner = entityA->m_simulationIsland;
  v10 = entry->m_contactMgr;
  v11 = serializedEntryIn;
  v12 = entityB->m_simulationIsland;
  v13 = entityA;
  v14 = result;
  if ( constraintOwner != v12 )
  {
    if ( entityA->m_motion.m_type.m_storage == 5 )
    {
      constraintOwner = entityB->m_simulationIsland;
    }
    else if ( entityB->m_motion.m_type.m_storage != 5 )
    {
      constraintOwner = hkpWorldAgentUtil::getIslandFromAgentEntry(entry, entityA->m_simulationIsland, v12);
    }
  }
  v15 = collisionInput;
  if ( hkpSaveContactPointsUtil::destroyOldEntry(
         (hkResult *)&entityB,
         (hkpSerializedAgentNnEntry::SerializedAgentType)v11->m_agentType.m_storage,
         collisionInput,
         (hkpDynamicsContactMgr *)v10,
         (hkpConstraintOwner *)&constraintOwner->vfptr,
         nnEntry)->m_enum )
    goto LABEL_73;
  v16 = nnEntry->m_collidable[0];
  v17 = 0i64;
  if ( v16->m_broadPhaseHandle.m_type == 1 )
    v17 = (hkpEntity *)((char *)v16 + v16->m_ownerOffset);
  if ( v13 != v17 )
  {
    nnEntry->m_collidable[0] = nnEntry->m_collidable[1];
    nnEntry->m_collidable[1] = v16;
    v18 = nnEntry->m_agentIndexOnCollidable[0];
    nnEntry->m_agentIndexOnCollidable[0] = nnEntry->m_agentIndexOnCollidable[1];
    nnEntry->m_agentIndexOnCollidable[1] = v18;
    v19 = *(hkBaseObjectVtbl **)&v10[6].m_type;
    *(_QWORD *)&v10[6].m_type = v10[7].vfptr;
    v10[7].vfptr = v19;
    v20 = v10[9].vfptr;
    if ( v20 )
    {
      v21 = v20->__first_virtual_table_function__;
      v20->__first_virtual_table_function__ = (void (__fastcall *)(hkBaseObject *))v20[1].__vecDelDtor;
      v20[1].__vecDelDtor = (void *(__fastcall *)(hkBaseObject *, unsigned int))v21;
      BYTE2(v10[9].vfptr[2].__first_virtual_table_function__) = BYTE2(v10[9].vfptr[2].__first_virtual_table_function__) == 0;
    }
  }
  if ( hkpSaveContactPointsUtil::deserializeEntry(
         (hkResult *)&entityB,
         v11,
         (hkpSerializedAgentNnEntry::SerializedAgentType)v11->m_agentType.m_storage,
         &v11->m_trackInfo,
         v15,
         nnEntry)->m_enum )
  {
LABEL_73:
    v14->m_enum = 1;
    v77 = v14;
  }
  else
  {
    v22 = v11->m_cpIdMgr.m_size;
    v23 = HIDWORD(v10[3].vfptr) & 0x3FFFFFFF;
    if ( v23 < v22 )
    {
      v24 = 2 * v23;
      v25 = v11->m_cpIdMgr.m_size;
      if ( v22 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(
        (hkResult *)&entityB,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v10[2].m_type,
        v25,
        1);
    }
    LODWORD(v10[3].vfptr) = v22;
    v26 = 0;
    v27 = 0i64;
    for ( i = 0; i < SLODWORD(v10[3].vfptr); *(_BYTE *)(v27 + *(_QWORD *)&v10[2].m_type - 1) = v29 )
    {
      ++i;
      v29 = v11->m_cpIdMgr.m_data[v27++];
    }
    if ( !*(_WORD *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 4i64) )
    {
      v30 = nnEntry->m_collidable[0];
      if ( v30->m_broadPhaseHandle.m_type == 1 )
        v31 = (char *)v30 + v30->m_ownerOffset;
      else
        v31 = 0i64;
      v32 = (hkpWorld *)*((_QWORD *)v31 + 2);
      --v32->m_criticalOperationsLockCount;
      v32->m_blockExecutingPendingOperations.m_bool = 1;
      hkpWorldOperationUtil::addConstraintImmediately(v32, (hkpConstraintInstance *)&v10[5], DO_FIRE_CALLBACKS);
      ++v32->m_criticalOperationsLockCount;
      v32->m_blockExecutingPendingOperations.m_bool = 0;
    }
    v33 = *(_QWORD *)&v10[4].m_memSizeAndFlags;
    v34 = *(unsigned __int16 *)(v33 + 4);
    v35 = v34 + 2;
    v36 = v34 + 3;
    v80 = v34 + 2;
    v82 = v34 + 3;
    v37 = 112 * (v34 >> 1) + 48 * ((*(_WORD *)(v33 + 4) & 1) + 3);
    v78 = 112 * (v34 >> 1) + 48 * ((*(_WORD *)(v33 + 4) & 1) + 3);
    if ( v34 >= 2 )
    {
      v37 += 48;
      v35 = v34 + 3;
      v36 = v34 + 4;
      v82 = v34 + 4;
      LOWORD(v78) = v37;
      v80 = v34 + 3;
    }
    LODWORD(entityB) = *(signed __int16 *)(v33 + 20) << 16;
    if ( *(float *)&entityB != 0.0 )
    {
      v37 += 96;
      v35 += 2;
      v36 += 3;
      v82 = v36;
      LOWORD(v78) = v37;
      v80 = v35;
    }
    v38 = v10[9].vfptr;
    if ( v38 )
    {
      v39 = *(_DWORD **)(*((_QWORD *)&v38->__first_virtual_table_function__
                         + BYTE2(v38[2].__first_virtual_table_function__))
                       + 296i64);
      v39[5] -= v37;
      v39[6] -= v35;
      v39[7] -= v36;
      v40 = v10[9].vfptr;
      HIWORD(v40[2].__vecDelDtor) -= v80;
      LOWORD(v40[2].__first_virtual_table_function__) -= v82;
      WORD2(v40[2].__vecDelDtor) -= v78;
    }
    v41 = *(_QWORD *)&v10[4].m_memSizeAndFlags;
    v42 = atomSizeRoundUp(*(unsigned __int16 *)(v41 + 2));
    v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v43[11] + 16i64))(v43[11], v41, v42);
    v44 = v11->m_atom.m_numContactPoints;
    v45 = hkpSimpleContactConstraintAtomUtil::allocateAtom(
            v44,
            (unsigned __int8)v11->m_atom.m_numUserDatasForBodyA,
            (unsigned __int8)v11->m_atom.m_numUserDatasForBodyB,
            v11->m_atom.m_maxNumContactPoints);
    *(_QWORD *)&v10[4].m_memSizeAndFlags = v45;
    v45->m_numContactPoints = v44;
    v46 = *(_QWORD *)&v10[4].m_memSizeAndFlags;
    *(_WORD *)(v46 + 16) = v11->m_atom.m_info.m_flags;
    *(_WORD *)(v46 + 18) = v11->m_atom.m_info.m_biNormalAxis;
    *(_WORD *)(v46 + 20) = v11->m_atom.m_info.m_rollingFrictionMultiplier.m_value;
    *(_WORD *)(v46 + 22) = v11->m_atom.m_info.m_internalData1.m_value;
    *(_WORD *)(v46 + 24) = v11->m_atom.m_info.m_rhsRolling[0].m_value;
    *(_WORD *)(v46 + 26) = v11->m_atom.m_info.m_rhsRolling[1].m_value;
    *(float *)(v46 + 28) = v11->m_atom.m_info.m_contactRadius;
    *(float *)(v46 + 32) = v11->m_atom.m_info.m_data[0];
    *(float *)(v46 + 36) = v11->m_atom.m_info.m_data[1];
    *(float *)(v46 + 40) = v11->m_atom.m_info.m_data[2];
    *(float *)(v46 + 44) = v11->m_atom.m_info.m_data[3];
    v47 = v10[9].vfptr;
    v10[4].m_type = v11->m_atom.m_sizeOfAllAtoms;
    v47[1].__first_virtual_table_function__ = *(void (__fastcall **)(hkBaseObject *))&v10[4].m_memSizeAndFlags;
    LOWORD(v10[9].vfptr[2].__vecDelDtor) = *(_WORD *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 2i64);
    v48 = *(_QWORD *)&v10[4].m_memSizeAndFlags;
    v49 = *(unsigned __int16 *)(v48 + 4);
    v50 = v49 + 2;
    v51 = v49 + 3;
    v81 = v49 + 2;
    v83 = v49 + 3;
    v52 = 112 * (v49 >> 1) + 48 * ((*(_WORD *)(v48 + 4) & 1) + 3);
    v79 = 112 * (v49 >> 1) + 48 * ((*(_WORD *)(v48 + 4) & 1) + 3);
    v53 = v52 + 48;
    if ( v49 >= 2 )
    {
      v50 = v49 + 3;
      v52 += 48;
      v51 = v49 + 4;
      v83 = v49 + 4;
      v79 = v53;
      v81 = v49 + 3;
    }
    LODWORD(entityB) = *(signed __int16 *)(v48 + 20) << 16;
    if ( *(float *)&entityB != 0.0 )
    {
      v52 += 96;
      v50 += 2;
      v53 += 96;
      v51 += 3;
      v79 = v52;
      v81 = v50;
      v83 = v51;
    }
    v54 = *(_DWORD **)(*((_QWORD *)&v10[9].vfptr->__first_virtual_table_function__
                       + BYTE2(v10[9].vfptr[2].__first_virtual_table_function__))
                     + 296i64);
    if ( v10[9].vfptr )
    {
      v55 = v52;
      if ( v54[4] > v53 )
        v53 = v54[4];
      if ( v53 > v52 )
        v55 = v53;
      v54[5] += v52;
      v54[6] += v50;
      v54[7] += v51;
      v54[4] = v55;
      v56 = v10[9].vfptr;
      HIWORD(v56[2].__vecDelDtor) += v81;
      LOWORD(v56[2].__first_virtual_table_function__) += v83;
      WORD2(v56[2].__vecDelDtor) += v79;
      v57 = WORD2(v10[9].vfptr[2].__vecDelDtor);
      if ( v54[4] > v57 )
        v57 = v54[4];
      v54[4] = v57;
    }
    hkString::memCpy(
      (void *)(32i64 * *(unsigned __int16 *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 6i64)
             + *(_QWORD *)&v10[4].m_memSizeAndFlags
             + 48i64),
      v11->m_propertiesStream.m_data,
      v44 * *(unsigned __int8 *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 10i64));
    hkString::memCpy((void *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 48i64), v11->m_contactPoints.m_data, 32 * v44);
    v59 = v95;
    if ( v95->m_zeroUserDataInContactPointProperties )
    {
      v60 = *(_QWORD *)&v10[4].m_memSizeAndFlags;
      v58 = 0i64;
      v61 = 32i64 * *(unsigned __int16 *)(v60 + 6) + v60 + 48;
      if ( *(_WORD *)(v60 + 4) > 0u )
      {
        v62 = *(unsigned __int8 *)(v60 + 10);
        do
        {
          *(_QWORD *)(v61 + 8) = 0i64;
          v58 = (unsigned int)(v58 + 1);
          v61 += v62;
        }
        while ( (signed int)v58 < *(unsigned __int16 *)(*(_QWORD *)&v10[4].m_memSizeAndFlags + 4i64) );
      }
    }
    v63 = v10->vfptr;
    v84 = 0i64;
    v85 = 0;
    v86 = 2147483648;
    ((void (__fastcall *)(hkpContactMgr *, _WORD **, __int64))v63[6].__vecDelDtor)(v10, &v84, v58);
    v64 = v85;
    if ( v95->m_fireContactPointAddedCallbacks && v85 > 0 )
    {
      v65 = 0i64;
      do
      {
        v66 = v59->m_passCollidablePointersInCollisionCallbacks == 0;
        entityB = 0i64;
        v67 = v84[v65];
        v92 = 2139095022;
        v93 = 0i64;
        v91 = 0i64;
        v96 = 0i64;
        if ( !v66 )
        {
          entityB = (hkpEntity *)((char *)v13 + 32);
          v96 = (hkpCdBody *)&v7->m_collidable.m_shape;
        }
        v68 = (hkpContactPointProperties *)v10->vfptr[5].__vecDelDtor((hkBaseObject *)&v10->vfptr, v67);
        v69 = (hkContactPoint *)((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))v10->vfptr[5].__first_virtual_table_function__)(
                                  v10,
                                  v67);
        event.m_type.m_storage = 1;
        event.m_contactPoint = v69;
        event.m_bodyA = (hkpCdBody *)entityB;
        event.m_collisionInput = collisionInput;
        event.m_bodyB = v96;
        event.m_collisionOutput = (hkpProcessCollisionOutput *)&v90;
        event.m_contactPointProperties = v68;
        event.m_internalContactMgr = (hkpDynamicsContactMgr *)v10;
        LOWORD(v88) = v67;
        event.m_gskCache = 0i64;
        *(_QWORD *)&event.m_projectedVelocity = 0i64;
        if ( v10->m_type )
          WORD1(v88) = 0;
        else
          WORD1(v88) = v10[1].m_referenceCount;
        hkpWorldCallbackUtil::fireContactPointAdded(v13->m_world, &event);
        if ( v13->m_contactListeners.m_size )
          hkpEntityCallbackUtil::fireContactPointAddedInternal(v13, &event);
        if ( v7->m_contactListeners.m_size )
          hkpEntityCallbackUtil::fireContactPointAddedInternal(v7, &event);
        v64 = v85;
        v59 = v95;
        ++v26;
        ++v65;
      }
      while ( v26 < v85 );
    }
    if ( v59->m_fireContactPointCallbacks )
    {
      v70 = 0i64;
      v71 = v64;
      if ( v64 > 0 )
      {
        do
        {
          v72 = v84[v70];
          if ( !(*(_BYTE *)((__int64)v10->vfptr[5].__vecDelDtor((hkBaseObject *)&v10->vfptr, v72) + 19) & 1) )
          {
            v73 = (__int64)v10->vfptr[5].__vecDelDtor((hkBaseObject *)&v10->vfptr, v72);
            v74 = (hkpGskCache *)((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))v10->vfptr[5].__first_virtual_table_function__)(
                                   v10,
                                   v72);
            v75 = v13->m_world;
            event.m_contactPointProperties = (hkpContactPointProperties *)v73;
            _mm_store_si128((__m128i *)&event.m_internalContactMgr, (__m128i)0i64);
            event.m_gskCache = v74;
            LODWORD(event.m_bodyA) = 2;
            event.m_callbackFiredFrom = (hkpEntity *)v10;
            event.m_collisionOutput = (hkpProcessCollisionOutput *)(v73 + 32);
            event.m_bodyB = (hkpCdBody *)v13;
            *(_QWORD *)&event.m_type.m_storage = v7;
            LODWORD(event.m_contactPoint) = 4;
            LOWORD(event.m_projectedVelocity) = 0;
            BYTE2(event.m_projectedVelocity) = 0;
            v88 = 0i64;
            v89 = 0i64;
            hkpWorldCallbackUtil::fireContactPointCallback(v75, (hkpContactPointEvent *)&event);
            LODWORD(event.m_bodyA) = 0;
            if ( v13->m_contactListeners.m_size )
              hkpEntityCallbackUtil::fireContactPointCallbackInternal(v13, (hkpContactPointEvent *)&event);
            LODWORD(event.m_bodyA) = 1;
            if ( v7->m_contactListeners.m_size )
              hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, (hkpContactPointEvent *)&event);
          }
          ++v70;
        }
        while ( v70 < v71 );
      }
    }
    hkAgentNnMachine_InvalidateTimInAgent(entry, (hkpCollisionInput *)&collisionInput->m_dispatcher);
    v76 = v86;
    v94->m_enum = 0;
    v85 = 0;
    if ( v76 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v84,
        2 * (v76 & 0x3FFFFFFF));
    v77 = v94;
  }
  return v77;
}::s_alloc,
        v84,
        2 * (v76 & 0x3FFFFFFF));
    v77 = v94;
  }
  return v77;
}

// File Line: 532
// RVA: 0xE22060
hkResult *__fastcall hkpSaveContactPointsUtil::serializeEntry(hkResult *result, hkpAgentEntry *entry, hkBool isNnEntry, hkpProcessCollisionInput *input, int *sizeOfThisEntryOut, hkpSerializedAgentNnEntry::SerializedAgentType *agentTypeOut, hkpAgent1nTrack **agent1nTrackOut, hkpSerializedTrack1nInfo *trackInfoOut)
{
  hkpProcessCollisionInput *v8; // r15
  hkpAgentEntry *v9; // rsi
  hkResult *v10; // rbx
  signed __int64 v11; // rdi
  signed __int64 v12; // rax
  char *v13; // rdi
  hkpSerializedAgentNnEntry::SerializedAgentType v14; // eax
  hkpAgent1nTrack *v15; // rax

  v8 = input;
  *agent1nTrackOut = 0i64;
  v9 = entry;
  v10 = result;
  switch ( entry->m_streamCommand )
  {
    case 0:
    case 1:
      *sizeOfThisEntryOut = 16;
      result->m_enum = 0;
      return v10;
    case 2:
    case 3:
    case 0xA:
    case 0xB:
      v11 = 16i64;
      v12 = 48i64;
      goto LABEL_4;
    case 4:
    case 5:
    case 0xC:
    case 0xD:
      v11 = 32i64;
      v12 = 64i64;
LABEL_4:
      if ( isNnEntry.m_bool )
        v11 = v12;
      v13 = &entry->m_streamCommand + v11;
      v14 = hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_processFunc);
      *agentTypeOut = v14;
      if ( (signed int)v14 <= 0 )
        goto $LN1_63;
      if ( (signed int)v14 <= 4 )
      {
        *agentTypeOut = v14;
        *sizeOfThisEntryOut = (unsigned __int8)v9->m_size;
$LN6_211:
        v10->m_enum = 0;
        return v10;
      }
      if ( v14 == 5 )
      {
        *agentTypeOut = 5;
        *sizeOfThisEntryOut = (unsigned __int8)v9->m_size;
        if ( !(v13[11] & 0x20) )
        {
          v15 = hkConvexListAgent3::getAgent1nTrack(v9, v13);
          *agent1nTrackOut = v15;
          hkpSaveContactPointsUtil::serialize1nTrack(v10, &v15->m_sectors, v8, trackInfoOut);
          return v10;
        }
        goto $LN6_211;
      }
      if ( (unsigned int)(v14 - 6) > 3 )
      {
$LN1_63:
        v10->m_enum = 1;
      }
      else
      {
        *sizeOfThisEntryOut = (unsigned __int8)v9->m_size;
        *agentTypeOut = v14;
        *agent1nTrackOut = (hkpAgent1nTrack *)(v13 + 8);
        hkpSaveContactPointsUtil::serialize1nTrack(
          v10,
          (hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *)(v13 + 8),
          v8,
          trackInfoOut);
      }
      return v10;
    case 8:
      goto $LN6_211;
    default:
      goto $LN1_63;
  }
}

// File Line: 645
// RVA: 0xE221F0
hkResult *__fastcall hkpSaveContactPointsUtil::destroyOldEntry(hkResult *result, hkpSerializedAgentNnEntry::SerializedAgentType agentType, hkpProcessCollisionInput *input, hkpDynamicsContactMgr *mgr, hkpConstraintOwner *constraintOwner, hkpAgentNnEntry *nnEntry)
{
  hkpDynamicsContactMgr *v6; // r12
  hkpSerializedAgentNnEntry::SerializedAgentType v7; // ebp
  int v8; // eax
  hkResult *v9; // rbx
  char *v11; // rsi
  hkpCollisionDispatcher *v12; // r14
  __int64 v13; // r15

  v6 = mgr;
  v7 = agentType;
  v8 = (unsigned __int8)nnEntry->m_streamCommand;
  v9 = result;
  if ( v8 == 2 )
  {
    v11 = (char *)&nnEntry[1].m_contactMgr;
  }
  else
  {
    if ( v8 != 4 )
    {
      result->m_enum = 1;
      return result;
    }
    v11 = (char *)nnEntry[1].m_collidable;
  }
  v12 = input->m_dispatcher.m_storage;
  v13 = (unsigned __int8)nnEntry->m_agentType;
  if ( hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[v13].m_processFunc) == agentType
    && v7 )
  {
    v12->m_agent3Func[v13].m_destroyFunc(
      (hkpAgentEntry *)&nnEntry->m_streamCommand,
      v11,
      (hkpContactMgr *)&v6->vfptr,
      constraintOwner,
      v12);
    v9->m_enum = 0;
  }
  else
  {
    v9->m_enum = 1;
  }
  return v9;
}

// File Line: 692
// RVA: 0xE222B0
hkResult *__fastcall hkpSaveContactPointsUtil::deserializeEntry(hkResult *result, hkpSerializedAgentNnEntry *serializedEntryIn, hkpSerializedAgentNnEntry::SerializedAgentType agentType, hkpSerializedTrack1nInfo *serializedTrack, hkpProcessCollisionInput *input, hkpAgentNnEntry *nnEntry)
{
  hkpSerializedTrack1nInfo *v6; // r12
  hkpSerializedAgentNnEntry::SerializedAgentType v7; // esi
  int v8; // eax
  hkpSerializedAgentNnEntry *v9; // r14
  hkResult *v10; // rbx
  char *v12; // rbp
  hkpAgent1nTrack *v13; // r9
  bool v14; // zf

  v6 = serializedTrack;
  v7 = agentType;
  v8 = (unsigned __int8)nnEntry->m_streamCommand;
  v9 = serializedEntryIn;
  v10 = result;
  if ( v8 == 2 )
  {
    v12 = (char *)&nnEntry[1].m_contactMgr;
  }
  else
  {
    if ( v8 != 4 )
    {
      result->m_enum = 1;
      return result;
    }
    v12 = (char *)nnEntry[1].m_collidable;
  }
  if ( hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)nnEntry->m_agentType].m_processFunc) != agentType
    || (signed int)v7 <= 0 )
  {
LABEL_19:
    v10->m_enum = 1;
    return v10;
  }
  if ( (signed int)v7 <= 4 )
  {
    hkString::memCpy(&nnEntry[1], &v9->m_nnEntryData[40], 80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
    nnEntry->m_numContactPoints = v9->m_nnEntryData[2];
    nnEntry->m_size = v9->m_nnEntryData[3];
  }
  else
  {
    if ( v7 != 5 )
    {
      if ( (unsigned int)(v7 - 6) <= 3 )
      {
        hkString::memCpy(
          &nnEntry[1],
          &v9->m_nnEntryData[40],
          80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
        v13 = (hkpAgent1nTrack *)(v12 + 8);
        v14 = v12 + 8 == 0i64;
LABEL_12:
        if ( !v14 )
        {
          v13->m_sectors.m_data = 0i64;
          v13->m_sectors.m_size = 0;
          v13->m_sectors.m_capacityAndFlags = 2147483648;
        }
        hkpSaveContactPointsUtil::deserialize1nTrack(v10, v6, input, &v13->m_sectors);
        return v10;
      }
      goto LABEL_19;
    }
    hkString::memCpy(&nnEntry[1], &v9->m_nnEntryData[40], 80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
    nnEntry->m_numContactPoints = v9->m_nnEntryData[2];
    nnEntry->m_size = v9->m_nnEntryData[3];
    if ( !(v12[11] & 0x20) )
    {
      v13 = hkConvexListAgent3::getAgent1nTrack((hkpAgentEntry *)&nnEntry->m_streamCommand, v12);
      v14 = v13 == 0i64;
      goto LABEL_12;
    }
  }
  v10->m_enum = 0;
  return v10;
}

// File Line: 791
// RVA: 0xE22460
hkResult *__fastcall hkpSaveContactPointsUtil::serialize1nTrack(hkResult *result, hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *sectorsIn, hkpProcessCollisionInput *input, hkpSerializedTrack1nInfo *trackInfoOut)
{
  hkpSerializedTrack1nInfo *v4; // r14
  int v5; // er9
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v6; // rbx
  hkResult *v7; // rdi
  int v8; // eax
  int v9; // eax
  int v10; // er12
  __int64 v11; // r13
  hkpAgent1nSector *v12; // rsi
  hkpAgentEntry *v13; // rbp
  unsigned __int64 v14; // r15
  _QWORD **v15; // rax
  __int64 v16; // rax
  hkpSerializedSubTrack1nInfo *v17; // rbx
  _QWORD **v18; // rax
  _QWORD **v19; // rax
  hkpAgent1nSector *v20; // rax
  hkpAgent1nSector *v21; // rcx
  hkpAgent1nSector *v22; // rcx
  signed __int64 v23; // rax
  __int128 v24; // xmm0
  _QWORD **v26; // rax
  hkpSerializedAgentNnEntry::SerializedAgentType agentTypeOut; // [rsp+40h] [rbp-58h]
  hkResult resulta; // [rsp+44h] [rbp-54h]
  hkpAgent1nTrack *agent1nTrackOut; // [rsp+48h] [rbp-50h]
  hkResult *v30; // [rsp+A0h] [rbp+8h]
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v31; // [rsp+A8h] [rbp+10h]
  hkpProcessCollisionInput *inputa; // [rsp+B0h] [rbp+18h]
  int sizeOfThisEntryOut; // [rsp+B8h] [rbp+20h]

  inputa = input;
  v31 = sectorsIn;
  v30 = result;
  v4 = trackInfoOut;
  v5 = sectorsIn->m_size;
  v6 = sectorsIn;
  v7 = result;
  v8 = v4->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v5 )
  {
    v9 = 2 * v8;
    if ( v5 < v9 )
      v5 = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&sizeOfThisEntryOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v4,
      v5,
      8);
  }
  v10 = 0;
  if ( v6->m_size <= 0 )
  {
LABEL_31:
    v7->m_enum = 0;
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v6->m_data[v11];
      v13 = (hkpAgentEntry *)v12->m_data;
      v14 = (unsigned __int64)&v12->m_data[v12->m_bytesAllocated];
      if ( (unsigned __int64)v12->m_data < v14 )
        break;
LABEL_19:
      if ( v4->m_sectors.m_size == (v4->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
      ++v4->m_sectors.m_size;
      v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 512i64);
      v21 = v20;
      if ( v20 )
        v20->m_bytesAllocated = 0;
      else
        v21 = 0i64;
      v4->m_sectors.m_data[v11] = v21;
      v22 = v4->m_sectors.m_data[v11];
      if ( ((unsigned __int8)v22 | (unsigned __int8)v12) & 0xF )
      {
        memmove(v22, v12, 0x200ui64);
      }
      else
      {
        v23 = 4i64;
        do
        {
          v24 = *(_OWORD *)&v12->m_bytesAllocated;
          v22 = (hkpAgent1nSector *)((char *)v22 + 128);
          v12 = (hkpAgent1nSector *)((char *)v12 + 128);
          *(_OWORD *)&v22[-1].m_data[368] = v24;
          *(_OWORD *)&v22[-1].m_data[384] = *(_OWORD *)&v12[-1].m_data[384];
          *(_OWORD *)&v22[-1].m_data[400] = *(_OWORD *)&v12[-1].m_data[400];
          *(_OWORD *)&v22[-1].m_data[416] = *(_OWORD *)&v12[-1].m_data[416];
          *(_OWORD *)&v22[-1].m_data[432] = *(_OWORD *)&v12[-1].m_data[432];
          *(_OWORD *)&v22[-1].m_data[448] = *(_OWORD *)&v12[-1].m_data[448];
          *(_OWORD *)&v22[-1].m_data[464] = *(_OWORD *)&v12[-1].m_data[464];
          *(_OWORD *)&v22[-1].m_data[480] = *(_OWORD *)&v12[-1].m_data[480];
          --v23;
        }
        while ( v23 );
      }
      ++v10;
      ++v11;
      if ( v10 >= v6->m_size )
      {
        v7 = v30;
        goto LABEL_31;
      }
    }
    while ( 1 )
    {
      agent1nTrackOut = 0i64;
      sizeOfThisEntryOut = 0;
      v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v16 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 40i64);
      v17 = (hkpSerializedSubTrack1nInfo *)v16;
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_DWORD *)(v16 + 12) = 2147483648;
        *(_QWORD *)(v16 + 16) = 0i64;
        *(_DWORD *)(v16 + 24) = 0;
        *(_QWORD *)(v16 + 28) = -2147483648i64;
      }
      else
      {
        v17 = 0i64;
      }
      if ( hkpSaveContactPointsUtil::serializeEntry(
             &resulta,
             v13,
             0,
             inputa,
             &sizeOfThisEntryOut,
             &agentTypeOut,
             &agent1nTrackOut,
             (hkpSerializedTrack1nInfo *)&v17->m_sectors)->m_enum )
        break;
      if ( v17->m_sectors.m_size )
      {
        v17->m_sectorIndex = v10;
        v17->m_offsetInSector = (_DWORD)agent1nTrackOut - (_DWORD)v12 - 16;
        if ( v4->m_subTracks.m_size == (v4->m_subTracks.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_subTracks, 8);
        v4->m_subTracks.m_data[v4->m_subTracks.m_size++] = v17;
      }
      else
      {
        hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo((hkpSerializedTrack1nInfo *)&v17->m_sectors);
        v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, signed __int64))(*v18[11] + 16i64))(
          v18[11],
          v17,
          40i64);
      }
      v13 = (hkpAgentEntry *)((char *)v13 + sizeOfThisEntryOut);
      if ( (unsigned __int64)v13 >= v14 )
      {
        v6 = v31;
        goto LABEL_19;
      }
    }
    if ( v17 )
    {
      hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo((hkpSerializedTrack1nInfo *)&v17->m_sectors);
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, signed __int64))(*v26[11] + 16i64))(
        v26[11],
        v17,
        40i64);
    }
    v7 = v30;
    v30->m_enum = 1;
  }
  return v7;
}

// File Line: 844
// RVA: 0xE22790
hkResult *__fastcall hkpSaveContactPointsUtil::deserialize1nTrack(hkResult *result, hkpSerializedTrack1nInfo *serializedTrack, hkpProcessCollisionInput *input, hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *sectorsOut)
{
  int v4; // ebx
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v5; // rbp
  int v6; // eax
  hkpSerializedTrack1nInfo *v7; // rsi
  int v8; // eax
  int v9; // er9
  int v10; // edi
  __int64 v11; // rbx
  _QWORD **v12; // rax
  hkpAgent1nSector *v13; // rax
  hkpAgent1nSector *v14; // rcx
  hkpAgent1nSector *v15; // rcx
  hkpAgent1nSector *v16; // rdx
  signed __int64 v17; // rax
  __int128 v18; // xmm0
  int v19; // ebx
  __int64 v20; // rdi
  hkpSerializedSubTrack1nInfo *v21; // rdx
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v22; // r9
  hkResult *v23; // rax
  hkResult *v24; // [rsp+50h] [rbp+8h]
  hkResult resulta; // [rsp+58h] [rbp+10h]
  hkpProcessCollisionInput *inputa; // [rsp+60h] [rbp+18h]

  inputa = input;
  v24 = result;
  v4 = serializedTrack->m_sectors.m_size;
  v5 = sectorsOut;
  v6 = sectorsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = serializedTrack;
  if ( v6 < v4 )
  {
    v8 = 2 * v6;
    v9 = serializedTrack->m_sectors.m_size;
    if ( v4 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v9, 8);
  }
  v5->m_size = v4;
  v10 = 0;
  if ( v7->m_sectors.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 512i64);
      v14 = v13;
      if ( v13 )
        v13->m_bytesAllocated = 0;
      else
        v14 = 0i64;
      v5->m_data[v11] = v14;
      v15 = v5->m_data[v11];
      v16 = v7->m_sectors.m_data[v11];
      if ( ((unsigned __int8)v15 | (unsigned __int8)v7->m_sectors.m_data[v11]) & 0xF )
      {
        memmove(v15, v16, 0x200ui64);
      }
      else
      {
        v17 = 4i64;
        do
        {
          v18 = *(_OWORD *)&v16->m_bytesAllocated;
          v15 = (hkpAgent1nSector *)((char *)v15 + 128);
          v16 = (hkpAgent1nSector *)((char *)v16 + 128);
          *(_OWORD *)&v15[-1].m_data[368] = v18;
          *(_OWORD *)&v15[-1].m_data[384] = *(_OWORD *)&v16[-1].m_data[384];
          *(_OWORD *)&v15[-1].m_data[400] = *(_OWORD *)&v16[-1].m_data[400];
          *(_OWORD *)&v15[-1].m_data[416] = *(_OWORD *)&v16[-1].m_data[416];
          *(_OWORD *)&v15[-1].m_data[432] = *(_OWORD *)&v16[-1].m_data[432];
          *(_OWORD *)&v15[-1].m_data[448] = *(_OWORD *)&v16[-1].m_data[448];
          *(_OWORD *)&v15[-1].m_data[464] = *(_OWORD *)&v16[-1].m_data[464];
          *(_OWORD *)&v15[-1].m_data[480] = *(_OWORD *)&v16[-1].m_data[480];
          --v17;
        }
        while ( v17 );
      }
      ++v10;
      ++v11;
    }
    while ( v10 < v7->m_sectors.m_size );
  }
  v19 = 0;
  if ( v7->m_subTracks.m_size <= 0 )
  {
LABEL_22:
    v23 = v24;
    v24->m_enum = 0;
  }
  else
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = v7->m_subTracks.m_data[v20];
      v22 = (hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *)&v5->m_data[v21->m_sectorIndex]->m_data[v21->m_offsetInSector];
      if ( v22 )
      {
        v22->m_data = 0i64;
        v22->m_size = 0;
        v22->m_capacityAndFlags = 2147483648;
      }
      if ( hkpSaveContactPointsUtil::deserialize1nTrack(
             &resulta,
             (hkpSerializedTrack1nInfo *)&v21->m_sectors,
             inputa,
             v22)->m_enum == 1 )
        break;
      ++v19;
      ++v20;
      if ( v19 >= v7->m_subTracks.m_size )
        goto LABEL_22;
    }
    v23 = v24;
    v24->m_enum = 1;
  }
  return v23;
}

// File Line: 880
// RVA: 0xE22970
signed __int64 __fastcall hkpSaveContactPointsUtil::getSerializedAgentType(void *(__fastcall *func)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))
{
  signed __int64 result; // rax

  if ( (char *)func == (char *)hkBoxBoxAgent3::process )
    return 1i64;
  if ( (char *)func == (char *)hkCapsuleTriangleAgent3::process )
    return 2i64;
  if ( (char *)func == (char *)hkPredGskAgent3::process )
    return 3i64;
  if ( (char *)func == (char *)hkPredGskCylinderAgent3::process )
    return 4i64;
  if ( (char *)func == (char *)hkConvexListAgent3::process )
    return 5i64;
  if ( (char *)func == (char *)hkListAgent3::process )
    return 6i64;
  if ( (char *)func == (char *)hkBvTreeAgent3::process )
    return 7i64;
  if ( (char *)func == (char *)hkpCollectionCollectionAgent3::process )
    return 8i64;
  result = 0i64;
  if ( (char *)func == (char *)hkpCollectionAgent3::process )
    result = 9i64;
  return result;
}

