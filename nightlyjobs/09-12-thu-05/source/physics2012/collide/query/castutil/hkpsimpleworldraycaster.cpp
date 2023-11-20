// File Line: 19
// RVA: 0x131CC30
float __fastcall hkpSimpleWorldRayCaster::addBroadPhaseHandle(hkpSimpleWorldRayCaster *this, hkpBroadPhaseHandle *broadPhaseHandle, int castIndex)
{
  hkpSimpleWorldRayCaster *v3; // rsi
  hkpCollidable *v4; // rdi
  hkpShape *v5; // r15
  hkpWorldRayCastOutput *v6; // rbx
  signed __int64 v7; // r14
  hkpWorldRayCastInput *v8; // rdx
  __m128 *v9; // rbp
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  unsigned int v18; // eax
  _BYTE *v19; // rax
  float result; // xmm0_4
  __m128 v21; // xmm2
  char v22; // [rsp+50h] [rbp+18h]

  v3 = this;
  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  v5 = v4->m_shape;
  v6 = &this->m_result[castIndex];
  if ( !v4->m_shape )
    return v6->m_hitFraction;
  v7 = castIndex;
  if ( !*(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(
                    this->m_filter,
                    (hkBool *)&v22,
                    &this->m_input[castIndex],
                    v4) )
    return v6->m_hitFraction;
  v8 = v3->m_input;
  v9 = (__m128 *)v4->m_motion;
  v10 = v9[2];
  v11 = _mm_sub_ps(v8[v7].m_from.m_quad, v9[3]);
  v12 = _mm_unpacklo_ps(*v9, v9[1]);
  v13 = _mm_movelh_ps(v12, v10);
  v3->m_shapeInput.m_from.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v11, v11, 85),
                                         _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v10, 212)),
                                       _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v13)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v11, v11, 170),
                                       _mm_shuffle_ps(_mm_unpackhi_ps(*v9, v9[1]), v10, 228)));
  v14 = v9[2];
  v15 = _mm_unpacklo_ps(*v9, v9[1]);
  v16 = _mm_sub_ps(v8[v7].m_to.m_quad, v9[3]);
  v17 = _mm_movelh_ps(v15, v14);
  v3->m_shapeInput.m_to.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v16, v16, 85),
                                       _mm_shuffle_ps(_mm_movehl_ps(v17, v15), v14, 212)),
                                     _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v17)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(_mm_unpackhi_ps(*v9, v9[1]), v14, 228),
                                     _mm_shuffle_ps(v16, v16, 170)));
  v18 = v8[v7].m_filterInfo;
  v3->m_shapeInput.m_collidable = v4;
  v3->m_shapeInput.m_filterInfo = v18;
  v3->m_shapeInput.m_userData = v8[v7].m_userData;
  v19 = (_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpWorldRayCastOutput *))v5->vfptr[2].__first_virtual_table_function__)(
                   v5,
                   &v22,
                   &v3->m_shapeInput,
                   v6);
  result = v6->m_hitFraction;
  if ( *v19 )
  {
    v21 = v6->m_normal.m_quad;
    v6->m_rootCollidable = v4;
    v6->m_normal.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v9[1]),
                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), *v9)),
                            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v9[2]));
  }
  return result;
}

