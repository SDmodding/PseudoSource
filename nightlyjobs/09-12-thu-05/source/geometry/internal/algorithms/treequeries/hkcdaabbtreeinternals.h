// File Line: 48
// RVA: 0xC966F0
__int64 __fastcall hkcdAabbTree_castRay<hkcdStaticTree::DefaultTreeStorage6>(const void *treePtr, hkVector4f *start, hkVector4f *end, hkcdAabbTreeQueries::RaycastCollector *collector)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  __m128i v6; // xmm6
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  hkcdRay ray; // [rsp+20h] [rbp-78h]
  __m128 v11; // [rsp+50h] [rbp-48h]
  __m128 v12; // [rsp+60h] [rbp-38h]

  v4 = end->m_quad;
  ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)collector;
  ray.m_origin.m_quad.m128_i32[2] = 0;
  v5 = start->m_quad;
  v6 = (__m128i)_mm_sub_ps(v4, start->m_quad);
  v7 = _mm_cmpeqps((__m128)0i64, (__m128)v6);
  v8 = _mm_rcp_ps((__m128)v6);
  v11 = _mm_shuffle_ps((__m128)v6, _mm_unpackhi_ps((__m128)v6, query.m_quad), 196);
  v12 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v6, 0x1Fu), 0x1Fu), (__m128)_xmm), v7),
          _mm_andnot_ps(v7, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, (__m128)v6)), v8)));
  ray.m_invDirection.m_quad = v5;
  v12.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v11)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkcdStaticTree::DefaultTreeStorage6,WrappedRaycastQuery<hkcdStaticTree::DefaultTreeStorage6>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&ray.m_direction,
    (hkSimdFloat32 *)treePtr,
    (hkcdStaticTree::DefaultTreeStorage6 *)&ray.m_invDirection,
    &ray,
    (WrappedRaycastQuery<hkcdStaticTree::DefaultTreeStorage6> *)collector);
  return ray.m_origin.m_quad.m128_u32[2];
}

// File Line: 79
// RVA: 0xC91A20
void __fastcall hkcdAabbTree_queryAabb<hkcdDynamicTree::DefaultTree48Storage>(const void *treePtr, hkAabb *aabb, hkcdAabbTreeQueries::AabbCollector *collector)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v5; // rbx
  hkLifoAllocator *v6; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<WrappedAabbQuery<hkcdDynamicTree::DefaultTree48Storage> > *v7; // r9
  hkcdDynamicTree::CodecRawUint *v8; // rdx
  unsigned __int64 v9; // rcx
  int v10; // eax
  char *v11; // rdi
  signed int v12; // ebx
  hkLifoAllocator *v13; // rax
  int v14; // er8
  hkcdDynamicTree::DefaultTree48Storage tree; // [rsp+20h] [rbp-58h]
  int v16; // [rsp+48h] [rbp-30h]
  __m128 v17; // [rsp+50h] [rbp-28h]
  __m128 v18; // [rsp+60h] [rbp-18h]
  hkcdAabbTreeQueries::AabbCollector *v19; // [rsp+80h] [rbp+8h]

  v3.m_quad = (__m128)aabb->m_min;
  v4.m_quad = (__m128)aabb->m_max;
  v5 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)treePtr;
  tree.m_nodes.m_data = 0i64;
  *(_QWORD *)&tree.m_root = &v19;
  v19 = collector;
  v17 = v3.m_quad;
  v18 = v4.m_quad;
  v16 = 1;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_numLeaves = 64;
  v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkcdDynamicTree::CodecRawUint *)v6->m_cur;
  v9 = (unsigned __int64)&v8[5].m_aabb.m_max;
  if ( v6->m_slabSize < 256 || (void *)v9 > v6->m_end )
    v8 = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(v6, 256);
  else
    v6->m_cur = (void *)v9;
  tree.m_nodes.m_data = v8;
  *(_QWORD *)&tree.m_firstFree = v8;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::DefaultTree48Storage,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<WrappedAabbQuery<hkcdDynamicTree::DefaultTree48Storage>>>(
    v5,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&tree.m_root,
    v7);
  v10 = tree.m_nodes.m_size;
  v11 = *(char **)&tree.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRawUint **)&tree.m_firstFree == tree.m_nodes.m_data )
    v10 = 0;
  tree.m_nodes.m_size = v10;
  v12 = (4 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v13->m_slabSize || &v11[v14] != v13->m_cur || v13->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v13, v11, v14);
  else
    v13->m_cur = v11;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      4 * tree.m_nodes.m_capacityAndFlags);
}

