// File Line: 25
// RVA: 0xBE91A0
void __fastcall hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(hkaiDynamicNavMeshQueryMediator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable';
}

// File Line: 33
// RVA: 0xBE91C0
void __fastcall hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(hkaiDynamicNavMeshQueryMediator *this, hkaiStreamingCollection *collection, hkcdDynamicAabbTree *tree, hkaiNavMeshCutter *cutter)
{
  hkaiNavMeshCutter *v4; // rdi
  hkcdDynamicAabbTree *v5; // rsi
  hkaiStreamingCollection *v6; // rbp
  hkaiDynamicNavMeshQueryMediator *v7; // rbx

  v4 = cutter;
  v5 = tree;
  v6 = collection;
  v7 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable';
  if ( collection )
    hkReferencedObject::addReference((hkReferencedObject *)&collection->vfptr);
  v7->m_collection.m_pntr = v6;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v7->m_aabbTree.m_pntr = v5;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v7->m_cutter.m_pntr = v4;
  v7->m_cutAabbTolerance = 0.050000001;
}

// File Line: 37
// RVA: 0xBE9250
void __fastcall hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(hkaiDynamicNavMeshQueryMediator *this)
{
  hkaiDynamicNavMeshQueryMediator *v1; // rbx
  hkaiNavMeshCutter *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDynamicNavMeshQueryMediator::`vftable';
  v2 = this->m_cutter.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_cutter.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_aabbTree.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_aabbTree.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_collection.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_collection.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 55
// RVA: 0xBE9CE0
hkSimdFloat32 *__fastcall NavMeshClosestPointCollector::processLeaf(NavMeshClosestPointCollector *this, hkSimdFloat32 *result, unsigned int leafKey, hkAabb *leafAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut, hkSimdFloat32 *closestDistanceSquared)
{
  NavMeshClosestPointCollector *v7; // rdi
  __m128i *v8; // rbx
  signed __int64 v9; // r9
  hkaiStreamingCollection::InstanceInfo *v10; // r8
  __int64 v11; // rcx
  __int64 v12; // r10
  hkSimdFloat32 *v13; // rax
  __int128 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __int128 v19; // xmm1
  __m128 v20; // xmm0
  hkaiNavMeshCutter *v21; // rax
  unsigned int v22; // eax
  hkVector4f v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128i v26; // xmm2
  __m128 v27; // [rsp+20h] [rbp-78h]
  __int128 v28; // [rsp+30h] [rbp-68h]
  __int128 v29; // [rsp+40h] [rbp-58h]
  __int128 v30; // [rsp+50h] [rbp-48h]
  __int128 v31; // [rsp+60h] [rbp-38h]
  __m128 v32; // [rsp+70h] [rbp-28h]
  __int128 v33; // [rsp+80h] [rbp-18h]

  v7 = this;
  v8 = (__m128i *)result;
  v9 = 3i64 * (signed int)leafKey;
  v10 = this->m_collection->m_instances.m_data;
  v9 *= 2i64;
  v11 = *((_QWORD *)&v10->m_instancePtr + v9);
  v12 = *((_QWORD *)&v10->m_mediator + v9);
  if ( v11 )
  {
    v14 = (__int128 *)v7->m_gcpInput;
    v15 = closestDistanceSquared->m_real;
    v16 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
    v17 = _mm_cmpleps(closestDistanceSquared->m_real, (__m128)0i64);
    v18 = _mm_mul_ps(
            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v16), v16)),
            _mm_mul_ps(*(__m128 *)_xmm, v16));
    v28 = *v14;
    v29 = v14[1];
    v30 = v14[2];
    v31 = v14[3];
    v32 = (__m128)v14[4];
    v19 = v14[5];
    v20 = queryPoint->m_quad;
    *((_QWORD *)&v29 + 1) = v11;
    *(_QWORD *)&v30 = v11 + 112;
    v21 = v7->m_cutter;
    v33 = v19;
    v32 = _mm_andnot_ps(v17, _mm_mul_ps(v18, v15));
    _mm_store_si128((__m128i *)&v27, (__m128i)v20);
    *(_QWORD *)&v33 = v21;
    v22 = (*(__int64 (__fastcall **)(__int64, __int128 *, __m128 *))(*(_QWORD *)v12 + 24i64))(v12, &v28, &v27);
    if ( v22 == -1 )
    {
      _mm_store_si128(v8, (__m128i)closestDistanceSquared->m_real);
    }
    else
    {
      v23.m_quad = v27;
      v24 = _mm_sub_ps(v27, queryPoint->m_quad);
      v25 = _mm_mul_ps(v24, v24);
      v26 = (__m128i)_mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                       _mm_shuffle_ps(v25, v25, 170));
      if ( *(float *)v26.m128i_i32 < closestDistanceSquared->m_real.m128_f32[0] )
      {
        v7->m_bestFaceKey = v22;
        *closestPointOut = (hkVector4f)v23.m_quad;
      }
      _mm_store_si128(v8, v26);
    }
    v13 = (hkSimdFloat32 *)v8;
  }
  else
  {
    v13 = result;
    _mm_store_si128((__m128i *)result, (__m128i)closestDistanceSquared->m_real);
  }
  return v13;
}

// File Line: 99
// RVA: 0xBE92C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::getClosestPoint(hkaiDynamicNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput, hkVector4f *closestPointOut)
{
  hkaiDynamicNavMeshQueryMediator *v3; // rdi
  hkVector4f *v4; // rsi
  hkaiNavMeshQueryMediator::GetClosestPointInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkcdDynamicAabbTree *v11; // rcx
  __int64 v12; // rax
  unsigned int v13; // ebx
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-38h]
  hkaiNavMeshQueryMediator::GetClosestPointInput *v21; // [rsp+38h] [rbp-30h]
  hkaiStreamingCollection *v22; // [rsp+40h] [rbp-28h]
  __int64 v23; // [rsp+48h] [rbp-20h]
  unsigned int v24; // [rsp+50h] [rbp-18h]

  v3 = this;
  v4 = closestPointOut;
  v5 = gcpInput;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtDynMediator::GCP";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshClosestPointCollector::`vftable';
  v22 = v3->m_collection.m_pntr;
  v12 = (__int64)v3->m_cutter.m_pntr;
  v21 = v5;
  v24 = -1;
  v23 = v12;
  hkcdDynamicAabbTree::getClosestPoint(v11, &v5->m_position, &v5->m_queryRadius, &collector, v4);
  v13 = v24;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable';
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 127
// RVA: 0xBE9B70
hkSimdFloat32 *__fastcall NavMeshClosestBoundaryEdgeCollector::processLeaf(NavMeshClosestBoundaryEdgeCollector *this, hkSimdFloat32 *result, unsigned int leafKey, hkAabb *leafAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut, hkSimdFloat32 *closestDistanceSquared)
{
  NavMeshClosestBoundaryEdgeCollector *v7; // rdi
  hkSimdFloat32 *v8; // rbx
  signed __int64 v9; // r9
  hkaiStreamingCollection::InstanceInfo *v10; // r8
  __int64 v11; // rcx
  __int64 v12; // r10
  hkSimdFloat32 *v13; // rax
  __int128 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __int128 v19; // xmm0
  hkaiNavMeshCutter *v20; // rax
  unsigned int v21; // eax
  hkVector4f v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // [rsp+20h] [rbp-88h]
  __int128 v25; // [rsp+30h] [rbp-78h]
  __int128 v26; // [rsp+40h] [rbp-68h]
  __int128 v27; // [rsp+50h] [rbp-58h]
  __int128 v28; // [rsp+60h] [rbp-48h]
  __m128 v29; // [rsp+70h] [rbp-38h]
  __int128 v30; // [rsp+80h] [rbp-28h]
  __int128 v31; // [rsp+90h] [rbp-18h]

  v7 = this;
  v8 = result;
  v9 = 3i64 * (signed int)leafKey;
  v10 = this->m_collection->m_instances.m_data;
  v9 *= 2i64;
  v11 = *((_QWORD *)&v10->m_instancePtr + v9);
  v12 = *((_QWORD *)&v10->m_mediator + v9);
  if ( v11 )
  {
    v14 = (__int128 *)v7->m_gcbInput;
    v15 = closestDistanceSquared->m_real;
    v16 = _mm_rsqrt_ps(closestDistanceSquared->m_real);
    v17 = _mm_cmpleps(closestDistanceSquared->m_real, (__m128)0i64);
    v18 = _mm_mul_ps(
            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(closestDistanceSquared->m_real, v16), v16)),
            _mm_mul_ps(*(__m128 *)_xmm, v16));
    v25 = *v14;
    v26 = v14[1];
    v27 = v14[2];
    v28 = v14[3];
    v29 = (__m128)v14[4];
    v30 = v14[5];
    v19 = v14[6];
    v29 = _mm_andnot_ps(v17, _mm_mul_ps(v18, v15));
    *((_QWORD *)&v26 + 1) = v11;
    *(_QWORD *)&v27 = v11 + 112;
    v20 = v7->m_cutter;
    v31 = v19;
    *(_QWORD *)&v30 = v20;
    _mm_store_si128((__m128i *)&v24, (__m128i)queryPoint->m_quad);
    v21 = (*(__int64 (__fastcall **)(__int64, __int128 *, __m128 *))(*(_QWORD *)v12 + 32i64))(v12, &v25, &v24);
    if ( v21 == -1 )
    {
      v23 = closestDistanceSquared->m_real;
    }
    else
    {
      v22.m_quad = v24;
      v23 = _mm_shuffle_ps(v24, v24, 255);
      if ( v23.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
      {
        v7->m_bestFaceKey = v21;
        *closestPointOut = (hkVector4f)v22.m_quad;
      }
    }
    v13 = v8;
    _mm_store_si128((__m128i *)v8, (__m128i)v23);
  }
  else
  {
    v13 = result;
    _mm_store_si128((__m128i *)result, (__m128i)closestDistanceSquared->m_real);
  }
  return v13;
}

