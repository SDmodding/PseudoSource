// File Line: 13
// RVA: 0xD0CFC0
void __fastcall hkpCollisionFilterList::hkpCollisionFilterList(hkpCollisionFilterList *this, hkArray<hkpCollisionFilter *,hkContainerHeapAllocator> *collisionFilters)
{
  hkArray<hkpCollisionFilter *,hkContainerHeapAllocator> *v2; // rdi
  hkpCollisionFilterList *v3; // rbx
  int v4; // esi
  __int64 v5; // rcx
  hkpCollisionFilter **v6; // rax
  __int64 v7; // rdx
  char *v8; // r8
  hkpCollisionFilter *v9; // rcx
  __int64 v10; // rdi
  int v11; // [rsp+30h] [rbp+8h]

  v2 = collisionFilters;
  v3 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v4 = 0;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable'{for `hkReferencedObject'};
  v3->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpCollidableCollidableFilter'};
  v3->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpShapeCollectionFilter'};
  v3->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayShapeCollectionFilter'};
  v3->vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayCollidableFilter'};
  v3->m_collisionFilters.m_data = 0i64;
  v3->m_collisionFilters.m_size = 0;
  v3->m_collisionFilters.m_capacityAndFlags = 2147483648;
  v3->m_type.m_storage = 3;
  if ( (v3->m_collisionFilters.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_size )
  {
    if ( v3->m_collisionFilters.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        8 * v3->m_collisionFilters.m_capacityAndFlags);
    v11 = 8 * v2->m_size;
    v3->m_collisionFilters.m_data = (hkpCollisionFilter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                             &v11);
    v3->m_collisionFilters.m_capacityAndFlags = v11 / 8;
  }
  v5 = v2->m_size;
  v6 = v3->m_collisionFilters.m_data;
  v3->m_collisionFilters.m_size = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (char *)((char *)v2->m_data - (char *)v6);
    do
    {
      v9 = *(hkpCollisionFilter **)((char *)v6 + (_QWORD)v8);
      ++v6;
      *(v6 - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  if ( v3->m_collisionFilters.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v3->m_collisionFilters.m_data[v10]->vfptr);
      ++v4;
      ++v10;
    }
    while ( v4 < v3->m_collisionFilters.m_size );
  }
}

// File Line: 23
// RVA: 0xD0D110
void __fastcall hkpCollisionFilterList::~hkpCollisionFilterList(hkpCollisionFilterList *this)
{
  int v1; // esi
  hkpCollisionFilterList *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable'{for `hkReferencedObject'};
  v2 = this;
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpCollidableCollidableFilter'};
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpShapeCollectionFilter'};
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayShapeCollectionFilter'};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayCollidableFilter'};
  if ( this->m_collisionFilters.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_collisionFilters.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_collisionFilters.m_size );
  }
  v4 = v2->m_collisionFilters.m_capacityAndFlags;
  v2->m_collisionFilters.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_collisionFilters.m_data,
      8 * v4);
  v2->m_collisionFilters.m_data = 0i64;
  v2->m_collisionFilters.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable';
  v2->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable';
  v2->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable';
  v2->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable';
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 33
// RVA: 0xD0D2E0
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(hkpCollisionFilterList *this, hkBool *result, hkpCollidable *a, hkpCollidable *b)
{
  hkpCollidable *v4; // rbp
  hkpCollidable *v5; // r14
  signed int v6; // eax
  unsigned __int128 v7; // di
  __int64 v8; // rbx
  __int64 v9; // rcx
  char v11; // [rsp+40h] [rbp+8h]

  v4 = b;
  v5 = a;
  v6 = this->m_postpad[1] - 1;
  v7 = __PAIR__((unsigned __int64)this, (unsigned __int64)result);
  v8 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    *(_BYTE *)v7 = 1;
  }
  else
  {
    while ( 1 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&v7 + 1) + 56i64) + 8 * v8);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollidable *, hkpCollidable *))(*(_QWORD *)(v9 + 16) + 8i64))(
                        v9 + 16,
                        &v11,
                        v5,
                        v4) )
        break;
      if ( --v8 < 0 )
        goto LABEL_4;
    }
    *(_BYTE *)v7 = 0;
  }
  return (hkBool *)v7;
}

