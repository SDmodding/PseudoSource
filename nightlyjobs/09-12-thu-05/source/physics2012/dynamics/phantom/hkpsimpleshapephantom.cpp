// File Line: 29
// RVA: 0xD67710
void __fastcall hkpSimpleShapePhantom::hkpSimpleShapePhantom(
        hkpSimpleShapePhantom *this,
        hkpShape *shape,
        hkTransformf *transform,
        unsigned int collisionFilterInfo)
{
  hkpShapePhantom::hkpShapePhantom(this, shape, transform);
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleShapePhantom::`vftable;
  this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  this->m_collisionDetails.m_data = 0i64;
  this->m_collisionDetails.m_size = 0;
  this->m_orderDirty.m_bool = 0;
  this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = collisionFilterInfo;
}

// File Line: 70
// RVA: 0xD67770
void __fastcall hkpSimpleShapePhantom::~hkpSimpleShapePhantom(hkpSimpleShapePhantom *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleShapePhantom::`vftable;
  m_capacityAndFlags = this->m_collisionDetails.m_capacityAndFlags;
  this->m_collisionDetails.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_collisionDetails.m_data,
      8 * m_capacityAndFlags);
  this->m_collisionDetails.m_data = 0i64;
  this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  hkpPhantom::~hkpPhantom(this);
}

// File Line: 75
// RVA: 0xD677F0
__int64 __fastcall hkpSimpleShapePhantom::getType(hkpSimpleShapePhantom *this)
{
  return 1i64;
}

// File Line: 82
// RVA: 0xD67C20
hkpPhantom *__fastcall hkpSimpleShapePhantom::clone(hkpSimpleShapePhantom *this)
{
  _QWORD **Value; // rax
  hkpSimpleShapePhantom *v3; // rax
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
  v3 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 448i64);
  if ( v3 )
  {
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(
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

// File Line: 97
// RVA: 0xD67800
void __fastcall hkpSimpleShapePhantom::setPositionAndLinearCast(
        hkpSimpleShapePhantom *this,
        hkVector4f *position,
        hkpLinearCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  __m128 v9; // xmm7
  hkpWorld *m_world; // rdx
  float m_startPointTolerance; // xmm5_4
  hkpProcessCollisionInput *m_collisionInput; // rcx
  __int64 m_config; // rax
  __m128 v14; // xmm7
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  float m_maxExtraPenetration; // xmm0_4
  __int64 v18; // rbx
  hkpCollisionDispatcher *i; // rdi
  hkpCollidable *m_collidable; // rdx
  _BYTE v21[24]; // [rsp+28h] [rbp-71h] BYREF
  _BYTE aabb_16[12]; // [rsp+40h] [rbp-59h]
  hkpCollisionFilter *m_storage; // [rsp+50h] [rbp-49h]
  hkpConvexListFilter *v24; // [rsp+58h] [rbp-41h]
  unsigned int v25; // [rsp+60h] [rbp-39h]
  hkpCollisionInput::Aabb32Info m_aabb32Info; // [rsp+68h] [rbp-31h]
  __m128 v27; // [rsp+98h] [rbp-1h]
  float v28; // [rsp+A8h] [rbp+Fh]
  unsigned int v29; // [rsp+ACh] [rbp+13h]
  __int64 v30; // [rsp+B0h] [rbp+17h]
  hkpCdPointCollector *v31; // [rsp+118h] [rbp+7Fh]

  this->m_motionState.m_transform.m_translation = (hkVector4f)position->m_quad;
  ((void (__fastcall *)(hkpShape *, hkMotionState *, hkpLinearCastInput *, _BYTE *))this->m_collidable.m_shape->hkpShapePhantom::hkpPhantom::hkpWorldObject::vfptr[2].__vecDelDtor)(
    this->m_collidable.m_shape,
    &this->m_motionState,
    input,
    &v21[8]);
  v9 = _mm_sub_ps(input->m_to.m_quad, position->m_quad);
  *(__m128 *)&v21[8] = _mm_add_ps(*(__m128 *)&v21[8], _mm_min_ps((__m128)0i64, v9));
  *(__m128 *)v21 = _mm_add_ps(*(__m128 *)v21, _mm_max_ps((__m128)0i64, v9));
  hkpPhantom::updateBroadPhase(this, (hkAabb *)&v21[8]);
  m_world = this->m_world;
  m_startPointTolerance = input->m_startPointTolerance;
  v28 = FLOAT_1_1920929eN7;
  m_collisionInput = m_world->m_collisionInput;
  *(_QWORD *)&v21[16] = m_collisionInput->m_dispatcher.m_storage;
  *(_QWORD *)aabb_16 = m_collisionInput->m_weldClosestPoints.m_storage;
  *(_QWORD *)&aabb_16[4] = *(_QWORD *)&m_collisionInput->m_forceAcceptContactPoints.m_storage;
  m_storage = m_collisionInput->m_filter.m_storage;
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
  LODWORD(m_config) = this->m_collisionDetails.m_size - 1;
  *(float *)&aabb_16[8] = m_startPointTolerance;
  v28 = m_maxExtraPenetration;
  v18 = (int)m_config;
  v29 = _mm_andnot_ps(
          _mm_cmple_ps(v15, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)),
            v15)).m128_u32[0];
  for ( i = m_world->m_collisionDispatcher; v18 >= 0; --v18 )
  {
    m_collidable = this->m_collisionDetails.m_data[v18].m_collidable;
    i->m_agent2Func[(unsigned __int8)i->m_agent2Types[(unsigned __int8)this->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)m_collidable->m_shape->m_type.m_storage]].m_linearCastFunc(
      &this->m_collidable,
      m_collidable,
      (hkpLinearCastCollisionInput *)&v21[16],
      castCollector,
      v31);
  }
}

