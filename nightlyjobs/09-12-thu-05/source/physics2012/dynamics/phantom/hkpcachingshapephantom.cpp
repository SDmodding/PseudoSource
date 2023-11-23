// File Line: 32
// RVA: 0xD68160
void __fastcall hkpCachingShapePhantom::hkpCachingShapePhantom(
        hkpCachingShapePhantom *this,
        hkpShape *shape,
        hkTransformf *transform,
        unsigned int collisionFilterInfo)
{
  hkpShapePhantom::hkpShapePhantom(this, shape, transform);
  this->vfptr = (hkBaseObjectVtbl *)&hkpCachingShapePhantom::`vftable;
  this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  this->m_collisionDetails.m_data = 0i64;
  this->m_collisionDetails.m_size = 0;
  this->m_orderDirty.m_bool = 0;
  this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = collisionFilterInfo;
}

// File Line: 37
// RVA: 0xD681C0
void __fastcall hkpCachingShapePhantom::~hkpCachingShapePhantom(hkpCachingShapePhantom *this)
{
  int v2; // eax
  __int64 v3; // rdi
  __int64 v4; // rbx
  int m_capacityAndFlags; // r8d
  void **v6; // [rsp+20h] [rbp-28h] BYREF
  int v7; // [rsp+28h] [rbp-20h]

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
      ((void (__fastcall *)(hkpCollisionAgent *, void ***))this->m_collisionDetails.m_data[v4].m_agent->vfptr[3].__first_virtual_table_function__)(
        this->m_collisionDetails.m_data[v4].m_agent,
        &v6);
      --v3;
      --v4;
    }
    while ( v3 >= 0 );
  }
  this->m_collisionDetails.m_size = 0;
  m_capacityAndFlags = this->m_collisionDetails.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_collisionDetails.m_data,
      16 * m_capacityAndFlags);
  this->m_collisionDetails.m_data = 0i64;
  this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  hkpPhantom::~hkpPhantom(this);
}

// File Line: 51
// RVA: 0xD68500
hkpPhantom *__fastcall hkpCachingShapePhantom::clone(hkpCachingShapePhantom *this)
{
  _QWORD **Value; // rax
  hkpCachingShapePhantom *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rbx
  __int64 m_size; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  __int64 v15; // rax
  int v17; // [rsp+30h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpCachingShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 448i64);
  if ( v3 )
  {
    hkpCachingShapePhantom::hkpCachingShapePhantom(
      v3,
      this->m_collidable.m_shape,
      &this->m_motionState.m_transform,
      this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  if ( (*(_DWORD *)(v5 + 212) & 0x3FFFFFFF) < this->m_overlapListeners.m_size )
  {
    if ( *(int *)(v5 + 212) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v5 + 200),
        8 * *(_DWORD *)(v5 + 212));
    v17 = 8 * this->m_overlapListeners.m_size;
    *(_QWORD *)(v5 + 200) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v17);
    *(_DWORD *)(v5 + 212) = v17 / 8;
  }
  m_size = this->m_overlapListeners.m_size;
  v7 = *(_QWORD *)(v5 + 200);
  *(_DWORD *)(v5 + 208) = m_size;
  v8 = m_size;
  if ( (int)m_size > 0 )
  {
    v9 = (char *)this->m_overlapListeners.m_data - v7;
    do
    {
      v10 = *(_QWORD *)&v9[v7];
      v7 += 8i64;
      *(_QWORD *)(v7 - 8) = v10;
      --v8;
    }
    while ( v8 );
  }
  if ( (*(_DWORD *)(v5 + 228) & 0x3FFFFFFF) < this->m_phantomListeners.m_size )
  {
    if ( *(int *)(v5 + 228) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v5 + 216),
        8 * *(_DWORD *)(v5 + 228));
    v17 = 8 * this->m_phantomListeners.m_size;
    *(_QWORD *)(v5 + 216) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v17);
    *(_DWORD *)(v5 + 228) = v17 / 8;
  }
  v11 = this->m_phantomListeners.m_size;
  v12 = *(_QWORD *)(v5 + 216);
  *(_DWORD *)(v5 + 224) = v11;
  v13 = v11;
  if ( (int)v11 > 0 )
  {
    v14 = (char *)this->m_phantomListeners.m_data - v12;
    do
    {
      v15 = *(_QWORD *)&v14[v12];
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v15;
      --v13;
    }
    while ( v13 );
  }
  hkpWorldObject::copyProperties((hkpWorldObject *)v5, this);
  return (hkpPhantom *)v5;
}

// File Line: 110
// RVA: 0xD682A0
__int64 __fastcall hkpCachingShapePhantom::getType(hkpCachingShapePhantom *this)
{
  return 2i64;
}

// File Line: 116
// RVA: 0xD682B0
void __fastcall hkpCachingShapePhantom::setPositionAndLinearCast(
        hkpCachingShapePhantom *this,
        hkVector4f *position,
        hkpLinearCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  __m128 v9; // xmm7
  hkpWorld *m_world; // rax
  float m_startPointTolerance; // xmm5_4
  hkpProcessCollisionInput *m_collisionInput; // rcx
  __int64 m_config; // rax
  __m128 v14; // xmm7
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  float m_maxExtraPenetration; // xmm0_4
  int v18; // eax
  __int64 v19; // rdi
  __int64 v20; // rbx
  hkAabb aabb; // [rsp+28h] [rbp-71h] BYREF
  float m_storage; // [rsp+48h] [rbp-51h]
  hkpCollisionFilter *v23; // [rsp+50h] [rbp-49h]
  hkpConvexListFilter *v24; // [rsp+58h] [rbp-41h]
  unsigned int v25; // [rsp+60h] [rbp-39h]
  hkpCollisionInput::Aabb32Info m_aabb32Info; // [rsp+68h] [rbp-31h]
  __m128 v27; // [rsp+98h] [rbp-1h]
  float v28; // [rsp+A8h] [rbp+Fh]
  unsigned int v29; // [rsp+ACh] [rbp+13h]
  __int64 v30; // [rsp+B0h] [rbp+17h]
  __int64 v31; // [rsp+118h] [rbp+7Fh]

  this->m_motionState.m_transform.m_translation = (hkVector4f)position->m_quad;
  ((void (__fastcall *)(hkpShape *, hkMotionState *, hkpLinearCastInput *, unsigned __int16 *))this->m_collidable.m_shape->hkpShapePhantom::hkpPhantom::hkpWorldObject::vfptr[2].__vecDelDtor)(
    this->m_collidable.m_shape,
    &this->m_motionState,
    input,
    &aabb.m_min.m_quad.m128_u16[4]);
  v9 = _mm_sub_ps(input->m_to.m_quad, position->m_quad);
  *(__m128 *)((char *)&aabb.m_min.m_quad + 8) = _mm_add_ps(
                                                  *(__m128 *)((char *)&aabb.m_min.m_quad + 8),
                                                  _mm_min_ps((__m128)0i64, v9));
  aabb.m_min.m_quad = _mm_add_ps(aabb.m_min.m_quad, _mm_max_ps((__m128)0i64, v9));
  hkpPhantom::updateBroadPhase(this, (hkAabb *)&aabb.m_min.m_quad.m128_u16[4]);
  m_world = this->m_world;
  m_startPointTolerance = input->m_startPointTolerance;
  v28 = FLOAT_1_1920929eN7;
  m_collisionInput = m_world->m_collisionInput;
  aabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)m_collisionInput->m_dispatcher.m_storage;
  aabb.m_max.m_quad.m128_u64[1] = m_collisionInput->m_weldClosestPoints.m_storage;
  aabb.m_max.m_quad.m128_i32[3] = m_collisionInput->m_forceAcceptContactPoints.m_storage;
  m_storage = m_collisionInput->m_tolerance.m_storage;
  v23 = m_collisionInput->m_filter.m_storage;
  v24 = m_collisionInput->m_convexListFilter.m_storage;
  v25 = m_collisionInput->m_createPredictiveAgents.m_storage;
  m_aabb32Info = m_collisionInput->m_aabb32Info;
  m_config = (__int64)m_collisionInput->m_config;
  v27 = v9;
  v30 = m_config;
  v14 = _mm_mul_ps(v9, v9);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  m_maxExtraPenetration = input->m_maxExtraPenetration;
  v18 = this->m_collisionDetails.m_size - 1;
  m_storage = m_startPointTolerance;
  v28 = m_maxExtraPenetration;
  v19 = v18;
  v29 = _mm_andnot_ps(
          _mm_cmple_ps(v15, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)),
            v15)).m128_u32[0];
  if ( v18 >= 0 )
  {
    v20 = v18;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkVector4f *, hkpCdPointCollector *, __int64))this->m_collisionDetails.m_data[v20].m_agent->vfptr[2].__first_virtual_table_function__)(
        this->m_collisionDetails.m_data[v20].m_agent,
        &this->m_collidable,
        this->m_collisionDetails.m_data[v20].m_collidable,
        &aabb.m_max,
        castCollector,
        v31);
      --v19;
      --v20;
    }
    while ( v19 >= 0 );
  }
}

// File Line: 167
// RVA: 0xD684D0
void __fastcall hkpCachingShapePhantom::setTransformAndLinearCast(
        hkpCachingShapePhantom *this,
        hkTransformf *transform,
        hkpLinearCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  hkVector4f v5; // xmm0
  hkVector4f *p_m_translation; // rdx

  v5.m_quad = (__m128)transform->m_rotation.m_col0;
  p_m_translation = &transform->m_translation;
  this->m_motionState.m_transform.m_rotation.m_col0 = (hkVector4f)v5.m_quad;
  this->m_motionState.m_transform.m_rotation.m_col1 = (hkVector4f)p_m_translation[-2].m_quad;
  this->m_motionState.m_transform.m_rotation.m_col2 = (hkVector4f)p_m_translation[-1].m_quad;
  hkpCachingShapePhantom::setPositionAndLinearCast(this, p_m_translation, input, castCollector, startCollector);
}

// File Line: 177
// RVA: 0xD686D0
void __fastcall hkpCachingShapePhantom::getClosestPoints(
        hkpCachingShapePhantom *this,
        hkpCdPointCollector *collector,
        hkpProcessCollisionInput *input)
{
  hkpProcessCollisionInput *m_collisionInput; // rbp
  int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rdi

  m_collisionInput = input;
  if ( !input )
    m_collisionInput = this->m_world->m_collisionInput;
  v6 = this->m_collisionDetails.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = v6;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkpProcessCollisionInput *, hkpCdPointCollector *))this->m_collisionDetails.m_data[v8].m_agent->vfptr[2].__vecDelDtor)(
        this->m_collisionDetails.m_data[v8].m_agent,
        &this->m_collidable,
        this->m_collisionDetails.m_data[v8].m_collidable,
        m_collisionInput,
        collector);
      --v7;
      --v8;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 193
// RVA: 0xD687C0
void __fastcall hkpCachingShapePhantom::getPenetrations(
        hkpCachingShapePhantom *this,
        hkpCdBodyPairCollector *collector,
        hkpProcessCollisionInput *input)
{
  hkpProcessCollisionInput *m_collisionInput; // rbp
  int v6; // eax
  __int64 v7; // rbx
  __int64 v8; // rdi

  m_collisionInput = input;
  if ( !input )
    m_collisionInput = this->m_world->m_collisionInput;
  v6 = this->m_collisionDetails.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = v6;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, hkpProcessCollisionInput *, hkpCdBodyPairCollector *))this->m_collisionDetails.m_data[v8].m_agent->vfptr[1].__first_virtual_table_function__)(
        this->m_collisionDetails.m_data[v8].m_agent,
        &this->m_collidable,
        this->m_collisionDetails.m_data[v8].m_collidable,
        m_collisionInput,
        collector);
      if ( collector->m_earlyOut.m_bool )
        break;
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 216
// RVA: 0xD68BF0
hkBool *__fastcall hkpCachingShapePhantom::isOverlappingCollidableAdded(
        hkpCachingShapePhantom *this,
        hkBool *result,
        hkpCollidable *collidable)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  hkpCollidable **p_m_collidable; // rax

  m_size = this->m_collisionDetails.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    result->m_bool = 0;
    return result;
  }
  else
  {
    p_m_collidable = &this->m_collisionDetails.m_data->m_collidable;
    while ( *p_m_collidable != collidable )
    {
      ++v4;
      p_m_collidable += 2;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
    result->m_bool = 1;
    return result;
  }
}

// File Line: 232
// RVA: 0xD68870
void __fastcall hkpCachingShapePhantom::addOverlappingCollidable(
        hkpCachingShapePhantom *this,
        hkpCollidable *collidable)
{
  hkpCachingShapePhantom::CollisionDetail *v4; // rbx
  hkpProcessCollisionInput *m_collisionInput; // rdx
  __int128 m_bitScale; // xmm1
  __int64 m_config; // rcx
  hkpShape *m_shape; // rdx
  __int64 v9; // rax
  bool v10; // zf
  _QWORD **Value; // rax
  __int128 v12; // [rsp+20h] [rbp-49h] BYREF
  __int128 v13; // [rsp+30h] [rbp-39h]
  __int128 v14; // [rsp+40h] [rbp-29h]
  hkVector4f v15; // [rsp+50h] [rbp-19h]
  hkVector4f v16; // [rsp+60h] [rbp-9h]
  __int128 v17; // [rsp+70h] [rbp+7h]
  hkStepInfo m_stepInfo; // [rsp+80h] [rbp+17h]
  hkpCollisionQualityInfo *m_storage; // [rsp+90h] [rbp+27h]
  __int64 v20; // [rsp+98h] [rbp+2Fh]
  void *m_dynamicsInfo; // [rsp+A0h] [rbp+37h]
  char m_bool; // [rsp+A8h] [rbp+3Fh]
  char v23; // [rsp+A9h] [rbp+40h]
  __int64 v24; // [rsp+B0h] [rbp+47h]

  if ( collidable->m_shape && !(unsigned int)hkpPhantom::fireCollidableAdded(this, collidable) )
  {
    if ( this->m_collisionDetails.m_size == (this->m_collisionDetails.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_collisionDetails.m_data, 16);
    v4 = &this->m_collisionDetails.m_data[this->m_collisionDetails.m_size++];
    m_collisionInput = this->m_world->m_collisionInput;
    v12 = *(_OWORD *)&m_collisionInput->m_dispatcher.m_storage;
    v13 = *(_OWORD *)&m_collisionInput->m_tolerance.m_storage;
    v14 = *(_OWORD *)&m_collisionInput->m_convexListFilter.m_storage;
    v15.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetLow;
    v16.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
    m_bitScale = (__int128)m_collisionInput->m_aabb32Info.m_bitScale;
    v20 = 0i64;
    v17 = m_bitScale;
    v12 = *(_OWORD *)&m_collisionInput->m_dispatcher.m_storage;
    *(float *)&v13 = m_collisionInput->m_tolerance.m_storage;
    *((_QWORD *)&v13 + 1) = m_collisionInput->m_filter.m_storage;
    *(_QWORD *)&v14 = m_collisionInput->m_convexListFilter.m_storage;
    DWORD2(v14) = m_collisionInput->m_createPredictiveAgents.m_storage;
    v15.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetLow;
    v16.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
    v17 = (__int128)m_collisionInput->m_aabb32Info.m_bitScale;
    m_stepInfo = m_collisionInput->m_stepInfo;
    m_storage = m_collisionInput->m_collisionQualityInfo.m_storage;
    m_dynamicsInfo = m_collisionInput->m_dynamicsInfo;
    m_bool = m_collisionInput->m_enableDeprecatedWelding.m_bool;
    v23 = m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
    m_config = (__int64)m_collisionInput->m_config;
    m_shape = this->m_collidable.m_shape;
    v24 = m_config;
    DWORD2(v14) = 0;
    m_storage = (hkpCollisionQualityInfo *)(v12 + 10368);
    v9 = (*(__int64 (__fastcall **)(hkpLinkedCollidable *, hkpCollidable *, __int128 *, _QWORD))(v12
                                                                                               + 40i64
                                                                                               * *(unsigned __int8 *)((unsigned __int8)collidable->m_shape->m_type.m_storage + v12 + 35i64 * (unsigned __int8)m_shape->m_type.m_storage + 688)
                                                                                               + 3144))(
           &this->m_collidable,
           collidable,
           &v12,
           0i64);
    v4->m_collidable = collidable;
    v4->m_agent = (hkpCollisionAgent *)v9;
    v10 = v20 == 0;
    this->m_orderDirty.m_bool = 1;
    if ( !v10 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*Value[11] + 16i64))(Value[11], v20, 512i64);
    }
  }
}

// File Line: 256
// RVA: 0xD68A70
void __fastcall hkpCachingShapePhantom::removeOverlappingCollidable(
        hkpCachingShapePhantom *this,
        hkpCollidable *collidable)
{
  bool v2; // zf
  int v5; // esi
  __int64 v6; // rdx
  hkpCollidable **p_m_collidable; // r8
  int m_size; // eax
  __int64 i; // rdi
  hkpPhantomOverlapListener *v10; // rcx
  int v11; // eax
  __int64 j; // rdi
  hkpPhantomOverlapListener *v13; // rcx
  hkpCollisionAgent *m_agent; // rcx
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // r8
  hkpCachingShapePhantom::CollisionDetail *v18; // rcx
  __int64 v19; // r8
  hkpCollidable *v20; // rax
  hkpCachingShapePhantom *v21; // [rsp+20h] [rbp-48h] BYREF
  hkpCollidable *v22; // [rsp+28h] [rbp-40h]
  char v23; // [rsp+30h] [rbp-38h]
  void **v24; // [rsp+38h] [rbp-30h] BYREF
  int v25; // [rsp+40h] [rbp-28h]

  v2 = collidable->m_shape == 0i64;
  v25 = 0x1FFFF;
  v24 = &hkpConstraintOwner::`vftable;
  if ( !v2 )
  {
    v5 = this->m_collisionDetails.m_size - 1;
    v6 = v5;
    if ( v5 < 0 )
    {
LABEL_6:
      m_size = this->m_overlapListeners.m_size;
      v22 = collidable;
      v21 = this;
      --m_size;
      v23 = 0;
      for ( i = m_size; i >= 0; --i )
      {
        v10 = this->m_overlapListeners.m_data[i];
        if ( v10 )
          v10->vfptr->collidableRemovedCallback(v10, (hkpCollidableRemovedEvent *)&v21);
      }
    }
    else
    {
      p_m_collidable = &this->m_collisionDetails.m_data[v5].m_collidable;
      while ( *p_m_collidable != collidable )
      {
        --v5;
        p_m_collidable -= 2;
        if ( --v6 < 0 )
          goto LABEL_6;
      }
      v11 = this->m_overlapListeners.m_size;
      v22 = collidable;
      v21 = this;
      --v11;
      v23 = 1;
      for ( j = v11; j >= 0; --j )
      {
        v13 = this->m_overlapListeners.m_data[j];
        if ( v13 )
          v13->vfptr->collidableRemovedCallback(v13, (hkpCollidableRemovedEvent *)&v21);
      }
      m_agent = this->m_collisionDetails.m_data[v5].m_agent;
      if ( m_agent )
        ((void (__fastcall *)(hkpCollisionAgent *, void ***))m_agent->vfptr[3].__first_virtual_table_function__)(
          m_agent,
          &v24);
      v15 = --this->m_collisionDetails.m_size;
      if ( (_DWORD)v15 != v5 )
      {
        v16 = 2i64;
        v17 = 16 * v15;
        v18 = &this->m_collisionDetails.m_data[v5];
        v19 = v17 - 16i64 * v5;
        do
        {
          v20 = *(hkpCollidable **)((char *)&v18->m_agent + v19);
          v18 = (hkpCachingShapePhantom::CollisionDetail *)((char *)v18 + 8);
          v18[-1].m_collidable = v20;
          --v16;
        }
        while ( v16 );
      }
      this->m_orderDirty.m_bool = 1;
    }
  }
}

