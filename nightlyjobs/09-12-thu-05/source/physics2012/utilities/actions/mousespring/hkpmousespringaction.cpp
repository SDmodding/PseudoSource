// File Line: 29
// RVA: 0xE16F40
void __fastcall hkpMouseSpringAction::hkpMouseSpringAction(hkpMouseSpringAction *this, hkpRigidBody *rb)
{
  hkpMouseSpringAction *v2; // rbx

  v2 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&rb->vfptr, 0i64);
  v2->m_springDamping = 0.5;
  v2->m_springElasticity = 0.30000001;
  v2->m_maxRelativeForce = 250.0;
  v2->m_objectDamping = 0.94999999;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMouseSpringAction::`vftable;
  v2->m_applyCallbacks.m_capacityAndFlags = 2147483648;
  v2->m_applyCallbacks.m_data = 0i64;
  v2->m_applyCallbacks.m_size = 0;
  v2->m_positionInRbLocal = 0i64;
  v2->m_mousePositionInWorld = 0i64;
  v2->m_shapeKey = -1;
  hkStringPtr::operator=(&v2->m_name, hkpMouseSpringAction::s_name);
}

// File Line: 47
// RVA: 0xE16FC0
void __fastcall hkpMouseSpringAction::hkpMouseSpringAction(hkpMouseSpringAction *this, hkVector4f *positionInRbLocal, hkVector4f *mousePositionInWorld, const float springDamping, const float springElasticity)
{
  hkpEntity *v5; // rsi
  hkVector4f *v6; // r14
  hkVector4f *v7; // rbx
  hkpMouseSpringAction *v8; // rdi
  int v9; // xmm1_4
  __m128 v10; // xmm0
  __int64 v11; // rbx
  __m128 v12; // xmm0
  __int64 v13; // rax
  void (__fastcall **v14)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *); // rcx
  __int64 v15; // rdx
  __int64 v16; // r8
  void (__fastcall *v17)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *); // rax
  hkpWorld *v18; // rbx
  __int128 v19; // xmm1
  hkpCollisionDispatcher *v20; // r8
  char v21; // sp
  char v22; // cl
  void (__fastcall *v23)(hkpSphereShape **, hkpLinkedCollidable *, __int128 *, hkAabbUint32 **, hkpSphereShape *, _QWORD, __m128 *, _QWORD, _QWORD); // r10
  __int128 *v24; // rax
  __int128 v25; // xmm1
  hkpSphereShape *v26; // [rsp+20h] [rbp-C8h]
  int v27; // [rsp+28h] [rbp-C0h]
  __m128 *v28; // [rsp+30h] [rbp-B8h]
  __int64 v29; // [rsp+38h] [rbp-B0h]
  char v30; // [rsp+40h] [rbp-A8h]
  char v31; // [rsp+41h] [rbp-A7h]
  __int16 v32; // [rsp+42h] [rbp-A6h]
  int v33; // [rsp+44h] [rbp-A4h]
  __int16 v34; // [rsp+48h] [rbp-A0h]
  char v35; // [rsp+4Ah] [rbp-9Eh]
  int v36; // [rsp+4Ch] [rbp-9Ch]
  hkpCollidable::BoundingVolumeData v37; // [rsp+50h] [rbp-98h]
  __m128 v38; // [rsp+98h] [rbp-50h]
  __int64 v39; // [rsp+A8h] [rbp-40h]
  unsigned int v40; // [rsp+C0h] [rbp-28h]
  __m128 v41; // [rsp+D8h] [rbp-10h]
  __m128 v42; // [rsp+E8h] [rbp+0h]
  __m128 v43; // [rsp+F8h] [rbp+10h]
  __int128 v44; // [rsp+108h] [rbp+20h]
  __int128 v45; // [rsp+118h] [rbp+30h]
  __int128 v46; // [rsp+128h] [rbp+40h]
  __int128 v47; // [rsp+138h] [rbp+50h]
  __int128 v48; // [rsp+148h] [rbp+60h]
  __int128 v49; // [rsp+158h] [rbp+70h]
  __int128 v50; // [rsp+168h] [rbp+80h]
  hkpSphereShape v51; // [rsp+178h] [rbp+90h]
  int v52; // [rsp+208h] [rbp+120h]
  int v53; // [rsp+210h] [rbp+128h]
  hkpEntity *entity; // [rsp+218h] [rbp+130h]

  v5 = entity;
  v6 = mousePositionInWorld;
  v7 = positionInRbLocal;
  v8 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, entity, 0i64);
  v9 = v52;
  v8->vfptr = (hkBaseObjectVtbl *)&hkpMouseSpringAction::`vftable;
  v10 = v7->m_quad;
  v11 = *(_QWORD *)&springElasticity;
  v8->m_positionInRbLocal.m_quad = v10;
  v12 = v6->m_quad;
  v8->m_springDamping = springDamping;
  v8->m_mousePositionInWorld.m_quad = v12;
  v12.m128_i32[0] = v53;
  LODWORD(v8->m_springElasticity) = v9;
  LODWORD(v8->m_objectDamping) = v12.m128_i32[0];
  v8->m_applyCallbacks.m_data = 0i64;
  v8->m_applyCallbacks.m_size = 0;
  v8->m_applyCallbacks.m_capacityAndFlags = 2147483648;
  v8->m_maxRelativeForce = 250.0;
  if ( v11 )
  {
    if ( (v8->m_applyCallbacks.m_capacityAndFlags & 0x3FFFFFFF) < *(_DWORD *)(v11 + 8) )
    {
      if ( v8->m_applyCallbacks.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          0i64,
          8 * v8->m_applyCallbacks.m_capacityAndFlags);
      v52 = 8 * *(_DWORD *)(v11 + 8);
      v8->m_applyCallbacks.m_data = (void (__fastcall **)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, &v52);
      v8->m_applyCallbacks.m_capacityAndFlags = v52 / 8;
    }
    v13 = *(signed int *)(v11 + 8);
    v14 = v8->m_applyCallbacks.m_data;
    v8->m_applyCallbacks.m_size = v13;
    v15 = v13;
    if ( (signed int)v13 > 0 )
    {
      v16 = *(_QWORD *)v11 - (_QWORD)v14;
      do
      {
        v17 = *(void (__fastcall **)(hkpMouseSpringAction *, hkStepInfo *, hkVector4f *))((char *)v14 + v16);
        ++v14;
        *(v14 - 1) = v17;
        --v15;
      }
      while ( v15 );
    }
  }
  v18 = v5->m_world;
  v8->m_shapeKey = -1;
  if ( v18 )
  {
    hkpSphereShape::hkpSphereShape(&v51, 1.0);
    v26 = &v51;
    v29 = 0i64;
    v41 = transform.m_quad;
    v42 = direction.m_quad;
    v27 = -1;
    v30 = 0;
    v33 = 0;
    v19 = (__int128)v6->m_quad;
    v43 = stru_141A71280.m_quad;
    v44 = v19;
    v28 = &v41;
    v34 = 32512;
    v36 = 0;
    v35 = -1;
    hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v37);
    *(float *)&v37.m_numChildShapeAabbs = FLOAT_N1_0;
    v20 = v18->m_collisionDispatcher;
    v31 = 8;
    v32 = 0;
    v22 = v21 + 68;
    HIBYTE(v34) = v21 + 32 - v22;
    v23 = (void (__fastcall *)(hkpSphereShape **, hkpLinkedCollidable *, __int128 *, hkAabbUint32 **, hkpSphereShape *, _QWORD, __m128 *, _QWORD, _QWORD))*((_QWORD *)&v20->vfptr + 5 * ((unsigned __int8)v20->m_agent2Types[(unsigned __int8)v51.m_type.m_storage][(unsigned __int8)v5->m_collidable.m_shape->m_type.m_storage] + 79i64));
    v24 = (__int128 *)v18->m_collisionInput;
    v45 = *v24;
    v46 = v24[1];
    v47 = v24[2];
    v48 = v24[3];
    v49 = v24[4];
    v25 = v24[5];
    v39 = 0i64;
    v37.m_childShapeAabbs = (hkAabbUint32 *)&hkpClosestCdPointCollector::`vftable;
    v50 = v25;
    *(float *)&v37.m_childShapeKeys = FLOAT_3_40282e38;
    v38 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, (__m128)xmmword_141A712A0), 196);
    v23(
      &v26,
      &v5->m_collidable,
      &v45,
      &v37.m_childShapeAabbs,
      &v51,
      *(_QWORD *)&v27,
      &v41,
      0i64,
      *(unsigned __int16 *)&v30);
    if ( v39 )
      v8->m_shapeKey = v40;
  }
  hkStringPtr::operator=(&v8->m_name, hkpMouseSpringAction::s_name);
}

// File Line: 84
// RVA: 0xE17300
void __fastcall hkpMouseSpringAction::setMousePosition(hkpMouseSpringAction *this, hkVector4f *mousePositionInWorld)
{
  hkVector4f *v2; // rdi
  hkpMouseSpringAction *v3; // rbx
  hkpEntity *v4; // rcx

  v2 = mousePositionInWorld;
  v3 = this;
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
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
    v4 = this->m_entity;
    if ( v4 && v4->m_world )
    {
      hkpEntity::activate(v4);
      v3->m_mousePositionInWorld = (hkVector4f)v2->m_quad;
    }
    else
    {
      v3->m_mousePositionInWorld = (hkVector4f)mousePositionInWorld->m_quad;
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
  hkpRigidBody *v2; // rdi
  hkStepInfo *v3; // r14
  __m128 *v4; // rbx
  __m128 v5; // xmm7
  hkpMaxSizeMotion *v6; // rsi
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
  hkVector4f v22; // [rsp+20h] [rbp-E0h]
  __m128 v23; // [rsp+30h] [rbp-D0h]
  hkMatrix3f v24; // [rsp+40h] [rbp-C0h]
  __m128 v25; // [rsp+70h] [rbp-90h]
  hkVector4f r; // [rsp+80h] [rbp-80h]
  __m128 v27; // [rsp+90h] [rbp-70h]
  hkMatrix3f aTb; // [rsp+A0h] [rbp-60h]
  hkMatrix3f v29; // [rsp+D0h] [rbp-30h]
  hkMatrix3f bTc; // [rsp+100h] [rbp+0h]
  hkMatrix3f a; // [rsp+130h] [rbp+30h]
  hkResult result; // [rsp+1B0h] [rbp+B0h]
  float v33; // [rsp+1C0h] [rbp+C0h]

  v2 = (hkpRigidBody *)this->m_entity;
  v3 = stepInfo;
  v4 = (__m128 *)this;
  hkVector4f::setTransformedPos(&v22, &v2->m_motion.m_motionState.m_transform, &this->m_positionInRbLocal);
  v5 = _mm_sub_ps(v22.m_quad, v4[5]);
  if ( hkpRigidBody::getStoredDynamicMotion(v2) )
    v6 = hkpRigidBody::getStoredDynamicMotion(v2);
  else
    v6 = &v2->m_motion;
  v7 = _mm_shuffle_ps(v6->m_inertiaAndMassInv.m_quad, v6->m_inertiaAndMassInv.m_quad, 255);
  r.m_quad = _mm_sub_ps(v22.m_quad, v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  hkMatrix3f::setCrossSkewSymmetric(&aTb, &r);
  v6->vfptr[6].__vecDelDtor((hkBaseObject *)&v6->vfptr, (unsigned int)&bTc);
  v24.m_col2.m_quad = _mm_mul_ps(v7, stru_141A71280.m_quad);
  v24.m_col0.m_quad = _mm_mul_ps(v7, transform.m_quad);
  v24.m_col1.m_quad = _mm_mul_ps(v7, direction.m_quad);
  hkMatrix3f::setMul(&v29, &aTb, &bTc);
  hkMatrix3f::setMul(&a, &v29, &aTb);
  hkMatrix3f::sub(&v24, &a);
  hkMatrix3f::invert(&v24, &result, 0.0000001);
  if ( result.m_enum == HK_SUCCESS )
  {
    v8 = _mm_shuffle_ps((__m128)v4[6].m128_u32[3], (__m128)v4[6].m128_u32[3], 0);
    v27 = _mm_mul_ps(v2->m_motion.m_linearVelocity.m_quad, v8);
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    v2->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)&v27);
    v25 = _mm_mul_ps(v2->m_motion.m_angularVelocity.m_quad, v8);
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v2->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v2->m_motion,
      &v25);
    v9 = _mm_sub_ps(v22.m_quad, v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v10 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v2->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v2->m_motion.m_angularVelocity.m_quad, v2->m_motion.m_angularVelocity.m_quad, 201),
              v9));
    v33 = v4[6].m128_f32[1] * v3->m_invDeltaTime.m_storage;
    v11 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 201), v2->m_motion.m_linearVelocity.m_quad),
              _mm_shuffle_ps((__m128)v4[6].m128_u32[0], (__m128)v4[6].m128_u32[0], 0)),
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
    v14 = _mm_shuffle_ps(v6->m_inertiaAndMassInv.m_quad, v6->m_inertiaAndMassInv.m_quad, 255);
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
    v33 = v4[6].m128_f32[2] * v3->m_deltaTime.m_storage;
    v18 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v33), (__m128)LODWORD(v33), 0), v16);
    if ( v15.m128_f32[0] > (float)(v18.m128_f32[0] * v18.m128_f32[0]) )
    {
      v19 = _mm_rsqrt_ps(v15);
      v23 = _mm_mul_ps(
              v12,
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v15, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v15), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))),
                v18));
    }
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v2->m_motion.vfptr[11].__first_virtual_table_function__)(
      &v2->m_motion,
      &v23,
      &v22);
    v20 = 0;
    if ( v4[8].m128_i32[0] > 0 )
    {
      v21 = 0i64;
      do
      {
        (*(void (__fastcall **)(__m128 *, hkStepInfo *, __m128 *))(v4[7].m128_u64[1] + v21))(v4, v3, &v23);
        ++v20;
        v21 += 8i64;
      }
      while ( v20 < v4[8].m128_i32[0] );
    }
  }
}

// File Line: 218
// RVA: 0xE172D0
void __fastcall hkpMouseSpringAction::entityRemovedCallback(hkpMouseSpringAction *this, hkpEntity *entity)
{
  hkpMouseSpringAction *v2; // rbx

  v2 = this;
  hkpUnaryAction::entityRemovedCallback((hkpUnaryAction *)&this->vfptr, entity);
  v2->m_entity = 0i64;
}

// File Line: 226
// RVA: 0xE17710
hkpAction *__fastcall hkpMouseSpringAction::clone(hkpMouseSpringAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody ***v3; // rbx
  hkpMouseSpringAction *v4; // rdi
  _QWORD **v6; // rax
  hkpMouseSpringAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rdx
  char *v13; // r8
  __int64 v14; // rax
  int v15; // [rsp+38h] [rbp+10h]

  v3 = (hkpRigidBody ***)newEntities;
  v4 = this;
  if ( newEntities->m_size != 1 || newPhantoms->m_size )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMouseSpringAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 144i64);
  if ( v7 )
  {
    hkpMouseSpringAction::hkpMouseSpringAction(v7, **v3);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(hkVector4f *)(v9 + 64) = v4->m_positionInRbLocal;
  *(hkVector4f *)(v9 + 80) = v4->m_mousePositionInWorld;
  *(float *)(v9 + 96) = v4->m_springDamping;
  *(float *)(v9 + 100) = v4->m_springElasticity;
  *(float *)(v9 + 104) = v4->m_maxRelativeForce;
  *(float *)(v9 + 108) = v4->m_objectDamping;
  *(_QWORD *)(v9 + 32) = v4->m_userData;
  *(_DWORD *)(v9 + 112) = v4->m_shapeKey;
  if ( (*(_DWORD *)(v9 + 132) & 0x3FFFFFFF) < v4->m_applyCallbacks.m_size )
  {
    if ( *(_DWORD *)(v9 + 132) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v9 + 120),
        8 * *(_DWORD *)(v9 + 132));
    v15 = 8 * v4->m_applyCallbacks.m_size;
    *(_QWORD *)(v9 + 120) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                              &v15);
    *(_DWORD *)(v9 + 132) = v15 / 8;
  }
  v10 = v4->m_applyCallbacks.m_size;
  v11 = *(_QWORD *)(v9 + 120);
  *(_DWORD *)(v9 + 128) = v10;
  v12 = v10;
  if ( (signed int)v10 > 0 )
  {
    v13 = (char *)v4->m_applyCallbacks.m_data - v11;
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

