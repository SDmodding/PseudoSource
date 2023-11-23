// File Line: 43
// RVA: 0xE20DD0
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(
        hkpSaveContactPointsUtil::SavePointsInput *input,
        hkpWorld *world,
        hkpPhysicsSystemWithContacts *sys)
{
  int m_size; // eax
  hkProcess **v4; // r9
  __int64 v7; // r8
  hkpSimulationIsland **m_data; // r10
  __int64 v9; // rcx
  hkProcess *v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rcx
  __int64 v13; // rax
  unsigned __int16 *v14; // r14
  int v15; // ebp
  int v16; // ecx
  __int64 v17; // r12
  hkpAgentNnEntry *v18; // rdi
  hkpAgentNnEntry *v19; // rsi
  _QWORD **Value; // rax
  hkpSerializedAgentNnEntry *v21; // rax
  hkpSerializedAgentNnEntry *v22; // rax
  hkpSerializedAgentNnEntry *v23; // rbx
  __int64 v24; // [rsp+30h] [rbp-78h]
  __int64 v25; // [rsp+38h] [rbp-70h]
  unsigned __int16 *v26; // [rsp+40h] [rbp-68h]
  hkArrayBase<hkProcess *> v27; // [rsp+48h] [rbp-60h] BYREF
  __int64 v28[3]; // [rsp+58h] [rbp-50h]
  int v30; // [rsp+B8h] [rbp+10h] BYREF
  hkResult result; // [rsp+C8h] [rbp+20h] BYREF

  m_size = world->m_activeSimulationIslands.m_size;
  v4 = 0i64;
  v27.m_data = 0i64;
  v27.m_size = 0;
  v27.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
  {
    v30 = 8 * m_size;
    v4 = (hkProcess **)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, hkpPhysicsSystemWithContacts *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                         &hkContainerHeapAllocator::s_alloc,
                         &v30,
                         sys,
                         0i64);
    v27.m_data = v4;
    v27.m_capacityAndFlags = v30 / 8;
  }
  v7 = world->m_activeSimulationIslands.m_size;
  m_data = world->m_activeSimulationIslands.m_data;
  v9 = 0i64;
  v27.m_size = v7;
  if ( (int)v7 > 0 )
  {
    do
    {
      v10 = (hkProcess *)m_data[v9++];
      v4[v9 - 1] = v10;
    }
    while ( v9 < v7 );
    LODWORD(v7) = v27.m_size;
  }
  hkArrayBase<hkpEntity *>::_insertAt(
    &v27,
    &hkContainerHeapAllocator::s_alloc,
    v7,
    (hkProcess *const *)world->m_inactiveSimulationIslands.m_data,
    world->m_inactiveSimulationIslands.m_size);
  v30 = 0;
  if ( v27.m_size > 0 )
  {
    v11 = 0i64;
    v25 = 0i64;
    do
    {
      v12 = *(__int64 *)((char *)v27.m_data + v11);
      v28[0] = v12 + 152;
      v28[1] = v12 + 120;
      v13 = 0i64;
      v24 = 0i64;
      do
      {
        v14 = (unsigned __int16 *)v28[v13];
        v15 = 0;
        v16 = *((_DWORD *)v14 + 4);
        v26 = v14;
        if ( v16 > 0 )
        {
          v17 = 0i64;
          do
          {
            ++v15;
            v17 += 8i64;
            v18 = *(hkpAgentNnEntry **)(v17 + *((_QWORD *)v14 + 1) - 8);
            if ( v15 == v16 )
              v19 = (hkpAgentNnEntry *)((char *)v18 + *v14);
            else
              v19 = v18 + 24;
            if ( v18 < v19 )
            {
              do
              {
                Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v21 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                     Value[11],
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
                if ( hkpSaveContactPointsUtil::serializeCollisionEntry(
                       &result,
                       input,
                       v18,
                       world->m_collisionInput,
                       v23)->m_enum == HK_SUCCESS )
                  hkpPhysicsSystemWithContacts::addContact(sys, v23);
                hkReferencedObject::removeReference(v23);
                v18 = (hkpAgentNnEntry *)((char *)v18 + (unsigned __int8)v18->m_size);
              }
              while ( v18 < v19 );
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
      ++v30;
      v25 += 8i64;
    }
    while ( v30 < v27.m_size );
  }
  v27.m_size = 0;
  if ( v27.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v27.m_data,
      8 * v27.m_capacityAndFlags);
}

// File Line: 74
// RVA: 0xE210A0
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(
        hkpSaveContactPointsUtil::SavePointsInput *input,
        hkpEntity **entities,
        int numEntities,
        hkpPhysicsSystemWithContacts *sys)
{
  __int64 v4; // rsi
  hkpWorld *m_world; // r13
  __int64 v7; // rbx
  hkpEntity **v8; // rdi
  __int64 v10; // rbp
  hkpLinkedCollidable *p_m_collidable; // rcx
  int v12; // edi
  hkpLinkedCollidable::CollisionEntry *m_data; // r14
  int Key; // eax
  _QWORD **Value; // rax
  hkpSerializedAgentNnEntry *v16; // rax
  hkpSerializedAgentNnEntry *v17; // rax
  hkpSerializedAgentNnEntry *serializedEntryOut; // rbx
  __int64 i; // [rsp+30h] [rbp-68h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+38h] [rbp-60h] BYREF
  AMD_HD3D v21[2]; // [rsp+48h] [rbp-50h] BYREF
  hkResult result; // [rsp+B0h] [rbp+18h] BYREF

  v4 = 0i64;
  m_world = (*entities)->m_world;
  v7 = numEntities;
  v8 = entities;
  *(_QWORD *)&v21[0].mEnableStereo = 0i64;
  v21[0].mWidth = 0;
  v21[0].mHeight = -1;
  if ( numEntities )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v21,
      &hkContainerHeapAllocator::s_alloc,
      numEntities);
  v10 = 0i64;
  for ( i = v7; v10 < v7; entries.m_capacityAndFlags = 0x80000000 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v21,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)&v8[v10]->m_collidable,
      0i64);
    p_m_collidable = &v8[v10]->m_collidable;
    entries.m_data = 0i64;
    entries.m_size = 0;
    entries.m_capacityAndFlags = 0x80000000;
    hkpLinkedCollidable::getCollisionEntriesSorted(p_m_collidable, &entries);
    v12 = 0;
    if ( entries.m_size > 0 )
    {
      do
      {
        m_data = entries.m_data;
        Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v21,
                              (unsigned __int64)entries.m_data[v4].m_partner);
        if ( Key > (int)v21[0].mHeight )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v16 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
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
                 input,
                 m_data[v4].m_agentEntry,
                 m_world->m_collisionInput,
                 serializedEntryOut)->m_enum == HK_SUCCESS )
            hkpPhysicsSystemWithContacts::addContact(sys, serializedEntryOut);
          hkReferencedObject::removeReference(serializedEntryOut);
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
        &hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * entries.m_capacityAndFlags);
    v8 = entities;
    ++v10;
    entries.m_data = 0i64;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v21,
    &hkContainerHeapAllocator::s_alloc);
  _(v21);
}

