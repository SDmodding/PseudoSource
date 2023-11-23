// File Line: 20
// RVA: 0x1327860
bool __fastcall equalVertices(hkVector4f *a, hkVector4f *b, hkSimdFloat32 *tolerance)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm3

  if ( _mm_movemask_ps(_mm_cmpeq_ps(b->m_quad, a->m_quad)) == 15 )
    return 1;
  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_mul_ps(v4, v4);
  return (float)((float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
               + _mm_shuffle_ps(v5, v5, 170).m128_f32[0]) <= (float)(tolerance->m_real.m128_f32[0]
                                                                   * tolerance->m_real.m128_f32[0]);
}

// File Line: 31
// RVA: 0x1326E30
__int64 __fastcall hkTjunctionDetector::vertexCloseToTriangle(
        hkVector4f *vertex,
        hkVector4f *triA,
        hkVector4f *triB,
        hkVector4f *triC,
        float tolerance)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm10
  __m128 v7; // xmm11
  __m128 v8; // xmm14
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  float v14; // xmm13_4
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  float v21; // xmm12_4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  float v26; // xmm4_4
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  float v29; // xmm1_4
  __int64 result; // rax
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  float v34; // xmm7_4
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  float v38; // xmm7_4
  __m128 v39; // xmm7
  __m128 v40; // xmm12
  __m128 v41; // xmm4
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm6
  __m128 v49; // xmm6
  __m128 v50; // xmm8
  __m128 v51; // xmm8
  __m128 v52; // xmm1
  __m128 v53; // xmm5
  __m128 v54; // xmm5
  __m128 v55; // xmm2
  __m128 v56; // [rsp+10h] [rbp-B8h]

  v5 = _mm_sub_ps(triA->m_quad, triC->m_quad);
  v6 = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v7 = _mm_sub_ps(triC->m_quad, triB->m_quad);
  v8 = _mm_sub_ps(triB->m_quad, triA->m_quad);
  v9 = _mm_sub_ps(vertex->m_quad, triA->m_quad);
  v10 = _mm_sub_ps(vertex->m_quad, triB->m_quad);
  v56 = _mm_sub_ps(vertex->m_quad, triC->m_quad);
  v11 = _mm_mul_ps(v9, v9);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_andnot_ps(
          _mm_cmple_ps(v12, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13)),
            v12)).m128_f32[0];
  v15 = _mm_mul_ps(v10, v10);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17));
  v19 = _mm_mul_ps(*(__m128 *)_xmm, v17);
  v20 = _mm_mul_ps(v56, v56);
  LODWORD(v21) = _mm_andnot_ps(_mm_cmple_ps(v16, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v18, v19), v16)).m128_u32[0];
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23));
  v25 = _mm_mul_ps(v8, v8);
  LODWORD(v26) = _mm_andnot_ps(_mm_cmple_ps(v22, (__m128)0i64), _mm_mul_ps(v24, v22)).m128_u32[0];
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_andnot_ps(
          _mm_cmple_ps(v27, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
              _mm_mul_ps(*(__m128 *)_xmm, v28)),
            v27)).m128_f32[0];
  if ( v14 < v29 && v21 < v29 && (float)((float)(v21 + v14) - v29) < v6.m128_f32[0] )
    return 1i64;
  v31 = _mm_mul_ps(v7, v7);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  v34 = _mm_andnot_ps(
          _mm_cmple_ps(v32, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
              _mm_mul_ps(*(__m128 *)_xmm, v33)),
            v32)).m128_f32[0];
  if ( v21 < v34 && v26 < v34 && (float)((float)(v26 + v21) - v34) < v6.m128_f32[0] )
    return 2i64;
  v35 = _mm_mul_ps(v5, v5);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_andnot_ps(
          _mm_cmple_ps(v36, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
              _mm_mul_ps(*(__m128 *)_xmm, v37)),
            v36)).m128_f32[0];
  if ( v26 < v38 && v14 < v38 && (float)((float)(v26 + v14) - v38) < v6.m128_f32[0] )
    return 3i64;
  v39 = _mm_shuffle_ps(v7, v7, 201);
  v40 = _mm_shuffle_ps(v8, v8, 201);
  v41 = _mm_sub_ps(_mm_mul_ps(v39, v8), _mm_mul_ps(v40, v7));
  v42 = _mm_shuffle_ps(v41, v41, 201);
  v43 = _mm_mul_ps(v42, v42);
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v45 = _mm_rsqrt_ps(v44);
  v46 = _mm_mul_ps(
          v42,
          _mm_andnot_ps(
            _mm_cmple_ps(v44, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
              _mm_mul_ps(v45, *(__m128 *)_xmm))));
  v47 = _mm_mul_ps(v46, v9);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v47, v47, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v47, v47, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v47, v47, 170).m128_f32[0])) >> 1) > v6.m128_f32[0] )
    return 0i64;
  result = 0i64;
  v48 = _mm_sub_ps(_mm_mul_ps(v9, v40), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8));
  v49 = _mm_shuffle_ps(v48, v48, 201);
  v50 = _mm_sub_ps(_mm_mul_ps(v10, v39), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v7));
  v51 = _mm_shuffle_ps(v50, v50, 201);
  v52 = _mm_unpacklo_ps(v49, v51);
  v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v56), _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v5));
  v54 = _mm_shuffle_ps(v53, v53, 201);
  v55 = _mm_movelh_ps(v52, v54);
  if ( (_mm_movemask_ps(
          _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(_mm_movehl_ps(v55, v52), v54, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v55)),
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), _mm_shuffle_ps(_mm_unpackhi_ps(v49, v51), v54, 228))),
            v6)) & 7) == 7 )
    return 4i64;
  return result;
}

