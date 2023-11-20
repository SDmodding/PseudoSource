// File Line: 74
// RVA: 0xB72990
void __fastcall hkaiNavMeshGenerationUtils::ValidationSettings::ValidationSettings(hkaiNavMeshGenerationUtils::ValidationSettings *this)
{
  this->m_maxHorizontalRange = 10000.0;
  this->m_maxVerticalRange = 1000.0;
}

// File Line: 93
// RVA: 0xB78920
void __fastcall hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(hkaiNavMeshGenerationProgressCallbackContext *this, hkaiNavMeshGenerationSettings *settings)
{
  this->m_settings = settings;
  this->m_weldedGeometry = 0i64;
  this->m_walkableTriangles = 0i64;
  this->m_cuttingTriangles = 0i64;
  this->m_unsimplifiedNavMesh = 0i64;
  this->m_simplifiedNavMesh = 0i64;
  this->m_originalMesh = 0i64;
  this->m_simplifiedMesh = 0i64;
  this->m_boundaryFilterNumEdgesInGroup = 0i64;
  this->m_boundaryFilterEdgesToRemove = 0i64;
  this->m_numFacesInPartition = 0i64;
  this->m_partitions = 0i64;
  this->m_segments = 0i64;
  this->m_segmentVertices = 0i64;
}

// File Line: 103
// RVA: 0xB6E1A0
void __fastcall hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(hkaiNavMeshGenerationOutputs *this)
{
  this->m_weldedGeometry = 0i64;
  this->m_walkableTriangles = 0i64;
  this->m_cuttingTriangles = 0i64;
  this->m_unsimplifiedNavMesh = 0i64;
  this->m_navMesh = 0i64;
}

// File Line: 108
// RVA: 0xB78970
void __fastcall quantizeReal(hkVector4f *xInOut, hkSimdFloat32 *gridSize, hkSimdFloat32 *invGridSize)
{
  __m128 v3; // xmm2
  hkVector4f v4; // xmm4
  __m128 v5; // xmm2
  __m128 v6; // xmm4

  v3 = _mm_cmpltps(xInOut->m_quad, (__m128)0i64);
  v4.m_quad = _mm_or_ps(
                _mm_and_ps(_mm_sub_ps(xInOut->m_quad, _mm_mul_ps(gridSize->m_real, (__m128)xmmword_141A711B0)), v3),
                _mm_andnot_ps(v3, xInOut->m_quad));
  *xInOut = (hkVector4f)v4.m_quad;
  v5 = _mm_cvtepi32_ps(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v4.m_quad),
           _mm_cvttps_epi32(v4.m_quad)));
  v6 = _mm_mul_ps(_mm_sub_ps(v4.m_quad, v5), invGridSize->m_real);
  xInOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_xor_si128(
                           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
                           _mm_cvttps_epi32(v6))),
                       gridSize->m_real),
                     v5);
}

// File Line: 136
// RVA: 0xB75850
void __fastcall hkaiNavMeshGenerationUtils::quantize(hkGeometry *geomInOut, float gridSize)
{
  int v2; // edx
  hkGeometry *v3; // r8
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __int64 v6; // rcx
  hkVector4f *v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm4

  v2 = 0;
  v3 = geomInOut;
  v4 = _mm_shuffle_ps((__m128)LODWORD(gridSize), (__m128)LODWORD(gridSize), 0);
  v5 = _mm_div_ps(query.m_quad, v4);
  if ( geomInOut->m_vertices.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v3->m_vertices.m_data;
      ++v2;
      ++v6;
      v8 = _mm_cmpltps(v7[v6 - 1].m_quad, (__m128)0i64);
      v9 = _mm_or_ps(
             _mm_and_ps(_mm_sub_ps(v7[v6 - 1].m_quad, _mm_mul_ps((__m128)xmmword_141A711B0, v4)), v8),
             _mm_andnot_ps(v8, v7[v6 - 1].m_quad));
      v7[v6 - 1] = (hkVector4f)v9;
      v10 = _mm_cvtepi32_ps(
              _mm_xor_si128(
                (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v9),
                _mm_cvttps_epi32(v9)));
      v11 = _mm_mul_ps(_mm_sub_ps(v9, v10), v5);
      v7[v6 - 1].m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_cvtepi32_ps(
                                _mm_xor_si128(
                                  (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v11),
                                  _mm_cvttps_epi32(v11))),
                              v4),
                            v10);
    }
    while ( v2 < v3->m_vertices.m_size );
  }
}

// File Line: 147
// RVA: 0xB789E0
void __fastcall flipGeometryWindingAll(hkGeometry *geomInOut)
{
  int v1; // er8
  hkGeometry *v2; // r10
  __int64 v3; // r9
  hkGeometry::Triangle *v4; // rdx
  int v5; // ecx

  v1 = 0;
  v2 = geomInOut;
  if ( geomInOut->m_triangles.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v1;
      v4 = &v2->m_triangles.m_data[v3];
      ++v3;
      v5 = v4->m_b;
      v4->m_b = v4->m_c;
      v4->m_c = v5;
    }
    while ( v1 < v2->m_triangles.m_size );
  }
}

// File Line: 156
// RVA: 0xB78680
hkResult *__fastcall hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(hkResult *result, hkGeometry *dstGeom, hkGeometry *srcGeom, hkAabb *pruneAabb, hkaiNavMeshGenerationSettings::TriangleWinding inputWinding)
{
  hkAabb *v5; // rsi
  hkGeometry *v6; // rdi
  hkGeometry *v7; // r14
  hkResult *v8; // rbx
  int v9; // er9
  __int64 v10; // rax
  hkGeometry::Triangle *v11; // rcx
  __int64 v12; // rdx
  char *v13; // r8
  int v14; // eax
  int v15; // er9
  __int64 v16; // rax
  hkVector4f *v17; // rcx
  __int64 v18; // rdx
  char *v19; // r8
  hkVector4f v20; // xmm0
  hkResult v22; // [rsp+30h] [rbp-18h]
  hkResult v23; // [rsp+34h] [rbp-14h]
  hkResult resulta; // [rsp+68h] [rbp+20h]

  v5 = pruneAabb;
  v6 = srcGeom;
  v7 = dstGeom;
  v8 = result;
  if ( !(_mm_movemask_ps(_mm_cmpleps(pruneAabb->m_max.m_quad, pruneAabb->m_min.m_quad)) & 7) )
  {
    hkGeometryUtils::getGeometryInsideAabb(&resulta, srcGeom, dstGeom, pruneAabb, 0);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      hkGeometryUtils::getGeometryInsideAabb(&v23, v6, v7, v5, MODE_COPY_DATA);
      if ( v23.m_enum )
      {
        v8->m_enum = 1;
        return v8;
      }
      goto LABEL_30;
    }
    goto LABEL_26;
  }
  v9 = srcGeom->m_triangles.m_size;
  if ( (dstGeom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v9 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &dstGeom->m_triangles,
      v9,
      16);
    if ( resulta.m_enum )
      goto LABEL_26;
  }
  if ( (v7->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_triangles.m_size )
  {
    if ( v7->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v7->m_triangles.m_data,
        16 * v7->m_triangles.m_capacityAndFlags);
    v23.m_enum = 16 * v6->m_triangles.m_size;
    v7->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                       (int *)&v23);
    v7->m_triangles.m_capacityAndFlags = v23.m_enum / 16;
  }
  v10 = v6->m_triangles.m_size;
  v11 = v7->m_triangles.m_data;
  v7->m_triangles.m_size = v10;
  v12 = v10;
  if ( (signed int)v10 > 0 )
  {
    v13 = (char *)((char *)v6->m_triangles.m_data - (char *)v11);
    do
    {
      v14 = *(int *)((char *)&v11->m_a + (_QWORD)v13);
      ++v11;
      v11[-1].m_a = v14;
      v11[-1].m_b = *(_DWORD *)((char *)v11 + (_QWORD)v13 - 12);
      v11[-1].m_c = *(_DWORD *)((char *)v11 + (_QWORD)v13 - 8);
      v11[-1].m_material = *(_DWORD *)((char *)v11 + (_QWORD)v13 - 4);
      --v12;
    }
    while ( v12 );
  }
  if ( resulta.m_enum )
    goto LABEL_26;
  v15 = v6->m_vertices.m_size;
  if ( (v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v15 )
  {
    v22.m_enum = 0;
    goto LABEL_18;
  }
  hkArrayUtil::_reserve(&v22, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_vertices, v15, 16);
  if ( v22.m_enum )
  {
LABEL_26:
    v8->m_enum = 1;
    return v8;
  }
LABEL_18:
  if ( (v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_vertices.m_size )
  {
    if ( v7->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v7->m_vertices.m_data,
        16 * v7->m_vertices.m_capacityAndFlags);
    v23.m_enum = 16 * v6->m_vertices.m_size;
    v7->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            (int *)&v23);
    v7->m_vertices.m_capacityAndFlags = v23.m_enum / 16;
  }
  v16 = v6->m_vertices.m_size;
  v17 = v7->m_vertices.m_data;
  v7->m_vertices.m_size = v16;
  v18 = v16;
  if ( (signed int)v16 > 0 )
  {
    v19 = (char *)((char *)v6->m_vertices.m_data - (char *)v17);
    do
    {
      v20.m_quad = *(__m128 *)((char *)v17 + (_QWORD)v19);
      ++v17;
      v17[-1] = (hkVector4f)v20.m_quad;
      --v18;
    }
    while ( v18 );
  }
  if ( v22.m_enum )
    goto LABEL_26;
LABEL_30:
  if ( inputWinding == 1 )
    flipGeometryWindingAll(v7);
  v8->m_enum = 0;
  return v8;
}

// File Line: 258
// RVA: 0xB729B0
void __fastcall hkaiNavMeshGenerationUtils::validateInputGeometry(hkaiNavMeshGenerationSettings *input, hkaiNavMeshGenerationUtils::ValidationSettings *validationSettings, hkGeometry *geom)
{
  hkGeometry *v3; // rbx

  v3 = geom;
  hkaiNavMeshGenerationUtils::_validateRangeOfInput(
    &geom->m_vertices,
    validationSettings->m_maxHorizontalRange,
    validationSettings->m_maxVerticalRange,
    &input->m_up);
  hkaiNavMeshGenerationUtils::_validateInputGeometryOverlaps(v3);
}

// File Line: 265
// RVA: 0xB750C0
void __fastcall hkaiNavMeshGenerationUtils::_validateRangeOfInput(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, float maxHorizontalRange, float maxVerticalRange, hkVector4f *up)
{
  int v4; // esi
  hkVector4f *v5; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rdi
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __int64 v9; // rbx
  __m128i v10; // xmm4
  __m128 v11; // xmm7
  __m128 v12; // xmm3
  float v13; // xmm8_4
  __m128 v14; // xmm9
  __m128 v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm9
  __m128 v21; // xmm1
  __m128 v22; // xmm7
  hkErrStream v23; // [rsp+20h] [rbp-D8h]
  char buf; // [rsp+40h] [rbp-B8h]
  unsigned int v25; // [rsp+2A0h] [rbp+1A8h]
  float v26; // [rsp+2A8h] [rbp+1B0h]

  v26 = maxHorizontalRange;
  v4 = 0;
  v5 = up;
  v6 = vertices;
  v7 = (__m128)xmmword_141A712A0;
  v8 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( vertices->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      if ( _mm_movemask_ps(_mm_cmpunordps(v6->m_data[v9].m_quad, v6->m_data[v9].m_quad)) & 7 )
      {
        hkErrStream::hkErrStream(&v23, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v23.vfptr,
          "Input vertex data of geometry contains corrupt floating point data.");
        hkError::messageWarning(1666537773, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 272);
        hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
      }
      ++v4;
      ++v9;
      v7 = _mm_min_ps(v7, v6->m_data[v9 - 1].m_quad);
      v8 = _mm_max_ps(v8, v6->m_data[v9 - 1].m_quad);
    }
    while ( v4 < v6->m_size );
  }
  v10 = _mm_load_si128((const __m128i *)v5);
  *(_OWORD *)&v23.vfptr = 0i64;
  v11 = _mm_mul_ps(_mm_sub_ps(v8, v7), (__m128)xmmword_141A711B0);
  v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v10, 1u), 1u);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps((__m128)v25, (__m128)v25, 0);
  *((_DWORD *)&v23.vfptr
  + ((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                            _mm_and_ps(
                                                              _mm_cmpleps(
                                                                _mm_max_ps(
                                                                  _mm_shuffle_ps(v12, v12, 170),
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(v12, v12, 85),
                                                                    _mm_shuffle_ps(v12, v12, 0))),
                                                                v12),
                                                              (__m128)xmmword_141A4D050))]
   + 1)
  % 3) = 1065353216;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v23.vfptr, *(__m128 *)&v23.vfptr, 201), (__m128)v10),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v10, (__m128)v10, 201), *(__m128 *)&v23.vfptr));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(v11, *(__m128 *)&v23.vfptr);
  v20 = _mm_mul_ps(
          v15,
          _mm_andnot_ps(
            _mm_cmpleps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
              _mm_mul_ps(*(__m128 *)_xmm, v18))));
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170)))) >> 1) >= v13 )
  {
    hkErrStream::hkErrStream(&v23, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v23.vfptr,
      "Input vertex data of geometry outside range given by m_maxHorizontalRange.");
    hkError::messageWarning(1658471356, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 290);
    hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
  }
  v21 = _mm_mul_ps(v11, v20);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170)))) >> 1) >= v13 )
  {
    hkErrStream::hkErrStream(&v23, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v23.vfptr,
      "Input vertex data of geometry outside range given by m_maxHorizontalRange.");
    hkError::messageWarning(1658471356, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 292);
    hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
  }
  v22 = _mm_mul_ps(v11, v5->m_quad);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170)))) >> 1) >= COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                (__m128)LODWORD(v26),
                                                                                                (__m128)LODWORD(v26),
                                                                                                0)) )
  {
    hkErrStream::hkErrStream(&v23, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v23.vfptr,
      "Input vertex data of geometry outside range given by m_maxVerticalRange.");
    hkError::messageWarning(1658471356, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 294);
    hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
  }
}

// File Line: 299
// RVA: 0xB75490
void __fastcall hkaiNavMeshGenerationUtils::_validateInputGeometryOverlaps(hkGeometry *geom)
{
  __int64 v1; // r14
  hkGeometry *v2; // rdi
  __int64 v3; // rsi
  int v4; // er9
  int v5; // ebx
  __int64 v6; // r12
  hkGeometry::Triangle *v7; // rcx
  hkVector4f *v8; // rdx
  __m128 v9; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  __m128 v14; // xmm0
  _OWORD *v15; // r15
  __m128 v16; // xmm1
  hk1AxisSweep::AabbInt *v17; // r9
  int v18; // er12
  __int64 v19; // r15
  signed __int64 v20; // r13
  hkResultEnum v21; // eax
  unsigned int v22; // er10
  hk1AxisSweep::AabbInt *v23; // rcx
  signed __int64 v24; // r8
  hk1AxisSweep::AabbInt *v25; // rax
  int v26; // ebx
  hkOstream *v27; // rax
  hkOstream *v28; // rax
  hkOstream *v29; // rax
  hkOstream *v30; // rax
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-B8h]
  int v32; // [rsp+38h] [rbp-B0h]
  int v33; // [rsp+3Ch] [rbp-ACh]
  hkErrStream v34; // [rsp+40h] [rbp-A8h]
  __m128 buf; // [rsp+60h] [rbp-88h]
  __m128 v36; // [rsp+70h] [rbp-78h]
  hkResult result; // [rsp+2D8h] [rbp+1F0h]
  int vars0; // [rsp+2E0h] [rbp+1F8h]

  v1 = geom->m_triangles.m_size;
  v2 = geom;
  if ( (signed int)v1 >= 100000 )
  {
    v3 = 0i64;
    array = 0i64;
    v32 = 0;
    v33 = 2147483648;
    if ( (signed int)v1 + 4 > 0 )
    {
      v4 = v1 + 4;
      if ( (signed int)v1 + 4 < 0 )
        v4 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v4, 32);
    }
    v32 = v1 + 4;
    v5 = 0;
    if ( (signed int)v1 > 0 )
    {
      v6 = v1;
      do
      {
        v7 = v2->m_triangles.m_data;
        v8 = v2->m_vertices.m_data;
        v9 = v8[*(int *)((char *)&v7->m_a + v3)].m_quad;
        v10 = v8[*(int *)((char *)&v7->m_b + v3)].m_quad;
        v11 = v8[*(int *)((char *)&v7->m_c + v3)].m_quad;
        if ( _mm_movemask_ps(_mm_cmpunordps(v9, v9)) & 7
          || _mm_movemask_ps(_mm_cmpunordps(v10, v10)) & 7
          || _mm_movemask_ps(_mm_cmpunordps(v11, v11)) & 7 )
        {
          hkErrStream::hkErrStream(&v34, &buf.m128_u16[4], 512);
          v12 = hkOstream::operator<<((hkOstream *)&v34.vfptr, "Triangle ");
          v13 = hkOstream::operator<<(v12, v5);
          hkOstream::operator<<(v13, " has invalid vertices.");
          hkError::messageWarning(1689537253, &buf.m128_i8[8], "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 319);
          hkOstream::~hkOstream((hkOstream *)&v34.vfptr);
        }
        v36 = _mm_max_ps(_mm_max_ps(v9, v10), v11);
        buf = _mm_min_ps(_mm_min_ps(v9, v10), v11);
        hk1AxisSweep::AabbInt::set(&array[v5], (hkAabb *)&buf, v5);
        ++v5;
        v3 += 16i64;
        --v6;
      }
      while ( v6 );
      LODWORD(v3) = 0;
    }
    v14 = v36;
    buf.m128_i32[0] = -1;
    v15 = array[v1].m_min;
    v16 = buf;
    *v15 = buf;
    v15[1] = v14;
    v15[2] = v16;
    v15[3] = v14;
    v15[4] = v16;
    v15[5] = v14;
    v15[6] = v16;
    v15[7] = v14;
    hk1AxisSweep::sortAabbs(array, v1);
    v17 = array;
    vars0 = v1 - 1;
    v18 = 0;
    v19 = 0i64;
    v20 = 1i64;
    do
    {
      v21 = *(_DWORD *)v17[v19].m_expansionMin;
      v22 = v17[v19].m_max[0];
      v23 = &v17[v19];
      ++v19;
      result.m_enum = v21;
      v24 = v20;
      v25 = &v17[v19];
      v26 = v3;
      if ( v17[v19].m_min[0] <= v22 )
      {
        do
        {
          if ( (((v25->m_max[2] - v23->m_min[2]) | (v25->m_max[1] - v23->m_min[1]) | (v23->m_max[2] - v25->m_min[2]) | (v23->m_max[1] - v25->m_min[1])) & 0x80000000) == 0 )
            ++v26;
          v25 = &v17[++v24];
        }
        while ( v25->m_min[0] <= v22 );
        if ( v26 >= 100000 )
        {
          hkErrStream::hkErrStream(&v34, &buf.m128_u16[4], 512);
          v27 = hkOstream::operator<<((hkOstream *)&v34.vfptr, "Lots of overlaps (");
          v28 = hkOstream::operator<<(v27, v26);
          v29 = hkOstream::operator<<(v28, ") for triangle ");
          v30 = hkOstream::operator<<(v29, result.m_enum);
          hkOstream::operator<<(v30, ". If you see this warning a lot, it may indicate corrupt input geometry");
          hkError::messageWarning(1392258972, &buf.m128_i8[8], "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 354);
          hkOstream::~hkOstream((hkOstream *)&v34.vfptr);
          v17 = array;
        }
        LODWORD(v3) = 0;
      }
      ++v18;
      ++v20;
    }
    while ( v18 < vars0 );
    v32 = v3;
    if ( v33 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v17,
        32 * v33);
  }
}

// File Line: 367
// RVA: 0xB6E1C0
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMesh(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMesh *navMeshOut, hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  hkaiNavMeshGenerationSettings *v4; // rbp
  hkaiNavMeshGenerationProgressCallback *v5; // rdi
  hkaiNavMesh *v6; // rbx
  hkGeometry *v7; // rsi
  hkaiNavMeshGenerationOutputs outputs; // [rsp+30h] [rbp-38h]

  v4 = input;
  v5 = _callbacks;
  v6 = navMeshOut;
  v7 = triMeshIn;
  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = v6;
  return hkaiNavMeshGenerationUtils::_generateNavMesh(v4, v7, &outputs, v5, 0i64);
}

// File Line: 374
// RVA: 0xB6E230
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMesh(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMeshGenerationOutputs *outputs, hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  return hkaiNavMeshGenerationUtils::_generateNavMesh(input, triMeshIn, outputs, _callbacks, 0i64);
}

