// File Line: 25
// RVA: 0xBE91A0
void __fastcall hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
        hkaiDynamicNavMeshQueryMediator *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable;
}

// File Line: 33
// RVA: 0xBE91C0
void __fastcall hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
        hkaiDynamicNavMeshQueryMediator *this,
        hkaiStreamingCollection *collection,
        hkcdDynamicAabbTree *tree,
        hkaiNavMeshCutter *cutter)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable;
  if ( collection )
    hkReferencedObject::addReference(collection);
  this->m_collection.m_pntr = collection;
  if ( tree )
    hkReferencedObject::addReference(tree);
  this->m_aabbTree.m_pntr = tree;
  if ( cutter )
    hkReferencedObject::addReference(cutter);
  this->m_cutter.m_pntr = cutter;
  this->m_cutAabbTolerance = 0.050000001;
}

// File Line: 37
// RVA: 0xBE9250
void __fastcall hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(
        hkaiDynamicNavMeshQueryMediator *this)
{
  hkaiNavMeshCutter *m_pntr; // rcx
  hkcdDynamicAabbTree *v3; // rcx
  hkaiStreamingCollection *v4; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable;
  m_pntr = this->m_cutter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_cutter.m_pntr = 0i64;
  v3 = this->m_aabbTree.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_aabbTree.m_pntr = 0i64;
  v4 = this->m_collection.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_collection.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 55
// RVA: 0xBE9CE0
hkSimdFloat32 *__fastcall NavMeshClosestPointCollector::processLeaf(
        NavMeshClosestPointCollector *this,
        hkSimdFloat32 *result,
        int leafKey,
        hkAabb *leafAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut,
        hkSimdFloat32 *closestDistanceSquared)
{
  __int64 v9; // r9
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v11; // rcx
  __int64 v12; // r10
  hkSimdFloat32 *v13; // rax
  __int128 *m_gcpInput; // rax
  __m128 m_real; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __int128 v19; // xmm1
  __m128 m_quad; // xmm0
  hkaiNavMeshCutter *m_cutter; // rax
  unsigned int v22; // eax
  hkVector4f v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  hkSimdFloat32 v26; // xmm2
  __m128 v27; // [rsp+20h] [rbp-78h] BYREF
  __int128 v28; // [rsp+30h] [rbp-68h] BYREF
  __int128 v29; // [rsp+40h] [rbp-58h]
  __int128 v30; // [rsp+50h] [rbp-48h]
  __int128 v31; // [rsp+60h] [rbp-38h]
  __m128 v32; // [rsp+70h] [rbp-28h]
  hkaiNavMeshCutter *v33; // [rsp+80h] [rbp-18h]
  __int64 v34; // [rsp+88h] [rbp-10h]

  v9 = 3i64 * leafKey;
  m_data = this->m_collection->m_instances.m_data;
  v9 *= 2i64;
  v11 = *((_QWORD *)&m_data->m_instancePtr + v9);
  v12 = *((_QWORD *)&m_data->m_mediator + v9);
  if ( v11 )
  {
    m_gcpInput = (__int128 *)this->m_gcpInput;
    m_real = closestDistanceSquared->m_real;
    v16 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
    v17 = _mm_cmple_ps(closestDistanceSquared->m_real, (__m128)0i64);
    v18 = _mm_mul_ps(
            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v16), v16)),
            _mm_mul_ps(*(__m128 *)_xmm, v16));
    v28 = *m_gcpInput;
    v29 = m_gcpInput[1];
    v30 = m_gcpInput[2];
    v31 = m_gcpInput[3];
    v32 = (__m128)m_gcpInput[4];
    v19 = m_gcpInput[5];
    m_quad = queryPoint->m_quad;
    *((_QWORD *)&v29 + 1) = v11;
    *(_QWORD *)&v30 = v11 + 112;
    m_cutter = this->m_cutter;
    v34 = *((_QWORD *)&v19 + 1);
    v32 = _mm_andnot_ps(v17, _mm_mul_ps(v18, m_real));
    v27 = m_quad;
    v33 = m_cutter;
    v22 = (*(__int64 (__fastcall **)(__int64, __int128 *, __m128 *))(*(_QWORD *)v12 + 24i64))(v12, &v28, &v27);
    if ( v22 == -1 )
    {
      *result = (hkSimdFloat32)closestDistanceSquared->m_real;
    }
    else
    {
      v23.m_quad = v27;
      v24 = _mm_sub_ps(v27, queryPoint->m_quad);
      v25 = _mm_mul_ps(v24, v24);
      v26.m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                     _mm_shuffle_ps(v25, v25, 170));
      if ( v26.m_real.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
      {
        this->m_bestFaceKey = v22;
        *closestPointOut = (hkVector4f)v23.m_quad;
      }
      *result = (hkSimdFloat32)v26.m_real;
    }
    return result;
  }
  else
  {
    v13 = result;
    *result = (hkSimdFloat32)closestDistanceSquared->m_real;
  }
  return v13;
}

