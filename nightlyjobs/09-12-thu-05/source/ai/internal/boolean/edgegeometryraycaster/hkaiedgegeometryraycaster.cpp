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
  this->m_faceEdges.m_faceEdges.m_capacityAndFlags = 2147483648;
  this->m_faceEdges.m_faceStartEdges.m_data = 0i64;
  this->m_faceEdges.m_faceStartEdges.m_size = 0;
  this->m_faceEdges.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  this->m_facePlanes.m_data = 0i64;
  this->m_facePlanes.m_size = 0;
  this->m_facePlanes.m_capacityAndFlags = 2147483648;
  this->m_tree = 0i64;
  this->m_hitFilter.m_pntr = 0i64;
  this->m_faceFlagMask.m_storage = 15;
}

// File Line: 112
// RVA: 0xB7B130
void __fastcall hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(hkaiEdgeGeometryRaycaster *this)
{
  void **v1; // rdi
  hkaiEdgeGeometryRaycaster *v2; // rbx
  int v3; // eax
  _QWORD **v4; // rax
  hkReferencedObject *v5; // rcx
  int v6; // er8
  hkReferencedObject *v7; // rcx
  hkReferencedObject *v8; // rcx
  hkReferencedObject *v9; // rcx

  v1 = (void **)this->m_tree;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgeGeometryRaycaster::`vftable;
  if ( v1 )
  {
    v3 = *((_DWORD *)v1 + 3);
    *((_DWORD *)v1 + 2) = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *v1,
        48 * (v3 & 0x3FFFFFFF));
    *v1 = 0i64;
    *((_DWORD *)v1 + 3) = 2147483648;
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void **, signed __int64))(*v4[11] + 16i64))(v4[11], v1, 40i64);
  }
  v5 = (hkReferencedObject *)&v2->m_hitFilter.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v2->m_hitFilter.m_pntr = 0i64;
  v6 = v2->m_facePlanes.m_capacityAndFlags;
  v2->m_facePlanes.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_facePlanes.m_data,
      16 * v6);
  v2->m_facePlanes.m_data = 0i64;
  v2->m_facePlanes.m_capacityAndFlags = 2147483648;
  hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&v2->m_faceEdges);
  v7 = (hkReferencedObject *)&v2->m_carverGeometry.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v2->m_carverGeometry.m_pntr = 0i64;
  v8 = (hkReferencedObject *)&v2->m_geometry.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v2->m_geometry.m_pntr = 0i64;
  v9 = (hkReferencedObject *)&v2->m_edgeGeometry.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v2->m_edgeGeometry.m_pntr = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 122
// RVA: 0xB7B260
hkResult *__fastcall hkaiEdgeGeometryRaycaster::init(hkaiEdgeGeometryRaycaster *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  hkaiEdgeGeometry *v3; // rbx
  hkResult *v4; // r13
  hkaiEdgeGeometryRaycaster *v5; // rsi
  hkReferencedObject *v6; // rcx
  int v8; // er9
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  __int64 v12; // r10
  __int64 v13; // r11
  hkaiEdgeGeometry::Edge *const **v14; // rax
  __m128 v15; // xmm3
  signed int **v16; // rbx
  signed int **v17; // r8
  signed int **i; // rdx
  signed int *v19; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  _QWORD **v24; // rax
  hkcdDynamicTree::DefaultTree48Storage *v25; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *v26; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *v27; // rbx
  __int64 v28; // rdi
  __int64 v29; // r14
  unsigned int v30; // er12
  __int64 v31; // r13
  __m128 v32; // xmm11
  hkaiEdgeGeometry::Edge *const **v33; // rax
  __m128 v34; // xmm7
  int v35; // er8
  signed int **v36; // rdx
  signed int **v37; // r9
  __m128 v38; // xmm6
  hkVector4f *v39; // r10
  signed int *v40; // rax
  signed __int64 v41; // r15
  hkcdDynamicTree::CodecRaw<unsigned int> *v42; // rdx
  signed __int64 v43; // rdi
  hkcdDynamicTree::CodecRaw<unsigned int> *v44; // rax
  __int64 v45; // rbp
  __m128 v46; // xmm7
  __m128 v47; // xmm8
  __int64 v48; // rdx
  __m128 *v49; // r9
  signed __int64 v50; // r11
  __int64 v51; // rax
  __m128 v52; // xmm9
  __m128 v53; // xmm10
  __int64 v54; // r8
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  signed __int64 v57; // rdx
  __m128 *v58; // rdx
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  __m128 v64; // xmm6
  __m128 v65; // xmm5
  __m128 v66; // xmm5
  hkcdDynamicTree::CodecRaw<unsigned int> *v67; // rbp
  unsigned __int64 v68; // rdx
  unsigned __int64 v69; // r10
  float v70; // eax
  signed __int64 v71; // rcx
  __m128 v72; // xmm1
  hkcdDynamicTree::CodecRaw<unsigned int> *v73; // [rsp+30h] [rbp-A8h]
  __m128 *v74; // [rsp+38h] [rbp-A0h]
  hkResult resulta; // [rsp+E0h] [rbp+8h]
  hkResult *v76; // [rsp+E8h] [rbp+10h]
  hkResult v77; // [rsp+F0h] [rbp+18h]

  v76 = result;
  v3 = geom;
  v4 = result;
  v5 = this;
  if ( geom )
    hkReferencedObject::addReference((hkReferencedObject *)&geom->vfptr);
  v6 = (hkReferencedObject *)&v5->m_edgeGeometry.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_edgeGeometry.m_pntr = v3;
  hkaiFaceEdges::setGeometry(&v5->m_faceEdges, &resulta, v3);
  if ( resulta.m_enum )
  {
    v4->m_enum = 1;
    return v4;
  }
  v8 = v5->m_faceEdges.m_faceStartEdges.m_size - 1;
  v9 = v5->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 >= v8 )
  {
    resulta.m_enum = 0;
    goto LABEL_13;
  }
  v10 = 2 * v9;
  if ( v8 < v10 )
    v8 = v10;
  hkArrayUtil::_reserve(
    &resulta,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &v5->m_facePlanes,
    v8,
    16);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_13:
    hkaiEdgeGeometry::calculateFaceNormals(v5->m_edgeGeometry.m_pntr, &v5->m_faceEdges, &v5->m_facePlanes);
    v11 = 0;
    if ( v5->m_edgeGeometry.m_pntr->m_faces.m_size > 0 )
    {
      v12 = 0i64;
      v13 = 0i64;
      do
      {
        v14 = v5->m_faceEdges.m_faceStartEdges.m_data;
        ++v13;
        v15 = 0i64;
        v16 = (signed int **)v14[v13 - 1];
        v17 = (signed int **)v14[v13];
        for ( i = v16;
              i != v17;
              v15 = _mm_add_ps(
                      v15,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                        _mm_shuffle_ps(v20, v20, 170))) )
        {
          v19 = *i;
          ++i;
          v20 = _mm_mul_ps(
                  v5->m_edgeGeometry.m_pntr->m_vertices.m_data[*v19].m_quad,
                  v5->m_facePlanes.m_data[v12].m_quad);
        }
        v21 = 0i64;
        ++v11;
        ++v12;
        v21.m128_f32[0] = (float)(signed int)(v17 - v16);
        v22 = _mm_shuffle_ps(v21, v21, 0);
        v23 = _mm_rcp_ps(v22);
        v5->m_facePlanes.m_data[v12 - 1].m_quad = _mm_shuffle_ps(
                                                    v5->m_facePlanes.m_data[v12 - 1].m_quad,
                                                    _mm_unpackhi_ps(
                                                      v5->m_facePlanes.m_data[v12 - 1].m_quad,
                                                      _mm_sub_ps(
                                                        (__m128)0i64,
                                                        _mm_mul_ps(
                                                          v15,
                                                          _mm_mul_ps(
                                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)),
                                                            v23)))),
                                                    196);
      }
      while ( v11 < v5->m_edgeGeometry.m_pntr->m_faces.m_size );
    }
    if ( v5->m_edgeGeometry.m_pntr->m_edges.m_size )
    {
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                                       v24[11],
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
      v5->m_tree = v27;
      if ( !v27
        || (v28 = v5->m_edgeGeometry.m_pntr->m_faces.m_size,
            hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
              (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)&v27->m_nodes,
              &resulta,
              2 * v28),
            resulta.m_enum) )
      {
        v4->m_enum = 1;
        return v4;
      }
      v29 = 0i64;
      v30 = 0;
      if ( (signed int)v28 > 0 )
      {
        v31 = v28;
        v32 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        do
        {
          v33 = v5->m_faceEdges.m_faceStartEdges.m_data;
          v34 = (__m128)xmmword_141A712A0;
          v35 = 0;
          v36 = (signed int **)v33[v29];
          v37 = (signed int **)v33[v29 + 1];
          v38 = _mm_xor_ps(v32, (__m128)xmmword_141A712A0);
          if ( v36 != v37 )
          {
            v39 = v5->m_edgeGeometry.m_pntr->m_vertices.m_data;
            do
            {
              v40 = *v36;
              ++v36;
              ++v35;
              v34 = _mm_min_ps(v34, v39[*v40].m_quad);
              v38 = _mm_max_ps(v38, v39[*v40].m_quad);
            }
            while ( v36 != v37 );
            if ( v35 )
            {
              if ( !v27->m_firstFree )
                hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
                  (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)&v27->m_nodes,
                  &resulta,
                  256);
              v41 = v27->m_firstFree;
              v42 = v27->m_nodes.m_data;
              v43 = v41;
              v27->m_firstFree = v27->m_nodes.m_data[(signed int)v41].m_aabb.m_min.m_quad.m128_u32[0];
              v42[v43].m_children[0] = 0;
              v42[v43].m_children[1] = v30;
              v42[v43].m_aabb.m_min.m_quad = v34;
              v42[v43].m_aabb.m_max.m_quad = v38;
              v44 = v27->m_nodes.m_data;
              v45 = v27->m_root;
              v46 = v27->m_nodes.m_data[v41].m_aabb.m_min.m_quad;
              v47 = v27->m_nodes.m_data[v41].m_aabb.m_max.m_quad;
              if ( (_DWORD)v45 )
              {
                if ( !v27->m_firstFree )
                  hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
                    (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)&v27->m_nodes,
                    &v77,
                    256);
                v48 = v27->m_firstFree;
                v49 = &v27->m_nodes.m_data[v45].m_aabb.m_min.m_quad;
                v50 = (signed __int64)&v27->m_nodes.m_data[v48];
                v27->m_firstFree = v27->m_nodes.m_data[(signed int)v48].m_aabb.m_min.m_quad.m128_u32[0];
                v51 = v49[2].m128_u32[1];
                if ( (_DWORD)v51 )
                {
                  v52 = _mm_add_ps(v47, v46);
                  v53 = _mm_sub_ps(v47, v46);
                  do
                  {
                    v55 = _mm_min_ps(*v49, v46);
                    v56 = _mm_max_ps(v49[1], v47);
                    v57 = v49[2].m128_u32[2];
                    v73 = &v27->m_nodes.m_data[v51];
                    v54 = (__int64)v73;
                    v58 = &v27->m_nodes.m_data[v57].m_aabb.m_min.m_quad;
                    v74 = v58;
                    *v49 = v55;
                    v49[1] = v56;
                    v59 = *(__m128 *)(v54 + 16);
                    v60 = v59;
                    v61 = _mm_add_ps(_mm_sub_ps(v59, *(__m128 *)v54), v53);
                    v62 = _mm_sub_ps(_mm_add_ps(v60, *(__m128 *)v54), v52);
                    v63 = _mm_mul_ps(v62, v62);
                    v64 = _mm_add_ps(_mm_sub_ps(v58[1], *v58), v53);
                    v65 = _mm_sub_ps(_mm_add_ps(v58[1], *v58), v52);
                    v66 = _mm_mul_ps(v65, v65);
                    v49 = (__m128 *)*(&v73
                                    + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85))
                                                             + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170)))
                                             * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85))
                                                             + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170))))));
                    v51 = v49[2].m128_u32[1];
                  }
                  while ( (_DWORD)v51 );
                }
                v68 = (unsigned __int128)((v50 - (unsigned __int64)v27->m_nodes.m_data)
                                        * (signed __int128)3074457345618258603i64) >> 64;
                v69 = (v68 >> 63) + ((signed __int64)v68 >> 3);
                v70 = v49[2].m128_f32[0];
                if ( v70 == 0.0 )
                {
                  v27->m_root = v69;
                }
                else
                {
                  v67 = v27->m_nodes.m_data;
                  v67->m_children[(v67[LODWORD(v70)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v49 - (char *)v67) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                                    + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v49 - (char *)v67) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                                + 12i64 * LODWORD(v70)] = v69;
                }
                *(float *)(v50 + 32) = v49[2].m128_f32[0];
                v71 = (char *)v49 - (char *)v27->m_nodes.m_data;
                *(_DWORD *)(v50 + 40) = v41;
                *(_DWORD *)(v50 + 36) = ((unsigned __int64)((unsigned __int128)(v71
                                                                              * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                      + ((signed __int64)((unsigned __int128)(v71
                                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 3);
                v49[2].m128_i32[0] = v69;
                v27->m_nodes.m_data[v41].m_parent = v69;
                v72 = _mm_max_ps(v49[1], v47);
                *(__m128 *)v50 = _mm_min_ps(*v49, v46);
                *(__m128 *)(v50 + 16) = v72;
              }
              else
              {
                v27->m_root = v41;
                v44[v41].m_parent = 0;
              }
              ++v27->m_numLeaves;
            }
          }
          ++v29;
          ++v30;
        }
        while ( v29 < v31 );
        v4 = v76;
      }
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>>::optimizeIncremental(
        v27,
        v27->m_numLeaves,
        2);
    }
    else
    {
      v5->m_tree = 0i64;
    }
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

// File Line: 225
// RVA: 0xB7C130
hkResult *__fastcall hkaiEdgeGeometryRaycaster::initNoTree(hkaiEdgeGeometryRaycaster *this, hkResult *result, hkGeometry *geom)
{
  hkGeometry *v3; // rsi
  hkResult *v4; // rbx
  hkaiEdgeGeometryRaycaster *v5; // rbp
  hkReferencedObject *v6; // rcx
  __int64 v7; // r13
  int v8; // er14
  int v9; // eax
  int v10; // eax
  int v11; // er9
  _OWORD *v12; // rax
  __int64 v13; // r8
  __int64 v14; // r9
  hkGeometry::Triangle *v15; // rcx
  hkVector4f *v16; // rdx
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  hkResult resulta; // [rsp+90h] [rbp+8h]

  v3 = geom;
  v4 = result;
  v5 = this;
  if ( geom )
    hkReferencedObject::addReference((hkReferencedObject *)&geom->vfptr);
  v6 = (hkReferencedObject *)&v5->m_geometry.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_geometry.m_pntr = v3;
  v7 = v3->m_triangles.m_size;
  if ( (_DWORD)v7 )
  {
    v8 = v7 + 1;
    v9 = v5->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= (signed int)v7 + 1 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v10 = 2 * v9;
      v11 = v7 + 1;
      if ( v8 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_facePlanes,
        v11,
        16);
      if ( resulta.m_enum )
      {
        v4->m_enum = 1;
        return v4;
      }
    }
    v12 = (_OWORD *)v5->m_facePlanes.m_data->m_quad.m128_f32;
    v5->m_facePlanes.m_size = v8;
    v13 = v7;
    *v12 = 0i64;
    if ( (signed int)v7 > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = v3->m_triangles.m_data;
        v16 = v3->m_vertices.m_data;
        ++v14;
        v17 = v16[v15[v14 - 1].m_a].m_quad;
        v18 = _mm_sub_ps(v16[*((signed int *)&v15[v14] - 3)].m_quad, v17);
        v19 = _mm_sub_ps(v16[*((signed int *)&v15[v14] - 2)].m_quad, v17);
        v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19));
        v21 = _mm_shuffle_ps(v20, v20, 201);
        v22 = _mm_mul_ps(v21, v21);
        v23 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170));
        v24 = _mm_rsqrt_ps(v23);
        v25 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v23, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                    _mm_mul_ps(*(__m128 *)_xmm, v24))),
                v21);
        v26 = _mm_mul_ps(v17, v25);
        v5->m_facePlanes.m_data[v14].m_quad = _mm_shuffle_ps(
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
    v4->m_enum = 0;
  }
  else
  {
    v4->m_enum = 0;
  }
  return v4;
}

// File Line: 250
// RVA: 0xB7B8B0
hkResult *__fastcall hkaiEdgeGeometryRaycaster::init(hkaiEdgeGeometryRaycaster *this, hkResult *result, hkGeometry *geom, hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers, hkBitField *cuttingTriangles)
{
  hkArrayBase<hkRefPtr<hkaiVolume const > > *v5; // r15
  hkGeometry *v6; // r12
  hkResult *v7; // rsi
  hkaiEdgeGeometryRaycaster *v8; // r13
  hkReferencedObject *v9; // rcx
  _QWORD **v10; // rax
  __int64 v11; // rax
  hkGeometry *v12; // rbx
  hkReferencedObject *v13; // rcx
  int v14; // er14
  __int64 v15; // rbx
  hkaiVolume *v16; // rcx
  hkGeometry *v17; // rcx
  int v18; // er8
  int v19; // er15
  hkArray<hkVector4f,hkContainerHeapAllocator> *v20; // r12
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // er9
  _QWORD **v25; // rax
  hkcdDynamicTree::DefaultTree48Storage *v26; // rax
  __int64 *v27; // rax
  __int64 *v28; // rbx
  int v29; // er14
  __int64 v30; // r15
  hkGeometry *v31; // r8
  int v32; // ecx
  hkGeometry::Triangle *v33; // rcx
  hkVector4f *v34; // rdx
  __m128 v35; // xmm6
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  int v38; // eax
  hkGeometry *v39; // rcx
  hkGeometry::Triangle *v40; // rdx
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
  __int64 v55; // r8
  __int64 v56; // rdx
  signed __int64 v57; // rsi
  __int64 v58; // rax
  __int64 v59; // r12
  __m128 v60; // xmm7
  __m128 v61; // xmm8
  __int64 v62; // rdx
  __m128 *v63; // r9
  signed __int64 v64; // r11
  __int64 v65; // rax
  __m128 v66; // xmm9
  __m128 v67; // xmm10
  __int64 v68; // r8
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  signed __int64 v71; // rdx
  __m128 *v72; // rdx
  __m128 v73; // xmm2
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm6
  __m128 v77; // xmm3
  __m128 v78; // xmm3
  __m128 v79; // xmm5
  __m128 v80; // xmm5
  __int64 v81; // r12
  unsigned __int64 v82; // rdx
  unsigned __int64 v83; // r10
  float v84; // eax
  signed __int64 v85; // rcx
  __m128 v86; // xmm1
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  hkGeometry geometry; // [rsp+38h] [rbp-C8h]
  __int64 v90; // [rsp+68h] [rbp-98h]
  hkResult v91; // [rsp+70h] [rbp-90h]
  __int64 v92; // [rsp+78h] [rbp-88h]
  __m128 *v93; // [rsp+80h] [rbp-80h]
  hkMatrix4f transform; // [rsp+90h] [rbp-70h]
  hkResult v95; // [rsp+170h] [rbp+70h]
  hkResult *v96; // [rsp+178h] [rbp+78h]
  hkResult v97; // [rsp+180h] [rbp+80h]

  v96 = result;
  v5 = carvers;
  v6 = geom;
  v7 = result;
  v8 = this;
  if ( geom )
    hkReferencedObject::addReference((hkReferencedObject *)&geom->vfptr);
  v9 = (hkReferencedObject *)&v8->m_geometry.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v8->m_geometry.m_pntr = v6;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 48i64);
  v12 = (hkGeometry *)v11;
  if ( v11 )
  {
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkGeometry::`vftable;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_DWORD *)(v11 + 24) = 0;
    *(_DWORD *)(v11 + 28) = 2147483648;
    *(_QWORD *)(v11 + 32) = 0i64;
    *(_DWORD *)(v11 + 40) = 0;
    *(_DWORD *)(v11 + 44) = 2147483648;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (hkReferencedObject *)&v8->m_carverGeometry.m_pntr->vfptr;
  if ( v13 && v13 != (hkReferencedObject *)v12 )
    hkReferencedObject::removeReference(v13);
  v8->m_carverGeometry.m_pntr = v12;
  if ( !v12 )
  {
    v7->m_enum = 1;
    return v7;
  }
  v14 = 0;
  if ( v5->m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v5->m_data[v15].m_pntr;
      if ( v16 )
      {
        geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
        *(_DWORD *)&geometry.m_memSizeAndFlags = 0x1FFFF;
        geometry.m_vertices.m_data = 0i64;
        geometry.m_vertices.m_size = 0;
        geometry.m_vertices.m_capacityAndFlags = 2147483648;
        geometry.m_triangles.m_data = 0i64;
        geometry.m_triangles.m_size = 0;
        geometry.m_triangles.m_capacityAndFlags = 2147483648;
        ((void (__fastcall *)(hkaiVolume *, hkResult *, hkGeometry *))v16->vfptr[2].__first_virtual_table_function__)(
          v16,
          &v97,
          &geometry);
        if ( v97.m_enum )
        {
          v18 = geometry.m_triangles.m_capacityAndFlags;
          geometry.m_triangles.m_size = 0;
LABEL_24:
          v7->m_enum = 1;
          if ( v18 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              geometry.m_triangles.m_data,
              16 * v18);
          geometry.m_triangles.m_data = 0i64;
          geometry.m_triangles.m_capacityAndFlags = 2147483648;
          geometry.m_vertices.m_size = 0;
          if ( geometry.m_vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              geometry.m_vertices.m_data,
              16 * geometry.m_vertices.m_capacityAndFlags);
          return v7;
        }
        v17 = v8->m_carverGeometry.m_pntr;
        _mm_store_si128((__m128i *)&transform, _mm_srli_si128(_mm_slli_si128((__m128i)::transform.m_quad, 4), 4));
        _mm_store_si128((__m128i *)&transform.m_col1, _mm_srli_si128(_mm_slli_si128((__m128i)direction.m_quad, 4), 4));
        _mm_store_si128(
          (__m128i *)&transform.m_col2,
          _mm_srli_si128(_mm_slli_si128((__m128i)stru_141A71280.m_quad, 4), 4));
        transform.m_col3.m_quad = _mm_shuffle_ps(qi.m_vec.m_quad, _mm_unpackhi_ps(qi.m_vec.m_quad, query.m_quad), 196);
        hkGeometry::appendGeometry(v17, &resulta, &geometry, &transform);
        v18 = geometry.m_triangles.m_capacityAndFlags;
        geometry.m_triangles.m_size = 0;
        if ( resulta.m_enum )
          goto LABEL_24;
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
      ++v14;
      ++v15;
    }
    while ( v14 < v5->m_size );
  }
  v19 = v6->m_triangles.m_size + v8->m_carverGeometry.m_pntr->m_triangles.m_size;
  if ( !v19 )
    goto LABEL_65;
  v20 = &v8->m_facePlanes;
  v21 = v19 + 1;
  v22 = v8->m_facePlanes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 >= v19 + 1 )
  {
    v95.m_enum = 0;
  }
  else
  {
    v23 = 2 * v22;
    v24 = v19 + 1;
    if ( v21 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(
      &v95,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_facePlanes,
      v24,
      16);
    if ( v95.m_enum )
      goto LABEL_34;
  }
  v8->m_facePlanes.m_size = v21;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
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
  v8->m_tree = v28;
  if ( !v28
    || (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
          &v97,
          2 * v19),
        (v95.m_enum = v97.m_enum) != 0) )
  {
LABEL_34:
    v7->m_enum = 1;
    return v7;
  }
  v29 = 0;
  *v20->m_data = 0i64;
  v90 = v19;
  if ( v19 <= 0 )
    goto LABEL_64;
  v30 = 0i64;
  do
  {
    v31 = v8->m_geometry.m_pntr;
    v32 = v31->m_triangles.m_size;
    if ( v29 >= v32 )
    {
      v38 = v29 - v32;
      v39 = v8->m_carverGeometry.m_pntr;
      v40 = v39->m_triangles.m_data;
      v41 = v39->m_vertices.m_data;
      v35 = v41[v40[v38].m_a].m_quad;
      v36 = v41[v40[v38].m_b].m_quad;
      v37 = v41[v40[v38].m_c].m_quad;
    }
    else
    {
      if ( !((cuttingTriangles->m_storage.m_words.m_data[(signed __int64)v29 >> 5] >> (v29 & 0x1F)) & 1) )
      {
        v20->m_data[v30] = 0i64;
        goto LABEL_62;
      }
      v33 = v31->m_triangles.m_data;
      v34 = v31->m_vertices.m_data;
      v35 = v34[v33[v30].m_a].m_quad;
      v36 = v34[v33[v30].m_b].m_quad;
      v37 = v34[v33[v30].m_c].m_quad;
    }
    v42 = _mm_min_ps(v35, v36);
    v43 = _mm_max_ps(v35, v36);
    v44 = _mm_sub_ps(v36, v35);
    v45 = _mm_min_ps(v42, v37);
    v46 = _mm_max_ps(v43, v37);
    v47 = _mm_sub_ps(v37, v35);
    v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v47));
    v49 = _mm_shuffle_ps(v48, v48, 201);
    v50 = _mm_mul_ps(v49, v49);
    v51 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
            _mm_shuffle_ps(v50, v50, 170));
    v52 = _mm_rsqrt_ps(v51);
    v53 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v51, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                _mm_mul_ps(*(__m128 *)_xmm, v52))),
            v49);
    v54 = _mm_mul_ps(v53, v35);
    v20->m_data[v30 + 1].m_quad = _mm_shuffle_ps(
                                    v53,
                                    _mm_unpackhi_ps(
                                      v53,
                                      _mm_sub_ps(
                                        (__m128)0i64,
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                                          _mm_shuffle_ps(v54, v54, 170)))),
                                    196);
    if ( !*((_DWORD *)v28 + 4) )
      hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
        (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
        &resulta,
        256);
    v56 = *v28;
    v97.m_enum = *((_DWORD *)v28 + 4);
    v55 = (unsigned int)v97.m_enum;
    v57 = 6i64 * (unsigned int)v97.m_enum;
    *((_DWORD *)v28 + 4) = *(_DWORD *)(v56 + 48i64 * (signed int)v97.m_enum);
    *(_DWORD *)(v56 + 8 * v57 + 36) = 0;
    *(_DWORD *)(v56 + 8 * v57 + 40) = v29 + 1;
    *(__m128 *)(v56 + 8 * v57) = v45;
    *(__m128 *)(v56 + 8 * v57 + 16) = v46;
    v58 = *v28;
    v59 = *((unsigned int *)v28 + 8);
    v60 = *(__m128 *)(*v28 + 48 * v55);
    v61 = *(__m128 *)(*v28 + 48 * v55 + 16);
    if ( (_DWORD)v59 )
    {
      if ( !*((_DWORD *)v28 + 4) )
        hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > *)v28,
          &v91,
          256);
      v62 = *((unsigned int *)v28 + 4);
      v63 = (__m128 *)(*v28 + 48 * v59);
      v64 = *v28 + 48 * v62;
      *((_DWORD *)v28 + 4) = *(_DWORD *)(*v28 + 48i64 * (signed int)v62);
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
          v92 = *v28 + 48 * v65;
          v68 = v92;
          v72 = (__m128 *)(*v28 + v71);
          v93 = v72;
          *v63 = v69;
          v63[1] = v70;
          v73 = *(__m128 *)(v68 + 16);
          v74 = v73;
          v75 = _mm_add_ps(_mm_sub_ps(v73, *(__m128 *)v68), v67);
          v76 = _mm_add_ps(_mm_sub_ps(v72[1], *v72), v67);
          v77 = _mm_sub_ps(_mm_add_ps(v74, *(__m128 *)v68), v66);
          v78 = _mm_mul_ps(v77, v77);
          v79 = _mm_sub_ps(_mm_add_ps(v72[1], *v72), v66);
          v80 = _mm_mul_ps(v79, v79);
          v63 = (__m128 *)*(&v92
                          + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 170)))
                                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 170))))));
          v65 = v63[2].m128_u32[1];
        }
        while ( (_DWORD)v65 );
      }
      v82 = (unsigned __int128)((v64 - *v28) * (signed __int128)3074457345618258603i64) >> 64;
      v83 = (v82 >> 63) + ((signed __int64)v82 >> 3);
      v84 = v63[2].m128_f32[0];
      if ( v84 == 0.0 )
      {
        *((_DWORD *)v28 + 8) = v83;
      }
      else
      {
        v81 = *v28;
        *(_DWORD *)(v81
                  + 4
                  * ((*(_DWORD *)(v81 + 48i64 * LODWORD(v84) + 40) == ((unsigned __int64)((unsigned __int128)(((signed __int64)v63 - v81) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                                    + (unsigned int)((signed __int64)((unsigned __int128)(((signed __int64)v63 - v81) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                   + 12i64 * LODWORD(v84))
                  + 36) = v83;
      }
      *(float *)(v64 + 32) = v63[2].m128_f32[0];
      v85 = (signed __int64)v63 - *v28;
      *(hkResult *)(v64 + 40) = v97;
      *(_DWORD *)(v64 + 36) = ((unsigned __int64)((unsigned __int128)(v85 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                            + ((signed __int64)((unsigned __int128)(v85 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v63[2].m128_i32[0] = v83;
      *(_DWORD *)(*v28 + 8 * v57 + 32) = v83;
      v86 = _mm_max_ps(v63[1], v61);
      *(__m128 *)v64 = _mm_min_ps(*v63, v60);
      *(__m128 *)(v64 + 16) = v86;
    }
    else
    {
      *((_DWORD *)v28 + 8) = v55;
      *(_DWORD *)(v58 + 8 * v57 + 32) = 0;
    }
    ++*((_DWORD *)v28 + 6);
    v20 = &v8->m_facePlanes;
LABEL_62:
    ++v29;
    ++v30;
    --v90;
  }
  while ( v90 );
  v7 = v96;
LABEL_64:
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int>>>::optimizeIncremental(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > > *)v28,
    *((_DWORD *)v28 + 6),
    2);
LABEL_65:
  v7->m_enum = 0;
  return v7;
}v28,
    *((_DWORD *)v28 + 6),
    2);
LABEL_65:
  v7->m_enum = 0;
  return v7;
}

// File Line: 344
// RVA: 0xB7D960
signed __int64 __fastcall hkaiEdgeGeometryRaycaster::getNumVertsForFace(hkaiEdgeGeometryRaycaster *this, int faceId)
{
  signed __int64 result; // rax

  if ( this->m_geometry.m_pntr )
    result = 3i64;
  else
    result = (unsigned int)((_QWORD)((char *)this->m_faceEdges.m_faceStartEdges.m_data[faceId + 1]
                                   - (char *)this->m_faceEdges.m_faceStartEdges.m_data[faceId]) >> 3);
  return result;
}

// File Line: 359
// RVA: 0xB7D990
void __fastcall hkaiEdgeGeometryRaycaster::getVertsForFace(hkaiEdgeGeometryRaycaster *this, int faceId, hkArrayBase<hkVector4f> *vertsOut)
{
  hkArrayBase<hkVector4f> *v3; // r9
  hkaiEdgeGeometryRaycaster *v4; // r11
  hkGeometry *v5; // r8
  int v6; // eax
  int v7; // ecx
  hkVector4f *v8; // rcx
  hkGeometry::Triangle *v9; // rdx
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  __int64 v12; // rax
  hkGeometry *v13; // rdx
  int v14; // eax
  hkGeometry::Triangle *v15; // r8
  hkVector4f v16; // xmm2
  hkaiEdgeGeometry::Edge *const **v17; // rax
  hkaiEdgeGeometry::Edge *const *v18; // rsi
  __int64 v19; // r10
  signed __int64 v20; // rdx
  __int64 v21; // rbp
  signed __int64 v22; // rdi
  __int64 v23; // rbx
  hkaiEdgeGeometry::Edge *v24; // rcx
  hkVector4f *v25; // rdx
  __int64 v26; // r8

  v3 = vertsOut;
  v4 = this;
  if ( this->m_geometry.m_pntr )
  {
    vertsOut->m_size = 6;
    v5 = this->m_geometry.m_pntr;
    v6 = faceId - 1;
    v7 = v5->m_triangles.m_size;
    if ( faceId - 1 >= v7 )
    {
      v13 = v4->m_carverGeometry.m_pntr;
      v14 = v6 - v7;
      v8 = v13->m_vertices.m_data;
      v15 = &v13->m_triangles.m_data[v14];
      v10.m_quad = (__m128)v8[v15->m_a];
      v11.m_quad = (__m128)v8[v15->m_b];
      v12 = v15->m_c;
    }
    else
    {
      v8 = v5->m_vertices.m_data;
      v9 = &v5->m_triangles.m_data[v6];
      v10.m_quad = (__m128)v8[v9->m_a];
      v11.m_quad = (__m128)v8[v9->m_b];
      v12 = v9->m_c;
    }
    v16.m_quad = (__m128)v8[v12];
    *v3->m_data = (hkVector4f)v10.m_quad;
    v3->m_data[1] = (hkVector4f)v11.m_quad;
    v3->m_data[2] = (hkVector4f)v11.m_quad;
    v3->m_data[3] = (hkVector4f)v16.m_quad;
    v3->m_data[4] = (hkVector4f)v16.m_quad;
    v3->m_data[5] = (hkVector4f)v10.m_quad;
  }
  else
  {
    v17 = this->m_faceEdges.m_faceStartEdges.m_data;
    v18 = v17[faceId];
    v19 = 0i64;
    v20 = v17[faceId + 1] - v18;
    v21 = (signed int)v20;
    vertsOut->m_size = 2 * v20;
    if ( (signed int)v20 > 0 )
    {
      v22 = 1i64;
      v23 = 0i64;
      do
      {
        v24 = v18[v19++];
        v25 = v4->m_edgeGeometry.m_pntr->m_vertices.m_data;
        v26 = (signed int)v24->m_b;
        v22 += 2i64;
        v23 += 2i64;
        v3->m_data[v23 - 2] = v25[v24->m_a];
        v3->m_data[v22 - 2] = v25[v26];
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
  hkaiEdgeGeometryRaycaster *v3; // rbx
  hkaiEdgeGeometry *v5; // rdx
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> result; // [rsp+30h] [rbp+8h]

  v2 = faceId;
  v3 = this;
  hkaiEdgeGeometryRaycaster::getFlagsForFace(this, &result, faceId);
  if ( !(v3->m_faceFlagMask.m_storage & (unsigned __int8)result.m_storage) )
    return 1;
  v5 = v3->m_edgeGeometry.m_pntr;
  if ( v5 )
    LODWORD(v2) = v5->m_faces.m_data[v2].m_faceIndex;
  return (_DWORD)v2 == v3->m_ignoreFaceIndex;
}

// File Line: 445
// RVA: 0xB7D910
hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *__fastcall hkaiEdgeGeometryRaycaster::getFlagsForFace(hkaiEdgeGeometryRaycaster *this, hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *result, int faceId)
{
  hkaiEdgeGeometry *v3; // r9
  hkGeometry *v4; // rcx
  bool v5; // sf
  unsigned __int8 v6; // of
  char v7; // r8
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *v8; // rax

  v3 = this->m_edgeGeometry.m_pntr;
  if ( v3 )
  {
    v8 = result;
    result->m_storage = (char)v3->m_faces.m_data[faceId].m_flags;
  }
  else
  {
    v4 = this->m_geometry.m_pntr;
    v6 = __OFSUB__(faceId - 1, v4->m_triangles.m_size);
    v5 = faceId - 1 - v4->m_triangles.m_size < 0;
    v7 = 4;
    v8 = result;
    if ( v5 ^ v6 )
      v7 = 1;
    result->m_storage = v7;
  }
  return v8;
}

// File Line: 469
// RVA: 0xB7DC40
float __fastcall calculateEpsilon(hkArrayBase<hkVector4f> *faceVertices, int numEdges)
{
  __m128 v2; // xmm2
  __int64 v3; // r8
  __m128 v4; // xmm1
  hkVector4f *v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v2 = (__m128)xmmword_141A712A0;
  v3 = numEdges;
  v4 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( numEdges > 0 )
  {
    v5 = faceVertices->m_data;
    do
    {
      v2 = _mm_min_ps(v2, v5->m_quad);
      v4 = _mm_max_ps(v4, v5->m_quad);
      ++v5;
      --v3;
    }
    while ( v3 );
  }
  v6 = _mm_mul_ps(_mm_sub_ps(v4, v2), (__m128)xmmword_141A711B0);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  return COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0))
       * COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpleps(v8, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
               v8)));
}

// File Line: 488
// RVA: 0xB7DD00
__int64 __fastcall pointInPolygon(hkVector4f *samplePoint, hkVector4f *extrusion, hkArrayBase<hkVector4f> *faceVertices, int numEdges, hkVector4f *faceNorm, int maxNumIters)
{
  int v6; // er11
  hkVector4f *v7; // rbp
  hkArrayBase<hkVector4f> *v8; // rdi
  __int64 v9; // rsi
  int v10; // ebx
  __m128 v11; // xmm14
  __m128 v12; // xmm3
  float v13; // xmm8_4
  int v14; // er8
  __int64 v15; // r14
  __int64 v16; // r15
  int v17; // ecx
  __int64 v18; // rdx
  __m128 *v19; // r8
  __m128 v20; // xmm11
  __m128 v21; // xmm9
  __m128 v22; // xmm10
  __m128 *v23; // rax
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
  int v42; // er10
  unsigned int maxNumItersa; // [rsp+F8h] [rbp+30h]

  v6 = maxNumIters;
  v7 = extrusion;
  v8 = faceVertices;
  v9 = numEdges;
  v10 = 0;
  v11 = samplePoint->m_quad;
  v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)faceNorm), 1u), 1u);
  v13 = 0.0;
  v14 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
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
    if ( (signed int)v9 <= 0 )
      return v17 & 1;
    v19 = &v8->m_data->m_quad;
    v20 = v7->m_quad;
    v21 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v15];
    v22 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v16];
    v23 = &v8->m_data[1].m_quad;
    while ( 1 )
    {
      v24 = _mm_sub_ps(_mm_add_ps(v20, *v19), v11);
      v25 = _mm_sub_ps(_mm_add_ps(v20, *v23), v11);
      v26 = _mm_and_ps(v21, v24);
      v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_and_ps(v22, v24);
      v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 78), v28);
      v30 = _mm_and_ps(v21, v25);
      v31 = COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v29, v29, 177) | v29.m128_i32[0]) + v13;
      v32 = _mm_or_ps(_mm_shuffle_ps(v30, v30, 78), v30);
      v33 = _mm_and_ps(v22, v25);
      LODWORD(v34) = *(unsigned __int128 *)&_mm_shuffle_ps(v32, v32, 177) | v32.m128_i32[0];
      v35 = _mm_or_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v36 = COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v35, v35, 177) | v35.m128_i32[0]) + v13;
      if ( (float)(v36 * v31) >= 0.0 )
        break;
      v37 = v31 - v36;
      v38 = v37 < 0.0;
      v39 = COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v27, v27, 177) | v27.m128_i32[0]) - v34;
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
      v19 += 2;
      v23 += 2;
      if ( v18 >= v9 )
        return v17 & 1;
    }
    if ( (float)(v36 * v31) != 0.0 || v6 == 1 )
      goto LABEL_14;
    v41 = calculateEpsilon(v8, v9);
    ++v10;
    *(float *)&maxNumItersa = (float)((float)(v41 - COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]))
                                    * (float)((float)(1664525 * v42 + 1013904223) * 2.3283064e-10))
                            + COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]);
    LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps((__m128)maxNumItersa, (__m128)maxNumItersa, 0);
  }
  return 0i64;
}