// File Line: 109
// RVA: 0xE21280
void __fastcall hkpSaveContactPointsUtil::saveContactPoints(
        hkpSaveContactPointsUtil::SavePointsInput *input,
        hkpAgentNnEntry **entries,
        int numEntries,
        hkpPhysicsSystemWithContacts *sys)
{
  hkpLinkedCollidable *v6; // r10
  char *v8; // rax
  __int64 v9; // r15
  __int64 v10; // rdi
  __int64 i; // rsi
  _QWORD **Value; // rax
  hkpSerializedAgentNnEntry *v13; // rax
  hkpSerializedAgentNnEntry *v14; // rax
  hkpSerializedAgentNnEntry *serializedEntryOut; // rbx
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  v6 = (*entries)->m_collidable[0];
  if ( v6->m_broadPhaseHandle.m_type == 1 )
    v8 = (char *)v6 + v6->m_ownerOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 2);
  v10 = 0i64;
  for ( i = numEntries; v10 < i; ++v10 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpSerializedAgentNnEntry *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                         Value[11],
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
           input,
           entries[v10],
           *(hkpProcessCollisionInput **)(v9 + 184),
           serializedEntryOut)->m_enum == HK_SUCCESS )
      hkpPhysicsSystemWithContacts::addContact(sys, serializedEntryOut);
    hkReferencedObject::removeReference(serializedEntryOut);
  }
}

