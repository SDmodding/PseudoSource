// File Line: 19
// RVA: 0xE162A0
void __fastcall hkpGroupCollisionFilter::hkpGroupCollisionFilter(hkpGroupCollisionFilter *this)
{
  unsigned int *m_collisionGroups; // rdi
  __int64 v3; // rcx

  hkpCollisionFilter::hkpCollisionFilter(this);
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpGroupCollisionFilter::`vftable{for `hkReferencedObject};
  m_collisionGroups = this->m_collisionGroups;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpGroupCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v3 = 32i64;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpGroupCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpGroupCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpGroupCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->m_noGroupCollisionEnabled.m_bool = 1;
  while ( v3 )
  {
    *m_collisionGroups++ = 0;
    --v3;
  }
}

// File Line: 29
// RVA: 0xE163B0
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        int groupA,
        unsigned int groupB)
{
  unsigned int v5; // r10d
  int v6; // eax
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  unsigned int v17; // edx
  int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // edx
  int v21; // eax
  unsigned int v22; // edx
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  unsigned int v26; // edx
  int v27; // eax
  unsigned int v28; // edx
  int v29; // eax
  unsigned int v30; // edx
  int v31; // eax
  unsigned int v32; // edx
  int v33; // eax
  unsigned int v34; // edx
  unsigned int v35; // edx
  int v36; // eax
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // edx
  int v40; // eax
  unsigned int v41; // edx
  int v42; // eax
  unsigned int v43; // edx
  int v44; // eax
  unsigned int v45; // edx
  int v46; // eax
  unsigned int v47; // edx
  int v48; // eax
  unsigned int v49; // edx
  unsigned int v50; // edx
  int v51; // eax
  unsigned int v52; // edx
  int v53; // eax
  unsigned int v54; // edx
  int v55; // eax
  unsigned int v56; // edx
  int v57; // eax
  unsigned int v58; // edx
  int v59; // eax
  unsigned int v60; // edx
  int v61; // eax
  unsigned int v62; // edx
  int v63; // eax

  if ( groupA && groupB )
  {
    v5 = 0;
    v6 = 0;
    if ( (_BYTE)groupA )
    {
      if ( (groupA & 1) != 0 )
        v6 = this->m_collisionGroups[0];
      if ( (groupA & 2) != 0 )
        v7 = this->m_collisionGroups[1];
      else
        v7 = 0;
      v8 = v7 | v6;
      if ( (groupA & 4) != 0 )
        v9 = this->m_collisionGroups[2];
      else
        v9 = 0;
      v10 = v9 | v8;
      if ( (groupA & 8) != 0 )
        v11 = this->m_collisionGroups[3];
      else
        v11 = 0;
      v12 = v11 | v10;
      if ( (groupA & 0x10) != 0 )
        v13 = this->m_collisionGroups[4];
      else
        v13 = 0;
      v14 = v13 | v12;
      if ( (groupA & 0x20) != 0 )
        v15 = this->m_collisionGroups[5];
      else
        v15 = 0;
      v16 = v15 | v14;
      if ( (groupA & 0x40) != 0 )
        v17 = this->m_collisionGroups[6];
      else
        v17 = 0;
      v18 = v17 | v16;
      if ( (groupA & 0x80u) == 0 )
        v19 = 0;
      else
        v19 = this->m_collisionGroups[7];
      v6 = v19 | v18;
    }
    if ( (groupA & 0xFF00) != 0 )
    {
      if ( (groupA & 0x100) != 0 )
        v20 = this->m_collisionGroups[8];
      else
        v20 = 0;
      v21 = v20 | v6;
      if ( (groupA & 0x200) != 0 )
        v22 = this->m_collisionGroups[9];
      else
        v22 = 0;
      v23 = v22 | v21;
      if ( (groupA & 0x400) != 0 )
        v24 = this->m_collisionGroups[10];
      else
        v24 = 0;
      v25 = v24 | v23;
      if ( (groupA & 0x800) != 0 )
        v26 = this->m_collisionGroups[11];
      else
        v26 = 0;
      v27 = v26 | v25;
      if ( (groupA & 0x1000) != 0 )
        v28 = this->m_collisionGroups[12];
      else
        v28 = 0;
      v29 = v28 | v27;
      if ( (groupA & 0x2000) != 0 )
        v30 = this->m_collisionGroups[13];
      else
        v30 = 0;
      v31 = v30 | v29;
      if ( (groupA & 0x4000) != 0 )
        v32 = this->m_collisionGroups[14];
      else
        v32 = 0;
      v33 = v32 | v31;
      if ( (groupA & 0x8000) != 0 )
        v34 = this->m_collisionGroups[15];
      else
        v34 = 0;
      v6 = v34 | v33;
    }
    if ( (groupA & 0xFF0000) != 0 )
    {
      if ( (groupA & 0x10000) != 0 )
        v35 = this->m_collisionGroups[16];
      else
        v35 = 0;
      v36 = v35 | v6;
      if ( (groupA & 0x20000) != 0 )
        v37 = this->m_collisionGroups[17];
      else
        v37 = 0;
      v38 = v37 | v36;
      if ( (groupA & 0x40000) != 0 )
        v39 = this->m_collisionGroups[18];
      else
        v39 = 0;
      v40 = v39 | v38;
      if ( (groupA & 0x80000) != 0 )
        v41 = this->m_collisionGroups[19];
      else
        v41 = 0;
      v42 = v41 | v40;
      if ( (groupA & 0x100000) != 0 )
        v43 = this->m_collisionGroups[20];
      else
        v43 = 0;
      v44 = v43 | v42;
      if ( (groupA & 0x200000) != 0 )
        v45 = this->m_collisionGroups[21];
      else
        v45 = 0;
      v46 = v45 | v44;
      if ( (groupA & 0x400000) != 0 )
        v47 = this->m_collisionGroups[22];
      else
        v47 = 0;
      v48 = v47 | v46;
      if ( (groupA & 0x800000) != 0 )
        v49 = this->m_collisionGroups[23];
      else
        v49 = 0;
      v6 = v49 | v48;
    }
    if ( (groupA & 0xFF000000) != 0 )
    {
      if ( (groupA & 0x1000000) != 0 )
        v50 = this->m_collisionGroups[24];
      else
        v50 = 0;
      v51 = v50 | v6;
      if ( (groupA & 0x2000000) != 0 )
        v52 = this->m_collisionGroups[25];
      else
        v52 = 0;
      v53 = v52 | v51;
      if ( (groupA & 0x4000000) != 0 )
        v54 = this->m_collisionGroups[26];
      else
        v54 = 0;
      v55 = v54 | v53;
      if ( (groupA & 0x8000000) != 0 )
        v56 = this->m_collisionGroups[27];
      else
        v56 = 0;
      v57 = v56 | v55;
      if ( (groupA & 0x10000000) != 0 )
        v58 = this->m_collisionGroups[28];
      else
        v58 = 0;
      v59 = v58 | v57;
      if ( (groupA & 0x20000000) != 0 )
        v60 = this->m_collisionGroups[29];
      else
        v60 = 0;
      v61 = v60 | v59;
      if ( (groupA & 0x40000000) != 0 )
        v62 = this->m_collisionGroups[30];
      else
        v62 = 0;
      v63 = v62 | v61;
      if ( groupA < 0 )
        v5 = this->m_collisionGroups[31];
      v6 = v5 | v63;
    }
    result->m_bool = (v6 & groupB) != 0;
    return result;
  }
  else
  {
    result->m_bool = (char)this->m_noGroupCollisionEnabled;
    return result;
  }
}

