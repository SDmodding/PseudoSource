// File Line: 21
// RVA: 0xCF2F80
void __fastcall hkpGroupFilter::hkpGroupFilter(hkpGroupFilter *this)
{
  hkpGroupFilter *v1; // rbx
  unsigned int *v2; // rdi
  signed __int64 v3; // rcx

  v1 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkpGroupFilter::`vftable{for `hkReferencedObject};
  v2 = v1->m_collisionLookupTable;
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpCollidableCollidableFilter};
  v1->m_type.m_storage = 2;
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpShapeCollectionFilter};
  v3 = 32i64;
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&hkpGroupFilter::`vftable{for `hkpRayCollidableFilter};
  while ( v3 )
  {
    *v2 = -1;
    ++v2;
    --v3;
  }
  v1->m_nextFreeSystemGroup = 0;
}

// File Line: 32
// RVA: 0xCF3000
void __fastcall hkpGroupFilter::~hkpGroupFilter(hkpGroupFilter *this)
{
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 39
// RVA: 0xCF33C0
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, unsigned int infoA, unsigned int infoB)
{
  hkBool *v4; // rax
  unsigned int v5; // eax

  if ( (infoB ^ infoA) & 0xFFFF0000 || !(infoA & 0xFFFF0000) )
  {
    v5 = this->m_collisionLookupTable[infoA & 0x1F];
    result->m_bool = _bittest((const signed int *)&v5, infoB & 0x1F);
    v4 = result;
  }
  else if ( (infoA ^ (infoB >> 5)) & 0x3E0 )
  {
    v4 = result;
    if ( (infoB ^ (infoA >> 5)) & 0x3E0 )
      result->m_bool = 1;
    else
      result->m_bool = 0;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 81
// RVA: 0xCF3130
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, hkpCollidable *a, hkpCollidable *b)
{
  hkBool *v4; // rbx

  v4 = result;
  hkpGroupFilter::isCollisionEnabled(
    (hkpGroupFilter *)((char *)this - 16),
    result,
    a->m_broadPhaseHandle.m_collisionFilterInfo,
    b->m_broadPhaseHandle.m_collisionFilterInfo);
  return v4;
}

// File Line: 87
// RVA: 0xCF3280
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *collectionBodyA, hkpCdBody *collectionBodyB, hkpShapeContainer *containerShapeA, hkpShapeContainer *containerShapeB, unsigned int keyA, unsigned int keyB)
{
  hkpGroupFilter *v9; // rbp
  hkBool *v10; // rsi
  hkpCdBody *v11; // rbx
  unsigned int v12; // edi
  hkpCdBody *i; // rax
  unsigned int v14; // eax
  hkpCdBody *v15; // rcx
  hkpCdBody *j; // rax

  v9 = this;
  v10 = result;
  v11 = collectionBodyA;
  v12 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, hkpCollisionInput *))containerShapeA->vfptr->getCollisionFilterInfo)(
          containerShapeA,
          keyA,
          input);
  if ( v12 == -1 )
  {
    for ( i = v11->m_parent; i; i = i->m_parent )
      v11 = i;
    v12 = *(&v11[1].m_shapeKey + 1);
  }
  v14 = containerShapeB->vfptr->getCollisionFilterInfo(containerShapeB, keyB);
  if ( v14 == -1 )
  {
    v15 = collectionBodyB;
    for ( j = collectionBodyB->m_parent; j; j = j->m_parent )
      v15 = j;
    v14 = *(&v15[1].m_shapeKey + 1);
  }
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)v9 - 24), v10, v12, v14);
  return v10;
}

