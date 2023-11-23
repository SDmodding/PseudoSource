// File Line: 16
// RVA: 0xD63970
void __fastcall hkpUnaryAction::hkpUnaryAction(hkpUnaryAction *this, hkpEntity *entity, unsigned __int64 userData)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_userData = userData;
  this->m_world = 0i64;
  this->m_island = 0i64;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_entity = entity;
  this->vfptr = (hkBaseObjectVtbl *)&hkpUnaryAction::`vftable;
  if ( entity )
    hkReferencedObject::addReference(entity);
}

// File Line: 28
// RVA: 0xD63AA0
void __fastcall hkpUnaryAction::entityRemovedCallback(hkpUnaryAction *this, hkpEntity *entity)
{
  if ( this->m_world )
    hkpWorld::removeActionImmediately(this->m_world, this);
}

// File Line: 37
// RVA: 0xD639E0
void __fastcall hkpUnaryAction::~hkpUnaryAction(hkpUnaryAction *this)
{
  hkpEntity *m_entity; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpUnaryAction::`vftable;
  m_entity = this->m_entity;
  if ( m_entity )
  {
    hkReferencedObject::removeReference(m_entity);
    this->m_entity = 0i64;
  }
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  hkStringPtr::~hkStringPtr(&this->m_name);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 48
// RVA: 0xD63AC0
void __fastcall hkpUnaryAction::setEntity(hkpUnaryAction *this, hkpEntity *entity)
{
  hkpEntity *m_entity; // r8
  hkpWorld *m_world; // rcx
  hkpWorld *v6; // rcx

  m_entity = this->m_entity;
  if ( m_entity )
  {
    m_world = this->m_world;
    if ( m_world )
      hkpWorld::detachActionFromEntity(m_world, this, m_entity);
    hkReferencedObject::removeReference(this->m_entity);
    this->m_entity = 0i64;
  }
  this->m_entity = entity;
  hkReferencedObject::addReference(entity);
  v6 = this->m_world;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, this, this->m_entity);
}

// File Line: 72
// RVA: 0xD63A40
void __fastcall hkpUnaryAction::getEntities(
        hkpUnaryAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  if ( entitiesOut->m_size == (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&entitiesOut->m_data, 8);
  entitiesOut->m_data[entitiesOut->m_size++] = this->m_entity;
}