// File Line: 170
// RVA: 0xBE93C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::getClosestBoundaryEdge(hkaiDynamicNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *gcbInput, hkVector4f *closestPointOut)
{
  hkaiDynamicNavMeshQueryMediator *v3; // rdi
  hkVector4f *v4; // rsi
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkcdDynamicAabbTree *v11; // rcx
  __int64 v12; // rax
  unsigned int v13; // ebx
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+30h] [rbp-38h]
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v21; // [rsp+38h] [rbp-30h]
  hkaiStreamingCollection *v22; // [rsp+40h] [rbp-28h]
  __int64 v23; // [rsp+48h] [rbp-20h]
  unsigned int v24; // [rsp+50h] [rbp-18h]

  v3 = this;
  v4 = closestPointOut;
  v5 = gcbInput;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtDynMediator::GCBoundary";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshClosestBoundaryEdgeCollector::`vftable';
  v22 = v3->m_collection.m_pntr;
  v12 = (__int64)v3->m_cutter.m_pntr;
  v21 = v5;
  v24 = -1;
  v23 = v12;
  hkcdDynamicAabbTree::getClosestPoint(v11, &v5->m_position, &v5->m_queryRadius, &collector, v4);
  v13 = v24;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable';
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 199
// RVA: 0xBE9EB0
signed __int64 __fastcall NavMeshSectionRaycaster::processLeaf(NavMeshSectionRaycaster *this, unsigned int leafKey, hkAabb *leafAabb, hkSimdFloat32 *hitFractionInOut)
{
  hkaiNavMeshInstance *v4; // rdx
  signed __int64 result; // rax

  v4 = this->m_collection->m_instances.m_data[leafKey].m_instancePtr;
  if ( v4 )
    result = NavMeshSectionRaycaster::castRayAgainstMeshInstance(this, v4, hitFractionInOut);
  else
    result = 0i64;
  return result;
}