// File Line: 575
// RVA: 0xB7CC70
unsigned int __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstFace(hkaiEdgeGeometryRaycaster *this, int faceId, hkVector4f *rayStart, hkVector4f *rayEnd, hkSimdFloat32 *hitFractionInOut)
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
__int64 __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstFace(hkaiEdgeGeometryRaycaster *this, int faceId, hkVector4f *rayStart, hkVector4f *rayEnd, hkVector4f *facePlane, hkVector4f *extrusion, hkSimdFloat32 *hitFractionInOut)
{
  hkVector4f *v7; // r14
  hkVector4f *v8; // r15
  unsigned int v9; // ebp
  hkaiEdgeGeometryRaycaster *v10; // rsi
  __m128 v12; // xmm5
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
  int v24; // eax
  unsigned int v25; // edi
  int v26; // ebx
  int v27; // er13
  LPVOID v28; // rax
  hkLifoAllocator *v29; // rcx
  hkVector4f *v30; // rax
  int v31; // edx
  char *v32; // r8
  hkaiEdgeGeometryHitFilter *v33; // rcx
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // er8
  __m128 v37; // [rsp+30h] [rbp-68h]
  hkVector4f samplePoint; // [rsp+40h] [rbp-58h]
  hkArrayBase<hkVector4f> vertsOut; // [rsp+50h] [rbp-48h]
  void *p; // [rsp+60h] [rbp-38h]
  int v41; // [rsp+68h] [rbp-30h]

  v7 = rayEnd;
  v8 = rayStart;
  v9 = faceId;
  v10 = this;
  if ( hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
    return 0i64;
  v12 = v8->m_quad;
  v13 = _mm_mul_ps(facePlane->m_quad, v8->m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, facePlane->m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(v7->m_quad, facePlane->m_quad);
  v17 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15);
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, facePlane->m_quad), 196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  if ( (float)(v20.m128_f32[0] * v17.m128_f32[0]) >= 0.0 )
    return 0i64;
  v21 = _mm_sub_ps(v7->m_quad, v12);
  v22 = _mm_sub_ps(v17, v20);
  v23 = _mm_rcp_ps(v22);
  v37 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)), v23), v17);
  samplePoint.m_quad = _mm_add_ps(_mm_mul_ps(v21, v37), v12);
  v24 = hkaiEdgeGeometryRaycaster::getNumVertsForFace(v10, v9);
  v25 = 0;
  v26 = 2 * v24;
  v27 = v24;
  vertsOut.m_size = 0;
  v41 = 2 * v24;
  if ( 2 * v24 )
  {
    v28 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (hkLifoAllocator *)v28;
    v30 = (hkVector4f *)*((_QWORD *)v28 + 3);
    v31 = (16 * v26 + 127) & 0xFFFFFF80;
    v32 = (char *)v30 + v31;
    if ( v31 > v29->m_slabSize || v32 > v29->m_end )
      v30 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v29, v31);
    else
      v29->m_cur = v32;
  }
  else
  {
    v30 = 0i64;
  }
  vertsOut.m_data = v30;
  p = v30;
  vertsOut.m_capacityAndFlags = v26 | 0x80000000;
  hkaiEdgeGeometryRaycaster::getVertsForFace(v10, v9, &vertsOut);
  if ( pointInPolygon(&samplePoint, extrusion, &vertsOut, v27, facePlane, 10) )
  {
    v33 = v10->m_hitFilter.m_pntr;
    if ( !v33
      || !((unsigned __int8 (__fastcall *)(hkaiEdgeGeometryHitFilter *, _QWORD, hkVector4f *, hkVector4f *, __m128 *, hkVector4f *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v33->vfptr[1].__first_virtual_table_function__)(
            v33,
            v9,
            v8,
            v7,
            &v37,
            facePlane,
            v37.m128_u64[0],
            v37.m128_u64[1],
            samplePoint.m_quad.m128_u64[0],
            samplePoint.m_quad.m128_u64[1]) )
    {
      v25 = 1;
      hitFractionInOut->m_real = _mm_min_ps(v37, hitFractionInOut->m_real);
    }
  }
  v34 = (16 * v41 + 127) & 0xFFFFFF80;
  v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (v34 + 15) & 0xFFFFFFF0;
  if ( v34 > v35->m_slabSize || (char *)p + v36 != v35->m_cur || v35->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v35, p, v36);
  else
    v35->m_cur = p;
  if ( vertsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertsOut.m_data,
      16 * vertsOut.m_capacityAndFlags);
  return v25;
}

// File Line: 649
// RVA: 0xB7CF40
signed __int64 __fastcall hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(hkaiEdgeGeometryRaycaster *this, int faceId, hkVector4f *rayStart, hkVector4f *rayEnd, hkcdRay *ray, hkVector4f *extrusion, bool stopOnFirstHit, hkSimdFloat32 *hitFractionInOut)
{
  __int64 v8; // r15
  hkaiEdgeGeometryRaycaster *v9; // r13
  unsigned int v11; // edi
  signed int v12; // ebp
  int v13; // eax
  __int64 v14; // rsi
  int v15; // ebx
  LPVOID v16; // rax
  hkLifoAllocator *v17; // rcx
  hkVector4f *v18; // rax
  int v19; // edx
  char *v20; // r8
  __int64 v21; // r8
  hkVector4f *v22; // rcx
  __m128 v23; // xmm11
  __m128 v24; // xmm12
  hkVector4f v25; // xmm5
  __m128 v26; // xmm10
  __m128 v27; // xmm9
  __m128 v28; // xmm13
  __m128 v29; // xmm14
  __m128 v30; // xmm8
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm6
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm5
  __m128 v45; // xmm9
  __m128 v46; // xmm6
  __m128 v47; // xmm6
  __m128 v48; // xmm9
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  signed int v51; // edx
  signed int v52; // ebx
  hkLifoAllocator *v53; // rax
  int v54; // er8
  __m128 v55; // xmm9
  __m128 v56; // xmm10
  __m128 v57; // xmm12
  hkVector4f v58; // xmm5
  __m128 v59; // xmm11
  __m128 v60; // xmm13
  __m128 v61; // xmm8
  __m128 v62; // xmm8
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm1
  __m128 v68; // xmm7
  __m128 v69; // xmm6
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  __m128 v72; // xmm4
  __m128 v73; // xmm5
  __m128 v74; // xmm1
  __m128 v75; // xmm5
  __m128 v76; // xmm9
  __m128 v77; // xmm6
  __m128 v78; // xmm6
  __m128 v79; // xmm9
  __m128 v80; // xmm0
  __m128 v81; // xmm3
  signed int v82; // eax
  signed int v83; // ebx
  hkLifoAllocator *v84; // rax
  int v85; // er8
  signed int v86; // edx
  __m128 v87; // xmm3
  __m128 v88; // xmm1
  hkArrayBase<hkVector4f> vertsOut; // [rsp+40h] [rbp-E8h]
  void *p; // [rsp+50h] [rbp-D8h]
  int v91; // [rsp+58h] [rbp-D0h]
  hkVector4f *rayStarta; // [rsp+140h] [rbp+18h]
  hkVector4f *rayEnda; // [rsp+148h] [rbp+20h]

  rayEnda = rayEnd;
  rayStarta = rayStart;
  v8 = faceId;
  v9 = this;
  if ( hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
    return 0i64;
  v11 = 0;
  v12 = 0;
  v13 = hkaiEdgeGeometryRaycaster::getNumVertsForFace(v9, v8);
  vertsOut.m_size = 0;
  v14 = v13;
  v15 = 2 * v13;
  v91 = 2 * v13;
  if ( 2 * v13 )
  {
    v16 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkLifoAllocator *)v16;
    v18 = (hkVector4f *)*((_QWORD *)v16 + 3);
    v19 = (16 * v15 + 127) & 0xFFFFFF80;
    v20 = (char *)v18 + v19;
    if ( v19 > v17->m_slabSize || v20 > v17->m_end )
      v18 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v17, v19);
    else
      v17->m_cur = v20;
  }
  else
  {
    v18 = 0i64;
  }
  vertsOut.m_data = v18;
  p = v18;
  vertsOut.m_capacityAndFlags = v15 | 0x80000000;
  hkaiEdgeGeometryRaycaster::getVertsForFace(v9, v8, &vertsOut);
  v21 = 0i64;
  if ( v14 > 0 )
  {
    v22 = vertsOut.m_data;
    do
    {
      v23 = _mm_add_ps(v22[1].m_quad, extrusion->m_quad);
      v24 = _mm_sub_ps(ray->m_origin.m_quad, v22->m_quad);
      v25.m_quad = (__m128)ray->m_direction;
      v26 = _mm_sub_ps(v23, v22->m_quad);
      v27 = _mm_sub_ps(_mm_add_ps(v22->m_quad, extrusion->m_quad), v22->m_quad);
      v28 = _mm_shuffle_ps(v26, v26, 201);
      v29 = _mm_shuffle_ps(v27, v27, 201);
      v30 = _mm_sub_ps(_mm_mul_ps(v27, v28), _mm_mul_ps(v26, v29));
      v31 = _mm_shuffle_ps(v30, v30, 201);
      v32 = _mm_mul_ps(v31, v25.m_quad);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      if ( (float)(v33.m128_f32[0] * v33.m128_f32[0]) < 0.00000011920929 )
        goto LABEL_56;
      v34 = _mm_mul_ps(v31, v24);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170));
      v36 = _mm_rcp_ps(v33);
      v37 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v33)), v36), _mm_sub_ps((__m128)0i64, v35));
      if ( !_mm_movemask_ps(_mm_mul_ps(v35, v33)) )
        goto LABEL_56;
      if ( v37.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps(v25.m_quad, v25.m_quad, 255)) )
        goto LABEL_56;
      v38 = _mm_add_ps(_mm_mul_ps(v37, v25.m_quad), v24);
      v39 = _mm_sub_ps(v26, v38);
      v40 = _mm_sub_ps(v27, v38);
      v41 = _mm_mul_ps(v31, v31);
      v42 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40), _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39));
      v43 = _mm_shuffle_ps(v38, v38, 201);
      v44 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v31);
      v45 = _mm_sub_ps(_mm_mul_ps(v27, v43), _mm_mul_ps(v38, v29));
      v46 = _mm_sub_ps(_mm_mul_ps(v38, v28), _mm_mul_ps(v26, v43));
      v47 = _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v31);
      v48 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v31);
      v49 = _mm_unpacklo_ps(v44, v48);
      v50 = _mm_movelh_ps(v49, v47);
      if ( (_mm_movemask_ps(
              _mm_cmpleps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                    _mm_shuffle_ps(v41, v41, 170)),
                  (__m128)_xmm_b951b717b951b717b951b717b951b717),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v44, v48), v47, 228),
                  _mm_add_ps(v50, _mm_shuffle_ps(_mm_movehl_ps(v50, v49), v47, 212))))) & 7) == 7 )
      {
        v51 = 15;
        hitFractionInOut->m_real = _mm_min_ps(v37, hitFractionInOut->m_real);
        if ( stopOnFirstHit )
          goto LABEL_16;
      }
      else
      {
LABEL_56:
        v51 = 0;
      }
      v55 = _mm_sub_ps(v22[1].m_quad, v23);
      v56 = _mm_sub_ps(v22->m_quad, v23);
      v57 = _mm_sub_ps(ray->m_origin.m_quad, v23);
      v58.m_quad = (__m128)ray->m_direction;
      v59 = _mm_shuffle_ps(v56, v56, 201);
      v60 = _mm_shuffle_ps(v55, v55, 201);
      v61 = _mm_sub_ps(_mm_mul_ps(v55, v59), _mm_mul_ps(v56, v60));
      v62 = _mm_shuffle_ps(v61, v61, 201);
      v63 = _mm_mul_ps(v62, v58.m_quad);
      v64 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
              _mm_shuffle_ps(v63, v63, 170));
      if ( (float)(v64.m128_f32[0] * v64.m128_f32[0]) < 0.00000011920929 )
        goto LABEL_57;
      v65 = _mm_mul_ps(v62, v57);
      v66 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
              _mm_shuffle_ps(v65, v65, 170));
      v67 = _mm_rcp_ps(v64);
      v68 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v64)), v67), _mm_sub_ps((__m128)0i64, v66));
      if ( !_mm_movemask_ps(_mm_mul_ps(v66, v64)) )
        goto LABEL_57;
      if ( v68.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps(v58.m_quad, v58.m_quad, 255)) )
        goto LABEL_57;
      v69 = _mm_add_ps(_mm_mul_ps(v68, v58.m_quad), v57);
      v70 = _mm_sub_ps(v56, v69);
      v71 = _mm_sub_ps(v55, v69);
      v72 = _mm_mul_ps(v62, v62);
      v73 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v71), _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v70));
      v74 = _mm_shuffle_ps(v69, v69, 201);
      v75 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v62);
      v76 = _mm_sub_ps(_mm_mul_ps(v55, v74), _mm_mul_ps(v69, v60));
      v77 = _mm_sub_ps(_mm_mul_ps(v69, v59), _mm_mul_ps(v56, v74));
      v78 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v62);
      v79 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v62);
      v80 = _mm_unpacklo_ps(v75, v79);
      v81 = _mm_movelh_ps(v80, v78);
      if ( (_mm_movemask_ps(
              _mm_cmpleps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                    _mm_shuffle_ps(v72, v72, 170)),
                  (__m128)_xmm_b951b717b951b717b951b717b951b717),
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v75, v79), v78, 228),
                  _mm_add_ps(v81, _mm_shuffle_ps(_mm_movehl_ps(v81, v80), v78, 212))))) & 7) == 7 )
      {
        v82 = 15;
        hitFractionInOut->m_real = _mm_min_ps(v68, hitFractionInOut->m_real);
        if ( stopOnFirstHit )
        {
LABEL_16:
          v52 = (16 * v91 + 127) & 0xFFFFFF80;
          v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v54 = (v52 + 15) & 0xFFFFFFF0;
          if ( v52 > v53->m_slabSize || (char *)p + v54 != v53->m_cur || v53->m_firstNonLifoEnd == p )
            hkLifoAllocator::slowBlockFree(v53, p, v54);
          else
            v53->m_cur = p;
          if ( vertsOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              vertsOut.m_data,
              16 * vertsOut.m_capacityAndFlags);
          return 1i64;
        }
      }
      else
      {
LABEL_57:
        v82 = 0;
      }
      if ( v12 || v51 || (v12 = 0, v82) )
        v12 = 1;
      ++v21;
      v22 += 2;
    }
    while ( v21 < v14 );
  }
  v83 = (16 * v91 + 127) & 0xFFFFFF80;
  v84 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v85 = (v83 + 15) & 0xFFFFFFF0;
  if ( v83 > v84->m_slabSize || (char *)p + v85 != v84->m_cur || v84->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v84, p, v85);
  else
    v84->m_cur = p;
  if ( vertsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertsOut.m_data,
      16 * vertsOut.m_capacityAndFlags);
  if ( v12
    || (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                       v9,
                       v8,
                       rayStarta,
                       rayEnda,
                       &v9->m_facePlanes.m_data[v8],
                       &aabbOut,
                       hitFractionInOut) )
  {
    v86 = 1;
    if ( stopOnFirstHit )
      return 1i64;
  }
  else
  {
    v86 = 0;
  }
  v87 = v9->m_facePlanes.m_data[v8].m_quad;
  v88 = _mm_mul_ps(extrusion->m_quad, v87);
  vertsOut = (hkArrayBase<hkVector4f>)_mm_shuffle_ps(
                                        v87,
                                        _mm_unpackhi_ps(
                                          v87,
                                          _mm_sub_ps(
                                            _mm_shuffle_ps(v87, v87, 255),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                                              _mm_shuffle_ps(v88, v88, 170)))),
                                        196);
  if ( v86
    || (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                       v9,
                       v8,
                       rayStarta,
                       rayEnda,
                       (hkVector4f *)&vertsOut,
                       extrusion,
                       hitFractionInOut) )
  {
    v11 = 1;
  }
  return v11;
}

