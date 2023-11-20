// File Line: 22
// RVA: 0xE17860
void __fastcall hkpPhysicsData::hkpPhysicsData(hkpPhysicsData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsData::`vftable';
  this->m_systems.m_capacityAndFlags = 2147483648;
  this->m_systems.m_data = 0i64;
  this->m_systems.m_size = 0;
  this->m_worldCinfo = 0i64;
}

// File Line: 28
// RVA: 0xE17A90
void __fastcall hkpPhysicsData::populateFromWorld(hkpPhysicsData *this, hkpWorld *world, bool saveContactPoints)
{
  bool v3; // bl
  hkpWorld *v4; // rsi
  hkpPhysicsData *v5; // rdi
  _QWORD **v6; // rax
  hkpWorldCinfo *v7; // rax
  _QWORD **v8; // rax
  hkpPhysicsSystem *v9; // rax
  hkpPhysicsSystemWithContacts *v10; // rbx
  hkpSaveContactPointsUtil::SavePointsInput input; // [rsp+20h] [rbp-18h]

  v3 = saveContactPoints;
  v4 = world;
  v5 = this;
  if ( !this->m_worldCinfo )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkpWorldCinfo *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 256i64);
    if ( v7 )
      hkpWorldCinfo::hkpWorldCinfo(v7);
    v5->m_worldCinfo = v7;
  }
  hkpWorld::getCinfo(v4, v5->m_worldCinfo);
  hkpWorld::getWorldAsSystems(v4, &v5->m_systems);
  if ( v3 )
  {
    input.m_useEntityIds = 0;
    input.m_getIdForEntity = 0i64;
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 120i64);
    v10 = (hkpPhysicsSystemWithContacts *)v9;
    if ( v9 )
    {
      hkpPhysicsSystem::hkpPhysicsSystem(v9);
      v10->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystemWithContacts::`vftable';
      v10->m_contacts.m_data = 0i64;
      v10->m_contacts.m_size = 0;
      v10->m_contacts.m_capacityAndFlags = 2147483648;
    }
    else
    {
      v10 = 0i64;
    }
    hkpSaveContactPointsUtil::saveContactPoints(&input, v4, v10);
    v10->m_active.m_bool = 0;
    if ( v5->m_systems.m_size == (v5->m_systems.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_systems, 8);
    v5->m_systems.m_data[v5->m_systems.m_size++] = (hkpPhysicsSystem *)&v10->vfptr;
  }
}

