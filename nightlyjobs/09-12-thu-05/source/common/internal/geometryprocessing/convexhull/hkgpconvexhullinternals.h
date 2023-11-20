// File Line: 233
// RVA: 0xCB4120
void __fastcall hkgpConvexHullImpl::hkgpConvexHullImpl(hkgpConvexHullImpl *this)
{
  hkgpConvexHullImpl *v1; // rbx

  v1 = this;
  hkgpConvexHull::BuildConfig::BuildConfig(&this->m_config);
  *(_DWORD *)&v1->m_mesh.m_memSizeAndFlags = 0x1FFFF;
  v1->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::`vftable;
  v1->m_mesh.m_vertices.m_allocator.m_firstPool = 0i64;
  v1->m_mesh.m_vertices.m_used = 0i64;
  v1->m_mesh.m_vertices.m_numUsed = 0;
  v1->m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
  v1->m_mesh.m_triangles.m_used = 0i64;
  v1->m_mesh.m_triangles.m_numUsed = 0;
  v1->m_pendings.m_data = 0i64;
  v1->m_pendings.m_size = 0;
  v1->m_pendings.m_capacityAndFlags = 2147483648;
  v1->m_planes.m_data = 0i64;
  v1->m_planes.m_size = 0;
  v1->m_planes.m_capacityAndFlags = 2147483648;
  v1->m_supportCache.m_data = 0i64;
  v1->m_supportCache.m_size = 0;
  v1->m_supportCache.m_capacityAndFlags = 2147483648;
  v1->m_uid = _InterlockedExchangeAdd((volatile signed __int32 *)&hkgpConvexHullImpl::g_uidGenerator, 1u);
  hkgpConvexHullImpl::reset(v1, 0);
}

// File Line: 241
// RVA: 0xCB4220
void __fastcall hkgpConvexHullImpl::~hkgpConvexHullImpl(hkgpConvexHullImpl *this)
{
  hkgpConvexHullImpl *v1; // rdi
  int v2; // eax
  int v3; // er8
  int v4; // er8

  v1 = this;
  hkgpConvexHullImpl::reset(this, 0);
  v2 = v1->m_supportCache.m_capacityAndFlags;
  v1->m_supportCache.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_supportCache.m_data,
      48 * (v2 & 0x3FFFFFFF));
  v1->m_supportCache.m_data = 0i64;
  v1->m_supportCache.m_capacityAndFlags = 2147483648;
  v3 = v1->m_planes.m_capacityAndFlags;
  v1->m_planes.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_planes.m_data,
      16 * v3);
  v1->m_planes.m_data = 0i64;
  v1->m_planes.m_capacityAndFlags = 2147483648;
  v4 = v1->m_pendings.m_capacityAndFlags;
  v1->m_pendings.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_pendings.m_data,
      v4 << 6);
  v1->m_pendings.m_data = 0i64;
  v1->m_pendings.m_capacityAndFlags = 2147483648;
  v1->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::`vftable;
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *)&v1->m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v1->m_mesh.m_triangles);
  hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::reset(&v1->m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>(&v1->m_mesh.m_vertices.m_allocator);
  v1->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 247
// RVA: 0xCB8870
void __fastcall hkgpConvexHullImpl::reset(hkgpConvexHullImpl *this, bool keepPlane)
{
  hkgpConvexHullImpl *v2; // rdi
  bool v3; // bl
  __m128 v4; // xmm2

  v2 = this;
  v3 = keepPlane;
  this->m_mesh.vfptr[1].__first_virtual_table_function__((hkBaseObject *)&this->m_mesh);
  v2->m_planes.m_size = 0;
  v2->m_pendings.m_size = 0;
  v2->m_supportCache.m_size = 0;
  v2->m_centroids[0] = 0i64;
  v2->m_centroids[1] = 0i64;
  v2->m_centroids[0].m_quad = _mm_shuffle_ps(
                                (__m128)0i64,
                                _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712A0),
                                196);
  v2->m_centroids[1].m_quad = _mm_shuffle_ps(
                                (__m128)0i64,
                                _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712A0),
                                196);
  v2->m_boundingBoxes[0].m_min = (hkVector4f)xmmword_141A712A0;
  v4 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v2->m_boundingBoxes[0].m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v4);
  v2->m_boundingBoxes[1].m_min = (hkVector4f)xmmword_141A712A0;
  v2->m_boundingBoxes[1].m_max.m_quad = _mm_xor_ps(v4, (__m128)xmmword_141A712A0);
  *(_WORD *)&v2->m_hasMassProperties = 0;
  v2->m_hasIndexing = 0;
  v2->m_pid = 0;
  v2->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v2->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v2->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v2->m_localTransform.m_translation = 0i64;
  v2->m_inertia = 0i64;
  v2->m_inertiaMatrix.m_col0 = (hkVector4f)transform.m_quad;
  v2->m_inertiaMatrix.m_col1 = (hkVector4f)direction.m_quad;
  v2->m_inertiaMatrix.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v2->m_projectionAxis = 0i64;
  v2->m_volume = 0i64;
  v2->m_dimensions = -1;
  v2->m_surface = 0i64;
  v2->m_scale = 0i64;
  v2->m_scaleInv = 0i64;
  v2->m_origin = 0i64;
  if ( !v3 )
    v2->m_projectionPlane = 0i64;
}

// File Line: 280
// RVA: 0xCB48F0
hkgpConvexHullImpl *__fastcall hkgpConvexHullImpl::clone(hkgpConvexHullImpl *this)
{
  hkgpConvexHullImpl *v1; // r14
  _QWORD **v2; // rax
  hkgpConvexHullImpl *v3; // rax
  __int64 v4; // rax
  __int64 v5; // r12
  bool v6; // al
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  __int64 v12; // rdx
  _DWORD *v13; // rcx
  int v14; // er9
  __int64 v15; // r8
  hkgpConvexHullImpl::Vertex *v16; // rdx
  __int64 v17; // rcx
  int v18; // edi
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int v22; // er8
  __int64 v23; // rdx
  int v24; // er8
  unsigned __int64 v25; // rbx
  _QWORD *v26; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v27; // rax
  unsigned __int64 v28; // r9
  __int64 v29; // rax
  int v30; // er8
  hkgpConvexHullImpl::Triangle *v31; // r14
  hkgpConvexHullImpl::Triangle *v32; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v33; // rax
  signed __int64 v34; // rsi
  unsigned __int64 *v35; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v36; // rdi
  unsigned __int64 v37; // rax
  signed int v38; // ebx
  unsigned __int64 v39; // rax
  unsigned int v40; // ebp
  unsigned __int64 v41; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v43; // [rsp+30h] [rbp-48h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v44; // [rsp+40h] [rbp-38h]
  hkResult result; // [rsp+80h] [rbp+8h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHullImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 496i64);
  if ( v3 )
  {
    hkgpConvexHullImpl::hkgpConvexHullImpl(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  *(_DWORD *)v5 = *(_DWORD *)&v1->m_config.m_allowLowerDimensions.m_bool;
  *(float *)(v5 + 4) = v1->m_config.m_minCosAngle;
  *(_DWORD *)(v5 + 8) = *(_DWORD *)&v1->m_config.m_setSourceIndices.m_bool;
  *(_DWORD *)(v5 + 12) = *(_DWORD *)&v1->m_config.m_internalInputs.m_bool;
  *(hkVector4f *)(v5 + 240) = v1->m_projectionAxis;
  *(hkVector4f *)(v5 + 256) = v1->m_projectionPlane;
  *(hkVector4f *)(v5 + 272) = v1->m_origin;
  *(hkVector4f *)(v5 + 288) = v1->m_scale;
  *(hkVector4f *)(v5 + 304) = v1->m_scaleInv;
  *(hkVector4f *)(v5 + 320) = v1->m_localTransform.m_rotation.m_col0;
  *(hkVector4f *)(v5 + 336) = v1->m_localTransform.m_rotation.m_col1;
  *(hkVector4f *)(v5 + 352) = v1->m_localTransform.m_rotation.m_col2;
  *(hkVector4f *)(v5 + 368) = v1->m_localTransform.m_translation;
  *(hkVector4f *)(v5 + 384) = v1->m_inertia;
  *(hkSimdFloat32 *)(v5 + 448) = v1->m_volume;
  *(hkSimdFloat32 *)(v5 + 464) = v1->m_surface;
  *(_DWORD *)(v5 + 480) = v1->m_dimensions;
  *(_DWORD *)(v5 + 484) = v1->m_pid;
  *(_BYTE *)(v5 + 492) = v1->m_hasMassProperties;
  v6 = v1->m_hasIndexing;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_BYTE *)(v5 + 494) = v6;
  v7 = v1->m_pendings.m_size;
  v8 = *(_DWORD *)(v5 + 100) & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v1->m_pendings.m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v5 + 88),
      v10,
      64);
  }
  v11 = v7 - *(_DWORD *)(v5 + 96);
  v12 = v11;
  if ( v11 > 0 )
  {
    v13 = (_DWORD *)(*(_QWORD *)(v5 + 88) + ((signed __int64)*(signed int *)(v5 + 96) << 6) + 52);
    do
    {
      if ( v13 != (_DWORD *)52 )
      {
        *(v13 - 2) = 0;
        *v13 = -1;
      }
      v13 += 16;
      --v12;
    }
    while ( v12 );
  }
  *(_DWORD *)(v5 + 96) = v7;
  v14 = 0;
  if ( v1->m_pendings.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v1->m_pendings.m_data;
      v17 = *(_QWORD *)(v5 + 88);
      ++v14;
      ++v15;
      *(_OWORD *)(v15 * 64 + v17 - 48) = *((_OWORD *)&v16[v15] - 3);
      *(_DWORD *)(v15 * 64 + v17 - 32) = *((_DWORD *)&v16[v15] - 8);
      *(_DWORD *)(v15 * 64 + v17 - 28) = *((_DWORD *)&v16[v15] - 7);
      *(_DWORD *)(v15 * 64 + v17 - 24) = *((_DWORD *)&v16[v15] - 6);
      *(_DWORD *)(v15 * 64 + v17 - 20) = *((_DWORD *)&v16[v15] - 5);
      *(_DWORD *)(v15 * 64 + v17 - 16) = *((_DWORD *)&v16[v15] - 4);
      *(_DWORD *)(v15 * 64 + v17 - 12) = *((_DWORD *)&v16[v15] - 3);
    }
    while ( v14 < v1->m_pendings.m_size );
  }
  v18 = v1->m_planes.m_size;
  v19 = *(_DWORD *)(v5 + 116) & 0x3FFFFFFF;
  if ( v19 < v18 )
  {
    v20 = 2 * v19;
    v21 = v1->m_planes.m_size;
    if ( v18 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v5 + 104),
      v21,
      16);
  }
  *(_DWORD *)(v5 + 112) = v18;
  v22 = 0;
  if ( v1->m_planes.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      ++v22;
      ++v23;
      *(hkVector4f *)(v23 * 16 + *(_QWORD *)(v5 + 104) - 16) = v1->m_planes.m_data[v23 - 1];
    }
    while ( v22 < v1->m_planes.m_size );
  }
  v24 = v1->m_mesh.m_vertices.m_numUsed;
  v44.m_elem = 0i64;
  v44.m_numElems = 0;
  v44.m_hashMod = -1;
  if ( v24 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v44,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v24);
    v25 = (unsigned __int64)v1->m_mesh.m_vertices.m_used;
    if ( v25 )
    {
      v26 = *(_QWORD **)v25;
      if ( *(_QWORD *)v25 )
      {
        do
        {
          v25 = (unsigned __int64)v26;
          v26 = (_QWORD *)*v26;
        }
        while ( v26 );
      }
      for ( ; v25; v25 = *(_QWORD *)(v25 + 8) )
      {
        v27 = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool **)(v5 + 40);
        if ( !v27 || !v27->m_free )
          v27 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> *)(v5 + 40));
        if ( v27 )
        {
          v28 = (unsigned __int64)v27->m_free;
          v27->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v28;
          *(_QWORD *)(v28 + 64) = v27;
          ++v27->m_used;
          *(_OWORD *)(v28 + 16) = *(_OWORD *)(v25 + 16);
          *(_DWORD *)(v28 + 32) = *(_DWORD *)(v25 + 32);
          *(_DWORD *)(v28 + 36) = *(_DWORD *)(v25 + 36);
          *(_DWORD *)(v28 + 40) = *(_DWORD *)(v25 + 40);
          *(_DWORD *)(v28 + 44) = *(_DWORD *)(v25 + 44);
          *(_DWORD *)(v28 + 48) = *(_DWORD *)(v25 + 48);
          *(_DWORD *)(v28 + 52) = *(_DWORD *)(v25 + 52);
          *(_QWORD *)(v28 + 8) = 0i64;
          *(_QWORD *)v28 = *(_QWORD *)(v5 + 48);
          v29 = *(_QWORD *)(v5 + 48);
          if ( v29 )
            *(_QWORD *)(v29 + 8) = v28;
          ++*(_DWORD *)(v5 + 56);
          *(_QWORD *)(v5 + 48) = v28;
        }
        else
        {
          v28 = 0i64;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v44,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v25,
          v28);
      }
    }
  }
  v30 = v1->m_mesh.m_triangles.m_numUsed;
  if ( v30 )
  {
    v43.m_elem = 0i64;
    v43.m_numElems = 0;
    v43.m_hashMod = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v43,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v30);
    v31 = v1->m_mesh.m_triangles.m_used;
    if ( v31 )
    {
      v32 = v31->m_next;
      if ( v31->m_next )
      {
        do
        {
          v31 = v32;
          v32 = v32->m_next;
        }
        while ( v32 );
      }
      for ( ; v31; v31 = v31->m_prev )
      {
        v33 = hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Triangle,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>>::allocate(
                (hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Triangle,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator> > *)(v5 + 64),
                v31);
        v34 = 3i64;
        v35 = (unsigned __int64 *)&v33->m_items[0].m_data[16];
        v36 = v33;
        do
        {
          v37 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v44,
                  *v35,
                  0i64);
          ++v35;
          *(v35 - 1) = v37;
          --v34;
        }
        while ( v34 );
        v38 = 0;
        do
        {
          v39 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v43,
                  (*(_QWORD *)&v36->m_items[0].m_data[8 * v38 + 40] & 0xFFFFFFFFFFFFFFFCui64)
                + (*(_QWORD *)&v36->m_items[0].m_data[8 * v38 + 40] & 3i64),
                  0i64);
          v40 = v39 & 3;
          v41 = v39 & 0xFFFFFFFFFFFFFFFCui64;
          if ( v39 & 0xFFFFFFFFFFFFFFFCui64 )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
              &v43,
              &result,
              (*(_QWORD *)&v36->m_items[0].m_data[8 * v38 + 40] & 0xFFFFFFFFFFFFFFFCui64)
            + (*(_QWORD *)&v36->m_items[0].m_data[8 * v38 + 40] & 3i64));
            *(_QWORD *)&v36->m_items[0].m_data[8 * v38 + 40] = v41 + v40;
            *(_QWORD *)(v41 + 8i64 * (signed int)v40 + 40) = (char *)v36 + (unsigned int)v38;
          }
          else
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v43,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (unsigned __int64)v31 + (unsigned int)v38,
              (unsigned __int64)v36 + (unsigned int)v38);
          }
          ++v38;
        }
        while ( v38 < 3 );
      }
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v43,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v43);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v44,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v44);
  return (hkgpConvexHullImpl *)v5;
}

// File Line: 553
// RVA: 0xCB8300
void __fastcall hkgpConvexHullImpl::rebuildDomainParameters(hkgpConvexHullImpl *this, hkVector4f *points, const int numPoints)
{
  __m128 v3; // xmm7
  hkgpConvexHullImpl *v4; // rbx
  __m128 v5; // xmm6
  hkVector4f *v6; // rdx
  __int64 v7; // r8
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  __m128i v10; // xmm2
  __m128 v11; // xmm1
  __m128i v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  hkErrStream v16; // [rsp+20h] [rbp-248h]
  char buf; // [rsp+40h] [rbp-228h]

  if ( numPoints )
  {
    v3 = points->m_quad;
    v4 = this;
    v5 = points->m_quad;
    if ( numPoints > 1 )
    {
      v6 = points + 1;
      v7 = (unsigned int)(numPoints - 1);
      do
      {
        v3 = _mm_min_ps(v3, v6->m_quad);
        v5 = _mm_max_ps(v5, v6->m_quad);
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    if ( ((unsigned __int8)_mm_movemask_ps(_mm_cmpltps((__m128)xmmword_141A712A0, v5)) | (unsigned __int8)_mm_movemask_ps(_mm_cmpltps(v3, _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0)))) & 7 )
    {
      hkErrStream::hkErrStream(&v16, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v16.vfptr, "Input domain out of range");
      if ( (unsigned int)hkError::messageError(
                           1079648628,
                           &buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           572) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    }
    v8 = _mm_mul_ps(_mm_max_ps(_mm_sub_ps(v5, v3), (__m128)_xmm), (__m128)xmmword_141A711B0);
    v9 = _mm_rcp_ps(v8);
    v10 = (__m128i)_mm_add_ps(v8, v3);
    v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v9)), v9);
    v4->m_origin = (hkVector4f)v10;
    v12 = (__m128i)_mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, query.m_quad), 196);
    v4->m_scale = (hkVector4f)v12;
    _mm_store_si128((__m128i *)&v4->m_origin, _mm_srli_si128(_mm_slli_si128(v10, 4), 4));
    _mm_store_si128((__m128i *)&v4->m_scale, _mm_srli_si128(_mm_slli_si128(v12, 4), 4));
    v13 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_8191_0), (__m128)LODWORD(FLOAT_8191_0), 0),
            v4->m_scale.m_quad);
    v14 = _mm_rcp_ps(v13);
    v4->m_scale.m_quad = v13;
    v15 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v14)), v14);
    v4->m_scaleInv.m_quad = v15;
    v4->m_scaleInv.m_quad = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, query.m_quad), 196);
  }
}

// File Line: 601
// RVA: 0xCC3FE0
void __fastcall hkgpConvexHullImpl::computeProjectionPlane(hkgpConvexHullImpl *this, hkVector4f *points, int numPoints, hkVector4f *planeOut)
{
  int v4; // edi
  hkVector4f *v5; // rbp
  signed __int64 v6; // rbx
  float v7; // xmm5_4
  float v8; // xmm7_4
  int v9; // er10
  __int64 v10; // r11
  __m128 i; // xmm8
  int v12; // ecx
  signed __int64 v13; // rdx
  __m128 v14; // xmm4
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  hkVector4f v18; // xmm3
  __m128 v19; // xmm1
  float v20; // xmm2_4
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm2

  v4 = 0;
  v5 = points;
  v6 = 0i64;
  *planeOut = 0i64;
  v7 = 0.0;
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_0000099999997),
                                     (__m128)LODWORD(FLOAT_0_0000099999997),
                                     0);
  if ( numPoints > 0 )
  {
    do
    {
      v9 = v4 + 1;
      v10 = v4 + 1;
      for ( i = v5[v6].m_quad; v9 < numPoints; ++v10 )
      {
        v12 = v9 + 1;
        v13 = v10 + 1;
        v14 = _mm_sub_ps(v5[v10].m_quad, i);
        if ( v9 + 1 < numPoints )
        {
          v15 = _mm_shuffle_ps(v14, v14, 201);
          do
          {
            v16 = _mm_sub_ps(v5[v13].m_quad, i);
            v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v14), _mm_mul_ps(v15, v16));
            v18.m_quad = _mm_shuffle_ps(v17, v17, 201);
            v19 = _mm_mul_ps(v18.m_quad, v18.m_quad);
            v20 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170));
            if ( v20 > v7 )
            {
              *planeOut = (hkVector4f)v18.m_quad;
              v7 = v20;
              if ( v20 > v8 )
              {
                v12 = numPoints;
                v13 = numPoints;
                v9 = numPoints;
                v10 = numPoints;
                v4 = numPoints;
                v6 = numPoints;
              }
            }
            ++v12;
            ++v13;
          }
          while ( v12 < numPoints );
        }
        ++v9;
      }
      ++v6;
      ++v4;
    }
    while ( v6 < numPoints );
  }
  v21 = _mm_mul_ps(planeOut->m_quad, planeOut->m_quad);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v22), (__m128)0i64);
  planeOut->m_quad = _mm_or_ps(
                       _mm_and_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpleps(v22, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                               _mm_mul_ps(*(__m128 *)_xmm, v23))),
                           planeOut->m_quad),
                         v24),
                       _mm_andnot_ps(v24, planeOut->m_quad));
  if ( !_mm_movemask_ps(v24) )
    *planeOut = (hkVector4f)transform.m_quad;
  v25 = _mm_mul_ps(planeOut->m_quad, v5->m_quad);
  planeOut->m_quad = _mm_shuffle_ps(
                       planeOut->m_quad,
                       _mm_unpackhi_ps(
                         planeOut->m_quad,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                             _mm_shuffle_ps(v25, v25, 170)))),
                       196);
}