// File Line: 47
// RVA: 0xD0D360
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(hkpCollisionFilterList *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a, hkpCdBody *b, hkpShapeContainer *bContainer, unsigned int bKey)
{
  hkpCdBody *v7; // r12
  hkpCollisionInput *v8; // r13
  signed int v9; // eax
  unsigned __int128 v10; // di
  __int64 v11; // rbx
  unsigned int v12; // ebp
  hkpShapeContainer *v13; // r14
  hkpCdBody *v14; // r15
  __int64 v15; // rcx
  _QWORD v17[2]; // [rsp+30h] [rbp-38h]
  char v18; // [rsp+70h] [rbp+8h]

  v7 = a;
  v8 = input;
  v9 = this->m_type.m_storage - 1;
  v10 = __PAIR__((unsigned __int64)this, (unsigned __int64)result);
  v11 = v9;
  if ( v9 < 0 )
  {
LABEL_5:
    *(_BYTE *)v10 = 1;
  }
  else
  {
    v12 = bKey;
    v13 = bContainer;
    v14 = b;
    while ( 1 )
    {
      LODWORD(v17[0]) = v12;
      v15 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&v10 + 1) + 48i64) + 8 * v11);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, _QWORD))(*(_QWORD *)(v15 + 24) + 8i64))(
                        v15 + 24,
                        &v18,
                        v8,
                        v7,
                        v14,
                        v13,
                        v17[0]) )
        break;
      if ( --v11 < 0 )
        goto LABEL_5;
    }
    *(_BYTE *)v10 = 0;
  }
  return (hkBool *)v10;
}

// File Line: 60
// RVA: 0xD0D500
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(hkpCollisionFilterList *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *bContainer, unsigned int bKey)
{
  hkpShapeContainer *v5; // r14
  hkpShapeRayCastInput *v6; // r15
  signed int v7; // eax
  unsigned __int128 v8; // di
  __int64 v9; // rbx
  unsigned int v10; // ebp
  __int64 v11; // rcx
  _QWORD v13[5]; // [rsp+20h] [rbp-28h]
  char v14; // [rsp+50h] [rbp+8h]

  v5 = bContainer;
  v6 = aInput;
  v7 = this->m_prepad[0] - 1;
  v8 = __PAIR__((unsigned __int64)this, (unsigned __int64)result);
  v9 = v7;
  if ( v7 < 0 )
  {
LABEL_5:
    *(_BYTE *)v8 = 1;
  }
  else
  {
    v10 = bKey;
    while ( 1 )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&v8 + 1) + 40i64) + 8 * v9);
      LODWORD(v13[0]) = v10;
      if ( !*(_BYTE *)(**(__int64 (__fastcall ***)(signed __int64, char *, hkpShapeRayCastInput *, hkpShapeContainer *, _QWORD))(v11 + 32))(
                        v11 + 32,
                        &v14,
                        v6,
                        v5,
                        v13[0]) )
        break;
      if ( --v9 < 0 )
        goto LABEL_5;
    }
    *(_BYTE *)v8 = 0;
  }
  return (hkBool *)v8;
}

