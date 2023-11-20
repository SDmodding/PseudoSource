// File Line: 34
// RVA: 0xD665F0
void __fastcall hkpAabbPhantom::hkpAabbPhantom(hkpAabbPhantom *this, hkAabb *aabb, unsigned int collisionFilterInfo)
{
  hkAabb *v3; // rbx
  unsigned int v4; // esi
  hkpAabbPhantom *v5; // rdi

  v3 = aabb;
  v4 = collisionFilterInfo;
  v5 = this;
  hkpWorldObject::hkpWorldObject((hkpWorldObject *)&this->vfptr, 0i64, BROAD_PHASE_PHANTOM);
  v5->m_overlapListeners.m_capacityAndFlags = 2147483648;
  v5->m_overlapListeners.m_data = 0i64;
  v5->m_overlapListeners.m_size = 0;
  v5->m_phantomListeners.m_data = 0i64;
  v5->m_phantomListeners.m_size = 0;
  v5->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v5->m_collidable.m_ownerOffset = -32;
  v5->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable;
  v5->m_overlappingCollidables.m_data = 0i64;
  v5->m_overlappingCollidables.m_size = 0;
  v5->m_overlappingCollidables.m_capacityAndFlags = 2147483648;
  v5->m_orderDirty.m_bool = 0;
  v5->m_aabb.m_min = v3->m_min;
  v5->m_aabb.m_max = v3->m_max;
  v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v4;
}

// File Line: 42
// RVA: 0xD666B0
void __fastcall hkpAabbPhantom::~hkpAabbPhantom(hkpAabbPhantom *this)
{
  hkpAabbPhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable;
  v2 = this->m_overlappingCollidables.m_capacityAndFlags;
  this->m_overlappingCollidables.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_overlappingCollidables.m_data,
      8 * v2);
  v1->m_overlappingCollidables.m_data = 0i64;
  v1->m_overlappingCollidables.m_capacityAndFlags = 2147483648;
  hkpPhantom::~hkpPhantom((hkpPhantom *)&v1->vfptr);
}

// File Line: 46
// RVA: 0xD66730
__int64 __fastcall hkpAabbPhantom::getType(hkpAabbPhantom *this)
{
  return 0i64;
}

// File Line: 52
// RVA: 0xD66FC0
hkpPhantom *__fastcall hkpAabbPhantom::clone(hkpAabbPhantom *this)
{
  hkpAabbPhantom *v1; // rdi
  _QWORD **v2; // rax
  hkpAabbPhantom *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  __int64 v15; // rax
  int v17; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 304i64);
  if ( v3 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v3, &v1->m_aabb, v1->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  if ( (*(_DWORD *)(v5 + 212) & 0x3FFFFFFF) < v1->m_overlapListeners.m_size )
  {
    if ( *(_DWORD *)(v5 + 212) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v5 + 200),
        8 * *(_DWORD *)(v5 + 212));
    v17 = 8 * v1->m_overlapListeners.m_size;
    *(_QWORD *)(v5 + 200) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                              &v17);
    *(_DWORD *)(v5 + 212) = v17 / 8;
  }
  v6 = v1->m_overlapListeners.m_size;
  v7 = *(_QWORD *)(v5 + 200);
  *(_DWORD *)(v5 + 208) = v6;
  v8 = v6;
  if ( (signed int)v6 > 0 )
  {
    v9 = (char *)v1->m_overlapListeners.m_data - v7;
    do
    {
      v10 = *(_QWORD *)&v9[v7];
      v7 += 8i64;
      *(_QWORD *)(v7 - 8) = v10;
      --v8;
    }
    while ( v8 );
  }
  if ( (*(_DWORD *)(v5 + 228) & 0x3FFFFFFF) < v1->m_phantomListeners.m_size )
  {
    if ( *(_DWORD *)(v5 + 228) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v5 + 216),
        8 * *(_DWORD *)(v5 + 228));
    v17 = 8 * v1->m_phantomListeners.m_size;
    *(_QWORD *)(v5 + 216) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                              &v17);
    *(_DWORD *)(v5 + 228) = v17 / 8;
  }
  v11 = v1->m_phantomListeners.m_size;
  v12 = *(_QWORD *)(v5 + 216);
  *(_DWORD *)(v5 + 224) = v11;
  v13 = v11;
  if ( (signed int)v11 > 0 )
  {
    v14 = (char *)v1->m_phantomListeners.m_data - v12;
    do
    {
      v15 = *(_QWORD *)&v14[v12];
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v15;
      --v13;
    }
    while ( v13 );
  }
  hkpWorldObject::copyProperties((hkpWorldObject *)v5, (hkpWorldObject *)&v1->vfptr);
  return (hkpPhantom *)v5;
}

