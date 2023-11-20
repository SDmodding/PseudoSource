// File Line: 27
// RVA: 0xE156E0
void __fastcall hkpGravityGun::hkpGravityGun(hkpGravityGun *this)
{
  hkpGravityGun *v1; // rbx

  v1 = this;
  hkpFirstPersonGun::hkpFirstPersonGun((hkpFirstPersonGun *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkpGravityGun::`vftable';
  v1->m_grabbedBodies.m_capacityAndFlags = 2147483648;
  v1->m_grabbedBodies.m_data = 0i64;
  v1->m_grabbedBodies.m_size = 0;
  v1->m_maxNumObjectsPicked = 10;
  v1->m_maxMassOfObjectPicked = 200.0;
  v1->m_maxDistOfObjectPicked = 50.0;
  v1->m_impulseAppliedWhenObjectNotPicked = 100.0;
  v1->m_throwVelocity = 50.0;
  v1->m_type.m_storage = 3;
  hkStringPtr::operator=(&v1->m_name, "GravityGun");
  v1->m_capturedObjectPosition = (hkVector4f)_xmm;
  v1->m_capturedObjectsOffset.m_quad = _xmm;
}

// File Line: 36
// RVA: 0xE15770
void __fastcall hkpGravityGun::hkpGravityGun(hkpGravityGun *this, hkFinishLoadedObjectFlag flag)
{
  hkpGravityGun *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // [rsp+38h] [rbp+10h]

  v4 = flag.m_finishing;
  v2 = this;
  v3 = &this->m_name;
  v3[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable';
  hkStringPtr::hkStringPtr(v3, flag);
  v2->m_listeners.m_capacityAndFlags = 2147483648;
  v2->m_listeners.m_data = 0i64;
  v2->m_listeners.m_size = 0;
  if ( v4 )
    v2->m_type.m_storage = 0;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpGravityGun::`vftable';
  v2->m_grabbedBodies.m_data = 0i64;
  v2->m_grabbedBodies.m_size = 0;
  v2->m_grabbedBodies.m_capacityAndFlags = 2147483648;
  if ( v4 )
    v2->m_type.m_storage = 3;
}

// File Line: 45
// RVA: 0xE15990
hkpRigidBody *__fastcall hkpGravityGun::pickBody(hkpGravityGun *this, hkTransformf *viewTransform, hkpRigidBody *characterBody, hkpWorld *world)
{
  hkpGravityGun *v4; // r14
  hkTransformf *v5; // r12
  signed __int64 v6; // rdx
  float v7; // xmm7_4
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v8; // rax
  int v9; // ecx
  __int64 v10; // rdx
  int v11; // edi
  __int64 v12; // r13
  __int64 v13; // rsi
  float v14; // xmm8_4
  hkpRigidBody *v15; // rbx
  signed int v16; // ecx
  signed int v17; // eax
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  float v21; // xmm1_4
  float v22; // xmm6_4
  __int64 v23; // rdx
  __int64 v24; // rcx
  hkpRigidBody **v25; // rax
  hkVector4f v26; // xmm1
  int v28; // [rsp+20h] [rbp-A8h]
  signed __int64 v29; // [rsp+30h] [rbp-98h]
  __int64 v30; // [rsp+38h] [rbp-90h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v31; // [rsp+40h] [rbp-88h]
  hkpRigidBody *v32; // [rsp+48h] [rbp-80h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v33; // [rsp+50h] [rbp-78h]
  hkVector4f v34; // [rsp+58h] [rbp-70h]
  char collector[24]; // [rsp+68h] [rbp-60h]
  int v36; // [rsp+88h] [rbp-40h]
  int v37; // [rsp+8Ch] [rbp-3Ch]
  int v38; // [rsp+98h] [rbp-30h]
  int v39; // [rsp+B8h] [rbp-10h]
  hkpRigidBody *v40; // [rsp+C8h] [rbp+0h]
  hkpRigidBody *v41; // [rsp+158h] [rbp+90h]
  hkpWorld *v42; // [rsp+160h] [rbp+98h]

  v4 = this;
  v5 = viewTransform;
  v6 = 2i64;
  v33 = &world->m_inactiveSimulationIslands;
  v29 = 2i64;
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_34999999),
                                     (__m128)LODWORD(FLOAT_0_34999999),
                                     0);
  v32 = 0i64;
  v8 = &world->m_activeSimulationIslands;
  v31 = &world->m_activeSimulationIslands;
  do
  {
    v9 = 0;
    v28 = 0;
    if ( v8->m_size > 0 )
    {
      v10 = 0i64;
      v30 = 0i64;
      do
      {
        v11 = 0;
        v12 = *(__int64 *)((char *)v8->m_data + v10);
        if ( *(_DWORD *)(v12 + 104) > 0 )
        {
          v13 = 0i64;
          LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0);
          do
          {
            v15 = *(hkpRigidBody **)(v13 + *(_QWORD *)(v12 + 96));
            hkVector4f::setTransformedInversePos(
              &v34,
              v5,
              &v15->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1);
            v16 = 0;
            v17 = 0;
            v18 = _mm_shuffle_ps(v34.m_quad, v34.m_quad, 0);
            if ( v18.m128_f32[0] > COERCE_FLOAT(
                                     _mm_shuffle_ps(
                                       (__m128)LODWORD(v4->m_maxDistOfObjectPicked),
                                       (__m128)LODWORD(v4->m_maxDistOfObjectPicked),
                                       0)) )
              v16 = 1;
            if ( v18.m128_f32[0] < v14 )
              v17 = 1;
            if ( !(v17 | v16) && v15 != v41 )
            {
              v19 = _mm_add_ps(v18, query.m_quad);
              v20 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v34.m_quad, 1u), 1u);
              LODWORD(v21) = (unsigned __int128)_mm_rcp_ps(v19);
              v22 = (float)((float)(2.0 - (float)(v21 * v19.m128_f32[0])) * v21)
                  * (float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)));
              if ( hkpMotion::getMass((hkpMotion *)&v15->m_motion.vfptr) > v4->m_maxMassOfObjectPicked )
                v22 = v22 + COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0));
              if ( v22 <= v7 )
              {
                v23 = v4->m_grabbedBodies.m_size;
                v24 = 0i64;
                if ( v23 <= 0 )
                {
LABEL_19:
                  v26.m_quad = (__m128)v15->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
                  *(hkVector4f *)((char *)&v34 + 8) = v5->m_translation;
                  *(hkVector4f *)&collector[8] = (hkVector4f)v26.m_quad;
                  v40 = 0i64;
                  v36 = 1065353216;
                  v37 = -1;
                  *(_QWORD *)collector = &hkpClosestRayHitCollector::`vftable';
                  v39 = 0;
                  v38 = -1;
                  *(_DWORD *)&collector[8] = 1065353216;
                  LOBYTE(v32) = 0;
                  HIDWORD(v32) = 0;
                  v33 = 0i64;
                  hkpWorld::castRay(
                    v42,
                    (hkpWorldRayCastInput *)&v34.m_quad.m128_u16[4],
                    (hkpRayHitCollector *)collector);
                  if ( !v40 || v40 == (hkpRigidBody *)&v15->m_collidable )
                  {
                    v7 = v22;
                    v32 = v15;
                  }
                }
                else
                {
                  v25 = v4->m_grabbedBodies.m_data;
                  while ( *v25 != v15 )
                  {
                    ++v24;
                    ++v25;
                    if ( v24 >= v23 )
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
        v8 = v31;
        ++v9;
        v10 += 8i64;
        v28 = v9;
        v30 = v10;
      }
      while ( v9 < v31->m_size );
      v6 = v29;
    }
    v8 = v33;
    --v6;
    v31 = v33;
    v29 = v6;
  }
  while ( v6 );
  return v32;
}

// File Line: 123
// RVA: 0xE15C70
void __fastcall hkpGravityGun::takeObject(hkpGravityGun *this, hkpRigidBody *body)
{
  hkpGravityGun *v2; // rbx
  hkpRigidBody *v3; // rdi

  v2 = this;
  v3 = body;
  hkReferencedObject::addReference((hkReferencedObject *)&body->vfptr);
  if ( v2->m_grabbedBodies.m_size == (v2->m_grabbedBodies.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_grabbedBodies, 8);
  v2->m_grabbedBodies.m_data[v2->m_grabbedBodies.m_size++] = v3;
  hkpRigidBody::setMassInv(
    v3,
    COERCE_FLOAT(_mm_shuffle_ps(v3->m_motion.m_inertiaAndMassInv.m_quad, v3->m_motion.m_inertiaAndMassInv.m_quad, 255))
  * 100.0);
}

// File Line: 130
// RVA: 0xE15CF0
hkpRigidBody *__fastcall hkpGravityGun::dropObject(hkpGravityGun *this, int index)
{
  hkpRigidBody **v2; // rax
  hkpRigidBody *v3; // rbx
  int v4; // er9
  signed __int64 v5; // rcx
  int v6; // er9
  __int64 v7; // rdx
  __int64 v8; // rax

  v2 = this->m_grabbedBodies.m_data;
  v3 = v2[index];
  v4 = --this->m_grabbedBodies.m_size - index;
  v5 = (signed __int64)&v2[index];
  v6 = 8 * v4;
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
    do
    {
      v8 = *(_QWORD *)(v5 + 8);
      v5 += 8i64;
      *(_QWORD *)(v5 - 8) = v8;
      --v7;
    }
    while ( v7 );
  }
  hkpRigidBody::setMassInv(
    v3,
    COERCE_FLOAT(_mm_shuffle_ps(v3->m_motion.m_inertiaAndMassInv.m_quad, v3->m_motion.m_inertiaAndMassInv.m_quad, 255))
  * 0.0099999998);
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
  return v3;
}

// File Line: 139
// RVA: 0xE15D80
void __fastcall hkpGravityGun::gravityGunPull(hkpGravityGun *this, hkTransformf *viewTransform, hkpRigidBody *characterBody, hkpWorld *world)
{
  hkTransformf *v4; // rsi
  hkpGravityGun *v5; // rbx
  hkpRigidBody *v6; // rax
  hkpRigidBody *v7; // rdi
  __m128 v8; // [rsp+20h] [rbp-18h]

  v4 = viewTransform;
  v5 = this;
  v6 = hkpGravityGun::pickBody(this, viewTransform, characterBody, world);
  v7 = v6;
  if ( v6 )
  {
    if ( (float)(v6->m_motion.m_inertiaAndMassInv.m_quad.m128_f32[3] * v5->m_maxMassOfObjectPicked) < 1.0
      || v5->m_grabbedBodies.m_size >= v5->m_maxNumObjectsPicked )
    {
      v8 = _mm_mul_ps(
             v4->m_rotation.m_col0.m_quad,
             _mm_sub_ps(
               (__m128)0i64,
               _mm_shuffle_ps(
                 (__m128)LODWORD(v5->m_impulseAppliedWhenObjectNotPicked),
                 (__m128)LODWORD(v5->m_impulseAppliedWhenObjectNotPicked),
                 0)));
      hkpEntity::activate((hkpEntity *)&v6->vfptr);
      v7->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v8);
    }
    else
    {
      hkpGravityGun::takeObject(v5, v6);
    }
  }
}

// File Line: 158
// RVA: 0xE15E30
void __fastcall hkpGravityGun::gravityGunPush(hkpGravityGun *this, hkTransformf *viewTransform, hkpRigidBody *characterBody, hkpWorld *world)
{
  hkpRigidBody *v4; // rbp
  hkTransformf *v5; // rsi
  hkpGravityGun *v6; // rdi
  hkpRigidBody *v7; // rbx
  hkpRigidBody *v8; // rax
  hkpRigidBody *v9; // rbx
  __m128 v10; // [rsp+20h] [rbp-18h]

  v4 = characterBody;
  v5 = viewTransform;
  v6 = this;
  if ( this->m_grabbedBodies.m_size )
  {
    v7 = hkpGravityGun::dropObject(this, 0);
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(v6->m_throwVelocity), (__m128)LODWORD(v6->m_throwVelocity), 0),
                v5->m_rotation.m_col0.m_quad),
              _mm_mul_ps(direction.m_quad, (__m128)xmmword_141A711B0)),
            v4->m_motion.m_linearVelocity.m_quad);
    hkpEntity::activate((hkpEntity *)&v7->vfptr);
    v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v10);
    v7->m_collidable.m_broadPhaseHandle.m_objectQualityType = 6;
  }
  else
  {
    v8 = hkpGravityGun::pickBody(this, viewTransform, characterBody, world);
    v9 = v8;
    if ( v8 )
    {
      v10 = _mm_mul_ps(
              v5->m_rotation.m_col0.m_quad,
              _mm_shuffle_ps(
                (__m128)LODWORD(v6->m_impulseAppliedWhenObjectNotPicked),
                (__m128)LODWORD(v6->m_impulseAppliedWhenObjectNotPicked),
                0));
      hkpEntity::activate((hkpEntity *)&v8->vfptr);
      v9->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v9->m_motion.vfptr, (unsigned int)&v10);
    }
  }
}

// File Line: 182
// RVA: 0xE161F0
void __fastcall hkpGravityGun::gravityGunPutDown(hkpGravityGun *this, hkTransformf *viewTransform, hkpRigidBody *characterBody, hkpWorld *world)
{
  if ( this->m_grabbedBodies.m_size )
    hkpGravityGun::dropObject(this, 0);
}

// File Line: 190
// RVA: 0xE15F10
void __fastcall hkpGravityGun::gravityGunStep(hkpGravityGun *this, float timeStep, hkTransformf *viewTransform, hkpRigidBody *characterBody)
{
  signed int v4; // esi
  hkpRigidBody *v5; // r12
  hkTransformf *v6; // r13
  hkpGravityGun *v7; // r15
  __int64 v8; // r14
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  __m128 v11; // xmm0
  hkpRigidBody *v12; // rdi
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm6
  hkVector4f v18; // xmm4
  float v19; // xmm6_4
  unsigned __int16 v20; // ax
  __m128 v21; // xmm1
  __m128 *v22; // rdx
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // [rsp+18h] [rbp-79h]
  hkVector4f b; // [rsp+28h] [rbp-69h]
  hkVector4f v27; // [rsp+38h] [rbp-59h]
  __m128 v28; // [rsp+48h] [rbp-49h]
  unsigned int v29; // [rsp+F8h] [rbp+67h]

  v4 = 0;
  v5 = characterBody;
  v6 = viewTransform;
  v7 = this;
  if ( this->m_grabbedBodies.m_size > 0 )
  {
    v8 = 0i64;
    v9 = _mm_shuffle_ps((__m128)0x3F4CCCCDu, (__m128)0x3F4CCCCDu, 0);
    v29 = 1061997773;
    v10 = _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(0.40000001 / timeStep),
            (__m128)COERCE_UNSIGNED_INT(0.40000001 / timeStep),
            0);
    do
    {
      v11 = 0i64;
      v11.m128_f32[0] = (float)v4;
      b.m_quad = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v7->m_capturedObjectsOffset.m_quad),
                   v7->m_capturedObjectPosition.m_quad);
      hkVector4f::setTransformedPos(&v27, v6, &b);
      v12 = v7->m_grabbedBodies.m_data[v8];
      v13 = v5->m_motion.m_linearVelocity.m_quad;
      _mm_store_si128((__m128i *)&v25, (__m128i)v12->m_motion.m_linearVelocity.m_quad);
      v25 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v13, v12->m_motion.m_linearVelocity.m_quad), v9),
              v12->m_motion.m_linearVelocity.m_quad);
      v25 = _mm_add_ps(
              v25,
              _mm_mul_ps(
                _mm_sub_ps(v27.m_quad, v12->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad),
                v10));
      v14 = _mm_mul_ps(v25, v25);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_andnot_ps(
              _mm_cmpleps(v15, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                _mm_mul_ps(*(__m128 *)_xmm, v16)));
      v18.m_quad = _mm_mul_ps(v25, v17);
      v19 = v17.m128_f32[0] * v15.m128_f32[0];
      *(hkVector4f *)((char *)&b + 8) = (hkVector4f)v18.m_quad;
      v20 = hkUFloat8::getEncodedFloat(v12->m_motion.m_motionState.m_maxLinearVelocity.m_value);
      v25.m128_i32[2] = (v20 + 243712) << 12;
      if ( v20 )
        v29 = v25.m128_u32[2];
      else
        v29 = 0;
      v21 = _mm_shuffle_ps((__m128)v29, (__m128)v29, 0);
      if ( v19 < v21.m128_f32[0] )
      {
        hkpEntity::activate((hkpEntity *)&v12->vfptr);
        v22 = &v25;
      }
      else
      {
        v25.m128_i32[3] = 1008981770;
        *(hkVector4f *)((char *)&b + 8) = (hkVector4f)_mm_mul_ps(
                                                        *(__m128 *)((char *)&b.m_quad + 8),
                                                        _mm_sub_ps(
                                                          v21,
                                                          _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0)));
        hkpEntity::activate((hkpEntity *)&v12->vfptr);
        v22 = (__m128 *)((char *)&b.m_quad + 8);
      }
      v12->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v12->m_motion.vfptr, (unsigned int)v22);
      v23 = _mm_mul_ps(v12->m_motion.m_angularVelocity.m_quad, v9);
      v28 = v23;
      v24 = _mm_mul_ps(v23, v23);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) > 1.0 )
      {
        hkpEntity::activate((hkpEntity *)&v12->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v12->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v12->m_motion,
          &v28);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < v7->m_grabbedBodies.m_size );
  }
}

// File Line: 232
// RVA: 0xE157E0
void __fastcall hkpGravityGun::stepGun(hkpGravityGun *this, float timeStep, hkpWorld *world, hkpRigidBody *body, hkTransformf *viewTransform, bool fire, bool fireRmb)
{
  float v7; // xmm6_4
  hkpRigidBody *v8; // rbp
  hkpGravityGun *v9; // rdi
  int v10; // ebx
  __int64 v11; // rsi
  __m128i v12; // xmm1
  int v13; // ebx
  __int64 v14; // rsi
  int v15; // ebx
  __int64 v16; // rsi
  __int128 v17; // [rsp+20h] [rbp-38h]
  __int128 v18; // [rsp+30h] [rbp-28h]

  v7 = timeStep;
  v8 = body;
  v9 = this;
  if ( fire )
  {
    hkpGravityGun::gravityGunPush(this, viewTransform, body, world);
    v10 = 0;
    _mm_store_si128((__m128i *)&v17, (__m128i)v8->m_motion.m_motionState.m_transform.m_translation.m_quad);
    if ( v9->m_listeners.m_size > 0 )
    {
      v11 = 0i64;
      do
      {
        ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, __int128 *, _QWORD))v9->m_listeners.m_data[v11]->vfptr[2].__first_virtual_table_function__)(
          v9->m_listeners.m_data[v11],
          &v17,
          0i64);
        ++v10;
        ++v11;
      }
      while ( v10 < v9->m_listeners.m_size );
    }
  }
  else if ( fireRmb )
  {
    if ( this->m_grabbedBodies.m_size == this->m_maxNumObjectsPicked )
    {
      hkpGravityGun::gravityGunPutDown(this, viewTransform, body, world);
      v15 = 0;
      _mm_store_si128((__m128i *)&v18, (__m128i)v8->m_motion.m_motionState.m_transform.m_translation.m_quad);
      if ( v9->m_listeners.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, __int128 *, _QWORD))v9->m_listeners.m_data[v16]->vfptr[2].__first_virtual_table_function__)(
            v9->m_listeners.m_data[v16],
            &v18,
            0i64);
          ++v15;
          ++v16;
        }
        while ( v15 < v9->m_listeners.m_size );
      }
    }
    else
    {
      hkpGravityGun::gravityGunPull(this, viewTransform, body, world);
      v12 = (__m128i)v8->m_motion.m_motionState.m_transform.m_translation;
      v13 = 0;
      _mm_store_si128((__m128i *)&v18, (__m128i)viewTransform->m_translation.m_quad);
      _mm_store_si128((__m128i *)&v17, v12);
      if ( v9->m_listeners.m_size > 0 )
      {
        v14 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpFirstPersonGunBulletListener *, __int128 *, __int128 *))v9->m_listeners.m_data[v14]->vfptr[2].__first_virtual_table_function__)(
            v9->m_listeners.m_data[v14],
            &v18,
            &v17);
          ++v13;
          ++v14;
        }
        while ( v13 < v9->m_listeners.m_size );
      }
    }
  }
  hkpGravityGun::gravityGunStep(v9, v7, viewTransform, v8);
}

// File Line: 276
// RVA: 0xE15960
void __fastcall hkpGravityGun::reset(hkpGravityGun *this, hkpWorld *world)
{
  hkpGravityGun *i; // rbx

  for ( i = this; i->m_grabbedBodies.m_size; hkpGravityGun::dropObject(i, 0) )
    ;
}

