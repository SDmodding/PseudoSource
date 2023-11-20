// File Line: 34
// RVA: 0xE0D9B0
signed __int64 __fastcall hkpBreakOffPartsUtil::GameControlFunctor::test(hkpBreakOffPartsUtil::GameControlFunctor *this, hkpRigidBody *limitedBody, hkpRigidBody *otherBody, const unsigned int key)
{
  return 3i64;
}

// File Line: 43
// RVA: 0xE0BD00
void __fastcall hkpBreakOffPartsUtil::hkpBreakOffPartsUtil(hkpBreakOffPartsUtil *this, hkpBreakOffPartsListener *listenerInterface)
{
  hkpBreakOffPartsListener *v2; // rbx
  hkpBreakOffPartsUtil *v3; // rdi
  _QWORD **v4; // rax
  hkCriticalSection *v5; // rax
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkReferencedObject *v8; // rbx
  hkReferencedObject *v9; // rcx

  v2 = listenerInterface;
  v3 = this;
  hkpWorldExtension::hkpWorldExtension((hkpWorldExtension *)&this->vfptr, 1000);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpWorldExtension'};
  v3->vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpContactImpulseLimitBreachedListener'};
  v3->vfptr = (hkpEntityListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpEntityListener'};
  v3->vfptr = (hkpConstraintListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpConstraintListener'};
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 40i64);
  if ( v5 )
    hkCriticalSection::hkCriticalSection(v5, 1);
  v3->m_criticalSection = v5;
  v3->m_breakOffPartsListener = v2;
  v3->m_breakOffGameControlFunctor.m_pntr = 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 16i64);
  v8 = (hkReferencedObject *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpBreakOffPartsUtil::GameControlFunctor::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  if ( v8 )
    hkReferencedObject::addReference(v8);
  v9 = (hkReferencedObject *)&v3->m_breakOffGameControlFunctor.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v3->m_breakOffGameControlFunctor.m_pntr = (hkpBreakOffPartsUtil::GameControlFunctor *)v8;
  hkReferencedObject::removeReference(v8);
}

// File Line: 50
// RVA: 0xE0C3F0
void __fastcall hkpBreakOffPartsUtil::~hkpBreakOffPartsUtil(hkpBreakOffPartsUtil *this)
{
  hkCriticalSection *v1; // rdi
  hkpBreakOffPartsUtil *v2; // rbx
  _QWORD **v3; // rax
  hkReferencedObject *v4; // rcx

  v1 = this->m_criticalSection;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpWorldExtension'};
  this->vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpContactImpulseLimitBreachedListener'};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpEntityListener'};
  this->vfptr = (hkpConstraintListenerVtbl *)&hkpBreakOffPartsUtil::`vftable'{for `hkpConstraintListener'};
  if ( v1 )
  {
    DeleteCriticalSection(&v1->m_section);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 40i64);
  }
  v4 = (hkReferencedObject *)&v2->m_breakOffGameControlFunctor.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v2->m_breakOffGameControlFunctor.m_pntr = 0i64;
  v2->vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable';
  v2->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable';
  v2->vfptr = (hkpContactImpulseLimitBreachedListenerVtbl *)&hkpContactImpulseLimitBreachedListener::`vftable';
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 55
// RVA: 0xE0BFF0
void __fastcall hkpBreakOffPartsUtil::removeKeysFromListShape(hkpEntity *entity, unsigned int *keysToRemove, int numKeys)
{
  hkpShape *v3; // rbp
  hkAabbUint32 *v4; // r15
  unsigned int *v5; // rsi
  hkpEntity *v6; // r14
  __int64 v7; // rdi
  unsigned __int64 v8; // rbx
  hkpShapeContainer *v9; // r8
  __int64 i; // rbx
  __int64 j; // rbx
  unsigned int *v12; // rbp
  __int64 v13; // rdi
  __int64 v14; // rsi
  signed __int64 v15; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> shapesToRemove; // [rsp+20h] [rbp-58h]
  hkpRemoveTerminalsMoppModifier v17; // [rsp+30h] [rbp-48h]

  v3 = entity->m_collidable.m_shape;
  v4 = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  v5 = keysToRemove;
  v6 = entity;
  v7 = numKeys;
  if ( v3->m_type.m_storage != 8 )
  {
    if ( v3->m_type.m_storage != 9 )
      return;
    v8 = v3[2].m_userData;
    shapesToRemove.m_size = numKeys;
    shapesToRemove.m_capacityAndFlags = numKeys | 0x80000000;
    shapesToRemove.m_data = keysToRemove;
    v9 = (hkpShapeContainer *)(v8 + 32);
    if ( !v8 )
      v9 = 0i64;
    hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
      &v17,
      *(hkpMoppCode **)&v3[1].m_memSizeAndFlags,
      v9,
      &shapesToRemove);
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(&v17, *(hkpMoppCode **)&v3[1].m_memSizeAndFlags);
    if ( *(_BYTE *)(v8 + 16) != 8 )
    {
      hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v17);
      shapesToRemove.m_size = 0;
      if ( shapesToRemove.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          shapesToRemove.m_data,
          4 * shapesToRemove.m_capacityAndFlags);
      goto LABEL_11;
    }
    v3 = (hkpShape *)v8;
    hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(&v17);
    shapesToRemove.m_size = 0;
    if ( shapesToRemove.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        shapesToRemove.m_data,
        4 * shapesToRemove.m_capacityAndFlags);
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_capacityAndFlags = 2147483648;
  }
  for ( i = 0i64; i < v7; ++i )
    hkpListShape::disableChild((hkpListShape *)v3, v5[i]);
LABEL_11:
  if ( v4 )
  {
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_size = 0;
    shapesToRemove.m_capacityAndFlags = -1;
    for ( j = 0i64; j < v7; ++j )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v5[j],
        1ui64);
    v12 = v6->m_collidable.m_boundingVolumeData.m_childShapeKeys;
    v13 = 0i64;
    v14 = v6->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( (signed int)v6->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs > 0 )
    {
      v15 = (signed __int64)&v4->m_max[2];
      do
      {
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
                             v12[v13],
                             0i64) )
        {
          *(_DWORD *)(v15 - 20) = 2147418112;
          *(_QWORD *)(v15 - 16) = 2147418112i64;
          *(_QWORD *)(v15 - 4) = 0i64;
        }
        ++v13;
        v15 += 32i64;
      }
      while ( v13 < v14 );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&shapesToRemove);
  }
}moryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&sh

// File Line: 120
// RVA: 0xE0C220
void __fastcall hkpBreakOffPartsUtil::removeKeysFromListShapeByEnabledList(hkpEntity *entity, hkBitField *enabledKeys)
{
  hkpShape *v2; // rbx
  hkAabbUint32 *v3; // rbp
  hkBitField *v4; // rsi
  hkpEntity *v5; // rdi
  hkpShape *v6; // r14
  int v7; // er9
  __int64 v8; // r10
  signed __int64 v9; // rax
  hkpRemoveTerminalsMoppModifier2 v10; // [rsp+20h] [rbp-48h]

  v2 = entity->m_collidable.m_shape;
  v3 = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  v4 = enabledKeys;
  v5 = entity;
  if ( v2->m_type.m_storage != 8 )
  {
    if ( v2->m_type.m_storage != 9 )
      return;
    v6 = (hkpShape *)v2[2].m_userData;
    hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2(
      &v10,
      *(hkpMoppCode **)&v2[1].m_memSizeAndFlags,
      enabledKeys);
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(
      (hkpRemoveTerminalsMoppModifier *)&v10.vfptr,
      *(hkpMoppCode **)&v2[1].m_memSizeAndFlags);
    if ( v6->m_type.m_storage != 8 )
    {
      hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier((hkpRemoveTerminalsMoppModifier *)&v10.vfptr);
      goto LABEL_6;
    }
    v2 = v6;
    hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier((hkpRemoveTerminalsMoppModifier *)&v10.vfptr);
  }
  hkpListShape::setEnabledChildren((hkpListShape *)v2, v4);
LABEL_6:
  if ( v3 )
  {
    v7 = 0;
    v8 = v5->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( (signed int)v5->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs > 0 )
    {
      v9 = (signed __int64)&v3->m_max[2];
      do
      {
        if ( !((v4->m_storage.m_words.m_data[(signed __int64)v7 >> 5] >> (v7 & 0x1F)) & 1) )
        {
          *(_DWORD *)(v9 - 20) = 2147418112;
          *(_QWORD *)(v9 - 16) = 2147418112i64;
          *(_QWORD *)(v9 - 4) = 0i64;
        }
        ++v7;
        v9 += 32i64;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 174
// RVA: 0xE0D640
void __fastcall hkpBreakOffPartsUtil::worldDeletedCallback(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpBreakOffPartsUtil *v2; // rbx
  hkpContactImpulseLimitBreachedListener *v3; // rdx

  v2 = this;
  if ( this )
    v3 = (hkpContactImpulseLimitBreachedListener *)&this->vfptr;
  else
    v3 = 0i64;
  hkpWorld::removeContactImpulseLimitBreachedListener(this->m_world, v3);
  v2->m_world = 0i64;
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
}

// File Line: 181
// RVA: 0xE0D680
void __fastcall hkpBreakOffPartsUtil::entityRemovedCallback(hkpBreakOffPartsUtil *this, hkpEntity *entity)
{
  ;
}

// File Line: 188
// RVA: 0xE0D8F0
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::LimitContactImpulseUtil(hkpBreakOffPartsUtil::LimitContactImpulseUtil *this, hkpBreakOffPartsUtil *breakUtil, hkpEntity *entity)
{
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v3; // rbx

  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_entity = entity;
  this->m_maxConstraintImpulse = 3.40282e38;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable'{for `hkpCollisionListener'};
  this->m_shapeKeyToMaxImpulse.m_map.m_hashMod = -1;
  this->m_shapeKeyToMaxImpulse.m_map.m_elem = 0i64;
  this->m_shapeKeyToMaxImpulse.m_map.m_numElems = 0;
  this->m_breakOffUtil = breakUtil;
  this->m_maxImpulse.m_value = -1;
  entity->m_limitContactImpulseUtilAndFlag = this;
  hkpEntity::addContactListener(entity, (hkpContactListener *)&this->vfptr);
  hkReferencedObject::addReference((hkReferencedObject *)&v3->m_breakOffUtil->vfptr);
}