// File Line: 394
// RVA: 0xB6E250
__int64 __fastcall hkaiNavMeshGenerationUtils::_generateNavMesh(hkaiNavMeshGenerationSettings *input, hkGeometry *_triMeshIn, hkaiNavMeshGenerationOutputs *outputs, hkaiNavMeshGenerationProgressCallback *_callbacks, hkaiEdgeGeometryRaycaster *edgeConnectionRayCaster)
{
  hkaiNavMeshGenerationSettings *v5; // r15
  hkaiNavMeshGenerationProgressCallback *v6; // rdi
  hkaiNavMeshGenerationOutputs *v7; // r13
  hkGeometry *v8; // rsi
  _QWORD *v9; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  hkVector4f *v14; // rax
  unsigned int v15; // er14
  hkVector4f *v16; // rax
  _QWORD **v17; // rax
  hkaiNavMesh *v18; // rax
  hkReferencedObject *v19; // rax
  hkaiNavMesh *v20; // r14
  _QWORD **v21; // rax
  hkaiNavMesh *v22; // rax
  hkaiNavMesh *v23; // rax
  bool v24; // zf
  int v25; // ecx
  hkaiNavMesh *v26; // rbx
  hkBitField *cb; // r12
  __int64 v28; // rdi
  int v29; // eax
  int v30; // er8
  int v31; // ebx
  int v32; // er9
  hkVector4f *v33; // rax
  __int64 i; // rbx
  int v35; // ebx
  int v36; // eax
  int v37; // er9
  hkErrStream *v38; // rcx
  int v39; // edx
  hkResultEnum v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // er9
  hkRefPtr<hkaiVolume const > *v44; // rdi
  __int64 v45; // rbx
  hkReferencedObject *v46; // rcx
  hkBitField *v47; // rcx
  hkRefPtr<hkaiVolume const > *v48; // rdi
  __int64 v49; // rbx
  hkRefPtr<hkaiVolume const > *v50; // r12
  __int64 v51; // r13
  hkReferencedObject *v52; // rcx
  hkReferencedObject *v53; // rcx
  hkaiVolume *v54; // rax
  hkReferencedObject **v55; // rbx
  hkRefPtr<hkaiVolume const > *v56; // rcx
  hkBitField *v57; // rdx
  hkReferencedObject *v58; // rcx
  hkReferencedObject **v59; // rdi
  hkAabb *v60; // rbx
  _QWORD **v61; // rax
  hkaiInvertedAabbVolume *v62; // rax
  hkaiVolume *v63; // rax
  hkaiVolume *v64; // rdi
  int v65; // ecx
  hkRefPtr<hkaiVolume const > *v66; // rbx
  hkRefPtr<hkaiVolume const > *v67; // rdx
  hkBitField *v68; // rax
  hkReferencedObject *v69; // rcx
  _QWORD **v70; // rax
  hkaiCarverTree *v71; // rax
  hkaiCarverTree *v72; // rax
  _QWORD **v73; // rax
  __int64 v74; // rax
  hkGeometry *v75; // r8
  hkGeometry *v76; // rdi
  hkReferencedObject *v77; // rbx
  _QWORD *v78; // r8
  _QWORD *v79; // rcx
  unsigned __int64 v80; // rax
  signed __int64 v81; // rcx
  float v82; // xmm1_4
  int v83; // ebx
  int v84; // ecx
  int v85; // eax
  int v86; // er9
  hkErrStream *v87; // rcx
  int v88; // eax
  int v89; // eax
  int v90; // er9
  int v91; // ebx
  int v92; // er9
  int v93; // er9
  int v94; // er9
  hkVector4f *v95; // rax
  int v96; // er9
  hkErrStream *v97; // rcx
  hkVector4f *v98; // rax
  hkVector4f *v99; // rax
  _QWORD *v100; // r8
  _QWORD *v101; // rcx
  unsigned __int64 v102; // rax
  signed __int64 v103; // rcx
  _QWORD *v104; // r8
  _QWORD *v105; // rcx
  unsigned __int64 v106; // rax
  signed __int64 v107; // rcx
  int v108; // er9
  hkBitField *v109; // rbx
  hkBitField *v110; // rax
  hkBitField *v111; // rcx
  hkErrStream *v112; // rcx
  hkVector4f *v113; // rax
  int v114; // ebx
  hkBitField *v115; // r13
  hkcdDynamicAabbTree *v116; // rbx
  _QWORD *v117; // r8
  _QWORD *v118; // rcx
  unsigned __int64 v119; // rax
  signed __int64 v120; // rcx
  _QWORD **v121; // rax
  hkcdDynamicAabbTree *v122; // rax
  hkcdDynamicAabbTree *v123; // rax
  hkErrStream *v124; // rcx
  hkVector4f *v125; // rax
  _QWORD *v126; // r8
  _QWORD *v127; // rcx
  unsigned __int64 v128; // rax
  signed __int64 v129; // rcx
  _QWORD *v130; // r8
  _QWORD *v131; // rcx
  unsigned __int64 v132; // rax
  signed __int64 v133; // rcx
  int v134; // eax
  int v135; // er9
  hkErrStream *v136; // rcx
  int v137; // er9
  int v138; // ecx
  hkVector4f *v139; // rax
  hkVector4f *v140; // rax
  __m128 v141; // xmm6
  _QWORD *v142; // r8
  unsigned __int64 v143; // rcx
  unsigned __int64 v144; // rax
  _QWORD *v145; // r8
  _QWORD *v146; // rcx
  unsigned __int64 v147; // rax
  signed __int64 v148; // rcx
  hkVector4f *v149; // rax
  _QWORD *v150; // r8
  _QWORD *v151; // rcx
  unsigned __int64 v152; // rax
  signed __int64 v153; // rcx
  _QWORD *v154; // r8
  unsigned __int64 v155; // rcx
  unsigned __int64 v156; // rax
  __m128 v157; // xmm2
  __m128 v158; // xmm1
  __m128 v159; // xmm4
  __m128 v160; // xmm4
  __m128 v161; // xmm1
  __m128 v162; // xmm2
  __m128 v163; // xmm3
  __m128 v164; // xmm5
  int v165; // ecx
  __m128 v166; // xmm3
  __m128 v167; // xmm1
  __m128 v168; // xmm2
  _QWORD *v169; // r8
  _QWORD *v170; // rcx
  unsigned __int64 v171; // rax
  signed __int64 v172; // rcx
  _QWORD *v173; // r8
  _QWORD *v174; // rcx
  unsigned __int64 v175; // rax
  signed __int64 v176; // rcx
  _QWORD *v177; // r8
  _QWORD *v178; // rcx
  unsigned __int64 v179; // rax
  signed __int64 v180; // rcx
  _QWORD *v181; // r8
  _QWORD *v182; // rcx
  unsigned __int64 v183; // rax
  signed __int64 v184; // rcx
  _QWORD *v185; // r8
  _QWORD *v186; // rcx
  unsigned __int64 v187; // rax
  signed __int64 v188; // rcx
  _QWORD *v189; // r8
  _QWORD *v190; // rcx
  unsigned __int64 v191; // rax
  signed __int64 v192; // rcx
  _QWORD *v193; // r8
  _QWORD *v194; // rcx
  unsigned __int64 v195; // rax
  signed __int64 v196; // rcx
  _QWORD *v197; // r8
  _QWORD *v198; // rcx
  unsigned __int64 v199; // rax
  signed __int64 v200; // rcx
  int v201; // edx
  int v202; // er8
  __int64 v203; // rcx
  int v204; // edx
  int v205; // eax
  int v206; // er8
  __int64 v207; // rax
  _QWORD *v208; // r8
  _QWORD *v209; // rcx
  unsigned __int64 v210; // rax
  signed __int64 v211; // rcx
  hkErrStream *v212; // rcx
  hkVector4f *v213; // rax
  hkErrStream *v214; // rcx
  hkVector4f *v215; // rax
  _QWORD *v216; // r8
  _QWORD *v217; // rcx
  unsigned __int64 v218; // rax
  signed __int64 v219; // rcx
  hkVector4f *v220; // rax
  _QWORD *v221; // r8
  _QWORD *v222; // rcx
  unsigned __int64 v223; // rax
  signed __int64 v224; // rcx
  _QWORD *v225; // r8
  _QWORD *v226; // rcx
  unsigned __int64 v227; // rax
  signed __int64 v228; // rcx
  hkVector4f *v229; // rax
  _QWORD *v230; // r8
  _QWORD *v231; // rcx
  unsigned __int64 v232; // rax
  signed __int64 v233; // rcx
  __int64 v234; // r9
  __int64 v235; // r8
  __int64 v236; // rcx
  _QWORD *v237; // r8
  _QWORD *v238; // rcx
  unsigned __int64 v239; // rax
  signed __int64 v240; // rcx
  _QWORD **v241; // rax
  hkaiEdgeGeometryRaycaster *v242; // rax
  __int64 v243; // rax
  _QWORD *v244; // r8
  _QWORD *v245; // rcx
  unsigned __int64 v246; // rax
  signed __int64 v247; // rcx
  hkErrStream *v248; // rcx
  hkVector4f *v249; // rax
  _QWORD *v250; // r8
  _QWORD *v251; // rcx
  unsigned __int64 v252; // rax
  signed __int64 v253; // rcx
  _QWORD *v254; // r8
  _QWORD *v255; // rcx
  unsigned __int64 v256; // rax
  signed __int64 v257; // rcx
  _QWORD *v258; // r8
  _QWORD *v259; // rcx
  unsigned __int64 v260; // rax
  signed __int64 v261; // rcx
  _QWORD *v262; // r8
  _QWORD *v263; // rcx
  unsigned __int64 v264; // rax
  signed __int64 v265; // rcx
  _QWORD *v266; // r8
  _QWORD *v267; // rcx
  unsigned __int64 v268; // rax
  signed __int64 v269; // rcx
  hkErrStream *v270; // rcx
  hkaiNavMesh *v271; // rdi
  hkaiNavMesh *v272; // rax
  _QWORD *v273; // r8
  _QWORD *v274; // rcx
  unsigned __int64 v275; // rax
  signed __int64 v276; // rcx
  int v277; // edi
  _QWORD *v278; // r8
  _QWORD *v279; // rcx
  unsigned __int64 v280; // rax
  signed __int64 v281; // rcx
  _QWORD *v282; // r8
  _QWORD *v283; // rcx
  unsigned __int64 v284; // rax
  signed __int64 v285; // rcx
  hkaiNavMesh *v286; // rdi
  hkErrStream *v287; // rcx
  hkErrStream *v288; // rcx
  hkVector4f *v289; // rax
  __m128 v290; // xmm2
  hkaiNavMesh *v291; // r14
  hkaiNavMesh *v292; // rcx
  _QWORD *v293; // r8
  _QWORD *v294; // rcx
  unsigned __int64 v295; // rax
  signed __int64 v296; // rcx
  int v297; // edi
  _QWORD *v298; // r8
  _QWORD *v299; // rcx
  unsigned __int64 v300; // rax
  signed __int64 v301; // rcx
  hkVector4f *v302; // rax
  _QWORD *v303; // r8
  _QWORD *v304; // rcx
  unsigned __int64 v305; // rax
  signed __int64 v306; // rcx
  hkVector4f *v307; // rax
  hkVector4f *v308; // rax
  hkVector4f *v309; // rax
  int v310; // ebx
  hkRefPtr<hkaiVolume const > *v311; // rdi
  hkVector4f *v312; // rax
  hkVector4f *v313; // rax
  _QWORD *v314; // rax
  _QWORD *v315; // rcx
  _QWORD *v316; // r8
  unsigned __int64 v317; // rax
  signed __int64 v318; // rcx
  int sizeElem; // [rsp+20h] [rbp-E0h]
  int sizeElema; // [rsp+20h] [rbp-E0h]
  int sizeElemb; // [rsp+20h] [rbp-E0h]
  int sizeElemc; // [rsp+20h] [rbp-E0h]
  hkArrayBase<hkRefPtr<hkaiVolume const > > carvers; // [rsp+80h] [rbp-80h]
  hkArrayBase<int> originalFaceIndices; // [rsp+90h] [rbp-70h]
  hkBitField *walkableInOut; // [rsp+A0h] [rbp-60h]
  int v327; // [rsp+A8h] [rbp-58h]
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+B0h] [rbp-50h]
  hkArrayBase<unsigned int> v329; // [rsp+C0h] [rbp-40h]
  hkResult v330[2]; // [rsp+D0h] [rbp-30h]
  hkResult v331; // [rsp+D8h] [rbp-28h]
  hkArrayBase<hkVector4f> triangleVertices; // [rsp+E0h] [rbp-20h]
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+F0h] [rbp-10h]
  hkArray<int,hkContainerHeapAllocator> hitFaces; // [rsp+100h] [rbp+0h]
  hkReferencedObject *v335; // [rsp+110h] [rbp+10h]
  hkArrayBase<unsigned int> v336; // [rsp+118h] [rbp+18h]
  hkArrayBase<unsigned int> v337; // [rsp+128h] [rbp+28h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+138h] [rbp+38h]
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+148h] [rbp+48h]
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+158h] [rbp+58h]
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+168h] [rbp+68h]
  int v342; // [rsp+178h] [rbp+78h]
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+180h] [rbp+80h]
  hkaiNavMesh *navMeshOut; // [rsp+190h] [rbp+90h]
  char v345; // [rsp+198h] [rbp+98h]
  hkArray<int,hkContainerHeapAllocator> remap; // [rsp+1A0h] [rbp+A0h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+1B0h] [rbp+B0h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+1C0h] [rbp+C0h]
  hkBitField *cuttingTriangles; // [rsp+1D0h] [rbp+D0h]
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+1D8h] [rbp+D8h]
  char v351; // [rsp+1E8h] [rbp+E8h]
  void *array; // [rsp+1F0h] [rbp+F0h]
  int v353; // [rsp+1F8h] [rbp+F8h]
  int v354; // [rsp+1FCh] [rbp+FCh]
  hkResult v355; // [rsp+200h] [rbp+100h]
  hkResult v356; // [rsp+204h] [rbp+104h]
  hkResult v357; // [rsp+208h] [rbp+108h]
  hkaiCarverTree *carverTree; // [rsp+210h] [rbp+110h]
  hkResult v359; // [rsp+218h] [rbp+118h]
  hkResult v360; // [rsp+21Ch] [rbp+11Ch]
  hkResult v361; // [rsp+220h] [rbp+120h]
  hkResult v362; // [rsp+224h] [rbp+124h]
  hkResult v363; // [rsp+228h] [rbp+128h]
  hkResult v364; // [rsp+22Ch] [rbp+12Ch]
  hkResult v365; // [rsp+230h] [rbp+130h]
  hkResult v366; // [rsp+234h] [rbp+134h]
  hkResult v367; // [rsp+238h] [rbp+138h]
  hkResult v368; // [rsp+23Ch] [rbp+13Ch]
  hkResult v369; // [rsp+240h] [rbp+140h]
  hkResult v370; // [rsp+244h] [rbp+144h]
  hkResult v371; // [rsp+248h] [rbp+148h]
  hkResult v372; // [rsp+24Ch] [rbp+14Ch]
  hkResult v373; // [rsp+250h] [rbp+150h]
  hkResult v374; // [rsp+254h] [rbp+154h]
  hkResult v375; // [rsp+258h] [rbp+158h]
  hkaiNavMesh *mesh; // [rsp+260h] [rbp+160h]
  int v377; // [rsp+268h] [rbp+168h]
  hkResult v378; // [rsp+26Ch] [rbp+16Ch]
  int v379; // [rsp+270h] [rbp+170h]
  hkResult v380; // [rsp+274h] [rbp+174h]
  hkResult v381; // [rsp+278h] [rbp+178h]
  hkResult v382; // [rsp+27Ch] [rbp+17Ch]
  hkResult v383; // [rsp+280h] [rbp+180h]
  hkResult v384; // [rsp+284h] [rbp+184h]
  int v385; // [rsp+288h] [rbp+188h]
  int newStride; // [rsp+28Ch] [rbp+18Ch]
  int v387; // [rsp+290h] [rbp+190h]
  hkResult v388; // [rsp+294h] [rbp+194h]
  int v389; // [rsp+298h] [rbp+198h]
  hkResult v390; // [rsp+29Ch] [rbp+19Ch]
  void **v391; // [rsp+2A0h] [rbp+1A0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v392; // [rsp+2A8h] [rbp+1A8h]
  hkGeometry cuttingGeom; // [rsp+2B8h] [rbp+1B8h]
  hkaiFaceEdges faceEdges; // [rsp+2E8h] [rbp+1E8h]
  hkaiNavMeshGenerationProgressCallbackContext cbCtx; // [rsp+310h] [rbp+210h]
  hkResult v396; // [rsp+380h] [rbp+280h]
  hkResult v397; // [rsp+384h] [rbp+284h]
  hkReferencedObject *v398; // [rsp+388h] [rbp+288h]
  hkResult v399; // [rsp+390h] [rbp+290h]
  hkReferencedObject *v400; // [rsp+398h] [rbp+298h]
  hkaMatrix<float> v401; // [rsp+3A0h] [rbp+2A0h]
  hkResult result; // [rsp+3B8h] [rbp+2B8h]
  hkaMatrix<float> v403; // [rsp+3C0h] [rbp+2C0h]
  hkVector4f vertsOut; // [rsp+3E0h] [rbp+2E0h]
  __m128 v405; // [rsp+3F0h] [rbp+2F0h]
  __m128 v406; // [rsp+400h] [rbp+300h]
  hkVector4f extrudeDirection; // [rsp+410h] [rbp+310h]
  hkAabb extrudedTriAabb; // [rsp+420h] [rbp+320h]
  hkaiEdgeGeometry geom; // [rsp+440h] [rbp+340h]
  hkErrStream v410; // [rsp+490h] [rbp+390h]
  hkErrStream v411; // [rsp+4A8h] [rbp+3A8h]
  hkErrStream v412; // [rsp+4C0h] [rbp+3C0h]
  hkErrStream v413; // [rsp+4D8h] [rbp+3D8h]
  hkErrStream v414; // [rsp+4F0h] [rbp+3F0h]
  hkErrStream v415; // [rsp+508h] [rbp+408h]
  hkErrStream v416; // [rsp+520h] [rbp+420h]
  hkErrStream v417; // [rsp+538h] [rbp+438h]
  hkErrStream v418; // [rsp+550h] [rbp+450h]
  hkErrStream v419; // [rsp+568h] [rbp+468h]
  hkErrStream v420; // [rsp+580h] [rbp+480h]
  hkErrStream v421; // [rsp+598h] [rbp+498h]
  hkErrStream v422; // [rsp+5B0h] [rbp+4B0h]
  hkErrStream v423; // [rsp+5C8h] [rbp+4C8h]
  hkErrStream v424; // [rsp+5E0h] [rbp+4E0h]
  hkErrStream v425; // [rsp+5F8h] [rbp+4F8h]
  hkErrStream v426; // [rsp+610h] [rbp+510h]
  hkErrStream v427; // [rsp+628h] [rbp+528h]
  hkErrStream v428; // [rsp+640h] [rbp+540h]
  hkErrStream v429; // [rsp+658h] [rbp+558h]
  hkErrStream v430; // [rsp+670h] [rbp+570h]
  hkErrStream v431; // [rsp+688h] [rbp+588h]
  hkErrStream v432; // [rsp+6A0h] [rbp+5A0h]
  hkErrStream v433; // [rsp+6B8h] [rbp+5B8h]
  hkErrStream v434; // [rsp+6D0h] [rbp+5D0h]
  hkVector4f rayDir; // [rsp+6F0h] [rbp+5F0h]
  hkErrStream v436; // [rsp+700h] [rbp+600h]
  hkErrStream v437; // [rsp+718h] [rbp+618h]
  hkErrStream v438; // [rsp+730h] [rbp+630h]
  hkErrStream v439; // [rsp+748h] [rbp+648h]
  hkErrStream v440; // [rsp+760h] [rbp+660h]
  hkErrStream v441; // [rsp+778h] [rbp+678h]
  hkErrStream v442; // [rsp+790h] [rbp+690h]
  hkErrStream v443; // [rsp+7A8h] [rbp+6A8h]
  hkErrStream v444; // [rsp+7C0h] [rbp+6C0h]
  hkErrStream v445; // [rsp+7D8h] [rbp+6D8h]
  hkErrStream v446; // [rsp+7F0h] [rbp+6F0h]
  hkErrStream v447; // [rsp+808h] [rbp+708h]
  hkErrStream v448; // [rsp+820h] [rbp+720h]
  hkErrStream v449; // [rsp+838h] [rbp+738h]
  hkErrStream v450; // [rsp+850h] [rbp+750h]
  hkErrStream v451; // [rsp+868h] [rbp+768h]
  hkErrStream v452; // [rsp+880h] [rbp+780h]
  hkErrStream v453; // [rsp+898h] [rbp+798h]
  hkErrStream v454; // [rsp+8B0h] [rbp+7B0h]
  hkErrStream v455; // [rsp+8C8h] [rbp+7C8h]
  hkErrStream v456; // [rsp+8E0h] [rbp+7E0h]
  hkErrStream v457; // [rsp+8F8h] [rbp+7F8h]
  hkErrStream v458; // [rsp+910h] [rbp+810h]
  hkErrStream v459; // [rsp+928h] [rbp+828h]
  hkSimdFloat32 characterHeight; // [rsp+940h] [rbp+840h]
  hkErrStream v461; // [rsp+950h] [rbp+850h]
  hkErrStream v462; // [rsp+968h] [rbp+868h]
  hkErrStream v463; // [rsp+980h] [rbp+880h]
  hkErrStream v464; // [rsp+998h] [rbp+898h]
  hkErrStream v465; // [rsp+9B0h] [rbp+8B0h]
  hkErrStream v466; // [rsp+9C8h] [rbp+8C8h]
  hkErrStream v467; // [rsp+9E0h] [rbp+8E0h]
  hkaiEdgeGeometry geomA; // [rsp+A00h] [rbp+900h]
  hkErrStream v469; // [rsp+A50h] [rbp+950h]
  hkErrStream v470; // [rsp+A68h] [rbp+968h]
  hkErrStream v471; // [rsp+A80h] [rbp+980h]
  hkErrStream v472; // [rsp+A98h] [rbp+998h]
  hkaiEdgeGeometry geomOut; // [rsp+AB0h] [rbp+9B0h]
  hkaiEdgeGeometry cuttingEdgeGeometryOut; // [rsp+B00h] [rbp+A00h]
  hkaiSelfIntersectBooleanFilter2 v475; // [rsp+B50h] [rbp+A50h]
  __m128 v476; // [rsp+BB0h] [rbp+AB0h]
  hkaiGeometryExtrudeUtil v477; // [rsp+BC0h] [rbp+AC0h]
  hkaiBooleanOperation v478; // [rsp+C80h] [rbp+B80h]
  hkaiNavMeshSimplificationSnapshot v479; // [rsp+DF0h] [rbp+CF0h]
  char v480; // [rsp+1020h] [rbp+F20h]
  char v481; // [rsp+1220h] [rbp+1120h]
  char v482; // [rsp+1420h] [rbp+1320h]
  char v483; // [rsp+1620h] [rbp+1520h]
  char v484; // [rsp+1820h] [rbp+1720h]
  char v485; // [rsp+1A20h] [rbp+1920h]
  char v486; // [rsp+1C20h] [rbp+1B20h]
  char v487; // [rsp+1E20h] [rbp+1D20h]
  char v488; // [rsp+2020h] [rbp+1F20h]
  char v489; // [rsp+2220h] [rbp+2120h]
  char v490; // [rsp+2420h] [rbp+2320h]
  char v491; // [rsp+2620h] [rbp+2520h]
  char v492; // [rsp+2820h] [rbp+2720h]
  char v493; // [rsp+2A20h] [rbp+2920h]
  char v494; // [rsp+2C20h] [rbp+2B20h]
  char v495; // [rsp+2E20h] [rbp+2D20h]
  char v496; // [rsp+3020h] [rbp+2F20h]
  char v497; // [rsp+3220h] [rbp+3120h]
  char v498; // [rsp+3420h] [rbp+3320h]
  char v499; // [rsp+3620h] [rbp+3520h]
  char v500; // [rsp+3820h] [rbp+3720h]
  char v501; // [rsp+3A20h] [rbp+3920h]
  char v502; // [rsp+3C20h] [rbp+3B20h]
  char v503; // [rsp+3E20h] [rbp+3D20h]
  char v504; // [rsp+4020h] [rbp+3F20h]
  char v505; // [rsp+4220h] [rbp+4120h]
  char v506; // [rsp+4420h] [rbp+4320h]
  char v507; // [rsp+4620h] [rbp+4520h]
  char buf; // [rsp+4820h] [rbp+4720h]
  char v509; // [rsp+4A20h] [rbp+4920h]
  char v510; // [rsp+4C20h] [rbp+4B20h]
  char v511; // [rsp+4E20h] [rbp+4D20h]
  char v512; // [rsp+5020h] [rbp+4F20h]
  char v513; // [rsp+5220h] [rbp+5120h]
  char v514; // [rsp+5420h] [rbp+5320h]
  char v515; // [rsp+5620h] [rbp+5520h]
  char v516; // [rsp+5820h] [rbp+5720h]
  char v517; // [rsp+5A20h] [rbp+5920h]
  char v518; // [rsp+5C20h] [rbp+5B20h]
  char v519; // [rsp+5E20h] [rbp+5D20h]
  char v520; // [rsp+6020h] [rbp+5F20h]
  char v521; // [rsp+6220h] [rbp+6120h]
  char v522; // [rsp+6420h] [rbp+6320h]
  char v523; // [rsp+6620h] [rbp+6520h]
  char v524; // [rsp+6820h] [rbp+6720h]
  char v525; // [rsp+6A20h] [rbp+6920h]
  char v526; // [rsp+6C20h] [rbp+6B20h]
  char v527; // [rsp+6E20h] [rbp+6D20h]
  char v528; // [rsp+7020h] [rbp+6F20h]
  char v529; // [rsp+7220h] [rbp+7120h]
  char v530; // [rsp+7420h] [rbp+7320h]
  char v531; // [rsp+7620h] [rbp+7520h]
  char v532; // [rsp+7820h] [rbp+7720h]
  char v533; // [rsp+7A20h] [rbp+7920h]
  char v534; // [rsp+7C20h] [rbp+7B20h]
  char v535; // [rsp+7E20h] [rbp+7D20h]
  char v536; // [rsp+8020h] [rbp+7F20h]
  char v537; // [rsp+8220h] [rbp+8120h]
  char v538; // [rsp+8420h] [rbp+8320h]
  char description; // [rsp+8620h] [rbp+8520h]
  bool v540; // [rsp+8870h] [rbp+8770h]
  hkGeometry *v541; // [rsp+8878h] [rbp+8778h]
  hkaiNavMeshGenerationOutputs *v542; // [rsp+8880h] [rbp+8780h]

  v542 = outputs;
  v541 = _triMeshIn;
  v5 = input;
  v6 = _callbacks;
  v7 = outputs;
  v8 = _triMeshIn;
  v540 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v9[1];
  v12 = v9;
  if ( (unsigned __int64)v11 < v9[3] )
  {
    *v11 = "TthkaiNavMeshGenerationUtils::generateNavMesh";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v11 += 2;
    *((_DWORD *)v11 - 2) = v13;
    v12[1] = v11;
  }
  if ( !v8->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v462, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v462.vfptr, "Passed in empty triMesh to generateNavMesh()");
    hkError::messageWarning(1060047688, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 401);
    hkOstream::~hkOstream((hkOstream *)&v462.vfptr);
    v14 = (hkVector4f *)v7->m_navMesh;
    if ( v14 )
    {
      v14[8] = (hkVector4f)aabbOut.m_quad;
      v14[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 1;
    goto LABEL_555;
  }
  if ( !HK_flyingcolors_ai.m_bool )
  {
    hkaiCheckKeycode(v11, v10, v12);
    hkaiProcessFlyingColors(&HK_flyingcolors_ai);
    if ( !HK_flyingcolors_ai.m_bool )
    {
      hkErrStream::hkErrStream(&v464, &description, 512);
      hkOstream::operator<<((hkOstream *)&v464.vfptr, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(691989308, &description, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 413);
      hkOstream::~hkOstream((hkOstream *)&v464.vfptr);
      v16 = (hkVector4f *)v7->m_navMesh;
      if ( v16 )
      {
        v16[8] = (hkVector4f)aabbOut.m_quad;
        v16[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 3;
      goto LABEL_555;
    }
  }
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkaiNavMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 176i64);
  if ( !v18 || (hkaiNavMesh::hkaiNavMesh(v18), v20 = (hkaiNavMesh *)v19, (v400 = v19) == 0i64) )
  {
    hkErrStream::hkErrStream(&v458, &v537, 512);
    hkOstream::operator<<(
      (hkOstream *)&v458.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v537, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 443);
    hkOstream::~hkOstream((hkOstream *)&v458.vfptr);
    v313 = (hkVector4f *)v7->m_navMesh;
    if ( v313 )
    {
      v313[8] = (hkVector4f)aabbOut.m_quad;
      v313[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_555;
  }
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkaiNavMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 176i64);
  if ( !v22 || (hkaiNavMesh::hkaiNavMesh(v22), (v398 = (hkReferencedObject *)&v23->vfptr) == 0i64) )
  {
    hkErrStream::hkErrStream(&v456, &v535, 512);
    hkOstream::operator<<(
      (hkOstream *)&v456.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v535, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 444);
    hkOstream::~hkOstream((hkOstream *)&v456.vfptr);
    v312 = (hkVector4f *)v7->m_navMesh;
    if ( v312 )
    {
      v312[8] = (hkVector4f)aabbOut.m_quad;
      v312[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    hkReferencedObject::removeReference(v400);
    goto LABEL_555;
  }
  if ( v7->m_navMesh )
    v23 = v7->m_navMesh;
  v24 = v5->m_enableSimplification.m_bool == 0;
  v25 = v23->m_edgeDataStriding;
  v26 = v23;
  mesh = v23;
  if ( !v24 )
    v26 = v20;
  newStride = v25;
  navMeshOut = v26;
  hkaiNavMesh::setEdgeDataStriding(v23, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v26, &v396, 0, 0);
  if ( v5->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(v5, v8);
  cb = (hkBitField *)&v391;
  if ( v6 )
    cb = (hkBitField *)v6;
  cuttingTriangles = cb;
  v391 = &hkaiNavMeshGenerationProgressCallback::`vftable';
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&cbCtx, v5);
  if ( !(*(unsigned __int64 (__fastcall **)(hkBitField *, _QWORD, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
          cb,
          0i64,
          &cbCtx)
    || !(*((unsigned __int8 (__fastcall **)(hkBitField *, _QWORD, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
         + 2))(
          cb,
          0i64,
          &cbCtx)
    || (v15 = 1,
        !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
           cb,
           1i64,
           &cbCtx)) )
  {
    v15 = 0;
    goto LABEL_548;
  }
  v28 = v5->m_materialMap.m_size;
  v354 = 2147483648;
  array = 0i64;
  v353 = 0;
  v29 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(v28);
  v30 = v354;
  v31 = v29;
  if ( (v354 & 0x3FFFFFFF) >= v29 )
  {
    v364.m_enum = 0;
  }
  else
  {
    v32 = v29;
    if ( v29 < 2 * (v354 & 0x3FFFFFFF) )
      v32 = 2 * (v354 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v364, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v32, 1);
    if ( v364.m_enum )
    {
      hkErrStream::hkErrStream(&v466, &v482, 512);
      hkOstream::operator<<(
        (hkOstream *)&v466.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v482, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 480);
      hkOstream::~hkOstream((hkOstream *)&v466.vfptr);
      v33 = (hkVector4f *)v7->m_navMesh;
      if ( v33 )
      {
        v33[8] = (hkVector4f)aabbOut.m_quad;
        v33[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_544;
    }
    v30 = v354;
  }
  v353 = v31;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    &v392,
    array,
    v30 & 0x3FFFFFFF);
  for ( i = 0i64; i < v28; ++i )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v392,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned int)v5->m_materialMap.m_data[i].m_materialIndex,
      v5->m_materialMap.m_data[i].m_flags.m_storage);
  v35 = 0;
  v36 = 2147483648;
  carvers.m_data = 0i64;
  carvers.m_size = 0;
  carvers.m_capacityAndFlags = 2147483648;
  v37 = v5->m_carvers.m_size + 1;
  if ( v37 <= 0 )
  {
    v360.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v360, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, v37, 8);
    if ( v360.m_enum )
    {
      hkErrStream::hkErrStream(&v443, &v532, 512);
      hkOstream::operator<<(
        (hkOstream *)&v443.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v532, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 498);
      v38 = &v443;
LABEL_535:
      hkOstream::~hkOstream((hkOstream *)&v38->vfptr);
      v309 = (hkVector4f *)v7->m_navMesh;
      if ( v309 )
      {
        v309[8] = (hkVector4f)aabbOut.m_quad;
        v309[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_538;
    }
    v36 = carvers.m_capacityAndFlags;
    v35 = carvers.m_size;
  }
  v40 = v5->m_carvers.m_size;
  v327 = v5->m_carvers.m_size;
  v39 = v327;
  if ( v327 > v35 )
    v40 = v35;
  v41 = v36 & 0x3FFFFFFF;
  v331.m_enum = v40;
  if ( v41 >= v327 )
  {
    v381.m_enum = 0;
  }
  else
  {
    v42 = 2 * v41;
    v43 = v327;
    if ( v327 < v42 )
      v43 = v42;
    hkArrayUtil::_reserve(&v381, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, v43, 8);
    v39 = v327;
  }
  v44 = &carvers.m_data[v39];
  v45 = v35 - v39 - 1;
  if ( (signed int)v45 >= 0 )
  {
    do
    {
      v46 = (hkReferencedObject *)&v44[v45].m_pntr->vfptr;
      if ( v46 )
        hkReferencedObject::removeReference(v46);
      v44[v45--].m_pntr = 0i64;
    }
    while ( v45 >= 0 );
  }
  v47 = (hkBitField *)(signed int)v331.m_enum;
  v48 = v5->m_carvers.m_data;
  v49 = 0i64;
  walkableInOut = (hkBitField *)(signed int)v331.m_enum;
  if ( (signed int)v331.m_enum > 0i64 )
  {
    v50 = carvers.m_data;
    v51 = v331.m_enum;
    do
    {
      v52 = (hkReferencedObject *)&v48[v49].m_pntr->vfptr;
      if ( v52 )
        hkReferencedObject::addReference(v52);
      v53 = (hkReferencedObject *)&v50[v49].m_pntr->vfptr;
      if ( v53 )
        hkReferencedObject::removeReference(v53);
      v54 = v48[v49++].m_pntr;
      v50[v49 - 1].m_pntr = v54;
    }
    while ( v49 < v51 );
    cb = cuttingTriangles;
    v7 = v542;
    v47 = walkableInOut;
  }
  v55 = (hkReferencedObject **)&v5->m_carvers.m_data[(_QWORD)v47];
  v56 = &carvers.m_data[(_QWORD)v47];
  v57 = (hkBitField *)(v327 - v331.m_enum);
  walkableInOut = (hkBitField *)(v327 - v331.m_enum);
  if ( v327 - v331.m_enum > 0 )
  {
    v58 = (hkReferencedObject *)((char *)v56 - (char *)v55);
    v335 = v58;
    do
    {
      v59 = (hkReferencedObject **)((char *)v55 + (_QWORD)v58);
      if ( (hkReferencedObject **)((char *)v55 + (_QWORD)v58) )
      {
        if ( *v55 )
        {
          hkReferencedObject::addReference(*v55);
          v57 = walkableInOut;
        }
        v58 = v335;
        *v59 = *v55;
      }
      ++v55;
      v57 = (hkBitField *)((char *)v57 - 1);
      walkableInOut = v57;
    }
    while ( v57 );
  }
  v60 = &v5->m_boundsAabb;
  carvers.m_size = v327;
  if ( !(_mm_movemask_ps(_mm_cmpleps(v5->m_boundsAabb.m_max.m_quad, v5->m_boundsAabb.m_min.m_quad)) & 7) )
  {
    v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v62 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v61[11] + 8i64))(
                                      v61[11],
                                      96i64);
    if ( v62 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v62, &v5->m_boundsAabb);
      v64 = v63;
    }
    else
    {
      v64 = 0i64;
    }
    v65 = carvers.m_size;
    if ( carvers.m_size == (carvers.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, 8);
      v65 = carvers.m_size;
    }
    v66 = carvers.m_data;
    v67 = &carvers.m_data[v65];
    if ( v67 )
    {
      v67->m_pntr = 0i64;
      v65 = carvers.m_size;
      v66 = carvers.m_data;
    }
    v68 = (hkBitField *)v65;
    carvers.m_size = v65 + 1;
    v69 = (hkReferencedObject *)&v66[v65].m_pntr->vfptr;
    walkableInOut = v68;
    if ( v69 && v69 != (hkReferencedObject *)v64 )
    {
      hkReferencedObject::removeReference(v69);
      v68 = walkableInOut;
    }
    v66[(_QWORD)v68].m_pntr = v64;
    v60 = &v5->m_boundsAabb;
  }
  v70 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v71 = (hkaiCarverTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v70[11] + 8i64))(v70[11], 48i64);
  if ( !v71 || (hkaiCarverTree::hkaiCarverTree(v71), (carverTree = v72) == 0i64) )
  {
    hkErrStream::hkErrStream(&v454, &v533, 512);
    hkOstream::operator<<(
      (hkOstream *)&v454.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v533, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 516);
    v38 = &v454;
    goto LABEL_535;
  }
  hkaiCarverTree::init(
    v72,
    &v397,
    &carvers,
    (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&v5->m_painters.m_data);
  v73 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v74 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v73[11] + 8i64))(v73[11], 48i64);
  v335 = (hkReferencedObject *)v74;
  if ( !v74 )
  {
    v77 = 0i64;
    hkErrStream::hkErrStream(&v452, &v531, 512);
    hkOstream::operator<<(
      (hkOstream *)&v452.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v531, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 519);
    hkOstream::~hkOstream((hkOstream *)&v452.vfptr);
    goto LABEL_528;
  }
  v75 = v541;
  *(_DWORD *)(v74 + 8) = 0x1FFFF;
  v76 = (hkGeometry *)v74;
  *(_QWORD *)v74 = &hkGeometry::`vftable';
  *(_QWORD *)(v74 + 16) = 0i64;
  *(_DWORD *)(v74 + 24) = 0;
  *(_DWORD *)(v74 + 28) = 2147483648;
  *(_QWORD *)(v74 + 32) = 0i64;
  *(_DWORD *)(v74 + 40) = 0;
  *(_DWORD *)(v74 + 44) = 2147483648;
  if ( v7->m_weldedGeometry )
    v76 = v7->m_weldedGeometry;
  hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(
    (hkResult *)&v541,
    v76,
    v75,
    v60,
    (hkaiNavMeshGenerationSettings::TriangleWinding)(unsigned __int8)v5->m_triangleWinding.m_storage);
  if ( (_DWORD)v541 )
  {
    hkErrStream::hkErrStream(&v471, &v484, 512);
    hkOstream::operator<<(
      (hkOstream *)&v471.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v484, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 523);
    hkOstream::~hkOstream((hkOstream *)&v471.vfptr);
    v77 = v335;
LABEL_528:
    v308 = (hkVector4f *)v7->m_navMesh;
    if ( v308 )
    {
      v308[8] = (hkVector4f)aabbOut.m_quad;
      v308[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_531;
  }
  v78 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v79 = (_QWORD *)v78[1];
  if ( (unsigned __int64)v79 < v78[3] )
  {
    *v79 = "TtconvertAndMerge";
    v80 = __rdtsc();
    v81 = (signed __int64)(v79 + 2);
    *(_DWORD *)(v81 - 8) = v80;
    v78[1] = v81;
  }
  v82 = v5->m_quantizationGridSize;
  if ( v82 != 0.0 )
    hkaiNavMeshGenerationUtils::quantize(v76, v82);
  if ( v5->m_weldInputVertices.m_bool )
  {
    v83 = v76->m_vertices.m_size;
    v84 = v76->m_triangles.m_size;
    v85 = 2147483648;
    vertexRemapOut.m_data = 0i64;
    vertexRemapOut.m_size = 0;
    vertexRemapOut.m_capacityAndFlags = 2147483648;
    LODWORD(v541) = v84;
    triangleRemapOut.m_data = 0i64;
    triangleRemapOut.m_size = 0;
    triangleRemapOut.m_capacityAndFlags = 2147483648;
    sweepAabbs.m_data = 0i64;
    sweepAabbs.m_size = 0;
    sweepAabbs.m_capacityAndFlags = 2147483648;
    uniqueVerts.m_data = 0i64;
    uniqueVerts.m_size = 0;
    uniqueVerts.m_capacityAndFlags = 2147483648;
    sortData.m_data = 0i64;
    sortData.m_size = 0;
    sortData.m_capacityAndFlags = 2147483648;
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_size = 0;
    sortedAabbs.m_capacityAndFlags = 2147483648;
    if ( v83 <= 0 )
    {
      v356.m_enum = 0;
    }
    else
    {
      v86 = v83;
      if ( v83 < 0 )
        v86 = 0;
      hkArrayUtil::_reserve(
        &v356,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &vertexRemapOut,
        v86,
        4);
      if ( v356.m_enum )
      {
        hkErrStream::hkErrStream(&v413, &v512, 512);
        hkOstream::operator<<(
          (hkOstream *)&v413.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v512, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 561);
        v87 = &v413;
LABEL_129:
        hkOstream::~hkOstream((hkOstream *)&v87->vfptr);
        v95 = (hkVector4f *)v7->m_navMesh;
        if ( v95 )
        {
          v95[8] = (hkVector4f)aabbOut.m_quad;
          v95[9] = (hkVector4f)aabbOut.m_quad;
        }
        sortedAabbs.m_size = 0;
        if ( sortedAabbs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            sortedAabbs.m_data,
            32 * sortedAabbs.m_capacityAndFlags);
        sortedAabbs.m_data = 0i64;
        sortedAabbs.m_capacityAndFlags = 2147483648;
        sortData.m_size = 0;
        if ( sortData.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            sortData.m_data,
            8 * sortData.m_capacityAndFlags);
        sortData.m_data = 0i64;
        sortData.m_capacityAndFlags = 2147483648;
        uniqueVerts.m_size = 0;
        if ( uniqueVerts.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            uniqueVerts.m_data,
            16 * uniqueVerts.m_capacityAndFlags);
        uniqueVerts.m_data = 0i64;
        uniqueVerts.m_capacityAndFlags = 2147483648;
        sweepAabbs.m_size = 0;
        if ( sweepAabbs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            sweepAabbs.m_data,
            32 * sweepAabbs.m_capacityAndFlags);
        sweepAabbs.m_data = 0i64;
        sweepAabbs.m_capacityAndFlags = 2147483648;
        triangleRemapOut.m_size = 0;
        if ( triangleRemapOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            triangleRemapOut.m_data,
            4 * triangleRemapOut.m_capacityAndFlags);
        triangleRemapOut.m_data = 0i64;
        triangleRemapOut.m_capacityAndFlags = 2147483648;
        vertexRemapOut.m_size = 0;
        if ( vertexRemapOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vertexRemapOut.m_data,
            4 * vertexRemapOut.m_capacityAndFlags);
        vertexRemapOut.m_data = 0i64;
        vertexRemapOut.m_capacityAndFlags = 2147483648;
        v15 = 2;
        goto LABEL_178;
      }
      v85 = triangleRemapOut.m_capacityAndFlags;
      v84 = (signed int)v541;
    }
    v88 = v85 & 0x3FFFFFFF;
    if ( v88 >= v84 )
    {
      v357.m_enum = 0;
    }
    else
    {
      v89 = 2 * v88;
      if ( v84 < v89 )
        v84 = v89;
      hkArrayUtil::_reserve(
        &v357,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &triangleRemapOut,
        v84,
        4);
      if ( v357.m_enum )
      {
        hkErrStream::hkErrStream(&v459, &v486, 512);
        hkOstream::operator<<(
          (hkOstream *)&v459.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v486, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 564);
        v87 = &v459;
        goto LABEL_129;
      }
    }
    if ( (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) >= v83 )
    {
      v359.m_enum = 0;
    }
    else
    {
      v90 = v83;
      if ( v83 < 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) )
        v90 = 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v359, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &uniqueVerts, v90, 16);
      if ( v359.m_enum )
      {
        hkErrStream::hkErrStream(&v415, &v526, 512);
        hkOstream::operator<<(
          (hkOstream *)&v415.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v526, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 567);
        v87 = &v415;
        goto LABEL_129;
      }
    }
    v91 = v83 + 4;
    if ( (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v91 )
    {
      v361.m_enum = 0;
    }
    else
    {
      v92 = v91;
      if ( v91 < 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
        v92 = 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v361, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &sweepAabbs, v92, 32);
      if ( v361.m_enum )
      {
        hkErrStream::hkErrStream(&v445, &v488, 512);
        hkOstream::operator<<(
          (hkOstream *)&v445.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v488, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 570);
        v87 = &v445;
        goto LABEL_129;
      }
    }
    if ( (sortData.m_capacityAndFlags & 0x3FFFFFFF) >= v91 )
    {
      v355.m_enum = 0;
    }
    else
    {
      v93 = v91;
      if ( v91 < 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF) )
        v93 = 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v355, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &sortData, v93, 8);
      if ( v355.m_enum )
      {
        hkErrStream::hkErrStream(&v417, &v514, 512);
        hkOstream::operator<<(
          (hkOstream *)&v417.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v514, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 573);
        v87 = &v417;
        goto LABEL_129;
      }
    }
    sortData.m_size = v91;
    if ( (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v91 )
    {
      v365.m_enum = 0;
    }
    else
    {
      v94 = v91;
      if ( v91 < 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
        v94 = 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v365, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &sortedAabbs, v94, 32);
      if ( v365.m_enum )
      {
        hkErrStream::hkErrStream(&v467, &v490, 512);
        hkOstream::operator<<(
          (hkOstream *)&v467.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v490, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 576);
        v87 = &v467;
        goto LABEL_129;
      }
    }
    sortedAabbs.m_size = v91;
    v345 = 0;
    hkGeometryUtils::_weldVertices(
      v76,
      v5->m_weldThreshold,
      0,
      &vertexRemapOut,
      &triangleRemapOut,
      &uniqueVerts,
      &sweepAabbs,
      &sortData,
      &sortedAabbs);
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_capacityAndFlags = 2147483648;
    sortData.m_size = 0;
    if ( sortData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        sortData.m_data,
        8 * sortData.m_capacityAndFlags);
    sortData.m_data = 0i64;
    sortData.m_capacityAndFlags = 2147483648;
    uniqueVerts.m_size = 0;
    if ( uniqueVerts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        uniqueVerts.m_data,
        16 * uniqueVerts.m_capacityAndFlags);
    uniqueVerts.m_data = 0i64;
    uniqueVerts.m_capacityAndFlags = 2147483648;
    sweepAabbs.m_size = 0;
    if ( sweepAabbs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        sweepAabbs.m_data,
        32 * sweepAabbs.m_capacityAndFlags);
    sweepAabbs.m_data = 0i64;
    sweepAabbs.m_capacityAndFlags = 2147483648;
    triangleRemapOut.m_size = 0;
    if ( triangleRemapOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        triangleRemapOut.m_data,
        4 * triangleRemapOut.m_capacityAndFlags);
    triangleRemapOut.m_data = 0i64;
    triangleRemapOut.m_capacityAndFlags = 2147483648;
    vertexRemapOut.m_size = 0;
    if ( vertexRemapOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        vertexRemapOut.m_data,
        4 * vertexRemapOut.m_capacityAndFlags);
    vertexRemapOut.m_data = 0i64;
    vertexRemapOut.m_capacityAndFlags = 2147483648;
  }
  newTriangles.m_data = 0i64;
  newTriangles.m_size = 0;
  newTriangles.m_capacityAndFlags = 2147483648;
  v96 = v76->m_triangles.m_size;
  if ( v96 <= 0 )
  {
    v367.m_enum = 0;
  }
  else
  {
    if ( v96 < 0 )
      v96 = 0;
    hkArrayUtil::_reserve(&v367, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &newTriangles, v96, 16);
    if ( v367.m_enum )
    {
      hkErrStream::hkErrStream(&v419, &v536, 512);
      hkOstream::operator<<(
        (hkOstream *)&v419.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v536, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 584);
      v97 = &v419;
LABEL_166:
      hkOstream::~hkOstream((hkOstream *)&v97->vfptr);
      v98 = (hkVector4f *)v7->m_navMesh;
      if ( v98 )
      {
        v98[8] = (hkVector4f)aabbOut.m_quad;
        v98[9] = (hkVector4f)aabbOut.m_quad;
      }
      newTriangles.m_size = 0;
      if ( newTriangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          newTriangles.m_data,
          16 * newTriangles.m_capacityAndFlags);
      newTriangles.m_data = 0i64;
      newTriangles.m_capacityAndFlags = 2147483648;
      v15 = 2;
      goto LABEL_178;
    }
  }
  hkGeometryUtils::removeDuplicateTrianglesFast(&v369, v76, &newTriangles);
  if ( v369.m_enum )
  {
    hkErrStream::hkErrStream(&v447, &v492, 512);
    hkOstream::operator<<(
      (hkOstream *)&v447.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v492, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 587);
    v97 = &v447;
    goto LABEL_166;
  }
  newTriangles.m_size = 0;
  if ( newTriangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newTriangles.m_data,
      16 * newTriangles.m_capacityAndFlags);
  newTriangles.m_data = 0i64;
  newTriangles.m_capacityAndFlags = 2147483648;
  if ( !v76->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v421, &v516, 512);
    hkOstream::operator<<((hkOstream *)&v421.vfptr, "No triangles were contained in the input AABB.");
    hkError::messageWarning(1541620707, &v516, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 592);
    hkOstream::~hkOstream((hkOstream *)&v421.vfptr);
    v99 = (hkVector4f *)v7->m_navMesh;
    if ( v99 )
    {
      v99[8] = (hkVector4f)aabbOut.m_quad;
      v99[9] = (hkVector4f)aabbOut.m_quad;
    }
    goto LABEL_178;
  }
  if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
         + 2))(
          cb,
          1i64,
          &cbCtx) )
  {
    v15 = 0;
LABEL_178:
    v100 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v101 = (_QWORD *)v100[1];
    if ( (unsigned __int64)v101 < v100[3] )
    {
      *v101 = "Et";
      v102 = __rdtsc();
      v103 = (signed __int64)(v101 + 2);
      *(_DWORD *)(v103 - 8) = v102;
      v100[1] = v103;
    }
    v77 = v335;
    goto LABEL_531;
  }
  v104 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v105 = (_QWORD *)v104[1];
  if ( (unsigned __int64)v105 < v104[3] )
  {
    *v105 = "Et";
    v106 = __rdtsc();
    v107 = (signed __int64)(v105 + 2);
    *(_DWORD *)(v107 - 8) = v106;
    v104[1] = v107;
  }
  v403.m_data.m_data = 0i64;
  v403.m_data.m_size = 0;
  v403.m_data.m_capacityAndFlags = 2147483648;
  v403.m_m = 0;
  v401.m_data.m_data = 0i64;
  v401.m_data.m_size = 0;
  v401.m_data.m_capacityAndFlags = 2147483648;
  v401.m_m = 0;
  v108 = v76->m_triangles.m_size;
  v109 = (hkBitField *)&v403;
  if ( v7->m_cuttingTriangles )
    v109 = v7->m_cuttingTriangles;
  v110 = v7->m_walkableTriangles;
  v111 = (hkBitField *)&v401;
  cuttingTriangles = v109;
  if ( v110 )
    v111 = v110;
  walkableInOut = v111;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v111->m_storage,
    (hkResult *)&v541,
    0,
    v108,
    1);
  if ( (_DWORD)v541 )
  {
    hkErrStream::hkErrStream(&v461, &v494, 512);
    hkOstream::operator<<(
      (hkOstream *)&v461.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v494, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 608);
    v112 = &v461;
LABEL_191:
    hkOstream::~hkOstream((hkOstream *)&v112->vfptr);
    v113 = (hkVector4f *)v7->m_navMesh;
    if ( v113 )
    {
      v113[8] = (hkVector4f)aabbOut.m_quad;
      v113[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_526;
  }
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v109->m_storage,
    (hkResult *)&v541,
    0,
    v76->m_triangles.m_size,
    1);
  if ( (_DWORD)v541 )
  {
    hkErrStream::hkErrStream(&v423, &v528, 512);
    hkOstream::operator<<(
      (hkOstream *)&v423.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v528, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 614);
    v112 = &v423;
    goto LABEL_191;
  }
  v114 = 0;
  if ( v76->m_triangles.m_size > 0 )
  {
    v115 = cuttingTriangles;
    do
    {
      if ( !hkaiNavMeshGenerationUtils::isTriangleCutting(
              v76,
              v114,
              v5,
              (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v392) )
        v115->m_storage.m_words.m_data[(signed __int64)v114 >> 5] &= ~(1 << (v114 & 0x1F));
      ++v114;
    }
    while ( v114 < v76->m_triangles.m_size );
    v7 = v542;
  }
  v116 = 0i64;
  v117 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v118 = (_QWORD *)v117[1];
  if ( (unsigned __int64)v118 < v117[3] )
  {
    *v118 = "TtbuildDynamicTree";
    v119 = __rdtsc();
    v120 = (signed __int64)(v118 + 2);
    *(_DWORD *)(v120 - 8) = v119;
    v117[1] = v120;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
          cb,
          2i64,
          &cbCtx) )
    goto LABEL_560;
  v121 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v122 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v121[11] + 8i64))(
                                  v121[11],
                                  32i64);
  if ( v122 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v122);
    v116 = v123;
  }
  if ( !v116 )
  {
    hkErrStream::hkErrStream(&v449, &v496, 512);
    hkOstream::operator<<(
      (hkOstream *)&v449.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v496, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 631);
    v124 = &v449;
LABEL_209:
    hkOstream::~hkOstream((hkOstream *)&v124->vfptr);
    v125 = (hkVector4f *)v7->m_navMesh;
    if ( v125 )
    {
      v125[8] = (hkVector4f)aabbOut.m_quad;
      v125[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_214;
  }
  hkaiNavMeshGenerationUtils::buildCuttingGeomTree(
    (hkResult *)&v541,
    (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v392,
    v76,
    v5,
    cuttingTriangles,
    v116);
  if ( (_DWORD)v541 )
  {
    hkErrStream::hkErrStream(&v425, &v518, 512);
    hkOstream::operator<<(
      (hkOstream *)&v425.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v518, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 634);
    v124 = &v425;
    goto LABEL_209;
  }
  if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
         + 2))(
          cb,
          2i64,
          &cbCtx) )
  {
LABEL_560:
    v15 = 0;
LABEL_214:
    v126 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v127 = (_QWORD *)v126[1];
    if ( (unsigned __int64)v127 < v126[3] )
    {
      *v127 = "Et";
      v128 = __rdtsc();
      v129 = (signed __int64)(v127 + 2);
      *(_DWORD *)(v129 - 8) = v128;
      v126[1] = v129;
    }
    goto LABEL_524;
  }
  v130 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v131 = (_QWORD *)v130[1];
  if ( (unsigned __int64)v131 < v130[3] )
  {
    *v131 = "Et";
    v132 = __rdtsc();
    v133 = (signed __int64)(v131 + 2);
    *(_DWORD *)(v133 - 8) = v132;
    v130[1] = v133;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
          cb,
          3i64,
          &cbCtx) )
  {
    v15 = 0;
    goto LABEL_524;
  }
  v134 = 2147483648;
  triangleVertices.m_data = 0i64;
  triangleVertices.m_size = 0;
  triangleVertices.m_capacityAndFlags = 2147483648;
  v329.m_data = 0i64;
  v329.m_size = 0;
  originalFaceIndices.m_capacityAndFlags = 2147483648;
  hitFaces.m_capacityAndFlags = 2147483648;
  v329.m_capacityAndFlags = 2147483648;
  v336.m_data = 0i64;
  v336.m_size = 0;
  v336.m_capacityAndFlags = 2147483648;
  v337.m_data = 0i64;
  v337.m_size = 0;
  v337.m_capacityAndFlags = 2147483648;
  originalFaceIndices.m_data = 0i64;
  originalFaceIndices.m_size = 0;
  hitFaces.m_data = 0i64;
  hitFaces.m_size = 0;
  v135 = v76->m_triangles.m_size;
  if ( v135 <= 0 )
  {
    v363.m_enum = 0;
  }
  else
  {
    if ( v135 < 0 )
      v135 = 0;
    hkArrayUtil::_reserve(&v363, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v336, v135, 4);
    if ( v363.m_enum )
    {
      hkErrStream::hkErrStream(&v472, &v498, 512);
      hkOstream::operator<<(
        (hkOstream *)&v472.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v498, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 649);
      v136 = &v472;
LABEL_232:
      hkOstream::~hkOstream((hkOstream *)&v136->vfptr);
      v139 = (hkVector4f *)v7->m_navMesh;
      if ( v139 )
      {
        v139[8] = (hkVector4f)aabbOut.m_quad;
        v139[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_511;
    }
    v134 = originalFaceIndices.m_capacityAndFlags;
  }
  v137 = v76->m_triangles.m_size + 1;
  v138 = v134 & 0x3FFFFFFF;
  if ( (v134 & 0x3FFFFFFF) >= v137 )
  {
    v366.m_enum = 0;
  }
  else
  {
    if ( v137 < 2 * v138 )
      v137 = 2 * v138;
    hkArrayUtil::_reserve(
      &v366,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &originalFaceIndices,
      v137,
      4);
    if ( v366.m_enum )
    {
      hkErrStream::hkErrStream(&v427, &v534, 512);
      hkOstream::operator<<(
        (hkOstream *)&v427.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v534, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 652);
      v136 = &v427;
      goto LABEL_232;
    }
    v134 = originalFaceIndices.m_capacityAndFlags;
  }
  if ( originalFaceIndices.m_size == (v134 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &originalFaceIndices, 4);
  originalFaceIndices.m_data[originalFaceIndices.m_size] = -1;
  ++originalFaceIndices.m_size;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::setForSingleTriangle(&geomA, &v390);
  if ( v390.m_enum )
  {
    hkErrStream::hkErrStream(&v451, &v500, 512);
    hkOstream::operator<<(
      (hkOstream *)&v451.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v500, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 659);
    hkOstream::~hkOstream((hkOstream *)&v451.vfptr);
    v140 = (hkVector4f *)v7->m_navMesh;
    if ( v140 )
    {
      v140[8] = (hkVector4f)aabbOut.m_quad;
      v140[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
    goto LABEL_511;
  }
  *(_DWORD *)&cuttingGeom.m_memSizeAndFlags = 0x1FFFF;
  cuttingGeom.m_vertices.m_data = 0i64;
  cuttingGeom.m_vertices.m_size = 0;
  cuttingGeom.m_vertices.m_capacityAndFlags = 2147483648;
  cuttingGeom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  cuttingGeom.m_triangles.m_data = 0i64;
  cuttingGeom.m_triangles.m_size = 0;
  cuttingGeom.m_triangles.m_capacityAndFlags = 2147483648;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomOut);
  hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&v475);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geom);
  hkaiBooleanOperation::hkaiBooleanOperation(&v478);
  hkaiGeometryExtrudeUtil::hkaiGeometryExtrudeUtil(&v477);
  faceEdges.m_faceEdges.m_data = 0i64;
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceEdges.m_capacityAndFlags = 2147483648;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  faceEdges.m_faceStartEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  trisOut.m_data = 0i64;
  trisOut.m_size = 0;
  trisOut.m_capacityAndFlags = 2147483648;
  triConnectivityOut.m_data = 0i64;
  triConnectivityOut.m_size = 0;
  triConnectivityOut.m_capacityAndFlags = 2147483648;
  LODWORD(v541) = 0;
  v141 = _mm_shuffle_ps((__m128)LODWORD(v5->m_characterHeight), (__m128)LODWORD(v5->m_characterHeight), 0);
  characterHeight.m_real = v141;
  if ( v76->m_triangles.m_size > 0 )
  {
    do
    {
      v142 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v143 = v142[1];
      if ( v143 < v142[3] )
      {
        *(_QWORD *)v143 = "Ltcsg";
        *(_QWORD *)(v143 + 16) = "Stwalkable";
        v144 = __rdtsc();
        *(_DWORD *)(v143 + 8) = v144;
        v142[1] = v143 + 24;
      }
      if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, _QWORD, _QWORD, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
             + 1))(
              cb,
              3i64,
              (unsigned int)v541,
              (unsigned int)v76->m_triangles.m_size,
              &cbCtx) )
      {
        v150 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v151 = (_QWORD *)v150[1];
        if ( (unsigned __int64)v151 < v150[3] )
        {
          *v151 = "lt";
          v152 = __rdtsc();
          v153 = (signed __int64)(v151 + 2);
          *(_DWORD *)(v153 - 8) = v152;
          v150[1] = v153;
        }
        v15 = 0;
        goto LABEL_341;
      }
      if ( !hkaiNavMeshGenerationUtils::isTriangleWalkable(
              v76,
              (int)v541,
              v5,
              carverTree,
              (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v392) )
        walkableInOut->m_storage.m_words.m_data[(signed __int64)(signed int)v541 >> 5] &= ~(1 << ((unsigned __int8)v541 & 0x1F));
      v145 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v146 = (_QWORD *)v145[1];
      if ( (unsigned __int64)v146 < v145[3] )
      {
        *v146 = "lt";
        v147 = __rdtsc();
        v148 = (signed __int64)(v146 + 2);
        *(_DWORD *)(v148 - 8) = v147;
        v145[1] = v148;
      }
      LODWORD(v541) = (_DWORD)v541 + 1;
    }
    while ( (signed int)v541 < v76->m_triangles.m_size );
  }
  if ( v5->m_regionPruningSettings.m_pruneBeforeTriangulation.m_bool )
  {
    hkaiNavMeshGenerationUtils::_pruneTriangles((hkResult *)&v541, v76, v5, walkableInOut);
    if ( (_DWORD)v541 )
    {
      hkErrStream::hkErrStream(&v429, &v520, 512);
      hkOstream::operator<<(
        (hkOstream *)&v429.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v520, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 695);
      hkOstream::~hkOstream((hkOstream *)&v429.vfptr);
      v149 = (hkVector4f *)v7->m_navMesh;
      if ( v149 )
      {
        v149[8] = (hkVector4f)aabbOut.m_quad;
        v149[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_341;
    }
  }
  LODWORD(v541) = 0;
  if ( v76->m_triangles.m_size <= 0 )
  {
LABEL_309:
    triConnectivityOut.m_size = 0;
    if ( triConnectivityOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        triConnectivityOut.m_data,
        4 * triConnectivityOut.m_capacityAndFlags);
    triConnectivityOut.m_data = 0i64;
    triConnectivityOut.m_capacityAndFlags = 2147483648;
    trisOut.m_size = 0;
    if ( trisOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        trisOut.m_data,
        4 * trisOut.m_capacityAndFlags);
    trisOut.m_data = 0i64;
    trisOut.m_capacityAndFlags = 2147483648;
    hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&faceEdges);
    hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v477);
    hkaiBooleanOperation::~hkaiBooleanOperation(&v478);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
    hkaiSelfIntersectBooleanFilter2::~hkaiSelfIntersectBooleanFilter2(&v475);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
    hkGeometry::~hkGeometry(&cuttingGeom);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
    if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
           + 2))(
            cb,
            3i64,
            &cbCtx) )
    {
      v15 = 0;
      goto LABEL_511;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v116->vfptr);
    v116 = 0i64;
    if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
            cb,
            4i64,
            &cbCtx) )
    {
      v15 = 0;
      goto LABEL_511;
    }
    v225 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v226 = (_QWORD *)v225[1];
    if ( (unsigned __int64)v226 < v225[3] )
    {
      *v226 = "TtWeldExact";
      v227 = __rdtsc();
      v228 = (signed __int64)(v226 + 2);
      *(_DWORD *)(v228 - 8) = v227;
      v225[1] = v228;
    }
    remap.m_data = 0i64;
    remap.m_size = 0;
    remap.m_capacityAndFlags = 2147483648;
    hkaiNavMeshGenerationUtils::weldDuplicateVertices(
      (hkResult *)&v541,
      (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
      &remap);
    if ( (_DWORD)v541 )
    {
      hkErrStream::hkErrStream(&v470, &v487, 512);
      hkOstream::operator<<(
        (hkOstream *)&v470.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v487, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 913);
      hkOstream::~hkOstream((hkOstream *)&v470.vfptr);
      v229 = (hkVector4f *)v7->m_navMesh;
      if ( v229 )
      {
        v229[8] = (hkVector4f)aabbOut.m_quad;
        v229[9] = (hkVector4f)aabbOut.m_quad;
      }
      remap.m_size = 0;
      if ( remap.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          remap.m_data,
          4 * remap.m_capacityAndFlags);
      remap.m_data = 0i64;
      remap.m_capacityAndFlags = 2147483648;
      v230 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v231 = (_QWORD *)v230[1];
      if ( (unsigned __int64)v231 < v230[3] )
      {
        *v231 = "Et";
        v232 = __rdtsc();
        v233 = (signed __int64)(v231 + 2);
        *(_DWORD *)(v233 - 8) = v232;
        v230[1] = v233;
      }
      v15 = 2;
      goto LABEL_511;
    }
    v234 = 0i64;
    if ( v329.m_size > 0 )
    {
      v235 = 0i64;
      do
      {
        v234 = (unsigned int)(v234 + 1);
        v236 = (signed int)v329.m_data[v235];
        ++v235;
        v329.m_data[v235 - 1] = remap.m_data[v236];
      }
      while ( (signed int)v234 < v329.m_size );
    }
    remap.m_size = 0;
    if ( remap.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        remap.m_data,
        (unsigned int)(4 * remap.m_capacityAndFlags),
        v234);
    remap.m_data = 0i64;
    remap.m_capacityAndFlags = 2147483648;
    v237 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v238 = (_QWORD *)v237[1];
    if ( (unsigned __int64)v238 < v237[3] )
    {
      *v238 = "Et";
      v239 = __rdtsc();
      v240 = (signed __int64)(v238 + 2);
      *(_DWORD *)(v240 - 8) = v239;
      v237[1] = v240;
    }
    if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
           + 2))(
            cb,
            4i64,
            &cbCtx) )
    {
      v15 = 0;
      goto LABEL_511;
    }
    hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(&v479);
    v241 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v242 = (hkaiEdgeGeometryRaycaster *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v241[11] + 8i64))(
                                          v241[11],
                                          112i64);
    if ( v242 )
    {
      hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(v242);
      *(_QWORD *)&v330[0].m_enum = v243;
      if ( v243 )
      {
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                5i64,
                &cbCtx) )
        {
          v15 = 0;
LABEL_508:
          if ( *(_QWORD *)&v330[0].m_enum )
            hkReferencedObject::removeReference(*(hkReferencedObject **)&v330[0].m_enum);
          hkaiNavMeshSimplificationSnapshot::~hkaiNavMeshSimplificationSnapshot(&v479);
          goto LABEL_511;
        }
        if ( !edgeConnectionRayCaster )
        {
          v244 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v245 = (_QWORD *)v244[1];
          if ( (unsigned __int64)v245 < v244[3] )
          {
            *v245 = "TtbuildEdgeGeomRaycasters";
            v246 = __rdtsc();
            v247 = (signed __int64)(v245 + 2);
            *(_DWORD *)(v247 - 8) = v246;
            v244[1] = v247;
          }
          hkaiEdgeGeometryRaycaster::init(
            *(hkaiEdgeGeometryRaycaster **)&v330[0].m_enum,
            &v371,
            v76,
            &carvers,
            cuttingTriangles);
          if ( v371.m_enum )
          {
            hkErrStream::hkErrStream(&v411, &v489, 512);
            hkOstream::operator<<(
              (hkOstream *)&v411.vfptr,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, &v489, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 935);
            v248 = &v411;
LABEL_376:
            hkOstream::~hkOstream((hkOstream *)&v248->vfptr);
            v249 = (hkVector4f *)v7->m_navMesh;
            if ( v249 )
            {
              v249[8] = (hkVector4f)aabbOut.m_quad;
              v249[9] = (hkVector4f)aabbOut.m_quad;
            }
            v250 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v251 = (_QWORD *)v250[1];
            if ( (unsigned __int64)v251 < v250[3] )
            {
              *v251 = "Et";
              v252 = __rdtsc();
              v253 = (signed __int64)(v251 + 2);
              *(_DWORD *)(v253 - 8) = v252;
              v250[1] = v253;
            }
LABEL_507:
            v15 = 2;
            goto LABEL_508;
          }
          edgeConnectionRayCaster = *(hkaiEdgeGeometryRaycaster **)&v330[0].m_enum;
          if ( v5->m_simplificationSettings.m_saveInputSnapshot.m_bool )
            hkaiNavMeshSimplificationSnapshot::setRaycasterInformation(&v479, v76, &carvers, cuttingTriangles);
          v254 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v255 = (_QWORD *)v254[1];
          if ( (unsigned __int64)v255 < v254[3] )
          {
            *v255 = "Et";
            v256 = __rdtsc();
            v257 = (signed __int64)(v255 + 2);
            *(_DWORD *)(v257 - 8) = v256;
            v254[1] = v257;
          }
        }
        v258 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v259 = (_QWORD *)v258[1];
        if ( (unsigned __int64)v259 < v258[3] )
        {
          *v259 = "TtRemoveUnreachable";
          v260 = __rdtsc();
          v261 = (signed __int64)(v259 + 2);
          *(_DWORD *)(v261 - 8) = v260;
          v258[1] = v261;
        }
        hkaiNavMeshGenerationUtils::_removeUnreachableTriangles(
          (hkResult *)&v541,
          v5,
          *(hkaiEdgeGeometryRaycaster **)&v330[0].m_enum,
          0i64,
          carverTree,
          (hkArray<int,hkContainerHeapAllocator> *)&v336,
          (hkArray<int,hkContainerHeapAllocator> *)&v329,
          (hkArray<int,hkContainerHeapAllocator> *)&v337,
          (hkArray<int,hkContainerHeapAllocator> *)&v336,
          0i64,
          &originalFaceIndices,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
          &hitFaces,
          (hkaiNavMeshGenerationProgressCallback *)cb,
          &cbCtx);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v412, &v491, 512);
          hkOstream::operator<<(
            (hkOstream *)&v412.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v491, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 952);
          v248 = &v412;
          goto LABEL_376;
        }
        edgeConnectionRayCaster->m_faceFlagMask.m_storage = 15;
        hitFaces.m_size = 0;
        if ( hitFaces.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            hitFaces.m_data,
            4 * hitFaces.m_capacityAndFlags);
        hitFaces.m_data = 0i64;
        hitFaces.m_capacityAndFlags = 2147483648;
        v262 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v263 = (_QWORD *)v262[1];
        if ( (unsigned __int64)v263 < v262[3] )
        {
          *v263 = "Et";
          v264 = __rdtsc();
          v265 = (signed __int64)(v263 + 2);
          *(_DWORD *)(v265 - 8) = v264;
          v262[1] = v265;
        }
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                5i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        v266 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v267 = (_QWORD *)v266[1];
        if ( (unsigned __int64)v267 < v266[3] )
        {
          *v267 = "TtcreateNavMesh";
          v268 = __rdtsc();
          v269 = (signed __int64)(v267 + 2);
          *(_DWORD *)(v269 - 8) = v268;
          v266[1] = v269;
        }
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                6i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_501;
        }
        hkaiNavMeshGenerationUtils::_createNavMesh(
          &v373,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
          (hkArray<int,hkContainerHeapAllocator> *)&v329,
          (hkArray<int,hkContainerHeapAllocator> *)&v336,
          (hkArray<int,hkContainerHeapAllocator> *)&v337,
          (hkArray<int,hkContainerHeapAllocator> *)&originalFaceIndices,
          v76,
          carverTree,
          v5,
          navMeshOut);
        if ( v373.m_enum )
        {
          hkErrStream::hkErrStream(&v414, &v493, 512);
          hkOstream::operator<<(
            (hkOstream *)&v414.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v493, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 966);
          v270 = &v414;
LABEL_498:
          hkOstream::~hkOstream((hkOstream *)&v270->vfptr);
          v302 = (hkVector4f *)v7->m_navMesh;
          if ( v302 )
          {
            v302[8] = (hkVector4f)aabbOut.m_quad;
            v302[9] = (hkVector4f)aabbOut.m_quad;
          }
          v15 = 2;
          goto LABEL_501;
        }
        v271 = navMeshOut;
        if ( navMeshOut->m_edges.m_size >= 0x400000 || navMeshOut->m_faces.m_size >= 0x400000 )
        {
          hkErrStream::hkErrStream(&v448, &v527, 512);
          hkOstream::operator<<(
            (hkOstream *)&v448.vfptr,
            "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to proc"
            "ess the mesh in pieces instead.");
          hkError::messageWarning(1349609975, &v527, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 967);
          v270 = &v448;
          goto LABEL_498;
        }
        cbCtx.m_unsimplifiedNavMesh = navMeshOut;
        if ( v540 )
        {
          v272 = mesh;
          navMeshOut->m_flags.m_storage |= 1u;
          v272->m_flags.m_storage |= 1u;
        }
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                6i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_501;
        }
        triangleVertices.m_size = 0;
        if ( triangleVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            triangleVertices.m_data,
            16 * triangleVertices.m_capacityAndFlags);
        triangleVertices.m_data = 0i64;
        triangleVertices.m_capacityAndFlags = 2147483648;
        v329.m_size = 0;
        if ( v329.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v329.m_data,
            4 * v329.m_capacityAndFlags);
        v329.m_data = 0i64;
        v329.m_capacityAndFlags = 2147483648;
        v336.m_size = 0;
        if ( v336.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v336.m_data,
            4 * v336.m_capacityAndFlags);
        v336.m_data = 0i64;
        v336.m_capacityAndFlags = 2147483648;
        v337.m_size = 0;
        if ( v337.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v337.m_data,
            4 * v337.m_capacityAndFlags);
        v337.m_data = 0i64;
        v337.m_capacityAndFlags = 2147483648;
        originalFaceIndices.m_size = 0;
        if ( originalFaceIndices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            originalFaceIndices.m_data,
            4 * originalFaceIndices.m_capacityAndFlags);
        originalFaceIndices.m_data = 0i64;
        originalFaceIndices.m_capacityAndFlags = 2147483648;
        v273 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v274 = (_QWORD *)v273[1];
        if ( (unsigned __int64)v274 < v273[3] )
        {
          *v274 = "Et";
          v275 = __rdtsc();
          v276 = (signed __int64)(v274 + 2);
          *(_DWORD *)(v276 - 8) = v275;
          v273[1] = v276;
        }
        if ( !v271->m_faces.m_size || !v271->m_edges.m_size )
        {
          hkErrStream::hkErrStream(&v446, &v525, 512);
          hkOstream::operator<<(
            (hkOstream *)&v446.vfptr,
            "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was conta"
            "ined in carvers.");
          hkError::messageWarning(1541620706, &v525, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 987);
          v288 = &v446;
LABEL_455:
          hkOstream::~hkOstream((hkOstream *)&v288->vfptr);
          v289 = (hkVector4f *)v7->m_navMesh;
          if ( v289 )
          {
            v289[8] = (hkVector4f)aabbOut.m_quad;
            v289[9] = (hkVector4f)aabbOut.m_quad;
          }
          goto LABEL_508;
        }
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                7i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        hkaiEdgeGeometryRaycaster::setupForEdgeConnections(edgeConnectionRayCaster);
        v277 = 0;
        LODWORD(v541) = v5->m_edgeConnectionIterations + 1;
        if ( (signed int)v541 > 0 )
        {
          while ( 1 )
          {
            v278 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v279 = (_QWORD *)v278[1];
            if ( (unsigned __int64)v279 < v278[3] )
            {
              *v279 = "TtconnectEdges";
              v280 = __rdtsc();
              v281 = (signed __int64)(v279 + 2);
              *(_DWORD *)(v281 - 8) = v280;
              v278[1] = v281;
            }
            hkaiNavMeshGenerationUtils::_connectEdges(
              &v380,
              v5,
              navMeshOut,
              edgeConnectionRayCaster,
              v277,
              (hkaiNavMeshGenerationProgressCallback *)cb,
              &cbCtx);
            if ( v380.m_enum )
              break;
            if ( navMeshOut->m_edges.m_size >= 0x400000 || navMeshOut->m_faces.m_size >= 0x400000 )
            {
              hkErrStream::hkErrStream(&v416, &v495, 512);
              hkOstream::operator<<(
                (hkOstream *)&v416.vfptr,
                "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to "
                "process the mesh in pieces instead.");
              hkError::messageWarning(1349609975, &v495, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1018);
              v248 = &v416;
              goto LABEL_376;
            }
            v282 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v283 = (_QWORD *)v282[1];
            if ( (unsigned __int64)v283 < v282[3] )
            {
              *v283 = "Et";
              v284 = __rdtsc();
              v285 = (signed __int64)(v283 + 2);
              *(_DWORD *)(v285 - 8) = v284;
              v282[1] = v285;
            }
            if ( ++v277 >= (signed int)v541 )
              goto LABEL_431;
          }
          hkErrStream::hkErrStream(&v418, &v497, 512);
          hkOstream::operator<<(
            (hkOstream *)&v418.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v497, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1017);
          v248 = &v418;
          goto LABEL_376;
        }
