// File Line: 29
// RVA: 0xE14A60
void __fastcall hkpConstrainedSystemFilter::hkpConstrainedSystemFilter(
        hkpConstrainedSystemFilter *this,
        hkpCollisionFilter *otherFilter)
{
  hkpCollisionFilter::hkpCollisionFilter(this);
  this->m_otherFilter = otherFilter;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstrainedSystemFilter::`vftable;
  if ( otherFilter )
    hkReferencedObject::addReference(otherFilter);
}

// File Line: 39
// RVA: 0xE14AE0
void __fastcall hkpConstrainedSystemFilter::~hkpConstrainedSystemFilter(hkpConstrainedSystemFilter *this)
{
  hkpCollisionFilter *m_otherFilter; // rcx

  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkReferencedObject};
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpConstrainedSystemFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstrainedSystemFilter::`vftable;
  m_otherFilter = this->m_otherFilter;
  if ( m_otherFilter )
    hkReferencedObject::removeReference(m_otherFilter);
  this->hkpConstraintListener::vfptr = (hkpConstraintListenerVtbl *)&hkpConstraintListener::`vftable;
  this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpRayCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpRayShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpShapeCollectionFilter::`vftable;
  this->hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpCollidableCollidableFilter::`vftable;
  this->hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 47
// RVA: 0xE14B90
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(
        hkpConstrainedSystemFilter *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  int v4; // edi
  hkpEntity *v6; // rbp
  hkpEntity *v7; // rsi
  __int64 v8; // rcx
  int NumConstraints; // ebx
  hkpEntity *v11; // r15
  bool v12; // al
  int v13; // ebp
  hkpConstraintInstance *Constraint; // rax
  hkpConstraintInstance *v15; // rbx
  char v16; // [rsp+40h] [rbp+8h] BYREF

  v4 = 0;
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
      NumConstraints = hkpEntity::getNumConstraints(v7);
      v11 = v6;
      v12 = (int)hkpEntity::getNumConstraints(v6) > NumConstraints;
      if ( v12 )
        v11 = v7;
      if ( v12 )
        v7 = v6;
      v13 = hkpEntity::getNumConstraints(v11);
      if ( v13 <= 0 )
      {
LABEL_22:
        result->m_bool = 1;
      }
      else
      {
        while ( 1 )
        {
          Constraint = hkpEntity::getConstraint(v11, v4);
          v15 = Constraint;
          if ( Constraint )
          {
            if ( ((unsigned int (__fastcall *)(hkpConstraintData *))Constraint->m_data->vfptr[1].__first_virtual_table_function__)(Constraint->m_data) != 11
              && (v15->m_entities[0] == v7 || v15->m_entities[1] == v7) )
            {
              break;
            }
          }
          if ( ++v4 >= v13 )
            goto LABEL_22;
        }
        result->m_bool = 0;
      }
      return result;
    }
    else
    {
      result->m_bool = 1;
      return result;
    }
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 89
// RVA: 0xE14CD0
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(
        hkpConstrainedSystemFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  __int64 v7; // rcx
  char v10; // [rsp+50h] [rbp+8h] BYREF

  v7 = *(_QWORD *)&this->m_type.m_storage;
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

// File Line: 95
// RVA: 0xE14D40
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(
        hkpConstrainedSystemFilter *this,
        hkBool *result,
        hkpCollisionInput *input,
        hkpCdBody *collectionBodyA,
        hkpCdBody *collectionBodyB,
        hkpShapeContainer *containerShapeA,
        hkpShapeContainer *containerShapeB,
        unsigned int keyA,
        unsigned int keyB)
{
  __int64 v9; // rcx
  char v12; // [rsp+60h] [rbp+8h] BYREF

  v9 = *(_QWORD *)&this->m_type.m_storage;
  if ( !v9
    || *(_BYTE *)(**(__int64 (__fastcall ***)(__int64, char *, hkpCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, hkpShapeContainer *, unsigned int, unsigned int))(v9 + 24))(
                   v9 + 24,
                   &v12,
                   input,
                   collectionBodyA,
                   collectionBodyB,
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

// File Line: 101
// RVA: 0xE14DD0
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(
        hkpConstrainedSystemFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *bContainer,
        unsigned int bKey)
{
  __int64 v5; // rcx
  char v8; // [rsp+40h] [rbp+8h] BYREF

  v5 = *(_QWORD *)this->m_prepad;
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

// File Line: 106
// RVA: 0xE14E20
hkBool *__fastcall hkpConstrainedSystemFilter::isCollisionEnabled(
        hkpConstrainedSystemFilter *this,
        hkBool *result,
        hkpWorldRayCastInput *a,
        hkpCollidable *collidableB)
{
  hkpRayCollidableFilterVtbl *vfptr; // rcx
  char v7; // [rsp+30h] [rbp+8h] BYREF

  vfptr = this->hkpCollisionFilter::hkpRayCollidableFilter::vfptr;
  if ( !vfptr
    || *(_BYTE *)(*((__int64 (__fastcall **)(__int64, char *, hkpWorldRayCastInput *, hkpCollidable *))vfptr[2].isCollisionEnabled
                  + 1))(
                   (__int64)&vfptr[2].isCollisionEnabled,
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

// File Line: 112
// RVA: 0xE14E70
void __fastcall hkpConstrainedSystemFilter::constraintAddedCallback(
        hkpConstrainedSystemFilter *this,
        hkpConstraintInstance *constraint)
{
  hkpAgentNnEntry *Agent; // rax

  if ( ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) != 11 )
  {
    Agent = hkAgentNnMachine_FindAgent(
              &constraint->m_entities[0]->m_collidable,
              &constraint->m_entities[1]->m_collidable);
    if ( Agent )
      hkpWorldAgentUtil::removeAgentAndItsToiEvents(Agent);
  }
}

// File Line: 126
// RVA: 0xE14EC0
void __fastcall hkpConstrainedSystemFilter::constraintRemovedCallback(
        hkpConstrainedSystemFilter *this,
        hkpConstraintInstance *constraint)
{
  ;
}