// File Line: 99
// RVA: 0xBE92C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::getClosestPoint(
        hkaiDynamicNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkaiNavMeshCutter *v12; // rax
  unsigned int v13; // ebx
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-38h] BYREF
  hkaiNavMeshQueryMediator::GetClosestPointInput *v21; // [rsp+38h] [rbp-30h]
  hkaiStreamingCollection *v22; // [rsp+40h] [rbp-28h]
  hkaiNavMeshCutter *v23; // [rsp+48h] [rbp-20h]
  unsigned int v24; // [rsp+50h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtDynMediator::GCP";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_pntr = this->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshClosestPointCollector::`vftable;
  v22 = this->m_collection.m_pntr;
  v12 = this->m_cutter.m_pntr;
  v21 = gcpInput;
  v24 = -1;
  v23 = v12;
  hkcdDynamicAabbTree::getClosestPoint(
    m_pntr,
    &gcpInput->m_position,
    &gcpInput->m_queryRadius,
    &collector,
    closestPointOut);
  v13 = v24;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = v15 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 127
// RVA: 0xBE9B70
hkSimdFloat32 *__fastcall NavMeshClosestBoundaryEdgeCollector::processLeaf(
        NavMeshClosestBoundaryEdgeCollector *this,
        hkSimdFloat32 *result,
        int leafKey,
        hkAabb *leafAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut,
        hkSimdFloat32 *closestDistanceSquared)
{
  __int64 v9; // r9
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v11; // rcx
  __int64 v12; // r10
  hkSimdFloat32 *v13; // rax
  __int128 *m_gcbInput; // rax
  __m128 m_real; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __int128 v19; // xmm0
  hkaiNavMeshCutter *m_cutter; // rax
  unsigned int v21; // eax
  hkVector4f v22; // xmm1
  __m128 v23; // xmm0
  __m128 m_quad; // [rsp+20h] [rbp-88h] BYREF
  __int128 v25; // [rsp+30h] [rbp-78h] BYREF
  __int128 v26; // [rsp+40h] [rbp-68h]
  __int128 v27; // [rsp+50h] [rbp-58h]
  __int128 v28; // [rsp+60h] [rbp-48h]
  __m128 v29; // [rsp+70h] [rbp-38h]
  __int128 v30; // [rsp+80h] [rbp-28h]
  __int128 v31; // [rsp+90h] [rbp-18h]

  v9 = 3i64 * leafKey;
  m_data = this->m_collection->m_instances.m_data;
  v9 *= 2i64;
  v11 = *((_QWORD *)&m_data->m_instancePtr + v9);
  v12 = *((_QWORD *)&m_data->m_mediator + v9);
  if ( v11 )
  {
    m_gcbInput = (__int128 *)this->m_gcbInput;
    m_real = closestDistanceSquared->m_real;
    v16 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
    v17 = _mm_cmple_ps(closestDistanceSquared->m_real, (__m128)0i64);
    v18 = _mm_mul_ps(
            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v16), v16)),
            _mm_mul_ps(*(__m128 *)_xmm, v16));
    v25 = *m_gcbInput;
    v26 = m_gcbInput[1];
    v27 = m_gcbInput[2];
    v28 = m_gcbInput[3];
    v29 = (__m128)m_gcbInput[4];
    v30 = m_gcbInput[5];
    v19 = m_gcbInput[6];
    v29 = _mm_andnot_ps(v17, _mm_mul_ps(v18, m_real));
    *((_QWORD *)&v26 + 1) = v11;
    *(_QWORD *)&v27 = v11 + 112;
    m_cutter = this->m_cutter;
    v31 = v19;
    *(_QWORD *)&v30 = m_cutter;
    m_quad = queryPoint->m_quad;
    v21 = (*(__int64 (__fastcall **)(__int64, __int128 *, __m128 *))(*(_QWORD *)v12 + 32i64))(v12, &v25, &m_quad);
    if ( v21 == -1 )
    {
      v23 = closestDistanceSquared->m_real;
    }
    else
    {
      v22.m_quad = m_quad;
      v23 = _mm_shuffle_ps(m_quad, m_quad, 255);
      if ( v23.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
      {
        this->m_bestFaceKey = v21;
        *closestPointOut = (hkVector4f)v22.m_quad;
      }
    }
    v13 = result;
    *result = (hkSimdFloat32)v23;
  }
  else
  {
    v13 = result;
    *result = (hkSimdFloat32)closestDistanceSquared->m_real;
  }
  return v13;
}