// File Line: 65
// RVA: 0xD66E00
void __fastcall hkpAabbPhantom::calcAabb(hkpAabbPhantom *this, hkAabb *aabb)
{
  aabb->m_min = this->m_aabb.m_min;
  aabb->m_max = this->m_aabb.m_max;
}

// File Line: 70
// RVA: 0xD67190
void __fastcall hkpAabbPhantom::setAabb(hkpAabbPhantom *this, hkAabb *newAabb)
{
  hkAabb *v2; // rax
  hkVector4f *v3; // rdx

  v2 = newAabb;
  v3 = &this->m_aabb.m_min;
  *v3 = v2->m_min;
  v3[1] = v2->m_max;
  hkpPhantom::updateBroadPhase((hkpPhantom *)&this->vfptr, &this->m_aabb);
}

// File Line: 80
// RVA: 0xD66740
void __fastcall hkpAabbPhantom::castRay(hkpAabbPhantom *this, hkpWorldRayCastInput *input, hkpRayHitCollector *collector)
{
  hkpAabbPhantom *v3; // rdi
  hkpRayHitCollector *v4; // rbp
  hkpWorldRayCastInput *v5; // rsi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpCollisionFilter *v11; // rax
  hkpCollidable **v12; // rbx
  int v13; // edi
  hkpShape *v14; // rcx
  __m128 *v15; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  __m128 v30; // [rsp+20h] [rbp-48h]
  __m128 v31; // [rsp+30h] [rbp-38h]
  unsigned int v32; // [rsp+40h] [rbp-28h]
  hkpRayShapeCollectionFilter *v33; // [rsp+48h] [rbp-20h]
  __int64 v34; // [rsp+50h] [rbp-18h]
  unsigned __int64 i; // [rsp+58h] [rbp-10h]

  v3 = this;
  v4 = collector;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtrcPhantom";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v32 = v5->m_filterInfo;
  v33 = 0i64;
  v34 = 0i64;
  i = 0i64;
  if ( v5->m_enableShapeCollectionFilter.m_bool && (v11 = v3->m_world->m_collisionFilter) != 0i64 )
    v33 = (hkpRayShapeCollectionFilter *)&v11->vfptr;
  else
    v33 = 0i64;
  v12 = v3->m_overlappingCollidables.m_data;
  v13 = v3->m_overlappingCollidables.m_size - 1;
  for ( i = v5->m_userData; v13 >= 0; --v13 )
  {
    v14 = (*v12)->m_shape;
    if ( v14 )
    {
      v15 = (__m128 *)(*v12)->m_motion;
      v16 = _mm_sub_ps(v5->m_from.m_quad, v15[3]);
      v17 = v15[2];
      v18 = _mm_unpacklo_ps(*v15, v15[1]);
      v19 = _mm_movelh_ps(v18, v17);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v17, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v19)),
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v15, v15[1]), v17, 228)));
      v21 = v5->m_to.m_quad;
      v30 = v20;
      v22 = _mm_sub_ps(v21, v15[3]);
      v23 = v15[2];
      v24 = _mm_unpacklo_ps(*v15, v15[1]);
      v25 = _mm_movelh_ps(v24, v23);
      v31 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v25)),
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v15, v15[1]), v23, 228)));
      ((void (__fastcall *)(hkpShape *, __m128 *, hkpCollidable *, hkpRayHitCollector *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, hkpRayShapeCollectionFilter *, hkpCollidable *, unsigned __int64))v14->vfptr[3].__vecDelDtor)(
        v14,
        &v30,
        *v12,
        v4,
        v30.m128_u64[0],
        v30.m128_u64[1],
        v31.m128_u64[0],
        v31.m128_u64[1],
        *(_QWORD *)&v32,
        v33,
        *v12,
        i);
    }
    ++v12;
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v26[1] = v29;
  }
}

