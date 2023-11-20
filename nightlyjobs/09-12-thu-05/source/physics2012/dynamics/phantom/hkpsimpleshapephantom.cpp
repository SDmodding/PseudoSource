// File Line: 29
// RVA: 0xD67710
void __fastcall hkpSimpleShapePhantom::hkpSimpleShapePhantom(hkpSimpleShapePhantom *this, hkpShape *shape, hkTransformf *transform, unsigned int collisionFilterInfo)
{
  unsigned int v4; // edi
  hkpSimpleShapePhantom *v5; // rbx

  v4 = collisionFilterInfo;
  v5 = this;
  hkpShapePhantom::hkpShapePhantom((hkpShapePhantom *)&this->vfptr, shape, transform);
  v5->vfptr = (hkBaseObjectVtbl *)&hkpSimpleShapePhantom::`vftable;
  v5->m_collisionDetails.m_capacityAndFlags = 2147483648;
  v5->m_collisionDetails.m_data = 0i64;
  v5->m_collisionDetails.m_size = 0;
  v5->m_orderDirty.m_bool = 0;
  v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v4;
}

// File Line: 70
// RVA: 0xD67770
void __fastcall hkpSimpleShapePhantom::~hkpSimpleShapePhantom(hkpSimpleShapePhantom *this)
{
  hkpSimpleShapePhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleShapePhantom::`vftable;
  v2 = this->m_collisionDetails.m_capacityAndFlags;
  this->m_collisionDetails.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_collisionDetails.m_data,
      8 * v2);
  v1->m_collisionDetails.m_data = 0i64;
  v1->m_collisionDetails.m_capacityAndFlags = 2147483648;
  hkpPhantom::~hkpPhantom((hkpPhantom *)&v1->vfptr);
}

// File Line: 75
// RVA: 0xD677F0
signed __int64 __fastcall hkpSimpleShapePhantom::getType(hkpSimpleShapePhantom *this)
{
  return 1i64;
}

// File Line: 82
// RVA: 0xD67C20
hkpPhantom *__fastcall hkpSimpleShapePhantom::clone(hkpSimpleShapePhantom *this)
{
  hkpSimpleShapePhantom *v1; // rdi
  _QWORD **v2; // rax
  hkpSimpleShapePhantom *v3; // rax
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
  v3 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 448i64);
  if ( v3 )
  {
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(
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

// File Line: 97
// RVA: 0xD67800
void __fastcall hkpSimpleShapePhantom::setPositionAndLinearCast(hkpSimpleShapePhantom *this, hkVector4f *position, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkpSimpleShapePhantom *v5; // r15
  hkpCdPointCollector *v6; // r12
  hkVector4f *v7; // rbx
  __m128 *v8; // rdi
  float v9; // xmm2_4
  __m128 v10; // xmm7
  hkpWorld *v11; // rdx
  int v12; // xmm5_4
  hkpProcessCollisionInput *v13; // rcx
  __int64 v14; // rax
  __m128 v15; // xmm7
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  float v18; // xmm0_4
  __int64 v19; // rbx
  hkpCollisionDispatcher *i; // rdi
  hkpCollidable *v21; // rdx
  __m128 v22; // [rsp+28h] [rbp-71h]
  hkpCollisionDispatcher *v23; // [rsp+38h] [rbp-61h]
  __int64 v24; // [rsp+40h] [rbp-59h]
  int v25; // [rsp+48h] [rbp-51h]
  hkpCollisionFilter *v26; // [rsp+50h] [rbp-49h]
  hkpConvexListFilter *v27; // [rsp+58h] [rbp-41h]
  unsigned int v28; // [rsp+60h] [rbp-39h]
  hkVector4f v29; // [rsp+68h] [rbp-31h]
  hkVector4f v30; // [rsp+78h] [rbp-21h]
  hkVector4f v31; // [rsp+88h] [rbp-11h]
  __m128 v32; // [rsp+98h] [rbp-1h]
  float v33; // [rsp+A8h] [rbp+Fh]
  int v34; // [rsp+ACh] [rbp+13h]
  __int64 v35; // [rsp+B0h] [rbp+17h]
  hkpCdPointCollector *v36; // [rsp+118h] [rbp+7Fh]

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
    &v22.m128_u16[4]);
  v10 = _mm_sub_ps(*v8, v7->m_quad);
  *(__m128 *)((char *)&v22 + 8) = _mm_add_ps(*(__m128 *)((char *)&v22 + 8), _mm_min_ps((__m128)0i64, v10));
  v22 = _mm_add_ps(v22, _mm_max_ps((__m128)0i64, v10));
  hkpPhantom::updateBroadPhase((hkpPhantom *)&v5->vfptr, (hkAabb *)&v22.m128_u16[4]);
  v11 = v5->m_world;
  v12 = v8[1].m128_i32[1];
  v33 = FLOAT_1_1920929eN7;
  v13 = v11->m_collisionInput;
  v23 = v13->m_dispatcher.m_storage;
  v24 = v13->m_weldClosestPoints.m_storage;
  *(__int64 *)((char *)&v24 + 4) = *(_QWORD *)&v13->m_forceAcceptContactPoints.m_storage;
  v26 = v13->m_filter.m_storage;
  v27 = v13->m_convexListFilter.m_storage;
  v28 = v13->m_createPredictiveAgents.m_storage;
  v29.m_quad = (__m128)v13->m_aabb32Info.m_bitOffsetLow;
  v30.m_quad = (__m128)v13->m_aabb32Info.m_bitOffsetHigh;
  v31.m_quad = (__m128)v13->m_aabb32Info.m_bitScale;
  v14 = (__int64)v13->m_config;
  v32 = v10;
  v35 = v14;
  v15 = _mm_mul_ps(v10, v10);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = v8[1].m128_f32[0];
  LODWORD(v14) = v5->m_collisionDetails.m_size - 1;
  v25 = v12;
  v33 = v18;
  v19 = (signed int)v14;
  v34 = (unsigned __int128)_mm_andnot_ps(
                             _mm_cmpleps(v16, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v17)),
                               v16));
  for ( i = v11->m_collisionDispatcher; v19 >= 0; --v19 )
  {
    v21 = v5->m_collisionDetails.m_data[v19].m_collidable;
    i->m_agent2Func[(unsigned __int8)i->m_agent2Types[(unsigned __int8)v5->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)v21->m_shape->m_type.m_storage]].m_linearCastFunc(
      (hkpCdBody *)&v5->m_collidable.m_shape,
      (hkpCdBody *)&v21->m_shape,
      (hkpLinearCastCollisionInput *)&v23,
      v6,
      v36);
  }
}

