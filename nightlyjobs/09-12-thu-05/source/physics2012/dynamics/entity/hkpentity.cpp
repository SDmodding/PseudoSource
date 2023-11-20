// File Line: 49
// RVA: 0xD616E0
void __fastcall hkpEntity::hkpEntity(hkpEntity *this, hkpShape *shape)
{
  hkpEntity *v2; // rdi

  v2 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, shape, BROAD_PHASE_ENTITY);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  v2->m_material.m_friction = 0.5;
  v2->m_material.m_restitution = 0.40000001;
  v2->m_material.m_rollingFrictionMultiplier.m_value = 0;
  v2->m_constraintsMaster.m_data = 0i64;
  *(_DWORD *)&v2->m_constraintsMaster.m_size = 2147483648;
  v2->m_constraintsSlave.m_data = 0i64;
  v2->m_constraintsSlave.m_size = 0;
  v2->m_constraintsSlave.m_capacityAndFlags = 2147483648;
  v2->m_constraintRuntime.m_data = 0i64;
  v2->m_constraintRuntime.m_size = 0;
  v2->m_constraintRuntime.m_capacityAndFlags = 2147483648;
  v2->m_spuCollisionCallback.m_util = 0i64;
  *(_DWORD *)&v2->m_spuCollisionCallback.m_capacity = 16973824;
  hkpMotion::hkpMotion((hkpMotion *)&v2->m_motion.vfptr);
  v2->m_motion.m_savedMotion = 0i64;
  v2->m_motion.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
  v2->m_contactListeners.m_data = 0i64;
  *(_DWORD *)&v2->m_contactListeners.m_size = 2147483648;
  v2->m_actions.m_data = 0i64;
  *(_DWORD *)&v2->m_actions.m_size = 2147483648;
  v2->m_localFrame.m_pntr = 0i64;
  v2->m_simulationIsland = 0i64;
  v2->m_extendedListeners = 0i64;
  v2->m_limitContactImpulseUtilAndFlag = 0i64;
  v2->m_solverData = 0;
  v2->m_numShapeKeysInContactPointProperties = 0;
  v2->m_storageIndex = -1;
  v2->m_breakableBody = 0i64;
  v2->m_uid = -1;
  v2->m_damageMultiplier = 1.0;
  v2->m_npData = -1;
}