// File Line: 642
// RVA: 0xCC4200
char __fastcall hkgpConvexHullImpl::flushPending(hkgpConvexHullImpl *this)
{
  int v1; // esi
  char v2; // di
  hkgpConvexHullImpl *v3; // r15
  int v4; // edx
  hkgpConvexHullImpl::Vertex *v5; // rax
  unsigned int v6; // xmm1_4
  unsigned int v7; // xmm0_4
  int v8; // eax
  __int64 v9; // rbx
  unsigned int v10; // er12
  unsigned int v11; // er13
  unsigned int *v12; // rcx
  int v13; // eax
  __int64 v14; // r11
  int v15; // er10
  int v16; // er9
  int v17; // edx
  unsigned int *v18; // r14
  int v19; // er8
  int v20; // edi
  int v21; // ecx
  int v22; // eax
  hkgpConvexHullImpl::Triangle *v23; // rdi
  int v24; // er12
  int v25; // er13
  hkBaseObjectVtbl *v26; // rdx
  __int64 v27; // r12
  signed __int64 v28; // rax
  signed __int64 v29; // r10
  bool v30; // zf
  __m128i v31; // xmm0
  __m128i v32; // xmm2
  __m128i v33; // xmm5
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v34; // r14
  __m128i v35; // xmm1
  __m128i v36; // xmm4
  __m128 v37; // xmm0
  __m128i v38; // xmm2
  __m128 v39; // xmm1
  __m128i v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm0
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm5
  __m128 v54; // xmm1
  int v55; // er9
  __int64 v56; // r8
  hkgpConvexHullImpl::Vertex *v57; // rax
  __int64 v58; // r13
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v59; // rax
  __int64 v60; // r12
  hkgpConvexHullImpl::Vertex *v61; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v62; // rax
  __int64 v63; // rbx
  hkgpConvexHullImpl::Vertex *v64; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v65; // rax
  hkgpConvexHullImpl::Vertex *v66; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v67; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v68; // rsi
  hkgpConvexHullImpl::Vertex *v69; // rax
  hkgpConvexHullImpl::Vertex *v70; // rcx
  __int64 v71; // rdx
  int v72; // eax
  hkgpConvexHullImpl::Vertex *v73; // rcx
  __int64 v74; // rdx
  int v75; // eax
  __int64 v76; // rdx
  hkgpConvexHullImpl::Vertex *v77; // rcx
  bool v78; // sf
  int v79; // eax
  hkgpConvexHullImpl::Vertex *v80; // rcx
  int v81; // eax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v82; // rax
  signed __int64 v83; // rdi
  __int64 v84; // rdx
  hkgpConvexHullImpl::Triangle *v85; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v86; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v87; // r13
  hkgpConvexHullImpl::Triangle *v88; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v89; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v90; // r12
  hkgpConvexHullImpl::Triangle *v91; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v92; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v93; // r15
  __int64 v94; // rax
  __int64 v95; // rdi
  signed int *v96; // rax
  signed int v97; // ecx
  signed int v98; // edx
  int v99; // er8
  int v100; // er9
  int v101; // er10
  int v102; // er11
  int v103; // edx
  int v104; // ecx
  __int64 v105; // rdi
  int v106; // edx
  signed int *v107; // r8
  int v108; // eax
  signed int v109; // ecx
  signed int v110; // edx
  signed int v111; // eax
  int v112; // er9
  int v113; // er8
  int v114; // er10
  int v115; // er11
  int v116; // edx
  int v117; // ecx
  int v118; // edi
  signed int *v119; // r8
  int v120; // edi
  signed int v121; // edx
  signed int v122; // ecx
  signed int v123; // eax
  int v124; // er9
  int v125; // er10
  int v126; // er8
  int v127; // er11
  int v128; // edx
  int v129; // ecx
  int v130; // eax
  int v131; // edx
  int v132; // edi
  int v133; // eax
  _QWORD *v134; // rdi
  int v135; // ecx
  int v136; // er10
  int v137; // er8
  int v138; // er9
  int v139; // er11
  int v140; // eax
  int v141; // esi
  int v142; // edx
  int v143; // esi
  int v144; // er14
  signed __int64 v145; // r8
  char *v146; // rcx
  signed __int64 v147; // rdx
  __int64 v148; // rax
  signed __int64 v149; // r8
  __int64 v150; // rcx
  signed __int64 v151; // rdx
  __int64 v152; // rax
  signed __int64 v153; // r8
  __int64 v154; // rcx
  signed __int64 v155; // rdx
  __int64 v156; // rax
  signed __int64 v157; // r8
  __int64 v158; // rcx
  signed __int64 v159; // rdx
  __int64 v160; // rax
  hkgpConvexHullImpl::Triangle *v162; // rbx
  signed __int64 v163; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v164; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v165; // rsi
  hkgpConvexHullImpl::Vertex *v166; // rax
  __int128 v167; // xmm0
  int v168; // eax
  int v169; // eax
  unsigned int v170; // ecx
  unsigned __int64 v171; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v172; // r14
  unsigned __int64 v173; // r9
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v174; // r13
  char v175; // cl
  int v176; // er8
  __int64 v177; // rcx
  __m128i v178; // xmm0
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v179; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v180; // rdi
  hkgpConvexHullImpl::Triangle *v181; // rax
  _DWORD *v182; // r11
  _DWORD *v183; // r8
  int v184; // ebx
  int v185; // er14
  int v186; // ecx
  int v187; // er10
  int v188; // er9
  int v189; // ebx
  int v190; // eax
  int v191; // er14
  int v192; // er11
  int v193; // er12
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v194; // r11
  hkgpConvexHullImpl::Triangle *v195; // rax
  _DWORD *v196; // r9
  _DWORD *v197; // r8
  int v198; // er10
  int v199; // edi
  int v200; // ebx
  int v201; // edx
  int v202; // ecx
  int v203; // er9
  int v204; // edi
  int v205; // ebx
  int v206; // er8
  int v207; // [rsp+20h] [rbp-E0h]
  int v208; // [rsp+24h] [rbp-DCh]
  hkErrStream v209; // [rsp+30h] [rbp-D0h]
  int v210; // [rsp+50h] [rbp-B0h]
  signed int *v211; // [rsp+58h] [rbp-A8h]
  __int64 v212; // [rsp+60h] [rbp-A0h]
  __int64 v213; // [rsp+68h] [rbp-98h]
  __int64 i; // [rsp+70h] [rbp-90h]
  int v215; // [rsp+78h] [rbp-88h]
  __int64 v216; // [rsp+80h] [rbp-80h]
  __m128i v217; // [rsp+90h] [rbp-70h]
  int v218; // [rsp+A0h] [rbp-60h]
  unsigned int *v219; // [rsp+A8h] [rbp-58h]
  __m128i v220; // [rsp+B0h] [rbp-50h]
  hkgpConvexHullImpl::Edge root; // [rsp+C0h] [rbp-40h]
  __m128i v222; // [rsp+D0h] [rbp-30h]
  unsigned int v223; // [rsp+100h] [rbp+0h]
  unsigned int v224; // [rsp+104h] [rbp+4h]
  unsigned int v225; // [rsp+108h] [rbp+8h]
  char buf; // [rsp+120h] [rbp+20h]
  hkgpConvexHullImpl *v227; // [rsp+390h] [rbp+290h]
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v228; // [rsp+390h] [rbp+290h]
  char v229; // [rsp+398h] [rbp+298h]
  int v230; // [rsp+398h] [rbp+298h]
  int v231; // [rsp+398h] [rbp+298h]
  int v232; // [rsp+398h] [rbp+298h]
  int v233; // [rsp+3A0h] [rbp+2A0h]
  unsigned __int64 v234; // [rsp+3A0h] [rbp+2A0h]
  int v235; // [rsp+3A8h] [rbp+2A8h]

  v227 = this;
  v1 = this->m_pendings.m_size;
  v2 = 0;
  v3 = this;
  v218 = v1;
  v229 = 0;
  if ( v1 < 4 )
  {
    hkErrStream::hkErrStream(&v209, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v209.vfptr, "Internal error");
    if ( (unsigned int)hkError::messageError(
                         1680669032,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         647) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v209.vfptr);
  }
  v3->m_projectionPlane = 0i64;
  v4 = 0;
  v210 = 0;
  if ( v1 > 0 )
  {
    do
    {
      v216 = v4;
      v5 = &v3->m_pendings.m_data[(signed __int64)v4];
      v6 = v5->m_x[1];
      v223 = v5->m_x[0];
      v7 = v5->m_x[2];
      v224 = v6;
      v8 = v4 + 1;
      v9 = v4 + 1;
      v235 = v4 + 1;
      v213 = v4 + 1;
      v225 = v7;
      if ( v4 + 1 < v1 )
      {
        v10 = v225;
        v11 = v224;
        do
        {
          v12 = (unsigned int *)&v3->m_pendings.m_data[v9];
          v13 = v8 + 1;
          v14 = v13;
          v219 = (unsigned int *)&v3->m_pendings.m_data[v9];
          v233 = v13;
          for ( i = v13; v233 < v1; i = v14 )
          {
            v15 = v12[8] - v223;
            v16 = v12[9] - v11;
            v17 = v12[10] - v10;
            v18 = (unsigned int *)&v3->m_pendings.m_data[v14];
            v19 = v18[8] - v223;
            v20 = v18[9] - v11;
            v21 = v18[10] - v10;
            v22 = v20;
            LODWORD(v23) = v15 * v20 - v16 * v19;
            v24 = v16 * v21 - v17 * v22;
            v25 = v17 * v19 - v15 * v21;
            if ( v24 | v25 | (unsigned int)v23 )
            {
              v26 = (hkBaseObjectVtbl *)v24;
              v23 = (hkgpConvexHullImpl::Triangle *)(signed int)v23;
              v217.m128i_i64[0] = v25;
              v27 = v25;
              root.m_triangle = v23;
              v209.vfptr = v26;
              v28 = (signed int)v23 * (signed __int64)(signed int)v225;
              v29 = -(v28 + v25 * (signed __int64)(signed int)v224 + (_QWORD)v26 * (signed int)v223);
              v30 = v3->m_config.m_allowLowerDimensions.m_bool == 0;
              v220.m128i_i64[0] = -(v28 + v25 * (signed __int64)(signed int)v224 + (_QWORD)v26 * (signed int)v223);
              if ( v30 )
              {
                v34 = 0i64;
              }
              else
              {
                v31 = _mm_cvtsi32_si128(v18[10]);
                v32 = _mm_cvtsi32_si128(v18[9]);
                v33 = _mm_cvtsi32_si128(v18[8]);
                v34 = 0i64;
                v35 = _mm_cvtsi32_si128(0);
                v36 = _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(v219[8]), _mm_cvtsi32_si128(v219[10])),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(v219[9]), v35));
                v37 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(v33, v31),
                                               _mm_unpacklo_epi32(v32, v35))),
                                  4),
                                4);
                v38 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v224), v35);
                v39 = v3->m_scaleInv.m_quad;
                v40 = _mm_unpacklo_epi32(_mm_unpacklo_epi32(_mm_cvtsi32_si128(v223), _mm_cvtsi32_si128(v225)), v38);
                v41 = v3->m_origin.m_quad;
                v42 = _mm_add_ps(
                        _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v40), 4), 4), v39),
                        v41);
                v43 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v37, v39), v41), v42);
                v44 = _mm_sub_ps(
                        _mm_add_ps(
                          _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v36), 4), 4), v39),
                          v41),
                        v42);
                v45 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v44),
                        _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v43));
                v46 = _mm_shuffle_ps(v45, v45, 201);
                v47 = _mm_mul_ps(v46, v46);
                v48 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                        _mm_shuffle_ps(v47, v47, 170));
                v49 = _mm_rsqrt_ps(v48);
                v50 = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v48, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                            _mm_mul_ps(*(__m128 *)_xmm, v49))),
                        v46);
                v51 = _mm_mul_ps(v50, v42);
                v52 = _mm_mul_ps(v3->m_projectionPlane.m_quad, v3->m_projectionPlane.m_quad);
                v53 = _mm_shuffle_ps(
                        v50,
                        _mm_unpackhi_ps(
                          v50,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                              _mm_shuffle_ps(v51, v51, 170)))),
                        196);
                v54 = _mm_mul_ps(v53, v53);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 170))) > (float)((float)(COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v52,
                                                                                                v52,
                                                                                                85))
                                                                                          + COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v52,
                                                                                                v52,
                                                                                                0)))
                                                                                  + COERCE_FLOAT(_mm_shuffle_ps(v52, v52, 170))) )
                  v3->m_projectionPlane.m_quad = v53;
              }
              v55 = v233 + 1;
              v215 = v233 + 1;
              v56 = v233 + 1;
              if ( v233 + 1 < v1 )
              {
                while ( 1 )
                {
                  v57 = v3->m_pendings.m_data;
                  v58 = v56 << 6;
                  v222.m128i_i64[0] = v56 << 6;
                  v212 = (_QWORD)v26 * v57[v56].m_x[0] + v29 + v27 * v57[v56].m_x[1] + (_QWORD)v23 * v57[v56].m_x[2];
                  if ( v212 )
                  {
                    v59 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !v59 || !v59->m_free )
                      v59 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v59 )
                    {
                      v60 = (__int64)v59->m_free->m_data;
                      v59->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v60;
                      *(_QWORD *)(v60 + 64) = v59;
                      ++v59->m_used;
                      *(_DWORD *)(v60 + 44) = 0;
                      *(_DWORD *)(v60 + 52) = -1;
                      *(_QWORD *)(v60 + 8) = 0i64;
                      *(_QWORD *)v60 = v3->m_mesh.m_vertices.m_used;
                      v61 = v3->m_mesh.m_vertices.m_used;
                      if ( v61 )
                        v61->m_prev = (hkgpConvexHullImpl::Vertex *)v60;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v60;
                    }
                    else
                    {
                      v60 = 0i64;
                    }
                    v62 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    v211 = (signed int *)v60;
                    if ( !v62 || !v62->m_free )
                      v62 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v62 )
                    {
                      v63 = (__int64)v62->m_free->m_data;
                      v62->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v63;
                      *(_QWORD *)(v63 + 64) = v62;
                      ++v62->m_used;
                      *(_DWORD *)(v63 + 44) = 0;
                      *(_DWORD *)(v63 + 52) = -1;
                      *(_QWORD *)(v63 + 8) = 0i64;
                      *(_QWORD *)v63 = v3->m_mesh.m_vertices.m_used;
                      v64 = v3->m_mesh.m_vertices.m_used;
                      if ( v64 )
                        v64->m_prev = (hkgpConvexHullImpl::Vertex *)v63;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v63;
                    }
                    else
                    {
                      v63 = 0i64;
                    }
                    v65 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !v65 || !v65->m_free )
                      v65 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v65 )
                    {
                      v34 = v65->m_free;
                      v65->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v34->m_data;
                      v34->m_pool = v65;
                      ++v65->m_used;
                      *(_DWORD *)&v34->m_data[52] = -1;
                      *(_DWORD *)&v34->m_data[44] = 0;
                      *(_QWORD *)&v34->m_data[8] = 0i64;
                      *(_QWORD *)v34->m_data = v3->m_mesh.m_vertices.m_used;
                      v66 = v3->m_mesh.m_vertices.m_used;
                      if ( v66 )
                        v66->m_prev = (hkgpConvexHullImpl::Vertex *)v34;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v34;
                    }
                    v67 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !v67 || !v67->m_free )
                      v67 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v67 )
                    {
                      v68 = v67->m_free;
                      v67->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v68->m_data;
                      v68->m_pool = v67;
                      ++v67->m_used;
                      *(_DWORD *)&v68->m_data[44] = 0;
                      *(_DWORD *)&v68->m_data[52] = -1;
                      *(_QWORD *)&v68->m_data[8] = 0i64;
                      *(_QWORD *)v68->m_data = v3->m_mesh.m_vertices.m_used;
                      v69 = v3->m_mesh.m_vertices.m_used;
                      if ( v69 )
                        v69->m_prev = (hkgpConvexHullImpl::Vertex *)v68;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v68;
                    }
                    else
                    {
                      v68 = 0i64;
                    }
                    v70 = v3->m_pendings.m_data;
                    v71 = v216 << 6;
                    v216 = v71;
                    *(hkVector4f *)(v60 + 16) = *(hkVector4f *)((char *)&v70->m_source + v71);
                    *(_DWORD *)(v60 + 32) = *(int *)((char *)v70->m_x + v71);
                    *(_DWORD *)(v60 + 36) = *(int *)((char *)&v70->m_x[1] + v71);
                    *(_DWORD *)(v60 + 40) = *(int *)((char *)&v70->m_x[2] + v71);
                    *(float *)(v60 + 44) = *(float *)((char *)&v70->m_scratch + v71);
                    *(_DWORD *)(v60 + 48) = *(int *)((char *)&v70->m_refs + v71);
                    v72 = *(int *)((char *)&v70->m_index + v71);
                    *(_DWORD *)(v60 + 48) = 0;
                    *(_DWORD *)(v60 + 52) = v72;
                    v73 = v3->m_pendings.m_data;
                    v74 = v213 << 6;
                    v213 = v74;
                    *(hkVector4f *)(v63 + 16) = *(hkVector4f *)((char *)&v73->m_source + v74);
                    *(_DWORD *)(v63 + 32) = *(int *)((char *)v73->m_x + v74);
                    *(_DWORD *)(v63 + 36) = *(int *)((char *)&v73->m_x[1] + v74);
                    *(_DWORD *)(v63 + 40) = *(int *)((char *)&v73->m_x[2] + v74);
                    *(float *)(v63 + 44) = *(float *)((char *)&v73->m_scratch + v74);
                    *(_DWORD *)(v63 + 48) = *(int *)((char *)&v73->m_refs + v74);
                    v75 = *(int *)((char *)&v73->m_index + v74);
                    v76 = i;
                    *(_DWORD *)(v63 + 52) = v75;
                    *(_DWORD *)(v63 + 48) = 0;
                    v77 = v3->m_pendings.m_data;
                    v76 <<= 6;
                    v30 = v212 == 0;
                    v78 = v212 < 0;
                    i = v76;
                    *(hkVector4f *)&v34->m_data[16] = *(hkVector4f *)((char *)&v77->m_source + v76);
                    *(_DWORD *)&v34->m_data[32] = *(int *)((char *)v77->m_x + v76);
                    *(_DWORD *)&v34->m_data[36] = *(int *)((char *)&v77->m_x[1] + v76);
                    *(_DWORD *)&v34->m_data[40] = *(int *)((char *)&v77->m_x[2] + v76);
                    *(float *)&v34->m_data[44] = *(float *)((char *)&v77->m_scratch + v76);
                    *(_DWORD *)&v34->m_data[48] = *(int *)((char *)&v77->m_refs + v76);
                    v79 = *(int *)((char *)&v77->m_index + v76);
                    *(_DWORD *)&v34->m_data[48] = 0;
                    *(_DWORD *)&v34->m_data[52] = v79;
                    v80 = v3->m_pendings.m_data;
                    *(hkVector4f *)&v68->m_data[16] = *(hkVector4f *)((char *)&v80->m_source + v58);
                    *(_DWORD *)&v68->m_data[32] = *(int *)((char *)v80->m_x + v58);
                    *(_DWORD *)&v68->m_data[36] = *(int *)((char *)&v80->m_x[1] + v58);
                    *(_DWORD *)&v68->m_data[40] = *(int *)((char *)&v80->m_x[2] + v58);
                    *(float *)&v68->m_data[44] = *(float *)((char *)&v80->m_scratch + v58);
                    *(_DWORD *)&v68->m_data[48] = *(int *)((char *)&v80->m_refs + v58);
                    v81 = *(int *)((char *)&v80->m_index + v58);
                    *(_DWORD *)&v68->m_data[48] = 0;
                    *(_DWORD *)&v68->m_data[52] = v81;
                    if ( !v78 && !v30 )
                    {
                      v211 = (signed int *)v63;
                      v63 = v60;
                    }
                    v82 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v3->m_mesh.m_triangles.m_allocator.m_firstPool;
                    v83 = (signed __int64)&v3->m_mesh.m_triangles;
                    if ( !v82 || !v82->m_free )
                      v82 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v82 )
                    {
                      v84 = (__int64)v82->m_free->m_data;
                      v212 = v84;
                      v82->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v84;
                      *(_QWORD *)(v84 + 112) = v82;
                      ++v82->m_used;
                      *(_DWORD *)(v84 + 88) = -1;
                      *(_DWORD *)(v84 + 100) = -1;
                      *(_QWORD *)(v84 + 8) = 0i64;
                      *(_QWORD *)v84 = v3->m_mesh.m_triangles.m_used;
                      v85 = v3->m_mesh.m_triangles.m_used;
                      if ( v85 )
                        v85->m_prev = (hkgpConvexHullImpl::Triangle *)v84;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v84;
                    }
                    else
                    {
                      v212 = 0i64;
                    }
                    v86 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool **)v83;
                    if ( !*(_QWORD *)v83 || !v86->m_free )
                      v86 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v86 )
                    {
                      v87 = v86->m_free;
                      v86->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v87->m_data;
                      v87->m_pool = v86;
                      ++v86->m_used;
                      *(_DWORD *)&v87->m_data[88] = -1;
                      *(_DWORD *)&v87->m_data[100] = -1;
                      *(_QWORD *)&v87->m_data[8] = 0i64;
                      *(_QWORD *)v87->m_data = v3->m_mesh.m_triangles.m_used;
                      v88 = v3->m_mesh.m_triangles.m_used;
                      if ( v88 )
                        v88->m_prev = (hkgpConvexHullImpl::Triangle *)v87;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v87;
                    }
                    else
                    {
                      v87 = 0i64;
                    }
                    v89 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool **)v83;
                    if ( !*(_QWORD *)v83 || !v89->m_free )
                      v89 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v89 )
                    {
                      v90 = v89->m_free;
                      v89->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v90->m_data;
                      v90->m_pool = v89;
                      ++v89->m_used;
                      *(_DWORD *)&v90->m_data[88] = -1;
                      *(_DWORD *)&v90->m_data[100] = -1;
                      *(_QWORD *)&v90->m_data[8] = 0i64;
                      *(_QWORD *)v90->m_data = v3->m_mesh.m_triangles.m_used;
                      v91 = v3->m_mesh.m_triangles.m_used;
                      if ( v91 )
                        v91->m_prev = (hkgpConvexHullImpl::Triangle *)v90;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v90;
                    }
                    else
                    {
                      v90 = 0i64;
                    }
                    v92 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool **)v83;
                    if ( !*(_QWORD *)v83 || !v92->m_free )
                      v92 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v92 )
                    {
                      v93 = v92->m_free;
                      v92->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v93->m_data;
                      v93->m_pool = v92;
                      ++v92->m_used;
                      *(_DWORD *)&v93->m_data[88] = -1;
                      *(_DWORD *)&v93->m_data[100] = -1;
                      *(_QWORD *)&v93->m_data[8] = 0i64;
                      *(_QWORD *)v93->m_data = *(_QWORD *)(v83 + 8);
                      v94 = *(_QWORD *)(v83 + 8);
                      if ( v94 )
                        *(_QWORD *)(v94 + 8) = v93;
                      ++*(_DWORD *)(v83 + 16);
                      *(_QWORD *)(v83 + 8) = v93;
                    }
                    else
                    {
                      v93 = 0i64;
                    }
                    v95 = v212;
                    v96 = v211;
                    *(_QWORD *)(v212 + 16) = v211;
                    *(_DWORD *)(v95 + 96) = 0;
                    *(_QWORD *)(v95 + 24) = v63;
                    *(_QWORD *)(v95 + 32) = v34;
                    *(_DWORD *)(v95 + 100) = -1;
                    ++v96[12];
                    ++*(_DWORD *)(v63 + 48);
                    ++*(_DWORD *)&v34->m_data[48];
                    v97 = v96[9];
                    v98 = v96[8];
                    LODWORD(v96) = v96[10];
                    v99 = *(_DWORD *)(v63 + 40) - (_DWORD)v96;
                    v100 = *(_DWORD *)&v34->m_data[32] - v98;
                    v101 = *(_DWORD *)(v63 + 36) - v97;
                    v102 = *(_DWORD *)(v63 + 32) - v98;
                    v103 = *(_DWORD *)&v34->m_data[36] - v97;
                    v104 = *(_DWORD *)&v34->m_data[40] - (_DWORD)v96;
                    v230 = v101 * v104 - v99 * v103;
                    v105 = v212;
                    *(_DWORD *)(v212 + 64) = v230;
                    v106 = v102 * v103 - v101 * v100;
                    LODWORD(v96) = v99 * v100;
                    v107 = v211;
                    v108 = (_DWORD)v96 - v102 * v104;
                    *(_DWORD *)(v105 + 68) = v108;
                    *(_DWORD *)(v105 + 72) = v106;
                    *(_QWORD *)(v105 + 80) = 0i64;
                    if ( v230 | v108 | v106 )
                      *(_QWORD *)(v105 + 80) = -(v108 * (signed __int64)v107[9]
                                               + v106 * (signed __int64)v107[10]
                                               + v107[8] * (signed __int64)v230);
                    *(_QWORD *)&v87->m_data[16] = v107;
                    *(_DWORD *)&v87->m_data[96] = 0;
                    *(_QWORD *)&v87->m_data[24] = v68;
                    *(_QWORD *)&v87->m_data[32] = v63;
                    *(_DWORD *)&v87->m_data[100] = -1;
                    ++v107[12];
                    ++*(_DWORD *)&v68->m_data[48];
                    ++*(_DWORD *)(v63 + 48);
                    v109 = v107[9];
                    v110 = v107[8];
                    v111 = v107[10];
                    v112 = *(_DWORD *)(v63 + 32) - v110;
                    v113 = *(_DWORD *)&v68->m_data[40] - v111;
                    v114 = *(_DWORD *)&v68->m_data[36] - v109;
                    v115 = *(_DWORD *)&v68->m_data[32] - v110;
                    v116 = *(_DWORD *)(v63 + 36) - v109;
                    v117 = *(_DWORD *)(v63 + 40) - v111;
                    v231 = v114 * v117 - v113 * v116;
                    *(_DWORD *)&v87->m_data[64] = v231;
                    v118 = v113 * v112;
                    v119 = v211;
                    v120 = v118 - v115 * v117;
                    *(_DWORD *)&v87->m_data[68] = v120;
                    v207 = v115 * v116 - v114 * v112;
                    *(_DWORD *)&v87->m_data[72] = v207;
                    *(_QWORD *)&v87->m_data[80] = 0i64;
                    if ( v231 | v120 | v207 )
                      *(_QWORD *)&v87->m_data[80] = -(v120 * (signed __int64)v119[9]
                                                    + v207 * (signed __int64)v119[10]
                                                    + v119[8] * (signed __int64)v231);
                    *(_DWORD *)&v90->m_data[96] = 0;
                    *(_QWORD *)&v90->m_data[16] = v119;
                    *(_QWORD *)&v90->m_data[24] = v34;
                    *(_QWORD *)&v90->m_data[32] = v68;
                    *(_DWORD *)&v90->m_data[100] = -1;
                    ++v119[12];
                    ++*(_DWORD *)&v34->m_data[48];
                    ++*(_DWORD *)&v68->m_data[48];
                    v121 = v119[8];
                    v122 = v119[9];
                    v123 = v119[10];
                    v124 = *(_DWORD *)&v68->m_data[32] - v121;
                    v125 = *(_DWORD *)&v34->m_data[36] - v122;
                    v126 = *(_DWORD *)&v34->m_data[40] - v123;
                    v127 = *(_DWORD *)&v34->m_data[32] - v121;
                    v128 = *(_DWORD *)&v68->m_data[36] - v122;
                    v129 = *(_DWORD *)&v68->m_data[40] - v123;
                    v130 = v125 * v129 - v126 * v128;
                    v232 = v125 * v129 - v126 * v128;
                    v131 = v127 * v128 - v125 * v124;
                    v132 = v126 * v124 - v127 * v129;
                    *(_DWORD *)&v90->m_data[64] = v130;
                    v208 = v132;
                    *(_DWORD *)&v90->m_data[68] = v132;
                    v133 = v132 | v131;
                    v134 = (_QWORD *)v212;
                    *(_DWORD *)&v90->m_data[72] = v131;
                    *(_QWORD *)&v90->m_data[80] = 0i64;
                    if ( v232 | v133 )
                      *(_QWORD *)&v90->m_data[80] = -(v211[8] * (signed __int64)v232
                                                    + v211[9] * (signed __int64)v208
                                                    + v131 * (signed __int64)v211[10]);
                    *(_QWORD *)&v93->m_data[24] = v68;
                    *(_QWORD *)&v93->m_data[32] = v34;
                    *(_QWORD *)&v93->m_data[16] = v63;
                    *(_DWORD *)&v93->m_data[96] = 0;
                    *(_DWORD *)&v93->m_data[100] = -1;
                    ++*(_DWORD *)(v63 + 48);
                    ++*(_DWORD *)&v68->m_data[48];
                    ++*(_DWORD *)&v34->m_data[48];
                    v135 = *(_DWORD *)&v34->m_data[40] - *(_DWORD *)(v63 + 40);
                    v136 = *(_DWORD *)&v68->m_data[36] - *(_DWORD *)(v63 + 36);
                    v137 = *(_DWORD *)&v68->m_data[40] - *(_DWORD *)(v63 + 40);
                    v138 = *(_DWORD *)&v34->m_data[32] - *(_DWORD *)(v63 + 32);
                    v139 = *(_DWORD *)&v68->m_data[32] - *(_DWORD *)(v63 + 32);
                    v140 = v137 * (*(_DWORD *)&v34->m_data[36] - *(_DWORD *)(v63 + 36));
                    v141 = *(_DWORD *)&v34->m_data[40] - *(_DWORD *)(v63 + 40);
                    v142 = v139 * (*(_DWORD *)&v34->m_data[36] - *(_DWORD *)(v63 + 36)) - v136 * v138;
                    *(_DWORD *)&v93->m_data[72] = v142;
                    v143 = v136 * v141 - v140;
                    v144 = v137 * v138 - v139 * v135;
                    *(_QWORD *)&v93->m_data[80] = 0i64;
                    *(_DWORD *)&v93->m_data[64] = v143;
                    *(_DWORD *)&v93->m_data[68] = v144;
                    if ( v143 | v144 | v142 )
                      *(_QWORD *)&v93->m_data[80] = -(v144 * (signed __int64)*(signed int *)(v63 + 36)
                                                    + *(signed int *)(v63 + 32) * (signed __int64)v143
                                                    + *(signed int *)(v63 + 40) * (signed __int64)v142);
                    v134[5] = (char *)v87 + 2;
                    *(_QWORD *)&v87->m_data[56] = v134;
                    v134[6] = (char *)v93 + 2;
                    *(_QWORD *)&v93->m_data[56] = (char *)v134 + 1;
                    v134[7] = v90;
                    *(_QWORD *)&v90->m_data[40] = (char *)v134 + 2;
                    *(_QWORD *)&v87->m_data[40] = (char *)v90 + 2;
                    *(_QWORD *)&v90->m_data[56] = v87;
                    *(_QWORD *)&v90->m_data[48] = (char *)v93 + 1;
                    *(_QWORD *)&v93->m_data[48] = (char *)v90 + 1;
                    *(_QWORD *)&v93->m_data[40] = (char *)v87 + 1;
                    *(_QWORD *)&v87->m_data[48] = v93;
                    v3 = v227;
                    --v3->m_pendings.m_size;
                    if ( v227->m_pendings.m_size != v215 )
                    {
                      v145 = 8i64;
                      v146 = (char *)v227->m_pendings.m_data + v222.m128i_i64[0];
                      v147 = (char *)&v227->m_pendings.m_data[(signed __int64)v227->m_pendings.m_size] - v146;
                      do
                      {
                        v148 = *(_QWORD *)&v146[v147];
                        v146 += 8;
                        *((_QWORD *)v146 - 1) = v148;
                        --v145;
                      }
                      while ( v145 );
                    }
                    if ( --v227->m_pendings.m_size != v233 )
                    {
                      v149 = 8i64;
                      v150 = (__int64)v227->m_pendings.m_data + i;
                      v151 = (signed __int64)&v227->m_pendings.m_data[(signed __int64)v227->m_pendings.m_size] - v150;
                      do
                      {
                        v152 = *(_QWORD *)(v151 + v150);
                        v150 += 8i64;
                        *(_QWORD *)(v150 - 8) = v152;
                        --v149;
                      }
                      while ( v149 );
                    }
                    if ( --v227->m_pendings.m_size != v235 )
                    {
                      v153 = 8i64;
                      v154 = (__int64)v227->m_pendings.m_data + v213;
                      v155 = (signed __int64)&v227->m_pendings.m_data[(signed __int64)v227->m_pendings.m_size] - v154;
                      do
                      {
                        v156 = *(_QWORD *)(v155 + v154);
                        v154 += 8i64;
                        *(_QWORD *)(v154 - 8) = v156;
                        --v153;
                      }
                      while ( v153 );
                    }
                    if ( --v227->m_pendings.m_size != v210 )
                    {
                      v157 = 8i64;
                      v158 = (__int64)v227->m_pendings.m_data + v216;
                      v159 = (signed __int64)&v227->m_pendings.m_data[(signed __int64)v227->m_pendings.m_size] - v158;
                      do
                      {
                        v160 = *(_QWORD *)(v159 + v158);
                        v158 += 8i64;
                        *(_QWORD *)(v158 - 8) = v160;
                        --v157;
                      }
                      while ( v157 );
                    }
                    v1 = v218;
                    v29 = v220.m128i_i64[0];
                    v23 = root.m_triangle;
                    v27 = v217.m128i_i64[0];
                    v55 = v218;
                    v56 = v218;
                    v233 = v218;
                    v14 = v218;
                    i = v218;
                    v213 = v218;
                    v216 = v218;
                    v235 = v218;
                    v9 = v218;
                    v210 = v218;
                    v229 = 1;
                  }
                  v26 = v209.vfptr;
                  ++v55;
                  ++v56;
                  v215 = v55;
                  if ( v55 >= v1 )
                    break;
                  v34 = 0i64;
                }
              }
              v2 = v229;
              if ( !v229 )
                return 0;
            }
            else
            {
              v2 = v229;
            }
            v12 = v219;
            v10 = v225;
            v11 = v224;
            ++v14;
            ++v233;
          }
          ++v9;
          v8 = v235 + 1;
          v213 = v9;
          v235 = v8;
        }
        while ( v8 < v1 );
        v4 = v210;
      }
      v210 = ++v4;
    }
    while ( v4 < v1 );
    if ( v2 )
    {
      if ( v3->m_pendings.m_size > 0 )
      {
        do
        {
          v162 = v3->m_mesh.m_triangles.m_used;
          v163 = (signed __int64)&v3->m_pendings.m_data[(signed __int64)(v3->m_pendings.m_size - 1)];
          if ( v162 )
          {
            while ( v162->m_plane.m_d
                  + *(signed int *)(v163 + 32) * (signed __int64)v162->m_plane.m_c[0]
                  + *(signed int *)(v163 + 40) * (signed __int64)v162->m_plane.m_c[2]
                  + *(signed int *)(v163 + 36) * (signed __int64)v162->m_plane.m_c[1] <= 0 )
            {
              v162 = v162->m_next;
              if ( !v162 )
                goto LABEL_161;
            }
            if ( v162 )
            {
              v164 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
              if ( !v164 || !v164->m_free )
                v164 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
              if ( v164 )
              {
                v165 = v164->m_free;
                v164->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v165->m_data;
                v165->m_pool = v164;
                ++v164->m_used;
                *(_DWORD *)&v165->m_data[44] = 0;
                *(_DWORD *)&v165->m_data[52] = -1;
                *(_QWORD *)&v165->m_data[8] = 0i64;
                *(_QWORD *)v165->m_data = v3->m_mesh.m_vertices.m_used;
                v166 = v3->m_mesh.m_vertices.m_used;
                if ( v166 )
                  v166->m_prev = (hkgpConvexHullImpl::Vertex *)v165;
                ++v3->m_mesh.m_vertices.m_numUsed;
                v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v165;
              }
              else
              {
                v165 = 0i64;
              }
              v167 = *(_OWORD *)(v163 + 16);
              v209.vfptr = 0i64;
              *(_DWORD *)&v209.m_memSizeAndFlags = 0;
              *(_OWORD *)&v165->m_data[16] = v167;
              *(_DWORD *)&v165->m_data[32] = *(_DWORD *)(v163 + 32);
              *(_DWORD *)&v165->m_data[36] = *(_DWORD *)(v163 + 36);
              *(_DWORD *)&v165->m_data[40] = *(_DWORD *)(v163 + 40);
              *(_DWORD *)&v165->m_data[44] = *(_DWORD *)(v163 + 44);
              v168 = *(_DWORD *)(v163 + 48);
              root.m_triangle = v162;
              *(_DWORD *)&v165->m_data[48] = v168;
              v169 = *(_DWORD *)(v163 + 52);
              *(_DWORD *)&v165->m_data[48] = 0;
              *(_DWORD *)&v165->m_data[52] = v169;
              ++v3->m_pid;
              root.m_index = 0;
              hkgpConvexHullImpl::clearHorizon(
                v3,
                (hkgpConvexHullImpl::Vertex *)v165,
                &root,
                (hkgpConvexHullImpl::Edge *)&v209);
              v170 = *(_DWORD *)&v209.m_memSizeAndFlags;
              v171 = (unsigned __int64)v209.vfptr;
              if ( (_QWORD)*(&v209.vfptr[2].__first_virtual_table_function__ + *(signed int *)&v209.m_memSizeAndFlags) & 0xFFFFFFFFFFFFFFFCui64 )
              {
                do
                {
                  v220.m128i_i64[0] = v171;
                  v220.m128i_i32[2] = (9 >> 2 * v170) & 3;
                  _mm_store_si128((__m128i *)&v209, v220);
                  v30 = (*(_QWORD *)(v171 + 8i64 * ((9 >> 2 * v170) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0;
                  v171 = (unsigned __int64)v209.vfptr;
                  v170 = *(_DWORD *)&v209.m_memSizeAndFlags;
                }
                while ( !v30 );
              }
              v172 = 0i64;
              v228 = 0i64;
              v173 = v171 + v170;
              v174 = 0i64;
              v234 = v171 + v170;
              while ( 1 )
              {
                v175 = 2 * v170;
                v217.m128i_i64[0] = v171;
                v176 = (9 >> v175) & 3;
                v217.m128i_i32[2] = (9 >> v175) & 3;
                if ( *(_QWORD *)(v171 + 8i64 * v176 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
                {
                  do
                  {
                    v177 = *(_QWORD *)(v171 + 8i64 * v176 + 40);
                    v171 = *(_QWORD *)(v171 + 8i64 * v176 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    v222.m128i_i64[0] = v171;
                    v222.m128i_i32[2] = (9 >> 2 * (v177 & 3)) & 3;
                    v30 = (*(_QWORD *)(v171 + 8i64 * v222.m128i_i32[2] + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0;
                    v178 = v222;
                    v217 = v222;
                    v176 = (9 >> 2 * (v177 & 3)) & 3;
                  }
                  while ( !v30 );
                }
                else
                {
                  v178 = v217;
                }
                _mm_store_si128((__m128i *)&v209, v178);
                v179 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v3->m_mesh.m_triangles.m_allocator.m_firstPool;
                if ( v173 == v171 + (unsigned int)v176 )
                  break;
                if ( !v179 || !v179->m_free )
                  v179 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                if ( v179 )
                {
                  v180 = v179->m_free;
                  v179->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v180->m_data;
                  v180->m_pool = v179;
                  ++v179->m_used;
                  *(_DWORD *)&v180->m_data[88] = -1;
                  *(_DWORD *)&v180->m_data[100] = -1;
                  *(_QWORD *)&v180->m_data[8] = 0i64;
                  *(_QWORD *)v180->m_data = v3->m_mesh.m_triangles.m_used;
                  v181 = v3->m_mesh.m_triangles.m_used;
                  if ( v181 )
                    v181->m_prev = (hkgpConvexHullImpl::Triangle *)v180;
                  ++v3->m_mesh.m_triangles.m_numUsed;
                  v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v180;
                }
                else
                {
                  v180 = 0i64;
                }
                v182 = (_DWORD *)*((_QWORD *)&v209.vfptr[1].__vecDelDtor + *(signed int *)&v209.m_memSizeAndFlags);
                v183 = (_DWORD *)*((_QWORD *)&v209.vfptr[1].__vecDelDtor
                                 + ((9i64 >> 2 * LOBYTE(v209.m_memSizeAndFlags)) & 3));
                *(_QWORD *)&v180->m_data[32] = v182;
                *(_QWORD *)&v180->m_data[16] = v165;
                *(_QWORD *)&v180->m_data[24] = v183;
                *(_DWORD *)&v180->m_data[96] = 0;
                *(_DWORD *)&v180->m_data[100] = -1;
                ++*(_DWORD *)&v165->m_data[48];
                ++v183[12];
                ++v182[12];
                v184 = v183[8];
                v185 = v182[9] - *(_DWORD *)&v165->m_data[36];
                v187 = v183[9] - *(_DWORD *)&v165->m_data[36];
                v188 = v183[10] - *(_DWORD *)&v165->m_data[40];
                LODWORD(v183) = v182[8] - *(_DWORD *)&v165->m_data[32];
                v189 = v184 - *(_DWORD *)&v165->m_data[32];
                v190 = v185;
                LODWORD(v182) = v182[10] - *(_DWORD *)&v165->m_data[40];
                v186 = (signed int)v182;
                v191 = v189 * v185 - v187 * (_DWORD)v183;
                *(_DWORD *)&v180->m_data[72] = v191;
                v192 = v187 * (_DWORD)v182 - v188 * v190;
                *(_DWORD *)&v180->m_data[64] = v192;
                *(_QWORD *)&v180->m_data[80] = 0i64;
                v193 = v188 * (_DWORD)v183 - v189 * v186;
                *(_DWORD *)&v180->m_data[68] = v193;
                if ( v192 | v193 | v191 )
                  *(_QWORD *)&v180->m_data[80] = -(v192 * (signed __int64)*(signed int *)&v165->m_data[32]
                                                 + v193 * (signed __int64)*(signed int *)&v165->m_data[36]
                                                 + v191 * (signed __int64)*(signed int *)&v165->m_data[40]);
                *((_QWORD *)&v209.vfptr[2].__first_virtual_table_function__ + *(signed int *)&v209.m_memSizeAndFlags) = (char *)v180 + 1;
                *(_QWORD *)&v180->m_data[48] = (char *)v209.vfptr + *(unsigned int *)&v209.m_memSizeAndFlags;
                if ( v174 )
                {
                  v172 = v228;
                  *(_QWORD *)&v174->m_data[40] = (char *)v180 + 2;
                  *(_QWORD *)&v180->m_data[56] = v174;
                }
                else
                {
                  v172 = v180;
                  v228 = v180;
                }
                LOBYTE(v170) = v209.m_memSizeAndFlags;
                v171 = (unsigned __int64)v209.vfptr;
                v173 = v234;
                v174 = v180;
              }
              if ( !v179 || !v179->m_free )
                v179 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
              if ( v179 )
              {
                v194 = v179->m_free;
                v179->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v194->m_data;
                v194->m_pool = v179;
                ++v179->m_used;
                *(_DWORD *)&v194->m_data[88] = -1;
                *(_DWORD *)&v194->m_data[100] = -1;
                *(_QWORD *)&v194->m_data[8] = 0i64;
                *(_QWORD *)v194->m_data = v3->m_mesh.m_triangles.m_used;
                v195 = v3->m_mesh.m_triangles.m_used;
                if ( v195 )
                  v195->m_prev = (hkgpConvexHullImpl::Triangle *)v194;
                ++v3->m_mesh.m_triangles.m_numUsed;
                v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v194;
              }
              else
              {
                v194 = 0i64;
              }
              v196 = (_DWORD *)*((_QWORD *)&v209.vfptr[1].__vecDelDtor + *(signed int *)&v209.m_memSizeAndFlags);
              v197 = (_DWORD *)*((_QWORD *)&v209.vfptr[1].__vecDelDtor
                               + ((9i64 >> 2 * LOBYTE(v209.m_memSizeAndFlags)) & 3));
              *(_QWORD *)&v194->m_data[32] = v196;
              *(_QWORD *)&v194->m_data[16] = v165;
              *(_QWORD *)&v194->m_data[24] = v197;
              *(_DWORD *)&v194->m_data[96] = 0;
              *(_DWORD *)&v194->m_data[100] = -1;
              ++*(_DWORD *)&v165->m_data[48];
              ++v197[12];
              ++v196[12];
              v198 = v197[9] - *(_DWORD *)&v165->m_data[36];
              v199 = v197[10] - *(_DWORD *)&v165->m_data[40];
              v200 = v197[8] - *(_DWORD *)&v165->m_data[32];
              v201 = v196[9] - *(_DWORD *)&v165->m_data[36];
              v202 = v196[10] - *(_DWORD *)&v165->m_data[40];
              LODWORD(v197) = v196[8] - *(_DWORD *)&v165->m_data[32];
              *(_QWORD *)&v194->m_data[80] = 0i64;
              v203 = v202 * v198 - v201 * v199;
              *(_DWORD *)&v194->m_data[64] = v203;
              v204 = (_DWORD)v197 * v199 - v202 * v200;
              v205 = v201 * v200 - (_DWORD)v197 * v198;
              *(_DWORD *)&v194->m_data[68] = v204;
              *(_DWORD *)&v194->m_data[72] = v205;
              if ( v203 | v204 | v205 )
                *(_QWORD *)&v194->m_data[80] = -(v203 * (signed __int64)*(signed int *)&v165->m_data[32]
                                               + v204 * (signed __int64)*(signed int *)&v165->m_data[36]
                                               + v205 * (signed __int64)*(signed int *)&v165->m_data[40]);
              *((_QWORD *)&v209.vfptr[2].__first_virtual_table_function__ + *(signed int *)&v209.m_memSizeAndFlags) = (char *)v194 + 1;
              *(_QWORD *)&v194->m_data[48] = (char *)v209.vfptr + *(unsigned int *)&v209.m_memSizeAndFlags;
              *(_QWORD *)&v174->m_data[40] = (char *)v194 + 2;
              *(_QWORD *)&v194->m_data[56] = v174;
              *(_QWORD *)&v194->m_data[40] = (char *)v172 + 2;
              if ( v172 )
                *(_QWORD *)&v172->m_data[56] = v194;
            }
          }
LABEL_161:
          --v3->m_pendings.m_size;
        }
        while ( v3->m_pendings.m_size > 0 );
        v2 = v229;
      }
      v206 = v3->m_pendings.m_capacityAndFlags;
      v3->m_pendings.m_size = 0;
      if ( v206 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v3->m_pendings.m_data,
          v206 << 6);
      v3->m_pendings.m_data = 0i64;
      v3->m_pendings.m_capacityAndFlags = 2147483648;
    }
  }
  return v2;
}

// File Line: 784
// RVA: 0xCC3CC0
void __fastcall hkgpConvexHullImpl::clearHorizon(hkgpConvexHullImpl *this, hkgpConvexHullImpl::Vertex *vertex, hkgpConvexHullImpl::Edge *root, hkgpConvexHullImpl::Edge *horizon)
{
  hkgpConvexHullImpl::Triangle *v4; // rax
  hkgpConvexHullImpl::Edge *v5; // rdi
  hkgpConvexHullImpl::Vertex *v6; // rsi
  hkgpConvexHullImpl *v7; // rbx
  int v8; // ecx
  hkgpConvexHullImpl::Triangle *v9; // r8
  unsigned __int64 v10; // rcx
  char v11; // al
  char v12; // al
  __int64 v13; // r9
  signed __int64 v14; // r8
  signed __int64 v15; // r8
  hkgpConvexHullImpl::Triangle *v16; // rbp
  signed __int64 v17; // rsi
  hkgpConvexHullImpl::Vertex ***v18; // rdi
  hkgpConvexHullImpl::Vertex **v19; // rax
  hkgpConvexHullImpl::Vertex **v20; // rdx
  hkgpConvexHullImpl::Vertex *v21; // rax
  hkgpConvexHullImpl::Vertex *v22; // rcx
  hkgpConvexHullImpl::Vertex *v23; // rdx
  bool v24; // zf
  hkgpConvexHullImpl::Vertex *v25; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v26; // rax
  __int64 v27; // rcx
  hkgpConvexHullImpl::Triangle *v28; // rax
  hkgpConvexHullImpl::Triangle *v29; // rcx
  hkgpConvexHullImpl::Triangle *v30; // rdx
  unsigned __int64 v31; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v32; // rax
  unsigned __int64 v33; // r8
  hkgpConvexHullImpl::Edge roota; // [rsp+20h] [rbp-28h]
  hkgpConvexHullImpl::Vertex *vertexa; // [rsp+58h] [rbp+10h]
  hkgpConvexHullImpl::Edge *horizona; // [rsp+68h] [rbp+20h]

  horizona = horizon;
  vertexa = vertex;
  v4 = root->m_triangle;
  v5 = root;
  v6 = vertex;
  v7 = this;
  if ( root->m_triangle )
  {
    v8 = this->m_pid;
    if ( v4->m_pid != v8 )
    {
      v4->m_pid = v8;
      v9 = root->m_triangle;
      if ( v9->m_plane.m_d
         + v9->m_plane.m_c[0] * (signed __int64)vertex->m_x[0]
         + vertex->m_x[1] * (signed __int64)v9->m_plane.m_c[1]
         + vertex->m_x[2] * (signed __int64)v9->m_plane.m_c[2] < 0 )
      {
        horizon->m_triangle = v9;
        *(_QWORD *)&horizon->m_index = *(_QWORD *)&v5->m_index;
      }
      else
      {
        v10 = v9->m_links[v5->m_index];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(v10 & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v10 & 3;
        hkgpConvexHullImpl::clearHorizon(v7, vertex, &roota, horizon);
        v11 = v5->m_triangle->m_links[(9 >> 2 * v5->m_index) & 3];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(v5->m_triangle->m_links[(9 >> 2 * v5->m_index) & 3] & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v11 & 3;
        hkgpConvexHullImpl::clearHorizon(v7, v6, &roota, horizona);
        v12 = v5->m_triangle->m_links[(18 >> 2 * v5->m_index) & 3];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(v5->m_triangle->m_links[(18 >> 2 * v5->m_index) & 3] & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v12 & 3;
        hkgpConvexHullImpl::clearHorizon(v7, vertexa, &roota, horizona);
        v13 = 0i64;
        if ( v5->m_triangle->m_links[v5->m_index] & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((v5->m_triangle->m_links[v5->m_index] & 0xFFFFFFFFFFFFFFFCui64)
                    + 8 * (v5->m_triangle->m_links[v5->m_index] & 3)
                    + 40) = 0i64;
        v5->m_triangle->m_links[v5->m_index] = 0i64;
        v14 = (signed __int64)v5->m_triangle + 8 * ((9 >> 2 * v5->m_index) & 3);
        if ( *(_QWORD *)(v14 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((*(_QWORD *)(v14 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v14 + 40) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v14 + 40) = 0i64;
        v15 = (signed __int64)v5->m_triangle + 8 * ((18 >> 2 * v5->m_index) & 3);
        if ( *(_QWORD *)(v15 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((*(_QWORD *)(v15 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v15 + 40) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v15 + 40) = 0i64;
        v16 = v5->m_triangle;
        v17 = 3i64;
        v18 = (hkgpConvexHullImpl::Vertex ***)v5->m_triangle->m_vertices;
        do
        {
          v19 = *v18;
          if ( !--*((_DWORD *)v19 + 12) )
          {
            v20 = *v18;
            v21 = **v18;
            v22 = (*v18)[1];
            if ( v21 )
              v21->m_prev = v22;
            if ( v22 )
              v22->m_next = v21;
            else
              v7->m_mesh.m_vertices.m_used = v21;
            --v7->m_mesh.m_vertices.m_numUsed;
            v23 = v20[8];
            v24 = v23[40].m_source.m_quad.m128_i32[2]-- == 1;
            if ( v24 )
            {
              v25 = v23[40].m_prev;
              v26 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *)v23[40].m_source.m_quad.m128_u64[0];
              if ( v25 )
                v25[40].m_source.m_quad.m128_u64[0] = (unsigned __int64)v26;
              else
                v7->m_mesh.m_vertices.m_allocator.m_firstPool = v26;
              v27 = v23[40].m_source.m_quad.m128_i64[0];
              if ( v27 )
                *(_QWORD *)(v27 + 2568) = v23[40].m_prev;
              ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkgpConvexHullImpl::Vertex *, signed __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->blockFree)(
                &hkContainerHeapAllocator::s_alloc,
                v23,
                2592i64,
                v13);
            }
          }
          ++v18;
          --v17;
        }
        while ( v17 );
        v28 = v16->m_next;
        v29 = v16->m_prev;
        if ( v16->m_next )
          v28->m_prev = v29;
        if ( v29 )
          v29->m_next = v28;
        else
          v7->m_mesh.m_triangles.m_used = v28;
        --v7->m_mesh.m_triangles.m_numUsed;
        v30 = v16[1].m_prev;
        v24 = v30[39].m_plane.m_c[0]-- == 1;
        if ( v24 )
        {
          v31 = v30[39].m_links[1];
          v32 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *)v30[39].m_links[2];
          if ( v31 )
            *(_QWORD *)(v31 + 4112) = v32;
          else
            v7->m_mesh.m_triangles.m_allocator.m_firstPool = v32;
          v33 = v30[39].m_links[2];
          if ( v33 )
            *(_QWORD *)(v33 + 4104) = v30[39].m_links[1];
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkgpConvexHullImpl::Triangle *, signed __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->blockFree)(
            &hkContainerHeapAllocator::s_alloc,
            v30,
            4128i64,
            v13);
        }
      }
    }
  }
}

// File Line: 927
// RVA: 0xCB7BB0
char __fastcall hkgpConvexHullImpl::isPointInside(hkgpConvexHullImpl *this, hkVector4f *point, bool usePlanes, float epsilon)
{
  hkVector4f *v4; // rdi
  hkgpConvexHullImpl *v5; // rbx
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  int v8; // ecx
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128i v12; // xmm1
  hkgpConvexHullImpl::Triangle *v14; // rdx
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rax
  float v19; // xmm4_4
  __m128 *v20; // rcx
  __m128 v21; // xmm1
  hkErrStream v22; // [rsp+20h] [rbp-268h]
  __int64 v23; // [rsp+60h] [rbp-228h]
  int v24; // [rsp+68h] [rbp-220h]
  char buf; // [rsp+80h] [rbp-208h]

  v4 = point;
  v5 = this;
  if ( usePlanes )
  {
    if ( !this->m_hasIndexing )
    {
      hkErrStream::hkErrStream(&v22, &buf, 512);
      v15 = hkOstream::operator<<((hkOstream *)&v22.vfptr, "No index available (");
      v16 = hkOstream::operator<<(v15, v5->m_uid, (int)v15);
      hkOstream::operator<<(v16, ") hkgpConvexHull::buildIndices need to be called before this operation.");
      if ( (unsigned int)hkError::messageError(
                           2046417030,
                           &buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           358) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v22.vfptr);
    }
    v17 = v5->m_planes.m_size;
    v18 = 0i64;
    LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
    if ( v17 > 0 )
    {
      v20 = &v5->m_planes.m_data->m_quad;
      while ( 1 )
      {
        v21 = _mm_mul_ps(*v20, v4->m_quad);
        if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170)))
                   + COERCE_FLOAT(_mm_shuffle_ps(*v20, *v20, 255))) > v19 )
          break;
        ++v18;
        ++v20;
        if ( v18 >= v17 )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    v6 = _mm_mul_ps(_mm_sub_ps(point->m_quad, this->m_origin.m_quad), this->m_scale.m_quad);
    v7 = _mm_cmpltps(v6, (__m128)_xmm);
    v8 = _mm_movemask_ps(_mm_cmpltps((__m128)_xmm, v6)) | _mm_movemask_ps(
                                                            _mm_cmpltps(
                                                              v6,
                                                              (__m128)_xmm_c6000000c6000000c6000000c6000000));
    v9 = _mm_max_ps(
           (__m128)_xmm_c6000000c6000000c6000000c6000000,
           _mm_or_ps(_mm_andnot_ps(v7, (__m128)_xmm), _mm_and_ps(v6, v7)));
    v10 = _mm_cmpltps(v9, (__m128)0i64);
    v11 = _mm_or_ps(
            _mm_andnot_ps(v10, _mm_add_ps(v9, (__m128)xmmword_141A711B0)),
            _mm_and_ps(_mm_sub_ps(v9, (__m128)xmmword_141A711B0), v10));
    v12 = _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v11),
            _mm_cvttps_epi32(v11));
    v23 = v12.m128i_i64[0];
    v24 = (unsigned __int128)_mm_shuffle_epi32(v12, 170);
    if ( v8 & 7 )
      return 0;
    v14 = v5->m_mesh.m_triangles.m_used;
    if ( v14 )
    {
      while ( v14->m_plane.m_d
            + (signed int)v23 * (signed __int64)v14->m_plane.m_c[0]
            + SHIDWORD(v23) * (signed __int64)v14->m_plane.m_c[1]
            + v24 * (signed __int64)v14->m_plane.m_c[2] <= 0 )
      {
        v14 = v14->m_next;
        if ( !v14 )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

// File Line: 952
// RVA: 0xCB45C0
bool __fastcall hkgpConvexHullImpl::clipLine(hkgpConvexHullImpl *this, hkVector4f *aIn, hkVector4f *bIn, float *t0, float *t1, float epsilon)
{
  float *v6; // rbp
  hkgpConvexHullImpl *v7; // rbx
  hkVector4f *v8; // rdi
  hkVector4f *v9; // rsi
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  __int64 v12; // r8
  __m128 v13; // xmm8
  __m128 v14; // xmm10
  __m128 v15; // xmm7
  __m128 v16; // xmm9
  __m128 v17; // xmm11
  __m128 v18; // xmm12
  hkVector4f *v19; // r9
  signed int v20; // er10
  __m128 *v21; // r11
  unsigned __int64 v22; // rcx
  __m128 v23; // xmm13
  __m128 v24; // xmm14
  __m128 v25; // xmm8
  __m128 v26; // xmm15
  __m128 v27; // xmm0
  __m128 v28; // xmm7
  __m128 v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  __m128 v32; // xmm6
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  int v35; // eax
  signed __int64 v36; // rax
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm5
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  hkErrStream v51; // [rsp+20h] [rbp-2D8h]
  __m128 v52; // [rsp+40h] [rbp-2B8h]
  char buf; // [rsp+50h] [rbp-2A8h]

  v6 = t0;
  v7 = this;
  v8 = bIn;
  v9 = aIn;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v51, &buf, 512);
    v10 = hkOstream::operator<<((hkOstream *)&v51.vfptr, "No index available (");
    v11 = hkOstream::operator<<(v10, v7->m_uid, (int)v10);
    hkOstream::operator<<(v11, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v51.vfptr);
  }
  v12 = v7->m_planes.m_size;
  v13 = v9->m_quad;
  v14 = 0i64;
  v15 = _mm_sub_ps(v8->m_quad, v9->m_quad);
  v16 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
  v17 = query.m_quad;
  v18 = _mm_sub_ps((__m128)0i64, v16);
  if ( (signed int)v12 > 0 )
  {
    v19 = v7->m_planes.m_data;
    v20 = 2;
    v21 = &v7->m_planes.m_data->m_quad;
    v22 = ((unsigned __int64)(v12 - 1) >> 2) + 1;
    v23 = _mm_shuffle_ps(v13, v13, 0);
    v24 = _mm_shuffle_ps(v13, v13, 85);
    v25 = _mm_shuffle_ps(v13, v13, 170);
    v26 = _mm_shuffle_ps(v15, v15, 85);
    _mm_store_si128((__m128i *)&v52, _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v27 = _mm_shuffle_ps(v15, v15, 0);
    v28 = _mm_shuffle_ps(v15, v15, 170);
    *(__m128 *)&v51.vfptr = v27;
    do
    {
      v29 = *v21;
      v21 += 4;
      v30 = v29;
      v31 = v19[(v20 - 1) % (signed int)v12].m_quad;
      v32 = _mm_shuffle_ps(v29, v31, 238);
      v33 = _mm_shuffle_ps(v30, v31, 68);
      v34 = v19[v20 % (signed int)v12].m_quad;
      v35 = v20 + 1;
      v20 += 4;
      v36 = v35 % (signed int)v12;
      v37 = _mm_shuffle_ps(v34, v19[v36].m_quad, 68);
      v38 = _mm_shuffle_ps(v34, v19[v36].m_quad, 238);
      v39 = _mm_shuffle_ps(v33, v37, 136);
      v40 = _mm_shuffle_ps(v33, v37, 221);
      v41 = _mm_shuffle_ps(v32, v38, 136);
      v42 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v38, 221), _mm_mul_ps(v23, v39)), _mm_mul_ps(v24, v40));
      v43 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)&v51.vfptr, v39), _mm_mul_ps(v26, v40)), _mm_mul_ps(v28, v41));
      v44 = _mm_cmpltps(v16, v43);
      v45 = _mm_div_ps(_mm_xor_ps(_mm_add_ps(v42, _mm_mul_ps(v25, v41)), v52), v43);
      v46 = _mm_and_ps(_mm_cmpltps(v14, v45), _mm_cmpltps(v43, v18));
      v47 = _mm_and_ps(_mm_cmpltps(v45, v17), v44);
      v14 = _mm_or_ps(_mm_and_ps(v46, v45), _mm_andnot_ps(v46, v14));
      v17 = _mm_or_ps(_mm_andnot_ps(v47, v17), _mm_and_ps(v47, v45));
      --v22;
    }
    while ( v22 );
  }
  v48 = _mm_max_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v49 = _mm_min_ps(_mm_shuffle_ps(v17, v17, 78), v17);
  v48.m128_f32[0] = fmax(v48.m128_f32[0], COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 177)));
  *v6 = v48.m128_f32[0];
  v49.m128_f32[0] = fmin(v49.m128_f32[0], COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 177)));
  *t1 = v49.m128_f32[0];
  return v48.m128_f32[0] < v49.m128_f32[0];
}

