// File Line: 29
// RVA: 0xE16F40
void __fastcall hkpMouseSpringAction::hkpMouseSpringAction(hkpMouseSpringAction *this, hkpRigidBody *rb)
{
  hkpUnaryAction::hkpUnaryAction(this, rb, 0i64);
  this->m_springDamping = 0.5;
  this->m_springElasticity = 0.30000001;
  this->m_maxRelativeForce = 250.0;
  this->m_objectDamping = 0.94999999;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMouseSpringAction::`vftable;
  this->m_applyCallbacks.m_capacityAndFlags = 0x80000000;
  this->m_applyCallbacks.m_data = 0i64;
  this->m_applyCallbacks.m_size = 0;
  this->m_positionInRbLocal = 0i64;
  this->m_mousePositionInWorld = 0i64;
  this->m_shapeKey = -1;
  hkStringPtr::operator=(&this->m_name, hkpMouseSpringAction::s_name);
}

// File Line: 47
// RVA: 0xE16FC0
void __fastcall hkpMouseSpringAction::hkpMouseSpringAction(
        hkpMouseSpringAction *this,
        hkVector4f *positionInRbLocal,
        hkVector4f *mousePositionInWorld,
        float springDamping,
        __int64 springElasticity)
{
  hkpEntity *v5; // rsi
  float v9; // xmm1_4
  __m128 m_quad; // xmm0
  __int64 v11; // rbx
  __m128 v12; // xmm0
  __int64 v13; // rax
  void (__fastcall **m_data)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *); // rcx
  __int64 v15; // rdx
  __int64 v16; // r8
  void (__fastcall *v17)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *); // rax
  hkpWorld *m_world; // rbx
  __m128 v19; // xmm1
  hkpCollisionDispatcher *m_collisionDispatcher; // r8
  char v21; // sp
  char v22; // cl
  void (__fastcall *m_getClosestPointFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *); // r10
  __int128 *m_collisionInput; // rax
  __int128 v25; // xmm1
  hkpSphereShape *v26; // [rsp+20h] [rbp-C8h] BYREF
  int v27; // [rsp+28h] [rbp-C0h]
  __int128 *v28; // [rsp+30h] [rbp-B8h]
  __int64 v29; // [rsp+38h] [rbp-B0h]
  char v30; // [rsp+40h] [rbp-A8h]
  char v31; // [rsp+41h] [rbp-A7h]
  __int16 v32; // [rsp+42h] [rbp-A6h]
  int v33; // [rsp+44h] [rbp-A4h]
  __int16 v34; // [rsp+48h] [rbp-A0h]
  char v35; // [rsp+4Ah] [rbp-9Eh]
  int v36; // [rsp+4Ch] [rbp-9Ch]
  hkpCollidable::BoundingVolumeData v37; // [rsp+50h] [rbp-98h] BYREF
  __m128 v38; // [rsp+98h] [rbp-50h]
  __int64 v39; // [rsp+A8h] [rbp-40h]
  unsigned int v40; // [rsp+C0h] [rbp-28h]
  __int128 v41[4]; // [rsp+D8h] [rbp-10h] BYREF
  __int128 v42[6]; // [rsp+118h] [rbp+30h] BYREF
  hkpSphereShape v43; // [rsp+178h] [rbp+90h] BYREF
  float v44; // [rsp+208h] [rbp+120h] BYREF
  int v45; // [rsp+210h] [rbp+128h]
  hkpEntity *entity; // [rsp+218h] [rbp+130h]

  v5 = entity;
  hkpUnaryAction::hkpUnaryAction(this, entity, 0i64);
  v9 = v44;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMouseSpringAction::`vftable;
  m_quad = positionInRbLocal->m_quad;
  v11 = springElasticity;
  this->m_positionInRbLocal.m_quad = m_quad;
  v12 = mousePositionInWorld->m_quad;
  this->m_springDamping = springDamping;
  this->m_mousePositionInWorld.m_quad = v12;
  v12.m128_i32[0] = v45;
  this->m_springElasticity = v9;
  LODWORD(this->m_objectDamping) = v12.m128_i32[0];
  this->m_applyCallbacks.m_data = 0i64;
  this->m_applyCallbacks.m_size = 0;
  this->m_applyCallbacks.m_capacityAndFlags = 0x80000000;
  this->m_maxRelativeForce = 250.0;
  if ( v11 )
  {
    if ( (this->m_applyCallbacks.m_capacityAndFlags & 0x3FFFFFFF) < *(_DWORD *)(v11 + 8) )
    {
      if ( this->m_applyCallbacks.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          0i64,
          8 * this->m_applyCallbacks.m_capacityAndFlags);
      LODWORD(v44) = 8 * *(_DWORD *)(v11 + 8);
      this->m_applyCallbacks.m_data = (void (__fastcall **)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v44);
      this->m_applyCallbacks.m_capacityAndFlags = SLODWORD(v44) / 8;
    }
    v13 = *(int *)(v11 + 8);
    m_data = this->m_applyCallbacks.m_data;
    this->m_applyCallbacks.m_size = v13;
    v15 = v13;
    if ( (int)v13 > 0 )
    {
      v16 = *(_QWORD *)v11 - (_QWORD)m_data;
      do
      {
        v17 = *(void (__fastcall **)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *))((char *)m_data++ + v16);
        *(m_data - 1) = v17;
        --v15;
      }
      while ( v15 );
    }
  }
  m_world = v5->m_world;
  this->m_shapeKey = -1;
  if ( m_world )
  {
    hkpSphereShape::hkpSphereShape(&v43, 1.0);
    v26 = &v43;
    v29 = 0i64;
    v41[0] = (__int128)transform.m_quad;
    v41[1] = (__int128)direction.m_quad;
    v27 = -1;
    v30 = 0;
    v33 = 0;
    v19 = mousePositionInWorld->m_quad;
    v41[2] = (__int128)stru_141A71280.m_quad;
    v41[3] = (__int128)v19;
    v28 = v41;
    v34 = 32512;
    v36 = 0;
    v35 = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v37);
    *(float *)&v37.m_numChildShapeAabbs = FLOAT_N1_0;
    m_collisionDispatcher = m_world->m_collisionDispatcher;
    v31 = 8;
    v32 = 0;
    v22 = v21 + 68;
    HIBYTE(v34) = v21 + 32 - v22;
    m_getClosestPointFunc = m_collisionDispatcher->m_agent2Func[(unsigned __int8)m_collisionDispatcher->m_agent2Types[(unsigned __int8)v43.m_type.m_storage][(unsigned __int8)v5->m_collidable.m_shape->m_type.m_storage]].m_getClosestPointFunc;
    m_collisionInput = (__int128 *)m_world->m_collisionInput;
    v42[0] = *m_collisionInput;
    v42[1] = m_collisionInput[1];
    v42[2] = m_collisionInput[2];
    v42[3] = m_collisionInput[3];
    v42[4] = m_collisionInput[4];
    v25 = m_collisionInput[5];
    v39 = 0i64;
    v37.m_childShapeAabbs = (hkAabbUint32 *)&hkpClosestCdPointCollector::`vftable;
    v42[5] = v25;
    *(float *)&v37.m_childShapeKeys = FLOAT_3_40282e38;
    v38 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, (__m128)xmmword_141A712A0), 196);
    m_getClosestPointFunc(
      (hkpCdBody *)&v26,
      &v5->m_collidable,
      (hkpCollisionInput *)v42,
      (hkpCdPointCollector *)&v37.m_childShapeAabbs);
    if ( v39 )
      this->m_shapeKey = v40;
  }
  hkStringPtr::operator=(&this->m_name, hkpMouseSpringAction::s_name);
}

// File Line: 84
// RVA: 0xE17300
void __fastcall hkpMouseSpringAction::setMousePosition(hkpMouseSpringAction *this, hkVector4f *mousePositionInWorld)
{
  hkpEntity *m_entity; // rcx

  if ( (_mm_movemask_ps(
          _mm_cmplt_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_sub_ps(mousePositionInWorld->m_quad, this->m_mousePositionInWorld.m_quad),
                        1u),
                      1u),
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) & 7) == 7 )
  {
    this->m_mousePositionInWorld = (hkVector4f)mousePositionInWorld->m_quad;
  }
  else
  {
    m_entity = this->m_entity;
    if ( m_entity && m_entity->m_world )
    {
      hkpEntity::activate(m_entity);
      this->m_mousePositionInWorld = (hkVector4f)mousePositionInWorld->m_quad;
    }
    else
    {
      this->m_mousePositionInWorld = (hkVector4f)mousePositionInWorld->m_quad;
    }
  }
}

// File Line: 97
// RVA: 0xE173A0
void __fastcall hkpMouseSpringAction::setMaxRelativeForce(hkpMouseSpringAction *this, float newMax)
{
  this->m_maxRelativeForce = newMax;
}

// File Line: 104
// RVA: 0xE173B0
void __fastcall hkpMouseSpringAction::applyAction(hkpMouseSpringAction *this, hkStepInfo *stepInfo)
{
  hkpRigidBody *m_entity; // rdi
  __m128 v5; // xmm7
  hkpMaxSizeMotion *StoredDynamicMotion; // rsi
  __m128 v7; // xmm6
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  int v20; // edi
  __int64 v21; // rsi
  hkVector4f v22; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v23; // [rsp+30h] [rbp-D0h] BYREF
  hkMatrix3f v24; // [rsp+40h] [rbp-C0h] BYREF
  __m128 v25; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f r; // [rsp+80h] [rbp-80h] BYREF
  __m128 v27; // [rsp+90h] [rbp-70h] BYREF
  hkMatrix3f aTb; // [rsp+A0h] [rbp-60h] BYREF
  hkMatrix3f v29; // [rsp+D0h] [rbp-30h] BYREF
  hkMatrix3f bTc; // [rsp+100h] [rbp+0h] BYREF
  hkMatrix3f a; // [rsp+130h] [rbp+30h] BYREF
  hkResult result; // [rsp+1B0h] [rbp+B0h] BYREF
  float v33; // [rsp+1C0h] [rbp+C0h]

  m_entity = (hkpRigidBody *)this->m_entity;
  hkVector4f::setTransformedPos(&v22, &m_entity->m_motion.m_motionState.m_transform, &this->m_positionInRbLocal);
  v5 = _mm_sub_ps(v22.m_quad, this->m_mousePositionInWorld.m_quad);
  if ( hkpRigidBody::getStoredDynamicMotion(m_entity) )
    StoredDynamicMotion = hkpRigidBody::getStoredDynamicMotion(m_entity);
  else
    StoredDynamicMotion = &m_entity->m_motion;
  v7 = _mm_shuffle_ps(
         StoredDynamicMotion->m_inertiaAndMassInv.m_quad,
         StoredDynamicMotion->m_inertiaAndMassInv.m_quad,
         255);
  r.m_quad = _mm_sub_ps(v22.m_quad, m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  hkMatrix3f::setCrossSkewSymmetric(&aTb, &r);
  StoredDynamicMotion->vfptr[6].__vecDelDtor(StoredDynamicMotion, (unsigned int)&bTc);
  v24.m_col2.m_quad = _mm_mul_ps(v7, stru_141A71280.m_quad);
  v24.m_col0.m_quad = _mm_mul_ps(v7, transform.m_quad);
  v24.m_col1.m_quad = _mm_mul_ps(v7, direction.m_quad);
  hkMatrix3f::setMul(&v29, &aTb, &bTc);
  hkMatrix3f::setMul(&a, &v29, &aTb);
  hkMatrix3f::sub(&v24, &a);
  hkMatrix3f::invert(&v24, &result, 0.0000001);
  if ( result.m_enum == HK_SUCCESS )
  {
    v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_objectDamping), (__m128)LODWORD(this->m_objectDamping), 0);
    v27 = _mm_mul_ps(m_entity->m_motion.m_linearVelocity.m_quad, v8);
    hkpEntity::activate(m_entity);
    m_entity->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&m_entity->m_motion, (unsigned int)&v27);
    v25 = _mm_mul_ps(m_entity->m_motion.m_angularVelocity.m_quad, v8);
    hkpEntity::activate(m_entity);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))m_entity->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
      &m_entity->m_motion,
      &v25);
    v9 = _mm_sub_ps(v22.m_quad, m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v10 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), m_entity->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(
                m_entity->m_motion.m_angularVelocity.m_quad,
                m_entity->m_motion.m_angularVelocity.m_quad,
                201),
              v9));
    v33 = this->m_springElasticity * stepInfo->m_invDeltaTime.m_storage;
    v11 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 201), m_entity->m_motion.m_linearVelocity.m_quad),
              _mm_shuffle_ps((__m128)LODWORD(this->m_springDamping), (__m128)LODWORD(this->m_springDamping), 0)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v33), (__m128)LODWORD(v33), 0), v5));
    v12 = _mm_xor_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v24.m_col1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v24.m_col0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v24.m_col2.m_quad)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v23 = v12;
    v13 = _mm_mul_ps(v12, v12);
    v14 = _mm_shuffle_ps(
            StoredDynamicMotion->m_inertiaAndMassInv.m_quad,
            StoredDynamicMotion->m_inertiaAndMassInv.m_quad,
            255);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    if ( v14.m128_f32[0] == 0.0 )
    {
      v16 = 0i64;
    }
    else
    {
      v17 = _mm_rcp_ps(v14);
      v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v14)), v17);
    }
    v33 = this->m_maxRelativeForce * stepInfo->m_deltaTime.m_storage;
    v18 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v33), (__m128)LODWORD(v33), 0), v16);
    if ( v15.m128_f32[0] > (float)(v18.m128_f32[0] * v18.m128_f32[0]) )
    {
      v19 = _mm_rsqrt_ps(v15);
      v23 = _mm_mul_ps(
              v12,
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v15, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v15), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))),
                v18));
    }
    hkpEntity::activate(m_entity);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))m_entity->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
      &m_entity->m_motion,
      &v23,
      &v22);
    v20 = 0;
    if ( this->m_applyCallbacks.m_size > 0 )
    {
      v21 = 0i64;
      do
      {
        this->m_applyCallbacks.m_data[v21](this, stepInfo, (hkVector4f *)&v23);
        ++v20;
        ++v21;
      }
      while ( v20 < this->m_applyCallbacks.m_size );
    }
  }
}

// File Line: 218
// RVA: 0xE172D0
void __fastcall hkpMouseSpringAction::entityRemovedCallback(hkpMouseSpringAction *this, hkpEntity *entity)
{
  hkpUnaryAction::entityRemovedCallback(this, entity);
  this->m_entity = 0i64;
}

// File Line: 226
// RVA: 0xE17710
hkpAction *__fastcall hkpMouseSpringAction::clone(
        hkpMouseSpringAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpMouseSpringAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  __int64 m_size; // rax
  __int64 v11; // rcx
  __int64 v12; // rdx
  char *v13; // r8
  __int64 v14; // rax
  int v15; // [rsp+38h] [rbp+10h] BYREF

  if ( newEntities->m_size != 1 || newPhantoms->m_size )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMouseSpringAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
  if ( v7 )
  {
    hkpMouseSpringAction::hkpMouseSpringAction(v7, (hkpRigidBody *)*newEntities->m_data);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(hkVector4f *)(v9 + 64) = this->m_positionInRbLocal;
  *(hkVector4f *)(v9 + 80) = this->m_mousePositionInWorld;
  *(float *)(v9 + 96) = this->m_springDamping;
  *(float *)(v9 + 100) = this->m_springElasticity;
  *(float *)(v9 + 104) = this->m_maxRelativeForce;
  *(float *)(v9 + 108) = this->m_objectDamping;
  *(_QWORD *)(v9 + 32) = this->m_userData;
  *(_DWORD *)(v9 + 112) = this->m_shapeKey;
  if ( (*(_DWORD *)(v9 + 132) & 0x3FFFFFFF) < this->m_applyCallbacks.m_size )
  {
    if ( *(int *)(v9 + 132) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v9 + 120),
        8 * *(_DWORD *)(v9 + 132));
    v15 = 8 * this->m_applyCallbacks.m_size;
    *(_QWORD *)(v9 + 120) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v15);
    *(_DWORD *)(v9 + 132) = v15 / 8;
  }
  m_size = this->m_applyCallbacks.m_size;
  v11 = *(_QWORD *)(v9 + 120);
  *(_DWORD *)(v9 + 128) = m_size;
  v12 = m_size;
  if ( (int)m_size > 0 )
  {
    v13 = (char *)this->m_applyCallbacks.m_data - v11;
    do
    {
      v14 = *(_QWORD *)&v13[v11];
      v11 += 8i64;
      *(_QWORD *)(v11 - 8) = v14;
      --v12;
    }
    while ( v12 );
  }
  return (hkpAction *)v9;
}