// File Line: 170
// RVA: 0xBE93C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::getClosestBoundaryEdge(
        hkaiDynamicNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *gcbInput,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkaiNavMeshCutter *v12; // rax
  unsigned int v13; // ebx
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-38h] BYREF
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v21; // [rsp+38h] [rbp-30h]
  hkaiStreamingCollection *v22; // [rsp+40h] [rbp-28h]
  hkaiNavMeshCutter *v23; // [rsp+48h] [rbp-20h]
  unsigned int v24; // [rsp+50h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtDynMediator::GCBoundary";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_pntr = this->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshClosestBoundaryEdgeCollector::`vftable;
  v22 = this->m_collection.m_pntr;
  v12 = this->m_cutter.m_pntr;
  v21 = gcbInput;
  v24 = -1;
  v23 = v12;
  hkcdDynamicAabbTree::getClosestPoint(
    m_pntr,
    &gcbInput->m_position,
    &gcbInput->m_queryRadius,
    &collector,
    closestPointOut);
  v13 = v24;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = v15 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 199
// RVA: 0xBE9EB0
__int64 __fastcall NavMeshSectionRaycaster::processLeaf(
        NavMeshSectionRaycaster *this,
        unsigned int leafKey,
        hkAabb *leafAabb,
        hkSimdFloat32 *hitFractionInOut)
{
  hkaiNavMeshInstance *m_instancePtr; // rdx

  m_instancePtr = this->m_collection->m_instances.m_data[leafKey].m_instancePtr;
  if ( m_instancePtr )
    return NavMeshSectionRaycaster::castRayAgainstMeshInstance(
             this,
             (hkaiNavMeshUtils *)m_instancePtr,
             hitFractionInOut);
  else
    return 0i64;
}