// File Line: 1036
// RVA: 0xCB03D0
void __fastcall hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(hkgpConvexHullImpl *this)
{
  hkgpConvexHullImpl *v1; // rdi
  int v2; // er9
  hkgpConvexHullImpl::Triangle *i; // rdx
  __int64 v4; // rcx
  __int64 v5; // rcx
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  int v16; // esi
  int v17; // ebx
  int v18; // er9
  unsigned __int64 v19; // rbx
  __int64 v20; // r14
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm6
  __m128 v27; // xmm6
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  hkgpConvexHullImpl::Vertex *v34; // rax
  int j; // ecx
  int v36; // eax
  int v37; // er13
  __int64 v38; // rsi
  __int64 v39; // r15
  int v40; // eax
  __m128 *v41; // r12
  int v42; // edx
  unsigned __int64 v43; // rbx
  unsigned __int64 *v44; // rcx
  __int64 v45; // rax
  int v46; // edx
  unsigned __int64 v47; // rbx
  unsigned __int64 *v48; // rcx
  __int64 v49; // rax
  int v50; // edx
  unsigned __int64 v51; // rbx
  unsigned __int64 *v52; // rcx
  __int64 v53; // rax
  int v54; // edx
  __int64 v55; // rcx
  unsigned __int64 v56; // rbx
  __int64 v57; // rsi
  int v58; // eax
  __m128 v59; // xmm4
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  char v62; // r14
  int v63; // edx
  __int64 v64; // rsi
  char v65; // al
  unsigned __int64 v66; // rsi
  unsigned __int64 *v67; // r8
  __int64 v68; // rax
  int v69; // edx
  __int64 v70; // rbx
  char v71; // al
  unsigned __int64 v72; // rbx
  unsigned __int64 *v73; // rcx
  __int64 v74; // rax
  hkVector4f *v75; // rax
  unsigned int *v76; // rbx
  __m128 v77; // xmm12
  unsigned int *v78; // rax
  unsigned int *v79; // rcx
  __m128 v80; // xmm4
  __m128 v81; // xmm5
  __m128 v82; // xmm7
  __m128 v83; // xmm6
  __m128 *v84; // rcx
  __m128 v85; // xmm5
  __m128 v86; // xmm5
  __m128 v87; // xmm1
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  __m128 v90; // xmm4
  __m128 v91; // xmm6
  __m128 v92; // xmm7
  __m128 v93; // xmm6
  __m128 v94; // xmm1
  __m128 v95; // xmm1
  __m128 v96; // xmm0
  hkgpConvexHullImpl::Vertex *v97; // rax
  __m128 v98; // xmm4
  __m128 v99; // xmm7
  __m128 v100; // xmm6
  hkgpConvexHullImpl::Vertex *v101; // rcx
  __m128 v102; // xmm5
  __m128 v103; // xmm7
  __m128 v104; // xmm1
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  __m128 v107; // xmm7
  __m128 v108; // xmm2
  __m128 v109; // xmm7
  __m128 v110; // xmm8
  __m128 v111; // xmm2
  __m128 v112; // xmm8
  __m128 *k; // r8
  int v114; // edx
  __int64 v115; // rax
  hkVector4f *v116; // rcx
  __m128 v117; // xmm1
  __m128 v118; // xmm3
  int v119; // ecx
  int v120; // er8
  _QWORD *v121; // [rsp+30h] [rbp-C0h]
  int v122; // [rsp+38h] [rbp-B8h]
  int v123; // [rsp+3Ch] [rbp-B4h]
  hkgpConvexHullImpl::SortedTriangle *array; // [rsp+40h] [rbp-B0h]
  int v125; // [rsp+48h] [rbp-A8h]
  int v126; // [rsp+4Ch] [rbp-A4h]
  __m128 *v127; // [rsp+50h] [rbp-A0h]
  int v128; // [rsp+58h] [rbp-98h]
  int v129; // [rsp+5Ch] [rbp-94h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v130; // [rsp+60h] [rbp-90h]
  __int64 v131; // [rsp+78h] [rbp-78h]
  __int64 v132; // [rsp+88h] [rbp-68h]
  __int64 v133; // [rsp+98h] [rbp-58h]
  __int64 v134; // [rsp+A8h] [rbp-48h]
  hkResult result; // [rsp+160h] [rbp+70h]
  __int64 retaddr; // [rsp+168h] [rbp+78h]

  v1 = this;
  if ( !this->m_hasIndexing )
  {
    v2 = this->m_mesh.m_triangles.m_numUsed;
    v126 = 2147483648;
    v130.m_hashMod = -1;
    v129 = 2147483648;
    array = 0i64;
    v125 = 0;
    v130.m_elem = 0i64;
    v130.m_numElems = 0;
    v127 = 0i64;
    v128 = 0;
    if ( v2 )
    {
      if ( v2 > 0 )
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v2, 16);
      for ( i = v1->m_mesh.m_triangles.m_used; i; i = i->m_next )
      {
        v4 = v125++;
        v5 = (__int64)&array[v4];
        *(_QWORD *)v5 = i;
        v6 = v1->m_scaleInv.m_quad;
        v7 = v1->m_origin.m_quad;
        v8 = _mm_add_ps(
               _mm_mul_ps(
                 (__m128)_mm_srli_si128(
                           _mm_slli_si128(
                             (__m128i)_mm_cvtepi32_ps(
                                        _mm_unpacklo_epi32(
                                          _mm_unpacklo_epi32(
                                            _mm_cvtsi32_si128(i->m_vertices[0]->m_x[0]),
                                            _mm_cvtsi32_si128(i->m_vertices[0]->m_x[2])),
                                          _mm_unpacklo_epi32(
                                            _mm_cvtsi32_si128(i->m_vertices[0]->m_x[1]),
                                            _mm_cvtsi32_si128(0)))),
                             4),
                           4),
                 v6),
               v7);
        v9 = _mm_sub_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   (__m128)_mm_srli_si128(
                             _mm_slli_si128(
                               (__m128i)_mm_cvtepi32_ps(
                                          _mm_unpacklo_epi32(
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128(i->m_vertices[2]->m_x[0]),
                                              _mm_cvtsi32_si128(i->m_vertices[2]->m_x[2])),
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128(i->m_vertices[2]->m_x[1]),
                                              _mm_cvtsi32_si128(0)))),
                               4),
                             4),
                   v6),
                 v7),
               v8);
        v10 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(i->m_vertices[1]->m_x[0]),
                                               _mm_cvtsi32_si128(i->m_vertices[1]->m_x[2])),
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(i->m_vertices[1]->m_x[1]),
                                               _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    v6),
                  v7),
                v8);
        v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
        v12 = _mm_shuffle_ps(v11, v11, 201);
        v13 = _mm_mul_ps(v12, v12);
        v14 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170));
        v15 = _mm_rsqrt_ps(v14);
        *(_DWORD *)(v5 + 8) = (unsigned __int128)_mm_andnot_ps(
                                                   _mm_cmpleps(v14, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                                                       _mm_mul_ps(*(__m128 *)_xmm, v15)),
                                                     v14));
      }
      if ( v125 > 1 )
        hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::SortedTriangle,hkAlgorithm::less<hkgpConvexHullImpl::SortedTriangle>>(
          array,
          0,
          v125 - 1,
          0);
      v16 = 0;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        &v130,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v1->m_mesh.m_triangles.m_numUsed);
      v17 = v1->m_mesh.m_triangles.m_numUsed;
      if ( (v129 & 0x3FFFFFFF) < v17 )
      {
        v18 = v1->m_mesh.m_triangles.m_numUsed;
        if ( v17 < 2 * (v129 & 0x3FFFFFFF) )
          v18 = 2 * (v129 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v127, v18, 16);
      }
      v128 = v17;
      v19 = (unsigned __int64)v1->m_mesh.m_triangles.m_used;
      if ( v19 )
      {
        v20 = 0i64;
        do
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v130,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v19,
            v16);
          v21 = v1->m_scaleInv.m_quad;
          v22 = v1->m_origin.m_quad;
          v23 = _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 16) + 32i64)),
                                               _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 16) + 40i64))),
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 16) + 36i64)),
                                               _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    v21),
                  v22);
          v24 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 32) + 32i64)),
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 32) + 40i64))),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 32) + 36i64)),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v21),
                    v22),
                  v23);
          v25 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 24) + 32i64)),
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 24) + 40i64))),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(*(_DWORD *)(*(_QWORD *)(v19 + 24) + 36i64)),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v21),
                    v22),
                  v23);
          v26 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
          v27 = _mm_shuffle_ps(v26, v26, 201);
          v28 = _mm_mul_ps(v27, v27);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v29), (__m128)0i64);
          ++v20;
          v32 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v29, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                          _mm_mul_ps(*(__m128 *)_xmm, v30))),
                      v27),
                    v31),
                  _mm_andnot_ps(v31, v27));
          v33 = _mm_mul_ps(v32, v23);
          v127[v20 - 1] = _mm_shuffle_ps(
                            v32,
                            _mm_unpackhi_ps(
                              v32,
                              _mm_sub_ps(
                                (__m128)0i64,
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                  _mm_shuffle_ps(v33, v33, 170)))),
                            196);
          *(_DWORD *)(v19 + 100) = v16;
          *(_DWORD *)(v19 + 88) = -1;
          v19 = *(_QWORD *)v19;
          ++v16;
        }
        while ( v19 );
      }
    }
    v34 = v1->m_mesh.m_vertices.m_used;
    for ( j = 0; v34; ++j )
    {
      v34->m_index = j;
      v34 = v34->m_next;
    }
    v36 = v1->m_dimensions;
    v1->m_planes.m_size = 0;
    switch ( v36 )
    {
      case 3:
        v121 = 0i64;
        v122 = 0;
        v37 = 0;
        v123 = 2147483648;
        if ( v125 > 0 )
        {
          v38 = 0i64;
          retaddr = 0i64;
          do
          {
            v39 = *(__int64 *)((char *)&array->m_data + v38);
            if ( *(_DWORD *)(v39 + 88) == -1 )
            {
              v40 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      &v130,
                      *(unsigned __int64 *)((char *)&array->m_data + v38),
                      0xFFFFFFFFFFFFFFFFui64);
              v41 = &v127[v40];
              *(_DWORD *)(v39 + 88) = v1->m_planes.m_size;
              if ( v1->m_planes.m_size == (v1->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v1->m_planes,
                  16);
              v42 = 0;
              v1->m_planes.m_data[v1->m_planes.m_size++].m_quad = *v41;
              v122 = 0;
              v43 = *(_QWORD *)(v39 + 40) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v131) = *(_DWORD *)(v39 + 40) & 3;
              if ( !(v123 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v121, 16);
                v42 = v122;
              }
              v44 = &v121[2 * v42];
              if ( v44 )
              {
                v45 = v131;
                *v44 = v43;
                v44[1] = v45;
                v42 = v122;
              }
              v46 = v42 + 1;
              v122 = v46;
              v47 = *(_QWORD *)(v39 + 48) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v133) = *(_QWORD *)(v39 + 48) & 3;
              if ( v46 == (v123 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v121, 16);
                v46 = v122;
              }
              v48 = &v121[2 * v46];
              if ( v48 )
              {
                v49 = v133;
                *v48 = v47;
                v48[1] = v49;
                v46 = v122;
              }
              v50 = v46 + 1;
              v122 = v50;
              v51 = *(_QWORD *)(v39 + 56) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v131) = *(_QWORD *)(v39 + 56) & 3;
              if ( v50 == (v123 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v121, 16);
                v50 = v122;
              }
              v52 = &v121[2 * v50];
              if ( v52 )
              {
                v53 = v131;
                *v52 = v51;
                v52[1] = v53;
                v50 = v122;
              }
              v54 = v50 + 1;
              v122 = v54;
              if ( v54 )
              {
                do
                {
                  v55 = v54--;
                  v55 *= 2i64;
                  v56 = v121[v55 - 2];
                  v57 = v121[v55 - 1];
                  v122 = v54;
                  if ( *(_DWORD *)(v56 + 88) == -1 )
                  {
                    v58 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            &v130,
                            v56,
                            0xFFFFFFFFFFFFFFFFui64);
                    result.m_enum = 953267991;
                    v59 = v127[v58];
                    if ( _mm_movemask_ps(_mm_cmpunordps(v59, v59)) & 7
                      || (v60 = _mm_mul_ps(v59, v59),
                          COERCE_FLOAT((unsigned int)(2
                                                    * COERCE_SIGNED_INT(
                                                        (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 85))
                                                                      + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 0)))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 170)))
                                                      - 1.0)) >> 1) >= COERCE_FLOAT(
                                                                         _mm_shuffle_ps(
                                                                           (__m128)(unsigned int)result.m_enum,
                                                                           (__m128)(unsigned int)result.m_enum,
                                                                           0)))
                      || (v61 = _mm_mul_ps(*v41, v59),
                          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170))) >= v1->m_config.m_minCosAngle) )
                    {
                      v62 = 2 * v57;
                      *(_DWORD *)(v56 + 88) = *(_DWORD *)(v39 + 88);
                      v63 = v122;
                      v64 = *(_QWORD *)(v56 + 8i64 * ((9 >> 2 * v57) & 3) + 40);
                      v65 = v64;
                      v66 = v64 & 0xFFFFFFFFFFFFFFFCui64;
                      LODWORD(v132) = v65 & 3;
                      if ( v122 == (v123 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                          &v121,
                          16);
                        v63 = v122;
                      }
                      v67 = &v121[2 * v63];
                      if ( v67 )
                      {
                        v68 = v132;
                        *v67 = v66;
                        v67[1] = v68;
                        v63 = v122;
                      }
                      v69 = v63 + 1;
                      v122 = v69;
                      v70 = *(_QWORD *)(v56 + 8i64 * ((18 >> v62) & 3) + 40);
                      v71 = v70;
                      v72 = v70 & 0xFFFFFFFFFFFFFFFCui64;
                      LODWORD(v134) = v71 & 3;
                      if ( v69 == (v123 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                          &v121,
                          16);
                        v69 = v122;
                      }
                      v73 = &v121[2 * v69];
                      if ( v73 )
                      {
                        v74 = v134;
                        *v73 = v72;
                        v73[1] = v74;
                        v69 = v122;
                      }
                      v54 = v69 + 1;
                      v122 = v54;
                    }
                    else
                    {
                      v54 = v122;
                    }
                  }
                }
                while ( v54 );
                v38 = retaddr;
              }
            }
            v38 += 16i64;
            ++v37;
            retaddr = v38;
          }
          while ( v37 < v125 );
        }
        v122 = 0;
        if ( v123 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v121,
            16 * v123);
        break;
      case 2:
        v75 = hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(v1);
        v76 = (unsigned int *)v1->m_mesh.m_vertices.m_used;
        v77 = v75->m_quad;
        v78 = v76;
        if ( v76 )
        {
          v79 = *(unsigned int **)v76;
          if ( *(_QWORD *)v76 )
          {
            do
            {
              v78 = v79;
              v79 = *(unsigned int **)v79;
            }
            while ( v79 );
          }
          for ( ; v76; v76 = *(unsigned int **)v76 )
          {
            v80 = v1->m_scaleInv.m_quad;
            v81 = v1->m_origin.m_quad;
            v82 = _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(_mm_cvtsi32_si128(v78[8]), _mm_cvtsi32_si128(v78[10])),
                                               _mm_unpacklo_epi32(_mm_cvtsi32_si128(v78[9]), _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v80),
                    v81);
            v83 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v76[8]),
                                                   _mm_cvtsi32_si128(v76[10])),
                                                 _mm_unpacklo_epi32(_mm_cvtsi32_si128(v76[9]), _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v80),
                      v81),
                    v82);
            if ( v1->m_planes.m_size == (v1->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v1->m_planes,
                16);
            v84 = &v1->m_planes.m_data[v1->m_planes.m_size++].m_quad;
            v78 = v76;
            v85 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v1->m_projectionPlane.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v1->m_projectionPlane.m_quad, v1->m_projectionPlane.m_quad, 201), v83));
            v86 = _mm_shuffle_ps(v85, v85, 201);
            v87 = _mm_mul_ps(v86, v86);
            v88 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                    _mm_shuffle_ps(v87, v87, 170));
            v89 = _mm_rsqrt_ps(v88);
            v90 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v88), (__m128)0i64);
            v91 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v88, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v89, v88), v89)),
                            _mm_mul_ps(*(__m128 *)_xmm, v89))),
                        v86),
                      v90),
                    _mm_andnot_ps(v90, v86));
            v92 = _mm_mul_ps(v82, v91);
            v93 = _mm_shuffle_ps(
                    v91,
                    _mm_unpackhi_ps(
                      v91,
                      _mm_sub_ps(
                        (__m128)0i64,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                          _mm_shuffle_ps(v92, v92, 170)))),
                    196);
            v94 = _mm_mul_ps(v77, v93);
            v95 = _mm_shuffle_ps(v94, _mm_unpackhi_ps(v94, v93), 196);
            v96 = _mm_add_ps(_mm_shuffle_ps(v95, v95, 78), v95);
            *v84 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 _mm_cmpeq_epi32(
                                   _mm_srai_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v96, v96, 177), v96), 0x1Fu),
                                   (__m128i)0i64),
                                 0x1Fu),
                               0x1Fu),
                     v93);
          }
        }
        break;
      case 1:
        v97 = v1->m_mesh.m_vertices.m_used;
        v98 = v1->m_scaleInv.m_quad;
        v99 = v1->m_origin.m_quad;
        v100 = _mm_add_ps(
                 _mm_mul_ps(
                   (__m128)_mm_srli_si128(
                             _mm_slli_si128(
                               (__m128i)_mm_cvtepi32_ps(
                                          _mm_unpacklo_epi32(
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128(v97->m_x[0]),
                                              _mm_cvtsi32_si128(v97->m_x[2])),
                                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v97->m_x[1]), _mm_cvtsi32_si128(0)))),
                               4),
                             4),
                   v98),
                 v99);
        if ( v97 )
        {
          v101 = v97->m_next;
          if ( v97->m_next )
          {
            do
            {
              v97 = v101;
              v101 = v101->m_next;
            }
            while ( v101 );
          }
        }
        v102 = _mm_add_ps(
                 _mm_mul_ps(
                   (__m128)_mm_srli_si128(
                             _mm_slli_si128(
                               (__m128i)_mm_cvtepi32_ps(
                                          _mm_unpacklo_epi32(
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128(v97->m_x[0]),
                                              _mm_cvtsi32_si128(v97->m_x[2])),
                                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v97->m_x[1]), _mm_cvtsi32_si128(0)))),
                               4),
                             4),
                   v98),
                 v99);
        v103 = _mm_sub_ps(v102, v100);
        v104 = _mm_mul_ps(v103, v103);
        v105 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                 _mm_shuffle_ps(v104, v104, 170));
        v106 = _mm_rsqrt_ps(v105);
        v107 = _mm_mul_ps(
                 v103,
                 _mm_andnot_ps(
                   _mm_cmpleps(v105, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v106, v105), v106)),
                     _mm_mul_ps(*(__m128 *)_xmm, v106))));
        v108 = _mm_mul_ps(v107, v102);
        v109 = _mm_shuffle_ps(
                 v107,
                 _mm_unpackhi_ps(
                   v107,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                       _mm_shuffle_ps(v108, v108, 170)))),
                 196);
        if ( 0 == (v1->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_planes, 16);
        v1->m_planes.m_data[v1->m_planes.m_size++].m_quad = v109;
        v110 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v109);
        v111 = _mm_mul_ps(v110, v100);
        v112 = _mm_shuffle_ps(
                 v110,
                 _mm_unpackhi_ps(
                   v110,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                       _mm_shuffle_ps(v111, v111, 170)))),
                 196);
        if ( v1->m_planes.m_size == (v1->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_planes, 16);
        v1->m_planes.m_data[v1->m_planes.m_size++].m_quad = v112;
        break;
    }
    if ( v1->m_config.m_ensurePlaneEnclosing.m_bool )
    {
      for ( k = (__m128 *)v1->m_mesh.m_vertices.m_used; k; k = (__m128 *)k->m128_u64[0] )
      {
        v114 = 0;
        if ( v1->m_planes.m_size > 0 )
        {
          v115 = 0i64;
          do
          {
            v116 = v1->m_planes.m_data;
            v117 = _mm_mul_ps(v116[v115].m_quad, k[1]);
            v118 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                       _mm_shuffle_ps(v117, v117, 170)),
                     _mm_shuffle_ps(v116[v115].m_quad, v116[v115].m_quad, 255));
            if ( v118.m128_f32[0] > 0.0 )
              v116[v115].m_quad = _mm_shuffle_ps(
                                    v116[v115].m_quad,
                                    _mm_unpackhi_ps(
                                      v116[v115].m_quad,
                                      _mm_sub_ps(_mm_shuffle_ps(v116[v115].m_quad, v116[v115].m_quad, 255), v118)),
                                    196);
            ++v114;
            ++v115;
          }
          while ( v114 < v1->m_planes.m_size );
        }
      }
    }
    if ( v1->m_planes.m_size )
    {
      v119 = v1->m_planes.m_size;
      if ( v119 < (v1->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v1->m_planes,
          16,
          0i64,
          v119);
    }
    v120 = v129;
    v1->m_hasIndexing = 1;
    v128 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v127,
        16 * v120);
    v127 = 0i64;
    v129 = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v130,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v130);
    v125 = 0;
    if ( v126 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v126);
  }
}::s_alloc.vfptr,
          &v1->m_planes,
          16,
          0i64,
          v119);
    }
    v120 = v129;
    v1->m_hasIndexing = 1;
    v128 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v127,
        16 * v120);
    v127 = 0i64;
    v129 = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hk