// File Line: 136
// RVA: 0xD66930
void __fastcall hkpAabbPhantom::castRay(hkpAabbPhantom *this, hkpWorldRayCastInput *input, hkpWorldRayCastOutput *output)
{
  hkpAabbPhantom *v3; // rdi
  hkpWorldRayCastOutput *v4; // rsi
  hkpWorldRayCastInput *v5; // rbp
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpCollisionFilter *v11; // rax
  hkpCollidable **v12; // rbx
  int v13; // edi
  hkpShape *v14; // rcx
  __m128 *v15; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkpCollidable *v28; // rdx
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  __m128 v33; // [rsp+20h] [rbp-48h]
  __m128 v34; // [rsp+30h] [rbp-38h]
  unsigned int v35; // [rsp+40h] [rbp-28h]
  hkpRayShapeCollectionFilter *v36; // [rsp+48h] [rbp-20h]
  __int64 v37; // [rsp+50h] [rbp-18h]
  unsigned __int64 i; // [rsp+58h] [rbp-10h]
  char v39; // [rsp+70h] [rbp+8h]

  v3 = this;
  v4 = output;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtrcPhantom";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v35 = v5->m_filterInfo;
  v36 = 0i64;
  v37 = 0i64;
  i = 0i64;
  if ( v5->m_enableShapeCollectionFilter.m_bool && (v11 = v3->m_world->m_collisionFilter) != 0i64 )
    v36 = (hkpRayShapeCollectionFilter *)&v11->vfptr;
  else
    v36 = 0i64;
  v12 = v3->m_overlappingCollidables.m_data;
  v13 = v3->m_overlappingCollidables.m_size - 1;
  for ( i = v5->m_userData; v13 >= 0; --v13 )
  {
    v14 = (*v12)->m_shape;
    if ( v14 )
    {
      v15 = (__m128 *)(*v12)->m_motion;
      v16 = _mm_sub_ps(v5->m_from.m_quad, v15[3]);
      v17 = v15[2];
      v18 = _mm_unpacklo_ps(*v15, v15[1]);
      v19 = _mm_movelh_ps(v18, v17);
      v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v17, 212));
      v21 = _mm_shuffle_ps(v16, v16, 0);
      v22 = _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v15, v15[1]), v17, 228), _mm_shuffle_ps(v16, v16, 170));
      v23 = v5->m_to.m_quad;
      v33 = _mm_add_ps(_mm_add_ps(v20, _mm_mul_ps(v21, v19)), v22);
      v24 = _mm_sub_ps(v23, v15[3]);
      v25 = v15[2];
      v26 = _mm_unpacklo_ps(*v15, v15[1]);
      v27 = _mm_movelh_ps(v26, v25);
      v34 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(_mm_movehl_ps(v27, v26), v25, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v27)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v15, v15[1]), v25, 228)));
      ((void (__fastcall *)(hkpShape *, char *, __m128 *, hkpWorldRayCastOutput *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, hkpRayShapeCollectionFilter *, hkpCollidable *, unsigned __int64))v14->vfptr[2].__first_virtual_table_function__)(
        v14,
        &v39,
        &v33,
        v4,
        v33.m128_u64[0],
        v33.m128_u64[1],
        v34.m128_u64[0],
        v34.m128_u64[1],
        *(_QWORD *)&v35,
        v36,
        *v12,
        i);
      if ( v39 )
        v4->m_rootCollidable = *v12;
    }
    ++v12;
  }
  v28 = v4->m_rootCollidable;
  if ( v28 )
    hkVector4f::setRotatedDir(&v4->m_normal, (hkMatrix3f *)v28->m_motion, &v4->m_normal);
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] = v32;
  }
}

