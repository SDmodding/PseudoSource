// File Line: 19
// RVA: 0x131CC30
float __fastcall hkpSimpleWorldRayCaster::addBroadPhaseHandle(
        hkpSimpleWorldRayCaster *this,
        hkpBroadPhaseHandle *broadPhaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // rdi
  hkpShape *m_shape; // r15
  hkpWorldRayCastOutput *v6; // rbx
  unsigned __int64 v7; // r14
  hkpWorldRayCastInput *m_input; // rdx
  __m128 *m_motion; // rbp
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  unsigned int m_filterInfo; // eax
  _BYTE *v19; // rax
  float result; // xmm0_4
  __m128 m_quad; // xmm2
  char v22; // [rsp+50h] [rbp+18h] BYREF

  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  m_shape = v4->m_shape;
  v6 = &this->m_result[castIndex];
  if ( !v4->m_shape )
    return v6->m_hitFraction;
  v7 = castIndex;
  if ( !this->m_filter->vfptr->isCollisionEnabled(this->m_filter, &v22, &this->m_input[v7], v4)->m_bool )
    return v6->m_hitFraction;
  m_input = this->m_input;
  m_motion = (__m128 *)v4->m_motion;
  v10 = m_motion[2];
  v11 = _mm_sub_ps(m_input[v7].m_from.m_quad, m_motion[3]);
  v12 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v13 = _mm_movelh_ps(v12, v10);
  this->m_shapeInput.m_from.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v11, v11, 85),
                                           _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v10, 212)),
                                         _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v13)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v11, v11, 170),
                                         _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v10, 228)));
  v14 = m_motion[2];
  v15 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v16 = _mm_sub_ps(m_input[v7].m_to.m_quad, m_motion[3]);
  v17 = _mm_movelh_ps(v15, v14);
  this->m_shapeInput.m_to.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v16, v16, 85),
                                         _mm_shuffle_ps(_mm_movehl_ps(v17, v15), v14, 212)),
                                       _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v17)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v14, 228),
                                       _mm_shuffle_ps(v16, v16, 170)));
  m_filterInfo = m_input[v7].m_filterInfo;
  this->m_shapeInput.m_collidable = v4;
  this->m_shapeInput.m_filterInfo = m_filterInfo;
  this->m_shapeInput.m_userData = m_input[v7].m_userData;
  v19 = (_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpWorldRayCastOutput *))m_shape->vfptr[2].__first_virtual_table_function__)(
                   m_shape,
                   &v22,
                   &this->m_shapeInput,
                   v6);
  result = v6->m_hitFraction;
  if ( *v19 )
  {
    m_quad = v6->m_normal.m_quad;
    v6->m_rootCollidable = v4;
    v6->m_normal.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), m_motion[1]),
                              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), *m_motion)),
                            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), m_motion[2]));
  }
  return result;
}

// File Line: 48
// RVA: 0x131C690
void __fastcall hkpSimpleWorldRayCaster::castRay(
        hkpSimpleWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *input,
        hkpCollisionFilter *filter,
        hkpWorldRayCastOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpRayCollidableFilter *v14; // rax
  hkVector4f v15; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  __m128 m_quad; // [rsp+20h] [rbp-38h] BYREF
  int v22; // [rsp+30h] [rbp-28h]
  hkVector4f *p_m_to; // [rsp+38h] [rbp-20h]
  int v24; // [rsp+40h] [rbp-18h]
  __int64 v25; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtRayCastSimpl";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  this->m_input = input;
  this->m_result = output;
  v14 = &filter->hkpRayCollidableFilter;
  if ( !filter )
    v14 = 0i64;
  this->m_filter = v14;
  if ( input->m_enableShapeCollectionFilter.m_bool )
  {
    if ( filter )
      this->m_shapeInput.m_rayShapeCollectionFilter = &filter->hkpRayShapeCollectionFilter;
    else
      this->m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  }
  else
  {
    this->m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  }
  v15.m_quad = (__m128)input->m_from;
  v25 = 0i64;
  p_m_to = &input->m_to;
  vfptr = broadphase->vfptr;
  m_quad = v15.m_quad;
  v22 = 1;
  v24 = 16;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpSimpleWorldRayCaster *, _QWORD))vfptr[12].__first_virtual_table_function__)(
    broadphase,
    &m_quad,
    this,
    0i64);
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v19 = __rdtsc();
    v20 = v18 + 2;
    *((_DWORD *)v20 - 2) = v19;
    v17[1] = v20;
  }
}