// File Line: 1160
// RVA: 0xCB0030
void __fastcall hkgpConvexHullImpl::buildBevelPlanes<hkgpConvexHullImpl::PositionAsTransform>(hkgpConvexHullImpl *this, float maxCosAngle, hkArray<hkVector4f,hkContainerHeapAllocator> *bevelPlanes)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rbx
  hkgpConvexHullImpl *v4; // rbp
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkgpConvexHullImpl::Triangle *v7; // r14
  float v8; // xmm8_4
  signed int v9; // edi
  unsigned __int64 *v10; // rsi
  unsigned __int64 v11; // r10
  signed int v12; // edx
  hkgpConvexHullImpl::Vertex *v13; // rcx
  unsigned __int64 v14; // r9
  int *v15; // rax
  int v16; // ecx
  __int64 v17; // rax
  hkVector4f *v18; // rcx
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  __m128 v27; // xmm4
  __m128 v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128i v32; // xmm0
  __m128i v33; // xmm2
  __m128i v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm6
  hkErrStream v37; // [rsp+20h] [rbp-268h]
  char buf; // [rsp+40h] [rbp-248h]

  v3 = bevelPlanes;
  v4 = this;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v37, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v37.vfptr, "No index available (");
    v6 = hkOstream::operator<<(v5, v4->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v37.vfptr);
  }
  if ( v4->m_dimensions == 3 )
  {
    v7 = v4->m_mesh.m_triangles.m_used;
    for ( LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(maxCosAngle), (__m128)LODWORD(maxCosAngle), 0);
          v7;
          v7 = v7->m_next )
    {
      v9 = 0;
      v10 = v7->m_links;
      do
      {
        v11 = *v10 & 0xFFFFFFFFFFFFFFFCui64;
        v12 = 0;
        v13 = v7->m_vertices[(9i64 >> 2 * (unsigned __int8)v9) & 3];
        v14 = *(v10 - 3) - (_QWORD)v13;
        v15 = v13->m_x;
        do
        {
          v16 = *(int *)((char *)v15 + v14);
          if ( v16 < *v15 )
            break;
          if ( v16 > *v15 )
          {
            if ( v11 )
              goto LABEL_23;
            break;
          }
          ++v12;
          ++v15;
        }
        while ( v12 < 3 );
        v17 = v7->m_plane.m_index;
        if ( (_DWORD)v17 != *(_DWORD *)(v11 + 88) )
        {
          v18 = v4->m_planes.m_data;
          v19 = v18[*(signed int *)(v11 + 88)].m_quad;
          v20 = _mm_mul_ps(v18[v17].m_quad, v19);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))) < v8 )
          {
            v21 = _mm_add_ps(v18[v17].m_quad, v19);
            v22 = _mm_mul_ps(v21, v21);
            v23 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170));
            v24 = _mm_rsqrt_ps(v23);
            v25 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v23), (__m128)0i64);
            v26 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v23, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                            _mm_mul_ps(*(__m128 *)_xmm, v24))),
                        v21),
                      v25),
                    _mm_andnot_ps(v25, v21));
            if ( _mm_movemask_ps(v25) )
            {
              v27 = v4->m_scaleInv.m_quad;
              v28 = v4->m_origin.m_quad;
              v29 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          (__m128)_mm_srli_si128(
                                    _mm_slli_si128(
                                      (__m128i)_mm_cvtepi32_ps(
                                                 _mm_unpacklo_epi32(
                                                   _mm_unpacklo_epi32(
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(v10 - 3) + 32)),
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(v10 - 3) + 40))),
                                                   _mm_unpacklo_epi32(
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(v10 - 3) + 36)),
                                                     _mm_cvtsi32_si128(0)))),
                                      4),
                                    4),
                          v27),
                        v28),
                      v26);
              v30 = _mm_shuffle_ps(
                      v26,
                      _mm_unpackhi_ps(
                        v26,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170))),
                      196);
              if ( v4->m_config.m_ensurePlaneEnclosing.m_bool )
              {
                for ( i = v4->m_mesh.m_vertices.m_used;
                      i;
                      v30 = _mm_shuffle_ps(
                              v30,
                              _mm_unpackhi_ps(
                                v30,
                                _mm_max_ps(
                                  _mm_shuffle_ps(v30, v30, 255),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                                    _mm_shuffle_ps(v35, v35, 170)))),
                              196) )
                {
                  v32 = _mm_cvtsi32_si128(i->m_x[2]);
                  v33 = _mm_cvtsi32_si128(i->m_x[1]);
                  v34 = _mm_cvtsi32_si128(i->m_x[0]);
                  i = i->m_next;
                  v35 = _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              (__m128)_mm_srli_si128(
                                        _mm_slli_si128(
                                          (__m128i)_mm_cvtepi32_ps(
                                                     _mm_unpacklo_epi32(
                                                       _mm_unpacklo_epi32(v34, v32),
                                                       _mm_unpacklo_epi32(v33, _mm_cvtsi32_si128(0)))),
                                          4),
                                        4),
                              v27),
                            v28),
                          v30);
                }
              }
              v36 = _mm_shuffle_ps(
                      v30,
                      _mm_unpackhi_ps(v30, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v30, v30, 255))),
                      196);
              if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
              v3->m_data[v3->m_size++].m_quad = v36;
            }
          }
        }
LABEL_23:
        ++v9;
        ++v10;
      }
      while ( v9 < 3 );
    }
  }
}

// File Line: 1224
// RVA: 0xCB89E0
hkResult *__fastcall hkgpConvexHullImpl::simplify(hkgpConvexHullImpl *this, hkResult *result, hkgpConvexHull::SimplifyConfig *config)
{
  bool v3; // zf
  hkgpConvexHull::SimplifyConfig *v4; // r15
  bool v5; // r12
  int v6; // eax
  hkResult *v7; // r13
  hkgpConvexHullImpl *v8; // rsi
  int v9; // ebx
  float v10; // xmm9_4
  float v11; // xmm9_4
  hkgpConvexHullImpl::Triangle *v12; // rcx
  float v13; // xmm5_4
  hkgpConvexHullImpl::Triangle *v14; // r11
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  float v23; // xmm3_4
  __m128 *v24; // rdi
  signed int v25; // ebx
  __m128 *v26; // r14
  __m128 **v27; // r9
  signed int v28; // er8
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  float v31; // xmm3_4
  int v32; // er10
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  float v35; // xmm2_4
  int v36; // er9
  int v37; // er8
  hkgpConvexHullImpl::Vertex *i; // rbx
  hkOstream *v39; // rax
  hkOstream *v40; // rax
  int v41; // er11
  int v42; // edx
  int v43; // edi
  __int64 v44; // rbx
  int v45; // er8
  signed __int64 v46; // rcx
  int *v47; // r14
  int v48; // ebx
  int v49; // eax
  int v50; // er9
  hkgpConvexHullImpl::Vertex *v51; // rcx
  hkBaseObjectVtbl *v52; // r8
  hkBaseObjectVtbl *v53; // rax
  int v54; // ebx
  int v55; // er9
  __int64 v56; // rdx
  __int64 v57; // r8
  int v58; // ebx
  hkVector4f *v59; // rdx
  int v60; // er8
  int v61; // er9
  hkgpConvexHullImpl::Vertex *v62; // rcx
  int v63; // er8
  hkVector4f *v64; // rax
  hkVector4f *array; // [rsp+30h] [rbp-D0h]
  int numPoints; // [rsp+38h] [rbp-C8h]
  int v68; // [rsp+3Ch] [rbp-C4h]
  hkArray<int,hkContainerHeapAllocator> vi; // [rsp+40h] [rbp-C0h]
  hkVector4f *points; // [rsp+50h] [rbp-B0h]
  int v71; // [rsp+58h] [rbp-A8h]
  int v72; // [rsp+5Ch] [rbp-A4h]
  hkResult v73; // [rsp+60h] [rbp-A0h]
  hkErrStream v74; // [rsp+68h] [rbp-98h]
  hkResult v75; // [rsp+80h] [rbp-80h]
  hkArray<int,hkContainerHeapAllocator> vpf; // [rsp+88h] [rbp-78h]
  char buf; // [rsp+A0h] [rbp-60h]
  hkResult v78; // [rsp+320h] [rbp+220h]
  bool v79; // [rsp+330h] [rbp+230h]
  hkResult resulta; // [rsp+338h] [rbp+238h]

  v3 = config->m_forceRebuild.m_bool == 0;
  v4 = config;
  v79 = this->m_hasMassProperties;
  v5 = !v3;
  LOBYTE(v78.m_enum) = this->m_hasIndexing;
  v6 = this->m_dimensions;
  v7 = result;
  v8 = this;
  if ( v6 < 0 )
    goto LABEL_103;
  if ( v6 > 2 )
  {
    if ( v6 == 3 )
    {
      if ( config->m_maxVertices >= 4 )
      {
        v9 = this->m_mesh.m_vertices.m_numUsed;
        hkgpConvexHullImpl::decimateVertices(this, config->m_maxVertices, config->m_ensureContainment.m_bool != 0, 0);
        v5 = v8->m_mesh.m_vertices.m_numUsed != v9;
      }
      if ( v4->m_minArea > 0.0 )
      {
        LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(v4->m_minArea),
                                            (__m128)LODWORD(v4->m_minArea),
                                            0);
        v11 = v10 + v10;
        do
        {
          v12 = v8->m_mesh.m_triangles.m_used;
          v13 = v11;
          v14 = 0i64;
          if ( !v12 )
            break;
          do
          {
            v15 = v12->m_vertices[0]->m_source.m_quad;
            v16 = _mm_sub_ps(v12->m_vertices[1]->m_source.m_quad, v15);
            v17 = _mm_sub_ps(v12->m_vertices[2]->m_source.m_quad, v15);
            v18 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16),
                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17));
            v19 = _mm_shuffle_ps(v18, v18, 201);
            v20 = _mm_mul_ps(v19, v19);
            v21 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170));
            v22 = _mm_rsqrt_ps(v21);
            LODWORD(v23) = (unsigned __int128)_mm_andnot_ps(
                                                _mm_cmpleps(v21, (__m128)0i64),
                                                _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                    _mm_mul_ps(*(__m128 *)_xmm, v22)),
                                                  v21));
            if ( v23 < v13 )
            {
              v13 = v23;
              v14 = v12;
            }
            v12 = v12->m_next;
          }
          while ( v12 );
          if ( !v14 )
            break;
          v24 = (__m128 *)v14->m_vertices[1];
          v25 = 0;
          v26 = (__m128 *)v14->m_vertices[0];
          v27 = (__m128 **)&v14->m_vertices[1];
          v28 = 1;
          v29 = _mm_sub_ps(v26[1], v24[1]);
          v30 = _mm_mul_ps(v29, v29);
          v31 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170));
          do
          {
            v32 = v28 + 1;
            v33 = _mm_sub_ps((*v27)[1], v14->m_vertices[(v28 + 1) % 3]->m_source.m_quad);
            v34 = _mm_mul_ps(v33, v33);
            v35 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170));
            if ( v35 > v31 )
            {
              v31 = v35;
              v25 = v28;
            }
            ++v27;
            ++v28;
          }
          while ( v32 < 3 );
          if ( v25 )
          {
            if ( v25 == 1 )
              v26[3].m128_i32[1] = -1;
            else
              v24[3].m128_i32[1] = -1;
          }
          else
          {
            v14->m_vertices[2]->m_index = -1;
          }
          v36 = v8->m_mesh.m_vertices.m_numUsed;
          v68 = 2147483648;
          array = 0i64;
          v37 = 0;
          numPoints = 0;
          if ( v36 <= 0 )
          {
            resulta.m_enum = 0;
          }
          else
          {
            if ( v36 < 0 )
              v36 = 0;
            hkArrayUtil::_reserve(
              &resulta,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &array,
              v36,
              16);
            v37 = numPoints;
          }
          for ( i = v8->m_mesh.m_vertices.m_used; i; i = i->m_next )
          {
            if ( i->m_index != -1 )
            {
              if ( v37 == (v68 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                v37 = numPoints;
              }
              array[v37] = i->m_source;
              v37 = numPoints++ + 1;
            }
          }
          if ( hkgpConvexHullImpl::build(v8, array, v37, 0, 0i64) == 3 )
            hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v8);
          v5 = 1;
          numPoints = 0;
          if ( v68 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              16 * v68);
          v3 = v8->m_dimensions == 3;
          array = 0i64;
          v68 = 2147483648;
        }
        while ( v3 );
      }
      if ( v4->m_removeUnreferencedVertices.m_bool && v8->m_dimensions == 3 )
      {
        if ( !v8->m_hasIndexing )
        {
          hkErrStream::hkErrStream(&v74, &buf, 512);
          v39 = hkOstream::operator<<((hkOstream *)&v74.vfptr, "No index available (");
          v40 = hkOstream::operator<<(v39, v8->m_uid, (int)v39);
          hkOstream::operator<<(v40, ") hkgpConvexHull::buildIndices need to be called before this operation.");
          if ( (unsigned int)hkError::messageError(
                               2046417030,
                               &buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgp"
                               "ConvexHullInternals.h",
                               358) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v74.vfptr);
        }
        vpf.m_data = 0i64;
        vpf.m_capacityAndFlags = 2147483648;
        vi.m_data = 0i64;
        vi.m_capacityAndFlags = 2147483648;
        array = 0i64;
        v68 = 2147483648;
        do
        {
          vpf.m_size = 0;
          vi.m_size = 0;
          numPoints = 0;
          hkgpConvexHullImpl::generateIndexedFaces<int,int>(v8, &vpf, &vi, 0, 0);
          v41 = vi.m_size;
          v42 = numPoints;
          v43 = 0;
          if ( vi.m_size > 0 )
          {
            v44 = 0i64;
            do
            {
              v45 = 0;
              v46 = 0i64;
              if ( v42 <= 0 )
                goto LABEL_52;
              while ( array->m_quad.m128_i32[v46] != vi.m_data[v44] )
              {
                ++v46;
                ++v45;
                if ( v46 >= v42 )
                  goto LABEL_52;
              }
              if ( v45 == -1 )
              {
LABEL_52:
                v47 = vi.m_data;
                if ( v42 == (v68 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
                  v42 = numPoints;
                }
                array->m_quad.m128_i32[v42] = v47[v44];
                v41 = vi.m_size;
                v42 = numPoints++ + 1;
              }
              ++v43;
              ++v44;
            }
            while ( v43 < v41 );
          }
          v48 = v8->m_mesh.m_vertices.m_numUsed;
          if ( v42 >= v48 )
            break;
          v49 = 0;
          v5 = 1;
          v74.vfptr = 0i64;
          *(_DWORD *)(&v74.m_referenceCount + 1) = 2147483648;
          points = 0i64;
          v71 = 0;
          *(_DWORD *)&v74.m_memSizeAndFlags = 0;
          v72 = 2147483648;
          if ( v48 <= 0 )
          {
            v75.m_enum = 0;
          }
          else
          {
            v50 = v48;
            if ( v48 < 0 )
              v50 = 0;
            hkArrayUtil::_reserve(&v75, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v74, v50, 16);
            v42 = numPoints;
            v49 = *(_DWORD *)&v74.m_memSizeAndFlags;
          }
          v51 = v8->m_mesh.m_vertices.m_used;
          v52 = v74.vfptr;
          *(_DWORD *)&v74.m_memSizeAndFlags = v48 + v49;
          if ( v51 )
          {
            do
            {
              v53 = v52;
              ++v52;
              *v53 = (hkBaseObjectVtbl)v51->m_source;
              v51 = v51->m_next;
            }
            while ( v51 );
            v42 = numPoints;
          }
          v54 = v42;
          if ( (v72 & 0x3FFFFFFF) >= v42 )
          {
            v73.m_enum = 0;
          }
          else
          {
            if ( v42 < 2 * (v72 & 0x3FFFFFFF) )
              v42 = 2 * (v72 & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v73, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, v42, 16);
            v42 = numPoints;
          }
          v71 = v54;
          v55 = 0;
          if ( v42 > 0 )
          {
            v56 = 0i64;
            v57 = 0i64;
            do
            {
              ++v55;
              ++v57;
              ++v56;
              points[v56 - 1] = (hkVector4f)v74.vfptr[array->m_quad.m128_i32[v57 - 1]];
            }
            while ( v55 < numPoints );
            v54 = v71;
          }
          if ( hkgpConvexHullImpl::build(v8, points, v54, 0, 0i64) == 3 )
            hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v8);
          v71 = 0;
          if ( v72 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              points,
              16 * v72);
          points = 0i64;
          v72 = 2147483648;
          *(_DWORD *)&v74.m_memSizeAndFlags = 0;
          if ( *(_DWORD *)(&v74.m_referenceCount + 1) >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v74.vfptr,
              16 * *(_DWORD *)(&v74.m_referenceCount + 1));
          v3 = v8->m_dimensions == 3;
          v74.vfptr = 0i64;
          *(_DWORD *)(&v74.m_referenceCount + 1) = 2147483648;
        }
        while ( v3 );
        numPoints = 0;
        if ( v68 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * v68);
        array = 0i64;
        v68 = 2147483648;
        vi.m_size = 0;
        if ( vi.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vi.m_data,
            4 * vi.m_capacityAndFlags);
        vi.m_data = 0i64;
        vi.m_capacityAndFlags = 2147483648;
        vpf.m_size = 0;
        if ( vpf.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vpf.m_data,
            4 * vpf.m_capacityAndFlags);
      }
      if ( v5 && v8->m_dimensions == 3 )
      {
        v58 = v8->m_mesh.m_vertices.m_numUsed;
        v59 = 0i64;
        v60 = 0;
        vi.m_size = 0;
        vi.m_capacityAndFlags = 2147483648;
        vi.m_data = 0i64;
        if ( v58 > 0 )
        {
          v61 = v58;
          if ( v58 < 0 )
            v61 = 0;
          hkArrayUtil::_reserve(&v73, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &vi, v61, 16);
          v60 = vi.m_size;
          v59 = (hkVector4f *)vi.m_data;
        }
        v62 = v8->m_mesh.m_vertices.m_used;
        v63 = v58 + v60;
        vi.m_size = v63;
        if ( v62 )
        {
          do
          {
            v64 = v59;
            ++v59;
            *v64 = v62->m_source;
            v62 = v62->m_next;
          }
          while ( v62 );
          v63 = vi.m_size;
          v59 = (hkVector4f *)vi.m_data;
        }
        hkgpConvexHullImpl::build(v8, v59, v63, 0, 0i64);
        if ( LOBYTE(v78.m_enum) )
          hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v8);
        if ( v79 )
          hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v8, &v78);
        vi.m_size = 0;
        if ( vi.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vi.m_data,
            16 * vi.m_capacityAndFlags);
      }
      goto LABEL_102;
    }
LABEL_103:
    result->m_enum = 1;
    return v7;
  }
LABEL_102:
  v7->m_enum = 0;
  return v7;
}

// File Line: 1405
// RVA: 0xCB7DE0
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::maxDistance(hkgpConvexHullImpl *this, hkSimdFloat32 *result, hkArray<hkVector4f,hkContainerHeapAllocator> *points, hkVector4f *planeOut)
{
  int v4; // er10
  hkgpConvexHullImpl *v5; // rbx
  int v6; // er10
  hkgpConvexHullImpl::Triangle *v7; // rax
  char *v8; // rcx
  int v9; // ebx
  int v10; // er11
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __int64 v22; // r10
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  char *v30; // rcx
  hkgpConvexHullImpl::Vertex *v31; // r11
  hkgpConvexHullImpl::Vertex *v32; // rax
  hkgpConvexHullImpl::Vertex *v33; // rcx
  __m128 v34; // xmm8
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  int v43; // er10
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __int64 v46; // rcx
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm4
  hkVector4f v52; // xmm1
  char v54; // [rsp+60h] [rbp+8h]

  v4 = this->m_dimensions;
  v5 = this;
  *result = (hkSimdFloat32)xmmword_141A712F0;
  v6 = v4 - 2;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      v7 = this->m_mesh.m_triangles.m_used;
      v8 = &v54;
      if ( !v7 )
        v8 = 0i64;
      if ( v8 )
      {
        v9 = points->m_size;
        do
        {
          v10 = 0;
          v11 = v7->m_vertices[0]->m_source.m_quad;
          v12 = _mm_sub_ps(v7->m_vertices[1]->m_source.m_quad, v11);
          v13 = _mm_sub_ps(v7->m_vertices[2]->m_source.m_quad, v11);
          v14 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12),
                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
          v15 = _mm_shuffle_ps(v14, v14, 201);
          v16 = _mm_mul_ps(v15, v15);
          v17 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170));
          v18 = _mm_rsqrt_ps(v17);
          v19 = _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v17, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                      _mm_mul_ps(*(__m128 *)_xmm, v18))),
                  v15);
          v20 = _mm_mul_ps(v11, v19);
          v21 = _mm_shuffle_ps(
                  v19,
                  _mm_unpackhi_ps(
                    v19,
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                        _mm_shuffle_ps(v20, v20, 170)))),
                  196);
          if ( v9 > 0 )
          {
            v22 = 0i64;
            do
            {
              ++v10;
              ++v22;
              v23 = _mm_mul_ps(points->m_data[v22 - 1].m_quad, v21);
              v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v21), 196);
              v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
              v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
              v27 = _mm_cmpltps(result->m_real, v26);
              v28 = _mm_and_ps(v27, v26);
              v29 = _mm_andnot_ps(v27, planeOut->m_quad);
              result->m_real = _mm_or_ps(_mm_andnot_ps(v27, result->m_real), v28);
              planeOut->m_quad = _mm_or_ps(v29, _mm_and_ps(v21, v27));
              v9 = points->m_size;
            }
            while ( v10 < v9 );
          }
          v7 = v7->m_next;
          v30 = &v54;
          if ( !v7 )
            v30 = 0i64;
        }
        while ( v30 );
      }
    }
  }
  else
  {
    v31 = this->m_mesh.m_vertices.m_used;
    v32 = v31;
    if ( v31 )
    {
      v33 = v31->m_next;
      if ( v31->m_next )
      {
        do
        {
          v32 = v33;
          v33 = v33->m_next;
        }
        while ( v33 );
      }
      for ( ; v31; v31 = v31->m_next )
      {
        v34 = v32->m_source.m_quad;
        v35 = _mm_sub_ps(v31->m_source.m_quad, v34);
        v36 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v5->m_projectionPlane.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v5->m_projectionPlane.m_quad, v5->m_projectionPlane.m_quad, 201), v35));
        v37 = _mm_shuffle_ps(v36, v36, 201);
        v38 = _mm_mul_ps(v37, v37);
        v39 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170));
        v40 = _mm_rsqrt_ps(v39);
        v41 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v39), (__m128)0i64);
        v42 = _mm_or_ps(
                _mm_and_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v39, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                        _mm_mul_ps(*(__m128 *)_xmm, v40))),
                    v37),
                  v41),
                _mm_andnot_ps(v41, v37));
        if ( _mm_movemask_ps(v41) )
        {
          v43 = 0;
          v44 = _mm_mul_ps(v42, v34);
          v45 = _mm_shuffle_ps(
                  v42,
                  _mm_unpackhi_ps(
                    v42,
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                        _mm_shuffle_ps(v44, v44, 170)))),
                  196);
          if ( points->m_size > 0 )
          {
            v46 = 0i64;
            do
            {
              ++v43;
              ++v46;
              v47 = _mm_mul_ps(points->m_data[v46 - 1].m_quad, v45);
              v48 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v45), 196);
              v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 78), v48);
              v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v49);
              v51 = _mm_cmpltps(result->m_real, v50);
              v52.m_quad = _mm_or_ps(_mm_andnot_ps(v51, planeOut->m_quad), _mm_and_ps(v45, v51));
              result->m_real = _mm_or_ps(_mm_and_ps(v51, v50), _mm_andnot_ps(v51, result->m_real));
              *planeOut = (hkVector4f)v52.m_quad;
            }
            while ( v43 < points->m_size );
          }
        }
        v32 = v31;
      }
    }
  }
  return result;
}

// File Line: 1468
// RVA: 0xCB84C0
void __fastcall hkgpConvexHullImpl::refitDomainFromSources(hkgpConvexHullImpl *this)
{
  int v1; // edi
  hkVector4f *v2; // rdx
  hkgpConvexHullImpl *v3; // rbx
  int v4; // er8
  int v5; // er9
  hkgpConvexHullImpl::Vertex *v6; // rcx
  int v7; // er8
  hkVector4f *v8; // rax
  __m128 *v9; // rax
  char *v10; // rcx
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128i v16; // xmm1
  char *v17; // rcx
  hkVector4f *points; // [rsp+30h] [rbp-78h]
  int numPoints; // [rsp+38h] [rbp-70h]
  int v20; // [rsp+3Ch] [rbp-6Ch]
  __int64 v21; // [rsp+60h] [rbp-48h]
  int v22; // [rsp+68h] [rbp-40h]
  char v23; // [rsp+B0h] [rbp+8h]

  v1 = this->m_mesh.m_vertices.m_numUsed;
  v2 = 0i64;
  v3 = this;
  points = 0i64;
  v4 = 0;
  numPoints = 0;
  v20 = 2147483648;
  if ( v1 > 0 )
  {
    v5 = v1;
    if ( v1 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&v23,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &points,
      v5,
      16);
    v4 = numPoints;
    v2 = points;
  }
  v6 = v3->m_mesh.m_vertices.m_used;
  v7 = v1 + v4;
  numPoints = v7;
  if ( v6 )
  {
    do
    {
      v8 = v2;
      ++v2;
      *v8 = v6->m_source;
      v6 = v6->m_next;
    }
    while ( v6 );
    v7 = numPoints;
    v2 = points;
  }
  hkgpConvexHullImpl::rebuildDomainParameters(v3, v2, v7);
  v9 = (__m128 *)v3->m_mesh.m_vertices.m_used;
  v10 = &v23;
  if ( !v9 )
    v10 = 0i64;
  if ( v10 )
  {
    do
    {
      v11 = _mm_mul_ps(_mm_sub_ps(v9[1], v3->m_origin.m_quad), v3->m_scale.m_quad);
      v12 = _mm_cmpltps(v11, (__m128)_xmm);
      v13 = _mm_max_ps(
              (__m128)_xmm_c6000000c6000000c6000000c6000000,
              _mm_or_ps(_mm_andnot_ps(v12, (__m128)_xmm), _mm_and_ps(v11, v12)));
      v14 = _mm_cmpltps(v13, (__m128)0i64);
      v15 = _mm_or_ps(
              _mm_andnot_ps(v14, _mm_add_ps(v13, (__m128)xmmword_141A711B0)),
              _mm_and_ps(_mm_sub_ps(v13, (__m128)xmmword_141A711B0), v14));
      v16 = _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v15),
              _mm_cvttps_epi32(v15));
      v21 = v16.m128i_i64[0];
      v9[2].m128_u64[0] = v16.m128i_i64[0];
      v22 = (unsigned __int128)_mm_shuffle_epi32(v16, 170);
      v9[2].m128_i32[2] = v22;
      v9 = (__m128 *)v9->m128_u64[0];
      v17 = &v23;
      if ( !v9 )
        v17 = 0i64;
    }
    while ( v17 );
  }
  numPoints = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points,
      16 * v20);
}