// File Line: 197
// RVA: 0xE0D880
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::~LimitContactImpulseUtil(hkpBreakOffPartsUtil::LimitContactImpulseUtil *this)
{
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v1; // rdi

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtil::`vftable'{for `hkpCollisionListener'};
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_breakOffUtil->vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_shapeKeyToMaxImpulse.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_shapeKeyToMaxImpulse);
  v1->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 202
// RVA: 0xE0D9C0
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__fastcall hkpBreakOffPartsUtil::createLimitContactImpulseUtil(hkpBreakOffPartsUtil *this, hkpEntity *entity)
{
  hkpBreakOffPartsUtil *v2; // rsi
  hkpEntity *v3; // rdi
  _QWORD **v4; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *result; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v6; // rbx

  v2 = this;
  v3 = entity;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                                              v4[11],
                                                              80i64);
  v6 = result;
  if ( result )
  {
    hkpBreakOffPartsUtil::LimitContactImpulseUtil::LimitContactImpulseUtil(result, v2, v3);
    v6->vfptr = (hkBaseObjectVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::`vftable'{for `hkReferencedObject'};
    v6->vfptr = (hkpContactListenerVtbl *)&hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::`vftable'{for `hkpCollisionListener'};
    result = v6;
    v3->m_limitContactImpulseUtilAndFlag = (void *)((_QWORD)v3->m_limitContactImpulseUtilAndFlag | 1i64);
  }
  return result;
}

// File Line: 214
// RVA: 0xE0BE10
void __fastcall hkpBreakOffPartsUtil::markPieceBreakable(hkpBreakOffPartsUtil *this, hkpEntity *entity, unsigned int key, float maxImpulse)
{
  unsigned __int64 v4; // rdi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  unsigned __int8 v6; // dl
  hkUFloat8 v7; // [rsp+50h] [rbp+18h]
  float fv; // [rsp+58h] [rbp+20h]

  v4 = key;
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v5 )
    v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((__int64 (*)(void))this->vfptr[3].__vecDelDtor)();
  fv = maxImpulse;
  hkUFloat8::operator=(&v7, &fv);
  v6 = v7.m_value;
  if ( (signed int)(unsigned __int8)v7.m_value < 1 )
    v6 = 1;
  v7.m_value = v6;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    v5 + 3,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v4,
    v6);
}

// File Line: 223
// RVA: 0xE0BEA0
void __fastcall hkpBreakOffPartsUtil::markEntityBreakable(hkpBreakOffPartsUtil *this, hkpEntity *entity, float maxImpulse)
{
  unsigned __int64 v3; // rbx
  char v4; // dl
  float fv; // [rsp+48h] [rbp+10h]
  hkUFloat8 v6; // [rsp+50h] [rbp+18h]

  v3 = (_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v3 )
    v3 = ((__int64 (*)(void))this->vfptr[3].__vecDelDtor)();
  fv = maxImpulse;
  hkUFloat8::operator=(&v6, &fv);
  v4 = v6.m_value;
  if ( (signed int)(unsigned __int8)v6.m_value < 1 )
    v4 = 1;
  *(_BYTE *)(v3 + 40) = v4;
}

// File Line: 230
// RVA: 0xE0BF90
void __fastcall hkpBreakOffPartsUtil::unmarkPieceBreakable(hkpBreakOffPartsUtil *this, hkpEntity *entity, unsigned int key)
{
  hkpEntity *v3; // rdi
  hkpBreakOffPartsUtil *v4; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  hkResult result; // [rsp+38h] [rbp+10h]

  v3 = entity;
  v4 = this;
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( v5 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(v5 + 3, &result, key);
    if ( !(v5[3].m_numElems & 0x7FFFFFFF) )
      hkpBreakOffPartsUtil::unmarkEntityBreakable(v4, v3);
  }
}

// File Line: 245
// RVA: 0xE0BF40
void __fastcall hkpBreakOffPartsUtil::unmarkEntityBreakable(hkpBreakOffPartsUtil *this, hkpEntity *entity)
{
  hkpEntity *v2; // rdi
  unsigned __int64 v3; // rbx

  v2 = entity;
  v3 = (_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    hkpEntity::removeContactListener(entity, (hkpContactListener *)(v3 + 16));
    (**(void (__fastcall ***)(unsigned __int64, signed __int64))v3)(v3, 1i64);
    v2->m_limitContactImpulseUtilAndFlag = 0i64;
  }
}

