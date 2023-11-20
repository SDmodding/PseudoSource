// File Line: 15
// RVA: 0xE15160
void __fastcall hkpDisableEntityCollisionFilter::hkpDisableEntityCollisionFilter(hkpDisableEntityCollisionFilter *this)
{
  hkpDisableEntityCollisionFilter *v1; // rbx

  v1 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkReferencedObject};
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpDisableEntityCollisionFilter::`vftable;
  v1->m_disabledEntities.m_capacityAndFlags = 2147483648;
  v1->m_disabledEntities.m_data = 0i64;
  v1->m_disabledEntities.m_size = 0;
}

// File Line: 20
// RVA: 0xE151D0
void __fastcall hkpDisableEntityCollisionFilter::~hkpDisableEntityCollisionFilter(hkpDisableEntityCollisionFilter *this)
{
  hkpEntityListener *v1; // rsi
  hkpDisableEntityCollisionFilter *v2; // rbx
  int v3; // ebp
  __int64 v4; // r14
  hkpEntity *v5; // rdi
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkpEntity::ExtendedListeners *v8; // rax
  int v9; // edx
  __int64 v10; // rcx
  __int64 v11; // r8
  hkpEntityListener **v12; // rax
  int v13; // er8

  v1 = (hkpEntityListener *)&this->vfptr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v2 = this;
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v3 = 0;
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpDisableEntityCollisionFilter::`vftable;
  if ( this->m_disabledEntities.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->m_disabledEntities.m_data[v4];
      if ( !v5->m_extendedListeners )
      {
        v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 32i64);
        if ( v7 )
        {
          *(_QWORD *)v7 = 0i64;
          *(_DWORD *)(v7 + 8) = 2147483648;
          *(_QWORD *)(v7 + 16) = 0i64;
          *(_DWORD *)(v7 + 24) = 2147483648;
        }
        else
        {
          v7 = 0i64;
        }
        v5->m_extendedListeners = (hkpEntity::ExtendedListeners *)v7;
      }
      v8 = v5->m_extendedListeners;
      v9 = 0;
      v10 = 0i64;
      v11 = v8->m_entityListeners.m_size;
      if ( v11 > 0 )
      {
        v12 = v8->m_entityListeners.m_data;
        while ( *v12 != v1 )
        {
          ++v10;
          ++v9;
          ++v12;
          if ( v10 >= v11 )
            goto LABEL_15;
        }
        if ( v9 >= 0 )
          hkpEntity::removeEntityListener(v2->m_disabledEntities.m_data[v4], v1);
      }
LABEL_15:
      ++v3;
      ++v4;
    }
    while ( v3 < v2->m_disabledEntities.m_size );
  }
  v13 = v2->m_disabledEntities.m_capacityAndFlags;
  v2->m_disabledEntities.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_disabledEntities.m_data,
      8 * v13);
  v2->m_disabledEntities.m_data = 0i64;
  v2->m_disabledEntities.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  v2->vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  v2->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  v2->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  v2->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 33
// RVA: 0xE155E0
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpCollidable *a, hkpCollidable *b)
{
  __int64 v4; // r11
  __int64 v5; // r10
  _QWORD *v6; // rcx
  hkpCollidable *v7; // rax
  hkBool *v8; // rax

  v4 = SLODWORD(this->vfptr);
  v5 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_6:
    result->m_bool = 1;
    v8 = result;
  }
  else
  {
    v6 = *(_QWORD **)&this->m_postpad[1];
    while ( 1 )
    {
      v7 = (hkpCollidable *)(*v6 + 32i64);
      if ( v7 == a || v7 == b )
        break;
      ++v5;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_6;
    }
    result->m_bool = 0;
    v8 = result;
  }
  return v8;
}

// File Line: 47
// RVA: 0xE15630
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a)
{
  result->m_bool = 1;
  return result;
}

// File Line: 52
// RVA: 0xE15650
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *bContainer)
{
  result->m_bool = 1;
  return result;
}

// File Line: 57
// RVA: 0xE15640
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *collectionBodyA)
{
  result->m_bool = 1;
  return result;
}

// File Line: 63
// RVA: 0xE15660
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpWorldRayCastInput *a, hkpCollidable *collidableB)
{
  result->m_bool = 1;
  return result;
}