// File Line: 723
// RVA: 0xB7D6C0
void __fastcall hkaiEdgeGeometryRaycaster::raycastBundleAgainstFace(hkaiEdgeGeometryRaycaster *this, int faceId, hkVector4f *bundleStarts, hkVector4f *bundleEnds, hkcdRay *rays, hkVector4f *hitFractions, hkVector4fComparison *mask, hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut, unsigned int extruded, hkVector4f *extrusion)
{
  __int64 v10; // r15
  hkVector4f *v11; // r12
  hkVector4f *v12; // r13
  hkaiEdgeGeometryRaycaster *v13; // r14
  hkaiEdgeGeometry *v14; // r10
  bool v15; // cl
  signed int v16; // edi
  __m128 *v17; // rsi
  int v18; // eax
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  unsigned int v21; // eax
  __m128i v22; // xmm0
  hkVector4f v23; // xmm0
  char v24; // [rsp+40h] [rbp-48h]
  bool i; // [rsp+40h] [rbp-48h]
  hkSimdFloat32 hitFractionInOut; // [rsp+50h] [rbp-38h]

  v10 = faceId;
  v11 = bundleEnds;
  v12 = bundleStarts;
  v13 = this;
  if ( !hkaiEdgeGeometryRaycaster::shouldSkipFace(this, faceId) )
  {
    v14 = v13->m_edgeGeometry.m_pntr;
    if ( v14 )
      v24 = v14->m_faces.m_data[v10].m_flags.m_storage;
    else
      v24 = 1;
    v15 = extruded && !(v24 & 6);
    v16 = 0;
    v17 = 0i64;
    for ( i = v15; ; v15 = i )
    {
      v18 = _mm_movemask_ps(mask->m_mask);
      if ( _bittest(&v18, v16) )
      {
        v19 = _mm_and_ps(v17[337020912], hitFractions->m_quad);
        v20 = _mm_or_ps(_mm_shuffle_ps(v19, v19, 78), v19);
        hitFractionInOut.m_real = _mm_or_ps(_mm_shuffle_ps(v20, v20, 177), v20);
        v21 = v15 ? (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(
                                    v13,
                                    v10,
                                    &v12[v16],
                                    &v11[v16],
                                    &rays[v16],
                                    extrusion,
                                    earlyOut != 2,
                                    &hitFractionInOut) : hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                                                           v13,
                                                           v10,
                                                           &v12[v16],
                                                           &v11[v16],
                                                           &hitFractionInOut);
        if ( v21 )
        {
          if ( earlyOut == STOP_BUNDLE_ON_HIT )
          {
            *hitFractions = 0i64;
            return;
          }
          if ( earlyOut == 1 )
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
              v22 = _mm_load_si128((const __m128i *)hitFractions);
              if ( v16 == 3 )
                v23.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(v22, 4), 4);
              else
                v23.m_quad = (__m128)_mm_slli_si128(_mm_srli_si128(v22, 4), 4);
              *hitFractions = (hkVector4f)v23.m_quad;
            }
          }
          else
          {
            hitFractions->m_quad = _mm_or_ps(
                                     _mm_andnot_ps(v17[337020912], hitFractions->m_quad),
                                     _mm_and_ps(v17[337020912], hitFractionInOut.m_real));
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
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRay(hkaiEdgeGeometryRaycaster *this, hkVector4f *start, hkVector4f *end)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *v3; // r9
  __m128 v5; // xmm5
  unsigned int v6; // ebx
  __m128i v7; // xmm5
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  hkaiEdgeGeometryRaycaster *v10; // [rsp+20h] [rbp-1D8h]
  __m128 v11; // [rsp+30h] [rbp-1C8h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+40h] [rbp-1B8h]
  int v13; // [rsp+1C0h] [rbp-38h]

  v3 = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)this->m_tree;
  if ( !v3 )
    return 0i64;
  v5 = end->m_quad;
  v10 = this;
  v6 = 0;
  stackInstance.m_stack[16] = -1;
  v11 = v5;
  v13 = 0;
  v7 = (__m128i)_mm_sub_ps(v5, start->m_quad);
  *(hkVector4f *)&stackInstance.m_stack[4] = (hkVector4f)start->m_quad;
  v8 = _mm_cmpeqps((__m128)0i64, (__m128)v7);
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
  stackInstance.m_stack[31] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, *(__m128 *)&stackInstance.m_stack[8])) & 7 | 0x3F000000;
  *(_QWORD *)stackInstance.m_stack = &v10;
  *(_OWORD *)&stackInstance.m_stack[12] = *(_OWORD *)&stackInstance.m_stack[28];
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::RayCastWrapper<FirstHitRayQuery>>(
    v3,
    (EdgeGeomRaycastAabbTree *)&stackInstance.m_stack[32],
    &stackInstance,
    (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::RayCastWrapper<FirstHitRayQuery> *)v3);
  if ( COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&stackInstance.m_stack[8], *(__m128 *)&stackInstance.m_stack[8], 255)) < 1.0 )
    v6 = 1;
  return v6;
}