// File Line: 75
// RVA: 0x131C9D0
void __fastcall hkpSimpleWorldRayCaster::castRay(
        hkpSimpleWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *input,
        hkpCollisionFilter *filter,
        const char *cache,
        hkpWorldRayCastOutput *output)
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
    *v11 = "TtRayCstCchSim";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  this->m_input = input;
  v15 = &filter->hkpRayCollidableFilter;
  this->m_result = output;
  v16 = 0i64;
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
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpSimpleWorldRayCaster *, _QWORD))vfptr[12].__first_virtual_table_function__)(
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

// File Line: 102
// RVA: 0x131C7C0
void __fastcall hkpSimpleWorldRayCaster::castRayGroup(
        hkpSimpleWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *inputArray,
        int numRays,
        hkpCollisionFilter *filter,
        hkpWorldRayCastOutput *outputs)
{
  unsigned __int64 v10; // rdx
  _QWORD *Value; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // ecx
  hkpWorldRayCastInput *v16; // rax
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  int v21; // r15d
  hkLifoAllocator *v22; // rax
  char *cache; // rbx
  int v24; // r15d
  char *v25; // rcx
  int i; // ebp
  hkLifoAllocator *v28; // rax
  int v29; // r8d
  _QWORD *v30; // rax
  _QWORD *v31; // rcx
  _QWORD *v32; // r8
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  __m128 v35; // [rsp+30h] [rbp-48h] BYREF
  __m128 v36; // [rsp+40h] [rbp-38h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtRayCstGrpSim";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = v12 + 2;
    *((_DWORD *)v14 - 2) = v13;
    Value[1] = v14;
  }
  v15 = numRays - 2;
  v16 = inputArray + 1;
  v17 = _mm_max_ps(inputArray->m_from.m_quad, inputArray->m_to.m_quad);
  v18 = _mm_min_ps(inputArray->m_from.m_quad, inputArray->m_to.m_quad);
  v36 = v17;
  v35 = v18;
  if ( numRays - 2 >= 0 )
  {
    do
    {
      --v15;
      v19 = _mm_min_ps(v18, v16->m_to.m_quad);
      v20 = _mm_max_ps(v17, v16->m_to.m_quad);
      ++v16;
      v18 = _mm_min_ps(v19, v16[-1].m_from.m_quad);
      v17 = _mm_max_ps(v20, v16[-1].m_from.m_quad);
    }
    while ( v15 >= 0 );
    v36 = v17;
    v35 = v18;
  }
  v21 = ((__int64 (__fastcall *)(hkpBroadPhase *, unsigned __int64, _QWORD *))broadphase->vfptr[13].__vecDelDtor)(
          broadphase,
          v10,
          Value);
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  cache = (char *)v22->m_cur;
  v24 = (v21 + 127) & 0xFFFFFF80;
  v25 = &cache[v24];
  if ( v24 > v22->m_slabSize || v25 > v22->m_end )
    cache = (char *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
  else
    v22->m_cur = v25;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, char *))broadphase->vfptr[14].__vecDelDtor)(broadphase, &v35, cache);
  for ( i = numRays - 1; i >= 0; --i )
    hkpSimpleWorldRayCaster::castRay(this, broadphase, inputArray++, filter, cache, outputs++);
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
    v34 = v31 + 2;
    *((_DWORD *)v34 - 2) = v33;
    v32[1] = v34;
  }
}

// File Line: 144
// RVA: 0x131CB00
void __fastcall hkpSimpleWorldRayCaster::castRaysFromSinglePoint(
        hkpSimpleWorldRayCaster *this,
        hkpBroadPhase *broadphase,
        hkpWorldRayCastInput *inputArray,
        int numRays,
        hkpCollisionFilter *filter,
        const char *cache,
        hkpWorldRayCastOutput *outputs)
{
  _QWORD *Value; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkpRayShapeCollectionFilter *v16; // rax
  hkpRayCollidableFilter *v17; // rdx
  hkVector4f v18; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  __m128 m_quad; // [rsp+20h] [rbp-38h] BYREF
  int v25; // [rsp+30h] [rbp-28h]
  hkVector4f *p_m_to; // [rsp+38h] [rbp-20h]
  int v27; // [rsp+40h] [rbp-18h]
  const char *v28; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtRayCstFSPSim";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  this->m_input = inputArray;
  this->m_result = outputs;
  v16 = 0i64;
  v17 = &filter->hkpRayCollidableFilter;
  if ( !filter )
    v17 = 0i64;
  this->m_filter = v17;
  if ( inputArray->m_enableShapeCollectionFilter.m_bool && filter )
    v16 = &filter->hkpRayShapeCollectionFilter;
  this->m_shapeInput.m_rayShapeCollectionFilter = v16;
  v18.m_quad = (__m128)inputArray->m_from;
  p_m_to = &inputArray->m_to;
  m_quad = v18.m_quad;
  v28 = cache;
  vfptr = broadphase->vfptr;
  v27 = 48;
  v25 = numRays;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpSimpleWorldRayCaster *, _QWORD))vfptr[12].__first_virtual_table_function__)(
    broadphase,
    &m_quad,
    this,
    0i64);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
}

