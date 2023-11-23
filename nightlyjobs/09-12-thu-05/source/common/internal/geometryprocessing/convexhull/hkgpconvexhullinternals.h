// File Line: 233
// RVA: 0xCB4120
void __fastcall hkgpConvexHullImpl::hkgpConvexHullImpl(hkgpConvexHullImpl *this)
{
  hkgpConvexHull::BuildConfig::BuildConfig(&this->m_config);
  *(_DWORD *)&this->m_mesh.m_memSizeAndFlags = 0x1FFFF;
  this->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::`vftable;
  this->m_mesh.m_vertices.m_allocator.m_firstPool = 0i64;
  this->m_mesh.m_vertices.m_used = 0i64;
  this->m_mesh.m_vertices.m_numUsed = 0;
  this->m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
  this->m_mesh.m_triangles.m_used = 0i64;
  this->m_mesh.m_triangles.m_numUsed = 0;
  this->m_pendings.m_data = 0i64;
  this->m_pendings.m_size = 0;
  this->m_pendings.m_capacityAndFlags = 0x80000000;
  this->m_planes.m_data = 0i64;
  this->m_planes.m_size = 0;
  this->m_planes.m_capacityAndFlags = 0x80000000;
  this->m_supportCache.m_data = 0i64;
  this->m_supportCache.m_size = 0;
  this->m_supportCache.m_capacityAndFlags = 0x80000000;
  this->m_uid = _InterlockedExchangeAdd((volatile signed __int32 *)&hkgpConvexHullImpl::g_uidGenerator, 1u);
  hkgpConvexHullImpl::reset(this, 0);
}

// File Line: 241
// RVA: 0xCB4220
void __fastcall hkgpConvexHullImpl::~hkgpConvexHullImpl(hkgpConvexHullImpl *this)
{
  int m_capacityAndFlags; // eax
  int v3; // r8d
  int v4; // r8d

  hkgpConvexHullImpl::reset(this, 0);
  m_capacityAndFlags = this->m_supportCache.m_capacityAndFlags;
  this->m_supportCache.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_supportCache.m_data,
      48 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_supportCache.m_data = 0i64;
  this->m_supportCache.m_capacityAndFlags = 0x80000000;
  v3 = this->m_planes.m_capacityAndFlags;
  this->m_planes.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_planes.m_data, 16 * v3);
  this->m_planes.m_data = 0i64;
  this->m_planes.m_capacityAndFlags = 0x80000000;
  v4 = this->m_pendings.m_capacityAndFlags;
  this->m_pendings.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pendings.m_data,
      v4 << 6);
  this->m_pendings.m_data = 0i64;
  this->m_pendings.m_capacityAndFlags = 0x80000000;
  this->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::`vftable;
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *)&this->m_mesh.m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&this->m_mesh.m_triangles);
  hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::reset(&this->m_mesh.m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>(&this->m_mesh.m_vertices.m_allocator);
  this->m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 247
// RVA: 0xCB8870
void __fastcall hkgpConvexHullImpl::reset(hkgpConvexHullImpl *this, bool keepPlane)
{
  __m128 v4; // xmm2

  this->m_mesh.vfptr[1].__first_virtual_table_function__(&this->m_mesh);
  this->m_planes.m_size = 0;
  this->m_pendings.m_size = 0;
  this->m_supportCache.m_size = 0;
  this->m_centroids[0] = 0i64;
  this->m_centroids[1] = 0i64;
  this->m_centroids[0].m_quad = _mm_shuffle_ps(
                                  (__m128)0i64,
                                  _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712A0),
                                  196);
  this->m_centroids[1].m_quad = _mm_shuffle_ps(
                                  (__m128)0i64,
                                  _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712A0),
                                  196);
  this->m_boundingBoxes[0].m_min = (hkVector4f)xmmword_141A712A0;
  v4 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  this->m_boundingBoxes[0].m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v4);
  this->m_boundingBoxes[1].m_min = (hkVector4f)xmmword_141A712A0;
  this->m_boundingBoxes[1].m_max.m_quad = _mm_xor_ps(v4, (__m128)xmmword_141A712A0);
  *(_WORD *)&this->m_hasMassProperties = 0;
  this->m_hasIndexing = 0;
  this->m_pid = 0;
  this->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_localTransform.m_translation = 0i64;
  this->m_inertia = 0i64;
  this->m_inertiaMatrix.m_col0 = (hkVector4f)transform.m_quad;
  this->m_inertiaMatrix.m_col1 = (hkVector4f)direction.m_quad;
  this->m_inertiaMatrix.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_projectionAxis = 0i64;
  this->m_volume = 0i64;
  this->m_dimensions = -1;
  this->m_surface = 0i64;
  this->m_scale = 0i64;
  this->m_scaleInv = 0i64;
  this->m_origin = 0i64;
  if ( !keepPlane )
    this->m_projectionPlane = 0i64;
}

// File Line: 280
// RVA: 0xCB48F0
hkgpConvexHullImpl *__fastcall hkgpConvexHullImpl::clone(hkgpConvexHullImpl *this)
{
  _QWORD **Value; // rax
  hkgpConvexHullImpl *v3; // rax
  __int64 v4; // rax
  __int64 v5; // r12
  bool m_hasIndexing; // al
  int m_size; // edi
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  __int64 v12; // rdx
  _DWORD *v13; // rcx
  int v14; // r9d
  __int64 v15; // r8
  hkgpConvexHullImpl::Vertex *m_data; // rdx
  __int64 v17; // rcx
  int v18; // edi
  int v19; // eax
  int v20; // eax
  int v21; // r9d
  int v22; // r8d
  __int64 v23; // rdx
  int m_numUsed; // r8d
  hkgpConvexHullImpl::Vertex *m_used; // rbx
  hkgpConvexHullImpl::Vertex *i; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  unsigned __int64 m_free; // r9
  __int64 v29; // rax
  int v30; // r8d
  hkgpConvexHullImpl::Triangle *m_prev; // r14
  hkgpConvexHullImpl::Triangle *j; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v33; // rax
  __int64 v34; // rsi
  unsigned __int64 *v35; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v36; // rdi
  unsigned __int64 v37; // rax
  int k; // ebx
  unsigned __int64 v39; // rax
  unsigned int v40; // ebp
  unsigned __int64 v41; // rsi
  AMD_HD3D v43[2]; // [rsp+30h] [rbp-48h] BYREF
  hkResult result; // [rsp+80h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHullImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 496i64);
  if ( v3 )
  {
    hkgpConvexHullImpl::hkgpConvexHullImpl(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  *(_DWORD *)v5 = *(_DWORD *)&this->m_config.m_allowLowerDimensions.m_bool;
  *(float *)(v5 + 4) = this->m_config.m_minCosAngle;
  *(_DWORD *)(v5 + 8) = *(_DWORD *)&this->m_config.m_setSourceIndices.m_bool;
  *(_DWORD *)(v5 + 12) = *(_DWORD *)&this->m_config.m_internalInputs.m_bool;
  *(hkVector4f *)(v5 + 240) = this->m_projectionAxis;
  *(hkVector4f *)(v5 + 256) = this->m_projectionPlane;
  *(hkVector4f *)(v5 + 272) = this->m_origin;
  *(hkVector4f *)(v5 + 288) = this->m_scale;
  *(hkVector4f *)(v5 + 304) = this->m_scaleInv;
  *(hkVector4f *)(v5 + 320) = this->m_localTransform.m_rotation.m_col0;
  *(hkVector4f *)(v5 + 336) = this->m_localTransform.m_rotation.m_col1;
  *(hkVector4f *)(v5 + 352) = this->m_localTransform.m_rotation.m_col2;
  *(hkVector4f *)(v5 + 368) = this->m_localTransform.m_translation;
  *(hkVector4f *)(v5 + 384) = this->m_inertia;
  *(hkSimdFloat32 *)(v5 + 448) = this->m_volume;
  *(hkSimdFloat32 *)(v5 + 464) = this->m_surface;
  *(_DWORD *)(v5 + 480) = this->m_dimensions;
  *(_DWORD *)(v5 + 484) = this->m_pid;
  *(_BYTE *)(v5 + 492) = this->m_hasMassProperties;
  m_hasIndexing = this->m_hasIndexing;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_BYTE *)(v5 + 494) = m_hasIndexing;
  m_size = this->m_pendings.m_size;
  v8 = *(_DWORD *)(v5 + 100) & 0x3FFFFFFF;
  if ( v8 < m_size )
  {
    v9 = 2 * v8;
    v10 = this->m_pendings.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v5 + 88), v10, 64);
  }
  v11 = m_size - *(_DWORD *)(v5 + 96);
  v12 = v11;
  if ( v11 > 0 )
  {
    v13 = (_DWORD *)(*(_QWORD *)(v5 + 88) + ((__int64)*(int *)(v5 + 96) << 6) + 52);
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
  *(_DWORD *)(v5 + 96) = m_size;
  v14 = 0;
  if ( this->m_pendings.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      m_data = this->m_pendings.m_data;
      v17 = *(_QWORD *)(v5 + 88);
      ++v14;
      ++v15;
      *(hkVector4f *)(v15 * 64 + v17 - 48) = m_data[v15 - 1].m_source;
      *(_DWORD *)(v15 * 64 + v17 - 32) = m_data[v15 - 1].m_x[0];
      *(_DWORD *)(v15 * 64 + v17 - 28) = m_data[v15 - 1].m_x[1];
      *(_DWORD *)(v15 * 64 + v17 - 24) = m_data[v15 - 1].m_x[2];
      *(float *)(v15 * 64 + v17 - 20) = m_data[v15 - 1].m_scratch;
      *(_DWORD *)(v15 * 64 + v17 - 16) = m_data[v15 - 1].m_refs;
      *(_DWORD *)(v15 * 64 + v17 - 12) = m_data[v15 - 1].m_index;
    }
    while ( v14 < this->m_pendings.m_size );
  }
  v18 = this->m_planes.m_size;
  v19 = *(_DWORD *)(v5 + 116) & 0x3FFFFFFF;
  if ( v19 < v18 )
  {
    v20 = 2 * v19;
    v21 = this->m_planes.m_size;
    if ( v18 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v5 + 104), v21, 16);
  }
  *(_DWORD *)(v5 + 112) = v18;
  v22 = 0;
  if ( this->m_planes.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      ++v22;
      ++v23;
      *(hkVector4f *)(v23 * 16 + *(_QWORD *)(v5 + 104) - 16) = this->m_planes.m_data[v23 - 1];
    }
    while ( v22 < this->m_planes.m_size );
  }
  m_numUsed = this->m_mesh.m_vertices.m_numUsed;
  v43[0].mStereo = 0i64;
  v43[0].mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  if ( m_numUsed )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v43[0].mStereo,
      &hkContainerHeapAllocator::s_alloc,
      m_numUsed);
    m_used = this->m_mesh.m_vertices.m_used;
    if ( m_used )
    {
      for ( i = m_used->m_next; i; i = i->m_next )
        m_used = i;
      for ( ; m_used; m_used = m_used->m_prev )
      {
        NewPool = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool **)(v5 + 40);
        if ( !NewPool || !NewPool->m_free )
          NewPool = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> *)(v5 + 40));
        if ( NewPool )
        {
          m_free = (unsigned __int64)NewPool->m_free;
          NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)m_free;
          *(_QWORD *)(m_free + 64) = NewPool;
          ++NewPool->m_used;
          *(hkVector4f *)(m_free + 16) = m_used->m_source;
          *(_DWORD *)(m_free + 32) = m_used->m_x[0];
          *(_DWORD *)(m_free + 36) = m_used->m_x[1];
          *(_DWORD *)(m_free + 40) = m_used->m_x[2];
          *(float *)(m_free + 44) = m_used->m_scratch;
          *(_DWORD *)(m_free + 48) = m_used->m_refs;
          *(_DWORD *)(m_free + 52) = m_used->m_index;
          *(_QWORD *)(m_free + 8) = 0i64;
          *(_QWORD *)m_free = *(_QWORD *)(v5 + 48);
          v29 = *(_QWORD *)(v5 + 48);
          if ( v29 )
            *(_QWORD *)(v29 + 8) = m_free;
          ++*(_DWORD *)(v5 + 56);
          *(_QWORD *)(v5 + 48) = m_free;
        }
        else
        {
          m_free = 0i64;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v43[0].mStereo,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)m_used,
          m_free);
      }
    }
  }
  v30 = this->m_mesh.m_triangles.m_numUsed;
  if ( v30 )
  {
    *(_QWORD *)&v43[0].mEnableStereo = 0i64;
    v43[0].mWidth = 0;
    v43[0].mHeight = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v43,
      &hkContainerHeapAllocator::s_alloc,
      v30);
    m_prev = this->m_mesh.m_triangles.m_used;
    if ( m_prev )
    {
      for ( j = m_prev->m_next; j; j = j->m_next )
        m_prev = j;
      for ( ; m_prev; m_prev = m_prev->m_prev )
      {
        v33 = hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Triangle,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>>::allocate(
                (hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Triangle,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator> > *)(v5 + 64),
                m_prev);
        v34 = 3i64;
        v35 = (unsigned __int64 *)&v33->m_items[0].m_data[16];
        v36 = v33;
        do
        {
          v37 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v43[0].mStereo,
                  *v35++,
                  0i64);
          *(v35 - 1) = v37;
          --v34;
        }
        while ( v34 );
        for ( k = 0; k < 3; ++k )
        {
          v39 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v43,
                  *(_QWORD *)&v36->m_items[0].m_data[8 * k + 40],
                  0i64);
          v40 = v39 & 3;
          v41 = v39 & 0xFFFFFFFFFFFFFFFCui64;
          if ( (v39 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v43,
              &result,
              *(_QWORD *)&v36->m_items[0].m_data[8 * k + 40]);
            *(_QWORD *)&v36->m_items[0].m_data[8 * k + 40] = v41 + v40;
            *(_QWORD *)(v41 + 8i64 * (int)v40 + 40) = (char *)v36 + (unsigned int)k;
          }
          else
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v43,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)m_prev + (unsigned int)k,
              (unsigned __int64)v36 + (unsigned int)k);
          }
        }
      }
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v43,
      &hkContainerHeapAllocator::s_alloc);
    _(v43);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v43[0].mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v43[0].mStereo);
  return (hkgpConvexHullImpl *)v5;
}

// File Line: 553
// RVA: 0xCB8300
void __fastcall hkgpConvexHullImpl::rebuildDomainParameters(
        hkgpConvexHullImpl *this,
        hkVector4f *points,
        int numPoints)
{
  __m128 m_quad; // xmm7
  __m128 v5; // xmm6
  hkVector4f *v6; // rdx
  __int64 v7; // r8
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  hkVector4f v10; // xmm2
  __m128 v11; // xmm1
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm1
  __m128 v14; // xmm0
  hkVector4f v15; // xmm3
  hkErrStream v16; // [rsp+20h] [rbp-248h] BYREF
  char buf[512]; // [rsp+40h] [rbp-228h] BYREF

  if ( numPoints )
  {
    m_quad = points->m_quad;
    v5 = points->m_quad;
    if ( numPoints > 1 )
    {
      v6 = points + 1;
      v7 = (unsigned int)(numPoints - 1);
      do
      {
        m_quad = _mm_min_ps(m_quad, v6->m_quad);
        v5 = _mm_max_ps(v5, v6->m_quad);
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    if ( (((unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps((__m128)xmmword_141A712A0, v5)) | (unsigned __int8)_mm_movemask_ps(_mm_cmplt_ps(m_quad, _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0)))) & 7) != 0 )
    {
      hkErrStream::hkErrStream(&v16, buf, 512);
      hkOstream::operator<<(&v16, "Input domain out of range");
      if ( (unsigned int)hkError::messageError(
                           0x405A2174u,
                           buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           572) )
        __debugbreak();
      hkOstream::~hkOstream(&v16);
    }
    v8 = _mm_mul_ps(_mm_max_ps(_mm_sub_ps(v5, m_quad), (__m128)_xmm), (__m128)xmmword_141A711B0);
    v9 = _mm_rcp_ps(v8);
    v10.m_quad = _mm_add_ps(v8, m_quad);
    v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v9)), v9);
    this->m_origin = (hkVector4f)v10.m_quad;
    v12.m_quad = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, query.m_quad), 196);
    this->m_scale = (hkVector4f)v12.m_quad;
    this->m_origin = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v10.m_quad, 4), 4);
    this->m_scale = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v12.m_quad, 4), 4);
    v13.m_quad = _mm_mul_ps(
                   _mm_shuffle_ps((__m128)LODWORD(FLOAT_8191_0), (__m128)LODWORD(FLOAT_8191_0), 0),
                   this->m_scale.m_quad);
    v14 = _mm_rcp_ps(v13.m_quad);
    this->m_scale = (hkVector4f)v13.m_quad;
    v15.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13.m_quad, v14)), v14);
    this->m_scaleInv = (hkVector4f)v15.m_quad;
    this->m_scaleInv.m_quad = _mm_shuffle_ps(v15.m_quad, _mm_unpackhi_ps(v15.m_quad, query.m_quad), 196);
  }
}

