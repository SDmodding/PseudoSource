// File Line: 15
// RVA: 0x132E650
void __fastcall hkpArrayAction::hkpArrayAction(
        hkpArrayAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        unsigned __int64 userData)
{
  int m_size; // eax
  __int64 v6; // rcx
  hkpEntity **m_data; // rax
  __int64 v8; // rdx
  char *v9; // r8
  hkpEntity *v10; // rcx
  int v11; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = userData;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_world = 0i64;
  this->m_island = 0i64;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->vfptr = (hkBaseObjectVtbl *)&hkpArrayAction::`vftable;
  this->m_entities.m_data = 0i64;
  this->m_entities.m_size = 0;
  this->m_entities.m_capacityAndFlags = 0x80000000;
  m_size = entities->m_size;
  if ( m_size > 0 )
  {
    v11 = 8 * m_size;
    this->m_entities.m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v11);
    this->m_entities.m_capacityAndFlags = v11 / 8;
  }
  v6 = entities->m_size;
  m_data = this->m_entities.m_data;
  this->m_entities.m_size = v6;
  v8 = v6;
  if ( (int)v6 > 0 )
  {
    v9 = (char *)((char *)entities->m_data - (char *)m_data);
    do
    {
      v10 = *(hkpEntity **)((char *)m_data++ + (_QWORD)v9);
      *(m_data - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  hkpArrayAction::_referenceBodies(this);
}

// File Line: 23
// RVA: 0x132E930
void __fastcall hkpArrayAction::~hkpArrayAction(hkpArrayAction *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpArrayAction::`vftable;
  if ( this->m_entities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_entities.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_entities.m_size );
  }
  m_capacityAndFlags = this->m_entities.m_capacityAndFlags;
  this->m_entities.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_entities.m_data,
      8 * m_capacityAndFlags);
  this->m_entities.m_data = 0i64;
  this->m_entities.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  hkStringPtr::~hkStringPtr(&this->m_name);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 33
// RVA: 0x132E9F0
void __fastcall hkpArrayAction::_referenceBodies(hkpArrayAction *this)
{
  int v1; // ebx
  __int64 v3; // rdi

  v1 = 0;
  if ( this->m_entities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::addReference(this->m_entities.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_entities.m_size );
  }
}

// File Line: 42
// RVA: 0x132E740
void __fastcall hkpArrayAction::addEntity(hkpArrayAction *this, hkpEntity *entity)
{
  hkpWorld *m_world; // rcx

  if ( this->m_entities.m_size == (this->m_entities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_entities.m_data, 8);
  this->m_entities.m_data[this->m_entities.m_size++] = entity;
  hkReferencedObject::addReference(entity);
  m_world = this->m_world;
  if ( m_world )
    hkpWorld::attachActionToEntity(m_world, this, entity);
}

// File Line: 53
// RVA: 0x132E850
void __fastcall hkpArrayAction::getEntities(
        hkpArrayAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  __int64 m_size; // rcx
  hkpEntity **m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkpEntity *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h] BYREF

  if ( (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) < this->m_entities.m_size )
  {
    if ( entitiesOut->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entitiesOut->m_data,
        8 * entitiesOut->m_capacityAndFlags);
    v9 = 8 * this->m_entities.m_size;
    entitiesOut->m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &v9);
    entitiesOut->m_capacityAndFlags = v9 / 8;
  }
  m_size = this->m_entities.m_size;
  m_data = entitiesOut->m_data;
  entitiesOut->m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)this->m_entities.m_data - (char *)m_data);
    do
    {
      v8 = *(hkpEntity **)((char *)m_data++ + (_QWORD)v7);
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 59
// RVA: 0x132E7C0
void __fastcall hkpArrayAction::removeEntity(hkpArrayAction *this, hkpEntity *entity)
{
  hkpWorld *m_world; // rcx
  __int64 m_size; // r9
  int v6; // r8d
  __int64 v7; // rcx
  hkpEntity **m_data; // rax

  m_world = this->m_world;
  if ( m_world )
    hkpWorld::detachActionFromEntity(m_world, this, entity);
  m_size = this->m_entities.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_7:
    v6 = -1;
  }
  else
  {
    m_data = this->m_entities.m_data;
    while ( *m_data != entity )
    {
      ++v7;
      ++v6;
      ++m_data;
      if ( v7 >= m_size )
        goto LABEL_7;
    }
  }
  this->m_entities.m_size = m_size - 1;
  if ( (_DWORD)m_size - 1 != v6 )
    this->m_entities.m_data[v6] = this->m_entities.m_data[(int)m_size - 1];
  hkReferencedObject::removeReference(entity);
}

// File Line: 76
// RVA: 0x132E910
void __fastcall hkpArrayAction::entityRemovedCallback(hkpArrayAction *this, hkpEntity *entity)
{
  hkpWorld::removeActionImmediately(this->m_world, this);
}