// File Line: 107
// RVA: 0x13278B0
char __fastcall findTriangle(
        hkpSimpleMeshShape *mesh,
        hkArray<unsigned int,hkContainerHeapAllocator> *triangles,
        int a,
        int b,
        int c)
{
  __int64 m_size; // rbx
  __int64 v6; // r10
  hkpSimpleMeshShape::Triangle *m_data; // rdi
  unsigned int *i; // rdx
  hkpSimpleMeshShape::Triangle *v9; // rax
  int m_a; // ecx
  int m_b; // ecx
  int m_c; // ecx

  m_size = triangles->m_size;
  v6 = 0i64;
  if ( m_size <= 0 )
    return 0;
  m_data = mesh->m_triangles.m_data;
  for ( i = triangles->m_data; ; ++i )
  {
    v9 = &m_data[*i];
    m_a = v9->m_a;
    if ( v9->m_a == a || m_a == b || m_a == c )
    {
      m_b = v9->m_b;
      if ( m_b == a || m_b == b || m_b == c )
      {
        m_c = v9->m_c;
        if ( m_c == a || m_c == b || m_c == c )
          break;
      }
    }
    if ( ++v6 >= m_size )
      return 0;
  }
  return 1;
}

// File Line: 128
// RVA: 0x1327290
void __fastcall hkTjunctionDetector::detect(
        hkpSimpleMeshShape *mesh,
        hkpBvTreeShape *bvTree,
        hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *Tjunctions,
        hkArray<hkVector4f,hkContainerHeapAllocator> *weldedVertices,
        float junctionTolerance,
        float weldTolerance)
{
  __int64 v6; // r12
  int v9; // ebx
  hkpSimpleMeshShape *v10; // rdi
  __int64 v11; // r15
  __m128 v12; // xmm11
  float v13; // xmm12_4
  __m128 v14; // xmm13
  __m128 *p_m_quad; // r14
  __m128 v16; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v18; // xmm0
  char v19; // cl
  hkpSimpleMeshShape::Triangle *v20; // rax
  __int64 m_a; // r12
  __int64 m_b; // r14
  __int64 m_c; // r15
  hkVector4f *m_data; // rax
  hkVector4f *v25; // rdi
  hkVector4f *v26; // r13
  int v27; // eax
  int v28; // edi
  bool Triangle; // al
  int v30; // r9d
  hkVector4f v31; // xmm8
  hkVector4f v32; // xmm6
  hkVector4f v33; // xmm7
  hkVector4f v34; // xmm9
  hkTjunctionDetector::ProximityInfo *v35; // rcx
  _DWORD *v36; // r15
  char v37; // [rsp+30h] [rbp-A8h]
  hkVector4f *a; // [rsp+38h] [rbp-A0h]
  int v39; // [rsp+40h] [rbp-98h]
  unsigned int v40; // [rsp+44h] [rbp-94h]
  __int64 v41; // [rsp+48h] [rbp-90h]
  hkVector4f *triA; // [rsp+50h] [rbp-88h]
  __m256i tolerance; // [rsp+58h] [rbp-80h] BYREF
  __m128 v44; // [rsp+88h] [rbp-50h]
  hkArray<unsigned int,hkContainerHeapAllocator> triangles; // [rsp+C8h] [rbp-10h] BYREF
  char v46; // [rsp+D8h] [rbp+0h] BYREF
  hkpSimpleMeshShape *mesha; // [rsp+398h] [rbp+2C0h]
  hkpBvTreeShape *v48; // [rsp+3A0h] [rbp+2C8h]
  void *array; // [rsp+3B0h] [rbp+2D8h]
  void *retaddr; // [rsp+3B8h] [rbp+2E0h]

  v6 = 0i64;
  v9 = 0;
  v10 = mesh;
  if ( mesh->m_vertices.m_size <= 0 )
    return;
  v11 = 0i64;
  v41 = 0i64;
  v12 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  v13 = *(float *)&mesh;
  v14 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  do
  {
    p_m_quad = (__m128 *)((char *)&v10->m_vertices.m_data->m_quad + v11);
    *(_OWORD *)tolerance.m256i_i8 = xmmword_141A712A0;
    a = (hkVector4f *)p_m_quad;
    *(__m128 *)&tolerance.m256i_u64[2] = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
    *(__m128 *)tolerance.m256i_i8 = _mm_min_ps((__m128)xmmword_141A712A0, *p_m_quad);
    v16 = _mm_max_ps(*(__m128 *)&tolerance.m256i_u64[2], *p_m_quad);
    triangles.m_data = (unsigned int *)&v46;
    vfptr = bvTree->vfptr;
    triangles.m_size = 0;
    *(__m128 *)tolerance.m256i_i8 = _mm_sub_ps(*(__m128 *)tolerance.m256i_i8, v12);
    v18 = _mm_add_ps(v16, v12);
    triangles.m_capacityAndFlags = -2147483520;
    *(__m128 *)&tolerance.m256i_u64[2] = v18;
    ((void (__fastcall *)(hkpBvTreeShape *, __m256i *, hkArray<unsigned int,hkContainerHeapAllocator> *))vfptr[8].__first_virtual_table_function__)(
      bvTree,
      &tolerance,
      &triangles);
    v19 = 0;
    v37 = 0;
    v39 = 0;
    if ( triangles.m_size <= 0 )
      goto LABEL_35;
    tolerance.m256i_i64[0] = 0i64;
    do
    {
      v40 = *(unsigned int *)((char *)triangles.m_data + v6);
      v20 = &v10->m_triangles.m_data[v40];
      m_a = v20->m_a;
      if ( (_DWORD)m_a == v9 )
        goto LABEL_29;
      m_b = v20->m_b;
      if ( (_DWORD)m_b == v9 )
        goto LABEL_28;
      m_c = v20->m_c;
      if ( (_DWORD)m_c == v9 )
        goto LABEL_28;
      m_data = v10->m_vertices.m_data;
      v18.m128_f32[0] = v13;
      v18 = _mm_shuffle_ps(v18, v18, 0);
      *(__m128 *)&tolerance.m256i_u64[1] = v18;
      triA = &m_data[m_a];
      v25 = &m_data[m_c];
      v26 = &m_data[m_b];
      tolerance.m256i_i64[3] = (__int64)v25;
      if ( equalVertices(a, triA, (hkSimdFloat32 *)&tolerance.m256i_u64[1])
        || equalVertices(a, v26, (hkSimdFloat32 *)&tolerance.m256i_u64[1])
        || equalVertices(a, v25, (hkSimdFloat32 *)&tolerance.m256i_u64[1]) )
      {
        v19 = 1;
        v37 = 1;
LABEL_27:
        v10 = mesha;
LABEL_28:
        p_m_quad = &a->m_quad;
        goto LABEL_29;
      }
      v27 = hkTjunctionDetector::vertexCloseToTriangle(a, triA, v26, v25, *(float *)&retaddr);
      v28 = v27;
      if ( !v27 )
        goto LABEL_26;
      if ( v27 == 1 )
      {
        Triangle = findTriangle(mesha, &triangles, v9, m_a, m_b);
      }
      else
      {
        if ( v27 == 2 )
        {
          v30 = m_b;
        }
        else
        {
          if ( v27 != 3 )
            goto LABEL_20;
          v30 = m_a;
        }
        Triangle = findTriangle(mesha, &triangles, v9, v30, m_c);
      }
      if ( Triangle )
      {
LABEL_26:
        v19 = v37;
        goto LABEL_27;
      }
LABEL_20:
      p_m_quad = &a->m_quad;
      v31.m_quad = v26->m_quad;
      v44.m128_u64[0] = __PAIR64__(v40, v9);
      v32.m_quad = a->m_quad;
      v44.m128_i32[2] = v28;
      v33.m_quad = triA->m_quad;
      v34.m_quad = *(__m128 *)tolerance.m256i_i64[3];
      if ( Tjunctions->m_size == (Tjunctions->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&Tjunctions->m_data, 80);
      v35 = &Tjunctions->m_data[Tjunctions->m_size];
      if ( v35 )
      {
        v18 = v44;
        v35->m_vertex = (hkVector4f)v32.m_quad;
        *(__m128 *)&v35->m_index = v18;
        v35->m_v0 = (hkVector4f)v33.m_quad;
        v35->m_v1 = (hkVector4f)v31.m_quad;
        v35->m_v2 = (hkVector4f)v34.m_quad;
      }
      ++Tjunctions->m_size;
      v10 = mesha;
      v19 = v37;
LABEL_29:
      v6 = tolerance.m256i_i64[0] + 4;
      ++v39;
      tolerance.m256i_i64[0] += 4i64;
    }
    while ( v39 < triangles.m_size );
    if ( v19 )
    {
      v36 = array;
      if ( *((_DWORD *)array + 2) == (*((_DWORD *)array + 3) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)array, 16);
      *(__m128 *)(*(_QWORD *)v36 + 16i64 * (int)v36[2]++) = *p_m_quad;
    }
    v11 = v41;
    v6 = 0i64;
LABEL_35:
    triangles.m_size = 0;
    if ( triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        triangles.m_data,
        4 * triangles.m_capacityAndFlags);
    bvTree = v48;
    v11 += 16i64;
    ++v9;
    v41 = v11;
  }
  while ( v9 < v10->m_vertices.m_size );
}

// File Line: 203
// RVA: 0x13276D0
hkpSimpleMeshShape *__fastcall hkTjunctionDetector::createSimpleMeshFromGeometry(hkGeometry *geometry)
{
  _QWORD **Value; // rax
  hkpSimpleMeshShape *v3; // rax
  int v4; // ebp
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 m_size; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  __int128 v11; // xmm0
  int v12; // r14d
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  __int64 v16; // rdx
  int m_a; // eax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpSimpleMeshShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  v4 = 0;
  if ( v3 )
  {
    hkpSimpleMeshShape::hkpSimpleMeshShape(v3, hkConvexShapeDefaultRadius);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( (*(_DWORD *)(v6 + 60) & 0x3FFFFFFF) < geometry->m_vertices.m_size )
  {
    if ( *(int *)(v6 + 60) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v6 + 48),
        16 * *(_DWORD *)(v6 + 60));
    result.m_enum = 16 * geometry->m_vertices.m_size;
    *(_QWORD *)(v6 + 48) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             &hkContainerHeapAllocator::s_alloc,
                             &result);
    *(_DWORD *)(v6 + 60) = result.m_enum / 16;
  }
  m_size = geometry->m_vertices.m_size;
  v8 = *(_QWORD *)(v6 + 48);
  *(_DWORD *)(v6 + 56) = m_size;
  v9 = m_size;
  if ( (int)m_size > 0 )
  {
    v10 = (char *)geometry->m_vertices.m_data - v8;
    do
    {
      v11 = *(_OWORD *)&v10[v8];
      v8 += 16i64;
      *(_OWORD *)(v8 - 16) = v11;
      --v9;
    }
    while ( v9 );
  }
  v12 = geometry->m_triangles.m_size;
  v13 = *(_DWORD *)(v6 + 76) & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    v15 = geometry->m_triangles.m_size;
    if ( v12 < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v6 + 64), v15, 16);
  }
  *(_DWORD *)(v6 + 72) = v12;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      ++v4;
      m_a = geometry->m_triangles.m_data[v16++].m_a;
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 16) = m_a;
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 12) = geometry->m_triangles.m_data[v16 - 1].m_b;
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 8) = geometry->m_triangles.m_data[v16 - 1].m_c;
    }
    while ( v4 < geometry->m_triangles.m_size );
  }
  return (hkpSimpleMeshShape *)v6;
}