// File Line: 256
// RVA: 0xE0BF00
void __fastcall hkpBreakOffPartsUtil::setMaxConstraintImpulse(hkpBreakOffPartsUtil *this, hkpEntity *entity, float maxConstraintImpulse)
{
  unsigned __int64 v3; // rax

  v3 = (_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( !v3 )
    v3 = ((__int64 (*)(void))this->vfptr[3].__vecDelDtor)();
  *(float *)(v3 + 44) = maxConstraintImpulse;
}

// File Line: 262
// RVA: 0xE0D970
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::limitContactImpulse(hkpBreakOffPartsUtil::LimitContactImpulseUtil *this, hkUFloat8 *maxImpulse, bool isEntityIdSmaller, hkpContactPointProperties *properties)
{
  unsigned __int8 v4; // al
  unsigned __int8 v5; // cl

  v4 = maxImpulse->m_value;
  if ( maxImpulse->m_value )
  {
    v5 = properties->m_maxImpulse.m_value;
    if ( !v5 || v4 < v5 )
    {
      properties->m_flags &= 0xFDu;
      properties->m_maxImpulse.m_value = v4;
      if ( isEntityIdSmaller )
        properties->m_flags |= 4u;
      else
        properties->m_flags &= 0xFBu;
    }
  }
}

// File Line: 290
// RVA: 0xE0DA60
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault::contactPointAddedCallback(hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault *this, hkpContactPointAddedEvent *event)
{
  hkpContactPointAddedEvent *v2; // rbx
  hkpBreakOffPartsUtil::LimitContactImpulseUtilDefault *v3; // rdi
  hkpCdBody *v4; // r8
  hkpCdBody *v5; // rax
  hkpCdBody *i; // r9
  unsigned int v7; // er14
  hkpCdBody *v8; // rax
  hkpCdBody *v9; // rdx
  hkpCdBody *j; // rcx
  hkpDynamicsContactMgr *v11; // rax
  hkpRigidBody *v12; // rbp
  hkpRigidBody *v13; // rsi
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v14; // rcx
  __int64 v15; // rbp
  int v16; // eax
  __int64 v17; // r8
  bool v18; // cf
  int v19; // eax
  hkUFloat8 result; // [rsp+50h] [rbp+8h]

  v2 = event;
  v3 = this;
  if ( this->m_shapeKeyToMaxImpulse.m_map.m_elem[1].key )
  {
    v4 = event->m_bodyA;
    v5 = event->m_bodyA->m_parent;
    for ( i = event->m_bodyA; v5; v5 = v5->m_parent )
    {
      i = v4;
      v4 = v5;
    }
    v7 = i->m_shapeKey;
    if ( (hkpCdBody *)&this->vfptr->contactPointAddedCallback != v4 )
    {
      v8 = event->m_bodyB;
      v9 = v8;
      for ( j = v8->m_parent; j; j = j->m_parent )
      {
        v9 = v8;
        v8 = j;
      }
      v7 = v9->m_shapeKey;
    }
    if ( !((unsigned int (*)(void))v2->m_internalContactMgr->vfptr[6].__first_virtual_table_function__)() )
    {
      v11 = v2->m_internalContactMgr;
      v12 = (hkpRigidBody *)v3->vfptr;
      v13 = (hkpRigidBody *)v11[5].vfptr;
      v14 = (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)&v3[-1].m_breakOffUtil;
      if ( v13 == v12 )
      {
        v15 = *(_QWORD *)&v11[5].m_memSizeAndFlags;
        hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(
          v14,
          &result,
          v7,
          *(hkpRigidBody **)&v11[5].m_memSizeAndFlags);
        v16 = (unsigned __int64)(*(__int64 (__fastcall **)(unsigned __int64, hkpRigidBody *, __int64, _QWORD, hkUFloat8 *))(*(_QWORD *)v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
                                  v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
                                  v13,
                                  v15,
                                  v7,
                                  &result)
            - 1;
        if ( v16 )
        {
          if ( v16 == 1 )
            return;
          v18 = v13->m_uid < *(_DWORD *)(v15 + 308);
        }
        else
        {
          result.m_value = 1;
          v18 = v13->m_uid < *(_DWORD *)(v15 + 308);
        }
      }
      else
      {
        hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(v14, &result, v7, v13);
        v19 = (unsigned __int64)(*(__int64 (__fastcall **)(unsigned __int64, hkpRigidBody *, hkpRigidBody *, _QWORD, hkUFloat8 *))(*(_QWORD *)v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
                                  v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
                                  v12,
                                  v13,
                                  v7,
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
        v18 = v12->m_uid < v13->m_uid;
      }
      LOBYTE(v17) = v18;
      (*(void (__fastcall **)(hkpBreakOffPartsUtil **, hkUFloat8 *, __int64, hkpContactPointProperties *))&v3[-1].m_breakOffUtil->m_id)(
        &v3[-1].m_breakOffUtil,
        &result,
        v17,
        v2->m_contactPointProperties);
    }
  }
}

// File Line: 382
// RVA: 0xE0DD50
__int64 __fastcall findTopShapeKey(const unsigned int *leafKeyPtr, int sizeOfKeyStorage)
{
  unsigned int v2; // er8
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
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly::contactPointCallback(hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly *this, hkpContactPointEvent *event)
{
  hkpContactPointEvent *v2; // rbx
  hkpBreakOffPartsUtil::LimitContactImpulseUtilCpuOnly *v3; // rsi
  __int64 v4; // r8
  unsigned int *v5; // rax
  unsigned int v6; // edi
  unsigned __int64 i; // rcx
  hkpRigidBody *v8; // r15
  hkpRigidBody *v9; // rbp
  int v10; // eax
  __int64 v11; // r8
  hkUFloat8 result; // [rsp+50h] [rbp+8h]

  v2 = event;
  v3 = this;
  if ( this->m_shapeKeyToMaxImpulse.m_map.m_elem[1].key && event->m_contactPointProperties->m_flags & 1 )
  {
    v4 = event->m_source;
    v5 = 0i64;
    if ( event->m_bodies[v4]->m_numShapeKeysInContactPointProperties > 0u )
      v5 = &event->m_shapeKeyStorage[(signed int)(v4
                                                * (unsigned __int8)event->m_bodies[0]->m_numShapeKeysInContactPointProperties)];
    v6 = -1;
    for ( i = (unsigned __int64)&v5[BYTE1(this->vfptr[5].~hkpContactListener)]; *v5 != -1; ++v5 )
    {
      if ( (unsigned __int64)v5 >= i )
        break;
      v6 = *v5;
    }
    if ( (_DWORD)v4 )
    {
      v8 = event->m_bodies[v4];
      v9 = (hkpRigidBody *)*((_QWORD *)&event->m_source + 2 - v4);
    }
    else
    {
      v8 = event->m_bodies[0];
      v9 = event->m_bodies[1];
    }
    hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(
      (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)&v3[-1].m_breakOffUtil,
      &result,
      v6,
      v9);
    v10 = (unsigned __int64)(*(__int64 (__fastcall **)(unsigned __int64, hkpRigidBody *, hkpRigidBody *, _QWORD, hkUFloat8 *))(*(_QWORD *)v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val + 24i64))(
                              v3->m_shapeKeyToMaxImpulse.m_map.m_elem[4].val,
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
    (*(void (__fastcall **)(hkpBreakOffPartsUtil **, hkUFloat8 *, __int64, hkpContactPointProperties *))&v3[-1].m_breakOffUtil->m_id)(
      &v3[-1].m_breakOffUtil,
      &result,
      v11,
      v2->m_contactPointProperties);
  }
}

// File Line: 466
// RVA: 0xE0D690
void __fastcall hkpBreakOffPartsUtil::constraintAddedCallback(hkpBreakOffPartsUtil *this, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rbx
  unsigned __int64 v3; // r8
  hkpEntity *v4; // rax
  hkpConstraintData *v5; // rbx
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // r8
  float v8; // xmm2_4
  float v9; // xmm1_4

  v2 = constraint;
  if ( ((unsigned int (*)(void))constraint->m_data->vfptr[1].__first_virtual_table_function__)() != 11 )
  {
    v3 = (unsigned __int64)v2->m_entities[0]->m_limitContactImpulseUtilAndFlag;
    v4 = v2->m_entities[1];
    v5 = v2->m_data;
    v6 = (_QWORD)v4->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
    v7 = v3 & 0xFFFFFFFFFFFFFFFEui64;
    if ( v7 || v6 )
    {
      v8 = FLOAT_3_40282e38;
      v9 = FLOAT_3_40282e38;
      if ( v7 )
        v8 = *(float *)(v7 + 44);
      if ( v6 )
        v9 = *(float *)(v6 + 44);
      v5->vfptr[6].__vecDelDtor((hkBaseObject *)&v5->vfptr, v9 <= v8);
    }
    ((void (__fastcall *)(hkpConstraintData *))v5->vfptr[4].__vecDelDtor)(v5);
  }
}

// File Line: 510
// RVA: 0xE0DD80
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__fastcall findUtil(hkpSimpleConstraintContactMgr *mgr, hkpContactPointProperties *props, hkBool *defaultValueHitOut, unsigned int *key, hkUFloat8 *maxImpulseOut)
{
  hkBaseObjectVtbl *v5; // rax
  unsigned int *v6; // r14
  hkBool *v7; // r15
  hkpContactPointProperties *v8; // rsi
  hkpSimpleConstraintContactMgr *v9; // rdi
  unsigned int v10; // ebx
  __int64 v11; // rax
  int v12; // edx
  BOOL v13; // er9
  unsigned int v14; // ebx
  __int64 v15; // rax
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rbx
  hkpSimpleContactConstraintAtom *v18; // r10
  __int64 v19; // rax
  signed int v20; // edx
  signed int *v21; // rcx
  unsigned __int64 i; // r8
  unsigned int v23; // eax

  v5 = mgr->vfptr;
  v6 = key;
  v7 = defaultValueHitOut;
  v8 = props;
  v9 = mgr;
  if ( props->m_flags & 4 )
  {
    v10 = *(_DWORD *)(*(_QWORD *)(((__int64 (*)(void))v5[8].__vecDelDtor)() + 40) + 308i64);
    v11 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))v9->vfptr[8].__vecDelDtor)(v9);
    v12 = 0;
    v13 = v10 >= *(_DWORD *)(*(_QWORD *)(v11 + 48) + 308i64);
  }
  else
  {
    v14 = *(_DWORD *)(*(_QWORD *)(((__int64 (*)(void))v5[8].__vecDelDtor)() + 40) + 308i64);
    v15 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))v9->vfptr[8].__vecDelDtor)(v9);
    v12 = 0;
    v13 = v14 < *(_DWORD *)(*(_QWORD *)(v15 + 48) + 308i64);
  }
  v16 = (unsigned __int64)v9->m_constraint.m_entities[v13]->m_limitContactImpulseUtilAndFlag;
  maxImpulseOut->m_value = (char)v8->m_maxImpulse;
  v17 = v16 & 0xFFFFFFFFFFFFFFFEui64;
  if ( v17 )
  {
    v18 = v9->m_contactConstraintData.m_atom;
    if ( v13 )
      v12 = (unsigned __int8)v18->m_numUserDatasForBodyA;
    v19 = v12;
    v20 = -1;
    v21 = (signed int *)((char *)&v8->0 + 4 * (v19 + 8));
    for ( i = (unsigned __int64)&v21[*((unsigned __int8 *)&v18->m_numUserDatasForBodyA + v13)]; *v21 != -1; ++v21 )
    {
      if ( (unsigned __int64)v21 >= i )
        break;
      v20 = *v21;
    }
    *v6 = v20;
    v23 = *((_DWORD *)&v8[1].m_impulseApplied + v13 * (unsigned __int8)v18->m_numUserDatasForBodyA);
    *v6 = v23;
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
      v7->m_bool = 1;
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v17;
    }
  }
  return 0i64;
}

