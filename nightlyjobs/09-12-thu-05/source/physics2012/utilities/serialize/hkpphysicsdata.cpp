// File Line: 22
// RVA: 0xE17860
void __fastcall hkpPhysicsData::hkpPhysicsData(hkpPhysicsData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsData::`vftable;
  this->m_systems.m_capacityAndFlags = 0x80000000;
  this->m_systems.m_data = 0i64;
  this->m_systems.m_size = 0;
  this->m_worldCinfo = 0i64;
}

// File Line: 28
// RVA: 0xE17A90
void __fastcall hkpPhysicsData::populateFromWorld(hkpPhysicsData *this, hkpWorld *world, bool saveContactPoints)
{
  _QWORD **Value; // rax
  hkpWorldCinfo *v7; // rax
  _QWORD **v8; // rax
  hkpPhysicsSystem *v9; // rax
  hkpPhysicsSystemWithContacts *v10; // rbx
  hkpSaveContactPointsUtil::SavePointsInput input; // [rsp+20h] [rbp-18h] BYREF

  if ( !this->m_worldCinfo )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkpWorldCinfo *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 256i64);
    if ( v7 )
      hkpWorldCinfo::hkpWorldCinfo(v7);
    this->m_worldCinfo = v7;
  }
  hkpWorld::getCinfo(world, this->m_worldCinfo);
  hkpWorld::getWorldAsSystems(world, &this->m_systems);
  if ( saveContactPoints )
  {
    input.m_useEntityIds = 0;
    input.m_getIdForEntity = 0i64;
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 120i64);
    v10 = (hkpPhysicsSystemWithContacts *)v9;
    if ( v9 )
    {
      hkpPhysicsSystem::hkpPhysicsSystem(v9);
      v10->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystemWithContacts::`vftable;
      v10->m_contacts.m_data = 0i64;
      v10->m_contacts.m_size = 0;
      v10->m_contacts.m_capacityAndFlags = 0x80000000;
    }
    else
    {
      v10 = 0i64;
    }
    hkpSaveContactPointsUtil::saveContactPoints(&input, world, v10);
    v10->m_active.m_bool = 0;
    if ( this->m_systems.m_size == (this->m_systems.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_systems.m_data, 8);
    this->m_systems.m_data[this->m_systems.m_size++] = v10;
  }
}