// File Line: 601
// RVA: 0xCC3FE0
void __fastcall hkgpConvexHullImpl::computeProjectionPlane(
        hkgpConvexHullImpl *this,
        hkVector4f *points,
        int numPoints,
        hkVector4f *planeOut)
{
  int v4; // edi
  __int64 v6; // rbx
  float v7; // xmm5_4
  float v8; // xmm7_4
  int v9; // r10d
  __int64 v10; // r11
  __m128 i; // xmm8
  int v12; // ecx
  __int64 v13; // rdx
  __m128 v14; // xmm4
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  float v20; // xmm2_4
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm2

  v4 = 0;
  v6 = 0i64;
  *planeOut = 0i64;
  v7 = 0.0;
  for ( LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0).m128_u32[0];
        v6 < numPoints;
        ++v4 )
  {
    v9 = v4 + 1;
    v10 = v4 + 1;
    for ( i = points[v6].m_quad; v9 < numPoints; ++v10 )
    {
      v12 = v9 + 1;
      v13 = v10 + 1;
      v14 = _mm_sub_ps(points[v10].m_quad, i);
      if ( v9 + 1 < numPoints )
      {
        v15 = _mm_shuffle_ps(v14, v14, 201);
        do
        {
          v16 = _mm_sub_ps(points[v13].m_quad, i);
          v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v14), _mm_mul_ps(v15, v16));
          v18 = _mm_shuffle_ps(v17, v17, 201);
          v19 = _mm_mul_ps(v18, v18);
          v20 = (float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
              + _mm_shuffle_ps(v19, v19, 170).m128_f32[0];
          if ( v20 > v7 )
          {
            *planeOut = (hkVector4f)v18;
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
  }
  v21 = _mm_mul_ps(planeOut->m_quad, planeOut->m_quad);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v22), (__m128)0i64);
  planeOut->m_quad = _mm_or_ps(
                       _mm_and_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v22, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                               _mm_mul_ps(*(__m128 *)_xmm, v23))),
                           planeOut->m_quad),
                         v24),
                       _mm_andnot_ps(v24, planeOut->m_quad));
  if ( !_mm_movemask_ps(v24) )
    *planeOut = (hkVector4f)transform.m_quad;
  v25 = _mm_mul_ps(planeOut->m_quad, points->m_quad);
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
  int m_size; // esi
  char v2; // di
  hkgpConvexHullImpl *v3; // r15
  int v4; // edx
  hkgpConvexHullImpl::Vertex *v5; // rax
  signed int v6; // xmm1_4
  signed int v7; // xmm0_4
  int v8; // eax
  __int64 v9; // rbx
  signed int v10; // r12d
  signed int v11; // r13d
  unsigned int *v12; // rcx
  int v13; // eax
  __int64 v14; // r11
  unsigned int v15; // r10d
  unsigned int v16; // r9d
  unsigned int v17; // edx
  unsigned int *v18; // r14
  unsigned int v19; // eax
  unsigned int v20; // r13d
  unsigned int v21; // r12d
  int v22; // ecx
  hkgpConvexHullImpl::Triangle *m_triangle; // rdi
  int v24; // r12d
  int v25; // r13d
  hkBaseObjectVtbl *v26; // rdx
  hkBaseObjectVtbl *v27; // r12
  __int64 vfptr; // r10
  bool v29; // zf
  __m128i v30; // xmm0
  __m128i v31; // xmm2
  __m128i v32; // xmm5
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // r14
  __m128i v34; // xmm1
  __m128i v35; // xmm4
  __m128 v36; // xmm0
  __m128i v37; // xmm2
  __m128 m_quad; // xmm1
  __m128i v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm6
  __m128 v42; // xmm0
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm4
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm5
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm5
  __m128 v53; // xmm1
  int v54; // r9d
  __int64 v55; // r8
  hkgpConvexHullImpl::Vertex *m_data; // rax
  __int64 v57; // r13
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  __int64 v59; // r12
  hkgpConvexHullImpl::Vertex *m_used; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  __int64 v62; // rbx
  hkgpConvexHullImpl::Vertex *v63; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v64; // rax
  hkgpConvexHullImpl::Vertex *v65; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v66; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v67; // rsi
  hkgpConvexHullImpl::Vertex *v68; // rax
  hkgpConvexHullImpl::Vertex *v69; // rcx
  __int64 v70; // rdx
  int v71; // eax
  hkgpConvexHullImpl::Vertex *v72; // rcx
  __int64 v73; // rdx
  int v74; // eax
  __int64 v75; // rdx
  hkgpConvexHullImpl::Vertex *v76; // rcx
  bool v77; // cc
  int v78; // eax
  hkgpConvexHullImpl::Vertex *v79; // rcx
  int v80; // eax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v81; // rax
  hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Triangle,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // rdi
  __int64 v83; // rdx
  hkgpConvexHullImpl::Triangle *v84; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v85; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v86; // r13
  hkgpConvexHullImpl::Triangle *v87; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v88; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v89; // r12
  hkgpConvexHullImpl::Triangle *v90; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v91; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v92; // r15
  hkgpConvexHullImpl::Triangle *v93; // rax
  __int64 v94; // rdi
  int *v95; // rax
  int v96; // ecx
  int v97; // edx
  int v98; // r8d
  int v99; // r9d
  int v100; // r10d
  int v101; // r11d
  int v102; // edx
  int v103; // ecx
  __int64 v104; // rdi
  int v105; // edx
  int *v106; // r8
  int v107; // eax
  int v108; // ecx
  int v109; // edx
  int v110; // eax
  int v111; // r9d
  int v112; // r8d
  int v113; // r10d
  int v114; // r11d
  int v115; // edx
  int v116; // ecx
  int v117; // edi
  int *v118; // r8
  int v119; // edi
  int v120; // edx
  int v121; // ecx
  int v122; // eax
  int v123; // r9d
  int v124; // r10d
  int v125; // r8d
  int v126; // r11d
  int v127; // edx
  int v128; // edi
  int v129; // edx
  _QWORD *v130; // rdi
  int v131; // edx
  int v132; // r10d
  int v133; // r8d
  int v134; // r11d
  int v135; // eax
  int v136; // esi
  int v137; // r14d
  int v138; // edx
  int v139; // ecx
  int v140; // esi
  int v141; // r14d
  __int64 v142; // r8
  char *v143; // rcx
  char *v144; // rdx
  __int64 v145; // rax
  __int64 v146; // r8
  char *v147; // rcx
  char *v148; // rdx
  __int64 v149; // rax
  __int64 v150; // r8
  char *v151; // rcx
  char *v152; // rdx
  __int64 v153; // rax
  __int64 v154; // r8
  char *v155; // rcx
  char *v156; // rdx
  __int64 v157; // rax
  hkgpConvexHullImpl::Triangle *m_next; // rbx
  __int64 v160; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v161; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v162; // rsi
  hkgpConvexHullImpl::Vertex *v163; // rax
  __int128 v164; // xmm0
  int v165; // eax
  int v166; // eax
  unsigned int v167; // ecx
  unsigned __int64 v168; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v169; // r14
  unsigned __int64 v170; // r9
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v171; // r13
  int v172; // r8d
  __int64 v173; // rdx
  hkReferencedObject v174; // xmm0
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v175; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v176; // rdi
  hkgpConvexHullImpl::Triangle *v177; // rax
  _DWORD *v178; // r11
  _DWORD *v179; // r8
  int v180; // ecx
  int v181; // r10d
  int v182; // r9d
  int v183; // ebx
  int v184; // eax
  int v185; // r12d
  int v186; // r14d
  int v187; // r11d
  int v188; // r12d
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v189; // r11
  hkgpConvexHullImpl::Triangle *v190; // rax
  _DWORD *v191; // r9
  _DWORD *v192; // r8
  int v193; // r10d
  int v194; // edi
  int v195; // ebx
  int v196; // edx
  int v197; // ecx
  int v198; // r9d
  int v199; // edi
  int v200; // ebx
  int m_capacityAndFlags; // r8d
  int v202; // [rsp+20h] [rbp-E0h]
  int v203; // [rsp+24h] [rbp-DCh]
  hkErrStream v204; // [rsp+30h] [rbp-D0h] BYREF
  int v205; // [rsp+50h] [rbp-B0h]
  int *v206; // [rsp+58h] [rbp-A8h]
  __int64 v207; // [rsp+60h] [rbp-A0h]
  __int64 v208; // [rsp+68h] [rbp-98h]
  __int64 i; // [rsp+70h] [rbp-90h]
  int v210; // [rsp+78h] [rbp-88h]
  __int64 v211; // [rsp+80h] [rbp-80h]
  hkReferencedObject v212; // [rsp+90h] [rbp-70h]
  int v213; // [rsp+A0h] [rbp-60h]
  unsigned int *v214; // [rsp+A8h] [rbp-58h]
  hkReferencedObject v215; // [rsp+B0h] [rbp-50h]
  hkgpConvexHullImpl::Edge root; // [rsp+C0h] [rbp-40h] BYREF
  hkReferencedObject v217; // [rsp+D0h] [rbp-30h]
  signed int v218; // [rsp+100h] [rbp+0h]
  signed int v219; // [rsp+104h] [rbp+4h]
  signed int v220; // [rsp+108h] [rbp+8h]
  char buf[512]; // [rsp+120h] [rbp+20h] BYREF
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v223; // [rsp+390h] [rbp+290h]
  char v224; // [rsp+398h] [rbp+298h]
  int v225; // [rsp+398h] [rbp+298h]
  int v226; // [rsp+398h] [rbp+298h]
  int v227; // [rsp+398h] [rbp+298h]
  int v228; // [rsp+3A0h] [rbp+2A0h]
  unsigned __int64 v229; // [rsp+3A0h] [rbp+2A0h]
  int v230; // [rsp+3A8h] [rbp+2A8h]

  m_size = this->m_pendings.m_size;
  v2 = 0;
  v3 = this;
  v213 = m_size;
  v224 = 0;
  if ( m_size < 4 )
  {
    hkErrStream::hkErrStream(&v204, buf, 512);
    hkOstream::operator<<(&v204, "Internal error");
    if ( (unsigned int)hkError::messageError(
                         0x642CF968u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         647) )
      __debugbreak();
    hkOstream::~hkOstream(&v204);
  }
  v3->m_projectionPlane = 0i64;
  v4 = 0;
  v205 = 0;
  if ( m_size > 0 )
  {
    do
    {
      v211 = v4;
      v5 = &v3->m_pendings.m_data[(__int64)v4];
      v6 = v5->m_x[1];
      v218 = v5->m_x[0];
      v7 = v5->m_x[2];
      v219 = v6;
      v8 = v4 + 1;
      v9 = v4 + 1;
      v230 = v4 + 1;
      v208 = v9;
      v220 = v7;
      if ( v4 + 1 < m_size )
      {
        v10 = v220;
        v11 = v219;
        do
        {
          v12 = (unsigned int *)&v3->m_pendings.m_data[v9];
          v13 = v8 + 1;
          v14 = v13;
          v214 = v12;
          v228 = v13;
          for ( i = v13; v228 < m_size; i = v14 )
          {
            v15 = v12[8] - v218;
            v16 = v12[9] - v11;
            v17 = v12[10] - v10;
            v18 = (unsigned int *)&v3->m_pendings.m_data[v14];
            v19 = v18[9] - v11;
            v20 = v18[8] - v218;
            v21 = v18[10] - v10;
            v22 = v15 * v21;
            LODWORD(m_triangle) = v15 * v19 - v16 * v20;
            v24 = v16 * v21 - v17 * v19;
            v25 = v17 * v20 - v22;
            if ( v24 | v25 | (unsigned int)m_triangle )
            {
              v26 = (hkBaseObjectVtbl *)v24;
              m_triangle = (hkgpConvexHullImpl::Triangle *)(int)m_triangle;
              v212.vfptr = (hkBaseObjectVtbl *)v25;
              v27 = (hkBaseObjectVtbl *)v25;
              root.m_triangle = m_triangle;
              v204.vfptr = v26;
              vfptr = -((int)m_triangle * (__int64)v220 + v25 * (__int64)v219 + (_QWORD)v26 * v218);
              v29 = v3->m_config.m_allowLowerDimensions.m_bool == 0;
              v215.vfptr = (hkBaseObjectVtbl *)vfptr;
              if ( v29 )
              {
                m_free = 0i64;
              }
              else
              {
                v30 = _mm_cvtsi32_si128(v18[10]);
                v31 = _mm_cvtsi32_si128(v18[9]);
                v32 = _mm_cvtsi32_si128(v18[8]);
                m_free = 0i64;
                v34 = _mm_cvtsi32_si128(0);
                v35 = _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(v214[8]), _mm_cvtsi32_si128(v214[10])),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(v214[9]), v34));
                v36 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(v32, v30),
                                               _mm_unpacklo_epi32(v31, v34))),
                                  4),
                                4);
                v37 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v219), v34);
                m_quad = v3->m_scaleInv.m_quad;
                v39 = _mm_unpacklo_epi32(_mm_unpacklo_epi32(_mm_cvtsi32_si128(v218), _mm_cvtsi32_si128(v220)), v37);
                v40 = v3->m_origin.m_quad;
                v41 = _mm_add_ps(
                        _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v39), 4), 4), m_quad),
                        v40);
                v42 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v36, m_quad), v40), v41);
                v43 = _mm_sub_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v35), 4), 4),
                            m_quad),
                          v40),
                        v41);
                v44 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v43),
                        _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v42));
                v45 = _mm_shuffle_ps(v44, v44, 201);
                v46 = _mm_mul_ps(v45, v45);
                v47 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                        _mm_shuffle_ps(v46, v46, 170));
                v48 = _mm_rsqrt_ps(v47);
                v49 = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v47, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                            _mm_mul_ps(*(__m128 *)_xmm, v48))),
                        v45);
                v50 = _mm_mul_ps(v49, v41);
                v51 = _mm_mul_ps(v3->m_projectionPlane.m_quad, v3->m_projectionPlane.m_quad);
                v52 = _mm_shuffle_ps(
                        v49,
                        _mm_unpackhi_ps(
                          v49,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                              _mm_shuffle_ps(v50, v50, 170)))),
                        196);
                v53 = _mm_mul_ps(v52, v52);
                if ( (float)((float)(_mm_shuffle_ps(v53, v53, 85).m128_f32[0] + _mm_shuffle_ps(v53, v53, 0).m128_f32[0])
                           + _mm_shuffle_ps(v53, v53, 170).m128_f32[0]) > (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0]
                                                                                        + _mm_shuffle_ps(v51, v51, 0).m128_f32[0])
                                                                                + _mm_shuffle_ps(v51, v51, 170).m128_f32[0]) )
                  v3->m_projectionPlane.m_quad = v52;
              }
              v54 = v228 + 1;
              v210 = v228 + 1;
              v55 = v228 + 1;
              if ( v228 + 1 < m_size )
              {
                while ( 1 )
                {
                  m_data = v3->m_pendings.m_data;
                  v57 = v55 << 6;
                  v217.vfptr = (hkBaseObjectVtbl *)(v55 << 6);
                  v207 = (_QWORD)v26 * m_data[v55].m_x[0]
                       + vfptr
                       + (_QWORD)v27 * m_data[v55].m_x[1]
                       + (_QWORD)m_triangle * m_data[v55].m_x[2];
                  if ( v207 )
                  {
                    m_firstPool = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !m_firstPool || !m_firstPool->m_free )
                      m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( m_firstPool )
                    {
                      v59 = (__int64)m_firstPool->m_free->m_data;
                      m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v59;
                      *(_QWORD *)(v59 + 64) = m_firstPool;
                      ++m_firstPool->m_used;
                      *(_DWORD *)(v59 + 44) = 0;
                      *(_DWORD *)(v59 + 52) = -1;
                      *(_QWORD *)(v59 + 8) = 0i64;
                      *(_QWORD *)v59 = v3->m_mesh.m_vertices.m_used;
                      m_used = v3->m_mesh.m_vertices.m_used;
                      if ( m_used )
                        m_used->m_prev = (hkgpConvexHullImpl::Vertex *)v59;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v59;
                    }
                    else
                    {
                      v59 = 0i64;
                    }
                    NewPool = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    v206 = (int *)v59;
                    if ( !NewPool || !NewPool->m_free )
                      NewPool = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( NewPool )
                    {
                      v62 = (__int64)NewPool->m_free->m_data;
                      NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v62;
                      *(_QWORD *)(v62 + 64) = NewPool;
                      ++NewPool->m_used;
                      *(_DWORD *)(v62 + 44) = 0;
                      *(_DWORD *)(v62 + 52) = -1;
                      *(_QWORD *)(v62 + 8) = 0i64;
                      *(_QWORD *)v62 = v3->m_mesh.m_vertices.m_used;
                      v63 = v3->m_mesh.m_vertices.m_used;
                      if ( v63 )
                        v63->m_prev = (hkgpConvexHullImpl::Vertex *)v62;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v62;
                    }
                    else
                    {
                      v62 = 0i64;
                    }
                    v64 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !v64 || !v64->m_free )
                      v64 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v64 )
                    {
                      m_free = v64->m_free;
                      v64->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
                      m_free->m_pool = v64;
                      ++v64->m_used;
                      *(_DWORD *)&m_free->m_data[52] = -1;
                      *(_DWORD *)&m_free->m_data[44] = 0;
                      *(_QWORD *)&m_free->m_data[8] = 0i64;
                      *(_QWORD *)m_free->m_data = v3->m_mesh.m_vertices.m_used;
                      v65 = v3->m_mesh.m_vertices.m_used;
                      if ( v65 )
                        v65->m_prev = (hkgpConvexHullImpl::Vertex *)m_free;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)m_free;
                    }
                    v66 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
                    if ( !v66 || !v66->m_free )
                      v66 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
                    if ( v66 )
                    {
                      v67 = v66->m_free;
                      v66->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v67->m_data;
                      v67->m_pool = v66;
                      ++v66->m_used;
                      *(_DWORD *)&v67->m_data[44] = 0;
                      *(_DWORD *)&v67->m_data[52] = -1;
                      *(_QWORD *)&v67->m_data[8] = 0i64;
                      *(_QWORD *)v67->m_data = v3->m_mesh.m_vertices.m_used;
                      v68 = v3->m_mesh.m_vertices.m_used;
                      if ( v68 )
                        v68->m_prev = (hkgpConvexHullImpl::Vertex *)v67;
                      ++v3->m_mesh.m_vertices.m_numUsed;
                      v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v67;
                    }
                    else
                    {
                      v67 = 0i64;
                    }
                    v69 = v3->m_pendings.m_data;
                    v70 = v211 << 6;
                    v211 = v70;
                    *(hkVector4f *)(v59 + 16) = *(hkVector4f *)((char *)&v69->m_source + v70);
                    *(_DWORD *)(v59 + 32) = *(int *)((char *)v69->m_x + v70);
                    *(_DWORD *)(v59 + 36) = *(int *)((char *)&v69->m_x[1] + v70);
                    *(_DWORD *)(v59 + 40) = *(int *)((char *)&v69->m_x[2] + v70);
                    *(_DWORD *)(v59 + 44) = *(int *)((char *)&v69->m_x[3] + v70);
                    *(_DWORD *)(v59 + 48) = *(int *)((char *)&v69->m_refs + v70);
                    v71 = *(int *)((char *)&v69->m_index + v70);
                    *(_DWORD *)(v59 + 48) = 0;
                    *(_DWORD *)(v59 + 52) = v71;
                    v72 = v3->m_pendings.m_data;
                    v73 = v208 << 6;
                    v208 = v73;
                    *(hkVector4f *)(v62 + 16) = *(hkVector4f *)((char *)&v72->m_source + v73);
                    *(_DWORD *)(v62 + 32) = *(int *)((char *)v72->m_x + v73);
                    *(_DWORD *)(v62 + 36) = *(int *)((char *)&v72->m_x[1] + v73);
                    *(_DWORD *)(v62 + 40) = *(int *)((char *)&v72->m_x[2] + v73);
                    *(_DWORD *)(v62 + 44) = *(int *)((char *)&v72->m_x[3] + v73);
                    *(_DWORD *)(v62 + 48) = *(int *)((char *)&v72->m_refs + v73);
                    v74 = *(int *)((char *)&v72->m_index + v73);
                    v75 = i;
                    *(_DWORD *)(v62 + 52) = v74;
                    *(_DWORD *)(v62 + 48) = 0;
                    v76 = v3->m_pendings.m_data;
                    v75 <<= 6;
                    v77 = v207 <= 0;
                    i = v75;
                    *(hkVector4f *)&m_free->m_data[16] = *(hkVector4f *)((char *)&v76->m_source + v75);
                    *(_DWORD *)&m_free->m_data[32] = *(int *)((char *)v76->m_x + v75);
                    *(_DWORD *)&m_free->m_data[36] = *(int *)((char *)&v76->m_x[1] + v75);
                    *(_DWORD *)&m_free->m_data[40] = *(int *)((char *)&v76->m_x[2] + v75);
                    *(_DWORD *)&m_free->m_data[44] = *(int *)((char *)&v76->m_x[3] + v75);
                    *(_DWORD *)&m_free->m_data[48] = *(int *)((char *)&v76->m_refs + v75);
                    v78 = *(int *)((char *)&v76->m_index + v75);
                    *(_DWORD *)&m_free->m_data[48] = 0;
                    *(_DWORD *)&m_free->m_data[52] = v78;
                    v79 = v3->m_pendings.m_data;
                    *(hkVector4f *)&v67->m_data[16] = *(hkVector4f *)((char *)&v79->m_source + v57);
                    *(_DWORD *)&v67->m_data[32] = *(int *)((char *)v79->m_x + v57);
                    *(_DWORD *)&v67->m_data[36] = *(int *)((char *)&v79->m_x[1] + v57);
                    *(_DWORD *)&v67->m_data[40] = *(int *)((char *)&v79->m_x[2] + v57);
                    *(_DWORD *)&v67->m_data[44] = *(int *)((char *)&v79->m_x[3] + v57);
                    *(_DWORD *)&v67->m_data[48] = *(int *)((char *)&v79->m_refs + v57);
                    v80 = *(int *)((char *)&v79->m_index + v57);
                    *(_DWORD *)&v67->m_data[48] = 0;
                    *(_DWORD *)&v67->m_data[52] = v80;
                    if ( !v77 )
                    {
                      v206 = (int *)v62;
                      v62 = v59;
                    }
                    v81 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v3->m_mesh.m_triangles.m_allocator.m_firstPool;
                    p_m_triangles = &v3->m_mesh.m_triangles;
                    if ( !v81 || !v81->m_free )
                      v81 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v81 )
                    {
                      v83 = (__int64)v81->m_free->m_data;
                      v207 = v83;
                      v81->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v83;
                      *(_QWORD *)(v83 + 112) = v81;
                      ++v81->m_used;
                      *(_DWORD *)(v83 + 88) = -1;
                      *(_DWORD *)(v83 + 100) = -1;
                      *(_QWORD *)(v83 + 8) = 0i64;
                      *(_QWORD *)v83 = v3->m_mesh.m_triangles.m_used;
                      v84 = v3->m_mesh.m_triangles.m_used;
                      if ( v84 )
                        v84->m_prev = (hkgpConvexHullImpl::Triangle *)v83;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v83;
                    }
                    else
                    {
                      v207 = 0i64;
                    }
                    v85 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)p_m_triangles->m_allocator.m_firstPool;
                    if ( !p_m_triangles->m_allocator.m_firstPool || !v85->m_free )
                      v85 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v85 )
                    {
                      v86 = v85->m_free;
                      v85->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v86->m_data;
                      v86->m_pool = v85;
                      ++v85->m_used;
                      *(_DWORD *)&v86->m_data[88] = -1;
                      *(_DWORD *)&v86->m_data[100] = -1;
                      *(_QWORD *)&v86->m_data[8] = 0i64;
                      *(_QWORD *)v86->m_data = v3->m_mesh.m_triangles.m_used;
                      v87 = v3->m_mesh.m_triangles.m_used;
                      if ( v87 )
                        v87->m_prev = (hkgpConvexHullImpl::Triangle *)v86;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v86;
                    }
                    else
                    {
                      v86 = 0i64;
                    }
                    v88 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)p_m_triangles->m_allocator.m_firstPool;
                    if ( !p_m_triangles->m_allocator.m_firstPool || !v88->m_free )
                      v88 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v88 )
                    {
                      v89 = v88->m_free;
                      v88->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v89->m_data;
                      v89->m_pool = v88;
                      ++v88->m_used;
                      *(_DWORD *)&v89->m_data[88] = -1;
                      *(_DWORD *)&v89->m_data[100] = -1;
                      *(_QWORD *)&v89->m_data[8] = 0i64;
                      *(_QWORD *)v89->m_data = v3->m_mesh.m_triangles.m_used;
                      v90 = v3->m_mesh.m_triangles.m_used;
                      if ( v90 )
                        v90->m_prev = (hkgpConvexHullImpl::Triangle *)v89;
                      ++v3->m_mesh.m_triangles.m_numUsed;
                      v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v89;
                    }
                    else
                    {
                      v89 = 0i64;
                    }
                    v91 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)p_m_triangles->m_allocator.m_firstPool;
                    if ( !p_m_triangles->m_allocator.m_firstPool || !v91->m_free )
                      v91 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
                    if ( v91 )
                    {
                      v92 = v91->m_free;
                      v91->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v92->m_data;
                      v92->m_pool = v91;
                      ++v91->m_used;
                      *(_DWORD *)&v92->m_data[88] = -1;
                      *(_DWORD *)&v92->m_data[100] = -1;
                      *(_QWORD *)&v92->m_data[8] = 0i64;
                      *(_QWORD *)v92->m_data = p_m_triangles->m_used;
                      v93 = p_m_triangles->m_used;
                      if ( v93 )
                        v93->m_prev = (hkgpConvexHullImpl::Triangle *)v92;
                      ++p_m_triangles->m_numUsed;
                      p_m_triangles->m_used = (hkgpConvexHullImpl::Triangle *)v92;
                    }
                    else
                    {
                      v92 = 0i64;
                    }
                    v94 = v207;
                    v95 = v206;
                    *(_QWORD *)(v207 + 16) = v206;
                    *(_DWORD *)(v94 + 96) = 0;
                    *(_QWORD *)(v94 + 24) = v62;
                    *(_QWORD *)(v94 + 32) = m_free;
                    *(_DWORD *)(v94 + 100) = -1;
                    ++v95[12];
                    ++*(_DWORD *)(v62 + 48);
                    ++*(_DWORD *)&m_free->m_data[48];
                    v96 = v95[9];
                    v97 = v95[8];
                    LODWORD(v95) = v95[10];
                    v98 = *(_DWORD *)(v62 + 40) - (_DWORD)v95;
                    v99 = *(_DWORD *)&m_free->m_data[32] - v97;
                    v100 = *(_DWORD *)(v62 + 36) - v96;
                    v101 = *(_DWORD *)(v62 + 32) - v97;
                    v102 = *(_DWORD *)&m_free->m_data[36] - v96;
                    v103 = *(_DWORD *)&m_free->m_data[40] - (_DWORD)v95;
                    v225 = v100 * v103 - v98 * v102;
                    v104 = v207;
                    *(_DWORD *)(v207 + 64) = v225;
                    v105 = v101 * v102 - v100 * v99;
                    LODWORD(v95) = v98 * v99;
                    v106 = v206;
                    v107 = (_DWORD)v95 - v101 * v103;
                    *(_DWORD *)(v104 + 68) = v107;
                    *(_DWORD *)(v104 + 72) = v105;
                    *(_QWORD *)(v104 + 80) = 0i64;
                    if ( v225 | v107 | v105 )
                      *(_QWORD *)(v104 + 80) = -(v107 * (__int64)v106[9]
                                               + v105 * (__int64)v106[10]
                                               + v106[8] * (__int64)v225);
                    *(_QWORD *)&v86->m_data[16] = v106;
                    *(_DWORD *)&v86->m_data[96] = 0;
                    *(_QWORD *)&v86->m_data[24] = v67;
                    *(_QWORD *)&v86->m_data[32] = v62;
                    *(_DWORD *)&v86->m_data[100] = -1;
                    ++v106[12];
                    ++*(_DWORD *)&v67->m_data[48];
                    ++*(_DWORD *)(v62 + 48);
                    v108 = v106[9];
                    v109 = v106[8];
                    v110 = v106[10];
                    v111 = *(_DWORD *)(v62 + 32) - v109;
                    v112 = *(_DWORD *)&v67->m_data[40] - v110;
                    v113 = *(_DWORD *)&v67->m_data[36] - v108;
                    v114 = *(_DWORD *)&v67->m_data[32] - v109;
                    v115 = *(_DWORD *)(v62 + 36) - v108;
                    v116 = *(_DWORD *)(v62 + 40) - v110;
                    v226 = v113 * v116 - v112 * v115;
                    *(_DWORD *)&v86->m_data[64] = v226;
                    v117 = v112 * v111;
                    v118 = v206;
                    v119 = v117 - v114 * v116;
                    *(_DWORD *)&v86->m_data[68] = v119;
                    v202 = v114 * v115 - v113 * v111;
                    *(_DWORD *)&v86->m_data[72] = v202;
                    *(_QWORD *)&v86->m_data[80] = 0i64;
                    if ( v226 | v119 | v202 )
                      *(_QWORD *)&v86->m_data[80] = -(v119 * (__int64)v118[9]
                                                    + v202 * (__int64)v118[10]
                                                    + v118[8] * (__int64)v226);
                    *(_DWORD *)&v89->m_data[96] = 0;
                    *(_QWORD *)&v89->m_data[16] = v118;
                    *(_QWORD *)&v89->m_data[24] = m_free;
                    *(_QWORD *)&v89->m_data[32] = v67;
                    *(_DWORD *)&v89->m_data[100] = -1;
                    ++v118[12];
                    ++*(_DWORD *)&m_free->m_data[48];
                    ++*(_DWORD *)&v67->m_data[48];
                    v120 = v118[8];
                    v121 = v118[9];
                    v122 = v118[10];
                    v123 = *(_DWORD *)&v67->m_data[32] - v120;
                    v124 = *(_DWORD *)&m_free->m_data[36] - v121;
                    v125 = *(_DWORD *)&m_free->m_data[40] - v122;
                    v126 = *(_DWORD *)&m_free->m_data[32] - v120;
                    v127 = *(_DWORD *)&v67->m_data[36] - v121;
                    v128 = *(_DWORD *)&v67->m_data[40] - v122;
                    v227 = v124 * v128 - v125 * v127;
                    v129 = v126 * v127 - v124 * v123;
                    *(_DWORD *)&v89->m_data[64] = v227;
                    v203 = v125 * v123 - v126 * v128;
                    *(_DWORD *)&v89->m_data[68] = v203;
                    v130 = (_QWORD *)v207;
                    *(_DWORD *)&v89->m_data[72] = v129;
                    *(_QWORD *)&v89->m_data[80] = 0i64;
                    if ( v227 | v203 | v129 )
                      *(_QWORD *)&v89->m_data[80] = -(v206[8] * (__int64)v227
                                                    + v206[9] * (__int64)v203
                                                    + v129 * (__int64)v206[10]);
                    *(_QWORD *)&v92->m_data[24] = v67;
                    *(_QWORD *)&v92->m_data[32] = m_free;
                    *(_QWORD *)&v92->m_data[16] = v62;
                    *(_DWORD *)&v92->m_data[96] = 0;
                    *(_DWORD *)&v92->m_data[100] = -1;
                    ++*(_DWORD *)(v62 + 48);
                    ++*(_DWORD *)&v67->m_data[48];
                    ++*(_DWORD *)&m_free->m_data[48];
                    v131 = *(_DWORD *)&m_free->m_data[36] - *(_DWORD *)(v62 + 36);
                    v132 = *(_DWORD *)&v67->m_data[36] - *(_DWORD *)(v62 + 36);
                    v133 = *(_DWORD *)&v67->m_data[40] - *(_DWORD *)(v62 + 40);
                    v134 = *(_DWORD *)&v67->m_data[32] - *(_DWORD *)(v62 + 32);
                    v135 = v133 * v131;
                    v136 = *(_DWORD *)&m_free->m_data[40] - *(_DWORD *)(v62 + 40);
                    v137 = *(_DWORD *)&m_free->m_data[32] - *(_DWORD *)(v62 + 32);
                    v138 = v134 * v131 - v132 * v137;
                    v139 = v134 * v136;
                    *(_DWORD *)&v92->m_data[72] = v138;
                    v140 = v132 * v136 - v135;
                    v141 = v133 * v137 - v139;
                    *(_QWORD *)&v92->m_data[80] = 0i64;
                    *(_DWORD *)&v92->m_data[64] = v140;
                    *(_DWORD *)&v92->m_data[68] = v141;
                    if ( v140 | v141 | v138 )
                      *(_QWORD *)&v92->m_data[80] = -(v141 * (__int64)*(int *)(v62 + 36)
                                                    + *(int *)(v62 + 32) * (__int64)v140
                                                    + *(int *)(v62 + 40) * (__int64)v138);
                    v130[5] = &v86->m_data[2];
                    *(_QWORD *)&v86->m_data[56] = v130;
                    v130[6] = &v92->m_data[2];
                    *(_QWORD *)&v92->m_data[56] = (char *)v130 + 1;
                    v130[7] = v89;
                    *(_QWORD *)&v89->m_data[40] = (char *)v130 + 2;
                    *(_QWORD *)&v86->m_data[40] = &v89->m_data[2];
                    *(_QWORD *)&v89->m_data[56] = v86;
                    *(_QWORD *)&v89->m_data[48] = &v92->m_data[1];
                    *(_QWORD *)&v92->m_data[48] = &v89->m_data[1];
                    *(_QWORD *)&v92->m_data[40] = &v86->m_data[1];
                    *(_QWORD *)&v86->m_data[48] = v92;
                    v3 = this;
                    if ( --this->m_pendings.m_size != v210 )
                    {
                      v142 = 8i64;
                      v143 = (char *)this->m_pendings.m_data + (unsigned __int64)v217.vfptr;
                      v144 = (char *)((char *)&this->m_pendings.m_data[(__int64)this->m_pendings.m_size] - v143);
                      do
                      {
                        v145 = *(_QWORD *)&v143[(_QWORD)v144];
                        v143 += 8;
                        *((_QWORD *)v143 - 1) = v145;
                        --v142;
                      }
                      while ( v142 );
                    }
                    if ( --this->m_pendings.m_size != v228 )
                    {
                      v146 = 8i64;
                      v147 = (char *)this->m_pendings.m_data + i;
                      v148 = (char *)((char *)&this->m_pendings.m_data[(__int64)this->m_pendings.m_size] - v147);
                      do
                      {
                        v149 = *(_QWORD *)&v147[(_QWORD)v148];
                        v147 += 8;
                        *((_QWORD *)v147 - 1) = v149;
                        --v146;
                      }
                      while ( v146 );
                    }
                    if ( --this->m_pendings.m_size != v230 )
                    {
                      v150 = 8i64;
                      v151 = (char *)this->m_pendings.m_data + v208;
                      v152 = (char *)((char *)&this->m_pendings.m_data[(__int64)this->m_pendings.m_size] - v151);
                      do
                      {
                        v153 = *(_QWORD *)&v151[(_QWORD)v152];
                        v151 += 8;
                        *((_QWORD *)v151 - 1) = v153;
                        --v150;
                      }
                      while ( v150 );
                    }
                    if ( --this->m_pendings.m_size != v205 )
                    {
                      v154 = 8i64;
                      v155 = (char *)this->m_pendings.m_data + v211;
                      v156 = (char *)((char *)&this->m_pendings.m_data[(__int64)this->m_pendings.m_size] - v155);
                      do
                      {
                        v157 = *(_QWORD *)&v155[(_QWORD)v156];
                        v155 += 8;
                        *((_QWORD *)v155 - 1) = v157;
                        --v154;
                      }
                      while ( v154 );
                    }
                    m_size = v213;
                    vfptr = (__int64)v215.vfptr;
                    m_triangle = root.m_triangle;
                    v27 = v212.vfptr;
                    v54 = v213;
                    v55 = v213;
                    v228 = v213;
                    v14 = v213;
                    i = v213;
                    v208 = v213;
                    v211 = v213;
                    v230 = v213;
                    v9 = v213;
                    v205 = v213;
                    v224 = 1;
                  }
                  v26 = v204.vfptr;
                  ++v54;
                  ++v55;
                  v210 = v54;
                  if ( v54 >= m_size )
                    break;
                  m_free = 0i64;
                }
              }
              v2 = v224;
              if ( !v224 )
                return 0;
            }
            else
            {
              v2 = v224;
            }
            v12 = v214;
            v10 = v220;
            v11 = v219;
            ++v14;
            ++v228;
          }
          ++v9;
          v8 = v230 + 1;
          v208 = v9;
          v230 = v8;
        }
        while ( v8 < m_size );
        v4 = v205;
      }
      v205 = ++v4;
    }
    while ( v4 < m_size );
    if ( v2 )
    {
      if ( v3->m_pendings.m_size > 0 )
      {
        do
        {
          m_next = v3->m_mesh.m_triangles.m_used;
          v160 = (__int64)&v3->m_pendings.m_data[(__int64)(v3->m_pendings.m_size - 1)];
          if ( m_next )
          {
            while ( m_next->m_plane.m_d
                  + *(int *)(v160 + 32) * (__int64)m_next->m_plane.m_c[0]
                  + *(int *)(v160 + 40) * (__int64)m_next->m_plane.m_c[2]
                  + *(int *)(v160 + 36) * (__int64)m_next->m_plane.m_c[1] <= 0 )
            {
              m_next = m_next->m_next;
              if ( !m_next )
                goto LABEL_160;
            }
            v161 = v3->m_mesh.m_vertices.m_allocator.m_firstPool;
            if ( !v161 || !v161->m_free )
              v161 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v3->m_mesh.m_vertices.m_allocator);
            if ( v161 )
            {
              v162 = v161->m_free;
              v161->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v162->m_data;
              v162->m_pool = v161;
              ++v161->m_used;
              *(_DWORD *)&v162->m_data[44] = 0;
              *(_DWORD *)&v162->m_data[52] = -1;
              *(_QWORD *)&v162->m_data[8] = 0i64;
              *(_QWORD *)v162->m_data = v3->m_mesh.m_vertices.m_used;
              v163 = v3->m_mesh.m_vertices.m_used;
              if ( v163 )
                v163->m_prev = (hkgpConvexHullImpl::Vertex *)v162;
              ++v3->m_mesh.m_vertices.m_numUsed;
              v3->m_mesh.m_vertices.m_used = (hkgpConvexHullImpl::Vertex *)v162;
            }
            else
            {
              v162 = 0i64;
            }
            v164 = *(_OWORD *)(v160 + 16);
            v204.vfptr = 0i64;
            *(_DWORD *)&v204.m_memSizeAndFlags = 0;
            *(_OWORD *)&v162->m_data[16] = v164;
            *(_DWORD *)&v162->m_data[32] = *(_DWORD *)(v160 + 32);
            *(_DWORD *)&v162->m_data[36] = *(_DWORD *)(v160 + 36);
            *(_DWORD *)&v162->m_data[40] = *(_DWORD *)(v160 + 40);
            *(_DWORD *)&v162->m_data[44] = *(_DWORD *)(v160 + 44);
            v165 = *(_DWORD *)(v160 + 48);
            root.m_triangle = m_next;
            *(_DWORD *)&v162->m_data[48] = v165;
            v166 = *(_DWORD *)(v160 + 52);
            *(_DWORD *)&v162->m_data[48] = 0;
            *(_DWORD *)&v162->m_data[52] = v166;
            ++v3->m_pid;
            root.m_index = 0;
            hkgpConvexHullImpl::clearHorizon(
              v3,
              (hkgpConvexHullImpl::Vertex *)v162,
              &root,
              (hkgpConvexHullImpl::Edge *)&v204);
            v167 = *(_DWORD *)&v204.m_memSizeAndFlags;
            v168 = (unsigned __int64)v204.vfptr;
            if ( ((unsigned __int64)*(&v204.vfptr[2].__first_virtual_table_function__ + *(int *)&v204.m_memSizeAndFlags) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            {
              do
              {
                v215.vfptr = (hkBaseObjectVtbl *)v168;
                *(_DWORD *)&v215.m_memSizeAndFlags = (9 >> (2 * v167)) & 3;
                v204.hkReferencedObject = v215;
                v167 = *(_DWORD *)&v215.m_memSizeAndFlags;
              }
              while ( (*(_QWORD *)(v168 + 8i64 * *(int *)&v215.m_memSizeAndFlags + 40) & 0xFFFFFFFFFFFFFFFCui64) != 0 );
            }
            v169 = 0i64;
            v223 = 0i64;
            v170 = v168 + v167;
            v171 = 0i64;
            v229 = v170;
            while ( 1 )
            {
              v212.vfptr = (hkBaseObjectVtbl *)v168;
              v172 = (9 >> (2 * v167)) & 3;
              *(_DWORD *)&v212.m_memSizeAndFlags = v172;
              if ( (*(_QWORD *)(v168 + 8i64 * v172 + 40) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
              {
                do
                {
                  v173 = *(_QWORD *)(v168 + 8i64 * v172 + 40);
                  v217.vfptr = (hkBaseObjectVtbl *)(v173 & 0xFFFFFFFFFFFFFFFCui64);
                  *(_DWORD *)&v217.m_memSizeAndFlags = (9 >> (2 * (v173 & 3))) & 3;
                  v29 = (*(_QWORD *)((v173 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * *(int *)&v217.m_memSizeAndFlags + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0;
                  v174 = v217;
                  v212 = v217;
                  v172 = *(_DWORD *)&v217.m_memSizeAndFlags;
                  v168 = v173 & 0xFFFFFFFFFFFFFFFCui64;
                }
                while ( !v29 );
              }
              else
              {
                v174 = v212;
              }
              v204.hkReferencedObject = v174;
              v175 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v3->m_mesh.m_triangles.m_allocator.m_firstPool;
              if ( v170 == v168 + (unsigned int)v172 )
                break;
              if ( !v175 || !v175->m_free )
                v175 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
              if ( v175 )
              {
                v176 = v175->m_free;
                v175->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v176->m_data;
                v176->m_pool = v175;
                ++v175->m_used;
                *(_DWORD *)&v176->m_data[88] = -1;
                *(_DWORD *)&v176->m_data[100] = -1;
                *(_QWORD *)&v176->m_data[8] = 0i64;
                *(_QWORD *)v176->m_data = v3->m_mesh.m_triangles.m_used;
                v177 = v3->m_mesh.m_triangles.m_used;
                if ( v177 )
                  v177->m_prev = (hkgpConvexHullImpl::Triangle *)v176;
                ++v3->m_mesh.m_triangles.m_numUsed;
                v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v176;
              }
              else
              {
                v176 = 0i64;
              }
              v178 = (_DWORD *)*((_QWORD *)&v204.vfptr[1].__vecDelDtor + *(int *)&v204.m_memSizeAndFlags);
              v179 = (_DWORD *)*((_QWORD *)&v204.vfptr[1].__vecDelDtor
                               + ((9i64 >> (2 * LOBYTE(v204.m_memSizeAndFlags))) & 3));
              *(_QWORD *)&v176->m_data[32] = v178;
              *(_QWORD *)&v176->m_data[16] = v162;
              *(_QWORD *)&v176->m_data[24] = v179;
              *(_DWORD *)&v176->m_data[96] = 0;
              *(_DWORD *)&v176->m_data[100] = -1;
              ++*(_DWORD *)&v162->m_data[48];
              ++v179[12];
              ++v178[12];
              v181 = v179[9] - *(_DWORD *)&v162->m_data[36];
              v182 = v179[10] - *(_DWORD *)&v162->m_data[40];
              v183 = v179[8] - *(_DWORD *)&v162->m_data[32];
              v184 = v178[9] - *(_DWORD *)&v162->m_data[36];
              v180 = v178[10] - *(_DWORD *)&v162->m_data[40];
              v185 = v178[8] - *(_DWORD *)&v162->m_data[32];
              v186 = v183 * v184 - v181 * v185;
              *(_DWORD *)&v176->m_data[72] = v186;
              v187 = v181 * v180 - v182 * v184;
              *(_DWORD *)&v176->m_data[64] = v187;
              *(_QWORD *)&v176->m_data[80] = 0i64;
              v188 = v182 * v185 - v183 * v180;
              *(_DWORD *)&v176->m_data[68] = v188;
              if ( v187 | v188 | v186 )
                *(_QWORD *)&v176->m_data[80] = -(v187 * (__int64)*(int *)&v162->m_data[32]
                                               + v188 * (__int64)*(int *)&v162->m_data[36]
                                               + v186 * (__int64)*(int *)&v162->m_data[40]);
              *((_QWORD *)&v204.vfptr[2].__first_virtual_table_function__ + *(int *)&v204.m_memSizeAndFlags) = &v176->m_data[1];
              *(_QWORD *)&v176->m_data[48] = (char *)v204.vfptr + *(unsigned int *)&v204.m_memSizeAndFlags;
              if ( v171 )
              {
                v169 = v223;
                *(_QWORD *)&v171->m_data[40] = &v176->m_data[2];
                *(_QWORD *)&v176->m_data[56] = v171;
              }
              else
              {
                v169 = v176;
                v223 = v176;
              }
              LOBYTE(v167) = v204.m_memSizeAndFlags;
              v168 = (unsigned __int64)v204.vfptr;
              v170 = v229;
              v171 = v176;
            }
            if ( !v175 || !v175->m_free )
              v175 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)&v3->m_mesh.m_triangles);
            if ( v175 )
            {
              v189 = v175->m_free;
              v175->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v189->m_data;
              v189->m_pool = v175;
              ++v175->m_used;
              *(_DWORD *)&v189->m_data[88] = -1;
              *(_DWORD *)&v189->m_data[100] = -1;
              *(_QWORD *)&v189->m_data[8] = 0i64;
              *(_QWORD *)v189->m_data = v3->m_mesh.m_triangles.m_used;
              v190 = v3->m_mesh.m_triangles.m_used;
              if ( v190 )
                v190->m_prev = (hkgpConvexHullImpl::Triangle *)v189;
              ++v3->m_mesh.m_triangles.m_numUsed;
              v3->m_mesh.m_triangles.m_used = (hkgpConvexHullImpl::Triangle *)v189;
            }
            else
            {
              v189 = 0i64;
            }
            v191 = (_DWORD *)*((_QWORD *)&v204.vfptr[1].__vecDelDtor + *(int *)&v204.m_memSizeAndFlags);
            v192 = (_DWORD *)*((_QWORD *)&v204.vfptr[1].__vecDelDtor
                             + ((9i64 >> (2 * LOBYTE(v204.m_memSizeAndFlags))) & 3));
            *(_QWORD *)&v189->m_data[32] = v191;
            *(_QWORD *)&v189->m_data[16] = v162;
            *(_QWORD *)&v189->m_data[24] = v192;
            *(_DWORD *)&v189->m_data[96] = 0;
            *(_DWORD *)&v189->m_data[100] = -1;
            ++*(_DWORD *)&v162->m_data[48];
            ++v192[12];
            ++v191[12];
            v193 = v192[9] - *(_DWORD *)&v162->m_data[36];
            v194 = v192[10] - *(_DWORD *)&v162->m_data[40];
            v195 = v192[8] - *(_DWORD *)&v162->m_data[32];
            v196 = v191[9] - *(_DWORD *)&v162->m_data[36];
            v197 = v191[10] - *(_DWORD *)&v162->m_data[40];
            LODWORD(v192) = v191[8] - *(_DWORD *)&v162->m_data[32];
            *(_QWORD *)&v189->m_data[80] = 0i64;
            v198 = v197 * v193 - v196 * v194;
            *(_DWORD *)&v189->m_data[64] = v198;
            v199 = (_DWORD)v192 * v194 - v197 * v195;
            v200 = v196 * v195 - (_DWORD)v192 * v193;
            *(_DWORD *)&v189->m_data[68] = v199;
            *(_DWORD *)&v189->m_data[72] = v200;
            if ( v198 | v199 | v200 )
              *(_QWORD *)&v189->m_data[80] = -(v198 * (__int64)*(int *)&v162->m_data[32]
                                             + v199 * (__int64)*(int *)&v162->m_data[36]
                                             + v200 * (__int64)*(int *)&v162->m_data[40]);
            *((_QWORD *)&v204.vfptr[2].__first_virtual_table_function__ + *(int *)&v204.m_memSizeAndFlags) = &v189->m_data[1];
            *(_QWORD *)&v189->m_data[48] = (char *)v204.vfptr + *(unsigned int *)&v204.m_memSizeAndFlags;
            *(_QWORD *)&v171->m_data[40] = &v189->m_data[2];
            *(_QWORD *)&v189->m_data[56] = v171;
            *(_QWORD *)&v189->m_data[40] = &v169->m_data[2];
            if ( v169 )
              *(_QWORD *)&v169->m_data[56] = v189;
          }
LABEL_160:
          --v3->m_pendings.m_size;
        }
        while ( v3->m_pendings.m_size > 0 );
        v2 = v224;
      }
      m_capacityAndFlags = v3->m_pendings.m_capacityAndFlags;
      v3->m_pendings.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v3->m_pendings.m_data,
          m_capacityAndFlags << 6);
      v3->m_pendings.m_data = 0i64;
      v3->m_pendings.m_capacityAndFlags = 0x80000000;
    }
  }
  return v2;
}     + v200 * (__int64)*(int *)&v162->m_data[40]);
            *((_QWORD *)&v204.vfptr[2].__first_virtual_table_function__ + *(int *)&v204.m_memSizeAndFlags) = &v189->m_data[1];
            *(_QWORD *)&v189->m_data[48] = (char *)v204.vfptr + *(u

// File Line: 784
// RVA: 0xCC3CC0
void __fastcall hkgpConvexHullImpl::clearHorizon(
        hkgpConvexHullImpl *this,
        hkgpConvexHullImpl::Vertex *vertex,
        hkgpConvexHullImpl::Edge *root,
        hkgpConvexHullImpl::Edge *horizon)
{
  hkgpConvexHullImpl::Triangle *m_triangle; // rax
  int m_pid; // ecx
  hkgpConvexHullImpl::Triangle *v9; // r8
  unsigned __int64 v10; // rcx
  char v11; // al
  char v12; // al
  __int64 v13; // r9
  unsigned __int64 v14; // rdx
  char *v15; // r8
  char *v16; // r8
  hkgpConvexHullImpl::Triangle *v17; // rbp
  __int64 v18; // rsi
  hkgpConvexHullImpl::Vertex ***m_vertices; // rdi
  hkgpConvexHullImpl::Vertex **v20; // rax
  hkgpConvexHullImpl::Vertex **v21; // rdx
  hkgpConvexHullImpl::Vertex *v22; // rax
  hkgpConvexHullImpl::Vertex *v23; // rcx
  hkgpConvexHullImpl::Vertex *v24; // rdx
  bool v25; // zf
  hkgpConvexHullImpl::Vertex *m_prev; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v27; // rax
  __int64 v28; // rcx
  hkgpConvexHullImpl::Triangle *m_next; // rax
  hkgpConvexHullImpl::Triangle *v30; // rcx
  hkgpConvexHullImpl::Triangle *v31; // rdx
  unsigned __int64 v32; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *v33; // rax
  unsigned __int64 v34; // r8
  hkgpConvexHullImpl::Edge roota; // [rsp+20h] [rbp-28h] BYREF

  m_triangle = root->m_triangle;
  if ( root->m_triangle )
  {
    m_pid = this->m_pid;
    if ( m_triangle->m_pid != m_pid )
    {
      m_triangle->m_pid = m_pid;
      v9 = root->m_triangle;
      if ( v9->m_plane.m_d
         + v9->m_plane.m_c[0] * (__int64)vertex->m_x[0]
         + vertex->m_x[1] * (__int64)v9->m_plane.m_c[1]
         + vertex->m_x[2] * (__int64)v9->m_plane.m_c[2] < 0 )
      {
        horizon->m_triangle = v9;
        *(_QWORD *)&horizon->m_index = *(_QWORD *)&root->m_index;
      }
      else
      {
        v10 = v9->m_links[root->m_index];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(v10 & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v10 & 3;
        hkgpConvexHullImpl::clearHorizon(this, vertex, &roota, horizon);
        v11 = root->m_triangle->m_links[(9 >> (2 * root->m_index)) & 3];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(root->m_triangle->m_links[(9 >> (2 * root->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v11 & 3;
        hkgpConvexHullImpl::clearHorizon(this, vertex, &roota, horizon);
        v12 = root->m_triangle->m_links[(18 >> (2 * root->m_index)) & 3];
        roota.m_triangle = (hkgpConvexHullImpl::Triangle *)(root->m_triangle->m_links[(18 >> (2 * root->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64);
        roota.m_index = v12 & 3;
        hkgpConvexHullImpl::clearHorizon(this, vertex, &roota, horizon);
        v13 = 0i64;
        v14 = root->m_triangle->m_links[root->m_index];
        if ( (v14 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((v14 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (v14 & 3) + 40) = 0i64;
        root->m_triangle->m_links[root->m_index] = 0i64;
        v15 = (char *)root->m_triangle + 8 * ((9 >> (2 * root->m_index)) & 3);
        if ( (*((_QWORD *)v15 + 5) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((*((_QWORD *)v15 + 5) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*((_QWORD *)v15 + 5) & 3i64) + 40) = 0i64;
        *((_QWORD *)v15 + 5) = 0i64;
        v16 = (char *)root->m_triangle + 8 * ((18 >> (2 * root->m_index)) & 3);
        if ( (*((_QWORD *)v16 + 5) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((*((_QWORD *)v16 + 5) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*((_QWORD *)v16 + 5) & 3i64) + 40) = 0i64;
        *((_QWORD *)v16 + 5) = 0i64;
        v17 = root->m_triangle;
        v18 = 3i64;
        m_vertices = (hkgpConvexHullImpl::Vertex ***)root->m_triangle->m_vertices;
        do
        {
          v20 = *m_vertices;
          if ( !--*((_DWORD *)v20 + 12) )
          {
            v21 = *m_vertices;
            v22 = **m_vertices;
            v23 = (*m_vertices)[1];
            if ( v22 )
              v22->m_prev = v23;
            if ( v23 )
              v23->m_next = v22;
            else
              this->m_mesh.m_vertices.m_used = v22;
            --this->m_mesh.m_vertices.m_numUsed;
            v24 = v21[8];
            v25 = v24[40].m_source.m_quad.m128_i32[2]-- == 1;
            if ( v25 )
            {
              m_prev = v24[40].m_prev;
              v27 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *)v24[40].m_source.m_quad.m128_u64[0];
              if ( m_prev )
                m_prev[40].m_source.m_quad.m128_u64[0] = (unsigned __int64)v27;
              else
                this->m_mesh.m_vertices.m_allocator.m_firstPool = v27;
              v28 = v24[40].m_source.m_quad.m128_i64[0];
              if ( v28 )
                *(_QWORD *)(v28 + 2568) = v24[40].m_prev;
              ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkgpConvexHullImpl::Vertex *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->blockFree)(
                &hkContainerHeapAllocator::s_alloc,
                v24,
                2592i64,
                v13);
            }
          }
          ++m_vertices;
          --v18;
        }
        while ( v18 );
        m_next = v17->m_next;
        v30 = v17->m_prev;
        if ( v17->m_next )
          m_next->m_prev = v30;
        if ( v30 )
          v30->m_next = m_next;
        else
          this->m_mesh.m_triangles.m_used = m_next;
        --this->m_mesh.m_triangles.m_numUsed;
        v31 = v17[1].m_prev;
        v25 = v31[39].m_plane.m_c[0]-- == 1;
        if ( v25 )
        {
          v32 = v31[39].m_links[1];
          v33 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::Pool *)v31[39].m_links[2];
          if ( v32 )
            *(_QWORD *)(v32 + 4112) = v33;
          else
            this->m_mesh.m_triangles.m_allocator.m_firstPool = v33;
          v34 = v31[39].m_links[2];
          if ( v34 )
            *(_QWORD *)(v34 + 4104) = v31[39].m_links[1];
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkgpConvexHullImpl::Triangle *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->blockFree)(
            &hkContainerHeapAllocator::s_alloc,
            v31,
            4128i64,
            v13);
        }
      }
    }
  }
}

// File Line: 927
// RVA: 0xCB7BB0
char __fastcall hkgpConvexHullImpl::isPointInside(
        hkgpConvexHullImpl *this,
        hkVector4f *point,
        bool usePlanes,
        float epsilon)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  int v8; // ecx
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128i v12; // xmm1
  hkgpConvexHullImpl::Triangle *m_used; // rdx
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  __int64 m_size; // rdx
  __int64 v18; // rax
  float v19; // xmm4_4
  hkVector4f *i; // rcx
  __m128 v21; // xmm1
  hkErrStream v22; // [rsp+20h] [rbp-268h] BYREF
  __int64 v23; // [rsp+60h] [rbp-228h]
  unsigned int v24; // [rsp+68h] [rbp-220h]
  char buf[520]; // [rsp+80h] [rbp-208h] BYREF

  if ( usePlanes )
  {
    if ( !this->m_hasIndexing )
    {
      hkErrStream::hkErrStream(&v22, buf, 512);
      v15 = hkOstream::operator<<(&v22, "No index available (");
      v16 = hkOstream::operator<<(v15, this->m_uid);
      hkOstream::operator<<(v16, ") hkgpConvexHull::buildIndices need to be called before this operation.");
      if ( (unsigned int)hkError::messageError(
                           0x79F9D886u,
                           buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           358) )
        __debugbreak();
      hkOstream::~hkOstream(&v22);
    }
    m_size = this->m_planes.m_size;
    v18 = 0i64;
    LODWORD(v19) = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0).m128_u32[0];
    if ( m_size > 0 )
    {
      for ( i = this->m_planes.m_data; ; ++i )
      {
        v21 = _mm_mul_ps(i->m_quad, point->m_quad);
        if ( (float)((float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                           + _mm_shuffle_ps(v21, v21, 170).m128_f32[0])
                   + _mm_shuffle_ps(i->m_quad, i->m_quad, 255).m128_f32[0]) > v19 )
          break;
        if ( ++v18 >= m_size )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    v6 = _mm_mul_ps(_mm_sub_ps(point->m_quad, this->m_origin.m_quad), this->m_scale.m_quad);
    v7 = _mm_cmplt_ps(v6, (__m128)_xmm);
    v8 = _mm_movemask_ps(_mm_cmplt_ps((__m128)_xmm, v6)) | _mm_movemask_ps(
                                                             _mm_cmplt_ps(
                                                               v6,
                                                               (__m128)_xmm_c6000000c6000000c6000000c6000000));
    v9 = _mm_max_ps(
           (__m128)_xmm_c6000000c6000000c6000000c6000000,
           _mm_or_ps(_mm_andnot_ps(v7, (__m128)_xmm), _mm_and_ps(v6, v7)));
    v10 = _mm_cmplt_ps(v9, (__m128)0i64);
    v11 = _mm_or_ps(
            _mm_andnot_ps(v10, _mm_add_ps(v9, (__m128)xmmword_141A711B0)),
            _mm_and_ps(_mm_sub_ps(v9, (__m128)xmmword_141A711B0), v10));
    v12 = _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v11),
            _mm_cvttps_epi32(v11));
    v23 = v12.m128i_i64[0];
    v24 = _mm_shuffle_epi32(v12, 170).m128i_u32[0];
    if ( (v8 & 7) != 0 )
      return 0;
    m_used = this->m_mesh.m_triangles.m_used;
    if ( m_used )
    {
      while ( m_used->m_plane.m_d
            + (int)v23 * (__int64)m_used->m_plane.m_c[0]
            + SHIDWORD(v23) * (__int64)m_used->m_plane.m_c[1]
            + (int)v24 * (__int64)m_used->m_plane.m_c[2] <= 0 )
      {
        m_used = m_used->m_next;
        if ( !m_used )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

// File Line: 952
// RVA: 0xCB45C0
bool __fastcall hkgpConvexHullImpl::clipLine(
        hkgpConvexHullImpl *this,
        hkVector4f *aIn,
        hkVector4f *bIn,
        float *t0,
        float *t1,
        float epsilon)
{
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  __int64 m_size; // r8
  __m128 m_quad; // xmm8
  __m128 v14; // xmm10
  __m128 v15; // xmm7
  __m128 v16; // xmm9
  __m128 v17; // xmm11
  __m128 v18; // xmm12
  hkVector4f *m_data; // r9
  int v20; // r10d
  hkVector4f *v21; // r11
  unsigned __int64 v22; // rcx
  __m128 v23; // xmm13
  __m128 v24; // xmm14
  __m128 v25; // xmm8
  __m128 v26; // xmm15
  hkReferencedObject v27; // xmm0
  __m128 v28; // xmm7
  __m128 v29; // xmm6
  __m128 v30; // xmm0
  __m128 v31; // xmm5
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  int v34; // eax
  __int64 v35; // rax
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm6
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  hkErrStream v50; // [rsp+20h] [rbp-2D8h] BYREF
  __m128 v51; // [rsp+40h] [rbp-2B8h]
  char buf[512]; // [rsp+50h] [rbp-2A8h] BYREF

  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v50, buf, 512);
    v10 = hkOstream::operator<<(&v50, "No index available (");
    v11 = hkOstream::operator<<(v10, this->m_uid);
    hkOstream::operator<<(v11, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v50);
  }
  m_size = this->m_planes.m_size;
  m_quad = aIn->m_quad;
  v14 = 0i64;
  v15 = _mm_sub_ps(bIn->m_quad, aIn->m_quad);
  v16 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
  v17 = query.m_quad;
  v18 = _mm_sub_ps((__m128)0i64, v16);
  if ( (int)m_size > 0 )
  {
    m_data = this->m_planes.m_data;
    v20 = 2;
    v21 = m_data;
    v22 = ((unsigned __int64)(m_size - 1) >> 2) + 1;
    v23 = _mm_shuffle_ps(m_quad, m_quad, 0);
    v24 = _mm_shuffle_ps(m_quad, m_quad, 85);
    v25 = _mm_shuffle_ps(m_quad, m_quad, 170);
    v26 = _mm_shuffle_ps(v15, v15, 85);
    v51 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    v27 = (hkReferencedObject)_mm_shuffle_ps(v15, v15, 0);
    v28 = _mm_shuffle_ps(v15, v15, 170);
    v50.hkReferencedObject = v27;
    do
    {
      v29 = v21->m_quad;
      v21 += 4;
      v30 = m_data[(v20 - 1) % (int)m_size].m_quad;
      v31 = _mm_shuffle_ps(v29, v30, 68);
      v32 = _mm_shuffle_ps(v29, v30, 238);
      v33 = m_data[v20 % (int)m_size].m_quad;
      v34 = v20 + 1;
      v20 += 4;
      v35 = v34 % (int)m_size;
      v36 = _mm_shuffle_ps(v33, m_data[v35].m_quad, 68);
      v37 = _mm_shuffle_ps(v33, m_data[v35].m_quad, 238);
      v38 = _mm_shuffle_ps(v31, v36, 136);
      v39 = _mm_shuffle_ps(v31, v36, 221);
      v40 = _mm_shuffle_ps(v32, v37, 221);
      v41 = _mm_shuffle_ps(v32, v37, 136);
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps((__m128)v50.hkReferencedObject, v38), _mm_mul_ps(v26, v39)),
              _mm_mul_ps(v28, v41));
      v43 = _mm_cmplt_ps(v16, v42);
      v44 = _mm_div_ps(
              _mm_xor_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(v40, _mm_mul_ps(v23, v38)), _mm_mul_ps(v24, v39)),
                  _mm_mul_ps(v25, v41)),
                v51),
              v42);
      v45 = _mm_and_ps(_mm_cmplt_ps(v14, v44), _mm_cmplt_ps(v42, v18));
      v46 = _mm_and_ps(_mm_cmplt_ps(v44, v17), v43);
      v14 = _mm_or_ps(_mm_and_ps(v45, v44), _mm_andnot_ps(v45, v14));
      v17 = _mm_or_ps(_mm_andnot_ps(v46, v17), _mm_and_ps(v46, v44));
      --v22;
    }
    while ( v22 );
  }
  v47 = _mm_max_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v48 = _mm_min_ps(_mm_shuffle_ps(v17, v17, 78), v17);
  v47.m128_f32[0] = fmax(v47.m128_f32[0], _mm_shuffle_ps(v47, v47, 177).m128_f32[0]);
  *t0 = v47.m128_f32[0];
  v48.m128_f32[0] = fmin(v48.m128_f32[0], _mm_shuffle_ps(v48, v48, 177).m128_f32[0]);
  *t1 = v48.m128_f32[0];
  return v47.m128_f32[0] < v48.m128_f32[0];
}

// File Line: 1036
// RVA: 0xCB03D0
void __fastcall hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(hkgpConvexHullImpl *this)
{
  int m_numUsed; // r9d
  hkgpConvexHullImpl::Triangle *i; // rdx
  __int64 v4; // rcx
  hkgpConvexHullImpl::SortedTriangle *v5; // rcx
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm2
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
  int v18; // r9d
  hkgpConvexHullImpl::Triangle *m_used; // rbx
  __int64 v20; // r14
  hkVector4f v21; // xmm1
  hkVector4f v22; // xmm2
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
  hkgpConvexHullImpl::Vertex *m_next; // rax
  int j; // ecx
  int m_dimensions; // eax
  int v37; // r13d
  char *v38; // rsi
  __int64 v39; // r15
  int v40; // eax
  __m128 *v41; // r12
  int v42; // edx
  unsigned __int64 v43; // rbx
  unsigned __int64 *v44; // rcx
  IAmdDxExt *mExtension; // rax
  int v46; // edx
  unsigned __int64 v47; // rbx
  unsigned __int64 *v48; // rcx
  __int64 v49; // rax
  int v50; // edx
  unsigned __int64 v51; // rbx
  unsigned __int64 *v52; // rcx
  IAmdDxExt *v53; // rax
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
  hkgpConvexHullImpl::Vertex *v76; // rbx
  __m128 m_quad; // xmm12
  unsigned int *v78; // rax
  hkgpConvexHullImpl::Vertex *k; // rcx
  hkVector4f v80; // xmm4
  hkVector4f v81; // xmm5
  __m128 v82; // xmm7
  __m128 v83; // xmm6
  hkVector4f *v84; // rcx
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
  hkVector4f v98; // xmm4
  hkVector4f v99; // xmm7
  __m128 v100; // xmm6
  hkgpConvexHullImpl::Vertex *m; // rcx
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
  hkgpConvexHullImpl::Vertex *n; // r8
  int v114; // edx
  __int64 v115; // rax
  hkVector4f *m_data; // rcx
  __m128 v117; // xmm1
  __m128 v118; // xmm3
  int m_size; // ecx
  int v120; // r8d
  _QWORD *v121; // [rsp+30h] [rbp-C0h] BYREF
  int v122; // [rsp+38h] [rbp-B8h]
  int v123; // [rsp+3Ch] [rbp-B4h]
  hkgpConvexHullImpl::SortedTriangle *array; // [rsp+40h] [rbp-B0h] BYREF
  int v125; // [rsp+48h] [rbp-A8h]
  int v126; // [rsp+4Ch] [rbp-A4h]
  _OWORD *v127; // [rsp+50h] [rbp-A0h] BYREF
  int v128; // [rsp+58h] [rbp-98h]
  int v129; // [rsp+5Ch] [rbp-94h]
  AMD_HD3D v130; // [rsp+60h] [rbp-90h] BYREF
  __int64 v131; // [rsp+88h] [rbp-68h]
  __int64 v132; // [rsp+98h] [rbp-58h]
  __int64 v133; // [rsp+A8h] [rbp-48h]
  hkResult result; // [rsp+160h] [rbp+70h] BYREF
  char *retaddr; // [rsp+168h] [rbp+78h]

  if ( !this->m_hasIndexing )
  {
    m_numUsed = this->m_mesh.m_triangles.m_numUsed;
    v126 = 0x80000000;
    v130.mHeight = -1;
    v129 = 0x80000000;
    array = 0i64;
    v125 = 0;
    *(_QWORD *)&v130.mEnableStereo = 0i64;
    v130.mWidth = 0;
    v127 = 0i64;
    v128 = 0;
    if ( m_numUsed )
    {
      if ( m_numUsed > 0 )
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 16);
      for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
      {
        v4 = v125++;
        v5 = &array[v4];
        v5->m_data = i;
        v6.m_quad = (__m128)this->m_scaleInv;
        v7.m_quad = (__m128)this->m_origin;
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
                 v6.m_quad),
               v7.m_quad);
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
                   v6.m_quad),
                 v7.m_quad),
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
                    v6.m_quad),
                  v7.m_quad),
                v8);
        v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
        v12 = _mm_shuffle_ps(v11, v11, 201);
        v13 = _mm_mul_ps(v12, v12);
        v14 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170));
        v15 = _mm_rsqrt_ps(v14);
        LODWORD(v5->m_value) = _mm_andnot_ps(
                                 _mm_cmple_ps(v14, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v15)),
                                   v14)).m128_u32[0];
      }
      if ( v125 > 1 )
        hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::SortedTriangle,hkAlgorithm::less<hkgpConvexHullImpl::SortedTriangle>>(
          array,
          0,
          v125 - 1,
          0);
      v16 = 0;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v130,
        &hkContainerHeapAllocator::s_alloc,
        this->m_mesh.m_triangles.m_numUsed);
      v17 = this->m_mesh.m_triangles.m_numUsed;
      if ( (v129 & 0x3FFFFFFF) < v17 )
      {
        v18 = this->m_mesh.m_triangles.m_numUsed;
        if ( v17 < 2 * (v129 & 0x3FFFFFFF) )
          v18 = 2 * (v129 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v127, v18, 16);
      }
      v128 = v17;
      m_used = this->m_mesh.m_triangles.m_used;
      if ( m_used )
      {
        v20 = 0i64;
        do
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v130,
            &hkContainerHeapAllocator::s_alloc,
            (unsigned __int64)m_used,
            v16);
          v21.m_quad = (__m128)this->m_scaleInv;
          v22.m_quad = (__m128)this->m_origin;
          v23 = _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[0]),
                                               _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[2])),
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[1]),
                                               _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    v21.m_quad),
                  v22.m_quad);
          v24 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v21.m_quad),
                    v22.m_quad),
                  v23);
          v25 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v21.m_quad),
                    v22.m_quad),
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
          v31 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v29), (__m128)0i64);
          ++v20;
          v32 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v29, (__m128)0i64),
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
          m_used->m_index = v16;
          m_used->m_plane.m_index = -1;
          m_used = m_used->m_next;
          ++v16;
        }
        while ( m_used );
      }
    }
    m_next = this->m_mesh.m_vertices.m_used;
    for ( j = 0; m_next; ++j )
    {
      m_next->m_index = j;
      m_next = m_next->m_next;
    }
    m_dimensions = this->m_dimensions;
    this->m_planes.m_size = 0;
    switch ( m_dimensions )
    {
      case 3:
        v121 = 0i64;
        v122 = 0;
        v37 = 0;
        v123 = 0x80000000;
        if ( v125 > 0 )
        {
          v38 = 0i64;
          retaddr = 0i64;
          do
          {
            v39 = *(_QWORD *)&v38[(_QWORD)array];
            if ( *(_DWORD *)(v39 + 88) == -1 )
            {
              v40 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v130,
                      *(_QWORD *)&v38[(_QWORD)array],
                      0xFFFFFFFFFFFFFFFFui64);
              v41 = (__m128 *)&v127[v40];
              *(_DWORD *)(v39 + 88) = this->m_planes.m_size;
              if ( this->m_planes.m_size == (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_planes.m_data, 16);
              v42 = 0;
              this->m_planes.m_data[this->m_planes.m_size++].m_quad = *v41;
              v122 = 0;
              v43 = *(_QWORD *)(v39 + 40) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v130.mExtension) = *(_DWORD *)(v39 + 40) & 3;
              if ( (v123 & 0x3FFFFFFF) == 0 )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 16);
                v42 = v122;
              }
              v44 = &v121[2 * v42];
              if ( v44 )
              {
                mExtension = v130.mExtension;
                *v44 = v43;
                v44[1] = (unsigned __int64)mExtension;
                v42 = v122;
              }
              v46 = v42 + 1;
              v122 = v46;
              v47 = *(_QWORD *)(v39 + 48) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v132) = *(_QWORD *)(v39 + 48) & 3;
              if ( v46 == (v123 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 16);
                v46 = v122;
              }
              v48 = &v121[2 * v46];
              if ( v48 )
              {
                v49 = v132;
                *v48 = v47;
                v48[1] = v49;
                v46 = v122;
              }
              v50 = v46 + 1;
              v122 = v50;
              v51 = *(_QWORD *)(v39 + 56) & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v130.mExtension) = *(_QWORD *)(v39 + 56) & 3;
              if ( v50 == (v123 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 16);
                v50 = v122;
              }
              v52 = &v121[2 * v50];
              if ( v52 )
              {
                v53 = v130.mExtension;
                *v52 = v51;
                v52[1] = (unsigned __int64)v53;
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
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v130,
                            v56,
                            0xFFFFFFFFFFFFFFFFui64);
                    result.m_enum = 953267991;
                    v59 = (__m128)v127[v58];
                    if ( (_mm_movemask_ps(_mm_cmpunord_ps(v59, v59)) & 7) != 0
                      || (v60 = _mm_mul_ps(v59, v59),
                          COERCE_FLOAT((unsigned int)(2
                                                    * COERCE_INT(
                                                        (float)((float)(_mm_shuffle_ps(v60, v60, 85).m128_f32[0]
                                                                      + _mm_shuffle_ps(v60, v60, 0).m128_f32[0])
                                                              + _mm_shuffle_ps(v60, v60, 170).m128_f32[0])
                                                      - 1.0)) >> 1) >= _mm_shuffle_ps(
                                                                         (__m128)(unsigned int)result.m_enum,
                                                                         (__m128)(unsigned int)result.m_enum,
                                                                         0).m128_f32[0])
                      || (v61 = _mm_mul_ps(*v41, v59),
                          (float)((float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                                + _mm_shuffle_ps(v61, v61, 170).m128_f32[0]) >= this->m_config.m_minCosAngle) )
                    {
                      v62 = 2 * v57;
                      *(_DWORD *)(v56 + 88) = *(_DWORD *)(v39 + 88);
                      v63 = v122;
                      v64 = *(_QWORD *)(v56 + 8i64 * ((9 >> (2 * v57)) & 3) + 40);
                      v65 = v64;
                      v66 = v64 & 0xFFFFFFFFFFFFFFFCui64;
                      LODWORD(v131) = v65 & 3;
                      if ( v122 == (v123 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 16);
                        v63 = v122;
                      }
                      v67 = &v121[2 * v63];
                      if ( v67 )
                      {
                        v68 = v131;
                        *v67 = v66;
                        v67[1] = v68;
                        v63 = v122;
                      }
                      v69 = v63 + 1;
                      v122 = v69;
                      v70 = *(_QWORD *)(v56 + 8i64 * ((18 >> v62) & 3) + 40);
                      v71 = v70;
                      v72 = v70 & 0xFFFFFFFFFFFFFFFCui64;
                      LODWORD(v133) = v71 & 3;
                      if ( v69 == (v123 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 16);
                        v69 = v122;
                      }
                      v73 = &v121[2 * v69];
                      if ( v73 )
                      {
                        v74 = v133;
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
            v38 += 16;
            ++v37;
            retaddr = v38;
          }
          while ( v37 < v125 );
        }
        v122 = 0;
        if ( v123 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v121, 16 * v123);
        break;
      case 2:
        v75 = hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(this);
        v76 = this->m_mesh.m_vertices.m_used;
        m_quad = v75->m_quad;
        v78 = (unsigned int *)v76;
        if ( v76 )
        {
          for ( k = v76->m_next; k; k = k->m_next )
            v78 = (unsigned int *)k;
          do
          {
            v80.m_quad = (__m128)this->m_scaleInv;
            v81.m_quad = (__m128)this->m_origin;
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
                      v80.m_quad),
                    v81.m_quad);
            v83 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v76->m_x[0]),
                                                   _mm_cvtsi32_si128(v76->m_x[2])),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v76->m_x[1]),
                                                   _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v80.m_quad),
                      v81.m_quad),
                    v82);
            if ( this->m_planes.m_size == (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_planes.m_data, 16);
            v84 = &this->m_planes.m_data[this->m_planes.m_size++];
            v78 = (unsigned int *)v76;
            v85 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), this->m_projectionPlane.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(this->m_projectionPlane.m_quad, this->m_projectionPlane.m_quad, 201), v83));
            v86 = _mm_shuffle_ps(v85, v85, 201);
            v87 = _mm_mul_ps(v86, v86);
            v88 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                    _mm_shuffle_ps(v87, v87, 170));
            v89 = _mm_rsqrt_ps(v88);
            v90 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v88), (__m128)0i64);
            v91 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v88, (__m128)0i64),
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
            v94 = _mm_mul_ps(m_quad, v93);
            v95 = _mm_shuffle_ps(v94, _mm_unpackhi_ps(v94, v93), 196);
            v96 = _mm_add_ps(_mm_shuffle_ps(v95, v95, 78), v95);
            v84->m_quad = _mm_xor_ps(
                            (__m128)_mm_slli_epi32(
                                      _mm_srli_epi32(
                                        _mm_cmpeq_epi32(
                                          _mm_srai_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v96, v96, 177), v96), 0x1Fu),
                                          (__m128i)0i64),
                                        0x1Fu),
                                      0x1Fu),
                            v93);
            v76 = v76->m_next;
          }
          while ( v76 );
        }
        break;
      case 1:
        v97 = this->m_mesh.m_vertices.m_used;
        v98.m_quad = (__m128)this->m_scaleInv;
        v99.m_quad = (__m128)this->m_origin;
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
                   v98.m_quad),
                 v99.m_quad);
        if ( v97 )
        {
          for ( m = v97->m_next; m; m = m->m_next )
            v97 = m;
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
                   v98.m_quad),
                 v99.m_quad);
        v103 = _mm_sub_ps(v102, v100);
        v104 = _mm_mul_ps(v103, v103);
        v105 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                 _mm_shuffle_ps(v104, v104, 170));
        v106 = _mm_rsqrt_ps(v105);
        v107 = _mm_mul_ps(
                 v103,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v105, (__m128)0i64),
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
        if ( (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_planes.m_data, 16);
        this->m_planes.m_data[this->m_planes.m_size++].m_quad = v109;
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
        if ( this->m_planes.m_size == (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_planes.m_data, 16);
        this->m_planes.m_data[this->m_planes.m_size++].m_quad = v112;
        break;
    }
    if ( this->m_config.m_ensurePlaneEnclosing.m_bool )
    {
      for ( n = this->m_mesh.m_vertices.m_used; n; n = n->m_next )
      {
        v114 = 0;
        if ( this->m_planes.m_size > 0 )
        {
          v115 = 0i64;
          do
          {
            m_data = this->m_planes.m_data;
            v117 = _mm_mul_ps(m_data[v115].m_quad, n->m_source.m_quad);
            v118 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                       _mm_shuffle_ps(v117, v117, 170)),
                     _mm_shuffle_ps(m_data[v115].m_quad, m_data[v115].m_quad, 255));
            if ( v118.m128_f32[0] > 0.0 )
              m_data[v115].m_quad = _mm_shuffle_ps(
                                      m_data[v115].m_quad,
                                      _mm_unpackhi_ps(
                                        m_data[v115].m_quad,
                                        _mm_sub_ps(_mm_shuffle_ps(m_data[v115].m_quad, m_data[v115].m_quad, 255), v118)),
                                      196);
            ++v114;
            ++v115;
          }
          while ( v114 < this->m_planes.m_size );
        }
      }
    }
    if ( this->m_planes.m_size )
    {
      m_size = this->m_planes.m_size;
      if ( m_size < (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&this->m_planes.m_data,
          16,
          0i64,
          m_size);
    }
    v120 = v129;
    this->m_hasIndexing = 1;
    v128 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v127, 16 * v120);
    v127 = 0i64;
    v129 = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v130,
      &hkContainerHeapAllocator::s_alloc);
    _(&v130);
    v125 = 0;
    if ( v126 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v126);
  }
}lloc,
          (const void **)&this->m_planes.m_data,
          16,
          0i64,
          m_size);
    }
    v120 = v129;
    this->m_hasIndexing = 1;
    v128 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v127, 16 * v120);
    v127 = 0i64;
    v129 = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64

