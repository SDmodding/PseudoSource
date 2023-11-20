// File Line: 16
// RVA: 0xD63970
void __fastcall hkpUnaryAction::hkpUnaryAction(hkpUnaryAction *this, hkpEntity *entity, unsigned __int64 userData)
{
  hkpUnaryAction *v3; // rbx
  hkpEntity *v4; // rdi

  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_userData = userData;
  this->m_world = 0i64;
  this->m_island = 0i64;
  v4 = entity;
  hkStringPtr::hkStringPtr(&this->m_name);
  v3->m_entity = v4;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpUnaryAction::`vftable;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
}

// File Line: 28
// RVA: 0xD63AA0
void __fastcall hkpUnaryAction::entityRemovedCallback(hkpUnaryAction *this, hkpEntity *entity)
{
  if ( this->m_world )
    hkpWorld::removeActionImmediately(this->m_world, (hkpAction *)&this->vfptr);
}

// File Line: 37
// RVA: 0xD639E0
void __fastcall hkpUnaryAction::~hkpUnaryAction(hkpUnaryAction *this)
{
  hkpUnaryAction *v1; // rbx
  hkpEntity *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpUnaryAction::`vftable;
  v2 = this->m_entity;
  if ( v2 )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
    v1->m_entity = 0i64;
  }
  v1->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 48
// RVA: 0xD63AC0
void __fastcall hkpUnaryAction::setEntity(hkpUnaryAction *this, hkpEntity *entity)
{
  hkpEntity *v2; // r8
  hkpEntity *v3; // rdi
  hkpUnaryAction *v4; // rbx
  hkpWorld *v5; // rcx
  hkpWorld *v6; // rcx

  v2 = this->m_entity;
  v3 = entity;
  v4 = this;
  if ( v2 )
  {
    v5 = this->m_world;
    if ( v5 )
      hkpWorld::detachActionFromEntity(v5, (hkpAction *)&v4->vfptr, v2);
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->m_entity->vfptr);
    v4->m_entity = 0i64;
  }
  v4->m_entity = v3;
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v6 = v4->m_world;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, (hkpAction *)&v4->vfptr, v4->m_entity);
}

// File Line: 72
// RVA: 0xD63A40
void __fastcall hkpUnaryAction::getEntities(hkpUnaryAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v2; // rbx
  hkpUnaryAction *v3; // rdi

  v2 = entitiesOut;
  v3 = this;
  if ( entitiesOut->m_size == (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, entitiesOut, 8);
  v2->m_data[v2->m_size++] = v3->m_entity;
}