// File Line: 557
// RVA: 0xE0DED0
hkpBreakOffPartsUtil::LimitContactImpulseUtil *__usercall findUtil_0@<rax>(hkpRigidBody *body@<rcx>, hkpConstraintInstance *constraint@<rdx>, hkBool *defaultValueHitOut@<r8>, unsigned int *key@<r9>, float a5@<xmm0>, hkUFloat8 *maxImpulseOut)
{
  hkpRigidBody *v6; // rsi
  unsigned int *v7; // r15
  hkBool *v8; // r14
  hkpConstraintInstance *v9; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int16 v11; // ax
  float v12; // xmm0_4
  hkpConstraintData *v13; // rcx
  __m128i *v14; // rax
  hkpShape *v15; // rdx
  hkpWorld *v16; // rcx
  unsigned int v17; // eax
  hkVector4f pivotInBodySpace; // [rsp+20h] [rbp-28h]
  hkUFloat8 v20; // [rsp+50h] [rbp+8h]
  float fv; // [rsp+58h] [rbp+10h]

  v6 = body;
  v7 = key;
  v8 = defaultValueHitOut;
  v9 = constraint;
  v10 = (_QWORD)body->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  ((void (*)(void))constraint->m_data->vfptr[5].__first_virtual_table_function__)();
  fv = a5;
  hkUFloat8::operator=(&v20, &fv);
  v11 = hkUFloat8::getEncodedFloat(v20.m_value);
  *(_DWORD *)&v20.m_value = (v11 + 243712) << 12;
  if ( v11 )
    v12 = *(float *)&v20.m_value;
  else
    v12 = 0.0;
  maxImpulseOut->m_value = (signed int)v12;
  if ( v10 )
  {
    v13 = v9->m_data;
    if ( v6 == (hkpRigidBody *)v9->m_entities[0] )
      v14 = (__m128i *)hkpConstraintDataUtils::getPivotA(v13);
    else
      v14 = (__m128i *)hkpConstraintDataUtils::getPivotB(v13);
    v15 = v6->m_collidable.m_shape;
    v16 = v6->m_world;
    _mm_store_si128((__m128i *)&pivotInBodySpace, *v14);
    v17 = hkpConstraintPivotsUtil::findClosestShapeKey(v16, v15, &pivotInBodySpace);
    *v7 = v17;
    if ( v17 != -1
      && (unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v10 + 48),
                            v17,
                            0i64) )
    {
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v10;
    }
    if ( *(_BYTE *)(v10 + 40) )
    {
      v8->m_bool = 1;
      return (hkpBreakOffPartsUtil::LimitContactImpulseUtil *)v10;
    }
  }
  return 0i64;
}