// File Line: 1491
// RVA: 0xCB5FB0
hkBool *__fastcall hkgpConvexHullImpl::ensureContainment(hkgpConvexHullImpl *this, hkBool *result, hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  hkVector4f *v3; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rbx
  hkBool *v5; // r15
  hkgpConvexHullImpl *v6; // rdi
  int v7; // eax
  __int32 v8; // ebp
  __int64 v9; // r10
  __int64 v10; // rdx
  hkVector4f *v11; // rcx
  signed __int64 v12; // r8
  hkVector4f v13; // xmm0
  hkVector4f *v14; // rdx
  __int64 v15; // r9
  __int64 v16; // rcx
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  hkVector4f *v19; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  bool v24; // r14
  bool v25; // bl
  int v26; // eax
  bool v27; // r12
  bool v28; // r13
  float v29; // xmm8_4
  char v30; // r14
  int v31; // ebp
  __m128 *v32; // rax
  __m128 *v33; // rcx
  __m128 *v34; // rdx
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  float v37; // xmm3_4
  __m128 v38; // xmm1
  float v39; // xmm2_4
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm2
  __m128 v44; // xmm6
  __m128 v45; // xmm1
  __m128 v46; // xmm5
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  __m128 v51; // xmm0
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  hkResult *v54; // rcx
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  hkResult *v57; // rcx
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  hkVector4f planeOut; // [rsp+20h] [rbp-A8h]
  hkSimdFloat32 v64; // [rsp+30h] [rbp-98h]
  hkResult v65; // [rsp+D0h] [rbp+8h]
  hkResult resulta; // [rsp+E8h] [rbp+20h]

  v3 = 0i64;
  v4 = points;
  v5 = result;
  v6 = this;
  if ( this->m_dimensions == 3 )
  {
    v7 = this->m_planes.m_size;
    v8 = 2147483648;
    if ( v7 > 0 )
    {
      v65.m_enum = 16 * v7;
      v3 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                           (int *)&v65);
      v8 = v65.m_enum / 16;
    }
    v9 = (unsigned int)v6->m_planes.m_size;
    v10 = (signed int)v9;
    if ( (signed int)v9 > 0 )
    {
      v11 = v3;
      v12 = (char *)v6->m_planes.m_data - (char *)v3;
      do
      {
        v13.m_quad = *(__m128 *)((char *)v11 + v12);
        ++v11;
        v11[-1] = (hkVector4f)v13.m_quad;
        --v10;
      }
      while ( v10 );
      if ( (signed int)v9 > 0 )
      {
        v14 = v3;
        v15 = v9;
        do
        {
          v16 = v4->m_size;
          v17 = v14->m_quad;
          v18 = 0i64;
          if ( v16 > 0 )
          {
            v19 = v4->m_data;
            do
            {
              ++v19;
              v20 = _mm_mul_ps(v17, v19[-1].m_quad);
              v21 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v17), 196);
              v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
              v18 = _mm_max_ps(aabbOut.m_quad, _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22));
              --v16;
            }
            while ( v16 );
          }
          v23 = v14->m_quad;
          ++v14;
          v14[-1].m_quad = _mm_shuffle_ps(
                             v23,
                             _mm_unpackhi_ps(v23, _mm_sub_ps(_mm_shuffle_ps(v23, v23, 255), v18)),
                             196);
          --v15;
        }
        while ( v15 );
      }
    }
    v24 = v6->m_hasMassProperties;
    v25 = v6->m_hasIndexing;
    hkgpConvexHull::buildFromPlanes(v6->m_hull, v3, v9, &v6->m_config);
    if ( v25 )
      hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
    if ( v24 )
      hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, &resulta);
    v5->m_bool = 1;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3,
        16 * v8);
  }
  else
  {
    v26 = points->m_size;
    v27 = this->m_hasMassProperties;
    v28 = this->m_hasIndexing;
    v65.m_enum = LODWORD(FLOAT_0_0000099999997);
    LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)(unsigned int)v65.m_enum,
                                        (__m128)(unsigned int)v65.m_enum,
                                        0);
    v30 = 0;
    v31 = 0;
    if ( 2 * v26 > 0 )
    {
      while ( 1 )
      {
        planeOut.m_quad = 0i64;
        hkgpConvexHullImpl::maxDistance(v6, &v64, v4, &planeOut);
        if ( COERCE_FLOAT((unsigned int)(2 * v64.m_real.m128_i32[0]) >> 1) <= v29 )
          break;
        v32 = (__m128 *)v6->m_mesh.m_vertices.m_used;
        v33 = (__m128 *)v32->m128_u64[0];
        v34 = (__m128 *)v6->m_mesh.m_vertices.m_used;
        v35 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), planeOut.m_quad);
        v36 = _mm_mul_ps(v32[1], v35);
        v37 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170));
        if ( v32->m128_u64[0] )
        {
          do
          {
            v38 = _mm_mul_ps(v33[1], v35);
            v39 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170));
            if ( v39 > v37 )
            {
              v34 = v33;
              v37 = v39;
            }
            v33 = (__m128 *)v33->m128_u64[0];
          }
          while ( v33 );
        }
        v40 = _mm_mul_ps(v34[1], planeOut.m_quad);
        v41 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, planeOut.m_quad), 196);
        v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 78), v41);
        v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 177), v42);
        v44 = _mm_shuffle_ps(
                planeOut.m_quad,
                _mm_unpackhi_ps(planeOut.m_quad, _mm_sub_ps(_mm_shuffle_ps(planeOut.m_quad, planeOut.m_quad, 255), v43)),
                196);
        v45 = _mm_mul_ps(_mm_sub_ps(v34[1], _mm_mul_ps(planeOut.m_quad, v43)), v44);
        v46 = _mm_mul_ps(_mm_sub_ps(v34[1], _mm_mul_ps(_mm_sub_ps(v43, v64.m_real), planeOut.m_quad)), v44);
        v47 = _mm_shuffle_ps(v45, _mm_unpackhi_ps(v45, v44), 196);
        v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 78), v47);
        v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 177), v48);
        v50 = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, v44), 196);
        v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 78), v50);
        v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 177), v51);
        if ( v49.m128_f32[0] <= 0.00000011920929 )
          break;
        v53 = _mm_rcp_ps(v49);
        v54 = &v65;
        if ( !v32 )
          v54 = 0i64;
        v55 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v53, v49)), v53), v52);
        if ( v54 )
        {
          do
          {
            v56 = v32[1];
            v57 = &v65;
            v58 = _mm_mul_ps(v44, v56);
            v59 = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, v44), 196);
            v60 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
            v61 = _mm_add_ps(
                    _mm_sub_ps(v56, _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60), v44)),
                    _mm_mul_ps(_mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60), v55), v44));
            v32[1] = _mm_shuffle_ps(v61, _mm_unpackhi_ps(v61, _mm_shuffle_ps(v32[1], v32[1], 255)), 196);
            v32 = (__m128 *)v32->m128_u64[0];
            if ( !v32 )
              v57 = 0i64;
          }
          while ( v57 );
        }
        ++v31;
        v30 = 1;
        if ( v31 >= 2 * v4->m_size )
          goto LABEL_35;
      }
      if ( !v30 )
        goto LABEL_39;
LABEL_35:
      hkgpConvexHullImpl::refitDomainFromSources(v6);
      if ( v28 )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
      if ( v27 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, &v65);
    }
LABEL_39:
    v5->m_bool = 1;
  }
  return v5;
}ullImpl::buildIndices<hkgpConvexHull

// File Line: 1569
// RVA: 0xCB4E90
char __fastcall hkgpConvexHullImpl::decimateVertices(hkgpConvexHullImpl *this, int numVerticesToKeep, bool containment, bool useCgo)
{
  bool v4; // di
  signed int v5; // er12
  hkgpConvexHullImpl *v6; // r13
  hkgpConvexHull *v7; // rbx
  bool v8; // si
  bool v9; // r14
  signed int v10; // edi
  hkgpConvexHull *v11; // rbx
  hkgpConvexHullImpl *v12; // rax
  int v13; // ecx
  char v14; // bl
  bool v16; // zf
  int v17; // eax
  int v18; // ebx
  int v19; // er9
  hkgpConvexHullImpl::Vertex *v20; // rcx
  hkVector4f *v21; // rdx
  hkVector4f *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  int v25; // er9
  char v26; // al
  bool v27; // al
  int v28; // er9
  int v29; // ebx
  int v30; // eax
  int v31; // ecx
  int v32; // er9
  hkgpConvexHullImpl::Vertex *v33; // rcx
  hkVector4f *v34; // rdx
  hkVector4f *v35; // rax
  hkgpConvexHullImpl::Vertex *v36; // rax
  hkgpConvexHullImpl::Triangle *v37; // r14
  signed int v38; // esi
  float v39; // xmm9_4
  __int64 v40; // rbx
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  char v43; // di
  unsigned int *v44; // rcx
  unsigned int *v45; // rax
  __m128i v46; // xmm8
  unsigned int *v47; // rcx
  __m128 v48; // xmm8
  __m128i v49; // xmm4
  unsigned int *v50; // rcx
  __m128i v51; // xmm3
  signed __int64 v52; // rax
  unsigned __int64 v53; // rdx
  unsigned __int64 v54; // rcx
  __int64 v55; // rdx
  __int64 v56; // rdi
  __m128 v57; // xmm6
  __m128 v58; // xmm7
  __int64 v59; // rbx
  unsigned int *v60; // rcx
  unsigned int *v61; // rax
  __m128i v62; // xmm8
  unsigned int *v63; // rcx
  __m128 v64; // xmm8
  __m128i v65; // xmm4
  unsigned int *v66; // rcx
  __m128i v67; // xmm3
  __int64 v68; // rcx
  __int64 v69; // rdx
  int v70; // er8
  hkgpConvexHullImpl::SortedEdge *v71; // rcx
  unsigned __int64 v72; // rdx
  __int64 v73; // rax
  hkgpConvexHullImpl::Vertex *k; // rax
  int v75; // er14
  __int64 v76; // rsi
  int v77; // eax
  __int64 v78; // r12
  __int64 v79; // rdi
  char v80; // r10
  hkgpConvexHullImpl::Vertex *v81; // rdx
  hkgpConvexHullImpl::Triangle *v82; // r11
  __int64 v83; // rbx
  const float *v84; // r9
  char v85; // cl
  __int64 v86; // rdx
  float v87; // xmm0_4
  signed __int64 v88; // rax
  unsigned __int64 v89; // rdx
  unsigned __int64 v90; // rcx
  __int64 v91; // rdx
  const float *v92; // rdx
  __int64 v93; // r8
  __int64 v94; // rcx
  float v95; // xmm0_4
  __int64 v96; // rcx
  __int64 v97; // rdi
  __int64 v98; // rbx
  hkgpConvexHullImpl::Vertex *v99; // rdx
  hkgpConvexHullImpl::Vertex *v100; // rax
  hkgpConvexHullImpl::Vertex *v101; // rcx
  hkgpConvexHullImpl::Vertex *v102; // rdx
  hkgpConvexHullImpl::Vertex *v103; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v104; // rax
  unsigned __int64 v105; // rcx
  int v106; // ebx
  hkVector4f *v107; // rdx
  int v108; // er8
  int v109; // er9
  hkgpConvexHullImpl::Vertex *v110; // rcx
  int v111; // er8
  hkVector4f *v112; // rax
  hkVector4f *v113; // rdx
  hkOstream *v114; // rax
  hkOstream *v115; // rax
  bool v116; // r14
  int v117; // ecx
  hkVector4f *v118; // r8
  hkgpConvexHullImpl::Vertex *v119; // rbx
  float v120; // xmm6_4
  signed int v121; // edi
  hkResult *v122; // rax
  hkResult *v123; // rax
  int v124; // er11
  int v125; // edx
  __int64 v126; // r9
  signed __int64 v127; // r10
  signed __int64 v128; // rax
  __m128 v129; // xmm0
  __m128 v130; // xmm2
  __m128 v131; // xmm1
  __m128 v132; // xmm3
  __m128 v133; // xmm3
  __m128 v134; // xmm3
  __m128 v135; // xmm4
  __m128 v136; // xmm2
  float v137; // xmm3_4
  bool v138; // [rsp+30h] [rbp-D0h]
  bool v139; // [rsp+30h] [rbp-D0h]
  hkVector4f *v140; // [rsp+38h] [rbp-C8h]
  int numPoints; // [rsp+40h] [rbp-C0h]
  int v142; // [rsp+44h] [rbp-BCh]
  char v143; // [rsp+48h] [rbp-B8h]
  hkgpConvexHullImpl::SortedEdge *pArr; // [rsp+50h] [rbp-B0h]
  int j; // [rsp+58h] [rbp-A8h]
  int v146; // [rsp+5Ch] [rbp-A4h]
  hkgpConvexHull::BuildConfig array; // [rsp+60h] [rbp-A0h]
  hkStridedVertices points; // [rsp+70h] [rbp-90h]
  hkVector4f *v149; // [rsp+80h] [rbp-80h]
  int i; // [rsp+88h] [rbp-78h]
  int v151; // [rsp+8Ch] [rbp-74h]
  hkResult result; // [rsp+90h] [rbp-70h]
  __int128 v153; // [rsp+A0h] [rbp-60h]
  hkResult v154; // [rsp+B0h] [rbp-50h]
  hkResult v155; // [rsp+B4h] [rbp-4Ch]
  hkGeometry geometry; // [rsp+B8h] [rbp-48h]
  hkResult v157; // [rsp+E8h] [rbp-18h]
  hkgpCgo::Config config; // [rsp+F0h] [rbp-10h]
  hkVector4f plane; // [rsp+140h] [rbp+40h]
  __m128i v160; // [rsp+150h] [rbp+50h]
  __m128i v161; // [rsp+160h] [rbp+60h]
  __m128i v162; // [rsp+170h] [rbp+70h]
  __m128i v163; // [rsp+180h] [rbp+80h]
  __m128i v164; // [rsp+190h] [rbp+90h]
  __m128i v165; // [rsp+1A0h] [rbp+A0h]
  __m128i v166; // [rsp+1B0h] [rbp+B0h]
  hkSimdFloat32 v167; // [rsp+1C0h] [rbp+C0h]
  hkSimdFloat32 v168; // [rsp+1D0h] [rbp+D0h]
  char buf; // [rsp+1E0h] [rbp+E0h]
  int v170; // [rsp+488h] [rbp+388h]
  bool v171; // [rsp+490h] [rbp+390h]
  hkBool v172; // [rsp+498h] [rbp+398h]

  v171 = containment;
  v170 = numVerticesToKeep;
  v4 = containment;
  v5 = numVerticesToKeep;
  v6 = this;
  if ( !useCgo )
  {
    v16 = this->m_dimensions == -1;
    *(_DWORD *)&array.m_internalInputs.m_bool = 2147483648;
    v14 = !v16;
    v17 = 0;
    v172.m_bool = !v16;
    *(_QWORD *)&array.m_allowLowerDimensions.m_bool = 0i64;
    *(_DWORD *)&array.m_setSourceIndices.m_bool = 0;
    if ( containment )
    {
      v18 = this->m_mesh.m_vertices.m_numUsed;
      if ( v18 > 0 )
      {
        v19 = this->m_mesh.m_vertices.m_numUsed;
        if ( v18 < 0 )
          v19 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v19, 16);
        v17 = *(_DWORD *)&array.m_setSourceIndices.m_bool;
      }
      v20 = v6->m_mesh.m_vertices.m_used;
      v21 = *(hkVector4f **)&array.m_allowLowerDimensions.m_bool;
      for ( *(_DWORD *)&array.m_setSourceIndices.m_bool = v18 + v17; v20; v20 = v20->m_next )
      {
        v22 = v21;
        ++v21;
        *v22 = v20->m_source;
      }
      v14 = v172.m_bool;
    }
    if ( v6->m_dimensions == 2 )
    {
      if ( v5 < 3 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&geometry, &buf, 512);
        v114 = hkOstream::operator<<((hkOstream *)&geometry, "The number of vertices requested(");
        v115 = hkOstream::operator<<(v114, v5, (int)v114);
        hkOstream::operator<<(v115, ") is less than 3.");
        hkError::messageWarning(
          -1034166809,
          &buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
          1700);
        hkOstream::~hkOstream((hkOstream *)&geometry);
        v5 = 3;
        v170 = 3;
      }
      if ( v6->m_mesh.m_vertices.m_numUsed <= v5 )
        goto LABEL_149;
      v116 = v6->m_hasIndexing;
      v117 = 0;
      v139 = v6->m_hasMassProperties;
      v118 = 0i64;
      v140 = 0i64;
      numPoints = 0;
      v142 = 2147483648;
      while ( 1 )
      {
        v119 = v6->m_mesh.m_vertices.m_used;
        v120 = *(float *)&xmmword_141A712A0;
        v121 = -1;
        v122 = &result;
        if ( !v119 )
          v122 = 0i64;
        if ( v122 )
        {
          do
          {
            if ( v117 == (v142 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v140, 8);
              v117 = numPoints;
              v118 = v140;
            }
            v118->m_quad.m128_u64[v117] = (unsigned __int64)v119;
            v117 = numPoints++ + 1;
            if ( v119 )
              v119 = v119->m_next;
            v118 = v140;
            v123 = &result;
            if ( !v119 )
              v123 = 0i64;
          }
          while ( v123 );
        }
        v124 = v117 - 1;
        v125 = 0;
        if ( v117 > 0 )
        {
          v126 = 0i64;
          v127 = 8i64 * v124;
          v128 = 8i64 * (v117 - 2);
          do
          {
            v129 = *(__m128 *)(*(unsigned __int64 *)((char *)v118->m_quad.m128_u64 + v128) + 16);
            v130 = _mm_sub_ps(*(__m128 *)(*(unsigned __int64 *)((char *)v118->m_quad.m128_u64 + v127) + 16), v129);
            v131 = _mm_sub_ps(*(__m128 *)(v118->m_quad.m128_u64[v126] + 16), v129);
            v132 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), v130),
                     _mm_mul_ps(_mm_shuffle_ps(v130, v130, 201), v131));
            v133 = _mm_shuffle_ps(v132, v132, 201);
            v134 = _mm_mul_ps(v133, v133);
            v135 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                     _mm_shuffle_ps(v134, v134, 170));
            v136 = _mm_rsqrt_ps(v135);
            LODWORD(v137) = (unsigned __int128)_mm_andnot_ps(
                                                 _mm_cmpleps(v135, (__m128)0i64),
                                                 _mm_mul_ps(
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v136, v135), v136)),
                                                     _mm_mul_ps(v136, *(__m128 *)_xmm)),
                                                   v135));
            if ( v137 < v120 )
            {
              v120 = v137;
              v121 = v124;
            }
            v124 = v125;
            v128 = v127;
            ++v125;
            v127 = v126 * 8;
            ++v126;
          }
          while ( v125 < v117 );
        }
        hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::release(
          &v6->m_mesh.m_vertices,
          (hkgpConvexHullImpl::Vertex *)v118->m_quad.m128_u64[v121]);
        v117 = 0;
        numPoints = 0;
        if ( v6->m_mesh.m_vertices.m_numUsed <= v170 )
          break;
        v118 = v140;
      }
      hkgpConvexHullImpl::refitDomainFromSources(v6);
      v14 = v172.m_bool;
      if ( v172.m_bool && v171 )
        hkgpConvexHullImpl::ensureContainment(v6, &v172, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
      if ( v116 )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
      if ( v139 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, (hkResult *)&v172);
      numPoints = 0;
      if ( v142 < 0 )
        goto LABEL_149;
      v113 = v140;
    }
    else
    {
      if ( v6->m_dimensions != 3 )
        goto LABEL_149;
      if ( v5 < 4 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&geometry, &buf, 512);
        v23 = hkOstream::operator<<((hkOstream *)&geometry, "The number of vertices requested(");
        v24 = hkOstream::operator<<(v23, v5, (int)v23);
        hkOstream::operator<<(v24, ") is less than 4.");
        hkError::messageWarning(
          -1034166810,
          &buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
          1622);
        hkOstream::~hkOstream((hkOstream *)&geometry);
        v5 = 4;
        v170 = 4;
      }
      v25 = v6->m_mesh.m_vertices.m_numUsed;
      if ( v25 <= v5 )
        goto LABEL_149;
      v26 = v6->m_hasIndexing;
      v149 = 0i64;
      i = 0;
      v143 = v26;
      v27 = v6->m_hasMassProperties;
      v151 = 2147483648;
      v138 = v27;
      if ( v25 <= 0 )
      {
        v154.m_enum = 0;
      }
      else
      {
        if ( v25 < 0 )
          v25 = 0;
        hkArrayUtil::_reserve(&v154, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v149, v25, 16);
      }
      v28 = v6->m_mesh.m_vertices.m_numUsed;
      pArr = 0i64;
      j = 0;
      v146 = 2147483648;
      if ( v28 <= 0 )
        v155.m_enum = 0;
      else
        hkArrayUtil::_reserve(&v155, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &pArr, v28, 24);
      v29 = v6->m_mesh.m_vertices.m_numUsed;
      if ( v29 <= v5 )
      {
LABEL_105:
        v14 = v172.m_bool;
        if ( v172.m_bool && v4 )
          hkgpConvexHullImpl::ensureContainment(v6, &v172, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
      }
      else
      {
        while ( 1 )
        {
          v30 = 0;
          v31 = v151 & 0x3FFFFFFF;
          i = 0;
          if ( (v151 & 0x3FFFFFFF) >= v29 )
          {
            v157.m_enum = 0;
          }
          else
          {
            v32 = v29;
            if ( v29 < 2 * v31 )
              v32 = 2 * v31;
            hkArrayUtil::_reserve(&v157, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v149, v32, 16);
            v30 = i;
          }
          v33 = v6->m_mesh.m_vertices.m_used;
          v34 = v149;
          for ( i = v29 + v30; v33; v33 = v33->m_next )
          {
            v35 = v34;
            ++v34;
            *v35 = v33->m_source;
          }
          v36 = v6->m_mesh.m_vertices.m_used;
          for ( j = 0; v36; v36 = v36->m_next )
            v36->m_scratch = 0.0;
          v37 = v6->m_mesh.m_triangles.m_used;
          if ( v37 )
          {
            do
            {
              v38 = 0;
              do
              {
                *(_DWORD *)&geometry.m_memSizeAndFlags = v38;
                if ( 0.0 == v37->m_vertices[v38]->m_scratch )
                {
                  v160.m128i_i64[0] = (__int64)v37;
                  v160.m128i_i32[2] = v38;
                  _mm_store_si128((__m128i *)&v153, v160);
                  v39 = 0.0;
                  while ( 1 )
                  {
                    v40 = v153;
                    v41 = v6->m_scaleInv.m_quad;
                    v42 = v6->m_origin.m_quad;
                    v43 = 2 * BYTE8(v153);
                    v44 = *(unsigned int **)(v153 + 8 * ((9i64 >> 2 * BYTE8(v153)) & 3) + 16);
                    v45 = *(unsigned int **)(v153 + 8i64 * SDWORD2(v153) + 16);
                    v46 = _mm_slli_si128(
                            (__m128i)_mm_cvtepi32_ps(
                                       _mm_unpacklo_epi32(
                                         _mm_unpacklo_epi32(_mm_cvtsi32_si128(v44[8]), _mm_cvtsi32_si128(v44[10])),
                                         _mm_unpacklo_epi32(_mm_cvtsi32_si128(v44[9]), _mm_cvtsi32_si128(0)))),
                            4);
                    v47 = *(unsigned int **)(v153 + 8 * ((18i64 >> 2 * BYTE8(v153)) & 3) + 16);
                    v48 = _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_si128(v46, 4), v41), v42);
                    v49 = _mm_unpacklo_epi32(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v47[8]), _mm_cvtsi32_si128(v47[10])),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v47[9]), _mm_cvtsi32_si128(0)));
                    v50 = *(unsigned int **)((*(_QWORD *)(v153 + 8i64 * SDWORD2(v153) + 40) & 0xFFFFFFFFFFFFFFFCui64)
                                           + 8
                                           * ((18i64 >> 2
                                                      * ((unsigned __int8)*(_QWORD *)(v153 + 8i64 * SDWORD2(v153) + 40) & 3u)) & 3)
                                           + 16);
                    v51 = _mm_unpacklo_epi32(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v50[8]), _mm_cvtsi32_si128(v50[10])),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v50[9]), _mm_cvtsi32_si128(0)));
                    *(__m128 *)&config.m_semantic = _mm_sub_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          (__m128)_mm_srli_si128(
                                                                    _mm_slli_si128(
                                                                      (__m128i)_mm_cvtepi32_ps(
                                                                                 _mm_unpacklo_epi32(
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_cvtsi32_si128(v45[8]),
                                                                                     _mm_cvtsi32_si128(v45[10])),
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_cvtsi32_si128(v45[9]),
                                                                                     _mm_cvtsi32_si128(0)))),
                                                                      4),
                                                                    4),
                                                          v41),
                                                        v42),
                                                      v48);
                    *(__m128 *)&config.m_maxAngle = _mm_sub_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          (__m128)_mm_srli_si128(
                                                                    _mm_slli_si128((__m128i)_mm_cvtepi32_ps(v49), 4),
                                                                    4),
                                                          v41),
                                                        v42),
                                                      v48);
                    *(__m128 *)&config.m_updateThreshold = _mm_sub_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(
                                                                 (__m128)_mm_srli_si128(
                                                                           _mm_slli_si128(
                                                                             (__m128i)_mm_cvtepi32_ps(v51),
                                                                             4),
                                                                           4),
                                                                 v41),
                                                               v42),
                                                             v48);
                    hkMatrix3f::getDeterminant((hkMatrix3f *)&config, &v167);
                    v39 = v39 + v167.m_real.m128_f32[0];
                    v52 = *(_QWORD *)(v40 + 8i64 * ((18 >> v43) & 3) + 40) & 3i64;
                    v53 = *(_QWORD *)(v40 + 8i64 * ((18 >> v43) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    v162.m128i_i64[0] = *(_QWORD *)(v40 + 8i64 * ((18 >> v43) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    v162.m128i_i32[2] = v52;
                    _mm_store_si128((__m128i *)&v153, v162);
                    if ( !v53 )
                      break;
                    if ( (hkgpConvexHullImpl::Triangle *)(v53 + v52) == (hkgpConvexHullImpl::Triangle *)((char *)v37 + (unsigned int)v38) )
                      goto LABEL_53;
                  }
                  v54 = v37->m_links[v38];
                  v166.m128i_i64[0] = v37->m_links[v38] & 0xFFFFFFFFFFFFFFFCui64;
                  v55 = v166.m128i_i64[0];
                  v166.m128i_i32[2] = (9 >> 2 * (v54 & 3)) & 3;
                  _mm_store_si128((__m128i *)&v153, v166);
                  if ( v55 )
                  {
                    do
                    {
                      v56 = v153;
                      v57 = v6->m_scaleInv.m_quad;
                      v58 = v6->m_origin.m_quad;
                      v59 = SDWORD2(v153);
                      v60 = *(unsigned int **)(v153 + 8 * ((9i64 >> 2 * BYTE8(v153)) & 3) + 16);
                      v61 = *(unsigned int **)(v153 + 8i64 * SDWORD2(v153) + 16);
                      v62 = _mm_slli_si128(
                              (__m128i)_mm_cvtepi32_ps(
                                         _mm_unpacklo_epi32(
                                           _mm_unpacklo_epi32(_mm_cvtsi32_si128(v60[8]), _mm_cvtsi32_si128(v60[10])),
                                           _mm_unpacklo_epi32(_mm_cvtsi32_si128(v60[9]), _mm_cvtsi32_si128(0)))),
                              4);
                      v63 = *(unsigned int **)(v153 + 8 * ((18i64 >> 2 * BYTE8(v153)) & 3) + 16);
                      v64 = _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_si128(v62, 4), v57), v58);
                      v65 = _mm_unpacklo_epi32(
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v63[8]), _mm_cvtsi32_si128(v63[10])),
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v63[9]), _mm_cvtsi32_si128(0)));
                      v66 = *(unsigned int **)((*(_QWORD *)(v153 + 8i64 * SDWORD2(v153) + 40) & 0xFFFFFFFFFFFFFFFCui64)
                                             + 8
                                             * ((18i64 >> 2
                                                        * ((unsigned __int8)*(_QWORD *)(v153 + 8i64 * SDWORD2(v153) + 40) & 3u)) & 3)
                                             + 16);
                      v67 = _mm_unpacklo_epi32(
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v66[8]), _mm_cvtsi32_si128(v66[10])),
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v66[9]), _mm_cvtsi32_si128(0)));
                      *(__m128 *)&config.m_semantic = _mm_sub_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(
                                                            (__m128)_mm_srli_si128(
                                                                      _mm_slli_si128(
                                                                        (__m128i)_mm_cvtepi32_ps(
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_unpacklo_epi32(
                                                                                       _mm_cvtsi32_si128(v61[8]),
                                                                                       _mm_cvtsi32_si128(v61[10])),
                                                                                     _mm_unpacklo_epi32(
                                                                                       _mm_cvtsi32_si128(v61[9]),
                                                                                       _mm_cvtsi32_si128(0)))),
                                                                        4),
                                                                      4),
                                                            v57),
                                                          v58),
                                                        v64);
                      *(__m128 *)&config.m_maxAngle = _mm_sub_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(
                                                            (__m128)_mm_srli_si128(
                                                                      _mm_slli_si128((__m128i)_mm_cvtepi32_ps(v65), 4),
                                                                      4),
                                                            v57),
                                                          v58),
                                                        v64);
                      *(__m128 *)&config.m_updateThreshold = _mm_sub_ps(
                                                               _mm_add_ps(
                                                                 _mm_mul_ps(
                                                                   (__m128)_mm_srli_si128(
                                                                             _mm_slli_si128(
                                                                               (__m128i)_mm_cvtepi32_ps(v67),
                                                                               4),
                                                                             4),
                                                                   v57),
                                                                 v58),
                                                               v64);
                      hkMatrix3f::getDeterminant((hkMatrix3f *)&config, &v168);
                      v68 = *(_QWORD *)(v56 + 8 * v59 + 40);
                      v39 = v39 + v168.m_real.m128_f32[0];
                      v165.m128i_i64[0] = *(_QWORD *)(v56 + 8 * v59 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                      v69 = v165.m128i_i64[0];
                      v165.m128i_i32[2] = (9 >> 2 * (v68 & 3)) & 3;
                      _mm_store_si128((__m128i *)&v153, v165);
                    }
                    while ( v69 );
                  }
