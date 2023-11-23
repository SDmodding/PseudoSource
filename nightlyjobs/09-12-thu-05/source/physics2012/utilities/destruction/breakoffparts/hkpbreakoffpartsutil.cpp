// File Line: 34
// RVA: 0xE0D9B0
__int64 __fastcall hkpBreakOffPartsUtil::GameControlFunctor::test(
        hkpBreakOffPartsUtil::GameControlFunctor *this,
        hkpRigidBody *limitedBody,
        hkpRigidBody *otherBody,
        const unsigned int key)
{
  return 3i64;
}

// File Line: 43
// RVA: 0xE0BD00
void __fastcall hkpBreakOffPartsUtil::hkpBreakOffPartsUtil(
        hkpBreakOffPartsUtil *this,
        hkpBreakOffPartsListener *listenerInterface)
{
  _QWORD **Value; // rax
  hkCriticalSection *v5; // rax
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkpBreakOffPartsUtil::GameControlFunctor *v8; // rbx
  hkpBreakOffPartsUtil::GameControlFunctor *m_pntr; // rcx

  hkpWorldExtension::hkpWorldExtension(this, 1000);
  this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpWorldExtension};
  this->hkpContactImpulseLimitBreachedListener::vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpContactImpulseLimitBreachedListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpEntityListener};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpConstraintListener};
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v5 )
    hkCriticalSection::hkCriticalSection(v5, 1u);
  this->m_criticalSection = v5;
  this->m_breakOffPartsListener = listenerInterface;
  this->m_breakOffGameControlFunctor.m_pntr = 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 16i64);
  v8 = (hkpBreakOffPartsUtil::GameControlFunctor *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpBreakOffPartsUtil::GameControlFunctor::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v8 )
    hkReferencedObject::addReference(v8);
  m_pntr = this->m_breakOffGameControlFunctor.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_breakOffGameControlFunctor.m_pntr = v8;
  hkReferencedObject::removeReference(v8);
}