// File Line: 926
// RVA: 0xB7C490
unsigned int __fastcall hkaiEdgeGeometryRaycaster::castRayExtruded(hkaiEdgeGeometryRaycaster *this, hkVector4f *start, hkVector4f *end, hkVector4f *extrusion)
{
  __int128 v5; // xmm0
  hkVector4f ends; // [rsp+30h] [rbp-88h]
  __int128 v7; // [rsp+40h] [rbp-78h]
  __int128 v8; // [rsp+50h] [rbp-68h]
  __int128 v9; // [rsp+60h] [rbp-58h]
  hkVector4f starts; // [rsp+70h] [rbp-48h]
  __m128 v11; // [rsp+80h] [rbp-38h]
  __m128 v12; // [rsp+90h] [rbp-28h]
  __m128 v13; // [rsp+A0h] [rbp-18h]

  if ( !this->m_tree )
    return 0;
  v5 = (__int128)end->m_quad;
  starts.m_quad = start->m_quad;
  ends.m_quad = (__m128)v5;
  v11 = starts.m_quad;
  v7 = v5;
  v12 = starts.m_quad;
  v8 = v5;
  v13 = starts.m_quad;
  v9 = v5;
  return hkaiEdgeGeometryRaycaster::castRayBundleExtruded(this, &starts, &ends, extrusion, 0);
}