// File Line: 201
// RVA: 0xD66B40
void __fastcall hkpAabbPhantom::linearCast(hkpAabbPhantom *this, hkpCollidable *const toBeCast, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkpAabbPhantom *v5; // rbp
  hkpCdPointCollector *v6; // r13
  __m128 *v7; // rbx
  hkpCollidable *v8; // rsi
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpWorld *v13; // rdx
  int v14; // xmm5_4
  __int64 v15; // rdi
  __m128 v16; // xmm2
  hkpProcessCollisionInput *v17; // rcx
  __int64 v18; // rax
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  hkpCollisionDispatcher *v22; // r15
  hkpCollisionFilter *v23; // r14
  hkpCdPointCollector *v24; // r12
  hkpCollidable *v25; // rbx
  _BYTE *v26; // rax
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  hkpCollisionDispatcher *v32; // [rsp+30h] [rbp-B8h]
  unsigned int v33; // [rsp+38h] [rbp-B0h]
  unsigned int v34; // [rsp+3Ch] [rbp-ACh]
  float v35; // [rsp+40h] [rbp-A8h]
  hkpCollisionFilter *v36; // [rsp+48h] [rbp-A0h]
  hkpConvexListFilter *v37; // [rsp+50h] [rbp-98h]
  unsigned int v38; // [rsp+58h] [rbp-90h]
  hkVector4f v39; // [rsp+60h] [rbp-88h]
  hkVector4f v40; // [rsp+70h] [rbp-78h]
  hkVector4f v41; // [rsp+80h] [rbp-68h]
  __m128 v42; // [rsp+90h] [rbp-58h]
  float v43; // [rsp+A0h] [rbp-48h]
  int v44; // [rsp+A4h] [rbp-44h]
  __int64 v45; // [rsp+A8h] [rbp-40h]
  char v46; // [rsp+F0h] [rbp+8h]
  __int64 v47; // [rsp+F8h] [rbp+10h]

  v5 = this;
  v6 = castCollector;
  v7 = &input->m_to.m_quad;
  v8 = toBeCast;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TthkpAabbPhantom::linearCast";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = v5->m_world;
  v14 = v7[1].m128_i32[1];
  v15 = 0i64;
  v16 = _mm_sub_ps(*v7, *((__m128 *)v8->m_motion + 3));
  v43 = FLOAT_1_1920929eN7;
  v34 = 0;
  v17 = v13->m_collisionInput;
  v32 = v17->m_dispatcher.m_storage;
  v33 = v17->m_weldClosestPoints.m_storage;
  v34 = v17->m_forceAcceptContactPoints.m_storage;
  v35 = v17->m_tolerance.m_storage;
  v36 = v17->m_filter.m_storage;
  v37 = v17->m_convexListFilter.m_storage;
  v38 = v17->m_createPredictiveAgents.m_storage;
  v39.m_quad = (__m128)v17->m_aabb32Info.m_bitOffsetLow;
  v40.m_quad = (__m128)v17->m_aabb32Info.m_bitOffsetHigh;
  v41.m_quad = (__m128)v17->m_aabb32Info.m_bitScale;
  v18 = (__int64)v17->m_config;
  v42 = v16;
  v35 = *(float *)&v14;
  v45 = v18;
  v19 = _mm_mul_ps(v16, v16);
  v47 = v5->m_overlappingCollidables.m_size;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v43 = v7[1].m128_f32[0];
  v44 = (unsigned __int128)_mm_andnot_ps(
                             _mm_cmpleps(v20, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v21)),
                               v20));
  v22 = v13->m_collisionDispatcher;
  v23 = v13->m_collisionFilter;
  if ( v47 > 0 )
  {
    v24 = startCollector;
    do
    {
      v25 = v5->m_overlappingCollidables.m_data[v15];
      v26 = (_BYTE *)v23->vfptr->isCollisionEnabled(
                       (hkpCollidableCollidableFilter *)&v23->vfptr,
                       (hkBool *)&v46,
                       v8,
                       v5->m_overlappingCollidables.m_data[v15]);
      if ( v25->m_shape && *v26 && v25 != v8 )
        v22->m_agent2Func[(unsigned __int8)v22->m_agent2Types[(unsigned __int8)v8->m_shape->m_type.m_storage][(unsigned __int8)v25->m_shape->m_type.m_storage]].m_linearCastFunc(
          (hkpCdBody *)&v8->m_shape,
          (hkpCdBody *)&v25->m_shape,
          (hkpLinearCastCollisionInput *)&v32,
          v6,
          v24);
      ++v15;
    }
    while ( v15 < v47 );
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  v29 = v27;
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v30 = __rdtsc();
    v31 = (signed __int64)(v28 + 2);
    *(_DWORD *)(v31 - 8) = v30;
    v29[1] = v31;
  }
}