LABEL_53:
                  v70 = j;
                  if ( j == (v146 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &pArr, 24);
                    v70 = j;
                  }
                  v71 = pArr;
                  v72 = v70;
                  v73 = *(_QWORD *)&geometry.m_memSizeAndFlags;
                  j = v70 + 1;
                  pArr[v72].m_data.m_triangle = v37;
                  *(_QWORD *)&v71[v72].m_data.m_index = v73;
                  v71[v72].m_value = v39;
                  v37->m_vertices[v38]->m_scratch = 1.0;
                }
                ++v38;
              }
              while ( v38 < 3 );
              v37 = v37->m_next;
            }
            while ( v37 );
            v5 = v170;
          }
          for ( k = v6->m_mesh.m_vertices.m_used; k; k = k->m_next )
            k->m_scratch = 0.0;
          if ( j > 1 )
            hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::SortedEdge,hkAlgorithm::less<hkgpConvexHullImpl::SortedEdge>>(
              pArr,
              0,
              j - 1,
              0);
          v75 = 0;
          v76 = 0i64;
          v77 = v6->m_mesh.m_vertices.m_numUsed - v5;
          v78 = v77;
          if ( v77 > 0 )
          {
            v79 = 0i64;
            do
            {
              v80 = 0;
              v81 = pArr[v79].m_data.m_triangle->m_vertices[pArr[v79].m_data.m_index];
              v81->m_scratch = v81->m_scratch + 1.0;
              v82 = pArr[v79].m_data.m_triangle;
              v83 = (signed int)pArr[v79].m_data.m_index;
              v164.m128i_i64[0] = (__int64)pArr[v79].m_data.m_triangle;
              v164.m128i_i32[2] = v83;
              _mm_store_si128((__m128i *)&points, v164);
              while ( 1 )
              {
                v84 = points.m_vertices;
                v85 = 2 * LOBYTE(points.m_numVertices);
                v86 = *(_QWORD *)&points.m_vertices[2 * ((9i64 >> 2 * LOBYTE(points.m_numVertices)) & 3) + 4];
                v87 = *(float *)(v86 + 44) + 1.0;
                *(float *)(v86 + 44) = v87;
                if ( v87 > 1.0 )
                  v80 = 1;
                v88 = *(_QWORD *)&v84[2 * ((18 >> v85) & 3) + 10] & 3i64;
                v89 = *(_QWORD *)&v84[2 * ((18 >> v85) & 3) + 10] & 0xFFFFFFFFFFFFFFFCui64;
                v163.m128i_i64[0] = *(_QWORD *)&v84[2 * ((18 >> v85) & 3) + 10] & 0xFFFFFFFFFFFFFFFCui64;
                v163.m128i_i32[2] = v88;
                _mm_store_si128((__m128i *)&points, v163);
                if ( !v89 )
                  break;
                if ( (hkgpConvexHullImpl::Triangle *)(v89 + v88) == (hkgpConvexHullImpl::Triangle *)((char *)v82 + (unsigned int)v83) )
                  goto LABEL_75;
              }
              v90 = v82->m_links[v83];
              v161.m128i_i64[0] = v82->m_links[v83] & 0xFFFFFFFFFFFFFFFCui64;
              v91 = v161.m128i_i64[0];
              v161.m128i_i32[2] = (9 >> 2 * (v90 & 3)) & 3;
              _mm_store_si128((__m128i *)&points, v161);
              if ( v91 )
              {
                do
                {
                  v92 = points.m_vertices;
                  v93 = points.m_numVertices;
                  v94 = *(_QWORD *)&points.m_vertices[2 * ((9i64 >> 2 * LOBYTE(points.m_numVertices)) & 3) + 4];
                  v95 = *(float *)(v94 + 44) + 1.0;
                  *(float *)(v94 + 44) = v95;
                  v96 = *(_QWORD *)&v92[2 * v93 + 10];
                  if ( v95 > 1.0 )
                    v80 = 1;
                  plane.m_quad.m128_u64[0] = v96 & 0xFFFFFFFFFFFFFFFCui64;
                  plane.m_quad.m128_i32[2] = (9 >> 2 * (v96 & 3)) & 3;
                  _mm_store_si128((__m128i *)&points, (__m128i)plane.m_quad);
                }
                while ( v96 & 0xFFFFFFFFFFFFFFFCui64 );
              }
LABEL_75:
              if ( v80 )
                break;
              ++v76;
              ++v75;
              ++v79;
            }
            while ( v76 < v78 );
          }
          v97 = v75;
          if ( v75 > 0 )
          {
            v98 = 0i64;
            do
            {
              v99 = pArr[v98].m_data.m_triangle->m_vertices[pArr[v98].m_data.m_index];
              v100 = v99->m_next;
              v101 = v99->m_prev;
              if ( v99->m_next )
                v100->m_prev = v101;
              if ( v101 )
                v101->m_next = v100;
              else
                v6->m_mesh.m_vertices.m_used = v100;
              --v6->m_mesh.m_vertices.m_numUsed;
              v102 = v99[1].m_next;
              v16 = v102[40].m_source.m_quad.m128_i32[2]-- == 1;
              if ( v16 )
              {
                v103 = v102[40].m_prev;
                v104 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *)v102[40].m_source.m_quad.m128_u64[0];
                if ( v103 )
                  v103[40].m_source.m_quad.m128_u64[0] = (unsigned __int64)v104;
                else
                  v6->m_mesh.m_vertices.m_allocator.m_firstPool = v104;
                v105 = v102[40].m_source.m_quad.m128_u64[0];
                if ( v105 )
                  *(_QWORD *)(v105 + 2568) = v102[40].m_prev;
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v102,
                  2592);
              }
              ++v98;
              --v97;
            }
            while ( v97 );
          }
          v106 = v6->m_mesh.m_vertices.m_numUsed;
          v107 = 0i64;
          v108 = 0;
          numPoints = 0;
          v142 = 2147483648;
          v140 = 0i64;
          if ( v106 <= 0 )
          {
            result.m_enum = 0;
          }
          else
          {
            v109 = v106;
            if ( v106 < 0 )
              v109 = 0;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v140,
              v109,
              16);
            v108 = numPoints;
            v107 = v140;
          }
          v110 = v6->m_mesh.m_vertices.m_used;
          v111 = v106 + v108;
          numPoints = v111;
          if ( v110 )
          {
            do
            {
              v112 = v107;
              ++v107;
              *v112 = v110->m_source;
              v110 = v110->m_next;
            }
            while ( v110 );
            v111 = numPoints;
            v107 = v140;
          }
          if ( hkgpConvexHullImpl::build(v6, v107, v111, 0, 0i64) == -1 )
            break;
          numPoints = 0;
          if ( v142 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v140,
              16 * v142);
          v29 = v6->m_mesh.m_vertices.m_numUsed;
          v5 = v170;
          v140 = 0i64;
          v142 = 2147483648;
          if ( v29 <= v170 )
          {
            v4 = v171;
            goto LABEL_105;
          }
        }
        hkgpConvexHullImpl::build(v6, v149, i, 0, 0i64);
        v14 = 0;
        numPoints = 0;
        if ( v142 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v140,
            16 * v142);
      }
      if ( v143 )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
      if ( v138 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, (hkResult *)&v172);
      j = 0;
      if ( v146 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          pArr,
          24 * (v146 & 0x3FFFFFFF));
      pArr = 0i64;
      v146 = 2147483648;
      i = 0;
      if ( v151 < 0 )
        goto LABEL_149;
      v113 = v149;
    }
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkVector4f *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v113);
LABEL_149:
    *(_DWORD *)&array.m_setSourceIndices.m_bool = 0;
    if ( *(_DWORD *)&array.m_internalInputs.m_bool >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)&array.m_allowLowerDimensions.m_bool,
        16 * *(_DWORD *)&array.m_internalInputs.m_bool);
    return v14;
  }
  v7 = this->m_hull;
  v8 = this->m_hasIndexing;
  v9 = this->m_hasMassProperties;
  v10 = hkgpConvexHull::getDimensions(this->m_hull);
  if ( (signed int)hkgpConvexHull::getNumVertices(v7) <= v5 )
    return 1;
  if ( v10 < 2 )
    return 0;
  geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
  geometry.m_vertices.m_data = 0i64;
  geometry.m_vertices.m_size = 0;
  geometry.m_vertices.m_capacityAndFlags = 2147483648;
  geometry.m_triangles.m_data = 0i64;
  geometry.m_triangles.m_size = 0;
  geometry.m_triangles.m_capacityAndFlags = 2147483648;
  hkgpConvexHull::generateGeometry(v7, 0, &geometry, 0, 0);
  *(_QWORD *)&config.m_semantic = 0i64;
  config.m_updateThreshold = 0.0;
  *(_OWORD *)&config.m_maxAngle = _xmm;
  config.m_minConvergence = FLOAT_0_0000099999997;
  *(_DWORD *)&config.m_inverseOrientation.m_bool = 0x1000000;
  *(_WORD *)&config.m_protectNakedBoundaries.m_bool = 0;
  config.m_decimateComponents.m_bool = 0;
  config.m_minDistance = FLOAT_N0_000099999997;
  config.m_maxDistance = FLOAT_3_40282e38;
  config.m_tracker = 0i64;
  *(_DWORD *)&config.m_project.m_bool = 257;
  config.m_maxVertices = v5;
  if ( v171 )
    config.m_maxShrink = 0.0;
  else
    LODWORD(config.m_maxShrink) = (_DWORD)FLOAT_1_0;
  config.m_solverAccuracy = 64;
  hkgpCgo::optimize(&config, &geometry, 0i64, 0i64);
  v11 = v6->m_hull;
  v12 = hkgpConvexHull::getConfiguration(v6->m_hull);
  *(_DWORD *)&array.m_allowLowerDimensions.m_bool = *(_DWORD *)&v12->m_config.m_allowLowerDimensions.m_bool;
  array.m_minCosAngle = v12->m_config.m_minCosAngle;
  v13 = *(_DWORD *)&v12->m_config.m_setSourceIndices.m_bool;
  LODWORD(v12) = *(_DWORD *)&v12->m_config.m_internalInputs.m_bool;
  *(_DWORD *)&array.m_setSourceIndices.m_bool = v13;
  array.m_buildIndices.m_bool = v8 != 0;
  array.m_buildMassProperties.m_bool = v9 != 0;
  *(_DWORD *)&array.m_internalInputs.m_bool = (_DWORD)v12;
  if ( v10 >= 3 )
  {
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    points.m_striding = 16;
    points.m_numVertices = geometry.m_vertices.m_size;
    v14 = hkgpConvexHull::build(v11, &points, &array) != -1;
  }
  else
  {
    points.m_striding = 16;
    _mm_store_si128((__m128i *)&plane, (__m128i)hkgpConvexHull::getProjectionPlane(v11)->m_quad);
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    points.m_numVertices = geometry.m_vertices.m_size;
    v14 = hkgpConvexHull::buildPlanar(v11, &points, &plane, &array) != -1;
  }
  hkGeometry::~hkGeometry(&geometry);
  return v14;
}

// File Line: 1750
// RVA: 0xCB6CB0
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::getEdgeLengths(hkgpConvexHullImpl *this, hkSimdFloat32 *result)
{
  int v2; // er8
  hkSimdFloat32 *v3; // r14
  hkgpConvexHullImpl *v4; // rbx
  int v5; // er8
  int v6; // er8
  hkgpConvexHullImpl::Triangle *v7; // rbx
  signed int v8; // er11
  __m128 **v9; // r10
  signed int v10; // ecx
  __m128 *v11; // rdi
  __m128 *v12; // rax
  int v13; // edx
  int v14; // ecx
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  hkSimdFloat32 *v19; // rax
  int v20; // edi
  signed int v21; // er9
  hkVector4f *v22; // rdx
  int v23; // er8
  int v24; // er9
  hkgpConvexHullImpl::Vertex *v25; // rcx
  int v26; // er8
  hkVector4f *v27; // rax
  signed __int64 v28; // rcx
  signed __int64 v29; // rax
  __int64 v30; // r10
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  hkgpConvexHullImpl::Vertex *v36; // rax
  __m128 *v37; // rcx
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  hkVector4f *array; // [rsp+30h] [rbp-48h]
  int v44; // [rsp+38h] [rbp-40h]
  int v45; // [rsp+3Ch] [rbp-3Ch]
  hkResult resulta; // [rsp+80h] [rbp+8h]

  v2 = this->m_dimensions;
  v3 = result;
  v4 = this;
  *result = 0i64;
  v5 = v2 - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 && (v7 = this->m_mesh.m_triangles.m_used) != 0i64 )
      {
        do
        {
          v8 = 0;
          v9 = (__m128 **)v7->m_vertices;
          do
          {
            v10 = 0;
            v11 = (__m128 *)v7->m_vertices[(9i64 >> 2 * (unsigned __int8)v8) & 3];
            v12 = v11 + 2;
            do
            {
              v13 = *(_DWORD *)((char *)v12->m128_u64 + (char *)*v9 - (char *)v11);
              if ( v13 < SLODWORD(v12->m128_u64[0]) )
                break;
              if ( v13 > SLODWORD(v12->m128_u64[0]) )
              {
                if ( (unsigned __int64)v9[3] & 0xFFFFFFFFFFFFFFFCui64 )
                  goto LABEL_15;
                break;
              }
              ++v10;
              v12 = (__m128 *)((char *)v12 + 4);
            }
            while ( v10 < 3 );
            v14 = v7->m_plane.m_index;
            if ( v14 == -1 || v14 != *(_DWORD *)(((unsigned __int64)v9[3] & 0xFFFFFFFFFFFFFFFCui64) + 88) )
            {
              v15 = _mm_sub_ps((*v9)[1], v11[1]);
              v16 = _mm_mul_ps(v15, v15);
              v17 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                      _mm_shuffle_ps(v16, v16, 170));
              v18 = _mm_rsqrt_ps(v17);
              v3->m_real = _mm_add_ps(
                             _mm_andnot_ps(
                               _mm_cmpleps(v17, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v18), v18)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                 v17)),
                             v3->m_real);
            }
LABEL_15:
            ++v8;
            ++v9;
          }
          while ( v8 < 3 );
          v7 = v7->m_next;
        }
        while ( v7 );
        v19 = v3;
      }
      else
      {
        v19 = result;
      }
    }
    else
    {
      v20 = this->m_mesh.m_vertices.m_numUsed;
      v21 = 2147483648;
      v22 = 0i64;
      v23 = 0;
      v44 = 0;
      v45 = 2147483648;
      array = 0i64;
      if ( v20 > 0 )
      {
        v24 = v20;
        if ( v20 < 0 )
          v24 = 0;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v24, 16);
        v21 = v45;
        v23 = v44;
        v22 = array;
      }
      v25 = v4->m_mesh.m_vertices.m_used;
      v26 = v20 + v23;
      v44 = v26;
      if ( v25 )
      {
        do
        {
          v27 = v22;
          ++v22;
          *v27 = v25->m_source;
          v25 = v25->m_next;
        }
        while ( v25 );
        v21 = v45;
        v26 = v44;
        v22 = array;
      }
      if ( v26 > 0 )
      {
        v28 = 16i64 * (v26 - 1);
        v29 = 0i64;
        v30 = (unsigned int)v26;
        do
        {
          v31 = *(__m128 *)((char *)&v22->m_quad + v28);
          v28 = v29 * 16;
          ++v29;
          v32 = _mm_sub_ps(v31, v22[v29 - 1].m_quad);
          v33 = _mm_mul_ps(v32, v32);
          v34 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                  _mm_shuffle_ps(v33, v33, 170));
          v35 = _mm_rsqrt_ps(v34);
          v3->m_real = _mm_add_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v34, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                               _mm_mul_ps(*(__m128 *)_xmm, v35)),
                             v34)),
                         v3->m_real);
          --v30;
        }
        while ( v30 );
      }
      v44 = 0;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v22,
          16 * v21);
      v19 = v3;
    }
  }
  else
  {
    v36 = this->m_mesh.m_vertices.m_used;
    v37 = (__m128 *)v36->m_next;
    v38 = v36->m_source.m_quad;
    v19 = result;
    v39 = _mm_sub_ps(v38, v37[1]);
    v40 = _mm_mul_ps(v39, v39);
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170));
    v42 = _mm_rsqrt_ps(v41);
    result->m_real = _mm_andnot_ps(
                       _mm_cmpleps(v41, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                           _mm_mul_ps(*(__m128 *)_xmm, v42)),
                         v41));
  }
  return v19;
}

// File Line: 1830
// RVA: 0xCB3180
hkVector4f *__fastcall hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(hkgpConvexHullImpl *this)
{
  hkVector4f *result; // rax
  __m128 v2; // xmm4
  hkgpConvexHullImpl::Vertex *i; // rdx
  int v4; // edx

  result = &this->m_centroids[1];
  if ( COERCE_FLOAT(_mm_shuffle_ps(this->m_centroids[1].m_quad, this->m_centroids[1].m_quad, 255)) == 3.40282e38 )
  {
    v2 = 0i64;
    *result = 0i64;
    for ( i = this->m_mesh.m_vertices.m_used; i; i = i->m_next )
      result->m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             (__m128)_mm_srli_si128(
                                       _mm_slli_si128(
                                         (__m128i)_mm_cvtepi32_ps(
                                                    _mm_unpacklo_epi32(
                                                      _mm_unpacklo_epi32(
                                                        _mm_cvtsi32_si128(i->m_x[0]),
                                                        _mm_cvtsi32_si128(i->m_x[2])),
                                                      _mm_unpacklo_epi32(
                                                        _mm_cvtsi32_si128(i->m_x[1]),
                                                        _mm_cvtsi32_si128(0)))),
                                         4),
                                       4),
                             this->m_scaleInv.m_quad),
                           this->m_origin.m_quad),
                         result->m_quad);
    v4 = this->m_mesh.m_vertices.m_numUsed;
    if ( v4 )
    {
      v2.m128_f32[0] = (float)v4;
      result->m_quad = _mm_mul_ps(result->m_quad, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v2, v2, 0)));
    }
    *(__m128i *)result = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)result), 4), 4);
  }
  return result;
}

// File Line: 1856
// RVA: 0xCB11E0
hkResult *__fastcall hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(hkgpConvexHullImpl *this, hkResult *result)
{
  hkResultEnum v2; // edi
  hkResult *v3; // r14
  hkgpConvexHullImpl *v4; // rbx
  int v5; // eax
  hkVector4f *v6; // rax
  hkgpConvexHullImpl::Triangle *v7; // rcx
  hkgpConvexHullImpl::Triangle *v8; // rdx
  __m128 v9; // xmm12
  __m128 v10; // xmm4
  __m128 v11; // xmm7
  __m128 v12; // xmm15
  __m128i v13; // xmm14
  __m128 v14; // xmm13
  __m128 v15; // xmm8
  __m128 v16; // xmm9
  __m128 v17; // xmm10
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm9
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm8
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm10
  __m128 v33; // xmm7
  __m128 v34; // xmm8
  __m128 v35; // xmm7
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm6
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm8
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm14
  __m128 v46; // xmm2
  __m128 v47; // xmm4
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm6
  __m128 v51; // xmm13
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  __m128 v56; // xmm15
  __m128 v57; // xmm12
  __m128 v58; // xmm8
  __m128 v59; // xmm9
  __m128 v60; // xmm10
  __m128 v61; // xmm7
  __m128 v62; // xmm6
  __m128 v63; // xmm4
  __m128 v64; // xmm5
  __m128 v65; // xmm5
  __m128 v66; // xmm1
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm4
  __m128 v70; // xmm6
  __m128 v71; // xmm2
  __m128 v72; // xmm6
  __m128 v73; // xmm1
  __int64 v74; // rcx
  __m128 *v75; // rax
  __m128 v76; // xmm3
  __m128 v77; // xmm1
  __m128 v78; // xmm4
  __m128 v79; // xmm6
  __m128 v80; // xmm14
  __m128 v81; // xmm3
  __m128 v82; // xmm13
  hkOstream *v83; // rax
  hkOstream *v84; // rax
  __m128 v85; // xmm1
  __m128 v86; // xmm0
  __m128 v87; // xmm0
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  hkVector4f v90; // xmm1
  hkVector4f v91; // xmm0
  int v92; // esi
  __m128 v93; // xmm6
  __m128 *v94; // rdx
  float v95; // eax
  signed int v96; // er8
  __m128 v97; // xmm7
  int v98; // er9
  hkgpConvexHullImpl::Vertex *v99; // rcx
  int v100; // eax
  __m128 *v101; // rax
  signed __int64 v102; // rcx
  __m128 v103; // xmm5
  __m128 *v104; // rax
  signed __int64 v105; // rcx
  __m128 v106; // xmm4
  __m128 v107; // xmm3
  __m128 v108; // xmm3
  __m128 v109; // xmm4
  __m128 v110; // xmm1
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  hkVector4f v113; // xmm1
  __m128 v114; // xmm1
  hkResult *v115; // rax
  __m128 array; // [rsp+30h] [rbp-B8h]
  hkVector4f eigenVal; // [rsp+40h] [rbp-A8h]
  hkSimdFloat32 scale; // [rsp+50h] [rbp-98h]
  __m128 v119; // [rsp+68h] [rbp-80h]
  __m128 v120; // [rsp+78h] [rbp-70h]
  __m128 v121; // [rsp+88h] [rbp-60h]
  __m128 v122; // [rsp+98h] [rbp-50h]
  hkRotationf eigenVec; // [rsp+A8h] [rbp-40h]
  hkMatrix3f aTb; // [rsp+D8h] [rbp-10h]
  hkMatrix3f a; // [rsp+108h] [rbp+20h]
  hkMatrix3f v126; // [rsp+138h] [rbp+50h]
  hkMatrix3f bTc; // [rsp+168h] [rbp+80h]
  char buf; // [rsp+198h] [rbp+B0h]
  hkResult resulta; // [rsp+458h] [rbp+370h]

  v2 = 0;
  v3 = result;
  v4 = this;
  if ( !this->m_hasMassProperties )
  {
    v5 = this->m_dimensions;
    this->m_degeneratedMassProperties = 0;
    if ( v5 == 3 )
    {
      v6 = hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(this);
      v7 = v4->m_mesh.m_triangles.m_used;
      v8 = v7;
      v9 = v6->m_quad;
      v10 = 0i64;
      v11 = 0i64;
      array = 0i64;
      v121 = 0i64;
      v12 = 0i64;
      v122 = 0i64;
      v13 = 0i64;
      v14 = 0i64;
      if ( v7 )
      {
        v15 = v4->m_scaleInv.m_quad;
        v16 = v4->m_origin.m_quad;
        eigenVal.m_quad = (__m128)v4->m_scaleInv;
        scale.m_real = v16;
        do
        {
          v17 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[0]->m_x[0]),
                                                 _mm_cvtsi32_si128(v8->m_vertices[0]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[0]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  v9);
          v18 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[1]->m_x[0]),
                                                 _mm_cvtsi32_si128(v8->m_vertices[1]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[1]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  v9);
          v19 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[2]->m_x[0]),
                                                 _mm_cvtsi32_si128(v8->m_vertices[2]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v8->m_vertices[2]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  v9);
          v20 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19));
          v21 = _mm_shuffle_ps(v20, v20, 201);
          v22 = _mm_mul_ps(v17, v21);
          v23 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                  _mm_shuffle_ps(v22, v22, 170));
          v24 = _mm_sub_ps(v18, v19);
          array = _mm_add_ps(v10, v23);
          v12 = _mm_add_ps(v12, _mm_mul_ps(_mm_add_ps(_mm_add_ps(v18, v17), v19), v23));
          v122 = v12;
          v25 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v17),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v24));
          v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), v21);
          v27 = _mm_mul_ps(v26, v26);
          v28 = _mm_shuffle_ps(v17, v18, 68);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_shuffle_ps(v19, v19, 68);
          v32 = _mm_shuffle_ps(_mm_shuffle_ps(v17, v18, 238), _mm_shuffle_ps(v19, v19, 238), 136);
          v121 = _mm_add_ps(
                   v11,
                   _mm_andnot_ps(
                     _mm_cmpleps(v29, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                         _mm_mul_ps(v30, *(__m128 *)_xmm)),
                       v29)));
          v33 = v28;
          v34 = _mm_shuffle_ps(v28, v31, 221);
          v35 = _mm_shuffle_ps(v33, v31, 136);
          v36 = _mm_mul_ps(v32, v34);
          v37 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 201), v35), v35);
          *(float *)v13.m128i_i32 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85))
                                                          + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                                                  + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170)))
                                          * v23.m128_f32[0])
                                  + COERCE_FLOAT(_mm_shuffle_ps((__m128)v13, (__m128)v13, 0));
          v38 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170));
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170));
          v14.m128_f32[0] = (float)((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85))
                                                          + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                                                  + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170)))
                                          + (float)(v39.m128_f32[0] * v38.m128_f32[0]))
                                  * v23.m128_f32[0])
                          + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0));
          v8 = v8->m_next;
          v40 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 201), v34), v34);
          v41 = _mm_mul_ps(v34, v35);
          v42 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                  _mm_shuffle_ps(v40, v40, 170));
          v43 = _mm_shuffle_ps(v35, v35, 170);
          v44 = _mm_shuffle_ps(v35, v35, 0);
          v45 = _mm_shuffle_ps(
                  _mm_unpacklo_ps(
                    (__m128)v13,
                    _mm_add_ps(_mm_mul_ps(v42, v23), _mm_shuffle_ps((__m128)v13, (__m128)v13, 85))),
                  (__m128)v13,
                  228);
          v46 = _mm_mul_ps(v32, v35);
          v47 = _mm_shuffle_ps(v35, v35, 85);
          v11 = v121;
          v48 = _mm_add_ps(_mm_add_ps(v47, v44), v43);
          v49 = _mm_mul_ps(v39, v48);
          v50 = _mm_mul_ps(v38, v48);
          v10 = array;
          v51 = _mm_shuffle_ps(
                  _mm_unpacklo_ps(
                    v14,
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                            _mm_shuffle_ps(v46, v46, 170)),
                          v49),
                        v23),
                      _mm_shuffle_ps(v14, v14, 85))),
                  v14,
                  228);
          v52 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), v32), v32);
          v13 = (__m128i)_mm_shuffle_ps(
                           v45,
                           _mm_unpackhi_ps(
                             v45,
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                                   _mm_shuffle_ps(v52, v52, 170)),
                                 v23),
                               _mm_shuffle_ps(v45, v45, 170))),
                           180);
          v53 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                  _mm_shuffle_ps(v41, v41, 170));
          v15 = eigenVal.m_quad;
          v54 = _mm_mul_ps(_mm_add_ps(v53, v50), v23);
          v16 = scale.m_real;
          v14 = _mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, _mm_add_ps(v54, _mm_shuffle_ps(v51, v51, 170))), 180);
        }
        while ( v8 );
      }
      v55 = _mm_div_ps(query.m_quad, v10);
      eigenVal.m_quad = v55;
      v56 = _mm_mul_ps(v12, _mm_mul_ps(v55, (__m128)xmmword_141A711D0));
      v57 = _mm_add_ps(v9, v56);
      v122 = v56;
      v4->m_localTransform.m_translation.m_quad = v57;
      if ( v4->m_config.m_checkForDegeneratedMassProperties.m_bool )
      {
        v58 = 0i64;
        if ( v7 )
        {
          v59 = v4->m_scaleInv.m_quad;
          v60 = v4->m_origin.m_quad;
          do
          {
            v61 = _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v7->m_vertices[0]->m_x[0]),
                                                 _mm_cvtsi32_si128(v7->m_vertices[0]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v7->m_vertices[0]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v59),
                    v60);
            v62 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v7->m_vertices[2]->m_x[0]),
                                                   _mm_cvtsi32_si128(v7->m_vertices[2]->m_x[2])),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v7->m_vertices[2]->m_x[1]),
                                                   _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v59),
                      v60),
                    v61);
            v63 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v7->m_vertices[1]->m_x[0]),
                                                   _mm_cvtsi32_si128(v7->m_vertices[1]->m_x[2])),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v7->m_vertices[1]->m_x[1]),
                                                   _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v59),
                      v60),
                    v61);
            v64 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v63),
                    _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v62));
            v65 = _mm_shuffle_ps(v64, v64, 201);
            v66 = _mm_mul_ps(v65, v65);
            v67 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                    _mm_shuffle_ps(v66, v66, 170));
            v68 = _mm_rsqrt_ps(v67);
            v69 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v67), (__m128)0i64);
            v70 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v67, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                            _mm_mul_ps(v68, *(__m128 *)_xmm))),
                        v65),
                      v69),
                    _mm_andnot_ps(v69, v65));
            v71 = _mm_mul_ps(v70, v61);
            v7 = v7->m_next;
            v72 = _mm_shuffle_ps(
                    v70,
                    _mm_unpackhi_ps(
                      v70,
                      _mm_sub_ps(
                        (__m128)0i64,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                          _mm_shuffle_ps(v71, v71, 170)))),
                    196);
            v73 = _mm_mul_ps(v72, v57);
            v58 = _mm_max_ps(
                    v58,
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                        _mm_shuffle_ps(v73, v73, 170)),
                      _mm_shuffle_ps(v72, v72, 255)));
          }
          while ( v7 );
          v10 = array;
        }
        if ( v58.m128_f32[0] > 0.0 )
          v4->m_degeneratedMassProperties = 1;
        if ( v4->m_hasIndexing )
        {
          v74 = (unsigned int)v4->m_planes.m_size;
          v58 = 0i64;
          if ( (signed int)v74 > 0 )
          {
            v75 = &v4->m_planes.m_data->m_quad;
            do
            {
              v76 = *v75;
              ++v75;
              v77 = _mm_mul_ps(v76, v57);
              v58 = _mm_max_ps(
                      v58,
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                          _mm_shuffle_ps(v77, v77, 170)),
                        _mm_shuffle_ps(v76, v76, 255)));
              --v74;
            }
            while ( v74 );
          }
        }
        v55 = eigenVal.m_quad;
        if ( v58.m128_f32[0] > 0.0 )
          v4->m_degeneratedMassProperties = 1;
      }
      v4->m_surface.m_real = _mm_mul_ps(v121, (__m128)xmmword_141A711B0);
      v78 = _mm_mul_ps(v10, (__m128)xmmword_141A711F0);
      v79 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u);
      v4->m_volume.m_real = v78;
      if ( v78.m128_f32[0] <= 0.00000011920929 )
      {
        v4->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
        v4->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
        v4->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        v4->m_volume = 0i64;
        v4->m_degeneratedMassProperties = 1;
        v4->m_inertiaMatrix.m_col0 = 0i64;
        v4->m_inertiaMatrix.m_col1 = 0i64;
        v4->m_inertiaMatrix.m_col2 = 0i64;
        v4->m_inertia = 0i64;
      }
      else
      {
        resulta.m_enum = LODWORD(FLOAT_N0_050000001);
        v80 = _mm_mul_ps(
                (__m128)v13,
                _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0), v55));
        v81 = (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_add_ps(_mm_shuffle_ps(v80, v80, 90), _mm_shuffle_ps(v80, v80, 65)),
                          4),
                        4);
        v82 = _mm_mul_ps(
                v14,
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_050000001), (__m128)LODWORD(FLOAT_N0_050000001), 0),
                  v55));
        v119 = _mm_or_ps(
                 _mm_andnot_ps((__m128)xmmword_141A79680, _mm_shuffle_ps(v82, v82, 78)),
                 _mm_and_ps((__m128)xmmword_141A79680, v81));
        v120 = _mm_or_ps(
                 _mm_andnot_ps((__m128)xmmword_141A796A0, _mm_shuffle_ps(v82, v82, 225)),
                 _mm_and_ps((__m128)xmmword_141A796A0, v81));
        scale.m_real = query.m_quad;
        hkMatrix3f::setCrossSkewSymmetric(&aTb, (hkVector4f *)&v122);
        hkMatrix3f::setCrossSkewSymmetric(&bTc, &aabbOut);
        hkMatrix3f::setMul(&v126, &aTb, &aTb);
        hkMatrix3f::setMul(&a, &bTc, &bTc);
        hkMatrix3f::transpose(&a);
        hkMatrix3f::sub(&v126, &a);
        hkMatrix3f::addMul((hkMatrix3f *)&v119.m128_u16[4], &scale, &v126);
        if ( hkMatrix3f::diagonalizeSymmetric(
               (hkMatrix3f *)&v119.m128_u16[4],
               &resulta,
               &eigenVec,
               &eigenVal,
               0,
               128,
               0.00000011920929)->m_enum == 1 )
        {
          v4->m_degeneratedMassProperties = 1;
          eigenVec.m_col0 = (hkVector4f)transform.m_quad;
          eigenVec.m_col1 = (hkVector4f)direction.m_quad;
          eigenVec.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          eigenVal.m_quad = query.m_quad;
          hkErrStream::hkErrStream((hkErrStream *)&scale, &buf, 512);
          v83 = hkOstream::operator<<((hkOstream *)&scale, "Failed to diagonalize inertia matrix (");
          v84 = hkOstream::operator<<(v83, v4->m_uid, (int)v83);
          hkOstream::operator<<(v84, ")");
          hkError::messageWarning(
            283749,
            &buf,
            "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
            1982);
          hkOstream::~hkOstream((hkOstream *)&scale);
        }
        hkMatrix3f::transpose((hkMatrix3f *)&eigenVec.m_col0);
        hkRotationf::renormalize(&eigenVec);
        v85 = v119;
        v4->m_inertiaMatrix.m_col0.m_quad = *(__m128 *)((char *)&v119 + 8);
        v86 = v120;
        v4->m_inertiaMatrix.m_col1.m_quad = v85;
        v4->m_inertiaMatrix.m_col2.m_quad = v86;
        hkMatrix3f::changeBasis((hkMatrix3f *)&v119.m128_u16[4], &eigenVec);
        v87 = *(__m128 *)((char *)&v119 + 8);
        v88 = v120;
        v4->m_inertia.m_quad = *(__m128 *)((char *)&v119 + 8);
        v89 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A79600, v87), _mm_and_ps(v119, (__m128)xmmword_141A79600));
        v4->m_inertia.m_quad = v89;
        v4->m_inertia.m_quad = _mm_or_ps(
                                 _mm_and_ps(v88, (__m128)xmmword_141A79620),
                                 _mm_andnot_ps((__m128)xmmword_141A79620, v89));
        hkMatrix3f::transpose((hkMatrix3f *)&eigenVec.m_col0);
        v90.m_quad = (__m128)eigenVec.m_col1;
        v4->m_localTransform.m_rotation.m_col0 = eigenVec.m_col0;
        v91.m_quad = (__m128)eigenVec.m_col2;
        v4->m_localTransform.m_rotation.m_col1 = (hkVector4f)v90.m_quad;
        v4->m_localTransform.m_rotation.m_col2 = (hkVector4f)v91.m_quad;
        if ( fmin(
               COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 170)),
               fmin(COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 85)), COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 0)))) <= 0.00000011920929 )
          v4->m_degeneratedMassProperties = 1;
      }
      v4->m_hasMassProperties = 1;
    }
    else if ( v5 == 2 )
    {
      v92 = this->m_mesh.m_vertices.m_numUsed;
      v93 = 0i64;
      v94 = 0i64;
      v95 = 0.0;
      v96 = 2147483648;
      v97 = 0i64;
      array.m128_u64[0] = 0i64;
      array.m128_u64[1] = 0x8000000000000000i64;
      if ( v92 > 0 )
      {
        v98 = v92;
        if ( v92 < 0 )
          v98 = 0;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v98, 16);
        v96 = array.m128_i32[3];
        v95 = array.m128_f32[2];
        v94 = (__m128 *)array.m128_u64[0];
      }
      v99 = v4->m_mesh.m_vertices.m_used;
      v100 = v92 + LODWORD(v95);
      array.m128_i32[2] = v100;
      if ( v99 )
      {
        do
        {
          v101 = v94;
          ++v94;
          *v101 = _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(v99->m_x[0]),
                                                 _mm_cvtsi32_si128(v99->m_x[2])),
                                               _mm_unpacklo_epi32(_mm_cvtsi32_si128(v99->m_x[1]), _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v4->m_scaleInv.m_quad),
                    v4->m_origin.m_quad);
          v99 = v99->m_next;
        }
        while ( v99 );
        v96 = array.m128_i32[3];
        v100 = array.m128_i32[2];
        v94 = (__m128 *)array.m128_u64[0];
      }
      v102 = v100 - 1;
      if ( v102 > 1 )
      {
        v103 = *v94;
        v104 = v94 + 1;
        v105 = v102 - 1;
        do
        {
          v106 = *v104;
          v107 = v104[1];
          ++v104;
          v108 = _mm_sub_ps(v107, v103);
          v109 = _mm_sub_ps(v106, v103);
          v110 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v108, v108, 201), v109),
                   _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v108));
          v111 = _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v4->m_projectionPlane.m_quad);
          v112 = (__m128)_mm_srli_epi32(
                           _mm_slli_epi32(
                             (__m128i)_mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                                        _mm_shuffle_ps(v111, v111, 170)),
                             1u),
                           1u);
          v97 = _mm_add_ps(v97, v112);
          v93 = _mm_add_ps(v93, _mm_mul_ps(_mm_mul_ps(v112, (__m128)xmmword_141A711C0), _mm_add_ps(v108, v109)));
          --v105;
        }
        while ( v105 );
      }
      v4->m_hasMassProperties = 1;
      v4->m_surface.m_real = _mm_mul_ps(v97, (__m128)xmmword_141A711B0);
      v113.m_quad = (__m128)v4->m_inertiaMatrix.m_col0;
      v113.m_quad.m128_f32[0] = 1.0;
      v4->m_inertiaMatrix.m_col0 = (hkVector4f)v113.m_quad;
      v4->m_inertia = (hkVector4f)transform.m_quad;
      v114 = _mm_add_ps(_mm_mul_ps(_mm_div_ps(query.m_quad, v97), v93), *v94);
      array.m128_i32[2] = 0;
      v4->m_localTransform.m_translation.m_quad = v114;
      if ( v96 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v94,
          16 * v96);
    }
    else
    {
      this->m_hasMassProperties = 1;
      this->m_surface = 0i64;
      this->m_volume = 0i64;
      this->m_inertiaMatrix.m_col0 = (hkVector4f)transform.m_quad;
      this->m_inertiaMatrix.m_col1 = (hkVector4f)direction.m_quad;
      this->m_inertiaMatrix.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      this->m_inertia = 0i64;
      this->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
      this->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      this->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      this->m_localTransform.m_translation = 0i64;
    }
  }
  v115 = v3;
  LOBYTE(v2) = v4->m_hasMassProperties == 0;
  v3->m_enum = v2;
  return v115;
}0i64;
      this->m_volume = 0i64;
      this->m_inertiaMatrix.m_col0 = (hkVector4f)transform.m_quad;
      this->m_inertiaMatrix.m_col1 = (hkVector4f)direction.m_quad;
      this->m_inertiaMatrix.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      this->m_inertia = 0i64;
      this->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
      this->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      this->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    