// File Line: 943
// RVA: 0xB7C510
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRayBundle(hkaiEdgeGeometryRaycaster *this, hkVector4f *starts, hkVector4f *ends, hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut)
{
  hkaiEdgeGeometryRaycaster *v4; // rbx
  unsigned int v6; // esi
  signed __int64 v7; // r8
  RayBundleQuery *v8; // r9
  __m128 *v9; // rcx
  signed __int64 v10; // r11
  __m128 v11; // xmm6
  __m128 v12; // xmm5
  __m128i v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // [rsp+20h] [rbp-E0h]
  __m128 v28; // [rsp+30h] [rbp-D0h]
  __m128 v29; // [rsp+40h] [rbp-C0h]
  __m128 v30; // [rsp+50h] [rbp-B0h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+60h] [rbp-A0h]
  int v32; // [rsp+1B0h] [rbp+B0h]
  hkaiEdgeGeometryRaycaster::BundleEarlyOut v33; // [rsp+1B4h] [rbp+B4h]
  int v34; // [rsp+1B8h] [rbp+B8h]
  __int128 v35; // [rsp+1C0h] [rbp+C0h]
  __int128 v36; // [rsp+1D0h] [rbp+D0h]
  __int128 v37; // [rsp+1E0h] [rbp+E0h]
  EdgeGeomRaycastAabbTree tree; // [rsp+1F0h] [rbp+F0h]
  int v39; // [rsp+2F0h] [rbp+1F0h]

  v4 = this;
  if ( !this->m_tree )
    return 0i64;
  v6 = 0;
  *(_QWORD *)&stackInstance.m_stack[34] = ends;
  v33 = earlyOut;
  v7 = (char *)ends - (char *)starts;
  *(_QWORD *)stackInstance.m_stack = 0i64;
  *(_QWORD *)&stackInstance.m_stack[32] = starts;
  v8 = (RayBundleQuery *)starts;
  v9 = (__m128 *)&stackInstance.m_stack[44];
  v10 = 4i64;
  *(hkVector4f *)&stackInstance.m_stack[28] = (hkVector4f)query.m_quad;
  *(_OWORD *)&stackInstance.m_stack[4] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[8] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[12] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[16] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[20] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[24] = 0i64;
  do
  {
    v11 = *(__m128 *)&v8->m_caster;
    v12 = *(__m128 *)((char *)&v8->m_caster + v7);
    v8 = (RayBundleQuery *)((char *)v8 + 16);
    v9 += 3;
    v13 = (__m128i)_mm_sub_ps(v12, v11);
    v14 = _mm_cmpeqps((__m128)0i64, (__m128)v13);
    v15 = _mm_rcp_ps((__m128)v13);
    v16 = _mm_shuffle_ps((__m128)v13, _mm_unpackhi_ps((__m128)v13, query.m_quad), 196);
    v9[-4] = v16;
    v9[-3] = _mm_or_ps(
               _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v13, 0x1Fu), 0x1Fu), (__m128)_xmm), v14),
               _mm_andnot_ps(v14, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, (__m128)v13)), v15)));
    v9[-3].m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v16)) & 7 | 0x3F000000;
    v9[-5] = v11;
    *(__m128 *)((char *)v8 + (char *)&v27 - (char *)starts - 16) = v9[-3];
    --v10;
  }
  while ( v10 );
  v17 = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)v4->m_tree;
  v34 = 0;
  v32 = 1;
  v35 = 0i64;
  *(_QWORD *)stackInstance.m_stack = v4;
  v39 = 0;
  v36 = 0i64;
  v37 = 0i64;
  v18 = _mm_shuffle_ps(v29, v30, 68);
  v19 = _mm_shuffle_ps(v27, v28, 68);
  v20 = starts[2].m_quad;
  *(__m128 *)&stackInstance.m_stack[24] = _mm_shuffle_ps(
                                            _mm_shuffle_ps(v27, v28, 238),
                                            _mm_shuffle_ps(v29, v30, 238),
                                            136);
  v21 = starts->m_quad;
  v22 = starts->m_quad;
  *(__m128 *)&stackInstance.m_stack[16] = _mm_shuffle_ps(v19, v18, 136);
  *(__m128 *)&stackInstance.m_stack[20] = _mm_shuffle_ps(v19, v18, 221);
  v23 = _mm_shuffle_ps(v22, starts[1].m_quad, 68);
  v24 = _mm_shuffle_ps(v20, starts[3].m_quad, 68);
  v25 = _mm_shuffle_ps(v21, starts[1].m_quad, 238);
  v26 = _mm_shuffle_ps(v20, starts[3].m_quad, 238);
  *(__m128 *)&stackInstance.m_stack[4] = _mm_shuffle_ps(v23, v24, 136);
  *(__m128 *)&stackInstance.m_stack[8] = _mm_shuffle_ps(v23, v24, 221);
  *(__m128 *)&stackInstance.m_stack[12] = _mm_shuffle_ps(v25, v26, 136);
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,RayBundleQuery>(
    v17,
    &tree,
    &stackInstance,
    v8);
  LOBYTE(v6) = _mm_movemask_ps(_mm_cmpltps(*(__m128 *)&stackInstance.m_stack[28], query.m_quad)) == 15;
  return v6;
}

