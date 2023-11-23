// File Line: 49
// RVA: 0xD616E0
void __fastcall hkpEntity::hkpEntity(hkpEntity *this, hkpShape *shape)
{
  hkpWorldObject::hkpWorldObject(this, shape, 1);
  this->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  this->m_material.m_friction = 0.5;
  this->m_material.m_restitution = 0.40000001;
  this->m_material.m_rollingFrictionMultiplier.m_value = 0;
  this->m_constraintsMaster.m_data = 0i64;
  *(_DWORD *)&this->m_constraintsMaster.m_size = 0x80000000;
  this->m_constraintsSlave.m_data = 0i64;
  this->m_constraintsSlave.m_size = 0;
  this->m_constraintsSlave.m_capacityAndFlags = 0x80000000;
  this->m_constraintRuntime.m_data = 0i64;
  this->m_constraintRuntime.m_size = 0;
  this->m_constraintRuntime.m_capacityAndFlags = 0x80000000;
  this->m_spuCollisionCallback.m_util = 0i64;
  *(_DWORD *)&this->m_spuCollisionCallback.m_capacity = 16973824;
  hkpMotion::hkpMotion(&this->m_motion);
  this->m_motion.m_savedMotion = 0i64;
  this->m_motion.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
  this->m_contactListeners.m_data = 0i64;
  *(_DWORD *)&this->m_contactListeners.m_size = 0x80000000;
  this->m_actions.m_data = 0i64;
  *(_DWORD *)&this->m_actions.m_size = 0x80000000;
  this->m_localFrame.m_pntr = 0i64;
  this->m_simulationIsland = 0i64;
  this->m_extendedListeners = 0i64;
  this->m_limitContactImpulseUtilAndFlag = 0i64;
  this->m_solverData = 0;
  this->m_numShapeKeysInContactPointProperties = 0;
  this->m_storageIndex = -1;
  this->m_breakableBody = 0i64;
  this->m_uid = -1;
  this->m_damageMultiplier = 1.0;
  this->m_npData = -1;
}

