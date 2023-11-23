// File Line: 24
// RVA: 0xE14490
void __fastcall hkpBallGun::hkpBallGun(hkpBallGun *this, int numBullets)
{
  _QWORD **Value; // rax
  hkQueue<hkpRigidBody *> *v5; // rax

  hkpFirstPersonGun::hkpFirstPersonGun(this);
  this->m_bulletOffsetFromCenter = 0i64;
  this->m_bulletRadius = 0.2;
  this->m_bulletVelocity = 40.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable;
  this->m_bulletMass = 50.0;
  this->m_damageMultiplier = 50.0;
  this->m_maxBulletsInWorld = numBullets;
  this->m_type.m_storage = 1;
  hkStringPtr::operator=(&this->m_name, "BallGun");
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkQueue<hkpRigidBody *> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
  if ( v5 )
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v5);
  this->m_addedBodies = v5;
  hkQueue<hkpRigidBody *>::setCapacity(v5, numBullets);
}

// File Line: 33
// RVA: 0xE14540
void __fastcall hkpBallGun::~hkpBallGun(hkpBallGun *this)
{
  hkQueue<hkpRigidBody *> *m_addedBodies; // r8
  __int64 m_head; // rdx
  hkpEntity *v4; // rdi
  int v5; // edx
  int v6; // eax
  __int64 i; // rbx
  hkpFirstPersonGunBulletListener *v8; // rcx
  hkpWorld *m_world; // rcx
  hkQueue<hkpRigidBody *> *v10; // rbx
  _QWORD **Value; // rax
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  this->vfptr = (hkBaseObjectVtbl *)&hkpBallGun::`vftable;
  while ( this->m_addedBodies->m_elementsInUse )
  {
    m_addedBodies = this->m_addedBodies;
    m_head = m_addedBodies->m_head;
    v4 = m_addedBodies->m_data[m_head];
    v5 = m_head + 1;
    if ( v5 == m_addedBodies->m_capacity )
      v5 = 0;
    --m_addedBodies->m_elementsInUse;
    m_addedBodies->m_head = v5;
    v6 = this->m_listeners.m_size - 1;
    for ( i = v6; i >= 0; --i )
    {
      v8 = this->m_listeners.m_data[i];
      v8->vfptr[2].__vecDelDtor(v8, (unsigned int)v4);
    }
    m_world = v4->m_world;
    if ( m_world )
      hkpWorld::removeEntity(m_world, &result, v4);
    hkReferencedObject::removeReference(v4);
  }
  v10 = this->m_addedBodies;
  if ( v10 )
  {
    hkQueue<hkpRigidBody *>::~hkQueue<hkpRigidBody *>(this->m_addedBodies);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkQueue<hkpRigidBody *> *, __int64))(*Value[11] + 16i64))(Value[11], v10, 24i64);
  }
  hkpFirstPersonGun::~hkpFirstPersonGun(this);
}

// File Line: 57
// RVA: 0xE14630
void __fastcall hkpBallGun::fireGun(hkpBallGun *this, hkpWorld *world, hkTransformf *viewTransform)
{
  hkVector4f v3; // xmm2
  hkVector4f v6; // xmm6
  _QWORD **Value; // rax
  hkpSphereShape *v8; // rax
  hkpShape *v9; // rax
  float m_bulletMass; // xmm1_4
  float v11; // xmm0_4
  float m_bulletRadius; // xmm3_4
  int v13; // edi
  __int64 v14; // rsi
  _QWORD **v15; // rax
  hkpRigidBody *v16; // rax
  hkpEntity *v17; // rax
  hkpEntity *v18; // r14
  int v19; // esi
  __int64 v20; // rdi
  hkQueue<hkpRigidBody *> *m_addedBodies; // rdi
  int m_capacity; // edx
  int v23; // edx
  hkQueue<hkpRigidBody *> *v24; // r8
  __int64 m_head; // rdx
  hkpEntity *v26; // rsi
  int v27; // edx
  int v28; // eax
  __int64 i; // rdi
  hkpFirstPersonGunBulletListener *v30; // rcx
  hkVector4f sweepStart; // [rsp+30h] [rbp-A8h] BYREF
  __int128 v32; // [rsp+40h] [rbp-98h] BYREF
  __m256i position; // [rsp+50h] [rbp-88h] BYREF
  hkpRigidBodyCinfo bodyInfo; // [rsp+70h] [rbp-68h] BYREF
  hkResult result; // [rsp+198h] [rbp+C0h] BYREF

  v3.m_quad = (__m128)viewTransform->m_translation;
  result.m_enum = LODWORD(FLOAT_200_0);
  v6.m_quad = (__m128)viewTransform->m_rotation.m_col0;
  *(hkVector4f *)position.m256i_i8 = (hkVector4f)v3.m_quad;
  sweepStart.m_quad = _mm_add_ps(v3.m_quad, v6.m_quad);
  *(__m128 *)&position.m256i_u64[2] = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)LODWORD(FLOAT_200_0), (__m128)LODWORD(FLOAT_200_0), 0),
                                          v6.m_quad),
                                        sweepStart.m_quad);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v8 )
    hkpSphereShape::hkpSphereShape(v8, this->m_bulletRadius);
  else
    v9 = 0i64;
  m_bulletMass = this->m_bulletMass;
  bodyInfo.m_shape = v9;
  LOBYTE(bodyInfo.m_rollingFrictionMultiplier) = 6;
  bodyInfo.m_centerOfMass.m_quad.m128_i8[12] = 2;
  bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_f32[2] = m_bulletMass;
  bodyInfo.m_mass = FLOAT_0_0099999998;
  bodyInfo.m_centerOfMass.m_quad.m128_f32[0] = FLOAT_0_2;
  bodyInfo.m_inertiaTensor.m_col2.m_quad.m128_i32[2] = (int)FLOAT_1_0;
  hkpInertiaTensorComputer::setShapeVolumeMassProperties(v9, m_bulletMass * 2.0, &bodyInfo);
  v11 = this->m_bulletMass;
  m_bulletRadius = this->m_bulletRadius;
  *(__m128 *)&position.m256i_u64[1] = _mm_add_ps(this->m_bulletOffsetFromCenter.m_quad, sweepStart.m_quad);
  bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_u64[1] = LODWORD(v11);
  bodyInfo.m_inertiaTensor.m_col2.m_quad.m128_f32[0] = FLOAT_0_40000001;
  if ( hkpFirstPersonGun::sweepSphere(
         &result,
         world,
         &sweepStart,
         m_bulletRadius,
         (hkVector4f *)&position.m256i_u64[2],
         (hkpFirstPersonGun::SweepSphereOut *)&bodyInfo.m_allowedPenetrationDepth)->m_enum )
    *(__m128 *)&bodyInfo.m_shape = _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_bulletVelocity),
                                       (__m128)LODWORD(this->m_bulletVelocity),
                                       0),
                                     v6.m_quad);
  else
    hkpFirstPersonGun::calcVelocityToTarget(
      (hkVector4f *)&position.m256i_u64[1],
      (hkVector4f *)&bodyInfo.m_allowedPenetrationDepth,
      &world->m_gravity,
      this->m_bulletVelocity,
      (hkVector4f *)&bodyInfo.m_shape);
  v13 = 0;
  v32 = *(_OWORD *)&bodyInfo.m_allowedPenetrationDepth;
  if ( this->m_listeners.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, __m256i *, __int128 *))this->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
        this->m_listeners.m_data[v14],
        &position,
        &v32);
      ++v13;
      ++v14;
    }
    while ( v13 < this->m_listeners.m_size );
  }
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(v15[11], 720i64);
  if ( v16 )
  {
    hkpRigidBody::hkpRigidBody(v16, &bodyInfo);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  hkReferencedObject::removeReference(bodyInfo.m_shape);
  v19 = 0;
  v18->m_damageMultiplier = this->m_damageMultiplier;
  if ( this->m_listeners.m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkpEntity *))this->m_listeners.m_data[v20]->vfptr[1].__first_virtual_table_function__)(
        this->m_listeners.m_data[v20],
        v18);
      ++v19;
      ++v20;
    }
    while ( v19 < this->m_listeners.m_size );
  }
  hkpWorld::addEntity(world, v18, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  m_addedBodies = this->m_addedBodies;
  m_capacity = m_addedBodies->m_capacity;
  if ( m_addedBodies->m_elementsInUse >= m_capacity )
  {
    if ( m_capacity )
      v23 = 2 * m_capacity;
    else
      v23 = 8;
    hkQueue<hkpRigidBody *>::setCapacity(this->m_addedBodies, v23);
  }
  if ( m_addedBodies->m_tail == m_addedBodies->m_capacity )
    m_addedBodies->m_tail = 0;
  m_addedBodies->m_data[m_addedBodies->m_tail++] = (hkpRigidBody *)v18;
  ++m_addedBodies->m_elementsInUse;
  v24 = this->m_addedBodies;
  if ( v24->m_elementsInUse > this->m_maxBulletsInWorld )
  {
    m_head = v24->m_head;
    v26 = v24->m_data[m_head];
    v27 = m_head + 1;
    if ( v27 == v24->m_capacity )
      v27 = 0;
    --v24->m_elementsInUse;
    v24->m_head = v27;
    v28 = this->m_listeners.m_size - 1;
    for ( i = v28; i >= 0; --i )
    {
      v30 = this->m_listeners.m_data[i];
      v30->vfptr[2].__vecDelDtor(v30, (unsigned int)v26);
    }
    if ( v26->m_world )
      hkpWorld::removeEntity(world, (hkBool *)&result, v26);
    hkReferencedObject::removeReference(v26);
  }
}

// File Line: 127
// RVA: 0xE14950
void __fastcall hkpBallGun::reset(hkpBallGun *this, hkpWorld *world)
{
  hkQueue<hkpRigidBody *> *i; // r8
  __int64 m_head; // rdx
  hkpEntity *v6; // rdi
  int v7; // edx
  int v8; // eax
  __int64 j; // rbx
  hkpFirstPersonGunBulletListener *v10; // rcx
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  for ( i = this->m_addedBodies; i->m_elementsInUse; i = this->m_addedBodies )
  {
    m_head = i->m_head;
    v6 = i->m_data[m_head];
    v7 = m_head + 1;
    if ( v7 == i->m_capacity )
      v7 = 0;
    --i->m_elementsInUse;
    i->m_head = v7;
    v8 = this->m_listeners.m_size - 1;
    for ( j = v8; j >= 0; --j )
    {
      v10 = this->m_listeners.m_data[j];
      v10->vfptr[2].__vecDelDtor(v10, (unsigned int)v6);
    }
    if ( v6->m_world == world )
      hkpWorld::removeEntity(world, &result, v6);
    hkReferencedObject::removeReference(v6);
  }
}