// File Line: 86
// RVA: 0xE16660
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  hkpGroupCollisionFilter::isCollisionEnabled(
    (hkpGroupCollisionFilter *)((char *)this - 16),
    result,
    a->m_broadPhaseHandle.m_collisionFilterInfo,
    b->m_broadPhaseHandle.m_collisionFilterInfo);
  return result;
}

// File Line: 91
// RVA: 0xE16690
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  unsigned int v10; // eax
  hkpCdBody *i; // r9

  v10 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, hkpCollisionInput *))bContainer->vfptr->getCollisionFilterInfo)(
          bContainer,
          bKey,
          input);
  for ( i = a->m_parent; i; i = i->m_parent )
    a = i;
  hkpGroupCollisionFilter::isCollisionEnabled(
    (hkpGroupCollisionFilter *)((char *)this - 24),
    result,
    *(&a[1].m_shapeKey + 1),
    v10);
  return result;
}

// File Line: 97
// RVA: 0xE16700
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *collectionBodyA,
        hkpCdBody *collectionBodyB,
        hkpShapeContainer *containerShapeA,
        hkpShapeContainer *containerShapeB,
        unsigned int keyA,
        unsigned int keyB)
{
  int v11; // ebx
  unsigned int v12; // eax

  v11 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, hkpCollisionInput *, hkpCdBody *))containerShapeA->vfptr->getCollisionFilterInfo)(
          containerShapeA,
          keyA,
          input,
          collectionBodyA);
  v12 = containerShapeB->vfptr->getCollisionFilterInfo(containerShapeB, keyB);
  hkpGroupCollisionFilter::isCollisionEnabled((hkpGroupCollisionFilter *)((char *)this - 24), result, v11, v12);
  return result;
}