// File Line: 69
// RVA: 0xD61840
void __fastcall hkpEntity::hkpEntity(hkpEntity *this, hkFinishLoadedObjectFlag flag)
{
  hkpMaxSizeMotion *p_m_motion; // rdx
  void **v4; // rax

  hkpWorldObject::hkpWorldObject(this, flag);
  p_m_motion = &this->m_motion;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  this->m_constraintsMaster.m_data = 0i64;
  *(_DWORD *)&this->m_constraintsMaster.m_size = 0x80000000;
  this->m_constraintsSlave.m_data = 0i64;
  this->m_constraintsSlave.m_size = 0;
  this->m_constraintsSlave.m_capacityAndFlags = 0x80000000;
  this->m_constraintRuntime.m_data = 0i64;
  this->m_constraintRuntime.m_size = 0;
  this->m_constraintRuntime.m_capacityAndFlags = 0x80000000;
  this->m_motion.vfptr = (hkBaseObjectVtbl *)&hkpMotion::`vftable;
  if ( flag.m_finishing )
    this->m_motion.m_gravityFactor.m_value = 16256;
  p_m_motion->vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
  this->m_contactListeners.m_data = 0i64;
  *(_DWORD *)&this->m_contactListeners.m_size = 0x80000000;
  this->m_actions.m_data = 0i64;
  *(_DWORD *)&this->m_actions.m_size = 0x80000000;
  if ( flag.m_finishing )
  {
    switch ( this->m_motion.m_type.m_storage )
    {
      case 2:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpSphereMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 3:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpBoxMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 4:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpKeyframedRigidMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 5:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpFixedRigidMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 6:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpThinBoxMotion::`vftable;
          goto LABEL_17;
        }
        break;
      case 7:
        if ( this != (hkpEntity *)-336i64 )
        {
          v4 = &hkpCharacterMotion::`vftable;
LABEL_17:
          p_m_motion->vfptr = (hkBaseObjectVtbl *)v4;
          this->m_motion.m_gravityFactor.m_value = 16256;
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
  unsigned __int8 m_storage; // cl
  unsigned int v7; // edx
  char v8; // bp
  __int64 v9; // rax
  int m_userData; // eax

  if ( this->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
    hkpCollidable::BoundingVolumeData::deallocate(&this->m_collidable.m_boundingVolumeData);
  if ( world )
  {
    if ( shape )
    {
      m_storage = shape->m_type.m_storage;
      if ( (unsigned __int8)(m_storage - 16) > 1u )
      {
        v7 = world->m_collisionDispatcher->m_hasAlternateType[m_storage];
        v8 = 0;
        if ( (v7 & 0x40000) != 0 )
        {
          v9 = ((__int64 (__fastcall *)(hkpShape *))shape->vfptr[7].__vecDelDtor)(shape);
        }
        else
        {
          if ( (v7 & 0x400000) == 0 )
            return;
          v9 = ((__int64 (__fastcall *)(hkpShape *))shape->vfptr[7].__vecDelDtor)(shape);
          v8 = 1;
        }
        if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) > 1u || !v8 )
        {
          if ( shape->m_type.m_storage == 8 )
            m_userData = shape[1].m_userData;
          else
            m_userData = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9);
          hkpCollidable::BoundingVolumeData::allocate(&this->m_collidable.m_boundingVolumeData, m_userData);
          this->m_collidable.m_boundingVolumeData.m_min[0] = 1;
          this->m_collidable.m_boundingVolumeData.m_max[0] = 0;
          if ( this->m_motion.m_type.m_storage == 5 )
            hkpEntity::updateCachedAabb(this);
        }
      }
    }
  }
}

// File Line: 194
// RVA: 0xD61670
void __fastcall hkpEntity::updateCachedAabb(hkpEntity *this)
{
  hkpWorld *m_world; // rax
  hkpEntity *entityBatch; // [rsp+30h] [rbp+8h] BYREF

  m_world = this->m_world;
  if ( m_world )
  {
    if ( this->m_collidable.m_shape )
    {
      entityBatch = this;
      hkpEntityAabbUtil::entityBatchRecalcAabb(m_world->m_collisionInput, &entityBatch, 1);
    }
  }
}

// File Line: 227
// RVA: 0xD60980
void __fastcall hkpEntity::~hkpEntity(hkpEntity *this)
{
  unsigned __int64 m_limitContactImpulseUtilAndFlag; // rbx
  unsigned __int64 v3; // rbx
  hkpEntity::ExtendedListeners *m_extendedListeners; // rbx
  _QWORD **Value; // rax
  hkLocalFrame *m_pntr; // rcx
  signed __int16 m_capacityAndFlags; // si
  hkpAction **m_data; // rbx
  _QWORD **v9; // rax
  unsigned __int16 v10; // si
  hkpContactListener **v11; // rbx
  _QWORD **v12; // rax
  int v13; // r8d
  int v14; // r8d
  unsigned __int16 v15; // si
  hkConstraintInternal *v16; // rbx
  _QWORD **v17; // rax

  m_limitContactImpulseUtilAndFlag = (unsigned __int64)this->m_limitContactImpulseUtilAndFlag;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEntity::`vftable;
  v3 = m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    hkpEntity::removeContactListener(this, (hkpContactListener *)(v3 + 16));
    (**(void (__fastcall ***)(unsigned __int64, __int64))v3)(v3, 1i64);
    this->m_limitContactImpulseUtilAndFlag = 0i64;
  }
  hkpEntityCallbackUtil::fireEntityDeleted(this);
  m_extendedListeners = this->m_extendedListeners;
  if ( m_extendedListeners )
  {
    hkpEntity::ExtendedListeners::~ExtendedListeners(this->m_extendedListeners);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntity::ExtendedListeners *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_extendedListeners,
      32i64);
  }
  m_pntr = this->m_localFrame.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_localFrame.m_pntr = 0i64;
  m_capacityAndFlags = this->m_actions.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
  {
    m_data = this->m_actions.m_data;
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAction **, _QWORD))(*v9[11] + 16i64))(
      v9[11],
      m_data,
      8 * (m_capacityAndFlags & 0x3FFFu));
  }
  v10 = this->m_contactListeners.m_capacityAndFlags;
  if ( (v10 & 0x8000) == 0 )
  {
    v11 = this->m_contactListeners.m_data;
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpContactListener **, _QWORD))(*v12[11] + 16i64))(
      v12[11],
      v11,
      8 * (v10 & 0x3FFFu));
  }
  hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion(&this->m_motion);
  v13 = this->m_constraintRuntime.m_capacityAndFlags;
  this->m_constraintRuntime.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_constraintRuntime.m_data,
      v13 & 0x3FFFFFFF);
  this->m_constraintRuntime.m_data = 0i64;
  this->m_constraintRuntime.m_capacityAndFlags = 0x80000000;
  v14 = this->m_constraintsSlave.m_capacityAndFlags;
  this->m_constraintsSlave.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_constraintsSlave.m_data,
      8 * v14);
  this->m_constraintsSlave.m_data = 0i64;
  this->m_constraintsSlave.m_capacityAndFlags = 0x80000000;
  v15 = this->m_constraintsMaster.m_capacityAndFlags;
  if ( (v15 & 0x8000) == 0 )
  {
    v16 = this->m_constraintsMaster.m_data;
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkConstraintInternal *, _QWORD))(*v17[11] + 16i64))(
      v17[11],
      v16,
      (unsigned __int16)(v15 & 0x3FFF) << 6);
  }
  hkpWorldObject::~hkpWorldObject(this);
}