// File Line: 242
// RVA: 0xD66EA0
hkBool *__fastcall hkpAabbPhantom::isOverlappingCollidableAdded(hkpAabbPhantom *this, hkBool *result, hkpCollidable *collidable)
{
  __int64 v3; // r10
  __int64 v4; // r9
  hkpCollidable **v5; // rax
  hkBool *v6; // rax

  v3 = this->m_overlappingCollidables.m_size;
  v4 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_5:
    result->m_bool = 0;
    v6 = result;
  }
  else
  {
    v5 = this->m_overlappingCollidables.m_data;
    while ( *v5 != collidable )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
    result->m_bool = 1;
    v6 = result;
  }
  return v6;
}

// File Line: 255
// RVA: 0xD66E20
void __fastcall hkpAabbPhantom::addOverlappingCollidable(hkpAabbPhantom *this, hkpCollidable *collidable)
{
  hkpCollidable *v2; // rsi
  hkpAabbPhantom *v3; // rdi

  v2 = collidable;
  v3 = this;
  if ( hkpPhantom::fireCollidableAdded((hkpPhantom *)&this->vfptr, collidable) == HK_COLLIDABLE_ACCEPT )
  {
    if ( v3->m_overlappingCollidables.m_size == (v3->m_overlappingCollidables.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_overlappingCollidables,
        8);
    v3->m_overlappingCollidables.m_data[v3->m_overlappingCollidables.m_size++] = v2;
    v3->m_orderDirty.m_bool = 1;
  }
}

// File Line: 270
// RVA: 0xD66EE0
void __fastcall hkpAabbPhantom::removeOverlappingCollidable(hkpAabbPhantom *this, hkpCollidable *collidable)
{
  hkpAabbPhantom *v2; // rsi
  signed int v3; // edi
  __int64 v4; // r8
  __int64 v5; // rcx
  hkpCollidable **v6; // rax
  int v7; // eax
  __int64 i; // rbx
  hkpPhantomOverlapListener *v9; // rcx
  __int64 v10; // rax
  hkpAabbPhantom *v11; // [rsp+20h] [rbp-28h]
  hkpCollidable *v12; // [rsp+28h] [rbp-20h]
  bool v13; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = 0;
  v4 = this->m_overlappingCollidables.m_size;
  v5 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v6 = v2->m_overlappingCollidables.m_data;
    while ( *v6 != collidable )
    {
      ++v5;
      ++v3;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_5;
    }
  }
  v12 = collidable;
  v11 = v2;
  v13 = v3 >= 0;
  v7 = v2->m_overlapListeners.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = v2->m_overlapListeners.m_data[i];
    if ( v9 )
      v9->vfptr->collidableRemovedCallback(v9, (hkpCollidableRemovedEvent *)&v11);
  }
  if ( v3 >= 0 )
  {
    v10 = --v2->m_overlappingCollidables.m_size;
    if ( (_DWORD)v10 != v3 )
      v2->m_overlappingCollidables.m_data[v3] = v2->m_overlappingCollidables.m_data[v10];
    v2->m_orderDirty.m_bool = 1;
  }
}

// File Line: 287
// RVA: 0xD671C0
void __fastcall hkpAabbPhantom::deallocateInternalArrays(hkpAabbPhantom *this)
{
  hkpAabbPhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  if ( !this->m_overlappingCollidables.m_size )
  {
    v2 = this->m_overlappingCollidables.m_capacityAndFlags;
    this->m_overlappingCollidables.m_size = 0;
    if ( v2 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_overlappingCollidables.m_data,
        8 * v2);
    v1->m_overlappingCollidables.m_data = 0i64;
    v1->m_overlappingCollidables.m_capacityAndFlags = 2147483648;
  }
  hkpPhantom::deallocateInternalArrays((hkpPhantom *)&v1->vfptr);
}

// File Line: 316
// RVA: 0xD67240
void __fastcall hkpAabbPhantom::ensureDeterministicOrder(hkpAabbPhantom *this)
{
  hkpAabbPhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  if ( this->m_orderDirty.m_bool )
  {
    v2 = this->m_overlappingCollidables.m_size;
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkpCollidable *,hkpAabbPhantom::OrderByUid>(
        this->m_overlappingCollidables.m_data,
        0,
        v2 - 1,
        0);
    v1->m_orderDirty.m_bool = 0;
  }
}