// File Line: 48
// RVA: 0x131C690
void __fastcall hkpSimpleWorldRayCaster::castRay(hkpSimpleWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *input, hkpCollisionFilter *filter, hkpWorldRayCastOutput *output)
{
  hkpSimpleWorldRayCaster *v5; // rbx
  hkpCollisionFilter *v6; // rdi
  hkpWorldRayCastInput *v7; // rsi
  hkpBroadPhase *v8; // r14
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  signed __int64 v14; // rax
  __int128 v15; // xmm0
  hkBaseObjectVtbl *v16; // rax
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  __int128 v21; // [rsp+20h] [rbp-38h]
  int v22; // [rsp+30h] [rbp-28h]
  hkVector4f *v23; // [rsp+38h] [rbp-20h]
  int v24; // [rsp+40h] [rbp-18h]
  __int64 v25; // [rsp+48h] [rbp-10h]

  v5 = this;
  v6 = filter;
  v7 = input;
  v8 = broadphase;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtRayCastSimpl";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v5->m_input = v7;
  v5->m_result = output;
  v14 = (signed __int64)&v6->vfptr;
  if ( !v6 )
    v14 = 0i64;
  v5->m_filter = (hkpRayCollidableFilter *)v14;
  if ( v7->m_enableShapeCollectionFilter.m_bool )
  {
    if ( v6 )
      v5->m_shapeInput.m_rayShapeCollectionFilter = (hkpRayShapeCollectionFilter *)&v6->vfptr;
    else
      v5->m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  }
  else
  {
    v5->m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  }
  v15 = (__int128)v7->m_from;
  v25 = 0i64;
  v23 = &v7->m_to;
  v16 = v8->vfptr;
  v21 = v15;
  v22 = 1;
  v24 = 16;
  ((void (__fastcall *)(hkpBroadPhase *, __int128 *, hkpSimpleWorldRayCaster *, _QWORD, _QWORD, _QWORD, _QWORD, hkVector4f *, _QWORD, _QWORD))v16[12].__first_virtual_table_function__)(
    v8,
    &v21,
    v5,
    0i64,
    v15,
    *((_QWORD *)&v15 + 1),
    *(_QWORD *)&v22,
    &v7->m_to,
    *(_QWORD *)&v24,
    0i64);
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v19 = __rdtsc();
    v20 = (signed __int64)(v18 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v17[1] = v20;
  }
}

// File Line: 75
// RVA: 0x131C9D0
void __fastcall hkpSimpleWorldRayCaster::castRay(hkpSimpleWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *input, hkpCollisionFilter *filter, const char *cache, hkpWorldRayCastOutput *output)
{
  hkpSimpleWorldRayCaster *v6; // rbx
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
    *v11 = "TtRayCstCchSim";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v6->m_input = v8;
  v15 = (signed __int64)&v7->vfptr;
  v6->m_result = output;
  v16 = 0i64;
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
  ((void (__fastcall *)(hkpBroadPhase *, __int128 *, hkpSimpleWorldRayCaster *, _QWORD, _QWORD, _QWORD, _QWORD, hkVector4f *, _QWORD, const char *))v18[12].__first_virtual_table_function__)(
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

// File Line: 102
// RVA: 0x131C7C0
void __fastcall hkpSimpleWorldRayCaster::castRayGroup(hkpSimpleWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *inputArray, int numRays, hkpCollisionFilter *filter, hkpWorldRayCastOutput *outputs)
{
  hkpSimpleWorldRayCaster *v6; // r13
  int v7; // ebp
  hkpWorldRayCastInput *v8; // rdi
  hkpBroadPhase *v9; // r14
  unsigned __int64 v10; // rdx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  int v15; // ecx
  __m128 *v16; // rax
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  int v21; // er15
  hkLifoAllocator *v22; // rax
  char *cache; // rbx
  int v24; // er15
  char *v25; // rcx
  int v26; // ebp
  hkpWorldRayCastOutput *output; // rsi
  hkLifoAllocator *v28; // rax
  int v29; // er8
  _QWORD *v30; // rax
  _QWORD *v31; // rcx
  _QWORD *v32; // r8
  unsigned __int64 v33; // rax
  signed __int64 v34; // rcx
  __m128 v35; // [rsp+30h] [rbp-48h]
  __m128 v36; // [rsp+40h] [rbp-38h]

  v6 = this;
  v7 = numRays;
  v8 = inputArray;
  v9 = broadphase;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtRayCstGrpSim";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v11[1] = v14;
  }
  v15 = v7 - 2;
  v16 = &v8[1].m_from.m_quad;
  v17 = _mm_max_ps(v8->m_from.m_quad, v8->m_to.m_quad);
  v18 = _mm_min_ps(v8->m_from.m_quad, v8->m_to.m_quad);
  v36 = v17;
  v35 = v18;
  if ( v7 - 2 >= 0 )
  {
    do
    {
      --v15;
      v19 = _mm_min_ps(v18, v16[1]);
      v20 = _mm_max_ps(v17, v16[1]);
      v16 += 3;
      v18 = _mm_min_ps(v19, v16[-3]);
      v17 = _mm_max_ps(v20, v16[-3]);
    }
    while ( v15 >= 0 );
    v36 = v17;
    v35 = v18;
  }
  v21 = ((__int64 (__fastcall *)(hkpBroadPhase *, unsigned __int64, LPVOID))v9->vfptr[13].__vecDelDtor)(v9, v10, v11);
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  cache = (char *)v22->m_cur;
  v24 = (v21 + 127) & 0xFFFFFF80;
  v25 = &cache[v24];
  if ( v24 > v22->m_slabSize || v25 > v22->m_end )
    cache = (char *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
  else
    v22->m_cur = v25;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, char *))v9->vfptr[14].__vecDelDtor)(v9, &v35, cache);
  v26 = v7 - 1;
  for ( output = outputs; v26 >= 0; --v26 )
  {
    hkpSimpleWorldRayCaster::castRay(v6, v9, v8, filter, cache, output);
    ++v8;
    ++output;
  }
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v28->m_slabSize || &cache[v29] != v28->m_cur || v28->m_firstNonLifoEnd == cache )
    hkLifoAllocator::slowBlockFree(v28, cache, v29);
  else
    v28->m_cur = cache;
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  v32 = v30;
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "Et";
    v33 = __rdtsc();
    v34 = (signed __int64)(v31 + 2);
    *(_DWORD *)(v34 - 8) = v33;
    v32[1] = v34;
  }
}