// File Line: 214
// RVA: 0xBE9920
__int64 __fastcall NavMeshSectionRaycaster::castRayAgainstMeshInstance(
        NavMeshSectionRaycaster *this,
        hkaiNavMeshUtils *meshInstance,
        hkSimdFloat32 *hitFractionInOut)
{
  hkaiNavMeshQueryMediator::RaycastInput *m_rayInput; // rax
  hkaiNavMeshQueryMediator *m_mediator; // rcx
  __int128 m_to; // xmm0
  unsigned int v9; // xmm0_4
  unsigned int v10; // edx
  hkaiNavMeshCutter *m_cutter; // r9
  unsigned int v12; // r12d
  int v13; // ebx
  __int64 v14; // rdi
  unsigned int v15; // r15d
  unsigned int v16; // ebx
  __int64 result; // rax
  hkSimdFloat32 v18; // xmm0
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+30h] [rbp-69h] BYREF
  hkSimdFloat32 *v20[2]; // [rsp+40h] [rbp-59h] BYREF
  __int128 v21; // [rsp+50h] [rbp-49h]
  __int128 v22; // [rsp+60h] [rbp-39h]
  hkVector4f v23; // [rsp+70h] [rbp-29h]
  __int128 v24; // [rsp+80h] [rbp-19h]
  hkSimdFloat32 v25; // [rsp+90h] [rbp-9h] BYREF
  unsigned int origKey; // [rsp+A0h] [rbp+7h]
  hkcdRay ray; // [rsp+B0h] [rbp+17h] BYREF
  char v28; // [rsp+100h] [rbp+67h]

  m_rayInput = this->m_rayInput;
  m_mediator = this->m_collection->m_instances.m_data[*(int *)&meshInstance[472]].m_mediator;
  *(_OWORD *)v20 = *(_OWORD *)&m_rayInput->m_filterInfo;
  v21 = *(_OWORD *)&m_rayInput->m_hitFilter;
  v22 = *(_OWORD *)&m_rayInput->m_localToWorldTransform;
  v23.m_quad = (__m128)m_rayInput->m_from;
  m_to = (__int128)m_rayInput->m_to;
  *((_QWORD *)&v21 + 1) = meshInstance;
  *(_QWORD *)&v22 = meshInstance + 112;
  v24 = m_to;
  if ( !((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, hkSimdFloat32 **, hkSimdFloat32 *))m_mediator->vfptr[2].__first_virtual_table_function__)(
          m_mediator,
          v20,
          &v25) )
    return 0i64;
  v9 = v25.m_real.m128_i32[0];
  if ( v25.m_real.m128_f32[0] >= this->m_hit.m_hitFraction.m_real.m128_f32[0] )
    return 0i64;
  v10 = origKey;
  m_cutter = this->m_cutter;
  v12 = origKey & 0x3FFFFF;
  if ( m_cutter
    && (!*(_DWORD *)&meshInstance[328] ? (v28 = 0) : (v28 = *(_BYTE *)((int)v12 + *(_QWORD *)&meshInstance[320])),
        (v28 & 1) != 0) )
  {
    cutOut.m_data = 0i64;
    cutOut.m_size = 0;
    cutOut.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshCutter::getCutKeysFromOriginal(m_cutter, origKey, &cutOut);
    v13 = 0;
    if ( cutOut.m_size <= 0 )
    {
LABEL_14:
      v16 = 0;
    }
    else
    {
      v14 = 0i64;
      while ( 1 )
      {
        v15 = cutOut.m_data[v14];
        if ( (!(_QWORD)v21
           || (*(unsigned int (__fastcall **)(_QWORD, hkaiNavMeshUtils *, _QWORD, _QWORD, hkSimdFloat32 *))(*(_QWORD *)v21 + 32i64))(
                v21,
                meshInstance,
                v12,
                LODWORD(v20[0]),
                v20[1]))
          && hkaiNavMeshUtils::intersectLineFace<hkaiNavMeshInstance>(
               meshInstance,
               (hkaiNavMeshInstance *)(v15 & 0x3FFFFF),
               &this->m_ray,
               &ray) )
        {
          break;
        }
        ++v13;
        ++v14;
        if ( v13 >= cutOut.m_size )
          goto LABEL_14;
      }
      v18.m_real = v25.m_real;
      this->m_hit.m_hitFaceKey = v15;
      this->m_hit.m_hitFraction = (hkSimdFloat32)v18.m_real;
      v16 = 1;
      hitFractionInOut->m_real = _mm_shuffle_ps((__m128)v18.m_real.m128_u32[0], (__m128)v18.m_real.m128_u32[0], 0);
    }
    cutOut.m_size = 0;
    if ( cutOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        cutOut.m_data,
        4 * cutOut.m_capacityAndFlags);
    return v16;
  }
  else
  {
    this->m_hit.m_hitFraction = (hkSimdFloat32)v25.m_real;
    this->m_hit.m_hitFaceKey = v10;
    result = 1i64;
    hitFractionInOut->m_real = _mm_shuffle_ps((__m128)v9, (__m128)v9, 0);
  }
  return result;
}

