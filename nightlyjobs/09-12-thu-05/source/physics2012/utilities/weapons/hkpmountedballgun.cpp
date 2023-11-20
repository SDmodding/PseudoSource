// File Line: 19
// RVA: 0xE16B10
void __fastcall hkpMountedBallGun::hkpMountedBallGun(hkpMountedBallGun *this, hkFinishLoadedObjectFlag flag)
{
  hkpMountedBallGun *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpBallGun::hkpBallGun((hkpBallGun *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMountedBallGun::`vftable;
  if ( v3 )
    v2->m_type.m_storage = 4;
}

// File Line: 28
// RVA: 0xE16AC0
void __fastcall hkpMountedBallGun::hkpMountedBallGun(hkpMountedBallGun *this, int numBullets)
{
  hkpMountedBallGun *v2; // rbx

  v2 = this;
  hkpBallGun::hkpBallGun((hkpBallGun *)&this->vfptr, numBullets);
  v2->m_type.m_storage = 4;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMountedBallGun::`vftable;
  hkStringPtr::operator=(&v2->m_name, "MountedBallGun");
  v2->m_position = (hkVector4f)_xmm;
}

// File Line: 35
// RVA: 0xE16B50
void __fastcall hkpMountedBallGun::fireGun(hkpMountedBallGun *this, hkpWorld *world, hkTransformf *viewTransform)
{
  hkVector4f v3; // xmm2
  hkpMountedBallGun *v4; // rbx
  hkpWorld *v5; // r15
  hkVector4f v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  _QWORD **v9; // rax
  hkpSphereShape *v10; // rax
  hkpShape *v11; // rax
  float v12; // xmm1_4
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
  hkpWorld *v31; // rcx
  __int128 v32; // [rsp+30h] [rbp-D0h]
  hkVector4f sweepEnd; // [rsp+40h] [rbp-C0h]
  hkVector4f sweepStart; // [rsp+50h] [rbp-B0h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+60h] [rbp-A0h]
  hkpFirstPersonGun::SweepSphereOut out; // [rsp+140h] [rbp+40h]
  hkResult result; // [rsp+1B0h] [rbp+B0h]

  v3.m_quad = (__m128)viewTransform->m_translation;
  v4 = this;
  result.m_enum = LODWORD(FLOAT_200_0);
  v5 = world;
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
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 56i64);
  if ( v10 )
    hkpSphereShape::hkpSphereShape(v10, v4->m_bulletRadius);
  else
    v11 = 0i64;
  v12 = v4->m_bulletMass;
  bodyInfo.m_shape = v11;
  bodyInfo.m_qualityType.m_storage = 6;
  bodyInfo.m_motionType.m_storage = 2;
  bodyInfo.m_mass = v12;
  bodyInfo.m_restitution = FLOAT_0_2;
  bodyInfo.m_allowedPenetrationDepth = FLOAT_0_0099999998;
  bodyInfo.m_position = v4->m_position;
  LODWORD(bodyInfo.m_friction) = (_DWORD)FLOAT_1_0;
  hkpInertiaTensorComputer::setShapeVolumeMassProperties(v11, v12 * 2.0, &bodyInfo);
  bodyInfo.m_mass = v4->m_bulletMass;
  bodyInfo.m_linearDamping = 0.0;
  bodyInfo.m_angularDamping = FLOAT_0_40000001;
  if ( hkpFirstPersonGun::sweepSphere(&result, v5, &sweepStart, 0.050000001, &sweepEnd, &out)->m_enum )
    bodyInfo.m_linearVelocity.m_quad = _mm_mul_ps(
                                         _mm_shuffle_ps(
                                           (__m128)LODWORD(v4->m_bulletVelocity),
                                           (__m128)LODWORD(v4->m_bulletVelocity),
                                           0),
                                         v6.m_quad);
  else
    hkpFirstPersonGun::calcVelocityToTarget(
      &bodyInfo.m_position,
      &out.m_contactPoint.m_position,
      &v5->m_gravity,
      v4->m_bulletVelocity,
      &bodyInfo.m_linearVelocity);
  v13 = 0;
  _mm_store_si128((__m128i *)&v32, (__m128i)out.m_contactPoint.m_position.m_quad);
  if ( v4->m_listeners.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, __int128 *))v4->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
        v4->m_listeners.m_data[v14],
        &v4->m_position,
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
    v31 = v26->m_world;
    if ( v31 )
      hkpWorld::removeEntity(v31, (hkBool *)&result, v26);
    hkReferencedObject::removeReference((hkReferencedObject *)&v26->vfptr);
  }
}

