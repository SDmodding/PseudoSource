// File Line: 13
// RVA: 0xD0CFC0
void __fastcall hkpCollisionFilterList::hkpCollisionFilterList(
        hkpCollisionFilterList *this,
        hkArray<hkpCollisionFilter *,hkContainerHeapAllocator> *collisionFilters)
{
  int v4; // esi
  __int64 m_size; // rcx
  hkpCollisionFilter **m_data; // rax
  __int64 v7; // rdx
  char *v8; // r8
  hkpCollisionFilter *v9; // rcx
  __int64 v10; // rdi
  int v11; // [rsp+30h] [rbp+8h] BYREF

  hkpCollisionFilter::hkpCollisionFilter(this);
  v4 = 0;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayCollidableFilter};
  this->m_collisionFilters.m_data = 0i64;
  this->m_collisionFilters.m_size = 0;
  this->m_collisionFilters.m_capacityAndFlags = 0x80000000;
  this->m_type.m_storage = 3;
  if ( (this->m_collisionFilters.m_capacityAndFlags & 0x3FFFFFFF) < collisionFilters->m_size )
  {
    if ( this->m_collisionFilters.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        0i64,
        8 * this->m_collisionFilters.m_capacityAndFlags);
    v11 = 8 * collisionFilters->m_size;
    this->m_collisionFilters.m_data = (hkpCollisionFilter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                               &hkContainerHeapAllocator::s_alloc,
                                                               &v11);
    this->m_collisionFilters.m_capacityAndFlags = v11 / 8;
  }
  m_size = collisionFilters->m_size;
  m_data = this->m_collisionFilters.m_data;
  this->m_collisionFilters.m_size = m_size;
  v7 = m_size;
  if ( (int)m_size > 0 )
  {
    v8 = (char *)((char *)collisionFilters->m_data - (char *)m_data);
    do
    {
      v9 = *(hkpCollisionFilter **)((char *)m_data++ + (_QWORD)v8);
      *(m_data - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  if ( this->m_collisionFilters.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      hkReferencedObject::addReference(this->m_collisionFilters.m_data[v10]);
      ++v4;
      ++v10;
    }
    while ( v4 < this->m_collisionFilters.m_size );
  }
}

// File Line: 23
// RVA: 0xD0D110
void __fastcall hkpCollisionFilterList::~hkpCollisionFilterList(hkpCollisionFilterList *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayCollidableFilter};
  if ( this->m_collisionFilters.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_collisionFilters.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_collisionFilters.m_size );
  }
  m_capacityAndFlags = this->m_collisionFilters.m_capacityAndFlags;
  this->m_collisionFilters.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_collisionFilters.m_data,
      8 * m_capacityAndFlags);
  this->m_collisionFilters.m_data = 0i64;
  this->m_collisionFilters.m_capacityAndFlags = 0x80000000;
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 33
// RVA: 0xD0D2E0
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(
        hkpCollisionFilterList *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  signed int v6; // eax
  __int64 v9; // rbx
  __int64 v10; // rcx
  char v12; // [rsp+40h] [rbp+8h] BYREF

  v6 = this->m_postpad[1] - 1;
  v9 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    result->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v10 = *(_QWORD *)(*(_QWORD *)&this->m_type.m_storage + 8 * v9);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollidable *, hkpCollidable *))(*(_QWORD *)(v10 + 16) + 8i64))(
                        v10 + 16,
                        &v12,
                        a,
                        b) )
        break;
      if ( --v9 < 0 )
        goto LABEL_4;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 47
// RVA: 0xD0D360
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(
        hkpCollisionFilterList *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  signed int v9; // eax
  __int64 v12; // rbx
  unsigned int v13; // ebp
  hkpShapeContainer *v14; // r14
  hkpCdBody *v15; // r15
  __int64 v16; // rcx
  char v18; // [rsp+70h] [rbp+8h] BYREF

  v9 = this->m_type.m_storage - 1;
  v12 = v9;
  if ( v9 < 0 )
  {
LABEL_5:
    result->m_bool = 1;
  }
  else
  {
    v13 = bKey;
    v14 = bContainer;
    v15 = b;
    while ( 1 )
    {
      v16 = *(_QWORD *)(*(_QWORD *)this->m_prepad + 8 * v12);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, unsigned int))(*(_QWORD *)(v16 + 24) + 8i64))(
                        v16 + 24,
                        &v18,
                        input,
                        a,
                        v15,
                        v14,
                        v13) )
        break;
      if ( --v12 < 0 )
        goto LABEL_5;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 60