// File Line: 105
// RVA: 0xE16770
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  unsigned int v8; // eax

  v8 = bContainer->vfptr->getCollisionFilterInfo(bContainer, bKey);
  hkpGroupCollisionFilter::isCollisionEnabled(
    (hkpGroupCollisionFilter *)((char *)this - 32),
    result,
    aInput->m_filterInfo,
    v8);
  return result;
}

// File Line: 111
// RVA: 0xE167D0
hkBool *__fastcall hkpGroupCollisionFilter::isCollisionEnabled(
        hkpGroupCollisionFilter *this,
        hkBool *result,
        hkpWorldRayCastInput *aInput,
        hkpCollidable *collidableB)
{
  hkpGroupCollisionFilter::isCollisionEnabled(
    (hkpGroupCollisionFilter *)((char *)this - 40),
    result,
    aInput->m_filterInfo,
    collidableB->m_broadPhaseHandle.m_collisionFilterInfo);
  return result;
}

// File Line: 118
// RVA: 0xE16310
void __fastcall hkpGroupCollisionFilter::enableCollisionGroups(
        hkpGroupCollisionFilter *this,
        unsigned int groupBitsA,
        unsigned int groupBitsB)
{
  int v4; // ecx
  unsigned int *m_collisionGroups; // rax
  __int64 v6; // r9

  if ( groupBitsA || groupBitsB )
  {
    v4 = 1;
    m_collisionGroups = this->m_collisionGroups;
    v6 = 32i64;
    do
    {
      if ( (v4 & groupBitsA) != 0 )
        *m_collisionGroups |= groupBitsB;
      if ( (v4 & groupBitsB) != 0 )
        *m_collisionGroups |= groupBitsA;
      v4 = __ROL4__(v4, 1);
      ++m_collisionGroups;
      --v6;
    }
    while ( v6 );
  }
  else
  {
    this->m_noGroupCollisionEnabled.m_bool = 1;
  }
}

// File Line: 139
// RVA: 0xE16360
void __fastcall hkpGroupCollisionFilter::disableCollisionGroups(
        hkpGroupCollisionFilter *this,
        unsigned int groupBitsA,
        unsigned int groupBitsB)
{
  int v4; // edx
  unsigned int *m_collisionGroups; // rcx
  __int64 v6; // r10

  if ( groupBitsA || groupBitsB )
  {
    v4 = 1;
    m_collisionGroups = this->m_collisionGroups;
    v6 = 32i64;
    do
    {
      if ( (v4 & groupBitsA) != 0 )
        *m_collisionGroups &= ~groupBitsB;
      if ( (v4 & groupBitsB) != 0 )
        *m_collisionGroups &= ~groupBitsA;
      v4 = __ROL4__(v4, 1);
      ++m_collisionGroups;
      --v6;
    }
    while ( v6 );
  }
  else
  {
    this->m_noGroupCollisionEnabled.m_bool = 0;
  }
}