// File Line: 1160
// RVA: 0xCB0030
void __fastcall hkgpConvexHullImpl::buildBevelPlanes<hkgpConvexHullImpl::PositionAsTransform>(
        hkgpConvexHullImpl *this,
        float maxCosAngle,
        hkArray<hkVector4f,hkContainerHeapAllocator> *bevelPlanes)
{
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkgpConvexHullImpl::Triangle *m_used; // r14
  float v8; // xmm8_4
  int v9; // edi
  unsigned __int64 *m_links; // rsi
  unsigned __int64 v11; // r10
  int v12; // edx
  hkgpConvexHullImpl::Vertex *v13; // rcx
  unsigned __int64 v14; // r9
  int *m_x; // rax
  int v16; // ecx
  __int64 m_index; // rax
  hkVector4f *m_data; // rcx
  __m128 m_quad; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  hkVector4f v27; // xmm4
  hkVector4f v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128i v32; // xmm0
  __m128i v33; // xmm2
  __m128i v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm6
  hkErrStream v37; // [rsp+20h] [rbp-268h] BYREF
  char buf[512]; // [rsp+40h] [rbp-248h] BYREF

  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v37, buf, 512);
    v5 = hkOstream::operator<<(&v37, "No index available (");
    v6 = hkOstream::operator<<(v5, this->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v37);
  }
  if ( this->m_dimensions == 3 )
  {
    m_used = this->m_mesh.m_triangles.m_used;
    for ( LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(maxCosAngle), (__m128)LODWORD(maxCosAngle), 0).m128_u32[0];
          m_used;
          m_used = m_used->m_next )
    {
      v9 = 0;
      m_links = m_used->m_links;
      do
      {
        v11 = *m_links & 0xFFFFFFFFFFFFFFFCui64;
        v12 = 0;
        v13 = m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)v9)) & 3];
        v14 = *(m_links - 3) - (_QWORD)v13;
        m_x = v13->m_x;
        do
        {
          v16 = *(int *)((char *)m_x + v14);
          if ( v16 < *m_x )
            break;
          if ( v16 > *m_x )
          {
            if ( v11 )
              goto LABEL_23;
            break;
          }
          ++v12;
          ++m_x;
        }
        while ( v12 < 3 );
        m_index = m_used->m_plane.m_index;
        if ( (_DWORD)m_index != *(_DWORD *)(v11 + 88) )
        {
          m_data = this->m_planes.m_data;
          m_quad = m_data[*(int *)(v11 + 88)].m_quad;
          v20 = _mm_mul_ps(m_data[m_index].m_quad, m_quad);
          if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                     + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) < v8 )
          {
            v21 = _mm_add_ps(m_data[m_index].m_quad, m_quad);
            v22 = _mm_mul_ps(v21, v21);
            v23 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170));
            v24 = _mm_rsqrt_ps(v23);
            v25 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v23), (__m128)0i64);
            v26 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v23, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                            _mm_mul_ps(*(__m128 *)_xmm, v24))),
                        v21),
                      v25),
                    _mm_andnot_ps(v25, v21));
            if ( _mm_movemask_ps(v25) )
            {
              v27.m_quad = (__m128)this->m_scaleInv;
              v28.m_quad = (__m128)this->m_origin;
              v29 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          (__m128)_mm_srli_si128(
                                    _mm_slli_si128(
                                      (__m128i)_mm_cvtepi32_ps(
                                                 _mm_unpacklo_epi32(
                                                   _mm_unpacklo_epi32(
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(m_links - 3) + 32)),
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(m_links - 3) + 40))),
                                                   _mm_unpacklo_epi32(
                                                     _mm_cvtsi32_si128(*(_DWORD *)(*(m_links - 3) + 36)),
                                                     _mm_cvtsi32_si128(0)))),
                                      4),
                                    4),
                          v27.m_quad),
                        v28.m_quad),
                      v26);
              v30 = _mm_shuffle_ps(
                      v26,
                      _mm_unpackhi_ps(
                        v26,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170))),
                      196);
              if ( this->m_config.m_ensurePlaneEnclosing.m_bool )
              {
                for ( i = this->m_mesh.m_vertices.m_used;
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
                              v27.m_quad),
                            v28.m_quad),
                          v30);
                }
              }
              v36 = _mm_shuffle_ps(
                      v30,
                      _mm_unpackhi_ps(v30, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v30, v30, 255))),
                      196);
              if ( bevelPlanes->m_size == (bevelPlanes->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&bevelPlanes->m_data, 16);
              bevelPlanes->m_data[bevelPlanes->m_size++].m_quad = v36;
            }
          }
        }
