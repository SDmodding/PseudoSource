// File Line: 106
// RVA: 0xB7B0C0
void __fastcall hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(hkaiEdgeGeometryRaycaster *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_ignoreFaceIndex = -1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgeGeometryRaycaster::`vftable;
  this->m_edgeGeometry.m_pntr = 0i64;
  this->m_geometry.m_pntr = 0i64;
  this->m_carverGeometry.m_pntr = 0i64;
  this->m_faceEdges.m_faceEdges.m_data = 0i64;
  this->m_faceEdges.m_faceEdges.m_size = 0;
  this->m_faceEdges.m_faceEdges.m_capacityAndFlags = 0x80000000;
  this->m_faceEdges.m_faceStartEdges.m_data = 0i64;
  this->m_faceEdges.m_faceStartEdges.m_size = 0;
  this->m_faceEdges.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  this->m_facePlanes.m_data = 0i64;
  this->m_facePlanes.m_size = 0;
  this->m_facePlanes.m_capacityAndFlags = 0x80000000;
  this->m_tree = 0i64;
  this->m_hitFilter.m_pntr = 0i64;
  this->m_faceFlagMask.m_storage = 15;
}

// File Line: 112
// RVA: 0xB7B130
void __fastcall hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(hkaiEdgeGeometryRaycaster *this)
{
  void **m_tree; // rdi
  int v3; // eax
  _QWORD **Value; // rax
  hkaiEdgeGeometryHitFilter *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkGeometry *v7; // rcx
  hkGeometry *v8; // rcx
  hkaiEdgeGeometry *v9; // rcx

  m_tree = (void **)this->m_tree;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgeGeometryRaycaster::`vftable;
  if ( m_tree )
  {
    v3 = *((_DWORD *)m_tree + 3);
    *((_DWORD *)m_tree + 2) = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *m_tree,
        48 * (v3 & 0x3FFFFFFF));
    *m_tree = 0i64;
    *((_DWORD *)m_tree + 3) = 0x80000000;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void **, __int64))(*Value[11] + 16i64))(Value[11], m_tree, 40i64);
  }
  m_pntr = this->m_hitFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_hitFilter.m_pntr = 0i64;
  m_capacityAndFlags = this->m_facePlanes.m_capacityAndFlags;
  this->m_facePlanes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_facePlanes.m_data,
      16 * m_capacityAndFlags);
  this->m_facePlanes.m_data = 0i64;
  this->m_facePlanes.m_capacityAndFlags = 0x80000000;
  hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&this->m_faceEdges);
  v7 = this->m_carverGeometry.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_carverGeometry.m_pntr = 0i64;
  v8 = this->m_geometry.m_pntr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  this->m_geometry.m_pntr = 0i64;
  v9 = this->m_edgeGeometry.m_pntr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  this->m_edgeGeometry.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 122
// RVA: 0xB7B260
hkResult *__fastcall hkaiEdgeGeometryRaycaster::init(
        hkaiEdgeGeometryRaycaster *this,
        hkResult *result,
        hkaiEdgeGeometry *geom)
{
  hkResult *v4; // r13
  hkaiEdgeGeometry *m_pntr; // rcx
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  __int64 v12; // r10
  __int64 v13; // r11
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  __m128 v15; // xmm3
  hkaiEdgeGeometry::Edge *const *v16; // rbx
  int **v17; // r8
  int **v18; // rdx
  int *v19; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  _QWORD **Value; // rax
  hkcdDynamicTree::DefaultTree48Storage *v25; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *v26; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *v27; // rbx
  __int64 m_size; // rdi
  __int64 v29; // r14
  unsigned int v30; // r12d
  __int64 v31; // r13
  __m128 v32; // xmm11
  hkaiEdgeGeometry::Edge *const **v33; // rax
  __m128 v34; // xmm7
  int v35; // r8d
  int **v36; // rdx
  int **v37; // r9
  __m128 v38; // xmm6
  hkVector4f *v39; // r10
  int *v40; // rax
  __int64 m_firstFree; // r15
  hkcdDynamicTree::CodecRaw<unsigned int> *v42; // rdx
  __int64 v43; // rdi
  hkcdDynamicTree::CodecRaw<unsigned int> *v44; // rax
  __int64 m_root; // rbp
  __m128 m_quad; // xmm7
  __m128 v47; // xmm8
  __int64 v48; // rdx
  __m128 *p_m_quad; // r9
  __int64 v50; // r11
  __int64 v51; // rax
  __m128 v52; // xmm9
  __m128 v53; // xmm10
  __int64 v54; // r8
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  __int64 v57; // rdx
  __m128 *v58; // rdx
  __m128 v59; // xmm2
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  __m128 v63; // xmm6
  __m128 v64; // xmm5
  __m128 v65; // xmm5
  __int64 v66; // r10
  int v67; // eax
  signed __int64 v68; // rcx
  __m128 v69; // xmm1
  __int64 v70[2]; // [rsp+30h] [rbp-A8h]
  hkResult resulta; // [rsp+E0h] [rbp+8h] BYREF
  hkResult *v72; // [rsp+E8h] [rbp+10h]
  hkResult v73; // [rsp+F0h] [rbp+18h] BYREF

  v72 = result;
  v4 = result;
  if ( geom )
    hkReferencedObject::addReference(geom);
  m_pntr = this->m_edgeGeometry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_edgeGeometry.m_pntr = geom;
  hkaiFaceEdges::setGeometry(&this->m_faceEdges, &resulta, geom);
  if ( resulta.m_enum )
  {
    v4->m_enum = HK_FAILURE;
    return v4;
  }
  v8 = this->m_faceEdges.m_faceStartEdges.m_size - 1;
  v9 = this->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 >= v8 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_13;
  }
  v10 = 2 * v9;
  if ( v8 < v10 )
    v8 = v10;
  hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_facePlanes, v8, 16);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_13:
    hkaiEdgeGeometry::calculateFaceNormals(this->m_edgeGeometry.m_pntr, &this->m_faceEdges, &this->m_facePlanes);
    v11 = 0;
    if ( this->m_edgeGeometry.m_pntr->m_faces.m_size > 0 )
    {
      v12 = 0i64;
      v13 = 0i64;
      do
      {
        m_data = this->m_faceEdges.m_faceStartEdges.m_data;
        ++v13;
        v15 = 0i64;
        v16 = m_data[v13 - 1];
        v17 = (int **)m_data[v13];
        v18 = (int **)v16;
        if ( v16 != (hkaiEdgeGeometry::Edge *const *)v17 )
        {
          do
          {
            v19 = *v18++;
            v20 = _mm_mul_ps(
                    this->m_edgeGeometry.m_pntr->m_vertices.m_data[*v19].m_quad,
                    this->m_facePlanes.m_data[v12].m_quad);
            v15 = _mm_add_ps(
                    v15,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                      _mm_shuffle_ps(v20, v20, 170)));
          }
          while ( v18 != v17 );
        }
        v21 = 0i64;
        ++v11;
        ++v12;
        v21.m128_f32[0] = (float)(int)(((char *)v17 - (char *)v16) >> 3);
        v22 = _mm_shuffle_ps(v21, v21, 0);
        v23 = _mm_rcp_ps(v22);
        this->m_facePlanes.m_data[v12 - 1].m_quad = _mm_shuffle_ps(
                                                      this->m_facePlanes.m_data[v12 - 1].m_quad,
                                                      _mm_unpackhi_ps(
                                                        this->m_facePlanes.m_data[v12 - 1].m_quad,
                                                        _mm_sub_ps(
                                                          (__m128)0i64,
                                                          _mm_mul_ps(
                                                            v15,
                                                            _mm_mul_ps(
                                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)),
                                                              v23)))),
                                                      196);
      }
      while ( v11 < this->m_edgeGeometry.m_pntr->m_faces.m_size );
    }
    if ( this->m_edgeGeometry.m_pntr->m_edges.m_size )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                       Value[11],
                                                       40i64);
      if ( v25 )
      {
        EdgeGeomRaycastAabbTree::EdgeGeomRaycastAabbTree(v25);
        v27 = v26;
      }
      else
      {
        v27 = 0i64;
      }
      this->m_tree = v27;
      if ( !v27
        || (m_size = this->m_edgeGeometry.m_pntr->m_faces.m_size,
            hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
              v27,
              &resulta,
              2 * m_size),
            resulta.m_enum) )
      {
        v4->m_enum = HK_FAILURE;
        return v4;
      }
      v29 = 0i64;
      v30 = 0;
      if ( (int)m_size > 0 )
      {
        v31 = m_size;
        v32 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        do
        {
          v33 = this->m_faceEdges.m_faceStartEdges.m_data;
          v34 = (__m128)xmmword_141A712A0;
          v35 = 0;
          v36 = (int **)v33[v29];
          v37 = (int **)v33[v29 + 1];
          v38 = _mm_xor_ps(v32, (__m128)xmmword_141A712A0);
          if ( v36 != v37 )
          {
            v39 = this->m_edgeGeometry.m_pntr->m_vertices.m_data;
            do
            {
              v40 = *v36++;
              ++v35;
              v34 = _mm_min_ps(v34, v39[*v40].m_quad);
              v38 = _mm_max_ps(v38, v39[*v40].m_quad);
            }
            while ( v36 != v37 );
            if ( v35 )
            {
              if ( !v27->m_firstFree )
                hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
                  v27,
                  &resulta,
                  256);
              m_firstFree = v27->m_firstFree;
              v42 = v27->m_nodes.m_data;
              v43 = m_firstFree;
              v27->m_firstFree = v27->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
              v42[v43].m_children[0] = 0;
              v42[v43].m_children[1] = v30;
              v42[v43].m_aabb.m_min.m_quad = v34;
              v42[v43].m_aabb.m_max.m_quad = v38;
              v44 = v27->m_nodes.m_data;
              m_root = v27->m_root;
              m_quad = v27->m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad;
              v47 = v27->m_nodes.m_data[m_firstFree].m_aabb.m_max.m_quad;
              if ( (_DWORD)m_root )
              {
                if ( !v27->m_firstFree )
                  hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
                    v27,
                    &v73,
                    256);
                v48 = v27->m_firstFree;
                p_m_quad = &v27->m_nodes.m_data[m_root].m_aabb.m_min.m_quad;
                v50 = (__int64)&v27->m_nodes.m_data[v48];
                v27->m_firstFree = v27->m_nodes.m_data[(int)v48].m_aabb.m_min.m_quad.m128_u32[0];
                v51 = p_m_quad[2].m128_u32[1];
                if ( (_DWORD)v51 )
                {
                  v52 = _mm_add_ps(v47, m_quad);
                  v53 = _mm_sub_ps(v47, m_quad);
                  do
                  {
                    v55 = _mm_min_ps(*p_m_quad, m_quad);
                    v56 = _mm_max_ps(p_m_quad[1], v47);
                    v57 = p_m_quad[2].m128_u32[2];
                    v70[0] = (__int64)&v27->m_nodes.m_data[v51];
                    v54 = v70[0];
                    v58 = &v27->m_nodes.m_data[v57].m_aabb.m_min.m_quad;
                    v70[1] = (__int64)v58;
                    *p_m_quad = v55;
                    p_m_quad[1] = v56;
                    v59 = *(__m128 *)(v54 + 16);
                    v60 = _mm_add_ps(_mm_sub_ps(v59, *(__m128 *)v54), v53);
                    v61 = _mm_sub_ps(_mm_add_ps(v59, *(__m128 *)v54), v52);
                    v62 = _mm_mul_ps(v61, v61);
                    v63 = _mm_add_ps(_mm_sub_ps(v58[1], *v58), v53);
                    v64 = _mm_sub_ps(_mm_add_ps(v58[1], *v58), v52);
                    v65 = _mm_mul_ps(v64, v64);
                    p_m_quad = (__m128 *)v70[(float)((float)((float)(_mm_shuffle_ps(v62, v62, 85).m128_f32[0]
                                                                   + _mm_shuffle_ps(v62, v62, 0).m128_f32[0])
                                                           + _mm_shuffle_ps(v62, v62, 170).m128_f32[0])
                                                   * (float)((float)(_mm_shuffle_ps(v60, v60, 85).m128_f32[0]
                                                                   + _mm_shuffle_ps(v60, v60, 0).m128_f32[0])
                                                           + _mm_shuffle_ps(v60, v60, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0]) + _mm_shuffle_ps(v65, v65, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0] + _mm_shuffle_ps(v63, v63, 0).m128_f32[0]) + _mm_shuffle_ps(v63, v63, 170).m128_f32[0]))];
                    v51 = p_m_quad[2].m128_u32[1];
                  }
                  while ( (_DWORD)v51 );
                }
                v66 = (signed __int64)(v50 - (unsigned __int64)v27->m_nodes.m_data) / 48;
                v67 = p_m_quad[2].m128_i32[0];
                if ( v67 )
                  v27->m_nodes.m_data[v67].m_children[v27->m_nodes.m_data[v67].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v27->m_nodes.m_data) / 48)] = v66;
                else
                  v27->m_root = v66;
                *(_DWORD *)(v50 + 32) = p_m_quad[2].m128_i32[0];
                v68 = (char *)p_m_quad - (char *)v27->m_nodes.m_data;
                *(_DWORD *)(v50 + 40) = m_firstFree;
                *(_DWORD *)(v50 + 36) = v68 / 48;
                p_m_quad[2].m128_i32[0] = v66;
                v27->m_nodes.m_data[m_firstFree].m_parent = v66;
                v69 = _mm_max_ps(p_m_quad[1], v47);
                *(__m128 *)v50 = _mm_min_ps(*p_m_quad, m_quad);
                *(__m128 *)(v50 + 16) = v69;
              }
              else
              {
                v27->m_root = m_firstFree;
                v44[m_firstFree].m_parent = 0;
              }
              ++v27->m_numLeaves;
            }
          }
          ++v29;
          ++v30;
        }
        while ( v29 < v31 );
        v4 = v72;
      }
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>>::optimizeIncremental(
        v27,
        v27->m_numLeaves,
        2);
    }
    else
    {
      this->m_tree = 0i64;
    }
    v4->m_enum = HK_SUCCESS;
    return v4;
  }
  v4->m_enum = HK_FAILURE;
  return v4;
}<256,hkcdDynamicTree::AnisotropicMetric,hkcdDyna

