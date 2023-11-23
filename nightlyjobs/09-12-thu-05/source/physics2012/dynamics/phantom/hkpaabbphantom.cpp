// File Line: 34
// RVA: 0xD665F0
void __fastcall hkpAabbPhantom::hkpAabbPhantom(hkpAabbPhantom *this, hkAabb *aabb, unsigned int collisionFilterInfo)
{
  hkpWorldObject::hkpWorldObject(this, 0i64, 2);
  this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  this->m_overlapListeners.m_data = 0i64;
  this->m_overlapListeners.m_size = 0;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->m_collidable.m_ownerOffset = -32;
  this->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable;
  this->m_overlappingCollidables.m_data = 0i64;
  this->m_overlappingCollidables.m_size = 0;
  this->m_overlappingCollidables.m_capacityAndFlags = 0x80000000;
  this->m_orderDirty.m_bool = 0;
  this->m_aabb = *aabb;
  this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = collisionFilterInfo;
}

// File Line: 42
// RVA: 0xD666B0
void __fastcall hkpAabbPhantom::~hkpAabbPhantom(hkpAabbPhantom *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpAabbPhantom::`vftable;
  m_capacityAndFlags = this->m_overlappingCollidables.m_capacityAndFlags;
  this->m_overlappingCollidables.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_overlappingCollidables.m_data,
      8 * m_capacityAndFlags);
  this->m_overlappingCollidables.m_data = 0i64;
  this->m_overlappingCollidables.m_capacityAndFlags = 0x80000000;
  hkpPhantom::~hkpPhantom(this);
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
  _QWORD **Value; // rax
  hkpAabbPhantom *v3; // rax
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
  v3 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 304i64);
  if ( v3 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v3, &this->m_aabb, this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo);
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

// File Line: 65
// RVA: 0xD66E00
void __fastcall hkpAabbPhantom::calcAabb(hkpAabbPhantom *this, hkAabb *aabb)
{
  *aabb = this->m_aabb;
}

// File Line: 70
// RVA: 0xD67190
void __fastcall hkpAabbPhantom::setAabb(hkpAabbPhantom *this, hkAabb *newAabb)
{
  this->m_aabb = *newAabb;
  hkpPhantom::updateBroadPhase(this, &this->m_aabb);
}

// File Line: 80
// RVA: 0xD66740
void __fastcall hkpAabbPhantom::castRay(
        hkpAabbPhantom *this,
        hkpWorldRayCastInput *input,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidable **m_data; // rbx
  int v13; // edi
  hkpShape *m_shape; // rcx
  __m128 *m_motion; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  hkVector4f v21; // xmm5
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  __int128 v30[2]; // [rsp+20h] [rbp-48h] BYREF
  unsigned int m_filterInfo; // [rsp+40h] [rbp-28h]
  hkpRayShapeCollectionFilter *v32; // [rsp+48h] [rbp-20h]
  hkpCollidable *v33; // [rsp+50h] [rbp-18h]
  unsigned __int64 i; // [rsp+58h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtrcPhantom";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_filterInfo = input->m_filterInfo;
  v32 = 0i64;
  v33 = 0i64;
  i = 0i64;
  if ( input->m_enableShapeCollectionFilter.m_bool && (m_collisionFilter = this->m_world->m_collisionFilter) != 0i64 )
    v32 = &m_collisionFilter->hkpRayShapeCollectionFilter;
  else
    v32 = 0i64;
  m_data = this->m_overlappingCollidables.m_data;
  v13 = this->m_overlappingCollidables.m_size - 1;
  for ( i = input->m_userData; v13 >= 0; --v13 )
  {
    m_shape = (*m_data)->m_shape;
    if ( m_shape )
    {
      m_motion = (__m128 *)(*m_data)->m_motion;
      v16 = _mm_sub_ps(input->m_from.m_quad, m_motion[3]);
      v17 = m_motion[2];
      v18 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
      v19 = _mm_movelh_ps(v18, v17);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v17, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v19)),
              _mm_mul_ps(
                _mm_shuffle_ps(v16, v16, 170),
                _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v17, 228)));
      v21.m_quad = (__m128)input->m_to;
      v30[0] = (__int128)v20;
      v22 = _mm_sub_ps(v21.m_quad, m_motion[3]);
      v23 = m_motion[2];
      v24 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
      v25 = _mm_movelh_ps(v24, v23);
      v30[1] = (__int128)_mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23, 212)),
                             _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v25)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v22, v22, 170),
                             _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v23, 228)));
      v33 = *m_data;
      ((void (__fastcall *)(hkpShape *, __int128 *, hkpCollidable *, hkpRayHitCollector *))m_shape->vfptr[3].__vecDelDtor)(
        m_shape,
        v30,
        *m_data,
        collector);
    }
    ++m_data;
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = v27 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v26[1] = v29;
  }
}

// File Line: 136
// RVA: 0xD66930
void __fastcall hkpAabbPhantom::castRay(
        hkpAabbPhantom *this,
        hkpWorldRayCastInput *input,
        hkpWorldRayCastOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidable **m_data; // rbx
  int v13; // edi
  hkpShape *m_shape; // rcx
  __m128 *m_motion; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  hkVector4f v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkpCollidable *m_rootCollidable; // rdx
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  __int128 v33[2]; // [rsp+20h] [rbp-48h] BYREF
  unsigned int m_filterInfo; // [rsp+40h] [rbp-28h]
  hkpRayShapeCollectionFilter *v35; // [rsp+48h] [rbp-20h]
  hkpCollidable *v36; // [rsp+50h] [rbp-18h]
  unsigned __int64 i; // [rsp+58h] [rbp-10h]
  char v38; // [rsp+70h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtrcPhantom";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_filterInfo = input->m_filterInfo;
  v35 = 0i64;
  v36 = 0i64;
  i = 0i64;
  if ( input->m_enableShapeCollectionFilter.m_bool && (m_collisionFilter = this->m_world->m_collisionFilter) != 0i64 )
    v35 = &m_collisionFilter->hkpRayShapeCollectionFilter;
  else
    v35 = 0i64;
  m_data = this->m_overlappingCollidables.m_data;
  v13 = this->m_overlappingCollidables.m_size - 1;
  for ( i = input->m_userData; v13 >= 0; --v13 )
  {
    m_shape = (*m_data)->m_shape;
    if ( m_shape )
    {
      m_motion = (__m128 *)(*m_data)->m_motion;
      v16 = _mm_sub_ps(input->m_from.m_quad, m_motion[3]);
      v17 = m_motion[2];
      v18 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
      v19 = _mm_movelh_ps(v18, v17);
      v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v17, 212));
      v21 = _mm_shuffle_ps(v16, v16, 0);
      v22 = _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v17, 228), _mm_shuffle_ps(v16, v16, 170));
      v23.m_quad = (__m128)input->m_to;
      v33[0] = (__int128)_mm_add_ps(_mm_add_ps(v20, _mm_mul_ps(v21, v19)), v22);
      v24 = _mm_sub_ps(v23.m_quad, m_motion[3]);
      v25 = m_motion[2];
      v26 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
      v27 = _mm_movelh_ps(v26, v25);
      v33[1] = (__int128)_mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(_mm_movehl_ps(v27, v26), v25, 212)),
                             _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v27)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v24, v24, 170),
                             _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v25, 228)));
      v36 = *m_data;
      ((void (__fastcall *)(hkpShape *, char *, __int128 *, hkpWorldRayCastOutput *))m_shape->vfptr[2].__first_virtual_table_function__)(
        m_shape,
        &v38,
        v33,
        output);
      if ( v38 )
        output->m_rootCollidable = *m_data;
    }
    ++m_data;
  }
  m_rootCollidable = output->m_rootCollidable;
  if ( m_rootCollidable )
    hkVector4f::setRotatedDir(&output->m_normal, (hkMatrix3f *)m_rootCollidable->m_motion, &output->m_normal);
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v31 = __rdtsc();
    v32 = v30 + 2;
    *((_DWORD *)v32 - 2) = v31;
    v29[1] = v32;
  }
}

// File Line: 201
// RVA: 0xD66B40
void __fastcall hkpAabbPhantom::linearCast(
        hkpAabbPhantom *this,
        hkpCollidable *const toBeCast,
        hkpLinearCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpWorld *m_world; // rdx
  float m_startPointTolerance; // xmm5_4
  __int64 v15; // rdi
  __m128 v16; // xmm2
  hkpProcessCollisionInput *m_collisionInput; // rcx
  __int64 m_config; // rax
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  hkpCollisionDispatcher *m_collisionDispatcher; // r15
  hkpCollisionFilter *m_collisionFilter; // r14
  hkpCdPointCollector *v24; // r12
  hkpCollidable *v25; // rbx
  hkBool *v26; // rax
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  hkpCollisionDispatcher *m_storage; // [rsp+30h] [rbp-B8h] BYREF
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
  float m_maxExtraPenetration; // [rsp+A0h] [rbp-48h]
  unsigned int v44; // [rsp+A4h] [rbp-44h]
  __int64 v45; // [rsp+A8h] [rbp-40h]
  char v46; // [rsp+F0h] [rbp+8h] BYREF
  __int64 m_size; // [rsp+F8h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TthkpAabbPhantom::linearCast";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_world = this->m_world;
  m_startPointTolerance = input->m_startPointTolerance;
  v15 = 0i64;
  v16 = _mm_sub_ps(input->m_to.m_quad, *((__m128 *)toBeCast->m_motion + 3));
  m_maxExtraPenetration = FLOAT_1_1920929eN7;
  v34 = 0;
  m_collisionInput = m_world->m_collisionInput;
  m_storage = m_collisionInput->m_dispatcher.m_storage;
  v33 = m_collisionInput->m_weldClosestPoints.m_storage;
  v34 = m_collisionInput->m_forceAcceptContactPoints.m_storage;
  v35 = m_collisionInput->m_tolerance.m_storage;
  v36 = m_collisionInput->m_filter.m_storage;
  v37 = m_collisionInput->m_convexListFilter.m_storage;
  v38 = m_collisionInput->m_createPredictiveAgents.m_storage;
  v39.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetLow;
  v40.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
  v41.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitScale;
  m_config = (__int64)m_collisionInput->m_config;
  v42 = v16;
  v35 = m_startPointTolerance;
  v45 = m_config;
  v19 = _mm_mul_ps(v16, v16);
  m_size = this->m_overlappingCollidables.m_size;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  m_maxExtraPenetration = input->m_maxExtraPenetration;
  v44 = _mm_andnot_ps(
          _mm_cmple_ps(v20, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(*(__m128 *)_xmm, v21)),
            v20)).m128_u32[0];
  m_collisionDispatcher = m_world->m_collisionDispatcher;
  m_collisionFilter = m_world->m_collisionFilter;
  if ( m_size > 0 )
  {
    v24 = startCollector;
    do
    {
      v25 = this->m_overlappingCollidables.m_data[v15];
      v26 = m_collisionFilter->hkpCollidableCollidableFilter::vfptr->isCollisionEnabled(
              &m_collisionFilter->hkpCollidableCollidableFilter,
              (hkBool *)&v46,
              toBeCast,
              v25);
      if ( v25->m_shape && v26->m_bool && v25 != toBeCast )
        m_collisionDispatcher->m_agent2Func[(unsigned __int8)m_collisionDispatcher->m_agent2Types[(unsigned __int8)toBeCast->m_shape->m_type.m_storage][(unsigned __int8)v25->m_shape->m_type.m_storage]].m_linearCastFunc(
          toBeCast,
          v25,
          (hkpLinearCastCollisionInput *)&m_storage,
          castCollector,
          v24);
      ++v15;
    }
    while ( v15 < m_size );
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  v29 = v27;
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v30 = __rdtsc();
    v31 = v28 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v29[1] = v31;
  }
}

// File Line: 242
// RVA: 0xD66EA0
hkBool *__fastcall hkpAabbPhantom::isOverlappingCollidableAdded(
        hkpAabbPhantom *this,
        hkBool *result,
        hkpCollidable *collidable)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  hkpCollidable **m_data; // rax

  m_size = this->m_overlappingCollidables.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    result->m_bool = 0;
    return result;
  }
  else
  {
    m_data = this->m_overlappingCollidables.m_data;
    while ( *m_data != collidable )
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

// File Line: 255
// RVA: 0xD66E20
void __fastcall hkpAabbPhantom::addOverlappingCollidable(hkpAabbPhantom *this, hkpCollidable *collidable)
{
  if ( hkpPhantom::fireCollidableAdded(this, collidable) == HK_COLLIDABLE_ACCEPT )
  {
    if ( this->m_overlappingCollidables.m_size == (this->m_overlappingCollidables.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_overlappingCollidables.m_data,
        8);
    this->m_overlappingCollidables.m_data[this->m_overlappingCollidables.m_size++] = collidable;
    this->m_orderDirty.m_bool = 1;
  }
}

// File Line: 270
// RVA: 0xD66EE0
void __fastcall hkpAabbPhantom::removeOverlappingCollidable(hkpAabbPhantom *this, hkpCollidable *collidable)
{
  int v3; // edi
  __int64 m_size; // r8
  __int64 v5; // rcx
  hkpCollidable **m_data; // rax
  int v7; // eax
  __int64 i; // rbx
  hkpPhantomOverlapListener *v9; // rcx
  __int64 v10; // rax
  __int64 v11[2]; // [rsp+20h] [rbp-28h] BYREF
  bool v12; // [rsp+30h] [rbp-18h]

  v3 = 0;
  m_size = this->m_overlappingCollidables.m_size;
  v5 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_overlappingCollidables.m_data;
    while ( *m_data != collidable )
    {
      ++v5;
      ++v3;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
  }
  v11[1] = (__int64)collidable;
  v11[0] = (__int64)this;
  v12 = v3 >= 0;
  v7 = this->m_overlapListeners.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = this->m_overlapListeners.m_data[i];
    if ( v9 )
      v9->vfptr->collidableRemovedCallback(v9, (hkpCollidableRemovedEvent *)v11);
  }
  if ( v3 >= 0 )
  {
    v10 = --this->m_overlappingCollidables.m_size;
    if ( (_DWORD)v10 != v3 )
      this->m_overlappingCollidables.m_data[v3] = this->m_overlappingCollidables.m_data[v10];
    this->m_orderDirty.m_bool = 1;
  }
}

// File Line: 287
// RVA: 0xD671C0
void __fastcall hkpAabbPhantom::deallocateInternalArrays(hkpAabbPhantom *this)
{
  int m_capacityAndFlags; // r8d

  if ( !this->m_overlappingCollidables.m_size )
  {
    m_capacityAndFlags = this->m_overlappingCollidables.m_capacityAndFlags;
    this->m_overlappingCollidables.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_overlappingCollidables.m_data,
        8 * m_capacityAndFlags);
    this->m_overlappingCollidables.m_data = 0i64;
    this->m_overlappingCollidables.m_capacityAndFlags = 0x80000000;
  }
  hkpPhantom::deallocateInternalArrays(this);
}

// File Line: 316
// RVA: 0xD67240
void __fastcall hkpAabbPhantom::ensureDeterministicOrder(hkpAabbPhantom *this)
{
  int m_size; // r8d

  if ( this->m_orderDirty.m_bool )
  {
    m_size = this->m_overlappingCollidables.m_size;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpCollidable *,hkpAabbPhantom::OrderByUid>(
        this->m_overlappingCollidables.m_data,
        0,
        m_size - 1,
        0);
    this->m_orderDirty.m_bool = 0;
  }
}