// File Line: 152
// RVA: 0xE22B90
unsigned __int64 __fastcall `anonymous namespace::hkEntitySelectorListed::isEntityOk(
        hkEntitySelectorListed *this,
        hkpEntity *entity)
{
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           &this->m_map,
           (unsigned __int64)entity,
           0i64);
}

// File Line: 164
// RVA: 0xE22BA0
void __fastcall hkpSaveContactPointsUtil::loadContactPointsInternal(
        hkpSaveContactPointsUtil::LoadPointsInput *input,
        hkpPhysicsSystemWithContacts *sys,
        hkpWorld *world,
        hkpSaveContactPointsUtil::EntitySelector *selector)
{
  hkpSaveContactPointsUtil::EntitySelector *v4; // r13
  int v6; // r15d
  hkpSaveContactPointsUtil::LoadPointsInput *v8; // r14
  __int64 i; // r12
  hkpSerializedAgentNnEntry *v10; // rbx
  hkpRigidBody *m_bodyA; // rbp
  __int64 m_bodyB; // r14
  hkpAgentNnEntry *entry; // r13
  __int64 v14; // rax
  bool v15; // zf
  hkpLinkedCollidable *entityB; // [rsp+20h] [rbp-58h]
  hkResult result; // [rsp+88h] [rbp+10h] BYREF
  hkpSaveContactPointsUtil::EntitySelector *v19; // [rsp+98h] [rbp+20h]

  v19 = selector;
  ++world->m_criticalOperationsLockCount;
  v4 = selector;
  v6 = sys->m_contacts.m_size - 1;
  v8 = input;
  for ( i = v6; i >= 0; --i )
  {
    v10 = sys->m_contacts.m_data[i];
    if ( v10->m_useEntityIds.m_bool )
    {
      m_bodyA = (hkpRigidBody *)v8->m_getEntityFromId(v10->m_bodyAId);
      m_bodyB = (__int64)v8->m_getEntityFromId(v10->m_bodyBId);
    }
    else
    {
      m_bodyA = (hkpRigidBody *)v10->m_bodyA;
      m_bodyB = (__int64)v10->m_bodyB;
    }
    if ( m_bodyA && m_bodyB && (v4->vfptr->isEntityOk(v4, m_bodyA) || v4->vfptr->isEntityOk(v4, (hkpEntity *)m_bodyB)) )
    {
      entry = hkAgentNnMachine_FindAgent(&m_bodyA->m_collidable, (hkpLinkedCollidable *)(m_bodyB + 32));
      if ( entry )
      {
        if ( *(_DWORD *)v10->m_endianCheckBuffer != 259 )
          hkpSaveContactPointsEndianUtil::swapEndianTypeInCollisionEntry(world->m_collisionInput, v10);
        entityB = (hkpLinkedCollidable *)m_bodyB;
        v8 = input;
        hkpSaveContactPointsUtil::deserializeCollisionEntry(
          &result,
          input,
          v10,
          m_bodyA,
          entityB,
          world->m_collisionInput,
          entry);
        if ( input->m_removeSerializedAgentsWhenLoaded && result.m_enum == HK_FAILURE )
        {
          hkReferencedObject::removeReference(sys->m_contacts.m_data[i]);
          v14 = --sys->m_contacts.m_size;
          v4 = v19;
          if ( (_DWORD)v14 != v6 )
            sys->m_contacts.m_data[i] = sys->m_contacts.m_data[v14];
        }
        else
        {
          v4 = v19;
        }
        goto LABEL_18;
      }
      v4 = v19;
    }
    v8 = input;
LABEL_18:
    --v6;
  }
  v15 = world->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 222
// RVA: 0xE21360
void __fastcall hkpSaveContactPointsUtil::loadContactPoints(
        hkpSaveContactPointsUtil::LoadPointsInput *input,
        hkpPhysicsSystemWithContacts *sys,
        hkpWorld *world)
{
  hkpSaveContactPointsUtil::EntitySelector selector; // [rsp+48h] [rbp+20h] BYREF

  selector.vfptr = (hkpSaveContactPointsUtil::EntitySelectorVtbl *)&`anonymous namespace::hkEntitySelectorAll::`vftable;
  hkpSaveContactPointsUtil::loadContactPointsInternal(input, sys, world, &selector);
}

// File Line: 228
// RVA: 0xE21390
void __fastcall hkpSaveContactPointsUtil::loadContactPoints(
        hkpSaveContactPointsUtil::LoadPointsInput *input,
        hkpPhysicsSystemWithContacts *sys,
        hkpEntity **entities,
        int numEntities)
{
  __int64 v5; // rbx
  hkpWorld *m_world; // r15
  __int64 v7; // rdi
  hkpSaveContactPointsUtil::EntitySelector selector; // [rsp+20h] [rbp-38h] BYREF
  AMD_HD3D v11; // [rsp+28h] [rbp-30h] BYREF

  v5 = 0i64;
  m_world = (*entities)->m_world;
  selector.vfptr = (hkpSaveContactPointsUtil::EntitySelectorVtbl *)&`anonymous namespace::hkEntitySelectorListed::`vftable;
  v7 = numEntities;
  *(_QWORD *)&v11.mEnableStereo = 0i64;
  v11.mWidth = 0;
  v11.mHeight = -1;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11,
    &hkContainerHeapAllocator::s_alloc,
    v7);
  if ( v7 > 0 )
  {
    do
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)entities[v5++],
        1ui64);
    while ( v5 < v7 );
  }
  hkpSaveContactPointsUtil::loadContactPointsInternal(input, sys, m_world, &selector);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11,
    &hkContainerHeapAllocator::s_alloc);
  _(&v11);
}

// File Line: 239
// RVA: 0xE21470
hkResult *__fastcall hkpSaveContactPointsUtil::serializeCollisionEntry(
        hkResult *result,
        hkpSaveContactPointsUtil::SavePointsInput *input,
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *collisionInput,
        hkpSerializedAgentNnEntry *serializedEntryOut)
{
  hkpSerializedAgentNnEntry *v9; // rbx
  int v10; // r8d
  hkpContactMgr *m_contactMgr; // r14
  int vfptr; // r15d
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  __int64 v16; // rdx
  int v17; // r8d
  char v18; // al
  __int64 v19; // rsi
  int v20; // r15d
  int v21; // eax
  int v22; // eax
  int v23; // r9d
  int v24; // r15d
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  __int64 v28; // rcx
  hkpLinkedCollidable *v29; // rax
  hkpEntity *v30; // rcx
  hkpLinkedCollidable *v31; // rax
  hkpEntity *v32; // rsi
  bool m_useEntityIds; // al
  int n; // [rsp+40h] [rbp-38h] BYREF
  hkResult resulta; // [rsp+44h] [rbp-34h] BYREF
  hkpAgent1nTrack *agent1nTrackOut; // [rsp+48h] [rbp-30h] BYREF
  hkpSerializedAgentNnEntry::SerializedAgentType agentTypeOut; // [rsp+90h] [rbp+18h] BYREF

  if ( ((unsigned int (__fastcall *)(hkpContactMgr *))entry->m_contactMgr->vfptr[6].__first_virtual_table_function__)(entry->m_contactMgr)
    || !*(_WORD *)(*(_QWORD *)&entry->m_contactMgr[4].m_memSizeAndFlags + 4i64) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    v9 = serializedEntryOut;
    n = -1;
    agentTypeOut = INVALID_AGENT_TYPE;
    if ( hkpSaveContactPointsUtil::serializeEntry(
           &resulta,
           entry,
           (hkBool)1,
           collisionInput,
           &n,
           &agentTypeOut,
           &agent1nTrackOut,
           &serializedEntryOut->m_trackInfo)->m_enum )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      v10 = n;
      v9->m_agentType.m_storage = agentTypeOut;
      if ( v10 )
        hkString::memCpy(v9->m_nnEntryData, entry, v10);
      m_contactMgr = entry->m_contactMgr;
      vfptr = (int)m_contactMgr[3].vfptr;
      v13 = v9->m_cpIdMgr.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v13 < vfptr )
      {
        v14 = 2 * v13;
        v15 = (int)m_contactMgr[3].vfptr;
        if ( vfptr < v14 )
          v15 = v14;
        hkArrayUtil::_reserve(
          (hkResult *)&agentTypeOut,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v9->m_cpIdMgr.m_data,
          v15,
          1);
      }
      v16 = 0i64;
      v17 = 0;
      for ( v9->m_cpIdMgr.m_size = vfptr; v17 < v9->m_cpIdMgr.m_size; v9->m_cpIdMgr.m_data[v16++] = v18 )
      {
        ++v17;
        v18 = *(_BYTE *)(v16 + *(_QWORD *)&m_contactMgr[2].m_type);
      }
      v19 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
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
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v9->m_propertiesStream.m_data,
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
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v9->m_contactPoints.m_data,
          v27,
          32);
      }
      v9->m_contactPoints.m_size = v24;
      hkString::memCpy(v9->m_contactPoints.m_data, (const void *)(v19 + 48), 32 * *(unsigned __int16 *)(v19 + 4));
      v28 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
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
      v29 = entry->m_collidable[0];
      if ( v29->m_broadPhaseHandle.m_type == 1 )
        v30 = (hkpEntity *)((char *)v29 + v29->m_ownerOffset);
      else
        v30 = 0i64;
      v31 = entry->m_collidable[1];
      if ( v31->m_broadPhaseHandle.m_type == 1 )
        v32 = (hkpEntity *)((char *)v31 + v31->m_ownerOffset);
      else
        v32 = 0i64;
      m_useEntityIds = input->m_useEntityIds;
      v9->m_useEntityIds.m_bool = input->m_useEntityIds;
      if ( m_useEntityIds )
      {
        v9->m_bodyAId = input->m_getIdForEntity(v30);
        v9->m_bodyBId = input->m_getIdForEntity(v32);
      }
      else
      {
        v9->m_bodyA = v30;
        v9->m_bodyB = v32;
        hkReferencedObject::addReference(v30);
        hkReferencedObject::addReference(v9->m_bodyB);
      }
      result->m_enum = HK_SUCCESS;
    }
    return result;
  }
}

// File Line: 321
// RVA: 0xE217F0
hkResult *__fastcall hkpSaveContactPointsUtil::deserializeCollisionEntry(
        hkResult *result,
        hkpSaveContactPointsUtil::LoadPointsInput *input,
        hkpSerializedAgentNnEntry *serializedEntryIn,
        hkpRigidBody *entityA,
        hkpLinkedCollidable *entityB,
        hkpProcessCollisionInput *collisionInput,
        hkpAgentNnEntry *entry)
{
  hkpRigidBody *v7; // r15
  hkpAgentNnEntry *nnEntry; // rbx
  hkpSimulationIsland *constraintOwner; // rax
  hkpContactMgr *m_contactMgr; // rsi
  hkpSimulationIsland *v12; // r8
  hkpProcessCollisionInput *v15; // rdi
  hkpLinkedCollidable *v16; // rcx
  hkpEntity *v17; // rax
  unsigned __int16 v18; // cx
  hkBaseObjectVtbl *v19; // rcx
  hkBaseObjectVtbl *vfptr; // rdx
  void (__fastcall *first_virtual_table_function)(hkBaseObject *); // rcx
  int m_size; // r12d
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  int v26; // r12d
  __int64 v27; // rdx
  int i; // r8d
  char v29; // al
  hkpLinkedCollidable *v30; // rax
  char *v31; // rbx
  hkpWorld *v32; // rbx
  __int64 v33; // r10
  int v34; // ecx
  int v35; // r8d
  int v36; // r9d
  int v37; // edx
  hkBaseObjectVtbl *v38; // rcx
  _DWORD *v39; // rax
  hkBaseObjectVtbl *v40; // rcx
  __int64 v41; // rdi
  unsigned int v42; // ebx
  _QWORD **Value; // rax
  int m_numContactPoints; // ebx
  hkpSimpleContactConstraintAtom *Atom; // rax
  __int64 v46; // rcx
  hkBaseObjectVtbl *v47; // rcx
  __int64 v48; // r8
  int v49; // ecx
  int v50; // r9d
  int v51; // r10d
  int v52; // edx
  int v53; // r11d
  _DWORD *v54; // r8
  int v55; // eax
  hkBaseObjectVtbl *v56; // rcx
  int v57; // ecx
  __int64 v58; // r8
  hkpSaveContactPointsUtil::LoadPointsInput *v59; // rbx
  __int64 v60; // rcx
  __int64 v61; // rdx
  unsigned int v62; // eax
  hkBaseObjectVtbl *v63; // rax
  int v64; // eax
  __int64 v65; // r13
  bool v66; // zf
  unsigned __int16 v67; // di
  hkpContactPointProperties *v68; // rbx
  __int64 v69; // rax
  __int64 v70; // rdi
  __int64 j; // r13
  unsigned __int16 v72; // r12
  __int64 v73; // rbx
  hkContactPoint *v74; // rax
  hkpWorld *m_world; // rcx
  int v76; // r8d
  __int16 v78; // [rsp+34h] [rbp-CCh]
  __int16 v79; // [rsp+34h] [rbp-CCh]
  __int16 v80; // [rsp+38h] [rbp-C8h]
  __int16 v81; // [rsp+38h] [rbp-C8h]
  __int16 v82; // [rsp+3Ch] [rbp-C4h]
  __int16 v83; // [rsp+3Ch] [rbp-C4h]
  _WORD *v84; // [rsp+40h] [rbp-C0h] BYREF
  int v85; // [rsp+48h] [rbp-B8h]
  int v86; // [rsp+4Ch] [rbp-B4h]
  hkpContactPointEvent event; // [rsp+50h] [rbp-B0h] BYREF
  char v88; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v89; // [rsp+C8h] [rbp-38h]
  int v90; // [rsp+30F0h] [rbp+2FF0h]
  __int64 v91; // [rsp+3110h] [rbp+3010h]
  hkpRigidBody *p_m_collidable; // [rsp+31C0h] [rbp+30C0h]

  v7 = (hkpRigidBody *)entityB;
  nnEntry = entry;
  constraintOwner = entityA->m_simulationIsland;
  m_contactMgr = entry->m_contactMgr;
  v12 = *(hkpSimulationIsland **)&entityB[2].m_broadPhaseHandle.m_type;
  if ( constraintOwner != v12 )
  {
    if ( entityA->m_motion.m_type.m_storage == 5 )
    {
      constraintOwner = *(hkpSimulationIsland **)&entityB[2].m_broadPhaseHandle.m_type;
    }
    else if ( LOBYTE(entityB[2].m_boundingVolumeData.m_childShapeKeys) != 5 )
    {
      constraintOwner = hkpWorldAgentUtil::getIslandFromAgentEntry(
                          (hkpAgentNnSector *)entry,
                          entityA->m_simulationIsland,
                          v12);
    }
  }
  v15 = collisionInput;
  if ( hkpSaveContactPointsUtil::destroyOldEntry(
         (hkResult *)&entityB,
         (hkpSerializedAgentNnEntry::SerializedAgentType)serializedEntryIn->m_agentType.m_storage,
         collisionInput,
         (hkpDynamicsContactMgr *)m_contactMgr,
         constraintOwner,
         nnEntry)->m_enum )
    goto LABEL_70;
  v16 = nnEntry->m_collidable[0];
  v17 = 0i64;
  if ( v16->m_broadPhaseHandle.m_type == 1 )
    v17 = (hkpEntity *)((char *)v16 + v16->m_ownerOffset);
  if ( entityA != v17 )
  {
    nnEntry->m_collidable[0] = nnEntry->m_collidable[1];
    nnEntry->m_collidable[1] = v16;
    v18 = nnEntry->m_agentIndexOnCollidable[0];
    nnEntry->m_agentIndexOnCollidable[0] = nnEntry->m_agentIndexOnCollidable[1];
    nnEntry->m_agentIndexOnCollidable[1] = v18;
    v19 = *(hkBaseObjectVtbl **)&m_contactMgr[6].m_type;
    *(_QWORD *)&m_contactMgr[6].m_type = m_contactMgr[7].vfptr;
    m_contactMgr[7].vfptr = v19;
    vfptr = m_contactMgr[9].vfptr;
    if ( vfptr )
    {
      first_virtual_table_function = vfptr->__first_virtual_table_function__;
      vfptr->__first_virtual_table_function__ = (void (__fastcall *)(hkBaseObject *))vfptr[1].__vecDelDtor;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(hkBaseObject *, unsigned int))first_virtual_table_function;
      BYTE2(m_contactMgr[9].vfptr[2].__first_virtual_table_function__) = BYTE2(m_contactMgr[9].vfptr[2].__first_virtual_table_function__) == 0;
    }
  }
  if ( hkpSaveContactPointsUtil::deserializeEntry(
         (hkResult *)&entityB,
         serializedEntryIn,
         (hkpSerializedAgentNnEntry::SerializedAgentType)serializedEntryIn->m_agentType.m_storage,
         &serializedEntryIn->m_trackInfo,
         v15,
         nnEntry)->m_enum )
  {
LABEL_70:
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    m_size = serializedEntryIn->m_cpIdMgr.m_size;
    v23 = HIDWORD(m_contactMgr[3].vfptr) & 0x3FFFFFFF;
    if ( v23 < m_size )
    {
      v24 = 2 * v23;
      v25 = serializedEntryIn->m_cpIdMgr.m_size;
      if ( m_size < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(
        (hkResult *)&entityB,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_contactMgr[2].m_type,
        v25,
        1);
    }
    LODWORD(m_contactMgr[3].vfptr) = m_size;
    v26 = 0;
    v27 = 0i64;
    for ( i = 0; i < SLODWORD(m_contactMgr[3].vfptr); *(_BYTE *)(v27 + *(_QWORD *)&m_contactMgr[2].m_type - 1) = v29 )
    {
      ++i;
      v29 = serializedEntryIn->m_cpIdMgr.m_data[v27++];
    }
    if ( !*(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) )
    {
      v30 = nnEntry->m_collidable[0];
      if ( v30->m_broadPhaseHandle.m_type == 1 )
        v31 = (char *)v30 + v30->m_ownerOffset;
      else
        v31 = 0i64;
      v32 = (hkpWorld *)*((_QWORD *)v31 + 2);
      --v32->m_criticalOperationsLockCount;
      v32->m_blockExecutingPendingOperations.m_bool = 1;
      hkpWorldOperationUtil::addConstraintImmediately(v32, (hkpConstraintInstance *)&m_contactMgr[5], DO_FIRE_CALLBACKS);
      ++v32->m_criticalOperationsLockCount;
      v32->m_blockExecutingPendingOperations.m_bool = 0;
    }
    v33 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
    v34 = *(unsigned __int16 *)(v33 + 4);
    v35 = v34 + 2;
    v36 = v34 + 3;
    v80 = v34 + 2;
    v82 = v34 + 3;
    v37 = 112 * (v34 >> 1) + 48 * ((*(_WORD *)(v33 + 4) & 1) + 3);
    v78 = v37;
    if ( (unsigned int)v34 >= 2 )
    {
      v37 += 48;
      v35 = v34 + 3;
      v36 = v34 + 4;
      v82 = v34 + 4;
      v78 = v37;
      v80 = v34 + 3;
    }
    LODWORD(entityB) = *(__int16 *)(v33 + 20) << 16;
    if ( *(float *)&entityB != 0.0 )
    {
      v37 += 96;
      v35 += 2;
      v36 += 3;
      v82 = v36;
      v78 = v37;
      v80 = v35;
    }
    v38 = m_contactMgr[9].vfptr;
    if ( v38 )
    {
      v39 = *(_DWORD **)(*((_QWORD *)&v38->__first_virtual_table_function__
                         + BYTE2(v38[2].__first_virtual_table_function__))
                       + 296i64);
      v39[5] -= v37;
      v39[6] -= v35;
      v39[7] -= v36;
      v40 = m_contactMgr[9].vfptr;
      HIWORD(v40[2].__vecDelDtor) -= v80;
      LOWORD(v40[2].__first_virtual_table_function__) -= v82;
      WORD2(v40[2].__vecDelDtor) -= v78;
    }
    v41 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
    v42 = atomSizeRoundUp(*(unsigned __int16 *)(v41 + 2));
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*Value[11] + 16i64))(Value[11], v41, v42);
    m_numContactPoints = serializedEntryIn->m_atom.m_numContactPoints;
    Atom = hkpSimpleContactConstraintAtomUtil::allocateAtom(
             m_numContactPoints,
             (unsigned __int8)serializedEntryIn->m_atom.m_numUserDatasForBodyA,
             (unsigned __int8)serializedEntryIn->m_atom.m_numUserDatasForBodyB,
             serializedEntryIn->m_atom.m_maxNumContactPoints);
    *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags = Atom;
    Atom->m_numContactPoints = m_numContactPoints;
    v46 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
    *(_WORD *)(v46 + 16) = serializedEntryIn->m_atom.m_info.m_flags;
    *(_WORD *)(v46 + 18) = serializedEntryIn->m_atom.m_info.m_biNormalAxis;
    *(_WORD *)(v46 + 20) = serializedEntryIn->m_atom.m_info.m_rollingFrictionMultiplier.m_value;
    *(_WORD *)(v46 + 22) = serializedEntryIn->m_atom.m_info.m_internalData1.m_value;
    *(_WORD *)(v46 + 24) = serializedEntryIn->m_atom.m_info.m_rhsRolling[0].m_value;
    *(_WORD *)(v46 + 26) = serializedEntryIn->m_atom.m_info.m_rhsRolling[1].m_value;
    *(float *)(v46 + 28) = serializedEntryIn->m_atom.m_info.m_contactRadius;
    *(float *)(v46 + 32) = serializedEntryIn->m_atom.m_info.m_data[0];
    *(float *)(v46 + 36) = serializedEntryIn->m_atom.m_info.m_data[1];
    *(float *)(v46 + 40) = serializedEntryIn->m_atom.m_info.m_data[2];
    *(float *)(v46 + 44) = serializedEntryIn->m_atom.m_info.m_data[3];
    v47 = m_contactMgr[9].vfptr;
    m_contactMgr[4].m_type = serializedEntryIn->m_atom.m_sizeOfAllAtoms;
    v47[1].__first_virtual_table_function__ = *(void (__fastcall **)(hkBaseObject *))&m_contactMgr[4].m_memSizeAndFlags;
    LOWORD(m_contactMgr[9].vfptr[2].__vecDelDtor) = *(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 2i64);
    v48 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
    v49 = *(unsigned __int16 *)(v48 + 4);
    v50 = v49 + 2;
    v51 = v49 + 3;
    v81 = v49 + 2;
    v83 = v49 + 3;
    v52 = 112 * (v49 >> 1) + 48 * ((*(_WORD *)(v48 + 4) & 1) + 3);
    v79 = 112 * (v49 >> 1) + 48 * ((*(_WORD *)(v48 + 4) & 1) + 3);
    v53 = v52 + 48;
    if ( (unsigned int)v49 >= 2 )
    {
      v50 = v49 + 3;
      v52 += 48;
      v51 = v49 + 4;
      v83 = v49 + 4;
      v79 = v53;
      v81 = v49 + 3;
    }
    LODWORD(entityB) = *(__int16 *)(v48 + 20) << 16;
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
    v54 = *(_DWORD **)(*((_QWORD *)&m_contactMgr[9].vfptr->__first_virtual_table_function__
                       + BYTE2(m_contactMgr[9].vfptr[2].__first_virtual_table_function__))
                     + 296i64);
    if ( m_contactMgr[9].vfptr )
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
      v56 = m_contactMgr[9].vfptr;
      HIWORD(v56[2].__vecDelDtor) += v81;
      LOWORD(v56[2].__first_virtual_table_function__) += v83;
      WORD2(v56[2].__vecDelDtor) += v79;
      v57 = WORD2(m_contactMgr[9].vfptr[2].__vecDelDtor);
      if ( v54[4] > v57 )
        v57 = v54[4];
      v54[4] = v57;
    }
    hkString::memCpy(
      (void *)(32i64 * *(unsigned __int16 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 6i64)
             + *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags
             + 48i64),
      serializedEntryIn->m_propertiesStream.m_data,
      m_numContactPoints * *(unsigned __int8 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 10i64));
    hkString::memCpy(
      (void *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 48i64),
      serializedEntryIn->m_contactPoints.m_data,
      32 * m_numContactPoints);
    v59 = input;
    if ( input->m_zeroUserDataInContactPointProperties )
    {
      v60 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
      v58 = 0i64;
      v61 = 32i64 * *(unsigned __int16 *)(v60 + 6) + v60 + 48;
      if ( *(_WORD *)(v60 + 4) )
      {
        v62 = *(unsigned __int8 *)(v60 + 10);
        do
        {
          *(_QWORD *)(v61 + 8) = 0i64;
          v58 = (unsigned int)(v58 + 1);
          v61 += v62;
        }
        while ( (int)v58 < *(unsigned __int16 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) );
      }
    }
    v63 = m_contactMgr->vfptr;
    v84 = 0i64;
    v85 = 0;
    v86 = 0x80000000;
    ((void (__fastcall *)(hkpContactMgr *, _WORD **, __int64))v63[6].__vecDelDtor)(m_contactMgr, &v84, v58);
    v64 = v85;
    if ( input->m_fireContactPointAddedCallbacks && v85 > 0 )
    {
      v65 = 0i64;
      do
      {
        v66 = !v59->m_passCollidablePointersInCollisionCallbacks;
        entityB = 0i64;
        v67 = v84[v65];
        v90 = 2139095022;
        v91 = 0i64;
        v89 = 0i64;
        p_m_collidable = 0i64;
        if ( !v66 )
        {
          entityB = &entityA->m_collidable;
          p_m_collidable = (hkpRigidBody *)&v7->m_collidable;
        }
        v68 = (hkpContactPointProperties *)m_contactMgr->vfptr[5].__vecDelDtor(m_contactMgr, v67);
        v69 = ((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))m_contactMgr->vfptr[5].__first_virtual_table_function__)(
                m_contactMgr,
                v67);
        LODWORD(event.m_bodies[1]) = 1;
        *(_QWORD *)&event.m_type = v69;
        *(_QWORD *)&event.m_source = entityB;
        event.m_rotateNormal = (float *)collisionInput;
        event.m_bodies[0] = p_m_collidable;
        event.m_shapeKeyStorage = (unsigned int *)&v88;
        event.m_contactPointProperties = v68;
        event.m_separatingVelocity = (float *)m_contactMgr;
        LOWORD(event.m_accumulators[0]) = v67;
        event.m_contactPoint = 0i64;
        *(_QWORD *)&event.m_firingCallbacksForFullManifold.m_bool = 0i64;
        if ( m_contactMgr->m_type )
          WORD1(event.m_accumulators[0]) = 0;
        else
          WORD1(event.m_accumulators[0]) = m_contactMgr[1].m_referenceCount;
        hkpWorldCallbackUtil::fireContactPointAdded(entityA->m_world, (hkpContactPointAddedEvent *)&event);
        if ( entityA->m_contactListeners.m_size )
          hkpEntityCallbackUtil::fireContactPointAddedInternal(entityA, (hkpContactPointAddedEvent *)&event);
        if ( v7->m_contactListeners.m_size )
          hkpEntityCallbackUtil::fireContactPointAddedInternal(v7, (hkpContactPointAddedEvent *)&event);
        v64 = v85;
        v59 = input;
        ++v26;
        ++v65;
      }
      while ( v26 < v85 );
    }
    if ( v59->m_fireContactPointCallbacks )
    {
      v70 = 0i64;
      for ( j = v64; v70 < j; ++v70 )
      {
        v72 = v84[v70];
        if ( (*((_BYTE *)m_contactMgr->vfptr[5].__vecDelDtor(m_contactMgr, v72) + 19) & 1) == 0 )
        {
          v73 = (__int64)m_contactMgr->vfptr[5].__vecDelDtor(m_contactMgr, v72);
          v74 = (hkContactPoint *)((__int64 (__fastcall *)(hkpContactMgr *, _QWORD))m_contactMgr->vfptr[5].__first_virtual_table_function__)(
                                    m_contactMgr,
                                    v72);
          m_world = entityA->m_world;
          event.m_contactPointProperties = (hkpContactPointProperties *)v73;
          *(_OWORD *)&event.m_separatingVelocity = 0i64;
          event.m_contactPoint = v74;
          event.m_source = SOURCE_WORLD;
          event.m_contactMgr = (hkpSimpleConstraintContactMgr *)m_contactMgr;
          event.m_shapeKeyStorage = (unsigned int *)(v73 + 32);
          event.m_bodies[0] = entityA;
          event.m_bodies[1] = v7;
          event.m_type = 4;
          *(_WORD *)&event.m_firingCallbacksForFullManifold.m_bool = 0;
          event.m_lastCallbackForFullManifold.m_bool = 0;
          event.m_accumulators[0] = 0i64;
          event.m_accumulators[1] = 0i64;
          hkpWorldCallbackUtil::fireContactPointCallback(m_world, &event);
          event.m_source = SOURCE_A;
          if ( entityA->m_contactListeners.m_size )
            hkpEntityCallbackUtil::fireContactPointCallbackInternal(entityA, &event);
          event.m_source = SOURCE_B;
          if ( v7->m_contactListeners.m_size )
            hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, &event);
        }
      }
    }
    hkAgentNnMachine_InvalidateTimInAgent(entry, collisionInput);
    v76 = v86;
    result->m_enum = HK_SUCCESS;
    v85 = 0;
    if ( v76 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v84, 2 * (v76 & 0x3FFFFFFF));
    return result;
  }
}

// File Line: 532
// RVA: 0xE22060
hkResult *__fastcall hkpSaveContactPointsUtil::serializeEntry(
        hkResult *result,
        hkpAgentEntry *entry,
        hkBool isNnEntry,
        hkpProcessCollisionInput *input,
        int *sizeOfThisEntryOut,
        hkpSerializedAgentNnEntry::SerializedAgentType *agentTypeOut,
        hkpAgent1nTrack **agent1nTrackOut,
        hkpSerializedTrack1nInfo *trackInfoOut)
{
  __int64 v11; // rdi
  __int64 v12; // rax
  char *v13; // rdi
  int SerializedAgentType; // eax
  hkpAgent1nTrack *Agent1nTrack; // rax

  *agent1nTrackOut = 0i64;
  switch ( entry->m_streamCommand )
  {
    case 0:
    case 1:
      *sizeOfThisEntryOut = 16;
      result->m_enum = HK_SUCCESS;
      return result;
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
      SerializedAgentType = hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_processFunc);
      *agentTypeOut = SerializedAgentType;
      if ( SerializedAgentType <= 0 )
        goto $LN1_63;
      if ( SerializedAgentType <= 4 )
      {
        *agentTypeOut = SerializedAgentType;
        *sizeOfThisEntryOut = (unsigned __int8)entry->m_size;
$LN6_211:
        result->m_enum = HK_SUCCESS;
        return result;
      }
      if ( SerializedAgentType == 5 )
      {
        *agentTypeOut = CONVEX_LIST_AGENT3;
        *sizeOfThisEntryOut = (unsigned __int8)entry->m_size;
        if ( (v13[11] & 0x20) == 0 )
        {
          Agent1nTrack = hkConvexListAgent3::getAgent1nTrack(entry, v13);
          *agent1nTrackOut = Agent1nTrack;
          hkpSaveContactPointsUtil::serialize1nTrack(result, &Agent1nTrack->m_sectors, input, trackInfoOut);
          return result;
        }
        goto $LN6_211;
      }
      if ( (unsigned int)(SerializedAgentType - 6) > 3 )
      {
$LN1_63:
        result->m_enum = HK_FAILURE;
      }
      else
      {
        *sizeOfThisEntryOut = (unsigned __int8)entry->m_size;
        *agentTypeOut = SerializedAgentType;
        *agent1nTrackOut = (hkpAgent1nTrack *)(v13 + 8);
        hkpSaveContactPointsUtil::serialize1nTrack(
          result,
          (hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *)(v13 + 8),
          input,
          trackInfoOut);
      }
      return result;
    case 8:
      goto $LN6_211;
    default:
      goto $LN1_63;
  }
}

// File Line: 645
// RVA: 0xE221F0
hkResult *__fastcall hkpSaveContactPointsUtil::destroyOldEntry(
        hkResult *result,
        hkpSerializedAgentNnEntry::SerializedAgentType agentType,
        hkpProcessCollisionInput *input,
        hkpDynamicsContactMgr *mgr,
        hkpConstraintOwner *constraintOwner,
        hkpAgentNnEntry *nnEntry)
{
  int m_streamCommand; // eax
  char *p_m_contactMgr; // rsi
  hkpCollisionDispatcher *m_storage; // r14
  __int64 m_agentType; // r15

  m_streamCommand = (unsigned __int8)nnEntry->m_streamCommand;
  if ( m_streamCommand == 2 )
  {
    p_m_contactMgr = (char *)&nnEntry[1].m_contactMgr;
  }
  else
  {
    if ( m_streamCommand != 4 )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
    p_m_contactMgr = (char *)nnEntry[1].m_collidable;
  }
  m_storage = input->m_dispatcher.m_storage;
  m_agentType = (unsigned __int8)nnEntry->m_agentType;
  if ( hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[m_agentType].m_processFunc) == agentType
    && agentType )
  {
    m_storage->m_agent3Func[m_agentType].m_destroyFunc(nnEntry, p_m_contactMgr, mgr, constraintOwner, m_storage);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 692
// RVA: 0xE222B0
hkResult *__fastcall hkpSaveContactPointsUtil::deserializeEntry(
        hkResult *result,
        hkpSerializedAgentNnEntry *serializedEntryIn,
        int agentType,
        hkpSerializedTrack1nInfo *serializedTrack,
        hkpProcessCollisionInput *input,
        hkpAgentNnEntry *nnEntry)
{
  int m_streamCommand; // eax
  char *p_m_contactMgr; // rbp
  hkpAgent1nTrack *Agent1nTrack; // r9
  bool v14; // zf

  m_streamCommand = (unsigned __int8)nnEntry->m_streamCommand;
  if ( m_streamCommand == 2 )
  {
    p_m_contactMgr = (char *)&nnEntry[1].m_contactMgr;
  }
  else
  {
    if ( m_streamCommand != 4 )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
    p_m_contactMgr = (char *)nnEntry[1].m_collidable;
  }
  if ( hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)nnEntry->m_agentType].m_processFunc) != agentType
    || agentType <= 0 )
  {
LABEL_19:
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( agentType <= 4 )
  {
    hkString::memCpy(
      &nnEntry[1],
      &serializedEntryIn->m_nnEntryData[40],
      80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
    nnEntry->m_numContactPoints = serializedEntryIn->m_nnEntryData[2];
    nnEntry->m_size = serializedEntryIn->m_nnEntryData[3];
  }
  else
  {
    if ( agentType != 5 )
    {
      if ( (unsigned int)(agentType - 6) <= 3 )
      {
        hkString::memCpy(
          &nnEntry[1],
          &serializedEntryIn->m_nnEntryData[40],
          80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
        Agent1nTrack = (hkpAgent1nTrack *)(p_m_contactMgr + 8);
        v14 = p_m_contactMgr + 8 == 0i64;
LABEL_12:
        if ( !v14 )
        {
          Agent1nTrack->m_sectors.m_data = 0i64;
          Agent1nTrack->m_sectors.m_size = 0;
          Agent1nTrack->m_sectors.m_capacityAndFlags = 0x80000000;
        }
        hkpSaveContactPointsUtil::deserialize1nTrack(result, serializedTrack, input, &Agent1nTrack->m_sectors);
        return result;
      }
      goto LABEL_19;
    }
    hkString::memCpy(
      &nnEntry[1],
      &serializedEntryIn->m_nnEntryData[40],
      80 * (unsigned __int8)nnEntry->m_nnTrackType.m_storage - 40);
    nnEntry->m_numContactPoints = serializedEntryIn->m_nnEntryData[2];
    nnEntry->m_size = serializedEntryIn->m_nnEntryData[3];
    if ( (p_m_contactMgr[11] & 0x20) == 0 )
    {
      Agent1nTrack = hkConvexListAgent3::getAgent1nTrack(nnEntry, p_m_contactMgr);
      v14 = Agent1nTrack == 0i64;
      goto LABEL_12;
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 791
// RVA: 0xE22460
hkResult *__fastcall hkpSaveContactPointsUtil::serialize1nTrack(
        hkResult *result,
        hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *sectorsIn,
        hkpProcessCollisionInput *input,
        hkpSerializedTrack1nInfo *trackInfoOut)
{
  int m_size; // r9d
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v6; // rbx
  hkResult *v7; // rdi
  int v8; // eax
  int v9; // eax
  int v10; // r12d
  __int64 v11; // r13
  hkpAgent1nSector *v12; // rsi
  hkpAgentEntry *m_data; // rbp
  unsigned __int64 v14; // r15
  _QWORD **v15; // rax
  __int64 v16; // rax
  hkpSerializedSubTrack1nInfo *v17; // rbx
  _QWORD **v18; // rax
  _QWORD **Value; // rax
  hkpAgent1nSector *v20; // rax
  hkpAgent1nSector *v21; // rcx
  hkpAgent1nSector *v22; // rcx
  __int64 v23; // rax
  __int128 v24; // xmm0
  _QWORD **v26; // rax
  hkpSerializedAgentNnEntry::SerializedAgentType agentTypeOut; // [rsp+40h] [rbp-58h] BYREF
  hkResult resulta; // [rsp+44h] [rbp-54h] BYREF
  hkpAgent1nTrack *agent1nTrackOut; // [rsp+48h] [rbp-50h] BYREF
  int sizeOfThisEntryOut; // [rsp+B8h] [rbp+20h] BYREF

  m_size = sectorsIn->m_size;
  v6 = sectorsIn;
  v7 = result;
  v8 = trackInfoOut->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < m_size )
  {
    v9 = 2 * v8;
    if ( m_size < v9 )
      m_size = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&sizeOfThisEntryOut,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&trackInfoOut->m_sectors.m_data,
      m_size,
      8);
  }
  v10 = 0;
  if ( v6->m_size <= 0 )
  {
LABEL_31:
    v7->m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v6->m_data[v11];
      m_data = (hkpAgentEntry *)v12->m_data;
      v14 = (unsigned __int64)&v12->m_data[v12->m_bytesAllocated];
      if ( (unsigned __int64)v12->m_data < v14 )
        break;
LABEL_19:
      if ( trackInfoOut->m_sectors.m_size == (trackInfoOut->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&trackInfoOut->m_sectors.m_data, 8);
      ++trackInfoOut->m_sectors.m_size;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 512i64);
      v21 = v20;
      if ( v20 )
        v20->m_bytesAllocated = 0;
      else
        v21 = 0i64;
      trackInfoOut->m_sectors.m_data[v11] = v21;
      v22 = trackInfoOut->m_sectors.m_data[v11];
      if ( (((unsigned __int8)v22 | (unsigned __int8)v12) & 0xF) != 0 )
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
        v7 = result;
        goto LABEL_31;
      }
    }
    while ( 1 )
    {
      agent1nTrackOut = 0i64;
      sizeOfThisEntryOut = 0;
      v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v16 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(v15[11], 40i64);
      v17 = (hkpSerializedSubTrack1nInfo *)v16;
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_DWORD *)(v16 + 12) = 0x80000000;
        *(_QWORD *)(v16 + 16) = 0i64;
        *(_DWORD *)(v16 + 24) = 0;
        *(_QWORD *)(v16 + 28) = 0xFFFFFFFF80000000ui64;
      }
      else
      {
        v17 = 0i64;
      }
      if ( hkpSaveContactPointsUtil::serializeEntry(
             &resulta,
             m_data,
             0,
             input,
             &sizeOfThisEntryOut,
             &agentTypeOut,
             &agent1nTrackOut,
             v17)->m_enum )
        break;
      if ( v17->m_sectors.m_size )
      {
        v17->m_sectorIndex = v10;
        v17->m_offsetInSector = (_DWORD)agent1nTrackOut - (_DWORD)v12 - 16;
        if ( trackInfoOut->m_subTracks.m_size == (trackInfoOut->m_subTracks.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&trackInfoOut->m_subTracks.m_data,
            8);
        trackInfoOut->m_subTracks.m_data[trackInfoOut->m_subTracks.m_size++] = v17;
      }
      else
      {
        hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(v17);
        v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, __int64))(*v18[11] + 16i64))(
          v18[11],
          v17,
          40i64);
      }
      m_data = (hkpAgentEntry *)((char *)m_data + sizeOfThisEntryOut);
      if ( (unsigned __int64)m_data >= v14 )
      {
        v6 = sectorsIn;
        goto LABEL_19;
      }
    }
    if ( v17 )
    {
      hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(v17);
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, __int64))(*v26[11] + 16i64))(v26[11], v17, 40i64);
    }
    v7 = result;
    result->m_enum = HK_FAILURE;
  }
  return v7;
}

// File Line: 844
// RVA: 0xE22790
hkResult *__fastcall hkpSaveContactPointsUtil::deserialize1nTrack(
        hkResult *result,
        hkpSerializedTrack1nInfo *serializedTrack,
        hkpProcessCollisionInput *input,
        hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *sectorsOut)
{
  int m_size; // ebx
  int v6; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edi
  __int64 v11; // rbx
  _QWORD **Value; // rax
  hkpAgent1nSector *v13; // rax
  hkpAgent1nSector *v14; // rcx
  hkpAgent1nSector *v15; // rcx
  hkpAgent1nSector *v16; // rdx
  __int64 v17; // rax
  __int128 v18; // xmm0
  int v19; // ebx
  __int64 v20; // rdi
  hkpSerializedSubTrack1nInfo *v21; // rdx
  hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *v22; // r9
  hkResult *v23; // rax
  hkResult resulta; // [rsp+58h] [rbp+10h] BYREF
  hkpProcessCollisionInput *inputa; // [rsp+60h] [rbp+18h]

  inputa = input;
  m_size = serializedTrack->m_sectors.m_size;
  v6 = sectorsOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v8 = 2 * v6;
    v9 = serializedTrack->m_sectors.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&sectorsOut->m_data, v9, 8);
  }
  sectorsOut->m_size = m_size;
  v10 = 0;
  if ( serializedTrack->m_sectors.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 512i64);
      v14 = v13;
      if ( v13 )
        v13->m_bytesAllocated = 0;
      else
        v14 = 0i64;
      sectorsOut->m_data[v11] = v14;
      v15 = sectorsOut->m_data[v11];
      v16 = serializedTrack->m_sectors.m_data[v11];
      if ( (((unsigned __int8)v15 | (unsigned __int8)v16) & 0xF) != 0 )
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
    while ( v10 < serializedTrack->m_sectors.m_size );
  }
  v19 = 0;
  if ( serializedTrack->m_subTracks.m_size <= 0 )
  {
LABEL_22:
    v23 = result;
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = serializedTrack->m_subTracks.m_data[v20];
      v22 = (hkArray<hkpAgent1nSector *,hkContainerHeapAllocator> *)&sectorsOut->m_data[v21->m_sectorIndex]->m_data[v21->m_offsetInSector];
      if ( v22 )
      {
        v22->m_data = 0i64;
        v22->m_size = 0;
        v22->m_capacityAndFlags = 0x80000000;
      }
      if ( hkpSaveContactPointsUtil::deserialize1nTrack(&resulta, v21, inputa, v22)->m_enum == HK_FAILURE )
        break;
      ++v19;
      ++v20;
      if ( v19 >= serializedTrack->m_subTracks.m_size )
        goto LABEL_22;
    }
    v23 = result;
    result->m_enum = HK_FAILURE;
  }
  return v23;
}

// File Line: 880
// RVA: 0xE22970
__int64 __fastcall hkpSaveContactPointsUtil::getSerializedAgentType(
        void *(__fastcall *func)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))
{
  __int64 result; // rax

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
    return 9i64;
  return result;
}