// File Line: 225
// RVA: 0xB7C130
hkResult *__fastcall hkaiEdgeGeometryRaycaster::initNoTree(
        hkaiEdgeGeometryRaycaster *this,
        hkResult *result,
        hkGeometry *geom)
{
  hkGeometry *m_pntr; // rcx
  __int64 m_size; // r13
  int v8; // r14d
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  hkVector4f *m_data; // rax
  __int64 v13; // r8
  __int64 v14; // r9
  hkGeometry::Triangle *v15; // rcx
  hkVector4f *v16; // rdx
  __m128 m_quad; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  hkResult resulta; // [rsp+90h] [rbp+8h] BYREF

  if ( geom )
    hkReferencedObject::addReference(geom);
  m_pntr = this->m_geometry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_geometry.m_pntr = geom;
  m_size = geom->m_triangles.m_size;
  if ( (_DWORD)m_size )
  {
    v8 = m_size + 1;
    v9 = this->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= (int)m_size + 1 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      v10 = 2 * v9;
      v11 = m_size + 1;
      if ( v8 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_facePlanes, v11, 16);
      if ( resulta.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
    }
    m_data = this->m_facePlanes.m_data;
    this->m_facePlanes.m_size = v8;
    v13 = m_size;
    *m_data = 0i64;
    if ( (int)m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = geom->m_triangles.m_data;
        v16 = geom->m_vertices.m_data;
        m_quad = v16[v15[v14++].m_a].m_quad;
        v18 = _mm_sub_ps(v16[v15[v14 - 1].m_b].m_quad, m_quad);
        v19 = _mm_sub_ps(v16[v15[v14 - 1].m_c].m_quad, m_quad);
        v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19));
        v21 = _mm_shuffle_ps(v20, v20, 201);
        v22 = _mm_mul_ps(v21, v21);
        v23 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170));
        v24 = _mm_rsqrt_ps(v23);
        v25 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v23, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                    _mm_mul_ps(*(__m128 *)_xmm, v24))),
                v21);
        v26 = _mm_mul_ps(m_quad, v25);
        this->m_facePlanes.m_data[v14].m_quad = _mm_shuffle_ps(
                                                  v25,
                                                  _mm_unpackhi_ps(
                                                    v25,
                                                    _mm_sub_ps(
                                                      (__m128)0i64,
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v26, v26, 85),
                                                          _mm_shuffle_ps(v26, v26, 0)),
                                                        _mm_shuffle_ps(v26, v26, 170)))),
                                                  196);
        --v13;
      }
      while ( v13 );
    }
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 250
// RVA: 0xB7B8B0
hkResult *__fastcall hkaiEdgeGeometryRaycaster::init(
        hkaiEdgeGeometryRaycaster *this,
        hkResult *result,
        hkGeometry *geom,
        hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers,
        hkBitField *cuttingTriangles)
{
  hkResult *v7; // rsi
  hkGeometry *m_pntr; // rcx
  _QWORD **Value; // rax
  __int64 v11; // rax
  hkGeometry *v12; // rbx
  hkGeometry *v13; // rcx
  int v14; // r14d
  __int64 v15; // rbx
  hkaiVolume *v16; // rcx
  hkGeometry *v17; // rcx
  int m_capacityAndFlags; // r8d
  int v19; // r15d
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_facePlanes; // r12
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // r9d
  _QWORD **v25; // rax
  hkcdDynamicTree::DefaultTree48Storage *v26; // rax
  __int64 *v27; // rax
  __int64 *v28; // rbx
  int v29; // r14d
  __int64 v30; // r15
  hkGeometry *v31; // r8
  int m_size; // ecx
  hkGeometry::Triangle *v33; // rcx
  hkVector4f *v34; // rdx
  __m128 m_quad; // xmm6
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  int v38; // eax
  hkGeometry *v39; // rcx
  hkGeometry::Triangle *m_data; // rdx
  hkVector4f *v41; // r8
  __m128 v42; // xmm7
  __m128 v43; // xmm8
  __m128 v44; // xmm0
  __m128 v45; // xmm7
  __m128 v46; // xmm8
  __m128 v47; // xmm1
  __m128 v48; // xmm5
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __int64 m_enum; // r8
  __int64 v56; // rdx
  __int64 v57; // rsi
  __int64 v58; // rax
  __int64 v59; // r12
  __m128 v60; // xmm7
  __m128 v61; // xmm8
  __int64 v62; // rdx
  __m128 *v63; // r9
  __int64 v64; // r11
  __int64 v65; // rax
  __m128 v66; // xmm9
  __m128 v67; // xmm10
  __int64 v68; // r8
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __int64 v71; // rdx
  __m128 *v72; // rdx
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm6
  __m128 v76; // xmm3
  __m128 v77; // xmm3
  __m128 v78; // xmm5
  __m128 v79; // xmm5
  __int64 v80; // r10
  unsigned int v81; // eax
  __int64 v82; // rcx
  __m128 v83; // xmm1
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  hkGeometry geometry; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v87; // [rsp+68h] [rbp-98h]
  hkResult v88; // [rsp+70h] [rbp-90h] BYREF
  __int64 v89[3]; // [rsp+78h] [rbp-88h]
  hkMatrix4f transform; // [rsp+90h] [rbp-70h] BYREF
  hkResult v91; // [rsp+170h] [rbp+70h] BYREF
  hkResult *v92; // [rsp+178h] [rbp+78h]
  hkResult v93; // [rsp+180h] [rbp+80h] BYREF

  v92 = result;
  v7 = result;
  if ( geom )
    hkReferencedObject::addReference(geom);
  m_pntr = this->m_geometry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_geometry.m_pntr = geom;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v12 = (hkGeometry *)v11;
  if ( v11 )
  {
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkGeometry::`vftable;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_DWORD *)(v11 + 24) = 0;
    *(_DWORD *)(v11 + 28) = 0x80000000;
    *(_QWORD *)(v11 + 32) = 0i64;
    *(_DWORD *)(v11 + 40) = 0;
    *(_DWORD *)(v11 + 44) = 0x80000000;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = this->m_carverGeometry.m_pntr;
  if ( v13 && v13 != v12 )
    hkReferencedObject::removeReference(v13);
  this->m_carverGeometry.m_pntr = v12;
  if ( !v12 )
  {
    v7->m_enum = HK_FAILURE;
    return v7;
  }
  v14 = 0;
  if ( carvers->m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = carvers->m_data[v15].m_pntr;
      if ( v16 )
      {
        geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
        *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
        geometry.m_vertices.m_data = 0i64;
        geometry.m_vertices.m_size = 0;
        geometry.m_vertices.m_capacityAndFlags = 0x80000000;
        geometry.m_triangles.m_data = 0i64;
        geometry.m_triangles.m_size = 0;
        geometry.m_triangles.m_capacityAndFlags = 0x80000000;
        ((void (__fastcall *)(hkaiVolume *, hkResult *, hkGeometry *))v16->vfptr[2].__first_virtual_table_function__)(
          v16,
          &v93,
          &geometry);
        if ( v93.m_enum )
        {
          m_capacityAndFlags = geometry.m_triangles.m_capacityAndFlags;
          geometry.m_triangles.m_size = 0;
LABEL_24:
          v7->m_enum = HK_FAILURE;
          if ( m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              geometry.m_triangles.m_data,
              16 * m_capacityAndFlags);
          geometry.m_triangles.m_data = 0i64;
          geometry.m_triangles.m_capacityAndFlags = 0x80000000;
          geometry.m_vertices.m_size = 0;
          if ( geometry.m_vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              geometry.m_vertices.m_data,
              16 * geometry.m_vertices.m_capacityAndFlags);
          return v7;
        }
        v17 = this->m_carverGeometry.m_pntr;
        transform.m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)::transform.m_quad, 4), 4);
        transform.m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)direction.m_quad, 4), 4);
        transform.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)stru_141A71280.m_quad, 4), 4);
        transform.m_col3.m_quad = _mm_shuffle_ps(qi.m_vec.m_quad, _mm_unpackhi_ps(qi.m_vec.m_quad, query.m_quad), 196);
        hkGeometry::appendGeometry(v17, &resulta, &geometry, &transform);
        m_capacityAndFlags = geometry.m_triangles.m_capacityAndFlags;
        geometry.m_triangles.m_size = 0;
        if ( resulta.m_enum )
          goto LABEL_24;
        if ( geometry.m_triangles.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            geometry.m_triangles.m_data,
            16 * geometry.m_triangles.m_capacityAndFlags);
        geometry.m_triangles.m_data = 0i64;
        geometry.m_triangles.m_capacityAndFlags = 0x80000000;
        geometry.m_vertices.m_size = 0;
        if ( geometry.m_vertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            geometry.m_vertices.m_data,
            16 * geometry.m_vertices.m_capacityAndFlags);
      }
      ++v14;
      ++v15;
    }
    while ( v14 < carvers->m_size );
  }
  v19 = geom->m_triangles.m_size + this->m_carverGeometry.m_pntr->m_triangles.m_size;
  if ( !v19 )
    goto LABEL_65;
  p_m_facePlanes = &this->m_facePlanes;
  v21 = v19 + 1;
  v22 = this->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 >= v19 + 1 )
  {
    v91.m_enum = HK_SUCCESS;
  }
  else
  {
    v23 = 2 * v22;
    v24 = v19 + 1;
    if ( v21 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(&v91, &hkContainerHeapAllocator::s_alloc, &this->m_facePlanes, v24, 16);
    if ( v91.m_enum )
      goto LABEL_34;
  }
  this->m_facePlanes.m_size = v21;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(
                                                   v25[11],
                                                   40i64);
  if ( v26 )
  {
    EdgeGeomRaycastAabbTree::EdgeGeomRaycastAabbTree(v26);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  this->m_tree = v28;
  if ( !v28
    || (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
          &v93,
          2 * v19),
        (v91.m_enum = v93.m_enum) != HK_SUCCESS) )
  {
LABEL_34:
    v7->m_enum = HK_FAILURE;
    return v7;
  }
  v29 = 0;
  *p_m_facePlanes->m_data = 0i64;
  v87 = v19;
  if ( v19 <= 0 )
    goto LABEL_64;
  v30 = 0i64;
  do
  {
    v31 = this->m_geometry.m_pntr;
    m_size = v31->m_triangles.m_size;
    if ( v29 >= m_size )
    {
      v38 = v29 - m_size;
      v39 = this->m_carverGeometry.m_pntr;
      m_data = v39->m_triangles.m_data;
      v41 = v39->m_vertices.m_data;
      m_quad = v41[m_data[v38].m_a].m_quad;
      v36 = v41[m_data[v38].m_b].m_quad;
      v37 = v41[m_data[v38].m_c].m_quad;
    }
    else
    {
      if ( ((cuttingTriangles->m_storage.m_words.m_data[(__int64)v29 >> 5] >> (v29 & 0x1F)) & 1) == 0 )
      {
        p_m_facePlanes->m_data[v30] = 0i64;
        goto LABEL_62;
      }
      v33 = v31->m_triangles.m_data;
      v34 = v31->m_vertices.m_data;
      m_quad = v34[v33[v30].m_a].m_quad;
      v36 = v34[v33[v30].m_b].m_quad;
      v37 = v34[v33[v30].m_c].m_quad;
    }
    v42 = _mm_min_ps(m_quad, v36);
    v43 = _mm_max_ps(m_quad, v36);
    v44 = _mm_sub_ps(v36, m_quad);
    v45 = _mm_min_ps(v42, v37);
    v46 = _mm_max_ps(v43, v37);
    v47 = _mm_sub_ps(v37, m_quad);
    v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v47));
    v49 = _mm_shuffle_ps(v48, v48, 201);
    v50 = _mm_mul_ps(v49, v49);
    v51 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
            _mm_shuffle_ps(v50, v50, 170));
    v52 = _mm_rsqrt_ps(v51);
    v53 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v51, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                _mm_mul_ps(*(__m128 *)_xmm, v52))),
            v49);
    v54 = _mm_mul_ps(v53, m_quad);
    p_m_facePlanes->m_data[v30 + 1].m_quad = _mm_shuffle_ps(
                                               v53,
                                               _mm_unpackhi_ps(
                                                 v53,
                                                 _mm_sub_ps(
                                                   (__m128)0i64,
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v54, v54, 85),
                                                       _mm_shuffle_ps(v54, v54, 0)),
                                                     _mm_shuffle_ps(v54, v54, 170)))),
                                               196);
    if ( !*((_DWORD *)v28 + 4) )
      hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
        (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
        &resulta,
        256);
    v56 = *v28;
    v93.m_enum = *((_DWORD *)v28 + 4);
    m_enum = (unsigned int)v93.m_enum;
    v57 = 6i64 * (unsigned int)v93.m_enum;
    *((_DWORD *)v28 + 4) = *(_DWORD *)(v56 + 48i64 * (int)v93.m_enum);
    *(_DWORD *)(v56 + 8 * v57 + 36) = 0;
    *(_DWORD *)(v56 + 8 * v57 + 40) = v29 + 1;
    *(__m128 *)(v56 + 8 * v57) = v45;
    *(__m128 *)(v56 + 8 * v57 + 16) = v46;
    v58 = *v28;
    v59 = *((unsigned int *)v28 + 8);
    v60 = *(__m128 *)(*v28 + 48 * m_enum);
    v61 = *(__m128 *)(*v28 + 48 * m_enum + 16);
    if ( (_DWORD)v59 )
    {
      if ( !*((_DWORD *)v28 + 4) )
        hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
          &v88,
          256);
      v62 = *((unsigned int *)v28 + 4);
      v63 = (__m128 *)(*v28 + 48 * v59);
      v64 = *v28 + 48 * v62;
      *((_DWORD *)v28 + 4) = *(_DWORD *)(*v28 + 48i64 * (int)v62);
      v65 = v63[2].m128_u32[1];
      if ( (_DWORD)v65 )
      {
        v66 = _mm_add_ps(v61, v60);
        v67 = _mm_sub_ps(v61, v60);
        do
        {
          v69 = _mm_min_ps(*v63, v60);
          v70 = _mm_max_ps(v63[1], v61);
          v71 = 48i64 * v63[2].m128_u32[2];
          v89[0] = *v28 + 48 * v65;
          v68 = v89[0];
          v72 = (__m128 *)(*v28 + v71);
          v89[1] = (__int64)v72;
          *v63 = v69;
          v63[1] = v70;
          v73 = *(__m128 *)(v68 + 16);
          v74 = _mm_add_ps(_mm_sub_ps(v73, *(__m128 *)v68), v67);
          v75 = _mm_add_ps(_mm_sub_ps(v72[1], *v72), v67);
          v76 = _mm_sub_ps(_mm_add_ps(v73, *(__m128 *)v68), v66);
          v77 = _mm_mul_ps(v76, v76);
          v78 = _mm_sub_ps(_mm_add_ps(v72[1], *v72), v66);
          v79 = _mm_mul_ps(v78, v78);
          v63 = (__m128 *)v89[(float)((float)((float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0]
                                                    + _mm_shuffle_ps(v74, v74, 0).m128_f32[0])
                                            + _mm_shuffle_ps(v74, v74, 170).m128_f32[0])
                                    * (float)((float)(_mm_shuffle_ps(v77, v77, 85).m128_f32[0]
                                                    + _mm_shuffle_ps(v77, v77, 0).m128_f32[0])
                                            + _mm_shuffle_ps(v77, v77, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v79, v79, 85).m128_f32[0] + _mm_shuffle_ps(v79, v79, 0).m128_f32[0]) + _mm_shuffle_ps(v79, v79, 170).m128_f32[0])
                                                                                                  * (float)((float)(_mm_shuffle_ps(v75, v75, 85).m128_f32[0] + _mm_shuffle_ps(v75, v75, 0).m128_f32[0]) + _mm_shuffle_ps(v75, v75, 170).m128_f32[0]))];
          v65 = v63[2].m128_u32[1];
        }
        while ( (_DWORD)v65 );
      }
      v80 = (v64 - *v28) / 48;
      v81 = v63[2].m128_u32[0];
      if ( v81 )
        *(_DWORD *)(*v28
                  + 4
                  * ((*(_DWORD *)(*v28 + 48i64 * v81 + 40) == (unsigned int)(((__int64)v63 - *v28) / 48)) + 12i64 * v81)
                  + 36) = v80;
      else
        *((_DWORD *)v28 + 8) = v80;
      *(_DWORD *)(v64 + 32) = v63[2].m128_i32[0];
      v82 = (__int64)v63 - *v28;
      *(hkResult *)(v64 + 40) = v93;
      *(_DWORD *)(v64 + 36) = v82 / 48;
      v63[2].m128_i32[0] = v80;
      *(_DWORD *)(*v28 + 8 * v57 + 32) = v80;
      v83 = _mm_max_ps(v63[1], v61);
      *(__m128 *)v64 = _mm_min_ps(*v63, v60);
      *(__m128 *)(v64 + 16) = v83;
    }
    else
    {
      *((_DWORD *)v28 + 8) = m_enum;
      *(_DWORD *)(v58 + 8 * v57 + 32) = 0;
    }
    ++*((_DWORD *)v28 + 6);
    p_m_facePlanes = &this->m_facePlanes;
LABEL_62:
    ++v29;
    ++v30;
    --v87;
  }
  while ( v87 );
  v7 = v92;
LABEL_64:
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>>::optimizeIncremental(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *)v28,
    *((_DWORD *)v28 + 6),
    2);
LABEL_65:
  v7->m_enum = HK_SUCCESS;
  return v7;
}

// File Line: 344
// RVA: 0xB7D960
__int64 __fastcall hkaiEdgeGeometryRaycaster::getNumVertsForFace(hkaiEdgeGeometryRaycaster *this, int faceId)
{
  if ( this->m_geometry.m_pntr )
    return 3i64;
  else
    return (unsigned int)(this->m_faceEdges.m_faceStartEdges.m_data[faceId + 1]
                        - this->m_faceEdges.m_faceStartEdges.m_data[faceId]);
}

// File Line: 359
// RVA: 0xB7D990
void __fastcall hkaiEdgeGeometryRaycaster::getVertsForFace(
        hkaiEdgeGeometryRaycaster *this,
        int faceId,
        hkArrayBase<hkVector4f> *vertsOut)
{
  hkGeometry *m_pntr; // r8
  int v6; // eax
  int m_size; // ecx
  hkVector4f *m_data; // rcx
  hkGeometry::Triangle *v9; // rdx
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  __int64 m_c; // rax
  hkGeometry *v13; // rdx
  int v14; // eax
  hkGeometry::Triangle *v15; // r8
  hkVector4f v16; // xmm2
  hkaiEdgeGeometry::Edge *const **v17; // rax
  hkaiEdgeGeometry::Edge *const *v18; // rsi
  __int64 v19; // r10
  __int64 v20; // rdx
  __int64 v21; // rbp
  __int64 v22; // rdi
  __int64 v23; // rbx
  hkaiEdgeGeometry::Edge *v24; // rcx
  hkVector4f *v25; // rdx
  __int64 m_b; // r8

  if ( this->m_geometry.m_pntr )
  {
    vertsOut->m_size = 6;
    m_pntr = this->m_geometry.m_pntr;
    v6 = faceId - 1;
    m_size = m_pntr->m_triangles.m_size;
    if ( faceId - 1 >= m_size )
    {
      v13 = this->m_carverGeometry.m_pntr;
      v14 = v6 - m_size;
      m_data = v13->m_vertices.m_data;
      v15 = &v13->m_triangles.m_data[v14];
      v10.m_quad = (__m128)m_data[v15->m_a];
      v11.m_quad = (__m128)m_data[v15->m_b];
      m_c = v15->m_c;
    }
    else
    {
      m_data = m_pntr->m_vertices.m_data;
      v9 = &m_pntr->m_triangles.m_data[v6];
      v10.m_quad = (__m128)m_data[v9->m_a];
      v11.m_quad = (__m128)m_data[v9->m_b];
      m_c = v9->m_c;
    }
    v16.m_quad = (__m128)m_data[m_c];
    *vertsOut->m_data = (hkVector4f)v10.m_quad;
    vertsOut->m_data[1] = (hkVector4f)v11.m_quad;
    vertsOut->m_data[2] = (hkVector4f)v11.m_quad;
    vertsOut->m_data[3] = (hkVector4f)v16.m_quad;
    vertsOut->m_data[4] = (hkVector4f)v16.m_quad;
    vertsOut->m_data[5] = (hkVector4f)v10.m_quad;
  }
  else
  {
    v17 = this->m_faceEdges.m_faceStartEdges.m_data;
    v18 = v17[faceId];
    v19 = 0i64;
    v20 = v17[faceId + 1] - v18;
    v21 = (int)v20;
    vertsOut->m_size = 2 * v20;
    if ( (int)v20 > 0 )
    {
      v22 = 1i64;
      v23 = 0i64;
      do
      {
        v24 = v18[v19++];
        v25 = this->m_edgeGeometry.m_pntr->m_vertices.m_data;
        m_b = (int)v24->m_b;
        v22 += 2i64;
        v23 += 2i64;
        vertsOut->m_data[v23 - 2] = v25[v24->m_a];
        vertsOut->m_data[v22 - 2] = v25[m_b];
      }
      while ( v19 < v21 );
    }
  }
}

// File Line: 416
// RVA: 0xB7DAF0
bool __fastcall hkaiEdgeGeometryRaycaster::shouldSkipFace(hkaiEdgeGeometryRaycaster *this, int faceId)
{
  __int64 v2; // rdi
  hkaiEdgeGeometry *m_pntr; // rdx
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> result; // [rsp+30h] [rbp+8h] BYREF

  v2 = faceId;
  hkaiEdgeGeometryRaycaster::getFlagsForFace(this, &result, faceId);
  if ( (this->m_faceFlagMask.m_storage & (unsigned __int8)result.m_storage) == 0 )
    return 1;
  m_pntr = this->m_edgeGeometry.m_pntr;
  if ( m_pntr )
    LODWORD(v2) = m_pntr->m_faces.m_data[v2].m_faceIndex;
  return (_DWORD)v2 == this->m_ignoreFaceIndex;
}

// File Line: 445
// RVA: 0xB7D910
hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *__fastcall hkaiEdgeGeometryRaycaster::getFlagsForFace(
        hkaiEdgeGeometryRaycaster *this,
        hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *result,
        int faceId)
{
  hkaiEdgeGeometry *m_pntr; // r9
  bool v4; // cc
  char v5; // r8
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *v6; // rax

  m_pntr = this->m_edgeGeometry.m_pntr;
  if ( m_pntr )
  {
    v6 = result;
    result->m_storage = (char)m_pntr->m_faces.m_data[faceId].m_flags;
  }
  else
  {
    v4 = faceId - 1 < this->m_geometry.m_pntr->m_triangles.m_size;
    v5 = 4;
    v6 = result;
    if ( v4 )
      v5 = 1;
    result->m_storage = v5;
  }
  return v6;
}

// File Line: 469
// RVA: 0xB7DC40
float __fastcall calculateEpsilon(hkArrayBase<hkVector4f> *faceVertices, int numEdges)
{
  __m128 v2; // xmm2
  __int64 v3; // r8
  __m128 v4; // xmm1
  hkVector4f *m_data; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v2 = (__m128)xmmword_141A712A0;
  v3 = numEdges;
  v4 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( numEdges > 0 )
  {
    m_data = faceVertices->m_data;
    do
    {
      v2 = _mm_min_ps(v2, m_data->m_quad);
      v4 = _mm_max_ps(v4, m_data->m_quad);
      ++m_data;
      --v3;
    }
    while ( v3 );
  }
  v6 = _mm_mul_ps(_mm_sub_ps(v4, v2), (__m128)xmmword_141A711B0);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  return _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0).m128_f32[0]
       * _mm_andnot_ps(
           _mm_cmple_ps(v8, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
             v8)).m128_f32[0];
}

// File Line: 488
// RVA: 0xB7DD00
__int64 __fastcall pointInPolygon(
        hkVector4f *samplePoint,
        hkVector4f *extrusion,
        hkArrayBase<hkVector4f> *faceVertices,
        int numEdges,
        hkVector4f *faceNorm,
        int maxNumIters)
{
  int v6; // r11d
  __int64 v9; // rsi
  int v10; // ebx
  __m128 m_quad; // xmm14
  __m128 v12; // xmm3
  float v13; // xmm8_4
  int v14; // r8d
  __int64 v15; // r14
  __int64 v16; // r15
  int v17; // ecx
  __int64 v18; // rdx
  hkVector4f *m_data; // r8
  __m128 v20; // xmm11
  __m128 v21; // xmm9
  __m128 v22; // xmm10
  hkVector4f *i; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  float v31; // xmm3_4
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  float v34; // xmm5_4
  __m128 v35; // xmm1
  float v36; // xmm4_4
  float v37; // xmm3_4
  bool v38; // cf
  float v39; // xmm2_4
  float v41; // xmm0_4
  int v42; // r10d
  unsigned int maxNumItersa; // [rsp+F8h] [rbp+30h]

  v6 = maxNumIters;
  v9 = numEdges;
  v10 = 0;
  m_quad = samplePoint->m_quad;
  v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)faceNorm), 1u), 1u);
  v13 = 0.0;
  v14 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v12, v12, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v12, v12, 85),
                                                                       _mm_shuffle_ps(v12, v12, 0))),
                                                                   v12),
                                                                 (__m128)xmmword_141A4D7C0))];
  v15 = (v14 + 1) % 3;
  v16 = (v14 + 2) % 3;
  while ( v10 < v6 )
  {
    v17 = 0;
    v18 = 0i64;
    if ( (int)v9 <= 0 )
      return v17 & 1;
    m_data = faceVertices->m_data;
    v20 = extrusion->m_quad;
    v21 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v15];
    v22 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v16];
    for ( i = faceVertices->m_data + 1; ; i += 2 )
    {
      v24 = _mm_sub_ps(_mm_add_ps(v20, m_data->m_quad), m_quad);
      v25 = _mm_sub_ps(_mm_add_ps(v20, i->m_quad), m_quad);
      v26 = _mm_and_ps(v21, v24);
      v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_and_ps(v22, v24);
      v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 78), v28);
      v30 = _mm_and_ps(v21, v25);
      v31 = COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 177).m128_u32[0] | v29.m128_i32[0]) + v13;
      v32 = _mm_or_ps(_mm_shuffle_ps(v30, v30, 78), v30);
      v33 = _mm_and_ps(v22, v25);
      LODWORD(v34) = _mm_shuffle_ps(v32, v32, 177).m128_u32[0] | v32.m128_i32[0];
      v35 = _mm_or_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v36 = COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 177).m128_u32[0] | v35.m128_i32[0]) + v13;
      if ( (float)(v36 * v31) >= 0.0 )
        break;
      v37 = v31 - v36;
      v38 = v37 < 0.0;
      v39 = COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 177).m128_u32[0] | v27.m128_i32[0]) - v34;
      if ( v37 <= 0.0 )
        goto LABEL_9;
      if ( (float)(v39 * v36) <= (float)(v37 * v34) )
      {
        v38 = v37 < 0.0;
LABEL_9:
        if ( v38 && (float)(v39 * v36) < (float)(v37 * v34) )
          ++v17;
        goto LABEL_14;
      }
      ++v17;
LABEL_14:
      ++v18;
      m_data += 2;
      if ( v18 >= v9 )
        return v17 & 1;
    }
    if ( (float)(v36 * v31) != 0.0 || v6 == 1 )
      goto LABEL_14;
    v41 = calculateEpsilon(faceVertices, v9);
    ++v10;
    *(float *)&maxNumItersa = (float)((float)(v41 - COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]))
                                    * (float)((float)(1664525 * v42 + 1013904223) * 2.3283064e-10))
                            + COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]);
    LODWORD(v13) = _mm_shuffle_ps((__m128)maxNumItersa, (__m128)maxNumItersa, 0).m128_u32[0];
  }
  return 0i64;
}

// File Line: 575
// RVA: 0xB7CC70
unsigned int __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstFace(
        hkaiEdgeGeometryRaycaster *this,
        int faceId,
        hkVector4f *rayStart,
        hkVector4f *rayEnd,
        hkSimdFloat32 *hitFractionInOut)
{
  return hkaiEdgeGeometryRaycaster::raycastAgainstFace(
           this,
           faceId,
           rayStart,
           rayEnd,
           &this->m_facePlanes.m_data[faceId],
           &aabbOut,
           hitFractionInOut);
}

// File Line: 580
// RVA: 0xB7CCB0
__int64 __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstFace(
        hkaiEdgeGeometryRaycaster *this,
        unsigned int faceId,
        hkVector4f *rayStart,
        hkVector4f *rayEnd,
        hkVector4f *facePlane,
        hkVector4f *extrusion,
        hkSimdFloat32 *hitFractionInOut)
{
  __m128 m_quad; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  int NumVertsForFace; // eax
  unsigned int v25; // edi
  int v26; // ebx
  int v27; // r13d
  hkLifoAllocator *Value; // rcx
  hkVector4f *m_cur; // rax
  int v30; // edx
  char *v31; // r8
  hkaiEdgeGeometryHitFilter *m_pntr; // rcx
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // r8d
  __m128 v36; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f samplePoint; // [rsp+40h] [rbp-58h] BYREF
  hkArrayBase<hkVector4f> vertsOut; // [rsp+50h] [rbp-48h] BYREF
  void *p; // [rsp+60h] [rbp-38h]
  int v40; // [rsp+68h] [rbp-30h]

  if ( hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
    return 0i64;
  m_quad = rayStart->m_quad;
  v13 = _mm_mul_ps(facePlane->m_quad, rayStart->m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, facePlane->m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(rayEnd->m_quad, facePlane->m_quad);
  v17 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15);
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, facePlane->m_quad), 196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  if ( (float)(v20.m128_f32[0] * v17.m128_f32[0]) >= 0.0 )
    return 0i64;
  v21 = _mm_sub_ps(rayEnd->m_quad, m_quad);
  v22 = _mm_sub_ps(v17, v20);
  v23 = _mm_rcp_ps(v22);
  v36 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)), v23), v17);
  samplePoint.m_quad = _mm_add_ps(_mm_mul_ps(v21, v36), m_quad);
  NumVertsForFace = hkaiEdgeGeometryRaycaster::getNumVertsForFace(this, faceId);
  v25 = 0;
  v26 = 2 * NumVertsForFace;
  v27 = NumVertsForFace;
  vertsOut.m_size = 0;
  v40 = 2 * NumVertsForFace;
  if ( 2 * NumVertsForFace )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v30 = (16 * v26 + 127) & 0xFFFFFF80;
    v31 = (char *)m_cur + v30;
    if ( v30 > Value->m_slabSize || v31 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v30);
    else
      Value->m_cur = v31;
  }
  else
  {
    m_cur = 0i64;
  }
  vertsOut.m_data = m_cur;
  p = m_cur;
  vertsOut.m_capacityAndFlags = v26 | 0x80000000;
  hkaiEdgeGeometryRaycaster::getVertsForFace(this, faceId, &vertsOut);
  if ( pointInPolygon(&samplePoint, extrusion, &vertsOut, v27, facePlane, 10) )
  {
    m_pntr = this->m_hitFilter.m_pntr;
    if ( !m_pntr
      || !((unsigned __int8 (__fastcall *)(hkaiEdgeGeometryHitFilter *, _QWORD, hkVector4f *, hkVector4f *, __m128 *, hkVector4f *))m_pntr->vfptr[1].__first_virtual_table_function__)(
            m_pntr,
            faceId,
            rayStart,
            rayEnd,
            &v36,
            facePlane) )
    {
      v25 = 1;
      hitFractionInOut->m_real = _mm_min_ps(v36, hitFractionInOut->m_real);
    }
  }
  v33 = (16 * v40 + 127) & 0xFFFFFF80;
  v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (v33 + 15) & 0xFFFFFFF0;
  if ( v33 > v34->m_slabSize || (char *)p + v35 != v34->m_cur || v34->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v34, p, v35);
  else
    v34->m_cur = p;
  if ( vertsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertsOut.m_data,
      16 * vertsOut.m_capacityAndFlags);
  return v25;
}

// File Line: 649
// RVA: 0xB7CF40
__int64 __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(
        hkaiEdgeGeometryRaycaster *this,
        int faceId,
        hkVector4f *rayStart,
        hkVector4f *rayEnd,
        hkcdRay *ray,
        hkVector4f *extrusion,
        bool stopOnFirstHit,
        hkSimdFloat32 *hitFractionInOut)
{
  __int64 v8; // r15
  unsigned int v11; // edi
  int v12; // ebp
  int NumVertsForFace; // eax
  __int64 v14; // rsi
  int v15; // ebx
  hkLifoAllocator *Value; // rcx
  hkVector4f *m_cur; // rax
  int v18; // edx
  char *v19; // r8
  __int64 v20; // r8
  hkVector4f *m_data; // rcx
  __m128 v22; // xmm11
  __m128 v23; // xmm12
  hkVector4f v24; // xmm5
  __m128 v25; // xmm10
  __m128 v26; // xmm9
  __m128 v27; // xmm13
  __m128 v28; // xmm14
  __m128 v29; // xmm8
  __m128 v30; // xmm8
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm7
  __m128 v37; // xmm6
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm5
  __m128 v44; // xmm9
  __m128 v45; // xmm6
  __m128 v46; // xmm6
  __m128 v47; // xmm9
  __m128 v48; // xmm0
  __m128 v49; // xmm3
  int v50; // edx
  signed int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // r8d
  __m128 v54; // xmm9
  __m128 v55; // xmm10
  __m128 v56; // xmm12
  hkVector4f v57; // xmm5
  __m128 v58; // xmm11
  __m128 v59; // xmm13
  __m128 v60; // xmm8
  __m128 v61; // xmm8
  __m128 v62; // xmm1
  __m128 v63; // xmm4
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm1
  __m128 v67; // xmm7
  __m128 v68; // xmm6
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm4
  __m128 v72; // xmm5
  __m128 v73; // xmm1
  __m128 v74; // xmm5
  __m128 v75; // xmm9
  __m128 v76; // xmm6
  __m128 v77; // xmm6
  __m128 v78; // xmm9
  __m128 v79; // xmm0
  __m128 v80; // xmm3
  int v81; // eax
  signed int v82; // ebx
  hkLifoAllocator *v83; // rax
  int v84; // r8d
  int v85; // edx
  __m128 m_quad; // xmm3
  __m128 v87; // xmm1
  hkArrayBase<hkVector4f> vertsOut; // [rsp+40h] [rbp-E8h] BYREF
  void *p; // [rsp+50h] [rbp-D8h]
  int v90; // [rsp+58h] [rbp-D0h]

  v8 = faceId;
  if ( hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
    return 0i64;
  v11 = 0;
  v12 = 0;
  NumVertsForFace = hkaiEdgeGeometryRaycaster::getNumVertsForFace(this, v8);
  vertsOut.m_size = 0;
  v14 = NumVertsForFace;
  v15 = 2 * NumVertsForFace;
  v90 = 2 * NumVertsForFace;
  if ( 2 * NumVertsForFace )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v18 = (16 * v15 + 127) & 0xFFFFFF80;
    v19 = (char *)m_cur + v18;
    if ( v18 > Value->m_slabSize || v19 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v18);
    else
      Value->m_cur = v19;
  }
  else
  {
    m_cur = 0i64;
  }
  vertsOut.m_data = m_cur;
  p = m_cur;
  vertsOut.m_capacityAndFlags = v15 | 0x80000000;
  hkaiEdgeGeometryRaycaster::getVertsForFace(this, v8, &vertsOut);
  v20 = 0i64;
  if ( v14 > 0 )
  {
    m_data = vertsOut.m_data;
    do
    {
      v22 = _mm_add_ps(m_data[1].m_quad, extrusion->m_quad);
      v23 = _mm_sub_ps(ray->m_origin.m_quad, m_data->m_quad);
      v24.m_quad = (__m128)ray->m_direction;
      v25 = _mm_sub_ps(v22, m_data->m_quad);
      v26 = _mm_sub_ps(_mm_add_ps(m_data->m_quad, extrusion->m_quad), m_data->m_quad);
      v27 = _mm_shuffle_ps(v25, v25, 201);
      v28 = _mm_shuffle_ps(v26, v26, 201);
      v29 = _mm_sub_ps(_mm_mul_ps(v26, v27), _mm_mul_ps(v25, v28));
      v30 = _mm_shuffle_ps(v29, v29, 201);
      v31 = _mm_mul_ps(v30, v24.m_quad);
      v32 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170));
      if ( (float)(v32.m128_f32[0] * v32.m128_f32[0]) < 0.00000011920929 )
        goto LABEL_20;
      v33 = _mm_mul_ps(v30, v23);
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170));
      v35 = _mm_rcp_ps(v32);
      v36 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v32)), v35), _mm_sub_ps((__m128)0i64, v34));
      if ( !_mm_movemask_ps(_mm_mul_ps(v34, v32)) )
        goto LABEL_20;
      if ( v36.m128_f32[0] >= _mm_shuffle_ps(v24.m_quad, v24.m_quad, 255).m128_f32[0] )
        goto LABEL_20;
      v37 = _mm_add_ps(_mm_mul_ps(v36, v24.m_quad), v23);
      v38 = _mm_sub_ps(v25, v37);
      v39 = _mm_sub_ps(v26, v37);
      v40 = _mm_mul_ps(v30, v30);
      v41 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v39), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v38));
      v42 = _mm_shuffle_ps(v37, v37, 201);
      v43 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v30);
      v44 = _mm_sub_ps(_mm_mul_ps(v26, v42), _mm_mul_ps(v37, v28));
      v45 = _mm_sub_ps(_mm_mul_ps(v37, v27), _mm_mul_ps(v25, v42));
      v46 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v30);
      v47 = _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v30);
      v48 = _mm_unpacklo_ps(v43, v47);
      v49 = _mm_movelh_ps(v48, v46);
      if ( (_mm_movemask_ps(
              _mm_cmple_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                    _mm_shuffle_ps(v40, v40, 170)),
                  (__m128)_xmm_b951b717b951b717b951b717b951b717),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v43, v47), v46, 228),
                  _mm_add_ps(v49, _mm_shuffle_ps(_mm_movehl_ps(v49, v48), v46, 212))))) & 7) == 7 )
      {
        v50 = 15;
        hitFractionInOut->m_real = _mm_min_ps(v36, hitFractionInOut->m_real);
        if ( stopOnFirstHit )
          goto LABEL_16;
      }
      else
      {
LABEL_20:
        v50 = 0;
      }
      v54 = _mm_sub_ps(m_data[1].m_quad, v22);
      v55 = _mm_sub_ps(m_data->m_quad, v22);
      v56 = _mm_sub_ps(ray->m_origin.m_quad, v22);
      v57.m_quad = (__m128)ray->m_direction;
      v58 = _mm_shuffle_ps(v55, v55, 201);
      v59 = _mm_shuffle_ps(v54, v54, 201);
      v60 = _mm_sub_ps(_mm_mul_ps(v54, v58), _mm_mul_ps(v55, v59));
      v61 = _mm_shuffle_ps(v60, v60, 201);
      v62 = _mm_mul_ps(v61, v57.m_quad);
      v63 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
              _mm_shuffle_ps(v62, v62, 170));
      if ( (float)(v63.m128_f32[0] * v63.m128_f32[0]) < 0.00000011920929 )
        goto LABEL_27;
      v64 = _mm_mul_ps(v61, v56);
      v65 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
              _mm_shuffle_ps(v64, v64, 170));
      v66 = _mm_rcp_ps(v63);
      v67 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v63)), v66), _mm_sub_ps((__m128)0i64, v65));
      if ( !_mm_movemask_ps(_mm_mul_ps(v65, v63)) )
        goto LABEL_27;
      if ( v67.m128_f32[0] >= _mm_shuffle_ps(v57.m_quad, v57.m_quad, 255).m128_f32[0] )
        goto LABEL_27;
      v68 = _mm_add_ps(_mm_mul_ps(v67, v57.m_quad), v56);
      v69 = _mm_sub_ps(v55, v68);
      v70 = _mm_sub_ps(v54, v68);
      v71 = _mm_mul_ps(v61, v61);
      v72 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v70), _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v69));
      v73 = _mm_shuffle_ps(v68, v68, 201);
      v74 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), v61);
      v75 = _mm_sub_ps(_mm_mul_ps(v54, v73), _mm_mul_ps(v68, v59));
      v76 = _mm_sub_ps(_mm_mul_ps(v68, v58), _mm_mul_ps(v55, v73));
      v77 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v61);
      v78 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v61);
      v79 = _mm_unpacklo_ps(v74, v78);
      v80 = _mm_movelh_ps(v79, v77);
      if ( (_mm_movemask_ps(
              _mm_cmple_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                    _mm_shuffle_ps(v71, v71, 170)),
                  (__m128)_xmm_b951b717b951b717b951b717b951b717),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v74, v78), v77, 228),
                  _mm_add_ps(v80, _mm_shuffle_ps(_mm_movehl_ps(v80, v79), v77, 212))))) & 7) == 7 )
      {
        v81 = 15;
        hitFractionInOut->m_real = _mm_min_ps(v67, hitFractionInOut->m_real);
        if ( stopOnFirstHit )
        {
LABEL_16:
          v51 = (16 * v90 + 127) & 0xFFFFFF80;
          v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v53 = (v51 + 15) & 0xFFFFFFF0;
          if ( v51 > v52->m_slabSize || (char *)p + v53 != v52->m_cur || v52->m_firstNonLifoEnd == p )
            hkLifoAllocator::slowBlockFree(v52, p, v53);
          else
            v52->m_cur = p;
          if ( vertsOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              vertsOut.m_data,
              16 * vertsOut.m_capacityAndFlags);
          return 1i64;
        }
      }
      else
      {
LABEL_27:
        v81 = 0;
      }
      if ( v12 || v50 || (v12 = 0, v81) )
        v12 = 1;
      ++v20;
      m_data += 2;
    }
    while ( v20 < v14 );
  }
  v82 = (16 * v90 + 127) & 0xFFFFFF80;
  v83 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v84 = (v82 + 15) & 0xFFFFFFF0;
  if ( v82 > v83->m_slabSize || (char *)p + v84 != v83->m_cur || v83->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v83, p, v84);
  else
    v83->m_cur = p;
  if ( vertsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertsOut.m_data,
      16 * vertsOut.m_capacityAndFlags);
  if ( v12
    || (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                       this,
                       v8,
                       rayStart,
                       rayEnd,
                       &this->m_facePlanes.m_data[v8],
                       &aabbOut,
                       hitFractionInOut) )
  {
    v85 = 1;
    if ( stopOnFirstHit )
      return 1i64;
  }
  else
  {
    v85 = 0;
  }
  m_quad = this->m_facePlanes.m_data[v8].m_quad;
  v87 = _mm_mul_ps(extrusion->m_quad, m_quad);
  vertsOut = (hkArrayBase<hkVector4f>)_mm_shuffle_ps(
                                        m_quad,
                                        _mm_unpackhi_ps(
                                          m_quad,
                                          _mm_sub_ps(
                                            _mm_shuffle_ps(m_quad, m_quad, 255),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                                              _mm_shuffle_ps(v87, v87, 170)))),
                                        196);
  if ( v85
    || (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                       this,
                       v8,
                       rayStart,
                       rayEnd,
                       (hkVector4f *)&vertsOut,
                       extrusion,
                       hitFractionInOut) )
  {
    return 1;
  }
  return v11;
}

// File Line: 723
// RVA: 0xB7D6C0
void __fastcall hkaiEdgeGeometryRaycaster::raycastBundleAgainstFace(
        hkaiEdgeGeometryRaycaster *this,
        int faceId,
        hkVector4f *bundleStarts,
        hkVector4f *bundleEnds,
        hkcdRay *rays,
        hkVector4f *hitFractions,
        hkVector4fComparison *mask,
        hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut,
        unsigned int extruded,
        hkVector4f *extrusion)
{
  __int64 v10; // r15
  hkaiEdgeGeometry *m_pntr; // r10
  bool v15; // cl
  signed int v16; // edi
  __int64 v17; // rsi
  int v18; // eax
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i si128; // xmm0
  hkVector4f v23; // xmm0
  char m_storage; // [rsp+40h] [rbp-48h]
  bool i; // [rsp+40h] [rbp-48h]
  hkSimdFloat32 hitFractionInOut; // [rsp+50h] [rbp-38h] BYREF

  v10 = faceId;
  if ( !hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
  {
    m_pntr = this->m_edgeGeometry.m_pntr;
    if ( m_pntr )
      m_storage = m_pntr->m_faces.m_data[v10].m_flags.m_storage;
    else
      m_storage = 1;
    v15 = extruded && (m_storage & 6) == 0;
    v16 = 0;
    v17 = 0i64;
    for ( i = v15; ; v15 = i )
    {
      v18 = _mm_movemask_ps(mask->m_mask);
      if ( _bittest(&v18, v16) )
      {
        v19 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v17], hitFractions->m_quad);
        v20 = _mm_or_ps(_mm_shuffle_ps(v19, v19, 78), v19);
        hitFractionInOut.m_real = _mm_or_ps(_mm_shuffle_ps(v20, v20, 177), v20);
        if ( v15
           ? hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(
               this,
               v10,
               &bundleStarts[v16],
               &bundleEnds[v16],
               &rays[v16],
               extrusion,
               earlyOut != STOP_NEVER,
               &hitFractionInOut)
           : hkaiEdgeGeometryRaycaster::raycastAgainstFace(
               this,
               v10,
               &bundleStarts[v16],
               &bundleEnds[v16],
               &hitFractionInOut) )
        {
          if ( earlyOut == STOP_BUNDLE_ON_HIT )
          {
            *hitFractions = 0i64;
            return;
          }
          if ( earlyOut == STOP_INDIVIDUAL_ON_HIT )
          {
            if ( v16 == 1 )
            {
              hitFractions->m_quad = _mm_shuffle_ps(
                                       _mm_unpacklo_ps(hitFractions->m_quad, (__m128)0i64),
                                       hitFractions->m_quad,
                                       228);
            }
            else if ( v16 == 2 )
            {
              hitFractions->m_quad = _mm_shuffle_ps(
                                       hitFractions->m_quad,
                                       _mm_unpackhi_ps(hitFractions->m_quad, (__m128)0i64),
                                       180);
            }
            else
            {
              si128 = _mm_load_si128((const __m128i *)hitFractions);
              if ( v16 == 3 )
                v23.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(si128, 4), 4);
              else
                v23.m_quad = (__m128)_mm_slli_si128(_mm_srli_si128(si128, 4), 4);
              *hitFractions = (hkVector4f)v23.m_quad;
            }
          }
          else
          {
            hitFractions->m_quad = _mm_or_ps(
                                     _mm_andnot_ps(
                                       (__m128)`hkVector4f::getComponent::`2::indexToMask[v17],
                                       hitFractions->m_quad),
                                     _mm_and_ps(
                                       (__m128)`hkVector4f::getComponent::`2::indexToMask[v17],
                                       hitFractionInOut.m_real));
          }
        }
      }
      ++v16;
      ++v17;
      if ( v16 >= 4 )
        return;
    }
  }
}

// File Line: 897
// RVA: 0xB7C350
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRay(
        hkaiEdgeGeometryRaycaster *this,
        hkVector4f *start,
        hkVector4f *end)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *m_tree; // r9
  __m128 m_quad; // xmm5
  unsigned int v6; // ebx
  __m128i v7; // xmm5
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  hkaiEdgeGeometryRaycaster *v10; // [rsp+20h] [rbp-1D8h] BYREF
  __m128 v11; // [rsp+30h] [rbp-1C8h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+40h] [rbp-1B8h] BYREF
  int v13; // [rsp+1C0h] [rbp-38h]

  m_tree = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)this->m_tree;
  if ( !m_tree )
    return 0i64;
  m_quad = end->m_quad;
  v10 = this;
  v6 = 0;
  stackInstance.m_stack[16] = -1;
  v11 = m_quad;
  v13 = 0;
  v7 = (__m128i)_mm_sub_ps(m_quad, start->m_quad);
  *(hkVector4f *)&stackInstance.m_stack[4] = (hkVector4f)start->m_quad;
  v8 = _mm_cmpeq_ps((__m128)0i64, (__m128)v7);
  v9 = _mm_rcp_ps((__m128)v7);
  *(__m128 *)&stackInstance.m_stack[8] = _mm_shuffle_ps((__m128)v7, _mm_unpackhi_ps((__m128)v7, query.m_quad), 196);
  *(__m128 *)&stackInstance.m_stack[28] = _mm_or_ps(
                                            _mm_and_ps(
                                              _mm_xor_ps(
                                                (__m128)_mm_slli_epi32(_mm_srli_epi32(v7, 0x1Fu), 0x1Fu),
                                                (__m128)_xmm),
                                              v8),
                                            _mm_andnot_ps(
                                              v8,
                                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, (__m128)v7)), v9)));
  stackInstance.m_stack[31] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, *(__m128 *)&stackInstance.m_stack[8])) & 7 | 0x3F000000;
  *(_QWORD *)stackInstance.m_stack = &v10;
  *(_OWORD *)&stackInstance.m_stack[12] = *(_OWORD *)&stackInstance.m_stack[28];
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::RayCastWrapper<FirstHitRayQuery>>(
    m_tree,
    (EdgeGeomRaycastAabbTree *)&stackInstance.m_stack[32],
    &stackInstance,
    (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::RayCastWrapper<FirstHitRayQuery> *)m_tree);
  if ( _mm_shuffle_ps(*(__m128 *)&stackInstance.m_stack[8], *(__m128 *)&stackInstance.m_stack[8], 255).m128_f32[0] < 1.0 )
    return 1;
  return v6;
}

// File Line: 926
// RVA: 0xB7C490
unsigned int __fastcall hkaiEdgeGeometryRaycaster::castRayExtruded(
        hkaiEdgeGeometryRaycaster *this,
        hkVector4f *start,
        hkVector4f *end,
        hkVector4f *extrusion)
{
  __int128 m_quad; // xmm0
  hkVector4f ends; // [rsp+30h] [rbp-88h] BYREF
  __int128 v7; // [rsp+40h] [rbp-78h]
  __int128 v8; // [rsp+50h] [rbp-68h]
  __int128 v9; // [rsp+60h] [rbp-58h]
  hkVector4f starts; // [rsp+70h] [rbp-48h] BYREF
  __m128 v11; // [rsp+80h] [rbp-38h]
  __m128 v12; // [rsp+90h] [rbp-28h]
  __m128 v13; // [rsp+A0h] [rbp-18h]

  if ( !this->m_tree )
    return 0;
  m_quad = (__int128)end->m_quad;
  starts.m_quad = start->m_quad;
  ends.m_quad = (__m128)m_quad;
  v11 = starts.m_quad;
  v7 = m_quad;
  v12 = starts.m_quad;
  v8 = m_quad;
  v13 = starts.m_quad;
  v9 = m_quad;
  return hkaiEdgeGeometryRaycaster::castRayBundleExtruded(this, &starts, &ends, extrusion, STOP_BUNDLE_ON_HIT);
}

// File Line: 943
// RVA: 0xB7C510
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRayBundle(
        hkaiEdgeGeometryRaycaster *this,
        hkVector4f *starts,
        hkVector4f *ends,
        hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut)
{
  unsigned int v6; // esi
  signed __int64 v7; // r8
  RayBundleQuery *v8; // r9
  unsigned int *v9; // rcx
  __int64 v10; // r11
  __m128 v11; // xmm6
  __m128 v12; // xmm5
  __m128i v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *m_tree; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 m_quad; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v28; // [rsp+30h] [rbp-D0h]
  __m128 v29; // [rsp+40h] [rbp-C0h]
  __m128 v30; // [rsp+50h] [rbp-B0h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+60h] [rbp-A0h] BYREF
  int v32; // [rsp+1B0h] [rbp+B0h]
  hkaiEdgeGeometryRaycaster::BundleEarlyOut v33; // [rsp+1B4h] [rbp+B4h]
  int v34; // [rsp+1B8h] [rbp+B8h]
  __int128 v35; // [rsp+1C0h] [rbp+C0h]
  __int128 v36; // [rsp+1D0h] [rbp+D0h]
  __int128 v37; // [rsp+1E0h] [rbp+E0h]
  EdgeGeomRaycastAabbTree tree; // [rsp+1F0h] [rbp+F0h] BYREF
  int v39; // [rsp+2F0h] [rbp+1F0h]

  if ( !this->m_tree )
    return 0i64;
  v6 = 0;
  *(_QWORD *)&stackInstance.m_stack[34] = ends;
  v33 = earlyOut;
  v7 = (char *)ends - (char *)starts;
  *(_QWORD *)stackInstance.m_stack = 0i64;
  *(_QWORD *)&stackInstance.m_stack[32] = starts;
  v8 = (RayBundleQuery *)starts;
  v9 = &stackInstance.m_stack[44];
  v10 = 4i64;
  *(hkVector4f *)&stackInstance.m_stack[28] = (hkVector4f)query.m_quad;
  memset(&stackInstance.m_stack[4], 0, 96);
  do
  {
    v11 = *(__m128 *)&v8->m_caster;
    v12 = *(__m128 *)((char *)&v8->m_caster + v7);
    v8 = (RayBundleQuery *)((char *)v8 + 16);
    v9 += 12;
    v13 = (__m128i)_mm_sub_ps(v12, v11);
    v14 = _mm_cmpeq_ps((__m128)0i64, (__m128)v13);
    v15 = _mm_rcp_ps((__m128)v13);
    v16 = _mm_shuffle_ps((__m128)v13, _mm_unpackhi_ps((__m128)v13, query.m_quad), 196);
    *((__m128 *)v9 - 4) = v16;
    *((__m128 *)v9 - 3) = _mm_or_ps(
                            _mm_and_ps(
                              _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v13, 0x1Fu), 0x1Fu), (__m128)_xmm),
                              v14),
                            _mm_andnot_ps(v14, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, (__m128)v13)), v15)));
    *(v9 - 9) = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v16)) & 7 | 0x3F000000;
    *((__m128 *)v9 - 5) = v11;
    *(_OWORD *)((char *)v8 + (char *)&v27 - (char *)starts - 16) = *((_OWORD *)v9 - 3);
    --v10;
  }
  while ( v10 );
  m_tree = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)this->m_tree;
  v34 = 0;
  v32 = 1;
  v35 = 0i64;
  *(_QWORD *)stackInstance.m_stack = this;
  v39 = 0;
  v36 = 0i64;
  v37 = 0i64;
  v18 = _mm_shuffle_ps(v29, v30, 68);
  v19 = _mm_shuffle_ps(v27, v28, 68);
  m_quad = starts[2].m_quad;
  *(__m128 *)&stackInstance.m_stack[24] = _mm_shuffle_ps(
                                            _mm_shuffle_ps(v27, v28, 238),
                                            _mm_shuffle_ps(v29, v30, 238),
                                            136);
  v21 = starts->m_quad;
  v22 = starts->m_quad;
  *(__m128 *)&stackInstance.m_stack[16] = _mm_shuffle_ps(v19, v18, 136);
  *(__m128 *)&stackInstance.m_stack[20] = _mm_shuffle_ps(v19, v18, 221);
  v23 = _mm_shuffle_ps(v22, starts[1].m_quad, 68);
  v24 = _mm_shuffle_ps(m_quad, starts[3].m_quad, 68);
  v25 = _mm_shuffle_ps(v21, starts[1].m_quad, 238);
  v26 = _mm_shuffle_ps(m_quad, starts[3].m_quad, 238);
  *(__m128 *)&stackInstance.m_stack[4] = _mm_shuffle_ps(v23, v24, 136);
  *(__m128 *)&stackInstance.m_stack[8] = _mm_shuffle_ps(v23, v24, 221);
  *(__m128 *)&stackInstance.m_stack[12] = _mm_shuffle_ps(v25, v26, 136);
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,RayBundleQuery>(
    m_tree,
    &tree,
    &stackInstance,
    v8);
  LOBYTE(v6) = _mm_movemask_ps(_mm_cmplt_ps(*(__m128 *)&stackInstance.m_stack[28], query.m_quad)) == 15;
  return v6;
}

// File Line: 961
// RVA: 0xB7C790
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRayBundleExtruded(
        hkaiEdgeGeometryRaycaster *this,
        hkVector4f *starts,
        hkVector4f *ends,
        hkVector4f *extrusion,
        hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut)
{
  hkVector4f *v6; // r10
  unsigned int v9; // esi
  signed __int64 v10; // r8
  unsigned int *v11; // rcx
  RayBundleQuery *v12; // r9
  __int64 v13; // r11
  __m128 m_quad; // xmm6
  __m128 v15; // xmm5
  __m128i v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *m_tree; // rcx
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v33; // [rsp+30h] [rbp-D0h]
  __m128 v34; // [rsp+40h] [rbp-C0h]
  __m128 v35; // [rsp+50h] [rbp-B0h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+60h] [rbp-A0h] BYREF
  int v37; // [rsp+1B0h] [rbp+B0h]
  hkaiEdgeGeometryRaycaster::BundleEarlyOut v38; // [rsp+1B4h] [rbp+B4h]
  int v39; // [rsp+1B8h] [rbp+B8h]
  __m128 v40; // [rsp+1C0h] [rbp+C0h]
  __m128 v41; // [rsp+1D0h] [rbp+D0h]
  __m128 v42; // [rsp+1E0h] [rbp+E0h]
  EdgeGeomRaycastAabbTree tree; // [rsp+1F0h] [rbp+F0h] BYREF
  int v44; // [rsp+2F0h] [rbp+1F0h]

  v6 = starts;
  if ( !this->m_tree )
    return 0i64;
  v9 = 0;
  *(_QWORD *)&stackInstance.m_stack[34] = ends;
  v10 = (char *)ends - (char *)starts;
  *(_QWORD *)&stackInstance.m_stack[32] = starts;
  v38 = earlyOut;
  *(_QWORD *)stackInstance.m_stack = 0i64;
  v11 = &stackInstance.m_stack[44];
  v12 = (RayBundleQuery *)((char *)&v32 - (char *)starts);
  *(hkVector4f *)&stackInstance.m_stack[28] = (hkVector4f)query.m_quad;
  memset(&stackInstance.m_stack[4], 0, 96);
  v13 = 4i64;
  do
  {
    m_quad = starts->m_quad;
    v15 = *(__m128 *)((char *)&starts->m_quad + v10);
    ++starts;
    v11 += 12;
    v16 = (__m128i)_mm_sub_ps(v15, m_quad);
    v17 = _mm_cmpeq_ps((__m128)0i64, (__m128)v16);
    v18 = _mm_rcp_ps((__m128)v16);
    v19 = _mm_shuffle_ps((__m128)v16, _mm_unpackhi_ps((__m128)v16, query.m_quad), 196);
    *((__m128 *)v11 - 4) = v19;
    *((__m128 *)v11 - 3) = _mm_or_ps(
                             _mm_and_ps(
                               _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v16, 0x1Fu), 0x1Fu), (__m128)_xmm),
                               v17),
                             _mm_andnot_ps(v17, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v16, v18)), v18)));
    *(v11 - 9) = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v19)) & 7 | 0x3F000000;
    *((__m128 *)v11 - 5) = m_quad;
    *(_OWORD *)((char *)v12 + (_QWORD)starts - 16) = *((_OWORD *)v11 - 3);
    --v13;
  }
  while ( v13 );
  m_tree = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)this->m_tree;
  v37 = 1;
  *(_QWORD *)stackInstance.m_stack = this;
  v39 = 1;
  v44 = 0;
  v21 = _mm_shuffle_ps(v34, v35, 68);
  v22 = _mm_shuffle_ps(v32, v33, 68);
  v23 = v6[2].m_quad;
  *(__m128 *)&stackInstance.m_stack[24] = _mm_shuffle_ps(
                                            _mm_shuffle_ps(v32, v33, 238),
                                            _mm_shuffle_ps(v34, v35, 238),
                                            136);
  v24 = _mm_shuffle_ps(v6->m_quad, v6[1].m_quad, 68);
  v25 = _mm_shuffle_ps(v6->m_quad, v6[1].m_quad, 238);
  *(__m128 *)&stackInstance.m_stack[16] = _mm_shuffle_ps(v22, v21, 136);
  v26 = _mm_shuffle_ps(v22, v21, 221);
  v27 = _mm_shuffle_ps(v23, v6[3].m_quad, 68);
  v28 = _mm_shuffle_ps(v23, v6[3].m_quad, 238);
  *(__m128 *)&stackInstance.m_stack[20] = v26;
  *(__m128 *)&stackInstance.m_stack[4] = _mm_shuffle_ps(v24, v27, 136);
  *(__m128 *)&stackInstance.m_stack[8] = _mm_shuffle_ps(v24, v27, 221);
  v29 = extrusion->m_quad;
  v30 = extrusion->m_quad;
  *(__m128 *)&stackInstance.m_stack[12] = _mm_shuffle_ps(v25, v28, 136);
  v31 = _mm_cmple_ps(v29, (__m128)0i64);
  v40 = v29;
  v41 = _mm_or_ps(_mm_andnot_ps(v31, (__m128)0i64), _mm_and_ps(v30, v31));
  v42 = _mm_or_ps(_mm_andnot_ps(v31, v29), _mm_and_ps((__m128)0i64, v31));
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,RayBundleQuery>(
    m_tree,
    &tree,
    &stackInstance,
    v12);
  LOBYTE(v9) = _mm_movemask_ps(_mm_cmplt_ps(*(__m128 *)&stackInstance.m_stack[28], query.m_quad)) == 15;
  return v9;
}

// File Line: 1000
// RVA: 0xB7EB70
void __fastcall SmallRayBundleExtrudedQuery::SmallRayBundleExtrudedQuery(
        SmallRayBundleExtrudedQuery *this,
        hkVector4f *starts,
        hkVector4f *ends,
        hkVector4f *extrusion)
{
  signed __int64 v5; // r8
  __m128 m_quad; // xmm0
  __m128i inserted; // xmm7
  __int64 v8; // r11
  __m128 v9; // xmm6
  hkVector4f *p_m_direction; // r9
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128i v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  int v17; // eax
  __m128 v18; // xmm1

  this->m_ends = ends;
  this->m_caster = 0i64;
  this->m_starts = starts;
  v5 = (char *)ends - (char *)starts;
  m_quad = extrusion->m_quad;
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_rayStillAlive = 511;
  v8 = 9i64;
  this->m_extrusion.m_quad = m_quad;
  v9 = (__m128)xmmword_141A712A0;
  p_m_direction = &this->m_rays[0].m_direction;
  v11 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), (__m128)xmmword_141A712A0);
  do
  {
    v12 = starts->m_quad;
    v13 = *(__m128 *)((char *)&starts->m_quad + v5);
    p_m_direction += 3;
    ++starts;
    v9 = _mm_min_ps(_mm_min_ps(v9, v12), v13);
    v11 = _mm_max_ps(_mm_max_ps(v11, v12), v13);
    v14 = (__m128i)_mm_sub_ps(v13, v12);
    v15 = _mm_cmpeq_ps((__m128)0i64, (__m128)v14);
    v16 = _mm_rcp_ps((__m128)v14);
    p_m_direction[-3].m_quad = _mm_shuffle_ps((__m128)v14, _mm_unpackhi_ps((__m128)v14, query.m_quad), 196);
    v17 = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, p_m_direction[-3].m_quad)) & 7 | 0x3F000000;
    p_m_direction[-2].m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v14, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v15),
                                 _mm_andnot_ps(
                                   v15,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, (__m128)v14)), v16)));
    p_m_direction[-2].m_quad.m128_i32[3] = v17;
    p_m_direction[-4] = (hkVector4f)starts[-1].m_quad;
    --v8;
  }
  while ( v8 );
  v18 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), extrusion->m_quad);
  this->m_rayAabb.m_min.m_quad = _mm_min_ps(v9, _mm_add_ps(v9, v18));
  this->m_rayAabb.m_max.m_quad = _mm_max_ps(v11, _mm_add_ps(v11, v18));
}

// File Line: 1016
// RVA: 0xB7F2A0
__int64 __fastcall SmallRayBundleExtrudedQuery::processLeaf(
        SmallRayBundleExtrudedQuery *this,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > >::NodeContext *leaf)
{
  int v3; // r12d
  int v4; // ebp
  hkcdRay *ray; // r14
  bool v6; // r15
  int v7; // edi
  __int64 v8; // rsi
  hkVector4f *v9; // r9
  hkVector4f *v10; // r8
  int v12; // eax
  hkSimdFloat32 hitFractionInOut; // [rsp+40h] [rbp-38h] BYREF
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> v15; // [rsp+80h] [rbp+8h] BYREF

  v3 = leaf->m_node->m_children[1];
  hkaiEdgeGeometryRaycaster::getFlagsForFace(this->m_caster, &v15, v3);
  v4 = 1;
  ray = this->m_rays;
  v6 = (v15.m_storage & 4) == 0;
  v7 = 0;
  v8 = 0i64;
  do
  {
    if ( (v4 & this->m_rayStillAlive) != 0 )
    {
      v9 = &this->m_ends[v8];
      v10 = &this->m_starts[v8];
      hitFractionInOut.m_real = query.m_quad;
      if ( v6
         ? hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(
             this->m_caster,
             v3,
             v10,
             v9,
             ray,
             &this->m_extrusion,
             1,
             &hitFractionInOut)
         : hkaiEdgeGeometryRaycaster::raycastAgainstFace(this->m_caster, v3, v10, v9, &hitFractionInOut) )
      {
        if ( v7 > 2 )
        {
          v12 = 448;
          if ( v7 <= 5 )
            v12 = 56;
        }
        else
        {
          v12 = 7;
        }
        this->m_rayStillAlive &= ~v12;
      }
    }
    ++v7;
    v4 *= 2;
    ++ray;
    ++v8;
  }
  while ( v7 < 9 );
  return this->m_rayStillAlive;
}

// File Line: 1063
// RVA: 0xB7CA50
__int64 __fastcall hkaiEdgeGeometryRaycaster::castSmallRayBundleExtruded(
        hkaiEdgeGeometryRaycaster *this,
        hkVector4f *starts,
        hkVector4f *ends,
        hkVector4f *extrusion)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_tree; // rdi
  unsigned int v6; // esi
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<SmallRayBundleExtrudedQuery> *v8; // r9
  hkcdDynamicTree::CodecRaw<unsigned int> *m_cur; // rdx
  hkVector4f *p_m_max; // rcx
  int m_size; // eax
  char *v12; // rdi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // r8d
  EdgeGeomRaycastAabbTree tree; // [rsp+20h] [rbp-E0h] BYREF
  int v18; // [rsp+48h] [rbp-B8h]
  hkAabb m_rayAabb; // [rsp+50h] [rbp-B0h]
  SmallRayBundleExtrudedQuery v20; // [rsp+70h] [rbp-90h] BYREF

  m_tree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_tree;
  SmallRayBundleExtrudedQuery::SmallRayBundleExtrudedQuery(&v20, starts, ends, extrusion);
  v6 = 0;
  v20.m_caster = this;
  *(_QWORD *)&tree.m_root = &v20;
  m_rayAabb = v20.m_rayAabb;
  v18 = 1;
  tree.m_nodes.m_capacityAndFlags = 0x80000000;
  tree.m_numLeaves = 64;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::CodecRaw<unsigned int> *)Value->m_cur;
  p_m_max = &m_cur[5].m_aabb.m_max;
  if ( Value->m_slabSize < 256 || p_m_max > Value->m_end )
    m_cur = (hkcdDynamicTree::CodecRaw<unsigned int> *)hkLifoAllocator::allocateFromNewSlab(Value, 256);
  else
    Value->m_cur = p_m_max;
  tree.m_nodes.m_data = m_cur;
  *(_QWORD *)&tree.m_firstFree = m_cur;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<SmallRayBundleExtrudedQuery>>(
    m_tree,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&tree.m_root,
    v8);
  m_size = tree.m_nodes.m_size;
  v12 = *(char **)&tree.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRaw<unsigned int> **)&tree.m_firstFree == tree.m_nodes.m_data )
    m_size = 0;
  tree.m_nodes.m_size = m_size;
  v13 = (4 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v14->m_slabSize || &v12[v15] != v14->m_cur || v14->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v14, v12, v15);
  else
    v14->m_cur = v12;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      4 * tree.m_nodes.m_capacityAndFlags);
  LOBYTE(v6) = v20.m_rayStillAlive == 0;
  return v6;
}

// File Line: 1077
// RVA: 0xB7CBF0
void __fastcall hkaiEdgeGeometryRaycaster::setupForRemoveUnreachableTriangles(hkaiEdgeGeometryRaycaster *this)
{
  this->m_faceFlagMask.m_storage = 9;
  this->m_ignoreFaceIndex = -1;
}

// File Line: 1084
// RVA: 0xB7CC10
void __fastcall hkaiEdgeGeometryRaycaster::setupForEdgeConnections(hkaiEdgeGeometryRaycaster *this)
{
  this->m_faceFlagMask.m_storage = 13;
  this->m_ignoreFaceIndex = -1;
}

// File Line: 1091
// RVA: 0xB7CC30
void __fastcall hkaiEdgeGeometryRaycaster::setHitFilter(
        hkaiEdgeGeometryRaycaster *this,
        hkaiEdgeGeometryHitFilter *filter)
{
  hkaiEdgeGeometryHitFilter *m_pntr; // rcx

  if ( filter )
    hkReferencedObject::addReference(filter);
  m_pntr = this->m_hitFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_hitFilter.m_pntr = filter;
}