// File Line: 105
// RVA: 0xCF3160
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a, hkpCdBody *b, hkpShapeContainer *bContainer, unsigned int bKey)
{
  hkpGroupFilter *v7; // r14
  hkBool *v8; // rdi
  hkpCdBody *v9; // rbx
  hkpCollisionInput *v10; // rsi
  unsigned int v11; // ebp
  hkpCdBody *v12; // r10
  hkpCdBody *i; // rax
  hkpCdBody *v14; // rdx
  hkpCdBody **v15; // r8
  unsigned int v16; // ecx
  unsigned int v17; // eax
  hkpCdBody *v18; // rax
  hkpCdBody *v19; // rcx
  __int64 v20; // rax

  v7 = this;
  v8 = result;
  v9 = a;
  v10 = input;
  v11 = bContainer->vfptr->getCollisionFilterInfo(bContainer, bKey);
  if ( v11 == -1 )
  {
    v12 = b;
    for ( i = b->m_parent; i; i = i->m_parent )
      v12 = i;
    v11 = *(&v12[1].m_shapeKey + 1);
  }
  v14 = v9->m_parent;
  v15 = &v9->m_parent;
  if ( v14 )
  {
    while ( 1 )
    {
      v16 = v10->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)v14->m_shape->m_type.m_storage];
      if ( _bittest((const signed int *)&v16, 0x12u) )
      {
        v17 = ((__int64 (__fastcall *)(hkpShape *, _QWORD, hkpCdBody **))v14->m_shape[1].vfptr[2].__vecDelDtor)(
                &v14->m_shape[1],
                v9->m_shapeKey,
                v15);
        goto LABEL_18;
      }
      if ( _bittest((const signed int *)&v16, 0x16u) )
      {
        v20 = ((__int64 (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody **))v14->m_shape->vfptr[7].__vecDelDtor)(
                v14->m_shape,
                v14,
                v15);
        v17 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v20 + 32i64))(v20, v9->m_shapeKey);
        goto LABEL_18;
      }
      if ( _bittest((const signed int *)&v16, 0x19u) )
        break;
      if ( _bittest((const signed int *)&v16, 0x1Au) )
      {
        v8->m_bool = 1;
        return v8;
      }
      v9 = v14;
      v14 = v14->m_parent;
      if ( !v14 )
        goto LABEL_11;
    }
    v18 = *v15;
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
    v17 = *(&v9[1].m_shapeKey + 1);
  }
LABEL_18:
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)v7 - 24), v8, v17, v11);
  return v8;
}

// File Line: 179
// RVA: 0xCF3330
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *bContainer, unsigned int bKey)
{
  hkBool *v5; // rsi
  hkpGroupFilter *v6; // rbx
  hkpShapeRayCastInput *v7; // rdi
  unsigned int v8; // eax

  v5 = result;
  v6 = this;
  v7 = aInput;
  v8 = bContainer->vfptr->getCollisionFilterInfo(bContainer, bKey);
  hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)((char *)v6 - 32), v5, v7->m_filterInfo, v8);
  return v5;
}

// File Line: 185
// RVA: 0xCF3390
hkBool *__fastcall hkpGroupFilter::isCollisionEnabled(hkpGroupFilter *this, hkBool *result, hkpWorldRayCastInput *aInput, hkpCollidable *collidableB)
{
  hkBool *v4; // rbx

  v4 = result;
  hkpGroupFilter::isCollisionEnabled(
    (hkpGroupFilter *)((char *)this - 40),
    result,
    aInput->m_filterInfo,
    collidableB->m_broadPhaseHandle.m_collisionFilterInfo);
  return v4;
}

// File Line: 192
// RVA: 0xCF30B0
void __fastcall hkpGroupFilter::enableCollisionsUsingBitfield(hkpGroupFilter *this, unsigned int layerBitsA, unsigned int layerBitsB)
{
  signed int v3; // er9
  unsigned int *v4; // rax
  signed __int64 v5; // rcx

  v3 = 1;
  v4 = this->m_collisionLookupTable;
  v5 = 32i64;
  do
  {
    if ( v3 & layerBitsA )
      *v4 |= layerBitsB;
    if ( v3 & layerBitsB )
      *v4 |= layerBitsA;
    v3 = __ROL4__(v3, 1);
    ++v4;
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
void __fastcall hkpGroupFilter::disableCollisionsUsingBitfield(hkpGroupFilter *this, unsigned int layerBitsA, unsigned int layerBitsB)
{
  signed int v3; // er9
  unsigned int *v4; // rax
  signed __int64 v5; // r10

  v3 = 1;
  v4 = this->m_collisionLookupTable;
  v5 = 32i64;
  do
  {
    if ( v3 & layerBitsA )
      *v4 &= ~layerBitsB;
    if ( v3 & layerBitsB )
      *v4 &= ~layerBitsA;
    v3 = __ROL4__(v3, 1);
    ++v4;
    --v5;
  }
  while ( v5 );
}

