// File Line: 20
// RVA: 0xE194D0
void __fastcall hkpGunProjectile::hkpGunProjectile(hkpGunProjectile *this, hkpProjectileGun *gun, hkpRigidBody *body)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGunProjectile::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpGunProjectile::`vftable{for `hkpContactListener};
  this->m_flags.m_storage = 0;
  this->m_body = body;
  this->m_existanceTime = 0.0;
  this->m_gun = gun;
  hkReferencedObject::addReference((hkReferencedObject *)&body->vfptr);
}

// File Line: 25
// RVA: 0xE19520
void __fastcall hkpGunProjectile::~hkpGunProjectile(hkpGunProjectile *this)
{
  hkpGunProjectile *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGunProjectile::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpGunProjectile::`vftable{for `hkpContactListener};
  hkpGunProjectile::_destroyBody(this);
  v1->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 30
// RVA: 0xE19570
void __fastcall hkpGunProjectile::destroy(hkpGunProjectile *this)
{
  hkpGunProjectile *v1; // rbx

  v1 = this;
  if ( !(this->m_flags.m_storage & 1) )
  {
    ((void (*)(void))this->vfptr[1].__first_virtual_table_function__)();
    v1->m_flags.m_storage |= 1u;
  }
}

// File Line: 39
// RVA: 0xE19610
void __fastcall hkpGunProjectile::addToWorld(hkpGunProjectile *this, hkpWorld *world)
{
  hkpWorld *v2; // rdi
  hkpGunProjectile *v3; // rbx

  v2 = world;
  v3 = this;
  if ( this->m_flags.m_storage & 4 )
    hkpEntity::addContactListener((hkpEntity *)&this->m_body->vfptr, (hkpContactListener *)&this->vfptr);
  hkpWorld::addEntity(v2, (hkpEntity *)&v3->m_body->vfptr, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
}

// File Line: 49
// RVA: 0xE19660
void __fastcall hkpGunProjectile::removeFromWorld(hkpGunProjectile *this)
{
  hkpGunProjectile *v1; // rbx
  hkpRigidBody *v2; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->m_body;
  if ( v2 )
  {
    hkpWorld::removeEntity(v2->m_world, &result, (hkpEntity *)&v2->vfptr);
    if ( v1->m_flags.m_storage & 4 )
      hkpEntity::removeContactListener((hkpEntity *)&v1->m_body->vfptr, (hkpContactListener *)&v1->vfptr);
  }
}

// File Line: 63
// RVA: 0xE19950
void __fastcall hkpGunProjectile::onDestroy(hkpGunProjectile *this)
{
  hkpGunProjectile::_destroyBody(this);
}

// File Line: 68
// RVA: 0xE19960
void __fastcall hkpGunProjectile::_destroyBody(hkpGunProjectile *this)
{
  hkpRigidBody *v1; // rax
  hkpGunProjectile *v2; // rbx

  v1 = this->m_body;
  v2 = this;
  if ( v1 )
  {
    if ( v1->m_world )
      hkpGunProjectile::removeFromWorld(this);
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_body->vfptr);
    v2->m_body = 0i64;
  }
}

// File Line: 81
// RVA: 0xE196B0
void __fastcall hkpGunProjectile::update(hkpGunProjectile *this, float timeStep)
{
  hkBaseObjectVtbl *v2; // rax

  if ( !(this->m_flags.m_storage & 1) )
  {
    v2 = this->vfptr;
    this->m_existanceTime = timeStep + this->m_existanceTime;
    ((void (*)(void))v2[2].__first_virtual_table_function__)();
  }
}

// File Line: 90
// RVA: 0xE195A0
void __fastcall hkpGunProjectile::setHitListening(hkpGunProjectile *this, bool enable)
{
  bool v2; // di
  hkpGunProjectile *v3; // rbx
  hkpRigidBody *v4; // rcx
  hkpContactListener *v5; // rdx

  v2 = enable;
  v3 = this;
  if ( enable != (((unsigned __int8)this->m_flags.m_storage >> 2) & 1) )
  {
    v4 = this->m_body;
    if ( v4 && v4->m_world )
    {
      v5 = (hkpContactListener *)&v3->vfptr;
      if ( !v2 )
      {
        hkpEntity::removeContactListener((hkpEntity *)&v4->vfptr, v5);
LABEL_9:
        v3->m_flags.m_storage &= 0xFBu;
        return;
      }
      hkpEntity::addContactListener((hkpEntity *)&v4->vfptr, v5);
    }
    if ( v2 )
    {
      v3->m_flags.m_storage |= 4u;
      return;
    }
    goto LABEL_9;
  }
}

