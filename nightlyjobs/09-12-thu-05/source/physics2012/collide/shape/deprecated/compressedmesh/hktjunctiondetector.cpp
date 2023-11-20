// File Line: 20
// RVA: 0x1327860
bool __fastcall equalVertices(hkVector4f *a, hkVector4f *b, hkSimdFloat32 *tolerance)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm3

  if ( _mm_movemask_ps(_mm_cmpeqps(b->m_quad, a->m_quad)) == 15 )
    return 1;
  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_mul_ps(v4, v4);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170))) <= (float)(tolerance->m_real.m128_f32[0]
                                                                     * tolerance->m_real.m128_f32[0]);
}

// File Line: 31
// RVA: 0x1326E30
signed __int64 __fastcall hkTjunctionDetector::vertexCloseToTriangle(hkVector4f *vertex, hkVector4f *triA, hkVector4f *triB, hkVector4f *triC, float tolerance)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm10
  __m128 v7; // xmm11
  __m128 v8; // xmm14
  __m128 v9; // xmm4
  __m128 v10; // xmm6
  __m128 v11; // xmm8
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  float v15; // xmm13_4
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  float v22; // xmm12_4
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  float v27; // xmm4_4
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  float v30; // xmm1_4
  signed __int64 result; // rax
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  float v35; // xmm7_4
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  float v39; // xmm7_4
  __m128 v40; // xmm7
  __m128 v41; // xmm12
  __m128 v42; // xmm4
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm6
  __m128 v50; // xmm6
  __m128 v51; // xmm8
  __m128 v52; // xmm8
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm5
  __m128 v56; // xmm2
  __m128 v57; // [rsp+10h] [rbp-B8h]

  v5 = _mm_sub_ps(triA->m_quad, triC->m_quad);
  v6 = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v7 = _mm_sub_ps(triC->m_quad, triB->m_quad);
  v8 = _mm_sub_ps(triB->m_quad, triA->m_quad);
  v9 = _mm_sub_ps(vertex->m_quad, triC->m_quad);
  v10 = _mm_sub_ps(vertex->m_quad, triA->m_quad);
  v11 = _mm_sub_ps(vertex->m_quad, triB->m_quad);
  v57 = v9;
  v12 = _mm_mul_ps(v10, v10);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  LODWORD(v15) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v13, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v14)),
                                        v13));
  v16 = _mm_mul_ps(v11, v11);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18));
  v20 = _mm_mul_ps(*(__m128 *)_xmm, v18);
  v21 = _mm_mul_ps(v9, v9);
  LODWORD(v22) = (unsigned __int128)_mm_andnot_ps(_mm_cmpleps(v17, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v19, v20), v17));
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)), _mm_mul_ps(*(__m128 *)_xmm, v24));
  v26 = _mm_mul_ps(v8, v8);
  LODWORD(v27) = (unsigned __int128)_mm_andnot_ps(_mm_cmpleps(v23, (__m128)0i64), _mm_mul_ps(v25, v23));
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v29 = _mm_rsqrt_ps(v28);
  LODWORD(v30) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v28, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v29)),
                                        v28));
  if ( v15 < v30 && v22 < v30 && (float)((float)(v22 + v15) - v30) < v6.m128_f32[0] )
    return 1i64;
  v32 = _mm_mul_ps(v7, v7);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  LODWORD(v35) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v33, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v34)),
                                        v33));
  if ( v22 < v35 && v27 < v35 && (float)((float)(v27 + v22) - v35) < v6.m128_f32[0] )
    return 2i64;
  v36 = _mm_mul_ps(v5, v5);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  LODWORD(v39) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v37, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v38)),
                                        v37));
  if ( v27 < v39 && v15 < v39 && (float)((float)(v27 + v15) - v39) < v6.m128_f32[0] )
    return 3i64;
  v40 = _mm_shuffle_ps(v7, v7, 201);
  v41 = _mm_shuffle_ps(v8, v8, 201);
  v42 = _mm_sub_ps(_mm_mul_ps(v40, v8), _mm_mul_ps(v41, v7));
  v43 = _mm_shuffle_ps(v42, v42, 201);
  v44 = _mm_mul_ps(v43, v43);
  v45 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)), _mm_shuffle_ps(v44, v44, 170));
  v46 = _mm_rsqrt_ps(v45);
  v47 = _mm_mul_ps(
          v43,
          _mm_andnot_ps(
            _mm_cmpleps(v45, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
              _mm_mul_ps(v46, *(__m128 *)_xmm))));
  v48 = _mm_mul_ps(v47, v10);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 170)))) >> 1) > v6.m128_f32[0] )
    return 0i64;
  result = 0i64;
  v49 = _mm_sub_ps(_mm_mul_ps(v10, v41), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8));
  v50 = _mm_shuffle_ps(v49, v49, 201);
  v51 = _mm_sub_ps(_mm_mul_ps(v11, v40), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v7));
  v52 = _mm_shuffle_ps(v51, v51, 201);
  v53 = _mm_unpacklo_ps(v50, v52);
  v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v57), _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v5));
  v55 = _mm_shuffle_ps(v54, v54, 201);
  v56 = _mm_movelh_ps(v53, v55);
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(_mm_movehl_ps(v56, v53), v55, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v56)),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), _mm_shuffle_ps(_mm_unpackhi_ps(v50, v52), v55, 228))),
            v6)) & 7) == 7 )
    result = 4i64;
  return result;
}