// File Line: 214
// RVA: 0xBE9920
signed __int64 __fastcall NavMeshSectionRaycaster::castRayAgainstMeshInstance(NavMeshSectionRaycaster *this, hkaiNavMeshInstance *meshInstance, hkSimdFloat32 *hitFractionInOut)
{
  NavMeshSectionRaycaster *v3; // r14
  hkSimdFloat32 *v4; // rbx
  hkaiNavMeshInstance *v5; // r13
  hkaiNavMeshQueryMediator::RaycastInput *v6; // rax
  hkaiNavMeshQueryMediator *v7; // rcx
  __int128 v8; // xmm0
  unsigned int v9; // xmm0_4
  unsigned int v10; // edx
  hkaiNavMeshCutter *v11; // r9
  unsigned int v12; // er12
  int v13; // ebx
  __int64 v14; // rdi
  unsigned int v15; // er15
  unsigned int v16; // esi
  unsigned int v17; // ebx
  signed __int64 result; // rax
  __int128 v19; // xmm0
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+30h] [rbp-69h]
  hkSimdFloat32 *v21[2]; // [rsp+40h] [rbp-59h]
  __int128 v22; // [rsp+50h] [rbp-49h]
  __int128 v23; // [rsp+60h] [rbp-39h]
  hkVector4f v24; // [rsp+70h] [rbp-29h]
  __int128 v25; // [rsp+80h] [rbp-19h]
  __int128 v26; // [rsp+90h] [rbp-9h]
  unsigned int origKey; // [rsp+A0h] [rbp+7h]
  hkcdRay ray; // [rsp+B0h] [rbp+17h]
  char v29; // [rsp+100h] [rbp+67h]
  hkSimdFloat32 *v30; // [rsp+110h] [rbp+77h]

  v30 = hitFractionInOut;
  v3 = this;
  v4 = hitFractionInOut;
  v5 = meshInstance;
  v6 = this->m_rayInput;
  v7 = this->m_collection->m_instances.m_data[meshInstance->m_runtimeId].m_mediator;
  *(_OWORD *)v21 = *(_OWORD *)&v6->m_filterInfo;
  v22 = *(_OWORD *)&v6->m_hitFilter;
  v23 = *(_OWORD *)&v6->m_localToWorldTransform;
  v24.m_quad = (__m128)v6->m_from;
  v8 = (__int128)v6->m_to;
  *((_QWORD *)&v22 + 1) = meshInstance;
  *(_QWORD *)&v23 = (char *)meshInstance + 112;
  v25 = v8;
  if ( !((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, hkSimdFloat32 **, __int128 *))v7->vfptr[2].__first_virtual_table_function__)(
          v7,
          v21,
          &v26) )
    return 0i64;
  v9 = v26;
  if ( *(float *)&v26 >= v3->m_hit.m_hitFraction.m_real.m128_f32[0] )
    return 0i64;
  v10 = origKey;
  v11 = v3->m_cutter;
  v12 = origKey & 0x3FFFFF;
  if ( v11 && (!v5->m_faceFlags.m_size ? (v29 = 0) : (v29 = v5->m_faceFlags.m_data[v12].m_storage), v29 & 1) )
  {
    cutOut.m_data = 0i64;
    cutOut.m_size = 0;
    cutOut.m_capacityAndFlags = 2147483648;
    hkaiNavMeshCutter::getCutKeysFromOriginal(v11, origKey, &cutOut);
    v13 = 0;
    if ( cutOut.m_size <= 0 )
    {
LABEL_14:
      v17 = 0;
    }
    else
    {
      v14 = 0i64;
      while ( 1 )
      {
        v15 = cutOut.m_data[v14];
        v16 = cutOut.m_data[v14] & 0x3FFFFF;
        if ( !(_QWORD)v22
          || (*(unsigned int (__fastcall **)(_QWORD, hkaiNavMeshInstance *, _QWORD, _QWORD, hkSimdFloat32 *))(*(_QWORD *)v22 + 32i64))(
               v22,
               v5,
               v12,
               LODWORD(v21[0]),
               v21[1]) )
        {
          if ( hkaiNavMeshUtils::intersectLineFace<hkaiNavMeshInstance>(
                 (hkaiNavMeshUtils *)v5,
                 (hkaiNavMeshInstance *)v16,
                 (__int64)&v3->m_ray,
                 &ray) )
          {
            break;
          }
        }
        ++v13;
        ++v14;
        if ( v13 >= cutOut.m_size )
          goto LABEL_14;
      }
      v19 = v26;
      v3->m_hit.m_hitFaceKey = v15;
      v3->m_hit.m_hitFraction = (hkSimdFloat32)v19;
      v17 = 1;
      v30->m_real = _mm_shuffle_ps((__m128)(unsigned int)v19, (__m128)(unsigned int)v19, 0);
    }
    cutOut.m_size = 0;
    if ( cutOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        cutOut.m_data,
        4 * cutOut.m_capacityAndFlags);
    result = v17;
  }
  else
  {
    v3->m_hit.m_hitFraction = (hkSimdFloat32)v26;
    v3->m_hit.m_hitFaceKey = v10;
    result = 1i64;
    v4->m_real = _mm_shuffle_ps((__m128)v9, (__m128)v9, 0);
  }
  return result;
}