LABEL_23:
        ++v9;
        ++m_links;
      }
      while ( v9 < 3 );
    }
  }
}

// File Line: 1224
// RVA: 0xCB89E0
hkResult *__fastcall hkgpConvexHullImpl::simplify(
        hkgpConvexHullImpl *this,
        hkResult *result,
        hkgpConvexHull::SimplifyConfig *config)
{
  bool v3; // zf
  bool v5; // r12
  int m_dimensions; // eax
  int m_numUsed; // ebx
  float v10; // xmm9_4
  float v11; // xmm9_4
  hkgpConvexHullImpl::Triangle *m_used; // rcx
  float v13; // xmm5_4
  hkgpConvexHullImpl::Triangle *v14; // r11
  __m128 m_quad; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  float v23; // xmm3_4
  __m128 *v24; // rdi
  int v25; // ebx
  __m128 *v26; // r14
  __m128 **v27; // r9
  int v28; // r8d
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  float v31; // xmm3_4
  int v32; // r10d
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  float v35; // xmm2_4
  int v36; // r9d
  int v37; // r8d
  hkgpConvexHullImpl::Vertex *i; // rbx
  hkOstream *v39; // rax
  hkOstream *v40; // rax
  int m_size; // r11d
  int v42; // edx
  int v43; // edi
  __int64 v44; // rbx
  int v45; // r8d
  __int64 v46; // rcx
  int *m_data; // r14
  int v48; // ebx
  int v49; // eax
  hkgpConvexHullImpl::Vertex *m_next; // rcx
  hkBaseObjectVtbl *vfptr; // r8
  hkVector4f *v52; // rax
  int v53; // ebx
  int v54; // r9d
  __int64 v55; // rdx
  __int64 v56; // r8
  int v57; // ebx
  hkVector4f *v58; // rdx
  int v59; // r8d
  hkgpConvexHullImpl::Vertex *v60; // rcx
  int v61; // r8d
  hkVector4f *v62; // rax
  hkResult sizeElem; // [rsp+20h] [rbp-E0h]
  hkVector4f *array; // [rsp+30h] [rbp-D0h] BYREF
  int numPoints; // [rsp+38h] [rbp-C8h]
  int v67; // [rsp+3Ch] [rbp-C4h]
  hkArray<int,hkContainerHeapAllocator> vi; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f *points; // [rsp+50h] [rbp-B0h] BYREF
  int v70; // [rsp+58h] [rbp-A8h]
  int v71; // [rsp+5Ch] [rbp-A4h]
  hkResult v72; // [rsp+60h] [rbp-A0h] BYREF
  hkErrStream v73; // [rsp+68h] [rbp-98h] BYREF
  hkResult v74; // [rsp+80h] [rbp-80h] BYREF
  hkArray<int,hkContainerHeapAllocator> vpf; // [rsp+88h] [rbp-78h] BYREF
  char buf[512]; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v77; // [rsp+320h] [rbp+220h] BYREF
  bool m_hasMassProperties; // [rsp+330h] [rbp+230h]
  hkResult resulta; // [rsp+338h] [rbp+238h] BYREF

  v3 = config->m_forceRebuild.m_bool == 0;
  m_hasMassProperties = this->m_hasMassProperties;
  v5 = !v3;
  LOBYTE(v77.m_enum) = this->m_hasIndexing;
  m_dimensions = this->m_dimensions;
  if ( m_dimensions < 0 )
    goto LABEL_97;
  if ( m_dimensions > 2 )
  {
    if ( m_dimensions == 3 )
    {
      if ( config->m_maxVertices >= 4 )
      {
        m_numUsed = this->m_mesh.m_vertices.m_numUsed;
        hkgpConvexHullImpl::decimateVertices(this, config->m_maxVertices, config->m_ensureContainment.m_bool != 0, 0);
        v5 = this->m_mesh.m_vertices.m_numUsed != m_numUsed;
      }
      if ( config->m_minArea > 0.0 )
      {
        v10 = _mm_shuffle_ps((__m128)LODWORD(config->m_minArea), (__m128)LODWORD(config->m_minArea), 0).m128_f32[0];
        v11 = v10 + v10;
        do
        {
          m_used = this->m_mesh.m_triangles.m_used;
          v13 = v11;
          v14 = 0i64;
          if ( !m_used )
            break;
          do
          {
            m_quad = m_used->m_vertices[0]->m_source.m_quad;
            v16 = _mm_sub_ps(m_used->m_vertices[1]->m_source.m_quad, m_quad);
            v17 = _mm_sub_ps(m_used->m_vertices[2]->m_source.m_quad, m_quad);
            v18 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16),
                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17));
            v19 = _mm_shuffle_ps(v18, v18, 201);
            v20 = _mm_mul_ps(v19, v19);
            v21 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170));
            v22 = _mm_rsqrt_ps(v21);
            v23 = _mm_andnot_ps(
                    _mm_cmple_ps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                        _mm_mul_ps(*(__m128 *)_xmm, v22)),
                      v21)).m128_f32[0];
            if ( v23 < v13 )
            {
              v13 = v23;
              v14 = m_used;
            }
            m_used = m_used->m_next;
          }
          while ( m_used );
          if ( !v14 )
            break;
          v24 = (__m128 *)v14->m_vertices[1];
          v25 = 0;
          v26 = (__m128 *)v14->m_vertices[0];
          v27 = (__m128 **)&v14->m_vertices[1];
          v28 = 1;
          v29 = _mm_sub_ps(v26[1], v24[1]);
          v30 = _mm_mul_ps(v29, v29);
          v31 = (float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
              + _mm_shuffle_ps(v30, v30, 170).m128_f32[0];
          do
          {
            v32 = v28 + 1;
            v33 = _mm_sub_ps((*v27)[1], v14->m_vertices[(v28 + 1) % 3]->m_source.m_quad);
            v34 = _mm_mul_ps(v33, v33);
            v35 = (float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                + _mm_shuffle_ps(v34, v34, 170).m128_f32[0];
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
          v36 = this->m_mesh.m_vertices.m_numUsed;
          v67 = 0x80000000;
          array = 0i64;
          v37 = 0;
          numPoints = 0;
          if ( v36 <= 0 )
          {
            resulta.m_enum = HK_SUCCESS;
          }
          else
          {
            hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v36, 16);
            v37 = numPoints;
          }
          for ( i = this->m_mesh.m_vertices.m_used; i; i = i->m_next )
          {
            if ( i->m_index != -1 )
            {
              if ( v37 == (v67 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v37 = numPoints;
              }
              array[v37] = i->m_source;
              v37 = ++numPoints;
            }
          }
          if ( hkgpConvexHullImpl::build(this, array, v37, 0, 0i64) == 3 )
            hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
          v5 = 1;
          numPoints = 0;
          if ( v67 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v67);
          v3 = this->m_dimensions == 3;
          array = 0i64;
          v67 = 0x80000000;
        }
        while ( v3 );
      }
      if ( config->m_removeUnreferencedVertices.m_bool && this->m_dimensions == 3 )
      {
        if ( !this->m_hasIndexing )
        {
          hkErrStream::hkErrStream(&v73, buf, 512);
          v39 = hkOstream::operator<<(&v73, "No index available (");
          v40 = hkOstream::operator<<(v39, this->m_uid);
          hkOstream::operator<<(v40, ") hkgpConvexHull::buildIndices need to be called before this operation.");
          if ( (unsigned int)hkError::messageError(
                               0x79F9D886u,
                               buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgp"
                               "ConvexHullInternals.h",
                               358) )
            __debugbreak();
          hkOstream::~hkOstream(&v73);
        }
        vpf.m_data = 0i64;
        vpf.m_capacityAndFlags = 0x80000000;
        vi.m_data = 0i64;
        vi.m_capacityAndFlags = 0x80000000;
        array = 0i64;
        v67 = 0x80000000;
        do
        {
          vpf.m_size = 0;
          vi.m_size = 0;
          numPoints = 0;
          LOBYTE(sizeElem.m_enum) = 0;
          hkgpConvexHullImpl::generateIndexedFaces<int,int>(this, &vpf, &vi, 0, sizeElem);
          m_size = vi.m_size;
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
                goto LABEL_50;
              while ( array->m_quad.m128_i32[v46] != vi.m_data[v44] )
              {
                ++v46;
                ++v45;
                if ( v46 >= v42 )
                  goto LABEL_50;
              }
              if ( v45 == -1 )
              {
LABEL_50:
                m_data = vi.m_data;
                if ( v42 == (v67 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
                  v42 = numPoints;
                }
                array->m_quad.m128_i32[v42] = m_data[v44];
                m_size = vi.m_size;
                v42 = ++numPoints;
              }
              ++v43;
              ++v44;
            }
            while ( v43 < m_size );
          }
          v48 = this->m_mesh.m_vertices.m_numUsed;
          if ( v42 >= v48 )
            break;
          v49 = 0;
          v5 = 1;
          v73.vfptr = 0i64;
          *(_DWORD *)(&v73.m_referenceCount + 1) = 0x80000000;
          points = 0i64;
          v70 = 0;
          *(_DWORD *)&v73.m_memSizeAndFlags = 0;
          v71 = 0x80000000;
          if ( v48 <= 0 )
          {
            v74.m_enum = HK_SUCCESS;
          }
          else
          {
            hkArrayUtil::_reserve(&v74, &hkContainerHeapAllocator::s_alloc, (const void **)&v73.vfptr, v48, 16);
            v42 = numPoints;
            v49 = *(_DWORD *)&v73.m_memSizeAndFlags;
          }
          m_next = this->m_mesh.m_vertices.m_used;
          vfptr = v73.vfptr;
          *(_DWORD *)&v73.m_memSizeAndFlags = v48 + v49;
          if ( m_next )
          {
            do
            {
              v52 = (hkVector4f *)vfptr++;
              *v52 = m_next->m_source;
              m_next = m_next->m_next;
            }
            while ( m_next );
            v42 = numPoints;
          }
          v53 = v42;
          if ( (v71 & 0x3FFFFFFF) >= v42 )
          {
            v72.m_enum = HK_SUCCESS;
          }
          else
          {
            if ( v42 < 2 * (v71 & 0x3FFFFFFF) )
              v42 = 2 * (v71 & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v72, &hkContainerHeapAllocator::s_alloc, (const void **)&points, v42, 16);
            v42 = numPoints;
          }
          v70 = v53;
          v54 = 0;
          if ( v42 > 0 )
          {
            v55 = 0i64;
            v56 = 0i64;
            do
            {
              ++v54;
              points[v55++] = (hkVector4f)v73.vfptr[array->m_quad.m128_i32[v56++]];
            }
            while ( v54 < numPoints );
            v53 = v70;
          }
          if ( hkgpConvexHullImpl::build(this, points, v53, 0, 0i64) == 3 )
            hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
          v70 = 0;
          if ( v71 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, points, 16 * v71);
          points = 0i64;
          v71 = 0x80000000;
          *(_DWORD *)&v73.m_memSizeAndFlags = 0;
          if ( *(int *)(&v73.m_referenceCount + 1) >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v73.vfptr,
              16 * *(_DWORD *)(&v73.m_referenceCount + 1));
          v3 = this->m_dimensions == 3;
          v73.vfptr = 0i64;
          *(_DWORD *)(&v73.m_referenceCount + 1) = 0x80000000;
        }
        while ( v3 );
        numPoints = 0;
        if ( v67 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v67);
        array = 0i64;
        v67 = 0x80000000;
        vi.m_size = 0;
        if ( vi.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            vi.m_data,
            4 * vi.m_capacityAndFlags);
        vi.m_data = 0i64;
        vi.m_capacityAndFlags = 0x80000000;
        vpf.m_size = 0;
        if ( vpf.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            vpf.m_data,
            4 * vpf.m_capacityAndFlags);
      }
      if ( v5 && this->m_dimensions == 3 )
      {
        v57 = this->m_mesh.m_vertices.m_numUsed;
        v58 = 0i64;
        v59 = 0;
        vi.m_size = 0;
        vi.m_capacityAndFlags = 0x80000000;
        vi.m_data = 0i64;
        if ( v57 > 0 )
        {
          hkArrayUtil::_reserve(&v72, &hkContainerHeapAllocator::s_alloc, (const void **)&vi.m_data, v57, 16);
          v59 = vi.m_size;
          v58 = (hkVector4f *)vi.m_data;
        }
        v60 = this->m_mesh.m_vertices.m_used;
        v61 = v57 + v59;
        vi.m_size = v61;
        if ( v60 )
        {
          do
          {
            v62 = v58++;
            *v62 = v60->m_source;
            v60 = v60->m_next;
          }
          while ( v60 );
          v61 = vi.m_size;
          v58 = (hkVector4f *)vi.m_data;
        }
        hkgpConvexHullImpl::build(this, v58, v61, 0, 0i64);
        if ( LOBYTE(v77.m_enum) )
          hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
        if ( m_hasMassProperties )
          hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this, &v77);
        vi.m_size = 0;
        if ( vi.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            vi.m_data,
            16 * vi.m_capacityAndFlags);
      }
      goto LABEL_96;
    }
LABEL_97:
    result->m_enum = HK_FAILURE;
    return result;
  }
LABEL_96:
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 1405
// RVA: 0xCB7DE0
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::maxDistance(
        hkgpConvexHullImpl *this,
        hkSimdFloat32 *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points,
        hkVector4f *planeOut)
{
  int m_dimensions; // r10d
  int v6; // r10d
  hkgpConvexHullImpl::Triangle *m_used; // rax
  char *v8; // rcx
  int m_size; // ebx
  int v10; // r11d
  __m128 m_quad; // xmm5
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
  hkgpConvexHullImpl::Vertex *m_next; // r11
  hkgpConvexHullImpl::Vertex *v32; // rax
  hkgpConvexHullImpl::Vertex *i; // rcx
  __m128 v34; // xmm8
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  int v43; // r10d
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __int64 v46; // rcx
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm4
  hkVector4f v52; // xmm1
  char v54; // [rsp+60h] [rbp+8h] BYREF

  m_dimensions = this->m_dimensions;
  *result = (hkSimdFloat32)xmmword_141A712F0;
  v6 = m_dimensions - 2;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      m_used = this->m_mesh.m_triangles.m_used;
      v8 = &v54;
      if ( !m_used )
        v8 = 0i64;
      if ( v8 )
      {
        m_size = points->m_size;
        do
        {
          v10 = 0;
          m_quad = m_used->m_vertices[0]->m_source.m_quad;
          v12 = _mm_sub_ps(m_used->m_vertices[1]->m_source.m_quad, m_quad);
          v13 = _mm_sub_ps(m_used->m_vertices[2]->m_source.m_quad, m_quad);
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
                    _mm_cmple_ps(v17, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                      _mm_mul_ps(*(__m128 *)_xmm, v18))),
                  v15);
          v20 = _mm_mul_ps(m_quad, v19);
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
          if ( m_size > 0 )
          {
            v22 = 0i64;
            do
            {
              ++v10;
              v23 = _mm_mul_ps(points->m_data[v22++].m_quad, v21);
              v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v21), 196);
              v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
              v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
              v27 = _mm_cmplt_ps(result->m_real, v26);
              v28 = _mm_and_ps(v27, v26);
              v29 = _mm_andnot_ps(v27, planeOut->m_quad);
              result->m_real = _mm_or_ps(_mm_andnot_ps(v27, result->m_real), v28);
              planeOut->m_quad = _mm_or_ps(v29, _mm_and_ps(v21, v27));
              m_size = points->m_size;
            }
            while ( v10 < m_size );
          }
          m_used = m_used->m_next;
          v30 = &v54;
          if ( !m_used )
            v30 = 0i64;
        }
        while ( v30 );
      }
    }
  }
  else
  {
    m_next = this->m_mesh.m_vertices.m_used;
    v32 = m_next;
    if ( m_next )
    {
      for ( i = m_next->m_next; i; i = i->m_next )
        v32 = i;
      do
      {
        v34 = v32->m_source.m_quad;
        v35 = _mm_sub_ps(m_next->m_source.m_quad, v34);
        v36 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), this->m_projectionPlane.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(this->m_projectionPlane.m_quad, this->m_projectionPlane.m_quad, 201), v35));
        v37 = _mm_shuffle_ps(v36, v36, 201);
        v38 = _mm_mul_ps(v37, v37);
        v39 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170));
        v40 = _mm_rsqrt_ps(v39);
        v41 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v39), (__m128)0i64);
        v42 = _mm_or_ps(
                _mm_and_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v39, (__m128)0i64),
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
              v47 = _mm_mul_ps(points->m_data[v46++].m_quad, v45);
              v48 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v45), 196);
              v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 78), v48);
              v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v49);
              v51 = _mm_cmplt_ps(result->m_real, v50);
              v52.m_quad = _mm_or_ps(_mm_andnot_ps(v51, planeOut->m_quad), _mm_and_ps(v45, v51));
              result->m_real = _mm_or_ps(_mm_and_ps(v51, v50), _mm_andnot_ps(v51, result->m_real));
              *planeOut = (hkVector4f)v52.m_quad;
            }
            while ( v43 < points->m_size );
          }
        }
        v32 = m_next;
        m_next = m_next->m_next;
      }
      while ( m_next );
    }
  }
  return result;
}

// File Line: 1468
// RVA: 0xCB84C0
void __fastcall hkgpConvexHullImpl::refitDomainFromSources(hkgpConvexHullImpl *this)
{
  int m_numUsed; // edi
  hkVector4f *v2; // rdx
  int v4; // r8d
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  int v6; // r8d
  hkVector4f *v7; // rax
  hkgpConvexHullImpl::Vertex *m_next; // rax
  hkResult *v9; // rcx
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128i v17; // xmm1
  hkResult *v18; // rcx
  hkVector4f *points; // [rsp+30h] [rbp-78h] BYREF
  int numPoints; // [rsp+38h] [rbp-70h]
  int v21; // [rsp+3Ch] [rbp-6Ch]
  __int64 v22; // [rsp+60h] [rbp-48h]
  unsigned int v23; // [rsp+68h] [rbp-40h]
  hkResult v24; // [rsp+B0h] [rbp+8h] BYREF

  m_numUsed = this->m_mesh.m_vertices.m_numUsed;
  v2 = 0i64;
  points = 0i64;
  v4 = 0;
  numPoints = 0;
  v21 = 0x80000000;
  if ( m_numUsed > 0 )
  {
    hkArrayUtil::_reserve(&v24, &hkContainerHeapAllocator::s_alloc, (const void **)&points, m_numUsed, 16);
    v4 = numPoints;
    v2 = points;
  }
  m_used = this->m_mesh.m_vertices.m_used;
  v6 = m_numUsed + v4;
  numPoints = v6;
  if ( m_used )
  {
    do
    {
      v7 = v2++;
      *v7 = m_used->m_source;
      m_used = m_used->m_next;
    }
    while ( m_used );
    v6 = numPoints;
    v2 = points;
  }
  hkgpConvexHullImpl::rebuildDomainParameters(this, v2, v6);
  m_next = this->m_mesh.m_vertices.m_used;
  v9 = &v24;
  if ( !m_next )
    v9 = 0i64;
  if ( v9 )
  {
    do
    {
      v10 = _mm_mul_ps(_mm_sub_ps(m_next->m_source.m_quad, this->m_origin.m_quad), this->m_scale.m_quad);
      v11 = _mm_cmplt_ps(v10, (__m128)_xmm);
      v12 = _mm_max_ps(
              (__m128)_xmm_c6000000c6000000c6000000c6000000,
              _mm_or_ps(_mm_andnot_ps(v11, (__m128)_xmm), _mm_and_ps(v10, v11)));
      v13 = _mm_sub_ps(v12, (__m128)xmmword_141A711B0);
      v14 = _mm_add_ps(v12, (__m128)xmmword_141A711B0);
      v15 = _mm_cmplt_ps(v12, (__m128)0i64);
      v16 = _mm_or_ps(_mm_andnot_ps(v15, v14), _mm_and_ps(v13, v15));
      v17 = _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v16),
              _mm_cvttps_epi32(v16));
      v22 = v17.m128i_i64[0];
      m_next->m_x[0] = v17.m128i_i32[0];
      m_next->m_x[1] = HIDWORD(v22);
      v23 = _mm_shuffle_epi32(v17, 170).m128i_u32[0];
      m_next->m_x[2] = v23;
      m_next = m_next->m_next;
      v18 = &v24;
      if ( !m_next )
        v18 = 0i64;
    }
    while ( v18 );
  }
  numPoints = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, points, 16 * v21);
}