// File Line: 282
// RVA: 0xBE94C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::castRay(
        hkaiDynamicNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::RaycastInput *input,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkcdDynamicAabbTree *m_pntr; // rcx
  __m128i v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  hkVector4f v15; // xmm0
  hkaiStreamingCollection *v16; // rax
  hkaiNavMeshCutter *v17; // rax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  hkcdAabbTreeQueries::RaycastCollector collector; // [rsp+20h] [rbp-88h] BYREF
  hkaiNavMeshQueryMediator::RaycastInput *v27; // [rsp+28h] [rbp-80h]
  __m128 m_quad; // [rsp+30h] [rbp-78h]
  __m128 v29; // [rsp+40h] [rbp-68h]
  __m128 v30; // [rsp+50h] [rbp-58h]
  hkaiStreamingCollection *v31; // [rsp+60h] [rbp-48h]
  hkaiNavMeshCutter *v32; // [rsp+68h] [rbp-40h]
  hkSimdFloat32 v33; // [rsp+70h] [rbp-38h]
  unsigned int v34; // [rsp+80h] [rbp-28h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtDynMediator::castRay";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_pntr = this->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&NavMeshSectionRaycaster::`vftable;
  v27 = input;
  v12 = (__m128i)_mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  v13 = _mm_cmpeq_ps((__m128)0i64, (__m128)v12);
  v14 = _mm_rcp_ps((__m128)v12);
  v29 = _mm_shuffle_ps((__m128)v12, _mm_unpackhi_ps((__m128)v12, query.m_quad), 196);
  v30 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu), (__m128)_xmm), v13),
          _mm_andnot_ps(v13, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v12, v14)), v14)));
  v30.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v29)) & 7 | 0x3F000000;
  v15.m_quad = (__m128)input->m_from;
  v16 = this->m_collection.m_pntr;
  v34 = -1;
  v31 = v16;
  v17 = this->m_cutter.m_pntr;
  m_quad = v15.m_quad;
  v33.m_real = *(__m128 *)_xmm;
  v32 = v17;
  if ( m_pntr && hkcdDynamicAabbTree::castRay(m_pntr, &input->m_from, &input->m_to, &collector) )
  {
    v18 = v34;
    hitOut->m_hitFraction = (hkSimdFloat32)v33.m_real;
    hitOut->m_hitFaceKey = v18;
    v19 = 1;
  }
  else
  {
    v19 = 0;
  }
  collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&hkcdAabbTreeQueries::RaycastCollector::`vftable;
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
  return v19;
}

// File Line: 321
// RVA: 0xBE9E80
__int64 __fastcall NavMeshSectionAabbQuery::processLeaf(
        NavMeshSectionAabbQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkaiNavMeshInstance *m_instancePtr; // rdx

  m_instancePtr = this->m_collection->m_instances.m_data[leafKey].m_instancePtr;
  if ( m_instancePtr )
    NavMeshSectionAabbQuery::queryAabbAgainstMesh(this, m_instancePtr);
  return 1i64;
}

// File Line: 334
// RVA: 0xBE9EE0
void __fastcall NavMeshSectionAabbQuery::queryAabbAgainstMesh(
        NavMeshSectionAabbQuery *this,
        hkaiNavMeshUtils *meshInstance)
{
  hkaiNavMeshQueryMediator::AabbQueryInput *m_queryInput; // rax
  __m128 v5; // xmm0
  __int64 v6; // rax
  hkaiNavMeshQueryMediator *m_mediator; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> *m_hits; // r8
  int v9; // edx
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  int v13; // r13d
  __int64 v14; // r12
  unsigned int v15; // r9d
  char *v16; // rax
  int v17; // edx
  hkaiNavMeshCutter *m_cutter; // rcx
  int v19; // esi
  __int64 i; // rbx
  unsigned int v21; // edi
  BOOL v22; // ecx
  int v23; // eax
  hkArray<unsigned int,hkContainerTempAllocator> *v24; // rdx
  hkAabb *sizeElem; // [rsp+20h] [rbp-D8h]
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+30h] [rbp-C8h] BYREF
  _DWORD *v27; // [rsp+40h] [rbp-B8h] BYREF
  int v28; // [rsp+48h] [rbp-B0h]
  int v29; // [rsp+4Ch] [rbp-ACh]
  hkArrayBase<unsigned int> v30; // [rsp+50h] [rbp-A8h] BYREF
  __int128 v31; // [rsp+60h] [rbp-98h] BYREF
  char v32[24]; // [rsp+70h] [rbp-88h]
  __m128 m_quad; // [rsp+88h] [rbp-70h]
  __m128 v34; // [rsp+98h] [rbp-60h]
  int faceIndex[4]; // [rsp+A8h] [rbp-50h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+B8h] [rbp-40h] BYREF
  __m128 v37; // [rsp+C8h] [rbp-30h]
  void *retaddr; // [rsp+118h] [rbp+20h] BYREF
  char v39; // [rsp+120h] [rbp+28h] BYREF

  v29 = 0x80000000;
  v30.m_capacityAndFlags = 0x80000000;
  m_queryInput = this->m_queryInput;
  v27 = 0i64;
  v28 = 0;
  v30.m_data = 0i64;
  v30.m_size = 0;
  v31 = *(_OWORD *)&m_queryInput->m_filterInfo;
  *(_OWORD *)v32 = *(_OWORD *)&m_queryInput->m_hitFilter;
  *(_OWORD *)&v32[8] = *(_OWORD *)&m_queryInput->m_localToWorldTransform;
  m_quad = m_queryInput->m_aabb.m_min.m_quad;
  v5 = m_queryInput->m_aabb.m_max.m_quad;
  *(_QWORD *)&v32[8] = meshInstance + 112;
  v6 = *(int *)&meshInstance[472];
  v34 = v5;
  m_mediator = this->m_collection->m_instances.m_data[v6].m_mediator;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, __int128 *, _DWORD **))m_mediator->vfptr[3].__first_virtual_table_function__)(
    m_mediator,
    &v31,
    &v27);
  m_hits = this->m_hits;
  v9 = v28;
  v10 = v28 + m_hits->m_size;
  v11 = m_hits->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v10 )
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, m_hits, v10, 4);
    v9 = v28;
  }
  v13 = v9 - 1;
  v14 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    while ( 1 )
    {
      v15 = v27[v14];
      if ( this->m_cutter
        && (!*(_DWORD *)&meshInstance[328]
          ? (v39 = 0, v16 = &v39)
          : (char *)(v16 = (char *)&retaddr,
                     LOBYTE(retaddr) = *(_BYTE *)((v15 & 0x3FFFFF) + *(_QWORD *)&meshInstance[320])),
            (*v16 & 1) != 0) )
      {
        v17 = v9 - 1;
        v28 = v17;
        if ( v17 != v13 )
          v27[v14] = v27[v17];
        m_cutter = this->m_cutter;
        cutOut.m_data = 0i64;
        cutOut.m_size = 0;
        cutOut.m_capacityAndFlags = 0x80000000;
        hkaiNavMeshCutter::getCutKeysFromOriginal(m_cutter, v15, &cutOut);
        v19 = cutOut.m_size - 1;
        for ( i = cutOut.m_size - 1; i >= 0; --i )
        {
          v21 = cutOut.m_data[i] & 0x3FFFFF;
          v22 = 1;
          if ( *(_QWORD *)v32 )
          {
            sizeElem = (hkAabb *)*((_QWORD *)&v31 + 1);
            if ( !(*(unsigned int (__fastcall **)(_QWORD, hkaiNavMeshUtils *, _QWORD, _QWORD))(**(_QWORD **)v32 + 32i64))(
                    *(_QWORD *)v32,
                    meshInstance,
                    v21,
                    (unsigned int)v31) )
              v22 = 0;
          }
          if ( !v22
            || (*(__m128 *)faceIndex = _mm_shuffle_ps(
                                         (__m128)LODWORD(this->m_cutAabbTolerance),
                                         (__m128)LODWORD(this->m_cutAabbTolerance),
                                         0),
                hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
                  meshInstance,
                  (hkaiNavMeshInstance *)v21,
                  (__m128 *)faceIndex,
                  &extraRadius,
                  sizeElem),
                (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(m_quad, v37), _mm_cmple_ps(extraRadius.m_real, v34))) & 7) != 7) )
          {
            v23 = cutOut.m_size - 1;
            cutOut.m_size = v23;
            if ( v23 != v19 )
              cutOut.m_data[i] = cutOut.m_data[v23];
          }
          --v19;
        }
        hkArrayBase<unsigned int>::_insertAt(
          &v30,
          &hkContainerTempAllocator::s_alloc,
          v30.m_size,
          cutOut.m_data,
          cutOut.m_size);
        cutOut.m_size = 0;
        if ( cutOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            cutOut.m_data,
            4 * cutOut.m_capacityAndFlags);
        cutOut.m_data = 0i64;
        cutOut.m_capacityAndFlags = 0x80000000;
      }
      else
      {
        v24 = this->m_hits;
        v24->m_data[v24->m_size++] = v15;
      }
      --v13;
      if ( --v14 < 0 )
        break;
      v9 = v28;
    }
  }
  hkArrayBase<unsigned int>::_append(this->m_hits, &hkContainerTempAllocator::s_alloc, (char *)v30.m_data, v30.m_size);
  v30.m_size = 0;
  if ( v30.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v30.m_data,
      4 * v30.m_capacityAndFlags);
  v30.m_data = 0i64;
  v28 = 0;
  v30.m_capacityAndFlags = 0x80000000;
  if ( v29 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v27, 4 * v29);
}

// File Line: 405
// RVA: 0xBE9670
void __fastcall hkaiDynamicNavMeshQueryMediator::queryAabb(
        hkaiDynamicNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::AabbQueryInput *input,
        hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkcdDynamicAabbTree *m_pntr; // rcx
  float m_cutAabbTolerance; // xmm0_4
  hkaiStreamingCollection *v13; // rax
  hkaiNavMeshCutter *v14; // rax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-38h] BYREF
  hkaiNavMeshQueryMediator::AabbQueryInput *v21; // [rsp+28h] [rbp-30h]
  hkaiStreamingCollection *v22; // [rsp+30h] [rbp-28h]
  hkaiNavMeshCutter *v23; // [rsp+38h] [rbp-20h]
  hkArray<unsigned int,hkContainerTempAllocator> *v24; // [rsp+40h] [rbp-18h]
  float v25; // [rsp+48h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtDynMediator::queryAabb";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_pntr = this->m_aabbTree.m_pntr;
  m_cutAabbTolerance = this->m_cutAabbTolerance;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&NavMeshSectionAabbQuery::`vftable;
  v13 = this->m_collection.m_pntr;
  v21 = input;
  v25 = m_cutAabbTolerance;
  v22 = v13;
  v14 = this->m_cutter.m_pntr;
  v24 = hits;
  v23 = v14;
  if ( m_pntr )
    hkcdDynamicAabbTree::queryAabb(m_pntr, &input->m_aabb, &collector);
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = v16 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v17[1] = v19;
  }
}