// File Line: 282
// RVA: 0xBE94C0
__int64 __fastcall hkaiDynamicNavMeshQueryMediator::castRay(hkaiDynamicNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::RaycastInput *input, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  hkaiDynamicNavMeshQueryMediator *v3; // rsi
  hkaiNavMeshQueryMediator::HitDetails *v4; // rbx
  hkaiNavMeshQueryMediator::RaycastInput *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkcdDynamicAabbTree *v11; // rcx
  __m128i v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __int128 v15; // xmm0
  __int64 v16; // rax
  __int64 v17; // rax
  int v18; // eax
  unsigned __int8 v19; // bl
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  hkcdAabbTreeQueries::RaycastCollector collector; // [rsp+20h] [rbp-88h]
  hkaiNavMeshQueryMediator::RaycastInput *v27; // [rsp+28h] [rbp-80h]
  __int128 v28; // [rsp+30h] [rbp-78h]
  __m128 v29; // [rsp+40h] [rbp-68h]
  __m128 v30; // [rsp+50h] [rbp-58h]
  __int64 v31; // [rsp+60h] [rbp-48h]
  __int64 v32; // [rsp+68h] [rbp-40h]
  hkSimdFloat32 v33; // [rsp+70h] [rbp-38h]
  int v34; // [rsp+80h] [rbp-28h]

  v3 = this;
  v4 = hitOut;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtDynMediator::castRay";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_aabbTree.m_pntr;
  collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&NavMeshSectionRaycaster::`vftable';
  v27 = v5;
  v12 = (__m128i)_mm_sub_ps(v5->m_to.m_quad, v5->m_from.m_quad);
  v13 = _mm_cmpeqps((__m128)0i64, (__m128)v12);
  v14 = _mm_rcp_ps((__m128)v12);
  v29 = _mm_shuffle_ps((__m128)v12, _mm_unpackhi_ps((__m128)v12, query.m_quad), 196);
  v30 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu), (__m128)_xmm), v13),
          _mm_andnot_ps(v13, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v12, v14)), v14)));
  v30.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v29)) & 7 | 0x3F000000;
  v15 = (__int128)v5->m_from;
  v16 = (__int64)v3->m_collection.m_pntr;
  v34 = -1;
  v31 = v16;
  v17 = (__int64)v3->m_cutter.m_pntr;
  v28 = v15;
  v33.m_real = *(__m128 *)_xmm;
  v32 = v17;
  if ( v11 && hkcdDynamicAabbTree::castRay(v11, &v5->m_from, &v5->m_to, &collector) )
  {
    v18 = v34;
    v4->m_hitFraction = (hkSimdFloat32)v33.m_real;
    v4->m_hitFaceKey = v18;
    v19 = 1;
  }
  else
  {
    v19 = 0;
  }
  collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&hkcdAabbTreeQueries::RaycastCollector::`vftable';
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v22[1] = v24;
  }
  return v19;
}