// File Line: 1491
// RVA: 0xCB5FB0
hkBool *__fastcall hkgpConvexHullImpl::ensureContainment(
        hkgpConvexHullImpl *this,
        hkBool *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  hkVector4f *v3; // rsi
  int m_size; // eax
  __int32 v8; // ebp
  __int64 v9; // r10
  __int64 v10; // rdx
  hkVector4f *v11; // rcx
  char *v12; // r8
  hkVector4f v13; // xmm0
  hkVector4f *v14; // rdx
  __int64 v15; // r9
  __int64 v16; // rcx
  __m128 m_quad; // xmm4
  __m128 v18; // xmm3
  hkVector4f *m_data; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  bool m_hasMassProperties; // r14
  bool m_hasIndexing; // bl
  int v26; // eax
  bool v27; // r12
  bool v28; // r13
  float v29; // xmm8_4
  char v30; // r14
  int v31; // ebp
  hkgpConvexHullImpl::Vertex *m_used; // rax
  __m128 *m_next; // rcx
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
  hkVector4f planeOut; // [rsp+20h] [rbp-A8h] BYREF
  hkSimdFloat32 v64; // [rsp+30h] [rbp-98h] BYREF
  hkResult v65; // [rsp+D0h] [rbp+8h] BYREF
  hkResult resulta; // [rsp+E8h] [rbp+20h] BYREF

  v3 = 0i64;
  if ( this->m_dimensions == 3 )
  {
    m_size = this->m_planes.m_size;
    v8 = 0x80000000;
    if ( m_size > 0 )
    {
      v65.m_enum = 16 * m_size;
      v3 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v65);
      v8 = v65.m_enum / 16;
    }
    v9 = (unsigned int)this->m_planes.m_size;
    v10 = (int)v9;
    if ( (int)v9 > 0 )
    {
      v11 = v3;
      v12 = (char *)((char *)this->m_planes.m_data - (char *)v3);
      do
      {
        v13.m_quad = *(__m128 *)((char *)v11++ + (_QWORD)v12);
        v11[-1] = (hkVector4f)v13.m_quad;
        --v10;
      }
      while ( v10 );
      v14 = v3;
      v15 = v9;
      do
      {
        v16 = points->m_size;
        m_quad = v14->m_quad;
        v18 = 0i64;
        if ( v16 > 0 )
        {
          m_data = points->m_data;
          do
          {
            ++m_data;
            v20 = _mm_mul_ps(m_quad, m_data[-1].m_quad);
            v21 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, m_quad), 196);
            v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
            v18 = _mm_max_ps(aabbOut.m_quad, _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22));
            --v16;
          }
          while ( v16 );
        }
        v23 = v14->m_quad;
        ++v14;
        v14[-1].m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, _mm_sub_ps(_mm_shuffle_ps(v23, v23, 255), v18)), 196);
        --v15;
      }
      while ( v15 );
    }
    m_hasMassProperties = this->m_hasMassProperties;
    m_hasIndexing = this->m_hasIndexing;
    hkgpConvexHull::buildFromPlanes(this->m_hull, v3, v9, &this->m_config);
    if ( m_hasIndexing )
      hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
    if ( m_hasMassProperties )
      hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this, &resulta);
    result->m_bool = 1;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v3, 16 * v8);
  }
  else
  {
    v26 = points->m_size;
    v27 = this->m_hasMassProperties;
    v28 = this->m_hasIndexing;
    v65.m_enum = LODWORD(FLOAT_0_0000099999997);
    LODWORD(v29) = _mm_shuffle_ps((__m128)(unsigned int)v65.m_enum, (__m128)(unsigned int)v65.m_enum, 0).m128_u32[0];
    v30 = 0;
    v31 = 0;
    if ( 2 * v26 > 0 )
    {
      while ( 1 )
      {
        planeOut.m_quad = 0i64;
        hkgpConvexHullImpl::maxDistance(this, &v64, points, &planeOut);
        if ( COERCE_FLOAT((unsigned int)(2 * v64.m_real.m128_i32[0]) >> 1) <= v29 )
          break;
        m_used = this->m_mesh.m_vertices.m_used;
        m_next = (__m128 *)m_used->m_next;
        v34 = (__m128 *)m_used;
        v35 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), planeOut.m_quad);
        v36 = _mm_mul_ps(m_used->m_source.m_quad, v35);
        v37 = (float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
            + _mm_shuffle_ps(v36, v36, 170).m128_f32[0];
        if ( m_used->m_next )
        {
          do
          {
            v38 = _mm_mul_ps(m_next[1], v35);
            v39 = (float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0] + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                + _mm_shuffle_ps(v38, v38, 170).m128_f32[0];
            if ( v39 > v37 )
            {
              v34 = m_next;
              v37 = v39;
            }
            m_next = (__m128 *)m_next->m128_u64[0];
          }
          while ( m_next );
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
        if ( !m_used )
          v54 = 0i64;
        v55 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v53, v49)), v53), v52);
        if ( v54 )
        {
          do
          {
            v56 = m_used->m_source.m_quad;
            v57 = &v65;
            v58 = _mm_mul_ps(v44, v56);
            v59 = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, v44), 196);
            v60 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
            v61 = _mm_add_ps(
                    _mm_sub_ps(v56, _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60), v44)),
                    _mm_mul_ps(_mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60), v55), v44));
            m_used->m_source.m_quad = _mm_shuffle_ps(
                                        v61,
                                        _mm_unpackhi_ps(
                                          v61,
                                          _mm_shuffle_ps(m_used->m_source.m_quad, m_used->m_source.m_quad, 255)),
                                        196);
            m_used = m_used->m_next;
            if ( !m_used )
              v57 = 0i64;
          }
          while ( v57 );
        }
        ++v31;
        v30 = 1;
        if ( v31 >= 2 * points->m_size )
          goto LABEL_34;
      }
      if ( !v30 )
        goto LABEL_38;
LABEL_34:
      hkgpConvexHullImpl::refitDomainFromSources(this);
      if ( v28 )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
      if ( v27 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this, &v65);
    }
LABEL_38:
    result->m_bool = 1;
  }
  return result;
}pConvexHullImpl::PositionAsTransform>(this);
      if ( v27 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransfo

// File Line: 1569
// RVA: 0xCB4E90
char __fastcall hkgpConvexHullImpl::decimateVertices(
        hkgpConvexHullImpl *this,
        int numVerticesToKeep,
        bool containment,
        bool useCgo)
{
  bool v4; // di
  int v5; // r12d
  hkgpConvexHull *m_hull; // rbx
  bool v8; // si
  bool v9; // r14
  int Dimensions; // edi
  hkgpConvexHull *v11; // rbx
  hkgpConvexHullImpl *Configuration; // rax
  int v13; // ecx
  char m_enum; // bl
  bool v16; // zf
  int v17; // eax
  int m_numUsed; // ebx
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  hkVector4f *v20; // rdx
  hkVector4f *v21; // rax
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  int v24; // r9d
  bool v25; // al
  bool v26; // al
  int v27; // r9d
  int v28; // ebx
  int v29; // eax
  int v30; // ecx
  int v31; // r9d
  hkgpConvexHullImpl::Vertex *v32; // rcx
  hkVector4f *v33; // rdx
  hkVector4f *v34; // rax
  hkgpConvexHullImpl::Vertex *v35; // rax
  hkgpConvexHullImpl::Triangle *v36; // r14
  int k; // esi
  float v38; // xmm9_4
  __int64 v39; // rbx
  hkVector4f v40; // xmm6
  hkVector4f v41; // xmm7
  char v42; // di
  unsigned int *v43; // rcx
  unsigned int *v44; // rax
  __m128i v45; // xmm8
  unsigned int *v46; // rcx
  __m128 v47; // xmm8
  __m128i v48; // xmm4
  unsigned int *v49; // rcx
  __m128i v50; // xmm3
  __int64 v51; // rax
  unsigned __int64 v52; // rdx
  unsigned __int64 v53; // rdx
  __int64 v54; // rdi
  hkVector4f v55; // xmm6
  hkVector4f v56; // xmm7
  __int64 v57; // rbx
  unsigned int *v58; // rcx
  unsigned int *v59; // rax
  __m128i v60; // xmm8
  unsigned int *v61; // rcx
  __m128 v62; // xmm8
  __m128i v63; // xmm4
  unsigned int *v64; // rcx
  __m128i v65; // xmm3
  __int64 v66; // rdx
  int v67; // r8d
  hkgpConvexHullImpl::SortedEdge *v68; // rcx
  unsigned __int64 v69; // rdx
  __int64 v70; // rax
  hkgpConvexHullImpl::Vertex *m; // rax
  int v72; // r14d
  __int64 v73; // rsi
  int v74; // eax
  __int64 v75; // r12
  __int64 v76; // rdi
  char v77; // r10
  hkgpConvexHullImpl::Vertex *v78; // rdx
  hkgpConvexHullImpl::Triangle *m_triangle; // r11
  __int64 m_index; // rbx
  const float *m_vertices; // r9
  char v82; // cl
  __int64 v83; // rdx
  float v84; // xmm0_4
  __int64 v85; // rax
  unsigned __int64 v86; // rdx
  unsigned __int64 v87; // rdx
  const float *v88; // rdx
  __int64 m_numVertices; // r8
  __int64 v90; // rcx
  float v91; // xmm0_4
  __int64 v92; // rcx
  __int64 v93; // rdi
  __int64 v94; // rbx
  hkgpConvexHullImpl::Vertex *v95; // rdx
  hkgpConvexHullImpl::Vertex *v96; // rax
  hkgpConvexHullImpl::Vertex *m_prev; // rcx
  hkgpConvexHullImpl::Vertex *v98; // rdx
  hkgpConvexHullImpl::Vertex *v99; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v100; // rax
  unsigned __int64 v101; // rcx
  int v102; // ebx
  hkVector4f *v103; // rdx
  int v104; // r8d
  hkgpConvexHullImpl::Vertex *v105; // rcx
  int v106; // r8d
  hkVector4f *v107; // rax
  hkVector4f *v108; // rdx
  hkOstream *v109; // rax
  hkOstream *v110; // rax
  bool m_hasIndexing; // r14
  int v112; // ecx
  hkVector4f *v113; // r8
  hkgpConvexHullImpl::Vertex *m_next; // rbx
  float v115; // xmm6_4
  int v116; // edi
  hkResult *p_result; // rax
  hkResult *v118; // rax
  int v119; // r11d
  int v120; // edx
  __int64 v121; // r9
  __int64 v122; // r10
  __int64 v123; // rax
  __m128 v124; // xmm0
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm3
  __m128 v128; // xmm3
  __m128 v129; // xmm3
  __m128 v130; // xmm4
  __m128 v131; // xmm2
  float v132; // xmm3_4
  bool v133; // [rsp+30h] [rbp-D0h]
  bool m_hasMassProperties; // [rsp+30h] [rbp-D0h]
  hkVector4f *v135; // [rsp+38h] [rbp-C8h] BYREF
  int numPoints; // [rsp+40h] [rbp-C0h]
  int v137; // [rsp+44h] [rbp-BCh]
  bool v138; // [rsp+48h] [rbp-B8h]
  hkgpConvexHullImpl::SortedEdge *pArr; // [rsp+50h] [rbp-B0h] BYREF
  int j; // [rsp+58h] [rbp-A8h]
  int v141; // [rsp+5Ch] [rbp-A4h]
  hkgpConvexHull::BuildConfig array; // [rsp+60h] [rbp-A0h] BYREF
  hkStridedVertices points; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f *v144; // [rsp+80h] [rbp-80h] BYREF
  int i; // [rsp+88h] [rbp-78h]
  int v146; // [rsp+8Ch] [rbp-74h]
  hkResult result; // [rsp+90h] [rbp-70h] BYREF
  __int128 v148; // [rsp+A0h] [rbp-60h]
  hkResult v149; // [rsp+B0h] [rbp-50h] BYREF
  hkResult v150; // [rsp+B4h] [rbp-4Ch] BYREF
  hkGeometry geometry; // [rsp+B8h] [rbp-48h] BYREF
  hkResult v152; // [rsp+E8h] [rbp-18h] BYREF
  hkgpCgo::Config config; // [rsp+F0h] [rbp-10h] BYREF
  hkVector4f plane; // [rsp+140h] [rbp+40h] BYREF
  __int128 v155; // [rsp+150h] [rbp+50h]
  hkStridedVertices v156; // [rsp+160h] [rbp+60h]
  __int128 v157; // [rsp+170h] [rbp+70h]
  hkStridedVertices v158; // [rsp+180h] [rbp+80h]
  hkStridedVertices v159; // [rsp+190h] [rbp+90h]
  __int128 v160; // [rsp+1A0h] [rbp+A0h]
  __int128 v161; // [rsp+1B0h] [rbp+B0h]
  hkSimdFloat32 v162; // [rsp+1C0h] [rbp+C0h] BYREF
  hkSimdFloat32 v163; // [rsp+1D0h] [rbp+D0h] BYREF
  char buf[512]; // [rsp+1E0h] [rbp+E0h] BYREF
  int v165; // [rsp+488h] [rbp+388h]
  hkResult v167; // [rsp+498h] [rbp+398h] BYREF

  v165 = numVerticesToKeep;
  v4 = containment;
  v5 = numVerticesToKeep;
  if ( !useCgo )
  {
    v16 = this->m_dimensions == -1;
    *(_DWORD *)&array.m_internalInputs.m_bool = 0x80000000;
    m_enum = !v16;
    v17 = 0;
    LOBYTE(v167.m_enum) = !v16;
    *(_QWORD *)&array.m_allowLowerDimensions.m_bool = 0i64;
    *(_DWORD *)&array.m_setSourceIndices.m_bool = 0;
    if ( containment )
    {
      m_numUsed = this->m_mesh.m_vertices.m_numUsed;
      if ( m_numUsed > 0 )
      {
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&array,
          this->m_mesh.m_vertices.m_numUsed,
          16);
        v17 = *(_DWORD *)&array.m_setSourceIndices.m_bool;
      }
      m_used = this->m_mesh.m_vertices.m_used;
      v20 = *(hkVector4f **)&array.m_allowLowerDimensions.m_bool;
      for ( *(_DWORD *)&array.m_setSourceIndices.m_bool = m_numUsed + v17; m_used; m_used = m_used->m_next )
      {
        v21 = v20++;
        *v21 = m_used->m_source;
      }
      m_enum = v167.m_enum;
    }
    if ( this->m_dimensions == 2 )
    {
      if ( v5 < 3 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&geometry, buf, 512);
        v109 = hkOstream::operator<<((hkOstream *)&geometry, "The number of vertices requested(");
        v110 = hkOstream::operator<<(v109, v5);
        hkOstream::operator<<(v110, ") is less than 3.");
        hkError::messageWarning(
          0xC25BDDE7,
          buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
          1700);
        hkOstream::~hkOstream((hkOstream *)&geometry);
        v5 = 3;
        v165 = 3;
      }
      if ( this->m_mesh.m_vertices.m_numUsed <= v5 )
        goto LABEL_143;
      m_hasIndexing = this->m_hasIndexing;
      v112 = 0;
      m_hasMassProperties = this->m_hasMassProperties;
      v113 = 0i64;
      v135 = 0i64;
      numPoints = 0;
      v137 = 0x80000000;
      while ( 1 )
      {
        m_next = this->m_mesh.m_vertices.m_used;
        v115 = 3.40282e38;
        v116 = -1;
        p_result = &result;
        if ( !m_next )
          p_result = 0i64;
        if ( p_result )
        {
          do
          {
            if ( v112 == (v137 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v135, 8);
              v112 = numPoints;
              v113 = v135;
            }
            v113->m_quad.m128_u64[v112] = (unsigned __int64)m_next;
            v112 = ++numPoints;
            if ( m_next )
              m_next = m_next->m_next;
            v113 = v135;
            v118 = &result;
            if ( !m_next )
              v118 = 0i64;
          }
          while ( v118 );
        }
        v119 = v112 - 1;
        v120 = 0;
        if ( v112 > 0 )
        {
          v121 = 0i64;
          v122 = 8i64 * v119;
          v123 = 8i64 * (v112 - 2);
          do
          {
            v124 = *(__m128 *)(*(unsigned __int64 *)((char *)v113->m_quad.m128_u64 + v123) + 16);
            v125 = _mm_sub_ps(*(__m128 *)(*(unsigned __int64 *)((char *)v113->m_quad.m128_u64 + v122) + 16), v124);
            v126 = _mm_sub_ps(*(__m128 *)(v113->m_quad.m128_u64[v121] + 16), v124);
            v127 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v125),
                     _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), v126));
            v128 = _mm_shuffle_ps(v127, v127, 201);
            v129 = _mm_mul_ps(v128, v128);
            v130 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                     _mm_shuffle_ps(v129, v129, 170));
            v131 = _mm_rsqrt_ps(v130);
            v132 = _mm_andnot_ps(
                     _mm_cmple_ps(v130, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v131, v130), v131)),
                         _mm_mul_ps(v131, *(__m128 *)_xmm)),
                       v130)).m128_f32[0];
            if ( v132 < v115 )
            {
              v115 = v132;
              v116 = v119;
            }
            v119 = v120;
            v123 = v122;
            ++v120;
            v122 = v121 * 8;
            ++v121;
          }
          while ( v120 < v112 );
        }
        hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>>::release(
          &this->m_mesh.m_vertices,
          (hkgpConvexHullImpl::Vertex *)v113->m_quad.m128_u64[v116]);
        v112 = 0;
        numPoints = 0;
        if ( this->m_mesh.m_vertices.m_numUsed <= v165 )
          break;
        v113 = v135;
      }
      hkgpConvexHullImpl::refitDomainFromSources(this);
      m_enum = v167.m_enum;
      if ( LOBYTE(v167.m_enum) && containment )
        hkgpConvexHullImpl::ensureContainment(
          this,
          (hkBool *)&v167,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
      if ( m_hasIndexing )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
      if ( m_hasMassProperties )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this, &v167);
      numPoints = 0;
      if ( v137 < 0 )
        goto LABEL_143;
      v108 = v135;
    }
    else
    {
      if ( this->m_dimensions != 3 )
        goto LABEL_143;
      if ( v5 < 4 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&geometry, buf, 512);
        v22 = hkOstream::operator<<((hkOstream *)&geometry, "The number of vertices requested(");
        v23 = hkOstream::operator<<(v22, v5);
        hkOstream::operator<<(v23, ") is less than 4.");
        hkError::messageWarning(
          0xC25BDDE6,
          buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
          1622);
        hkOstream::~hkOstream((hkOstream *)&geometry);
        v5 = 4;
        v165 = 4;
      }
      v24 = this->m_mesh.m_vertices.m_numUsed;
      if ( v24 <= v5 )
        goto LABEL_143;
      v25 = this->m_hasIndexing;
      v144 = 0i64;
      i = 0;
      v138 = v25;
      v26 = this->m_hasMassProperties;
      v146 = 0x80000000;
      v133 = v26;
      if ( v24 <= 0 )
        v149.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v149, &hkContainerHeapAllocator::s_alloc, (const void **)&v144, v24, 16);
      v27 = this->m_mesh.m_vertices.m_numUsed;
      pArr = 0i64;
      j = 0;
      v141 = 0x80000000;
      if ( v27 <= 0 )
        v150.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, (const void **)&pArr, v27, 24);
      v28 = this->m_mesh.m_vertices.m_numUsed;
      if ( v28 <= v5 )
      {
LABEL_99:
        m_enum = v167.m_enum;
        if ( LOBYTE(v167.m_enum) && v4 )
          hkgpConvexHullImpl::ensureContainment(
            this,
            (hkBool *)&v167,
            (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
      }
      else
      {
        while ( 1 )
        {
          v29 = 0;
          v30 = v146 & 0x3FFFFFFF;
          i = 0;
          if ( (v146 & 0x3FFFFFFF) >= v28 )
          {
            v152.m_enum = HK_SUCCESS;
          }
          else
          {
            v31 = v28;
            if ( v28 < 2 * v30 )
              v31 = 2 * v30;
            hkArrayUtil::_reserve(&v152, &hkContainerHeapAllocator::s_alloc, (const void **)&v144, v31, 16);
            v29 = i;
          }
          v32 = this->m_mesh.m_vertices.m_used;
          v33 = v144;
          for ( i = v28 + v29; v32; v32 = v32->m_next )
          {
            v34 = v33++;
            *v34 = v32->m_source;
          }
          v35 = this->m_mesh.m_vertices.m_used;
          for ( j = 0; v35; v35 = v35->m_next )
            v35->m_scratch = 0.0;
          v36 = this->m_mesh.m_triangles.m_used;
          if ( v36 )
          {
            do
            {
              for ( k = 0; k < 3; ++k )
              {
                *(_DWORD *)&geometry.m_memSizeAndFlags = k;
                if ( v36->m_vertices[k]->m_scratch == 0.0 )
                {
                  *(_QWORD *)&v155 = v36;
                  DWORD2(v155) = k;
                  v148 = v155;
                  v38 = 0.0;
                  while ( 1 )
                  {
                    v39 = v148;
                    v40.m_quad = (__m128)this->m_scaleInv;
                    v41.m_quad = (__m128)this->m_origin;
                    v42 = 2 * BYTE8(v148);
                    v43 = *(unsigned int **)(v148 + 8 * ((9i64 >> (2 * BYTE8(v148))) & 3) + 16);
                    v44 = *(unsigned int **)(v148 + 8i64 * SDWORD2(v148) + 16);
                    v45 = _mm_slli_si128(
                            (__m128i)_mm_cvtepi32_ps(
                                       _mm_unpacklo_epi32(
                                         _mm_unpacklo_epi32(_mm_cvtsi32_si128(v43[8]), _mm_cvtsi32_si128(v43[10])),
                                         _mm_unpacklo_epi32(_mm_cvtsi32_si128(v43[9]), _mm_cvtsi32_si128(0)))),
                            4);
                    v46 = *(unsigned int **)(v148 + 8 * ((18i64 >> (2 * BYTE8(v148))) & 3) + 16);
                    v47 = _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_si128(v45, 4), v40.m_quad), v41.m_quad);
                    v48 = _mm_unpacklo_epi32(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v46[8]), _mm_cvtsi32_si128(v46[10])),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v46[9]), _mm_cvtsi32_si128(0)));
                    v49 = *(unsigned int **)((*(_QWORD *)(v148 + 8i64 * SDWORD2(v148) + 40) & 0xFFFFFFFFFFFFFFFCui64)
                                           + 8
                                           * ((18i64 >> (2
                                                       * ((unsigned __int8)*(_QWORD *)(v148 + 8i64 * SDWORD2(v148) + 40) & 3u))) & 3)
                                           + 16);
                    v50 = _mm_unpacklo_epi32(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v49[8]), _mm_cvtsi32_si128(v49[10])),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v49[9]), _mm_cvtsi32_si128(0)));
                    *(__m128 *)&config.m_semantic = _mm_sub_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          (__m128)_mm_srli_si128(
                                                                    _mm_slli_si128(
                                                                      (__m128i)_mm_cvtepi32_ps(
                                                                                 _mm_unpacklo_epi32(
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_cvtsi32_si128(v44[8]),
                                                                                     _mm_cvtsi32_si128(v44[10])),
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_cvtsi32_si128(v44[9]),
                                                                                     _mm_cvtsi32_si128(0)))),
                                                                      4),
                                                                    4),
                                                          v40.m_quad),
                                                        v41.m_quad),
                                                      v47);
                    *(__m128 *)&config.m_maxAngle = _mm_sub_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          (__m128)_mm_srli_si128(
                                                                    _mm_slli_si128((__m128i)_mm_cvtepi32_ps(v48), 4),
                                                                    4),
                                                          v40.m_quad),
                                                        v41.m_quad),
                                                      v47);
                    *(__m128 *)&config.m_updateThreshold = _mm_sub_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(
                                                                 (__m128)_mm_srli_si128(
                                                                           _mm_slli_si128(
                                                                             (__m128i)_mm_cvtepi32_ps(v50),
                                                                             4),
                                                                           4),
                                                                 v40.m_quad),
                                                               v41.m_quad),
                                                             v47);
                    hkMatrix3f::getDeterminant((hkMatrix3f *)&config, &v162);
                    v38 = v38 + v162.m_real.m128_f32[0];
                    v51 = *(_QWORD *)(v39 + 8i64 * ((18 >> v42) & 3) + 40) & 3i64;
                    v52 = *(_QWORD *)(v39 + 8i64 * ((18 >> v42) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    *(_QWORD *)&v157 = v52;
                    DWORD2(v157) = v51;
                    v148 = v157;
                    if ( !v52 )
                      break;
                    if ( (hkgpConvexHullImpl::Triangle *)(v52 + v51) == (hkgpConvexHullImpl::Triangle *)((char *)v36 + (unsigned int)k) )
                      goto LABEL_49;
                  }
                  v53 = v36->m_links[k];
                  *(_QWORD *)&v161 = v53 & 0xFFFFFFFFFFFFFFFCui64;
                  DWORD2(v161) = (9 >> (2 * (v53 & 3))) & 3;
                  v148 = v161;
                  if ( (v53 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                  {
                    do
                    {
                      v54 = v148;
                      v55.m_quad = (__m128)this->m_scaleInv;
                      v56.m_quad = (__m128)this->m_origin;
                      v57 = SDWORD2(v148);
                      v58 = *(unsigned int **)(v148 + 8 * ((9i64 >> (2 * BYTE8(v148))) & 3) + 16);
                      v59 = *(unsigned int **)(v148 + 8i64 * SDWORD2(v148) + 16);
                      v60 = _mm_slli_si128(
                              (__m128i)_mm_cvtepi32_ps(
                                         _mm_unpacklo_epi32(
                                           _mm_unpacklo_epi32(_mm_cvtsi32_si128(v58[8]), _mm_cvtsi32_si128(v58[10])),
                                           _mm_unpacklo_epi32(_mm_cvtsi32_si128(v58[9]), _mm_cvtsi32_si128(0)))),
                              4);
                      v61 = *(unsigned int **)(v148 + 8 * ((18i64 >> (2 * BYTE8(v148))) & 3) + 16);
                      v62 = _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_si128(v60, 4), v55.m_quad), v56.m_quad);
                      v63 = _mm_unpacklo_epi32(
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v61[8]), _mm_cvtsi32_si128(v61[10])),
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v61[9]), _mm_cvtsi32_si128(0)));
                      v64 = *(unsigned int **)((*(_QWORD *)(v148 + 8i64 * SDWORD2(v148) + 40) & 0xFFFFFFFFFFFFFFFCui64)
                                             + 8
                                             * ((18i64 >> (2
                                                         * ((unsigned __int8)*(_QWORD *)(v148 + 8i64 * SDWORD2(v148) + 40) & 3u))) & 3)
                                             + 16);
                      v65 = _mm_unpacklo_epi32(
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v64[8]), _mm_cvtsi32_si128(v64[10])),
                              _mm_unpacklo_epi32(_mm_cvtsi32_si128(v64[9]), _mm_cvtsi32_si128(0)));
                      *(__m128 *)&config.m_semantic = _mm_sub_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(
                                                            (__m128)_mm_srli_si128(
                                                                      _mm_slli_si128(
                                                                        (__m128i)_mm_cvtepi32_ps(
                                                                                   _mm_unpacklo_epi32(
                                                                                     _mm_unpacklo_epi32(
                                                                                       _mm_cvtsi32_si128(v59[8]),
                                                                                       _mm_cvtsi32_si128(v59[10])),
                                                                                     _mm_unpacklo_epi32(
                                                                                       _mm_cvtsi32_si128(v59[9]),
                                                                                       _mm_cvtsi32_si128(0)))),
                                                                        4),
                                                                      4),
                                                            v55.m_quad),
                                                          v56.m_quad),
                                                        v62);
                      *(__m128 *)&config.m_maxAngle = _mm_sub_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(
                                                            (__m128)_mm_srli_si128(
                                                                      _mm_slli_si128((__m128i)_mm_cvtepi32_ps(v63), 4),
                                                                      4),
                                                            v55.m_quad),
                                                          v56.m_quad),
                                                        v62);
                      *(__m128 *)&config.m_updateThreshold = _mm_sub_ps(
                                                               _mm_add_ps(
                                                                 _mm_mul_ps(
                                                                   (__m128)_mm_srli_si128(
                                                                             _mm_slli_si128(
                                                                               (__m128i)_mm_cvtepi32_ps(v65),
                                                                               4),
                                                                             4),
                                                                   v55.m_quad),
                                                                 v56.m_quad),
                                                               v62);
                      hkMatrix3f::getDeterminant((hkMatrix3f *)&config, &v163);
                      v38 = v38 + v163.m_real.m128_f32[0];
                      v66 = *(_QWORD *)(v54 + 8 * v57 + 40);
                      *(_QWORD *)&v160 = v66 & 0xFFFFFFFFFFFFFFFCui64;
                      DWORD2(v160) = (9 >> (2 * (v66 & 3))) & 3;
                      v148 = v160;
                    }
                    while ( (v66 & 0xFFFFFFFFFFFFFFFCui64) != 0 );
                  }
