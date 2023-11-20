// File Line: 24
// RVA: 0xE14490
void __fastcall hkpBallGun::hkpBallGun(hkpBallGun *this, int numBullets)
{
  int v2; // edi
  hkpBallGun *v3; // rbx
  _QWORD **v4; // rax
  hkQueue<hkpRigidBody *> *v5; // rax

  v2 = numBullets;
  v3 = this;
  hkpFirstPersonGun::hkpFirstPersonGun((hkpFirstPersonGun *)&this->vfptr);
  v3->m_bulletOffsetFromCenter = 0i64;
  v3->m_bulletRadius = 0.2;
  v3->m_bulletVelocity = 40.0;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable';
  v3->m_bulletMass = 50.0;
  v3->m_damageMultiplier = 50.0;
  v3->m_maxBulletsInWorld = v2;
  v3->m_type.m_storage = 1;
  hkStringPtr::operator=(&v3->m_name, "BallGun");
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkQueue<hkpRigidBody *> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 24i64);
  if ( v5 )
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v5);
  v3->m_addedBodies = v5;
  hkQueue<hkpRigidBody *>::setCapacity(v5, v2);
}

// File Line: 33
// RVA: 0xE14540
void __fastcall hkpBallGun::~hkpBallGun(hkpBallGun *this)
{
  hkpBallGun *v1; // rsi
  hkQueue<hkpRigidBody *> *v2; // r8
  __int64 v3; // rdx
  hkpEntity *v4; // rdi
  int v5; // edx
  int v6; // eax
  __int64 i; // rbx
  hkpFirstPersonGunBulletListener *v8; // rcx
  hkpWorld *v9; // rcx
  hkQueue<hkpRigidBody *> *v10; // rbx
  _QWORD **v11; // rax
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable';
  while ( v1->m_addedBodies->m_elementsInUse )
  {
    v2 = v1->m_addedBodies;
    v3 = v2->m_head;
    v4 = (hkpEntity *)&v2->m_data[v3]->vfptr;
    v5 = v3 + 1;
    if ( v5 == v2->m_capacity )
      v5 = 0;
    --v2->m_elementsInUse;
    v2->m_head = v5;
    v6 = v1->m_listeners.m_size - 1;
    for ( i = v6; i >= 0; --i )
    {
      v8 = v1->m_listeners.m_data[i];
      v8->vfptr[2].__vecDelDtor((hkBaseObject *)&v8->vfptr, (unsigned int)v4);
    }
    v9 = v4->m_world;
    if ( v9 )
      hkpWorld::removeEntity(v9, &result, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
  }
  v10 = v1->m_addedBodies;
  if ( v10 )
  {
    hkQueue<hkpRigidBody *>::~hkQueue<hkpRigidBody *>(v1->m_addedBodies);
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkQueue<hkpRigidBody *> *, signed __int64))(*v11[11] + 16i64))(
      v11[11],
      v10,
      24i64);
  }
  hkpFirstPersonGun::~hkpFirstPersonGun((hkpFirstPersonGun *)&v1->vfptr);
}

