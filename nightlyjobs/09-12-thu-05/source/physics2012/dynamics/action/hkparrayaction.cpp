// File Line: 15
// RVA: 0x132E650
void __fastcall hkpArrayAction::hkpArrayAction(hkpArrayAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, unsigned __int64 userData)
{
  hkpArrayAction *v3; // rbx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v4; // rdi
  int v5; // eax
  __int64 v6; // rcx
  hkpEntity **v7; // rax
  __int64 v8; // rdx
  char *v9; // r8
  hkpEntity *v10; // rcx
  int v11; // [rsp+30h] [rbp+8h]

  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = userData;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  this->m_world = 0i64;
  this->m_island = 0i64;
  v4 = entities;
  hkStringPtr::hkStringPtr(&this->m_name);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpArrayAction::`vftable;
  v3->m_entities.m_data = 0i64;
  v3->m_entities.m_size = 0;
  v3->m_entities.m_capacityAndFlags = 2147483648;
  v5 = v4->m_size;
  if ( v5 > 0 )
  {
    v11 = 8 * v5;
    v3->m_entities.m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v11);
    v3->m_entities.m_capacityAndFlags = v11 / 8;
  }
  v6 = v4->m_size;
  v7 = v3->m_entities.m_data;
  v3->m_entities.m_size = v6;
  v8 = v6;
  if ( (signed int)v6 > 0 )
  {
    v9 = (char *)((char *)v4->m_data - (char *)v7);
    do
    {
      v10 = *(hkpEntity **)((char *)v7 + (_QWORD)v9);
      ++v7;
      *(v7 - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  hkpArrayAction::_referenceBodies(v3);
}

// File Line: 23
// RVA: 0x132E930
void __fastcall hkpArrayAction::~hkpArrayAction(hkpArrayAction *this)
{
  int v1; // esi
  hkpArrayAction *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpArrayAction::`vftable;
  v2 = this;
  if ( this->m_entities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_entities.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_entities.m_size );
  }
  v4 = v2->m_entities.m_capacityAndFlags;
  v2->m_entities.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_entities.m_data,
      8 * v4);
  v2->m_entities.m_data = 0i64;
  v2->m_entities.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpAction::`vftable;
  hkStringPtr::~hkStringPtr(&v2->m_name);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 33
// RVA: 0x132E9F0
void __fastcall hkpArrayAction::_referenceBodies(hkpArrayAction *this)
{
  int v1; // ebx
  hkpArrayAction *v2; // rsi
  __int64 v3; // rdi

  v1 = 0;
  v2 = this;
  if ( this->m_entities.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v2->m_entities.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_entities.m_size );
  }
}

// File Line: 42
// RVA: 0x132E740
void __fastcall hkpArrayAction::addEntity(hkpArrayAction *this, hkpEntity *entity)
{
  hkpEntity *v2; // rsi
  hkpArrayAction *v3; // rdi
  hkpWorld *v4; // rcx

  v2 = entity;
  v3 = this;
  if ( this->m_entities.m_size == (this->m_entities.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_entities, 8);
  v3->m_entities.m_data[v3->m_entities.m_size++] = v2;
  hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v4 = v3->m_world;
  if ( v4 )
    hkpWorld::attachActionToEntity(v4, (hkpAction *)&v3->vfptr, v2);
}

// File Line: 53
// RVA: 0x132E850
void __fastcall hkpArrayAction::getEntities(hkpArrayAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v2; // rbx
  hkpArrayAction *v3; // rdi
  __int64 v4; // rcx
  hkpEntity **v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkpEntity *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h]

  v2 = entitiesOut;
  v3 = this;
  if ( (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) < this->m_entities.m_size )
  {
    if ( entitiesOut->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entitiesOut->m_data,
        8 * entitiesOut->m_capacityAndFlags);
    v9 = 8 * v3->m_entities.m_size;
    v2->m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                 &v9);
    v2->m_capacityAndFlags = v9 / 8;
  }
  v4 = v3->m_entities.m_size;
  v5 = v2->m_data;
  v2->m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v3->m_entities.m_data - (char *)v5);
    do
    {
      v8 = *(hkpEntity **)((char *)v5 + (_QWORD)v7);
      ++v5;
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 59
// RVA: 0x132E7C0
void __fastcall hkpArrayAction::removeEntity(hkpArrayAction *this, hkpEntity *entity)
{
  hkpArrayAction *v2; // rdi
  hkpWorld *v3; // rcx
  hkpEntity *v4; // rbx
  __int64 v5; // r9
  signed int v6; // er8
  __int64 v7; // rcx
  hkpEntity **v8; // rax

  v2 = this;
  v3 = this->m_world;
  v4 = entity;
  if ( v3 )
    hkpWorld::detachActionFromEntity(v3, (hkpAction *)&v2->vfptr, entity);
  v5 = v2->m_entities.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( (signed int)v5 <= 0 )
  {
LABEL_7:
    v6 = -1;
  }
  else
  {
    v8 = v2->m_entities.m_data;
    while ( *v8 != v4 )
    {
      ++v7;
      ++v6;
      ++v8;
      if ( v7 >= v5 )
        goto LABEL_7;
    }
  }
  v2->m_entities.m_size = v5 - 1;
  if ( (_DWORD)v5 - 1 != v6 )
    v2->m_entities.m_data[v6] = v2->m_entities.m_data[(signed int)v5 - 1];
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
}

// File Line: 76
// RVA: 0x132E910
void __fastcall hkpArrayAction::entityRemovedCallback(hkpArrayAction *this, hkpEntity *entity)
{
  hkpWorld::removeActionImmediately(this->m_world, (hkpAction *)&this->vfptr);
}