// File Line: 107
// RVA: 0x13278B0
char __fastcall findTriangle(hkpSimpleMeshShape *mesh, hkArray<unsigned int,hkContainerHeapAllocator> *triangles, int a, int b, int c)
{
  __int64 v5; // rbx
  __int64 v6; // r10
  hkpSimpleMeshShape::Triangle *v7; // rdi
  unsigned int *v8; // rdx
  hkpSimpleMeshShape::Triangle *v9; // rax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  v5 = triangles->m_size;
  v6 = 0i64;
  if ( v5 <= 0 )
    return 0;
  v7 = mesh->m_triangles.m_data;
  v8 = triangles->m_data;
  while ( 1 )
  {
    v9 = &v7[*v8];
    v10 = v9->m_a;
    if ( v9->m_a == a || v10 == b || v10 == c )
    {
      v11 = v9->m_b;
      if ( v11 == a || v11 == b || v11 == c )
      {
        v12 = v9->m_c;
        if ( v12 == a || v12 == b || v12 == c )
          break;
      }
    }
    ++v6;
    ++v8;
    if ( v6 >= v5 )
      return 0;
  }
  return 1;
}

// File Line: 128
// RVA: 0x1327290
void __fastcall hkTjunctionDetector::detect(hkpSimpleMeshShape *mesh, hkpBvTreeShape *bvTree, hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *Tjunctions, hkArray<hkVector4f,hkContainerHeapAllocator> *weldedVertices, float junctionTolerance, float weldTolerance)
{
  unsigned __int64 v6; // r12
  hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *v7; // rsi
  hkpBvTreeShape *v8; // r9
  int v9; // ebx
  hkpSimpleMeshShape *v10; // rdi
  __int64 v11; // r15
  __m128 v12; // xmm11
  float v13; // xmm12_4
  __m128 v14; // xmm13
  __m128 *v15; // r14
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  hkBaseObjectVtbl *v18; // rax
  __m128 v19; // xmm0
  char v20; // cl
  hkpSimpleMeshShape::Triangle *v21; // rax
  __int64 v22; // r12
  __int64 v23; // r14
  __int64 v24; // r15
  hkVector4f *v25; // rax
  hkVector4f *v26; // rdi
  hkVector4f *v27; // r13
  int v28; // eax
  int v29; // edi
  bool v30; // al
  int v31; // er9
  hkVector4f v32; // xmm8
  hkVector4f v33; // xmm6
  hkVector4f v34; // xmm7
  __m128 v35; // xmm9
  __m128 *v36; // rcx
  _DWORD *v37; // r15
  char v38; // [rsp+30h] [rbp-A8h]
  hkVector4f *a; // [rsp+38h] [rbp-A0h]
  int v40; // [rsp+40h] [rbp-98h]
  unsigned int v41; // [rsp+44h] [rbp-94h]
  __int64 v42; // [rsp+48h] [rbp-90h]
  hkVector4f *triA; // [rsp+50h] [rbp-88h]
  hkSimdFloat32 tolerance; // [rsp+58h] [rbp-80h]
  __m128 v45; // [rsp+68h] [rbp-70h]
  __m128 v46; // [rsp+88h] [rbp-50h]
  hkArray<unsigned int,hkContainerHeapAllocator> triangles; // [rsp+C8h] [rbp-10h]
  char v48; // [rsp+D8h] [rbp+0h]
  hkpSimpleMeshShape *mesha; // [rsp+398h] [rbp+2C0h]
  hkpBvTreeShape *v50; // [rsp+3A0h] [rbp+2C8h]
  void *array; // [rsp+3B0h] [rbp+2D8h]
  void *retaddr; // [rsp+3B8h] [rbp+2E0h]

  v6 = 0i64;
  v7 = Tjunctions;
  v8 = bvTree;
  v9 = 0;
  v10 = mesh;
  if ( mesh->m_vertices.m_size <= 0 )
    return;
  v11 = 0i64;
  v42 = 0i64;
  v12 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  v13 = *(float *)&mesh;
  v14 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  do
  {
    v15 = (__m128 *)((char *)&v10->m_vertices.m_data->m_quad + v11);
    tolerance.m_real = (__m128)xmmword_141A712A0;
    v16 = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
    a = (hkVector4f *)v15;
    v45 = v16;
    tolerance.m_real = _mm_min_ps((__m128)xmmword_141A712A0, *v15);
    v17 = _mm_max_ps(v16, *v15);
    triangles.m_data = (unsigned int *)&v48;
    v18 = v8->vfptr;
    triangles.m_size = 0;
    tolerance.m_real = _mm_sub_ps(tolerance.m_real, v12);
    v19 = _mm_add_ps(v17, v12);
    triangles.m_capacityAndFlags = -2147483520;
    v45 = v19;
    ((void (__fastcall *)(hkpBvTreeShape *, hkSimdFloat32 *, hkArray<unsigned int,hkContainerHeapAllocator> *))v18[8].__first_virtual_table_function__)(
      v8,
      &tolerance,
      &triangles);
    v20 = 0;
    v38 = 0;
    v40 = 0;
    if ( triangles.m_size <= 0 )
      goto LABEL_35;
    tolerance.m_real.m128_u64[0] = 0i64;
    do
    {
      v41 = *(unsigned int *)((char *)triangles.m_data + v6);
      v21 = &v10->m_triangles.m_data[v41];
      v22 = v21->m_a;
      if ( (_DWORD)v22 == v9 )
        goto LABEL_29;
      v23 = v21->m_b;
      if ( (_DWORD)v23 == v9 )
        goto LABEL_28;
      v24 = v21->m_c;
      if ( (_DWORD)v24 == v9 )
        goto LABEL_28;
      v25 = v10->m_vertices.m_data;
      v19.m128_f32[0] = v13;
      v19 = _mm_shuffle_ps(v19, v19, 0);
      *(hkSimdFloat32 *)((char *)&tolerance + 8) = (hkSimdFloat32)v19;
      triA = &v25[v22];
      v26 = &v25[v24];
      v27 = &v25[v23];
      v45.m128_u64[1] = (unsigned __int64)&v25[v24];
      if ( equalVertices(a, &v25[v22], (hkSimdFloat32 *)((char *)&tolerance + 8))
        || equalVertices(a, v27, (hkSimdFloat32 *)((char *)&tolerance + 8))
        || equalVertices(a, v26, (hkSimdFloat32 *)((char *)&tolerance + 8)) )
      {
        v20 = 1;
        v38 = 1;
LABEL_27:
        v10 = mesha;
LABEL_28:
        v15 = &a->m_quad;
        goto LABEL_29;
      }
      v28 = hkTjunctionDetector::vertexCloseToTriangle(a, triA, v27, v26, *(float *)&retaddr);
      v29 = v28;
      if ( !v28 )
        goto LABEL_26;
      if ( v28 == 1 )
      {
        v30 = findTriangle(mesha, &triangles, v9, v22, v23);
      }
      else
      {
        if ( v28 == 2 )
        {
          v31 = v23;
        }
        else
        {
          if ( v28 != 3 )
            goto LABEL_20;
          v31 = v22;
        }
        v30 = findTriangle(mesha, &triangles, v9, v31, v24);
      }
      if ( v30 )
      {
LABEL_26:
        v20 = v38;
        goto LABEL_27;
      }
LABEL_20:
      v15 = &a->m_quad;
      v32.m_quad = v27->m_quad;
      v46.m128_u64[0] = __PAIR__(v41, v9);
      v33.m_quad = a->m_quad;
      v46.m128_i32[2] = v29;
      v34.m_quad = triA->m_quad;
      v35 = *(__m128 *)v45.m128_u64[1];
      if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 80);
      v36 = &v7->m_data[v7->m_size].m_vertex.m_quad;
      if ( v36 )
      {
        v19 = v46;
        *(hkVector4f *)v36 = (hkVector4f)v33.m_quad;
        v36[1] = v19;
        v36[2] = v34.m_quad;
        v36[3] = v32.m_quad;
        v36[4] = v35;
      }
      ++v7->m_size;
      v10 = mesha;
      v20 = v38;
LABEL_29:
      v6 = tolerance.m_real.m128_u64[0] + 4;
      ++v40;
      tolerance.m_real.m128_u64[0] += 4i64;
    }
    while ( v40 < triangles.m_size );
    if ( v20 )
    {
      v37 = array;
      if ( *((_DWORD *)array + 2) == (*((_DWORD *)array + 3) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, 16);
      *(__m128 *)(*(_QWORD *)v37 + 16i64 * (signed int)v37[2]++) = *v15;
    }
    v11 = v42;
    v6 = 0i64;
LABEL_35:
    triangles.m_size = 0;
    if ( triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        triangles.m_data,
        4 * triangles.m_capacityAndFlags);
    v8 = v50;
    v11 += 16i64;
    ++v9;
    v42 = v11;
  }
  while ( v9 < v10->m_vertices.m_size );
}