// File Line: 286
// RVA: 0xD68C40
void __fastcall hkpCachingShapePhantom::updateShapeCollectionFilter(hkpCachingShapePhantom *this)
{
  int v1; // ebx
  __int128 *m_collisionInput; // rdx
  __int128 v4; // xmm1
  __int64 v5; // rdi
  void **v6; // [rsp+30h] [rbp-88h] BYREF
  int v7; // [rsp+38h] [rbp-80h]
  __int128 v8[6]; // [rsp+50h] [rbp-68h] BYREF

  v1 = 0;
  m_collisionInput = (__int128 *)this->m_world->m_collisionInput;
  v8[0] = *m_collisionInput;
  v8[1] = m_collisionInput[1];
  v8[2] = m_collisionInput[2];
  v8[3] = m_collisionInput[3];
  v8[4] = m_collisionInput[4];
  v4 = m_collisionInput[5];
  v7 = 0x1FFFF;
  v6 = &hkpConstraintOwner::`vftable;
  v8[5] = v4;
  if ( this->m_collisionDetails.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpCollisionAgent *, hkpLinkedCollidable *, hkpCollidable *, __int128 *, void ***))this->m_collisionDetails.m_data[v5].m_agent->vfptr[4].__vecDelDtor)(
        this->m_collisionDetails.m_data[v5].m_agent,
        &this->m_collidable,
        this->m_collisionDetails.m_data[v5].m_collidable,
        v8,
        &v6);
      ++v1;
      ++v5;
    }
    while ( v1 < this->m_collisionDetails.m_size );
  }
}

// File Line: 301
// RVA: 0xD68D20
void __fastcall hkpCachingShapePhantom::deallocateInternalArrays(hkpCachingShapePhantom *this)
{
  int m_capacityAndFlags; // r8d

  if ( !this->m_collisionDetails.m_size )
  {
    m_capacityAndFlags = this->m_collisionDetails.m_capacityAndFlags;
    this->m_collisionDetails.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_collisionDetails.m_data,
        16 * m_capacityAndFlags);
    this->m_collisionDetails.m_data = 0i64;
    this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  }
  hkpShapePhantom::deallocateInternalArrays(this);
}

// File Line: 330
// RVA: 0xD68770
void __fastcall hkpCachingShapePhantom::ensureDeterministicOrder(hkpCachingShapePhantom *this)
{
  int m_size; // r8d

  if ( this->m_orderDirty.m_bool )
  {
    m_size = this->m_collisionDetails.m_size;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpCachingShapePhantom::CollisionDetail,hkpCachingShapePhantom::OrderByUid>(
        this->m_collisionDetails.m_data,
        0,
        m_size - 1,
        0);
    this->m_orderDirty.m_bool = 0;
  }
}