// File Line: 605
// RVA: 0xE0C4B0
void __usercall hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback(hkpBreakOffPartsUtil *this@<rcx>, hkpContactImpulseLimitBreachedListenerInfo *breachedContacts@<rdx>, int numBreachedContacts@<r8d>, __m128 a4@<xmm0>)
{
  __int64 v4; // rdi
  hkpContactImpulseLimitBreachedListenerInfo *v5; // rbx
  hkpBreakOffPartsUtil *v6; // r14
  __int64 v7; // r12
  hkLifoAllocator *v8; // rax
  char *v9; // r13
  int v10; // edx
  char *v11; // rcx
  hkLifoAllocator *v12; // rax
  int v13; // edx
  char *v14; // rcx
  hkLifoAllocator *v15; // rax
  int v16; // edx
  char *v17; // rcx
  hkLifoAllocator *v18; // rax
  int v19; // edx
  char *v20; // rcx
  __int64 v21; // r15
  hkpConstraintInstance **v22; // rbx
  hkpContactPointProperties *v23; // rdx
  hkpSimpleConstraintContactMgr *v24; // rcx
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v25; // rax
  unsigned __int64 v26; // rsi
  int v27; // eax
  __int64 v28; // rcx
  __int64 v29; // rdi
  __int64 v30; // rax
  signed __int64 v31; // r14
  _QWORD **v32; // rax
  __int64 v33; // rax
  __int64 v34; // rcx
  signed __int64 v35; // rsi
  float v36; // xmm0_4
  unsigned int v37; // eax
  signed __int64 v38; // rax
  hkpConstraintInstance *v39; // rax
  unsigned __int16 v40; // ax
  hkpConstraintInstance *v41; // rsi
  __int64 v42; // r14
  _QWORD **v43; // rax
  __int64 v44; // rax
  __int64 v45; // rdi
  __int64 v46; // rcx
  _QWORD *v47; // r8
  __int64 v48; // rdx
  __int64 v49; // rcx
  signed __int64 v50; // rcx
  hkpEntity *v51; // rdx
  unsigned __int64 v52; // rax
  __int64 v53; // r14
  int v54; // edx
  __m128 *v55; // r14
  hkVector4f *v56; // rcx
  __m128 v57; // xmm4
  __m128 v58; // xmm6
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm8
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  char *v65; // r15
  int v66; // edi
  hkpContactImpulseLimitBreachedListenerVtbl *v67; // rcx
  __int64 v68; // rsi
  __int64 v69; // r13
  int v70; // ecx
  hkpEntity *v71; // rbx
  __int64 v72; // rbx
  int v73; // er8
  __int64 v74; // rdx
  __int64 v75; // rbx
  int v76; // eax
  _QWORD **v77; // rax
  hkpEntity ***v78; // r13
  signed __int64 v79; // rcx
  hkpEntity **v80; // r15
  __int64 v81; // rdi
  char v82; // bl
  hkpEntity *v83; // rsi
  hkpEntity *v84; // r12
  unsigned __int64 v85; // r14
  unsigned __int64 v86; // r14
  hkpConstraintData *v87; // rcx
  __m128i *v88; // rax
  hkpShape *v89; // rdx
  hkpWorld *v90; // rcx
  unsigned int v91; // eax
  __int64 v92; // rdi
  hkpBreakOffPartsUtil *v93; // r12
  hkpContactImpulseLimitBreachedListenerVtbl *v94; // rcx
  int v95; // eax
  int v96; // ecx
  hkpEntity *v97; // rdi
  int v98; // esi
  hkpEntity **v99; // rbx
  int v100; // eax
  _QWORD **v101; // rax
  int v102; // esi
  signed int v103; // ebx
  hkLifoAllocator *v104; // rax
  void *v105; // rdx
  int v106; // er8
  int v107; // er14
  signed int v108; // edi
  hkLifoAllocator *v109; // rax
  void *v110; // rdx
  int v111; // ebx
  hkLifoAllocator *v112; // rax
  void *v113; // rdx
  unsigned int v114; // ebx
  hkLifoAllocator *v115; // rax
  int v116; // er8
  bool v117; // zf
  bool v118; // sf
  unsigned __int8 v119; // of
  void *v120; // rbx
  int v121; // [rsp+30h] [rbp-D0h]
  hkResult result; // [rsp+34h] [rbp-CCh]
  void *v123; // [rsp+38h] [rbp-C8h]
  void *v124; // [rsp+40h] [rbp-C0h]
  void *p; // [rsp+48h] [rbp-B8h]
  __int64 v126; // [rsp+50h] [rbp-B0h]
  unsigned int key[2]; // [rsp+58h] [rbp-A8h]
  void *v128; // [rsp+60h] [rbp-A0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v129; // [rsp+68h] [rbp-98h]
  int v130; // [rsp+78h] [rbp-88h]
  hkVector4f pivotBinW; // [rsp+80h] [rbp-80h]
  hkVector4f pivotAinW; // [rsp+90h] [rbp-70h]
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+A0h] [rbp-60h]
  hkpPhysicsSystem sys; // [rsp+B0h] [rbp-50h]
  hkpEntity **array; // [rsp+120h] [rbp+20h]
  int index; // [rsp+128h] [rbp+28h]
  int v137; // [rsp+12Ch] [rbp+2Ch]
  char v138; // [rsp+130h] [rbp+30h]
  char *v139; // [rsp+530h] [rbp+430h]
  int v140; // [rsp+538h] [rbp+438h]
  int v141; // [rsp+53Ch] [rbp+43Ch]
  char v142; // [rsp+540h] [rbp+440h]
  hkpBreakOffPartsUtil *v143; // [rsp+9F0h] [rbp+8F0h]
  hkBool defaultValueHitOut; // [rsp+9F8h] [rbp+8F8h]
  int v145; // [rsp+A00h] [rbp+900h]
  hkUFloat8 maxImpulseOut; // [rsp+A08h] [rbp+908h]

  v145 = numBreachedContacts;
  v143 = this;
  v4 = numBreachedContacts;
  v5 = breachedContacts;
  v6 = this;
  if ( breachedContacts->m_data.m_solver.m_type == 2 )
  {
    hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback_forToi(
      (hkpBreakOffPartsUtil *)((char *)this - 32),
      breachedContacts);
    return;
  }
  array = (hkpEntity **)&v138;
  v137 = -2147483520;
  index = 0;
  hkpPhysicsSystem::hkpPhysicsSystem(&sys);
  v129.m_elem = 0i64;
  v129.m_numElems = 0;
  v129.m_hashMod = -1;
  v7 = 0i64;
  if ( (_DWORD)v4 )
  {
    v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (char *)v8->m_cur;
    v10 = (24 * v4 + 127) & 0xFFFFFF80;
    v128 = v9;
    v11 = &v9[v10];
    if ( v10 > v8->m_slabSize || v11 > v8->m_end )
    {
      v9 = (char *)hkLifoAllocator::allocateFromNewSlab(v8, v10);
      v128 = v9;
    }
    else
    {
      v8->m_cur = v11;
    }
  }
  else
  {
    v9 = 0i64;
    v128 = 0i64;
  }
  LODWORD(v126) = 0;
  v130 = v4 | 0x80000000;
  if ( (_DWORD)v4 )
  {
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (8 * v4 + 127) & 0xFFFFFF80;
    v123 = v12->m_cur;
    v14 = (char *)v123 + v13;
    if ( v13 > v12->m_slabSize || v14 > v12->m_end )
      v123 = hkLifoAllocator::allocateFromNewSlab(v12, v13);
    else
      v12->m_cur = v14;
  }
  else
  {
    v123 = 0i64;
  }
  result.m_enum = 0;
  if ( (_DWORD)v4 )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (8 * v4 + 127) & 0xFFFFFF80;
    v124 = v15->m_cur;
    v17 = (char *)v124 + v16;
    if ( v16 > v15->m_slabSize || v17 > v15->m_end )
      v124 = hkLifoAllocator::allocateFromNewSlab(v15, v16);
    else
      v15->m_cur = v17;
  }
  else
  {
    v124 = 0i64;
  }
  v121 = 0;
  if ( (_DWORD)v4 )
  {
    v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    p = v18->m_cur;
    v19 = (32 * v4 + 127) & 0xFFFFFF80;
    v20 = (char *)p + v19;
    if ( v19 > v18->m_slabSize || v20 > v18->m_end )
      p = hkLifoAllocator::allocateFromNewSlab(v18, v19);
    else
      v18->m_cur = v20;
  }
  else
  {
    p = 0i64;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)&v6->m_id;
  EnterCriticalSection(lpCriticalSection);
  v21 = v4;
  if ( (signed int)v4 > 0 )
  {
    v22 = &v5->m_data.m_solver.m_constraintInstance;
    do
    {
      if ( *((_WORD *)v22 - 3) == 1 )
      {
        v23 = (hkpContactPointProperties *)v22[1];
        v24 = (hkpSimpleConstraintContactMgr *)&(*v22)[-2].m_uid;
        key[0] = -1;
        defaultValueHitOut.m_bool = 0;
        v25 = findUtil(v24, v23, &defaultValueHitOut, key, &maxImpulseOut);
        v26 = (unsigned __int64)v25;
        if ( v25 )
        {
          v27 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                    &v129,
                                    (unsigned __int64)v25);
          if ( v27 > v129.m_hashMod )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v129,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v26,
              (signed int)v7);
            v30 = (signed int)v7;
            v7 = (unsigned int)(v7 + 1);
            v31 = 3 * v30;
            v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v33 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(v32[11], 216i64);
            v29 = v33;
            if ( v33 )
            {
              *(_DWORD *)(v33 + 16) = 0;
              *(_DWORD *)(v33 + 20) = -2147483644;
              *(_QWORD *)(v33 + 8) = v33 + 24;
            }
            else
            {
              v29 = 0i64;
            }
            *(_QWORD *)&v9[8 * v31] = v29;
            *(_QWORD *)&v9[8 * v31 + 16] = v26;
            *(_QWORD *)v29 = *(_QWORD *)(v26 + 32);
            *(_DWORD *)&v9[8 * v31 + 8] = defaultValueHitOut.m_bool != 0;
          }
          else
          {
            v28 = SLODWORD(v129.m_elem[v27].val);
            v29 = *(_QWORD *)&v9[24 * v28];
            *(_DWORD *)&v9[24 * v28 + 8] |= defaultValueHitOut.m_bool != 0;
          }
          if ( *(_DWORD *)(v29 + 16) == (*(_DWORD *)(v29 + 20) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (void *)(v29 + 8),
              48);
          v34 = *(signed int *)(v29 + 16);
          *(_DWORD *)(v29 + 16) = v34 + 1;
          v35 = *(_QWORD *)(v29 + 8) + 48 * v34;
          *(_QWORD *)v35 = *(_QWORD *)v29 ^ (_QWORD)(*v22)->m_entities[0] ^ (_QWORD)(*v22)->m_entities[1];
          if ( *(hkpEntity **)v29 == (*v22)->m_entities[0] )
            v36 = *(float *)&FLOAT_1_0;
          else
            v36 = FLOAT_N1_0;
          v37 = key[0];
          *(float *)(v35 + 20) = v36;
          *(_DWORD *)(v35 + 8) = v37;
          *(_BYTE *)(v35 + 12) = 1;
          if ( *((_WORD *)v22 - 4) )
            v38 = (signed __int64)v22[2];
          else
            v38 = (signed __int64)(&(*v22)[-1].m_internal->m_runtime
                                 + 4
                                 * (((char *)v22[1]
                                   - 32 * HIWORD((*v22)[-1].m_internal->m_constraint)
                                   - (char *)(*v22)[-1].m_internal
                                   - 48)
                                  / BYTE2((*v22)[-1].m_internal->m_entities[0])));
          *(_QWORD *)(v35 + 24) = v38;
          v39 = v22[1];
          *(_QWORD *)(v35 + 32) = v39;
          v40 = hkUFloat8::getEncodedFloat(BYTE2(v39->m_owner));
          *(_DWORD *)&defaultValueHitOut.m_bool = (v40 + 243712) << 12;
          if ( v40 )
            a4.m128_i32[0] = *(_DWORD *)&defaultValueHitOut.m_bool;
          else
            a4.m128_i32[0] = 0;
          *(_DWORD *)(v35 + 16) = a4.m128_i32[0];
          *(_QWORD *)(v35 + 40) = (char *)*v22 - 120;
        }
      }
      else
      {
        v41 = *v22;
        v42 = ((unsigned __int8 (*)(void))(*v22)->m_data->vfptr[6].__first_virtual_table_function__)();
        v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v44 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(v43[11], 216i64);
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
        v46 = (signed int)v126;
        v47 = v124;
        *((_QWORD *)v123 + v46) = v45;
        v48 = result.m_enum;
        LODWORD(v126) = v46 + 1;
        v49 = *(signed int *)(v45 + 16);
        *(_DWORD *)(v45 + 16) = v49 + 1;
        v50 = *(_QWORD *)(v45 + 8) + 48 * v49;
        v47[v48] = v41;
        result.m_enum = v48 + 1;
        if ( (_BYTE)v42 )
          v51 = v41->m_entities[1];
        else
          v51 = v41->m_entities[0];
        *(_QWORD *)v45 = v51;
        v52 = (_QWORD)v41->m_entities[0] ^ (unsigned __int64)v51 ^ (_QWORD)v41->m_entities[1];
        v53 = v121;
        v54 = v121 + 1;
        *(_QWORD *)v50 = v52;
        *(_DWORD *)(v50 + 8) = -1;
        *(_BYTE *)(v50 + 12) = 0;
        v121 = v54;
        *(_QWORD *)(v50 + 32) = 0i64;
        *(_DWORD *)(v50 + 16) = 2139095022;
        *(_QWORD *)(v50 + 40) = 0i64;
        *(_DWORD *)(v50 + 20) = 1065353216;
        v55 = (__m128 *)((char *)p + 32 * v53);
        *(_QWORD *)(v50 + 24) = v55;
        hkpConstraintInstance::getPivotsInWorld(v41, &pivotAinW, &pivotBinW);
        v56 = &pivotAinW;
        if ( v41->m_entities[0] != *(hkpEntity **)v45 )
          v56 = &pivotBinW;
        *v55 = v56->m_quad;
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
                _mm_cmpleps(v59, (__m128)0i64),
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
          v62 = _mm_mul_ps(
                  v57,
                  _mm_andnot_ps(
                    _mm_cmpleps(v63, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                      _mm_mul_ps(v64, *(__m128 *)_xmm))));
        }
        else
        {
          v62 = transform.m_quad;
        }
        a4 = _mm_unpackhi_ps(v62, _mm_sub_ps((__m128)0i64, v61));
        v55[1] = _mm_shuffle_ps(v62, a4, 196);
      }
      v22 += 4;
      --v21;
    }
    while ( v21 );
    v6 = v143;
  }
  if ( (signed int)v7 > 0 )
  {
    v65 = v9;
    v66 = 0;
    do
    {
      v67 = v6->vfptr;
      v68 = *(_QWORD *)v65;
      v69 = *((_QWORD *)v65 + 2);
      v140 = 0;
      v141 = -2147483392;
      v139 = &v142;
      (*((void (__fastcall **)(hkpContactImpulseLimitBreachedListenerVtbl *, hkBool *, __int64, char **, hkpPhysicsSystem *))v67->__vecDelDtor
       + 2))(
        v67,
        &defaultValueHitOut,
        v68,
        &v139,
        &sys);
      if ( !*(_DWORD *)&defaultValueHitOut.m_bool )
      {
        if ( v140 )
        {
          v70 = index;
          v71 = *(hkpEntity **)v68;
          if ( index == (v137 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v70 = index;
          }
          array[v70] = v71;
          ++index;
          if ( v140 > 0 )
          {
            v72 = 0i64;
            do
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v69 + 48),
                (hkResult *)&maxImpulseOut,
                *(unsigned int *)&v139[v72]);
              ++v66;
              v72 += 4i64;
            }
            while ( v66 < v140 );
            v6 = v143;
          }
        }
        if ( *((_DWORD *)v65 + 2) )
          *(_BYTE *)(v69 + 40) = -1;
        v66 = 0;
        v73 = 0;
        if ( *(_DWORD *)(v68 + 16) > 0 )
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
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 8),
            48 * (v76 & 0x3FFFFFFF));
        *(_QWORD *)(v75 + 8) = 0i64;
        *(_DWORD *)(v75 + 20) = 2147483648;
        v77 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v77[11] + 16i64))(v77[11], v75, 216i64);
      }
      v140 = 0;
      if ( v141 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v139,
          4 * v141);
      v65 += 24;
      --v7;
    }
    while ( v7 );
  }
  if ( (signed int)v126 > 0 )
  {
    v78 = (hkpEntity ***)v123;
    *(_QWORD *)key = (unsigned int)v126;
    v79 = (_BYTE *)v124 - (_BYTE *)v123;
    v126 = (_BYTE *)v124 - (_BYTE *)v123;
    while ( 1 )
    {
      v80 = *v78;
      v81 = *(__int64 *)((char *)v78 + v79);
      v82 = 0;
      v83 = **v78;
      v84 = (*v78)[1];
      v85 = (unsigned __int64)v83->m_limitContactImpulseUtilAndFlag;
      (*(void (**)(void))(**(_QWORD **)(v81 + 24) + 88i64))();
      *(_DWORD *)&maxImpulseOut.m_value = a4.m128_i32[0];
      hkUFloat8::operator=((hkUFloat8 *)&defaultValueHitOut, (const float *)&maxImpulseOut.m_value);
      hkUFloat8::getEncodedFloat(defaultValueHitOut.m_bool);
      v86 = v85 & 0xFFFFFFFFFFFFFFFEui64;
      if ( !v86 )
        goto LABEL_154;
      v87 = *(hkpConstraintData **)(v81 + 24);
      if ( v83 == *(hkpEntity **)(v81 + 40) )
        v88 = (__m128i *)hkpConstraintDataUtils::getPivotA(v87);
      else
        v88 = (__m128i *)hkpConstraintDataUtils::getPivotB(v87);
      a4 = *(__m128 *)v88;
      v89 = v83->m_collidable.m_shape;
      v90 = v83->m_world;
      _mm_store_si128((__m128i *)&pivotBinW, *v88);
      v91 = hkpConstraintPivotsUtil::findClosestShapeKey(v90, v89, &pivotBinW);
      *(_DWORD *)&v84->m_memSizeAndFlags = v91;
      if ( v91 != -1
        && (unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(v86 + 48),
                              v91,
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
LABEL_154:
        v92 = 0i64;
        v86 = 0i64;
      }
LABEL_100:
      v93 = v143;
      v94 = v143->vfptr;
      v139 = &v142;
      v140 = 0;
      v141 = -2147483392;
      (*((void (__fastcall **)(hkpContactImpulseLimitBreachedListenerVtbl *, int *, hkpEntity **, char **, hkpPhysicsSystem *))v94->__vecDelDtor
       + 2))(
        v94,
        &v121,
        v80,
        &v139,
        &sys);
      if ( !v121 && v86 )
      {
        v95 = v140;
        if ( v140 )
        {
          v96 = index;
          v97 = *v80;
          if ( index == (v137 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v96 = index;
          }
          array[v96] = v97;
          ++index;
          v95 = v140;
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
              *(unsigned int *)&v139[v92]);
            ++v98;
            v92 += 4i64;
          }
          while ( v98 < v140 );
          LODWORD(v92) = 0;
        }
        if ( v82 )
          *(_BYTE *)(v86 + 40) = -1;
      }
      v99 = *v78;
      if ( *v78 )
      {
        v100 = *((_DWORD *)v99 + 5);
        *((_DWORD *)v99 + 4) = v92;
        if ( v100 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v99[1],
            48 * (v100 & 0x3FFFFFFF));
        v99[1] = 0i64;
        *((_DWORD *)v99 + 5) = 2147483648;
        v101 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpEntity **, signed __int64))(*v101[11] + 16i64))(v101[11], v99, 216i64);
      }
      v140 = v92;
      if ( v141 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v139,
          4 * v141);
      v79 = v126;
      ++v78;
      if ( !--*(_QWORD *)key )
        goto LABEL_120;
    }
  }
  v93 = v143;