// File Line: 69
// RVA: 0xD61840
void __fastcall hkpEntity::hkpEntity(hkpEntity *this, hkFinishLoadedObjectFlag flag)
{
  hkpEntity *v2; // rbx
  _QWORD *v3; // rdx
  void **v4; // rax
  int v5; // [rsp+38h] [rbp+10h]

  v5 = flag.m_finishing;
  v2 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, flag);
  v3 = &v2->m_motion.vfptr;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  v2->m_constraintsMaster.m_data = 0i64;
  *(_DWORD *)&v2->m_constraintsMaster.m_size = 2147483648;
  v2->m_constraintsSlave.m_data = 0i64;
  v2->m_constraintsSlave.m_size = 0;
  v2->m_constraintsSlave.m_capacityAndFlags = 2147483648;
  v2->m_constraintRuntime.m_data = 0i64;
  v2->m_constraintRuntime.m_size = 0;
  v2->m_constraintRuntime.m_capacityAndFlags = 2147483648;
  v2->m_motion.vfptr = (hkBaseObjectVtbl *)&hkpMotion::`vftable;
  if ( v5 )
    v2->m_motion.m_gravityFactor.m_value = 16256;
  *v3 = &hkpMaxSizeMotion::`vftable;
  v2->m_contactListeners.m_data = 0i64;
  *(_DWORD *)&v2->m_contactListeners.m_size = 2147483648;
  v2->m_actions.m_data = 0i64;
  *(_DWORD *)&v2->m_actions.m_size = 2147483648;
  if ( v5 )
  {
    switch ( v2->m_motion.m_type.m_storage )
    {
      case 2:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpSphereMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 3:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpBoxMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 4:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpKeyframedRigidMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 5:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpFixedRigidMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 6:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpThinBoxMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 7:
        if ( v2 != (hkpEntity *)-336i64 )
        {
          v4 = &hkpCharacterMotion::`vftable;
LABEL_17:
          *v3 = v4;
          v2->m_motion.m_gravityFactor.m_value = 16256;
        }
        break;
      default:
        return;
    }
  }
}

// File Line: 101
// RVA: 0xD61580
void __fastcall hkpEntity::setCachedShapeData(hkpEntity *this, hkpWorld *world, hkpShape *shape)
{
  hkpShape *v3; // rbx
  hkpWorld *v4; // rsi
  hkpEntity *v5; // rdi
  unsigned __int8 v6; // cl
  unsigned int v7; // edx
  char v8; // bp
  __int64 v9; // rax
  int v10; // eax

  v3 = shape;
  v4 = world;
  v5 = this;
  if ( this->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
    hkpCollidable::BoundingVolumeData::deallocate(&this->m_collidable.m_boundingVolumeData);
  if ( v4 )
  {
    if ( v3 )
    {
      v6 = v3->m_type.m_storage;
      if ( (unsigned __int8)(v6 - 16) > 1u )
      {
        v7 = v4->m_collisionDispatcher->m_hasAlternateType[v6];
        v8 = 0;
        if ( _bittest((const signed int *)&v7, 0x12u) )
        {
          v9 = ((__int64 (__fastcall *)(hkpShape *))v3->vfptr[7].__vecDelDtor)(v3);
        }
        else
        {
          if ( !_bittest((const signed int *)&v7, 0x16u) )
            return;
          v9 = ((__int64 (__fastcall *)(hkpShape *))v3->vfptr[7].__vecDelDtor)(v3);
          v8 = 1;
        }
        if ( (unsigned __int8)(v5->m_motion.m_type.m_storage - 4) > 1u || !v8 )
        {
          if ( v3->m_type.m_storage == 8 )
            v10 = v3[1].m_userData;
          else
            v10 = (*(__int64 (**)(void))(*(_QWORD *)v9 + 8i64))();
          hkpCollidable::BoundingVolumeData::allocate(&v5->m_collidable.m_boundingVolumeData, v10);
          v5->m_collidable.m_boundingVolumeData.m_min[0] = 1;
          v5->m_collidable.m_boundingVolumeData.m_max[0] = 0;
          if ( v5->m_motion.m_type.m_storage == 5 )
            hkpEntity::updateCachedAabb(v5);
        }
      }
    }
  }
}

// File Line: 194
// RVA: 0xD61670
void __fastcall hkpEntity::updateCachedAabb(hkpEntity *this)
{
  hkpWorld *v1; // rax
  hkpEntity *entityBatch; // [rsp+30h] [rbp+8h]

  v1 = this->m_world;
  if ( v1 )
  {
    if ( this->m_collidable.m_shape )
    {
      entityBatch = this;
      hkpEntityAabbUtil::entityBatchRecalcAabb(
        (hkpCollisionInput *)&v1->m_collisionInput->m_dispatcher,
        &entityBatch,
        1);
    }
  }
}

// File Line: 227
// RVA: 0xD60980
void __fastcall hkpEntity::~hkpEntity(hkpEntity *this)
{
  unsigned __int64 v1; // rbx
  hkpEntity *v2; // rdi
  unsigned __int64 v3; // rbx
  hkpEntity::ExtendedListeners *v4; // rbx
  _QWORD **v5; // rax
  hkReferencedObject *v6; // rcx
  unsigned __int16 v7; // si
  hkpAction **v8; // rbx
  _QWORD **v9; // rax
  unsigned __int16 v10; // si
  hkpContactListener **v11; // rbx
  _QWORD **v12; // rax
  int v13; // er8
  int v14; // er8
  unsigned __int16 v15; // si
  hkConstraintInternal *v16; // rbx
  _QWORD **v17; // rax

  v1 = (unsigned __int64)this->m_limitContactImpulseUtilAndFlag;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  v3 = v1 & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    hkpEntity::removeContactListener(this, (hkpContactListener *)(v3 + 16));
    (**(void (__fastcall ***)(unsigned __int64, signed __int64))v3)(v3, 1i64);
    v2->m_limitContactImpulseUtilAndFlag = 0i64;
  }
  hkpEntityCallbackUtil::fireEntityDeleted(v2);
  v4 = v2->m_extendedListeners;
  if ( v4 )
  {
    hkpEntity::ExtendedListeners::~ExtendedListeners(v2->m_extendedListeners);
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntity::ExtendedListeners *, signed __int64))(*v5[11] + 16i64))(
      v5[11],
      v4,
      32i64);
  }
  v6 = (hkReferencedObject *)&v2->m_localFrame.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v2->m_localFrame.m_pntr = 0i64;
  v7 = v2->m_actions.m_capacityAndFlags;
  if ( (v7 & 0x8000u) == 0 )
  {
    v8 = v2->m_actions.m_data;
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAction **, _QWORD))(*v9[11] + 16i64))(v9[11], v8, 8 * (v7 & 0x3FFFu));
  }
  v10 = v2->m_contactListeners.m_capacityAndFlags;
  if ( !(v10 & 0x8000) )
  {
    v11 = v2->m_contactListeners.m_data;
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpContactListener **, _QWORD))(*v12[11] + 16i64))(
      v12[11],
      v11,
      8 * (v10 & 0x3FFFu));
  }
  hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)&v2->m_motion.vfptr);
  v13 = v2->m_constraintRuntime.m_capacityAndFlags;
  v2->m_constraintRuntime.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_constraintRuntime.m_data,
      v13 & 0x3FFFFFFF);
  v2->m_constraintRuntime.m_data = 0i64;
  v2->m_constraintRuntime.m_capacityAndFlags = 2147483648;
  v14 = v2->m_constraintsSlave.m_capacityAndFlags;
  v2->m_constraintsSlave.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_constraintsSlave.m_data,
      8 * v14);
  v2->m_constraintsSlave.m_data = 0i64;
  v2->m_constraintsSlave.m_capacityAndFlags = 2147483648;
  v15 = v2->m_constraintsMaster.m_capacityAndFlags;
  if ( !(v15 & 0x8000) )
  {
    v16 = v2->m_constraintsMaster.m_data;
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkConstraintInternal *, _QWORD))(*v17[11] + 16i64))(
      v17[11],
      v16,
      (v15 & 0x3FFFu) << 6);
  }
  hkpWorldObject::~hkpWorldObject((hkpWorldObject *)&v2->vfptr);
}

// File Line: 260
// RVA: 0xD60BA0
void __fastcall hkpEntity::addEntityListener(hkpEntity *this, hkpEntityListener *el)
{
  int v2; // ebx
  hkpEntityListener *v3; // rsi
  hkpEntity *v4; // rdi
  _QWORD **v5; // rax
  __int64 v6; // rax
  hkpEntity::ExtendedListeners *v7; // rdi
  int v8; // ecx
  hkpEntityListener **v9; // rax

  v2 = 0;
  v3 = el;
  v4 = this;
  if ( !this->m_extendedListeners )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *(_DWORD *)(v6 + 8) = 2147483648;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_DWORD *)(v6 + 24) = 2147483648;
    }
    else
    {
      v6 = 0i64;
    }
    v4->m_extendedListeners = (hkpEntity::ExtendedListeners *)v6;
  }
  v7 = v4->m_extendedListeners;
  v8 = v7->m_entityListeners.m_size;
  if ( v8 <= 0 )
    goto LABEL_10;
  v9 = v7->m_entityListeners.m_data;
  while ( *v9 )
  {
    ++v2;
    ++v9;
    if ( v2 >= v8 )
      goto LABEL_10;
  }
  if ( v2 < 0 )
  {
LABEL_10:
    if ( (_WORD)v8 == (v7->m_entityListeners.m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(&v7->m_entityListeners, 8);
    v7->m_entityListeners.m_data[v7->m_entityListeners.m_size++] = v3;
  }
  else
  {
    v7->m_entityListeners.m_data[v2] = v3;
  }
}

// File Line: 281
// RVA: 0xD60C90
void __fastcall hkpEntity::removeEntityListener(hkpEntity *this, hkpEntityListener *el)
{
  hkpEntityListener *v2; // rdi
  hkpEntity *v3; // rbx
  _QWORD **v4; // rax
  __int64 v5; // rax
  hkpEntity::ExtendedListeners *v6; // r9
  signed int v7; // edx
  __int64 v8; // rcx
  __int64 v9; // r8
  hkpEntityListener **v10; // rax

  v2 = el;
  v3 = this;
  if ( !this->m_extendedListeners )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
    if ( v5 )
    {
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 8) = 2147483648;
      *(_QWORD *)(v5 + 16) = 0i64;
      *(_DWORD *)(v5 + 24) = 2147483648;
    }
    else
    {
      v5 = 0i64;
    }
    v3->m_extendedListeners = (hkpEntity::ExtendedListeners *)v5;
  }
  v6 = v3->m_extendedListeners;
  v7 = 0;
  v8 = 0i64;
  v9 = v6->m_entityListeners.m_size;
  if ( v9 <= 0 )
  {
LABEL_10:
    v7 = -1;
  }
  else
  {
    v10 = v6->m_entityListeners.m_data;
    while ( *v10 != v2 )
    {
      ++v8;
      ++v7;
      ++v10;
      if ( v8 >= v9 )
        goto LABEL_10;
    }
  }
  v6->m_entityListeners.m_data[v7] = 0i64;
}

// File Line: 294
// RVA: 0xD60D50
void __fastcall hkpEntity::addEntityActivationListener(hkpEntity *this, hkpEntityActivationListener *el)
{
  int v2; // ebx
  hkpEntityActivationListener *v3; // rsi
  hkpEntity *v4; // rdi
  _QWORD **v5; // rax
  __int64 v6; // rax
  hkpEntity::ExtendedListeners *v7; // rdi
  int v8; // ecx
  hkpEntityActivationListener **v9; // rax

  v2 = 0;
  v3 = el;
  v4 = this;
  if ( !this->m_extendedListeners )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *(_DWORD *)(v6 + 8) = 2147483648;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_DWORD *)(v6 + 24) = 2147483648;
    }
    else
    {
      v6 = 0i64;
    }
    v4->m_extendedListeners = (hkpEntity::ExtendedListeners *)v6;
  }
  v7 = v4->m_extendedListeners;
  v8 = v7->m_activationListeners.m_size;
  if ( v8 <= 0 )
    goto LABEL_10;
  v9 = v7->m_activationListeners.m_data;
  while ( *v9 )
  {
    ++v2;
    ++v9;
    if ( v2 >= v8 )
      goto LABEL_10;
  }
  if ( v2 < 0 )
  {
LABEL_10:
    if ( (_WORD)v8 == (v7->m_activationListeners.m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(v7, 8);
    v7->m_activationListeners.m_data[v7->m_activationListeners.m_size++] = v3;
  }
  else
  {
    v7->m_activationListeners.m_data[v2] = v3;
  }
}

// File Line: 316
// RVA: 0xD60E40
void __fastcall hkpEntity::removeEntityActivationListener(hkpEntity *this, hkpEntityActivationListener *el)
{
  hkpEntity::ExtendedListeners *v2; // r10
  signed int v3; // er8
  __int64 v4; // rcx
  __int64 v5; // r9
  hkpEntityActivationListener **v6; // rax

  v2 = this->m_extendedListeners;
  v3 = 0;
  v4 = 0i64;
  v5 = v2->m_activationListeners.m_size;
  if ( v5 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v6 = v2->m_activationListeners.m_data;
    while ( *v6 != el )
    {
      ++v4;
      ++v3;
      ++v6;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
  }
  v2->m_activationListeners.m_data[v3] = 0i64;
}

// File Line: 328
// RVA: 0xD60E90
void __fastcall hkpEntity::addContactListener(hkpEntity *this, hkpContactListener *cl)
{
  hkSmallArray<hkpContactListener *> *v2; // rbx
  int v3; // ecx
  hkpContactListener *v4; // rdi
  __int64 v5; // r9
  __int64 v6; // r8
  hkpContactListener **v7; // rax

  v2 = &this->m_contactListeners;
  v3 = 0;
  v4 = cl;
  v5 = v2->m_size;
  v6 = 0i64;
  if ( v5 <= 0 )
    goto LABEL_5;
  v7 = v2->m_data;
  while ( *v7 )
  {
    ++v6;
    ++v3;
    ++v7;
    if ( v6 >= v5 )
      goto LABEL_5;
  }
  if ( v3 < 0 )
  {
LABEL_5:
    if ( (_WORD)v5 == (v2->m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(v2, 8);
    v2->m_data[v2->m_size++] = v4;
  }
  else
  {
    v2->m_data[v3] = cl;
  }
}

// File Line: 346
// RVA: 0xD60F30
void __fastcall hkpEntity::removeContactListener(hkpEntity *this, hkpContactListener *cl)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpContactListener **v5; // rax

  v2 = this->m_contactListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_contactListeners.m_data;
    while ( *v5 != cl )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_contactListeners.m_data[v3] = 0i64;
}

// File Line: 357
// RVA: 0xD60F90
hkpContactMgr *__fastcall hkpEntity::findContactMgrTo(hkpEntity *this, hkpEntity *entity)
{
  __int64 v2; // r9
  __int64 v3; // r8
  hkpLinkedCollidable::CollisionEntry *v4; // rax
  hkpLinkedCollidable *v5; // rdx

  v2 = this->m_collidable.m_collisionEntries.m_size;
  v3 = 0i64;
  if ( v2 <= 0 )
    return 0i64;
  v4 = this->m_collidable.m_collisionEntries.m_data;
  v5 = &entity->m_collidable;
  while ( v4->m_partner != v5 )
  {
    ++v3;
    ++v4;
    if ( v3 >= v2 )
      return 0i64;
  }
  return v4->m_agentEntry->m_contactMgr;
}

// File Line: 377
// RVA: 0xD61DB0
hkBool *__fastcall hkpEntity_isActive(hkBool *result, hkpEntity *entity)
{
  hkpSimulationIsland *v2; // rax

  v2 = entity->m_simulationIsland;
  if ( v2 )
    result->m_bool = (*((_BYTE *)v2 + 50) >> 2) & 3;
  else
    result->m_bool = 0;
  return result;
}

// File Line: 389
// RVA: 0xD61300
hkBool *__fastcall hkpEntity::isActive(hkpEntity *this, hkBool *result)
{
  hkpSimulationIsland *v2; // rax

  v2 = this->m_simulationIsland;
  if ( v2 )
    result->m_bool = (*((_BYTE *)v2 + 50) >> 2) & 3;
  else
    result->m_bool = 0;
  return result;
}

// File Line: 394
// RVA: 0xD60FE0
void __fastcall hkpEntity::activate(hkpEntity *this)
{
  hkpSimulationIsland *v1; // rax
  hkpEntity *v2; // rbx
  unsigned __int8 *v3; // rax
  __int16 v4; // dx
  __int16 v5; // r8
  __int16 v6; // r8

  v1 = this->m_simulationIsland;
  v2 = this;
  if ( (!v1 || !((*((_BYTE *)v1 + 50) >> 2) & 3)) && this->m_motion.m_type.m_storage != 5 && this->m_world )
  {
    *(_DWORD *)this->m_motion.m_deactivationNumInactiveFrames = 0;
    hkpWorldOperationUtil::markIslandActive(this->m_world, this->m_simulationIsland);
    v3 = (unsigned __int8 *)v2->m_world;
    v4 = v3[1006];
    v5 = v3[1005];
    if ( (unsigned __int8)(v3[1007] & 3) < (unsigned __int8)(v2->m_motion.m_deactivationIntegrateCounter & 3) )
      v5 = ~v5;
    v6 = v5 << 14;
    if ( v3[1007] < (signed int)(unsigned __int8)v2->m_motion.m_deactivationIntegrateCounter )
      v4 = ~v4;
    v2->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    v2->m_motion.m_deactivationNumInactiveFrames[0] |= v6;
    v2->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    v2->m_motion.m_deactivationNumInactiveFrames[1] |= v4 << 14;
  }
}

// File Line: 417
// RVA: 0xD610B0
void __fastcall hkpEntity::requestDeactivation(hkpEntity *this)
{
  hkpSimulationIsland *v1; // rax

  v1 = this->m_simulationIsland;
  if ( v1 && (*((_BYTE *)v1 + 50) >> 2) & 3 && this->m_motion.m_deactivationIntegrateCounter != -1 )
    hkpMotion::requestDeactivation((hkpMotion *)&this->m_motion.vfptr);
}

// File Line: 432
// RVA: 0xD610F0
void __fastcall hkpEntity::deactivate(hkpEntity *this)
{
  hkpEntity *v1; // rdi
  hkpSimulationIsland *v2; // rcx
  char v3; // al
  int v4; // esi
  hkpWorld *v5; // rax
  unsigned int v6; // ebx
  hkpSimulationIsland *v7; // rax
  __int64 v8; // rdx
  __m128 *v9; // rcx

  v1 = this;
  v2 = this->m_simulationIsland;
  if ( v2 && (*((_BYTE *)v2 + 50) >> 2) & 3 )
  {
    v3 = *((_BYTE *)v2 + 49);
    v4 = 0;
    if ( v3 & 0xC || v3 & 3 )
    {
      v5 = v1->m_world;
      v6 = v5->m_minDesiredIslandSize;
      v5->m_minDesiredIslandSize = 0;
      *((_BYTE *)v1->m_simulationIsland + 49) &= 0xF3u;
      *((_BYTE *)v1->m_simulationIsland + 49) = *((_BYTE *)v1->m_simulationIsland + 49) & 0xFD | 1;
      hkpWorldOperationUtil::splitSimulationIsland(v1->m_world, v1->m_simulationIsland);
      v1->m_world->m_minDesiredIslandSize = v6;
    }
    v7 = v1->m_simulationIsland;
    if ( v7->m_entities.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        ++v4;
        ++v8;
        v9 = (__m128 *)v7->m_entities.m_data[v8 - 1];
        v9[37] = _mm_shuffle_ps(v9[37], _mm_unpackhi_ps(v9[37], (__m128)xmmword_141A712A0), 196);
        v9[38] = _mm_shuffle_ps(v9[38], _mm_unpackhi_ps(v9[38], (__m128)xmmword_141A712A0), 196);
        v7 = v1->m_simulationIsland;
      }
      while ( v4 < v7->m_entities.m_size );
    }
    hkpWorldOperationUtil::markIslandInactive(v1->m_world, v1->m_simulationIsland);
  }
}

// File Line: 469
// RVA: 0xD61210
void __fastcall hkpEntity::activateAsCriticalOperation(hkpEntity *this)
{
  hkpEntity *v1; // rax
  hkpWorld *v2; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this->m_world;
  if ( v2 && v2->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 34;
    v4 = v1;
    hkpWorld::queueOperation(v2, &operation);
  }
  else
  {
    hkpEntity::activate(v1);
  }
}

// File Line: 481
// RVA: 0xD61260
void __fastcall hkpEntity::requestDeactivationAsCriticalOperation(hkpEntity *this)
{
  hkpEntity *v1; // rax
  hkpWorld *v2; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this->m_world;
  if ( v2 && v2->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 35;
    v4 = v1;
    hkpWorld::queueOperation(v2, &operation);
  }
  else
  {
    hkpEntity::requestDeactivation(v1);
  }
}

// File Line: 494
// RVA: 0xD612B0
void __fastcall hkpEntity::deactivateAsCriticalOperation(hkpEntity *this)
{
  hkpEntity *v1; // rax
  hkpWorld *v2; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this->m_world;
  if ( v2 && v2->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 36;
    v4 = v1;
    hkpWorld::queueOperation(v2, &operation);
  }
  else
  {
    hkpEntity::deactivate(v1);
  }
}

// File Line: 507
// RVA: 0xD619B0
void __fastcall hkpEntity::deallocateInternalArrays(hkpEntity *this)
{
  hkpEntity *v1; // rsi
  unsigned __int64 v2; // rbx
  int v3; // er8
  unsigned __int16 v4; // di
  hkConstraintInternal *v5; // rbx
  _QWORD **v6; // rax
  int v7; // er8
  int v8; // er8
  int v9; // edx
  int v10; // ecx
  hkpContactListener **v11; // rax
  unsigned __int16 v12; // di
  hkpContactListener **v13; // rbx
  _QWORD **v14; // rax
  hkpEntity::ExtendedListeners *v15; // r14
  char v16; // di
  int v17; // edx
  int v18; // ecx
  hkpEntityActivationListener **v19; // rax
  unsigned __int16 v20; // bp
  hkpEntityActivationListener **v21; // rbx
  _QWORD **v22; // rax
  hkpEntity::ExtendedListeners *v23; // r14
  char v24; // bl
  int v25; // edx
  int v26; // ecx
  hkpEntityListener **v27; // rax
  unsigned __int16 v28; // r15
  hkpEntityListener **v29; // rbp
  _QWORD **v30; // rax
  hkpEntity::ExtendedListeners *v31; // rbx
  _QWORD **v32; // rax
  unsigned __int16 v33; // di
  hkpAction **v34; // rbx
  _QWORD **v35; // rax

  v1 = this;
  v2 = (_QWORD)this->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v2 )
  {
    hkpEntity::removeContactListener(this, (hkpContactListener *)(v2 + 16));
    (**(void (__fastcall ***)(unsigned __int64, signed __int64))v2)(v2, 1i64);
    v1->m_limitContactImpulseUtilAndFlag = 0i64;
  }
  if ( !v1->m_collidable.m_collisionEntries.m_size )
  {
    v3 = v1->m_collidable.m_collisionEntries.m_capacityAndFlags;
    v1->m_collidable.m_collisionEntries.m_size = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v1->m_collidable.m_collisionEntries.m_data,
        16 * v3);
    v1->m_collidable.m_collisionEntries.m_data = 0i64;
    v1->m_collidable.m_collisionEntries.m_capacityAndFlags = 2147483648;
  }
  if ( !v1->m_constraintsMaster.m_size )
  {
    v4 = v1->m_constraintsMaster.m_capacityAndFlags;
    if ( !(v4 & 0x8000) )
    {
      v5 = v1->m_constraintsMaster.m_data;
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkConstraintInternal *, _QWORD))(*v6[11] + 16i64))(
        v6[11],
        v5,
        (v4 & 0x3FFFu) << 6);
    }
    v1->m_constraintsMaster.m_capacityAndFlags &= 0xC000u;
    v1->m_constraintsMaster.m_capacityAndFlags |= 0x8000u;
    v1->m_constraintsMaster.m_data = 0i64;
    v1->m_constraintsMaster.m_size = 0;
  }
  if ( !v1->m_constraintsSlave.m_size )
  {
    v7 = v1->m_constraintsSlave.m_capacityAndFlags;
    v1->m_constraintsSlave.m_size = 0;
    if ( v7 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v1->m_constraintsSlave.m_data,
        8 * v7);
    v1->m_constraintsSlave.m_data = 0i64;
    v1->m_constraintsSlave.m_capacityAndFlags = 2147483648;
  }
  if ( !v1->m_constraintRuntime.m_size )
  {
    v8 = v1->m_constraintRuntime.m_capacityAndFlags;
    v1->m_constraintRuntime.m_size = 0;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v1->m_constraintRuntime.m_data,
        v8 & 0x3FFFFFFF);
    v1->m_constraintRuntime.m_data = 0i64;
    v1->m_constraintRuntime.m_capacityAndFlags = 2147483648;
  }
  v9 = v1->m_contactListeners.m_size;
  v10 = 0;
  if ( v9 <= 0 )
  {
LABEL_23:
    v12 = v1->m_contactListeners.m_capacityAndFlags;
    if ( !(v12 & 0x8000) )
    {
      v13 = v1->m_contactListeners.m_data;
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpContactListener **, _QWORD))(*v14[11] + 16i64))(
        v14[11],
        v13,
        8 * (v12 & 0x3FFFu));
    }
    v1->m_contactListeners.m_capacityAndFlags &= 0xC000u;
    v1->m_contactListeners.m_capacityAndFlags |= 0x8000u;
    v1->m_contactListeners.m_data = 0i64;
    v1->m_contactListeners.m_size = 0;
  }
  else
  {
    v11 = v1->m_contactListeners.m_data;
    while ( !*v11 )
    {
      ++v10;
      ++v11;
      if ( v10 >= v9 )
        goto LABEL_23;
    }
  }
  v15 = v1->m_extendedListeners;
  v16 = 0;
  if ( v15 )
  {
    v17 = v15->m_activationListeners.m_size;
    v18 = 0;
    if ( v17 <= 0 )
    {
LABEL_31:
      v20 = v15->m_activationListeners.m_capacityAndFlags;
      if ( !(v20 & 0x8000) )
      {
        v21 = v15->m_activationListeners.m_data;
        v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpEntityActivationListener **, _QWORD))(*v22[11] + 16i64))(
          v22[11],
          v21,
          8 * (v20 & 0x3FFFu));
      }
      v15->m_activationListeners.m_capacityAndFlags &= 0xC000u;
      v15->m_activationListeners.m_capacityAndFlags |= 0x8000u;
      v15->m_activationListeners.m_data = 0i64;
      v15->m_activationListeners.m_size = 0;
    }
    else
    {
      v19 = v15->m_activationListeners.m_data;
      while ( !*v19 )
      {
        ++v18;
        ++v19;
        if ( v18 >= v17 )
          goto LABEL_31;
      }
      v16 = 1;
    }
  }
  v23 = v1->m_extendedListeners;
  v24 = 0;
  if ( v23 )
  {
    v25 = v23->m_entityListeners.m_size;
    v26 = 0;
    if ( v25 <= 0 )
    {
LABEL_39:
      v28 = v23->m_entityListeners.m_capacityAndFlags;
      if ( !(v28 & 0x8000) )
      {
        v29 = v23->m_entityListeners.m_data;
        v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpEntityListener **, _QWORD))(*v30[11] + 16i64))(
          v30[11],
          v29,
          8 * (v28 & 0x3FFFu));
      }
      v23->m_entityListeners.m_data = 0i64;
      v23->m_entityListeners.m_size = 0;
      v23->m_entityListeners.m_capacityAndFlags &= 0xC000u;
      v23->m_entityListeners.m_capacityAndFlags |= 0x8000u;
    }
    else
    {
      v27 = v23->m_entityListeners.m_data;
      while ( !*v27 )
      {
        ++v26;
        ++v27;
        if ( v26 >= v25 )
          goto LABEL_39;
      }
      v24 = 1;
    }
  }
  if ( !v16 && !v24 )
  {
    v31 = v1->m_extendedListeners;
    if ( v31 )
    {
      hkpEntity::ExtendedListeners::~ExtendedListeners(v1->m_extendedListeners);
      v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpEntity::ExtendedListeners *, signed __int64))(*v32[11] + 16i64))(
        v32[11],
        v31,
        32i64);
    }
    v1->m_extendedListeners = 0i64;
  }
  if ( !v1->m_actions.m_size )
  {
    v33 = v1->m_actions.m_capacityAndFlags;
    if ( !(v33 & 0x8000) )
    {
      v34 = v1->m_actions.m_data;
      v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAction **, _QWORD))(*v35[11] + 16i64))(v35[11], v34, 8 * (v33 & 0x3FFFu));
    }
    v1->m_actions.m_capacityAndFlags &= 0xC000u;
    v1->m_actions.m_capacityAndFlags |= 0x8000u;
    v1->m_actions.m_data = 0i64;
    v1->m_actions.m_size = 0;
  }
}

// File Line: 672
// RVA: 0xD61330
__int64 __fastcall hkpEntity::getNumConstraints(hkpEntity *this)
{
  return this->m_constraintsSlave.m_size + (unsigned int)this->m_constraintsMaster.m_size;
}

// File Line: 678
// RVA: 0xD61350
hkpConstraintInstance *__fastcall hkpEntity::getConstraint(hkpEntity *this, int i)
{
  __int64 v2; // rax
  hkpConstraintInstance *result; // rax

  v2 = this->m_constraintsMaster.m_size;
  if ( i >= (signed int)v2 )
    result = this->m_constraintsSlave.m_data[i - v2];
  else
    result = this->m_constraintsMaster.m_data[(signed __int64)i].m_constraint;
  return result;
}

// File Line: 685
// RVA: 0xD61480
hkpConstraintInstance *__fastcall hkpEntity::getConstraint(hkpEntity *this, int i)
{
  __int64 v2; // rax
  hkpConstraintInstance *result; // rax

  v2 = this->m_constraintsMaster.m_size;
  if ( i >= (signed int)v2 )
    result = this->m_constraintsSlave.m_data[i - v2];
  else
    result = this->m_constraintsMaster.m_data[(signed __int64)i].m_constraint;
  return result;
}

// File Line: 692
// RVA: 0xD61390
void __fastcall hkpEntity::getAllConstraints(hkpEntity *this, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v2; // rdi
  hkpEntity *v3; // rbx
  int v4; // eax
  int v5; // esi
  int v6; // er8
  int v7; // er8
  int v8; // er9
  int v9; // er8
  int v10; // er11
  signed int v11; // er10
  __int64 v12; // rdx
  __int64 v13; // r9
  hkpConstraintInstance *v14; // rax
  __int64 v15; // r9
  signed __int64 v16; // rdx
  hkpConstraintInstance *v17; // rax
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = constraints;
  v3 = this;
  v4 = hkpEntity::getNumConstraints(this);
  v5 = v4;
  v6 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v4 )
  {
    v7 = 2 * v6;
    v8 = v4;
    if ( v4 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v8, 8);
  }
  v9 = 0;
  v2->m_size = v5;
  v10 = 0;
  v11 = 0;
  if ( v3->m_constraintsMaster.m_size > 0u )
  {
    v12 = 0i64;
    v13 = 0i64;
    do
    {
      ++v11;
      v14 = v3->m_constraintsMaster.m_data[v13].m_constraint;
      ++v10;
      ++v13;
      v2->m_data[v12] = v14;
      ++v12;
    }
    while ( v11 < v3->m_constraintsMaster.m_size );
  }
  if ( v3->m_constraintsSlave.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v15 * 8 + 8i64 * v10;
      v17 = v3->m_constraintsSlave.m_data[v15];
      ++v9;
      ++v15;
      *(hkpConstraintInstance **)((char *)v2->m_data + v16) = v17;
    }
    while ( v9 < v3->m_constraintsSlave.m_size );
  }
}

// File Line: 713
// RVA: 0xD616B0
hkSmallArray<hkConstraintInternal> *__fastcall hkpEntity::getConstraintMastersImpl(hkpEntity *this)
{
  return &this->m_constraintsMaster;
}

// File Line: 720
// RVA: 0xD616C0
hkSmallArray<hkConstraintInternal> *__fastcall hkpEntity::getConstraintMastersRwImpl(hkpEntity *this)
{
  return &this->m_constraintsMaster;
}

// File Line: 726
// RVA: 0xD616D0
hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *__fastcall hkpEntity::getConstraintSlavesImpl(hkpEntity *this)
{
  return &this->m_constraintsSlave;
}

// File Line: 758
// RVA: 0xD614C0
void __fastcall hkpEntity::sortConstraintsSlavesDeterministically(hkpEntity *this)
{
  hkpEntity *v1; // rbx
  int v2; // er8
  int i; // edx
  hkpConstraintInstance *v4; // r8
  __int64 v5; // rax
  __int64 v6; // r9
  hkpConstraintInstance **v7; // rcx

  v1 = this;
  if ( this->m_motion.m_type.m_storage == 5 )
  {
    v2 = this->m_constraintsSlave.m_size;
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkpConstraintInstance *,`anonymous namespace::cmpLessConstraint>(
        this->m_constraintsSlave.m_data,
        0,
        v2 - 1,
        (cmpLessConstraint)this);
    for ( i = 0; i < v1->m_constraintsSlave.m_size; ++i )
    {
      v4 = v1->m_constraintsSlave.m_data[i];
      v5 = 0i64;
      v6 = *(unsigned __int16 *)(((unsigned __int64)v1 ^ (_QWORD)v4->m_entities[0] ^ (_QWORD)v4->m_entities[1]) + 0x100);
      if ( v6 > 0 )
      {
        v7 = *(hkpConstraintInstance ***)(((unsigned __int64)v1 ^ (_QWORD)v4->m_entities[0] ^ (_QWORD)v4->m_entities[1])
                                        + 0xF8);
        while ( *v7 != v4 )
        {
          ++v5;
          v7 += 8;
          if ( v5 >= v6 )
            goto LABEL_11;
        }
        *(_WORD *)((v5 << 6)
                 + *(_QWORD *)(((unsigned __int64)v1 ^ (_QWORD)v4->m_entities[0] ^ (_QWORD)v4->m_entities[1]) + 0xF8)
                 + 58) = i;
      }
LABEL_11:
      ;
    }
  }
}

