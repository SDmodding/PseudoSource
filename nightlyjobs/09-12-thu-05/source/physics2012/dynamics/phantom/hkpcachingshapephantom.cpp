// File Line: 32
// RVA: 0xD68160
void __fastcall hkpCachingShapePhantom::hkpCachingShapePhantom(hkpCachingShapePhantom *this, hkpShape *shape, hkTransformf *transform, unsigned int collisionFilterInfo)
{
  unsigned int v4; // edi
  hkpCachingShapePhantom *v5; // rbx

  v4 = collisionFilterInfo;
  v5 = this;
  hkpShapePhantom::hkpShapePhantom((hkpShapePhantom *)&this->vfptr, shape, transform);
  v5->vfptr = (hkBaseObjectVtbl *)&hkpCachingShapePhantom::`vftable;
  v5->m_collisionDetails.m_capacityAndFlags = 2147483648;
  v5->m_collisionDetails.m_data = 0i64;
  v5->m_collisionDetails.m_size = 0;
  v5->m_orderDirty.m_bool = 0;
  v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v4;
}

// File Line: 37
// RVA: 0xD681C0
void __fastcall hkpCachingShapePhantom::~hkpCachingShapePhantom(hkpCachingShapePhantom *this)
{
  hkpCachingShapePhantom *v1; // rsi
  int v2; // eax
  __int64 v3; // rdi
  signed __int64 v4; // rbx
  int v5; // er8
  void **v6; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+28h] [rbp-20h]

  v1 = this;
  v7 = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCachingShapePhantom::`vftable;
  v6 = &hkpConstraintOwner::`vftable;
  v2 = this->m_collisionDetails.m_size - 1;
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = v2;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, void ***))v1->m_collisionDetails.m_data[v4].m_agent->vfptr[3].__first_virtual_table_function__)(
        v1->m_collisionDetails.m_data[v4].m_agent,
        &v6);
      --v3;
      --v4;
    }
    while ( v3 >= 0 );
  }
  v1->m_collisionDetails.m_size = 0;
  v5 = v1->m_collisionDetails.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_collisionDetails.m_data,
      16 * v5);
  v1->m_collisionDetails.m_data = 0i64;
  v1->m_collisionDetails.m_capacityAndFlags = 2147483648;
  hkpPhantom::~hkpPhantom((hkpPhantom *)&v1->vfptr);
}

// File Line: 51
// RVA: 0xD68500
hkpPhantom *__fastcall hkpCachingShapePhantom::clone(hkpCachingShapePhantom *this)
{
  hkpCachingShapePhantom *v1; // rdi
  _QWORD **v2; // rax
  hkpCachingShapePhantom *v3; // rax
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
  v3 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 448i64);
  if ( v3 )
  {
    hkpCachingShapePhantom::hkpCachingShapePhantom(
      v3,
      v1->m_collidable.m_shape,
      &v1->m_motionState.m_transform,
      v1->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo);
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

// File Line: 110
// RVA: 0xD682A0
signed __int64 __fastcall hkpCachingShapePhantom::getType(hkpCachingShapePhantom *this)
{
  return 2i64;
}

// File Line: 116
// RVA: 0xD682B0
void __fastcall hkpCachingShapePhantom::setPositionAndLinearCast(hkpCachingShapePhantom *this, hkVector4f *position, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkpCachingShapePhantom *v5; // r14
  hkpCdPointCollector *v6; // r12
  hkVector4f *v7; // rbx
  __m128 *v8; // rdi
  float v9; // xmm2_4
  __m128 v10; // xmm7
  hkpWorld *v11; // rax
  int v12; // xmm5_4
  hkpProcessCollisionInput *v13; // rcx
  __int64 v14; // rax
  __m128 v15; // xmm7
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  float v18; // xmm0_4
  int v19; // eax
  __int64 v20; // rdi
  signed __int64 v21; // rbx
  hkpCachingShapePhantom::CollisionDetail *v22; // r8
  hkpCollisionAgent *v23; // rcx
  hkpCollidable *v24; // r8
  hkAabb aabb; // [rsp+28h] [rbp-71h]
  float v26; // [rsp+48h] [rbp-51h]
  hkpCollisionFilter *v27; // [rsp+50h] [rbp-49h]
  hkpConvexListFilter *v28; // [rsp+58h] [rbp-41h]
  unsigned int v29; // [rsp+60h] [rbp-39h]
  hkVector4f v30; // [rsp+68h] [rbp-31h]
  hkVector4f v31; // [rsp+78h] [rbp-21h]
  hkVector4f v32; // [rsp+88h] [rbp-11h]
  __m128 v33; // [rsp+98h] [rbp-1h]
  float v34; // [rsp+A8h] [rbp+Fh]
  int v35; // [rsp+ACh] [rbp+13h]
  __int64 v36; // [rsp+B0h] [rbp+17h]
  unsigned __int64 v37; // [rsp+118h] [rbp+7Fh]

  v5 = this;
  v6 = castCollector;
  v7 = position;
  v8 = &input->m_to.m_quad;
  this->m_motionState.m_transform.m_translation = (hkVector4f)position->m_quad;
  v9 = (float)(this->m_world->m_collisionInput->m_tolerance.m_storage * 0.5) + input->m_startPointTolerance;
  ((void (__fastcall *)(hkpShape *, hkMotionState *, hkpLinearCastInput *, unsigned __int16 *))this->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
    this->m_collidable.m_shape,
    &this->m_motionState,
    input,
    &aabb.m_min.m_quad.m128_u16[4]);
  v10 = _mm_sub_ps(*v8, v7->m_quad);
  *(__m128 *)((char *)&aabb.m_min.m_quad + 8) = _mm_add_ps(
                                                  *(__m128 *)((char *)&aabb.m_min.m_quad + 8),
                                                  _mm_min_ps((__m128)0i64, v10));
  aabb.m_min.m_quad = _mm_add_ps(aabb.m_min.m_quad, _mm_max_ps((__m128)0i64, v10));
  hkpPhantom::updateBroadPhase((hkpPhantom *)&v5->vfptr, (hkAabb *)((char *)&aabb + 8));
  v11 = v5->m_world;
  v12 = v8[1].m128_i32[1];
  v34 = FLOAT_1_1920929eN7;
  v13 = v11->m_collisionInput;
  aabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)v13->m_dispatcher.m_storage;
  aabb.m_max.m_quad.m128_u64[1] = v13->m_weldClosestPoints.m_storage;
  aabb.m_max.m_quad.m128_i32[3] = v13->m_forceAcceptContactPoints.m_storage;
  v26 = v13->m_tolerance.m_storage;
  v27 = v13->m_filter.m_storage;
  v28 = v13->m_convexListFilter.m_storage;
  v29 = v13->m_createPredictiveAgents.m_storage;
  v30.m_quad = (__m128)v13->m_aabb32Info.m_bitOffsetLow;
  v31.m_quad = (__m128)v13->m_aabb32Info.m_bitOffsetHigh;
  v32.m_quad = (__m128)v13->m_aabb32Info.m_bitScale;
  v14 = (__int64)v13->m_config;
  v33 = v10;
  v36 = v14;
  v15 = _mm_mul_ps(v10, v10);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = v8[1].m128_f32[0];
  v19 = v5->m_collisionDetails.m_size - 1;
  v26 = *(float *)&v12;
  v34 = v18;
  v20 = v19;
  v35 = (unsigned __int128)_mm_andnot_ps(
                             _mm_cmpleps(v16, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v17)),
                               v16));
  if ( v19 >= 0 )
  {
    v21 = v19;
    do
    {
      v22 = v5->m_collisionDetails.m_data;
      v23 = v22[v21].m_agent;
      v24 = v22[v21].m_collidable;
      aabb.m_min.m_quad.m128_u64[0] = v37;
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkVector4f *, hkpCdPointCollector *, unsigned __int64))v23->vfptr[2].__first_virtual_table_function__)(
        v23,
        &v5->m_collidable,
        v24,
        &aabb.m_max,
        v6,
        v37);
      --v20;
      --v21;
    }
    while ( v20 >= 0 );
  }
}

// File Line: 167
// RVA: 0xD684D0
void __fastcall hkpCachingShapePhantom::setTransformAndLinearCast(hkpCachingShapePhantom *this, hkTransformf *transform, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkVector4f v5; // xmm0
  hkVector4f *v6; // rdx

  v5.m_quad = (__m128)transform->m_rotation.m_col0;
  v6 = &transform->m_translation;
  this->m_motionState.m_transform.m_rotation.m_col0 = (hkVector4f)v5.m_quad;
  this->m_motionState.m_transform.m_rotation.m_col1 = (hkVector4f)v6[-2].m_quad;
  this->m_motionState.m_transform.m_rotation.m_col2 = (hkVector4f)v6[-1].m_quad;
  hkpCachingShapePhantom::setPositionAndLinearCast(this, v6, input, castCollector, startCollector);
}

// File Line: 177
// RVA: 0xD686D0
void __fastcall hkpCachingShapePhantom::getClosestPoints(hkpCachingShapePhantom *this, hkpCdPointCollector *collector, hkpCollisionInput *input)
{
  hkpProcessCollisionInput *v3; // rbp
  hkpCdPointCollector *v4; // r14
  hkpCachingShapePhantom *v5; // rsi
  int v6; // eax
  __int64 v7; // rbx
  signed __int64 v8; // rdi

  v3 = (hkpProcessCollisionInput *)input;
  v4 = collector;
  v5 = this;
  if ( !input )
    v3 = this->m_world->m_collisionInput;
  v6 = this->m_collisionDetails.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = v6;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkpProcessCollisionInput *, hkpCdPointCollector *))v5->m_collisionDetails.m_data[v8].m_agent->vfptr[2].__vecDelDtor)(
        v5->m_collisionDetails.m_data[v8].m_agent,
        &v5->m_collidable,
        v5->m_collisionDetails.m_data[v8].m_collidable,
        v3,
        v4);
      --v7;
      --v8;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 193
// RVA: 0xD687C0
void __fastcall hkpCachingShapePhantom::getPenetrations(hkpCachingShapePhantom *this, hkpCdBodyPairCollector *collector, hkpCollisionInput *input)
{
  hkpProcessCollisionInput *v3; // rbp
  hkpCdBodyPairCollector *v4; // r14
  hkpCachingShapePhantom *v5; // rsi
  int v6; // eax
  __int64 v7; // rbx
  signed __int64 v8; // rdi

  v3 = (hkpProcessCollisionInput *)input;
  v4 = collector;
  v5 = this;
  if ( !input )
    v3 = this->m_world->m_collisionInput;
  v6 = this->m_collisionDetails.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = v6;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkpProcessCollisionInput *, hkpCdBodyPairCollector *))v5->m_collisionDetails.m_data[v8].m_agent->vfptr[1].__first_virtual_table_function__)(
        v5->m_collisionDetails.m_data[v8].m_agent,
        &v5->m_collidable,
        v5->m_collisionDetails.m_data[v8].m_collidable,
        v3,
        v4);
      if ( v4->m_earlyOut.m_bool )
        break;
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 216
// RVA: 0xD68BF0
hkBool *__fastcall hkpCachingShapePhantom::isOverlappingCollidableAdded(hkpCachingShapePhantom *this, hkBool *result, hkpCollidable *collidable)
{
  __int64 v3; // r10
  __int64 v4; // r9
  hkpCollidable **v5; // rax
  hkBool *v6; // rax

  v3 = this->m_collisionDetails.m_size;
  v4 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_5:
    result->m_bool = 0;
    v6 = result;
  }
  else
  {
    v5 = &this->m_collisionDetails.m_data->m_collidable;
    while ( *v5 != collidable )
    {
      ++v4;
      v5 += 2;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
    result->m_bool = 1;
    v6 = result;
  }
  return v6;
}

// File Line: 232
// RVA: 0xD68870
void __fastcall hkpCachingShapePhantom::addOverlappingCollidable(hkpCachingShapePhantom *this, hkpCollidable *collidable)
{
  hkpCollidable *v2; // rsi
  hkpCachingShapePhantom *v3; // r14
  _QWORD *v4; // rbx
  hkpProcessCollisionInput *v5; // rdx
  __int128 v6; // xmm1
  hkpCollisionQualityInfo *v7; // rax
  __int64 v8; // rcx
  hkpShape *v9; // rdx
  __int64 v10; // rax
  bool v11; // zf
  _QWORD **v12; // rax
  __int128 v13; // [rsp+20h] [rbp-49h]
  __int128 v14; // [rsp+30h] [rbp-39h]
  __int128 v15; // [rsp+40h] [rbp-29h]
  hkVector4f v16; // [rsp+50h] [rbp-19h]
  hkVector4f v17; // [rsp+60h] [rbp-9h]
  __int128 v18; // [rsp+70h] [rbp+7h]
  __int128 v19; // [rsp+80h] [rbp+17h]
  hkpCollisionQualityInfo *v20; // [rsp+90h] [rbp+27h]
  __int64 v21; // [rsp+98h] [rbp+2Fh]
  void *v22; // [rsp+A0h] [rbp+37h]
  char v23; // [rsp+A8h] [rbp+3Fh]
  char v24; // [rsp+A9h] [rbp+40h]
  __int64 v25; // [rsp+B0h] [rbp+47h]

  v2 = collidable;
  v3 = this;
  if ( collidable->m_shape && !(unsigned int)hkpPhantom::fireCollidableAdded((hkpPhantom *)&this->vfptr, collidable) )
  {
    if ( v3->m_collisionDetails.m_size == (v3->m_collisionDetails.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_collisionDetails,
        16);
    v4 = &v3->m_collisionDetails.m_data[v3->m_collisionDetails.m_size++].m_agent;
    v5 = v3->m_world->m_collisionInput;
    v13 = *(_OWORD *)&v5->m_dispatcher.m_storage;
    v14 = *(_OWORD *)&v5->m_tolerance.m_storage;
    v15 = *(_OWORD *)&v5->m_convexListFilter.m_storage;
    v16.m_quad = (__m128)v5->m_aabb32Info.m_bitOffsetLow;
    v17.m_quad = (__m128)v5->m_aabb32Info.m_bitOffsetHigh;
    v6 = (__int128)v5->m_aabb32Info.m_bitScale;
    v21 = 0i64;
    v18 = v6;
    *(_QWORD *)&v13 = v5->m_dispatcher.m_storage;
    v7 = (hkpCollisionQualityInfo *)v13;
    *((_QWORD *)&v13 + 1) = *(_QWORD *)&v5->m_weldClosestPoints.m_storage;
    *(float *)&v14 = v5->m_tolerance.m_storage;
    *((_QWORD *)&v14 + 1) = v5->m_filter.m_storage;
    *(_QWORD *)&v15 = v5->m_convexListFilter.m_storage;
    DWORD2(v15) = v5->m_createPredictiveAgents.m_storage;
    v16.m_quad = (__m128)v5->m_aabb32Info.m_bitOffsetLow;
    v17.m_quad = (__m128)v5->m_aabb32Info.m_bitOffsetHigh;
    v18 = (__int128)v5->m_aabb32Info.m_bitScale;
    _mm_store_si128((__m128i *)&v19, (__m128i)v5->m_stepInfo);
    v20 = v5->m_collisionQualityInfo.m_storage;
    v22 = v5->m_dynamicsInfo;
    v23 = v5->m_enableDeprecatedWelding.m_bool;
    v24 = v5->m_allowToSkipConfirmedCallbacks.m_bool;
    v8 = (__int64)v5->m_config;
    v9 = v3->m_collidable.m_shape;
    v25 = v8;
    DWORD2(v15) = 0;
    v20 = v7 + 162;
    v10 = (*((__int64 (__fastcall **)(hkpLinkedCollidable *, hkpCollidable *, __int128 *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD))&v7[49].m_createContact
           + 5
           * *((unsigned __int8 *)&v7[10].m_toiAccuracy
             + 35 * (unsigned __int8)v9->m_type.m_storage
             + (unsigned __int8)v2->m_shape->m_type.m_storage)))(
            &v3->m_collidable,
            v2,
            &v13,
            0i64,
            v13,
            *((_QWORD *)&v13 + 1),
            v14,
            *((_QWORD *)&v14 + 1),
            v15,
            *((_QWORD *)&v15 + 1),
            v16.m_quad.m128_u64[0],
            v16.m_quad.m128_u64[1],
            v17.m_quad.m128_u64[0],
            v17.m_quad.m128_u64[1],
            v18,
            *((_QWORD *)&v18 + 1));
    v4[1] = v2;
    *v4 = v10;
    v11 = v21 == 0;
    v3->m_orderDirty.m_bool = 1;
    if ( !v11 )
    {
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v12[11] + 16i64))(v12[11], v21, 512i64);
    }
  }
}

// File Line: 256
// RVA: 0xD68A70
void __fastcall hkpCachingShapePhantom::removeOverlappingCollidable(hkpCachingShapePhantom *this, hkpCollidable *collidable)
{
  bool v2; // zf
  hkpCollidable *v3; // r9
  hkpCachingShapePhantom *v4; // rbx
  int v5; // esi
  __int64 v6; // rdx
  hkpCollidable **v7; // r8
  int v8; // eax
  __int64 i; // rdi
  hkpPhantomOverlapListener *v10; // rcx
  int v11; // eax
  __int64 j; // rdi
  hkpPhantomOverlapListener *v13; // rcx
  hkpCollisionAgent *v14; // rcx
  __int64 v15; // rcx
  signed __int64 v16; // rdx
  signed __int64 v17; // r8
  signed __int64 v18; // rcx
  signed __int64 v19; // r8
  __int64 v20; // rax
  hkpCachingShapePhantom *v21; // [rsp+20h] [rbp-48h]
  hkpCollidable *v22; // [rsp+28h] [rbp-40h]
  char v23; // [rsp+30h] [rbp-38h]
  void **v24; // [rsp+38h] [rbp-30h]
  int v25; // [rsp+40h] [rbp-28h]

  v2 = collidable->m_shape == 0i64;
  v3 = collidable;
  v4 = this;
  v25 = 0x1FFFF;
  v24 = &hkpConstraintOwner::`vftable;
  if ( !v2 )
  {
    v5 = this->m_collisionDetails.m_size - 1;
    v6 = v5;
    if ( v5 < 0 )
    {
LABEL_6:
      v8 = this->m_overlapListeners.m_size;
      v22 = v3;
      v21 = this;
      --v8;
      v23 = 0;
      for ( i = v8; i >= 0; --i )
      {
        v10 = v4->m_overlapListeners.m_data[i];
        if ( v10 )
          v10->vfptr->collidableRemovedCallback(v10, (hkpCollidableRemovedEvent *)&v21);
      }
    }
    else
    {
      v7 = &this->m_collisionDetails.m_data[v5].m_collidable;
      while ( *v7 != v3 )
      {
        --v5;
        v7 -= 2;
        if ( --v6 < 0 )
          goto LABEL_6;
      }
      v11 = this->m_overlapListeners.m_size;
      v22 = v3;
      v21 = this;
      --v11;
      v23 = 1;
      for ( j = v11; j >= 0; --j )
      {
        v13 = v4->m_overlapListeners.m_data[j];
        if ( v13 )
          v13->vfptr->collidableRemovedCallback(v13, (hkpCollidableRemovedEvent *)&v21);
      }
      v14 = v4->m_collisionDetails.m_data[v5].m_agent;
      if ( v14 )
        ((void (__fastcall *)(hkpCollisionAgent *, void ***))v14->vfptr[3].__first_virtual_table_function__)(v14, &v24);
      v15 = --v4->m_collisionDetails.m_size;
      if ( (_DWORD)v15 != v5 )
      {
        v16 = 2i64;
        v17 = 16 * v15;
        v18 = (signed __int64)&v4->m_collisionDetails.m_data[v5];
        v19 = v17 - 16i64 * v5;
        do
        {
          v20 = *(_QWORD *)(v19 + v18);
          v18 += 8i64;
          *(_QWORD *)(v18 - 8) = v20;
          --v16;
        }
        while ( v16 );
      }
      v4->m_orderDirty.m_bool = 1;
    }
  }
}