LABEL_120:
  LeaveCriticalSection(lpCriticalSection);
  v102 = v145;
  v103 = (32 * v145 + 127) & 0xFFFFFF80;
  v104 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v105 = p;
  v106 = (v103 + 15) & 0xFFFFFFF0;
  if ( v103 > v104->m_slabSize || (char *)p + v106 != v104->m_cur || v104->m_firstNonLifoEnd == p )
  {
    hkLifoAllocator::slowBlockFree(v104, p, v106);
    v105 = p;
  }
  else
  {
    v104->m_cur = p;
  }
  v107 = v130;
  if ( v130 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v105,
      32 * v130);
  v108 = (8 * v102 + 127) & 0xFFFFFF80;
  v109 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v110 = v124;
  v111 = (v108 + 15) & 0xFFFFFFF0;
  if ( v108 > v109->m_slabSize || (char *)v124 + v111 != v109->m_cur || v109->m_firstNonLifoEnd == v124 )
  {
    hkLifoAllocator::slowBlockFree(v109, v124, v111);
    v110 = v124;
  }
  else
  {
    v109->m_cur = v124;
  }
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v110,
      8 * v107);
  v112 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v113 = v123;
  if ( v108 > v112->m_slabSize || (char *)v123 + v111 != v112->m_cur || v112->m_firstNonLifoEnd == v123 )
  {
    hkLifoAllocator::slowBlockFree(v112, v123, v111);
    v113 = v123;
  }
  else
  {
    v112->m_cur = v123;
  }
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v113,
      8 * v107);
  v114 = (24 * v102 + 127) & 0xFFFFFF80;
  v115 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v116 = (v114 + 15) & 0xFFFFFFF0;
  v119 = __OFSUB__(v114, v115->m_slabSize);
  v117 = v114 == v115->m_slabSize;
  v118 = (signed int)(v114 - v115->m_slabSize) < 0;
  v120 = v128;
  if ( (unsigned __int8)(v118 ^ v119) | v117 && (char *)v128 + v116 == v115->m_cur && v115->m_firstNonLifoEnd != v128 )
    v115->m_cur = v128;
  else
    hkLifoAllocator::slowBlockFree(v115, v128, v116);
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v120,
      24 * (v107 & 0x3FFFFFFF));
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v129,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v129);
  hkpWorld::addPhysicsSystem((hkpWorld *)v93[-1].m_breakOffPartsListener, &sys);
  hkArrayBase<hkpEntity *>::_insertAt(
    (hkArrayBase<hkProcess *> *)&array,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    index,
    (hkProcess *const *)sys.m_rigidBodies.m_data,
    sys.m_rigidBodies.m_size);
  if ( index )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      (hkpWorld *)v93[-1].m_breakOffPartsListener,
      array,
      (unsigned int)index,
      RR_MODE_RECOLLIDE_NARROWPHASE);
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::removeAll(&sys);
    hkReferencedObject::unlockAll();
  }
  hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
  index = 0;
  if ( v137 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v137);
}ase<hkProcess *> *)&array,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    index,
    (hkProcess *const *)sys.m_rigidBodies.m_data,
    sys.m_rigidBodies.m_size);
  if ( index )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      (hkpWorld *)v93[-1].m_breakOffPartsListener,
      array,
      (unsigned int)index,
      RR_MODE_RECOLLIDE_NARROWPHASE);
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::removeAll(&sys);
    hkReferencedObject::unlockAll();
  }
  hkpPhysicsSystem::~hkpPhysicsSyst

