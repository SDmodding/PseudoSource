// File Line: 19
// RVA: 0x131D270
float __fastcall hkpWorldRayCaster::addBroadPhaseHandle(hkpWorldRayCaster *this, hkpBroadPhaseHandle *broadPhaseHandle, int castIndex)
{
  hkpWorldRayCaster *v3; // rsi
  hkpCollidable *v4; // r14
  hkpShape *v5; // r15
  float *v6; // rdi
  hkpWorldRayCastInput *v7; // rbx
  __m128 *v8; // rcx
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  unsigned int v17; // eax
  char v19; // [rsp+50h] [rbp+18h]

  v3 = this;
  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  v5 = v4->m_shape;
  v6 = (float *)((char *)this->m_collectorBase + castIndex * this->m_collectorStriding);
  if ( !v4->m_shape )
    return v6[2];
  v7 = &this->m_input[castIndex];
  if ( *(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(this->m_filter, (hkBool *)&v19, v7, v4) )
  {
    v8 = (__m128 *)v4->m_motion;
    v9 = v8[2];
    v10 = _mm_sub_ps(v3->m_input->m_from.m_quad, v8[3]);
    v11 = _mm_unpacklo_ps(*v8, v8[1]);
    v12 = _mm_movelh_ps(v11, v9);
    v3->m_shapeInput.m_from.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v10, v10, 85),
                                           _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v9, 212)),
                                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(_mm_unpackhi_ps(*v8, v8[1]), v9, 228),
                                         _mm_shuffle_ps(v10, v10, 170)));
    v13 = v8[2];
    v14 = _mm_unpacklo_ps(*v8, v8[1]);
    v15 = _mm_sub_ps(v7->m_to.m_quad, v8[3]);
    v16 = _mm_movelh_ps(v14, v13);
    v3->m_shapeInput.m_to.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v15, v15, 85),
                                         _mm_shuffle_ps(_mm_movehl_ps(v16, v14), v13, 212)),
                                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v16)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(_mm_unpackhi_ps(*v8, v8[1]), v13, 228),
                                       _mm_shuffle_ps(v15, v15, 170)));
    v17 = v7->m_filterInfo;
    v3->m_shapeInput.m_collidable = v4;
    v3->m_shapeInput.m_filterInfo = v17;
    v3->m_shapeInput.m_userData = v7->m_userData;
    ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpCollidable *, float *))v5->vfptr[3].__vecDelDtor)(
      v5,
      &v3->m_shapeInput,
      v4,
      v6);
  }
  return v6[2];
}

// File Line: 47
// RVA: 0x131CDE0
void __fastcall hkpWorldRayCaster::castRay(hkpWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *input, hkpCollisionFilter *filter, const char *cache, hkpRayHitCollector *collector)
{
  hkpWorldRayCaster *v6; // rbx
  hkpCollisionFilter *v7; // rdi
  hkpWorldRayCastInput *v8; // rsi
  hkpBroadPhase *v9; // r14
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  signed __int64 v15; // rcx
  signed __int64 v16; // rax
  __int128 v17; // xmm0
  hkBaseObjectVtbl *v18; // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  __int128 v23; // [rsp+20h] [rbp-38h]
  int v24; // [rsp+30h] [rbp-28h]
  hkVector4f *v25; // [rsp+38h] [rbp-20h]
  int v26; // [rsp+40h] [rbp-18h]
  const char *v27; // [rsp+48h] [rbp-10h]

  v6 = this;
  v7 = filter;
  v8 = input;
  v9 = broadphase;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtRayCstCached";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v6->m_input = v8;
  v15 = (signed __int64)&v7->vfptr;
  v6->m_collectorBase = collector;
  v16 = 0i64;
  v6->m_collectorStriding = 0;
  if ( !v7 )
    v15 = 0i64;
  v6->m_filter = (hkpRayCollidableFilter *)v15;
  if ( v8->m_enableShapeCollectionFilter.m_bool && v7 )
    v16 = (signed __int64)&v7->vfptr;
  v6->m_shapeInput.m_rayShapeCollectionFilter = (hkpRayShapeCollectionFilter *)v16;
  v17 = (__int128)v8->m_from;
  v25 = &v8->m_to;
  v23 = v17;
  v27 = cache;
  v18 = v9->vfptr;
  v24 = 1;
  v26 = 16;
  ((void (__fastcall *)(hkpBroadPhase *, __int128 *, hkpWorldRayCaster *, _QWORD, _QWORD, _QWORD, _QWORD, hkVector4f *, _QWORD, const char *))v18[12].__first_virtual_table_function__)(
    v9,
    &v23,
    v6,
    0i64,
    v17,
    *((_QWORD *)&v17 + 1),
    *(_QWORD *)&v24,
    &v8->m_to,
    *(_QWORD *)&v26,
    cache);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v19[1] = v22;
  }
}

