// File Line: 15
// RVA: 0xE15160
void __fastcall hkpDisableEntityCollisionFilter::hkpDisableEntityCollisionFilter(hkpDisableEntityCollisionFilter *this)
{
  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpDisableEntityCollisionFilter::`vftable;
  this->m_disabledEntities.m_capacityAndFlags = 0x80000000;
  this->m_disabledEntities.m_data = 0i64;
  this->m_disabledEntities.m_size = 0;
}

// File Line: 20
// RVA: 0xE151D0
void __fastcall hkpDisableEntityCollisionFilter::~hkpDisableEntityCollisionFilter(
        hkpDisableEntityCollisionFilter *this)
{
  hkpEntityListener *v1; // rsi
  int v3; // ebp
  __int64 v4; // r14
  hkpEntity *v5; // rdi
  _QWORD **Value; // rax
  __int64 v7; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // rax
  int v9; // edx
  __int64 v10; // rcx
  __int64 m_size; // r8
  hkpEntityListener **m_data; // rax
  int m_capacityAndFlags; // r8d

  v1 = &this->hkpEntityListener;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v3 = 0;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpDisableEntityCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpDisableEntityCollisionFilter::`vftable;
  if ( this->m_disabledEntities.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = this->m_disabledEntities.m_data[v4];
      if ( !v5->m_extendedListeners )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
        if ( v7 )
        {
          *(_QWORD *)v7 = 0i64;
          *(_DWORD *)(v7 + 8) = 0x80000000;
          *(_QWORD *)(v7 + 16) = 0i64;
          *(_DWORD *)(v7 + 24) = 0x80000000;
        }
        else
        {
          v7 = 0i64;
        }
        v5->m_extendedListeners = (hkpEntity::ExtendedListeners *)v7;
      }
      m_extendedListeners = v5->m_extendedListeners;
      v9 = 0;
      v10 = 0i64;
      m_size = m_extendedListeners->m_entityListeners.m_size;
      if ( m_extendedListeners->m_entityListeners.m_size )
      {
        m_data = m_extendedListeners->m_entityListeners.m_data;
        while ( *m_data != v1 )
        {
          ++v10;
          ++v9;
          ++m_data;
          if ( v10 >= m_size )
            goto LABEL_15;
        }
        if ( v9 >= 0 )
          hkpEntity::removeEntityListener(this->m_disabledEntities.m_data[v4], v1);
      }
LABEL_15:
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_disabledEntities.m_size );
  }
  m_capacityAndFlags = this->m_disabledEntities.m_capacityAndFlags;
  this->m_disabledEntities.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_disabledEntities.m_data,
      8 * m_capacityAndFlags);
  this->m_disabledEntities.m_data = 0i64;
  this->m_disabledEntities.m_capacityAndFlags = 0x80000000;
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 33
// RVA: 0xE155E0
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  __int64 vfptr_low; // r11
  __int64 v5; // r10
  _QWORD *v6; // rcx
  hkpCollidable *v7; // rax

  vfptr_low = SLODWORD(this->hkpEntityListener::vfptr);
  v5 = 0i64;
  if ( vfptr_low <= 0 )
  {
LABEL_6:
    result->m_bool = 1;
    return result;
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
      if ( v5 >= vfptr_low )
        goto LABEL_6;
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 47
// RVA: 0xE15630
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a)
{
  result->m_bool = 1;
  return result;
}

// File Line: 52
// RVA: 0xE15650
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer)
{
  result->m_bool = 1;
  return result;
}

// File Line: 57
// RVA: 0xE15640
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *collectionBodyA)
{
  result->m_bool = 1;
  return result;
}

// File Line: 63
// RVA: 0xE15660
hkBool *__fastcall hkpDisableEntityCollisionFilter::isCollisionEnabled(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpWorldRayCastInput *a,
        hkpCollidable *collidableB)
{
  result->m_bool = 1;
  return result;
}