LABEL_49:
                  v67 = j;
                  if ( j == (v141 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pArr, 24);
                    v67 = j;
                  }
                  v68 = pArr;
                  v69 = v67;
                  v70 = *(_QWORD *)&geometry.m_memSizeAndFlags;
                  j = v67 + 1;
                  pArr[v69].m_data.m_triangle = v36;
                  *(_QWORD *)&v68[v69].m_data.m_index = v70;
                  v68[v69].m_value = v38;
                  v36->m_vertices[k]->m_scratch = 1.0;
                }
              }
              v36 = v36->m_next;
            }
            while ( v36 );
            v5 = v165;
          }
          for ( m = this->m_mesh.m_vertices.m_used; m; m = m->m_next )
            m->m_scratch = 0.0;
          if ( j > 1 )
            hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::SortedEdge,hkAlgorithm::less<hkgpConvexHullImpl::SortedEdge>>(
              pArr,
              0,
              j - 1,
              0);
          v72 = 0;
          v73 = 0i64;
          v74 = this->m_mesh.m_vertices.m_numUsed - v5;
          v75 = v74;
          if ( v74 > 0 )
          {
            v76 = 0i64;
            do
            {
              v77 = 0;
              v78 = pArr[v76].m_data.m_triangle->m_vertices[pArr[v76].m_data.m_index];
              v78->m_scratch = v78->m_scratch + 1.0;
              m_triangle = pArr[v76].m_data.m_triangle;
              m_index = (int)pArr[v76].m_data.m_index;
              v159.m_vertices = (const float *)m_triangle;
              v159.m_numVertices = m_index;
              points = v159;
              while ( 1 )
              {
                m_vertices = points.m_vertices;
                v82 = 2 * LOBYTE(points.m_numVertices);
                v83 = *(_QWORD *)&points.m_vertices[2 * ((9i64 >> (2 * LOBYTE(points.m_numVertices))) & 3) + 4];
                v84 = *(float *)(v83 + 44) + 1.0;
                *(float *)(v83 + 44) = v84;
                if ( v84 > 1.0 )
                  v77 = 1;
                v85 = *(_QWORD *)&m_vertices[2 * ((18 >> v82) & 3) + 10] & 3i64;
                v86 = *(_QWORD *)&m_vertices[2 * ((18 >> v82) & 3) + 10] & 0xFFFFFFFFFFFFFFFCui64;
                v158.m_vertices = (const float *)v86;
                v158.m_numVertices = v85;
                points = v158;
                if ( !v86 )
                  break;
                if ( (hkgpConvexHullImpl::Triangle *)(v86 + v85) == (hkgpConvexHullImpl::Triangle *)((char *)m_triangle + (unsigned int)m_index) )
                  goto LABEL_71;
              }
              v87 = m_triangle->m_links[m_index];
              v156.m_vertices = (const float *)(v87 & 0xFFFFFFFFFFFFFFFCui64);
              v156.m_numVertices = (9 >> (2 * (v87 & 3))) & 3;
              points = v156;
              if ( (v87 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
              {
                do
                {
                  v88 = points.m_vertices;
                  m_numVertices = points.m_numVertices;
                  v90 = *(_QWORD *)&points.m_vertices[2 * ((9i64 >> (2 * LOBYTE(points.m_numVertices))) & 3) + 4];
                  v91 = *(float *)(v90 + 44) + 1.0;
                  *(float *)(v90 + 44) = v91;
                  v92 = *(_QWORD *)&v88[2 * m_numVertices + 10];
                  if ( v91 > 1.0 )
                    v77 = 1;
                  plane.m_quad.m128_u64[0] = *(_QWORD *)&v88[2 * m_numVertices + 10] & 0xFFFFFFFFFFFFFFFCui64;
                  plane.m_quad.m128_i32[2] = (9 >> (2 * (v92 & 3))) & 3;
                  points = (hkStridedVertices)plane.m_quad;
                }
                while ( plane.m_quad.m128_u64[0] );
              }
LABEL_71:
              if ( v77 )
                break;
              ++v73;
              ++v72;
              ++v76;
            }
            while ( v73 < v75 );
          }
          v93 = v72;
          if ( v72 > 0 )
          {
            v94 = 0i64;
            do
            {
              v95 = pArr[v94].m_data.m_triangle->m_vertices[pArr[v94].m_data.m_index];
              v96 = v95->m_next;
              m_prev = v95->m_prev;
              if ( v95->m_next )
                v96->m_prev = m_prev;
              if ( m_prev )
                m_prev->m_next = v96;
              else
                this->m_mesh.m_vertices.m_used = v96;
              --this->m_mesh.m_vertices.m_numUsed;
              v98 = v95[1].m_next;
              v16 = v98[40].m_source.m_quad.m128_i32[2]-- == 1;
              if ( v16 )
              {
                v99 = v98[40].m_prev;
                v100 = (hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *)v98[40].m_source.m_quad.m128_u64[0];
                if ( v99 )
                  v99[40].m_source.m_quad.m128_u64[0] = (unsigned __int64)v100;
                else
                  this->m_mesh.m_vertices.m_allocator.m_firstPool = v100;
                v101 = v98[40].m_source.m_quad.m128_u64[0];
                if ( v101 )
                  *(_QWORD *)(v101 + 2568) = v98[40].m_prev;
                hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v98, 2592);
              }
              ++v94;
              --v93;
            }
            while ( v93 );
          }
          v102 = this->m_mesh.m_vertices.m_numUsed;
          v103 = 0i64;
          v104 = 0;
          numPoints = 0;
          v137 = 0x80000000;
          v135 = 0i64;
          if ( v102 <= 0 )
          {
            result.m_enum = HK_SUCCESS;
          }
          else
          {
            hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v135, v102, 16);
            v104 = numPoints;
            v103 = v135;
          }
          v105 = this->m_mesh.m_vertices.m_used;
          v106 = v102 + v104;
          numPoints = v106;
          if ( v105 )
          {
            do
            {
              v107 = v103++;
              *v107 = v105->m_source;
              v105 = v105->m_next;
            }
            while ( v105 );
            v106 = numPoints;
            v103 = v135;
          }
          if ( hkgpConvexHullImpl::build(this, v103, v106, 0, 0i64) == -1 )
            break;
          numPoints = 0;
          if ( v137 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v135, 16 * v137);
          v28 = this->m_mesh.m_vertices.m_numUsed;
          v5 = v165;
          v135 = 0i64;
          v137 = 0x80000000;
          if ( v28 <= v165 )
          {
            v4 = containment;
            goto LABEL_99;
          }
        }
        hkgpConvexHullImpl::build(this, v144, i, 0, 0i64);
        m_enum = 0;
        numPoints = 0;
        if ( v137 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v135, 16 * v137);
      }
      if ( v138 )
        hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this);
      if ( v133 )
        hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this, &v167);
      j = 0;
      if ( v141 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          pArr,
          24 * (v141 & 0x3FFFFFFF));
      pArr = 0i64;
      v141 = 0x80000000;
      i = 0;
      if ( v146 < 0 )
        goto LABEL_143;
      v108 = v144;
    }
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkVector4f *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v108);
LABEL_143:
    *(_DWORD *)&array.m_setSourceIndices.m_bool = 0;
    if ( *(int *)&array.m_internalInputs.m_bool >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&array.m_allowLowerDimensions.m_bool,
        16 * *(_DWORD *)&array.m_internalInputs.m_bool);
    return m_enum;
  }
  m_hull = this->m_hull;
  v8 = this->m_hasIndexing;
  v9 = this->m_hasMassProperties;
  Dimensions = hkgpConvexHull::getDimensions(m_hull);
  if ( (int)hkgpConvexHull::getNumVertices(m_hull) <= v5 )
    return 1;
  if ( Dimensions < 2 )
    return 0;
  geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
  geometry.m_vertices.m_data = 0i64;
  geometry.m_vertices.m_size = 0;
  geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  geometry.m_triangles.m_data = 0i64;
  geometry.m_triangles.m_size = 0;
  geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  hkgpConvexHull::generateGeometry(m_hull, SOURCE_VERTICES, &geometry, 0, 0);
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
  if ( containment )
    config.m_maxShrink = 0.0;
  else
    LODWORD(config.m_maxShrink) = (_DWORD)FLOAT_1_0;
  config.m_solverAccuracy = SA_HIGH;
  hkgpCgo::optimize(&config, &geometry, 0i64, 0i64);
  v11 = this->m_hull;
  Configuration = hkgpConvexHull::getConfiguration(v11);
  *(_DWORD *)&array.m_allowLowerDimensions.m_bool = *(_DWORD *)&Configuration->m_config.m_allowLowerDimensions.m_bool;
  array.m_minCosAngle = Configuration->m_config.m_minCosAngle;
  v13 = *(_DWORD *)&Configuration->m_config.m_setSourceIndices.m_bool;
  LODWORD(Configuration) = *(_DWORD *)&Configuration->m_config.m_internalInputs.m_bool;
  *(_DWORD *)&array.m_setSourceIndices.m_bool = v13;
  array.m_buildIndices.m_bool = v8;
  array.m_buildMassProperties.m_bool = v9;
  *(_DWORD *)&array.m_internalInputs.m_bool = (_DWORD)Configuration;
  if ( Dimensions >= 3 )
  {
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    points.m_striding = 16;
    points.m_numVertices = geometry.m_vertices.m_size;
    m_enum = hkgpConvexHull::build(v11, &points, &array) != -1;
  }
  else
  {
    points.m_striding = 16;
    plane.m_quad = hkgpConvexHull::getProjectionPlane(v11)->m_quad;
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    points.m_numVertices = geometry.m_vertices.m_size;
    m_enum = hkgpConvexHull::buildPlanar(v11, &points, &plane, &array) != -1;
  }
  hkGeometry::~hkGeometry(&geometry);
  return m_enum;
}s.m_bool;
  *(_DWORD *)&array.m_setSourceIndices.m_bool = v13;
  array.m_buildIndices.m_bool = v8;
  array.m_buildMassProperties.m_bool = v9;
  *(_DWORD *)&array.m_internalInputs.m_bool = (_DWORD)Configuration;
  if ( Dimensions >= 3 )
  {
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    points.m_striding = 16;
    points.m_numVertices = geometry.m_vertices.m_size;
    m_enum = hkgpConvexHull::build(v11, &points, &array) != -1;
  }
  else
  {
    points.m_striding = 16;
    plane.m_quad = hkgpConvexHull::getProjectionPlane(v11)->m_quad;
    points.m_vertices = geometry.m_vertices.m_data->m_quad.m128_f32;
    

// File Line: 1750
// RVA: 0xCB6CB0
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::getEdgeLengths(hkgpConvexHullImpl *this, hkSimdFloat32 *result)
{
  int m_dimensions; // r8d
  int v5; // r8d
  int v6; // r8d
  hkgpConvexHullImpl::Triangle *m_next; // rbx
  int v8; // r11d
  __m128 **m_vertices; // r10
  int v10; // ecx
  __m128 *v11; // rdi
  __m128 *v12; // rax
  int v13; // edx
  int m_index; // ecx
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  hkSimdFloat32 *v19; // rax
  int m_numUsed; // edi
  int v21; // r9d
  hkVector4f *v22; // rdx
  int v23; // r8d
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  int v25; // r8d
  hkVector4f *v26; // rax
  __int64 v27; // rcx
  __int64 v28; // rax
  __int64 v29; // r10
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  hkgpConvexHullImpl::Vertex *v35; // rax
  __m128 *v36; // rcx
  __m128 m_quad; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  hkVector4f *array; // [rsp+30h] [rbp-48h] BYREF
  int v43; // [rsp+38h] [rbp-40h]
  int v44; // [rsp+3Ch] [rbp-3Ch]
  hkResult resulta; // [rsp+80h] [rbp+8h] BYREF

  m_dimensions = this->m_dimensions;
  *result = 0i64;
  v5 = m_dimensions - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 && (m_next = this->m_mesh.m_triangles.m_used) != 0i64 )
      {
        do
        {
          v8 = 0;
          m_vertices = (__m128 **)m_next->m_vertices;
          do
          {
            v10 = 0;
            v11 = (__m128 *)m_next->m_vertices[(9i64 >> (2 * (unsigned __int8)v8)) & 3];
            v12 = v11 + 2;
            do
            {
              v13 = *(int *)((char *)v12->m128_i32 + (char *)*m_vertices - (char *)v11);
              if ( v13 < v12->m128_i32[0] )
                break;
              if ( v13 > v12->m128_i32[0] )
              {
                if ( ((unsigned __int64)m_vertices[3] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                  goto LABEL_15;
                break;
              }
              ++v10;
              v12 = (__m128 *)((char *)v12 + 4);
            }
            while ( v10 < 3 );
            m_index = m_next->m_plane.m_index;
            if ( m_index == -1
              || m_index != *(_DWORD *)(((unsigned __int64)m_vertices[3] & 0xFFFFFFFFFFFFFFFCui64) + 88) )
            {
              v15 = _mm_sub_ps((*m_vertices)[1], v11[1]);
              v16 = _mm_mul_ps(v15, v15);
              v17 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                      _mm_shuffle_ps(v16, v16, 170));
              v18 = _mm_rsqrt_ps(v17);
              result->m_real = _mm_add_ps(
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v17, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v18), v18)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                     v17)),
                                 result->m_real);
            }
LABEL_15:
            ++v8;
            ++m_vertices;
          }
          while ( v8 < 3 );
          m_next = m_next->m_next;
        }
        while ( m_next );
        return result;
      }
      else
      {
        return result;
      }
    }
    else
    {
      m_numUsed = this->m_mesh.m_vertices.m_numUsed;
      v21 = 0x80000000;
      v22 = 0i64;
      v23 = 0;
      v43 = 0;
      v44 = 0x80000000;
      array = 0i64;
      if ( m_numUsed > 0 )
      {
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 16);
        v21 = v44;
        v23 = v43;
        v22 = array;
      }
      m_used = this->m_mesh.m_vertices.m_used;
      v25 = m_numUsed + v23;
      v43 = v25;
      if ( m_used )
      {
        do
        {
          v26 = v22++;
          *v26 = m_used->m_source;
          m_used = m_used->m_next;
        }
        while ( m_used );
        v21 = v44;
        v25 = v43;
        v22 = array;
      }
      if ( v25 > 0 )
      {
        v27 = 16i64 * (v25 - 1);
        v28 = 0i64;
        v29 = (unsigned int)v25;
        do
        {
          v30 = *(__m128 *)((char *)&v22->m_quad + v27);
          v27 = v28 * 16;
          v31 = _mm_sub_ps(v30, v22[v28++].m_quad);
          v32 = _mm_mul_ps(v31, v31);
          v33 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170));
          v34 = _mm_rsqrt_ps(v33);
          result->m_real = _mm_add_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v33, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v34)),
                                 v33)),
                             result->m_real);
          --v29;
        }
        while ( v29 );
      }
      v43 = 0;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v22, 16 * v21);
      return result;
    }
  }
  else
  {
    v35 = this->m_mesh.m_vertices.m_used;
    v36 = (__m128 *)v35->m_next;
    m_quad = v35->m_source.m_quad;
    v19 = result;
    v38 = _mm_sub_ps(m_quad, v36[1]);
    v39 = _mm_mul_ps(v38, v38);
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v41 = _mm_rsqrt_ps(v40);
    result->m_real = _mm_andnot_ps(
                       _mm_cmple_ps(v40, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                           _mm_mul_ps(*(__m128 *)_xmm, v41)),
                         v40));
  }
  return v19;
}

// File Line: 1830
// RVA: 0xCB3180
hkVector4f *__fastcall hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(
        hkgpConvexHullImpl *this)
{
  hkVector4f *result; // rax
  __m128 v2; // xmm4
  hkgpConvexHullImpl::Vertex *i; // rdx
  int m_numUsed; // edx

  result = &this->m_centroids[1];
  if ( _mm_shuffle_ps(this->m_centroids[1].m_quad, this->m_centroids[1].m_quad, 255).m128_f32[0] == 3.40282e38 )
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
    m_numUsed = this->m_mesh.m_vertices.m_numUsed;
    if ( m_numUsed )
    {
      v2.m128_f32[0] = (float)m_numUsed;
      result->m_quad = _mm_mul_ps(result->m_quad, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v2, v2, 0)));
    }
    *(__m128i *)result = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)result), 4), 4);
  }
  return result;
}

// File Line: 1856
// RVA: 0xCB11E0
hkResult *__fastcall hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(
        hkgpConvexHullImpl *this,
        hkResult *result)
{
  hkResultEnum v2; // edi
  int m_dimensions; // eax
  hkVector4f *v6; // rax
  hkgpConvexHullImpl::Triangle *m_used; // rcx
  hkgpConvexHullImpl::Triangle *m_next; // rdx
  __m128 m_quad; // xmm12
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
  hkVector4f v57; // xmm12
  __m128 v58; // xmm8
  hkVector4f v59; // xmm9
  hkVector4f v60; // xmm10
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
  __m128 v72; // xmm1
  __m128 v73; // xmm6
  __m128 v74; // xmm1
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __m128 v77; // xmm3
  __m128 v78; // xmm1
  hkSimdFloat32 v79; // xmm4
  __m128 v80; // xmm6
  __m128 v81; // xmm14
  __m128 v82; // xmm3
  __m128 v83; // xmm13
  hkOstream *v84; // rax
  hkOstream *v85; // rax
  hkVector4f v86; // xmm1
  hkVector4f v87; // xmm0
  __m128 v88; // xmm0
  __m128 v89; // xmm1
  hkVector4f v90; // xmm2
  hkVector4f v91; // xmm1
  hkVector4f v92; // xmm0
  int m_numUsed; // esi
  __m128 v94; // xmm6
  __m128 *v95; // rdx
  int v96; // eax
  int v97; // r8d
  __m128 v98; // xmm7
  hkgpConvexHullImpl::Vertex *v99; // rcx
  int v100; // eax
  __m128 *v101; // rax
  __int64 v102; // rcx
  __m128 v103; // xmm5
  __m128 *v104; // rax
  __int64 v105; // rcx
  __m128 v106; // xmm4
  __m128 v107; // xmm3
  __m128 v108; // xmm3
  __m128 v109; // xmm4
  __m128 v110; // xmm1
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  hkVector4f v113; // xmm1
  hkVector4f v114; // xmm1
  hkResult *v115; // rax
  __m128 array; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f eigenVal; // [rsp+40h] [rbp-A8h] BYREF
  hkOstream scale; // [rsp+50h] [rbp-98h] BYREF
  __m256i v119; // [rsp+68h] [rbp-80h] BYREF
  __m128 v120; // [rsp+88h] [rbp-60h]
  hkVector4f v121; // [rsp+98h] [rbp-50h] BYREF
  hkRotationf eigenVec; // [rsp+A8h] [rbp-40h] BYREF
  hkMatrix3f aTb; // [rsp+D8h] [rbp-10h] BYREF
  hkMatrix3f a; // [rsp+108h] [rbp+20h] BYREF
  hkMatrix3f v125; // [rsp+138h] [rbp+50h] BYREF
  hkMatrix3f bTc; // [rsp+168h] [rbp+80h] BYREF
  char buf[536]; // [rsp+198h] [rbp+B0h] BYREF
  hkResult resulta; // [rsp+458h] [rbp+370h] BYREF

  v2 = HK_SUCCESS;
  if ( !this->m_hasMassProperties )
  {
    m_dimensions = this->m_dimensions;
    this->m_degeneratedMassProperties = 0;
    if ( m_dimensions == 3 )
    {
      v6 = hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsTransform>(this);
      m_used = this->m_mesh.m_triangles.m_used;
      m_next = m_used;
      m_quad = v6->m_quad;
      v10 = 0i64;
      v11 = 0i64;
      array = 0i64;
      v120 = 0i64;
      v12 = 0i64;
      v121.m_quad = 0i64;
      v13 = 0i64;
      v14 = 0i64;
      if ( m_used )
      {
        v15 = this->m_scaleInv.m_quad;
        v16 = this->m_origin.m_quad;
        eigenVal.m_quad = v15;
        scale.hkReferencedObject = (hkReferencedObject)v16;
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
                                                 _mm_cvtsi32_si128(m_next->m_vertices[0]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_next->m_vertices[0]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_next->m_vertices[0]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  m_quad);
          v18 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_next->m_vertices[1]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_next->m_vertices[1]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_next->m_vertices[1]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  m_quad);
          v19 = _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_next->m_vertices[2]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_next->m_vertices[2]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_next->m_vertices[2]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v15),
                    v16),
                  m_quad);
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
          v121.m_quad = v12;
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
          v120 = _mm_add_ps(
                   v11,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v29, (__m128)0i64),
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
          *(float *)v13.m128i_i32 = (float)((float)((float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v37, v37, 170).m128_f32[0])
                                          * v23.m128_f32[0])
                                  + _mm_shuffle_ps((__m128)v13, (__m128)v13, 0).m128_f32[0];
          v38 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170));
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170));
          v14.m128_f32[0] = (float)((float)((float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v36, v36, 170).m128_f32[0])
                                          + (float)(v39.m128_f32[0] * v38.m128_f32[0]))
                                  * v23.m128_f32[0])
                          + _mm_shuffle_ps(v14, v14, 0).m128_f32[0];
          m_next = m_next->m_next;
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
          v11 = v120;
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
          v16 = (__m128)scale.hkReferencedObject;
          v14 = _mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, _mm_add_ps(v54, _mm_shuffle_ps(v51, v51, 170))), 180);
        }
        while ( m_next );
      }
      v55 = _mm_div_ps(query.m_quad, v10);
      eigenVal.m_quad = v55;
      v56 = _mm_mul_ps(v12, _mm_mul_ps(v55, (__m128)xmmword_141A711D0));
      v57.m_quad = _mm_add_ps(m_quad, v56);
      v121.m_quad = v56;
      this->m_localTransform.m_translation = (hkVector4f)v57.m_quad;
      if ( this->m_config.m_checkForDegeneratedMassProperties.m_bool )
      {
        v58 = 0i64;
        if ( m_used )
        {
          v59.m_quad = (__m128)this->m_scaleInv;
          v60.m_quad = (__m128)this->m_origin;
          do
          {
            v61 = _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[0]),
                                                 _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_vertices[0]->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      v59.m_quad),
                    v60.m_quad);
            v62 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[0]),
                                                   _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[2])),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(m_used->m_vertices[2]->m_x[1]),
                                                   _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v59.m_quad),
                      v60.m_quad),
                    v61);
            v63 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        (__m128)_mm_srli_si128(
                                  _mm_slli_si128(
                                    (__m128i)_mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[0]),
                                                   _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[2])),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(m_used->m_vertices[1]->m_x[1]),
                                                   _mm_cvtsi32_si128(0)))),
                                    4),
                                  4),
                        v59.m_quad),
                      v60.m_quad),
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
            v69 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v67), (__m128)0i64);
            v70 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v67, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                            _mm_mul_ps(v68, *(__m128 *)_xmm))),
                        v65),
                      v69),
                    _mm_andnot_ps(v69, v65));
            v71 = _mm_mul_ps(v70, v61);
            m_used = m_used->m_next;
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
            v73 = _mm_shuffle_ps(v72, v72, 255);
            v74 = _mm_mul_ps(v72, v57.m_quad);
            v58 = _mm_max_ps(
                    v58,
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                        _mm_shuffle_ps(v74, v74, 170)),
                      v73));
          }
          while ( m_used );
          v10 = array;
        }
        if ( v58.m128_f32[0] > 0.0 )
          this->m_degeneratedMassProperties = 1;
        if ( this->m_hasIndexing )
        {
          m_size = (unsigned int)this->m_planes.m_size;
          v58 = 0i64;
          if ( (int)m_size > 0 )
          {
            m_data = this->m_planes.m_data;
            do
            {
              v77 = m_data->m_quad;
              ++m_data;
              v78 = _mm_mul_ps(v77, v57.m_quad);
              v58 = _mm_max_ps(
                      v58,
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                          _mm_shuffle_ps(v78, v78, 170)),
                        _mm_shuffle_ps(v77, v77, 255)));
              --m_size;
            }
            while ( m_size );
          }
        }
        v55 = eigenVal.m_quad;
        if ( v58.m128_f32[0] > 0.0 )
          this->m_degeneratedMassProperties = 1;
      }
      this->m_surface.m_real = _mm_mul_ps(v120, (__m128)xmmword_141A711B0);
      v79.m_real = _mm_mul_ps(v10, (__m128)xmmword_141A711F0);
      v80 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u);
      this->m_volume = (hkSimdFloat32)v79.m_real;
      if ( v79.m_real.m128_f32[0] <= 0.00000011920929 )
      {
        this->m_localTransform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
        this->m_localTransform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
        this->m_localTransform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        this->m_volume = 0i64;
        this->m_degeneratedMassProperties = 1;
        this->m_inertiaMatrix.m_col0 = 0i64;
        this->m_inertiaMatrix.m_col1 = 0i64;
        this->m_inertiaMatrix.m_col2 = 0i64;
        this->m_inertia = 0i64;
      }
      else
      {
        resulta.m_enum = LODWORD(FLOAT_N0_050000001);
        v81 = _mm_mul_ps(
                (__m128)v13,
                _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0), v55));
        v82 = (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_add_ps(_mm_shuffle_ps(v81, v81, 90), _mm_shuffle_ps(v81, v81, 65)),
                          4),
                        4);
        v83 = _mm_mul_ps(
                v14,
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_050000001), (__m128)LODWORD(FLOAT_N0_050000001), 0),
                  v55));
        *(__m128 *)v119.m256i_i8 = _mm_or_ps(
                                     _mm_andnot_ps((__m128)xmmword_141A79680, _mm_shuffle_ps(v83, v83, 78)),
                                     _mm_and_ps((__m128)xmmword_141A79680, v82));
        *(__m128 *)&v119.m256i_u64[2] = _mm_or_ps(
                                          _mm_andnot_ps((__m128)xmmword_141A796A0, _mm_shuffle_ps(v83, v83, 225)),
                                          _mm_and_ps((__m128)xmmword_141A796A0, v82));
        scale.hkReferencedObject = (hkReferencedObject)query.m_quad;
        hkMatrix3f::setCrossSkewSymmetric(&aTb, &v121);
        hkMatrix3f::setCrossSkewSymmetric(&bTc, &aabbOut);
        hkMatrix3f::setMul(&v125, &aTb, &aTb);
        hkMatrix3f::setMul(&a, &bTc, &bTc);
        hkMatrix3f::transpose(&a);
        hkMatrix3f::sub(&v125, &a);
        hkMatrix3f::addMul((hkMatrix3f *)&v119.m256i_u64[1], (hkSimdFloat32 *)&scale, &v125);
        if ( hkMatrix3f::diagonalizeSymmetric(
               (hkMatrix3f *)&v119.m256i_u64[1],
               &resulta,
               &eigenVec,
               &eigenVal,
               128,
               0.00000011920929)->m_enum == HK_FAILURE )
        {
          this->m_degeneratedMassProperties = 1;
          eigenVec.m_col0 = (hkVector4f)transform.m_quad;
          eigenVec.m_col1 = (hkVector4f)direction.m_quad;
          eigenVec.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          eigenVal.m_quad = query.m_quad;
          hkErrStream::hkErrStream((hkErrStream *)&scale, buf, 512);
          v84 = hkOstream::operator<<(&scale, "Failed to diagonalize inertia matrix (");
          v85 = hkOstream::operator<<(v84, this->m_uid);
          hkOstream::operator<<(v85, ")");
          hkError::messageWarning(
            0x45465u,
            buf,
            "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
            1982);
          hkOstream::~hkOstream(&scale);
        }
        hkMatrix3f::transpose(&eigenVec);
        hkRotationf::renormalize(&eigenVec);
        v86.m_quad = *(__m128 *)v119.m256i_i8;
        this->m_inertiaMatrix.m_col0 = *(hkVector4f *)&v119.m256i_u64[1];
        v87.m_quad = *(__m128 *)&v119.m256i_u64[2];
        this->m_inertiaMatrix.m_col1 = (hkVector4f)v86.m_quad;
        this->m_inertiaMatrix.m_col2 = (hkVector4f)v87.m_quad;
        hkMatrix3f::changeBasis((hkMatrix3f *)&v119.m256i_u64[1], &eigenVec);
        v88 = *(__m128 *)&v119.m256i_u64[1];
        v89 = *(__m128 *)&v119.m256i_u64[2];
        this->m_inertia = *(hkVector4f *)&v119.m256i_u64[1];
        v90.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)xmmword_141A79600, v88),
                       _mm_and_ps(*(__m128 *)v119.m256i_i8, (__m128)xmmword_141A79600));
        this->m_inertia = (hkVector4f)v90.m_quad;
        this->m_inertia.m_quad = _mm_or_ps(
                                   _mm_and_ps(v89, (__m128)xmmword_141A79620),
                                   _mm_andnot_ps((__m128)xmmword_141A79620, v90.m_quad));
        hkMatrix3f::transpose(&eigenVec);
        v91.m_quad = (__m128)eigenVec.m_col1;
        this->m_localTransform.m_rotation.m_col0 = eigenVec.m_col0;
        v92.m_quad = (__m128)eigenVec.m_col2;
        this->m_localTransform.m_rotation.m_col1 = (hkVector4f)v91.m_quad;
        this->m_localTransform.m_rotation.m_col2 = (hkVector4f)v92.m_quad;
        if ( fmin(
               _mm_shuffle_ps(v80, v80, 170).m128_f32[0],
               fmin(_mm_shuffle_ps(v80, v80, 85).m128_f32[0], _mm_shuffle_ps(v80, v80, 0).m128_f32[0])) <= 0.00000011920929 )
          this->m_degeneratedMassProperties = 1;
      }
      this->m_hasMassProperties = 1;
    }
    else if ( m_dimensions == 2 )
    {
      m_numUsed = this->m_mesh.m_vertices.m_numUsed;
      v94 = 0i64;
      v95 = 0i64;
      v96 = 0;
      v97 = 0x80000000;
      v98 = 0i64;
      array.m128_u64[0] = 0i64;
      array.m128_u64[1] = 0x8000000000000000ui64;
      if ( m_numUsed > 0 )
      {
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 16);
        v97 = array.m128_i32[3];
        v96 = array.m128_i32[2];
        v95 = (__m128 *)array.m128_u64[0];
      }
      v99 = this->m_mesh.m_vertices.m_used;
      v100 = m_numUsed + v96;
      array.m128_i32[2] = v100;
      if ( v99 )
      {
        do
        {
          v101 = v95++;
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
                      this->m_scaleInv.m_quad),
                    this->m_origin.m_quad);
          v99 = v99->m_next;
        }
        while ( v99 );
        v97 = array.m128_i32[3];
        v100 = array.m128_i32[2];
        v95 = (__m128 *)array.m128_u64[0];
      }
      v102 = v100 - 1;
      if ( v102 > 1 )
      {
        v103 = *v95;
        v104 = v95 + 1;
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
          v111 = _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), this->m_projectionPlane.m_quad);
          v112 = (__m128)_mm_srli_epi32(
                           _mm_slli_epi32(
                             (__m128i)_mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                                        _mm_shuffle_ps(v111, v111, 170)),
                             1u),
                           1u);
          v98 = _mm_add_ps(v98, v112);
          v94 = _mm_add_ps(v94, _mm_mul_ps(_mm_mul_ps(v112, (__m128)xmmword_141A711C0), _mm_add_ps(v108, v109)));
          --v105;
        }
        while ( v105 );
      }
      this->m_hasMassProperties = 1;
      this->m_surface.m_real = _mm_mul_ps(v98, (__m128)xmmword_141A711B0);
      v113.m_quad = (__m128)this->m_inertiaMatrix.m_col0;
      v113.m_quad.m128_f32[0] = 1.0;
      this->m_inertiaMatrix.m_col0 = (hkVector4f)v113.m_quad;
      this->m_inertia = (hkVector4f)transform.m_quad;
      v114.m_quad = _mm_add_ps(_mm_mul_ps(_mm_div_ps(query.m_quad, v98), v94), *v95);
      array.m128_i32[2] = 0;
      this->m_localTransform.m_translation = (hkVector4f)v114.m_quad;
      if ( v97 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v95, 16 * v97);
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
  v115 = result;
  LOBYTE(v2) = !this->m_hasMassProperties;
  result->m_enum = v2;
  return v115;
}