// File Line: 120
// RVA: 0xC91B80
hkResult *__fastcall hkcdAabbTree_queryAabbHits<hkcdDynamicTree::DefaultTree48Storage>(hkResult *result, const void *treePtr, hkAabb *aabb, hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  hkResult *v4; // rsi
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // rbx
  hkLifoAllocator *v8; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<WrappedAabbHitsQuery<hkcdDynamicTree::DefaultTree48Storage> > *v9; // r9
  hkcdDynamicTree::CodecRawUint *v10; // rdx
  unsigned __int64 v11; // rcx
  int v12; // eax
  char *v13; // rdi
  signed int v14; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // er8
  hkArray<unsigned int,hkContainerTempAllocator> *v18; // [rsp+20h] [rbp-68h]
  hkResult *v19; // [rsp+28h] [rbp-60h]
  hkcdDynamicTree::DefaultTree48Storage tree; // [rsp+30h] [rbp-58h]
  __m128 v21; // [rsp+60h] [rbp-28h]
  __m128 v22; // [rsp+70h] [rbp-18h]

  v4 = result;
  v19 = result;
  result->m_enum = 0;
  tree.m_nodes.m_data = 0i64;
  v5.m_quad = (__m128)aabb->m_min;
  v6.m_quad = (__m128)aabb->m_max;
  v7 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)treePtr;
  v18 = hits;
  *(_QWORD *)&tree.m_root = &v18;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  v21 = v5.m_quad;
  v22 = v6.m_quad;
  tree.m_numLeaves = 64;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkcdDynamicTree::CodecRawUint *)v8->m_cur;
  v11 = (unsigned __int64)&v10[5].m_aabb.m_max;
  if ( v8->m_slabSize < 256 || (void *)v11 > v8->m_end )
    v10 = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(v8, 256);
  else
    v8->m_cur = (void *)v11;
  tree.m_nodes.m_data = v10;
  *(_QWORD *)&tree.m_firstFree = v10;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::DefaultTree48Storage,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<WrappedAabbHitsQuery<hkcdDynamicTree::DefaultTree48Storage>>>(
    v7,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&tree.m_root,
    v9);
  v12 = tree.m_nodes.m_size;
  v13 = *(char **)&tree.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRawUint **)&tree.m_firstFree == tree.m_nodes.m_data )
    v12 = 0;
  tree.m_nodes.m_size = v12;
  v14 = (4 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v15->m_slabSize || &v13[v16] != v15->m_cur || v15->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v15, v13, v16);
  else
    v15->m_cur = v13;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      4 * tree.m_nodes.m_capacityAndFlags);
  return v4;
}

// File Line: 173
// RVA: 0xC96800
__int64 __fastcall hkcdAabbTree_getClosestPoint<hkcdStaticTree::DefaultTreeStorage6>(const void *treePtr, hkVector4f *point, hkSimdFloat32 *maxDistance, hkcdAabbTreeQueries::ClosestPointCollector *collector, hkVector4f *closestPointOut)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  WrappedClosestPointQuery<hkcdStaticTree::DefaultTreeStorage6> query; // [rsp+30h] [rbp-58h]
  hkVector4f v9; // [rsp+60h] [rbp-28h]
  hkcdAabbTreeQueries::ClosestPointCollector *v10; // [rsp+70h] [rbp-18h]

  v5 = point->m_quad;
  v6 = maxDistance->m_real;
  v10 = collector;
  LODWORD(query.m_collector) = -1;
  *(__m128 *)&query.m_bestIndex = _mm_mul_ps(v6, v6);
  v9.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, *(__m128 *)&query.m_bestIndex), 196);
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::closest<hkcdStaticTree::DefaultTreeStorage6,WrappedClosestPointQuery<hkcdStaticTree::DefaultTreeStorage6>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&query.m_closestPoint,
    (hkSimdFloat32 *)treePtr,
    (hkcdStaticTree::DefaultTreeStorage6 *)point,
    (hkVector4f *)&query.m_collector,
    &query);
  *closestPointOut = (hkVector4f)v9.m_quad;
  return LODWORD(query.m_collector);
}

// File Line: 208
// RVA: 0xC91990
void __fastcall hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(const void *treePtr, hkcdAabbTreeQueries::AllPairsCollector *collector, WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage> *a3)
{
  hkcdAabbTreeQueries::AllPairsCollector *v3; // [rsp+30h] [rbp+8h]

  v3 = collector;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::DefaultTree48Storage,WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)treePtr,
    (hkcdDynamicTree::DefaultTree48Storage *)&v3,
    a3);
}

// File Line: 220
// RVA: 0xC91970
void __fastcall hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(const void *treePtr, const void *otherTreePtr, hkcdAabbTreeQueries::AllPairsCollector *collector, WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage> *a4)
{
  hkcdAabbTreeQueries::AllPairsCollector *v4; // [rsp+30h] [rbp+8h]

  v4 = collector;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage,WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)treePtr,
    (hkcdDynamicTree::DefaultTree48Storage *)otherTreePtr,
    (hkcdDynamicTree::DefaultTree48Storage *)&v4,
    a4);
}

