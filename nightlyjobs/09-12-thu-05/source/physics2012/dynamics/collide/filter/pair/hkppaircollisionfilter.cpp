// File Line: 19
// RVA: 0xD78AB0
void __fastcall hkpPairCollisionFilter::~hkpPairCollisionFilter(hkpPairCollisionFilter *this)
{
  hkpCollisionFilter *m_childFilter; // rcx

  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpPairCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  m_childFilter = this->m_childFilter;
  if ( m_childFilter )
    hkReferencedObject::removeReference(m_childFilter);
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::clearAndDeallocate(
    &this->m_disabledPairs,
    &hkContainerHeapAllocator::s_alloc);
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 28
// RVA: 0xD78CA0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpEntity *entityA,
        hkpEntity *entityB)
{
  bool v5; // cc
  hkBool *v6; // rax
  hkpPairCollisionFilter::PairFilterKey v7; // [rsp+20h] [rbp-18h] BYREF

  if ( entityA && entityB )
  {
    if ( entityA >= entityB )
    {
      v7.m_a = entityB;
      v7.m_b = entityA;
    }
    else
    {
      v7.m_a = entityA;
      v7.m_b = entityB;
    }
    v5 = (int)hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::findKey(
                &this->m_disabledPairs,
                &v7) <= this->m_disabledPairs.m_hashMod;
    v6 = result;
    result->m_bool = !v5;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
  return v6;
}

// File Line: 46
// RVA: 0xD78D20
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpCollidable *collidableA,
        hkpCollidable *collidableB)
{
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *m_elem; // rcx
  hkpEntity *v9; // r9
  hkpEntity *v10; // r8
  char v12; // [rsp+30h] [rbp+8h] BYREF

  m_elem = this->m_disabledPairs.m_elem;
  if ( !m_elem
    || *(_BYTE *)(*(__int64 (__fastcall **)(unsigned __int64 *, char *))(m_elem->val + 8))(&m_elem->val, &v12) )
  {
    v9 = 0i64;
    if ( collidableA->m_broadPhaseHandle.m_type == 1 )
      v10 = (hkpEntity *)((char *)collidableA + collidableA->m_ownerOffset);
    else
      v10 = 0i64;
    if ( collidableB->m_broadPhaseHandle.m_type == 1 )
      v9 = (hkpEntity *)((char *)collidableB + collidableB->m_ownerOffset);
    hkpPairCollisionFilter::isCollisionEnabled((hkpPairCollisionFilter *)((char *)this - 16), result, v10, v9);
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

// File Line: 61
// RVA: 0xD78DC0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  __int64 v7; // rcx
  char v10; // [rsp+50h] [rbp+8h] BYREF

  v7 = *(_QWORD *)&this->m_postpad[1];
  if ( !v7
    || *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, unsigned int))(*(_QWORD *)(v7 + 24) + 8i64))(
                   v7 + 24,
                   &v10,
                   input,
                   a,
                   b,
                   bContainer,
                   bKey) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 66
// RVA: 0xD78E30
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *containerShapeA,
        hkpShapeContainer *containerShapeB,
        unsigned int keyA,
        unsigned int keyB)
{
  __int64 v9; // rcx
  char v12; // [rsp+60h] [rbp+8h] BYREF

  v9 = *(_QWORD *)&this->m_postpad[1];
  if ( !v9
    || *(_BYTE *)(**(__int64 (__fastcall ***)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, hkpShapeContainer *, unsigned int, unsigned int))(v9 + 24))(
                   v9 + 24,
                   &v12,
                   input,
                   a,
                   b,
                   containerShapeA,
                   containerShapeB,
                   keyA,
                   keyB) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 71
// RVA: 0xD78EC0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  __int64 v5; // rcx
  char v8; // [rsp+40h] [rbp+8h] BYREF

  v5 = *(_QWORD *)&this->m_type.m_storage;
  if ( !v5
    || *(_BYTE *)(**(__int64 (__fastcall ***)(__int64, char *, hkpShapeRayCastInput *, hkpShapeContainer *, unsigned int))(v5 + 32))(
                   v5 + 32,
                   &v8,
                   aInput,
                   bContainer,
                   bKey) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 77
// RVA: 0xD78F10
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(
        hkpPairCollisionFilter *this,
        hkBool *result,
        hkpWorldRayCastInput *a,
        hkpCollidable *collidableB)
{
  __int64 v4; // rcx
  char v7; // [rsp+30h] [rbp+8h] BYREF

  v4 = *(_QWORD *)this->m_prepad;
  if ( !v4
    || *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpWorldRayCastInput *, hkpCollidable *))(*(_QWORD *)(v4 + 40) + 8i64))(
                   v4 + 40,
                   &v7,
                   a,
                   collidableB) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 83
// RVA: 0xD78B50
unsigned __int64 __fastcall hkpPairCollisionFilter::enableCollisionsBetween(
        hkpPairCollisionFilter *this,
        hkpEntity *entityA,
        hkpEntity *entityB)
{
  hkpPairCollisionFilter::PairFilterKey v3; // xmm6
  hkMap<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations,hkContainerHeapAllocator> *p_m_disabledPairs; // rdi
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rbx
  hkpPairCollisionFilter::PairFilterKey v7; // [rsp+20h] [rbp-28h] BYREF
  hkResult v8; // [rsp+50h] [rbp+8h] BYREF

  if ( entityA >= entityB )
  {
    v7.m_a = entityB;
    v7.m_b = entityA;
  }
  else
  {
    v7.m_a = entityA;
    v7.m_b = entityB;
  }
  v3 = v7;
  p_m_disabledPairs = &this->m_disabledPairs;
  result = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::getWithDefault(
             &this->m_disabledPairs,
             &v7,
             0i64);
  if ( result )
  {
    v7 = v3;
    v6 = result - 1;
    if ( result == 1 )
    {
      hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
        p_m_disabledPairs,
        &v8,
        &v7);
      return 0i64;
    }
    else
    {
      hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(
        p_m_disabledPairs,
        &hkContainerHeapAllocator::s_alloc,
        &v7,
        v6);
      return (unsigned int)v6;
    }
  }
  return result;
}

// File Line: 114
// RVA: 0xD78C10
__int64 __fastcall hkpPairCollisionFilter::disableCollisionsBetween(
        hkpPairCollisionFilter *this,
        hkpEntity *entityA,
        hkpEntity *entityB)
{
  hkpPairCollisionFilter::PairFilterKey v3; // xmm6
  hkMap<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations,hkContainerHeapAllocator> *p_m_disabledPairs; // rdi
  unsigned __int64 v5; // rax
  int v6; // ebx
  hkpPairCollisionFilter::PairFilterKey v8; // [rsp+20h] [rbp-28h] BYREF

  if ( entityA >= entityB )
  {
    v8.m_a = entityB;
    v8.m_b = entityA;
  }
  else
  {
    v8.m_a = entityA;
    v8.m_b = entityB;
  }
  v3 = v8;
  p_m_disabledPairs = &this->m_disabledPairs;
  v5 = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::getWithDefault(
         &this->m_disabledPairs,
         &v8,
         0i64);
  v8 = v3;
  v6 = v5;
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(
    p_m_disabledPairs,
    &hkContainerHeapAllocator::s_alloc,
    &v8,
    v5 + 1);
  return (unsigned int)(v6 + 1);
}

// File Line: 135
// RVA: 0xD78F60
void __fastcall hkpPairCollisionFilter::clearAll(hkpPairCollisionFilter *this)
{
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::clear(&this->m_disabledPairs);
}