// File Line: 54
// RVA: 0xE17890
void __fastcall hkpPhysicsData::~hkpPhysicsData(hkpPhysicsData *this)
{
  hkpWorldCinfo *m_worldCinfo; // rcx
  int v3; // edi
  __int64 v4; // rsi
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsData::`vftable;
  m_worldCinfo = this->m_worldCinfo;
  if ( m_worldCinfo )
    hkReferencedObject::removeReference(m_worldCinfo);
  v3 = 0;
  if ( this->m_systems.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_systems.m_data[v4]);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_systems.m_size );
  }
  m_capacityAndFlags = this->m_systems.m_capacityAndFlags;
  this->m_systems.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_systems.m_data,
      8 * m_capacityAndFlags);
  this->m_systems.m_data = 0i64;
  this->m_systems.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 68
// RVA: 0xE17BC0
hkpWorld *__fastcall hkpPhysicsData::createWorld(hkpPhysicsData *this, hkBool registerAllAgents)
{
  _QWORD **v3; // rax
  hkpWorld *v4; // rax
  hkpWorldCinfo *m_worldCinfo; // rdx
  _QWORD **Value; // rax
  hkpWorld *v7; // rax
  hkpWorld *v8; // rsi
  int v9; // ebp
  __int64 v10; // rbx
  hkpPhysicsSystem **m_data; // rdx
  hkpWorldCinfo *v12; // rax
  hkpSaveContactPointsUtil::LoadPointsInput input; // [rsp+20h] [rbp-138h] BYREF
  hkpWorldCinfo v15; // [rsp+40h] [rbp-118h] BYREF
  char v16; // [rsp+160h] [rbp+8h] BYREF
  char m_bool; // [rsp+168h] [rbp+10h]

  m_bool = registerAllAgents.m_bool;
  hkpWorldCinfo::hkpWorldCinfo(&v15);
  if ( this->m_worldCinfo )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v4 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 1088i64);
    if ( v4 )
    {
      m_worldCinfo = this->m_worldCinfo;
      goto LABEL_6;
    }
  }
  else
  {
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v4 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v3[11] + 8i64))(v3[11], 1088i64);
    if ( v4 )
    {
      m_worldCinfo = &v15;
LABEL_6:
      hkpWorld::hkpWorld(v4, m_worldCinfo, 0x1332998u);
      v8 = v7;
      goto LABEL_8;
    }
  }
  v8 = 0i64;
LABEL_8:
  if ( m_bool )
    hkpAgentRegisterUtil::registerAllAgents(v8->m_collisionDispatcher);
  v9 = 0;
  if ( this->m_systems.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      hkpWorld::addPhysicsSystem(v8, this->m_systems.m_data[v10]);
      if ( *(_BYTE *)this->m_systems.m_data[v10]->vfptr[2].__vecDelDtor(this->m_systems.m_data[v10], &v16) )
      {
        m_data = this->m_systems.m_data;
        *(_WORD *)&input.m_removeSerializedAgentsWhenLoaded = 0;
        input.m_getEntityFromId = 0i64;
        *(_WORD *)&input.m_fireContactPointAddedCallbacks = 257;
        input.m_passCollidablePointersInCollisionCallbacks = 0;
        hkpSaveContactPointsUtil::loadContactPoints(&input, (hkpPhysicsSystemWithContacts *)m_data[v10], v8);
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->m_systems.m_size );
  }
  v12 = this->m_worldCinfo;
  if ( v12 && v12->m_collisionFilter.m_pntr )
    hkpWorld::updateCollisionFilterOnWorld(
      v8,
      HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
      HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  v15.vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable;
  if ( v15.m_memoryWatchDog.m_pntr )
    hkReferencedObject::removeReference(v15.m_memoryWatchDog.m_pntr);
  v15.m_memoryWatchDog.m_pntr = 0i64;
  if ( v15.m_convexListFilter.m_pntr )
    hkReferencedObject::removeReference(v15.m_convexListFilter.m_pntr);
  v15.m_convexListFilter.m_pntr = 0i64;
  if ( v15.m_collisionFilter.m_pntr )
    hkReferencedObject::removeReference(v15.m_collisionFilter.m_pntr);
  return v8;
}

// File Line: 109
// RVA: 0xE184F0
void __fastcall tryMoveEntity(hkpPhysicsSystem *fromSystem, hkpPhysicsSystem *toSystem, hkpRigidBody *entity)
{
  int v3; // r10d
  __int64 m_size; // r8
  int v8; // ebx
  __int64 v9; // r9
  hkpRigidBody **m_data; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  hkpRigidBody **v13; // rax
  bool v14; // al
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  m_size = fromSystem->m_rigidBodies.m_size;
  v8 = 0;
  v9 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v8 = -1;
  }
  else
  {
    m_data = fromSystem->m_rigidBodies.m_data;
    while ( *m_data != entity )
    {
      ++v9;
      ++v8;
      ++m_data;
      if ( v9 >= m_size )
        goto LABEL_5;
    }
  }
  v11 = toSystem->m_rigidBodies.m_size;
  v12 = 0i64;
  if ( v11 <= 0 )
    goto LABEL_12;
  v13 = toSystem->m_rigidBodies.m_data;
  while ( *v13 != entity )
  {
    ++v12;
    ++v3;
    ++v13;
    if ( v12 >= v11 )
      goto LABEL_12;
  }
  if ( v3 == -1 )
  {
LABEL_12:
    if ( v8 != -1 )
    {
      v14 = toSystem->m_active.m_bool || hkpEntity::isActive(entity, &result)->m_bool;
      toSystem->m_active.m_bool = v14;
      hkpPhysicsSystem::addRigidBody(toSystem, entity);
      hkpPhysicsSystem::removeRigidBody(fromSystem, v8);
    }
  }
}

// File Line: 129
// RVA: 0xE17D90
void __fastcall hkpPhysicsData::splitPhysicsSystems(
        hkpPhysicsSystem *inputSystemConst,
        hkpPhysicsData::SplitPhysicsSystemsOutput *output)
{
  _QWORD **Value; // rax
  hkpPhysicsSystem *v4; // rax
  int v5; // r15d
  hkpPhysicsSystem *v6; // rax
  hkpPhysicsSystem *v7; // r14
  int v8; // edi
  __int64 v9; // rsi
  int v10; // edi
  __int64 v11; // rsi
  int v12; // edi
  __int64 v13; // rsi
  int v14; // edi
  __int64 v15; // rsi
  _QWORD **v16; // rax
  hkpPhysicsSystem *v17; // rax
  hkpPhysicsSystem *v18; // rax
  hkpPhysicsSystem *v19; // r12
  unsigned __int64 m_userData; // rax
  _QWORD **v21; // rax
  hkpPhysicsSystem *v22; // rax
  hkpPhysicsSystem *v23; // rax
  hkpPhysicsSystem *v24; // r13
  unsigned __int64 v25; // rax
  _QWORD **v26; // rax
  hkpPhysicsSystem *v27; // rax
  hkpPhysicsSystem *v28; // rax
  hkpPhysicsSystem *v29; // rbp
  unsigned __int64 v30; // rax
  _QWORD **v31; // rax
  hkpPhysicsSystem *v32; // rax
  hkpPhysicsSystem *v33; // rax
  hkpPhysicsSystem *v34; // rdi
  char v35; // si
  int v36; // edx
  __int64 v37; // rcx
  int v38; // ebx
  hkpEntity *v39; // r12
  __int64 v40; // rdi
  hkpConstraintInstance *v41; // rdx
  hkpConstraintInstance *v42; // rcx
  int v43; // r13d
  __int64 v44; // rbx
  hkpAction **m_data; // rax
  int v46; // ecx
  int v47; // ebp
  __int64 v48; // rsi
  char v49; // dl
  int v50; // edi
  __int64 v51; // rbx
  hkpEntity *v52; // r8
  hkpEntity **v53; // rax
  hkpRigidBody *v54; // rbx
  bool v55; // al
  char m_storage; // cl
  hkpPhysicsSystem *v57; // rcx
  hkpPhysicsSystem *v58; // rcx
  hkpPhysicsData::SplitPhysicsSystemsOutput *v59; // rbx
  _QWORD **v60; // rax
  hkpPhysicsSystem *v61; // rax
  hkpPhysicsSystem *v62; // rax
  hkpPhysicsSystem *v63; // rdi
  __int64 v64; // rbx
  int v65; // [rsp+20h] [rbp-98h]
  hkpPhysicsSystem *toSystem; // [rsp+28h] [rbp-90h]
  hkBool v67; // [rsp+30h] [rbp-88h] BYREF
  char *v68; // [rsp+38h] [rbp-80h] BYREF
  int v69; // [rsp+40h] [rbp-78h]
  int v70; // [rsp+44h] [rbp-74h]
  hkpPhysicsSystem *v71; // [rsp+48h] [rbp-70h]
  hkpPhysicsSystem *v72; // [rsp+50h] [rbp-68h]
  hkpPhysicsSystem *v73; // [rsp+58h] [rbp-60h]
  __int64 v74; // [rsp+60h] [rbp-58h]
  __int64 v75; // [rsp+68h] [rbp-50h]
  char v76; // [rsp+C0h] [rbp+8h]
  char v78; // [rsp+D0h] [rbp+18h]
  hkBool result; // [rsp+D8h] [rbp+20h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  v5 = 0;
  if ( v4 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 0;
  if ( inputSystemConst->m_rigidBodies.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkpPhysicsSystem::addRigidBody(v7, inputSystemConst->m_rigidBodies.m_data[v9]);
      ++v8;
      ++v9;
    }
    while ( v8 < inputSystemConst->m_rigidBodies.m_size );
  }
  v10 = 0;
  if ( inputSystemConst->m_actions.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkpPhysicsSystem::addAction(v7, inputSystemConst->m_actions.m_data[v11]);
      ++v10;
      ++v11;
    }
    while ( v10 < inputSystemConst->m_actions.m_size );
  }
  v12 = 0;
  if ( inputSystemConst->m_constraints.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkpPhysicsSystem::addConstraint(v7, inputSystemConst->m_constraints.m_data[v13]);
      ++v12;
      ++v13;
    }
    while ( v12 < inputSystemConst->m_constraints.m_size );
  }
  v14 = 0;
  if ( inputSystemConst->m_phantoms.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      hkpPhysicsSystem::addPhantom(v7, inputSystemConst->m_phantoms.m_data[v15]);
      ++v14;
      ++v15;
    }
    while ( v14 < inputSystemConst->m_phantoms.m_size );
  }
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 104i64);
  if ( v17 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v17);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v71 = v19;
  hkStringPtr::operator=(&v19->m_name, "Unconstrained Rigid Bodies");
  m_userData = v7->m_userData;
  v19->m_active.m_bool = 0;
  v19->m_userData = m_userData;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 104i64);
  if ( v22 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v22);
    v24 = v23;
  }
  else
  {
    v24 = 0i64;
  }
  v73 = v24;
  hkStringPtr::operator=(&v24->m_name, "Fixed Rigid Bodies");
  v25 = v7->m_userData;
  v24->m_active.m_bool = 0;
  v24->m_userData = v25;
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 104i64);
  if ( v27 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v27);
    v29 = v28;
  }
  else
  {
    v29 = 0i64;
  }
  v72 = v29;
  hkStringPtr::operator=(&v29->m_name, "Keyframed Rigid Bodies");
  v30 = v7->m_userData;
  v29->m_active.m_bool = 0;
  v29->m_userData = v30;
  if ( v7->m_rigidBodies.m_size > 0 )
  {
    while ( 1 )
    {
      v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v31[11] + 8i64))(v31[11], 104i64);
      if ( v32 )
      {
        hkpPhysicsSystem::hkpPhysicsSystem(v32);
        v34 = v33;
      }
      else
      {
        v34 = 0i64;
      }
      toSystem = v34;
      hkStringPtr::operator=(&v34->m_name, "Constrained System");
      v34->m_userData = v7->m_userData;
      v34->m_active = (hkBool)hkpEntity::isActive(*v7->m_rigidBodies.m_data, &result)->m_bool;
      hkpPhysicsSystem::addRigidBody(v34, *v7->m_rigidBodies.m_data);
      hkpPhysicsSystem::removeRigidBody(v7, 0);
      do
      {
        v35 = 0;
        v36 = 0;
        v78 = 0;
        v65 = 0;
        if ( v34->m_rigidBodies.m_size <= 0 )
          break;
        v37 = 0i64;
        v74 = 0i64;
        do
        {
          v38 = 0;
          v39 = *(hkpRigidBody **)((char *)v34->m_rigidBodies.m_data + v37);
          if ( v7->m_constraints.m_size > 0 )
          {
            v40 = 0i64;
            do
            {
              v41 = v7->m_constraints.m_data[v40];
              if ( v41->m_entities[0] == v39 || v41->m_entities[1] == v39 )
              {
                v35 = 1;
                hkpPhysicsSystem::addConstraint(toSystem, v41);
                v42 = v7->m_constraints.m_data[v40];
                if ( (unsigned __int64)v39 ^ (__int64)v42->m_entities[0] ^ (__int64)v42->m_entities[1]
                  && *(_BYTE *)(((unsigned __int64)v39 ^ (__int64)v42->m_entities[0] ^ (__int64)v42->m_entities[1])
                              + 0x160) != 5 )
                {
                  tryMoveEntity(
                    v7,
                    toSystem,
                    (hkpEntity *)((unsigned __int64)v39 ^ (__int64)v42->m_entities[0] ^ (__int64)v42->m_entities[1]));
                }
                hkpPhysicsSystem::removeConstraint(v7, v38);
              }
              else
              {
                ++v38;
                ++v40;
              }
            }
            while ( v38 < v7->m_constraints.m_size );
            v34 = toSystem;
            v37 = v74;
            v36 = v65;
            v78 = v35;
            v5 = 0;
          }
          v43 = 0;
          if ( v7->m_actions.m_size > 0 )
          {
            v44 = 0i64;
            v75 = 0i64;
            while ( 1 )
            {
              m_data = v7->m_actions.m_data;
              v68 = 0i64;
              v69 = 0;
              v70 = 0x80000000;
              (*(hkpAction **)((char *)m_data + v44))->vfptr[2].__vecDelDtor(
                *(hkpAction **)((char *)m_data + v44),
                (unsigned int)&v68);
              v46 = v69;
              v76 = 0;
              v47 = 0;
              if ( v69 <= 0 )
                goto LABEL_59;
              v48 = 0i64;
              do
              {
                if ( *(hkpEntity **)&v68[v48] == v39 )
                {
                  v78 = 1;
                  hkpPhysicsSystem::addAction(v34, *(hkpAction **)((char *)v7->m_actions.m_data + v44));
                  hkpPhysicsSystem::removeAction(v7, v43);
                  v46 = v69;
                  v49 = 1;
                  v76 = 1;
                  v50 = 0;
                  if ( v69 <= 0 )
                    goto LABEL_57;
                  v51 = 0i64;
                  do
                  {
                    v52 = *(hkpEntity **)&v68[v51];
                    if ( v52 != v39 && v52 && v52->m_motion.m_type.m_storage != 5 )
                    {
                      tryMoveEntity(v7, toSystem, v52);
                      v46 = v69;
                    }
                    ++v50;
                    v51 += 8i64;
                  }
                  while ( v50 < v46 );
                  v44 = v75;
                }
                v49 = v76;
LABEL_57:
                v34 = toSystem;
                ++v47;
                v48 += 8i64;
              }
              while ( v47 < v46 );
              if ( !v49 )
              {
LABEL_59:
                ++v43;
                v44 += 8i64;
                v75 = v44;
              }
              v69 = 0;
              if ( v70 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v68, 8 * v70);
              v34 = toSystem;
              v68 = 0i64;
              v70 = 0x80000000;
              if ( v43 >= v7->m_actions.m_size )
              {
                v35 = v78;
                v37 = v74;
                v36 = v65;
                break;
              }
            }
          }
          ++v36;
          v37 += 8i64;
          v65 = v36;
          v74 = v37;
        }
        while ( v36 < v34->m_rigidBodies.m_size );
      }
      while ( v35 );
      if ( v34->m_constraints.m_size || v34->m_actions.m_size )
      {
        if ( output->m_constrainedSystems.m_size == (output->m_constrainedSystems.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&output->m_constrainedSystems.m_data,
            8);
        v29 = v72;
        v19 = v71;
        v24 = v73;
        output->m_constrainedSystems.m_data[output->m_constrainedSystems.m_size++] = v34;
        goto LABEL_87;
      }
      v53 = v34->m_rigidBodies.m_data;
      v54 = (hkpRigidBody *)*v53;
      v55 = !(*v53)->m_simulationIsland || hkpEntity::isActive(*v53, &v67)->m_bool;
      m_storage = v54->m_motion.m_type.m_storage;
      if ( m_storage == 4 )
        break;
      if ( m_storage != 5 )
      {
        v19 = v71;
        if ( v71->m_active.m_bool || v55 )
          v55 = 1;
        v58 = v71;
        v71->m_active.m_bool = v55;
        hkpPhysicsSystem::addRigidBody(v58, v54);
        v29 = v72;
        goto LABEL_83;
      }
      v24 = v73;
      hkpPhysicsSystem::addRigidBody(v73, v54);
      v29 = v72;
      v19 = v71;
      v34->vfptr->__vecDelDtor(v34, 1u);
LABEL_87:
      if ( v7->m_rigidBodies.m_size <= 0 )
        goto LABEL_88;
    }
    v29 = v72;
    if ( v72->m_active.m_bool || v55 )
      v55 = 1;
    v57 = v72;
    v72->m_active.m_bool = v55;
    hkpPhysicsSystem::addRigidBody(v57, v54);
    v19 = v71;
LABEL_83:
    v24 = v73;
    v34->vfptr->__vecDelDtor(v34, 1u);
    goto LABEL_87;
  }
LABEL_88:
  if ( v29->m_rigidBodies.m_size )
  {
    v59 = output;
    output->m_unconstrainedKeyframedBodies = v29;
  }
  else
  {
    v29->vfptr->__vecDelDtor(v29, 1u);
    v59 = output;
    output->m_unconstrainedKeyframedBodies = 0i64;
  }
  if ( v24->m_rigidBodies.m_size )
  {
    v59->m_unconstrainedFixedBodies = v24;
  }
  else
  {
    v24->vfptr->__vecDelDtor(v24, 1u);
    v59->m_unconstrainedFixedBodies = 0i64;
  }
  if ( v19->m_rigidBodies.m_size )
  {
    v59->m_unconstrainedMovingBodies = v19;
  }
  else
  {
    v19->vfptr->__vecDelDtor(v19, 1u);
    v59->m_unconstrainedMovingBodies = 0i64;
  }
  if ( v7->m_phantoms.m_size <= 0 )
  {
    v59->m_phantoms = 0i64;
  }
  else
  {
    v60 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v61 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v60[11] + 8i64))(v60[11], 104i64);
    if ( v61 )
    {
      hkpPhysicsSystem::hkpPhysicsSystem(v61);
      v63 = v62;
    }
    else
    {
      v63 = 0i64;
    }
    hkStringPtr::operator=(&v63->m_name, "Phantoms");
    v63->m_userData = v7->m_userData;
    v59->m_phantoms = v63;
    if ( v7->m_phantoms.m_size > 0 )
    {
      v64 = 0i64;
      do
      {
        hkpPhysicsSystem::addPhantom(v63, v7->m_phantoms.m_data[v64]);
        ++v5;
        ++v64;
      }
      while ( v5 < v7->m_phantoms.m_size );
    }
  }
  v7->vfptr->__vecDelDtor(v7, 1u);
}

// File Line: 354
// RVA: 0xE17950
hkpPhysicsSystem *__fastcall hkpPhysicsData::findPhysicsSystemByName(hkpPhysicsData *this, const char *name)
{
  int v2; // ebx
  __int64 i; // rdi
  const char *v6; // rcx

  v2 = 0;
  if ( this->m_systems.m_size <= 0 )
    return 0i64;
  for ( i = 0i64; ; ++i )
  {
    v6 = (const char *)((unsigned __int64)this->m_systems.m_data[i]->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( v6 )
    {
      if ( !(unsigned int)hkString::strCasecmp(v6, name) )
        break;
    }
    if ( ++v2 >= this->m_systems.m_size )
      return 0i64;
  }
  return this->m_systems.m_data[v2];
}

// File Line: 370
// RVA: 0xE179E0
hkpRigidBody *__fastcall hkpPhysicsData::findRigidBodyByName(hkpPhysicsData *this, const char *name)
{
  int v2; // r14d
  __int64 i; // r15
  int v6; // ebx
  hkpPhysicsSystem *v7; // rsi
  __int64 v8; // rdi
  hkpRigidBody *v9; // rbp

  v2 = 0;
  if ( this->m_systems.m_size <= 0 )
    return 0i64;
  for ( i = 0i64; ; ++i )
  {
    v6 = 0;
    v7 = this->m_systems.m_data[i];
    if ( v7->m_rigidBodies.m_size > 0 )
      break;
LABEL_8:
    if ( ++v2 >= this->m_systems.m_size )
      return 0i64;
  }
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v7->m_rigidBodies.m_data[v8];
    if ( ((unsigned __int64)v9->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0
      && !(unsigned int)hkString::strCasecmp(
                          (const char *)((unsigned __int64)v9->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          name) )
    {
      return v9;
    }
    ++v6;
    ++v8;
    if ( v6 >= v7->m_rigidBodies.m_size )
      goto LABEL_8;
  }
}

