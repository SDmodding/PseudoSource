// File Line: 19
// RVA: 0xD78AB0
void __fastcall hkpPairCollisionFilter::~hkpPairCollisionFilter(hkpPairCollisionFilter *this)
{
  hkpPairCollisionFilter *v1; // rbx
  hkpCollisionFilter *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpPairCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  v2 = this->m_childFilter;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::clearAndDeallocate(
    (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&v1->m_disabledPairs.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable';
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable';
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable';
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 28
// RVA: 0xD78CA0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpEntity *entityA, hkpEntity *entityB)
{
  hkBool *v4; // rdi
  hkMap<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations,hkContainerHeapAllocator> *v5; // rbx
  int v6; // eax
  bool v7; // zf
  bool v8; // sf
  unsigned __int8 v9; // of
  hkBool *v10; // rax
  hkpPairCollisionFilter::PairFilterKey v11; // [rsp+20h] [rbp-18h]

  v4 = result;
  if ( entityA && entityB )
  {
    if ( entityA >= entityB )
    {
      v11.m_a = entityB;
      v11.m_b = entityA;
    }
    else
    {
      v11.m_a = entityA;
      v11.m_b = entityB;
    }
    v5 = &this->m_disabledPairs;
    _mm_store_si128((__m128i *)&v11, (__m128i)v11);
    v6 = (unsigned __int64)hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::findKey(
                             (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem,
                             &v11);
    v9 = __OFSUB__(v6, v5->m_hashMod);
    v7 = v6 == v5->m_hashMod;
    v8 = v6 - v5->m_hashMod < 0;
    v10 = v4;
    if ( (unsigned __int8)(v8 ^ v9) | v7 )
      v4->m_bool = 0;
    else
      v4->m_bool = 1;
  }
  else
  {
    result->m_bool = 1;
    v10 = result;
  }
  return v10;
}

// File Line: 46
// RVA: 0xD78D20
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpCollidable *collidableA, hkpCollidable *collidableB)
{
  hkpPairCollisionFilter *v4; // rbp
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v5; // rcx
  hkpCollidable *v6; // rsi
  hkpCollidable *v7; // rdi
  hkBool *v8; // rbx
  hkpEntity *v9; // r9
  hkpEntity *v10; // r8
  char v12; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = this->m_disabledPairs.m_elem;
  v6 = collidableB;
  v7 = collidableA;
  v8 = result;
  if ( !v5 || *(_BYTE *)(*(__int64 (__fastcall **)(unsigned __int64 *, char *))(v5->val + 8))(&v5->val, &v12) )
  {
    v9 = 0i64;
    if ( v7->m_broadPhaseHandle.m_type == 1 )
      v10 = (hkpEntity *)((char *)v7 + v7->m_ownerOffset);
    else
      v10 = 0i64;
    if ( v6->m_broadPhaseHandle.m_type == 1 )
      v9 = (hkpEntity *)((char *)v6 + v6->m_ownerOffset);
    hkpPairCollisionFilter::isCollisionEnabled((hkpPairCollisionFilter *)((char *)v4 - 16), v8, v10, v9);
  }
  else
  {
    v8->m_bool = 0;
  }
  return v8;
}

// File Line: 61
// RVA: 0xD78DC0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a, hkpCdBody *b, hkpShapeContainer *bContainer, unsigned int bKey)
{
  __int64 v7; // rcx
  hkBool *v8; // rbx
  unsigned int v9; // ST30_4
  hkBool *v10; // rax
  char v11; // [rsp+50h] [rbp+8h]

  v7 = *(_QWORD *)&this->m_postpad[1];
  v8 = result;
  if ( !v7
    || (v9 = bKey,
        *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, unsigned int))(*(_QWORD *)(v7 + 24) + 8i64))(
                    v7 + 24,
                    &v11,
                    input,
                    a,
                    b,
                    bContainer,
                    v9)) )
  {
    v8->m_bool = 1;
    v10 = v8;
  }
  else
  {
    v8->m_bool = 0;
    v10 = v8;
  }
  return v10;
}

// File Line: 66
// RVA: 0xD78E30
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a, hkpCdBody *b, hkpShapeContainer *containerShapeA, hkpShapeContainer *containerShapeB, unsigned int keyA, unsigned int keyB)
{
  __int64 v9; // rcx
  hkBool *v10; // rbx
  unsigned int v11; // ST40_4
  unsigned int v12; // ST38_4
  hkBool *v13; // rax
  char v14; // [rsp+60h] [rbp+8h]

  v9 = *(_QWORD *)&this->m_postpad[1];
  v10 = result;
  if ( !v9
    || (v11 = keyB,
        v12 = keyA,
        *(_BYTE *)(**(__int64 (__fastcall ***)(signed __int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, hkpShapeContainer *, unsigned int, unsigned int))(v9 + 24))(
                    v9 + 24,
                    &v14,
                    input,
                    a,
                    b,
                    containerShapeA,
                    containerShapeB,
                    v12,
                    v11)) )
  {
    v10->m_bool = 1;
    v13 = v10;
  }
  else
  {
    v10->m_bool = 0;
    v13 = v10;
  }
  return v13;
}