// File Line: 961
// RVA: 0xB7C790
__int64 __fastcall hkaiEdgeGeometryRaycaster::castRayBundleExtruded(hkaiEdgeGeometryRaycaster *this, hkVector4f *starts, hkVector4f *ends, hkVector4f *extrusion, hkaiEdgeGeometryRaycaster::BundleEarlyOut earlyOut)
{
  hkVector4f *v5; // r14
  hkVector4f *v6; // r10
  hkaiEdgeGeometryRaycaster *v7; // rbx
  unsigned int v9; // esi
  signed __int64 v10; // r8
  __m128 *v11; // rcx
  RayBundleQuery *v12; // r9
  signed __int64 v13; // r11
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128i v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *v20; // rcx
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
  __m128 v32; // [rsp+20h] [rbp-E0h]
  __m128 v33; // [rsp+30h] [rbp-D0h]
  __m128 v34; // [rsp+40h] [rbp-C0h]
  __m128 v35; // [rsp+50h] [rbp-B0h]
  hkcdTreeQueriesStacks::FixedCpu<64,unsigned int> stackInstance; // [rsp+60h] [rbp-A0h]
  int v37; // [rsp+1B0h] [rbp+B0h]
  hkaiEdgeGeometryRaycaster::BundleEarlyOut v38; // [rsp+1B4h] [rbp+B4h]
  int v39; // [rsp+1B8h] [rbp+B8h]
  __m128 v40; // [rsp+1C0h] [rbp+C0h]
  __m128 v41; // [rsp+1D0h] [rbp+D0h]
  __m128 v42; // [rsp+1E0h] [rbp+E0h]
  EdgeGeomRaycastAabbTree tree; // [rsp+1F0h] [rbp+F0h]
  int v44; // [rsp+2F0h] [rbp+1F0h]

  v5 = extrusion;
  v6 = starts;
  v7 = this;
  if ( !this->m_tree )
    return 0i64;
  v9 = 0;
  *(_QWORD *)&stackInstance.m_stack[34] = ends;
  v10 = (char *)ends - (char *)starts;
  *(_QWORD *)&stackInstance.m_stack[32] = starts;
  v38 = earlyOut;
  *(_QWORD *)stackInstance.m_stack = 0i64;
  v11 = (__m128 *)&stackInstance.m_stack[44];
  v12 = (RayBundleQuery *)((char *)&v32 - (char *)starts);
  *(hkVector4f *)&stackInstance.m_stack[28] = (hkVector4f)query.m_quad;
  *(_OWORD *)&stackInstance.m_stack[4] = 0i64;
  v13 = 4i64;
  *(_OWORD *)&stackInstance.m_stack[8] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[12] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[16] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[20] = 0i64;
  *(_OWORD *)&stackInstance.m_stack[24] = 0i64;
  do
  {
    v14 = starts->m_quad;
    v15 = *(__m128 *)((char *)&starts->m_quad + v10);
    ++starts;
    v11 += 3;
    v16 = (__m128i)_mm_sub_ps(v15, v14);
    v17 = _mm_cmpeqps((__m128)0i64, (__m128)v16);
    v18 = _mm_rcp_ps((__m128)v16);
    v19 = _mm_shuffle_ps((__m128)v16, _mm_unpackhi_ps((__m128)v16, query.m_quad), 196);
    v11[-4] = v19;
    v11[-3] = _mm_or_ps(
                _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v16, 0x1Fu), 0x1Fu), (__m128)_xmm), v17),
                _mm_andnot_ps(v17, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v16, v18)), v18)));
    v11[-3].m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v19)) & 7 | 0x3F000000;
    v11[-5] = v14;
    *(__m128 *)((char *)v12 + (_QWORD)starts - 16) = v11[-3];
    --v13;
  }
  while ( v13 );
  v20 = (hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0> *)v7->m_tree;
  v37 = 1;
  *(_QWORD *)stackInstance.m_stack = v7;
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
  v29 = v5->m_quad;
  v30 = v5->m_quad;
  *(__m128 *)&stackInstance.m_stack[12] = _mm_shuffle_ps(v25, v28, 136);
  v31 = _mm_cmpleps(v29, (__m128)0i64);
  v40 = v29;
  v41 = _mm_or_ps(_mm_andnot_ps(v31, (__m128)0i64), _mm_and_ps(v30, v31));
  v42 = _mm_or_ps(_mm_andnot_ps(v31, v29), _mm_and_ps((__m128)0i64, v31));
  hkcdTreeQueries<hkcdTreeQueriesStacks::FixedCpu,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::FixedCpu<64,unsigned int>,RayBundleQuery>(
    v20,
    &tree,
    &stackInstance,
    v12);
  LOBYTE(v9) = _mm_movemask_ps(_mm_cmpltps(*(__m128 *)&stackInstance.m_stack[28], query.m_quad)) == 15;
  return v9;
}