// File Line: 120
// RVA: 0xE196E0
void __fastcall hkpGunProjectile::flyTrue(hkpRigidBody *body, float minVelocity, float timeStep)
{
  hkVector4f v3; // xmm3
  hkpRigidBody *v4; // rbx
  hkVector4f v5; // xmm1
  __m128 v6; // xmm1
  __m128 v7; // xmm9
  float v8; // xmm10_4
  hkVector4f v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm7
  __m128 v15; // xmm7
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  float v19; // xmm5_4
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  hkMatrix3f bTc; // [rsp+20h] [rbp-118h]
  hkVector4f v23; // [rsp+50h] [rbp-E8h]
  hkVector4f axis; // [rsp+60h] [rbp-D8h]
  hkMatrix3f v25; // [rsp+70h] [rbp-C8h]
  hkMatrix3f aTb; // [rsp+A0h] [rbp-98h]
  unsigned int v27; // [rsp+148h] [rbp+10h]

  v3.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v4 = body;
  *(float *)&v27 = minVelocity * minVelocity;
  v5.m_quad = (__m128)body->m_motion.m_linearVelocity;
  bTc.m_col1 = body->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v6 = _mm_mul_ps(v5.m_quad, v5.m_quad);
  v7 = body->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v23.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_translation;
  bTc.m_col2 = (hkVector4f)v3.m_quad;
  v8 = timeStep;
  bTc.m_col0.m_quad = v7;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170))) > COERCE_FLOAT(_mm_shuffle_ps((__m128)v27, (__m128)v27, 0)) )
  {
    v9.m_quad = (__m128)body->m_motion.m_linearVelocity;
    v10 = _mm_mul_ps(v9.m_quad, v9.m_quad);
    v11 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170));
    v12 = _mm_rsqrt_ps(v11);
    v13 = _mm_mul_ps(
            v9.m_quad,
            _mm_andnot_ps(
              _mm_cmpleps(v11, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                _mm_mul_ps(*(__m128 *)_xmm, v12))));
    v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v7));
    v15 = _mm_shuffle_ps(v14, v14, 201);
    v16 = _mm_mul_ps(v15, v15);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    LODWORD(v19) = (unsigned __int128)_mm_andnot_ps(
                                        _mm_cmpleps(v17, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                          v17));
    if ( v19 > COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0)) )
    {
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170));
      v21 = _mm_rsqrt_ps(v20);
      axis.m_quad = _mm_mul_ps(
                      v15,
                      _mm_andnot_ps(
                        _mm_cmpleps(v20, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                          _mm_mul_ps(*(__m128 *)_xmm, v21))));
      hkRotationf::setAxisAngle((hkRotationf *)&aTb, &axis, (float)(v19 * v8) * -5.0);
      hkMatrix3f::setMul(&v25, &aTb, &bTc);
      bTc = v25;
      hkpRigidBody::setTransform(v4, (hkTransformf *)&bTc);
    }
  }
}

