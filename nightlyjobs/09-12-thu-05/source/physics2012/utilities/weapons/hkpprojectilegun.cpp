// File Line: 20
// RVA: 0xE194D0
void __fastcall hkpGunProjectile::hkpGunProjectile(hkpGunProjectile *this, hkpProjectileGun *gun, hkpRigidBody *body)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpGunProjectile::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpGunProjectile::`vftable{for `hkpContactListener};
  this->m_flags.m_storage = 0;
  this->m_body = body;
  this->m_existanceTime = 0.0;
  this->m_gun = gun;
  hkReferencedObject::addReference(body);
}

// File Line: 25
// RVA: 0xE19520
void __fastcall hkpGunProjectile::~hkpGunProjectile(hkpGunProjectile *this)
{
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpGunProjectile::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpGunProjectile::`vftable{for `hkpContactListener};
  hkpGunProjectile::_destroyBody(this);
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 30
// RVA: 0xE19570
void __fastcall hkpGunProjectile::destroy(hkpGunProjectile *this)
{
  if ( (this->m_flags.m_storage & 1) == 0 )
  {
    this->hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__(this);
    this->m_flags.m_storage |= 1u;
  }
}

// File Line: 39
// RVA: 0xE19610
void __fastcall hkpGunProjectile::addToWorld(hkpGunProjectile *this, hkpWorld *world)
{
  if ( (this->m_flags.m_storage & 4) != 0 )
    hkpEntity::addContactListener(this->m_body, &this->hkpContactListener);
  hkpWorld::addEntity(world, this->m_body, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
}

// File Line: 49
// RVA: 0xE19660
void __fastcall hkpGunProjectile::removeFromWorld(hkpGunProjectile *this)
{
  hkpRigidBody *m_body; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  m_body = this->m_body;
  if ( m_body )
  {
    hkpWorld::removeEntity(m_body->m_world, &result, m_body);
    if ( (this->m_flags.m_storage & 4) != 0 )
      hkpEntity::removeContactListener(this->m_body, &this->hkpContactListener);
  }
}

// File Line: 63
// RVA: 0xE19950
// attributes: thunk
void __fastcall hkpGunProjectile::onDestroy(hkpGunProjectile *this)
{
  hkpGunProjectile::_destroyBody(this);
}

// File Line: 68
// RVA: 0xE19960
void __fastcall hkpGunProjectile::_destroyBody(hkpGunProjectile *this)
{
  hkpRigidBody *m_body; // rax

  m_body = this->m_body;
  if ( m_body )
  {
    if ( m_body->m_world )
      hkpGunProjectile::removeFromWorld(this);
    hkReferencedObject::removeReference(this->m_body);
    this->m_body = 0i64;
  }
}

// File Line: 81
// RVA: 0xE196B0
void __fastcall hkpGunProjectile::update(hkpGunProjectile *this, float timeStep)
{
  hkBaseObjectVtbl *vfptr; // rax

  if ( (this->m_flags.m_storage & 1) == 0 )
  {
    vfptr = this->hkReferencedObject::hkBaseObject::vfptr;
    this->m_existanceTime = timeStep + this->m_existanceTime;
    ((void (*)(void))vfptr[2].__first_virtual_table_function__)();
  }
}

// File Line: 90
// RVA: 0xE195A0
void __fastcall hkpGunProjectile::setHitListening(hkpGunProjectile *this, bool enable)
{
  hkpRigidBody *m_body; // rcx
  hkpContactListener *v5; // rdx

  if ( enable != ((this->m_flags.m_storage & 4) != 0) )
  {
    m_body = this->m_body;
    if ( m_body && m_body->m_world )
    {
      v5 = &this->hkpContactListener;
      if ( !enable )
      {
        hkpEntity::removeContactListener(m_body, v5);
LABEL_9:
        this->m_flags.m_storage &= ~4u;
        return;
      }
      hkpEntity::addContactListener(m_body, v5);
    }
    if ( enable )
    {
      this->m_flags.m_storage |= 4u;
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
  hkVector4f v5; // xmm1
  __m128 v6; // xmm1
  __m128 m_quad; // xmm9
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
  hkTransformf bTc; // [rsp+20h] [rbp-118h] BYREF
  hkVector4f axis; // [rsp+60h] [rbp-D8h] BYREF
  hkMatrix3f v24; // [rsp+70h] [rbp-C8h] BYREF
  hkMatrix3f aTb; // [rsp+A0h] [rbp-98h] BYREF
  unsigned int v26; // [rsp+148h] [rbp+10h]

  v3.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  *(float *)&v26 = minVelocity * minVelocity;
  v5.m_quad = (__m128)body->m_motion.m_linearVelocity;
  bTc.m_rotation.m_col1 = body->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v6 = _mm_mul_ps(v5.m_quad, v5.m_quad);
  m_quad = body->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  bTc.m_translation = body->m_motion.m_motionState.m_transform.m_translation;
  bTc.m_rotation.m_col2 = (hkVector4f)v3.m_quad;
  bTc.m_rotation.m_col0.m_quad = m_quad;
  if ( (float)((float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0] + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
             + _mm_shuffle_ps(v6, v6, 170).m128_f32[0]) > _mm_shuffle_ps((__m128)v26, (__m128)v26, 0).m128_f32[0] )
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
              _mm_cmple_ps(v11, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                _mm_mul_ps(*(__m128 *)_xmm, v12))));
    v14 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v13),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), m_quad));
    v15 = _mm_shuffle_ps(v14, v14, 201);
    v16 = _mm_mul_ps(v15, v15);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    v19 = _mm_andnot_ps(
            _mm_cmple_ps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                _mm_mul_ps(*(__m128 *)_xmm, v18)),
              v17)).m128_f32[0];
    if ( v19 > _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0).m128_f32[0] )
    {
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170));
      v21 = _mm_rsqrt_ps(v20);
      axis.m_quad = _mm_mul_ps(
                      v15,
                      _mm_andnot_ps(
                        _mm_cmple_ps(v20, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                          _mm_mul_ps(*(__m128 *)_xmm, v21))));
      hkRotationf::setAxisAngle((hkRotationf *)&aTb, &axis, (float)(v19 * timeStep) * -5.0);
      hkMatrix3f::setMul(&v24, &aTb, &bTc.m_rotation);
      bTc.m_rotation = (hkRotationf)v24;
      hkpRigidBody::setTransform(body, &bTc);
    }
  }
}