// File Line: 2058
// RVA: 0xCB2830
__int64 __fastcall hkgpConvexHullImpl::generateIndexedFaces<int,int>(hkgpConvexHullImpl *this, hkArray<int,hkContainerHeapAllocator> *vpf, hkArray<int,hkContainerHeapAllocator> *vi, bool useSourceIndex, bool maximizeArea)
{
  signed __int64 v5; // r12
  bool v6; // si
  hkArray<int,hkContainerHeapAllocator> *v7; // rbx
  hkArray<int,hkContainerHeapAllocator> *v8; // rdi
  hkgpConvexHullImpl *v9; // r15
  unsigned int v10; // er14
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int v22; // eax
  hkgpConvexHullImpl::Triangle *i; // rdx
  signed __int64 v24; // r8
  int v25; // er9
  hkgpConvexHullImpl::Triangle *v26; // r8
  int v27; // edx
  __int64 v28; // rdi
  char v29; // r15
  signed __int64 v30; // rcx
  __int64 v31; // r13
  __int64 v32; // rcx
  unsigned int v33; // esi
  int *v34; // rsi
  __int64 v35; // rcx
  char v36; // cl
  __int64 v37; // rcx
  signed __int64 v38; // rcx
  bool v39; // zf
  int v40; // esi
  hkgpConvexHullImpl::Vertex *j; // rdi
  unsigned int v42; // esi
  int k; // edi
  int v44; // er9
  int *v45; // rax
  int v46; // ecx
  hkgpConvexHullImpl::Vertex *l; // rbx
  hkArray<int,hkContainerHeapAllocator> *v48; // rax
  __int64 v49; // r14
  __int64 v50; // r9
  signed int v51; // er9
  signed __int64 v52; // r15
  int v53; // er13
  hkgpConvexHullImpl::Triangle *v54; // r11
  hkgpConvexHullImpl::Triangle *v55; // rdx
  hkgpConvexHullImpl::Triangle *v56; // rcx
  int v57; // er9
  int v58; // eax
  int v59; // ebx
  int v60; // edi
  int v61; // esi
  int v62; // er10
  int v63; // edx
  signed __int64 v64; // rax
  signed __int64 v65; // rcx
  signed int v66; // edi
  char *v67; // rdx
  signed int v68; // er8
  __int64 v69; // rbx
  int v70; // er9
  signed __int64 v71; // rcx
  int v72; // eax
  signed __int64 m; // rcx
  int v74; // eax
  signed __int64 n; // rcx
  int v76; // eax
  hkgpConvexHullImpl::Triangle **array; // [rsp+30h] [rbp-D0h]
  int v79; // [rsp+38h] [rbp-C8h]
  int v80; // [rsp+3Ch] [rbp-C4h]
  hkResult result[2]; // [rsp+40h] [rbp-C0h]
  __int128 v82; // [rsp+50h] [rbp-B0h]
  int v83; // [rsp+60h] [rbp-A0h]
  __int64 v84; // [rsp+68h] [rbp-98h]
  int v85; // [rsp+70h] [rbp-90h]
  hkErrStream v86; // [rsp+80h] [rbp-80h]
  __m128i v87; // [rsp+A0h] [rbp-60h]
  __m128i v88; // [rsp+B0h] [rbp-50h]
  char *v89; // [rsp+C0h] [rbp-40h]
  int v90; // [rsp+C8h] [rbp-38h]
  int v91; // [rsp+CCh] [rbp-34h]
  char v92; // [rsp+D0h] [rbp-30h]
  char buf; // [rsp+150h] [rbp+50h]
  hkgpConvexHullImpl *v94; // [rsp+3A0h] [rbp+2A0h]
  int v95; // [rsp+3A0h] [rbp+2A0h]
  hkArray<int,hkContainerHeapAllocator> *v96; // [rsp+3A8h] [rbp+2A8h]
  signed int v97; // [rsp+3B0h] [rbp+2B0h]
  bool v98; // [rsp+3B8h] [rbp+2B8h]

  v98 = useSourceIndex;
  v96 = vpf;
  v94 = this;
  v5 = 0i64;
  v6 = useSourceIndex;
  v7 = vi;
  v8 = vpf;
  v9 = this;
  v10 = 0;
  v97 = 0;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v86, &buf, 512);
    v11 = hkOstream::operator<<((hkOstream *)&v86.vfptr, "No index available (");
    v12 = hkOstream::operator<<(v11, v9->m_uid, (int)v11);
    hkOstream::operator<<(v12, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v86.vfptr);
  }
  v13 = v8->m_capacityAndFlags;
  v8->m_size = 0;
  v14 = v9->m_planes.m_size;
  v15 = v13 & 0x3FFFFFFF;
  if ( v15 < v14 )
  {
    v16 = 2 * v15;
    if ( v14 < v16 )
      v14 = v16;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v14, 4);
  }
  v7->m_size = 0;
  v17 = 3 * v9->m_mesh.m_vertices.m_numUsed;
  v18 = v7->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v17, 4);
  }
  v20 = v9->m_dimensions;
  if ( v20 == 3 )
  {
    v21 = v9->m_mesh.m_triangles.m_numUsed;
    v22 = 0;
    array = 0i64;
    v79 = 0;
    v80 = 2147483648;
    if ( v21 > 0 )
    {
      if ( v21 < 0 )
        v21 = 0;
      hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v21, 8);
      v22 = v79;
    }
    for ( i = v9->m_mesh.m_triangles.m_used; i; i = i->m_next )
    {
      array[v22] = i;
      v22 = v79++ + 1;
    }
    if ( v22 > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::Triangle *,hkgpConvexHullImpl::Triangle::SortByPlaneId>(
        array,
        0,
        v22 - 1,
        0);
      v22 = v79;
    }
    v24 = 0i64;
    *(_QWORD *)&result[0].m_enum = 0i64;
    v84 = v22;
    if ( v22 > 0i64 )
    {
      v25 = `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard;
      do
      {
        v26 = array[v24];
        if ( v26->m_plane.m_index == v10 )
        {
          if ( !(v25 & 1) )
          {
            v25 |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard = v25;
          }
          v27 = 0;
          v82 = `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e;
          while ( *(_DWORD *)((v26->m_links[v27] & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 )
          {
            if ( ++v27 >= 3 )
              goto LABEL_32;
          }
          v88.m128i_i64[0] = (__int64)v26;
          v88.m128i_i32[2] = v27;
          _mm_store_si128((__m128i *)&v82, v88);
LABEL_32:
          v28 = v82;
          if ( (_QWORD)v82 )
          {
            v29 = BYTE8(v82);
            v30 = SDWORD2(v82) + 2i64;
            v31 = *(_QWORD *)(v82 + 8 * v30);
            v32 = v82 + 8 * v30;
            do
            {
              LODWORD(v5) = v5 + 1;
              if ( v6 )
              {
                v33 = *(_DWORD *)(*(_QWORD *)v32 + 28i64) & 0xC0FFFFFF;
                if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
                v7->m_data[v7->m_size] = v33;
              }
              else
              {
                v34 = (int *)(*(_QWORD *)v32 + 52i64);
                if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
                v7->m_data[v7->m_size] = *v34;
              }
              ++v7->m_size;
              v87.m128i_i64[0] = v28;
              v87.m128i_i32[2] = (9 >> 2 * v29) & 3;
              v35 = *(_QWORD *)(v28 + 8i64 * v87.m128i_i32[2] + 40);
              _mm_store_si128((__m128i *)&v82, v87);
              if ( *(_DWORD *)((v35 & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 )
              {
                do
                {
                  v36 = *(_QWORD *)(v82 + 8i64 * SDWORD2(v82) + 40) & 3;
                  v86.vfptr = (hkBaseObjectVtbl *)(*(_QWORD *)(v82 + 8i64 * SDWORD2(v82) + 40) & 0xFFFFFFFFFFFFFFFCui64);
                  *(_DWORD *)&v86.m_memSizeAndFlags = (9 >> 2 * v36) & 3;
                  v37 = *((_QWORD *)&v86.vfptr[2].__first_virtual_table_function__
                        + *(signed int *)&v86.m_memSizeAndFlags);
                  _mm_store_si128((__m128i *)&v82, *(__m128i *)&v86.vfptr);
                }
                while ( *(_DWORD *)((v37 & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 );
              }
              v29 = BYTE8(v82);
              v28 = v82;
              v6 = v98;
              v38 = SDWORD2(v82) + 2i64;
              v39 = *(_QWORD *)(v82 + 8 * v38) == v31;
              v32 = v82 + 8 * v38;
            }
            while ( !v39 );
            if ( v96->m_size == (v96->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v96, 4);
            v6 = v98;
            v96->m_data[v96->m_size++] = v5;
            v25 = `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard;
            ++v10;
            v5 = 0i64;
          }
        }
        v24 = *(_QWORD *)&result[0].m_enum + 1i64;
        *(_QWORD *)&result[0].m_enum = v24;
      }
      while ( v24 < v84 );
      v9 = v94;
      v97 = v10;
    }
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v80);
  }
  else if ( v20 == 2 )
  {
    v40 = v9->m_mesh.m_vertices.m_numUsed;
    v10 = 1;
    v97 = 1;
    if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 4);
    v8->m_data[v8->m_size++] = v40;
    if ( v98 )
    {
      for ( j = v9->m_mesh.m_vertices.m_used; j; j = j->m_next )
      {
        v42 = j->m_source.m_quad.m128_i32[3] & 0xC0FFFFFF;
        if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
        v7->m_data[v7->m_size++] = v42;
      }
    }
    else
    {
      for ( k = 0; k < v9->m_mesh.m_vertices.m_numUsed; ++k )
      {
        if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
        v7->m_data[v7->m_size++] = k;
      }
    }
  }
  if ( maximizeArea && v10 )
  {
    v44 = v9->m_mesh.m_vertices.m_numUsed;
    v45 = v7->m_data;
    v46 = 0;
    array = 0i64;
    v79 = 0;
    v80 = 2147483648;
    *(_QWORD *)&v82 = v45;
    if ( v44 > 0 )
    {
      if ( v44 < 0 )
        v44 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&maximizeArea,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v44,
        8);
      v46 = v79;
    }
    for ( l = v9->m_mesh.m_vertices.m_used; l; l = l->m_next )
    {
      if ( v46 == (v80 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v46 = v79;
      }
      array[v46] = (hkgpConvexHullImpl::Triangle *)l;
      v46 = v79++ + 1;
    }
    v48 = v96;
    v95 = 0;
    if ( v96->m_size > 0 )
    {
      v49 = v82;
      v50 = 0i64;
      v84 = 0i64;
      do
      {
        v51 = *(int *)((char *)v48->m_data + v50);
        *(_DWORD *)&maximizeArea = v51;
        if ( v51 >= 3 )
        {
          v52 = -1i64;
          *(_QWORD *)&v82 = -1i64;
          v83 = -1;
          v53 = 0;
          if ( v51 <= 0 )
          {
            v5 = 0i64;
          }
          else
          {
            do
            {
              v85 = v53 + 1;
              v54 = array[*(signed int *)(v49 + 4i64 * ((v53 + 2) % v51))];
              v55 = array[*(signed int *)(v49 + 4i64 * ((v53 + 1) % v51))];
              v56 = array[*(signed int *)(v49 + 4 * v5)];
              v57 = HIDWORD(v54->m_vertices[2]) - HIDWORD(v56->m_vertices[2]);
              v58 = v56->m_links[0];
              v59 = LODWORD(v54->m_vertices[2]) - LODWORD(v56->m_vertices[2]);
              v60 = HIDWORD(v55->m_vertices[2]) - HIDWORD(v56->m_vertices[2]);
              v61 = LODWORD(v55->m_vertices[2]) - LODWORD(v56->m_vertices[2]);
              LODWORD(v56) = LODWORD(v54->m_links[0]) - v58;
              v62 = LODWORD(v55->m_links[0]) - v58;
              v63 = v60 * (_DWORD)v56 - v62 * v57;
              v64 = (v62 * v59 - v61 * (signed int)v56) * (signed __int64)(v62 * v59 - v61 * (signed int)v56);
              v65 = (v61 * v57 - v60 * v59) * (signed __int64)(v61 * v57 - v60 * v59);
              if ( v65 + v64 + v63 * (signed __int64)v63 <= (signed __int64)v82 )
              {
                v66 = v83;
              }
              else
              {
                *(_QWORD *)&v82 = v65 + v64 + v63 * (signed __int64)v63;
                v66 = v53;
                v83 = v53;
                v52 = v5;
              }
              v53 = v85;
              v51 = maximizeArea;
              ++v5;
            }
            while ( v85 < maximizeArea );
            v5 = 0i64;
            if ( v66 > 0 )
            {
              v67 = &v92;
              v68 = -2147483616;
              v90 = 0;
              v69 = v49;
              v89 = &v92;
              v91 = -2147483616;
              if ( v66 <= 32 )
              {
                result[0].m_enum = 0;
              }
              else
              {
                v70 = v66;
                if ( v66 < 64 )
                  v70 = 64;
                hkArrayUtil::_reserve(
                  result,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v89,
                  v70,
                  4);
                v68 = v91;
                v67 = v89;
                v51 = maximizeArea;
              }
              v90 = v66;
              v71 = 0i64;
              if ( v52 > 0 )
              {
                do
                {
                  v72 = *(_DWORD *)(v49 + 4 * v71++);
                  *(_DWORD *)&v67[4 * v71 - 4] = v72;
                  v67 = v89;
                }
                while ( v71 < v52 );
                v68 = v91;
              }
              for ( m = v52; m < v51; *(_DWORD *)(v69 - 4) = v74 )
              {
                v74 = *(_DWORD *)(v49 + 4 * m++);
                v69 += 4i64;
              }
              for ( n = 0i64; n < v52; *(_DWORD *)(v69 - 4) = v76 )
              {
                v76 = *(_DWORD *)&v67[4 * n++];
                v69 += 4i64;
              }
              v90 = 0;
              if ( v68 >= 0 )
              {
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v67,
                  4 * v68);
                v51 = maximizeArea;
              }
            }
          }
        }
        ++v95;
        v49 += 4i64 * v51;
        v48 = v96;
        v50 = v84 + 4;
        v84 += 4i64;
      }
      while ( v95 < v96->m_size );
      v10 = v97;
    }
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v80);
  }
  return v10;
}

// File Line: 2177
// RVA: 0xCB6830
void __fastcall hkgpConvexHullImpl::generateVertexAdjacencyGraph(hkgpConvexHullImpl *this, hkArray<int,hkContainerHeapAllocator> *edges, hkArray<int,hkContainerHeapAllocator> *vertexOffsets)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // r15
  hkArray<int,hkContainerHeapAllocator> *v4; // rdi
  hkgpConvexHullImpl *v5; // r13
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  __int64 v8; // r14
  int v9; // ecx
  int v10; // er9
  __int64 v11; // rsi
  char *v12; // rbx
  int v13; // er8
  int v14; // eax
  __int64 v15; // rdx
  __int64 v16; // rcx
  hkgpConvexHullImpl::Triangle *v17; // r12
  signed int v18; // esi
  signed __int64 v19; // r14
  __int64 v20; // rbx
  hkgpConvexHullImpl::Vertex *v21; // r15
  __int64 v22; // rsi
  int v23; // er9
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  int v28; // eax
  int v29; // er9
  hkResultEnum v30; // edx
  int v31; // er13
  __int64 v32; // rbx
  __int64 v33; // r12
  int v34; // esi
  char *v35; // rax
  int v36; // ecx
  int v37; // er14
  __int64 v38; // r15
  int v39; // eax
  __int64 v40; // rdi
  char *v41; // rbx
  int v42; // er8
  char *array; // [rsp+30h] [rbp-D0h]
  int v44; // [rsp+38h] [rbp-C8h]
  int v45; // [rsp+3Ch] [rbp-C4h]
  hkErrStream v46; // [rsp+40h] [rbp-C0h]
  char buf; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+2A0h] [rbp+1A0h]
  hkArray<int,hkContainerHeapAllocator> *v49; // [rsp+2B0h] [rbp+1B0h]

  v49 = vertexOffsets;
  v3 = vertexOffsets;
  v4 = edges;
  v5 = this;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v46, &buf, 512);
    v6 = hkOstream::operator<<((hkOstream *)&v46.vfptr, "No index available (");
    v7 = hkOstream::operator<<(v6, v5->m_uid, (int)v6);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v46.vfptr);
  }
  v8 = v5->m_mesh.m_vertices.m_numUsed;
  v45 = 2147483648;
  array = 0i64;
  v9 = 0;
  v44 = 0;
  if ( (signed int)v8 > 0 )
  {
    v10 = v8;
    if ( (signed int)v8 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v10, 16);
    v9 = v44;
  }
  v11 = v9 - (signed int)v8 - 1;
  if ( v9 - (signed int)v8 - 1 >= 0 )
  {
    v12 = &array[16 * v8 + 12 + 16 * v11];
    do
    {
      v13 = *(_DWORD *)v12;
      *((_DWORD *)v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 12),
          4 * v13);
      *(_QWORD *)(v12 - 12) = 0i64;
      *(_DWORD *)v12 = 2147483648;
      v12 -= 16;
      --v11;
    }
    while ( v11 >= 0 );
    v9 = v44;
    v3 = v49;
  }
  v14 = v8 - v9;
  v15 = (signed int)v8 - v9;
  v16 = (__int64)&array[16 * v9];
  if ( v14 > 0 )
  {
    do
    {
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_DWORD *)(v16 + 12) = 2147483648;
      }
      v16 += 16i64;
      --v15;
    }
    while ( v15 );
  }
  v17 = v5->m_mesh.m_triangles.m_used;
  v44 = v8;
  if ( v17 )
  {
    do
    {
      v18 = 0;
      v19 = (signed __int64)v17->m_vertices;
      do
      {
        v20 = (__int64)&array[16 * *(signed int *)(*(_QWORD *)v19 + 52i64)];
        v21 = v17->m_vertices[(9i64 >> 2 * (unsigned __int8)v18) & 3];
        if ( *(_DWORD *)(v20 + 8) == (*(_DWORD *)(v20 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array[16 * *(signed int *)(*(_QWORD *)v19 + 52i64)],
            4);
        ++v18;
        v19 += 8i64;
        *(_DWORD *)(*(_QWORD *)v20 + 4i64 * (signed int)(*(_DWORD *)(v20 + 8))++) = v21->m_index;
      }
      while ( v18 < 3 );
      v17 = v17->m_next;
    }
    while ( v17 );
    v3 = v49;
  }
  LODWORD(v22) = 0;
  v4->m_size = 0;
  v23 = v5->m_mesh.m_vertices.m_numUsed + 3 * v5->m_mesh.m_triangles.m_numUsed;
  v24 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < v23 )
  {
    v25 = 2 * v24;
    if ( v23 < v25 )
      v23 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v23, 4);
  }
  v26 = v5->m_mesh.m_vertices.m_numUsed;
  v27 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 < v26 )
  {
    v28 = 2 * v27;
    v29 = v5->m_mesh.m_vertices.m_numUsed;
    if ( v26 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v29, 4);
  }
  v30 = 0;
  v3->m_size = v26;
  v31 = 0;
  result.m_enum = 0;
  if ( v44 > 0 )
  {
    v32 = 0i64;
    v33 = 0i64;
    do
    {
      v34 = *(_DWORD *)&array[v32 + 8];
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 4);
        v30 = result.m_enum;
      }
      v4->m_data[v4->m_size++] = v34;
      v35 = array;
      v36 = v4->m_size;
      v22 = 0i64;
      v37 = 0;
      if ( *(_DWORD *)&array[v32 + 8] > 0 )
      {
        do
        {
          v38 = *(_QWORD *)&v35[v32];
          if ( v36 == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 4);
          ++v37;
          v39 = *(_DWORD *)(v38 + v22);
          v22 += 4i64;
          v4->m_data[v4->m_size++] = v39;
          v35 = array;
          v36 = v4->m_size;
        }
        while ( v37 < *(_DWORD *)&array[v32 + 8] );
        v30 = result.m_enum;
        v3 = v49;
        LODWORD(v22) = 0;
      }
      ++v31;
      ++v33;
      v3->m_data[v33 - 1] = v30;
      v30 += *(_DWORD *)&array[v32 + 8] + 1;
      v32 += 16i64;
      result.m_enum = v30;
    }
    while ( v31 < v44 );
  }
  v40 = v44 - 1;
  if ( v44 - 1 >= 0 )
  {
    v41 = &array[16 * (v44 - 1) + 12];
    do
    {
      v42 = *(_DWORD *)v41;
      *((_DWORD *)v41 - 1) = v22;
      if ( v42 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v41 - 12),
          4 * v42);
      *(_QWORD *)(v41 - 12) = 0i64;
      *(_DWORD *)v41 = 2147483648;
      v41 -= 16;
      --v40;
    }
    while ( v40 >= 0 );
  }
  v44 = v22;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v45);
}

// File Line: 2209
// RVA: 0xCB6490
void __fastcall hkgpConvexHullImpl::generatePlanesPerVertex(hkgpConvexHullImpl *this, hkArray<int,hkContainerHeapAllocator> *startPlaneOffsetOut, hkArray<int,hkContainerHeapAllocator> *planeIndicesOut)
{
  hkArrayBase<unsigned int> *v3; // r13
  hkArray<int,hkContainerHeapAllocator> *v4; // r12
  hkgpConvexHullImpl *v5; // rsi
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  __int64 v8; // r15
  int v9; // edx
  int v10; // er9
  __int64 v11; // rbp
  __int64 v12; // rdi
  char *v13; // rbx
  int v14; // er8
  int v15; // eax
  __int64 v16; // rcx
  __int64 v17; // rdx
  hkgpConvexHullImpl::Triangle *v18; // r14
  int v19; // edi
  signed __int64 v20; // rsi
  signed __int64 v21; // rbp
  int v22; // edx
  __int64 v23; // rcx
  __int64 v24; // rbx
  __int64 v25; // r9
  _DWORD *v26; // rax
  int v27; // ebx
  int v28; // eax
  int v29; // eax
  int v30; // er9
  int *v31; // rax
  __int64 v32; // rbx
  __int64 v33; // rdi
  __int64 v34; // rdi
  char *v35; // rbx
  int v36; // er8
  char *array; // [rsp+30h] [rbp-258h]
  int v38; // [rsp+38h] [rbp-250h]
  int v39; // [rsp+3Ch] [rbp-24Ch]
  hkErrStream v40; // [rsp+40h] [rbp-248h]
  char buf; // [rsp+60h] [rbp-228h]
  hkResult result; // [rsp+290h] [rbp+8h]

  v3 = (hkArrayBase<unsigned int> *)planeIndicesOut;
  v4 = startPlaneOffsetOut;
  v5 = this;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v40, &buf, 512);
    v6 = hkOstream::operator<<((hkOstream *)&v40.vfptr, "No index available (");
    v7 = hkOstream::operator<<(v6, v5->m_uid, (int)v6);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v40.vfptr);
  }
  v8 = v5->m_mesh.m_vertices.m_numUsed;
  v39 = 2147483648;
  v9 = 0;
  array = 0i64;
  v38 = 0;
  if ( (signed int)v8 > 0 )
  {
    v10 = v8;
    if ( (signed int)v8 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v10, 16);
    v9 = v38;
  }
  v11 = v8;
  v12 = v9 - (signed int)v8 - 1;
  if ( v9 - (signed int)v8 - 1 >= 0 )
  {
    v13 = &array[16 * v8 + 12 + 16 * v12];
    do
    {
      v14 = *(_DWORD *)v13;
      *((_DWORD *)v13 - 1) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v13 - 12),
          4 * v14);
      *(_QWORD *)(v13 - 12) = 0i64;
      *(_DWORD *)v13 = 2147483648;
      v13 -= 16;
      --v12;
    }
    while ( v12 >= 0 );
    v9 = v38;
  }
  v15 = v8 - v9;
  v16 = (__int64)&array[16 * v9];
  v17 = (signed int)v8 - v9;
  if ( v15 > 0 )
  {
    do
    {
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_DWORD *)(v16 + 12) = 2147483648;
      }
      v16 += 16i64;
      --v17;
    }
    while ( v17 );
  }
  v18 = v5->m_mesh.m_triangles.m_used;
  v38 = v8;
  if ( v18 )
  {
    do
    {
      v19 = v18->m_plane.m_index;
      v20 = (signed __int64)v18->m_vertices;
      v21 = 3i64;
      do
      {
        v22 = 0;
        v23 = 0i64;
        v24 = (__int64)&array[16 * *(signed int *)(*(_QWORD *)v20 + 52i64)];
        v25 = *(signed int *)(v24 + 8);
        if ( (signed int)v25 <= 0 )
          goto LABEL_27;
        v26 = *(_DWORD **)v24;
        while ( *v26 != v19 )
        {
          ++v23;
          ++v22;
          ++v26;
          if ( v23 >= v25 )
            goto LABEL_27;
        }
        if ( v22 < 0 )
        {
LABEL_27:
          if ( (_DWORD)v25 == (*(_DWORD *)(v24 + 12) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &array[16 * *(signed int *)(*(_QWORD *)v20 + 52i64)],
              4);
          *(_DWORD *)(*(_QWORD *)v24 + 4i64 * (signed int)(*(_DWORD *)(v24 + 8))++) = v19;
        }
        v20 += 8i64;
        --v21;
      }
      while ( v21 );
      v18 = v18->m_next;
    }
    while ( v18 );
    v11 = v8;
  }
  v3->m_size = 0;
  v27 = v8 + 1;
  v28 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v28 < (signed int)v8 + 1 )
  {
    v29 = 2 * v28;
    v30 = v8 + 1;
    if ( v27 < v29 )
      v30 = v29;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v30, 4);
  }
  v31 = v4->m_data;
  v4->m_size = v27;
  v32 = 0i64;
  *v31 = 0;
  if ( v11 > 0 )
  {
    v33 = 0i64;
    do
    {
      hkArrayBase<unsigned int>::_append(
        v3,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        *(const unsigned int **)&array[v33],
        *(_DWORD *)&array[v33 + 8]);
      v4->m_data[v32++ + 1] = v3->m_size;
      v33 += 16i64;
    }
    while ( v32 < v11 );
  }
  v34 = v38 - 1;
  if ( v38 - 1 >= 0 )
  {
    v35 = &array[16 * (v38 - 1) + 12];
    do
    {
      v36 = *(_DWORD *)v35;
      *((_DWORD *)v35 - 1) = 0;
      if ( v36 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v35 - 12),
          4 * v36);
      *(_QWORD *)(v35 - 12) = 0i64;
      *(_DWORD *)v35 = 2147483648;
      v35 -= 16;
      --v34;
    }
    while ( v34 >= 0 );
  }
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v39);
}

// File Line: 2290
// RVA: 0xCB35F0
signed __int64 __fastcall hkgpConvexHullImpl::splitByPlane<hkgpConvexHullImpl::PositionAsSource>(hkgpConvexHullImpl *this, hkVector4f *plane, hkgpConvexHull **pos, hkgpConvexHull **neg, float thickness)
{
  hkgpConvexHull **v5; // r12
  hkgpConvexHull **v6; // r13
  hkVector4f *v7; // r10
  hkgpConvexHullImpl *v8; // r15
  int v9; // ecx
  __m128 *v11; // rax
  int v12; // ebx
  int v13; // er8
  float v14; // xmm5_4
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  signed int v21; // ecx
  signed int v22; // eax
  unsigned int v23; // ebx
  int v24; // eax
  int v25; // eax
  hkgpConvexHullImpl::Vertex *v26; // rbx
  float v27; // xmm0_4
  int v28; // ecx
  __int64 v29; // rax
  hkgpConvexHullImpl::Triangle *i; // rsi
  signed int v31; // ebx
  signed __int64 v32; // rdi
  __m128 *v33; // rdx
  float v34; // xmm3_4
  __m128 *v35; // rcx
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  int v38; // ecx
  _QWORD **v39; // rax
  hkgpConvexHull *v40; // rax
  hkgpConvexHull *v41; // rax
  hkgpConvexHullImpl *v42; // rcx
  _QWORD **v43; // rax
  hkgpConvexHull *v44; // rax
  hkgpConvexHull *v45; // rax
  hkgpConvexHullImpl *v46; // rcx
  bool v47; // di
  bool v48; // bl
  __m128 *v49; // rax
  int v50; // edx
  int v51; // ecx
  float v52; // xmm3_4
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  float v56; // xmm1_4
  __m128 *v57; // rbx
  int v58; // edx
  int v59; // ecx
  __m128 *v60; // rax
  __m128 *v61; // r8
  float v62; // xmm2_4
  __m128 v63; // xmm8
  __m128 v64; // xmm0
  __m128 v65; // xmm6
  int v66; // ecx
  signed int v67; // er14
  _QWORD **v68; // rax
  hkgpConvexHull *v69; // rax
  hkgpConvexHull *v70; // rax
  hkgpConvexHullImpl *v71; // rcx
  _QWORD **v72; // rax
  hkgpConvexHull *v73; // rax
  hkgpConvexHull *v74; // rax
  hkgpConvexHullImpl *v75; // rcx
  int *v76; // rbx
  int v77; // er8
  hkErrStream array; // [rsp+30h] [rbp-D0h]
  int v79; // [rsp+48h] [rbp-B8h]
  int v80; // [rsp+4Ch] [rbp-B4h]
  hkVector4f *points; // [rsp+50h] [rbp-B0h]
  int numPoints; // [rsp+58h] [rbp-A8h]
  int v83; // [rsp+5Ch] [rbp-A4h]
  char buf; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+2D0h] [rbp+1D0h]
  hkResult v86; // [rsp+2E0h] [rbp+1E0h]
  float v87; // [rsp+2E8h] [rbp+1E8h]

  v5 = neg;
  v6 = pos;
  v7 = plane;
  v8 = this;
  if ( pos )
    *pos = 0i64;
  if ( neg )
    *neg = 0i64;
  v9 = this->m_dimensions - 2;
  if ( v9 )
  {
    if ( v9 != 1 )
    {
      hkErrStream::hkErrStream(&array, &buf, 512);
      hkOstream::operator<<((hkOstream *)&array.vfptr, "Current dimension not implemented for that operation");
      if ( (unsigned int)hkError::messageError(
                           981918703,
                           &buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           2419) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&array.vfptr);
      return 4i64;
    }
    v11 = (__m128 *)v8->m_mesh.m_vertices.m_used;
    v12 = 0;
    v13 = 0;
    LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0);
    v15 = 0i64;
    v16 = 0i64;
    if ( v11 )
    {
      do
      {
        v17 = _mm_mul_ps(v11[1], plane->m_quad);
        v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, plane->m_quad), 196);
        v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
        if ( v11->m128_u64[1] )
        {
          v15 = _mm_min_ps(v20, v15);
          v16 = _mm_max_ps(v20, v16);
        }
        else
        {
          v15 = v20;
          v16 = v20;
        }
        if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= v14 )
        {
          v11[2].m128_i32[3] = v20.m128_i32[0];
          if ( v20.m128_f32[0] <= 0.0 )
            ++v12;
          else
            ++v13;
        }
        else
        {
          v11[2].m128_i32[3] = 0;
        }
        v11 = (__m128 *)v11->m128_u64[0];
      }
      while ( v11 );
      if ( v13 && v12 )
      {
        v21 = 0;
        v22 = 0;
        array.vfptr = 0i64;
        *(_DWORD *)&array.m_memSizeAndFlags = 0;
        *(_DWORD *)(&array.m_referenceCount + 1) = 2147483648;
        points = 0i64;
        numPoints = 0;
        v83 = 2147483648;
        if ( fmin(
               COERCE_FLOAT((unsigned int)(2 * v15.m128_i32[0]) >> 1),
               COERCE_FLOAT((unsigned int)(2 * v16.m128_i32[0]) >> 1)) <= v14 )
          v21 = 1;
        if ( (float)(v16.m128_f32[0] - v15.m128_f32[0]) <= v14 )
          v22 = 1;
        if ( v22 | v21 )
        {
          v23 = ((float)((float)(v15.m128_f32[0] + v16.m128_f32[0]) * 0.5) < 0.0) + 1;
LABEL_94:
          numPoints = 0;
          if ( v83 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              points,
              16 * v83);
          points = 0i64;
          v83 = 2147483648;
          *(_DWORD *)&array.m_memSizeAndFlags = 0;
          if ( *(_DWORD *)(&array.m_referenceCount + 1) >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array.vfptr,
              16 * *(_DWORD *)(&array.m_referenceCount + 1));
          return v23;
        }
        v24 = v13 + v8->m_mesh.m_vertices.m_numUsed / 4;
        if ( v24 <= 0 )
        {
          result.m_enum = 0;
        }
        else
        {
          if ( v24 < 0 )
            v24 = 0;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v24, 16);
        }
        v25 = v12 + v8->m_mesh.m_vertices.m_numUsed / 4;
        if ( (v83 & 0x3FFFFFFF) >= v25 )
        {
          v86.m_enum = 0;
        }
        else
        {
          if ( v25 < 2 * (v83 & 0x3FFFFFFF) )
            v25 = 2 * (v83 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v86, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, v25, 16);
        }
        v26 = v8->m_mesh.m_vertices.m_used;
        if ( !v26 )
        {
LABEL_54:
          for ( i = v8->m_mesh.m_triangles.m_used; i; i = i->m_next )
          {
            v31 = 0;
            v32 = (signed __int64)i->m_vertices;
            do
            {
              v33 = *(__m128 **)v32;
              v34 = *(float *)(*(_QWORD *)v32 + 44i64);
              if ( v34 > 0.0 )
              {
                v35 = (__m128 *)i->m_vertices[(9i64 >> 2 * (unsigned __int8)v31) & 3];
                if ( (float)(v35[2].m128_f32[3] * v34) < 0.0 )
                {
                  v36 = _mm_sub_ps(v35[1], v33[1]);
                  v87 = v34 / (float)(v34 - v35[2].m128_f32[3]);
                  v37 = _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0), v36),
                          v33[1]);
                  if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                  array.vfptr[*(signed int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)v37;
                  v38 = numPoints;
                  ++*(_DWORD *)&array.m_memSizeAndFlags;
                  if ( numPoints == (v83 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      &points,
                      16);
                    v38 = numPoints;
                  }
                  points[v38] = (hkVector4f)v37;
                  ++numPoints;
                }
              }
              ++v31;
              v32 += 8i64;
            }
            while ( v31 < 3 );
          }
          if ( v6 )
          {
            v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v40 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v39[11] + 8i64))(
                                      v39[11],
                                      40i64);
            if ( v40 )
              hkgpConvexHull::hkgpConvexHull(v40);
            else
              v41 = 0i64;
            *v6 = v41;
            v42 = v41->m_data;
            *(_DWORD *)&v42->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&v8->m_config.m_allowLowerDimensions.m_bool;
            v42->m_config.m_minCosAngle = v8->m_config.m_minCosAngle;
            *(_DWORD *)&v42->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&v8->m_config.m_setSourceIndices.m_bool;
            *(_DWORD *)&v42->m_config.m_internalInputs.m_bool = *(_DWORD *)&v8->m_config.m_internalInputs.m_bool;
          }
          if ( v5 )
          {
            v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v44 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(
                                      v43[11],
                                      40i64);
            if ( v44 )
              hkgpConvexHull::hkgpConvexHull(v44);
            else
              v45 = 0i64;
            *v5 = v45;
            v46 = v45->m_data;
            *(_DWORD *)&v46->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&v8->m_config.m_allowLowerDimensions.m_bool;
            v46->m_config.m_minCosAngle = v8->m_config.m_minCosAngle;
            *(_DWORD *)&v46->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&v8->m_config.m_setSourceIndices.m_bool;
            *(_DWORD *)&v46->m_config.m_internalInputs.m_bool = *(_DWORD *)&v8->m_config.m_internalInputs.m_bool;
          }
          v47 = v6
             && hkgpConvexHullImpl::build(
                  (*v6)->m_data,
                  (hkVector4f *)array.vfptr,
                  *(const int *)&array.m_memSizeAndFlags,
                  0,
                  v8) == v8->m_dimensions;
          v48 = v5 && hkgpConvexHullImpl::build((*v5)->m_data, points, numPoints, 0, v8) == v8->m_dimensions;
          if ( !v47 && v6 )
          {
            if ( *v6 )
              (*v6)->vfptr->__vecDelDtor((hkBaseObject *)&(*v6)->vfptr, 1u);
            *v6 = 0i64;
          }
          if ( !v48 && v5 )
          {
            if ( *v5 )
              (*v5)->vfptr->__vecDelDtor((hkBaseObject *)&(*v5)->vfptr, 1u);
            *v5 = 0i64;
          }
          v23 = 3;
          goto LABEL_94;
        }
        while ( 1 )
        {
          v27 = v26->m_scratch;
          if ( v27 == 0.0 )
          {
            if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            array.vfptr[*(signed int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)v26->m_source;
            v28 = numPoints;
            ++*(_DWORD *)&array.m_memSizeAndFlags;
            if ( numPoints == (v83 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
              v28 = numPoints;
            }
            v29 = v28;
          }
          else
          {
            if ( v27 > 0.0 )
            {
              if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
              array.vfptr[*(signed int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)v26->m_source;
              ++*(_DWORD *)&array.m_memSizeAndFlags;
              goto LABEL_53;
            }
            if ( numPoints == (v83 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
            v29 = numPoints;
          }
          points[v29] = v26->m_source;
          ++numPoints;
LABEL_53:
          v26 = v26->m_next;
          if ( !v26 )
            goto LABEL_54;
        }
      }
      if ( v12 <= v13 )
      {
        if ( v13 )
          return 1i64;
        return 0i64;
      }
      return 2i64;
    }
    return 0i64;
  }
  v49 = (__m128 *)v8->m_mesh.m_vertices.m_used;
  v50 = 0;
  v51 = 0;
  if ( !v49 )
    return 0i64;
  LODWORD(v52) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0);
  do
  {
    v53 = _mm_mul_ps(v49[1], v7->m_quad);
    v54 = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, v7->m_quad), 196);
    v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 78), v54);
    v56 = COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 177)) + v55.m128_f32[0];
    v49[2].m128_f32[3] = v56;
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v56)) >> 1) > v52 )
    {
      if ( v49[2].m128_f32[3] >= 0.0 )
        ++v51;
      else
        ++v50;
    }
    else
    {
      v49[2].m128_i32[3] = 0;
    }
    v49 = (__m128 *)v49->m128_u64[0];
  }
  while ( v49 );
  if ( !v50 )
  {
    if ( v51 )
      return 1i64;
    return 0i64;
  }
  if ( !v51 )
    return 2i64;
  v57 = (__m128 *)v8->m_mesh.m_vertices.m_used;
  v58 = 0;
  v59 = 0;
  array.vfptr = 0i64;
  *(_DWORD *)(&array.m_referenceCount + 1) = 2147483648;
  array.m_writer.m_pntr = 0i64;
  *(_DWORD *)&array.m_memSizeAndFlags = 0;
  v79 = 0;
  v80 = 2147483648;
  v60 = v57;
  if ( v57 )
  {
    v61 = (__m128 *)v57->m128_u64[0];
    if ( v57->m128_u64[0] )
    {
      do
      {
        v60 = v61;
        v61 = (__m128 *)v61->m128_u64[0];
      }
      while ( v61 );
    }
    for ( ; v57; v57 = (__m128 *)v57->m128_u64[0] )
    {
      v62 = v57[2].m128_f32[3];
      v63 = v57[1];
      if ( (float)(v60[2].m128_f32[3] * v62) < 0.0 )
      {
        v64 = _mm_sub_ps(v63, v60[1]);
        v87 = v60[2].m128_f32[3] / (float)(v60[2].m128_f32[3] - v62);
        v65 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0), v64), v60[1]);
        if ( v58 == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        }
        array.vfptr[v58] = (hkBaseObjectVtbl)v65;
        v66 = v79;
        ++*(_DWORD *)&array.m_memSizeAndFlags;
        if ( v79 == (v80 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array.m_writer, 16);
          v66 = v79;
        }
        *(__m128 *)&array.m_writer.m_pntr[v66].vfptr = v65;
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        v59 = v79++ + 1;
      }
      if ( v57[2].m128_f32[3] > 0.0 )
        goto LABEL_157;
      if ( v58 == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
      }
      array.vfptr[v58] = (hkBaseObjectVtbl)v63;
      v59 = v79;
      v58 = (*(_DWORD *)&array.m_memSizeAndFlags)++ + 1;
      if ( v57[2].m128_f32[3] >= 0.0 )
      {
LABEL_157:
        if ( v59 == (v80 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array.m_writer, 16);
          v59 = v79;
        }
        *(__m128 *)&array.m_writer.m_pntr[v59].vfptr = v63;
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        v59 = v79++ + 1;
      }
      v60 = v57;
    }
  }
  v67 = 1;
  if ( v5 )
  {
    v68 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v69 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v68[11] + 8i64))(v68[11], 40i64);
    if ( v69 )
      hkgpConvexHull::hkgpConvexHull(v69);
    else
      v70 = 0i64;
    *v5 = v70;
    v71 = v70->m_data;
    *(_DWORD *)&v71->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&v8->m_config.m_allowLowerDimensions.m_bool;
    v71->m_config.m_minCosAngle = v8->m_config.m_minCosAngle;
    *(_DWORD *)&v71->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&v8->m_config.m_setSourceIndices.m_bool;
    *(_DWORD *)&v71->m_config.m_internalInputs.m_bool = *(_DWORD *)&v8->m_config.m_internalInputs.m_bool;
    (*v5)->m_data->m_projectionPlane = v8->m_projectionPlane;
    if ( hkgpConvexHullImpl::build(
           (*v5)->m_data,
           (hkVector4f *)array.vfptr,
           *(const int *)&array.m_memSizeAndFlags,
           1,
           v8) != v8->m_dimensions )
    {
      if ( *v5 )
        (*v5)->vfptr->__vecDelDtor((hkBaseObject *)&(*v5)->vfptr, 1u);
      *v5 = 0i64;
    }
  }
  if ( v6 )
  {
    v72 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v73 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v72[11] + 8i64))(v72[11], 40i64);
    if ( v73 )
      hkgpConvexHull::hkgpConvexHull(v73);
    else
      v74 = 0i64;
    *v6 = v74;
    v75 = v74->m_data;
    *(_DWORD *)&v75->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&v8->m_config.m_allowLowerDimensions.m_bool;
    v75->m_config.m_minCosAngle = v8->m_config.m_minCosAngle;
    *(_DWORD *)&v75->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&v8->m_config.m_setSourceIndices.m_bool;
    *(_DWORD *)&v75->m_config.m_internalInputs.m_bool = *(_DWORD *)&v8->m_config.m_internalInputs.m_bool;
    (*v6)->m_data->m_projectionPlane = v8->m_projectionPlane;
    if ( hkgpConvexHullImpl::build((*v6)->m_data, (hkVector4f *)array.m_writer.m_pntr, v79, 1, v8) != v8->m_dimensions )
    {
      if ( *v6 )
        (*v6)->vfptr->__vecDelDtor((hkBaseObject *)&(*v6)->vfptr, 1u);
      *v6 = 0i64;
    }
  }
  v76 = &v83;
  do
  {
    v77 = *(v76 - 4);
    v76 -= 4;
    *(v76 - 1) = 0;
    if ( v77 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v76 - 3),
        16 * v77);
    --v67;
    *(_QWORD *)(v76 - 3) = 0i64;
    *v76 = 2147483648;
  }
  while ( v67 >= 0 );
  return 3i64;
}

// File Line: 2434
// RVA: 0xCB7960
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::getSpan(hkgpConvexHullImpl *this, hkSimdFloat32 *result, hkVector4f *axis, hkSimdFloat32 *minBound, hkSimdFloat32 *maxBound)
{
  hkSimdFloat32 *v5; // r12
  hkVector4f *v6; // r14
  hkSimdFloat32 *v7; // r15
  hkgpConvexHullImpl *v8; // rbx
  int v9; // edi
  hkVector4f *v10; // rdx
  int v11; // eax
  int v12; // er9
  hkgpConvexHullImpl::Vertex *v13; // rcx
  hkVector4f *v14; // rax
  int v15; // edi
  hkVector4f *v16; // rdx
  int v17; // eax
  int v18; // er9
  hkgpConvexHullImpl::Vertex *j; // rax
  hkVector4f *v20; // rcx
  hkSimdFloat32 *v21; // rax
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  hkSimdFloat32 *v26; // rax
  hkVector4f *array; // [rsp+30h] [rbp-40h]
  int i; // [rsp+38h] [rbp-38h]
  int v29; // [rsp+3Ch] [rbp-34h]
  hkVector4f direction; // [rsp+40h] [rbp-30h]
  hkVector4f vertexOut; // [rsp+50h] [rbp-20h]
  hkVector4f v32; // [rsp+60h] [rbp-10h]
  hkResult resulta; // [rsp+A0h] [rbp+30h]

  v5 = minBound;
  v6 = axis;
  v7 = result;
  v8 = this;
  direction.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), axis->m_quad);
  if ( !this->m_supportCache.m_size )
  {
    v9 = this->m_mesh.m_vertices.m_numUsed;
    v10 = 0i64;
    v11 = 0;
    array = 0i64;
    i = 0;
    v29 = 2147483648;
    if ( v9 > 0 )
    {
      v12 = v9;
      if ( v9 < 0 )
        v12 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 16);
      v11 = i;
      v10 = array;
    }
    v13 = v8->m_mesh.m_vertices.m_used;
    for ( i = v9 + v11; v13; v13 = v13->m_next )
    {
      v14 = v10;
      ++v10;
      *v14 = v13->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(
      (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array,
      &v8->m_supportCache);
    i = 0;
    if ( v29 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v29);
  }
  hkGeometryProcessing::getSupportingVertex(
    (hkArrayBase<hkFourTransposedPointsf> *)&v8->m_supportCache.m_data,
    v6,
    &vertexOut);
  if ( !v8->m_supportCache.m_size )
  {
    v15 = v8->m_mesh.m_vertices.m_numUsed;
    v16 = 0i64;
    v17 = 0;
    array = 0i64;
    i = 0;
    v29 = 2147483648;
    if ( v15 > 0 )
    {
      v18 = v15;
      if ( v15 < 0 )
        v18 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 16);
      v17 = i;
      v16 = array;
    }
    i = v15 + v17;
    for ( j = v8->m_mesh.m_vertices.m_used; j; j = j->m_next )
    {
      v20 = v16;
      ++v16;
      *v20 = j->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(
      (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array,
      &v8->m_supportCache);
    i = 0;
    if ( v29 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v29);
  }
  hkGeometryProcessing::getSupportingVertex(
    (hkArrayBase<hkFourTransposedPointsf> *)&v8->m_supportCache.m_data,
    &direction,
    &v32);
  v21 = maxBound;
  v22 = _mm_mul_ps(v6->m_quad, vertexOut.m_quad);
  maxBound->m_real = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                       _mm_shuffle_ps(v22, v22, 170));
  v23 = _mm_mul_ps(v6->m_quad, v32.m_quad);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  *v5 = (hkSimdFloat32)v24;
  v25 = v21->m_real;
  v26 = v7;
  v7->m_real = _mm_sub_ps(v25, v24);
  return v26;
}

// File Line: 2446
// RVA: 0xCB7000
void __fastcall hkgpConvexHullImpl::getOrientedBoundingBox(hkgpConvexHullImpl *this, hkVector4f *halfExtents, hkTransformf *worldTransform)
{
  hkTransformf *v3; // rbp
  hkVector4f *v4; // r14
  hkgpConvexHullImpl *v5; // rbx
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  float v8; // xmm7_4
  int v9; // edi
  float i; // xmm8_4
  signed __int64 v11; // rsi
  __m128 v12; // xmm6
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  __m128 v17; // xmm2
  hkSimdFloat32 result; // [rsp+30h] [rbp-2D8h]
  hkSimdFloat32 minBound; // [rsp+50h] [rbp-2B8h]
  hkSimdFloat32 maxBound; // [rsp+60h] [rbp-2A8h]
  hkSimdFloat32 v21; // [rsp+70h] [rbp-298h]
  hkSimdFloat32 v22; // [rsp+80h] [rbp-288h]
  hkTransformf v23; // [rsp+90h] [rbp-278h]
  char buf; // [rsp+D0h] [rbp-238h]

  v3 = worldTransform;
  v4 = halfExtents;
  v5 = this;
  if ( this->m_dimensions >= 3 )
  {
    if ( !this->m_hasIndexing )
    {
      hkErrStream::hkErrStream((hkErrStream *)&result, &buf, 512);
      v6 = hkOstream::operator<<((hkOstream *)&result, "No index available (");
      v7 = hkOstream::operator<<(v6, v5->m_uid, (int)v6);
      hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
      if ( (unsigned int)hkError::messageError(
                           2046417030,
                           &buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           358) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&result);
    }
    v8 = *(float *)&xmmword_141A712A0;
    v9 = 0;
    for ( i = *(float *)&xmmword_141A712A0; v9 < v5->m_planes.m_size; ++v9 )
    {
      v11 = v9;
      hkgpConvexHullImpl::getSpan(v5, &v22, &v5->m_planes.m_data[v11], &minBound, &maxBound);
      v12 = v22.m_real;
      if ( v22.m_real.m128_f32[0] < v8 )
      {
        hkgpConvexHullImpl::getOrientedRectangle(v5, &v21, &v5->m_planes.m_data[v11], (hkVector4f *)&result, &v23);
        if ( (float)((float)(maxBound.m_real.m128_f32[0] - minBound.m_real.m128_f32[0]) * v21.m_real.m128_f32[0]) < i )
        {
          i = (float)(maxBound.m_real.m128_f32[0] - minBound.m_real.m128_f32[0]) * v21.m_real.m128_f32[0];
          v8 = v12.m128_f32[0];
          v13.m_quad = (__m128)v23.m_rotation.m_col0;
          v4->m_quad = _mm_shuffle_ps(result.m_real, _mm_unpackhi_ps(result.m_real, v12), 180);
          v14.m_quad = (__m128)v23.m_rotation.m_col1;
          v3->m_rotation.m_col0 = (hkVector4f)v13.m_quad;
          v15.m_quad = (__m128)v23.m_rotation.m_col2;
          v3->m_rotation.m_col1 = (hkVector4f)v14.m_quad;
          v16.m_quad = (__m128)v23.m_translation;
          v3->m_rotation.m_col2 = (hkVector4f)v15.m_quad;
          v3->m_translation = (hkVector4f)v16.m_quad;
        }
      }
    }
    v17 = _mm_mul_ps(_mm_shuffle_ps(v4->m_quad, v4->m_quad, 170), (__m128)xmmword_141A711B0);
    v4->m_quad = _mm_shuffle_ps(v4->m_quad, _mm_unpackhi_ps(v4->m_quad, v17), 180);
    v3->m_translation.m_quad = _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps((__m128)0i64, v17), v3->m_rotation.m_col2.m_quad),
                                 v3->m_translation.m_quad);
  }
  else
  {
    hkgpConvexHullImpl::getOrientedRectangle(this, &result, &this->m_projectionPlane, halfExtents, worldTransform);
  }
}

// File Line: 2484
// RVA: 0xCB7240
__m128i *__fastcall hkgpConvexHullImpl::getOrientedRectangle(hkgpConvexHullImpl *this, hkSimdFloat32 *result, hkVector4f *projectionPlane, hkVector4f *halfExtents, hkTransformf *worldTransform)
{
  hkVector4f *v5; // r12
  hkVector4f *v6; // r14
  __m128i *v7; // r15
  hkgpConvexHullImpl *v8; // rdi
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  __m128 v11; // xmm9
  int v12; // eax
  __m128 v13; // xmm6
  __m128 v14; // xmm13
  __m128 v15; // xmm14
  __m128 v16; // xmm10
  __m128 v17; // xmm12
  __m128 v18; // xmm8
  hkgpConvexHullImpl::Triangle *v19; // r10
  hkgpConvexHullImpl::Vertex *v20; // rax
  signed int v21; // edx
  int *v22; // rcx
  int v23; // er8
  hkgpConvexHullImpl::Triangle *v24; // rcx
  hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator *v25; // rax
  signed __int64 v26; // rdx
  signed __int64 v27; // rax
  hkVector4f *v28; // rcx
  __m128 v29; // xmm8
  signed __int64 v30; // rax
  signed __int64 v31; // rdx
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm15
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // xmm5
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm6
  __m128 v44; // xmm6
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v50; // xmm0
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator *v56; // rax
  int v57; // ebx
  __int64 v58; // rsi
  __m128 v59; // xmm0
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128 v65; // xmm5
  __m128 v66; // xmm2
  __m128 v67; // xmm5
  __m128 v68; // xmm3
  __m128 v69; // xmm4
  __m128 v70; // xmm10
  __m128i *v71; // rax
  hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator v72; // [rsp+30h] [rbp-B8h]
  hkVector4f v73; // [rsp+40h] [rbp-A8h]
  hkVector4f axis; // [rsp+50h] [rbp-98h]
  __m128 v75; // [rsp+60h] [rbp-88h]
  __m128 v76; // [rsp+70h] [rbp-78h]
  hkSimdFloat32 resulta; // [rsp+88h] [rbp-60h]
  hkSimdFloat32 v78; // [rsp+98h] [rbp-50h]
  hkSimdFloat32 v79; // [rsp+A8h] [rbp-40h]
  hkSimdFloat32 minBound; // [rsp+B8h] [rbp-30h]
  hkSimdFloat32 maxBound; // [rsp+C8h] [rbp-20h]
  char buf; // [rsp+D8h] [rbp-10h]
  __m128 *v83; // [rsp+3B8h] [rbp+2D0h]

  v5 = halfExtents;
  v6 = projectionPlane;
  v7 = (__m128i *)result;
  v8 = this;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v75.m128_u16[4], &buf, 512);
    v9 = hkOstream::operator<<((hkOstream *)&v75.m128_u16[4], "No index available (");
    v10 = hkOstream::operator<<(v9, v8->m_uid, (int)v9);
    hkOstream::operator<<(v10, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v75.m128_u16[4]);
  }
  v11 = (__m128)xmmword_141A712A0;
  v12 = v8->m_dimensions;
  v13 = (__m128)xmmword_141A711B0;
  v14 = 0i64;
  v15 = 0i64;
  v16 = (__m128)xmmword_141A712A0;
  v17 = (__m128)xmmword_141A712A0;
  v18 = (__m128)xmmword_141A712A0;
  v75 = (__m128)xmmword_141A712A0;
  _mm_store_si128(v7, (__m128i)xmmword_141A712A0);
  v76 = (__m128)xmmword_141A711B0;
  if ( v12 == 3 )
  {
    v72.m_edge.m_triangle = v8->m_mesh.m_triangles.m_used;
    v19 = v72.m_edge.m_triangle;
    v72.m_edge.m_index = 0;
    _mm_store_si128((__m128i *)&v72, (__m128i)v72);
    if ( v19 )
    {
      v20 = v19->m_vertices[0];
      v21 = 0;
      v22 = v20->m_x;
      do
      {
        v23 = *(int *)((char *)v22 + (char *)v19->m_vertices[1] - (char *)v20);
        if ( *v22 < v23 )
          break;
        if ( *v22 > v23 )
        {
          if ( v19->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
            hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v72);
          break;
        }
        ++v21;
        ++v22;
      }
      while ( v21 < 3 );
    }
    v24 = v72.m_edge.m_triangle;
    v25 = &v72;
    if ( !v72.m_edge.m_triangle )
      v25 = 0i64;
    if ( v25 )
    {
      do
      {
        v26 = v24->m_plane.m_index;
        v27 = *(signed int *)((v24->m_links[v72.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) + 88);
        if ( (_DWORD)v26 != (_DWORD)v27 )
        {
          v28 = v8->m_planes.m_data;
          v29 = v6->m_quad;
          v30 = v27;
          v31 = v26;
          v32 = _mm_mul_ps(v28[v30].m_quad, v6->m_quad);
          v33 = _mm_mul_ps(v28[v31].m_quad, v6->m_quad);
          if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170)))
                     * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170)))) > 0.0 )
            goto LABEL_37;
          v34 = _mm_shuffle_ps(v29, v29, 201);
          v35 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v28[v30].m_quad, v28[v30].m_quad, 201), v28[v31].m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v28[v31].m_quad, v28[v31].m_quad, 201), v28[v30].m_quad));
          v36 = _mm_shuffle_ps(v35, v35, 201);
          v37 = _mm_sub_ps(_mm_mul_ps(v36, v29), _mm_mul_ps(v36, v34));
          v38 = _mm_shuffle_ps(v37, v37, 201);
          v39 = _mm_mul_ps(v38, v38);
          v40 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170));
          v41 = _mm_rsqrt_ps(v40);
          v42 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v40), (__m128)0i64);
          v43 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v40, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                          _mm_mul_ps(v41, *(__m128 *)_xmm))),
                      v38),
                    v42),
                  _mm_andnot_ps(v42, v38));
          axis.m_quad = v43;
          if ( !_mm_movemask_ps(v42) )
            goto LABEL_37;
          v44 = _mm_sub_ps(_mm_mul_ps(v43, v34), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v29));
          v45 = _mm_shuffle_ps(v44, v44, 201);
          v46 = _mm_mul_ps(v45, v45);
          v47 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                  _mm_shuffle_ps(v46, v46, 170));
          v48 = _mm_rsqrt_ps(v47);
          v49 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v47), (__m128)0i64);
          v73.m_quad = _mm_or_ps(
                         _mm_and_ps(
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmpleps(v47, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                 _mm_mul_ps(v48, *(__m128 *)_xmm))),
                             v45),
                           v49),
                         _mm_andnot_ps(v49, v45));
          if ( _mm_movemask_ps(v49) )
          {
            hkgpConvexHullImpl::getSpan(v8, &resulta, &axis, &minBound, &maxBound);
            hkgpConvexHullImpl::getSpan(v8, (hkSimdFloat32 *)&v75.m128_u16[4], &v73, &v78, &v79);
            v50 = _mm_mul_ps(resulta.m_real, *(__m128 *)((char *)&v75 + 8));
            v51 = _mm_cmpltps(v50, *(__m128 *)v7);
            v52 = _mm_and_ps(axis.m_quad, v51);
            v53 = _mm_and_ps(v51, v50);
            v54 = _mm_andnot_ps(v51, *(__m128 *)v7);
            v55 = _mm_and_ps(resulta.m_real, v51);
            v18 = _mm_or_ps(_mm_andnot_ps(v51, v75), _mm_and_ps(*(__m128 *)((char *)&v75 + 8), v51));
            v75 = v18;
            *(__m128 *)v7 = _mm_or_ps(v53, v54);
            v14 = _mm_or_ps(_mm_andnot_ps(v51, v14), v52);
            v15 = _mm_or_ps(_mm_andnot_ps(v51, v15), _mm_and_ps(v73.m_quad, v51));
            v17 = _mm_or_ps(_mm_andnot_ps(v51, v17), v55);
            v11 = _mm_or_ps(
                    _mm_and_ps(_mm_mul_ps(_mm_add_ps(maxBound.m_real, minBound.m_real), v76), v51),
                    _mm_andnot_ps(v51, v11));
            v16 = _mm_or_ps(
                    _mm_and_ps(_mm_mul_ps(_mm_add_ps(v79.m_real, v78.m_real), v76), v51),
                    _mm_andnot_ps(v51, v16));
          }
          else
          {
LABEL_37:
            v18 = v75;
          }
        }
        hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v72);
        v24 = v72.m_edge.m_triangle;
        v56 = &v72;
        if ( !v72.m_edge.m_triangle )
          v56 = 0i64;
      }
      while ( v56 );
LABEL_33:
      v13 = v76;
      goto LABEL_34;
    }
  }
  else if ( v12 == 2 )
  {
    v57 = 0;
    if ( v8->m_planes.m_size > 0 )
    {
      v58 = 0i64;
      do
      {
        v59 = v6->m_quad;
        v73.m_quad = (__m128)v8->m_planes.m_data[v58];
        v60 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v73.m_quad, v73.m_quad, 201), v59),
                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v73.m_quad));
        v61 = _mm_shuffle_ps(v60, v60, 201);
        v62 = _mm_mul_ps(v61, v61);
        v63 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                _mm_shuffle_ps(v62, v62, 170));
        v64 = _mm_rsqrt_ps(v63);
        v65 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v63), (__m128)0i64);
        axis.m_quad = _mm_or_ps(
                        _mm_and_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v63, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                                _mm_mul_ps(v64, *(__m128 *)_xmm))),
                            v61),
                          v65),
                        _mm_andnot_ps(v65, v61));
        if ( _mm_movemask_ps(v65) )
        {
          hkgpConvexHullImpl::getSpan(v8, (hkSimdFloat32 *)&v75.m128_u16[4], &v73, &v78, &v79);
          hkgpConvexHullImpl::getSpan(v8, &resulta, &axis, &minBound, &maxBound);
          v66 = _mm_mul_ps(*(__m128 *)((char *)&v75 + 8), resulta.m_real);
          v67 = _mm_cmpltps(v66, *(__m128 *)v7);
          v68 = _mm_and_ps(*(__m128 *)((char *)&v75 + 8), v67);
          v69 = _mm_and_ps(resulta.m_real, v67);
          *(__m128 *)v7 = _mm_or_ps(_mm_andnot_ps(v67, *(__m128 *)v7), _mm_and_ps(v67, v66));
          v14 = _mm_or_ps(_mm_andnot_ps(v67, v14), _mm_and_ps(v73.m_quad, v67));
          v15 = _mm_or_ps(_mm_andnot_ps(v67, v15), _mm_and_ps(axis.m_quad, v67));
          v17 = _mm_or_ps(_mm_andnot_ps(v67, v17), v68);
          v18 = _mm_or_ps(_mm_andnot_ps(v67, v18), v69);
          v11 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_add_ps(v79.m_real, v78.m_real), v76), v67), _mm_andnot_ps(v67, v11));
          v16 = _mm_or_ps(
                  _mm_and_ps(_mm_mul_ps(_mm_add_ps(maxBound.m_real, minBound.m_real), v76), v67),
                  _mm_andnot_ps(v67, v16));
        }
        ++v57;
        ++v58;
      }
      while ( v57 < v8->m_planes.m_size );
      goto LABEL_33;
    }
  }
LABEL_34:
  v70 = _mm_add_ps(_mm_mul_ps(v16, v15), _mm_mul_ps(v11, v14));
  v83[3] = v70;
  v83[3] = _mm_sub_ps(v70, _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 255), v6->m_quad));
  *v83 = v14;
  v83[1] = v15;
  v83[2] = v6->m_quad;
  v71 = v7;
  v5->m_quad = _mm_mul_ps(
                 _mm_movelh_ps(_mm_unpacklo_ps(v17, v18), _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad)),
                 v13);
  return v71;
}