// File Line: 286
// RVA: 0xD68C40
void __fastcall hkpCachingShapePhantom::updateShapeCollectionFilter(hkpCachingShapePhantom *this)
{
  int v1; // ebx
  hkpCachingShapePhantom *v2; // rsi
  __int128 *v3; // rdx
  __int128 v4; // xmm1
  __int64 v5; // rdi
  void **v6; // [rsp+30h] [rbp-88h]
  int v7; // [rsp+38h] [rbp-80h]
  __int128 v8; // [rsp+50h] [rbp-68h]
  __int128 v9; // [rsp+60h] [rbp-58h]
  __int128 v10; // [rsp+70h] [rbp-48h]
  __int128 v11; // [rsp+80h] [rbp-38h]
  __int128 v12; // [rsp+90h] [rbp-28h]
  __int128 v13; // [rsp+A0h] [rbp-18h]

  v1 = 0;
  v2 = this;
  v3 = (__int128 *)this->m_world->m_collisionInput;
  v8 = *v3;
  v9 = v3[1];
  v10 = v3[2];
  v11 = v3[3];
  v12 = v3[4];
  v4 = v3[5];
  v7 = 0x1FFFF;
  v6 = &hkpConstraintOwner::`vftable;
  v13 = v4;
  if ( this->m_collisionDetails.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, __int128 *, void ***))v2->m_collisionDetails.m_data[v5].m_agent->vfptr[4].__vecDelDtor)(
        v2->m_collisionDetails.m_data[v5].m_agent,
        &v2->m_collidable,
        v2->m_collisionDetails.m_data[v5].m_collidable,
        &v8,
        &v6);
      ++v1;
      ++v5;
    }
    while ( v1 < v2->m_collisionDetails.m_size );
  }
}

// File Line: 301
// RVA: 0xD68D20
void __fastcall hkpCachingShapePhantom::deallocateInternalArrays(hkpCachingShapePhantom *this)
{
  hkpCachingShapePhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  if ( !this->m_collisionDetails.m_size )
  {
    v2 = this->m_collisionDetails.m_capacityAndFlags;
    this->m_collisionDetails.m_size = 0;
    if ( v2 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_collisionDetails.m_data,
        16 * v2);
    v1->m_collisionDetails.m_data = 0i64;
    v1->m_collisionDetails.m_capacityAndFlags = 2147483648;
  }
  hkpShapePhantom::deallocateInternalArrays((hkpShapePhantom *)&v1->vfptr);
}

// File Line: 330
// RVA: 0xD68770
void __fastcall hkpCachingShapePhantom::ensureDeterministicOrder(hkpCachingShapePhantom *this)
{
  hkpCachingShapePhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  if ( this->m_orderDirty.m_bool )
  {
    v2 = this->m_collisionDetails.m_size;
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkpCachingShapePhantom::CollisionDetail,hkpCachingShapePhantom::OrderByUid>(
        this->m_collisionDetails.m_data,
        0,
        v2 - 1,
        0);
    v1->m_orderDirty.m_bool = 0;
  }
}