// File Line: 152
// RVA: 0xD67A40
void __fastcall hkpSimpleShapePhantom::setTransformAndLinearCast(
        hkpSimpleShapePhantom *this,
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
  hkpSimpleShapePhantom::setPositionAndLinearCast(this, p_m_translation, input, castCollector, startCollector);
}

// File Line: 163
// RVA: 0xD67A70
void __fastcall hkpSimpleShapePhantom::getClosestPoints(
        hkpSimpleShapePhantom *this,
        hkpCdPointCollector *collector,
        hkpProcessCollisionInput *input)
{
  hkpProcessCollisionInput *m_collisionInput; // rbx
  hkpCollisionDispatcher *m_storage; // r15
  int v7; // eax
  __int64 i; // rsi
  hkpCollidable *m_collidable; // rdx

  m_collisionInput = input;
  if ( !input )
    m_collisionInput = this->m_world->m_collisionInput;
  m_storage = m_collisionInput->m_dispatcher.m_storage;
  v7 = this->m_collisionDetails.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    m_collidable = this->m_collisionDetails.m_data[i].m_collidable;
    m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[(unsigned __int8)this->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)m_collidable->m_shape->m_type.m_storage]].m_getClosestPointFunc(
      &this->m_collidable,
      m_collidable,
      m_collisionInput,
      collector);
  }
}

// File Line: 182
// RVA: 0xD67B70
void __fastcall hkpSimpleShapePhantom::getPenetrations(
        hkpSimpleShapePhantom *this,
        hkpCdBodyPairCollector *collector,
        hkpProcessCollisionInput *input)
{
  hkpProcessCollisionInput *m_collisionInput; // rdi
  hkpCollisionDispatcher *m_storage; // r15
  int v7; // eax
  __int64 i; // rbx
  hkpCollidable *m_collidable; // rdx

  m_collisionInput = input;
  if ( !input )
    m_collisionInput = this->m_world->m_collisionInput;
  m_storage = m_collisionInput->m_dispatcher.m_storage;
  v7 = this->m_collisionDetails.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    m_collidable = this->m_collisionDetails.m_data[i].m_collidable;
    m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[(unsigned __int8)this->m_collidable.m_shape->m_type.m_storage][(unsigned __int8)m_collidable->m_shape->m_type.m_storage]].m_getPenetrationsFunc(
      &this->m_collidable,
      m_collidable,
      m_collisionInput,
      collector);
    if ( collector->m_earlyOut.m_bool )
      break;
  }
}

// File Line: 208
// RVA: 0xD67E70
hkBool *__fastcall hkpSimpleShapePhantom::isOverlappingCollidableAdded(
        hkpSimpleShapePhantom *this,
        hkBool *result,
        hkpCollidable *collidable)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  hkpSimpleShapePhantom::CollisionDetail *m_data; // rax

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
    m_data = this->m_collisionDetails.m_data;
    while ( m_data->m_collidable != collidable )
    {
      ++v4;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
    result->m_bool = 1;
    return result;
  }
}

