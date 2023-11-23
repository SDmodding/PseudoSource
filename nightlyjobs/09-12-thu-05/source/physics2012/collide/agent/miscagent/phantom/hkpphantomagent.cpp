// File Line: 16
// RVA: 0xCF6110
void __fastcall hkpPhantomAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpPhantomAgent::createPhantomAgent;
  f.m_getPenetrationsFunc = hkpPhantomAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpPhantomAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpPhantomAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, PHANTOM_CALLBACK, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, PHANTOM_CALLBACK);
}

// File Line: 33
// RVA: 0xCF6280
void __fastcall hkpPhantomAgent::hkpPhantomAgent(
        hkpPhantomAgent *this,
        hkpCollidable *bodyA,
        hkpCollidable *bodyB,
        hkpContactMgr *contactMgr)
{
  hkpCdBody *m_parent; // rax
  hkpCollidable *i; // r9
  hkpCdBody *v7; // rax
  hkpCollidable *j; // rcx

  this->m_contactMgr = contactMgr;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhantomAgent::`vftable;
  m_parent = bodyA->m_parent;
  for ( i = bodyA; m_parent; m_parent = m_parent->m_parent )
    i = (hkpCollidable *)m_parent;
  this->m_collidableA = i;
  v7 = bodyB->m_parent;
  for ( j = bodyB; v7; v7 = v7->m_parent )
    j = (hkpCollidable *)v7;
  this->m_collidableB = j;
  this->m_bodyTypeA = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  this->m_bodyTypeB = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
}

// File Line: 42
// RVA: 0xCF62F0
hkpCollisionAgent *__fastcall hkpPhantomAgent::createPhantomAgent(
        hkpCollidable *bodyA,
        hkpCollidable *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpPhantomAgent *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rsi
  hkpCdBody *m_parent; // rax
  hkpShape *m_shape; // r14
  hkpCollidable *i; // r8
  hkpCdBody *v15; // rax
  hkpCollidable *j; // rdx
  hkpCdBody *v17; // rax
  hkpShape *k; // r14
  hkpCdBody *m; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpPhantomAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  if ( v9 )
  {
    hkpPhantomAgent::hkpPhantomAgent(v9, bodyA, bodyB, contactMgr);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( *(_DWORD *)(v11 + 56) == 32 )
  {
    m_parent = bodyB->m_parent;
    m_shape = bodyA->m_shape;
    for ( i = bodyB; m_parent; m_parent = m_parent->m_parent )
      i = (hkpCollidable *)m_parent;
    v15 = bodyA->m_parent;
    for ( j = bodyA; v15; v15 = v15->m_parent )
      j = (hkpCollidable *)v15;
    ((void (__fastcall *)(hkpShape *, hkpCollidable *, hkpCollidable *, hkpCollisionInput *))m_shape->vfptr[8].__first_virtual_table_function__)(
      bodyA->m_shape,
      j,
      i,
      input);
    *(_QWORD *)(v11 + 40) = m_shape;
  }
  if ( *(_DWORD *)(v11 + 60) == 32 )
  {
    v17 = bodyA->m_parent;
    for ( k = bodyB->m_shape; v17; v17 = v17->m_parent )
      bodyA = (hkpCollidable *)v17;
    for ( m = bodyB->m_parent; m; m = m->m_parent )
      bodyB = (hkpCollidable *)m;
    ((void (__fastcall *)(hkpShape *, hkpCollidable *, hkpCollidable *, hkpCollisionInput *))k->vfptr[8].__first_virtual_table_function__)(
      k,
      bodyB,
      bodyA,
      input);
    *(_QWORD *)(v11 + 48) = k;
  }
  return (hkpCollisionAgent *)v11;
}

// File Line: 64
// RVA: 0xCF6420
hkpCollisionAgent *__fastcall hkpPhantomAgent::createNoPhantomAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rdi
  hkpShape *m_shape; // rcx
  hkpCdBody *v7; // rbx
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // r8
  hkpCdBody *v10; // rax
  hkpCdBody *j; // rdx
  hkpShape *v12; // rcx
  hkpCdBody *k; // rax
  hkpCdBody *m; // rax

  v4 = bodyA;
  m_shape = bodyA->m_shape;
  v7 = bodyB;
  if ( m_shape->m_type.m_storage == 32 )
  {
    m_parent = bodyB->m_parent;
    for ( i = bodyB; m_parent; m_parent = m_parent->m_parent )
      i = m_parent;
    v10 = v4->m_parent;
    for ( j = v4; v10; v10 = v10->m_parent )
      j = v10;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))m_shape->vfptr[8].__first_virtual_table_function__)(
      m_shape,
      j,
      i,
      input);
  }
  v12 = v7->m_shape;
  if ( v7->m_shape->m_type.m_storage == 32 )
  {
    for ( k = v4->m_parent; k; k = k->m_parent )
      v4 = k;
    for ( m = v7->m_parent; m; m = m->m_parent )
      v7 = m;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))v12->vfptr[8].__first_virtual_table_function__)(
      v12,
      v7,
      v4,
      input);
  }
  return 0i64;
}

// File Line: 87
// RVA: 0xCF6220
void __fastcall hkpPhantomAgent::cleanup(hkpPhantomAgent *this, hkpConstraintOwner *constraintOwner)
{
  if ( this->m_bodyTypeA == PHANTOM_CALLBACK )
    ((void (__fastcall *)(hkpPhantomCallbackShape *, hkpCollidable *, hkpCollidable *))this->m_shapeA->vfptr[9].__vecDelDtor)(
      this->m_shapeA,
      this->m_collidableA,
      this->m_collidableB);
  if ( this->m_bodyTypeB == PHANTOM_CALLBACK )
    ((void (__fastcall *)(hkpPhantomCallbackShape *, hkpCollidable *, hkpCollidable *))this->m_shapeB->vfptr[9].__vecDelDtor)(
      this->m_shapeB,
      this->m_collidableB,
      this->m_collidableA);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 106
// RVA: 0xCF61D0
void __fastcall hkpPhantomAgent::processCollision(
        hkpPhantomAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input)
{
  ;
}

// File Line: 110
// RVA: 0xCF6190
void __fastcall hkpPhantomAgent::getPenetrations(
        hkpPhantomAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  ((void (__fastcall *)(hkpCdBodyPairCollector *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))collector->vfptr->addCdBodyPair)(
    collector,
    bodyA,
    bodyB,
    input);
}

// File Line: 115
// RVA: 0xCF61B0
void __fastcall hkpPhantomAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
}

// File Line: 120
// RVA: 0xCF61E0
void __fastcall hkpPhantomAgent::getClosestPoints(
        hkpPhantomAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input)
{
  ;
}

// File Line: 124
// RVA: 0xCF61F0
void __fastcall hkpPhantomAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *pointDetails)
{
  ;
}

// File Line: 128
// RVA: 0xCF6200
void __fastcall hkpPhantomAgent::linearCast(
        hkpPhantomAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input)
{
  ;
}

// File Line: 132
// RVA: 0xCF6210
void __fastcall hkpPhantomAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector)
{
  ;
}