// File Line: 50
// RVA: 0xE0C3F0
void __fastcall hkpBreakOffPartsUtil::~hkpBreakOffPartsUtil(hkpBreakOffPartsUtil *this)
{
  hkCriticalSection *m_criticalSection; // rdi
  _QWORD **Value; // rax
  hkpBreakOffPartsUtil::GameControlFunctor *m_pntr; // rcx

  m_criticalSection = this->m_criticalSection;
  this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpWorldExtension};
  this->hkpContactImpulseLimitBreachedListener::vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpContactImpulseLimitBreachedListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpEntityListener};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpBreakOffPartsUtil::`vftable{for `hkpConstraintListener};
  if ( m_criticalSection )
  {
    DeleteCriticalSection(&m_criticalSection->m_section);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_criticalSection,
      40i64);
  }
  m_pntr = this->m_breakOffGameControlFunctor.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_breakOffGameControlFunctor.m_pntr = 0i64;
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpContactImpulseLimitBreachedListener::vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpContactImpulseLimitBreachedListener::`vftable;
  this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 55
// RVA: 0xE0BFF0
void __fastcall hkpBreakOffPartsUtil::removeKeysFromListShape(
        hkpEntity *entity,
        unsigned int *keysToRemove,
        int numKeys)
{
  hkpShape *m_shape; // rbp
  hkAabbUint32 *m_childShapeAabbs; // r15
  __int64 v7; // rdi
  unsigned __int64 m_userData; // rbx
  hkpShapeContainer *v9; // r8
  __int64 i; // rbx
  __int64 j; // rbx
  unsigned int *m_childShapeKeys; // rbp
  __int64 v13; // rdi
  __int64 m_numChildShapeAabbs; // rsi
  unsigned int *v15; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> shapesToRemove; // [rsp+20h] [rbp-58h] BYREF
  hkpRemoveTerminalsMoppModifier v17; // [rsp+30h] [rbp-48h] BYREF

  m_shape = entity->m_collidable.m_shape;
  m_childShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  v7 = numKeys;
  if ( m_shape->m_type.m_storage != 8 )
  {
    if ( m_shape->m_type.m_storage != 9 )
      return;
    m_userData = m_shape[2].m_userData;
    shapesToRemove.m_size = numKeys;
    shapesToRemove.m_capacityAndFlags = numKeys | 0x80000000;
    shapesToRemove.m_data = keysToRemove;
    v9 = (hkpShapeContainer *)(m_userData + 32);
    if ( !m_userData )
      v9 = 0i64;
    hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
      &v17,
      *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags,
      v9,
      &shapesToRemove);
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(&v17, *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags);
    if ( *(_BYTE *)(m_userData + 16) != 8 )
    {
      hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v17);
      shapesToRemove.m_size = 0;
      if ( shapesToRemove.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          shapesToRemove.m_data,
          4 * shapesToRemove.m_capacityAndFlags);
      goto LABEL_11;
    }
    m_shape = (hkpShape *)m_userData;
    hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v17);
    shapesToRemove.m_size = 0;
    if ( shapesToRemove.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        shapesToRemove.m_data,
        4 * shapesToRemove.m_capacityAndFlags);
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_capacityAndFlags = 0x80000000;
  }
  for ( i = 0i64; i < v7; ++i )
    hkpListShape::disableChild((hkpListShape *)m_shape, keysToRemove[i]);
LABEL_11:
  if ( m_childShapeAabbs )
  {
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_size = 0;
    shapesToRemove.m_capacityAndFlags = -1;
    for ( j = 0i64; j < v7; ++j )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
        &hkContainerHeapAllocator::s_alloc,
        keysToRemove[j],
        1ui64);
    m_childShapeKeys = entity->m_collidable.m_boundingVolumeData.m_childShapeKeys;
    v13 = 0i64;
    m_numChildShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs )
    {
      v15 = &m_childShapeAabbs->m_max[2];
      do
      {
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
                             m_childShapeKeys[v13],
                             0i64) )
        {
          *(v15 - 5) = 2147418112;
          *((_QWORD *)v15 - 2) = 2147418112i64;
          *(_QWORD *)(v15 - 1) = 0i64;
        }
        ++v13;
        v15 += 8;
      }
      while ( v13 < m_numChildShapeAabbs );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&shapesToRemove);
  }
}a

// File Line: 120
// RVA: 0xE0C220
void __fastcall hkpBreakOffPartsUtil::removeKeysFromListShapeByEnabledList(hkpEntity *entity, hkBitField *enabledKeys)
{
  hkpShape *m_shape; // rbx
  hkAabbUint32 *m_childShapeAabbs; // rbp
  hkpShape *m_userData; // r14
  int v7; // r9d
  __int64 m_numChildShapeAabbs; // r10
  unsigned int *v9; // rax
  hkpRemoveTerminalsMoppModifier2 v10; // [rsp+20h] [rbp-48h] BYREF

  m_shape = entity->m_collidable.m_shape;
  m_childShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  if ( m_shape->m_type.m_storage != 8 )
  {
    if ( m_shape->m_type.m_storage != 9 )
      return;
    m_userData = (hkpShape *)m_shape[2].m_userData;
    hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2(
      &v10,
      *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags,
      enabledKeys);
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(&v10, *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags);
    if ( m_userData->m_type.m_storage != 8 )
    {
      hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v10);
      goto LABEL_6;
    }
    m_shape = m_userData;
    hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v10);
  }
  hkpListShape::setEnabledChildren((hkpListShape *)m_shape, enabledKeys);
LABEL_6:
  if ( m_childShapeAabbs )
  {
    v7 = 0;
    m_numChildShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs )
    {
      v9 = &m_childShapeAabbs->m_max[2];
      do
      {
        if ( ((enabledKeys->m_storage.m_words.m_data[(__int64)v7 >> 5] >> (v7 & 0x1F)) & 1) == 0 )
        {
          *(v9 - 5) = 2147418112;
          *((_QWORD *)v9 - 2) = 2147418112i64;
          *(_QWORD *)(v9 - 1) = 0i64;
        }
        ++v7;
        v9 += 8;
        --m_numChildShapeAabbs;
      }
      while ( m_numChildShapeAabbs );
    }
  }
}

// File Line: 174
// RVA: 0xE0D640
void __fastcall hkpBreakOffPartsUtil::worldDeletedCallback(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpContactImpulseLimitBreachedListener *v3; // rdx

  if ( this )
    v3 = &this->hkpContactImpulseLimitBreachedListener;
  else
    v3 = 0i64;
  hkpWorld::removeContactImpulseLimitBreachedListener(this->m_world, v3);
  this->m_world = 0i64;
  hkReferencedObject::removeReference(this);
}

// File Line: 181
// RVA: 0xE0D680
void __fastcall hkpBreakOffPartsUtil::entityRemovedCallback(hkpBreakOffPartsUtil *this, hkpEntity *entity)
{
  ;
}

// File Line: 188
// RVA: 0xE0D8F0
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::LimitContactImpulseUtil(
        hkpBreakOffPartsUtil::LimitContactImpulseUtil *this,
        hkpBreakOffPartsUtil *breakUtil,
        hkpEntity *entity)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_entity = entity;
  this->m_maxConstraintImpulse = 3.40282e38;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable{for `hkReferencedObject};
  this->hkpCollisionListener::hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable{for `hkpCollisionListener};
  this->m_shapeKeyToMaxImpulse.m_map.m_hashMod = -1;
  this->m_shapeKeyToMaxImpulse.m_map.m_elem = 0i64;
  this->m_shapeKeyToMaxImpulse.m_map.m_numElems = 0;
  this->m_breakOffUtil = breakUtil;
  this->m_maxImpulse.m_value = -1;
  entity->m_limitContactImpulseUtilAndFlag = this;
  hkpEntity::addContactListener(entity, &this->hkpCollisionListener);
  hkReferencedObject::addReference(this->m_breakOffUtil);
}

// File Line: 197
// RVA: 0xE0D880
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::~LimitContactImpulseUtil(
        hkpBreakOffPartsUtil::LimitContactImpulseUtil *this)
{
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable{for `hkReferencedObject};
  this->hkpCollisionListener::hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable{for `hkpCollisionListener};
  hkReferencedObject::removeReference(this->m_breakOffUtil);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_shapeKeyToMaxImpulse.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_shapeKeyToMaxImpulse);
  this->hkpCollisionListener::hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 202
// RVA: 0xE0D9C0
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__fastcall hkpBreakOffPartsUtil::createLimitContactImpulseUtil(
        hkpBreakOffPartsUtil *this,
        hkpEntity *entity)
{
  _QWORD **Value; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *result; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v6; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                              Value[11],
                                                              80i64);
  v6 = result;
  if ( result )
  {
    hkpBreakOffPartsUtil::LimitContactImpulseUtil::LimitContactImpulseUtil(result, this, entity);
    v6->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::`vftable{for `hkReferencedObject};
    v6->hkpCollisionListener::hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::`vftable{for `hkpCollisionListener};
    result = v6;
    entity->m_limitContactImpulseUtilAndFlag = (void *)((unsigned __int64)entity->m_limitContactImpulseUtilAndFlag | 1);
  }
  return result;
}

// File Line: 214
// RVA: 0xE0BE10
void __fastcall hkpBreakOffPartsUtil::markPieceBreakable(
        hkpBreakOffPartsUtil *this,
        hkpEntity *entity,
        unsigned int key,
        float maxImpulse)
{
  unsigned __int64 v4; // rdi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  unsigned __int8 m_value; // dl
  hkUFloat8 v7; // [rsp+50h] [rbp+18h] BYREF
  float fv; // [rsp+58h] [rbp+20h] BYREF

  v4 = key;
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v5 )
    v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((__int64 (__fastcall *)(hkpBreakOffPartsUtil *))this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr[3].__vecDelDtor)(this);
  fv = maxImpulse;
  hkUFloat8::operator=(&v7, &fv);
  m_value = v7.m_value;
  if ( !v7.m_value )
    m_value = 1;
  v7.m_value = m_value;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    v5 + 3,
    &hkContainerHeapAllocator::s_alloc,
    v4,
    m_value);
}

// File Line: 223
// RVA: 0xE0BEA0
void __fastcall hkpBreakOffPartsUtil::markEntityBreakable(
        hkpBreakOffPartsUtil *this,
        hkpEntity *entity,
        float maxImpulse)
{
  unsigned __int64 v3; // rbx
  char m_value; // dl
  float fv; // [rsp+48h] [rbp+10h] BYREF
  hkUFloat8 v6; // [rsp+50h] [rbp+18h] BYREF

  v3 = (unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v3 )
    v3 = ((__int64 (__fastcall *)(hkpBreakOffPartsUtil *))this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr[3].__vecDelDtor)(this);
  fv = maxImpulse;
  hkUFloat8::operator=(&v6, &fv);
  m_value = v6.m_value;
  if ( !v6.m_value )
    m_value = 1;
  *(_BYTE *)(v3 + 40) = m_value;
}

// File Line: 230
// RVA: 0xE0BF90
void __fastcall hkpBreakOffPartsUtil::unmarkPieceBreakable(
        hkpBreakOffPartsUtil *this,
        hkpEntity *entity,
        unsigned int key)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( v5 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(v5 + 3, &result, key);
    if ( (v5[3].m_numElems & 0x7FFFFFFF) == 0 )
      hkpBreakOffPartsUtil::unmarkEntityBreakable(this, entity);
  }
}

// File Line: 245
// RVA: 0xE0BF40
void __fastcall hkpBreakOffPartsUtil::unmarkEntityBreakable(hkpBreakOffPartsUtil *this, hkpEntity *entity)
{
  unsigned __int64 v3; // rbx

  v3 = (unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    hkpEntity::removeContactListener(entity, (hkpContactListener *)(v3 + 16));
    (**(void (__fastcall ***)(unsigned __int64, __int64))v3)(v3, 1i64);
    entity->m_limitContactImpulseUtilAndFlag = 0i64;
  }
}

// File Line: 256
// RVA: 0xE0BF00
void __fastcall hkpBreakOffPartsUtil::setMaxConstraintImpulse(
        hkpBreakOffPartsUtil *this,
        hkpEntity *entity,
        float maxConstraintImpulse)
{
  unsigned __int64 v3; // rax

  v3 = (unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v3 )
    v3 = ((__int64 (__fastcall *)(hkpBreakOffPartsUtil *))this->hkpWorldExtension::hkReferencedObject::hkBaseObject::vfptr[3].__vecDelDtor)(this);
  *(float *)(v3 + 44) = maxConstraintImpulse;
}

// File Line: 262
// RVA: 0xE0D970
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::limitContactImpulse(
        hkpBreakOffPartsUtil::LimitContactImpulseUtil *this,
        hkUFloat8 *maxImpulse,
        bool isEntityIdSmaller,
        hkpContactPointProperties *properties)
{
  unsigned __int8 m_value; // al
  unsigned __int8 v5; // cl

  m_value = maxImpulse->m_value;
  if ( maxImpulse->m_value )
  {
    v5 = properties->m_maxImpulse.m_value;
    if ( !v5 || m_value < v5 )
    {
      properties->m_flags &= ~2u;
      properties->m_maxImpulse.m_value = m_value;
      if ( isEntityIdSmaller )
        properties->m_flags |= 4u;
      else
        properties->m_flags &= ~4u;
    }
  }
}

// File Line: 290
// RVA: 0xE0DA60
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::contactPointAddedCallback(
        hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault *this,
        hkpContactPointAddedEvent *event)
{
  hkpCdBody *m_bodyA; // r8
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // r9
  unsigned int m_shapeKey; // r14d
  hkpCdBody *m_bodyB; // rax
  hkpCdBody *v9; // rdx
  hkpCdBody *j; // rcx
  hkpDynamicsContactMgr *m_internalContactMgr; // rax
  hkpContactListenerVtbl *vfptr; // rbp
  hkpRigidBody *v13; // rsi
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v14; // rcx
  hkpRigidBody *v15; // rbp
  int v16; // eax
  __int64 v17; // r8
  bool v18; // cf
  int v19; // eax
  hkUFloat8 result; // [rsp+50h] [rbp+8h] BYREF

  if ( this->m_shapeKeyToMaxImpulse.m_map.m_elem[1].key )
  {
    m_bodyA = event->m_bodyA;
    m_parent = event->m_bodyA->m_parent;
    for ( i = event->m_bodyA; m_parent; m_parent = m_parent->m_parent )
    {
      i = m_bodyA;
      m_bodyA = m_parent;
    }
    m_shapeKey = i->m_shapeKey;
    if ( (hkpCdBody *)&this->hkpBreakOffPartsUtil::LimitContactImpulseUtil::hkpCollisionListener::hkpContactListener::vfptr->contactPointAddedCallback != m_bodyA )
    {
      m_bodyB = event->m_bodyB;
      v9 = m_bodyB;
      for ( j = m_bodyB->m_parent; j; j = j->m_parent )
      {
        v9 = m_bodyB;
        m_bodyB = j;
      }
      m_shapeKey = v9->m_shapeKey;
    }
    if ( !((unsigned int (__fastcall *)(hkpDynamicsContactMgr *))event->m_internalContactMgr->vfptr[6].__first_virtual_table_function__)(event->m_internalContactMgr) )
    {
      m_internalContactMgr = event->m_internalContactMgr;
      vfptr = this->hkpBreakOffPartsUtil::LimitContactImpulseUtil::hkpCollisionListener::hkpContactListener::vfptr;
      v13 = (hkpRigidBody *)m_internalContactMgr[5].vfptr;
      v14 = (hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault *)((char *)this - 16);
      if ( v13 == (hkpRigidBody *)vfptr )
      {
        v15 = *(hkpRigidBody **)&m_internalContactMgr[5].m_memSizeAndFlags;
        hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(v14, &result, m_shapeKey, v15);
        v16 = (*(__int64 (__fastcall **)(unsigned __int64, hkpRigidBody *, hkpRigidBody *, _QWORD, hkUFloat8 *))(*(_QWORD *)this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
                this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
                v13,
                v15,
                m_shapeKey,
                &result)
            - 1;
        if ( v16 )
        {
          if ( v16 == 1 )
            return;
          v18 = v13->m_uid < v15->m_uid;
        }
        else
        {
          result.m_value = 1;
          v18 = v13->m_uid < v15->m_uid;
        }
      }
      else
      {
        hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(v14, &result, m_shapeKey, v13);
        v19 = (*(__int64 (__fastcall **)(unsigned __int64, hkpContactListenerVtbl *, hkpRigidBody *, _QWORD, hkUFloat8 *))(*(_QWORD *)this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
                this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
                vfptr,
                v13,
                m_shapeKey,
                &result)
            - 1;
        if ( v19 )
        {
          if ( v19 == 1 )
            return;
        }
        else
        {
          result.m_value = 1;
        }
        v18 = HIDWORD(vfptr[5].__vecDelDtor) < v13->m_uid;
      }
      LOBYTE(v17) = v18;
      (*(void (__fastcall **)(hkpBreakOffPartsUtil **, hkUFloat8 *, __int64, hkpContactPointProperties *))&this[-1].m_breakOffUtil->m_id)(
        &this[-1].m_breakOffUtil,
        &result,
        v17,
        event->m_contactPointProperties);
    }
  }
}

// File Line: 382
// RVA: 0xE0DD50
__int64 __fastcall findTopShapeKey(unsigned int *leafKeyPtr, int sizeOfKeyStorage)
{
  unsigned int v2; // r8d
  const unsigned int *i; // rdx

  v2 = -1;
  for ( i = &leafKeyPtr[sizeOfKeyStorage]; *leafKeyPtr != -1; ++leafKeyPtr )
  {
    if ( leafKeyPtr >= i )
      break;
    v2 = *leafKeyPtr;
  }
  return v2;
}

// File Line: 395
// RVA: 0xE0DBF0
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly::contactPointCallback(
        hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly *this,
        hkpContactPointEvent *event)
{
  __int64 m_source; // r8
  unsigned int *v5; // rax
  unsigned int v6; // edi
  unsigned int *i; // rcx
  hkpRigidBody *v8; // r15
  hkpRigidBody *v9; // rbp
  int v10; // eax
  __int64 v11; // r8
  hkUFloat8 result; // [rsp+50h] [rbp+8h] BYREF

  if ( this->m_shapeKeyToMaxImpulse.m_map.m_elem[1].key && (event->m_contactPointProperties->m_flags & 1) != 0 )
  {
    m_source = event->m_source;
    v5 = 0i64;
    if ( event->m_bodies[m_source]->m_numShapeKeysInContactPointProperties )
      v5 = &event->m_shapeKeyStorage[(int)(m_source
                                         * (unsigned __int8)event->m_bodies[0]->m_numShapeKeysInContactPointProperties)];
    v6 = -1;
    for ( i = &v5[BYTE1(this->hkpBreakOffPartsUtil::LimitContactImpulseUtil::hkpCollisionListener::hkpContactListener::vfptr[5].~hkpContactListener)];
          *v5 != -1;
          ++v5 )
    {
      if ( v5 >= i )
        break;
      v6 = *v5;
    }
    if ( (_DWORD)m_source )
    {
      v8 = event->m_bodies[m_source];
      v9 = (hkpRigidBody *)*((_QWORD *)&event->m_source + 2 - m_source);
    }
    else
    {
      v8 = event->m_bodies[0];
      v9 = event->m_bodies[1];
    }
    hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(
      (hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly *)((char *)this - 16),
      &result,
      v6,
      v9);
    v10 = (*(__int64 (__fastcall **)(unsigned __int64, hkpRigidBody *, hkpRigidBody *, _QWORD, hkUFloat8 *))(*(_QWORD *)this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
            this->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
            v8,
            v9,
            v6,
            &result)
        - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        return;
    }
    else
    {
      result.m_value = 1;
    }
    LOBYTE(v11) = v8->m_uid < v9->m_uid;
    (*(void (__fastcall **)(hkpBreakOffPartsUtil **, hkUFloat8 *, __int64, hkpContactPointProperties *))&this[-1].m_breakOffUtil->m_id)(
      &this[-1].m_breakOffUtil,
      &result,
      v11,
      event->m_contactPointProperties);
  }
}

// File Line: 466
// RVA: 0xE0D690
void __fastcall hkpBreakOffPartsUtil::constraintAddedCallback(
        hkpBreakOffPartsUtil *this,
        hkpConstraintInstance *constraint)
{
  unsigned __int64 m_limitContactImpulseUtilAndFlag; // r8
  hkpEntity *v4; // rax
  hkpConstraintData *m_data; // rbx
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // r8
  float v8; // xmm2_4
  float v9; // xmm1_4

  if ( ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) != 11 )
  {
    m_limitContactImpulseUtilAndFlag = (unsigned __int64)constraint->m_entities[0]->m_limitContactImpulseUtilAndFlag;
    v4 = constraint->m_entities[1];
    m_data = constraint->m_data;
    v6 = (unsigned __int64)v4->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
    v7 = m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
    if ( v7 || v6 )
    {
      v8 = FLOAT_3_40282e38;
      v9 = FLOAT_3_40282e38;
      if ( v7 )
        v8 = *(float *)(v7 + 44);
      if ( v6 )
        v9 = *(float *)(v6 + 44);
      m_data->vfptr[6].__vecDelDtor(m_data, v9 <= v8);
    }
    ((void (__fastcall *)(hkpConstraintData *))m_data->vfptr[4].__vecDelDtor)(m_data);
  }
}

// File Line: 510
// RVA: 0xE0DD80
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__fastcall findUtil(
        hkpSimpleConstraintContactMgr *mgr,
        hkpContactPointProperties *props,
        hkBool *defaultValueHitOut,
        unsigned int *key,
        hkUFloat8 *maxImpulseOut)
{
  hkBaseObjectVtbl *vfptr; // rax
  unsigned int v10; // ebx
  __int64 v11; // rax
  int m_numUserDatasForBodyA; // edx
  BOOL v13; // r9d
  unsigned int v14; // ebx
  __int64 v15; // rax
  unsigned __int64 m_limitContactImpulseUtilAndFlag; // rbx
  unsigned __int64 v17; // rbx
  hkpSimpleContactConstraintAtom *m_atom; // r10
  __int64 v19; // rax
  unsigned int v20; // edx
  unsigned int *v21; // rcx
  unsigned int *i; // r8
  unsigned int v23; // eax

  vfptr = mgr->vfptr;
  if ( (props->m_flags & 4) != 0 )
  {
    v10 = *(_DWORD *)(*(_QWORD *)(((__int64 (*)(void))vfptr[8].__vecDelDtor)() + 40) + 308i64);
    v11 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))mgr->vfptr[8].__vecDelDtor)(mgr);
    m_numUserDatasForBodyA = 0;
    v13 = v10 >= *(_DWORD *)(*(_QWORD *)(v11 + 48) + 308i64);
  }
  else
  {
    v14 = *(_DWORD *)(*(_QWORD *)(((__int64 (*)(void))vfptr[8].__vecDelDtor)() + 40) + 308i64);
    v15 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))mgr->vfptr[8].__vecDelDtor)(mgr);
    m_numUserDatasForBodyA = 0;
    v13 = v14 < *(_DWORD *)(*(_QWORD *)(v15 + 48) + 308i64);
  }
  m_limitContactImpulseUtilAndFlag = (unsigned __int64)mgr->m_constraint.m_entities[v13]->m_limitContactImpulseUtilAndFlag;
  maxImpulseOut->m_value = (char)props->m_maxImpulse;
  v17 = m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v17 )
  {
    m_atom = mgr->m_contactConstraintData.m_atom;
    if ( v13 )
      m_numUserDatasForBodyA = (unsigned __int8)m_atom->m_numUserDatasForBodyA;
    v19 = m_numUserDatasForBodyA;
    v20 = -1;
    v21 = (unsigned int *)&props[1].hkpSolverResults + v19;
    for ( i = &v21[*((unsigned __int8 *)&m_atom->m_numUserDatasForBodyA + v13)]; *v21 != -1; ++v21 )
    {
      if ( v21 >= i )
        break;
      v20 = *v21;
    }
    *key = v20;
    v23 = *((_DWORD *)&props[1].m_impulseApplied + v13 * (unsigned __int8)m_atom->m_numUserDatasForBodyA);
    *key = v23;
    if ( v23 != -1
      && (unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v17 + 48),
                            v23,
                            0i64) )
    {
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v17;
    }
    if ( *(_BYTE *)(v17 + 40) )
    {
      defaultValueHitOut->m_bool = 1;
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v17;
    }
  }
  return 0i64;
}

// File Line: 557
// RVA: 0xE0DED0
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__fastcall findUtil_0(
        hkpRigidBody *body,
        hkpConstraintInstance *constraint,
        hkBool *defaultValueHitOut,
        unsigned int *key,
        hkUFloat8 *maxImpulseOut)
{
  unsigned __int64 v9; // rbx
  unsigned __int16 EncodedFloat; // ax
  float v11; // xmm0_4
  hkpConstraintData *m_data; // rcx
  hkVector4f *PivotA; // rax
  hkpShape *m_shape; // rdx
  hkpWorld *m_world; // rcx
  unsigned int ClosestShapeKey; // eax
  hkVector4f pivotInBodySpace; // [rsp+20h] [rbp-28h] BYREF
  float v19; // [rsp+50h] [rbp+8h] BYREF
  float fv; // [rsp+58h] [rbp+10h] BYREF

  v9 = (unsigned __int64)body->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  fv = ((float (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[5].__first_virtual_table_function__)(constraint->m_data);
  hkUFloat8::operator=((hkUFloat8 *)&v19, &fv);
  EncodedFloat = hkUFloat8::getEncodedFloat(LOBYTE(v19));
  LODWORD(v19) = (EncodedFloat + 243712) << 12;
  if ( EncodedFloat )
    v11 = v19;
  else
    v11 = 0.0;
  maxImpulseOut->m_value = (int)v11;
  if ( v9 )
  {
    m_data = constraint->m_data;
    if ( body == constraint->m_entities[0] )
      PivotA = (hkVector4f *)hkpConstraintDataUtils::getPivotA(m_data);
    else
      PivotA = hkpConstraintDataUtils::getPivotB(m_data);
    m_shape = body->m_collidable.m_shape;
    m_world = body->m_world;
    pivotInBodySpace.m_quad = PivotA->m_quad;
    ClosestShapeKey = hkpConstraintPivotsUtil::findClosestShapeKey(m_world, m_shape, &pivotInBodySpace);
    *key = ClosestShapeKey;
    if ( ClosestShapeKey != -1
      && (unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v9 + 48),
                            ClosestShapeKey,
                            0i64) )
    {
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v9;
    }
    if ( *(_BYTE *)(v9 + 40) )
    {
      defaultValueHitOut->m_bool = 1;
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v9;
    }
  }
  return 0i64;
}

// File Line: 605
// RVA: 0xE0C4B0
void __fastcall hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback(
        hkpBreakOffPartsUtil *this,
        hkpContactImpulseLimitBreachedListenerInfo *breachedContacts,
        int numBreachedContacts)
{
  __int64 v3; // rdi
  hkpBreakOffPartsUtil *v5; // r14
  __int64 v6; // r12
  hkLifoAllocator *Value; // rax
  char *m_cur; // r13
  int v9; // edx
  char *v10; // rcx
  hkLifoAllocator *v11; // rax
  int v12; // edx
  char *v13; // rcx
  hkLifoAllocator *v14; // rax
  int v15; // edx
  char *v16; // rcx
  hkLifoAllocator *v17; // rax
  int v18; // edx
  char *v19; // rcx
  __int64 v20; // r15
  hkpConstraintInstance **p_m_constraintInstance; // rbx
  hkpContactPointProperties *v22; // rdx
  hkpSimpleConstraintContactMgr *p_m_uid; // rcx
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *Util; // rax
  unsigned __int64 v25; // rsi
  int v26; // eax
  __int64 val_low; // rcx
  __int64 v28; // rdi
  __int64 v29; // rax
  __int64 v30; // r14
  _QWORD **v31; // rax
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rsi
  float v35; // xmm0_4
  unsigned int v36; // eax
  __int64 v37; // rax
  hkpConstraintInstance *v38; // rax
  unsigned __int16 EncodedFloat; // ax
  int v40; // xmm0_4
  hkpConstraintInstance *v41; // rsi
  char v42; // r14
  _QWORD **v43; // rax
  __int64 v44; // rax
  __int64 v45; // rdi
  int v46; // ecx
  _QWORD *v47; // r8
  __int64 m_enum; // rdx
  __int64 v49; // rcx
  __int64 v50; // rcx
  hkpEntity *v51; // rdx
  __int64 v52; // rax
  __int64 v53; // r14
  int v54; // edx
  __m128 *v55; // r14
  hkVector4f *p_pivotAinW; // rcx
  __m128 v57; // xmm4
  __m128 v58; // xmm6
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm8
  __m128 m_quad; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  char *v65; // r15
  int v66; // edi
  hkpContactImpulseLimitBreachedListenerVtbl *vfptr; // rcx
  __int64 v68; // rsi
  __int64 v69; // r13
  int m_size; // ecx
  hkProcess *v71; // rbx
  __int64 v72; // rbx
  int v73; // r8d
  __int64 v74; // rdx
  __int64 v75; // rbx
  int v76; // eax
  _QWORD **v77; // rax
  hkProcess ***v78; // r13
  signed __int64 v79; // rcx
  hkProcess **v80; // r15
  __int64 v81; // rdi
  char v82; // bl
  hkProcess *v83; // rsi
  hkProcess *v84; // r12
  hkDisplaySerializeOStream *m_outStream; // r14
  unsigned __int64 v86; // r14
  hkpConstraintData *v87; // rcx
  hkVector4f *PivotA; // rax
  hkpShape *m_displayHandler; // rdx
  hkpWorld *m_inStream; // rcx
  unsigned int ClosestShapeKey; // eax
  __int64 v92; // rdi
  hkpBreakOffPartsUtil *v93; // r12
  hkpContactImpulseLimitBreachedListenerVtbl *v94; // rcx
  int v95; // eax
  int v96; // ecx
  hkProcess *v97; // rdi
  int v98; // esi
  hkProcess **v99; // rbx
  int v100; // eax
  _QWORD **v101; // rax
  int v102; // esi
  signed int v103; // ebx
  hkLifoAllocator *v104; // rax
  void *v105; // rdx
  int v106; // r8d
  int v107; // r14d
  signed int v108; // edi
  hkLifoAllocator *v109; // rax
  void *v110; // rdx
  int v111; // ebx
  hkLifoAllocator *v112; // rax
  void *v113; // rdx
  signed int v114; // ebx
  hkLifoAllocator *v115; // rax
  int v116; // r8d
  bool v117; // cc
  void *v118; // rbx
  int v119; // [rsp+30h] [rbp-D0h] BYREF
  hkResult result; // [rsp+34h] [rbp-CCh] BYREF
  void *v121; // [rsp+38h] [rbp-C8h]
  void *v122; // [rsp+40h] [rbp-C0h]
  void *p; // [rsp+48h] [rbp-B8h]
  __int64 v124; // [rsp+50h] [rbp-B0h]
  unsigned int key[2]; // [rsp+58h] [rbp-A8h] BYREF
  void *v126; // [rsp+60h] [rbp-A0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v127; // [rsp+68h] [rbp-98h] BYREF
  int v128; // [rsp+78h] [rbp-88h]
  hkVector4f pivotBinW; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f pivotAinW; // [rsp+90h] [rbp-70h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+A0h] [rbp-60h]
  hkpPhysicsSystem sys; // [rsp+B0h] [rbp-50h] BYREF
  hkArrayBase<hkProcess *> array; // [rsp+120h] [rbp+20h] BYREF
  char v134; // [rsp+130h] [rbp+30h] BYREF
  char *v135; // [rsp+530h] [rbp+430h] BYREF
  int v136; // [rsp+538h] [rbp+438h]
  int v137; // [rsp+53Ch] [rbp+43Ch]
  char v138[1024]; // [rsp+540h] [rbp+440h] BYREF
  int defaultValueHitOut; // [rsp+9F8h] [rbp+8F8h] BYREF
  int v141; // [rsp+A00h] [rbp+900h]
  hkResult maxImpulseOut; // [rsp+A08h] [rbp+908h] BYREF

  v141 = numBreachedContacts;
  v3 = numBreachedContacts;
  v5 = this;
  if ( breachedContacts->m_data.m_solver.m_type == 2 )
  {
    hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback_forToi(
      (hkpBreakOffPartsUtil *)((char *)this - 32),
      breachedContacts);
    return;
  }
  array.m_data = (hkProcess **)&v134;
  array.m_capacityAndFlags = -2147483520;
  array.m_size = 0;
  hkpPhysicsSystem::hkpPhysicsSystem(&sys);
  v127.m_elem = 0i64;
  v127.m_numElems = 0;
  v127.m_hashMod = -1;
  v6 = 0i64;
  if ( (_DWORD)v3 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v9 = (24 * v3 + 127) & 0xFFFFFF80;
    v126 = m_cur;
    v10 = &m_cur[v9];
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    {
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v9);
      v126 = m_cur;
    }
    else
    {
      Value->m_cur = v10;
    }
  }
  else
  {
    m_cur = 0i64;
    v126 = 0i64;
  }
  LODWORD(v124) = 0;
  v128 = v3 | 0x80000000;
  if ( (_DWORD)v3 )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (8 * v3 + 127) & 0xFFFFFF80;
    v121 = v11->m_cur;
    v13 = (char *)v121 + v12;
    if ( v12 > v11->m_slabSize || v13 > v11->m_end )
      v121 = (void *)hkLifoAllocator::allocateFromNewSlab(v11, v12);
    else
      v11->m_cur = v13;
  }
  else
  {
    v121 = 0i64;
  }
  result.m_enum = HK_SUCCESS;
  if ( (_DWORD)v3 )
  {
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (8 * v3 + 127) & 0xFFFFFF80;
    v122 = v14->m_cur;
    v16 = (char *)v122 + v15;
    if ( v15 > v14->m_slabSize || v16 > v14->m_end )
      v122 = (void *)hkLifoAllocator::allocateFromNewSlab(v14, v15);
    else
      v14->m_cur = v16;
  }
  else
  {
    v122 = 0i64;
  }
  v119 = 0;
  if ( (_DWORD)v3 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    p = v17->m_cur;
    v18 = (32 * v3 + 127) & 0xFFFFFF80;
    v19 = (char *)p + v18;
    if ( v18 > v17->m_slabSize || v19 > v17->m_end )
      p = (void *)hkLifoAllocator::allocateFromNewSlab(v17, v18);
    else
      v17->m_cur = v19;
  }
  else
  {
    p = 0i64;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)&v5->m_id;
  EnterCriticalSection(lpCriticalSection);
  v20 = v3;
  if ( (int)v3 > 0 )
  {
    p_m_constraintInstance = &breachedContacts->m_data.m_solver.m_constraintInstance;
    do
    {
      if ( *((_WORD *)p_m_constraintInstance - 3) == 1 )
      {
        v22 = (hkpContactPointProperties *)p_m_constraintInstance[1];
        p_m_uid = (hkpSimpleConstraintContactMgr *)&(*p_m_constraintInstance)[-2].m_uid;
        key[0] = -1;
        LOBYTE(defaultValueHitOut) = 0;
        Util = findUtil(p_m_uid, v22, (hkBool *)&defaultValueHitOut, key, (hkUFloat8 *)&maxImpulseOut);
        v25 = (unsigned __int64)Util;
        if ( Util )
        {
          v26 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                &v127,
                                (unsigned __int64)Util);
          if ( v26 > v127.m_hashMod )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v127,
              &hkContainerHeapAllocator::s_alloc,
              v25,
              (int)v6);
            v29 = (int)v6;
            v6 = (unsigned int)(v6 + 1);
            v30 = 3 * v29;
            v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v32 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v31[11] + 8i64))(v31[11], 216i64);
            v28 = v32;
            if ( v32 )
            {
              *(_DWORD *)(v32 + 16) = 0;
              *(_DWORD *)(v32 + 20) = -2147483644;
              *(_QWORD *)(v32 + 8) = v32 + 24;
            }
            else
            {
              v28 = 0i64;
            }
            *(_QWORD *)&m_cur[8 * v30] = v28;
            *(_QWORD *)&m_cur[8 * v30 + 16] = v25;
            *(_QWORD *)v28 = *(_QWORD *)(v25 + 32);
            *(_DWORD *)&m_cur[8 * v30 + 8] = (_BYTE)defaultValueHitOut != 0;
          }
          else
          {
            val_low = SLODWORD(v127.m_elem[v26].val);
            v28 = *(_QWORD *)&m_cur[24 * val_low];
            *(_DWORD *)&m_cur[24 * val_low + 8] |= (_BYTE)defaultValueHitOut != 0;
          }
          if ( *(_DWORD *)(v28 + 16) == (*(_DWORD *)(v28 + 20) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)(v28 + 8), 48);
          v33 = *(int *)(v28 + 16);
          *(_DWORD *)(v28 + 16) = v33 + 1;
          v34 = *(_QWORD *)(v28 + 8) + 48 * v33;
          *(_QWORD *)v34 = *(_QWORD *)v28 ^ (__int64)(*p_m_constraintInstance)->m_entities[0] ^ (__int64)(*p_m_constraintInstance)->m_entities[1];
          if ( *(hkpEntity **)v28 == (*p_m_constraintInstance)->m_entities[0] )
            v35 = *(float *)&FLOAT_1_0;
          else
            v35 = FLOAT_N1_0;
          v36 = key[0];
          *(float *)(v34 + 20) = v35;
          *(_DWORD *)(v34 + 8) = v36;
          *(_BYTE *)(v34 + 12) = 1;
          if ( *((_WORD *)p_m_constraintInstance - 4) )
            v37 = (__int64)p_m_constraintInstance[2];
          else
            v37 = (__int64)(&(*p_m_constraintInstance)[-1].m_internal->m_runtime
                          + 4
                          * (((char *)p_m_constraintInstance[1]
                            - 32 * HIWORD((*p_m_constraintInstance)[-1].m_internal->m_constraint)
                            - (char *)(*p_m_constraintInstance)[-1].m_internal
                            - 48)
                           / BYTE2((*p_m_constraintInstance)[-1].m_internal->m_entities[0])));
          *(_QWORD *)(v34 + 24) = v37;
          v38 = p_m_constraintInstance[1];
          *(_QWORD *)(v34 + 32) = v38;
          EncodedFloat = hkUFloat8::getEncodedFloat(BYTE2(v38->m_owner));
          defaultValueHitOut = (EncodedFloat + 243712) << 12;
          if ( EncodedFloat )
            v40 = defaultValueHitOut;
          else
            v40 = 0;
          *(_DWORD *)(v34 + 16) = v40;
          *(_QWORD *)(v34 + 40) = (char *)*p_m_constraintInstance - 120;
        }
      }
      else
      {
        v41 = *p_m_constraintInstance;
        v42 = ((__int64 (__fastcall *)(hkpConstraintData *))(*p_m_constraintInstance)->m_data->vfptr[6].__first_virtual_table_function__)((*p_m_constraintInstance)->m_data);
        v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v44 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v43[11] + 8i64))(v43[11], 216i64);
        v45 = v44;
        if ( v44 )
        {
          *(_DWORD *)(v44 + 16) = 0;
          *(_DWORD *)(v44 + 20) = -2147483644;
          *(_QWORD *)(v44 + 8) = v44 + 24;
        }
        else
        {
          v45 = 0i64;
        }
        v46 = v124;
        v47 = v122;
        *((_QWORD *)v121 + (int)v124) = v45;
        m_enum = result.m_enum;
        LODWORD(v124) = v46 + 1;
        v49 = *(int *)(v45 + 16);
        *(_DWORD *)(v45 + 16) = v49 + 1;
        v50 = *(_QWORD *)(v45 + 8) + 48 * v49;
        v47[m_enum] = v41;
        result.m_enum = m_enum + 1;
        if ( v42 )
          v51 = v41->m_entities[1];
        else
          v51 = v41->m_entities[0];
        *(_QWORD *)v45 = v51;
        v52 = (unsigned __int64)v41->m_entities[0] ^ (unsigned __int64)v51 ^ (unsigned __int64)v41->m_entities[1];
        v53 = v119;
        v54 = v119 + 1;
        *(_QWORD *)v50 = v52;
        *(_DWORD *)(v50 + 8) = -1;
        *(_BYTE *)(v50 + 12) = 0;
        v119 = v54;
        *(_QWORD *)(v50 + 32) = 0i64;
        *(_DWORD *)(v50 + 16) = 2139095022;
        *(_QWORD *)(v50 + 40) = 0i64;
        *(_DWORD *)(v50 + 20) = 1065353216;
        v55 = (__m128 *)((char *)p + 32 * v53);
        *(_QWORD *)(v50 + 24) = v55;
        hkpConstraintInstance::getPivotsInWorld(v41, &pivotAinW, &pivotBinW);
        p_pivotAinW = &pivotAinW;
        if ( v41->m_entities[0] != *(hkpEntity **)v45 )
          p_pivotAinW = &pivotBinW;
        *v55 = p_pivotAinW->m_quad;
        if ( v41->m_entities[0] == *(hkpEntity **)v45 )
          v57 = _mm_sub_ps(pivotBinW.m_quad, pivotAinW.m_quad);
        else
          v57 = _mm_sub_ps(pivotAinW.m_quad, pivotBinW.m_quad);
        v58 = _mm_mul_ps(v57, v57);
        v59 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                _mm_shuffle_ps(v58, v58, 170));
        v60 = _mm_rsqrt_ps(v59);
        v61 = _mm_andnot_ps(
                _mm_cmple_ps(v59, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v59), v60)),
                    _mm_mul_ps(v60, *(__m128 *)_xmm)),
                  v59));
        if ( v61.m128_f32[0] >= 0.00000011920929 )
        {
          v63 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                  _mm_shuffle_ps(v58, v58, 170));
          v64 = _mm_rsqrt_ps(v63);
          m_quad = _mm_mul_ps(
                     v57,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v63, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                         _mm_mul_ps(v64, *(__m128 *)_xmm))));
        }
        else
        {
          m_quad = transform.m_quad;
        }
        v55[1] = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, _mm_sub_ps((__m128)0i64, v61)), 196);
      }
      p_m_constraintInstance += 4;
      --v20;
    }
    while ( v20 );
    v5 = this;
  }
  if ( (int)v6 > 0 )
  {
    v65 = m_cur;
    v66 = 0;
    do
    {
      vfptr = v5->hkpContactImpulseLimitBreachedListener::vfptr;
      v68 = *(_QWORD *)v65;
      v69 = *((_QWORD *)v65 + 2);
      v136 = 0;
      v137 = -2147483392;
      v135 = v138;
      (*((void (__fastcall **)(hkpContactImpulseLimitBreachedListenerVtbl *, int *, __int64, char **, hkpPhysicsSystem *))vfptr->__vecDelDtor
       + 2))(
        vfptr,
        &defaultValueHitOut,
        v68,
        &v135,
        &sys);
      if ( !defaultValueHitOut )
      {
        if ( v136 )
        {
          m_size = array.m_size;
          v71 = *(hkProcess **)v68;
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
            m_size = array.m_size;
          }
          array.m_data[m_size] = v71;
          ++array.m_size;
          if ( v136 > 0 )
          {
            v72 = 0i64;
            do
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v69 + 48),
                &maxImpulseOut,
                *(unsigned int *)&v135[v72]);
              ++v66;
              v72 += 4i64;
            }
            while ( v66 < v136 );
            v5 = this;
          }
        }
        if ( *((_DWORD *)v65 + 2) )
          *(_BYTE *)(v69 + 40) = -1;
        v66 = 0;
        v73 = 0;
        if ( *(int *)(v68 + 16) > 0 )
        {
          v74 = 0i64;
          do
          {
            ++v73;
            v74 += 48i64;
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v68 + 8) + v74 - 24) + 28i64) = 1602224112;
          }
          while ( v73 < *(_DWORD *)(v68 + 16) );
        }
      }
      v75 = *(_QWORD *)v65;
      if ( *(_QWORD *)v65 )
      {
        v76 = *(_DWORD *)(v75 + 20);
        *(_DWORD *)(v75 + 16) = 0;
        if ( v76 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 8),
            48 * (v76 & 0x3FFFFFFF));
        *(_QWORD *)(v75 + 8) = 0i64;
        *(_DWORD *)(v75 + 20) = 0x80000000;
        v77 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v77[11] + 16i64))(v77[11], v75, 216i64);
      }
      v136 = 0;
      if ( v137 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v135, 4 * v137);
      v65 += 24;
      --v6;
    }
    while ( v6 );
  }
  if ( (int)v124 > 0 )
  {
    v78 = (hkProcess ***)v121;
    *(_QWORD *)key = (unsigned int)v124;
    v79 = (_BYTE *)v122 - (_BYTE *)v121;
    v124 = (_BYTE *)v122 - (_BYTE *)v121;
    while ( 1 )
    {
      v80 = *v78;
      v81 = *(__int64 *)((char *)v78 + v79);
      v82 = 0;
      v83 = **v78;
      v84 = (*v78)[1];
      m_outStream = v83[4].m_outStream;
      maxImpulseOut.m_enum = (*(float (__fastcall **)(_QWORD))(**(_QWORD **)(v81 + 24) + 88i64))(*(_QWORD *)(v81 + 24));
      hkUFloat8::operator=((hkUFloat8 *)&defaultValueHitOut, (const float *)&maxImpulseOut);
      hkUFloat8::getEncodedFloat(defaultValueHitOut);
      v86 = (unsigned __int64)m_outStream & 0xFFFFFFFFFFFFFFFEui64;
      if ( !v86 )
        goto LABEL_99;
      v87 = *(hkpConstraintData **)(v81 + 24);
      if ( v83 == *(hkProcess **)(v81 + 40) )
        PivotA = (hkVector4f *)hkpConstraintDataUtils::getPivotA(v87);
      else
        PivotA = hkpConstraintDataUtils::getPivotB(v87);
      m_displayHandler = (hkpShape *)v83->m_displayHandler;
      m_inStream = (hkpWorld *)v83->m_inStream;
      pivotBinW.m_quad = PivotA->m_quad;
      ClosestShapeKey = hkpConstraintPivotsUtil::findClosestShapeKey(m_inStream, m_displayHandler, &pivotBinW);
      *(_DWORD *)&v84->m_selectable.m_bool = ClosestShapeKey;
      if ( ClosestShapeKey != -1
        && (unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v86 + 48),
                              ClosestShapeKey,
                              0i64) )
      {
        v92 = 0i64;
        goto LABEL_100;
      }
      if ( *(_BYTE *)(v86 + 40) )
      {
        v82 = 1;
        v92 = 0i64;
      }
      else
      {
LABEL_99:
        v92 = 0i64;
        v86 = 0i64;
      }
LABEL_100:
      v93 = this;
      v94 = this->hkpContactImpulseLimitBreachedListener::vfptr;
      v135 = v138;
      v136 = 0;
      v137 = -2147483392;
      (*((void (__fastcall **)(hkpContactImpulseLimitBreachedListenerVtbl *, int *, hkProcess **, char **, hkpPhysicsSystem *))v94->__vecDelDtor
       + 2))(
        v94,
        &v119,
        v80,
        &v135,
        &sys);
      if ( !v119 && v86 )
      {
        v95 = v136;
        if ( v136 )
        {
          v96 = array.m_size;
          v97 = *v80;
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
            v96 = array.m_size;
          }
          array.m_data[v96] = v97;
          ++array.m_size;
          v95 = v136;
          v92 = 0i64;
        }
        v98 = 0;
        if ( v95 > 0 )
        {
          do
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v86 + 48),
              &result,
              *(unsigned int *)&v135[v92]);
            ++v98;
            v92 += 4i64;
          }
          while ( v98 < v136 );
        }
        if ( v82 )
          *(_BYTE *)(v86 + 40) = -1;
      }
      v99 = *v78;
      if ( *v78 )
      {
        v100 = *((_DWORD *)v99 + 5);
        *((_DWORD *)v99 + 4) = 0;
        if ( v100 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v99[1],
            48 * (v100 & 0x3FFFFFFF));
        v99[1] = 0i64;
        *((_DWORD *)v99 + 5) = 0x80000000;
        v101 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkProcess **, __int64))(*v101[11] + 16i64))(v101[11], v99, 216i64);
      }
      v136 = 0;
      if ( v137 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v135, 4 * v137);
      v79 = v124;
      ++v78;
      if ( !--*(_QWORD *)key )
        goto LABEL_119;
    }
  }
  v93 = this;
LABEL_119:
  LeaveCriticalSection(lpCriticalSection);
  v102 = v141;
  v103 = (32 * v141 + 127) & 0xFFFFFF80;
  v104 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v105 = p;
  v106 = (v103 + 15) & 0xFFFFFFF0;
  if ( v103 > v104->m_slabSize || (char *)p + v106 != v104->m_cur || v104->m_firstNonLifoEnd == p )
  {
    hkLifoAllocator::slowBlockFree(v104, (char *)p, v106);
    v105 = p;
  }
  else
  {
    v104->m_cur = p;
  }
  v107 = v128;
  if ( v128 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v105, 32 * v128);
  v108 = (8 * v102 + 127) & 0xFFFFFF80;
  v109 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v110 = v122;
  v111 = (v108 + 15) & 0xFFFFFFF0;
  if ( v108 > v109->m_slabSize || (char *)v122 + v111 != v109->m_cur || v109->m_firstNonLifoEnd == v122 )
  {
    hkLifoAllocator::slowBlockFree(v109, (char *)v122, v111);
    v110 = v122;
  }
  else
  {
    v109->m_cur = v122;
  }
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v110, 8 * v107);
  v112 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v113 = v121;
  if ( v108 > v112->m_slabSize || (char *)v121 + v111 != v112->m_cur || v112->m_firstNonLifoEnd == v121 )
  {
    hkLifoAllocator::slowBlockFree(v112, (char *)v121, v111);
    v113 = v121;
  }
  else
  {
    v112->m_cur = v121;
  }
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v113, 8 * v107);
  v114 = (24 * v102 + 127) & 0xFFFFFF80;
  v115 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v116 = (v114 + 15) & 0xFFFFFFF0;
  v117 = v114 <= v115->m_slabSize;
  v118 = v126;
  if ( v117 && (char *)v126 + v116 == v115->m_cur && v115->m_firstNonLifoEnd != v126 )
    v115->m_cur = v126;
  else
    hkLifoAllocator::slowBlockFree(v115, (char *)v126, v116);
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v118, 24 * (v107 & 0x3FFFFFFF));
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v127,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v127);
  hkpWorld::addPhysicsSystem((hkpWorld *)v93[-1].m_breakOffPartsListener, &sys);
  hkArrayBase<hkpEntity *>::_insertAt(
    &array,
    &hkContainerHeapAllocator::s_alloc,
    array.m_size,
    (hkProcess *const *)sys.m_rigidBodies.m_data,
    sys.m_rigidBodies.m_size);
  if ( array.m_size )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      (hkpWorld *)v93[-1].m_breakOffPartsListener,
      (hkpEntity **)array.m_data,
      (unsigned int)array.m_size,
      RR_MODE_RECOLLIDE_NARROWPHASE);
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::removeAll(&sys);
    hkReferencedObject::unlockAll();
  }
  hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
}m_size,
    (hkProcess *const *)sys.m_rigidBodies.m_data,
    sys.m_rigidBodies.m_size);
  if ( array.m_size )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      (hkpWorld *)v93[-1].m_breakOffPartsListener,
      (hkpEntity **)array.m_data,
      (unsigned int)array.m_size,
      RR_MODE_RECOLLIDE_NARROWPHASE);
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::removeAll(&sys);
    hkReferencedObject::unlockAll();
  }
  hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
  array.m_size = 

// File Line: 835
// RVA: 0xE0D240
void __fastcall hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback_forToi(
        hkpBreakOffPartsUtil *this,
        hkpContactImpulseLimitBreachedListenerInfo *breachedContact)
{
  hkCriticalSection *m_criticalSection; // rdi
  hkpContactPointProperties *m_properties; // rdx
  hkpSimpleConstraintContactMgr *p_m_uid; // rcx
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *Util; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v8; // r13
  hkpConstraintInstance *m_constraintInstance; // r8
  unsigned __int16 m_type; // r9
  __int64 v11; // r14
  __int64 m_entity; // rsi
  hkpRigidBody *v13; // r14
  hkContactPoint *m_contactPoint; // rax
  unsigned __int16 EncodedFloat; // ax
  hkResultEnum m_enum; // xmm0_4
  hkpConstraintInstance *v17; // rax
  float v18; // xmm0_4
  hkpBreakOffPartsListener *m_breakOffPartsListener; // rcx
  bool v20; // r12
  __int64 v21; // rbx
  int i; // edi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+30h] [rbp-D0h]
  __int64 v24; // [rsp+40h] [rbp-C0h] BYREF
  __int64 *v25; // [rsp+48h] [rbp-B8h]
  int v26; // [rsp+50h] [rbp-B0h]
  int v27; // [rsp+54h] [rbp-ACh]
  hkpRigidBody *v28; // [rsp+58h] [rbp-A8h] BYREF
  unsigned int v29; // [rsp+60h] [rbp-A0h]
  char v30; // [rsp+64h] [rbp-9Ch]
  hkResultEnum v31; // [rsp+68h] [rbp-98h]
  float v32; // [rsp+6Ch] [rbp-94h]
  hkContactPoint *v33; // [rsp+70h] [rbp-90h]
  hkpSolverResults *m_solverResult; // [rsp+78h] [rbp-88h]
  hkpPhysicsSystem sys; // [rsp+120h] [rbp+20h] BYREF
  char *v36; // [rsp+190h] [rbp+90h] BYREF
  int v37; // [rsp+198h] [rbp+98h]
  int v38; // [rsp+19Ch] [rbp+9Ch]
  char v39; // [rsp+1A0h] [rbp+A0h] BYREF
  hkBool defaultValueHitOut; // [rsp+5F0h] [rbp+4F0h] BYREF
  hkResult maxImpulseOut; // [rsp+5F8h] [rbp+4F8h] BYREF
  unsigned int key; // [rsp+600h] [rbp+500h] BYREF
  int v43; // [rsp+608h] [rbp+508h] BYREF

  hkpPhysicsSystem::hkpPhysicsSystem(&sys);
  m_criticalSection = this->m_criticalSection;
  lpCriticalSection = &m_criticalSection->m_section;
  EnterCriticalSection(&m_criticalSection->m_section);
  m_properties = breachedContact->m_data.m_single.m_properties;
  p_m_uid = (hkpSimpleConstraintContactMgr *)&breachedContact->m_data.m_solver.m_constraintInstance[-2].m_uid;
  key = -1;
  defaultValueHitOut.m_bool = 0;
  Util = findUtil(p_m_uid, m_properties, &defaultValueHitOut, &key, (hkUFloat8 *)&maxImpulseOut);
  v8 = Util;
  if ( !Util )
  {
LABEL_17:
    LeaveCriticalSection(&m_criticalSection->m_section);
    goto LABEL_18;
  }
  m_constraintInstance = breachedContact->m_data.m_solver.m_constraintInstance;
  m_type = breachedContact->m_data.m_solver.m_type;
  v38 = -2147483392;
  v36 = &v39;
  v37 = 0;
  v11 = (__int64)m_constraintInstance->m_entities[0] ^ (__int64)m_constraintInstance->m_entities[1];
  m_entity = (__int64)Util->m_entity;
  v25 = (__int64 *)&v28;
  v13 = (hkpRigidBody *)(m_entity ^ v11);
  v26 = 1;
  v27 = -2147483644;
  v24 = m_entity;
  v28 = v13;
  v29 = key;
  if ( m_type )
    m_contactPoint = breachedContact->m_data.m_single.m_contactPoint;
  else
    m_contactPoint = (hkContactPoint *)(&m_constraintInstance[-1].m_internal->m_runtime
                                      + 4
                                      * (((char *)&breachedContact->m_data.m_solver.m_solverResult[-4
                                                                                                 * HIWORD(m_constraintInstance[-1].m_internal->m_constraint)]
                                        - (char *)m_constraintInstance[-1].m_internal
                                        - 48)
                                       / BYTE2(m_constraintInstance[-1].m_internal->m_entities[0])));
  v33 = m_contactPoint;
  m_solverResult = breachedContact->m_data.m_solver.m_solverResult;
  EncodedFloat = hkUFloat8::getEncodedFloat(BYTE2(m_solverResult[2].m_impulseApplied));
  maxImpulseOut.m_enum = (EncodedFloat + 243712) << 12;
  if ( EncodedFloat )
    m_enum = maxImpulseOut.m_enum;
  else
    m_enum = HK_SUCCESS;
  v17 = breachedContact->m_data.m_solver.m_constraintInstance;
  v31 = m_enum;
  if ( (hkpEntity *)m_entity == v17->m_entities[0] )
    v18 = *(float *)&FLOAT_1_0;
  else
    v18 = FLOAT_N1_0;
  m_breakOffPartsListener = this->m_breakOffPartsListener;
  v32 = v18;
  v30 = 1;
  m_breakOffPartsListener->vfptr->breakOffSubPart(
    m_breakOffPartsListener,
    (hkResult *)&v43,
    (hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *)&v24,
    (hkArray<unsigned int,hkContainerHeapAllocator> *)&v36,
    &sys);
  if ( v43 == 1 )
  {
    v26 = 0;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v25, 48 * (v27 & 0x3FFFFFFF));
    v25 = 0i64;
    v27 = 0x80000000;
    v37 = 0;
    if ( v38 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v36, 4 * v38);
    v36 = 0i64;
    v38 = 0x80000000;
    goto LABEL_17;
  }
  v20 = v37 != 0;
  v21 = 0i64;
  for ( i = 0; i < v37; v21 += 4i64 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
      &v8->m_shapeKeyToMaxImpulse.m_map,
      &maxImpulseOut,
      *(unsigned int *)&v36[v21]);
    ++i;
  }
  if ( defaultValueHitOut.m_bool )
    v8->m_maxImpulse.m_value = -1;
  v26 = 0;
  if ( v27 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v25, 48 * (v27 & 0x3FFFFFFF));
  v25 = 0i64;
  v27 = 0x80000000;
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v36, 4 * v38);
  v36 = 0i64;
  v38 = 0x80000000;
  LeaveCriticalSection(lpCriticalSection);
  if ( *(_BYTE *)(m_entity + 352) != 5 )
    v13 = (hkpRigidBody *)m_entity;
  hkpWorld::addPhysicsSystem(this->m_world, &sys);
  if ( v20 )
  {
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::addRigidBody(&sys, v13);
    hkReferencedObject::unlockAll();
  }
  if ( sys.m_rigidBodies.m_size )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      this->m_world,
      sys.m_rigidBodies.m_data,
      (unsigned int)sys.m_rigidBodies.m_size,
      RR_MODE_RECOLLIDE_NARROWPHASE);
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::removeAll(&sys);
    hkReferencedObject::unlockAll();
  }
LABEL_18:
  hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
}

// File Line: 943
// RVA: 0xE0D750
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::findWeakestPoint(
        hkpBreakOffPartsUtil::LimitContactImpulseUtil *this,
        unsigned int *keyOut,
        float *weakestImpulseOut)
{
  unsigned __int16 v6; // ax
  __int64 m_hashMod; // r9
  int v8; // r8d
  unsigned __int8 val; // cl
  __int64 v10; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v12; // edx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v13; // r8
  __int64 v14; // r9
  int v15; // r8d
  __int64 v16; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v17; // rax
  unsigned __int16 EncodedFloat; // ax

  if ( (this->m_shapeKeyToMaxImpulse.m_map.m_numElems & 0x7FFFFFFF) != 0 )
  {
    m_hashMod = this->m_shapeKeyToMaxImpulse.m_map.m_hashMod;
    v8 = 0;
    val = -1;
    v10 = 0i64;
    if ( m_hashMod >= 0 )
    {
      m_elem = this->m_shapeKeyToMaxImpulse.m_map.m_elem;
      do
      {
        if ( m_elem->key != -1i64 )
          break;
        ++v10;
        ++v8;
        ++m_elem;
      }
      while ( v10 <= m_hashMod );
    }
    v12 = v8;
    if ( v8 <= this->m_shapeKeyToMaxImpulse.m_map.m_hashMod )
    {
      do
      {
        v13 = this->m_shapeKeyToMaxImpulse.m_map.m_elem;
        if ( LOBYTE(v13[v12].val) < val )
        {
          val = v13[v12].val;
          *keyOut = v13[v12].key;
        }
        v14 = this->m_shapeKeyToMaxImpulse.m_map.m_hashMod;
        v15 = v12 + 1;
        v16 = v15;
        if ( v15 <= v14 )
        {
          v17 = &this->m_shapeKeyToMaxImpulse.m_map.m_elem[v15];
          do
          {
            if ( v17->key != -1i64 )
              break;
            ++v16;
            ++v15;
            ++v17;
          }
          while ( v16 <= v14 );
        }
        v12 = v15;
      }
      while ( v15 <= this->m_shapeKeyToMaxImpulse.m_map.m_hashMod );
    }
    EncodedFloat = hkUFloat8::getEncodedFloat(val);
    if ( EncodedFloat )
    {
      *(_DWORD *)weakestImpulseOut = (EncodedFloat + 243712) << 12;
      return;
    }
  }
  else
  {
    *keyOut = -1;
    v6 = hkUFloat8::getEncodedFloat(this->m_maxImpulse.m_value);
    if ( v6 )
    {
      *(_DWORD *)weakestImpulseOut = (v6 + 243712) << 12;
      return;
    }
  }
  *weakestImpulseOut = 0.0;
}

// File Line: 966
// RVA: 0xE0C330
void __fastcall hkpBreakOffPartsUtil::performAttachments(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // rdi
  hkpContactImpulseLimitBreachedListener *v5; // rdx

  v2 = 0i64;
  v5 = &this->hkpContactImpulseLimitBreachedListener;
  if ( !this )
    v5 = 0i64;
  hkpWorld::addContactImpulseLimitBreachedListener(world, v5);
  if ( this )
    v2 = &this->hkpConstraintListener;
  hkpWorld::addConstraintListener(world, v2);
}

// File Line: 972
// RVA: 0xE0C390
void __fastcall hkpBreakOffPartsUtil::performDetachments(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpContactImpulseLimitBreachedListener *v2; // rdi
  hkpConstraintListener *v5; // rdx

  v2 = 0i64;
  v5 = &this->hkpConstraintListener;
  if ( !this )
    v5 = 0i64;
  hkpWorld::removeConstraintListener(world, v5);
  if ( this )
    v2 = &this->hkpContactImpulseLimitBreachedListener;
  hkpWorld::removeContactImpulseLimitBreachedListener(world, v2);
}

