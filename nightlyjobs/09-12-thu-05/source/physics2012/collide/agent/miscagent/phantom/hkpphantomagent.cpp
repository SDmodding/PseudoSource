// File Line: 16
// RVA: 0xCF6110
void __fastcall hkpPhantomAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpPhantomAgent::createPhantomAgent;
  f.m_getPenetrationsFunc = hkpPhantomAgent::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpPhantomAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpPhantomAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, PHANTOM_CALLBACK, ALL_SHAPE_TYPES);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, ALL_SHAPE_TYPES, PHANTOM_CALLBACK);
}

// File Line: 33
// RVA: 0xCF6280
void __fastcall hkpPhantomAgent::hkpPhantomAgent(hkpPhantomAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpContactMgr *contactMgr)
{
  hkpCdBody *v4; // rax
  hkpPhantomAgent *v5; // r10
  hkpCollidable *i; // r9
  hkpCdBody *v7; // rax
  hkpCdBody *j; // rcx

  this->m_contactMgr = contactMgr;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhantomAgent::`vftable;
  v4 = bodyA->m_parent;
  v5 = this;
  for ( i = (hkpCollidable *)bodyA; v4; v4 = v4->m_parent )
    i = (hkpCollidable *)v4;
  this->m_collidableA = i;
  v7 = bodyB->m_parent;
  for ( j = bodyB; v7; v7 = v7->m_parent )
    j = v7;
  v5->m_collidableB = (hkpCollidable *)j;
  v5->m_bodyTypeA = (unsigned __int8)bodyA->m_shape->m_type.m_storage;
  v5->m_bodyTypeB = (unsigned __int8)bodyB->m_shape->m_type.m_storage;
}

// File Line: 42
// RVA: 0xCF62F0
hkpCollisionAgent *__fastcall hkpPhantomAgent::createPhantomAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpCdBody *v4; // rdi
  hkpContactMgr *v5; // rsi
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rbx
  _QWORD **v8; // rax
  hkpPhantomAgent *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rsi
  hkpCdBody *v12; // rax
  hkpShape *v13; // r14
  hkpCdBody *i; // r8
  hkpCdBody *v15; // rax
  hkpCdBody *j; // rdx
  hkpCdBody *v17; // rax
  hkpShape *k; // r14
  hkpCdBody *l; // rax

  v4 = bodyA;
  v5 = contactMgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpPhantomAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 64i64);
  if ( v9 )
  {
    hkpPhantomAgent::hkpPhantomAgent(v9, v4, v7, v5);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( *(_DWORD *)(v11 + 56) == 32 )
  {
    v12 = v7->m_parent;
    v13 = v4->m_shape;
    for ( i = v7; v12; v12 = v12->m_parent )
      i = v12;
    v15 = v4->m_parent;
    for ( j = v4; v15; v15 = v15->m_parent )
      j = v15;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))v13->vfptr[8].__first_virtual_table_function__)(
      v4->m_shape,
      j,
      i,
      v6);
    *(_QWORD *)(v11 + 40) = v13;
  }
  if ( *(_DWORD *)(v11 + 60) == 32 )
  {
    v17 = v4->m_parent;
    for ( k = v7->m_shape; v17; v17 = v17->m_parent )
      v4 = v17;
    for ( l = v7->m_parent; l; l = l->m_parent )
      v7 = l;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))k->vfptr[8].__first_virtual_table_function__)(
      k,
      v7,
      v4,
      v6);
    *(_QWORD *)(v11 + 48) = k;
  }
  return (hkpCollisionAgent *)v11;
}

// File Line: 64
// RVA: 0xCF6420
hkpCollisionAgent *__fastcall hkpPhantomAgent::createNoPhantomAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rdi
  hkpShape *v5; // rcx
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // rax
  hkpCdBody *i; // r8
  hkpCdBody *v10; // rax
  hkpCdBody *j; // rdx
  hkpShape *v12; // rcx
  hkpCdBody *k; // rax
  hkpCdBody *l; // rax

  v4 = bodyA;
  v5 = bodyA->m_shape;
  v6 = input;
  v7 = bodyB;
  if ( v5->m_type.m_storage == 32 )
  {
    v8 = bodyB->m_parent;
    for ( i = bodyB; v8; v8 = v8->m_parent )
      i = v8;
    v10 = v4->m_parent;
    for ( j = v4; v10; v10 = v10->m_parent )
      j = v10;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))v5->vfptr[8].__first_virtual_table_function__)(
      v5,
      j,
      i,
      v6);
  }
  v12 = v7->m_shape;
  if ( v7->m_shape->m_type.m_storage == 32 )
  {
    for ( k = v4->m_parent; k; k = k->m_parent )
      v4 = k;
    for ( l = v7->m_parent; l; l = l->m_parent )
      v7 = l;
    ((void (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))v12->vfptr[8].__first_virtual_table_function__)(
      v12,
      v7,
      v4,
      v6);
  }
  return 0i64;
}

// File Line: 87
// RVA: 0xCF6220
void __fastcall hkpPhantomAgent::cleanup(hkpPhantomAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpPhantomAgent *v2; // rbx

  v2 = this;
  if ( this->m_bodyTypeA == 32 )
    ((void (__fastcall *)(hkpPhantomCallbackShape *, hkpCollidable *, hkpCollidable *))this->m_shapeA->vfptr[9].__vecDelDtor)(
      this->m_shapeA,
      this->m_collidableA,
      this->m_collidableB);
  if ( v2->m_bodyTypeB == 32 )
    ((void (__fastcall *)(hkpPhantomCallbackShape *, hkpCollidable *, hkpCollidable *))v2->m_shapeB->vfptr[9].__vecDelDtor)(
      v2->m_shapeB,
      v2->m_collidableB,
      v2->m_collidableA);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 106
// RVA: 0xCF61D0
void __fastcall hkpPhantomAgent::processCollision(hkpPhantomAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpProcessCollisionInput *input)
{
  ;
}

// File Line: 110
// RVA: 0xCF6190
void __fastcall hkpPhantomAgent::getPenetrations(hkpPhantomAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  ((void (__fastcall *)(hkpCdBodyPairCollector *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))collector->vfptr->addCdBodyPair)(
    collector,
    bodyA,
    bodyB,
    input);
}

// File Line: 115
// RVA: 0xCF61B0
void __fastcall hkpPhantomAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
}

// File Line: 120
// RVA: 0xCF61E0
void __fastcall hkpPhantomAgent::getClosestPoints(hkpPhantomAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input)
{
  ;
}

// File Line: 124
// RVA: 0xCF61F0
void __fastcall hkpPhantomAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *pointDetails)
{
  ;
}

// File Line: 128
// RVA: 0xCF6200
void __fastcall hkpPhantomAgent::linearCast(hkpPhantomAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input)
{
  ;
}

// File Line: 132
// RVA: 0xCF6210
void __fastcall hkpPhantomAgent::staticLinearCast(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector)
{
  ;
}

