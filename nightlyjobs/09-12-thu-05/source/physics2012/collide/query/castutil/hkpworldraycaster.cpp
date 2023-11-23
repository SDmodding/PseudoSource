// File Line: 19
// RVA: 0x131D270
float __fastcall hkpWorldRayCaster::addBroadPhaseHandle(
        hkpWorldRayCaster *this,
        hkpBroadPhaseHandle *broadPhaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // r14
  hkpShape *m_shape; // r15
  float *v6; // rdi
  hkpWorldRayCastInput *v7; // rbx
  __m128 *m_motion; // rcx
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  unsigned int m_filterInfo; // eax
  char v19; // [rsp+50h] [rbp+18h] BYREF

  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  m_shape = v4->m_shape;
  v6 = (float *)((char *)this->m_collectorBase + castIndex * this->m_collectorStriding);
  if ( !v4->m_shape )
    return v6[2];
  v7 = &this->m_input[castIndex];
  if ( this->m_filter->vfptr->isCollisionEnabled(this->m_filter, &v19, v7, v4)->m_bool )
  {
    m_motion = (__m128 *)v4->m_motion;
    v9 = m_motion[2];
    v10 = _mm_sub_ps(this->m_input->m_from.m_quad, m_motion[3]);
    v11 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
    v12 = _mm_movelh_ps(v11, v9);
    this->m_shapeInput.m_from.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v10, v10, 85),
                                             _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v9, 212)),
                                           _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12)),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v9, 228),
                                           _mm_shuffle_ps(v10, v10, 170)));
    v13 = m_motion[2];
    v14 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
    v15 = _mm_sub_ps(v7->m_to.m_quad, m_motion[3]);
    v16 = _mm_movelh_ps(v14, v13);
    this->m_shapeInput.m_to.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v15, v15, 85),
                                           _mm_shuffle_ps(_mm_movehl_ps(v16, v14), v13, 212)),
                                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v16)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v13, 228),
                                         _mm_shuffle_ps(v15, v15, 170)));
    m_filterInfo = v7->m_filterInfo;
    this->m_shapeInput.m_collidable = v4;
    this->m_shapeInput.m_filterInfo = m_filterInfo;
    this->m_shapeInput.m_userData = v7->m_userData;
    ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpCollidable *, float *))m_shape->vfptr[3].__vecDelDtor)(
      m_shape,
      &this->m_shapeInput,
      v4,
      v6);
  }
  return v6[2];
}

// File Line: 47
// RVA: 0x131CDE0
void __fastcall hkpWorldRayCaster::castRay(
        hkpWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *input,
        hkpCollisionFilter *filter,
        const char *cache,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  hkpRayCollidableFilter *v15; // rcx
  hkpRayShapeCollectionFilter *v16; // rax
  hkVector4f v17; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  __m128 m_quad; // [rsp+20h] [rbp-38h] BYREF
  int v24; // [rsp+30h] [rbp-28h]
  hkVector4f *p_m_to; // [rsp+38h] [rbp-20h]
  int v26; // [rsp+40h] [rbp-18h]
  const char *v27; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtRayCstCached";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  this->m_input = input;
  v15 = &filter->hkpRayCollidableFilter;
  this->m_collectorBase = collector;
  v16 = 0i64;
  this->m_collectorStriding = 0;
  if ( !filter )
    v15 = 0i64;
  this->m_filter = v15;
  if ( input->m_enableShapeCollectionFilter.m_bool && filter )
    v16 = &filter->hkpRayShapeCollectionFilter;
  this->m_shapeInput.m_rayShapeCollectionFilter = v16;
  v17.m_quad = (__m128)input->m_from;
  p_m_to = &input->m_to;
  m_quad = v17.m_quad;
  v27 = cache;
  vfptr = broadphase->vfptr;
  v24 = 1;
  v26 = 16;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpWorldRayCaster *, _QWORD))vfptr[12].__first_virtual_table_function__)(
    broadphase,
    &m_quad,
    this,
    0i64);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v21 = __rdtsc();
    v22 = v20 + 2;
    *((_DWORD *)v22 - 2) = v21;
    v19[1] = v22;
  }
}

