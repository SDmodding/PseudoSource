// File Line: 18
// RVA: 0x132E0C0
void __fastcall hkpBinaryAction::hkpBinaryAction(hkpBinaryAction *this, hkpEntity *entityA, hkpEntity *entityB, unsigned __int64 userData)
{
  hkpBinaryAction *v4; // rdi
  hkpEntity *v5; // rbx
  hkpEntity *v6; // rsi

  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_userData = userData;
  this->m_world = 0i64;
  this->m_island = 0i64;
  v5 = entityB;
  v6 = entityA;
  hkStringPtr::hkStringPtr(&this->m_name);
  v4->m_entityA = v6;
  v4->m_entityB = v5;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpBinaryAction::`vftable;
  if ( v5 || v6 )
    hkpBinaryAction::_referenceBodies(v4);
}

// File Line: 25
// RVA: 0x132E2D0
void __fastcall hkpBinaryAction::_referenceBodies(hkpBinaryAction *this)
{
  hkpBinaryAction *v1; // rbx
  hkpEntity *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  v2 = this->m_entityA;
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v3 = (hkReferencedObject *)&v1->m_entityB->vfptr;
  if ( v3 )
    hkReferencedObject::addReference(v3);
}

// File Line: 48
// RVA: 0x132E1D0
void __fastcall hkpBinaryAction::entityRemovedCallback(hkpBinaryAction *this, hkpEntity *entity)
{
  if ( this->m_world )
    hkpWorld::removeActionImmediately(this->m_world, (hkpAction *)&this->vfptr);
}

// File Line: 57
// RVA: 0x132E140
void __fastcall hkpBinaryAction::getEntities(hkpBinaryAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v2; // rbx
  hkpBinaryAction *v3; // rdi
  int v4; // eax

  v2 = entitiesOut;
  v3 = this;
  if ( entitiesOut->m_size == (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, entitiesOut, 8);
  v2->m_data[v2->m_size] = v3->m_entityA;
  v4 = v2->m_capacityAndFlags;
  if ( ++v2->m_size == (v4 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3->m_entityB;
}

// File Line: 63
// RVA: 0x132E1F0
void __fastcall hkpBinaryAction::setEntityA(hkpBinaryAction *this, hkpEntity *entityA)
{
  hkpBinaryAction *v2; // rbx
  hkpEntity *v3; // rdi
  hkpEntity *v4; // r8
  hkpWorld *v5; // rcx
  hkpWorld *v6; // rcx

  v2 = this;
  v3 = entityA;
  hkReferencedObject::addReference((hkReferencedObject *)&entityA->vfptr);
  v4 = v2->m_entityA;
  if ( v4 )
  {
    v5 = v2->m_world;
    if ( v5 )
      hkpWorld::detachActionFromEntity(v5, (hkpAction *)&v2->vfptr, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_entityA->vfptr);
    v2->m_entityA = 0i64;
  }
  v6 = v2->m_world;
  v2->m_entityA = v3;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, (hkpAction *)&v2->vfptr, v3);
}

// File Line: 95
// RVA: 0x132E260
void __fastcall hkpBinaryAction::setEntityB(hkpBinaryAction *this, hkpEntity *entityB)
{
  hkpBinaryAction *v2; // rbx
  hkpEntity *v3; // rdi
  hkpEntity *v4; // r8
  hkpWorld *v5; // rcx
  hkpWorld *v6; // rcx

  v2 = this;
  v3 = entityB;
  hkReferencedObject::addReference((hkReferencedObject *)&entityB->vfptr);
  v4 = v2->m_entityB;
  if ( v4 )
  {
    v5 = v2->m_world;
    if ( v5 )
      hkpWorld::detachActionFromEntity(v5, (hkpAction *)&v2->vfptr, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_entityB->vfptr);
    v2->m_entityB = 0i64;
  }
  v6 = v2->m_world;
  v2->m_entityB = v3;
  if ( v6 )
    hkpWorld::attachActionToEntity(v6, (hkpAction *)&v2->vfptr, v3);
}