// File Line: 76
// RVA: 0x131CF10
void __fastcall hkpWorldRayCaster::castRayGroup(hkpWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *inputArray, int numRays, hkpCollisionFilter *filter, hkpRayHitCollector *collectorBase, int collectorStriding)
{
  hkpBroadPhase *v7; // r14
  int v8; // ebp
  hkpWorldRayCastInput *v9; // rdi
  _QWORD *v10; // rax
  unsigned __int64 v11; // rdx
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  int v16; // ecx
  __m128 *v17; // rax
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  int v22; // er15
  hkLifoAllocator *v23; // rax
  char *cache; // rbx
  int v25; // er15
  char *v26; // rcx
  int v27; // ebp
  hkpRayHitCollector *collector; // rsi
  hkLifoAllocator *v29; // rax
  int v30; // er8
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  __m128 v36; // [rsp+30h] [rbp-58h]
  __m128 v37; // [rsp+40h] [rbp-48h]
  hkpWorldRayCaster *v38; // [rsp+90h] [rbp+8h]

  v38 = this;
  v7 = broadphase;
  v8 = numRays;
  v9 = inputArray;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v10[1];
  v13 = v10;
  if ( (unsigned __int64)v12 < v10[3] )
  {
    *v12 = "TtRayCastGroup";
    v14 = __rdtsc();
    v11 = (unsigned __int64)HIDWORD(v14) << 32;
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v16 = v8 - 2;
  v17 = &v9[1].m_from.m_quad;
  v18 = _mm_max_ps(v9->m_from.m_quad, v9->m_to.m_quad);
  v19 = _mm_min_ps(v9->m_from.m_quad, v9->m_to.m_quad);
  v37 = v18;
  v36 = v19;
  if ( v8 - 2 >= 0 )
  {
    do
    {
      --v16;
      v20 = _mm_min_ps(v19, v17[1]);
      v21 = _mm_max_ps(v18, v17[1]);
      v17 += 3;
      v19 = _mm_min_ps(v20, v17[-3]);
      v18 = _mm_max_ps(v21, v17[-3]);
    }
    while ( v16 >= 0 );
    v37 = v18;
    v36 = v19;
  }
  v22 = ((__int64 (__fastcall *)(hkpBroadPhase *, unsigned __int64, _QWORD *))v7->vfptr[13].__vecDelDtor)(v7, v11, v13);
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  cache = (char *)v23->m_cur;
  v25 = (v22 + 127) & 0xFFFFFF80;
  v26 = &cache[v25];
  if ( v25 > v23->m_slabSize || v26 > v23->m_end )
    cache = (char *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
  else
    v23->m_cur = v26;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, char *))v7->vfptr[14].__vecDelDtor)(v7, &v36, cache);
  v27 = v8 - 1;
  for ( collector = collectorBase; v27 >= 0; --v27 )
  {
    hkpWorldRayCaster::castRay(v38, v7, v9, filter, cache, collector);
    ++v9;
    collector = (hkpRayHitCollector *)((char *)collector + collectorStriding);
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
    v35 = (signed __int64)(v32 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v33[1] = v35;
  }
}

// File Line: 117
// RVA: 0x131D140
void __fastcall hkpWorldRayCaster::castRaysFromSinglePoint(hkpWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *inputArray, int numRays, hkpCollisionFilter *filter, const char *cache, hkpRayHitCollector *collectorBase, int collectorStriding)
{
  hkpWorldRayCaster *v8; // rbx
  int v9; // ebp
  hkpWorldRayCastInput *v10; // rdi
  hkpBroadPhase *v11; // rsi
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  hkpRayShapeCollectionFilter *v17; // rcx
  hkpRayCollidableFilter *v18; // rax
  __int128 v19; // xmm0
  hkBaseObjectVtbl *v20; // rax
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  __int128 v25; // [rsp+20h] [rbp-38h]
  int v26; // [rsp+30h] [rbp-28h]
  hkVector4f *v27; // [rsp+38h] [rbp-20h]
  int v28; // [rsp+40h] [rbp-18h]
  const char *v29; // [rsp+48h] [rbp-10h]

  v8 = this;
  v9 = numRays;
  v10 = inputArray;
  v11 = broadphase;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "TtRayCastFSP";
    v15 = __rdtsc();
    v16 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v14[1] = v16;
  }
  v17 = 0i64;
  v8->m_input = v10;
  v18 = (hkpRayCollidableFilter *)&filter->vfptr;
  if ( !filter )
    v18 = 0i64;
  v8->m_filter = v18;
  v8->m_collectorBase = collectorBase;
  v8->m_collectorStriding = collectorStriding;
  if ( v10->m_enableShapeCollectionFilter.m_bool && filter )
    v17 = (hkpRayShapeCollectionFilter *)&filter->vfptr;
  v8->m_shapeInput.m_rayShapeCollectionFilter = v17;
  v19 = (__int128)v10->m_from;
  v27 = &v10->m_to;
  v25 = v19;
  v29 = cache;
  v20 = v11->vfptr;
  v28 = 48;
  v26 = v9;
  ((void (__fastcall *)(hkpBroadPhase *, __int128 *, hkpWorldRayCaster *, _QWORD, _QWORD, _QWORD, _QWORD, hkVector4f *, _QWORD, const char *))v20[12].__first_virtual_table_function__)(
    v11,
    &v25,
    v8,
    0i64,
    v19,
    *((_QWORD *)&v19 + 1),
    *(_QWORD *)&v26,
    &v10->m_to,
    *(_QWORD *)&v28,
    cache);
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v21[1] = v24;
  }
}