// File Line: 203
// RVA: 0x13276D0
hkpSimpleMeshShape *__fastcall hkTjunctionDetector::createSimpleMeshFromGeometry(hkGeometry *geometry)
{
  hkGeometry *v1; // rbx
  _QWORD **v2; // rax
  hkpSimpleMeshShape *v3; // rax
  int v4; // ebp
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  __int128 v11; // xmm0
  int v12; // er14
  int v13; // eax
  int v14; // eax
  int v15; // er9
  __int64 v16; // rdx
  int v17; // eax
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = geometry;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpSimpleMeshShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 104i64);
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
  if ( (*(_DWORD *)(v6 + 60) & 0x3FFFFFFF) < v1->m_vertices.m_size )
  {
    if ( *(_DWORD *)(v6 + 60) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v6 + 48),
        16 * *(_DWORD *)(v6 + 60));
    result.m_enum = 16 * v1->m_vertices.m_size;
    *(_QWORD *)(v6 + 48) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                             (int *)&result);
    *(_DWORD *)(v6 + 60) = result.m_enum / 16;
  }
  v7 = v1->m_vertices.m_size;
  v8 = *(_QWORD *)(v6 + 48);
  *(_DWORD *)(v6 + 56) = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)v1->m_vertices.m_data - v8;
    do
    {
      v11 = *(_OWORD *)&v10[v8];
      v8 += 16i64;
      *(_OWORD *)(v8 - 16) = v11;
      --v9;
    }
    while ( v9 );
  }
  v12 = v1->m_triangles.m_size;
  v13 = *(_DWORD *)(v6 + 76) & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    v15 = v1->m_triangles.m_size;
    if ( v12 < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v6 + 64),
      v15,
      16);
  }
  *(_DWORD *)(v6 + 72) = v12;
  if ( v1->m_triangles.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      ++v4;
      v17 = v1->m_triangles.m_data[v16].m_a;
      ++v16;
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 16) = v17;
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 12) = *((_DWORD *)&v1->m_triangles.m_data[v16] - 3);
      *(_DWORD *)(v16 * 16 + *(_QWORD *)(v6 + 64) - 8) = *((_DWORD *)&v1->m_triangles.m_data[v16] - 2);
    }
    while ( v4 < v1->m_triangles.m_size );
  }
  return (hkpSimpleMeshShape *)v6;
}

