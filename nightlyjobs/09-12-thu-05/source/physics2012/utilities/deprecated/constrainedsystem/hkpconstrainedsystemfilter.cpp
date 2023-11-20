// File Line: 29
// RVA: 0xE14A60
void __fastcall hkpConstrainedSystemFilter::hkpConstrainedSystemFilter(hkpConstrainedSystemFilter *this, hkpCollisionFilter *otherFilter)
{
  hkpCollisionFilter *v2; // rdi
  hkpConstrainedSystemFilter *v3; // rbx

  v2 = otherFilter;
  v3 = this;
  hkpCollisionFilter::hkpCollisionFilter((hkpCollisionFilter *)&this->vfptr);
  v3->m_otherFilter = v2;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkReferencedObject'};
  v3->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  v3->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpShapeCollectionFilter'};
  v3->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  v3->vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpRayCollidableFilter'};
  v3->vfptr = (hkpConstraintListenerVtbl *)&hkpConstrainedSystemFilter::`vftable';
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
}

// File Line: 39
// RVA: 0xE14AE0
void __fastcall hkpConstrainedSystemFilter::~hkpConstrainedSystemFilter(hkpConstrainedSystemFilter *this)
{
  hkpConstrainedSystemFilter *v1; // rbx
  hkpCollisionFilter *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpShapeCollectionFilter'};
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable'{for `hkpRayCollidableFilter'};
  this->vfptr = (hkpConstraintListenerVtbl *)&hkpConstrainedSystemFilter::`vftable';
  v2 = this->m_otherFilter;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable';
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable';
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable';
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable';
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 47
// RVA: 0xE14B90
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(hkpConstrainedSystemFilter *this, hkBool *result, hkpCollidable *a, hkpCollidable *b)
{
  int v4; // edi
  hkBool *v5; // r14
  hkpEntity *v6; // rbp
  hkpEntity *v7; // rsi
  __int64 v8; // rcx
  hkBool *v9; // rax
  signed int v10; // ebx
  hkpEntity *v11; // r15
  bool v12; // al
  int v13; // ebp
  hkpConstraintInstance *v14; // rax
  hkpConstraintInstance *v15; // rbx
  char v16; // [rsp+40h] [rbp+8h]

  v4 = 0;
  v5 = result;
  if ( a->m_broadPhaseHandle.m_type == 1 )
    v6 = (hkpEntity *)((char *)a + a->m_ownerOffset);
  else
    v6 = 0i64;
  if ( b->m_broadPhaseHandle.m_type == 1 )
    v7 = (hkpEntity *)((char *)b + b->m_ownerOffset);
  else
    v7 = 0i64;
  v8 = *(_QWORD *)&this->m_postpad[1];
  if ( !v8 || *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)(v8 + 16) + 8i64))(v8 + 16, &v16) )
  {
    if ( v6 && v7 )
    {
      v10 = hkpEntity::getNumConstraints(v7);
      v11 = v6;
      v12 = (signed int)hkpEntity::getNumConstraints(v6) > v10;
      if ( v12 )
        v11 = v7;
      if ( v12 )
        v7 = v6;
      v13 = hkpEntity::getNumConstraints(v11);
      if ( v13 <= 0 )
      {
LABEL_22:
        v5->m_bool = 1;
      }
      else
      {
        while ( 1 )
        {
          v14 = hkpEntity::getConstraint(v11, v4);
          v15 = v14;
          if ( v14 )
          {
            if ( ((unsigned int (*)(void))v14->m_data->vfptr[1].__first_virtual_table_function__)() != 11
              && (v15->m_entities[0] == v7 || v15->m_entities[1] == v7) )
            {
              break;
            }
          }
          if ( ++v4 >= v13 )
            goto LABEL_22;
        }
        v5->m_bool = 0;
      }
      v9 = v5;
    }
    else
    {
      v5->m_bool = 1;
      v9 = v5;
    }
  }
  else
  {
    v5->m_bool = 0;
    v9 = v5;
  }
  return v9;
}

// File Line: 89
// RVA: 0xE14CD0
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(hkpConstrainedSystemFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *a, hkpCdBody *b, hkpShapeContainer *bContainer, unsigned int bKey)
{
  __int64 v7; // rcx
  hkBool *v8; // rbx
  unsigned int v9; // ST30_4
  hkBool *v10; // rax
  char v11; // [rsp+50h] [rbp+8h]

  v7 = *(_QWORD *)&this->m_type.m_storage;
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

// File Line: 95
// RVA: 0xE14D40
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(hkpConstrainedSystemFilter *this, hkBool *result, hkpCollisionInput *input, hkpCdBody *collectionBodyA, hkpCdBody *collectionBodyB, hkpShapeContainer *containerShapeA, hkpShapeContainer *containerShapeB, unsigned int keyA, unsigned int keyB)
{
  __int64 v9; // rcx
  hkBool *v10; // rbx
  unsigned int v11; // ST40_4
  unsigned int v12; // ST38_4
  hkBool *v13; // rax
  char v14; // [rsp+60h] [rbp+8h]

  v9 = *(_QWORD *)&this->m_type.m_storage;
  v10 = result;
  if ( !v9
    || (v11 = keyB,
        v12 = keyA,
        *(_BYTE *)(**(__int64 (__fastcall ***)(signed __int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, hkpShapeContainer *, unsigned int, unsigned int))(v9 + 24))(
                    v9 + 24,
                    &v14,
                    input,
                    collectionBodyA,
                    collectionBodyB,
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

// File Line: 101
// RVA: 0xE14DD0
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(hkpConstrainedSystemFilter *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *bContainer, unsigned int bKey)
{
  __int64 v5; // rcx
  hkBool *v6; // rbx
  unsigned int v7; // ST20_4
  hkBool *v8; // rax
  char v9; // [rsp+40h] [rbp+8h]

  v5 = *(_QWORD *)this->m_prepad;
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

// File Line: 106
// RVA: 0xE14E20
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(hkpConstrainedSystemFilter *this, hkBool *result, hkpWorldRayCastInput *a, hkpCollidable *collidableB)
{
  hkpRayCollidableFilterVtbl *v4; // rcx
  hkBool *v5; // rbx
  hkBool *v6; // rax
  char v7; // [rsp+30h] [rbp+8h]

  v4 = this->vfptr;
  v5 = result;
  if ( !v4
    || *(_BYTE *)(*((__int64 (__fastcall **)(signed __int64, char *, hkpWorldRayCastInput *, hkpCollidable *))v4[2].isCollisionEnabled
                  + 1))(
                   (signed __int64)&v4[2].isCollisionEnabled,
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

// File Line: 112
// RVA: 0xE14E70
void __fastcall hkpConstrainedSystemFilter::constraintAddedCallback(hkpConstrainedSystemFilter *this, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rbx
  hkpAgentNnEntry *v3; // rax

  v2 = constraint;
  if ( ((unsigned int (*)(void))constraint->m_data->vfptr[1].__first_virtual_table_function__)() != 11 )
  {
    v3 = hkAgentNnMachine_FindAgent(&v2->m_entities[0]->m_collidable, &v2->m_entities[1]->m_collidable);
    if ( v3 )
      hkpWorldAgentUtil::removeAgentAndItsToiEvents(v3);
  }
}

// File Line: 126
// RVA: 0xE14EC0
void __fastcall hkpConstrainedSystemFilter::constraintRemovedCallback(hkpConstrainedSystemFilter *this, hkpConstraintInstance *constraint)
{
  ;
}

