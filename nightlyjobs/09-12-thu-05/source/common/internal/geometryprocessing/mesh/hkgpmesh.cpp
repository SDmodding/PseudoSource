// File Line: 219
// RVA: 0xCD9360
hkgpMeshInternals::Ring *__fastcall hkgpMeshInternals::createRing(hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Edge *v1; // rbx
  __int64 v2; // r14
  hkgpMeshBase::Triangle *v3; // rbp
  _QWORD **v4; // rax
  __int64 v5; // rax
  _DWORD *v6; // rdi
  hkgpMeshBase::Triangle **v7; // rcx
  int v8; // er8
  char v9; // cl
  int v10; // eax
  signed int v11; // eax
  __int64 *v12; // rax
  __int64 v13; // r9
  __int64 v14; // r10
  __int64 v15; // r11
  __int64 v16; // rax
  int v17; // er8
  _QWORD **v18; // rax
  __int64 v20; // [rsp+28h] [rbp-30h]
  __int64 v21; // [rsp+38h] [rbp-20h]

  v1 = edge;
  if ( edge->m_triangle->m_links[edge->m_index] & 0xFFFFFFFFFFFFFFFCui64 )
    return 0i64;
  v2 = *(_QWORD *)&edge->m_index;
  v3 = edge->m_triangle;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 16i64);
  v6 = (_DWORD *)v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = 0i64;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 2147483648;
  }
  else
  {
    v6 = 0i64;
  }
  do
  {
    if ( v6[2] == (v6[3] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 64);
    v7 = (hkgpMeshBase::Triangle **)(*(_QWORD *)v6 + ((signed __int64)(signed int)v6[2]++ << 6));
    *v7 = v1->m_triangle;
    v7[1] = *(hkgpMeshBase::Triangle **)&v1->m_index;
    v8 = 2 * v1->m_index;
    if ( v1->m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(v1->m_index)) & 3] == v3->m_vertices[(signed int)v2] )
      break;
    v1->m_triangle = v1->m_triangle;
    LODWORD(v20) = (9 >> v8) & 3;
    *(_QWORD *)&v1->m_index = v20;
    if ( v1->m_triangle->m_links[(signed int)v20] & 0xFFFFFFFFFFFFFFFCui64 )
    {
      do
      {
        v9 = v1->m_triangle->m_links[v1->m_index] & 3;
        v1->m_triangle = (hkgpMeshBase::Triangle *)(v1->m_triangle->m_links[v1->m_index] & 0xFFFFFFFFFFFFFFFCui64);
        LODWORD(v21) = (9 >> 2 * v9) & 3;
        *(_QWORD *)&v1->m_index = v21;
      }
      while ( v1->m_triangle->m_links[(signed int)v21] & 0xFFFFFFFFFFFFFFFCui64 );
    }
  }
  while ( (char *)v1->m_triangle + v1->m_index != (char *)v3 + (unsigned int)v2 );
  v10 = v6[2];
  if ( v10 > 0
    && *(_QWORD *)(**(_QWORD **)v6 + 8i64 * *(signed int *)(*(_QWORD *)v6 + 8i64) + 16) != *(_QWORD *)(*(_QWORD *)(((signed __int64)(v10 - 1) << 6) + *(_QWORD *)v6) + 8 * ((9i64 >> 2 * (unsigned __int8)*(_DWORD *)(((signed __int64)(v10 - 1) << 6) + *(_QWORD *)v6 + 8)) & 3) + 16) )
  {
    v6[2] = 0;
  }
  v11 = v6[2];
  if ( v11 >= 3 )
    return (hkgpMeshInternals::Ring *)v6;
  if ( v11 == 2 )
  {
    v12 = *(__int64 **)v6;
    v13 = *(_QWORD *)(*(_QWORD *)v6 + 64i64);
    if ( !v13 )
      return (hkgpMeshInternals::Ring *)v6;
    v14 = *((signed int *)v12 + 18);
    v15 = *((signed int *)v12 + 2);
    v16 = *v12;
    if ( *(_QWORD *)(v16 + 8 * v15 + 16) == *(_QWORD *)(v13 + 8 * ((9i64 >> 2 * (unsigned __int8)v14) & 3) + 16)
      && *(_QWORD *)(v16 + 8 * ((9i64 >> 2 * (unsigned __int8)v15) & 3) + 16) == *(_QWORD *)(v13 + 8 * v14 + 16) )
    {
      return (hkgpMeshInternals::Ring *)v6;
    }
  }
  v6[2] = 0;
  v17 = v6[3];
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v6,
      v17 << 6);
  *(_QWORD *)v6 = 0i64;
  v6[3] = 2147483648;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, _DWORD *, signed __int64))(*v18[11] + 16i64))(v18[11], v6, 16i64);
  return 0i64;
}

// File Line: 280
// RVA: 0xCE0410
void __fastcall hkgpMeshInternals::ConcaveEdgeJob::run(hkgpMeshInternals::ConcaveEdgeJob *this)
{
  hkgpMeshInternals::ConcaveEdgeJob *v1; // r14
  hkgpConvexHull *v2; // rax
  int v3; // ecx
  hkgpConvexHull *v4; // r10
  int v5; // er12
  __int64 v6; // r13
  signed __int64 v7; // r15
  hkgpMeshInternals::Segment *v8; // rdi
  char *v9; // rsi
  signed __int64 v10; // rbx
  hkgpMeshInternals::Segment *v11; // rax
  __int64 v12; // rdx
  __m128i v13; // xmm0
  __m128 v14; // xmm7
  __m128 v15; // xmm8
  __m128i v16; // xmm11
  __m128i v17; // xmm14
  __m128 v18; // xmm9
  __m128i v19; // xmm10
  __m128 v20; // xmm12
  __m128 v21; // xmm13
  char v22; // r13
  char v23; // si
  float v24; // xmm1_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  hkgpMeshBase::Triangle *v27; // rax
  hkgpMesh *v28; // rcx
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  hkgpMesh *v31; // rcx
  int v32; // edi
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  __m128i v35; // xmm6
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm4
  __m128 v39; // xmm15
  hkgpMesh *v40; // rcx
  char v41; // r15
  __int64 v42; // rax
  char v43; // r12
  signed __int64 v44; // rdx
  __m128 v45; // xmm0
  __int64 v46; // rcx
  signed __int64 v47; // rdx
  __m128 v48; // xmm0
  __m128 v49; // [rsp+30h] [rbp-D0h]
  __m128 v50; // [rsp+30h] [rbp-D0h]
  hkVector4f v51; // [rsp+40h] [rbp-C0h]
  __m128 v52; // [rsp+50h] [rbp-B0h]
  hkVector4f point; // [rsp+60h] [rbp-A0h]
  hkgpMesh::IConvexOverlap::IConvexShape ishape; // [rsp+70h] [rbp-90h]
  hkgpMesh::Location *v55; // [rsp+78h] [rbp-88h]
  int v56; // [rsp+80h] [rbp-80h]
  hkVector4f normal; // [rsp+90h] [rbp-70h]
  hkgpMesh::Location location; // [rsp+A0h] [rbp-60h]
  hkSimdFloat32 offset; // [rsp+120h] [rbp+20h]
  __m128i v60; // [rsp+130h] [rbp+30h]
  __m128i v61; // [rsp+140h] [rbp+40h]
  __m128 v62; // [rsp+150h] [rbp+50h]
  __m128 v63; // [rsp+160h] [rbp+60h]
  hkVector4f a; // [rsp+170h] [rbp+70h]
  __m128i v65; // [rsp+180h] [rbp+80h]
  __m128 v66; // [rsp+190h] [rbp+90h]
  __m128 v67; // [rsp+1A0h] [rbp+A0h]
  __m128i v68; // [rsp+1B0h] [rbp+B0h]
  hkBool result; // [rsp+2A0h] [rbp+1A0h]
  int v70; // [rsp+2A8h] [rbp+1A8h]
  hkgpConvexHull *v71; // [rsp+2B0h] [rbp+1B0h]

  v1 = this;
  v2 = hkgpMesh::getConvexHull(this->m_mesh);
  v3 = v1->m_segments.m_size;
  v4 = v2;
  v71 = v2;
  if ( v3 )
  {
    v5 = 0;
    if ( v3 > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = 2i64;
        v8 = &v1->m_segments.m_data[v6];
        v9 = (char *)v8->m_valid;
        v10 = (signed __int64)v8->m_normals;
        do
        {
          v8->m_offsets[0] = v8->m_vertices[0];
          *v9++ = hkgpMesh::computeOffsetPoint(
                    v1->m_mesh,
                    (hkSimdFloat32 *)(v10 + 64),
                    (hkVector4f *)v10,
                    (hkVector4f *)(v10 + 32),
                    8,
                    1);
          v10 += 16i64;
          v8 = (hkgpMeshInternals::Segment *)((char *)v8 + 16);
          --v7;
        }
        while ( v7 );
        ++v5;
        ++v6;
      }
      while ( v5 < v1->m_segments.m_size );
      v4 = v71;
    }
    do
    {
      v11 = v1->m_segments.m_data;
      v12 = v1->m_segments.m_size;
      v13 = *((__m128i *)&v11[v12] - 1);
      v14 = *((__m128 *)&v11[v12] - 7);
      v15 = *((__m128 *)&v11[v12] - 6);
      v16 = (__m128i)v11[v12 - 1].m_vertices[0];
      v17 = *((__m128i *)&v11[v12] - 8);
      v18 = *((__m128 *)&v11[v12] - 5);
      v19 = *((__m128i *)&v11[v12] - 4);
      v20 = *((__m128 *)&v11[v12] - 3);
      v21 = *((__m128 *)&v11[v12] - 2);
      v1->m_segments.m_size = v12 - 1;
      v22 = _mm_cvtsi128_si32(v13);
      v68 = v13;
      v60 = v16;
      v23 = v68.m128i_i8[1];
      v61 = v17;
      v52 = v14;
      v62 = v14;
      v49 = v15;
      v63 = v15;
      a.m_quad = v18;
      v65 = v19;
      v66 = v20;
      v67 = v21;
      if ( !v22 || !v68.m128i_i8[1] )
        goto LABEL_21;
      v24 = *(float *)&xmmword_141A711B0;
      point.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)v19, v18), (__m128)xmmword_141A711B0), v18);
      if ( v4 )
      {
        if ( !hkgpConvexHull::isPointInside(v4, &result, &point, (hkBool)1, 0.0)->m_bool )
          goto LABEL_28;
        v24 = *(float *)&xmmword_141A711B0;
      }
      v70 = 1065185444;
      location.m_region.m_type = 0;
      v25 = (float)(v21.m128_f32[0] + v20.m128_f32[0]) * v24;
      v26 = COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F7D70A4u, (__m128)0x3F7D70A4u, 0)) * v25;
      if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v27 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
        v27 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      }
      v28 = v1->m_mesh;
      location.m_region.m_feature.m_triangle = v27;
      location.m_normal = 0i64;
      location.m_pseudoNormal = 0i64;
      location.m_coordinates = 0i64;
      *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                        + 1);
      location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
      location.m_inside.m_real = g_vectorfConstants[0];
      hkgpMesh::locate(v28, &point, &location, (hkBool)1);
      v29 = _mm_rsqrt_ps(location.m_squaredDistance.m_real);
      v30 = _mm_cmpleps(location.m_squaredDistance.m_real, (__m128)0i64);
      if ( (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       v30,
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(location.m_squaredDistance.m_real, v29), v29)),
                           _mm_mul_ps(*(__m128 *)_xmm, v29)),
                         location.m_squaredDistance.m_real)))
                 * location.m_inside.m_real.m128_f32[0]) <= v26 )
        goto LABEL_31;
      if ( (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       v30,
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(location.m_squaredDistance.m_real, v29), v29)),
                           _mm_mul_ps(*(__m128 *)_xmm, v29)),
                         location.m_squaredDistance.m_real)))
                 * location.m_inside.m_real.m128_f32[0]) >= (float)(v25 + v25) )
        goto LABEL_31;
      v31 = v1->m_mesh;
      _mm_store_si128((__m128i *)&location, v16);
      _mm_store_si128((__m128i *)&location.m_pseudoNormal, v17);
      _mm_store_si128((__m128i *)&location.m_coordinates, (__m128i)v18);
      _mm_store_si128((__m128i *)&location.m_projection, v19);
      ishape.vfptr = (hkgpMesh::IConvexOverlap::IConvexShapeVtbl *)&hkgpMesh::ExternShape::`vftable';
      v55 = &location;
      v56 = 4;
      if ( (unsigned __int8)hkgpMesh::checkOverlap(v31, &ishape, (float)(0.0 - v25) * 0.0099999998, 1) )
      {
LABEL_31:
        v14 = v52;
        v15 = v49;
LABEL_21:
        v32 = v68.m128i_i32[1];
        if ( v68.m128i_i32[1] < 5 )
        {
          v33 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v15, v14), (__m128)xmmword_141A711B0), v14);
          v50 = _mm_mul_ps(_mm_add_ps(v21, v20), (__m128)xmmword_141A711B0);
          offset.m_real = v50;
          v34 = _mm_mul_ps(v33, v33);
          v35 = (__m128i)_mm_add_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)v17, (__m128)v16), (__m128)xmmword_141A711B0),
                           (__m128)v16);
          v36 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170));
          v37 = _mm_rsqrt_ps(v36);
          v38 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v36), (__m128)0i64);
          v39 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v36, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                          _mm_mul_ps(*(__m128 *)_xmm, v37))),
                      v33),
                    v38),
                  _mm_andnot_ps(v38, v33));
          normal.m_quad = v39;
          if ( _mm_movemask_ps(v38) )
          {
            v40 = v1->m_mesh;
            _mm_store_si128((__m128i *)&v51, v35);
            v41 = hkgpMesh::computeOffsetPoint(v40, &offset, &normal, &v51, 8, 1);
            if ( v1->m_segments.m_size == (v1->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v1->m_segments,
                144);
            v42 = v1->m_segments.m_size;
            v43 = v68.m128i_i8[2];
            v44 = (signed __int64)&v1->m_segments.m_data[v42];
            v1->m_segments.m_size = v42 + 1;
            *(__m128i *)v44 = v16;
            *(__m128 *)(v44 + 32) = v14;
            *(__m128 *)(v44 + 64) = v18;
            *(__m128i *)(v44 + 80) = v19;
            *(__m128 *)(v44 + 96) = v20;
            *(__m128 *)(v44 + 112) = v21;
            *(_BYTE *)(v44 + 128) = v22;
            *(_BYTE *)(v44 + 129) = v23;
            *(_DWORD *)(v44 + 132) = v32;
            *(_BYTE *)(v44 + 130) = v43;
            *(__m128i *)(v44 + 16) = v35;
            *(__m128 *)(v44 + 48) = v39;
            v45 = v51.m_quad;
            *(_BYTE *)(v44 + 129) = v41;
            *(__m128 *)(v44 + 80) = v45;
            *(__m128 *)(v44 + 112) = v50;
            ++*(_DWORD *)(v44 + 132);
            if ( v1->m_segments.m_size == (v1->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v1->m_segments,
                144);
            v46 = v1->m_segments.m_size;
            v1->m_segments.m_size = v46 + 1;
            v47 = (signed __int64)&v1->m_segments.m_data[v46];
            *(__m128i *)(v47 + 16) = v17;
            *(__m128 *)(v47 + 48) = v15;
            *(__m128 *)(v47 + 64) = v18;
            *(__m128i *)(v47 + 80) = v19;
            *(__m128 *)(v47 + 96) = v20;
            *(__m128 *)(v47 + 112) = v21;
            *(_BYTE *)(v47 + 128) = v22;
            *(_BYTE *)(v47 + 129) = v23;
            *(_DWORD *)(v47 + 132) = v32;
            *(_BYTE *)(v47 + 130) = v43;
            *(__m128i *)v47 = v35;
            *(__m128 *)(v47 + 32) = v39;
            v48 = v51.m_quad;
            *(_BYTE *)(v47 + 128) = v41;
            *(__m128 *)(v47 + 64) = v48;
            *(__m128 *)(v47 + 96) = v50;
            ++*(_DWORD *)(v47 + 132);
          }
        }
        goto LABEL_28;
      }
      hkArrayBase<hkVector4f>::_append(
        (hkArrayBase<hkVector4f> *)&v1->m_edges.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &a,
        2);
LABEL_28:
      v4 = v71;
    }
    while ( v1->m_segments.m_size );
  }
}

// File Line: 399
// RVA: 0xCDC2F0
void __fastcall IConvexOverlapImpl::ShapeInterface::getSupportingVertices(IConvexOverlapImpl::ShapeInterface *this, const void *shapeA, hkVector4f *directionA, const void *shapeB, hkTransformf *aTb, hkcdVertex *vertexAinAOut, hkcdVertex *vertexBinBOut, hkVector4f *vertexBinAOut)
{
  __int64 v8; // rax
  hkVector4f v9; // xmm3
  __m128 v10; // xmm1
  const void *v11; // rdi
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // [rsp+20h] [rbp-18h]

  v8 = *(_QWORD *)shapeA;
  v9.m_quad = (__m128)aTb->m_rotation.m_col2;
  v10 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
  v11 = shapeB;
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
  (*(void (__fastcall **)(const void *, hkVector4f *, hkcdVertex *))(v8 + 16))(shapeA, directionA, vertexAinAOut);
  (*(void (__fastcall **)(const void *, __m128 *, hkcdVertex *))(*(_QWORD *)v11 + 16i64))(v11, &v15, vertexBinBOut);
  v14 = vertexBinBOut->m_quad;
  vertexBinAOut->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), aTb->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), aTb->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), aTb->m_rotation.m_col2.m_quad)),
                            aTb->m_translation.m_quad);
}

// File Line: 425
// RVA: 0xCD9620
float __fastcall IConvexOverlapImpl::distance(IConvexOverlapImpl *this, hkgpMesh::IConvexOverlap::IConvexShape *shapeA, hkgpMesh::IConvexOverlap::IConvexShape *shapeB, bool allowPenetration)
{
  hkgpMesh::IConvexOverlap::IConvexShape *v4; // r12
  hkgpMesh::IConvexOverlap::IConvexShape *v5; // r15
  signed int v6; // er14
  __m128 v7; // xmm11
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *v8; // rax
  int v9; // ebx
  __m128 v10; // xmm12
  __m128 v11; // xmm14
  __m128 v12; // xmm14
  __m128 v13; // xmm8
  __m128 v14; // xmm13
  signed __int64 v15; // r11
  unsigned int v16; // eax
  __m128 v17; // xmm15
  __m128 *v18; // rdx
  __m128 *v19; // rcx
  __m128 v20; // xmm10
  __m128 v21; // xmm0
  __m128 v22; // xmm8
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm9
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm7
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm7
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  __m128 v43; // xmm5
  __m128 v44; // xmm5
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm7
  __m128 v54; // xmm2
  signed int v55; // ecx
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm9
  __m128 v59; // xmm4
  __m128 v60; // xmm7
  __m128 v61; // xmm9
  __m128 v62; // xmm8
  __m128 v63; // xmm5
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  __m128 v66; // xmm6
  __m128 v67; // xmm3
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
  int v78; // er8
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
  __m128 v97; // xmm0
  __m128 v98; // xmm8
  __m128 v99; // xmm2
  __m128 v100; // xmm7
  __m128 v101; // xmm0
  __m128 v102; // xmm3
  __m128 v103; // xmm0
  __m128 v104; // xmm4
  __m128 v105; // xmm3
  __m128 v106; // xmm1
  __m128 v107; // xmm3
  __m128 v108; // xmm10
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __m128 v111; // xmm0
  __m128 v112; // xmm4
  __m128 v113; // xmm1
  __m128 v114; // xmm1
  __m128 v115; // xmm10
  __m128 v116; // xmm1
  __m128 v117; // xmm9
  __m128 v118; // xmm1
  __m128 v119; // xmm4
  __m128 v120; // xmm8
  __m128 v121; // xmm1
  __m128 v122; // xmm7
  __m128 v123; // xmm5
  __m128 v124; // xmm1
  __m128 v125; // xmm3
  __m128 v126; // xmm1
  __m128 v127; // xmm4
  __m128 v128; // xmm1
  __m128 v129; // xmm2
  __m128 v130; // xmm6
  __m128 v131; // xmm1
  __m128 v132; // xmm3
  __m128 v133; // xmm1
  __m128 v134; // xmm0
  __m128 v135; // xmm3
  __m128 v136; // xmm4
  __m128 v137; // xmm9
  __m128 v138; // xmm0
  __m128 v139; // xmm2
  __m128 v140; // xmm2
  __m128 v141; // xmm1
  __m128 v142; // xmm9
  __m128 v143; // xmm11
  __m128 v144; // xmm10
  __m128 v145; // xmm1
  __m128 v146; // xmm2
  __m128 v147; // xmm2
  __m128 v148; // xmm3
  __m128 v149; // xmm4
  __m128 v150; // xmm0
  __m128 v151; // xmm3
  __m128 v152; // xmm5
  __m128 v153; // xmm7
  __m128 v154; // xmm0
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm0
  __m128 v158; // xmm7
  __m128 v159; // xmm4
  __m128 v160; // xmm5
  __m128 v161; // xmm6
  __m128 v162; // xmm6
  __m128 v163; // xmm1
  __m128 v164; // xmm3
  __m128 v165; // xmm0
  __m128 v166; // xmm2
  __m128 v167; // xmm7
  __m128 v168; // xmm1
  __m128 v169; // xmm3
  __m128 v170; // xmm1
  __m128 v171; // xmm7
  __m128 v172; // xmm2
  __m128 v173; // xmm2
  __m128 v174; // xmm3
  __m128 v175; // xmm5
  __m128 v176; // xmm8
  __m128 v177; // xmm1
  __m128 v178; // xmm4
  __m128 v179; // xmm2
  __m128 v180; // xmm9
  __m128 v181; // xmm7
  __m128 v182; // xmm11
  __m128 v183; // xmm2
  __m128 v184; // xmm6
  __m128 v185; // xmm6
  __m128 v186; // xmm9
  __m128 v187; // xmm7
  __m128 v188; // xmm9
  __m128 v189; // xmm0
  __m128 v190; // xmm8
  __m128 v191; // xmm7
  __m128 v192; // xmm8
  __m128 v193; // xmm1
  __m128 v194; // xmm8
  __m128 v195; // xmm2
  __m128 v196; // xmm9
  int v197; // eax
  float v198; // xmm1_4
  float v199; // xmm10_4
  float v200; // xmm1_4
  float v201; // xmm10_4
  int v202; // ecx
  __m128 v203; // xmm9
  __m128 v204; // xmm8
  __m128 v205; // xmm5
  __m128 v206; // xmm4
  __m128 v207; // xmm2
  __m128 v208; // xmm12
  __m128 v209; // xmm2
  __m128 v210; // xmm4
  __m128 v211; // xmm2
  __m128 v212; // xmm6
  __m128 v213; // xmm3
  __m128 v214; // xmm4
  __m128 v215; // xmm2
  __m128 v216; // xmm0
  __m128 v217; // xmm7
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
  __m128 v241; // xmm1
  __m128 v242; // xmm2
  __m128 v243; // xmm0
  __m128 v244; // xmm3
  __m128 v245; // xmm2
  __m128 v246; // xmm2
  __m128 v247; // xmm0
  __m128 v248; // xmm1
  int v249; // ecx
  float v250; // xmm1_4
  float v251; // xmm10_4
  signed int v252; // eax
  signed int v253; // eax
  signed int v254; // eax
  __m128 v255; // xmm1
  __m128 v256; // xmm13
  __m128 v257; // xmm3
  __m128 v258; // xmm1
  __m128 v259; // xmm4
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *v260; // rax
  __m128 v261; // xmm1
  __m128 v262; // xmm3
  __m128 v263; // xmm3
  __m128 v264; // xmm1
  __m128 v265; // xmm2
  __m128 v266; // xmm9
  __m128 v267; // xmm9
  __m128 v268; // xmm0
  __m128 v269; // xmm6
  __m128 v270; // xmm3
  __m128 v271; // xmm1
  __m128 v272; // xmm2
  __m128 v273; // xmm6
  __m128 v274; // xmm7
  __m128 v275; // xmm4
  __m128 v276; // xmm3
  __m128 v277; // xmm2
  __m128 v278; // xmm0
  __m128 v279; // xmm1
  __m128 v280; // xmm7
  __m128 v281; // xmm2
  __m128 v282; // xmm8
  __m128 v283; // xmm8
  __m128 v284; // xmm2
  __m128 v285; // xmm6
  __m128 v286; // xmm1
  __m128 v287; // xmm10
  __m128 v288; // xmm15
  __m128 *v289; // r9
  __m128 v290; // xmm1
  __m128 v291; // xmm2
  __m128 v292; // xmm6
  __m128 v293; // xmm4
  __m128 v294; // xmm5
  __m128 v295; // xmm3
  __m128 v296; // xmm0
  __m128 v297; // xmm1
  __m128 v298; // xmm9
  __m128 v299; // xmm3
  __m128 v300; // xmm9
  __m128 v301; // xmm8
  __m128 v302; // xmm8
  __m128 v303; // xmm0
  __m128 v304; // xmm8
  __m128 v305; // xmm4
  __m128 v306; // xmm5
  __m128 v307; // xmm9
  __m128 v308; // xmm4
  __m128 v309; // xmm1
  __m128 v310; // xmm3
  __m128 v311; // xmm2
  __m128 v312; // xmm4
  __m128i v313; // xmm5
  __m128 v314; // xmm1
  __m128 v315; // xmm2
  __m128 v316; // xmm9
  __m128 v317; // xmm3
  __m128 v318; // xmm1
  __m128 v319; // xmm4
  __m128 v320; // xmm6
  signed int v321; // edx
  __m128 v322; // xmm2
  signed int v323; // eax
  signed int v324; // ecx
  signed int v325; // edi
  signed __int64 v326; // rsi
  signed __int64 v327; // r10
  int v328; // edx
  __int64 v329; // r8
  __m128 v330; // xmm0
  __m128 v331; // xmm2
  __m128 v332; // xmm4
  __m128 v333; // xmm7
  __m128 v334; // xmm5
  __m128 v335; // xmm1
  __m128 v336; // xmm3
  __m128 v337; // xmm4
  __m128 v338; // xmm7
  __int128 v339; // xmm10
  __m128 v340; // xmm1
  __m128 v341; // xmm5
  __m128 v342; // xmm2
  __m128 v343; // xmm4
  __m128 v344; // xmm3
  __m128 v345; // xmm6
  __m128 v346; // xmm9
  __m128 v347; // xmm7
  __m128 v348; // xmm8
  __m128 v349; // xmm8
  __m128 v350; // xmm9
  __m128 v351; // xmm6
  __m128 v352; // xmm9
  __m128 v353; // xmm6
  __m128 v354; // xmm7
  __m128 v355; // xmm1
  __m128 v356; // xmm7
  __m128 v357; // xmm2
  __m128 v358; // xmm9
  int v359; // ecx
  __m128 v360; // xmm2
  __m128 v361; // xmm0
  __int64 v362; // rcx
  signed int v363; // ecx
  __m128 v364; // xmm4
  __m128 v365; // xmm5
  __m128 v366; // xmm1
  __m128 v367; // xmm3
  __m128 v368; // xmm2
  __m128 v369; // xmm9
  __m128 v370; // xmm6
  __m128 v371; // xmm12
  __m128 v372; // xmm8
  __m128 v373; // xmm8
  __m128 v374; // xmm9
  __m128 v375; // xmm5
  __m128 v376; // xmm9
  __m128 v377; // xmm5
  __m128 v378; // xmm6
  __m128 v379; // xmm1
  __m128 v380; // xmm6
  __m128 v381; // xmm2
  __m128 v382; // xmm9
  int v383; // ecx
  __m128 v384; // xmm2
  __m128 v385; // xmm0
  __int64 v386; // rcx
  signed int v387; // ecx
  __m128 v388; // xmm6
  __m128 v389; // xmm7
  __m128 v390; // xmm5
  __m128 v391; // xmm1
  __m128 v392; // xmm4
  __m128 v393; // xmm1
  __m128 v394; // xmm2
  int v395; // eax
  __m128 v396; // xmm4
  __m128 v397; // xmm1
  __m128 v398; // xmm2
  __m128 v399; // xmm1
  __m128 v400; // xmm1
  __m128 v401; // xmm8
  __int64 v402; // r9
  __int64 v403; // rax
  __int64 v404; // rcx
  __m128 v405; // xmm0
  __m128 v406; // xmm14
  __m128 v407; // xmm3
  __m128 v408; // xmm2
  __m128 v409; // xmm3
  __m128 v410; // xmm4
  __m128 v411; // xmm7
  __m128 v412; // xmm5
  __m128 v413; // xmm1
  __m128 v414; // xmm2
  __m128 v415; // xmm1
  __m128 v416; // xmm6
  __m128 v417; // xmm5
  __m128 v418; // xmm1
  __m128 v419; // xmm8
  __m128 v420; // xmm2
  __m128 v421; // xmm2
  __m128 v422; // xmm8
  __m128 v423; // xmm2
  __int64 v424; // r9
  __int64 v425; // rax
  __int64 v426; // rcx
  __m128 v427; // xmm0
  __m128 v428; // xmm13
  __m128 v429; // xmm3
  __m128 v430; // xmm2
  __m128 v431; // xmm3
  __m128 v432; // xmm4
  __m128 v433; // xmm10
  _QWORD *v434; // rbx
  unsigned __int64 v435; // rcx
  unsigned __int64 v436; // rax
  hkcdGsk::GetClosestPointStatus v437; // eax
  _QWORD *v438; // rcx
  unsigned __int64 v439; // rax
  signed __int64 v440; // rcx
  __int64 v441; // r9
  char v442; // dl
  char v443; // r8
  float result; // xmm0_4
  int v445; // [rsp+48h] [rbp-80h]
  __m128 v446; // [rsp+50h] [rbp-78h]
  char v447[24]; // [rsp+60h] [rbp-68h]
  __m128 v448; // [rsp+78h] [rbp-50h]
  __int64 v449; // [rsp+90h] [rbp-38h]
  __m128 v450; // [rsp+98h] [rbp-30h]
  __m128 v451; // [rsp+A8h] [rbp-20h]
  __m128 v452; // [rsp+B8h] [rbp-10h]
  __m128 v453; // [rsp+E8h] [rbp+20h]
  __m128 v454; // [rsp+F8h] [rbp+30h]
  int v455; // [rsp+108h] [rbp+40h]
  int v456; // [rsp+10Ch] [rbp+44h]
  unsigned int v457; // [rsp+110h] [rbp+48h]
  void **v458; // [rsp+118h] [rbp+50h]
  int v459; // [rsp+120h] [rbp+58h]
  char v460; // [rsp+124h] [rbp+5Ch]
  __m128 v461; // [rsp+128h] [rbp+60h]
  hkTransformf aTb; // [rsp+138h] [rbp+70h]
  BOOL v463; // [rsp+178h] [rbp+B0h]
  __m128 v464; // [rsp+188h] [rbp+C0h]
  unsigned int v465; // [rsp+198h] [rbp+D0h]
  __m128 v466; // [rsp+1A8h] [rbp+E0h]
  __int128 v467; // [rsp+1B8h] [rbp+F0h]
  __m128 v468; // [rsp+1C8h] [rbp+100h]
  __m128 v469; // [rsp+1D8h] [rbp+110h]
  __m128 v470; // [rsp+1E8h] [rbp+120h]
  __m128 v471; // [rsp+1F8h] [rbp+130h]
  __m128 v472; // [rsp+208h] [rbp+140h]
  __m128 v473; // [rsp+218h] [rbp+150h]
  __m128 v474; // [rsp+228h] [rbp+160h]
  __m128 v475; // [rsp+238h] [rbp+170h]
  __m128 v476; // [rsp+248h] [rbp+180h]
  hkcdGsk::GetClosestPointOutput output; // [rsp+258h] [rbp+190h]
  __m128 v478; // [rsp+288h] [rbp+1C0h]
  __m128 v479; // [rsp+298h] [rbp+1D0h]
  __m128 v480; // [rsp+2A8h] [rbp+1E0h]
  __m128 v481; // [rsp+2B8h] [rbp+1F0h]
  __m128 v482; // [rsp+2C8h] [rbp+200h]
  __m128 v483; // [rsp+2D8h] [rbp+210h]
  __m128 v484; // [rsp+2E8h] [rbp+220h]
  __m128 v485; // [rsp+2F8h] [rbp+230h]
  __m128 v486; // [rsp+308h] [rbp+240h]
  __m128 v487; // [rsp+318h] [rbp+250h]
  __m128 v488; // [rsp+328h] [rbp+260h]
  __m128 v489; // [rsp+338h] [rbp+270h]
  __m128 v490; // [rsp+348h] [rbp+280h]
  __m128 v491; // [rsp+358h] [rbp+290h]
  __m128 v492; // [rsp+368h] [rbp+2A0h]
  __m128 v493; // [rsp+378h] [rbp+2B0h]
  __m128 v494; // [rsp+388h] [rbp+2C0h]
  __m128 v495; // [rsp+398h] [rbp+2D0h]
  __m128 v496; // [rsp+3A8h] [rbp+2E0h]
  __m128 v497; // [rsp+3B8h] [rbp+2F0h]
  __m128 v498; // [rsp+3C8h] [rbp+300h]
  __m128 v499; // [rsp+3D8h] [rbp+310h]
  __m128 v500; // [rsp+3E8h] [rbp+320h]
  hkVector4f supportOut; // [rsp+3F8h] [rbp+330h]
  __m128 v502; // [rsp+408h] [rbp+340h]
  __m128 v503; // [rsp+418h] [rbp+350h]
  __m128 v504; // [rsp+428h] [rbp+360h]
  __m128 v505; // [rsp+438h] [rbp+370h]
  __m128 v506; // [rsp+448h] [rbp+380h]
  hkVector4f v507; // [rsp+458h] [rbp+390h]
  hkVector4f v508; // [rsp+468h] [rbp+3A0h]
  hkVector4f v509; // [rsp+478h] [rbp+3B0h]
  hkVector4f v510; // [rsp+488h] [rbp+3C0h]
  __m128 v511; // [rsp+498h] [rbp+3D0h]
  __m128 v512; // [rsp+4A8h] [rbp+3E0h]
  __m128 v513; // [rsp+4B8h] [rbp+3F0h]
  __m128 v514; // [rsp+4C8h] [rbp+400h]
  hkPadSpu<int> dimB; // [rsp+5C0h] [rbp+4F8h]
  float v516; // [rsp+5C8h] [rbp+500h]
  hkPadSpu<int> dimA; // [rsp+5D0h] [rbp+508h]

  v4 = shapeA;
  v465 = LODWORD(FLOAT_1_4);
  v5 = shapeB;
  v6 = 0;
  v460 = 65;
  v459 = 0;
  v7 = 0i64;
  v464 = (__m128)xmmword_141A712A0;
  v463 = allowPenetration;
  v458 = &IConvexOverlapImpl::ShapeInterface::`vftable';
  v8 = shapeA->vfptr;
  aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  aTb.m_translation = 0i64;
  _mm_store_si128((__m128i *)&v467, (__m128i)transform.m_quad);
  v8->getSupportingVertex(shapeA, (hkVector4f *)&v467, (hkVector4f *)&v449);
  v5->vfptr->getSupportingVertex(v5, (hkVector4f *)&v467, (hkVector4f *)&v474);
  v9 = 1;
  dimA.m_storage = 1;
  dimB.m_storage = 1;
  v510.m_quad = (__m128)aTb.m_translation;
  v10 = 0i64;
  v446 = 0i64;
  v507.m_quad = (__m128)aTb.m_rotation.m_col0;
  v508.m_quad = (__m128)aTb.m_rotation.m_col1;
  v509.m_quad = (__m128)aTb.m_rotation.m_col2;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v474, v474, 85), aTb.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v474, v474, 0), aTb.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v474, v474, 170), aTb.m_rotation.m_col2.m_quad)),
          aTb.m_translation.m_quad);
  v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, v474), 196);
  v450 = v12;
  v451 = _mm_shuffle_ps(v451, _mm_unpackhi_ps(v451, v475), 196);
  v452 = _mm_shuffle_ps(v452, _mm_unpackhi_ps(v452, v476), 196);
  v516 = FLOAT_0_0000099999997;
  v472 = *(__m128 *)_xmm;
  v13 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v473 = (__m128)_xmm;
LABEL_2:
  v14 = *(__m128 *)((char *)&v446 + 8);
  v457 = v465;
  v15 = 3i64;
  v16 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
  v469 = _mm_mul_ps(v13, _mm_shuffle_ps((__m128)v465, (__m128)v465, 0));
  v17 = *(__m128 *)&v447[8];
  *(hkVector4f *)v447 = (hkVector4f)query.m_quad;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0u:
        goto LABEL_125;
      case 1u:
        goto LABEL_106;
      case 2u:
        goto LABEL_98;
      case 3u:
        v287 = *(__m128 *)v447;
        v288 = v14;
        v289 = &v450;
        goto LABEL_74;
      case 8u:
        goto LABEL_115;
      case 9u:
        goto LABEL_37;
      case 0xAu:
        v18 = (__m128 *)((char *)&v446 + 8);
        v19 = &v450;
        goto LABEL_6;
      case 0x10u:
        goto LABEL_90;
      case 0x11u:
        v18 = &v450;
        v19 = (__m128 *)((char *)&v446 + 8);
LABEL_6:
        if ( v445 == 2 )
        {
          v20 = *v19;
          v21 = v19[2];
          v22 = _mm_sub_ps(v19[1], v21);
          v23 = *v18;
          v24 = v18[1];
          v25 = _mm_sub_ps(*v19, v21);
          v454 = v25;
          v461 = v22;
          v26 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v22),
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v25));
          v27 = _mm_shuffle_ps(v26, v26, 201);
          v28 = _mm_mul_ps(_mm_sub_ps(v24, v20), v27);
          v29 = _mm_mul_ps(_mm_sub_ps(v23, v20), v27);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v31 = _mm_mul_ps(v30, v30);
          v32 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v33 = _mm_mul_ps(v32, v32);
          if ( _mm_movemask_ps(_mm_mul_ps(v32, v30)) )
          {
            v498 = _mm_sub_ps(v30, v32);
            v34 = _mm_rcp_ps(v498);
            v503 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v498, v34)), v34), v30);
            v35 = v19[1];
            v36 = v35;
            v37 = _mm_add_ps(*v18, _mm_mul_ps(_mm_sub_ps(v18[1], *v18), v503));
            v38 = _mm_sub_ps(v19[2], *v19);
            v39 = _mm_sub_ps(v35, v37);
            v40 = _mm_sub_ps(v19[2], v37);
            v41 = _mm_sub_ps(v36, *v19);
            v42 = _mm_sub_ps(*v19, v37);
            v43 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v41),
                    _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v38));
            v44 = _mm_shuffle_ps(v43, v43, 201);
            v45 = _mm_shuffle_ps(v44, v44, 210);
            v46 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v45),
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 210), v44)),
                    v39);
            v47 = _mm_shuffle_ps(v39, v39, 210);
            v48 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v45),
                      _mm_mul_ps(_mm_shuffle_ps(v42, v42, 210), v44)),
                    v40);
            v49 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v45);
            v50 = v46;
            v51 = _mm_unpackhi_ps(v46, v48);
            v52 = _mm_unpacklo_ps(v50, v48);
            v53 = _mm_mul_ps(_mm_sub_ps(v49, _mm_mul_ps(v47, v44)), v42);
            v54 = _mm_movelh_ps(v52, v53);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
                      v7,
                      _mm_add_ps(
                        _mm_shuffle_ps(v51, v53, 228),
                        _mm_add_ps(v54, _mm_shuffle_ps(_mm_movehl_ps(v54, v52), v53, 212))))) & 7) == 7 )
            {
              v55 = 1;
              goto LABEL_33;
            }
            goto LABEL_16;
          }
          v56 = v19[2];
          v57 = v19[1];
          v58 = _mm_cmpltps(v31, v33);
          v59 = _mm_sub_ps(v19[2], v57);
          v60 = _mm_sub_ps(v57, v20);
          v61 = _mm_or_ps(_mm_and_ps(v58, v23), _mm_andnot_ps(v58, v24));
          v62 = _mm_shuffle_ps(v59, v59, 201);
          v63 = _mm_sub_ps(v20, v56);
          v64 = _mm_sub_ps(v61, v57);
          v65 = _mm_sub_ps(v61, v56);
          v66 = _mm_shuffle_ps(v63, v63, 201);
          v67 = _mm_sub_ps(v61, v20);
          v68 = _mm_sub_ps(_mm_mul_ps(v66, v59), _mm_mul_ps(v62, v63));
          v10 = _mm_shuffle_ps(v68, v68, 201);
          v446 = v10;
          v69 = _mm_sub_ps(_mm_mul_ps(v62, v64), _mm_mul_ps(_mm_shuffle_ps(v64, v64, 201), v59));
          v70 = _mm_sub_ps(_mm_mul_ps(v66, v65), _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v63));
          v71 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v10);
          v72 = _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v10);
          v73 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v67),
                  _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v60));
          v74 = _mm_unpacklo_ps(v71, v72);
          v75 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v10);
          v76 = _mm_movelh_ps(v74, v75);
          v77 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v71, v72), v75, 228),
                  _mm_add_ps(v76, _mm_shuffle_ps(_mm_movehl_ps(v76, v74), v75, 212)));
          v78 = _mm_movemask_ps(_mm_cmpltps(v77, v7)) & 7;
          if ( v78 == 7 )
          {
            v79 = _mm_mul_ps(_mm_sub_ps(v14, v12), v10);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                     _mm_shuffle_ps(v79, v79, 170))) )
            {
              v10 = _mm_xor_ps(v10, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v446 = v10;
              v80 = *v19;
              *v19 = v19[1];
              v19[1] = v80;
              *(hkVector4f *)v447 = (hkVector4f)query.m_quad;
              v77 = _mm_shuffle_ps(v77, v77, 225);
            }
          }
          *(__m128 *)&v447[16] = v77;
          if ( v78 != 7 )
          {
            v22 = v461;
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
            v90 = _mm_mul_ps(v461, v461);
            v505 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                     _mm_shuffle_ps(v84, v84, 170));
            v512 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                     _mm_shuffle_ps(v90, v90, 170));
            v91 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v512, v505), _mm_mul_ps(v85, v85)), *(__m128 *)&epsilon);
            v92 = _mm_rcp_ps(v91);
            v514 = v91;
            v93 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v92, v91)), v92);
            v94 = _mm_rcp_ps(v512);
            v480 = v93;
            v95 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v94, v512)), v94);
            v96 = _mm_rcp_ps(v505);
            v496 = v95;
            v482 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v96, v505)), v96);
            v97 = _mm_mul_ps(v89, v85);
            v98 = _mm_mul_ps(v89, v95);
            v99 = _mm_cmpleps(v91, *(__m128 *)&epsilon);
            v100 = _mm_sub_ps(_mm_mul_ps(v512, v88), v97);
            v101 = _mm_cmpltps(v100, v91);
            v102 = _mm_andnot_ps(
                     v99,
                     _mm_mul_ps(
                       _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v101, v91), _mm_and_ps(v101, v100))),
                       v93));
            v103 = _mm_mul_ps(v85, v95);
            v104 = v19[2];
            v105 = _mm_sub_ps(_mm_mul_ps(_mm_or_ps(v102, _mm_and_ps(v99, *(__m128 *)v447)), v103), v98);
            v106 = _mm_cmpltps(v105, *(__m128 *)v447);
            v107 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v106, *(__m128 *)v447), _mm_and_ps(v106, v105)));
            v108 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v85, v482), v107), _mm_mul_ps(v88, v482));
            v109 = _mm_cmpltps(v108, *(__m128 *)v447);
            v110 = _mm_add_ps(
                     *v18,
                     _mm_mul_ps(
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v109, *(__m128 *)v447), _mm_and_ps(v109, v108))),
                       v82));
            v111 = v104;
            v112 = _mm_sub_ps(v104, *v18);
            v113 = _mm_sub_ps(v110, _mm_add_ps(v111, _mm_mul_ps(v107, v461)));
            v114 = _mm_mul_ps(v113, v113);
            v115 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                     _mm_shuffle_ps(v114, v114, 170));
            v116 = _mm_mul_ps(v82, v454);
            v117 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                     _mm_shuffle_ps(v116, v116, 170));
            v118 = _mm_mul_ps(v112, v82);
            v119 = _mm_mul_ps(v112, v454);
            v120 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                     _mm_shuffle_ps(v118, v118, 170));
            v121 = _mm_mul_ps(v454, v454);
            v122 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                     _mm_shuffle_ps(v119, v119, 170));
            v484 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
                     _mm_shuffle_ps(v121, v121, 170));
            v504 = v505;
            v123 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v484, v505), _mm_mul_ps(v117, v117)), *(__m128 *)&epsilon);
            v124 = _mm_rcp_ps(v123);
            v478 = v123;
            v125 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v124, v123)), v124);
            v126 = _mm_rcp_ps(v484);
            v486 = v125;
            v127 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v126, v484)), v126);
            v128 = _mm_rcp_ps(v505);
            v511 = v127;
            v129 = _mm_cmpleps(v123, *(__m128 *)&epsilon);
            v130 = _mm_sub_ps(_mm_mul_ps(v484, v120), _mm_mul_ps(v122, v117));
            v488 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v128, v505)), v128);
            v131 = _mm_cmpltps(v130, v123);
            v132 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v129,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v131, v123), _mm_and_ps(v131, v130))),
                             v125)),
                         _mm_and_ps(v129, *(__m128 *)v447)),
                       _mm_mul_ps(v117, v127)),
                     _mm_mul_ps(v122, v127));
            v133 = _mm_cmpltps(v132, *(__m128 *)v447);
            v134 = _mm_and_ps(v133, v132);
            v7 = 0i64;
            v135 = v19[2];
            v136 = _mm_max_ps((__m128)0i64, _mm_or_ps(v134, _mm_andnot_ps(v133, *(__m128 *)v447)));
            v137 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v117, v488), v136), _mm_mul_ps(v120, v488));
            v138 = _mm_cmpltps(v137, *(__m128 *)v447);
            v139 = _mm_sub_ps(
                     _mm_add_ps(
                       *v18,
                       _mm_mul_ps(
                         _mm_max_ps(
                           (__m128)0i64,
                           _mm_or_ps(_mm_and_ps(v138, v137), _mm_andnot_ps(v138, *(__m128 *)v447))),
                         v82)),
                     _mm_add_ps(v19[2], _mm_mul_ps(v136, v454)));
            v140 = _mm_mul_ps(v139, v139);
            v141 = _mm_cmpltps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                       _mm_shuffle_ps(v140, v140, 170)),
                     v115);
            *v19 = _mm_or_ps(_mm_and_ps(v141, *v19), _mm_andnot_ps(v141, v19[1]));
            v19[1] = v135;
            v10 = v446;
LABEL_31:
            v55 = 2;
            goto LABEL_32;
          }
          *v18 = v61;
          v55 = 0;
LABEL_32:
          v14 = *(__m128 *)((char *)&v446 + 8);
          v17 = *(__m128 *)&v447[8];
          v12 = v450;
          *(hkVector4f *)v447 = (hkVector4f)query.m_quad;
          goto LABEL_33;
        }
        v142 = *v19;
        v143 = v18[1];
        v144 = *(__m128 *)&v447[16];
        v145 = _mm_mul_ps(_mm_sub_ps(*v18, *v19), v10);
        v146 = _mm_sub_ps(v18[1], *v19);
        v454 = *v19;
        v147 = _mm_mul_ps(v146, v10);
        v148 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                 _mm_shuffle_ps(v145, v145, 170));
        v149 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v147, v147, 85), _mm_shuffle_ps(v147, v147, 0)),
                 _mm_shuffle_ps(v147, v147, 170));
        if ( (float)(v149.m128_f32[0] * v148.m128_f32[0]) < 0.0 )
        {
          v500 = _mm_sub_ps(v148, v149);
          v150 = _mm_rcp_ps(v500);
          v490 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v500, v150)), v150), v148);
          v151 = *v18;
          v152 = v19[2];
          v153 = v19[1];
          v143 = v18[1];
          v154 = _mm_sub_ps(v18[1], *v18);
          v155 = _mm_sub_ps(v19[1], *v19);
          v454 = *v19;
          v142 = v454;
          v156 = _mm_add_ps(v151, _mm_mul_ps(v154, v490));
          v157 = _mm_sub_ps(v152, v454);
          v158 = _mm_sub_ps(v153, v156);
          v159 = _mm_sub_ps(v454, v156);
          v160 = _mm_sub_ps(v152, v156);
          v161 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), v155),
                   _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v157));
          v162 = _mm_shuffle_ps(v161, v161, 201);
          v163 = _mm_shuffle_ps(v162, v162, 210);
          v164 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v160, v160, 201), v163),
                     _mm_mul_ps(_mm_shuffle_ps(v160, v160, 210), v162)),
                   v158);
          v165 = _mm_shuffle_ps(v158, v158, 210);
          v166 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v159, v159, 201), v163),
                     _mm_mul_ps(_mm_shuffle_ps(v159, v159, 210), v162)),
                   v160);
          v167 = _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v163);
          v168 = v164;
          v169 = _mm_unpackhi_ps(v164, v166);
          v170 = _mm_unpacklo_ps(v168, v166);
          v171 = _mm_mul_ps(_mm_sub_ps(v167, _mm_mul_ps(v165, v162)), v159);
          v172 = _mm_movelh_ps(v170, v171);
          if ( (_mm_movemask_ps(
                  _mm_cmpltps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_shuffle_ps(v169, v171, 228),
                      _mm_add_ps(v172, _mm_shuffle_ps(_mm_movehl_ps(v172, v170), v171, 212))))) & 7) == 7 )
          {
            v55 = 1;
            v7 = 0i64;
            goto LABEL_33;
          }
        }
        v173 = v19[1];
        v174 = v19[2];
        v175 = _mm_sub_ps(v142, v174);
        v176 = _mm_sub_ps(v19[1], v142);
        v177 = _mm_sub_ps(v143, v173);
        v178 = _mm_sub_ps(v19[2], v173);
        v179 = v143;
        v180 = _mm_shuffle_ps(v178, v178, 201);
        v181 = _mm_shuffle_ps(v175, v175, 201);
        v182 = _mm_sub_ps(v143, v454);
        v183 = _mm_sub_ps(v179, v174);
        v184 = _mm_sub_ps(_mm_mul_ps(v181, v178), _mm_mul_ps(v180, v175));
        v185 = _mm_shuffle_ps(v184, v184, 201);
        v186 = _mm_sub_ps(_mm_mul_ps(v180, v177), _mm_mul_ps(_mm_shuffle_ps(v177, v177, 201), v178));
        v187 = _mm_sub_ps(_mm_mul_ps(v181, v183), _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v175));
        v188 = _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v185);
        v189 = _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), v176);
        v190 = _mm_mul_ps(_mm_shuffle_ps(v176, v176, 201), v182);
        v191 = _mm_mul_ps(_mm_shuffle_ps(v187, v187, 201), v185);
        v7 = 0i64;
        v192 = _mm_sub_ps(v190, v189);
        v193 = _mm_unpacklo_ps(v188, v191);
        v194 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v185);
        v195 = _mm_movelh_ps(v193, v194);
        v196 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v188, v191), v194, 228),
                 _mm_add_ps(v195, _mm_shuffle_ps(_mm_movehl_ps(v195, v193), v194, 212)));
        *(__m128 *)&v447[16] = v196;
        v197 = _mm_movemask_ps(_mm_cmpltps(v196, (__m128)0i64)) & 7;
        switch ( v197 )
        {
          case 7:
            v55 = 0;
            *v18 = v18[1];
            goto LABEL_32;
          case 6:
            goto LABEL_30;
          case 5:
            goto LABEL_47;
          case 3:
            goto LABEL_48;
          case 1:
            LODWORD(v198) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 85);
            LODWORD(v199) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 170);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 85)) - v198) * v199) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 170)) - v199) * v198) )
              goto LABEL_48;
            goto LABEL_47;
        }
        if ( v197 != 2 )
        {
          if ( v197 != 4
            || (LODWORD(v250) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 0),
                LODWORD(v251) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 85),
                (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 0)) - v250) * v251) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 85)) - v251) * v250)) )
          {
LABEL_30:
            *v19 = v19[2];
            goto LABEL_31;
          }
LABEL_47:
          v19[1] = v19[2];
          v12 = v450;
          v17 = *(__m128 *)&v447[8];
          v14 = *(__m128 *)((char *)&v446 + 8);
          *(hkVector4f *)v447 = (hkVector4f)query.m_quad;
          goto LABEL_48;
        }
        LODWORD(v200) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 170);
        LODWORD(v201) = (unsigned __int128)_mm_shuffle_ps(v144, v144, 0);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 170)) - v200) * v201) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v196, v196, 0)) - v201) * v200) )
          goto LABEL_30;
LABEL_48:
        v55 = 2;
LABEL_33:
        if ( v55 )
        {
          v202 = v55 - 1;
          if ( !v202 )
            goto LABEL_58;
          if ( v202 != 1 )
            goto LABEL_129;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_37:
          v203 = _mm_sub_ps(v17, v14);
          v204 = _mm_sub_ps(v14, v12);
          v205 = _mm_sub_ps(v451, v12);
          v206 = _mm_shuffle_ps(v203, v203, 201);
          v454 = v203;
          v461 = v204;
          v207 = _mm_shuffle_ps(v205, v205, 201);
          v208 = _mm_sub_ps(_mm_mul_ps(v207, v203), _mm_mul_ps(v206, v205));
          v10 = _mm_shuffle_ps(v208, v208, 201);
          v446 = v10;
          v209 = _mm_sub_ps(_mm_mul_ps(v207, v10), _mm_mul_ps(v10, v205));
          v210 = _mm_sub_ps(_mm_mul_ps(v206, v10), _mm_mul_ps(v10, v203));
          v211 = _mm_shuffle_ps(v209, v209, 201);
          v212 = _mm_mul_ps(v204, v211);
          v213 = _mm_mul_ps(_mm_sub_ps(v12, v17), v211);
          v214 = _mm_shuffle_ps(v210, v210, 201);
          v215 = _mm_shuffle_ps(v212, v213, 68);
          v216 = _mm_mul_ps(v204, v214);
          v217 = _mm_mul_ps(_mm_sub_ps(v451, v14), v214);
          v218 = _mm_shuffle_ps(v216, v217, 68);
          v219 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v212, v213, 238), _mm_shuffle_ps(v216, v217, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v215, v218, 221), _mm_shuffle_ps(v215, v218, 136)));
          v220 = _mm_movemask_ps(_mm_cmpltps(v7, v219));
          if ( v220 == 15 )
          {
            v283 = _mm_mul_ps(v204, v10);
            v284 = _mm_shuffle_ps(v219, v219, 0);
            v285 = _mm_add_ps(_mm_shuffle_ps(v219, v219, 85), v284);
            v286 = _mm_rcp_ps(v285);
            v481 = v285;
            v483 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v286, v285)), v286), v284);
            v282 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_shuffle_ps(v283, v283, 170),
                                            _mm_add_ps(_mm_shuffle_ps(v283, v283, 85), _mm_shuffle_ps(v283, v283, 0))),
                                 0x1Fu),
                               0x1Fu),
                     v10);
            v453 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v14), v483), v14);
            goto LABEL_128;
          }
          v221 = v220 - 7;
          if ( !v221 )
          {
            v12 = v451;
            v450 = v451;
LABEL_70:
            dimB.m_storage = 1;
LABEL_115:
            v410 = _mm_sub_ps(v17, v14);
            v411 = _mm_sub_ps(v17, v12);
            v412 = _mm_sub_ps(v14, v12);
            v413 = _mm_mul_ps(v411, v410);
            v414 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v413, v413, 85), _mm_shuffle_ps(v413, v413, 0)),
                     _mm_shuffle_ps(v413, v413, 170));
            v415 = _mm_mul_ps(v412, v410);
            v416 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v415, v415, 85), _mm_shuffle_ps(v415, v415, 0)),
                     _mm_shuffle_ps(v415, v415, 170));
            if ( (float)(v416.m128_f32[0] * v414.m128_f32[0]) >= v7.m128_f32[0] )
            {
              v423 = _mm_cmpleps(v414, v7);
              dimA.m_storage = 1;
              v14 = _mm_or_ps(_mm_and_ps(v423, v17), _mm_andnot_ps(v423, v14));
              *(__m128 *)((char *)&v446 + 8) = v14;
              v282 = _mm_sub_ps(v14, v12);
            }
            else
            {
              dimA.m_storage = 2;
              v417 = _mm_sub_ps(_mm_mul_ps(v412, v414), _mm_mul_ps(v411, v416));
              v418 = _mm_mul_ps(v410, v410);
              v419 = _mm_shuffle_ps(v410, v410, 201);
              v420 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v417, v417, 201), v410), _mm_mul_ps(v419, v417));
              v491 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v418, v418, 85), _mm_shuffle_ps(v418, v418, 0)),
                       _mm_shuffle_ps(v418, v418, 170));
              v421 = _mm_shuffle_ps(v420, v420, 201);
              v493 = _mm_rcp_ps(v491);
              v422 = _mm_sub_ps(_mm_mul_ps(v419, v421), _mm_mul_ps(v421, v410));
              v282 = _mm_mul_ps(_mm_shuffle_ps(v422, v422, 201), v493);
            }
LABEL_128:
            v446 = v282;
LABEL_129:
            v10 = v446;
            v445 = dimB.m_storage;
            v254 = 0;
            goto LABEL_59;
          }
          v222 = v221 - 4;
          if ( !v222 )
            goto LABEL_70;
          v223 = v222 - 2;
          if ( !v223 )
          {
            v14 = v17;
            *(__m128 *)((char *)&v446 + 8) = v17;
LABEL_68:
            dimA.m_storage = 1;
LABEL_106:
            v388 = _mm_sub_ps(v12, v14);
            v389 = _mm_sub_ps(v451, v14);
            v390 = _mm_sub_ps(v451, v12);
            v391 = _mm_mul_ps(v390, v389);
            v392 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v391, v391, 85), _mm_shuffle_ps(v391, v391, 0)),
                     _mm_shuffle_ps(v391, v391, 170));
            v393 = _mm_mul_ps(v388, v390);
            v394 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v393, v393, 85), _mm_shuffle_ps(v393, v393, 0)),
                     _mm_shuffle_ps(v393, v393, 170));
            if ( (float)(v394.m128_f32[0] * v392.m128_f32[0]) >= v7.m128_f32[0] )
            {
              v432 = _mm_cmpleps(v392, v7);
              v395 = 1;
              v12 = _mm_or_ps(_mm_and_ps(v451, v432), _mm_andnot_ps(v432, v12));
              v282 = _mm_sub_ps(v14, v12);
              v450 = v12;
            }
            else
            {
              v395 = 2;
              v396 = _mm_sub_ps(_mm_mul_ps(v392, v388), _mm_mul_ps(v394, v389));
              v397 = _mm_mul_ps(v390, v390);
              v398 = _mm_shuffle_ps(v390, v390, 201);
              v495 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v397, v397, 85), _mm_shuffle_ps(v397, v397, 0)),
                       _mm_shuffle_ps(v397, v397, 170));
              v497 = _mm_rcp_ps(v495);
              v399 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v396, v396, 201), v390), _mm_mul_ps(v396, v398));
              v400 = _mm_shuffle_ps(v399, v399, 201);
              v401 = _mm_sub_ps(_mm_mul_ps(v400, v390), _mm_mul_ps(v400, v398));
              v282 = _mm_mul_ps(_mm_shuffle_ps(v401, v401, 201), v497);
            }
            dimB.m_storage = v395;
            goto LABEL_128;
          }
          if ( v223 == 1 )
            goto LABEL_68;
          v224 = _mm_mul_ps(v205, v203);
          v225 = _mm_sub_ps(v12, v14);
          v226 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v224, v224, 85), _mm_shuffle_ps(v224, v224, 0)),
                   _mm_shuffle_ps(v224, v224, 170));
          v227 = _mm_mul_ps(v225, v203);
          v228 = _mm_mul_ps(v225, v205);
          v229 = _mm_mul_ps(v205, v205);
          v230 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v227, v227, 85), _mm_shuffle_ps(v227, v227, 0)),
                   _mm_shuffle_ps(v227, v227, 170));
          v231 = _mm_mul_ps(v454, v454);
          v232 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v228, v228, 85), _mm_shuffle_ps(v228, v228, 0)),
                   _mm_shuffle_ps(v228, v228, 170));
          v506 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                   _mm_shuffle_ps(v231, v231, 170));
          v492 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v229, v229, 85), _mm_shuffle_ps(v229, v229, 0)),
                   _mm_shuffle_ps(v229, v229, 170));
          v233 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v492, v506), _mm_mul_ps(v226, v226)), *(__m128 *)&epsilon);
          v234 = _mm_rcp_ps(v233);
          v502 = v233;
          v235 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v234, v233)), v234);
          v236 = _mm_rcp_ps(v492);
          v494 = v235;
          v237 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v236, v492)), v236);
          v238 = _mm_rcp_ps(v506);
          v513 = v237;
          v239 = _mm_sub_ps(_mm_mul_ps(v492, v230), _mm_mul_ps(v232, v226));
          v479 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v238, v506)), v238);
          v240 = _mm_cmpltps(v239, v233);
          v241 = _mm_cmpleps(v233, *(__m128 *)&epsilon);
          v242 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(
                       _mm_andnot_ps(
                         v241,
                         _mm_mul_ps(
                           _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v239, v240), _mm_andnot_ps(v240, v233))),
                           v235)),
                       _mm_and_ps(v241, *(__m128 *)v447)),
                     _mm_mul_ps(v237, v226)),
                   _mm_mul_ps(v237, v232));
          v243 = _mm_cmpltps(v242, *(__m128 *)v447);
          v244 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v242, v243), _mm_andnot_ps(v243, *(__m128 *)v447)));
          v245 = _mm_mul_ps(v479, v226);
          v7 = 0i64;
          v246 = _mm_add_ps(_mm_mul_ps(v245, v244), _mm_mul_ps(v479, v230));
          v247 = _mm_cmpltps(v246, *(__m128 *)v447);
          v248 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v246, v247), _mm_andnot_ps(v247, *(__m128 *)v447)));
          v249 = _mm_movemask_ps(
                   _mm_cmpeqps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v248, v248), _mm_unpacklo_ps(v244, v244)),
                     (__m128)xmmword_141A71330));
          v453 = _mm_add_ps(_mm_mul_ps(v248, v454), v14);
          if ( !v249 )
          {
            v281 = _mm_mul_ps(v461, v10);
            v282 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v281, v281, 85), _mm_shuffle_ps(v281, v281, 0)),
                                            _mm_shuffle_ps(v281, v281, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v10);
            goto LABEL_128;
          }
          if ( v249 & 1 )
          {
            v14 = v17;
            *(__m128 *)((char *)&v446 + 8) = v17;
            dimA.m_storage = 1;
          }
          else
          {
            v252 = dimA.m_storage;
            if ( v249 & 2 )
              v252 = 1;
            dimA.m_storage = v252;
          }
          if ( v249 & 4 )
          {
            v12 = v451;
            dimB.m_storage = 1;
            v450 = v451;
          }
          else
          {
            v253 = dimB.m_storage;
            if ( v249 & 8 )
              v253 = 1;
            dimB.m_storage = v253;
          }
          v16 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
          if ( v16 > 0x18 )
          {
LABEL_58:
            v254 = 1;
            goto LABEL_59;
          }
          continue;
        }
        if ( dimA.m_storage == 2 )
        {
          v10 = v446;
          dimA.m_storage = 1;
          v445 = dimB.m_storage;
          v254 = 0;
        }
        else
        {
          v10 = v446;
          dimB.m_storage = 1;
          v254 = 0;
          v445 = 1;
        }
LABEL_59:
        v13 = v469;
        v255 = _mm_mul_ps(v10, v10);
        v256 = _mm_mul_ps(_mm_sub_ps(v14, v12), v10);
        v257 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v255, v255, 85), _mm_shuffle_ps(v255, v255, 0)),
                 _mm_shuffle_ps(v255, v255, 170));
        v258 = _mm_rsqrt_ps(v257);
        v499 = v257;
        v259 = _mm_andnot_ps(
                 _mm_cmpleps(v257, v7),
                 _mm_mul_ps(_mm_sub_ps(v473, _mm_mul_ps(_mm_mul_ps(v258, v257), v258)), _mm_mul_ps(v258, v472)));
        v10 = _mm_mul_ps(v10, v259);
        v446 = v10;
        if ( !v254
          && (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v256, v256, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v256, v256, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v256, v256, 170)))
                   * v259.m128_f32[0]) >= v469.m128_f32[0]
          && v257.m128_f32[0] >= (float)((float)(v469.m128_f32[0] * v469.m128_f32[0])
                                       * (float)(v469.m128_f32[0] * v469.m128_f32[0])) )
        {
          v260 = v4->vfptr;
          v261 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v262 = _mm_xor_ps(v261, v10);
          v466 = v262;
          v263 = _mm_xor_ps(v262, v261);
          v264 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
          v265 = _mm_movelh_ps(v264, aTb.m_rotation.m_col2.m_quad);
          v470 = _mm_add_ps(
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
          v260->getSupportingVertex(v4, (hkVector4f *)&v466, (hkVector4f *)&v468);
          v5->vfptr->getSupportingVertex(v5, (hkVector4f *)&v470, (hkVector4f *)&v471);
          v266 = _mm_add_ps(
                   aTb.m_translation.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v471, v471, 85), aTb.m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v471, v471, 0), aTb.m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v471, v471, 170), aTb.m_rotation.m_col2.m_quad)));
          v267 = _mm_shuffle_ps(v266, _mm_unpackhi_ps(v266, v471), 196);
          v268 = _mm_mul_ps(_mm_sub_ps(v468, *(__m128 *)((char *)&v446 + 8)), v466);
          v269 = _mm_mul_ps(_mm_sub_ps(v468, v267), v10);
          v270 = _mm_mul_ps(_mm_sub_ps(v267, v450), v10);
          v271 = _mm_unpacklo_ps(v269, v268);
          v272 = _mm_movelh_ps(v271, v270);
          v273 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v269, v268), v270, 228),
                   _mm_add_ps(v272, _mm_shuffle_ps(_mm_movehl_ps(v272, v271), v270, 212)));
          v274 = _mm_mul_ps(_mm_sub_ps(v468, *(__m128 *)&v447[8]), v466);
          v275 = _mm_mul_ps(_mm_sub_ps(v468, v448), v466);
          v276 = _mm_mul_ps(_mm_sub_ps(v267, v451), v10);
          v277 = _mm_shuffle_ps(v274, v275, 68);
          v278 = _mm_mul_ps(_mm_sub_ps(v267, v452), v10);
          v279 = _mm_shuffle_ps(v276, v278, 68);
          v280 = _mm_cmpltps(
                   _mm_add_ps(
                     _mm_shuffle_ps(_mm_shuffle_ps(v274, v275, 238), _mm_shuffle_ps(v276, v278, 238), 136),
                     _mm_add_ps(_mm_shuffle_ps(v277, v279, 221), _mm_shuffle_ps(v277, v279, 136))),
                   v13);
          switch ( _mm_movemask_ps(_mm_cmpltps(_mm_movelh_ps(_mm_unpacklo_ps(v464, v13), _mm_unpacklo_ps(v13, v13)), v273)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v6 = 5;
              output.m_distance.m_real = _mm_shuffle_ps(v273, v273, 0);
              goto LABEL_147;
            case 2:
              goto LABEL_131;
            case 4:
              goto LABEL_133;
            case 6:
              if ( COERCE_FLOAT(_mm_shuffle_ps(v273, v273, 170)) > COERCE_FLOAT(_mm_shuffle_ps(v273, v273, 85)) )
              {
LABEL_133:
                if ( _mm_movemask_ps(v280) & hkcdGskBase::dimToMaskZ[dimB.m_storage] )
                {
LABEL_136:
                  v433 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v446 + 8), v450), v10);
                  output.m_distance.m_real = _mm_add_ps(
                                               _mm_add_ps(_mm_shuffle_ps(v433, v433, 85), _mm_shuffle_ps(v433, v433, 0)),
                                               _mm_shuffle_ps(v433, v433, 170));
                  goto LABEL_147;
                }
                *(&v450 + dimB.m_storage++) = v267;
                v12 = v450;
              }
              else
              {
LABEL_131:
                if ( _mm_movemask_ps(v280) & hkcdGskBase::dimToMaskY[dimA.m_storage] )
                  goto LABEL_136;
                *(__m128 *)((char *)&v446 + 16 * dimA.m_storage++ + 8) = v468;
                v12 = v450;
              }
              break;
            default:
              goto LABEL_136;
          }
          goto LABEL_2;
        }
        if ( v463 )
        {
          v434 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v435 = v434[1];
          if ( v435 < v434[3] )
          {
            *(_QWORD *)v435 = "TtPenetration";
            v436 = __rdtsc();
            *(_DWORD *)(v435 + 8) = v436;
            v434[1] = v435 + 16;
          }
          v437 = hkcdGskBase::handlePenetration(
                   (hkcdGskBase *)&v447[16],
                   (hkcdGskBase::ShapeInterface *)&v458,
                   v4,
                   v5,
                   &aTb,
                   &dimA,
                   &dimB,
                   &output,
                   &supportOut);
          v438 = (_QWORD *)v434[1];
          v6 = v437;
          if ( (unsigned __int64)v438 < v434[3] )
          {
            *v438 = "Et";
            v439 = __rdtsc();
            v440 = (signed __int64)(v438 + 2);
            *(_DWORD *)(v440 - 8) = v439;
            v434[1] = v440;
          }
        }
        else
        {
          if ( dimB.m_storage + dimA.m_storage > 4 )
          {
            if ( dimA.m_storage > dimB.m_storage )
              v9 = v15;
            dimA.m_storage = v9;
          }
          v6 = 6;
        }
LABEL_147:
        v441 = dimA.m_storage;
        v442 = v450.m128_i8[12];
        v443 = v451.m128_i8[12];
        *((_BYTE *)&v459 + ((LOBYTE(dimA.m_storage) - 2) & 3)) = v452.m128_i8[12];
        *((_BYTE *)&v459 + v441) = v442;
        *((_BYTE *)&v459 + v441 + 1) = v443;
        if ( v6 > 4 )
          result = FLOAT_N3_40282e38;
        else
          result = output.m_distance.m_real.m128_f32[0];
        return result;
      case 0x18u:
        v287 = g_vectorfConstants[0];
        v288 = v12;
        v289 = (__m128 *)((char *)&v446 + 8);
LABEL_74:
        v290 = v289[1];
        v291 = v289[2];
        v292 = _mm_sub_ps(v289[1], *v289);
        v293 = _mm_sub_ps(*v289, v291);
        v294 = _mm_sub_ps(v289[3], *v289);
        v295 = _mm_sub_ps(v289[2], v290);
        v296 = _mm_sub_ps(v289[3], v290);
        v297 = _mm_sub_ps(v289[3], v291);
        v298 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v296, v296, 201), v295),
                 _mm_mul_ps(_mm_shuffle_ps(v295, v295, 201), v296));
        v299 = _mm_mul_ps(_mm_sub_ps(v288, v289[3]), v287);
        v300 = _mm_shuffle_ps(v298, v298, 201);
        v301 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v297, v297, 201), v293),
                 _mm_mul_ps(_mm_shuffle_ps(v293, v293, 201), v297));
        v302 = _mm_shuffle_ps(v301, v301, 201);
        v303 = _mm_mul_ps(v299, v302);
        v304 = _mm_mul_ps(v302, v302);
        v305 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v294, v294, 201), v292),
                 _mm_mul_ps(_mm_shuffle_ps(v292, v292, 201), v294));
        v306 = _mm_mul_ps(v299, v300);
        v307 = _mm_mul_ps(v300, v300);
        v308 = _mm_shuffle_ps(v305, v305, 201);
        v309 = _mm_unpacklo_ps(v306, v303);
        v310 = _mm_mul_ps(v299, v308);
        v311 = _mm_movelh_ps(v309, v310);
        v312 = _mm_mul_ps(v308, v308);
        v313 = (__m128i)_mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v306, v303), v310, 228),
                          _mm_add_ps(v311, _mm_shuffle_ps(_mm_movehl_ps(v311, v309), v310, 212)));
        v314 = _mm_unpacklo_ps(v307, v304);
        v315 = _mm_movelh_ps(v314, v312);
        v316 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v307, v304), v312, 228),
                 _mm_add_ps(v315, _mm_shuffle_ps(_mm_movehl_ps(v315, v314), v312, 212)));
        v317 = _mm_cmpeqps(v7, v316);
        v318 = _mm_rcp_ps(v316);
        v485 = v316;
        v487 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v318, v316)), v318);
        v456 = 897988542;
        v319 = _mm_or_ps(
                 _mm_andnot_ps(
                   v317,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v313, 1u), 1u), (__m128)v313), v487)),
                 _mm_and_ps(v317, (__m128)xmmword_141A712A0));
        v320 = _mm_max_ps(
                 _mm_shuffle_ps(v319, v319, 170),
                 _mm_max_ps(_mm_shuffle_ps(v319, v319, 85), _mm_shuffle_ps(v319, v319, 0)));
        v489 = _mm_and_ps(_mm_cmpleps(v320, v319), (__m128)xmmword_141A79E80);
        v321 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v489)];
        if ( v320.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0)) )
          goto LABEL_58;
        v455 = 1066192077;
        v322 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v321], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v321], v319));
        if ( v320.m128_f32[0] <= (float)(fmax(
                                           COERCE_FLOAT(_mm_shuffle_ps(v322, v322, 170)),
                                           fmax(
                                             COERCE_FLOAT(_mm_shuffle_ps(v322, v322, 85)),
                                             COERCE_FLOAT(_mm_shuffle_ps(v322, v322, 0))))
                                       * COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0))) )
        {
          v323 = 2;
          v324 = 1;
          v325 = 4;
          v326 = 16i64;
          v327 = 32i64;
          v328 = _mm_movemask_ps(_mm_cmpleps(v7, (__m128)v313));
          v329 = 0i64;
          do
          {
            if ( v324 & v328 && v323 & v328 )
            {
              v330 = *(__m128 *)((char *)v289 + v327);
              v331 = _mm_sub_ps(v289[v329], v330);
              v332 = _mm_sub_ps(v289[3], v330);
              v333 = _mm_sub_ps(v288, v330);
              v334 = _mm_mul_ps(v332, v331);
              v335 = _mm_sub_ps(*(__m128 *)((char *)v289 + v326), v330);
              v336 = _mm_mul_ps(v333, v331);
              v337 = _mm_mul_ps(v332, v335);
              v338 = _mm_mul_ps(v333, v335);
              if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 170)))
                         * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v337, v337, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v337, v337, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v337, v337, 170)))) >= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v334, v334, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v334, v334, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v334, v334, 170)))
                                                                                            * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v338, v338, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v338, v338, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v338, v338, 170)))) )
                v323 = v324;
              v328 &= ~v323;
            }
            v323 = v325;
            v326 = v327;
            v325 = v324;
            v324 = __ROL4__(v324, 1);
            v327 = v329 * 16;
            ++v329;
            --v15;
          }
          while ( v15 );
          if ( v328 & 7 )
            v321 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v328];
          else
            v321 = -1;
          LODWORD(v15) = 3;
        }
        if ( v321 < 0 )
          goto LABEL_58;
        v289[v321] = v289[3];
        v12 = v450;
        v14 = *(__m128 *)((char *)&v446 + 8);
        if ( dimA.m_storage == 4 )
        {
          v17 = *(__m128 *)&v447[8];
          dimA.m_storage = v15;
LABEL_90:
          v339 = (__int128)v448;
          v340 = _mm_sub_ps(v12, v17);
          v341 = _mm_sub_ps(v14, v448);
          v342 = _mm_sub_ps(v12, v448);
          v343 = _mm_sub_ps(v448, v17);
          v344 = _mm_sub_ps(v12, v14);
          v345 = _mm_shuffle_ps(v341, v341, 201);
          v346 = _mm_shuffle_ps(v343, v343, 201);
          v347 = _mm_sub_ps(v17, v14);
          v348 = _mm_sub_ps(_mm_mul_ps(v345, v343), _mm_mul_ps(v346, v341));
          v349 = _mm_shuffle_ps(v348, v348, 201);
          v446 = v349;
          v350 = _mm_sub_ps(_mm_mul_ps(v346, v340), _mm_mul_ps(_mm_shuffle_ps(v340, v340, 201), v343));
          v351 = _mm_sub_ps(_mm_mul_ps(v345, v342), _mm_mul_ps(_mm_shuffle_ps(v342, v342, 201), v341));
          v352 = _mm_mul_ps(_mm_shuffle_ps(v350, v350, 201), v349);
          v353 = _mm_mul_ps(_mm_shuffle_ps(v351, v351, 201), v349);
          v354 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v347, v347, 201), v344),
                   _mm_mul_ps(_mm_shuffle_ps(v344, v344, 201), v347));
          v355 = _mm_unpacklo_ps(v352, v353);
          v356 = _mm_mul_ps(_mm_shuffle_ps(v354, v354, 201), v349);
          v357 = _mm_movelh_ps(v355, v356);
          v358 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v352, v353), v356, 228),
                   _mm_add_ps(v357, _mm_shuffle_ps(_mm_movehl_ps(v357, v355), v356, 212)));
          v359 = _mm_movemask_ps(_mm_cmpltps(v358, v7)) & 7;
          if ( v359 == 7 )
          {
            v360 = _mm_mul_ps(_mm_sub_ps(v14, v12), v349);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v360, v360, 85), _mm_shuffle_ps(v360, v360, 0)),
                     _mm_shuffle_ps(v360, v360, 170))) )
            {
              *(__m128 *)((char *)&v446 + 8) = v17;
              v361 = v14;
              v14 = v17;
              *(__m128 *)&v447[8] = v361;
              v446 = _mm_xor_ps(v349, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v358 = _mm_shuffle_ps(v358, v358, 225);
            }
          }
          *(__m128 *)&v447[16] = v358;
          if ( v359 == 7 )
            goto LABEL_129;
          v362 = hkcdGskBase::maskToIndex[v359];
          if ( (signed int)v362 >= 0 )
          {
            v402 = *(char *)(v362 + 5398197060i64);
            v403 = v362;
            v404 = *(char *)(v362 + 5398197062i64);
            v405 = *(__m128 *)((char *)&v446 + 16 * v403 + 8);
            v406 = _mm_sub_ps(v12, v405);
            v407 = _mm_sub_ps(*(__m128 *)((char *)&v446 + 16 * v404 + 8), v405);
            v408 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v446 + 16 * v402 + 8), v405), v406);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v408, v408, 85), _mm_shuffle_ps(v408, v408, 0)),
                     _mm_shuffle_ps(v408, v408, 170))) )
            {
              v409 = _mm_mul_ps(v407, v406);
              *(__m128 *)((char *)&v446 + 16 * v402 + 8) = (__m128)v339;
              if ( _mm_movemask_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v409, v409, 85), _mm_shuffle_ps(v409, v409, 0)),
                       _mm_shuffle_ps(v409, v409, 170))) )
              {
                dimA.m_storage = 1;
                if ( (_DWORD)v404 == 2 )
                  LODWORD(v404) = v402;
                *(__m128 *)((char *)&v446 + 16 * (signed int)v404 + 8) = *(__m128 *)&v447[8];
                v14 = *(__m128 *)((char *)&v446 + 8);
                v12 = v450;
                v282 = _mm_sub_ps(*(__m128 *)((char *)&v446 + 8), v450);
                goto LABEL_128;
              }
            }
            else
            {
              *(__m128 *)((char *)&v446 + 16 * v404 + 8) = (__m128)v339;
            }
LABEL_114:
            v12 = v450;
            v17 = *(__m128 *)&v447[8];
            v14 = *(__m128 *)((char *)&v446 + 8);
            goto LABEL_115;
          }
          v363 = v362 + 8;
          if ( v363 < 3 )
          {
            *(__m128 *)((char *)&v446 + 16 * v363 + 8) = (__m128)v339;
            goto LABEL_114;
          }
LABEL_124:
          dimA.m_storage = 1;
          dimB.m_storage = 1;
LABEL_125:
          v282 = _mm_sub_ps(v14, v12);
          goto LABEL_128;
        }
        dimB.m_storage = v15;
LABEL_98:
        v364 = _mm_sub_ps(v12, v452);
        v365 = _mm_shuffle_ps(v364, v364, 201);
        v366 = _mm_sub_ps(v14, v451);
        v367 = _mm_sub_ps(v452, v451);
        v368 = _mm_sub_ps(v14, v452);
        v369 = _mm_shuffle_ps(v367, v367, 201);
        v370 = _mm_sub_ps(v451, v12);
        v371 = _mm_sub_ps(v14, v12);
        v372 = _mm_sub_ps(_mm_mul_ps(v365, v367), _mm_mul_ps(v369, v364));
        v373 = _mm_shuffle_ps(v372, v372, 201);
        v446 = v373;
        v374 = _mm_sub_ps(_mm_mul_ps(v369, v366), _mm_mul_ps(_mm_shuffle_ps(v366, v366, 201), v367));
        v375 = _mm_sub_ps(_mm_mul_ps(v365, v368), _mm_mul_ps(_mm_shuffle_ps(v368, v368, 201), v364));
        v376 = _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v373);
        v377 = _mm_mul_ps(_mm_shuffle_ps(v375, v375, 201), v373);
        v378 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v370, v370, 201), v371),
                 _mm_mul_ps(_mm_shuffle_ps(v371, v371, 201), v370));
        v379 = _mm_unpacklo_ps(v376, v377);
        v380 = _mm_mul_ps(_mm_shuffle_ps(v378, v378, 201), v373);
        v381 = _mm_movelh_ps(v379, v380);
        v382 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v376, v377), v380, 228),
                 _mm_add_ps(v381, _mm_shuffle_ps(_mm_movehl_ps(v381, v379), v380, 212)));
        v383 = _mm_movemask_ps(_mm_cmpltps(v382, v7)) & 7;
        if ( v383 == 7 )
        {
          v384 = _mm_mul_ps(v373, v371);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v384, v384, 85), _mm_shuffle_ps(v384, v384, 0)),
                   _mm_shuffle_ps(v384, v384, 170))) )
          {
            v450 = v451;
            v385 = v12;
            v12 = v451;
            v451 = v385;
            v446 = _mm_xor_ps(v373, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
            v382 = _mm_shuffle_ps(v382, v382, 225);
          }
        }
        *(__m128 *)&v447[16] = v382;
        if ( v383 == 7 )
          goto LABEL_129;
        v386 = hkcdGskBase::maskToIndex[v383];
        if ( (signed int)v386 >= 0 )
        {
          v424 = *(char *)(v386 + 5398197060i64);
          v425 = v386;
          v426 = hkcdGskBase::vertexToEdgeLut[v386 + 2];
          v427 = *(&v450 + v425);
          v428 = _mm_sub_ps(v14, v427);
          v429 = _mm_sub_ps(*(&v450 + v426), v427);
          v430 = _mm_mul_ps(_mm_sub_ps(*(&v450 + v424), v427), v428);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v430, v430, 85), _mm_shuffle_ps(v430, v430, 0)),
                   _mm_shuffle_ps(v430, v430, 170))) )
          {
            v431 = _mm_mul_ps(v429, v428);
            *(&v450 + v424) = v452;
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v431, v431, 85), _mm_shuffle_ps(v431, v431, 0)),
                     _mm_shuffle_ps(v431, v431, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v426 == 2 )
                LODWORD(v426) = v424;
              *(&v450 + (signed int)v426) = v451;
              v14 = *(__m128 *)((char *)&v446 + 8);
              v12 = v450;
              v282 = _mm_sub_ps(*(__m128 *)((char *)&v446 + 8), v450);
              goto LABEL_128;
            }
          }
          else
          {
            *(&v450 + v426) = v452;
          }
        }
        else
        {
          v387 = v386 + 8;
          if ( v387 >= 3 )
            goto LABEL_124;
          *(&v450 + v387) = v452;
        }
        v12 = v450;
        v14 = *(__m128 *)((char *)&v446 + 8);
        goto LABEL_106;
      default:
        goto LABEL_58;
    }
  }
} + 8);
        goto LABEL_106;
      default:
        goto LABEL_58;
    }
  }
}

// File Line: 441
// RVA: 0xCD8890
bool __usercall IConvexOverlapImpl::checkOverlap@<al>(IConvexOverlapImpl *this@<rcx>, hkgpMesh::IConvexOverlap::IConvexShape *shapeA@<rdx>, hkgpMesh::IConvexOverlap::IConvexShape *shapeB@<r8>, float minDist@<xmm3>, _BOOL8 a5@<r9>, float a6@<xmm0>)
{
  LOBYTE(a5) = 1;
  this->vfptr->distance((hkgpMesh::IConvexOverlap *)this, shapeA, shapeB, a5);
  return minDist >= a6;
}

// File Line: 446
// RVA: 0x15C95E0
__int64 dynamic_initializer_for__gIConvexOverlapImpl__()
{
  return atexit(dynamic_atexit_destructor_for__gIConvexOverlapImpl__);
}

// File Line: 450
// RVA: 0xCC5BD0
__int64 __fastcall hkgpMesh::Location::Region::hasCommonSuperset(hkgpMesh::Location::Region *const *regions, int numRegions)
{
  hkgpMesh::Location::Region *const *v2; // r15
  __int64 v3; // r14
  hkLifoAllocator *v4; // rax
  char *v5; // rdi
  unsigned __int64 v6; // rdx
  int v7; // er8
  hkgpMesh::Location::Region *const *v8; // rbx
  __int64 v9; // rsi
  int v10; // edx
  int v11; // edx
  int v12; // edx
  hkgpMeshBase::Triangle *v13; // rdx
  unsigned __int64 v14; // r9
  unsigned int v15; // edx
  unsigned __int64 v16; // r9
  hkgpMeshBase::Triangle *v17; // rdx
  unsigned __int64 v18; // rdi
  __int64 v19; // r11
  int v20; // edx
  signed __int64 v21; // rax
  unsigned int v22; // esi
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // er8
  hkgpMeshBase::Edge v27; // [rsp+20h] [rbp-50h]
  __m128i v28; // [rsp+30h] [rbp-40h]
  char *array; // [rsp+40h] [rbp-30h]
  int v30; // [rsp+48h] [rbp-28h]
  int v31; // [rsp+4Ch] [rbp-24h]
  char *v32; // [rsp+50h] [rbp-20h]
  int v33; // [rsp+58h] [rbp-18h]

  v2 = regions;
  v3 = numRegions;
  v31 = 2147483648;
  v33 = 64;
  array = 0i64;
  v30 = 0;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (char *)v4->m_cur;
  v6 = (unsigned __int64)(v5 + 512);
  if ( v4->m_slabSize < 512 || (void *)v6 > v4->m_end )
    v5 = (char *)hkLifoAllocator::allocateFromNewSlab(v4, 512);
  else
    v4->m_cur = (void *)v6;
  v7 = v30;
  array = v5;
  v31 = -2147483584;
  v32 = v5;
  if ( (signed int)v3 > 0 )
  {
    v8 = v2;
    v9 = (unsigned int)v3;
    while ( 1 )
    {
      v10 = **(_DWORD **)v8;
      v27 = (*v8)->m_feature;
      v11 = v10 - 1;
      if ( v11 )
      {
        v12 = v11 - 1;
        if ( v12 )
        {
          if ( v12 == 1 )
          {
            do
            {
              if ( v7 == (v31 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
                v7 = v30;
              }
              v13 = v27.m_triangle;
              *(_QWORD *)&array[8 * v7] = v27.m_triangle;
              v7 = v30++ + 1;
              v14 = v13->m_links[(18 >> 2 * LOBYTE(v27.m_index)) & 3];
              v15 = v14 & 3;
              v16 = v14 & 0xFFFFFFFFFFFFFFFCui64;
              v28.m128i_i64[0] = v16;
              v28.m128i_i32[2] = v15;
              _mm_store_si128((__m128i *)&v27, v28);
            }
            while ( v16
                 && (hkgpMeshBase::Triangle *)(v16 + v15) != (hkgpMeshBase::Triangle *)((char *)(*v8)->m_feature.m_triangle
                                                                                      + (*v8)->m_feature.m_index) );
          }
          goto LABEL_25;
        }
        if ( v7 == (v31 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v7 = v30;
        }
        v17 = v27.m_triangle;
        *(_QWORD *)&array[8 * v7] = v27.m_triangle;
        v7 = v30++ + 1;
        v18 = v17->m_links[v27.m_index] & 0xFFFFFFFFFFFFFFFCui64;
        if ( !v18 )
          goto LABEL_25;
        if ( v7 == (v31 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v7 = v30;
        }
        *(_QWORD *)&array[8 * v7] = v18;
      }
      else
      {
        if ( v7 == (v31 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v7 = v30;
        }
        *(_QWORD *)&array[8 * v7] = v27.m_triangle;
      }
      v7 = v30++ + 1;
LABEL_25:
      ++v8;
      if ( !--v9 )
      {
        v5 = v32;
        break;
      }
    }
  }
  v19 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_34:
    v22 = 1;
  }
  else
  {
    while ( 1 )
    {
      v20 = 0;
      v21 = 0i64;
      if ( v7 <= 0 )
        break;
      while ( *(hkgpMeshBase::Triangle **)&array[8 * v21] != v2[v19]->m_feature.m_triangle )
      {
        ++v21;
        ++v20;
        if ( v21 >= v7 )
          goto LABEL_31;
      }
      if ( v20 == -1 )
        break;
      if ( ++v19 >= v3 )
        goto LABEL_34;
    }
LABEL_31:
    v22 = 0;
  }
  if ( v5 == array )
    v7 = 0;
  v23 = (8 * v33 + 127) & 0xFFFFFF80;
  v30 = v7;
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (v23 + 15) & 0xFFFFFFF0;
  if ( v23 > v24->m_slabSize || &v5[v25] != v24->m_cur || v24->m_firstNonLifoEnd == v5 )
    hkLifoAllocator::slowBlockFree(v24, v5, v25);
  else
    v24->m_cur = v5;
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v31);
  return v22;
}

// File Line: 484
// RVA: 0xCC5F30
void __fastcall hkgpMesh::hkgpMesh(hkgpMesh *this)
{
  hkgpMesh *v1; // rdi
  _QWORD **v2; // rax
  __int64 v3; // rax
  _DWORD *v4; // rbx
  int v5; // er8

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_vertices.m_allocator.m_firstPool = 0i64;
  this->m_vertices.m_used = 0i64;
  this->m_vertices.m_numUsed = 0;
  this->m_triangles.m_allocator.m_firstPool = 0i64;
  this->m_triangles.m_used = 0i64;
  this->m_triangles.m_numUsed = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpMesh::`vftable';
  this->m_randSamples.m_data = 0i64;
  this->m_randSamples.m_size = 0;
  this->m_randSamples.m_capacityAndFlags = 2147483648;
  this->m_planes.m_data = 0i64;
  this->m_planes.m_size = 0;
  this->m_planes.m_capacityAndFlags = 2147483648;
  this->m_planeRoots.m_data = 0i64;
  this->m_planeRoots.m_size = 0;
  this->m_planeRoots.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_convexHull = 0i64;
  this->m_epsMinEdgeSqLength = 1.0e-10;
  this->m_epsMinTwiceTriangleArea = 8.6602538e-11;
  this->m_iconvexoverlap = (hkgpMesh::IConvexOverlap *)&gIConvexOverlapImpl;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = 0i64;
    *(_DWORD *)(v3 + 12) = 2147483648;
    *(_QWORD *)(v3 + 16) = 0i64;
    v5 = *(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 8) = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        v5 << 6);
    *(_QWORD *)v4 = 0i64;
    v4[3] = 2147483648;
    *((_QWORD *)v4 + 2) = 0i64;
    *((_QWORD *)v4 + 4) = 0i64;
    *((_QWORD *)v4 + 3) = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  v1->m_trianglesTree = v4;
  hkgpMesh::reset(v1);
}

// File Line: 495
// RVA: 0xCC6060
void __fastcall hkgpMesh::~hkgpMesh(hkgpMesh *this)
{
  hkgpMesh *v1; // rdi
  void **v2; // rbx
  int v3; // er8
  _QWORD **v4; // rax
  int v5; // er8
  int v6; // er8
  int v7; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpMesh::`vftable';
  hkgpMesh::reset(this);
  v2 = (void **)v1->m_trianglesTree;
  if ( v2 )
  {
    v3 = *((_DWORD *)v2 + 3);
    *((_DWORD *)v2 + 2) = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *v2,
        v3 << 6);
    *v2 = 0i64;
    *((_DWORD *)v2 + 3) = 2147483648;
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void **, signed __int64))(*v4[11] + 16i64))(v4[11], v2, 40i64);
  }
  v5 = v1->m_planeRoots.m_capacityAndFlags;
  v1->m_planeRoots.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_planeRoots.m_data,
      8 * v5);
  v1->m_planeRoots.m_data = 0i64;
  v1->m_planeRoots.m_capacityAndFlags = 2147483648;
  v6 = v1->m_planes.m_capacityAndFlags;
  v1->m_planes.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_planes.m_data,
      16 * v6);
  v1->m_planes.m_data = 0i64;
  v1->m_planes.m_capacityAndFlags = 2147483648;
  v7 = v1->m_randSamples.m_capacityAndFlags;
  v1->m_randSamples.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_randSamples.m_data,
      16 * v7);
  v1->m_randSamples.m_data = 0i64;
  v1->m_randSamples.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::`vftable';
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset(&v1->m_triangles);
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpConvexHullImpl::Triangle,32,hkContainerHeapAllocator>(&v1->m_triangles.m_allocator);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset(&v1->m_vertices);
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>(&v1->m_vertices.m_allocator);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 502
// RVA: 0xCC61E0
void __fastcall hkgpMesh::reset(hkgpMesh *this)
{
  hkgpMesh *v1; // rdi
  _DWORD *v2; // rbx
  int v3; // er8

  v1 = this;
  hkgpMesh::invalidateConvexHull(this);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset(&v1->m_vertices);
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::reset(&v1->m_triangles);
  v2 = v1->m_trianglesTree;
  v3 = v2[3];
  v2[2] = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v2,
      v3 << 6);
  *(_QWORD *)v2 = 0i64;
  v2[3] = 2147483648;
  *((_QWORD *)v2 + 2) = 0i64;
  *((_QWORD *)v2 + 4) = 0i64;
  *((_QWORD *)v2 + 3) = 0i64;
  *(_WORD *)&v1->m_hasErrors = 0;
}

// File Line: 514
// RVA: 0xCC6270
char __fastcall hkgpMesh::isClosedManifold(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // rdx
  signed int v2; // eax

  v1 = this->m_triangles.m_used;
  if ( v1 )
  {
    while ( 2 )
    {
      v2 = 0;
      do
      {
        if ( !(v1->m_links[v2] & 0xFFFFFFFFFFFFFFFCui64) )
          return 0;
        ++v2;
      }
      while ( v2 < 3 );
      v1 = v1->m_next;
      if ( v1 )
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
  hkgpMeshBase::Vertex *v2; // rax
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm0

  v2 = this->m_vertices.m_used;
  v3.m_quad = (__m128)v2->m_position;
  result->m_min = (hkVector4f)v3.m_quad;
  result->m_max = (hkVector4f)v3.m_quad;
  if ( v2 )
  {
    do
    {
      v3.m_quad = _mm_max_ps(v3.m_quad, v2->m_position.m_quad);
      v4.m_quad = _mm_min_ps(result->m_min.m_quad, v2->m_position.m_quad);
      v2 = v2->m_next;
      result->m_min = (hkVector4f)v4.m_quad;
    }
    while ( v2 );
    result->m_max = (hkVector4f)v3.m_quad;
  }
  return result;
}

// File Line: 540
// RVA: 0xCC6300
char __fastcall hkgpMesh::setPlane(hkgpMesh *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *p, bool check)
{
  hkVector4f *v6; // rsi
  hkVector4f *v7; // rbp
  hkVector4f *v8; // rdi
  hkgpMesh *v9; // rbx
  char result; // al
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
  hkVector4f v23; // xmm5
  hkVector4f v24; // xmm3
  __m128 v25; // xmm2

  v6 = c;
  v7 = b;
  v8 = a;
  v9 = this;
  result = 1;
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_epsMinEdgeSqLength),
                                      (__m128)LODWORD(this->m_epsMinEdgeSqLength),
                                      0);
  v12 = _mm_sub_ps(b->m_quad, a->m_quad);
  if ( check )
  {
    v13 = _mm_mul_ps(v12, v12);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(this, a, b);
      result = 0;
    }
  }
  v14 = _mm_sub_ps(v6->m_quad, v8->m_quad);
  if ( check )
  {
    v15 = _mm_mul_ps(v14, v14);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(v9, v8, v6);
      result = 0;
    }
  }
  v16 = _mm_sub_ps(v6->m_quad, v7->m_quad);
  if ( check )
  {
    v17 = _mm_mul_ps(v16, v16);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) <= v11 )
    {
      hkgpMesh::reportBadEdgeLength(v9, v6, v7);
      result = 0;
    }
  }
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v14));
  v19 = _mm_shuffle_ps(v18, v18, 201);
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rsqrt_ps(v21);
  v23.m_quad = _mm_shuffle_ps(
                 v19,
                 _mm_unpackhi_ps(
                   v19,
                   _mm_andnot_ps(
                     _mm_cmpleps(v21, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                         _mm_mul_ps(*(__m128 *)_xmm, v22)),
                       v21))),
                 196);
  *p = (hkVector4f)v23.m_quad;
  if ( check
    && COERCE_FLOAT(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 255)) < COERCE_FLOAT(
                                                                     _mm_shuffle_ps(
                                                                       (__m128)LODWORD(v9->m_epsMinTwiceTriangleArea),
                                                                       (__m128)LODWORD(v9->m_epsMinTwiceTriangleArea),
                                                                       0)) )
  {
    hkgpMesh::reportBadAreaTriangle(v9, v8, v7, v6);
    result = 0;
  }
  v24.m_quad = _mm_mul_ps(p->m_quad, _mm_div_ps(query.m_quad, _mm_shuffle_ps(p->m_quad, p->m_quad, 255)));
  *p = (hkVector4f)v24.m_quad;
  v25 = _mm_mul_ps(v8->m_quad, v24.m_quad);
  p->m_quad = _mm_shuffle_ps(
                v24.m_quad,
                _mm_unpackhi_ps(
                  v24.m_quad,
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
char __fastcall hkgpMesh::setPlane(hkgpMesh *this, hkgpMeshBase::Triangle *t, hkVector4f *p, bool check)
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
char __fastcall hkgpMesh::updatePlane(hkgpMesh *this, hkgpMeshBase::Triangle *triangle)
{
  hkgpMeshBase::Triangle *v2; // rbx
  char result; // al
  hkVector4f p; // [rsp+30h] [rbp-18h]

  v2 = triangle;
  if ( !hkgpMesh::setPlane(
          this,
          &triangle->m_vertices[0]->m_position,
          &triangle->m_vertices[1]->m_position,
          &triangle->m_vertices[2]->m_position,
          &p,
          1) )
    return 0;
  result = 1;
  v2->m_plane = (hkVector4f)p.m_quad;
  return result;
}

// File Line: 581
// RVA: 0xCC65D0
__int64 __fastcall hkgpMesh::fetchPositions(hkgpMesh *this, hkArray<hkVector4f,hkContainerHeapAllocator> *positions)
{
  int v2; // esi
  __int64 v3; // r14
  int v4; // er9
  int v5; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rdi
  hkgpMesh *v7; // rbx
  int v8; // eax
  hkgpMeshBase::Vertex *v9; // rax
  signed __int64 i; // rdx
  _OWORD *v11; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = this->m_vertices.m_numUsed;
  v3 = positions->m_size;
  v4 = v3 + v2;
  v5 = positions->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = positions;
  v7 = this;
  if ( v5 < (signed int)v3 + v2 )
  {
    v8 = 2 * v5;
    if ( v4 < v8 )
      v4 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, positions, v4, 16);
  }
  v6->m_size += v2;
  v9 = v7->m_vertices.m_used;
  for ( i = (signed __int64)&v6->m_data[v3]; v9; v9 = v9->m_next )
  {
    v11 = (_OWORD *)i;
    i += 16i64;
    *v11 = v9->m_position;
  }
  return (unsigned int)v7->m_vertices.m_numUsed;
}

// File Line: 592
// RVA: 0xCC6680
__int64 __fastcall hkgpMesh::floodFillDetachedParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // rax
  unsigned int i; // er14
  hkgpMeshBase::Triangle *v3; // rsi
  int v4; // ecx
  hkgpMeshBase::Triangle **v5; // rdx
  __int64 v6; // rax
  int v7; // ecx
  hkgpMeshBase::Triangle **v8; // rdx
  __int64 v9; // rax
  int v10; // ecx
  hkgpMeshBase::Triangle **v11; // rdx
  __int64 v12; // rax
  int v13; // er8
  __int64 v14; // rcx
  __int64 v15; // rbx
  char v16; // cl
  unsigned __int64 v17; // rbx
  char v18; // di
  int v19; // er8
  unsigned __int64 *v20; // rdx
  __int64 v21; // rax
  int v22; // er8
  unsigned __int64 *v23; // rax
  __int64 v24; // rcx
  _QWORD *array; // [rsp+10h] [rbp-19h]
  int v27; // [rsp+18h] [rbp-11h]
  int j; // [rsp+1Ch] [rbp-Dh]
  __int64 v29; // [rsp+28h] [rbp-1h]
  __int64 v30; // [rsp+38h] [rbp+Fh]
  __int64 v31; // [rsp+48h] [rbp+1Fh]
  __int64 v32; // [rsp+58h] [rbp+2Fh]
  __int64 v33; // [rsp+68h] [rbp+3Fh]

  v1 = this->m_triangles.m_used;
  for ( i = 0; v1; v1 = v1->m_next )
    v1->m_partId = -1;
  v3 = this->m_triangles.m_used;
  array = 0i64;
  v27 = 0;
  for ( j = 2147483648; v3; v3 = v3->m_next )
  {
    if ( v3->m_partId == -1 )
    {
      v4 = 0;
      LODWORD(v29) = 0;
      v27 = 0;
      if ( !(j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v4 = v27;
      }
      v5 = (hkgpMeshBase::Triangle **)&array[2 * v4];
      if ( v5 )
      {
        v6 = v29;
        *v5 = v3;
        v5[1] = (hkgpMeshBase::Triangle *)v6;
        v4 = v27;
      }
      v7 = v4 + 1;
      LODWORD(v30) = 1;
      v27 = v7;
      if ( v7 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v7 = v27;
      }
      v8 = (hkgpMeshBase::Triangle **)&array[2 * v7];
      if ( v8 )
      {
        v9 = v30;
        *v8 = v3;
        v8[1] = (hkgpMeshBase::Triangle *)v9;
        v7 = v27;
      }
      v10 = v7 + 1;
      LODWORD(v31) = 2;
      v27 = v10;
      if ( v10 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v10 = v27;
      }
      v11 = (hkgpMeshBase::Triangle **)&array[2 * v10];
      if ( v11 )
      {
        v12 = v31;
        *v11 = v3;
        v11[1] = (hkgpMeshBase::Triangle *)v12;
        v10 = v27;
      }
      v27 = v10 + 1;
      v3->m_partId = i;
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
          LODWORD(v32) = (9 >> 2 * v16) & 3;
          if ( v27 == (j & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * j);
  return i;
}ainerHeapAlloc

// File Line: 599
// RVA: 0xCC6960
__int64 __fastcall hkgpMesh::floodFillDetachedOrMaterialBoundariesParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // rax
  unsigned int i; // er14
  hkgpMeshBase::Triangle *v3; // rsi
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
  _QWORD *array; // [rsp+10h] [rbp-19h]
  int v30; // [rsp+18h] [rbp-11h]
  int j; // [rsp+1Ch] [rbp-Dh]
  __int64 v32; // [rsp+28h] [rbp-1h]
  __int64 v33; // [rsp+38h] [rbp+Fh]
  __int64 v34; // [rsp+48h] [rbp+1Fh]
  __int64 v35; // [rsp+58h] [rbp+2Fh]
  __int64 v36; // [rsp+68h] [rbp+3Fh]

  v1 = this->m_triangles.m_used;
  for ( i = 0; v1; v1 = v1->m_next )
    v1->m_partId = -1;
  v3 = this->m_triangles.m_used;
  array = 0i64;
  v30 = 0;
  for ( j = 2147483648; v3; v3 = v3->m_next )
  {
    if ( v3->m_partId == -1 )
    {
      v4 = 0;
      LODWORD(v32) = 0;
      v30 = 0;
      if ( !(j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v4 = v30;
      }
      v5 = (hkgpMeshBase::Triangle **)&array[2 * v4];
      if ( v5 )
      {
        v6 = v32;
        *v5 = v3;
        v5[1] = (hkgpMeshBase::Triangle *)v6;
        v4 = v30;
      }
      v7 = v4 + 1;
      LODWORD(v33) = 1;
      v30 = v7;
      if ( v7 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v7 = v30;
      }
      v8 = (hkgpMeshBase::Triangle **)&array[2 * v7];
      if ( v8 )
      {
        v9 = v33;
        *v8 = v3;
        v8[1] = (hkgpMeshBase::Triangle *)v9;
        v7 = v30;
      }
      v10 = v7 + 1;
      LODWORD(v34) = 2;
      v30 = v10;
      if ( v10 == (j & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v10 = v30;
      }
      v11 = (hkgpMeshBase::Triangle **)&array[2 * v10];
      if ( v11 )
      {
        v12 = v34;
        *v11 = v3;
        v11[1] = (hkgpMeshBase::Triangle *)v12;
        v10 = v30;
      }
      v30 = v10 + 1;
      v3->m_partId = i;
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
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * j);
  return i;
}

// File Line: 606
// RVA: 0xCC6C50
__int64 __fastcall hkgpMesh::countParts(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // rdx
  signed int i; // eax

  v1 = this->m_triangles.m_used;
  for ( i = -1; v1; v1 = v1->m_next )
  {
    if ( v1->m_partId > i )
      i = v1->m_partId;
  }
  return (unsigned int)(i + 1);
}

// File Line: 617
// RVA: 0xCC6C80
__int64 __fastcall hkgpMesh::explodeParts(hkgpMesh *this, hkArray<hkgpMesh *,hkContainerHeapAllocator> *sets, bool doSimplify, bool doConvexHulls, bool sort, hkgpMesh::eHollows hollowPolicy)
{
  hkArray<hkgpMesh *,hkContainerHeapAllocator> *v6; // r14
  hkgpMesh *v7; // rsi
  __int64 v8; // rax
  __int64 v9; // r12
  __int64 v10; // rbx
  int v11; // er9
  int v12; // eax
  signed __int64 v13; // rdi
  int v14; // eax
  hkgpMesh **v15; // rax
  hkgpMesh **v16; // r15
  int v17; // er8
  int v18; // er9
  __int64 v19; // rbx
  __int64 v20; // r13
  _QWORD **v21; // rax
  __int64 v22; // rax
  __int64 v23; // rcx
  hkgpMeshBase::Triangle *v24; // r14
  __int64 v25; // rax
  __int64 v26; // rbx
  _QWORD **v27; // rax
  hkgpMesh *v28; // rax
  hkgpMesh *v29; // rax
  hkgpMesh *v30; // rcx
  hkgpMesh *v31; // rcx
  hkcdDynamicTree::CodecRawUlong *v32; // rax
  signed __int64 v33; // r12
  hkcdDynamicTree::CodecRawUlong *v34; // r13
  _QWORD *v35; // rbx
  hkgpMeshBase::Triangle *v36; // rax
  unsigned __int64 v37; // r14
  unsigned __int64 v38; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v39; // r13
  hkgpMeshBase::Vertex *v40; // r15
  hkgpMeshBase::Vertex *v41; // rsi
  hkcdDynamicTree::CodecRawUlong *v42; // r13
  signed int v43; // ebx
  unsigned __int64 *v44; // rsi
  unsigned __int64 v45; // rcx
  unsigned __int64 v46; // r15
  unsigned __int64 v47; // rax
  unsigned int v48; // er9
  unsigned __int64 v49; // rax
  __int64 i; // rbx
  AMD_HD3D *v51; // rsi
  _QWORD **v52; // rax
  __int64 j; // rbx
  __int64 v54; // rsi
  hkgpMesh *v55; // r15
  __int64 v56; // r12
  signed __int64 v57; // rax
  hkgpMesh *v58; // r14
  char v59; // r13
  TrianglePairCollector *v60; // r9
  hkVector4f *k; // rbx
  hkgpMeshBase::Triangle *v62; // rax
  hkVector4f *l; // rbx
  hkgpMeshBase::Triangle *v64; // rax
  hkgpMeshBase::Triangle *v65; // rbx
  __m128 *v66; // rax
  __m128 *v67; // rcx
  __m128 v68; // xmm1
  __m128 *v69; // rax
  hkgpMeshBase::Triangle *v70; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v71; // rdx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v72; // rcx
  int v73; // ebx
  __int64 v74; // rsi
  _QWORD *v75; // rcx
  _QWORD *v76; // rdx
  hkSimdFloat32 *v77; // rbx
  hkgpMesh *v78; // rcx
  __int64 v79; // rcx
  int v80; // [rsp+30h] [rbp-D0h]
  signed __int64 v81; // [rsp+38h] [rbp-C8h]
  _QWORD *array; // [rsp+40h] [rbp-C0h]
  int v83; // [rsp+48h] [rbp-B8h]
  int v84; // [rsp+4Ch] [rbp-B4h]
  hkResult v85[2]; // [rsp+50h] [rbp-B0h]
  __int64 v86; // [rsp+58h] [rbp-A8h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> treeB; // [rsp+60h] [rbp-A0h]
  hkgpMeshBase::Triangle *v88; // [rsp+90h] [rbp-70h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v89; // [rsp+98h] [rbp-68h]
  hkgpMesh::Location location; // [rsp+A0h] [rbp-60h]
  hkSimdFloat32 v91; // [rsp+120h] [rbp+20h]
  hkSimdFloat32 result; // [rsp+130h] [rbp+30h]
  hkVector4f triangleA[3]; // [rsp+140h] [rbp+40h]
  hkVector4f triangleB[3]; // [rsp+170h] [rbp+70h]
  hkgpMesh *v95; // [rsp+200h] [rbp+100h]
  hkArray<hkgpMesh *,hkContainerHeapAllocator> *v96; // [rsp+208h] [rbp+108h]
  bool v97; // [rsp+210h] [rbp+110h]
  bool v98; // [rsp+218h] [rbp+118h]

  v98 = doConvexHulls;
  v97 = doSimplify;
  v96 = sets;
  v95 = this;
  v6 = sets;
  v7 = this;
  v8 = hkgpMesh::countParts(this);
  v9 = (signed int)v8;
  v80 = v8;
  if ( !(_DWORD)v8 )
    return v8;
  v10 = v6->m_size;
  v11 = v10 + v9;
  v12 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  v13 = 0i64;
  if ( v12 >= (signed int)v10 + (signed int)v9 )
  {
    treeB.m_nodes.m_size = 0;
  }
  else
  {
    v14 = 2 * v12;
    if ( v11 < v14 )
      v11 = v14;
    hkArrayUtil::_reserve(
      (hkResult *)&treeB.m_nodes.m_size,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v6,
      v11,
      8);
  }
  v15 = v6->m_data;
  v6->m_size += v9;
  v16 = &v15[v10];
  v17 = 3 * v7->m_triangles.m_numUsed;
  v81 = (signed __int64)&v15[v10];
  array = 0i64;
  v83 = 0;
  v84 = 2147483648;
  treeB.m_firstFree = 0i64;
  treeB.m_numLeaves = 0;
  treeB.m_path = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB.m_firstFree,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v17);
  if ( (signed int)v9 > 0 )
  {
    v18 = v9;
    if ( (signed int)v9 < 0 )
      v18 = 0;
    hkArrayUtil::_reserve(v85, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 8);
  }
  v83 = v9;
  v19 = 0i64;
  v20 = v9;
  v86 = v9;
  if ( (signed int)v9 > 0 )
  {
    do
    {
      v16[v19] = 0i64;
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 16i64);
      v23 = v22;
      if ( v22 )
      {
        *(_QWORD *)v22 = 0i64;
        *(_DWORD *)(v22 + 8) = 0;
        *(_DWORD *)(v22 + 12) = -1;
      }
      else
      {
        v23 = 0i64;
      }
      array[++v19 - 1] = v23;
    }
    while ( v19 < v9 );
  }
  v24 = v7->m_triangles.m_used;
  v88 = v24;
  if ( v24 )
  {
    do
    {
      v25 = v24->m_partId;
      if ( (_DWORD)v25 != -1 )
      {
        v26 = v24->m_partId;
        v91.m_real.m128_u64[0] = v24->m_partId;
        if ( !v16[v25] )
        {
          v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v28 = (hkgpMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v27[11] + 8i64))(v27[11], 152i64);
          if ( v28 )
          {
            hkgpMesh::hkgpMesh(v28);
            v30 = v29;
          }
          else
          {
            v30 = 0i64;
          }
          v16[v26] = v30;
          v30->m_iconvexoverlap = v7->m_iconvexoverlap;
        }
        v31 = v16[v26];
        v89 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)array[v24->m_partId];
        v32 = (hkcdDynamicTree::CodecRawUlong *)hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
                                                  &v31->m_triangles,
                                                  v24);
        v33 = 3i64;
        v34 = v32;
        v35 = v32->m_aabb.m_max.m_quad.m128_u64;
        treeB.m_nodes.m_data = v32;
        v36 = v24;
        v37 = v91.m_real.m128_u64[0];
        v38 = (char *)v36 - (char *)v34;
        v39 = v89;
        result.m_real.m128_u64[0] = v38;
        do
        {
          v40 = *(hkgpMeshBase::Vertex **)((char *)v35 + v38);
          v41 = (hkgpMeshBase::Vertex *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                          v39,
                                          *(_QWORD *)((char *)v35 + v38),
                                          0i64);
          if ( !v41 )
          {
            v41 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(
                    (hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)(*(_QWORD *)(v81 + 8 * v37) + 16i64),
                    v40);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              v39,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (unsigned __int64)v40,
              (unsigned __int64)v41);
          }
          v38 = result.m_real.m128_u64[0];
          *v35 = v41;
          v35[3] = 0i64;
          ++v35;
          --v33;
        }
        while ( v33 );
        v42 = treeB.m_nodes.m_data;
        v24 = v88;
        v43 = 0;
        v44 = treeB.m_nodes.m_data->m_children;
        do
        {
          v45 = v24->m_links[v43] & 0xFFFFFFFFFFFFFFFCui64;
          if ( v45 && *(_DWORD *)(v45 + 80) == v24->m_partId )
          {
            v46 = v45 + (v24->m_links[v43] & 3);
            v47 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB.m_firstFree,
                    v46,
                    0i64);
            v48 = v47 & 3;
            v49 = v47 & 0xFFFFFFFFFFFFFFFCui64;
            if ( v49 )
            {
              v42->m_children[v43] = v49 + v48;
              *(_QWORD *)(v49 + 8i64 * (signed int)v48 + 40) = (char *)v42 + (unsigned int)v43;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB.m_firstFree,
                v85,
                v46);
            }
            else
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB.m_firstFree,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (unsigned __int64)v24 + (unsigned int)v43,
                (unsigned __int64)v42 + (unsigned int)v43);
              *v44 = v46;
            }
          }
          ++v43;
          ++v44;
        }
        while ( v43 < 3 );
        v7 = v95;
        v16 = (hkgpMesh **)v81;
      }
      v24 = v24->m_next;
      v88 = v24;
    }
    while ( v24 );
    v20 = v86;
    LODWORD(v9) = v86;
  }
  for ( i = 0i64; i < v20; ++i )
  {
    v51 = (AMD_HD3D *)array[i];
    if ( v51 )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)array[i],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _(v51);
      v52 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, AMD_HD3D *, signed __int64))(*v52[11] + 16i64))(v52[11], v51, 16i64);
    }
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&treeB.m_firstFree,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&treeB.m_firstFree);
  v83 = 0;
  if ( v84 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v84);
  if ( hollowPolicy == HOLLOW_KEEP )
    goto LABEL_87;
  for ( j = 0i64; j < v20; ++j )
  {
    hkgpMesh::assignVertexNormals(v16[j]);
    hkgpMesh::rebuildTrianglesTree(v16[j], 0.0);
  }
  v54 = 0i64;
  *(_QWORD *)&v85[0].m_enum = 0i64;
  if ( v20 <= 0 )
    goto LABEL_87;
  do
  {
    v55 = v16[v54];
    if ( !hkgpMesh::isClosedManifold(v55) )
      goto LABEL_85;
    v56 = 0i64;
    if ( v20 <= 0 )
    {
LABEL_84:
      LODWORD(v9) = v80;
LABEL_85:
      v16 = (hkgpMesh **)v81;
      goto LABEL_86;
    }
    v57 = v81;
    while ( 1 )
    {
      v58 = *(hkgpMesh **)(v57 + 8 * v56);
      v59 = 1;
      if ( v56 != v54 )
        break;
LABEL_83:
      v20 = v86;
      if ( ++v56 >= v86 )
        goto LABEL_84;
    }
    if ( !hkgpMesh::isClosedManifold(*(hkgpMesh **)(v57 + 8 * v56)) )
      goto LABEL_82;
    for ( k = (hkVector4f *)v55->m_vertices.m_used; k; k = (hkVector4f *)k->m_quad.m128_u64[0] )
    {
      location.m_region.m_type = 0;
      if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v62 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
        v62 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      }
      location.m_region.m_feature.m_triangle = v62;
      location.m_normal = 0i64;
      location.m_pseudoNormal = 0i64;
      location.m_coordinates = 0i64;
      *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                        + 1);
      location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
      location.m_inside.m_real = g_vectorfConstants[0];
      hkgpMesh::locate(v58, k + 2, &location, (hkBool)1);
      if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
        goto LABEL_82;
    }
    for ( l = (hkVector4f *)v58->m_vertices.m_used; l; l = (hkVector4f *)l->m_quad.m128_u64[0] )
    {
      location.m_region.m_type = 0;
      if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v64 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
        v64 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      }
      location.m_region.m_feature.m_triangle = v64;
      location.m_normal = 0i64;
      location.m_pseudoNormal = 0i64;
      location.m_coordinates = 0i64;
      *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                        + 1);
      location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
      location.m_inside.m_real = g_vectorfConstants[0];
      hkgpMesh::locate(v55, l + 2, &location, (hkBool)1);
      if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
        goto LABEL_82;
    }
    v65 = v55->m_triangles.m_used;
    if ( v65 )
    {
      while ( 1 )
      {
        v66 = (__m128 *)v65->m_vertices[1];
        v67 = (__m128 *)v65->m_vertices[0];
        location.m_region.m_type = 0;
        v68 = v66[2];
        v69 = (__m128 *)v65->m_vertices[2];
        *(__m128 *)&treeB.m_firstFree = _mm_add_ps(v68, v67[2]);
        *(__m128 *)&treeB.m_firstFree = _mm_mul_ps(
                                          _mm_add_ps(v69[2], *(__m128 *)&treeB.m_firstFree),
                                          (__m128)xmmword_141A711C0);
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v70 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v70 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
        }
        location.m_region.m_feature.m_triangle = v70;
        location.m_normal = 0i64;
        location.m_pseudoNormal = 0i64;
        location.m_coordinates = 0i64;
        *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                          + 1);
        location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
        location.m_inside.m_real = g_vectorfConstants[0];
        hkgpMesh::locate(v58, (hkVector4f *)&treeB.m_firstFree, &location, (hkBool)1);
        if ( location.m_inside.m_real.m128_f32[0] > 0.0 )
          break;
        v65 = v65->m_next;
        if ( !v65 )
          goto LABEL_70;
      }
LABEL_82:
      v57 = v81;
      goto LABEL_83;
    }
LABEL_70:
    v71 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)v58->m_trianglesTree;
    v72 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v55->m_trianglesTree;
    treeB.m_nodes.m_data = (hkcdDynamicTree::CodecRawUlong *)&array;
    array = 0i64;
    v83 = 0;
    v84 = 2147483648;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,TrianglePairCollector>(
      v72,
      v71,
      &treeB,
      v60);
    v73 = 0;
    if ( v83 > 0 )
    {
      v74 = 0i64;
      while ( 1 )
      {
        v75 = (_QWORD *)array[v74];
        v76 = (_QWORD *)array[v74 + 1];
        _mm_store_si128((__m128i *)triangleA, *(__m128i *)(v75[2] + 32i64));
        _mm_store_si128((__m128i *)&triangleA[1], *(__m128i *)(v75[3] + 32i64));
        _mm_store_si128((__m128i *)&triangleA[2], *(__m128i *)(v75[4] + 32i64));
        _mm_store_si128((__m128i *)triangleB, *(__m128i *)(v76[2] + 32i64));
        _mm_store_si128((__m128i *)&triangleB[1], *(__m128i *)(v76[3] + 32i64));
        _mm_store_si128((__m128i *)&triangleB[2], *(__m128i *)(v76[4] + 32i64));
        if ( hkcdIntersectTriangleTriangle((hkVector4f (*)[3])triangleA, (hkVector4f (*)[3])triangleB) )
          break;
        ++v73;
        v74 += 2i64;
        if ( v73 >= v83 )
          goto LABEL_76;
      }
      v59 = 0;
LABEL_76:
      v54 = *(_QWORD *)&v85[0].m_enum;
    }
    v83 = 0;
    if ( v84 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v84);
    array = 0i64;
    v84 = 2147483648;
    if ( !v59 )
      goto LABEL_82;
    if ( hollowPolicy == 2 )
    {
      hkgpMesh::rebuildConvexHull(v58);
      hkgpMesh::rebuildConvexHull(v55);
      v77 = hkgpMesh::getConvexHullVolume(v58, &result);
      if ( COERCE_FLOAT(*hkgpMesh::getConvexHullVolume(v55, &v91)) <= v77->m_real.m128_f32[0] )
        goto LABEL_99;
      goto LABEL_82;
    }
    if ( hollowPolicy == 1 )
    {
      hkgpMesh::append(v58, v55);
      hkgpMesh::assignVertexNormals(v58);
      hkgpMesh::rebuildTrianglesTree(v58, 0.0);
    }
LABEL_99:
    v55->vfptr->__vecDelDtor((hkBaseObject *)&v55->vfptr, 1u);
    v16 = (hkgpMesh **)v81;
    v79 = *(_QWORD *)(v81 + 8 * v54);
    v20 = v86 - 1;
    *(_QWORD *)(v81 + 8 * v54) = *(_QWORD *)(v81 + 8 * v86 - 8);
    *(_QWORD *)(v81 + 8 * v20) = v79;
    LODWORD(v9) = v80 - 1;
    LODWORD(v79) = v96->m_size - 1;
    --v80;
    v86 = v20;
    v96->m_size = v79;
    v54 = 0i64;
LABEL_86:
    *(_QWORD *)&v85[0].m_enum = ++v54;
  }
  while ( v54 < v20 );
LABEL_87:
  if ( sort && (signed int)v9 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpMesh *,hkgpMeshInternals::CompareSetSize>(v16, 0, v9 - 1, 0);
  if ( (signed int)v9 > 0 )
  {
    do
    {
      if ( v97 )
      {
        v78 = v16[v13];
        v85[0].m_enum = 953267991;
        *(__m128 *)&treeB.m_firstFree = _mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0);
        *(__m128 *)&treeB.m_root = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
        hkgpMesh::simplify(v78, (hkgpMesh::SimplifyConfig *)&treeB.m_firstFree);
      }
      if ( v98 )
        hkgpMesh::rebuildConvexHull(v16[v13]);
      ++v13;
    }
    while ( v13 < (signed int)v9 );
  }
  return (unsigned int)v9;
}

// File Line: 818
// RVA: 0xCC7650
void __fastcall hkgpMesh::updatePlaneEquations(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // rbx
  hkgpMesh *i; // rdi

  v1 = this->m_triangles.m_used;
  for ( i = this; v1; v1 = v1->m_next )
  {
    v1->m_plane = 0i64;
    hkgpMesh::updatePlane(i, v1);
  }
}

// File Line: 828
// RVA: 0xCC76A0
void __fastcall hkgpMesh::collapseEdge(hkgpMesh *this, hkgpMeshBase::Edge *edge, bool updatePlanes)
{
  __int64 v3; // r13
  bool v4; // si
  signed int v5; // er8
  hkgpMesh *v6; // r15
  hkgpMeshBase::Vertex *v7; // r14
  char v8; // di
  hkgpMeshBase::Triangle *v9; // rbx
  signed __int64 v10; // rax
  unsigned __int64 v11; // rdx
  __int64 v12; // rdx
  char v13; // cl
  __int64 v14; // rdi
  hkgpMeshBase::Triangle *v15; // rbx
  __int64 v16; // rdx
  char v17; // cl
  hkgpMeshBase::Edge *v18; // rsi
  unsigned int v19; // ebx
  __int64 v20; // rcx
  signed __int64 v21; // r10
  hkgpMeshBase::Triangle *v22; // rdx
  int v23; // er13
  hkgpMeshBase::Triangle *v24; // r8
  signed __int64 v25; // r11
  signed __int64 v26; // r14
  unsigned __int64 v27; // r9
  __m128i v28; // xmm1
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // r8
  __int64 v32; // rax
  signed __int64 v33; // r8
  hkgpMeshBase::Triangle *v34; // rdx
  hkgpMeshBase::Triangle *v35; // r8
  int v36; // eax
  signed __int64 v37; // r10
  unsigned __int64 v38; // r9
  signed __int64 v39; // rdx
  unsigned __int64 v40; // r9
  __m128i v41; // xmm1
  __int64 v42; // rdx
  unsigned int v43; // er8
  hkgpMeshBase::Triangle *v44; // r9
  int v45; // er12
  __int64 v46; // rdx
  hkgpMeshBase::Triangle *v47; // r8
  int v48; // edi
  hkgpMeshBase::Triangle *triangle[2]; // [rsp+20h] [rbp-20h]
  __m128i v50; // [rsp+30h] [rbp-10h]
  hkgpMeshBase::Triangle **v51; // [rsp+80h] [rbp+40h]
  hkgpMeshBase::Edge *v52; // [rsp+88h] [rbp+48h]
  hkgpMeshBase::Triangle **v53; // [rsp+88h] [rbp+48h]
  signed int v54; // [rsp+90h] [rbp+50h]
  int v55; // [rsp+90h] [rbp+50h]

  v52 = edge;
  v4 = updatePlanes;
  v5 = edge->m_index;
  v6 = this;
  v50.m128i_i64[0] = (__int64)edge->m_triangle;
  v3 = v50.m128i_i64[0];
  v50.m128i_i32[2] = v5;
  v54 = v5;
  _mm_store_si128((__m128i *)triangle, v50);
  v7 = *(hkgpMeshBase::Vertex **)(v3 + 8 * ((9i64 >> 2 * (unsigned __int8)v5) & 3) + 16);
  while ( 1 )
  {
    v8 = (char)triangle[1];
    v9 = triangle[0];
    triangle[0]->m_vertices[SLODWORD(triangle[1])] = v7;
    if ( v4 )
    {
      hkgpMesh::updatePlane(v6, v9);
      v5 = v54;
    }
    v10 = v9->m_links[(18 >> 2 * v8) & 3] & 3;
    v11 = v9->m_links[(18 >> 2 * v8) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v50.m128i_i64[0] = v9->m_links[(18 >> 2 * v8) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v50.m128i_i32[2] = v10;
    _mm_store_si128((__m128i *)triangle, v50);
    if ( !v11 )
      break;
    if ( v11 + v10 == v3 + (unsigned int)v5 )
      goto LABEL_11;
  }
  v13 = *(_QWORD *)(v3 + 8i64 * v5 + 40) & 3;
  v50.m128i_i64[0] = *(_QWORD *)(v3 + 8i64 * v5 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v12 = v50.m128i_i64[0];
  v50.m128i_i32[2] = (9 >> 2 * v13) & 3;
  _mm_store_si128((__m128i *)triangle, v50);
  if ( v12 )
  {
    do
    {
      v14 = SLODWORD(triangle[1]);
      v15 = triangle[0];
      triangle[0]->m_vertices[SLODWORD(triangle[1])] = v7;
      if ( v4 )
        hkgpMesh::updatePlane(v6, v15);
      v17 = v15->m_links[v14] & 3;
      v50.m128i_i64[0] = v15->m_links[v14] & 0xFFFFFFFFFFFFFFFCui64;
      v16 = v50.m128i_i64[0];
      v50.m128i_i32[2] = (9 >> 2 * v17) & 3;
      _mm_store_si128((__m128i *)triangle, v50);
    }
    while ( v16 );
  }
LABEL_11:
  v18 = v52;
  v19 = 0;
  v20 = (signed int)v52->m_index;
  v21 = v52->m_triangle->m_links[v20] & 3;
  v22 = (hkgpMeshBase::Triangle *)(v52->m_triangle->m_links[v20] & 0xFFFFFFFFFFFFFFFCui64);
  if ( v22 )
  {
    v23 = (9 >> 2 * v21) & 3;
    v53 = &v22->m_next + v23 + 5i64;
    v24 = (hkgpMeshBase::Triangle *)((unsigned __int64)*v53 & 0xFFFFFFFFFFFFFFFCui64);
    v25 = (unsigned __int64)*v53 & 3;
    triangle[0] = (hkgpMeshBase::Triangle *)((unsigned __int64)*v53 & 0xFFFFFFFFFFFFFFFCui64);
    v55 = (18 >> 2 * v21) & 3;
    LODWORD(triangle[1]) = v25;
    v51 = &v22->m_next + v55 + 5i64;
    v26 = (unsigned __int64)*v51 & 3;
    v27 = (unsigned __int64)*v51 & 0xFFFFFFFFFFFFFFFCui64;
    v50.m128i_i64[0] = (unsigned __int64)*v51 & 0xFFFFFFFFFFFFFFFCui64;
    v50.m128i_i32[2] = v26;
    if ( v27 )
    {
      v28 = *(__m128i *)triangle;
      _mm_store_si128((__m128i *)triangle, v50);
      _mm_store_si128(&v50, v28);
      LODWORD(v25) = triangle[1];
      v24 = triangle[0];
      LODWORD(v26) = v50.m128i_i32[2];
      v27 = v50.m128i_i64[0];
    }
    if ( v24 )
    {
      v24->m_links[(signed int)v25] = v27 + (unsigned int)v26;
      if ( v27 )
        *(_QWORD *)(v27 + 8i64 * (signed int)v26 + 40) = (char *)v24 + (unsigned int)v25;
      if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v30 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        v29 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      }
      else
      {
        v29 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
        v30 = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
      }
      *v53 = (hkgpMeshBase::Triangle *)(v29 + v30);
      v31 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
      {
        *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                  + 8i64
                  * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                  + 40) = (char *)v22 + (unsigned int)v23;
        v31 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      }
      if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v32 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
      }
      else
      {
        v31 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
        v32 = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
      }
      *v51 = (hkgpMeshBase::Triangle *)(v31 + v32);
      if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
        *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                  + 8i64
                  * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                  + 40) = (char *)v22 + (unsigned int)v55;
    }
    v33 = (signed __int64)v22 + 8 * (signed int)v21;
    if ( *(_QWORD *)(v33 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
      *(_QWORD *)((*(_QWORD *)(v33 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v33 + 40) & 3i64) + 40) = 0i64;
    *(_QWORD *)(v33 + 40) = 0i64;
    hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::release(
      &v6->m_triangles,
      v22);
  }
  v34 = v18->m_triangle;
  v35 = (hkgpMeshBase::Triangle *)(v18->m_triangle->m_links[(9 >> 2 * LOBYTE(v18->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64);
  v36 = (18 >> 2 * LOBYTE(v18->m_index)) & 3;
  v37 = v18->m_triangle->m_links[(9 >> 2 * LOBYTE(v18->m_index)) & 3] & 3;
  triangle[0] = (hkgpMeshBase::Triangle *)(v18->m_triangle->m_links[(9 >> 2 * LOBYTE(v18->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64);
  LODWORD(triangle[1]) = v37;
  v38 = v34->m_links[v36];
  v39 = v34->m_links[v36] & 3;
  v40 = v38 & 0xFFFFFFFFFFFFFFFCui64;
  v50.m128i_i64[0] = v40;
  v50.m128i_i32[2] = v39;
  if ( v40 )
  {
    v41 = *(__m128i *)triangle;
    _mm_store_si128((__m128i *)triangle, v50);
    _mm_store_si128(&v50, v41);
    LODWORD(v39) = v50.m128i_i32[2];
    v40 = v50.m128i_i64[0];
    LODWORD(v37) = triangle[1];
    v35 = triangle[0];
  }
  if ( v35 )
  {
    v35->m_links[(signed int)v37] = v40 + (unsigned int)v39;
    if ( v40 )
      *(_QWORD *)(v40 + 8i64 * (signed int)v39 + 40) = (char *)v35 + (unsigned int)v37;
    if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v43 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
      v42 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    }
    else
    {
      v42 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      v43 = 0;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
    }
    v44 = v18->m_triangle;
    v45 = (9 >> 2 * v18->m_index) & 3;
    v18->m_triangle->m_links[v45] = v42 + v43;
    v46 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
    {
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                + 40) = (char *)v44 + (unsigned int)v45;
      v46 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    }
    if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v19 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
    }
    else
    {
      v46 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
    }
    v47 = v18->m_triangle;
    v48 = (18 >> 2 * v18->m_index) & 3;
    v18->m_triangle->m_links[v48] = v46 + v19;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                + 40) = (char *)v47 + (unsigned int)v48;
  }
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::release(
    &v6->m_triangles,
    v18->m_triangle);
}

// File Line: 848
// RVA: 0xCC7B50
hkgpMeshBase::Edge *__fastcall hkgpMesh::splitEdge(hkgpMesh *this, hkgpMeshBase::Edge *result, hkgpMeshBase::Edge *edge, hkgpMeshBase::Vertex *vertex, bool updatePlanes)
{
  hkgpMeshBase::Edge *v5; // r12
  hkgpMeshBase::Triangle *v6; // rdx
  unsigned __int64 v7; // rsi
  hkgpMesh *v8; // rbp
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *v9; // rcx
  hkgpMeshBase::Vertex *v10; // r13
  hkgpMeshBase::Edge *v11; // rdi
  hkgpMeshBase::Triangle *v12; // rax
  __int64 v13; // rdx
  hkgpMeshBase::Triangle *v14; // r8
  hkgpMeshBase::Triangle *v15; // r9
  signed __int64 v16; // rax
  unsigned __int64 v17; // rdx
  int v18; // er8
  hkgpMeshBase::Triangle *v19; // r8
  int v20; // edx
  __int64 v21; // rcx
  __int64 v22; // rax
  hkgpMeshBase::Triangle *v23; // rsi
  hkgpMeshBase::Triangle *v24; // r15
  hkgpMeshBase::Triangle *v25; // r14
  signed __int64 v26; // rdx
  hkgpMeshBase::Triangle *v27; // rcx
  hkgpMeshBase::Triangle *v28; // rax
  unsigned __int64 v29; // r9
  int v30; // er8
  int v31; // er8
  signed __int64 v32; // r10
  unsigned __int64 v33; // rdx
  int v34; // er9
  hkgpMeshBase::Triangle *v35; // r9
  int v36; // edx
  hkgpMeshBase::Edge *v37; // rax
  unsigned int v38; // [rsp+58h] [rbp+10h]

  v5 = result;
  v6 = edge->m_triangle;
  v7 = edge->m_triangle->m_links[edge->m_index];
  v8 = this;
  v9 = &this->m_triangles;
  v10 = vertex;
  v11 = edge;
  if ( v7 & 0xFFFFFFFFFFFFFFFCui64 )
  {
    v23 = (hkgpMeshBase::Triangle *)(v7 & 0xFFFFFFFFFFFFFFFCui64);
    v38 = edge->m_triangle->m_links[edge->m_index] & 3;
    v24 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            v9,
            v6);
    v25 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            &v8->m_triangles,
            v23);
    v26 = 18i64 >> 2 * (unsigned __int8)v11->m_index;
    v27 = v11->m_triangle;
    v24->m_vertices[0] = v10;
    v24->m_vertices[1] = v27->m_vertices[v26 & 3];
    v24->m_vertices[2] = v23->m_vertices[(9i64 >> 2 * (unsigned __int8)v38) & 3];
    LOBYTE(v27) = 2 * v11->m_index;
    v28 = v11->m_triangle;
    v25->m_vertices[0] = v10;
    v25->m_vertices[1] = v23->m_vertices[(18i64 >> 2 * (unsigned __int8)v38) & 3];
    v25->m_vertices[2] = v28->m_vertices[(9i64 >> (char)v27) & 3];
    v11->m_triangle->m_vertices[v11->m_index] = v10;
    v23->m_vertices[v38] = v10;
    v29 = v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v30 = v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 3;
    v24->m_links[1] = v29 + (v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 3);
    if ( v29 )
      *(_QWORD *)(v29 + 8i64 * v30 + 40) = (char *)v24 + 1;
    v31 = (18 >> 2 * v38) & 3;
    v32 = (signed __int64)v23 + 8 * v31;
    v33 = *(_QWORD *)(v32 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v34 = *(_DWORD *)(v32 + 40) & 3;
    v25->m_links[1] = v33 + (*(_QWORD *)(v32 + 40) & 3i64);
    if ( v33 )
      *(_QWORD *)(v33 + 8i64 * v34 + 40) = (char *)v25 + 1;
    v35 = v11->m_triangle;
    v36 = (18 >> 2 * LOBYTE(v11->m_index)) & 3;
    v24->m_links[0] = (unsigned __int64)v11->m_triangle + (unsigned int)v36;
    if ( v35 )
      v35->m_links[v36] = (unsigned __int64)v24;
    v25->m_links[0] = (unsigned __int64)v23 + (unsigned int)v31;
    if ( v23 )
      *(_QWORD *)(v32 + 40) = v25;
    v24->m_links[2] = (unsigned __int64)v23 + v38;
    if ( v23 )
      v23->m_links[v38] = (unsigned __int64)&v24->m_next + 2;
    v25->m_links[2] = (unsigned __int64)v11->m_triangle + v11->m_index;
    if ( v11->m_triangle )
      v11->m_triangle->m_links[v11->m_index] = (unsigned __int64)&v25->m_next + 2;
    if ( updatePlanes )
    {
      hkgpMesh::updatePlane(v8, v24);
      hkgpMesh::updatePlane(v8, v25);
      hkgpMesh::updatePlane(v8, v11->m_triangle);
      hkgpMesh::updatePlane(v8, v23);
    }
  }
  else
  {
    v12 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            v9,
            v6);
    v13 = (signed int)v11->m_index;
    v14 = v11->m_triangle;
    v15 = v12;
    v16 = (signed __int64)v11->m_triangle + 8 * v13;
    v15->m_vertices[0] = v10;
    v15->m_vertices[1] = v14->m_vertices[(18i64 >> 2 * (unsigned __int8)v13) & 3];
    v15->m_vertices[2] = *(hkgpMeshBase::Vertex **)(v16 + 16);
    v11->m_triangle->m_vertices[v11->m_index] = v10;
    v17 = v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v18 = v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 3;
    v15->m_links[1] = v17 + (v11->m_triangle->m_links[(18 >> 2 * LOBYTE(v11->m_index)) & 3] & 3);
    if ( v17 )
      *(_QWORD *)(v17 + 8i64 * v18 + 40) = (char *)v15 + 1;
    v19 = v11->m_triangle;
    v20 = (18 >> 2 * LOBYTE(v11->m_index)) & 3;
    v15->m_links[0] = (unsigned __int64)v11->m_triangle + (unsigned int)v20;
    if ( v19 )
      v19->m_links[v20] = (unsigned __int64)v15;
    if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v22 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
      v21 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    }
    else
    {
      v21 = 0i64;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
      v22 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
    }
    v15->m_links[2] = v21 + v22;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                + 40) = (char *)v15 + 2;
    if ( updatePlanes )
    {
      hkgpMesh::updatePlane(v8, v15);
      hkgpMesh::updatePlane(v8, v11->m_triangle);
    }
  }
  v5->m_triangle = v11->m_triangle;
  v37 = v5;
  v5->m_index = (18 >> 2 * LOBYTE(v11->m_index)) & 3;
  return v37;
}

// File Line: 891
// RVA: 0xCC7EB0
hkgpMeshBase::Edge *__fastcall hkgpMesh::splitEdge(hkgpMesh *this, hkgpMeshBase::Edge *result, hkgpMeshBase::Edge *edge, hkVector4f *position, bool updatePlanes)
{
  hkgpMesh *v5; // rsi
  hkVector4f *v6; // rbx
  hkgpMeshBase::Edge *v7; // rdi
  hkgpMeshBase::Edge *v8; // rbp
  hkgpMeshBase::Vertex *v9; // rax
  hkgpMeshBase::Edge v11; // [rsp+30h] [rbp-18h]

  v5 = this;
  v6 = position;
  v7 = edge;
  v8 = result;
  v9 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(&this->m_vertices);
  v9->m_data = 0i64;
  v9->m_position = (hkVector4f)v6->m_quad;
  v11 = *v7;
  hkgpMesh::splitEdge(v5, v8, &v11, v9, updatePlanes);
  return v8;
}

// File Line: 900
// RVA: 0xCC7F30
void __fastcall hkgpMesh::splitTriangle(hkgpMesh *this, hkgpMeshBase::Triangle *triangle, hkVector4f *position, bool updatePlanes)
{
  hkgpMesh *v4; // rdi
  hkVector4f *v5; // rbx
  hkgpMeshBase::Triangle *v6; // rbp
  hkgpMeshBase::Vertex *v7; // rax
  hkgpMeshBase::Vertex *v8; // rsi
  hkgpMeshBase::Triangle *v9; // rax
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *v10; // rcx
  hkgpMeshBase::Triangle *v11; // rdi
  hkgpMeshBase::Triangle *v12; // rax
  hkgpMeshBase::Triangle *v13; // rdx
  bool v14; // zf
  unsigned __int64 v15; // r8
  int v16; // eax
  unsigned __int64 v17; // rcx
  int v18; // er8

  v4 = this;
  v5 = position;
  v6 = triangle;
  v7 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(&this->m_vertices);
  v8 = v7;
  v7->m_data = 0i64;
  v7->m_position = (hkVector4f)v5->m_quad;
  v9 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
         &v4->m_triangles,
         v6);
  v10 = &v4->m_triangles;
  v11 = v9;
  v12 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
          v10,
          v6);
  v6->m_vertices[0] = v8;
  v11->m_vertices[1] = v8;
  v12->m_vertices[2] = v8;
  v13 = v12;
  v15 = v6->m_links[2] & 0xFFFFFFFFFFFFFFFCui64;
  v14 = v15 == 0;
  v16 = v6->m_links[2] & 3;
  v11->m_links[2] = v15 + (v6->m_links[2] & 3);
  if ( !v14 )
    *(_QWORD *)(v15 + 8i64 * v16 + 40) = (char *)v11 + 2;
  v17 = v6->m_links[0] & 0xFFFFFFFFFFFFFFFCui64;
  v14 = v17 == 0;
  v18 = v6->m_links[0] & 3;
  v13->m_links[0] = v17 + (v6->m_links[0] & 3);
  if ( !v14 )
    *(_QWORD *)(v17 + 8i64 * v18 + 40) = v13;
  v6->m_links[0] = (unsigned __int64)&v13->m_next + 1;
  v13->m_links[1] = (unsigned __int64)v6;
  v11->m_links[0] = (unsigned __int64)&v13->m_next + 2;
  v13->m_links[2] = (unsigned __int64)v11;
  v11->m_links[1] = (unsigned __int64)&v6->m_next + 2;
  v6->m_links[2] = (unsigned __int64)&v11->m_next + 1;
}

// File Line: 919
// RVA: 0xCC8020
void __fastcall hkgpMesh::simplify(hkgpMesh *this, hkgpMesh::SimplifyConfig *config)
{
  hkgpMesh *v2; // rbx
  __int64 *v3; // rsi
  int v4; // edi
  signed __int64 v5; // r14
  unsigned __int64 v6; // r12
  __m128 v7; // xmm9
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  hkVector4f v10; // xmm14
  hkgpMeshBase::Triangle *v11; // r15
  hkVector4f v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __int64 v20; // r13
  hkgpMeshBase::Vertex *v21; // rax
  hkVector4f v22; // xmm6
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
  signed __int64 v33; // rax
  unsigned __int64 v34; // rdx
  __int64 v35; // r13
  __int64 v36; // rcx
  __int64 v37; // rdx
  hkgpMesh *v38; // r13
  hkgpMeshBase::Triangle *v39; // rbx
  hkVector4f v40; // xmm0
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __int64 v48; // r15
  hkgpMeshBase::Vertex *v49; // rax
  hkVector4f v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm4
  __m128 v58; // xmm2
  __m128 v59; // xmm10
  __m128 v60; // xmm2
  unsigned __int64 v61; // rcx
  __int64 v62; // rdx
  __int128 v63; // xmm6
  int v64; // er9
  __int128 *v65; // rax
  __int64 v66; // rcx
  signed __int64 v67; // rax
  unsigned __int64 v68; // rdx
  __int64 v69; // rdx
  __int128 v70; // xmm6
  __int128 *v71; // rax
  signed __int64 v72; // rdx
  signed __int64 v73; // r8
  __int64 v74; // rdx
  __int64 v75; // rcx
  __int128 v76; // xmm6
  int v77; // er9
  __int128 *v78; // rax
  __int64 v79; // rcx
  signed __int64 v80; // rax
  unsigned __int64 v81; // rdx
  int v82; // er8
  void *v83; // rdx
  char v84; // r14
  __int64 v85; // rdx
  __m128i v86; // xmm6
  __m128i *v87; // rax
  signed __int64 v88; // rdx
  int v89; // eax
  int v90; // er10
  __int64 v91; // r9
  int v92; // eax
  int v93; // er11
  __int64 v94; // r10
  int v95; // eax
  int v96; // er10
  __int64 v97; // r9
  int v98; // eax
  __int64 v99; // rcx
  int v100; // er10
  __int64 v101; // r9
  int v102; // eax
  __int64 v103; // rcx
  __int64 v104; // r11
  int v105; // er10
  __int64 v106; // r9
  __int64 v107; // r8
  hkgpMesh *v108; // rcx
  __int128 v109; // [rsp+20h] [rbp-A0h]
  __int128 v110; // [rsp+20h] [rbp-A0h]
  hkgpMeshBase::Triangle *t[2]; // [rsp+30h] [rbp-90h]
  __int128 v112; // [rsp+40h] [rbp-80h]
  __m128i v113; // [rsp+50h] [rbp-70h]
  __m128i v114; // [rsp+60h] [rbp-60h]
  __m128i v115; // [rsp+70h] [rbp-50h]
  __m128i v116; // [rsp+80h] [rbp-40h]
  __m128i v117; // [rsp+90h] [rbp-30h]
  __int128 v118; // [rsp+A0h] [rbp-20h]
  __int128 v119; // [rsp+B0h] [rbp-10h]
  __int128 v120; // [rsp+C0h] [rbp+0h]
  __int128 v121; // [rsp+D0h] [rbp+10h]
  char *array; // [rsp+E0h] [rbp+20h]
  int v123; // [rsp+E8h] [rbp+28h]
  int v124; // [rsp+ECh] [rbp+2Ch]
  char v125; // [rsp+F0h] [rbp+30h]
  hkVector4f p; // [rsp+1F0h] [rbp+130h]
  __int128 v127; // [rsp+200h] [rbp+140h]
  hkVector4f v128; // [rsp+210h] [rbp+150h]
  hkVector4f v129; // [rsp+220h] [rbp+160h]
  hkVector4f v130; // [rsp+230h] [rbp+170h]
  char *v131; // [rsp+240h] [rbp+180h]
  int v132; // [rsp+248h] [rbp+188h]
  int v133; // [rsp+24Ch] [rbp+18Ch]
  char v134; // [rsp+250h] [rbp+190h]
  hkgpMesh *v135; // [rsp+430h] [rbp+370h]
  float *v136; // [rsp+438h] [rbp+378h]
  char v137; // [rsp+440h] [rbp+380h]
  unsigned __int64 v138; // [rsp+448h] [rbp+388h]

  v2 = this;
  do
  {
    v3 = (__int64 *)v2->m_triangles.m_used;
    v137 = 0;
    if ( !v3 )
      break;
    do
    {
      v4 = 0;
      v138 = *v3;
      while ( 1 )
      {
        v114.m128i_i64[0] = (__int64)v3;
        v114.m128i_i32[2] = v4;
        v5 = v3[v4 + 5] & 3;
        v6 = v3[v4 + 5] & 0xFFFFFFFFFFFFFFFCui64;
        if ( v6 )
          break;
LABEL_51:
        if ( ++v4 >= 3 )
        {
          v84 = v137;
          goto LABEL_53;
        }
      }
      v7 = aabbOut.m_quad;
      v8 = query.m_quad;
      v117.m128i_i64[0] = (__int64)v3;
      v117.m128i_i32[2] = v4;
      v9 = aabbOut.m_quad;
      v10.m_quad = *(__m128 *)(v3[((9i64 >> 2 * (unsigned __int8)v4) & 3) + 2] + 32);
      _mm_store_si128((__m128i *)t, v117);
      while ( 1 )
      {
        v11 = t[0];
        v12.m_quad = (__m128)t[0]->m_vertices[0]->m_position;
        v13 = _mm_sub_ps(t[0]->m_vertices[1]->m_position.m_quad, v12.m_quad);
        v14 = _mm_sub_ps(t[0]->m_vertices[2]->m_position.m_quad, v12.m_quad);
        v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14));
        v16 = _mm_shuffle_ps(v15, v15, 201);
        v17 = _mm_mul_ps(v16, v16);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        v19 = _mm_rsqrt_ps(v18);
        v7 = _mm_add_ps(
               v7,
               _mm_andnot_ps(
                 _mm_cmpleps(v18, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                     _mm_mul_ps(*(__m128 *)_xmm, v19)),
                   v18)));
        hkgpMesh::setPlane(v2, t[0], &p, 1);
        v20 = SLODWORD(t[1]);
        v21 = v11->m_vertices[SLODWORD(t[1])];
        v22.m_quad = (__m128)v21->m_position;
        v21->m_position = (hkVector4f)v10.m_quad;
        v23 = v11->m_vertices[0]->m_position.m_quad;
        v24 = _mm_sub_ps(v11->m_vertices[1]->m_position.m_quad, v23);
        v25 = _mm_sub_ps(v11->m_vertices[2]->m_position.m_quad, v23);
        v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
        v27 = _mm_shuffle_ps(v26, v26, 201);
        v28 = _mm_mul_ps(v27, v27);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rsqrt_ps(v29);
        v31 = _mm_andnot_ps(
                _mm_cmpleps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30)),
                  v29));
        hkgpMesh::setPlane(v135, v11, &v129, 1);
        v11->m_vertices[v20]->m_position = (hkVector4f)v22.m_quad;
        if ( v31.m128_f32[0] > 0.00000011920929 )
        {
          v9 = _mm_add_ps(v9, v31);
          v32 = _mm_mul_ps(p.m_quad, v129.m_quad);
          v8 = _mm_min_ps(
                 v8,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                   _mm_shuffle_ps(v32, v32, 170)));
        }
        v33 = v11->m_links[(18 >> 2 * v20) & 3] & 3;
        v34 = v11->m_links[(18 >> 2 * v20) & 3] & 0xFFFFFFFFFFFFFFFCui64;
        v115.m128i_i64[0] = v11->m_links[(18 >> 2 * v20) & 3] & 0xFFFFFFFFFFFFFFFCui64;
        v115.m128i_i32[2] = v33;
        _mm_store_si128((__m128i *)t, v115);
        if ( !v34 )
          break;
        v2 = v135;
        if ( (__int64 *)(v34 + (unsigned int)v33) == (__int64 *)((char *)v3 + (unsigned int)v4) )
          goto LABEL_16;
      }
      v35 = v4;
      v36 = v3[v4 + 5];
      v116.m128i_i64[0] = v3[v4 + 5] & 0xFFFFFFFFFFFFFFFCui64;
      v37 = v116.m128i_i64[0];
      v116.m128i_i32[2] = (9 >> 2 * (v36 & 3)) & 3;
      _mm_store_si128((__m128i *)t, v116);
      if ( !v37 )
        goto LABEL_17;
      v38 = v135;
      do
      {
        v39 = t[0];
        v40.m_quad = (__m128)t[0]->m_vertices[0]->m_position;
        v41 = _mm_sub_ps(t[0]->m_vertices[1]->m_position.m_quad, v40.m_quad);
        v42 = _mm_sub_ps(t[0]->m_vertices[2]->m_position.m_quad, v40.m_quad);
        v43 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v42));
        v44 = _mm_shuffle_ps(v43, v43, 201);
        v45 = _mm_mul_ps(v44, v44);
        v46 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                _mm_shuffle_ps(v45, v45, 170));
        v47 = _mm_rsqrt_ps(v46);
        v7 = _mm_add_ps(
               v7,
               _mm_andnot_ps(
                 _mm_cmpleps(v46, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v47, v46), v47)),
                     _mm_mul_ps(v47, *(__m128 *)_xmm)),
                   v46)));
        hkgpMesh::setPlane(v38, t[0], &v128, 1);
        v48 = SLODWORD(t[1]);
        v49 = v39->m_vertices[SLODWORD(t[1])];
        v50.m_quad = (__m128)v49->m_position;
        v49->m_position = (hkVector4f)v10.m_quad;
        v51 = v39->m_vertices[0]->m_position.m_quad;
        v52 = _mm_sub_ps(v39->m_vertices[1]->m_position.m_quad, v51);
        v53 = _mm_sub_ps(v39->m_vertices[2]->m_position.m_quad, v51);
        v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v52), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v53));
        v55 = _mm_shuffle_ps(v54, v54, 201);
        v56 = _mm_mul_ps(v55, v55);
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                _mm_shuffle_ps(v56, v56, 170));
        v58 = _mm_rsqrt_ps(v57);
        v59 = _mm_andnot_ps(
                _mm_cmpleps(v57, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
                    _mm_mul_ps(v58, *(__m128 *)_xmm)),
                  v57));
        hkgpMesh::setPlane(v38, v39, &v130, 1);
        v39->m_vertices[v48]->m_position = (hkVector4f)v50.m_quad;
        if ( v59.m128_f32[0] > 0.00000011920929 )
        {
          v9 = _mm_add_ps(v9, v59);
          v60 = _mm_mul_ps(v128.m_quad, v130.m_quad);
          v8 = _mm_min_ps(
                 v8,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                   _mm_shuffle_ps(v60, v60, 170)));
        }
        v61 = v39->m_links[v48];
        v113.m128i_i64[0] = v39->m_links[v48] & 0xFFFFFFFFFFFFFFFCui64;
        v62 = v113.m128i_i64[0];
        v113.m128i_i32[2] = (9 >> 2 * (v61 & 3)) & 3;
        _mm_store_si128((__m128i *)t, v113);
      }
      while ( v62 );
LABEL_16:
      v35 = v4;
LABEL_17:
      if ( v8.m128_f32[0] < *v136
        || COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v7.m128_f32[0] - v9.m128_f32[0])) >> 1) > v136[4] )
      {
        goto LABEL_50;
      }
      *(_QWORD *)&v119 = v3;
      DWORD2(v119) = v4;
      v63 = v119;
      v64 = 0;
      v123 = 0;
      v109 = v119;
      array = &v125;
      v124 = -2147483632;
      while ( 1 )
      {
        if ( v64 == (v124 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v64 = v123;
        }
        v65 = (__int128 *)&array[16 * v64];
        if ( v65 )
        {
          *v65 = v63;
          v64 = v123;
        }
        v123 = ++v64;
        v66 = (18 >> 2 * BYTE8(v109)) & 3;
        v67 = *(_QWORD *)(v109 + 8 * v66 + 40) & 3i64;
        v68 = *(_QWORD *)(v109 + 8 * v66 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        v115.m128i_i64[0] = *(_QWORD *)(v109 + 8 * v66 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        v115.m128i_i32[2] = v67;
        v63 = (__int128)v115;
        v109 = (__int128)v115;
        if ( !v68 )
          break;
        if ( (__int64 *)(v68 + (unsigned int)v67) == (__int64 *)((char *)v3 + (unsigned int)v4) )
          goto LABEL_33;
      }
      v69 = v3[v35 + 5];
      *(_QWORD *)&v121 = v69 & 0xFFFFFFFFFFFFFFFCui64;
      DWORD2(v121) = (9 >> 2 * (v69 & 3)) & 3;
      v70 = v121;
      v110 = v121;
      if ( v69 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        do
        {
          if ( v64 == (v124 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v64 = v123;
          }
          v71 = (__int128 *)&array[16 * v64];
          if ( v71 )
          {
            *v71 = v70;
            v64 = v123;
          }
          v123 = ++v64;
          v72 = *(_QWORD *)(v110 + 8i64 * SDWORD2(v110) + 40) & 3i64;
          *(_QWORD *)&v118 = *(_QWORD *)(v110 + 8i64 * SDWORD2(v110) + 40) & 0xFFFFFFFFFFFFFFFCui64;
          DWORD2(v118) = (9 >> 2 * v72) & 3;
          v70 = v118;
          v110 = v118;
        }
        while ( (_QWORD)v118 );
      }
LABEL_33:
      v73 = 0i64;
      if ( v64 > 0 )
      {
        v74 = (__int64)array;
        while ( 1 )
        {
          v75 = *(signed int *)(v74 + 8);
          if ( !(*(_QWORD *)(*(_QWORD *)v74 + 8 * v75 + 40) & 0xFFFFFFFFFFFFFFFCui64)
            || !(*(_QWORD *)(*(_QWORD *)v74 + 8i64 * ((9 >> 2 * v75) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) )
          {
            break;
          }
          ++v73;
          v74 += 16i64;
          if ( v73 >= v64 )
            goto LABEL_38;
        }
        v82 = v124;
        v123 = 0;
        if ( v124 >= 0 )
        {
          v83 = array;
          goto LABEL_48;
        }
        goto LABEL_49;
      }
LABEL_38:
      v113.m128i_i64[0] = v6;
      v113.m128i_i32[2] = v5;
      v76 = (__int128)v113;
      v77 = 0;
      v132 = 0;
      v112 = (__int128)v113;
      v131 = &v134;
      v133 = -2147483632;
      while ( 1 )
      {
        if ( v77 == (v133 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v131, 16);
          v77 = v132;
        }
        v78 = (__int128 *)&v131[16 * v77];
        if ( v78 )
        {
          *v78 = v76;
          v77 = v132;
        }
        v132 = ++v77;
        v79 = (18 >> 2 * BYTE8(v112)) & 3;
        v80 = *(_QWORD *)(v112 + 8 * v79 + 40) & 3i64;
        v81 = *(_QWORD *)(v112 + 8 * v79 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        *(_QWORD *)&v120 = *(_QWORD *)(v112 + 8 * v79 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        DWORD2(v120) = v80;
        v76 = v120;
        v112 = v120;
        if ( !v81 )
          break;
        if ( v81 + (unsigned int)v80 == v6 + (unsigned int)v5 )
          goto LABEL_62;
      }
      v85 = *(_QWORD *)(v6 + 8i64 * (signed int)v5 + 40);
      v114.m128i_i64[0] = v85 & 0xFFFFFFFFFFFFFFFCui64;
      v114.m128i_i32[2] = (9 >> 2 * (v85 & 3)) & 3;
      v86 = v114;
      v112 = (__int128)v114;
      if ( v85 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        do
        {
          if ( v77 == (v133 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v131, 16);
            v77 = v132;
          }
          v87 = (__m128i *)&v131[16 * v77];
          if ( v87 )
          {
            *v87 = v86;
            v77 = v132;
          }
          v132 = ++v77;
          v88 = *(_QWORD *)(v112 + 8i64 * SDWORD2(v112) + 40) & 3i64;
          *(_QWORD *)&v112 = *(_QWORD *)(v112 + 8i64 * SDWORD2(v112) + 40) & 0xFFFFFFFFFFFFFFFCui64;
          DWORD2(v112) = (9 >> 2 * v88) & 3;
          v86 = (__m128i)v112;
        }
        while ( (_QWORD)v112 );
      }
LABEL_62:
      v89 = v123;
      v90 = 0;
      if ( v123 > 0 )
      {
        v91 = 0i64;
        do
        {
          ++v90;
          v92 = *(_DWORD *)&array[v91 + 8];
          v91 += 16i64;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&array[v91 - 16] + 8 * ((9i64 >> 2 * (unsigned __int8)v92) & 3) + 16)
                    + 84i64) = 0;
          v89 = v123;
        }
        while ( v90 < v123 );
        v77 = v132;
      }
      v93 = 0;
      if ( v77 > 0 )
      {
        v94 = 0i64;
        do
        {
          ++v93;
          v95 = *(_DWORD *)&v131[v94 + 8];
          v94 += 16i64;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v131[v94 - 16] + 8 * ((9i64 >> 2 * (unsigned __int8)v95) & 3) + 16) + 84i64) = 0;
          v77 = v132;
        }
        while ( v93 < v132 );
        v89 = v123;
      }
      v96 = 0;
      if ( v89 > 0 )
      {
        v97 = 0i64;
        do
        {
          ++v96;
          v98 = *(_DWORD *)&array[v97 + 8];
          v97 += 16i64;
          v99 = *(_QWORD *)(*(_QWORD *)&array[v97 - 16] + 8 * ((9i64 >> 2 * (unsigned __int8)v98) & 3) + 16);
          ++*(_DWORD *)(v99 + 84);
          v89 = v123;
        }
        while ( v96 < v123 );
        v77 = v132;
      }
      v100 = 0;
      if ( v77 > 0 )
      {
        v101 = 0i64;
        do
        {
          ++v100;
          v102 = *(_DWORD *)&v131[v101 + 8];
          v101 += 16i64;
          v103 = *(_QWORD *)(*(_QWORD *)&v131[v101 - 16] + 8 * ((9i64 >> 2 * (unsigned __int8)v102) & 3) + 16);
          *(_DWORD *)(v103 + 84) += 2;
        }
        while ( v100 < v132 );
        v89 = v123;
      }
      v104 = (__int64)array;
      v105 = 0;
      v106 = v89;
      if ( v89 <= 0 )
        goto LABEL_98;
      v107 = (__int64)array;
      do
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v107
                                   + 8 * ((9i64 >> 2 * (unsigned __int8)*(_DWORD *)(v107 + 8)) & 3)
                                   + 16)
                       + 84i64) == 3 )
          ++v105;
        v107 += 16i64;
        --v106;
      }
      while ( v106 );
      if ( v105 != 2 )
      {
LABEL_98:
        v132 = 0;
        if ( v133 >= 0 )
        {
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            v131,
            (unsigned int)(16 * v133),
            v106);
          v104 = (__int64)array;
        }
        v82 = v124;
        v131 = 0i64;
        v133 = 2147483648;
        v123 = 0;
        if ( v124 >= 0 )
        {
          v83 = (void *)v104;
LABEL_48:
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v83,
            16 * v82);
        }
LABEL_49:
        array = 0i64;
        v124 = 2147483648;
LABEL_50:
        v2 = v135;
        goto LABEL_51;
      }
      if ( (__int64 *)v138 == v3 || v138 == v6 )
        v138 = v3[((9 >> 2 * v4) & 3) + 5] & 0xFFFFFFFFFFFFFFFCui64;
      v2 = v135;
      v108 = v135;
      _mm_store_si128((__m128i *)&v127, v114);
      hkgpMesh::collapseEdge(v108, (hkgpMeshBase::Edge *)&v127, 0);
      v84 = 1;
      v137 = 1;
      v132 = 0;
      if ( v133 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v131,
          16 * v133);
      v131 = 0i64;
      v133 = 2147483648;
      v123 = 0;
      if ( v124 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          16 * v124);
      array = 0i64;
      v124 = 2147483648;
LABEL_53:
      v3 = (__int64 *)v138;
    }
    while ( v138 );
  }
  while ( v84 );
  hkgpMesh::removeOrphanVertices(v2);
  hkgpMesh::invalidateConvexHull(v2);
  hkgpMesh::setVerticesTag(v2, -1);
}
  while ( v84 );
  hkgpMesh::removeOrphanVertices(v2);
  hkgpMesh::invalidateConvexHull(v2);
  hkgpMesh::setVerticesTag(v2, -1);
}

// File Line: 966
// RVA: 0xCC8C60
void __fastcall hkgpMesh::locate(hkgpMesh *this, hkVector4f *x, hkgpMesh::Location *location, hkBool useTree)
{
  hkgpMesh::Location *v4; // rbx
  hkVector4f *v5; // r14
  hkgpMesh *v6; // rdi
  hkVector4f v7; // xmm6
  hkgpMeshBase::Triangle *v8; // rsi
  __m128 v9; // xmm1
  __int64 v10; // rdx
  hkSimdFloat32 *v11; // rax
  __m128 v12; // xmm4
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __int64 v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 *v20; // r8
  __m128 *v21; // r9
  __m128 *v22; // r10
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __int64 v25; // rax
  hkVector4f v26; // xmm1
  hkgpMeshBase::Triangle *v27; // rdi
  __m128i *v28; // rax
  hkVector4f v29; // xmm0
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm0
  __int64 v32; // rcx
  __int64 v33; // rcx
  __m128 v34; // xmm5
  hkVector4f *normalOut; // [rsp+28h] [rbp-C0h]
  hkErrStream baryOut; // [rsp+40h] [rbp-A8h]
  char point[24]; // [rsp+60h] [rbp-88h]
  __m128 v38; // [rsp+78h] [rbp-70h]
  hkgpMeshBase::Triangle *v39; // [rsp+88h] [rbp-60h]
  NearestFeaturePolicy query; // [rsp+98h] [rbp-50h]
  hkVector4f p2; // [rsp+C8h] [rbp-20h]
  char buf; // [rsp+D8h] [rbp-10h]
  char v43; // [rsp+340h] [rbp+258h]

  v4 = location;
  v5 = x;
  v6 = this;
  if ( !this->m_hasPerVertexNormals )
  {
    hkErrStream::hkErrStream(&baryOut, &buf, 512);
    hkOstream::operator<<((hkOstream *)&baryOut.vfptr, "assignVertexNormals not called");
    if ( (unsigned int)hkError::messageError(1730889943, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 969) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&baryOut.vfptr);
    useTree.m_bool = v43;
  }
  v7.m_quad = (__m128)xmmword_141A712A0;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  query.m_normal = (hkVector4f)xmmword_141A712A0;
  v39 = 0i64;
  *(_OWORD *)&point[8] = 0i64;
  if ( useTree.m_bool )
  {
    v11 = hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::closest<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,NearestFeaturePolicy>(
            (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&baryOut,
            (hkSimdFloat32 *)v6->m_trianglesTree,
            (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)v5,
            (hkVector4f *)&point[8],
            &query,
            (hkSimdFloat32 *)normalOut);
    v10 = (__int64)v39;
    v9 = *(__m128 *)&point[8];
    v7.m_quad = v11->m_real;
LABEL_7:
    v12 = v38;
    goto LABEL_8;
  }
  v27 = v6->m_triangles.m_used;
  if ( !v27 )
    goto LABEL_7;
  do
  {
    _mm_store_si128((__m128i *)&query.m_coordinates, (__m128i)v27->m_vertices[0]->m_position.m_quad);
    v28 = (__m128i *)v27->m_vertices[2];
    _mm_store_si128((__m128i *)&query.m_nearestTriangle, (__m128i)v27->m_vertices[1]->m_position.m_quad);
    _mm_store_si128((__m128i *)&p2, v28[2]);
    hkGeometryProcessing::squaredDistanceFromPointToTriangle(
      (hkSimdFloat32 *)&query,
      v5,
      &query.m_coordinates,
      (hkVector4f *)&query.m_nearestTriangle,
      &p2,
      (hkVector4f *)point,
      (hkVector4f *)&baryOut);
    if ( query.m_normal.m_quad.m128_f32[0] >= v7.m_quad.m128_f32[0] )
    {
      v10 = (__int64)v39;
      v12 = v38;
      v9 = *(__m128 *)&point[8];
    }
    else
    {
      v9 = *(__m128 *)point;
      v12 = *(__m128 *)&baryOut.vfptr;
      v10 = (__int64)v27;
      v39 = v27;
      *(_OWORD *)&point[8] = *(_OWORD *)point;
      v38 = *(__m128 *)&baryOut.vfptr;
      v7.m_quad = (__m128)query.m_normal;
    }
    v27 = v27->m_next;
  }
  while ( v27 );
LABEL_8:
  v4->m_pseudoNormal = 0i64;
  v13 = _mm_andnot_ps(
          _mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v7.m_quad, 1u), 1u), *(__m128 *)&epsilon),
          v7.m_quad);
  if ( v10 )
  {
    v4->m_normal.m_quad = v9;
    v14 = _mm_mul_ps(v9, v9);
    *(_DWORD *)point = 1;
    *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
    v15 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
    v4->m_inside.m_real = g_vectorfConstants[0];
    v4->m_coordinates.m_quad = v12;
    v4->m_squaredDistance.m_real = v13;
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v16), (__m128)0i64);
    v19 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v16, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                    _mm_mul_ps(*(__m128 *)_xmm, v17))),
                v4->m_normal.m_quad),
              v18),
            _mm_andnot_ps(v18, v4->m_normal.m_quad));
    v4->m_normal.m_quad = v19;
    v20 = *(__m128 **)(v10 + 16);
    v21 = *(__m128 **)(v10 + 24);
    v22 = *(__m128 **)(v10 + 32);
    v23 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v20[2]);
    v4->m_projection.m_quad = v23;
    v24 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), *(__m128 *)(*(_QWORD *)(v10 + 24) + 32i64)), v23);
    v4->m_projection.m_quad = v24;
    v25 = *(_QWORD *)point;
    v4->m_projection.m_quad = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), *(__m128 *)(*(_QWORD *)(v10 + 32) + 32i64)),
                                v24);
    v4->m_inside = (hkSimdFloat32)::query.m_quad;
    v26.m_quad = *(__m128 *)(v10 + 64);
    *(_QWORD *)&v4->m_region.m_type = v25;
    v4->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
    *(_QWORD *)&v4->m_region.m_feature.m_index = v15;
    v4->m_pseudoNormal = (hkVector4f)v26.m_quad;
    switch ( _mm_movemask_ps(_mm_cmpneqps(v12, (__m128)0i64)) & 7 )
    {
      case 1:
        v31.m_quad = v20[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
        *(_DWORD *)point = 3;
        v4->m_pseudoNormal = (hkVector4f)v31.m_quad;
        goto LABEL_29;
      case 2:
        v30.m_quad = v21[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 1;
        *(_DWORD *)point = 3;
        v4->m_pseudoNormal = (hkVector4f)v30.m_quad;
        goto LABEL_29;
      case 3:
        if ( *(_QWORD *)(v10 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
          v4->m_pseudoNormal.m_quad = _mm_add_ps(
                                        *(__m128 *)((*(_QWORD *)(v10 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                        v4->m_pseudoNormal.m_quad);
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 0;
        goto LABEL_28;
      case 4:
        v29.m_quad = v22[3];
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 2;
        *(_DWORD *)point = 3;
        v4->m_pseudoNormal = (hkVector4f)v29.m_quad;
        goto LABEL_29;
      case 5:
        if ( *(_QWORD *)(v10 + 56) & 0xFFFFFFFFFFFFFFFCui64 )
          v4->m_pseudoNormal.m_quad = _mm_add_ps(
                                        *(__m128 *)((*(_QWORD *)(v10 + 56) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                        v4->m_pseudoNormal.m_quad);
        *(_DWORD *)point = 2;
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 2;
        v32 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
        *(_QWORD *)&v4->m_region.m_type = *(_QWORD *)point;
        v4->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
        *(_QWORD *)&v4->m_region.m_feature.m_index = v32;
        break;
      case 6:
        if ( *(_QWORD *)(v10 + 48) & 0xFFFFFFFFFFFFFFFCui64 )
          v4->m_pseudoNormal.m_quad = _mm_add_ps(
                                        *(__m128 *)((*(_QWORD *)(v10 + 48) & 0xFFFFFFFFFFFFFFFCui64) + 64),
                                        v4->m_pseudoNormal.m_quad);
        *(_DWORD *)&baryOut.m_memSizeAndFlags = 1;
LABEL_28:
        *(_DWORD *)point = 2;
LABEL_29:
        v33 = *(_QWORD *)&baryOut.m_memSizeAndFlags;
        *(_QWORD *)&v4->m_region.m_type = *(_QWORD *)point;
        v4->m_region.m_feature.m_triangle = (hkgpMeshBase::Triangle *)v10;
        *(_QWORD *)&v4->m_region.m_feature.m_index = v33;
        break;
      case 7:
        if ( v13.m128_f32[0] == 0.0 )
          v4->m_inside.m_real = g_vectorfConstants[0];
        break;
      default:
        break;
    }
    v34 = _mm_mul_ps(v19, v4->m_pseudoNormal.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170))) <= 0.0 )
      v4->m_inside.m_real = g_vectorfConstants[0];
  }
  else
  {
    v4->m_normal = 0i64;
    v4->m_coordinates = 0i64;
    v4->m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
    v4->m_region.m_type = 0;
    v4->m_inside = (hkSimdFloat32)::query.m_quad;
    if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v8 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    }
    else
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
    }
    v4->m_region.m_feature.m_triangle = v8;
    *(_QWORD *)&v4->m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                 + 1);
  }
}

// File Line: 1074
// RVA: 0xCC9120
hkSimdFloat32 *__fastcall hkgpMesh::squaredDistanceToPoint(hkgpMesh *this, hkSimdFloat32 *result, hkVector4f *x, hkVector4f *normal, hkVector4fComparison *inside)
{
  hkgpMeshBase::Triangle *v5; // rax
  hkVector4f *v6; // rdi
  hkSimdFloat32 *v7; // rbx
  hkSimdFloat32 v8; // xmm1
  hkVector4f v9; // xmm0
  hkSimdFloat32 *v10; // rax
  hkgpMesh::Location location; // [rsp+20h] [rbp-98h]

  v5 = 0i64;
  v6 = normal;
  v7 = result;
  location.m_region.m_type = 0;
  if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
  {
    v5 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
  }
  else
  {
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
  }
  location.m_region.m_feature.m_triangle = v5;
  *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                    + 1);
  location.m_normal = 0i64;
  location.m_pseudoNormal = 0i64;
  location.m_coordinates = 0i64;
  location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
  location.m_inside.m_real = g_vectorfConstants[0];
  hkgpMesh::locate(this, x, &location, (hkBool)1);
  v8.m_real = (__m128)location.m_squaredDistance;
  inside->m_mask = _mm_cmpltps(location.m_inside.m_real, (__m128)0i64);
  v9.m_quad = (__m128)location.m_normal;
  v10 = v7;
  _mm_store_si128((__m128i *)v7, (__m128i)v8.m_real);
  *v6 = (hkVector4f)v9.m_quad;
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
  hkSimdFloat32 *v2; // rbx
  hkgpConvexHull *v3; // rax

  v2 = result;
  v3 = hkgpMesh::getConvexHull(this);
  hkgpConvexHull::getVolume(v3, v2);
  return v2;
}

// File Line: 1094
// RVA: 0xCC9250
hkgpMesh *__fastcall hkgpMesh::clone(hkgpMesh *this)
{
  hkgpMesh *v1; // rsi
  _QWORD **v2; // rax
  hkgpMesh *v3; // rax
  __int64 v4; // rax
  __int64 v5; // r13
  hkgpMesh::IConvexOverlap *v6; // rax
  unsigned __int64 i; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v8; // rax
  unsigned __int64 v9; // r9
  __int64 v10; // rax
  hkgpMeshBase::Triangle *v11; // rsi
  hkgpMeshBase::Triangle *v12; // rax
  signed __int64 v13; // rbp
  signed __int64 v14; // rbx
  hkgpMeshBase::Triangle *v15; // rdi
  signed __int64 v16; // r14
  unsigned __int64 v17; // rax
  unsigned int v18; // ebx
  signed __int64 v19; // r14
  __int64 v20; // rcx
  __int64 v21; // rax
  unsigned __int64 v22; // rax
  unsigned int v23; // er9
  unsigned __int64 v24; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v26; // [rsp+20h] [rbp-48h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v27; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 152i64);
  if ( v3 )
  {
    hkgpMesh::hkgpMesh(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->m_iconvexoverlap;
  v27.m_elem = 0i64;
  v27.m_numElems = 0;
  v27.m_hashMod = -1;
  *(_QWORD *)(v5 + 64) = v6;
  for ( i = (unsigned __int64)v1->m_vertices.m_used; i; i = *(_QWORD *)i )
  {
    v8 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool **)(v5 + 16);
    if ( !v8 || !v8->m_free )
      v8 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)(v5 + 16));
    if ( v8 )
    {
      v9 = (unsigned __int64)v8->m_free;
      v8->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v9;
      *(_QWORD *)(v9 + 96) = v8;
      ++v8->m_used;
      *(_OWORD *)(v9 + 16) = *(_OWORD *)(i + 16);
      *(_OWORD *)(v9 + 32) = *(_OWORD *)(i + 32);
      *(_OWORD *)(v9 + 48) = *(_OWORD *)(i + 48);
      *(_OWORD *)(v9 + 64) = *(_OWORD *)(i + 64);
      *(_DWORD *)(v9 + 80) = *(_DWORD *)(i + 80);
      *(_DWORD *)(v9 + 84) = *(_DWORD *)(i + 84);
      *(_QWORD *)(v9 + 8) = 0i64;
      *(_QWORD *)v9 = *(_QWORD *)(v5 + 24);
      v10 = *(_QWORD *)(v5 + 24);
      if ( v10 )
        *(_QWORD *)(v10 + 8) = v9;
      ++*(_DWORD *)(v5 + 32);
      *(_QWORD *)(v5 + 24) = v9;
    }
    else
    {
      v9 = 0i64;
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v27,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      i,
      v9);
  }
  v11 = v1->m_triangles.m_used;
  v26.m_elem = 0i64;
  v26.m_numElems = 0;
  for ( v26.m_hashMod = -1; v11; v11 = v11->m_next )
  {
    v12 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
            (hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *)(v5 + 40),
            v11);
    v13 = 3i64;
    v14 = (signed __int64)v12->m_vertices;
    v15 = v12;
    v16 = (char *)v11 - (char *)v12;
    do
    {
      v17 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v27,
              *(_QWORD *)(v16 + v14),
              0i64);
      v14 += 8i64;
      *(_QWORD *)(v14 - 8) = v17;
      --v13;
    }
    while ( v13 );
    v18 = 0;
    do
    {
      v19 = 8i64 * (signed int)v18 + 40;
      v20 = *(__int64 *)((char *)&v11->m_next + v19);
      if ( v20 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v22 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v26,
                (v20 & 0xFFFFFFFFFFFFFFFCui64) + (*(_QWORD *)((_BYTE *)&v11->m_next + v19) & 3i64),
                0i64);
        v23 = v22 & 3;
        v24 = v22 & 0xFFFFFFFFFFFFFFFCui64;
        if ( v24 )
        {
          *(hkgpMeshBase::Triangle **)((char *)&v15->m_next + v19) = (hkgpMeshBase::Triangle *)(v24 + v23);
          *(_QWORD *)(v24 + 8i64 * (signed int)v23 + 40) = (char *)v15 + v18;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
            &v26,
            &result,
            (unsigned __int64)v11 + v18);
        }
        else
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v26,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (unsigned __int64)v11 + v18,
            (unsigned __int64)v15 + v18);
        }
      }
      else
      {
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v21 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        }
        else
        {
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v21 = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        }
        *(hkgpMeshBase::Triangle **)((char *)&v15->m_next + v19) = (hkgpMeshBase::Triangle *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                                                            + v21);
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                    + 40) = (char *)v15 + v18;
      }
      ++v18;
    }
    while ( (signed int)v18 < 3 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v26,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v26);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v27,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v27);
  return (hkgpMesh *)v5;
}

// File Line: 1138
// RVA: 0xCC9550
void __fastcall hkgpMesh::append(hkgpMesh *this, hkgpMesh *other)
{
  hkgpMeshBase::Vertex *v2; // rdi
  hkgpMesh *v3; // r14
  hkgpMesh *v4; // rax
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *v5; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v6; // rax
  unsigned __int64 v7; // r9
  hkgpMeshBase::Vertex *v8; // rax
  hkgpMeshBase::Triangle *v9; // r14
  hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> > *v10; // r13
  hkgpMeshBase::Triangle *v11; // rax
  signed __int64 v12; // rdi
  unsigned __int64 *v13; // rbx
  hkgpMeshBase::Triangle *v14; // rbp
  unsigned __int64 v15; // rax
  unsigned int v16; // ebx
  signed __int64 v17; // r12
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  unsigned int v20; // er15
  unsigned __int64 v21; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v22; // [rsp+20h] [rbp-58h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v23; // [rsp+30h] [rbp-48h]
  hkgpMesh *v24; // [rsp+80h] [rbp+8h]
  hkResult result; // [rsp+88h] [rbp+10h]

  v24 = this;
  v2 = other->m_vertices.m_used;
  v3 = other;
  v4 = this;
  v23.m_hashMod = -1;
  v22.m_hashMod = -1;
  v23.m_elem = 0i64;
  v23.m_numElems = 0;
  v22.m_elem = 0i64;
  v22.m_numElems = 0;
  if ( v2 )
  {
    v5 = &this->m_vertices;
    do
    {
      v6 = v5->m_allocator.m_firstPool;
      if ( !v5->m_allocator.m_firstPool || !v6->m_free )
        v6 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v5->m_allocator);
      if ( v6 )
      {
        v7 = (unsigned __int64)v6->m_free;
        v6->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v7;
        *(_QWORD *)(v7 + 96) = v6;
        ++v6->m_used;
        *(hkVector4f *)(v7 + 16) = v2->m_source;
        *(hkVector4f *)(v7 + 32) = v2->m_position;
        *(hkVector4f *)(v7 + 48) = v2->m_normal;
        *(hkVector4f *)(v7 + 64) = v2->m_data;
        *(_DWORD *)(v7 + 80) = v2->m_refs;
        *(_DWORD *)(v7 + 84) = v2->m_tag;
        *(_QWORD *)(v7 + 8) = 0i64;
        *(_QWORD *)v7 = v5->m_used;
        v8 = v5->m_used;
        if ( v8 )
          v8->m_prev = (hkgpMeshBase::Vertex *)v7;
        ++v5->m_numUsed;
        v5->m_used = (hkgpMeshBase::Vertex *)v7;
      }
      else
      {
        v7 = 0i64;
      }
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v23,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v2,
        v7);
      v2 = v2->m_next;
    }
    while ( v2 );
    v4 = v24;
  }
  v9 = v3->m_triangles.m_used;
  if ( v9 )
  {
    v10 = &v4->m_triangles;
    do
    {
      v11 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(
              v10,
              v9);
      v12 = 3i64;
      v13 = (unsigned __int64 *)v11->m_vertices;
      v14 = v11;
      do
      {
        v15 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v23,
                *v13,
                0i64);
        ++v13;
        *(v13 - 1) = v15;
        --v12;
      }
      while ( v12 );
      v16 = 0;
      do
      {
        v17 = (signed int)v16;
        v18 = v14->m_links[v17];
        if ( v18 & 0xFFFFFFFFFFFFFFFCui64 )
        {
          v19 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v22,
                  (v18 & 0xFFFFFFFFFFFFFFFCui64) + (v14->m_links[v17] & 3),
                  0i64);
          v20 = v19 & 3;
          v21 = v19 & 0xFFFFFFFFFFFFFFFCui64;
          if ( v19 & 0xFFFFFFFFFFFFFFFCui64 )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
              &v22,
              &result,
              (unsigned __int64)v9 + v16);
            v14->m_links[v17] = v21 + v20;
            *(_QWORD *)(v21 + 8i64 * (signed int)v20 + 40) = (char *)v14 + v16;
          }
          else
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v22,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (unsigned __int64)v9 + v16,
              (unsigned __int64)v14 + v16);
          }
        }
        ++v16;
      }
      while ( (signed int)v16 < 3 );
      v9 = v9->m_next;
    }
    while ( v9 );
  }
  hkgpMesh::invalidateConvexHull(v24);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v22,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v22);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v23,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v23);
}

// File Line: 1174
// RVA: 0xCC97D0
void __fastcall hkgpMesh::invalidateConvexHull(hkgpMesh *this)
{
  hkgpMesh *v1; // rbx
  hkgpConvexHull *v2; // rcx

  v1 = this;
  v2 = this->m_convexHull;
  if ( v2 )
    v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
  v1->m_convexHull = 0i64;
}

// File Line: 1180
// RVA: 0xCC9810
char __fastcall hkgpMesh::rebuildConvexHull(hkgpMesh *this)
{
  hkgpMesh *v1; // rbx
  _QWORD **v2; // rax
  hkgpConvexHull *v3; // rax
  hkgpConvexHull *v4; // rax
  hkgpConvexHull *v5; // rcx
  int v6; // er8
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+20h] [rbp-28h]
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-18h]

  v1 = this;
  hkgpMesh::invalidateConvexHull(this);
  if ( v1->m_vertices.m_numUsed <= 3 )
    return 1;
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  *(_WORD *)&config.m_buildIndices.m_bool = 257;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( v3 )
    hkgpConvexHull::hkgpConvexHull(v3);
  else
    v4 = 0i64;
  v1->m_convexHull = v4;
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 2147483648;
  hkgpMesh::fetchPositions(v1, &positions);
  hkgpConvexHull::build(v1->m_convexHull, positions.m_data, positions.m_size, &config);
  if ( (unsigned int)hkgpConvexHull::getDimensions(v1->m_convexHull) == 3 )
  {
    positions.m_size = 0;
    if ( positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        positions.m_data,
        16 * positions.m_capacityAndFlags);
    return 1;
  }
  v5 = v1->m_convexHull;
  if ( v5 )
    v5->vfptr->__vecDelDtor((hkBaseObject *)&v5->vfptr, 1u);
  v6 = positions.m_capacityAndFlags;
  v1->m_convexHull = 0i64;
  positions.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * v6);
  return 0;
}

// File Line: 1202
// RVA: 0xCC9960
int hkgpMesh::rebuildTrianglesTree(...)
{
  __int64 *v3; // rbx
  int v4; // er8
  hkgpMesh *v5; // rsi
  hkgpMeshBase::Triangle *v6; // rsi
  __m128 v7; // xmm11
  __m128 v8; // xmm3
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  unsigned __int64 v15; // r15
  __int64 v16; // rcx
  __int64 v17; // r14
  __int64 v18; // rax
  __int64 v19; // rdi
  __m128 v20; // xmm7
  __m128 v21; // xmm8
  __int64 v22; // r8
  __int64 v23; // rax
  __m128 *v24; // rdi
  __m128 *v25; // r8
  __m128 v26; // xmm9
  __m128 v27; // xmm10
  __int64 v28; // rdx
  __int64 v29; // rcx
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm6
  __m128 v38; // xmm5
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  float v41; // xmm4_4
  unsigned __int64 v42; // r11
  unsigned __int64 v43; // r9
  signed __int64 v44; // rax
  __m128 v45; // xmm1
  __int64 v46; // [rsp+30h] [rbp-D0h]
  __int64 v47; // [rsp+38h] [rbp-C8h]
  hkVector4f *vectorArray; // [rsp+40h] [rbp-C0h]
  hkVector4f *v49; // [rsp+48h] [rbp-B8h]
  hkVector4f *v50; // [rsp+50h] [rbp-B0h]
  hkAabb aabbOut; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+130h] [rbp+30h]
  float v53; // [rsp+138h] [rbp+38h]
  hkResult v54; // [rsp+140h] [rbp+40h]
  hkResult v55; // [rsp+148h] [rbp+48h]

  v53 = margin;
  v3 = (__int64 *)this->m_trianglesTree;
  v4 = *((_DWORD *)v3 + 3);
  v5 = this;
  *((_DWORD *)v3 + 2) = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*v3,
      v4 << 6);
  *v3 = 0i64;
  *((_DWORD *)v3 + 3) = 2147483648;
  v3[2] = 0i64;
  v3[4] = 0i64;
  v3[3] = 0i64;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v3,
    &result,
    2 * v5->m_triangles.m_numUsed);
  v6 = v5->m_triangles.m_used;
  v7 = _mm_shuffle_ps((__m128)LODWORD(v53), (__m128)LODWORD(v53), 0);
  if ( v6 )
  {
    result.m_enum = LODWORD(FLOAT_0_000099999997);
    do
    {
      v8 = v6->m_plane.m_quad;
      vectorArray = &v6->m_vertices[0]->m_position;
      v49 = &v6->m_vertices[1]->m_position;
      v50 = &v6->m_vertices[2]->m_position;
      if ( _mm_movemask_ps(_mm_cmpunordps(v8, v8)) & 7
        || (v9 = _mm_mul_ps(v8, v8),
            a3.m128_f32[0] = 0.000099999997,
            a3 = _mm_shuffle_ps(a3, a3, 0),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85))
                                                        + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170)))
                                        - 1.0)) >> 1) >= a3.m128_f32[0]) )
      {
        v6->m_leafIdx = 0i64;
      }
      else
      {
        hkAabbUtil::calcAabb(&vectorArray, 3i64, &aabbOut);
        a3 = 0i64;
        if ( v7.m128_f32[0] <= 0.0 )
        {
          result.m_enum = 1008981770;
          v10 = _mm_sub_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad);
          v11 = _mm_mul_ps(v10, v10);
          v12 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                  _mm_shuffle_ps(v11, v11, 170));
          v13 = _mm_rsqrt_ps(v12);
          a3 = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                   _mm_mul_ps(*(__m128 *)_xmm, v13)),
                 v12);
          v14 = _mm_mul_ps(
                  _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v12, (__m128)0i64), a3), (__m128)xmmword_141A711B0),
                  _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0));
          aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, v14);
          aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, v14);
        }
        else
        {
          aabbOut.m_max.m_quad = _mm_add_ps(aabbOut.m_max.m_quad, v7);
          aabbOut.m_min.m_quad = _mm_sub_ps(aabbOut.m_min.m_quad, v7);
        }
        if ( !v3[2] )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v3,
            &v54,
            1);
        v15 = v3[2];
        v16 = *v3;
        v17 = v3[2] << 6;
        v3[2] = *(_QWORD *)(((signed __int64)(signed int)v15 << 6) + *v3);
        *(_QWORD *)(v17 + v16 + 40) = 0i64;
        *(_QWORD *)(v17 + v16 + 48) = v6;
        *(hkVector4f *)(v17 + v16) = aabbOut.m_min;
        *(hkVector4f *)(v17 + v16 + 16) = aabbOut.m_max;
        v18 = *v3;
        v19 = v3[4];
        v20 = *(__m128 *)(v17 + *v3);
        v21 = *(__m128 *)(v17 + *v3 + 16);
        if ( v19 )
        {
          if ( !v3[2] )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v3,
              &v55,
              1);
          v22 = v3[2];
          v23 = (signed int)v22;
          v24 = (__m128 *)(*v3 + (v19 << 6));
          v25 = (__m128 *)(*v3 + (v22 << 6));
          v3[2] = *(_QWORD *)((v23 << 6) + *v3);
          if ( v24[2].m128_i32[2] )
          {
            v26 = _mm_add_ps(v21, v20);
            v27 = _mm_sub_ps(v21, v20);
            do
            {
              v28 = *v3 + (v24[2].m128_u64[1] << 6);
              v29 = *v3 + (v24[3].m128_u64[0] << 6);
              v30 = _mm_max_ps(v24[1], v21);
              *v24 = _mm_min_ps(*v24, v20);
              v24[1] = v30;
              v46 = v28;
              v47 = v29;
              v31 = *(__m128 *)(v28 + 16);
              v32 = *(__m128 *)(v29 + 16);
              v33 = v31;
              v34 = v32;
              v35 = _mm_add_ps(_mm_sub_ps(v31, *(__m128 *)v28), v27);
              v36 = _mm_sub_ps(_mm_add_ps(v33, *(__m128 *)v28), v26);
              v37 = _mm_add_ps(_mm_sub_ps(v32, *(__m128 *)v29), v27);
              v38 = _mm_sub_ps(_mm_add_ps(v34, *(__m128 *)v29), v26);
              v39 = _mm_mul_ps(v36, v36);
              v40 = _mm_mul_ps(v38, v38);
              v41 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170));
              a3 = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                       _mm_shuffle_ps(v40, v40, 170)),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                       _mm_shuffle_ps(v37, v37, 170)));
              v24 = (__m128 *)*(&v46
                              + ((float)(v41
                                       * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170)))) > a3.m128_f32[0]));
            }
            while ( v24[2].m128_i32[2] );
          }
          v42 = v24[2].m128_u64[0];
          v43 = ((signed __int64)v25 - *v3) >> 6;
          if ( v42 )
            *(_QWORD *)(*v3
                      + 8 * ((*(_QWORD *)((v42 << 6) + *v3 + 48) == ((signed __int64)v24 - *v3) >> 6) + 8 * v42)
                      + 40) = v43;
          else
            v3[4] = v43;
          v25[2].m128_u64[0] = v24[2].m128_u64[0];
          v44 = (signed __int64)v24 - *v3;
          v25[3].m128_u64[0] = v15;
          v25[2].m128_u64[1] = v44 >> 6;
          v24[2].m128_u64[0] = v43;
          *(_QWORD *)(v17 + *v3 + 32) = v43;
          v45 = _mm_max_ps(v24[1], v21);
          *v25 = _mm_min_ps(*v24, v20);
          v25[1] = v45;
          ++*((_DWORD *)v3 + 6);
          v6->m_leafIdx = v15;
        }
        else
        {
          v3[4] = v15;
          *(_QWORD *)(v17 + v18 + 32) = 0i64;
          ++*((_DWORD *)v3 + 6);
          v6->m_leafIdx = v15;
        }
      }
      v6 = v6->m_next;
    }
    while ( v6 );
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)v3,
    v3[4],
    (hkBool)1,
    32,
    16);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices((hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)v3);
}

// File Line: 1235
// RVA: 0xCC9E90
void __fastcall hkgpMesh::appendToGeometry(hkgpMesh *this, hkGeometry *geom, bool flipOrientation)
{
  bool v3; // r13
  hkGeometry *v4; // rbp
  hkgpMesh *v5; // rsi
  int v6; // edi
  int v7; // er14
  int v8; // eax
  int v9; // er9
  int v10; // eax
  __int64 v11; // r12
  int v12; // er15
  int v13; // er9
  int v14; // eax
  signed __int64 v15; // rdi
  int v16; // eax
  int v17; // er8
  signed __int64 v18; // rbp
  unsigned __int64 i; // rbx
  _OWORD *v20; // rax
  hkgpMeshBase::Triangle *v21; // rdi
  int *v22; // rbx
  int v23; // eax
  int v24; // ecx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v25; // [rsp+30h] [rbp-48h]
  hkResult result; // [rsp+80h] [rbp+8h]
  __int64 v27; // [rsp+98h] [rbp+20h]

  v3 = flipOrientation;
  v4 = geom;
  v5 = this;
  if ( this->m_triangles.m_numUsed > 0 )
  {
    v6 = this->m_vertices.m_numUsed;
    v7 = geom->m_vertices.m_size;
    v8 = geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    v9 = v7 + v6;
    if ( v8 < v7 + v6 )
    {
      v10 = 2 * v8;
      if ( v9 < v10 )
        v9 = v10;
      hkArrayUtil::_reserve(
        (hkResult *)&v27,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &geom->m_vertices,
        v9,
        16);
    }
    v4->m_vertices.m_size += v6;
    v11 = v4->m_triangles.m_size;
    v12 = v5->m_triangles.m_numUsed;
    v13 = v11 + v12;
    v14 = v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    v15 = (signed __int64)&v4->m_vertices.m_data[v7];
    if ( v14 >= (signed int)v11 + v12 )
    {
      result.m_enum = 0;
    }
    else
    {
      v16 = 2 * v14;
      if ( v13 < v16 )
        v13 = v16;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_triangles,
        v13,
        16);
    }
    v4->m_triangles.m_size += v12;
    v17 = v5->m_vertices.m_numUsed;
    v25.m_elem = 0i64;
    v25.m_numElems = 0;
    v18 = (signed __int64)&v4->m_triangles.m_data[v11];
    v25.m_hashMod = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v25,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v17 + 1);
    for ( i = (unsigned __int64)v5->m_vertices.m_used; i; i = *(_QWORD *)i )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v25,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        i,
        v7 + (v25.m_numElems & 0x7FFFFFFF));
      v20 = (_OWORD *)v15;
      v15 += 16i64;
      *v20 = *(_OWORD *)(i + 32);
    }
    v21 = v5->m_triangles.m_used;
    if ( v21 )
    {
      v22 = (int *)(v18 + 4);
      do
      {
        *(v22 - 1) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                       &v25,
                       (unsigned __int64)v21->m_vertices[0],
                       0xFFFFFFFFFFFFFFFFui64);
        *v22 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                 &v25,
                 (unsigned __int64)v21->m_vertices[1],
                 0xFFFFFFFFFFFFFFFFui64);
        v23 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v25,
                (unsigned __int64)v21->m_vertices[2],
                0xFFFFFFFFFFFFFFFFui64);
        v22[1] = v23;
        v22[2] = v21->m_material;
        if ( v3 )
        {
          v24 = *v22;
          *v22 = v23;
          v22[1] = v24;
        }
        v21 = v21->m_next;
        v22 += 4;
      }
      while ( v21 );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v25,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v25);
  }
}

// File Line: 1266
// RVA: 0xCCA0A0
void __fastcall hkgpMesh::appendFromGeometry(hkgpMesh *this, hkGeometry *geom, hkTransformf *xform, int partId, bool flipOrientation, bool removeInvalidTriangles)
{
  hkVector4f v6; // xmm3
  __m128i v7; // xmm1
  hkVector4f v8; // xmm2
  hkMatrix4f xforma; // [rsp+30h] [rbp-48h]

  v6.m_quad = (__m128)xform->m_translation;
  v7 = _mm_srli_si128(_mm_slli_si128((__m128i)xform->m_rotation.m_col1.m_quad, 4), 4);
  v8.m_quad = (__m128)xform->m_rotation.m_col2;
  _mm_store_si128((__m128i *)&xforma, _mm_srli_si128(_mm_slli_si128((__m128i)xform->m_rotation.m_col0.m_quad, 4), 4));
  _mm_store_si128((__m128i *)&xforma.m_col1, v7);
  _mm_store_si128((__m128i *)&xforma.m_col2, _mm_srli_si128(_mm_slli_si128((__m128i)v8.m_quad, 4), 4));
  xforma.m_col3.m_quad = _mm_shuffle_ps(v6.m_quad, _mm_unpackhi_ps(v6.m_quad, query.m_quad), 196);
  hkgpMesh::appendFromGeometry(this, geom, &xforma, partId, flipOrientation, removeInvalidTriangles);
}

// File Line: 1273
// RVA: 0xCCA130
void __usercall hkgpMesh::appendFromGeometry(hkgpMesh *this@<rcx>, hkGeometry *geom@<rdx>, hkMatrix4f *xform@<r8>, int partId@<r9d>, __int64 a5@<rbx>, bool flipOrientation, bool removeInvalidTriangles)
{
  int v7; // ebx
  hkVector4f *v8; // r15
  hkMatrix4f *v9; // r13
  hkgpMesh *v10; // rsi
  char *v11; // r10
  int v12; // edi
  int v13; // er9
  __int64 v14; // rbx
  char *v15; // rdi
  int v16; // eax
  int v17; // edx
  int v18; // er9
  __int64 v19; // rbx
  char *v20; // rdi
  int v21; // eax
  int v22; // eax
  __int64 v23; // rcx
  __int64 v24; // rdx
  signed __int64 v25; // rcx
  float v26; // edx
  __int64 v27; // rbx
  int *v28; // rdi
  int v29; // er8
  int v30; // eax
  unsigned __int64 v31; // rcx
  __int64 v32; // rdx
  signed __int64 v33; // rcx
  hkgpMesh *v34; // r10
  __int64 v35; // r14
  __int64 v36; // r12
  int v37; // edi
  __m128 v38; // xmm1
  __m128 v39; // xmm6
  __int64 v40; // rdx
  unsigned __int64 v41; // r9
  __int64 v42; // r8
  __m128 **v43; // r9
  __m128 **v44; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v45; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v46; // rdi
  hkgpMeshBase::Vertex *v47; // rax
  signed __int64 v48; // rcx
  __int128 v49; // xmm0
  int v50; // xmm1_4
  int v51; // edx
  unsigned __int64 v52; // rbx
  _QWORD *v53; // rcx
  __int64 v54; // rbx
  int *v55; // rdi
  int v56; // er8
  hkgpMesh *v57; // r9
  hkResultEnum v58; // edi
  char *v59; // rdx
  __int64 v60; // r8
  __int64 v61; // rcx
  __m128i *v62; // r14
  __m128i *v63; // rbx
  __m128i *v64; // rsi
  hkgpMesh *v65; // r10
  __m128i v66; // xmm1
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v67; // rax
  __m128i v68; // xmm0
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v69; // rax
  int v70; // er12
  signed __int64 v71; // rbx
  signed int v72; // er13
  char *v73; // r14
  hkVector4f *v74; // rbx
  hkVector4f *v75; // rsi
  int v76; // edi
  int v77; // er8
  int v78; // eax
  unsigned int v79; // er11
  unsigned int v80; // eax
  int v81; // edi
  __int64 v82; // rdx
  __int64 v83; // rax
  __int64 v84; // r10
  hkVector4f **v85; // r11
  hkVector4f **v86; // rax
  signed __int64 v87; // rdx
  int v88; // edi
  unsigned int v89; // edi
  __int64 v90; // r14
  signed __int64 v91; // rdx
  __int64 v92; // rcx
  __int64 v93; // rdx
  signed __int64 v94; // rdi
  unsigned __int64 v95; // rax
  signed __int64 v96; // rcx
  __int64 v97; // rax
  __int64 v98; // rdi
  unsigned __int64 v99; // rax
  hkgpMeshBase::Triangle *v100; // rdi
  int v101; // eax
  __m128 v102; // xmm3
  int v103; // ecx
  int v104; // edi
  __int64 v105; // rdx
  __int64 v106; // r8
  __int64 v107; // r8
  __int64 v108; // r8
  int v109; // edi
  __int64 v110; // rbx
  __int64 *v111; // rdx
  __int64 v112; // rax
  _QWORD *v113; // rcx
  __int64 v114; // rdx
  bool v115; // zf
  __int64 v116; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v117; // rax
  __int64 v118; // rcx
  __int64 v119; // rbx
  char *v120; // rdi
  int v121; // eax
  char *v122; // [rsp+30h] [rbp-C8h]
  int v123; // [rsp+38h] [rbp-C0h]
  int i; // [rsp+3Ch] [rbp-BCh]
  hkResult result; // [rsp+40h] [rbp-B8h]
  char *v126; // [rsp+48h] [rbp-B0h]
  unsigned int v127; // [rsp+50h] [rbp-A8h]
  int v128; // [rsp+54h] [rbp-A4h]
  int v129; // [rsp+58h] [rbp-A0h]
  hkVector4f p; // [rsp+60h] [rbp-98h]
  int v131; // [rsp+70h] [rbp-88h]
  char *array; // [rsp+78h] [rbp-80h]
  int v133; // [rsp+80h] [rbp-78h]
  int v134; // [rsp+84h] [rbp-74h]
  __int64 v135; // [rsp+88h] [rbp-70h]
  int v136; // [rsp+90h] [rbp-68h]
  hkVector4f a; // [rsp+98h] [rbp-60h]
  hkVector4f b; // [rsp+A8h] [rbp-50h]
  hkVector4f c; // [rsp+B8h] [rbp-40h]
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *retaddr; // [rsp+118h] [rbp+20h]
  hkgpMesh *v141; // [rsp+120h] [rbp+28h]
  __int64 v142; // [rsp+130h] [rbp+38h]
  int v143; // [rsp+138h] [rbp+40h]

  v143 = partId;
  v141 = this;
  v142 = a5;
  v7 = geom->m_vertices.m_size;
  v8 = 0i64;
  v9 = xform;
  v10 = this;
  v134 = 2147483648;
  v11 = 0i64;
  array = 0i64;
  v12 = 0;
  v133 = 0;
  v126 = 0i64;
  v127 = 0;
  v129 = 0;
  v128 = 2147483648;
  if ( v7 > 0 )
  {
    v13 = v7;
    if ( v7 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 8);
    v12 = v133;
    v11 = array;
  }
  if ( v7 - v12 > 0 )
    memset(&v11[8 * v12], 0, 8i64 * (v7 - v12));
  v133 = v7;
  v14 = (signed int)(v127 - 1);
  if ( (signed int)(v127 - 1) >= 0 )
  {
    v15 = &v126[16 * (v127 - 1) + 12];
    do
    {
      v16 = *(_DWORD *)v15;
      *((_DWORD *)v15 - 1) = 0;
      if ( v16 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v15 - 12),
          40 * (v16 & 0x3FFFFFFF));
      *(_QWORD *)(v15 - 12) = 0i64;
      *(_DWORD *)v15 = 2147483648;
      v15 -= 16;
      --v14;
    }
    while ( v14 >= 0 );
  }
  v17 = 0;
  v129 = 0;
  v127 = 0;
  if ( (v128 & 0x3FFFFFFF) < 8209 )
  {
    v18 = 8209;
    if ( 2 * (v128 & 0x3FFFFFFF) > 8209 )
      v18 = 2 * (v128 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v126, v18, 16);
    v17 = v127;
  }
  v19 = v17 - 8210;
  if ( v17 - 8210 >= 0 )
  {
    v20 = &v126[16 * v19 + 131356];
    do
    {
      v21 = *(_DWORD *)v20;
      *((_DWORD *)v20 - 1) = 0;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v20 - 12),
          40 * (v21 & 0x3FFFFFFF));
      *(_QWORD *)(v20 - 12) = 0i64;
      *(_DWORD *)v20 = 2147483648;
      v20 -= 16;
      --v19;
    }
    while ( v19 >= 0 );
    v17 = v127;
  }
  v22 = 8209 - v17;
  v23 = (__int64)&v126[16 * v17];
  v24 = 8209 - v17;
  if ( v22 > 0 )
  {
    do
    {
      if ( v23 )
      {
        *(_QWORD *)v23 = 0i64;
        *(_DWORD *)(v23 + 8) = 0;
        *(_DWORD *)(v23 + 12) = 2147483648;
      }
      v23 += 16i64;
      --v24;
    }
    while ( v24 );
  }
  v127 = 8209;
  v25 = 0i64;
  do
  {
    v25 += 16i64;
    *(_DWORD *)&v126[v25 - 8] = 0;
  }
  while ( v25 < 131344 );
  p.m_quad.m128_u64[0] = 0i64;
  p.m_quad.m128_u64[1] = 0x8000000000000000i64;
  v131 = 0;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &p, 8209, 16);
  v26 = p.m_quad.m128_f32[2];
  v27 = p.m_quad.m128_i32[2] - 8210;
  if ( p.m_quad.m128_i32[2] - 8210 >= 0 )
  {
    v28 = (int *)(16 * v27 + p.m_quad.m128_u64[0] + 131356);
    do
    {
      v29 = *v28;
      *(v28 - 1) = 0;
      if ( v29 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v28 - 3),
          16 * v29);
      *(_QWORD *)(v28 - 3) = 0i64;
      *v28 = 2147483648;
      v28 -= 4;
      --v27;
    }
    while ( v27 >= 0 );
    v26 = p.m_quad.m128_f32[2];
  }
  v30 = 8209 - LODWORD(v26);
  v31 = p.m_quad.m128_u64[0] + 16i64 * SLODWORD(v26);
  v32 = 8209 - LODWORD(v26);
  if ( v30 > 0 )
  {
    do
    {
      if ( v31 )
      {
        *(_QWORD *)v31 = 0i64;
        *(_DWORD *)(v31 + 8) = 0;
        *(_DWORD *)(v31 + 12) = 2147483648;
      }
      v31 += 16i64;
      --v32;
    }
    while ( v32 );
  }
  p.m_quad.m128_i32[2] = 8209;
  v33 = 0i64;
  do
  {
    v33 += 16i64;
    *(_DWORD *)(v33 + p.m_quad.m128_u64[0] - 8) = 0;
  }
  while ( v33 < 131344 );
  v34 = v141;
  v35 = 0i64;
  v36 = SLODWORD(v141->m_vertices.m_used);
  if ( v36 > 0 )
  {
    do
    {
      v37 = 0;
      v38 = *(__m128 *)((char *)&v8->m_quad + (unsigned __int64)v34->m_vertices.m_allocator.m_firstPool);
      v39 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v9->m_col0.m_quad), v9->m_col3.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    *(__m128 *)((char *)&v8->m_quad + (unsigned __int64)v34->m_vertices.m_allocator.m_firstPool),
                    v38,
                    85),
                  v9->m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v9->m_col2.m_quad));
      LODWORD(v122) = v39.m128_i32[0];
      HIDWORD(v122) = (unsigned __int128)_mm_shuffle_ps(v39, v39, 85);
      v123 = (unsigned __int128)_mm_shuffle_ps(v39, v39, 170);
      v40 = 0i64;
      v41 = p.m_quad.m128_u64[0]
          + 16
          * (((unsigned int)(1076768587 * v39.m128_i32[0]) ^ (unsigned __int64)(1077394133 * HIDWORD(v122) ^ (unsigned int)(1921969139 * v123)))
           % p.m_quad.m128_u32[2]);
      v42 = *(signed int *)(v41 + 8);
      if ( v42 <= 0 )
        goto LABEL_45;
      v43 = *(__m128 ***)v41;
      v44 = v43;
      while ( (_mm_movemask_ps(_mm_cmpeqps(**v44, v39)) & 7) != 7 )
      {
        ++v40;
        ++v37;
        v44 += 2;
        if ( v40 >= v42 )
          goto LABEL_45;
      }
      if ( v37 != -1 && (v48 = (signed __int64)&v43[2 * v37]) != 0 )
      {
        *(_QWORD *)&array[8 * v35] = *(_QWORD *)(v48 + 8);
      }
      else
      {
LABEL_45:
        v45 = v10->m_vertices.m_allocator.m_firstPool;
        if ( !v45 || !v45->m_free )
        {
          v45 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v10->m_vertices.m_allocator);
          v34 = v141;
        }
        if ( v45 )
        {
          v46 = v45->m_free;
          v45->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v46->m_data;
          v46->m_pool = v45;
          ++v45->m_used;
          *(_QWORD *)&v46->m_data[80] = -1i64;
          *(_QWORD *)&v46->m_data[8] = 0i64;
          *(_QWORD *)v46->m_data = v10->m_vertices.m_used;
          v47 = v10->m_vertices.m_used;
          if ( v47 )
            v47->m_prev = (hkgpMeshBase::Vertex *)v46;
          ++v10->m_vertices.m_numUsed;
          v10->m_vertices.m_used = (hkgpMeshBase::Vertex *)v46;
        }
        else
        {
          v46 = 0i64;
        }
        v49 = *(__int128 *)((char *)v8 + (unsigned __int64)v34->m_vertices.m_allocator.m_firstPool);
        *(__m128 *)&v46->m_data[32] = v39;
        *(_OWORD *)&v46->m_data[16] = v49;
        *(_OWORD *)&v46->m_data[64] = 0i64;
        v50 = *(_DWORD *)&v46->m_data[36];
        LODWORD(v135) = *(_DWORD *)&v46->m_data[32];
        LODWORD(v49) = *(_DWORD *)&v46->m_data[40];
        HIDWORD(v135) = v50;
        *(_QWORD *)&array[8 * v35] = v46;
        ++v131;
        v136 = v49;
        v51 = ((unsigned int)(1076768587 * v135) ^ (unsigned __int64)(1077394133 * HIDWORD(v135) ^ (unsigned int)(1921969139 * v49)))
            % p.m_quad.m128_u32[2];
        v52 = p.m_quad.m128_u64[0] + 16i64 * v51;
        if ( *(_DWORD *)(v52 + 8) == (*(_DWORD *)(v52 + 12) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (void *)(p.m_quad.m128_u64[0] + 16i64 * v51),
            16);
          v34 = v141;
        }
        v53 = (_QWORD *)(*(_QWORD *)v52 + 16i64 * (signed int)(*(_DWORD *)(v52 + 8))++);
        *v53 = (char *)v46 + 32;
        v10 = (hkgpMesh *)retaddr;
        v53[1] = v46;
      }
      ++v35;
      ++v8;
    }
    while ( v35 < v36 );
    v8 = 0i64;
  }
  v54 = p.m_quad.m128_i32[2] - 1;
  if ( p.m_quad.m128_i32[2] - 1 >= 0 )
  {
    v55 = (int *)(16i64 * (p.m_quad.m128_i32[2] - 1) + p.m_quad.m128_u64[0] + 12);
    do
    {
      v56 = *v55;
      *(v55 - 1) = 0;
      if ( v56 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v55 - 3),
          16 * v56);
      *(_QWORD *)(v55 - 3) = 0i64;
      *v55 = 2147483648;
      v55 -= 4;
      --v54;
    }
    while ( v54 >= 0 );
  }
  p.m_quad.m128_i32[2] = 0;
  if ( p.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)p.m_quad.m128_u64[0],
      16 * p.m_quad.m128_i32[3]);
  v57 = v141;
  v58 = 0;
  result.m_enum = 0;
  if ( SLODWORD(v141->m_triangles.m_allocator.m_firstPool) > 0 )
  {
    v59 = array;
    v60 = 0i64;
    v135 = 0i64;
    while ( 1 )
    {
      v61 = *(_QWORD *)&v57->m_vertices.m_numUsed;
      v62 = *(__m128i **)&v59[8 * *(signed int *)(v60 + v61)];
      v63 = *(__m128i **)&v59[8 * *(signed int *)(v60 + v61 + 4)];
      v64 = *(__m128i **)&v59[8 * *(signed int *)(v60 + v61 + 8)];
      if ( (_BYTE)v143 )
      {
        v63 = *(__m128i **)&v59[8 * *(signed int *)(v60 + v61 + 8)];
        v64 = *(__m128i **)&v59[8 * *(signed int *)(v60 + v61 + 4)];
      }
      if ( v62 != v63 && v63 != v64 && v64 != v62 )
        break;
LABEL_121:
      ++v58;
      v60 += 16i64;
      result.m_enum = v58;
      v135 = v60;
      if ( v58 >= SLODWORD(v57->m_triangles.m_allocator.m_firstPool) )
        goto LABEL_122;
    }
    v65 = (hkgpMesh *)retaddr;
    v66 = v63[2];
    v67 = retaddr[5].m_firstPool;
    _mm_store_si128((__m128i *)&a, v62[2]);
    v68 = v64[2];
    _mm_store_si128((__m128i *)&b, v66);
    _mm_store_si128((__m128i *)&c, v68);
    if ( !v67 || !v67->m_free )
    {
      v67 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(retaddr + 5);
      v65 = (hkgpMesh *)retaddr;
      v60 = v135;
      v57 = v141;
    }
    if ( v67 )
    {
      v8 = (hkVector4f *)v67->m_free;
      v67->m_free = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *)v8->m_quad.m128_u64[0];
      v8[7].m_quad.m128_u64[0] = (unsigned __int64)v67;
      ++v67->m_used;
      v8->m_quad.m128_u64[1] = 0i64;
      *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator> *)v8->m_quad.m128_f32 = retaddr[6];
      v69 = retaddr[6].m_firstPool;
      if ( v69 )
        *(_QWORD *)&v69->m_items[0].m_data[8] = v8;
      ++LODWORD(retaddr[7].m_firstPool);
      retaddr[6].m_firstPool = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v8;
    }
    v8[5].m_quad.m128_i32[0] = v142;
    v8[2].m_quad.m128_u64[1] = 0i64;
    v8[3].m_quad.m128_u64[0] = 0i64;
    v8[3].m_quad.m128_u64[1] = 0i64;
    v8[6].m_quad.m128_u64[0] = 0i64;
    v8[5].m_quad.m128_i32[2] = *(_DWORD *)(v60 + *(_QWORD *)&v57->m_vertices.m_numUsed + 12);
    v8[1].m_quad.m128_u64[0] = (unsigned __int64)v62;
    v8[1].m_quad.m128_u64[1] = (unsigned __int64)v63;
    v8[2].m_quad.m128_u64[0] = (unsigned __int64)v64;
    if ( !hkgpMesh::setPlane(v65, &a, &b, &c, v8 + 4, 1) )
      v8[4] = 0i64;
    v70 = 2;
    v71 = 16i64;
    v72 = 0;
    v73 = 0i64;
    v122 = 0i64;
    while ( 1 )
    {
      v74 = *(hkVector4f **)((char *)v8[1].m_quad.m128_u64 + v71);
      v75 = *(hkVector4f **)&v73[(_QWORD)v8 + 16];
      b.m_quad.m128_i32[2] = 0;
      a.m_quad.m128_u64[0] = (unsigned __int64)v74;
      a.m_quad.m128_u64[1] = (unsigned __int64)v75;
      c.m_quad.m128_i32[0] = 0;
      v76 = (signed int)v74;
      v77 = (signed int)v75;
      v78 = (signed int)v75;
      if ( (signed int)v74 > (signed int)v75 )
      {
        v76 = (signed int)v75;
        v78 = (signed int)v74;
      }
      v79 = v127;
      v80 = (95564881 * v78 ^ 45564901 * v76) % 5564887;
      v81 = 0;
      v82 = 0i64;
      v83 = (__int64)&v126[16 * (v80 % v127)];
      v84 = *(signed int *)(v83 + 8);
      if ( v84 <= 0 )
      {
LABEL_98:
        v88 = (signed int)v74;
        if ( (signed int)v74 > (signed int)v75 )
        {
          v88 = (signed int)v75;
          v77 = (signed int)v74;
        }
        ++v129;
        v89 = (95564881 * v77 ^ 45564901 * v88) % 5564887;
        v90 = (__int64)&v126[16 * (v89 % v79)];
        if ( *(_DWORD *)(v90 + 8) == (*(_DWORD *)(v90 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v126[16 * (v89 % v79)],
            40);
        v91 = *(_QWORD *)v90 + 40i64 * *(signed int *)(v90 + 8);
        if ( v91 )
        {
          *(_QWORD *)v91 = 0i64;
          *(_QWORD *)(v91 + 8) = 0i64;
          *(_QWORD *)(v91 + 16) = 0i64;
          *(_DWORD *)(v91 + 24) = 0;
          *(_DWORD *)(v91 + 32) = 0;
        }
        v92 = *(signed int *)(v90 + 8);
        v93 = *(_QWORD *)v90;
        v94 = 5 * v92;
        *(_DWORD *)(v90 + 8) = v92 + 1;
        v95 = b.m_quad.m128_u64[1];
        *(_QWORD *)(v93 + 8 * v94) = v74;
        *(_QWORD *)(v93 + 8 * v94 + 8) = v75;
        *(_QWORD *)(v93 + 8 * v94 + 16) = 0i64;
        *(_QWORD *)(v93 + 8 * v94 + 24) = v95;
        *(_QWORD *)(v93 + 8 * v94 + 32) = c.m_quad.m128_u64[0];
        v96 = 5i64 * (*(_DWORD *)(v90 + 8) - 1);
        v97 = *(_QWORD *)v90;
        v73 = v122;
        v87 = v97 + 8 * v96;
      }
      else
      {
        v85 = *(hkVector4f ***)v83;
        v86 = *(hkVector4f ***)v83;
        while ( (v74 != *v86 || v75 != v86[1]) && (v74 != v86[1] || v75 != *v86) )
        {
          ++v82;
          ++v81;
          v86 += 5;
          if ( v82 >= v84 )
            goto LABEL_97;
        }
        if ( v81 == -1 || (v87 = (signed __int64)&v85[5 * v81]) == 0 )
        {
LABEL_97:
          v79 = v127;
          goto LABEL_98;
        }
      }
      if ( ++*(_DWORD *)(v87 + 32) == 1 )
        break;
      if ( *(_DWORD *)(v87 + 32) == 2 )
      {
        if ( v74 == *(hkVector4f **)(v87 + 8) && v75 == *(hkVector4f **)v87 )
        {
          v8[2].m_quad.m128_u64[v70 + 1] = *(_QWORD *)(v87 + 16) + *(unsigned int *)(v87 + 24);
          v98 = *(_QWORD *)(v87 + 16);
          if ( v98 )
            *(_QWORD *)(v98 + 8i64 * *(signed int *)(v87 + 24) + 40) = (char *)v8 + (unsigned int)v70;
          if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
          {
            *(_QWORD *)(v87 + 16) = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
          }
          else
          {
            DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
            `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
            *(_QWORD *)(v87 + 16) = 0i64;
          }
          v99 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                + 1);
          goto LABEL_118;
        }
        hkgpMesh::reportInvalidEdgeWinding((hkgpMesh *)retaddr, v74 + 2, v75 + 2);
      }
      else
      {
        hkgpMesh::reportDuplicatedEdge((hkgpMesh *)retaddr, v74 + 2, v75 + 2);
      }
LABEL_119:
      v70 = v72;
      v71 = (signed __int64)v73;
      v73 += 8;
      ++v72;
      v122 = v73;
      if ( v72 >= 3 )
      {
        v59 = array;
        v60 = v135;
        v58 = result.m_enum;
        v57 = v141;
        v8 = 0i64;
        goto LABEL_121;
      }
    }
    p.m_quad.m128_i32[2] = v70;
    v99 = p.m_quad.m128_u64[1];
    *(_QWORD *)(v87 + 16) = v8;
LABEL_118:
    *(_QWORD *)(v87 + 24) = v99;
    goto LABEL_119;
  }
LABEL_122:
  if ( flipOrientation )
  {
    v100 = (hkgpMeshBase::Triangle *)retaddr[6].m_firstPool;
    v101 = 0;
    v122 = 0i64;
    v123 = 0;
    for ( i = 2147483648; v100; v100 = v100->m_next )
    {
      if ( !hkgpMesh::setPlane((hkgpMesh *)retaddr, v100, &p, 1)
        || _mm_movemask_ps(_mm_cmpunordps(p.m_quad, p.m_quad)) & 7
        || (v102 = _mm_mul_ps(p.m_quad, p.m_quad),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 85))
                                                        + COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 0)))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 170)))
                                        - 1.0)) >> 1) >= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0))) )
      {
        v103 = v123;
        if ( v123 == (i & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v122, 8);
          v103 = v123;
        }
        *(_QWORD *)&v122[8 * v103] = v100;
        v101 = v123++ + 1;
      }
      else
      {
        v101 = v123;
      }
    }
    v104 = 0;
    if ( v101 > 0 )
    {
      v105 = 0i64;
      do
      {
        v106 = *(_QWORD *)&v122[v105];
        if ( *(_QWORD *)(v106 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((*(_QWORD *)(v106 + 40) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v106 + 40) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v106 + 40) = 0i64;
        v107 = *(_QWORD *)&v122[v105];
        if ( *(_QWORD *)(v107 + 48) & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((*(_QWORD *)(v107 + 48) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v107 + 48) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v107 + 48) = 0i64;
        v108 = *(_QWORD *)&v122[v105];
        if ( *(_QWORD *)(v108 + 56) & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)((*(_QWORD *)(v108 + 56) & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*(_QWORD *)(v108 + 56) & 3i64) + 40) = 0i64;
        *(_QWORD *)(v108 + 56) = 0i64;
        v101 = v123;
        ++v104;
        v105 += 8i64;
      }
      while ( v104 < v123 );
    }
    v109 = 0;
    if ( v101 > 0 )
    {
      v110 = 0i64;
      do
      {
        v111 = *(__int64 **)&v122[v110];
        v112 = *v111;
        v113 = (_QWORD *)v111[1];
        if ( *v111 )
          *(_QWORD *)(v112 + 8) = v113;
        if ( v113 )
          *v113 = v112;
        else
          retaddr[6].m_firstPool = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *)v112;
        --LODWORD(retaddr[7].m_firstPool);
        v114 = v111[14];
        v115 = (*(_DWORD *)(v114 + 4120))-- == 1;
        if ( v115 )
        {
          v116 = *(_QWORD *)(v114 + 4104);
          v117 = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool **)(v114 + 4112);
          if ( v116 )
            *(_QWORD *)(v116 + 4112) = v117;
          else
            retaddr[5].m_firstPool = v117;
          v118 = *(_QWORD *)(v114 + 4112);
          if ( v118 )
            *(_QWORD *)(v118 + 4104) = *(_QWORD *)(v114 + 4104);
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)v114,
            4128);
        }
        ++v109;
        v110 += 8i64;
      }
      while ( v109 < v123 );
    }
    v123 = 0;
    if ( i >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v122,
        8 * i);
    hkgpMesh::removeOrphanVertices((hkgpMesh *)retaddr);
  }
  hkgpMesh::invalidateConvexHull((hkgpMesh *)retaddr);
  v119 = (signed int)(v127 - 1);
  if ( (signed int)(v127 - 1) >= 0 )
  {
    v120 = &v126[16 * (v127 - 1) + 12];
    do
    {
      v121 = *(_DWORD *)v120;
      *((_DWORD *)v120 - 1) = 0;
      if ( v121 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v120 - 12),
          40 * (v121 & 0x3FFFFFFF));
      *(_QWORD *)(v120 - 12) = 0i64;
      *(_DWORD *)v120 = 2147483648;
      v120 -= 16;
      --v119;
    }
    while ( v119 >= 0 );
  }
  v127 = 0;
  if ( v128 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v126,
      16 * v128);
  v126 = 0i64;
  v133 = 0;
  v128 = 2147483648;
  if ( v134 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v134);
}

// File Line: 1400
// RVA: 0xCCAF30
void __fastcall hkgpMesh::appendFromGeometryRaw(hkgpMesh *this, hkGeometry *geom, hkMatrix4f *xform, bool flipOrientation)
{
  int v4; // ebx
  __m128i v5; // xmm0
  __m128i v6; // xmm2
  __m128i v7; // xmm1
  hkgpMesh *v8; // r15
  bool v9; // si
  hkMatrix4f *v10; // r13
  char *v11; // rdx
  int v12; // ecx
  int v13; // er9
  char *v14; // rdi
  int v15; // eax
  __int64 v16; // rcx
  __int64 v17; // rbx
  char *v18; // rdi
  int v19; // eax
  int v20; // edx
  int v21; // er9
  __int64 v22; // rbx
  char *v23; // rdi
  int v24; // eax
  int v25; // eax
  __int64 v26; // rcx
  __int64 v27; // rdx
  signed __int64 v28; // rcx
  hkgpMesh *v29; // r8
  __int64 v30; // rcx
  __int64 v31; // r12
  int v32; // eax
  signed __int64 v33; // rsi
  __int64 v34; // r14
  __m128 **v35; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v36; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v37; // rdx
  hkgpMeshBase::Vertex *v38; // rax
  __m128 *v39; // rax
  __m128 v40; // xmm1
  __int64 v41; // rbx
  __m128 *v42; // r14
  __m128 *v43; // rsi
  __m128 v44; // xmm6
  __int64 v45; // r12
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm5
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v55; // rax
  __m128 v56; // xmm6
  signed __int64 v57; // rdi
  __m128 v58; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v59; // r15
  __int64 v60; // rax
  __int64 v61; // rdx
  signed int v62; // er13
  int v63; // eax
  bool v64; // sf
  unsigned __int8 v65; // of
  signed int v66; // er12
  int v67; // ecx
  __int64 v68; // rbx
  signed __int64 v69; // rsi
  hkVector4f *v70; // rsi
  hkVector4f *v71; // r14
  int v72; // edi
  int v73; // er8
  int v74; // eax
  unsigned int v75; // er11
  unsigned int v76; // eax
  int v77; // edi
  __int64 v78; // rdx
  __int64 v79; // rax
  __int64 v80; // r10
  hkVector4f **v81; // r11
  hkVector4f **v82; // rax
  signed __int64 v83; // rdx
  int v84; // edi
  unsigned int v85; // edi
  __int64 v86; // rbx
  signed __int64 v87; // rdx
  __int64 v88; // rcx
  __int64 v89; // rdx
  signed __int64 v90; // rdi
  __int64 v91; // rax
  signed __int64 v92; // rcx
  __int64 v93; // rax
  __int64 v94; // rdi
  __int64 v95; // rax
  __int64 v96; // rbx
  char *v97; // rdi
  int v98; // eax
  bool v99; // [rsp+30h] [rbp-C8h]
  char *v100; // [rsp+38h] [rbp-C0h]
  unsigned int v101; // [rsp+40h] [rbp-B8h]
  int v102; // [rsp+44h] [rbp-B4h]
  int v103; // [rsp+48h] [rbp-B0h]
  hkResult result; // [rsp+50h] [rbp-A8h]
  char *array; // [rsp+58h] [rbp-A0h]
  int v106; // [rsp+60h] [rbp-98h]
  int v107; // [rsp+64h] [rbp-94h]
  __int64 v108; // [rsp+68h] [rbp-90h]
  int v109; // [rsp+70h] [rbp-88h]
  int v110; // [rsp+74h] [rbp-84h]
  __int64 v111; // [rsp+78h] [rbp-80h]
  __m128 *v112; // [rsp+80h] [rbp-78h]
  __m128 *v113; // [rsp+88h] [rbp-70h]
  __m128 *v114; // [rsp+90h] [rbp-68h]
  hkVector4f *v115; // [rsp+98h] [rbp-60h]
  hkVector4f *v116; // [rsp+A0h] [rbp-58h]
  __int64 v117; // [rsp+B0h] [rbp-48h]
  __int64 v118; // [rsp+B8h] [rbp-40h]
  __int64 v119; // [rsp+C8h] [rbp-30h]
  hkgpMesh *retaddr; // [rsp+178h] [rbp+80h]
  hkgpMesh *v121; // [rsp+180h] [rbp+88h]
  hkGeometry *v122; // [rsp+188h] [rbp+90h]
  hkMatrix4f *v123; // [rsp+190h] [rbp+98h]

  v123 = xform;
  v122 = geom;
  v121 = this;
  v4 = geom->m_vertices.m_size;
  v5 = (__m128i)_mm_sub_ps(xform->m_col3.m_quad, qi.m_vec.m_quad);
  v6 = (__m128i)_mm_sub_ps(xform->m_col2.m_quad, stru_141A71280.m_quad);
  v7 = (__m128i)_mm_sub_ps(xform->m_col1.m_quad, direction.m_quad);
  v8 = this;
  v9 = flipOrientation;
  v10 = xform;
  v107 = 2147483648;
  v102 = 2147483648;
  v99 = _mm_movemask_ps(
          _mm_cmpleps(
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
  v100 = 0i64;
  v101 = 0;
  v103 = 0;
  array = 0i64;
  v106 = 0;
  if ( v4 > 0 )
  {
    v13 = v4;
    if ( v4 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 8);
    v12 = v106;
    v11 = array;
  }
  v14 = &v11[8 * v12];
  v15 = v4 - v12;
  v16 = v4 - v12;
  if ( v15 > 0 )
    memset(v14, 0, 8 * v16);
  v106 = v4;
  v17 = (signed int)(v101 - 1);
  if ( (signed int)(v101 - 1) >= 0 )
  {
    v18 = &v100[16 * (v101 - 1) + 12];
    do
    {
      v19 = *(_DWORD *)v18;
      *((_DWORD *)v18 - 1) = 0;
      if ( v19 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v18 - 12),
          40 * (v19 & 0x3FFFFFFF));
      *(_QWORD *)(v18 - 12) = 0i64;
      *(_DWORD *)v18 = 2147483648;
      v18 -= 16;
      --v17;
    }
    while ( v17 >= 0 );
  }
  v20 = 0;
  v103 = 0;
  v101 = 0;
  if ( (v102 & 0x3FFFFFFF) < 8209 )
  {
    v21 = 8209;
    if ( 2 * (v102 & 0x3FFFFFFF) > 8209 )
      v21 = 2 * (v102 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v100, v21, 16);
    v20 = v101;
  }
  v22 = v20 - 8210;
  if ( v20 - 8210 >= 0 )
  {
    v23 = &v100[16 * v22 + 131356];
    do
    {
      v24 = *(_DWORD *)v23;
      *((_DWORD *)v23 - 1) = 0;
      if ( v24 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v23 - 12),
          40 * (v24 & 0x3FFFFFFF));
      *(_QWORD *)(v23 - 12) = 0i64;
      *(_DWORD *)v23 = 2147483648;
      v23 -= 16;
      --v22;
    }
    while ( v22 >= 0 );
    v20 = v101;
  }
  v25 = 8209 - v20;
  v26 = (__int64)&v100[16 * v20];
  v27 = 8209 - v20;
  if ( v25 > 0 )
  {
    do
    {
      if ( v26 )
      {
        *(_QWORD *)v26 = 0i64;
        *(_DWORD *)(v26 + 8) = 0;
        *(_DWORD *)(v26 + 12) = 2147483648;
      }
      v26 += 16i64;
      --v27;
    }
    while ( v27 );
  }
  v101 = 8209;
  v28 = 0i64;
  do
  {
    v28 += 16i64;
    *(_DWORD *)&v100[v28 - 8] = 0;
  }
  while ( v28 < 131344 );
  v29 = v121;
  result.m_enum = 0;
  if ( SLODWORD(v121->m_triangles.m_allocator.m_firstPool) > 0 )
  {
    v30 = 0i64;
    v111 = 0i64;
    while ( 1 )
    {
      v31 = *(_QWORD *)&v29->m_vertices.m_numUsed;
      v108 = v31;
      v109 = *(_DWORD *)(v30 + v31);
      if ( v9 )
      {
        v110 = *(_DWORD *)(v30 + v31 + 8);
        v32 = *(_DWORD *)(v30 + v31 + 4);
      }
      else
      {
        v110 = *(_DWORD *)(v30 + v31 + 4);
        v32 = *(_DWORD *)(v30 + v31 + 8);
      }
      LODWORD(v111) = v32;
      v112 = 0i64;
      v113 = 0i64;
      v114 = 0i64;
      v33 = 0i64;
      do
      {
        v34 = *(&v109 + v33);
        v35 = (__m128 **)&array[8 * v34];
        if ( !*(_QWORD *)&array[8 * v34] )
        {
          v36 = v8->m_vertices.m_allocator.m_firstPool;
          if ( !v36 || !v36->m_free )
          {
            v36 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v8->m_vertices.m_allocator);
            v29 = v121;
          }
          if ( v36 )
          {
            v37 = v36->m_free;
            v36->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v37->m_data;
            v37->m_pool = v36;
            ++v36->m_used;
            *(_QWORD *)&v37->m_data[80] = -1i64;
            *(_QWORD *)&v37->m_data[8] = 0i64;
            *(_QWORD *)v37->m_data = v8->m_vertices.m_used;
            v38 = v8->m_vertices.m_used;
            if ( v38 )
              v38->m_prev = (hkgpMeshBase::Vertex *)v37;
            ++v8->m_vertices.m_numUsed;
            v8->m_vertices.m_used = (hkgpMeshBase::Vertex *)v37;
          }
          else
          {
            v37 = 0i64;
          }
          *v35 = (__m128 *)v37;
          *(_OWORD *)&v37->m_data[16] = *(_OWORD *)&v29->m_vertices.m_allocator.m_firstPool->m_items[0].m_data[16 * v34];
          (*v35)[4] = 0i64;
          v39 = *v35;
          if ( v99 )
          {
            v39[2] = v39[1];
          }
          else
          {
            v40 = v39[1];
            v39[2] = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v10->m_col0.m_quad), v10->m_col3.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v39[1], v40, 85), v10->m_col1.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v10->m_col2.m_quad));
          }
          (*v35)[2] = _mm_shuffle_ps(
                        (*v35)[2],
                        _mm_unpackhi_ps((*v35)[2], _mm_shuffle_ps((*v35)[1], (*v35)[1], 255)),
                        196);
        }
        *(&v111 + ++v33) = (__int64)*v35;
      }
      while ( v33 < 3 );
      v41 = (__int64)v112;
      v42 = v114;
      v43 = v113;
      v44 = v112[2];
      v45 = v108;
      v46 = _mm_sub_ps(v114[2], v44);
      v47 = _mm_sub_ps(v113[2], v44);
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v46));
      v49 = _mm_shuffle_ps(v48, v48, 201);
      v50 = _mm_mul_ps(v49, v49);
      v51 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
              _mm_shuffle_ps(v50, v50, 170));
      v52 = _mm_rsqrt_ps(v51);
      v53 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v51), (__m128)0i64);
      v54 = _mm_or_ps(
              _mm_and_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v51, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                      _mm_mul_ps(v52, *(__m128 *)_xmm))),
                  v49),
                v53),
              _mm_andnot_ps(v53, v49));
      if ( _mm_movemask_ps(v53) )
        break;
LABEL_94:
      v9 = (char)v123;
      v30 = v111 + 16;
      ++result.m_enum;
      v111 += 16i64;
      if ( result.m_enum >= SLODWORD(v29->m_triangles.m_allocator.m_firstPool) )
        goto LABEL_95;
    }
    v55 = v8->m_triangles.m_allocator.m_firstPool;
    v56 = _mm_mul_ps(v44, v54);
    v57 = (signed __int64)&v8->m_triangles;
    v58 = _mm_shuffle_ps(
            v54,
            _mm_unpackhi_ps(
              v54,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170)))),
            196);
    if ( !v55 || !v55->m_free )
    {
      v55 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v8->m_triangles.m_allocator);
      v29 = v121;
    }
    if ( v55 )
    {
      v59 = v55->m_free;
      v55->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v59->m_data;
      v59->m_pool = v55;
      ++v55->m_used;
      *(_QWORD *)&v59->m_data[8] = 0i64;
      *(_QWORD *)v59->m_data = *(_QWORD *)(v57 + 8);
      v60 = *(_QWORD *)(v57 + 8);
      if ( v60 )
        *(_QWORD *)(v60 + 8) = v59;
      ++*(_DWORD *)(v57 + 16);
      *(_QWORD *)(v57 + 8) = v59;
    }
    else
    {
      v59 = 0i64;
    }
    v61 = v111;
    v62 = 0;
    v63 = *(_DWORD *)(v111 + v45 + 4);
    v65 = __OFSUB__(*(_DWORD *)(v111 + v45), v63);
    v64 = *(_DWORD *)(v111 + v45) - v63 < 0;
    v66 = 2;
    *(_DWORD *)&v59->m_data[80] = (unsigned __int8)(v64 ^ v65);
    *(_QWORD *)&v59->m_data[40] = 0i64;
    *(_QWORD *)&v59->m_data[48] = 0i64;
    *(_QWORD *)&v59->m_data[56] = 0i64;
    v67 = *(_DWORD *)(v61 + *(_QWORD *)&v29->m_vertices.m_numUsed + 12);
    *(_QWORD *)&v59->m_data[96] = 0i64;
    *(_DWORD *)&v59->m_data[88] = v67;
    *(__m128 *)&v59->m_data[64] = v58;
    *(_QWORD *)&v59->m_data[16] = v41;
    v68 = 0i64;
    *(_QWORD *)&v59->m_data[24] = v43;
    *(_QWORD *)&v59->m_data[32] = v42;
    v108 = 0i64;
    v69 = 16i64;
    while ( 1 )
    {
      v70 = *(hkVector4f **)&v59->m_data[v69 + 16];
      v71 = *(hkVector4f **)&v59->m_data[v68 + 16];
      LODWORD(v117) = 0;
      v115 = v70;
      v116 = v71;
      LODWORD(v118) = 0;
      v72 = (signed int)v70;
      v73 = (signed int)v71;
      v74 = (signed int)v71;
      if ( (signed int)v70 > (signed int)v71 )
      {
        v72 = (signed int)v71;
        v74 = (signed int)v70;
      }
      v75 = v101;
      v76 = (95564881 * v74 ^ 45564901 * v72) % 5564887;
      v77 = 0;
      v78 = 0i64;
      v79 = (__int64)&v100[16 * (v76 % v101)];
      v80 = *(signed int *)(v79 + 8);
      if ( v80 <= 0 )
      {
LABEL_71:
        v84 = (signed int)v70;
        if ( (signed int)v70 > (signed int)v71 )
        {
          v84 = (signed int)v71;
          v73 = (signed int)v70;
        }
        ++v103;
        v85 = (95564881 * v73 ^ 45564901 * v84) % 5564887;
        v86 = (__int64)&v100[16 * (v85 % v75)];
        if ( *(_DWORD *)(v86 + 8) == (*(_DWORD *)(v86 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v100[16 * (v85 % v75)],
            40);
        v87 = *(_QWORD *)v86 + 40i64 * *(signed int *)(v86 + 8);
        if ( v87 )
        {
          *(_QWORD *)v87 = 0i64;
          *(_QWORD *)(v87 + 8) = 0i64;
          *(_QWORD *)(v87 + 16) = 0i64;
          *(_DWORD *)(v87 + 24) = 0;
          *(_DWORD *)(v87 + 32) = 0;
        }
        v88 = *(signed int *)(v86 + 8);
        v89 = *(_QWORD *)v86;
        v90 = 5 * v88;
        *(_DWORD *)(v86 + 8) = v88 + 1;
        v91 = v117;
        *(_QWORD *)(v89 + 8 * v90) = v70;
        *(_QWORD *)(v89 + 8 * v90 + 8) = v71;
        *(_QWORD *)(v89 + 8 * v90 + 16) = 0i64;
        *(_QWORD *)(v89 + 8 * v90 + 24) = v91;
        *(_QWORD *)(v89 + 8 * v90 + 32) = v118;
        v92 = 5i64 * (*(_DWORD *)(v86 + 8) - 1);
        v93 = *(_QWORD *)v86;
        v68 = v108;
        v83 = v93 + 8 * v92;
      }
      else
      {
        v81 = *(hkVector4f ***)v79;
        v82 = *(hkVector4f ***)v79;
        while ( (v70 != *v82 || v71 != v82[1]) && (v70 != v82[1] || v71 != *v82) )
        {
          ++v78;
          ++v77;
          v82 += 5;
          if ( v78 >= v80 )
            goto LABEL_70;
        }
        if ( v77 == -1 || (v83 = (signed __int64)&v81[5 * v77]) == 0 )
        {
LABEL_70:
          v75 = v101;
          goto LABEL_71;
        }
      }
      if ( ++*(_DWORD *)(v83 + 32) == 1 )
        break;
      if ( *(_DWORD *)(v83 + 32) == 2 )
      {
        if ( v70 == *(hkVector4f **)(v83 + 8) && v71 == *(hkVector4f **)v83 )
        {
          *(_QWORD *)&v59->m_data[8 * v66 + 40] = *(_QWORD *)(v83 + 16) + *(unsigned int *)(v83 + 24);
          v94 = *(_QWORD *)(v83 + 16);
          if ( v94 )
            *(_QWORD *)(v94 + 8i64 * *(signed int *)(v83 + 24) + 40) = (char *)v59 + (unsigned int)v66;
          if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
          {
            *(_QWORD *)(v83 + 16) = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
          }
          else
          {
            DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
            `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
            *(_QWORD *)(v83 + 16) = 0i64;
          }
          v95 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                + 1);
          goto LABEL_91;
        }
        hkgpMesh::reportInvalidEdgeWinding(retaddr, v70 + 2, v71 + 2);
      }
      else
      {
        hkgpMesh::reportDuplicatedEdge(retaddr, v70 + 2, v71 + 2);
      }
LABEL_92:
      v66 = v62;
      v69 = v68;
      v68 += 8i64;
      ++v62;
      v108 = v68;
      if ( v62 >= 3 )
      {
        v8 = retaddr;
        v10 = (hkMatrix4f *)v122;
        v29 = v121;
        goto LABEL_94;
      }
    }
    LODWORD(v119) = v66;
    v95 = v119;
    *(_QWORD *)(v83 + 16) = v59;
LABEL_91:
    *(_QWORD *)(v83 + 24) = v95;
    goto LABEL_92;
  }
LABEL_95:
  hkgpMesh::invalidateConvexHull(v8);
  v96 = (signed int)(v101 - 1);
  if ( (signed int)(v101 - 1) >= 0 )
  {
    v97 = &v100[16 * (v101 - 1) + 12];
    do
    {
      v98 = *(_DWORD *)v97;
      *((_DWORD *)v97 - 1) = 0;
      if ( v98 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v97 - 12),
          40 * (v98 & 0x3FFFFFFF));
      *(_QWORD *)(v97 - 12) = 0i64;
      *(_DWORD *)v97 = 2147483648;
      v97 -= 16;
      --v96;
    }
    while ( v96 >= 0 );
  }
  v101 = 0;
  if ( v102 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v100,
      16 * v102);
  v100 = 0i64;
  v106 = 0;
  v102 = 2147483648;
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v107);
}

// File Line: 1483
// RVA: 0xCCB9A0
void __fastcall hkgpMesh::appendFromConvexHull(hkgpMesh *this, hkgpConvexHull *hull)
{
  hkgpMesh *v2; // rbx
  hkGeometry geometry; // [rsp+30h] [rbp-38h]

  v2 = this;
  geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
  geometry.m_vertices.m_data = 0i64;
  geometry.m_vertices.m_size = 0;
  geometry.m_vertices.m_capacityAndFlags = 2147483648;
  geometry.m_triangles.m_data = 0i64;
  geometry.m_triangles.m_size = 0;
  geometry.m_triangles.m_capacityAndFlags = 2147483648;
  hkgpConvexHull::generateGeometry(hull, 0, &geometry, -1, 1);
  hkgpMesh::appendFromGeometry(v2, &geometry, (hkTransformf *)&transform, -1, 0, 1);
  geometry.m_triangles.m_size = 0;
  if ( geometry.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometry.m_triangles.m_data,
      16 * geometry.m_triangles.m_capacityAndFlags);
  geometry.m_triangles.m_data = 0i64;
  geometry.m_triangles.m_capacityAndFlags = 2147483648;
  geometry.m_vertices.m_size = 0;
  if ( geometry.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
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
int hkgpMesh::setPartIdAsConvexQuads(...)
{
  hkgpMeshBase::Triangle *v4; // rax
  char *v5; // rdx
  hkgpMesh *v6; // rbp
  char *v7; // rcx
  hkgpMeshBase::Triangle *v8; // r9
  unsigned int v9; // ebx
  hkgpMeshBase::Vertex *v10; // rax
  signed int v11; // edx
  float *v12; // rcx
  float v13; // xmm0_4
  hkgpMeshBase::Triangle *v14; // r10
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v15; // rax
  signed int v16; // edi
  float v17; // xmm6_4
  __m128 *v18; // r11
  __m128 v19; // xmm5
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
  hkgpMeshBase::Triangle *v35; // rcx
  char *v36; // rax
  char *v37; // rdx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v39; // [rsp+20h] [rbp-38h]
  char v40; // [rsp+60h] [rbp+8h]
  float v41; // [rsp+68h] [rbp+10h]

  v41 = minCosAngle;
  v4 = this->m_triangles.m_used;
  v5 = &v40;
  v6 = this;
  if ( !v4 )
    v5 = 0i64;
  if ( v5 )
  {
    do
    {
      v4->m_partId = -1;
      v4 = v4->m_next;
      v7 = &v40;
      if ( !v4 )
        v7 = 0i64;
    }
    while ( v7 );
  }
  v8 = v6->m_triangles.m_used;
  v39.m_edge.m_index = 0;
  v9 = 0;
  v39.m_edge.m_triangle = v8;
  _mm_store_si128((__m128i *)&v39, (__m128i)v39);
  if ( v8 )
  {
    v10 = v8->m_vertices[1];
    v11 = 0;
    v12 = v10->m_position.m_quad.m128_f32;
    do
    {
      v13 = *(float *)((char *)v12 + (char *)v8->m_vertices[0] - (char *)v10);
      if ( v13 < *v12 )
        break;
      if ( v13 > *v12 )
      {
        if ( v8->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v39);
        break;
      }
      ++v11;
      ++v12;
    }
    while ( v11 < 3 );
  }
  v14 = v39.m_edge.m_triangle;
  v15 = &v39;
  if ( !v39.m_edge.m_triangle )
    v15 = 0i64;
  if ( v15 )
  {
    v16 = v39.m_edge.m_index;
    v17 = v41;
    do
    {
      v18 = (__m128 *)(v14->m_links[v16] & 0xFFFFFFFFFFFFFFFCui64);
      if ( v18 )
      {
        if ( v14->m_partId == -1 && v18[5].m128_i32[0] == -1 )
        {
          v19 = v14->m_plane.m_quad;
          a4.m128_f32[0] = v17;
          a4 = _mm_shuffle_ps(a4, a4, 0);
          v20 = _mm_mul_ps(v18[4], v19);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))) >= a4.m128_f32[0] )
          {
            v21 = (__m128 *)v14->m_vertices[(18i64 >> 2 * (unsigned __int8)v16) & 3];
            v22 = _mm_sub_ps(v14->m_vertices[(9i64 >> 2 * (unsigned __int8)v16) & 3]->m_position.m_quad, v21[2]);
            v23 = *(__m128 **)((v14->m_links[v16] & 0xFFFFFFFFFFFFFFFCui64)
                             + 8 * ((18i64 >> 2 * ((unsigned __int8)v14->m_links[v16] & 3u)) & 3)
                             + 16);
            v24 = _mm_sub_ps(v23[2], v21[2]);
            v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v24);
            v26 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22);
            v27 = _mm_sub_ps(v14->m_vertices[v16]->m_position.m_quad, v23[2]);
            v28 = _mm_sub_ps(v25, v26);
            v29 = _mm_sub_ps(v21[2], v23[2]);
            v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v19);
            LODWORD(v31) = (unsigned __int128)_mm_shuffle_ps(v30, v30, 0);
            v32 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v29),
                    _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v27));
            v27.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v30, v30, 85);
            a4 = _mm_shuffle_ps(v30, v30, 170);
            if ( (float)((float)(v27.m128_f32[0] + v31) + a4.m128_f32[0]) > 0.0 )
            {
              v33 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v19);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))) > 0.0 )
              {
                v18[5].m128_i32[0] = v9;
                v14->m_partId = v9++;
              }
            }
          }
        }
      }
      if ( v14 )
      {
        hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v39);
        v16 = v39.m_edge.m_index;
        v14 = v39.m_edge.m_triangle;
      }
      v34 = &v39;
      if ( !v14 )
        v34 = 0i64;
    }
    while ( v34 );
  }
  v35 = v6->m_triangles.m_used;
  v36 = &v40;
  if ( !v35 )
    v36 = 0i64;
  if ( v36 )
  {
    do
    {
      if ( v35->m_partId == -1 )
        v35->m_partId = v9++;
      v35 = v35->m_next;
      v37 = &v40;
      if ( !v35 )
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
  hkgpMeshBase::Vertex *v1; // rax
  hkgpMesh *i; // r10
  hkgpMeshBase::Triangle *v3; // r9
  __m128 v4; // xmm12
  __m128 v5; // xmm9
  __m128 **v6; // rdx
  __m128 v7; // xmm5
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
  __m128 v28; // xmm8
  __m128 *v29; // rcx
  signed __int64 v30; // r8
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm8
  __m128 v34; // xmm7
  __m128 v35; // xmm12
  __m128 v36; // xmm2
  __m128 v37; // xmm4
  __m128 v38; // xmm7
  __m128 v39; // xmm6
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm9
  __m128 v46; // xmm7
  __m128 v47; // xmm2
  __m128 v48; // xmm6
  __m128 v49; // xmm5
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  const __m128i *j; // rcx
  __m128 v54; // xmm6
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm5
  __m128 v59; // [rsp+10h] [rbp-D8h]
  __m128 v60; // [rsp+20h] [rbp-C8h]
  __m128 v61; // [rsp+30h] [rbp-B8h]

  v1 = this->m_vertices.m_used;
  for ( i = this; v1; v1 = v1->m_next )
    v1->m_normal = 0i64;
  v3 = this->m_triangles.m_used;
  v4 = (__m128)xmmword_141A710D0;
  if ( v3 )
  {
    v5 = (__m128)_xmm;
    do
    {
      v6 = (__m128 **)v3->m_vertices;
      v7 = v3->m_vertices[1]->m_position.m_quad;
      v8 = v3->m_vertices[2]->m_position.m_quad;
      v9 = _mm_sub_ps(v3->m_vertices[0]->m_position.m_quad, v7);
      v10 = _mm_sub_ps(v7, v8);
      v11 = _mm_sub_ps(v8, v3->m_vertices[0]->m_position.m_quad);
      v12 = _mm_mul_ps(v9, v9);
      v13 = _mm_mul_ps(v10, v10);
      v14 = _mm_mul_ps(v11, v11);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_andnot_ps(
              _mm_cmpleps(v15, (__m128)0i64),
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
              _mm_cmpleps(v18, (__m128)0i64),
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
      v26 = _mm_andnot_ps(_mm_cmpleps(v21, (__m128)0i64), _mm_mul_ps(v23, v21));
      v27 = _mm_mul_ps(v26, v26);
      v28 = _mm_mul_ps(v17, v4);
      v29 = &v59;
      v30 = 3i64;
      v31 = _mm_sub_ps(_mm_add_ps(v27, v24), v25);
      v32 = v28;
      v33 = _mm_mul_ps(v28, v20);
      v34 = _mm_mul_ps(v20, v4);
      v35 = v3->m_plane.m_quad;
      v36 = _mm_mul_ps(v32, v26);
      v37 = _mm_sub_ps(_mm_add_ps(v25, v24), v27);
      v38 = _mm_mul_ps(v34, v26);
      v39 = _mm_sub_ps(_mm_add_ps(v27, v25), v24);
      v40 = _mm_rcp_ps(v36);
      v41 = _mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v40, v36)), v40);
      v42 = _mm_rcp_ps(v33);
      v59 = _mm_mul_ps(v41, v31);
      v43 = _mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v42, v33)), v42);
      v44 = _mm_rcp_ps(v38);
      v60 = _mm_mul_ps(v43, v37);
      v61 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_mul_ps(v44, v38)), v44), v39);
      do
      {
        v45 = *v29;
        if ( COERCE_FLOAT(*v29) > (float)(0.0 - 1.0) && v45.m128_f32[0] < 1.0 )
        {
          v46 = _mm_andnot_ps(*(__m128 *)_xmm, v45);
          v47 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v46), *(__m128 *)_xmm);
          v48 = _mm_cmpltps(v46, *(__m128 *)_xmm);
          v49 = _mm_cmpltps(*(__m128 *)_xmm, v46);
          v50 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v47), v49), _mm_andnot_ps(v49, v46));
          v51 = _mm_or_ps(_mm_andnot_ps(v49, _mm_mul_ps(v46, v46)), _mm_and_ps(v49, v47));
          v52 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v51, *(__m128 *)coeff4), *(__m128 *)coeff3), v51),
                                *(__m128 *)coeff2),
                              v51),
                            *(__m128 *)coeff1),
                          v51),
                        *(__m128 *)coeff0),
                      v51),
                    v50),
                  v50);
          (*v6)[3] = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(
                           *(__m128 *)_xmm,
                           _mm_xor_ps(
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v48,
                                 _mm_or_ps(
                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v52, v52)), v49),
                                   _mm_andnot_ps(v49, v52))),
                               _mm_and_ps(v48, v46)),
                             _mm_and_ps(v45, *(__m128 *)_xmm))),
                         v35),
                       (*v6)[3]);
        }
        ++v6;
        ++v29;
        --v30;
      }
      while ( v30 );
      v3 = v3->m_next;
      v5 = (__m128)_xmm;
      v4 = (__m128)xmmword_141A710D0;
    }
    while ( v3 );
  }
  for ( j = (const __m128i *)i->m_vertices.m_used; j; j = (const __m128i *)j->m128i_i64[0] )
  {
    v54 = (__m128)j[3];
    v55 = _mm_mul_ps(v54, v54);
    v56 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
            _mm_shuffle_ps(v55, v55, 170));
    v57 = _mm_rsqrt_ps(v56);
    v58 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v56), (__m128)0i64);
    j[3] = (const __m128i)_mm_or_ps(
                            _mm_and_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v56, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                                    _mm_mul_ps(v57, *(__m128 *)_xmm))),
                                v54),
                              v58),
                            _mm_andnot_ps(v58, v54));
    if ( !_mm_movemask_ps(v58) )
      j[3] = 0i64;
    _mm_store_si128((__m128i *)&j[3], _mm_srli_si128(_mm_slli_si128(_mm_load_si128(j + 3), 4), 4));
  }
  i->m_hasPerVertexNormals = 1;
}

// File Line: 1640
// RVA: 0xCCC7B0
void __fastcall hkgpMesh::fetchAreaSortedTriangles(hkgpMesh *this, hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles, bool resetPlaneId)
{
  int v3; // eax
  int v4; // er9
  bool v5; // di
  hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *v6; // rbx
  hkgpMesh *v7; // rsi
  hkgpMeshBase::Triangle *i; // rdx
  signed int v9; // er8
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = triangles->m_capacityAndFlags;
  triangles->m_size = 0;
  v4 = this->m_triangles.m_numUsed;
  v5 = resetPlaneId;
  v6 = triangles;
  v7 = this;
  if ( (v3 & 0x3FFFFFFF) < v4 )
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, triangles, v4, 8);
  for ( i = v7->m_triangles.m_used; i; i = i->m_next )
  {
    if ( v5 )
      i->m_planeId = -1;
    v6->m_data[v6->m_size++] = i;
  }
  v9 = v6->m_size;
  if ( v9 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpMeshBase::Triangle *,hkgpMesh::SortByArea>(v6->m_data, 0, v9 - 1, 0);
}

// File Line: 1653
// RVA: 0xCCC860
void __usercall hkgpMesh::appendConcaveEdges(hkgpMesh *this@<rcx>, float minConcavity@<xmm1>, float extrusion@<xmm2>, hkgpMesh *mesh@<r9>, __int64 a5@<rbx>)
{
  hkgpMesh *v5; // rbx
  hkgpMesh *v6; // r13
  int v7; // eax
  int v8; // er9
  hkgpMeshBase::Triangle *i; // rbx
  signed int v10; // edi
  hkgpMeshBase::Vertex *v11; // r8
  signed int v12; // edx
  hkgpMeshBase::Vertex *v13; // rcx
  signed __int64 v14; // r8
  float *v15; // rax
  float v16; // xmm0_4
  hkgpMeshBase::Triangle **v17; // rcx
  __int64 v18; // rax
  int v19; // ebx
  int v20; // er9
  __m128 v21; // xmm10
  __int64 v22; // r9
  __int64 v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm9
  __m128 v26; // xmm7
  __m128 v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm5
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  int v33; // er12
  __m128 v34; // xmm8
  float v35; // xmm9_4
  __int64 v36; // r15
  __int64 v37; // rcx
  __int64 v38; // r8
  __m128 *v39; // rdx
  __m128 *v40; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v41; // rax
  __m128 v42; // xmm6
  __m128 v43; // xmm7
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v44; // rdi
  hkgpMeshBase::Vertex *v45; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v46; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v47; // rsi
  hkgpMeshBase::Vertex *v48; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v49; // rax
  hkgpMeshBase::Triangle *v50; // rbx
  hkgpMeshBase::Triangle *v51; // rax
  __int64 v52; // rcx
  __int64 v53; // rax
  __int64 v54; // rcx
  __int64 v55; // rax
  __int64 v56; // rdx
  __int64 v57; // rax
  __int64 array; // [rsp+28h] [rbp-79h]
  int v59; // [rsp+30h] [rbp-71h]
  int v60; // [rsp+34h] [rbp-6Dh]
  __int64 v61; // [rsp+38h] [rbp-69h]
  int v62; // [rsp+40h] [rbp-61h]
  int v63; // [rsp+44h] [rbp-5Dh]
  __m128i v64; // [rsp+48h] [rbp-59h]
  __int128 v65; // [rsp+58h] [rbp-49h]
  char v66; // [rsp+68h] [rbp-39h]
  __int64 v67; // [rsp+110h] [rbp+6Fh]
  float v68; // [rsp+118h] [rbp+77h]
  hkResult result; // [rsp+120h] [rbp+7Fh]

  result.m_enum = LODWORD(extrusion);
  v68 = minConcavity;
  v67 = a5;
  v5 = mesh;
  v6 = this;
  v60 = 2147483648;
  v63 = 2147483648;
  v7 = mesh->m_triangles.m_numUsed;
  array = 0i64;
  v59 = 0;
  v8 = 3 * v7;
  v61 = 0i64;
  v62 = 0;
  if ( 3 * v7 > 0 )
  {
    if ( v8 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v8, 16);
  }
  for ( i = v5->m_triangles.m_used; i; i = i->m_next )
  {
    v10 = 0;
    do
    {
      v11 = i->m_vertices[v10];
      v64.m128i_i64[0] = (__int64)i;
      v64.m128i_i32[2] = v10;
      v12 = 0;
      v13 = i->m_vertices[(9i64 >> 2 * (unsigned __int8)v10) & 3];
      v14 = (char *)v11 - (char *)v13;
      v15 = v13->m_position.m_quad.m128_f32;
      do
      {
        v16 = *(float *)((char *)v15 + v14);
        if ( v16 < *v15 )
          break;
        if ( v16 > *v15 )
        {
          if ( i->m_links[v10] & 0xFFFFFFFFFFFFFFFCui64 )
            goto LABEL_20;
          break;
        }
        ++v12;
        ++v15;
      }
      while ( v12 < 3 );
      if ( i->m_links[v10] & 0xFFFFFFFFFFFFFFFCui64 )
      {
        _mm_store_si128((__m128i *)&v65, v64);
        if ( COERCE_FLOAT(*hkgpMesh::tetrahedronVolume6((hkSimdFloat32 *)&v66, (hkgpMeshBase::Edge *)&v65)) > 0.0 )
        {
          if ( v59 == (v60 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v17 = (hkgpMeshBase::Triangle **)(array + 16i64 * v59);
          if ( v17 )
          {
            v18 = v64.m128i_i64[1];
            *v17 = i;
            v17[1] = (hkgpMeshBase::Triangle *)v18;
          }
          ++v59;
        }
      }
LABEL_20:
      ++v10;
    }
    while ( v10 < 3 );
  }
  v19 = v59;
  if ( (v63 & 0x3FFFFFFF) < v59 )
  {
    v20 = v59;
    if ( v59 < 2 * (v63 & 0x3FFFFFFF) )
      v20 = 2 * (v63 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v61, v20, 16);
  }
  v62 = v19;
  v21 = 0i64;
  v22 = 0i64;
  if ( v59 > 0 )
  {
    v23 = 0i64;
    do
    {
      v22 = (unsigned int)(v22 + 1);
      v23 += 16i64;
      v24 = _mm_mul_ps(
              *(__m128 *)((*(_QWORD *)(*(_QWORD *)(array + v23 - 16) + 8i64 * *(signed int *)(array + v23 - 8) + 40) & 0xFFFFFFFFFFFFFFFCui64)
                        + 64),
              *(__m128 *)(*(_QWORD *)(array + v23 - 16) + 64i64));
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
              _mm_shuffle_ps(v24, v24, 170));
      v26 = _mm_andnot_ps(*(__m128 *)_xmm, v25);
      v27 = _mm_cmpltps(v26, *(__m128 *)_xmm);
      v28 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v26), *(__m128 *)_xmm);
      v29 = _mm_cmpltps(*(__m128 *)_xmm, v26);
      v30 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v28), v29), _mm_andnot_ps(v29, v26));
      v31 = _mm_or_ps(_mm_andnot_ps(v29, _mm_mul_ps(v26, v26)), _mm_and_ps(v29, v28));
      v32 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v31, *(__m128 *)coeff4), *(__m128 *)coeff3), v31),
                            *(__m128 *)coeff2),
                          v31),
                        *(__m128 *)coeff1),
                      v31),
                    *(__m128 *)coeff0),
                  v31),
                v30),
              v30);
      *(__m128 *)(v61 + v23 - 16) = _mm_sub_ps(
                                      *(__m128 *)_xmm,
                                      _mm_xor_ps(
                                        _mm_or_ps(
                                          _mm_andnot_ps(
                                            v27,
                                            _mm_or_ps(
                                              _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v32, v32)), v29),
                                              _mm_andnot_ps(v29, v32))),
                                          _mm_and_ps(v27, v26)),
                                        _mm_and_ps(v25, *(__m128 *)_xmm)));
      v21 = _mm_max_ps(*(__m128 *)(v61 + v23 - 16), v21);
    }
    while ( (signed int)v22 < v59 );
  }
  v33 = 0;
  v34 = _mm_shuffle_ps((__m128)LODWORD(v68), (__m128)LODWORD(v68), 0);
  LODWORD(v35) = (unsigned __int128)_mm_shuffle_ps((__m128)(unsigned int)v67, (__m128)(unsigned int)v67, 0);
  if ( v59 > 0 )
  {
    v36 = 0i64;
    do
    {
      if ( (float)(*(float *)(v61 + v36) / v21.m128_f32[0]) > v35 )
      {
        v37 = *(_QWORD *)(array + v36 + 8);
        v38 = *(_QWORD *)(array + v36);
        v39 = *(__m128 **)(v38 + 8i64 * (signed int)v37 + 16);
        v40 = *(__m128 **)(v38 + 8 * ((9i64 >> 2 * (unsigned __int8)v37) & 3) + 16);
        v41 = v6->m_vertices.m_allocator.m_firstPool;
        v42 = _mm_add_ps(v39[2], _mm_mul_ps(v39[3], v34));
        v43 = _mm_add_ps(v40[2], _mm_mul_ps(v40[3], v34));
        if ( !v41 || !v41->m_free )
          v41 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_vertices.m_allocator);
        if ( v41 )
        {
          v44 = v41->m_free;
          v41->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v44->m_data;
          v44->m_pool = v41;
          ++v41->m_used;
          *(_QWORD *)&v44->m_data[80] = -1i64;
          *(_QWORD *)&v44->m_data[8] = 0i64;
          *(_QWORD *)v44->m_data = v6->m_vertices.m_used;
          v45 = v6->m_vertices.m_used;
          if ( v45 )
            v45->m_prev = (hkgpMeshBase::Vertex *)v44;
          ++v6->m_vertices.m_numUsed;
          v6->m_vertices.m_used = (hkgpMeshBase::Vertex *)v44;
        }
        else
        {
          v44 = 0i64;
        }
        v46 = v6->m_vertices.m_allocator.m_firstPool;
        if ( !v46 || !v46->m_free )
          v46 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_vertices.m_allocator);
        if ( v46 )
        {
          v47 = v46->m_free;
          v46->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item **)v47->m_data;
          v47->m_pool = v46;
          ++v46->m_used;
          *(_QWORD *)&v47->m_data[80] = -1i64;
          *(_QWORD *)&v47->m_data[8] = 0i64;
          *(_QWORD *)v47->m_data = v6->m_vertices.m_used;
          v48 = v6->m_vertices.m_used;
          if ( v48 )
            v48->m_prev = (hkgpMeshBase::Vertex *)v47;
          ++v6->m_vertices.m_numUsed;
          v6->m_vertices.m_used = (hkgpMeshBase::Vertex *)v47;
        }
        else
        {
          v47 = 0i64;
        }
        *(__m128 *)&v44->m_data[32] = v42;
        *(__m128 *)&v47->m_data[32] = v43;
        v49 = v6->m_triangles.m_allocator.m_firstPool;
        if ( !v49 || !v49->m_free )
          v49 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_triangles.m_allocator);
        if ( v49 )
        {
          v50 = (hkgpMeshBase::Triangle *)v49->m_free;
          v49->m_free = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *)v50->m_next;
          v50[1].m_next = (hkgpMeshBase::Triangle *)v49;
          ++v49->m_used;
          v50->m_prev = 0i64;
          v50->m_next = v6->m_triangles.m_used;
          v51 = v6->m_triangles.m_used;
          if ( v51 )
            v51->m_prev = v50;
          ++v6->m_triangles.m_numUsed;
          v6->m_triangles.m_used = v50;
        }
        else
        {
          v50 = 0i64;
        }
        v50->m_vertices[0] = (hkgpMeshBase::Vertex *)v44;
        v50->m_vertices[1] = (hkgpMeshBase::Vertex *)v47;
        v50->m_vertices[2] = (hkgpMeshBase::Vertex *)v44;
        hkgpMesh::updatePlane(v6, v50);
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v53 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
          v52 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        }
        else
        {
          v52 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v53 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        }
        v50->m_links[0] = v52 + v53;
        v54 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
        {
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                    + 40) = v50;
          v54 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        }
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v55 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        }
        else
        {
          v54 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v55 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        }
        v50->m_links[1] = v54 + v55;
        v56 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
        {
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                    + 40) = (char *)v50 + 1;
          v56 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        }
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v57 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        }
        else
        {
          v56 = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v57 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        }
        v50->m_links[2] = v56 + v57;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e)
                    + 40) = (char *)v50 + 2;
      }
      ++v33;
      v36 += 16i64;
    }
    while ( v33 < v59 );
  }
  v62 = 0;
  if ( v63 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v61,
      (unsigned int)(16 * v63),
      v22);
  v61 = 0i64;
  v59 = 0;
  v63 = 2147483648;
  if ( v60 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(16 * v60),
      v22);
}

// File Line: 1725
// RVA: 0xCCCF70
__int64 __fastcall hkgpMesh::checkOverlap(hkgpMesh *this, hkgpMesh::IConvexOverlap::IConvexShape *ishape, float minDist, bool allowPenetration)
{
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *v4; // rax
  hkgpMesh *v5; // rbx
  _OWORD *v6; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // rbx
  __int128 v8; // xmm1
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle> *v10; // r9
  char *v11; // rcx
  unsigned __int64 v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  char tree[48]; // [rsp+20h] [rbp-49h]
  hkgpMesh::IConvexOverlap *v20; // [rsp+50h] [rbp-19h]
  hkgpMesh::IConvexOverlap::IConvexShape *v21; // [rsp+58h] [rbp-11h]
  __int64 v22; // [rsp+60h] [rbp-9h]
  unsigned __int8 v23; // [rsp+68h] [rbp-1h]
  bool v24; // [rsp+69h] [rbp+0h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+70h] [rbp+7h]
  __int128 v26; // [rsp+90h] [rbp+27h]
  char v27; // [rsp+A0h] [rbp+37h]

  v20 = this->m_iconvexoverlap;
  v4 = ishape->vfptr;
  v21 = ishape;
  *(__m128 *)&tree[32] = _mm_shuffle_ps((__m128)LODWORD(minDist), (__m128)LODWORD(minDist), 0);
  v5 = this;
  v22 = 0i64;
  v23 = 0;
  v24 = allowPenetration;
  v6 = (_OWORD *)v4->getBoundingBox(ishape, (hkAabb *)&v27);
  v7 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v5->m_trianglesTree;
  stackInstance.m_stack.m_size = 1;
  *(_QWORD *)tree = 0i64;
  v8 = v6[1];
  *(_OWORD *)&stackInstance.m_stack.m_localMemory = *v6;
  v26 = v8;
  stackInstance.m_stack.m_data = (unsigned __int64 *)&tree[32];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 2147483648;
  *(_DWORD *)&tree[24] = 64;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (char *)v9->m_cur;
  v12 = (unsigned __int64)(v11 + 512);
  if ( v9->m_slabSize < 512 || (void *)v12 > v9->m_end )
    v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 512);
  else
    v9->m_cur = (void *)v12;
  *(_QWORD *)tree = v11;
  *(_QWORD *)&tree[16] = v11;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle>>(
    v7,
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
  if ( *(_DWORD *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      8 * *(_DWORD *)&tree[12]);
  return v23;
}

// File Line: 1737
// RVA: 0xCCD110
__int64 __fastcall hkgpMesh::enumerateOverlaps(hkgpMesh *this, hkgpMesh::IConvexOverlap::IConvexShape *ishape, hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles, float minDist, bool allowPenetration)
{
  hkgpMesh::IConvexOverlap::IConvexShapeVtbl *v5; // rax
  hkgpMesh *v6; // rbx
  _OWORD *v7; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v8; // rbx
  __int128 v9; // xmm1
  hkLifoAllocator *v10; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle> *v11; // r9
  char *v12; // rcx
  unsigned __int64 v13; // rdx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // er8
  char tree[48]; // [rsp+20h] [rbp-51h]
  hkgpMesh::IConvexOverlap *v21; // [rsp+50h] [rbp-21h]
  hkgpMesh::IConvexOverlap::IConvexShape *v22; // [rsp+58h] [rbp-19h]
  hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *v23; // [rsp+60h] [rbp-11h]
  unsigned __int8 v24; // [rsp+68h] [rbp-9h]
  bool v25; // [rsp+69h] [rbp-8h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+70h] [rbp-1h]
  __int128 v27; // [rsp+90h] [rbp+1Fh]
  char v28; // [rsp+A0h] [rbp+2Fh]

  v21 = this->m_iconvexoverlap;
  v22 = ishape;
  *(__m128 *)&tree[32] = _mm_shuffle_ps((__m128)LODWORD(minDist), (__m128)LODWORD(minDist), 0);
  v25 = allowPenetration;
  v5 = ishape->vfptr;
  v6 = this;
  v24 = 0;
  v23 = triangles;
  v7 = (_OWORD *)v5->getBoundingBox(ishape, (hkAabb *)&v28);
  v8 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v6->m_trianglesTree;
  stackInstance.m_stack.m_size = 1;
  v9 = v7[1];
  *(_OWORD *)&stackInstance.m_stack.m_localMemory = *v7;
  v27 = v9;
  stackInstance.m_stack.m_data = (unsigned __int64 *)&tree[32];
  *(_DWORD *)&tree[12] = 2147483648;
  *(_QWORD *)tree = 0i64;
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[24] = 64;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (char *)v10->m_cur;
  v13 = (unsigned __int64)(v12 + 512);
  if ( v10->m_slabSize < 512 || (void *)v13 > v10->m_end )
    v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, 512);
  else
    v10->m_cur = (void *)v13;
  *(_QWORD *)tree = v12;
  *(_QWORD *)&tree[16] = v12;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<CollideShapeTriangle>>(
    v8,
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
  if ( *(_DWORD *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      8 * *(_DWORD *)&tree[12]);
  return v24;
}

// File Line: 1750
// RVA: 0xCCD2B0
bool __fastcall hkgpMesh::isConcave(hkgpMesh *this, hkgpMeshBase::Edge *edge, float eps)
{
  hkgpMeshBase::Edge v4; // [rsp+20h] [rbp-38h]
  char v5; // [rsp+30h] [rbp-28h]

  v4 = *edge;
  return COERCE_FLOAT(*hkgpMesh::tetrahedronVolume6((hkSimdFloat32 *)&v5, &v4)) < COERCE_FLOAT(
                                                                                    _mm_shuffle_ps(
                                                                                      (__m128)LODWORD(eps),
                                                                                      (__m128)LODWORD(eps),
                                                                                      0));
}

// File Line: 1756
// RVA: 0xCCD300
hkSimdFloat32 *__fastcall hkgpMesh::tetrahedronVolume6(hkSimdFloat32 *result, hkgpMeshBase::Edge *edge)
{
  __int64 v2; // r11
  hkgpMeshBase::Triangle *v3; // r10
  hkSimdFloat32 *v4; // rbx
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // r8
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm1
  hkgpMeshBase::Vertex *v9; // rax
  __m128 v10; // xmm0
  __m128 *v11; // rax
  hkMatrix3f v12; // [rsp+20h] [rbp-38h]

  v2 = (signed int)edge->m_index;
  v3 = edge->m_triangle;
  v4 = result;
  v5 = edge->m_triangle->m_links[v2] & 3;
  v6 = edge->m_triangle->m_links[v2] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v6 )
  {
    v8 = v3->m_vertices[v2]->m_position.m_quad;
    v9 = v3->m_vertices[(18i64 >> 2 * (unsigned __int8)v2) & 3];
    v12.m_col0.m_quad = _mm_sub_ps(*(__m128 *)(*(_QWORD *)(v6 + 8i64 * (signed int)v5 + 16) + 32i64), v8);
    v10 = v9->m_position.m_quad;
    v11 = *(__m128 **)(v6 + 8 * ((18i64 >> 2 * (unsigned __int8)v5) & 3) + 16);
    v12.m_col1.m_quad = _mm_sub_ps(v10, v8);
    v12.m_col2.m_quad = _mm_sub_ps(v11[2], v8);
    hkMatrix3f::getDeterminant(&v12, result);
    v7 = v4;
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
hkgpMeshBase::Triangle *__fastcall hkgpMesh::createTriangle(hkgpMesh *this, hkgpMeshBase::Vertex *a, hkgpMeshBase::Vertex *b, hkgpMeshBase::Vertex *c)
{
  hkgpMesh *v4; // r14
  hkgpMeshBase::Vertex *v5; // rbx
  hkgpMeshBase::Vertex *v6; // rdi
  hkgpMeshBase::Vertex *v7; // rsi
  hkgpMeshBase::Triangle *v8; // rax
  hkgpMeshBase::Triangle *v9; // rbp

  v4 = this;
  v5 = c;
  v6 = b;
  v7 = a;
  v8 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
  v9 = v8;
  v8->m_partId = -1;
  v8->m_links[0] = 0i64;
  v8->m_links[1] = 0i64;
  v8->m_links[2] = 0i64;
  v8->m_vertices[0] = v7;
  v8->m_vertices[1] = v6;
  v8->m_vertices[2] = v5;
  hkgpMesh::setPlane(v4, &v7->m_position, &v6->m_position, &v5->m_position, &v8->m_plane, 1);
  return v9;
}

// File Line: 1780
// RVA: 0xCCD450
hkgpMeshBase::Edge *__fastcall hkgpMesh::findEdge(hkgpMesh *this, hkgpMeshBase::Edge *result, hkgpMeshBase::Vertex *s, hkgpMeshBase::Vertex *e)
{
  hkgpMeshBase::Triangle *v4; // r10
  hkgpMeshBase::Triangle *v5; // rbx
  hkgpMeshBase::Vertex *v6; // r11
  hkgpMeshBase::Edge *v7; // rdi
  signed int v8; // er9
  signed int v9; // ecx
  __int64 v10; // rax
  signed __int64 v11; // rdx
  __int64 v13; // rax

  v4 = this->m_triangles.m_used;
  v5 = 0i64;
  v6 = e;
  v7 = result;
  if ( v4 )
  {
    while ( 2 )
    {
      v8 = 2;
      v9 = 0;
      v10 = 0i64;
      v11 = 16i64;
      do
      {
        if ( *(hkgpMeshBase::Vertex **)((char *)v4->m_vertices + v11) == s && v4->m_vertices[v10] == v6 )
        {
          v7->m_triangle = v4;
          v7->m_index = v8;
          return v7;
        }
        v8 = v9++;
        v11 = v10 * 8;
        ++v10;
      }
      while ( v9 < 3 );
      v4 = v4->m_next;
      if ( v4 )
        continue;
      break;
    }
  }
  if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
  {
    v5 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
  }
  else
  {
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
  }
  v13 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
        + 1);
  v7->m_triangle = v5;
  *(_QWORD *)&v7->m_index = v13;
  return v7;
}

// File Line: 1793
// RVA: 0xCCD510
hkgpMeshBase::Edge *__fastcall hkgpMesh::flipEdge(hkgpMesh *this, hkgpMeshBase::Edge *result, hkgpMeshBase::Edge *e)
{
  __int64 v3; // rcx
  hkgpMeshBase::Edge *v4; // r11
  hkgpMeshBase::Triangle *v5; // r8
  hkgpMeshBase::Edge *v6; // rdi
  signed __int64 v7; // r14
  unsigned __int64 v8; // rbx
  char v9; // cl
  unsigned __int64 v10; // rbp
  signed __int64 v11; // r13
  unsigned __int64 v12; // r15
  int v13; // eax
  signed __int64 v14; // r10
  unsigned __int64 v15; // r9
  unsigned __int64 v16; // r12
  hkgpMeshBase::Triangle *v17; // r8
  __int64 v18; // rax
  hkgpMeshBase::Triangle *v19; // r10
  int v20; // edx
  hkgpMeshBase::Edge *v21; // rax
  hkgpMeshBase::Triangle *v22; // rax
  unsigned int v23; // [rsp+0h] [rbp-58h]
  int v24; // [rsp+4h] [rbp-54h]
  __int64 v25; // [rsp+8h] [rbp-50h]
  unsigned __int64 v26; // [rsp+10h] [rbp-48h]
  _QWORD *v27; // [rsp+18h] [rbp-40h]
  unsigned int v28; // [rsp+70h] [rbp+18h]
  unsigned int v29; // [rsp+78h] [rbp+20h]

  v3 = (signed int)e->m_index;
  v4 = e;
  v5 = e->m_triangle;
  v6 = result;
  v25 = v3;
  v7 = v5->m_links[v3] & 3;
  v8 = v5->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v8 )
  {
    v9 = 2 * v3;
    v26 = v5->m_links[(9 >> v9) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v28 = v5->m_links[(9 >> v9) & 3] & 3;
    v10 = v5->m_links[(18 >> v9) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v11 = v5->m_links[(18 >> v9) & 3] & 3;
    v24 = (9 >> 2 * v7) & 3;
    v27 = (_QWORD *)(v8 + 8 * (v24 + 5i64));
    v12 = *v27 & 0xFFFFFFFFFFFFFFFCui64;
    v23 = *v27 & 3;
    v13 = (18 >> 2 * v7) & 3;
    v14 = v8 + 8i64 * v13;
    v15 = v8 + (unsigned int)v13;
    v16 = *(_QWORD *)(v14 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v29 = *(_QWORD *)(v14 + 40) & 3;
    v5->m_vertices[v25] = *(hkgpMeshBase::Vertex **)(v8 + 8 * ((18i64 >> 2 * (unsigned __int8)v7) & 3) + 16);
    *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 16) = v4->m_triangle->m_vertices[(18i64 >> 2 * (unsigned __int8)v4->m_index) & 3];
    v17 = v4->m_triangle;
    v18 = (18 >> 2 * v4->m_index) & 3;
    v17->m_links[v18] = v15;
    *(_QWORD *)(v14 + 40) = (char *)v17 + (unsigned int)v18;
    v19 = v4->m_triangle;
    v20 = (9 >> 2 * v4->m_index) & 3;
    v4->m_triangle->m_links[v20] = v26 + v28;
    if ( v26 )
      *(_QWORD *)(v26 + 8i64 * (signed int)v28 + 40) = (char *)v19 + (unsigned int)v20;
    v4->m_triangle->m_links[v4->m_index] = v16 + v29;
    if ( v16 )
      *(_QWORD *)(v16 + 8i64 * (signed int)v29 + 40) = (char *)v4->m_triangle + v4->m_index;
    *v27 = v12 + v23;
    if ( v12 )
      *(_QWORD *)(v12 + 8i64 * (signed int)v23 + 40) = v8 + (unsigned int)v24;
    *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 40) = v10 + (unsigned int)v11;
    if ( v10 )
      *(_QWORD *)(v10 + 8i64 * (signed int)v11 + 40) = v8 + (unsigned int)v7;
    v6->m_triangle = v4->m_triangle;
    v21 = v6;
    v6->m_index = (18 >> 2 * LOBYTE(v4->m_index)) & 3;
  }
  else
  {
    if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v22 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
    }
    else
    {
      `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
      v22 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
    }
    result->m_triangle = v22;
    *(_QWORD *)&result->m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                  + 1);
    v21 = result;
  }
  return v21;
}

// File Line: 1815
// RVA: 0xCCD780
__int64 __fastcall hkgpMesh::buildPlaneIndices(hkgpMesh *this, float minCosAngle, float minDistance, bool stopAtMaterialBoundaries)
{
  bool v4; // r15
  hkgpMesh *v5; // r14
  int v7; // er13
  float v8; // xmm8_4
  float v9; // xmm7_4
  __int64 v10; // r12
  hkgpMeshBase::Triangle *v11; // rsi
  __m128 v12; // xmm3
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
  unsigned int v38; // ebx
  _QWORD *array; // [rsp+20h] [rbp-79h]
  int v40; // [rsp+28h] [rbp-71h]
  int v41; // [rsp+2Ch] [rbp-6Dh]
  hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> triangles; // [rsp+30h] [rbp-69h]
  __int64 v43; // [rsp+48h] [rbp-51h]
  __int64 v44; // [rsp+58h] [rbp-41h]
  __int64 v45; // [rsp+68h] [rbp-31h]
  __int64 v46; // [rsp+78h] [rbp-21h]
  __int64 v47; // [rsp+88h] [rbp-11h]

  v4 = stopAtMaterialBoundaries;
  v5 = this;
  this->m_planes.m_size = 0;
  this->m_planeRoots.m_size = 0;
  if ( !this->m_triangles.m_numUsed )
    return 0i64;
  triangles.m_data = 0i64;
  triangles.m_size = 0;
  triangles.m_capacityAndFlags = 2147483648;
  hkgpMesh::fetchAreaSortedTriangles(this, &triangles, 1);
  array = 0i64;
  v40 = 0;
  v41 = 2147483648;
  v7 = 0;
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(minCosAngle), (__m128)LODWORD(minCosAngle), 0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(minDistance), (__m128)LODWORD(minDistance), 0);
  if ( triangles.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = triangles.m_data[v10];
      if ( v11->m_planeId < 0 )
      {
        v12 = v11->m_plane.m_quad;
        if ( !(_mm_movemask_ps(_mm_cmpunordps(v12, v12)) & 7) )
        {
          v13 = _mm_mul_ps(v12, v12);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_SIGNED_INT(
                                             (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170)))
                                           - 1.0)) >> 1) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
          {
            v14 = v11->m_plane.m_quad;
            v15 = 0;
            v11->m_planeId = v5->m_planes.m_size;
            v40 = 0;
            LODWORD(v43) = 0;
            if ( !(v41 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
            v24 = v5->m_planes.m_capacityAndFlags & 0x3FFFFFFF;
            v40 = v21 + 1;
            if ( v5->m_planes.m_size == v24 )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_planes,
                16);
            v5->m_planes.m_data[v5->m_planes.m_size++].m_quad = v14;
            if ( v5->m_planeRoots.m_size == (v5->m_planeRoots.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_planeRoots,
                8);
            v5->m_planeRoots.m_data[v5->m_planeRoots.m_size] = v11;
            v25 = v40;
            ++v5->m_planeRoots.m_size;
            while ( v25 )
            {
              --v25;
              v26 = *(_QWORD *)(array[2 * v25] + 8i64 * SLODWORD(array[2 * v25 + 1]) + 40);
              v40 = v25;
              v27 = v26 & 3;
              v28 = v26 & 0xFFFFFFFFFFFFFFFCui64;
              if ( v28 && *(_DWORD *)(v28 + 84) == -1 && (!v4 || *(_DWORD *)(v28 + 88) == v11->m_material) )
              {
                v29 = *(__m128 *)(v28 + 64);
                v30 = _mm_mul_ps(v14, v29);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) >= v8
                  && COERCE_FLOAT((unsigned int)(2
                                               * COERCE_SIGNED_INT(
                                                   COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 255))
                                                 - COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 255)))) >> 1) <= v9 )
                {
                  v31 = 2 * v27;
                  *(_DWORD *)(v28 + 84) = v11->m_planeId;
                  v32 = v40;
                  LODWORD(v46) = (9 >> 2 * v27) & 3;
                  if ( v40 == (v41 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
  v38 = v5->m_planes.m_size;
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v41);
  array = 0i64;
  v41 = 2147483648;
  triangles.m_size = 0;
  if ( triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triangles.m_data,
      8 * triangles.m_capacityAndFlags);
  return v38;
}

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
  __m128 v2; // xmm1
  signed __int64 v3; // rax
  __m128 **v4; // rdx

  v2 = position->m_quad;
  v3 = 0i64;
  v4 = (__m128 **)t->m_vertices;
  while ( (_mm_movemask_ps(_mm_cmpeqps((*v4)[2], v2)) & 7) != 7 )
  {
    ++v3;
    ++v4;
    if ( v3 >= 3 )
      return 0;
  }
  return 1;
}

// File Line: 1888
// RVA: 0xCCDCC0
void __fastcall hkgpMesh::removeTriangle(hkgpMesh *this, hkgpMeshBase::Triangle *t)
{
  if ( t->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
    *(_QWORD *)((t->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) + 8 * (t->m_links[0] & 3) + 40) = 0i64;
  t->m_links[0] = 0i64;
  if ( t->m_links[1] & 0xFFFFFFFFFFFFFFFCui64 )
    *(_QWORD *)((t->m_links[1] & 0xFFFFFFFFFFFFFFFCui64) + 8 * (t->m_links[1] & 3) + 40) = 0i64;
  t->m_links[1] = 0i64;
  if ( t->m_links[2] & 0xFFFFFFFFFFFFFFFCui64 )
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
  hkgpMesh *v2; // r9
  float v3; // xmm6_4
  hkgpMeshBase::Triangle *v4; // rcx
  char v5; // dl
  __m128 v6; // xmm0
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
  hkgpMeshBase::Triangle *v24; // rax
  hkgpMeshBase::Triangle *v25; // r8
  hkgpMeshBase::Triangle *v26; // rdx

  v2 = this;
  LODWORD(v3) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(fsign), (__m128)LODWORD(fsign), 0);
  do
  {
    v4 = v2->m_triangles.m_used;
    v5 = 0;
    v6 = v4->m_vertices[0]->m_position.m_quad;
    v7 = _mm_sub_ps(v4->m_vertices[1]->m_position.m_quad, v6);
    v8 = _mm_sub_ps(v4->m_vertices[2]->m_position.m_quad, v6);
    v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
    v10 = _mm_shuffle_ps(v9, v9, 201);
    v11 = _mm_mul_ps(v10, v10);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    v14 = COERCE_FLOAT(
            _mm_andnot_ps(
              _mm_cmpleps(v12, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                  _mm_mul_ps(*(__m128 *)_xmm, v13)),
                v12)))
        * v3;
    if ( !v4->m_next )
      break;
    do
    {
      v4 = v4->m_next;
      v15 = v4->m_vertices[0]->m_position.m_quad;
      v16 = _mm_sub_ps(v4->m_vertices[1]->m_position.m_quad, v15);
      v17 = _mm_sub_ps(v4->m_vertices[2]->m_position.m_quad, v15);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17));
      v19 = _mm_shuffle_ps(v18, v18, 201);
      v20 = _mm_mul_ps(v19, v19);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      v22 = _mm_rsqrt_ps(v21);
      v23 = COERCE_FLOAT(
              _mm_andnot_ps(
                _mm_cmpleps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                    _mm_mul_ps(*(__m128 *)_xmm, v22)),
                  v21)))
          * v3;
      if ( v23 > v14 )
      {
        v24 = v4->m_prev;
        if ( v24 )
        {
          v25 = v4->m_next;
          v26 = v24->m_prev;
          if ( v4->m_next )
          {
            v25->m_prev = v24;
            v24->m_next = v25;
          }
          else
          {
            v24->m_next = 0i64;
          }
          if ( v26 )
          {
            v26->m_next = v4;
            v4->m_prev = v26;
          }
          else
          {
            v2->m_triangles.m_used = v4;
            v4->m_prev = 0i64;
          }
          v24->m_prev = v4;
          v4->m_next = v24;
        }
        v5 = 1;
      }
      v14 = v23;
    }
    while ( v4->m_next );
  }
  while ( v5 );
}

// File Line: 1922
// RVA: 0xCCDF10
hkSimdFloat32 *__usercall hkgpMesh::projectPointOnSurface@<rax>(hkgpMesh *this@<rcx>, hkSimdFloat32 *result@<rdx>, float offset@<xmm2>, hkVector4f *point@<r9>, __int64 a5@<rbx>, int iterations)
{
  __int64 v6; // rdi
  hkSimdFloat32 *v7; // rsi
  hkVector4f *v8; // rbx
  hkgpMesh *v9; // r14
  __m128 v10; // xmm7
  int v11; // edx
  int v12; // er9
  __m128 v13; // xmm3
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __int64 v18; // rax
  __int64 v19; // rcx
  __m128 v20; // xmm0
  hkSimdFloat32 *v21; // rax
  int v22; // er8
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  hkVector4fComparison inside; // [rsp+30h] [rbp-C0h]
  hkVector4f normal; // [rsp+40h] [rbp-B0h]
  hkSimdFloat32 v29; // [rsp+50h] [rbp-A0h]
  char *array; // [rsp+60h] [rbp-90h]
  int v31; // [rsp+68h] [rbp-88h]
  int v32; // [rsp+6Ch] [rbp-84h]
  char v33; // [rsp+70h] [rbp-80h]
  __int64 v34; // [rsp+2D0h] [rbp+1E0h]
  hkResult resulta; // [rsp+2E0h] [rbp+1F0h]

  resulta.m_enum = LODWORD(offset);
  v34 = a5;
  v6 = LODWORD(offset);
  v7 = result;
  v8 = point;
  v9 = this;
  v32 = -2147483616;
  v10 = _mm_shuffle_ps((__m128)(unsigned int)v34, (__m128)(unsigned int)v34, 0);
  *result = 0i64;
  normal.m_quad = 0i64;
  v11 = 0;
  v31 = 0;
  array = &v33;
  if ( SLODWORD(offset) > 32 )
  {
    v12 = v6;
    if ( (signed int)v6 < 64 )
      v12 = 64;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 16);
    v11 = v31;
  }
  if ( (signed int)v6 > 0 )
  {
    do
    {
      v13 = hkgpMesh::squaredDistanceToPoint(v9, &v29, v8, &normal, &inside)->m_real;
      v14 = (__m128 *)&array[16 * v31];
      v15 = _mm_rsqrt_ps(v13);
      v16 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu),
              _mm_andnot_ps(
                _mm_cmpleps(v13, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v15), v15)),
                    _mm_mul_ps(*(__m128 *)_xmm, v15)),
                  v13)));
      *v7 = (hkSimdFloat32)v16;
      v17 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v10, v16), (__m128)xmmword_141A711B0), normal.m_quad),
              v8->m_quad);
      *v8 = (hkVector4f)v17;
      *v14 = v17;
      v11 = v31++ + 1;
      --v6;
    }
    while ( v6 );
  }
  *v8 = 0i64;
  if ( v11 > 0 )
  {
    v18 = (__int64)array;
    v19 = (unsigned int)v11;
    do
    {
      v18 += 16i64;
      v8->m_quad = _mm_add_ps(v8->m_quad, *(__m128 *)(v18 - 16));
      --v19;
    }
    while ( v19 );
  }
  v20 = 0i64;
  v20.m128_f32[0] = (float)v11;
  v8->m_quad = _mm_mul_ps(v8->m_quad, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v20, v20, 0)));
  v21 = hkgpMesh::squaredDistanceToPoint(v9, &v29, v8, &normal, &inside);
  v22 = v32;
  v23 = v21->m_real;
  v24 = v21->m_real;
  v31 = 0;
  v25 = _mm_rsqrt_ps(v23);
  v7->m_real = _mm_xor_ps(
                 (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu),
                 _mm_andnot_ps(
                   _mm_cmpleps(v24, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v25), v25)),
                       _mm_mul_ps(*(__m128 *)_xmm, v25)),
                     v23)));
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v22);
  return v7;
}

// File Line: 1951
// RVA: 0xCCE1B0
hkSimdFloat32 *__fastcall hkgpMesh::projectPointOnSurface(hkgpMesh *this, hkSimdFloat32 *result, float offset, hkVector4f *projection, hkVector4f *point, int iterations)
{
  hkVector4f *v6; // rbp
  hkSimdFloat32 *v7; // rbx
  hkgpMesh *v8; // r14
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
  hkVector4f normal; // [rsp+30h] [rbp-A8h]
  hkVector4fComparison inside; // [rsp+40h] [rbp-98h]
  hkSimdFloat32 resulta; // [rsp+50h] [rbp-88h]

  v6 = projection;
  v7 = result;
  v8 = this;
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
      v13 = hkgpMesh::squaredDistanceToPoint(v8, &resulta, point, &normal, &inside);
      v14 = _mm_rsqrt_ps(v13->m_real);
      v15 = _mm_andnot_ps(
              _mm_cmpleps(v13->m_real, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13->m_real, v14), v14)),
                  _mm_mul_ps(*(__m128 *)_xmm, v14)),
                v13->m_real));
      v16 = _mm_cmpltps(v15, v10);
      v17 = _mm_xor_ps(
              _mm_max_ps(v12, _mm_or_ps(_mm_and_ps(v15, v16), _mm_andnot_ps(v16, v10))),
              (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)&inside), 0x1Fu), 0x1Fu));
      *v7 = (hkSimdFloat32)v17;
      v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v9, v17), normal.m_quad), v6->m_quad);
      point->m_quad = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                            _mm_shuffle_ps(v18, v18, 170)),
                          v6->m_quad),
                        point->m_quad);
      --v11;
    }
    while ( v11 );
  }
  return v7;
}

// File Line: 1972
// RVA: 0xCCE360
char __fastcall hkgpMesh::computeOffsetPoint(hkgpMesh *this, hkSimdFloat32 *offset, hkVector4f *normal, hkVector4f *point, int maxIterations, bool checkInside)
{
  hkVector4f *v6; // rdi
  hkVector4f *v7; // r14
  hkSimdFloat32 *v8; // r13
  hkgpMesh *v9; // r12
  float v10; // xmm12_4
  float v11; // xmm11_4
  hkgpMeshBase::Triangle *v12; // rax
  hkSimdFloat32 v13; // xmm6
  int v14; // ebx
  bool v15; // dl
  char v16; // si
  signed int v17; // eax
  hkVector4f v18; // xmm3
  signed int v19; // ecx
  signed int v20; // eax
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
  hkgpMesh::Location location; // [rsp+20h] [rbp-148h]

  location.m_region.m_type = 0;
  v6 = point;
  v7 = normal;
  v8 = offset;
  v9 = this;
  v10 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99000001), (__m128)LODWORD(FLOAT_0_99000001), 0))
      * offset->m_real.m128_f32[0];
  v11 = offset->m_real.m128_f32[0] * 4.0;
  if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
  {
    v12 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
  }
  else
  {
    `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
    v12 = 0i64;
    *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
    DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
  }
  v13.m_real = (__m128)xmmword_141A712A0;
  v14 = 0;
  location.m_region.m_feature.m_triangle = v12;
  v15 = 0;
  v16 = 1;
  *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                    + 1);
  location.m_normal = 0i64;
  location.m_pseudoNormal = 0i64;
  location.m_coordinates = 0i64;
  location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
  location.m_inside.m_real = g_vectorfConstants[0];
  if ( maxIterations > 0 )
  {
    while ( 1 )
    {
      hkgpMesh::locate(v9, v6, &location, (hkBool)1);
      if ( checkInside )
      {
        v17 = 0;
        if ( location.m_inside.m_real.m128_f32[0] < 0.0 )
          v17 = 1;
      }
      else
      {
        v17 = 0;
      }
      v13.m_real = (__m128)location.m_squaredDistance;
      v15 = v17 != 0;
      if ( (float)(location.m_squaredDistance.m_real.m128_f32[0] + 0.00000011920929) >= (float)(v10 * v10) )
        break;
      if ( v14 && v15 )
        return 0;
      v18.m_quad = (__m128)location.m_normal;
      v19 = 0;
      v20 = 0;
      v21 = _mm_mul_ps(location.m_normal.m_quad, location.m_normal.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) <= 0.00000011920929 )
        v19 = 1;
      if ( location.m_squaredDistance.m_real.m128_f32[0] <= 0.00000011920929 )
        v20 = 1;
      if ( v20 | v19 )
        v18.m_quad = v7->m_quad;
      v22 = _mm_mul_ps(v18.m_quad, v18.m_quad);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_rsqrt_ps(v23);
      v25 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v23), (__m128)0i64);
      v26 = _mm_cmpleps(v23, (__m128)0i64);
      v27 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24));
      if ( !_mm_movemask_ps(v25) )
        return 0;
      v28 = _mm_rsqrt_ps(location.m_squaredDistance.m_real);
      v29 = _mm_mul_ps(*(__m128 *)_xmm, v28);
      v30 = _mm_mul_ps(
              _mm_or_ps(
                _mm_and_ps(_mm_mul_ps(_mm_andnot_ps(v26, v27), v18.m_quad), v25),
                _mm_andnot_ps(v25, v18.m_quad)),
              v7->m_quad);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      v32 = _mm_mul_ps(_mm_mul_ps(v28, location.m_squaredDistance.m_real), v28);
      v33 = _mm_rcp_ps(v31);
      v34 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v31)), v33),
              _mm_sub_ps(
                v8->m_real,
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(location.m_squaredDistance.m_real, (__m128)0i64),
                    _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v32), v29), location.m_squaredDistance.m_real)),
                  location.m_inside.m_real)));
      if ( v31.m128_f32[0] >= 0.00000011920929 && v34.m128_f32[0] <= v11 )
      {
        ++v14;
        v6->m_quad = _mm_add_ps(_mm_mul_ps(v7->m_quad, v34), v6->m_quad);
        if ( v14 < maxIterations )
          continue;
      }
      break;
    }
  }
  v35 = _mm_rsqrt_ps(v13.m_real);
  v36 = _mm_andnot_ps(
          _mm_cmpleps(v13.m_real, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v13.m_real), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35)),
            v13.m_real));
  v6->m_quad = _mm_shuffle_ps(v6->m_quad, _mm_unpackhi_ps(v6->m_quad, v36), 196);
  if ( v15 || v36.m128_f32[0] < v10 || v36.m128_f32[0] >= v11 )
    v16 = 0;
  return v16;
}

// File Line: 2006
// RVA: 0xCCE730
void __usercall hkgpMesh::generateSurfaceSamples(hkgpMesh *this@<rcx>, hkgpMesh::SurfaceSamplingConfig *config@<rdx>, hkArray<hkVector4f,hkContainerHeapAllocator> *samplesOut@<r8>, bool useWeight@<r9b>, __m128 a5@<xmm2>)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rbx
  hkgpMesh::SurfaceSamplingConfig *v6; // rsi
  hkgpMesh *v7; // rdi
  hkgpConvexHull *v8; // rax
  hkgpMesh *v9; // r11
  hkgpConvexHull *v10; // r12
  hkgpMeshBase::Vertex *i; // rdi
  hkgpMeshBase::Triangle *v12; // r13
  __m128 v13; // xmm8
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  int v16; // eax
  unsigned __int64 *v17; // r15
  __m128 *v18; // r10
  char v19; // al
  char v20; // r9
  signed int v21; // ecx
  signed __int64 v22; // r14
  __m128 *v23; // r8
  float *v24; // rax
  float v25; // xmm0_4
  unsigned __int64 v26; // rdx
  __m128 v27; // xmm7
  __m128 *v28; // rcx
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  float v32; // xmm1_4
  float v33; // xmm0_4
  __m128 v34; // xmm3
  __m128 *v35; // rax
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm11
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm9
  int v49; // eax
  int v50; // edi
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 j; // xmm7
  int v54; // [rsp+30h] [rbp-D0h]
  hkVector4f point; // [rsp+40h] [rbp-C0h]
  unsigned int v56; // [rsp+50h] [rbp-B0h]
  hkErrStream v57; // [rsp+60h] [rbp-A0h]
  hkSimdFloat32 v58; // [rsp+80h] [rbp-80h]
  hkMatrix3f v59; // [rsp+90h] [rbp-70h]
  char buf; // [rsp+C0h] [rbp-40h]
  hkgpMesh *v61; // [rsp+370h] [rbp+270h]
  int v62; // [rsp+378h] [rbp+278h]
  hkBool result; // [rsp+388h] [rbp+288h]

  v61 = this;
  v5 = samplesOut;
  v6 = config;
  v7 = this;
  if ( useWeight )
  {
    hkErrStream::hkErrStream(&v57, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v57.vfptr, "Weighted surface sampling not implemented");
    hkError::messageWarning(-87989008, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2009);
    hkOstream::~hkOstream((hkOstream *)&v57.vfptr);
  }
  v8 = hkgpMesh::getConvexHull(v7);
  v9 = v61;
  v10 = v8;
  if ( v6->m_doVertices )
  {
    for ( i = v61->m_vertices.m_used; i; v9 = v61 )
    {
      _mm_store_si128((__m128i *)&point, (__m128i)i->m_position.m_quad);
      if ( hkgpMesh::computeOffsetPoint(v9, &v6->m_offset, &i->m_normal, &point, 8, 1)
        && (!v10 || hkgpConvexHull::isPointInside(v10, &result, &point, 0, 0.0)->m_bool) )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
        v5->m_data[v5->m_size++] = (hkVector4f)point.m_quad;
      }
      i = i->m_next;
    }
  }
  if ( v6->m_doEdges )
  {
    v12 = v9->m_triangles.m_used;
    v13 = hkVector4fComparison_maskToComparison_327[v6->m_edgeCenterOnly != 0 ? 0xF : 0];
    if ( v12 )
    {
      *(_DWORD *)&result.m_bool = 953267991;
      while ( 1 )
      {
        v14 = v12->m_plane.m_quad;
        if ( !(_mm_movemask_ps(_mm_cmpunordps(v14, v14)) & 7) )
        {
          v15 = _mm_mul_ps(v14, v14);
          a5.m128_f32[0] = 0.000099999997;
          a5 = _mm_shuffle_ps(a5, a5, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_SIGNED_INT(
                                             (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)))
                                           - 1.0)) >> 1) < a5.m128_f32[0] )
            break;
        }
LABEL_44:
        v12 = v12->m_next;
        if ( !v12 )
          return;
      }
      LOBYTE(v16) = 0;
      v17 = v12->m_links;
      v62 = 0;
      while ( 1 )
      {
        v18 = (__m128 *)*(v17 - 3);
        v19 = 2 * v16;
        v20 = v19;
        v21 = 0;
        v22 = (9i64 >> v19) & 3;
        v23 = (__m128 *)v12->m_vertices[v22];
        v24 = v23[2].m128_f32;
        do
        {
          v25 = *(float *)((char *)v24 + *(v17 - 3) - (_QWORD)v23);
          if ( v25 < *v24 )
            break;
          if ( v25 > *v24 )
          {
            if ( *v17 & 0xFFFFFFFFFFFFFFFCui64 )
              goto LABEL_43;
            break;
          }
          ++v21;
          ++v24;
        }
        while ( v21 < 3 );
        v26 = *v17;
        v27 = v12->m_plane.m_quad;
        v28 = (__m128 *)(*v17 & 0xFFFFFFFFFFFFFFFCui64);
        if ( !v28 )
          goto LABEL_31;
        v29 = v28[4];
        v56 = 953267991;
        if ( !(_mm_movemask_ps(_mm_cmpunordps(v29, v29)) & 7) )
        {
          v30 = _mm_mul_ps(v29, v29);
          a5 = _mm_shuffle_ps((__m128)v56, (__m128)v56, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_SIGNED_INT(
                                             (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170)))
                                           - 1.0)) >> 1) < a5.m128_f32[0] )
          {
            v31 = _mm_mul_ps(v28[4], v27);
            LODWORD(v32) = (unsigned __int128)_mm_shuffle_ps(v31, v31, 85);
            LODWORD(v33) = (unsigned __int128)_mm_shuffle_ps(v31, v31, 0);
            a5 = _mm_shuffle_ps(v31, v31, 170);
            if ( (float)((float)(v32 + v33) + a5.m128_f32[0]) <= v6->m_maxCosAngle.m_real.m128_f32[0] )
            {
              v27 = _mm_add_ps(v27, v28[4]);
              if ( !v6->m_discardConvex )
                goto LABEL_31;
              v34 = v18[2];
              a5 = _mm_sub_ps(v23[2], v34);
              v35 = (__m128 *)v12->m_vertices[(18i64 >> v20) & 3];
              v59.m_col0.m_quad = a5;
              v59.m_col1.m_quad = _mm_sub_ps(v35[2], v34);
              v59.m_col2.m_quad = _mm_sub_ps(
                                    *(__m128 *)(*(_QWORD *)((v26 & 0xFFFFFFFFFFFFFFFCui64)
                                                          + 8 * ((18i64 >> 2 * ((unsigned __int8)v26 & 3u)) & 3)
                                                          + 16)
                                              + 32i64),
                                    v34);
              hkMatrix3f::getDeterminant(&v59, &v58);
              if ( v58.m_real.m128_f32[0] >= 0.00000011920929 )
                break;
            }
          }
        }
LABEL_43:
        v9 = v61;
        ++v17;
        v16 = v62 + 1;
        v62 = v16;
        if ( v16 >= 3 )
          goto LABEL_44;
      }
      v9 = v61;
LABEL_31:
      v36 = 0i64;
      v37 = _mm_mul_ps(v27, v27);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      a5 = _mm_rsqrt_ps(v38);
      v39 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v38), (__m128)0i64);
      *(__m128 *)&v57.vfptr = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v38, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(a5, v38), a5)),
                                        _mm_mul_ps(*(__m128 *)_xmm, a5))),
                                    v27),
                                  v39),
                                _mm_andnot_ps(v39, v27));
      if ( _mm_movemask_ps(v39) )
      {
        v40 = _mm_sub_ps(*(__m128 *)(*(v17 - 3) + 32), v12->m_vertices[v22]->m_position.m_quad);
        v41 = _mm_mul_ps(v40, v40);
        v42 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170));
        v43 = _mm_rsqrt_ps(v42);
        v44 = _mm_mul_ps(*(__m128 *)_xmm, v43);
        v45 = _mm_cmpleps(v42, (__m128)0i64);
        v46 = _mm_mul_ps(_mm_mul_ps(v42, v43), v43);
        v47 = 0i64;
        v48 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v46), v44), v42);
        a5 = _mm_rcp_ps(v6->m_edgeSamplesSpacing.m_real);
        v49 = _mm_cvtsi128_si32(
                _mm_cvttps_epi32(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(a5, v6->m_edgeSamplesSpacing.m_real)), a5),
                      _mm_andnot_ps(v45, v48)),
                    (__m128)xmmword_141A711B0)))
            + 3;
        if ( v49 > 64 )
          v49 = 64;
        v50 = 0;
        v54 = v49;
        v47.m128_f32[0] = (float)v49;
        v51 = _mm_shuffle_ps(v47, v47, 0);
        v52 = _mm_rcp_ps(v51);
        for ( j = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v51, v52)), v52); v50 <= v54; ++v50 )
        {
          a5 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_or_ps(_mm_andnot_ps(v13, _mm_mul_ps(j, v36)), _mm_and_ps(v13, (__m128)xmmword_141A711B0)),
                   _mm_sub_ps(v12->m_vertices[v22]->m_position.m_quad, *(__m128 *)(*(v17 - 3) + 32))),
                 *(__m128 *)(*(v17 - 3) + 32));
          point.m_quad = a5;
          if ( hkgpMesh::computeOffsetPoint(v9, &v6->m_offset, (hkVector4f *)&v57, &point, 8, 1)
            && (!v10 || hkgpConvexHull::isPointInside(v10, &result, &point, 0, 0.0)->m_bool) )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
            v5->m_data[v5->m_size++] = (hkVector4f)point.m_quad;
          }
          if ( v6->m_edgeCenterOnly )
            break;
          v36 = _mm_add_ps(v36, query.m_quad);
          v9 = v61;
        }
      }
      goto LABEL_43;
    }
  }
}

// File Line: 2088
// RVA: 0xCCEDD0
void __usercall hkgpMesh::generateConcaveEdges(hkgpMesh *this@<rcx>, float offset@<xmm1>, hkArray<hkVector4f,hkContainerHeapAllocator> *edgesOut@<r8>, unsigned int useWeight@<r9d>, hkVector4f a5@<xmm2>, hkgpJobQueue *jq)
{
  hkgpMesh *v6; // rbx
  hkgpMeshBase::Triangle *v7; // r15
  hkgpMeshInternals::ConcaveEdgeJob *v8; // rdi
  __m128 v9; // xmm13
  float v10; // xmm14_4
  __m128 v11; // xmm3
  __m128 v12; // xmm3
  signed int v13; // er12
  __m128 **v14; // r14
  signed int v15; // ecx
  signed __int64 v16; // rsi
  __m128 *v17; // r8
  float *v18; // rax
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
  _QWORD **v35; // rax
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
  int v53; // eax
  hkgpMeshInternals::Segment *v54; // rcx
  __int128 v55; // xmm0
  __int128 v56; // xmm1
  __int128 v57; // xmm0
  hkgpMeshBase::Vertex *v58; // rax
  hkVector4f v59; // xmm7
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
  int v76; // er8
  int v77; // eax
  _QWORD **v78; // rax
  _QWORD *array; // [rsp+20h] [rbp-D8h]
  int v80; // [rsp+28h] [rbp-D0h]
  int v81; // [rsp+2Ch] [rbp-CCh]
  hkSimdFloat32 result; // [rsp+30h] [rbp-C8h]
  hkMatrix3f v83; // [rsp+40h] [rbp-B8h]
  __int128 v84; // [rsp+A8h] [rbp-50h]
  __int128 v85; // [rsp+B8h] [rbp-40h]
  __int128 v86; // [rsp+E8h] [rbp-10h]
  hkgpMesh *retaddr; // [rsp+1E8h] [rbp+F0h]
  hkArrayBase<hkVector4f> *v88; // [rsp+1F8h] [rbp+100h]
  hkgpJobQueue *v89; // [rsp+208h] [rbp+110h]

  *(float *)&v88 = offset;
  v6 = this;
  v7 = this->m_triangles.m_used;
  v8 = 0i64;
  array = 0i64;
  v80 = 0;
  v81 = 2147483648;
  v9 = hkVector4fComparison_maskToComparison_327[useWeight != 0 ? 0xF : 0];
  if ( v7 )
  {
    v10 = *(float *)&this;
    do
    {
      v11 = v7->m_plane.m_quad;
      if ( !(_mm_movemask_ps(_mm_cmpunordps(v11, v11)) & 7) )
      {
        v12 = _mm_mul_ps(v11, v11);
        a5.m_quad.m128_f32[0] = 0.000099999997;
        a5.m_quad = _mm_shuffle_ps(a5.m_quad, a5.m_quad, 0);
        if ( COERCE_FLOAT((unsigned int)(2
                                       * COERCE_SIGNED_INT(
                                           (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85))
                                                         + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)))
                                         - 1.0)) >> 1) < a5.m_quad.m128_f32[0] )
        {
          v13 = 0;
          v14 = (__m128 **)v7->m_vertices;
          do
          {
            v15 = 0;
            v16 = (9i64 >> 2 * (unsigned __int8)v13) & 3;
            v17 = (__m128 *)v7->m_vertices[v16];
            v18 = v17[2].m128_f32;
            do
            {
              v19 = *(float *)((char *)v18 + (char *)*v14 - (char *)v17);
              if ( v19 < *v18 )
                break;
              if ( v19 > *v18 )
              {
                if ( (unsigned __int64)v14[3] & 0xFFFFFFFFFFFFFFFCui64 )
                  goto LABEL_49;
                break;
              }
              ++v15;
              ++v18;
            }
            while ( v15 < 3 );
            v20 = (unsigned __int64)v14[3];
            v21 = v7->m_plane.m_quad;
            v22 = (unsigned __int64)v14[3] & 0xFFFFFFFFFFFFFFFCui64;
            if ( v22 )
            {
              v23 = *(__m128 *)(v22 + 64);
              if ( !(_mm_movemask_ps(_mm_cmpunordps(v23, v23)) & 7) )
              {
                v24 = _mm_mul_ps(v23, v23);
                a5.m_quad = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
                if ( COERCE_FLOAT((unsigned int)(2
                                               * COERCE_SIGNED_INT(
                                                   (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85))
                                                                 + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                                                         + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170)))
                                                 - 1.0)) >> 1) < a5.m_quad.m128_f32[0] )
                {
                  v25 = *(__m128 *)(v22 + 64);
                  v26 = _mm_mul_ps(v25, v21);
                  a5.m_quad = _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                                _mm_shuffle_ps(v26, v26, 170));
                  if ( a5.m_quad.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0)) )
                  {
                    v27 = (*v14)[2];
                    v28 = _mm_add_ps(v21, v25);
                    a5.m_quad = _mm_sub_ps(v17[2], v27);
                    v29 = (__m128 *)v7->m_vertices[(18i64 >> 2 * (unsigned __int8)v13) & 3];
                    v83.m_col0 = (hkVector4f)a5.m_quad;
                    v83.m_col1.m_quad = _mm_sub_ps(v29[2], v27);
                    v83.m_col2.m_quad = _mm_sub_ps(
                                          *(__m128 *)(*(_QWORD *)((v20 & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8 * ((18i64 >> 2 * ((unsigned __int8)v20 & 3u)) & 3)
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
                      a5.m_quad = _mm_rsqrt_ps(v31);
                      v32 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v31), (__m128)0i64);
                      v33 = _mm_or_ps(
                              _mm_and_ps(
                                _mm_mul_ps(
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v31, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(a5.m_quad, v31), a5.m_quad)),
                                      _mm_mul_ps(*(__m128 *)_xmm, a5.m_quad))),
                                  v28),
                                v32),
                              _mm_andnot_ps(v32, v28));
                      if ( _mm_movemask_ps(v32) )
                      {
                        v34 = _mm_sub_ps(v7->m_vertices[v16]->m_position.m_quad, (*v14)[2]);
                        if ( !v8 )
                        {
                          v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                          v36 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v35[11] + 8i64))(v35[11], 40i64);
                          v8 = (hkgpMeshInternals::ConcaveEdgeJob *)v36;
                          if ( v36 )
                          {
                            *(_QWORD *)v36 = v6;
                            *(_DWORD *)(v36 + 20) = 2147483648;
                            *(_QWORD *)(v36 + 8) = 0i64;
                            *(_DWORD *)(v36 + 16) = 0;
                            *(_QWORD *)(v36 + 24) = 0i64;
                            *(_DWORD *)(v36 + 32) = 0;
                            *(_DWORD *)(v36 + 36) = 2147483648;
                          }
                          else
                          {
                            v8 = 0i64;
                          }
                          v37 = v80;
                          if ( v80 == (v81 & 0x3FFFFFFF) )
                          {
                            hkArrayUtil::_reserveMore(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              &array,
                              8);
                            v37 = v80;
                          }
                          array[v37] = v8;
                          ++v80;
                        }
                        v38 = *v14;
                        v39 = v7->m_vertices[v16];
                        a5.m_quad.m128_f32[0] = v10;
                        DWORD1(v86) = 0;
                        v40 = _mm_shuffle_ps(a5.m_quad, a5.m_quad, 0);
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
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                            &v8->m_segments,
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
                        v50 = (*v14)[3];
                        v51 = _mm_mul_ps((*v14)[3], v34);
                        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 170))) < 0.0 )
                        {
                          v52 = (*v14)[2];
                          v53 = v8->m_segments.m_capacityAndFlags;
                          DWORD1(v86) = 0;
                          if ( v8->m_segments.m_size == (v53 & 0x3FFFFFFF) )
                            hkArrayUtil::_reserveMore(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              &v8->m_segments,
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
                        v58 = v7->m_vertices[v16];
                        v59.m_quad = (__m128)v58->m_normal;
                        v60 = _mm_mul_ps(v58->m_normal.m_quad, v34);
                        LODWORD(v61) = (unsigned __int128)_mm_shuffle_ps(v60, v60, 85);
                        LODWORD(v62) = (unsigned __int128)_mm_shuffle_ps(v60, v60, 0);
                        a5.m_quad = _mm_shuffle_ps(v60, v60, 170);
                        if ( (float)((float)(v61 + v62) + a5.m_quad.m128_f32[0]) > 0.0 )
                        {
                          v63.m_quad = (__m128)v58->m_position;
                          v64 = v8->m_segments.m_capacityAndFlags;
                          DWORD1(v86) = 0;
                          if ( v8->m_segments.m_size == (v64 & 0x3FFFFFFF) )
                            hkArrayUtil::_reserveMore(
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              &v8->m_segments,
                              144);
                          v65 = &v8->m_segments.m_data[v8->m_segments.m_size];
                          if ( v65 )
                          {
                            v66 = v84;
                            v67 = v85;
                            v65->m_vertices[0] = (hkVector4f)v63.m_quad;
                            v65->m_vertices[1] = (hkVector4f)v63.m_quad;
                            v65->m_normals[0] = (hkVector4f)v59.m_quad;
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
                            v70 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v69[11] + 8i64))(
                                                          v69[11],
                                                          16i64);
                            if ( v70 )
                            {
                              v70[1].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
                              v70->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpMeshInternals::ConcaveEdgeJob::Handle>::`vftable';
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
            ++v14;
          }
          while ( v13 < 3 );
        }
      }
      v7 = v7->m_next;
    }
    while ( v7 );
    if ( v8 )
    {
      if ( !v89 )
      {
        hkgpMeshInternals::ConcaveEdgeJob::run(v8);
        goto LABEL_58;
      }
      v71 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v72 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v71[11] + 8i64))(
                                    v71[11],
                                    16i64);
      if ( v72 )
      {
        v72[1].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
        v72->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpMeshInternals::ConcaveEdgeJob::Handle>::`vftable';
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
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        *(hkVector4f **)(array[v74] + 24i64),
        *(_DWORD *)(array[v74] + 32i64));
      v75 = array[v74];
      if ( v75 )
      {
        v76 = *(_DWORD *)(v75 + 36);
        *(_DWORD *)(v75 + 32) = 0;
        if ( v76 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 24),
            16 * v76);
        *(_QWORD *)(v75 + 24) = 0i64;
        *(_DWORD *)(v75 + 36) = 2147483648;
        v77 = *(_DWORD *)(v75 + 20);
        *(_DWORD *)(v75 + 16) = 0;
        if ( v77 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v75 + 8),
            144 * (v77 & 0x3FFFFFFF));
        *(_QWORD *)(v75 + 8) = 0i64;
        *(_DWORD *)(v75 + 20) = 2147483648;
        v78 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v78[11] + 16i64))(v78[11], v75, 40i64);
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v80 );
  }
  v80 = 0;
  if ( v81 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v81);
}

// File Line: 2307
// RVA: 0xCCF6A0
void __fastcall hkgpMesh::generateEmptySpaceSamples(hkgpMesh *this, int maxOctreeDepth, float scaling, hkArray<hkVector4f,hkContainerHeapAllocator> *samplesOut, bool negate)
{
  hkgpMesh *v5; // r15
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rsi
  int v7; // er14
  hkgpConvexHull::BuildConfig *v8; // rax
  int v9; // eax
  hkAabb *v10; // rbx
  int v11; // edx
  hkAabb *v12; // r8
  hkVector4f *v13; // rcx
  int v14; // edx
  signed __int64 v15; // rcx
  __m128i v16; // xmm6
  __m128 v17; // xmm7
  __m128 v18; // xmm10
  signed int v19; // edi
  hkArray<hkVector4f,hkContainerHeapAllocator> v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  float v23; // xmm9_4
  hkStridedVertices v24; // xmm1
  hkgpConvexHull::BuildConfig v25; // xmm8
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  signed int v29; // ebx
  int v30; // edi
  int v31; // ecx
  __m128 *v32; // rdx
  __m128i v33; // xmm2
  __m128 v34; // xmm2
  hkAabb *array; // [rsp+30h] [rbp-D0h]
  int v36; // [rsp+38h] [rbp-C8h]
  int v37; // [rsp+3Ch] [rbp-C4h]
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+40h] [rbp-C0h]
  hkBool v39; // [rsp+50h] [rbp-B0h]
  hkStridedVertices points; // [rsp+60h] [rbp-A0h]
  hkgpConvexHull::BuildConfig v41; // [rsp+70h] [rbp-90h]
  hkgpConvexHull v42; // [rsp+80h] [rbp-80h]
  hkAabb result; // [rsp+B0h] [rbp-50h]
  float v44; // [rsp+180h] [rbp+80h]

  v44 = scaling;
  v5 = this;
  v6 = samplesOut;
  v7 = maxOctreeDepth;
  hkgpConvexHull::hkgpConvexHull(&v42);
  positions.m_capacityAndFlags = 2147483648;
  positions.m_data = 0i64;
  positions.m_size = 0;
  hkgpMesh::fetchPositions(v5, &positions);
  points.m_striding = 16;
  points.m_vertices = positions.m_data->m_quad.m128_f32;
  points.m_numVertices = positions.m_size;
  hkgpConvexHull::BuildConfig::BuildConfig(&v41);
  v9 = hkgpConvexHull::build(&v42, &points, v8);
  positions.m_size = 0;
  if ( v9 == 3 )
  {
    if ( positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        positions.m_data,
        16 * positions.m_capacityAndFlags);
    array = 0i64;
    v36 = 0;
    v37 = 2147483648;
    v10 = hkgpMesh::getBoundingBox(v5, &result);
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32);
    v11 = v36;
    v12 = array;
    v13 = &array[v36].m_min;
    if ( v13 )
    {
      *v13 = v10->m_min;
      v13[1] = v10->m_max;
      v11 = v36;
      v12 = array;
    }
    v36 = v11 + 1;
    hkGeometryProcessing::normalizeAspectRatio(v12);
    array->m_min.m_quad.m128_i32[3] = 1056964608;
    v14 = v36;
    do
    {
      v15 = v14;
      v16 = (__m128i)array[v15 - 1].m_min;
      v17 = *((__m128 *)&array[v15] - 1);
      v36 = v14 - 1;
      v18 = _mm_add_ps((__m128)v16, v17);
      v19 = _mm_cvtsi128_si32(_mm_srli_si128(v16, 12)) & 0xC0FFFFFF;
      v20 = (hkArray<hkVector4f,hkContainerHeapAllocator>)_mm_mul_ps(v18, (__m128)xmmword_141A711B0);
      positions = v20;
      v21 = _mm_sub_ps((__m128)v20, v17);
      v22 = _mm_mul_ps(v21, v21);
      v23 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170));
      hkgpMesh::squaredDistanceToPoint(
        v5,
        (hkSimdFloat32 *)&v41,
        (hkVector4f *)&positions,
        &result.m_min,
        (hkVector4fComparison *)&points);
      v24 = (hkStridedVertices)_mm_load_si128((const __m128i *)&points);
      if ( negate )
      {
        v24 = (hkStridedVertices)_mm_cmpeq_epi32((__m128i)v24, (__m128i)0i64);
        points = v24;
      }
      v25 = v41;
      if ( *(float *)&v41.m_allowLowerDimensions.m_bool <= v23 )
      {
        if ( v19 < v7 )
        {
          v29 = 0;
          v30 = (v19 + 1) | 0x3F000000;
          do
          {
            v31 = v36;
            if ( v36 == (v37 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32);
              v31 = v36;
            }
            v36 = v31 + 1;
            v32 = &array[v31].m_min.m_quad;
            switch ( v29 )
            {
              case 0:
                v33 = v16;
                break;
              case 1:
                v33 = v16;
                *(float *)v33.m128i_i32 = v17.m128_f32[0];
                break;
              case 2:
                v33 = (__m128i)_mm_shuffle_ps(v17, (__m128)v16, 228);
                break;
              case 3:
                v33 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E30, (__m128)v16),
                                 _mm_and_ps((__m128)xmmword_141A79E30, v17));
                break;
              case 4:
                v33 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E50, (__m128)v16),
                                 _mm_and_ps((__m128)xmmword_141A79E50, v17));
                break;
              case 5:
                v33 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E60, (__m128)v16),
                                 _mm_and_ps((__m128)xmmword_141A79E60, v17));
                break;
              case 6:
                v33 = (__m128i)v17;
                break;
              case 7:
                v33 = (__m128i)_mm_or_ps(
                                 _mm_andnot_ps((__m128)xmmword_141A79E70, (__m128)v16),
                                 _mm_and_ps((__m128)xmmword_141A79E70, v17));
                break;
              default:
                v33 = (__m128i)_mm_mul_ps(v18, (__m128)xmmword_141A711B0);
                break;
            }
            ++v29;
            v34 = (__m128)_mm_srli_si128(_mm_slli_si128(v33, 4), 4);
            *v32 = _mm_min_ps((__m128)positions, v34);
            v32[1] = _mm_max_ps((__m128)positions, v34);
            HIDWORD(v32->m128_u64[1]) = v30;
          }
          while ( v29 < 8 );
        }
      }
      else if ( !_mm_movemask_ps((__m128)v24)
             && hkgpConvexHull::isPointInside(&v42, &v39, (hkVector4f *)&positions, 0, 0.0)->m_bool )
      {
        v27 = _mm_rsqrt_ps((__m128)v25);
        v26.m128_f32[0] = v44;
        v28 = _mm_shuffle_ps(
                (__m128)positions,
                _mm_unpackhi_ps(
                  (__m128)positions,
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps((__m128)v25, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps((__m128)v25, v27), v27)),
                          _mm_mul_ps(*(__m128 *)_xmm, v27)),
                        (__m128)v25)),
                    _mm_shuffle_ps(v26, v26, 0))),
                196);
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
        v6->m_data[v6->m_size++].m_quad = v28;
      }
      v14 = v36;
    }
    while ( v36 );
    v36 = 0;
    if ( v37 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        32 * v37);
    array = 0i64;
    v37 = 2147483648;
  }
  else if ( positions.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  }
  hkgpConvexHull::~hkgpConvexHull(&v42);
}

// File Line: 2363
// RVA: 0xCCBAA0
__int64 __fastcall hkgpMesh::removeOrphanVertices(hkgpMesh *this)
{
  const __m128i *v1; // rax
  unsigned int v2; // esi
  hkgpMesh *i; // rbx
  hkgpMeshBase::Triangle *j; // rcx
  hkgpMeshBase::Vertex *v5; // rax
  hkVector4f v6; // xmm1
  hkgpMeshBase::Vertex *v7; // rax
  hkVector4f v8; // xmm1
  hkgpMeshBase::Vertex *v9; // rax
  hkVector4f v10; // xmm1
  hkgpMeshBase::Vertex *v11; // rdi
  __m128 v12; // xmm0
  hkgpMeshBase::Vertex **v13; // rdx
  hkgpMeshBase::Vertex *v14; // rax
  hkgpMeshBase::Vertex *v15; // rcx
  hkgpMeshBase::Vertex *v16; // rdx
  bool v17; // zf
  __int64 v18; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v19; // rax
  __int64 v20; // rcx

  v1 = (const __m128i *)this->m_vertices.m_used;
  v2 = 0;
  for ( i = this; v1; v1 = (const __m128i *)v1->m128i_i64[0] )
    _mm_store_si128((__m128i *)&v1[4], _mm_slli_si128(_mm_srli_si128(_mm_load_si128(v1 + 4), 4), 4));
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
  v11 = i->m_vertices.m_used;
  if ( v11 )
  {
    do
    {
      v12 = v11->m_data.m_quad;
      v13 = (hkgpMeshBase::Vertex **)v11;
      v11 = v11->m_next;
      if ( COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)) == 0.0 )
      {
        v14 = *v13;
        v15 = v13[1];
        if ( *v13 )
          v14->m_prev = v15;
        if ( v15 )
          v15->m_next = v14;
        else
          i->m_vertices.m_used = v14;
        --i->m_vertices.m_numUsed;
        v16 = v13[12];
        v17 = v16[37].m_normal.m_quad.m128_i32[2]-- == 1;
        if ( v17 )
        {
          v18 = v16[37].m_position.m_quad.m128_i64[1];
          v19 = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *)v16[37].m_normal.m_quad.m128_u64[0];
          if ( v18 )
            *(_QWORD *)(v18 + 3600) = v19;
          else
            i->m_vertices.m_allocator.m_firstPool = v19;
          v20 = v16[37].m_normal.m_quad.m128_i64[0];
          if ( v20 )
            *(_QWORD *)(v20 + 3592) = v16[37].m_position.m_quad.m128_u64[1];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v16,
            3616);
        }
        ++v2;
      }
    }
    while ( v11 );
    if ( v2 )
      hkgpMesh::invalidateConvexHull(i);
  }
  return v2;
}

// File Line: 2390
// RVA: 0xCCBC20
__int64 __fastcall hkgpMesh::removeButterflies(hkgpMesh *this, int tag)
{
  hkgpMeshBase::Vertex *v2; // rax
  unsigned int v3; // er15
  int v4; // er12
  hkgpMesh *i; // r13
  hkgpMeshBase::Triangle *j; // rcx
  hkgpMeshBase::Triangle *v7; // rsi
  signed int v8; // ebx
  __int128 v9; // xmm6
  int v10; // er9
  hkgpMeshBase::Vertex *v11; // r14
  __int128 *v12; // rax
  __int64 v13; // rcx
  signed __int64 v14; // rax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rdx
  __int128 v17; // xmm6
  __int128 *v18; // rax
  signed __int64 v19; // rdx
  hkgpMeshBase::Vertex *v20; // rax
  int v21; // er8
  hkgpMeshBase::Vertex *v22; // r9
  __int64 v23; // rdx
  hkOstream *v24; // rax
  __int128 v26; // [rsp+20h] [rbp-E0h]
  __int128 v27; // [rsp+20h] [rbp-E0h]
  hkErrStream v28; // [rsp+30h] [rbp-D0h]
  __int128 v29; // [rsp+50h] [rbp-B0h]
  __int128 v30; // [rsp+60h] [rbp-A0h]
  __int128 v31; // [rsp+70h] [rbp-90h]
  char *array; // [rsp+80h] [rbp-80h]
  int v33; // [rsp+88h] [rbp-78h]
  int v34; // [rsp+8Ch] [rbp-74h]
  char v35; // [rsp+90h] [rbp-70h]

  v2 = this->m_vertices.m_used;
  v3 = 0;
  v4 = tag;
  for ( i = this; v2; v2 = v2->m_next )
    v2->m_refs = 0;
  for ( j = this->m_triangles.m_used; j; j = j->m_next )
  {
    ++j->m_vertices[0]->m_refs;
    ++j->m_vertices[1]->m_refs;
    ++j->m_vertices[2]->m_refs;
  }
  v7 = i->m_triangles.m_used;
  if ( v7 )
  {
    do
    {
      v8 = 0;
      do
      {
        *(_QWORD *)&v30 = v7;
        DWORD2(v30) = v8;
        v9 = v30;
        v10 = 0;
        v26 = v30;
        v11 = v7->m_vertices[v8];
        array = &v35;
        v33 = 0;
        v34 = -2147483632;
        while ( 1 )
        {
          if ( v10 == (v34 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v10 = v33;
          }
          v12 = (__int128 *)&array[16 * v10];
          if ( v12 )
          {
            *v12 = v9;
            v10 = v33;
          }
          v33 = ++v10;
          v13 = (18 >> 2 * BYTE8(v26)) & 3;
          v14 = *(_QWORD *)(v26 + 8 * v13 + 40) & 3i64;
          v15 = *(_QWORD *)(v26 + 8 * v13 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          *(_QWORD *)&v29 = *(_QWORD *)(v26 + 8 * v13 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          DWORD2(v29) = v14;
          v9 = v29;
          v26 = v29;
          if ( !v15 )
            break;
          if ( (hkgpMeshBase::Triangle *)(v15 + (unsigned int)v14) == (hkgpMeshBase::Triangle *)((char *)v7
                                                                                               + (unsigned int)v8) )
            goto LABEL_21;
        }
        v16 = v7->m_links[v8];
        *(_QWORD *)&v31 = v16 & 0xFFFFFFFFFFFFFFFCui64;
        DWORD2(v31) = (9 >> 2 * (v16 & 3)) & 3;
        v17 = v31;
        v27 = v31;
        if ( v16 & 0xFFFFFFFFFFFFFFFCui64 )
        {
          do
          {
            if ( v10 == (v34 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
              v10 = v33;
            }
            v18 = (__int128 *)&array[16 * v10];
            if ( v18 )
            {
              *v18 = v17;
              v10 = v33;
            }
            v33 = ++v10;
            v19 = *(_QWORD *)(v27 + 8i64 * SDWORD2(v27) + 40) & 3i64;
            v28.vfptr = (hkBaseObjectVtbl *)(*(_QWORD *)(v27 + 8i64 * SDWORD2(v27) + 40) & 0xFFFFFFFFFFFFFFFCui64);
            *(_DWORD *)&v28.m_memSizeAndFlags = (9 >> 2 * v19) & 3;
            v17 = *(_OWORD *)&v28.vfptr;
            v27 = *(_OWORD *)&v28.vfptr;
          }
          while ( v28.vfptr );
        }
LABEL_21:
        if ( v10 < v11->m_refs )
        {
          v20 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::allocate(
                  &i->m_vertices,
                  v11);
          v21 = 0;
          v22 = v20;
          LODWORD(v20) = v33;
          v11->m_tag = v4;
          v11->m_refs -= (signed int)v20;
          LODWORD(v20) = v33;
          v22->m_tag = v4;
          v22->m_refs = (signed int)v20;
          if ( v33 > 0 )
          {
            v23 = 0i64;
            do
            {
              ++v21;
              v23 += 16i64;
              *(_QWORD *)(*(_QWORD *)&array[v23 - 16] + 8i64 * *(signed int *)&array[v23 - 8] + 16) = v22;
            }
            while ( v21 < v33 );
          }
          ++v3;
        }
        v33 = 0;
        if ( v34 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            16 * v34);
        ++v8;
      }
      while ( v8 < 3 );
      v7 = v7->m_next;
    }
    while ( v7 );
    if ( v3 )
    {
      hkErrStream::hkErrStream(&v28, &array, 512);
      v24 = hkOstream::operator<<((hkOstream *)&v28.vfptr, "Butterflies found: ");
      hkOstream::operator<<(v24, v3, (int)v24);
      hkError::messageReport(-1, (const char *)&array, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2428);
      hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
    }
  }
  return v3;
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
  bool v2; // bl
  hkgpAbstractMeshDefinitions::Error v3; // eax
  int v4; // edi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = raiseError;
  v3 = hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::checkTopology(
         (hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator> *)&this->vfptr,
         1);
  v4 = v3;
  if ( v2 && v3 )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "Invalid mesh topology (");
    v6 = hkOstream::operator<<(v5, v4, (int)v5);
    hkOstream::operator<<(v6, ")");
    if ( (unsigned int)hkError::messageError(1281108730, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2459) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  }
  return v4 == 0;
}

// File Line: 2466
// RVA: 0xCCFCE0
char __fastcall hkgpMesh::bindEdge(hkgpMesh *this, hkgpMeshBase::Edge *edge, bool onlyToNaked, bool mustMatch)
{
  __int64 v4; // rsi
  hkgpMeshBase::Triangle *v5; // rdi
  bool v6; // r10
  hkgpMeshBase::Triangle *v7; // r8
  signed int v8; // eax
  hkErrStream v10; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v4 = edge->m_index;
  v5 = edge->m_triangle;
  v6 = onlyToNaked;
  if ( edge->m_triangle->m_links[(signed int)v4] & 0xFFFFFFFFFFFFFFFCui64 )
    return 1;
  v7 = this->m_triangles.m_used;
  if ( v7 )
  {
    while ( 2 )
    {
      v8 = 0;
      do
      {
        if ( (!v6 || !(v7->m_links[v8] & 0xFFFFFFFFFFFFFFFCui64))
          && v7->m_vertices[(9i64 >> 2 * (unsigned __int8)v8) & 3] == v5->m_vertices[(signed int)v4]
          && v7->m_vertices[v8] == v5->m_vertices[(9i64 >> 2 * (unsigned __int8)v4) & 3] )
        {
          v7->m_links[v8] = (unsigned __int64)v5 + v4;
          if ( edge->m_triangle )
            edge->m_triangle->m_links[edge->m_index] = (unsigned __int64)v7 + (unsigned int)v8;
          return 1;
        }
        ++v8;
      }
      while ( v8 < 3 );
      v7 = v7->m_next;
      if ( v7 )
        continue;
      break;
    }
  }
  if ( mustMatch )
  {
    hkErrStream::hkErrStream(&v10, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v10.vfptr, "Unmatched edge");
    if ( (unsigned int)hkError::messageError(532035272, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2486) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
  }
  return 0;
}

// File Line: 2498
// RVA: 0xCCFE20
void __fastcall hkgpMesh::bindEdgeList(hkgpMesh *this, hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *edges)
{
  int v2; // er15
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *v3; // r10
  signed __int64 v4; // rdi
  __int64 v5; // r12
  signed int v6; // er13
  int v7; // er11
  signed __int64 v8; // rax
  hkgpMeshBase::Edge *v9; // r14
  signed __int64 v10; // r9
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rsi
  signed __int64 v14; // rdx
  signed __int64 v15; // rax
  signed __int64 v16; // r8
  __int64 v17; // rcx
  signed __int64 v18; // rcx
  signed __int64 v19; // rdx
  signed __int64 v20; // r8
  hkgpMeshBase::Edge *v21; // rcx
  char *v22; // r8
  __int64 v23; // rax
  signed __int64 v24; // [rsp+38h] [rbp+10h]

  v2 = 0;
  v3 = edges;
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
      if ( v6 < v3->m_size )
      {
        v9 = &v3->m_data[v5];
        v10 = (signed __int64)&v3->m_data[v5 + 1];
        while ( 1 )
        {
          v11 = *(_QWORD *)v10;
          if ( !*(_QWORD *)v10 )
            break;
          v12 = *(signed int *)(v10 + 8);
          v13 = (signed int)v9->m_index;
          if ( v9->m_triangle->m_vertices[v13] == *(hkgpMeshBase::Vertex **)(v11
                                                                           + 8
                                                                           * ((9i64 >> 2 * (unsigned __int8)v12) & 3)
                                                                           + 16)
            && v9->m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v13) & 3] == *(hkgpMeshBase::Vertex **)(v11 + 8 * v12 + 16) )
          {
            break;
          }
          ++v7;
          ++v8;
          v10 += 16i64;
          if ( v7 >= v3->m_size )
          {
            v4 = v24;
            goto LABEL_10;
          }
        }
        v9->m_triangle->m_links[v9->m_index] = v11 + *(unsigned int *)(v10 + 8);
        if ( *(_QWORD *)v10 )
          *(_QWORD *)(*(_QWORD *)v10 + 8i64 * *(signed int *)(v10 + 8) + 40) = (char *)v9->m_triangle + v9->m_index;
        if ( --v3->m_size != v7 )
        {
          v14 = 2i64;
          v15 = (signed __int64)&v3->m_data[v8];
          v16 = (signed __int64)&v3->m_data[v3->m_size] - v15;
          do
          {
            v17 = *(_QWORD *)(v16 + v15);
            v15 += 8i64;
            *(_QWORD *)(v15 - 8) = v17;
            --v14;
          }
          while ( v14 );
        }
        v18 = --v3->m_size;
        if ( (_DWORD)v18 != v2 )
        {
          v19 = 2i64;
          v20 = v18;
          v21 = &v3->m_data[v5];
          v22 = (char *)((char *)&v3->m_data[v20] - (char *)v21);
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
    while ( v2 < v3->m_size );
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
  int v6; // er8
  hkVector4f *v7; // rdi
  hkVector4f *v8; // rbx
  __m128 j; // xmm1
  int v10; // edi
  hkgpMeshBase::Triangle *v11; // r15
  char v12; // si
  signed int v13; // er13
  hkgpMeshInternals::Ring *v14; // rax
  hkgpMeshInternals::Ring *v15; // r12
  int v16; // ecx
  __int64 v17; // rbx
  __int64 v18; // rsi
  hkgpMeshBase::Triangle *v19; // r14
  int v20; // eax
  unsigned int v21; // ebx
  int v22; // er9
  __int64 v23; // rdx
  __int64 v24; // r8
  int v25; // ecx
  unsigned __int8 v26; // r14
  int v27; // esi
  __int64 v28; // r15
  int v29; // ebx
  int v30; // eax
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128i v35; // xmm1
  int v36; // edi
  int v37; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v38; // rdx
  bool v39; // zf
  bool v40; // sf
  int v41; // edx
  int v42; // esi
  __int64 v43; // rbx
  hkgpMeshInternals::Ring::Segment *v44; // rdi
  hkgpMeshBase::Triangle **v45; // rcx
  hkgpMeshInternals::Ring::Segment *v46; // rax
  int v47; // edx
  hkgpMeshBase::Triangle *v48; // rdi
  hkgpMeshBase::Triangle **v49; // rcx
  __int64 v50; // rax
  hkgpMeshInternals::Ring::Segment *v51; // rax
  int v52; // edx
  hkgpMeshBase::Triangle *v53; // rdi
  hkgpMeshBase::Triangle **v54; // rcx
  __int64 v55; // rax
  int v56; // edx
  hkgpMeshInternals::Ring::Segment *v57; // rax
  hkgpMeshBase::Triangle *v58; // r11
  __int64 v59; // rdi
  int v60; // er8
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128i v65; // xmm1
  int v66; // er10
  int v67; // er9
  __m128 v68; // xmm1
  __m128 v69; // xmm3
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128i v72; // xmm4
  int v73; // eax
  int v74; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v75; // r15
  _QWORD *v76; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v77; // r14
  signed int v78; // edx
  signed int v79; // esi
  signed __int64 v80; // r11
  __int64 v81; // rax
  __int64 v82; // r13
  unsigned __int64 v83; // rax
  __int64 v84; // r10
  __int64 v85; // rax
  int v86; // er12
  unsigned __int64 v87; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v88; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v89; // rbx
  int v90; // eax
  int v91; // ecx
  signed __int64 v92; // rcx
  unsigned __int64 v93; // rax
  signed __int64 v94; // r12
  unsigned __int64 v95; // r10
  int v96; // er11
  __int64 v97; // r13
  int v98; // er8
  int v99; // edx
  __int64 v100; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v101; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v102; // rdx
  int v103; // eax
  int v104; // ecx
  unsigned __int64 v105; // r8
  signed __int64 v106; // rcx
  unsigned __int64 v107; // r8
  __int16 v108; // dx
  int v109; // er10
  unsigned __int64 v110; // rax
  char v111; // cl
  unsigned __int64 v112; // rdx
  __int64 v113; // rbx
  __int64 v114; // r9
  int v115; // eax
  int v116; // ecx
  __int64 v117; // r9
  unsigned __int64 v118; // r9
  __int16 v119; // dx
  int v120; // ebx
  unsigned __int64 v121; // rdx
  signed __int64 v122; // r15
  __int64 v123; // rcx
  int v124; // er9
  unsigned __int64 v125; // r8
  signed __int64 v126; // r12
  unsigned __int64 v127; // r8
  signed __int64 v128; // r15
  unsigned __int64 v129; // rcx
  unsigned __int64 v130; // r9
  signed __int64 v131; // rdx
  __int64 v132; // r10
  __int64 v133; // r8
  int v134; // eax
  int v135; // ecx
  __int64 v136; // r8
  unsigned __int64 v137; // r8
  signed __int64 v138; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v139; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v140; // rdx
  int v141; // eax
  int v142; // ecx
  unsigned __int64 v143; // r9
  unsigned __int64 v144; // r9
  int v145; // er12
  hkgpMeshInternals::Ring *v146; // r13
  hkVector4f *v147; // rsi
  hkVector4f *v148; // rdi
  hkVector4f *v149; // rbx
  hkgpMeshBase::Triangle *v150; // r15
  __int64 v151; // rax
  signed int v152; // ebx
  char v153; // al
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v154; // rax
  signed __int64 v155; // rdx
  hkgpMeshBase::Edge *v156; // rcx
  __int64 v157; // rax
  int v158; // ecx
  int v159; // edi
  __int64 v160; // rbx
  int v161; // edi
  signed __int64 v162; // rbx
  int v163; // er9
  __int64 v164; // rbx
  hkgpMesh *v165; // r15
  __m128 *v166; // r14
  int v167; // esi
  char k; // di
  int v169; // er11
  __m128 *v170; // r13
  __m128 *v171; // r9
  char v172; // dl
  float v173; // xmm13_4
  __m128 *v174; // r12
  signed int v175; // er10
  unsigned __int64 v176; // r8
  int v177; // edx
  __int64 v178; // rcx
  __m128 *v179; // r8
  int v180; // edx
  __m128 v181; // xmm0
  __m128 v182; // xmm7
  __m128 v183; // xmm8
  __m128 v184; // xmm3
  __m128 v185; // xmm3
  __m128 v186; // xmm2
  __m128 v187; // xmm2
  __m128 v188; // xmm1
  __m128 v189; // xmm5
  __m128 v190; // xmm12
  __m128 v191; // xmm9
  __m128 v192; // xmm1
  __m128 v193; // xmm6
  __m128 v194; // xmm10
  __m128 v195; // xmm11
  __m128 v196; // xmm4
  __m128 v197; // xmm8
  __m128 v198; // xmm7
  __m128 v199; // xmm5
  __m128 v200; // xmm6
  __m128 v201; // xmm2
  __m128 v202; // xmm4
  __m128 v203; // xmm3
  __m128 v204; // xmm2
  float v205; // xmm1_4
  __int64 v206; // r14
  hkVector4f *v207; // rdi
  hkVector4f *v208; // rsi
  hkVector4f *v209; // rbx
  hkgpMeshBase::Triangle *v210; // rax
  hkgpMeshBase::Triangle *v211; // r15
  int v212; // edi
  int v213; // ebx
  hkOstream *v214; // rax
  hkOstream *v215; // rax
  hkOstream *v216; // rax
  hkOstream *v217; // rax
  hkOstream *v218; // rax
  hkOstream *v219; // rax
  hkOstream *v220; // rax
  char *v221; // [rsp+40h] [rbp-C0h]
  int v222; // [rsp+48h] [rbp-B8h]
  int v223; // [rsp+4Ch] [rbp-B4h]
  _QWORD *v224; // [rsp+50h] [rbp-B0h]
  int v225; // [rsp+58h] [rbp-A8h]
  int v226; // [rsp+5Ch] [rbp-A4h]
  float *v227; // [rsp+60h] [rbp-A0h]
  unsigned int v228; // [rsp+68h] [rbp-98h]
  int v229; // [rsp+6Ch] [rbp-94h]
  int v230; // [rsp+70h] [rbp-90h]
  _QWORD *v231; // [rsp+78h] [rbp-88h]
  int v232; // [rsp+80h] [rbp-80h]
  int v233; // [rsp+84h] [rbp-7Ch]
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> edges; // [rsp+88h] [rbp-78h]
  int v235; // [rsp+98h] [rbp-68h]
  int v236; // [rsp+9Ch] [rbp-64h]
  int i; // [rsp+A0h] [rbp-60h]
  hkVector4f *array; // [rsp+A8h] [rbp-58h]
  int v239; // [rsp+B0h] [rbp-50h]
  int v240; // [rsp+B4h] [rbp-4Ch]
  int v241; // [rsp+B8h] [rbp-48h]
  int v242; // [rsp+BCh] [rbp-44h]
  hkVector4f uv; // [rsp+C0h] [rbp-40h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion data; // [rsp+D0h] [rbp-30h]
  hkgpMeshBase::Triangle *v245; // [rsp+F0h] [rbp-10h]
  hkResult v246; // [rsp+F8h] [rbp-8h]
  int v247; // [rsp+FCh] [rbp-4h]
  int v248; // [rsp+100h] [rbp+0h]
  __int64 v249; // [rsp+108h] [rbp+8h]
  hkResult result; // [rsp+110h] [rbp+10h]
  __int64 v251; // [rsp+118h] [rbp+18h]
  hkgpMeshInternals::Ring *v252; // [rsp+120h] [rbp+20h]
  hkVector4f planeNormal; // [rsp+130h] [rbp+30h]
  __int64 v254; // [rsp+140h] [rbp+40h]
  __int64 v255; // [rsp+148h] [rbp+48h]
  __int64 v256; // [rsp+150h] [rbp+50h]
  hkStridedVertices points; // [rsp+158h] [rbp+58h]
  __int64 v258; // [rsp+170h] [rbp+70h]
  hkgpConvexHull::BuildConfig configa; // [rsp+178h] [rbp+78h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge edge; // [rsp+188h] [rbp+88h]
  __m128i v261; // [rsp+1A0h] [rbp+A0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location location; // [rsp+1B0h] [rbp+B0h]
  hkgpConvexHull v263; // [rsp+1C8h] [rbp+C8h]
  __int128 v264; // [rsp+1F0h] [rbp+F0h]
  __int64 v265; // [rsp+208h] [rbp+108h]
  __int64 v266; // [rsp+218h] [rbp+118h]
  hkVector4f dmin; // [rsp+220h] [rbp+120h]
  hkVector4f dmax; // [rsp+230h] [rbp+130h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> v269; // [rsp+240h] [rbp+140h]
  char buf; // [rsp+F40h] [rbp+E40h]
  hkgpMesh *v271; // [rsp+1230h] [rbp+1130h]
  hkgpMesh::HoleFillingConfig *v272; // [rsp+1238h] [rbp+1138h]
  __int64 v273; // [rsp+1238h] [rbp+1138h]
  char v274; // [rsp+1240h] [rbp+1140h]
  unsigned __int64 v275; // [rsp+1240h] [rbp+1140h]
  signed int v276; // [rsp+1248h] [rbp+1148h]
  __int64 v277; // [rsp+1248h] [rbp+1148h]

  v272 = config;
  v271 = this;
  v248 = this->m_triangles.m_numUsed;
  v2 = this->m_vertices.m_numUsed;
  v3 = 0i64;
  v4 = config;
  v5 = this;
  i = 0;
  v247 = v2;
  v236 = 0;
  array = 0i64;
  v6 = 0;
  v239 = 0;
  v240 = 2147483648;
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
      if ( v6 == (v240 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v6 = v239;
      }
      v239 = v6 + 1;
      hkGeometryProcessing::octahedronToNormal(&uv, &array[v6]);
      ++v8;
      if ( (signed __int64)v8 >= (signed __int64)&xmmword_141A71130 )
        break;
      v6 = v239;
    }
    ++v7;
    if ( (signed __int64)v7 >= (signed __int64)&xmmword_141A71130 )
      break;
    v6 = v239;
  }
  if ( v4->m_fillRings )
  {
    v10 = 0;
    v223 = 2147483648;
    v221 = 0i64;
    v222 = 0;
    while ( 1 )
    {
      v11 = v5->m_triangles.m_used;
      v12 = 0;
      v274 = 0;
      v245 = v11;
      if ( !v11 )
      {
LABEL_206:
        v222 = 0;
        if ( v223 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v221,
            8 * v223);
        v4 = v272;
        goto LABEL_209;
      }
LABEL_12:
      v13 = 0;
      v241 = 0;
      while ( 1 )
      {
        v261.m128i_i64[0] = (__int64)v11;
        v261.m128i_i32[2] = v13;
        if ( !(v11->m_links[v13] & 0xFFFFFFFFFFFFFFFCui64) )
        {
          _mm_store_si128((__m128i *)&v264, v261);
          v14 = hkgpMeshInternals::createRing((hkgpMeshBase::Edge *)&v264);
          v15 = v14;
          v252 = v14;
          if ( v14 )
          {
            if ( v14->m_segments.m_size >= 3 )
              break;
          }
        }
LABEL_204:
        v241 = ++v13;
        if ( v13 >= 3 )
        {
          v11 = v11->m_next;
          v245 = v11;
          if ( !v11 )
            goto LABEL_206;
          goto LABEL_12;
        }
      }
      v16 = 0;
      v222 = 0;
      if ( v14->m_segments.m_size > 0 )
      {
        v17 = 0i64;
        do
        {
          v18 = (signed int)v15->m_segments.m_data[v17].m_edge.m_index;
          v19 = v15->m_segments.m_data[v17].m_edge.m_triangle;
          if ( v16 == (v223 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v221, 8);
            v16 = v222;
          }
          *(_QWORD *)&v221[8 * v16] = v19->m_vertices[v18];
          ++v10;
          v16 = v222 + 1;
          ++v17;
          ++v222;
        }
        while ( v10 < v15->m_segments.m_size );
        v5 = v271;
        v12 = v274;
      }
      hkgpConvexHull::hkgpConvexHull(&v263);
      v20 = v222;
      v10 = 0;
      v227 = 0i64;
      v228 = 0;
      v229 = 2147483648;
      v21 = v222;
      if ( v222 <= 0 )
      {
        result.m_enum = 0;
      }
      else
      {
        if ( v222 < 0 )
          v20 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v227, v20, 16);
        v20 = v222;
      }
      v228 = v21;
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
          *(_OWORD *)&v227[v23 - 4] = *(_OWORD *)(*(_QWORD *)&v221[v24 - 8] + 32i64);
        }
        while ( v22 < v222 );
      }
      hkgpConvexHull::BuildConfig::BuildConfig(&configa);
      points.m_vertices = v227;
      configa.m_allowLowerDimensions.m_bool = 1;
      points.m_striding = 16;
      points.m_numVertices = v228;
      hkgpConvexHull::build(&v263, &points, &configa);
      if ( (signed int)hkgpConvexHull::getDimensions(&v263) >= 2 )
      {
        hkgpConvexHull::getBestProjectionPlane(&v263, &planeNormal);
        v25 = 0;
        v249 = 0i64;
        v242 = 0;
        while ( 1 )
        {
          if ( v25 >= v239 + 1 )
          {
LABEL_199:
            v11 = v245;
            v13 = v241;
            v10 = 0;
            goto LABEL_200;
          }
          v269.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable';
          _mm_store_si128((__m128i *)&v269.m_mesh.m_vertices, (__m128i)0i64);
          v269.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          _mm_store_si128((__m128i *)&v269.m_edgeDataPolicy, (__m128i)0i64);
          dmin.m_quad = (__m128)_xmm;
          dmax.m_quad = _xmm;
          v269.m_stack.m_data = v269.m_stack.m_storage;
          *(_DWORD *)&v269.m_memSizeAndFlags = 0x1FFFF;
          *(_DWORD *)&v269.m_mesh.m_memSizeAndFlags = 0x1FFFF;
          v269.m_mesh.m_vertices.m_numUsed = 0;
          v269.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
          v269.m_mesh.m_triangles.m_used = 0i64;
          v269.m_mesh.m_triangles.m_numUsed = 0;
          v269.m_stack.m_size = 0;
          v269.m_stack.m_capacityAndFlags = -2147483584;
          v269.m_status.m_storage = 0;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomain(
            &v269,
            &dmin,
            &dmax,
            0.0,
            1);
          uv.m_quad.m128_u64[0] = (unsigned __int64)v227;
          v26 = 1;
          uv.m_quad.m128_u64[1] = __PAIR__(16, v228);
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomainFromPlanarPoints(
            &v269,
            (hkStridedVertices *)&uv,
            &planeNormal,
            1,
            1,
            0);
          v27 = 0;
          if ( v222 > 0 )
          {
            v28 = 0i64;
            do
            {
              v29 = v269.m_margin;
              v30 = 0x7FFF - v269.m_margin;
              v31 = *(__m128 *)(*(_QWORD *)&v221[v28] + 32i64);
              v32 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v269.m_worldToLocal.m_col0.m_quad),
                          v269.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v269.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v269.m_worldToLocal.m_col2.m_quad));
              v33 = _mm_cmpltps(v32, (__m128)0i64);
              v34 = _mm_or_ps(
                      _mm_andnot_ps(v33, _mm_add_ps((__m128)xmmword_141A711B0, v32)),
                      _mm_and_ps(_mm_sub_ps(v32, (__m128)xmmword_141A711B0), v33));
              v35 = _mm_xor_si128(
                      (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v34),
                      _mm_cvttps_epi32(v34));
              v36 = _mm_cvtsi128_si32(v35);
              if ( v36 >= v269.m_margin )
              {
                if ( v36 > v30 )
                  v36 = 0x7FFF - v269.m_margin;
              }
              else
              {
                v36 = v269.m_margin;
              }
              v37 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v35, 85));
              if ( v37 >= v269.m_margin )
              {
                v29 = v37;
                if ( v37 > v30 )
                  v29 = 0x7FFF - v269.m_margin;
              }
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
                &v269,
                &location,
                v36,
                v29);
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(
                &v269,
                &data,
                v36,
                v29,
                1,
                &location,
                0);
              if ( data.m_type.m_storage )
              {
                v26 = 0;
              }
              else
              {
                v38 = data.m_edge.m_triangle->m_vertices[data.m_edge.m_index];
                *((_QWORD *)v38 + 3) = *((_DWORD *)v38 + 6) & 3 | (unsigned __int64)(4i64 * v27);
              }
              ++v27;
              v28 += 8i64;
            }
            while ( v27 < v222 );
          }
          v39 = v15->m_segments.m_size == 0;
          v40 = v15->m_segments.m_size < 0;
          v41 = 0;
          v224 = 0i64;
          v225 = 0;
          v226 = 2147483648;
          v42 = 0;
          if ( !v40 && !v39 )
          {
            v43 = 0i64;
            while ( 1 )
            {
              v44 = v15->m_segments.m_data;
              if ( v41 == (v226 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v224, 16);
                v41 = v225;
              }
              v45 = (hkgpMeshBase::Triangle **)&v224[2 * v41];
              if ( v45 )
              {
                *v45 = v44[v43].m_edge.m_triangle;
                v45[1] = *(hkgpMeshBase::Triangle **)&v44[v43].m_edge.m_index;
                v41 = v225;
              }
              v46 = v15->m_segments.m_data;
              v47 = v41 + 1;
              v225 = v47;
              v48 = v46[v43].m_edge.m_triangle;
              LODWORD(v265) = (9 >> 2 * LOBYTE(v46[v43].m_edge.m_index)) & 3;
              if ( v47 == (v226 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v224, 16);
                v47 = v225;
              }
              v49 = (hkgpMeshBase::Triangle **)&v224[2 * v47];
              if ( v49 )
              {
                v50 = v265;
                *v49 = v48;
                v49[1] = (hkgpMeshBase::Triangle *)v50;
                v47 = v225;
              }
              v51 = v15->m_segments.m_data;
              v52 = v47 + 1;
              v225 = v52;
              v53 = v51[v43].m_edge.m_triangle;
              LODWORD(v266) = (18 >> 2 * LOBYTE(v51[v43].m_edge.m_index)) & 3;
              if ( v52 == (v226 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v224, 16);
                v52 = v225;
              }
              v54 = (hkgpMeshBase::Triangle **)&v224[2 * v52];
              if ( v54 )
              {
                v55 = v266;
                *v54 = v53;
                v54[1] = (hkgpMeshBase::Triangle *)v55;
                v52 = v225;
              }
              data.m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)-9223372028264841215i64;
              v225 = v52 + 1;
              v56 = v269.m_margin;
              *(_QWORD *)&data.m_edge.m_index = v42;
              v57 = v15->m_segments.m_data;
              *(_QWORD *)&data.m_type.m_storage = (char *)&data + 16;
              v58 = v57[v43].m_edge.m_triangle;
              v59 = *(_QWORD *)&v57[v43].m_edge.m_index;
              v60 = 0x7FFF - v269.m_margin;
              v61 = v58->m_vertices[(signed int)v59]->m_position.m_quad;
              v62 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), v269.m_worldToLocal.m_col0.m_quad),
                          v269.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), v269.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), v269.m_worldToLocal.m_col2.m_quad));
              v63 = _mm_cmpltps(v62, (__m128)0i64);
              v64 = _mm_or_ps(
                      _mm_andnot_ps(v63, _mm_add_ps((__m128)xmmword_141A711B0, v62)),
                      _mm_and_ps(_mm_sub_ps(v62, (__m128)xmmword_141A711B0), v63));
              v65 = _mm_xor_si128(
                      (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v64),
                      _mm_cvttps_epi32(v64));
              v66 = _mm_cvtsi128_si32(v65);
              if ( v66 >= v269.m_margin )
              {
                if ( v66 > v60 )
                  v66 = 0x7FFF - v269.m_margin;
              }
              else
              {
                v66 = v269.m_margin;
              }
              v67 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v65, 85));
              if ( v67 >= v269.m_margin )
              {
                if ( v67 > v60 )
                  v67 = 0x7FFF - v269.m_margin;
              }
              else
              {
                v67 = v269.m_margin;
              }
              v68 = v58->m_vertices[(9i64 >> 2 * (unsigned __int8)v59) & 3]->m_position.m_quad;
              v69 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), v269.m_worldToLocal.m_col0.m_quad),
                          v269.m_worldToLocal.m_col3.m_quad),
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            v58->m_vertices[(9i64 >> 2 * (unsigned __int8)v59) & 3]->m_position.m_quad,
                            v68,
                            85),
                          v269.m_worldToLocal.m_col1.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v68, v68, 170), v269.m_worldToLocal.m_col2.m_quad));
              v70 = _mm_cmpltps(v69, (__m128)0i64);
              v71 = _mm_or_ps(
                      _mm_andnot_ps(v70, _mm_add_ps((__m128)xmmword_141A711B0, v69)),
                      _mm_and_ps(_mm_sub_ps(v69, (__m128)xmmword_141A711B0), v70));
              v72 = _mm_xor_si128(
                      (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v71),
                      _mm_cvttps_epi32(v71));
              v73 = _mm_cvtsi128_si32(v72);
              if ( v73 >= v269.m_margin )
              {
                if ( v73 > v60 )
                  v73 = 0x7FFF - v269.m_margin;
              }
              else
              {
                v73 = v269.m_margin;
              }
              v74 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v72, 85));
              if ( v74 >= v269.m_margin )
              {
                v56 = v74;
                if ( v74 > v60 )
                  v56 = 0x7FFF - v269.m_margin;
              }
              hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertEdge(
                &v269,
                (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&location,
                v66,
                v67,
                v73,
                v56,
                1,
                (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)&data);
              LODWORD(data.m_edge.m_triangle) = 0;
              if ( location.m_type.m_storage )
                v26 = 0;
              if ( SHIDWORD(data.m_edge.m_triangle) >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  *(void **)&data.m_type.m_storage,
                  8 * HIDWORD(data.m_edge.m_triangle));
              ++v42;
              ++v43;
              if ( v42 >= v15->m_segments.m_size )
                break;
              v41 = v225;
            }
          }
          LODWORD(v75) = v26;
          if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(&v269) < 2 )
            LODWORD(v75) = 0;
          v235 = (signed int)v75;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(&v269);
          v76 = v221;
          v77 = v269.m_mesh.m_triangles.m_used;
          v78 = 0;
          v276 = 0;
          do
          {
            if ( (_BYTE)v75 )
            {
              while ( v77 )
              {
                if ( (*((_WORD *)v77 + 33) & 0xFFE0) == 32 )
                {
                  v79 = 0;
                  if ( (_BYTE)v75 )
                  {
                    while ( 1 )
                    {
                      if ( v79 >= 3 )
                      {
                        v78 = v276;
                        goto LABEL_89;
                      }
                      if ( (*(_WORD *)((v77->m_links[v79] & 0xFFFFFFFFFFFFFFFCui64) + 66) & 0xFFE0) == 32 )
                      {
                        v80 = (9i64 >> 2 * (unsigned __int8)v79) & 3;
                        v81 = (signed int)(*((_QWORD *)v77->m_vertices[v79] + 3) >> 2);
                        v255 = v80;
                        v82 = v76[v81];
                        v83 = *((_QWORD *)v77->m_vertices[v80] + 3);
                        v256 = v82;
                        v84 = v76[(signed int)(v83 >> 2)];
                        v85 = 0i64;
                        v251 = v84;
                        v86 = 0;
                        v230 = 0;
                        v254 = 0i64;
                        if ( v225 > 0 )
                          break;
                      }
                      v78 = v276;
LABEL_148:
                      ++v79;
                      if ( !(_BYTE)v75 )
                        goto LABEL_89;
                    }
                    while ( 2 )
                    {
                      if ( *(_QWORD *)(v224[2 * v85] + 8i64 * SLODWORD(v224[2 * v85 + 1]) + 16) == v82
                        && *(_QWORD *)(v224[2 * v85] + 8 * ((9i64 >> 2 * LOBYTE(v224[2 * v85 + 1])) & 3) + 16) == v84
                        || *(_QWORD *)(v224[2 * v85] + 8i64 * SLODWORD(v224[2 * v85 + 1]) + 16) == v84
                        && *(_QWORD *)(v224[2 * v85] + 8 * ((9i64 >> 2 * LOBYTE(v224[2 * v85 + 1])) & 3) + 16) == v82 )
                      {
                        v87 = v77->m_links[v79];
                        if ( v87 & 0xFFFFFFFFFFFFFFFCui64 )
                        {
                          v88 = v77->m_vertices[v80];
                          v89 = v77->m_vertices[v79];
                          v90 = v89->m_x;
                          v91 = v88->m_x;
                          if ( v90 < v91 || v90 <= v91 && v89->m_y <= v88->m_y )
                          {
                            v93 = (unsigned __int64)v77;
                            LOBYTE(v92) = v79;
                          }
                          else
                          {
                            v92 = v77->m_links[v79] & 3;
                            v93 = v87 & 0xFFFFFFFFFFFFFFFCui64;
                          }
                          if ( !((1 << v92) & 7 & *(_BYTE *)(v93 + 66)) )
                          {
                            v94 = v77->m_links[v79] & 3;
                            v95 = v87 & 0xFFFFFFFFFFFFFFFCui64;
                            v96 = (18 >> 2 * v79) & 3;
                            v97 = *(_QWORD *)(v95 + 8i64 * ((18 >> 2 * v94) & 3) + 16);
                            v75 = v77->m_vertices[v96];
                            v98 = v75->m_y;
                            v99 = v75->m_x;
                            if ( (v89->m_x - v99) * (*(_DWORD *)(v97 + 20) - v98)
                               - (v89->m_y - v98) * (*(_DWORD *)(v97 + 16) - v99) > 0 )
                            {
                              v100 = *(_QWORD *)(v95 + 8i64 * (signed int)v94 + 16);
                              if ( (*(_DWORD *)(v100 + 16) - *(_DWORD *)(v97 + 16)) * (v98 - *(_DWORD *)(v97 + 20))
                                 - (*(_DWORD *)(v100 + 20) - *(_DWORD *)(v97 + 20)) * (v99 - *(_DWORD *)(v97 + 16)) > 0 )
                              {
                                v101 = v77->m_vertices[v96];
                                v102 = v77->m_vertices[(9i64 >> 2 * (unsigned __int8)v96) & 3];
                                v103 = v101->m_x;
                                v104 = v102->m_x;
                                if ( v103 >= v104
                                  && (v103 > v104 || v101->m_y > v102->m_y)
                                  && (v105 = v77->m_links[v96], v105 & 0xFFFFFFFFFFFFFFFCui64) )
                                {
                                  v106 = v77->m_links[v96] & 3;
                                  v107 = v105 & 0xFFFFFFFFFFFFFFFCui64;
                                }
                                else
                                {
                                  v107 = (unsigned __int64)v77;
                                  LOBYTE(v106) = (18 >> 2 * v79) & 3;
                                }
                                v108 = *(_WORD *)(v107 + 66);
                                v109 = (unsigned __int8)v108 & (1 << v106) & 7;
                                *(_WORD *)(v107 + 66) = v108 & (~((unsigned __int8)v108 & (1 << v106) & 7) | 0xFFF8);
                                v110 = v77->m_links[v79];
                                v111 = 2 * (v110 & 3);
                                v112 = v110 & 0xFFFFFFFFFFFFFFFCui64;
                                LODWORD(v107) = (18 >> v111) & 3;
                                v113 = *(_QWORD *)((v110 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v107 + 16);
                                v114 = *(_QWORD *)((v110 & 0xFFFFFFFFFFFFFFFCui64)
                                                 + 8 * ((9i64 >> 2 * ((18 >> v111) & 3u)) & 3)
                                                 + 16);
                                v115 = *(_DWORD *)(v113 + 16);
                                v116 = *(_DWORD *)(v114 + 16);
                                if ( v115 >= v116
                                  && (v115 > v116 || *(_DWORD *)(v113 + 20) > *(_DWORD *)(v114 + 20))
                                  && (v117 = *(_QWORD *)(v112 + 8i64 * (signed int)v107 + 40),
                                      v117 & 0xFFFFFFFFFFFFFFFCui64) )
                                {
                                  v107 = *(_QWORD *)(v112 + 8i64 * (signed int)v107 + 40) & 3i64;
                                  v118 = v117 & 0xFFFFFFFFFFFFFFFCui64;
                                }
                                else
                                {
                                  v118 = v112;
                                }
                                v119 = *(_WORD *)(v118 + 66);
                                v120 = (unsigned __int8)v119 & (1 << v107) & 7;
                                *(_WORD *)(v118 + 66) = v119 & (~((unsigned __int8)v119 & (1 << v107) & 7) | 0xFFF8);
                                v121 = v77->m_links[v79] & 0xFFFFFFFFFFFFFFFCui64;
                                v122 = v77->m_links[v79] & 3;
                                v123 = (signed int)v122;
                                v124 = (18 >> 2 * v122) & 3;
                                v77->m_vertices[v79] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(v121 + 8i64 * v124 + 16);
                                *(_QWORD *)(v121 + 8 * v123 + 16) = v77->m_vertices[v96];
                                v125 = v77->m_links[v96] & 0xFFFFFFFFFFFFFFFCui64;
                                v126 = v77->m_links[v96] & 3;
                                *(_QWORD *)(v121 + 8 * v123 + 40) = v125 + (v77->m_links[v96] & 3);
                                if ( v125 )
                                  *(_QWORD *)(v125 + 8i64 * (signed int)v126 + 40) = v121 + (unsigned int)v122;
                                v127 = *(_QWORD *)(v121 + 8i64 * v124 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                                v128 = *(_QWORD *)(v121 + 8i64 * v124 + 40) & 3i64;
                                v77->m_links[v79] = v127 + (*(_DWORD *)(v121 + 8i64 * v124 + 40) & 3);
                                if ( v127 )
                                  *(_QWORD *)(v127 + 8i64 * (signed int)v128 + 40) = (char *)v77 + (unsigned int)v79;
                                v77->m_links[v96] = v121 + (unsigned int)v124;
                                if ( v121 )
                                  *(_QWORD *)(v121 + 8i64 * v124 + 40) = (char *)v77 + (unsigned int)v96;
                                if ( v109 )
                                {
                                  v129 = v77->m_links[v96];
                                  v130 = v77->m_links[v96] & 0xFFFFFFFFFFFFFFFCui64;
                                  LODWORD(v131) = (9 >> 2 * (v129 & 3)) & 3;
                                  v132 = *(_QWORD *)(v130 + 8i64 * (signed int)v131 + 16);
                                  v133 = *(_QWORD *)(v130 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v129 & 3)) & 3u)) & 3) + 16);
                                  v134 = *(_DWORD *)(v132 + 16);
                                  v135 = *(_DWORD *)(v133 + 16);
                                  if ( v134 >= v135
                                    && (v134 > v135 || *(_DWORD *)(v132 + 20) > *(_DWORD *)(v133 + 20))
                                    && (v136 = *(_QWORD *)(v130 + 8i64 * (signed int)v131 + 40),
                                        v136 & 0xFFFFFFFFFFFFFFFCui64) )
                                  {
                                    v131 = *(_QWORD *)(v130 + 8i64 * (signed int)v131 + 40) & 3i64;
                                    v137 = v136 & 0xFFFFFFFFFFFFFFFCui64;
                                  }
                                  else
                                  {
                                    v137 = v77->m_links[v96] & 0xFFFFFFFFFFFFFFFCui64;
                                  }
                                  *(_WORD *)(v137 + 66) |= (1 << v131) & 7;
                                }
                                if ( v120 )
                                {
                                  LODWORD(v138) = (9 >> 2 * v96) & 3;
                                  v139 = v77->m_vertices[(signed int)v138];
                                  v140 = v77->m_vertices[(9i64 >> 2 * ((9 >> 2 * v96) & 3u)) & 3];
                                  v141 = v139->m_x;
                                  v142 = v140->m_x;
                                  if ( v141 >= v142
                                    && (v141 > v142 || v139->m_y > v140->m_y)
                                    && (v143 = v77->m_links[(signed int)v138], v143 & 0xFFFFFFFFFFFFFFFCui64) )
                                  {
                                    v138 = v77->m_links[(signed int)v138] & 3;
                                    v144 = v143 & 0xFFFFFFFFFFFFFFFCui64;
                                  }
                                  else
                                  {
                                    v144 = (unsigned __int64)v77;
                                  }
                                  *(_WORD *)(v144 + 66) ^= ((unsigned __int8)*(_WORD *)(v144 + 66) ^ (unsigned __int8)(*(unsigned __int16 *)(v144 + 66) | (1 << v138))) & 7;
                                }
                                LODWORD(v75) = v235;
                                v86 = v230;
                                v84 = v251;
                                v78 = -1;
                                v276 = -1;
LABEL_145:
                                v80 = v255;
                                v82 = v256;
                                ++v86;
                                v85 = v254++ + 1;
                                v230 = v86;
                                if ( v86 >= v225 )
                                {
                                  v76 = v221;
                                  goto LABEL_148;
                                }
                                continue;
                              }
                            }
                            v86 = v230;
                          }
                        }
                        v84 = v251;
                        LOBYTE(v75) = 0;
                        v235 = (signed int)v75;
                      }
                      break;
                    }
                    v78 = v276;
                    goto LABEL_145;
                  }
                }
                v78 = v276;
LABEL_89:
                v77 = v77->m_next;
                if ( !(_BYTE)v75 )
                  goto LABEL_152;
              }
              v78 = v276;
LABEL_152:
              v77 = v269.m_mesh.m_triangles.m_used;
            }
            v276 = ++v78;
          }
          while ( v78 < 1 );
          if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeDataOrientation(&v269)
            || !(_BYTE)v75 )
          {
            break;
          }
          v145 = v222;
          edges.m_data = 0i64;
          edges.m_size = 0;
          edges.m_capacityAndFlags = 2147483648;
          v231 = 0i64;
          v232 = 0;
          v277 = v222;
          v233 = 2147483648;
          if ( v77 )
          {
            v146 = v252;
            do
            {
              if ( (*((_WORD *)v77 + 33) & 0xFFE0) == 32 )
              {
                v147 = (hkVector4f *)v76[(signed int)(*((_QWORD *)v77->m_vertices[0] + 3) >> 2)];
                v148 = (hkVector4f *)v76[(signed int)(*((_QWORD *)v77->m_vertices[1] + 3) >> 2)];
                v149 = (hkVector4f *)v76[(signed int)(*((_QWORD *)v77->m_vertices[2] + 3) >> 2)];
                v150 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&v271->m_triangles);
                v151 = (__int64)v245;
                v150->m_partId = v245->m_partId;
                v150->m_links[0] = 0i64;
                v150->m_links[1] = 0i64;
                v150->m_links[2] = 0i64;
                v150->m_material = *(_DWORD *)(v151 + 88);
                v150->m_vertices[0] = (hkgpMeshBase::Vertex *)v147;
                v150->m_vertices[1] = (hkgpMeshBase::Vertex *)v148;
                v150->m_vertices[2] = (hkgpMeshBase::Vertex *)v149;
                hkgpMesh::setPlane(v271, v147 + 2, v148 + 2, v149 + 2, &v150->m_plane, 1);
                v152 = 0;
                do
                {
                  v153 = v77->m_links[v152];
                  edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v77->m_links[v152] & 0xFFFFFFFFFFFFFFFCui64);
                  edge.m_index = v153 & 3;
                  v154 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
                           &v269,
                           &edge);
                  if ( v154 )
                  {
                    v155 = (signed __int64)&v146->m_segments.m_data[(signed __int64)*(signed int *)v154->m_tags.m_data];
                    v150->m_links[v152] = *(_QWORD *)v155 + *(unsigned int *)(v155 + 8);
                    if ( *(_QWORD *)v155 )
                      *(_QWORD *)(*(_QWORD *)v155 + 8i64 * *(signed int *)(v155 + 8) + 40) = (char *)v150
                                                                                           + (unsigned int)v152;
                  }
                  else
                  {
                    LODWORD(v258) = v152;
                    if ( edges.m_size == (edges.m_capacityAndFlags & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &edges,
                        16);
                    v156 = &edges.m_data[edges.m_size];
                    if ( v156 )
                    {
                      v157 = v258;
                      v156->m_triangle = v150;
                      *(_QWORD *)&v156->m_index = v157;
                    }
                    ++edges.m_size;
                  }
                  ++v152;
                }
                while ( v152 < 3 );
                v158 = v232;
                if ( v232 == (v233 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v231, 8);
                  v158 = v232;
                }
                v231[v158] = v150;
                ++v232;
                v76 = v221;
              }
              v77 = v77->m_next;
            }
            while ( v77 );
            LOBYTE(v75) = v235;
            v145 = v277;
          }
          v5 = v271;
          hkgpMesh::bindEdgeList(v271, &edges);
          if ( edges.m_size )
          {
            LOBYTE(v75) = 0;
            v159 = 0;
            if ( v232 > 0 )
            {
              v160 = 0i64;
              do
              {
                hkgpMesh::removeTriangle(v271, (hkgpMeshBase::Triangle *)v231[v160]);
                ++v159;
                ++v160;
              }
              while ( v159 < v232 );
            }
            v161 = v145;
            if ( v145 < v222 )
            {
              v162 = 8i64 * v145;
              do
              {
                hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::release(
                  &v271->m_vertices,
                  *(hkgpMeshBase::Vertex **)&v221[v162]);
                ++v161;
                v162 += 8i64;
              }
              while ( v161 < v222 );
            }
            if ( (v223 & 0x3FFFFFFF) >= v145 )
            {
              v246.m_enum = 0;
            }
            else
            {
              v163 = v145;
              if ( v145 < 2 * (v223 & 0x3FFFFFFF) )
                v163 = 2 * (v223 & 0x3FFFFFFF);
              hkArrayUtil::_reserve(
                &v246,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v221,
                v163,
                8);
            }
            v222 = v145;
          }
          else
          {
            ++i;
            v274 = 1;
          }
          v232 = 0;
          if ( v233 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v231,
              8 * v233);
          v231 = 0i64;
          v233 = 2147483648;
          edges.m_size = 0;
          if ( edges.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              edges.m_data,
              16 * edges.m_capacityAndFlags);
          edges.m_data = 0i64;
          edges.m_capacityAndFlags = 2147483648;
          if ( !(_BYTE)v75 )
            goto LABEL_222;
          v164 = v249;
LABEL_194:
          v225 = 0;
          if ( v226 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v224,
              16 * v226);
          v224 = 0i64;
          v226 = 2147483648;
          v269.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable';
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(
            &v269,
            1);
          hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(&v269.m_edgeDataPolicy);
          v269.m_stack.m_size = 0;
          if ( v269.m_stack.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v269.m_stack.m_data,
              16 * v269.m_stack.m_capacityAndFlags);
          v269.m_stack.m_data = 0i64;
          v269.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable';
          v269.m_stack.m_capacityAndFlags = 2147483648;
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::reset(&v269.m_mesh.m_triangles);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>(&v269.m_mesh.m_triangles.m_allocator);
          hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset(&v269.m_mesh.m_vertices);
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>(&v269.m_mesh.m_vertices.m_allocator);
          v12 = v274;
          v15 = v252;
          v25 = v242++ + 1;
          v249 = v164 + 1;
          if ( v274 )
            goto LABEL_199;
        }
        v5 = v271;
LABEL_222:
        v164 = v249;
        if ( v249 )
          planeNormal.m_quad = (__m128)array[v249 - 1];
        goto LABEL_194;
      }
LABEL_200:
      hkgpMeshInternals::Ring::`scalar deleting destructor'(v15, 1u);
      v228 = 0;
      if ( !v12 )
        break;
      if ( v229 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v227,
          16 * v229);
      v227 = 0i64;
      v229 = 2147483648;
      hkgpConvexHull::~hkgpConvexHull(&v263);
    }
    if ( v229 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v227,
        16 * v229);
    v227 = 0i64;
    v229 = 2147483648;
    hkgpConvexHull::~hkgpConvexHull(&v263);
    goto LABEL_204;
  }
LABEL_209:
  v165 = v271;
  if ( v4->m_fillAFM )
  {
    while ( 1 )
    {
      v166 = (__m128 *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      v167 = `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard';
      for ( k = 1; ; k = 0 )
      {
        if ( !(v167 & 1) )
        {
          v167 |= 1u;
          v166 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' = v167;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        }
        v169 = DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        v170 = v166;
        v273 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
               + 1);
        if ( !(v167 & 1) )
        {
          v167 |= 1u;
          v166 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' = v167;
        }
        v171 = (__m128 *)v165->m_triangles.m_used;
        v172 = BYTE8(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e);
        v173 = *(float *)&xmmword_141A712A0;
        v174 = v166;
        v275 = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
               + 1);
        if ( v171 )
        {
          while ( 1 )
          {
            v175 = 0;
            do
            {
              LODWORD(v258) = v175;
              if ( !(v171[2].m128_u64[v175 + 1] & 0xFFFFFFFFFFFFFFFCui64) )
              {
                v176 = (unsigned __int64)v171;
                v177 = (9 >> 2 * v175) & 3;
                if ( v171[2].m128_u64[v177 + 1] & 0xFFFFFFFFFFFFFFFCui64 )
                {
                  while ( 1 )
                  {
                    v178 = *(_QWORD *)(v176 + 8i64 * v177 + 40);
                    v179 = (__m128 *)(*(_QWORD *)(v176 + 8i64 * v177 + 40) & 0xFFFFFFFFFFFFFFFCui64);
                    uv.m_quad.m128_u64[0] = (unsigned __int64)v179;
                    v180 = (9 >> 2 * (v178 & 3)) & 3;
                    uv.m_quad.m128_i32[2] = v180;
                    v39 = (v179[2].m128_u64[v180 + 1] & 0xFFFFFFFFFFFFFFFCui64) == 0;
                    _mm_store_si128((__m128i *)&planeNormal, (__m128i)uv.m_quad);
                    if ( v39 )
                      break;
                    v177 = planeNormal.m_quad.m128_i32[2];
                    v176 = planeNormal.m_quad.m128_u64[0];
                  }
                  if ( v179 != v171 )
                  {
                    v181 = *(__m128 *)(v171[1].m128_u64[(9i64 >> 2 * (unsigned __int8)v175) & 3] + 32);
                    v182 = _mm_sub_ps(*(__m128 *)(v171[1].m128_u64[v175] + 32), v181);
                    v183 = _mm_sub_ps(*(__m128 *)(v179[1].m128_u64[(9i64 >> 2 * (unsigned __int8)v180) & 3] + 32), v181);
                    v184 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v182),
                             _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), v183));
                    v185 = _mm_shuffle_ps(v184, v184, 201);
                    if ( !k
                      || (v186 = _mm_mul_ps(v171[4], v185),
                          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 170))) > v3.m128_f32[0])
                      && (v187 = _mm_mul_ps(v179[4], v185),
                          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 170))) > v3.m128_f32[0]) )
                    {
                      v188 = _mm_mul_ps(v182, v182);
                      v189 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v188, v188, 85), _mm_shuffle_ps(v188, v188, 0)),
                               _mm_shuffle_ps(v188, v188, 170));
                      v190 = _mm_rsqrt_ps(v189);
                      v191 = _mm_cmpltps(_mm_sub_ps(v3, v189), v3);
                      if ( _mm_movemask_ps(v191) )
                      {
                        v192 = _mm_mul_ps(v183, v183);
                        v193 = _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v192, v192, 85), _mm_shuffle_ps(v192, v192, 0)),
                                 _mm_shuffle_ps(v192, v192, 170));
                        v194 = _mm_cmpltps(_mm_sub_ps(v3, v193), v3);
                        v195 = _mm_rsqrt_ps(v193);
                        if ( _mm_movemask_ps(v194) )
                        {
                          v196 = _mm_mul_ps(
                                   _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmpleps(v189, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v190, v189), v190)),
                                             _mm_mul_ps(v190, *(__m128 *)_xmm))),
                                         v182),
                                       v191),
                                     _mm_andnot_ps(v191, v182)),
                                   _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmpleps(v193, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v195, v193), v195)),
                                             _mm_mul_ps(v195, *(__m128 *)_xmm))),
                                         v183),
                                       v194),
                                     _mm_andnot_ps(v194, v183)));
                          v197 = _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v196, v196, 85), _mm_shuffle_ps(v196, v196, 0)),
                                   _mm_shuffle_ps(v196, v196, 170));
                          v198 = _mm_andnot_ps(*(__m128 *)_xmm, v197);
                          v199 = _mm_cmpltps(*(__m128 *)_xmm, v198);
                          v200 = _mm_cmpltps(v198, *(__m128 *)_xmm);
                          v201 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v198), *(__m128 *)_xmm);
                          v202 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v201), v199), _mm_andnot_ps(v199, v198));
                          v203 = _mm_or_ps(_mm_andnot_ps(v199, _mm_mul_ps(v198, v198)), _mm_and_ps(v199, v201));
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
                          v3 = 0i64;
                          v205 = 1.5707964
                               - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                        v200,
                                                                        _mm_or_ps(
                                                                          _mm_and_ps(
                                                                            _mm_sub_ps(
                                                                              *(__m128 *)_xmm,
                                                                              _mm_add_ps(v204, v204)),
                                                                            v199),
                                                                          _mm_andnot_ps(v199, v204))) | v200.m128_i32[0] & v198.m128_i32[0]) ^ v197.m128_i32[0] & _xmm[0]);
                          if ( v205 < v173 )
                          {
                            v169 = v258;
                            v172 = uv.m_quad.m128_i8[8];
                            v170 = v171;
                            v173 = v205;
                            v273 = v258;
                            v275 = uv.m_quad.m128_u64[1];
                            v174 = v179;
                            goto LABEL_238;
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
                v172 = v275;
              }
              v169 = v273;
LABEL_238:
              ++v175;
            }
            while ( v175 < 3 );
            v171 = (__m128 *)v171->m128_u64[0];
            if ( !v171 )
            {
              v165 = v271;
              break;
            }
          }
        }
        if ( v170 )
          break;
        if ( !k )
          goto LABEL_247;
      }
      v206 = v169;
      v207 = (hkVector4f *)v170[1].m128_u64[v169];
      v208 = (hkVector4f *)v170[1].m128_u64[(9i64 >> 2 * (unsigned __int8)v169) & 3];
      v209 = (hkVector4f *)v174[1].m128_u64[(9i64 >> 2 * v172) & 3];
      v210 = hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Triangle,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>>::allocate(&v165->m_triangles);
      v210->m_partId = v170[5].m128_i32[0];
      v211 = v210;
      v210->m_links[0] = 0i64;
      v210->m_links[1] = 0i64;
      v210->m_links[2] = 0i64;
      v210->m_material = v170[5].m128_i32[2];
      v210->m_vertices[0] = (hkgpMeshBase::Vertex *)v208;
      v210->m_vertices[1] = (hkgpMeshBase::Vertex *)v207;
      v210->m_vertices[2] = (hkgpMeshBase::Vertex *)v209;
      hkgpMesh::setPlane(v271, v208 + 2, v207 + 2, v209 + 2, &v210->m_plane, 1);
      v170[2].m128_u64[v206 + 1] = (unsigned __int64)v211;
      v211->m_links[0] = (unsigned __int64)v170 + (unsigned int)v273;
      v211->m_links[2] = (unsigned __int64)v174 + (unsigned int)v275;
      if ( v174 )
        v174[2].m128_u64[(signed int)v275 + 1] = (unsigned __int64)&v211->m_next + 2;
      ++v236;
      v165 = v271;
    }
  }
LABEL_247:
  v165->m_hasPerVertexNormals = 0;
  hkErrStream::hkErrStream((hkErrStream *)&data, &buf, 512);
  hkOstream::operator<<((hkOstream *)&data, "HOLE FILLING STATS:");
  hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2792);
  hkOstream::~hkOstream((hkOstream *)&data);
  hkErrStream::hkErrStream((hkErrStream *)&data, &buf, 512);
  v212 = v165->m_vertices.m_numUsed - v247;
  v213 = v165->m_triangles.m_numUsed - v248;
  v214 = hkOstream::operator<<((hkOstream *)&data, "\tCreated: ");
  v215 = hkOstream::operator<<(v214, v213, (int)v214);
  v216 = hkOstream::operator<<(v215, " triangles and ");
  v217 = hkOstream::operator<<(v216, v212, (int)v216);
  hkOstream::operator<<(v217, " vertices");
  hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2793);
  hkOstream::~hkOstream((hkOstream *)&data);
  hkErrStream::hkErrStream((hkErrStream *)&data, &buf, 512);
  v218 = hkOstream::operator<<((hkOstream *)&data, "\tRings: ");
  v219 = hkOstream::operator<<(v218, i, (int)v218);
  v220 = hkOstream::operator<<(v219, " AFM: ");
  hkOstream::operator<<(v220, v236, (int)v220);
  hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2794);
  hkOstream::~hkOstream((hkOstream *)&data);
  v239 = 0;
  if ( v240 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v240);
}

// File Line: 2799
// RVA: 0xCD1C90
void __fastcall hkgpMesh::fixTJunctions(hkgpMesh *this, float maxDistanceToEdgeR, bool report)
{
  hkgpMesh *v3; // r14
  __m128 v4; // xmm8
  float v5; // xmm6_4
  hkgpMeshBase::Triangle *v6; // r15
  char v7; // si
  signed int v8; // er12
  __m128 *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v10; // rbx
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  signed __int64 v14; // rax
  __m128 *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  hkLifoAllocator *v18; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector> *v19; // r9
  hkcdDynamicTree::CodecRawUlong *v20; // rcx
  unsigned __int64 v21; // rdx
  int v22; // eax
  char *v23; // rdi
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // er8
  signed int v27; // er13
  __m128i v28; // xmm7
  __int64 v29; // r12
  hkgpMeshBase::Triangle *v30; // rsi
  signed int v31; // ebx
  hkVector4f **v32; // rdi
  hkgpMeshBase::Vertex *v33; // r14
  hkVector4f *v34; // rdx
  hkVector4f *v35; // r8
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  hkVector4f *v38; // r9
  __m128 v39; // xmm3
  __m128 v40; // xmm3
  hkOstream *v41; // rax
  hkgpMeshBase::Vertex *v42; // r9
  signed int v43; // [rsp+30h] [rbp-90h]
  int i; // [rsp+34h] [rbp-8Ch]
  char *v45; // [rsp+38h] [rbp-88h]
  __int64 v46; // [rsp+40h] [rbp-80h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+48h] [rbp-78h]
  __int64 v48; // [rsp+70h] [rbp-50h]
  hkSimdFloat32 result; // [rsp+80h] [rbp-40h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+90h] [rbp-30h]
  __m128 v51; // [rsp+B0h] [rbp-10h]
  char buf; // [rsp+C0h] [rbp+0h]
  __int64 v53; // [rsp+100h] [rbp+40h]
  hkgpMesh *v54; // [rsp+340h] [rbp+280h]
  unsigned int v55; // [rsp+348h] [rbp+288h]
  char v56; // [rsp+350h] [rbp+290h]
  char v57; // [rsp+358h] [rbp+298h]

  v3 = this;
  hkErrStream::hkErrStream((hkErrStream *)&tree.m_root, &v53, 512);
  hkOstream::operator<<(
    (hkOstream *)&tree.m_root,
    "hkgpMesh::fixTJunctions as been deprecated, use hkGeometryProcessing::fixTJunctions instead.");
  hkError::messageWarning(-1111330674, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2800);
  hkOstream::~hkOstream((hkOstream *)&tree.m_root);
  i = 0;
  v4 = _mm_shuffle_ps((__m128)v55, (__m128)v55, 0);
  v5 = v4.m128_f32[0] * v4.m128_f32[0];
  hkgpMesh::rebuildTrianglesTree(v3, 0.0);
  do
  {
    v6 = v3->m_triangles.m_used;
    v7 = 0;
    v57 = 0;
    if ( !v6 )
      break;
    do
    {
      v8 = 0;
      v43 = 0;
      do
      {
        *(_QWORD *)&tree.m_nodes.m_size = v6;
        LODWORD(tree.m_firstFree) = v8;
        if ( !(v6->m_links[v8] & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v9 = (__m128 *)v6->m_vertices[v8];
          v10 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v3->m_trianglesTree;
          v45 = 0i64;
          v11 = _mm_add_ps(v4, v4);
          v46 = 0x8000000000000000i64;
          v12 = v9[2];
          v13 = v9[2];
          stackInstance.m_stack.m_size = 1;
          tree.m_nodes.m_data = 0i64;
          tree.m_nodes.m_size = 0;
          v14 = (9i64 >> 2 * (unsigned __int8)v8) & 3;
          tree.m_nodes.m_capacityAndFlags = 2147483648;
          tree.m_numLeaves = 64;
          v46 = v14;
          v15 = (__m128 *)v6->m_vertices[v14];
          v16 = _mm_min_ps(v13, v15[2]);
          v17 = _mm_max_ps(v12, v15[2]);
          stackInstance.m_stack.m_data = (unsigned __int64 *)&v45;
          *(__m128 *)&stackInstance.m_stack.m_localMemory = _mm_sub_ps(v16, v11);
          v51 = _mm_add_ps(v17, v11);
          v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v20 = (hkcdDynamicTree::CodecRawUlong *)v18->m_cur;
          v21 = (unsigned __int64)&v20[8];
          if ( v18->m_slabSize < 512 || (void *)v21 > v18->m_end )
            v20 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v18, 512);
          else
            v18->m_cur = (void *)v21;
          tree.m_nodes.m_data = v20;
          tree.m_firstFree = (unsigned __int64)v20;
          tree.m_nodes.m_capacityAndFlags = -2147483584;
          hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector>>(
            v10,
            &tree,
            &stackInstance,
            v19);
          v22 = tree.m_nodes.m_size;
          v23 = (char *)tree.m_firstFree;
          if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
            v22 = 0;
          tree.m_nodes.m_size = v22;
          v24 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
          v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v26 = (v24 + 15) & 0xFFFFFFF0;
          if ( v24 > v25->m_slabSize || &v23[v26] != v25->m_cur || v25->m_firstNonLifoEnd == v23 )
            hkLifoAllocator::slowBlockFree(v25, v23, v26);
          else
            v25->m_cur = v23;
          tree.m_nodes.m_size = 0;
          if ( tree.m_nodes.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              tree.m_nodes.m_data,
              8 * tree.m_nodes.m_capacityAndFlags);
          v27 = 0;
          if ( (signed int)v46 > 0 )
          {
            v28 = *(__m128i *)&tree.m_nodes.m_size;
            v29 = 0i64;
            do
            {
              if ( v7 )
                break;
              v30 = *(hkgpMeshBase::Triangle **)&v45[v29];
              if ( v30 == v6 )
              {
                v7 = v57;
              }
              else
              {
                v31 = 0;
                v32 = (hkVector4f **)v30->m_vertices;
                while ( 1 )
                {
                  if ( !(v30->m_links[v31] & 0xFFFFFFFFFFFFFFFCui64)
                    || !(v30->m_links[(18 >> 2 * v31) & 3] & 0xFFFFFFFFFFFFFFFCui64) )
                  {
                    v33 = (hkgpMeshBase::Vertex *)*v32;
                    v34 = *v32 + 2;
                    v35 = &v6->m_vertices[v43]->m_position;
                    v36 = _mm_sub_ps(v34->m_quad, v35->m_quad);
                    v37 = _mm_mul_ps(v36, v36);
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170))) > v5 )
                    {
                      v38 = &v6->m_vertices[v46]->m_position;
                      v39 = _mm_sub_ps(v34->m_quad, v38->m_quad);
                      v40 = _mm_mul_ps(v39, v39);
                      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) > v5 )
                      {
                        hkGeometryProcessing::squaredDistanceFromPointToLine(
                          &result,
                          v34,
                          v35,
                          v38,
                          (hkSimdFloat32 *)&tree.m_numLeaves);
                        if ( *(float *)&tree.m_numLeaves > 0.00000011920929
                          && *(float *)&tree.m_numLeaves < (float)(1.0 - 0.00000011920929)
                          && result.m_real.m128_f32[0] <= v5 )
                        {
                          break;
                        }
                      }
                    }
                  }
                  ++v31;
                  ++v32;
                  if ( v31 >= 3 )
                  {
                    v7 = v57;
                    v3 = v54;
                    goto LABEL_32;
                  }
                }
                v42 = v33;
                v3 = v54;
                _mm_store_si128((__m128i *)&v48, v28);
                hkgpMesh::splitEdge(v3, (hkgpMeshBase::Edge *)&tree.m_root, (hkgpMeshBase::Edge *)&v48, v42, 0);
                hkgpMesh::rebuildTrianglesTree(v3, 0.0);
                ++i;
                v7 = 1;
                v57 = 1;
              }
LABEL_32:
              ++v27;
              v29 += 8i64;
            }
            while ( v27 < (signed int)v46 );
            v8 = v43;
          }
          LODWORD(v46) = 0;
          if ( v46 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v45,
              8 * HIDWORD(v46));
          v45 = 0i64;
          HIDWORD(v46) = 2147483648;
        }
        v43 = ++v8;
      }
      while ( v8 < 3 );
      v6 = v6->m_next;
    }
    while ( v6 );
  }
  while ( v7 );
  if ( v56 )
  {
    if ( i )
    {
      hkErrStream::hkErrStream((hkErrStream *)&tree.m_root, &buf, 512);
      v41 = hkOstream::operator<<((hkOstream *)&tree.m_root, "T-Junctions fixed: ");
      hkOstream::operator<<(v41, i, (int)v41);
      hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2858);
      hkOstream::~hkOstream((hkOstream *)&tree.m_root);
      hkgpMesh::fixBindings(v3);
      v3->m_hasPerVertexNormals = 0;
    }
  }
}

// File Line: 2866
// RVA: 0xCD21B0
void __fastcall hkgpMesh::fixBindings(hkgpMesh *this)
{
  hkgpMesh *v1; // r14
  int v2; // ebx
  hkgpMeshBase::Triangle *v3; // rdi
  int v4; // er8
  signed int v5; // ebx
  hkgpMeshBase::Triangle **v6; // rax
  hkgpMeshBase::Triangle *v7; // rcx
  int v8; // esi
  __int32 v9; // edi
  signed __int64 v10; // r13
  __int64 v11; // r12
  signed int v12; // er15
  int v13; // er11
  signed __int64 v14; // r9
  __int64 v15; // r14
  __int64 v16; // r10
  __int64 v17; // rbx
  __int64 v18; // rdi
  __int64 v19; // rdx
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkOstream *v22; // rax
  int v23; // er8
  signed __int64 v24; // rcx
  __int64 v25; // r9
  __int64 v26; // rdx
  __int64 v27; // rax
  char *array; // [rsp+30h] [rbp-C8h]
  int i; // [rsp+38h] [rbp-C0h]
  int v30; // [rsp+3Ch] [rbp-BCh]
  hkErrStream v31; // [rsp+40h] [rbp-B8h]
  char buf; // [rsp+60h] [rbp-98h]
  hkgpMesh *retaddr; // [rsp+2A8h] [rbp+1B0h]
  int v34; // [rsp+2B0h] [rbp+1B8h]
  hkResult result; // [rsp+2B8h] [rbp+1C0h]
  int v36; // [rsp+2C0h] [rbp+1C8h]

  v1 = this;
  v2 = 0;
  array = 0i64;
  i = 0;
  v30 = 2147483648;
  v34 = 0;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 1024, 16);
  v3 = v1->m_triangles.m_used;
  v4 = i;
  if ( v3 )
  {
    do
    {
      v5 = 0;
      do
      {
        if ( !(v3->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64) )
        {
          *(_DWORD *)&v31.m_memSizeAndFlags = v5;
          if ( v4 == (v30 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v4 = i;
          }
          v6 = (hkgpMeshBase::Triangle **)&array[16 * v4];
          if ( v6 )
          {
            v7 = *(hkgpMeshBase::Triangle **)&v31.m_memSizeAndFlags;
            *v6 = v3;
            v6[1] = v7;
            v4 = i;
          }
          i = ++v4;
        }
        ++v5;
      }
      while ( v5 < 3 );
      v3 = v3->m_next;
    }
    while ( v3 );
    v2 = 0;
  }
  v8 = v4;
  v36 = v4;
  v9 = 0;
  result.m_enum = 0;
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
        v15 = (__int64)&array[v11];
        v16 = (__int64)&array[v11 + 16];
        while ( 1 )
        {
          v17 = *(_QWORD *)v16;
          if ( !*(_QWORD *)v16 )
            break;
          v18 = *(signed int *)(v16 + 8);
          v19 = *(signed int *)(v15 + 8);
          if ( *(_QWORD *)(*(_QWORD *)v15 + 8 * v19 + 16) == *(_QWORD *)(v17
                                                                       + 8 * ((9i64 >> 2 * (unsigned __int8)v18) & 3)
                                                                       + 16)
            && *(_QWORD *)(*(_QWORD *)v15 + 8 * ((9i64 >> 2 * (unsigned __int8)v19) & 3) + 16) == *(_QWORD *)(v17 + 8 * v18 + 16) )
          {
            break;
          }
          ++v13;
          ++v14;
          v16 += 16i64;
          if ( v13 >= v4 )
          {
            v9 = result.m_enum;
            v2 = v34;
            goto LABEL_21;
          }
        }
        *(_QWORD *)(*(_QWORD *)v15 + 8i64 * *(signed int *)(v15 + 8) + 40) = v17 + *(unsigned int *)(v16 + 8);
        if ( *(_QWORD *)v16 )
          *(_QWORD *)(*(_QWORD *)v16 + 8i64 * *(signed int *)(v16 + 8) + 40) = *(_QWORD *)v15
                                                                             + *(unsigned int *)(v15 + 8);
        v4 = i - 1;
        i = v4;
        if ( v4 != v13 )
        {
          v24 = 2i64;
          v25 = (__int64)&array[16 * v14];
          v26 = (__int64)&array[16 * v4 - v25];
          do
          {
            v27 = *(_QWORD *)(v26 + v25);
            v25 += 8i64;
            *(_QWORD *)(v25 - 8) = v27;
            --v24;
          }
          while ( v24 );
          v4 = i;
        }
        --v12;
        v2 = v34 + 1;
        v9 = result.m_enum - 1;
        --v10;
        ++v34;
        v11 -= 16i64;
      }
LABEL_21:
      ++v9;
      ++v12;
      ++v10;
      v11 += 16i64;
      result.m_enum = v9;
    }
    while ( v9 < v4 );
    v8 = v36;
    v1 = retaddr;
  }
  if ( v8 )
  {
    hkErrStream::hkErrStream(&v31, &buf, 512);
    v20 = hkOstream::operator<<((hkOstream *)&v31.vfptr, "Naked edges found: ");
    v21 = hkOstream::operator<<(v20, v8, (int)v20);
    v22 = hkOstream::operator<<(v21, " fixed:");
    hkOstream::operator<<(v22, 2 * v2, (int)v22);
    hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 2892);
    hkOstream::~hkOstream((hkOstream *)&v31.vfptr);
  }
  v23 = v30;
  v1->m_hasPerVertexNormals = 0;
  i = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v23);
}

// File Line: 2899
// RVA: 0xCD2550
void __fastcall hkgpMesh::removePartTriangles(hkgpMesh *this, int id)
{
  int v2; // esi
  hkgpMeshBase::Triangle *v3; // rdx
  hkgpMesh *v4; // rdi
  hkgpMeshBase::Triangle *v5; // rbx

  v2 = id;
  v3 = this->m_triangles.m_used;
  v4 = this;
  if ( v3 )
  {
    do
    {
      v5 = v3->m_next;
      if ( v3->m_partId == v2 )
        hkgpMesh::removeTriangle(v4, v3);
      v3 = v5;
    }
    while ( v5 );
    v4->m_hasPerVertexNormals = 0;
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
  int v2; // esi
  hkgpMeshBase::Triangle *v3; // rdx
  hkgpMesh *v4; // rdi
  hkgpMeshBase::Triangle *v5; // rbx

  v2 = id;
  v3 = this->m_triangles.m_used;
  v4 = this;
  if ( v3 )
  {
    do
    {
      v5 = v3->m_next;
      if ( v3->m_planeId == v2 )
        hkgpMesh::removeTriangle(v4, v3);
      v3 = v5;
    }
    while ( v5 );
    v4->m_hasPerVertexNormals = 0;
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
  hkgpMeshBase::Triangle *v3; // rax
  hkgpMeshBase::Triangle *v4; // rcx

  v3 = this->m_triangles.m_used;
  if ( v3 )
  {
    do
    {
      v4 = v3->m_next;
      if ( v3->m_planeId == from_id )
        v3->m_planeId = to_id;
      v3 = v4;
    }
    while ( v4 );
  }
}

// File Line: 2934
// RVA: 0xCD2660
void __fastcall hkgpMesh::removePartFromClassification(hkgpMesh *this, int id, hkTransformf *transform, hkgpMesh *classifier, bool removeInside)
{
  hkgpMeshBase::Triangle *v5; // rbx
  hkgpMesh *v6; // r15
  hkTransformf *v7; // r12
  int v8; // ebp
  hkgpMesh *v9; // rsi
  hkgpMeshBase::Triangle *v10; // rdi
  hkgpMeshBase::Vertex *v11; // rax
  __m128 *v12; // rcx
  __m128 v13; // xmm0
  __m128 *v14; // rax
  __m128 v15; // xmm2
  hkgpMeshBase::Triangle *v16; // rax
  hkVector4f x; // [rsp+20h] [rbp-C8h]
  hkgpMesh::Location location; // [rsp+30h] [rbp-B8h]

  v5 = this->m_triangles.m_used;
  v6 = classifier;
  v7 = transform;
  v8 = id;
  v9 = this;
  if ( v5 )
  {
    do
    {
      v10 = v5->m_next;
      if ( v5->m_partId == v8 )
      {
        v11 = v5->m_vertices[1];
        v12 = (__m128 *)v5->m_vertices[0];
        location.m_region.m_type = 0;
        v13 = v11->m_position.m_quad;
        v14 = (__m128 *)v5->m_vertices[2];
        x.m_quad = _mm_add_ps(v13, v12[2]);
        v15 = _mm_mul_ps(_mm_add_ps(v14[2], x.m_quad), (__m128)xmmword_141A711C0);
        x.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v7->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v7->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v7->m_rotation.m_col2.m_quad)),
                     v7->m_translation.m_quad);
        if ( `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v16 = (hkgpMeshBase::Triangle *)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
          `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v16 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
        }
        location.m_region.m_feature.m_triangle = v16;
        location.m_normal = 0i64;
        location.m_pseudoNormal = 0i64;
        location.m_coordinates = 0i64;
        *(_QWORD *)&location.m_region.m_feature.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e
                                                          + 1);
        location.m_squaredDistance = (hkSimdFloat32)xmmword_141A712A0;
        location.m_inside.m_real = g_vectorfConstants[0];
        hkgpMesh::locate(v6, &x, &location, (hkBool)1);
        if ( location.m_inside.m_real.m128_f32[0] < 0.0 == removeInside )
          hkgpMesh::removeTriangle(v9, v5);
      }
      v5 = v10;
    }
    while ( v10 );
    v9->m_hasPerVertexNormals = 0;
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
  hkgpMeshBase::Triangle *v2; // rdi
  int v3; // esi
  hkgpMesh *v4; // rbp
  signed int v5; // ebx
  int v6; // ecx
  hkgpMeshBase::Triangle **v7; // rax
  __int64 v8; // rcx
  hkgpMeshBase::Vertex *v9; // rcx
  int v10; // er9
  __int64 v11; // r10
  __int64 v12; // rdx
  int v13; // er8
  char *array; // [rsp+20h] [rbp-38h]
  int v15; // [rsp+28h] [rbp-30h]
  int i; // [rsp+2Ch] [rbp-2Ch]
  __int64 v17; // [rsp+38h] [rbp-20h]

  v2 = this->m_triangles.m_used;
  v3 = id;
  v4 = this;
  array = 0i64;
  v15 = 0;
  for ( i = 2147483648; v2; v2 = v2->m_next )
  {
    if ( v2->m_partId == v3 )
    {
      v5 = 0;
      v2->m_plane.m_quad = _mm_xor_ps(
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                             v2->m_plane.m_quad);
      v6 = v15;
      do
      {
        LODWORD(v17) = v5;
        if ( v6 == (i & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v6 = v15;
        }
        v7 = (hkgpMeshBase::Triangle **)&array[16 * v6];
        if ( v7 )
        {
          v8 = v17;
          *v7 = v2;
          v7[1] = (hkgpMeshBase::Triangle *)v8;
          v6 = v15;
        }
        ++v6;
        ++v5;
        v15 = v6;
      }
      while ( v5 < 3 );
      v9 = v2->m_vertices[0];
      v2->m_vertices[0] = v2->m_vertices[1];
      v2->m_vertices[1] = v9;
    }
  }
  v10 = 0;
  if ( v15 > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = (__int64)&array[v11];
      if ( *(_QWORD *)(*(_QWORD *)&array[v11] + 8i64 * *(signed int *)&array[v11 + 8] + 40) & 0xFFFFFFFFFFFFFFFCui64 )
        *(_QWORD *)((*(_QWORD *)(*(_QWORD *)&array[v11] + 8i64 * *(signed int *)&array[v11 + 8] + 40) & 0xFFFFFFFFFFFFFFFCui64)
                  + 8 * (*(_QWORD *)(*(_QWORD *)&array[v11] + 8i64 * *(signed int *)&array[v11 + 8] + 40) & 3i64)
                  + 40) = 0i64;
      ++v10;
      *(_QWORD *)(*(_QWORD *)v12 + 8i64 * *(signed int *)(v12 + 8) + 40) = 0i64;
      v11 += 16i64;
    }
    while ( v10 < v15 );
  }
  hkgpMesh::bindEdgeList(v4, (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *)&array);
  v13 = i;
  v4->m_hasPerVertexNormals = 0;
  v15 = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v13);
}

// File Line: 2981
// RVA: 0xCD2A00
void __fastcall hkgpMesh::retriangulateFromPlanes(hkgpMesh *this)
{
  __int64 v1; // rsi
  hkgpMesh *v2; // r13
  int v3; // edx
  int v4; // er9
  __int64 v5; // rbx
  char *v6; // rdi
  int v7; // er8
  int v8; // eax
  __int64 v9; // rcx
  __int64 v10; // rdx
  int v11; // ebx
  int v12; // er9
  _DWORD *v13; // rdi
  __int64 v14; // rcx
  hkgpMeshBase::Triangle *v15; // rsi
  __int64 v16; // r14
  signed int v17; // ebx
  __int64 v18; // rdi
  hkgpMeshBase::Triangle **v19; // rcx
  hkgpMeshBase::Triangle *v20; // rax
  int v21; // esi
  __int64 v22; // rax
  hkResultEnum v23; // er15
  _QWORD *v24; // r12
  signed __int64 v25; // r14
  int v26; // edi
  int v27; // er9
  int v28; // edi
  __int64 v29; // rdx
  hkVector4f *v30; // r8
  __int64 v31; // r15
  int v32; // edi
  int v33; // eax
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128i v39; // xmm1
  int v40; // ebx
  int v41; // ecx
  __int64 v42; // rdx
  int v43; // ebx
  __int64 v44; // rsi
  __int64 v45; // r11
  int v46; // edi
  int v47; // er8
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128i v54; // xmm1
  int v55; // er10
  int v56; // er9
  __m128 v57; // xmm1
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128i v61; // xmm4
  int v62; // ecx
  int v63; // eax
  hkgpMesh *v64; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v65; // rbx
  __int64 v66; // rdx
  __int64 v67; // rsi
  __int64 v68; // r15
  __int64 v69; // r13
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Pool *v70; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item *v71; // rdx
  hkgpMeshBase::Triangle *v72; // rax
  __int64 v73; // rcx
  hkVector4f v74; // xmm0
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v75; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v76; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v77; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v78; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v79; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *i; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v81; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v82; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v83; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v84; // rdx
  int v85; // er8
  __int64 v86; // rbx
  char *v87; // rdi
  int v88; // er8
  char *array; // [rsp+40h] [rbp-A8h]
  int v90; // [rsp+48h] [rbp-A0h]
  int v91; // [rsp+4Ch] [rbp-9Ch]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v92; // [rsp+50h] [rbp-98h]
  int v93; // [rsp+58h] [rbp-90h]
  int v94; // [rsp+5Ch] [rbp-8Ch]
  _DWORD *v95; // [rsp+60h] [rbp-88h]
  __int64 v96; // [rsp+68h] [rbp-80h]
  __int64 v97; // [rsp+70h] [rbp-78h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion data; // [rsp+78h] [rbp-70h]
  hkVector4f dmax; // [rsp+98h] [rbp-50h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location location; // [rsp+A8h] [rbp-40h]
  hkVector4f dmin; // [rsp+C8h] [rbp-20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> v102; // [rsp+D8h] [rbp-10h]
  hkgpMesh *v103; // [rsp+E78h] [rbp+D90h]
  hkResult result; // [rsp+E80h] [rbp+D98h]
  int retaddr; // [rsp+E88h] [rbp+DA0h]
  hkgpMesh *v106; // [rsp+E90h] [rbp+DA8h]

  v106 = this;
  v1 = this->m_planes.m_size;
  v2 = this;
  retaddr = v1;
  if ( (_DWORD)v1 )
  {
    v91 = 2147483648;
    v3 = 0;
    array = 0i64;
    v95 = 0i64;
    v96 = 0x8000000000000000i64;
    v90 = 0;
    if ( (signed int)v1 > 0 )
    {
      v4 = v1;
      if ( (signed int)v1 < 0 )
        v4 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v4, 16);
      v3 = v90;
    }
    v5 = v3 - (signed int)v1 - 1;
    if ( v3 - (signed int)v1 - 1 >= 0 )
    {
      v6 = &array[16 * v1 + 12 + 16 * v5];
      do
      {
        v7 = *(_DWORD *)v6;
        *((_DWORD *)v6 - 1) = 0;
        if ( v7 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v6 - 12),
            16 * v7);
        *(_QWORD *)(v6 - 12) = 0i64;
        *(_DWORD *)v6 = 2147483648;
        v6 -= 16;
        --v5;
      }
      while ( v5 >= 0 );
      v3 = v90;
    }
    v8 = v1 - v3;
    v9 = (__int64)&array[16 * v3];
    v10 = (signed int)v1 - v3;
    if ( v8 > 0 )
    {
      do
      {
        if ( v9 )
        {
          *(_QWORD *)v9 = 0i64;
          *(_DWORD *)(v9 + 8) = 0;
          *(_DWORD *)(v9 + 12) = 2147483648;
        }
        v9 += 16i64;
        --v10;
      }
      while ( v10 );
    }
    v11 = v2->m_planes.m_size;
    v90 = v1;
    if ( (HIDWORD(v96) & 0x3FFFFFFF) < v11 )
    {
      v12 = v11;
      if ( v11 < 2 * (HIDWORD(v96) & 0x3FFFFFFF) )
        v12 = 2 * (HIDWORD(v96) & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v95, v12, 4);
    }
    v13 = &v95[(signed int)v96];
    v14 = v11 - (signed int)v96;
    if ( v11 - (signed int)v96 > 0 )
    {
      while ( v14 )
      {
        *v13 = -1;
        ++v13;
        --v14;
      }
    }
    v15 = v2->m_triangles.m_used;
    for ( LODWORD(v96) = v11; v15; v15 = v15->m_next )
    {
      v16 = v15->m_planeId;
      if ( (signed int)v16 >= 0 )
      {
        v17 = 0;
        v95[v16] = v15->m_material;
        do
        {
          data.m_edge.m_index = v17;
          if ( !(v15->m_links[v17] & 0xFFFFFFFFFFFFFFFCui64)
            || *(_DWORD *)((v15->m_links[v17] & 0xFFFFFFFFFFFFFFFCui64) + 84) != (_DWORD)v16 )
          {
            v18 = (__int64)&array[16 * v16];
            if ( *(_DWORD *)(v18 + 8) == (*(_DWORD *)(v18 + 12) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &array[16 * v16],
                16);
            v19 = (hkgpMeshBase::Triangle **)(*(_QWORD *)v18 + 16i64 * *(signed int *)(v18 + 8));
            if ( v19 )
            {
              v20 = *(hkgpMeshBase::Triangle **)&data.m_edge.m_index;
              *v19 = v15;
              v19[1] = v20;
            }
            ++*(_DWORD *)(v18 + 8);
          }
          ++v17;
        }
        while ( v17 < 3 );
      }
    }
    v21 = 0;
    v22 = 0i64;
    v23 = 0;
    result.m_enum = 0;
    v97 = 0i64;
    if ( v90 > 0 )
    {
      *(&data.m_edge.m_index + 1) = 16;
      dmin.m_quad = (__m128)_xmm;
      dmax.m_quad = _xmm;
      do
      {
        v24 = array;
        v92 = 0i64;
        v25 = 2 * v22;
        v93 = 0;
        v94 = 2147483648;
        v26 = *(_DWORD *)&array[16 * v22 + 8];
        if ( v26 <= 0 )
        {
          LODWORD(v106) = 0;
        }
        else
        {
          v27 = *(_DWORD *)&array[16 * v22 + 8];
          if ( v26 < 0 )
            v27 = 0;
          hkArrayUtil::_reserve(
            (hkResult *)&v106,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v92,
            v27,
            16);
        }
        v93 = v26;
        v28 = 0;
        if ( SLODWORD(v24[v25 + 1]) > 0 )
        {
          v29 = 0i64;
          do
          {
            ++v28;
            v29 += 16i64;
            *(_OWORD *)((char *)v92 + v29 - 16) = *(_OWORD *)(*(_QWORD *)(*(_QWORD *)(v29 + v24[v25] - 16)
                                                                        + 8i64 * *(signed int *)(v29 + v24[v25] - 8)
                                                                        + 16)
                                                            + 32i64);
          }
          while ( v28 < SLODWORD(v24[v25 + 1]) );
        }
        _mm_store_si128((__m128i *)&v102.m_mesh.m_vertices, (__m128i)0i64);
        _mm_store_si128((__m128i *)&v102.m_edgeDataPolicy, (__m128i)0i64);
        v102.m_stack.m_data = v102.m_stack.m_storage;
        *(_DWORD *)&v102.m_memSizeAndFlags = 0x1FFFF;
        v102.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable';
        *(_DWORD *)&v102.m_mesh.m_memSizeAndFlags = 0x1FFFF;
        v102.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable';
        v102.m_mesh.m_vertices.m_numUsed = 0;
        v102.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
        v102.m_mesh.m_triangles.m_used = 0i64;
        v102.m_mesh.m_triangles.m_numUsed = 0;
        v102.m_stack.m_size = 0;
        v102.m_stack.m_capacityAndFlags = -2147483584;
        v102.m_status.m_storage = 0;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomain(
          &v102,
          &dmin,
          &dmax,
          0.0,
          1);
        data.m_edge.m_triangle = v92;
        v30 = &v2->m_planes.m_data[v23];
        data.m_edge.m_index = v93;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setDomainFromPlanarPoints(
          &v102,
          (hkStridedVertices *)&data.m_edge,
          v30,
          1,
          1,
          0);
        if ( v93 > 0 )
        {
          v31 = 0i64;
          do
          {
            v32 = v102.m_margin;
            v33 = 0x7FFF - v102.m_margin;
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(*(__m128 *)((char *)&v92->0 + v31), *(__m128 *)((char *)&v92->0 + v31), 0),
                          v102.m_worldToLocal.m_col0.m_quad),
                        v102.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(*(__m128 *)((char *)&v92->0 + v31), *(__m128 *)((char *)&v92->0 + v31), 85),
                        v102.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*(__m128 *)((char *)&v92->0 + v31), *(__m128 *)((char *)&v92->0 + v31), 170),
                      v102.m_worldToLocal.m_col2.m_quad));
            v35 = _mm_sub_ps(v34, (__m128)xmmword_141A711B0);
            v36 = _mm_add_ps(v34, (__m128)xmmword_141A711B0);
            v37 = _mm_cmpltps(v34, (__m128)0i64);
            v38 = _mm_or_ps(_mm_andnot_ps(v37, v36), _mm_and_ps(v35, v37));
            v39 = _mm_xor_si128(
                    (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v38),
                    _mm_cvttps_epi32(v38));
            v40 = _mm_cvtsi128_si32(v39);
            if ( v40 >= v102.m_margin )
            {
              if ( v40 > v33 )
                v40 = 0x7FFF - v102.m_margin;
            }
            else
            {
              v40 = v102.m_margin;
            }
            v41 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v39, 85));
            if ( v41 >= v102.m_margin )
            {
              v32 = v41;
              if ( v41 > v33 )
                v32 = 0x7FFF - v102.m_margin;
            }
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
              &v102,
              &location,
              v40,
              v32);
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(
              &v102,
              &data,
              v40,
              v32,
              1,
              &location,
              0);
            if ( !data.m_type.m_storage )
            {
              v42 = *(_QWORD *)(v96 + 8i64 * (signed int)v97 + 16);
              *(_QWORD *)(v42 + 24) = *(_DWORD *)(v42 + 24) & 3 | (unsigned __int64)(4i64 * v21);
            }
            ++v21;
            v31 += 16i64;
          }
          while ( v21 < v93 );
          v23 = result.m_enum;
        }
        v43 = 0;
        if ( SLODWORD(v24[v25 + 1]) > 0 )
        {
          v44 = 0i64;
          do
          {
            v45 = v24[v25];
            v46 = v102.m_margin;
            v47 = 0x7FFF - v102.m_margin;
            v48 = *(__m128 *)(*(_QWORD *)(*(_QWORD *)(v45 + v44) + 8i64 * *(signed int *)(v45 + v44 + 8) + 16) + 32i64);
            v49 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v102.m_worldToLocal.m_col0.m_quad),
                        v102.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v102.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v102.m_worldToLocal.m_col2.m_quad));
            v50 = v49;
            v51 = _mm_sub_ps(v49, (__m128)xmmword_141A711B0);
            v52 = _mm_cmpltps(v49, (__m128)0i64);
            v53 = _mm_or_ps(_mm_andnot_ps(v52, _mm_add_ps(v50, (__m128)xmmword_141A711B0)), _mm_and_ps(v51, v52));
            v54 = _mm_xor_si128(
                    (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v53),
                    _mm_cvttps_epi32(v53));
            v55 = _mm_cvtsi128_si32(v54);
            if ( v55 >= v102.m_margin )
            {
              if ( v55 > v47 )
                v55 = 0x7FFF - v102.m_margin;
            }
            else
            {
              v55 = v102.m_margin;
            }
            v56 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v54, 85));
            if ( v56 >= v102.m_margin )
            {
              if ( v56 > v47 )
                v56 = 0x7FFF - v102.m_margin;
            }
            else
            {
              v56 = v102.m_margin;
            }
            v57 = *(__m128 *)(*(_QWORD *)(*(_QWORD *)(v45 + v44)
                                        + 8 * ((9i64 >> 2 * (unsigned __int8)*(_DWORD *)(v45 + v44 + 8)) & 3)
                                        + 16)
                            + 32i64);
            v58 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v102.m_worldToLocal.m_col0.m_quad),
                        v102.m_worldToLocal.m_col3.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v102.m_worldToLocal.m_col1.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v102.m_worldToLocal.m_col2.m_quad));
            v59 = _mm_cmpltps(v58, (__m128)0i64);
            v60 = _mm_or_ps(
                    _mm_andnot_ps(v59, _mm_add_ps(v58, (__m128)xmmword_141A711B0)),
                    _mm_and_ps(_mm_sub_ps(v58, (__m128)xmmword_141A711B0), v59));
            v61 = _mm_xor_si128(
                    (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v60),
                    _mm_cvttps_epi32(v60));
            v62 = _mm_cvtsi128_si32(v61);
            if ( v62 >= v102.m_margin )
            {
              if ( v62 > v47 )
                v62 = 0x7FFF - v102.m_margin;
            }
            else
            {
              v62 = v102.m_margin;
            }
            v63 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v61, 85));
            if ( v63 >= v102.m_margin )
            {
              v46 = v63;
              if ( v63 > v47 )
                v46 = 0x7FFF - v102.m_margin;
            }
            *(_QWORD *)&data.m_type.m_storage = &v97;
            v96 = -9223372028264841215i64;
            v97 = v45 + 16i64 * v43;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertEdge(
              &v102,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *)&location,
              v55,
              v56,
              v62,
              v46,
              1,
              (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)&data);
            LODWORD(v96) = 0;
            if ( v96 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)&data.m_type.m_storage,
                8 * HIDWORD(v96));
            ++v43;
            v44 += 16i64;
          }
          while ( v43 < SLODWORD(v24[v25 + 1]) );
        }
        if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(&v102) > 1 )
        {
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(&v102);
          v64 = v103;
          hkgpMesh::remapPlaneIndex(v103, v23, retaddr);
          v65 = v102.m_mesh.m_triangles.m_used;
          if ( v102.m_mesh.m_triangles.m_used )
          {
            do
            {
              if ( *((_BYTE *)v65 + 66) & 0x20 )
              {
                v66 = v24[v25];
                v67 = *(_QWORD *)(*(_QWORD *)(v66 + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[0] + 3) >> 2))
                                + 8i64
                                * *(signed int *)(v66
                                                + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[0] + 3) >> 2)
                                                + 8)
                                + 16);
                v68 = *(_QWORD *)(*(_QWORD *)(v66 + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[1] + 3) >> 2))
                                + 8i64
                                * *(signed int *)(v66
                                                + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[1] + 3) >> 2)
                                                + 8)
                                + 16);
                v69 = *(_QWORD *)(*(_QWORD *)(v66 + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[2] + 3) >> 2))
                                + 8i64
                                * *(signed int *)(v66
                                                + 16i64 * (signed int)(*((_QWORD *)v65->m_vertices[2] + 3) >> 2)
                                                + 8)
                                + 16);
                v70 = v64->m_triangles.m_allocator.m_firstPool;
                if ( !v70 || !v70->m_free )
                  v70 = hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&v64->m_triangles.m_allocator);
                if ( v70 )
                {
                  v71 = v70->m_free;
                  v70->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Triangle,32,hkContainerHeapAllocator>::Item **)v71->m_data;
                  v71->m_pool = v70;
                  ++v70->m_used;
                  *(_QWORD *)&v71->m_data[8] = 0i64;
                  *(_QWORD *)v71->m_data = v64->m_triangles.m_used;
                  v72 = v64->m_triangles.m_used;
                  if ( v72 )
                    v72->m_prev = (hkgpMeshBase::Triangle *)v71;
                  ++v64->m_triangles.m_numUsed;
                  v64->m_triangles.m_used = (hkgpMeshBase::Triangle *)v71;
                }
                else
                {
                  v71 = 0i64;
                }
                v64 = v103;
                v73 = v97;
                *(_DWORD *)&v71->m_data[80] = -1;
                *(_QWORD *)&v71->m_data[40] = 0i64;
                *(_QWORD *)&v71->m_data[48] = 0i64;
                *(_QWORD *)&v71->m_data[56] = 0i64;
                v74.m_quad = (__m128)v64->m_planes.m_data[(unsigned __int64)v25 / 2];
                *(hkResult *)&v71->m_data[84] = result;
                *(hkVector4f *)&v71->m_data[64] = (hkVector4f)v74.m_quad;
                *(_DWORD *)&v71->m_data[88] = v95[v73];
                *(_QWORD *)&v71->m_data[16] = v67;
                *(_QWORD *)&v71->m_data[24] = v68;
                *(_QWORD *)&v71->m_data[32] = v69;
              }
              v65 = v65->m_next;
            }
            while ( v65 );
            v23 = result.m_enum;
          }
          v2 = v103;
        }
        v102.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::`vftable';
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(
          &v102,
          1);
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(&v102.m_edgeDataPolicy);
        v21 = 0;
        v102.m_stack.m_size = 0;
        if ( v102.m_stack.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v102.m_stack.m_data,
            16 * v102.m_stack.m_capacityAndFlags);
        v75 = v102.m_mesh.m_triangles.m_allocator.m_firstPool;
        v102.m_stack.m_data = 0i64;
        v102.m_stack.m_capacityAndFlags = 2147483648;
        for ( v102.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkContainerHeapAllocator>::`vftable';
              v102.m_mesh.m_triangles.m_allocator.m_firstPool;
              v75 = v102.m_mesh.m_triangles.m_allocator.m_firstPool )
        {
          v76 = v75->m_links[0];
          if ( v76 )
            v76->m_links[1] = v75->m_links[1];
          else
            v102.m_mesh.m_triangles.m_allocator.m_firstPool = v75->m_links[1];
          v77 = v75->m_links[1];
          if ( v77 )
            v77->m_links[0] = v75->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v75,
            3104);
        }
        v102.m_mesh.m_triangles.m_used = 0i64;
        v102.m_mesh.m_triangles.m_numUsed = 0;
        if ( v75 )
        {
          do
          {
            v78 = v75->m_links[0];
            if ( v78 )
              v78->m_links[1] = v75->m_links[1];
            else
              v102.m_mesh.m_triangles.m_allocator.m_firstPool = v75->m_links[1];
            v79 = v75->m_links[1];
            if ( v79 )
              v79->m_links[0] = v75->m_links[0];
            hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v75,
              3104);
            v75 = v102.m_mesh.m_triangles.m_allocator.m_firstPool;
          }
          while ( v102.m_mesh.m_triangles.m_allocator.m_firstPool );
        }
        for ( i = v102.m_mesh.m_vertices.m_allocator.m_firstPool;
              v102.m_mesh.m_vertices.m_allocator.m_firstPool;
              i = v102.m_mesh.m_vertices.m_allocator.m_firstPool )
        {
          v81 = i->m_links[0];
          if ( v81 )
            v81->m_links[1] = i->m_links[1];
          else
            v102.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
          v82 = i->m_links[1];
          if ( v82 )
            v82->m_links[0] = i->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            i,
            1568);
        }
        v102.m_mesh.m_vertices.m_used = 0i64;
        v102.m_mesh.m_vertices.m_numUsed = 0;
        if ( i )
        {
          do
          {
            v83 = i->m_links[0];
            if ( v83 )
              v83->m_links[1] = i->m_links[1];
            else
              v102.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
            v84 = i->m_links[1];
            if ( v84 )
              v84->m_links[0] = i->m_links[0];
            hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              i,
              1568);
            i = v102.m_mesh.m_vertices.m_allocator.m_firstPool;
          }
          while ( v102.m_mesh.m_vertices.m_allocator.m_firstPool );
        }
        v93 = 0;
        v102.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
        v102.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
        if ( v94 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v92,
            16 * v94);
        ++v23;
        v92 = 0i64;
        v22 = v97 + 1;
        v94 = 2147483648;
        result.m_enum = v23;
        ++v97;
      }
      while ( v23 < v90 );
    }
    hkgpMesh::removePlaneTriangles(v2, retaddr);
    hkgpMesh::removeOrphanVertices(v2);
    hkgpMesh::rebuildTrianglesTree(v2, 0.0);
    v85 = HIDWORD(v96);
    v2->m_hasPerVertexNormals = 0;
    LODWORD(v96) = 0;
    if ( v85 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v95,
        4 * v85);
    v95 = 0i64;
    HIDWORD(v96) = 2147483648;
    v86 = v90 - 1;
    if ( v90 - 1 >= 0 )
    {
      v87 = &array[16 * (v90 - 1) + 12];
      do
      {
        v88 = *(_DWORD *)v87;
        *((_DWORD *)v87 - 1) = 0;
        if ( v88 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v87 - 12),
            16 * v88);
        *(_QWORD *)(v87 - 12) = 0i64;
        *(_DWORD *)v87 = 2147483648;
        v87 -= 16;
        --v86;
      }
      while ( v86 >= 0 );
    }
    v90 = 0;
    if ( v91 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v91);
  }
}

// File Line: 3075
// RVA: 0xCD36C0
void __fastcall hkgpMesh::enumerateTriangleOverlaps(hkgpMesh *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkArray<hkgpMeshBase::Triangle *,hkContainerHeapAllocator> *triangles)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  hkgpMesh *v7; // rbx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v8; // rbx
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector> *v10; // r9
  hkcdDynamicTree::CodecRawUlong *v11; // rcx
  unsigned __int64 v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  int v18; // esi
  __int64 v19; // rdi
  char *v20; // rdx
  char *v21; // r14
  char *v22; // [rsp+18h] [rbp-71h]
  int v23; // [rsp+20h] [rbp-69h]
  int v24; // [rsp+24h] [rbp-65h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+28h] [rbp-61h]
  int v26; // [rsp+50h] [rbp-39h]
  hkAabb v27; // [rsp+58h] [rbp-31h]
  hkVector4f vertexArray; // [rsp+78h] [rbp-11h]
  __int128 v29; // [rsp+88h] [rbp-1h]
  __int128 v30; // [rsp+98h] [rbp+Fh]
  hkAabb aabbOut; // [rsp+A8h] [rbp+1Fh]
  _DWORD *array; // [rsp+108h] [rbp+7Fh]

  v5 = b->m_quad;
  _mm_store_si128((__m128i *)&vertexArray, (__m128i)a->m_quad);
  v6 = c->m_quad;
  _mm_store_si128((__m128i *)&v29, (__m128i)v5);
  v7 = this;
  v24 = 2147483648;
  _mm_store_si128((__m128i *)&v30, (__m128i)v6);
  v23 = 0;
  hkAabbUtil::calcAabb(&vertexArray, 3, &aabbOut);
  v8 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v7->m_trianglesTree;
  v27 = aabbOut;
  tree.m_root = (unsigned __int64)&v22;
  v26 = 1;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_numLeaves = 64;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkcdDynamicTree::CodecRawUlong *)v9->m_cur;
  v12 = (unsigned __int64)&v11[8];
  if ( v9->m_slabSize < 512 || (void *)v12 > v9->m_end )
    v11 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v9, 512);
  else
    v9->m_cur = (void *)v12;
  tree.m_nodes.m_data = v11;
  tree.m_firstFree = (unsigned __int64)v11;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::SimpleCollector>>(
    v8,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)&tree.m_root,
    v10);
  v13 = tree.m_nodes.m_size;
  v14 = (char *)tree.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
    v13 = 0;
  tree.m_nodes.m_size = v13;
  v15 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      8 * tree.m_nodes.m_capacityAndFlags);
  v18 = 0;
  if ( v23 > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v22;
      _mm_store_si128((__m128i *)&tree.m_root, *(__m128i *)(*(_QWORD *)(*(_QWORD *)&v22[v19] + 16i64) + 32i64));
      _mm_store_si128((__m128i *)&v27, *(__m128i *)(*(_QWORD *)(*(_QWORD *)&v20[v19] + 24i64) + 32i64));
      _mm_store_si128((__m128i *)&v27.m_max, *(__m128i *)(*(_QWORD *)(*(_QWORD *)&v20[v19] + 32i64) + 32i64));
      if ( hkcdIntersectTriangleTriangle((hkVector4f (*)[3])&vertexArray, (hkVector4f (*)[3])&tree.m_root) )
      {
        v21 = v22;
        if ( array[2] == (array[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, 8);
        *(_QWORD *)(*(_QWORD *)array + 8i64 * (signed int)array[2]++) = *(_QWORD *)&v21[v19];
      }
      ++v18;
      v19 += 8i64;
    }
    while ( v18 < v23 );
  }
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22,
      8 * v24);
}

// File Line: 3092
// RVA: 0xCD3960
__int64 __fastcall hkgpMesh::checkTriangleOverlap(hkgpMesh *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  hkgpMesh *v6; // rbx
  __m128 v7; // xmm0
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v8; // rbx
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::TriangleOverlap> *v10; // r9
  hkcdDynamicTree::CodecRawUlong *v11; // rcx
  unsigned __int64 v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+20h] [rbp-59h]
  hkVector4f vertexArray; // [rsp+50h] [rbp-29h]
  __m128 v21; // [rsp+60h] [rbp-19h]
  __m128 v22; // [rsp+70h] [rbp-9h]
  char stackInstance[48]; // [rsp+80h] [rbp+7h]
  hkAabb aabbOut; // [rsp+B0h] [rbp+37h]

  v4 = a->m_quad;
  v5 = b->m_quad;
  v6 = this;
  LODWORD(tree.m_root) = 0;
  vertexArray.m_quad = v4;
  v7 = c->m_quad;
  v21 = v5;
  v22 = v7;
  hkAabbUtil::calcAabb(&vertexArray, 3, &aabbOut);
  v8 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v6->m_trianglesTree;
  *(__m256i *)&stackInstance[16] = (__m256i)aabbOut;
  *(_QWORD *)stackInstance = (char *)&tree + 32;
  *(_DWORD *)&stackInstance[8] = 1;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_numLeaves = 64;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkcdDynamicTree::CodecRawUlong *)v9->m_cur;
  v12 = (unsigned __int64)&v11[8];
  if ( v9->m_slabSize < 512 || (void *)v12 > v9->m_end )
    v11 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v9, 512);
  else
    v9->m_cur = (void *)v12;
  tree.m_nodes.m_data = v11;
  tree.m_firstFree = (unsigned __int64)v11;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkgpMeshInternals::TriangleOverlap>>(
    v8,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)stackInstance,
    v10);
  v13 = tree.m_nodes.m_size;
  v14 = (char *)tree.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
    v13 = 0;
  tree.m_nodes.m_size = v13;
  v15 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      8 * tree.m_nodes.m_capacityAndFlags);
  return LODWORD(tree.m_root);
}

// File Line: 3104
// RVA: 0xCD59C0
hkSimdFloat32 *__fastcall getLoopSurfaceArea(hkSimdFloat32 *result, hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *loop)
{
  int v2; // er9
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *v3; // rdi
  hkSimdFloat32 *v4; // r15
  int v5; // er9
  int v6; // edx
  int v7; // er14
  __int64 v8; // rbx
  hkgpMeshBase::Vertex *v9; // rsi
  hkgpMeshBase::Edge *v10; // r8
  int v11; // er9
  hkVector4f *v12; // rsi
  int v13; // er8
  __m128 v14; // xmm2
  hkVector4f *array; // [rsp+30h] [rbp-40h]
  int v17; // [rsp+38h] [rbp-38h]
  int v18; // [rsp+3Ch] [rbp-34h]
  hkAabb aabbOut; // [rsp+40h] [rbp-30h]
  hkResult resulta; // [rsp+98h] [rbp+28h]

  v2 = loop->m_size;
  v3 = loop;
  v4 = result;
  if ( v2 )
  {
    v5 = 2 * v2;
    v6 = 0;
    v18 = 2147483648;
    array = 0i64;
    v17 = 0;
    if ( v5 > 0 )
    {
      if ( v5 < 0 )
        v5 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v5, 16);
      v6 = v17;
    }
    v7 = 0;
    if ( v3->m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = v3->m_data[v8].m_triangle->m_vertices[v3->m_data[v8].m_index];
        if ( v6 == (v18 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v6 = v17;
        }
        array[v6] = v9->m_position;
        v10 = v3->m_data;
        v11 = v17 + 1;
        v17 = v11;
        v12 = (hkVector4f *)v10[v8].m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(v10[v8].m_index)) & 3];
        if ( v11 == (v18 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v11 = v17;
        }
        ++v7;
        ++v8;
        array[v11] = (hkVector4f)v12[2].m_quad;
        v6 = v17++ + 1;
      }
      while ( v7 < v3->m_size );
    }
    hkAabbUtil::calcAabb(array, v6, &aabbOut);
    v13 = v18;
    v14 = _mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
    v17 = 0;
    v4->m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                   _mm_shuffle_ps(v14, v14, 170));
    if ( v13 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v13);
      return v4;
    }
  }
  else
  {
    *(hkVector4f *)result = (hkVector4f)::aabbOut.m_quad;
  }
  return v4;
}

// File Line: 3127
// RVA: 0xCD3AF0
__int64 __fastcall hkgpMesh::extractAllLoops(hkgpMesh *this, hkArray<hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *,hkContainerHeapAllocator> *loops, int partId)
{
  hkgpMeshBase::Triangle *v3; // rsi
  int v4; // er14
  hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **v5; // r11
  int v6; // er9
  int v7; // edi
  _QWORD **v8; // rax
  __int64 v9; // rax
  _DWORD *v10; // rbx
  hkgpMeshBase::Triangle **v11; // rcx
  unsigned __int64 v12; // rax
  int v13; // ecx
  signed int v14; // er15
  int v15; // edi
  __int64 v16; // r10
  signed int v17; // eax
  int v18; // edi
  signed __int64 v19; // rbx
  hkArrayBase<hkgpMeshBase::Edge> *v20; // rsi
  hkgpMeshBase::Vertex *v21; // r13
  signed __int64 v22; // r8
  hkgpMeshBase::Vertex *v23; // r12
  hkArrayBase<hkgpMeshBase::Edge> *v24; // r14
  hkgpMeshBase::Edge *v25; // r8
  int v26; // eax
  hkgpMeshBase::Vertex *v27; // rcx
  __int64 v28; // rsi
  int v29; // er8
  _QWORD **v30; // rax
  int v31; // eax
  bool v32; // sf
  unsigned __int8 v33; // of
  int v34; // ebx
  int v35; // er9
  float v36; // xmm6_4
  signed __int64 v37; // rsi
  char *v38; // rcx
  char **v39; // r8
  unsigned int v40; // ebx
  __int64 v41; // rdx
  _QWORD *v42; // r8
  __int64 v43; // rsi
  int v44; // er8
  _QWORD **v45; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-58h]
  char **array; // [rsp+30h] [rbp-48h]
  int numtoinsert; // [rsp+38h] [rbp-40h]
  int v50; // [rsp+3Ch] [rbp-3Ch]
  signed int v51; // [rsp+90h] [rbp+18h]
  hkArrayBase<char *> *v52; // [rsp+98h] [rbp+20h]
  __int64 v53; // [rsp+A8h] [rbp+30h]

  v52 = (hkArrayBase<char *> *)loops;
  v3 = this->m_triangles.m_used;
  v4 = partId;
  v50 = 2147483648;
  v5 = 0i64;
  array = 0i64;
  v6 = 0;
  numtoinsert = 0;
  if ( !v3 )
    goto LABEL_62;
  do
  {
    if ( v4 == -1 || v3->m_partId == v4 )
    {
      v7 = 0;
      do
      {
        result.m_real.m128_i32[2] = v7;
        if ( !(v3->m_links[v7] & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 16i64);
          v10 = (_DWORD *)v9;
          if ( v9 )
          {
            *(_QWORD *)v9 = 0i64;
            *(_DWORD *)(v9 + 8) = 0;
            *(_DWORD *)(v9 + 12) = 2147483648;
          }
          else
          {
            v10 = 0i64;
          }
          if ( v10[2] == (v10[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v11 = (hkgpMeshBase::Triangle **)(*(_QWORD *)v10 + 16i64 * (signed int)v10[2]);
          if ( v11 )
          {
            v12 = result.m_real.m128_u64[1];
            *v11 = v3;
            v11[1] = (hkgpMeshBase::Triangle *)v12;
          }
          ++v10[2];
          v13 = numtoinsert;
          if ( numtoinsert == (v50 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v13 = numtoinsert;
          }
          array[v13] = (char *)v10;
          v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
          v6 = numtoinsert++ + 1;
        }
        ++v7;
      }
      while ( v7 < 3 );
    }
    v3 = v3->m_next;
  }
  while ( v3 );
  if ( !v6 )
  {
LABEL_62:
    v40 = 0;
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
    v53 = 0i64;
    v51 = 1;
    do
    {
      v18 = v17;
      if ( v17 >= v6 )
        goto LABEL_37;
      v19 = v16 + 8;
      do
      {
        v20 = *(hkArrayBase<hkgpMeshBase::Edge> **)((char *)v5 + v16);
        v21 = v20->m_data->m_triangle->m_vertices[v20->m_data->m_index];
        v22 = (signed __int64)&v20->m_data[v20->m_size - 1];
        v23 = *(hkgpMeshBase::Vertex **)(*(_QWORD *)v22 + 8 * ((9i64 >> 2 * *(_BYTE *)(v22 + 8)) & 3) + 16);
        if ( v21 == v23 )
          goto LABEL_35;
        v24 = *(hkArrayBase<hkgpMeshBase::Edge> **)((char *)v5 + v19);
        v25 = v24->m_data;
        v26 = v24->m_size - 1;
        result.m_real.m128_u64[0] = (unsigned __int64)v24->m_data->m_triangle->m_vertices[v24->m_data->m_index];
        v27 = v25[v26].m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v25[v26].m_index) & 3];
        if ( (hkgpMeshBase::Vertex *)result.m_real.m128_u64[0] == v27 )
          goto LABEL_34;
        if ( (hkgpMeshBase::Vertex *)result.m_real.m128_u64[0] == v23 )
        {
          hkArrayBase<hkgpMeshBase::Edge>::_append(
            v20,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v25,
            v24->m_size);
          v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
          v28 = *(__int64 *)((char *)array + v19);
          if ( v28 )
          {
            v29 = *(_DWORD *)(v28 + 12);
            *(_DWORD *)(v28 + 8) = 0;
            if ( v29 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)v28,
                16 * v29);
            *(_QWORD *)v28 = 0i64;
            *(_DWORD *)(v28 + 12) = 2147483648;
            v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v30[11] + 16i64))(v30[11], v28, 16i64);
            v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
          }
          v6 = numtoinsert - 1;
          numtoinsert = v6;
          if ( v6 != v18 )
          {
            *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v19) = v5[v6];
            v6 = numtoinsert;
            v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
          }
          --v18;
          v19 -= 8i64;
          v14 = -1;
LABEL_34:
          v16 = v53;
          goto LABEL_35;
        }
        if ( v21 != v27 )
          goto LABEL_34;
        hkArrayBase<hkgpMeshBase::Edge>::_append(
          v24,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v20->m_data,
          v20->m_size);
        v16 = v53;
        v41 = *(__int64 *)((char *)array + v53);
        v42 = (char **)((char *)array + v19);
        *(char **)((char *)array + v53) = *(char **)((char *)array + v19);
        *v42 = v41;
        v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
        v43 = *(__int64 *)((char *)array + v19);
        if ( v43 )
        {
          v44 = *(_DWORD *)(v43 + 12);
          *(_DWORD *)(v43 + 8) = 0;
          if ( v44 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)v43,
              16 * v44);
          *(_QWORD *)v43 = 0i64;
          *(_DWORD *)(v43 + 12) = 2147483648;
          v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v45[11] + 16i64))(v45[11], v43, 16i64);
          v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
          v16 = v53;
        }
        v6 = numtoinsert - 1;
        numtoinsert = v6;
        if ( v6 != v18 )
        {
          *(hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)((char *)v5 + v19) = v5[v6];
          v6 = numtoinsert;
          v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
        }
        --v18;
        v19 -= 8i64;
        v14 = -1;
LABEL_35:
        ++v18;
        v19 += 8i64;
      }
      while ( v18 < v6 );
      v17 = v51;
LABEL_37:
      v31 = v17 + 1;
      v16 += 8i64;
      v51 = v31--;
      v53 = v16;
      v33 = __OFSUB__(v31, v6);
      v32 = v31 - v6 < 0;
      v17 = v51;
    }
    while ( v32 ^ v33 );
    v15 = 1;
LABEL_39:
    ++v14;
  }
  while ( v14 < 1 );
  v34 = 0;
  getLoopSurfaceArea(&result, *v5);
  v35 = numtoinsert;
  if ( numtoinsert > 1 )
  {
    v36 = result.m_real.m128_f32[0];
    v37 = 1i64;
    do
    {
      getLoopSurfaceArea(&result, (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> *)array[v37]);
      if ( result.m_real.m128_f32[0] > v36 )
      {
        v34 = v15;
        v36 = result.m_real.m128_f32[0];
      }
      v35 = numtoinsert;
      ++v15;
      ++v37;
    }
    while ( v15 < numtoinsert );
    if ( v34 )
    {
      v38 = *array;
      v39 = &array[v34];
      *array = *v39;
      *v39 = v38;
      v35 = numtoinsert;
    }
  }
  hkArrayBase<unsigned __int64>::_append(v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, v35);
  v40 = numtoinsert;
  v5 = (hkArray<hkgpMeshBase::Edge,hkContainerHeapAllocator> **)array;
LABEL_57:
  numtoinsert = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v5,
      8 * v50);
  return v40;
}

// File Line: 3204
// RVA: 0xCD4640
void __fastcall hkgpMesh::simplifyPlanes(hkgpMesh *this, bool report)
{
  hkgpMesh *v2; // rsi
  signed int v3; // edi
  hkgpMeshBase::Triangle *v4; // r9
  hkgpMeshBase::Vertex *v5; // rax
  signed int v6; // edx
  float *v7; // rcx
  float v8; // xmm0_4
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v9; // r13
  hkgpMeshBase::Triangle *v10; // rbx
  signed int v11; // er14
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v12; // xmm7
  __int64 v13; // rdi
  __int128 v14; // xmm6
  int v15; // er9
  __int128 *v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // rax
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rdx
  __int128 v21; // xmm6
  __int128 *v22; // rax
  signed __int64 v23; // rdx
  unsigned __int64 v24; // rax
  bool v25; // r15
  int j; // esi
  int v27; // edi
  bool v28; // zf
  char *v29; // r15
  signed __int64 v30; // r8
  __int64 v31; // rdx
  __int64 v32; // rcx
  unsigned __int64 v33; // rdi
  hkgpMeshBase::Triangle *v34; // rsi
  int v35; // er10
  __m128 v36; // xmm4
  __int64 v37; // r8
  __int64 v38; // r9
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v45; // rax
  int v46; // edi
  int v47; // ebx
  hkOstream *v48; // rax
  hkOstream *v49; // rax
  hkOstream *v50; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v51; // [rsp+20h] [rbp-A0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v52; // [rsp+30h] [rbp-90h]
  __int128 v53; // [rsp+40h] [rbp-80h]
  hkErrStream v54; // [rsp+50h] [rbp-70h]
  int v55; // [rsp+68h] [rbp-58h]
  __int128 v56; // [rsp+70h] [rbp-50h]
  char *array; // [rsp+80h] [rbp-40h]
  int v58; // [rsp+88h] [rbp-38h]
  int v59; // [rsp+8Ch] [rbp-34h]
  char v60; // [rsp+90h] [rbp-30h]
  hkgpMesh *v61; // [rsp+2F0h] [rbp+230h]
  char v62; // [rsp+2F8h] [rbp+238h]
  int v63; // [rsp+300h] [rbp+240h]
  int i; // [rsp+308h] [rbp+248h]

  v2 = this;
  v3 = 0;
  i = this->m_triangles.m_numUsed;
  v63 = 0;
  do
  {
    v4 = v2->m_triangles.m_used;
    v55 = 0;
    v54.m_writer.m_pntr = (hkStreamWriter *)v4;
    _mm_store_si128((__m128i *)&v51, *(__m128i *)&v54.m_writer.m_pntr);
    if ( v4 )
    {
      v5 = v4->m_vertices[1];
      v6 = 0;
      v7 = v5->m_position.m_quad.m128_f32;
      do
      {
        v8 = *(float *)((char *)v7 + (char *)v4->m_vertices[0] - (char *)v5);
        if ( v8 < *v7 )
          break;
        if ( v8 > *v7 )
        {
          if ( v4->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v51);
          break;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < 3 );
    }
    v9 = &v51;
    v10 = (hkgpMeshBase::Triangle *)*(_OWORD *)&_mm_load_si128((const __m128i *)&v51);
    if ( !v10 )
      v9 = 0i64;
    if ( v9 )
    {
      v11 = v51.m_edge.m_index;
      while ( 1 )
      {
        v12 = v51;
        if ( v10->m_links[v11] & 0xFFFFFFFFFFFFFFFCui64 )
          break;
LABEL_61:
        if ( v10 )
        {
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v51);
          v11 = v51.m_edge.m_index;
          v10 = v51.m_edge.m_triangle;
        }
        v9 = &v51;
        if ( !v10 )
          v9 = 0i64;
        if ( !v9 )
          goto LABEL_66;
      }
      v13 = 0i64;
      *(_QWORD *)&v56 = v10;
      DWORD2(v56) = v11;
      v14 = v56;
      v59 = -2147483632;
      v53 = v56;
      v15 = 0;
      v58 = 0;
      array = &v60;
      while ( 1 )
      {
        if ( v15 == (v59 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v15 = v58;
        }
        v16 = (__int128 *)&array[16 * v15];
        if ( v16 )
        {
          *v16 = v14;
          v15 = v58;
        }
        v58 = ++v15;
        v17 = (18 >> 2 * BYTE8(v53)) & 3;
        v18 = *(_QWORD *)(v53 + 8 * v17 + 40) & 3i64;
        v19 = *(_QWORD *)(v53 + 8 * v17 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        v54.vfptr = (hkBaseObjectVtbl *)(*(_QWORD *)(v53 + 8 * v17 + 40) & 0xFFFFFFFFFFFFFFFCui64);
        *(_DWORD *)&v54.m_memSizeAndFlags = v18;
        v14 = *(_OWORD *)&v54.vfptr;
        v53 = *(_OWORD *)&v54.vfptr;
        if ( !v19 )
          break;
        if ( (hkgpMeshBase::Triangle *)(v19 + (unsigned int)v18) == (hkgpMeshBase::Triangle *)((char *)v10
                                                                                             + (unsigned int)v11) )
          goto LABEL_29;
      }
      v20 = v10->m_links[v11];
      *(_QWORD *)&v56 = v20 & 0xFFFFFFFFFFFFFFFCui64;
      DWORD2(v56) = (9 >> 2 * (v20 & 3)) & 3;
      v21 = v56;
      v53 = v56;
      if ( v20 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        do
        {
          if ( v15 == (v59 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v15 = v58;
          }
          v22 = (__int128 *)&array[16 * v15];
          if ( v22 )
          {
            *v22 = v21;
            v15 = v58;
          }
          v58 = ++v15;
          v23 = *(_QWORD *)(v53 + 8i64 * SDWORD2(v53) + 40) & 3i64;
          *(_QWORD *)&v53 = *(_QWORD *)(v53 + 8i64 * SDWORD2(v53) + 40) & 0xFFFFFFFFFFFFFFFCui64;
          DWORD2(v53) = (9 >> 2 * v23) & 3;
          v21 = v53;
        }
        while ( (_QWORD)v53 );
      }
LABEL_29:
      v24 = v10->m_links[v11] & 0xFFFFFFFFFFFFFFFCui64;
      v52.m_elem = 0i64;
      LODWORD(v24) = *(_DWORD *)(v24 + 84);
      v52.m_numElems = 0;
      v52.m_hashMod = -1;
      v25 = v10->m_planeId != (_DWORD)v24;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        &v52,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        16);
      for ( j = 0; j < v58; v13 += 16i64 )
      {
        if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                              &v52,
                              *(signed int *)(*(_QWORD *)&array[v13] + 84i64),
                              0i64) )
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v52,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            *(signed int *)(*(_QWORD *)&array[v13] + 84i64),
            1ui64);
        ++j;
      }
      v27 = v52.m_numElems & 0x7FFFFFFF;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v52,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v52);
      if ( v25 )
        v28 = v27 == 2;
      else
        v28 = v27 == 1;
      v29 = array;
      v30 = 0i64;
      if ( v58 <= 0 )
      {
LABEL_41:
        if ( v28 )
        {
          v33 = v10->m_links[v11] & 0xFFFFFFFFFFFFFFFCui64;
          v34 = v10;
          v35 = 0;
          v36 = v10->m_vertices[(9i64 >> 2 * (unsigned __int8)v11) & 3]->m_position.m_quad;
          if ( v58 <= 0 )
          {
LABEL_48:
            if ( v9 )
            {
              do
              {
                if ( v10 != v34 && v10 != (hkgpMeshBase::Triangle *)v33 )
                  break;
                if ( v10 )
                {
                  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v51);
                  v10 = v51.m_edge.m_triangle;
                }
                v45 = &v51;
                if ( !v10 )
                  v45 = 0i64;
              }
              while ( v45 );
              v11 = v51.m_edge.m_index;
            }
            v2 = v61;
            _mm_store_si128((__m128i *)&v54, (__m128i)v12);
            hkgpMesh::collapseEdge(v2, (hkgpMeshBase::Edge *)&v54, 0);
            v29 = array;
            v3 = -1;
            v63 = -1;
            goto LABEL_59;
          }
          v37 = (__int64)array;
          while ( 1 )
          {
            v38 = *(_QWORD *)v37;
            if ( *(hkgpMeshBase::Triangle **)v37 != v10 && v38 != v33 )
            {
              v39 = _mm_sub_ps(
                      *(__m128 *)(*(_QWORD *)(v38 + 8i64 * ((9 >> 2 * *(unsigned int *)(v37 + 8)) & 3) + 16) + 32i64),
                      v36);
              v40 = _mm_sub_ps(
                      *(__m128 *)(*(_QWORD *)(v38
                                            + 8 * ((9i64 >> 2 * ((9 >> 2 * *(unsigned int *)(v37 + 8)) & 3u)) & 3)
                                            + 16)
                                + 32i64),
                      v36);
              v41 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39),
                      _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
              v42 = _mm_shuffle_ps(v41, v41, 201);
              v43 = _mm_mul_ps(v42, v36);
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
                      v61->m_planes.m_data[*(signed int *)(v38 + 84)].m_quad);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170))) <= 0.00000011920929 )
                break;
            }
            ++v35;
            v37 += 16i64;
            if ( v35 >= v58 )
              goto LABEL_48;
          }
        }
      }
      else
      {
        v31 = (__int64)array;
        while ( 1 )
        {
          v32 = *(signed int *)(v31 + 8);
          if ( !(*(_QWORD *)(*(_QWORD *)v31 + 8 * v32 + 40) & 0xFFFFFFFFFFFFFFFCui64)
            || !(*(_QWORD *)(*(_QWORD *)v31 + 8i64 * ((9 >> 2 * v32) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) )
          {
            break;
          }
          ++v30;
          v31 += 16i64;
          if ( v30 >= v58 )
            goto LABEL_41;
        }
      }
      v2 = v61;
      v3 = v63;
LABEL_59:
      v58 = 0;
      if ( v59 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v29,
          16 * v59);
      goto LABEL_61;
    }
LABEL_66:
    v63 = ++v3;
  }
  while ( v3 < 1 );
  if ( v62 )
  {
    v46 = i;
    if ( i != v2->m_triangles.m_numUsed )
    {
      hkErrStream::hkErrStream(&v54, &array, 512);
      v47 = v2->m_triangles.m_numUsed;
      v48 = hkOstream::operator<<((hkOstream *)&v54.vfptr, "Planes simplify: ");
      v49 = hkOstream::operator<<(v48, v46, (int)v48);
      v50 = hkOstream::operator<<(v49, " => ");
      hkOstream::operator<<(v50, v47, (int)v50);
      hkError::messageReport(-1, (const char *)&array, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 3249);
      hkOstream::~hkOstream((hkOstream *)&v54.vfptr);
    }
  }
}rocessing\\Mesh\\hkgpMesh.cpp", 3249);
      hkOstream::~hkOstream((hkOstream *)&v54.vfptr);
    }
  }
}

// File Line: 3255
// RVA: 0xCD3FF0
__int64 __fastcall hkgpMesh::countFanPlanes(hkgpMesh *this, hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *v2; // rbx
  __int64 v3; // rdi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v4; // xmm6
  int v5; // er8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v6; // rax
  __int64 v7; // rcx
  unsigned __int64 v8; // rax
  bool v9; // zf
  unsigned __int64 v10; // rdx
  char v11; // cl
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v12; // xmm6
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v13; // rax
  char v14; // cl
  int v15; // edi
  __int64 v16; // rbx
  unsigned int v17; // ebx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > i; // [rsp+20h] [rbp-D8h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v20; // [rsp+30h] [rbp-C8h]
  char *array; // [rsp+40h] [rbp-B8h]
  int v22; // [rsp+48h] [rbp-B0h]
  int v23; // [rsp+4Ch] [rbp-ACh]
  char v24; // [rsp+50h] [rbp-A8h]

  v2 = edge->m_triangle;
  v3 = (signed int)edge->m_index;
  i.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)edge->m_triangle;
  i.m_numElems = v3;
  v4 = i;
  v5 = 0;
  v23 = -2147483632;
  array = &v24;
  v22 = 0;
  while ( 1 )
  {
    if ( v5 == (v23 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v5 = v22;
    }
    v6 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&array[16 * v5];
    if ( v6 )
    {
      *v6 = v4;
      v5 = v22;
    }
    v22 = ++v5;
    v7 = (18 >> 2 * LOBYTE(i.m_numElems)) & 3;
    v8 = *(&i.m_elem[2].val + v7) & 3;
    v10 = *(&i.m_elem[2].val + v7) & 0xFFFFFFFFFFFFFFFCui64;
    v9 = v10 == 0;
    v20.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)(*(&i.m_elem[2].val + v7) & 0xFFFFFFFFFFFFFFFCui64);
    v20.m_numElems = v8;
    v4 = v20;
    i = v20;
    if ( v9 )
      break;
    if ( (hkgpMeshBase::Triangle *)(v10 + (unsigned int)v8) == (hkgpMeshBase::Triangle *)((char *)v2 + (unsigned int)v3) )
      goto LABEL_15;
  }
  v11 = v2->m_links[v3] & 3;
  v20.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)(v2->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64);
  v20.m_numElems = (9 >> 2 * v11) & 3;
  v12 = v20;
  for ( i = v20; v20.m_elem; i = v20 )
  {
    if ( v5 == (v23 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v5 = v22;
    }
    v13 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&array[16 * v5];
    if ( v13 )
    {
      *v13 = v12;
      v5 = v22;
    }
    v22 = ++v5;
    v14 = *(&i.m_elem[2].val + i.m_numElems) & 3;
    v20.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)(*(&i.m_elem[2].val + i.m_numElems) & 0xFFFFFFFFFFFFFFFCui64);
    v20.m_numElems = (9 >> 2 * v14) & 3;
    v12 = v20;
  }
LABEL_15:
  i.m_elem = 0i64;
  i.m_numElems = 0;
  i.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &i,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    16);
  v15 = 0;
  if ( v22 > 0 )
  {
    v16 = 0i64;
    do
    {
      if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            &i,
                            *(signed int *)(*(_QWORD *)&array[v16] + 84i64),
                            0i64) )
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &i,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          *(signed int *)(*(_QWORD *)&array[v16] + 84i64),
          1ui64);
      ++v15;
      v16 += 16i64;
    }
    while ( v15 < v22 );
  }
  v17 = i.m_numElems & 0x7FFFFFFF;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &i,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&i);
  v22 = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v23);
  return v17;
}

// File Line: 3263
// RVA: 0xCD42B0
hkBool *__fastcall hkgpMesh::checkEdgeCollapseConvex(hkgpMesh *this, hkBool *result, hkgpMesh::FanEdgeCollector *fan, hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rsi
  __int64 v7; // r10
  unsigned __int64 v8; // rbx
  hkBool *v9; // r14
  hkgpMeshBase::Vertex *v10; // rbp
  hkgpMeshBase::Edge *v11; // rax
  hkgpMeshBase::Triangle *v12; // r11
  __int64 v13; // rdx
  __m128 *v14; // r9
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 *v18; // rcx
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm2

  v4 = edge->m_triangle;
  v5 = (signed int)edge->m_index;
  v6 = fan->m_edges.m_size;
  v7 = 0i64;
  v8 = edge->m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  v9 = result;
  v10 = edge->m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v5) & 3];
  if ( v6 <= 0 )
  {
LABEL_7:
    v9->m_bool = 1;
  }
  else
  {
    v11 = fan->m_edges.m_data;
    while ( 1 )
    {
      v12 = v11->m_triangle;
      v13 = *(_QWORD *)&v11->m_index;
      if ( v11->m_triangle != v4 && v12 != (hkgpMeshBase::Triangle *)v8 )
      {
        v14 = (__m128 *)v12->m_vertices[(signed int)v13];
        v15 = v12->m_vertices[(9i64 >> 2 * (unsigned __int8)v13) & 3]->m_position.m_quad;
        v16 = v15;
        v17 = _mm_sub_ps(v15, v10->m_position.m_quad);
        v18 = (__m128 *)v12->m_vertices[(18i64 >> 2 * (unsigned __int8)v13) & 3];
        v19 = _mm_sub_ps(v16, v14[2]);
        v20 = _mm_sub_ps(v18[2], v14[2]);
        v21 = _mm_sub_ps(v18[2], v10->m_position.m_quad);
        v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v19), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20));
        v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v21));
        v24 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), _mm_shuffle_ps(v22, v22, 201));
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) < 0.0 )
          break;
      }
      ++v7;
      ++v11;
      if ( v7 >= v6 )
        goto LABEL_7;
    }
    v9->m_bool = 0;
  }
  return v9;
}

// File Line: 3285
// RVA: 0xCD4400
hkBool *__fastcall hkgpMesh::checkEdgeCollapseConvex(hkgpMesh *this, hkBool *result, hkgpMeshBase::Edge *edge)
{
  hkgpMeshBase::Triangle *v3; // rbx
  __int64 v4; // rdi
  __int128 v5; // xmm6
  int v6; // er9
  hkgpMeshBase::Edge *v7; // r14
  hkBool *v8; // rsi
  hkgpMesh *v9; // r15
  __int128 *v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rax
  bool v13; // zf
  unsigned __int64 v14; // rdx
  char v15; // cl
  __int128 v16; // xmm6
  __int128 *v17; // rax
  char v18; // cl
  __int128 v20; // [rsp+20h] [rbp-C8h]
  __int128 i; // [rsp+30h] [rbp-B8h]
  char *array; // [rsp+40h] [rbp-A8h]
  int v23; // [rsp+48h] [rbp-A0h]
  int v24; // [rsp+4Ch] [rbp-9Ch]
  char v25; // [rsp+50h] [rbp-98h]

  v3 = edge->m_triangle;
  v4 = (signed int)edge->m_index;
  *(_QWORD *)&i = edge->m_triangle;
  DWORD2(i) = v4;
  v5 = i;
  v6 = 0;
  v7 = edge;
  v8 = result;
  v9 = this;
  array = &v25;
  v24 = -2147483632;
  v23 = 0;
  while ( 1 )
  {
    if ( v6 == (v24 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v6 = v23;
    }
    v10 = (__int128 *)&array[16 * v6];
    if ( v10 )
    {
      *v10 = v5;
      v6 = v23;
    }
    v23 = ++v6;
    v11 = (18 >> 2 * BYTE8(i)) & 3;
    v12 = *(_QWORD *)(i + 8 * v11 + 40) & 3i64;
    v14 = *(_QWORD *)(i + 8 * v11 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v13 = v14 == 0;
    *(_QWORD *)&v20 = *(_QWORD *)(i + 8 * v11 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    DWORD2(v20) = v12;
    v5 = v20;
    i = v20;
    if ( v13 )
      break;
    if ( (hkgpMeshBase::Triangle *)(v14 + (unsigned int)v12) == (hkgpMeshBase::Triangle *)((char *)v3 + (unsigned int)v4) )
      goto LABEL_15;
  }
  v15 = v3->m_links[v4] & 3;
  *(_QWORD *)&v20 = v3->m_links[v4] & 0xFFFFFFFFFFFFFFFCui64;
  DWORD2(v20) = (9 >> 2 * v15) & 3;
  v16 = v20;
  for ( i = v20; (_QWORD)v20; i = v20 )
  {
    if ( v6 == (v24 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v6 = v23;
    }
    v17 = (__int128 *)&array[16 * v6];
    if ( v17 )
    {
      *v17 = v16;
      v6 = v23;
    }
    v23 = ++v6;
    v18 = *(_QWORD *)(i + 8i64 * SDWORD2(i) + 40) & 3;
    *(_QWORD *)&v20 = *(_QWORD *)(i + 8i64 * SDWORD2(i) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    DWORD2(v20) = (9 >> 2 * v18) & 3;
    v16 = v20;
  }
LABEL_15:
  v20 = (__int128)*v7;
  hkgpMesh::checkEdgeCollapseConvex(v9, v8, (hkgpMesh::FanEdgeCollector *)&array, (hkgpMeshBase::Edge *)&v20);
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v24);
  return v8;
}

// File Line: 3292
// RVA: 0xCD4C90
void __fastcall hkgpMesh::initializeQEM(hkgpMesh *this)
{
  hkgpMeshBase::Triangle *v1; // r8
  hkgpMesh *v2; // rdi
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v3; // xmm6
  hkgpMeshBase::Vertex *v4; // rax
  signed int v5; // edx
  float *v6; // rcx
  float v7; // xmm0_4
  hkgpMeshBase::Triangle *v8; // rbx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v9; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v10; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v11; // [rsp+20h] [rbp-38h]
  __int128 v12; // [rsp+30h] [rbp-28h]

  v1 = this->m_triangles.m_used;
  v11.m_edge.m_triangle = v1;
  v11.m_edge.m_index = 0;
  v2 = this;
  v3 = v11;
  if ( v1 )
  {
    v4 = v1->m_vertices[1];
    v5 = 0;
    v6 = v4->m_position.m_quad.m128_f32;
    do
    {
      v7 = *(float *)((char *)v6 + (char *)v1->m_vertices[0] - (char *)v4);
      if ( v7 < *v6 )
        break;
      if ( v7 > *v6 )
      {
        if ( v1->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
        {
          hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v11);
          v3 = v11;
        }
        break;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < 3 );
  }
  v8 = v3.m_edge.m_triangle;
  v9 = &v11;
  if ( !v3.m_edge.m_triangle )
    v9 = 0i64;
  if ( v9 )
  {
    do
    {
      _mm_store_si128((__m128i *)&v12, (__m128i)v3);
      hkgpMesh::computeQEM(v2, (hkgpMeshBase::Edge *)&v12);
      if ( v8 )
      {
        hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v11);
        v8 = v11.m_edge.m_triangle;
        v3 = v11;
      }
      v10 = &v11;
      if ( !v8 )
        v10 = 0i64;
    }
    while ( v10 );
  }
}

// File Line: 3301
// RVA: 0xCD4D90
void __fastcall hkgpMesh::computeQEM(hkgpMesh *this, hkgpMeshBase::Edge *e)
{
  hkgpMeshBase::Triangle *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8
  hkgpMeshBase::Edge *v5; // rsi
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  __m128 *v9; // rax
  __int64 v10; // rcx
  signed __int64 v11; // rax
  bool v12; // zf
  unsigned __int64 v13; // rdx
  char v14; // cl
  __m128 v15; // xmm6
  __m128 *v16; // rax
  char v17; // cl
  int v18; // ebx
  __int64 v19; // rdi
  _QWORD *v20; // r9
  __int64 v21; // rcx
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __int64 v24; // rax
  __m128 v25; // xmm1
  __int64 v26; // rdx
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  char v32; // cl
  __m128 v33; // xmm3
  __m128 *v34; // rax
  hkgpMeshBase::Vertex *v35; // rdx
  float v36; // xmm1_4
  hkVector4f v37; // xmm0
  hkSimdFloat32 result; // [rsp+20h] [rbp-D8h]
  __m128 i; // [rsp+30h] [rbp-C8h]
  hkMatrix3f v40; // [rsp+40h] [rbp-B8h]
  int *array; // [rsp+70h] [rbp-88h]
  int v42; // [rsp+78h] [rbp-80h]
  int v43; // [rsp+7Ch] [rbp-7Ch]

  v2 = e->m_triangle;
  v3 = (signed int)e->m_index;
  i.m128_u64[0] = (unsigned __int64)e->m_triangle;
  i.m128_i32[2] = v3;
  v4 = 0;
  v5 = e;
  v6 = i;
  v42 = 0;
  v43 = -2147483632;
  array = &v42;
  v7 = 0i64;
  v8 = 0i64;
  while ( 1 )
  {
    if ( v4 == (v43 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v4 = v42;
    }
    v9 = (__m128 *)&array[4 * v4];
    if ( v9 )
    {
      *v9 = v6;
      v4 = v42;
    }
    v42 = ++v4;
    v10 = (18 >> 2 * i.m128_i8[8]) & 3;
    v11 = *(_QWORD *)(i.m128_u64[0] + 8 * v10 + 40) & 3i64;
    v13 = *(_QWORD *)(i.m128_u64[0] + 8 * v10 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v12 = v13 == 0;
    result.m_real.m128_u64[0] = *(_QWORD *)(i.m128_u64[0] + 8 * v10 + 40) & 0xFFFFFFFFFFFFFFFCui64;
    result.m_real.m128_i32[2] = v11;
    v6 = result.m_real;
    i = result.m_real;
    if ( v12 )
      break;
    if ( (hkgpMeshBase::Triangle *)(v13 + (unsigned int)v11) == (hkgpMeshBase::Triangle *)((char *)v2 + (unsigned int)v3) )
      goto LABEL_15;
  }
  v14 = v2->m_links[v3] & 3;
  result.m_real.m128_u64[0] = v2->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64;
  result.m_real.m128_i32[2] = (9 >> 2 * v14) & 3;
  v15 = result.m_real;
  for ( i = result.m_real; result.m_real.m128_u64[0]; i = result.m_real )
  {
    if ( v4 == (v43 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v4 = v42;
    }
    v16 = (__m128 *)&array[4 * v4];
    if ( v16 )
    {
      *v16 = v15;
      v4 = v42;
    }
    v42 = ++v4;
    v17 = *(_QWORD *)(i.m128_u64[0] + 8i64 * i.m128_i32[2] + 40) & 3;
    result.m_real.m128_u64[0] = *(_QWORD *)(i.m128_u64[0] + 8i64 * i.m128_i32[2] + 40) & 0xFFFFFFFFFFFFFFFCui64;
    result.m_real.m128_i32[2] = (9 >> 2 * v17) & 3;
    v15 = result.m_real;
  }
LABEL_15:
  v18 = 0;
  if ( v4 > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = *(_QWORD **)&array[v19];
      v21 = *(_QWORD *)&array[v19 + 2];
      v22 = *(__m128 *)(v20[2] + 32i64);
      v23 = _mm_sub_ps(*(__m128 *)(v20[3] + 32i64), v22);
      v24 = (signed int)v21;
      v25 = _mm_sub_ps(*(__m128 *)(v20[4] + 32i64), v22);
      v26 = v20[(signed int)v21 + 5];
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v25));
      v28 = _mm_shuffle_ps(v27, v27, 201);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v8 = _mm_add_ps(
             v8,
             _mm_andnot_ps(
               _mm_cmpleps(v30, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                   _mm_mul_ps(v31, *(__m128 *)_xmm)),
                 v30)));
      if ( v26 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v32 = 2 * v21;
        v33 = *(__m128 *)(v20[v24 + 2] + 32i64);
        v34 = (__m128 *)v20[((18i64 >> v32) & 3) + 2];
        v40.m_col0.m_quad = _mm_sub_ps(*(__m128 *)(v20[((9i64 >> v32) & 3) + 2] + 32i64), v33);
        v40.m_col1.m_quad = _mm_sub_ps(v34[2], v33);
        v40.m_col2.m_quad = _mm_sub_ps(
                              *(__m128 *)(*(_QWORD *)((v26 & 0xFFFFFFFFFFFFFFFCui64)
                                                    + 8 * ((18i64 >> 2 * ((unsigned __int8)v26 & 3u)) & 3)
                                                    + 16)
                                        + 32i64),
                              v33);
        hkMatrix3f::getDeterminant(&v40, &result);
        v4 = v42;
        v7 = _mm_add_ps(v7, _mm_mul_ps(result.m_real, result.m_real));
      }
      ++v18;
      v19 += 4i64;
    }
    while ( v18 < v4 );
  }
  v35 = v5->m_triangle->m_vertices[v5->m_index];
  LODWORD(v36) = (unsigned __int128)_mm_rcp_ps(v8);
  v37.m_quad = (__m128)v35->m_data;
  v37.m_quad.m128_f32[0] = (float)((float)(2.0 - (float)(v36 * v8.m128_f32[0])) * v36) * v7.m128_f32[0];
  v35->m_data = (hkVector4f)v37.m_quad;
  v42 = 0;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v43);
}

// File Line: 3321
// RVA: 0xCD5180
void __usercall hkgpMesh::simplifyQEM(hkgpMesh *this@<rcx>, int numTriangleToRemove@<edx>, float maxCost@<xmm2>, __m128 a4@<xmm0>)
{
  int v4; // edi
  int v5; // esi
  hkgpMesh *v6; // r15
  int v7; // er12
  float v8; // xmm8_4
  int v9; // er14
  float v10; // xmm6_4
  __m128i v11; // xmm7
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkgpMeshBase::Triangle *v14; // r9
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v15; // xmm2
  hkgpMeshBase::Vertex *v16; // rax
  signed int v17; // edx
  float *v18; // rcx
  hkgpMeshBase::Triangle *v19; // rdx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v20; // rax
  signed int v21; // er8
  __m128 *v22; // rcx
  __m128 *v23; // rax
  float v24; // xmm1_4
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v25; // rax
  int v26; // edx
  signed __int64 v27; // r8
  __int64 v28; // rax
  __int128 v29; // xmm0
  __m128 *v30; // rax
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v31; // [rsp+20h] [rbp-B8h]
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v32; // [rsp+30h] [rbp-A8h]
  __int128 v33; // [rsp+40h] [rbp-98h]
  hkErrStream v34; // [rsp+50h] [rbp-88h]
  char buf; // [rsp+70h] [rbp-68h]
  float v36; // [rsp+2B8h] [rbp+1E0h]

  if ( numTriangleToRemove > 0 )
  {
    v4 = -1;
    v5 = numTriangleToRemove;
    v6 = this;
    v7 = 0;
    v8 = v36;
    v9 = 0;
    do
    {
      v10 = *(float *)&xmmword_141A712A0;
      if ( !(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' & 1) )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::`local static guard' |= 1u;
      }
      v11 = (__m128i)`hkgpTopology::Edge<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkgpMeshBase::Vertex *>::null'::`2'::e;
      if ( v9 / v5 != v4 )
      {
        v4 = v9 / v5;
        hkErrStream::hkErrStream(&v34, &buf, 512);
        v12 = hkOstream::operator<<((hkOstream *)&v34.vfptr, "Progress: ");
        v13 = hkOstream::operator<<(v12, v9 / v5, (int)v12);
        hkOstream::operator<<(v13, " %");
        hkError::messageReport(-1, &buf, "GeometryProcessing\\Mesh\\hkgpMesh.cpp", 3332);
        hkOstream::~hkOstream((hkOstream *)&v34.vfptr);
      }
      v14 = v6->m_triangles.m_used;
      v32.m_edge.m_index = 0;
      v32.m_edge.m_triangle = v14;
      v15 = v32;
      v31 = v32;
      if ( v14 )
      {
        v16 = v14->m_vertices[1];
        v17 = 0;
        v18 = v16->m_position.m_quad.m128_f32;
        do
        {
          a4 = (__m128)*(unsigned int *)((char *)v18 + (char *)v14->m_vertices[0] - (char *)v16);
          if ( a4.m128_f32[0] < *v18 )
            break;
          if ( a4.m128_f32[0] > *v18 )
          {
            if ( v14->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
            {
              hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v31);
              v15 = v31;
            }
            break;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < 3 );
      }
      v19 = v15.m_edge.m_triangle;
      v20 = &v31;
      if ( !v15.m_edge.m_triangle )
        v20 = 0i64;
      if ( v20 )
      {
        v21 = v31.m_edge.m_index;
        do
        {
          if ( v19->m_links[v21] & 0xFFFFFFFFFFFFFFFCui64 )
          {
            v22 = (__m128 *)v19->m_vertices[(9i64 >> 2 * (unsigned __int8)v21) & 3];
            v23 = (__m128 *)v19->m_vertices[v21];
            a4 = _mm_shuffle_ps(v23[4], v23[4], 0);
            v24 = COERCE_FLOAT(_mm_shuffle_ps(v22[4], v22[4], 0)) + a4.m128_f32[0];
            if ( v24 < v10 )
            {
              v10 = v24;
              v11 = (__m128i)v15;
            }
          }
          if ( v19 )
          {
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v31);
            v21 = v31.m_edge.m_index;
            v19 = v31.m_edge.m_triangle;
            v15 = v31;
          }
          v25 = &v31;
          if ( !v19 )
            v25 = 0i64;
        }
        while ( v25 );
      }
      if ( !v11.m128i_i64[0] )
        break;
      a4.m128_f32[0] = v8;
      if ( v10 >= COERCE_FLOAT(_mm_shuffle_ps(a4, a4, 0)) )
        break;
      _mm_store_si128((__m128i *)&v33, v11);
      v26 = _mm_cvtsi128_si32(_mm_srli_si128(v11, 8));
      v27 = (9i64 >> 2 * (unsigned __int8)v26) & 3;
      v28 = *(_QWORD *)(v11.m128i_i64[0] + 8 * v27 + 16);
      v29 = *(_OWORD *)(v28 + 64);
      *(float *)&v29 = v10;
      *(_OWORD *)(v28 + 64) = v29;
      v30 = *(__m128 **)(v11.m128i_i64[0] + 8i64 * v26 + 16);
      a4 = v30[4];
      a4.m128_f32[0] = v10;
      v30[4] = a4;
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
      hkgpMesh::collapseEdge(v6, (hkgpMeshBase::Edge *)&v33, 0);
      ++v7;
      v9 += 100;
    }
    while ( v7 < v5 );
  }
}

// File Line: 3366
// RVA: 0xCD5470
void __fastcall hkgpMesh::applyLaplacianSmoothing(hkgpMesh *this, float iterations)
{
  hkgpMesh *v2; // r15
  __m128 v3; // xmm11
  __m128 v4; // xmm6
  hkgpMeshBase::Triangle *v5; // r9
  __m128 v6; // xmm12
  hkgpMeshBase::Vertex *v7; // rax
  signed int v8; // edx
  float *v9; // rcx
  float v10; // xmm0_4
  hkgpMeshBase::Triangle *v11; // rbx
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator *v12; // rax
  signed int v13; // edi
  __m128i v14; // xmm6
  int v15; // er9
  __m128i *v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // rax
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rdx
  __m128i v21; // xmm6
  __m128i *v22; // rax
  signed __int64 v23; // rdx
  signed __int64 v24; // r8
  __int64 v25; // rdx
  __int64 v26; // rcx
  __m128 v27; // xmm7
  __m128 v28; // xmm6
  int v29; // er14
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
  hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator v44; // [rsp+20h] [rbp-D0h]
  __m128i v45; // [rsp+30h] [rbp-C0h]
  __m128i v46; // [rsp+40h] [rbp-B0h]
  __m128i v47; // [rsp+50h] [rbp-A0h]
  __m128i v48; // [rsp+60h] [rbp-90h]
  __m128i v49; // [rsp+70h] [rbp-80h]
  hkVector4f result; // [rsp+80h] [rbp-70h]
  char *array; // [rsp+90h] [rbp-60h]
  int v52; // [rsp+98h] [rbp-58h]
  int v53; // [rsp+9Ch] [rbp-54h]
  char v54; // [rsp+A0h] [rbp-50h]
  void *retaddr; // [rsp+248h] [rbp+158h]

  v2 = this;
  v3 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  if ( v3.m128_f32[0] > 0.0 )
  {
    v4 = query.m_quad;
    do
    {
      v5 = v2->m_triangles.m_used;
      v49.m128i_i32[2] = 0;
      v49.m128i_i64[0] = (__int64)v5;
      v6 = _mm_min_ps(v3, v4);
      _mm_store_si128((__m128i *)&v44, v49);
      if ( v5 )
      {
        v7 = v5->m_vertices[1];
        v8 = 0;
        v9 = v7->m_position.m_quad.m128_f32;
        do
        {
          v10 = *(float *)((char *)v9 + (char *)v5->m_vertices[0] - (char *)v7);
          if ( v10 < *v9 )
            break;
          if ( v10 > *v9 )
          {
            if ( v5->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
              hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v44);
            break;
          }
          ++v8;
          ++v9;
        }
        while ( v8 < 3 );
      }
      v11 = v44.m_edge.m_triangle;
      v12 = &v44;
      if ( !v44.m_edge.m_triangle )
        v12 = 0i64;
      if ( v12 )
      {
        v13 = v44.m_edge.m_index;
        do
        {
          v49.m128i_i64[0] = (__int64)v11;
          v49.m128i_i32[2] = v13;
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
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
              v15 = v52;
            }
            v16 = (__m128i *)&array[16 * v15];
            if ( v16 )
            {
              *v16 = v14;
              v15 = v52;
            }
            v52 = ++v15;
            v17 = (18 >> 2 * v45.m128i_i8[8]) & 3;
            v18 = *(_QWORD *)(v45.m128i_i64[0] + 8 * v17 + 40) & 3i64;
            v19 = *(_QWORD *)(v45.m128i_i64[0] + 8 * v17 + 40) & 0xFFFFFFFFFFFFFFFCui64;
            v46.m128i_i64[0] = *(_QWORD *)(v45.m128i_i64[0] + 8 * v17 + 40) & 0xFFFFFFFFFFFFFFFCui64;
            v46.m128i_i32[2] = v18;
            v14 = v46;
            v45 = v46;
            if ( !v19 )
              break;
            if ( (hkgpMeshBase::Triangle *)(v19 + (unsigned int)v18) == (hkgpMeshBase::Triangle *)((char *)v11
                                                                                                 + (unsigned int)v13) )
              goto LABEL_29;
          }
          v20 = v11->m_links[v13];
          v47.m128i_i64[0] = v20 & 0xFFFFFFFFFFFFFFFCui64;
          v47.m128i_i32[2] = (9 >> 2 * (v20 & 3)) & 3;
          v21 = v47;
          v45 = v47;
          if ( v20 & 0xFFFFFFFFFFFFFFFCui64 )
          {
            do
            {
              if ( v15 == (v53 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                v15 = v52;
              }
              v22 = (__m128i *)&array[16 * v15];
              if ( v22 )
              {
                *v22 = v21;
                v15 = v52;
              }
              v52 = ++v15;
              v23 = *(_QWORD *)(v45.m128i_i64[0] + 8i64 * v45.m128i_i32[2] + 40) & 3i64;
              v48.m128i_i64[0] = *(_QWORD *)(v45.m128i_i64[0] + 8i64 * v45.m128i_i32[2] + 40) & 0xFFFFFFFFFFFFFFFCui64;
              v48.m128i_i32[2] = (9 >> 2 * v23) & 3;
              v21 = v48;
              v45 = v48;
            }
            while ( v48.m128i_i64[0] );
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
                        _mm_cmpleps(v38, (__m128)0i64),
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
              v42 = (__m128 *)v11->m_vertices[v13];
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
            v25 = (__int64)array;
            while ( 1 )
            {
              v26 = *(signed int *)(v25 + 8);
              if ( !(*(_QWORD *)(*(_QWORD *)v25 + 8 * v26 + 40) & 0xFFFFFFFFFFFFFFFCui64)
                || !(*(_QWORD *)(*(_QWORD *)v25 + 8i64 * ((9 >> 2 * v26) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64) )
              {
                break;
              }
              ++v24;
              v25 += 16i64;
              if ( v24 >= v15 )
                goto LABEL_34;
            }
          }
          v52 = 0;
          if ( v53 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              16 * v53);
          if ( v11 )
          {
            hkgpAbstractMesh<hkgpMeshBase::Edge,hkgpMeshBase::Vertex,hkgpMeshBase::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v44);
            v13 = v44.m_edge.m_index;
            v11 = v44.m_edge.m_triangle;
          }
          v43 = &v44;
          if ( !v11 )
            v43 = 0i64;
        }
        while ( v43 );
        v4 = query.m_quad;
      }
      v3 = _mm_sub_ps(v3, v4);
    }
    while ( v3.m128_f32[0] > 0.0 );
  }
}