// File Line: 71
// RVA: 0xD78EC0
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *bContainer, unsigned int bKey)
{
  __int64 v5; // rcx
  hkBool *v6; // rbx
  unsigned int v7; // ST20_4
  hkBool *v8; // rax
  char v9; // [rsp+40h] [rbp+8h]

  v5 = *(_QWORD *)&this->m_type.m_storage;
  v6 = result;
  if ( !v5
    || (v7 = bKey,
        *(_BYTE *)(**(__int64 (__fastcall ***)(signed __int64, char *, hkpShapeRayCastInput *, hkpShapeContainer *, unsigned int))(v5 + 32))(
                    v5 + 32,
                    &v9,
                    aInput,
                    bContainer,
                    v7)) )
  {
    v6->m_bool = 1;
    v8 = v6;
  }
  else
  {
    v6->m_bool = 0;
    v8 = v6;
  }
  return v8;
}

// File Line: 77
// RVA: 0xD78F10
hkBool *__fastcall hkpPairCollisionFilter::isCollisionEnabled(hkpPairCollisionFilter *this, hkBool *result, hkpWorldRayCastInput *a, hkpCollidable *collidableB)
{
  __int64 v4; // rcx
  hkBool *v5; // rbx
  hkBool *v6; // rax
  char v7; // [rsp+30h] [rbp+8h]

  v4 = *(_QWORD *)this->m_prepad;
  v5 = result;
  if ( !v4
    || *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpWorldRayCastInput *, hkpCollidable *))(*(_QWORD *)(v4 + 40) + 8i64))(
                   v4 + 40,
                   &v7,
                   a,
                   collidableB) )
  {
    v5->m_bool = 1;
    v6 = v5;
  }
  else
  {
    v5->m_bool = 0;
    v6 = v5;
  }
  return v6;
}

// File Line: 83
// RVA: 0xD78B50
unsigned __int64 __fastcall hkpPairCollisionFilter::enableCollisionsBetween(hkpPairCollisionFilter *this, hkpEntity *entityA, hkpEntity *entityB)
{
  __m128i v3; // xmm6
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *v4; // rdi
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rbx
  __m128i v7; // [rsp+20h] [rbp-28h]
  char v8; // [rsp+50h] [rbp+8h]

  if ( entityA >= entityB )
  {
    v7.m128i_i64[0] = (__int64)entityB;
    v7.m128i_i64[1] = (__int64)entityA;
  }
  else
  {
    v7.m128i_i64[0] = (__int64)entityA;
    v7.m128i_i64[1] = (__int64)entityB;
  }
  v3 = v7;
  v4 = (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem;
  _mm_store_si128(&v7, v7);
  result = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::getWithDefault(
             (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem,
             (hkpPairCollisionFilter::PairFilterKey *)&v7,
             0i64);
  if ( result )
  {
    _mm_store_si128(&v7, v3);
    v6 = result - 1;
    if ( result == 1 )
    {
      hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
        v4,
        (hkResult *)&v8,
        (hkpPairCollisionFilter::PairFilterKey *)&v7);
      result = 0i64;
    }
    else
    {
      hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(
        v4,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (hkpPairCollisionFilter::PairFilterKey *)&v7,
        v6);
      result = (unsigned int)v6;
    }
  }
  return result;
}

// File Line: 114
// RVA: 0xD78C10
__int64 __fastcall hkpPairCollisionFilter::disableCollisionsBetween(hkpPairCollisionFilter *this, hkpEntity *entityA, hkpEntity *entityB)
{
  __m128i v3; // xmm6
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *v4; // rdi
  unsigned __int64 v5; // rax
  int v6; // ebx
  __m128i v8; // [rsp+20h] [rbp-28h]

  if ( entityA >= entityB )
  {
    v8.m128i_i64[0] = (__int64)entityB;
    v8.m128i_i64[1] = (__int64)entityA;
  }
  else
  {
    v8.m128i_i64[0] = (__int64)entityA;
    v8.m128i_i64[1] = (__int64)entityB;
  }
  v3 = v8;
  v4 = (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem;
  _mm_store_si128(&v8, v8);
  v5 = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::getWithDefault(
         (hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem,
         (hkpPairCollisionFilter::PairFilterKey *)&v8,
         0i64);
  _mm_store_si128(&v8, v3);
  v6 = v5;
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(
    v4,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (hkpPairCollisionFilter::PairFilterKey *)&v8,
    v5 + 1);
  return (unsigned int)(v6 + 1);
}

// File Line: 135
// RVA: 0xD78F60
void __fastcall hkpPairCollisionFilter::clearAll(hkpPairCollisionFilter *this)
{
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::clear((hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *)&this->m_disabledPairs.m_elem);
}