// File Line: 260
// RVA: 0xD60BA0
void __fastcall hkpEntity::addEntityListener(hkpEntity *this, hkpEntityListener *el)
{
  int v2; // ebx
  _QWORD **Value; // rax
  __int64 v6; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int m_size; // ecx
  hkpEntityListener **m_data; // rax

  v2 = 0;
  if ( !this->m_extendedListeners )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *(_DWORD *)(v6 + 8) = 0x80000000;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_DWORD *)(v6 + 24) = 0x80000000;
    }
    else
    {
      v6 = 0i64;
    }
    this->m_extendedListeners = (hkpEntity::ExtendedListeners *)v6;
  }
  m_extendedListeners = this->m_extendedListeners;
  m_size = m_extendedListeners->m_entityListeners.m_size;
  if ( !m_extendedListeners->m_entityListeners.m_size )
    goto LABEL_10;
  m_data = m_extendedListeners->m_entityListeners.m_data;
  while ( *m_data )
  {
    ++v2;
    ++m_data;
    if ( v2 >= m_size )
      goto LABEL_10;
  }
  if ( v2 >= 0 )
  {
    m_extendedListeners->m_entityListeners.m_data[v2] = el;
  }
  else
  {
LABEL_10:
    if ( (_WORD)m_size == (m_extendedListeners->m_entityListeners.m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(&m_extendedListeners->m_entityListeners, 8);
    m_extendedListeners->m_entityListeners.m_data[m_extendedListeners->m_entityListeners.m_size++] = el;
  }
}

// File Line: 281
// RVA: 0xD60C90
void __fastcall hkpEntity::removeEntityListener(hkpEntity *this, hkpEntityListener *el)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // r9
  int v7; // edx
  __int64 v8; // rcx
  hkpEntityListener **m_data; // rax

  if ( !this->m_extendedListeners )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v5 )
    {
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 8) = 0x80000000;
      *(_QWORD *)(v5 + 16) = 0i64;
      *(_DWORD *)(v5 + 24) = 0x80000000;
    }
    else
    {
      v5 = 0i64;
    }
    this->m_extendedListeners = (hkpEntity::ExtendedListeners *)v5;
  }
  m_extendedListeners = this->m_extendedListeners;
  v7 = 0;
  v8 = 0i64;
  if ( m_extendedListeners->m_entityListeners.m_size )
  {
    m_data = m_extendedListeners->m_entityListeners.m_data;
    while ( *m_data != el )
    {
      ++v8;
      ++v7;
      ++m_data;
      if ( v8 >= m_extendedListeners->m_entityListeners.m_size )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v7 = -1;
  }
  m_extendedListeners->m_entityListeners.m_data[v7] = 0i64;
}

