// File Line: 219
// RVA: 0xCD9360
hkgpMeshInternals::Ring *__fastcall hkgpMeshInternals::createRing(hkgpMeshBase::Edge *edge)
{
  __int64 v2; // r14
  hkgpMeshBase::Triangle *m_triangle; // rbp
  _QWORD **Value; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  hkgpMeshBase::Triangle **v7; // rcx
  unsigned int v8; // r8d
  char v9; // cl
  int v10; // eax
  int v11; // eax
  int *v12; // rax
  __int64 v13; // r9
  __int64 v14; // r10
  __int64 v15; // r11
  __int64 v16; // rax
  int v17; // r8d
  _QWORD **v18; // rax
  __int64 v20; // [rsp+28h] [rbp-30h]
  __int64 v21; // [rsp+38h] [rbp-20h]

  if ( (edge->m_triangle->m_links[edge->m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    return 0i64;
  v2 = *(_QWORD *)&edge->m_index;
  m_triangle = edge->m_triangle;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
  v6 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = 0i64;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0x80000000;
  }
  else
  {
    v6 = 0i64;
  }
  do
  {
    if ( *(_DWORD *)(v6 + 8) == (*(_DWORD *)(v6 + 12) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v6, 64);
    v7 = (hkgpMeshBase::Triangle **)(*(_QWORD *)v6 + ((__int64)(int)(*(_DWORD *)(v6 + 8))++ << 6));
    *v7 = edge->m_triangle;
    v7[1] = *(hkgpMeshBase::Triangle **)&edge->m_index;
    v8 = 2 * edge->m_index;
    if ( edge->m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(edge->m_index))) & 3] == m_triangle->m_vertices[(int)v2] )
      break;
    edge->m_triangle = edge->m_triangle;
    LODWORD(v20) = (9 >> v8) & 3;
    *(_QWORD *)&edge->m_index = v20;
    if ( (edge->m_triangle->m_links[(int)v20] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    {
      do
      {
        v9 = edge->m_triangle->m_links[edge->m_index] & 3;
        edge->m_triangle = (hkgpMeshBase::Triangle *)(edge->m_triangle->m_links[edge->m_index] & 0xFFFFFFFFFFFFFFFCui64);
        LODWORD(v21) = (9 >> (2 * v9)) & 3;
        *(_QWORD *)&edge->m_index = v21;
      }
      while ( (edge->m_triangle->m_links[(int)v21] & 0xFFFFFFFFFFFFFFFCui64) != 0 );
    }
  }
  while ( (char *)edge->m_triangle + edge->m_index != (char *)m_triangle + (unsigned int)v2 );
  v10 = *(_DWORD *)(v6 + 8);
  if ( v10 > 0
    && *(_QWORD *)(**(_QWORD **)v6 + 8i64 * *(int *)(*(_QWORD *)v6 + 8i64) + 16) != *(_QWORD *)(*(_QWORD *)(((__int64)(v10 - 1) << 6) + *(_QWORD *)v6)
                                                                                              + 8
                                                                                              * ((9i64 >> (2 * (unsigned __int8)*(_DWORD *)(((__int64)(v10 - 1) << 6) + *(_QWORD *)v6 + 8))) & 3)
                                                                                              + 16) )
  {
    *(_DWORD *)(v6 + 8) = 0;
  }
  v11 = *(_DWORD *)(v6 + 8);
  if ( v11 >= 3 )
    return (hkgpMeshInternals::Ring *)v6;
  if ( v11 == 2 )
  {
    v12 = *(int **)v6;
    v13 = *(_QWORD *)(*(_QWORD *)v6 + 64i64);
    if ( !v13 )
      return (hkgpMeshInternals::Ring *)v6;
    v14 = v12[18];
    v15 = v12[2];
    v16 = *(_QWORD *)v12;
    if ( *(_QWORD *)(v16 + 8 * v15 + 16) == *(_QWORD *)(v13 + 8 * ((9i64 >> (2 * (unsigned __int8)v14)) & 3) + 16)
      && *(_QWORD *)(v16 + 8 * ((9i64 >> (2 * (unsigned __int8)v15)) & 3) + 16) == *(_QWORD *)(v13 + 8 * v14 + 16) )
    {
      return (hkgpMeshInternals::Ring *)v6;
    }
  }
  *(_DWORD *)(v6 + 8) = 0;
  v17 = *(_DWORD *)(v6 + 12);
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)v6, v17 << 6);
  *(_QWORD *)v6 = 0i64;
  *(_DWORD *)(v6 + 12) = 0x80000000;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v18[11] + 16i64))(v18[11], v6, 16i64);
  return 0i64;
}

// File Line: 280
// RVA: 0xCE0410
void __fastcall hkgpMeshInternals::ConcaveEdgeJob::run(hkgpMeshInternals::ConcaveEdgeJob *this)
{
  hkgpConvexHull *ConvexHull; // rax
  int m_size; // ecx
  hkgpConvexHull *v4; // r10
  int v5; // r12d
  __int64 v6; // r13
  __int64 v7; // r15
  hkgpMeshInternals::Segment *v8; // rdi
  char *m_valid; // rsi
  hkVector4f *m_normals; // rbx
  hkgpMeshInternals::Segment *m_data; // rax
  __int64 v12; // rdx
  __m128i v13; // xmm0
  __m128 m_quad; // xmm7
  __m128 v15; // xmm8
  hkVector4f v16; // xmm11
  hkVector4f v17; // xmm14
  __m128 v18; // xmm9
  hkVector4f v19; // xmm10
  __m128 m_real; // xmm12
  __m128 v21; // xmm13
  char v22; // r13
  char v23; // si
  float v24; // xmm6_4
  float v25; // xmm8_4
  hkgpMeshBase::Triangle *v26; // rax
  hkgpMesh *m_mesh; // rcx
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  hkgpMesh *v30; // rcx
  int v31; // edi
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm4
  __m128 v38; // xmm15
  hkgpMesh *v39; // rcx
  char v40; // r15
  __int64 v41; // rax
  char v42; // r12
  hkgpMeshInternals::Segment *v43; // rdx
  __m128 v44; // xmm0
  __int64 v45; // rcx
  hkgpMeshInternals::Segment *v46; // rdx
  __m128 v47; // xmm0
  __m128 v48; // [rsp+30h] [rbp-D0h]
  __m128 v49; // [rsp+30h] [rbp-D0h]
  hkVector4f v50; // [rsp+40h] [rbp-C0h] BYREF
  __m128 v51; // [rsp+50h] [rbp-B0h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> point; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f normal; // [rsp+90h] [rbp-70h] BYREF
  hkgpMesh::Location location; // [rsp+A0h] [rbp-60h] BYREF
  hkSimdFloat32 offset; // [rsp+120h] [rbp+20h] BYREF
  __m128 v56; // [rsp+130h] [rbp+30h]
  __m128 v57; // [rsp+140h] [rbp+40h]
  __m128 v58; // [rsp+150h] [rbp+50h]
  __m128 v59; // [rsp+160h] [rbp+60h]
  hkVector4f a; // [rsp+170h] [rbp+70h] BYREF
  __m128 v61; // [rsp+180h] [rbp+80h]
  __m128 v62; // [rsp+190h] [rbp+90h]
  __m128 v63; // [rsp+1A0h] [rbp+A0h]
  __m128i v64; // [rsp+1B0h] [rbp+B0h]
  hkBool result; // [rsp+2A0h] [rbp+1A0h] BYREF
  int v66; // [rsp+2A8h] [rbp+1A8h]
  hkgpConvexHull *v67; // [rsp+2B0h] [rbp+1B0h]

  ConvexHull = hkgpMesh::getConvexHull(this->m_mesh);
  m_size = this->m_segments.m_size;
  v4 = ConvexHull;
  v67 = ConvexHull;
  if ( m_size )
  {
    v5 = 0;
    if ( m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = 2i64;
        v8 = &this->m_segments.m_data[v6];
        m_valid = (char *)v8->m_valid;
        m_normals = v8->m_normals;
        do
        {
          v8->m_offsets[0] = v8->m_vertices[0];
          *m_valid++ = hkgpMesh::computeOffsetPoint(
                         this->m_mesh,
                         (hkSimdFloat32 *)&m_normals[4],
                         m_normals,
                         (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&m_normals[2],
                         8,
                         1);
          ++m_normals;
          v8 = (hkgpMeshInternals::Segment *)((char *)v8 + 16);
          --v7;
        }
        while ( v7 );
        ++v5;
        ++v6;
      }
      while ( v5 < this->m_segments.m_size );
      v4 = v67;
    }
    do
    {
      m_data = this->m_segments.m_data;
      v12 = this->m_segments.m_size;
      v13 = *(__m128i *)m_data[v12 - 1].m_valid;
      m_quad = m_data[v12 - 1].m_normals[0].m_quad;
      v15 = m_data[v12 - 1].m_normals[1].m_quad;
      v16.m_quad = (__m128)m_data[v12 - 1].m_vertices[0];
      v17.m_quad = (__m128)m_data[v12 - 1].m_vertices[1];
      v18 = m_data[v12 - 1].m_offsets[0].m_quad;
      v19.m_quad = (__m128)m_data[v12 - 1].m_offsets[1];
      m_real = m_data[v12 - 1].m_offsetsValues[0].m_real;
      v21 = m_data[v12 - 1].m_offsetsValues[1].m_real;
      this->m_segments.m_size = v12 - 1;
      v22 = _mm_cvtsi128_si32(v13);
      v64 = v13;
      v56 = v16.m_quad;
      v23 = v13.m128i_i8[1];
      v57 = v17.m_quad;
      v51 = m_quad;
      v58 = m_quad;
      v48 = v15;
      v59 = v15;
      a.m_quad = v18;
      v61 = v19.m_quad;
      v62 = m_real;
      v63 = v21;
      if ( !v22 || !v13.m128i_i8[1] )
        goto LABEL_20;
      point.m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                          _mm_mul_ps(
                                                                                            _mm_sub_ps(v19.m_quad, v18),
                                                                                            (__m128)xmmword_141A711B0),
                                                                                          v18);
      if ( !v4 || hkgpConvexHull::isPointInside(v4, &result, (hkVector4f *)&point, (hkBool)1, 0.0)->m_bool )
      {
        v66 = 1065185444;
        location.m_region.m_type = NONE;
        v24 = (float)(v21.m128_f32[0] + m_real.m128_f32[0]) * 0.5;
        v25 = _mm_shuffle_ps((__m128)0x3F7D70A4u, (__m128)0x3F7D70A4u, 0).m128_f32[0] * v24;
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v26 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v26 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        }
        m_mesh = this->m_mesh;
        location.m_region.m_feature.m_triangle = v26;
        memset(&location, 0, 48);
        *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                          + 1);
        location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
        location.m_inside.m_real = g_vectorfConstants[0];
        hkgpMesh::locate(m_mesh, &point, &location, (hkBool)1);
        v28 = _mm_rsqrt_ps(location.m_squaredDistance.m_real);
        v29 = _mm_cmple_ps(location.m_squaredDistance.m_real, (__m128)0i64);
        if ( (float)(_mm_andnot_ps(
                       v29,
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(location.m_squaredDistance.m_real, v28), v28)),
                           _mm_mul_ps(*(__m128 *)_xmm, v28)),
                         location.m_squaredDistance.m_real)).m128_f32[0]
                   * location.m_inside.m_real.m128_f32[0]) <= v25 )
          goto LABEL_19;
        if ( (float)(_mm_andnot_ps(
                       v29,
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(location.m_squaredDistance.m_real, v28), v28)),
                           _mm_mul_ps(*(__m128 *)_xmm, v28)),
                         location.m_squaredDistance.m_real)).m128_f32[0]
                   * location.m_inside.m_real.m128_f32[0]) >= (float)(v24 + v24) )
          goto LABEL_19;
        v30 = this->m_mesh;
        location.m_normal = (hkVector4f)v16.m_quad;
        location.m_pseudoNormal = (hkVector4f)v17.m_quad;
        location.m_coordinates.m_quad = v18;
        location.m_projection = (hkVector4f)v19.m_quad;
        point.m_firstFree = (unsigned __int64)&hkgpMesh::ExternShape::`vftable;
        *(_QWORD *)&point.m_numLeaves = &location;
        LODWORD(point.m_root) = 4;
        if ( (unsigned __int8)hkgpMesh::checkOverlap(
                                v30,
                                (hkgpMesh::IConvexOverlap::IConvexShape *)&point.m_firstFree,
                                (float)(0.0 - v24) * 0.0099999998,
                                1) )
        {
LABEL_19:
          m_quad = v51;
          v15 = v48;
LABEL_20:
          v31 = v64.m128i_i32[1];
          if ( v64.m128i_i32[1] < 5 )
          {
            v32 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v15, m_quad), (__m128)xmmword_141A711B0), m_quad);
            v49 = _mm_mul_ps(_mm_add_ps(v21, m_real), (__m128)xmmword_141A711B0);
            offset.m_real = v49;
            v33 = _mm_mul_ps(v32, v32);
            v34 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17.m_quad, v16.m_quad), (__m128)xmmword_141A711B0), v16.m_quad);
            v35 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                    _mm_shuffle_ps(v33, v33, 170));
            v36 = _mm_rsqrt_ps(v35);
            v37 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v35), (__m128)0i64);
            v38 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v35, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                            _mm_mul_ps(*(__m128 *)_xmm, v36))),
                        v32),
                      v37),
                    _mm_andnot_ps(v37, v32));
            normal.m_quad = v38;
            if ( _mm_movemask_ps(v37) )
            {
              v39 = this->m_mesh;
              v50.m_quad = v34;
              v40 = hkgpMesh::computeOffsetPoint(
                      v39,
                      &offset,
                      &normal,
                      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v50,
                      8,
                      1);
              if ( this->m_segments.m_size == (this->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&this->m_segments.m_data,
                  144);
              v41 = this->m_segments.m_size;
              v42 = v64.m128i_i8[2];
              v43 = &this->m_segments.m_data[v41];
              this->m_segments.m_size = v41 + 1;
              v43->m_vertices[0] = (hkVector4f)v16.m_quad;
              v43->m_normals[0].m_quad = m_quad;
              v43->m_offsets[0].m_quad = v18;
              v43->m_offsets[1] = (hkVector4f)v19.m_quad;
              v43->m_offsetsValues[0].m_real = m_real;
              v43->m_offsetsValues[1].m_real = v21;
              v43->m_valid[0] = v22;
              v43->m_valid[1] = v13.m128i_i8[1];
              v43->m_depth = v31;
              v43->m_planar = v42;
              v43->m_vertices[1].m_quad = v34;
              v43->m_normals[1].m_quad = v38;
              v44 = v50.m_quad;
              v43->m_valid[1] = v40;
              v43->m_offsets[1].m_quad = v44;
              v43->m_offsetsValues[1].m_real = v49;
              ++v43->m_depth;
              if ( this->m_segments.m_size == (this->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&this->m_segments.m_data,
                  144);
              v45 = this->m_segments.m_size;
              this->m_segments.m_size = v45 + 1;
              v46 = &this->m_segments.m_data[v45];
              v46->m_vertices[1] = (hkVector4f)v17.m_quad;
              v46->m_normals[1].m_quad = v15;
              v46->m_offsets[0].m_quad = v18;
              v46->m_offsets[1] = (hkVector4f)v19.m_quad;
              v46->m_offsetsValues[0].m_real = m_real;
              v46->m_offsetsValues[1].m_real = v21;
              v46->m_valid[0] = v22;
              v46->m_valid[1] = v23;
              v46->m_depth = v31;
              v46->m_planar = v42;
              v46->m_vertices[0].m_quad = v34;
              v46->m_normals[0].m_quad = v38;
              v47 = v50.m_quad;
              v46->m_valid[0] = v40;
              v46->m_offsets[0].m_quad = v47;
              v46->m_offsetsValues[0].m_real = v49;
              ++v46->m_depth;
            }
          }
          goto LABEL_27;
        }
        hkArrayBase<hkVector4f>::_append(&this->m_edges, &hkContainerHeapAllocator::s_alloc, &a, 2);
      }
LABEL_27:
      v4 = v67;
    }
    while ( this->m_segments.m_size );
  }
}

// File Line: 399
// RVA: 0xCDC2F0
void __fastcall IConvexOverlapImpl::ShapeInterface::getSupportingVertices(
        IConvexOverlapImpl::ShapeInterface *this,
        __int64 *shapeA,
        hkVector4f *directionA,
        const void *shapeB,
        hkTransformf *aTb,
        hkcdVertex *vertexAinAOut,
        hkcdVertex *vertexBinBOut,
        hkVector4f *vertexBinAOut)
{
  __int64 v8; // rax
  hkVector4f v9; // xmm3
  __m128 v10; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 m_quad; // xmm1
  __m128 v15; // [rsp+20h] [rbp-18h] BYREF

  v8 = *shapeA;
  v9.m_quad = (__m128)aTb->m_rotation.m_col2;
  v10 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v10, v9.m_quad);
  v13 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), directionA->m_quad);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v10), v9.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              _mm_unpackhi_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad),
              v9.m_quad,
              228),
            _mm_shuffle_ps(v13, v13, 170)));
  (*(void (__fastcall **)(__int64 *, hkVector4f *, hkcdVertex *))(v8 + 16))(shapeA, directionA, vertexAinAOut);
  (*(void (__fastcall **)(const void *, __m128 *, hkcdVertex *))(*(_QWORD *)shapeB + 16i64))(
    shapeB,
    &v15,
    vertexBinBOut);
  m_quad = vertexBinBOut->m_quad;
  vertexBinAOut->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), aTb->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), aTb->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), aTb->m_rotation.m_col2.m_quad)),
                            aTb->m_translation.m_quad);
}

// File Line: 425
// RVA: 0xCD9620
float __fastcall IConvexOverlapImpl::distance(
        IConvexOverlapImpl *this,
        hkgpMesh::IConvexOverlap::IConvexShape *shapeA,
        hkgpMesh::IConvexOverlap::IConvexShape *shapeB,
        bool allowPenetration)
{
  int v6; // r14d
  __m128 v7; // xmm11
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *vfptr; // rax
  int v9; // ebx
  __m128 v10; // xmm12
  __m128 v11; // xmm14
  __m128 v12; // xmm14
  __m128 v13; // xmm8
  __m128 v14; // xmm13
  __int64 v15; // r11
  unsigned int v16; // eax
  __m128 v17; // xmm15
  __m128 *v18; // rdx
  __m128 *v19; // rcx
  __m128 v20; // xmm10
  __m128 v21; // xmm0
  __m128 v22; // xmm8
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm9
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm7
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm5
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm7
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm7
  __m128 v53; // xmm2
  int v54; // ecx
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm0
  __m128 v58; // xmm4
  __m128 v59; // xmm7
  __m128 v60; // xmm9
  __m128 v61; // xmm8
  __m128 v62; // xmm5
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  __m128 v66; // xmm12
  __m128 v67; // xmm6
  __m128 v68; // xmm12
  __m128 v69; // xmm8
  __m128 v70; // xmm6
  __m128 v71; // xmm8
  __m128 v72; // xmm6
  __m128 v73; // xmm7
  __m128 v74; // xmm1
  __m128 v75; // xmm7
  __m128 v76; // xmm2
  __m128 v77; // xmm8
  int v78; // r8d
  __m128 v79; // xmm13
  __m128 v80; // xmm1
  __m128 v81; // xmm2
  __m128 v82; // xmm15
  __m128 v83; // xmm1
  __m128 v84; // xmm12
  __m128 v85; // xmm10
  __m128 v86; // xmm1
  __m128 v87; // xmm2
  __m128 v88; // xmm9
  __m128 v89; // xmm8
  __m128 v90; // xmm1
  __m128 v91; // xmm5
  __m128 v92; // xmm1
  __m128 v93; // xmm3
  __m128 v94; // xmm1
  __m128 v95; // xmm4
  __m128 v96; // xmm1
  __m128 v97; // xmm7
  __m128 v98; // xmm1
  __m128 v99; // xmm0
  __m128 v100; // xmm3
  __m128 v101; // xmm3
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128 v104; // xmm10
  __m128 v105; // xmm1
  __m128 v106; // xmm0
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm1
  __m128 v110; // xmm10
  __m128 v111; // xmm1
  __m128 v112; // xmm9
  __m128 v113; // xmm1
  __m128 v114; // xmm4
  __m128 v115; // xmm8
  __m128 v116; // xmm1
  __m128 v117; // xmm7
  __m128 v118; // xmm5
  __m128 v119; // xmm1
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  __m128 v122; // xmm4
  __m128 v123; // xmm1
  __m128 v124; // xmm2
  __m128 v125; // xmm6
  __m128 v126; // xmm0
  __m128 v127; // xmm3
  __m128 v128; // xmm0
  __m128 v129; // xmm1
  __m128 v130; // xmm0
  __m128 v131; // xmm3
  __m128 v132; // xmm4
  __m128 v133; // xmm9
  __m128 v134; // xmm1
  __m128 v135; // xmm2
  __m128 v136; // xmm2
  __m128 v137; // xmm0
  __m128 v138; // xmm9
  __m128 v139; // xmm11
  __m128 v140; // xmm10
  __m128 v141; // xmm1
  __m128 v142; // xmm2
  __m128 v143; // xmm2
  __m128 v144; // xmm3
  __m128 v145; // xmm4
  __m128 v146; // xmm0
  __m128 v147; // xmm3
  __m128 v148; // xmm5
  __m128 v149; // xmm7
  __m128 v150; // xmm0
  __m128 v151; // xmm1
  __m128 v152; // xmm3
  __m128 v153; // xmm0
  __m128 v154; // xmm7
  __m128 v155; // xmm4
  __m128 v156; // xmm5
  __m128 v157; // xmm6
  __m128 v158; // xmm6
  __m128 v159; // xmm1
  __m128 v160; // xmm6
  __m128 v161; // xmm3
  __m128 v162; // xmm0
  __m128 v163; // xmm2
  __m128 v164; // xmm7
  __m128 v165; // xmm1
  __m128 v166; // xmm3
  __m128 v167; // xmm1
  __m128 v168; // xmm7
  __m128 v169; // xmm2
  __m128 v170; // xmm2
  __m128 v171; // xmm3
  __m128 v172; // xmm5
  __m128 v173; // xmm8
  __m128 v174; // xmm1
  __m128 v175; // xmm4
  __m128 v176; // xmm2
  __m128 v177; // xmm9
  __m128 v178; // xmm7
  __m128 v179; // xmm11
  __m128 v180; // xmm2
  __m128 v181; // xmm6
  __m128 v182; // xmm6
  __m128 v183; // xmm9
  __m128 v184; // xmm7
  __m128 v185; // xmm9
  __m128 v186; // xmm0
  __m128 v187; // xmm8
  __m128 v188; // xmm7
  __m128 v189; // xmm8
  __m128 v190; // xmm1
  __m128 v191; // xmm8
  __m128 v192; // xmm2
  __m128 v193; // xmm9
  int v194; // eax
  float v195; // xmm1_4
  float v196; // xmm10_4
  float v197; // xmm1_4
  float v198; // xmm10_4
  int v199; // ecx
  __m128 v200; // xmm9
  __m128 v201; // xmm8
  __m128 v202; // xmm5
  __m128 v203; // xmm4
  __m128 v204; // xmm2
  __m128 v205; // xmm12
  __m128 v206; // xmm0
  __m128 v207; // xmm2
  __m128 v208; // xmm4
  __m128 v209; // xmm2
  __m128 v210; // xmm3
  __m128 v211; // xmm2
  __m128 v212; // xmm4
  __m128 v213; // xmm6
  __m128 v214; // xmm2
  __m128 v215; // xmm7
  __m128 v216; // xmm1
  __m128 v217; // xmm0
  __m128 v218; // xmm1
  __m128 v219; // xmm6
  int v220; // ecx
  int v221; // ecx
  int v222; // ecx
  int v223; // ecx
  __m128 v224; // xmm1
  __m128 v225; // xmm2
  __m128 v226; // xmm11
  __m128 v227; // xmm1
  __m128 v228; // xmm2
  __m128 v229; // xmm5
  __m128 v230; // xmm10
  __m128 v231; // xmm1
  __m128 v232; // xmm9
  __m128 v233; // xmm5
  __m128 v234; // xmm1
  __m128 v235; // xmm2
  __m128 v236; // xmm1
  __m128 v237; // xmm4
  __m128 v238; // xmm1
  __m128 v239; // xmm7
  __m128 v240; // xmm0
  __m128 v241; // xmm0
  __m128 v242; // xmm2
  __m128 v243; // xmm2
  __m128 v244; // xmm0
  __m128 v245; // xmm3
  __m128 v246; // xmm2
  __m128 v247; // xmm2
  __m128 v248; // xmm0
  __m128 v249; // xmm0
  int v250; // ecx
  float v251; // xmm1_4
  float v252; // xmm10_4
  int v253; // eax
  int v254; // eax
  int v255; // eax
  __m128 v256; // xmm1
  __m128 v257; // xmm13
  __m128 v258; // xmm3
  __m128 v259; // xmm1
  __m128 v260; // xmm4
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *v261; // rax
  __m128 v262; // xmm1
  __m128 v263; // xmm3
  __m128 v264; // xmm1
  __m128 v265; // xmm2
  __m128 v266; // xmm9
  __m128 v267; // xmm9
  __m128 v268; // xmm0
  __m128 v269; // xmm3
  __m128 v270; // xmm1
  __m128 v271; // xmm6
  __m128 v272; // xmm1
  __m128 v273; // xmm2
  __m128 v274; // xmm6
  __m128 v275; // xmm2
  __m128 v276; // xmm4
  __m128 v277; // xmm3
  __m128 v278; // xmm7
  __m128 v279; // xmm2
  __m128 v280; // xmm0
  __m128 v281; // xmm1
  __m128 v282; // xmm7
  __m128 v283; // xmm2
  __m128 v284; // xmm8
  __m128 v285; // xmm8
  __m128 v286; // xmm2
  __m128 v287; // xmm6
  __m128 v288; // xmm1
  __m128 v289; // xmm10
  __m128 v290; // xmm15
  __m128 *v291; // r9
  __m128 v292; // xmm1
  __m128 v293; // xmm2
  __m128 v294; // xmm6
  __m128 v295; // xmm4
  __m128 v296; // xmm5
  __m128 v297; // xmm3
  __m128 v298; // xmm0
  __m128 v299; // xmm1
  __m128 v300; // xmm9
  __m128 v301; // xmm3
  __m128 v302; // xmm9
  __m128 v303; // xmm8
  __m128 v304; // xmm8
  __m128 v305; // xmm0
  __m128 v306; // xmm8
  __m128 v307; // xmm4
  __m128 v308; // xmm5
  __m128 v309; // xmm9
  __m128 v310; // xmm4
  __m128 v311; // xmm1
  __m128 v312; // xmm3
  __m128 v313; // xmm2
  __m128 v314; // xmm4
  __m128i v315; // xmm5
  __m128 v316; // xmm1
  __m128 v317; // xmm2
  __m128 v318; // xmm9
  __m128 v319; // xmm1
  __m128 v320; // xmm4
  __m128 v321; // xmm4
  __m128 v322; // xmm6
  int v323; // edx
  __m128 v324; // xmm2
  int v325; // eax
  int v326; // ecx
  int v327; // edi
  __int64 v328; // rsi
  __int64 v329; // r10
  int v330; // edx
  __int64 v331; // r8
  __m128 v332; // xmm0
  __m128 v333; // xmm2
  __m128 v334; // xmm4
  __m128 v335; // xmm7
  __m128 v336; // xmm5
  __m128 v337; // xmm1
  __m128 v338; // xmm3
  __m128 v339; // xmm4
  __m128 v340; // xmm7
  __int128 v341; // xmm10
  __m128 v342; // xmm1
  __m128 v343; // xmm5
  __m128 v344; // xmm2
  __m128 v345; // xmm4
  __m128 v346; // xmm3
  __m128 v347; // xmm8
  __m128 v348; // xmm9
  __m128 v349; // xmm6
  __m128 v350; // xmm7
  __m128 v351; // xmm8
  __m128 v352; // xmm8
  __m128 v353; // xmm9
  __m128 v354; // xmm6
  __m128 v355; // xmm9
  __m128 v356; // xmm6
  __m128 v357; // xmm7
  __m128 v358; // xmm1
  __m128 v359; // xmm7
  __m128 v360; // xmm2
  __m128 v361; // xmm9
  int v362; // ecx
  __m128 v363; // xmm2
  __m128 v364; // xmm0
  __int64 v365; // rcx
  int v366; // ecx
  __m128 v367; // xmm4
  __m128 v368; // xmm5
  __m128 v369; // xmm1
  __m128 v370; // xmm3
  __m128 v371; // xmm2
  __m128 v372; // xmm9
  __m128 v373; // xmm6
  __m128 v374; // xmm12
  __m128 v375; // xmm8
  __m128 v376; // xmm8
  __m128 v377; // xmm9
  __m128 v378; // xmm5
  __m128 v379; // xmm9
  __m128 v380; // xmm5
  __m128 v381; // xmm6
  __m128 v382; // xmm1
  __m128 v383; // xmm6
  __m128 v384; // xmm2
  __m128 v385; // xmm9
  int v386; // ecx
  __m128 v387; // xmm2
  __m128 v388; // xmm0
  __int64 v389; // rcx
  int v390; // ecx
  __m128 v391; // xmm6
  __m128 v392; // xmm7
  __m128 v393; // xmm5
  __m128 v394; // xmm1
  __m128 v395; // xmm4
  __m128 v396; // xmm1
  __m128 v397; // xmm2
  int v398; // eax
  __m128 v399; // xmm4
  __m128 v400; // xmm1
  __m128 v401; // xmm2
  __m128 v402; // xmm1
  __m128 v403; // xmm1
  __m128 v404; // xmm8
  __int64 v405; // r9
  __int64 v406; // rax
  __int64 v407; // rcx
  __m128 v408; // xmm0
  __m128 v409; // xmm14
  __m128 v410; // xmm3
  __m128 v411; // xmm2
  __m128 v412; // xmm3
  __m128 v413; // xmm4
  __m128 v414; // xmm7
  __m128 v415; // xmm5
  __m128 v416; // xmm1
  __m128 v417; // xmm2
  __m128 v418; // xmm1
  __m128 v419; // xmm6
  __m128 v420; // xmm5
  __m128 v421; // xmm1
  __m128 v422; // xmm8
  __m128 v423; // xmm2
  __m128 v424; // xmm2
  __m128 v425; // xmm8
  __m128 v426; // xmm2
  __int64 v427; // r9
  __int64 v428; // rax
  __int64 v429; // rcx
  __m128 v430; // xmm0
  __m128 v431; // xmm13
  __m128 v432; // xmm3
  __m128 v433; // xmm2
  __m128 v434; // xmm3
  __m128 v435; // xmm4
  __m128 v436; // xmm10
  _QWORD *Value; // rbx
  unsigned __int64 v438; // rcx
  unsigned __int64 v439; // rax
  hkcdGsk::GetClosestPointStatus v440; // eax
  _QWORD *v441; // rcx
  unsigned __int64 v442; // rax
  _QWORD *v443; // rcx
  __int64 v444; // r9
  char v445; // dl
  char v446; // r8
  int m_storage; // [rsp+48h] [rbp-80h]
  _BYTE v449[56]; // [rsp+50h] [rbp-78h] BYREF
  hkcdGskBase v450; // [rsp+90h] [rbp-38h] BYREF
  __m128 v451; // [rsp+98h] [rbp-30h] BYREF
  __m128 v452; // [rsp+A8h] [rbp-20h]
  __m128 v453; // [rsp+B8h] [rbp-10h]
  __m128 v454; // [rsp+E8h] [rbp+20h]
  __m128 v455; // [rsp+F8h] [rbp+30h]
  int v456; // [rsp+108h] [rbp+40h]
  int v457; // [rsp+10Ch] [rbp+44h]
  unsigned int v458; // [rsp+110h] [rbp+48h]
  hkcdGskBase::ShapeInterface v459; // [rsp+118h] [rbp+50h] BYREF
  int v460; // [rsp+120h] [rbp+58h]
  char v461; // [rsp+124h] [rbp+5Ch]
  __m128 v462; // [rsp+128h] [rbp+60h]
  hkTransformf aTb; // [rsp+138h] [rbp+70h] BYREF
  BOOL v464; // [rsp+178h] [rbp+B0h]
  __m128 v465; // [rsp+188h] [rbp+C0h]
  unsigned int v466; // [rsp+198h] [rbp+D0h]
  __m128 v467; // [rsp+1A8h] [rbp+E0h] BYREF
  __m128 m_quad; // [rsp+1B8h] [rbp+F0h] BYREF
  __m128 v469; // [rsp+1C8h] [rbp+100h] BYREF
  __m128 v470; // [rsp+1D8h] [rbp+110h]
  __m128 v471; // [rsp+1E8h] [rbp+120h] BYREF
  __m128 v472; // [rsp+1F8h] [rbp+130h] BYREF
  __m128 v473; // [rsp+208h] [rbp+140h]
  __m128 v474; // [rsp+218h] [rbp+150h]
  __m128 v475[3]; // [rsp+228h] [rbp+160h] BYREF
  hkcdGsk::GetClosestPointOutput output; // [rsp+258h] [rbp+190h] BYREF
  __m128 v477; // [rsp+288h] [rbp+1C0h]
  __m128 v478; // [rsp+298h] [rbp+1D0h]
  __m128 v479; // [rsp+2A8h] [rbp+1E0h]
  __m128 v480; // [rsp+2B8h] [rbp+1F0h]
  __m128 v481; // [rsp+2C8h] [rbp+200h]
  __m128 v482; // [rsp+2D8h] [rbp+210h]
  __m128 v483; // [rsp+2E8h] [rbp+220h]
  __m128 v484; // [rsp+2F8h] [rbp+230h]
  __m128 v485; // [rsp+308h] [rbp+240h]
  __m128 v486; // [rsp+318h] [rbp+250h]
  __m128 v487; // [rsp+328h] [rbp+260h]
  __m128 v488; // [rsp+338h] [rbp+270h]
  __m128 v489; // [rsp+348h] [rbp+280h]
  __m128 v490; // [rsp+358h] [rbp+290h]
  __m128 v491; // [rsp+368h] [rbp+2A0h]
  __m128 v492; // [rsp+378h] [rbp+2B0h]
  __m128 v493; // [rsp+388h] [rbp+2C0h]
  __m128 v494; // [rsp+398h] [rbp+2D0h]
  __m128 v495; // [rsp+3A8h] [rbp+2E0h]
  __m128 v496; // [rsp+3B8h] [rbp+2F0h]
  __m128 v497; // [rsp+3C8h] [rbp+300h]
  __m128 v498; // [rsp+3D8h] [rbp+310h]
  __m128 v499; // [rsp+3E8h] [rbp+320h]
  hkVector4f supportOut; // [rsp+3F8h] [rbp+330h] BYREF
  __m128 v501; // [rsp+408h] [rbp+340h]
  __m128 v502; // [rsp+418h] [rbp+350h]
  __m128 v503; // [rsp+428h] [rbp+360h]
  __m128 v504; // [rsp+438h] [rbp+370h]
  __m128 v505; // [rsp+448h] [rbp+380h]
  hkTransformf v506; // [rsp+458h] [rbp+390h]
  __m128 v507; // [rsp+498h] [rbp+3D0h]
  __m128 v508; // [rsp+4A8h] [rbp+3E0h]
  __m128 v509; // [rsp+4B8h] [rbp+3F0h]
  __m128 v510; // [rsp+4C8h] [rbp+400h]
  hkPadSpu<int> dimB; // [rsp+5C0h] [rbp+4F8h] BYREF
  float v512; // [rsp+5C8h] [rbp+500h]
  hkPadSpu<int> dimA; // [rsp+5D0h] [rbp+508h] BYREF

  v466 = LODWORD(FLOAT_1_4);
  v6 = 0;
  v461 = 65;
  v460 = 0;
  v7 = 0i64;
  v465 = (__m128)xmmword_141A712A0;
  v464 = allowPenetration;
  v459.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&IConvexOverlapImpl::ShapeInterface::`vftable;
  vfptr = shapeA->vfptr;
  aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  aTb.m_translation = 0i64;
  m_quad = transform.m_quad;
  vfptr->getSupportingVertex(shapeA, (hkVector4f *)&m_quad, &v450.m_checkTriangleDots);
  shapeB->vfptr->getSupportingVertex(shapeB, (hkVector4f *)&m_quad, (hkVector4f *)v475);
  v9 = 1;
  dimA.m_storage = 1;
  dimB.m_storage = 1;
  v506 = aTb;
  v10 = 0i64;
  *(_OWORD *)v449 = 0i64;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v475[0], v475[0], 85), aTb.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v475[0], v475[0], 0), aTb.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v475[0], v475[0], 170), aTb.m_rotation.m_col2.m_quad)),
          aTb.m_translation.m_quad);
  v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, v475[0]), 196);
  v451 = v12;
  v452 = _mm_shuffle_ps(v452, _mm_unpackhi_ps(v452, v475[1]), 196);
  v453 = _mm_shuffle_ps(v453, _mm_unpackhi_ps(v453, v475[2]), 196);
  v512 = FLOAT_0_0000099999997;
  v473 = *(__m128 *)_xmm;
  v13 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v474 = (__m128)_xmm;
LABEL_2:
  v14 = *(__m128 *)&v449[8];
  v458 = v466;
  v15 = 3i64;
  v16 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
  v470 = _mm_mul_ps(v13, _mm_shuffle_ps((__m128)v466, (__m128)v466, 0));
  v17 = *(__m128 *)&v449[24];
  *(hkVector4f *)&v449[16] = (hkVector4f)query.m_quad;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0u:
        goto LABEL_124;
      case 1u:
        goto LABEL_105;
      case 2u:
        goto LABEL_97;
      case 3u:
        v289 = *(__m128 *)&v449[16];
        v290 = v14;
        v291 = &v451;
        goto LABEL_74;
      case 8u:
        goto LABEL_114;
      case 9u:
        goto LABEL_37;
      case 0xAu:
        v18 = (__m128 *)&v449[8];
        v19 = &v451;
        goto LABEL_6;
      case 0x10u:
        goto LABEL_89;
      case 0x11u:
        v18 = &v451;
        v19 = (__m128 *)&v449[8];
LABEL_6:
        if ( m_storage == 2 )
        {
          v20 = *v19;
          v21 = v19[2];
          v22 = _mm_sub_ps(v19[1], v21);
          v23 = *v18;
          v24 = v18[1];
          v455 = _mm_sub_ps(*v19, v21);
          v462 = v22;
          v25 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v455, v455, 201), v22),
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v455));
          v26 = _mm_shuffle_ps(v25, v25, 201);
          v27 = _mm_mul_ps(_mm_sub_ps(v24, v20), v26);
          v28 = _mm_mul_ps(_mm_sub_ps(v23, v20), v26);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v30 = _mm_mul_ps(v29, v29);
          v31 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170));
          v32 = _mm_mul_ps(v31, v31);
          if ( _mm_movemask_ps(_mm_mul_ps(v31, v29)) )
          {
            v497 = _mm_sub_ps(v29, v31);
            v33 = _mm_rcp_ps(v497);
            v502 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v497, v33)), v33), v29);
            v34 = v19[1];
            v35 = _mm_add_ps(*v18, _mm_mul_ps(_mm_sub_ps(v18[1], *v18), v502));
            v36 = _mm_sub_ps(v19[2], *v19);
            v37 = _mm_sub_ps(v34, v35);
            v38 = _mm_sub_ps(v19[2], v35);
            v39 = _mm_sub_ps(v34, *v19);
            v40 = _mm_sub_ps(*v19, v35);
            v41 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v39),
                    _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v36));
            v42 = _mm_shuffle_ps(v41, v41, 201);
            v43 = _mm_shuffle_ps(v42, v42, 210);
            v44 = _mm_shuffle_ps(v42, v42, 201);
            v45 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v43),
                      _mm_mul_ps(_mm_shuffle_ps(v38, v38, 210), v44)),
                    v37);
            v46 = _mm_shuffle_ps(v37, v37, 210);
            v47 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v43),
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 210), v44)),
                    v38);
            v48 = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v43);
            v49 = v45;
            v50 = _mm_unpackhi_ps(v45, v47);
            v51 = _mm_unpacklo_ps(v49, v47);
            v52 = _mm_mul_ps(_mm_sub_ps(v48, _mm_mul_ps(v46, v44)), v40);
            v53 = _mm_movelh_ps(v51, v52);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      v7,
                      _mm_add_ps(
                        _mm_shuffle_ps(v50, v52, 228),
                        _mm_add_ps(v53, _mm_shuffle_ps(_mm_movehl_ps(v53, v51), v52, 212))))) & 7) == 7 )
            {
              v54 = 1;
              goto LABEL_33;
            }
            goto LABEL_16;
          }
          v55 = v19[2];
          v56 = v19[1];
          v57 = _mm_cmplt_ps(v30, v32);
          v58 = _mm_sub_ps(v55, v56);
          v59 = _mm_sub_ps(v56, v20);
          v60 = _mm_or_ps(_mm_and_ps(v57, v23), _mm_andnot_ps(v57, v24));
          v61 = _mm_shuffle_ps(v58, v58, 201);
          v62 = _mm_sub_ps(v20, v55);
          v63 = _mm_sub_ps(v60, v56);
          v64 = _mm_sub_ps(v60, v55);
          v65 = _mm_sub_ps(v60, v20);
          v66 = _mm_shuffle_ps(v62, v62, 201);
          v67 = _mm_mul_ps(v66, v64);
          v68 = _mm_sub_ps(_mm_mul_ps(v66, v58), _mm_mul_ps(v61, v62));
          v10 = _mm_shuffle_ps(v68, v68, 201);
          *(__m128 *)v449 = v10;
          v69 = _mm_sub_ps(_mm_mul_ps(v61, v63), _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v58));
          v70 = _mm_sub_ps(v67, _mm_mul_ps(_mm_shuffle_ps(v64, v64, 201), v62));
          v71 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v10);
          v72 = _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v10);
          v73 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v65),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v59));
          v74 = _mm_unpacklo_ps(v71, v72);
          v75 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v10);
          v76 = _mm_movelh_ps(v74, v75);
          v77 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v71, v72), v75, 228),
                  _mm_add_ps(v76, _mm_shuffle_ps(_mm_movehl_ps(v76, v74), v75, 212)));
          v78 = _mm_movemask_ps(_mm_cmplt_ps(v77, v7)) & 7;
          if ( v78 == 7 )
          {
            v79 = _mm_mul_ps(_mm_sub_ps(v14, v12), v10);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                     _mm_shuffle_ps(v79, v79, 170))) )
            {
              v10 = _mm_xor_ps(v10, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              *(__m128 *)v449 = v10;
              v80 = *v19;
              *v19 = v19[1];
              v19[1] = v80;
              *(hkVector4f *)&v449[16] = (hkVector4f)query.m_quad;
              v77 = _mm_shuffle_ps(v77, v77, 225);
            }
          }
          *(__m128 *)&v449[32] = v77;
          if ( v78 != 7 )
          {
            v22 = v462;
LABEL_16:
            v81 = _mm_sub_ps(v19[2], *v18);
            v82 = _mm_sub_ps(v18[1], *v18);
            v83 = _mm_mul_ps(v82, v22);
            v84 = _mm_mul_ps(v82, v82);
            v85 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                    _mm_shuffle_ps(v83, v83, 170));
            v86 = _mm_mul_ps(v81, v82);
            v87 = _mm_mul_ps(v81, v22);
            v88 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
                    _mm_shuffle_ps(v86, v86, 170));
            v89 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                    _mm_shuffle_ps(v87, v87, 170));
            v90 = _mm_mul_ps(v462, v462);
            v504 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                     _mm_shuffle_ps(v84, v84, 170));
            v508 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                     _mm_shuffle_ps(v90, v90, 170));
            v91 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v508, v504), _mm_mul_ps(v85, v85)), *(__m128 *)&epsilon);
            v92 = _mm_rcp_ps(v91);
            v510 = v91;
            v93 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v92, v91)), v92);
            v94 = _mm_rcp_ps(v508);
            v479 = v93;
            v95 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v94, v508)), v94);
            v96 = _mm_rcp_ps(v504);
            v495 = v95;
            v481 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v96, v504)), v96);
            v97 = _mm_sub_ps(_mm_mul_ps(v508, v88), _mm_mul_ps(v89, v85));
            v98 = _mm_cmplt_ps(v97, v91);
            v99 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v98, v91), _mm_and_ps(v98, v97))), v93);
            v100 = _mm_cmple_ps(v91, *(__m128 *)&epsilon);
            v101 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(_mm_andnot_ps(v100, v99), _mm_and_ps(v100, *(__m128 *)&v449[16])),
                       _mm_mul_ps(v85, v95)),
                     _mm_mul_ps(v89, v95));
            v102 = _mm_cmplt_ps(v101, *(__m128 *)&v449[16]);
            v103 = _mm_max_ps(
                     (__m128)0i64,
                     _mm_or_ps(_mm_andnot_ps(v102, *(__m128 *)&v449[16]), _mm_and_ps(v102, v101)));
            v104 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v85, v481), v103), _mm_mul_ps(v88, v481));
            v105 = _mm_cmplt_ps(v104, *(__m128 *)&v449[16]);
            v106 = v19[2];
            v107 = _mm_sub_ps(v106, *v18);
            v108 = _mm_sub_ps(
                     _mm_add_ps(
                       *v18,
                       _mm_mul_ps(
                         _mm_max_ps(
                           (__m128)0i64,
                           _mm_or_ps(_mm_andnot_ps(v105, *(__m128 *)&v449[16]), _mm_and_ps(v105, v104))),
                         v82)),
                     _mm_add_ps(v106, _mm_mul_ps(v103, v462)));
            v109 = _mm_mul_ps(v108, v108);
            v110 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                     _mm_shuffle_ps(v109, v109, 170));
            v111 = _mm_mul_ps(v82, v455);
            v112 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                     _mm_shuffle_ps(v111, v111, 170));
            v113 = _mm_mul_ps(v107, v82);
            v114 = _mm_mul_ps(v107, v455);
            v115 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                     _mm_shuffle_ps(v113, v113, 170));
            v116 = _mm_mul_ps(v455, v455);
            v117 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                     _mm_shuffle_ps(v114, v114, 170));
            v483 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                     _mm_shuffle_ps(v116, v116, 170));
            v503 = v504;
            v118 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v483, v504), _mm_mul_ps(v112, v112)), *(__m128 *)&epsilon);
            v119 = _mm_rcp_ps(v118);
            v477 = v118;
            v120 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v119, v118)), v119);
            v121 = _mm_rcp_ps(v483);
            v485 = v120;
            v122 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v121, v483)), v121);
            v123 = _mm_rcp_ps(v504);
            v507 = v122;
            v124 = _mm_cmple_ps(v118, *(__m128 *)&epsilon);
            v125 = _mm_sub_ps(_mm_mul_ps(v483, v115), _mm_mul_ps(v117, v112));
            v487 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v123, v504)), v123);
            v126 = _mm_cmplt_ps(v125, v118);
            v127 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v124,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v126, v118), _mm_and_ps(v126, v125))),
                             v120)),
                         _mm_and_ps(v124, *(__m128 *)&v449[16])),
                       _mm_mul_ps(v112, v122)),
                     _mm_mul_ps(v117, v122));
            v128 = _mm_cmplt_ps(v127, *(__m128 *)&v449[16]);
            v129 = _mm_andnot_ps(v128, *(__m128 *)&v449[16]);
            v130 = _mm_and_ps(v128, v127);
            v7 = 0i64;
            v131 = v19[2];
            v132 = _mm_max_ps((__m128)0i64, _mm_or_ps(v130, v129));
            v133 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v112, v487), v132), _mm_mul_ps(v115, v487));
            v134 = _mm_cmplt_ps(v133, *(__m128 *)&v449[16]);
            v135 = _mm_sub_ps(
                     _mm_add_ps(
                       *v18,
                       _mm_mul_ps(
                         _mm_max_ps(
                           (__m128)0i64,
                           _mm_or_ps(_mm_and_ps(v134, v133), _mm_andnot_ps(v134, *(__m128 *)&v449[16]))),
                         v82)),
                     _mm_add_ps(v131, _mm_mul_ps(v132, v455)));
            v136 = _mm_mul_ps(v135, v135);
            v137 = _mm_cmplt_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0)),
                       _mm_shuffle_ps(v136, v136, 170)),
                     v110);
            *v19 = _mm_or_ps(_mm_and_ps(v137, *v19), _mm_andnot_ps(v137, v19[1]));
            v19[1] = v131;
            v10 = *(__m128 *)v449;
LABEL_31:
            v54 = 2;
            goto LABEL_32;
          }
          *v18 = v60;
          v54 = 0;
LABEL_32:
          v14 = *(__m128 *)&v449[8];
          v17 = *(__m128 *)&v449[24];
          v12 = v451;
          *(hkVector4f *)&v449[16] = (hkVector4f)query.m_quad;
          goto LABEL_33;
        }
        v138 = *v19;
        v139 = v18[1];
        v140 = *(__m128 *)&v449[32];
        v141 = _mm_mul_ps(_mm_sub_ps(*v18, *v19), v10);
        v142 = _mm_sub_ps(v139, *v19);
        v455 = *v19;
        v143 = _mm_mul_ps(v142, v10);
        v144 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v141, v141, 85), _mm_shuffle_ps(v141, v141, 0)),
                 _mm_shuffle_ps(v141, v141, 170));
        v145 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                 _mm_shuffle_ps(v143, v143, 170));
        if ( (float)(v145.m128_f32[0] * v144.m128_f32[0]) < 0.0 )
        {
          v499 = _mm_sub_ps(v144, v145);
          v146 = _mm_rcp_ps(v499);
          v489 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v499, v146)), v146), v144);
          v147 = *v18;
          v148 = v19[2];
          v149 = v19[1];
          v139 = v18[1];
          v150 = _mm_sub_ps(v139, *v18);
          v151 = _mm_sub_ps(v149, *v19);
          v455 = *v19;
          v138 = v455;
          v152 = _mm_add_ps(v147, _mm_mul_ps(v150, v489));
          v153 = _mm_sub_ps(v148, v455);
          v154 = _mm_sub_ps(v149, v152);
          v155 = _mm_sub_ps(v455, v152);
          v156 = _mm_sub_ps(v148, v152);
          v157 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v151),
                   _mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v153));
          v158 = _mm_shuffle_ps(v157, v157, 201);
          v159 = _mm_shuffle_ps(v158, v158, 210);
          v160 = _mm_shuffle_ps(v158, v158, 201);
          v161 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v156, v156, 201), v159),
                     _mm_mul_ps(_mm_shuffle_ps(v156, v156, 210), v160)),
                   v154);
          v162 = _mm_shuffle_ps(v154, v154, 210);
          v163 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v159),
                     _mm_mul_ps(_mm_shuffle_ps(v155, v155, 210), v160)),
                   v156);
          v164 = _mm_mul_ps(_mm_shuffle_ps(v154, v154, 201), v159);
          v165 = v161;
          v166 = _mm_unpackhi_ps(v161, v163);
          v167 = _mm_unpacklo_ps(v165, v163);
          v168 = _mm_mul_ps(_mm_sub_ps(v164, _mm_mul_ps(v162, v160)), v155);
          v169 = _mm_movelh_ps(v167, v168);
          if ( (_mm_movemask_ps(
                  _mm_cmplt_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_shuffle_ps(v166, v168, 228),
                      _mm_add_ps(v169, _mm_shuffle_ps(_mm_movehl_ps(v169, v167), v168, 212))))) & 7) == 7 )
          {
            v54 = 1;
            v7 = 0i64;
            goto LABEL_33;
          }
        }
        v170 = v19[1];
        v171 = v19[2];
        v172 = _mm_sub_ps(v138, v171);
        v173 = _mm_sub_ps(v170, v138);
        v174 = _mm_sub_ps(v139, v170);
        v175 = _mm_sub_ps(v171, v170);
        v176 = v139;
        v177 = _mm_shuffle_ps(v175, v175, 201);
        v178 = _mm_shuffle_ps(v172, v172, 201);
        v179 = _mm_sub_ps(v139, v455);
        v180 = _mm_sub_ps(v176, v171);
        v181 = _mm_sub_ps(_mm_mul_ps(v178, v175), _mm_mul_ps(v177, v172));
        v182 = _mm_shuffle_ps(v181, v181, 201);
        v183 = _mm_sub_ps(_mm_mul_ps(v177, v174), _mm_mul_ps(_mm_shuffle_ps(v174, v174, 201), v175));
        v184 = _mm_sub_ps(_mm_mul_ps(v178, v180), _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v172));
        v185 = _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v182);
        v186 = _mm_mul_ps(_mm_shuffle_ps(v179, v179, 201), v173);
        v187 = _mm_mul_ps(_mm_shuffle_ps(v173, v173, 201), v179);
        v188 = _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v182);
        v7 = 0i64;
        v189 = _mm_sub_ps(v187, v186);
        v190 = _mm_unpacklo_ps(v185, v188);
        v191 = _mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v182);
        v192 = _mm_movelh_ps(v190, v191);
        v193 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v185, v188), v191, 228),
                 _mm_add_ps(v192, _mm_shuffle_ps(_mm_movehl_ps(v192, v190), v191, 212)));
        *(__m128 *)&v449[32] = v193;
        v194 = _mm_movemask_ps(_mm_cmplt_ps(v193, (__m128)0i64)) & 7;
        switch ( v194 )
        {
          case 7:
            v54 = 0;
            *v18 = v18[1];
            goto LABEL_32;
          case 6:
            goto LABEL_30;
          case 5:
            goto LABEL_47;
          case 3:
            goto LABEL_48;
          case 1:
            v195 = _mm_shuffle_ps(v140, v140, 85).m128_f32[0];
            v196 = _mm_shuffle_ps(v140, v140, 170).m128_f32[0];
            if ( (float)((float)(_mm_shuffle_ps(v193, v193, 85).m128_f32[0] - v195) * v196) > (float)((float)(_mm_shuffle_ps(v193, v193, 170).m128_f32[0] - v196) * v195) )
              goto LABEL_48;
            goto LABEL_47;
        }
        if ( v194 != 2 )
        {
          if ( v194 != 4
            || (v251 = _mm_shuffle_ps(v140, v140, 0).m128_f32[0],
                v252 = _mm_shuffle_ps(v140, v140, 85).m128_f32[0],
                (float)((float)(_mm_shuffle_ps(v193, v193, 0).m128_f32[0] - v251) * v252) <= (float)((float)(_mm_shuffle_ps(v193, v193, 85).m128_f32[0] - v252) * v251)) )
          {
LABEL_30:
            *v19 = v19[2];
            goto LABEL_31;
          }
LABEL_47:
          v19[1] = v19[2];
          v12 = v451;
          v17 = *(__m128 *)&v449[24];
          v14 = *(__m128 *)&v449[8];
          *(hkVector4f *)&v449[16] = (hkVector4f)query.m_quad;
          goto LABEL_48;
        }
        v197 = _mm_shuffle_ps(v140, v140, 170).m128_f32[0];
        v198 = _mm_shuffle_ps(v140, v140, 0).m128_f32[0];
        if ( (float)((float)(_mm_shuffle_ps(v193, v193, 170).m128_f32[0] - v197) * v198) > (float)((float)(_mm_shuffle_ps(v193, v193, 0).m128_f32[0] - v198)
                                                                                                 * v197) )
          goto LABEL_30;
LABEL_48:
        v54 = 2;
LABEL_33:
        if ( v54 )
        {
          v199 = v54 - 1;
          if ( !v199 )
            goto LABEL_58;
          if ( v199 != 1 )
            goto LABEL_128;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_37:
          v200 = _mm_sub_ps(v17, v14);
          v201 = _mm_sub_ps(v14, v12);
          v202 = _mm_sub_ps(v452, v12);
          v203 = _mm_shuffle_ps(v200, v200, 201);
          v455 = v200;
          v462 = v201;
          v204 = _mm_shuffle_ps(v202, v202, 201);
          v205 = _mm_sub_ps(_mm_mul_ps(v204, v200), _mm_mul_ps(v203, v202));
          v10 = _mm_shuffle_ps(v205, v205, 201);
          *(__m128 *)v449 = v10;
          v206 = _mm_shuffle_ps(v10, v10, 201);
          v207 = _mm_sub_ps(_mm_mul_ps(v204, v10), _mm_mul_ps(v206, v202));
          v208 = _mm_sub_ps(_mm_mul_ps(v203, v10), _mm_mul_ps(v206, v200));
          v209 = _mm_shuffle_ps(v207, v207, 201);
          v210 = _mm_mul_ps(_mm_sub_ps(v12, v17), v209);
          v211 = _mm_mul_ps(v201, v209);
          v212 = _mm_shuffle_ps(v208, v208, 201);
          v213 = _mm_shuffle_ps(v211, v210, 238);
          v214 = _mm_shuffle_ps(v211, v210, 68);
          v215 = _mm_mul_ps(_mm_sub_ps(v452, v14), v212);
          v216 = _mm_mul_ps(v201, v212);
          v217 = _mm_shuffle_ps(v216, v215, 238);
          v218 = _mm_shuffle_ps(v216, v215, 68);
          v219 = _mm_add_ps(
                   _mm_shuffle_ps(v213, v217, 136),
                   _mm_add_ps(_mm_shuffle_ps(v214, v218, 221), _mm_shuffle_ps(v214, v218, 136)));
          v220 = _mm_movemask_ps(_mm_cmplt_ps(v7, v219));
          if ( v220 == 15 )
          {
            v285 = _mm_mul_ps(v201, v10);
            v286 = _mm_shuffle_ps(v219, v219, 0);
            v287 = _mm_add_ps(_mm_shuffle_ps(v219, v219, 85), v286);
            v288 = _mm_rcp_ps(v287);
            v480 = v287;
            v482 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v288, v287)), v288), v286);
            v284 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_shuffle_ps(v285, v285, 170),
                                            _mm_add_ps(_mm_shuffle_ps(v285, v285, 85), _mm_shuffle_ps(v285, v285, 0))),
                                 0x1Fu),
                               0x1Fu),
                     v10);
            v454 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v14), v482), v14);
            goto LABEL_127;
          }
          v221 = v220 - 7;
          if ( !v221 )
          {
            v12 = v452;
            v451 = v452;
LABEL_70:
            dimB.m_storage = 1;
LABEL_114:
            v413 = _mm_sub_ps(v17, v14);
            v414 = _mm_sub_ps(v17, v12);
            v415 = _mm_sub_ps(v14, v12);
            v416 = _mm_mul_ps(v414, v413);
            v417 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v416, v416, 85), _mm_shuffle_ps(v416, v416, 0)),
                     _mm_shuffle_ps(v416, v416, 170));
            v418 = _mm_mul_ps(v415, v413);
            v419 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v418, v418, 85), _mm_shuffle_ps(v418, v418, 0)),
                     _mm_shuffle_ps(v418, v418, 170));
            if ( (float)(v419.m128_f32[0] * v417.m128_f32[0]) >= v7.m128_f32[0] )
            {
              v426 = _mm_cmple_ps(v417, v7);
              dimA.m_storage = 1;
              v14 = _mm_or_ps(_mm_and_ps(v426, v17), _mm_andnot_ps(v426, v14));
              *(__m128 *)&v449[8] = v14;
              v284 = _mm_sub_ps(v14, v12);
            }
            else
            {
              dimA.m_storage = 2;
              v420 = _mm_sub_ps(_mm_mul_ps(v415, v417), _mm_mul_ps(v414, v419));
              v421 = _mm_mul_ps(v413, v413);
              v422 = _mm_shuffle_ps(v413, v413, 201);
              v423 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v420, v420, 201), v413), _mm_mul_ps(v422, v420));
              v490 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v421, v421, 85), _mm_shuffle_ps(v421, v421, 0)),
                       _mm_shuffle_ps(v421, v421, 170));
              v424 = _mm_shuffle_ps(v423, v423, 201);
              v492 = _mm_rcp_ps(v490);
              v425 = _mm_sub_ps(_mm_mul_ps(v422, v424), _mm_mul_ps(_mm_shuffle_ps(v424, v424, 201), v413));
              v284 = _mm_mul_ps(_mm_shuffle_ps(v425, v425, 201), v492);
            }
LABEL_127:
            *(__m128 *)v449 = v284;
LABEL_128:
            v10 = *(__m128 *)v449;
            m_storage = dimB.m_storage;
            v255 = 0;
            goto LABEL_59;
          }
          v222 = v221 - 4;
          if ( !v222 )
            goto LABEL_70;
          v223 = v222 - 2;
          if ( !v223 )
          {
            v14 = v17;
            *(__m128 *)&v449[8] = v17;
LABEL_68:
            dimA.m_storage = 1;
LABEL_105:
            v391 = _mm_sub_ps(v12, v14);
            v392 = _mm_sub_ps(v452, v14);
            v393 = _mm_sub_ps(v452, v12);
            v394 = _mm_mul_ps(v393, v392);
            v395 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v394, v394, 85), _mm_shuffle_ps(v394, v394, 0)),
                     _mm_shuffle_ps(v394, v394, 170));
            v396 = _mm_mul_ps(v391, v393);
            v397 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v396, v396, 85), _mm_shuffle_ps(v396, v396, 0)),
                     _mm_shuffle_ps(v396, v396, 170));
            if ( (float)(v397.m128_f32[0] * v395.m128_f32[0]) >= v7.m128_f32[0] )
            {
              v435 = _mm_cmple_ps(v395, v7);
              v398 = 1;
              v12 = _mm_or_ps(_mm_and_ps(v452, v435), _mm_andnot_ps(v435, v12));
              v284 = _mm_sub_ps(v14, v12);
              v451 = v12;
            }
            else
            {
              v398 = 2;
              v399 = _mm_sub_ps(_mm_mul_ps(v395, v391), _mm_mul_ps(v397, v392));
              v400 = _mm_mul_ps(v393, v393);
              v401 = _mm_shuffle_ps(v393, v393, 201);
              v494 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v400, v400, 85), _mm_shuffle_ps(v400, v400, 0)),
                       _mm_shuffle_ps(v400, v400, 170));
              v496 = _mm_rcp_ps(v494);
              v402 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v399, v399, 201), v393), _mm_mul_ps(v399, v401));
              v403 = _mm_shuffle_ps(v402, v402, 201);
              v404 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v403, v403, 201), v393), _mm_mul_ps(v403, v401));
              v284 = _mm_mul_ps(_mm_shuffle_ps(v404, v404, 201), v496);
            }
            dimB.m_storage = v398;
            goto LABEL_127;
          }
          if ( v223 == 1 )
            goto LABEL_68;
          v224 = _mm_mul_ps(v202, v200);
          v225 = _mm_sub_ps(v12, v14);
          v226 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v224, v224, 85), _mm_shuffle_ps(v224, v224, 0)),
                   _mm_shuffle_ps(v224, v224, 170));
          v227 = _mm_mul_ps(v225, v200);
          v228 = _mm_mul_ps(v225, v202);
          v229 = _mm_mul_ps(v202, v202);
          v230 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v227, v227, 85), _mm_shuffle_ps(v227, v227, 0)),
                   _mm_shuffle_ps(v227, v227, 170));
          v231 = _mm_mul_ps(v455, v455);
          v232 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v228, v228, 85), _mm_shuffle_ps(v228, v228, 0)),
                   _mm_shuffle_ps(v228, v228, 170));
          v505 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                   _mm_shuffle_ps(v231, v231, 170));
          v491 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v229, v229, 85), _mm_shuffle_ps(v229, v229, 0)),
                   _mm_shuffle_ps(v229, v229, 170));
          v233 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v491, v505), _mm_mul_ps(v226, v226)), *(__m128 *)&epsilon);
          v234 = _mm_rcp_ps(v233);
          v501 = v233;
          v235 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v234, v233)), v234);
          v236 = _mm_rcp_ps(v491);
          v493 = v235;
          v237 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v236, v491)), v236);
          v238 = _mm_rcp_ps(v505);
          v509 = v237;
          v239 = _mm_sub_ps(_mm_mul_ps(v491, v230), _mm_mul_ps(v232, v226));
          v478 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v238, v505)), v238);
          v240 = _mm_cmplt_ps(v239, v233);
          v241 = _mm_mul_ps(
                   _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v239, v240), _mm_andnot_ps(v240, v233))),
                   v235);
          v242 = _mm_cmple_ps(v233, *(__m128 *)&epsilon);
          v243 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(_mm_andnot_ps(v242, v241), _mm_and_ps(v242, *(__m128 *)&v449[16])),
                     _mm_mul_ps(v237, v226)),
                   _mm_mul_ps(v237, v232));
          v244 = _mm_cmplt_ps(v243, *(__m128 *)&v449[16]);
          v245 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v243, v244), _mm_andnot_ps(v244, *(__m128 *)&v449[16])));
          v246 = _mm_mul_ps(v478, v226);
          v7 = 0i64;
          v247 = _mm_add_ps(_mm_mul_ps(v246, v245), _mm_mul_ps(v478, v230));
          v248 = _mm_cmplt_ps(v247, *(__m128 *)&v449[16]);
          v249 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v247, v248), _mm_andnot_ps(v248, *(__m128 *)&v449[16])));
          v250 = _mm_movemask_ps(
                   _mm_cmpeq_ps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v249, v249), _mm_unpacklo_ps(v245, v245)),
                     (__m128)xmmword_141A71330));
          v454 = _mm_add_ps(_mm_mul_ps(v249, v455), v14);
          if ( !v250 )
          {
            v283 = _mm_mul_ps(v462, v10);
            v284 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v283, v283, 85), _mm_shuffle_ps(v283, v283, 0)),
                                            _mm_shuffle_ps(v283, v283, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v10);
            goto LABEL_127;
          }
          if ( (v250 & 1) != 0 )
          {
            v14 = v17;
            *(__m128 *)&v449[8] = v17;
            dimA.m_storage = 1;
          }
          else
          {
            v253 = dimA.m_storage;
            if ( (v250 & 2) != 0 )
              v253 = 1;
            dimA.m_storage = v253;
          }
          if ( (v250 & 4) != 0 )
          {
            v12 = v452;
            dimB.m_storage = 1;
            v451 = v452;
          }
          else
          {
            v254 = dimB.m_storage;
            if ( (v250 & 8) != 0 )
              v254 = 1;
            dimB.m_storage = v254;
          }
          v16 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
          if ( v16 > 0x18 )
          {
LABEL_58:
            v255 = 1;
            goto LABEL_59;
          }
          continue;
        }
        v10 = *(__m128 *)v449;
        if ( dimA.m_storage == 2 )
        {
          dimA.m_storage = 1;
          m_storage = dimB.m_storage;
          v255 = 0;
        }
        else
        {
          dimB.m_storage = 1;
          v255 = 0;
          m_storage = 1;
        }
LABEL_59:
        v13 = v470;
        v256 = _mm_mul_ps(v10, v10);
        v257 = _mm_mul_ps(_mm_sub_ps(v14, v12), v10);
        v258 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v256, v256, 85), _mm_shuffle_ps(v256, v256, 0)),
                 _mm_shuffle_ps(v256, v256, 170));
        v259 = _mm_rsqrt_ps(v258);
        v498 = v258;
        v260 = _mm_andnot_ps(
                 _mm_cmple_ps(v258, v7),
                 _mm_mul_ps(_mm_sub_ps(v474, _mm_mul_ps(_mm_mul_ps(v259, v258), v259)), _mm_mul_ps(v259, v473)));
        v10 = _mm_mul_ps(v10, v260);
        *(__m128 *)v449 = v10;
        if ( !v255
          && (float)((float)((float)(_mm_shuffle_ps(v257, v257, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v257, v257, 0).m128_f32[0])
                           + _mm_shuffle_ps(v257, v257, 170).m128_f32[0])
                   * v260.m128_f32[0]) >= v470.m128_f32[0]
          && v258.m128_f32[0] >= (float)((float)(v470.m128_f32[0] * v470.m128_f32[0])
                                       * (float)(v470.m128_f32[0] * v470.m128_f32[0])) )
        {
          v261 = shapeA->vfptr;
          v262 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v467 = _mm_xor_ps(v262, v10);
          v263 = _mm_xor_ps(v467, v262);
          v264 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
          v265 = _mm_movelh_ps(v264, aTb.m_rotation.m_col2.m_quad);
          v471 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v263, v263, 85),
                       _mm_shuffle_ps(_mm_movehl_ps(v265, v264), aTb.m_rotation.m_col2.m_quad, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v263, v263, 0), v265)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                       aTb.m_rotation.m_col2.m_quad,
                       228),
                     _mm_shuffle_ps(v263, v263, 170)));
          v261->getSupportingVertex(shapeA, (hkVector4f *)&v467, (hkVector4f *)&v469);
          shapeB->vfptr->getSupportingVertex(shapeB, (hkVector4f *)&v471, (hkVector4f *)&v472);
          v266 = _mm_add_ps(
                   aTb.m_translation.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v472, v472, 85), aTb.m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v472, v472, 0), aTb.m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v472, v472, 170), aTb.m_rotation.m_col2.m_quad)));
          v267 = _mm_shuffle_ps(v266, _mm_unpackhi_ps(v266, v472), 196);
          v268 = _mm_mul_ps(_mm_sub_ps(v469, *(__m128 *)&v449[8]), v467);
          v269 = _mm_mul_ps(_mm_sub_ps(v267, v451), v10);
          v270 = _mm_mul_ps(_mm_sub_ps(v469, v267), v10);
          v271 = _mm_unpackhi_ps(v270, v268);
          v272 = _mm_unpacklo_ps(v270, v268);
          v273 = _mm_movelh_ps(v272, v269);
          v274 = _mm_add_ps(
                   _mm_shuffle_ps(v271, v269, 228),
                   _mm_add_ps(v273, _mm_shuffle_ps(_mm_movehl_ps(v273, v272), v269, 212)));
          v275 = _mm_mul_ps(_mm_sub_ps(v469, *(__m128 *)&v449[24]), v467);
          v276 = _mm_mul_ps(_mm_sub_ps(v469, *(__m128 *)&v449[40]), v467);
          v277 = _mm_mul_ps(_mm_sub_ps(v267, v452), v10);
          v278 = _mm_shuffle_ps(v275, v276, 238);
          v279 = _mm_shuffle_ps(v275, v276, 68);
          v280 = _mm_mul_ps(_mm_sub_ps(v267, v453), v10);
          v281 = _mm_shuffle_ps(v277, v280, 68);
          v282 = _mm_cmplt_ps(
                   _mm_add_ps(
                     _mm_shuffle_ps(v278, _mm_shuffle_ps(v277, v280, 238), 136),
                     _mm_add_ps(_mm_shuffle_ps(v279, v281, 221), _mm_shuffle_ps(v279, v281, 136))),
                   v13);
          switch ( _mm_movemask_ps(_mm_cmplt_ps(_mm_movelh_ps(_mm_unpacklo_ps(v465, v13), _mm_unpacklo_ps(v13, v13)), v274)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v6 = 5;
              output.m_distance.m_real = _mm_shuffle_ps(v274, v274, 0);
              goto LABEL_146;
            case 2:
              goto LABEL_130;
            case 4:
              goto LABEL_132;
            case 6:
              if ( _mm_shuffle_ps(v274, v274, 170).m128_f32[0] > _mm_shuffle_ps(v274, v274, 85).m128_f32[0] )
              {
LABEL_132:
                if ( (_mm_movemask_ps(v282) & hkcdGskBase::dimToMaskZ[dimB.m_storage]) != 0 )
                {
LABEL_135:
                  v436 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v449[8], v451), v10);
                  output.m_distance.m_real = _mm_add_ps(
                                               _mm_add_ps(_mm_shuffle_ps(v436, v436, 85), _mm_shuffle_ps(v436, v436, 0)),
                                               _mm_shuffle_ps(v436, v436, 170));
                  goto LABEL_146;
                }
                *(&v451 + dimB.m_storage++) = v267;
                v12 = v451;
              }
              else
              {
LABEL_130:
                if ( (_mm_movemask_ps(v282) & hkcdGskBase::dimToMaskY[dimA.m_storage]) != 0 )
                  goto LABEL_135;
                *(__m128 *)&v449[16 * dimA.m_storage++ + 8] = v469;
                v12 = v451;
              }
              break;
            default:
              goto LABEL_135;
          }
          goto LABEL_2;
        }
        if ( v464 )
        {
          Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v438 = Value[1];
          if ( v438 < Value[3] )
          {
            *(_QWORD *)v438 = "TtPenetration";
            v439 = __rdtsc();
            *(_DWORD *)(v438 + 8) = v439;
            Value[1] = v438 + 16;
          }
          v440 = hkcdGskBase::handlePenetration(
                   (hkcdGskBase *)&v449[32],
                   &v459,
                   shapeA,
                   shapeB,
                   &aTb,
                   &dimA,
                   &dimB,
                   &output,
                   &supportOut);
          v441 = (_QWORD *)Value[1];
          v6 = v440;
          if ( (unsigned __int64)v441 < Value[3] )
          {
            *v441 = "Et";
            v442 = __rdtsc();
            v443 = v441 + 2;
            *((_DWORD *)v443 - 2) = v442;
            Value[1] = v443;
          }
        }
        else
        {
          if ( dimB.m_storage + dimA.m_storage > 4 )
          {
            if ( dimA.m_storage > dimB.m_storage )
              v9 = 3;
            dimA.m_storage = v9;
          }
          v6 = 6;
        }
LABEL_146:
        v444 = dimA.m_storage;
        v445 = v451.m128_i8[12];
        v446 = v452.m128_i8[12];
        *((_BYTE *)&v460 + ((LOBYTE(dimA.m_storage) - 2) & 3)) = v453.m128_i8[12];
        *((_BYTE *)&v460 + v444) = v445;
        *((_BYTE *)&v460 + v444 + 1) = v446;
        if ( v6 > 4 )
          return FLOAT_N3_40282e38;
        else
          return output.m_distance.m_real.m128_f32[0];
      case 0x18u:
        v289 = g_vectorfConstants[0];
        v290 = v12;
        v291 = (__m128 *)&v449[8];
LABEL_74:
        v292 = v291[1];
        v293 = v291[2];
        v294 = _mm_sub_ps(v292, *v291);
        v295 = _mm_sub_ps(*v291, v293);
        v296 = _mm_sub_ps(v291[3], *v291);
        v297 = _mm_sub_ps(v293, v292);
        v298 = _mm_sub_ps(v291[3], v292);
        v299 = _mm_sub_ps(v291[3], v293);
        v300 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v298, v298, 201), v297),
                 _mm_mul_ps(_mm_shuffle_ps(v297, v297, 201), v298));
        v301 = _mm_mul_ps(_mm_sub_ps(v290, v291[3]), v289);
        v302 = _mm_shuffle_ps(v300, v300, 201);
        v303 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v299, v299, 201), v295),
                 _mm_mul_ps(_mm_shuffle_ps(v295, v295, 201), v299));
        v304 = _mm_shuffle_ps(v303, v303, 201);
        v305 = _mm_mul_ps(v301, v304);
        v306 = _mm_mul_ps(v304, v304);
        v307 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v296, v296, 201), v294),
                 _mm_mul_ps(_mm_shuffle_ps(v294, v294, 201), v296));
        v308 = _mm_mul_ps(v301, v302);
        v309 = _mm_mul_ps(v302, v302);
        v310 = _mm_shuffle_ps(v307, v307, 201);
        v311 = _mm_unpacklo_ps(v308, v305);
        v312 = _mm_mul_ps(v301, v310);
        v313 = _mm_movelh_ps(v311, v312);
        v314 = _mm_mul_ps(v310, v310);
        v315 = (__m128i)_mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v308, v305), v312, 228),
                          _mm_add_ps(v313, _mm_shuffle_ps(_mm_movehl_ps(v313, v311), v312, 212)));
        v316 = _mm_unpacklo_ps(v309, v306);
        v317 = _mm_movelh_ps(v316, v314);
        v318 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v309, v306), v314, 228),
                 _mm_add_ps(v317, _mm_shuffle_ps(_mm_movehl_ps(v317, v316), v314, 212)));
        v319 = _mm_rcp_ps(v318);
        v484 = v318;
        v486 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v319, v318)), v319);
        v320 = _mm_cmpeq_ps(v7, v318);
        v457 = 897988542;
        v321 = _mm_or_ps(
                 _mm_andnot_ps(
                   v320,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v315, 1u), 1u), (__m128)v315), v486)),
                 _mm_and_ps(v320, (__m128)xmmword_141A712A0));
        v322 = _mm_max_ps(
                 _mm_shuffle_ps(v321, v321, 170),
                 _mm_max_ps(_mm_shuffle_ps(v321, v321, 85), _mm_shuffle_ps(v321, v321, 0)));
        v488 = _mm_and_ps(_mm_cmple_ps(v322, v321), (__m128)xmmword_141A79E80);
        v323 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v488)];
        if ( v322.m128_f32[0] < _mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0).m128_f32[0] )
          goto LABEL_58;
        v456 = 1066192077;
        v324 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v323], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v323], v321));
        if ( v322.m128_f32[0] <= (float)(fmax(
                                           _mm_shuffle_ps(v324, v324, 170).m128_f32[0],
                                           fmax(
                                             _mm_shuffle_ps(v324, v324, 85).m128_f32[0],
                                             _mm_shuffle_ps(v324, v324, 0).m128_f32[0]))
                                       * _mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0).m128_f32[0]) )
        {
          v325 = 2;
          v326 = 1;
          v327 = 4;
          v328 = 16i64;
          v329 = 32i64;
          v330 = _mm_movemask_ps(_mm_cmple_ps(v7, (__m128)v315));
          v331 = 0i64;
          do
          {
            if ( (v326 & v330) != 0 && (v325 & v330) != 0 )
            {
              v332 = *(__m128 *)((char *)v291 + v329);
              v333 = _mm_sub_ps(v291[v331], v332);
              v334 = _mm_sub_ps(v291[3], v332);
              v335 = _mm_sub_ps(v290, v332);
              v336 = _mm_mul_ps(v334, v333);
              v337 = _mm_sub_ps(*(__m128 *)((char *)v291 + v328), v332);
              v338 = _mm_mul_ps(v335, v333);
              v339 = _mm_mul_ps(v334, v337);
              v340 = _mm_mul_ps(v335, v337);
              if ( (float)((float)((float)(_mm_shuffle_ps(v338, v338, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v338, v338, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v338, v338, 170).m128_f32[0])
                         * (float)((float)(_mm_shuffle_ps(v339, v339, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v339, v339, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v339, v339, 170).m128_f32[0])) >= (float)((float)((float)(_mm_shuffle_ps(v336, v336, 85).m128_f32[0] + _mm_shuffle_ps(v336, v336, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v336, v336, 170).m128_f32[0])
                                                                                          * (float)((float)(_mm_shuffle_ps(v340, v340, 85).m128_f32[0] + _mm_shuffle_ps(v340, v340, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v340, v340, 170).m128_f32[0])) )
                v325 = v326;
              v330 &= ~v325;
            }
            v325 = v327;
            v328 = v329;
            v327 = v326;
            v326 = __ROL4__(v326, 1);
            v329 = v331 * 16;
            ++v331;
            --v15;
          }
          while ( v15 );
          if ( (v330 & 7) != 0 )
            v323 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v330];
          else
            v323 = -1;
        }
        if ( v323 < 0 )
          goto LABEL_58;
        v291[v323] = v291[3];
        v12 = v451;
        v14 = *(__m128 *)&v449[8];
        if ( dimA.m_storage == 4 )
        {
          v17 = *(__m128 *)&v449[24];
          dimA.m_storage = 3;
LABEL_89:
          v341 = *(_OWORD *)&v449[40];
          v342 = _mm_sub_ps(v12, v17);
          v343 = _mm_sub_ps(v14, *(__m128 *)&v449[40]);
          v344 = _mm_sub_ps(v12, *(__m128 *)&v449[40]);
          v345 = _mm_sub_ps(*(__m128 *)&v449[40], v17);
          v346 = _mm_sub_ps(v12, v14);
          v347 = _mm_shuffle_ps(v343, v343, 201);
          v348 = _mm_shuffle_ps(v345, v345, 201);
          v349 = _mm_mul_ps(v347, v344);
          v350 = _mm_sub_ps(v17, v14);
          v351 = _mm_sub_ps(_mm_mul_ps(v347, v345), _mm_mul_ps(v348, v343));
          v352 = _mm_shuffle_ps(v351, v351, 201);
          *(__m128 *)v449 = v352;
          v353 = _mm_sub_ps(_mm_mul_ps(v348, v342), _mm_mul_ps(_mm_shuffle_ps(v342, v342, 201), v345));
          v354 = _mm_sub_ps(v349, _mm_mul_ps(_mm_shuffle_ps(v344, v344, 201), v343));
          v355 = _mm_mul_ps(_mm_shuffle_ps(v353, v353, 201), v352);
          v356 = _mm_mul_ps(_mm_shuffle_ps(v354, v354, 201), v352);
          v357 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v350, v350, 201), v346),
                   _mm_mul_ps(_mm_shuffle_ps(v346, v346, 201), v350));
          v358 = _mm_unpacklo_ps(v355, v356);
          v359 = _mm_mul_ps(_mm_shuffle_ps(v357, v357, 201), v352);
          v360 = _mm_movelh_ps(v358, v359);
          v361 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v355, v356), v359, 228),
                   _mm_add_ps(v360, _mm_shuffle_ps(_mm_movehl_ps(v360, v358), v359, 212)));
          v362 = _mm_movemask_ps(_mm_cmplt_ps(v361, v7)) & 7;
          if ( v362 == 7 )
          {
            v363 = _mm_mul_ps(_mm_sub_ps(v14, v12), v352);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v363, v363, 85), _mm_shuffle_ps(v363, v363, 0)),
                     _mm_shuffle_ps(v363, v363, 170))) )
            {
              *(_QWORD *)&v449[16] = v17.m128_u64[1];
              v364 = v14;
              v14 = v17;
              *(__m128 *)&v449[24] = v364;
              *(__m128 *)v449 = _mm_xor_ps(
                                  v352,
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v361 = _mm_shuffle_ps(v361, v361, 225);
            }
          }
          *(__m128 *)&v449[32] = v361;
          if ( v362 == 7 )
            goto LABEL_128;
          v365 = hkcdGskBase::maskToIndex[v362];
          if ( (int)v365 >= 0 )
          {
            v405 = hkcdGskBase::vertexToEdgeLut[v365];
            v406 = v365;
            v407 = hkcdGskBase::vertexToEdgeLut[v365 + 2];
            v408 = *(__m128 *)&v449[16 * v406 + 8];
            v409 = _mm_sub_ps(v12, v408);
            v410 = _mm_sub_ps(*(__m128 *)&v449[16 * v407 + 8], v408);
            v411 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v449[16 * v405 + 8], v408), v409);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v411, v411, 85), _mm_shuffle_ps(v411, v411, 0)),
                     _mm_shuffle_ps(v411, v411, 170))) )
            {
              v412 = _mm_mul_ps(v410, v409);
              *(_OWORD *)&v449[16 * v405 + 8] = v341;
              if ( _mm_movemask_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v412, v412, 85), _mm_shuffle_ps(v412, v412, 0)),
                       _mm_shuffle_ps(v412, v412, 170))) )
              {
                dimA.m_storage = 1;
                if ( (_DWORD)v407 == 2 )
                  LODWORD(v407) = v405;
                *(_OWORD *)&v449[16 * (int)v407 + 8] = *(_OWORD *)&v449[24];
                v14 = *(__m128 *)&v449[8];
                v12 = v451;
                v284 = _mm_sub_ps(*(__m128 *)&v449[8], v451);
                goto LABEL_127;
              }
            }
            else
            {
              *(_OWORD *)&v449[16 * v407 + 8] = v341;
            }
LABEL_113:
            v12 = v451;
            v17 = *(__m128 *)&v449[24];
            v14 = *(__m128 *)&v449[8];
            goto LABEL_114;
          }
          v366 = v365 + 8;
          if ( v366 < 3 )
          {
            *(_OWORD *)&v449[16 * v366 + 8] = v341;
            goto LABEL_113;
          }
LABEL_123:
          dimA.m_storage = 1;
          dimB.m_storage = 1;
LABEL_124:
          v284 = _mm_sub_ps(v14, v12);
          goto LABEL_127;
        }
        dimB.m_storage = 3;
LABEL_97:
        v367 = _mm_sub_ps(v12, v453);
        v368 = _mm_shuffle_ps(v367, v367, 201);
        v369 = _mm_sub_ps(v14, v452);
        v370 = _mm_sub_ps(v453, v452);
        v371 = _mm_sub_ps(v14, v453);
        v372 = _mm_shuffle_ps(v370, v370, 201);
        v373 = _mm_sub_ps(v452, v12);
        v374 = _mm_sub_ps(v14, v12);
        v375 = _mm_sub_ps(_mm_mul_ps(v368, v370), _mm_mul_ps(v372, v367));
        v376 = _mm_shuffle_ps(v375, v375, 201);
        *(__m128 *)v449 = v376;
        v377 = _mm_sub_ps(_mm_mul_ps(v372, v369), _mm_mul_ps(_mm_shuffle_ps(v369, v369, 201), v370));
        v378 = _mm_sub_ps(_mm_mul_ps(v368, v371), _mm_mul_ps(_mm_shuffle_ps(v371, v371, 201), v367));
        v379 = _mm_mul_ps(_mm_shuffle_ps(v377, v377, 201), v376);
        v380 = _mm_mul_ps(_mm_shuffle_ps(v378, v378, 201), v376);
        v381 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v373, v373, 201), v374),
                 _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v373));
        v382 = _mm_unpacklo_ps(v379, v380);
        v383 = _mm_mul_ps(_mm_shuffle_ps(v381, v381, 201), v376);
        v384 = _mm_movelh_ps(v382, v383);
        v385 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v379, v380), v383, 228),
                 _mm_add_ps(v384, _mm_shuffle_ps(_mm_movehl_ps(v384, v382), v383, 212)));
        v386 = _mm_movemask_ps(_mm_cmplt_ps(v385, v7)) & 7;
        if ( v386 == 7 )
        {
          v387 = _mm_mul_ps(v376, v374);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v387, v387, 85), _mm_shuffle_ps(v387, v387, 0)),
                   _mm_shuffle_ps(v387, v387, 170))) )
          {
            v451 = v452;
            v388 = v12;
            v12 = v452;
            v452 = v388;
            *(__m128 *)v449 = _mm_xor_ps(
                                v376,
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
            v385 = _mm_shuffle_ps(v385, v385, 225);
          }
        }
        *(__m128 *)&v449[32] = v385;
        if ( v386 == 7 )
          goto LABEL_128;
        v389 = hkcdGskBase::maskToIndex[v386];
        if ( (int)v389 >= 0 )
        {
          v427 = hkcdGskBase::vertexToEdgeLut[v389];
          v428 = v389;
          v429 = hkcdGskBase::vertexToEdgeLut[v389 + 2];
          v430 = *(&v451 + v428);
          v431 = _mm_sub_ps(v14, v430);
          v432 = _mm_sub_ps(*(&v451 + v429), v430);
          v433 = _mm_mul_ps(_mm_sub_ps(*(&v451 + v427), v430), v431);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v433, v433, 85), _mm_shuffle_ps(v433, v433, 0)),
                   _mm_shuffle_ps(v433, v433, 170))) )
          {
            v434 = _mm_mul_ps(v432, v431);
            *(&v451 + v427) = v453;
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v434, v434, 85), _mm_shuffle_ps(v434, v434, 0)),
                     _mm_shuffle_ps(v434, v434, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v429 == 2 )
                LODWORD(v429) = v427;
              *(&v451 + (int)v429) = v452;
              v14 = *(__m128 *)&v449[8];
              v12 = v451;
              v284 = _mm_sub_ps(*(__m128 *)&v449[8], v451);
              goto LABEL_127;
            }
          }
          else
          {
            *(&v451 + v429) = v453;
          }
        }
        else
        {
          v390 = v389 + 8;
          if ( v390 >= 3 )
            goto LABEL_123;
          *(&v451 + v390) = v453;
        }
        v12 = v451;
        v14 = *(__m128 *)&v449[8];
        goto LABEL_105;
      default:
        goto LABEL_58;
    }
  }
}v449[8];
        goto LABEL_105;
      default:
        goto LABEL_58;
    }
  }
}

// File Line: 441
// RVA: 0xCD8890
bool __fastcall IConvexOverlapImpl::checkOverlap(
        IConvexOverlapImpl *this,
        hkgpMesh::IConvexOverlap::IConvexShape *shapeA,
        hkgpMesh::IConvexOverlap::IConvexShape *shapeB,
        float minDist)
{
  _BOOL8 v4; // r9

  LOBYTE(v4) = 1;
  return minDist >= this->vfptr->distance(this, shapeA, shapeB, v4);
}

// File Line: 446
// RVA: 0x15C95E0
__int64 dynamic_initializer_for__gIConvexOverlapImpl__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gIConvexOverlapImpl__);
}

// File Line: 450
// RVA: 0xCC5BD0
__int64 __fastcall hkgpMesh::Location::Region::hasCommonSuperset(
        hkgpMesh::Location::Region *const *regions,
        int numRegions)
{
  __int64 v3; // r14
  hkLifoAllocator *Value; // rax
  _QWORD *m_cur; // rdi
  char *v6; // rdx
  int v7; // r8d
  hkgpMesh::Location::Region *const *v8; // rbx
  __int64 v9; // rsi
  unsigned __int64 v10; // r9
  unsigned int v11; // edx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rdi
  __int64 v14; // r11
  int v15; // edx
  __int64 v16; // rax
  unsigned int v17; // esi
  signed int v18; // ebx
  hkLifoAllocator *v19; // rax
  int v20; // r8d
  hkgpMeshBase::Edge m_feature; // [rsp+20h] [rbp-50h]
  hkgpMeshBase::Edge v23; // [rsp+30h] [rbp-40h]
  _QWORD *array; // [rsp+40h] [rbp-30h] BYREF
  int v25; // [rsp+48h] [rbp-28h]
  int v26; // [rsp+4Ch] [rbp-24h]
  _QWORD *v27; // [rsp+50h] [rbp-20h]
  int v28; // [rsp+58h] [rbp-18h]

  v3 = numRegions;
  v26 = 0x80000000;
  v28 = 64;
  array = 0i64;
  v25 = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = Value->m_cur;
  v6 = (char *)(m_cur + 64);
  if ( Value->m_slabSize < 512 || v6 > Value->m_end )
    m_cur = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v6;
  v7 = v25;
  array = m_cur;
  v26 = -2147483584;
  v27 = m_cur;
  if ( (int)v3 > 0 )
  {
    v8 = regions;
    v9 = (unsigned int)v3;
    while ( 1 )
    {
      m_feature = (*v8)->m_feature;
      if ( **(_DWORD **)v8 == 1 )
      {
        if ( v7 == (v26 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v7 = v25;
        }
        array[v7] = m_feature.m_triangle;
      }
      else
      {
        if ( **(_DWORD **)v8 != 2 )
        {
          if ( **(_DWORD **)v8 == 3 )
          {
            do
            {
              if ( v7 == (v26 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                v7 = v25;
              }
              array[v7] = m_feature.m_triangle;
              v7 = ++v25;
              v10 = m_feature.m_triangle->m_links[(18 >> (2 * LOBYTE(m_feature.m_index))) & 3];
              v11 = v10 & 3;
              v12 = v10 & 0xFFFFFFFFFFFFFFFCui64;
              v23.m_triangle = (hkgpMeshBase::Triangle *)v12;
              v23.m_index = v11;
              m_feature = v23;
            }
            while ( v12
                 && (hkgpMeshBase::Triangle *)(v12 + v11) != (hkgpMeshBase::Triangle *)((char *)(*v8)->m_feature.m_triangle
                                                                                      + (*v8)->m_feature.m_index) );
          }
          goto LABEL_25;
        }
        if ( v7 == (v26 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v7 = v25;
        }
        array[v7] = m_feature.m_triangle;
        v7 = ++v25;
        v13 = m_feature.m_triangle->m_links[m_feature.m_index] & 0xFFFFFFFFFFFFFFFCui64;
        if ( !v13 )
          goto LABEL_25;
        if ( v7 == (v26 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v7 = v25;
        }
        array[v7] = v13;
      }
      v7 = ++v25;
LABEL_25:
      ++v8;
      if ( !--v9 )
      {
        m_cur = v27;
        break;
      }
    }
  }
  v14 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_34:
    v17 = 1;
  }
  else
  {
    while ( 1 )
    {
      v15 = 0;
      v16 = 0i64;
      if ( v7 <= 0 )
        break;
      while ( (hkgpMeshBase::Triangle *)array[v16] != regions[v14]->m_feature.m_triangle )
      {
        ++v16;
        ++v15;
        if ( v16 >= v7 )
          goto LABEL_31;
      }
      if ( v15 == -1 )
        break;
      if ( ++v14 >= v3 )
        goto LABEL_34;
    }
LABEL_31:
    v17 = 0;
  }
  if ( m_cur == array )
    v7 = 0;
  v18 = (8 * v28 + 127) & 0xFFFFFF80;
  v25 = v7;
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (v18 + 15) & 0xFFFFFFF0;
  if ( v18 > v19->m_slabSize || (char *)m_cur + v20 != v19->m_cur || v19->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v19, (char *)m_cur, v20);
  else
    v19->m_cur = m_cur;
  v25 = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v26);
  return v17;
}

// File Line: 484
// RVA: 0xCC5F30
void __fastcall hkgpMesh::hkgpMesh(hkgpMesh *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  _DWORD *v4; // rbx
  int v5; // r8d

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_vertices.m_allocator.m_firstPool = 0i64;
  this->m_vertices.m_used = 0i64;
  this->m_vertices.m_numUsed = 0;
  this->m_triangles.m_allocator.m_firstPool = 0i64;
  this->m_triangles.m_used = 0i64;
  this->m_triangles.m_numUsed = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpMesh::`vftable;
  this->m_randSamples.m_data = 0i64;
  this->m_randSamples.m_size = 0;
  this->m_randSamples.m_capacityAndFlags = 0x80000000;
  this->m_planes.m_data = 0i64;
  this->m_planes.m_size = 0;
  this->m_planes.m_capacityAndFlags = 0x80000000;
  this->m_planeRoots.m_data = 0i64;
  this->m_planeRoots.m_size = 0;
  this->m_planeRoots.m_capacityAndFlags = 0x80000000;
  this->m_convexHull = 0i64;
  this->m_epsMinEdgeSqLength = 1.0e-10;
  this->m_epsMinTwiceTriangleArea = 8.6602538e-11;
  this->m_iconvexoverlap = &gIConvexOverlapImpl;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = 0i64;
    *(_DWORD *)(v3 + 12) = 0x80000000;
    *(_QWORD *)(v3 + 16) = 0i64;
    v5 = *(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 8) = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, v5 << 6);
    *(_QWORD *)v4 = 0i64;
    v4[3] = 0x80000000;
    *((_QWORD *)v4 + 2) = 0i64;
    *((_QWORD *)v4 + 4) = 0i64;
    *((_QWORD *)v4 + 3) = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  this->m_trianglesTree = v4;
  hkgpMesh::reset(this);
}

// File Line: 495
// RVA: 0xCC6060
void __fastcall hkgpMesh::~hkgpMesh(hkgpMesh *this)
{
  void **m_trianglesTree; // rbx
  int v3; // r8d
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d
  int v6; // r8d
  int v7; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkgpMesh::`vftable;
  hkgpMesh::reset(this);
  m_trianglesTree = (void **)this->m_trianglesTree;
  if ( m_trianglesTree )
  {
    v3 = *((_DWORD *)m_trianglesTree + 3);
    *((_DWORD *)m_trianglesTree + 2) = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *m_trianglesTree, v3 << 6);
    *m_trianglesTree = 0i64;
    *((_DWORD *)m_trianglesTree + 3) = 0x80000000;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void **, __int64))(*Value[11] + 16i64))(Value[11], m_trianglesTree, 40i64);
  }
  m_capacityAndFlags = this->m_planeRoots.m_capacityAndFlags;
  this->m_planeRoots.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_planeRoots.m_data,
      8 * m_capacityAndFlags);
  this->m_planeRoots.m_data = 0i64;
  this->m_planeRoots.m_capacityAndFlags = 0x80000000;
  v6 = this->m_planes.m_capacityAndFlags;
  this->m_planes.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_planes.m_data, 16 * v6);
  this->m_planes.m_data = 0i64;
  this->m_planes.m_capacityAndFlags = 0x80000000;
  v7 = this->m_randSamples.m_capacityAndFlags;
  this->m_randSamples.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_randSamples.m_data,
      16 * v7);
  this->m_randSamples.m_data = 0i64;
  this->m_randSamples.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::`vftable;
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset(&this->m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>(&this->m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset(&this->m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>(&this->m_vertices.m_allocator);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 502
// RVA: 0xCC61E0
void __fastcall hkgpMesh::reset(hkgpMesh *this)
{
  _DWORD *m_trianglesTree; // rbx
  int v3; // r8d

  hkgpMesh::invalidateConvexHull(this);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset(&this->m_vertices);
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset(&this->m_triangles);
  m_trianglesTree = this->m_trianglesTree;
  v3 = m_trianglesTree[3];
  m_trianglesTree[2] = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)m_trianglesTree,
      v3 << 6);
  *(_QWORD *)m_trianglesTree = 0i64;
  m_trianglesTree[3] = 0x80000000;
  *((_QWORD *)m_trianglesTree + 2) = 0i64;
  *((_QWORD *)m_trianglesTree + 4) = 0i64;
  *((_QWORD *)m_trianglesTree + 3) = 0i64;
  *(_WORD *)&this->m_hasErrors = 0;
}

// File Line: 514
// RVA: 0xCC6270
char __fastcall hkgpMesh::isClosedManifold(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *m_used; // rdx
  int i; // eax

  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    while ( 2 )
    {
      for ( i = 0; i < 3; ++i )
      {
        if ( (m_used->m_links[i] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          return 0;
      }
      m_used = m_used->m_next;
      if ( m_used )
        continue;
      break;
    }
  }
  return 1;
}

// File Line: 527
// RVA: 0xCC62B0
hkAabb *__fastcall hkgpMesh::getBoundingBox(hkgpMesh *this, hkAabb *result)
{
  hkgpMeshBase::Vertex *m_used; // rax
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm0

  m_used = this->m_vertices.m_used;
  v3.m_quad = (__m128)m_used->m_position;
  result->m_min = (hkVector4f)v3.m_quad;
  result->m_max = (hkVector4f)v3.m_quad;
  if ( m_used )
  {
    do
    {
      v3.m_quad = _mm_max_ps(v3.m_quad, m_used->m_position.m_quad);
      v4.m_quad = _mm_min_ps(result->m_min.m_quad, m_used->m_position.m_quad);
      m_used = m_used->m_next;
      result->m_min = (hkVector4f)v4.m_quad;
    }
    while ( m_used );
    result->m_max = (hkVector4f)v3.m_quad;
  }
  return result;
}

// File Line: 540
// RVA: 0xCC6300
bool __fastcall hkgpMesh::setPlane(
        hkgpMesh *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *p,
        bool check)
{
  bool result; // al
  float v11; // xmm6_4
  __m128 v12; // xmm8
  __m128 v13; // xmm2
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm2

  result = 1;
  LODWORD(v11) = _mm_shuffle_ps(
                   (__m128)LODWORD(this->m_epsMinEdgeSqLength),
                   (__m128)LODWORD(this->m_epsMinEdgeSqLength),
                   0).m128_u32[0];
  v12 = _mm_sub_ps(b->m_quad, a->m_quad);
  if ( check )
  {
    v13 = _mm_mul_ps(v12, v12);
    if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
               + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(this, a, b);
      result = 0;
    }
  }
  v14 = _mm_sub_ps(c->m_quad, a->m_quad);
  if ( check )
  {
    v15 = _mm_mul_ps(v14, v14);
    if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
               + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(this, a, c);
      result = 0;
    }
  }
  v16 = _mm_sub_ps(c->m_quad, b->m_quad);
  if ( check )
  {
    v17 = _mm_mul_ps(v16, v16);
    if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
               + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(this, c, b);
      result = 0;
    }
  }
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v14));
  v19 = _mm_shuffle_ps(v18, v18, 201);
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_shuffle_ps(
          v19,
          _mm_unpackhi_ps(
            v19,
            _mm_andnot_ps(
              _mm_cmple_ps(v21, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                  _mm_mul_ps(*(__m128 *)_xmm, v22)),
                v21))),
          196);
  *p = (hkVector4f)v23;
  if ( check
    && _mm_shuffle_ps(v23, v23, 255).m128_f32[0] < _mm_shuffle_ps(
                                                     (__m128)LODWORD(this->m_epsMinTwiceTriangleArea),
                                                     (__m128)LODWORD(this->m_epsMinTwiceTriangleArea),
                                                     0).m128_f32[0] )
  {
    hkgpMesh::reportBadAreaTriangle(this, a, b, c);
    result = 0;
  }
  v24 = _mm_mul_ps(p->m_quad, _mm_div_ps(query.m_quad, _mm_shuffle_ps(p->m_quad, p->m_quad, 255)));
  *p = (hkVector4f)v24;
  v25 = _mm_mul_ps(a->m_quad, v24);
  p->m_quad = _mm_shuffle_ps(
                v24,
                _mm_unpackhi_ps(
                  v24,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                      _mm_shuffle_ps(v25, v25, 170)))),
                196);
  return result;
}

// File Line: 563
// RVA: 0xCC6530
bool __fastcall hkgpMesh::setPlane(hkgpMesh *this, hkgpMeshBase::Triangle *t, hkVector4f *p, bool check)
{
  return hkgpMesh::setPlane(
           this,
           &t->m_vertices[0]->m_position,
           &t->m_vertices[1]->m_position,
           &t->m_vertices[2]->m_position,
           p,
           check);
}

// File Line: 569
// RVA: 0xCC6570
bool __fastcall hkgpMesh::updatePlane(hkgpMesh *this, hkgpMeshBase::Triangle *triangle)
{
  bool result; // al
  hkVector4f p; // [rsp+30h] [rbp-18h] BYREF

  if ( !hkgpMesh::setPlane(
          this,
          &triangle->m_vertices[0]->m_position,
          &triangle->m_vertices[1]->m_position,
          &triangle->m_vertices[2]->m_position,
          &p,
          1) )
    return 0;
  result = 1;
  triangle->m_plane = (hkVector4f)p.m_quad;
  return result;
}

// File Line: 581
// RVA: 0xCC65D0
__int64 __fastcall hkgpMesh::fetchPositions(hkgpMesh *this, hkArray<hkVector4f,hkContainerHeapAllocator> *positions)
{
  int m_numUsed; // esi
  __int64 m_size; // r14
  int v4; // r9d
  int v5; // eax
  int v8; // eax
  hkgpMeshBase::Vertex *m_used; // rax
  hkVector4f *i; // rdx
  hkVector4f *v11; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_numUsed = this->m_vertices.m_numUsed;
  m_size = positions->m_size;
  v4 = m_size + m_numUsed;
  v5 = positions->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < (int)m_size + m_numUsed )
  {
    v8 = 2 * v5;
    if ( v4 < v8 )
      v4 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&positions->m_data, v4, 16);
  }
  positions->m_size += m_numUsed;
  m_used = this->m_vertices.m_used;
  for ( i = &positions->m_data[m_size]; m_used; m_used = m_used->m_next )
  {
    v11 = i++;
    *v11 = m_used->m_position;
  }
  return (unsigned int)this->m_vertices.m_numUsed;
}

// File Line: 592
// RVA: 0xCC6680
__int64 __fastcall hkgpMesh::floodFillDetachedParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *m_used; // rax
  unsigned int i; // r14d
  hkgpMeshBase::Triangle *m_next; // rsi
  int v4; // ecx
  hkgpMeshBase::Triangle **v5; // rdx
  __int64 v6; // rax
  int v7; // ecx
  hkgpMeshBase::Triangle **v8; // rdx
  __int64 v9; // rax
  int v10; // ecx
  hkgpMeshBase::Triangle **v11; // rdx
  __int64 v12; // rax
  int v13; // r8d
  __int64 v14; // rcx
  __int64 v15; // rbx
  char v16; // cl
  unsigned __int64 v17; // rbx
  char v18; // di
  int v19; // r8d
  unsigned __int64 *v20; // rdx
  __int64 v21; // rax
  int v22; // r8d
  unsigned __int64 *v23; // rax
  __int64 v24; // rcx
  _QWORD *array; // [rsp+10h] [rbp-19h] BYREF
  int v27; // [rsp+18h] [rbp-11h]
  int j; // [rsp+1Ch] [rbp-Dh]
  __int64 v29; // [rsp+28h] [rbp-1h]
  __int64 v30; // [rsp+38h] [rbp+Fh]
  __int64 v31; // [rsp+48h] [rbp+1Fh]
  __int64 v32; // [rsp+58h] [rbp+2Fh]
  __int64 v33; // [rsp+68h] [rbp+3Fh]

  m_used = this->m_triangles.m_used;
  for ( i = 0; m_used; m_used = m_used->m_next )
    m_used->m_partId = -1;
  m_next = this->m_triangles.m_used;
  array = 0i64;
  v27 = 0;
  for ( j = 0x80000000; m_next; m_next = m_next->m_next )
  {
    if ( m_next->m_partId == -1 )
    {
      v4 = 0;
      LODWORD(v29) = 0;
      v27 = 0;
      if ( (j & 0x3FFFFFFF) == 0 )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v4 = v27;
      }
      v5 = (hkgpMeshBase::Triangle **)&array[2 * v4];
      if ( v5 )
      {
        v6 = v29;
        *v5 = m_next;
        v5[1] = (hkgpMeshBase::Triangle *)v6;
        v4 = v27;
      }
      v7 = v4 + 1;
      LODWORD(v30) = 1;
      v27 = v7;
      if ( v7 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v7 = v27;
      }
      v8 = (hkgpMeshBase::Triangle **)&array[2 * v7];
      if ( v8 )
      {
        v9 = v30;
        *v8 = m_next;
        v8[1] = (hkgpMeshBase::Triangle *)v9;
        v7 = v27;
      }
      v10 = v7 + 1;
      LODWORD(v31) = 2;
      v27 = v10;
      if ( v10 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v10 = v27;
      }
      v11 = (hkgpMeshBase::Triangle **)&array[2 * v10];
      if ( v11 )
      {
        v12 = v31;
        *v11 = m_next;
        v11[1] = (hkgpMeshBase::Triangle *)v12;
        v10 = v27;
      }
      v27 = v10 + 1;
      m_next->m_partId = i;
      v13 = v27;
      ++i;
      do
      {
        v14 = v13--;
        v15 = *(_QWORD *)(array[2 * v14 - 2] + 8i64 * SLODWORD(array[2 * v14 - 1]) + 40);
        v27 = v13;
        v16 = v15 & 3;
        v17 = v15 & 0xFFFFFFFFFFFFFFFCui64;
        if ( v17 && *(_DWORD *)(v17 + 80) == -1 )
        {
          v18 = 2 * v16;
          *(_DWORD *)(v17 + 80) = i - 1;
          v19 = v27;
          LODWORD(v32) = (9 >> (2 * v16)) & 3;
          if ( v27 == (j & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v19 = v27;
          }
          v20 = &array[2 * v19];
          if ( v20 )
          {
            v21 = v32;
            *v20 = v17;
            v20[1] = v21;
            v19 = v27;
          }
          v22 = v19 + 1;
          v27 = v22;
          LODWORD(v33) = (18 >> v18) & 3;
          if ( v22 == (j & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v22 = v27;
          }
          v23 = &array[2 * v22];
          if ( v23 )
          {
            v24 = v33;
            *v23 = v17;
            v23[1] = v24;
            v22 = v27;
          }
          v13 = v22 + 1;
          v27 = v13;
        }
      }
      while ( v13 );
    }
  }
  v27 = 0;
  if ( j >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * j);
  return i;
}
  v27 = 0;
  if ( j >= 0 )
    hkCo

// File Line: 599
// RVA: 0xCC6960
__int64 __fastcall hkgpMesh::floodFillDetachedOrMaterialBoundariesParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *m_used; // rax
  unsigned int i; // r14d
  hkgpMeshBase::Triangle *m_next; // rsi
  int v4; // ecx
  hkgpMeshBase::Triangle **v5; // rdx
  __int64 v6; // rax
  int v7; // ecx
  hkgpMeshBase::Triangle **v8; // rdx
  __int64 v9; // rax
  int v10; // ecx
  hkgpMeshBase::Triangle **v11; // rdx
  __int64 v12; // rax
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // rax
  __int64 v17; // rbx
  char v18; // di
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // rax
  char v21; // di
  int v22; // edx
  unsigned __int64 *v23; // r8
  __int64 v24; // rax
  int v25; // edx
  unsigned __int64 *v26; // rax
  __int64 v27; // rcx
  _QWORD *array; // [rsp+10h] [rbp-19h] BYREF
  int v30; // [rsp+18h] [rbp-11h]
  int j; // [rsp+1Ch] [rbp-Dh]
  __int64 v32; // [rsp+28h] [rbp-1h]
  __int64 v33; // [rsp+38h] [rbp+Fh]
  __int64 v34; // [rsp+48h] [rbp+1Fh]
  __int64 v35; // [rsp+58h] [rbp+2Fh]
  __int64 v36; // [rsp+68h] [rbp+3Fh]

  m_used = this->m_triangles.m_used;
  for ( i = 0; m_used; m_used = m_used->m_next )
    m_used->m_partId = -1;
  m_next = this->m_triangles.m_used;
  array = 0i64;
  v30 = 0;
  for ( j = 0x80000000; m_next; m_next = m_next->m_next )
  {
    if ( m_next->m_partId == -1 )
    {
      v4 = 0;
      LODWORD(v32) = 0;
      v30 = 0;
      if ( (j & 0x3FFFFFFF) == 0 )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v4 = v30;
      }
      v5 = (hkgpMeshBase::Triangle **)&array[2 * v4];
      if ( v5 )
      {
        v6 = v32;
        *v5 = m_next;
        v5[1] = (hkgpMeshBase::Triangle *)v6;
        v4 = v30;
      }
      v7 = v4 + 1;
      LODWORD(v33) = 1;
      v30 = v7;
      if ( v7 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v7 = v30;
      }
      v8 = (hkgpMeshBase::Triangle **)&array[2 * v7];
      if ( v8 )
      {
        v9 = v33;
        *v8 = m_next;
        v8[1] = (hkgpMeshBase::Triangle *)v9;
        v7 = v30;
      }
      v10 = v7 + 1;
      LODWORD(v34) = 2;
      v30 = v10;
      if ( v10 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v10 = v30;
      }
      v11 = (hkgpMeshBase::Triangle **)&array[2 * v10];
      if ( v11 )
      {
        v12 = v34;
        *v11 = m_next;
        v11[1] = (hkgpMeshBase::Triangle *)v12;
        v10 = v30;
      }
      v30 = v10 + 1;
      m_next->m_partId = i;
      v13 = v30;
      ++i;
      do
      {
        v14 = v13--;
        v14 *= 2i64;
        v15 = array[v14 - 2];
        v16 = SLODWORD(array[v14 - 1]);
        v17 = *(_QWORD *)(v15 + 8 * v16 + 40);
        v30 = v13;
        v18 = v17 & 3;
        v19 = v17 & 0xFFFFFFFFFFFFFFFCui64;
        if ( v19 )
        {
          if ( *(_DWORD *)(v19 + 80) == -1 )
          {
            v20 = *(_QWORD *)(v15 + 8 * v16 + 40) & 0xFFFFFFFFFFFFFFFCui64;
            if ( !v20 || *(_DWORD *)(v15 + 88) == *(_DWORD *)(v20 + 88) )
            {
              v21 = 2 * v18;
              *(_DWORD *)(v19 + 80) = i - 1;
              v22 = v30;
              LODWORD(v35) = (9 >> v21) & 3;
              if ( v30 == (j & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v22 = v30;
              }
              v23 = &array[2 * v22];
              if ( v23 )
              {
                v24 = v35;
                *v23 = v19;
                v23[1] = v24;
                v22 = v30;
              }
              v25 = v22 + 1;
              v30 = v25;
              LODWORD(v36) = (18 >> v21) & 3;
              if ( v25 == (j & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v25 = v30;
              }
              v26 = &array[2 * v25];
              if ( v26 )
              {
                v27 = v36;
                *v26 = v19;
                v26[1] = v27;
                v25 = v30;
              }
              v13 = v25 + 1;
              v30 = v13;
            }
          }
        }
      }
      while ( v13 );
    }
  }
  v30 = 0;
  if ( j >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * j);
  return i;
}

// File Line: 606
// RVA: 0xCC6C50
__int64 __fastcall hkgpMesh::countParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *m_used; // rdx
  int i; // eax

  m_used = this->m_triangles.m_used;
  for ( i = -1; m_used; m_used = m_used->m_next )
  {
    if ( m_used->m_partId > i )
      i = m_used->m_partId;
  }
  return (unsigned int)(i + 1);
}

// File Line: 617
// RVA: 0xCC6C80
__int64 __fastcall hkgpMesh::explodeParts(
        hkgpMesh *this,
        hkArray<hkgpMesh *,hkContainerHeapAllocator> *sets,
        bool doSimplify,
        bool doConvexHulls,
        bool sort,
        hkgpMesh::eHollows hollowPolicy)
{
  hkgpMesh *v7; // rsi
  __int64 v8; // rax
  __int64 v9; // r12
  __int64 m_size; // rbx
  int v11; // r9d
  int v12; // eax
  __int64 v13; // rdi
  int v14; // eax
  hkgpMesh **m_data; // rax
  hkgpMesh **v16; // r15
  int v17; // r8d
  __int64 v18; // rbx
  __int64 v19; // r13
  _QWORD **Value; // rax
  __int64 v21; // rax
  __int64 v22; // rcx
  hkgpMeshBase::Triangle *m_used; // r14
  __int64 m_partId; // rax
  unsigned __int64 v25; // rbx
  _QWORD **v26; // rax
  hkgpMesh *v27; // rax
  hkgpMesh *v28; // rax
  hkgpMesh *v29; // rcx
  hkgpMesh *v30; // rcx
  __int64 v31; // r12
  hkgpMeshBase::Triangle *v32; // r13
  hkgpMeshBase::Vertex **m_vertices; // rbx
  hkgpMeshBase::Triangle *v34; // rax
  unsigned __int64 v35; // r14
  unsigned __int64 v36; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v37; // r13
  hkgpMeshBase::Vertex *v38; // r15
  hkgpMeshBase::Vertex *v39; // rsi
  __int64 v40; // r13
  int v41; // ebx
  unsigned __int64 *v42; // rsi
  unsigned __int64 v43; // rcx
  unsigned __int64 v44; // r15
  unsigned __int64 v45; // rax
  unsigned int v46; // r9d
  unsigned __int64 v47; // rax
  __int64 i; // rbx
  AMD_HD3D *v49; // rsi
  _QWORD **v50; // rax
  __int64 j; // rbx
  __int64 v52; // rsi
  hkgpMesh *v53; // r15
  __int64 v54; // r12
  hkgpMesh **v55; // rax
  hkgpMesh *v56; // r14
  char v57; // r13
  TrianglePairCollector *v58; // r9
  hkVector4f *k; // rbx
  hkgpMeshBase::Triangle *v60; // rax
  hkVector4f *m; // rbx
  hkgpMeshBase::Triangle *v62; // rax
  hkgpMeshBase::Triangle *m_next; // rbx
  __m128 *v64; // rax
  __m128 *v65; // rcx
  __m128 v66; // xmm1
  __m128 *v67; // rax
  hkgpMeshBase::Triangle *v68; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *m_trianglesTree; // rdx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v70; // rcx
  int v71; // ebx
  __int64 v72; // rsi
  _QWORD *v73; // rcx
  _QWORD *v74; // rdx
  hkSimdFloat32 *ConvexHullVolume; // rbx
  hkgpMesh *v76; // rcx
  hkgpMesh *v77; // rcx
  int v78; // [rsp+30h] [rbp-D0h]
  hkgpMesh **v79; // [rsp+38h] [rbp-C8h]
  _QWORD *array; // [rsp+40h] [rbp-C0h] BYREF
  int v81; // [rsp+48h] [rbp-B8h]
  int v82; // [rsp+4Ch] [rbp-B4h]
  hkResult v83[2]; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v84; // [rsp+58h] [rbp-A8h]
  char treeB[48]; // [rsp+60h] [rbp-A0h] BYREF
  hkgpMeshBase::Triangle *v86; // [rsp+90h] [rbp-70h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v87; // [rsp+98h] [rbp-68h]
  hkgpMesh::Location location; // [rsp+A0h] [rbp-60h] BYREF
  hkSimdFloat32 v89; // [rsp+120h] [rbp+20h] BYREF
  hkSimdFloat32 result; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f triangleA[3]; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f triangleB[3]; // [rsp+170h] [rbp+70h] BYREF

  v7 = this;
  v8 = hkgpMesh::countParts(this);
  v9 = (int)v8;
  v78 = v8;
  if ( !(_DWORD)v8 )
    return v8;
  m_size = sets->m_size;
  v11 = m_size + v8;
  v12 = sets->m_capacityAndFlags & 0x3FFFFFFF;
  v13 = 0i64;
  if ( v12 >= (int)m_size + (int)v9 )
  {
    *(_DWORD *)&treeB[8] = 0;
  }
  else
  {
    v14 = 2 * v12;
    if ( v11 < v14 )
      v11 = v14;
    hkArrayUtil::_reserve(
      (hkResult *)&treeB[8],
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&sets->m_data,
      v11,
      8);
  }
  m_data = sets->m_data;
  sets->m_size += v9;
  v16 = &m_data[m_size];
  v17 = 3 * v7->m_triangles.m_numUsed;
  v79 = v16;
  array = 0i64;
  v81 = 0;
  v82 = 0x80000000;
  *(_QWORD *)&treeB[16] = 0i64;
  *(_DWORD *)&treeB[24] = 0;
  *(_DWORD *)&treeB[28] = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB[16],
    &hkContainerHeapAllocator::s_alloc,
    v17);
  if ( (int)v9 > 0 )
    hkArrayUtil::_reserve(v83, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v9, 8);
  v81 = v9;
  v18 = 0i64;
  v19 = v9;
  v84 = v9;
  if ( (int)v9 > 0 )
  {
    do
    {
      v16[v18] = 0i64;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v21 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
      v22 = v21;
      if ( v21 )
      {
        *(_QWORD *)v21 = 0i64;
        *(_DWORD *)(v21 + 8) = 0;
        *(_DWORD *)(v21 + 12) = -1;
      }
      else
      {
        v22 = 0i64;
      }
      array[v18++] = v22;
    }
    while ( v18 < v9 );
  }
  m_used = v7->m_triangles.m_used;
  v86 = m_used;
  if ( m_used )
  {
    do
    {
      m_partId = m_used->m_partId;
      if ( (_DWORD)m_partId != -1 )
      {
        v25 = m_used->m_partId;
        v89.m_real.m128_u64[0] = v25;
        if ( !v16[m_partId] )
        {
          v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v27 = (hkgpMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 152i64);
          if ( v27 )
          {
            hkgpMesh::hkgpMesh(v27);
            v29 = v28;
          }
          else
          {
            v29 = 0i64;
          }
          v16[v25] = v29;
          v29->m_iconvexoverlap = v7->m_iconvexoverlap;
        }
        v30 = v16[v25];
        v87 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)array[m_used->m_partId];
        v31 = 3i64;
        v32 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
                &v30->m_triangles,
                m_used);
        m_vertices = v32->m_vertices;
        *(_QWORD *)treeB = v32;
        v34 = m_used;
        v35 = v89.m_real.m128_u64[0];
        v36 = (char *)v34 - (char *)v32;
        v37 = v87;
        result.m_real.m128_u64[0] = v36;
        do
        {
          v38 = *(hkgpMeshBase::Vertex **)((char *)m_vertices + v36);
          v39 = (hkgpMeshBase::Vertex *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                          v37,
                                          (unsigned __int64)v38,
                                          0i64);
          if ( !v39 )
          {
            v39 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(
                    &v79[v35]->m_vertices,
                    v38);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              v37,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)v38,
              (unsigned __int64)v39);
          }
          v36 = result.m_real.m128_u64[0];
          *m_vertices = v39;
          m_vertices[3] = 0i64;
          ++m_vertices;
          --v31;
        }
        while ( v31 );
        v40 = *(_QWORD *)treeB;
        m_used = v86;
        v41 = 0;
        v42 = (unsigned __int64 *)(*(_QWORD *)treeB + 40i64);
        do
        {
          v43 = m_used->m_links[v41] & 0xFFFFFFFFFFFFFFFCui64;
          if ( v43 && *(_DWORD *)(v43 + 80) == m_used->m_partId )
          {
            v44 = v43 + (m_used->m_links[v41] & 3);
            v45 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB[16],
                    v44,
                    0i64);
            v46 = v45 & 3;
            v47 = v45 & 0xFFFFFFFFFFFFFFFCui64;
            if ( v47 )
            {
              *(_QWORD *)(v40 + 8i64 * v41 + 40) = v47 + v46;
              *(_QWORD *)(v47 + 8i64 * (int)v46 + 40) = v40 + (unsigned int)v41;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB[16],
                v83,
                v44);
            }
            else
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB[16],
                &hkContainerHeapAllocator::s_alloc,
                (unsigned __int64)m_used + (unsigned int)v41,
                (unsigned int)v41 + v40);
              *v42 = v44;
            }
          }
          ++v41;
          ++v42;
        }
        while ( v41 < 3 );
        v7 = this;
        v16 = v79;
      }
      m_used = m_used->m_next;
      v86 = m_used;
    }
    while ( m_used );
    v19 = v84;
    LODWORD(v9) = v84;
  }
  for ( i = 0i64; i < v19; ++i )
  {
    v49 = (AMD_HD3D *)array[i];
    if ( v49 )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)array[i],
        &hkContainerHeapAllocator::s_alloc);
      _(v49);
      v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, AMD_HD3D *, __int64))(*v50[11] + 16i64))(v50[11], v49, 16i64);
    }
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB[16],
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&treeB[16]);
  v81 = 0;
  if ( v82 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v82);
  if ( hollowPolicy == HOLLOW_KEEP )
    goto LABEL_85;
  for ( j = 0i64; j < v19; ++j )
  {
    hkgpMesh::assignVertexNormals(v16[j]);
    hkgpMesh::rebuildTrianglesTree(v16[j], 0.0);
  }
  v52 = 0i64;
  *(_QWORD *)&v83[0].m_enum = 0i64;
  if ( v19 <= 0 )
    goto LABEL_85;
  do
  {
    v53 = v16[v52];
    if ( !hkgpMesh::isClosedManifold(v53) )
      goto LABEL_83;
    v54 = 0i64;
    if ( v19 <= 0 )
    {
LABEL_82:
      LODWORD(v9) = v78;
LABEL_83:
      v16 = v79;
      goto LABEL_84;
    }
    v55 = v79;
    while ( 1 )
    {
      v56 = v55[v54];
      v57 = 1;
      if ( v54 != v52 )
        break;
LABEL_81:
      v19 = v84;
      if ( ++v54 >= v84 )
        goto LABEL_82;
    }
    if ( !hkgpMesh::isClosedManifold(v55[v54]) )
      goto LABEL_80;
    for ( k = (hkVector4f *)v53->m_vertices.m_used; k; k = (hkVector4f *)k->m_quad.m128_u64[0] )
    {
      location.m_region.m_type = NONE;
      if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v60 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
        v60 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      }
      location.m_region.m_feature.m_triangle = v60;
      memset(&location, 0, 48);
      *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                        + 1);
      location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
      location.m_inside.m_real = g_vectorfConstants[0];
      hkgpMesh::locate(v56, k + 2, &location, (hkBool)1);
      if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
        goto LABEL_80;
    }
    for ( m = (hkVector4f *)v56->m_vertices.m_used; m; m = (hkVector4f *)m->m_quad.m128_u64[0] )
    {
      location.m_region.m_type = NONE;
      if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v62 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
        v62 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      }
      location.m_region.m_feature.m_triangle = v62;
      memset(&location, 0, 48);
      *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                        + 1);
      location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
      location.m_inside.m_real = g_vectorfConstants[0];
      hkgpMesh::locate(v53, m + 2, &location, (hkBool)1);
      if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
        goto LABEL_80;
    }
    m_next = v53->m_triangles.m_used;
    if ( m_next )
    {
      while ( 1 )
      {
        v64 = (__m128 *)m_next->m_vertices[1];
        v65 = (__m128 *)m_next->m_vertices[0];
        location.m_region.m_type = NONE;
        v66 = v64[2];
        v67 = (__m128 *)m_next->m_vertices[2];
        *(__m128 *)&treeB[16] = _mm_add_ps(v66, v65[2]);
        *(__m128 *)&treeB[16] = _mm_mul_ps(_mm_add_ps(v67[2], *(__m128 *)&treeB[16]), (__m128)xmmword_141A711C0);
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v68 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v68 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        }
        location.m_region.m_feature.m_triangle = v68;
        memset(&location, 0, 48);
        *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                          + 1);
        location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
        location.m_inside.m_real = g_vectorfConstants[0];
        hkgpMesh::locate(v56, (hkVector4f *)&treeB[16], &location, (hkBool)1);
        if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
          break;
        m_next = m_next->m_next;
        if ( !m_next )
          goto LABEL_68;
      }
LABEL_80:
      v55 = v79;
      goto LABEL_81;
    }
LABEL_68:
    m_trianglesTree = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)v56->m_trianglesTree;
    v70 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v53->m_trianglesTree;
    *(_QWORD *)treeB = &array;
    array = 0i64;
    v81 = 0;
    v82 = 0x80000000;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,TrianglePairCollector>(
      v70,
      m_trianglesTree,
      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)treeB,
      v58);
    v71 = 0;
    if ( v81 > 0 )
    {
      v72 = 0i64;
      while ( 1 )
      {
        v73 = (_QWORD *)array[v72];
        v74 = (_QWORD *)array[v72 + 1];
        triangleA[0] = *(hkVector4f *)(v73[2] + 32i64);
        triangleA[1] = *(hkVector4f *)(v73[3] + 32i64);
        triangleA[2] = *(hkVector4f *)(v73[4] + 32i64);
        triangleB[0] = *(hkVector4f *)(v74[2] + 32i64);
        triangleB[1] = *(hkVector4f *)(v74[3] + 32i64);
        triangleB[2] = *(hkVector4f *)(v74[4] + 32i64);
        if ( hkcdIntersectTriangleTriangle((hkVector4f (*)[3])triangleA, (hkVector4f (*)[3])triangleB) )
          break;
        ++v71;
        v72 += 2i64;
        if ( v71 >= v81 )
          goto LABEL_74;
      }
      v57 = 0;
LABEL_74:
      v52 = *(_QWORD *)&v83[0].m_enum;
    }
    v81 = 0;
    if ( v82 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v82);
    array = 0i64;
    v82 = 0x80000000;
    if ( !v57 )
      goto LABEL_80;
    if ( hollowPolicy == HOLLOW_DISCARD )
    {
      hkgpMesh::rebuildConvexHull(v56);
      hkgpMesh::rebuildConvexHull(v53);
      ConvexHullVolume = hkgpMesh::getConvexHullVolume(v56, &result);
      if ( COERCE_FLOAT(*hkgpMesh::getConvexHullVolume(v53, &v89)) <= ConvexHullVolume->m_real.m128_f32[0] )
        goto LABEL_97;
      goto LABEL_80;
    }
    if ( hollowPolicy == HOLLOW_MERGE )
    {
      hkgpMesh::append(v56, v53);
      hkgpMesh::assignVertexNormals(v56);
      hkgpMesh::rebuildTrianglesTree(v56, 0.0);
    }
LABEL_97:
    v53->vfptr->__vecDelDtor(v53, 1u);
    v16 = v79;
    v77 = v79[v52];
    v19 = v84 - 1;
    v79[v52] = v79[v84 - 1];
    v79[v19] = v77;
    LODWORD(v9) = v78 - 1;
    LODWORD(v77) = sets->m_size - 1;
    --v78;
    v84 = v19;
    sets->m_size = (int)v77;
    v52 = 0i64;
LABEL_84:
    *(_QWORD *)&v83[0].m_enum = ++v52;
  }
  while ( v52 < v19 );
LABEL_85:
  if ( sort && (int)v9 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpMesh *,hkgpMeshInternals::CompareSetSize>(v16, 0, v9 - 1, 0);
  if ( (int)v9 > 0 )
  {
    do
    {
      if ( doSimplify )
      {
        v76 = v16[v13];
        v83[0].m_enum = 953267991;
        *(__m128 *)&treeB[16] = _mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0);
        *(__m128 *)&treeB[32] = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
        hkgpMesh::simplify(v76, (hkgpMesh::SimplifyConfig *)&treeB[16]);
      }
      if ( doConvexHulls )
        hkgpMesh::rebuildConvexHull(v16[v13]);
      ++v13;
    }
    while ( v13 < (int)v9 );
  }
  return (unsigned int)v9;
}ildConvexHull(v16[v13]);
      ++v13;
    }
    while ( v13 < (int)v9 );
  }
  return (unsigned int)v9;
}

// File Line: 818
// RVA: 0xCC7650
void __fastcall hkgpMesh::updatePlaneEquations(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *i; // rbx

  for ( i = this->m_triangles.m_used; i; i = i->m_next )
  {
    i->m_plane = 0i64;
    hkgpMesh::updatePlane(this, i);
  }
}

// File Line: 828
// RVA: 0xCC76A0
void __fastcall hkgpMesh::collapseEdge(hkgpMesh *this, hkgpMeshBase::Edge *edge, bool updatePlanes)
{
  hkgpMeshBase::Triangle *m_triangle; // r13
  signed int m_index; // r8d
  hkgpMeshBase::Vertex *v7; // r14
  char v8; // di
  __int64 v9; // rbx
  __int64 v10; // rax
  unsigned __int64 v11; // rdx
  hkgpMeshBase::Edge *v12; // rsi
  unsigned int v13; // ebx
  __int64 v14; // rcx
  unsigned __int64 v15; // r10
  hkgpMeshBase::Triangle *v16; // rdx
  int v17; // r13d
  unsigned __int64 v18; // r8
  __int64 v19; // r11
  __int64 v20; // r14
  unsigned __int64 v21; // r9
  __int64 v22; // rcx
  __int64 v23; // rax
  __int64 v24; // r8
  __int64 v25; // rax
  char *v26; // r8
  unsigned __int64 v27; // r8
  __int64 v28; // r10
  unsigned __int64 v29; // r9
  int v30; // edx
  unsigned __int64 v31; // r9
  __int64 v32; // rdx
  unsigned int v33; // r8d
  hkgpMeshBase::Triangle *v34; // r9
  int v35; // r12d
  __int64 v36; // rdx
  hkgpMeshBase::Triangle *v37; // r8
  int v38; // edi
  __int128 triangle; // [rsp+20h] [rbp-20h]
  __int128 trianglea; // [rsp+20h] [rbp-20h]
  __int128 v41; // [rsp+30h] [rbp-10h]
  unsigned __int64 v42; // [rsp+30h] [rbp-10h]
  int v43; // [rsp+38h] [rbp-8h]
  unsigned __int64 *v44; // [rsp+80h] [rbp+40h]
  unsigned __int64 *v46; // [rsp+88h] [rbp+48h]
  signed int v47; // [rsp+90h] [rbp+50h]
  int v48; // [rsp+90h] [rbp+50h]

  m_triangle = edge->m_triangle;
  m_index = edge->m_index;
  *(_QWORD *)&v41 = edge->m_triangle;
  DWORD2(v41) = m_index;
  v47 = m_index;
  triangle = v41;
  v7 = edge->m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
  while ( 1 )
  {
    v8 = BYTE8(triangle);
    v9 = triangle;
    *(_QWORD *)(triangle + 8i64 * SDWORD2(triangle) + 16) = v7;
    if ( updatePlanes )
    {
      hkgpMesh::updatePlane(this, (hkgpMeshBase::Triangle *)triangle);
      m_index = v47;
    }
    v10 = *(_QWORD *)(triangle + 8i64 * ((18 >> (2 * BYTE8(triangle))) & 3) + 40) & 3i64;
    v11 = *(_QWORD *)(triangle + 8i64 * ((18 >> (2 * BYTE8(triangle))) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    *(_QWORD *)&v41 = v11;
    DWORD2(v41) = *(_DWORD *)(triangle + 8i64 * ((18 >> (2 * BYTE8(triangle))) & 3) + 40) & 3;
    triangle = v41;
    if ( (*(_QWORD *)(v9 + 8i64 * ((18 >> (2 * v8)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
      break;
    if ( (hkgpMeshBase::Triangle *)(v11 + v10) == (hkgpMeshBase::Triangle *)((char *)m_triangle + (unsigned int)m_index) )
      goto LABEL_11;
  }
  *(_QWORD *)&v41 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  DWORD2(v41) = (9 >> (2 * (m_triangle->m_links[m_index] & 3))) & 3;
  for ( trianglea = v41; (_QWORD)v41; trianglea = v41 )
  {
    *(_QWORD *)(trianglea + 8i64 * SDWORD2(trianglea) + 16) = v7;
    if ( updatePlanes )
      hkgpMesh::updatePlane(this, (hkgpMeshBase::Triangle *)trianglea);
    *(_QWORD *)&v41 = *(_QWORD *)(trianglea + 8i64 * SDWORD2(trianglea) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    DWORD2(v41) = (9 >> (2 * (*(_QWORD *)(trianglea + 8i64 * SDWORD2(trianglea) + 40) & 3))) & 3;
  }
LABEL_11:
  v12 = edge;
  v13 = 0;
  v14 = (int)edge->m_index;
  v15 = edge->m_triangle->m_links[v14] & 3;
  v16 = (hkgpMeshBase::Triangle *)(edge->m_triangle->m_links[v14] & 0xFFFFFFFFFFFFFFFCui64);
  if ( v16 )
  {
    v17 = (9 >> (2 * v15)) & 3;
    v46 = &v16->m_links[v17];
    v18 = *v46 & 0xFFFFFFFFFFFFFFFCui64;
    v19 = *v46 & 3;
    v48 = (18 >> (2 * v15)) & 3;
    v44 = &v16->m_links[v48];
    v20 = *v44 & 3;
    v21 = *v44 & 0xFFFFFFFFFFFFFFFCui64;
    if ( v21 )
    {
      LODWORD(v19) = *(_DWORD *)v44 & 3;
      v18 = *v44 & 0xFFFFFFFFFFFFFFFCui64;
      LODWORD(v20) = *(_DWORD *)v46 & 3;
      v21 = *v46 & 0xFFFFFFFFFFFFFFFCui64;
    }
    if ( v18 )
    {
      *(_QWORD *)(v18 + 8i64 * (int)v19 + 40) = v21 + (unsigned int)v20;
      if ( v21 )
        *(_QWORD *)(v21 + 8i64 * (int)v20 + 40) = v18 + (unsigned int)v19;
      if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v23 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        v22 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      }
      else
      {
        v22 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
        v23 = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
      }
      *v46 = v22 + v23;
      v24 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
      {
        *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                  + 8i64
                  * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                  + 40) = (char *)v16 + (unsigned int)v17;
        v24 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      }
      if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v25 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
      }
      else
      {
        v24 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
        v25 = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
      }
      *v44 = v24 + v25;
      if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
        *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                  + 8i64
                  * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                  + 40) = (char *)v16 + (unsigned int)v48;
    }
    v26 = (char *)v16 + 8 * (int)v15;
    if ( (*((_QWORD *)v26 + 5) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      *(_QWORD *)((*((_QWORD *)v26 + 5) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*((_QWORD *)v26 + 5) & 3i64) + 40) = 0i64;
    *((_QWORD *)v26 + 5) = 0i64;
    hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::release(
      &this->m_triangles,
      v16);
  }
  v27 = v12->m_triangle->m_links[(9 >> (2 * LOBYTE(v12->m_index))) & 3] & 0xFFFFFFFFFFFFFFFCui64;
  v28 = v12->m_triangle->m_links[(9 >> (2 * LOBYTE(v12->m_index))) & 3] & 3;
  v29 = v12->m_triangle->m_links[(18 >> (2 * LOBYTE(v12->m_index))) & 3];
  v30 = v29 & 3;
  v31 = v29 & 0xFFFFFFFFFFFFFFFCui64;
  v42 = v31;
  v43 = v30;
  if ( v31 )
  {
    v30 = v12->m_triangle->m_links[(9 >> (2 * LOBYTE(v12->m_index))) & 3] & 3;
    v31 = v12->m_triangle->m_links[(9 >> (2 * LOBYTE(v12->m_index))) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    LODWORD(v28) = v43;
    v27 = v42;
  }
  if ( v27 )
  {
    *(_QWORD *)(v27 + 8i64 * (int)v28 + 40) = v31 + (unsigned int)v30;
    if ( v31 )
      *(_QWORD *)(v31 + 8i64 * v30 + 40) = v27 + (unsigned int)v28;
    if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v33 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
      v32 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    }
    else
    {
      v32 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      v33 = 0;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
    }
    v34 = v12->m_triangle;
    v35 = (9 >> (2 * v12->m_index)) & 3;
    v12->m_triangle->m_links[v35] = v32 + v33;
    v36 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
    {
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                + 40) = (char *)v34 + (unsigned int)v35;
      v36 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    }
    if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v13 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
    }
    else
    {
      v36 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
    }
    v37 = v12->m_triangle;
    v38 = (18 >> (2 * v12->m_index)) & 3;
    v12->m_triangle->m_links[v38] = v36 + v13;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                + 40) = (char *)v37 + (unsigned int)v38;
  }
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::release(
    &this->m_triangles,
    v12->m_triangle);
}essing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::re

// File Line: 848
// RVA: 0xCC7B50
hkgpMeshBase::Edge *__fastcall hkgpMesh::splitEdge(
        hkgpMesh *this,
        hkgpMeshBase::Edge *result,
        hkgpMeshBase::Edge *edge,
        hkgpMeshBase::Vertex *vertex,
        bool updatePlanes)
{
  hkgpMeshBase::Triangle *m_triangle; // rdx
  unsigned __int64 v7; // rsi
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // rcx
  hkgpMeshBase::Triangle *v12; // rax
  __int64 m_index; // rdx
  hkgpMeshBase::Triangle *v14; // r8
  hkgpMeshBase::Triangle *v15; // r9
  char *v16; // rax
  unsigned __int64 v17; // rdx
  int v18; // r8d
  hkgpMeshBase::Triangle *v19; // r8
  int v20; // edx
  __int64 v21; // rcx
  __int64 v22; // rax
  hkgpMeshBase::Triangle *v23; // rsi
  hkgpMeshBase::Triangle *v24; // r15
  hkgpMeshBase::Triangle *v25; // r14
  __int64 v26; // rdx
  hkgpMeshBase::Triangle *v27; // rcx
  hkgpMeshBase::Triangle *v28; // rax
  unsigned __int64 v29; // r9
  int v30; // r8d
  int v31; // r8d
  char *v32; // r10
  unsigned __int64 v33; // rdx
  int v34; // r9d
  hkgpMeshBase::Triangle *v35; // r9
  int v36; // edx
  hkgpMeshBase::Edge *v37; // rax
  unsigned int v38; // [rsp+58h] [rbp+10h]

  m_triangle = edge->m_triangle;
  v7 = edge->m_triangle->m_links[edge->m_index];
  p_m_triangles = &this->m_triangles;
  if ( (v7 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    v23 = (hkgpMeshBase::Triangle *)(v7 & 0xFFFFFFFFFFFFFFFCui64);
    v38 = edge->m_triangle->m_links[edge->m_index] & 3;
    v24 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            p_m_triangles,
            m_triangle);
    v25 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            &this->m_triangles,
            v23);
    v26 = 18i64 >> (2 * (unsigned __int8)edge->m_index);
    v27 = edge->m_triangle;
    v24->m_vertices[0] = vertex;
    v24->m_vertices[1] = v27->m_vertices[v26 & 3];
    v24->m_vertices[2] = v23->m_vertices[(9i64 >> (2 * (unsigned __int8)v38)) & 3];
    LOBYTE(v27) = 2 * edge->m_index;
    v28 = edge->m_triangle;
    v25->m_vertices[0] = vertex;
    v25->m_vertices[1] = v23->m_vertices[(18i64 >> (2 * (unsigned __int8)v38)) & 3];
    v25->m_vertices[2] = v28->m_vertices[(9i64 >> (char)v27) & 3];
    edge->m_triangle->m_vertices[edge->m_index] = vertex;
    v23->m_vertices[v38] = vertex;
    v29 = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v30 = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3] & 3;
    v24->m_links[1] = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3];
    if ( v29 )
      *(_QWORD *)(v29 + 8i64 * v30 + 40) = (char *)&v24->m_next + 1;
    v31 = (18 >> (2 * v38)) & 3;
    v32 = (char *)v23 + 8 * v31;
    v33 = *((_QWORD *)v32 + 5) & 0xFFFFFFFFFFFFFFFCui64;
    v34 = *((_DWORD *)v32 + 10) & 3;
    v25->m_links[1] = *((_QWORD *)v32 + 5);
    if ( v33 )
      *(_QWORD *)(v33 + 8i64 * v34 + 40) = (char *)&v25->m_next + 1;
    v35 = edge->m_triangle;
    v36 = (18 >> (2 * LOBYTE(edge->m_index))) & 3;
    v24->m_links[0] = (unsigned __int64)edge->m_triangle + (unsigned int)v36;
    if ( v35 )
      v35->m_links[v36] = (unsigned __int64)v24;
    v25->m_links[0] = (unsigned __int64)v23 + (unsigned int)v31;
    if ( v23 )
      *((_QWORD *)v32 + 5) = v25;
    v24->m_links[2] = (unsigned __int64)v23 + v38;
    if ( v23 )
      v23->m_links[v38] = (unsigned __int64)&v24->m_next + 2;
    v25->m_links[2] = (unsigned __int64)edge->m_triangle + edge->m_index;
    if ( edge->m_triangle )
      edge->m_triangle->m_links[edge->m_index] = (unsigned __int64)&v25->m_next + 2;
    if ( updatePlanes )
    {
      hkgpMesh::updatePlane(this, v24);
      hkgpMesh::updatePlane(this, v25);
      hkgpMesh::updatePlane(this, edge->m_triangle);
      hkgpMesh::updatePlane(this, v23);
    }
  }
  else
  {
    v12 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            p_m_triangles,
            m_triangle);
    m_index = (int)edge->m_index;
    v14 = edge->m_triangle;
    v15 = v12;
    v16 = (char *)edge->m_triangle + 8 * m_index;
    v15->m_vertices[0] = vertex;
    v15->m_vertices[1] = v14->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3];
    v15->m_vertices[2] = (hkgpMeshBase::Vertex *)*((_QWORD *)v16 + 2);
    edge->m_triangle->m_vertices[edge->m_index] = vertex;
    v17 = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v18 = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3] & 3;
    v15->m_links[1] = edge->m_triangle->m_links[(18 >> (2 * LOBYTE(edge->m_index))) & 3];
    if ( v17 )
      *(_QWORD *)(v17 + 8i64 * v18 + 40) = (char *)&v15->m_next + 1;
    v19 = edge->m_triangle;
    v20 = (18 >> (2 * LOBYTE(edge->m_index))) & 3;
    v15->m_links[0] = (unsigned __int64)edge->m_triangle + (unsigned int)v20;
    if ( v19 )
      v19->m_links[v20] = (unsigned __int64)v15;
    if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v22 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
      v21 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    }
    else
    {
      v21 = 0i64;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
      v22 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
    }
    v15->m_links[2] = v21 + v22;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                + 40) = (char *)&v15->m_next + 2;
    if ( updatePlanes )
    {
      hkgpMesh::updatePlane(this, v15);
      hkgpMesh::updatePlane(this, edge->m_triangle);
    }
  }
  result->m_triangle = edge->m_triangle;
  v37 = result;
  result->m_index = (18 >> (2 * LOBYTE(edge->m_index))) & 3;
  return v37;
}

// File Line: 891
// RVA: 0xCC7EB0
hkgpMeshBase::Edge *__fastcall hkgpMesh::splitEdge(
        hkgpMesh *this,
        hkgpMeshBase::Edge *result,
        hkgpMeshBase::Edge *edge,
        hkVector4f *position,
        bool updatePlanes)
{
  hkgpMeshBase::Vertex *v9; // rax
  hkgpMeshBase::Edge v11; // [rsp+30h] [rbp-18h] BYREF

  v9 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(&this->m_vertices);
  v9->m_data = 0i64;
  v9->m_position = (hkVector4f)position->m_quad;
  v11 = *edge;
  hkgpMesh::splitEdge(this, result, &v11, v9, updatePlanes);
  return result;
}

// File Line: 900
// RVA: 0xCC7F30
void __fastcall hkgpMesh::splitTriangle(
        hkgpMesh *this,
        hkgpMeshBase::Triangle *triangle,
        hkVector4f *position,
        bool updatePlanes)
{
  hkgpMeshBase::Vertex *v7; // rsi
  hkgpMeshBase::Triangle *v8; // rax
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // rcx
  hkgpMeshBase::Triangle *v10; // rdi
  hkgpMeshBase::Triangle *v11; // rax
  hkgpMeshBase::Triangle *v12; // rdx
  unsigned __int64 v13; // r8
  int v14; // eax
  unsigned __int64 v15; // rcx
  int v16; // r8d

  v7 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(&this->m_vertices);
  v7->m_data = 0i64;
  v7->m_position = (hkVector4f)position->m_quad;
  v8 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
         &this->m_triangles,
         triangle);
  p_m_triangles = &this->m_triangles;
  v10 = v8;
  v11 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
          p_m_triangles,
          triangle);
  triangle->m_vertices[0] = v7;
  v10->m_vertices[1] = v7;
  v11->m_vertices[2] = v7;
  v12 = v11;
  v13 = triangle->m_links[2] & 0xFFFFFFFFFFFFFFFCui64;
  v14 = triangle->m_links[2] & 3;
  v10->m_links[2] = triangle->m_links[2];
  if ( v13 )
    *(_QWORD *)(v13 + 8i64 * v14 + 40) = (char *)&v10->m_next + 2;
  v15 = triangle->m_links[0] & 0xFFFFFFFFFFFFFFFCui64;
  v16 = triangle->m_links[0] & 3;
  v12->m_links[0] = triangle->m_links[0];
  if ( v15 )
    *(_QWORD *)(v15 + 8i64 * v16 + 40) = v12;
  triangle->m_links[0] = (unsigned __int64)&v12->m_next + 1;
  v12->m_links[1] = (unsigned __int64)triangle;
  v10->m_links[0] = (unsigned __int64)&v12->m_next + 2;
  v12->m_links[2] = (unsigned __int64)v10;
  v10->m_links[1] = (unsigned __int64)&triangle->m_next + 2;
  triangle->m_links[2] = (unsigned __int64)&v10->m_next + 1;
}

// File Line: 919
// RVA: 0xCC8020
void __fastcall hkgpMesh::simplify(hkgpMesh *this, hkgpMesh::SimplifyConfig *config)
{
  hkgpMeshBase::Triangle *m_used; // rsi
  unsigned int v4; // edi
  __int64 v5; // r14
  unsigned __int64 v6; // r12
  __m128 m_quad; // xmm9
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  hkVector4f v10; // xmm14
  __int64 v11; // r15
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  char v20; // r13
  __int64 v21; // rax
  __int128 v22; // xmm6
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm10
  __m128 v32; // xmm2
  __int64 v33; // rax
  unsigned __int64 v34; // rdx
  __int64 v35; // r13
  unsigned __int64 v36; // rdx
  hkgpMesh *v37; // r13
  __m128 v38; // xmm0
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm2
  __int64 v46; // rax
  __int128 v47; // xmm6
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm3
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __m128 v55; // xmm2
  __m128 v56; // xmm10
  __m128 v57; // xmm2
  __int64 v58; // rdx
  __int128 v59; // xmm6
  int v60; // r9d
  char *v61; // rax
  __int64 v62; // rcx
  __int64 v63; // rax
  unsigned __int64 v64; // rdx
  unsigned __int64 v65; // rdx
  __int128 v66; // xmm6
  char *v67; // rax
  __int64 v68; // r8
  char *v69; // rdx
  __int64 v70; // rcx
  __int128 v71; // xmm6
  int v72; // r9d
  char *v73; // rax
  __int64 v74; // rcx
  __int64 v75; // rax
  unsigned __int64 v76; // rdx
  int v77; // r8d
  char *v78; // rdx
  char v79; // r14
  __int64 v80; // rdx
  hkgpMeshBase::Edge v81; // xmm6
  char *v82; // rax
  __int64 v83; // rdx
  int v84; // eax
  int v85; // r10d
  __int64 v86; // r9
  int v87; // eax
  int v88; // r11d
  __int64 v89; // r10
  int v90; // eax
  int v91; // r10d
  __int64 v92; // r9
  int v93; // eax
  __int64 v94; // rcx
  int v95; // r10d
  __int64 v96; // r9
  int v97; // eax
  __int64 v98; // rcx
  char *v99; // r11
  int v100; // r10d
  __int64 v101; // r9
  char *v102; // r8
  __int128 v103; // [rsp+20h] [rbp-A0h]
  __int128 v104; // [rsp+20h] [rbp-A0h]
  __int128 t; // [rsp+30h] [rbp-90h]
  __int128 ta; // [rsp+30h] [rbp-90h]
  __int128 v107; // [rsp+40h] [rbp-80h]
  hkgpMeshBase::Edge v108; // [rsp+40h] [rbp-80h]
  __int128 v109; // [rsp+50h] [rbp-70h]
  hkgpMeshBase::Edge v110; // [rsp+60h] [rbp-60h]
  __int128 v111; // [rsp+70h] [rbp-50h]
  __int128 v112; // [rsp+80h] [rbp-40h]
  __int128 v113; // [rsp+90h] [rbp-30h]
  __int128 v114; // [rsp+A0h] [rbp-20h]
  __int128 v115; // [rsp+B0h] [rbp-10h]
  __int128 v116; // [rsp+C0h] [rbp+0h]
  __int128 v117; // [rsp+D0h] [rbp+10h]
  char *array; // [rsp+E0h] [rbp+20h] BYREF
  int v119; // [rsp+E8h] [rbp+28h]
  int v120; // [rsp+ECh] [rbp+2Ch]
  char v121; // [rsp+F0h] [rbp+30h] BYREF
  hkVector4f p; // [rsp+1F0h] [rbp+130h] BYREF
  hkgpMeshBase::Edge v123; // [rsp+200h] [rbp+140h] BYREF
  hkVector4f v124; // [rsp+210h] [rbp+150h] BYREF
  hkVector4f v125; // [rsp+220h] [rbp+160h] BYREF
  hkVector4f v126; // [rsp+230h] [rbp+170h] BYREF
  char *v127; // [rsp+240h] [rbp+180h] BYREF
  int v128; // [rsp+248h] [rbp+188h]
  int v129; // [rsp+24Ch] [rbp+18Ch]
  char v130; // [rsp+250h] [rbp+190h] BYREF
  hkgpMesh *v131; // [rsp+430h] [rbp+370h]
  float *v132; // [rsp+438h] [rbp+378h]
  char v133; // [rsp+440h] [rbp+380h]
  unsigned __int64 m_next; // [rsp+448h] [rbp+388h]

  do
  {
    m_used = this->m_triangles.m_used;
    v133 = 0;
    if ( !m_used )
      break;
    do
    {
      v4 = 0;
      m_next = (unsigned __int64)m_used->m_next;
      while ( 1 )
      {
        v110.m_triangle = m_used;
        v110.m_index = v4;
        v5 = m_used->m_links[v4] & 3;
        v6 = m_used->m_links[v4] & 0xFFFFFFFFFFFFFFFCui64;
        if ( v6 )
          break;
LABEL_50:
        if ( (int)++v4 >= 3 )
        {
          v79 = v133;
          goto LABEL_52;
        }
      }
      m_quad = aabbOut.m_quad;
      v8 = query.m_quad;
      *(_QWORD *)&v113 = m_used;
      DWORD2(v113) = v4;
      v9 = aabbOut.m_quad;
      v10.m_quad = (__m128)m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)v4)) & 3]->m_position;
      t = v113;
      while ( 1 )
      {
        v11 = t;
        v12 = *(__m128 *)(*(_QWORD *)(t + 16) + 32i64);
        v13 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(t + 24) + 32i64), v12);
        v14 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(t + 32) + 32i64), v12);
        v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14));
        v16 = _mm_shuffle_ps(v15, v15, 201);
        v17 = _mm_mul_ps(v16, v16);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        v19 = _mm_rsqrt_ps(v18);
        m_quad = _mm_add_ps(
                   m_quad,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v18, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                         _mm_mul_ps(*(__m128 *)_xmm, v19)),
                       v18)));
        hkgpMesh::setPlane(this, (hkgpMeshBase::Triangle *)t, &p, 1);
        v20 = BYTE8(t);
        v21 = *(_QWORD *)(t + 8i64 * SDWORD2(t) + 16);
        v22 = *(_OWORD *)(v21 + 32);
        *(hkVector4f *)(v21 + 32) = (hkVector4f)v10.m_quad;
        v23 = *(__m128 *)(*(_QWORD *)(t + 16) + 32i64);
        v24 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(t + 24) + 32i64), v23);
        v25 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(t + 32) + 32i64), v23);
        v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
        v27 = _mm_shuffle_ps(v26, v26, 201);
        v28 = _mm_mul_ps(v27, v27);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rsqrt_ps(v29);
        v31 = _mm_andnot_ps(
                _mm_cmple_ps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30)),
                  v29));
        hkgpMesh::setPlane(v131, (hkgpMeshBase::Triangle *)t, &v125, 1);
        *(_OWORD *)(*(_QWORD *)(t + 8i64 * SDWORD2(t) + 16) + 32i64) = v22;
        if ( v31.m128_f32[0] > 0.00000011920929 )
        {
          v9 = _mm_add_ps(v9, v31);
          v32 = _mm_mul_ps(p.m_quad, v125.m_quad);
          v8 = _mm_min_ps(
                 v8,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                   _mm_shuffle_ps(v32, v32, 170)));
        }
        v33 = *(_QWORD *)(t + 8i64 * ((18 >> (2 * BYTE8(t))) & 3) + 40) & 3i64;
        v34 = *(_QWORD *)(t + 8i64 * ((18 >> (2 * BYTE8(t))) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
        *(_QWORD *)&v111 = v34;
        DWORD2(v111) = *(_DWORD *)(t + 8i64 * ((18 >> (2 * BYTE8(t))) & 3) + 40) & 3;
        t = v111;
        if ( (*(_QWORD *)(v11 + 8i64 * ((18 >> (2 * v20)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          break;
        this = v131;
        if ( (hkgpMeshBase::Triangle *)(v34 + (unsigned int)v33) == (hkgpMeshBase::Triangle *)((char *)m_used + v4) )
          goto LABEL_15;
      }
      v35 = (int)v4;
      v36 = m_used->m_links[v4];
      *(_QWORD *)&v112 = v36 & 0xFFFFFFFFFFFFFFFCui64;
      DWORD2(v112) = (9 >> (2 * (v36 & 3))) & 3;
      ta = v112;
      if ( (v36 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        goto LABEL_16;
      v37 = v131;
      do
      {
        v38 = *(__m128 *)(*(_QWORD *)(ta + 16) + 32i64);
        v39 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(ta + 24) + 32i64), v38);
        v40 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(ta + 32) + 32i64), v38);
        v41 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
        v42 = _mm_shuffle_ps(v41, v41, 201);
        v43 = _mm_mul_ps(v42, v42);
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170));
        v45 = _mm_rsqrt_ps(v44);
        m_quad = _mm_add_ps(
                   m_quad,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v44, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                         _mm_mul_ps(v45, *(__m128 *)_xmm)),
                       v44)));
        hkgpMesh::setPlane(v37, (hkgpMeshBase::Triangle *)ta, &v124, 1);
        v46 = *(_QWORD *)(ta + 8i64 * SDWORD2(ta) + 16);
        v47 = *(_OWORD *)(v46 + 32);
        *(hkVector4f *)(v46 + 32) = (hkVector4f)v10.m_quad;
        v48 = *(__m128 *)(*(_QWORD *)(ta + 16) + 32i64);
        v49 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(ta + 24) + 32i64), v48);
        v50 = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(ta + 32) + 32i64), v48);
        v51 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v49), _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v50));
        v52 = _mm_shuffle_ps(v51, v51, 201);
        v53 = _mm_mul_ps(v52, v52);
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                _mm_shuffle_ps(v53, v53, 170));
        v55 = _mm_rsqrt_ps(v54);
        v56 = _mm_andnot_ps(
                _mm_cmple_ps(v54, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                    _mm_mul_ps(v55, *(__m128 *)_xmm)),
                  v54));
        hkgpMesh::setPlane(v37, (hkgpMeshBase::Triangle *)ta, &v126, 1);
        *(_OWORD *)(*(_QWORD *)(ta + 8i64 * SDWORD2(ta) + 16) + 32i64) = v47;
        if ( v56.m128_f32[0] > 0.00000011920929 )
        {
          v9 = _mm_add_ps(v9, v56);
          v57 = _mm_mul_ps(v124.m_quad, v126.m_quad);
          v8 = _mm_min_ps(
                 v8,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                   _mm_shuffle_ps(v57, v57, 170)));
        }
        v58 = *(_QWORD *)(ta + 8i64 * SDWORD2(ta) + 40);
        *(_QWORD *)&v109 = v58 & 0xFFFFFFFFFFFFFFFCui64;
        DWORD2(v109) = (9 >> (2 * (v58 & 3))) & 3;
        ta = v109;
      }
      while ( (v58 & 0xFFFFFFFFFFFFFFFCui64) != 0 );
LABEL_15:
      v35 = (int)v4;
LABEL_16:
      if ( v8.m128_f32[0] < *v132
        || COERCE_FLOAT((unsigned int)(2 * COERCE_INT(m_quad.m128_f32[0] - v9.m128_f32[0])) >> 1) > v132[4] )
      {
        goto LABEL_49;
      }
      *(_QWORD *)&v115 = m_used;
      DWORD2(v115) = v4;
      v59 = v115;
      v60 = 0;
      v119 = 0;
      v103 = v115;
      array = &v121;
      v120 = -2147483632;
      while ( 1 )
      {
        if ( v60 == (v120 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v60 = v119;
        }
        v61 = &array[16 * v60];
        if ( v61 )
        {
          *(_OWORD *)v61 = v59;
          v60 = v119;
        }
        v119 = ++v60;
        v62 = (18 >> (2 * BYTE8(v103))) & 3;
        v63 = *(_QWORD *)(v103 + 8 * v62 + 40) & 3i64;
        v64 = *(_QWORD *)(v103 + 8 * v62 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        *(_QWORD *)&v111 = v64;
        DWORD2(v111) = *(_DWORD *)(v103 + 8 * v62 + 40) & 3;
        v59 = v111;
        v103 = v111;
        if ( !v64 )
          break;
        if ( (hkgpMeshBase::Triangle *)(v64 + (unsigned int)v63) == (hkgpMeshBase::Triangle *)((char *)m_used + v4) )
          goto LABEL_32;
      }
      v65 = m_used->m_links[v35];
      *(_QWORD *)&v117 = v65 & 0xFFFFFFFFFFFFFFFCui64;
      DWORD2(v117) = (9 >> (2 * (v65 & 3))) & 3;
      v66 = v117;
      v104 = v117;
      if ( (v65 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        do
        {
          if ( v60 == (v120 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v60 = v119;
          }
          v67 = &array[16 * v60];
          if ( v67 )
          {
            *(_OWORD *)v67 = v66;
            v60 = v119;
          }
          v119 = ++v60;
          *(_QWORD *)&v114 = *(_QWORD *)(v104 + 8i64 * SDWORD2(v104) + 40) & 0xFFFFFFFFFFFFFFFCui64;
          DWORD2(v114) = (9 >> (2 * (*(_BYTE *)(v104 + 8i64 * SDWORD2(v104) + 40) & 3))) & 3;
          v66 = v114;
          v104 = v114;
        }
        while ( (_QWORD)v114 );
      }
LABEL_32:
      v68 = 0i64;
      if ( v60 > 0 )
      {
        v69 = array;
        while ( 1 )
        {
          v70 = *((int *)v69 + 2);
          if ( (*(_QWORD *)(*(_QWORD *)v69 + 8 * v70 + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0
            || (*(_QWORD *)(*(_QWORD *)v69 + 8i64 * ((9 >> (2 * v70)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          {
            break;
          }
          ++v68;
          v69 += 16;
          if ( v68 >= v60 )
            goto LABEL_37;
        }
        v77 = v120;
        v119 = 0;
        if ( v120 >= 0 )
        {
          v78 = array;
          goto LABEL_47;
        }
        goto LABEL_48;
      }
LABEL_37:
      *(_QWORD *)&v109 = v6;
      DWORD2(v109) = v5;
      v71 = v109;
      v72 = 0;
      v128 = 0;
      v107 = v109;
      v127 = &v130;
      v129 = -2147483632;
      while ( 1 )
      {
        if ( v72 == (v129 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v127, 16);
          v72 = v128;
        }
        v73 = &v127[16 * v72];
        if ( v73 )
        {
          *(_OWORD *)v73 = v71;
          v72 = v128;
        }
        v128 = ++v72;
        v74 = (18 >> (2 * BYTE8(v107))) & 3;
        v75 = *(_QWORD *)(v107 + 8 * v74 + 40) & 3i64;
        v76 = *(_QWORD *)(v107 + 8 * v74 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        *(_QWORD *)&v116 = v76;
        DWORD2(v116) = *(_DWORD *)(v107 + 8 * v74 + 40) & 3;
        v71 = v116;
        v107 = v116;
        if ( !v76 )
          break;
        if ( v76 + (unsigned int)v75 == v6 + (unsigned int)v5 )
          goto LABEL_61;
      }
      v80 = *(_QWORD *)(v6 + 8i64 * (int)v5 + 40);
      v110.m_triangle = (hkgpMeshBase::Triangle *)(v80 & 0xFFFFFFFFFFFFFFFCui64);
      v110.m_index = (9 >> (2 * (v80 & 3))) & 3;
      v81 = v110;
      v108 = v110;
      if ( (v80 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        do
        {
          if ( v72 == (v129 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v127, 16);
            v72 = v128;
          }
          v82 = &v127[16 * v72];
          if ( v82 )
          {
            *(hkgpMeshBase::Edge *)v82 = v81;
            v72 = v128;
          }
          v128 = ++v72;
          v83 = v108.m_triangle->m_links[v108.m_index] & 3;
          v108.m_triangle = (hkgpMeshBase::Triangle *)(v108.m_triangle->m_links[v108.m_index] & 0xFFFFFFFFFFFFFFFCui64);
          v108.m_index = (9 >> (2 * v83)) & 3;
          v81 = v108;
        }
        while ( v108.m_triangle );
      }
LABEL_61:
      v84 = v119;
      v85 = 0;
      if ( v119 > 0 )
      {
        v86 = 0i64;
        do
        {
          ++v85;
          v87 = *(_DWORD *)&array[v86 + 8];
          v86 += 16i64;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&array[v86 - 16] + 8 * ((9i64 >> (2 * (unsigned __int8)v87)) & 3) + 16)
                    + 84i64) = 0;
          v84 = v119;
        }
        while ( v85 < v119 );
        v72 = v128;
      }
      v88 = 0;
      if ( v72 > 0 )
      {
        v89 = 0i64;
        do
        {
          ++v88;
          v90 = *(_DWORD *)&v127[v89 + 8];
          v89 += 16i64;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v127[v89 - 16] + 8 * ((9i64 >> (2 * (unsigned __int8)v90)) & 3) + 16)
                    + 84i64) = 0;
          v72 = v128;
        }
        while ( v88 < v128 );
        v84 = v119;
      }
      v91 = 0;
      if ( v84 > 0 )
      {
        v92 = 0i64;
        do
        {
          ++v91;
          v93 = *(_DWORD *)&array[v92 + 8];
          v92 += 16i64;
          v94 = *(_QWORD *)(*(_QWORD *)&array[v92 - 16] + 8 * ((9i64 >> (2 * (unsigned __int8)v93)) & 3) + 16);
          ++*(_DWORD *)(v94 + 84);
          v84 = v119;
        }
        while ( v91 < v119 );
        v72 = v128;
      }
      v95 = 0;
      if ( v72 > 0 )
      {
        v96 = 0i64;
        do
        {
          ++v95;
          v97 = *(_DWORD *)&v127[v96 + 8];
          v96 += 16i64;
          v98 = *(_QWORD *)(*(_QWORD *)&v127[v96 - 16] + 8 * ((9i64 >> (2 * (unsigned __int8)v97)) & 3) + 16);
          *(_DWORD *)(v98 + 84) += 2;
        }
        while ( v95 < v128 );
        v84 = v119;
      }
      v99 = array;
      v100 = 0;
      v101 = v84;
      if ( v84 <= 0 )
        goto LABEL_83;
      v102 = array;
      do
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v102
                                   + 8 * ((9i64 >> (2 * (unsigned __int8)*((_DWORD *)v102 + 2))) & 3)
                                   + 16)
                       + 84i64) == 3 )
          ++v100;
        v102 += 16;
        --v101;
      }
      while ( v101 );
      if ( v100 != 2 )
      {
LABEL_83:
        v128 = 0;
        if ( v129 >= 0 )
        {
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            v127,
            (unsigned int)(16 * v129),
            v101);
          v99 = array;
        }
        v77 = v120;
        v127 = 0i64;
        v129 = 0x80000000;
        v119 = 0;
        if ( v120 >= 0 )
        {
          v78 = v99;
LABEL_47:
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v78, 16 * v77);
        }
LABEL_48:
        array = 0i64;
        v120 = 0x80000000;
LABEL_49:
        this = v131;
        goto LABEL_50;
      }
      if ( (hkgpMeshBase::Triangle *)m_next == m_used || m_next == v6 )
        m_next = m_used->m_links[(9 >> (2 * v4)) & 3] & 0xFFFFFFFFFFFFFFFCui64;
      this = v131;
      v123 = v110;
      hkgpMesh::collapseEdge(v131, &v123, 0);
      v79 = 1;
      v133 = 1;
      v128 = 0;
      if ( v129 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v127, 16 * v129);
      v127 = 0i64;
      v129 = 0x80000000;
      v119 = 0;
      if ( v120 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v120);
      array = 0i64;
      v120 = 0x80000000;
LABEL_52:
      m_used = (hkgpMeshBase::Triangle *)m_next;
    }
    while ( m_next );
  }
  while ( v79 );
  hkgpMesh::removeOrphanVertices(this);
  hkgpMesh::invalidateConvexHull(this);
  hkgpMesh::setVerticesTag(this, -1);
} );
  hkgpMesh::removeOrphanVertices(this);
  hkgpMesh::invalidateConvexHull(this);
  hkgpMesh::setVerticesTag(this, -1);
}

// File Line: 966
// RVA: 0xCC8C60
void __fastcall hkgpMesh::locate(
        hkgpMesh *this,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *x,
        hkgpMesh::Location *location,
        hkBool useTree)
{
  hkVector4f v7; // xmm6
  hkgpMeshBase::Triangle *v8; // rsi
  hkVector4f v9; // xmm1
  __int64 v10; // rdx
  hkSimdFloat32 *v11; // rax
  hkReferencedObject v12; // xmm4
  hkSimdFloat32 v13; // xmm7
  __m128 v14; // xmm1
  __int64 v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  hkVector4f v19; // xmm5
  __m128 *v20; // r8
  __m128 *v21; // r9
  __m128 *v22; // r10
  hkVector4f v23; // xmm0
  hkVector4f v24; // xmm1
  __int64 v25; // rax
  hkVector4f v26; // xmm1
  hkgpMeshBase::Triangle *m_used; // rdi
  __m128 *v28; // rax
  hkVector4f v29; // xmm0
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm0
  __int64 v32; // rcx
  __int64 v33; // rcx
  __m128 v34; // xmm5
  hkVector4f *normalOut; // [rsp+28h] [rbp-C0h]
  hkErrStream baryOut; // [rsp+40h] [rbp-A8h] BYREF
  char point[24]; // [rsp+60h] [rbp-88h] BYREF
  hkReferencedObject v38; // [rsp+78h] [rbp-70h]
  hkgpMeshBase::Triangle *v39; // [rsp+88h] [rbp-60h]
  NearestFeaturePolicy query; // [rsp+98h] [rbp-50h] BYREF
  hkVector4f p2; // [rsp+C8h] [rbp-20h] BYREF
  char buf[584]; // [rsp+D8h] [rbp-10h] BYREF
  char v43; // [rsp+340h] [rbp+258h]

  if ( !this->m_hasPerVertexNormals )
  {
    hkErrStream::hkErrStream(&baryOut, buf, 512);
    hkOstream::operator<<(&baryOut, "assignVertexNormals not called");
    if ( (unsigned int)hkError::messageError(0x672B48D7u, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 969) )
      __debugbreak();
    hkOstream::~hkOstream(&baryOut);
    useTree.m_bool = v43;
  }
  v7.m_quad = (__m128)xmmword_141A712A0;
  v8 = 0i64;
  v9.m_quad = 0i64;
  v10 = 0i64;
  query.m_normal = (hkVector4f)xmmword_141A712A0;
  v39 = 0i64;
  *(_OWORD *)&point[8] = 0i64;
  if ( useTree.m_bool )
  {
    v11 = hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::closest<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,NearestFeaturePolicy>(
            (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&baryOut,
            (hkSimdFloat32 *)this->m_trianglesTree,
            x,
            (hkVector4f *)&point[8],
            &query,
            (hkSimdFloat32 *)normalOut);
    v10 = (__int64)v39;
    v9.m_quad = *(__m128 *)&point[8];
    v7.m_quad = v11->m_real;
LABEL_7:
    v12 = v38;
    goto LABEL_8;
  }
  m_used = this->m_triangles.m_used;
  if ( !m_used )
    goto LABEL_7;
  do
  {
    query.m_coordinates = m_used->m_vertices[0]->m_position;
    v28 = (__m128 *)m_used->m_vertices[2];
    *(hkVector4f *)&query.m_nearestTriangle = m_used->m_vertices[1]->m_position;
    p2.m_quad = v28[2];
    hkGeometryProcessing::squaredDistanceFromPointToTriangle(
      (hkSimdFloat32 *)&query,
      (hkVector4f *)x,
      &query.m_coordinates,
      (hkVector4f *)&query.m_nearestTriangle,
      &p2,
      (hkVector4f *)point,
      (hkVector4f *)&baryOut);
    if ( query.m_normal.m_quad.m128_f32[0] >= v7.m_quad.m128_f32[0] )
    {
      v10 = (__int64)v39;
      v12 = v38;
      v9.m_quad = *(__m128 *)&point[8];
    }
    else
    {
      v9.m_quad = *(__m128 *)point;
      v12 = baryOut.hkReferencedObject;
      v10 = (__int64)m_used;
      v39 = m_used;
      *(_OWORD *)&point[8] = *(_OWORD *)point;
      v38 = baryOut.hkReferencedObject;
      v7.m_quad = (__m128)query.m_normal;
    }
    m_used = m_used->m_next;
  }
  while ( m_used );
LABEL_8:
  location->m_pseudoNormal = 0i64;
  v13.m_real = _mm_andnot_ps(
                 _mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v7.m_quad, 1u), 1u), *(__m128 *)&epsilon),
                 v7.m_quad);
  if ( v10 )
  {
    location->m_normal = (hkVector4f)v9.m_quad;
    v14 = _mm_mul_ps(v9.m_quad, v9.m_quad);
    *(_DWORD *)point = 1;
    *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
    v15 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
    location->m_inside.m_real = g_vectorfConstants[0];
    location->m_coordinates = (hkVector4f)v12;
    location->m_squaredDistance = (hkSimdFloat32)v13.m_real;
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v16), (__m128)0i64);
    v19.m_quad = _mm_or_ps(
                   _mm_and_ps(
                     _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v16, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                           _mm_mul_ps(*(__m128 *)_xmm, v17))),
                       location->m_normal.m_quad),
                     v18),
                   _mm_andnot_ps(v18, location->m_normal.m_quad));
    location->m_normal = (hkVector4f)v19.m_quad;
    v20 = *(__m128 **)(v10 + 16);
    v21 = *(__m128 **)(v10 + 24);
    v22 = *(__m128 **)(v10 + 32);
    v23.m_quad = _mm_mul_ps(_mm_shuffle_ps((__m128)v12, (__m128)v12, 0), v20[2]);
    location->m_projection = (hkVector4f)v23.m_quad;
    v24.m_quad = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps((__m128)v12, (__m128)v12, 85), *(__m128 *)(*(_QWORD *)(v10 + 24) + 32i64)),
                   v23.m_quad);
    location->m_projection = (hkVector4f)v24.m_quad;
    v25 = *(_QWORD *)point;
    location->m_projection.m_quad = _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)v12, (__m128)v12, 170),
                                        *(__m128 *)(*(_QWORD *)(v10 + 32) + 32i64)),
                                      v24.m_quad);
    location->m_inside = (hkSimdFloat32)::query.m_quad;
    v26.m_quad = *(__m128 *)(v10 + 64);
    *(_QWORD *)&location->m_region.m_type = v25;
    location->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
    *(_QWORD *)&location->m_region.m_feature.m_index = v15;
    location->m_pseudoNormal = (hkVector4f)v26.m_quad;
    switch ( _mm_movemask_ps(_mm_cmpneq_ps((__m128)v12, (__m128)0i64)) & 7 )
    {
      case 1:
        v31.m_quad = v20[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
        *(_DWORD *)point = 3;
        location->m_pseudoNormal = (hkVector4f)v31.m_quad;
        goto LABEL_29;
      case 2:
        v30.m_quad = v21[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 1;
        *(_DWORD *)point = 3;
        location->m_pseudoNormal = (hkVector4f)v30.m_quad;
        goto LABEL_29;
      case 3:
        if ( (*(_QWORD *)(v10 + 40) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          location->m_pseudoNormal.m_quad = _mm_add_ps(
                                              *(__m128 *)((*(_QWORD *)(v10 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                              location->m_pseudoNormal.m_quad);
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
        goto LABEL_28;
      case 4:
        v29.m_quad = v22[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 2;
        *(_DWORD *)point = 3;
        location->m_pseudoNormal = (hkVector4f)v29.m_quad;
        goto LABEL_29;
      case 5:
        if ( (*(_QWORD *)(v10 + 56) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          location->m_pseudoNormal.m_quad = _mm_add_ps(
                                              *(__m128 *)((*(_QWORD *)(v10 + 56) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                              location->m_pseudoNormal.m_quad);
        *(_DWORD *)point = 2;
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 2;
        v32 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
        *(_QWORD *)&location->m_region.m_type = *(_QWORD *)point;
        location->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
        *(_QWORD *)&location->m_region.m_feature.m_index = v32;
        break;
      case 6:
        if ( (*(_QWORD *)(v10 + 48) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          location->m_pseudoNormal.m_quad = _mm_add_ps(
                                              *(__m128 *)((*(_QWORD *)(v10 + 48) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                              location->m_pseudoNormal.m_quad);
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 1;
LABEL_28:
        *(_DWORD *)point = 2;
LABEL_29:
        v33 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
        *(_QWORD *)&location->m_region.m_type = *(_QWORD *)point;
        location->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
        *(_QWORD *)&location->m_region.m_feature.m_index = v33;
        break;
      case 7:
        if ( v13.m_real.m128_f32[0] == 0.0 )
          location->m_inside.m_real = g_vectorfConstants[0];
        break;
      default:
        break;
    }
    v34 = _mm_mul_ps(v19.m_quad, location->m_pseudoNormal.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
               + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]) <= 0.0 )
      location->m_inside.m_real = g_vectorfConstants[0];
  }
  else
  {
    location->m_normal = 0i64;
    location->m_coordinates = 0i64;
    location->m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
    location->m_region.m_type = NONE;
    location->m_inside = (hkSimdFloat32)::query.m_quad;
    if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v8 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    }
    else
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
    }
    location->m_region.m_feature.m_triangle = v8;
    *(_QWORD *)&location->m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                       + 1);
  }
}

// File Line: 1074
// RVA: 0xCC9120
hkSimdFloat32 *__fastcall hkgpMesh::squaredDistanceToPoint(
        hkgpMesh *this,
        hkSimdFloat32 *result,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *x,
        hkVector4f *normal,
        hkVector4fComparison *inside)
{
  hkgpMeshBase::Triangle *v5; // rax
  hkSimdFloat32 v8; // xmm1
  hkVector4f v9; // xmm0
  hkSimdFloat32 *v10; // rax
  hkgpMesh::Location location; // [rsp+20h] [rbp-98h] BYREF

  v5 = 0i64;
  location.m_region.m_type = NONE;
  if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
  {
    v5 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
  }
  else
  {
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
  }
  location.m_region.m_feature.m_triangle = v5;
  *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                    + 1);
  memset(&location, 0, 48);
  location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
  location.m_inside.m_real = g_vectorfConstants[0];
  hkgpMesh::locate(this, x, &location, (hkBool)1);
  v8.m_real = (__m128)location.m_squaredDistance;
  inside->m_mask = _mm_cmplt_ps(location.m_inside.m_real, (__m128)0i64);
  v9.m_quad = (__m128)location.m_normal;
  v10 = result;
  *result = (hkSimdFloat32)v8.m_real;
  *normal = (hkVector4f)v9.m_quad;
  return v10;
}

// File Line: 1084
// RVA: 0xCC9210
hkgpConvexHull *__fastcall hkgpMesh::getConvexHull(hkgpMesh *this)
{
  return this->m_convexHull;
}

// File Line: 1089
// RVA: 0xCC9220
hkSimdFloat32 *__fastcall hkgpMesh::getConvexHullVolume(hkgpMesh *this, hkSimdFloat32 *result)
{
  hkgpConvexHull *ConvexHull; // rax

  ConvexHull = hkgpMesh::getConvexHull(this);
  hkgpConvexHull::getVolume(ConvexHull, result);
  return result;
}

// File Line: 1094
// RVA: 0xCC9250
hkgpMesh *__fastcall hkgpMesh::clone(hkgpMesh *this)
{
  _QWORD **Value; // rax
  hkgpMesh *v3; // rax
  __int64 v4; // rax
  __int64 v5; // r13
  hkgpMesh::IConvexOverlap *m_iconvexoverlap; // rax
  hkgpMeshBase::Vertex *i; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  unsigned __int64 m_free; // r9
  __int64 v10; // rax
  hkgpMeshBase::Triangle *m_used; // rsi
  hkgpMeshBase::Triangle *v12; // rax
  __int64 v13; // rbp
  hkgpMeshBase::Vertex **m_vertices; // rbx
  hkgpMeshBase::Triangle *v15; // rdi
  signed __int64 v16; // r14
  unsigned __int64 v17; // rax
  unsigned int j; // ebx
  __int64 v19; // r14
  __int64 v20; // rax
  unsigned __int64 v21; // rax
  unsigned int v22; // r9d
  unsigned __int64 v23; // rax
  AMD_HD3D v25; // [rsp+20h] [rbp-48h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 152i64);
  if ( v3 )
  {
    hkgpMesh::hkgpMesh(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_iconvexoverlap = this->m_iconvexoverlap;
  v25.mStereo = 0i64;
  v25.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  *(_QWORD *)(v5 + 64) = m_iconvexoverlap;
  for ( i = this->m_vertices.m_used; i; i = i->m_next )
  {
    NewPool = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool **)(v5 + 16);
    if ( !NewPool || !NewPool->m_free )
      NewPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)(v5 + 16));
    if ( NewPool )
    {
      m_free = (unsigned __int64)NewPool->m_free;
      NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)m_free;
      *(_QWORD *)(m_free + 96) = NewPool;
      ++NewPool->m_used;
      *(hkVector4f *)(m_free + 16) = i->m_source;
      *(hkVector4f *)(m_free + 32) = i->m_position;
      *(hkVector4f *)(m_free + 48) = i->m_normal;
      *(hkVector4f *)(m_free + 64) = i->m_data;
      *(_DWORD *)(m_free + 80) = i->m_refs;
      *(_DWORD *)(m_free + 84) = i->m_tag;
      *(_QWORD *)(m_free + 8) = 0i64;
      *(_QWORD *)m_free = *(_QWORD *)(v5 + 24);
      v10 = *(_QWORD *)(v5 + 24);
      if ( v10 )
        *(_QWORD *)(v10 + 8) = m_free;
      ++*(_DWORD *)(v5 + 32);
      *(_QWORD *)(v5 + 24) = m_free;
    }
    else
    {
      m_free = 0i64;
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25.mStereo,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)i,
      m_free);
  }
  m_used = this->m_triangles.m_used;
  *(_QWORD *)&v25.mEnableStereo = 0i64;
  v25.mWidth = 0;
  for ( v25.mHeight = -1; m_used; m_used = m_used->m_next )
  {
    v12 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            (hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *)(v5 + 40),
            m_used);
    v13 = 3i64;
    m_vertices = v12->m_vertices;
    v15 = v12;
    v16 = (char *)m_used - (char *)v12;
    do
    {
      v17 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25.mStereo,
              *(unsigned __int64 *)((char *)m_vertices++ + v16),
              0i64);
      *(m_vertices - 1) = (hkgpMeshBase::Vertex *)v17;
      --v13;
    }
    while ( v13 );
    for ( j = 0; (int)j < 3; ++j )
    {
      v19 = 8i64 * (int)j + 40;
      if ( (*(unsigned __int64 *)((_BYTE *)&m_used->m_next + v19) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v21 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
                *(unsigned __int64 *)((char *)&m_used->m_next + v19),
                0i64);
        v22 = v21 & 3;
        v23 = v21 & 0xFFFFFFFFFFFFFFFCui64;
        if ( v23 )
        {
          *(hkgpMeshBase::Triangle **)((char *)&v15->m_next + v19) = (hkgpMeshBase::Triangle *)(v23 + v22);
          *(_QWORD *)(v23 + 8i64 * (int)v22 + 40) = (char *)v15 + j;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
            &result,
            (unsigned __int64)m_used + j);
        }
        else
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
            &hkContainerHeapAllocator::s_alloc,
            (unsigned __int64)m_used + j,
            (unsigned __int64)v15 + j);
        }
      }
      else
      {
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v20 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        }
        else
        {
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v20 = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        }
        *(hkgpMeshBase::Triangle **)((char *)&v15->m_next + v19) = (hkgpMeshBase::Triangle *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                                                            + v20);
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                    + 40) = (char *)v15 + j;
      }
    }
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
    &hkContainerHeapAllocator::s_alloc);
  _(&v25);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25.mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v25.mStereo);
  return (hkgpMesh *)v5;
}

// File Line: 1138
// RVA: 0xCC9550
void __fastcall hkgpMesh::append(hkgpMesh *this, hkgpMesh *other)
{
  hkgpMeshBase::Vertex *m_used; // rdi
  hkgpMesh *v4; // rax
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *p_m_vertices; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  unsigned __int64 m_free; // r9
  hkgpMeshBase::Vertex *v8; // rax
  hkgpMeshBase::Triangle *m_next; // r14
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // r13
  hkgpMeshBase::Triangle *v11; // rax
  __int64 v12; // rdi
  unsigned __int64 *m_vertices; // rbx
  hkgpMeshBase::Triangle *v14; // rbp
  unsigned __int64 v15; // rax
  unsigned int i; // ebx
  __int64 v17; // r12
  unsigned __int64 v18; // rax
  unsigned int v19; // r15d
  unsigned __int64 v20; // rsi
  AMD_HD3D v21; // [rsp+20h] [rbp-58h] BYREF
  hkResult result; // [rsp+88h] [rbp+10h] BYREF

  m_used = other->m_vertices.m_used;
  v4 = this;
  v21.mHeight = -1;
  v21.mStereo = 0i64;
  v21.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  *(_QWORD *)&v21.mEnableStereo = 0i64;
  v21.mWidth = 0;
  if ( m_used )
  {
    p_m_vertices = &this->m_vertices;
    do
    {
      m_firstPool = p_m_vertices->m_allocator.m_firstPool;
      if ( !p_m_vertices->m_allocator.m_firstPool || !m_firstPool->m_free )
        m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&p_m_vertices->m_allocator);
      if ( m_firstPool )
      {
        m_free = (unsigned __int64)m_firstPool->m_free;
        m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)m_free;
        *(_QWORD *)(m_free + 96) = m_firstPool;
        ++m_firstPool->m_used;
        *(hkVector4f *)(m_free + 16) = m_used->m_source;
        *(hkVector4f *)(m_free + 32) = m_used->m_position;
        *(hkVector4f *)(m_free + 48) = m_used->m_normal;
        *(hkVector4f *)(m_free + 64) = m_used->m_data;
        *(_DWORD *)(m_free + 80) = m_used->m_refs;
        *(_DWORD *)(m_free + 84) = m_used->m_tag;
        *(_QWORD *)(m_free + 8) = 0i64;
        *(_QWORD *)m_free = p_m_vertices->m_used;
        v8 = p_m_vertices->m_used;
        if ( v8 )
          v8->m_prev = (hkgpMeshBase::Vertex *)m_free;
        ++p_m_vertices->m_numUsed;
        p_m_vertices->m_used = (hkgpMeshBase::Vertex *)m_free;
      }
      else
      {
        m_free = 0i64;
      }
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21.mStereo,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)m_used,
        m_free);
      m_used = m_used->m_next;
    }
    while ( m_used );
    v4 = this;
  }
  m_next = other->m_triangles.m_used;
  if ( m_next )
  {
    p_m_triangles = &v4->m_triangles;
    do
    {
      v11 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
              p_m_triangles,
              m_next);
      v12 = 3i64;
      m_vertices = (unsigned __int64 *)v11->m_vertices;
      v14 = v11;
      do
      {
        v15 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21.mStereo,
                *m_vertices++,
                0i64);
        *(m_vertices - 1) = v15;
        --v12;
      }
      while ( v12 );
      for ( i = 0; (int)i < 3; ++i )
      {
        v17 = (int)i;
        if ( (v14->m_links[v17] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
        {
          v18 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
                  v14->m_links[v17],
                  0i64);
          v19 = v18 & 3;
          v20 = v18 & 0xFFFFFFFFFFFFFFFCui64;
          if ( (v18 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
              &result,
              (unsigned __int64)m_next + i);
            v14->m_links[v17] = v20 + v19;
            *(_QWORD *)(v20 + 8i64 * (int)v19 + 40) = (char *)v14 + i;
          }
          else
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)m_next + i,
              (unsigned __int64)v14 + i);
          }
        }
      }
      m_next = m_next->m_next;
    }
    while ( m_next );
  }
  hkgpMesh::invalidateConvexHull(this);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
    &hkContainerHeapAllocator::s_alloc);
  _(&v21);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21.mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v21.mStereo);
}

// File Line: 1174
// RVA: 0xCC97D0
void __fastcall hkgpMesh::invalidateConvexHull(hkgpMesh *this)
{
  hkgpConvexHull *m_convexHull; // rcx

  m_convexHull = this->m_convexHull;
  if ( m_convexHull )
    m_convexHull->vfptr->__vecDelDtor(m_convexHull, 1u);
  this->m_convexHull = 0i64;
}

// File Line: 1180
// RVA: 0xCC9810
char __fastcall hkgpMesh::rebuildConvexHull(hkgpMesh *this)
{
  _QWORD **Value; // rax
  hkgpConvexHull *v3; // rax
  hkgpConvexHull *v4; // rax
  hkgpConvexHull *m_convexHull; // rcx
  int m_capacityAndFlags; // r8d
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+20h] [rbp-28h] BYREF
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-18h] BYREF

  hkgpMesh::invalidateConvexHull(this);
  if ( this->m_vertices.m_numUsed <= 3 )
    return 1;
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  *(_WORD *)&config.m_buildIndices.m_bool = 257;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v3 )
    hkgpConvexHull::hkgpConvexHull(v3);
  else
    v4 = 0i64;
  this->m_convexHull = v4;
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 0x80000000;
  hkgpMesh::fetchPositions(this, &positions);
  hkgpConvexHull::build(this->m_convexHull, positions.m_data, positions.m_size, &config);
  if ( (unsigned int)hkgpConvexHull::getDimensions(this->m_convexHull) == 3 )
  {
    positions.m_size = 0;
    if ( positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        positions.m_data,
        16 * positions.m_capacityAndFlags);
    return 1;
  }
  m_convexHull = this->m_convexHull;
  if ( m_convexHull )
    m_convexHull->vfptr->__vecDelDtor(m_convexHull, 1u);
  m_capacityAndFlags = positions.m_capacityAndFlags;
  this->m_convexHull = 0i64;
  positions.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * m_capacityAndFlags);
  return 0;
}

// File Line: 1202
// RVA: 0xCC9960
// local variable allocation has failed, the output may be wrong!
void __fastcall hkgpMesh::rebuildTrianglesTree(hkgpMesh *this, float margin, double a3)
{
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *m_trianglesTree; // rbx
  int m_capacityAndFlags; // r8d
  hkgpMeshBase::Triangle *m_used; // rsi
  __m128 v7; // xmm11
  __m128 m_quad; // xmm3
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  unsigned __int64 m_firstFree; // r15
  hkcdDynamicTree::CodecRawUlong *m_data; // rcx
  unsigned __int64 v17; // r14
  hkcdDynamicTree::CodecRawUlong *v18; // rax
  unsigned __int64 m_root; // rdi
  __m128 v20; // xmm7
  __m128 v21; // xmm8
  unsigned __int64 v22; // r8
  __int64 v23; // rax
  __m128 *p_m_quad; // rdi
  __m128 *v25; // r8
  __m128 v26; // xmm9
  __m128 v27; // xmm10
  __int64 v28; // rdx
  __int64 v29; // rcx
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  float v39; // xmm4_4
  unsigned __int64 v40; // r11
  __int64 v41; // r9
  __int64 v42; // rax
  __m128 v43; // xmm1
  __int64 v44[2]; // [rsp+30h] [rbp-D0h]
  hkVector4f *vectorArray[4]; // [rsp+40h] [rbp-C0h] BYREF
  hkAabb aabbOut; // [rsp+60h] [rbp-A0h] BYREF
  hkResult result; // [rsp+130h] [rbp+30h] BYREF
  unsigned int v48; // [rsp+138h] [rbp+38h]
  hkResult v49; // [rsp+140h] [rbp+40h] BYREF
  hkResult v50; // [rsp+148h] [rbp+48h] BYREF

  v48 = LODWORD(margin);
  m_trianglesTree = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)this->m_trianglesTree;
  m_capacityAndFlags = m_trianglesTree->m_nodes.m_capacityAndFlags;
  m_trianglesTree->m_nodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      m_trianglesTree->m_nodes.m_data,
      m_capacityAndFlags << 6);
  m_trianglesTree->m_nodes.m_data = 0i64;
  m_trianglesTree->m_nodes.m_capacityAndFlags = 0x80000000;
  m_trianglesTree->m_firstFree = 0i64;
  m_trianglesTree->m_root = 0i64;
  *(_QWORD *)&m_trianglesTree->m_numLeaves = 0i64;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    m_trianglesTree,
    &result,
    2 * this->m_triangles.m_numUsed);
  m_used = this->m_triangles.m_used;
  v7 = _mm_shuffle_ps((__m128)v48, (__m128)v48, 0);
  if ( m_used )
  {
    result.m_enum = LODWORD(FLOAT_0_000099999997);
    do
    {
      m_quad = m_used->m_plane.m_quad;
      vectorArray[0] = &m_used->m_vertices[0]->m_position;
      vectorArray[1] = &m_used->m_vertices[1]->m_position;
      vectorArray[2] = &m_used->m_vertices[2]->m_position;
      if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) != 0
        || (v9 = _mm_mul_ps(m_quad, m_quad),
            *(float *)&a3 = 0.000099999997,
            *(__m128 *)&a3 = _mm_shuffle_ps(*(__m128 *)&a3, *(__m128 *)&a3, 0),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v9, v9, 170).m128_f32[0])
                                        - 1.0)) >> 1) >= *(float *)&a3) )
      {
        m_used->m_leafIdx = 0i64;
      }
      else
      {
        hkAabbUtil::calcAabb(vectorArray, 3, (const __m128i *)&aabbOut);
        *(_OWORD *)&a3 = 0i64;
        if ( v7.m128_f32[0] <= 0.0 )
        {
          result.m_enum = 1008981770;
          v10 = _mm_sub_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad);
          v11 = _mm_mul_ps(v10, v10);
          v12 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                  _mm_shuffle_ps(v11, v11, 170));
          v13 = _mm_rsqrt_ps(v12);
          *(__m128 *)&a3 = _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                               _mm_mul_ps(*(__m128 *)_xmm, v13)),
                             v12);
          v14 = _mm_mul_ps(
                  _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v12, (__m128)0i64), *(__m128 *)&a3), (__m128)xmmword_141A711B0),
                  _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0));
          aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, v14);
          aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, v14);
        }
        else
        {
          aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, v7);
          aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, v7);
        }
        if ( !m_trianglesTree->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            m_trianglesTree,
            &v49,
            1);
        m_firstFree = m_trianglesTree->m_firstFree;
        m_data = m_trianglesTree->m_nodes.m_data;
        v17 = m_firstFree << 6;
        m_trianglesTree->m_firstFree = m_trianglesTree->m_nodes.m_data[(__int64)(int)m_firstFree].m_aabb.m_min.m_quad.m128_u64[0];
        *(unsigned __int64 *)((char *)m_data->m_children + v17) = 0i64;
        *(unsigned __int64 *)((char *)&m_data->m_children[1] + v17) = (unsigned __int64)m_used;
        *(hkAabb *)((char *)&m_data->m_aabb + v17) = aabbOut;
        v18 = m_trianglesTree->m_nodes.m_data;
        m_root = m_trianglesTree->m_root;
        v20 = m_trianglesTree->m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad;
        v21 = m_trianglesTree->m_nodes.m_data[m_firstFree].m_aabb.m_max.m_quad;
        if ( m_root )
        {
          if ( !m_trianglesTree->m_firstFree )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              m_trianglesTree,
              &v50,
              1);
          v22 = m_trianglesTree->m_firstFree;
          v23 = (int)v22;
          p_m_quad = &m_trianglesTree->m_nodes.m_data[m_root].m_aabb.m_min.m_quad;
          v25 = &m_trianglesTree->m_nodes.m_data[v22].m_aabb.m_min.m_quad;
          m_trianglesTree->m_firstFree = m_trianglesTree->m_nodes.m_data[v23].m_aabb.m_min.m_quad.m128_u64[0];
          if ( p_m_quad[2].m128_i32[2] )
          {
            v26 = _mm_add_ps(v21, v20);
            v27 = _mm_sub_ps(v21, v20);
            do
            {
              v28 = (__int64)&m_trianglesTree->m_nodes.m_data[p_m_quad[2].m128_u64[1]];
              v29 = (__int64)&m_trianglesTree->m_nodes.m_data[p_m_quad[3].m128_u64[0]];
              v30 = _mm_max_ps(p_m_quad[1], v21);
              *p_m_quad = _mm_min_ps(*p_m_quad, v20);
              p_m_quad[1] = v30;
              v44[0] = v28;
              v44[1] = v29;
              v31 = *(__m128 *)(v28 + 16);
              v32 = *(__m128 *)(v29 + 16);
              v33 = _mm_add_ps(_mm_sub_ps(v31, *(__m128 *)v28), v27);
              v34 = _mm_sub_ps(_mm_add_ps(v31, *(__m128 *)v28), v26);
              v35 = _mm_add_ps(_mm_sub_ps(v32, *(__m128 *)v29), v27);
              v36 = _mm_sub_ps(_mm_add_ps(v32, *(__m128 *)v29), v26);
              v37 = _mm_mul_ps(v34, v34);
              v38 = _mm_mul_ps(v36, v36);
              v39 = (float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                  + _mm_shuffle_ps(v37, v37, 170).m128_f32[0];
              *(__m128 *)&a3 = _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                                   _mm_shuffle_ps(v38, v38, 170)),
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                                   _mm_shuffle_ps(v35, v35, 170)));
              p_m_quad = (__m128 *)v44[(float)(v39
                                             * (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v33, v33, 170).m128_f32[0])) > *(float *)&a3];
            }
            while ( p_m_quad[2].m128_i32[2] );
          }
          v40 = p_m_quad[2].m128_u64[0];
          v41 = ((char *)v25 - (char *)m_trianglesTree->m_nodes.m_data) >> 6;
          if ( v40 )
            m_trianglesTree->m_nodes.m_data[v40].m_children[m_trianglesTree->m_nodes.m_data[v40].m_children[1] == ((char *)p_m_quad - (char *)m_trianglesTree->m_nodes.m_data) >> 6] = v41;
          else
            m_trianglesTree->m_root = v41;
          v25[2].m128_u64[0] = p_m_quad[2].m128_u64[0];
          v42 = (char *)p_m_quad - (char *)m_trianglesTree->m_nodes.m_data;
          v25[3].m128_u64[0] = m_firstFree;
          v25[2].m128_u64[1] = v42 >> 6;
          p_m_quad[2].m128_u64[0] = v41;
          *(unsigned __int64 *)((char *)&m_trianglesTree->m_nodes.m_data->m_parent + v17) = v41;
          v43 = _mm_max_ps(p_m_quad[1], v21);
          *v25 = _mm_min_ps(*p_m_quad, v20);
          v25[1] = v43;
          ++m_trianglesTree->m_numLeaves;
          m_used->m_leafIdx = m_firstFree;
        }
        else
        {
          m_trianglesTree->m_root = m_firstFree;
          *(unsigned __int64 *)((char *)&v18->m_parent + v17) = 0i64;
          ++m_trianglesTree->m_numLeaves;
          m_used->m_leafIdx = m_firstFree;
        }
      }
      m_used = m_used->m_next;
    }
    while ( m_used );
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
    m_trianglesTree,
    m_trianglesTree->m_root,
    (hkBool)1,
    32,
    16);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(m_trianglesTree);
}

// File Line: 1235
// RVA: 0xCC9E90
void __fastcall hkgpMesh::appendToGeometry(hkgpMesh *this, hkGeometry *geom, bool flipOrientation)
{
  int m_numUsed; // edi
  int m_size; // r14d
  int v8; // eax
  int v9; // r9d
  int v10; // eax
  __int64 v11; // r12
  int v12; // r15d
  int v13; // r9d
  int v14; // eax
  hkVector4f *v15; // rdi
  int v16; // eax
  int v17; // r8d
  hkGeometry::Triangle *v18; // rbp
  hkgpMeshBase::Vertex *i; // rbx
  hkVector4f *v20; // rax
  hkgpMeshBase::Triangle *m_used; // rdi
  int *p_m_b; // rbx
  int v23; // eax
  int v24; // ecx
  AMD_HD3D v25; // [rsp+30h] [rbp-48h] BYREF
  hkResult result; // [rsp+80h] [rbp+8h] BYREF
  hkResult v27; // [rsp+98h] [rbp+20h] BYREF

  if ( this->m_triangles.m_numUsed > 0 )
  {
    m_numUsed = this->m_vertices.m_numUsed;
    m_size = geom->m_vertices.m_size;
    v8 = geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    v9 = m_size + m_numUsed;
    if ( v8 < m_size + m_numUsed )
    {
      v10 = 2 * v8;
      if ( v9 < v10 )
        v9 = v10;
      hkArrayUtil::_reserve(&v27, &hkContainerHeapAllocator::s_alloc, (const void **)&geom->m_vertices.m_data, v9, 16);
    }
    geom->m_vertices.m_size += m_numUsed;
    v11 = geom->m_triangles.m_size;
    v12 = this->m_triangles.m_numUsed;
    v13 = v11 + v12;
    v14 = geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    v15 = &geom->m_vertices.m_data[m_size];
    if ( v14 >= (int)v11 + v12 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v16 = 2 * v14;
      if ( v13 < v16 )
        v13 = v16;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&geom->m_triangles.m_data,
        v13,
        16);
    }
    geom->m_triangles.m_size += v12;
    v17 = this->m_vertices.m_numUsed;
    *(_QWORD *)&v25.mEnableStereo = 0i64;
    v25.mWidth = 0;
    v18 = &geom->m_triangles.m_data[v11];
    v25.mHeight = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
      &hkContainerHeapAllocator::s_alloc,
      v17 + 1);
    for ( i = this->m_vertices.m_used; i; i = i->m_next )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)i,
        m_size + (v25.mWidth & 0x7FFFFFFF));
      v20 = v15++;
      *v20 = i->m_position;
    }
    m_used = this->m_triangles.m_used;
    if ( m_used )
    {
      p_m_b = &v18->m_b;
      do
      {
        *(p_m_b - 1) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
                         (unsigned __int64)m_used->m_vertices[0],
                         0xFFFFFFFFFFFFFFFFui64);
        *p_m_b = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                   (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
                   (unsigned __int64)m_used->m_vertices[1],
                   0xFFFFFFFFFFFFFFFFui64);
        v23 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
                (unsigned __int64)m_used->m_vertices[2],
                0xFFFFFFFFFFFFFFFFui64);
        p_m_b[1] = v23;
        p_m_b[2] = m_used->m_material;
        if ( flipOrientation )
        {
          v24 = *p_m_b;
          *p_m_b = v23;
          p_m_b[1] = v24;
        }
        m_used = m_used->m_next;
        p_m_b += 4;
      }
      while ( m_used );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v25,
      &hkContainerHeapAllocator::s_alloc);
    _(&v25);
  }
}

// File Line: 1266
// RVA: 0xCCA0A0
void __fastcall hkgpMesh::appendFromGeometry(
        hkgpMesh *this,
        hkGeometry *geom,
        hkTransformf *xform,
        int partId,
        bool flipOrientation,
        bool removeInvalidTriangles)
{
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm2
  hkMatrix4f xforma; // [rsp+30h] [rbp-48h] BYREF

  v6.m_quad = (__m128)xform->m_translation;
  v7.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)xform->m_rotation.m_col1.m_quad, 4), 4);
  v8.m_quad = (__m128)xform->m_rotation.m_col2;
  xforma.m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)xform->m_rotation.m_col0.m_quad, 4), 4);
  xforma.m_col1 = (hkVector4f)v7.m_quad;
  xforma.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v8.m_quad, 4), 4);
  xforma.m_col3.m_quad = _mm_shuffle_ps(v6.m_quad, _mm_unpackhi_ps(v6.m_quad, query.m_quad), 196);
  hkgpMesh::appendFromGeometry(this, geom, &xforma, partId, flipOrientation, removeInvalidTriangles);
}

// File Line: 1273
// RVA: 0xCCA130
void __fastcall hkgpMesh::appendFromGeometry(
        hkgpMesh *this,
        hkGeometry *geom,
        hkMatrix4f *xform,
        char partId,
        bool flipOrientation,
        bool removeInvalidTriangles)
{
  int v6; // ebx
  int m_size; // ebx
  hkgpMeshBase::Triangle *v8; // r15
  hkgpMesh *v10; // rsi
  _QWORD *v11; // r10
  int v12; // edi
  __int64 v13; // rbx
  int *v14; // rdi
  int v15; // eax
  unsigned int v16; // edx
  int v17; // r9d
  __int64 v18; // rbx
  int *v19; // rdi
  int v20; // eax
  int v21; // eax
  const void **v22; // rcx
  __int64 v23; // rdx
  __int64 i; // rcx
  int v25; // edx
  __int64 v26; // rbx
  int *v27; // rdi
  int v28; // r8d
  int v29; // eax
  unsigned __int64 v30; // rcx
  __int64 v31; // rdx
  __int64 j; // rcx
  hkgpMesh *v33; // r10
  __int64 v34; // r14
  __int64 m_used_low; // r12
  int v36; // edi
  __m128 v37; // xmm1
  __m128 v38; // xmm6
  __int64 v39; // rdx
  unsigned __int64 v40; // r9
  __int64 v41; // r8
  __m128 **v42; // r9
  __m128 **v43; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // rdi
  hkgpMeshBase::Vertex *m_used; // rax
  __m128 **v47; // rcx
  __int128 v48; // xmm0
  int v49; // xmm1_4
  int v50; // edx
  unsigned __int64 v51; // rbx
  _QWORD *v52; // rcx
  __int64 v53; // rbx
  int *v54; // rdi
  int v55; // r8d
  hkgpMesh *v56; // r9
  hkResultEnum m_enum; // edi
  _QWORD *v58; // rdx
  __int64 v59; // r8
  __int64 v60; // rcx
  __m128 *v61; // r14
  hkgpMeshBase::Vertex *v62; // rbx
  hkgpMeshBase::Vertex *v63; // rsi
  hkgpMesh *v64; // r10
  __m128 m_quad; // xmm1
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  __m128 v67; // xmm0
  hkgpMeshBase::Triangle *v68; // rax
  int v69; // r12d
  __int64 v70; // rbx
  int v71; // r13d
  _QWORD *v72; // r14
  hkVector4f *v73; // rbx
  hkVector4f *v74; // rsi
  int v75; // edi
  int v76; // r8d
  int v77; // eax
  unsigned int v78; // r11d
  unsigned int v79; // eax
  int v80; // edi
  __int64 v81; // rdx
  const void **v82; // rax
  __int64 v83; // r10
  const void *v84; // r11
  hkVector4f **v85; // rax
  __int64 v86; // rdx
  int v87; // edi
  unsigned int v88; // edi
  const void **v89; // r14
  __int64 v90; // rdx
  __int64 v91; // rcx
  _QWORD *v92; // rdx
  __int64 v93; // rdi
  unsigned __int64 v94; // rax
  __int64 v95; // rcx
  const void *v96; // rax
  __int64 v97; // rdi
  unsigned __int64 v98; // rax
  hkgpMeshBase::Triangle *m_next; // rdi
  int v100; // eax
  __m128 v101; // xmm3
  int v102; // ecx
  int v103; // edi
  __int64 v104; // rdx
  __int64 v105; // r8
  __int64 v106; // r8
  __int64 v107; // r8
  int v108; // edi
  __int64 v109; // rbx
  __int64 v110; // rdx
  hkgpMeshBase::Triangle *v111; // rax
  hkgpMeshBase::Triangle *v112; // rcx
  __int64 v113; // rdx
  __int64 v115; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v116; // rax
  __int64 v117; // rcx
  __int64 v118; // rbx
  int *v119; // rdi
  int v120; // eax
  _QWORD *v121; // [rsp+30h] [rbp-C8h] BYREF
  int v122; // [rsp+38h] [rbp-C0h]
  int k; // [rsp+3Ch] [rbp-BCh]
  hkResult result; // [rsp+40h] [rbp-B8h] BYREF
  const void **v125; // [rsp+48h] [rbp-B0h] BYREF
  unsigned int v126; // [rsp+50h] [rbp-A8h]
  int v127; // [rsp+54h] [rbp-A4h]
  int v128; // [rsp+58h] [rbp-A0h]
  hkVector4f p; // [rsp+60h] [rbp-98h] BYREF
  int v130; // [rsp+70h] [rbp-88h]
  _QWORD *array; // [rsp+78h] [rbp-80h] BYREF
  int v132; // [rsp+80h] [rbp-78h]
  int v133; // [rsp+84h] [rbp-74h]
  __int64 v134; // [rsp+88h] [rbp-70h]
  int v135; // [rsp+90h] [rbp-68h]
  hkVector4f a; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f b; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f c; // [rsp+B8h] [rbp-40h] BYREF
  hkgpMesh *retaddr; // [rsp+118h] [rbp+20h]
  int v141; // [rsp+130h] [rbp+38h]

  v141 = v6;
  m_size = geom->m_vertices.m_size;
  v8 = 0i64;
  v10 = this;
  v133 = 0x80000000;
  v11 = 0i64;
  array = 0i64;
  v12 = 0;
  v132 = 0;
  v125 = 0i64;
  v126 = 0;
  v128 = 0;
  v127 = 0x80000000;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 8);
    v12 = v132;
    v11 = array;
  }
  if ( m_size - v12 > 0 )
    memset(&v11[v12], 0, 8i64 * (m_size - v12));
  v132 = m_size;
  v13 = (int)(v126 - 1);
  if ( (int)(v126 - 1) >= 0 )
  {
    v14 = (int *)&v125[2 * (int)(v126 - 1) + 1] + 1;
    do
    {
      v15 = *v14;
      *(v14 - 1) = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v14 - 3),
          40 * (v15 & 0x3FFFFFFF));
      *(_QWORD *)(v14 - 3) = 0i64;
      *v14 = 0x80000000;
      v14 -= 4;
      --v13;
    }
    while ( v13 >= 0 );
  }
  v16 = 0;
  v128 = 0;
  v126 = 0;
  if ( (v127 & 0x3FFFFFFFu) < 0x2011 )
  {
    v17 = 8209;
    if ( 2 * (v127 & 0x3FFFFFFF) > 8209 )
      v17 = 2 * (v127 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v125, v17, 16);
    v16 = v126;
  }
  v18 = (int)(v16 - 8210);
  if ( (int)(v16 - 8210) >= 0 )
  {
    v19 = (int *)&v125[2 * v18 + 16419] + 1;
    do
    {
      v20 = *v19;
      *(v19 - 1) = 0;
      if ( v20 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v19 - 3),
          40 * (v20 & 0x3FFFFFFF));
      *(_QWORD *)(v19 - 3) = 0i64;
      *v19 = 0x80000000;
      v19 -= 4;
      --v18;
    }
    while ( v18 >= 0 );
    v16 = v126;
  }
  v21 = 8209 - v16;
  v22 = &v125[2 * (int)v16];
  v23 = (int)(8209 - v16);
  if ( v21 > 0 )
  {
    do
    {
      if ( v22 )
      {
        *v22 = 0i64;
        *((_DWORD *)v22 + 2) = 0;
        *((_DWORD *)v22 + 3) = 0x80000000;
      }
      v22 += 2;
      --v23;
    }
    while ( v23 );
  }
  v126 = 8209;
  for ( i = 0i64; i < 16418; LODWORD(v125[i - 1]) = 0 )
    i += 2i64;
  p.m_quad.m128_u64[0] = 0i64;
  p.m_quad.m128_u64[1] = 0x8000000000000000ui64;
  v130 = 0;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p, 8209, 16);
  v25 = p.m_quad.m128_i32[2];
  v26 = p.m_quad.m128_i32[2] - 8210;
  if ( p.m_quad.m128_i32[2] - 8210 >= 0 )
  {
    v27 = (int *)(16 * v26 + p.m_quad.m128_u64[0] + 131356);
    do
    {
      v28 = *v27;
      *(v27 - 1) = 0;
      if ( v28 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v27 - 3),
          16 * v28);
      *(_QWORD *)(v27 - 3) = 0i64;
      *v27 = 0x80000000;
      v27 -= 4;
      --v26;
    }
    while ( v26 >= 0 );
    v25 = p.m_quad.m128_i32[2];
  }
  v29 = 8209 - v25;
  v30 = p.m_quad.m128_u64[0] + 16i64 * v25;
  v31 = 8209 - v25;
  if ( v29 > 0 )
  {
    do
    {
      if ( v30 )
      {
        *(_QWORD *)v30 = 0i64;
        *(_DWORD *)(v30 + 8) = 0;
        *(_DWORD *)(v30 + 12) = 0x80000000;
      }
      v30 += 16i64;
      --v31;
    }
    while ( v31 );
  }
  p.m_quad.m128_i32[2] = 8209;
  for ( j = 0i64; j < 131344; *(_DWORD *)(j + p.m_quad.m128_u64[0] - 8) = 0 )
    j += 16i64;
  v33 = this;
  v34 = 0i64;
  m_used_low = SLODWORD(this->m_vertices.m_used);
  if ( m_used_low > 0 )
  {
    do
    {
      v36 = 0;
      v37 = *(__m128 *)((char *)&v8->hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpMeshBase::BaseTriangle,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> >::Item
                      + (unsigned __int64)v33->m_vertices.m_allocator.m_firstPool);
      v38 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), xform->m_col0.m_quad), xform->m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), xform->m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), xform->m_col2.m_quad));
      LODWORD(v121) = v38.m128_i32[0];
      HIDWORD(v121) = _mm_shuffle_ps(v38, v38, 85).m128_u32[0];
      v122 = _mm_shuffle_ps(v38, v38, 170).m128_u32[0];
      v39 = 0i64;
      v40 = p.m_quad.m128_u64[0]
          + 16i64
          * (int)(((unsigned int)(1076768587 * v38.m128_i32[0]) ^ (unsigned __int64)((1077394133 * HIDWORD(v121)) ^ (unsigned int)(1921969139 * v122)))
                % p.m_quad.m128_u32[2]);
      v41 = *(int *)(v40 + 8);
      if ( v41 <= 0 )
        goto LABEL_43;
      v42 = *(__m128 ***)v40;
      v43 = v42;
      while ( (_mm_movemask_ps(_mm_cmpeq_ps(**v43, v38)) & 7) != 7 )
      {
        ++v39;
        ++v36;
        v43 += 2;
        if ( v39 >= v41 )
          goto LABEL_43;
      }
      if ( v36 == -1 || (v47 = &v42[2 * v36]) == 0i64 )
      {
LABEL_43:
        m_firstPool = v10->m_vertices.m_allocator.m_firstPool;
        if ( !m_firstPool || !m_firstPool->m_free )
        {
          m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v10->m_vertices.m_allocator);
          v33 = this;
        }
        if ( m_firstPool )
        {
          m_free = m_firstPool->m_free;
          m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
          m_free->m_pool = m_firstPool;
          ++m_firstPool->m_used;
          *(_QWORD *)&m_free->m_data[80] = -1i64;
          *(_QWORD *)&m_free->m_data[8] = 0i64;
          *(_QWORD *)m_free->m_data = v10->m_vertices.m_used;
          m_used = v10->m_vertices.m_used;
          if ( m_used )
            m_used->m_prev = (hkgpMeshBase::Vertex *)m_free;
          ++v10->m_vertices.m_numUsed;
          v10->m_vertices.m_used = (hkgpMeshBase::Vertex *)m_free;
        }
        else
        {
          m_free = 0i64;
        }
        v48 = *(__int128 *)((char *)&v8->hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpMeshBase::BaseTriangle,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> >::Item
                          + (unsigned __int64)v33->m_vertices.m_allocator.m_firstPool);
        *(__m128 *)&m_free->m_data[32] = v38;
        *(_OWORD *)&m_free->m_data[16] = v48;
        *(_OWORD *)&m_free->m_data[64] = 0i64;
        v49 = *(_DWORD *)&m_free->m_data[36];
        LODWORD(v134) = *(_DWORD *)&m_free->m_data[32];
        LODWORD(v48) = *(_DWORD *)&m_free->m_data[40];
        HIDWORD(v134) = v49;
        array[v34] = m_free;
        ++v130;
        v135 = v48;
        v50 = ((unsigned int)(1076768587 * v134) ^ (unsigned __int64)((1077394133 * HIDWORD(v134)) ^ (unsigned int)(1921969139 * v48)))
            % p.m_quad.m128_u32[2];
        v51 = p.m_quad.m128_u64[0] + 16i64 * v50;
        if ( *(_DWORD *)(v51 + 8) == (*(_DWORD *)(v51 + 12) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)(p.m_quad.m128_u64[0] + 16i64 * v50),
            16);
          v33 = this;
        }
        v52 = (_QWORD *)(*(_QWORD *)v51 + 16i64 * (int)(*(_DWORD *)(v51 + 8))++);
        *v52 = &m_free->m_data[32];
        v10 = retaddr;
        v52[1] = m_free;
      }
      else
      {
        array[v34] = v47[1];
      }
      ++v34;
      v8 = (hkgpMeshBase::Triangle *)((char *)v8 + 16);
    }
    while ( v34 < m_used_low );
    v8 = 0i64;
  }
  v53 = p.m_quad.m128_i32[2] - 1;
  if ( p.m_quad.m128_i32[2] - 1 >= 0 )
  {
    v54 = (int *)(16i64 * (p.m_quad.m128_i32[2] - 1) + p.m_quad.m128_u64[0] + 12);
    do
    {
      v55 = *v54;
      *(v54 - 1) = 0;
      if ( v55 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v54 - 3),
          16 * v55);
      *(_QWORD *)(v54 - 3) = 0i64;
      *v54 = 0x80000000;
      v54 -= 4;
      --v53;
    }
    while ( v53 >= 0 );
  }
  p.m_quad.m128_i32[2] = 0;
  if ( p.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)p.m_quad.m128_u64[0],
      16 * p.m_quad.m128_i32[3]);
  v56 = this;
  m_enum = HK_SUCCESS;
  result.m_enum = HK_SUCCESS;
  if ( SLODWORD(this->m_triangles.m_allocator.m_firstPool) > 0 )
  {
    v58 = array;
    v59 = 0i64;
    v134 = 0i64;
    while ( 1 )
    {
      v60 = *(_QWORD *)&v56->m_vertices.m_numUsed;
      v61 = (__m128 *)v58[*(int *)(v59 + v60)];
      v62 = (hkgpMeshBase::Vertex *)v58[*(int *)(v59 + v60 + 4)];
      v63 = (hkgpMeshBase::Vertex *)v58[*(int *)(v59 + v60 + 8)];
      if ( partId )
      {
        v62 = (hkgpMeshBase::Vertex *)v58[*(int *)(v59 + v60 + 8)];
        v63 = (hkgpMeshBase::Vertex *)v58[*(int *)(v59 + v60 + 4)];
      }
      if ( v61 != (__m128 *)v62 && v62 != v63 && v63 != (hkgpMeshBase::Vertex *)v61 )
        break;
LABEL_119:
      ++m_enum;
      v59 += 16i64;
      result.m_enum = m_enum;
      v134 = v59;
      if ( m_enum >= SLODWORD(v56->m_triangles.m_allocator.m_firstPool) )
        goto LABEL_120;
    }
    v64 = retaddr;
    m_quad = v62->m_position.m_quad;
    NewPool = retaddr->m_triangles.m_allocator.m_firstPool;
    a.m_quad = v61[2];
    v67 = v63->m_position.m_quad;
    b.m_quad = m_quad;
    c.m_quad = v67;
    if ( !NewPool || !NewPool->m_free )
    {
      NewPool = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&retaddr->m_triangles.m_allocator);
      v64 = retaddr;
      v59 = v134;
      v56 = this;
    }
    if ( NewPool )
    {
      v8 = (hkgpMeshBase::Triangle *)NewPool->m_free;
      NewPool->m_free = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *)v8->m_next;
      v8[1].m_next = (hkgpMeshBase::Triangle *)NewPool;
      ++NewPool->m_used;
      v8->m_prev = 0i64;
      v8->m_next = retaddr->m_triangles.m_used;
      v68 = retaddr->m_triangles.m_used;
      if ( v68 )
        v68->m_prev = v8;
      ++retaddr->m_triangles.m_numUsed;
      retaddr->m_triangles.m_used = v8;
    }
    v8->m_partId = v141;
    v8->m_links[0] = 0i64;
    v8->m_links[1] = 0i64;
    v8->m_links[2] = 0i64;
    v8->m_tag = 0i64;
    v8->m_material = *(_DWORD *)(v59 + *(_QWORD *)&v56->m_vertices.m_numUsed + 12);
    v8->m_vertices[0] = (hkgpMeshBase::Vertex *)v61;
    v8->m_vertices[1] = v62;
    v8->m_vertices[2] = v63;
    if ( !hkgpMesh::setPlane(v64, &a, &b, &c, &v8->m_plane, 1) )
      v8->m_plane = 0i64;
    v69 = 2;
    v70 = 16i64;
    v71 = 0;
    v72 = 0i64;
    v121 = 0i64;
    while ( 1 )
    {
      v73 = *(hkVector4f **)((char *)v8->m_vertices + v70);
      v74 = *(hkVector4f **)((char *)v72 + (_QWORD)v8 + 16);
      b.m_quad.m128_i32[2] = 0;
      a.m_quad.m128_u64[0] = (unsigned __int64)v73;
      a.m_quad.m128_u64[1] = (unsigned __int64)v74;
      c.m_quad.m128_i32[0] = 0;
      v75 = (int)v73;
      v76 = (int)v74;
      v77 = (int)v74;
      if ( (int)v73 > (int)v74 )
      {
        v75 = (int)v74;
        v77 = (int)v73;
      }
      v78 = v126;
      v79 = ((95564881 * v77) ^ (45564901 * v75)) % 5564887;
      v80 = 0;
      v81 = 0i64;
      v82 = &v125[2 * (int)(v79 % v126)];
      v83 = *((int *)v82 + 2);
      if ( v83 <= 0 )
      {
LABEL_96:
        v87 = (int)v73;
        if ( (int)v73 > (int)v74 )
        {
          v87 = (int)v74;
          v76 = (int)v73;
        }
        ++v128;
        v88 = ((95564881 * v76) ^ (45564901 * v87)) % 5564887;
        v89 = &v125[2 * (int)(v88 % v78)];
        if ( *((_DWORD *)v89 + 2) == (*((_DWORD *)v89 + 3) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v125[2 * (int)(v88 % v78)], 40);
        v90 = (__int64)*v89 + 40 * *((int *)v89 + 2);
        if ( v90 )
        {
          *(_QWORD *)v90 = 0i64;
          *(_QWORD *)(v90 + 8) = 0i64;
          *(_QWORD *)(v90 + 16) = 0i64;
          *(_DWORD *)(v90 + 24) = 0;
          *(_DWORD *)(v90 + 32) = 0;
        }
        v91 = *((int *)v89 + 2);
        v92 = *v89;
        v93 = 5 * v91;
        *((_DWORD *)v89 + 2) = v91 + 1;
        v94 = b.m_quad.m128_u64[1];
        v92[v93] = v73;
        v92[v93 + 1] = v74;
        v92[v93 + 2] = 0i64;
        v92[v93 + 3] = v94;
        v92[v93 + 4] = c.m_quad.m128_u64[0];
        v95 = 5i64 * (*((_DWORD *)v89 + 2) - 1);
        v96 = *v89;
        v72 = v121;
        v86 = (__int64)v96 + 8 * v95;
      }
      else
      {
        v84 = *v82;
        v85 = (hkVector4f **)*v82;
        while ( (v73 != *v85 || v74 != v85[1]) && (v73 != v85[1] || v74 != *v85) )
        {
          ++v81;
          ++v80;
          v85 += 5;
          if ( v81 >= v83 )
            goto LABEL_95;
        }
        if ( v80 == -1 || (v86 = (__int64)v84 + 40 * v80) == 0 )
        {
LABEL_95:
          v78 = v126;
          goto LABEL_96;
        }
      }
      if ( ++*(_DWORD *)(v86 + 32) == 1 )
        break;
      if ( *(_DWORD *)(v86 + 32) == 2 )
      {
        if ( v73 == *(hkVector4f **)(v86 + 8) && v74 == *(hkVector4f **)v86 )
        {
          v8->m_links[v69] = *(_QWORD *)(v86 + 16) + *(unsigned int *)(v86 + 24);
          v97 = *(_QWORD *)(v86 + 16);
          if ( v97 )
            *(_QWORD *)(v97 + 8i64 * *(int *)(v86 + 24) + 40) = (char *)v8 + (unsigned int)v69;
          if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
          {
            *(_QWORD *)(v86 + 16) = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
          }
          else
          {
            DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
            *(_QWORD *)(v86 + 16) = 0i64;
          }
          v98 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                + 1);
          goto LABEL_116;
        }
        hkgpMesh::reportInvalidEdgeWinding(retaddr, v73 + 2, v74 + 2);
      }
      else
      {
        hkgpMesh::reportDuplicatedEdge(retaddr, v73 + 2, v74 + 2);
      }
LABEL_117:
      v69 = v71;
      v70 = (__int64)v72++;
      ++v71;
      v121 = v72;
      if ( v71 >= 3 )
      {
        v58 = array;
        v59 = v134;
        m_enum = result.m_enum;
        v56 = this;
        v8 = 0i64;
        goto LABEL_119;
      }
    }
    p.m_quad.m128_i32[2] = v69;
    v98 = p.m_quad.m128_u64[1];
    *(_QWORD *)(v86 + 16) = v8;
LABEL_116:
    *(_QWORD *)(v86 + 24) = v98;
    goto LABEL_117;
  }
LABEL_120:
  if ( flipOrientation )
  {
    m_next = retaddr->m_triangles.m_used;
    v100 = 0;
    v121 = 0i64;
    v122 = 0;
    for ( k = 0x80000000; m_next; m_next = m_next->m_next )
    {
      if ( !hkgpMesh::setPlane(retaddr, m_next, &p, 1)
        || (_mm_movemask_ps(_mm_cmpunord_ps(p.m_quad, p.m_quad)) & 7) != 0
        || (v101 = _mm_mul_ps(p.m_quad, p.m_quad),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)(_mm_shuffle_ps(v101, v101, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v101, v101, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v101, v101, 170).m128_f32[0])
                                        - 1.0)) >> 1) >= _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0]) )
      {
        v102 = v122;
        if ( v122 == (k & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v121, 8);
          v102 = v122;
        }
        v121[v102] = m_next;
        v100 = ++v122;
      }
      else
      {
        v100 = v122;
      }
    }
    v103 = 0;
    if ( v100 > 0 )
    {
      v104 = 0i64;
      do
      {
        v105 = v121[v104];
        if ( (*(_QWORD *)(v105 + 40) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((*(_QWORD *)(v105 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v105 + 40) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v105 + 40) = 0i64;
        v106 = v121[v104];
        if ( (*(_QWORD *)(v106 + 48) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((*(_QWORD *)(v106 + 48) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v106 + 48) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v106 + 48) = 0i64;
        v107 = v121[v104];
        if ( (*(_QWORD *)(v107 + 56) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          *(_QWORD *)((*(_QWORD *)(v107 + 56) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v107 + 56) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v107 + 56) = 0i64;
        v100 = v122;
        ++v103;
        ++v104;
      }
      while ( v103 < v122 );
    }
    v108 = 0;
    if ( v100 > 0 )
    {
      v109 = 0i64;
      do
      {
        v110 = v121[v109];
        v111 = *(hkgpMeshBase::Triangle **)v110;
        v112 = *(hkgpMeshBase::Triangle **)(v110 + 8);
        if ( *(_QWORD *)v110 )
          v111->m_prev = v112;
        if ( v112 )
          v112->m_next = v111;
        else
          retaddr->m_triangles.m_used = v111;
        --retaddr->m_triangles.m_numUsed;
        v113 = *(_QWORD *)(v110 + 112);
        if ( (*(_DWORD *)(v113 + 4120))-- == 1 )
        {
          v115 = *(_QWORD *)(v113 + 4104);
          v116 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool **)(v113 + 4112);
          if ( v115 )
            *(_QWORD *)(v115 + 4112) = v116;
          else
            retaddr->m_triangles.m_allocator.m_firstPool = v116;
          v117 = *(_QWORD *)(v113 + 4112);
          if ( v117 )
            *(_QWORD *)(v117 + 4104) = *(_QWORD *)(v113 + 4104);
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, (void *)v113, 4128);
        }
        ++v108;
        ++v109;
      }
      while ( v108 < v122 );
    }
    v122 = 0;
    if ( k >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v121, 8 * k);
    hkgpMesh::removeOrphanVertices(retaddr);
  }
  hkgpMesh::invalidateConvexHull(retaddr);
  v118 = (int)(v126 - 1);
  if ( (int)(v126 - 1) >= 0 )
  {
    v119 = (int *)&v125[2 * (int)(v126 - 1) + 1] + 1;
    do
    {
      v120 = *v119;
      *(v119 - 1) = 0;
      if ( v120 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v119 - 3),
          40 * (v120 & 0x3FFFFFFF));
      *(_QWORD *)(v119 - 3) = 0i64;
      *v119 = 0x80000000;
      v119 -= 4;
      --v118;
    }
    while ( v118 >= 0 );
  }
  v126 = 0;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v125, 16 * v127);
  v125 = 0i64;
  v132 = 0;
  v127 = 0x80000000;
  if ( v133 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v133);
} )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v133);
}

// File Line: 1400
// RVA: 0xCCAF30
void __fastcall hkgpMesh::appendFromGeometryRaw(
        hkgpMesh *this,
        hkMatrix4f *geom,
        hkMatrix4f *xform,
        char flipOrientation)
{
  int v4; // ebx
  __m128i v5; // xmm0
  __m128i v6; // xmm2
  __m128i v7; // xmm1
  hkgpMesh *v8; // r15
  hkMatrix4f *v10; // r13
  char *v11; // rdx
  int v12; // ecx
  char *v13; // rdi
  int v14; // eax
  __int64 v15; // rcx
  __int64 v16; // rbx
  int *v17; // rdi
  int v18; // eax
  unsigned int v19; // edx
  int v20; // r9d
  __int64 v21; // rbx
  int *v22; // rdi
  int v23; // eax
  int v24; // eax
  const void **v25; // rcx
  __int64 v26; // rdx
  __int64 i; // rcx
  hkgpMesh *v28; // r8
  __int64 v29; // rcx
  __int64 v30; // r12
  int v31; // eax
  __int64 j; // rsi
  __int64 v33; // r14
  __m128 **v34; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // rdx
  hkgpMeshBase::Vertex *m_used; // rax
  __m128 *v38; // rax
  __m128 v39; // xmm1
  __int64 v40; // rbx
  __m128 *v41; // r14
  __m128 *v42; // rsi
  __m128 v43; // xmm6
  __int64 v44; // r12
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm5
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm4
  __m128 v53; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  __m128 v55; // xmm6
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // rdi
  __m128 v57; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v58; // r15
  hkgpMeshBase::Triangle *v59; // rax
  __int64 v60; // rdx
  int v61; // r13d
  int v62; // eax
  bool v63; // sf
  bool v64; // of
  int v65; // r12d
  int v66; // ecx
  __int64 v67; // rbx
  __int64 v68; // rsi
  hkVector4f *v69; // rsi
  hkVector4f *v70; // r14
  int v71; // edi
  int v72; // r8d
  int v73; // eax
  unsigned int v74; // r11d
  unsigned int v75; // eax
  int v76; // edi
  __int64 v77; // rdx
  const void **v78; // rax
  __int64 v79; // r10
  const void *v80; // r11
  hkVector4f **v81; // rax
  __int64 v82; // rdx
  int v83; // edi
  unsigned int v84; // edi
  const void **v85; // rbx
  __int64 v86; // rdx
  __int64 v87; // rcx
  _QWORD *v88; // rdx
  __int64 v89; // rdi
  __int64 v90; // rax
  __int64 v91; // rcx
  const void *v92; // rax
  __int64 v93; // rdi
  __int64 v94; // rax
  __int64 v95; // rbx
  int *v96; // rdi
  int v97; // eax
  bool v98; // [rsp+30h] [rbp-C8h]
  const void **v99; // [rsp+38h] [rbp-C0h] BYREF
  unsigned int v100; // [rsp+40h] [rbp-B8h]
  int v101; // [rsp+44h] [rbp-B4h]
  int v102; // [rsp+48h] [rbp-B0h]
  hkResult result; // [rsp+50h] [rbp-A8h] BYREF
  char *array; // [rsp+58h] [rbp-A0h] BYREF
  int v105; // [rsp+60h] [rbp-98h]
  int v106; // [rsp+64h] [rbp-94h]
  __int64 v107; // [rsp+68h] [rbp-90h]
  int v108; // [rsp+70h] [rbp-88h]
  int v109; // [rsp+74h] [rbp-84h]
  __int64 v110; // [rsp+78h] [rbp-80h]
  __m128 *v111; // [rsp+80h] [rbp-78h]
  __m128 *v112; // [rsp+88h] [rbp-70h]
  __m128 *v113; // [rsp+90h] [rbp-68h]
  hkVector4f *v114; // [rsp+98h] [rbp-60h]
  hkVector4f *v115; // [rsp+A0h] [rbp-58h]
  __int64 v116; // [rsp+B0h] [rbp-48h]
  __int64 v117; // [rsp+B8h] [rbp-40h]
  __int64 v118; // [rsp+C8h] [rbp-30h]
  hkgpMesh *retaddr; // [rsp+178h] [rbp+80h]
  char v122; // [rsp+190h] [rbp+98h]

  v122 = (char)xform;
  v4 = geom->m_col1.m_quad.m128_i32[2];
  v5 = (__m128i)_mm_sub_ps(xform->m_col3.m_quad, qi.m_vec.m_quad);
  v6 = (__m128i)_mm_sub_ps(xform->m_col2.m_quad, stru_141A71280.m_quad);
  v7 = (__m128i)_mm_sub_ps(xform->m_col1.m_quad, direction.m_quad);
  v8 = this;
  v10 = xform;
  v106 = 0x80000000;
  v101 = 0x80000000;
  v98 = _mm_movemask_ps(
          _mm_cmple_ps(
            _mm_max_ps(
              _mm_max_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(xform->m_col0.m_quad, transform.m_quad), 1u),
                          1u),
                (__m128)_mm_srli_epi32(_mm_slli_epi32(v7, 1u), 1u)),
              _mm_max_ps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u),
                (__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u))),
            *(__m128 *)&epsilon)) == 15;
  v11 = 0i64;
  v12 = 0;
  v99 = 0i64;
  v100 = 0;
  v102 = 0;
  array = 0i64;
  v105 = 0;
  if ( v4 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v4, 8);
    v12 = v105;
    v11 = array;
  }
  v13 = &v11[8 * v12];
  v14 = v4 - v12;
  v15 = v4 - v12;
  if ( v14 > 0 )
    memset(v13, 0, 8 * v15);
  v105 = v4;
  v16 = (int)(v100 - 1);
  if ( (int)(v100 - 1) >= 0 )
  {
    v17 = (int *)&v99[2 * (int)(v100 - 1) + 1] + 1;
    do
    {
      v18 = *v17;
      *(v17 - 1) = 0;
      if ( v18 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v17 - 3),
          40 * (v18 & 0x3FFFFFFF));
      *(_QWORD *)(v17 - 3) = 0i64;
      *v17 = 0x80000000;
      v17 -= 4;
      --v16;
    }
    while ( v16 >= 0 );
  }
  v19 = 0;
  v102 = 0;
  v100 = 0;
  if ( (v101 & 0x3FFFFFFFu) < 0x2011 )
  {
    v20 = 8209;
    if ( 2 * (v101 & 0x3FFFFFFF) > 8209 )
      v20 = 2 * (v101 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v99, v20, 16);
    v19 = v100;
  }
  v21 = (int)(v19 - 8210);
  if ( (int)(v19 - 8210) >= 0 )
  {
    v22 = (int *)&v99[2 * v21 + 16419] + 1;
    do
    {
      v23 = *v22;
      *(v22 - 1) = 0;
      if ( v23 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v22 - 3),
          40 * (v23 & 0x3FFFFFFF));
      *(_QWORD *)(v22 - 3) = 0i64;
      *v22 = 0x80000000;
      v22 -= 4;
      --v21;
    }
    while ( v21 >= 0 );
    v19 = v100;
  }
  v24 = 8209 - v19;
  v25 = &v99[2 * (int)v19];
  v26 = (int)(8209 - v19);
  if ( v24 > 0 )
  {
    do
    {
      if ( v25 )
      {
        *v25 = 0i64;
        *((_DWORD *)v25 + 2) = 0;
        *((_DWORD *)v25 + 3) = 0x80000000;
      }
      v25 += 2;
      --v26;
    }
    while ( v26 );
  }
  v100 = 8209;
  for ( i = 0i64; i < 16418; LODWORD(v99[i - 1]) = 0 )
    i += 2i64;
  v28 = this;
  result.m_enum = HK_SUCCESS;
  if ( SLODWORD(this->m_triangles.m_allocator.m_firstPool) > 0 )
  {
    v29 = 0i64;
    v110 = 0i64;
    while ( 1 )
    {
      v30 = *(_QWORD *)&v28->m_vertices.m_numUsed;
      v107 = v30;
      v108 = *(_DWORD *)(v29 + v30);
      if ( flipOrientation )
      {
        v109 = *(_DWORD *)(v29 + v30 + 8);
        v31 = *(_DWORD *)(v29 + v30 + 4);
      }
      else
      {
        v109 = *(_DWORD *)(v29 + v30 + 4);
        v31 = *(_DWORD *)(v29 + v30 + 8);
      }
      LODWORD(v110) = v31;
      v111 = 0i64;
      v112 = 0i64;
      v113 = 0i64;
      for ( j = 0i64; j < 3; *(&v110 + j) = (__int64)*v34 )
      {
        v33 = *(&v108 + j);
        v34 = (__m128 **)&array[8 * v33];
        if ( !*v34 )
        {
          m_firstPool = v8->m_vertices.m_allocator.m_firstPool;
          if ( !m_firstPool || !m_firstPool->m_free )
          {
            m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v8->m_vertices.m_allocator);
            v28 = this;
          }
          if ( m_firstPool )
          {
            m_free = m_firstPool->m_free;
            m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
            m_free->m_pool = m_firstPool;
            ++m_firstPool->m_used;
            *(_QWORD *)&m_free->m_data[80] = -1i64;
            *(_QWORD *)&m_free->m_data[8] = 0i64;
            *(_QWORD *)m_free->m_data = v8->m_vertices.m_used;
            m_used = v8->m_vertices.m_used;
            if ( m_used )
              m_used->m_prev = (hkgpMeshBase::Vertex *)m_free;
            ++v8->m_vertices.m_numUsed;
            v8->m_vertices.m_used = (hkgpMeshBase::Vertex *)m_free;
          }
          else
          {
            m_free = 0i64;
          }
          *v34 = (__m128 *)m_free;
          *(_OWORD *)&m_free->m_data[16] = *(_OWORD *)&v28->m_vertices.m_allocator.m_firstPool->m_items[0].m_data[16 * v33];
          (*v34)[4] = 0i64;
          v38 = *v34;
          if ( v98 )
          {
            v38[2] = v38[1];
          }
          else
          {
            v39 = v38[1];
            v38[2] = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v10->m_col0.m_quad), v10->m_col3.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), v10->m_col1.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), v10->m_col2.m_quad));
          }
          (*v34)[2] = _mm_shuffle_ps(
                        (*v34)[2],
                        _mm_unpackhi_ps((*v34)[2], _mm_shuffle_ps((*v34)[1], (*v34)[1], 255)),
                        196);
        }
        ++j;
      }
      v40 = (__int64)v111;
      v41 = v113;
      v42 = v112;
      v43 = v111[2];
      v44 = v107;
      v45 = _mm_sub_ps(v113[2], v43);
      v46 = _mm_sub_ps(v112[2], v43);
      v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v45));
      v48 = _mm_shuffle_ps(v47, v47, 201);
      v49 = _mm_mul_ps(v48, v48);
      v50 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
              _mm_shuffle_ps(v49, v49, 170));
      v51 = _mm_rsqrt_ps(v50);
      v52 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v50), (__m128)0i64);
      v53 = _mm_or_ps(
              _mm_and_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v50, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                      _mm_mul_ps(v51, *(__m128 *)_xmm))),
                  v48),
                v52),
              _mm_andnot_ps(v52, v48));
      if ( _mm_movemask_ps(v52) )
        break;
LABEL_92:
      flipOrientation = v122;
      v29 = v110 + 16;
      ++result.m_enum;
      v110 += 16i64;
      if ( result.m_enum >= SLODWORD(v28->m_triangles.m_allocator.m_firstPool) )
        goto LABEL_93;
    }
    NewPool = v8->m_triangles.m_allocator.m_firstPool;
    v55 = _mm_mul_ps(v43, v53);
    p_m_triangles = &v8->m_triangles;
    v57 = _mm_shuffle_ps(
            v53,
            _mm_unpackhi_ps(
              v53,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)))),
            196);
    if ( !NewPool || !NewPool->m_free )
    {
      NewPool = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v8->m_triangles.m_allocator);
      v28 = this;
    }
    if ( NewPool )
    {
      v58 = NewPool->m_free;
      NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v58->m_data;
      v58->m_pool = NewPool;
      ++NewPool->m_used;
      *(_QWORD *)&v58->m_data[8] = 0i64;
      *(_QWORD *)v58->m_data = p_m_triangles->m_used;
      v59 = p_m_triangles->m_used;
      if ( v59 )
        v59->m_prev = (hkgpMeshBase::Triangle *)v58;
      ++p_m_triangles->m_numUsed;
      p_m_triangles->m_used = (hkgpMeshBase::Triangle *)v58;
    }
    else
    {
      v58 = 0i64;
    }
    v60 = v110;
    v61 = 0;
    v62 = *(_DWORD *)(v110 + v44 + 4);
    v64 = __OFSUB__(*(_DWORD *)(v110 + v44), v62);
    v63 = *(_DWORD *)(v110 + v44) - v62 < 0;
    v65 = 2;
    *(_DWORD *)&v58->m_data[80] = v63 ^ v64;
    *(_QWORD *)&v58->m_data[40] = 0i64;
    *(_QWORD *)&v58->m_data[48] = 0i64;
    *(_QWORD *)&v58->m_data[56] = 0i64;
    v66 = *(_DWORD *)(v60 + *(_QWORD *)&v28->m_vertices.m_numUsed + 12);
    *(_QWORD *)&v58->m_data[96] = 0i64;
    *(_DWORD *)&v58->m_data[88] = v66;
    *(__m128 *)&v58->m_data[64] = v57;
    *(_QWORD *)&v58->m_data[16] = v40;
    v67 = 0i64;
    *(_QWORD *)&v58->m_data[24] = v42;
    *(_QWORD *)&v58->m_data[32] = v41;
    v107 = 0i64;
    v68 = 16i64;
    while ( 1 )
    {
      v69 = *(hkVector4f **)&v58->m_data[v68 + 16];
      v70 = *(hkVector4f **)&v58->m_data[v67 + 16];
      LODWORD(v116) = 0;
      v114 = v69;
      v115 = v70;
      LODWORD(v117) = 0;
      v71 = (int)v69;
      v72 = (int)v70;
      v73 = (int)v70;
      if ( (int)v69 > (int)v70 )
      {
        v71 = (int)v70;
        v73 = (int)v69;
      }
      v74 = v100;
      v75 = ((95564881 * v73) ^ (45564901 * v71)) % 5564887;
      v76 = 0;
      v77 = 0i64;
      v78 = &v99[2 * (int)(v75 % v100)];
      v79 = *((int *)v78 + 2);
      if ( v79 <= 0 )
      {
LABEL_69:
        v83 = (int)v69;
        if ( (int)v69 > (int)v70 )
        {
          v83 = (int)v70;
          v72 = (int)v69;
        }
        ++v102;
        v84 = ((95564881 * v72) ^ (45564901 * v83)) % 5564887;
        v85 = &v99[2 * (int)(v84 % v74)];
        if ( *((_DWORD *)v85 + 2) == (*((_DWORD *)v85 + 3) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v99[2 * (int)(v84 % v74)], 40);
        v86 = (__int64)*v85 + 40 * *((int *)v85 + 2);
        if ( v86 )
        {
          *(_QWORD *)v86 = 0i64;
          *(_QWORD *)(v86 + 8) = 0i64;
          *(_QWORD *)(v86 + 16) = 0i64;
          *(_DWORD *)(v86 + 24) = 0;
          *(_DWORD *)(v86 + 32) = 0;
        }
        v87 = *((int *)v85 + 2);
        v88 = *v85;
        v89 = 5 * v87;
        *((_DWORD *)v85 + 2) = v87 + 1;
        v90 = v116;
        v88[v89] = v69;
        v88[v89 + 1] = v70;
        v88[v89 + 2] = 0i64;
        v88[v89 + 3] = v90;
        v88[v89 + 4] = v117;
        v91 = 5i64 * (*((_DWORD *)v85 + 2) - 1);
        v92 = *v85;
        v67 = v107;
        v82 = (__int64)v92 + 8 * v91;
      }
      else
      {
        v80 = *v78;
        v81 = (hkVector4f **)*v78;
        while ( (v69 != *v81 || v70 != v81[1]) && (v69 != v81[1] || v70 != *v81) )
        {
          ++v77;
          ++v76;
          v81 += 5;
          if ( v77 >= v79 )
            goto LABEL_68;
        }
        if ( v76 == -1 || (v82 = (__int64)v80 + 40 * v76) == 0 )
        {
LABEL_68:
          v74 = v100;
          goto LABEL_69;
        }
      }
      if ( ++*(_DWORD *)(v82 + 32) == 1 )
        break;
      if ( *(_DWORD *)(v82 + 32) == 2 )
      {
        if ( v69 == *(hkVector4f **)(v82 + 8) && v70 == *(hkVector4f **)v82 )
        {
          *(_QWORD *)&v58->m_data[8 * v65 + 40] = *(_QWORD *)(v82 + 16) + *(unsigned int *)(v82 + 24);
          v93 = *(_QWORD *)(v82 + 16);
          if ( v93 )
            *(_QWORD *)(v93 + 8i64 * *(int *)(v82 + 24) + 40) = (char *)v58 + (unsigned int)v65;
          if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
          {
            *(_QWORD *)(v82 + 16) = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
          }
          else
          {
            DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
            *(_QWORD *)(v82 + 16) = 0i64;
          }
          v94 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                + 1);
          goto LABEL_89;
        }
        hkgpMesh::reportInvalidEdgeWinding(retaddr, v69 + 2, v70 + 2);
      }
      else
      {
        hkgpMesh::reportDuplicatedEdge(retaddr, v69 + 2, v70 + 2);
      }
LABEL_90:
      v65 = v61;
      v68 = v67;
      v67 += 8i64;
      ++v61;
      v107 = v67;
      if ( v61 >= 3 )
      {
        v8 = retaddr;
        v10 = geom;
        v28 = this;
        goto LABEL_92;
      }
    }
    LODWORD(v118) = v65;
    v94 = v118;
    *(_QWORD *)(v82 + 16) = v58;
LABEL_89:
    *(_QWORD *)(v82 + 24) = v94;
    goto LABEL_90;
  }
LABEL_93:
  hkgpMesh::invalidateConvexHull(v8);
  v95 = (int)(v100 - 1);
  if ( (int)(v100 - 1) >= 0 )
  {
    v96 = (int *)&v99[2 * (int)(v100 - 1) + 1] + 1;
    do
    {
      v97 = *v96;
      *(v96 - 1) = 0;
      if ( v97 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v96 - 3),
          40 * (v97 & 0x3FFFFFFF));
      *(_QWORD *)(v96 - 3) = 0i64;
      *v96 = 0x80000000;
      v96 -= 4;
      --v95;
    }
    while ( v95 >= 0 );
  }
  v100 = 0;
  if ( v101 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v99, 16 * v101);
  v99 = 0i64;
  v105 = 0;
  v101 = 0x80000000;
  if ( v106 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v106);
}

// File Line: 1483
// RVA: 0xCCB9A0
void __fastcall hkgpMesh::appendFromConvexHull(hkgpMesh *this, hkgpConvexHull *hull)
{
  hkGeometry geometry; // [rsp+30h] [rbp-38h] BYREF

  geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
  geometry.m_vertices.m_data = 0i64;
  geometry.m_vertices.m_size = 0;
  geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  geometry.m_triangles.m_data = 0i64;
  geometry.m_triangles.m_size = 0;
  geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  hkgpConvexHull::generateGeometry(hull, SOURCE_VERTICES, &geometry, -1, 1);
  hkgpMesh::appendFromGeometry(this, &geometry, (hkTransformf *)&transform, -1, 0, 1);
  geometry.m_triangles.m_size = 0;
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

// File Line: 1491
// RVA: 0xCCBF80
void __fastcall hkgpMesh::setPartId(hkgpMesh *this, int pid)
{
  hkgpMeshBase::Triangle *i; // rax

  for ( i = this->m_triangles.m_used; i; i = i->m_next )
    i->m_partId = pid;
}

// File Line: 1500
// RVA: 0xCCBFB0
void __fastcall hkgpMesh::setVerticesData(hkgpMesh *this, int index, float value)
{
  hkgpMeshBase::Vertex *i; // rax

  for ( i = this->m_vertices.m_used; i; i = i->m_next )
    i->m_data.m_quad.m128_f32[index] = value;
}

// File Line: 1509
// RVA: 0xCCBFE0
void __fastcall hkgpMesh::setVerticesTag(hkgpMesh *this, int tag)
{
  hkgpMeshBase::Vertex *i; // rax

  for ( i = this->m_vertices.m_used; i; i = i->m_next )
    i->m_tag = tag;
}

// File Line: 1518
// RVA: 0xCCC010
void __fastcall hkgpMesh::copyPartIdToVerticesW(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *i; // rax

  for ( i = this->m_triangles.m_used; i; i = i->m_next )
  {
    i->m_vertices[0]->m_position.m_quad.m128_i32[3] = i->m_partId | 0x3F000000;
    i->m_vertices[1]->m_position.m_quad.m128_i32[3] = i->m_partId | 0x3F000000;
    i->m_vertices[2]->m_position.m_quad.m128_i32[3] = i->m_partId | 0x3F000000;
  }
}

// File Line: 1530
// RVA: 0xCCC060
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkgpMesh::setPartIdAsConvexQuads(hkgpMesh *this, float minCosAngle, __int64 a3, double a4)
{
  hkgpMeshBase::Triangle *m_used; // rax
  char *v5; // rdx
  char *v7; // rcx
  hkgpMeshBase::Triangle *v8; // r9
  unsigned int v9; // ebx
  hkgpMeshBase::Vertex *v10; // rax
  int v11; // edx
  float *m128_f32; // rcx
  float v13; // xmm0_4
  hkgpMeshBase::Triangle *m_triangle; // r10
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v15; // rax
  signed int m_index; // edi
  float v17; // xmm6_4
  __m128 *v18; // r11
  __m128 m_quad; // xmm5
  __m128 v20; // xmm1
  __m128 *v21; // r8
  __m128 v22; // xmm1
  __m128 *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  float v31; // xmm0_4
  __m128 v32; // xmm4
  __m128 v33; // xmm4
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v34; // rax
  hkgpMeshBase::Triangle *m_next; // rcx
  char *v36; // rax
  char *v37; // rdx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v39; // [rsp+20h] [rbp-38h] BYREF
  char v40; // [rsp+60h] [rbp+8h] BYREF
  float v41; // [rsp+68h] [rbp+10h]

  v41 = minCosAngle;
  m_used = this->m_triangles.m_used;
  v5 = &v40;
  if ( !m_used )
    v5 = 0i64;
  if ( v5 )
  {
    do
    {
      m_used->m_partId = -1;
      m_used = m_used->m_next;
      v7 = &v40;
      if ( !m_used )
        v7 = 0i64;
    }
    while ( v7 );
  }
  v8 = this->m_triangles.m_used;
  v39.m_edge.m_index = 0;
  v9 = 0;
  v39.m_edge.m_triangle = v8;
  if ( v8 )
  {
    v10 = v8->m_vertices[1];
    v11 = 0;
    m128_f32 = v10->m_position.m_quad.m128_f32;
    do
    {
      v13 = *(float *)((char *)m128_f32 + (char *)v8->m_vertices[0] - (char *)v10);
      if ( v13 < *m128_f32 )
        break;
      if ( v13 > *m128_f32 )
      {
        if ( (v8->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v39);
        break;
      }
      ++v11;
      ++m128_f32;
    }
    while ( v11 < 3 );
  }
  m_triangle = v39.m_edge.m_triangle;
  v15 = &v39;
  if ( !v39.m_edge.m_triangle )
    v15 = 0i64;
  if ( v15 )
  {
    m_index = v39.m_edge.m_index;
    v17 = v41;
    do
    {
      v18 = (__m128 *)(m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64);
      if ( v18 )
      {
        if ( m_triangle->m_partId == -1 && v18[5].m128_i32[0] == -1 )
        {
          m_quad = m_triangle->m_plane.m_quad;
          *(float *)&a4 = v17;
          *(__m128 *)&a4 = _mm_shuffle_ps(*(__m128 *)&a4, *(__m128 *)&a4, 0);
          v20 = _mm_mul_ps(v18[4], m_quad);
          if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                     + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) >= *(float *)&a4 )
          {
            v21 = (__m128 *)m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3];
            v22 = _mm_sub_ps(
                    m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3]->m_position.m_quad,
                    v21[2]);
            v23 = *(__m128 **)((m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64)
                             + 8 * ((18i64 >> (2 * ((unsigned __int8)m_triangle->m_links[m_index] & 3u))) & 3)
                             + 16);
            v24 = _mm_sub_ps(v23[2], v21[2]);
            v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v24);
            v26 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22);
            v27 = _mm_sub_ps(m_triangle->m_vertices[m_index]->m_position.m_quad, v23[2]);
            v28 = _mm_sub_ps(v25, v26);
            v29 = _mm_sub_ps(v21[2], v23[2]);
            v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), m_quad);
            v31 = _mm_shuffle_ps(v30, v30, 0).m128_f32[0];
            v32 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v29),
                    _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v27));
            v27.m128_f32[0] = _mm_shuffle_ps(v30, v30, 85).m128_f32[0];
            *(__m128 *)&a4 = _mm_shuffle_ps(v30, v30, 170);
            if ( (float)((float)(v27.m128_f32[0] + v31) + *(float *)&a4) > 0.0 )
            {
              v33 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), m_quad);
              if ( (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
                         + _mm_shuffle_ps(v33, v33, 170).m128_f32[0]) > 0.0 )
              {
                v18[5].m128_i32[0] = v9;
                m_triangle->m_partId = v9++;
              }
            }
          }
        }
      }
      if ( m_triangle )
      {
        hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v39);
        m_index = v39.m_edge.m_index;
        m_triangle = v39.m_edge.m_triangle;
      }
      v34 = &v39;
      if ( !m_triangle )
        v34 = 0i64;
    }
    while ( v34 );
  }
  m_next = this->m_triangles.m_used;
  v36 = &v40;
  if ( !m_next )
    v36 = 0i64;
  if ( v36 )
  {
    do
    {
      if ( m_next->m_partId == -1 )
        m_next->m_partId = v9++;
      m_next = m_next->m_next;
      v37 = &v40;
      if ( !m_next )
        v37 = 0i64;
    }
    while ( v37 );
  }
  return v9;
}

// File Line: 1572
// RVA: 0xCCC320
void __fastcall hkgpMesh::assignVertexNormals(hkgpMesh *this)
{
  hkgpMeshBase::Vertex *i; // rax
  hkgpMeshBase::Triangle *m_used; // r9
  __m128 v4; // xmm12
  __m128 v5; // xmm9
  __m128 **m_vertices; // rdx
  __m128 m_quad; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm8
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __int128 *v28; // rcx
  __int64 v29; // r8
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm8
  __m128 v33; // xmm7
  __m128 v34; // xmm12
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm7
  __m128 v38; // xmm6
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm9
  __m128 v45; // xmm7
  __m128 v46; // xmm2
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  const __m128i *j; // rcx
  __m128 v55; // xmm6
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm5
  __int128 v60[3]; // [rsp+10h] [rbp-D8h] BYREF

  for ( i = this->m_vertices.m_used; i; i = i->m_next )
    i->m_normal = 0i64;
  m_used = this->m_triangles.m_used;
  v4 = (__m128)xmmword_141A710D0;
  if ( m_used )
  {
    v5 = (__m128)_xmm;
    do
    {
      m_vertices = (__m128 **)m_used->m_vertices;
      m_quad = m_used->m_vertices[1]->m_position.m_quad;
      v8 = m_used->m_vertices[2]->m_position.m_quad;
      v9 = _mm_sub_ps(m_used->m_vertices[0]->m_position.m_quad, m_quad);
      v10 = _mm_sub_ps(m_quad, v8);
      v11 = _mm_sub_ps(v8, m_used->m_vertices[0]->m_position.m_quad);
      v12 = _mm_mul_ps(v9, v9);
      v13 = _mm_mul_ps(v10, v10);
      v14 = _mm_mul_ps(v11, v11);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_andnot_ps(
              _mm_cmple_ps(v15, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v16), v16)),
                  _mm_mul_ps(*(__m128 *)_xmm, v16)),
                v15));
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170));
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_andnot_ps(
              _mm_cmple_ps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v19), v19)),
                  _mm_mul_ps(*(__m128 *)_xmm, v19)),
                v18));
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v22 = _mm_rsqrt_ps(v21);
      v23 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
              _mm_mul_ps(*(__m128 *)_xmm, v22));
      v24 = _mm_mul_ps(v17, v17);
      v25 = _mm_mul_ps(v20, v20);
      v26 = _mm_andnot_ps(_mm_cmple_ps(v21, (__m128)0i64), _mm_mul_ps(v23, v21));
      v27 = _mm_mul_ps(v26, v26);
      v28 = v60;
      v29 = 3i64;
      v30 = _mm_sub_ps(_mm_add_ps(v27, v24), v25);
      v31 = _mm_mul_ps(v17, v4);
      v32 = _mm_mul_ps(v31, v20);
      v33 = _mm_mul_ps(v20, v4);
      v34 = m_used->m_plane.m_quad;
      v35 = _mm_mul_ps(v31, v26);
      v36 = _mm_sub_ps(_mm_add_ps(v25, v24), v27);
      v37 = _mm_mul_ps(v33, v26);
      v38 = _mm_sub_ps(_mm_add_ps(v27, v25), v24);
      v39 = _mm_rcp_ps(v35);
      v40 = _mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v39, v35)), v39);
      v41 = _mm_rcp_ps(v32);
      v60[0] = (__int128)_mm_mul_ps(v40, v30);
      v42 = _mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v41, v32)), v41);
      v43 = _mm_rcp_ps(v37);
      v60[1] = (__int128)_mm_mul_ps(v42, v36);
      v60[2] = (__int128)_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v43, v37)), v43), v38);
      do
      {
        v44 = (__m128)*v28;
        if ( COERCE_FLOAT(*v28) > (float)(0.0 - 1.0) && v44.m128_f32[0] < 1.0 )
        {
          v45 = _mm_andnot_ps(*(__m128 *)_xmm, v44);
          v46 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v45), *(__m128 *)_xmm);
          v47 = _mm_cmplt_ps(*(__m128 *)_xmm, v45);
          v48 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v46), v47), _mm_andnot_ps(v47, v45));
          v49 = _mm_or_ps(_mm_andnot_ps(v47, _mm_mul_ps(v45, v45)), _mm_and_ps(v47, v46));
          v50 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v49, *(__m128 *)coeff4), *(__m128 *)coeff3), v49),
                                *(__m128 *)coeff2),
                              v49),
                            *(__m128 *)coeff1),
                          v49),
                        *(__m128 *)coeff0),
                      v49),
                    v48),
                  v48);
          v51 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v50, v50)), v47);
          v52 = _mm_andnot_ps(v47, v50);
          v53 = _mm_cmplt_ps(v45, *(__m128 *)_xmm);
          (*m_vertices)[3] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps(
                                   *(__m128 *)_xmm,
                                   _mm_xor_ps(
                                     _mm_or_ps(_mm_andnot_ps(v53, _mm_or_ps(v51, v52)), _mm_and_ps(v53, v45)),
                                     _mm_and_ps(v44, *(__m128 *)_xmm))),
                                 v34),
                               (*m_vertices)[3]);
        }
        ++m_vertices;
        ++v28;
        --v29;
      }
      while ( v29 );
      m_used = m_used->m_next;
      v5 = (__m128)_xmm;
      v4 = (__m128)xmmword_141A710D0;
    }
    while ( m_used );
  }
  for ( j = (const __m128i *)this->m_vertices.m_used; j; j = (const __m128i *)j->m128i_i64[0] )
  {
    v55 = (__m128)j[3];
    v56 = _mm_mul_ps(v55, v55);
    v57 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
            _mm_shuffle_ps(v56, v56, 170));
    v58 = _mm_rsqrt_ps(v57);
    v59 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v57), (__m128)0i64);
    j[3] = (const __m128i)_mm_or_ps(
                            _mm_and_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v57, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
                                    _mm_mul_ps(v58, *(__m128 *)_xmm))),
                                v55),
                              v59),
                            _mm_andnot_ps(v59, v55));
    if ( !_mm_movemask_ps(v59) )
      j[3] = 0i64;
    j[3] = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(j + 3), 4), 4);
  }
  this->m_hasPerVertexNormals = 1;
}

// File Line: 1640
// RVA: 0xCCC7B0
void __fastcall hkgpMesh::fetchAreaSortedTriangles(
        hkgpMesh *this,
        hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles,
        bool resetPlaneId)
{
  int m_capacityAndFlags; // eax
  int m_numUsed; // r9d
  hkgpMeshBase::Triangle *i; // rdx
  int m_size; // r8d
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_capacityAndFlags = triangles->m_capacityAndFlags;
  triangles->m_size = 0;
  m_numUsed = this->m_triangles.m_numUsed;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < m_numUsed )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&triangles->m_data, m_numUsed, 8);
  for ( i = this->m_triangles.m_used; i; i = i->m_next )
  {
    if ( resetPlaneId )
      i->m_planeId = -1;
    triangles->m_data[triangles->m_size++] = i;
  }
  m_size = triangles->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkgpMeshBase::Triangle *,hkgpMesh::SortByArea>(triangles->m_data, 0, m_size - 1, 0);
}

// File Line: 1653
// RVA: 0xCCC860
void __fastcall hkgpMesh::appendConcaveEdges(hkgpMesh *this, float minConcavity, float extrusion, hkgpMesh *mesh)
{
  unsigned int v4; // ebx
  int m_numUsed; // eax
  int v8; // r9d
  hkgpMeshBase::Triangle *i; // rbx
  int j; // edi
  hkgpMeshBase::Vertex *v11; // r8
  int v12; // edx
  hkgpMeshBase::Vertex *v13; // rcx
  signed __int64 v14; // r8
  float *m128_f32; // rax
  float v16; // xmm0_4
  hkgpMeshBase::Triangle **v17; // rcx
  hkgpMeshBase::Triangle *v18; // rax
  int v19; // ebx
  int v20; // r9d
  __m128 v21; // xmm10
  __int64 v22; // r9
  __int64 v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm9
  __m128 v26; // xmm7
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  int v35; // r12d
  __m128 v36; // xmm8
  float v37; // xmm9_4
  __int64 v38; // r15
  __int64 v39; // rcx
  __int64 v40; // r8
  __m128 *v41; // rdx
  __m128 *v42; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  __m128 v44; // xmm6
  __m128 v45; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // rdi
  hkgpMeshBase::Vertex *m_used; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v49; // rsi
  hkgpMeshBase::Vertex *v50; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v51; // rax
  hkgpMeshBase::Triangle *v52; // rbx
  hkgpMeshBase::Triangle *v53; // rax
  __int64 v54; // rcx
  __int64 v55; // rax
  __int64 v56; // rcx
  __int64 v57; // rax
  __int64 v58; // rdx
  __int64 v59; // rax
  char *array; // [rsp+28h] [rbp-79h] BYREF
  int v61; // [rsp+30h] [rbp-71h]
  int v62; // [rsp+34h] [rbp-6Dh]
  char *v63; // [rsp+38h] [rbp-69h] BYREF
  int v64; // [rsp+40h] [rbp-61h]
  int v65; // [rsp+44h] [rbp-5Dh]
  hkgpMeshBase::Edge v66; // [rsp+48h] [rbp-59h]
  hkgpMeshBase::Edge v67; // [rsp+58h] [rbp-49h] BYREF
  hkSimdFloat32 v68; // [rsp+68h] [rbp-39h] BYREF
  unsigned int v69; // [rsp+110h] [rbp+6Fh]
  hkResult result; // [rsp+120h] [rbp+7Fh] BYREF

  result.m_enum = LODWORD(extrusion);
  v69 = v4;
  v62 = 0x80000000;
  v65 = 0x80000000;
  m_numUsed = mesh->m_triangles.m_numUsed;
  array = 0i64;
  v61 = 0;
  v8 = 3 * m_numUsed;
  v63 = 0i64;
  v64 = 0;
  if ( 3 * m_numUsed > 0 )
  {
    if ( v8 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v8, 16);
  }
  for ( i = mesh->m_triangles.m_used; i; i = i->m_next )
  {
    for ( j = 0; j < 3; ++j )
    {
      v11 = i->m_vertices[j];
      v66.m_triangle = i;
      v66.m_index = j;
      v12 = 0;
      v13 = i->m_vertices[(9i64 >> (2 * (unsigned __int8)j)) & 3];
      v14 = (char *)v11 - (char *)v13;
      m128_f32 = v13->m_position.m_quad.m128_f32;
      do
      {
        v16 = *(float *)((char *)m128_f32 + v14);
        if ( v16 < *m128_f32 )
          break;
        if ( v16 > *m128_f32 )
        {
          if ( (i->m_links[j] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            goto LABEL_20;
          break;
        }
        ++v12;
        ++m128_f32;
      }
      while ( v12 < 3 );
      if ( (i->m_links[j] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v67 = v66;
        if ( COERCE_FLOAT(*hkgpMesh::tetrahedronVolume6(&v68, &v67)) > 0.0 )
        {
          if ( v61 == (v62 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v17 = (hkgpMeshBase::Triangle **)&array[16 * v61];
          if ( v17 )
          {
            v18 = *(hkgpMeshBase::Triangle **)&v66.m_index;
            *v17 = i;
            v17[1] = v18;
          }
          ++v61;
        }
      }
LABEL_20:
      ;
    }
  }
  v19 = v61;
  if ( (v65 & 0x3FFFFFFF) < v61 )
  {
    v20 = v61;
    if ( v61 < 2 * (v65 & 0x3FFFFFFF) )
      v20 = 2 * (v65 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v63, v20, 16);
  }
  v64 = v19;
  v21 = 0i64;
  v22 = 0i64;
  if ( v61 > 0 )
  {
    v23 = 0i64;
    do
    {
      v22 = (unsigned int)(v22 + 1);
      v23 += 16i64;
      v24 = _mm_mul_ps(
              *(__m128 *)((*(_QWORD *)(*(_QWORD *)&array[v23 - 16] + 8i64 * *(int *)&array[v23 - 8] + 40) & 0xFFFFFFFFFFFFFFFCui64)
                        + 64),
              *(__m128 *)(*(_QWORD *)&array[v23 - 16] + 64i64));
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
              _mm_shuffle_ps(v24, v24, 170));
      v26 = _mm_andnot_ps(*(__m128 *)_xmm, v25);
      v27 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v26), *(__m128 *)_xmm);
      v28 = _mm_cmplt_ps(*(__m128 *)_xmm, v26);
      v29 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v27), v28), _mm_andnot_ps(v28, v26));
      v30 = _mm_or_ps(_mm_andnot_ps(v28, _mm_mul_ps(v26, v26)), _mm_and_ps(v28, v27));
      v31 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v30, *(__m128 *)coeff4), *(__m128 *)coeff3), v30),
                            *(__m128 *)coeff2),
                          v30),
                        *(__m128 *)coeff1),
                      v30),
                    *(__m128 *)coeff0),
                  v30),
                v29),
              v29);
      v32 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v31, v31)), v28);
      v33 = _mm_andnot_ps(v28, v31);
      v34 = _mm_cmplt_ps(v26, *(__m128 *)_xmm);
      *(__m128 *)&v63[v23 - 16] = _mm_sub_ps(
                                    *(__m128 *)_xmm,
                                    _mm_xor_ps(
                                      _mm_or_ps(_mm_andnot_ps(v34, _mm_or_ps(v32, v33)), _mm_and_ps(v34, v26)),
                                      _mm_and_ps(v25, *(__m128 *)_xmm)));
      v21 = _mm_max_ps(*(__m128 *)&v63[v23 - 16], v21);
    }
    while ( (int)v22 < v61 );
  }
  v35 = 0;
  v36 = _mm_shuffle_ps((__m128)LODWORD(minConcavity), (__m128)LODWORD(minConcavity), 0);
  LODWORD(v37) = _mm_shuffle_ps((__m128)v69, (__m128)v69, 0).m128_u32[0];
  if ( v61 > 0 )
  {
    v38 = 0i64;
    do
    {
      if ( (float)(*(float *)&v63[v38] / v21.m128_f32[0]) > v37 )
      {
        v39 = *(_QWORD *)&array[v38 + 8];
        v40 = *(_QWORD *)&array[v38];
        v41 = *(__m128 **)(v40 + 8i64 * (int)v39 + 16);
        v42 = *(__m128 **)(v40 + 8 * ((9i64 >> (2 * (unsigned __int8)v39)) & 3) + 16);
        m_firstPool = this->m_vertices.m_allocator.m_firstPool;
        v44 = _mm_add_ps(v41[2], _mm_mul_ps(v41[3], v36));
        v45 = _mm_add_ps(v42[2], _mm_mul_ps(v42[3], v36));
        if ( !m_firstPool || !m_firstPool->m_free )
          m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_vertices.m_allocator);
        if ( m_firstPool )
        {
          m_free = m_firstPool->m_free;
          m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
          m_free->m_pool = m_firstPool;
          ++m_firstPool->m_used;
          *(_QWORD *)&m_free->m_data[80] = -1i64;
          *(_QWORD *)&m_free->m_data[8] = 0i64;
          *(_QWORD *)m_free->m_data = this->m_vertices.m_used;
          m_used = this->m_vertices.m_used;
          if ( m_used )
            m_used->m_prev = (hkgpMeshBase::Vertex *)m_free;
          ++this->m_vertices.m_numUsed;
          this->m_vertices.m_used = (hkgpMeshBase::Vertex *)m_free;
        }
        else
        {
          m_free = 0i64;
        }
        NewPool = this->m_vertices.m_allocator.m_firstPool;
        if ( !NewPool || !NewPool->m_free )
          NewPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_vertices.m_allocator);
        if ( NewPool )
        {
          v49 = NewPool->m_free;
          NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v49->m_data;
          v49->m_pool = NewPool;
          ++NewPool->m_used;
          *(_QWORD *)&v49->m_data[80] = -1i64;
          *(_QWORD *)&v49->m_data[8] = 0i64;
          *(_QWORD *)v49->m_data = this->m_vertices.m_used;
          v50 = this->m_vertices.m_used;
          if ( v50 )
            v50->m_prev = (hkgpMeshBase::Vertex *)v49;
          ++this->m_vertices.m_numUsed;
          this->m_vertices.m_used = (hkgpMeshBase::Vertex *)v49;
        }
        else
        {
          v49 = 0i64;
        }
        *(__m128 *)&m_free->m_data[32] = v44;
        *(__m128 *)&v49->m_data[32] = v45;
        v51 = this->m_triangles.m_allocator.m_firstPool;
        if ( !v51 || !v51->m_free )
          v51 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_triangles.m_allocator);
        if ( v51 )
        {
          v52 = (hkgpMeshBase::Triangle *)v51->m_free;
          v51->m_free = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *)v52->m_next;
          v52[1].m_next = (hkgpMeshBase::Triangle *)v51;
          ++v51->m_used;
          v52->m_prev = 0i64;
          v52->m_next = this->m_triangles.m_used;
          v53 = this->m_triangles.m_used;
          if ( v53 )
            v53->m_prev = v52;
          ++this->m_triangles.m_numUsed;
          this->m_triangles.m_used = v52;
        }
        else
        {
          v52 = 0i64;
        }
        v52->m_vertices[0] = (hkgpMeshBase::Vertex *)m_free;
        v52->m_vertices[1] = (hkgpMeshBase::Vertex *)v49;
        v52->m_vertices[2] = (hkgpMeshBase::Vertex *)m_free;
        hkgpMesh::updatePlane(this, v52);
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v55 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
          v54 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        else
        {
          v54 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v55 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        }
        v52->m_links[0] = v54 + v55;
        v56 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
        {
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                    + 40) = v52;
          v56 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v57 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        }
        else
        {
          v56 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v57 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        }
        v52->m_links[1] = v56 + v57;
        v58 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
        {
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                    + 40) = (char *)&v52->m_next + 1;
          v58 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v59 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        }
        else
        {
          v58 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v59 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        }
        v52->m_links[2] = v58 + v59;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e)
                    + 40) = (char *)&v52->m_next + 2;
      }
      ++v35;
      v38 += 16i64;
    }
    while ( v35 < v61 );
  }
  v64 = 0;
  if ( v65 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v63,
      (unsigned int)(16 * v65),
      v22);
  v63 = 0i64;
  v61 = 0;
  v65 = 0x80000000;
  if ( v62 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(16 * v62),
      v22);
},
      (unsigned int)(16 * v65),
      v22);
  v63 = 0i64;
  

// File Line: 1725
// RVA: 0xCCCF70
__int64 __fastcall hkgpMesh::checkOverlap(
        hkgpMesh *this,
        hkgpMesh::IConvexOverlap::IConvexShape *ishape,
        float minDist,
        bool allowPenetration)
{
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *vfptr; // rax
  hkAabb *v6; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_trianglesTree; // rbx
  __int128 m_max; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle> *v10; // r9
  __int64 m_cur; // rcx
  void *v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  char tree[48]; // [rsp+20h] [rbp-49h] BYREF
  hkgpMesh::IConvexOverlap *m_iconvexoverlap; // [rsp+50h] [rbp-19h]
  hkgpMesh::IConvexOverlap::IConvexShape *v21; // [rsp+58h] [rbp-11h]
  __int64 v22; // [rsp+60h] [rbp-9h]
  unsigned __int8 v23; // [rsp+68h] [rbp-1h]
  bool v24; // [rsp+69h] [rbp+0h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+70h] [rbp+7h] BYREF
  __int128 v26; // [rsp+90h] [rbp+27h]
  hkAabb v27; // [rsp+A0h] [rbp+37h] BYREF

  m_iconvexoverlap = this->m_iconvexoverlap;
  vfptr = ishape->vfptr;
  v21 = ishape;
  *(__m128 *)&tree[32] = _mm_shuffle_ps((__m128)LODWORD(minDist), (__m128)LODWORD(minDist), 0);
  v22 = 0i64;
  v23 = 0;
  v24 = allowPenetration;
  v6 = vfptr->getBoundingBox(ishape, &v27);
  m_trianglesTree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_trianglesTree;
  stackInstance.m_stack.m_size = 1;
  *(_QWORD *)tree = 0i64;
  m_max = (__int128)v6->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = v6->m_min;
  v26 = m_max;
  stackInstance.m_stack.m_data = (unsigned __int64 *)&tree[32];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 0x80000000;
  *(_DWORD *)&tree[24] = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (void *)(m_cur + 512);
  if ( Value->m_slabSize < 512 || v12 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v12;
  *(_QWORD *)tree = m_cur;
  *(_QWORD *)&tree[16] = m_cur;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle>>(
    m_trianglesTree,
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)tree,
    &stackInstance,
    v10);
  v13 = *(_DWORD *)&tree[8];
  v14 = *(char **)&tree[16];
  if ( *(_QWORD *)&tree[16] == *(_QWORD *)tree )
    v13 = 0;
  *(_DWORD *)&tree[8] = v13;
  v15 = (8 * *(_DWORD *)&tree[24] + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  *(_DWORD *)&tree[8] = 0;
  if ( *(int *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      8 * *(_DWORD *)&tree[12]);
  return v23;
}

// File Line: 1737
// RVA: 0xCCD110
__int64 __fastcall hkgpMesh::enumerateOverlaps(
        hkgpMesh *this,
        hkgpMesh::IConvexOverlap::IConvexShape *ishape,
        hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles,
        float minDist,
        bool allowPenetration)
{
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *vfptr; // rax
  hkAabb *v7; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_trianglesTree; // rbx
  __int128 m_max; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle> *v11; // r9
  __int64 m_cur; // rcx
  void *v13; // rdx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  char tree[48]; // [rsp+20h] [rbp-51h] BYREF
  hkgpMesh::IConvexOverlap *m_iconvexoverlap; // [rsp+50h] [rbp-21h]
  hkgpMesh::IConvexOverlap::IConvexShape *v22; // [rsp+58h] [rbp-19h]
  hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *v23; // [rsp+60h] [rbp-11h]
  unsigned __int8 v24; // [rsp+68h] [rbp-9h]
  bool v25; // [rsp+69h] [rbp-8h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+70h] [rbp-1h] BYREF
  __int128 v27; // [rsp+90h] [rbp+1Fh]
  hkAabb v28; // [rsp+A0h] [rbp+2Fh] BYREF

  m_iconvexoverlap = this->m_iconvexoverlap;
  v22 = ishape;
  *(__m128 *)&tree[32] = _mm_shuffle_ps((__m128)LODWORD(minDist), (__m128)LODWORD(minDist), 0);
  v25 = allowPenetration;
  vfptr = ishape->vfptr;
  v24 = 0;
  v23 = triangles;
  v7 = vfptr->getBoundingBox(ishape, &v28);
  m_trianglesTree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_trianglesTree;
  stackInstance.m_stack.m_size = 1;
  m_max = (__int128)v7->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = v7->m_min;
  v27 = m_max;
  stackInstance.m_stack.m_data = (unsigned __int64 *)&tree[32];
  *(_DWORD *)&tree[12] = 0x80000000;
  *(_QWORD *)tree = 0i64;
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[24] = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v13 = (void *)(m_cur + 512);
  if ( Value->m_slabSize < 512 || v13 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v13;
  *(_QWORD *)tree = m_cur;
  *(_QWORD *)&tree[16] = m_cur;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle>>(
    m_trianglesTree,
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)tree,
    &stackInstance,
    v11);
  v14 = *(_DWORD *)&tree[8];
  v15 = *(char **)&tree[16];
  if ( *(_QWORD *)&tree[16] == *(_QWORD *)tree )
    v14 = 0;
  *(_DWORD *)&tree[8] = v14;
  v16 = (8 * *(_DWORD *)&tree[24] + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v17, v15, v18);
  else
    v17->m_cur = v15;
  *(_DWORD *)&tree[8] = 0;
  if ( *(int *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      8 * *(_DWORD *)&tree[12]);
  return v24;
}

// File Line: 1750
// RVA: 0xCCD2B0
bool __fastcall hkgpMesh::isConcave(hkgpMesh *this, hkgpMeshBase::Edge *edge, float eps)
{
  hkgpMeshBase::Edge v4; // [rsp+20h] [rbp-38h] BYREF
  hkSimdFloat32 v5; // [rsp+30h] [rbp-28h] BYREF

  v4 = *edge;
  return COERCE_FLOAT(*hkgpMesh::tetrahedronVolume6(&v5, &v4)) < _mm_shuffle_ps(
                                                                   (__m128)LODWORD(eps),
                                                                   (__m128)LODWORD(eps),
                                                                   0).m128_f32[0];
}

// File Line: 1756
// RVA: 0xCCD300
hkSimdFloat32 *__fastcall hkgpMesh::tetrahedronVolume6(hkSimdFloat32 *result, hkgpMeshBase::Edge *edge)
{
  __int64 m_index; // r11
  hkgpMeshBase::Triangle *m_triangle; // r10
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // r8
  hkSimdFloat32 *v7; // rax
  __m128 m_quad; // xmm1
  hkgpMeshBase::Vertex *v9; // rax
  __m128 v10; // xmm0
  __m128 *v11; // rax
  hkMatrix3f v12; // [rsp+20h] [rbp-38h] BYREF

  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  v5 = edge->m_triangle->m_links[m_index] & 3;
  v6 = edge->m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v6 )
  {
    m_quad = m_triangle->m_vertices[m_index]->m_position.m_quad;
    v9 = m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3];
    v12.m_col0.m_quad = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(v6 + 8i64 * (int)v5 + 16) + 32i64), m_quad);
    v10 = v9->m_position.m_quad;
    v11 = *(__m128 **)(v6 + 8 * ((18i64 >> (2 * (unsigned __int8)v5)) & 3) + 16);
    v12.m_col1.m_quad = _mm_sub_ps(v10, m_quad);
    v12.m_col2.m_quad = _mm_sub_ps(v11[2], m_quad);
    hkMatrix3f::getDeterminant(&v12, result);
    return result;
  }
  else
  {
    v7 = result;
    *(hkVector4f *)result = (hkVector4f)aabbOut.m_quad;
  }
  return v7;
}

// File Line: 1767
// RVA: 0xCCD3B0
hkgpMeshBase::Triangle *__fastcall hkgpMesh::createTriangle(
        hkgpMesh *this,
        hkgpMeshBase::Vertex *a,
        hkgpMeshBase::Vertex *b,
        hkgpMeshBase::Vertex *c)
{
  hkgpMeshBase::Triangle *v8; // rbp

  v8 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
  v8->m_partId = -1;
  v8->m_links[0] = 0i64;
  v8->m_links[1] = 0i64;
  v8->m_links[2] = 0i64;
  v8->m_vertices[0] = a;
  v8->m_vertices[1] = b;
  v8->m_vertices[2] = c;
  hkgpMesh::setPlane(this, &a->m_position, &b->m_position, &c->m_position, &v8->m_plane, 1);
  return v8;
}

// File Line: 1780
// RVA: 0xCCD450
hkgpMeshBase::Edge *__fastcall hkgpMesh::findEdge(
        hkgpMesh *this,
        hkgpMeshBase::Edge *result,
        hkgpMeshBase::Vertex *s,
        hkgpMeshBase::Vertex *e)
{
  hkgpMeshBase::Triangle *m_used; // r10
  hkgpMeshBase::Triangle *v5; // rbx
  unsigned int v8; // r9d
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v13; // rax

  m_used = this->m_triangles.m_used;
  v5 = 0i64;
  if ( m_used )
  {
    while ( 2 )
    {
      v8 = 2;
      v9 = 0;
      v10 = 0i64;
      v11 = 16i64;
      do
      {
        if ( *(hkgpMeshBase::Vertex **)((char *)m_used->m_vertices + v11) == s && m_used->m_vertices[v10] == e )
        {
          result->m_triangle = m_used;
          result->m_index = v8;
          return result;
        }
        v8 = v9++;
        v11 = v10 * 8;
        ++v10;
      }
      while ( v9 < 3 );
      m_used = m_used->m_next;
      if ( m_used )
        continue;
      break;
    }
  }
  if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
  {
    v5 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
  }
  else
  {
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
  }
  v13 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
        + 1);
  result->m_triangle = v5;
  *(_QWORD *)&result->m_index = v13;
  return result;
}

// File Line: 1793
// RVA: 0xCCD510
hkgpMeshBase::Edge *__fastcall hkgpMesh::flipEdge(hkgpMesh *this, hkgpMeshBase::Edge *result, hkgpMeshBase::Edge *e)
{
  __int64 m_index; // rcx
  hkgpMeshBase::Triangle *m_triangle; // r8
  __int64 v7; // r14
  unsigned __int64 v8; // rbx
  char v9; // cl
  unsigned __int64 v10; // rbp
  __int64 v11; // r13
  unsigned __int64 v12; // r15
  __int64 v13; // r9
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r12
  hkgpMeshBase::Triangle *v16; // r8
  __int64 v17; // rax
  hkgpMeshBase::Triangle *v18; // r10
  unsigned int v19; // edx
  hkgpMeshBase::Edge *v20; // rax
  hkgpMeshBase::Triangle *v21; // rax
  unsigned int v22; // [rsp+0h] [rbp-58h]
  int v23; // [rsp+4h] [rbp-54h]
  __int64 v24; // [rsp+8h] [rbp-50h]
  unsigned __int64 v25; // [rsp+10h] [rbp-48h]
  _QWORD *v26; // [rsp+18h] [rbp-40h]
  unsigned int v27; // [rsp+70h] [rbp+18h]
  unsigned int v28; // [rsp+78h] [rbp+20h]

  m_index = (int)e->m_index;
  m_triangle = e->m_triangle;
  v24 = m_index;
  v7 = m_triangle->m_links[m_index] & 3;
  v8 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v8 )
  {
    v9 = 2 * m_index;
    v25 = m_triangle->m_links[(9 >> v9) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v27 = m_triangle->m_links[(9 >> v9) & 3] & 3;
    v10 = m_triangle->m_links[(18 >> v9) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v11 = m_triangle->m_links[(18 >> v9) & 3] & 3;
    v23 = (9 >> (2 * v7)) & 3;
    v26 = (_QWORD *)(v8 + 8 * (v23 + 5i64));
    v12 = *v26 & 0xFFFFFFFFFFFFFFFCui64;
    v22 = *v26 & 3;
    v13 = (18 >> (2 * v7)) & 3;
    v14 = v8 + 8i64 * (int)v13;
    v15 = *(_QWORD *)(v14 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v28 = *(_QWORD *)(v14 + 40) & 3;
    m_triangle->m_vertices[v24] = *(hkgpMeshBase::Vertex **)(v8 + 8 * ((18i64 >> (2 * (unsigned __int8)v7)) & 3) + 16);
    *(_QWORD *)(v8 + 8i64 * (int)v7 + 16) = e->m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)e->m_index)) & 3];
    v16 = e->m_triangle;
    v17 = (18 >> (2 * e->m_index)) & 3;
    v16->m_links[v17] = v8 + v13;
    *(_QWORD *)(v14 + 40) = (char *)v16 + (unsigned int)v17;
    v18 = e->m_triangle;
    v19 = (9 >> (2 * e->m_index)) & 3;
    e->m_triangle->m_links[v19] = v25 + v27;
    if ( v25 )
      *(_QWORD *)(v25 + 8i64 * (int)v27 + 40) = (char *)v18 + v19;
    e->m_triangle->m_links[e->m_index] = v15 + v28;
    if ( v15 )
      *(_QWORD *)(v15 + 8i64 * (int)v28 + 40) = (char *)e->m_triangle + e->m_index;
    *v26 = v12 + v22;
    if ( v12 )
      *(_QWORD *)(v12 + 8i64 * (int)v22 + 40) = v8 + (unsigned int)v23;
    *(_QWORD *)(v8 + 8i64 * (int)v7 + 40) = v10 + (unsigned int)v11;
    if ( v10 )
      *(_QWORD *)(v10 + 8i64 * (int)v11 + 40) = v8 + (unsigned int)v7;
    result->m_triangle = e->m_triangle;
    v20 = result;
    result->m_index = (18 >> (2 * LOBYTE(e->m_index))) & 3;
  }
  else
  {
    if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v21 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
    }
    else
    {
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
      v21 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
    }
    result->m_triangle = v21;
    *(_QWORD *)&result->m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                  + 1);
    return result;
  }
  return v20;
}

// File Line: 1815
// RVA: 0xCCD780
__int64 __fastcall hkgpMesh::buildPlaneIndices(
        hkgpMesh *this,
        float minCosAngle,
        float minDistance,
        bool stopAtMaterialBoundaries)
{
  int v7; // r13d
  float v8; // xmm8_4
  float v9; // xmm7_4
  __int64 v10; // r12
  hkgpMeshBase::Triangle *v11; // rsi
  __m128 m_quad; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  int v15; // ecx
  hkgpMeshBase::Triangle **v16; // rdx
  __int64 v17; // rax
  int v18; // ecx
  hkgpMeshBase::Triangle **v19; // rdx
  __int64 v20; // rax
  int v21; // ecx
  hkgpMeshBase::Triangle **v22; // rdx
  __int64 v23; // rax
  int v24; // eax
  int v25; // edx
  __int64 v26; // rbx
  char v27; // cl
  unsigned __int64 v28; // rbx
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  char v31; // di
  int v32; // edx
  unsigned __int64 *v33; // r8
  __int64 v34; // rax
  int v35; // edx
  unsigned __int64 *v36; // rcx
  __int64 v37; // rax
  unsigned int m_size; // ebx
  _QWORD *array; // [rsp+20h] [rbp-79h] BYREF
  int v40; // [rsp+28h] [rbp-71h]
  int v41; // [rsp+2Ch] [rbp-6Dh]
  hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> triangles; // [rsp+30h] [rbp-69h] BYREF
  __int64 v43; // [rsp+48h] [rbp-51h]
  __int64 v44; // [rsp+58h] [rbp-41h]
  __int64 v45; // [rsp+68h] [rbp-31h]
  __int64 v46; // [rsp+78h] [rbp-21h]
  __int64 v47; // [rsp+88h] [rbp-11h]

  this->m_planes.m_size = 0;
  this->m_planeRoots.m_size = 0;
  if ( !this->m_triangles.m_numUsed )
    return 0i64;
  triangles.m_data = 0i64;
  triangles.m_size = 0;
  triangles.m_capacityAndFlags = 0x80000000;
  hkgpMesh::fetchAreaSortedTriangles(this, &triangles, 1);
  array = 0i64;
  v40 = 0;
  v41 = 0x80000000;
  v7 = 0;
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(minCosAngle), (__m128)LODWORD(minCosAngle), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(minDistance), (__m128)LODWORD(minDistance), 0).m128_u32[0];
  if ( triangles.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = triangles.m_data[v10];
      if ( v11->m_planeId < 0 )
      {
        m_quad = v11->m_plane.m_quad;
        if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) == 0 )
        {
          v13 = _mm_mul_ps(m_quad, m_quad);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_INT(
                                             (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v13, v13, 170).m128_f32[0])
                                           - 1.0)) >> 1) < _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0] )
          {
            v14 = v11->m_plane.m_quad;
            v15 = 0;
            v11->m_planeId = this->m_planes.m_size;
            v40 = 0;
            LODWORD(v43) = 0;
            if ( (v41 & 0x3FFFFFFF) == 0 )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
              v15 = v40;
            }
            v16 = (hkgpMeshBase::Triangle **)&array[2 * v15];
            if ( v16 )
            {
              v17 = v43;
              *v16 = v11;
              v16[1] = (hkgpMeshBase::Triangle *)v17;
              v15 = v40;
            }
            v18 = v15 + 1;
            LODWORD(v44) = 1;
            v40 = v18;
            if ( v18 == (v41 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
              v18 = v40;
            }
            v19 = (hkgpMeshBase::Triangle **)&array[2 * v18];
            if ( v19 )
            {
              v20 = v44;
              *v19 = v11;
              v19[1] = (hkgpMeshBase::Triangle *)v20;
              v18 = v40;
            }
            v21 = v18 + 1;
            LODWORD(v45) = 2;
            v40 = v21;
            if ( v21 == (v41 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
              v21 = v40;
            }
            v22 = (hkgpMeshBase::Triangle **)&array[2 * v21];
            if ( v22 )
            {
              v23 = v45;
              *v22 = v11;
              v22[1] = (hkgpMeshBase::Triangle *)v23;
              v21 = v40;
            }
            v24 = this->m_planes.m_capacityAndFlags & 0x3FFFFFFF;
            v40 = v21 + 1;
            if ( this->m_planes.m_size == v24 )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_planes.m_data, 16);
            this->m_planes.m_data[this->m_planes.m_size++].m_quad = v14;
            if ( this->m_planeRoots.m_size == (this->m_planeRoots.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                &hkContainerHeapAllocator::s_alloc,
                (const void **)&this->m_planeRoots.m_data,
                8);
            this->m_planeRoots.m_data[this->m_planeRoots.m_size] = v11;
            v25 = v40;
            ++this->m_planeRoots.m_size;
            while ( v25 )
            {
              --v25;
              v26 = *(_QWORD *)(array[2 * v25] + 8i64 * SLODWORD(array[2 * v25 + 1]) + 40);
              v40 = v25;
              v27 = v26 & 3;
              v28 = v26 & 0xFFFFFFFFFFFFFFFCui64;
              if ( v28
                && *(_DWORD *)(v28 + 84) == -1
                && (!stopAtMaterialBoundaries || *(_DWORD *)(v28 + 88) == v11->m_material) )
              {
                v29 = *(__m128 *)(v28 + 64);
                v30 = _mm_mul_ps(v14, v29);
                if ( (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
                           + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) >= v8
                  && COERCE_FLOAT((unsigned int)(2
                                               * COERCE_INT(
                                                   _mm_shuffle_ps(v14, v14, 255).m128_f32[0]
                                                 - _mm_shuffle_ps(v29, v29, 255).m128_f32[0])) >> 1) <= v9 )
                {
                  v31 = 2 * v27;
                  *(_DWORD *)(v28 + 84) = v11->m_planeId;
                  v32 = v40;
                  LODWORD(v46) = (9 >> (2 * v27)) & 3;
                  if ( v40 == (v41 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                    v32 = v40;
                  }
                  v33 = &array[2 * v32];
                  if ( v33 )
                  {
                    v34 = v46;
                    *v33 = v28;
                    v33[1] = v34;
                    v32 = v40;
                  }
                  v35 = v32 + 1;
                  v40 = v35;
                  LODWORD(v47) = (18 >> v31) & 3;
                  if ( v35 == (v41 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                    v35 = v40;
                  }
                  v36 = &array[2 * v35];
                  if ( v36 )
                  {
                    v37 = v47;
                    *v36 = v28;
                    v36[1] = v37;
                    v35 = v40;
                  }
                  v25 = v35 + 1;
                  v40 = v25;
                }
              }
            }
          }
        }
      }
      ++v7;
      ++v10;
    }
    while ( v7 < triangles.m_size );
  }
  m_size = this->m_planes.m_size;
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v41);
  array = 0i64;
  v41 = 0x80000000;
  triangles.m_size = 0;
  if ( triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triangles.m_data,
      8 * triangles.m_capacityAndFlags);
  return m_size;
}( triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContain

// File Line: 1865
// RVA: 0xCCDC50
void __fastcall hkgpMesh::setPartIdsAsPlaneIndices(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *i; // rax

  if ( this->m_planes.m_size )
  {
    for ( i = this->m_triangles.m_used; i; i = i->m_next )
      i->m_partId = i->m_planeId;
  }
}

// File Line: 1877
// RVA: 0xCCDC80
char __fastcall hkgpMesh::hasPosition(hkgpMeshBase::Triangle *t, hkVector4f *position)
{
  __m128 m_quad; // xmm1
  __int64 v3; // rax
  __m128 **i; // rdx

  m_quad = position->m_quad;
  v3 = 0i64;
  for ( i = (__m128 **)t->m_vertices; (_mm_movemask_ps(_mm_cmpeq_ps((*i)[2], m_quad)) & 7) != 7; ++i )
  {
    if ( ++v3 >= 3 )
      return 0;
  }
  return 1;
}

// File Line: 1888
// RVA: 0xCCDCC0
void __fastcall hkgpMesh::removeTriangle(hkgpMesh *this, hkgpMeshBase::Triangle *t)
{
  if ( (t->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    *(_QWORD *)((t->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) + 8 * (t->m_links[0] & 3) + 40) = 0i64;
  t->m_links[0] = 0i64;
  if ( (t->m_links[1] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    *(_QWORD *)((t->m_links[1] & 0xFFFFFFFFFFFFFFFCui64) + 8 * (t->m_links[1] & 3) + 40) = 0i64;
  t->m_links[1] = 0i64;
  if ( (t->m_links[2] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    *(_QWORD *)((t->m_links[2] & 0xFFFFFFFFFFFFFFFCui64) + 8 * (t->m_links[2] & 3) + 40) = 0i64;
  t->m_links[2] = 0i64;
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::release(
    &this->m_triangles,
    t);
}

// File Line: 1897
// RVA: 0xCCDD40
void __fastcall hkgpMesh::sortTrianglesByArea(hkgpMesh *this, float fsign)
{
  float v3; // xmm6_4
  hkgpMeshBase::Triangle *m_used; // rcx
  char v5; // dl
  __m128 m_quad; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  float v14; // xmm5_4
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  float v23; // xmm3_4
  hkgpMeshBase::Triangle *m_prev; // rax
  hkgpMeshBase::Triangle *m_next; // r8
  hkgpMeshBase::Triangle *v26; // rdx

  LODWORD(v3) = _mm_shuffle_ps((__m128)LODWORD(fsign), (__m128)LODWORD(fsign), 0).m128_u32[0];
  do
  {
    m_used = this->m_triangles.m_used;
    v5 = 0;
    m_quad = m_used->m_vertices[0]->m_position.m_quad;
    v7 = _mm_sub_ps(m_used->m_vertices[1]->m_position.m_quad, m_quad);
    v8 = _mm_sub_ps(m_used->m_vertices[2]->m_position.m_quad, m_quad);
    v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
    v10 = _mm_shuffle_ps(v9, v9, 201);
    v11 = _mm_mul_ps(v10, v10);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    v14 = _mm_andnot_ps(
            _mm_cmple_ps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                _mm_mul_ps(*(__m128 *)_xmm, v13)),
              v12)).m128_f32[0]
        * v3;
    if ( !m_used->m_next )
      break;
    do
    {
      m_used = m_used->m_next;
      v15 = m_used->m_vertices[0]->m_position.m_quad;
      v16 = _mm_sub_ps(m_used->m_vertices[1]->m_position.m_quad, v15);
      v17 = _mm_sub_ps(m_used->m_vertices[2]->m_position.m_quad, v15);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17));
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
                v21)).m128_f32[0]
          * v3;
      if ( v23 > v14 )
      {
        m_prev = m_used->m_prev;
        if ( m_prev )
        {
          m_next = m_used->m_next;
          v26 = m_prev->m_prev;
          if ( m_used->m_next )
          {
            m_next->m_prev = m_prev;
            m_prev->m_next = m_next;
          }
          else
          {
            m_prev->m_next = 0i64;
          }
          if ( v26 )
          {
            v26->m_next = m_used;
            m_used->m_prev = v26;
          }
          else
          {
            this->m_triangles.m_used = m_used;
            m_used->m_prev = 0i64;
          }
          m_prev->m_prev = m_used;
          m_used->m_next = m_prev;
        }
        v5 = 1;
      }
      v14 = v23;
    }
    while ( m_used->m_next );
  }
  while ( v5 );
}

// File Line: 1922
// RVA: 0xCCDF10
hkSimdFloat32 *__fastcall hkgpMesh::projectPointOnSurface(
        hkgpMesh *this,
        hkSimdFloat32 *result,
        float offset,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *point,
        int iterations)
{
  unsigned int v5; // ebx
  __int64 v6; // rdi
  __m128 v10; // xmm7
  int v11; // edx
  int v12; // r9d
  __m128 m_real; // xmm3
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  __m128 *v18; // rax
  __int64 v19; // rcx
  __m128 v20; // xmm0
  hkSimdFloat32 *v21; // rax
  int v22; // r8d
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  hkVector4fComparison inside; // [rsp+30h] [rbp-C0h] BYREF
  hkVector4f normal; // [rsp+40h] [rbp-B0h] BYREF
  hkSimdFloat32 v29; // [rsp+50h] [rbp-A0h] BYREF
  char *array; // [rsp+60h] [rbp-90h] BYREF
  int v31; // [rsp+68h] [rbp-88h]
  int v32; // [rsp+6Ch] [rbp-84h]
  char v33; // [rsp+70h] [rbp-80h] BYREF
  unsigned int v34; // [rsp+2D0h] [rbp+1E0h]
  hkResult resulta; // [rsp+2E0h] [rbp+1F0h] BYREF

  resulta.m_enum = LODWORD(offset);
  v34 = v5;
  v6 = LODWORD(offset);
  v32 = -2147483616;
  v10 = _mm_shuffle_ps((__m128)v34, (__m128)v34, 0);
  *result = 0i64;
  normal.m_quad = 0i64;
  v11 = 0;
  v31 = 0;
  array = &v33;
  if ( SLODWORD(offset) > 32 )
  {
    v12 = LODWORD(offset);
    if ( SLODWORD(offset) < 64 )
      v12 = 64;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v12, 16);
    v11 = v31;
  }
  if ( SLODWORD(offset) > 0 )
  {
    do
    {
      m_real = hkgpMesh::squaredDistanceToPoint(this, &v29, point, &normal, &inside)->m_real;
      v14 = (__m128 *)&array[16 * v31];
      v15 = _mm_rsqrt_ps(m_real);
      v16 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu),
              _mm_andnot_ps(
                _mm_cmple_ps(m_real, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(m_real, v15), v15)),
                    _mm_mul_ps(*(__m128 *)_xmm, v15)),
                  m_real)));
      *result = (hkSimdFloat32)v16;
      v17.m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v10, v16), (__m128)xmmword_141A711B0), normal.m_quad),
                     (__m128)point->m_nodes);
      point->m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)v17.m_quad;
      *(hkVector4f *)v14 = (hkVector4f)v17.m_quad;
      v11 = ++v31;
      --v6;
    }
    while ( v6 );
  }
  point->m_nodes = 0i64;
  if ( v11 > 0 )
  {
    v18 = (__m128 *)array;
    v19 = (unsigned int)v11;
    do
    {
      ++v18;
      point->m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                           (__m128)point->m_nodes,
                                                                                           v18[-1]);
      --v19;
    }
    while ( v19 );
  }
  v20 = 0i64;
  v20.m128_f32[0] = (float)v11;
  point->m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                       (__m128)point->m_nodes,
                                                                                       _mm_div_ps(
                                                                                         query.m_quad,
                                                                                         _mm_shuffle_ps(v20, v20, 0)));
  v21 = hkgpMesh::squaredDistanceToPoint(this, &v29, point, &normal, &inside);
  v22 = v32;
  v23 = v21->m_real;
  v24 = v21->m_real;
  v31 = 0;
  v25 = _mm_rsqrt_ps(v23);
  result->m_real = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu),
                     _mm_andnot_ps(
                       _mm_cmple_ps(v24, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v25), v25)),
                           _mm_mul_ps(*(__m128 *)_xmm, v25)),
                         v23)));
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v22);
  return result;
}

// File Line: 1951
// RVA: 0xCCE1B0
hkSimdFloat32 *__fastcall hkgpMesh::projectPointOnSurface(
        hkgpMesh *this,
        hkSimdFloat32 *result,
        float offset,
        hkVector4f *projection,
        hkVector4f *point,
        int iterations)
{
  __m128 v9; // xmm6
  __m128 v10; // xmm7
  __int64 v11; // rsi
  __m128 v12; // xmm9
  hkSimdFloat32 *v13; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  hkVector4f normal; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4fComparison inside; // [rsp+40h] [rbp-98h] BYREF
  hkSimdFloat32 resulta; // [rsp+50h] [rbp-88h] BYREF

  v9 = _mm_shuffle_ps((__m128)LODWORD(offset), (__m128)LODWORD(offset), 0);
  normal.m_quad = 0i64;
  *result = 0i64;
  v10 = _mm_mul_ps(v9, (__m128)xmmword_141A711B0);
  if ( iterations > 0 )
  {
    v11 = (unsigned int)iterations;
    v12 = _mm_sub_ps((__m128)0i64, v10);
    do
    {
      v13 = hkgpMesh::squaredDistanceToPoint(
              this,
              &resulta,
              (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)point,
              &normal,
              &inside);
      v14 = _mm_rsqrt_ps(v13->m_real);
      v15 = _mm_andnot_ps(
              _mm_cmple_ps(v13->m_real, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13->m_real, v14), v14)),
                  _mm_mul_ps(*(__m128 *)_xmm, v14)),
                v13->m_real));
      v16 = _mm_cmplt_ps(v15, v10);
      v17 = _mm_xor_ps(
              _mm_max_ps(v12, _mm_or_ps(_mm_and_ps(v15, v16), _mm_andnot_ps(v16, v10))),
              (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu));
      *result = (hkSimdFloat32)v17;
      v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v9, v17), normal.m_quad), projection->m_quad);
      point->m_quad = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                            _mm_shuffle_ps(v18, v18, 170)),
                          projection->m_quad),
                        point->m_quad);
      --v11;
    }
    while ( v11 );
  }
  return result;
}

// File Line: 1972
// RVA: 0xCCE360
char __fastcall hkgpMesh::computeOffsetPoint(
        hkgpMesh *this,
        hkSimdFloat32 *offset,
        hkVector4f *normal,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *point,
        int maxIterations,
        bool checkInside)
{
  float v10; // xmm12_4
  float v11; // xmm11_4
  hkgpMeshBase::Triangle *v12; // rax
  hkSimdFloat32 v13; // xmm6
  int v14; // ebx
  bool v15; // dl
  char v16; // si
  BOOL v17; // eax
  __m128 m_quad; // xmm3
  int v19; // ecx
  int v20; // eax
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm9
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm14
  __m128 v30; // xmm9
  __m128 v31; // xmm4
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  hkgpMesh::Location location; // [rsp+20h] [rbp-148h] BYREF

  location.m_region.m_type = NONE;
  v10 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99000001), (__m128)LODWORD(FLOAT_0_99000001), 0).m128_f32[0]
      * offset->m_real.m128_f32[0];
  v11 = offset->m_real.m128_f32[0] * 4.0;
  if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
  {
    v12 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
  }
  else
  {
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
    v12 = 0i64;
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
  }
  v13.m_real = (__m128)xmmword_141A712A0;
  v14 = 0;
  location.m_region.m_feature.m_triangle = v12;
  v15 = 0;
  v16 = 1;
  *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                    + 1);
  memset(&location, 0, 48);
  location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
  location.m_inside.m_real = g_vectorfConstants[0];
  if ( maxIterations > 0 )
  {
    while ( 1 )
    {
      hkgpMesh::locate(this, point, &location, (hkBool)1);
      v17 = checkInside && location.m_inside.m_real.m128_f32[0] < 0.0;
      v13.m_real = (__m128)location.m_squaredDistance;
      v15 = v17;
      if ( (float)(location.m_squaredDistance.m_real.m128_f32[0] + 0.00000011920929) >= (float)(v10 * v10) )
        break;
      if ( v14 && v17 )
        return 0;
      m_quad = location.m_normal.m_quad;
      v19 = 0;
      v20 = 0;
      v21 = _mm_mul_ps(location.m_normal.m_quad, location.m_normal.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                 + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) <= 0.00000011920929 )
        v19 = 1;
      if ( location.m_squaredDistance.m_real.m128_f32[0] <= 0.00000011920929 )
        v20 = 1;
      if ( v20 | v19 )
        m_quad = normal->m_quad;
      v22 = _mm_mul_ps(m_quad, m_quad);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_rsqrt_ps(v23);
      v25 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v23), (__m128)0i64);
      v26 = _mm_cmple_ps(v23, (__m128)0i64);
      v27 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24));
      if ( !_mm_movemask_ps(v25) )
        return 0;
      v28 = _mm_rsqrt_ps(location.m_squaredDistance.m_real);
      v29 = _mm_mul_ps(*(__m128 *)_xmm, v28);
      v30 = _mm_mul_ps(
              _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_andnot_ps(v26, v27), m_quad), v25), _mm_andnot_ps(v25, m_quad)),
              normal->m_quad);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      v32 = _mm_mul_ps(_mm_mul_ps(v28, location.m_squaredDistance.m_real), v28);
      v33 = _mm_rcp_ps(v31);
      v34 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v31)), v33),
              _mm_sub_ps(
                offset->m_real,
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(location.m_squaredDistance.m_real, (__m128)0i64),
                    _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v32), v29), location.m_squaredDistance.m_real)),
                  location.m_inside.m_real)));
      if ( v31.m128_f32[0] >= 0.00000011920929 && v34.m128_f32[0] <= v11 )
      {
        ++v14;
        point->m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                             _mm_mul_ps(
                                                                                               normal->m_quad,
                                                                                               v34),
                                                                                             (__m128)point->m_nodes);
        if ( v14 < maxIterations )
          continue;
      }
      break;
    }
  }
  v35 = _mm_rsqrt_ps(v13.m_real);
  v36 = _mm_andnot_ps(
          _mm_cmple_ps(v13.m_real, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v13.m_real), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35)),
            v13.m_real));
  point->m_nodes = (hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator>)_mm_shuffle_ps(
                                                                                       (__m128)point->m_nodes,
                                                                                       _mm_unpackhi_ps(
                                                                                         (__m128)point->m_nodes,
                                                                                         v36),
                                                                                       196);
  if ( v15 || v36.m128_f32[0] < v10 || v36.m128_f32[0] >= v11 )
    return 0;
  return v16;
}

// File Line: 2006
// RVA: 0xCCE730
void __fastcall hkgpMesh::generateSurfaceSamples(
        hkgpMesh *this,
        hkgpMesh::SurfaceSamplingConfig *config,
        hkArray<hkVector4f,hkContainerHeapAllocator> *samplesOut,
        bool useWeight)
{
  __m128 v4; // xmm2
  hkgpConvexHull *ConvexHull; // rax
  hkgpMesh *v9; // r11
  hkgpConvexHull *v10; // r12
  hkgpMeshBase::Vertex *i; // rdi
  hkgpMeshBase::Triangle *m_used; // r13
  __m128 v13; // xmm8
  __m128 m_quad; // xmm3
  __m128 v15; // xmm3
  int v16; // eax
  unsigned __int64 *m_links; // r15
  __m128 *v18; // r10
  char v19; // r9
  int v20; // ecx
  __int64 v21; // r14
  __m128 *v22; // r8
  float *m128_f32; // rax
  float v24; // xmm0_4
  unsigned __int64 v25; // rdx
  __m128 v26; // xmm7
  __m128 *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float v32; // xmm0_4
  __m128 v33; // xmm3
  __m128 *v34; // rax
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm11
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm9
  int v48; // eax
  int v49; // edi
  __m128 v50; // xmm1
  __m128 v51; // xmm0
  __m128 j; // xmm7
  int v53; // [rsp+30h] [rbp-D0h]
  hkVector4f point; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v55; // [rsp+50h] [rbp-B0h]
  hkErrStream v56; // [rsp+60h] [rbp-A0h] BYREF
  hkSimdFloat32 v57; // [rsp+80h] [rbp-80h] BYREF
  hkMatrix3f v58; // [rsp+90h] [rbp-70h] BYREF
  char buf[512]; // [rsp+C0h] [rbp-40h] BYREF
  int v61; // [rsp+378h] [rbp+278h]
  int result; // [rsp+388h] [rbp+288h] BYREF

  if ( useWeight )
  {
    hkErrStream::hkErrStream(&v56, buf, 512);
    hkOstream::operator<<(&v56, "Weighted surface sampling not implemented");
    hkError::messageWarning(0xFAC164F0, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2009);
    hkOstream::~hkOstream(&v56);
  }
  ConvexHull = hkgpMesh::getConvexHull(this);
  v9 = this;
  v10 = ConvexHull;
  if ( config->m_doVertices )
  {
    for ( i = this->m_vertices.m_used; i; v9 = this )
    {
      point.m_quad = (__m128)i->m_position;
      if ( hkgpMesh::computeOffsetPoint(
             v9,
             &config->m_offset,
             &i->m_normal,
             (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&point,
             8,
             1)
        && (!v10 || hkgpConvexHull::isPointInside(v10, (hkBool *)&result, &point, 0, 0.0)->m_bool) )
      {
        if ( samplesOut->m_size == (samplesOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&samplesOut->m_data, 16);
        samplesOut->m_data[samplesOut->m_size++] = (hkVector4f)point.m_quad;
      }
      i = i->m_next;
    }
  }
  if ( config->m_doEdges )
  {
    m_used = v9->m_triangles.m_used;
    v13 = hkVector4fComparison_maskToComparison_327[config->m_edgeCenterOnly != 0 ? 0xF : 0];
    if ( m_used )
    {
      result = 953267991;
      while ( 1 )
      {
        m_quad = m_used->m_plane.m_quad;
        if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) == 0 )
        {
          v15 = _mm_mul_ps(m_quad, m_quad);
          v4.m128_f32[0] = 0.000099999997;
          v4 = _mm_shuffle_ps(v4, v4, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_INT(
                                             (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v15, v15, 170).m128_f32[0])
                                           - 1.0)) >> 1) < v4.m128_f32[0] )
            break;
        }
LABEL_44:
        m_used = m_used->m_next;
        if ( !m_used )
          return;
      }
      LOBYTE(v16) = 0;
      m_links = m_used->m_links;
      v61 = 0;
      while ( 1 )
      {
        v18 = (__m128 *)*(m_links - 3);
        v19 = 2 * v16;
        v20 = 0;
        v21 = (9i64 >> (2 * (unsigned __int8)v16)) & 3;
        v22 = (__m128 *)m_used->m_vertices[v21];
        m128_f32 = v22[2].m128_f32;
        do
        {
          v24 = *(float *)((char *)m128_f32 + *(m_links - 3) - (_QWORD)v22);
          if ( v24 < *m128_f32 )
            break;
          if ( v24 > *m128_f32 )
          {
            if ( (*m_links & 0xFFFFFFFFFFFFFFFCui64) != 0 )
              goto LABEL_43;
            break;
          }
          ++v20;
          ++m128_f32;
        }
        while ( v20 < 3 );
        v25 = *m_links;
        v26 = m_used->m_plane.m_quad;
        v27 = (__m128 *)(*m_links & 0xFFFFFFFFFFFFFFFCui64);
        if ( !v27 )
          goto LABEL_31;
        v28 = v27[4];
        v55 = 953267991;
        if ( (_mm_movemask_ps(_mm_cmpunord_ps(v28, v28)) & 7) == 0 )
        {
          v29 = _mm_mul_ps(v28, v28);
          v4 = _mm_shuffle_ps((__m128)v55, (__m128)v55, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_INT(
                                             (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v29, v29, 170).m128_f32[0])
                                           - 1.0)) >> 1) < v4.m128_f32[0] )
          {
            v30 = _mm_mul_ps(v27[4], v26);
            v31 = _mm_shuffle_ps(v30, v30, 85).m128_f32[0];
            v32 = _mm_shuffle_ps(v30, v30, 0).m128_f32[0];
            v4 = _mm_shuffle_ps(v30, v30, 170);
            if ( (float)((float)(v31 + v32) + v4.m128_f32[0]) <= config->m_maxCosAngle.m_real.m128_f32[0] )
            {
              v26 = _mm_add_ps(v26, v27[4]);
              if ( !config->m_discardConvex )
                goto LABEL_31;
              v33 = v18[2];
              v4 = _mm_sub_ps(v22[2], v33);
              v34 = (__m128 *)m_used->m_vertices[(18i64 >> v19) & 3];
              v58.m_col0.m_quad = v4;
              v58.m_col1.m_quad = _mm_sub_ps(v34[2], v33);
              v58.m_col2.m_quad = _mm_sub_ps(
                                    *(__m128 *)(*(_QWORD *)((v25 & 0xFFFFFFFFFFFFFFFCui64)
                                                          + 8 * ((18i64 >> (2 * ((unsigned __int8)v25 & 3u))) & 3)
                                                          + 16)
                                              + 32i64),
                                    v33);
              hkMatrix3f::getDeterminant(&v58, &v57);
              if ( v57.m_real.m128_f32[0] >= 0.00000011920929 )
                break;
            }
          }
        }
LABEL_43:
        v9 = this;
        ++m_links;
        v16 = v61 + 1;
        v61 = v16;
        if ( v16 >= 3 )
          goto LABEL_44;
      }
      v9 = this;
LABEL_31:
      v35 = 0i64;
      v36 = _mm_mul_ps(v26, v26);
      v37 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
              _mm_shuffle_ps(v36, v36, 170));
      v4 = _mm_rsqrt_ps(v37);
      v38 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v37), (__m128)0i64);
      v56.hkReferencedObject = (hkReferencedObject)_mm_or_ps(
                                                     _mm_and_ps(
                                                       _mm_mul_ps(
                                                         _mm_andnot_ps(
                                                           _mm_cmple_ps(v37, (__m128)0i64),
                                                           _mm_mul_ps(
                                                             _mm_sub_ps(
                                                               (__m128)_xmm,
                                                               _mm_mul_ps(_mm_mul_ps(v4, v37), v4)),
                                                             _mm_mul_ps(*(__m128 *)_xmm, v4))),
                                                         v26),
                                                       v38),
                                                     _mm_andnot_ps(v38, v26));
      if ( _mm_movemask_ps(v38) )
      {
        v39 = _mm_sub_ps(*(__m128 *)(*(m_links - 3) + 32), m_used->m_vertices[v21]->m_position.m_quad);
        v40 = _mm_mul_ps(v39, v39);
        v41 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                _mm_shuffle_ps(v40, v40, 170));
        v42 = _mm_rsqrt_ps(v41);
        v43 = _mm_mul_ps(*(__m128 *)_xmm, v42);
        v44 = _mm_cmple_ps(v41, (__m128)0i64);
        v45 = _mm_mul_ps(_mm_mul_ps(v41, v42), v42);
        v46 = 0i64;
        v47 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v45), v43), v41);
        v4 = _mm_rcp_ps(config->m_edgeSamplesSpacing.m_real);
        v48 = _mm_cvtsi128_si32(
                _mm_cvttps_epi32(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, config->m_edgeSamplesSpacing.m_real)), v4),
                      _mm_andnot_ps(v44, v47)),
                    (__m128)xmmword_141A711B0)))
            + 3;
        if ( v48 > 64 )
          v48 = 64;
        v49 = 0;
        v53 = v48;
        v46.m128_f32[0] = (float)v48;
        v50 = _mm_shuffle_ps(v46, v46, 0);
        v51 = _mm_rcp_ps(v50);
        for ( j = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v50, v51)), v51); v49 <= v53; ++v49 )
        {
          v4 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_or_ps(_mm_andnot_ps(v13, _mm_mul_ps(j, v35)), _mm_and_ps(v13, (__m128)xmmword_141A711B0)),
                   _mm_sub_ps(m_used->m_vertices[v21]->m_position.m_quad, *(__m128 *)(*(m_links - 3) + 32))),
                 *(__m128 *)(*(m_links - 3) + 32));
          point.m_quad = v4;
          if ( hkgpMesh::computeOffsetPoint(
                 v9,
                 &config->m_offset,
                 (hkVector4f *)&v56,
                 (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&point,
                 8,
                 1)
            && (!v10 || hkgpConvexHull::isPointInside(v10, (hkBool *)&result, &point, 0, 0.0)->m_bool) )
          {
            if ( samplesOut->m_size == (samplesOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&samplesOut->m_data, 16);
            samplesOut->m_data[samplesOut->m_size++] = (hkVector4f)point.m_quad;
          }
          if ( config->m_edgeCenterOnly )
            break;
          v35 = _mm_add_ps(v35, query.m_quad);
          v9 = this;
        }
      }
      goto LABEL_43;
    }
  }
}

// File Line: 2088
// RVA: 0xCCEDD0
void __fastcall hkgpMesh::generateConcaveEdges(
        hkgpMesh *this,
        float offset,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgesOut,
        unsigned int useWeight,
        hkgpJobQueue *jq)
{
  hkVector4f v5; // xmm2
  hkgpMesh *v6; // rbx
  hkgpMeshBase::Triangle *m_used; // r15
  hkgpMeshInternals::ConcaveEdgeJob *v8; // rdi
  __m128 v9; // xmm13
  float v10; // xmm14_4
  __m128 m_quad; // xmm3
  __m128 v12; // xmm3
  int v13; // r12d
  __m128 **m_vertices; // r14
  int v15; // ecx
  __int64 v16; // rsi
  __m128 *v17; // r8
  float *m128_f32; // rax
  float v19; // xmm0_4
  unsigned __int64 v20; // rdx
  __m128 v21; // xmm7
  unsigned __int64 v22; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm7
  __m128 *v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm8
  __m128 v34; // xmm6
  _QWORD **Value; // rax
  __int64 v36; // rax
  int v37; // ecx
  __m128 *v38; // rax
  hkgpMeshBase::Vertex *v39; // rcx
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm7
  hkVector4f v43; // xmm9
  __m128 v44; // xmm11
  __m128 v45; // xmm10
  hkgpMeshInternals::Segment *v46; // rcx
  __int128 v47; // xmm0
  __int128 v48; // xmm1
  __int128 v49; // xmm0
  __m128 v50; // xmm9
  __m128 v51; // xmm2
  __m128 v52; // xmm7
  int m_capacityAndFlags; // eax
  hkgpMeshInternals::Segment *v54; // rcx
  __int128 v55; // xmm0
  __int128 v56; // xmm1
  __int128 v57; // xmm0
  hkgpMeshBase::Vertex *v58; // rax
  __m128 v59; // xmm7
  __m128 v60; // xmm2
  float v61; // xmm1_4
  float v62; // xmm0_4
  hkVector4f v63; // xmm6
  int v64; // eax
  hkgpMeshInternals::Segment *v65; // rcx
  __int128 v66; // xmm0
  __int128 v67; // xmm1
  __int128 v68; // xmm0
  _QWORD **v69; // rax
  hkgpJobQueue::IJob *v70; // rax
  _QWORD **v71; // rax
  hkgpJobQueue::IJob *v72; // rax
  int v73; // esi
  __int64 v74; // rdi
  __int64 v75; // rbx
  int v76; // r8d
  int v77; // eax
  _QWORD **v78; // rax
  _QWORD *array; // [rsp+20h] [rbp-D8h] BYREF
  int v80; // [rsp+28h] [rbp-D0h]
  int v81; // [rsp+2Ch] [rbp-CCh]
  hkSimdFloat32 result; // [rsp+30h] [rbp-C8h] BYREF
  hkMatrix3f v83; // [rsp+40h] [rbp-B8h] BYREF
  __int128 v84; // [rsp+A8h] [rbp-50h]
  __int128 v85; // [rsp+B8h] [rbp-40h]
  __int128 v86; // [rsp+E8h] [rbp-10h]
  hkgpMesh *retaddr; // [rsp+1E8h] [rbp+F0h]
  hkArrayBase<hkVector4f> *v88; // [rsp+1F8h] [rbp+100h]
  hkgpJobQueue *v89; // [rsp+208h] [rbp+110h]

  *(float *)&v88 = offset;
  v6 = this;
  m_used = this->m_triangles.m_used;
  v8 = 0i64;
  array = 0i64;
  v80 = 0;
  v81 = 0x80000000;
  v9 = hkVector4fComparison_maskToComparison_327[useWeight != 0 ? 0xF : 0];
  if ( m_used )
  {
    v10 = *(float *)&this;
    do
    {
      m_quad = m_used->m_plane.m_quad;
      if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) == 0 )
      {
        v12 = _mm_mul_ps(m_quad, m_quad);
        v5.m_quad.m128_f32[0] = 0.000099999997;
        v5.m_quad = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 0);
        if ( COERCE_FLOAT((unsigned int)(2
                                       * COERCE_INT(
                                           (float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0]
                                                         + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                                                 + _mm_shuffle_ps(v12, v12, 170).m128_f32[0])
                                         - 1.0)) >> 1) < v5.m_quad.m128_f32[0] )
        {
          v13 = 0;
          m_vertices = (__m128 **)m_used->m_vertices;
          do
          {
            v15 = 0;
            v16 = (9i64 >> (2 * (unsigned __int8)v13)) & 3;
            v17 = (__m128 *)m_used->m_vertices[v16];
            m128_f32 = v17[2].m128_f32;
            do
            {
              v19 = *(float *)((char *)m128_f32 + (char *)*m_vertices - (char *)v17);
              if ( v19 < *m128_f32 )
                break;
              if ( v19 > *m128_f32 )
              {
                if ( ((unsigned __int64)m_vertices[3] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                  goto LABEL_49;
                break;
              }
              ++v15;
              ++m128_f32;
            }
            while ( v15 < 3 );
            v20 = (unsigned __int64)m_vertices[3];
            v21 = m_used->m_plane.m_quad;
            v22 = v20 & 0xFFFFFFFFFFFFFFFCui64;
            if ( (v20 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            {
              v23 = *(__m128 *)(v22 + 64);
              if ( (_mm_movemask_ps(_mm_cmpunord_ps(v23, v23)) & 7) == 0 )
              {
                v24 = _mm_mul_ps(v23, v23);
                v5.m_quad = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
                if ( COERCE_FLOAT((unsigned int)(2
                                               * COERCE_INT(
                                                   (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0]
                                                                 + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
                                                         + _mm_shuffle_ps(v24, v24, 170).m128_f32[0])
                                                 - 1.0)) >> 1) < v5.m_quad.m128_f32[0] )
                {
                  v25 = *(__m128 *)(v22 + 64);
                  v26 = _mm_mul_ps(v25, v21);
                  v5.m_quad = _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                                _mm_shuffle_ps(v26, v26, 170));
                  if ( v5.m_quad.m128_f32[0] <= _mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0).m128_f32[0] )
                  {
                    v27 = (*m_vertices)[2];
                    v28 = _mm_add_ps(v21, v25);
                    v5.m_quad = _mm_sub_ps(v17[2], v27);
                    v29 = (__m128 *)m_used->m_vertices[(18i64 >> (2 * (unsigned __int8)v13)) & 3];
                    v83.m_col0 = (hkVector4f)v5.m_quad;
                    v83.m_col1.m_quad = _mm_sub_ps(v29[2], v27);
                    v83.m_col2.m_quad = _mm_sub_ps(
                                          *(__m128 *)(*(_QWORD *)((v20 & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8 * ((18i64 >> (2 * ((unsigned __int8)v20 & 3u))) & 3)
                                                                + 16)
                                                    + 32i64),
                                          v27);
                    hkMatrix3f::getDeterminant(&v83, &result);
                    if ( result.m_real.m128_f32[0] >= 0.00000011920929 )
                    {
                      v30 = _mm_mul_ps(v28, v28);
                      v31 = _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                              _mm_shuffle_ps(v30, v30, 170));
                      v5.m_quad = _mm_rsqrt_ps(v31);
                      v32 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v31), (__m128)0i64);
                      v33 = _mm_or_ps(
                              _mm_and_ps(
                                _mm_mul_ps(
                                  _mm_andnot_ps(
                                    _mm_cmple_ps(v31, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5.m_quad, v31), v5.m_quad)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v5.m_quad))),
                                  v28),
                                v32),
                              _mm_andnot_ps(v32, v28));
                      if ( _mm_movemask_ps(v32) )
                      {
                        v34 = _mm_sub_ps(m_used->m_vertices[v16]->m_position.m_quad, (*m_vertices)[2]);
                        if ( !v8 )
                        {
                          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                          v36 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
                          v8 = (hkgpMeshInternals::ConcaveEdgeJob *)v36;
                          if ( v36 )
                          {
                            *(_QWORD *)v36 = v6;
                            *(_DWORD *)(v36 + 20) = 0x80000000;
                            *(_QWORD *)(v36 + 8) = 0i64;
                            *(_DWORD *)(v36 + 16) = 0;
                            *(_QWORD *)(v36 + 24) = 0i64;
                            *(_DWORD *)(v36 + 32) = 0;
                            *(_DWORD *)(v36 + 36) = 0x80000000;
                          }
                          else
                          {
                            v8 = 0i64;
                          }
                          v37 = v80;
                          if ( v80 == (v81 & 0x3FFFFFFF) )
                          {
                            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                            v37 = v80;
                          }
                          array[v37] = v8;
                          ++v80;
                        }
                        v38 = *m_vertices;
                        v39 = m_used->m_vertices[v16];
                        v5.m_quad.m128_f32[0] = v10;
                        DWORD1(v86) = 0;
                        v40 = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 0);
                        v41 = _mm_andnot_ps(v9, query.m_quad);
                        v42 = v38[2];
                        v43.m_quad = (__m128)v39->m_position;
                        v44 = _mm_max_ps(
                                aabbOut.m_quad,
                                _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_shuffle_ps(v38[1], v38[1], 255), v9), v41), v40));
                        v45 = _mm_max_ps(
                                aabbOut.m_quad,
                                _mm_mul_ps(
                                  _mm_or_ps(
                                    _mm_and_ps(_mm_shuffle_ps(v39->m_source.m_quad, v39->m_source.m_quad, 255), v9),
                                    v41),
                                  v40));
                        if ( v8->m_segments.m_size == (v8->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
                          hkArrayUtil::_reserveMore(
                            &hkContainerHeapAllocator::s_alloc,
                            (const void **)&v8->m_segments.m_data,
                            144);
                        v46 = &v8->m_segments.m_data[v8->m_segments.m_size];
                        if ( v46 )
                        {
                          v47 = v84;
                          v48 = v85;
                          v46->m_vertices[0].m_quad = v42;
                          v46->m_vertices[1] = (hkVector4f)v43.m_quad;
                          v46->m_normals[0].m_quad = v33;
                          v46->m_normals[1].m_quad = v33;
                          v46->m_offsets[0] = (hkVector4f)v47;
                          v49 = v86;
                          v46->m_offsets[1] = (hkVector4f)v48;
                          v46->m_offsetsValues[0].m_real = v44;
                          v46->m_offsetsValues[1].m_real = v45;
                          *(_OWORD *)v46->m_valid = v49;
                        }
                        ++v8->m_segments.m_size;
                        v50 = (*m_vertices)[3];
                        v51 = _mm_mul_ps(v50, v34);
                        if ( (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v51, v51, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v51, v51, 170).m128_f32[0]) < 0.0 )
                        {
                          v52 = (*m_vertices)[2];
                          m_capacityAndFlags = v8->m_segments.m_capacityAndFlags;
                          DWORD1(v86) = 0;
                          if ( v8->m_segments.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
                            hkArrayUtil::_reserveMore(
                              &hkContainerHeapAllocator::s_alloc,
                              (const void **)&v8->m_segments.m_data,
                              144);
                          v54 = &v8->m_segments.m_data[v8->m_segments.m_size];
                          if ( v54 )
                          {
                            v55 = v84;
                            v56 = v85;
                            v54->m_vertices[0].m_quad = v52;
                            v54->m_vertices[1].m_quad = v52;
                            v54->m_normals[0].m_quad = v50;
                            v54->m_normals[1].m_quad = v33;
                            v54->m_offsets[0] = (hkVector4f)v55;
                            v57 = v86;
                            v54->m_offsets[1] = (hkVector4f)v56;
                            v54->m_offsetsValues[0].m_real = v44;
                            v54->m_offsetsValues[1].m_real = v45;
                            *(_OWORD *)v54->m_valid = v57;
                          }
                          ++v8->m_segments.m_size;
                        }
                        v58 = m_used->m_vertices[v16];
                        v59 = v58->m_normal.m_quad;
                        v60 = _mm_mul_ps(v59, v34);
                        v61 = _mm_shuffle_ps(v60, v60, 85).m128_f32[0];
                        v62 = _mm_shuffle_ps(v60, v60, 0).m128_f32[0];
                        v5.m_quad = _mm_shuffle_ps(v60, v60, 170);
                        if ( (float)((float)(v61 + v62) + v5.m_quad.m128_f32[0]) > 0.0 )
                        {
                          v63.m_quad = (__m128)v58->m_position;
                          v64 = v8->m_segments.m_capacityAndFlags;
                          DWORD1(v86) = 0;
                          if ( v8->m_segments.m_size == (v64 & 0x3FFFFFFF) )
                            hkArrayUtil::_reserveMore(
                              &hkContainerHeapAllocator::s_alloc,
                              (const void **)&v8->m_segments.m_data,
                              144);
                          v65 = &v8->m_segments.m_data[v8->m_segments.m_size];
                          if ( v65 )
                          {
                            v66 = v84;
                            v67 = v85;
                            v65->m_vertices[0] = (hkVector4f)v63.m_quad;
                            v65->m_vertices[1] = (hkVector4f)v63.m_quad;
                            v65->m_normals[0].m_quad = v59;
                            v65->m_normals[1].m_quad = v33;
                            v65->m_offsets[0] = (hkVector4f)v66;
                            v68 = v86;
                            v65->m_offsets[1] = (hkVector4f)v67;
                            v65->m_offsetsValues[0].m_real = v44;
                            v65->m_offsetsValues[1].m_real = v45;
                            *(_OWORD *)v65->m_valid = v68;
                          }
                          ++v8->m_segments.m_size;
                        }
                        if ( v8->m_segments.m_size >= 64 )
                        {
                          if ( v89 )
                          {
                            v69 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                            v70 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v69[11] + 8i64))(
                                                          v69[11],
                                                          16i64);
                            if ( v70 )
                            {
                              v70[1].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
                              v70->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpMeshInternals::ConcaveEdgeJob::Handle>::`vftable;
                              hkgpJobQueue::push(v89, v70);
                            }
                            else
                            {
                              hkgpJobQueue::push(v89, 0i64);
                            }
                          }
                          else
                          {
                            hkgpMeshInternals::ConcaveEdgeJob::run(v8);
                          }
                          v8 = 0i64;
                        }
                        v6 = retaddr;
                      }
                    }
                  }
                }
              }
            }
LABEL_49:
            ++v13;
            ++m_vertices;
          }
          while ( v13 < 3 );
        }
      }
      m_used = m_used->m_next;
    }
    while ( m_used );
    if ( v8 )
    {
      if ( !v89 )
      {
        hkgpMeshInternals::ConcaveEdgeJob::run(v8);
        goto LABEL_58;
      }
      v71 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v72 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v71[11] + 8i64))(v71[11], 16i64);
      if ( v72 )
      {
        v72[1].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
        v72->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpMeshInternals::ConcaveEdgeJob::Handle>::`vftable;
      }
      hkgpJobQueue::push(v89, v72);
    }
  }
  if ( v89 )
    hkgpJobQueue::waitForCompletion(v89);
LABEL_58:
  v73 = 0;
  if ( v80 > 0 )
  {
    v74 = 0i64;
    do
    {
      hkArrayBase<hkVector4f>::_append(
        v88,
        &hkContainerHeapAllocator::s_alloc,
        *(hkVector4f **)(array[v74] + 24i64),
        *(_DWORD *)(array[v74] + 32i64));
      v75 = array[v74];
      if ( v75 )
      {
        v76 = *(_DWORD *)(v75 + 36);
        *(_DWORD *)(v75 + 32) = 0;
        if ( v76 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 24),
            16 * v76);
        *(_QWORD *)(v75 + 24) = 0i64;
        *(_DWORD *)(v75 + 36) = 0x80000000;
        v77 = *(_DWORD *)(v75 + 20);
        *(_DWORD *)(v75 + 16) = 0;
        if ( v77 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 8),
            144 * (v77 & 0x3FFFFFFF));
        *(_QWORD *)(v75 + 8) = 0i64;
        *(_DWORD *)(v75 + 20) = 0x80000000;
        v78 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v78[11] + 16i64))(v78[11], v75, 40i64);
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v80 );
  }
  v80 = 0;
  if ( v81 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v81);
}

// File Line: 2307
// RVA: 0xCCF6A0
void __fastcall hkgpMesh::generateEmptySpaceSamples(
        hkgpMesh *this,
        int maxOctreeDepth,
        float scaling,
        hkArray<hkVector4f,hkContainerHeapAllocator> *samplesOut,
        bool negate)
{
  hkgpConvexHull::BuildConfig *v8; // rax
  int v9; // eax
  hkAabb *BoundingBox; // rbx
  int v11; // edx
  hkAabb *v12; // r8
  hkVector4f *p_m_min; // rcx
  int v14; // edx
  __int64 v15; // rcx
  __m128i m_min; // xmm6
  __m128 m_quad; // xmm7
  __m128 v18; // xmm10
  signed int v19; // edi
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  float v22; // xmm9_4
  hkStridedVertices si128; // xmm1
  hkgpConvexHull::BuildConfig v24; // xmm8
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  int v28; // ebx
  int v29; // edi
  int v30; // ecx
  __m128 *p_m_quad; // rdx
  __m128i v32; // xmm2
  __m128 v33; // xmm2
  hkAabb *array; // [rsp+30h] [rbp-D0h] BYREF
  int v35; // [rsp+38h] [rbp-C8h]
  int v36; // [rsp+3Ch] [rbp-C4h]
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+40h] [rbp-C0h] BYREF
  hkBool v38; // [rsp+50h] [rbp-B0h] BYREF
  hkStridedVertices points; // [rsp+60h] [rbp-A0h] BYREF
  hkgpConvexHull::BuildConfig v40; // [rsp+70h] [rbp-90h] BYREF
  hkgpConvexHull v41; // [rsp+80h] [rbp-80h] BYREF
  hkAabb result; // [rsp+B0h] [rbp-50h] BYREF

  hkgpConvexHull::hkgpConvexHull(&v41);
  positions.m_capacityAndFlags = 0x80000000;
  positions.m_data = 0i64;
  positions.m_size = 0;
  hkgpMesh::fetchPositions(this, &positions);
  points.m_striding = 16;
  points.m_vertices = positions.m_data->m_quad.m128_f32;
  points.m_numVertices = positions.m_size;
  hkgpConvexHull::BuildConfig::BuildConfig(&v40);
  v9 = hkgpConvexHull::build(&v41, &points, v8);
  positions.m_size = 0;
  if ( v9 == 3 )
  {
    if ( positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        positions.m_data,
        16 * positions.m_capacityAndFlags);
    array = 0i64;
    v35 = 0;
    v36 = 0x80000000;
    BoundingBox = hkgpMesh::getBoundingBox(this, &result);
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 32);
    v11 = v35;
    v12 = array;
    p_m_min = &array[v35].m_min;
    if ( p_m_min )
    {
      *p_m_min = BoundingBox->m_min;
      p_m_min[1] = BoundingBox->m_max;
      v11 = v35;
      v12 = array;
    }
    v35 = v11 + 1;
    hkGeometryProcessing::normalizeAspectRatio(v12);
    array->m_min.m_quad.m128_i32[3] = 1056964608;
    v14 = v35;
    do
    {
      v15 = v14;
      m_min = (__m128i)array[v15 - 1].m_min;
      m_quad = array[v15 - 1].m_max.m_quad;
      v35 = v14 - 1;
      v18 = _mm_add_ps((__m128)m_min, m_quad);
      v19 = _mm_cvtsi128_si32(_mm_srli_si128(m_min, 12)) & 0xC0FFFFFF;
      positions = (hkArray<hkVector4f,hkContainerHeapAllocator>)_mm_mul_ps(v18, (__m128)xmmword_141A711B0);
      v20 = _mm_sub_ps((__m128)positions, m_quad);
      v21 = _mm_mul_ps(v20, v20);
      v22 = (float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
          + _mm_shuffle_ps(v21, v21, 170).m128_f32[0];
      hkgpMesh::squaredDistanceToPoint(
        this,
        (hkSimdFloat32 *)&v40,
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&positions,
        &result.m_min,
        (hkVector4fComparison *)&points);
      si128 = (hkStridedVertices)_mm_load_si128((const __m128i *)&points);
      if ( negate )
      {
        si128 = (hkStridedVertices)_mm_cmpeq_epi32((__m128i)si128, (__m128i)0i64);
        points = si128;
      }
      v24 = v40;
      if ( *(float *)&v40.m_allowLowerDimensions.m_bool <= v22 )
      {
        if ( v19 < maxOctreeDepth )
        {
          v28 = 0;
          v29 = (v19 + 1) | 0x3F000000;
          do
          {
            v30 = v35;
            if ( v35 == (v36 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 32);
              v30 = v35;
            }
            v35 = v30 + 1;
            p_m_quad = &array[v30].m_min.m_quad;
            switch ( v28 )
            {
              case 0:
                v32 = m_min;
                break;
              case 1:
                v32 = m_min;
                *(float *)v32.m128i_i32 = m_quad.m128_f32[0];
                break;
              case 2:
                v32 = (__m128i)_mm_shuffle_ps(m_quad, (__m128)m_min, 228);
                break;
              case 3:
                v32 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E30, (__m128)m_min),
                                 _mm_and_ps((__m128)xmmword_141A79E30, m_quad));
                break;
              case 4:
                v32 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E50, (__m128)m_min),
                                 _mm_and_ps((__m128)xmmword_141A79E50, m_quad));
                break;
              case 5:
                v32 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E60, (__m128)m_min),
                                 _mm_and_ps((__m128)xmmword_141A79E60, m_quad));
                break;
              case 6:
                v32 = (__m128i)m_quad;
                break;
              case 7:
                v32 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E70, (__m128)m_min),
                                 _mm_and_ps((__m128)xmmword_141A79E70, m_quad));
                break;
              default:
                v32 = (__m128i)_mm_mul_ps(v18, (__m128)xmmword_141A711B0);
                break;
            }
            ++v28;
            v33 = (__m128)_mm_srli_si128(_mm_slli_si128(v32, 4), 4);
            *p_m_quad = _mm_min_ps((__m128)positions, v33);
            p_m_quad[1] = _mm_max_ps((__m128)positions, v33);
            p_m_quad->m128_i32[3] = v29;
          }
          while ( v28 < 8 );
        }
      }
      else if ( !_mm_movemask_ps((__m128)si128)
             && hkgpConvexHull::isPointInside(&v41, &v38, (hkVector4f *)&positions, 0, 0.0)->m_bool )
      {
        v26 = _mm_rsqrt_ps((__m128)v24);
        v25.m128_f32[0] = scaling;
        v27 = _mm_shuffle_ps(
                (__m128)positions,
                _mm_unpackhi_ps(
                  (__m128)positions,
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps((__m128)v24, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps((__m128)v24, v26), v26)),
                          _mm_mul_ps(*(__m128 *)_xmm, v26)),
                        (__m128)v24)),
                    _mm_shuffle_ps(v25, v25, 0))),
                196);
        if ( samplesOut->m_size == (samplesOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&samplesOut->m_data, 16);
        samplesOut->m_data[samplesOut->m_size++].m_quad = v27;
      }
      v14 = v35;
    }
    while ( v35 );
    v35 = 0;
    if ( v36 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v36);
    array = 0i64;
    v36 = 0x80000000;
  }
  else if ( positions.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  }
  hkgpConvexHull::~hkgpConvexHull(&v41);
}

// File Line: 2363
// RVA: 0xCCBAA0
__int64 __fastcall hkgpMesh::removeOrphanVertices(hkgpMesh *this)
{
  const __m128i *m_used; // rax
  unsigned int i; // esi
  hkgpMeshBase::Triangle *j; // rcx
  hkgpMeshBase::Vertex *v5; // rax
  hkVector4f v6; // xmm1
  hkgpMeshBase::Vertex *v7; // rax
  hkVector4f v8; // xmm1
  hkgpMeshBase::Vertex *v9; // rax
  hkVector4f v10; // xmm1
  hkgpMeshBase::Vertex *m_next; // rdi
  __m128 m_quad; // xmm0
  hkgpMeshBase::Vertex *v13; // rdx
  hkgpMeshBase::Vertex *v14; // rax
  hkgpMeshBase::Vertex *m_prev; // rcx
  hkgpMeshBase::Vertex *v16; // rdx
  __int64 v18; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v19; // rax
  __int64 v20; // rcx

  m_used = (const __m128i *)this->m_vertices.m_used;
  for ( i = 0; m_used; m_used = (const __m128i *)m_used->m128i_i64[0] )
    m_used[4] = _mm_slli_si128(_mm_srli_si128(_mm_load_si128(m_used + 4), 4), 4);
  for ( j = this->m_triangles.m_used; j; j = j->m_next )
  {
    v5 = j->m_vertices[0];
    v6.m_quad = (__m128)v5->m_data;
    v6.m_quad.m128_f32[0] = 1.0;
    v5->m_data = (hkVector4f)v6.m_quad;
    v7 = j->m_vertices[1];
    v8.m_quad = (__m128)v7->m_data;
    v8.m_quad.m128_f32[0] = 1.0;
    v7->m_data = (hkVector4f)v8.m_quad;
    v9 = j->m_vertices[2];
    v10.m_quad = (__m128)v9->m_data;
    v10.m_quad.m128_f32[0] = 1.0;
    v9->m_data = (hkVector4f)v10.m_quad;
  }
  m_next = this->m_vertices.m_used;
  if ( m_next )
  {
    do
    {
      m_quad = m_next->m_data.m_quad;
      v13 = m_next;
      m_next = m_next->m_next;
      if ( _mm_shuffle_ps(m_quad, m_quad, 0).m128_f32[0] == 0.0 )
      {
        v14 = v13->m_next;
        m_prev = v13->m_prev;
        if ( v13->m_next )
          v14->m_prev = m_prev;
        if ( m_prev )
          m_prev->m_next = v14;
        else
          this->m_vertices.m_used = v14;
        --this->m_vertices.m_numUsed;
        v16 = v13[1].m_next;
        if ( v16[37].m_normal.m_quad.m128_i32[2]-- == 1 )
        {
          v18 = v16[37].m_position.m_quad.m128_i64[1];
          v19 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *)v16[37].m_normal.m_quad.m128_u64[0];
          if ( v18 )
            *(_QWORD *)(v18 + 3600) = v19;
          else
            this->m_vertices.m_allocator.m_firstPool = v19;
          v20 = v16[37].m_normal.m_quad.m128_i64[0];
          if ( v20 )
            *(_QWORD *)(v20 + 3592) = v16[37].m_position.m_quad.m128_u64[1];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v16, 3616);
        }
        ++i;
      }
    }
    while ( m_next );
    if ( i )
      hkgpMesh::invalidateConvexHull(this);
  }
  return i;
}

// File Line: 2390
// RVA: 0xCCBC20
__int64 __fastcall hkgpMesh::removeButterflies(hkgpMesh *this, int tag)
{
  hkgpMeshBase::Vertex *m_used; // rax
  unsigned int i; // r15d
  hkgpMeshBase::Triangle *j; // rcx
  hkgpMeshBase::Triangle *m_next; // rsi
  int k; // ebx
  __int128 v9; // xmm6
  int v10; // r9d
  hkgpMeshBase::Vertex *v11; // r14
  __int128 *v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rdx
  hkReferencedObject v17; // xmm6
  hkReferencedObject *v18; // rax
  __int64 v19; // rdx
  hkgpMeshBase::Vertex *v20; // rax
  int v21; // r8d
  hkgpMeshBase::Vertex *v22; // r9
  __int64 v23; // rdx
  hkOstream *v24; // rax
  __int128 v26; // [rsp+20h] [rbp-E0h]
  hkReferencedObject v27; // [rsp+20h] [rbp-E0h]
  hkErrStream v28; // [rsp+30h] [rbp-D0h] BYREF
  __int128 v29; // [rsp+50h] [rbp-B0h]
  __int128 v30; // [rsp+60h] [rbp-A0h]
  hkReferencedObject v31; // [rsp+70h] [rbp-90h]
  char *array; // [rsp+80h] [rbp-80h] BYREF
  int v33; // [rsp+88h] [rbp-78h]
  int v34; // [rsp+8Ch] [rbp-74h]
  char v35; // [rsp+90h] [rbp-70h] BYREF

  m_used = this->m_vertices.m_used;
  for ( i = 0; m_used; m_used = m_used->m_next )
    m_used->m_refs = 0;
  for ( j = this->m_triangles.m_used; j; j = j->m_next )
  {
    ++j->m_vertices[0]->m_refs;
    ++j->m_vertices[1]->m_refs;
    ++j->m_vertices[2]->m_refs;
  }
  m_next = this->m_triangles.m_used;
  if ( m_next )
  {
    do
    {
      for ( k = 0; k < 3; ++k )
      {
        *(_QWORD *)&v30 = m_next;
        DWORD2(v30) = k;
        v9 = v30;
        v10 = 0;
        v26 = v30;
        v11 = m_next->m_vertices[k];
        array = &v35;
        v33 = 0;
        v34 = -2147483632;
        while ( 1 )
        {
          if ( v10 == (v34 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v10 = v33;
          }
          v12 = (__int128 *)&array[16 * v10];
          if ( v12 )
          {
            *v12 = v9;
            v10 = v33;
          }
          v33 = ++v10;
          v13 = (18 >> (2 * BYTE8(v26))) & 3;
          v14 = *(_QWORD *)(v26 + 8 * v13 + 40) & 3i64;
          v15 = *(_QWORD *)(v26 + 8 * v13 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          *(_QWORD *)&v29 = v15;
          DWORD2(v29) = v14;
          v9 = v29;
          v26 = v29;
          if ( !v15 )
            break;
          if ( (hkgpMeshBase::Triangle *)(v15 + (unsigned int)v14) == (hkgpMeshBase::Triangle *)((char *)m_next
                                                                                               + (unsigned int)k) )
            goto LABEL_21;
        }
        v16 = m_next->m_links[k];
        v31.vfptr = (hkBaseObjectVtbl *)(v16 & 0xFFFFFFFFFFFFFFFCui64);
        *(_DWORD *)&v31.m_memSizeAndFlags = (9 >> (2 * (v16 & 3))) & 3;
        v17 = v31;
        v27 = v31;
        if ( (v16 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
        {
          do
          {
            if ( v10 == (v34 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
              v10 = v33;
            }
            v18 = (hkReferencedObject *)&array[16 * v10];
            if ( v18 )
            {
              *v18 = v17;
              v10 = v33;
            }
            v33 = ++v10;
            v19 = (__int64)*(&v27.vfptr[2].__first_virtual_table_function__ + *(int *)&v27.m_memSizeAndFlags) & 3;
            v28.vfptr = (hkBaseObjectVtbl *)((unsigned __int64)*(&v27.vfptr[2].__first_virtual_table_function__
                                                               + *(int *)&v27.m_memSizeAndFlags) & 0xFFFFFFFFFFFFFFFCui64);
            *(_DWORD *)&v28.m_memSizeAndFlags = (9 >> (2 * v19)) & 3;
            v17 = v28.hkReferencedObject;
            v27 = v28.hkReferencedObject;
          }
          while ( v28.vfptr );
        }
LABEL_21:
        if ( v10 < v11->m_refs )
        {
          v20 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(
                  &this->m_vertices,
                  v11);
          v21 = 0;
          v22 = v20;
          LODWORD(v20) = v33;
          v11->m_tag = tag;
          v11->m_refs -= (int)v20;
          LODWORD(v20) = v33;
          v22->m_tag = tag;
          v22->m_refs = (int)v20;
          if ( v33 > 0 )
          {
            v23 = 0i64;
            do
            {
              ++v21;
              v23 += 16i64;
              *(_QWORD *)(*(_QWORD *)&array[v23 - 16] + 8i64 * *(int *)&array[v23 - 8] + 16) = v22;
            }
            while ( v21 < v33 );
          }
          ++i;
        }
        v33 = 0;
        if ( v34 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v34);
      }
      m_next = m_next->m_next;
    }
    while ( m_next );
    if ( i )
    {
      hkErrStream::hkErrStream(&v28, (char *)&array, 512);
      v24 = hkOstream::operator<<(&v28, "Butterflies found: ");
      hkOstream::operator<<(v24, i);
      hkError::messageReport(0xFFFFFFFF, (const char *)&array, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2428);
      hkOstream::~hkOstream(&v28);
    }
  }
  return i;
}

// File Line: 2434
// RVA: 0xCCFBF0
void __fastcall hkgpMesh::reportBadAreaTriangle(hkgpMesh *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  this->m_hasErrors = 1;
}

// File Line: 2439
// RVA: 0xCCFC00
void __fastcall hkgpMesh::reportBadEdgeLength(hkgpMesh *this, hkVector4f *a, hkVector4f *b)
{
  this->m_hasErrors = 1;
}

// File Line: 2444
// RVA: 0xCCFC10
void __fastcall hkgpMesh::reportDuplicatedEdge(hkgpMesh *this, hkVector4f *a, hkVector4f *b)
{
  this->m_hasErrors = 1;
}

// File Line: 2449
// RVA: 0xCCFC20
void __fastcall hkgpMesh::reportInvalidEdgeWinding(hkgpMesh *this, hkVector4f *a, hkVector4f *b)
{
  this->m_hasErrors = 1;
}

// File Line: 2455
// RVA: 0xCCFC30
bool __fastcall hkgpMesh::hasValidTopology(hkgpMesh *this, bool raiseError)
{
  hkgpAbstractMeshDefinitions::Error v3; // eax
  unsigned int v4; // edi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v3 = hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::checkTopology(
         this,
         1);
  v4 = v3;
  if ( raiseError && v3 )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    v5 = hkOstream::operator<<(&v8, "Invalid mesh topology (");
    v6 = hkOstream::operator<<(v5, v4);
    hkOstream::operator<<(v6, ")");
    if ( (unsigned int)hkError::messageError(0x4C5C2AFAu, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2459) )
      __debugbreak();
    hkOstream::~hkOstream(&v8);
  }
  return v4 == 0;
}

// File Line: 2466
// RVA: 0xCCFCE0
char __fastcall hkgpMesh::bindEdge(hkgpMesh *this, hkgpMeshBase::Edge *edge, bool onlyToNaked, bool mustMatch)
{
  __int64 m_index; // rsi
  hkgpMeshBase::Triangle *m_triangle; // rdi
  hkgpMeshBase::Triangle *m_used; // r8
  int i; // eax
  hkErrStream v10; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_index = edge->m_index;
  m_triangle = edge->m_triangle;
  if ( (edge->m_triangle->m_links[(int)m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    return 1;
  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    while ( 2 )
    {
      for ( i = 0; i < 3; ++i )
      {
        if ( (!onlyToNaked || (m_used->m_links[i] & 0xFFFFFFFFFFFFFFFCui64) == 0)
          && m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)i)) & 3] == m_triangle->m_vertices[(int)m_index]
          && m_used->m_vertices[i] == m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3] )
        {
          m_used->m_links[i] = (unsigned __int64)m_triangle + m_index;
          if ( edge->m_triangle )
            edge->m_triangle->m_links[edge->m_index] = (unsigned __int64)m_used + (unsigned int)i;
          return 1;
        }
      }
      m_used = m_used->m_next;
      if ( m_used )
        continue;
      break;
    }
  }
  if ( mustMatch )
  {
    hkErrStream::hkErrStream(&v10, buf, 512);
    hkOstream::operator<<(&v10, "Unmatched edge");
    if ( (unsigned int)hkError::messageError(0x1FB636C8u, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2486) )
      __debugbreak();
    hkOstream::~hkOstream(&v10);
  }
  return 0;
}

// File Line: 2498
// RVA: 0xCCFE20
void __fastcall hkgpMesh::bindEdgeList(hkgpMesh *this, hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *edges)
{
  int v2; // r15d
  __int64 v4; // rdi
  __int64 v5; // r12
  int v6; // r13d
  int v7; // r11d
  __int64 v8; // rax
  hkgpMeshBase::Edge *v9; // r14
  hkgpMeshBase::Edge *v10; // r9
  hkgpMeshBase::Triangle *m_triangle; // rbx
  __int64 m_index; // rdi
  __int64 v13; // rsi
  __int64 v14; // rdx
  hkgpMeshBase::Edge *v15; // rax
  char *v16; // r8
  __int64 v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // r8
  hkgpMeshBase::Edge *v21; // rcx
  char *v22; // r8
  __int64 v23; // rax
  __int64 v24; // [rsp+38h] [rbp+10h]

  v2 = 0;
  if ( edges->m_size > 0 )
  {
    v4 = 1i64;
    v5 = 0i64;
    v24 = 1i64;
    v6 = 1;
    do
    {
      v7 = v6;
      v8 = v4;
      if ( v6 < edges->m_size )
      {
        v9 = &edges->m_data[v5];
        v10 = &edges->m_data[v5 + 1];
        while ( 1 )
        {
          m_triangle = v10->m_triangle;
          if ( !v10->m_triangle )
            break;
          m_index = (int)v10->m_index;
          v13 = (int)v9->m_index;
          if ( v9->m_triangle->m_vertices[v13] == m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3]
            && v9->m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v13)) & 3] == m_triangle->m_vertices[m_index] )
          {
            break;
          }
          ++v7;
          ++v8;
          ++v10;
          if ( v7 >= edges->m_size )
          {
            v4 = v24;
            goto LABEL_10;
          }
        }
        v9->m_triangle->m_links[v9->m_index] = (unsigned __int64)m_triangle + v10->m_index;
        if ( v10->m_triangle )
          v10->m_triangle->m_links[v10->m_index] = (unsigned __int64)v9->m_triangle + v9->m_index;
        if ( --edges->m_size != v7 )
        {
          v14 = 2i64;
          v15 = &edges->m_data[v8];
          v16 = (char *)((char *)&edges->m_data[edges->m_size] - (char *)v15);
          do
          {
            v17 = *(__int64 *)((char *)&v15->m_triangle + (_QWORD)v16);
            v15 = (hkgpMeshBase::Edge *)((char *)v15 + 8);
            *(_QWORD *)&v15[-1].m_index = v17;
            --v14;
          }
          while ( v14 );
        }
        v18 = --edges->m_size;
        if ( (_DWORD)v18 != v2 )
        {
          v19 = 2i64;
          v20 = v18;
          v21 = &edges->m_data[v5];
          v22 = (char *)((char *)&edges->m_data[v20] - (char *)v21);
          do
          {
            v23 = *(__int64 *)((char *)&v21->m_triangle + (_QWORD)v22);
            v21 = (hkgpMeshBase::Edge *)((char *)v21 + 8);
            *(_QWORD *)&v21[-1].m_index = v23;
            --v19;
          }
          while ( v19 );
        }
        --v2;
        --v6;
        v4 = v24 - 1;
        --v5;
      }
LABEL_10:
      ++v4;
      ++v2;
      ++v6;
      ++v5;
      v24 = v4;
    }
    while ( v2 < edges->m_size );
  }
}

// File Line: 2515
// RVA: 0xCD0010
void __fastcall hkgpMesh::fillHoles(hkgpMesh *this, hkgpMesh::HoleFillingConfig *config)
{
  int v2; // eax
  __m128 v3; // xmm11
  hkgpMesh::HoleFillingConfig *v4; // r12
  hkgpMesh *v5; // r14
  int v6; // r8d
  hkVector4f *v7; // rdi
  hkVector4f *v8; // rbx
  __m128 j; // xmm1
  int v10; // edi
  hkgpMeshBase::Triangle *m_used; // r15
  char v12; // si
  int v13; // r13d
  hkgpMeshInternals::Ring *v14; // rax
  hkgpMeshInternals::Ring *v15; // r12
  int v16; // ecx
  __int64 v17; // rbx
  __int64 m_index; // rsi
  hkgpMeshBase::Triangle *m_triangle; // r14
  int v20; // eax
  unsigned int v21; // ebx
  int v22; // r9d
  __int64 v23; // rdx
  __int64 v24; // r8
  int v25; // ecx
  unsigned __int8 v26; // r14
  int v27; // esi
  __int64 v28; // r15
  int m_margin; // ebx
  int v30; // eax
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128i v35; // xmm1
  int v36; // edi
  int v37; // ecx
  __int64 v38; // rdx
  bool v39; // cc
  int v40; // edx
  int v41; // esi
  __int64 v42; // rbx
  hkgpMeshInternals::Ring::Segment *m_data; // rdi
  hkgpMeshBase::Triangle **v44; // rcx
  hkgpMeshInternals::Ring::Segment *v45; // rax
  int v46; // edx
  hkgpMeshBase::Triangle *v47; // rdi
  hkgpMeshBase::Triangle **v48; // rcx
  __int64 v49; // rax
  hkgpMeshInternals::Ring::Segment *v50; // rax
  int v51; // edx
  hkgpMeshBase::Triangle *v52; // rdi
  hkgpMeshBase::Triangle **v53; // rcx
  __int64 v54; // rax
  int v55; // edx
  hkgpMeshInternals::Ring::Segment *v56; // rax
  hkgpMeshBase::Triangle *v57; // r11
  __int64 v58; // rdi
  int v59; // r8d
  __m128 m_quad; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128i v64; // xmm1
  int v65; // r10d
  int v66; // r9d
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128i v71; // xmm4
  int v72; // eax
  int v73; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v74; // r15
  char *v75; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_next; // r14
  int v77; // edx
  int v78; // esi
  __int64 v79; // r11
  __int64 v80; // rax
  __int64 v81; // r13
  unsigned __int64 v82; // rax
  __int64 v83; // r10
  __int64 v84; // rax
  int v85; // r12d
  unsigned __int64 v86; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v87; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v88; // rbx
  int m_x; // eax
  int v90; // ecx
  __int64 v91; // rcx
  unsigned __int64 v92; // rax
  __int64 v93; // r12
  unsigned __int64 v94; // r10
  int v95; // r11d
  __int64 v96; // r13
  int m_y; // r8d
  int v98; // edx
  __int64 v99; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v100; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v101; // rdx
  int v102; // eax
  int v103; // ecx
  unsigned __int64 v104; // r8
  __int64 v105; // rcx
  unsigned __int64 v106; // r8
  __int16 v107; // dx
  int v108; // r10d
  unsigned __int64 v109; // rdx
  char v110; // cl
  unsigned __int64 v111; // rdx
  __int64 v112; // rbx
  __int64 v113; // r9
  int v114; // eax
  int v115; // ecx
  __int64 v116; // r9
  unsigned __int64 v117; // r9
  __int16 v118; // dx
  int v119; // ebx
  unsigned __int64 v120; // rdx
  __int64 v121; // r15
  int v122; // r9d
  unsigned __int64 v123; // r8
  __int64 v124; // r12
  unsigned __int64 v125; // r8
  __int64 v126; // r15
  unsigned __int64 v127; // r9
  char v128; // cl
  unsigned __int64 v129; // r9
  __int64 v130; // rdx
  __int64 v131; // r10
  __int64 v132; // r8
  int v133; // eax
  int v134; // ecx
  __int64 v135; // r8
  unsigned __int64 v136; // r8
  __int64 v137; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v138; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v139; // rdx
  int v140; // eax
  int v141; // ecx
  unsigned __int64 v142; // r9
  unsigned __int64 v143; // r9
  int v144; // r12d
  hkgpMeshInternals::Ring *v145; // r13
  hkVector4f *v146; // rsi
  hkVector4f *v147; // rdi
  hkVector4f *v148; // rbx
  hkgpMeshBase::Triangle *v149; // r15
  __int64 v150; // rax
  int k; // ebx
  char v152; // al
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *EdgeData; // rax
  __int64 v154; // rdx
  hkgpMeshBase::Edge *v155; // rcx
  __int64 v156; // rax
  int v157; // ecx
  int v158; // edi
  __int64 v159; // rbx
  int v160; // edi
  __int64 v161; // rbx
  int v162; // r9d
  __int64 v163; // rbx
  hkgpMesh *v164; // r15
  __m128 *v165; // r14
  int v166; // esi
  char m; // di
  unsigned int v168; // r11d
  __m128 *v169; // r13
  __m128 *v170; // r9
  char v171; // dl
  float v172; // xmm13_4
  __m128 *v173; // r12
  int n; // r10d
  unsigned __int64 v175; // r8
  int v176; // edx
  __int64 v177; // r8
  char v178; // cl
  __m128 *v179; // r8
  int v180; // edx
  bool v181; // zf
  __m128 v182; // xmm0
  __m128 v183; // xmm7
  __m128 v184; // xmm8
  __m128 v185; // xmm3
  __m128 v186; // xmm3
  __m128 v187; // xmm2
  __m128 v188; // xmm2
  __m128 v189; // xmm1
  __m128 v190; // xmm5
  __m128 v191; // xmm12
  __m128 v192; // xmm9
  __m128 v193; // xmm1
  __m128 v194; // xmm6
  __m128 v195; // xmm10
  __m128 v196; // xmm11
  __m128 v197; // xmm4
  __m128 v198; // xmm8
  __m128 v199; // xmm7
  __m128 v200; // xmm5
  __m128 v201; // xmm2
  __m128 v202; // xmm4
  __m128 v203; // xmm3
  __m128 v204; // xmm2
  __m128 v205; // xmm0
  float v206; // xmm1_4
  __int64 v207; // r14
  hkVector4f *v208; // rdi
  hkVector4f *v209; // rsi
  hkVector4f *v210; // rbx
  hkgpMeshBase::Triangle *v211; // rax
  hkgpMeshBase::Triangle *v212; // r15
  unsigned int v213; // edi
  unsigned int v214; // ebx
  hkOstream *v215; // rax
  hkOstream *v216; // rax
  hkOstream *v217; // rax
  hkOstream *v218; // rax
  hkOstream *v219; // rax
  hkOstream *v220; // rax
  hkOstream *v221; // rax
  char *v222; // [rsp+40h] [rbp-C0h] BYREF
  int v223; // [rsp+48h] [rbp-B8h]
  int v224; // [rsp+4Ch] [rbp-B4h]
  _QWORD *v225; // [rsp+50h] [rbp-B0h] BYREF
  int v226; // [rsp+58h] [rbp-A8h]
  int v227; // [rsp+5Ch] [rbp-A4h]
  float *v228; // [rsp+60h] [rbp-A0h] BYREF
  unsigned int v229; // [rsp+68h] [rbp-98h]
  int v230; // [rsp+6Ch] [rbp-94h]
  int v231; // [rsp+70h] [rbp-90h]
  _QWORD *v232; // [rsp+78h] [rbp-88h] BYREF
  int v233; // [rsp+80h] [rbp-80h]
  int v234; // [rsp+84h] [rbp-7Ch]
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> edges; // [rsp+88h] [rbp-78h] BYREF
  int v236; // [rsp+98h] [rbp-68h]
  int v237; // [rsp+9Ch] [rbp-64h]
  int i; // [rsp+A0h] [rbp-60h]
  hkVector4f *array; // [rsp+A8h] [rbp-58h] BYREF
  int v240; // [rsp+B0h] [rbp-50h]
  int v241; // [rsp+B4h] [rbp-4Ch]
  int v242; // [rsp+B8h] [rbp-48h]
  int v243; // [rsp+BCh] [rbp-44h]
  hkVector4f uv; // [rsp+C0h] [rbp-40h] BYREF
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> data; // [rsp+D0h] [rbp-30h] BYREF
  hkgpMeshBase::Triangle *v246; // [rsp+F0h] [rbp-10h]
  hkResult v247; // [rsp+F8h] [rbp-8h] BYREF
  int v248; // [rsp+FCh] [rbp-4h]
  int m_numUsed; // [rsp+100h] [rbp+0h]
  __int64 v250; // [rsp+108h] [rbp+8h]
  hkResult result; // [rsp+110h] [rbp+10h] BYREF
  __int64 v252; // [rsp+118h] [rbp+18h]
  hkgpMeshInternals::Ring *v253; // [rsp+120h] [rbp+20h]
  hkVector4f planeNormal; // [rsp+130h] [rbp+30h] BYREF
  __int64 v255; // [rsp+140h] [rbp+40h]
  __int64 v256; // [rsp+148h] [rbp+48h]
  __int64 v257; // [rsp+150h] [rbp+50h]
  hkStridedVertices points; // [rsp+158h] [rbp+58h] BYREF
  __int64 v259; // [rsp+170h] [rbp+70h]
  hkgpConvexHull::BuildConfig configa; // [rsp+178h] [rbp+78h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge edge; // [rsp+188h] [rbp+88h] BYREF
  hkgpMeshBase::Edge v262; // [rsp+1A0h] [rbp+A0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location location; // [rsp+1B0h] [rbp+B0h] BYREF
  hkgpConvexHull v264; // [rsp+1C8h] [rbp+C8h] BYREF
  hkgpMeshBase::Edge v265; // [rsp+1F0h] [rbp+F0h] BYREF
  __int64 v266; // [rsp+208h] [rbp+108h]
  __int64 v267; // [rsp+218h] [rbp+118h]
  hkVector4f dmin; // [rsp+220h] [rbp+120h] BYREF
  hkVector4f dmax; // [rsp+230h] [rbp+130h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> v270; // [rsp+240h] [rbp+140h] BYREF
  char buf[512]; // [rsp+F40h] [rbp+E40h] BYREF
  unsigned int v274; // [rsp+1238h] [rbp+1138h]
  char v275; // [rsp+1240h] [rbp+1140h]
  int v276; // [rsp+1240h] [rbp+1140h]
  int v277; // [rsp+1248h] [rbp+1148h]
  int v278; // [rsp+1248h] [rbp+1148h]

  m_numUsed = this->m_triangles.m_numUsed;
  v2 = this->m_vertices.m_numUsed;
  v3 = 0i64;
  v4 = config;
  v5 = this;
  i = 0;
  v248 = v2;
  v237 = 0;
  array = 0i64;
  v6 = 0;
  v240 = 0;
  v241 = 0x80000000;
  v7 = &aabbOut;
  while ( 1 )
  {
    v8 = &aabbOut;
    for ( j = _mm_shuffle_ps(
                _mm_unpacklo_ps((__m128)0i64, _mm_mul_ps((__m128)xmmword_141A71200, v7->m_quad)),
                (__m128)0i64,
                228); ; j = uv.m_quad )
    {
      j.m128_f32[0] = 0.14285715 * v8->m_quad.m128_f32[0];
      uv.m_quad = j;
      if ( v6 == (v241 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v6 = v240;
      }
      v240 = v6 + 1;
      hkGeometryProcessing::octahedronToNormal(&uv, &array[v6]);
      if ( (__int64)++v8 >= (__int64)&xmmword_141A71130 )
        break;
      v6 = v240;
    }
    if ( (__int64)++v7 >= (__int64)&xmmword_141A71130 )
      break;
    v6 = v240;
  }
  if ( v4->m_fillRings )
  {
    v10 = 0;
    v224 = 0x80000000;
    v222 = 0i64;
    v223 = 0;
    while ( 1 )
    {
      m_used = v5->m_triangles.m_used;
      v12 = 0;
      v275 = 0;
      v246 = m_used;
      if ( !m_used )
      {
LABEL_204:
        v223 = 0;
        if ( v224 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v222, 8 * v224);
        v4 = config;
        goto LABEL_207;
      }
LABEL_12:
      v13 = 0;
      v242 = 0;
      while ( 1 )
      {
        v262.m_triangle = m_used;
        v262.m_index = v13;
        if ( (m_used->m_links[v13] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        {
          v265 = v262;
          v14 = hkgpMeshInternals::createRing(&v265);
          v15 = v14;
          v253 = v14;
          if ( v14 )
          {
            if ( v14->m_segments.m_size >= 3 )
              break;
          }
        }
LABEL_202:
        v242 = ++v13;
        if ( v13 >= 3 )
        {
          m_used = m_used->m_next;
          v246 = m_used;
          if ( !m_used )
            goto LABEL_204;
          goto LABEL_12;
        }
      }
      v16 = 0;
      v223 = 0;
      if ( v14->m_segments.m_size > 0 )
      {
        v17 = 0i64;
        do
        {
          m_index = (int)v15->m_segments.m_data[v17].m_edge.m_index;
          m_triangle = v15->m_segments.m_data[v17].m_edge.m_triangle;
          if ( v16 == (v224 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v222, 8);
            v16 = v223;
          }
          *(_QWORD *)&v222[8 * v16] = m_triangle->m_vertices[m_index];
          ++v10;
          v16 = v223 + 1;
          ++v17;
          ++v223;
        }
        while ( v10 < v15->m_segments.m_size );
        v5 = this;
        v12 = v275;
      }
      hkgpConvexHull::hkgpConvexHull(&v264);
      v20 = v223;
      v10 = 0;
      v228 = 0i64;
      v229 = 0;
      v230 = 0x80000000;
      v21 = v223;
      if ( v223 <= 0 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v228, v223, 16);
        v20 = v223;
      }
      v229 = v21;
      v22 = 0;
      if ( v20 > 0 )
      {
        v23 = 0i64;
        v24 = 0i64;
        do
        {
          ++v22;
          v24 += 8i64;
          v23 += 4i64;
          *(_OWORD *)&v228[v23 - 4] = *(_OWORD *)(*(_QWORD *)&v222[v24 - 8] + 32i64);
        }
        while ( v22 < v223 );
      }
      hkgpConvexHull::BuildConfig::BuildConfig(&configa);
      points.m_vertices = v228;
      configa.m_allowLowerDimensions.m_bool = 1;
      points.m_striding = 16;
      points.m_numVertices = v229;
      hkgpConvexHull::build(&v264, &points, &configa);
      if ( (int)hkgpConvexHull::getDimensions(&v264) >= 2 )
      {
        hkgpConvexHull::getBestProjectionPlane(&v264, &planeNormal);
        v25 = 0;
        v250 = 0i64;
        v243 = 0;
        while ( 1 )
        {
          if ( v25 >= v240 + 1 )
          {
LABEL_197:
            m_used = v246;
            v13 = v242;
            v10 = 0;
            goto LABEL_198;
          }
          v270.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable;
          memset(&v270.m_mesh.m_vertices, 0, 20);
          v270.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          v270.m_edgeDataPolicy = 0i64;
          dmin.m_quad = (__m128)_xmm;
          dmax.m_quad = _xmm;
          v270.m_stack.m_data = v270.m_stack.m_storage;
          *(_DWORD *)&v270.m_memSizeAndFlags = 0x1FFFF;
          *(_DWORD *)&v270.m_mesh.m_memSizeAndFlags = 0x1FFFF;
          memset(&v270.m_mesh.m_triangles, 0, 20);
          v270.m_stack.m_size = 0;
          v270.m_stack.m_capacityAndFlags = -2147483584;
          v270.m_status.m_storage = 0;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomain(
            &v270,
            &dmin,
            &dmax,
            0.0,
            1);
          uv.m_quad.m128_u64[0] = (unsigned __int64)v228;
          v26 = 1;
          uv.m_quad.m128_u64[1] = v229 | 0x1000000000i64;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomainFromPlanarPoints(
            &v270,
            (hkStridedVertices *)&uv,
            &planeNormal,
            1,
            1,
            0);
          v27 = 0;
          if ( v223 > 0 )
          {
            v28 = 0i64;
            do
            {
              m_margin = v270.m_margin;
              v30 = 0x7FFF - v270.m_margin;
              v31 = *(__m128 *)(*(_QWORD *)&v222[v28] + 32i64);
              v32 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v270.m_worldToLocal.m_col0.m_quad),
                          v270.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v270.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v270.m_worldToLocal.m_col2.m_quad));
              v33 = _mm_cmplt_ps(v32, (__m128)0i64);
              v34 = _mm_or_ps(
                      _mm_andnot_ps(v33, _mm_add_ps((__m128)xmmword_141A711B0, v32)),
                      _mm_and_ps(_mm_sub_ps(v32, (__m128)xmmword_141A711B0), v33));
              v35 = _mm_xor_si128(
                      (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v34),
                      _mm_cvttps_epi32(v34));
              v36 = _mm_cvtsi128_si32(v35);
              if ( v36 >= v270.m_margin )
              {
                if ( v36 > v30 )
                  v36 = 0x7FFF - v270.m_margin;
              }
              else
              {
                v36 = v270.m_margin;
              }
              v37 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v35, 85));
              if ( v37 >= v270.m_margin )
              {
                m_margin = v37;
                if ( v37 > v30 )
                  m_margin = 0x7FFF - v270.m_margin;
              }
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
                &v270,
                &location,
                v36,
                m_margin);
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(
                &v270,
                (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&data,
                v36,
                m_margin,
                1,
                &location,
                0);
              if ( LODWORD(data.m_tags.m_data) )
              {
                v26 = 0;
              }
              else
              {
                v38 = *(_QWORD *)(*(_QWORD *)&data.m_tags.m_size + 8i64 * SLODWORD(data.m_tags.m_storage[0]) + 16);
                *(_QWORD *)(v38 + 24) = *(_DWORD *)(v38 + 24) & 3 | (unsigned __int64)(4i64 * v27);
              }
              ++v27;
              v28 += 8i64;
            }
            while ( v27 < v223 );
          }
          v39 = v15->m_segments.m_size <= 0;
          v40 = 0;
          v225 = 0i64;
          v226 = 0;
          v227 = 0x80000000;
          v41 = 0;
          if ( !v39 )
          {
            v42 = 0i64;
            while ( 1 )
            {
              m_data = v15->m_segments.m_data;
              if ( v40 == (v227 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v225, 16);
                v40 = v226;
              }
              v44 = (hkgpMeshBase::Triangle **)&v225[2 * v40];
              if ( v44 )
              {
                *v44 = m_data[v42].m_edge.m_triangle;
                v44[1] = *(hkgpMeshBase::Triangle **)&m_data[v42].m_edge.m_index;
                v40 = v226;
              }
              v45 = v15->m_segments.m_data;
              v46 = v40 + 1;
              v226 = v46;
              v47 = v45[v42].m_edge.m_triangle;
              LODWORD(v266) = (9 >> (2 * LOBYTE(v45[v42].m_edge.m_index))) & 3;
              if ( v46 == (v227 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v225, 16);
                v46 = v226;
              }
              v48 = (hkgpMeshBase::Triangle **)&v225[2 * v46];
              if ( v48 )
              {
                v49 = v266;
                *v48 = v47;
                v48[1] = (hkgpMeshBase::Triangle *)v49;
                v46 = v226;
              }
              v50 = v15->m_segments.m_data;
              v51 = v46 + 1;
              v226 = v51;
              v52 = v50[v42].m_edge.m_triangle;
              LODWORD(v267) = (18 >> (2 * LOBYTE(v50[v42].m_edge.m_index))) & 3;
              if ( v51 == (v227 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v225, 16);
                v51 = v226;
              }
              v53 = (hkgpMeshBase::Triangle **)&v225[2 * v51];
              if ( v53 )
              {
                v54 = v267;
                *v53 = v52;
                v53[1] = (hkgpMeshBase::Triangle *)v54;
                v51 = v226;
              }
              *(_QWORD *)&data.m_tags.m_size = 0x8000000200000001ui64;
              v226 = v51 + 1;
              v55 = v270.m_margin;
              data.m_tags.m_storage[0] = v41;
              v56 = v15->m_segments.m_data;
              data.m_tags.m_data = data.m_tags.m_storage;
              v57 = v56[v42].m_edge.m_triangle;
              v58 = *(_QWORD *)&v56[v42].m_edge.m_index;
              v59 = 0x7FFF - v270.m_margin;
              m_quad = v57->m_vertices[(int)v58]->m_position.m_quad;
              v61 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v270.m_worldToLocal.m_col0.m_quad),
                          v270.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v270.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v270.m_worldToLocal.m_col2.m_quad));
              v62 = _mm_cmplt_ps(v61, (__m128)0i64);
              v63 = _mm_or_ps(
                      _mm_andnot_ps(v62, _mm_add_ps((__m128)xmmword_141A711B0, v61)),
                      _mm_and_ps(_mm_sub_ps(v61, (__m128)xmmword_141A711B0), v62));
              v64 = _mm_xor_si128(
                      (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v63),
                      _mm_cvttps_epi32(v63));
              v65 = _mm_cvtsi128_si32(v64);
              if ( v65 >= v270.m_margin )
              {
                if ( v65 > v59 )
                  v65 = 0x7FFF - v270.m_margin;
              }
              else
              {
                v65 = v270.m_margin;
              }
              v66 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v64, 85));
              if ( v66 >= v270.m_margin )
              {
                if ( v66 > v59 )
                  v66 = 0x7FFF - v270.m_margin;
              }
              else
              {
                v66 = v270.m_margin;
              }
              v67 = v57->m_vertices[(9i64 >> (2 * (unsigned __int8)v58)) & 3]->m_position.m_quad;
              v68 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), v270.m_worldToLocal.m_col0.m_quad),
                          v270.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), v270.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 170), v270.m_worldToLocal.m_col2.m_quad));
              v69 = _mm_cmplt_ps(v68, (__m128)0i64);
              v70 = _mm_or_ps(
                      _mm_andnot_ps(v69, _mm_add_ps((__m128)xmmword_141A711B0, v68)),
                      _mm_and_ps(_mm_sub_ps(v68, (__m128)xmmword_141A711B0), v69));
              v71 = _mm_xor_si128(
                      (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v70),
                      _mm_cvttps_epi32(v70));
              v72 = _mm_cvtsi128_si32(v71);
              if ( v72 >= v270.m_margin )
              {
                if ( v72 > v59 )
                  v72 = 0x7FFF - v270.m_margin;
              }
              else
              {
                v72 = v270.m_margin;
              }
              v73 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v71, 85));
              if ( v73 >= v270.m_margin )
              {
                v55 = v73;
                if ( v73 > v59 )
                  v55 = 0x7FFF - v270.m_margin;
              }
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertEdge(
                &v270,
                (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&location,
                v65,
                v66,
                v72,
                v55,
                1,
                &data);
              data.m_tags.m_size = 0;
              if ( location.m_type.m_storage )
                v26 = 0;
              if ( data.m_tags.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  data.m_tags.m_data,
                  8 * data.m_tags.m_capacityAndFlags);
              ++v41;
              ++v42;
              if ( v41 >= v15->m_segments.m_size )
                break;
              v40 = v226;
            }
          }
          LODWORD(v74) = v26;
          if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(&v270) < 2 )
            LODWORD(v74) = 0;
          v236 = (int)v74;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(&v270);
          v75 = v222;
          m_next = v270.m_mesh.m_triangles.m_used;
          v77 = 0;
          v277 = 0;
          do
          {
            if ( (_BYTE)v74 )
            {
              while ( m_next )
              {
                if ( (*((_WORD *)m_next + 33) & 0xFFE0) == 32 )
                {
                  v78 = 0;
                  while ( v78 < 3 )
                  {
                    if ( (*(_WORD *)((m_next->m_links[v78] & 0xFFFFFFFFFFFFFFFCui64) + 66) & 0xFFE0) == 32 )
                    {
                      v79 = (9i64 >> (2 * (unsigned __int8)v78)) & 3;
                      v80 = (int)(*((_QWORD *)m_next->m_vertices[v78] + 3) >> 2);
                      v256 = v79;
                      v81 = *(_QWORD *)&v75[8 * v80];
                      v82 = *((_QWORD *)m_next->m_vertices[v79] + 3);
                      v257 = v81;
                      v83 = *(_QWORD *)&v75[8 * (int)(v82 >> 2)];
                      v84 = 0i64;
                      v252 = v83;
                      v85 = 0;
                      v231 = 0;
                      v255 = 0i64;
                      if ( v226 > 0 )
                      {
                        while ( 1 )
                        {
                          if ( *(_QWORD *)(v225[2 * v84] + 8i64 * SLODWORD(v225[2 * v84 + 1]) + 16) == v81
                            && *(_QWORD *)(v225[2 * v84] + 8 * ((9i64 >> (2 * LOBYTE(v225[2 * v84 + 1]))) & 3) + 16) == v83
                            || *(_QWORD *)(v225[2 * v84] + 8i64 * SLODWORD(v225[2 * v84 + 1]) + 16) == v83
                            && *(_QWORD *)(v225[2 * v84] + 8 * ((9i64 >> (2 * LOBYTE(v225[2 * v84 + 1]))) & 3) + 16) == v81 )
                          {
                            v86 = m_next->m_links[v78];
                            if ( (v86 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                            {
                              v87 = m_next->m_vertices[v79];
                              v88 = m_next->m_vertices[v78];
                              m_x = v88->m_x;
                              v90 = v87->m_x;
                              if ( m_x < v90 || m_x <= v90 && v88->m_y <= v87->m_y )
                              {
                                v92 = (unsigned __int64)m_next;
                                LOBYTE(v91) = v78;
                              }
                              else
                              {
                                v91 = m_next->m_links[v78] & 3;
                                v92 = v86 & 0xFFFFFFFFFFFFFFFCui64;
                              }
                              if ( ((1 << v91) & 7 & *(_BYTE *)(v92 + 66)) == 0 )
                              {
                                v93 = m_next->m_links[v78] & 3;
                                v94 = v86 & 0xFFFFFFFFFFFFFFFCui64;
                                v95 = (18 >> (2 * v78)) & 3;
                                v96 = *(_QWORD *)(v94 + 8i64 * ((18 >> (2 * v93)) & 3) + 16);
                                v74 = m_next->m_vertices[v95];
                                m_y = v74->m_y;
                                v98 = v74->m_x;
                                if ( (v88->m_x - v98) * (*(_DWORD *)(v96 + 20) - m_y)
                                   - (v88->m_y - m_y) * (*(_DWORD *)(v96 + 16) - v98) > 0 )
                                {
                                  v99 = *(_QWORD *)(v94 + 8i64 * (int)v93 + 16);
                                  if ( (*(_DWORD *)(v99 + 16) - *(_DWORD *)(v96 + 16)) * (m_y - *(_DWORD *)(v96 + 20))
                                     - (*(_DWORD *)(v99 + 20) - *(_DWORD *)(v96 + 20)) * (v98 - *(_DWORD *)(v96 + 16)) > 0 )
                                  {
                                    v100 = m_next->m_vertices[v95];
                                    v101 = m_next->m_vertices[(9i64 >> (2 * (unsigned __int8)v95)) & 3];
                                    v102 = v100->m_x;
                                    v103 = v101->m_x;
                                    if ( v102 >= v103
                                      && (v102 > v103 || v100->m_y > v101->m_y)
                                      && (v104 = m_next->m_links[v95], (v104 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
                                    {
                                      v105 = m_next->m_links[v95] & 3;
                                      v106 = v104 & 0xFFFFFFFFFFFFFFFCui64;
                                    }
                                    else
                                    {
                                      v106 = (unsigned __int64)m_next;
                                      LOBYTE(v105) = (18 >> (2 * v78)) & 3;
                                    }
                                    v107 = *(_WORD *)(v106 + 66);
                                    v108 = (unsigned __int8)v107 & (1 << v105) & 7;
                                    *(_WORD *)(v106 + 66) = v107 & (~((unsigned __int8)v107 & (1 << v105) & 7) | 0xFFF8);
                                    v109 = m_next->m_links[v78];
                                    v110 = 2 * (v109 & 3);
                                    v111 = v109 & 0xFFFFFFFFFFFFFFFCui64;
                                    LODWORD(v106) = (18 >> v110) & 3;
                                    v112 = *(_QWORD *)(v111 + 8i64 * (int)v106 + 16);
                                    v113 = *(_QWORD *)(v111 + 8 * ((9i64 >> (2 * ((18 >> v110) & 3u))) & 3) + 16);
                                    v114 = *(_DWORD *)(v112 + 16);
                                    v115 = *(_DWORD *)(v113 + 16);
                                    if ( v114 >= v115
                                      && (v114 > v115 || *(_DWORD *)(v112 + 20) > *(_DWORD *)(v113 + 20))
                                      && (v116 = *(_QWORD *)(v111 + 8i64 * (int)v106 + 40),
                                          (v116 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
                                    {
                                      v106 = *(_QWORD *)(v111 + 8i64 * (int)v106 + 40) & 3i64;
                                      v117 = v116 & 0xFFFFFFFFFFFFFFFCui64;
                                    }
                                    else
                                    {
                                      v117 = v111;
                                    }
                                    v118 = *(_WORD *)(v117 + 66);
                                    v119 = (unsigned __int8)v118 & (1 << v106) & 7;
                                    *(_WORD *)(v117 + 66) = v118 & (~((unsigned __int8)v118 & (1 << v106) & 7) | 0xFFF8);
                                    v120 = m_next->m_links[v78] & 0xFFFFFFFFFFFFFFFCui64;
                                    v121 = m_next->m_links[v78] & 3;
                                    v122 = (18 >> (2 * v121)) & 3;
                                    m_next->m_vertices[v78] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(v120 + 8i64 * v122 + 16);
                                    *(_QWORD *)(v120 + 8i64 * (int)v121 + 16) = m_next->m_vertices[v95];
                                    v123 = m_next->m_links[v95] & 0xFFFFFFFFFFFFFFFCui64;
                                    v124 = m_next->m_links[v95] & 3;
                                    *(_QWORD *)(v120 + 8i64 * (int)v121 + 40) = m_next->m_links[v95];
                                    if ( v123 )
                                      *(_QWORD *)(v123 + 8i64 * (int)v124 + 40) = v120 + (unsigned int)v121;
                                    v125 = *(_QWORD *)(v120 + 8i64 * v122 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                                    v126 = *(_QWORD *)(v120 + 8i64 * v122 + 40) & 3i64;
                                    m_next->m_links[v78] = *(_QWORD *)(v120 + 8i64 * v122 + 40);
                                    if ( v125 )
                                      *(_QWORD *)(v125 + 8i64 * (int)v126 + 40) = (char *)m_next + (unsigned int)v78;
                                    m_next->m_links[v95] = v120 + (unsigned int)v122;
                                    if ( v120 )
                                      *(_QWORD *)(v120 + 8i64 * v122 + 40) = (char *)m_next + (unsigned int)v95;
                                    if ( v108 )
                                    {
                                      v127 = m_next->m_links[v95];
                                      v128 = 2 * (v127 & 3);
                                      v129 = v127 & 0xFFFFFFFFFFFFFFFCui64;
                                      LODWORD(v130) = (9 >> v128) & 3;
                                      v131 = *(_QWORD *)(v129 + 8i64 * (int)v130 + 16);
                                      v132 = *(_QWORD *)(v129 + 8 * ((9i64 >> (2 * ((9 >> v128) & 3u))) & 3) + 16);
                                      v133 = *(_DWORD *)(v131 + 16);
                                      v134 = *(_DWORD *)(v132 + 16);
                                      if ( v133 >= v134
                                        && (v133 > v134 || *(_DWORD *)(v131 + 20) > *(_DWORD *)(v132 + 20))
                                        && (v135 = *(_QWORD *)(v129 + 8i64 * (int)v130 + 40),
                                            (v135 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
                                      {
                                        v130 = *(_QWORD *)(v129 + 8i64 * (int)v130 + 40) & 3i64;
                                        v136 = v135 & 0xFFFFFFFFFFFFFFFCui64;
                                      }
                                      else
                                      {
                                        v136 = v129;
                                      }
                                      *(_WORD *)(v136 + 66) |= (1 << v130) & 7;
                                    }
                                    if ( v119 )
                                    {
                                      LODWORD(v137) = (9 >> (2 * v95)) & 3;
                                      v138 = m_next->m_vertices[(int)v137];
                                      v139 = m_next->m_vertices[(9i64 >> (2 * ((9 >> (2 * v95)) & 3u))) & 3];
                                      v140 = v138->m_x;
                                      v141 = v139->m_x;
                                      if ( v140 >= v141
                                        && (v140 > v141 || v138->m_y > v139->m_y)
                                        && (v142 = m_next->m_links[(int)v137], (v142 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
                                      {
                                        v137 = m_next->m_links[(int)v137] & 3;
                                        v143 = v142 & 0xFFFFFFFFFFFFFFFCui64;
                                      }
                                      else
                                      {
                                        v143 = (unsigned __int64)m_next;
                                      }
                                      *(_WORD *)(v143 + 66) ^= ((unsigned __int8)*(_WORD *)(v143 + 66) ^ (unsigned __int8)(*(_WORD *)(v143 + 66) | (1 << v137))) & 7;
                                    }
                                    LODWORD(v74) = v236;
                                    v85 = v231;
                                    v83 = v252;
                                    v77 = -1;
                                    v277 = -1;
                                    goto LABEL_143;
                                  }
                                }
                                v85 = v231;
                              }
                            }
                            v83 = v252;
                            LOBYTE(v74) = 0;
                            v236 = (int)v74;
                          }
                          v77 = v277;
LABEL_143:
                          v79 = v256;
                          v81 = v257;
                          ++v85;
                          v84 = ++v255;
                          v231 = v85;
                          if ( v85 >= v226 )
                          {
                            v75 = v222;
                            goto LABEL_146;
                          }
                        }
                      }
                    }
                    v77 = v277;
LABEL_146:
                    ++v78;
                    if ( !(_BYTE)v74 )
                      goto LABEL_87;
                  }
                  v77 = v277;
                }
                else
                {
                  v77 = v277;
                }
LABEL_87:
                m_next = m_next->m_next;
                if ( !(_BYTE)v74 )
                  goto LABEL_150;
              }
              v77 = v277;
LABEL_150:
              m_next = v270.m_mesh.m_triangles.m_used;
            }
            v277 = ++v77;
          }
          while ( v77 < 1 );
          if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeDataOrientation(&v270)
            || !(_BYTE)v74 )
          {
            break;
          }
          v144 = v223;
          edges.m_data = 0i64;
          edges.m_size = 0;
          edges.m_capacityAndFlags = 0x80000000;
          v232 = 0i64;
          v233 = 0;
          v278 = v223;
          v234 = 0x80000000;
          if ( m_next )
          {
            v145 = v253;
            do
            {
              if ( (*((_WORD *)m_next + 33) & 0xFFE0) == 32 )
              {
                v146 = *(hkVector4f **)&v75[8 * (int)(*((_QWORD *)m_next->m_vertices[0] + 3) >> 2)];
                v147 = *(hkVector4f **)&v75[8 * (int)(*((_QWORD *)m_next->m_vertices[1] + 3) >> 2)];
                v148 = *(hkVector4f **)&v75[8 * (int)(*((_QWORD *)m_next->m_vertices[2] + 3) >> 2)];
                v149 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
                v150 = (__int64)v246;
                v149->m_partId = v246->m_partId;
                v149->m_links[0] = 0i64;
                v149->m_links[1] = 0i64;
                v149->m_links[2] = 0i64;
                v149->m_material = *(_DWORD *)(v150 + 88);
                v149->m_vertices[0] = (hkgpMeshBase::Vertex *)v146;
                v149->m_vertices[1] = (hkgpMeshBase::Vertex *)v147;
                v149->m_vertices[2] = (hkgpMeshBase::Vertex *)v148;
                hkgpMesh::setPlane(this, v146 + 2, v147 + 2, v148 + 2, &v149->m_plane, 1);
                for ( k = 0; k < 3; ++k )
                {
                  v152 = m_next->m_links[k];
                  edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(m_next->m_links[k] & 0xFFFFFFFFFFFFFFFCui64);
                  edge.m_index = v152 & 3;
                  EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
                               &v270,
                               &edge);
                  if ( EdgeData )
                  {
                    v154 = (__int64)&v145->m_segments.m_data[(__int64)*(int *)EdgeData->m_tags.m_data];
                    v149->m_links[k] = *(_QWORD *)v154 + *(unsigned int *)(v154 + 8);
                    if ( *(_QWORD *)v154 )
                      *(_QWORD *)(*(_QWORD *)v154 + 8i64 * *(int *)(v154 + 8) + 40) = (char *)v149 + (unsigned int)k;
                  }
                  else
                  {
                    LODWORD(v259) = k;
                    if ( edges.m_size == (edges.m_capacityAndFlags & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&edges.m_data, 16);
                    v155 = &edges.m_data[edges.m_size];
                    if ( v155 )
                    {
                      v156 = v259;
                      v155->m_triangle = v149;
                      *(_QWORD *)&v155->m_index = v156;
                    }
                    ++edges.m_size;
                  }
                }
                v157 = v233;
                if ( v233 == (v234 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v232, 8);
                  v157 = v233;
                }
                v232[v157] = v149;
                ++v233;
                v75 = v222;
              }
              m_next = m_next->m_next;
            }
            while ( m_next );
            LOBYTE(v74) = v236;
            v144 = v278;
          }
          v5 = this;
          hkgpMesh::bindEdgeList(this, &edges);
          if ( edges.m_size )
          {
            LOBYTE(v74) = 0;
            v158 = 0;
            if ( v233 > 0 )
            {
              v159 = 0i64;
              do
              {
                hkgpMesh::removeTriangle(this, (hkgpMeshBase::Triangle *)v232[v159]);
                ++v158;
                ++v159;
              }
              while ( v158 < v233 );
            }
            v160 = v144;
            if ( v144 < v223 )
            {
              v161 = 8i64 * v144;
              do
              {
                hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::release(
                  &this->m_vertices,
                  *(hkgpMeshBase::Vertex **)&v222[v161]);
                ++v160;
                v161 += 8i64;
              }
              while ( v160 < v223 );
            }
            if ( (v224 & 0x3FFFFFFF) >= v144 )
            {
              v247.m_enum = HK_SUCCESS;
            }
            else
            {
              v162 = v144;
              if ( v144 < 2 * (v224 & 0x3FFFFFFF) )
                v162 = 2 * (v224 & 0x3FFFFFFF);
              hkArrayUtil::_reserve(&v247, &hkContainerHeapAllocator::s_alloc, (const void **)&v222, v162, 8);
            }
            v223 = v144;
          }
          else
          {
            ++i;
            v275 = 1;
          }
          v233 = 0;
          if ( v234 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v232, 8 * v234);
          v232 = 0i64;
          v234 = 0x80000000;
          edges.m_size = 0;
          if ( edges.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              edges.m_data,
              16 * edges.m_capacityAndFlags);
          edges.m_data = 0i64;
          edges.m_capacityAndFlags = 0x80000000;
          if ( !(_BYTE)v74 )
            goto LABEL_220;
          v163 = v250;
LABEL_192:
          v226 = 0;
          if ( v227 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v225, 16 * v227);
          v225 = 0i64;
          v227 = 0x80000000;
          v270.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(
            &v270,
            1);
          hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(&v270.m_edgeDataPolicy);
          v270.m_stack.m_size = 0;
          if ( v270.m_stack.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v270.m_stack.m_data,
              16 * v270.m_stack.m_capacityAndFlags);
          v270.m_stack.m_data = 0i64;
          v270.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable;
          v270.m_stack.m_capacityAndFlags = 0x80000000;
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&v270.m_mesh.m_triangles);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>(&v270.m_mesh.m_triangles.m_allocator);
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset(&v270.m_mesh.m_vertices);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>(&v270.m_mesh.m_vertices.m_allocator);
          v12 = v275;
          v15 = v253;
          v25 = ++v243;
          v250 = v163 + 1;
          if ( v275 )
            goto LABEL_197;
        }
        v5 = this;
LABEL_220:
        v163 = v250;
        if ( v250 )
          planeNormal.m_quad = (__m128)array[v250 - 1];
        goto LABEL_192;
      }
LABEL_198:
      hkgpMeshInternals::Ring::`scalar deleting destructor(v15, 1u);
      v229 = 0;
      if ( !v12 )
        break;
      if ( v230 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v228, 16 * v230);
      v228 = 0i64;
      v230 = 0x80000000;
      hkgpConvexHull::~hkgpConvexHull(&v264);
    }
    if ( v230 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v228, 16 * v230);
    v228 = 0i64;
    v230 = 0x80000000;
    hkgpConvexHull::~hkgpConvexHull(&v264);
    goto LABEL_202;
  }
LABEL_207:
  v164 = this;
  if ( v4->m_fillAFM )
  {
    while ( 1 )
    {
      v165 = (__m128 *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      v166 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard;
      for ( m = 1; ; m = 0 )
      {
        if ( (v166 & 1) == 0 )
        {
          v166 |= 1u;
          v165 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard = v166;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        }
        v168 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        v169 = v165;
        v274 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        if ( (v166 & 1) == 0 )
        {
          v166 |= 1u;
          v165 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard = v166;
        }
        v170 = (__m128 *)v164->m_triangles.m_used;
        v171 = BYTE8(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        v172 = 3.40282e38;
        v173 = v165;
        v276 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e);
        if ( v170 )
        {
          while ( 1 )
          {
            for ( n = 0; n < 3; ++n )
            {
              LODWORD(v259) = n;
              if ( (v170[2].m128_u64[n + 1] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
              {
                v175 = (unsigned __int64)v170;
                v176 = (9 >> (2 * n)) & 3;
                if ( (v170[2].m128_u64[v176 + 1] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                {
                  while ( 1 )
                  {
                    v177 = *(_QWORD *)(v175 + 8i64 * v176 + 40);
                    v178 = 2 * (v177 & 3);
                    v179 = (__m128 *)(v177 & 0xFFFFFFFFFFFFFFFCui64);
                    uv.m_quad.m128_u64[0] = (unsigned __int64)v179;
                    v180 = (9 >> v178) & 3;
                    uv.m_quad.m128_i32[2] = v180;
                    v181 = (v179[2].m128_u64[v180 + 1] & 0xFFFFFFFFFFFFFFFCui64) == 0;
                    planeNormal.m_quad = uv.m_quad;
                    if ( v181 )
                      break;
                    v176 = planeNormal.m_quad.m128_i32[2];
                    v175 = planeNormal.m_quad.m128_u64[0];
                  }
                  if ( v179 != v170 )
                  {
                    v182 = *(__m128 *)(v170[1].m128_u64[(9i64 >> (2 * (unsigned __int8)n)) & 3] + 32);
                    v183 = _mm_sub_ps(*(__m128 *)(v170[1].m128_u64[n] + 32), v182);
                    v184 = _mm_sub_ps(
                             *(__m128 *)(v179[1].m128_u64[(9i64 >> (2 * (unsigned __int8)v180)) & 3] + 32),
                             v182);
                    v185 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v183),
                             _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v184));
                    v186 = _mm_shuffle_ps(v185, v185, 201);
                    if ( !m
                      || (v187 = _mm_mul_ps(v170[4], v186),
                          (float)((float)(_mm_shuffle_ps(v187, v187, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v187, v187, 0).m128_f32[0])
                                + _mm_shuffle_ps(v187, v187, 170).m128_f32[0]) > v3.m128_f32[0])
                      && (v188 = _mm_mul_ps(v179[4], v186),
                          (float)((float)(_mm_shuffle_ps(v188, v188, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v188, v188, 0).m128_f32[0])
                                + _mm_shuffle_ps(v188, v188, 170).m128_f32[0]) > v3.m128_f32[0]) )
                    {
                      v189 = _mm_mul_ps(v183, v183);
                      v190 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v189, v189, 85), _mm_shuffle_ps(v189, v189, 0)),
                               _mm_shuffle_ps(v189, v189, 170));
                      v191 = _mm_rsqrt_ps(v190);
                      v192 = _mm_cmplt_ps(_mm_sub_ps(v3, v190), v3);
                      if ( _mm_movemask_ps(v192) )
                      {
                        v193 = _mm_mul_ps(v184, v184);
                        v194 = _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v193, v193, 85), _mm_shuffle_ps(v193, v193, 0)),
                                 _mm_shuffle_ps(v193, v193, 170));
                        v195 = _mm_cmplt_ps(_mm_sub_ps(v3, v194), v3);
                        v196 = _mm_rsqrt_ps(v194);
                        if ( _mm_movemask_ps(v195) )
                        {
                          v197 = _mm_mul_ps(
                                   _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmple_ps(v190, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v191, v190), v191)),
                                             _mm_mul_ps(v191, *(__m128 *)_xmm))),
                                         v183),
                                       v192),
                                     _mm_andnot_ps(v192, v183)),
                                   _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmple_ps(v194, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v196, v194), v196)),
                                             _mm_mul_ps(v196, *(__m128 *)_xmm))),
                                         v184),
                                       v195),
                                     _mm_andnot_ps(v195, v184)));
                          v198 = _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v197, v197, 85), _mm_shuffle_ps(v197, v197, 0)),
                                   _mm_shuffle_ps(v197, v197, 170));
                          v199 = _mm_andnot_ps(*(__m128 *)_xmm, v198);
                          v200 = _mm_cmplt_ps(*(__m128 *)_xmm, v199);
                          v201 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v199), *(__m128 *)_xmm);
                          v202 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v201), v200), _mm_andnot_ps(v200, v199));
                          v203 = _mm_or_ps(_mm_andnot_ps(v200, _mm_mul_ps(v199, v199)), _mm_and_ps(v200, v201));
                          v204 = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_add_ps(
                                                 _mm_mul_ps(
                                                   _mm_add_ps(_mm_mul_ps(v203, *(__m128 *)coeff4), *(__m128 *)coeff3),
                                                   v203),
                                                 *(__m128 *)coeff2),
                                               v203),
                                             *(__m128 *)coeff1),
                                           v203),
                                         *(__m128 *)coeff0),
                                       v203),
                                     v202),
                                   v202);
                          v205 = _mm_cmplt_ps(v199, *(__m128 *)_xmm);
                          v3 = 0i64;
                          v206 = 1.5707964
                               - COERCE_FLOAT((_mm_andnot_ps(
                                                 v205,
                                                 _mm_or_ps(
                                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v204, v204)), v200),
                                                   _mm_andnot_ps(v200, v204))).m128_u32[0] | v205.m128_i32[0] & v199.m128_i32[0]) ^ v198.m128_i32[0] & _xmm[0]);
                          if ( v206 < v172 )
                          {
                            v168 = v259;
                            v171 = uv.m_quad.m128_i8[8];
                            v169 = v170;
                            v172 = v206;
                            v274 = v259;
                            v276 = uv.m_quad.m128_i32[2];
                            v173 = v179;
                            continue;
                          }
                        }
                        else
                        {
                          v3 = 0i64;
                        }
                      }
                    }
                  }
                }
                v171 = v276;
              }
              v168 = v274;
            }
            v170 = (__m128 *)v170->m128_u64[0];
            if ( !v170 )
            {
              v164 = this;
              break;
            }
          }
        }
        if ( v169 )
          break;
        if ( !m )
          goto LABEL_245;
      }
      v207 = (int)v168;
      v208 = (hkVector4f *)v169[1].m128_u64[v168];
      v209 = (hkVector4f *)v169[1].m128_u64[(9i64 >> (2 * (unsigned __int8)v168)) & 3];
      v210 = (hkVector4f *)v173[1].m128_u64[(9i64 >> (2 * v171)) & 3];
      v211 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&v164->m_triangles);
      v211->m_partId = v169[5].m128_i32[0];
      v212 = v211;
      v211->m_links[0] = 0i64;
      v211->m_links[1] = 0i64;
      v211->m_links[2] = 0i64;
      v211->m_material = v169[5].m128_i32[2];
      v211->m_vertices[0] = (hkgpMeshBase::Vertex *)v209;
      v211->m_vertices[1] = (hkgpMeshBase::Vertex *)v208;
      v211->m_vertices[2] = (hkgpMeshBase::Vertex *)v210;
      hkgpMesh::setPlane(this, v209 + 2, v208 + 2, v210 + 2, &v211->m_plane, 1);
      v169[2].m128_u64[v207 + 1] = (unsigned __int64)v212;
      v212->m_links[0] = (unsigned __int64)v169 + v274;
      v212->m_links[2] = (unsigned __int64)v173 + (unsigned int)v276;
      if ( v173 )
        v173[2].m128_u64[v276 + 1] = (unsigned __int64)&v212->m_next + 2;
      ++v237;
      v164 = this;
    }
  }
LABEL_245:
  v164->m_hasPerVertexNormals = 0;
  hkErrStream::hkErrStream((hkErrStream *)&data, buf, 512);
  hkOstream::operator<<((hkOstream *)&data, "HOLE FILLING STATS:");
  hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2792);
  hkOstream::~hkOstream((hkOstream *)&data);
  hkErrStream::hkErrStream((hkErrStream *)&data, buf, 512);
  v213 = v164->m_vertices.m_numUsed - v248;
  v214 = v164->m_triangles.m_numUsed - m_numUsed;
  v215 = hkOstream::operator<<((hkOstream *)&data, "\tCreated: ");
  v216 = hkOstream::operator<<(v215, v214);
  v217 = hkOstream::operator<<(v216, " triangles and ");
  v218 = hkOstream::operator<<(v217, v213);
  hkOstream::operator<<(v218, " vertices");
  hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2793);
  hkOstream::~hkOstream((hkOstream *)&data);
  hkErrStream::hkErrStream((hkErrStream *)&data, buf, 512);
  v219 = hkOstream::operator<<((hkOstream *)&data, "\tRings: ");
  v220 = hkOstream::operator<<(v219, i);
  v221 = hkOstream::operator<<(v220, " AFM: ");
  hkOstream::operator<<(v221, v237);
  hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2794);
  hkOstream::~hkOstream((hkOstream *)&data);
  v240 = 0;
  if ( v241 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v241);
}cator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v241);
}

// File Line: 2799
// RVA: 0xCD1C90
void __fastcall hkgpMesh::fixTJunctions(hkgpMesh *this, float maxDistanceToEdgeR, bool report)
{
  double v3; // xmm2_8
  __m128 v5; // xmm8
  float v6; // xmm6_4
  hkgpMeshBase::Triangle *m_used; // r15
  char v8; // si
  int v9; // r12d
  hkgpMeshBase::Vertex *v10; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_trianglesTree; // rbx
  __m128 v12; // xmm0
  __m128 m_quad; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector> *v17; // r9
  hkcdDynamicTree::CodecRawUlong *m_cur; // rcx
  hkcdDynamicTree::CodecRawUlong *v19; // rdx
  int m_size; // eax
  char *m_firstFree; // rdi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  int v25; // r13d
  hkgpMeshBase::Edge v26; // xmm7
  __int64 v27; // r12
  hkgpMeshBase::Triangle *v28; // rsi
  int v29; // ebx
  hkVector4f **m_vertices; // rdi
  hkgpMeshBase::Vertex *v31; // r14
  hkVector4f *v32; // rdx
  hkVector4f *p_m_position; // r8
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  hkVector4f *v36; // r9
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  hkOstream *v39; // rax
  hkgpMeshBase::Vertex *v40; // r9
  int v41; // [rsp+30h] [rbp-90h]
  int i; // [rsp+34h] [rbp-8Ch]
  char *v43; // [rsp+38h] [rbp-88h] BYREF
  __int64 v44; // [rsp+40h] [rbp-80h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+48h] [rbp-78h] BYREF
  hkgpMeshBase::Edge v46; // [rsp+70h] [rbp-50h] BYREF
  hkSimdFloat32 result; // [rsp+80h] [rbp-40h] BYREF
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+90h] [rbp-30h] BYREF
  __m128 v49; // [rsp+B0h] [rbp-10h]
  char buf[64]; // [rsp+C0h] [rbp+0h] BYREF
  char v51[568]; // [rsp+100h] [rbp+40h] BYREF
  hkgpMesh *v52; // [rsp+340h] [rbp+280h]
  unsigned int v53; // [rsp+348h] [rbp+288h]
  char v54; // [rsp+350h] [rbp+290h]
  char v55; // [rsp+358h] [rbp+298h]

  hkErrStream::hkErrStream((hkErrStream *)&tree.m_root, v51, 512);
  hkOstream::operator<<(
    (hkOstream *)&tree.m_root,
    "hkgpMesh::fixTJunctions as been deprecated, use hkGeometryProcessing::fixTJunctions instead.");
  hkError::messageWarning(0xBDC2708E, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2800);
  hkOstream::~hkOstream((hkOstream *)&tree.m_root);
  i = 0;
  v5 = _mm_shuffle_ps((__m128)v53, (__m128)v53, 0);
  v6 = v5.m128_f32[0] * v5.m128_f32[0];
  hkgpMesh::rebuildTrianglesTree(this, 0.0, v3);
  do
  {
    m_used = this->m_triangles.m_used;
    v8 = 0;
    v55 = 0;
    if ( !m_used )
      break;
    do
    {
      v9 = 0;
      v41 = 0;
      do
      {
        *(_QWORD *)&tree.m_nodes.m_size = m_used;
        LODWORD(tree.m_firstFree) = v9;
        if ( (m_used->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        {
          v10 = m_used->m_vertices[v9];
          m_trianglesTree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_trianglesTree;
          v43 = 0i64;
          v12 = _mm_add_ps(v5, v5);
          v44 = 0x8000000000000000ui64;
          m_quad = v10->m_position.m_quad;
          stackInstance.m_stack.m_size = 1;
          tree.m_nodes.m_data = 0i64;
          tree.m_nodes.m_size = 0;
          tree.m_nodes.m_capacityAndFlags = 0x80000000;
          tree.m_numLeaves = 64;
          v44 = (9i64 >> (2 * (unsigned __int8)v9)) & 3;
          v14 = _mm_min_ps(m_quad, m_used->m_vertices[v44]->m_position.m_quad);
          v15 = _mm_max_ps(m_quad, m_used->m_vertices[v44]->m_position.m_quad);
          stackInstance.m_stack.m_data = (unsigned __int64 *)&v43;
          *(__m128 *)&stackInstance.m_stack.m_localMemory = _mm_sub_ps(v14, v12);
          v49 = _mm_add_ps(v15, v12);
          Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = (hkcdDynamicTree::CodecRawUlong *)Value->m_cur;
          v19 = m_cur + 8;
          if ( Value->m_slabSize < 512 || v19 > Value->m_end )
            m_cur = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
          else
            Value->m_cur = v19;
          tree.m_nodes.m_data = m_cur;
          tree.m_firstFree = (unsigned __int64)m_cur;
          tree.m_nodes.m_capacityAndFlags = -2147483584;
          hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector>>(
            m_trianglesTree,
            &tree,
            &stackInstance,
            v17);
          m_size = tree.m_nodes.m_size;
          m_firstFree = (char *)tree.m_firstFree;
          if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
            m_size = 0;
          tree.m_nodes.m_size = m_size;
          v22 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
          v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v24 = (v22 + 15) & 0xFFFFFFF0;
          if ( v22 > v23->m_slabSize || &m_firstFree[v24] != v23->m_cur || v23->m_firstNonLifoEnd == m_firstFree )
            hkLifoAllocator::slowBlockFree(v23, m_firstFree, v24);
          else
            v23->m_cur = m_firstFree;
          tree.m_nodes.m_size = 0;
          if ( tree.m_nodes.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              tree.m_nodes.m_data,
              8 * tree.m_nodes.m_capacityAndFlags);
          v25 = 0;
          if ( (int)v44 > 0 )
          {
            v26 = *(hkgpMeshBase::Edge *)&tree.m_nodes.m_size;
            v27 = 0i64;
            do
            {
              if ( v8 )
                break;
              v28 = *(hkgpMeshBase::Triangle **)&v43[v27];
              if ( v28 == m_used )
              {
                v8 = v55;
              }
              else
              {
                v29 = 0;
                m_vertices = (hkVector4f **)v28->m_vertices;
                while ( 1 )
                {
                  if ( (v28->m_links[v29] & 0xFFFFFFFFFFFFFFFCui64) == 0
                    || (v28->m_links[(18 >> (2 * v29)) & 3] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
                  {
                    v31 = (hkgpMeshBase::Vertex *)*m_vertices;
                    v32 = *m_vertices + 2;
                    p_m_position = &m_used->m_vertices[v41]->m_position;
                    v34 = _mm_sub_ps(v32->m_quad, p_m_position->m_quad);
                    v35 = _mm_mul_ps(v34, v34);
                    if ( (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                               + _mm_shuffle_ps(v35, v35, 170).m128_f32[0]) > v6 )
                    {
                      v36 = &m_used->m_vertices[v44]->m_position;
                      v37 = _mm_sub_ps(v32->m_quad, v36->m_quad);
                      v38 = _mm_mul_ps(v37, v37);
                      if ( (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v38, v38, 170).m128_f32[0]) > v6 )
                      {
                        hkGeometryProcessing::squaredDistanceFromPointToLine(
                          &result,
                          v32,
                          p_m_position,
                          v36,
                          (hkSimdFloat32 *)&tree.m_numLeaves);
                        if ( *(float *)&tree.m_numLeaves > 0.00000011920929
                          && *(float *)&tree.m_numLeaves < (float)(1.0 - 0.00000011920929)
                          && result.m_real.m128_f32[0] <= v6 )
                        {
                          break;
                        }
                      }
                    }
                  }
                  ++v29;
                  ++m_vertices;
                  if ( v29 >= 3 )
                  {
                    v8 = v55;
                    this = v52;
                    goto LABEL_32;
                  }
                }
                v40 = v31;
                this = v52;
                v46 = v26;
                hkgpMesh::splitEdge(v52, (hkgpMeshBase::Edge *)&tree.m_root, &v46, v40, 0);
                hkgpMesh::rebuildTrianglesTree(this, 0.0, 3.186184439476808e-58);
                ++i;
                v8 = 1;
                v55 = 1;
              }
LABEL_32:
              ++v25;
              v27 += 8i64;
            }
            while ( v25 < (int)v44 );
            v9 = v41;
          }
          LODWORD(v44) = 0;
          if ( v44 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v43, 8 * HIDWORD(v44));
          v43 = 0i64;
          HIDWORD(v44) = 0x80000000;
        }
        v41 = ++v9;
      }
      while ( v9 < 3 );
      m_used = m_used->m_next;
    }
    while ( m_used );
  }
  while ( v8 );
  if ( v54 )
  {
    if ( i )
    {
      hkErrStream::hkErrStream((hkErrStream *)&tree.m_root, buf, 512);
      v39 = hkOstream::operator<<((hkOstream *)&tree.m_root, "T-Junctions fixed: ");
      hkOstream::operator<<(v39, i);
      hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2858);
      hkOstream::~hkOstream((hkOstream *)&tree.m_root);
      hkgpMesh::fixBindings(this);
      this->m_hasPerVertexNormals = 0;
    }
  }
}

// File Line: 2866
// RVA: 0xCD21B0
void __fastcall hkgpMesh::fixBindings(hkgpMesh *this)
{
  int v2; // ebx
  hkgpMeshBase::Triangle *m_used; // rdi
  int v4; // r8d
  int j; // ebx
  hkgpMeshBase::Triangle **v6; // rax
  hkgpMeshBase::Triangle *v7; // rcx
  unsigned int v8; // esi
  __int32 m_enum; // edi
  __int64 v10; // r13
  __int64 v11; // r12
  int v12; // r15d
  int v13; // r11d
  __int64 v14; // r9
  char *v15; // r14
  char *v16; // r10
  __int64 v17; // rbx
  __int64 v18; // rdi
  __int64 v19; // rdx
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkOstream *v22; // rax
  int v23; // r8d
  __int64 v24; // rcx
  char *v25; // r9
  signed __int64 v26; // rdx
  __int64 v27; // rax
  char *array; // [rsp+30h] [rbp-C8h] BYREF
  int i; // [rsp+38h] [rbp-C0h]
  int v30; // [rsp+3Ch] [rbp-BCh]
  hkErrStream v31; // [rsp+40h] [rbp-B8h] BYREF
  char buf[520]; // [rsp+60h] [rbp-98h] BYREF
  hkgpMesh *retaddr; // [rsp+2A8h] [rbp+1B0h]
  int v34; // [rsp+2B0h] [rbp+1B8h]
  hkResult result; // [rsp+2B8h] [rbp+1C0h] BYREF
  int v36; // [rsp+2C0h] [rbp+1C8h]

  v2 = 0;
  array = 0i64;
  i = 0;
  v30 = 0x80000000;
  v34 = 0;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, 1024, 16);
  m_used = this->m_triangles.m_used;
  v4 = i;
  if ( m_used )
  {
    do
    {
      for ( j = 0; j < 3; ++j )
      {
        if ( (m_used->m_links[j] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        {
          *(_DWORD *)&v31.m_memSizeAndFlags = j;
          if ( v4 == (v30 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v4 = i;
          }
          v6 = (hkgpMeshBase::Triangle **)&array[16 * v4];
          if ( v6 )
          {
            v7 = *(hkgpMeshBase::Triangle **)&v31.m_memSizeAndFlags;
            *v6 = m_used;
            v6[1] = v7;
            v4 = i;
          }
          i = ++v4;
        }
      }
      m_used = m_used->m_next;
    }
    while ( m_used );
    v2 = 0;
  }
  v8 = v4;
  v36 = v4;
  m_enum = 0;
  result.m_enum = HK_SUCCESS;
  if ( v4 > 0 )
  {
    v10 = 1i64;
    v11 = 0i64;
    v12 = 1;
    do
    {
      v13 = v12;
      v14 = v10;
      if ( v12 < v4 )
      {
        v15 = &array[v11];
        v16 = &array[v11 + 16];
        while ( 1 )
        {
          v17 = *(_QWORD *)v16;
          if ( !*(_QWORD *)v16 )
            break;
          v18 = *((int *)v16 + 2);
          v19 = *((int *)v15 + 2);
          if ( *(_QWORD *)(*(_QWORD *)v15 + 8 * v19 + 16) == *(_QWORD *)(v17
                                                                       + 8 * ((9i64 >> (2 * (unsigned __int8)v18)) & 3)
                                                                       + 16)
            && *(_QWORD *)(*(_QWORD *)v15 + 8 * ((9i64 >> (2 * (unsigned __int8)v19)) & 3) + 16) == *(_QWORD *)(v17 + 8 * v18 + 16) )
          {
            break;
          }
          ++v13;
          ++v14;
          v16 += 16;
          if ( v13 >= v4 )
          {
            m_enum = result.m_enum;
            v2 = v34;
            goto LABEL_21;
          }
        }
        *(_QWORD *)(*(_QWORD *)v15 + 8i64 * *((int *)v15 + 2) + 40) = v17 + *((unsigned int *)v16 + 2);
        if ( *(_QWORD *)v16 )
          *(_QWORD *)(*(_QWORD *)v16 + 8i64 * *((int *)v16 + 2) + 40) = *(_QWORD *)v15 + *((unsigned int *)v15 + 2);
        v4 = i - 1;
        i = v4;
        if ( v4 != v13 )
        {
          v24 = 2i64;
          v25 = &array[16 * v14];
          v26 = &array[16 * v4] - v25;
          do
          {
            v27 = *(_QWORD *)&v25[v26];
            v25 += 8;
            *((_QWORD *)v25 - 1) = v27;
            --v24;
          }
          while ( v24 );
          v4 = i;
        }
        --v12;
        v2 = v34 + 1;
        m_enum = result.m_enum - 1;
        --v10;
        ++v34;
        v11 -= 16i64;
      }
LABEL_21:
      ++m_enum;
      ++v12;
      ++v10;
      v11 += 16i64;
      result.m_enum = m_enum;
    }
    while ( m_enum < v4 );
    v8 = v36;
    this = retaddr;
  }
  if ( v8 )
  {
    hkErrStream::hkErrStream(&v31, buf, 512);
    v20 = hkOstream::operator<<(&v31, "Naked edges found: ");
    v21 = hkOstream::operator<<(v20, v8);
    v22 = hkOstream::operator<<(v21, " fixed:");
    hkOstream::operator<<(v22, 2 * v2);
    hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2892);
    hkOstream::~hkOstream(&v31);
  }
  v23 = v30;
  this->m_hasPerVertexNormals = 0;
  i = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v23);
}

// File Line: 2899
// RVA: 0xCD2550
void __fastcall hkgpMesh::removePartTriangles(hkgpMesh *this, int id)
{
  hkgpMeshBase::Triangle *m_used; // rdx
  hkgpMeshBase::Triangle *m_next; // rbx

  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    do
    {
      m_next = m_used->m_next;
      if ( m_used->m_partId == id )
        hkgpMesh::removeTriangle(this, m_used);
      m_used = m_next;
    }
    while ( m_next );
    this->m_hasPerVertexNormals = 0;
  }
  else
  {
    this->m_hasPerVertexNormals = 0;
  }
}

// File Line: 2911
// RVA: 0xCD25C0
void __fastcall hkgpMesh::removePlaneTriangles(hkgpMesh *this, int id)
{
  hkgpMeshBase::Triangle *m_used; // rdx
  hkgpMeshBase::Triangle *m_next; // rbx

  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    do
    {
      m_next = m_used->m_next;
      if ( m_used->m_planeId == id )
        hkgpMesh::removeTriangle(this, m_used);
      m_used = m_next;
    }
    while ( m_next );
    this->m_hasPerVertexNormals = 0;
  }
  else
  {
    this->m_hasPerVertexNormals = 0;
  }
}

// File Line: 2923
// RVA: 0xCD2630
void __fastcall hkgpMesh::remapPlaneIndex(hkgpMesh *this, int from_id, int to_id)
{
  hkgpMeshBase::Triangle *m_used; // rax
  hkgpMeshBase::Triangle *m_next; // rcx

  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    do
    {
      m_next = m_used->m_next;
      if ( m_used->m_planeId == from_id )
        m_used->m_planeId = to_id;
      m_used = m_next;
    }
    while ( m_next );
  }
}

// File Line: 2934
// RVA: 0xCD2660
void __fastcall hkgpMesh::removePartFromClassification(
        hkgpMesh *this,
        int id,
        hkTransformf *transform,
        hkgpMesh *classifier,
        bool removeInside)
{
  hkgpMeshBase::Triangle *m_used; // rbx
  hkgpMeshBase::Triangle *m_next; // rdi
  hkgpMeshBase::Vertex *v11; // rax
  __m128 *v12; // rcx
  __m128 m_quad; // xmm0
  __m128 *v14; // rax
  __m128 v15; // xmm2
  hkgpMeshBase::Triangle *v16; // rax
  hkVector4f x; // [rsp+20h] [rbp-C8h] BYREF
  hkgpMesh::Location location; // [rsp+30h] [rbp-B8h] BYREF

  m_used = this->m_triangles.m_used;
  if ( m_used )
  {
    do
    {
      m_next = m_used->m_next;
      if ( m_used->m_partId == id )
      {
        v11 = m_used->m_vertices[1];
        v12 = (__m128 *)m_used->m_vertices[0];
        location.m_region.m_type = NONE;
        m_quad = v11->m_position.m_quad;
        v14 = (__m128 *)m_used->m_vertices[2];
        x.m_quad = _mm_add_ps(m_quad, v12[2]);
        v15 = _mm_mul_ps(_mm_add_ps(v14[2], x.m_quad), (__m128)xmmword_141A711C0);
        x.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), transform->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), transform->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), transform->m_rotation.m_col2.m_quad)),
                     transform->m_translation.m_quad);
        if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v16 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
          v16 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        }
        location.m_region.m_feature.m_triangle = v16;
        memset(&location, 0, 48);
        *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e
                                                          + 1);
        location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
        location.m_inside.m_real = g_vectorfConstants[0];
        hkgpMesh::locate(
          classifier,
          (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&x,
          &location,
          (hkBool)1);
        if ( location.m_inside.m_real.m128_f32[0] < 0.0 == removeInside )
          hkgpMesh::removeTriangle(this, m_used);
      }
      m_used = m_next;
    }
    while ( m_next );
    this->m_hasPerVertexNormals = 0;
  }
  else
  {
    this->m_hasPerVertexNormals = 0;
  }
}

// File Line: 2956
// RVA: 0xCD2830
void __fastcall hkgpMesh::flipPartOrientation(hkgpMesh *this, int id)
{
  hkgpMeshBase::Triangle *m_used; // rdi
  int v5; // ebx
  int m_size; // ecx
  hkgpMeshBase::Edge *v7; // rax
  __int64 v8; // rcx
  hkgpMeshBase::Vertex *v9; // rcx
  int v10; // r9d
  __int64 v11; // r10
  hkgpMeshBase::Edge *v12; // rdx
  unsigned __int64 v13; // r8
  int m_capacityAndFlags; // r8d
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> array; // [rsp+20h] [rbp-38h] BYREF
  __int64 v16; // [rsp+38h] [rbp-20h]

  m_used = this->m_triangles.m_used;
  array.m_data = 0i64;
  array.m_size = 0;
  for ( array.m_capacityAndFlags = 0x80000000; m_used; m_used = m_used->m_next )
  {
    if ( m_used->m_partId == id )
    {
      v5 = 0;
      m_used->m_plane.m_quad = _mm_xor_ps(
                                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                 m_used->m_plane.m_quad);
      m_size = array.m_size;
      do
      {
        LODWORD(v16) = v5;
        if ( m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
          m_size = array.m_size;
        }
        v7 = &array.m_data[m_size];
        if ( v7 )
        {
          v8 = v16;
          v7->m_triangle = m_used;
          *(_QWORD *)&v7->m_index = v8;
          m_size = array.m_size;
        }
        ++m_size;
        ++v5;
        array.m_size = m_size;
      }
      while ( v5 < 3 );
      v9 = m_used->m_vertices[0];
      m_used->m_vertices[0] = m_used->m_vertices[1];
      m_used->m_vertices[1] = v9;
    }
  }
  v10 = 0;
  if ( array.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &array.m_data[v11];
      v13 = array.m_data[v11].m_triangle->m_links[array.m_data[v11].m_index];
      if ( (v13 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
        *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (v13 & 3) + 40) = 0i64;
      ++v10;
      v12->m_triangle->m_links[v12->m_index] = 0i64;
      ++v11;
    }
    while ( v10 < array.m_size );
  }
  hkgpMesh::bindEdgeList(this, &array);
  m_capacityAndFlags = array.m_capacityAndFlags;
  this->m_hasPerVertexNormals = 0;
  array.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * m_capacityAndFlags);
}

// File Line: 2981
// RVA: 0xCD2A00
// local variable allocation has failed, the output may be wrong!
void __fastcall hkgpMesh::retriangulateFromPlanes(hkgpMesh *this, __int64 a2, double a3)
{
  __int64 m_size; // rsi
  hkgpMesh *v4; // r13
  int v5; // edx
  __int64 v6; // rbx
  int *v7; // rdi
  int v8; // r8d
  int v9; // eax
  const void **v10; // rcx
  __int64 v11; // rdx
  int v12; // ebx
  int v13; // r9d
  _DWORD *v14; // rdi
  __int64 v15; // rcx
  hkgpMeshBase::Triangle *m_used; // rsi
  __int64 m_planeId; // r14
  int v18; // ebx
  const void **v19; // rdi
  hkgpMeshBase::Triangle **v20; // rcx
  unsigned __int64 v21; // rax
  int v22; // esi
  char *v23; // rax
  hkResultEnum m_enum; // r15d
  const void **v25; // r12
  __int64 v26; // r14
  int v27; // edi
  int v28; // edi
  __int64 v29; // rdx
  hkVector4f *v30; // r8
  __int64 v31; // r15
  int m_margin; // edi
  int v33; // eax
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128i v38; // xmm1
  int v39; // ebx
  int v40; // ecx
  __int64 v41; // rdx
  int v42; // ebx
  __int64 v43; // rsi
  char *v44; // r11
  int v45; // edi
  int v46; // r8d
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128i v51; // xmm1
  int v52; // r10d
  int v53; // r9d
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  __m128i v57; // xmm4
  int v58; // ecx
  int v59; // eax
  hkgpMesh *v60; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_next; // rbx
  int *v62; // rdx
  __int64 v63; // rsi
  __int64 v64; // r15
  __int64 v65; // r13
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *m_free; // rdx
  hkgpMeshBase::Triangle *v68; // rax
  __int64 v69; // rcx
  hkVector4f v70; // xmm0
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v71; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v72; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v73; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v74; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v75; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *i; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v77; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v78; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v79; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v80; // rdx
  int v81; // r8d
  __int64 v82; // rbx
  int *v83; // rdi
  int v84; // r8d
  const void **array; // [rsp+40h] [rbp-A8h] BYREF
  int v86; // [rsp+48h] [rbp-A0h]
  int v87; // [rsp+4Ch] [rbp-9Ch]
  char *v88; // [rsp+50h] [rbp-98h] BYREF
  int v89; // [rsp+58h] [rbp-90h]
  int v90; // [rsp+5Ch] [rbp-8Ch]
  _DWORD *v91; // [rsp+60h] [rbp-88h] BYREF
  __int64 v92; // [rsp+68h] [rbp-80h]
  char *v93; // [rsp+70h] [rbp-78h] BYREF
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> data; // [rsp+78h] [rbp-70h] BYREF
  hkVector4f dmax; // [rsp+98h] [rbp-50h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location location; // [rsp+A8h] [rbp-40h] BYREF
  hkVector4f dmin; // [rsp+C8h] [rbp-20h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> v98; // [rsp+D8h] [rbp-10h] BYREF
  hkgpMesh *v99; // [rsp+E78h] [rbp+D90h]
  hkResult result; // [rsp+E80h] [rbp+D98h] BYREF
  void *retaddr; // [rsp+E88h] [rbp+DA0h]
  hkgpMesh *v102; // [rsp+E90h] [rbp+DA8h] BYREF

  v102 = this;
  m_size = this->m_planes.m_size;
  v4 = this;
  LODWORD(retaddr) = m_size;
  if ( (_DWORD)m_size )
  {
    v87 = 0x80000000;
    v5 = 0;
    array = 0i64;
    v91 = 0i64;
    v92 = 0x8000000000000000ui64;
    v86 = 0;
    if ( (int)m_size > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 16);
      v5 = v86;
    }
    v6 = v5 - (int)m_size - 1;
    if ( v5 - (int)m_size - 1 >= 0 )
    {
      v7 = (int *)&array[2 * m_size + 1] + 4 * v6 + 1;
      do
      {
        v8 = *v7;
        *(v7 - 1) = 0;
        if ( v8 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v7 - 3),
            16 * v8);
        *(_QWORD *)(v7 - 3) = 0i64;
        *v7 = 0x80000000;
        v7 -= 4;
        --v6;
      }
      while ( v6 >= 0 );
      v5 = v86;
    }
    v9 = m_size - v5;
    v10 = &array[2 * v5];
    v11 = (int)m_size - v5;
    if ( v9 > 0 )
    {
      do
      {
        if ( v10 )
        {
          *v10 = 0i64;
          *((_DWORD *)v10 + 2) = 0;
          *((_DWORD *)v10 + 3) = 0x80000000;
        }
        v10 += 2;
        --v11;
      }
      while ( v11 );
    }
    v12 = v4->m_planes.m_size;
    v86 = m_size;
    if ( (HIDWORD(v92) & 0x3FFFFFFF) < v12 )
    {
      v13 = v12;
      if ( v12 < 2 * (HIDWORD(v92) & 0x3FFFFFFF) )
        v13 = 2 * (HIDWORD(v92) & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v91, v13, 4);
    }
    v14 = &v91[(int)v92];
    v15 = v12 - (int)v92;
    if ( v12 - (int)v92 > 0 )
    {
      while ( v15 )
      {
        *v14++ = -1;
        --v15;
      }
    }
    m_used = v4->m_triangles.m_used;
    for ( LODWORD(v92) = v12; m_used; m_used = m_used->m_next )
    {
      m_planeId = m_used->m_planeId;
      if ( (int)m_planeId >= 0 )
      {
        v18 = 0;
        v91[m_planeId] = m_used->m_material;
        do
        {
          LODWORD(data.m_tags.m_storage[0]) = v18;
          if ( (m_used->m_links[v18] & 0xFFFFFFFFFFFFFFFCui64) == 0
            || *(_DWORD *)((m_used->m_links[v18] & 0xFFFFFFFFFFFFFFFCui64) + 84) != (_DWORD)m_planeId )
          {
            v19 = &array[2 * m_planeId];
            if ( *((_DWORD *)v19 + 2) == (*((_DWORD *)v19 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array[2 * m_planeId], 16);
            v20 = (hkgpMeshBase::Triangle **)((char *)*v19 + 16 * *((int *)v19 + 2));
            if ( v20 )
            {
              v21 = data.m_tags.m_storage[0];
              *v20 = m_used;
              v20[1] = (hkgpMeshBase::Triangle *)v21;
            }
            ++*((_DWORD *)v19 + 2);
          }
          ++v18;
        }
        while ( v18 < 3 );
      }
    }
    v22 = 0;
    v23 = 0i64;
    m_enum = HK_SUCCESS;
    result.m_enum = HK_SUCCESS;
    v93 = 0i64;
    if ( v86 > 0 )
    {
      HIDWORD(data.m_tags.m_storage[0]) = 16;
      dmin.m_quad = (__m128)_xmm;
      dmax.m_quad = _xmm;
      do
      {
        v25 = array;
        v88 = 0i64;
        v26 = 2i64 * (_QWORD)v23;
        v89 = 0;
        v90 = 0x80000000;
        v27 = (int)array[2 * (_QWORD)v23 + 1];
        if ( v27 <= 0 )
          LODWORD(v102) = 0;
        else
          hkArrayUtil::_reserve(
            (hkResult *)&v102,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v88,
            (int)array[2 * (_QWORD)v23 + 1],
            16);
        v89 = v27;
        v28 = 0;
        if ( SLODWORD(v25[v26 + 1]) > 0 )
        {
          v29 = 0i64;
          do
          {
            ++v28;
            v29 += 16i64;
            *(_OWORD *)&v88[v29 - 16] = *(_OWORD *)(*(_QWORD *)(*(_QWORD *)((char *)v25[v26] + v29 - 16)
                                                              + 8i64 * *(int *)((char *)v25[v26] + v29 - 8)
                                                              + 16)
                                                  + 32i64);
          }
          while ( v28 < SLODWORD(v25[v26 + 1]) );
        }
        memset(&v98.m_mesh.m_vertices, 0, 20);
        v98.m_edgeDataPolicy = 0i64;
        v98.m_stack.m_data = v98.m_stack.m_storage;
        *(_DWORD *)&v98.m_memSizeAndFlags = 0x1FFFF;
        v98.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable;
        *(_DWORD *)&v98.m_mesh.m_memSizeAndFlags = 0x1FFFF;
        v98.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable;
        memset(&v98.m_mesh.m_triangles, 0, 20);
        v98.m_stack.m_size = 0;
        v98.m_stack.m_capacityAndFlags = -2147483584;
        v98.m_status.m_storage = 0;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomain(
          &v98,
          &dmin,
          &dmax,
          0.0,
          1);
        *(_QWORD *)&data.m_tags.m_size = v88;
        v30 = &v4->m_planes.m_data[m_enum];
        LODWORD(data.m_tags.m_storage[0]) = v89;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomainFromPlanarPoints(
          &v98,
          (hkStridedVertices *)&data.m_tags.m_size,
          v30,
          1,
          1,
          0);
        if ( v89 > 0 )
        {
          v31 = 0i64;
          do
          {
            m_margin = v98.m_margin;
            v33 = 0x7FFF - v98.m_margin;
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(*(__m128 *)&v88[v31], *(__m128 *)&v88[v31], 0),
                          v98.m_worldToLocal.m_col0.m_quad),
                        v98.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(*(__m128 *)&v88[v31], *(__m128 *)&v88[v31], 85),
                        v98.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*(__m128 *)&v88[v31], *(__m128 *)&v88[v31], 170),
                      v98.m_worldToLocal.m_col2.m_quad));
            v35 = _mm_sub_ps(v34, (__m128)xmmword_141A711B0);
            v36 = _mm_add_ps(v34, (__m128)xmmword_141A711B0);
            *(__m128 *)&a3 = _mm_cmplt_ps(v34, (__m128)0i64);
            v37 = _mm_or_ps(_mm_andnot_ps(*(__m128 *)&a3, v36), _mm_and_ps(v35, *(__m128 *)&a3));
            v38 = _mm_xor_si128(
                    (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v37),
                    _mm_cvttps_epi32(v37));
            v39 = _mm_cvtsi128_si32(v38);
            if ( v39 >= v98.m_margin )
            {
              if ( v39 > v33 )
                v39 = 0x7FFF - v98.m_margin;
            }
            else
            {
              v39 = v98.m_margin;
            }
            v40 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v38, 85));
            if ( v40 >= v98.m_margin )
            {
              m_margin = v40;
              if ( v40 > v33 )
                m_margin = 0x7FFF - v98.m_margin;
            }
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
              &v98,
              &location,
              v39,
              m_margin);
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(
              &v98,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&data,
              v39,
              m_margin,
              1,
              &location,
              0);
            if ( !LODWORD(data.m_tags.m_data) )
            {
              v41 = *(_QWORD *)(v92 + 8i64 * (int)v93 + 16);
              *(_QWORD *)(v41 + 24) = *(_DWORD *)(v41 + 24) & 3 | (unsigned __int64)(4i64 * v22);
            }
            ++v22;
            v31 += 16i64;
          }
          while ( v22 < v89 );
          m_enum = result.m_enum;
        }
        v42 = 0;
        if ( SLODWORD(v25[v26 + 1]) > 0 )
        {
          v43 = 0i64;
          do
          {
            v44 = (char *)v25[v26];
            v45 = v98.m_margin;
            v46 = 0x7FFF - v98.m_margin;
            v47 = *(__m128 *)(*(_QWORD *)(*(_QWORD *)&v44[v43] + 8i64 * *(int *)&v44[v43 + 8] + 16) + 32i64);
            v48 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v98.m_worldToLocal.m_col0.m_quad),
                        v98.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v98.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v98.m_worldToLocal.m_col2.m_quad));
            v49 = _mm_cmplt_ps(v48, (__m128)0i64);
            v50 = _mm_or_ps(
                    _mm_andnot_ps(v49, _mm_add_ps(v48, (__m128)xmmword_141A711B0)),
                    _mm_and_ps(_mm_sub_ps(v48, (__m128)xmmword_141A711B0), v49));
            v51 = _mm_xor_si128(
                    (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v50),
                    _mm_cvttps_epi32(v50));
            v52 = _mm_cvtsi128_si32(v51);
            if ( v52 >= v98.m_margin )
            {
              if ( v52 > v46 )
                v52 = 0x7FFF - v98.m_margin;
            }
            else
            {
              v52 = v98.m_margin;
            }
            v53 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v51, 85));
            if ( v53 >= v98.m_margin )
            {
              if ( v53 > v46 )
                v53 = 0x7FFF - v98.m_margin;
            }
            else
            {
              v53 = v98.m_margin;
            }
            v54 = *(__m128 *)(*(_QWORD *)(*(_QWORD *)&v44[v43]
                                        + 8 * ((9i64 >> (2 * (unsigned __int8)*(_DWORD *)&v44[v43 + 8])) & 3)
                                        + 16)
                            + 32i64);
            v55 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v98.m_worldToLocal.m_col0.m_quad),
                        v98.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), v98.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), v98.m_worldToLocal.m_col2.m_quad));
            v56 = _mm_cmplt_ps(v55, (__m128)0i64);
            *(__m128 *)&a3 = _mm_or_ps(
                               _mm_andnot_ps(v56, _mm_add_ps(v55, (__m128)xmmword_141A711B0)),
                               _mm_and_ps(_mm_sub_ps(v55, (__m128)xmmword_141A711B0), v56));
            v57 = _mm_xor_si128(
                    (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, *(__m128 *)&a3),
                    _mm_cvttps_epi32(*(__m128 *)&a3));
            v58 = _mm_cvtsi128_si32(v57);
            if ( v58 >= v98.m_margin )
            {
              if ( v58 > v46 )
                v58 = 0x7FFF - v98.m_margin;
            }
            else
            {
              v58 = v98.m_margin;
            }
            v59 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v57, 85));
            if ( v59 >= v98.m_margin )
            {
              v45 = v59;
              if ( v59 > v46 )
                v45 = 0x7FFF - v98.m_margin;
            }
            data.m_tags.m_data = (unsigned __int64 *)&v93;
            v92 = 0x8000000200000001ui64;
            v93 = &v44[16 * v42];
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertEdge(
              &v98,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&location,
              v52,
              v53,
              v58,
              v45,
              1,
              &data);
            LODWORD(v92) = 0;
            if ( v92 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                data.m_tags.m_data,
                8 * HIDWORD(v92));
            ++v42;
            v43 += 16i64;
          }
          while ( v42 < SLODWORD(v25[v26 + 1]) );
        }
        if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(&v98) > 1 )
        {
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(&v98);
          v60 = v99;
          hkgpMesh::remapPlaneIndex(v99, m_enum, (int)retaddr);
          m_next = v98.m_mesh.m_triangles.m_used;
          if ( v98.m_mesh.m_triangles.m_used )
          {
            do
            {
              if ( (*((_BYTE *)m_next + 66) & 0x20) != 0 )
              {
                v62 = (int *)v25[v26];
                v63 = *(_QWORD *)(*(_QWORD *)&v62[4 * (int)(*((_QWORD *)m_next->m_vertices[0] + 3) >> 2)]
                                + 8i64 * v62[4 * (int)(*((_QWORD *)m_next->m_vertices[0] + 3) >> 2) + 2]
                                + 16);
                v64 = *(_QWORD *)(*(_QWORD *)&v62[4 * (int)(*((_QWORD *)m_next->m_vertices[1] + 3) >> 2)]
                                + 8i64 * v62[4 * (int)(*((_QWORD *)m_next->m_vertices[1] + 3) >> 2) + 2]
                                + 16);
                v65 = *(_QWORD *)(*(_QWORD *)&v62[4 * (int)(*((_QWORD *)m_next->m_vertices[2] + 3) >> 2)]
                                + 8i64 * v62[4 * (int)(*((_QWORD *)m_next->m_vertices[2] + 3) >> 2) + 2]
                                + 16);
                m_firstPool = v60->m_triangles.m_allocator.m_firstPool;
                if ( !m_firstPool || !m_firstPool->m_free )
                  m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v60->m_triangles.m_allocator);
                if ( m_firstPool )
                {
                  m_free = m_firstPool->m_free;
                  m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
                  m_free->m_pool = m_firstPool;
                  ++m_firstPool->m_used;
                  *(_QWORD *)&m_free->m_data[8] = 0i64;
                  *(_QWORD *)m_free->m_data = v60->m_triangles.m_used;
                  v68 = v60->m_triangles.m_used;
                  if ( v68 )
                    v68->m_prev = (hkgpMeshBase::Triangle *)m_free;
                  ++v60->m_triangles.m_numUsed;
                  v60->m_triangles.m_used = (hkgpMeshBase::Triangle *)m_free;
                }
                else
                {
                  m_free = 0i64;
                }
                v60 = v99;
                v69 = (__int64)v93;
                *(_DWORD *)&m_free->m_data[80] = -1;
                *(_QWORD *)&m_free->m_data[40] = 0i64;
                *(_QWORD *)&m_free->m_data[48] = 0i64;
                *(_QWORD *)&m_free->m_data[56] = 0i64;
                v70.m_quad = (__m128)v60->m_planes.m_data[(unsigned __int64)v26 / 2];
                *(hkResult *)&m_free->m_data[84] = result;
                *(hkVector4f *)&m_free->m_data[64] = (hkVector4f)v70.m_quad;
                *(_DWORD *)&m_free->m_data[88] = v91[v69];
                *(_QWORD *)&m_free->m_data[16] = v63;
                *(_QWORD *)&m_free->m_data[24] = v64;
                *(_QWORD *)&m_free->m_data[32] = v65;
              }
              m_next = m_next->m_next;
            }
            while ( m_next );
            m_enum = result.m_enum;
          }
          v4 = v99;
        }
        v98.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(
          &v98,
          1);
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(&v98.m_edgeDataPolicy);
        v22 = 0;
        v98.m_stack.m_size = 0;
        if ( v98.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v98.m_stack.m_data,
            16 * v98.m_stack.m_capacityAndFlags);
        v71 = v98.m_mesh.m_triangles.m_allocator.m_firstPool;
        v98.m_stack.m_data = 0i64;
        v98.m_stack.m_capacityAndFlags = 0x80000000;
        for ( v98.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable;
              v98.m_mesh.m_triangles.m_allocator.m_firstPool;
              v71 = v98.m_mesh.m_triangles.m_allocator.m_firstPool )
        {
          v72 = v71->m_links[0];
          if ( v72 )
            v72->m_links[1] = v71->m_links[1];
          else
            v98.m_mesh.m_triangles.m_allocator.m_firstPool = v71->m_links[1];
          v73 = v71->m_links[1];
          if ( v73 )
            v73->m_links[0] = v71->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v71, 3104);
        }
        v98.m_mesh.m_triangles.m_used = 0i64;
        v98.m_mesh.m_triangles.m_numUsed = 0;
        if ( v71 )
        {
          do
          {
            v74 = v71->m_links[0];
            if ( v74 )
              v74->m_links[1] = v71->m_links[1];
            else
              v98.m_mesh.m_triangles.m_allocator.m_firstPool = v71->m_links[1];
            v75 = v71->m_links[1];
            if ( v75 )
              v75->m_links[0] = v71->m_links[0];
            hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v71, 3104);
            v71 = v98.m_mesh.m_triangles.m_allocator.m_firstPool;
          }
          while ( v98.m_mesh.m_triangles.m_allocator.m_firstPool );
        }
        for ( i = v98.m_mesh.m_vertices.m_allocator.m_firstPool;
              v98.m_mesh.m_vertices.m_allocator.m_firstPool;
              i = v98.m_mesh.m_vertices.m_allocator.m_firstPool )
        {
          v77 = i->m_links[0];
          if ( v77 )
            v77->m_links[1] = i->m_links[1];
          else
            v98.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
          v78 = i->m_links[1];
          if ( v78 )
            v78->m_links[0] = i->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
        }
        v98.m_mesh.m_vertices.m_used = 0i64;
        v98.m_mesh.m_vertices.m_numUsed = 0;
        if ( i )
        {
          do
          {
            v79 = i->m_links[0];
            if ( v79 )
              v79->m_links[1] = i->m_links[1];
            else
              v98.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
            v80 = i->m_links[1];
            if ( v80 )
              v80->m_links[0] = i->m_links[0];
            hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
            i = v98.m_mesh.m_vertices.m_allocator.m_firstPool;
          }
          while ( v98.m_mesh.m_vertices.m_allocator.m_firstPool );
        }
        v89 = 0;
        v98.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
        v98.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
        if ( v90 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v88, 16 * v90);
        ++m_enum;
        v88 = 0i64;
        v23 = v93 + 1;
        v90 = 0x80000000;
        result.m_enum = m_enum;
        ++v93;
      }
      while ( m_enum < v86 );
    }
    hkgpMesh::removePlaneTriangles(v4, (int)retaddr);
    hkgpMesh::removeOrphanVertices(v4);
    hkgpMesh::rebuildTrianglesTree(v4, 0.0, a3);
    v81 = HIDWORD(v92);
    v4->m_hasPerVertexNormals = 0;
    LODWORD(v92) = 0;
    if ( v81 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v91, 4 * v81);
    v91 = 0i64;
    HIDWORD(v92) = 0x80000000;
    v82 = v86 - 1;
    if ( v86 - 1 >= 0 )
    {
      v83 = (int *)&array[2 * v86 - 1] + 1;
      do
      {
        v84 = *v83;
        *(v83 - 1) = 0;
        if ( v84 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v83 - 3),
            16 * v84);
        *(_QWORD *)(v83 - 3) = 0i64;
        *v83 = 0x80000000;
        v83 -= 4;
        --v82;
      }
      while ( v82 >= 0 );
    }
    v86 = 0;
    if ( v87 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v87);
  }
}

// File Line: 3075
// RVA: 0xCD36C0
void __fastcall hkgpMesh::enumerateTriangleOverlaps(
        hkgpMesh *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles)
{
  __m128 m_quad; // xmm1
  __m128 v6; // xmm0
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_trianglesTree; // rbx
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector> *v10; // r9
  __int64 m_cur; // rcx
  void *v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  int v18; // esi
  __int64 v19; // rdi
  char *v20; // r14
  char *v21; // [rsp+18h] [rbp-71h] BYREF
  int v22; // [rsp+20h] [rbp-69h]
  int v23; // [rsp+24h] [rbp-65h]
  char *tree; // [rsp+28h] [rbp-61h] BYREF
  int tree_8; // [rsp+30h] [rbp-59h]
  int tree_12; // [rsp+34h] [rbp-55h]
  char *tree_16; // [rsp+38h] [rbp-51h]
  int tree_24; // [rsp+40h] [rbp-49h]
  hkVector4f tree_32[3]; // [rsp+48h] [rbp-41h] BYREF
  hkVector4f vertexArray[3]; // [rsp+78h] [rbp-11h] BYREF
  hkAabb aabbOut; // [rsp+A8h] [rbp+1Fh] BYREF
  const void **array; // [rsp+108h] [rbp+7Fh]

  m_quad = b->m_quad;
  vertexArray[0] = (hkVector4f)a->m_quad;
  v6 = c->m_quad;
  vertexArray[1] = (hkVector4f)m_quad;
  v23 = 0x80000000;
  vertexArray[2] = (hkVector4f)v6;
  v22 = 0;
  hkAabbUtil::calcAabb(vertexArray, 3, &aabbOut);
  m_trianglesTree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_trianglesTree;
  tree_32[1] = aabbOut.m_min;
  tree_32[2] = aabbOut.m_max;
  tree_32[0].m_quad.m128_u64[0] = (unsigned __int64)&v21;
  tree_32[0].m_quad.m128_i32[2] = 1;
  tree = 0i64;
  tree_8 = 0;
  tree_12 = 0x80000000;
  tree_24 = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (void *)(m_cur + 512);
  if ( Value->m_slabSize < 512 || v12 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v12;
  tree = (char *)m_cur;
  tree_16 = (char *)m_cur;
  tree_12 = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector>>(
    m_trianglesTree,
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)tree_32,
    v10);
  v13 = tree_8;
  v14 = tree_16;
  if ( tree_16 == tree )
    v13 = 0;
  tree_8 = v13;
  v15 = (8 * tree_24 + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  tree_8 = 0;
  if ( tree_12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, tree, 8 * tree_12);
  v18 = 0;
  if ( v22 > 0 )
  {
    v19 = 0i64;
    do
    {
      tree_32[0] = *(hkVector4f *)(*(_QWORD *)(*(_QWORD *)&v21[v19] + 16i64) + 32i64);
      tree_32[1] = *(hkVector4f *)(*(_QWORD *)(*(_QWORD *)&v21[v19] + 24i64) + 32i64);
      tree_32[2] = *(hkVector4f *)(*(_QWORD *)(*(_QWORD *)&v21[v19] + 32i64) + 32i64);
      if ( hkcdIntersectTriangleTriangle((hkVector4f (*)[3])vertexArray, (hkVector4f (*)[3])tree_32) )
      {
        v20 = v21;
        if ( *((_DWORD *)array + 2) == (*((_DWORD *)array + 3) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, array, 8);
        *((_QWORD *)*array + (int)(*((_DWORD *)array + 2))++) = *(_QWORD *)&v20[v19];
      }
      ++v18;
      v19 += 8i64;
    }
    while ( v18 < v22 );
  }
  v22 = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v21, 8 * v23);
}

// File Line: 3092
// RVA: 0xCD3960
__int64 __fastcall hkgpMesh::checkTriangleOverlap(hkgpMesh *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  __m128 m_quad; // xmm0
  __m128 v5; // xmm1
  __m128 v7; // xmm0
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *m_trianglesTree; // rbx
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::TriangleOverlap> *v10; // r9
  hkcdDynamicTree::CodecRawUlong *m_cur; // rcx
  hkcdDynamicTree::CodecRawUlong *v12; // rdx
  int m_size; // eax
  char *m_firstFree; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+20h] [rbp-59h] BYREF
  hkVector4f vertexArray; // [rsp+50h] [rbp-29h] BYREF
  __m128 v21; // [rsp+60h] [rbp-19h]
  __m128 v22; // [rsp+70h] [rbp-9h]
  unsigned __int64 *stackInstance; // [rsp+80h] [rbp+7h] BYREF
  int stackInstance_8; // [rsp+88h] [rbp+Fh]
  hkAabb stackInstance_16; // [rsp+90h] [rbp+17h]
  hkAabb aabbOut; // [rsp+B0h] [rbp+37h] BYREF

  m_quad = a->m_quad;
  v5 = b->m_quad;
  LODWORD(tree.m_root) = 0;
  vertexArray.m_quad = m_quad;
  v7 = c->m_quad;
  v21 = v5;
  v22 = v7;
  hkAabbUtil::calcAabb(&vertexArray, 3, &aabbOut);
  m_trianglesTree = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_trianglesTree;
  stackInstance_16 = aabbOut;
  stackInstance = &tree.m_root;
  stackInstance_8 = 1;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 0x80000000;
  tree.m_numLeaves = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::CodecRawUlong *)Value->m_cur;
  v12 = m_cur + 8;
  if ( Value->m_slabSize < 512 || v12 > Value->m_end )
    m_cur = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v12;
  tree.m_nodes.m_data = m_cur;
  tree.m_firstFree = (unsigned __int64)m_cur;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::TriangleOverlap>>(
    m_trianglesTree,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)&stackInstance,
    v10);
  m_size = tree.m_nodes.m_size;
  m_firstFree = (char *)tree.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
    m_size = 0;
  tree.m_nodes.m_size = m_size;
  v15 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &m_firstFree[v17] != v16->m_cur || v16->m_firstNonLifoEnd == m_firstFree )
    hkLifoAllocator::slowBlockFree(v16, m_firstFree, v17);
  else
    v16->m_cur = m_firstFree;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      8 * tree.m_nodes.m_capacityAndFlags);
  return LODWORD(tree.m_root);
}

// File Line: 3104
// RVA: 0xCD59C0
hkVector4f *__fastcall getLoopSurfaceArea(
        hkVector4f *result,
        hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *loop)
{
  int m_size; // r9d
  int v5; // r9d
  int v6; // edx
  int v7; // r14d
  __int64 v8; // rbx
  hkgpMeshBase::Vertex *v9; // rsi
  hkgpMeshBase::Edge *m_data; // r8
  int v11; // r9d
  hkgpMeshBase::Vertex *v12; // rsi
  int v13; // r8d
  __m128 v14; // xmm2
  hkVector4f *array; // [rsp+30h] [rbp-40h] BYREF
  int v17; // [rsp+38h] [rbp-38h]
  int v18; // [rsp+3Ch] [rbp-34h]
  hkAabb aabbOut; // [rsp+40h] [rbp-30h] BYREF
  hkResult resulta; // [rsp+98h] [rbp+28h] BYREF

  m_size = loop->m_size;
  if ( m_size )
  {
    v5 = 2 * m_size;
    v6 = 0;
    v18 = 0x80000000;
    array = 0i64;
    v17 = 0;
    if ( v5 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v5, 16);
      v6 = v17;
    }
    v7 = 0;
    if ( loop->m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = loop->m_data[v8].m_triangle->m_vertices[loop->m_data[v8].m_index];
        if ( v6 == (v18 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v6 = v17;
        }
        array[v6] = v9->m_position;
        m_data = loop->m_data;
        v11 = v17 + 1;
        v17 = v11;
        v12 = m_data[v8].m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(m_data[v8].m_index))) & 3];
        if ( v11 == (v18 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v11 = v17;
        }
        ++v7;
        ++v8;
        array[v11] = v12->m_position;
        v6 = ++v17;
      }
      while ( v7 < loop->m_size );
    }
    hkAabbUtil::calcAabb(array, v6, &aabbOut);
    v13 = v18;
    v14 = _mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
    v17 = 0;
    result->m_quad = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                       _mm_shuffle_ps(v14, v14, 170));
    if ( v13 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v13);
      return result;
    }
  }
  else
  {
    *result = (hkVector4f)::aabbOut.m_quad;
  }
  return result;
}

// File Line: 3127
// RVA: 0xCD3AF0
__int64 __fastcall hkgpMesh::extractAllLoops(hkgpMesh *this, hkArrayBase<char *> *loops, int partId)
{
  hkgpMeshBase::Triangle *m_used; // rsi
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **v5; // r11
  int v6; // r9d
  int i; // edi
  _QWORD **Value; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  hkgpMeshBase::Triangle **v11; // rcx
  unsigned __int64 v12; // rax
  int v13; // ecx
  int v14; // r15d
  int v15; // edi
  __int64 v16; // r10
  int v17; // eax
  int v18; // edi
  __int64 v19; // rbx
  hkArrayBase<hkgpMeshBase::Edge> *v20; // rsi
  hkgpMeshBase::Vertex *v21; // r13
  __int64 v22; // r8
  hkgpMeshBase::Vertex *v23; // r12
  hkArrayBase<hkgpMeshBase::Edge> *v24; // r14
  hkgpMeshBase::Edge *m_data; // r8
  int v26; // eax
  hkgpMeshBase::Vertex *v27; // rcx
  __int64 v28; // rsi
  int v29; // r8d
  _QWORD **v30; // rax
  int v32; // ebx
  int v33; // r9d
  float v34; // xmm6_4
  __int64 v35; // rsi
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *v36; // rcx
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **v37; // r8
  unsigned int v38; // ebx
  __int64 v39; // rdx
  _QWORD *v40; // r8
  __int64 v41; // rsi
  int v42; // r8d
  _QWORD **v43; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-58h] BYREF
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **array; // [rsp+30h] [rbp-48h] BYREF
  int numtoinsert; // [rsp+38h] [rbp-40h]
  int v48; // [rsp+3Ch] [rbp-3Ch]
  int v49; // [rsp+90h] [rbp+18h]
  __int64 v51; // [rsp+A8h] [rbp+30h]

  m_used = this->m_triangles.m_used;
  v48 = 0x80000000;
  v5 = 0i64;
  array = 0i64;
  v6 = 0;
  numtoinsert = 0;
  if ( !m_used )
    goto LABEL_56;
  do
  {
    if ( partId == -1 || m_used->m_partId == partId )
    {
      for ( i = 0; i < 3; ++i )
      {
        result.m_real.m128_i32[2] = i;
        if ( (m_used->m_links[i] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
          v10 = v9;
          if ( v9 )
          {
            *(_QWORD *)v9 = 0i64;
            *(_DWORD *)(v9 + 8) = 0;
            *(_DWORD *)(v9 + 12) = 0x80000000;
          }
          else
          {
            v10 = 0i64;
          }
          if ( *(_DWORD *)(v10 + 8) == (*(_DWORD *)(v10 + 12) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v10, 16);
          v11 = (hkgpMeshBase::Triangle **)(*(_QWORD *)v10 + 16i64 * *(int *)(v10 + 8));
          if ( v11 )
          {
            v12 = result.m_real.m128_u64[1];
            *v11 = m_used;
            v11[1] = (hkgpMeshBase::Triangle *)v12;
          }
          ++*(_DWORD *)(v10 + 8);
          v13 = numtoinsert;
          if ( numtoinsert == (v48 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
            v13 = numtoinsert;
          }
          array[v13] = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *)v10;
          v5 = array;
          v6 = ++numtoinsert;
        }
      }
    }
    m_used = m_used->m_next;
  }
  while ( m_used );
  if ( !v6 )
  {
LABEL_56:
    v38 = 0;
    goto LABEL_57;
  }
  v14 = 0;
  v15 = 1;
  do
  {
    if ( v6 <= 0 )
      goto LABEL_39;
    v16 = 0i64;
    v17 = 1;
    v51 = 0i64;
    v49 = 1;
    do
    {
      v18 = v17;
      if ( v17 >= v6 )
        goto LABEL_37;
      v19 = v16 + 8;
      do
      {
        v20 = *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v16);
        v21 = v20->m_data->m_triangle->m_vertices[v20->m_data->m_index];
        v22 = (__int64)&v20->m_data[v20->m_size - 1];
        v23 = *(hkgpMeshBase::Vertex **)(*(_QWORD *)v22 + 8 * ((9i64 >> (2 * *(_BYTE *)(v22 + 8))) & 3) + 16);
        if ( v21 == v23 )
          goto LABEL_35;
        v24 = *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v19);
        m_data = v24->m_data;
        v26 = v24->m_size - 1;
        result.m_real.m128_u64[0] = (unsigned __int64)v24->m_data->m_triangle->m_vertices[v24->m_data->m_index];
        v27 = m_data[v26].m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_data[v26].m_index)) & 3];
        if ( (hkgpMeshBase::Vertex *)result.m_real.m128_u64[0] == v27 )
          goto LABEL_34;
        if ( (hkgpMeshBase::Vertex *)result.m_real.m128_u64[0] == v23 )
        {
          hkArrayBase<hkgpMeshBase::Edge>::_append(v20, &hkContainerHeapAllocator::s_alloc, m_data, v24->m_size);
          v5 = array;
          v28 = *(__int64 *)((char *)array + v19);
          if ( v28 )
          {
            v29 = *(_DWORD *)(v28 + 12);
            *(_DWORD *)(v28 + 8) = 0;
            if ( v29 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)v28,
                16 * v29);
            *(_QWORD *)v28 = 0i64;
            *(_DWORD *)(v28 + 12) = 0x80000000;
            v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v30[11] + 16i64))(v30[11], v28, 16i64);
            v5 = array;
          }
          v6 = numtoinsert - 1;
          numtoinsert = v6;
          if ( v6 != v18 )
          {
            *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v19) = v5[v6];
            v6 = numtoinsert;
            v5 = array;
          }
          --v18;
          v19 -= 8i64;
          v14 = -1;
LABEL_34:
          v16 = v51;
          goto LABEL_35;
        }
        if ( v21 != v27 )
          goto LABEL_34;
        hkArrayBase<hkgpMeshBase::Edge>::_append(v24, &hkContainerHeapAllocator::s_alloc, v20->m_data, v20->m_size);
        v16 = v51;
        v39 = *(__int64 *)((char *)array + v51);
        v40 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)array + v19);
        *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)array + v51) = *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)array + v19);
        *v40 = v39;
        v5 = array;
        v41 = *(__int64 *)((char *)array + v19);
        if ( v41 )
        {
          v42 = *(_DWORD *)(v41 + 12);
          *(_DWORD *)(v41 + 8) = 0;
          if ( v42 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)v41,
              16 * v42);
          *(_QWORD *)v41 = 0i64;
          *(_DWORD *)(v41 + 12) = 0x80000000;
          v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v43[11] + 16i64))(v43[11], v41, 16i64);
          v5 = array;
          v16 = v51;
        }
        v6 = numtoinsert - 1;
        numtoinsert = v6;
        if ( v6 != v18 )
        {
          *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v19) = v5[v6];
          v6 = numtoinsert;
          v5 = array;
        }
        --v18;
        v19 -= 8i64;
        v14 = -1;
LABEL_35:
        ++v18;
        v19 += 8i64;
      }
      while ( v18 < v6 );
      v17 = v49;
LABEL_37:
      v16 += 8i64;
      v49 = v17 + 1;
      v51 = v16;
    }
    while ( v17++ < v6 );
    v15 = 1;
LABEL_39:
    ++v14;
  }
  while ( v14 < 1 );
  v32 = 0;
  getLoopSurfaceArea(&result, *v5);
  v33 = numtoinsert;
  if ( numtoinsert > 1 )
  {
    v34 = result.m_real.m128_f32[0];
    v35 = 1i64;
    do
    {
      getLoopSurfaceArea(&result, array[v35]);
      if ( result.m_real.m128_f32[0] > v34 )
      {
        v32 = v15;
        v34 = result.m_real.m128_f32[0];
      }
      v33 = numtoinsert;
      ++v15;
      ++v35;
    }
    while ( v15 < numtoinsert );
    if ( v32 )
    {
      v36 = *array;
      v37 = &array[v32];
      *array = *v37;
      *v37 = v36;
      v33 = numtoinsert;
    }
  }
  hkArrayBase<unsigned __int64>::_append(loops, &hkContainerHeapAllocator::s_alloc, (char *const *)array, v33);
  v38 = numtoinsert;
  v5 = array;
LABEL_57:
  numtoinsert = 0;
  if ( v48 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v5, 8 * v48);
  return v38;
}

// File Line: 3204
// RVA: 0xCD4640
void __fastcall hkgpMesh::simplifyPlanes(hkgpMesh *this, bool report)
{
  hkgpMesh *v2; // rsi
  int v3; // edi
  hkgpMeshBase::Triangle *m_used; // r9
  hkgpMeshBase::Vertex *v5; // rax
  int v6; // edx
  float *m128_f32; // rcx
  float v8; // xmm0_4
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v9; // r13
  hkgpMeshBase::Triangle *m_triangle; // rbx
  signed int m_index; // r14d
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v12; // xmm7
  __int64 v13; // rdi
  __int128 v14; // xmm6
  int v15; // r9d
  __int128 *v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rax
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rdx
  __int128 v21; // xmm6
  __int128 *v22; // rax
  __int64 v23; // rdx
  unsigned __int64 v24; // rax
  bool v25; // r15
  int j; // esi
  unsigned int v27; // edi
  bool v28; // zf
  char *v29; // r15
  __int64 v30; // r8
  char *v31; // rdx
  __int64 v32; // rcx
  unsigned __int64 v33; // rdi
  hkgpMeshBase::Triangle *v34; // rsi
  int v35; // r10d
  __m128 m_quad; // xmm4
  char *v37; // r8
  __int64 v38; // r9
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v45; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v46; // r13
  int v47; // edi
  unsigned int m_numUsed; // ebx
  hkOstream *v49; // rax
  hkOstream *v50; // rax
  hkOstream *v51; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v52; // [rsp+20h] [rbp-A0h] BYREF
  AMD_HD3D v53; // [rsp+30h] [rbp-90h] BYREF
  __m256 v54; // [rsp+50h] [rbp-70h] BYREF
  __int128 v55; // [rsp+70h] [rbp-50h]
  char *array; // [rsp+80h] [rbp-40h] BYREF
  int v57; // [rsp+88h] [rbp-38h]
  int v58; // [rsp+8Ch] [rbp-34h]
  char v59; // [rsp+90h] [rbp-30h] BYREF
  hkgpMesh *v60; // [rsp+2F0h] [rbp+230h]
  char v61; // [rsp+2F8h] [rbp+238h]
  int v62; // [rsp+300h] [rbp+240h]
  int i; // [rsp+308h] [rbp+248h]

  v2 = this;
  v3 = 0;
  i = this->m_triangles.m_numUsed;
  v62 = 0;
  do
  {
    m_used = v2->m_triangles.m_used;
    v54.m256_f32[6] = 0.0;
    *(_QWORD *)&v54.m256_f32[4] = m_used;
    v52 = *(hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&v54.m256_f32[4];
    if ( m_used )
    {
      v5 = m_used->m_vertices[1];
      v6 = 0;
      m128_f32 = v5->m_position.m_quad.m128_f32;
      do
      {
        v8 = *(float *)((char *)m128_f32 + (char *)m_used->m_vertices[0] - (char *)v5);
        if ( v8 < *m128_f32 )
          break;
        if ( v8 > *m128_f32 )
        {
          if ( (m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v52);
          break;
        }
        ++v6;
        ++m128_f32;
      }
      while ( v6 < 3 );
    }
    v9 = &v52;
    m_triangle = (hkgpMeshBase::Triangle *)_mm_load_si128((const __m128i *)&v52).m128i_u64[0];
    if ( !m_triangle )
      v9 = 0i64;
    if ( v9 )
    {
      m_index = v52.m_edge.m_index;
      while ( 1 )
      {
        v12 = v52;
        if ( (m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          break;
LABEL_59:
        if ( m_triangle )
        {
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v52);
          m_index = v52.m_edge.m_index;
          m_triangle = v52.m_edge.m_triangle;
        }
        v46 = &v52;
        if ( !m_triangle )
          v46 = 0i64;
        if ( !v46 )
          goto LABEL_64;
      }
      v13 = 0i64;
      *(_QWORD *)&v55 = m_triangle;
      DWORD2(v55) = m_index;
      v14 = v55;
      v58 = -2147483632;
      *(_OWORD *)&v53.mStereo = v55;
      v15 = 0;
      v57 = 0;
      array = &v59;
      while ( 1 )
      {
        if ( v15 == (v58 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v15 = v57;
        }
        v16 = (__int128 *)&array[16 * v15];
        if ( v16 )
        {
          *v16 = v14;
          v15 = v57;
        }
        v57 = ++v15;
        v17 = (18 >> (2 * LOBYTE(v53.mExtension))) & 3;
        v18 = (__int64)v53.mStereo[v17 + 5].vfptr & 3;
        v19 = (unsigned __int64)v53.mStereo[v17 + 5].vfptr & 0xFFFFFFFFFFFFFFFCui64;
        *(_QWORD *)v54.m256_f32 = v19;
        LODWORD(v54.m256_f32[2]) = v18;
        v14 = *(_OWORD *)v54.m256_f32;
        *(_OWORD *)&v53.mStereo = *(_OWORD *)v54.m256_f32;
        if ( !v19 )
          break;
        if ( (hkgpMeshBase::Triangle *)(v19 + (unsigned int)v18) == (hkgpMeshBase::Triangle *)((char *)m_triangle
                                                                                             + (unsigned int)m_index) )
          goto LABEL_29;
      }
      v20 = m_triangle->m_links[m_index];
      *(_QWORD *)&v55 = v20 & 0xFFFFFFFFFFFFFFFCui64;
      DWORD2(v55) = (9 >> (2 * (v20 & 3))) & 3;
      v21 = v55;
      *(_OWORD *)&v53.mStereo = v55;
      if ( (v20 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        do
        {
          if ( v15 == (v58 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v15 = v57;
          }
          v22 = (__int128 *)&array[16 * v15];
          if ( v22 )
          {
            *v22 = v21;
            v15 = v57;
          }
          v57 = ++v15;
          v23 = (__int64)v53.mStereo[SLODWORD(v53.mExtension) + 5].vfptr & 3;
          v53.mStereo = (IAmdDxExtQuadBufferStereo *)((unsigned __int64)v53.mStereo[SLODWORD(v53.mExtension) + 5].vfptr & 0xFFFFFFFFFFFFFFFCui64);
          LODWORD(v53.mExtension) = (9 >> (2 * v23)) & 3;
          v21 = *(_OWORD *)&v53.mStereo;
        }
        while ( v53.mStereo );
      }
LABEL_29:
      v24 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
      *(_QWORD *)&v53.mEnableStereo = 0i64;
      LODWORD(v24) = *(_DWORD *)(v24 + 84);
      v53.mWidth = 0;
      v53.mHeight = -1;
      v25 = m_triangle->m_planeId != (_DWORD)v24;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v53,
        &hkContainerHeapAllocator::s_alloc,
        16);
      for ( j = 0; j < v57; v13 += 16i64 )
      {
        if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v53,
                              *(int *)(*(_QWORD *)&array[v13] + 84i64),
                              0i64) )
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v53,
            &hkContainerHeapAllocator::s_alloc,
            *(int *)(*(_QWORD *)&array[v13] + 84i64),
            1ui64);
        ++j;
      }
      v27 = v53.mWidth & 0x7FFFFFFF;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v53,
        &hkContainerHeapAllocator::s_alloc);
      _(&v53);
      if ( v25 )
        v28 = v27 == 2;
      else
        v28 = v27 == 1;
      v29 = array;
      v30 = 0i64;
      if ( v57 <= 0 )
      {
LABEL_41:
        if ( v28 )
        {
          v33 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
          v34 = m_triangle;
          v35 = 0;
          m_quad = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3]->m_position.m_quad;
          if ( v57 <= 0 )
          {
            do
            {
LABEL_48:
              if ( m_triangle != v34 && m_triangle != (hkgpMeshBase::Triangle *)v33 )
                break;
              if ( m_triangle )
              {
                hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v52);
                m_triangle = v52.m_edge.m_triangle;
              }
              v45 = &v52;
              if ( !m_triangle )
                v45 = 0i64;
            }
            while ( v45 );
            m_index = v52.m_edge.m_index;
            v2 = v60;
            *(hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *)v54.m256_f32 = v12;
            hkgpMesh::collapseEdge(v60, (hkgpMeshBase::Edge *)&v54, 0);
            v29 = array;
            v3 = -1;
            v62 = -1;
            goto LABEL_57;
          }
          v37 = array;
          while ( 1 )
          {
            v38 = *(_QWORD *)v37;
            if ( *(hkgpMeshBase::Triangle **)v37 != m_triangle && v38 != v33 )
            {
              v39 = _mm_sub_ps(
                      *(__m128 *)(*(_QWORD *)(v38 + 8i64 * ((9 >> (2 * *((_DWORD *)v37 + 2))) & 3) + 16) + 32i64),
                      m_quad);
              v40 = _mm_sub_ps(
                      *(__m128 *)(*(_QWORD *)(v38
                                            + 8 * ((9i64 >> (2 * ((9 >> (2 * *((_DWORD *)v37 + 2))) & 3u))) & 3)
                                            + 16)
                                + 32i64),
                      m_quad);
              v41 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39),
                      _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
              v42 = _mm_shuffle_ps(v41, v41, 201);
              v43 = _mm_mul_ps(v42, m_quad);
              v44 = _mm_mul_ps(
                      _mm_shuffle_ps(
                        v42,
                        _mm_unpackhi_ps(
                          v42,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                              _mm_shuffle_ps(v43, v43, 170)))),
                        196),
                      v60->m_planes.m_data[*(int *)(v38 + 84)].m_quad);
              if ( (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0] + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
                         + _mm_shuffle_ps(v44, v44, 170).m128_f32[0]) <= 0.00000011920929 )
                break;
            }
            ++v35;
            v37 += 16;
            if ( v35 >= v57 )
              goto LABEL_48;
          }
        }
      }
      else
      {
        v31 = array;
        while ( 1 )
        {
          v32 = *((int *)v31 + 2);
          if ( (*(_QWORD *)(*(_QWORD *)v31 + 8 * v32 + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0
            || (*(_QWORD *)(*(_QWORD *)v31 + 8i64 * ((9 >> (2 * v32)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          {
            break;
          }
          ++v30;
          v31 += 16;
          if ( v30 >= v57 )
            goto LABEL_41;
        }
      }
      v2 = v60;
      v3 = v62;
LABEL_57:
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v29, 16 * v58);
      goto LABEL_59;
    }
LABEL_64:
    v62 = ++v3;
  }
  while ( v3 < 1 );
  if ( v61 )
  {
    v47 = i;
    if ( i != v2->m_triangles.m_numUsed )
    {
      hkErrStream::hkErrStream((hkErrStream *)&v54, (char *)&array, 512);
      m_numUsed = v2->m_triangles.m_numUsed;
      v49 = hkOstream::operator<<((hkOstream *)&v54, "Planes simplify: ");
      v50 = hkOstream::operator<<(v49, v47);
      v51 = hkOstream::operator<<(v50, " => ");
      hkOstream::operator<<(v51, m_numUsed);
      hkError::messageReport(0xFFFFFFFF, (const char *)&array, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 3249);
      hkOstream::~hkOstream((hkOstream *)&v54);
    }
  }
}

// File Line: 3255
// RVA: 0xCD3FF0
__int64 __fastcall hkgpMesh::countFanPlanes(hkgpMesh *this, hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *m_triangle; // rbx
  __int64 m_index; // rdi
  __int128 v4; // xmm6
  int v5; // r8d
  char *v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rax
  IAmdDxExtQuadBufferStereo *v9; // rdx
  char v10; // cl
  __int128 v11; // xmm6
  char *v12; // rax
  char v13; // cl
  int v14; // edi
  __int64 v15; // rbx
  unsigned int v16; // ebx
  AMD_HD3D v18; // [rsp+20h] [rbp-D8h] BYREF
  char *array; // [rsp+40h] [rbp-B8h] BYREF
  int v20; // [rsp+48h] [rbp-B0h]
  int v21; // [rsp+4Ch] [rbp-ACh]
  char v22; // [rsp+50h] [rbp-A8h] BYREF

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  *(_QWORD *)&v18.mEnableStereo = edge->m_triangle;
  v18.mWidth = m_index;
  v4 = *(_OWORD *)&v18.mEnableStereo;
  v5 = 0;
  v21 = -2147483632;
  array = &v22;
  v20 = 0;
  while ( 1 )
  {
    if ( v5 == (v21 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
      v5 = v20;
    }
    v6 = &array[16 * v5];
    if ( v6 )
    {
      *(_OWORD *)v6 = v4;
      v5 = v20;
    }
    v20 = ++v5;
    v7 = (18 >> (2 * LOBYTE(v18.mWidth))) & 3;
    v8 = *(_QWORD *)(*(_QWORD *)&v18.mEnableStereo + 8 * v7 + 40) & 3i64;
    v9 = (IAmdDxExtQuadBufferStereo *)(*(_QWORD *)(*(_QWORD *)&v18.mEnableStereo + 8 * v7 + 40) & 0xFFFFFFFFFFFFFFFCui64);
    v18.mStereo = v9;
    LODWORD(v18.mExtension) = v8;
    v4 = *(_OWORD *)&v18.mStereo;
    *(_OWORD *)&v18.mEnableStereo = *(_OWORD *)&v18.mStereo;
    if ( !v9 )
      break;
    if ( (char *)v9 + (unsigned int)v8 == (char *)m_triangle + (unsigned int)m_index )
      goto LABEL_15;
  }
  v10 = m_triangle->m_links[m_index] & 3;
  v18.mStereo = (IAmdDxExtQuadBufferStereo *)(m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64);
  LODWORD(v18.mExtension) = (9 >> (2 * v10)) & 3;
  v11 = *(_OWORD *)&v18.mStereo;
  for ( *(_OWORD *)&v18.mEnableStereo = *(_OWORD *)&v18.mStereo;
        v18.mStereo;
        *(_OWORD *)&v18.mEnableStereo = *(_OWORD *)&v18.mStereo )
  {
    if ( v5 == (v21 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
      v5 = v20;
    }
    v12 = &array[16 * v5];
    if ( v12 )
    {
      *(_OWORD *)v12 = v11;
      v5 = v20;
    }
    v20 = ++v5;
    v13 = *(_QWORD *)(*(_QWORD *)&v18.mEnableStereo + 8i64 * (int)v18.mWidth + 40) & 3;
    v18.mStereo = (IAmdDxExtQuadBufferStereo *)(*(_QWORD *)(*(_QWORD *)&v18.mEnableStereo + 8i64 * (int)v18.mWidth + 40) & 0xFFFFFFFFFFFFFFFCui64);
    LODWORD(v18.mExtension) = (9 >> (2 * v13)) & 3;
    v11 = *(_OWORD *)&v18.mStereo;
  }
LABEL_15:
  *(_QWORD *)&v18.mEnableStereo = 0i64;
  v18.mWidth = 0;
  v18.mHeight = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v18,
    &hkContainerHeapAllocator::s_alloc,
    16);
  v14 = 0;
  if ( v20 > 0 )
  {
    v15 = 0i64;
    do
    {
      if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v18,
                            *(int *)(*(_QWORD *)&array[v15] + 84i64),
                            0i64) )
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v18,
          &hkContainerHeapAllocator::s_alloc,
          *(int *)(*(_QWORD *)&array[v15] + 84i64),
          1ui64);
      ++v14;
      v15 += 16i64;
    }
    while ( v14 < v20 );
  }
  v16 = v18.mWidth & 0x7FFFFFFF;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v18,
    &hkContainerHeapAllocator::s_alloc);
  _(&v18);
  v20 = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v21);
  return v16;
}

// File Line: 3263
// RVA: 0xCD42B0
hkBool *__fastcall hkgpMesh::checkEdgeCollapseConvex(
        hkgpMesh *this,
        hkBool *result,
        hkgpMesh::FanEdgeCollector *fan,
        hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *m_triangle; // rdi
  __int64 m_index; // rcx
  __int64 m_size; // rsi
  __int64 v7; // r10
  unsigned __int64 v8; // rbx
  hkgpMeshBase::Vertex *v10; // rbp
  hkgpMeshBase::Edge *m_data; // rax
  hkgpMeshBase::Triangle *v12; // r11
  __int64 v13; // rdx
  __m128 *v14; // r9
  __m128 m_quad; // xmm2
  __m128 v16; // xmm5
  __m128 *v17; // rcx
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm2

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  m_size = fan->m_edges.m_size;
  v7 = 0i64;
  v8 = edge->m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  v10 = edge->m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
  if ( m_size <= 0 )
  {
LABEL_7:
    result->m_bool = 1;
  }
  else
  {
    m_data = fan->m_edges.m_data;
    while ( 1 )
    {
      v12 = m_data->m_triangle;
      v13 = *(_QWORD *)&m_data->m_index;
      if ( m_data->m_triangle != m_triangle && v12 != (hkgpMeshBase::Triangle *)v8 )
      {
        v14 = (__m128 *)v12->m_vertices[(int)v13];
        m_quad = v12->m_vertices[(9i64 >> (2 * (unsigned __int8)v13)) & 3]->m_position.m_quad;
        v16 = _mm_sub_ps(m_quad, v10->m_position.m_quad);
        v17 = (__m128 *)v12->m_vertices[(18i64 >> (2 * (unsigned __int8)v13)) & 3];
        v18 = _mm_sub_ps(m_quad, v14[2]);
        v19 = _mm_sub_ps(v17[2], v14[2]);
        v20 = _mm_sub_ps(v17[2], v10->m_position.m_quad);
        v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19));
        v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v20));
        v23 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), _mm_shuffle_ps(v21, v21, 201));
        if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                   + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) < 0.0 )
          break;
      }
      ++v7;
      ++m_data;
      if ( v7 >= m_size )
        goto LABEL_7;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 3285
// RVA: 0xCD4400
hkBool *__fastcall hkgpMesh::checkEdgeCollapseConvex(hkgpMesh *this, hkBool *result, hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *m_triangle; // rbx
  __int64 m_index; // rdi
  __int128 v5; // xmm6
  int m_size; // r9d
  hkgpMeshBase::Edge *v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rax
  hkgpMeshBase::Triangle *v13; // rdx
  char v14; // cl
  __int128 v15; // xmm6
  hkgpMeshBase::Edge *v16; // rax
  char v17; // cl
  __int128 v19; // [rsp+20h] [rbp-C8h] BYREF
  __int128 i; // [rsp+30h] [rbp-B8h]
  hkgpMesh::FanEdgeCollector array; // [rsp+40h] [rbp-A8h] BYREF

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  *(_QWORD *)&i = edge->m_triangle;
  DWORD2(i) = m_index;
  v5 = i;
  m_size = 0;
  array.m_edges.m_data = array.m_edges.m_storage;
  array.m_edges.m_capacityAndFlags = -2147483632;
  array.m_edges.m_size = 0;
  while ( 1 )
  {
    if ( m_size == (array.m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_edges.m_data, 16);
      m_size = array.m_edges.m_size;
    }
    v10 = &array.m_edges.m_data[m_size];
    if ( v10 )
    {
      *v10 = (hkgpMeshBase::Edge)v5;
      m_size = array.m_edges.m_size;
    }
    array.m_edges.m_size = ++m_size;
    v11 = (18 >> (2 * BYTE8(i))) & 3;
    v12 = *(_QWORD *)(i + 8 * v11 + 40) & 3i64;
    v13 = (hkgpMeshBase::Triangle *)(*(_QWORD *)(i + 8 * v11 + 40) & 0xFFFFFFFFFFFFFFFCui64);
    *(_QWORD *)&v19 = v13;
    DWORD2(v19) = v12;
    v5 = v19;
    i = v19;
    if ( !v13 )
      break;
    if ( (char *)v13 + (unsigned int)v12 == (char *)m_triangle + (unsigned int)m_index )
      goto LABEL_15;
  }
  v14 = m_triangle->m_links[m_index] & 3;
  *(_QWORD *)&v19 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  DWORD2(v19) = (9 >> (2 * v14)) & 3;
  v15 = v19;
  for ( i = v19; (_QWORD)v19; i = v19 )
  {
    if ( m_size == (array.m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_edges.m_data, 16);
      m_size = array.m_edges.m_size;
    }
    v16 = &array.m_edges.m_data[m_size];
    if ( v16 )
    {
      *v16 = (hkgpMeshBase::Edge)v15;
      m_size = array.m_edges.m_size;
    }
    array.m_edges.m_size = ++m_size;
    v17 = *(_QWORD *)(i + 8i64 * SDWORD2(i) + 40) & 3;
    *(_QWORD *)&v19 = *(_QWORD *)(i + 8i64 * SDWORD2(i) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    DWORD2(v19) = (9 >> (2 * v17)) & 3;
    v15 = v19;
  }
LABEL_15:
  v19 = (__int128)*edge;
  hkgpMesh::checkEdgeCollapseConvex(this, result, &array, (hkgpMeshBase::Edge *)&v19);
  array.m_edges.m_size = 0;
  if ( array.m_edges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_edges.m_data,
      16 * array.m_edges.m_capacityAndFlags);
  return result;
}

// File Line: 3292
// RVA: 0xCD4C90
void __fastcall hkgpMesh::initializeQEM(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *m_used; // r8
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v3; // xmm6
  hkgpMeshBase::Vertex *v4; // rax
  int v5; // edx
  float *m128_f32; // rcx
  float v7; // xmm0_4
  hkgpMeshBase::Triangle *m_triangle; // rbx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v9; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v10; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v11; // [rsp+20h] [rbp-38h] BYREF
  hkgpMeshBase::Edge m_edge; // [rsp+30h] [rbp-28h] BYREF

  m_used = this->m_triangles.m_used;
  v11.m_edge.m_triangle = m_used;
  v11.m_edge.m_index = 0;
  v3 = v11;
  if ( m_used )
  {
    v4 = m_used->m_vertices[1];
    v5 = 0;
    m128_f32 = v4->m_position.m_quad.m128_f32;
    do
    {
      v7 = *(float *)((char *)m128_f32 + (char *)m_used->m_vertices[0] - (char *)v4);
      if ( v7 < *m128_f32 )
        break;
      if ( v7 > *m128_f32 )
      {
        if ( (m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
        {
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v11);
          v3 = v11;
        }
        break;
      }
      ++v5;
      ++m128_f32;
    }
    while ( v5 < 3 );
  }
  m_triangle = v3.m_edge.m_triangle;
  v9 = &v11;
  if ( !v3.m_edge.m_triangle )
    v9 = 0i64;
  if ( v9 )
  {
    do
    {
      m_edge = v3.m_edge;
      hkgpMesh::computeQEM(this, &m_edge);
      if ( m_triangle )
      {
        hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v11);
        m_triangle = v11.m_edge.m_triangle;
        v3 = v11;
      }
      v10 = &v11;
      if ( !m_triangle )
        v10 = 0i64;
    }
    while ( v10 );
  }
}

// File Line: 3301
// RVA: 0xCD4D90
void __fastcall hkgpMesh::computeQEM(hkgpMesh *this, hkgpMeshBase::Edge *e)
{
  hkgpMeshBase::Triangle *m_triangle; // rbx
  __int64 m_index; // rdi
  int v4; // r8d
  __m128 m_real; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  __m128 *v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rax
  unsigned __int64 v12; // rdx
  char v13; // cl
  __m128 v14; // xmm6
  __m128 *v15; // rax
  char v16; // cl
  int v17; // ebx
  __int64 v18; // rdi
  _QWORD *v19; // r9
  __int64 v20; // rcx
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __int64 v23; // rax
  __m128 v24; // xmm1
  __int64 v25; // rdx
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  char v31; // cl
  __m128 v32; // xmm3
  __m128 *v33; // rax
  hkgpMeshBase::Vertex *v34; // rdx
  float v35; // xmm1_4
  hkVector4f v36; // xmm0
  hkSimdFloat32 result; // [rsp+20h] [rbp-D8h] BYREF
  __m128 i; // [rsp+30h] [rbp-C8h]
  hkMatrix3f v39; // [rsp+40h] [rbp-B8h] BYREF
  int *array; // [rsp+70h] [rbp-88h] BYREF
  int v41; // [rsp+78h] [rbp-80h] BYREF
  int v42; // [rsp+7Ch] [rbp-7Ch]

  m_triangle = e->m_triangle;
  m_index = (int)e->m_index;
  i.m128_u64[0] = (unsigned __int64)e->m_triangle;
  i.m128_i32[2] = m_index;
  v4 = 0;
  m_real = i;
  v41 = 0;
  v42 = -2147483632;
  array = &v41;
  v7 = 0i64;
  v8 = 0i64;
  while ( 1 )
  {
    if ( v4 == (v42 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
      v4 = v41;
    }
    v9 = (__m128 *)&array[4 * v4];
    if ( v9 )
    {
      *v9 = m_real;
      v4 = v41;
    }
    v41 = ++v4;
    v10 = (18 >> (2 * i.m128_i8[8])) & 3;
    v11 = *(_QWORD *)(i.m128_u64[0] + 8 * v10 + 40) & 3i64;
    v12 = *(_QWORD *)(i.m128_u64[0] + 8 * v10 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    result.m_real.m128_u64[0] = v12;
    result.m_real.m128_i32[2] = v11;
    m_real = result.m_real;
    i = result.m_real;
    if ( !v12 )
      break;
    if ( (hkgpMeshBase::Triangle *)(v12 + (unsigned int)v11) == (hkgpMeshBase::Triangle *)((char *)m_triangle
                                                                                         + (unsigned int)m_index) )
      goto LABEL_15;
  }
  v13 = m_triangle->m_links[m_index] & 3;
  result.m_real.m128_u64[0] = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  result.m_real.m128_i32[2] = (9 >> (2 * v13)) & 3;
  v14 = result.m_real;
  for ( i = result.m_real; result.m_real.m128_u64[0]; i = result.m_real )
  {
    if ( v4 == (v42 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
      v4 = v41;
    }
    v15 = (__m128 *)&array[4 * v4];
    if ( v15 )
    {
      *v15 = v14;
      v4 = v41;
    }
    v41 = ++v4;
    v16 = *(_QWORD *)(i.m128_u64[0] + 8i64 * i.m128_i32[2] + 40) & 3;
    result.m_real.m128_u64[0] = *(_QWORD *)(i.m128_u64[0] + 8i64 * i.m128_i32[2] + 40) & 0xFFFFFFFFFFFFFFFCui64;
    result.m_real.m128_i32[2] = (9 >> (2 * v16)) & 3;
    v14 = result.m_real;
  }
LABEL_15:
  v17 = 0;
  if ( v4 > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = *(_QWORD **)&array[v18];
      v20 = *(_QWORD *)&array[v18 + 2];
      v21 = *(__m128 *)(v19[2] + 32i64);
      v22 = _mm_sub_ps(*(__m128 *)(v19[3] + 32i64), v21);
      v23 = (int)v20;
      v24 = _mm_sub_ps(*(__m128 *)(v19[4] + 32i64), v21);
      v25 = v19[(int)v20 + 5];
      v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v24));
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_mul_ps(v27, v27);
      v29 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170));
      v30 = _mm_rsqrt_ps(v29);
      v8 = _mm_add_ps(
             v8,
             _mm_andnot_ps(
               _mm_cmple_ps(v29, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                   _mm_mul_ps(v30, *(__m128 *)_xmm)),
                 v29)));
      if ( (v25 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v31 = 2 * v20;
        v32 = *(__m128 *)(v19[v23 + 2] + 32i64);
        v33 = (__m128 *)v19[((18i64 >> v31) & 3) + 2];
        v39.m_col0.m_quad = _mm_sub_ps(*(__m128 *)(v19[((9i64 >> v31) & 3) + 2] + 32i64), v32);
        v39.m_col1.m_quad = _mm_sub_ps(v33[2], v32);
        v39.m_col2.m_quad = _mm_sub_ps(
                              *(__m128 *)(*(_QWORD *)((v25 & 0xFFFFFFFFFFFFFFFCui64)
                                                    + 8 * ((18i64 >> (2 * ((unsigned __int8)v25 & 3u))) & 3)
                                                    + 16)
                                        + 32i64),
                              v32);
        hkMatrix3f::getDeterminant(&v39, &result);
        v4 = v41;
        v7 = _mm_add_ps(v7, _mm_mul_ps(result.m_real, result.m_real));
      }
      ++v17;
      v18 += 4i64;
    }
    while ( v17 < v4 );
  }
  v34 = e->m_triangle->m_vertices[e->m_index];
  v35 = _mm_rcp_ps(v8).m128_f32[0];
  v36.m_quad = (__m128)v34->m_data;
  v36.m_quad.m128_f32[0] = (float)((float)(2.0 - (float)(v35 * v8.m128_f32[0])) * v35) * v7.m128_f32[0];
  v34->m_data = (hkVector4f)v36.m_quad;
  v41 = 0;
  if ( v42 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v42);
}

// File Line: 3321
// RVA: 0xCD5180
void __fastcall hkgpMesh::simplifyQEM(hkgpMesh *this, int numTriangleToRemove, float maxCost)
{
  __m128 v3; // xmm0
  int v4; // edi
  int v7; // r12d
  float v8; // xmm8_4
  int v9; // r14d
  float v10; // xmm6_4
  __m128i v11; // xmm7
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkgpMeshBase::Triangle *m_used; // r9
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v15; // xmm2
  hkgpMeshBase::Vertex *v16; // rax
  int v17; // edx
  float *m128_f32; // rcx
  hkgpMeshBase::Triangle *m_triangle; // rdx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v20; // rax
  signed int m_index; // r8d
  __m128 *v22; // rcx
  __m128 *v23; // rax
  float v24; // xmm1_4
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v25; // rax
  int v26; // edx
  __int64 v27; // r8
  __int64 v28; // rax
  __int128 v29; // xmm0
  __m128 *v30; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v31; // [rsp+20h] [rbp-B8h] BYREF
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v32; // [rsp+30h] [rbp-A8h]
  __m128i v33; // [rsp+40h] [rbp-98h] BYREF
  hkErrStream v34; // [rsp+50h] [rbp-88h] BYREF
  char buf[512]; // [rsp+70h] [rbp-68h] BYREF
  float v36; // [rsp+2B8h] [rbp+1E0h]

  if ( numTriangleToRemove > 0 )
  {
    v4 = -1;
    v7 = 0;
    v8 = v36;
    v9 = 0;
    do
    {
      v10 = 3.40282e38;
      if ( (`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard & 1) == 0 )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::`local static guard |= 1u;
      }
      v11 = (__m128i)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null::`2::e;
      if ( v9 / numTriangleToRemove != v4 )
      {
        v4 = v9 / numTriangleToRemove;
        hkErrStream::hkErrStream(&v34, buf, 512);
        v12 = hkOstream::operator<<(&v34, "Progress: ");
        v13 = hkOstream::operator<<(v12, v9 / numTriangleToRemove);
        hkOstream::operator<<(v13, " %");
        hkError::messageReport(0xFFFFFFFF, buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 3332);
        hkOstream::~hkOstream(&v34);
      }
      m_used = this->m_triangles.m_used;
      v32.m_edge.m_index = 0;
      v32.m_edge.m_triangle = m_used;
      v15 = v32;
      v31 = v32;
      if ( m_used )
      {
        v16 = m_used->m_vertices[1];
        v17 = 0;
        m128_f32 = v16->m_position.m_quad.m128_f32;
        do
        {
          v3 = (__m128)*(unsigned int *)((char *)m128_f32 + (char *)m_used->m_vertices[0] - (char *)v16);
          if ( v3.m128_f32[0] < *m128_f32 )
            break;
          if ( v3.m128_f32[0] > *m128_f32 )
          {
            if ( (m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
            {
              hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v31);
              v15 = v31;
            }
            break;
          }
          ++v17;
          ++m128_f32;
        }
        while ( v17 < 3 );
      }
      m_triangle = v15.m_edge.m_triangle;
      v20 = &v31;
      if ( !v15.m_edge.m_triangle )
        v20 = 0i64;
      if ( v20 )
      {
        m_index = v31.m_edge.m_index;
        do
        {
          if ( (m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            v22 = (__m128 *)m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
            v23 = (__m128 *)m_triangle->m_vertices[m_index];
            v3 = _mm_shuffle_ps(v23[4], v23[4], 0);
            v24 = _mm_shuffle_ps(v22[4], v22[4], 0).m128_f32[0] + v3.m128_f32[0];
            if ( v24 < v10 )
            {
              v10 = v24;
              v11 = (__m128i)v15;
            }
          }
          if ( m_triangle )
          {
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v31);
            m_index = v31.m_edge.m_index;
            m_triangle = v31.m_edge.m_triangle;
            v15 = v31;
          }
          v25 = &v31;
          if ( !m_triangle )
            v25 = 0i64;
        }
        while ( v25 );
      }
      if ( !v11.m128i_i64[0] )
        break;
      v3.m128_f32[0] = v8;
      if ( v10 >= _mm_shuffle_ps(v3, v3, 0).m128_f32[0] )
        break;
      v33 = v11;
      v26 = _mm_cvtsi128_si32(_mm_srli_si128(v11, 8));
      v27 = (9i64 >> (2 * (unsigned __int8)v26)) & 3;
      v28 = *(_QWORD *)(v11.m128i_i64[0] + 8 * v27 + 16);
      v29 = *(_OWORD *)(v28 + 64);
      *(float *)&v29 = v10;
      *(_OWORD *)(v28 + 64) = v29;
      v30 = *(__m128 **)(v11.m128i_i64[0] + 8i64 * v26 + 16);
      v3 = v30[4];
      v3.m128_f32[0] = v10;
      v30[4] = v3;
      *(__m128 *)(*(_QWORD *)(v11.m128i_i64[0] + 8 * v27 + 16) + 32i64) = _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_sub_ps(
                                                                                *(__m128 *)(*(_QWORD *)(v11.m128i_i64[0] + 8i64 * v26 + 16)
                                                                                          + 32i64),
                                                                                *(__m128 *)(*(_QWORD *)(v11.m128i_i64[0] + 8 * v27 + 16)
                                                                                          + 32i64)),
                                                                              (__m128)xmmword_141A711B0),
                                                                            *(__m128 *)(*(_QWORD *)(v11.m128i_i64[0]
                                                                                                  + 8 * v27
                                                                                                  + 16)
                                                                                      + 32i64));
      hkgpMesh::collapseEdge(this, (hkgpMeshBase::Edge *)&v33, 0);
      ++v7;
      v9 += 100;
    }
    while ( v7 < numTriangleToRemove );
  }
}

// File Line: 3366
// RVA: 0xCD5470
void __fastcall hkgpMesh::applyLaplacianSmoothing(hkgpMesh *this, float iterations)
{
  __m128 v3; // xmm11
  __m128 m_quad; // xmm6
  hkgpMeshBase::Triangle *m_used; // r9
  __m128 v6; // xmm12
  hkgpMeshBase::Vertex *v7; // rax
  int v8; // edx
  float *m128_f32; // rcx
  float v10; // xmm0_4
  hkgpMeshBase::Triangle *m_triangle; // rbx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v12; // rax
  signed int m_index; // edi
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v14; // xmm6
  int v15; // r9d
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rax
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rdx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v21; // xmm6
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v22; // rax
  __int64 v23; // rdx
  __int64 v24; // r8
  char *v25; // rdx
  __int64 v26; // rcx
  __m128 v27; // xmm7
  __m128 v28; // xmm6
  int v29; // r14d
  __int64 v30; // rsi
  _QWORD *v31; // rcx
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm0
  __m128 *v42; // rcx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v43; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v44; // [rsp+20h] [rbp-D0h] BYREF
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v45; // [rsp+30h] [rbp-C0h]
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v46; // [rsp+40h] [rbp-B0h]
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v47; // [rsp+50h] [rbp-A0h]
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v48; // [rsp+60h] [rbp-90h]
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v49; // [rsp+70h] [rbp-80h]
  hkVector4f result; // [rsp+80h] [rbp-70h] BYREF
  char *array; // [rsp+90h] [rbp-60h] BYREF
  int v52; // [rsp+98h] [rbp-58h]
  int v53; // [rsp+9Ch] [rbp-54h]
  char v54; // [rsp+A0h] [rbp-50h] BYREF
  void *retaddr; // [rsp+248h] [rbp+158h]

  v3 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  if ( v3.m128_f32[0] > 0.0 )
  {
    m_quad = query.m_quad;
    do
    {
      m_used = this->m_triangles.m_used;
      v49.m_edge.m_index = 0;
      v49.m_edge.m_triangle = m_used;
      v6 = _mm_min_ps(v3, m_quad);
      v44 = v49;
      if ( m_used )
      {
        v7 = m_used->m_vertices[1];
        v8 = 0;
        m128_f32 = v7->m_position.m_quad.m128_f32;
        do
        {
          v10 = *(float *)((char *)m128_f32 + (char *)m_used->m_vertices[0] - (char *)v7);
          if ( v10 < *m128_f32 )
            break;
          if ( v10 > *m128_f32 )
          {
            if ( (m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
              hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v44);
            break;
          }
          ++v8;
          ++m128_f32;
        }
        while ( v8 < 3 );
      }
      m_triangle = v44.m_edge.m_triangle;
      v12 = &v44;
      if ( !v44.m_edge.m_triangle )
        v12 = 0i64;
      if ( v12 )
      {
        m_index = v44.m_edge.m_index;
        do
        {
          v49.m_edge.m_triangle = m_triangle;
          v49.m_edge.m_index = m_index;
          v14 = v49;
          v15 = 0;
          v52 = 0;
          v45 = v49;
          array = &v54;
          v53 = -2147483632;
          while ( 1 )
          {
            if ( v15 == (v53 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
              v15 = v52;
            }
            v16 = (hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array[16 * v15];
            if ( v16 )
            {
              *v16 = v14;
              v15 = v52;
            }
            v52 = ++v15;
            v17 = (18 >> (2 * LOBYTE(v45.m_edge.m_index))) & 3;
            v18 = v45.m_edge.m_triangle->m_links[v17] & 3;
            v19 = v45.m_edge.m_triangle->m_links[v17] & 0xFFFFFFFFFFFFFFFCui64;
            v46.m_edge.m_triangle = (hkgpMeshBase::Triangle *)v19;
            v46.m_edge.m_index = v18;
            v14 = v46;
            v45 = v46;
            if ( !v19 )
              break;
            if ( (hkgpMeshBase::Triangle *)(v19 + (unsigned int)v18) == (hkgpMeshBase::Triangle *)((char *)m_triangle
                                                                                                 + (unsigned int)m_index) )
              goto LABEL_29;
          }
          v20 = m_triangle->m_links[m_index];
          v47.m_edge.m_triangle = (hkgpMeshBase::Triangle *)(v20 & 0xFFFFFFFFFFFFFFFCui64);
          v47.m_edge.m_index = (9 >> (2 * (v20 & 3))) & 3;
          v21 = v47;
          v45 = v47;
          if ( (v20 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            do
            {
              if ( v15 == (v53 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v15 = v52;
              }
              v22 = (hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array[16 * v15];
              if ( v22 )
              {
                *v22 = v21;
                v15 = v52;
              }
              v52 = ++v15;
              v23 = v45.m_edge.m_triangle->m_links[v45.m_edge.m_index] & 3;
              v48.m_edge.m_triangle = (hkgpMeshBase::Triangle *)(v45.m_edge.m_triangle->m_links[v45.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64);
              v48.m_edge.m_index = (9 >> (2 * v23)) & 3;
              v21 = v48;
              v45 = v48;
            }
            while ( v48.m_edge.m_triangle );
          }
LABEL_29:
          v24 = 0i64;
          if ( v15 <= 0 )
          {
LABEL_34:
            v27 = 0i64;
            v28 = 0i64;
            v29 = 0;
            if ( v15 > 0 )
            {
              v30 = 0i64;
              do
              {
                hkGeometryProcessing::computeMedian(
                  &result,
                  (hkVector4f *)(*(_QWORD *)(*(_QWORD *)&array[v30] + 16i64) + 32i64),
                  (hkVector4f *)(*(_QWORD *)(*(_QWORD *)&array[v30] + 24i64) + 32i64),
                  (hkVector4f *)(*(_QWORD *)(*(_QWORD *)&array[v30] + 32i64) + 32i64));
                ++v29;
                v31 = *(_QWORD **)&array[v30];
                v30 += 16i64;
                v32 = *(__m128 *)(v31[2] + 32i64);
                v33 = _mm_sub_ps(*(__m128 *)(v31[3] + 32i64), v32);
                v34 = _mm_sub_ps(*(__m128 *)(v31[4] + 32i64), v32);
                v35 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v33),
                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v34));
                v36 = _mm_shuffle_ps(v35, v35, 201);
                v37 = _mm_mul_ps(v36, v36);
                v38 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                        _mm_shuffle_ps(v37, v37, 170));
                v39 = _mm_rsqrt_ps(v38);
                v40 = _mm_andnot_ps(
                        _mm_cmple_ps(v38, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                            _mm_mul_ps(*(__m128 *)_xmm, v39)),
                          v38));
                v28 = _mm_add_ps(v28, v40);
                v27 = _mm_add_ps(v27, _mm_mul_ps(result.m_quad, v40));
              }
              while ( v29 < v52 );
            }
            if ( v28.m128_f32[0] > 0.00000011920929 )
            {
              v41 = _mm_rcp_ps(v28);
              v42 = (__m128 *)m_triangle->m_vertices[m_index];
              v42[2] = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v41)), v41), v27),
                             v42[2]),
                           v6),
                         v42[2]);
            }
          }
          else
          {
            v25 = array;
            while ( 1 )
            {
              v26 = *((int *)v25 + 2);
              if ( (*(_QWORD *)(*(_QWORD *)v25 + 8 * v26 + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0
                || (*(_QWORD *)(*(_QWORD *)v25 + 8i64 * ((9 >> (2 * v26)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
              {
                break;
              }
              ++v24;
              v25 += 16;
              if ( v24 >= v15 )
                goto LABEL_34;
            }
          }
          v52 = 0;
          if ( v53 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v53);
          if ( m_triangle )
          {
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v44);
            m_index = v44.m_edge.m_index;
            m_triangle = v44.m_edge.m_triangle;
          }
          v43 = &v44;
          if ( !m_triangle )
            v43 = 0i64;
        }
        while ( v43 );
        m_quad = query.m_quad;
      }
      v3 = _mm_sub_ps(v3, m_quad);
    }
    while ( v3.m128_f32[0] > 0.0 );
  }
}