// File Line: 321
// RVA: 0xBE9E80
signed __int64 __fastcall NavMeshSectionAabbQuery::processLeaf(NavMeshSectionAabbQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkaiNavMeshInstance *v3; // rdx

  v3 = this->m_collection->m_instances.m_data[leafKey].m_instancePtr;
  if ( v3 )
    NavMeshSectionAabbQuery::queryAabbAgainstMesh(this, v3);
  return 1i64;
}

// File Line: 334
// RVA: 0xBE9EE0
void __fastcall NavMeshSectionAabbQuery::queryAabbAgainstMesh(NavMeshSectionAabbQuery *this, hkaiNavMeshInstance *meshInstance)
{
  __int128 *v2; // rax
  hkaiNavMeshInstance *v3; // r14
  NavMeshSectionAabbQuery *v4; // r15
  __m128 v5; // xmm0
  __int64 v6; // rax
  hkaiNavMeshQueryMediator *v7; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> *v8; // r8
  int v9; // edx
  int v10; // er9
  int v11; // eax
  int v12; // eax
  int v13; // er13
  __int64 v14; // r12
  unsigned int v15; // er9
  char *v16; // rax
  int v17; // edx
  hkaiNavMeshCutter *v18; // rcx
  int v19; // esi
  __int64 i; // rbx
  unsigned int v21; // edi
  BOOL v22; // ecx
  int v23; // eax
  hkArray<unsigned int,hkContainerTempAllocator> *v24; // rdx
  hkAabb *sizeElem; // [rsp+20h] [rbp-D8h]
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+30h] [rbp-C8h]
  _DWORD *v27; // [rsp+40h] [rbp-B8h]
  int v28; // [rsp+48h] [rbp-B0h]
  int v29; // [rsp+4Ch] [rbp-ACh]
  hkArrayBase<unsigned int> v30; // [rsp+50h] [rbp-A8h]
  __int128 v31; // [rsp+60h] [rbp-98h]
  __int128 v32; // [rsp+70h] [rbp-88h]
  __m128 v33; // [rsp+88h] [rbp-70h]
  __m128 v34; // [rsp+98h] [rbp-60h]
  int faceIndex[4]; // [rsp+A8h] [rbp-50h]
  hkSimdFloat32 extraRadius; // [rsp+B8h] [rbp-40h]
  __m128 v37; // [rsp+C8h] [rbp-30h]
  void *retaddr; // [rsp+118h] [rbp+20h]
  char v39; // [rsp+120h] [rbp+28h]

  v29 = 2147483648;
  v30.m_capacityAndFlags = 2147483648;
  v2 = (__int128 *)this->m_queryInput;
  v27 = 0i64;
  v28 = 0;
  v30.m_data = 0i64;
  v30.m_size = 0;
  v3 = meshInstance;
  v4 = this;
  v31 = *v2;
  v32 = v2[1];
  *(__int128 *)((char *)&v32 + 8) = v2[2];
  v33 = (__m128)v2[3];
  v5 = (__m128)v2[4];
  *((_QWORD *)&v32 + 1) = (char *)meshInstance + 112;
  v6 = meshInstance->m_runtimeId;
  v34 = v5;
  v7 = this->m_collection->m_instances.m_data[v6].m_mediator;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, __int128 *, _DWORD **))v7->vfptr[3].__first_virtual_table_function__)(
    v7,
    &v31,
    &v27);
  v8 = v4->m_hits;
  v9 = v28;
  v10 = v28 + v8->m_size;
  v11 = v8->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v10 )
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v8,
      v10,
      4);
    v9 = v28;
  }
  v13 = v9 - 1;
  v14 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    while ( 1 )
    {
      v15 = v27[v14];
      if ( v4->m_cutter
        && (!v3->m_faceFlags.m_size ? (v39 = 0, v16 = &v39) : (v16 = (char *)&retaddr,
                                                               LOBYTE(retaddr) = v3->m_faceFlags.m_data[v15 & 0x3FFFFF].m_storage),
            *v16 & 1) )
      {
        v17 = v9 - 1;
        v28 = v17;
        if ( v17 != v13-- )
          v27[v14] = v27[v17];
        v18 = v4->m_cutter;
        cutOut.m_data = 0i64;
        cutOut.m_size = 0;
        cutOut.m_capacityAndFlags = 2147483648;
        hkaiNavMeshCutter::getCutKeysFromOriginal(v18, v15, &cutOut);
        v19 = cutOut.m_size - 1;
        for ( i = cutOut.m_size - 1; i >= 0; --i )
        {
          v21 = cutOut.m_data[i] & 0x3FFFFF;
          v22 = 1;
          if ( (_QWORD)v32 )
          {
            sizeElem = (hkAabb *)*((_QWORD *)&v31 + 1);
            if ( !(*(unsigned int (__fastcall **)(_QWORD, hkaiNavMeshInstance *, _QWORD, _QWORD))(*(_QWORD *)v32 + 32i64))(
                    v32,
                    v3,
                    v21,
                    (unsigned int)v31) )
              v22 = 0;
          }
          if ( !v22
            || (*(__m128 *)faceIndex = _mm_shuffle_ps(
                                         (__m128)LODWORD(v4->m_cutAabbTolerance),
                                         (__m128)LODWORD(v4->m_cutAabbTolerance),
                                         0),
                hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
                  (hkaiNavMeshUtils *)v3,
                  (hkaiNavMeshInstance *)v21,
                  (__int64)faceIndex,
                  &extraRadius,
                  sizeElem),
                (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v33, v37), _mm_cmpleps(extraRadius.m_real, v34))) & 7) != 7) )
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
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          v30.m_size,
          cutOut.m_data,
          cutOut.m_size);
        cutOut.m_size = 0;
        if ( cutOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            cutOut.m_data,
            4 * cutOut.m_capacityAndFlags);
        cutOut.m_data = 0i64;
        cutOut.m_capacityAndFlags = 2147483648;
      }
      else
      {
        v24 = v4->m_hits;
        v24->m_data[v24->m_size++] = v15;
      }
      if ( --v14 < 0 )
        break;
      v9 = v28;
    }
  }
  hkArrayBase<unsigned int>::_append(
    (hkArrayBase<unsigned int> *)&v4->m_hits->m_data,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    v30.m_data,
    v30.m_size);
  v30.m_size = 0;
  if ( v30.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v30.m_data,
      4 * v30.m_capacityAndFlags);
  v30.m_data = 0i64;
  v28 = 0;
  v30.m_capacityAndFlags = 2147483648;
  if ( v29 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v27,
      4 * v29);
}