// File Line: 154
// RVA: 0xE199A0
void __fastcall hkpProjectileGun::hkpProjectileGun(
        hkpProjectileGun *this,
        hkpWorld *world,
        struct hkdWorld *destructionWorld)
{
  hkpFirstPersonGun::hkpFirstPersonGun(this);
  this->m_maxProjectiles = 5;
  *(_QWORD *)&this->m_reloadTime = 1050253722i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpProjectileGun::`vftable;
  this->m_projectiles.m_capacityAndFlags = 0x80000000;
  this->m_projectiles.m_data = 0i64;
  this->m_projectiles.m_size = 0;
  this->m_world = world;
  this->m_destructionWorld = destructionWorld;
}

// File Line: 159
// RVA: 0xE19AB0
void __fastcall hkpProjectileGun::clearProjectiles(hkpProjectileGun *this)
{
  __int64 m_size; // rbp
  __int64 v2; // rdi
  hkpGunProjectile *v4; // rbx

  m_size = this->m_projectiles.m_size;
  v2 = 0i64;
  if ( m_size <= 0 )
  {
    this->m_projectiles.m_size = 0;
  }
  else
  {
    do
    {
      v4 = this->m_projectiles.m_data[v2];
      hkpGunProjectile::destroy(v4);
      hkReferencedObject::removeReference(v4);
      ++v2;
    }
    while ( v2 < m_size );
    this->m_projectiles.m_size = 0;
  }
}

// File Line: 171
// RVA: 0xE19B40
void __fastcall hkpProjectileGun::destroyAgedProjectiles(hkpProjectileGun *this, float time)
{
  __int64 m_size; // rdi
  __int64 i; // rbx
  hkpGunProjectile *v5; // rcx

  m_size = this->m_projectiles.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    v5 = this->m_projectiles.m_data[i];
    if ( time < v5->m_existanceTime )
      hkpGunProjectile::destroy(v5);
  }
}

// File Line: 184
// RVA: 0xE19C30
void __fastcall hkpProjectileGun::updateProjectiles(hkpProjectileGun *this, float timeStep)
{
  __int64 m_size; // rsi
  __int64 i; // rbx

  m_size = this->m_projectiles.m_size;
  for ( i = 0i64; i < m_size; ++i )
    hkpGunProjectile::update(this->m_projectiles.m_data[i], timeStep);
}

// File Line: 194
// RVA: 0xE19CA0
void __fastcall hkpProjectileGun::clearHitProjectiles(hkpProjectileGun *this)
{
  __int64 m_size; // r9
  __int64 i; // rax
  hkpGunProjectile *v3; // r8

  m_size = this->m_projectiles.m_size;
  for ( i = 0i64; i < m_size; v3->m_flags.m_storage &= ~2u )
    v3 = this->m_projectiles.m_data[i++];
}

// File Line: 203
// RVA: 0xE19BB0
void __fastcall hkpProjectileGun::removeDestroyedProjectiles(hkpProjectileGun *this)
{
  int m_size; // ebp
  int v2; // ebx
  __int64 v4; // rdi
  hkpGunProjectile *v5; // rcx
  __int64 v6; // rax

  m_size = this->m_projectiles.m_size;
  v2 = 0;
  if ( m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = this->m_projectiles.m_data[v4];
      if ( (v5->m_flags.m_storage & 1) != 0 )
      {
        hkReferencedObject::removeReference(v5);
        v6 = --this->m_projectiles.m_size;
        if ( (_DWORD)v6 != v2 )
          this->m_projectiles.m_data[v4] = this->m_projectiles.m_data[v6];
        --m_size;
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < m_size );
  }
}

// File Line: 220
// RVA: 0xE19D10
void __fastcall hkpProjectileGun::addProjectile(hkpProjectileGun *this, hkpGunProjectile *proj)
{
  hkReferencedObject::addReference(proj);
  if ( this->m_projectiles.m_size == (this->m_projectiles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_projectiles.m_data, 8);
  this->m_projectiles.m_data[this->m_projectiles.m_size++] = proj;
  hkpGunProjectile::addToWorld(proj, this->m_world);
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
void __fastcall hkpProjectileGun::stepGun(
        hkpProjectileGun *this,
        float timeStep,
        hkpWorld *world,
        hkpRigidBody *characterBody,
        hkTransformf *viewTransform,
        bool fire,
        bool fireRmb)
{
  float m_reload; // xmm2_4

  m_reload = this->m_reload;
  if ( m_reload > 0.0 )
    this->m_reload = m_reload - timeStep;
  ((void (__fastcall *)(hkpProjectileGun *, hkBaseObjectVtbl *, hkpWorld *, hkpRigidBody *))this->vfptr[5].__vecDelDtor)(
    this,
    this->vfptr,
    world,
    characterBody);
}

// File Line: 252
// RVA: 0xE19A80
void __fastcall hkpProjectileGun::onUpdate(
        hkpProjectileGun *this,
        float timeStep,
        hkpWorld *world,
        hkpRigidBody *characterBody,
        hkTransformf *viewTransform,
        bool fire,
        bool fireRmb)
{
  hkpProjectileGun::updateProjectiles(this, timeStep);
  hkpProjectileGun::clearHitProjectiles(this);
  hkpProjectileGun::removeDestroyedProjectiles(this);
}

// File Line: 259
// RVA: 0xE19CD0
hkpGunProjectile *__fastcall hkpProjectileGun::getFirstActiveProjectile(hkpProjectileGun *this)
{
  __int64 m_size; // r8
  __int64 v2; // rax
  hkpGunProjectile **i; // rcx

  m_size = this->m_projectiles.m_size;
  v2 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = this->m_projectiles.m_data; ((*i)->m_flags.m_storage & 1) != 0; ++i )
  {
    if ( ++v2 >= m_size )
      return 0i64;
  }
  return *i;
}

// File Line: 273
// RVA: 0xE19A70
// attributes: thunk
void __fastcall hkpProjectileGun::reset(hkpProjectileGun *this, hkpWorld *world)
{
  hkpProjectileGun::clearProjectiles(this);
}

