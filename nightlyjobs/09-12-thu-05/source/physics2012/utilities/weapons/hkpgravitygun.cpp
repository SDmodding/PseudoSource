// File Line: 27
// RVA: 0xE156E0
void __fastcall hkpGravityGun::hkpGravityGun(hkpGravityGun *this)
{
  hkpFirstPersonGun::hkpFirstPersonGun(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkpGravityGun::`vftable;
  this->m_grabbedBodies.m_capacityAndFlags = 0x80000000;
  this->m_grabbedBodies.m_data = 0i64;
  this->m_grabbedBodies.m_size = 0;
  this->m_maxNumObjectsPicked = 10;
  this->m_maxMassOfObjectPicked = 200.0;
  this->m_maxDistOfObjectPicked = 50.0;
  this->m_impulseAppliedWhenObjectNotPicked = 100.0;
  this->m_throwVelocity = 50.0;
  this->m_type.m_storage = 3;
  hkStringPtr::operator=(&this->m_name, "GravityGun");
  this->m_capturedObjectPosition = (hkVector4f)_xmm;
  this->m_capturedObjectsOffset.m_quad = _xmm;
}

// File Line: 36
// RVA: 0xE15770
void __fastcall hkpGravityGun::hkpGravityGun(hkpGravityGun *this, hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *p_m_name; // rcx

  p_m_name = &this->m_name;
  p_m_name[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, flag);
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
  if ( flag.m_finishing )
    this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGravityGun::`vftable;
  this->m_grabbedBodies.m_data = 0i64;
  this->m_grabbedBodies.m_size = 0;
  this->m_grabbedBodies.m_capacityAndFlags = 0x80000000;
  if ( flag.m_finishing )
    this->m_type.m_storage = 3;
}

// File Line: 45
// RVA: 0xE15990
hkpRigidBody *__fastcall hkpGravityGun::pickBody(
        hkpGravityGun *this,
        hkTransformf *viewTransform,
        hkpRigidBody *characterBody,
        hkpWorld *world)
{
  __int64 v6; // rdx
  float v7; // xmm7_4
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // rax
  int v9; // ecx
  __int64 v10; // rdx
  int v11; // edi
  __int64 v12; // r13
  __int64 v13; // rsi
  float v14; // xmm8_4
  hkpRigidBody *v15; // rbx
  int v16; // ecx
  int v17; // eax
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  float v21; // xmm1_4
  float v22; // xmm6_4
  __int64 m_size; // rdx
  __int64 v24; // rcx
  hkpRigidBody **m_data; // rax
  hkVector4f v26; // xmm1
  int v28; // [rsp+20h] [rbp-A8h]
  __int64 v29; // [rsp+30h] [rbp-98h]
  __int64 v30; // [rsp+38h] [rbp-90h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v31; // [rsp+40h] [rbp-88h]
  hkpRigidBody *v32; // [rsp+48h] [rbp-80h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_inactiveSimulationIslands; // [rsp+50h] [rbp-78h]
  hkVector4f v34; // [rsp+58h] [rbp-70h] BYREF
  hkpRayHitCollector collector[2]; // [rsp+68h] [rbp-60h] BYREF
  int v36; // [rsp+88h] [rbp-40h]
  int v37; // [rsp+8Ch] [rbp-3Ch]
  int v38; // [rsp+98h] [rbp-30h]
  int v39; // [rsp+B8h] [rbp-10h]
  hkpRigidBody *v40; // [rsp+C8h] [rbp+0h]
  hkpRigidBody *v41; // [rsp+158h] [rbp+90h]
  hkpWorld *v42; // [rsp+160h] [rbp+98h]

  v6 = 2i64;
  p_m_inactiveSimulationIslands = &world->m_inactiveSimulationIslands;
  v29 = 2i64;
  LODWORD(v7) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_34999999), (__m128)LODWORD(FLOAT_0_34999999), 0).m128_u32[0];
  v32 = 0i64;
  p_m_activeSimulationIslands = &world->m_activeSimulationIslands;
  v31 = &world->m_activeSimulationIslands;
  do
  {
    v9 = 0;
    v28 = 0;
    if ( p_m_activeSimulationIslands->m_size > 0 )
    {
      v10 = 0i64;
      v30 = 0i64;
      do
      {
        v11 = 0;
        v12 = *(__int64 *)((char *)p_m_activeSimulationIslands->m_data + v10);
        if ( *(int *)(v12 + 104) > 0 )
        {
          v13 = 0i64;
          LODWORD(v14) = _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_u32[0];
          do
          {
            v15 = *(hkpRigidBody **)(v13 + *(_QWORD *)(v12 + 96));
            hkVector4f::setTransformedInversePos(
              &v34,
              viewTransform,
              &v15->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1);
            v16 = 0;
            v17 = 0;
            v18 = _mm_shuffle_ps(v34.m_quad, v34.m_quad, 0);
            if ( v18.m128_f32[0] > _mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_maxDistOfObjectPicked),
                                     (__m128)LODWORD(this->m_maxDistOfObjectPicked),
                                     0).m128_f32[0] )
              v16 = 1;
            if ( v18.m128_f32[0] < v14 )
              v17 = 1;
            if ( !(v17 | v16) && v15 != v41 )
            {
              v19 = _mm_add_ps(v18, query.m_quad);
              v20 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v34.m_quad, 1u), 1u);
              v21 = _mm_rcp_ps(v19).m128_f32[0];
              v22 = (float)((float)(2.0 - (float)(v21 * v19.m128_f32[0])) * v21)
                  * (float)(_mm_shuffle_ps(v20, v20, 170).m128_f32[0] + _mm_shuffle_ps(v20, v20, 85).m128_f32[0]);
              if ( hkpMotion::getMass(&v15->m_motion) > this->m_maxMassOfObjectPicked )
                v22 = v22 + _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_f32[0];
              if ( v22 <= v7 )
              {
                m_size = this->m_grabbedBodies.m_size;
                v24 = 0i64;
                if ( m_size <= 0 )
                {
LABEL_19:
                  v26.m_quad = (__m128)v15->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
                  v34.m_quad.m128_u64[1] = viewTransform->m_translation.m_quad.m128_u64[0];
                  *(hkVector4f *)&collector[0].m_earlyOutHitFraction = (hkVector4f)v26.m_quad;
                  v40 = 0i64;
                  v36 = 1065353216;
                  v37 = -1;
                  collector[0].vfptr = (hkpRayHitCollectorVtbl *)&hkpClosestRayHitCollector::`vftable;
                  v39 = 0;
                  v38 = -1;
                  collector[0].m_earlyOutHitFraction = 1.0;
                  LOBYTE(v32) = 0;
                  HIDWORD(v32) = 0;
                  p_m_inactiveSimulationIslands = 0i64;
                  hkpWorld::castRay(v42, (hkpWorldRayCastInput *)&v34.m_quad.m128_u16[4], collector);
                  if ( !v40 || v40 == (hkpRigidBody *)&v15->m_collidable )
                  {
                    v7 = v22;
                    v32 = v15;
                  }
                }
                else
                {
                  m_data = this->m_grabbedBodies.m_data;
                  while ( *m_data != v15 )
                  {
                    ++v24;
                    ++m_data;
                    if ( v24 >= m_size )
                      goto LABEL_19;
                  }
                }
              }
            }
            ++v11;
            v13 += 8i64;
          }
          while ( v11 < *(_DWORD *)(v12 + 104) );
          v9 = v28;
          v10 = v30;
        }
        p_m_activeSimulationIslands = v31;
        ++v9;
        v10 += 8i64;
        v28 = v9;
        v30 = v10;
      }
      while ( v9 < v31->m_size );
      v6 = v29;
    }
    p_m_activeSimulationIslands = p_m_inactiveSimulationIslands;
    --v6;
    v31 = p_m_inactiveSimulationIslands;
    v29 = v6;
  }
  while ( v6 );
  return v32;
}

// File Line: 123
// RVA: 0xE15C70
void __fastcall hkpGravityGun::takeObject(hkpGravityGun *this, hkpRigidBody *body)
{
  hkReferencedObject::addReference(body);
  if ( this->m_grabbedBodies.m_size == (this->m_grabbedBodies.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_grabbedBodies.m_data, 8);
  this->m_grabbedBodies.m_data[this->m_grabbedBodies.m_size++] = body;
  hkpRigidBody::setMassInv(
    body,
    _mm_shuffle_ps(body->m_motion.m_inertiaAndMassInv.m_quad, body->m_motion.m_inertiaAndMassInv.m_quad, 255).m128_f32[0]
  * 100.0);
}

// File Line: 130
// RVA: 0xE15CF0
hkpRigidBody *__fastcall hkpGravityGun::dropObject(hkpGravityGun *this, int index)
{
  hkpRigidBody **m_data; // rax
  hkpRigidBody *v3; // rbx
  int v4; // r9d
  hkpRigidBody **v5; // rcx
  int v6; // r9d
  __int64 v7; // rdx
  hkpRigidBody *v8; // rax

  m_data = this->m_grabbedBodies.m_data;
  v3 = m_data[index];
  v4 = --this->m_grabbedBodies.m_size - index;
  v5 = &m_data[index];
  v6 = 8 * v4;
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
    do
    {
      v8 = v5[1];
      *v5++ = v8;
      --v7;
    }
    while ( v7 );
  }
  hkpRigidBody::setMassInv(
    v3,
    _mm_shuffle_ps(v3->m_motion.m_inertiaAndMassInv.m_quad, v3->m_motion.m_inertiaAndMassInv.m_quad, 255).m128_f32[0]
  * 0.0099999998);
  hkReferencedObject::removeReference(v3);
  return v3;
}

// File Line: 139
// RVA: 0xE15D80
void __fastcall hkpGravityGun::gravityGunPull(
        hkpGravityGun *this,
        hkTransformf *viewTransform,
        hkpRigidBody *characterBody,
        hkpWorld *world)
{
  hkpRigidBody *v6; // rax
  hkpRigidBody *v7; // rdi
  __m128 v8; // [rsp+20h] [rbp-18h] BYREF

  v6 = hkpGravityGun::pickBody(this, viewTransform, characterBody, world);
  v7 = v6;
  if ( v6 )
  {
    if ( (float)(v6->m_motion.m_inertiaAndMassInv.m_quad.m128_f32[3] * this->m_maxMassOfObjectPicked) < 1.0
      || this->m_grabbedBodies.m_size >= this->m_maxNumObjectsPicked )
    {
      v8 = _mm_mul_ps(
             viewTransform->m_rotation.m_col0.m_quad,
             _mm_sub_ps(
               (__m128)0i64,
               _mm_shuffle_ps(
                 (__m128)LODWORD(this->m_impulseAppliedWhenObjectNotPicked),
                 (__m128)LODWORD(this->m_impulseAppliedWhenObjectNotPicked),
                 0)));
      hkpEntity::activate(v6);
      v7->m_motion.hkpEntity::vfptr[11].__vecDelDtor(&v7->m_motion, (unsigned int)&v8);
    }
    else
    {
      hkpGravityGun::takeObject(this, v6);
    }
  }
}

// File Line: 158
// RVA: 0xE15E30
void __fastcall hkpGravityGun::gravityGunPush(
        hkpGravityGun *this,
        hkTransformf *viewTransform,
        hkpRigidBody *characterBody,
        hkpWorld *world)
{
  hkpRigidBody *v7; // rbx
  hkpRigidBody *v8; // rax
  hkpRigidBody *v9; // rbx
  __m128 v10; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_grabbedBodies.m_size )
  {
    v7 = hkpGravityGun::dropObject(this, 0);
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(this->m_throwVelocity), (__m128)LODWORD(this->m_throwVelocity), 0),
                viewTransform->m_rotation.m_col0.m_quad),
              _mm_mul_ps(direction.m_quad, (__m128)xmmword_141A711B0)),
            characterBody->m_motion.m_linearVelocity.m_quad);
    hkpEntity::activate(v7);
    v7->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v7->m_motion, (unsigned int)&v10);
    v7->m_collidable.m_broadPhaseHandle.m_objectQualityType = 6;
  }
  else
  {
    v8 = hkpGravityGun::pickBody(this, viewTransform, characterBody, world);
    v9 = v8;
    if ( v8 )
    {
      v10 = _mm_mul_ps(
              viewTransform->m_rotation.m_col0.m_quad,
              _mm_shuffle_ps(
                (__m128)LODWORD(this->m_impulseAppliedWhenObjectNotPicked),
                (__m128)LODWORD(this->m_impulseAppliedWhenObjectNotPicked),
                0));
      hkpEntity::activate(v8);
      v9->m_motion.hkpEntity::vfptr[11].__vecDelDtor(&v9->m_motion, (unsigned int)&v10);
    }
  }
}

// File Line: 182
// RVA: 0xE161F0
void __fastcall hkpGravityGun::gravityGunPutDown(
        hkpGravityGun *this,
        hkTransformf *viewTransform,
        hkpRigidBody *characterBody,
        hkpWorld *world)
{
  if ( this->m_grabbedBodies.m_size )
    hkpGravityGun::dropObject(this, 0);
}

// File Line: 190
// RVA: 0xE15F10
void __fastcall hkpGravityGun::gravityGunStep(
        hkpGravityGun *this,
        float timeStep,
        hkTransformf *viewTransform,
        hkpRigidBody *characterBody)
{
  int v4; // esi
  __int64 v8; // r14
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  __m128 v11; // xmm0
  hkpRigidBody *v12; // rdi
  hkVector4f v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm6
  __m128 v18; // xmm4
  float v19; // xmm6_4
  unsigned __int16 EncodedFloat; // ax
  __m128 v21; // xmm1
  __m128 *p_m_quad; // rdx
  __m128 v23; // xmm2
  __m128 m_quad; // [rsp+18h] [rbp-79h] BYREF
  __m256i b; // [rsp+28h] [rbp-69h] BYREF
  __m128 v26[3]; // [rsp+48h] [rbp-49h] BYREF
  unsigned int v27; // [rsp+F8h] [rbp+67h]

  v4 = 0;
  if ( this->m_grabbedBodies.m_size > 0 )
  {
    v8 = 0i64;
    v9 = _mm_shuffle_ps((__m128)0x3F4CCCCDu, (__m128)0x3F4CCCCDu, 0);
    v27 = 1061997773;
    v10 = _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(0.40000001 / timeStep),
            (__m128)COERCE_UNSIGNED_INT(0.40000001 / timeStep),
            0);
    do
    {
      v11 = 0i64;
      v11.m128_f32[0] = (float)v4;
      *(__m128 *)b.m256i_i8 = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), this->m_capturedObjectsOffset.m_quad),
                                this->m_capturedObjectPosition.m_quad);
      hkVector4f::setTransformedPos((hkVector4f *)&b.m256i_u64[2], viewTransform, (hkVector4f *)&b);
      v12 = this->m_grabbedBodies.m_data[v8];
      v13.m_quad = (__m128)characterBody->m_motion.m_linearVelocity;
      m_quad = v12->m_motion.m_linearVelocity.m_quad;
      m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(v13.m_quad, v12->m_motion.m_linearVelocity.m_quad), v9),
                 v12->m_motion.m_linearVelocity.m_quad);
      m_quad = _mm_add_ps(
                 m_quad,
                 _mm_mul_ps(
                   _mm_sub_ps(
                     *(__m128 *)&b.m256i_u64[2],
                     v12->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad),
                   v10));
      v14 = _mm_mul_ps(m_quad, m_quad);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_andnot_ps(
              _mm_cmple_ps(v15, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                _mm_mul_ps(*(__m128 *)_xmm, v16)));
      v18 = _mm_mul_ps(m_quad, v17);
      v19 = v17.m128_f32[0] * v15.m128_f32[0];
      *(__m128 *)&b.m256i_u64[1] = v18;
      EncodedFloat = hkUFloat8::getEncodedFloat(v12->m_motion.m_motionState.m_maxLinearVelocity.m_value);
      m_quad.m128_i32[2] = (EncodedFloat + 243712) << 12;
      if ( EncodedFloat )
        v27 = m_quad.m128_u32[2];
      else
        v27 = 0;
      v21 = _mm_shuffle_ps((__m128)v27, (__m128)v27, 0);
      if ( v19 < v21.m128_f32[0] )
      {
        hkpEntity::activate(v12);
        p_m_quad = &m_quad;
      }
      else
      {
        m_quad.m128_i32[3] = 1008981770;
        *(__m128 *)&b.m256i_u64[1] = _mm_mul_ps(
                                       *(__m128 *)&b.m256i_u64[1],
                                       _mm_sub_ps(v21, _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0)));
        hkpEntity::activate(v12);
        p_m_quad = (__m128 *)&b.m256i_u64[1];
      }
      v12->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v12->m_motion, (unsigned int)p_m_quad);
      v26[0] = _mm_mul_ps(v12->m_motion.m_angularVelocity.m_quad, v9);
      v23 = _mm_mul_ps(v26[0], v26[0]);
      if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                 + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) > 1.0 )
      {
        hkpEntity::activate(v12);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v12->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
          &v12->m_motion,
          v26);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < this->m_grabbedBodies.m_size );
  }
}

// File Line: 232
// RVA: 0xE157E0
void __fastcall hkpGravityGun::stepGun(
        hkpGravityGun *this,
        float timeStep,
        hkpWorld *world,
        hkpRigidBody *body,
        hkTransformf *viewTransform,
        bool fire,
        bool fireRmb)
{
  int v10; // ebx
  __int64 v11; // rsi
  hkVector4f v12; // xmm1
  int v13; // ebx
  __int64 v14; // rsi
  int v15; // ebx
  __int64 v16; // rsi
  hkVector4f v17; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f v18; // [rsp+30h] [rbp-28h] BYREF

  if ( fire )
  {
    hkpGravityGun::gravityGunPush(this, viewTransform, body, world);
    v10 = 0;
    v17.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_translation;
    if ( this->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, _QWORD))this->m_listeners.m_data[v11]->vfptr[2].__first_virtual_table_function__)(
          this->m_listeners.m_data[v11],
          &v17,
          0i64);
        ++v10;
        ++v11;
      }
      while ( v10 < this->m_listeners.m_size );
    }
  }
  else if ( fireRmb )
  {
    if ( this->m_grabbedBodies.m_size == this->m_maxNumObjectsPicked )
    {
      hkpGravityGun::gravityGunPutDown(this, viewTransform, body, world);
      v15 = 0;
      v18.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_translation;
      if ( this->m_listeners.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, _QWORD))this->m_listeners.m_data[v16]->vfptr[2].__first_virtual_table_function__)(
            this->m_listeners.m_data[v16],
            &v18,
            0i64);
          ++v15;
          ++v16;
        }
        while ( v15 < this->m_listeners.m_size );
      }
    }
    else
    {
      hkpGravityGun::gravityGunPull(this, viewTransform, body, world);
      v12.m_quad = (__m128)body->m_motion.m_motionState.m_transform.m_translation;
      v13 = 0;
      v18.m_quad = (__m128)viewTransform->m_translation;
      v17.m_quad = v12.m_quad;
      if ( this->m_listeners.m_size > 0 )
      {
        v14 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, hkVector4f *, hkVector4f *))this->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
            this->m_listeners.m_data[v14],
            &v18,
            &v17);
          ++v13;
          ++v14;
        }
        while ( v13 < this->m_listeners.m_size );
      }
    }
  }
  hkpGravityGun::gravityGunStep(this, timeStep, viewTransform, body);
}

// File Line: 276
// RVA: 0xE15960
void __fastcall hkpGravityGun::reset(hkpGravityGun *this, hkpWorld *world)
{
  while ( this->m_grabbedBodies.m_size )
    hkpGravityGun::dropObject(this, 0);
}