// File Line: 294
// RVA: 0xD60D50
void __fastcall hkpEntity::addEntityActivationListener(hkpEntity *this, hkpEntityActivationListener *el)
{
  int v2; // ebx
  _QWORD **Value; // rax
  __int64 v6; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // rdi
  int m_size; // ecx
  hkpEntityActivationListener **m_data; // rax

  v2 = 0;
  if ( !this->m_extendedListeners )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *(_DWORD *)(v6 + 8) = 0x80000000;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_DWORD *)(v6 + 24) = 0x80000000;
    }
    else
    {
      v6 = 0i64;
    }
    this->m_extendedListeners = (hkpEntity::ExtendedListeners *)v6;
  }
  m_extendedListeners = this->m_extendedListeners;
  m_size = m_extendedListeners->m_activationListeners.m_size;
  if ( !m_extendedListeners->m_activationListeners.m_size )
    goto LABEL_10;
  m_data = m_extendedListeners->m_activationListeners.m_data;
  while ( *m_data )
  {
    ++v2;
    ++m_data;
    if ( v2 >= m_size )
      goto LABEL_10;
  }
  if ( v2 >= 0 )
  {
    m_extendedListeners->m_activationListeners.m_data[v2] = el;
  }
  else
  {
LABEL_10:
    if ( (_WORD)m_size == (m_extendedListeners->m_activationListeners.m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(m_extendedListeners, 8);
    m_extendedListeners->m_activationListeners.m_data[m_extendedListeners->m_activationListeners.m_size++] = el;
  }
}

// File Line: 316
// RVA: 0xD60E40
void __fastcall hkpEntity::removeEntityActivationListener(hkpEntity *this, hkpEntityActivationListener *el)
{
  hkpEntity::ExtendedListeners *m_extendedListeners; // r10
  int v3; // r8d
  __int64 v4; // rcx
  hkpEntityActivationListener **m_data; // rax

  m_extendedListeners = this->m_extendedListeners;
  v3 = 0;
  v4 = 0i64;
  if ( m_extendedListeners->m_activationListeners.m_size )
  {
    m_data = m_extendedListeners->m_activationListeners.m_data;
    while ( *m_data != el )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_extendedListeners->m_activationListeners.m_size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = -1;
  }
  m_extendedListeners->m_activationListeners.m_data[v3] = 0i64;
}

// File Line: 328
// RVA: 0xD60E90
void __fastcall hkpEntity::addContactListener(hkpEntity *this, hkpContactListener *cl)
{
  hkSmallArray<hkpContactListener *> *p_m_contactListeners; // rbx
  int v3; // ecx
  __int64 m_size; // r9
  __int64 v6; // r8
  hkpContactListener **m_data; // rax

  p_m_contactListeners = &this->m_contactListeners;
  v3 = 0;
  m_size = p_m_contactListeners->m_size;
  v6 = 0i64;
  if ( !p_m_contactListeners->m_size )
    goto LABEL_5;
  m_data = p_m_contactListeners->m_data;
  while ( *m_data )
  {
    ++v6;
    ++v3;
    ++m_data;
    if ( v6 >= m_size )
      goto LABEL_5;
  }
  if ( v3 >= 0 )
  {
    p_m_contactListeners->m_data[v3] = cl;
  }
  else
  {
LABEL_5:
    if ( (_WORD)m_size == (p_m_contactListeners->m_capacityAndFlags & 0x3FFF) )
      hkSmallArrayUtil::_reserveMore(p_m_contactListeners, 8);
    p_m_contactListeners->m_data[p_m_contactListeners->m_size++] = cl;
  }
}

// File Line: 346
// RVA: 0xD60F30
void __fastcall hkpEntity::removeContactListener(hkpEntity *this, hkpContactListener *cl)
{
  int v2; // r9d
  __int64 v3; // r8
  hkpContactListener **m_data; // rax

  v2 = 0;
  v3 = 0i64;
  if ( this->m_contactListeners.m_size )
  {
    m_data = this->m_contactListeners.m_data;
    while ( *m_data != cl )
    {
      ++v3;
      ++v2;
      ++m_data;
      if ( v3 >= this->m_contactListeners.m_size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v2 = -1;
  }
  this->m_contactListeners.m_data[v2] = 0i64;
}

// File Line: 357
// RVA: 0xD60F90
hkpDynamicsContactMgr *__fastcall hkpEntity::findContactMgrTo(hkpEntity *this, hkpEntity *entity)
{
  __int64 m_size; // r9
  __int64 v3; // r8
  hkpLinkedCollidable::CollisionEntry *m_data; // rax
  hkpLinkedCollidable *p_m_collidable; // rdx

  m_size = this->m_collidable.m_collisionEntries.m_size;
  v3 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  m_data = this->m_collidable.m_collisionEntries.m_data;
  p_m_collidable = &entity->m_collidable;
  while ( m_data->m_partner != p_m_collidable )
  {
    ++v3;
    ++m_data;
    if ( v3 >= m_size )
      return 0i64;
  }
  return (hkpDynamicsContactMgr *)m_data->m_agentEntry->m_contactMgr;
}

// File Line: 377
// RVA: 0xD61DB0
hkBool *__fastcall hkpEntity_isActive(hkBool *result, hkpEntity *entity)
{
  hkpSimulationIsland *m_simulationIsland; // rax

  m_simulationIsland = entity->m_simulationIsland;
  if ( m_simulationIsland )
    result->m_bool = (*((_BYTE *)m_simulationIsland + 50) >> 2) & 3;
  else
    result->m_bool = 0;
  return result;
}

// File Line: 389
// RVA: 0xD61300
hkBool *__fastcall hkpEntity::isActive(hkpEntity *this, hkBool *result)
{
  hkpSimulationIsland *m_simulationIsland; // rax

  m_simulationIsland = this->m_simulationIsland;
  if ( m_simulationIsland )
    result->m_bool = (*((_BYTE *)m_simulationIsland + 50) >> 2) & 3;
  else
    result->m_bool = 0;
  return result;
}

// File Line: 394
// RVA: 0xD60FE0
void __fastcall hkpEntity::activate(hkpEntity *this)
{
  hkpSimulationIsland *m_simulationIsland; // rax
  hkpWorld *m_world; // rax
  __int16 v4; // dx
  __int16 v5; // r8
  __int16 v6; // r8

  m_simulationIsland = this->m_simulationIsland;
  if ( (!m_simulationIsland || ((*((_BYTE *)m_simulationIsland + 50) >> 2) & 3) == 0)
    && this->m_motion.m_type.m_storage != 5
    && this->m_world )
  {
    *(_DWORD *)this->m_motion.m_deactivationNumInactiveFrames = 0;
    hkpWorldOperationUtil::markIslandActive(this->m_world, this->m_simulationIsland);
    m_world = this->m_world;
    v4 = (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    v5 = (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
    if ( (unsigned __int8)(m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(this->m_motion.m_deactivationIntegrateCounter & 3) )
      v5 = ~v5;
    v6 = v5 << 14;
    if ( (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (int)(unsigned __int8)this->m_motion.m_deactivationIntegrateCounter )
      v4 = ~v4;
    this->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    this->m_motion.m_deactivationNumInactiveFrames[0] |= v6;
    this->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    this->m_motion.m_deactivationNumInactiveFrames[1] |= v4 << 14;
  }
}

// File Line: 417
// RVA: 0xD610B0
void __fastcall hkpEntity::requestDeactivation(hkpEntity *this)
{
  hkpSimulationIsland *m_simulationIsland; // rax

  m_simulationIsland = this->m_simulationIsland;
  if ( m_simulationIsland
    && ((*((_BYTE *)m_simulationIsland + 50) >> 2) & 3) != 0
    && this->m_motion.m_deactivationIntegrateCounter != -1 )
  {
    hkpMotion::requestDeactivation(&this->m_motion);
  }
}

// File Line: 432
// RVA: 0xD610F0
void __fastcall hkpEntity::deactivate(hkpEntity *this)
{
  hkpSimulationIsland *m_simulationIsland; // rcx
  char v3; // al
  int v4; // esi
  hkpWorld *m_world; // rax
  unsigned int m_minDesiredIslandSize; // ebx
  hkpSimulationIsland *v7; // rax
  __int64 v8; // rdx
  __m128 *v9; // rcx

  m_simulationIsland = this->m_simulationIsland;
  if ( m_simulationIsland && ((*((_BYTE *)m_simulationIsland + 50) >> 2) & 3) != 0 )
  {
    v3 = *((_BYTE *)m_simulationIsland + 49);
    v4 = 0;
    if ( (v3 & 0xC) != 0 || (v3 & 3) != 0 )
    {
      m_world = this->m_world;
      m_minDesiredIslandSize = m_world->m_minDesiredIslandSize;
      m_world->m_minDesiredIslandSize = 0;
      *((_BYTE *)this->m_simulationIsland + 49) &= 0xF3u;
      *((_BYTE *)this->m_simulationIsland + 49) = *((_BYTE *)this->m_simulationIsland + 49) & 0xFC | 1;
      hkpWorldOperationUtil::splitSimulationIsland(this->m_world, this->m_simulationIsland);
      this->m_world->m_minDesiredIslandSize = m_minDesiredIslandSize;
    }
    v7 = this->m_simulationIsland;
    if ( v7->m_entities.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        ++v4;
        v9 = (__m128 *)v7->m_entities.m_data[v8++];
        v9[37] = _mm_shuffle_ps(v9[37], _mm_unpackhi_ps(v9[37], (__m128)xmmword_141A712A0), 196);
        v9[38] = _mm_shuffle_ps(v9[38], _mm_unpackhi_ps(v9[38], (__m128)xmmword_141A712A0), 196);
        v7 = this->m_simulationIsland;
      }
      while ( v4 < v7->m_entities.m_size );
    }
    hkpWorldOperationUtil::markIslandInactive(this->m_world, this->m_simulationIsland);
  }
}

// File Line: 469
// RVA: 0xD61210
void __fastcall hkpEntity::activateAsCriticalOperation(hkpEntity *this)
{
  hkpWorld *m_world; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 34;
    v4 = this;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
  }
}

// File Line: 481
// RVA: 0xD61260
void __fastcall hkpEntity::requestDeactivationAsCriticalOperation(hkpEntity *this)
{
  hkpWorld *m_world; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 35;
    v4 = this;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::requestDeactivation(this);
  }
}

// File Line: 494
// RVA: 0xD612B0
void __fastcall hkpEntity::deactivateAsCriticalOperation(hkpEntity *this)
{
  hkpWorld *m_world; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpEntity *v4; // [rsp+28h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 36;
    v4 = this;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::deactivate(this);
  }
}

// File Line: 507
// RVA: 0xD619B0
void __fastcall hkpEntity::deallocateInternalArrays(hkpEntity *this)
{
  unsigned __int64 v2; // rbx
  int m_capacityAndFlags; // r8d
  unsigned __int16 v4; // di
  hkConstraintInternal *m_data; // rbx
  _QWORD **Value; // rax
  int v7; // r8d
  int v8; // r8d
  int v9; // ecx
  hkpContactListener **v10; // rax
  unsigned __int16 v11; // di
  hkpContactListener **v12; // rbx
  _QWORD **v13; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // r14
  char v15; // di
  int v16; // ecx
  hkpEntityActivationListener **v17; // rax
  unsigned __int16 v18; // bp
  hkpEntityActivationListener **v19; // rbx
  _QWORD **v20; // rax
  hkpEntity::ExtendedListeners *v21; // r14
  char v22; // bl
  int v23; // ecx
  hkpEntityListener **v24; // rax
  unsigned __int16 v25; // r15
  hkpEntityListener **v26; // rbp
  _QWORD **v27; // rax
  hkpEntity::ExtendedListeners *v28; // rbx
  _QWORD **v29; // rax
  unsigned __int16 v30; // di
  hkpAction **v31; // rbx
  _QWORD **v32; // rax

  v2 = (unsigned __int64)this->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v2 )
  {
    hkpEntity::removeContactListener(this, (hkpContactListener *)(v2 + 16));
    (**(void (__fastcall ***)(unsigned __int64, __int64))v2)(v2, 1i64);
    this->m_limitContactImpulseUtilAndFlag = 0i64;
  }
  if ( !this->m_collidable.m_collisionEntries.m_size )
  {
    m_capacityAndFlags = this->m_collidable.m_collisionEntries.m_capacityAndFlags;
    this->m_collidable.m_collisionEntries.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_collidable.m_collisionEntries.m_data,
        16 * m_capacityAndFlags);
    this->m_collidable.m_collisionEntries.m_data = 0i64;
    this->m_collidable.m_collisionEntries.m_capacityAndFlags = 0x80000000;
  }
  if ( !this->m_constraintsMaster.m_size )
  {
    v4 = this->m_constraintsMaster.m_capacityAndFlags;
    if ( (v4 & 0x8000) == 0 )
    {
      m_data = this->m_constraintsMaster.m_data;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkConstraintInternal *, _QWORD))(*Value[11] + 16i64))(
        Value[11],
        m_data,
        (unsigned __int16)(v4 & 0x3FFF) << 6);
    }
    this->m_constraintsMaster.m_capacityAndFlags &= 0xC000u;
    this->m_constraintsMaster.m_capacityAndFlags |= 0x8000u;
    this->m_constraintsMaster.m_data = 0i64;
    this->m_constraintsMaster.m_size = 0;
  }
  if ( !this->m_constraintsSlave.m_size )
  {
    v7 = this->m_constraintsSlave.m_capacityAndFlags;
    this->m_constraintsSlave.m_size = 0;
    if ( v7 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_constraintsSlave.m_data,
        8 * v7);
    this->m_constraintsSlave.m_data = 0i64;
    this->m_constraintsSlave.m_capacityAndFlags = 0x80000000;
  }
  if ( !this->m_constraintRuntime.m_size )
  {
    v8 = this->m_constraintRuntime.m_capacityAndFlags;
    this->m_constraintRuntime.m_size = 0;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_constraintRuntime.m_data,
        v8 & 0x3FFFFFFF);
    this->m_constraintRuntime.m_data = 0i64;
    this->m_constraintRuntime.m_capacityAndFlags = 0x80000000;
  }
  v9 = 0;
  if ( this->m_contactListeners.m_size )
  {
    v10 = this->m_contactListeners.m_data;
    while ( !*v10 )
    {
      ++v9;
      ++v10;
      if ( v9 >= this->m_contactListeners.m_size )
        goto LABEL_23;
    }
  }
  else
  {
LABEL_23:
    v11 = this->m_contactListeners.m_capacityAndFlags;
    if ( (v11 & 0x8000) == 0 )
    {
      v12 = this->m_contactListeners.m_data;
      v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpContactListener **, _QWORD))(*v13[11] + 16i64))(
        v13[11],
        v12,
        8 * (v11 & 0x3FFFu));
    }
    this->m_contactListeners.m_capacityAndFlags &= 0xC000u;
    this->m_contactListeners.m_capacityAndFlags |= 0x8000u;
    this->m_contactListeners.m_data = 0i64;
    this->m_contactListeners.m_size = 0;
  }
  m_extendedListeners = this->m_extendedListeners;
  v15 = 0;
  if ( m_extendedListeners )
  {
    v16 = 0;
    if ( m_extendedListeners->m_activationListeners.m_size )
    {
      v17 = m_extendedListeners->m_activationListeners.m_data;
      while ( !*v17 )
      {
        ++v16;
        ++v17;
        if ( v16 >= m_extendedListeners->m_activationListeners.m_size )
          goto LABEL_31;
      }
      v15 = 1;
    }
    else
    {
LABEL_31:
      v18 = m_extendedListeners->m_activationListeners.m_capacityAndFlags;
      if ( (v18 & 0x8000) == 0 )
      {
        v19 = m_extendedListeners->m_activationListeners.m_data;
        v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpEntityActivationListener **, _QWORD))(*v20[11] + 16i64))(
          v20[11],
          v19,
          8 * (v18 & 0x3FFFu));
      }
      m_extendedListeners->m_activationListeners.m_capacityAndFlags &= 0xC000u;
      m_extendedListeners->m_activationListeners.m_capacityAndFlags |= 0x8000u;
      m_extendedListeners->m_activationListeners.m_data = 0i64;
      m_extendedListeners->m_activationListeners.m_size = 0;
    }
  }
  v21 = this->m_extendedListeners;
  v22 = 0;
  if ( v21 )
  {
    v23 = 0;
    if ( v21->m_entityListeners.m_size )
    {
      v24 = v21->m_entityListeners.m_data;
      while ( !*v24 )
      {
        ++v23;
        ++v24;
        if ( v23 >= v21->m_entityListeners.m_size )
          goto LABEL_39;
      }
      v22 = 1;
    }
    else
    {
LABEL_39:
      v25 = v21->m_entityListeners.m_capacityAndFlags;
      if ( (v25 & 0x8000) == 0 )
      {
        v26 = v21->m_entityListeners.m_data;
        v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpEntityListener **, _QWORD))(*v27[11] + 16i64))(
          v27[11],
          v26,
          8 * (v25 & 0x3FFFu));
      }
      v21->m_entityListeners.m_data = 0i64;
      v21->m_entityListeners.m_size = 0;
      v21->m_entityListeners.m_capacityAndFlags &= 0xC000u;
      v21->m_entityListeners.m_capacityAndFlags |= 0x8000u;
    }
  }
  if ( !v15 && !v22 )
  {
    v28 = this->m_extendedListeners;
    if ( v28 )
    {
      hkpEntity::ExtendedListeners::~ExtendedListeners(this->m_extendedListeners);
      v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpEntity::ExtendedListeners *, __int64))(*v29[11] + 16i64))(
        v29[11],
        v28,
        32i64);
    }
    this->m_extendedListeners = 0i64;
  }
  if ( !this->m_actions.m_size )
  {
    v30 = this->m_actions.m_capacityAndFlags;
    if ( (v30 & 0x8000) == 0 )
    {
      v31 = this->m_actions.m_data;
      v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAction **, _QWORD))(*v32[11] + 16i64))(v32[11], v31, 8 * (v30 & 0x3FFFu));
    }
    this->m_actions.m_capacityAndFlags &= 0xC000u;
    this->m_actions.m_capacityAndFlags |= 0x8000u;
    this->m_actions.m_data = 0i64;
    this->m_actions.m_size = 0;
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
  __int64 m_size; // rax

  m_size = this->m_constraintsMaster.m_size;
  if ( i >= (int)m_size )
    return this->m_constraintsSlave.m_data[i - m_size];
  else
    return this->m_constraintsMaster.m_data[(__int64)i].m_constraint;
}