// File Line: 154
// RVA: 0xE199A0
void __fastcall hkpProjectileGun::hkpProjectileGun(hkpProjectileGun *this, hkpWorld *world, struct hkdWorld *destructionWorld)
{
  struct hkdWorld *v3; // rsi
  hkpWorld *v4; // rbx
  hkpProjectileGun *v5; // rdi

  v3 = destructionWorld;
  v4 = world;
  v5 = this;
  hkpFirstPersonGun::hkpFirstPersonGun((hkpFirstPersonGun *)&this->vfptr);
  v5->m_maxProjectiles = 5;
  *(_QWORD *)&v5->m_reloadTime = 1050253722i64;
  v5->vfptr = (hkBaseObjectVtbl *)&hkpProjectileGun::`vftable;
  v5->m_projectiles.m_capacityAndFlags = 2147483648;
  v5->m_projectiles.m_data = 0i64;
  v5->m_projectiles.m_size = 0;
  v5->m_world = v4;
  v5->m_destructionWorld = v3;
}

// File Line: 159
// RVA: 0xE19AB0
void __fastcall hkpProjectileGun::clearProjectiles(hkpProjectileGun *this)
{
  __int64 v1; // rbp
  __int64 v2; // rdi
  hkpProjectileGun *v3; // rsi
  hkpGunProjectile *v4; // rbx

  v1 = this->m_projectiles.m_size;
  v2 = 0i64;
  v3 = this;
  if ( v1 <= 0 )
  {
    this->m_projectiles.m_size = 0;
  }
  else
  {
    do
    {
      v4 = v3->m_projectiles.m_data[v2];
      hkpGunProjectile::destroy(v4);
      hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
      ++v2;
    }
    while ( v2 < v1 );
    v3->m_projectiles.m_size = 0;
  }
}

// File Line: 171
// RVA: 0xE19B40
void __fastcall hkpProjectileGun::destroyAgedProjectiles(hkpProjectileGun *this, float time)
{
  __int64 v2; // rdi
  __int64 v3; // rbx
  hkpProjectileGun *i; // rsi
  hkpGunProjectile *v5; // rcx

  v2 = this->m_projectiles.m_size;
  v3 = 0i64;
  for ( i = this; v3 < v2; ++v3 )
  {
    v5 = i->m_projectiles.m_data[v3];
    if ( time < v5->m_existanceTime )
      hkpGunProjectile::destroy(v5);
  }
}

// File Line: 184
// RVA: 0xE19C30
void __fastcall hkpProjectileGun::updateProjectiles(hkpProjectileGun *this, float timeStep)
{
  __int64 v2; // rsi
  __int64 v3; // rbx
  hkpProjectileGun *i; // rdi

  v2 = this->m_projectiles.m_size;
  v3 = 0i64;
  for ( i = this; v3 < v2; ++v3 )
    hkpGunProjectile::update(i->m_projectiles.m_data[v3], timeStep);
}

// File Line: 194
// RVA: 0xE19CA0
void __fastcall hkpProjectileGun::clearHitProjectiles(hkpProjectileGun *this)
{
  __int64 v1; // r9
  __int64 i; // rax
  hkpGunProjectile *v3; // r8

  v1 = this->m_projectiles.m_size;
  for ( i = 0i64; i < v1; v3->m_flags.m_storage &= 0xFDu )
    v3 = this->m_projectiles.m_data[++i - 1];
}

// File Line: 203
// RVA: 0xE19BB0
void __fastcall hkpProjectileGun::removeDestroyedProjectiles(hkpProjectileGun *this)
{
  int v1; // ebp
  int v2; // ebx
  hkpProjectileGun *v3; // rsi
  __int64 v4; // rdi
  hkpGunProjectile *v5; // rcx
  __int64 v6; // rax

  v1 = this->m_projectiles.m_size;
  v2 = 0;
  v3 = this;
  if ( v1 > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v3->m_projectiles.m_data[v4];
      if ( v5->m_flags.m_storage & 1 )
      {
        hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
        v6 = --v3->m_projectiles.m_size;
        if ( (_DWORD)v6 != v2 )
          v3->m_projectiles.m_data[v4] = v3->m_projectiles.m_data[v6];
        --v1;
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < v1 );
  }
}

// File Line: 220
// RVA: 0xE19D10
void __fastcall hkpProjectileGun::addProjectile(hkpProjectileGun *this, hkpGunProjectile *proj)
{
  hkpProjectileGun *v2; // rsi
  hkpGunProjectile *v3; // rdi

  v2 = this;
  v3 = proj;
  hkReferencedObject::addReference((hkReferencedObject *)&proj->vfptr);
  if ( v2->m_projectiles.m_size == (v2->m_projectiles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_projectiles, 8);
  v2->m_projectiles.m_data[v2->m_projectiles.m_size++] = v3;
  hkpGunProjectile::addToWorld(v3, v2->m_world);
}

// File Line: 231
// RVA: 0xE19A50
void __fastcall hkpProjectileGun::fireGun(hkpProjectileGun *this, hkpWorld *world, hkTransformf *viewTransform)
{
  if ( this->m_reload <= 0.0 )
  {
    this->m_reload = this->m_reloadTime;
    ((void (__fastcall *)(hkpProjectileGun *, hkpWorld *, hkTransformf *))this->vfptr[4].__first_virtual_table_function__)(
      this,
      world,
      viewTransform);
  }
}

// File Line: 243
// RVA: 0xE19A10
void __fastcall hkpProjectileGun::stepGun(hkpProjectileGun *this, float timeStep, hkpWorld *world, hkpRigidBody *characterBody, hkTransformf *viewTransform, bool fire, bool fireRmb)
{
  float v7; // xmm2_4

  v7 = this->m_reload;
  if ( v7 > 0.0 )
    this->m_reload = v7 - timeStep;
  ((void (__fastcall *)(hkpProjectileGun *, hkBaseObjectVtbl *, hkpWorld *, hkpRigidBody *))this->vfptr[5].__vecDelDtor)(
    this,
    this->vfptr,
    world,
    characterBody);
}

// File Line: 252
// RVA: 0xE19A80
void __fastcall hkpProjectileGun::onUpdate(hkpProjectileGun *this, float timeStep, hkpWorld *world, hkpRigidBody *characterBody, hkTransformf *viewTransform, bool fire, bool fireRmb)
{
  hkpProjectileGun *v7; // rbx

  v7 = this;
  hkpProjectileGun::updateProjectiles(this, timeStep);
  hkpProjectileGun::clearHitProjectiles(v7);
  hkpProjectileGun::removeDestroyedProjectiles(v7);
}

// File Line: 259
// RVA: 0xE19CD0
hkpGunProjectile *__fastcall hkpProjectileGun::getFirstActiveProjectile(hkpProjectileGun *this)
{
  __int64 v1; // r8
  __int64 v2; // rax
  hkpGunProjectile **v3; // rcx

  v1 = this->m_projectiles.m_size;
  v2 = 0i64;
  if ( v1 <= 0 )
    return 0i64;
  v3 = this->m_projectiles.m_data;
  while ( (*v3)->m_flags.m_storage & 1 )
  {
    ++v2;
    ++v3;
    if ( v2 >= v1 )
      return 0i64;
  }
  return *v3;
}

// File Line: 273
// RVA: 0xE19A70
void __fastcall hkpProjectileGun::reset(hkpProjectileGun *this, hkpWorld *world)
{
  hkpProjectileGun::clearProjectiles(this);
}