// File Line: 54
// RVA: 0xE17890
void __fastcall hkpPhysicsData::~hkpPhysicsData(hkpPhysicsData *this)
{
  hkpPhysicsData *v1; // rbx
  hkpWorldCinfo *v2; // rcx
  int v3; // edi
  __int64 v4; // rsi
  int v5; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsData::`vftable';
  v2 = this->m_worldCinfo;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = 0;
  if ( v1->m_systems.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_systems.m_data[v4]->vfptr);
      ++v3;
      ++v4;
    }
    while ( v3 < v1->m_systems.m_size );
  }
  v5 = v1->m_systems.m_capacityAndFlags;
  v1->m_systems.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_systems.m_data,
      8 * v5);
  v1->m_systems.m_data = 0i64;
  v1->m_systems.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 68
// RVA: 0xE17BC0
hkpWorld *__fastcall hkpPhysicsData::createWorld(hkpPhysicsData *this, hkBool registerAllAgents)
{
  hkpPhysicsData *v2; // rdi
  _QWORD **v3; // rax
  hkpWorld *v4; // rax
  hkpWorldCinfo *v5; // rdx
  _QWORD **v6; // rax
  hkpWorld *v7; // rax
  hkpWorld *v8; // rsi
  int v9; // ebp
  __int64 v10; // rbx
  hkpPhysicsSystem **v11; // rdx
  hkpWorldCinfo *v12; // rax
  hkpSaveContactPointsUtil::LoadPointsInput input; // [rsp+20h] [rbp-138h]
  hkpWorldCinfo v15; // [rsp+40h] [rbp-118h]
  char v16; // [rsp+160h] [rbp+8h]
  char v17; // [rsp+168h] [rbp+10h]

  v17 = registerAllAgents.m_bool;
  v2 = this;
  hkpWorldCinfo::hkpWorldCinfo(&v15);
  if ( v2->m_worldCinfo )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v4 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 1088i64);
    if ( v4 )
    {
      v5 = v2->m_worldCinfo;
      goto LABEL_6;
    }
  }
  else
  {
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v4 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(v3[11], 1088i64);
    if ( v4 )
    {
      v5 = &v15;
LABEL_6:
      hkpWorld::hkpWorld(v4, v5, 0x1332998u);
      v8 = v7;
      goto LABEL_8;
    }
  }
  v8 = 0i64;
LABEL_8:
  if ( v17 )
    hkpAgentRegisterUtil::registerAllAgents(v8->m_collisionDispatcher);
  v9 = 0;
  if ( v2->m_systems.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      hkpWorld::addPhysicsSystem(v8, v2->m_systems.m_data[v10]);
      if ( *(_BYTE *)v2->m_systems.m_data[v10]->vfptr[2].__vecDelDtor(
                       (hkBaseObject *)&v2->m_systems.m_data[v10]->vfptr,
                       (unsigned int)&v16) )
      {
        v11 = v2->m_systems.m_data;
        *(_WORD *)&input.m_removeSerializedAgentsWhenLoaded = 0;
        input.m_getEntityFromId = 0i64;
        *(_WORD *)&input.m_fireContactPointAddedCallbacks = 257;
        input.m_passCollidablePointersInCollisionCallbacks = 0;
        hkpSaveContactPointsUtil::loadContactPoints(&input, (hkpPhysicsSystemWithContacts *)v11[v10], v8);
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v2->m_systems.m_size );
  }
  v12 = v2->m_worldCinfo;
  if ( v12 && v12->m_collisionFilter.m_pntr )
    hkpWorld::updateCollisionFilterOnWorld(v8, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  v15.vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable';
  if ( v15.m_memoryWatchDog.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v15.m_memoryWatchDog.m_pntr->vfptr);
  v15.m_memoryWatchDog.m_pntr = 0i64;
  if ( v15.m_convexListFilter.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v15.m_convexListFilter.m_pntr->vfptr);
  v15.m_convexListFilter.m_pntr = 0i64;
  if ( v15.m_collisionFilter.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v15.m_collisionFilter.m_pntr->vfptr);
  return v8;
}

// File Line: 109
// RVA: 0xE184F0
void __fastcall tryMoveEntity(hkpPhysicsSystem *fromSystem, hkpPhysicsSystem *toSystem, hkpEntity *entity)
{
  int v3; // er10
  hkpRigidBody *v4; // rdi
  __int64 v5; // r8
  hkpPhysicsSystem *v6; // rsi
  hkpPhysicsSystem *v7; // rbp
  int v8; // ebx
  __int64 v9; // r9
  hkpRigidBody **v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  hkpRigidBody **v13; // rax
  bool v14; // al
  hkBool result; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = (hkpRigidBody *)entity;
  v5 = fromSystem->m_rigidBodies.m_size;
  v6 = toSystem;
  v7 = fromSystem;
  v8 = 0;
  v9 = 0i64;
  if ( v5 <= 0 )
  {
LABEL_5:
    v8 = -1;
  }
  else
  {
    v10 = fromSystem->m_rigidBodies.m_data;
    while ( *v10 != v4 )
    {
      ++v9;
      ++v8;
      ++v10;
      if ( v9 >= v5 )
        goto LABEL_5;
    }
  }
  v11 = toSystem->m_rigidBodies.m_size;
  v12 = 0i64;
  if ( v11 <= 0 )
    goto LABEL_12;
  v13 = v6->m_rigidBodies.m_data;
  while ( *v13 != v4 )
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
      v14 = v6->m_active.m_bool || hkpEntity::isActive((hkpEntity *)&v4->vfptr, &result)->m_bool;
      v6->m_active.m_bool = v14;
      hkpPhysicsSystem::addRigidBody(v6, v4);
      hkpPhysicsSystem::removeRigidBody(v7, v8);
    }
  }
}

// File Line: 129
// RVA: 0xE17D90
void __fastcall hkpPhysicsData::splitPhysicsSystems(hkpPhysicsSystem *inputSystemConst, hkpPhysicsData::SplitPhysicsSystemsOutput *output)
{
  hkpPhysicsSystem *v2; // rbx
  _QWORD **v3; // rax
  hkpPhysicsSystem *v4; // rax
  int v5; // er15
  __int64 v6; // rax
  __int64 v7; // r14
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
  unsigned __int64 v20; // rax
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
  __int64 v42; // rcx
  int v43; // er13
  __int64 v44; // rbx
  __int64 v45; // rax
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
  char v56; // cl
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
  hkBool v67; // [rsp+30h] [rbp-88h]
  char *v68; // [rsp+38h] [rbp-80h]
  int v69; // [rsp+40h] [rbp-78h]
  int v70; // [rsp+44h] [rbp-74h]
  hkpPhysicsSystem *v71; // [rsp+48h] [rbp-70h]
  hkpPhysicsSystem *v72; // [rsp+50h] [rbp-68h]
  hkpPhysicsSystem *v73; // [rsp+58h] [rbp-60h]
  __int64 v74; // [rsp+60h] [rbp-58h]
  __int64 v75; // [rsp+68h] [rbp-50h]
  char v76; // [rsp+C0h] [rbp+8h]
  hkpPhysicsData::SplitPhysicsSystemsOutput *v77; // [rsp+C8h] [rbp+10h]
  char v78; // [rsp+D0h] [rbp+18h]
  hkBool result; // [rsp+D8h] [rbp+20h]

  v77 = output;
  v2 = inputSystemConst;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(v3[11], 104i64);
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
  if ( v2->m_rigidBodies.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkpPhysicsSystem::addRigidBody((hkpPhysicsSystem *)v7, v2->m_rigidBodies.m_data[v9]);
      ++v8;
      ++v9;
    }
    while ( v8 < v2->m_rigidBodies.m_size );
  }
  v10 = 0;
  if ( v2->m_actions.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkpPhysicsSystem::addAction((hkpPhysicsSystem *)v7, v2->m_actions.m_data[v11]);
      ++v10;
      ++v11;
    }
    while ( v10 < v2->m_actions.m_size );
  }
  v12 = 0;
  if ( v2->m_constraints.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkpPhysicsSystem::addConstraint((hkpPhysicsSystem *)v7, v2->m_constraints.m_data[v13]);
      ++v12;
      ++v13;
    }
    while ( v12 < v2->m_constraints.m_size );
  }
  v14 = 0;
  if ( v2->m_phantoms.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      hkpPhysicsSystem::addPhantom((hkpPhysicsSystem *)v7, v2->m_phantoms.m_data[v15]);
      ++v14;
      ++v15;
    }
    while ( v14 < v2->m_phantoms.m_size );
  }
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 104i64);
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
  v20 = *(_QWORD *)(v7 + 88);
  v19->m_active.m_bool = 0;
  v19->m_userData = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 104i64);
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
  v25 = *(_QWORD *)(v7 + 88);
  v24->m_active.m_bool = 0;
  v24->m_userData = v25;
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 104i64);
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
  v30 = *(_QWORD *)(v7 + 88);
  v29->m_active.m_bool = 0;
  v29->m_userData = v30;
  if ( *(_DWORD *)(v7 + 24) > 0 )
  {
    while ( 1 )
    {
      v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(v31[11], 104i64);
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
      v34->m_userData = *(_QWORD *)(v7 + 88);
      v34->m_active = (hkBool)hkpEntity::isActive(**(hkpEntity ***)(v7 + 16), &result)->m_bool;
      hkpPhysicsSystem::addRigidBody(v34, **(hkpRigidBody ***)(v7 + 16));
      hkpPhysicsSystem::removeRigidBody((hkpPhysicsSystem *)v7, 0);
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
          v39 = *(hkpEntity **)((char *)v34->m_rigidBodies.m_data + v37);
          if ( *(_DWORD *)(v7 + 40) > 0 )
          {
            v40 = 0i64;
            do
            {
              v41 = *(hkpConstraintInstance **)(v40 + *(_QWORD *)(v7 + 32));
              if ( v41->m_entities[0] == v39 || v41->m_entities[1] == v39 )
              {
                v35 = 1;
                hkpPhysicsSystem::addConstraint(toSystem, v41);
                v42 = *(_QWORD *)(v40 + *(_QWORD *)(v7 + 32));
                if ( v39 != (hkpEntity *)(*(_QWORD *)(v42 + 40) ^ *(_QWORD *)(v42 + 48))
                  && *(_BYTE *)(((unsigned __int64)v39 ^ *(_QWORD *)(v42 + 40) ^ *(_QWORD *)(v42 + 48)) + 0x160) != 5 )
                {
                  tryMoveEntity(
                    (hkpPhysicsSystem *)v7,
                    toSystem,
                    (hkpEntity *)((unsigned __int64)v39 ^ *(_QWORD *)(v42 + 40) ^ *(_QWORD *)(v42 + 48)));
                }
                hkpPhysicsSystem::removeConstraint((hkpPhysicsSystem *)v7, v38);
              }
              else
              {
                ++v38;
                v40 += 8i64;
              }
            }
            while ( v38 < *(_DWORD *)(v7 + 40) );
            v34 = toSystem;
            v37 = v74;
            v36 = v65;
            v78 = v35;
            v5 = 0;
          }
          v43 = 0;
          if ( *(_DWORD *)(v7 + 56) > 0 )
          {
            v44 = 0i64;
            v75 = 0i64;
            while ( 1 )
            {
              v45 = *(_QWORD *)(v7 + 48);
              v68 = 0i64;
              v69 = 0;
              v70 = 2147483648;
              (*(void (__fastcall **)(_QWORD, char **))(**(_QWORD **)(v44 + v45) + 32i64))(*(_QWORD *)(v44 + v45), &v68);
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
                  hkpPhysicsSystem::addAction(v34, *(hkpAction **)(*(_QWORD *)(v7 + 48) + v44));
                  hkpPhysicsSystem::removeAction((hkpPhysicsSystem *)v7, v43);
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
                      tryMoveEntity((hkpPhysicsSystem *)v7, toSystem, v52);
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
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v68,
                  8 * v70);
              v34 = toSystem;
              v68 = 0i64;
              v70 = 2147483648;
              if ( v43 >= *(_DWORD *)(v7 + 56) )
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
        if ( v77->m_constrainedSystems.m_size == (v77->m_constrainedSystems.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v77->m_constrainedSystems,
            8);
        v29 = v72;
        v19 = v71;
        v24 = v73;
        v77->m_constrainedSystems.m_data[v77->m_constrainedSystems.m_size++] = v34;
        goto LABEL_87;
      }
      v53 = (hkpEntity **)v34->m_rigidBodies.m_data;
      v54 = (hkpRigidBody *)*v53;
      v55 = !(*v53)->m_simulationIsland || hkpEntity::isActive(*v53, &v67)->m_bool;
      v56 = v54->m_motion.m_type.m_storage;
      if ( v56 == 4 )
        break;
      if ( v56 != 5 )
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
      v34->vfptr->__vecDelDtor((hkBaseObject *)&v34->vfptr, 1u);
LABEL_87:
      if ( *(_DWORD *)(v7 + 24) <= 0 )
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
    v34->vfptr->__vecDelDtor((hkBaseObject *)&v34->vfptr, 1u);
    goto LABEL_87;
  }
LABEL_88:
  if ( v29->m_rigidBodies.m_size )
  {
    v59 = v77;
    v77->m_unconstrainedKeyframedBodies = v29;
  }
  else
  {
    v29->vfptr->__vecDelDtor((hkBaseObject *)&v29->vfptr, 1u);
    v59 = v77;
    v77->m_unconstrainedKeyframedBodies = 0i64;
  }
  if ( v24->m_rigidBodies.m_size )
  {
    v59->m_unconstrainedFixedBodies = v24;
  }
  else
  {
    v24->vfptr->__vecDelDtor((hkBaseObject *)&v24->vfptr, 1u);
    v59->m_unconstrainedFixedBodies = 0i64;
  }
  if ( v19->m_rigidBodies.m_size )
  {
    v59->m_unconstrainedMovingBodies = v19;
  }
  else
  {
    v19->vfptr->__vecDelDtor((hkBaseObject *)&v19->vfptr, 1u);
    v59->m_unconstrainedMovingBodies = 0i64;
  }
  if ( *(_DWORD *)(v7 + 72) <= 0 )
  {
    v59->m_phantoms = 0i64;
  }
  else
  {
    v60 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v61 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v60[11] + 8i64))(v60[11], 104i64);
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
    v63->m_userData = *(_QWORD *)(v7 + 88);
    v59->m_phantoms = v63;
    if ( *(_DWORD *)(v7 + 72) > 0 )
    {
      v64 = 0i64;
      do
      {
        hkpPhysicsSystem::addPhantom(v63, *(hkpPhantom **)(*(_QWORD *)(v7 + 64) + v64));
        ++v5;
        v64 += 8i64;
      }
      while ( v5 < *(_DWORD *)(v7 + 72) );
    }
  }
  (**(void (__fastcall ***)(__int64, signed __int64))v7)(v7, 1i64);
}

// File Line: 354
// RVA: 0xE17950
hkpPhysicsSystem *__fastcall hkpPhysicsData::findPhysicsSystemByName(hkpPhysicsData *this, const char *name)
{
  int v2; // ebx
  const char *v3; // rbp
  hkpPhysicsData *v4; // rsi
  __int64 v5; // rdi
  const char *v6; // rcx

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( this->m_systems.m_size <= 0 )
    return 0i64;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = (const char *)((_QWORD)v4->m_systems.m_data[v5]->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( v6 )
    {
      if ( !(unsigned int)hkString::strCasecmp(v6, v3) )
        break;
    }
    ++v2;
    ++v5;
    if ( v2 >= v4->m_systems.m_size )
      return 0i64;
  }
  return v4->m_systems.m_data[v2];
}

// File Line: 370
// RVA: 0xE179E0
hkpRigidBody *__fastcall hkpPhysicsData::findRigidBodyByName(hkpPhysicsData *this, const char *name)
{
  int v2; // er14
  const char *v3; // r12
  hkpPhysicsData *v4; // r13
  __int64 v5; // r15
  int v6; // ebx
  hkpPhysicsSystem *v7; // rsi
  __int64 v8; // rdi
  hkpRigidBody *v9; // rbp

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( this->m_systems.m_size <= 0 )
    return 0i64;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = 0;
    v7 = v4->m_systems.m_data[v5];
    if ( v7->m_rigidBodies.m_size > 0 )
      break;
LABEL_8:
    ++v2;
    ++v5;
    if ( v2 >= v4->m_systems.m_size )
      return 0i64;
  }
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v7->m_rigidBodies.m_data[v8];
    if ( (_QWORD)v9->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( !(unsigned int)hkString::strCasecmp(
                            (const char *)((_QWORD)v9->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            v3) )
        return v9;
    }
    ++v6;
    ++v8;
    if ( v6 >= v7->m_rigidBodies.m_size )
      goto LABEL_8;
  }
}