// File Line: 685
// RVA: 0xD61480
hkpConstraintInstance *__fastcall hkpEntity::getConstraint(hkpEntity *this, int i)
{
  __int64 m_size; // rax

  m_size = this->m_constraintsMaster.m_size;
  if ( i >= (int)m_size )
    return this->m_constraintsSlave.m_data[i - m_size];
  else
    return this->m_constraintsMaster.m_data[(__int64)i].m_constraint;
}

// File Line: 692
// RVA: 0xD61390
void __fastcall hkpEntity::getAllConstraints(
        hkpEntity *this,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  int NumConstraints; // eax
  int v5; // esi
  int v6; // r8d
  int v7; // r8d
  int v8; // r9d
  int v9; // r8d
  int v10; // r11d
  int v11; // r10d
  __int64 v12; // rdx
  __int64 v13; // r9
  hkpConstraintInstance *m_constraint; // rax
  __int64 v15; // r9
  __int64 v16; // rdx
  hkpConstraintInstance *v17; // rax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  NumConstraints = hkpEntity::getNumConstraints(this);
  v5 = NumConstraints;
  v6 = constraints->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < NumConstraints )
  {
    v7 = 2 * v6;
    v8 = NumConstraints;
    if ( NumConstraints < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&constraints->m_data, v8, 8);
  }
  v9 = 0;
  constraints->m_size = v5;
  v10 = 0;
  v11 = 0;
  if ( this->m_constraintsMaster.m_size )
  {
    v12 = 0i64;
    v13 = 0i64;
    do
    {
      ++v11;
      m_constraint = this->m_constraintsMaster.m_data[v13].m_constraint;
      ++v10;
      ++v13;
      constraints->m_data[v12++] = m_constraint;
    }
    while ( v11 < this->m_constraintsMaster.m_size );
  }
  if ( this->m_constraintsSlave.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v15 * 8 + 8i64 * v10;
      v17 = this->m_constraintsSlave.m_data[v15];
      ++v9;
      ++v15;
      *(hkpConstraintInstance **)((char *)constraints->m_data + v16) = v17;
    }
    while ( v9 < this->m_constraintsSlave.m_size );
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
hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *__fastcall hkpEntity::getConstraintSlavesImpl(
        hkpEntity *this)
{
  return &this->m_constraintsSlave;
}