// File Line: 221
// RVA: 0xD67DF0
void __fastcall hkpSimpleShapePhantom::addOverlappingCollidable(hkpSimpleShapePhantom *this, hkpCollidable *collidable)
{
  __int64 m_size; // r8
  hkpSimpleShapePhantom::CollisionDetail *v5; // rdx

  if ( collidable->m_shape && !(unsigned int)hkpPhantom::fireCollidableAdded(this, collidable) )
  {
    if ( this->m_collisionDetails.m_size == (this->m_collisionDetails.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_collisionDetails.m_data, 8);
    m_size = this->m_collisionDetails.m_size;
    v5 = &this->m_collisionDetails.m_data[m_size];
    this->m_collisionDetails.m_size = m_size + 1;
    v5->m_collidable = collidable;
    this->m_orderDirty.m_bool = 1;
  }
}

// File Line: 238
// RVA: 0xD67EB0
void __fastcall hkpSimpleShapePhantom::removeOverlappingCollidable(
        hkpSimpleShapePhantom *this,
        hkpCollidable *collidable)
{
  int v4; // esi
  __int64 v5; // rcx
  hkpSimpleShapePhantom::CollisionDetail *v6; // rdx
  int m_size; // eax
  __int64 i; // rbx
  hkpPhantomOverlapListener *v9; // rcx
  int v10; // eax
  __int64 j; // rbx
  hkpPhantomOverlapListener *v12; // rcx
  __int64 v13; // rax
  hkpSimpleShapePhantom *v14; // [rsp+20h] [rbp-28h] BYREF
  hkpCollidable *v15; // [rsp+28h] [rbp-20h]
  char v16; // [rsp+30h] [rbp-18h]

  if ( collidable->m_shape )
  {
    v4 = this->m_collisionDetails.m_size - 1;
    v5 = v4;
    if ( v4 < 0 )
    {
LABEL_6:
      m_size = this->m_overlapListeners.m_size;
      v15 = collidable;
      v14 = this;
      --m_size;
      v16 = 0;
      for ( i = m_size; i >= 0; --i )
      {
        v9 = this->m_overlapListeners.m_data[i];
        if ( v9 )
          v9->vfptr->collidableRemovedCallback(v9, (hkpCollidableRemovedEvent *)&v14);
      }
    }
    else
    {
      v6 = &this->m_collisionDetails.m_data[v4];
      while ( v6->m_collidable != collidable )
      {
        --v4;
        --v6;
        if ( --v5 < 0 )
          goto LABEL_6;
      }
      v10 = this->m_overlapListeners.m_size;
      v15 = collidable;
      v14 = this;
      --v10;
      v16 = 1;
      for ( j = v10; j >= 0; --j )
      {
        v12 = this->m_overlapListeners.m_data[j];
        if ( v12 )
          v12->vfptr->collidableRemovedCallback(v12, (hkpCollidableRemovedEvent *)&v14);
      }
      v13 = --this->m_collisionDetails.m_size;
      if ( (_DWORD)v13 != v4 )
        this->m_collisionDetails.m_data[v4].m_collidable = this->m_collisionDetails.m_data[v13].m_collidable;
      this->m_orderDirty.m_bool = 1;
    }
  }
}

// File Line: 262
// RVA: 0xD67FD0
void __fastcall hkpSimpleShapePhantom::deallocateInternalArrays(hkpSimpleShapePhantom *this)
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
        8 * m_capacityAndFlags);
    this->m_collisionDetails.m_data = 0i64;
    this->m_collisionDetails.m_capacityAndFlags = 0x80000000;
  }
  hkpShapePhantom::deallocateInternalArrays(this);
}

// File Line: 290
// RVA: 0xD67B20
void __fastcall hkpSimpleShapePhantom::ensureDeterministicOrder(hkpSimpleShapePhantom *this)
{
  int m_size; // r8d

  if ( this->m_orderDirty.m_bool )
  {
    m_size = this->m_collisionDetails.m_size;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpSimpleShapePhantom::CollisionDetail,hkpSimpleShapePhantom::OrderByUid>(
        this->m_collisionDetails.m_data,
        0,
        m_size - 1,
        0);
    this->m_orderDirty.m_bool = 0;
  }
}

