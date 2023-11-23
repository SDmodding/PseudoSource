// File Line: 21
// RVA: 0xCF2F80
void __fastcall hkpGroupFilter::hkpGroupFilter(hkpGroupFilter *this)
{
  unsigned int *m_collisionLookupTable; // rdi
  __int64 v3; // rcx

  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpGroupFilter::`vftable{for `hkReferencedObject};
  m_collisionLookupTable = this->m_collisionLookupTable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->m_type.m_storage = 2;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpShapeCollectionFilter};
  v3 = 32i64;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpRayCollidableFilter};
  while ( v3 )
  {
    *m_collisionLookupTable++ = -1;
    --v3;
  }
  this->m_nextFreeSystemGroup = 0;
}

// File Line: 32
// RVA: 0xCF3000
void __fastcall hkpGroupFilter::~hkpGroupFilter(hkpGroupFilter *this)
{
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 39
// RVA: 0xCF33C0
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        unsigned int infoA,
        unsigned int infoB)
{
  hkBool *v4; // rax
  unsigned int v5; // eax

  if ( ((infoB ^ infoA) & 0xFFFF0000) != 0 || (infoA & 0xFFFF0000) == 0 )
  {
    v5 = this->m_collisionLookupTable[infoA & 0x1F];
    result->m_bool = _bittest((const int *)&v5, infoB & 0x1F);
    return result;
  }
  else if ( ((infoA ^ (infoB >> 5)) & 0x3E0) != 0 )
  {
    v4 = result;
    result->m_bool = ((infoB ^ (infoA >> 5)) & 0x3E0) != 0;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
  return v4;
}

// File Line: 81
// RVA: 0xCF3130
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  hkpGroupFilter::isCollisionEnabled(
    (hkpGroupFilter *)((char *)this - 16),
    result,
    a->m_broadPhaseHandle.m_collisionFilterInfo,
    b->m_broadPhaseHandle.m_collisionFilterInfo);
  return result;
}

// File Line: 87
// RVA: 0xCF3280
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *collectionBodyA,
        hkpCdBody *collectionBodyB,
        hkpShapeContainer *containerShapeA,
        hkpShapeContainer *containerShapeB,
        unsigned int keyA,
        unsigned int keyB)
{
  unsigned int v12; // edi
  hkpCdBody *i; // rax
  unsigned int v14; // eax
  hkpCdBody *v15; // rcx
  hkpCdBody *j; // rax

  v12 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, hkpCollisionInput *))containerShapeA->vfptr->getCollisionFilterInfo)(
          containerShapeA,
          keyA,
          input);
  if ( v12 == -1 )
  {
    for ( i = collectionBodyA->m_parent; i; i = i->m_parent )
      collectionBodyA = i;
    v12 = *(&collectionBodyA[1].m_shapeKey + 1);
  }
  v14 = containerShapeB->vfptr->getCollisionFilterInfo(containerShapeB, keyB);
  if ( v14 == -1 )
  {
    v15 = collectionBodyB;
    for ( j = collectionBodyB->m_parent; j; j = j->m_parent )
      v15 = j;
    v14 = *(&v15[1].m_shapeKey + 1);
  }
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)this - 24), result, v12, v14);
  return result;
}