// File Line: 69
// RVA: 0xE153A0
hkBool *__fastcall hkpDisableEntityCollisionFilter::addEntityToFilter(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpEntity *new_entity)
{
  hkpEntity *v3; // rdi
  hkBool *v4; // rsi
  hkpDisableEntityCollisionFilter *v5; // rbp
  hkBool *v6; // rax
  __int64 v7; // rdx
  int v8; // ebx
  __int64 v9; // rcx
  hkpEntity **v10; // rax
  hkpEntityListener *v11; // rbp
  _QWORD **v12; // rax
  __int64 v13; // rax
  hkpEntity::ExtendedListeners *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  hkpEntityListener **v17; // rax

  v3 = new_entity;
  v4 = result;
  v5 = this;
  if ( new_entity )
  {
    v7 = this->m_disabledEntities.m_size;
    v8 = 0;
    v9 = 0i64;
    if ( v7 <= 0 )
    {
LABEL_7:
      if ( v5->m_disabledEntities.m_size == (v5->m_disabledEntities.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v5->m_disabledEntities,
          8);
      v5->m_disabledEntities.m_data[v5->m_disabledEntities.m_size++] = v3;
      v11 = (hkpEntityListener *)&v5->vfptr;
      if ( !v3->m_extendedListeners )
      {
        v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 32i64);
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *(_DWORD *)(v13 + 8) = 2147483648;
          *(_QWORD *)(v13 + 16) = 0i64;
          *(_DWORD *)(v13 + 24) = 2147483648;
        }
        else
        {
          v13 = 0i64;
        }
        v3->m_extendedListeners = (hkpEntity::ExtendedListeners *)v13;
      }
      v14 = v3->m_extendedListeners;
      v15 = 0i64;
      v16 = v14->m_entityListeners.m_size;
      if ( v16 <= 0 )
        goto LABEL_21;
      v17 = v14->m_entityListeners.m_data;
      while ( *v17 != v11 )
      {
        ++v15;
        ++v8;
        ++v17;
        if ( v15 >= v16 )
          goto LABEL_21;
      }
      if ( v8 < 0 )
LABEL_21:
        hkpEntity::addEntityListener(v3, v11);
      v4->m_bool = 1;
    }
    else
    {
      v10 = v5->m_disabledEntities.m_data;
      while ( *v10 != new_entity )
      {
        ++v9;
        ++v10;
        if ( v9 >= v7 )
          goto LABEL_7;
      }
      v4->m_bool = 0;
    }
    v6 = v4;
  }
  else
  {
    result->m_bool = 0;
    v6 = result;
  }
  return v6;
}

// File Line: 92
// RVA: 0xE15500
hkBool *__fastcall hkpDisableEntityCollisionFilter::removeEntityFromFilter(hkpDisableEntityCollisionFilter *this, hkBool *result, hkpEntity *new_entity)
{
  hkBool *v3; // r9
  hkpEntity *v4; // r10
  hkpDisableEntityCollisionFilter *v5; // rdx
  __int64 v6; // r11
  int v7; // er8
  __int64 v8; // rcx
  hkpEntity **v9; // rax
  hkBool *v10; // rax
  __int64 v11; // rax

  v3 = result;
  v4 = new_entity;
  v5 = this;
  if ( new_entity && (v6 = this->m_disabledEntities.m_size, v7 = 0, v8 = 0i64, v6 > 0) )
  {
    v9 = v5->m_disabledEntities.m_data;
    while ( *v9 != v4 )
    {
      ++v8;
      ++v7;
      ++v9;
      if ( v8 >= v6 )
        goto LABEL_6;
    }
    v11 = --v5->m_disabledEntities.m_size;
    if ( (_DWORD)v11 != v7 )
      v5->m_disabledEntities.m_data[v7] = v5->m_disabledEntities.m_data[v11];
    v3->m_bool = 1;
    v10 = v3;
  }
  else
  {
LABEL_6:
    v3->m_bool = 0;
    v10 = v3;
  }
  return v10;
}

// File Line: 116
// RVA: 0xE15570
void __fastcall hkpDisableEntityCollisionFilter::entityRemovedCallback(hkpDisableEntityCollisionFilter *this, hkpEntity *entity)
{
  hkpEntity *v2; // rdi
  hkpDisableEntityCollisionFilter *v3; // rsi
  hkpShapeCollectionFilter *v4; // rbx
  hkpEntityListener *v5; // rdx
  hkBool result; // [rsp+38h] [rbp+10h]

  if ( entity )
  {
    v2 = entity;
    v3 = this;
    v4 = (hkpShapeCollectionFilter *)&this[-1].vfptr;
    hkpDisableEntityCollisionFilter::removeEntityFromFilter(
      (hkpDisableEntityCollisionFilter *)((char *)this - 72),
      &result,
      entity);
    v5 = 0i64;
    if ( v4 )
      v5 = (hkpEntityListener *)v3;
    hkpEntity::removeEntityListener(v2, v5);
  }
}

// File Line: 125
// RVA: 0xE155D0
void __fastcall hkpDisableEntityCollisionFilter::entityDeletedCallback(hkpDisableEntityCollisionFilter *this, hkpEntity *entity)
{
  ;
}