// File Line: 1000
// RVA: 0xB7EB70
void __fastcall SmallRayBundleExtrudedQuery::SmallRayBundleExtrudedQuery(SmallRayBundleExtrudedQuery *this, hkVector4f *starts, hkVector4f *ends, hkVector4f *extrusion)
{
  hkVector4f *v4; // r10
  signed __int64 v5; // r8
  __m128 v6; // xmm0
  __m128i v7; // xmm7
  signed __int64 v8; // r11
  __m128 v9; // xmm6
  hkVector4f *v10; // r9
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
  v4 = extrusion;
  v5 = (char *)ends - (char *)starts;
  v6 = extrusion->m_quad;
  v7 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  this->m_rayStillAlive = 511;
  v8 = 9i64;
  this->m_extrusion.m_quad = v6;
  v9 = (__m128)xmmword_141A712A0;
  v10 = &this->m_rays[0].m_direction;
  v11 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v7, 0), (__m128)xmmword_141A712A0);
  do
  {
    v12 = starts->m_quad;
    v13 = *(__m128 *)((char *)&starts->m_quad + v5);
    v10 += 3;
    ++starts;
    v9 = _mm_min_ps(_mm_min_ps(v9, v12), v13);
    v11 = _mm_max_ps(_mm_max_ps(v11, v12), v13);
    v14 = (__m128i)_mm_sub_ps(v13, v12);
    v15 = _mm_cmpeqps((__m128)0i64, (__m128)v14);
    v16 = _mm_rcp_ps((__m128)v14);
    v10[-3].m_quad = _mm_shuffle_ps((__m128)v14, _mm_unpackhi_ps((__m128)v14, query.m_quad), 196);
    v17 = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v10[-3].m_quad)) & 7 | 0x3F000000;
    v10[-2].m_quad = _mm_or_ps(
                       _mm_and_ps(
                         _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v14, 0x1Fu), 0x1Fu), (__m128)_xmm),
                         v15),
                       _mm_andnot_ps(v15, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, (__m128)v14)), v16)));
    v10[-2].m_quad.m128_i32[3] = v17;
    v10[-4] = (hkVector4f)starts[-1].m_quad;
    --v8;
  }
  while ( v8 );
  v18 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v7, 64), v4->m_quad);
  this->m_rayAabb.m_min.m_quad = _mm_min_ps(v9, _mm_add_ps(v9, v18));
  this->m_rayAabb.m_max.m_quad = _mm_max_ps(v11, _mm_add_ps(v11, v18));
}