// File Line: 105
// RVA: 0xCF3160
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  unsigned int v11; // ebp
  hkpCdBody *v12; // r10
  hkpCdBody *i; // rax
  hkpCdBody *m_parent; // rdx
  hkpCdBody **p_m_parent; // r8
  unsigned int v16; // ecx
  unsigned int v17; // eax
  hkpCdBody *v18; // rax
  hkpCdBody *v19; // rcx
  __int64 v20; // rax

  v11 = bContainer->vfptr->getCollisionFilterInfo(bContainer, bKey);
  if ( v11 == -1 )
  {
    v12 = b;
    for ( i = b->m_parent; i; i = i->m_parent )
      v12 = i;
    v11 = *(&v12[1].m_shapeKey + 1);
  }
  m_parent = a->m_parent;
  p_m_parent = &a->m_parent;
  if ( m_parent )
  {
    while ( 1 )
    {
      v16 = input->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)m_parent->m_shape->m_type.m_storage];
      if ( (v16 & 0x40000) != 0 )
      {
        v17 = ((__int64 (__fastcall *)(hkpShape *, _QWORD, hkpCdBody **))m_parent->m_shape[1].vfptr[2].__vecDelDtor)(
                &m_parent->m_shape[1],
                a->m_shapeKey,
                p_m_parent);
        goto LABEL_18;
      }
      if ( (v16 & 0x400000) != 0 )
      {
        v20 = ((__int64 (__fastcall *)(hkpShape *))m_parent->m_shape->vfptr[7].__vecDelDtor)(m_parent->m_shape);
        v17 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v20 + 32i64))(v20, a->m_shapeKey);
        goto LABEL_18;
      }
      if ( (v16 & 0x2000000) != 0 )
        break;
      if ( (v16 & 0x4000000) != 0 )
      {
        result->m_bool = 1;
        return result;
      }
      a = m_parent;
      m_parent = m_parent->m_parent;
      if ( !m_parent )
        goto LABEL_11;
    }
    v18 = *p_m_parent;
    do
    {
      v19 = v18;
      v18 = v18->m_parent;
    }
    while ( v18 );
    v17 = *(&v19[1].m_shapeKey + 1);
  }
  else
  {
LABEL_11:
    v17 = *(&a[1].m_shapeKey + 1);
  }
LABEL_18:
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)this - 24), result, v17, v11);
  return result;
}

// File Line: 179
// RVA: 0xCF3330
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  unsigned int v8; // eax

  v8 = bContainer->vfptr->getCollisionFilterInfo(bContainer, bKey);
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)this - 32), result, aInput->m_filterInfo, v8);
  return result;
}

// File Line: 185
// RVA: 0xCF3390
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(
        hkpGroupFilter *this,
        hkBool *result,
        hkpWorldRayCastInput *aInput,
        hkpCollidable *collidableB)
{
  hkpGroupFilter::isCollisionEnabled(
    (hkpGroupFilter *)((char *)this - 40),
    result,
    aInput->m_filterInfo,
    collidableB->m_broadPhaseHandle.m_collisionFilterInfo);
  return result;
}

// File Line: 192
// RVA: 0xCF30B0
void __fastcall hkpGroupFilter::enableCollisionsUsingBitfield(
        hkpGroupFilter *this,
        unsigned int layerBitsA,
        unsigned int layerBitsB)
{
  int v3; // r9d
  unsigned int *m_collisionLookupTable; // rax
  __int64 v5; // rcx

  v3 = 1;
  m_collisionLookupTable = this->m_collisionLookupTable;
  v5 = 32i64;
  do
  {
    if ( (v3 & layerBitsA) != 0 )
      *m_collisionLookupTable |= layerBitsB;
    if ( (v3 & layerBitsB) != 0 )
      *m_collisionLookupTable |= layerBitsA;
    v3 = __ROL4__(v3, 1);
    ++m_collisionLookupTable;
    --v5;
  }
  while ( v5 );
}

// File Line: 209
// RVA: 0xCF3040
void __fastcall hkpGroupFilter::enableCollisionsBetween(hkpGroupFilter *this, int layerA, int layerB)
{
  this->m_collisionLookupTable[layerA] |= 1 << layerB;
  this->m_collisionLookupTable[layerB] |= 1 << layerA;
}

// File Line: 218
// RVA: 0xCF3070
void __fastcall hkpGroupFilter::disableCollisionsBetween(hkpGroupFilter *this, int layerA, int layerB)
{
  this->m_collisionLookupTable[layerA] &= ~(1 << layerB);
  this->m_collisionLookupTable[layerB] &= ~(1 << layerA);
}

// File Line: 229
// RVA: 0xCF30F0
void __fastcall hkpGroupFilter::disableCollisionsUsingBitfield(
        hkpGroupFilter *this,
        unsigned int layerBitsA,
        unsigned int layerBitsB)
{
  int v3; // r9d
  unsigned int *m_collisionLookupTable; // rax
  __int64 v5; // r10

  v3 = 1;
  m_collisionLookupTable = this->m_collisionLookupTable;
  v5 = 32i64;
  do
  {
    if ( (v3 & layerBitsA) != 0 )
      *m_collisionLookupTable &= ~layerBitsB;
    if ( (v3 & layerBitsB) != 0 )
      *m_collisionLookupTable &= ~layerBitsA;
    v3 = __ROL4__(v3, 1);
    ++m_collisionLookupTable;
    --v5;
  }
  while ( v5 );
}