LABEL_431:
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                7i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        v286 = navMeshOut;
        hkaiNavMeshUtils::validate(navMeshOut, 0);
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                8i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        hkaiNavMeshUtils::compactVertices(&v368, v286, 0, 0);
        if ( v368.m_enum )
        {
          hkErrStream::hkErrStream(&v420, &v499, 512);
          hkOstream::operator<<(
            (hkOstream *)&v420.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v499, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1047);
          v287 = &v420;
          goto LABEL_505;
        }
        hkaiNavMeshGenerationUtils::_mergeVertices((hkResult *)&v541, v286, 0.00039999999);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v422, &v501, 512);
          hkOstream::operator<<(
            (hkOstream *)&v422.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v501, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1062);
          v287 = &v422;
          goto LABEL_505;
        }
        hkaiNavMeshGenerationUtils::_removeDegenerateFaces((hkResult *)&v541, v286);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v424, &v503, 512);
          hkOstream::operator<<(
            (hkOstream *)&v424.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v503, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1074);
          v287 = &v424;
          goto LABEL_505;
        }
        hkaiNavMeshUtils::validate(v286, 0);
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                8i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                9i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        hkaiNavMeshGenerationUtils::_pruneRegions((hkResult *)&v541, v286, &v5->m_up, &v5->m_regionPruningSettings);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v426, &v505, 512);
          hkOstream::operator<<(
            (hkOstream *)&v426.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v505, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1098);
          v287 = &v426;
          goto LABEL_505;
        }
        hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(
          (hkResult *)&v541,
          v286,
          v5,
          *(hkaiEdgeGeometryRaycaster **)&v330[0].m_enum,
          (hkaiNavMeshGenerationProgressCallback *)cb);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v428, &v507, 512);
          hkOstream::operator<<(
            (hkOstream *)&v428.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v507, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1109);
          v287 = &v428;
          goto LABEL_505;
        }
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                9i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        if ( !v286->m_faces.m_size )
        {
          hkErrStream::hkErrStream(&v430, &v509, 512);
          hkOstream::operator<<((hkOstream *)&v430.vfptr, "Erosion removed all faces from the nav mesh.");
          hkError::messageWarning(1209185063, &v509, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1115);
          v288 = &v430;
          goto LABEL_455;
        }
        if ( !(*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                cb,
                10i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        hkaiNavMeshGenerationUtils::_pruneRegions((hkResult *)&v541, v286, &v5->m_up, &v5->m_regionPruningSettings);
        if ( (_DWORD)v541 )
        {
          hkErrStream::hkErrStream(&v432, &v511, 512);
          hkOstream::operator<<(
            (hkOstream *)&v432.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v511, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1134);
          v287 = &v432;
          goto LABEL_505;
        }
        hkaiNavMeshUtils::compactVertices(&v382, v286, 0, 0);
        if ( v382.m_enum )
        {
          hkErrStream::hkErrStream(&v434, &v513, 512);
          hkOstream::operator<<(
            (hkOstream *)&v434.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v513, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1148);
          v287 = &v434;
          goto LABEL_505;
        }
        hkAabbUtil::calcAabb(v286->m_vertices.m_data, v286->m_vertices.m_size, &v286->m_aabb);
        v290 = _mm_shuffle_ps((__m128)LODWORD(v5->m_characterHeight), (__m128)LODWORD(v5->m_characterHeight), 0);
        v286->m_aabb.m_max.m_quad = _mm_add_ps(v290, v286->m_aabb.m_max.m_quad);
        v286->m_aabb.m_min.m_quad = _mm_sub_ps(v286->m_aabb.m_min.m_quad, v290);
        if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
               + 2))(
                cb,
                10i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_508;
        }
        if ( v5->m_enableSimplification.m_bool )
        {
          hkaiNavMesh::setEdgeDataStriding(v286, &v362, 1, 0);
          if ( v362.m_enum )
          {
            hkErrStream::hkErrStream(&v436, &v515, 512);
            hkOstream::operator<<(
              (hkOstream *)&v436.vfptr,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, &v515, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1177);
            v287 = &v436;
            goto LABEL_505;
          }
          v291 = mesh;
          v362.m_enum = hkaiNavMesh::setEdgeDataStriding(mesh, &v399, 1, 0)->m_enum;
          if ( v362.m_enum )
          {
            hkErrStream::hkErrStream(&v438, &v517, 512);
            hkOstream::operator<<(
              (hkOstream *)&v438.vfptr,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, &v517, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1179);
            v287 = &v438;
            goto LABEL_505;
          }
          hkaiNavMeshUtils::validate(v286, 0);
          v292 = v7->m_unsimplifiedNavMesh;
          if ( v292 )
          {
            hkaiNavMesh::copy(v292, &v384, v286);
            if ( v384.m_enum )
            {
              hkErrStream::hkErrStream(&v440, &v519, 512);
              hkOstream::operator<<(
                (hkOstream *)&v440.vfptr,
                "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation"
                " chapter in the User Guide.");
              hkError::messageWarning(1549811857, &v519, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1188);
              v287 = &v440;
              goto LABEL_505;
            }
          }
          v293 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v294 = (_QWORD *)v293[1];
          if ( (unsigned __int64)v294 < v293[3] )
          {
            *v294 = "Ttsimplify";
            v295 = __rdtsc();
            v296 = (signed __int64)(v294 + 2);
            *(_DWORD *)(v296 - 8) = v295;
            v293[1] = v296;
          }
          if ( v5->m_simplificationSettings.m_saveInputSnapshot.m_bool )
          {
            hkaiNavMeshSimplificationSnapshot::setMeshAndSettings(&v479, v286, v5);
            hkaiNavMeshSimplificationSnapshot::save(&v479);
          }
          v297 = hkaiNavMeshSimplificationUtils::_simplifyNavMesh(
                   v5,
                   v286,
                   v291,
                   *(hkaiEdgeGeometryRaycaster **)&v330[0].m_enum,
                   (hkaiNavMeshGenerationProgressCallback *)cb);
          if ( v297 != 2 )
            hkaiNavMesh::clear(v291);
          if ( v297 == 1 )
          {
            hkErrStream::hkErrStream(&v442, &v521, 512);
            hkOstream::operator<<(
              (hkOstream *)&v442.vfptr,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, &v521, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1210);
            v270 = &v442;
            goto LABEL_498;
          }
          if ( !v297 )
          {
            v15 = 0;
LABEL_501:
            v303 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v304 = (_QWORD *)v303[1];
            if ( (unsigned __int64)v304 < v303[3] )
            {
              *v304 = "Et";
              v305 = __rdtsc();
              v306 = (signed __int64)(v304 + 2);
              *(_DWORD *)(v306 - 8) = v305;
              v303[1] = v306;
            }
            goto LABEL_508;
          }
          cbCtx.m_simplifiedNavMesh = v291;
          v298 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v299 = (_QWORD *)v298[1];
          if ( (unsigned __int64)v299 < v298[3] )
          {
            *v299 = "Et";
            v300 = __rdtsc();
            v301 = (signed __int64)(v299 + 2);
            *(_DWORD *)(v301 - 8) = v300;
            v298[1] = v301;
          }
        }
        else
        {
          v291 = mesh;
        }
        if ( v5->m_setBestFaceCenters.m_bool && !v5->m_wallClimbingSettings.m_enableWallClimbing.m_bool )
          hkaiNavMeshUtils::setBestFaceCenters(v291, &v5->m_up);
        hkaiNavMesh::setEdgeDataStriding(v291, &v388, newStride, 0);
        if ( v388.m_enum == HK_SUCCESS )
        {
          hkaiNavMeshUtils::validate(v291, 1);
          if ( (*(unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data)(
                 cb,
                 21i64,
                 &cbCtx) )
          {
            if ( (*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
                  + 2))(
                   cb,
                   21i64,
                   &cbCtx) )
            {
              v15 = 5;
            }
            else
            {
              v15 = 0;
            }
          }
          else
          {
            v15 = 0;
          }
          goto LABEL_508;
        }
        hkErrStream::hkErrStream(&v444, &v523, 512);
        hkOstream::operator<<(
          (hkOstream *)&v444.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v523, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1232);
        v287 = &v444;
        goto LABEL_505;
      }
    }
    else
    {
      *(_QWORD *)&v330[0].m_enum = 0i64;
    }
    hkErrStream::hkErrStream(&v450, &v529, 512);
    hkOstream::operator<<(
      (hkOstream *)&v450.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v529, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 927);
    v287 = &v450;