// File Line: 152
// RVA: 0xD67A40
void __fastcall hkpSimpleShapePhantom::setTransformAndLinearCast(hkpSimpleShapePhantom *this, hkTransformf *transform, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkVector4f v5; // xmm0
  hkVector4f *v6; // rdx

  v5.m_quad = (__m128)transform->m_rotation.m_col0;
  v6 = &transform->m_translation;
  this->m_motionState.m_transform.m_rotation.m_col0 = (hkVector4f)v5.m_quad;
  this->m_motionState.m_transform.m_rotation.m_col1 = (hkVector4f)v6[-2].m_quad;
  this->m_motionState.m_transform.m_rotation.m_col2 = (hkVector4f)v6[-1].m_quad;
  hkpSimpleShapePhantom::setPositionAndLinearCast(this, v6, input, castCollector, startCollector);
}

// File Line: 163
// RVA: 0xD67A70
void __fastcall hkpSimpleShapePhantom::getClosestPoints(hkpSimpleShapePhantom *this, hkpCdPointCollector *collector, hkpCollisionInput *input)
{
  hkpProcessCollisionInput *v3; // rbx
  hkpCdPointCollector *v4; // rbp
  hkpSimpleShapePhantom *v5; // rdi
  hkpCollisionDispatcher *v6; // r15
  int v7; // eax
  __int64 i; // rsi
  hkpCollidable *v9; // rdx

  v3 = (hkpProcessCollisionInput *)input;
  v4 = collector;
  v5 = this;
  if ( !input )
    v3 = this->m_world->m_collisionInput;
  v6 = v3->m_dispatcher.m_storage;
  v7 = this->m_collisionDetails.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = v5->m_collisionDetails.m_data[i].m_collidable;
    (*((void (__fastcall **)(hkpLinkedCollidable *, hkpCollidable *, hkpProcessCollisionInput *, hkpCdPointCollector *))&v6->vfptr
     + 5
     * ((unsigned __int8)v6->m_agent2Types[(unsigned __int8)v5->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)v9->m_shape->m_type.m_storage]
      + 79i64)))(
      &v5->m_collidable,
      v9,
      v3,
      v4);
  }
}

// File Line: 182
// RVA: 0xD67B70
void __fastcall hkpSimpleShapePhantom::getPenetrations(hkpSimpleShapePhantom *this, hkpCdBodyPairCollector *collector, hkpCollisionInput *input)
{
  hkpProcessCollisionInput *v3; // rdi
  hkpCdBodyPairCollector *v4; // rbp
  hkpSimpleShapePhantom *v5; // rsi
  hkpCollisionDispatcher *v6; // r15
  int v7; // eax
  __int64 i; // rbx
  hkpCollidable *v9; // rdx

  v3 = (hkpProcessCollisionInput *)input;
  v4 = collector;
  v5 = this;
  if ( !input )
    v3 = this->m_world->m_collisionInput;
  v6 = v3->m_dispatcher.m_storage;
  v7 = this->m_collisionDetails.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = v5->m_collisionDetails.m_data[i].m_collidable;
    v6->m_agent2Func[(unsigned __int8)v6->m_agent2Types[(unsigned __int8)v5->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)v9->m_shape->m_type.m_storage]].m_getPenetrationsFunc(
      (hkpCdBody *)&v5->m_collidable.m_shape,
      (hkpCdBody *)&v9->m_shape,
      (hkpCollisionInput *)&v3->m_dispatcher,
      v4);
    if ( v4->m_earlyOut.m_bool )
      break;
  }
}

