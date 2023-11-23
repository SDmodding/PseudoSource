// File Line: 18
// RVA: 0x132E0C0
void __fastcall hkpBinaryAction::hkpBinaryAction(
        hkpBinaryAction *this,
        hkpEntity *entityA,
        hkpEntity *entityB,
        unsigned __int64 userData)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_userData = userData;
  this->m_world = 0i64;
  this->m_island = 0i64;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_entityA = entityA;
  this->m_entityB = entityB;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBinaryAction::`vftable;
  if ( entityB || entityA )
    hkpBinaryAction::_referenceBodies(this);
}

// File Line: 25
// RVA: 0x132E2D0
void __fastcall hkpBinaryAction::_referenceBodies(hkpBinaryAction *this)
{
  hkpEntity *m_entityA; // rcx
  hkpEntity *m_entityB; // rcx

  m_entityA = this->m_entityA;
  if ( m_entityA )
    hkReferencedObject::addReference(m_entityA);
  m_entityB = this->m_entityB;
  if ( m_entityB )
    hkReferencedObject::addReference(m_entityB);
}

// File Line: 48
// RVA: 0x132E1D0
void __fastcall hkpBinaryAction::entityRemovedCallback(hkpBinaryAction *this, hkpEntity *entity)
{
  if ( this->m_world )
    hkpWorld::removeActionImmediately(this->m_world, this);
}

// File Line: 57
// RVA: 0x132E140
void __fastcall hkpBinaryAction::getEntities(
        hkpBinaryAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  int m_capacityAndFlags; // eax

  if ( entitiesOut->m_size == (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&entitiesOut->m_data, 8);
  entitiesOut->m_data[entitiesOut->m_size] = this->m_entityA;
  m_capacityAndFlags = entitiesOut->m_capacityAndFlags;
  if ( ++entitiesOut->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&entitiesOut->m_data, 8);
  entitiesOut->m_data[entitiesOut->m_size++] = this->m_entityB;
}

// File Line: 63
// RVA: 0x132E1F0
void __fastcall hkpBinaryAction::setEntityA(hkpBinaryAction *this, hkpEntity *entityA)
{
  hkpEntity *m_entityA; // r8
  hkpWorld *m_world; // rcx
  hkpWorld *v6; // rcx

  hkReferencedObject::addReference(entityA);
  m_entityA = this->m_entityA;
  if ( m_entityA )
  {
    m_world = this->m_world;
    if ( m_world )
      hkpWorld::detachActionFromEntity(m_world, this, m_entityA);
    hkReferencedObject::removeReference(this->m_entityA);
    this->m_entityA = 0i64;
  }
  v6 = this->m_world;
  this->m_entityA = entityA;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, this, entityA);
}

// File Line: 95
// RVA: 0x132E260
void __fastcall hkpBinaryAction::setEntityB(hkpBinaryAction *this, hkpEntity *entityB)
{
  hkpEntity *m_entityB; // r8
  hkpWorld *m_world; // rcx
  hkpWorld *v6; // rcx

  hkReferencedObject::addReference(entityB);
  m_entityB = this->m_entityB;
  if ( m_entityB )
  {
    m_world = this->m_world;
    if ( m_world )
      hkpWorld::detachActionFromEntity(m_world, this, m_entityB);
    hkReferencedObject::removeReference(this->m_entityB);
    this->m_entityB = 0i64;
  }
  v6 = this->m_world;
  this->m_entityB = entityB;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, this, entityB);
}