LABEL_505:
    hkOstream::~hkOstream((hkOstream *)&v287->vfptr);
    v307 = (hkVector4f *)v7->m_navMesh;
    if ( v307 )
    {
      v307[8] = (hkVector4f)aabbOut.m_quad;
      v307[9] = (hkVector4f)aabbOut.m_quad;
    }
    goto LABEL_507;
  }
  while ( 1 )
  {
    v154 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v155 = v154[1];
    if ( v155 < v154[3] )
    {
      *(_QWORD *)v155 = "Ltcsg";
      *(_QWORD *)(v155 + 16) = "Stwalkable";
      v156 = __rdtsc();
      *(_DWORD *)(v155 + 8) = v156;
      v154[1] = v155 + 24;
    }
    if ( !(*((unsigned __int8 (__fastcall **)(hkBitField *, signed __int64, _QWORD, _QWORD, hkaiNavMeshGenerationProgressCallbackContext *))cb->m_storage.m_words.m_data
           + 1))(
            cb,
            3i64,
            (unsigned int)v541,
            (unsigned int)v76->m_triangles.m_size,
            &cbCtx) )
    {
      v15 = 0;
      goto LABEL_339;
    }
    if ( !((walkableInOut->m_storage.m_words.m_data[(signed __int64)(signed int)v541 >> 5] >> ((unsigned __int8)v541 & 0x1F)) & 1) )
      goto LABEL_306;
    hkGeometry::clear(&cuttingGeom);
    hkaiEdgeGeometry::clear(&cuttingEdgeGeometryOut);
    hkaiEdgeGeometry::clear(&geomOut);
    hkaiSelfIntersectBooleanFilter2::reset(&v475);
    hkaiEdgeGeometry::clear(&geom);
    hkaiBooleanOperation::clear(&v478);
    trisOut.m_size = 0;
    triConnectivityOut.m_size = 0;
    hkaiNavMeshGenerationUtils::getTriangleVerts(v76, v5, (int)v541, &vertsOut);
    if ( v540 )
    {
      v157 = _mm_sub_ps(v405, vertsOut.m_quad);
      v158 = _mm_sub_ps(v406, vertsOut.m_quad);
      v159 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v157),
               _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), v158));
      v160 = _mm_shuffle_ps(v159, v159, 201);
      v161 = _mm_mul_ps(v160, v160);
      v162 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
               _mm_shuffle_ps(v161, v161, 170));
      v163 = _mm_rsqrt_ps(v162);
      v476 = v162;
      v164 = _mm_mul_ps(
               _mm_xor_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v162, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v163, v162), v163)),
                       _mm_mul_ps(*(__m128 *)_xmm, v163))),
                   v160),
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64)),
               v141);
    }
    else
    {
      v164 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v141), v5->m_up.m_quad);
    }
    extrudeDirection.m_quad = v164;
    v165 = (_DWORD)v541 + 1;
    geomA.m_faces.m_data[1].m_faceIndex = (_DWORD)v541 + 1;
    v342 = v165;
    v166 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v164);
    rayDir.m_quad = v166;
    *geomA.m_vertices.m_data = (hkVector4f)vertsOut.m_quad;
    geomA.m_vertices.m_data[1].m_quad = v405;
    geomA.m_vertices.m_data[2].m_quad = v406;
    v167 = _mm_max_ps(_mm_max_ps(vertsOut.m_quad, v405), v406);
    v168 = _mm_min_ps(_mm_min_ps(vertsOut.m_quad, v405), v406);
    extrudedTriAabb.m_max.m_quad = _mm_max_ps(v167, _mm_add_ps(v167, v166));
    extrudedTriAabb.m_min.m_quad = _mm_min_ps(v168, _mm_add_ps(v168, v166));
    v169 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v170 = (_QWORD *)v169[1];
    if ( (unsigned __int64)v170 < v169[3] )
    {
      *v170 = "StgetNearbyCuttingGeometry";
      v171 = __rdtsc();
      v172 = (signed __int64)(v170 + 2);
      *(_DWORD *)(v172 - 8) = v171;
      v169[1] = v172;
    }
    hkaiNavMeshGenerationUtils::getNearbyCuttingGeometry(
      &v331,
      &extrudedTriAabb,
      v76,
      (int)v541,
      v5,
      v116,
      &cuttingGeom,
      &cuttingEdgeGeometryOut);
    if ( v331.m_enum )
    {
      hkErrStream::hkErrStream(&v441, &v485, 512);
      hkOstream::operator<<(
        (hkOstream *)&v441.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v485, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 761);
      v214 = &v441;
      goto LABEL_335;
    }
    v173 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v174 = (_QWORD *)v173[1];
    if ( (unsigned __int64)v174 < v173[3] )
    {
      *v174 = "Stextrude";
      v175 = __rdtsc();
      v176 = (signed __int64)(v174 + 2);
      *(_DWORD *)(v176 - 8) = v175;
      v173[1] = v176;
    }
    hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(&v477, &v375, &cuttingEdgeGeometryOut, &extrudeDirection, &geomOut);
    if ( v375.m_enum )
    {
      hkErrStream::hkErrStream(&v457, &v483, 512);
      hkOstream::operator<<(
        (hkOstream *)&v457.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v483, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 776);
      v214 = &v457;
      goto LABEL_335;
    }
    hkaiGeometryCarverExtractor::addCarversInRegion(&v370, &geomOut, carverTree, &extrudedTriAabb);
    if ( v370.m_enum )
    {
      hkErrStream::hkErrStream(&v439, &v481, 512);
      hkOstream::operator<<(
        (hkOstream *)&v439.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v481, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 798);
      v214 = &v439;
      goto LABEL_335;
    }
    v177 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v178 = (_QWORD *)v177[1];
    if ( (unsigned __int64)v178 < v177[3] )
    {
      *v178 = "Stsubtract";
      v179 = __rdtsc();
      v180 = (signed __int64)(v178 + 2);
      *(_DWORD *)(v180 - 8) = v179;
      v177[1] = v180;
    }
    v181 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v182 = (_QWORD *)v181[1];
    if ( (unsigned __int64)v182 < v181[3] )
    {
      *v182 = "TtsetFilter";
      v183 = __rdtsc();
      v184 = (signed __int64)(v182 + 2);
      *(_DWORD *)(v184 - 8) = v183;
      v181[1] = v184;
    }
    hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&v475, &v374, &geomA, &geomOut);
    if ( v374.m_enum )
    {
      hkErrStream::hkErrStream(&v465, &v510, 512);
      hkOstream::operator<<(
        (hkOstream *)&v465.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v510, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 814);
      hkOstream::~hkOstream((hkOstream *)&v465.vfptr);
      v215 = (hkVector4f *)v7->m_navMesh;
      if ( v215 )
      {
        v215[8] = (hkVector4f)aabbOut.m_quad;
        v215[9] = (hkVector4f)aabbOut.m_quad;
      }
      v216 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v217 = (_QWORD *)v216[1];
      if ( (unsigned __int64)v217 < v216[3] )
      {
        *v217 = "Et";
        v218 = __rdtsc();
        v15 = 2;
        v219 = (signed __int64)(v217 + 2);
        *(_DWORD *)(v219 - 8) = v218;
        v216[1] = v219;
        goto LABEL_339;
      }
      goto LABEL_337;
    }
    v185 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v186 = (_QWORD *)v185[1];
    if ( (unsigned __int64)v186 < v185[3] )
    {
      *v186 = "Et";
      v187 = __rdtsc();
      v188 = (signed __int64)(v186 + 2);
      *(_DWORD *)(v188 - 8) = v187;
      v185[1] = v188;
    }
    hkaiBooleanOperation::subtract(&v478, &v372, &geomA, &geomOut, &geom, 0i64, (hkaiBooleanFilter *)&v475.vfptr);
    if ( v372.m_enum )
    {
      hkErrStream::hkErrStream(&v437, &v524, 512);
      hkOstream::operator<<(
        (hkOstream *)&v437.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v524, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 818);
      v214 = &v437;
LABEL_335:
      hkOstream::~hkOstream((hkOstream *)&v214->vfptr);
      v220 = (hkVector4f *)v7->m_navMesh;
      if ( v220 )
      {
        v220[8] = (hkVector4f)aabbOut.m_quad;
        v220[9] = (hkVector4f)aabbOut.m_quad;
      }
LABEL_337:
      v15 = 2;
      goto LABEL_339;
    }
    if ( v5->m_checkEdgeGeometryConsistency.m_bool )
    {
      v189 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v190 = (_QWORD *)v189[1];
      if ( (unsigned __int64)v190 < v189[3] )
      {
        *v190 = "TtcheckConsistency";
        v191 = __rdtsc();
        v192 = (signed __int64)(v190 + 2);
        *(_DWORD *)(v192 - 8) = v191;
        v189[1] = v192;
      }
      v193 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v194 = (_QWORD *)v193[1];
      if ( (unsigned __int64)v194 < v193[3] )
      {
        *v194 = "Et";
        v195 = __rdtsc();
        v196 = (signed __int64)(v194 + 2);
        *(_DWORD *)(v196 - 8) = v195;
        v193[1] = v196;
      }
    }
    v197 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v198 = (_QWORD *)v197[1];
    if ( (unsigned __int64)v198 < v197[3] )
    {
      *v198 = "Sttriangulate";
      v199 = __rdtsc();
      v200 = (signed __int64)(v198 + 2);
      *(_DWORD *)(v200 - 8) = v199;
      v197[1] = v200;
    }
    trisPerFaceOut.m_data = (int *)&v351;
    trisPerFaceOut.m_size = 0;
    trisPerFaceOut.m_capacityAndFlags = -2147483646;
    hkaiNavMeshGenerationUtils::_triangulate(
      &v378,
      v5,
      &geom,
      &faceEdges,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      0i64,
      v540);
    if ( v378.m_enum )
      break;
    hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
      &v383,
      &geom.m_vertices,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      0i64,
      v5);
    if ( v383.m_enum )
    {
      hkErrStream::hkErrStream(&v410, &v538, 512);
      hkOstream::operator<<(
        (hkOstream *)&v410.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v538, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 844);
      v212 = &v410;
      goto LABEL_322;
    }
    v379 = triangleVertices.m_size;
    hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v377,
      (hkResult *)&triangleVertices,
      (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(triangleVertices.m_size
                                                                          + geom.m_vertices.m_size),
      -1,
      sizeElem);
    if ( v377 )
    {
      hkErrStream::hkErrStream(&v469, &v506, 512);
      hkOstream::operator<<(
        (hkOstream *)&v469.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v506, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 867);
      v212 = &v469;
      goto LABEL_322;
    }
    hkArrayBase<hkVector4f>::_append(
      &triangleVertices,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      geom.m_vertices.m_data,
      geom.m_vertices.m_size);
    v327 = v329.m_size;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v387,
      (hkResult *)&v329,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v329.m_size + trisOut.m_size),
      -1,
      sizeElema);
    if ( v387 )
    {
      hkErrStream::hkErrStream(&v433, &v522, 512);
      hkOstream::operator<<(
        (hkOstream *)&v433.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v522, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 872);
      v212 = &v433;
      goto LABEL_322;
    }
    hkArrayBase<unsigned int>::_append(
      &v329,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (const unsigned int *)trisOut.m_data,
      trisOut.m_size);
    v201 = 0;
    if ( trisOut.m_size > 0 )
    {
      v202 = v379;
      v203 = v327;
      do
      {
        ++v201;
        ++v203;
        v329.m_data[v203 - 1] += v202;
      }
      while ( v201 < trisOut.m_size );
    }
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v385,
      (hkResult *)&v337,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v337.m_size + triConnectivityOut.m_size),
      -1,
      sizeElemb);
    if ( v385 )
    {
      hkErrStream::hkErrStream(&v453, &v504, 512);
      hkOstream::operator<<(
        (hkOstream *)&v453.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v504, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 880);
      v212 = &v453;
      goto LABEL_322;
    }
    hkArrayBase<unsigned int>::_append(
      &v337,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (const unsigned int *)triConnectivityOut.m_data,
      triConnectivityOut.m_size);
    hkArrayBase<unsigned int>::_append(
      &v336,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (const unsigned int *)trisPerFaceOut.m_data,
      trisPerFaceOut.m_size);
    v204 = 0;
    if ( trisPerFaceOut.m_size > 0 )
    {
      v205 = originalFaceIndices.m_size;
      v206 = v342;
      do
      {
        ++v204;
        originalFaceIndices.m_data[v205] = v206;
        v205 = originalFaceIndices.m_size++ + 1;
      }
      while ( v204 < trisPerFaceOut.m_size );
    }
    v342 = trisOut.m_size / 3;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v389,
      (hkResult *)&hitFaces,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(trisOut.m_size / 3 + hitFaces.m_size),
      -1,
      sizeElemc);
    if ( v389 )
    {
      hkErrStream::hkErrStream(&v431, &v530, 512);
      hkOstream::operator<<(
        (hkOstream *)&v431.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v530, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 892);
      v212 = &v431;
      goto LABEL_322;
    }
    v207 = hitFaces.m_size;
    hitFaces.m_size += v342;
    hkaiNavMeshGenerationUtils::raycastAgainstCuttingGeometry(
      v330,
      (int)v541,
      (hkArrayBase<hkVector4f> *)&geom.m_vertices.m_data,
      (hkArrayBase<int> *)&trisOut.m_data,
      &hitFaces.m_data[v207],
      &cuttingGeom,
      &characterHeight,
      &rayDir);
    if ( v330[0].m_enum )
    {
      hkErrStream::hkErrStream(&v463, &v502, 512);
      hkOstream::operator<<(
        (hkOstream *)&v463.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v502, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 896);
      v212 = &v463;
      goto LABEL_322;
    }
    trisPerFaceOut.m_size = 0;
    if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        trisPerFaceOut.m_data,
        4 * trisPerFaceOut.m_capacityAndFlags);
    trisPerFaceOut.m_data = 0i64;
    trisPerFaceOut.m_capacityAndFlags = 2147483648;
LABEL_306:
    v208 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v209 = (_QWORD *)v208[1];
    if ( (unsigned __int64)v209 < v208[3] )
    {
      *v209 = "lt";
      v210 = __rdtsc();
      v211 = (signed __int64)(v209 + 2);
      *(_DWORD *)(v211 - 8) = v210;
      v208[1] = v211;
    }
    LODWORD(v541) = (_DWORD)v541 + 1;
    if ( (signed int)v541 >= v76->m_triangles.m_size )
      goto LABEL_309;
  }
  hkErrStream::hkErrStream(&v455, &v480, 512);
  hkOstream::operator<<(
    (hkOstream *)&v455.vfptr,
    "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter in the User Guide.");
  hkError::messageWarning(1549811857, &v480, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 840);
  v212 = &v455;
LABEL_322:
  hkOstream::~hkOstream((hkOstream *)&v212->vfptr);
  v213 = (hkVector4f *)v7->m_navMesh;
  if ( v213 )
  {
    v213[8] = (hkVector4f)aabbOut.m_quad;
    v213[9] = (hkVector4f)aabbOut.m_quad;
  }
  v15 = 2;
  trisPerFaceOut.m_size = 0;
  if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      trisPerFaceOut.m_data,
      4 * trisPerFaceOut.m_capacityAndFlags);
  trisPerFaceOut.m_data = 0i64;
  trisPerFaceOut.m_capacityAndFlags = 2147483648;
LABEL_339:
  v221 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v222 = (_QWORD *)v221[1];
  if ( (unsigned __int64)v222 < v221[3] )
  {
    *v222 = "lt";
    v223 = __rdtsc();
    v224 = (signed __int64)(v222 + 2);
    *(_DWORD *)(v224 - 8) = v223;
    v221[1] = v224;
  }
LABEL_341:
  triConnectivityOut.m_size = 0;
  if ( triConnectivityOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triConnectivityOut.m_data,
      4 * triConnectivityOut.m_capacityAndFlags);
  triConnectivityOut.m_data = 0i64;
  triConnectivityOut.m_capacityAndFlags = 2147483648;
  trisOut.m_size = 0;
  if ( trisOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      trisOut.m_data,
      4 * trisOut.m_capacityAndFlags);
  trisOut.m_data = 0i64;
  trisOut.m_capacityAndFlags = 2147483648;
  hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&faceEdges);
  hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v477);
  hkaiBooleanOperation::~hkaiBooleanOperation(&v478);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
  hkaiSelfIntersectBooleanFilter2::~hkaiSelfIntersectBooleanFilter2(&v475);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
  hkGeometry::~hkGeometry(&cuttingGeom);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
LABEL_511:
  hitFaces.m_size = 0;
  if ( hitFaces.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      hitFaces.m_data,
      4 * hitFaces.m_capacityAndFlags);
  hitFaces.m_data = 0i64;
  hitFaces.m_capacityAndFlags = 2147483648;
  originalFaceIndices.m_size = 0;
  if ( originalFaceIndices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      originalFaceIndices.m_data,
      4 * originalFaceIndices.m_capacityAndFlags);
  originalFaceIndices.m_data = 0i64;
  originalFaceIndices.m_capacityAndFlags = 2147483648;
  v337.m_size = 0;
  if ( v337.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v337.m_data,
      4 * v337.m_capacityAndFlags);
  v337.m_data = 0i64;
  v337.m_capacityAndFlags = 2147483648;
  v336.m_size = 0;
  if ( v336.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v336.m_data,
      4 * v336.m_capacityAndFlags);
  v336.m_data = 0i64;
  v336.m_capacityAndFlags = 2147483648;
  v329.m_size = 0;
  if ( v329.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v329.m_data,
      4 * v329.m_capacityAndFlags);
  v329.m_data = 0i64;
  v329.m_capacityAndFlags = 2147483648;
  triangleVertices.m_size = 0;
  if ( triangleVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triangleVertices.m_data,
      16 * triangleVertices.m_capacityAndFlags);
  triangleVertices.m_data = 0i64;
  triangleVertices.m_capacityAndFlags = 2147483648;
LABEL_524:
  if ( v116 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v116->vfptr);
LABEL_526:
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v401);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v403);
  v77 = v335;
LABEL_531:
  if ( v77 )
    hkReferencedObject::removeReference(v77);
  hkReferencedObject::removeReference((hkReferencedObject *)&carverTree->vfptr);
LABEL_538:
  v310 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v311 = &carvers.m_data[v310];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor'(v311);
      --v311;
      --v310;
    }
    while ( v310 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 2147483648;
  hkPointerMap<int,int,hkContainerHeapAllocator>::~hkPointerMap<int,int,hkContainerHeapAllocator>((hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v392);
LABEL_544:
  v353 = 0;
  if ( v354 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v354 & 0x3FFFFFFF);
  array = 0i64;
  v354 = 2147483648;
LABEL_548:
  v391 = &hkaiNavMeshGenerationProgressCallback::`vftable';
  hkReferencedObject::removeReference(v398);
  hkReferencedObject::removeReference(v400);
LABEL_555:
  v314 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v315 = (_QWORD *)v314[1];
  v316 = v314;
  if ( (unsigned __int64)v315 < v314[3] )
  {
    *v315 = "Et";
    v317 = __rdtsc();
    v318 = (signed __int64)(v315 + 2);
    *(_DWORD *)(v318 - 8) = v317;
    v316[1] = v318;
  }
  return v15;
}v317;
    v316[1] = v318;
  }
  return v15;
}ptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v337.m_data,
      4 * v337.m_capacityAndFlags);
  v337.m_data = 0i64;
  v337.m_capacityAndFlags = 2147483648;
  v336.m_size = 0;
  if ( v336.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v336.m_data,
      4 * v336.m_capacityAndFlags);
  v336.m_data = 0i64;
  v336.m_capacityAndFlags = 2147483648;
  v329.m_size = 0;
  if ( v329.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v329.m_data,
      4 * v329.m_capacityAndFlags);
  v329.m_data = 0i64;
  v329.m_capacityAndFlags = 2147483648;
  triangleVertices.m_size = 0;
  if ( triangleVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triangleVertices.m_data,
      16 * triangleVertices.m_capacityAndFlags);
  triangleVertices.m_data = 0i64;
  triangleVertices.m_capacityAndFlags = 2147483648;
LABEL_524:
  if ( v116 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v116->vfptr);
LABEL_526:
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v401);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v403);
  v77 = v335;
LABEL_531:
  if ( v77 )
    hkReferencedObject::removeReference(v77);
  hkReferencedObject::removeReference

// File Line: 1244
// RVA: 0xB77920
void __fastcall hkaiNavMeshGenerationUtils::getTriangleVerts(hkGeometry *triMeshIn, hkaiNavMeshGenerationSettings *settings, int t, hkVector4f *vertsOut)
{
  hkVector4f *v4; // rdx
  hkGeometry::Triangle *v5; // r8
  signed __int64 v6; // rax
  hkVector4f v7; // xmm0
  signed __int64 v8; // rax

  v4 = triMeshIn->m_vertices.m_data;
  v5 = &triMeshIn->m_triangles.m_data[t];
  v6 = v5->m_b;
  *vertsOut = v4[v5->m_a];
  v7.m_quad = (__m128)v4[v6];
  v8 = v5->m_c;
  vertsOut[1] = (hkVector4f)v7.m_quad;
  vertsOut[2] = v4[v8];
}

// File Line: 1249
// RVA: 0xB76E80
hkResult *__fastcall hkaiNavMeshGenerationUtils::buildCuttingGeomTree(hkResult *result, hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap, hkGeometry *triMeshIn, hkaiNavMeshGenerationSettings *input, hkBitField *cuttingTriangles, hkcdDynamicAabbTree *cuttingGeomTree)
{
  int v6; // esi
  hkcdDynamicAabbTree *v7; // rbp
  hkGeometry *v8; // r13
  hkResult *v9; // r14
  hkaiNavMeshGenerationSettings *v10; // r12
  hkResult *v11; // rax
  signed int v12; // ebx
  hkBitField *v13; // r15
  __int64 v14; // rdi
  hkAabb aabb; // [rsp+20h] [rbp-78h]
  hkVector4f vertsOut; // [rsp+40h] [rbp-58h]
  __m128 v17; // [rsp+50h] [rbp-48h]
  __m128 v18; // [rsp+60h] [rbp-38h]
  hkResult resulta; // [rsp+B0h] [rbp+18h]

  v6 = triMeshIn->m_triangles.m_size;
  v7 = cuttingGeomTree;
  v8 = triMeshIn;
  v9 = result;
  v10 = input;
  hkcdDynamicAabbTree::reserveLeaves(cuttingGeomTree, &resulta, triMeshIn->m_triangles.m_size);
  if ( resulta.m_enum )
  {
    v9->m_enum = 1;
    v11 = v9;
  }
  else
  {
    v12 = 0;
    if ( v6 > 0 )
    {
      v13 = cuttingTriangles;
      v14 = 0i64;
      do
      {
        if ( (v13->m_storage.m_words.m_data[v14 >> 5] >> (v12 & 0x1F)) & 1 )
        {
          hkaiNavMeshGenerationUtils::getTriangleVerts(v8, v10, v12, &vertsOut);
          aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(vertsOut.m_quad, v17), v18);
          aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(vertsOut.m_quad, v17), v18);
          hkcdDynamicAabbTree::insert(v7, &aabb, v12);
        }
        ++v12;
        ++v14;
      }
      while ( v12 < v6 );
    }
    hkcdDynamicAabbTree::rebuildFast(v7, 1);
    v9->m_enum = 0;
    v11 = v9;
  }
  return v11;
}

// File Line: 1279
// RVA: 0xB76FC0
bool __fastcall hkaiNavMeshGenerationUtils::isTriangleWalkable(hkGeometry *triMeshIn, int t, hkaiNavMeshGenerationSettings *input, hkaiCarverTree *carverTree, hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap)
{
  hkGeometry::Triangle *v5; // rax
  int v6; // edi
  bool v7; // bp
  hkaiNavMeshGenerationSettings *v8; // rbx
  hkGeometry *v9; // rsi
  hkaiCarverTree *v10; // r15
  int v11; // er14
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  int v19; // eax
  hkVector4f normal; // [rsp+20h] [rbp-A8h]
  hkArrayBase<hkVector4f> points; // [rsp+30h] [rbp-98h]
  __m128 v23; // [rsp+40h] [rbp-88h]
  hkVector4f vertsOut; // [rsp+50h] [rbp-78h]
  hkVector4f B; // [rsp+60h] [rbp-68h]
  hkVector4f C; // [rsp+70h] [rbp-58h]

  v5 = triMeshIn->m_triangles.m_data;
  v6 = t;
  v7 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v8 = input;
  v9 = triMeshIn;
  v10 = carverTree;
  v11 = v5[t].m_material;
  if ( !(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&materialMap->m_map.m_elem,
           (unsigned int)v5[t].m_material,
           input->m_defaultConstructionProperties.m_storage) & 1) )
    return 0;
  hkaiNavMeshGenerationUtils::getTriangleVerts(v9, v8, v6, &vertsOut);
  if ( !v7 )
  {
    points.m_capacityAndFlags = -2147483647;
    points.m_data = (hkVector4f *)&v23;
    points.m_size = 1;
    v12 = _mm_sub_ps(C.m_quad, vertsOut.m_quad);
    v13 = _mm_sub_ps(B.m_quad, vertsOut.m_quad);
    v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
    v15 = _mm_shuffle_ps(v14, v14, 201);
    v23 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(vertsOut.m_quad, B.m_quad), C.m_quad), (__m128)xmmword_141A711C0);
    v16 = _mm_mul_ps(v15, v15);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    normal.m_quad = _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v17, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                          _mm_mul_ps(*(__m128 *)_xmm, v18))),
                      v15);
    v19 = hkaiNavMeshGenerationSettings::isWalkableBySlope(v8, &normal, &points, v11);
    points.m_size = 0;
    if ( !v19 )
    {
      if ( points.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          points.m_data,
          16 * points.m_capacityAndFlags);
      return 0;
    }
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
  }
  return hkaiCarverTree::carversContainTriangle(v10, &vertsOut, &B, &C) == 0;
}

// File Line: 1323
// RVA: 0xB771E0
bool __fastcall hkaiNavMeshGenerationUtils::isTriangleCutting(hkGeometry *triMeshIn, int t, hkaiNavMeshGenerationSettings *input, hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap)
{
  return ((unsigned __int8)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&materialMap->m_map.m_elem,
                             (unsigned int)triMeshIn->m_triangles.m_data[t].m_material,
                             input->m_defaultConstructionProperties.m_storage) >> 1) & 1;
}

// File Line: 1361
// RVA: 0xB78A20
void __fastcall `anonymous namespace'::Prism::initFromExtrudedTriangle(Prism *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *normal, hkSimdFloat32 *extrusionLength)
{
  hkVector4f *v6; // r10
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  hkVector4f v16; // xmm6
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  hkVector4f v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  hkVector4f v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  hkVector4f v40; // xmm3
  __m128 v41; // xmm2

  v6 = normal;
  this->m_a = (hkVector4f)a->m_quad;
  this->m_b = (hkVector4f)b->m_quad;
  this->m_c = (hkVector4f)c->m_quad;
  this->m_normalTimesExtrusion.m_quad = _mm_mul_ps(normal->m_quad, extrusionLength->m_real);
  v7 = _mm_sub_ps(c->m_quad, a->m_quad);
  v8 = _mm_sub_ps(b->m_quad, a->m_quad);
  v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(v13, *(__m128 *)_xmm))),
          v10);
  v15 = _mm_mul_ps(v14, a->m_quad);
  v16.m_quad = _mm_shuffle_ps(
                 v14,
                 _mm_unpackhi_ps(
                   v14,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                       _mm_shuffle_ps(v15, v15, 170)))),
                 196);
  this->m_bottomPlane = (hkVector4f)v16.m_quad;
  v17 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(normal->m_quad, extrusionLength->m_real), a->m_quad), v16.m_quad);
  this->m_topPlane.m_quad = _mm_shuffle_ps(
                              v16.m_quad,
                              _mm_unpackhi_ps(
                                v16.m_quad,
                                _mm_sub_ps(
                                  (__m128)0i64,
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                                    _mm_shuffle_ps(v17, v17, 170)))),
                              196);
  v18 = _mm_sub_ps(b->m_quad, a->m_quad);
  v19 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 201), v18),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), normal->m_quad));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v20, v20);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v22, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                     _mm_mul_ps(v23, *(__m128 *)_xmm))),
                 v20);
  this->m_planeAB = (hkVector4f)v24.m_quad;
  v25 = _mm_mul_ps(a->m_quad, v24.m_quad);
  this->m_planeAB.m_quad = _mm_shuffle_ps(
                             v24.m_quad,
                             _mm_unpackhi_ps(
                               v24.m_quad,
                               _mm_sub_ps(
                                 (__m128)0i64,
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                                   _mm_shuffle_ps(v25, v25, 170)))),
                             196);
  v26 = _mm_sub_ps(c->m_quad, b->m_quad);
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 201), v26),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), normal->m_quad));
  v28 = _mm_shuffle_ps(v27, v27, 201);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v30, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                     _mm_mul_ps(v31, *(__m128 *)_xmm))),
                 v28);
  this->m_planeBC = (hkVector4f)v32.m_quad;
  v33 = _mm_mul_ps(b->m_quad, v32.m_quad);
  this->m_planeBC.m_quad = _mm_shuffle_ps(
                             v32.m_quad,
                             _mm_unpackhi_ps(
                               v32.m_quad,
                               _mm_sub_ps(
                                 (__m128)0i64,
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                   _mm_shuffle_ps(v33, v33, 170)))),
                             196);
  v34 = _mm_sub_ps(a->m_quad, c->m_quad);
  v35 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 201), v34),
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), normal->m_quad));
  v36 = _mm_shuffle_ps(v35, v35, 201);
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v38, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                     _mm_mul_ps(v39, *(__m128 *)_xmm))),
                 v36);
  this->m_planeCA = (hkVector4f)v40.m_quad;
  v41 = _mm_mul_ps(v40.m_quad, c->m_quad);
  this->m_planeCA.m_quad = _mm_shuffle_ps(
                             v40.m_quad,
                             _mm_unpackhi_ps(
                               v40.m_quad,
                               _mm_sub_ps(
                                 (__m128)0i64,
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                                   _mm_shuffle_ps(v41, v41, 170)))),
                             196);
}

// File Line: 1391
// RVA: 0xB78D60
bool __fastcall `anonymous namespace'::Prism::testPlaneAgainstTri(Prism *this, hkVector4f *plane, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *testPoint)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  float v10; // xmm5_4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  float v19; // xmm1_4
  bool result; // al

  v6 = _mm_mul_ps(plane->m_quad, testPoint->m_quad);
  v7 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, plane->m_quad), 196);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_mul_ps(a->m_quad, plane->m_quad);
  v10 = COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 177)) + v8.m128_f32[0];
  v11 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, plane->m_quad), 196);
  v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v13 = _mm_mul_ps(b->m_quad, plane->m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, plane->m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(plane->m_quad, c->m_quad);
  v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, plane->m_quad), 196);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
  v19 = 0.0 - 0.00000011920929;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 177)) + v12.m128_f32[0]) * v10) >= (float)(0.0 - 0.00000011920929)
    || (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 177)) + v15.m128_f32[0]) * v10) >= v19 )
  {
    result = 0;
  }
  else
  {
    result = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 177)) + v18.m128_f32[0]) * v10) < v19;
  }
  return result;
}

// File Line: 1416
// RVA: 0xB79060
bool __fastcall `anonymous namespace'::Prism::hasSeparatingPlaneForTri(Prism *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  hkVector4f *v4; // rbp
  hkVector4f *testPoint; // r14
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rsi
  Prism *v8; // rbx
  hkVector4f v10; // [rsp+30h] [rbp-18h]

  v4 = a;
  testPoint = &this->m_a;
  v6 = c;
  v7 = b;
  v8 = this;
  if ( `anonymous namespace'::Prism::testPlaneAgainstTriFast(this, &this->m_topPlane, a, b, c, &this->m_a)
    || `anonymous namespace'::Prism::testPlaneAgainstTriFast(v8, &v8->m_planeAB, v4, v7, v6, &v8->m_c)
    || `anonymous namespace'::Prism::testPlaneAgainstTriFast(v8, &v8->m_planeBC, v4, v7, v6, testPoint)
    || `anonymous namespace'::Prism::testPlaneAgainstTriFast(v8, &v8->m_planeCA, v4, v7, v6, &v8->m_b) )
  {
    return 1;
  }
  v10.m_quad = _mm_add_ps(v8->m_normalTimesExtrusion.m_quad, testPoint->m_quad);
  return `anonymous namespace'::Prism::testPlaneAgainstTriFast(v8, &v8->m_bottomPlane, v4, v7, v6, &v10) != 0;
}

// File Line: 1434
// RVA: 0xB78E30
bool __fastcall `anonymous namespace'::Prism::testPlaneAgainstTriFast(Prism *this, hkVector4f *plane, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *testPoint)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm6

  v6 = _mm_mul_ps(b->m_quad, plane->m_quad);
  v7 = _mm_mul_ps(a->m_quad, plane->m_quad);
  v8 = _mm_mul_ps(c->m_quad, plane->m_quad);
  v9 = _mm_mul_ps(plane->m_quad, testPoint->m_quad);
  v10 = _mm_shuffle_ps(v7, v6, 68);
  v11 = _mm_shuffle_ps(v8, v9, 68);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_shuffle_ps(_mm_shuffle_ps(v7, v6, 238), _mm_shuffle_ps(v8, v9, 238), 136),
            _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255)),
          _mm_add_ps(_mm_shuffle_ps(v10, v11, 221), _mm_shuffle_ps(v10, v11, 136)));
  return (_mm_movemask_ps(
            _mm_cmpltps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_shuffle_ps(v12, v12, 255), 0x1Fu), 0x1Fu),
                v12),
              _mm_sub_ps((__m128)0i64, *(__m128 *)&epsilon))) & 7) == 7;
}