// File Line: 219
// RVA: 0x1326CB0
void __fastcall hkTjunctionDetector::detect(
        hkGeometry *geometry,
        hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *Tjunctions,
        hkArray<hkVector4f,hkContainerHeapAllocator> *weldedVertices,
        float tolerance,
        float weldTolerance)
{
  hkpBvTreeShape *v5; // rbp
  int v7; // ebx
  __int64 i; // rdi
  hkVector4f *m_data; // r9
  hkGeometry::Triangle *v12; // rax
  __int64 m_a; // rcx
  __int64 m_b; // rdx
  __int64 m_c; // r8
  hkpSimpleMeshShape *SimpleMeshFromGeometry; // rbx
  hkpShapeContainer *v17; // rcx
  hkpMoppCode *v18; // rdi
  _QWORD **Value; // rax
  hkpMoppBvTreeShape *v20; // rax
  hkpBvTreeShape *v21; // rax
  hkSimdFloat32 tolerancea; // [rsp+30h] [rbp-68h] BYREF
  hkpMoppCompilerInput moppInput; // [rsp+40h] [rbp-58h] BYREF

  v5 = 0i64;
  v7 = 0;
  if ( geometry->m_triangles.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      m_data = geometry->m_vertices.m_data;
      v12 = geometry->m_triangles.m_data;
      m_a = v12[i].m_a;
      m_b = v12[i].m_b;
      m_c = v12[i].m_c;
      tolerancea.m_real = _mm_shuffle_ps(
                            (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                            (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                            0);
      if ( !hkcdTriangleUtil::isDegenerate(&m_data[m_a], &m_data[m_b], &m_data[m_c], &tolerancea) )
        break;
      if ( ++v7 >= geometry->m_triangles.m_size )
        return;
    }
    SimpleMeshFromGeometry = hkTjunctionDetector::createSimpleMeshFromGeometry(geometry);
    hkpMoppCompilerInput::hkpMoppCompilerInput(&moppInput);
    moppInput.m_enableChunkSubdivision.m_bool = 1;
    v17 = &SimpleMeshFromGeometry->hkpShapeContainer;
    if ( !SimpleMeshFromGeometry )
      v17 = 0i64;
    v18 = hkpMoppUtility::buildCode(v17, &moppInput, 0i64);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkpMoppBvTreeShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
    if ( v20 )
    {
      hkpMoppBvTreeShape::hkpMoppBvTreeShape(v20, SimpleMeshFromGeometry, v18);
      v5 = v21;
    }
    hkReferencedObject::removeReference(v18);
    hkReferencedObject::removeReference(SimpleMeshFromGeometry);
    hkTjunctionDetector::detect(SimpleMeshFromGeometry, v5, Tjunctions, weldedVertices, tolerance, weldTolerance);
    hkReferencedObject::removeReference(v5);
  }
}

