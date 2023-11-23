// File Line: 19
// RVA: 0xE16B10
void __fastcall hkpMountedBallGun::hkpMountedBallGun(hkpMountedBallGun *this, hkFinishLoadedObjectFlag flag)
{
  hkpBallGun::hkpBallGun(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMountedBallGun::`vftable;
  if ( flag.m_finishing )
    this->m_type.m_storage = 4;
}

// File Line: 28
// RVA: 0xE16AC0
void __fastcall hkpMountedBallGun::hkpMountedBallGun(hkpMountedBallGun *this, int numBullets)
{
  hkpBallGun::hkpBallGun(this, numBullets);
  this->m_type.m_storage = 4;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMountedBallGun::`vftable;
  hkStringPtr::operator=(&this->m_name, "MountedBallGun");
  this->m_position = (hkVector4f)_xmm;
}

// File Line: 35
// RVA: 0xE16B50
void __fastcall hkpMountedBallGun::fireGun(hkpMountedBallGun *this, hkpWorld *world, hkTransformf *viewTransform)
{
  hkVector4f v3; // xmm2
  hkVector4f v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  _QWORD **Value; // rax
  hkpSphereShape *v10; // rax
  hkpShape *v11; // rax
  float m_bulletMass; // xmm1_4
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
  hkpWorld *m_world; // rcx
  hkVector4f v32; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f sweepEnd; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f sweepStart; // [rsp+50h] [rbp-B0h] BYREF
  hkpRigidBodyCinfo bodyInfo; // [rsp+60h] [rbp-A0h] BYREF
  hkpFirstPersonGun::SweepSphereOut out; // [rsp+140h] [rbp+40h] BYREF
  hkResult result; // [rsp+1B0h] [rbp+B0h] BYREF

  v3.m_quad = (__m128)viewTransform->m_translation;
  result.m_enum = LODWORD(FLOAT_200_0);
  v6.m_quad = (__m128)viewTransform->m_rotation.m_col0;
  v7 = _mm_add_ps(v3.m_quad, viewTransform->m_rotation.m_col0.m_quad);
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_200_0), (__m128)LODWORD(FLOAT_200_0), 0),
           viewTransform->m_rotation.m_col0.m_quad),
         v7);
  sweepStart.m_quad = v7;
  sweepEnd.m_quad = v8;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v10 )
    hkpSphereShape::hkpSphereShape(v10, this->m_bulletRadius);
  else
    v11 = 0i64;
  m_bulletMass = this->m_bulletMass;
  bodyInfo.m_shape = v11;
  bodyInfo.m_qualityType.m_storage = 6;
  bodyInfo.m_motionType.m_storage = 2;
  bodyInfo.m_mass = m_bulletMass;
  bodyInfo.m_restitution = FLOAT_0_2;
  bodyInfo.m_allowedPenetrationDepth = FLOAT_0_0099999998;
  bodyInfo.m_position = this->m_position;
  LODWORD(bodyInfo.m_friction) = (_DWORD)FLOAT_1_0;
  hkpInertiaTensorComputer::setShapeVolumeMassProperties(v11, m_bulletMass * 2.0, &bodyInfo);
  bodyInfo.m_mass = this->m_bulletMass;
  bodyInfo.m_linearDamping = 0.0;
  bodyInfo.m_angularDamping = FLOAT_0_40000001;
  if ( hkpFirstPersonGun::sweepSphere(&result, world, &sweepStart, 0.050000001, &sweepEnd, &out)->m_enum )
    bodyInfo.m_linearVelocity.m_quad = _mm_mul_ps(
                                         _mm_shuffle_ps(
                                           (__m128)LODWORD(this->m_bulletVelocity),
                                           (__m128)LODWORD(this->m_bulletVelocity),
                                           0),
                                         v6.m_quad);
  else
    hkpFirstPersonGun::calcVelocityToTarget(
      &bodyInfo.m_position,
      &out.m_contactPoint.m_position,
      &world->m_gravity,
      this->m_bulletVelocity,
      &bodyInfo.m_linearVelocity);
  v13 = 0;
  v32.m_quad = (__m128)out.m_contactPoint.m_position;
  if ( this->m_listeners.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, hkVector4f *))this->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
        this->m_listeners.m_data[v14],
        &this->m_position,
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
    m_world = v26->m_world;
    if ( m_world )
      hkpWorld::removeEntity(m_world, (hkBool *)&result, v26);
    hkReferencedObject::removeReference(v26);
  }
}