// File Line: 2058
// RVA: 0xCB2830
__int64 __fastcall hkgpConvexHullImpl::generateIndexedFaces<int,int>(
        hkgpConvexHullImpl *this,
        hkArray<int,hkContainerHeapAllocator> *vpf,
        hkArray<int,hkContainerHeapAllocator> *vi,
        bool useSourceIndex,
        hkResult maximizeArea)
{
  __int64 v5; // r12
  bool v6; // si
  hkgpConvexHullImpl *v9; // r15
  unsigned int v10; // r14d
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  int m_capacityAndFlags; // eax
  int m_size; // r9d
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  int v18; // eax
  int v19; // eax
  int m_dimensions; // eax
  int m_numUsed; // r9d
  int v22; // eax
  hkgpConvexHullImpl::Triangle *i; // rdx
  __int64 v24; // r8
  int v25; // r9d
  hkgpConvexHullImpl::Triangle *v26; // r8
  int v27; // edx
  hkBaseObjectVtbl *vfptr; // rdi
  char m_memSizeAndFlags; // r15
  __int64 v30; // rcx
  __int64 v31; // r13
  void *(__fastcall **v32)(hkBaseObject *, unsigned int); // rcx
  unsigned int v33; // esi
  int *v34; // rsi
  __int64 v35; // rcx
  char v36; // cl
  __int64 v37; // rcx
  __int64 v38; // rcx
  bool v39; // zf
  int v40; // esi
  hkgpConvexHullImpl::Vertex *j; // rdi
  unsigned int v42; // esi
  int k; // edi
  int v44; // r9d
  int *m_data; // rax
  int v46; // ecx
  hkgpConvexHullImpl::Vertex *m; // rbx
  hkArray<int,hkContainerHeapAllocator> *v48; // rax
  hkBaseObjectVtbl *v49; // r14
  __int64 v50; // r9
  int m_enum; // r9d
  __int64 v52; // r15
  hkResultEnum v53; // r13d
  hkgpConvexHullImpl::Triangle *v54; // r11
  hkgpConvexHullImpl::Triangle *v55; // rdx
  hkgpConvexHullImpl::Triangle *v56; // rcx
  int v57; // r9d
  int v58; // eax
  int v59; // ebx
  int v60; // edi
  int v61; // esi
  int v62; // r10d
  int v63; // edx
  __int64 v64; // rax
  __int64 v65; // rcx
  int v66; // edi
  char *v67; // rdx
  int v68; // r8d
  hkBaseObjectVtbl *v69; // rbx
  int v70; // r9d
  __int64 v71; // rcx
  int v72; // eax
  __int64 n; // rcx
  int v74; // eax
  __int64 ii; // rcx
  int v76; // eax
  hkgpConvexHullImpl::Triangle **array; // [rsp+30h] [rbp-D0h] BYREF
  int v79; // [rsp+38h] [rbp-C8h]
  int v80; // [rsp+3Ch] [rbp-C4h]
  hkResult result[2]; // [rsp+40h] [rbp-C0h] BYREF
  hkReferencedObject v82; // [rsp+50h] [rbp-B0h]
  int v83; // [rsp+60h] [rbp-A0h]
  __int64 v84; // [rsp+68h] [rbp-98h]
  hkResultEnum v85; // [rsp+70h] [rbp-90h]
  hkErrStream v86; // [rsp+80h] [rbp-80h] BYREF
  hkReferencedObject v87; // [rsp+A0h] [rbp-60h]
  hkReferencedObject v88; // [rsp+B0h] [rbp-50h]
  char *v89; // [rsp+C0h] [rbp-40h] BYREF
  int v90; // [rsp+C8h] [rbp-38h]
  int v91; // [rsp+CCh] [rbp-34h]
  char v92[128]; // [rsp+D0h] [rbp-30h] BYREF
  char buf[520]; // [rsp+150h] [rbp+50h] BYREF
  int v95; // [rsp+3A0h] [rbp+2A0h]
  int v97; // [rsp+3B0h] [rbp+2B0h]

  v5 = 0i64;
  v6 = useSourceIndex;
  v9 = this;
  v10 = 0;
  v97 = 0;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v86, buf, 512);
    v11 = hkOstream::operator<<(&v86, "No index available (");
    v12 = hkOstream::operator<<(v11, v9->m_uid);
    hkOstream::operator<<(v12, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v86);
  }
  m_capacityAndFlags = vpf->m_capacityAndFlags;
  vpf->m_size = 0;
  m_size = v9->m_planes.m_size;
  v15 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < m_size )
  {
    v16 = 2 * v15;
    if ( m_size < v16 )
      m_size = v16;
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&vpf->m_data, m_size, 4);
  }
  vi->m_size = 0;
  v17 = 3 * v9->m_mesh.m_vertices.m_numUsed;
  v18 = vi->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&vi->m_data, v17, 4);
  }
  m_dimensions = v9->m_dimensions;
  if ( m_dimensions == 3 )
  {
    m_numUsed = v9->m_mesh.m_triangles.m_numUsed;
    v22 = 0;
    array = 0i64;
    v79 = 0;
    v80 = 0x80000000;
    if ( m_numUsed > 0 )
    {
      hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 8);
      v22 = v79;
    }
    for ( i = v9->m_mesh.m_triangles.m_used; i; i = i->m_next )
    {
      array[v22] = i;
      v22 = ++v79;
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
    if ( v22 > 0 )
    {
      v25 = `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard;
      do
      {
        v26 = array[v24];
        if ( v26->m_plane.m_index == v10 )
        {
          if ( (v25 & 1) == 0 )
          {
            v25 |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard = v25;
          }
          v27 = 0;
          v82 = (hkReferencedObject)`hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::e;
          while ( *(_DWORD *)((v26->m_links[v27] & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 )
          {
            if ( ++v27 >= 3 )
              goto LABEL_30;
          }
          v88.vfptr = (hkBaseObjectVtbl *)v26;
          *(_DWORD *)&v88.m_memSizeAndFlags = v27;
          v82 = v88;
LABEL_30:
          vfptr = v82.vfptr;
          if ( v82.vfptr )
          {
            m_memSizeAndFlags = v82.m_memSizeAndFlags;
            v30 = *(int *)&v82.m_memSizeAndFlags + 2i64;
            v31 = *((_QWORD *)&v82.vfptr->__vecDelDtor + v30);
            v32 = &v82.vfptr->__vecDelDtor + v30;
            do
            {
              LODWORD(v5) = v5 + 1;
              if ( v6 )
              {
                v33 = *((_DWORD *)*v32 + 7) & 0xC0FFFFFF;
                if ( vi->m_size == (vi->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vi->m_data, 4);
                vi->m_data[vi->m_size] = v33;
              }
              else
              {
                v34 = (int *)((char *)*v32 + 52);
                if ( vi->m_size == (vi->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vi->m_data, 4);
                vi->m_data[vi->m_size] = *v34;
              }
              ++vi->m_size;
              v87.vfptr = vfptr;
              *(_DWORD *)&v87.m_memSizeAndFlags = (9 >> (2 * m_memSizeAndFlags)) & 3;
              v35 = *((_QWORD *)&vfptr[2].__first_virtual_table_function__ + *(int *)&v87.m_memSizeAndFlags);
              v82 = v87;
              if ( *(_DWORD *)((v35 & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 )
              {
                do
                {
                  v36 = (__int64)*(&v82.vfptr[2].__first_virtual_table_function__ + *(int *)&v82.m_memSizeAndFlags) & 3;
                  v86.vfptr = (hkBaseObjectVtbl *)((unsigned __int64)*(&v82.vfptr[2].__first_virtual_table_function__
                                                                     + *(int *)&v82.m_memSizeAndFlags) & 0xFFFFFFFFFFFFFFFCui64);
                  *(_DWORD *)&v86.m_memSizeAndFlags = (9 >> (2 * v36)) & 3;
                  v37 = *((_QWORD *)&v86.vfptr[2].__first_virtual_table_function__ + *(int *)&v86.m_memSizeAndFlags);
                  v82 = v86.hkReferencedObject;
                }
                while ( *(_DWORD *)((v37 & 0xFFFFFFFFFFFFFFFCui64) + 88) == v10 );
              }
              m_memSizeAndFlags = v82.m_memSizeAndFlags;
              vfptr = v82.vfptr;
              v6 = useSourceIndex;
              v38 = *(int *)&v82.m_memSizeAndFlags + 2i64;
              v39 = *((_QWORD *)&v82.vfptr->__vecDelDtor + v38) == v31;
              v32 = &v82.vfptr->__vecDelDtor + v38;
            }
            while ( !v39 );
            if ( vpf->m_size == (vpf->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vpf->m_data, 4);
            v6 = useSourceIndex;
            vpf->m_data[vpf->m_size++] = v5;
            v25 = `hkgpTopology::Edge<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkgpConvexHullImpl::Vertex *>::null::`2::`local static guard;
            ++v10;
            v5 = 0i64;
          }
        }
        v24 = *(_QWORD *)&result[0].m_enum + 1i64;
        *(_QWORD *)&result[0].m_enum = v24;
      }
      while ( v24 < v84 );
      v9 = this;
      v97 = v10;
    }
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v80);
  }
  else if ( m_dimensions == 2 )
  {
    v40 = v9->m_mesh.m_vertices.m_numUsed;
    v10 = 1;
    v97 = 1;
    if ( vpf->m_size == (vpf->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vpf->m_data, 4);
    vpf->m_data[vpf->m_size++] = v40;
    if ( useSourceIndex )
    {
      for ( j = v9->m_mesh.m_vertices.m_used; j; j = j->m_next )
      {
        v42 = j->m_source.m_quad.m128_i32[3] & 0xC0FFFFFF;
        if ( vi->m_size == (vi->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vi->m_data, 4);
        vi->m_data[vi->m_size++] = v42;
      }
    }
    else
    {
      for ( k = 0; k < v9->m_mesh.m_vertices.m_numUsed; ++k )
      {
        if ( vi->m_size == (vi->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vi->m_data, 4);
        vi->m_data[vi->m_size++] = k;
      }
    }
  }
  if ( LOBYTE(maximizeArea.m_enum) && v10 )
  {
    v44 = v9->m_mesh.m_vertices.m_numUsed;
    m_data = vi->m_data;
    v46 = 0;
    array = 0i64;
    v79 = 0;
    v80 = 0x80000000;
    v82.vfptr = (hkBaseObjectVtbl *)m_data;
    if ( v44 > 0 )
    {
      hkArrayUtil::_reserve(&maximizeArea, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v44, 8);
      v46 = v79;
    }
    for ( m = v9->m_mesh.m_vertices.m_used; m; m = m->m_next )
    {
      if ( v46 == (v80 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v46 = v79;
      }
      array[v46] = (hkgpConvexHullImpl::Triangle *)m;
      v46 = ++v79;
    }
    v48 = vpf;
    v95 = 0;
    if ( vpf->m_size > 0 )
    {
      v49 = v82.vfptr;
      v50 = 0i64;
      v84 = 0i64;
      do
      {
        m_enum = *(int *)((char *)v48->m_data + v50);
        maximizeArea.m_enum = m_enum;
        if ( m_enum >= 3 )
        {
          v52 = -1i64;
          v82.vfptr = (hkBaseObjectVtbl *)-1i64;
          v83 = -1;
          v53 = HK_SUCCESS;
          do
          {
            v85 = v53 + 1;
            v54 = array[*((int *)&v49->__vecDelDtor + (v53 + 2) % m_enum)];
            v55 = array[*((int *)&v49->__vecDelDtor + (v53 + 1) % m_enum)];
            v56 = array[*((int *)&v49->__vecDelDtor + v5)];
            v57 = HIDWORD(v54->m_vertices[2]) - HIDWORD(v56->m_vertices[2]);
            v58 = v56->m_links[0];
            v59 = LODWORD(v54->m_vertices[2]) - LODWORD(v56->m_vertices[2]);
            v60 = HIDWORD(v55->m_vertices[2]) - HIDWORD(v56->m_vertices[2]);
            v61 = LODWORD(v55->m_vertices[2]) - LODWORD(v56->m_vertices[2]);
            LODWORD(v56) = LODWORD(v54->m_links[0]) - v58;
            v62 = LODWORD(v55->m_links[0]) - v58;
            v63 = v60 * (_DWORD)v56 - v62 * v57;
            v64 = (v62 * v59 - v61 * (int)v56) * (__int64)(v62 * v59 - v61 * (int)v56);
            v65 = (v61 * v57 - v60 * v59) * (__int64)(v61 * v57 - v60 * v59);
            if ( v65 + v64 + v63 * (__int64)v63 <= (__int64)v82.vfptr )
            {
              v66 = v83;
            }
            else
            {
              v82.vfptr = (hkBaseObjectVtbl *)(v65 + v64 + v63 * (__int64)v63);
              v66 = v53;
              v83 = v53;
              v52 = v5;
            }
            v53 = v85;
            m_enum = maximizeArea.m_enum;
            ++v5;
          }
          while ( v85 < maximizeArea.m_enum );
          v5 = 0i64;
          if ( v66 > 0 )
          {
            v67 = v92;
            v68 = -2147483616;
            v90 = 0;
            v69 = v49;
            v89 = v92;
            v91 = -2147483616;
            if ( v66 <= 32 )
            {
              result[0].m_enum = HK_SUCCESS;
            }
            else
            {
              v70 = v66;
              if ( v66 < 64 )
                v70 = 64;
              hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&v89, v70, 4);
              v68 = v91;
              v67 = v89;
              m_enum = maximizeArea.m_enum;
            }
            v90 = v66;
            v71 = 0i64;
            if ( v52 > 0 )
            {
              do
              {
                v72 = *((_DWORD *)&v49->__vecDelDtor + v71++);
                *(_DWORD *)&v67[4 * v71 - 4] = v72;
                v67 = v89;
              }
              while ( v71 < v52 );
              v68 = v91;
            }
            for ( n = v52; n < m_enum; HIDWORD(v69[-1].__first_virtual_table_function__) = v74 )
            {
              v74 = *((_DWORD *)&v49->__vecDelDtor + n++);
              v69 = (hkBaseObjectVtbl *)((char *)v69 + 4);
            }
            for ( ii = 0i64; ii < v52; HIDWORD(v69[-1].__first_virtual_table_function__) = v76 )
            {
              v76 = *(_DWORD *)&v67[4 * ii++];
              v69 = (hkBaseObjectVtbl *)((char *)v69 + 4);
            }
            v90 = 0;
            if ( v68 >= 0 )
            {
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v67, 4 * v68);
              m_enum = maximizeArea.m_enum;
            }
          }
        }
        ++v95;
        v49 = (hkBaseObjectVtbl *)((char *)v49 + 4 * m_enum);
        v48 = vpf;
        v50 = v84 + 4;
        v84 += 4i64;
      }
      while ( v95 < vpf->m_size );
      v10 = v97;
    }
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v80);
  }
  return v10;
}

// File Line: 2177
// RVA: 0xCB6830
void __fastcall hkgpConvexHullImpl::generateVertexAdjacencyGraph(
        hkgpConvexHullImpl *this,
        hkArray<int,hkContainerHeapAllocator> *edges,
        hkArray<int,hkContainerHeapAllocator> *vertexOffsets)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // r15
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  __int64 m_numUsed; // r14
  int v9; // ecx
  __int64 v10; // rsi
  int *v11; // rbx
  int v12; // r8d
  int v13; // eax
  __int64 v14; // rdx
  const void **v15; // rcx
  hkgpConvexHullImpl::Triangle *m_used; // r12
  int v17; // esi
  hkgpConvexHullImpl::Vertex **m_vertices; // r14
  const void **v19; // rbx
  hkgpConvexHullImpl::Vertex *v20; // r15
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  hkResultEnum m_enum; // edx
  int v29; // r13d
  __int64 v30; // rbx
  __int64 v31; // r12
  int v32; // esi
  const void **v33; // rax
  int m_size; // ecx
  __int64 v35; // rsi
  int v36; // r14d
  char *v37; // r15
  int v38; // eax
  __int64 v39; // rdi
  int *v40; // rbx
  int v41; // r8d
  const void **array; // [rsp+30h] [rbp-D0h] BYREF
  int v43; // [rsp+38h] [rbp-C8h]
  int v44; // [rsp+3Ch] [rbp-C4h]
  hkErrStream v45; // [rsp+40h] [rbp-C0h] BYREF
  char buf[560]; // [rsp+60h] [rbp-A0h] BYREF
  hkResult result; // [rsp+2A0h] [rbp+1A0h] BYREF
  hkArray<int,hkContainerHeapAllocator> *v48; // [rsp+2B0h] [rbp+1B0h]

  v48 = vertexOffsets;
  v3 = vertexOffsets;
  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v45, buf, 512);
    v6 = hkOstream::operator<<(&v45, "No index available (");
    v7 = hkOstream::operator<<(v6, this->m_uid);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v45);
  }
  m_numUsed = this->m_mesh.m_vertices.m_numUsed;
  v44 = 0x80000000;
  array = 0i64;
  v9 = 0;
  v43 = 0;
  if ( (int)m_numUsed > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 16);
    v9 = v43;
  }
  v10 = v9 - (int)m_numUsed - 1;
  if ( v9 - (int)m_numUsed - 1 >= 0 )
  {
    v11 = (int *)&array[2 * m_numUsed + 1] + 4 * v10 + 1;
    do
    {
      v12 = *v11;
      *(v11 - 1) = 0;
      if ( v12 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v11 - 3),
          4 * v12);
      *(_QWORD *)(v11 - 3) = 0i64;
      *v11 = 0x80000000;
      v11 -= 4;
      --v10;
    }
    while ( v10 >= 0 );
    v9 = v43;
    v3 = v48;
  }
  v13 = m_numUsed - v9;
  v14 = (int)m_numUsed - v9;
  v15 = &array[2 * v9];
  if ( v13 > 0 )
  {
    do
    {
      if ( v15 )
      {
        *v15 = 0i64;
        *((_DWORD *)v15 + 2) = 0;
        *((_DWORD *)v15 + 3) = 0x80000000;
      }
      v15 += 2;
      --v14;
    }
    while ( v14 );
  }
  m_used = this->m_mesh.m_triangles.m_used;
  v43 = m_numUsed;
  if ( m_used )
  {
    do
    {
      v17 = 0;
      m_vertices = m_used->m_vertices;
      do
      {
        v19 = &array[2 * (*m_vertices)->m_index];
        v20 = m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)v17)) & 3];
        if ( *((_DWORD *)v19 + 2) == (*((_DWORD *)v19 + 3) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array[2 * (*m_vertices)->m_index], 4);
        ++v17;
        ++m_vertices;
        *((_DWORD *)*v19 + (int)(*((_DWORD *)v19 + 2))++) = v20->m_index;
      }
      while ( v17 < 3 );
      m_used = m_used->m_next;
    }
    while ( m_used );
    v3 = v48;
  }
  edges->m_size = 0;
  v21 = this->m_mesh.m_vertices.m_numUsed + 3 * this->m_mesh.m_triangles.m_numUsed;
  v22 = edges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < v21 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edges->m_data, v21, 4);
  }
  v24 = this->m_mesh.m_vertices.m_numUsed;
  v25 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < v24 )
  {
    v26 = 2 * v25;
    v27 = this->m_mesh.m_vertices.m_numUsed;
    if ( v24 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v3->m_data, v27, 4);
  }
  m_enum = HK_SUCCESS;
  v3->m_size = v24;
  v29 = 0;
  result.m_enum = HK_SUCCESS;
  if ( v43 > 0 )
  {
    v30 = 0i64;
    v31 = 0i64;
    do
    {
      v32 = (int)array[v30 + 1];
      if ( edges->m_size == (edges->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&edges->m_data, 4);
        m_enum = result.m_enum;
      }
      edges->m_data[edges->m_size++] = v32;
      v33 = array;
      m_size = edges->m_size;
      v35 = 0i64;
      v36 = 0;
      if ( SLODWORD(array[v30 + 1]) > 0 )
      {
        do
        {
          v37 = (char *)v33[v30];
          if ( m_size == (edges->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&edges->m_data, 4);
          ++v36;
          v38 = *(_DWORD *)&v37[v35];
          v35 += 4i64;
          edges->m_data[edges->m_size++] = v38;
          v33 = array;
          m_size = edges->m_size;
        }
        while ( v36 < SLODWORD(array[v30 + 1]) );
        m_enum = result.m_enum;
        v3 = v48;
      }
      ++v29;
      v3->m_data[v31++] = m_enum;
      m_enum += LODWORD(array[v30 + 1]) + 1;
      v30 += 2i64;
      result.m_enum = m_enum;
    }
    while ( v29 < v43 );
  }
  v39 = v43 - 1;
  if ( v43 - 1 >= 0 )
  {
    v40 = (int *)&array[2 * v43 - 1] + 1;
    do
    {
      v41 = *v40;
      *(v40 - 1) = 0;
      if ( v41 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v40 - 3),
          4 * v41);
      *(_QWORD *)(v40 - 3) = 0i64;
      *v40 = 0x80000000;
      v40 -= 4;
      --v39;
    }
    while ( v39 >= 0 );
  }
  v43 = 0;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v44);
}

// File Line: 2209
// RVA: 0xCB6490
void __fastcall hkgpConvexHullImpl::generatePlanesPerVertex(
        hkgpConvexHullImpl *this,
        hkArray<int,hkContainerHeapAllocator> *startPlaneOffsetOut,
        hkArrayBase<unsigned int> *planeIndicesOut)
{
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  __int64 m_numUsed; // r15
  int v9; // edx
  __int64 v10; // rbp
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // r8d
  int v14; // eax
  const void **v15; // rcx
  __int64 v16; // rdx
  hkgpConvexHullImpl::Triangle *m_used; // r14
  int m_index; // edi
  hkgpConvexHullImpl::Vertex **m_vertices; // rsi
  __int64 v20; // rbp
  int v21; // edx
  __int64 v22; // rcx
  const void **v23; // rbx
  __int64 v24; // r9
  _DWORD *v25; // rax
  int v26; // ebx
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  int *m_data; // rax
  __int64 v31; // rbx
  __int64 v32; // rdi
  __int64 v33; // rdi
  int *v34; // rbx
  int v35; // r8d
  const void **array; // [rsp+30h] [rbp-258h] BYREF
  int v37; // [rsp+38h] [rbp-250h]
  int v38; // [rsp+3Ch] [rbp-24Ch]
  hkErrStream v39; // [rsp+40h] [rbp-248h] BYREF
  char buf[512]; // [rsp+60h] [rbp-228h] BYREF
  hkResult result; // [rsp+290h] [rbp+8h] BYREF

  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v39, buf, 512);
    v6 = hkOstream::operator<<(&v39, "No index available (");
    v7 = hkOstream::operator<<(v6, this->m_uid);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v39);
  }
  m_numUsed = this->m_mesh.m_vertices.m_numUsed;
  v38 = 0x80000000;
  v9 = 0;
  array = 0i64;
  v37 = 0;
  if ( (int)m_numUsed > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 16);
    v9 = v37;
  }
  v10 = m_numUsed;
  v11 = v9 - (int)m_numUsed - 1;
  if ( v9 - (int)m_numUsed - 1 >= 0 )
  {
    v12 = (int *)&array[2 * m_numUsed + 1] + 4 * v11 + 1;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 0x80000000;
      v12 -= 4;
      --v11;
    }
    while ( v11 >= 0 );
    v9 = v37;
  }
  v14 = m_numUsed - v9;
  v15 = &array[2 * v9];
  v16 = (int)m_numUsed - v9;
  if ( v14 > 0 )
  {
    do
    {
      if ( v15 )
      {
        *v15 = 0i64;
        *((_DWORD *)v15 + 2) = 0;
        *((_DWORD *)v15 + 3) = 0x80000000;
      }
      v15 += 2;
      --v16;
    }
    while ( v16 );
  }
  m_used = this->m_mesh.m_triangles.m_used;
  v37 = m_numUsed;
  if ( m_used )
  {
    do
    {
      m_index = m_used->m_plane.m_index;
      m_vertices = m_used->m_vertices;
      v20 = 3i64;
      do
      {
        v21 = 0;
        v22 = 0i64;
        v23 = &array[2 * (*m_vertices)->m_index];
        v24 = *((int *)v23 + 2);
        if ( (int)v24 <= 0 )
          goto LABEL_25;
        v25 = *v23;
        while ( *v25 != m_index )
        {
          ++v22;
          ++v21;
          ++v25;
          if ( v22 >= v24 )
            goto LABEL_25;
        }
        if ( v21 < 0 )
        {
LABEL_25:
          if ( (_DWORD)v24 == (*((_DWORD *)v23 + 3) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array[2 * (*m_vertices)->m_index], 4);
          *((_DWORD *)*v23 + (int)(*((_DWORD *)v23 + 2))++) = m_index;
        }
        ++m_vertices;
        --v20;
      }
      while ( v20 );
      m_used = m_used->m_next;
    }
    while ( m_used );
    v10 = m_numUsed;
  }
  planeIndicesOut->m_size = 0;
  v26 = m_numUsed + 1;
  v27 = startPlaneOffsetOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 < (int)m_numUsed + 1 )
  {
    v28 = 2 * v27;
    v29 = m_numUsed + 1;
    if ( v26 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&startPlaneOffsetOut->m_data,
      v29,
      4);
  }
  m_data = startPlaneOffsetOut->m_data;
  startPlaneOffsetOut->m_size = v26;
  v31 = 0i64;
  *m_data = 0;
  if ( v10 > 0 )
  {
    v32 = 0i64;
    do
    {
      hkArrayBase<unsigned int>::_append(
        planeIndicesOut,
        &hkContainerHeapAllocator::s_alloc,
        (char *)array[v32],
        (int)array[v32 + 1]);
      startPlaneOffsetOut->m_data[++v31] = planeIndicesOut->m_size;
      v32 += 2i64;
    }
    while ( v31 < v10 );
  }
  v33 = v37 - 1;
  if ( v37 - 1 >= 0 )
  {
    v34 = (int *)&array[2 * v37 - 1] + 1;
    do
    {
      v35 = *v34;
      *(v34 - 1) = 0;
      if ( v35 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v34 - 3),
          4 * v35);
      *(_QWORD *)(v34 - 3) = 0i64;
      *v34 = 0x80000000;
      v34 -= 4;
      --v33;
    }
    while ( v33 >= 0 );
  }
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v38);
}

// File Line: 2290
// RVA: 0xCB35F0
__int64 __fastcall hkgpConvexHullImpl::splitByPlane<hkgpConvexHullImpl::PositionAsSource>(
        hkgpConvexHullImpl *this,
        hkVector4f *plane,
        hkBaseObject **pos,
        hkBaseObject **neg,
        float thickness)
{
  int v9; // ecx
  __m128 *m_used; // rax
  int v12; // ebx
  int v13; // r8d
  float v14; // xmm5_4
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  int v21; // ecx
  int v22; // eax
  unsigned int v23; // ebx
  int v24; // eax
  int v25; // eax
  hkgpConvexHullImpl::Vertex *m_next; // rbx
  float m_scratch; // xmm0_4
  int v28; // ecx
  __int64 v29; // rax
  hkgpConvexHullImpl::Triangle *i; // rsi
  int v31; // ebx
  __m128 **m_vertices; // rdi
  __m128 *v33; // rdx
  float v34; // xmm3_4
  __m128 *v35; // rcx
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  int v38; // ecx
  _QWORD **Value; // rax
  hkgpConvexHull *v40; // rax
  hkgpConvexHull *v41; // rax
  hkgpConvexHullImpl *m_data; // rcx
  _QWORD **v43; // rax
  hkgpConvexHull *v44; // rax
  hkgpConvexHull *v45; // rax
  hkgpConvexHullImpl *v46; // rcx
  bool v47; // di
  bool v48; // bl
  hkgpConvexHullImpl::Vertex *v49; // rax
  int v50; // edx
  int v51; // ecx
  float v52; // xmm3_4
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  float v56; // xmm1_4
  hkgpConvexHullImpl::Vertex *v57; // rbx
  int v58; // edx
  int v59; // ecx
  __m128 *v60; // rax
  hkgpConvexHullImpl::Vertex *j; // r8
  float v62; // xmm2_4
  __m128 m_quad; // xmm8
  __m128 v64; // xmm0
  __m128 v65; // xmm6
  int v66; // ecx
  int v67; // r14d
  _QWORD **v68; // rax
  hkgpConvexHull *v69; // rax
  hkgpConvexHull *v70; // rax
  hkgpConvexHullImpl *v71; // rcx
  _QWORD **v72; // rax
  hkgpConvexHull *v73; // rax
  hkgpConvexHull *v74; // rax
  hkgpConvexHullImpl *v75; // rcx
  int *v76; // rbx
  int v77; // r8d
  hkErrStream array; // [rsp+30h] [rbp-D0h] BYREF
  int v79; // [rsp+48h] [rbp-B8h]
  int v80; // [rsp+4Ch] [rbp-B4h]
  hkVector4f *points; // [rsp+50h] [rbp-B0h] BYREF
  int numPoints; // [rsp+58h] [rbp-A8h]
  int v83; // [rsp+5Ch] [rbp-A4h] BYREF
  char buf[512]; // [rsp+60h] [rbp-A0h] BYREF
  hkResult result; // [rsp+2D0h] [rbp+1D0h] BYREF
  hkResult v86; // [rsp+2E0h] [rbp+1E0h] BYREF
  float v87; // [rsp+2E8h] [rbp+1E8h]

  if ( pos )
    *pos = 0i64;
  if ( neg )
    *neg = 0i64;
  v9 = this->m_dimensions - 2;
  if ( v9 )
  {
    if ( v9 != 1 )
    {
      hkErrStream::hkErrStream(&array, buf, 512);
      hkOstream::operator<<(&array, "Current dimension not implemented for that operation");
      if ( (unsigned int)hkError::messageError(
                           0x3A86E3EFu,
                           buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           2419) )
        __debugbreak();
      hkOstream::~hkOstream(&array);
      return 4i64;
    }
    m_used = (__m128 *)this->m_mesh.m_vertices.m_used;
    v12 = 0;
    v13 = 0;
    LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0).m128_u32[0];
    v15 = 0i64;
    v16 = 0i64;
    if ( m_used )
    {
      do
      {
        v17 = _mm_mul_ps(m_used[1], plane->m_quad);
        v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, plane->m_quad), 196);
        v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
        if ( m_used->m128_u64[1] )
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
          m_used[2].m128_i32[3] = v20.m128_i32[0];
          if ( v20.m128_f32[0] <= 0.0 )
            ++v12;
          else
            ++v13;
        }
        else
        {
          m_used[2].m128_i32[3] = 0;
        }
        m_used = (__m128 *)m_used->m128_u64[0];
      }
      while ( m_used );
      if ( v13 && v12 )
      {
        v21 = 0;
        v22 = 0;
        array.vfptr = 0i64;
        *(_DWORD *)&array.m_memSizeAndFlags = 0;
        *(_DWORD *)(&array.m_referenceCount + 1) = 0x80000000;
        points = 0i64;
        numPoints = 0;
        v83 = 0x80000000;
        if ( fmin(
               COERCE_FLOAT((unsigned int)(2 * v15.m128_i32[0]) >> 1),
               COERCE_FLOAT((unsigned int)(2 * v16.m128_i32[0]) >> 1)) <= v14 )
          v21 = 1;
        if ( (float)(v16.m128_f32[0] - v15.m128_f32[0]) <= v14 )
          v22 = 1;
        if ( v22 | v21 )
        {
          v23 = ((float)((float)(v15.m128_f32[0] + v16.m128_f32[0]) * 0.5) < 0.0) + 1;
LABEL_92:
          numPoints = 0;
          if ( v83 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, points, 16 * v83);
          points = 0i64;
          v83 = 0x80000000;
          *(_DWORD *)&array.m_memSizeAndFlags = 0;
          if ( *(int *)(&array.m_referenceCount + 1) >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              array.vfptr,
              16 * *(_DWORD *)(&array.m_referenceCount + 1));
          return v23;
        }
        v24 = v13 + this->m_mesh.m_vertices.m_numUsed / 4;
        if ( v24 <= 0 )
          result.m_enum = HK_SUCCESS;
        else
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, v24, 16);
        v25 = v12 + this->m_mesh.m_vertices.m_numUsed / 4;
        if ( (v83 & 0x3FFFFFFF) >= v25 )
        {
          v86.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v25 < 2 * (v83 & 0x3FFFFFFF) )
            v25 = 2 * (v83 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v86, &hkContainerHeapAllocator::s_alloc, (const void **)&points, v25, 16);
        }
        m_next = this->m_mesh.m_vertices.m_used;
        if ( !m_next )
        {
LABEL_52:
          for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
          {
            v31 = 0;
            m_vertices = (__m128 **)i->m_vertices;
            do
            {
              v33 = *m_vertices;
              v34 = (*m_vertices)[2].m128_f32[3];
              if ( v34 > 0.0 )
              {
                v35 = (__m128 *)i->m_vertices[(9i64 >> (2 * (unsigned __int8)v31)) & 3];
                if ( (float)(v35[2].m128_f32[3] * v34) < 0.0 )
                {
                  v36 = _mm_sub_ps(v35[1], v33[1]);
                  v87 = v34 / (float)(v34 - v35[2].m128_f32[3]);
                  v37 = _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0), v36),
                          v33[1]);
                  if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, 16);
                  array.vfptr[*(int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)v37;
                  v38 = numPoints;
                  ++*(_DWORD *)&array.m_memSizeAndFlags;
                  if ( numPoints == (v83 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points, 16);
                    v38 = numPoints;
                  }
                  points[v38] = (hkVector4f)v37;
                  ++numPoints;
                }
              }
              ++v31;
              ++m_vertices;
            }
            while ( v31 < 3 );
          }
          if ( pos )
          {
            Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v40 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
            if ( v40 )
              hkgpConvexHull::hkgpConvexHull(v40);
            else
              v41 = 0i64;
            *pos = v41;
            m_data = v41->m_data;
            *(_DWORD *)&m_data->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&this->m_config.m_allowLowerDimensions.m_bool;
            m_data->m_config.m_minCosAngle = this->m_config.m_minCosAngle;
            *(_DWORD *)&m_data->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&this->m_config.m_setSourceIndices.m_bool;
            *(_DWORD *)&m_data->m_config.m_internalInputs.m_bool = *(_DWORD *)&this->m_config.m_internalInputs.m_bool;
          }
          if ( neg )
          {
            v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v44 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v43[11] + 8i64))(v43[11], 40i64);
            if ( v44 )
              hkgpConvexHull::hkgpConvexHull(v44);
            else
              v45 = 0i64;
            *neg = v45;
            v46 = v45->m_data;
            *(_DWORD *)&v46->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&this->m_config.m_allowLowerDimensions.m_bool;
            v46->m_config.m_minCosAngle = this->m_config.m_minCosAngle;
            *(_DWORD *)&v46->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&this->m_config.m_setSourceIndices.m_bool;
            *(_DWORD *)&v46->m_config.m_internalInputs.m_bool = *(_DWORD *)&this->m_config.m_internalInputs.m_bool;
          }
          v47 = pos
             && hkgpConvexHullImpl::build(
                  (hkgpConvexHullImpl *)(*pos)[2].vfptr,
                  (hkVector4f *)array.vfptr,
                  *(const int *)&array.m_memSizeAndFlags,
                  0,
                  this) == this->m_dimensions;
          v48 = neg
             && hkgpConvexHullImpl::build((hkgpConvexHullImpl *)(*neg)[2].vfptr, points, numPoints, 0, this) == this->m_dimensions;
          if ( !v47 && pos )
          {
            if ( *pos )
              (*pos)->vfptr->__vecDelDtor(*pos, 1i64);
            *pos = 0i64;
          }
          if ( !v48 && neg )
          {
            if ( *neg )
              (*neg)->vfptr->__vecDelDtor(*neg, 1i64);
            *neg = 0i64;
          }
          v23 = 3;
          goto LABEL_92;
        }
        while ( 1 )
        {
          m_scratch = m_next->m_scratch;
          if ( m_scratch == 0.0 )
          {
            if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, 16);
            array.vfptr[*(int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)m_next->m_source;
            v28 = numPoints;
            ++*(_DWORD *)&array.m_memSizeAndFlags;
            if ( numPoints == (v83 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points, 16);
              v28 = numPoints;
            }
            v29 = v28;
          }
          else
          {
            if ( m_scratch > 0.0 )
            {
              if ( *(_DWORD *)&array.m_memSizeAndFlags == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, 16);
              array.vfptr[*(int *)&array.m_memSizeAndFlags] = (hkBaseObjectVtbl)m_next->m_source;
              ++*(_DWORD *)&array.m_memSizeAndFlags;
              goto LABEL_51;
            }
            if ( numPoints == (v83 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points, 16);
            v29 = numPoints;
          }
          points[v29] = m_next->m_source;
          ++numPoints;
LABEL_51:
          m_next = m_next->m_next;
          if ( !m_next )
            goto LABEL_52;
        }
      }
      if ( v12 <= v13 )
        return v13 != 0;
      return 2i64;
    }
    return 0i64;
  }
  v49 = this->m_mesh.m_vertices.m_used;
  v50 = 0;
  v51 = 0;
  if ( !v49 )
    return 0i64;
  LODWORD(v52) = _mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0).m128_u32[0];
  do
  {
    v53 = _mm_mul_ps(v49->m_source.m_quad, plane->m_quad);
    v54 = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, plane->m_quad), 196);
    v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 78), v54);
    v56 = _mm_shuffle_ps(v55, v55, 177).m128_f32[0] + v55.m128_f32[0];
    v49->m_scratch = v56;
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v56)) >> 1) > v52 )
    {
      if ( v49->m_scratch >= 0.0 )
        ++v51;
      else
        ++v50;
    }
    else
    {
      v49->m_scratch = 0.0;
    }
    v49 = v49->m_next;
  }
  while ( v49 );
  if ( !v50 )
    return v51 != 0;
  if ( !v51 )
    return 2i64;
  v57 = this->m_mesh.m_vertices.m_used;
  v58 = 0;
  v59 = 0;
  array.vfptr = 0i64;
  *(_DWORD *)(&array.m_referenceCount + 1) = 0x80000000;
  array.m_writer.m_pntr = 0i64;
  *(_DWORD *)&array.m_memSizeAndFlags = 0;
  v79 = 0;
  v80 = 0x80000000;
  v60 = (__m128 *)v57;
  if ( v57 )
  {
    for ( j = v57->m_next; j; j = j->m_next )
      v60 = (__m128 *)j;
    do
    {
      v62 = v57->m_scratch;
      m_quad = v57->m_source.m_quad;
      if ( (float)(v60[2].m128_f32[3] * v62) < 0.0 )
      {
        v64 = _mm_sub_ps(m_quad, v60[1]);
        v87 = v60[2].m128_f32[3] / (float)(v60[2].m128_f32[3] - v62);
        v65 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0), v64), v60[1]);
        if ( v58 == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, 16);
          v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        }
        array.vfptr[v58] = (hkBaseObjectVtbl)v65;
        v66 = v79;
        ++*(_DWORD *)&array.m_memSizeAndFlags;
        if ( v79 == (v80 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_writer.m_pntr, 16);
          v66 = v79;
        }
        array.m_writer.m_pntr[v66] = (hkStreamWriter)v65;
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        v59 = ++v79;
      }
      if ( v57->m_scratch > 0.0 )
        goto LABEL_126;
      if ( v58 == (*(_DWORD *)(&array.m_referenceCount + 1) & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.vfptr, 16);
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
      }
      array.vfptr[v58] = (hkBaseObjectVtbl)m_quad;
      v59 = v79;
      v58 = ++*(_DWORD *)&array.m_memSizeAndFlags;
      if ( v57->m_scratch >= 0.0 )
      {
LABEL_126:
        if ( v59 == (v80 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_writer.m_pntr, 16);
          v59 = v79;
        }
        array.m_writer.m_pntr[v59] = (hkStreamWriter)m_quad;
        v58 = *(_DWORD *)&array.m_memSizeAndFlags;
        v59 = ++v79;
      }
      v60 = (__m128 *)v57;
      v57 = v57->m_next;
    }
    while ( v57 );
  }
  v67 = 1;
  if ( neg )
  {
    v68 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v69 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v68[11] + 8i64))(v68[11], 40i64);
    if ( v69 )
      hkgpConvexHull::hkgpConvexHull(v69);
    else
      v70 = 0i64;
    *neg = v70;
    v71 = v70->m_data;
    *(_DWORD *)&v71->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&this->m_config.m_allowLowerDimensions.m_bool;
    v71->m_config.m_minCosAngle = this->m_config.m_minCosAngle;
    *(_DWORD *)&v71->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&this->m_config.m_setSourceIndices.m_bool;
    *(_DWORD *)&v71->m_config.m_internalInputs.m_bool = *(_DWORD *)&this->m_config.m_internalInputs.m_bool;
    (*neg)[2].vfptr[16] = (hkBaseObjectVtbl)this->m_projectionPlane;
    if ( hkgpConvexHullImpl::build(
           (hkgpConvexHullImpl *)(*neg)[2].vfptr,
           (hkVector4f *)array.vfptr,
           *(const int *)&array.m_memSizeAndFlags,
           1,
           this) != this->m_dimensions )
    {
      if ( *neg )
        (*neg)->vfptr->__vecDelDtor(*neg, 1i64);
      *neg = 0i64;
    }
  }
  if ( pos )
  {
    v72 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v73 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v72[11] + 8i64))(v72[11], 40i64);
    if ( v73 )
      hkgpConvexHull::hkgpConvexHull(v73);
    else
      v74 = 0i64;
    *pos = v74;
    v75 = v74->m_data;
    *(_DWORD *)&v75->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&this->m_config.m_allowLowerDimensions.m_bool;
    v75->m_config.m_minCosAngle = this->m_config.m_minCosAngle;
    *(_DWORD *)&v75->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&this->m_config.m_setSourceIndices.m_bool;
    *(_DWORD *)&v75->m_config.m_internalInputs.m_bool = *(_DWORD *)&this->m_config.m_internalInputs.m_bool;
    (*pos)[2].vfptr[16] = (hkBaseObjectVtbl)this->m_projectionPlane;
    if ( hkgpConvexHullImpl::build(
           (hkgpConvexHullImpl *)(*pos)[2].vfptr,
           (hkVector4f *)array.m_writer.m_pntr,
           v79,
           1,
           this) != this->m_dimensions )
    {
      if ( *pos )
        (*pos)->vfptr->__vecDelDtor(*pos, 1i64);
      *pos = 0i64;
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
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v76 - 3),
        16 * v77);
    --v67;
    *(_QWORD *)(v76 - 3) = 0i64;
    *v76 = 0x80000000;
  }
  while ( v67 >= 0 );
  return 3i64;
}

// File Line: 2434
// RVA: 0xCB7960
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::getSpan(
        hkgpConvexHullImpl *this,
        hkSimdFloat32 *result,
        hkVector4f *axis,
        hkSimdFloat32 *minBound,
        hkSimdFloat32 *maxBound)
{
  int m_numUsed; // edi
  hkVector4f *m_data; // rdx
  int m_size; // eax
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  hkVector4f *v13; // rax
  int v14; // edi
  hkVector4f *v15; // rdx
  int v16; // eax
  hkgpConvexHullImpl::Vertex *i; // rax
  hkVector4f *v18; // rcx
  hkSimdFloat32 *v19; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 m_real; // xmm0
  hkSimdFloat32 *v24; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-40h] BYREF
  hkVector4f direction; // [rsp+40h] [rbp-30h] BYREF
  hkVector4f vertexOut; // [rsp+50h] [rbp-20h] BYREF
  hkVector4f v28; // [rsp+60h] [rbp-10h] BYREF
  hkResult resulta; // [rsp+A0h] [rbp+30h] BYREF

  direction.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), axis->m_quad);
  if ( !this->m_supportCache.m_size )
  {
    m_numUsed = this->m_mesh.m_vertices.m_numUsed;
    m_data = 0i64;
    m_size = 0;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    if ( m_numUsed > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, m_numUsed, 16);
      m_size = array.m_size;
      m_data = array.m_data;
    }
    m_used = this->m_mesh.m_vertices.m_used;
    for ( array.m_size = m_numUsed + m_size; m_used; m_used = m_used->m_next )
    {
      v13 = m_data++;
      *v13 = m_used->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(&array, &this->m_supportCache);
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        16 * array.m_capacityAndFlags);
  }
  hkGeometryProcessing::getSupportingVertex(&this->m_supportCache, axis, &vertexOut);
  if ( !this->m_supportCache.m_size )
  {
    v14 = this->m_mesh.m_vertices.m_numUsed;
    v15 = 0i64;
    v16 = 0;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    if ( v14 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v14, 16);
      v16 = array.m_size;
      v15 = array.m_data;
    }
    array.m_size = v14 + v16;
    for ( i = this->m_mesh.m_vertices.m_used; i; i = i->m_next )
    {
      v18 = v15++;
      *v18 = i->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(&array, &this->m_supportCache);
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        16 * array.m_capacityAndFlags);
  }
  hkGeometryProcessing::getSupportingVertex(&this->m_supportCache, &direction, &v28);
  v19 = maxBound;
  v20 = _mm_mul_ps(axis->m_quad, vertexOut.m_quad);
  maxBound->m_real = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                       _mm_shuffle_ps(v20, v20, 170));
  v21 = _mm_mul_ps(axis->m_quad, v28.m_quad);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  *minBound = (hkSimdFloat32)v22;
  m_real = v19->m_real;
  v24 = result;
  result->m_real = _mm_sub_ps(m_real, v22);
  return v24;
}

// File Line: 2446
// RVA: 0xCB7000
void __fastcall hkgpConvexHullImpl::getOrientedBoundingBox(
        hkgpConvexHullImpl *this,
        hkVector4f *halfExtents,
        hkTransformf *worldTransform)
{
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  float v8; // xmm7_4
  int v9; // edi
  float i; // xmm8_4
  __int64 v11; // rsi
  __m128 m_real; // xmm6
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  __m128 v17; // xmm2
  hkErrStream result; // [rsp+30h] [rbp-2D8h] BYREF
  hkSimdFloat32 minBound; // [rsp+50h] [rbp-2B8h] BYREF
  hkSimdFloat32 maxBound; // [rsp+60h] [rbp-2A8h] BYREF
  hkSimdFloat32 v21; // [rsp+70h] [rbp-298h] BYREF
  hkSimdFloat32 v22; // [rsp+80h] [rbp-288h] BYREF
  hkTransformf v23; // [rsp+90h] [rbp-278h] BYREF
  char buf[512]; // [rsp+D0h] [rbp-238h] BYREF

  if ( this->m_dimensions >= 3 )
  {
    if ( !this->m_hasIndexing )
    {
      hkErrStream::hkErrStream(&result, buf, 512);
      v6 = hkOstream::operator<<(&result, "No index available (");
      v7 = hkOstream::operator<<(v6, this->m_uid);
      hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
      if ( (unsigned int)hkError::messageError(
                           0x79F9D886u,
                           buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConv"
                           "exHullInternals.h",
                           358) )
        __debugbreak();
      hkOstream::~hkOstream(&result);
    }
    v8 = 3.40282e38;
    v9 = 0;
    for ( i = 3.40282e38; v9 < this->m_planes.m_size; ++v9 )
    {
      v11 = v9;
      hkgpConvexHullImpl::getSpan(this, &v22, &this->m_planes.m_data[v11], &minBound, &maxBound);
      m_real = v22.m_real;
      if ( v22.m_real.m128_f32[0] < v8 )
      {
        hkgpConvexHullImpl::getOrientedRectangle(this, &v21, &this->m_planes.m_data[v11], (hkVector4f *)&result, &v23);
        if ( (float)((float)(maxBound.m_real.m128_f32[0] - minBound.m_real.m128_f32[0]) * v21.m_real.m128_f32[0]) < i )
        {
          i = (float)(maxBound.m_real.m128_f32[0] - minBound.m_real.m128_f32[0]) * v21.m_real.m128_f32[0];
          v8 = m_real.m128_f32[0];
          v13.m_quad = (__m128)v23.m_rotation.m_col0;
          halfExtents->m_quad = _mm_shuffle_ps(
                                  (__m128)result.hkReferencedObject,
                                  _mm_unpackhi_ps((__m128)result.hkReferencedObject, m_real),
                                  180);
          v14.m_quad = (__m128)v23.m_rotation.m_col1;
          worldTransform->m_rotation.m_col0 = (hkVector4f)v13.m_quad;
          v15.m_quad = (__m128)v23.m_rotation.m_col2;
          worldTransform->m_rotation.m_col1 = (hkVector4f)v14.m_quad;
          v16.m_quad = (__m128)v23.m_translation;
          worldTransform->m_rotation.m_col2 = (hkVector4f)v15.m_quad;
          worldTransform->m_translation = (hkVector4f)v16.m_quad;
        }
      }
    }
    v17 = _mm_mul_ps(_mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 170), (__m128)xmmword_141A711B0);
    halfExtents->m_quad = _mm_shuffle_ps(halfExtents->m_quad, _mm_unpackhi_ps(halfExtents->m_quad, v17), 180);
    worldTransform->m_translation.m_quad = _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)0i64, v17),
                                               worldTransform->m_rotation.m_col2.m_quad),
                                             worldTransform->m_translation.m_quad);
  }
  else
  {
    hkgpConvexHullImpl::getOrientedRectangle(
      this,
      (hkSimdFloat32 *)&result,
      &this->m_projectionPlane,
      halfExtents,
      worldTransform);
  }
}

// File Line: 2484
// RVA: 0xCB7240
hkSimdFloat32 *__fastcall hkgpConvexHullImpl::getOrientedRectangle(
        hkgpConvexHullImpl *this,
        hkSimdFloat32 *result,
        hkVector4f *projectionPlane,
        hkVector4f *halfExtents,
        hkTransformf *worldTransform)
{
  hkVector4f *v5; // rsi
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  __m128 v12; // xmm9
  int m_dimensions; // eax
  __m128 v14; // xmm6
  __m128 v15; // xmm13
  __m128 v16; // xmm14
  __m128 v17; // xmm10
  __m128 v18; // xmm12
  __m128 v19; // xmm8
  hkgpConvexHullImpl::Vertex *v20; // rax
  int v21; // edx
  int *m_x; // rcx
  int v23; // r8d
  hkgpConvexHullImpl::Triangle *m_triangle; // rcx
  hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator *v25; // rax
  __int64 m_index; // rdx
  __int64 v27; // rax
  hkVector4f *m_data; // rcx
  __m128 m_quad; // xmm8
  __int64 v30; // rax
  __int64 v31; // rdx
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
  hkSimdFloat32 *v71; // rax
  hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator v72; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f v73; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f axis; // [rsp+50h] [rbp-98h] BYREF
  __m256i v75; // [rsp+60h] [rbp-88h] BYREF
  hkSimdFloat32 resulta; // [rsp+88h] [rbp-60h] BYREF
  hkSimdFloat32 v77; // [rsp+98h] [rbp-50h] BYREF
  hkSimdFloat32 v78; // [rsp+A8h] [rbp-40h] BYREF
  hkSimdFloat32 minBound; // [rsp+B8h] [rbp-30h] BYREF
  hkSimdFloat32 maxBound; // [rsp+C8h] [rbp-20h] BYREF
  char buf[536]; // [rsp+D8h] [rbp-10h] BYREF
  hkVector4f *v82; // [rsp+3B8h] [rbp+2D0h]

  if ( !this->m_hasIndexing )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v75.m256i_u64[1], buf, 512);
    v10 = hkOstream::operator<<((hkOstream *)&v75.m256i_u64[1], "No index available (");
    v11 = hkOstream::operator<<(v10, this->m_uid);
    hkOstream::operator<<(v11, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v75.m256i_u64[1]);
  }
  v12 = (__m128)xmmword_141A712A0;
  m_dimensions = this->m_dimensions;
  v14 = (__m128)xmmword_141A711B0;
  v15 = 0i64;
  v16 = 0i64;
  v17 = (__m128)xmmword_141A712A0;
  v18 = (__m128)xmmword_141A712A0;
  v19 = (__m128)xmmword_141A712A0;
  *(_OWORD *)v75.m256i_i8 = xmmword_141A712A0;
  *result = (hkSimdFloat32)xmmword_141A712A0;
  *(_OWORD *)&v75.m256i_u64[2] = xmmword_141A711B0;
  if ( m_dimensions == 3 )
  {
    v72.m_edge.m_triangle = this->m_mesh.m_triangles.m_used;
    v72.m_edge.m_index = 0;
    if ( v72.m_edge.m_triangle )
    {
      v20 = v72.m_edge.m_triangle->m_vertices[0];
      v21 = 0;
      m_x = v20->m_x;
      do
      {
        v23 = *(int *)((char *)m_x + (char *)v72.m_edge.m_triangle->m_vertices[1] - (char *)v20);
        if ( *m_x < v23 )
          break;
        if ( *m_x > v23 )
        {
          if ( (v72.m_edge.m_triangle->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v72);
          break;
        }
        ++v21;
        ++m_x;
      }
      while ( v21 < 3 );
    }
    m_triangle = v72.m_edge.m_triangle;
    v25 = &v72;
    if ( !v72.m_edge.m_triangle )
      v25 = 0i64;
    if ( v25 )
    {
      do
      {
        m_index = m_triangle->m_plane.m_index;
        v27 = *(int *)((m_triangle->m_links[v72.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) + 88);
        if ( (_DWORD)m_index != (_DWORD)v27 )
        {
          m_data = this->m_planes.m_data;
          m_quad = projectionPlane->m_quad;
          v30 = v27;
          v31 = m_index;
          v32 = _mm_mul_ps(m_data[v30].m_quad, projectionPlane->m_quad);
          v33 = _mm_mul_ps(m_data[v31].m_quad, projectionPlane->m_quad);
          if ( (float)((float)((float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0] + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
                             + _mm_shuffle_ps(v32, v32, 170).m128_f32[0])
                     * (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
                             + _mm_shuffle_ps(v33, v33, 170).m128_f32[0])) > 0.0 )
            goto LABEL_22;
          v34 = _mm_shuffle_ps(m_quad, m_quad, 201);
          v35 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_data[v30].m_quad, m_data[v30].m_quad, 201), m_data[v31].m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_data[v31].m_quad, m_data[v31].m_quad, 201), m_data[v30].m_quad));
          v36 = _mm_shuffle_ps(v35, v35, 201);
          v37 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), m_quad), _mm_mul_ps(v36, v34));
          v38 = _mm_shuffle_ps(v37, v37, 201);
          v39 = _mm_mul_ps(v38, v38);
          v40 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170));
          v41 = _mm_rsqrt_ps(v40);
          v42 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v40), (__m128)0i64);
          v43 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v40, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                          _mm_mul_ps(v41, *(__m128 *)_xmm))),
                      v38),
                    v42),
                  _mm_andnot_ps(v42, v38));
          axis.m_quad = v43;
          if ( !_mm_movemask_ps(v42) )
            goto LABEL_22;
          v44 = _mm_sub_ps(_mm_mul_ps(v43, v34), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), m_quad));
          v45 = _mm_shuffle_ps(v44, v44, 201);
          v46 = _mm_mul_ps(v45, v45);
          v47 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                  _mm_shuffle_ps(v46, v46, 170));
          v48 = _mm_rsqrt_ps(v47);
          v49 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v47), (__m128)0i64);
          v73.m_quad = _mm_or_ps(
                         _mm_and_ps(
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v47, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                 _mm_mul_ps(v48, *(__m128 *)_xmm))),
                             v45),
                           v49),
                         _mm_andnot_ps(v49, v45));
          if ( _mm_movemask_ps(v49) )
          {
            hkgpConvexHullImpl::getSpan(this, &resulta, &axis, &minBound, &maxBound);
            hkgpConvexHullImpl::getSpan(this, (hkSimdFloat32 *)&v75.m256i_u64[1], &v73, &v77, &v78);
            v50 = _mm_mul_ps(resulta.m_real, *(__m128 *)&v75.m256i_u64[1]);
            v51 = _mm_cmplt_ps(v50, result->m_real);
            v52 = _mm_and_ps(axis.m_quad, v51);
            v53 = _mm_and_ps(v51, v50);
            v54 = _mm_andnot_ps(v51, result->m_real);
            v55 = _mm_and_ps(resulta.m_real, v51);
            v19 = _mm_or_ps(_mm_andnot_ps(v51, *(__m128 *)v75.m256i_i8), _mm_and_ps(*(__m128 *)&v75.m256i_u64[1], v51));
            *(__m128 *)v75.m256i_i8 = v19;
            result->m_real = _mm_or_ps(v53, v54);
            v15 = _mm_or_ps(_mm_andnot_ps(v51, v15), v52);
            v16 = _mm_or_ps(_mm_andnot_ps(v51, v16), _mm_and_ps(v73.m_quad, v51));
            v18 = _mm_or_ps(_mm_andnot_ps(v51, v18), v55);
            v12 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(_mm_add_ps(maxBound.m_real, minBound.m_real), *(__m128 *)&v75.m256i_u64[2]),
                      v51),
                    _mm_andnot_ps(v51, v12));
            v17 = _mm_or_ps(
                    _mm_and_ps(_mm_mul_ps(_mm_add_ps(v78.m_real, v77.m_real), *(__m128 *)&v75.m256i_u64[2]), v51),
                    _mm_andnot_ps(v51, v17));
          }
          else
          {
LABEL_22:
            v19 = *(__m128 *)v75.m256i_i8;
          }
        }
        hkgpAbstractMesh<hkgpConvexHullImpl::Edge,hkgpConvexHullImpl::Vertex,hkgpConvexHullImpl::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v72);
        m_triangle = v72.m_edge.m_triangle;
        v56 = &v72;
        if ( !v72.m_edge.m_triangle )
          v56 = 0i64;
      }
      while ( v56 );
LABEL_33:
      v14 = *(__m128 *)&v75.m256i_u64[2];
    }
  }
  else if ( m_dimensions == 2 )
  {
    v57 = 0;
    if ( this->m_planes.m_size > 0 )
    {
      v82 = v5;
      v58 = 0i64;
      do
      {
        v59 = projectionPlane->m_quad;
        v73.m_quad = (__m128)this->m_planes.m_data[v58];
        v60 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v73.m_quad, v73.m_quad, 201), v59),
                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v73.m_quad));
        v61 = _mm_shuffle_ps(v60, v60, 201);
        v62 = _mm_mul_ps(v61, v61);
        v63 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                _mm_shuffle_ps(v62, v62, 170));
        v64 = _mm_rsqrt_ps(v63);
        v65 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v63), (__m128)0i64);
        axis.m_quad = _mm_or_ps(
                        _mm_and_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v63, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                                _mm_mul_ps(v64, *(__m128 *)_xmm))),
                            v61),
                          v65),
                        _mm_andnot_ps(v65, v61));
        if ( _mm_movemask_ps(v65) )
        {
          hkgpConvexHullImpl::getSpan(this, (hkSimdFloat32 *)&v75.m256i_u64[1], &v73, &v77, &v78);
          hkgpConvexHullImpl::getSpan(this, &resulta, &axis, &minBound, &maxBound);
          v66 = _mm_mul_ps(*(__m128 *)&v75.m256i_u64[1], resulta.m_real);
          v67 = _mm_cmplt_ps(v66, result->m_real);
          v68 = _mm_and_ps(*(__m128 *)&v75.m256i_u64[1], v67);
          v69 = _mm_and_ps(resulta.m_real, v67);
          result->m_real = _mm_or_ps(_mm_andnot_ps(v67, result->m_real), _mm_and_ps(v67, v66));
          v15 = _mm_or_ps(_mm_andnot_ps(v67, v15), _mm_and_ps(v73.m_quad, v67));
          v16 = _mm_or_ps(_mm_andnot_ps(v67, v16), _mm_and_ps(axis.m_quad, v67));
          v18 = _mm_or_ps(_mm_andnot_ps(v67, v18), v68);
          v19 = _mm_or_ps(_mm_andnot_ps(v67, v19), v69);
          v12 = _mm_or_ps(
                  _mm_and_ps(_mm_mul_ps(_mm_add_ps(v78.m_real, v77.m_real), *(__m128 *)&v75.m256i_u64[2]), v67),
                  _mm_andnot_ps(v67, v12));
          v17 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(maxBound.m_real, minBound.m_real), *(__m128 *)&v75.m256i_u64[2]),
                    v67),
                  _mm_andnot_ps(v67, v17));
        }
        ++v57;
        ++v58;
      }
      while ( v57 < this->m_planes.m_size );
      goto LABEL_33;
    }
  }
  v70 = _mm_add_ps(_mm_mul_ps(v17, v16), _mm_mul_ps(v12, v15));
  v82[3] = (hkVector4f)v70;
  v82[3].m_quad = _mm_sub_ps(
                    v70,
                    _mm_mul_ps(
                      _mm_shuffle_ps(projectionPlane->m_quad, projectionPlane->m_quad, 255),
                      projectionPlane->m_quad));
  *v82 = (hkVector4f)v15;
  v82[1] = (hkVector4f)v16;
  v82[2] = (hkVector4f)projectionPlane->m_quad;
  v71 = result;
  halfExtents->m_quad = _mm_mul_ps(
                          _mm_movelh_ps(_mm_unpacklo_ps(v18, v19), _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad)),
                          v14);
  return v71;
}