// File Line: 1016
// RVA: 0xB7F2A0
__int64 __fastcall SmallRayBundleExtrudedQuery::processLeaf(SmallRayBundleExtrudedQuery *this, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage<256,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRaw<unsigned int> > >::NodeContext *leaf)
{
  hkcdDynamicTree::CodecRaw<unsigned int> *v2; // rax
  SmallRayBundleExtrudedQuery *v3; // rbx
  int v4; // er12
  signed int v5; // ebp
  hkcdRay *ray; // r14
  char v7; // r15
  signed int v8; // edi
  __int64 v9; // rsi
  hkVector4f *v10; // r9
  hkVector4f *v11; // r8
  unsigned int v12; // eax
  signed int v13; // eax
  hkSimdFloat32 hitFractionInOut; // [rsp+40h] [rbp-38h]
  unsigned __int8 v16; // [rsp+80h] [rbp+8h]

  v2 = leaf->m_node;
  v3 = this;
  v4 = v2->m_children[1];
  hkaiEdgeGeometryRaycaster::getFlagsForFace(
    this->m_caster,
    (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> *)&v16,
    v2->m_children[1]);
  v5 = 1;
  ray = v3->m_rays;
  v7 = ~(v16 >> 2) & 1;
  v8 = 0;
  v9 = 0i64;
  do
  {
    if ( v5 & v3->m_rayStillAlive )
    {
      v10 = &v3->m_ends[v9];
      v11 = &v3->m_starts[v9];
      hitFractionInOut.m_real = query.m_quad;
      v12 = v7 ? (unsigned int)hkaiEdgeGeometryRaycaster::raycastAgainstExtrudedFace(
                                 v3->m_caster,
                                 v4,
                                 v11,
                                 v10,
                                 ray,
                                 &v3->m_extrusion,
                                 1,
                                 &hitFractionInOut) : hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                                                        v3->m_caster,
                                                        v4,
                                                        v11,
                                                        v10,
                                                        &hitFractionInOut);
      if ( v12 != 0 )
      {
        if ( v8 > 2 )
        {
          v13 = 448;
          if ( v8 <= 5 )
            v13 = 56;
        }
        else
        {
          v13 = 7;
        }
        v3->m_rayStillAlive &= ~v13;
      }
    }
    ++v8;
    v5 *= 2;
    ++ray;
    ++v9;
  }
  while ( v8 < 9 );
  return v3->m_rayStillAlive;
}

// File Line: 1063
// RVA: 0xB7CA50
__int64 __fastcall hkaiEdgeGeometryRaycaster::castSmallRayBundleExtruded(hkaiEdgeGeometryRaycaster *this, hkVector4f *starts, hkVector4f *ends, hkVector4f *extrusion)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v4; // rdi
  hkaiEdgeGeometryRaycaster *v5; // rbx
  unsigned int v6; // esi
  hkLifoAllocator *v7; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<SmallRayBundleExtrudedQuery> *v8; // r9
  hkcdDynamicTree::CodecRaw<unsigned int> *v9; // rdx
  unsigned __int64 v10; // rcx
  int v11; // eax
  char *v12; // rdi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // er8
  EdgeGeomRaycastAabbTree tree; // [rsp+20h] [rbp-E0h]
  int v18; // [rsp+48h] [rbp-B8h]
  hkVector4f v19; // [rsp+50h] [rbp-B0h]
  hkVector4f v20; // [rsp+60h] [rbp-A0h]
  SmallRayBundleExtrudedQuery v21; // [rsp+70h] [rbp-90h]

  v4 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_tree;
  v5 = this;
  SmallRayBundleExtrudedQuery::SmallRayBundleExtrudedQuery(&v21, starts, ends, extrusion);
  v6 = 0;
  v21.m_caster = v5;
  *(_QWORD *)&tree.m_root = &v21;
  v19.m_quad = (__m128)v21.m_rayAabb.m_min;
  v20.m_quad = (__m128)v21.m_rayAabb.m_max;
  v18 = 1;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_numLeaves = 64;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkcdDynamicTree::CodecRaw<unsigned int> *)v7->m_cur;
  v10 = (unsigned __int64)&v9[5].m_aabb.m_max;
  if ( v7->m_slabSize < 256 || (void *)v10 > v7->m_end )
    v9 = (hkcdDynamicTree::CodecRaw<unsigned int> *)hkLifoAllocator::allocateFromNewSlab(v7, 256);
  else
    v7->m_cur = (void *)v10;
  tree.m_nodes.m_data = v9;
  *(_QWORD *)&tree.m_firstFree = v9;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<EdgeGeomRaycastAabbTree,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<SmallRayBundleExtrudedQuery>>(
    v4,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&tree.m_root,
    v8);
  v11 = tree.m_nodes.m_size;
  v12 = *(char **)&tree.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRaw<unsigned int> **)&tree.m_firstFree == tree.m_nodes.m_data )
    v11 = 0;
  tree.m_nodes.m_size = v11;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      4 * tree.m_nodes.m_capacityAndFlags);
  LOBYTE(v6) = v21.m_rayStillAlive == 0;
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
void __fastcall hkaiEdgeGeometryRaycaster::setHitFilter(hkaiEdgeGeometryRaycaster *this, hkaiEdgeGeometryHitFilter *filter)
{
  hkaiEdgeGeometryHitFilter *v2; // rbx
  hkaiEdgeGeometryRaycaster *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = filter;
  v3 = this;
  if ( filter )
    hkReferencedObject::addReference((hkReferencedObject *)&filter->vfptr);
  v4 = (hkReferencedObject *)&v3->m_hitFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_hitFilter.m_pntr = v2;
}