// File Line: 208
// RVA: 0xD67E70
hkBool *__fastcall hkpSimpleShapePhantom::isOverlappingCollidableAdded(hkpSimpleShapePhantom *this, hkBool *result, hkpCollidable *collidable)
{
  __int64 v3; // r10
  __int64 v4; // r9
  hkpSimpleShapePhantom::CollisionDetail *v5; // rax
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
    v5 = this->m_collisionDetails.m_data;
    while ( v5->m_collidable != collidable )
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

// File Line: 221
// RVA: 0xD67DF0
void __fastcall hkpSimpleShapePhantom::addOverlappingCollidable(hkpSimpleShapePhantom *this, hkpCollidable *collidable)
{
  hkpCollidable *v2; // rdi
  hkpSimpleShapePhantom *v3; // rsi
  __int64 v4; // r8
  hkpSimpleShapePhantom::CollisionDetail *v5; // rdx

  v2 = collidable;
  v3 = this;
  if ( collidable->m_shape && !(unsigned int)hkpPhantom::fireCollidableAdded((hkpPhantom *)&this->vfptr, collidable) )
  {
    if ( v3->m_collisionDetails.m_size == (v3->m_collisionDetails.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_collisionDetails,
        8);
    v4 = v3->m_collisionDetails.m_size;
    v5 = &v3->m_collisionDetails.m_data[v4];
    v3->m_collisionDetails.m_size = v4 + 1;
    v5->m_collidable = v2;
    v3->m_orderDirty.m_bool = 1;
  }
}

// File Line: 238
// RVA: 0xD67EB0
void __fastcall hkpSimpleShapePhantom::removeOverlappingCollidable(hkpSimpleShapePhantom *this, hkpCollidable *collidable)
{
  hkpCollidable *v2; // r8
  hkpSimpleShapePhantom *v3; // rdi
  int v4; // esi
  __int64 v5; // rcx
  hkpSimpleShapePhantom::CollisionDetail *v6; // rdx
  int v7; // eax
  __int64 i; // rbx
  hkpPhantomOverlapListener *v9; // rcx
  int v10; // eax
  __int64 j; // rbx
  hkpPhantomOverlapListener *v12; // rcx
  __int64 v13; // rax
  hkpSimpleShapePhantom *v14; // [rsp+20h] [rbp-28h]
  hkpCollidable *v15; // [rsp+28h] [rbp-20h]
  char v16; // [rsp+30h] [rbp-18h]

  v2 = collidable;
  v3 = this;
  if ( collidable->m_shape )
  {
    v4 = this->m_collisionDetails.m_size - 1;
    v5 = v4;
    if ( v4 < 0 )
    {
LABEL_6:
      v7 = v3->m_overlapListeners.m_size;
      v15 = v2;
      v14 = v3;
      --v7;
      v16 = 0;
      for ( i = v7; i >= 0; --i )
      {
        v9 = v3->m_overlapListeners.m_data[i];
        if ( v9 )
          v9->vfptr->collidableRemovedCallback(v9, (hkpCollidableRemovedEvent *)&v14);
      }
    }
    else
    {
      v6 = &v3->m_collisionDetails.m_data[v4];
      while ( v6->m_collidable != v2 )
      {
        --v4;
        --v6;
        if ( --v5 < 0 )
          goto LABEL_6;
      }
      v10 = v3->m_overlapListeners.m_size;
      v15 = v2;
      v14 = v3;
      --v10;
      v16 = 1;
      for ( j = v10; j >= 0; --j )
      {
        v12 = v3->m_overlapListeners.m_data[j];
        if ( v12 )
          v12->vfptr->collidableRemovedCallback(v12, (hkpCollidableRemovedEvent *)&v14);
      }
      v13 = --v3->m_collisionDetails.m_size;
      if ( (_DWORD)v13 != v4 )
        v3->m_collisionDetails.m_data[v4].m_collidable = v3->m_collisionDetails.m_data[v13].m_collidable;
      v3->m_orderDirty.m_bool = 1;
    }
  }
}

// File Line: 262
// RVA: 0xD67FD0
void __fastcall hkpSimpleShapePhantom::deallocateInternalArrays(hkpSimpleShapePhantom *this)
{
  hkpSimpleShapePhantom *v1; // rbx
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
        8 * v2);
    v1->m_collisionDetails.m_data = 0i64;
    v1->m_collisionDetails.m_capacityAndFlags = 2147483648;
  }
  hkpShapePhantom::deallocateInternalArrays((hkpShapePhantom *)&v1->vfptr);
}

// File Line: 290
// RVA: 0xD67B20
void __fastcall hkpSimpleShapePhantom::ensureDeterministicOrder(hkpSimpleShapePhantom *this)
{
  hkpSimpleShapePhantom *v1; // rbx
  int v2; // er8

  v1 = this;
  if ( this->m_orderDirty.m_bool )
  {
    v2 = this->m_collisionDetails.m_size;
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkpSimpleShapePhantom::CollisionDetail,hkpSimpleShapePhantom::OrderByUid>(
        this->m_collisionDetails.m_data,
        0,
        v2 - 1,
        0);
    v1->m_orderDirty.m_bool = 0;
  }
}