// File Line: 73
// RVA: 0xD0D420
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(hkpCollisionFilterList *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *collectionBodyA)
{
  hkBool *v4; // rdi
  hkpCollisionFilterList *v5; // rsi
  signed int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rcx
  char v10; // [rsp+90h] [rbp+8h]
  hkpCollisionInput *v11; // [rsp+A0h] [rbp+18h]
  hkpCdBody *v12; // [rsp+A8h] [rbp+20h]

  v12 = collectionBodyA;
  v11 = input;
  v4 = result;
  v5 = this;
  v6 = this->m_type.m_storage - 1;
  v7 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    v4->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v8 = *(_QWORD *)(*(_QWORD *)v5->m_prepad + 8 * v7);
      if ( !*(_BYTE *)(**(__int64 (__fastcall ***)(signed __int64, char *))(v8 + 24))(v8 + 24, &v10) )
        break;
      if ( --v7 < 0 )
        goto LABEL_4;
    }
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 87
// RVA: 0xD0D5A0
hkBool *__fastcall hkpCollisionFilterList::isCollisionEnabled(hkpCollisionFilterList *this, hkBool *result, hkpWorldRayCastInput *a, hkpCollidable *collidableB)
{
  hkpCollidable *v4; // rbp
  hkpWorldRayCastInput *v5; // r14
  int v6; // eax
  unsigned __int128 v7; // di
  __int64 v8; // rbx
  __int64 v9; // rcx
  char v11; // [rsp+40h] [rbp+8h]

  v4 = collidableB;
  v5 = a;
  v6 = LODWORD(this->vfptr) - 1;
  v7 = __PAIR__((unsigned __int64)this, (unsigned __int64)result);
  v8 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    *(_BYTE *)v7 = 1;
  }
  else
  {
    while ( 1 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&v7 + 1) + 32i64) + 8 * v8);
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpWorldRayCastInput *, hkpCollidable *))(*(_QWORD *)(v9 + 40) + 8i64))(
                        v9 + 40,
                        &v11,
                        v5,
                        v4) )
        break;
      if ( --v8 < 0 )
        goto LABEL_4;
    }
    *(_BYTE *)v7 = 0;
  }
  return (hkBool *)v7;
}

// File Line: 101
// RVA: 0xD0CF50
void __fastcall hkpCollisionFilterList::hkpCollisionFilterList(hkpCollisionFilterList *this)
{
  hkpCollisionFilterList *v1; // rbx

  v1 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkpCollisionFilterList::`vftable'{for `hkReferencedObject'};
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpCollidableCollidableFilter'};
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpShapeCollectionFilter'};
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayShapeCollectionFilter'};
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&hkpCollisionFilterList::`vftable'{for `hkpRayCollidableFilter'};
  v1->m_collisionFilters.m_capacityAndFlags = 2147483648;
  v1->m_collisionFilters.m_data = 0i64;
  v1->m_collisionFilters.m_size = 0;
}

// File Line: 105
// RVA: 0xD0D220
void __fastcall hkpCollisionFilterList::addCollisionFilter(hkpCollisionFilterList *this, hkpCollisionFilter *filter)
{
  hkpCollisionFilterList *v2; // rbx
  hkpCollisionFilter *v3; // rdi

  v2 = this;
  v3 = filter;
  hkReferencedObject::addReference((hkReferencedObject *)&filter->vfptr);
  if ( v2->m_collisionFilters.m_size == (v2->m_collisionFilters.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_collisionFilters, 8);
  v2->m_collisionFilters.m_data[v2->m_collisionFilters.m_size++] = v3;
}

// File Line: 111
// RVA: 0xD0D280
void __fastcall hkpCollisionFilterList::removeCollisionFilter(hkpCollisionFilterList *this, hkpCollisionFilter *filter)
{
  __int64 v2; // r11
  signed int v3; // er9
  __int64 v4; // r8
  hkpCollisionFilter **v5; // rax

  v2 = this->m_collisionFilters.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_collisionFilters.m_data;
    while ( *v5 != filter )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_collisionFilters.m_size = v2 - 1;
  if ( (_DWORD)v2 - 1 != v3 )
    this->m_collisionFilters.m_data[v3] = this->m_collisionFilters.m_data[(signed int)v2 - 1];
  hkReferencedObject::removeReference((hkReferencedObject *)&filter->vfptr);
}

// File Line: 120
// RVA: 0xD0D210
hkArray<hkpCollisionFilter *,hkContainerHeapAllocator> *__fastcall hkpCollisionFilterList::getCollisionFilters(hkpCollisionFilterList *this)
{
  return &this->m_collisionFilters;
}

// File Line: 125
// RVA: 0xD0D620
void __fastcall hkpCollisionFilterList::init(hkpCollisionFilterList *this, hkpWorld *world)
{
  int v2; // ebx
  hkpWorld *v3; // rbp
  hkpCollisionFilterList *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = world;
  v4 = this;
  if ( this->m_collisionFilters.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))v4->m_collisionFilters.m_data[v5]->vfptr[1].__first_virtual_table_function__)(
        v4->m_collisionFilters.m_data[v5],
        v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_collisionFilters.m_size );
  }
}