// File Line: 219
// RVA: 0x1326CB0
void __fastcall hkTjunctionDetector::detect(hkGeometry *geometry, hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *Tjunctions, hkArray<hkVector4f,hkContainerHeapAllocator> *weldedVertices, float tolerance, float weldTolerance)
{
  hkpBvTreeShape *v5; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // r14
  int v7; // ebx
  hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *v8; // r15
  hkGeometry *v9; // rsi
  __int64 v10; // rdi
  hkVector4f *v11; // r9
  hkGeometry::Triangle *v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // r8
  hkpSimpleMeshShape *v16; // rbx
  hkpShapeContainer *v17; // rcx
  hkpMoppCode *v18; // rdi
  _QWORD **v19; // rax
  hkpMoppBvTreeShape *v20; // rax
  hkpBvTreeShape *v21; // rax
  hkSimdFloat32 tolerancea; // [rsp+30h] [rbp-68h]
  hkpMoppCompilerInput moppInput; // [rsp+40h] [rbp-58h]

  v5 = 0i64;
  v6 = weldedVertices;
  v7 = 0;
  v8 = Tjunctions;
  v9 = geometry;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = v9->m_vertices.m_data;
      v12 = v9->m_triangles.m_data;
      v13 = v12[v10].m_a;
      v14 = v12[v10].m_b;
      v15 = v12[v10].m_c;
      tolerancea.m_real = _mm_shuffle_ps(
                            (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                            (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                            0);
      if ( !(unsigned int)hkcdTriangleUtil::isDegenerate(&v11[v13], &v11[v14], &v11[v15], &tolerancea) )
        break;
      ++v7;
      ++v10;
      if ( v7 >= v9->m_triangles.m_size )
        return;
    }
    v16 = hkTjunctionDetector::createSimpleMeshFromGeometry(v9);
    hkpMoppCompilerInput::hkpMoppCompilerInput(&moppInput);
    moppInput.m_enableChunkSubdivision.m_bool = 1;
    v17 = (hkpShapeContainer *)&v16->vfptr;
    if ( !v16 )
      v17 = 0i64;
    v18 = hkpMoppUtility::buildCode(v17, &moppInput, 0i64);
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkpMoppBvTreeShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 112i64);
    if ( v20 )
    {
      hkpMoppBvTreeShape::hkpMoppBvTreeShape(v20, (hkpShapeCollection *)&v16->vfptr, v18);
      v5 = v21;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v18->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v16->vfptr);
    hkTjunctionDetector::detect(v16, v5, v8, v6, tolerance, weldTolerance);
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
  }
}