// File Line: 758
// RVA: 0xD614C0
void __fastcall hkpEntity::sortConstraintsSlavesDeterministically(hkpEntity *this)
{
  int m_size; // r8d
  int i; // edx
  hkpConstraintInstance *v4; // r8
  __int64 v5; // rax
  hkpConstraintInstance **v6; // rcx

  if ( this->m_motion.m_type.m_storage == 5 )
  {
    m_size = this->m_constraintsSlave.m_size;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpConstraintInstance *,`anonymous namespace::cmpLessConstraint>(
        this->m_constraintsSlave.m_data,
        0,
        m_size - 1,
        (cmpLessConstraint)this);
    for ( i = 0; i < this->m_constraintsSlave.m_size; ++i )
    {
      v4 = this->m_constraintsSlave.m_data[i];
      v5 = 0i64;
      if ( *(_WORD *)(((unsigned __int64)this ^ (__int64)v4->m_entities[0] ^ (__int64)v4->m_entities[1]) + 0x100) )
      {
        v6 = *(hkpConstraintInstance ***)(((unsigned __int64)this ^ (__int64)v4->m_entities[0] ^ (__int64)v4->m_entities[1])
                                        + 0xF8);
        while ( *v6 != v4 )
        {
          ++v5;
          v6 += 8;
          if ( v5 >= *(unsigned __int16 *)(((unsigned __int64)this ^ (__int64)v4->m_entities[0] ^ (__int64)v4->m_entities[1])
                                         + 0x100) )
            goto LABEL_11;
        }
        *(_WORD *)((v5 << 6)
                 + *(_QWORD *)(((unsigned __int64)this ^ (__int64)v4->m_entities[0] ^ (__int64)v4->m_entities[1]) + 0xF8)
                 + 58) = i;
      }
LABEL_11:
      ;
    }
  }
}