// File Line: 835
// RVA: 0xE0D240
void __fastcall hkpBreakOffPartsUtil::contactImpulseLimitBreachedCallback_forToi(hkpBreakOffPartsUtil *this, hkpContactImpulseLimitBreachedListenerInfo *breachedContact)
{
  hkpBreakOffPartsUtil *v2; // r15
  hkpContactImpulseLimitBreachedListenerInfo *v3; // rbx
  _RTL_CRITICAL_SECTION *v4; // rdi
  hkpContactPointProperties *v5; // rdx
  hkpSimpleConstraintContactMgr *v6; // rcx
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v7; // rax
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v8; // r13
  hkpConstraintInstance *v9; // r8
  unsigned __int16 v10; // r9
  __int64 v11; // r14
  __int64 v12; // rsi
  hkpRigidBody *v13; // r14
  signed __int64 v14; // rax
  unsigned __int16 v15; // ax
  int v16; // xmm0_4
  hkpConstraintInstance *v17; // rax
  float v18; // xmm0_4
  hkpBreakOffPartsListener *v19; // rcx
  char v20; // r12
  __int64 v21; // rbx
  int v22; // edi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+30h] [rbp-D0h]
  __int64 v24; // [rsp+40h] [rbp-C0h]
  __int64 *v25; // [rsp+48h] [rbp-B8h]
  int v26; // [rsp+50h] [rbp-B0h]
  int v27; // [rsp+54h] [rbp-ACh]
  hkpRigidBody *v28; // [rsp+58h] [rbp-A8h]
  unsigned int v29; // [rsp+60h] [rbp-A0h]
  char v30; // [rsp+64h] [rbp-9Ch]
  int v31; // [rsp+68h] [rbp-98h]
  float v32; // [rsp+6Ch] [rbp-94h]
  __int64 v33; // [rsp+70h] [rbp-90h]
  hkpSolverResults *v34; // [rsp+78h] [rbp-88h]
  hkpPhysicsSystem sys; // [rsp+120h] [rbp+20h]
  char *v36; // [rsp+190h] [rbp+90h]
  int v37; // [rsp+198h] [rbp+98h]
  int v38; // [rsp+19Ch] [rbp+9Ch]
  char v39; // [rsp+1A0h] [rbp+A0h]
  hkBool defaultValueHitOut; // [rsp+5F0h] [rbp+4F0h]
  hkUFloat8 maxImpulseOut; // [rsp+5F8h] [rbp+4F8h]
  unsigned int key; // [rsp+600h] [rbp+500h]
  int v43; // [rsp+608h] [rbp+508h]

  v2 = this;
  v3 = breachedContact;
  hkpPhysicsSystem::hkpPhysicsSystem(&sys);
  v4 = &v2->m_criticalSection->m_section;
  lpCriticalSection = &v2->m_criticalSection->m_section;
  EnterCriticalSection(&v2->m_criticalSection->m_section);
  v5 = v3->m_data.m_single.m_properties;
  v6 = (hkpSimpleConstraintContactMgr *)&v3->m_data.m_solver.m_constraintInstance[-2].m_uid;
  key = -1;
  defaultValueHitOut.m_bool = 0;
  v7 = findUtil(v6, v5, &defaultValueHitOut, &key, &maxImpulseOut);
  v8 = v7;
  if ( !v7 )
  {
LABEL_17:
    LeaveCriticalSection(v4);
    goto LABEL_18;
  }
  v9 = v3->m_data.m_solver.m_constraintInstance;
  v10 = v3->m_data.m_solver.m_type;
  v38 = -2147483392;
  v36 = &v39;
  v37 = 0;
  v11 = (_QWORD)v9->m_entities[0] ^ (_QWORD)v9->m_entities[1];
  v12 = (__int64)v7->m_entity;
  v25 = (__int64 *)&v28;
  v13 = (hkpRigidBody *)(v12 ^ v11);
  v26 = 1;
  v27 = -2147483644;
  v24 = v12;
  v28 = v13;
  v29 = key;
  if ( v10 )
    v14 = (signed __int64)v3->m_data.m_single.m_contactPoint;
  else
    v14 = (signed __int64)(&v9[-1].m_internal->m_runtime
                         + 4
                         * ((_QWORD)((char *)&v3->m_data.m_solver.m_solverResult[-4
                                                                               * HIWORD(v9[-1].m_internal->m_constraint)]
                                   - (char *)v9[-1].m_internal
                                   - 48)
                          / BYTE2(v9[-1].m_internal->m_entities[0])));
  v33 = v14;
  v34 = v3->m_data.m_solver.m_solverResult;
  v15 = hkUFloat8::getEncodedFloat(BYTE2(v34[2].m_impulseApplied));
  *(_DWORD *)&maxImpulseOut.m_value = (v15 + 243712) << 12;
  if ( v15 )
    v16 = *(_DWORD *)&maxImpulseOut.m_value;
  else
    v16 = 0;
  v17 = v3->m_data.m_solver.m_constraintInstance;
  v31 = v16;
  if ( (hkpEntity *)v12 == v17->m_entities[0] )
    v18 = *(float *)&FLOAT_1_0;
  else
    v18 = FLOAT_N1_0;
  v19 = v2->m_breakOffPartsListener;
  v32 = v18;
  v30 = 1;
  v19->vfptr->breakOffSubPart(
    v19,
    (hkResult *)&v43,
    (hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *)&v24,
    (hkArray<unsigned int,hkContainerHeapAllocator> *)&v36,
    &sys);
  if ( v43 == 1 )
  {
    v26 = 0;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v25,
        48 * (v27 & 0x3FFFFFFF));
    v25 = 0i64;
    v27 = 2147483648;
    v37 = 0;
    if ( v38 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v36,
        4 * v38);
    v36 = 0i64;
    v38 = 2147483648;
    goto LABEL_17;
  }
  v20 = 0;
  if ( v37 )
    v20 = 1;
  v21 = 0i64;
  v22 = 0;
  if ( v37 > 0 )
  {
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_shapeKeyToMaxImpulse.m_map.m_elem,
        (hkResult *)&maxImpulseOut,
        *(unsigned int *)&v36[v21]);
      ++v22;
      v21 += 4i64;
    }
    while ( v22 < v37 );
    LODWORD(v21) = 0;
  }
  if ( defaultValueHitOut.m_bool )
    v8->m_maxImpulse.m_value = -1;
  v26 = v21;
  if ( v27 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v25,
      48 * (v27 & 0x3FFFFFFF));
  v25 = 0i64;
  v27 = 2147483648;
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v36,
      4 * v38);
  v36 = 0i64;
  v38 = 2147483648;
  LeaveCriticalSection(lpCriticalSection);
  if ( *(_BYTE *)(v12 + 352) != 5 )
    v13 = (hkpRigidBody *)v12;
  hkpWorld::addPhysicsSystem(v2->m_world, &sys);
  if ( v20 )
  {
    hkReferencedObject::lockAll();
    hkpPhysicsSystem::addRigidBody(&sys, v13);
    hkReferencedObject::unlockAll();
  }
  if ( sys.m_rigidBodies.m_size )
  {
    hkpWorld::reintegrateAndRecollideEntities(
      v2->m_world,
      (hkpEntity **)sys.m_rigidBodies.m_data,
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
void __fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::findWeakestPoint(hkpBreakOffPartsUtil::LimitContactImpulseUtil *this, unsigned int *keyOut, float *weakestImpulseOut)
{
  float *v3; // rbx
  unsigned int *v4; // r11
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v5; // r10
  unsigned __int16 v6; // ax
  __int64 v7; // r9
  int v8; // er8
  unsigned __int8 v9; // cl
  __int64 v10; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v11; // rax
  int v12; // edx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v13; // r8
  signed __int64 v14; // r9
  int v15; // er8
  signed __int64 v16; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v17; // rax
  unsigned __int16 v18; // ax

  v3 = weakestImpulseOut;
  v4 = keyOut;
  v5 = this;
  if ( this->m_shapeKeyToMaxImpulse.m_map.m_numElems & 0x7FFFFFFF )
  {
    v7 = this->m_shapeKeyToMaxImpulse.m_map.m_hashMod;
    v8 = 0;
    v9 = -1;
    v10 = 0i64;
    if ( v7 >= 0 )
    {
      v11 = v5->m_shapeKeyToMaxImpulse.m_map.m_elem;
      do
      {
        if ( v11->key != -1i64 )
          break;
        ++v10;
        ++v8;
        ++v11;
      }
      while ( v10 <= v7 );
    }
    v12 = v8;
    if ( v8 <= v5->m_shapeKeyToMaxImpulse.m_map.m_hashMod )
    {
      do
      {
        v13 = v5->m_shapeKeyToMaxImpulse.m_map.m_elem;
        if ( LOBYTE(v13[v12].val) < v9 )
        {
          v9 = v13[v12].val;
          *v4 = v13[v12].key;
        }
        v14 = v5->m_shapeKeyToMaxImpulse.m_map.m_hashMod;
        v15 = v12 + 1;
        v16 = v15;
        if ( v15 <= v14 )
        {
          v17 = &v5->m_shapeKeyToMaxImpulse.m_map.m_elem[v15];
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
      while ( v15 <= v5->m_shapeKeyToMaxImpulse.m_map.m_hashMod );
    }
    v18 = hkUFloat8::getEncodedFloat(v9);
    if ( v18 )
    {
      *(_DWORD *)v3 = (v18 + 243712) << 12;
      return;
    }
  }
  else
  {
    *keyOut = -1;
    v6 = hkUFloat8::getEncodedFloat(this->m_maxImpulse.m_value);
    if ( v6 )
    {
      *(_DWORD *)v3 = (v6 + 243712) << 12;
      return;
    }
  }
  *v3 = 0.0;
}

// File Line: 966
// RVA: 0xE0C330
void __fastcall hkpBreakOffPartsUtil::performAttachments(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpConstraintListener *v2; // rdi
  hkpWorld *v3; // rsi
  hkpBreakOffPartsUtil *v4; // rbx
  hkpContactImpulseLimitBreachedListener *v5; // rdx

  v2 = 0i64;
  v3 = world;
  v4 = this;
  v5 = (hkpContactImpulseLimitBreachedListener *)&this->vfptr;
  if ( !this )
    v5 = 0i64;
  hkpWorld::addContactImpulseLimitBreachedListener(v3, v5);
  if ( v4 )
    v2 = (hkpConstraintListener *)&v4->vfptr;
  hkpWorld::addConstraintListener(v3, v2);
}

// File Line: 972
// RVA: 0xE0C390
void __fastcall hkpBreakOffPartsUtil::performDetachments(hkpBreakOffPartsUtil *this, hkpWorld *world)
{
  hkpContactImpulseLimitBreachedListener *v2; // rdi
  hkpWorld *v3; // rsi
  hkpBreakOffPartsUtil *v4; // rbx
  hkpConstraintListener *v5; // rdx

  v2 = 0i64;
  v3 = world;
  v4 = this;
  v5 = (hkpConstraintListener *)&this->vfptr;
  if ( !this )
    v5 = 0i64;
  hkpWorld::removeConstraintListener(v3, v5);
  if ( v4 )
    v2 = (hkpContactImpulseLimitBreachedListener *)&v4->vfptr;
  hkpWorld::removeContactImpulseLimitBreachedListener(v3, v2);
}