// File Line: 76
// RVA: 0x131CF10
void __fastcall hkpWorldRayCaster::castRayGroup(
        hkpWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *inputArray,
        int numRays,
        hkpCollisionFilter *filter,
        hkpRayHitCollector *collectorBase,
        int collectorStriding)
{
  _QWORD *Value; // rax
  unsigned __int64 v11; // rdx
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  int v16; // ecx
  hkpWorldRayCastInput *v17; // rax
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  int v22; // r15d
  hkLifoAllocator *v23; // rax
  char *cache; // rbx
  int v25; // r15d
  char *v26; // rcx
  int i; // ebp
  hkLifoAllocator *v29; // rax
  int v30; // r8d
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  __m128 v36; // [rsp+30h] [rbp-58h] BYREF
  __m128 v37; // [rsp+40h] [rbp-48h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtRayCastGroup";
    v14 = __rdtsc();
    v11 = (unsigned __int64)HIDWORD(v14) << 32;
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  v16 = numRays - 2;
  v17 = inputArray + 1;
  v18 = _mm_max_ps(inputArray->m_from.m_quad, inputArray->m_to.m_quad);
  v19 = _mm_min_ps(inputArray->m_from.m_quad, inputArray->m_to.m_quad);
  v37 = v18;
  v36 = v19;
  if ( numRays - 2 >= 0 )
  {
    do
    {
      --v16;
      v20 = _mm_min_ps(v19, v17->m_to.m_quad);
      v21 = _mm_max_ps(v18, v17->m_to.m_quad);
      ++v17;
      v19 = _mm_min_ps(v20, v17[-1].m_from.m_quad);
      v18 = _mm_max_ps(v21, v17[-1].m_from.m_quad);
    }
    while ( v16 >= 0 );
    v37 = v18;
    v36 = v19;
  }
  v22 = ((__int64 (__fastcall *)(hkpBroadPhase *, unsigned __int64, _QWORD *))broadphase->vfptr[13].__vecDelDtor)(
          broadphase,
          v11,
          v13);
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  cache = (char *)v23->m_cur;
  v25 = (v22 + 127) & 0xFFFFFF80;
  v26 = &cache[v25];
  if ( v25 > v23->m_slabSize || v26 > v23->m_end )
    cache = (char *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
  else
    v23->m_cur = v26;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, char *))broadphase->vfptr[14].__vecDelDtor)(broadphase, &v36, cache);
  for ( i = numRays - 1; i >= 0; --i )
  {
    hkpWorldRayCaster::castRay(this, broadphase, inputArray++, filter, cache, collectorBase);
    collectorBase = (hkpRayHitCollector *)((char *)collectorBase + collectorStriding);
  }
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v29->m_slabSize || &cache[v30] != v29->m_cur || v29->m_firstNonLifoEnd == cache )
    hkLifoAllocator::slowBlockFree(v29, cache, v30);
  else
    v29->m_cur = cache;
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = v32 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v33[1] = v35;
  }
}

// File Line: 117
// RVA: 0x131D140
void __fastcall hkpWorldRayCaster::castRaysFromSinglePoint(
        hkpWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *inputArray,
        int numRays,
        hkpCollisionFilter *filter,
        const char *cache,
        hkpRayHitCollector *collectorBase,
        int collectorStriding)
{
  _QWORD *Value; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  hkpRayShapeCollectionFilter *v17; // rcx
  hkpRayCollidableFilter *v18; // rax
  hkVector4f v19; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  __m128 m_quad; // [rsp+20h] [rbp-38h] BYREF
  int v26; // [rsp+30h] [rbp-28h]
  hkVector4f *p_m_to; // [rsp+38h] [rbp-20h]
  int v28; // [rsp+40h] [rbp-18h]
  const char *v29; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)Value[1];
  v14 = Value;
  if ( (unsigned __int64)v13 < Value[3] )
  {
    *v13 = "TtRayCastFSP";
    v15 = __rdtsc();
    v16 = v13 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v14[1] = v16;
  }
  v17 = 0i64;
  this->m_input = inputArray;
  v18 = &filter->hkpRayCollidableFilter;
  if ( !filter )
    v18 = 0i64;
  this->m_filter = v18;
  this->m_collectorBase = collectorBase;
  this->m_collectorStriding = collectorStriding;
  if ( inputArray->m_enableShapeCollectionFilter.m_bool && filter )
    v17 = &filter->hkpRayShapeCollectionFilter;
  this->m_shapeInput.m_rayShapeCollectionFilter = v17;
  v19.m_quad = (__m128)inputArray->m_from;
  p_m_to = &inputArray->m_to;
  m_quad = v19.m_quad;
  v29 = cache;
  vfptr = broadphase->vfptr;
  v28 = 48;
  v26 = numRays;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpWorldRayCaster *, _QWORD))vfptr[12].__first_virtual_table_function__)(
    broadphase,
    &m_quad,
    this,
    0i64);
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = v22 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v21[1] = v24;
  }
}