// File Line: 144
// RVA: 0x131CB00
void __fastcall hkpSimpleWorldRayCaster::castRaysFromSinglePoint(hkpSimpleWorldRayCaster *this, hkpBroadPhase *broadphase, hkpWorldRayCastInput *inputArray, int numRays, hkpCollisionFilter *filter, const char *cache, hkpWorldRayCastOutput *outputs)
{
  hkpSimpleWorldRayCaster *v7; // rbx
  int v8; // ebp
  hkpWorldRayCastInput *v9; // rdi
  hkpBroadPhase *v10; // rsi
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkpRayShapeCollectionFilter *v16; // rax
  hkpRayCollidableFilter *v17; // rdx
  __int128 v18; // xmm0
  hkBaseObjectVtbl *v19; // rax
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  __int128 v24; // [rsp+20h] [rbp-38h]
  int v25; // [rsp+30h] [rbp-28h]
  hkVector4f *v26; // [rsp+38h] [rbp-20h]
  int v27; // [rsp+40h] [rbp-18h]
  const char *v28; // [rsp+48h] [rbp-10h]

  v7 = this;
  v8 = numRays;
  v9 = inputArray;
  v10 = broadphase;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtRayCstFSPSim";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v7->m_input = v9;
  v7->m_result = outputs;
  v16 = 0i64;
  v17 = (hkpRayCollidableFilter *)&filter->vfptr;
  if ( !filter )
    v17 = 0i64;
  v7->m_filter = v17;
  if ( v9->m_enableShapeCollectionFilter.m_bool && filter )
    v16 = (hkpRayShapeCollectionFilter *)&filter->vfptr;
  v7->m_shapeInput.m_rayShapeCollectionFilter = v16;
  v18 = (__int128)v9->m_from;
  v26 = &v9->m_to;
  v24 = v18;
  v28 = cache;
  v19 = v10->vfptr;
  v27 = 48;
  v25 = v8;
  ((void (__fastcall *)(hkpBroadPhase *, __int128 *, hkpSimpleWorldRayCaster *, _QWORD, _QWORD, _QWORD, _QWORD, hkVector4f *, _QWORD, const char *))v19[12].__first_virtual_table_function__)(
    v10,
    &v24,
    v7,
    0i64,
    v18,
    *((_QWORD *)&v18 + 1),
    *(_QWORD *)&v25,
    &v9->m_to,
    *(_QWORD *)&v27,
    cache);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
}