// RVA: 0xD0D500
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(
        hkpCollisionFilterList *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  signed int v7; // eax
  __int64 v10; // rbx
  unsigned int v11; // ebp
  __int64 v12; // rcx
  char v14; // [rsp+50h] [rbp+8h] BYREF

  v7 = this->m_prepad[0] - 1;
  v10 = v7;
  if ( v7 < 0 )
  {
LABEL_5:
    result->m_bool = 1;
  }
  else
  {
    v11 = bKey;
    while ( 1 )
    {
      v12 = *((_QWORD *)&this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr->__vecDelDtor + v10);
      if ( !*(_BYTE *)(**(__int64 (__fastcall ***)(__int64, char *, hkpShapeRayCastInput *, hkpShapeContainer *, unsigned int))(v12 + 32))(
                        v12 + 32,
                        &v14,
                        aInput,
                        bContainer,
                        v11) )
        break;
      if ( --v10 < 0 )
        goto LABEL_5;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 73
// RVA: 0xD0D420
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(
        hkpCollisionFilterList *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *collectionBodyA)
{
  signed int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rcx
  char v10; // [rsp+90h] [rbp+8h] BYREF
  hkpCollisionInput *v11; // [rsp+A0h] [rbp+18h]
  hkpCdBody *v12; // [rsp+A8h] [rbp+20h]

  v12 = collectionBodyA;
  v11 = input;
  v6 = this->m_type.m_storage - 1;
  v7 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    result->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v8 = *(_QWORD *)(*(_QWORD *)this->m_prepad + 8 * v7);
      if ( !*(_BYTE *)(**(__int64 (__fastcall ***)(__int64, char *))(v8 + 24))(v8 + 24, &v10) )
        break;
      if ( --v7 < 0 )
        goto LABEL_4;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 87
// RVA: 0xD0D5A0
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(
        hkpCollisionFilterList *this,
        hkBool *result,
        hkpWorldRayCastInput *a,
        hkpCollidable *collidableB)
{
  int v6; // eax
  __int64 v9; // rbx
  __int64 v10; // rcx
  char v12; // [rsp+40h] [rbp+8h] BYREF

  v6 = LODWORD(this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr) - 1;
  v9 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    result->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v10 = *((_QWORD *)&this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr->isCollisionEnabled + v9);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpWorldRayCastInput *, hkpCollidable *))(*(_QWORD *)(v10 + 40) + 8i64))(
                        v10 + 40,
                        &v12,
                        a,
                        collidableB) )
        break;
      if ( --v9 < 0 )
        goto LABEL_4;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 101
// RVA: 0xD0CF50
void __fastcall hkpCollisionFilterList::hkpCollisionFilterList(hkpCollisionFilterList *this)
{
  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable{for `hkpRayCollidableFilter};
  this->m_collisionFilters.m_capacityAndFlags = 0x80000000;
  this->m_collisionFilters.m_data = 0i64;
  this->m_collisionFilters.m_size = 0;
}

// File Line: 105
// RVA: 0xD0D220
void __fastcall hkpCollisionFilterList::addCollisionFilter(hkpCollisionFilterList *this, hkpCollisionFilter *filter)
{
  hkReferencedObject::addReference(filter);
  if ( this->m_collisionFilters.m_size == (this->m_collisionFilters.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_collisionFilters.m_data, 8);
  this->m_collisionFilters.m_data[this->m_collisionFilters.m_size++] = filter;
}

// File Line: 111
// RVA: 0xD0D280
void __fastcall hkpCollisionFilterList::removeCollisionFilter(hkpCollisionFilterList *this, hkpCollisionFilter *filter)
{
  __int64 m_size; // r11
  int v3; // r9d
  __int64 v4; // r8
  hkpCollisionFilter **m_data; // rax

  m_size = this->m_collisionFilters.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_collisionFilters.m_data;
    while ( *m_data != filter )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_collisionFilters.m_size = m_size - 1;
  if ( (_DWORD)m_size - 1 != v3 )
    this->m_collisionFilters.m_data[v3] = this->m_collisionFilters.m_data[(int)m_size - 1];
  hkReferencedObject::removeReference(filter);
}

// File Line: 120
// RVA: 0xD0D210
hkArray<hkpCollisionFilter *,hkContainerHeapAllocator> *__fastcall hkpCollisionFilterList::getCollisionFilters(
        hkpCollisionFilterList *this)
{
  return &this->m_collisionFilters;
}

// File Line: 125
// RVA: 0xD0D620
void __fastcall hkpCollisionFilterList::init(hkpCollisionFilterList *this, hkpWorld *world)
{
  int v2; // ebx
  __int64 v5; // rdi

  v2 = 0;
  if ( this->m_collisionFilters.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))this->m_collisionFilters.m_data[v5]->hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__)(
        this->m_collisionFilters.m_data[v5],
        world);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_collisionFilters.m_size );
  }
}