// File Line: 69
// RVA: 0xE153A0
hkBool *__fastcall hkpDisableEntityCollisionFilter::addEntityToFilter(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpEntity *new_entity)
{
  __int64 m_size; // rdx
  int v8; // ebx
  __int64 v9; // rcx
  hkpEntity **v10; // rax
  hkpEntityListener *v11; // rbp
  _QWORD **Value; // rax
  __int64 v13; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  hkpEntityListener **m_data; // rax

  if ( new_entity )
  {
    m_size = this->m_disabledEntities.m_size;
    v8 = 0;
    v9 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_7:
      if ( this->m_disabledEntities.m_size == (this->m_disabledEntities.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&this->m_disabledEntities.m_data,
          8);
      this->m_disabledEntities.m_data[this->m_disabledEntities.m_size++] = new_entity;
      v11 = &this->hkpEntityListener;
      if ( !new_entity->m_extendedListeners )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *(_DWORD *)(v13 + 8) = 0x80000000;
          *(_QWORD *)(v13 + 16) = 0i64;
          *(_DWORD *)(v13 + 24) = 0x80000000;
        }
        else
        {
          v13 = 0i64;
        }
        new_entity->m_extendedListeners = (hkpEntity::ExtendedListeners *)v13;
      }
      m_extendedListeners = new_entity->m_extendedListeners;
      v15 = 0i64;
      v16 = m_extendedListeners->m_entityListeners.m_size;
      if ( !m_extendedListeners->m_entityListeners.m_size )
        goto LABEL_21;
      m_data = m_extendedListeners->m_entityListeners.m_data;
      while ( *m_data != v11 )
      {
        ++v15;
        ++v8;
        ++m_data;
        if ( v15 >= v16 )
          goto LABEL_21;
      }
      if ( v8 < 0 )
LABEL_21:
        hkpEntity::addEntityListener(new_entity, v11);
      result->m_bool = 1;
    }
    else
    {
      v10 = this->m_disabledEntities.m_data;
      while ( *v10 != new_entity )
      {
        ++v9;
        ++v10;
        if ( v9 >= m_size )
          goto LABEL_7;
      }
      result->m_bool = 0;
    }
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 92
// RVA: 0xE15500
hkBool *__fastcall hkpDisableEntityCollisionFilter::removeEntityFromFilter(
        hkpDisableEntityCollisionFilter *this,
        hkBool *result,
        hkpEntity *new_entity)
{
  __int64 m_size; // r11
  int v7; // r8d
  __int64 v8; // rcx
  hkpEntity **m_data; // rax
  __int64 v11; // rax

  if ( new_entity && (m_size = this->m_disabledEntities.m_size, v7 = 0, v8 = 0i64, m_size > 0) )
  {
    m_data = this->m_disabledEntities.m_data;
    while ( *m_data != new_entity )
    {
      ++v8;
      ++v7;
      ++m_data;
      if ( v8 >= m_size )
        goto LABEL_6;
    }
    v11 = --this->m_disabledEntities.m_size;
    if ( (_DWORD)v11 != v7 )
      this->m_disabledEntities.m_data[v7] = this->m_disabledEntities.m_data[v11];
    result->m_bool = 1;
    return result;
  }
  else
  {
LABEL_6:
    result->m_bool = 0;
    return result;
  }
}

// File Line: 116
// RVA: 0xE15570
void __fastcall hkpDisableEntityCollisionFilter::entityRemovedCallback(
        hkpDisableEntityCollisionFilter *this,
        hkpEntity *entity)
{
  hkpShapeCollectionFilter *v4; // rbx
  hkpEntityListener *v5; // rdx
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  if ( entity )
  {
    v4 = &this[-1].hkpShapeCollectionFilter;
    hkpDisableEntityCollisionFilter::removeEntityFromFilter(
      (hkpDisableEntityCollisionFilter *)((char *)this - 72),
      &result,
      entity);
    v5 = 0i64;
    if ( v4 )
      v5 = (hkpEntityListener *)this;
    hkpEntity::removeEntityListener(entity, v5);
  }
}

// File Line: 125
// RVA: 0xE155D0
void __fastcall hkpDisableEntityCollisionFilter::entityDeletedCallback(
        hkpDisableEntityCollisionFilter *this,
        hkpEntity *entity)
{
  ;
}