// File Line: 405
// RVA: 0xBE9670
void __fastcall hkaiDynamicNavMeshQueryMediator::queryAabb(hkaiDynamicNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::AabbQueryInput *input, hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  hkaiDynamicNavMeshQueryMediator *v3; // rbx
  hkArray<unsigned int,hkContainerTempAllocator> *v4; // rsi
  hkaiNavMeshQueryMediator::AabbQueryInput *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkcdDynamicAabbTree *v11; // rcx
  int v12; // xmm0_4
  __int64 v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-38h]
  hkaiNavMeshQueryMediator::AabbQueryInput *v21; // [rsp+28h] [rbp-30h]
  __int64 v22; // [rsp+30h] [rbp-28h]
  __int64 v23; // [rsp+38h] [rbp-20h]
  hkArray<unsigned int,hkContainerTempAllocator> *v24; // [rsp+40h] [rbp-18h]
  int v25; // [rsp+48h] [rbp-10h]

  v3 = this;
  v4 = hits;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtDynMediator::queryAabb";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_aabbTree.m_pntr;
  v12 = LODWORD(v3->m_cutAabbTolerance);
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&NavMeshSectionAabbQuery::`vftable';
  v13 = (__int64)v3->m_collection.m_pntr;
  v21 = v5;
  v25 = v12;
  v22 = v13;
  v14 = (__int64)v3->m_cutter.m_pntr;
  v24 = v4;
  v23 = v14;
  if ( v11 )
    hkcdDynamicAabbTree::queryAabb(v11, &v5->m_aabb, &collector);
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable';
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v17[1] = v19;
  }
}