// File Line: 57
// RVA: 0xE14630
void __fastcall hkpBallGun::fireGun(hkpBallGun *this, hkpWorld *world, hkTransformf *viewTransform)
{
  __m128 v3; // xmm2
  hkpBallGun *v4; // rbx
  hkpWorld *v5; // r15
  hkVector4f v6; // xmm6
  _QWORD **v7; // rax
  hkpSphereShape *v8; // rax
  hkpShape *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  int v13; // edi
  __int64 v14; // rsi
  _QWORD **v15; // rax
  hkpRigidBody *v16; // rax
  hkpEntity *v17; // rax
  hkpEntity *v18; // r14
  int v19; // esi
  __int64 v20; // rdi
  hkQueue<hkpRigidBody *> *v21; // rdi
  int v22; // edx
  int v23; // edx
  hkQueue<hkpRigidBody *> *v24; // r8
  __int64 v25; // rdx
  hkpEntity *v26; // rsi
  int v27; // edx
  int v28; // eax
  __int64 i; // rdi
  hkpFirstPersonGunBulletListener *v30; // rcx
  hkVector4f sweepStart; // [rsp+30h] [rbp-A8h]
  __int128 v32; // [rsp+40h] [rbp-98h]
  hkVector4f position; // [rsp+50h] [rbp-88h]
  hkVector4f sweepEnd; // [rsp+60h] [rbp-78h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+70h] [rbp-68h]
  hkResult result; // [rsp+198h] [rbp+C0h]

  v3 = viewTransform->m_translation.m_quad;
  result.m_enum = LODWORD(FLOAT_200_0);
  v4 = this;
  v5 = world;
  v6.m_quad = (__m128)viewTransform->m_rotation.m_col0;
  position.m_quad = v3;
  sweepStart.m_quad = _mm_add_ps(v3, v6.m_quad);
  sweepEnd.m_quad = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps((__m128)LODWORD(FLOAT_200_0), (__m128)LODWORD(FLOAT_200_0), 0),
                        v6.m_quad),
                      sweepStart.m_quad);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 56i64);
  if ( v8 )
    hkpSphereShape::hkpSphereShape(v8, v4->m_bulletRadius);
  else
    v9 = 0i64;
  v10 = v4->m_bulletMass;
  bodyInfo.m_shape = v9;
  LOBYTE(bodyInfo.m_rollingFrictionMultiplier) = 6;
  bodyInfo.m_centerOfMass.m_quad.m128_i8[12] = 2;
  bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_f32[2] = v10;
  bodyInfo.m_mass = FLOAT_0_0099999998;
  bodyInfo.m_centerOfMass.m_quad.m128_f32[0] = FLOAT_0_2;
  bodyInfo.m_inertiaTensor.m_col2.m_quad.m128_i32[2] = (signed int)FLOAT_1_0;
  hkpInertiaTensorComputer::setShapeVolumeMassProperties(v9, v10 * 2.0, &bodyInfo);
  v11 = v4->m_bulletMass;
  v12 = v4->m_bulletRadius;
  *(hkVector4f *)((char *)&position + 8) = (hkVector4f)_mm_add_ps(
                                                         v4->m_bulletOffsetFromCenter.m_quad,
                                                         sweepStart.m_quad);
  bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_u64[1] = LODWORD(v11);
  bodyInfo.m_inertiaTensor.m_col2.m_quad.m128_f32[0] = FLOAT_0_40000001;
  if ( hkpFirstPersonGun::sweepSphere(
         &result,
         v5,
         &sweepStart,
         v12,
         &sweepEnd,
         (hkpFirstPersonGun::SweepSphereOut *)&bodyInfo.m_allowedPenetrationDepth)->m_enum )
    *(__m128 *)&bodyInfo.m_shape = _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       (__m128)LODWORD(v4->m_bulletVelocity),
                                       (__m128)LODWORD(v4->m_bulletVelocity),
                                       0),
                                     v6.m_quad);
  else
    hkpFirstPersonGun::calcVelocityToTarget(
      (hkVector4f *)((char *)&position + 8),
      (hkVector4f *)&bodyInfo.m_allowedPenetrationDepth,
      &v5->m_gravity,
      v4->m_bulletVelocity,
      (hkVector4f *)&bodyInfo.m_shape);
  v13 = 0;
  _mm_store_si128((__m128i *)&v32, *(__m128i *)&bodyInfo.m_allowedPenetrationDepth);
  if ( v4->m_listeners.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, __int128 *))v4->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
        v4->m_listeners.m_data[v14],
        &position,
        &v32);
      ++v13;
      ++v14;
    }
    while ( v13 < v4->m_listeners.m_size );
  }
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 720i64);
  if ( v16 )
  {
    hkpRigidBody::hkpRigidBody(v16, &bodyInfo);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&bodyInfo.m_shape->vfptr);
  v19 = 0;
  v18->m_damageMultiplier = v4->m_damageMultiplier;
  if ( v4->m_listeners.m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkpEntity *))v4->m_listeners.m_data[v20]->vfptr[1].__first_virtual_table_function__)(
        v4->m_listeners.m_data[v20],
        v18);
      ++v19;
      ++v20;
    }
    while ( v19 < v4->m_listeners.m_size );
  }
  hkpWorld::addEntity(v5, v18, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  v21 = v4->m_addedBodies;
  v22 = v21->m_capacity;
  if ( v21->m_elementsInUse >= v22 )
  {
    if ( v22 )
      v23 = 2 * v22;
    else
      v23 = 8;
    hkQueue<hkpRigidBody *>::setCapacity(v4->m_addedBodies, v23);
  }
  if ( v21->m_tail == v21->m_capacity )
    v21->m_tail = 0;
  v21->m_data[v21->m_tail++] = (hkpRigidBody *)v18;
  ++v21->m_elementsInUse;
  v24 = v4->m_addedBodies;
  if ( v24->m_elementsInUse > v4->m_maxBulletsInWorld )
  {
    v25 = v24->m_head;
    v26 = (hkpEntity *)&v24->m_data[v25]->vfptr;
    v27 = v25 + 1;
    if ( v27 == v24->m_capacity )
      v27 = 0;
    --v24->m_elementsInUse;
    v24->m_head = v27;
    v28 = v4->m_listeners.m_size - 1;
    for ( i = v28; i >= 0; --i )
    {
      v30 = v4->m_listeners.m_data[i];
      v30->vfptr[2].__vecDelDtor((hkBaseObject *)&v30->vfptr, (unsigned int)v26);
    }
    if ( v26->m_world )
      hkpWorld::removeEntity(v5, (hkBool *)&result, v26);
    hkReferencedObject::removeReference((hkReferencedObject *)&v26->vfptr);
  }
}

// File Line: 127
// RVA: 0xE14950
void __fastcall hkpBallGun::reset(hkpBallGun *this, hkpWorld *world)
{
  hkQueue<hkpRigidBody *> *v2; // r8
  hkpWorld *v3; // rbp
  hkpBallGun *i; // rsi
  __int64 v5; // rdx
  hkpEntity *v6; // rdi
  int v7; // edx
  int v8; // eax
  __int64 j; // rbx
  hkpFirstPersonGunBulletListener *v10; // rcx
  hkBool result; // [rsp+40h] [rbp+8h]

  v2 = this->m_addedBodies;
  v3 = world;
  for ( i = this; v2->m_elementsInUse; v2 = i->m_addedBodies )
  {
    v5 = v2->m_head;
    v6 = (hkpEntity *)&v2->m_data[v5]->vfptr;
    v7 = v5 + 1;
    if ( v7 == v2->m_capacity )
      v7 = 0;
    --v2->m_elementsInUse;
    v2->m_head = v7;
    v8 = i->m_listeners.m_size - 1;
    for ( j = v8; j >= 0; --j )
    {
      v10 = i->m_listeners.m_data[j];
      v10->vfptr[2].__vecDelDtor((hkBaseObject *)&v10->vfptr, (unsigned int)v6);
    }
    if ( v6->m_world == v3 )
      hkpWorld::removeEntity(v3, &result, v6);
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
  }
}