// File Line: 1446
// RVA: 0xB78ED0
bool __fastcall `anonymous namespace'::Prism::testTriPlaneAgainstPrism(Prism *this, hkVector4f *ta, hkVector4f *tb, hkVector4f *tc)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm2

  v4 = _mm_sub_ps(tb->m_quad, ta->m_quad);
  v5 = _mm_sub_ps(tc->m_quad, ta->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))),
          v7);
  v12 = _mm_mul_ps(ta->m_quad, v11);
  v13 = _mm_shuffle_ps(
          v11,
          _mm_unpackhi_ps(
            v11,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)))),
          196);
  v14 = _mm_mul_ps(this->m_c.m_quad, v13);
  v15 = _mm_mul_ps(this->m_a.m_quad, v13);
  v16 = _mm_shuffle_ps(v14, v14, 68);
  v17 = _mm_mul_ps(this->m_b.m_quad, v13);
  v18 = _mm_shuffle_ps(v15, v17, 68);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_shuffle_ps(_mm_shuffle_ps(v15, v17, 238), _mm_shuffle_ps(v14, v14, 238), 136),
            _mm_shuffle_ps(v13, v13, 255)),
          _mm_add_ps(_mm_shuffle_ps(v18, v16, 221), _mm_shuffle_ps(v18, v16, 136)));
  v20 = _mm_mul_ps(this->m_normalTimesExtrusion.m_quad, v13);
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170)),
          v19);
  return (_mm_movemask_ps(_mm_cmpltps(*(__m128 *)&epsilon, _mm_min_ps(v19, v21))) & 7) == 7
      || (_mm_movemask_ps(
            _mm_cmpltps(
              _mm_max_ps(v19, v21),
              _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                *(__m128 *)&epsilon))) & 7) == 7;
}

// File Line: 1472
// RVA: 0xB77220
hkResult *__fastcall hkaiNavMeshGenerationUtils::getNearbyCuttingGeometry(hkResult *result, hkAabb *extrudedTriAabb, hkGeometry *triMeshIn, int t, hkaiNavMeshGenerationSettings *input, hkcdDynamicAabbTree *cuttingGeomTree, hkGeometry *cuttingGeom, hkaiEdgeGeometry *cuttingEdgeGeometryOut)
{
  hkaiNavMeshGenerationSettings *v8; // r13
  int v9; // ebx
  hkGeometry *v10; // r15
  hkAabb *v11; // rdi
  hkResult *v12; // r12
  int v13; // er8
  int v15; // ecx
  _DWORD *v16; // rdx
  hkGeometry *v17; // rbx
  int v18; // er9
  hkArray<hkVector4f,hkContainerHeapAllocator> *v19; // rdi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // esi
  int v26; // er9
  int v27; // er8
  hkGeometry::Triangle *v28; // rcx
  hkVector4f *v29; // rdx
  bool v30; // r14
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  int v41; // esi
  hkGeometry *v42; // r12
  __int64 v43; // rbx
  __int64 v44; // r13
  hkGeometry::Triangle *v45; // rcx
  hkVector4f *v46; // rsi
  __int64 v47; // rbx
  signed __int64 v48; // r15
  unsigned __int64 v49; // r14
  int v50; // eax
  unsigned __int64 v51; // rcx
  __m128 v52; // xmm0
  signed __int64 v53; // rax
  __int64 v54; // rcx
  hkGeometry::Triangle *v55; // rdx
  int v56; // eax
  int v57; // er8
  bool v58; // [rsp+30h] [rbp-D0h]
  _DWORD *array; // [rsp+38h] [rbp-C8h]
  int v60; // [rsp+40h] [rbp-C0h]
  int v61; // [rsp+44h] [rbp-BCh]
  void *ptr; // [rsp+48h] [rbp-B8h]
  int v63; // [rsp+50h] [rbp-B0h]
  int v64; // [rsp+54h] [rbp-ACh]
  hkResult resulta; // [rsp+58h] [rbp-A8h]
  hkResult v66; // [rsp+5Ch] [rbp-A4h]
  hkResult v67; // [rsp+60h] [rbp-A0h]
  hkResult v68; // [rsp+64h] [rbp-9Ch]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v69; // [rsp+68h] [rbp-98h]
  hkResult v70[2]; // [rsp+78h] [rbp-88h]
  int v71; // [rsp+80h] [rbp-80h]
  int v72; // [rsp+84h] [rbp-7Ch]
  int v73; // [rsp+88h] [rbp-78h]
  int v74; // [rsp+90h] [rbp-70h]
  int v75; // [rsp+94h] [rbp-6Ch]
  int v76; // [rsp+98h] [rbp-68h]
  hkVector4f normal; // [rsp+A0h] [rbp-60h]
  hkSimdFloat32 extrusionLength; // [rsp+B0h] [rbp-50h]
  hkVector4f a; // [rsp+C0h] [rbp-40h]
  hkVector4f b; // [rsp+D0h] [rbp-30h]
  hkVector4f c; // [rsp+E0h] [rbp-20h]
  hkVector4f vertsOut; // [rsp+F0h] [rbp-10h]
  hkVector4f triB; // [rsp+100h] [rbp+0h]
  hkVector4f triC; // [rsp+110h] [rbp+10h]
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb v85; // [rsp+150h] [rbp+50h]
  Prism v86; // [rsp+1A0h] [rbp+A0h]
  hkResult *v87; // [rsp+280h] [rbp+180h]
  hkAabb *aabb; // [rsp+288h] [rbp+188h]
  hkGeometry *v89; // [rsp+290h] [rbp+190h]
  int v90; // [rsp+298h] [rbp+198h]

  v90 = t;
  v89 = triMeshIn;
  aabb = extrudedTriAabb;
  v87 = result;
  v8 = input;
  v9 = t;
  v10 = triMeshIn;
  v11 = extrudedTriAabb;
  v12 = result;
  v58 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  array = 0i64;
  v60 = 0;
  v61 = 2147483648;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16, 4);
  if ( resulta.m_enum
    || (hkcdDynamicAabbTree::queryAabb(
          cuttingGeomTree,
          v70,
          v11,
          (hkArray<unsigned int,hkContainerTempAllocator> *)&array),
        v70[0].m_enum) )
  {
LABEL_2:
    v13 = v61;
    v12->m_enum = 1;
    v60 = 0;
    if ( v13 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v13);
    return v12;
  }
  hkaiEdgeGeometry::clear(cuttingEdgeGeometryOut);
  v15 = v60;
  v16 = array;
  if ( !v60 || v60 == 1 && *array == v9 )
  {
    v57 = v61;
    v12->m_enum = 0;
    v60 = 0;
    if ( v57 >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v16,
        4 * v57);
      return v12;
    }
    return v12;
  }
  v17 = cuttingGeom;
  v18 = 3 * v60;
  v19 = &cuttingGeom->m_vertices;
  v20 = cuttingGeom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < 3 * v60 )
  {
    v21 = 2 * v20;
    if ( v18 < v21 )
      v18 = v21;
    hkArrayUtil::_reserve(
      &v68,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &cuttingGeom->m_vertices,
      v18,
      16);
    if ( v68.m_enum == HK_SUCCESS )
    {
      v15 = v60;
      goto LABEL_15;
    }
    goto LABEL_2;
  }
  v68.m_enum = 0;
LABEL_15:
  v22 = v17->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 >= v15 )
  {
    v66.m_enum = 0;
LABEL_22:
    ptr = 0i64;
    v63 = 0;
    v64 = 2147483648;
    v24 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(3 * v15);
    v25 = v24;
    if ( (v64 & 0x3FFFFFFF) >= v24 )
    {
      v67.m_enum = 0;
    }
    else
    {
      v26 = v24;
      if ( v24 < 2 * (v64 & 0x3FFFFFFF) )
        v26 = 2 * (v64 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v67, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &ptr, v26, 1);
      if ( v67.m_enum )
      {
        v27 = v64;
        v12->m_enum = 1;
        v63 = 0;
        if ( v27 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            ptr,
            v27 & 0x3FFFFFFF);
        ptr = 0i64;
        v60 = 0;
LABEL_58:
        v64 = 2147483648;
        goto LABEL_59;
      }
    }
    v63 = v25;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      &v69,
      ptr,
      v25);
    v28 = v10->m_triangles.m_data;
    v29 = v10->m_vertices.m_data;
    v30 = v58;
    v31 = v29[v28[v90].m_a].m_quad;
    a.m_quad = (__m128)v29[v28[v90].m_a];
    v32 = v29[v28[v90].m_b].m_quad;
    b.m_quad = (__m128)v29[v28[v90].m_b];
    v33 = v29[v28[v90].m_c].m_quad;
    c.m_quad = (__m128)v29[v28[v90].m_c];
    if ( v58 )
    {
      v34 = _mm_sub_ps(v32, v31);
      v35 = _mm_sub_ps(v33, v31);
      v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34), _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v35));
      v37 = _mm_shuffle_ps(v36, v36, 201);
      v38 = _mm_mul_ps(v37, v37);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_rsqrt_ps(v39);
      normal.m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v39, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                            _mm_mul_ps(*(__m128 *)_xmm, v40))),
                        v37);
    }
    else
    {
      normal.m_quad = (__m128)v8->m_up;
    }
    extrusionLength.m_real = _mm_shuffle_ps(
                               (__m128)LODWORD(v8->m_characterHeight),
                               (__m128)LODWORD(v8->m_characterHeight),
                               0);
    `anonymous namespace'::Prism::initFromExtrudedTriangle(&v86, &a, &b, &c, &normal, &extrusionLength);
    if ( v58 )
      hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(
        &v85,
        &a,
        &b,
        &c,
        &normal,
        &extrusionLength);
    v41 = 0;
    resulta.m_enum = 0;
    if ( v60 > 0 )
    {
      v42 = cuttingGeom;
      v43 = 0i64;
      *(_QWORD *)&v70[0].m_enum = 0i64;
      do
      {
        v44 = *(signed int *)((char *)array + v43);
        if ( (_DWORD)v44 != v90 )
        {
          hkaiNavMeshGenerationUtils::getTriangleVerts(v10, input, v44, &vertsOut);
          if ( hkaiNavMeshUtils::triangleAabbCheck(aabb, &vertsOut, &triB, &triC) )
          {
            if ( !`anonymous namespace'::Prism::hasSeparatingPlaneForTri(&v86, &vertsOut, &triB, &triC)
              && (!v30
               || hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(
                    &v85,
                    &vertsOut,
                    &triB,
                    &triC)) )
            {
              v45 = v10->m_triangles.m_data;
              v46 = &vertsOut;
              v47 = 0i64;
              v48 = 3i64;
              v74 = v45[v44].m_a;
              v75 = v45[v44].m_b;
              v76 = v45[v44].m_c;
              do
              {
                v49 = *(int *)((char *)&v74 + v47);
                v50 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                          &v69,
                                          v49);
                if ( v50 > v69.m_hashMod )
                {
                  v51 = v42->m_vertices.m_size;
                  v52 = v46->m_quad;
                  v53 = v19->m_size;
                  *(int *)((char *)&v71 + v47) = v51;
                  v19->m_data[v53].m_quad = v52;
                  ++v19->m_size;
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    &v69,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v49,
                    v51);
                }
                else
                {
                  *(int *)((char *)&v71 + v47) = v69.m_elem[v50].val;
                }
                v47 += 4i64;
                ++v46;
                --v48;
              }
              while ( v48 );
              v54 = v42->m_triangles.m_size;
              v41 = resulta.m_enum;
              v43 = *(_QWORD *)&v70[0].m_enum;
              v10 = v89;
              v42->m_triangles.m_size = v54 + 1;
              v55 = &v42->m_triangles.m_data[v54];
              v30 = v58;
              v55->m_a = v71;
              v56 = v72;
              v55->m_material = v44;
              v55->m_b = v56;
              v55->m_c = v73;
            }
          }
        }
        ++v41;
        v43 += 4i64;
        resulta.m_enum = v41;
        *(_QWORD *)&v70[0].m_enum = v43;
      }
      while ( v41 < v60 );
      v12 = v87;
      v17 = cuttingGeom;
    }
    if ( v30 )
    {
      hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter((hkaiGeometryToEdgeGeometryConverter *)&vertsOut);
      vertsOut.m_quad.m128_i8[8] = 1;
      hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
        (hkaiGeometryToEdgeGeometryConverter *)&vertsOut,
        (hkResult *)&input,
        v17,
        (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
        cuttingEdgeGeometryOut);
      if ( (_DWORD)input )
      {
        v12->m_enum = 1;
        hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter((hkaiGeometryToEdgeGeometryConverter *)&vertsOut);
LABEL_55:
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &v69,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&v69);
        v63 = 0;
        if ( v64 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            ptr,
            v64 & 0x3FFFFFFF);
        ptr = 0i64;
        v60 = 0;
        goto LABEL_58;
      }
      hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter((hkaiGeometryToEdgeGeometryConverter *)&vertsOut);
    }
    else
    {
      hkaiEdgeGeometry::set(
        cuttingEdgeGeometryOut,
        (hkResult *)&input,
        v17,
        (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
        0);
      if ( (_DWORD)input )
      {
        v12->m_enum = 1;
        goto LABEL_55;
      }
    }
    v12->m_enum = 0;
    goto LABEL_55;
  }
  v23 = 2 * v22;
  if ( v15 < v23 )
    v15 = v23;
  hkArrayUtil::_reserve(&v66, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v17->m_triangles, v15, 16);
  if ( v66.m_enum == HK_SUCCESS )
  {
    v15 = v60;
    goto LABEL_22;
  }
  v12->m_enum = 1;
  v60 = 0;
LABEL_59:
  if ( v61 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v61);
  return v12;
}

// File Line: 1596
// RVA: 0xB77C60
hkResult *__fastcall hkaiNavMeshGenerationUtils::raycastAgainstCuttingGeometry(hkResult *result, int walkableTriIndex, hkArrayBase<hkVector4f> *vertices, hkArrayBase<int> *triangles, int *hitFaces, hkGeometry *cuttingGeometry, hkSimdFloat32 *characterHeight, hkVector4f *rayDir)
{
  hkResult *v8; // rbx
  hkArrayBase<int> *v9; // rsi
  int v10; // er13
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // rdi
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  __m128 v16; // xmm6
  int v17; // er15
  hkGeometry *v18; // r14
  _QWORD *v19; // r8
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // rax
  int v22; // er9
  __int64 v23; // rdi
  int v24; // er9
  int v25; // edx
  int v26; // er8
  _QWORD *v27; // r8
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // rax
  int v30; // esi
  __int64 v31; // r12
  int v32; // er13
  hkGeometry::Triangle *v33; // r8
  hkVector4f *v34; // rcx
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  _DWORD *v39; // rdi
  __int64 i; // rcx
  int v41; // er8
  __int64 v42; // r13
  int v43; // er9
  hkResultEnum v44; // eax
  float v45; // er8
  __int64 v46; // r9
  float v47; // ecx
  unsigned __int64 v48; // rdi
  float v49; // er10
  int v50; // er9
  int v51; // er9
  int v52; // eax
  unsigned __int64 v53; // rdx
  __int64 v54; // r8
  __int64 v55; // r12
  signed __int64 v56; // r14
  int v57; // ebx
  __m128 v58; // xmm7
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 *v61; // rdx
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm1
  __int64 v65; // rcx
  signed __int64 v66; // rdi
  __int64 v67; // rcx
  __int64 v68; // rdx
  int v69; // edi
  int v70; // er9
  float v71; // er8
  int v72; // er9
  hkResultEnum v73; // eax
  int v74; // esi
  hk1AxisSweep::AabbInt *v75; // rdx
  unsigned int v76; // ecx
  unsigned int v77; // eax
  bool v78; // cf
  bool v79; // zf
  hk1AxisSweep::AabbInt *v80; // rax
  hk1AxisSweep::AabbInt *v81; // rcx
  __int64 v82; // rsi
  __int64 v83; // rcx
  _DWORD *v84; // rdi
  unsigned __int64 v85; // r9
  _QWORD *v86; // r8
  unsigned __int64 v87; // rdi
  unsigned __int64 v88; // rax
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-98h]
  int v91; // [rsp+38h] [rbp-90h]
  int v92; // [rsp+3Ch] [rbp-8Ch]
  hk1AxisSweep::AabbInt *aabbs; // [rsp+40h] [rbp-88h]
  int v94; // [rsp+48h] [rbp-80h]
  int v95; // [rsp+4Ch] [rbp-7Ch]
  hkResult v96[2]; // [rsp+50h] [rbp-78h]
  hkAabb aabbIn; // [rsp+58h] [rbp-70h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+78h] [rbp-50h]
  hk1AxisSweep::IteratorAB v99; // [rsp+88h] [rbp-40h]
  hkaiPositionHitFilter v100; // [rsp+B8h] [rbp-10h]
  hkaiEdgeGeometryRaycaster v101; // [rsp+E8h] [rbp+20h]
  hkResult *v102; // [rsp+1B8h] [rbp+F0h]
  _QWORD *v103; // [rsp+1C8h] [rbp+100h]
  hkResult v104[2]; // [rsp+1D0h] [rbp+108h]
  _DWORD *v105; // [rsp+1D8h] [rbp+110h]
  hkGeometry *geom; // [rsp+1E0h] [rbp+118h]
  __m128 *retaddr; // [rsp+1E8h] [rbp+120h]
  __m128 *v108; // [rsp+1F0h] [rbp+128h]

  v108 = (__m128 *)result;
  v8 = result;
  v9 = triangles;
  v10 = walkableTriIndex;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtraycastNoTree";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  aabbIn.m_max.m_quad.m128_f32[2] = FLOAT_0_001;
  v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v17 = v9->m_size / 3;
  v96[1].m_enum = v9->m_size / 3;
  hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&v101);
  hkaiPositionHitFilter::hkaiPositionHitFilter(&v100, v16.m128_f32[0]);
  hkaiEdgeGeometryRaycaster::setupForRemoveUnreachableTriangles(&v101);
  hkaiEdgeGeometryRaycaster::setHitFilter(&v101, (hkaiEdgeGeometryHitFilter *)&v100.vfptr);
  v18 = geom;
  hkaiEdgeGeometryRaycaster::initNoTree(&v101, (hkResult *)&sortedAabbs.m_size, geom);
  if ( sortedAabbs.m_size )
  {
    v8->m_enum = 1;
    v100.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v101);
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = v19[1];
    if ( v20 < v19[3] )
    {
      *(_QWORD *)v20 = "Et";
      v21 = __rdtsc();
      *(_DWORD *)(v20 + 8) = v21;
      v19[1] = v20 + 16;
    }
    return v8;
  }
  v22 = v18->m_triangles.m_size;
  v23 = 0i64;
  v92 = 2147483648;
  v24 = v22 + 4;
  v25 = 0;
  array = 0i64;
  v91 = 0;
  if ( v24 <= 0 )
  {
    v96[0].m_enum = 0;
  }
  else
  {
    if ( v24 < 0 )
      v24 = 0;
    hkArrayUtil::_reserve(v96, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v24, 32);
    if ( v96[0].m_enum )
    {
      v26 = v92;
      v8->m_enum = 1;
      v91 = 0;
      if ( v26 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          32 * v26);
      array = 0i64;
      v100.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
      v92 = 2147483648;
      hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v101);
      v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v28 = v27[1];
      if ( v28 < v27[3] )
      {
        *(_QWORD *)v28 = "Et";
        v29 = __rdtsc();
        *(_DWORD *)(v28 + 8) = v29;
        v27[1] = v28 + 16;
      }
      return v8;
    }
    v25 = v91;
  }
  v30 = 0;
  sortedAabbs.m_capacityAndFlags = v18->m_triangles.m_size;
  v31 = sortedAabbs.m_capacityAndFlags;
  if ( sortedAabbs.m_capacityAndFlags > 0 )
  {
    v32 = v10 + 1;
    do
    {
      v33 = v18->m_triangles.m_data;
      if ( v33[v23].m_material + 1 != v32 )
      {
        v34 = v18->m_vertices.m_data;
        v35 = v34[v33[v23].m_a].m_quad;
        v36 = v34[v33[v23].m_a].m_quad;
        v37 = v34[v33[v23].m_b].m_quad;
        v38 = v34[v33[v23].m_c].m_quad;
        v91 = v25 + 1;
        aabbIn.m_min.m_quad = _mm_min_ps(_mm_min_ps(v36, v37), v38);
        aabbIn.m_max.m_quad = _mm_max_ps(_mm_max_ps(v35, v37), v38);
        hk1AxisSweep::AabbInt::set(&array[v25], &aabbIn, v30);
        v25 = v91;
      }
      ++v30;
      ++v23;
      --v31;
    }
    while ( v31 );
  }
  if ( v25 )
  {
    v42 = 0i64;
    v43 = v17 + 4;
    v95 = 2147483648;
    aabbs = 0i64;
    v94 = 0;
    if ( v17 + 4 <= 0 )
    {
      v44 = 0;
    }
    else
    {
      if ( v43 < 0 )
        v43 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&aabbIn.m_max.m_quad.m128_u16[4],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &aabbs,
        v43,
        32);
      v44 = aabbIn.m_max.m_quad.m128_i32[2];
    }
    v96[0].m_enum = v44;
    if ( v44 )
    {
      v8->m_enum = 1;
LABEL_103:
      v94 = v42;
      if ( v95 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          aabbs,
          32 * v95);
      v91 = 0;
      v95 = 2147483648;
      aabbs = 0i64;
      if ( v92 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          32 * v92);
      array = 0i64;
      goto LABEL_108;
    }
    v45 = -0.0;
    *(_QWORD *)&v96[0].m_enum = 0i64;
    v46 = 0i64;
    v47 = -0.0;
    aabbIn.m_min = (hkVector4f)0x8000000000000000ui64;
    v48 = 0i64;
    v49 = 0.0;
    aabbIn.m_max.m_quad.m128_u64[0] = 0x8000000000000000i64;
    if ( v17 <= 0 )
    {
      LODWORD(sortedAabbs.m_data) = 0;
    }
    else
    {
      v50 = v17;
      if ( v17 < 0 )
        v50 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&sortedAabbs,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v96,
        v50,
        16);
      v45 = aabbIn.m_min.m_quad.m128_f32[1];
      v46 = aabbIn.m_min.m_quad.m128_u32[0];
      v47 = aabbIn.m_max.m_quad.m128_f32[1];
      v49 = aabbIn.m_max.m_quad.m128_f32[0];
      v48 = aabbIn.m_min.m_quad.m128_u64[1];
    }
    if ( (LODWORD(v47) & 0x3FFFFFFF) >= v17 )
    {
      v52 = 0;
      HIDWORD(sortedAabbs.m_data) = 0;
    }
    else
    {
      v51 = v17;
      if ( v17 < 2 * (LODWORD(v47) & 0x3FFFFFFF) )
        v51 = 2 * (LODWORD(v47) & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&sortedAabbs.m_data + 1,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &aabbIn.m_min.m_quad.m128_u16[4],
        v51,
        16);
      v45 = aabbIn.m_min.m_quad.m128_f32[1];
      v46 = aabbIn.m_min.m_quad.m128_u32[0];
      v47 = aabbIn.m_max.m_quad.m128_f32[1];
      v49 = aabbIn.m_max.m_quad.m128_f32[0];
      v48 = aabbIn.m_min.m_quad.m128_u64[1];
      v52 = HIDWORD(sortedAabbs.m_data);
    }
    if ( LODWORD(sortedAabbs.m_data) || v52 )
    {
      v8->m_enum = 1;
      aabbIn.m_max.m_quad.m128_i32[0] = 0;
      if ( v47 < 0.0 )
      {
LABEL_100:
        aabbIn.m_min.m_quad.m128_u64[1] = 0i64;
        aabbIn.m_max.m_quad.m128_i32[1] = 2147483648;
        aabbIn.m_min.m_quad.m128_i32[0] = 0;
        if ( v45 >= 0.0 )
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            *(_QWORD *)&v96[0].m_enum,
            (unsigned int)(16 * LODWORD(v45)),
            v46);
        *(_QWORD *)&v96[0].m_enum = 0i64;
        aabbIn.m_min.m_quad.m128_i32[1] = 2147483648;
        goto LABEL_103;
      }
      v53 = v48;
      v54 = (unsigned int)(16 * LODWORD(v47));
      goto LABEL_98;
    }
    v55 = (__int64)v105;
    if ( v17 > 0 )
    {
      v56 = 0i64;
      v57 = 0;
      v58 = _mm_sub_ps((__m128)0i64, v16);
      while ( 1 )
      {
        v59 = _mm_mul_ps(v58, *v108);
        v60 = _mm_add_ps(
                _mm_add_ps(
                  *(__m128 *)(*v103 + 16i64 * *(signed int *)(v42 + **(_QWORD **)&v104[0].m_enum)),
                  *(__m128 *)(*v103 + 16i64 * *(signed int *)(v42 + **(_QWORD **)&v104[0].m_enum + 4))),
                *(__m128 *)(*v103 + 16i64 * *(signed int *)(v42 + **(_QWORD **)&v104[0].m_enum + 8)));
        aabbIn.m_min.m_quad.m128_i32[0] = v46 + 1;
        v61 = (__m128 *)(*(_QWORD *)&v96[0].m_enum + 16i64 * (signed int)v46);
        v62 = _mm_mul_ps(v60, (__m128)xmmword_141A711C0);
        aabbIn.m_max.m_quad.m128_i32[0] = LODWORD(v49) + 1;
        *v61 = _mm_add_ps(v59, v62);
        v63 = _mm_add_ps(_mm_mul_ps(*retaddr, *v108), v62);
        *(__m128 *)(v48 + 16i64 * SLODWORD(v49)) = v63;
        aabbIn.m_min.m_quad = _mm_min_ps(*v61, v63);
        v64 = _mm_max_ps(*v61, *(__m128 *)(v48 + 16i64 * SLODWORD(v49)));
        aabbIn.m_min.m_quad = _mm_sub_ps(aabbIn.m_min.m_quad, *(__m128 *)&epsilon);
        v65 = v94++;
        aabbIn.m_max.m_quad = _mm_add_ps(v64, *(__m128 *)&epsilon);
        hk1AxisSweep::AabbInt::set(&aabbs[v65], &aabbIn, v57);
        *(_DWORD *)(v55 + 4 * v56++) = -1;
        ++v57;
        v42 += 12i64;
        if ( v56 >= v17 )
          break;
        LODWORD(v46) = aabbIn.m_min.m_quad.m128_i32[0];
        v49 = aabbIn.m_max.m_quad.m128_f32[0];
        v48 = aabbIn.m_min.m_quad.m128_u64[1];
      }
      v8 = v102;
      v18 = geom;
      v17 = v96[1].m_enum;
      LODWORD(v42) = 0;
    }
    v66 = 4i64;
    do
    {
      v67 = v94++;
      aabbs[v67].m_min[0] = -1;
      v68 = v91++;
      array[v68].m_min[0] = -1;
      --v66;
    }
    while ( v66 );
    v69 = v91;
    sortedAabbs.m_data = 0i64;
    v94 = 0;
    v95 = 2147483648;
    if ( v91 < 0 )
      v69 = v94;
    if ( v69 <= 0 )
    {
      v104[0].m_enum = v42;
    }
    else
    {
      v70 = v69;
      if ( v69 < 0 )
        v70 = v42;
      hkArrayUtil::_reserve(v104, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortedAabbs, v70, 32);
      if ( v104[0].m_enum )
      {
        v8->m_enum = 1;
        goto LABEL_64;
      }
    }
    v71 = -0.0;
    v94 = v69;
    aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
    aabbIn.m_min.m_quad.m128_u64[1] = 0x8000000000000000i64;
    if ( v69 <= 0 )
    {
      v73 = (signed int)v42;
    }
    else
    {
      v72 = v69;
      if ( v69 < 0 )
        v72 = v42;
      hkArrayUtil::_reserve(&v96[1], (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &aabbIn, v72, 8);
      v73 = v96[1].m_enum;
      v71 = aabbIn.m_min.m_quad.m128_f32[3];
      if ( v96[1].m_enum )
        goto LABEL_75;
    }
    aabbIn.m_min.m_quad.m128_i32[2] = v69;
LABEL_75:
    v104[0].m_enum = v73;
    if ( v73 == HK_SUCCESS )
    {
      hk1AxisSweep::sortAabbs(aabbs, v17, (hkArrayBase<hkRadixSort::SortData32> *)&aabbIn, &sortedAabbs);
      v74 = sortedAabbs.m_capacityAndFlags;
      hk1AxisSweep::sortAabbs(
        array,
        sortedAabbs.m_capacityAndFlags,
        (hkArrayBase<hkRadixSort::SortData32> *)&aabbIn,
        &sortedAabbs);
      aabbIn.m_min.m_quad.m128_i32[2] = v42;
      if ( aabbIn.m_min.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          (void *)aabbIn.m_min.m_quad.m128_u64[0],
          8 * aabbIn.m_min.m_quad.m128_i32[3]);
      aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
      aabbIn.m_min.m_quad.m128_i32[3] = 2147483648;
      v94 = 0;
      if ( v95 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * v95);
      v75 = aabbs;
      v76 = v42;
      v77 = array->m_min[0];
      v99.m_numA = v17;
      v99.m_numB = v74;
      v78 = aabbs->m_min[0] < v77;
      v79 = aabbs->m_min[0] == v77;
      v99.m_pa = aabbs;
      v99.m_pb = array;
      LOBYTE(v76) = !v78 && !v79;
      v99.m_aIsBigger = v76;
      if ( v76 )
      {
        v99.m_currentPtr = array;
      }
      else
      {
        v99.m_currentPtr = aabbs;
        v75 = array;
      }
      v99.m_potentialPtr = v75 - 1;
      while ( 1 )
      {
        hk1AxisSweep::IteratorAB::next(&v99);
        if ( v99.m_numA <= 0 || v99.m_numB <= 0 )
          break;
        if ( v99.m_aIsBigger )
        {
          v80 = v99.m_potentialPtr;
          v81 = v99.m_pb;
        }
        else
        {
          v80 = v99.m_pa;
          v81 = v99.m_potentialPtr;
        }
        v82 = *(signed int *)v81->m_expansionMin;
        v83 = *(signed int *)v80->m_expansionMin;
        v84 = (_DWORD *)(v55 + 4 * v83);
        if ( *(_DWORD *)(v55 + 4 * v83) == -1 )
        {
          v85 = aabbIn.m_min.m_quad.m128_u64[1];
          aabbIn.m_min = (hkVector4f)query.m_quad;
          if ( hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                 &v101,
                 v82 + 1,
                 (hkVector4f *)(16 * v83 + *(_QWORD *)&v96[0].m_enum),
                 (hkVector4f *)(16 * v83 + v85),
                 (hkSimdFloat32 *)&aabbIn) )
          {
            *v84 = v18->m_triangles.m_data[v82].m_material + 1;
          }
        }
      }
      v8->m_enum = v42;
      goto LABEL_96;
    }
    v8->m_enum = 1;
    aabbIn.m_min.m_quad.m128_i32[2] = v42;
    if ( v71 >= 0.0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)aabbIn.m_min.m_quad.m128_u64[0],
        8 * LODWORD(v71));
    aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
    aabbIn.m_min.m_quad.m128_i32[3] = 2147483648;
LABEL_64:
    v94 = v42;
    if ( v95 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * v95);
    sortedAabbs.m_data = 0i64;
    v95 = 2147483648;
LABEL_96:
    aabbIn.m_max.m_quad.m128_i32[0] = v42;
    if ( aabbIn.m_max.m_quad.m128_i32[1] < 0 )
    {
LABEL_99:
      v45 = aabbIn.m_min.m_quad.m128_f32[1];
      goto LABEL_100;
    }
    v53 = aabbIn.m_min.m_quad.m128_u64[1];
    v54 = (unsigned int)(16 * aabbIn.m_max.m_quad.m128_i32[1]);
LABEL_98:
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v53,
      v54,
      v46);
    goto LABEL_99;
  }
  if ( v17 > 0 )
  {
    v39 = v105;
    for ( i = v17; i; --i )
    {
      *v39 = -1;
      ++v39;
    }
  }
  v41 = v92;
  v8->m_enum = 0;
  v91 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      32 * v41);
  array = 0i64;
LABEL_108:
  v92 = 2147483648;
  v100.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v101);
  v86 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v87 = v86[1];
  if ( v87 < v86[3] )
  {
    v88 = __rdtsc();
    *(_DWORD *)(v87 + 8) = v88;
    *(_QWORD *)v87 = "Et";
    v86[1] = v87 + 16;
  }
  return v8;
}

// File Line: 1739
// RVA: 0xB77970
hkResult *__fastcall hkaiNavMeshGenerationUtils::weldDuplicateVertices(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<int,hkContainerHeapAllocator> *remap)
{
  signed __int64 v3; // rsi
  hkArray<int,hkContainerHeapAllocator> *v4; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rdi
  hkResult *v6; // r12
  int v7; // er9
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // er8
  signed __int64 v13; // rbx
  signed __int64 v14; // rdx
  signed int v15; // er10
  __int64 v16; // r9
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  int v19; // ecx
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm1
  signed __int64 v22; // rcx
  hkVector4f v23; // xmm0
  signed __int64 v24; // rsi
  __int64 v25; // r9
  signed __int64 v26; // r15
  DuplicateVertexRef *v27; // r10
  __int64 v28; // rdx
  signed __int64 v29; // rdx
  __m128 i; // xmm1
  DuplicateVertexRef *v31; // r8
  __int64 v32; // rax
  DuplicateVertexRef *array; // [rsp+30h] [rbp-18h]
  int v35; // [rsp+38h] [rbp-10h]
  int v36; // [rsp+3Ch] [rbp-Ch]
  hkResult resulta; // [rsp+88h] [rbp+40h]
  hkResult v38; // [rsp+98h] [rbp+50h]

  v3 = vertices->m_size;
  v4 = remap;
  v5 = vertices;
  v6 = result;
  v36 = 2147483648;
  array = 0i64;
  v35 = 0;
  if ( (signed int)v3 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v7 = v3;
    if ( (signed int)v3 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 8);
    if ( resulta.m_enum )
    {
      v6->m_enum = 1;
      goto LABEL_33;
    }
  }
  v8 = v4->m_capacityAndFlags;
  v35 = v3;
  v9 = v8 & 0x3FFFFFFF;
  if ( v9 >= (signed int)v3 )
  {
    v38.m_enum = 0;
  }
  else
  {
    v10 = 2 * v9;
    v11 = v3;
    if ( (signed int)v3 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&v38, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v11, 4);
    if ( v38.m_enum )
    {
      v6->m_enum = 1;
      goto LABEL_33;
    }
  }
  v4->m_size = v3;
  v12 = 0;
  v13 = v3;
  v14 = 0i64;
  if ( v3 >= 4 )
  {
    v15 = 2;
    v16 = 0i64;
    do
    {
      v14 += 4i64;
      v16 += 4i64;
      v17.m_quad = (__m128)v5->m_data[v16 - 4];
      *((_DWORD *)&array[v14 - 3] - 1) = v12;
      v12 += 4;
      LODWORD(array[v14 - 4].m_value) = v17.m_quad.m128_i32[0];
      v18.m_quad = (__m128)v5->m_data[v16 - 3];
      *((_DWORD *)&array[v14 - 2] - 1) = v15 - 1;
      v19 = v15 + 1;
      LODWORD(array[v14 - 3].m_value) = v18.m_quad.m128_i32[0];
      v20.m_quad = (__m128)v5->m_data[v16 - 2];
      *((_DWORD *)&array[v14 - 1] - 1) = v15;
      v15 += 4;
      LODWORD(array[v14 - 2].m_value) = v20.m_quad.m128_i32[0];
      v21.m_quad = (__m128)v5->m_data[v16 - 1];
      *((_DWORD *)&array[v14] - 1) = v19;
      LODWORD(array[v14 - 1].m_value) = v21.m_quad.m128_i32[0];
    }
    while ( v14 < v3 - 3 );
  }
  if ( v14 < v3 )
  {
    v22 = v14;
    do
    {
      ++v14;
      ++v22;
      v23.m_quad = (__m128)v5->m_data[v22 - 1];
      *((_DWORD *)&array[v14] - 1) = v12++;
      LODWORD(array[v14 - 1].m_value) = v23.m_quad.m128_i32[0];
    }
    while ( v14 < v3 );
  }
  if ( (signed int)v3 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
      array,
      0,
      v3 - 1,
      0);
  if ( (signed int)v3 > 0 )
  {
    v24 = 1i64;
    v25 = 0i64;
    v26 = v13;
    do
    {
      v27 = array;
      v28 = array[v25].m_index;
      if ( (signed int)v28 >= 0 )
      {
        v4->m_data[v28] = v28;
        v29 = v24;
        for ( i = v5->m_data[v27[v25].m_index].m_quad; v29 < v13; ++v29 )
        {
          v31 = array;
          v32 = array[v29].m_index;
          if ( (signed int)v32 >= 0 )
          {
            if ( v27[v25].m_value != array[v29].m_value )
              break;
            if ( (_mm_movemask_ps(_mm_cmpeqps(i, v5->m_data[v32].m_quad)) & 7) == 7 )
            {
              v4->m_data[array[v29].m_index] = v27[v25].m_index;
              v31[v29].m_index = -1;
            }
          }
        }
        v27[v25].m_index = -1;
      }
      ++v25;
      ++v24;
      --v26;
    }
    while ( v26 );
  }
  v6->m_enum = 0;
LABEL_33:
  v35 = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v36);
  return v6;
}

// File Line: 1792
// RVA: 0xB75920
bool __fastcall hkaiNavMeshGenerationUtils::_rayTriangleIntersect(hkVector4f *pos, hkVector4f *dir, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkSimdFloat32 *distOut)
{
  __m128 v6; // xmm6
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  unsigned int v10; // eax
  hkSimdFloat32 tolerance; // [rsp+30h] [rbp-68h]
  hkSimdFloat32 fractionOut; // [rsp+40h] [rbp-58h]
  hkcdRay ray; // [rsp+50h] [rbp-48h]

  v6 = dir->m_quad;
  tolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  v7 = _mm_cmpeqps((__m128)0i64, v6);
  v8 = _mm_rcp_ps(v6);
  ray.m_direction.m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, query.m_quad), 196);
  v9 = pos->m_quad;
  ray.m_invDirection.m_quad = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps(
                                    (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)v6, 0x1Fu), 0x1Fu),
                                    (__m128)_xmm),
                                  v7),
                                _mm_andnot_ps(v7, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v6, v8)), v8)));
  ray.m_origin.m_quad = v9;
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, ray.m_direction.m_quad)) & 7 | 0x3F000000;
  v10 = hkcdLineTriangleIntersect(&ray, a, b, c, &tolerance, &fractionOut);
  *distOut = (hkSimdFloat32)fractionOut.m_real;
  return v10 != 0;
}

// File Line: 1857
// RVA: 0xB75A20
hkResult *__usercall hkaiNavMeshGenerationUtils::_removeUnreachableTriangles@<rax>(hkResult *result@<rcx>, hkaiNavMeshGenerationSettings *input@<rdx>, hkaiEdgeGeometryRaycaster *cuttingGeomRaycaster@<r8>, hkaiEdgeGeometry *walkableGeom@<r9>, hkArrayBase<int> *a5@<rbx>, hkaiCarverTree *tree, hkArray<int,hkContainerHeapAllocator> *trianglesPerFace, hkArray<int,hkContainerHeapAllocator> *trisInOut, hkArray<int,hkContainerHeapAllocator> *triConnectivityInOut, hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut, hkArrayBase<int> *materials, hkArrayBase<int> *originalFaceIndices, hkArray<hkVector4f,hkContainerHeapAllocator> *triangleVertices, hkArray<int,hkContainerHeapAllocator> *hitFaces, hkaiNavMeshGenerationProgressCallback *cb, hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  bool v16; // zf
  hkaiEdgeGeometry *v17; // r12
  hkaiEdgeGeometryRaycaster *v18; // r13
  __m128 epsilon; // xmm8
  int v20; // edx
  hkResult *v21; // r15
  int v23; // ebx
  int v24; // edi
  int v25; // eax
  void *v26; // r9
  signed int v27; // er8
  signed __int64 v28; // rbx
  int v29; // er9
  __int64 v30; // rcx
  _DWORD *v31; // rdi
  hkArray<int,hkContainerHeapAllocator> *v32; // rax
  hkArray<int,hkContainerHeapAllocator> *v33; // rdi
  int v34; // ecx
  __m128 *v35; // r9
  int v36; // edx
  int v37; // er15
  __int64 v38; // rsi
  __m128 v39; // xmm9
  hkArrayBase<int> *v40; // rax
  signed __int64 v41; // r8
  __int64 v42; // rdx
  int v43; // ecx
  int v44; // ebx
  __int64 v45; // r12
  __m128 v46; // xmm7
  signed __int64 v47; // r14
  __m128 v48; // xmm10
  __int64 v49; // r8
  int *v50; // rdi
  signed __int64 v51; // rdx
  __m128 v52; // xmm5
  __m128 v53; // xmm5
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  __m128 v56; // xmm1
  __m128 v57; // xmm4
  __m128 v58; // xmm4
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm6
  int *v63; // rax
  signed __int64 v64; // rcx
  __int64 v65; // rdx
  __m128 v66; // xmm3
  __m128 v67; // xmm2
  signed __int64 v68; // rax
  __m128 v69; // xmm1
  _DWORD *v70; // rdi
  int v71; // [rsp+40h] [rbp-A0h]
  bool v72; // [rsp+44h] [rbp-9Ch]
  void *array; // [rsp+48h] [rbp-98h]
  int v74; // [rsp+50h] [rbp-90h]
  int v75; // [rsp+54h] [rbp-8Ch]
  int v76; // [rsp+58h] [rbp-88h]
  hkResult resulta[2]; // [rsp+60h] [rbp-80h]
  __int64 v78; // [rsp+68h] [rbp-78h]
  hkVector4f p; // [rsp+70h] [rbp-70h]
  hkSimdFloat32 hitFractionInOut; // [rsp+80h] [rbp-60h]
  hkVector4f rayEnd[4]; // [rsp+90h] [rbp-50h]
  hkVector4f rayStart[4]; // [rsp+D0h] [rbp-10h]
  hkaiRemoveUnreachableHitFilter v83; // [rsp+110h] [rbp+30h]
  _DWORD *v84; // [rsp+240h] [rbp+160h]
  __m128 *v85; // [rsp+248h] [rbp+168h]
  hkaiEdgeGeometry *retaddr; // [rsp+258h] [rbp+178h]
  hkaiCarverTree *v87; // [rsp+260h] [rbp+180h]
  hkArrayBase<int> *v88; // [rsp+268h] [rbp+188h]
  hkArrayBase<int> *v89; // [rsp+270h] [rbp+190h]
  hkArrayBase<int> *tris; // [rsp+270h] [rbp+190h]
  hkArray<int,hkContainerHeapAllocator> *v91; // [rsp+278h] [rbp+198h]

  v91 = (hkArray<int,hkContainerHeapAllocator> *)walkableGeom;
  v88 = (hkArrayBase<int> *)input;
  v87 = (hkaiCarverTree *)result;
  v16 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool == 0;
  v71 = LODWORD(FLOAT_0_001);
  v72 = !v16;
  v17 = walkableGeom;
  v18 = cuttingGeomRaycaster;
  epsilon = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v20 = v89->m_size;
  v21 = result;
  if ( !v20 )
  {
    result->m_enum = 0;
    return result;
  }
  tris = a5;
  v75 = 2147483648;
  array = 0i64;
  v74 = 0;
  v23 = v20 / 3;
  v24 = (v20 / 3 + 31) >> 5;
  v25 = v24;
  if ( v24 )
  {
    v71 = 4 * v24;
    v26 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            &v71);
    v25 = v71 / 4;
  }
  else
  {
    v26 = 0i64;
  }
  v27 = 2147483648;
  v76 = v23;
  if ( v25 )
    v27 = v25;
  v28 = 4i64;
  array = v26;
  v74 = v24;
  v75 = v27;
  *(_QWORD *)&resulta[0].m_enum = 4i64;
  if ( (v27 & 0x3FFFFFFF) < v24 )
  {
    v29 = v24;
    if ( v24 < 2 * (v27 & 0x3FFFFFFF) )
      v29 = 2 * (v27 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v29, 4);
    v27 = v75;
    v26 = array;
  }
  v74 = v24;
  if ( !v26 )
  {
    v21->m_enum = 1;
    v74 = 0;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v27);
    return v21;
  }
  if ( v24 - 1 >= 0 )
  {
    v30 = (unsigned int)v24;
    v31 = v26;
    while ( v30 )
    {
      *v31 = 0;
      ++v31;
      --v30;
    }
  }
  v32 = (hkArray<int,hkContainerHeapAllocator> *)&v17->m_vertices;
  if ( !v17 )
    v32 = triConnectivityInOut;
  v33 = (hkArray<int,hkContainerHeapAllocator> *)tris;
  p.m_quad.m128_u64[0] = (unsigned __int64)v32;
  hkaiRemoveUnreachableHitFilter::hkaiRemoveUnreachableHitFilter(
    &v83,
    (hkArrayBase<hkVector4f> *)v32,
    v17,
    (hkArrayBase<int> *)&trisInOut->m_data,
    v88,
    tris,
    (hkBitField *)&array,
    epsilon.m128_f32[0]);
  hkaiRemoveUnreachableHitFilter::init(&v83, (hkResult *)&p.m_quad.m128_u16[4]);
  if ( p.m_quad.m128_i32[2] )
  {
    v21->m_enum = 1;
    hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(&v83);
    v74 = 0;
    if ( v75 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        4 * v75);
    return v21;
  }
  hkaiEdgeGeometryRaycaster::setupForRemoveUnreachableTriangles(v18);
  hkaiEdgeGeometryRaycaster::setHitFilter(v18, (hkaiEdgeGeometryHitFilter *)&v83.vfptr);
  v34 = v88->m_size;
  v35 = v85;
  v36 = 0;
  v37 = 0;
  v38 = 0i64;
  v39 = _mm_shuffle_ps((__m128)LODWORD(v85->m128_u64[0]), (__m128)LODWORD(v85->m128_u64[0]), 0);
  v71 = 0;
  if ( v34 > 0 )
  {
    v40 = v88;
    v41 = 12i64;
    v78 = 12i64;
    while ( 1 )
    {
      if ( materials && originalFaceIndices )
      {
        (*((void (__fastcall **)(hkArrayBase<int> *, signed __int64, _QWORD, _QWORD, hkArrayBase<int> *))materials->m_data
         + 1))(
          materials,
          5i64,
          (unsigned int)v36,
          (unsigned int)v34,
          originalFaceIndices);
        v35 = v85;
        v41 = v78;
        v40 = v88;
      }
      v42 = *(unsigned int *)((char *)v40->m_data + v28 - 4);
      v43 = v17 ? *(unsigned int *)((char *)&v17->m_faces.m_data->m_faceIndex + v41) : *(int *)((char *)trisInOut->m_data
                                                                                              + v28);
      v18->m_ignoreFaceIndex = v43;
      v44 = __ROL4__(1, v37);
      if ( (signed int)v42 > 0 )
        break;
LABEL_50:
      v40 = v88;
      v34 = v88->m_size;
      v35 = v85;
      v36 = v71 + 1;
      v41 += 12i64;
      v28 = *(_QWORD *)&resulta[0].m_enum + 4i64;
      v71 = v36;
      v78 = v41;
      *(_QWORD *)&resulta[0].m_enum += 4i64;
      if ( v36 >= v34 )
        goto LABEL_51;
    }
    resulta[0].m_enum = 1057132380;
    v45 = v42;
    v46 = _mm_shuffle_ps((__m128)0x3F028F5Cu, (__m128)0x3F028F5Cu, 0);
    v47 = 3 * v38;
    v48 = _mm_sub_ps((__m128)0i64, epsilon);
    while ( 1 )
    {
      v49 = *(_QWORD *)p.m_quad.m128_u64[0];
      v50 = &v33->m_data[v47];
      v51 = 2i64 * v50[2];
      v52 = _mm_add_ps(
              *(__m128 *)(*(_QWORD *)p.m_quad.m128_u64[0] + 16i64 * *v50),
              *(__m128 *)(*(_QWORD *)p.m_quad.m128_u64[0] + 16i64 * v50[1]));
      p.m_quad = v52;
      v53 = _mm_mul_ps(_mm_add_ps(v52, *(__m128 *)(v49 + 8 * v51)), (__m128)xmmword_141A711C0);
      p.m_quad = v53;
      if ( v72 )
      {
        v54 = *(__m128 *)(v49 + 16i64 * *v50);
        v55 = _mm_sub_ps(*(__m128 *)(v49 + 16i64 * v50[1]), v54);
        v56 = _mm_sub_ps(*(__m128 *)(v49 + 16i64 * v50[2]), v54);
        v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v55), _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v56));
        v58 = _mm_shuffle_ps(v57, v57, 201);
        v59 = _mm_mul_ps(v58, v58);
        v60 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                _mm_shuffle_ps(v59, v59, 170));
        v61 = _mm_rsqrt_ps(v60);
        v62 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v61, v60), v61)),
                    _mm_mul_ps(*(__m128 *)_xmm, v61))),
                v58);
      }
      else
      {
        v62 = v35[1];
      }
      rayStart[0].m_quad = _mm_add_ps(_mm_mul_ps(v62, v48), v53);
      rayEnd[0].m_quad = _mm_add_ps(_mm_mul_ps(v62, v39), v53);
      if ( !trisPerFaceInOut )
        goto LABEL_43;
      v63 = trisPerFaceInOut->m_data;
      if ( trisPerFaceInOut->m_data[v38] < 0 )
        goto LABEL_43;
      hitFractionInOut.m_real = query.m_quad;
      if ( !hkaiEdgeGeometryRaycaster::raycastAgainstFace(v18, v63[v38], rayStart, rayEnd, &hitFractionInOut) )
        break;
LABEL_47:
      *((_DWORD *)array + ((signed __int64)v37 >> 5)) |= v44;
LABEL_48:
      v44 = __ROL4__(v44, 1);
      v35 = v85;
      v33 = (hkArray<int,hkContainerHeapAllocator> *)tris;
      ++v37;
      ++v38;
      v47 += 3i64;
      if ( !--v45 )
      {
        v41 = v78;
        v17 = retaddr;
        goto LABEL_50;
      }
    }
    v53 = p.m_quad;
LABEL_43:
    v64 = 0i64;
    v65 = *(_QWORD *)p.m_quad.m128_u64[0];
    v66 = _mm_mul_ps(v62, epsilon);
    v67 = _mm_mul_ps(_mm_sub_ps(v39, epsilon), v62);
    do
    {
      ++v64;
      v68 = 2i64 * *v50;
      ++v50;
      v69 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)(v65 + 8 * v68), v53), v46), v53), v66);
      rayStart[v64] = (hkVector4f)v69;
      rayEnd[v64].m_quad = _mm_add_ps(v67, v69);
    }
    while ( v64 <= 2 );
    if ( !hkaiEdgeGeometryRaycaster::castRayBundle(v18, rayStart, rayEnd, 0)
      && !hkaiCarverTree::carversContainPoint(v87, &p) )
    {
      goto LABEL_48;
    }
    goto LABEL_47;
  }
LABEL_51:
  hkaiNavMeshGenerationUtils::_removeTriangles(
    (hkBitField *)&array,
    v33,
    v91,
    (hkArray<int,hkContainerHeapAllocator> *)tree,
    (hkArrayBase<int> *)&trianglesPerFace->m_data,
    (hkArrayBase<int> *)&trisPerFaceInOut->m_data);
  hkaiEdgeGeometryRaycaster::setHitFilter(v18, 0i64);
  v70 = v84;
  *v84 = 0;
  hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(&v83);
  v74 = 0;
  if ( v75 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v75);
  return (hkResult *)v70;
}

// File Line: 2022
// RVA: 0xB79180
hkSimdFloat32 *__fastcall calcArea(hkSimdFloat32 *result, hkaiNavMesh *mesh, hkaiNavMesh::Edge *edges, int numEdges)
{
  __m128 v4; // xmm3
  hkaiNavMesh::Edge *v5; // r10
  hkVector4f *v6; // rdx
  __int64 v7; // rax
  __m128 v8; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  hkSimdFloat32 *v11; // rax

  v4 = 0i64;
  v5 = &edges[numEdges];
  if ( edges != v5 )
  {
    v6 = mesh->m_vertices.m_data;
    do
    {
      v7 = edges->m_a;
      ++edges;
      v8 = v6[edges[-1].m_b].m_quad;
      v9 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v6[v7].m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v6[v7].m_quad, v6[v7].m_quad, 201), v8));
      v4 = _mm_add_ps(v4, _mm_shuffle_ps(v9, v9, 201));
    }
    while ( edges != v5 );
  }
  v10 = _mm_mul_ps(v4, v4);
  v11 = result;
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                     _mm_shuffle_ps(v10, v10, 170));
  return v11;
}

// File Line: 2039
// RVA: 0xB79210
hkResult *__fastcall findUniqueEdgeLoop(hkResult *result, hkaiNavMesh *mesh, hkaiNavMesh::Face *face, hkArray<int,hkContainerHeapAllocator> *vertexMap, hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *dstEdges, hkArray<int,hkContainerTempAllocator> *edgeIndices)
{
  hkArray<int,hkContainerTempAllocator> *v6; // rbx
  signed int v7; // er12
  signed int v8; // edi
  hkaiNavMesh::Face *v9; // rsi
  char *v10; // r10
  __int64 v11; // rbx
  char *v12; // r11
  hkaiNavMesh *v13; // r13
  hkResult *v14; // r14
  int v15; // er8
  signed int v16; // er15
  int v17; // er9
  int v18; // er9
  hkResultEnum v19; // eax
  signed __int64 v21; // rax
  hkResultEnum v22; // er14
  signed __int64 v23; // rcx
  hkaiNavMesh::Edge *v24; // rax
  __int64 v25; // r13
  signed __int64 v26; // rsi
  int v27; // ebx
  __int64 v28; // rax
  int v29; // ecx
  hkArray<int,hkContainerTempAllocator> *v30; // r15
  int v31; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v32; // rdi
  __int64 v33; // rdx
  signed __int64 v34; // r8
  hkResultEnum v35; // eax
  hkArray<int,hkContainerTempAllocator> *v36; // rbx
  hkResult *v37; // rbx
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v38; // r12
  signed int v39; // ebx
  __int64 v40; // rsi
  hkaiNavMesh::Edge *v41; // r8
  signed __int64 v42; // rax
  int v43; // er9
  int v44; // eax
  int v45; // eax
  hkaiNavMesh::Edge *v46; // rdx
  signed __int64 v47; // r8
  __int64 v48; // rcx
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // er9
  hkArray<int,hkContainerTempAllocator> *v53; // r15
  __int64 v54; // rdi
  int v55; // er9
  int v56; // eax
  int v57; // eax
  int *v58; // rcx
  signed __int64 v59; // rdx
  __int64 v60; // r8
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // er9
  signed __int64 v65; // r12
  int v66; // er9
  hkResultEnum v67; // er13
  signed __int64 v68; // rax
  float v69; // xmm6_4
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v70; // rdi
  signed __int64 v71; // r15
  signed __int64 v72; // rbx
  int v73; // er14
  hkaiNavMesh::Edge *v74; // r8
  signed __int64 v75; // rax
  __int64 v76; // r9
  hkaiNavMesh::Edge *v77; // rcx
  hkaiNavMesh::Edge *v78; // rdx
  __int64 v79; // r8
  int v80; // eax
  char *v81; // rax
  hkArray<int,hkContainerTempAllocator> *v82; // rbx
  int *v83; // rcx
  int *v84; // rdx
  __int64 v85; // r8
  int v86; // eax
  hkArray<int,hkContainerTempAllocator> *v87; // rbx
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  int v89; // [rsp+34h] [rbp-CCh]
  int v90; // [rsp+38h] [rbp-C8h]
  hkResult v91; // [rsp+3Ch] [rbp-C4h]
  char *v92; // [rsp+40h] [rbp-C0h]
  char *array; // [rsp+50h] [rbp-B0h]
  int v94; // [rsp+58h] [rbp-A8h]
  int v95; // [rsp+5Ch] [rbp-A4h]
  char v96; // [rsp+60h] [rbp-A0h]
  char *v97; // [rsp+E0h] [rbp-20h]
  int v98; // [rsp+E8h] [rbp-18h]
  int v99; // [rsp+ECh] [rbp-14h]
  char v100; // [rsp+F0h] [rbp-10h]
  hkSimdFloat32 v101; // [rsp+170h] [rbp+70h]
  hkResult *v102; // [rsp+1E0h] [rbp+E0h]
  hkaiNavMesh *mesha; // [rsp+1E8h] [rbp+E8h]
  hkaiNavMesh::Face *v104; // [rsp+1F0h] [rbp+F0h]
  hkArray<int,hkContainerHeapAllocator> *v105; // [rsp+1F8h] [rbp+F8h]

  v105 = vertexMap;
  v104 = face;
  mesha = mesh;
  v102 = result;
  v6 = edgeIndices;
  v7 = 0;
  v8 = -2147483616;
  v9 = face;
  v10 = &v100;
  dstEdges->m_size = 0;
  v6->m_size = 0;
  v11 = face->m_numEdges;
  v12 = &v96;
  v13 = mesh;
  v14 = result;
  v15 = 0;
  v94 = 0;
  v89 = -2147483616;
  array = &v96;
  v95 = -2147483616;
  v92 = &v100;
  v97 = &v100;
  v98 = 0;
  v16 = -2147483616;
  v90 = -2147483616;
  v99 = -2147483616;
  if ( (signed int)v11 >= 32 )
  {
    if ( (signed int)v11 <= 32 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v17 = v11;
      if ( (signed int)v11 < 64 )
        v17 = 64;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v17, 4);
      v8 = v95;
      v16 = v99;
      v10 = v97;
      v12 = array;
      v89 = v95;
      v90 = v99;
      v92 = v97;
    }
    if ( (v16 & 0x3FFFFFFF) >= (signed int)v11 )
    {
      v19 = 0;
      v91.m_enum = 0;
    }
    else
    {
      v18 = v11;
      if ( (signed int)v11 < 2 * (v16 & 0x3FFFFFFF) )
        v18 = 2 * (v16 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v91, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v97, v18, 4);
      v8 = v95;
      v16 = v99;
      v10 = v97;
      v12 = array;
      v19 = v91.m_enum;
      v89 = v95;
      v90 = v99;
      v92 = v97;
    }
    if ( resulta.m_enum || v19 )
    {
      v98 = 0;
      v14->m_enum = 1;
      if ( v16 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v10,
          4 * v16);
        v8 = v95;
        v12 = array;
      }
      v97 = 0i64;
      v99 = 2147483648;
      v94 = 0;
      if ( v8 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v12,
          4 * v8);
      return v14;
    }
    vertexMap = v105;
    v15 = v94;
  }
  v21 = v9->m_startEdgeIndex;
  v22 = 0;
  resulta.m_enum = -1;
  v23 = v21;
  v24 = v13->m_edges.m_data;
  v25 = v11;
  if ( (signed int)v11 <= 0 )
    goto LABEL_121;
  v26 = (signed __int64)&v24[v23].m_oppositeFace;
  do
  {
    v27 = vertexMap->m_data[*(signed int *)(v26 - 12)];
    v91.m_enum = vertexMap->m_data[*(signed int *)(v26 - 8)];
    if ( v27 != v91.m_enum )
    {
      v28 = 0i64;
      if ( v15 <= 0 )
        goto LABEL_26;
      while ( *(_DWORD *)&v12[4 * v28] != v27 )
      {
        if ( ++v28 >= v15 )
          goto LABEL_26;
      }
      if ( v28 < 0 )
      {
LABEL_26:
        if ( v15 == (v8 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
          v12 = array;
          v15 = v94;
        }
        *(_DWORD *)&v12[4 * v15] = v27;
        v29 = v98;
        ++v94;
        if ( v98 == (v99 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v97, 4);
          v29 = v98;
        }
        *(_DWORD *)&v97[4 * v29] = 1;
        ++v98;
      }
      else if ( ++*(_DWORD *)&v10[4 * v28] >= 2 )
      {
        resulta.m_enum = v22;
        ++v7;
      }
      v30 = edgeIndices;
      v31 = v22 + v104->m_startEdgeIndex;
      if ( edgeIndices->m_size == (edgeIndices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, edgeIndices, 4);
      v30->m_data[v30->m_size] = v31;
      v32 = dstEdges;
      ++v30->m_size;
      if ( v32->m_size == (v32->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v32, 20);
      v33 = v32->m_size;
      vertexMap = v105;
      v34 = (signed __int64)&v32->m_data[v33];
      v32->m_size = v33 + 1;
      *(_DWORD *)v34 = *(_DWORD *)(v26 - 12);
      *(_DWORD *)(v34 + 4) = *(_DWORD *)(v26 - 8);
      *(_DWORD *)(v34 + 8) = *(_DWORD *)(v26 - 4);
      *(_DWORD *)(v34 + 12) = *(_DWORD *)v26;
      *(_BYTE *)(v34 + 16) = *(_BYTE *)(v26 + 4);
      *(_BYTE *)(v34 + 17) = *(_BYTE *)(v26 + 5);
      *(_WORD *)(v34 + 18) = *(_WORD *)(v26 + 6);
      v35 = v91.m_enum;
      *(_DWORD *)v34 = v27;
      *(_DWORD *)(v34 + 4) = v35;
      v8 = v95;
      v12 = array;
      v16 = v99;
      v10 = v97;
    }
    v15 = v94;
    ++v22;
    v26 += 20i64;
    --v25;
  }
  while ( v25 );
  v92 = v10;
  v90 = v16;
  v89 = v8;
  if ( (signed int)resulta.m_enum < 0 )
  {
LABEL_121:
    v37 = v102;
    v98 = 0;
    v102->m_enum = 0;
    if ( v16 >= 0 )
    {
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkArray<int,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v10,
        (unsigned int)(4 * v16),
        vertexMap);
      v8 = v95;
      v12 = array;
    }
    v97 = 0i64;
    v99 = 2147483648;
    v94 = 0;
    if ( v8 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkArray<int,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v12,
        (unsigned int)(4 * v8),
        vertexMap);
  }
  else if ( v7 <= 1 )
  {
    v38 = dstEdges;
    v39 = 0;
    v40 = dstEdges->m_size;
    if ( (signed int)v40 > 0 )
    {
      v41 = dstEdges->m_data;
      do
      {
        v42 = 0i64;
        if ( v94 <= 0i64 )
        {
LABEL_51:
          v42 = -1i64;
        }
        else
        {
          while ( *(_DWORD *)&v12[4 * v42] != v41->m_a )
          {
            if ( ++v42 >= v94 )
              goto LABEL_51;
          }
        }
        if ( *(_DWORD *)&v10[4 * v42] > 1 )
          break;
        ++v39;
        ++v41;
      }
      while ( v39 < (signed int)v40 );
      if ( v39 > 0 )
      {
        v43 = v40 + v39;
        v44 = dstEdges->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v44 < (signed int)v40 + v39 )
        {
          v45 = 2 * v44;
          if ( v43 < v45 )
            v43 = v45;
          hkArrayUtil::_reserve(
            (hkResult *)&v104,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            dstEdges,
            v43,
            20);
        }
        v46 = v38->m_data;
        v38->m_size += v39;
        v47 = (signed __int64)&v46[v40];
        if ( 5 * v39 > 0 )
        {
          v48 = (unsigned int)(5 * v39);
          do
          {
            v49 = v46->m_a;
            v47 += 4i64;
            v46 = (hkaiNavMesh::Edge *)((char *)v46 + 4);
            *(_DWORD *)(v47 - 4) = v49;
            --v48;
          }
          while ( v48 );
        }
        hkString::memMove(v38->m_data, &v38->m_data[v39], 20 * v40);
        v50 = v38->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v50 < (signed int)v40 )
        {
          v51 = 2 * v50;
          v52 = v40;
          if ( (signed int)v40 < v51 )
            v52 = v51;
          hkArrayUtil::_reserve(
            (hkResult *)&v104,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            v38,
            v52,
            20);
        }
        v53 = edgeIndices;
        v38->m_size = v40;
        v54 = v53->m_size;
        v55 = v54 + v39;
        v56 = v53->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v56 < (signed int)v54 + v39 )
        {
          v57 = 2 * v56;
          if ( v55 < v57 )
            v55 = v57;
          hkArrayUtil::_reserve(
            (hkResult *)&v104,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            v53,
            v55,
            4);
        }
        v58 = v53->m_data;
        v53->m_size += v39;
        v59 = (signed __int64)&v58[v54];
        if ( v39 > 0 )
        {
          v60 = (unsigned int)v39;
          do
          {
            v61 = *v58;
            v59 += 4i64;
            ++v58;
            *(_DWORD *)(v59 - 4) = v61;
            --v60;
          }
          while ( v60 );
        }
        hkString::memMove(v53->m_data, &v53->m_data[v39], 4 * v40);
        v62 = v53->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v62 < (signed int)v40 )
        {
          v63 = 2 * v62;
          v64 = v40;
          if ( (signed int)v40 < v63 )
            v64 = v63;
          hkArrayUtil::_reserve(
            (hkResult *)&v104,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            v53,
            v64,
            4);
        }
        v8 = v95;
        v10 = v97;
        v12 = array;
        v53->m_size = v40;
        v16 = v99;
        v89 = v8;
        v90 = v99;
        v92 = v10;
      }
    }
    v65 = v38->m_size;
    v66 = -1;
    v67 = 0;
    v68 = 0i64;
    resulta.m_enum = -1;
    v69 = 0.0 - 1.0;
    LODWORD(v104) = -1;
    if ( v65 <= 0 )
      goto LABEL_122;
    v70 = dstEdges;
    v71 = v94;
    do
    {
      v72 = v68 + 1;
      v73 = v67 + 1;
      if ( v68 + 1 < v65 )
      {
        v74 = &v70->m_data[v72];
        do
        {
          v75 = 0i64;
          if ( (signed int)v71 <= 0 )
          {
LABEL_85:
            v75 = -1i64;
          }
          else
          {
            while ( *(_DWORD *)&v12[4 * v75] != v74->m_a )
            {
              if ( ++v75 >= v71 )
                goto LABEL_85;
            }
          }
          if ( *(_DWORD *)&v10[4 * v75] > 1 )
            break;
          ++v72;
          ++v73;
          ++v74;
        }
        while ( v72 < v65 );
      }
      if ( v73 - v67 > 1 )
      {
        calcArea(&v101, mesha, &v70->m_data[v67], v73 - v67);
        if ( v101.m_real.m128_f32[0] <= v69 )
        {
          v66 = (signed int)v104;
        }
        else
        {
          v69 = v101.m_real.m128_f32[0];
          resulta.m_enum = v67;
          v66 = v73 - v67;
          LODWORD(v104) = v73 - v67;
        }
      }
      v10 = v92;
      v68 = v72;
      v67 = v73;
    }
    while ( v72 < v65 );
    v8 = v89;
    v16 = v90;
    if ( v66 <= 1 )
    {
LABEL_122:
      v87 = edgeIndices;
      v98 = 0;
      dstEdges->m_size = 0;
      v87->m_size = 0;
      v37 = v102;
      v102->m_enum = 0;
      if ( v16 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v92,
          4 * v16);
        v8 = v95;
        v12 = array;
      }
      v97 = 0i64;
      v99 = 2147483648;
      v94 = 0;
    }
    else
    {
      if ( (signed int)resulta.m_enum <= 0 )
      {
        v81 = v92;
        v82 = edgeIndices;
      }
      else
      {
        v76 = resulta.m_enum;
        v77 = dstEdges->m_data;
        v78 = &dstEdges->m_data[resulta.m_enum];
        if ( 5 * (signed int)v104 <= 0 )
        {
          v81 = v92;
        }
        else
        {
          v79 = (unsigned int)(5 * (_DWORD)v104);
          do
          {
            v80 = v78->m_a;
            v77 = (hkaiNavMesh::Edge *)((char *)v77 + 4);
            v78 = (hkaiNavMesh::Edge *)((char *)v78 + 4);
            *(_DWORD *)&v77[-1].m_flags.m_storage = v80;
            --v79;
          }
          while ( v79 );
          v8 = v95;
          v12 = array;
          v16 = v99;
          v81 = v97;
        }
        v82 = edgeIndices;
        v83 = edgeIndices->m_data;
        v84 = &edgeIndices->m_data[v76];
        v66 = (signed int)v104;
        if ( (signed int)v104 > 0 )
        {
          v85 = (unsigned int)v104;
          do
          {
            v86 = *v84;
            ++v83;
            ++v84;
            *(v83 - 1) = v86;
            --v85;
          }
          while ( v85 );
          v8 = v95;
          v12 = array;
          v16 = v99;
          v81 = v97;
        }
      }
      dstEdges->m_size = v66;
      v82->m_size = v66;
      v37 = v102;
      v98 = 0;
      v102->m_enum = 0;
      if ( v16 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v81,
          4 * v16);
        v8 = v95;
        v12 = array;
      }
      v97 = 0i64;
      v99 = 2147483648;
      v94 = 0;
    }
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v12,
        4 * v8);
  }
  else
  {
    v36 = edgeIndices;
    v98 = 0;
    dstEdges->m_size = 0;
    v36->m_size = 0;
    v37 = v102;
    v102->m_enum = 0;
    if ( v16 >= 0 )
    {
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkArray<int,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v10,
        (unsigned int)(4 * v16),
        vertexMap);
      v8 = v95;
      v12 = array;
    }
    v97 = 0i64;
    v99 = 2147483648;
    v94 = 0;
    if ( v8 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkArray<int,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v12,
        (unsigned int)(4 * v8),
        vertexMap);
  }
  return v37;
}

// File Line: 2218
// RVA: 0xB760D0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_mergeVertices(hkResult *result, hkaiNavMesh *mesh, float threshold)
{
  hkVector4f v3; // xmm3
  __int64 v4; // rdi
  float v5; // xmm6_4
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v6; // r13
  hkaiNavMesh *v7; // rsi
  hkResult *v8; // r15
  __int64 v9; // r12
  hkVector4f v10; // xmm2
  __m128 *v11; // rax
  __int64 v12; // rcx
  __int64 v13; // r14
  __m128 v14; // xmm1
  int v15; // er9
  int v16; // er9
  int v17; // er8
  int v18; // eax
  int v19; // ebx
  int v20; // er9
  int v21; // er8
  __int64 v22; // rdi
  hkVector4f *v23; // rsi
  int v24; // ebx
  int v25; // ecx
  int v26; // ebx
  int v27; // er9
  int v28; // eax
  int v29; // er9
  int v30; // ecx
  int v31; // er9
  int *v32; // rdi
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // r12
  __int64 v36; // r13
  hkaiNavMesh::Face *v37; // rbx
  int v38; // ecx
  hkaiNavMesh::Face *v39; // rbx
  int v40; // er9
  int v41; // er9
  hkResultEnum v42; // eax
  int v43; // er14
  int v44; // esi
  int v45; // eax
  __int64 v46; // r9
  int v47; // ecx
  __int64 v48; // rdi
  char *v49; // rdx
  int v50; // er8
  signed __int64 v51; // rdi
  signed __int64 v52; // r10
  int v53; // edx
  __int64 v54; // rcx
  signed __int64 v55; // rcx
  char *v56; // rcx
  int v57; // ecx
  hkResultEnum v58; // edi
  hkaiNavMesh::Edge *v59; // r8
  signed __int64 i; // rdi
  unsigned int v61; // edx
  int v62; // eax
  int v63; // er8
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+30h] [rbp-D0h]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+40h] [rbp-C0h]
  void *buffer; // [rsp+50h] [rbp-B0h]
  int v68; // [rsp+58h] [rbp-A8h]
  int v69; // [rsp+5Ch] [rbp-A4h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v70; // [rsp+60h] [rbp-A0h]
  void *array; // [rsp+70h] [rbp-90h]
  int v72; // [rsp+78h] [rbp-88h]
  int v73; // [rsp+7Ch] [rbp-84h]
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> dstEdges; // [rsp+80h] [rbp-80h]
  hkResult resultOut; // [rsp+90h] [rbp-70h]
  hkResult v76; // [rsp+94h] [rbp-6Ch]
  hkResult v77; // [rsp+98h] [rbp-68h]
  hkResult v78; // [rsp+9Ch] [rbp-64h]
  __int64 v79; // [rsp+A0h] [rbp-60h]
  hkAabb aabbIn; // [rsp+B0h] [rbp-50h]
  hkFindClosestPositionUtil v81; // [rsp+D0h] [rbp-30h]
  hkaiNavMesh *v82; // [rsp+208h] [rbp+108h]
  hkResult resulta; // [rsp+218h] [rbp+118h]

  v82 = mesh;
  v3.m_quad = (__m128)xmmword_141A712A0;
  v4 = mesh->m_vertices.m_size;
  v5 = threshold;
  v6 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mesh->m_vertices;
  v7 = mesh;
  aabbIn.m_min = (hkVector4f)xmmword_141A712A0;
  v8 = result;
  v9 = v4;
  v10.m_quad = _mm_xor_ps(
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                 (__m128)xmmword_141A712A0);
  aabbIn.m_max = (hkVector4f)v10.m_quad;
  if ( (signed int)v4 > 0 )
  {
    v11 = (__m128 *)v6->m_data;
    v12 = v4;
    do
    {
      v3.m_quad = _mm_min_ps(v3.m_quad, *v11);
      ++v11;
      aabbIn.m_min = (hkVector4f)v3.m_quad;
      v10.m_quad = _mm_max_ps(v10.m_quad, v11[-1]);
      aabbIn.m_max = (hkVector4f)v10.m_quad;
      --v12;
    }
    while ( v12 );
  }
  v13 = 0i64;
  v73 = 2147483648;
  resulta.m_enum = LODWORD(FLOAT_0_1);
  array = 0i64;
  v72 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  aabbIn.m_max.m_quad = _mm_add_ps(v10.m_quad, v14);
  aabbIn.m_min.m_quad = _mm_sub_ps(v3.m_quad, v14);
  if ( (signed int)v4 > 0 )
  {
    v15 = v4;
    if ( (signed int)v4 < 0 )
      v15 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
    if ( resulta.m_enum )
    {
      v8->m_enum = 1;
LABEL_9:
      v72 = 0;
      if ( v73 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v73);
      return v8;
    }
  }
  v72 = v4;
  a.m_data = 0i64;
  a.m_size = 0;
  a.m_capacityAndFlags = 2147483648;
  if ( (signed int)v4 > 0 )
  {
    v16 = v4;
    if ( (signed int)v4 < 0 )
      v16 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, v16, 16);
    if ( resulta.m_enum )
    {
      v17 = a.m_capacityAndFlags;
      v8->m_enum = 1;
      a.m_size = 0;
      if ( v17 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          a.m_data,
          16 * v17);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 2147483648;
      goto LABEL_9;
    }
  }
  buffer = 0i64;
  v68 = 0;
  v69 = 2147483648;
  v18 = hkFindClosestPositionUtil::getSizeInBytesFor(v4);
  v19 = v18;
  if ( (v69 & 0x3FFFFFFF) >= v18 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v20 = v18;
    if ( v18 < 2 * (v69 & 0x3FFFFFFF) )
      v20 = 2 * (v69 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &buffer, v20, 1);
    if ( resulta.m_enum )
    {
      v21 = v69;
      v8->m_enum = 1;
      v68 = 0;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          buffer,
          v21 & 0x3FFFFFFF);
      buffer = 0i64;
      v69 = 2147483648;
      a.m_size = 0;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          a.m_data,
          16 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 2147483648;
LABEL_131:
      v72 = v13;
      goto LABEL_132;
    }
  }
  v68 = v19;
  hkFindClosestPositionUtil::hkFindClosestPositionUtil(&v81);
  hkFindClosestPositionUtil::start(&v81, &aabbIn, v5);
  hkFindClosestPositionUtil::setBuffer(&v81, buffer, v4);
  v22 = 0i64;
  if ( v9 <= 0 )
  {
LABEL_36:
    hkFindClosestPositionUtil::end(&v81);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_hashMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v81.m_hashMap);
    hkFreeList::freeAllMemory(&v81.m_boxFreeList);
    v81.m_positions.m_size = v13;
    if ( v81.m_positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v81.m_positions.m_data,
        16 * v81.m_positions.m_capacityAndFlags);
    v81.m_positions.m_data = 0i64;
    v81.m_positions.m_capacityAndFlags = 2147483648;
    v68 = 0;
    if ( v69 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        buffer,
        v69 & 0x3FFFFFFF);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v6, &a);
    a.m_size = v13;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        a.m_data,
        16 * a.m_capacityAndFlags);
    v26 = v7->m_edges.m_size;
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 2147483648;
    v70.m_data = 0i64;
    v70.m_size = 0;
    v70.m_capacityAndFlags = 2147483648;
    if ( v26 > 0 )
    {
      v27 = v26;
      if ( v26 < 0 )
        v27 = v13;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v70, v27, 20);
      if ( resulta.m_enum )
      {
        v8->m_enum = 1;
LABEL_47:
        v70.m_size = v13;
        if ( v70.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v70.m_data,
            20 * (v70.m_capacityAndFlags & 0x3FFFFFFF));
        v70.m_data = 0i64;
        v70.m_capacityAndFlags = 2147483648;
LABEL_128:
        facesToRemove.m_size = v13;
        if ( facesToRemove.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            facesToRemove.m_data,
            4 * facesToRemove.m_capacityAndFlags);
        facesToRemove.m_data = 0i64;
        facesToRemove.m_capacityAndFlags = 2147483648;
        goto LABEL_131;
      }
    }
    v28 = 0;
    a.m_data = 0i64;
    a.m_capacityAndFlags = 2147483648;
    a.m_size = 0;
    if ( v26 > 0 )
    {
      v29 = v26;
      if ( v26 < 0 )
        v29 = v13;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, v29, 4);
      if ( resulta.m_enum )
      {
        v8->m_enum = 1;
LABEL_62:
        a.m_size = v13;
        if ( a.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            a.m_data,
            4 * a.m_capacityAndFlags);
        a.m_data = 0i64;
        a.m_capacityAndFlags = 2147483648;
        goto LABEL_47;
      }
      v28 = a.m_size;
    }
    v30 = a.m_capacityAndFlags & 0x3FFFFFFF;
    if ( (a.m_capacityAndFlags & 0x3FFFFFFF) < v26 )
    {
      v31 = v26;
      if ( v26 < 2 * v30 )
        v31 = 2 * v30;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &a, v31, 4);
      v28 = a.m_size;
    }
    v32 = &a.m_data->m_fromOffset + v28;
    v33 = v26 - v28;
    if ( v26 - v28 > 0 )
    {
      while ( v33 )
      {
        *v32 = -1;
        ++v32;
        --v33;
      }
    }
    v34 = v7->m_faces.m_size;
    a.m_size = v26;
    resulta.m_enum = 0;
    v35 = 0i64;
    v79 = v34;
    if ( v34 <= 0 )
    {
LABEL_107:
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v7->m_edges,
        &v70);
      v59 = v7->m_edges.m_data;
      for ( i = (signed __int64)&v59[v7->m_edges.m_size]; v59 != (hkaiNavMesh::Edge *)i; ++v59 )
      {
        if ( v59->m_oppositeEdge != -1 )
        {
          v61 = *(&a.m_data->m_fromOffset + (signed int)v59->m_oppositeEdge);
          v59->m_oppositeEdge = v61;
          if ( v61 == -1 )
            v59->m_oppositeFace = -1;
        }
      }
      a.m_size = v13;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          a.m_data,
          4 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 2147483648;
      v70.m_size = 0;
      if ( v70.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v70.m_data,
          20 * (v70.m_capacityAndFlags & 0x3FFFFFFF));
      if ( facesToRemove.m_size > 0
        && (hkaiNavMeshUtils::removeFaces((hkResult *)&v82, v7, &facesToRemove, 1), (_DWORD)v82) )
      {
        v8->m_enum = 1;
      }
      else
      {
        v8->m_enum = v13;
      }
      goto LABEL_128;
    }
    v36 = 0i64;
    while ( 1 )
    {
      v37 = v7->m_faces.m_data;
      v38 = 2147483648;
      buffer = 0i64;
      v39 = &v37[v36];
      v68 = 0;
      v69 = 2147483648;
      dstEdges.m_data = 0i64;
      dstEdges.m_size = 0;
      dstEdges.m_capacityAndFlags = 2147483648;
      v40 = 2 * v39->m_numEdges;
      if ( v40 <= 0 )
      {
        v76.m_enum = (signed int)v13;
      }
      else
      {
        if ( v40 < 0 )
          v40 = v13;
        hkArrayUtil::_reserve(&v76, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &buffer, v40, 4);
        v38 = dstEdges.m_capacityAndFlags;
      }
      v41 = 2 * v39->m_numEdges;
      if ( (v38 & 0x3FFFFFFF) >= v41 )
      {
        v42 = (signed int)v13;
        resultOut.m_enum = (signed int)v13;
      }
      else
      {
        if ( v41 < 2 * (v38 & 0x3FFFFFFF) )
          v41 = 2 * (v38 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &resultOut,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &dstEdges,
          v41,
          20);
        v38 = dstEdges.m_capacityAndFlags;
        v42 = resultOut.m_enum;
      }
      if ( v76.m_enum || v42 )
        break;
      findUniqueEdgeLoop(
        &v77,
        v7,
        v39,
        (hkArray<int,hkContainerHeapAllocator> *)&array,
        &dstEdges,
        (hkArray<int,hkContainerTempAllocator> *)&buffer);
      if ( v77.m_enum )
      {
        v62 = dstEdges.m_capacityAndFlags;
        v8->m_enum = 1;
        dstEdges.m_size = v13;
        if ( v62 < 0 )
          goto LABEL_122;
        v63 = 5 * (v62 & 0x3FFFFFFF);
        goto LABEL_121;
      }
      v43 = v70.m_size;
      v39->m_startEdgeIndex = v70.m_size;
      v44 = dstEdges.m_size;
      v39->m_numEdges = dstEdges.m_size;
      v45 = v70.m_size;
      v46 = (unsigned int)(v70.m_size + v44);
      v47 = v70.m_capacityAndFlags & 0x3FFFFFFF;
      v48 = v70.m_size;
      if ( (v70.m_capacityAndFlags & 0x3FFFFFFF) >= (signed int)v46 )
      {
        v78.m_enum = 0;
      }
      else
      {
        if ( (signed int)v46 < 2 * v47 )
          LODWORD(v46) = 2 * v47;
        hkArrayUtil::_reserve(&v78, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v70, v46, 20);
        v45 = v70.m_size;
      }
      v70.m_size = v44 + v45;
      v49 = (char *)v70.m_data + 20 * v48;
      v50 = 0;
      if ( v44 > 0 )
      {
        v46 = 0i64;
        v51 = (signed __int64)(v49 + 8);
        v52 = -8i64 - (_QWORD)v49;
        do
        {
          v53 = v50++ + v43;
          v54 = *(signed int *)((char *)buffer + v46);
          v46 += 4i64;
          *(&a.m_data->m_fromOffset + v54) = v53;
          v55 = v52 + v51;
          v51 += 20i64;
          v56 = (char *)dstEdges.m_data + v55;
          *(_DWORD *)(v51 - 28) = *(_DWORD *)v56;
          *(_DWORD *)(v51 - 24) = *((_DWORD *)v56 + 1);
          *(_DWORD *)(v51 - 20) = *((_DWORD *)v56 + 2);
          *(_DWORD *)(v51 - 16) = *((_DWORD *)v56 + 3);
          *(_BYTE *)(v51 - 12) = v56[16];
          *(_BYTE *)(v51 - 11) = v56[17];
          *(_WORD *)(v51 - 10) = *((_WORD *)v56 + 9);
        }
        while ( v50 < v44 );
      }
      if ( v39->m_numEdges > 1 )
      {
        v58 = resulta.m_enum;
      }
      else
      {
        v57 = facesToRemove.m_size;
        if ( facesToRemove.m_size == (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &facesToRemove, 4);
          v57 = facesToRemove.m_size;
        }
        v58 = resulta.m_enum;
        facesToRemove.m_data[v57] = resulta.m_enum;
        ++facesToRemove.m_size;
        if ( !v39->m_numEdges )
          v39->m_startEdgeIndex = -1;
      }
      LODWORD(v13) = 0;
      dstEdges.m_size = 0;
      if ( dstEdges.m_capacityAndFlags >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMesh::Edge *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          dstEdges.m_data,
          20 * (dstEdges.m_capacityAndFlags & 0x3FFFFFFFu),
          v46);
      dstEdges.m_data = 0i64;
      dstEdges.m_capacityAndFlags = 2147483648;
      v68 = 0;
      if ( v69 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, void *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          buffer,
          (unsigned int)(4 * v69),
          v46);
      v7 = v82;
      ++v35;
      ++v36;
      buffer = 0i64;
      v69 = 2147483648;
      resulta.m_enum = v58 + 1;
      if ( v35 >= v79 )
        goto LABEL_107;
    }
    v8->m_enum = 1;
    dstEdges.m_size = v13;
    if ( v38 >= 0 )
    {
      v63 = 5 * (v38 & 0x3FFFFFFF);
LABEL_121:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        dstEdges.m_data,
        4 * v63);
    }
LABEL_122:
    dstEdges.m_data = 0i64;
    dstEdges.m_capacityAndFlags = 2147483648;
    v68 = 0;
    if ( v69 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        buffer,
        4 * v69);
    buffer = 0i64;
    v69 = 2147483648;
    goto LABEL_62;
  }
  while ( 1 )
  {
    v23 = (hkVector4f *)((char *)v6->m_data + v13);
    v24 = hkFindClosestPositionUtil::findClosest(&v81, (hkVector4f *)((char *)v6->m_data + v13));
    if ( v24 < 0 )
      break;
LABEL_34:
    ++v22;
    v13 += 16i64;
    *((_DWORD *)array + v22 - 1) = v24;
    if ( v22 >= v9 )
    {
      v7 = v82;
      LODWORD(v13) = 0;
      goto LABEL_36;
    }
  }
  resultOut.m_enum = 0;
  v24 = hkFindClosestPositionUtil::addPoint(&v81, v23, &resultOut);
  if ( resultOut.m_enum == HK_SUCCESS )
  {
    v25 = a.m_size;
    if ( a.m_size == (a.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 16);
      v25 = a.m_size;
    }
    a.m_data[v25] = (hkRelocationInfo::Import)v23->m_quad;
    ++a.m_size;
    goto LABEL_34;
  }
  v8->m_enum = 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_hashMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v81.m_hashMap);
  hkFreeList::freeAllMemory(&v81.m_boxFreeList);
  v81.m_positions.m_size = 0;
  if ( v81.m_positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v81.m_positions.m_data,
      16 * v81.m_positions.m_capacityAndFlags);
  v81.m_positions.m_data = 0i64;
  v81.m_positions.m_capacityAndFlags = 2147483648;
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buffer,
      v69 & 0x3FFFFFFF);
  buffer = 0i64;
  v69 = 2147483648;
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      a.m_data,
      16 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  a.m_capacityAndFlags = 2147483648;
  v72 = 0;
LABEL_132:
  if ( v73 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v73);
  return v8;
}

// File Line: 2385
// RVA: 0xB76CE0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_removeDegenerateFaces(hkResult *result, hkaiNavMesh *mesh)
{
  __int64 v2; // rdi
  hkSimdFloat32 *v3; // r15
  hkResult *v4; // r14
  int v5; // er9
  __int64 v6; // rsi
  unsigned int v7; // ebx
  __int64 v8; // rdi
  __int64 v9; // rcx
  hkVector4f *sizeElem; // [rsp+20h] [rbp-40h]
  _DWORD *array; // [rsp+30h] [rbp-30h]
  int v13; // [rsp+38h] [rbp-28h]
  int v14; // [rsp+3Ch] [rbp-24h]
  int faceIndex; // [rsp+40h] [rbp-20h]
  char v16; // [rsp+50h] [rbp-10h]
  hkResult resulta; // [rsp+98h] [rbp+38h]

  v2 = mesh->m_faces.m_size;
  v3 = (hkSimdFloat32 *)mesh;
  v4 = result;
  v14 = 2147483648;
  array = 0i64;
  v13 = 0;
  if ( (signed int)v2 > 0 )
  {
    v5 = v2;
    if ( (signed int)v2 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v5, 4);
    if ( resulta.m_enum )
    {
      v4->m_enum = 1;
      goto LABEL_21;
    }
  }
  v6 = v2;
  v7 = 0;
  if ( (signed int)v2 > 0 )
  {
    v8 = 0i64;
    while ( *(_WORD *)(v3[1].m_real.m128_u64[0] + v8 + 8) > 2 )
    {
      if ( COERCE_FLOAT(*hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                           (hkaiNavMeshUtils *)&v16,
                           v3,
                           (hkaiNavMesh *)v7,
                           (unsigned __int64)&faceIndex,
                           sizeElem)) == 0.0 )
      {
        LODWORD(v9) = v13;
        if ( v13 == (v14 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
          LODWORD(v9) = v13;
        }
        v9 = (signed int)v9;
        goto LABEL_16;
      }
LABEL_17:
      ++v7;
      v8 += 16i64;
      if ( !--v6 )
        goto LABEL_18;
    }
    if ( v13 == (v14 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
    v9 = v13;
LABEL_16:
    array[v9] = v7;
    ++v13;
    goto LABEL_17;
  }
LABEL_18:
  hkaiNavMeshUtils::removeFaces(&resulta, (hkaiNavMesh *)v3, (hkArray<int,hkContainerTempAllocator> *)&array, 1);
  if ( resulta.m_enum )
    v4->m_enum = 1;
  else
    v4->m_enum = 0;
LABEL_21:
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v14);
  return v4;
}

// File Line: 2421
// RVA: 0xB729F0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(hkResult *result, hkaiNavMesh *navMesh, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometryRaycaster *raycaster, hkaiNavMeshGenerationProgressCallback *callbacks)
{
  hkaiEdgeGeometryRaycaster *v5; // r14
  hkaiNavMeshGenerationSettings *v6; // rsi
  hkaiNavMesh *v7; // rbp
  hkResult *v8; // rbx
  char v9; // al
  int v10; // er8
  hkaiNavMeshGenerationResult::GenerationResultEnum v11; // eax
  int v12; // er8
  hkaiNavMeshGenerationSettings::RegionPruningSettings pruneSettings; // [rsp+20h] [rbp-28h]
  hkResult resulta; // [rsp+60h] [rbp+18h]

  v5 = raycaster;
  v6 = input;
  v7 = navMesh;
  v8 = result;
  if ( input->m_minCharacterWidth <= 0.0 )
    goto LABEL_15;
  v9 = input->m_characterWidthUsage.m_storage;
  if ( !(v9 & 2) )
  {
    if ( v9 & 1 )
    {
      hkaiNavMeshGenerationUtils::_blockUntraversableEdges(&resulta, navMesh, input, raycaster);
      if ( resulta.m_enum )
        goto LABEL_4;
    }
LABEL_15:
    v8->m_enum = 0;
    return v8;
  }
  hkaiNavMeshGenerationUtils::_blockUntraversableEdges(&resulta, navMesh, input, raycaster);
  if ( resulta.m_enum )
  {
LABEL_4:
    v8->m_enum = 1;
    return v8;
  }
  hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(&pruneSettings);
  hkaiNavMeshGenerationSettings::RegionPruningSettings::operator=(&pruneSettings, &v6->m_regionPruningSettings);
  pruneSettings.m_borderPreservationTolerance = 0.0;
  hkaiNavMeshGenerationUtils::_pruneRegions(&resulta, v7, &v6->m_up, &pruneSettings);
  if ( resulta.m_enum )
  {
    v10 = pruneSettings.m_regionSeedPoints.m_capacityAndFlags;
    v8->m_enum = 1;
    pruneSettings.m_regionSeedPoints.m_size = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pruneSettings.m_regionSeedPoints.m_data,
        16 * v10);
    return v8;
  }
  v11 = hkaiNavMeshErosion::erode(v7, v6, v5, callbacks);
  v12 = pruneSettings.m_regionSeedPoints.m_capacityAndFlags;
  pruneSettings.m_regionSeedPoints.m_size = 0;
  if ( v11 == 5 )
  {
    if ( pruneSettings.m_regionSeedPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pruneSettings.m_regionSeedPoints.m_data,
        16 * pruneSettings.m_regionSeedPoints.m_capacityAndFlags);
    goto LABEL_15;
  }
  v8->m_enum = 1;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pruneSettings.m_regionSeedPoints.m_data,
      16 * v12);
  return v8;
}

// File Line: 2459
// RVA: 0xB73450
hkResult *__usercall hkaiNavMeshGenerationUtils::_pruneTriangles@<rax>(hkResult *result@<rcx>, hkGeometry *triMeshIn@<rdx>, hkaiNavMeshGenerationSettings *settings@<r8>, hkBitField *walkableInOut@<r9>, __m128 a5@<xmm0>, __m128 a6@<xmm6>)
{
  __int64 v6; // r10
  __int64 v7; // r14
  float v8; // xmm4_4
  float v9; // xmm2_4
  hkBitField *v10; // r11
  hkaiNavMeshGenerationSettings *v11; // r13
  hkGeometry *v12; // r15
  hkResult *v13; // rdi
  char *v14; // rax
  hkResultEnum v15; // xmm0_4
  hkFixedArray<int> v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  int v20; // er9
  int v21; // er8
  __m128i v22; // xmm7
  __m128 v23; // xmm5
  int v24; // er8
  __int64 v26; // rsi
  int v27; // ebx
  __int64 v28; // rdi
  hkVector4f *v29; // rdx
  hkGeometry::Triangle *v30; // rcx
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  int v36; // er12
  signed __int64 v37; // rdx
  int v38; // esi
  int v39; // ebx
  int v40; // er9
  signed int v41; // er8
  int v42; // er9
  hkResultEnum v43; // eax
  hkLifoAllocator *v44; // rax
  int *v45; // rcx
  int v46; // ebx
  char *v47; // rdx
  unsigned int v48; // ecx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  hk1AxisSweep::AabbInt *v51; // rdi
  int v52; // er12
  int v53; // ebx
  signed __int64 v54; // rcx
  unsigned int v55; // er8
  hk1AxisSweep::AabbInt *v56; // rdx
  signed __int64 v57; // rcx
  unsigned int v58; // er8
  hk1AxisSweep::AabbInt *v59; // rdx
  hkResult *v60; // rsi
  int *v61; // rdi
  signed int v62; // ebx
  hkLifoAllocator *v63; // rax
  int v64; // er8
  hk1AxisSweep::AabbInt *v65; // rbx
  int v66; // er8
  hkResultEnum v67; // edi
  __m128 v68; // xmm0
  signed __int64 v69; // rdx
  __int64 v70; // rsi
  signed int v71; // er12
  hk1AxisSweep::AabbInt *v72; // r14
  __m128 v73; // xmm9
  __m128 v74; // xmm8
  bool v75; // di
  int v76; // er14
  __int64 v77; // r10
  hkVector4f v78; // xmm14
  int v79; // edx
  hkVector4f v80; // xmm15
  __m128 v81; // xmm7
  __int64 v82; // r9
  unsigned int *v83; // r11
  __int64 v84; // rcx
  signed __int64 v85; // r8
  __int64 v86; // rdx
  __int64 v87; // rcx
  __m128 v88; // xmm6
  signed __int64 v89; // rax
  __m128 v90; // xmm10
  signed __int64 v91; // rax
  __m128 v92; // xmm5
  __m128 v93; // xmm11
  __m128 v94; // xmm1
  __m128 v95; // xmm2
  __m128 v96; // xmm2
  __m128 v97; // xmm2
  __m128 v98; // xmm4
  __m128 v99; // xmm1
  __m128 *v100; // rcx
  __m128 v101; // xmm15
  __int64 v102; // rdx
  __m128 v103; // xmm13
  __m128 v104; // xmm12
  __m128 v105; // xmm14
  __m128 v106; // xmm1
  __m128 v107; // xmm6
  __m128 v108; // xmm6
  __m128 v109; // xmm8
  __m128 v110; // xmm9
  __m128 v111; // xmm7
  __m128 v112; // xmm10
  __m128 v113; // xmm4
  __m128 v114; // xmm2
  __m128 v115; // xmm4
  __m128 v116; // xmm2
  __m128 v117; // xmm3
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm4
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __m128 v123; // xmm3
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm0
  __m128 v127; // xmm5
  __m128 v128; // xmm4
  __m128 v129; // xmm1
  __m128 v130; // xmm3
  __m128 v131; // xmm2
  __m128 v132; // xmm5
  __m128 v133; // xmm2
  __m128 v134; // xmm3
  __m128 v135; // xmm5
  __m128 v136; // xmm0
  __m128 v137; // xmm1
  __m128 v138; // xmm2
  __m128 v139; // xmm2
  __m128 v140; // xmm1
  __m128 v141; // xmm2
  __m128 v142; // xmm7
  __m128 v143; // xmm4
  __m128 v144; // xmm9
  __m128 v145; // xmm10
  __m128 v146; // xmm1
  __m128 v147; // xmm2
  __m128 v148; // xmm5
  __m128 v149; // xmm1
  __m128 v150; // xmm4
  __m128 v151; // xmm2
  __m128 v152; // xmm0
  __m128 v153; // xmm2
  __m128 v154; // xmm2
  bool v155; // bl
  bool v156; // al
  __int64 v157; // rbx
  int v158; // er11
  int v159; // edi
  int v160; // er8
  hkBitField *v161; // rbx
  __int64 v162; // r9
  __int64 v163; // r10
  int *v164; // rdi
  signed int v165; // ebx
  hkLifoAllocator *v166; // rax
  int v167; // er8
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-A0h]
  int size; // [rsp+38h] [rbp-98h]
  int v170; // [rsp+3Ch] [rbp-94h]
  hkResult resulta; // [rsp+40h] [rbp-90h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+48h] [rbp-88h]
  hkResult v173; // [rsp+58h] [rbp-78h]
  int v174; // [rsp+5Ch] [rbp-74h]
  hkFixedArray<int> parents; // [rsp+60h] [rbp-70h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+70h] [rbp-60h]
  int v177; // [rsp+80h] [rbp-50h]
  int v178; // [rsp+88h] [rbp-48h]
  hkAabb aabbIn; // [rsp+90h] [rbp-40h]
  hkAabb meshAabb; // [rsp+B0h] [rbp-20h]
  __m128 v181; // [rsp+D0h] [rbp+0h]
  hkUnionFind v182; // [rsp+E0h] [rbp+10h]
  __m128 v183; // [rsp+100h] [rbp+30h]
  __m128 v184; // [rsp+110h] [rbp+40h]
  __int128 v185; // [rsp+120h] [rbp+50h]
  __m128 v186; // [rsp+130h] [rbp+60h]
  __m128 v187; // [rsp+140h] [rbp+70h]
  __m128 v188; // [rsp+150h] [rbp+80h]
  __m128 v189; // [rsp+160h] [rbp+90h]
  __m128 v190; // [rsp+170h] [rbp+A0h]
  __m128 v191; // [rsp+180h] [rbp+B0h]
  hkVector4f expansion; // [rsp+190h] [rbp+C0h]
  __m128 v193; // [rsp+1A0h] [rbp+D0h]
  hkResult *v194; // [rsp+2A0h] [rbp+1D0h]
  __int64 i; // [rsp+2A8h] [rbp+1D8h]
  hkResult v196; // [rsp+2B0h] [rbp+1E0h]
  hkBitField *v197; // [rsp+2B8h] [rbp+1E8h]

  v6 = settings->m_overrideSettings.m_size;
  v7 = triMeshIn->m_triangles.m_size;
  v8 = settings->m_edgeMatchingParams.m_maxStepHeight;
  v9 = settings->m_edgeMatchingParams.m_maxSeparation;
  v10 = walkableInOut;
  v11 = settings;
  v12 = triMeshIn;
  v13 = result;
  if ( v6 > 0 )
  {
    v14 = (char *)&settings->m_overrideSettings.m_data->m_edgeMatchingParams.m_maxSeparation;
    do
    {
      v15 = *((_DWORD *)v14 - 1);
      resulta.m_enum = LODWORD(v8);
      v14 += 240;
      v196.m_enum = v15;
      a5.m128_i32[0] = *((_DWORD *)v14 - 60);
      v8 = fmaxf(v8, *(float *)&v196.m_enum);
      v196.m_enum = LODWORD(v9);
      resulta.m_enum = a5.m128_i32[0];
      a5 = (__m128)a5.m128_u32[0];
      v9 = fmaxf(v9, a5.m128_f32[0]);
      --v6;
    }
    while ( v6 );
  }
  if ( settings->m_wallClimbingSettings.m_enableWallClimbing.m_bool )
  {
    v196.m_enum = LODWORD(v8);
    resulta.m_enum = LODWORD(v9);
    a6.m128_f32[0] = fmaxf(v8, v9);
    v16 = (hkFixedArray<int>)_mm_shuffle_ps(a6, a6, 0);
  }
  else
  {
    a5.m128_f32[0] = v9;
    v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&settings->m_up), 1u), 1u);
    parents = (hkFixedArray<int>)_mm_shuffle_ps(a5, a5, 0);
    *((float *)&parents.m_data.m_storage
    + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                             _mm_and_ps(
                                                               _mm_cmpleps(
                                                                 _mm_max_ps(
                                                                   _mm_shuffle_ps(v17, v17, 170),
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v17, v17, 85),
                                                                     _mm_shuffle_ps(v17, v17, 0))),
                                                                 v17),
                                                               (__m128)xmmword_141A4D050))]) = v8;
    v16 = parents;
  }
  v18 = (__m128)xmmword_141A712A0;
  v19 = _mm_mul_ps((__m128)v16, (__m128)xmmword_141A711B0);
  v20 = v7 + 4;
  v170 = 2147483648;
  meshAabb.m_min = (hkVector4f)xmmword_141A712A0;
  array = 0i64;
  v21 = 0;
  size = 0;
  v22 = _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  _mm_store_si128((__m128i *)&v185, v22);
  v23 = _mm_xor_ps((__m128)v22, (__m128)xmmword_141A712A0);
  meshAabb.m_max.m_quad = v23;
  if ( (signed int)v7 + 4 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v20 < 0 )
      v20 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v20, 32);
    if ( resulta.m_enum )
    {
      v24 = v170;
      size = 0;
      v13->m_enum = 1;
      if ( v24 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          32 * v24);
      return v13;
    }
    v23 = meshAabb.m_max.m_quad;
    v18 = meshAabb.m_min.m_quad;
    v21 = size;
    v10 = v197;
  }
  v26 = v7;
  v27 = 0;
  if ( (signed int)v7 > 0 )
  {
    v28 = 0i64;
    do
    {
      if ( (v10->m_storage.m_words.m_data[(signed __int64)v27 >> 5] >> (v27 & 0x1F)) & 1 )
      {
        v29 = v12->m_vertices.m_data;
        v30 = v12->m_triangles.m_data;
        v31 = v29[v30[v28].m_b].m_quad;
        v32 = _mm_min_ps(_mm_min_ps(v29[v30[v28].m_a].m_quad, v31), v29[v30[v28].m_c].m_quad);
        v33 = _mm_max_ps(_mm_max_ps(v29[v30[v28].m_a].m_quad, v31), v29[v30[v28].m_c].m_quad);
        size = v21 + 1;
        aabbIn.m_min.m_quad = _mm_sub_ps(v32, v19);
        aabbIn.m_max.m_quad = _mm_add_ps(v33, v19);
        meshAabb.m_min.m_quad = _mm_min_ps(v18, aabbIn.m_min.m_quad);
        meshAabb.m_max.m_quad = _mm_max_ps(v23, aabbIn.m_max.m_quad);
        hk1AxisSweep::AabbInt::set(&array[v21], &aabbIn, v27);
        v21 = size;
        v10 = v197;
        v23 = meshAabb.m_max.m_quad;
        v18 = meshAabb.m_min.m_quad;
      }
      ++v27;
      ++v28;
      --v26;
    }
    while ( v26 );
    v13 = v194;
  }
  v34 = v11->m_boundsAabb.m_max.m_quad;
  v35 = v11->m_boundsAabb.m_min.m_quad;
  if ( !(_mm_movemask_ps(_mm_cmpleps(v11->m_boundsAabb.m_max.m_quad, v35)) & 7) )
  {
    aabbIn.m_min.m_quad = v18;
    meshAabb.m_min.m_quad = _mm_max_ps(v18, v35);
    meshAabb.m_max.m_quad = _mm_min_ps(v23, v34);
  }
  v36 = v21;
  v178 = v21;
  v37 = 4i64;
  while ( 1 )
  {
    size = v21 + 1;
    array[v21].m_min[0] = -1;
    if ( !--v37 )
      break;
    v21 = size;
  }
  v38 = 0;
  v39 = v36 + 4;
  sortedAabbs.m_capacityAndFlags = 2147483648;
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  if ( v36 + 4 <= 0 )
  {
    v196.m_enum = 0;
  }
  else
  {
    v40 = v36 + 4;
    if ( v39 < 0 )
      v40 = 0;
    hkArrayUtil::_reserve(&v196, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortedAabbs, v40, 32);
    if ( v196.m_enum )
    {
      v13->m_enum = 1;
LABEL_44:
      sortedAabbs.m_size = 0;
      if ( sortedAabbs.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * sortedAabbs.m_capacityAndFlags);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 2147483648;
      goto LABEL_62;
    }
  }
  v41 = 2147483648;
  sortedAabbs.m_size = v36 + 4;
  *(_QWORD *)&elementsPerGroup.m_size = 0i64;
  v173.m_enum = 0;
  v174 = 2147483648;
  if ( v39 <= 0 )
  {
    v43 = 0;
LABEL_39:
    v173.m_enum = v36 + 4;
    goto LABEL_40;
  }
  v42 = v36 + 4;
  if ( v39 < 0 )
    v42 = 0;
  hkArrayUtil::_reserve(
    &v173,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &elementsPerGroup.m_size,
    v42,
    8);
  v43 = v173.m_enum;
  v41 = v174;
  if ( v173.m_enum == HK_SUCCESS )
    goto LABEL_39;
LABEL_40:
  v196.m_enum = v43;
  if ( v43 )
  {
    v173.m_enum = 0;
    v13->m_enum = 1;
    if ( v41 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)&elementsPerGroup.m_size,
        8 * v41);
    *(_QWORD *)&elementsPerGroup.m_size = 0i64;
    v174 = 2147483648;
    goto LABEL_44;
  }
  hk1AxisSweep::sortAabbs(array, v36, (hkArrayBase<hkRadixSort::SortData32> *)&elementsPerGroup.m_size, &sortedAabbs);
  v173.m_enum = 0;
  if ( v174 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&elementsPerGroup.m_size,
      8 * v174);
  *(_QWORD *)&elementsPerGroup.m_size = 0i64;
  v174 = 2147483648;
  sortedAabbs.m_size = 0;
  if ( sortedAabbs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      sortedAabbs.m_data,
      32 * sortedAabbs.m_capacityAndFlags);
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (int *)v44->m_cur;
  v46 = (4 * v7 + 127) & 0xFFFFFF80;
  v47 = (char *)v45 + v46;
  if ( v46 > v44->m_slabSize || v47 > v44->m_end )
    v45 = (int *)hkLifoAllocator::allocateFromNewSlab(v44, v46);
  else
    v44->m_cur = v47;
  parents.m_data.m_storage = v45;
  parents.m_size.m_storage = v7;
  if ( (signed int)v7 > 0 && !v45 )
  {
    v48 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v13->m_enum = 1;
    v49 = (hkLifoAllocator *)TlsGetValue(v48);
    v50 = (v46 + 15) & 0xFFFFFFF0;
    if ( v46 <= v49->m_slabSize && (void *)v50 == v49->m_cur && v49->m_firstNonLifoEnd )
      v49->m_cur = 0i64;
    else
      hkLifoAllocator::slowBlockFree(v49, 0i64, v50);
LABEL_62:
    size = 0;
    if ( v170 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        32 * v170);
    return v13;
  }
  hkUnionFind::hkUnionFind(&v182, &parents, v7);
  v51 = array;
  v52 = v36 - 1;
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_size = 0;
  elementsPerGroup.m_capacityAndFlags = 2147483648;
  parents.m_data.m_storage = 0i64;
  parents.m_size.m_storage = 0;
  *((_DWORD *)&parents.m_size + 1) = 2147483648;
  v182.m_isCollapsed = 0;
  v53 = 1;
  if ( v52 > 0 )
  {
    while ( 1 )
    {
      v54 = v38;
      v55 = array[v54].m_max[0];
      v56 = &array[v53];
      if ( v56->m_min[0] <= v55 )
        break;
LABEL_69:
      v53 = ++v38 + 1;
      if ( v38 >= v52 )
        goto LABEL_70;
    }
    while ( (((v56->m_max[2] - array[v54].m_min[2]) | (v56->m_max[1] - array[v54].m_min[1]) | (array[v54].m_max[2]
                                                                                             - v56->m_min[2]) | (array[v54].m_max[1] - v56->m_min[1])) & 0x80000000) != 0 )
    {
      v56 = &array[++v53];
      if ( v56->m_min[0] > v55 )
        goto LABEL_69;
    }
  }
LABEL_70:
  while ( v38 < v52 )
  {
    hkUnionFind::addEdge(&v182, *(_DWORD *)v51[v38].m_expansionMin, *(_DWORD *)v51[v53++].m_expansionMin);
    if ( v38 >= v52 )
      break;
    while ( 1 )
    {
      v57 = v38;
      v58 = v51[v57].m_max[0];
      v59 = &v51[v53];
      if ( v59->m_min[0] <= v58 )
        break;
LABEL_75:
      v53 = ++v38 + 1;
      if ( v38 >= v52 )
        goto LABEL_78;
    }
    while ( (((v59->m_max[2] - v51[v57].m_min[2]) | (v59->m_max[1] - v51[v57].m_min[1]) | (v51[v57].m_max[2]
                                                                                         - v59->m_min[2]) | (v51[v57].m_max[1] - v59->m_min[1])) & 0x80000000) != 0 )
    {
      v59 = &v51[++v53];
      if ( v59->m_min[0] > v58 )
        goto LABEL_75;
    }
  }
LABEL_78:
  hkUnionFind::assignGroups(&v182, &v196, &elementsPerGroup);
  if ( v196.m_enum
    || (hkUnionFind::sortByGroupId(&v182, &v173, &elementsPerGroup, (hkArray<int,hkContainerHeapAllocator> *)&parents),
        v173.m_enum) )
  {
    v60 = v194;
    v194->m_enum = 1;
  }
  else
  {
    v65 = (hk1AxisSweep::AabbInt *)elementsPerGroup.m_size;
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_size = 0;
    sortedAabbs.m_capacityAndFlags = 2147483648;
    v177 = 0;
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
      (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&sortedAabbs,
      &v196,
      0,
      elementsPerGroup.m_size,
      0);
    if ( v196.m_enum )
    {
      v60 = v194;
      v66 = sortedAabbs.m_capacityAndFlags;
      sortedAabbs.m_size = 0;
      v194->m_enum = 1;
      if ( v66 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          sortedAabbs.m_data,
          4 * v66);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 2147483648;
    }
    else
    {
      v67 = 0;
      v196.m_enum = 0;
      hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(
        &v11->m_regionPruningSettings,
        &v11->m_up,
        &expansion);
      v68 = (__m128)LODWORD(v11->m_regionPruningSettings.m_minDistanceToSeedPoints);
      v69 = 0i64;
      v173.m_enum = 0;
      v70 = 0i64;
      v189 = _mm_shuffle_ps(v68, v68, 0);
      sortedAabbs.m_data = v65;
      v71 = 1;
      *(_QWORD *)&elementsPerGroup.m_size = 0i64;
      v72 = v65;
      if ( (signed int)v65 > 0 )
      {
        do
        {
          v73 = (__m128)xmmword_141A712A0;
          v74 = aabbOut.m_quad;
          v75 = v11->m_regionPruningSettings.m_regionSeedPoints.m_size == 0;
          v76 = 0;
          v77 = v11->m_regionPruningSettings.m_regionSeedPoints.m_size;
          v78.m_quad = _mm_xor_ps((__m128)v22, (__m128)xmmword_141A712A0);
          aabbIn.m_min = (hkVector4f)xmmword_141A712A0;
          aabbIn.m_max = (hkVector4f)v78.m_quad;
          v79 = elementsPerGroup.m_data[v69];
          v80.m_quad = (__m128)xmmword_141A712A0;
          v81 = aabbOut.m_quad;
          if ( v79 > 0 )
          {
            v82 = (unsigned int)v79;
            v83 = v197->m_storage.m_words.m_data;
            do
            {
              v84 = parents.m_data.m_storage[v70++];
              if ( (v83[v84 >> 5] >> (v84 & 0x1F)) & 1 )
              {
                v85 = 2 * v84;
                ++v76;
                v86 = *(_QWORD *)(i + 16);
                v87 = *(_QWORD *)(i + 32);
                v88 = *(__m128 *)(v86 + 16i64 * *(signed int *)(v87 + 8 * v85));
                v89 = 2i64 * *(signed int *)(v87 + 8 * v85 + 4);
                v181 = v88;
                v90 = *(__m128 *)(v86 + 8 * v89);
                v91 = 2i64 * *(signed int *)(v87 + 8 * v85 + 8);
                v193 = v90;
                v93 = _mm_sub_ps(v90, v88);
                v184 = *(__m128 *)(v86 + 8 * v91);
                v92 = v184;
                v80.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v80.m_quad, v88), v90), v184);
                v78.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v78.m_quad, v88), v90), v184);
                v190 = v80.m_quad;
                aabbIn.m_min = (hkVector4f)v80.m_quad;
                v94 = _mm_sub_ps(v184, v88);
                v186 = v78.m_quad;
                aabbIn.m_max = (hkVector4f)v78.m_quad;
                v95 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v93),
                        _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v94));
                v96 = _mm_shuffle_ps(v95, v95, 201);
                v97 = _mm_mul_ps(v96, v96);
                v98 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170));
                v99 = _mm_rsqrt_ps(v98);
                v81 = _mm_add_ps(
                        v81,
                        _mm_andnot_ps(
                          _mm_cmpleps(v98, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v98), v99)),
                              _mm_mul_ps(*(__m128 *)_xmm, v99)),
                            v98)));
                v188 = v81;
                if ( !v75 && v77 > 0 )
                {
                  v100 = &v11->m_regionPruningSettings.m_regionSeedPoints.m_data->m_quad;
                  v101 = v88;
                  v102 = v77;
                  v103 = _mm_sub_ps(v88, v184);
                  v104 = _mm_sub_ps(v184, v90);
                  v105 = _mm_shuffle_ps(v104, v104, 201);
                  v183 = _mm_shuffle_ps(v74, _mm_unpackhi_ps(v74, (__m128)xmmword_141A712F0), 196);
                  v187 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, v73), 196);
                  v106 = _mm_shuffle_ps(v93, v93, 201);
                  v191 = v106;
                  v107 = _mm_sub_ps(_mm_mul_ps(v105, v93), _mm_mul_ps(v106, v104));
                  v108 = _mm_shuffle_ps(v107, v107, 201);
                  v181 = _mm_shuffle_ps(v103, v103, 201);
                  do
                  {
                    v109 = *v100;
                    v110 = _mm_sub_ps(*v100, v90);
                    v111 = _mm_sub_ps(*v100, v101);
                    v112 = _mm_sub_ps(*v100, v92);
                    v113 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), v93), _mm_mul_ps(v106, v111));
                    v114 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v104), _mm_mul_ps(v105, v110));
                    v115 = _mm_mul_ps(_mm_shuffle_ps(v113, v113, 201), v108);
                    v116 = _mm_mul_ps(_mm_shuffle_ps(v114, v114, 201), v108);
                    v117 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v112, v112, 201), v103), _mm_mul_ps(v181, v112));
                    v118 = _mm_unpacklo_ps(v115, v116);
                    v119 = _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), v108);
                    v120 = _mm_shuffle_ps(_mm_unpackhi_ps(v115, v116), v119, 228);
                    v121 = _mm_movelh_ps(v118, v119);
                    if ( (_mm_movemask_ps(
                            _mm_cmpltps(
                              v183,
                              _mm_add_ps(v120, _mm_add_ps(v121, _mm_shuffle_ps(_mm_movehl_ps(v121, v118), v119, 212))))) & 7) == 7 )
                    {
                      v122 = _mm_mul_ps(v108, v108);
                      v123 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v122, v122, 85), _mm_shuffle_ps(v122, v122, 0)),
                               _mm_shuffle_ps(v122, v122, 170));
                      v124 = _mm_mul_ps(v108, v111);
                      v125 = _mm_sub_ps(
                               v109,
                               _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmpeqps(v123, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_rcp_ps(v123),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                                       _mm_shuffle_ps(v124, v124, 170)))),
                                 v108));
                    }
                    else
                    {
                      v126 = _mm_mul_ps(v104, v104);
                      v127 = _mm_mul_ps(v93, v93);
                      v128 = _mm_mul_ps(v111, v93);
                      v129 = _mm_unpacklo_ps(v127, v126);
                      v130 = _mm_mul_ps(v103, v103);
                      v131 = _mm_movelh_ps(v129, v130);
                      v132 = _mm_shuffle_ps(_mm_unpackhi_ps(v127, v126), v130, 228);
                      v133 = _mm_add_ps(v131, _mm_shuffle_ps(_mm_movehl_ps(v131, v129), v130, 212));
                      v134 = _mm_mul_ps(v112, v103);
                      v135 = _mm_add_ps(v132, v133);
                      v136 = _mm_mul_ps(v110, v104);
                      v137 = _mm_unpacklo_ps(v128, v136);
                      v138 = _mm_movelh_ps(v137, v134);
                      v139 = _mm_andnot_ps(
                               _mm_cmpeqps(v135, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_rcp_ps(v135),
                                 _mm_add_ps(
                                   _mm_shuffle_ps(_mm_unpackhi_ps(v128, v136), v134, 228),
                                   _mm_add_ps(v138, _mm_shuffle_ps(_mm_movehl_ps(v138, v137), v134, 212)))));
                      v140 = _mm_cmpltps(v139, v187);
                      v141 = _mm_max_ps(v183, _mm_or_ps(_mm_and_ps(v140, v139), _mm_andnot_ps(v140, v187)));
                      v142 = _mm_sub_ps(v111, _mm_mul_ps(_mm_shuffle_ps(v141, v141, 0), v93));
                      v143 = _mm_mul_ps(v142, v142);
                      v144 = _mm_sub_ps(v110, _mm_mul_ps(_mm_shuffle_ps(v141, v141, 85), v104));
                      v145 = _mm_sub_ps(v112, _mm_mul_ps(_mm_shuffle_ps(v141, v141, 170), v103));
                      v146 = _mm_mul_ps(v144, v144);
                      v147 = _mm_cmpltps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                                 _mm_shuffle_ps(v143, v143, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v146, v146, 85), _mm_shuffle_ps(v146, v146, 0)),
                                 _mm_shuffle_ps(v146, v146, 170)));
                      v148 = _mm_or_ps(_mm_andnot_ps(v147, v144), _mm_and_ps(v147, v142));
                      v149 = _mm_mul_ps(v145, v145);
                      v150 = _mm_mul_ps(v148, v148);
                      v151 = _mm_cmpltps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
                                 _mm_shuffle_ps(v150, v150, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v149, v149, 85), _mm_shuffle_ps(v149, v149, 0)),
                                 _mm_shuffle_ps(v149, v149, 170)));
                      v152 = _mm_or_ps(_mm_andnot_ps(v151, v145), _mm_and_ps(v148, v151));
                      v92 = v184;
                      v125 = _mm_sub_ps(v109, v152);
                    }
                    v90 = v193;
                    v153 = _mm_sub_ps(v125, v109);
                    v154 = _mm_mul_ps(v153, v153);
                    v106 = v191;
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 170))) < v189.m128_f32[0] )
                      v75 = 1;
                    ++v100;
                    --v102;
                  }
                  while ( v102 );
                  v78.m_quad = v186;
                  v80.m_quad = v190;
                  v81 = v188;
                  v74 = aabbOut.m_quad;
                  v73 = (__m128)xmmword_141A712A0;
                }
              }
              --v82;
            }
            while ( v82 );
          }
          aabbIn.m_max.m_quad = _mm_add_ps(v78.m_quad, expansion.m_quad);
          aabbIn.m_min.m_quad = _mm_sub_ps(v80.m_quad, expansion.m_quad);
          v155 = (float)(v81.m128_f32[0] * 0.5) < v11->m_regionPruningSettings.m_minRegionArea;
          v156 = hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(&aabbIn, &meshAabb);
          if ( !v155 && v75 )
          {
            v67 = v196.m_enum;
          }
          else
          {
            v67 = v196.m_enum;
            if ( !v156 )
            {
              sortedAabbs.m_data->m_min[(signed __int64)(signed int)v173.m_enum >> 5] |= v71;
              v67 += v76;
              v196.m_enum = v67;
            }
          }
          v71 = __ROL4__(v71, 1);
          v72 = sortedAabbs.m_data;
          v22 = _mm_load_si128((const __m128i *)&v185);
          ++v173.m_enum;
          v69 = *(_QWORD *)&elementsPerGroup.m_size + 1i64;
          *(_QWORD *)&elementsPerGroup.m_size = v69;
        }
        while ( v69 < (_QWORD)sortedAabbs.m_data );
      }
      if ( v67 != v178 )
      {
        v157 = 0i64;
        v158 = 0;
        v159 = 0;
        for ( i = 0i64; v157 < (signed __int64)v72; i = v157 )
        {
          v160 = elementsPerGroup.m_data[v157];
          if ( (sortedAabbs.m_data->m_min[(signed __int64)v159 >> 5] >> (v159 & 0x1F)) & 1 )
          {
            if ( v160 > 0 )
            {
              v161 = v197;
              v162 = v158;
              v163 = (unsigned int)v160;
              v158 += v160;
              do
              {
                ++v162;
                v161->m_storage.m_words.m_data[(signed __int64)parents.m_data.m_storage[v162 - 1] >> 5] &= ~(1 << (parents.m_data.m_storage[v162 - 1] & 0x1F));
                --v163;
              }
              while ( v163 );
              v157 = i;
            }
          }
          else
          {
            v158 += v160;
          }
          ++v157;
          ++v159;
        }
        v60 = v194;
        v194->m_enum = 0;
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&sortedAabbs);
        parents.m_size.m_storage = 0;
        if ( *((_DWORD *)&parents.m_size + 1) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            parents.m_data.m_storage,
            4 * *((_DWORD *)&parents.m_size + 1));
        parents.m_data.m_storage = 0i64;
        *((_DWORD *)&parents.m_size + 1) = 2147483648;
        elementsPerGroup.m_size = 0;
        if ( elementsPerGroup.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            elementsPerGroup.m_data,
            4 * elementsPerGroup.m_capacityAndFlags);
        v164 = parents.m_data.m_storage;
        elementsPerGroup.m_data = 0i64;
        elementsPerGroup.m_capacityAndFlags = 2147483648;
        v165 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
        v166 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v167 = (v165 + 15) & 0xFFFFFFF0;
        if ( v165 > v166->m_slabSize || (char *)v164 + v167 != v166->m_cur || v166->m_firstNonLifoEnd == v164 )
          hkLifoAllocator::slowBlockFree(v166, v164, v167);
        else
          v166->m_cur = v164;
        size = 0;
        goto LABEL_135;
      }
      v60 = v194;
      v194->m_enum = 0;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&sortedAabbs);
    }
  }
  parents.m_size.m_storage = 0;
  if ( *((_DWORD *)&parents.m_size + 1) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      parents.m_data.m_storage,
      4 * *((_DWORD *)&parents.m_size + 1));
  elementsPerGroup.m_size = 0;
  *((_DWORD *)&parents.m_size + 1) = 2147483648;
  parents.m_data.m_storage = 0i64;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  v61 = parents.m_data.m_storage;
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_capacityAndFlags = 2147483648;
  v62 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v64 = (v62 + 15) & 0xFFFFFFF0;
  if ( v62 > v63->m_slabSize || (char *)v61 + v64 != v63->m_cur || v63->m_firstNonLifoEnd == v61 )
  {
    hkLifoAllocator::slowBlockFree(v63, v61, v64);
    size = 0;
  }
  else
  {
    v63->m_cur = v61;
    size = 0;
  }
LABEL_135:
  if ( v170 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      32 * v170);
  return v60;
}kMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      32 * v170);
  return v60;
}

// File Line: 2681
// RVA: 0xB72B90
hkResult *__fastcall hkaiNavMeshGenerationUtils::_pruneRegions(hkResult *result, hkaiNavMesh *mesh, hkVector4f *up, hkaiNavMeshGenerationSettings::RegionPruningSettings *pruneSettings)
{
  int v4; // edi
  int v5; // er15
  hkaiNavMeshGenerationSettings::RegionPruningSettings *v6; // rsi
  hkVector4f *v7; // rbx
  hkaiNavMesh *v8; // r13
  hkResult *v9; // r12
  int v10; // er9
  int v11; // er8
  int v12; // edx
  hkVector4f *v13; // rcx
  __m128 v14; // xmm6
  int v15; // eax
  __int64 v16; // r14
  int v17; // er9
  __int64 v18; // rdx
  __int64 v19; // rcx
  hkAabb *v20; // rax
  __m128 v21; // xmm6
  int v22; // edi
  float v23; // xmm6_4
  __int32 v24; // eax
  void *v25; // r9
  signed int v26; // er8
  int v27; // er9
  __int64 v28; // rcx
  int *v29; // rdi
  int v30; // eax
  __int64 v31; // rbx
  __int64 v32; // r12
  __int64 v33; // rdi
  __int64 v34; // rax
  __int64 v35; // rcx
  __m128 v36; // xmm1
  int v37; // edi
  __int64 v38; // rbx
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  int v41; // er9
  float v42; // xmm6_4
  int v43; // er15
  int v44; // edi
  bool v45; // zf
  bool v46; // si
  bool v47; // al
  int v48; // er9
  int v49; // edx
  int v50; // edi
  hkAabb *sizeElem; // [rsp+20h] [rbp-E0h]
  hkArray<float,hkContainerHeapAllocator> areasOut; // [rsp+30h] [rbp-D0h]
  hkAabb *v54; // [rsp+40h] [rbp-C0h]
  int v55; // [rsp+48h] [rbp-B8h]
  int v56; // [rsp+4Ch] [rbp-B4h]
  char *array; // [rsp+50h] [rbp-B0h]
  int v58; // [rsp+58h] [rbp-A8h]
  int v59; // [rsp+5Ch] [rbp-A4h]
  _DWORD *v60; // [rsp+60h] [rbp-A0h]
  int v61; // [rsp+68h] [rbp-98h]
  int v62; // [rsp+6Ch] [rbp-94h]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+70h] [rbp-90h]
  void *v64; // [rsp+80h] [rbp-80h]
  int v65; // [rsp+88h] [rbp-78h]
  int v66; // [rsp+8Ch] [rbp-74h]
  int v67; // [rsp+90h] [rbp-70h]
  hkErrStream v68; // [rsp+A0h] [rbp-60h]
  __int64 v69; // [rsp+C0h] [rbp-40h]
  hkVector4f position; // [rsp+D0h] [rbp-30h]
  hkSimdFloat32 extraRadius; // [rsp+E0h] [rbp-20h]
  __m128 v72; // [rsp+F0h] [rbp-10h]
  hkVector4f closestPointOut; // [rsp+100h] [rbp+0h]
  hkAabb aabbOut; // [rsp+110h] [rbp+10h]
  int faceIndex[4]; // [rsp+130h] [rbp+30h]
  char buf; // [rsp+140h] [rbp+40h]
  hkResult *v77; // [rsp+390h] [rbp+290h]
  hkResult resulta; // [rsp+398h] [rbp+298h]
  int v79; // [rsp+3A8h] [rbp+2A8h]

  v77 = result;
  v4 = mesh->m_faces.m_size;
  v5 = 0;
  v6 = pruneSettings;
  v7 = up;
  v8 = mesh;
  v9 = result;
  array = 0i64;
  v58 = 0;
  v59 = 2147483648;
  if ( v4 > 0 )
  {
    v10 = v4;
    if ( v4 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v10, 4);
    if ( resulta.m_enum )
    {
      v11 = v59;
      v9->m_enum = 1;
      v58 = 0;
      if ( v11 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v11);
      return v9;
    }
  }
  v12 = v8->m_vertices.m_size;
  v13 = v8->m_vertices.m_data;
  aabbOut.m_min = (hkVector4f)xmmword_141A712A0;
  v58 = v4;
  v14 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  aabbOut.m_max.m_quad = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
  hkAabbUtil::calcAabb(v13, v12, &aabbOut);
  areasOut.m_data = 0i64;
  areasOut.m_size = 0;
  areasOut.m_capacityAndFlags = 2147483648;
  v15 = hkaiNavMeshUtils::computeRegions(v8, 1, (hkArrayBase<int> *)&array, &areasOut);
  v16 = v15;
  v79 = v15;
  if ( v15 != -1 )
  {
    if ( !v15 )
    {
      hkErrStream::hkErrStream(&v68, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v68.vfptr, "No regions found. Empty nav mesh?");
      hkError::messageWarning(640513734, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 2706);
      hkOstream::~hkOstream((hkOstream *)&v68.vfptr);
      v9->m_enum = 0;
      goto LABEL_9;
    }
    v54 = 0i64;
    v55 = 0;
    v56 = 2147483648;
    if ( v15 <= 0 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v17 = v15;
      if ( v15 < 0 )
        v17 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v54, v17, 32);
      if ( resulta.m_enum )
      {
        v9->m_enum = 1;
LABEL_19:
        v55 = 0;
        if ( v56 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v54,
            32 * v56);
        v54 = 0i64;
        v56 = 2147483648;
        goto LABEL_9;
      }
    }
    v55 = v16;
    v18 = v16;
    if ( (signed int)v16 > 0 )
    {
      v19 = 0i64;
      do
      {
        v20 = v54;
        ++v19;
        v54[v19 - 1].m_min = (hkVector4f)xmmword_141A712A0;
        *((__m128 *)&v20[v19] - 1) = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
        --v18;
      }
      while ( v18 );
    }
    v21 = (__m128)LODWORD(v6->m_minDistanceToSeedPoints);
    v64 = 0i64;
    v22 = ((signed int)v16 + 31) >> 5;
    v65 = 0;
    v66 = 2147483648;
    v21.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v21, v21, 0);
    v23 = v21.m128_f32[0] * v21.m128_f32[0];
    v24 = v22;
    if ( v22 )
    {
      resulta.m_enum = 4 * v22;
      v25 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (int *)&resulta);
      v24 = resulta.m_enum / 4;
    }
    else
    {
      v25 = 0i64;
    }
    v26 = 2147483648;
    v64 = v25;
    if ( v24 )
      v26 = v24;
    v65 = ((signed int)v16 + 31) >> 5;
    v67 = v16;
    v66 = v26;
    if ( (v26 & 0x3FFFFFFF) < v22 )
    {
      v27 = ((signed int)v16 + 31) >> 5;
      if ( v22 < 2 * (v26 & 0x3FFFFFFF) )
        v27 = 2 * (v26 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v64, v27, 4);
      v26 = v66;
      v25 = v64;
    }
    v65 = ((signed int)v16 + 31) >> 5;
    if ( !v25 )
    {
      v9->m_enum = 1;
      v65 = 0;
      if ( v26 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          0i64,
          4 * v26);
      v64 = 0i64;
      v66 = 2147483648;
      goto LABEL_19;
    }
    if ( v22 - 1 >= 0 )
    {
      v28 = (unsigned int)v22;
      v29 = (int *)v25;
      v30 = -(v6->m_regionSeedPoints.m_size <= 0);
      while ( v28 )
      {
        *v29 = v30;
        ++v29;
        --v28;
      }
    }
    hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(v6, v7, (hkVector4f *)&v68);
    v31 = 0i64;
    if ( v8->m_faces.m_size > 0 )
    {
      v32 = 0i64;
      do
      {
        v33 = *(signed int *)&array[v32];
        *(hkVector4f *)faceIndex = (hkVector4f)::aabbOut.m_quad;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>(
          (hkaiNavMeshUtils *)v8,
          (hkaiNavMesh *)(unsigned int)v5,
          (unsigned __int64)faceIndex,
          &extraRadius,
          sizeElem);
        v34 = (__int64)&v54[v33];
        v35 = v33 >> 5;
        LODWORD(v33) = v33 & 0x1F;
        v69 = v35;
        resulta.m_enum = (signed int)v33;
        v72 = _mm_add_ps(v72, *(__m128 *)&v68.vfptr);
        extraRadius.m_real = _mm_sub_ps(extraRadius.m_real, *(__m128 *)&v68.vfptr);
        v36 = *(__m128 *)(v34 + 16);
        *(__m128 *)v34 = _mm_min_ps(*(__m128 *)v34, extraRadius.m_real);
        *(__m128 *)(v34 + 16) = _mm_max_ps(v36, v72);
        if ( !((*((_DWORD *)v64 + v35) >> v33) & 1) )
        {
          v37 = 0;
          if ( v6->m_regionSeedPoints.m_size > 0 )
          {
            v38 = 0i64;
            while ( 1 )
            {
              position.m_quad = (__m128)v6->m_regionSeedPoints.m_data[v38];
              _mm_store_si128((__m128i *)&closestPointOut, (__m128i)position.m_quad);
              hkaiNavMeshUtils::getClosestPointOnFace(v8, &position, v5, &closestPointOut);
              v39 = _mm_sub_ps(position.m_quad, closestPointOut.m_quad);
              v40 = _mm_mul_ps(v39, v39);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) < v23 )
                break;
              ++v37;
              ++v38;
              if ( v37 >= v6->m_regionSeedPoints.m_size )
                goto LABEL_52;
            }
            *((_DWORD *)v64 + v69) |= 1 << SLOBYTE(resulta.m_enum);
          }
        }
LABEL_52:
        ++v5;
        v32 += 4i64;
      }
      while ( v5 < v8->m_faces.m_size );
      LODWORD(v16) = v79;
      v9 = v77;
      v31 = 0i64;
    }
    v60 = 0i64;
    v61 = 0;
    v62 = 2147483648;
    if ( (signed int)v16 > 0 )
    {
      v41 = v16;
      if ( (signed int)v16 < 0 )
        v41 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v60, v41, 4);
      if ( resulta.m_enum )
      {
        v9->m_enum = 1;
LABEL_91:
        v61 = v31;
        if ( v62 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v60,
            4 * v62);
        v65 = 0;
        v62 = 2147483648;
        v60 = 0i64;
        if ( v66 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v64,
            4 * v66);
        v55 = 0;
        v66 = 2147483648;
        v64 = 0i64;
        if ( v56 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v54,
            32 * v56);
        areasOut.m_size = 0;
        v56 = 2147483648;
        v54 = 0i64;
        if ( areasOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            areasOut.m_data,
            4 * areasOut.m_capacityAndFlags);
        v58 = 0;
        areasOut.m_data = 0i64;
        goto LABEL_100;
      }
    }
    v42 = v6->m_minRegionArea;
    v61 = v16;
    v43 = 0;
    v44 = 0;
    v45 = (_DWORD)v16 == 0;
    if ( (signed int)v16 > 0 )
    {
      do
      {
        v46 = v42 < *(float *)((char *)areasOut.m_data + v31)
           && (*((_DWORD *)v64 + ((signed __int64)v44 >> 5)) >> (v44 & 0x1F)) & 1;
        v47 = hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(&v54[v44], &aabbOut);
        if ( v46 || v47 )
        {
          *(_DWORD *)((char *)v60 + v31) = v43++;
        }
        else
        {
          LODWORD(v16) = v16 - 1;
          *(_DWORD *)((char *)v60 + v31) = -1;
        }
        ++v44;
        v31 += 4i64;
      }
      while ( v44 < v61 );
      v31 = 0i64;
      v45 = (_DWORD)v16 == 0;
    }
    if ( v45 )
    {
      hkErrStream::hkErrStream(&v68, &buf, 512);
      hkOstream::operator<<(
        (hkOstream *)&v68.vfptr,
        "All regions are either below the area threshold or too far from a seed point. Keeping the largest region.");
      hkError::messageWarning(808710226, &buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 2804);
      hkOstream::~hkOstream((hkOstream *)&v68.vfptr);
      *v60 = v43;
    }
    v48 = v8->m_faces.m_size;
    facesToRemove.m_data = 0i64;
    v49 = 0;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 2147483648;
    if ( v48 > 0 )
    {
      if ( v48 < 0 )
        v48 = 0;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &facesToRemove,
        v48,
        4);
      if ( resulta.m_enum )
      {
        v9->m_enum = 1;
LABEL_88:
        facesToRemove.m_size = v31;
        if ( facesToRemove.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            facesToRemove.m_data,
            4 * facesToRemove.m_capacityAndFlags);
        facesToRemove.m_data = 0i64;
        facesToRemove.m_capacityAndFlags = 2147483648;
        goto LABEL_91;
      }
      v49 = facesToRemove.m_size;
    }
    v50 = 0;
    if ( v8->m_faces.m_size > 0 )
    {
      do
      {
        if ( v60[*(signed int *)&array[v31]] == -1 )
        {
          if ( v49 == (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &facesToRemove, 4);
            v49 = facesToRemove.m_size;
          }
          facesToRemove.m_data[v49] = v50;
          v49 = facesToRemove.m_size++ + 1;
        }
        ++v50;
        v31 += 4i64;
      }
      while ( v50 < v8->m_faces.m_size );
      LODWORD(v31) = 0;
    }
    hkaiNavMeshUtils::removeFaces(&resulta, v8, &facesToRemove, 1);
    if ( resulta.m_enum )
      v9->m_enum = 1;
    else
      v9->m_enum = v31;
    goto LABEL_88;
  }
  v9->m_enum = 1;
LABEL_9:
  areasOut.m_size = 0;
  if ( areasOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      areasOut.m_data,
      4 * areasOut.m_capacityAndFlags);
  areasOut.m_data = 0i64;
  v58 = 0;
LABEL_100:
  areasOut.m_capacityAndFlags = 2147483648;
  if ( v59 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v59);
  return v9;
}

// File Line: 2844
// RVA: 0xB74FE0
void __fastcall hkaiNavMeshGenerationUtils::_saveSnapshot(hkaiNavMeshGenerationSettings *input, hkGeometry *geom)
{
  hkGeometry *v2; // rdi
  hkaiNavMeshGenerationSettings *v3; // rbx
  hkClass *v4; // rax
  hkOstream v5; // [rsp+30h] [rbp-438h]
  hkaiNavMeshGenerationSettings settings; // [rsp+50h] [rbp-418h]
  hkaiNavMeshGenerationSnapshot object; // [rsp+240h] [rbp-228h]
  hkBool result; // [rsp+470h] [rbp+8h]

  v2 = geom;
  v3 = input;
  hkOstream::hkOstream(&v5, (const char *)((_QWORD)input->m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  if ( hkOstream::isOk(&v5, &result)->m_bool )
  {
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&settings);
    hkaiNavMeshGenerationSettings::operator=(&settings, v3);
    settings.m_saveInputSnapshot.m_bool = 0;
    hkaiNavMeshGenerationSnapshot::hkaiNavMeshGenerationSnapshot(&object, v2, &settings);
    v4 = hkaiNavMeshGenerationSnapshot::staticClass();
    hkSerializeUtil::save((hkResult *)&result, &object, v4, v5.m_writer.m_pntr, 0);
    hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(&object);
    hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&settings);
  }
  hkOstream::~hkOstream(&v5);
}

// File Line: 2862
// RVA: 0xB74620
hkResult *__fastcall hkaiNavMeshGenerationUtils::_blockUntraversableEdges(hkResult *result, hkaiNavMesh *mesh, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometryRaycaster *raycaster)
{
  int v4; // ebx
  hkaiEdgeGeometryRaycaster *v5; // rsi
  hkaiNavMeshGenerationSettings *v6; // r14
  hkaiNavMesh *v7; // r13
  hkResult *v8; // r15
  int v9; // edi
  float v10; // xmm6_4
  __int32 v11; // eax
  _DWORD *v12; // rcx
  unsigned int v13; // er8
  int v14; // er8
  int v15; // er9
  int v16; // er8
  int v18; // eax
  _DWORD *v19; // rdi
  __int64 i; // rcx
  int v21; // ebx
  int v22; // edi
  unsigned __int32 v23; // eax
  void *v24; // r9
  signed __int64 v25; // r8
  int v26; // er9
  __int64 v27; // r8
  void *v28; // rdx
  __int64 v29; // rcx
  _DWORD *v30; // rdi
  int v31; // ebx
  int v32; // edi
  __int32 v33; // ecx
  __int64 v34; // rax
  void *v35; // r10
  signed int v36; // eax
  int v37; // ecx
  int v38; // er9
  __int64 v39; // rcx
  _DWORD *v40; // rdi
  int v41; // esi
  __int64 v42; // r11
  hkaiNavMesh::Face *v43; // rbx
  signed __int64 v44; // r10
  signed __int64 v45; // r8
  hkaiNavMesh::Edge *v46; // rdi
  int v47; // ecx
  signed __int64 v48; // rdi
  char v49; // r15
  int v50; // er12
  __int64 v51; // rbx
  hkaiNavMesh::Face *v52; // r14
  signed __int64 v53; // r11
  signed __int64 v54; // r8
  hkaiNavMesh::Edge *v55; // rdi
  __int64 v56; // rax
  __int64 v57; // r10
  __int64 v58; // rcx
  __int64 v59; // r10
  signed __int64 v60; // rdx
  bool v61; // zf
  bool v62; // sf
  signed __int64 v63; // rdx
  char *v64; // r10
  __int64 v65; // rax
  __int64 v66; // r11
  int v67; // er12
  signed __int64 v68; // r14
  int v69; // esi
  signed __int64 v70; // r15
  hkaiNavMesh::Edge *v71; // rax
  __int64 v72; // r8
  hkVector4f *v73; // rcx
  hkaiNavMeshGenerationSettings *v74; // r13
  signed __int64 v75; // rbx
  __int64 v76; // rax
  hkVector4f *v77; // rdi
  int v78; // er9
  __int64 v79; // rdi
  hkaiNavMesh::Edge *v80; // r8
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  __int64 v83; // rax
  _DWORD *v84; // rdi
  signed int v85; // er8
  signed int v86; // er8
  hkResult v87; // [rsp+40h] [rbp-88h]
  void *v88; // [rsp+48h] [rbp-80h]
  int v89; // [rsp+50h] [rbp-78h]
  unsigned int v90; // [rsp+54h] [rbp-74h]
  int v91; // [rsp+58h] [rbp-70h]
  _DWORD *array; // [rsp+60h] [rbp-68h]
  hkaiNavMesh::Face *v93; // [rsp+68h] [rbp-60h]
  int v94; // [rsp+70h] [rbp-58h]
  hkResult resulta[4]; // [rsp+78h] [rbp-50h]
  hkVector4f v96; // [rsp+88h] [rbp-40h]
  hkaiNavMesh mesha; // [rsp+98h] [rbp-30h]
  _DWORD *v98; // [rsp+198h] [rbp+D0h]
  hkaiNavMesh *v99; // [rsp+1A0h] [rbp+D8h]
  hkaiNavMeshGenerationSettings *v100; // [rsp+1A8h] [rbp+E0h]

  v4 = mesh->m_edges.m_size;
  v5 = raycaster;
  v6 = input;
  v7 = mesh;
  v8 = result;
  *(float *)&v87.m_enum = input->m_minCharacterWidth * input->m_minCharacterWidth;
  v9 = (v4 + 31) >> 5;
  array = 0i64;
  v93 = (hkaiNavMesh::Face *)0x8000000000000000i64;
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)(unsigned int)v87.m_enum,
                                      (__m128)(unsigned int)v87.m_enum,
                                      0);
  v11 = v9;
  if ( v9 )
  {
    v87.m_enum = 4 * v9;
    v12 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      (int *)&v87);
    v11 = v87.m_enum / 4;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 2147483648;
  array = v12;
  if ( v11 )
    v13 = v11;
  LODWORD(v93) = (v4 + 31) >> 5;
  v94 = v4;
  HIDWORD(v93) = v13;
  v14 = v13 & 0x3FFFFFFF;
  if ( v14 < v9 )
  {
    v15 = (v4 + 31) >> 5;
    if ( v9 < 2 * v14 )
      v15 = 2 * v14;
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
  }
  LODWORD(v93) = (v4 + 31) >> 5;
  if ( !array )
  {
    v16 = HIDWORD(v93);
    v8->m_enum = 1;
    LODWORD(v93) = 0;
    if ( v16 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v16);
    return v8;
  }
  v18 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    v19 = array;
    for ( i = (unsigned int)(v18 + 1); i; --i )
    {
      *v19 = 0;
      ++v19;
    }
  }
  if ( !v6->m_enableSimplification.m_bool )
  {
LABEL_26:
    v21 = v7->m_vertices.m_size;
    v90 = 2147483648;
    v88 = 0i64;
    v89 = 0;
    v22 = (v21 + 31) >> 5;
    v23 = v22;
    if ( v22 )
    {
      v87.m_enum = 4 * v22;
      v24 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (int *)&v87);
      v23 = v87.m_enum / 4;
    }
    else
    {
      v24 = 0i64;
    }
    v25 = 0x80000000i64;
    v88 = v24;
    if ( v23 )
      v25 = v23;
    v89 = (v21 + 31) >> 5;
    v91 = v21;
    v90 = v25;
    if ( (v25 & 0x3FFFFFFF) < v22 )
    {
      v26 = (v21 + 31) >> 5;
      if ( v22 < (signed int)(2 * (v25 & 0x3FFFFFFF)) )
        v26 = 2 * (v25 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v88, v26, 4);
      v25 = v90;
      v24 = v88;
    }
    v89 = (v21 + 31) >> 5;
    if ( v24 )
    {
      if ( v22 - 1 >= 0 )
      {
        v29 = (unsigned int)v22;
        v30 = v24;
        while ( v29 )
        {
          *v30 = 0;
          ++v30;
          --v29;
        }
        v25 = v90;
        v24 = v88;
      }
      v31 = v7->m_edges.m_size;
      v88 = 0i64;
      v89 = 0;
      v90 = 2147483648;
      v32 = (v31 + 31) >> 5;
      v33 = v32;
      if ( v32 )
      {
        v87.m_enum = 4 * v32;
        v34 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, signed __int64, void *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                &hkContainerHeapAllocator::s_alloc,
                &v87,
                v25,
                v24);
        LODWORD(v25) = v90;
        v24 = v88;
        v35 = (void *)v34;
        v33 = v87.m_enum / 4;
      }
      else
      {
        v35 = 0i64;
      }
      v36 = 2147483648;
      v88 = v35;
      if ( v33 )
        v36 = v33;
      v89 = (v31 + 31) >> 5;
      v91 = v31;
      v90 = v36;
      v37 = v36 & 0x3FFFFFFF;
      if ( (v36 & 0x3FFFFFFF) < v32 )
      {
        v38 = (v31 + 31) >> 5;
        if ( v32 < 2 * v37 )
          v38 = 2 * v37;
        hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v88, v38, 4);
        LODWORD(v25) = v90;
        v24 = v88;
        v36 = v90;
        v35 = v88;
      }
      v89 = (v31 + 31) >> 5;
      if ( v35 )
      {
        if ( v32 - 1 >= 0 )
        {
          v39 = (unsigned int)v32;
          v40 = v35;
          while ( v39 )
          {
            *v40 = 0;
            ++v40;
            --v39;
          }
          v24 = v88;
        }
        v41 = 0;
        if ( v7->m_faces.m_size > 0 )
        {
          v42 = 0i64;
          do
          {
            v43 = v7->m_faces.m_data;
            v44 = v43[v42].m_startEdgeIndex;
            if ( (signed int)v44 < (signed int)v44 + v43[v42].m_numEdges )
            {
              v45 = v44;
              do
              {
                v46 = v7->m_edges.m_data;
                if ( (v46[v45].m_oppositeEdge == -1 || v46[v45].m_flags.m_storage & 0x20)
                  && !((array[(signed __int64)(signed int)v44 >> 5] >> (v44 & 0x1F)) & 1) )
                {
                  *((_DWORD *)v24 + ((signed __int64)v46[v45].m_a >> 5)) |= 1 << (v46[v45].m_a & 0x1F);
                  v47 = v46[v45].m_b;
                  v48 = (signed __int64)v46[v45].m_b >> 5;
                  *((_DWORD *)v88 + v48) |= 1 << (v47 & 0x1F);
                  v24 = v88;
                }
                LODWORD(v44) = v44 + 1;
                ++v45;
              }
              while ( (signed int)v44 < v43[v42].m_startEdgeIndex + v43[v42].m_numEdges );
            }
            ++v41;
            ++v42;
          }
          while ( v41 < v7->m_faces.m_size );
        }
        do
        {
          v49 = 0;
          v50 = 0;
          if ( v7->m_faces.m_size <= 0 )
            break;
          v51 = 0i64;
          do
          {
            v52 = v7->m_faces.m_data;
            v53 = v52[v51].m_startEdgeIndex;
            if ( (signed int)v53 < (signed int)v53 + v52[v51].m_numEdges )
            {
              v54 = v53;
              do
              {
                v55 = v7->m_edges.m_data;
                v56 = (signed int)v55[v54].m_oppositeEdge;
                if ( (_DWORD)v56 != -1 && !(v55[v54].m_flags.m_storage & 0x20) )
                {
                  v57 = v55[v54].m_a;
                  if ( !((*((_DWORD *)v24 + (v57 >> 5)) >> (v55[v54].m_a & 0x1F)) & 1) )
                  {
                    v58 = v55[v56].m_b;
                    if ( (*((_DWORD *)v24 + (v58 >> 5)) >> (v58 & 0x1F)) & 1 )
                    {
                      v49 = 1;
                      *((_DWORD *)v24 + ((signed __int64)v55[v54].m_a >> 5)) |= 1 << (v57 & 0x1F);
                      v24 = v88;
                    }
                  }
                  v59 = v55[v54].m_b;
                  if ( !((*((_DWORD *)v24 + (v59 >> 5)) >> (v55[v54].m_b & 0x1F)) & 1)
                    && (*((_DWORD *)v24 + ((signed __int64)v55[v56].m_a >> 5)) >> (v55[v56].m_a & 0x1F)) & 1 )
                  {
                    v60 = (signed __int64)v55[v54].m_b >> 5;
                    v49 = 1;
                    *((_DWORD *)v24 + v60) |= 1 << (v59 & 0x1F);
                    v24 = v88;
                  }
                }
                LODWORD(v53) = v53 + 1;
                ++v54;
              }
              while ( (signed int)v53 < v52[v51].m_startEdgeIndex + v52[v51].m_numEdges );
            }
            ++v50;
            ++v51;
          }
          while ( v50 < v7->m_faces.m_size );
        }
        while ( v49 );
        v61 = v7->m_faces.m_size == 0;
        v62 = v7->m_faces.m_size < 0;
        v63 = 0i64;
        *(float *)&v87.m_enum = 0.0;
        *(_QWORD *)&resulta[0].m_enum = 0i64;
        if ( !v62 && !v61 )
        {
          v64 = 0i64;
          array = 0i64;
          do
          {
            v65 = v7->m_faceDataStriding;
            v66 = (__int64)v7->m_faces.m_data;
            v93 = v7->m_faces.m_data;
            if ( (_DWORD)v65 )
              v67 = v7->m_faceData.m_data[v63 * v65];
            else
              v67 = 0;
            v68 = *(signed int *)&v64[v66];
            v69 = __ROL4__(1, v68);
            if ( (signed int)v68 < (signed int)v68 + *(signed __int16 *)&v64[v66 + 8] )
            {
              v70 = v68;
              do
              {
                v71 = v7->m_edges.m_data;
                if ( v71[v70].m_oppositeEdge != -1 )
                {
                  v72 = v71[v70].m_a;
                  if ( (*((_DWORD *)v24 + (v72 >> 5)) >> (v71[v70].m_a & 0x1F)) & 1 )
                  {
                    if ( (*((_DWORD *)v24 + ((signed __int64)v71[v70].m_b >> 5)) >> (v71[v70].m_b & 0x1F)) & 1 )
                    {
                      v73 = v7->m_vertices.m_data;
                      v74 = v100;
                      v75 = 2i64;
                      v76 = v71[v70].m_b;
                      v77 = (hkVector4f *)resulta;
                      *(hkVector4f *)&resulta[0].m_enum = v73[v72];
                      v96.m_quad = (__m128)v73[v76];
                      do
                      {
                        hkaiNavMeshGenerationSettings::getCharacterWidthUsage(v74, v77, v67);
                        ++v77;
                        --v75;
                      }
                      while ( v75 );
                      v7 = v99;
                      v64 = (char *)array;
                      v66 = (__int64)v93;
                      *((_DWORD *)v88 + ((signed __int64)(signed int)v68 >> 5)) |= v69;
                      v24 = v88;
                    }
                  }
                }
                v69 = __ROL4__(v69, 1);
                LODWORD(v68) = v68 + 1;
                ++v70;
              }
              while ( (signed int)v68 < *(_DWORD *)&v64[v66] + (signed int)*(signed __int16 *)&v64[v66 + 8] );
            }
            v64 += 16;
            v63 = *(_QWORD *)&resulta[0].m_enum + 1i64;
            array = v64;
            ++v87.m_enum;
            ++*(_QWORD *)&resulta[0].m_enum;
          }
          while ( v87.m_enum < v7->m_faces.m_size );
        }
        v78 = 0;
        if ( v7->m_edges.m_size > 0 )
        {
          v79 = 0i64;
          do
          {
            v80 = v7->m_edges.m_data;
            v81 = _mm_sub_ps(v7->m_vertices.m_data[v80[v79].m_a].m_quad, v7->m_vertices.m_data[v80[v79].m_b].m_quad);
            v82 = _mm_mul_ps(v81, v81);
            if ( (*((_DWORD *)v88 + ((signed __int64)v78 >> 5)) >> (v78 & 0x1F)) & 1
              && (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 170))) < v10 )
            {
              v83 = (signed int)v80[v79].m_oppositeEdge;
              if ( (_DWORD)v83 != -1 )
                *(_QWORD *)&v80[v83].m_oppositeEdge = -1i64;
              *(_QWORD *)&v80[v79].m_oppositeEdge = -1i64;
            }
            ++v78;
            ++v79;
          }
          while ( v78 < v7->m_edges.m_size );
        }
        hkaiNavMeshUtils::validate(v7, 0);
        v84 = v98;
        v85 = v90;
        *v98 = 0;
        v89 = 0;
        if ( v85 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v88,
            4 * v85);
        v86 = v90;
        v88 = 0i64;
        v90 = 2147483648;
        v89 = 0;
        if ( v86 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v88,
            4 * v86);
        v88 = 0i64;
        v90 = 2147483648;
        LODWORD(v93) = 0;
        if ( SHIDWORD(v93) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * HIDWORD(v93));
        return (hkResult *)v84;
      }
      v8->m_enum = 1;
      v89 = 0;
      if ( v36 >= 0 )
      {
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, void *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          0i64,
          (unsigned int)(4 * v36),
          v24);
        LODWORD(v25) = v90;
        v24 = v88;
      }
      v88 = 0i64;
      v90 = 2147483648;
      v89 = 0;
      if ( (signed int)v25 < 0 )
        goto LABEL_39;
      v28 = v24;
      v27 = (unsigned int)(4 * v25);
    }
    else
    {
      v8->m_enum = 1;
      v89 = 0;
      if ( (signed int)v25 < 0 )
      {
LABEL_39:
        v88 = 0i64;
        v90 = 2147483648;
        LODWORD(v93) = 0;
        goto LABEL_21;
      }
      v27 = (unsigned int)(4 * v25);
      v28 = 0i64;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v28, v27);
    goto LABEL_39;
  }
  hkaiNavMesh::hkaiNavMesh(&mesha);
  hkaiNavMesh::copy(&mesha, &v87, v7);
  if ( *(float *)&v87.m_enum == 0.0 )
  {
    hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices((hkResult *)&array, v6, &mesha);
    if ( !(_DWORD)array )
    {
      hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(
        resulta,
        v6,
        &mesha,
        v5,
        0i64,
        0i64,
        (hkBitField *)&array);
      if ( resulta[0].m_enum == HK_SUCCESS )
      {
        hkaiNavMesh::~hkaiNavMesh(&mesha);
        goto LABEL_26;
      }
    }
  }
  v8->m_enum = 1;
  hkaiNavMesh::~hkaiNavMesh(&mesha);
  LODWORD(v93) = 0;
LABEL_21:
  if ( SHIDWORD(v93) < 0 )
    return v8;
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
    array,
    4 * HIDWORD(v93));
  return v8;
}
        v6,
        &mesha,
        v5,
        0i64,
        0i64,
        (hkBitField *)&array);
     

