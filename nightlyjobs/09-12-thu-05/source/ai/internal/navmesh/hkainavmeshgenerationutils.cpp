// File Line: 74
// RVA: 0xB72990
void __fastcall hkaiNavMeshGenerationUtils::ValidationSettings::ValidationSettings(
        hkaiNavMeshGenerationUtils::ValidationSettings *this)
{
  this->m_maxHorizontalRange = 10000.0;
  this->m_maxVerticalRange = 1000.0;
}

// File Line: 93
// RVA: 0xB78920
void __fastcall hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(
        hkaiNavMeshGenerationProgressCallbackContext *this,
        hkaiNavMeshGenerationSettings *settings)
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
  __m128 v4; // xmm4
  __m128 v5; // xmm2
  __m128 v6; // xmm4

  v3 = _mm_cmplt_ps(xInOut->m_quad, (__m128)0i64);
  v4 = _mm_or_ps(
         _mm_and_ps(_mm_sub_ps(xInOut->m_quad, _mm_mul_ps(gridSize->m_real, (__m128)xmmword_141A711B0)), v3),
         _mm_andnot_ps(v3, xInOut->m_quad));
  *xInOut = (hkVector4f)v4;
  v5 = _mm_cvtepi32_ps(
         _mm_xor_si128(
           (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v4),
           _mm_cvttps_epi32(v4)));
  v6 = _mm_mul_ps(_mm_sub_ps(v4, v5), invGridSize->m_real);
  xInOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_xor_si128(
                           (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v6),
                           _mm_cvttps_epi32(v6))),
                       gridSize->m_real),
                     v5);
}

// File Line: 136
// RVA: 0xB75850
void __fastcall hkaiNavMeshGenerationUtils::quantize(hkGeometry *geomInOut, float gridSize)
{
  int v2; // edx
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __int64 v6; // rcx
  hkVector4f *m_data; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm4

  v2 = 0;
  v4 = _mm_shuffle_ps((__m128)LODWORD(gridSize), (__m128)LODWORD(gridSize), 0);
  v5 = _mm_div_ps(query.m_quad, v4);
  if ( geomInOut->m_vertices.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      m_data = geomInOut->m_vertices.m_data;
      ++v2;
      v8 = _mm_cmplt_ps(m_data[v6++].m_quad, (__m128)0i64);
      v9 = _mm_or_ps(
             _mm_and_ps(_mm_sub_ps(m_data[v6 - 1].m_quad, _mm_mul_ps((__m128)xmmword_141A711B0, v4)), v8),
             _mm_andnot_ps(v8, m_data[v6 - 1].m_quad));
      m_data[v6 - 1] = (hkVector4f)v9;
      v10 = _mm_cvtepi32_ps(
              _mm_xor_si128(
                (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
                _mm_cvttps_epi32(v9)));
      v11 = _mm_mul_ps(_mm_sub_ps(v9, v10), v5);
      m_data[v6 - 1].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_xor_si128(
                                      (__m128i)_mm_cmple_ps(
                                                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                 v11),
                                      _mm_cvttps_epi32(v11))),
                                  v4),
                                v10);
    }
    while ( v2 < geomInOut->m_vertices.m_size );
  }
}

// File Line: 147
// RVA: 0xB789E0
void __fastcall flipGeometryWindingAll(hkGeometry *geomInOut)
{
  int v1; // r8d
  __int64 v3; // r9
  hkGeometry::Triangle *v4; // rdx
  int m_b; // ecx

  v1 = 0;
  if ( geomInOut->m_triangles.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v1;
      v4 = &geomInOut->m_triangles.m_data[v3++];
      m_b = v4->m_b;
      v4->m_b = v4->m_c;
      v4->m_c = m_b;
    }
    while ( v1 < geomInOut->m_triangles.m_size );
  }
}

// File Line: 156
// RVA: 0xB78680
hkResult *__fastcall hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(
        hkResult *result,
        hkGeometry *dstGeom,
        hkGeometry *srcGeom,
        hkAabb *pruneAabb,
        hkaiNavMeshGenerationSettings::TriangleWinding inputWinding)
{
  int m_size; // r9d
  __int64 v10; // rax
  hkGeometry::Triangle *m_data; // rcx
  __int64 v12; // rdx
  char *v13; // r8
  int v14; // eax
  int v15; // r9d
  __int64 v16; // rax
  hkVector4f *v17; // rcx
  __int64 v18; // rdx
  char *v19; // r8
  hkVector4f v20; // xmm0
  hkResult v22; // [rsp+30h] [rbp-18h] BYREF
  hkResult v23; // [rsp+34h] [rbp-14h] BYREF
  hkResult resulta; // [rsp+68h] [rbp+20h] BYREF

  if ( (_mm_movemask_ps(_mm_cmple_ps(pruneAabb->m_max.m_quad, pruneAabb->m_min.m_quad)) & 7) == 0 )
  {
    hkGeometryUtils::getGeometryInsideAabb(&resulta, srcGeom, dstGeom, pruneAabb, MODE_PRESIZE_ARRAYS);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      hkGeometryUtils::getGeometryInsideAabb(&v23, srcGeom, dstGeom, pruneAabb, MODE_COPY_DATA);
      if ( v23.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
      goto LABEL_30;
    }
    goto LABEL_26;
  }
  m_size = srcGeom->m_triangles.m_size;
  if ( (dstGeom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &dstGeom->m_triangles, m_size, 16);
    if ( resulta.m_enum )
      goto LABEL_26;
  }
  if ( (dstGeom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < srcGeom->m_triangles.m_size )
  {
    if ( dstGeom->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        dstGeom->m_triangles.m_data,
        16 * dstGeom->m_triangles.m_capacityAndFlags);
    v23.m_enum = 16 * srcGeom->m_triangles.m_size;
    dstGeom->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            &hkContainerHeapAllocator::s_alloc,
                                                            &v23);
    dstGeom->m_triangles.m_capacityAndFlags = v23.m_enum / 16;
  }
  v10 = srcGeom->m_triangles.m_size;
  m_data = dstGeom->m_triangles.m_data;
  dstGeom->m_triangles.m_size = v10;
  v12 = v10;
  if ( (int)v10 > 0 )
  {
    v13 = (char *)((char *)srcGeom->m_triangles.m_data - (char *)m_data);
    do
    {
      v14 = *(int *)((char *)&m_data->m_a + (_QWORD)v13);
      ++m_data;
      m_data[-1].m_a = v14;
      m_data[-1].m_b = *(_DWORD *)((char *)m_data + (_QWORD)v13 - 12);
      m_data[-1].m_c = *(_DWORD *)((char *)m_data + (_QWORD)v13 - 8);
      m_data[-1].m_material = *(_DWORD *)((char *)m_data + (_QWORD)v13 - 4);
      --v12;
    }
    while ( v12 );
  }
  if ( resulta.m_enum )
    goto LABEL_26;
  v15 = srcGeom->m_vertices.m_size;
  if ( (dstGeom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v15 )
  {
    v22.m_enum = HK_SUCCESS;
    goto LABEL_18;
  }
  hkArrayUtil::_reserve(&v22, &hkContainerHeapAllocator::s_alloc, &dstGeom->m_vertices, v15, 16);
  if ( v22.m_enum )
  {
LABEL_26:
    result->m_enum = HK_FAILURE;
    return result;
  }
LABEL_18:
  if ( (dstGeom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < srcGeom->m_vertices.m_size )
  {
    if ( dstGeom->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        dstGeom->m_vertices.m_data,
        16 * dstGeom->m_vertices.m_capacityAndFlags);
    v23.m_enum = 16 * srcGeom->m_vertices.m_size;
    dstGeom->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &v23);
    dstGeom->m_vertices.m_capacityAndFlags = v23.m_enum / 16;
  }
  v16 = srcGeom->m_vertices.m_size;
  v17 = dstGeom->m_vertices.m_data;
  dstGeom->m_vertices.m_size = v16;
  v18 = v16;
  if ( (int)v16 > 0 )
  {
    v19 = (char *)((char *)srcGeom->m_vertices.m_data - (char *)v17);
    do
    {
      v20.m_quad = *(__m128 *)((char *)v17++ + (_QWORD)v19);
      v17[-1] = (hkVector4f)v20.m_quad;
      --v18;
    }
    while ( v18 );
  }
  if ( v22.m_enum )
    goto LABEL_26;
LABEL_30:
  if ( inputWinding == WINDING_CW )
    flipGeometryWindingAll(dstGeom);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 258
// RVA: 0xB729B0
void __fastcall hkaiNavMeshGenerationUtils::validateInputGeometry(
        hkaiNavMeshGenerationSettings *input,
        hkaiNavMeshGenerationUtils::ValidationSettings *validationSettings,
        hkGeometry *geom)
{
  hkaiNavMeshGenerationUtils::_validateRangeOfInput(
    &geom->m_vertices,
    validationSettings->m_maxHorizontalRange,
    validationSettings->m_maxVerticalRange,
    &input->m_up);
  hkaiNavMeshGenerationUtils::_validateInputGeometryOverlaps(geom);
}

// File Line: 265
// RVA: 0xB750C0
void __fastcall hkaiNavMeshGenerationUtils::_validateRangeOfInput(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        float maxHorizontalRange,
        float maxVerticalRange,
        const __m128i *up)
{
  unsigned int v4; // ebx
  int v5; // esi
  __m128 v8; // xmm8
  __m128 v9; // xmm7
  __int64 v10; // rbx
  __m128i si128; // xmm4
  __m128 v12; // xmm7
  __m128 v13; // xmm3
  float v14; // xmm8_4
  __m128 v15; // xmm9
  __m128 v16; // xmm9
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm9
  __m128 v22; // xmm1
  __m128 v23; // xmm7
  hkErrStream v24; // [rsp+20h] [rbp-D8h] BYREF
  char buf[512]; // [rsp+40h] [rbp-B8h] BYREF
  unsigned int v26; // [rsp+2A0h] [rbp+1A8h]

  v5 = 0;
  v8 = (__m128)xmmword_141A712A0;
  v9 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( vertices->m_size > 0 )
  {
    v26 = v4;
    v10 = 0i64;
    do
    {
      if ( (_mm_movemask_ps(_mm_cmpunord_ps(vertices->m_data[v10].m_quad, vertices->m_data[v10].m_quad)) & 7) != 0 )
      {
        hkErrStream::hkErrStream(&v24, buf, 512);
        hkOstream::operator<<(&v24, "Input vertex data of geometry contains corrupt floating point data.");
        hkError::messageWarning(1666537773, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 272);
        hkOstream::~hkOstream(&v24);
      }
      ++v5;
      v8 = _mm_min_ps(v8, vertices->m_data[v10++].m_quad);
      v9 = _mm_max_ps(v9, vertices->m_data[v10 - 1].m_quad);
    }
    while ( v5 < vertices->m_size );
  }
  si128 = _mm_load_si128(up);
  v24.hkReferencedObject = 0i64;
  v12 = _mm_mul_ps(_mm_sub_ps(v9, v8), (__m128)xmmword_141A711B0);
  v13 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
  v14 = _mm_shuffle_ps((__m128)v26, (__m128)v26, 0).m128_f32[0];
  *((_DWORD *)&v24.vfptr
  + ((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                            _mm_and_ps(
                                                              _mm_cmple_ps(
                                                                _mm_max_ps(
                                                                  _mm_shuffle_ps(v13, v13, 170),
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(v13, v13, 85),
                                                                    _mm_shuffle_ps(v13, v13, 0))),
                                                                v13),
                                                              (__m128)xmmword_141A4D050))]
   + 1)
  % 3) = 1065353216;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v24.hkReferencedObject, (__m128)v24.hkReferencedObject, 201), (__m128)si128),
          _mm_mul_ps(_mm_shuffle_ps((__m128)si128, (__m128)si128, 201), (__m128)v24.hkReferencedObject));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(v12, (__m128)v24.hkReferencedObject);
  v21 = _mm_mul_ps(
          v16,
          _mm_andnot_ps(
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))));
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])) >> 1) >= v14 )
  {
    hkErrStream::hkErrStream(&v24, buf, 512);
    hkOstream::operator<<(&v24, "Input vertex data of geometry outside range given by m_maxHorizontalRange.");
    hkError::messageWarning(1658471356, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 290);
    hkOstream::~hkOstream(&v24);
  }
  v22 = _mm_mul_ps(v12, v21);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v22, v22, 170).m128_f32[0])) >> 1) >= v14 )
  {
    hkErrStream::hkErrStream(&v24, buf, 512);
    hkOstream::operator<<(&v24, "Input vertex data of geometry outside range given by m_maxHorizontalRange.");
    hkError::messageWarning(1658471356, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 292);
    hkOstream::~hkOstream(&v24);
  }
  v23 = _mm_mul_ps(v12, *(__m128 *)up);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v23, v23, 170).m128_f32[0])) >> 1) >= _mm_shuffle_ps(
                                                                                            (__m128)LODWORD(maxHorizontalRange),
                                                                                            (__m128)LODWORD(maxHorizontalRange),
                                                                                            0).m128_f32[0] )
  {
    hkErrStream::hkErrStream(&v24, buf, 512);
    hkOstream::operator<<(&v24, "Input vertex data of geometry outside range given by m_maxVerticalRange.");
    hkError::messageWarning(1658471356, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 294);
    hkOstream::~hkOstream(&v24);
  }
}

// File Line: 299
// RVA: 0xB75490
void __fastcall hkaiNavMeshGenerationUtils::_validateInputGeometryOverlaps(hkGeometry *geom)
{
  __int64 m_size; // r14
  __int64 v3; // rsi
  int v4; // r9d
  int v5; // ebx
  __int64 v6; // r12
  hkGeometry::Triangle *m_data; // rcx
  hkVector4f *v8; // rdx
  __m128 m_quad; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkVector4f v14; // xmm0
  hk1AxisSweep::AabbInt *v15; // r15
  hkVector4f v16; // xmm1
  hk1AxisSweep::AabbInt *v17; // r9
  int v18; // r12d
  __int64 v19; // r15
  __int64 v20; // r13
  hkResultEnum v21; // eax
  unsigned int v22; // r10d
  hk1AxisSweep::AabbInt *v23; // rcx
  __int64 v24; // r8
  hk1AxisSweep::AabbInt *v25; // rax
  int v26; // ebx
  hkOstream *v27; // rax
  hkOstream *v28; // rax
  hkOstream *v29; // rax
  hkOstream *v30; // rax
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-B8h] BYREF
  int v32; // [rsp+38h] [rbp-B0h]
  int v33; // [rsp+3Ch] [rbp-ACh]
  hkErrStream v34; // [rsp+40h] [rbp-A8h] BYREF
  hkAabb buf[17]; // [rsp+60h] [rbp-88h] BYREF
  hkResult result; // [rsp+2D8h] [rbp+1F0h] BYREF
  int vars0; // [rsp+2E0h] [rbp+1F8h]

  m_size = geom->m_triangles.m_size;
  if ( (int)m_size >= 100000 )
  {
    v3 = 0i64;
    array = 0i64;
    v32 = 0;
    v33 = 0x80000000;
    if ( (int)m_size + 4 > 0 )
    {
      v4 = m_size + 4;
      if ( (int)m_size + 4 < 0 )
        v4 = 0;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v4, 32);
    }
    v32 = m_size + 4;
    v5 = 0;
    v6 = m_size;
    do
    {
      m_data = geom->m_triangles.m_data;
      v8 = geom->m_vertices.m_data;
      m_quad = v8[m_data[v3].m_a].m_quad;
      v10 = v8[m_data[v3].m_b].m_quad;
      v11 = v8[m_data[v3].m_c].m_quad;
      if ( (_mm_movemask_ps(_mm_cmpunord_ps(m_quad, m_quad)) & 7) != 0
        || (_mm_movemask_ps(_mm_cmpunord_ps(v10, v10)) & 7) != 0
        || (_mm_movemask_ps(_mm_cmpunord_ps(v11, v11)) & 7) != 0 )
      {
        hkErrStream::hkErrStream(&v34, &buf[0].m_min.m_quad.m128_u16[4], 512);
        v12 = hkOstream::operator<<(&v34, "Triangle ");
        v13 = hkOstream::operator<<(v12, v5);
        hkOstream::operator<<(v13, " has invalid vertices.");
        hkError::messageWarning(
          1689537253,
          &buf[0].m_min.m_quad.m128_i8[8],
          "NavMesh\\hkaiNavMeshGenerationUtils.cpp",
          319);
        hkOstream::~hkOstream(&v34);
      }
      buf[0].m_max.m_quad = _mm_max_ps(_mm_max_ps(m_quad, v10), v11);
      buf[0].m_min.m_quad = _mm_min_ps(_mm_min_ps(m_quad, v10), v11);
      hk1AxisSweep::AabbInt::set(&array[v5], buf, v5);
      ++v5;
      ++v3;
      --v6;
    }
    while ( v6 );
    v14.m_quad = (__m128)buf[0].m_max;
    buf[0].m_min.m_quad.m128_i32[0] = -1;
    v15 = &array[m_size];
    v16.m_quad = (__m128)buf[0].m_min;
    *(hkVector4f *)v15->m_min = buf[0].m_min;
    *(hkVector4f *)v15->m_max = (hkVector4f)v14.m_quad;
    *(hkVector4f *)v15[1].m_min = (hkVector4f)v16.m_quad;
    *(hkVector4f *)v15[1].m_max = (hkVector4f)v14.m_quad;
    *(hkVector4f *)v15[2].m_min = (hkVector4f)v16.m_quad;
    *(hkVector4f *)v15[2].m_max = (hkVector4f)v14.m_quad;
    *(hkVector4f *)v15[3].m_min = (hkVector4f)v16.m_quad;
    *(hkVector4f *)v15[3].m_max = (hkVector4f)v14.m_quad;
    hk1AxisSweep::sortAabbs(array, m_size);
    v17 = array;
    vars0 = m_size - 1;
    v18 = 0;
    v19 = 0i64;
    v20 = 1i64;
    do
    {
      v21 = *(_DWORD *)v17[v19].m_expansionMin;
      v22 = v17[v19].m_max[0];
      v23 = &v17[v19++];
      result.m_enum = v21;
      v24 = v20;
      v25 = &v17[v19];
      v26 = 0;
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
          hkErrStream::hkErrStream(&v34, &buf[0].m_min.m_quad.m128_u16[4], 512);
          v27 = hkOstream::operator<<(&v34, "Lots of overlaps (");
          v28 = hkOstream::operator<<(v27, v26);
          v29 = hkOstream::operator<<(v28, ") for triangle ");
          v30 = hkOstream::operator<<(v29, result.m_enum);
          hkOstream::operator<<(v30, ". If you see this warning a lot, it may indicate corrupt input geometry");
          hkError::messageWarning(
            1392258972,
            &buf[0].m_min.m_quad.m128_i8[8],
            "NavMesh\\hkaiNavMeshGenerationUtils.cpp",
            354);
          hkOstream::~hkOstream(&v34);
          v17 = array;
        }
      }
      ++v18;
      ++v20;
    }
    while ( v18 < vars0 );
    v32 = 0;
    if ( v33 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v17, 32 * v33);
  }
}

// File Line: 367
// RVA: 0xB6E1C0
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMesh(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMesh *navMeshOut,
        hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  hkaiNavMeshGenerationOutputs outputs; // [rsp+30h] [rbp-38h] BYREF

  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = navMeshOut;
  return hkaiNavMeshGenerationUtils::_generateNavMesh(input, triMeshIn, &outputs, _callbacks, 0i64);
}

// File Line: 374
// RVA: 0xB6E230
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMesh(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMeshGenerationOutputs *outputs,
        hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  return hkaiNavMeshGenerationUtils::_generateNavMesh(input, triMeshIn, outputs, _callbacks, 0i64);
}

// File Line: 394
// RVA: 0xB6E250
__int64 __fastcall hkaiNavMeshGenerationUtils::_generateNavMesh(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *_triMeshIn,
        hkaiNavMeshGenerationOutputs *outputs,
        hkaiNavMeshGenerationProgressCallback *_callbacks,
        hkaiEdgeGeometryRaycaster *edgeConnectionRayCaster)
{
  hkaiNavMeshGenerationOutputs *v7; // r13
  _QWORD *Value; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  hkVector4f *m_navMesh; // rax
  unsigned int v15; // r14d
  hkVector4f *v16; // rax
  _QWORD **v17; // rax
  hkaiNavMesh *v18; // rax
  hkReferencedObject *v19; // rax
  hkaiNavMesh *v20; // r14
  _QWORD **v21; // rax
  hkaiNavMesh *v22; // rax
  hkaiNavMesh *v23; // rax
  bool v24; // zf
  int m_edgeDataStriding; // ecx
  hkaiNavMesh *v26; // rbx
  hkaiNavMeshGenerationProgressCallback *cb; // r12
  __int64 m_size; // rdi
  int SizeInBytesFor; // eax
  unsigned int v30; // r8d
  int v31; // ebx
  hkVector4f *v32; // rax
  __int64 i; // rbx
  int v34; // ebx
  int m_capacityAndFlags; // eax
  int v36; // r9d
  hkErrStream *v37; // rcx
  int v38; // edx
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // r9d
  hkRefPtr<hkaiVolume const > *v43; // rdi
  __int64 v44; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkBitField *m_enum; // rcx
  hkRefPtr<hkaiVolume const > *m_data; // rdi
  __int64 v48; // rbx
  hkRefPtr<hkaiVolume const > *v49; // r12
  __int64 v50; // r13
  hkReferencedObject *v51; // rcx
  hkReferencedObject *v52; // rcx
  hkaiVolume *v53; // rax
  hkRefPtr<hkaiVolume const > *v54; // rbx
  hkRefPtr<hkaiVolume const > *v55; // rcx
  hkBitField *v56; // rdx
  hkReferencedObject *v57; // rcx
  hkaiVolume **v58; // rdi
  hkAabb *p_m_boundsAabb; // rbx
  _QWORD **v60; // rax
  hkaiInvertedAabbVolume *v61; // rax
  hkaiVolume *v62; // rax
  hkaiVolume *v63; // rdi
  int v64; // ecx
  hkRefPtr<hkaiVolume const > *v65; // rbx
  hkRefPtr<hkaiVolume const > *v66; // rdx
  hkBitField *v67; // rax
  hkReferencedObject *v68; // rcx
  _QWORD **v69; // rax
  hkaiCarverTree *v70; // rax
  hkaiCarverTree *v71; // rax
  _QWORD **v72; // rax
  __int64 v73; // rax
  hkGeometry *v74; // r8
  hkGeometry *m_weldedGeometry; // rdi
  hkReferencedObject *v76; // rbx
  _QWORD *v77; // r8
  _QWORD *v78; // rcx
  unsigned __int64 v79; // rax
  _QWORD *v80; // rcx
  float m_quantizationGridSize; // xmm1_4
  int v82; // ebx
  int v83; // ecx
  int v84; // eax
  hkErrStream *v85; // rcx
  int v86; // eax
  int v87; // eax
  int v88; // r9d
  int v89; // ebx
  int v90; // r9d
  int v91; // r9d
  int v92; // r9d
  hkVector4f *v93; // rax
  int v94; // r9d
  hkErrStream *v95; // rcx
  hkVector4f *v96; // rax
  hkVector4f *v97; // rax
  _QWORD *v98; // r8
  _QWORD *v99; // rcx
  unsigned __int64 v100; // rax
  _QWORD *v101; // rcx
  _QWORD *v102; // r8
  _QWORD *v103; // rcx
  unsigned __int64 v104; // rax
  _QWORD *v105; // rcx
  int v106; // r9d
  hkBitField *m_cuttingTriangles; // rbx
  hkBitField *m_walkableTriangles; // rax
  hkBitField *v109; // rcx
  hkErrStream *v110; // rcx
  hkVector4f *v111; // rax
  int v112; // ebx
  hkBitField *v113; // r13
  hkcdDynamicAabbTree *v114; // rbx
  _QWORD *v115; // r8
  _QWORD *v116; // rcx
  unsigned __int64 v117; // rax
  _QWORD *v118; // rcx
  _QWORD **v119; // rax
  hkcdDynamicAabbTree *v120; // rax
  hkcdDynamicAabbTree *v121; // rax
  hkErrStream *v122; // rcx
  hkVector4f *v123; // rax
  _QWORD *v124; // r8
  _QWORD *v125; // rcx
  unsigned __int64 v126; // rax
  _QWORD *v127; // rcx
  _QWORD *v128; // r8
  _QWORD *v129; // rcx
  unsigned __int64 v130; // rax
  _QWORD *v131; // rcx
  int v132; // eax
  int v133; // r9d
  hkErrStream *v134; // rcx
  int v135; // r9d
  int v136; // ecx
  hkVector4f *v137; // rax
  hkVector4f *v138; // rax
  __m128 v139; // xmm6
  _QWORD *v140; // r8
  unsigned __int64 v141; // rcx
  unsigned __int64 v142; // rax
  _QWORD *v143; // r8
  _QWORD *v144; // rcx
  unsigned __int64 v145; // rax
  _QWORD *v146; // rcx
  hkVector4f *v147; // rax
  _QWORD *v148; // r8
  _QWORD *v149; // rcx
  unsigned __int64 v150; // rax
  _QWORD *v151; // rcx
  _QWORD *v152; // r8
  unsigned __int64 v153; // rcx
  unsigned __int64 v154; // rax
  __m128 v155; // xmm2
  __m128 v156; // xmm1
  __m128 v157; // xmm4
  __m128 v158; // xmm4
  __m128 v159; // xmm1
  __m128 v160; // xmm2
  __m128 v161; // xmm3
  __m128 v162; // xmm5
  int v163; // ecx
  __m128 v164; // xmm3
  __m128 v165; // xmm1
  __m128 v166; // xmm2
  _QWORD *v167; // r8
  _QWORD *v168; // rcx
  unsigned __int64 v169; // rax
  _QWORD *v170; // rcx
  _QWORD *v171; // r8
  _QWORD *v172; // rcx
  unsigned __int64 v173; // rax
  _QWORD *v174; // rcx
  _QWORD *v175; // r8
  _QWORD *v176; // rcx
  unsigned __int64 v177; // rax
  _QWORD *v178; // rcx
  _QWORD *v179; // r8
  _QWORD *v180; // rcx
  unsigned __int64 v181; // rax
  _QWORD *v182; // rcx
  _QWORD *v183; // r8
  _QWORD *v184; // rcx
  unsigned __int64 v185; // rax
  _QWORD *v186; // rcx
  _QWORD *v187; // r8
  _QWORD *v188; // rcx
  unsigned __int64 v189; // rax
  _QWORD *v190; // rcx
  _QWORD *v191; // r8
  _QWORD *v192; // rcx
  unsigned __int64 v193; // rax
  _QWORD *v194; // rcx
  _QWORD *v195; // r8
  _QWORD *v196; // rcx
  unsigned __int64 v197; // rax
  _QWORD *v198; // rcx
  int v199; // edx
  int v200; // r8d
  __int64 v201; // rcx
  int v202; // edx
  int v203; // eax
  int v204; // r8d
  __int64 v205; // rcx
  _QWORD *v206; // r8
  _QWORD *v207; // rcx
  unsigned __int64 v208; // rax
  _QWORD *v209; // rcx
  hkErrStream *v210; // rcx
  hkVector4f *v211; // rax
  hkErrStream *v212; // rcx
  hkVector4f *v213; // rax
  _QWORD *v214; // r8
  _QWORD *v215; // rcx
  unsigned __int64 v216; // rax
  _QWORD *v217; // rcx
  hkVector4f *v218; // rax
  _QWORD *v219; // r8
  _QWORD *v220; // rcx
  unsigned __int64 v221; // rax
  _QWORD *v222; // rcx
  _QWORD *v223; // r8
  _QWORD *v224; // rcx
  unsigned __int64 v225; // rax
  _QWORD *v226; // rcx
  hkVector4f *v227; // rax
  _QWORD *v228; // r8
  _QWORD *v229; // rcx
  unsigned __int64 v230; // rax
  _QWORD *v231; // rcx
  __int64 v232; // r9
  __int64 v233; // r8
  __int64 v234; // rcx
  _QWORD *v235; // r8
  _QWORD *v236; // rcx
  unsigned __int64 v237; // rax
  _QWORD *v238; // rcx
  _QWORD **v239; // rax
  hkaiEdgeGeometryRaycaster *v240; // rax
  __int64 v241; // rax
  _QWORD *v242; // r8
  _QWORD *v243; // rcx
  unsigned __int64 v244; // rax
  _QWORD *v245; // rcx
  hkErrStream *v246; // rcx
  hkVector4f *v247; // rax
  _QWORD *v248; // r8
  _QWORD *v249; // rcx
  unsigned __int64 v250; // rax
  _QWORD *v251; // rcx
  _QWORD *v252; // r8
  _QWORD *v253; // rcx
  unsigned __int64 v254; // rax
  _QWORD *v255; // rcx
  _QWORD *v256; // r8
  _QWORD *v257; // rcx
  unsigned __int64 v258; // rax
  _QWORD *v259; // rcx
  _QWORD *v260; // r8
  _QWORD *v261; // rcx
  unsigned __int64 v262; // rax
  _QWORD *v263; // rcx
  _QWORD *v264; // r8
  _QWORD *v265; // rcx
  unsigned __int64 v266; // rax
  _QWORD *v267; // rcx
  hkErrStream *v268; // rcx
  hkaiNavMesh *v269; // rdi
  hkaiNavMesh *v270; // rax
  _QWORD *v271; // r8
  _QWORD *v272; // rcx
  unsigned __int64 v273; // rax
  _QWORD *v274; // rcx
  int v275; // edi
  _QWORD *v276; // r8
  _QWORD *v277; // rcx
  unsigned __int64 v278; // rax
  _QWORD *v279; // rcx
  _QWORD *v280; // r8
  _QWORD *v281; // rcx
  unsigned __int64 v282; // rax
  _QWORD *v283; // rcx
  hkaiNavMesh *v284; // rdi
  hkErrStream *v285; // rcx
  hkErrStream *v286; // rcx
  hkVector4f *v287; // rax
  __m128 v288; // xmm2
  hkaiNavMesh *v289; // r14
  hkaiNavMesh *m_unsimplifiedNavMesh; // rcx
  _QWORD *v291; // r8
  _QWORD *v292; // rcx
  unsigned __int64 v293; // rax
  _QWORD *v294; // rcx
  int v295; // edi
  _QWORD *v296; // r8
  _QWORD *v297; // rcx
  unsigned __int64 v298; // rax
  _QWORD *v299; // rcx
  hkVector4f *v300; // rax
  _QWORD *v301; // r8
  _QWORD *v302; // rcx
  unsigned __int64 v303; // rax
  _QWORD *v304; // rcx
  hkVector4f *v305; // rax
  hkVector4f *v306; // rax
  hkVector4f *v307; // rax
  int v308; // ebx
  hkRefPtr<hkaiVolume const > *v309; // rdi
  hkVector4f *v310; // rax
  hkVector4f *v311; // rax
  _QWORD *v312; // rax
  _QWORD *v313; // rcx
  _QWORD *v314; // r8
  unsigned __int64 v315; // rax
  _QWORD *v316; // rcx
  int sizeElem; // [rsp+20h] [rbp-E0h]
  int sizeElema; // [rsp+20h] [rbp-E0h]
  int sizeElemb; // [rsp+20h] [rbp-E0h]
  int sizeElemc; // [rsp+20h] [rbp-E0h]
  hkArrayBase<hkRefPtr<hkaiVolume const > > carvers; // [rsp+80h] [rbp-80h] BYREF
  hkArrayBase<int> originalFaceIndices; // [rsp+90h] [rbp-70h] BYREF
  hkBitField *walkableInOut; // [rsp+A0h] [rbp-60h]
  int v325; // [rsp+A8h] [rbp-58h]
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+B0h] [rbp-50h] BYREF
  hkArrayBase<unsigned int> v327; // [rsp+C0h] [rbp-40h] BYREF
  hkResult v328[2]; // [rsp+D0h] [rbp-30h] BYREF
  hkResult v329; // [rsp+D8h] [rbp-28h] BYREF
  hkArrayBase<hkVector4f> triangleVertices; // [rsp+E0h] [rbp-20h] BYREF
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+F0h] [rbp-10h] BYREF
  hkArray<int,hkContainerHeapAllocator> hitFaces; // [rsp+100h] [rbp+0h] BYREF
  hkReferencedObject *v333; // [rsp+110h] [rbp+10h]
  hkArrayBase<unsigned int> v334; // [rsp+118h] [rbp+18h] BYREF
  hkArrayBase<unsigned int> v335; // [rsp+128h] [rbp+28h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+138h] [rbp+38h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+148h] [rbp+48h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+158h] [rbp+58h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+168h] [rbp+68h] BYREF
  int v340; // [rsp+178h] [rbp+78h]
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+180h] [rbp+80h] BYREF
  hkaiNavMesh *navMeshOut; // [rsp+190h] [rbp+90h]
  char v343; // [rsp+198h] [rbp+98h]
  hkArray<int,hkContainerHeapAllocator> remap; // [rsp+1A0h] [rbp+A0h] BYREF
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+1B0h] [rbp+B0h] BYREF
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+1C0h] [rbp+C0h] BYREF
  hkBitField *cuttingTriangles; // [rsp+1D0h] [rbp+D0h]
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+1D8h] [rbp+D8h] BYREF
  char v349; // [rsp+1E8h] [rbp+E8h] BYREF
  void *array; // [rsp+1F0h] [rbp+F0h] BYREF
  int v351; // [rsp+1F8h] [rbp+F8h]
  int v352; // [rsp+1FCh] [rbp+FCh]
  hkResult v353; // [rsp+200h] [rbp+100h] BYREF
  hkResult v354; // [rsp+204h] [rbp+104h] BYREF
  hkResult v355; // [rsp+208h] [rbp+108h] BYREF
  hkaiCarverTree *carverTree; // [rsp+210h] [rbp+110h]
  hkResult v357; // [rsp+218h] [rbp+118h] BYREF
  hkResult v358; // [rsp+21Ch] [rbp+11Ch] BYREF
  hkResult v359; // [rsp+220h] [rbp+120h] BYREF
  hkResult v360; // [rsp+224h] [rbp+124h] BYREF
  hkResult v361; // [rsp+228h] [rbp+128h] BYREF
  hkResult v362; // [rsp+22Ch] [rbp+12Ch] BYREF
  hkResult v363; // [rsp+230h] [rbp+130h] BYREF
  hkResult v364; // [rsp+234h] [rbp+134h] BYREF
  hkResult v365; // [rsp+238h] [rbp+138h] BYREF
  hkResult v366; // [rsp+23Ch] [rbp+13Ch] BYREF
  hkResult v367; // [rsp+240h] [rbp+140h] BYREF
  hkResult v368; // [rsp+244h] [rbp+144h] BYREF
  hkResult v369; // [rsp+248h] [rbp+148h] BYREF
  hkResult v370; // [rsp+24Ch] [rbp+14Ch] BYREF
  hkResult v371; // [rsp+250h] [rbp+150h] BYREF
  hkResult v372; // [rsp+254h] [rbp+154h] BYREF
  hkResult v373; // [rsp+258h] [rbp+158h] BYREF
  hkaiNavMesh *mesh; // [rsp+260h] [rbp+160h]
  int v375; // [rsp+268h] [rbp+168h] BYREF
  hkResult v376; // [rsp+26Ch] [rbp+16Ch] BYREF
  int v377; // [rsp+270h] [rbp+170h]
  hkResult v378; // [rsp+274h] [rbp+174h] BYREF
  hkResult v379; // [rsp+278h] [rbp+178h] BYREF
  hkResult v380; // [rsp+27Ch] [rbp+17Ch] BYREF
  hkResult v381; // [rsp+280h] [rbp+180h] BYREF
  hkResult v382; // [rsp+284h] [rbp+184h] BYREF
  int v383; // [rsp+288h] [rbp+188h] BYREF
  int newStride; // [rsp+28Ch] [rbp+18Ch]
  int v385; // [rsp+290h] [rbp+190h] BYREF
  hkResult v386; // [rsp+294h] [rbp+194h] BYREF
  int v387; // [rsp+298h] [rbp+198h] BYREF
  hkResult v388; // [rsp+29Ch] [rbp+19Ch] BYREF
  void **v389; // [rsp+2A0h] [rbp+1A0h] BYREF
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v390; // [rsp+2A8h] [rbp+1A8h] BYREF
  hkGeometry cuttingGeom; // [rsp+2B8h] [rbp+1B8h] BYREF
  hkaiFaceEdges faceEdges; // [rsp+2E8h] [rbp+1E8h] BYREF
  hkaiNavMeshGenerationProgressCallbackContext cbCtx; // [rsp+310h] [rbp+210h] BYREF
  hkResult v394; // [rsp+380h] [rbp+280h] BYREF
  hkResult v395; // [rsp+384h] [rbp+284h] BYREF
  hkReferencedObject *v396; // [rsp+388h] [rbp+288h]
  hkResult v397; // [rsp+390h] [rbp+290h] BYREF
  hkReferencedObject *v398; // [rsp+398h] [rbp+298h]
  hkaMatrix<float> v399; // [rsp+3A0h] [rbp+2A0h] BYREF
  hkResult result; // [rsp+3B8h] [rbp+2B8h] BYREF
  hkaMatrix<float> v401; // [rsp+3C0h] [rbp+2C0h] BYREF
  hkVector4f vertsOut; // [rsp+3E0h] [rbp+2E0h] BYREF
  __m128 v403; // [rsp+3F0h] [rbp+2F0h]
  __m128 v404; // [rsp+400h] [rbp+300h]
  hkVector4f extrudeDirection; // [rsp+410h] [rbp+310h] BYREF
  hkAabb extrudedTriAabb; // [rsp+420h] [rbp+320h] BYREF
  hkaiEdgeGeometry geom; // [rsp+440h] [rbp+340h] BYREF
  hkErrStream v408; // [rsp+490h] [rbp+390h] BYREF
  hkErrStream v409; // [rsp+4A8h] [rbp+3A8h] BYREF
  hkErrStream v410; // [rsp+4C0h] [rbp+3C0h] BYREF
  hkErrStream v411; // [rsp+4D8h] [rbp+3D8h] BYREF
  hkErrStream v412; // [rsp+4F0h] [rbp+3F0h] BYREF
  hkErrStream v413; // [rsp+508h] [rbp+408h] BYREF
  hkErrStream v414; // [rsp+520h] [rbp+420h] BYREF
  hkErrStream v415; // [rsp+538h] [rbp+438h] BYREF
  hkErrStream v416; // [rsp+550h] [rbp+450h] BYREF
  hkErrStream v417; // [rsp+568h] [rbp+468h] BYREF
  hkErrStream v418; // [rsp+580h] [rbp+480h] BYREF
  hkErrStream v419; // [rsp+598h] [rbp+498h] BYREF
  hkErrStream v420; // [rsp+5B0h] [rbp+4B0h] BYREF
  hkErrStream v421; // [rsp+5C8h] [rbp+4C8h] BYREF
  hkErrStream v422; // [rsp+5E0h] [rbp+4E0h] BYREF
  hkErrStream v423; // [rsp+5F8h] [rbp+4F8h] BYREF
  hkErrStream v424; // [rsp+610h] [rbp+510h] BYREF
  hkErrStream v425; // [rsp+628h] [rbp+528h] BYREF
  hkErrStream v426; // [rsp+640h] [rbp+540h] BYREF
  hkErrStream v427; // [rsp+658h] [rbp+558h] BYREF
  hkErrStream v428; // [rsp+670h] [rbp+570h] BYREF
  hkErrStream v429; // [rsp+688h] [rbp+588h] BYREF
  hkErrStream v430; // [rsp+6A0h] [rbp+5A0h] BYREF
  hkErrStream v431; // [rsp+6B8h] [rbp+5B8h] BYREF
  hkErrStream v432; // [rsp+6D0h] [rbp+5D0h] BYREF
  hkVector4f rayDir; // [rsp+6F0h] [rbp+5F0h] BYREF
  hkErrStream v434; // [rsp+700h] [rbp+600h] BYREF
  hkErrStream v435; // [rsp+718h] [rbp+618h] BYREF
  hkErrStream v436; // [rsp+730h] [rbp+630h] BYREF
  hkErrStream v437; // [rsp+748h] [rbp+648h] BYREF
  hkErrStream v438; // [rsp+760h] [rbp+660h] BYREF
  hkErrStream v439; // [rsp+778h] [rbp+678h] BYREF
  hkErrStream v440; // [rsp+790h] [rbp+690h] BYREF
  hkErrStream v441; // [rsp+7A8h] [rbp+6A8h] BYREF
  hkErrStream v442; // [rsp+7C0h] [rbp+6C0h] BYREF
  hkErrStream v443; // [rsp+7D8h] [rbp+6D8h] BYREF
  hkErrStream v444; // [rsp+7F0h] [rbp+6F0h] BYREF
  hkErrStream v445; // [rsp+808h] [rbp+708h] BYREF
  hkErrStream v446; // [rsp+820h] [rbp+720h] BYREF
  hkErrStream v447; // [rsp+838h] [rbp+738h] BYREF
  hkErrStream v448; // [rsp+850h] [rbp+750h] BYREF
  hkErrStream v449; // [rsp+868h] [rbp+768h] BYREF
  hkErrStream v450; // [rsp+880h] [rbp+780h] BYREF
  hkErrStream v451; // [rsp+898h] [rbp+798h] BYREF
  hkErrStream v452; // [rsp+8B0h] [rbp+7B0h] BYREF
  hkErrStream v453; // [rsp+8C8h] [rbp+7C8h] BYREF
  hkErrStream v454; // [rsp+8E0h] [rbp+7E0h] BYREF
  hkErrStream v455; // [rsp+8F8h] [rbp+7F8h] BYREF
  hkErrStream v456; // [rsp+910h] [rbp+810h] BYREF
  hkErrStream v457; // [rsp+928h] [rbp+828h] BYREF
  hkSimdFloat32 characterHeight; // [rsp+940h] [rbp+840h] BYREF
  hkErrStream v459; // [rsp+950h] [rbp+850h] BYREF
  hkErrStream v460; // [rsp+968h] [rbp+868h] BYREF
  hkErrStream v461; // [rsp+980h] [rbp+880h] BYREF
  hkErrStream v462; // [rsp+998h] [rbp+898h] BYREF
  hkErrStream v463; // [rsp+9B0h] [rbp+8B0h] BYREF
  hkErrStream v464; // [rsp+9C8h] [rbp+8C8h] BYREF
  hkErrStream v465; // [rsp+9E0h] [rbp+8E0h] BYREF
  hkaiEdgeGeometry geomA; // [rsp+A00h] [rbp+900h] BYREF
  hkErrStream v467; // [rsp+A50h] [rbp+950h] BYREF
  hkErrStream v468; // [rsp+A68h] [rbp+968h] BYREF
  hkErrStream v469; // [rsp+A80h] [rbp+980h] BYREF
  hkErrStream v470; // [rsp+A98h] [rbp+998h] BYREF
  hkaiEdgeGeometry geomOut; // [rsp+AB0h] [rbp+9B0h] BYREF
  hkaiEdgeGeometry cuttingEdgeGeometryOut; // [rsp+B00h] [rbp+A00h] BYREF
  hkaiSelfIntersectBooleanFilter2 v473; // [rsp+B50h] [rbp+A50h] BYREF
  __m128 v474; // [rsp+BB0h] [rbp+AB0h]
  hkaiGeometryExtrudeUtil v475; // [rsp+BC0h] [rbp+AC0h] BYREF
  hkaiBooleanOperation v476; // [rsp+C80h] [rbp+B80h] BYREF
  hkaiNavMeshSimplificationSnapshot v477; // [rsp+DF0h] [rbp+CF0h] BYREF
  char v478[512]; // [rsp+1020h] [rbp+F20h] BYREF
  char v479[512]; // [rsp+1220h] [rbp+1120h] BYREF
  char v480[512]; // [rsp+1420h] [rbp+1320h] BYREF
  char v481[512]; // [rsp+1620h] [rbp+1520h] BYREF
  char v482[512]; // [rsp+1820h] [rbp+1720h] BYREF
  char v483[512]; // [rsp+1A20h] [rbp+1920h] BYREF
  char v484[512]; // [rsp+1C20h] [rbp+1B20h] BYREF
  char v485[512]; // [rsp+1E20h] [rbp+1D20h] BYREF
  char v486[512]; // [rsp+2020h] [rbp+1F20h] BYREF
  char v487[512]; // [rsp+2220h] [rbp+2120h] BYREF
  char v488[512]; // [rsp+2420h] [rbp+2320h] BYREF
  char v489[512]; // [rsp+2620h] [rbp+2520h] BYREF
  char v490[512]; // [rsp+2820h] [rbp+2720h] BYREF
  char v491[512]; // [rsp+2A20h] [rbp+2920h] BYREF
  char v492[512]; // [rsp+2C20h] [rbp+2B20h] BYREF
  char v493[512]; // [rsp+2E20h] [rbp+2D20h] BYREF
  char v494[512]; // [rsp+3020h] [rbp+2F20h] BYREF
  char v495[512]; // [rsp+3220h] [rbp+3120h] BYREF
  char v496[512]; // [rsp+3420h] [rbp+3320h] BYREF
  char v497[512]; // [rsp+3620h] [rbp+3520h] BYREF
  char v498[512]; // [rsp+3820h] [rbp+3720h] BYREF
  char v499[512]; // [rsp+3A20h] [rbp+3920h] BYREF
  char v500[512]; // [rsp+3C20h] [rbp+3B20h] BYREF
  char v501[512]; // [rsp+3E20h] [rbp+3D20h] BYREF
  char v502[512]; // [rsp+4020h] [rbp+3F20h] BYREF
  char v503[512]; // [rsp+4220h] [rbp+4120h] BYREF
  char v504[512]; // [rsp+4420h] [rbp+4320h] BYREF
  char v505[512]; // [rsp+4620h] [rbp+4520h] BYREF
  char buf[512]; // [rsp+4820h] [rbp+4720h] BYREF
  char v507[512]; // [rsp+4A20h] [rbp+4920h] BYREF
  char v508[512]; // [rsp+4C20h] [rbp+4B20h] BYREF
  char v509[512]; // [rsp+4E20h] [rbp+4D20h] BYREF
  char v510[512]; // [rsp+5020h] [rbp+4F20h] BYREF
  char v511[512]; // [rsp+5220h] [rbp+5120h] BYREF
  char v512[512]; // [rsp+5420h] [rbp+5320h] BYREF
  char v513[512]; // [rsp+5620h] [rbp+5520h] BYREF
  char v514[512]; // [rsp+5820h] [rbp+5720h] BYREF
  char v515[512]; // [rsp+5A20h] [rbp+5920h] BYREF
  char v516[512]; // [rsp+5C20h] [rbp+5B20h] BYREF
  char v517[512]; // [rsp+5E20h] [rbp+5D20h] BYREF
  char v518[512]; // [rsp+6020h] [rbp+5F20h] BYREF
  char v519[512]; // [rsp+6220h] [rbp+6120h] BYREF
  char v520[512]; // [rsp+6420h] [rbp+6320h] BYREF
  char v521[512]; // [rsp+6620h] [rbp+6520h] BYREF
  char v522[512]; // [rsp+6820h] [rbp+6720h] BYREF
  char v523[512]; // [rsp+6A20h] [rbp+6920h] BYREF
  char v524[512]; // [rsp+6C20h] [rbp+6B20h] BYREF
  char v525[512]; // [rsp+6E20h] [rbp+6D20h] BYREF
  char v526[512]; // [rsp+7020h] [rbp+6F20h] BYREF
  char v527[512]; // [rsp+7220h] [rbp+7120h] BYREF
  char v528[512]; // [rsp+7420h] [rbp+7320h] BYREF
  char v529[512]; // [rsp+7620h] [rbp+7520h] BYREF
  char v530[512]; // [rsp+7820h] [rbp+7720h] BYREF
  char v531[512]; // [rsp+7A20h] [rbp+7920h] BYREF
  char v532[512]; // [rsp+7C20h] [rbp+7B20h] BYREF
  char v533[512]; // [rsp+7E20h] [rbp+7D20h] BYREF
  char v534[512]; // [rsp+8020h] [rbp+7F20h] BYREF
  char v535[512]; // [rsp+8220h] [rbp+8120h] BYREF
  char v536[512]; // [rsp+8420h] [rbp+8320h] BYREF
  char description[512]; // [rsp+8620h] [rbp+8520h] BYREF
  bool v538; // [rsp+8870h] [rbp+8770h]
  hkGeometry *v539; // [rsp+8878h] [rbp+8778h] BYREF
  hkaiNavMeshGenerationOutputs *v540; // [rsp+8880h] [rbp+8780h]

  v540 = outputs;
  v539 = _triMeshIn;
  v7 = outputs;
  v538 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TthkaiNavMeshGenerationUtils::generateNavMesh";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v11 += 2;
    *((_DWORD *)v11 - 2) = v13;
    v12[1] = v11;
  }
  if ( !_triMeshIn->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v460, buf, 512);
    hkOstream::operator<<(&v460, "Passed in empty triMesh to generateNavMesh()");
    hkError::messageWarning(1060047688, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 401);
    hkOstream::~hkOstream(&v460);
    m_navMesh = (hkVector4f *)v7->m_navMesh;
    if ( m_navMesh )
    {
      m_navMesh[8] = (hkVector4f)aabbOut.m_quad;
      m_navMesh[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 1;
    goto LABEL_547;
  }
  if ( !HK_flyingcolors_ai.m_bool )
  {
    hkaiCheckKeycode(v11, v10, v12);
    hkaiProcessFlyingColors(&HK_flyingcolors_ai);
    if ( !HK_flyingcolors_ai.m_bool )
    {
      hkErrStream::hkErrStream(&v462, description, 512);
      hkOstream::operator<<(&v462, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(691989308, description, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 413);
      hkOstream::~hkOstream(&v462);
      v16 = (hkVector4f *)v7->m_navMesh;
      if ( v16 )
      {
        v16[8] = (hkVector4f)aabbOut.m_quad;
        v16[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 3;
      goto LABEL_547;
    }
  }
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkaiNavMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 176i64);
  if ( !v18 || (hkaiNavMesh::hkaiNavMesh(v18), v20 = (hkaiNavMesh *)v19, (v398 = v19) == 0i64) )
  {
    hkErrStream::hkErrStream(&v456, v535, 512);
    hkOstream::operator<<(
      &v456,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v535, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 443);
    hkOstream::~hkOstream(&v456);
    v311 = (hkVector4f *)v7->m_navMesh;
    if ( v311 )
    {
      v311[8] = (hkVector4f)aabbOut.m_quad;
      v311[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_547;
  }
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkaiNavMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 176i64);
  if ( !v22 || (hkaiNavMesh::hkaiNavMesh(v22), (v396 = v23) == 0i64) )
  {
    hkErrStream::hkErrStream(&v454, v533, 512);
    hkOstream::operator<<(
      &v454,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v533, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 444);
    hkOstream::~hkOstream(&v454);
    v310 = (hkVector4f *)v7->m_navMesh;
    if ( v310 )
    {
      v310[8] = (hkVector4f)aabbOut.m_quad;
      v310[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    hkReferencedObject::removeReference(v398);
    goto LABEL_547;
  }
  if ( v7->m_navMesh )
    v23 = v7->m_navMesh;
  v24 = input->m_enableSimplification.m_bool == 0;
  m_edgeDataStriding = v23->m_edgeDataStriding;
  v26 = v23;
  mesh = v23;
  if ( !v24 )
    v26 = v20;
  newStride = m_edgeDataStriding;
  navMeshOut = v26;
  hkaiNavMesh::setEdgeDataStriding(v23, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v26, &v394, 0, 0);
  if ( input->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(input, _triMeshIn);
  cb = (hkaiNavMeshGenerationProgressCallback *)&v389;
  if ( _callbacks )
    cb = _callbacks;
  cuttingTriangles = (hkBitField *)cb;
  v389 = &hkaiNavMeshGenerationProgressCallback::`vftable;
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&cbCtx, input);
  if ( !cb->vfptr->stepStartedCallback(cb, UNASSIGNED, &cbCtx)
    || !cb->vfptr->stepEndedCallback(cb, UNASSIGNED, &cbCtx)
    || (v15 = 1, !cb->vfptr->stepStartedCallback(cb, BEGIN, &cbCtx)) )
  {
    v15 = 0;
    goto LABEL_540;
  }
  m_size = input->m_materialMap.m_size;
  v352 = 0x80000000;
  array = 0i64;
  v351 = 0;
  SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(m_size);
  v30 = 0x80000000;
  v31 = SizeInBytesFor;
  if ( SizeInBytesFor <= 0 )
  {
    v362.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v362, &hkContainerHeapAllocator::s_alloc, &array, SizeInBytesFor, 1);
    if ( v362.m_enum )
    {
      hkErrStream::hkErrStream(&v464, v480, 512);
      hkOstream::operator<<(
        &v464,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v480, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 480);
      hkOstream::~hkOstream(&v464);
      v32 = (hkVector4f *)v7->m_navMesh;
      if ( v32 )
      {
        v32[8] = (hkVector4f)aabbOut.m_quad;
        v32[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_536;
    }
    v30 = v352;
  }
  v351 = v31;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    &v390,
    array,
    v30 & 0x3FFFFFFF);
  for ( i = 0i64; i < m_size; ++i )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v390,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned int)input->m_materialMap.m_data[i].m_materialIndex,
      input->m_materialMap.m_data[i].m_flags.m_storage);
  v34 = 0;
  m_capacityAndFlags = 0x80000000;
  carvers.m_data = 0i64;
  carvers.m_size = 0;
  carvers.m_capacityAndFlags = 0x80000000;
  v36 = input->m_carvers.m_size + 1;
  if ( v36 <= 0 )
  {
    v358.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v358, &hkContainerTempAllocator::s_alloc, &carvers, v36, 8);
    if ( v358.m_enum )
    {
      hkErrStream::hkErrStream(&v441, v530, 512);
      hkOstream::operator<<(
        &v441,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v530, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 498);
      v37 = &v441;
LABEL_527:
      hkOstream::~hkOstream(v37);
      v307 = (hkVector4f *)v7->m_navMesh;
      if ( v307 )
      {
        v307[8] = (hkVector4f)aabbOut.m_quad;
        v307[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_530;
    }
    m_capacityAndFlags = carvers.m_capacityAndFlags;
    v34 = carvers.m_size;
  }
  v39 = input->m_carvers.m_size;
  v325 = v39;
  v38 = v39;
  if ( v39 > v34 )
    v39 = v34;
  v40 = m_capacityAndFlags & 0x3FFFFFFF;
  v329.m_enum = v39;
  if ( v40 >= v325 )
  {
    v379.m_enum = HK_SUCCESS;
  }
  else
  {
    v41 = 2 * v40;
    v42 = v325;
    if ( v325 < v41 )
      v42 = v41;
    hkArrayUtil::_reserve(&v379, &hkContainerTempAllocator::s_alloc, &carvers, v42, 8);
    v38 = v325;
  }
  v43 = &carvers.m_data[v38];
  v44 = v34 - v38 - 1;
  if ( (int)v44 >= 0 )
  {
    do
    {
      m_pntr = v43[v44].m_pntr;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      v43[v44--].m_pntr = 0i64;
    }
    while ( v44 >= 0 );
  }
  m_enum = (hkBitField *)(int)v329.m_enum;
  m_data = input->m_carvers.m_data;
  v48 = 0i64;
  walkableInOut = (hkBitField *)(int)v329.m_enum;
  if ( v329.m_enum > HK_SUCCESS )
  {
    v49 = carvers.m_data;
    v50 = v329.m_enum;
    do
    {
      v51 = m_data[v48].m_pntr;
      if ( v51 )
        hkReferencedObject::addReference(v51);
      v52 = v49[v48].m_pntr;
      if ( v52 )
        hkReferencedObject::removeReference(v52);
      v53 = m_data[v48++].m_pntr;
      v49[v48 - 1].m_pntr = v53;
    }
    while ( v48 < v50 );
    cb = (hkaiNavMeshGenerationProgressCallback *)cuttingTriangles;
    v7 = v540;
    m_enum = walkableInOut;
  }
  v54 = &input->m_carvers.m_data[(_QWORD)m_enum];
  v55 = &carvers.m_data[(_QWORD)m_enum];
  v56 = (hkBitField *)(v325 - v329.m_enum);
  walkableInOut = v56;
  if ( v325 - v329.m_enum > 0 )
  {
    v57 = (hkReferencedObject *)((char *)v55 - (char *)v54);
    v333 = v57;
    do
    {
      v58 = (hkaiVolume **)((char *)&v54->m_pntr + (_QWORD)v57);
      if ( (hkRefPtr<hkaiVolume const > *)((char *)v54 + (_QWORD)v57) )
      {
        if ( v54->m_pntr )
        {
          hkReferencedObject::addReference(v54->m_pntr);
          v56 = walkableInOut;
        }
        v57 = v333;
        *v58 = v54->m_pntr;
      }
      ++v54;
      v56 = (hkBitField *)((char *)v56 - 1);
      walkableInOut = v56;
    }
    while ( v56 );
  }
  p_m_boundsAabb = &input->m_boundsAabb;
  carvers.m_size = v325;
  if ( (_mm_movemask_ps(_mm_cmple_ps(input->m_boundsAabb.m_max.m_quad, input->m_boundsAabb.m_min.m_quad)) & 7) == 0 )
  {
    v60 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v61 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v60[11] + 8i64))(v60[11], 96i64);
    if ( v61 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v61, &input->m_boundsAabb);
      v63 = v62;
    }
    else
    {
      v63 = 0i64;
    }
    v64 = carvers.m_size;
    if ( carvers.m_size == (carvers.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &carvers, 8);
      v64 = carvers.m_size;
    }
    v65 = carvers.m_data;
    v66 = &carvers.m_data[v64];
    if ( v66 )
    {
      v66->m_pntr = 0i64;
      v64 = carvers.m_size;
      v65 = carvers.m_data;
    }
    v67 = (hkBitField *)v64;
    carvers.m_size = v64 + 1;
    v68 = v65[v64].m_pntr;
    walkableInOut = v67;
    if ( v68 && v68 != v63 )
    {
      hkReferencedObject::removeReference(v68);
      v67 = walkableInOut;
    }
    v65[(_QWORD)v67].m_pntr = v63;
    p_m_boundsAabb = &input->m_boundsAabb;
  }
  v69 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v70 = (hkaiCarverTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v69[11] + 8i64))(v69[11], 48i64);
  if ( !v70 || (hkaiCarverTree::hkaiCarverTree(v70), (carverTree = v71) == 0i64) )
  {
    hkErrStream::hkErrStream(&v452, v531, 512);
    hkOstream::operator<<(
      &v452,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v531, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 516);
    v37 = &v452;
    goto LABEL_527;
  }
  hkaiCarverTree::init(v71, &v395, &carvers, &input->m_painters);
  v72 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v73 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v72[11] + 8i64))(v72[11], 48i64);
  v333 = (hkReferencedObject *)v73;
  if ( !v73 )
  {
    v76 = 0i64;
    hkErrStream::hkErrStream(&v450, v529, 512);
    hkOstream::operator<<(
      &v450,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v529, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 519);
    hkOstream::~hkOstream(&v450);
    goto LABEL_520;
  }
  v74 = v539;
  *(_DWORD *)(v73 + 8) = 0x1FFFF;
  m_weldedGeometry = (hkGeometry *)v73;
  *(_QWORD *)v73 = &hkGeometry::`vftable;
  *(_QWORD *)(v73 + 16) = 0i64;
  *(_DWORD *)(v73 + 24) = 0;
  *(_DWORD *)(v73 + 28) = 0x80000000;
  *(_QWORD *)(v73 + 32) = 0i64;
  *(_DWORD *)(v73 + 40) = 0;
  *(_DWORD *)(v73 + 44) = 0x80000000;
  if ( v7->m_weldedGeometry )
    m_weldedGeometry = v7->m_weldedGeometry;
  hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(
    (hkResult *)&v539,
    m_weldedGeometry,
    v74,
    p_m_boundsAabb,
    (hkaiNavMeshGenerationSettings::TriangleWinding)(unsigned __int8)input->m_triangleWinding.m_storage);
  if ( (_DWORD)v539 )
  {
    hkErrStream::hkErrStream(&v469, v482, 512);
    hkOstream::operator<<(
      &v469,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v482, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 523);
    hkOstream::~hkOstream(&v469);
    v76 = v333;
LABEL_520:
    v306 = (hkVector4f *)v7->m_navMesh;
    if ( v306 )
    {
      v306[8] = (hkVector4f)aabbOut.m_quad;
      v306[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_523;
  }
  v77 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v78 = (_QWORD *)v77[1];
  if ( (unsigned __int64)v78 < v77[3] )
  {
    *v78 = "TtconvertAndMerge";
    v79 = __rdtsc();
    v80 = v78 + 2;
    *((_DWORD *)v80 - 2) = v79;
    v77[1] = v80;
  }
  m_quantizationGridSize = input->m_quantizationGridSize;
  if ( m_quantizationGridSize != 0.0 )
    hkaiNavMeshGenerationUtils::quantize(m_weldedGeometry, m_quantizationGridSize);
  if ( input->m_weldInputVertices.m_bool )
  {
    v82 = m_weldedGeometry->m_vertices.m_size;
    v83 = m_weldedGeometry->m_triangles.m_size;
    v84 = 0x80000000;
    vertexRemapOut.m_data = 0i64;
    vertexRemapOut.m_size = 0;
    vertexRemapOut.m_capacityAndFlags = 0x80000000;
    LODWORD(v539) = v83;
    triangleRemapOut.m_data = 0i64;
    triangleRemapOut.m_size = 0;
    triangleRemapOut.m_capacityAndFlags = 0x80000000;
    sweepAabbs.m_data = 0i64;
    sweepAabbs.m_size = 0;
    sweepAabbs.m_capacityAndFlags = 0x80000000;
    uniqueVerts.m_data = 0i64;
    uniqueVerts.m_size = 0;
    uniqueVerts.m_capacityAndFlags = 0x80000000;
    sortData.m_data = 0i64;
    sortData.m_size = 0;
    sortData.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_size = 0;
    sortedAabbs.m_capacityAndFlags = 0x80000000;
    if ( v82 <= 0 )
    {
      v354.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v354, &hkContainerHeapAllocator::s_alloc, &vertexRemapOut, v82, 4);
      if ( v354.m_enum )
      {
        hkErrStream::hkErrStream(&v411, v510, 512);
        hkOstream::operator<<(
          &v411,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v510, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 561);
        v85 = &v411;
LABEL_125:
        hkOstream::~hkOstream(v85);
        v93 = (hkVector4f *)v7->m_navMesh;
        if ( v93 )
        {
          v93[8] = (hkVector4f)aabbOut.m_quad;
          v93[9] = (hkVector4f)aabbOut.m_quad;
        }
        sortedAabbs.m_size = 0;
        if ( sortedAabbs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            sortedAabbs.m_data,
            32 * sortedAabbs.m_capacityAndFlags);
        sortedAabbs.m_data = 0i64;
        sortedAabbs.m_capacityAndFlags = 0x80000000;
        sortData.m_size = 0;
        if ( sortData.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            sortData.m_data,
            8 * sortData.m_capacityAndFlags);
        sortData.m_data = 0i64;
        sortData.m_capacityAndFlags = 0x80000000;
        uniqueVerts.m_size = 0;
        if ( uniqueVerts.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            uniqueVerts.m_data,
            16 * uniqueVerts.m_capacityAndFlags);
        uniqueVerts.m_data = 0i64;
        uniqueVerts.m_capacityAndFlags = 0x80000000;
        sweepAabbs.m_size = 0;
        if ( sweepAabbs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            sweepAabbs.m_data,
            32 * sweepAabbs.m_capacityAndFlags);
        sweepAabbs.m_data = 0i64;
        sweepAabbs.m_capacityAndFlags = 0x80000000;
        triangleRemapOut.m_size = 0;
        if ( triangleRemapOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            triangleRemapOut.m_data,
            4 * triangleRemapOut.m_capacityAndFlags);
        triangleRemapOut.m_data = 0i64;
        triangleRemapOut.m_capacityAndFlags = 0x80000000;
        vertexRemapOut.m_size = 0;
        if ( vertexRemapOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            vertexRemapOut.m_data,
            4 * vertexRemapOut.m_capacityAndFlags);
        vertexRemapOut.m_data = 0i64;
        vertexRemapOut.m_capacityAndFlags = 0x80000000;
        v15 = 2;
        goto LABEL_172;
      }
      v84 = triangleRemapOut.m_capacityAndFlags;
      v83 = (int)v539;
    }
    v86 = v84 & 0x3FFFFFFF;
    if ( v86 >= v83 )
    {
      v355.m_enum = HK_SUCCESS;
    }
    else
    {
      v87 = 2 * v86;
      if ( v83 < v87 )
        v83 = v87;
      hkArrayUtil::_reserve(&v355, &hkContainerHeapAllocator::s_alloc, &triangleRemapOut, v83, 4);
      if ( v355.m_enum )
      {
        hkErrStream::hkErrStream(&v457, v484, 512);
        hkOstream::operator<<(
          &v457,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v484, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 564);
        v85 = &v457;
        goto LABEL_125;
      }
    }
    if ( (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) >= v82 )
    {
      v357.m_enum = HK_SUCCESS;
    }
    else
    {
      v88 = v82;
      if ( v82 < 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) )
        v88 = 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v357, &hkContainerHeapAllocator::s_alloc, &uniqueVerts, v88, 16);
      if ( v357.m_enum )
      {
        hkErrStream::hkErrStream(&v413, v524, 512);
        hkOstream::operator<<(
          &v413,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v524, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 567);
        v85 = &v413;
        goto LABEL_125;
      }
    }
    v89 = v82 + 4;
    if ( (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v89 )
    {
      v359.m_enum = HK_SUCCESS;
    }
    else
    {
      v90 = v89;
      if ( v89 < 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
        v90 = 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v359, &hkContainerHeapAllocator::s_alloc, &sweepAabbs, v90, 32);
      if ( v359.m_enum )
      {
        hkErrStream::hkErrStream(&v443, v486, 512);
        hkOstream::operator<<(
          &v443,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v486, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 570);
        v85 = &v443;
        goto LABEL_125;
      }
    }
    if ( (sortData.m_capacityAndFlags & 0x3FFFFFFF) >= v89 )
    {
      v353.m_enum = HK_SUCCESS;
    }
    else
    {
      v91 = v89;
      if ( v89 < 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF) )
        v91 = 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v353, &hkContainerHeapAllocator::s_alloc, &sortData, v91, 8);
      if ( v353.m_enum )
      {
        hkErrStream::hkErrStream(&v415, v512, 512);
        hkOstream::operator<<(
          &v415,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v512, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 573);
        v85 = &v415;
        goto LABEL_125;
      }
    }
    sortData.m_size = v89;
    if ( (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v89 )
    {
      v363.m_enum = HK_SUCCESS;
    }
    else
    {
      v92 = v89;
      if ( v89 < 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
        v92 = 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v363, &hkContainerHeapAllocator::s_alloc, &sortedAabbs, v92, 32);
      if ( v363.m_enum )
      {
        hkErrStream::hkErrStream(&v465, v488, 512);
        hkOstream::operator<<(
          &v465,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v488, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 576);
        v85 = &v465;
        goto LABEL_125;
      }
    }
    sortedAabbs.m_size = v89;
    v343 = 0;
    hkGeometryUtils::_weldVertices(
      m_weldedGeometry,
      input->m_weldThreshold,
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
        &hkContainerHeapAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_capacityAndFlags = 0x80000000;
    sortData.m_size = 0;
    if ( sortData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        sortData.m_data,
        8 * sortData.m_capacityAndFlags);
    sortData.m_data = 0i64;
    sortData.m_capacityAndFlags = 0x80000000;
    uniqueVerts.m_size = 0;
    if ( uniqueVerts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        uniqueVerts.m_data,
        16 * uniqueVerts.m_capacityAndFlags);
    uniqueVerts.m_data = 0i64;
    uniqueVerts.m_capacityAndFlags = 0x80000000;
    sweepAabbs.m_size = 0;
    if ( sweepAabbs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        sweepAabbs.m_data,
        32 * sweepAabbs.m_capacityAndFlags);
    sweepAabbs.m_data = 0i64;
    sweepAabbs.m_capacityAndFlags = 0x80000000;
    triangleRemapOut.m_size = 0;
    if ( triangleRemapOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        triangleRemapOut.m_data,
        4 * triangleRemapOut.m_capacityAndFlags);
    triangleRemapOut.m_data = 0i64;
    triangleRemapOut.m_capacityAndFlags = 0x80000000;
    vertexRemapOut.m_size = 0;
    if ( vertexRemapOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        vertexRemapOut.m_data,
        4 * vertexRemapOut.m_capacityAndFlags);
    vertexRemapOut.m_data = 0i64;
    vertexRemapOut.m_capacityAndFlags = 0x80000000;
  }
  newTriangles.m_data = 0i64;
  newTriangles.m_size = 0;
  newTriangles.m_capacityAndFlags = 0x80000000;
  v94 = m_weldedGeometry->m_triangles.m_size;
  if ( v94 <= 0 )
  {
    v365.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v365, &hkContainerHeapAllocator::s_alloc, &newTriangles, v94, 16);
    if ( v365.m_enum )
    {
      hkErrStream::hkErrStream(&v417, v534, 512);
      hkOstream::operator<<(
        &v417,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v534, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 584);
      v95 = &v417;
LABEL_160:
      hkOstream::~hkOstream(v95);
      v96 = (hkVector4f *)v7->m_navMesh;
      if ( v96 )
      {
        v96[8] = (hkVector4f)aabbOut.m_quad;
        v96[9] = (hkVector4f)aabbOut.m_quad;
      }
      newTriangles.m_size = 0;
      if ( newTriangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          newTriangles.m_data,
          16 * newTriangles.m_capacityAndFlags);
      newTriangles.m_data = 0i64;
      newTriangles.m_capacityAndFlags = 0x80000000;
      v15 = 2;
      goto LABEL_172;
    }
  }
  hkGeometryUtils::removeDuplicateTrianglesFast(&v367, m_weldedGeometry, &newTriangles);
  if ( v367.m_enum )
  {
    hkErrStream::hkErrStream(&v445, v490, 512);
    hkOstream::operator<<(
      &v445,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v490, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 587);
    v95 = &v445;
    goto LABEL_160;
  }
  newTriangles.m_size = 0;
  if ( newTriangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newTriangles.m_data,
      16 * newTriangles.m_capacityAndFlags);
  newTriangles.m_data = 0i64;
  newTriangles.m_capacityAndFlags = 0x80000000;
  if ( !m_weldedGeometry->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v419, v514, 512);
    hkOstream::operator<<(&v419, "No triangles were contained in the input AABB.");
    hkError::messageWarning(1541620707, v514, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 592);
    hkOstream::~hkOstream(&v419);
    v97 = (hkVector4f *)v7->m_navMesh;
    if ( v97 )
    {
      v97[8] = (hkVector4f)aabbOut.m_quad;
      v97[9] = (hkVector4f)aabbOut.m_quad;
    }
    goto LABEL_172;
  }
  if ( !cb->vfptr->stepEndedCallback(cb, BEGIN, &cbCtx) )
  {
    v15 = 0;
LABEL_172:
    v98 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v99 = (_QWORD *)v98[1];
    if ( (unsigned __int64)v99 < v98[3] )
    {
      *v99 = "Et";
      v100 = __rdtsc();
      v101 = v99 + 2;
      *((_DWORD *)v101 - 2) = v100;
      v98[1] = v101;
    }
    v76 = v333;
    goto LABEL_523;
  }
  v102 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v103 = (_QWORD *)v102[1];
  if ( (unsigned __int64)v103 < v102[3] )
  {
    *v103 = "Et";
    v104 = __rdtsc();
    v105 = v103 + 2;
    *((_DWORD *)v105 - 2) = v104;
    v102[1] = v105;
  }
  v401.m_data.m_data = 0i64;
  v401.m_data.m_size = 0;
  v401.m_data.m_capacityAndFlags = 0x80000000;
  v401.m_m = 0;
  v399.m_data.m_data = 0i64;
  v399.m_data.m_size = 0;
  v399.m_data.m_capacityAndFlags = 0x80000000;
  v399.m_m = 0;
  v106 = m_weldedGeometry->m_triangles.m_size;
  m_cuttingTriangles = (hkBitField *)&v401;
  if ( v7->m_cuttingTriangles )
    m_cuttingTriangles = v7->m_cuttingTriangles;
  m_walkableTriangles = v7->m_walkableTriangles;
  v109 = (hkBitField *)&v399;
  cuttingTriangles = m_cuttingTriangles;
  if ( m_walkableTriangles )
    v109 = m_walkableTriangles;
  walkableInOut = v109;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    v109,
    (hkResult *)&v539,
    0,
    v106,
    1);
  if ( (_DWORD)v539 )
  {
    hkErrStream::hkErrStream(&v459, v492, 512);
    hkOstream::operator<<(
      &v459,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v492, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 608);
    v110 = &v459;
LABEL_185:
    hkOstream::~hkOstream(v110);
    v111 = (hkVector4f *)v7->m_navMesh;
    if ( v111 )
    {
      v111[8] = (hkVector4f)aabbOut.m_quad;
      v111[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_518;
  }
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    m_cuttingTriangles,
    (hkResult *)&v539,
    0,
    m_weldedGeometry->m_triangles.m_size,
    1);
  if ( (_DWORD)v539 )
  {
    hkErrStream::hkErrStream(&v421, v526, 512);
    hkOstream::operator<<(
      &v421,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v526, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 614);
    v110 = &v421;
    goto LABEL_185;
  }
  v112 = 0;
  if ( m_weldedGeometry->m_triangles.m_size > 0 )
  {
    v113 = cuttingTriangles;
    do
    {
      if ( !hkaiNavMeshGenerationUtils::isTriangleCutting(
              m_weldedGeometry,
              v112,
              input,
              (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v390) )
        v113->m_storage.m_words.m_data[(__int64)v112 >> 5] &= ~(1 << (v112 & 0x1F));
      ++v112;
    }
    while ( v112 < m_weldedGeometry->m_triangles.m_size );
    v7 = v540;
  }
  v114 = 0i64;
  v115 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v116 = (_QWORD *)v115[1];
  if ( (unsigned __int64)v116 < v115[3] )
  {
    *v116 = "TtbuildDynamicTree";
    v117 = __rdtsc();
    v118 = v116 + 2;
    *((_DWORD *)v118 - 2) = v117;
    v115[1] = v118;
  }
  if ( !cb->vfptr->stepStartedCallback(cb, END, &cbCtx) )
    goto LABEL_207;
  v119 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v120 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v119[11] + 8i64))(v119[11], 32i64);
  if ( v120 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v120);
    v114 = v121;
  }
  if ( !v114 )
  {
    hkErrStream::hkErrStream(&v447, v494, 512);
    hkOstream::operator<<(
      &v447,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v494, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 631);
    v122 = &v447;
LABEL_203:
    hkOstream::~hkOstream(v122);
    v123 = (hkVector4f *)v7->m_navMesh;
    if ( v123 )
    {
      v123[8] = (hkVector4f)aabbOut.m_quad;
      v123[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    goto LABEL_208;
  }
  hkaiNavMeshGenerationUtils::buildCuttingGeomTree(
    (hkResult *)&v539,
    (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v390,
    m_weldedGeometry,
    input,
    cuttingTriangles,
    v114);
  if ( (_DWORD)v539 )
  {
    hkErrStream::hkErrStream(&v423, v516, 512);
    hkOstream::operator<<(
      &v423,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v516, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 634);
    v122 = &v423;
    goto LABEL_203;
  }
  if ( !cb->vfptr->stepEndedCallback(cb, END, &cbCtx) )
  {
LABEL_207:
    v15 = 0;
LABEL_208:
    v124 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v125 = (_QWORD *)v124[1];
    if ( (unsigned __int64)v125 < v124[3] )
    {
      *v125 = "Et";
      v126 = __rdtsc();
      v127 = v125 + 2;
      *((_DWORD *)v127 - 2) = v126;
      v124[1] = v127;
    }
    goto LABEL_516;
  }
  v128 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v129 = (_QWORD *)v128[1];
  if ( (unsigned __int64)v129 < v128[3] )
  {
    *v129 = "Et";
    v130 = __rdtsc();
    v131 = v129 + 2;
    *((_DWORD *)v131 - 2) = v130;
    v128[1] = v131;
  }
  if ( !cb->vfptr->stepStartedCallback(cb, END|BEGIN, &cbCtx) )
  {
    v15 = 0;
    goto LABEL_516;
  }
  v132 = 0x80000000;
  triangleVertices.m_data = 0i64;
  triangleVertices.m_size = 0;
  triangleVertices.m_capacityAndFlags = 0x80000000;
  v327.m_data = 0i64;
  v327.m_size = 0;
  originalFaceIndices.m_capacityAndFlags = 0x80000000;
  hitFaces.m_capacityAndFlags = 0x80000000;
  v327.m_capacityAndFlags = 0x80000000;
  v334.m_data = 0i64;
  v334.m_size = 0;
  v334.m_capacityAndFlags = 0x80000000;
  v335.m_data = 0i64;
  v335.m_size = 0;
  v335.m_capacityAndFlags = 0x80000000;
  originalFaceIndices.m_data = 0i64;
  originalFaceIndices.m_size = 0;
  hitFaces.m_data = 0i64;
  hitFaces.m_size = 0;
  v133 = m_weldedGeometry->m_triangles.m_size;
  if ( v133 <= 0 )
  {
    v361.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v361, &hkContainerHeapAllocator::s_alloc, &v334, v133, 4);
    if ( v361.m_enum )
    {
      hkErrStream::hkErrStream(&v470, v496, 512);
      hkOstream::operator<<(
        &v470,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v496, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 649);
      v134 = &v470;
LABEL_224:
      hkOstream::~hkOstream(v134);
      v137 = (hkVector4f *)v7->m_navMesh;
      if ( v137 )
      {
        v137[8] = (hkVector4f)aabbOut.m_quad;
        v137[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_503;
    }
    v132 = originalFaceIndices.m_capacityAndFlags;
  }
  v135 = m_weldedGeometry->m_triangles.m_size + 1;
  v136 = v132 & 0x3FFFFFFF;
  if ( (v132 & 0x3FFFFFFF) >= v135 )
  {
    v364.m_enum = HK_SUCCESS;
  }
  else
  {
    if ( v135 < 2 * v136 )
      v135 = 2 * v136;
    hkArrayUtil::_reserve(&v364, &hkContainerHeapAllocator::s_alloc, &originalFaceIndices, v135, 4);
    if ( v364.m_enum )
    {
      hkErrStream::hkErrStream(&v425, v532, 512);
      hkOstream::operator<<(
        &v425,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v532, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 652);
      v134 = &v425;
      goto LABEL_224;
    }
    v132 = originalFaceIndices.m_capacityAndFlags;
  }
  if ( originalFaceIndices.m_size == (v132 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &originalFaceIndices, 4);
  originalFaceIndices.m_data[originalFaceIndices.m_size++] = -1;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::setForSingleTriangle(&geomA, &v388);
  if ( v388.m_enum )
  {
    hkErrStream::hkErrStream(&v449, v498, 512);
    hkOstream::operator<<(
      &v449,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v498, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 659);
    hkOstream::~hkOstream(&v449);
    v138 = (hkVector4f *)v7->m_navMesh;
    if ( v138 )
    {
      v138[8] = (hkVector4f)aabbOut.m_quad;
      v138[9] = (hkVector4f)aabbOut.m_quad;
    }
    v15 = 2;
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
    goto LABEL_503;
  }
  *(_DWORD *)&cuttingGeom.m_memSizeAndFlags = 0x1FFFF;
  cuttingGeom.m_vertices.m_data = 0i64;
  cuttingGeom.m_vertices.m_size = 0;
  cuttingGeom.m_vertices.m_capacityAndFlags = 0x80000000;
  cuttingGeom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  cuttingGeom.m_triangles.m_data = 0i64;
  cuttingGeom.m_triangles.m_size = 0;
  cuttingGeom.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomOut);
  hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&v473);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geom);
  hkaiBooleanOperation::hkaiBooleanOperation(&v476);
  hkaiGeometryExtrudeUtil::hkaiGeometryExtrudeUtil(&v475);
  faceEdges.m_faceEdges.m_data = 0i64;
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceEdges.m_capacityAndFlags = 0x80000000;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  faceEdges.m_faceStartEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  trisOut.m_data = 0i64;
  trisOut.m_size = 0;
  trisOut.m_capacityAndFlags = 0x80000000;
  triConnectivityOut.m_data = 0i64;
  triConnectivityOut.m_size = 0;
  triConnectivityOut.m_capacityAndFlags = 0x80000000;
  LODWORD(v539) = 0;
  v139 = _mm_shuffle_ps((__m128)LODWORD(input->m_characterHeight), (__m128)LODWORD(input->m_characterHeight), 0);
  characterHeight.m_real = v139;
  if ( m_weldedGeometry->m_triangles.m_size > 0 )
  {
    do
    {
      v140 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v141 = v140[1];
      if ( v141 < v140[3] )
      {
        *(_QWORD *)v141 = "Ltcsg";
        *(_QWORD *)(v141 + 16) = "Stwalkable";
        v142 = __rdtsc();
        *(_DWORD *)(v141 + 8) = v142;
        v140[1] = v141 + 24;
      }
      if ( !cb->vfptr->stepMiddleCallback(cb, END|BEGIN, (int)v539, m_weldedGeometry->m_triangles.m_size, &cbCtx) )
      {
        v148 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v149 = (_QWORD *)v148[1];
        if ( (unsigned __int64)v149 < v148[3] )
        {
          *v149 = "lt";
          v150 = __rdtsc();
          v151 = v149 + 2;
          *((_DWORD *)v151 - 2) = v150;
          v148[1] = v151;
        }
        v15 = 0;
        goto LABEL_333;
      }
      if ( !hkaiNavMeshGenerationUtils::isTriangleWalkable(
              m_weldedGeometry,
              (int)v539,
              input,
              carverTree,
              (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v390) )
        walkableInOut->m_storage.m_words.m_data[(__int64)(int)v539 >> 5] &= ~(1 << ((unsigned __int8)v539 & 0x1F));
      v143 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v144 = (_QWORD *)v143[1];
      if ( (unsigned __int64)v144 < v143[3] )
      {
        *v144 = "lt";
        v145 = __rdtsc();
        v146 = v144 + 2;
        *((_DWORD *)v146 - 2) = v145;
        v143[1] = v146;
      }
      LODWORD(v539) = (_DWORD)v539 + 1;
    }
    while ( (int)v539 < m_weldedGeometry->m_triangles.m_size );
  }
  if ( input->m_regionPruningSettings.m_pruneBeforeTriangulation.m_bool )
  {
    hkaiNavMeshGenerationUtils::_pruneTriangles((hkResult *)&v539, m_weldedGeometry, input, walkableInOut);
    if ( (_DWORD)v539 )
    {
      hkErrStream::hkErrStream(&v427, v518, 512);
      hkOstream::operator<<(
        &v427,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v518, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 695);
      hkOstream::~hkOstream(&v427);
      v147 = (hkVector4f *)v7->m_navMesh;
      if ( v147 )
      {
        v147[8] = (hkVector4f)aabbOut.m_quad;
        v147[9] = (hkVector4f)aabbOut.m_quad;
      }
      v15 = 2;
      goto LABEL_333;
    }
  }
  LODWORD(v539) = 0;
  if ( m_weldedGeometry->m_triangles.m_size <= 0 )
  {
LABEL_301:
    triConnectivityOut.m_size = 0;
    if ( triConnectivityOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        triConnectivityOut.m_data,
        4 * triConnectivityOut.m_capacityAndFlags);
    triConnectivityOut.m_data = 0i64;
    triConnectivityOut.m_capacityAndFlags = 0x80000000;
    trisOut.m_size = 0;
    if ( trisOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        trisOut.m_data,
        4 * trisOut.m_capacityAndFlags);
    trisOut.m_data = 0i64;
    trisOut.m_capacityAndFlags = 0x80000000;
    hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&faceEdges);
    hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v475);
    hkaiBooleanOperation::~hkaiBooleanOperation(&v476);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
    hkaiSelfIntersectBooleanFilter2::~hkaiSelfIntersectBooleanFilter2(&v473);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
    hkGeometry::~hkGeometry(&cuttingGeom);
    hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
    if ( !cb->vfptr->stepEndedCallback(cb, END|BEGIN, &cbCtx) )
    {
      v15 = 0;
      goto LABEL_503;
    }
    hkReferencedObject::removeReference(v114);
    v114 = 0i64;
    if ( !cb->vfptr->stepStartedCallback(cb, (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)4i64, &cbCtx) )
    {
      v15 = 0;
      goto LABEL_503;
    }
    v223 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v224 = (_QWORD *)v223[1];
    if ( (unsigned __int64)v224 < v223[3] )
    {
      *v224 = "TtWeldExact";
      v225 = __rdtsc();
      v226 = v224 + 2;
      *((_DWORD *)v226 - 2) = v225;
      v223[1] = v226;
    }
    remap.m_data = 0i64;
    remap.m_size = 0;
    remap.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshGenerationUtils::weldDuplicateVertices(
      (hkResult *)&v539,
      (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
      &remap);
    if ( (_DWORD)v539 )
    {
      hkErrStream::hkErrStream(&v468, v485, 512);
      hkOstream::operator<<(
        &v468,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v485, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 913);
      hkOstream::~hkOstream(&v468);
      v227 = (hkVector4f *)v7->m_navMesh;
      if ( v227 )
      {
        v227[8] = (hkVector4f)aabbOut.m_quad;
        v227[9] = (hkVector4f)aabbOut.m_quad;
      }
      remap.m_size = 0;
      if ( remap.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          remap.m_data,
          4 * remap.m_capacityAndFlags);
      remap.m_data = 0i64;
      remap.m_capacityAndFlags = 0x80000000;
      v228 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v229 = (_QWORD *)v228[1];
      if ( (unsigned __int64)v229 < v228[3] )
      {
        *v229 = "Et";
        v230 = __rdtsc();
        v231 = v229 + 2;
        *((_DWORD *)v231 - 2) = v230;
        v228[1] = v231;
      }
      v15 = 2;
      goto LABEL_503;
    }
    v232 = 0i64;
    if ( v327.m_size > 0 )
    {
      v233 = 0i64;
      do
      {
        v232 = (unsigned int)(v232 + 1);
        v234 = (int)v327.m_data[v233++];
        v327.m_data[v233 - 1] = remap.m_data[v234];
      }
      while ( (int)v232 < v327.m_size );
    }
    remap.m_size = 0;
    if ( remap.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        remap.m_data,
        (unsigned int)(4 * remap.m_capacityAndFlags),
        v232);
    remap.m_data = 0i64;
    remap.m_capacityAndFlags = 0x80000000;
    v235 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v236 = (_QWORD *)v235[1];
    if ( (unsigned __int64)v236 < v235[3] )
    {
      *v236 = "Et";
      v237 = __rdtsc();
      v238 = v236 + 2;
      *((_DWORD *)v238 - 2) = v237;
      v235[1] = v238;
    }
    if ( !cb->vfptr->stepEndedCallback(cb, (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)4i64, &cbCtx) )
    {
      v15 = 0;
      goto LABEL_503;
    }
    hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(&v477);
    v239 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v240 = (hkaiEdgeGeometryRaycaster *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v239[11] + 8i64))(
                                          v239[11],
                                          112i64);
    if ( v240 )
    {
      hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(v240);
      *(_QWORD *)&v328[0].m_enum = v241;
      if ( v241 )
      {
        if ( !cb->vfptr->stepStartedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)5i64,
                &cbCtx) )
        {
          v15 = 0;
LABEL_500:
          if ( *(_QWORD *)&v328[0].m_enum )
            hkReferencedObject::removeReference(*(hkReferencedObject **)&v328[0].m_enum);
          hkaiNavMeshSimplificationSnapshot::~hkaiNavMeshSimplificationSnapshot(&v477);
          goto LABEL_503;
        }
        if ( !edgeConnectionRayCaster )
        {
          v242 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v243 = (_QWORD *)v242[1];
          if ( (unsigned __int64)v243 < v242[3] )
          {
            *v243 = "TtbuildEdgeGeomRaycasters";
            v244 = __rdtsc();
            v245 = v243 + 2;
            *((_DWORD *)v245 - 2) = v244;
            v242[1] = v245;
          }
          hkaiEdgeGeometryRaycaster::init(
            *(hkaiEdgeGeometryRaycaster **)&v328[0].m_enum,
            &v369,
            m_weldedGeometry,
            &carvers,
            cuttingTriangles);
          if ( v369.m_enum )
          {
            hkErrStream::hkErrStream(&v409, v487, 512);
            hkOstream::operator<<(
              &v409,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, v487, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 935);
            v246 = &v409;
LABEL_368:
            hkOstream::~hkOstream(v246);
            v247 = (hkVector4f *)v7->m_navMesh;
            if ( v247 )
            {
              v247[8] = (hkVector4f)aabbOut.m_quad;
              v247[9] = (hkVector4f)aabbOut.m_quad;
            }
            v248 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v249 = (_QWORD *)v248[1];
            if ( (unsigned __int64)v249 < v248[3] )
            {
              *v249 = "Et";
              v250 = __rdtsc();
              v251 = v249 + 2;
              *((_DWORD *)v251 - 2) = v250;
              v248[1] = v251;
            }
LABEL_499:
            v15 = 2;
            goto LABEL_500;
          }
          edgeConnectionRayCaster = *(hkaiEdgeGeometryRaycaster **)&v328[0].m_enum;
          if ( input->m_simplificationSettings.m_saveInputSnapshot.m_bool )
            hkaiNavMeshSimplificationSnapshot::setRaycasterInformation(
              &v477,
              m_weldedGeometry,
              &carvers,
              cuttingTriangles);
          v252 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v253 = (_QWORD *)v252[1];
          if ( (unsigned __int64)v253 < v252[3] )
          {
            *v253 = "Et";
            v254 = __rdtsc();
            v255 = v253 + 2;
            *((_DWORD *)v255 - 2) = v254;
            v252[1] = v255;
          }
        }
        v256 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v257 = (_QWORD *)v256[1];
        if ( (unsigned __int64)v257 < v256[3] )
        {
          *v257 = "TtRemoveUnreachable";
          v258 = __rdtsc();
          v259 = v257 + 2;
          *((_DWORD *)v259 - 2) = v258;
          v256[1] = v259;
        }
        hkaiNavMeshGenerationUtils::_removeUnreachableTriangles(
          (hkResult *)&v539,
          input,
          *(hkaiEdgeGeometryRaycaster **)&v328[0].m_enum,
          0i64,
          carverTree,
          (hkArray<int,hkContainerHeapAllocator> *)&v334,
          (hkArray<int,hkContainerHeapAllocator> *)&v327,
          (hkArray<int,hkContainerHeapAllocator> *)&v335,
          (hkArray<int,hkContainerHeapAllocator> *)&v334,
          0i64,
          &originalFaceIndices,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
          &hitFaces,
          cb,
          &cbCtx);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v410, v489, 512);
          hkOstream::operator<<(
            &v410,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v489, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 952);
          v246 = &v410;
          goto LABEL_368;
        }
        edgeConnectionRayCaster->m_faceFlagMask.m_storage = 15;
        hitFaces.m_size = 0;
        if ( hitFaces.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            hitFaces.m_data,
            4 * hitFaces.m_capacityAndFlags);
        hitFaces.m_data = 0i64;
        hitFaces.m_capacityAndFlags = 0x80000000;
        v260 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v261 = (_QWORD *)v260[1];
        if ( (unsigned __int64)v261 < v260[3] )
        {
          *v261 = "Et";
          v262 = __rdtsc();
          v263 = v261 + 2;
          *((_DWORD *)v263 - 2) = v262;
          v260[1] = v263;
        }
        if ( !cb->vfptr->stepEndedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)5i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        v264 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v265 = (_QWORD *)v264[1];
        if ( (unsigned __int64)v265 < v264[3] )
        {
          *v265 = "TtcreateNavMesh";
          v266 = __rdtsc();
          v267 = v265 + 2;
          *((_DWORD *)v267 - 2) = v266;
          v264[1] = v267;
        }
        if ( !cb->vfptr->stepStartedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)6i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_493;
        }
        hkaiNavMeshGenerationUtils::_createNavMesh(
          &v371,
          (hkArray<hkVector4f,hkContainerHeapAllocator> *)&triangleVertices,
          (hkArray<int,hkContainerHeapAllocator> *)&v327,
          (hkArray<int,hkContainerHeapAllocator> *)&v334,
          (hkArray<int,hkContainerHeapAllocator> *)&v335,
          (hkArray<int,hkContainerHeapAllocator> *)&originalFaceIndices,
          m_weldedGeometry,
          carverTree,
          input,
          navMeshOut);
        if ( v371.m_enum )
        {
          hkErrStream::hkErrStream(&v412, v491, 512);
          hkOstream::operator<<(
            &v412,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v491, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 966);
          v268 = &v412;
LABEL_490:
          hkOstream::~hkOstream(v268);
          v300 = (hkVector4f *)v7->m_navMesh;
          if ( v300 )
          {
            v300[8] = (hkVector4f)aabbOut.m_quad;
            v300[9] = (hkVector4f)aabbOut.m_quad;
          }
          v15 = 2;
          goto LABEL_493;
        }
        v269 = navMeshOut;
        if ( navMeshOut->m_edges.m_size >= 0x400000 || navMeshOut->m_faces.m_size >= 0x400000 )
        {
          hkErrStream::hkErrStream(&v446, v525, 512);
          hkOstream::operator<<(
            &v446,
            "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to proc"
            "ess the mesh in pieces instead.");
          hkError::messageWarning(1349609975, v525, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 967);
          v268 = &v446;
          goto LABEL_490;
        }
        cbCtx.m_unsimplifiedNavMesh = navMeshOut;
        if ( v538 )
        {
          v270 = mesh;
          navMeshOut->m_flags.m_storage |= 1u;
          v270->m_flags.m_storage |= 1u;
        }
        if ( !cb->vfptr->stepEndedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)6i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_493;
        }
        triangleVertices.m_size = 0;
        if ( triangleVertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            triangleVertices.m_data,
            16 * triangleVertices.m_capacityAndFlags);
        triangleVertices.m_data = 0i64;
        triangleVertices.m_capacityAndFlags = 0x80000000;
        v327.m_size = 0;
        if ( v327.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v327.m_data,
            4 * v327.m_capacityAndFlags);
        v327.m_data = 0i64;
        v327.m_capacityAndFlags = 0x80000000;
        v334.m_size = 0;
        if ( v334.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v334.m_data,
            4 * v334.m_capacityAndFlags);
        v334.m_data = 0i64;
        v334.m_capacityAndFlags = 0x80000000;
        v335.m_size = 0;
        if ( v335.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v335.m_data,
            4 * v335.m_capacityAndFlags);
        v335.m_data = 0i64;
        v335.m_capacityAndFlags = 0x80000000;
        originalFaceIndices.m_size = 0;
        if ( originalFaceIndices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            originalFaceIndices.m_data,
            4 * originalFaceIndices.m_capacityAndFlags);
        originalFaceIndices.m_data = 0i64;
        originalFaceIndices.m_capacityAndFlags = 0x80000000;
        v271 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v272 = (_QWORD *)v271[1];
        if ( (unsigned __int64)v272 < v271[3] )
        {
          *v272 = "Et";
          v273 = __rdtsc();
          v274 = v272 + 2;
          *((_DWORD *)v274 - 2) = v273;
          v271[1] = v274;
        }
        if ( !v269->m_faces.m_size || !v269->m_edges.m_size )
        {
          hkErrStream::hkErrStream(&v444, v523, 512);
          hkOstream::operator<<(
            &v444,
            "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was conta"
            "ined in carvers.");
          hkError::messageWarning(1541620706, v523, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 987);
          v286 = &v444;
LABEL_447:
          hkOstream::~hkOstream(v286);
          v287 = (hkVector4f *)v7->m_navMesh;
          if ( v287 )
          {
            v287[8] = (hkVector4f)aabbOut.m_quad;
            v287[9] = (hkVector4f)aabbOut.m_quad;
          }
          goto LABEL_500;
        }
        if ( !cb->vfptr->stepStartedCallback(cb, END|BEGIN|0x4, &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        hkaiEdgeGeometryRaycaster::setupForEdgeConnections(edgeConnectionRayCaster);
        v275 = 0;
        LODWORD(v539) = input->m_edgeConnectionIterations + 1;
        if ( (int)v539 > 0 )
        {
          while ( 1 )
          {
            v276 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v277 = (_QWORD *)v276[1];
            if ( (unsigned __int64)v277 < v276[3] )
            {
              *v277 = "TtconnectEdges";
              v278 = __rdtsc();
              v279 = v277 + 2;
              *((_DWORD *)v279 - 2) = v278;
              v276[1] = v279;
            }
            hkaiNavMeshGenerationUtils::_connectEdges(
              &v378,
              input,
              navMeshOut,
              edgeConnectionRayCaster,
              v275,
              cb,
              &cbCtx);
            if ( v378.m_enum )
              break;
            if ( navMeshOut->m_edges.m_size >= 0x400000 || navMeshOut->m_faces.m_size >= 0x400000 )
            {
              hkErrStream::hkErrStream(&v414, v493, 512);
              hkOstream::operator<<(
                &v414,
                "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to "
                "process the mesh in pieces instead.");
              hkError::messageWarning(1349609975, v493, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1018);
              v246 = &v414;
              goto LABEL_368;
            }
            v280 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v281 = (_QWORD *)v280[1];
            if ( (unsigned __int64)v281 < v280[3] )
            {
              *v281 = "Et";
              v282 = __rdtsc();
              v283 = v281 + 2;
              *((_DWORD *)v283 - 2) = v282;
              v280[1] = v283;
            }
            if ( ++v275 >= (int)v539 )
              goto LABEL_423;
          }
          hkErrStream::hkErrStream(&v416, v495, 512);
          hkOstream::operator<<(
            &v416,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v495, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1017);
          v246 = &v416;
          goto LABEL_368;
        }
LABEL_423:
        if ( !cb->vfptr->stepEndedCallback(cb, END|BEGIN|0x4, &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        v284 = navMeshOut;
        hkaiNavMeshUtils::validate(navMeshOut, 0);
        if ( !cb->vfptr->stepStartedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)8i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        hkaiNavMeshUtils::compactVertices(&v366, v284, 0, 0);
        if ( v366.m_enum )
        {
          hkErrStream::hkErrStream(&v418, v497, 512);
          hkOstream::operator<<(
            &v418,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v497, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1047);
          v285 = &v418;
          goto LABEL_497;
        }
        hkaiNavMeshGenerationUtils::_mergeVertices((hkResult *)&v539, v284, 0.00039999999);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v420, v499, 512);
          hkOstream::operator<<(
            &v420,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v499, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1062);
          v285 = &v420;
          goto LABEL_497;
        }
        hkaiNavMeshGenerationUtils::_removeDegenerateFaces((hkResult *)&v539, v284);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v422, v501, 512);
          hkOstream::operator<<(
            &v422,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v501, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1074);
          v285 = &v422;
          goto LABEL_497;
        }
        hkaiNavMeshUtils::validate(v284, 0);
        if ( !cb->vfptr->stepEndedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)8i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        if ( !cb->vfptr->stepStartedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)9i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        hkaiNavMeshGenerationUtils::_pruneRegions(
          (hkResult *)&v539,
          v284,
          &input->m_up,
          &input->m_regionPruningSettings);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v424, v503, 512);
          hkOstream::operator<<(
            &v424,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v503, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1098);
          v285 = &v424;
          goto LABEL_497;
        }
        hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(
          (hkResult *)&v539,
          v284,
          input,
          *(hkaiEdgeGeometryRaycaster **)&v328[0].m_enum,
          cb);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v426, v505, 512);
          hkOstream::operator<<(
            &v426,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v505, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1109);
          v285 = &v426;
          goto LABEL_497;
        }
        if ( !cb->vfptr->stepEndedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)9i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        if ( !v284->m_faces.m_size )
        {
          hkErrStream::hkErrStream(&v428, v507, 512);
          hkOstream::operator<<(&v428, "Erosion removed all faces from the nav mesh.");
          hkError::messageWarning(1209185063, v507, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1115);
          v286 = &v428;
          goto LABEL_447;
        }
        if ( !cb->vfptr->stepStartedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)10i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        hkaiNavMeshGenerationUtils::_pruneRegions(
          (hkResult *)&v539,
          v284,
          &input->m_up,
          &input->m_regionPruningSettings);
        if ( (_DWORD)v539 )
        {
          hkErrStream::hkErrStream(&v430, v509, 512);
          hkOstream::operator<<(
            &v430,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v509, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1134);
          v285 = &v430;
          goto LABEL_497;
        }
        hkaiNavMeshUtils::compactVertices(&v380, v284, 0, 0);
        if ( v380.m_enum )
        {
          hkErrStream::hkErrStream(&v432, v511, 512);
          hkOstream::operator<<(
            &v432,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v511, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1148);
          v285 = &v432;
          goto LABEL_497;
        }
        hkAabbUtil::calcAabb(v284->m_vertices.m_data, v284->m_vertices.m_size, &v284->m_aabb);
        v288 = _mm_shuffle_ps((__m128)LODWORD(input->m_characterHeight), (__m128)LODWORD(input->m_characterHeight), 0);
        v284->m_aabb.m_max.m_quad = _mm_add_ps(v288, v284->m_aabb.m_max.m_quad);
        v284->m_aabb.m_min.m_quad = _mm_sub_ps(v284->m_aabb.m_min.m_quad, v288);
        if ( !cb->vfptr->stepEndedCallback(
                cb,
                (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)10i64,
                &cbCtx) )
        {
          v15 = 0;
          goto LABEL_500;
        }
        if ( input->m_enableSimplification.m_bool )
        {
          hkaiNavMesh::setEdgeDataStriding(v284, &v360, 1, 0);
          if ( v360.m_enum )
          {
            hkErrStream::hkErrStream(&v434, v513, 512);
            hkOstream::operator<<(
              &v434,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, v513, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1177);
            v285 = &v434;
            goto LABEL_497;
          }
          v289 = mesh;
          v360.m_enum = hkaiNavMesh::setEdgeDataStriding(mesh, &v397, 1, 0)->m_enum;
          if ( v360.m_enum )
          {
            hkErrStream::hkErrStream(&v436, v515, 512);
            hkOstream::operator<<(
              &v436,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, v515, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1179);
            v285 = &v436;
            goto LABEL_497;
          }
          hkaiNavMeshUtils::validate(v284, 0);
          m_unsimplifiedNavMesh = v7->m_unsimplifiedNavMesh;
          if ( m_unsimplifiedNavMesh )
          {
            hkaiNavMesh::copy(m_unsimplifiedNavMesh, &v382, v284);
            if ( v382.m_enum )
            {
              hkErrStream::hkErrStream(&v438, v517, 512);
              hkOstream::operator<<(
                &v438,
                "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation"
                " chapter in the User Guide.");
              hkError::messageWarning(1549811857, v517, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1188);
              v285 = &v438;
              goto LABEL_497;
            }
          }
          v291 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v292 = (_QWORD *)v291[1];
          if ( (unsigned __int64)v292 < v291[3] )
          {
            *v292 = "Ttsimplify";
            v293 = __rdtsc();
            v294 = v292 + 2;
            *((_DWORD *)v294 - 2) = v293;
            v291[1] = v294;
          }
          if ( input->m_simplificationSettings.m_saveInputSnapshot.m_bool )
          {
            hkaiNavMeshSimplificationSnapshot::setMeshAndSettings(&v477, v284, input);
            hkaiNavMeshSimplificationSnapshot::save(&v477);
          }
          v295 = hkaiNavMeshSimplificationUtils::_simplifyNavMesh(
                   input,
                   v284,
                   v289,
                   *(hkaiEdgeGeometryRaycaster **)&v328[0].m_enum,
                   cb);
          if ( v295 != 2 )
            hkaiNavMesh::clear(v289);
          if ( v295 == 1 )
          {
            hkErrStream::hkErrStream(&v440, v519, 512);
            hkOstream::operator<<(
              &v440,
              "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation c"
              "hapter in the User Guide.");
            hkError::messageWarning(1549811857, v519, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1210);
            v268 = &v440;
            goto LABEL_490;
          }
          if ( !v295 )
          {
            v15 = 0;
LABEL_493:
            v301 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v302 = (_QWORD *)v301[1];
            if ( (unsigned __int64)v302 < v301[3] )
            {
              *v302 = "Et";
              v303 = __rdtsc();
              v304 = v302 + 2;
              *((_DWORD *)v304 - 2) = v303;
              v301[1] = v304;
            }
            goto LABEL_500;
          }
          cbCtx.m_simplifiedNavMesh = v289;
          v296 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v297 = (_QWORD *)v296[1];
          if ( (unsigned __int64)v297 < v296[3] )
          {
            *v297 = "Et";
            v298 = __rdtsc();
            v299 = v297 + 2;
            *((_DWORD *)v299 - 2) = v298;
            v296[1] = v299;
          }
        }
        else
        {
          v289 = mesh;
        }
        if ( input->m_setBestFaceCenters.m_bool && !input->m_wallClimbingSettings.m_enableWallClimbing.m_bool )
          hkaiNavMeshUtils::setBestFaceCenters(v289, &input->m_up);
        hkaiNavMesh::setEdgeDataStriding(v289, &v386, newStride, 0);
        if ( v386.m_enum == HK_SUCCESS )
        {
          hkaiNavMeshUtils::validate(v289, 1);
          if ( cb->vfptr->stepStartedCallback(
                 cb,
                 (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)21i64,
                 &cbCtx) )
          {
            if ( cb->vfptr->stepEndedCallback(
                   cb,
                   (hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep)21i64,
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
          goto LABEL_500;
        }
        hkErrStream::hkErrStream(&v442, v521, 512);
        hkOstream::operator<<(
          &v442,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v521, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 1232);
        v285 = &v442;
        goto LABEL_497;
      }
    }
    else
    {
      *(_QWORD *)&v328[0].m_enum = 0i64;
    }
    hkErrStream::hkErrStream(&v448, v527, 512);
    hkOstream::operator<<(
      &v448,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v527, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 927);
    v285 = &v448;
LABEL_497:
    hkOstream::~hkOstream(v285);
    v305 = (hkVector4f *)v7->m_navMesh;
    if ( v305 )
    {
      v305[8] = (hkVector4f)aabbOut.m_quad;
      v305[9] = (hkVector4f)aabbOut.m_quad;
    }
    goto LABEL_499;
  }
  while ( 1 )
  {
    v152 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v153 = v152[1];
    if ( v153 < v152[3] )
    {
      *(_QWORD *)v153 = "Ltcsg";
      *(_QWORD *)(v153 + 16) = "Stwalkable";
      v154 = __rdtsc();
      *(_DWORD *)(v153 + 8) = v154;
      v152[1] = v153 + 24;
    }
    if ( !cb->vfptr->stepMiddleCallback(cb, END|BEGIN, (int)v539, m_weldedGeometry->m_triangles.m_size, &cbCtx) )
    {
      v15 = 0;
      goto LABEL_331;
    }
    if ( ((walkableInOut->m_storage.m_words.m_data[(__int64)(int)v539 >> 5] >> ((unsigned __int8)v539 & 0x1F)) & 1) == 0 )
      goto LABEL_298;
    hkGeometry::clear(&cuttingGeom);
    hkaiEdgeGeometry::clear(&cuttingEdgeGeometryOut);
    hkaiEdgeGeometry::clear(&geomOut);
    hkaiSelfIntersectBooleanFilter2::reset(&v473);
    hkaiEdgeGeometry::clear(&geom);
    hkaiBooleanOperation::clear(&v476);
    trisOut.m_size = 0;
    triConnectivityOut.m_size = 0;
    hkaiNavMeshGenerationUtils::getTriangleVerts(m_weldedGeometry, input, (int)v539, &vertsOut);
    if ( v538 )
    {
      v155 = _mm_sub_ps(v403, vertsOut.m_quad);
      v156 = _mm_sub_ps(v404, vertsOut.m_quad);
      v157 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v156, v156, 201), v155),
               _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v156));
      v158 = _mm_shuffle_ps(v157, v157, 201);
      v159 = _mm_mul_ps(v158, v158);
      v160 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0)),
               _mm_shuffle_ps(v159, v159, 170));
      v161 = _mm_rsqrt_ps(v160);
      v474 = v160;
      v162 = _mm_mul_ps(
               _mm_xor_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmple_ps(v160, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v161, v160), v161)),
                       _mm_mul_ps(*(__m128 *)_xmm, v161))),
                   v158),
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64)),
               v139);
    }
    else
    {
      v162 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v139), input->m_up.m_quad);
    }
    extrudeDirection.m_quad = v162;
    v163 = (_DWORD)v539 + 1;
    geomA.m_faces.m_data[1].m_faceIndex = (_DWORD)v539 + 1;
    v340 = v163;
    v164 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v162);
    rayDir.m_quad = v164;
    *geomA.m_vertices.m_data = (hkVector4f)vertsOut.m_quad;
    geomA.m_vertices.m_data[1].m_quad = v403;
    geomA.m_vertices.m_data[2].m_quad = v404;
    v165 = _mm_max_ps(_mm_max_ps(vertsOut.m_quad, v403), v404);
    v166 = _mm_min_ps(_mm_min_ps(vertsOut.m_quad, v403), v404);
    extrudedTriAabb.m_max.m_quad = _mm_max_ps(v165, _mm_add_ps(v165, v164));
    extrudedTriAabb.m_min.m_quad = _mm_min_ps(v166, _mm_add_ps(v166, v164));
    v167 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v168 = (_QWORD *)v167[1];
    if ( (unsigned __int64)v168 < v167[3] )
    {
      *v168 = "StgetNearbyCuttingGeometry";
      v169 = __rdtsc();
      v170 = v168 + 2;
      *((_DWORD *)v170 - 2) = v169;
      v167[1] = v170;
    }
    hkaiNavMeshGenerationUtils::getNearbyCuttingGeometry(
      &v329,
      &extrudedTriAabb,
      m_weldedGeometry,
      (int)v539,
      input,
      v114,
      &cuttingGeom,
      &cuttingEdgeGeometryOut);
    if ( v329.m_enum )
    {
      hkErrStream::hkErrStream(&v439, v483, 512);
      hkOstream::operator<<(
        &v439,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v483, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 761);
      v212 = &v439;
      goto LABEL_327;
    }
    v171 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v172 = (_QWORD *)v171[1];
    if ( (unsigned __int64)v172 < v171[3] )
    {
      *v172 = "Stextrude";
      v173 = __rdtsc();
      v174 = v172 + 2;
      *((_DWORD *)v174 - 2) = v173;
      v171[1] = v174;
    }
    hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(&v475, &v373, &cuttingEdgeGeometryOut, &extrudeDirection, &geomOut);
    if ( v373.m_enum )
    {
      hkErrStream::hkErrStream(&v455, v481, 512);
      hkOstream::operator<<(
        &v455,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v481, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 776);
      v212 = &v455;
      goto LABEL_327;
    }
    hkaiGeometryCarverExtractor::addCarversInRegion(&v368, &geomOut, carverTree, &extrudedTriAabb);
    if ( v368.m_enum )
    {
      hkErrStream::hkErrStream(&v437, v479, 512);
      hkOstream::operator<<(
        &v437,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v479, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 798);
      v212 = &v437;
      goto LABEL_327;
    }
    v175 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v176 = (_QWORD *)v175[1];
    if ( (unsigned __int64)v176 < v175[3] )
    {
      *v176 = "Stsubtract";
      v177 = __rdtsc();
      v178 = v176 + 2;
      *((_DWORD *)v178 - 2) = v177;
      v175[1] = v178;
    }
    v179 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v180 = (_QWORD *)v179[1];
    if ( (unsigned __int64)v180 < v179[3] )
    {
      *v180 = "TtsetFilter";
      v181 = __rdtsc();
      v182 = v180 + 2;
      *((_DWORD *)v182 - 2) = v181;
      v179[1] = v182;
    }
    hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&v473, &v372, &geomA, &geomOut);
    if ( v372.m_enum )
    {
      hkErrStream::hkErrStream(&v463, v508, 512);
      hkOstream::operator<<(
        &v463,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v508, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 814);
      hkOstream::~hkOstream(&v463);
      v213 = (hkVector4f *)v7->m_navMesh;
      if ( v213 )
      {
        v213[8] = (hkVector4f)aabbOut.m_quad;
        v213[9] = (hkVector4f)aabbOut.m_quad;
      }
      v214 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v215 = (_QWORD *)v214[1];
      if ( (unsigned __int64)v215 < v214[3] )
      {
        *v215 = "Et";
        v216 = __rdtsc();
        v15 = 2;
        v217 = v215 + 2;
        *((_DWORD *)v217 - 2) = v216;
        v214[1] = v217;
        goto LABEL_331;
      }
      goto LABEL_329;
    }
    v183 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v184 = (_QWORD *)v183[1];
    if ( (unsigned __int64)v184 < v183[3] )
    {
      *v184 = "Et";
      v185 = __rdtsc();
      v186 = v184 + 2;
      *((_DWORD *)v186 - 2) = v185;
      v183[1] = v186;
    }
    hkaiBooleanOperation::subtract(&v476, &v370, &geomA, &geomOut, &geom, 0i64, &v473);
    if ( v370.m_enum )
    {
      hkErrStream::hkErrStream(&v435, v522, 512);
      hkOstream::operator<<(
        &v435,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v522, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 818);
      v212 = &v435;
LABEL_327:
      hkOstream::~hkOstream(v212);
      v218 = (hkVector4f *)v7->m_navMesh;
      if ( v218 )
      {
        v218[8] = (hkVector4f)aabbOut.m_quad;
        v218[9] = (hkVector4f)aabbOut.m_quad;
      }
LABEL_329:
      v15 = 2;
      goto LABEL_331;
    }
    if ( input->m_checkEdgeGeometryConsistency.m_bool )
    {
      v187 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v188 = (_QWORD *)v187[1];
      if ( (unsigned __int64)v188 < v187[3] )
      {
        *v188 = "TtcheckConsistency";
        v189 = __rdtsc();
        v190 = v188 + 2;
        *((_DWORD *)v190 - 2) = v189;
        v187[1] = v190;
      }
      v191 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v192 = (_QWORD *)v191[1];
      if ( (unsigned __int64)v192 < v191[3] )
      {
        *v192 = "Et";
        v193 = __rdtsc();
        v194 = v192 + 2;
        *((_DWORD *)v194 - 2) = v193;
        v191[1] = v194;
      }
    }
    v195 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v196 = (_QWORD *)v195[1];
    if ( (unsigned __int64)v196 < v195[3] )
    {
      *v196 = "Sttriangulate";
      v197 = __rdtsc();
      v198 = v196 + 2;
      *((_DWORD *)v198 - 2) = v197;
      v195[1] = v198;
    }
    trisPerFaceOut.m_data = (int *)&v349;
    trisPerFaceOut.m_size = 0;
    trisPerFaceOut.m_capacityAndFlags = -2147483646;
    hkaiNavMeshGenerationUtils::_triangulate(
      &v376,
      input,
      &geom,
      &faceEdges,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      0i64,
      v538);
    if ( v376.m_enum )
      break;
    hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
      &v381,
      &geom.m_vertices,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      0i64,
      input);
    if ( v381.m_enum )
    {
      hkErrStream::hkErrStream(&v408, v536, 512);
      hkOstream::operator<<(
        &v408,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v536, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 844);
      v210 = &v408;
      goto LABEL_314;
    }
    v377 = triangleVertices.m_size;
    hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v375,
      (hkResult *)&triangleVertices,
      (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(triangleVertices.m_size
                                                                          + geom.m_vertices.m_size),
      -1,
      sizeElem);
    if ( v375 )
    {
      hkErrStream::hkErrStream(&v467, v504, 512);
      hkOstream::operator<<(
        &v467,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v504, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 867);
      v210 = &v467;
      goto LABEL_314;
    }
    hkArrayBase<hkVector4f>::_append(
      &triangleVertices,
      &hkContainerHeapAllocator::s_alloc,
      geom.m_vertices.m_data,
      geom.m_vertices.m_size);
    v325 = v327.m_size;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v385,
      (hkResult *)&v327,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v327.m_size + trisOut.m_size),
      -1,
      sizeElema);
    if ( v385 )
    {
      hkErrStream::hkErrStream(&v431, v520, 512);
      hkOstream::operator<<(
        &v431,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v520, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 872);
      v210 = &v431;
      goto LABEL_314;
    }
    hkArrayBase<unsigned int>::_append(
      &v327,
      &hkContainerHeapAllocator::s_alloc,
      (const unsigned int *)trisOut.m_data,
      trisOut.m_size);
    v199 = 0;
    if ( trisOut.m_size > 0 )
    {
      v200 = v377;
      v201 = v325;
      do
      {
        ++v199;
        v327.m_data[v201++] += v200;
      }
      while ( v199 < trisOut.m_size );
    }
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v383,
      (hkResult *)&v335,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v335.m_size + triConnectivityOut.m_size),
      -1,
      sizeElemb);
    if ( v383 )
    {
      hkErrStream::hkErrStream(&v451, v502, 512);
      hkOstream::operator<<(
        &v451,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v502, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 880);
      v210 = &v451;
      goto LABEL_314;
    }
    hkArrayBase<unsigned int>::_append(
      &v335,
      &hkContainerHeapAllocator::s_alloc,
      (const unsigned int *)triConnectivityOut.m_data,
      triConnectivityOut.m_size);
    hkArrayBase<unsigned int>::_append(
      &v334,
      &hkContainerHeapAllocator::s_alloc,
      (const unsigned int *)trisPerFaceOut.m_data,
      trisPerFaceOut.m_size);
    v202 = 0;
    if ( trisPerFaceOut.m_size > 0 )
    {
      v203 = originalFaceIndices.m_size;
      v204 = v340;
      do
      {
        ++v202;
        originalFaceIndices.m_data[v203] = v204;
        v203 = ++originalFaceIndices.m_size;
      }
      while ( v202 < trisPerFaceOut.m_size );
    }
    v340 = trisOut.m_size / 3;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v387,
      (hkResult *)&hitFaces,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(trisOut.m_size / 3 + hitFaces.m_size),
      -1,
      sizeElemc);
    if ( v387 )
    {
      hkErrStream::hkErrStream(&v429, v528, 512);
      hkOstream::operator<<(
        &v429,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v528, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 892);
      v210 = &v429;
      goto LABEL_314;
    }
    v205 = hitFaces.m_size;
    hitFaces.m_size += v340;
    hkaiNavMeshGenerationUtils::raycastAgainstCuttingGeometry(
      v328,
      (int)v539,
      &geom.m_vertices,
      &trisOut,
      &hitFaces.m_data[v205],
      &cuttingGeom,
      &characterHeight,
      &rayDir);
    if ( v328[0].m_enum )
    {
      hkErrStream::hkErrStream(&v461, v500, 512);
      hkOstream::operator<<(
        &v461,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v500, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 896);
      v210 = &v461;
      goto LABEL_314;
    }
    trisPerFaceOut.m_size = 0;
    if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        trisPerFaceOut.m_data,
        4 * trisPerFaceOut.m_capacityAndFlags);
    trisPerFaceOut.m_data = 0i64;
    trisPerFaceOut.m_capacityAndFlags = 0x80000000;
LABEL_298:
    v206 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v207 = (_QWORD *)v206[1];
    if ( (unsigned __int64)v207 < v206[3] )
    {
      *v207 = "lt";
      v208 = __rdtsc();
      v209 = v207 + 2;
      *((_DWORD *)v209 - 2) = v208;
      v206[1] = v209;
    }
    LODWORD(v539) = (_DWORD)v539 + 1;
    if ( (int)v539 >= m_weldedGeometry->m_triangles.m_size )
      goto LABEL_301;
  }
  hkErrStream::hkErrStream(&v453, v478, 512);
  hkOstream::operator<<(
    &v453,
    "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter in the User Guide.");
  hkError::messageWarning(1549811857, v478, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 840);
  v210 = &v453;
LABEL_314:
  hkOstream::~hkOstream(v210);
  v211 = (hkVector4f *)v7->m_navMesh;
  if ( v211 )
  {
    v211[8] = (hkVector4f)aabbOut.m_quad;
    v211[9] = (hkVector4f)aabbOut.m_quad;
  }
  v15 = 2;
  trisPerFaceOut.m_size = 0;
  if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      trisPerFaceOut.m_data,
      4 * trisPerFaceOut.m_capacityAndFlags);
  trisPerFaceOut.m_data = 0i64;
  trisPerFaceOut.m_capacityAndFlags = 0x80000000;
LABEL_331:
  v219 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v220 = (_QWORD *)v219[1];
  if ( (unsigned __int64)v220 < v219[3] )
  {
    *v220 = "lt";
    v221 = __rdtsc();
    v222 = v220 + 2;
    *((_DWORD *)v222 - 2) = v221;
    v219[1] = v222;
  }
LABEL_333:
  triConnectivityOut.m_size = 0;
  if ( triConnectivityOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triConnectivityOut.m_data,
      4 * triConnectivityOut.m_capacityAndFlags);
  triConnectivityOut.m_data = 0i64;
  triConnectivityOut.m_capacityAndFlags = 0x80000000;
  trisOut.m_size = 0;
  if ( trisOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      trisOut.m_data,
      4 * trisOut.m_capacityAndFlags);
  trisOut.m_data = 0i64;
  trisOut.m_capacityAndFlags = 0x80000000;
  hkaiUniqueEdges::~hkaiUniqueEdges((hkaiUniqueEdges *)&faceEdges);
  hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v475);
  hkaiBooleanOperation::~hkaiBooleanOperation(&v476);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
  hkaiSelfIntersectBooleanFilter2::~hkaiSelfIntersectBooleanFilter2(&v473);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&cuttingEdgeGeometryOut);
  hkGeometry::~hkGeometry(&cuttingGeom);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
LABEL_503:
  hitFaces.m_size = 0;
  if ( hitFaces.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      hitFaces.m_data,
      4 * hitFaces.m_capacityAndFlags);
  hitFaces.m_data = 0i64;
  hitFaces.m_capacityAndFlags = 0x80000000;
  originalFaceIndices.m_size = 0;
  if ( originalFaceIndices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      originalFaceIndices.m_data,
      4 * originalFaceIndices.m_capacityAndFlags);
  originalFaceIndices.m_data = 0i64;
  originalFaceIndices.m_capacityAndFlags = 0x80000000;
  v335.m_size = 0;
  if ( v335.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v335.m_data,
      4 * v335.m_capacityAndFlags);
  v335.m_data = 0i64;
  v335.m_capacityAndFlags = 0x80000000;
  v334.m_size = 0;
  if ( v334.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v334.m_data,
      4 * v334.m_capacityAndFlags);
  v334.m_data = 0i64;
  v334.m_capacityAndFlags = 0x80000000;
  v327.m_size = 0;
  if ( v327.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v327.m_data,
      4 * v327.m_capacityAndFlags);
  v327.m_data = 0i64;
  v327.m_capacityAndFlags = 0x80000000;
  triangleVertices.m_size = 0;
  if ( triangleVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triangleVertices.m_data,
      16 * triangleVertices.m_capacityAndFlags);
  triangleVertices.m_data = 0i64;
  triangleVertices.m_capacityAndFlags = 0x80000000;
LABEL_516:
  if ( v114 )
    hkReferencedObject::removeReference(v114);
LABEL_518:
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v399);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v401);
  v76 = v333;
LABEL_523:
  if ( v76 )
    hkReferencedObject::removeReference(v76);
  hkReferencedObject::removeReference(carverTree);
LABEL_530:
  v308 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v309 = &carvers.m_data[v308];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor(v309--);
      --v308;
    }
    while ( v308 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 0x80000000;
  hkPointerMap<int,int,hkContainerHeapAllocator>::~hkPointerMap<int,int,hkContainerHeapAllocator>((hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v390);
LABEL_536:
  v351 = 0;
  if ( v352 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v352 & 0x3FFFFFFF);
  array = 0i64;
  v352 = 0x80000000;
LABEL_540:
  v389 = &hkaiNavMeshGenerationProgressCallback::`vftable;
  hkReferencedObject::removeReference(v396);
  hkReferencedObject::removeReference(v398);
LABEL_547:
  v312 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v313 = (_QWORD *)v312[1];
  v314 = v312;
  if ( (unsigned __int64)v313 < v312[3] )
  {
    *v313 = "Et";
    v315 = __rdtsc();
    v316 = v313 + 2;
    *((_DWORD *)v316 - 2) = v315;
    v314[1] = v316;
  }
  return v15;
};
  originalFaceIndices.m_data = 0i64;
  originalFaceIndices.m_capacityAndFlags = 0x80000000;
  v335.m_size = 0;
  if ( v335.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v335.m_data,
      4 * v335.m_capacityAndFlags);
  v335.m_data = 0i64;
  v335.m_capacityAndFlags = 0x80000000;
  v334.m_size = 0;
  if ( v334.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v334.m_data,
      4 * v334.m_capacityAndFlags);
  v334.m_data = 0i64;
  v334.m_capacityAndFlags = 0x80000000;
  v327.m_size = 0;
  if ( v327.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v327.m_data,
      4 * v327.m_capacityAndFlags);
  v327.m_data = 0i64;
  v327.m_capacityAndFlags = 0x80000000;
  triangleVertices.m_size = 0;
  if ( triangleVertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triangleVertices.m_data,
      16 * triangleVertices.m_capacityAndFlags);
  triangleVertices.m_data = 0i64;
  triangleVertices.m_capacityAndFlags = 0x80000000;
LABEL_516:
  if ( v114 )
    hkReferencedObject::removeReference(v114);
LABEL_518:
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v399);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v401);
  v76 = v333;
LABEL_523:
  if ( v76 )
    hkReferencedObject::removeReference(v76);
  hkReferencedObject::removeReference(carverTree);
LABEL_530:
  v308 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v309 = &carvers.m_data[v308];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor(v309--);
      --v308;
    }
    while ( v308 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 0x80000000;
  hkPointerMap<int,int,hkContainerHeapAllocator>::~hkPointerMap<int,int,hkContainerHeapAllocator>((hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v390);
LABEL_536:
  v351 = 0;
  if ( v352 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v352 & 0x3FFFFFFF);
  array = 0i64;
  v352 = 0x80000000;
LABEL_540:
  v389 = &hkaiNavMeshGenerationProgressCallback::`vftable;
  hkReferencedObject::removeReference(v396);
  hkReferencedObject::removeReference(v398);
LABEL_547:
  v312 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v313 = (_QWORD *)v312[1];
  v314 = v312;
  if ( (unsigned __int64)v313 < v312[3] )
  {
    *v313 = "Et";
    v315 = __rdtsc();
    v316 = v313 + 2;
    *((_DWORD *)v316 - 2) = v315;
   

// File Line: 1244
// RVA: 0xB77920
void __fastcall hkaiNavMeshGenerationUtils::getTriangleVerts(
        hkGeometry *triMeshIn,
        hkaiNavMeshGenerationSettings *settings,
        int t,
        hkVector4f *vertsOut)
{
  hkVector4f *m_data; // rdx
  hkGeometry::Triangle *v5; // r8
  __int64 m_b; // rax
  hkVector4f v7; // xmm0
  __int64 m_c; // rax

  m_data = triMeshIn->m_vertices.m_data;
  v5 = &triMeshIn->m_triangles.m_data[t];
  m_b = v5->m_b;
  *vertsOut = m_data[v5->m_a];
  v7.m_quad = (__m128)m_data[m_b];
  m_c = v5->m_c;
  vertsOut[1] = (hkVector4f)v7.m_quad;
  vertsOut[2] = m_data[m_c];
}

// File Line: 1249
// RVA: 0xB76E80
hkResult *__fastcall hkaiNavMeshGenerationUtils::buildCuttingGeomTree(
        hkResult *result,
        hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap,
        hkGeometry *triMeshIn,
        hkaiNavMeshGenerationSettings *input,
        hkBitField *cuttingTriangles,
        hkcdDynamicAabbTree *cuttingGeomTree)
{
  int m_size; // esi
  hkcdDynamicAabbTree *v7; // rbp
  signed int v12; // ebx
  hkBitField *v13; // r15
  __int64 v14; // rdi
  hkAabb aabb; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f vertsOut; // [rsp+40h] [rbp-58h] BYREF
  __m128 v17; // [rsp+50h] [rbp-48h]
  __m128 v18; // [rsp+60h] [rbp-38h]
  hkResult resulta; // [rsp+B0h] [rbp+18h] BYREF

  m_size = triMeshIn->m_triangles.m_size;
  v7 = cuttingGeomTree;
  hkcdDynamicAabbTree::reserveLeaves(cuttingGeomTree, &resulta, m_size);
  if ( resulta.m_enum )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    v12 = 0;
    if ( m_size > 0 )
    {
      v13 = cuttingTriangles;
      v14 = 0i64;
      do
      {
        if ( ((v13->m_storage.m_words.m_data[v14 >> 5] >> (v12 & 0x1F)) & 1) != 0 )
        {
          hkaiNavMeshGenerationUtils::getTriangleVerts(triMeshIn, input, v12, &vertsOut);
          aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(vertsOut.m_quad, v17), v18);
          aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(vertsOut.m_quad, v17), v18);
          hkcdDynamicAabbTree::insert(v7, &aabb, v12);
        }
        ++v12;
        ++v14;
      }
      while ( v12 < m_size );
    }
    hkcdDynamicAabbTree::rebuildFast(v7, 1);
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 1279
// RVA: 0xB76FC0
bool __fastcall hkaiNavMeshGenerationUtils::isTriangleWalkable(
        hkGeometry *triMeshIn,
        int t,
        hkaiNavMeshGenerationSettings *input,
        hkaiCarverTree *carverTree,
        hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap)
{
  bool v6; // bp
  unsigned int m_material; // r14d
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  BOOL isWalkableBySlope; // eax
  hkVector4f normal; // [rsp+20h] [rbp-A8h] BYREF
  hkArrayBase<hkVector4f> points; // [rsp+30h] [rbp-98h] BYREF
  __m128 v22; // [rsp+40h] [rbp-88h] BYREF
  hkVector4f vertsOut; // [rsp+50h] [rbp-78h] BYREF
  hkVector4f B; // [rsp+60h] [rbp-68h] BYREF
  hkVector4f C; // [rsp+70h] [rbp-58h] BYREF

  v6 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  m_material = triMeshIn->m_triangles.m_data[t].m_material;
  if ( (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          &materialMap->m_map,
          m_material,
          input->m_defaultConstructionProperties.m_storage) & 1) == 0 )
    return 0;
  hkaiNavMeshGenerationUtils::getTriangleVerts(triMeshIn, input, t, &vertsOut);
  if ( !v6 )
  {
    points.m_capacityAndFlags = -2147483647;
    points.m_data = (hkVector4f *)&v22;
    points.m_size = 1;
    v11 = _mm_sub_ps(C.m_quad, vertsOut.m_quad);
    v12 = _mm_sub_ps(B.m_quad, vertsOut.m_quad);
    v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11));
    v14 = _mm_shuffle_ps(v13, v13, 201);
    v22 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(vertsOut.m_quad, B.m_quad), C.m_quad), (__m128)xmmword_141A711C0);
    v15 = _mm_mul_ps(v14, v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rsqrt_ps(v16);
    normal.m_quad = _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v16, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                          _mm_mul_ps(*(__m128 *)_xmm, v17))),
                      v14);
    isWalkableBySlope = hkaiNavMeshGenerationSettings::isWalkableBySlope(input, &normal, &points, m_material);
    points.m_size = 0;
    if ( !isWalkableBySlope )
    {
      if ( points.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          points.m_data,
          16 * points.m_capacityAndFlags);
      return 0;
    }
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
  }
  return hkaiCarverTree::carversContainTriangle(carverTree, &vertsOut, &B, &C) == 0;
}

// File Line: 1323
// RVA: 0xB771E0
bool __fastcall hkaiNavMeshGenerationUtils::isTriangleCutting(
        hkGeometry *triMeshIn,
        int t,
        hkaiNavMeshGenerationSettings *input,
        hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap)
{
  return (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            &materialMap->m_map,
            (unsigned int)triMeshIn->m_triangles.m_data[t].m_material,
            input->m_defaultConstructionProperties.m_storage) & 2) != 0;
}

// File Line: 1361
// RVA: 0xB78A20
void __fastcall `anonymous namespace::Prism::initFromExtrudedTriangle(
        Prism *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *normal,
        hkSimdFloat32 *extrusionLength)
{
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
            _mm_cmple_ps(v12, (__m128)0i64),
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
          _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v18),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), normal->m_quad));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v20, v20);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v22, (__m128)0i64),
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
          _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v26),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), normal->m_quad));
  v28 = _mm_shuffle_ps(v27, v27, 201);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v30, (__m128)0i64),
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
          _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v34),
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), normal->m_quad));
  v36 = _mm_shuffle_ps(v35, v35, 201);
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v38, (__m128)0i64),
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
bool __fastcall `anonymous namespace::Prism::testPlaneAgainstTri(
        Prism *this,
        hkVector4f *plane,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *testPoint)
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

  v6 = _mm_mul_ps(plane->m_quad, testPoint->m_quad);
  v7 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, plane->m_quad), 196);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_mul_ps(a->m_quad, plane->m_quad);
  v10 = _mm_shuffle_ps(v8, v8, 177).m128_f32[0] + v8.m128_f32[0];
  v11 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, plane->m_quad), 196);
  v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v13 = _mm_mul_ps(b->m_quad, plane->m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, plane->m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(plane->m_quad, c->m_quad);
  v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, plane->m_quad), 196);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
  v19 = 0.0 - 0.00000011920929;
  return (float)((float)(_mm_shuffle_ps(v12, v12, 177).m128_f32[0] + v12.m128_f32[0]) * v10) < (float)(0.0 - 0.00000011920929)
      && (float)((float)(_mm_shuffle_ps(v15, v15, 177).m128_f32[0] + v15.m128_f32[0]) * v10) < v19
      && (float)((float)(_mm_shuffle_ps(v18, v18, 177).m128_f32[0] + v18.m128_f32[0]) * v10) < v19;
}

// File Line: 1416
// RVA: 0xB79060
bool __fastcall `anonymous namespace::Prism::hasSeparatingPlaneForTri(
        Prism *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c)
{
  hkVector4f *testPoint; // r14
  hkVector4f v10; // [rsp+30h] [rbp-18h] BYREF

  testPoint = &this->m_a;
  if ( `anonymous namespace::Prism::testPlaneAgainstTriFast(this, &this->m_topPlane, a, b, c, &this->m_a)
    || `anonymous namespace::Prism::testPlaneAgainstTriFast(this, &this->m_planeAB, a, b, c, &this->m_c)
    || `anonymous namespace::Prism::testPlaneAgainstTriFast(this, &this->m_planeBC, a, b, c, testPoint)
    || `anonymous namespace::Prism::testPlaneAgainstTriFast(this, &this->m_planeCA, a, b, c, &this->m_b) )
  {
    return 1;
  }
  v10.m_quad = _mm_add_ps(this->m_normalTimesExtrusion.m_quad, testPoint->m_quad);
  return `anonymous namespace::Prism::testPlaneAgainstTriFast(this, &this->m_bottomPlane, a, b, c, &v10);
}

// File Line: 1434
// RVA: 0xB78E30
bool __fastcall `anonymous namespace::Prism::testPlaneAgainstTriFast(
        Prism *this,
        hkVector4f *plane,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *testPoint)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm6

  v6 = _mm_mul_ps(b->m_quad, plane->m_quad);
  v7 = _mm_mul_ps(c->m_quad, plane->m_quad);
  v8 = _mm_mul_ps(a->m_quad, plane->m_quad);
  v9 = _mm_mul_ps(plane->m_quad, testPoint->m_quad);
  v10 = _mm_shuffle_ps(v8, v6, 238);
  v11 = _mm_shuffle_ps(v8, v6, 68);
  v12 = _mm_shuffle_ps(v7, v9, 68);
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_shuffle_ps(v10, _mm_shuffle_ps(v7, v9, 238), 136),
            _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255)),
          _mm_add_ps(_mm_shuffle_ps(v11, v12, 221), _mm_shuffle_ps(v11, v12, 136)));
  return (_mm_movemask_ps(
            _mm_cmplt_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_shuffle_ps(v13, v13, 255), 0x1Fu), 0x1Fu),
                v13),
              _mm_sub_ps((__m128)0i64, *(__m128 *)&epsilon))) & 7) == 7;
}

// File Line: 1446
// RVA: 0xB78ED0
bool __fastcall `anonymous namespace::Prism::testTriPlaneAgainstPrism(
        Prism *this,
        hkVector4f *ta,
        hkVector4f *tb,
        hkVector4f *tc)
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
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm2

  v4 = _mm_sub_ps(tb->m_quad, ta->m_quad);
  v5 = _mm_sub_ps(tc->m_quad, ta->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
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
  v18 = _mm_shuffle_ps(v15, v17, 238);
  v19 = _mm_shuffle_ps(v15, v17, 68);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, _mm_shuffle_ps(v14, v14, 238), 136), _mm_shuffle_ps(v13, v13, 255)),
          _mm_add_ps(_mm_shuffle_ps(v19, v16, 221), _mm_shuffle_ps(v19, v16, 136)));
  v21 = _mm_mul_ps(this->m_normalTimesExtrusion.m_quad, v13);
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170)),
          v20);
  return (_mm_movemask_ps(_mm_cmplt_ps(*(__m128 *)&epsilon, _mm_min_ps(v20, v22))) & 7) == 7
      || (_mm_movemask_ps(
            _mm_cmplt_ps(
              _mm_max_ps(v20, v22),
              _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                *(__m128 *)&epsilon))) & 7) == 7;
}

// File Line: 1472
// RVA: 0xB77220
hkResult *__fastcall hkaiNavMeshGenerationUtils::getNearbyCuttingGeometry(
        hkResult *result,
        hkAabb *extrudedTriAabb,
        hkGeometry *triMeshIn,
        int t,
        hkaiNavMeshGenerationSettings *input,
        hkcdDynamicAabbTree *cuttingGeomTree,
        hkGeometry *cuttingGeom,
        hkaiEdgeGeometry *cuttingEdgeGeometryOut)
{
  hkaiNavMeshGenerationSettings *v8; // r13
  hkGeometry *v10; // r15
  hkResult *v12; // r12
  int m_capacityAndFlags; // r8d
  int m_size; // ecx
  unsigned int *m_data; // rdx
  hkGeometry *v17; // rbx
  int v18; // r9d
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rdi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int SizeInBytesFor; // eax
  int v25; // esi
  int v26; // r9d
  int v27; // r8d
  hkGeometry::Triangle *v28; // rcx
  hkVector4f *v29; // rdx
  bool v30; // r14
  __m128 m_quad; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  int m_enum; // esi
  hkGeometry *v42; // r12
  IAmdDxExtQuadBufferStereo *mStereo; // rbx
  __int64 v44; // r13
  hkGeometry::Triangle *v45; // rcx
  hkaiGeometryToEdgeGeometryConverter *p_vertsOut; // rsi
  __int64 v47; // rbx
  __int64 v48; // r15
  unsigned __int64 v49; // r14
  int Key; // eax
  unsigned __int64 v51; // rcx
  hkVector4f v52; // xmm0
  __int64 v53; // rax
  __int64 v54; // rcx
  hkGeometry::Triangle *v55; // rdx
  int mExtension_high; // eax
  int v57; // r8d
  bool v58; // [rsp+30h] [rbp-D0h]
  hkArray<unsigned int,hkContainerTempAllocator> array; // [rsp+38h] [rbp-C8h] BYREF
  void *ptr; // [rsp+48h] [rbp-B8h] BYREF
  int v61; // [rsp+50h] [rbp-B0h]
  int v62; // [rsp+54h] [rbp-ACh]
  hkResult resulta; // [rsp+58h] [rbp-A8h] BYREF
  hkResult v64; // [rsp+5Ch] [rbp-A4h] BYREF
  hkResult v65; // [rsp+60h] [rbp-A0h] BYREF
  hkResult v66; // [rsp+64h] [rbp-9Ch] BYREF
  AMD_HD3D v67; // [rsp+68h] [rbp-98h] BYREF
  int v68; // [rsp+88h] [rbp-78h]
  int v69[4]; // [rsp+90h] [rbp-70h]
  hkVector4f normal; // [rsp+A0h] [rbp-60h] BYREF
  hkSimdFloat32 extrusionLength; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f a; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f b; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f c; // [rsp+E0h] [rbp-20h] BYREF
  hkaiGeometryToEdgeGeometryConverter vertsOut; // [rsp+F0h] [rbp-10h] BYREF
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb v76; // [rsp+150h] [rbp+50h] BYREF
  Prism v77; // [rsp+1A0h] [rbp+A0h] BYREF

  v8 = input;
  v10 = triMeshIn;
  v12 = result;
  v58 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, 16, 4);
  if ( resulta.m_enum
    || (hkcdDynamicAabbTree::queryAabb(cuttingGeomTree, (hkResult *)&v67.mStereo, extrudedTriAabb, &array),
        LODWORD(v67.mStereo)) )
  {
LABEL_2:
    m_capacityAndFlags = array.m_capacityAndFlags;
    v12->m_enum = HK_FAILURE;
    array.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        4 * m_capacityAndFlags);
    return v12;
  }
  hkaiEdgeGeometry::clear(cuttingEdgeGeometryOut);
  m_size = array.m_size;
  m_data = array.m_data;
  if ( !array.m_size || array.m_size == 1 && *array.m_data == t )
  {
    v57 = array.m_capacityAndFlags;
    v12->m_enum = HK_SUCCESS;
    array.m_size = 0;
    if ( v57 >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, m_data, 4 * v57);
      return v12;
    }
    return v12;
  }
  v17 = cuttingGeom;
  v18 = 3 * array.m_size;
  p_m_vertices = &cuttingGeom->m_vertices;
  v20 = cuttingGeom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < 3 * array.m_size )
  {
    v21 = 2 * v20;
    if ( v18 < v21 )
      v18 = v21;
    hkArrayUtil::_reserve(&v66, &hkContainerHeapAllocator::s_alloc, &cuttingGeom->m_vertices, v18, 16);
    if ( v66.m_enum == HK_SUCCESS )
    {
      m_size = array.m_size;
      goto LABEL_15;
    }
    goto LABEL_2;
  }
  v66.m_enum = HK_SUCCESS;
LABEL_15:
  v22 = v17->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 >= m_size )
  {
    v64.m_enum = HK_SUCCESS;
LABEL_22:
    ptr = 0i64;
    v61 = 0;
    v62 = 0x80000000;
    SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(3 * m_size);
    v25 = SizeInBytesFor;
    if ( (v62 & 0x3FFFFFFF) >= SizeInBytesFor )
    {
      v65.m_enum = HK_SUCCESS;
    }
    else
    {
      v26 = SizeInBytesFor;
      if ( SizeInBytesFor < 2 * (v62 & 0x3FFFFFFF) )
        v26 = 2 * (v62 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v65, &hkContainerHeapAllocator::s_alloc, &ptr, v26, 1);
      if ( v65.m_enum )
      {
        v27 = v62;
        v12->m_enum = HK_FAILURE;
        v61 = 0;
        if ( v27 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, ptr, v27 & 0x3FFFFFFF);
        ptr = 0i64;
        array.m_size = 0;
LABEL_58:
        v62 = 0x80000000;
        goto LABEL_59;
      }
    }
    v61 = v25;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v67,
      ptr,
      v25);
    v28 = v10->m_triangles.m_data;
    v29 = v10->m_vertices.m_data;
    v30 = v58;
    m_quad = v29[v28[t].m_a].m_quad;
    a.m_quad = m_quad;
    v32 = v29[v28[t].m_b].m_quad;
    b.m_quad = v32;
    v33 = v29[v28[t].m_c].m_quad;
    c.m_quad = v33;
    if ( v58 )
    {
      v34 = _mm_sub_ps(v32, m_quad);
      v35 = _mm_sub_ps(v33, m_quad);
      v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34), _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v35));
      v37 = _mm_shuffle_ps(v36, v36, 201);
      v38 = _mm_mul_ps(v37, v37);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_rsqrt_ps(v39);
      normal.m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v39, (__m128)0i64),
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
    `anonymous namespace::Prism::initFromExtrudedTriangle(&v77, &a, &b, &c, &normal, &extrusionLength);
    if ( v58 )
      hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(
        &v76,
        &a,
        &b,
        &c,
        &normal,
        &extrusionLength);
    m_enum = 0;
    resulta.m_enum = HK_SUCCESS;
    if ( array.m_size > 0 )
    {
      v42 = cuttingGeom;
      mStereo = 0i64;
      v67.mStereo = 0i64;
      do
      {
        v44 = *(int *)((char *)array.m_data + (unsigned __int64)mStereo);
        if ( (_DWORD)v44 != t )
        {
          hkaiNavMeshGenerationUtils::getTriangleVerts(v10, input, v44, (hkVector4f *)&vertsOut);
          if ( hkaiNavMeshUtils::triangleAabbCheck(
                 extrudedTriAabb,
                 (hkVector4f *)&vertsOut,
                 (hkVector4f *)&vertsOut.m_triangles,
                 (hkVector4f *)&vertsOut.m_faceTriangleIndices) )
          {
            if ( !`anonymous namespace::Prism::hasSeparatingPlaneForTri(
                    &v77,
                    (hkVector4f *)&vertsOut,
                    (hkVector4f *)&vertsOut.m_triangles,
                    (hkVector4f *)&vertsOut.m_faceTriangleIndices)
              && (!v30
               || hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(
                    &v76,
                    (hkVector4f *)&vertsOut,
                    (hkVector4f *)&vertsOut.m_triangles,
                    (hkVector4f *)&vertsOut.m_faceTriangleIndices)) )
            {
              v45 = v10->m_triangles.m_data;
              p_vertsOut = &vertsOut;
              v47 = 0i64;
              v48 = 3i64;
              v69[0] = v45[v44].m_a;
              v69[1] = v45[v44].m_b;
              v69[2] = v45[v44].m_c;
              do
              {
                v49 = v69[v47];
                Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v67,
                                      v49);
                if ( Key > (int)v67.mHeight )
                {
                  v51 = v42->m_vertices.m_size;
                  v52.m_quad = *(__m128 *)&p_vertsOut->m_edgeAngularDistance;
                  v53 = p_m_vertices->m_size;
                  *(_DWORD *)((char *)&v67.mExtension + v47 * 4) = v51;
                  p_m_vertices->m_data[v53] = (hkVector4f)v52.m_quad;
                  ++p_m_vertices->m_size;
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v67,
                    &hkContainerHeapAllocator::s_alloc,
                    v49,
                    v51);
                }
                else
                {
                  *(_DWORD *)((char *)&v67.mExtension + v47 * 4) = *(_DWORD *)(*(_QWORD *)&v67.mEnableStereo
                                                                             + 16i64 * Key
                                                                             + 8);
                }
                ++v47;
                p_vertsOut = (hkaiGeometryToEdgeGeometryConverter *)((char *)p_vertsOut + 16);
                --v48;
              }
              while ( v48 );
              v54 = v42->m_triangles.m_size;
              m_enum = resulta.m_enum;
              mStereo = v67.mStereo;
              v10 = triMeshIn;
              v42->m_triangles.m_size = v54 + 1;
              v55 = &v42->m_triangles.m_data[v54];
              v30 = v58;
              v55->m_a = (int)v67.mExtension;
              mExtension_high = HIDWORD(v67.mExtension);
              v55->m_material = v44;
              v55->m_b = mExtension_high;
              v55->m_c = v68;
            }
          }
        }
        ++m_enum;
        mStereo = (IAmdDxExtQuadBufferStereo *)((char *)mStereo + 4);
        resulta.m_enum = m_enum;
        v67.mStereo = mStereo;
      }
      while ( m_enum < array.m_size );
      v12 = result;
      v17 = cuttingGeom;
    }
    if ( v30 )
    {
      hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(&vertsOut);
      vertsOut.m_allowMergingDifferentUserData.m_bool = 1;
      hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
        &vertsOut,
        (hkResult *)&input,
        v17,
        (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
        cuttingEdgeGeometryOut);
      if ( (_DWORD)input )
      {
        v12->m_enum = HK_FAILURE;
        hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&vertsOut);
LABEL_55:
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v67,
          &hkContainerHeapAllocator::s_alloc);
        _(&v67);
        v61 = 0;
        if ( v62 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, ptr, v62 & 0x3FFFFFFF);
        ptr = 0i64;
        array.m_size = 0;
        goto LABEL_58;
      }
      hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&vertsOut);
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
        v12->m_enum = HK_FAILURE;
        goto LABEL_55;
      }
    }
    v12->m_enum = HK_SUCCESS;
    goto LABEL_55;
  }
  v23 = 2 * v22;
  if ( m_size < v23 )
    m_size = v23;
  hkArrayUtil::_reserve(&v64, &hkContainerHeapAllocator::s_alloc, &v17->m_triangles, m_size, 16);
  if ( v64.m_enum == HK_SUCCESS )
  {
    m_size = array.m_size;
    goto LABEL_22;
  }
  v12->m_enum = HK_FAILURE;
  array.m_size = 0;
LABEL_59:
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
  return v12;
}

// File Line: 1596
// RVA: 0xB77C60
hkResult *__fastcall hkaiNavMeshGenerationUtils::raycastAgainstCuttingGeometry(
        hkResult *result,
        int walkableTriIndex,
        hkArrayBase<hkVector4f> *vertices,
        hkArrayBase<int> *triangles,
        int *hitFaces,
        hkGeometry *cuttingGeometry,
        hkSimdFloat32 *characterHeight,
        hkVector4f *rayDir)
{
  hkResult *v8; // rbx
  _QWORD *Value; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // rdi
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  __m128 v16; // xmm6
  int m_enum; // r15d
  hkGeometry *v18; // r14
  _QWORD *v19; // r8
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // rax
  int m_size; // r9d
  __int64 v23; // rdi
  int v24; // r9d
  int v25; // edx
  int v26; // r8d
  int v27; // esi
  __int64 m_capacityAndFlags; // r12
  int v29; // r13d
  hkGeometry::Triangle *m_data; // r8
  hkVector4f *v31; // rcx
  __m128 m_quad; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  _DWORD *v35; // rdi
  __int64 i; // rcx
  int v37; // r8d
  __int64 v38; // r13
  hkResultEnum v39; // eax
  int v40; // r8d
  __int64 v41; // r9
  int v42; // ecx
  unsigned __int64 v43; // rdi
  int v44; // r10d
  int v45; // r9d
  int m_data_high; // eax
  unsigned __int64 v47; // rdx
  __int64 v48; // r8
  __int64 v49; // r12
  __int64 v50; // r14
  int v51; // ebx
  __m128 v52; // xmm7
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 *v55; // rdx
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  __int64 v59; // rcx
  __int64 v60; // rdi
  __int64 v61; // rcx
  __int64 v62; // rdx
  int v63; // edi
  int v64; // r8d
  hkResultEnum v65; // eax
  int v66; // esi
  hk1AxisSweep::AabbInt *v67; // rdx
  unsigned int v68; // eax
  bool v69; // cf
  bool v70; // zf
  hk1AxisSweep::AabbInt *m_potentialPtr; // rax
  hk1AxisSweep::AabbInt *m_pb; // rcx
  __int64 v73; // rsi
  __int64 v74; // rcx
  _DWORD *v75; // rdi
  unsigned __int64 v76; // r9
  _QWORD *v77; // r8
  unsigned __int64 v78; // rdi
  unsigned __int64 v79; // rax
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-98h] BYREF
  int v82; // [rsp+38h] [rbp-90h]
  int v83; // [rsp+3Ch] [rbp-8Ch]
  hk1AxisSweep::AabbInt *aabbs; // [rsp+40h] [rbp-88h] BYREF
  int v85; // [rsp+48h] [rbp-80h]
  int v86; // [rsp+4Ch] [rbp-7Ch]
  hkResult v87[2]; // [rsp+50h] [rbp-78h] BYREF
  hkAabb aabbIn; // [rsp+58h] [rbp-70h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+78h] [rbp-50h] BYREF
  hk1AxisSweep::IteratorAB v90; // [rsp+88h] [rbp-40h] BYREF
  hkaiPositionHitFilter v91; // [rsp+B8h] [rbp-10h] BYREF
  hkaiEdgeGeometryRaycaster v92; // [rsp+E8h] [rbp+20h] BYREF
  hkResult *v93; // [rsp+1B8h] [rbp+F0h]
  _QWORD *v94; // [rsp+1C8h] [rbp+100h]
  hkResult v95[2]; // [rsp+1D0h] [rbp+108h] BYREF
  _DWORD *v96; // [rsp+1D8h] [rbp+110h]
  hkGeometry *geom; // [rsp+1E0h] [rbp+118h]
  __m128 *retaddr; // [rsp+1E8h] [rbp+120h]

  v8 = result;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtraycastNoTree";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  aabbIn.m_max.m_quad.m128_f32[2] = FLOAT_0_001;
  v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  m_enum = triangles->m_size / 3;
  v87[1].m_enum = m_enum;
  hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&v92);
  hkaiPositionHitFilter::hkaiPositionHitFilter(&v91, v16.m128_f32[0]);
  hkaiEdgeGeometryRaycaster::setupForRemoveUnreachableTriangles(&v92);
  hkaiEdgeGeometryRaycaster::setHitFilter(&v92, &v91);
  v18 = geom;
  hkaiEdgeGeometryRaycaster::initNoTree(&v92, (hkResult *)&sortedAabbs.m_size, geom);
  if ( !sortedAabbs.m_size )
  {
    m_size = v18->m_triangles.m_size;
    v23 = 0i64;
    v83 = 0x80000000;
    v24 = m_size + 4;
    v25 = 0;
    array = 0i64;
    v82 = 0;
    if ( v24 <= 0 )
    {
      v87[0].m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(v87, &hkContainerHeapAllocator::s_alloc, &array, v24, 32);
      if ( v87[0].m_enum )
      {
        v26 = v83;
        v8->m_enum = HK_FAILURE;
        v82 = 0;
        if ( v26 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v26);
        array = 0i64;
        v91.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
        v83 = 0x80000000;
        hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v92);
        v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v20 = v19[1];
        if ( v20 < v19[3] )
          goto LABEL_5;
        return v8;
      }
      v25 = v82;
    }
    v27 = 0;
    sortedAabbs.m_capacityAndFlags = v18->m_triangles.m_size;
    m_capacityAndFlags = sortedAabbs.m_capacityAndFlags;
    if ( sortedAabbs.m_capacityAndFlags > 0 )
    {
      v29 = walkableTriIndex + 1;
      do
      {
        m_data = v18->m_triangles.m_data;
        if ( m_data[v23].m_material + 1 != v29 )
        {
          v31 = v18->m_vertices.m_data;
          m_quad = v31[m_data[v23].m_a].m_quad;
          v33 = v31[m_data[v23].m_b].m_quad;
          v34 = v31[m_data[v23].m_c].m_quad;
          v82 = v25 + 1;
          aabbIn.m_min.m_quad = _mm_min_ps(_mm_min_ps(m_quad, v33), v34);
          aabbIn.m_max.m_quad = _mm_max_ps(_mm_max_ps(m_quad, v33), v34);
          hk1AxisSweep::AabbInt::set(&array[v25], &aabbIn, v27);
          v25 = v82;
        }
        ++v27;
        ++v23;
        --m_capacityAndFlags;
      }
      while ( m_capacityAndFlags );
    }
    if ( !v25 )
    {
      if ( m_enum > 0 )
      {
        v35 = v96;
        for ( i = m_enum; i; --i )
          *v35++ = -1;
      }
      v37 = v83;
      v8->m_enum = HK_SUCCESS;
      v82 = 0;
      if ( v37 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v37);
      array = 0i64;
LABEL_98:
      v83 = 0x80000000;
      v91.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v92);
      v77 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v78 = v77[1];
      if ( v78 < v77[3] )
      {
        v79 = __rdtsc();
        *(_DWORD *)(v78 + 8) = v79;
        *(_QWORD *)v78 = "Et";
        v77[1] = v78 + 16;
      }
      return v8;
    }
    v38 = 0i64;
    v86 = 0x80000000;
    aabbs = 0i64;
    v85 = 0;
    if ( m_enum + 4 <= 0 )
    {
      v39 = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(
        (hkResult *)&aabbIn.m_max.m_quad.m128_u16[4],
        &hkContainerHeapAllocator::s_alloc,
        &aabbs,
        m_enum + 4,
        32);
      v39 = aabbIn.m_max.m_quad.m128_i32[2];
    }
    v87[0].m_enum = v39;
    if ( v39 )
    {
      v8->m_enum = HK_FAILURE;
LABEL_93:
      v85 = 0;
      if ( v86 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, aabbs, 32 * v86);
      v82 = 0;
      v86 = 0x80000000;
      aabbs = 0i64;
      if ( v83 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v83);
      array = 0i64;
      goto LABEL_98;
    }
    v40 = 0x80000000;
    *(_QWORD *)&v87[0].m_enum = 0i64;
    v41 = 0i64;
    v42 = 0x80000000;
    aabbIn.m_min = (hkVector4f)0x8000000000000000ui64;
    v43 = 0i64;
    v44 = 0;
    aabbIn.m_max.m_quad.m128_u64[0] = 0x8000000000000000ui64;
    if ( m_enum <= 0 )
    {
      LODWORD(sortedAabbs.m_data) = 0;
    }
    else
    {
      hkArrayUtil::_reserve((hkResult *)&sortedAabbs, &hkContainerHeapAllocator::s_alloc, v87, m_enum, 16);
      v40 = aabbIn.m_min.m_quad.m128_i32[1];
      v41 = aabbIn.m_min.m_quad.m128_u32[0];
      v42 = aabbIn.m_max.m_quad.m128_i32[1];
      v44 = aabbIn.m_max.m_quad.m128_i32[0];
      v43 = aabbIn.m_min.m_quad.m128_u64[1];
    }
    if ( (v42 & 0x3FFFFFFF) >= m_enum )
    {
      m_data_high = 0;
      HIDWORD(sortedAabbs.m_data) = 0;
    }
    else
    {
      v45 = m_enum;
      if ( m_enum < 2 * (v42 & 0x3FFFFFFF) )
        v45 = 2 * (v42 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&sortedAabbs.m_data + 1,
        &hkContainerHeapAllocator::s_alloc,
        &aabbIn.m_min.m_quad.m128_u16[4],
        v45,
        16);
      v40 = aabbIn.m_min.m_quad.m128_i32[1];
      v41 = aabbIn.m_min.m_quad.m128_u32[0];
      v42 = aabbIn.m_max.m_quad.m128_i32[1];
      v44 = aabbIn.m_max.m_quad.m128_i32[0];
      v43 = aabbIn.m_min.m_quad.m128_u64[1];
      m_data_high = HIDWORD(sortedAabbs.m_data);
    }
    if ( LODWORD(sortedAabbs.m_data) || m_data_high )
    {
      v8->m_enum = HK_FAILURE;
      aabbIn.m_max.m_quad.m128_i32[0] = 0;
      if ( v42 < 0 )
      {
LABEL_90:
        aabbIn.m_min.m_quad.m128_u64[1] = 0i64;
        aabbIn.m_max.m_quad.m128_i32[1] = 0x80000000;
        aabbIn.m_min.m_quad.m128_i32[0] = 0;
        if ( v40 >= 0 )
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            *(_QWORD *)&v87[0].m_enum,
            (unsigned int)(16 * v40),
            v41);
        *(_QWORD *)&v87[0].m_enum = 0i64;
        aabbIn.m_min.m_quad.m128_i32[1] = 0x80000000;
        goto LABEL_93;
      }
      v47 = v43;
      v48 = (unsigned int)(16 * v42);
      goto LABEL_88;
    }
    v49 = (__int64)v96;
    if ( m_enum > 0 )
    {
      v50 = 0i64;
      v51 = 0;
      v52 = _mm_sub_ps((__m128)0i64, v16);
      while ( 1 )
      {
        v53 = _mm_mul_ps(v52, *(__m128 *)&result->m_enum);
        v54 = _mm_add_ps(
                _mm_add_ps(
                  *(__m128 *)(*v94 + 16i64 * *(int *)(v38 + **(_QWORD **)&v95[0].m_enum)),
                  *(__m128 *)(*v94 + 16i64 * *(int *)(v38 + **(_QWORD **)&v95[0].m_enum + 4))),
                *(__m128 *)(*v94 + 16i64 * *(int *)(v38 + **(_QWORD **)&v95[0].m_enum + 8)));
        aabbIn.m_min.m_quad.m128_i32[0] = v41 + 1;
        v55 = (__m128 *)(*(_QWORD *)&v87[0].m_enum + 16i64 * (int)v41);
        v56 = _mm_mul_ps(v54, (__m128)xmmword_141A711C0);
        aabbIn.m_max.m_quad.m128_i32[0] = v44 + 1;
        *v55 = _mm_add_ps(v53, v56);
        v57 = _mm_add_ps(_mm_mul_ps(*retaddr, *(__m128 *)&result->m_enum), v56);
        *(__m128 *)(v43 + 16i64 * v44) = v57;
        aabbIn.m_min.m_quad = _mm_min_ps(*v55, v57);
        v58 = _mm_max_ps(*v55, *(__m128 *)(v43 + 16i64 * v44));
        aabbIn.m_min.m_quad = _mm_sub_ps(aabbIn.m_min.m_quad, *(__m128 *)&epsilon);
        v59 = v85++;
        aabbIn.m_max.m_quad = _mm_add_ps(v58, *(__m128 *)&epsilon);
        hk1AxisSweep::AabbInt::set(&aabbs[v59], &aabbIn, v51);
        *(_DWORD *)(v49 + 4 * v50++) = -1;
        ++v51;
        v38 += 12i64;
        if ( v50 >= m_enum )
          break;
        LODWORD(v41) = aabbIn.m_min.m_quad.m128_i32[0];
        v44 = aabbIn.m_max.m_quad.m128_i32[0];
        v43 = aabbIn.m_min.m_quad.m128_u64[1];
      }
      v8 = v93;
      v18 = geom;
      m_enum = v87[1].m_enum;
    }
    v60 = 4i64;
    do
    {
      v61 = v85++;
      aabbs[v61].m_min[0] = -1;
      v62 = v82++;
      array[v62].m_min[0] = -1;
      --v60;
    }
    while ( v60 );
    v63 = v82;
    sortedAabbs.m_data = 0i64;
    v85 = 0;
    v86 = 0x80000000;
    if ( v82 < 0 )
      v63 = v85;
    if ( v63 <= 0 )
    {
      v95[0].m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(v95, &hkContainerTempAllocator::s_alloc, &sortedAabbs, v63, 32);
      if ( v95[0].m_enum )
      {
        v8->m_enum = HK_FAILURE;
        goto LABEL_56;
      }
    }
    v64 = 0x80000000;
    v85 = v63;
    aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
    aabbIn.m_min.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    if ( v63 <= 0 )
    {
      v65 = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v87[1], &hkContainerHeapAllocator::s_alloc, &aabbIn, v63, 8);
      v65 = v87[1].m_enum;
      v64 = aabbIn.m_min.m_quad.m128_i32[3];
      if ( v87[1].m_enum )
        goto LABEL_65;
    }
    aabbIn.m_min.m_quad.m128_i32[2] = v63;
LABEL_65:
    v95[0].m_enum = v65;
    if ( v65 == HK_SUCCESS )
    {
      hk1AxisSweep::sortAabbs(aabbs, m_enum, (hkArrayBase<hkRadixSort::SortData32> *)&aabbIn, &sortedAabbs);
      v66 = sortedAabbs.m_capacityAndFlags;
      hk1AxisSweep::sortAabbs(
        array,
        sortedAabbs.m_capacityAndFlags,
        (hkArrayBase<hkRadixSort::SortData32> *)&aabbIn,
        &sortedAabbs);
      aabbIn.m_min.m_quad.m128_i32[2] = 0;
      if ( aabbIn.m_min.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          (void *)aabbIn.m_min.m_quad.m128_u64[0],
          8 * aabbIn.m_min.m_quad.m128_i32[3]);
      aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
      aabbIn.m_min.m_quad.m128_i32[3] = 0x80000000;
      v85 = 0;
      if ( v86 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * v86);
      v67 = aabbs;
      v68 = array->m_min[0];
      v90.m_numA = m_enum;
      v90.m_numB = v66;
      v69 = aabbs->m_min[0] < v68;
      v70 = aabbs->m_min[0] == v68;
      v90.m_pa = aabbs;
      v90.m_pb = array;
      v90.m_aIsBigger = !v69 && !v70;
      if ( v69 || v70 )
      {
        v90.m_currentPtr = aabbs;
        v67 = array;
      }
      else
      {
        v90.m_currentPtr = array;
      }
      v90.m_potentialPtr = v67 - 1;
      while ( 1 )
      {
        hk1AxisSweep::IteratorAB::next(&v90);
        if ( v90.m_numA <= 0 || v90.m_numB <= 0 )
          break;
        if ( v90.m_aIsBigger )
        {
          m_potentialPtr = v90.m_potentialPtr;
          m_pb = v90.m_pb;
        }
        else
        {
          m_potentialPtr = v90.m_pa;
          m_pb = v90.m_potentialPtr;
        }
        v73 = *(int *)m_pb->m_expansionMin;
        v74 = *(int *)m_potentialPtr->m_expansionMin;
        v75 = (_DWORD *)(v49 + 4 * v74);
        if ( *v75 == -1 )
        {
          v76 = aabbIn.m_min.m_quad.m128_u64[1];
          aabbIn.m_min = (hkVector4f)query.m_quad;
          if ( hkaiEdgeGeometryRaycaster::raycastAgainstFace(
                 &v92,
                 v73 + 1,
                 (hkVector4f *)(16 * v74 + *(_QWORD *)&v87[0].m_enum),
                 (hkVector4f *)(16 * v74 + v76),
                 (hkSimdFloat32 *)&aabbIn) )
          {
            *v75 = v18->m_triangles.m_data[v73].m_material + 1;
          }
        }
      }
      v8->m_enum = HK_SUCCESS;
      goto LABEL_86;
    }
    v8->m_enum = HK_FAILURE;
    aabbIn.m_min.m_quad.m128_i32[2] = 0;
    if ( v64 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)aabbIn.m_min.m_quad.m128_u64[0],
        8 * v64);
    aabbIn.m_min.m_quad.m128_u64[0] = 0i64;
    aabbIn.m_min.m_quad.m128_i32[3] = 0x80000000;
LABEL_56:
    v85 = 0;
    if ( v86 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortedAabbs.m_data, 32 * v86);
    sortedAabbs.m_data = 0i64;
    v86 = 0x80000000;
LABEL_86:
    aabbIn.m_max.m_quad.m128_i32[0] = 0;
    if ( aabbIn.m_max.m_quad.m128_i32[1] < 0 )
    {
LABEL_89:
      v40 = aabbIn.m_min.m_quad.m128_i32[1];
      goto LABEL_90;
    }
    v47 = aabbIn.m_min.m_quad.m128_u64[1];
    v48 = (unsigned int)(16 * aabbIn.m_max.m_quad.m128_i32[1]);
LABEL_88:
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v47,
      v48,
      v41);
    goto LABEL_89;
  }
  v8->m_enum = HK_FAILURE;
  v91.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&v92);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = v19[1];
  if ( v20 < v19[3] )
  {
LABEL_5:
    *(_QWORD *)v20 = "Et";
    v21 = __rdtsc();
    *(_DWORD *)(v20 + 8) = v21;
    v19[1] = v20 + 16;
  }
  return v8;
}:s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v47,
      v48,
      v41);
    goto LABEL_89;
  }
  v8->m_enum = HK_FAILURE;
  v91.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkaiEdgeGeometryRaycaster::~hkaiE

// File Line: 1739
// RVA: 0xB77970
hkResult *__fastcall hkaiNavMeshGenerationUtils::weldDuplicateVertices(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<int,hkContainerHeapAllocator> *remap)
{
  __int64 m_size; // rsi
  int m_capacityAndFlags; // eax
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // r8d
  __int64 v12; // rbx
  __int64 v13; // rdx
  int v14; // r10d
  __int64 v15; // r9
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm1
  int v18; // ecx
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  __int64 v21; // rcx
  hkVector4f v22; // xmm0
  __int64 v23; // rsi
  __int64 v24; // r9
  __int64 v25; // r15
  DuplicateVertexRef *v26; // r10
  __int64 m_index; // rdx
  __int64 v28; // rdx
  __m128 i; // xmm1
  DuplicateVertexRef *v30; // r8
  __int64 v31; // rax
  DuplicateVertexRef *array; // [rsp+30h] [rbp-18h] BYREF
  int v34; // [rsp+38h] [rbp-10h]
  int v35; // [rsp+3Ch] [rbp-Ch]
  hkResult resulta; // [rsp+88h] [rbp+40h] BYREF
  hkResult v37; // [rsp+98h] [rbp+50h] BYREF

  m_size = vertices->m_size;
  v35 = 0x80000000;
  array = 0i64;
  v34 = 0;
  if ( (int)m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, m_size, 8);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_31;
    }
  }
  m_capacityAndFlags = remap->m_capacityAndFlags;
  v34 = m_size;
  v8 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= (int)m_size )
  {
    v37.m_enum = HK_SUCCESS;
  }
  else
  {
    v9 = 2 * v8;
    v10 = m_size;
    if ( (int)m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&v37, &hkContainerHeapAllocator::s_alloc, remap, v10, 4);
    if ( v37.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_31;
    }
  }
  remap->m_size = m_size;
  v11 = 0;
  v12 = m_size;
  v13 = 0i64;
  if ( m_size >= 4 )
  {
    v14 = 2;
    v15 = 0i64;
    do
    {
      v13 += 4i64;
      v15 += 4i64;
      v16.m_quad = (__m128)vertices->m_data[v15 - 4];
      *((_DWORD *)&array[v13 - 3] - 1) = v11;
      v11 += 4;
      LODWORD(array[v13 - 4].m_value) = v16.m_quad.m128_i32[0];
      v17.m_quad = (__m128)vertices->m_data[v15 - 3];
      *((_DWORD *)&array[v13 - 2] - 1) = v14 - 1;
      v18 = v14 + 1;
      LODWORD(array[v13 - 3].m_value) = v17.m_quad.m128_i32[0];
      v19.m_quad = (__m128)vertices->m_data[v15 - 2];
      *((_DWORD *)&array[v13 - 1] - 1) = v14;
      v14 += 4;
      LODWORD(array[v13 - 2].m_value) = v19.m_quad.m128_i32[0];
      v20.m_quad = (__m128)vertices->m_data[v15 - 1];
      array[v13 - 1].m_index = v18;
      LODWORD(array[v13 - 1].m_value) = v20.m_quad.m128_i32[0];
    }
    while ( v13 < m_size - 3 );
  }
  if ( v13 < m_size )
  {
    v21 = v13;
    do
    {
      ++v13;
      v22.m_quad = (__m128)vertices->m_data[v21++];
      array[v13 - 1].m_index = v11++;
      LODWORD(array[v13 - 1].m_value) = v22.m_quad.m128_i32[0];
    }
    while ( v13 < m_size );
  }
  if ( (int)m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
      array,
      0,
      m_size - 1,
      0);
  if ( (int)m_size > 0 )
  {
    v23 = 1i64;
    v24 = 0i64;
    v25 = v12;
    do
    {
      v26 = array;
      m_index = array[v24].m_index;
      if ( (int)m_index >= 0 )
      {
        remap->m_data[m_index] = m_index;
        v28 = v23;
        for ( i = vertices->m_data[v26[v24].m_index].m_quad; v28 < v12; ++v28 )
        {
          v30 = array;
          v31 = array[v28].m_index;
          if ( (int)v31 >= 0 )
          {
            if ( v26[v24].m_value != array[v28].m_value )
              break;
            if ( (_mm_movemask_ps(_mm_cmpeq_ps(i, vertices->m_data[v31].m_quad)) & 7) == 7 )
            {
              remap->m_data[array[v28].m_index] = v26[v24].m_index;
              v30[v28].m_index = -1;
            }
          }
        }
        v26[v24].m_index = -1;
      }
      ++v24;
      ++v23;
      --v25;
    }
    while ( v25 );
  }
  result->m_enum = HK_SUCCESS;
LABEL_31:
  v34 = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v35);
  return result;
}

// File Line: 1792
// RVA: 0xB75920
bool __fastcall hkaiNavMeshGenerationUtils::_rayTriangleIntersect(
        hkVector4f *pos,
        hkVector4f *dir,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkSimdFloat32 *distOut)
{
  __m128 m_quad; // xmm6
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  unsigned int v10; // eax
  hkSimdFloat32 tolerance; // [rsp+30h] [rbp-68h] BYREF
  hkSimdFloat32 fractionOut; // [rsp+40h] [rbp-58h] BYREF
  hkcdRay ray; // [rsp+50h] [rbp-48h] BYREF

  m_quad = dir->m_quad;
  tolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  v7 = _mm_cmpeq_ps((__m128)0i64, m_quad);
  v8 = _mm_rcp_ps(m_quad);
  ray.m_direction.m_quad = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  v9 = pos->m_quad;
  ray.m_invDirection.m_quad = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps(
                                    (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)m_quad, 0x1Fu), 0x1Fu),
                                    (__m128)_xmm),
                                  v7),
                                _mm_andnot_ps(v7, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v8)), v8)));
  ray.m_origin.m_quad = v9;
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, ray.m_direction.m_quad)) & 7 | 0x3F000000;
  v10 = hkcdLineTriangleIntersect(&ray, a, b, c, &tolerance, &fractionOut);
  *distOut = (hkSimdFloat32)fractionOut.m_real;
  return v10 != 0;
}

// File Line: 1857
// RVA: 0xB75A20
hkaiCarverTree *__fastcall hkaiNavMeshGenerationUtils::_removeUnreachableTriangles(
        hkaiCarverTree *result,
        hkArrayBase<int> *input,
        hkaiEdgeGeometryRaycaster *cuttingGeomRaycaster,
        hkArray<int,hkContainerHeapAllocator> *walkableGeom,
        hkArray<int,hkContainerHeapAllocator> *tree,
        hkArray<int,hkContainerHeapAllocator> *trianglesPerFace,
        hkArray<int,hkContainerHeapAllocator> *trisInOut,
        hkArray<int,hkContainerHeapAllocator> *triConnectivityInOut,
        hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut,
        hkArrayBase<int> *materials,
        hkArrayBase<int> *originalFaceIndices,
        hkArray<hkVector4f,hkContainerHeapAllocator> *triangleVertices,
        hkArray<int,hkContainerHeapAllocator> *hitFaces,
        hkaiNavMeshGenerationProgressCallback *cb,
        hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkArrayBase<int> *v15; // rbx
  bool v16; // zf
  hkaiEdgeGeometry *v17; // r12
  __m128 epsilon; // xmm8
  int m_size; // edx
  int v23; // ebx
  int v24; // edi
  int v25; // eax
  unsigned int *m_data; // r9
  int m_capacityAndFlags; // r8d
  __int64 v28; // rbx
  int v29; // r9d
  __int64 v30; // rcx
  unsigned int *v31; // rdi
  hkArrayBase<hkVector4f> *p_m_vertices; // rax
  hkArray<int,hkContainerHeapAllocator> *v33; // rdi
  int v34; // ecx
  __m128 *v35; // r9
  int v36; // edx
  int v37; // r15d
  __int64 v38; // rsi
  __m128 v39; // xmm9
  hkArrayBase<int> *v40; // rax
  __int64 v41; // r8
  __int64 v42; // rdx
  int v43; // ecx
  int v44; // ebx
  __int64 v45; // r12
  __m128 v46; // xmm7
  __int64 v47; // r14
  __m128 v48; // xmm10
  __int64 v49; // r8
  int *v50; // rdi
  __int64 v51; // rdx
  __m128 m_quad; // xmm5
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm6
  int *v62; // rax
  __int64 v63; // rcx
  __int64 v64; // rdx
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __int64 v67; // rax
  __m128 v68; // xmm1
  _DWORD *v69; // rdi
  int v70; // [rsp+40h] [rbp-A0h] BYREF
  bool v71; // [rsp+44h] [rbp-9Ch]
  hkBitField array; // [rsp+48h] [rbp-98h] BYREF
  hkResult resulta[2]; // [rsp+60h] [rbp-80h] BYREF
  __int64 v74; // [rsp+68h] [rbp-78h]
  hkVector4f p; // [rsp+70h] [rbp-70h] BYREF
  hkSimdFloat32 hitFractionInOut; // [rsp+80h] [rbp-60h] BYREF
  hkVector4f rayEnd[4]; // [rsp+90h] [rbp-50h] BYREF
  hkVector4f rayStart[4]; // [rsp+D0h] [rbp-10h] BYREF
  hkaiRemoveUnreachableHitFilter v79; // [rsp+110h] [rbp+30h] BYREF
  _DWORD *v80; // [rsp+240h] [rbp+160h]
  __m128 *v81; // [rsp+248h] [rbp+168h]
  hkaiEdgeGeometry *retaddr; // [rsp+258h] [rbp+178h]
  hkArrayBase<int> *v85; // [rsp+270h] [rbp+190h]
  hkArrayBase<int> *tris; // [rsp+270h] [rbp+190h]

  v16 = LOBYTE(input[10].m_data) == 0;
  v70 = LODWORD(FLOAT_0_001);
  v71 = !v16;
  v17 = (hkaiEdgeGeometry *)walkableGeom;
  epsilon = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  m_size = v85->m_size;
  if ( !m_size )
  {
    LODWORD(result->vfptr) = 0;
    return result;
  }
  tris = v15;
  array.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  array.m_storage.m_words.m_data = 0i64;
  array.m_storage.m_words.m_size = 0;
  v23 = m_size / 3;
  v24 = (m_size / 3 + 31) >> 5;
  v25 = v24;
  if ( v24 )
  {
    v70 = 4 * v24;
    m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v70);
    v25 = v70 / 4;
  }
  else
  {
    m_data = 0i64;
  }
  m_capacityAndFlags = 0x80000000;
  array.m_storage.m_numBits = v23;
  if ( v25 )
    m_capacityAndFlags = v25;
  v28 = 4i64;
  array.m_storage.m_words.m_data = m_data;
  array.m_storage.m_words.m_size = v24;
  array.m_storage.m_words.m_capacityAndFlags = m_capacityAndFlags;
  *(_QWORD *)&resulta[0].m_enum = 4i64;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < v24 )
  {
    v29 = v24;
    if ( v24 < 2 * (m_capacityAndFlags & 0x3FFFFFFF) )
      v29 = 2 * (m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &array, v29, 4);
    m_capacityAndFlags = array.m_storage.m_words.m_capacityAndFlags;
    m_data = array.m_storage.m_words.m_data;
  }
  array.m_storage.m_words.m_size = v24;
  if ( !m_data )
  {
    LODWORD(result->vfptr) = 1;
    array.m_storage.m_words.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * m_capacityAndFlags);
    return result;
  }
  if ( v24 - 1 >= 0 )
  {
    v30 = (unsigned int)v24;
    v31 = m_data;
    while ( v30 )
    {
      *v31++ = 0;
      --v30;
    }
  }
  p_m_vertices = &v17->m_vertices;
  if ( !v17 )
    p_m_vertices = (hkArrayBase<hkVector4f> *)triConnectivityInOut;
  v33 = (hkArray<int,hkContainerHeapAllocator> *)tris;
  p.m_quad.m128_u64[0] = (unsigned __int64)p_m_vertices;
  hkaiRemoveUnreachableHitFilter::hkaiRemoveUnreachableHitFilter(
    &v79,
    p_m_vertices,
    v17,
    trisInOut,
    input,
    tris,
    &array,
    epsilon.m128_f32[0]);
  hkaiRemoveUnreachableHitFilter::init(&v79, (hkResult *)&p.m_quad.m128_u16[4]);
  if ( p.m_quad.m128_i32[2] )
  {
    LODWORD(result->vfptr) = 1;
    hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(&v79);
    array.m_storage.m_words.m_size = 0;
    if ( array.m_storage.m_words.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_storage.m_words.m_data,
        4 * array.m_storage.m_words.m_capacityAndFlags);
    return result;
  }
  hkaiEdgeGeometryRaycaster::setupForRemoveUnreachableTriangles(cuttingGeomRaycaster);
  hkaiEdgeGeometryRaycaster::setHitFilter(cuttingGeomRaycaster, &v79);
  v34 = input->m_size;
  v35 = v81;
  v36 = 0;
  v37 = 0;
  v38 = 0i64;
  v39 = _mm_shuffle_ps((__m128)v81->m128_u32[0], (__m128)v81->m128_u32[0], 0);
  v70 = 0;
  if ( v34 > 0 )
  {
    v40 = input;
    v41 = 12i64;
    v74 = 12i64;
    while ( 1 )
    {
      if ( materials && originalFaceIndices )
      {
        (*((void (__fastcall **)(hkArrayBase<int> *, __int64, _QWORD, _QWORD, hkArrayBase<int> *))materials->m_data + 1))(
          materials,
          5i64,
          (unsigned int)v36,
          (unsigned int)v34,
          originalFaceIndices);
        v35 = v81;
        v41 = v74;
        v40 = input;
      }
      v42 = *(unsigned int *)((char *)v40->m_data + v28 - 4);
      v43 = v17
          ? *(unsigned int *)((char *)&v17->m_faces.m_data->m_faceIndex + v41)
          : *(int *)((char *)trisInOut->m_data + v28);
      cuttingGeomRaycaster->m_ignoreFaceIndex = v43;
      v44 = __ROL4__(1, v37);
      if ( (int)v42 > 0 )
        break;
LABEL_50:
      v40 = input;
      v34 = input->m_size;
      v35 = v81;
      v36 = v70 + 1;
      v41 += 12i64;
      v28 = *(_QWORD *)&resulta[0].m_enum + 4i64;
      v70 = v36;
      v74 = v41;
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
      p.m_quad = _mm_add_ps(
                   *(__m128 *)(*(_QWORD *)p.m_quad.m128_u64[0] + 16i64 * *v50),
                   *(__m128 *)(*(_QWORD *)p.m_quad.m128_u64[0] + 16i64 * v50[1]));
      m_quad = _mm_mul_ps(_mm_add_ps(p.m_quad, *(__m128 *)(v49 + 8 * v51)), (__m128)xmmword_141A711C0);
      p.m_quad = m_quad;
      if ( v71 )
      {
        v53 = *(__m128 *)(v49 + 16i64 * *v50);
        v54 = _mm_sub_ps(*(__m128 *)(v49 + 16i64 * v50[1]), v53);
        v55 = _mm_sub_ps(*(__m128 *)(v49 + 16i64 * v50[2]), v53);
        v56 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v54), _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v55));
        v57 = _mm_shuffle_ps(v56, v56, 201);
        v58 = _mm_mul_ps(v57, v57);
        v59 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                _mm_shuffle_ps(v58, v58, 170));
        v60 = _mm_rsqrt_ps(v59);
        v61 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v59, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v59), v60)),
                    _mm_mul_ps(*(__m128 *)_xmm, v60))),
                v57);
      }
      else
      {
        v61 = v35[1];
      }
      rayStart[0].m_quad = _mm_add_ps(_mm_mul_ps(v61, v48), m_quad);
      rayEnd[0].m_quad = _mm_add_ps(_mm_mul_ps(v61, v39), m_quad);
      if ( !trisPerFaceInOut )
        goto LABEL_43;
      v62 = trisPerFaceInOut->m_data;
      if ( trisPerFaceInOut->m_data[v38] < 0 )
        goto LABEL_43;
      hitFractionInOut.m_real = query.m_quad;
      if ( !hkaiEdgeGeometryRaycaster::raycastAgainstFace(
              cuttingGeomRaycaster,
              v62[v38],
              rayStart,
              rayEnd,
              &hitFractionInOut) )
        break;
LABEL_47:
      array.m_storage.m_words.m_data[(__int64)v37 >> 5] |= v44;
LABEL_48:
      v44 = __ROL4__(v44, 1);
      v35 = v81;
      v33 = (hkArray<int,hkContainerHeapAllocator> *)tris;
      ++v37;
      ++v38;
      v47 += 3i64;
      if ( !--v45 )
      {
        v41 = v74;
        v17 = retaddr;
        goto LABEL_50;
      }
    }
    m_quad = p.m_quad;
LABEL_43:
    v63 = 0i64;
    v64 = *(_QWORD *)p.m_quad.m128_u64[0];
    v65 = _mm_mul_ps(v61, epsilon);
    v66 = _mm_mul_ps(_mm_sub_ps(v39, epsilon), v61);
    do
    {
      ++v63;
      v67 = 2i64 * *v50++;
      v68 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)(v64 + 8 * v67), m_quad), v46), m_quad), v65);
      rayStart[v63] = (hkVector4f)v68;
      rayEnd[v63].m_quad = _mm_add_ps(v66, v68);
    }
    while ( v63 <= 2 );
    if ( !hkaiEdgeGeometryRaycaster::castRayBundle(cuttingGeomRaycaster, rayStart, rayEnd, STOP_BUNDLE_ON_HIT)
      && !hkaiCarverTree::carversContainPoint(result, &p) )
    {
      goto LABEL_48;
    }
    goto LABEL_47;
  }
LABEL_51:
  hkaiNavMeshGenerationUtils::_removeTriangles(&array, v33, walkableGeom, tree, trianglesPerFace, trisPerFaceInOut);
  hkaiEdgeGeometryRaycaster::setHitFilter(cuttingGeomRaycaster, 0i64);
  v69 = v80;
  *v80 = 0;
  hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(&v79);
  array.m_storage.m_words.m_size = 0;
  if ( array.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_storage.m_words.m_data,
      4 * array.m_storage.m_words.m_capacityAndFlags);
  return (hkaiCarverTree *)v69;
}

// File Line: 2022
// RVA: 0xB79180
hkSimdFloat32 *__fastcall calcArea(hkSimdFloat32 *result, hkaiNavMesh *mesh, hkaiNavMesh::Edge *edges, int numEdges)
{
  __m128 v4; // xmm3
  hkaiNavMesh::Edge *v5; // r10
  hkVector4f *m_data; // rdx
  __int64 m_a; // rax
  __m128 m_quad; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  hkSimdFloat32 *v11; // rax

  v4 = 0i64;
  v5 = &edges[numEdges];
  if ( edges != v5 )
  {
    m_data = mesh->m_vertices.m_data;
    do
    {
      m_a = edges->m_a;
      ++edges;
      m_quad = m_data[edges[-1].m_b].m_quad;
      v9 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), m_data[m_a].m_quad),
             _mm_mul_ps(_mm_shuffle_ps(m_data[m_a].m_quad, m_data[m_a].m_quad, 201), m_quad));
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
hkResult *__fastcall findUniqueEdgeLoop(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkaiNavMesh::Face *face,
        hkArray<int,hkContainerHeapAllocator> *vertexMap,
        hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *dstEdges,
        hkArray<int,hkContainerTempAllocator> *edgeIndices)
{
  hkArray<int,hkContainerTempAllocator> *v6; // rbx
  int v7; // r12d
  int v8; // edi
  char *v10; // r10
  __int64 m_numEdges; // rbx
  char *v12; // r11
  int v15; // r8d
  int v16; // r15d
  int v17; // r9d
  int v18; // r9d
  hkResultEnum m_enum; // eax
  __int64 m_startEdgeIndex; // rax
  hkResultEnum v22; // r14d
  __int64 v23; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  __int64 v25; // r13
  __int64 p_m_oppositeFace; // rsi
  int v27; // ebx
  __int64 v28; // rax
  int v29; // ecx
  hkArray<int,hkContainerTempAllocator> *v30; // r15
  __int32 v31; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v32; // rdi
  __int64 m_size; // rdx
  __int64 v34; // r8
  hkResultEnum v35; // eax
  hkArray<int,hkContainerTempAllocator> *v36; // rbx
  hkResult *v37; // rbx
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v38; // r12
  int v39; // ebx
  __int64 v40; // rsi
  hkaiNavMesh::Edge *v41; // r8
  __int64 v42; // rax
  int v43; // r9d
  int v44; // eax
  int v45; // eax
  hkaiNavMesh::Edge *v46; // rdx
  hkaiNavMesh::Edge *v47; // r8
  __int64 v48; // rcx
  int m_a; // eax
  int v50; // eax
  int v51; // eax
  int v52; // r9d
  hkArray<int,hkContainerTempAllocator> *v53; // r15
  __int64 v54; // rdi
  int v55; // r9d
  int v56; // eax
  int v57; // eax
  int *v58; // rcx
  int *v59; // rdx
  __int64 v60; // r8
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // r9d
  __int64 v65; // r12
  int v66; // r9d
  hkResultEnum v67; // r13d
  __int64 v68; // rax
  float v69; // xmm6_4
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> *v70; // rdi
  __int64 v71; // r15
  __int64 v72; // rbx
  hkResultEnum v73; // r14d
  hkaiNavMesh::Edge *v74; // r8
  __int64 v75; // rax
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
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  int v89; // [rsp+34h] [rbp-CCh]
  int v90; // [rsp+38h] [rbp-C8h]
  hkResult v91; // [rsp+3Ch] [rbp-C4h] BYREF
  char *v92; // [rsp+40h] [rbp-C0h]
  char *array; // [rsp+50h] [rbp-B0h] BYREF
  int v94; // [rsp+58h] [rbp-A8h]
  int v95; // [rsp+5Ch] [rbp-A4h]
  char v96[128]; // [rsp+60h] [rbp-A0h] BYREF
  char *v97; // [rsp+E0h] [rbp-20h] BYREF
  int v98; // [rsp+E8h] [rbp-18h]
  int v99; // [rsp+ECh] [rbp-14h]
  char v100[128]; // [rsp+F0h] [rbp-10h] BYREF
  hkSimdFloat32 v101; // [rsp+170h] [rbp+70h] BYREF
  hkaiNavMesh::Face *v104; // [rsp+1F0h] [rbp+F0h] BYREF
  hkArray<int,hkContainerHeapAllocator> *v105; // [rsp+1F8h] [rbp+F8h]

  v105 = vertexMap;
  v104 = face;
  v6 = edgeIndices;
  v7 = 0;
  v8 = -2147483616;
  v10 = v100;
  dstEdges->m_size = 0;
  v6->m_size = 0;
  m_numEdges = face->m_numEdges;
  v12 = v96;
  v15 = 0;
  v94 = 0;
  v89 = -2147483616;
  array = v96;
  v95 = -2147483616;
  v92 = v100;
  v97 = v100;
  v98 = 0;
  v16 = -2147483616;
  v90 = -2147483616;
  v99 = -2147483616;
  if ( (int)m_numEdges < 32 )
    goto LABEL_20;
  if ( (int)m_numEdges <= 32 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v17 = m_numEdges;
    if ( (int)m_numEdges < 64 )
      v17 = 64;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v17, 4);
    v8 = v95;
    v16 = v99;
    v10 = v97;
    v12 = array;
    v89 = v95;
    v90 = v99;
    v92 = v97;
  }
  if ( (v16 & 0x3FFFFFFF) >= (int)m_numEdges )
  {
    m_enum = HK_SUCCESS;
    v91.m_enum = HK_SUCCESS;
  }
  else
  {
    v18 = m_numEdges;
    if ( (int)m_numEdges < 2 * (v16 & 0x3FFFFFFF) )
      v18 = 2 * (v16 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v91, &hkContainerHeapAllocator::s_alloc, &v97, v18, 4);
    v8 = v95;
    v16 = v99;
    v10 = v97;
    v12 = array;
    m_enum = v91.m_enum;
    v89 = v95;
    v90 = v99;
    v92 = v97;
  }
  if ( resulta.m_enum == HK_SUCCESS && m_enum == HK_SUCCESS )
  {
    vertexMap = v105;
    v15 = v94;
LABEL_20:
    m_startEdgeIndex = face->m_startEdgeIndex;
    v22 = HK_SUCCESS;
    resulta.m_enum = -1;
    v23 = m_startEdgeIndex;
    m_data = mesh->m_edges.m_data;
    v25 = m_numEdges;
    if ( (int)m_numEdges <= 0 )
      goto LABEL_113;
    p_m_oppositeFace = (__int64)&m_data[v23].m_oppositeFace;
    do
    {
      v27 = vertexMap->m_data[*(int *)(p_m_oppositeFace - 12)];
      v91.m_enum = vertexMap->m_data[*(int *)(p_m_oppositeFace - 8)];
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
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
            v12 = array;
            v15 = v94;
          }
          *(_DWORD *)&v12[4 * v15] = v27;
          v29 = v98;
          ++v94;
          if ( v98 == (v99 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v97, 4);
            v29 = v98;
          }
          *(_DWORD *)&v97[4 * v29] = 1;
          ++v98;
        }
        else if ( (int)++*(_DWORD *)&v10[4 * v28] >= 2 )
        {
          resulta.m_enum = v22;
          ++v7;
        }
        v30 = edgeIndices;
        v31 = v22 + v104->m_startEdgeIndex;
        if ( edgeIndices->m_size == (edgeIndices->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, edgeIndices, 4);
        v30->m_data[v30->m_size] = v31;
        v32 = dstEdges;
        ++v30->m_size;
        if ( v32->m_size == (v32->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v32, 20);
        m_size = v32->m_size;
        vertexMap = v105;
        v34 = (__int64)&v32->m_data[m_size];
        v32->m_size = m_size + 1;
        *(_DWORD *)v34 = *(_DWORD *)(p_m_oppositeFace - 12);
        *(_DWORD *)(v34 + 4) = *(_DWORD *)(p_m_oppositeFace - 8);
        *(_DWORD *)(v34 + 8) = *(_DWORD *)(p_m_oppositeFace - 4);
        *(_DWORD *)(v34 + 12) = *(_DWORD *)p_m_oppositeFace;
        *(_BYTE *)(v34 + 16) = *(_BYTE *)(p_m_oppositeFace + 4);
        *(_BYTE *)(v34 + 17) = *(_BYTE *)(p_m_oppositeFace + 5);
        *(_WORD *)(v34 + 18) = *(_WORD *)(p_m_oppositeFace + 6);
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
      p_m_oppositeFace += 20i64;
      --v25;
    }
    while ( v25 );
    v92 = v10;
    v90 = v16;
    v89 = v8;
    if ( resulta.m_enum < HK_SUCCESS )
    {
LABEL_113:
      v37 = result;
      v98 = 0;
      result->m_enum = HK_SUCCESS;
      if ( v16 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 4 * v16);
        v8 = v95;
        v12 = array;
      }
      v97 = 0i64;
      v99 = 0x80000000;
      v94 = 0;
      if ( v8 < 0 )
        return v37;
    }
    else
    {
      if ( v7 > 1 )
      {
        v36 = edgeIndices;
        v98 = 0;
        dstEdges->m_size = 0;
        v36->m_size = 0;
        v37 = result;
        result->m_enum = HK_SUCCESS;
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
        v99 = 0x80000000;
        v94 = 0;
        if ( v8 >= 0 )
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkArray<int,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            v12,
            (unsigned int)(4 * v8),
            vertexMap);
        return v37;
      }
      v38 = dstEdges;
      v39 = 0;
      v40 = dstEdges->m_size;
      if ( (int)v40 > 0 )
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
          if ( *(int *)&v10[4 * v42] > 1 )
            break;
          ++v39;
          ++v41;
        }
        while ( v39 < (int)v40 );
        if ( v39 > 0 )
        {
          v43 = v40 + v39;
          v44 = dstEdges->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v44 < (int)v40 + v39 )
          {
            v45 = 2 * v44;
            if ( v43 < v45 )
              v43 = v45;
            hkArrayUtil::_reserve((hkResult *)&v104, &hkContainerTempAllocator::s_alloc, dstEdges, v43, 20);
          }
          v46 = v38->m_data;
          v38->m_size += v39;
          v47 = &v46[v40];
          if ( 5 * v39 > 0 )
          {
            v48 = (unsigned int)(5 * v39);
            do
            {
              m_a = v46->m_a;
              v47 = (hkaiNavMesh::Edge *)((char *)v47 + 4);
              v46 = (hkaiNavMesh::Edge *)((char *)v46 + 4);
              *(_DWORD *)&v47[-1].m_flags.m_storage = m_a;
              --v48;
            }
            while ( v48 );
          }
          hkString::memMove(v38->m_data, &v38->m_data[v39], 20 * v40);
          v50 = v38->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v50 < (int)v40 )
          {
            v51 = 2 * v50;
            v52 = v40;
            if ( (int)v40 < v51 )
              v52 = v51;
            hkArrayUtil::_reserve((hkResult *)&v104, &hkContainerTempAllocator::s_alloc, v38, v52, 20);
          }
          v53 = edgeIndices;
          v38->m_size = v40;
          v54 = v53->m_size;
          v55 = v54 + v39;
          v56 = v53->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v56 < (int)v54 + v39 )
          {
            v57 = 2 * v56;
            if ( v55 < v57 )
              v55 = v57;
            hkArrayUtil::_reserve((hkResult *)&v104, &hkContainerTempAllocator::s_alloc, v53, v55, 4);
          }
          v58 = v53->m_data;
          v53->m_size += v39;
          v59 = &v58[v54];
          v60 = (unsigned int)v39;
          do
          {
            v61 = *v58;
            ++v59;
            ++v58;
            *(v59 - 1) = v61;
            --v60;
          }
          while ( v60 );
          hkString::memMove(v53->m_data, &v53->m_data[v39], 4 * v40);
          v62 = v53->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v62 < (int)v40 )
          {
            v63 = 2 * v62;
            v64 = v40;
            if ( (int)v40 < v63 )
              v64 = v63;
            hkArrayUtil::_reserve((hkResult *)&v104, &hkContainerTempAllocator::s_alloc, v53, v64, 4);
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
      v67 = HK_SUCCESS;
      v68 = 0i64;
      resulta.m_enum = -1;
      v69 = 0.0 - 1.0;
      LODWORD(v104) = -1;
      if ( v65 <= 0 )
        goto LABEL_110;
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
            if ( (int)v71 <= 0 )
            {
LABEL_84:
              v75 = -1i64;
            }
            else
            {
              while ( *(_DWORD *)&v12[4 * v75] != v74->m_a )
              {
                if ( ++v75 >= v71 )
                  goto LABEL_84;
              }
            }
            if ( *(int *)&v10[4 * v75] > 1 )
              break;
            ++v72;
            ++v73;
            ++v74;
          }
          while ( v72 < v65 );
        }
        if ( v73 - v67 > 1 )
        {
          calcArea(&v101, mesh, &v70->m_data[v67], v73 - v67);
          if ( v101.m_real.m128_f32[0] <= v69 )
          {
            v66 = (int)v104;
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
LABEL_110:
        v87 = edgeIndices;
        v98 = 0;
        dstEdges->m_size = 0;
        v87->m_size = 0;
        v37 = result;
        result->m_enum = HK_SUCCESS;
        if ( v16 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v92, 4 * v16);
          v8 = v95;
          v12 = array;
        }
        v97 = 0i64;
        v99 = 0x80000000;
        v94 = 0;
      }
      else
      {
        if ( resulta.m_enum <= HK_SUCCESS )
        {
          v81 = v92;
          v82 = edgeIndices;
        }
        else
        {
          v76 = resulta.m_enum;
          v77 = dstEdges->m_data;
          v78 = &dstEdges->m_data[resulta.m_enum];
          if ( 5 * (int)v104 <= 0 )
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
          v66 = (int)v104;
          if ( (int)v104 > 0 )
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
        v37 = result;
        v98 = 0;
        result->m_enum = HK_SUCCESS;
        if ( v16 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v81, 4 * v16);
          v8 = v95;
          v12 = array;
        }
        v97 = 0i64;
        v99 = 0x80000000;
        v94 = 0;
      }
      if ( v8 < 0 )
        return v37;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 4 * v8);
    return v37;
  }
  v98 = 0;
  result->m_enum = HK_FAILURE;
  if ( v16 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 4 * v16);
    v8 = v95;
    v12 = array;
  }
  v97 = 0i64;
  v99 = 0x80000000;
  v94 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 4 * v8);
  return result;
}
      }
      if ( v8 < 0 )
        return v37;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 4 * v8);
    return v37;
  }
  v98 = 0;
  result->m_enum = HK_FAILURE;
  if ( v16 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 4 * v16);
    v8 = v95;
    v12 = array;
  }
  v97 = 0i64;
  v99 = 0x80000000;
  v94 = 0;
  if 

// File Line: 2218
// RVA: 0xB760D0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_mergeVertices(hkResult *result, hkaiNavMesh *mesh, float threshold)
{
  hkVector4f v3; // xmm3
  __int64 m_size; // rdi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *p_m_vertices; // r13
  hkaiNavMesh *v7; // rsi
  __int64 v9; // r12
  hkVector4f v10; // xmm2
  __m128 *m_data; // rax
  __int64 v12; // rcx
  __int64 v13; // r14
  __m128 v14; // xmm1
  int v15; // r8d
  int m_capacityAndFlags; // r8d
  int SizeInBytesFor; // eax
  int v18; // ebx
  int v19; // r9d
  int v20; // r8d
  __int64 v21; // rdi
  hkVector4f *v22; // rsi
  int Closest; // ebx
  int v24; // ecx
  int v25; // ebx
  int v26; // eax
  int v27; // ecx
  int v28; // r9d
  int *v29; // rdi
  __int64 v30; // rcx
  __int64 v31; // rax
  __int64 v32; // r12
  __int64 v33; // r13
  hkaiNavMesh::Face *v34; // rbx
  int v35; // ecx
  hkaiNavMesh::Face *v36; // rbx
  int v37; // r9d
  int v38; // r9d
  hkResultEnum m_enum; // eax
  int v40; // r14d
  int v41; // esi
  int v42; // eax
  __int64 v43; // r9
  int v44; // ecx
  __int64 v45; // rdi
  char *v46; // rdx
  int v47; // r8d
  char *v48; // rdi
  __int64 v49; // r10
  int v50; // edx
  __int64 v51; // rcx
  char *v52; // rcx
  char *v53; // rcx
  int v54; // ecx
  hkResultEnum v55; // edi
  hkaiNavMesh::Edge *v56; // r8
  hkaiNavMesh::Edge *i; // rdi
  unsigned int v58; // edx
  int v59; // eax
  int v60; // r8d
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+40h] [rbp-C0h] BYREF
  hkArray<int,hkContainerTempAllocator> buffer; // [rsp+50h] [rbp-B0h] BYREF
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v65; // [rsp+60h] [rbp-A0h] BYREF
  hkArray<int,hkContainerHeapAllocator> array; // [rsp+70h] [rbp-90h] BYREF
  hkArray<hkaiNavMesh::Edge,hkContainerTempAllocator> dstEdges; // [rsp+80h] [rbp-80h] BYREF
  hkResult resultOut; // [rsp+90h] [rbp-70h] BYREF
  hkResult v69; // [rsp+94h] [rbp-6Ch] BYREF
  hkResult v70; // [rsp+98h] [rbp-68h] BYREF
  hkResult v71; // [rsp+9Ch] [rbp-64h] BYREF
  __int64 v72; // [rsp+A0h] [rbp-60h]
  hkAabb aabbIn; // [rsp+B0h] [rbp-50h] BYREF
  hkFindClosestPositionUtil v74; // [rsp+D0h] [rbp-30h] BYREF
  hkaiNavMesh *v75; // [rsp+208h] [rbp+108h] BYREF
  hkResult resulta; // [rsp+218h] [rbp+118h] BYREF

  v75 = mesh;
  v3.m_quad = (__m128)xmmword_141A712A0;
  m_size = mesh->m_vertices.m_size;
  p_m_vertices = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&mesh->m_vertices;
  v7 = mesh;
  aabbIn.m_min = (hkVector4f)xmmword_141A712A0;
  v9 = m_size;
  v10.m_quad = _mm_xor_ps(
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                 (__m128)xmmword_141A712A0);
  aabbIn.m_max = (hkVector4f)v10.m_quad;
  if ( (int)m_size > 0 )
  {
    m_data = (__m128 *)p_m_vertices->m_data;
    v12 = m_size;
    do
    {
      v3.m_quad = _mm_min_ps(v3.m_quad, *m_data++);
      aabbIn.m_min = (hkVector4f)v3.m_quad;
      v10.m_quad = _mm_max_ps(v10.m_quad, m_data[-1]);
      aabbIn.m_max = (hkVector4f)v10.m_quad;
      --v12;
    }
    while ( v12 );
  }
  v13 = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  resulta.m_enum = LODWORD(FLOAT_0_1);
  array.m_data = 0i64;
  array.m_size = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  aabbIn.m_max.m_quad = _mm_add_ps(v10.m_quad, v14);
  aabbIn.m_min.m_quad = _mm_sub_ps(v3.m_quad, v14);
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_7;
    }
  }
  array.m_size = m_size;
  a.m_data = 0i64;
  a.m_size = 0;
  a.m_capacityAndFlags = 0x80000000;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &a, m_size, 16);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = a.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      a.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          a.m_data,
          16 * m_capacityAndFlags);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 0x80000000;
LABEL_7:
      v15 = array.m_capacityAndFlags;
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        goto LABEL_125;
      return result;
    }
  }
  buffer.m_data = 0i64;
  buffer.m_size = 0;
  buffer.m_capacityAndFlags = 0x80000000;
  SizeInBytesFor = hkFindClosestPositionUtil::getSizeInBytesFor(m_size);
  v18 = SizeInBytesFor;
  if ( (buffer.m_capacityAndFlags & 0x3FFFFFFF) >= SizeInBytesFor )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v19 = SizeInBytesFor;
    if ( SizeInBytesFor < 2 * (buffer.m_capacityAndFlags & 0x3FFFFFFF) )
      v19 = 2 * (buffer.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &buffer, v19, 1);
    if ( resulta.m_enum )
    {
      v20 = buffer.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      buffer.m_size = 0;
      if ( v20 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          buffer.m_data,
          v20 & 0x3FFFFFFF);
      buffer.m_data = 0i64;
      buffer.m_capacityAndFlags = 0x80000000;
      a.m_size = 0;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          a.m_data,
          16 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 0x80000000;
LABEL_123:
      array.m_size = 0;
      goto LABEL_124;
    }
  }
  buffer.m_size = v18;
  hkFindClosestPositionUtil::hkFindClosestPositionUtil(&v74);
  hkFindClosestPositionUtil::start(&v74, &aabbIn, threshold);
  hkFindClosestPositionUtil::setBuffer(&v74, buffer.m_data, m_size);
  v21 = 0i64;
  if ( v9 <= 0 )
  {
LABEL_32:
    hkFindClosestPositionUtil::end(&v74);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v74.m_hashMap.m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v74.m_hashMap);
    hkFreeList::freeAllMemory(&v74.m_boxFreeList);
    v74.m_positions.m_size = 0;
    if ( v74.m_positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v74.m_positions.m_data,
        16 * v74.m_positions.m_capacityAndFlags);
    v74.m_positions.m_data = 0i64;
    v74.m_positions.m_capacityAndFlags = 0x80000000;
    buffer.m_size = 0;
    if ( buffer.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        buffer.m_data,
        buffer.m_capacityAndFlags & 0x3FFFFFFF);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(p_m_vertices, &a);
    a.m_size = 0;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        a.m_data,
        16 * a.m_capacityAndFlags);
    v25 = v7->m_edges.m_size;
    facesToRemove.m_data = 0i64;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 0x80000000;
    v65.m_data = 0i64;
    v65.m_size = 0;
    v65.m_capacityAndFlags = 0x80000000;
    if ( v25 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v65, v25, 20);
      if ( resulta.m_enum )
      {
        result->m_enum = HK_FAILURE;
LABEL_41:
        v65.m_size = 0;
        if ( v65.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v65.m_data,
            20 * (v65.m_capacityAndFlags & 0x3FFFFFFF));
        v65.m_data = 0i64;
        v65.m_capacityAndFlags = 0x80000000;
LABEL_120:
        facesToRemove.m_size = 0;
        if ( facesToRemove.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            facesToRemove.m_data,
            4 * facesToRemove.m_capacityAndFlags);
        facesToRemove.m_data = 0i64;
        facesToRemove.m_capacityAndFlags = 0x80000000;
        goto LABEL_123;
      }
    }
    v26 = 0;
    a.m_data = 0i64;
    a.m_capacityAndFlags = 0x80000000;
    a.m_size = 0;
    if ( v25 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &a, v25, 4);
      if ( resulta.m_enum )
      {
        result->m_enum = HK_FAILURE;
LABEL_54:
        a.m_size = 0;
        if ( a.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            a.m_data,
            4 * a.m_capacityAndFlags);
        a.m_data = 0i64;
        a.m_capacityAndFlags = 0x80000000;
        goto LABEL_41;
      }
      v26 = a.m_size;
    }
    v27 = a.m_capacityAndFlags & 0x3FFFFFFF;
    if ( (a.m_capacityAndFlags & 0x3FFFFFFF) < v25 )
    {
      v28 = v25;
      if ( v25 < 2 * v27 )
        v28 = 2 * v27;
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &a, v28, 4);
      v26 = a.m_size;
    }
    v29 = &a.m_data->m_fromOffset + v26;
    v30 = v25 - v26;
    if ( v25 - v26 > 0 )
    {
      while ( v30 )
      {
        *v29++ = -1;
        --v30;
      }
    }
    v31 = v7->m_faces.m_size;
    a.m_size = v25;
    resulta.m_enum = HK_SUCCESS;
    v32 = 0i64;
    v72 = v31;
    if ( v31 <= 0 )
    {
LABEL_99:
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v7->m_edges,
        &v65);
      v56 = v7->m_edges.m_data;
      for ( i = &v56[v7->m_edges.m_size]; v56 != i; ++v56 )
      {
        if ( v56->m_oppositeEdge != -1 )
        {
          v58 = *(&a.m_data->m_fromOffset + (int)v56->m_oppositeEdge);
          v56->m_oppositeEdge = v58;
          if ( v58 == -1 )
            v56->m_oppositeFace = -1;
        }
      }
      a.m_size = 0;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          a.m_data,
          4 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      a.m_capacityAndFlags = 0x80000000;
      v65.m_size = 0;
      if ( v65.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v65.m_data,
          20 * (v65.m_capacityAndFlags & 0x3FFFFFFF));
      result->m_enum = facesToRemove.m_size > 0
                    && (hkaiNavMeshUtils::removeFaces((hkResult *)&v75, v7, &facesToRemove, 1), (_DWORD)v75);
      goto LABEL_120;
    }
    v33 = 0i64;
    while ( 1 )
    {
      v34 = v7->m_faces.m_data;
      v35 = 0x80000000;
      buffer.m_data = 0i64;
      v36 = &v34[v33];
      buffer.m_size = 0;
      buffer.m_capacityAndFlags = 0x80000000;
      dstEdges.m_data = 0i64;
      dstEdges.m_size = 0;
      dstEdges.m_capacityAndFlags = 0x80000000;
      v37 = 2 * v36->m_numEdges;
      if ( v37 <= 0 )
      {
        v69.m_enum = HK_SUCCESS;
      }
      else
      {
        if ( (v36->m_numEdges & 0x40000000) != 0 )
          v37 = 0;
        hkArrayUtil::_reserve(&v69, &hkContainerTempAllocator::s_alloc, &buffer, v37, 4);
        v35 = dstEdges.m_capacityAndFlags;
      }
      v38 = 2 * v36->m_numEdges;
      if ( (v35 & 0x3FFFFFFF) >= v38 )
      {
        m_enum = HK_SUCCESS;
        resultOut.m_enum = HK_SUCCESS;
      }
      else
      {
        if ( v38 < 2 * (v35 & 0x3FFFFFFF) )
          v38 = 2 * (v35 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&resultOut, &hkContainerTempAllocator::s_alloc, &dstEdges, v38, 20);
        v35 = dstEdges.m_capacityAndFlags;
        m_enum = resultOut.m_enum;
      }
      if ( v69.m_enum || m_enum )
        break;
      findUniqueEdgeLoop(&v70, v7, v36, &array, &dstEdges, &buffer);
      if ( v70.m_enum )
      {
        v59 = dstEdges.m_capacityAndFlags;
        result->m_enum = HK_FAILURE;
        dstEdges.m_size = 0;
        if ( v59 < 0 )
          goto LABEL_114;
        v60 = 5 * (v59 & 0x3FFFFFFF);
        goto LABEL_113;
      }
      v40 = v65.m_size;
      v36->m_startEdgeIndex = v65.m_size;
      v41 = dstEdges.m_size;
      v36->m_numEdges = dstEdges.m_size;
      v42 = v65.m_size;
      v43 = (unsigned int)(v65.m_size + v41);
      v44 = v65.m_capacityAndFlags & 0x3FFFFFFF;
      v45 = v65.m_size;
      if ( (v65.m_capacityAndFlags & 0x3FFFFFFF) >= (int)v43 )
      {
        v71.m_enum = HK_SUCCESS;
      }
      else
      {
        if ( (int)v43 < 2 * v44 )
          LODWORD(v43) = 2 * v44;
        hkArrayUtil::_reserve(&v71, &hkContainerHeapAllocator::s_alloc, &v65, v43, 20);
        v42 = v65.m_size;
      }
      v65.m_size = v41 + v42;
      v46 = (char *)v65.m_data + 20 * v45;
      v47 = 0;
      if ( v41 > 0 )
      {
        v43 = 0i64;
        v48 = v46 + 8;
        v49 = -8i64 - (_QWORD)v46;
        do
        {
          v50 = v47 + v40;
          ++v47;
          v51 = *(int *)((char *)buffer.m_data + v43);
          v43 += 4i64;
          *(&a.m_data->m_fromOffset + v51) = v50;
          v52 = &v48[v49];
          v48 += 20;
          v53 = (char *)dstEdges.m_data + (unsigned __int64)v52;
          *((_DWORD *)v48 - 7) = *(_DWORD *)v53;
          *((_DWORD *)v48 - 6) = *((_DWORD *)v53 + 1);
          *((_DWORD *)v48 - 5) = *((_DWORD *)v53 + 2);
          *((_DWORD *)v48 - 4) = *((_DWORD *)v53 + 3);
          *(v48 - 12) = v53[16];
          *(v48 - 11) = v53[17];
          *((_WORD *)v48 - 5) = *((_WORD *)v53 + 9);
        }
        while ( v47 < v41 );
      }
      if ( v36->m_numEdges > 1 )
      {
        v55 = resulta.m_enum;
      }
      else
      {
        v54 = facesToRemove.m_size;
        if ( facesToRemove.m_size == (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &facesToRemove, 4);
          v54 = facesToRemove.m_size;
        }
        v55 = resulta.m_enum;
        facesToRemove.m_data[v54] = resulta.m_enum;
        ++facesToRemove.m_size;
        if ( !v36->m_numEdges )
          v36->m_startEdgeIndex = -1;
      }
      dstEdges.m_size = 0;
      if ( dstEdges.m_capacityAndFlags >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMesh::Edge *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          dstEdges.m_data,
          20 * (dstEdges.m_capacityAndFlags & 0x3FFFFFFFu),
          v43);
      dstEdges.m_data = 0i64;
      dstEdges.m_capacityAndFlags = 0x80000000;
      buffer.m_size = 0;
      if ( buffer.m_capacityAndFlags >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          buffer.m_data,
          (unsigned int)(4 * buffer.m_capacityAndFlags),
          v43);
      v7 = v75;
      ++v32;
      ++v33;
      buffer.m_data = 0i64;
      buffer.m_capacityAndFlags = 0x80000000;
      resulta.m_enum = v55 + 1;
      if ( v32 >= v72 )
        goto LABEL_99;
    }
    result->m_enum = HK_FAILURE;
    dstEdges.m_size = 0;
    if ( v35 >= 0 )
    {
      v60 = 5 * (v35 & 0x3FFFFFFF);
LABEL_113:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, dstEdges.m_data, 4 * v60);
    }
LABEL_114:
    dstEdges.m_data = 0i64;
    dstEdges.m_capacityAndFlags = 0x80000000;
    buffer.m_size = 0;
    if ( buffer.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        buffer.m_data,
        4 * buffer.m_capacityAndFlags);
    buffer.m_data = 0i64;
    buffer.m_capacityAndFlags = 0x80000000;
    goto LABEL_54;
  }
  while ( 1 )
  {
    v22 = (hkVector4f *)&p_m_vertices->m_data[v13];
    Closest = hkFindClosestPositionUtil::findClosest(&v74, v22);
    if ( Closest < 0 )
      break;
LABEL_30:
    ++v21;
    ++v13;
    array.m_data[v21 - 1] = Closest;
    if ( v21 >= v9 )
    {
      v7 = v75;
      goto LABEL_32;
    }
  }
  resultOut.m_enum = HK_SUCCESS;
  Closest = hkFindClosestPositionUtil::addPoint(&v74, v22, &resultOut);
  if ( resultOut.m_enum == HK_SUCCESS )
  {
    v24 = a.m_size;
    if ( a.m_size == (a.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &a, 16);
      v24 = a.m_size;
    }
    a.m_data[v24] = (hkRelocationInfo::Import)v22->m_quad;
    ++a.m_size;
    goto LABEL_30;
  }
  result->m_enum = HK_FAILURE;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v74.m_hashMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v74.m_hashMap);
  hkFreeList::freeAllMemory(&v74.m_boxFreeList);
  v74.m_positions.m_size = 0;
  if ( v74.m_positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v74.m_positions.m_data,
      16 * v74.m_positions.m_capacityAndFlags);
  v74.m_positions.m_data = 0i64;
  v74.m_positions.m_capacityAndFlags = 0x80000000;
  buffer.m_size = 0;
  if ( buffer.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buffer.m_data,
      buffer.m_capacityAndFlags & 0x3FFFFFFF);
  buffer.m_data = 0i64;
  buffer.m_capacityAndFlags = 0x80000000;
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      a.m_data,
      16 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  a.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
LABEL_124:
  v15 = array.m_capacityAndFlags;
  if ( array.m_capacityAndFlags >= 0 )
LABEL_125:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array.m_data, 4 * v15);
  return result;
}

// File Line: 2385
// RVA: 0xB76CE0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_removeDegenerateFaces(hkResult *result, hkSimdFloat32 *mesh)
{
  __int64 v2; // rdi
  __int64 v5; // rsi
  unsigned int v6; // ebx
  __int64 v7; // rdi
  __int64 m_size; // rcx
  hkVector4f *sizeElem; // [rsp+20h] [rbp-40h]
  hkArray<int,hkContainerTempAllocator> array; // [rsp+30h] [rbp-30h] BYREF
  int faceIndex; // [rsp+40h] [rbp-20h] BYREF
  hkaiNavMeshUtils v13; // [rsp+50h] [rbp-10h] BYREF
  hkResult resulta; // [rsp+98h] [rbp+38h] BYREF

  v2 = mesh[1].m_real.m128_i32[2];
  array.m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  if ( (int)v2 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v2, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_19;
    }
  }
  v5 = v2;
  v6 = 0;
  if ( (int)v2 > 0 )
  {
    v7 = 0i64;
    while ( *(__int16 *)(mesh[1].m_real.m128_u64[0] + v7 + 8) > 2 )
    {
      if ( COERCE_FLOAT(*hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                           &v13,
                           mesh,
                           (hkaiNavMesh *)v6,
                           (int)&faceIndex,
                           sizeElem)) == 0.0 )
      {
        LODWORD(m_size) = array.m_size;
        if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
          LODWORD(m_size) = array.m_size;
        }
        m_size = (int)m_size;
        goto LABEL_14;
      }
LABEL_15:
      ++v6;
      v7 += 16i64;
      if ( !--v5 )
        goto LABEL_16;
    }
    if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
    m_size = array.m_size;
LABEL_14:
    array.m_data[m_size] = v6;
    ++array.m_size;
    goto LABEL_15;
  }
LABEL_16:
  hkaiNavMeshUtils::removeFaces(&resulta, (hkaiNavMesh *)mesh, &array, 1);
  if ( resulta.m_enum )
    result->m_enum = HK_FAILURE;
  else
    result->m_enum = HK_SUCCESS;
LABEL_19:
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
  return result;
}

// File Line: 2421
// RVA: 0xB729F0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(
        hkResult *result,
        hkaiNavMesh *navMesh,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometryRaycaster *raycaster,
        hkaiNavMeshGenerationProgressCallback *callbacks)
{
  char m_storage; // al
  int m_capacityAndFlags; // r8d
  hkaiNavMeshGenerationResult::GenerationResultEnum v11; // eax
  hkaiNavMeshGenerationSettings::RegionPruningSettings pruneSettings; // [rsp+20h] [rbp-28h] BYREF
  hkResult resulta; // [rsp+60h] [rbp+18h] BYREF

  if ( input->m_minCharacterWidth <= 0.0 )
    goto LABEL_15;
  m_storage = input->m_characterWidthUsage.m_storage;
  if ( (m_storage & 2) == 0 )
  {
    if ( (m_storage & 1) != 0 )
    {
      hkaiNavMeshGenerationUtils::_blockUntraversableEdges(&resulta, navMesh, input, raycaster);
      if ( resulta.m_enum )
        goto LABEL_4;
    }
    goto LABEL_15;
  }
  hkaiNavMeshGenerationUtils::_blockUntraversableEdges(&resulta, navMesh, input, raycaster);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(&pruneSettings);
    hkaiNavMeshGenerationSettings::RegionPruningSettings::operator=(&pruneSettings, &input->m_regionPruningSettings);
    pruneSettings.m_borderPreservationTolerance = 0.0;
    hkaiNavMeshGenerationUtils::_pruneRegions(&resulta, navMesh, &input->m_up, &pruneSettings);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = pruneSettings.m_regionSeedPoints.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      pruneSettings.m_regionSeedPoints.m_size = 0;
      if ( m_capacityAndFlags < 0 )
        return result;
LABEL_7:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pruneSettings.m_regionSeedPoints.m_data,
        16 * m_capacityAndFlags);
      return result;
    }
    v11 = hkaiNavMeshErosion::erode(navMesh, input, raycaster, callbacks);
    m_capacityAndFlags = pruneSettings.m_regionSeedPoints.m_capacityAndFlags;
    pruneSettings.m_regionSeedPoints.m_size = 0;
    if ( v11 != GENERATION_SUCCESS )
    {
      result->m_enum = HK_FAILURE;
      if ( m_capacityAndFlags < 0 )
        return result;
      goto LABEL_7;
    }
    if ( pruneSettings.m_regionSeedPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pruneSettings.m_regionSeedPoints.m_data,
        16 * pruneSettings.m_regionSeedPoints.m_capacityAndFlags);
LABEL_15:
    result->m_enum = HK_SUCCESS;
    return result;
  }
LABEL_4:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 2459
// RVA: 0xB73450
hkResult *__fastcall hkaiNavMeshGenerationUtils::_pruneTriangles(
        hkResult *result,
        hkGeometry *triMeshIn,
        hkaiNavMeshGenerationSettings *settings,
        hkBitField *walkableInOut)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm6
  __int64 m_size; // r10
  __int64 v7; // r14
  float m_maxStepHeight; // xmm4_4
  float m_maxSeparation; // xmm2_4
  float *p_m_maxSeparation; // rax
  hkResultEnum v15; // xmm0_4
  hkFixedArray<int> v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  int v20; // r8d
  __m128 v21; // xmm7
  __m128 m_quad; // xmm5
  int v23; // r8d
  __int64 v25; // rsi
  int v26; // ebx
  __int64 v27; // rdi
  hkVector4f *m_data; // rdx
  hkGeometry::Triangle *v29; // rcx
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  hkVector4f v33; // xmm1
  hkVector4f v34; // xmm2
  int v35; // r12d
  __int64 v36; // rdx
  int v37; // esi
  int v38; // r8d
  hkResultEnum m_enum; // eax
  hkLifoAllocator *Value; // rax
  int *m_cur; // rcx
  int v42; // ebx
  char *v43; // rdx
  unsigned int m_slotID; // ecx
  hkLifoAllocator *v45; // rax
  int v46; // r8d
  hk1AxisSweep::AabbInt *v47; // rdi
  int v48; // r12d
  int v49; // ebx
  __int64 v50; // rcx
  unsigned int v51; // r8d
  hk1AxisSweep::AabbInt *v52; // rdx
  __int64 v53; // rcx
  unsigned int v54; // r8d
  hk1AxisSweep::AabbInt *v55; // rdx
  hkResult *v56; // rsi
  int *v57; // rdi
  signed int v58; // ebx
  hkLifoAllocator *v59; // rax
  int v60; // r8d
  unsigned int *v61; // rbx
  int m_capacityAndFlags; // r8d
  hkResultEnum v63; // edi
  __m128 m_minDistanceToSeedPoints_low; // xmm0
  __int64 v65; // rdx
  __int64 v66; // rsi
  int v67; // r12d
  unsigned int *v68; // r14
  __m128 v69; // xmm9
  __m128 v70; // xmm8
  bool v71; // di
  int v72; // r14d
  __int64 v73; // r10
  hkVector4f v74; // xmm14
  int v75; // edx
  hkVector4f v76; // xmm15
  __m128 v77; // xmm7
  __int64 v78; // r9
  unsigned int *v79; // r11
  __int64 v80; // rcx
  __int64 v81; // r8
  __int64 v82; // rdx
  __int64 v83; // rcx
  __m128 v84; // xmm6
  __int64 v85; // rax
  __m128 v86; // xmm10
  __int64 v87; // rax
  __m128 v88; // xmm5
  __m128 v89; // xmm11
  __m128 v90; // xmm1
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  __m128 v93; // xmm2
  __m128 v94; // xmm4
  __m128 v95; // xmm1
  hkVector4f *v96; // rcx
  __m128 v97; // xmm15
  __int64 v98; // rdx
  __m128 v99; // xmm13
  __m128 v100; // xmm12
  __m128 v101; // xmm14
  __m128 v102; // xmm1
  __m128 v103; // xmm6
  __m128 v104; // xmm6
  __m128 v105; // xmm8
  __m128 v106; // xmm9
  __m128 v107; // xmm7
  __m128 v108; // xmm10
  __m128 v109; // xmm4
  __m128 v110; // xmm2
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  __m128 v113; // xmm3
  __m128 v114; // xmm4
  __m128 v115; // xmm1
  __m128 v116; // xmm3
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm0
  __m128 v123; // xmm5
  __m128 v124; // xmm4
  __m128 v125; // xmm1
  __m128 v126; // xmm3
  __m128 v127; // xmm2
  __m128 v128; // xmm5
  __m128 v129; // xmm2
  __m128 v130; // xmm3
  __m128 v131; // xmm5
  __m128 v132; // xmm0
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm2
  __m128 v136; // xmm0
  __m128 v137; // xmm2
  __m128 v138; // xmm7
  __m128 v139; // xmm4
  __m128 v140; // xmm9
  __m128 v141; // xmm10
  __m128 v142; // xmm1
  __m128 v143; // xmm5
  __m128 v144; // xmm5
  __m128 v145; // xmm1
  __m128 v146; // xmm4
  __m128 v147; // xmm2
  __m128 v148; // xmm0
  __m128 v149; // xmm2
  __m128 v150; // xmm2
  bool v151; // bl
  bool isRegionNearBoundary; // al
  __int64 v153; // rbx
  int v154; // r11d
  int v155; // edi
  int v156; // r8d
  hkBitField *v157; // rbx
  __int64 v158; // r9
  __int64 v159; // r10
  int *m_storage; // rdi
  signed int v161; // ebx
  hkLifoAllocator *v162; // rax
  int v163; // r8d
  hk1AxisSweep::AabbInt *array; // [rsp+30h] [rbp-A0h] BYREF
  int size; // [rsp+38h] [rbp-98h]
  int v166; // [rsp+3Ch] [rbp-94h]
  hkResult resulta; // [rsp+40h] [rbp-90h] BYREF
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+48h] [rbp-88h] BYREF
  hkResult v169; // [rsp+58h] [rbp-78h] BYREF
  int v170; // [rsp+5Ch] [rbp-74h]
  hkFixedArray<int> parents; // [rsp+60h] [rbp-70h] BYREF
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > sortedAabbs; // [rsp+70h] [rbp-60h] BYREF
  int v173; // [rsp+88h] [rbp-48h]
  hkAabb aabbIn; // [rsp+90h] [rbp-40h] BYREF
  hkAabb meshAabb; // [rsp+B0h] [rbp-20h] BYREF
  __m128 v176; // [rsp+D0h] [rbp+0h]
  hkUnionFind v177; // [rsp+E0h] [rbp+10h] BYREF
  __m128 v178; // [rsp+100h] [rbp+30h]
  __m128 v179; // [rsp+110h] [rbp+40h]
  __m128i v180; // [rsp+120h] [rbp+50h] BYREF
  __m128 v181; // [rsp+130h] [rbp+60h]
  __m128 v182; // [rsp+140h] [rbp+70h]
  __m128 v183; // [rsp+150h] [rbp+80h]
  __m128 v184; // [rsp+160h] [rbp+90h]
  __m128 v185; // [rsp+170h] [rbp+A0h]
  __m128 v186; // [rsp+180h] [rbp+B0h]
  hkVector4f expansion; // [rsp+190h] [rbp+C0h] BYREF
  __m128 v188; // [rsp+1A0h] [rbp+D0h]
  hkResult *v189; // [rsp+2A0h] [rbp+1D0h]
  __int64 i; // [rsp+2A8h] [rbp+1D8h]
  hkResult v191; // [rsp+2B0h] [rbp+1E0h] BYREF
  hkBitField *v192; // [rsp+2B8h] [rbp+1E8h]

  m_size = settings->m_overrideSettings.m_size;
  v7 = triMeshIn->m_triangles.m_size;
  m_maxStepHeight = settings->m_edgeMatchingParams.m_maxStepHeight;
  m_maxSeparation = settings->m_edgeMatchingParams.m_maxSeparation;
  if ( m_size > 0 )
  {
    p_m_maxSeparation = &settings->m_overrideSettings.m_data->m_edgeMatchingParams.m_maxSeparation;
    do
    {
      v15 = *((_DWORD *)p_m_maxSeparation - 1);
      resulta.m_enum = LODWORD(m_maxStepHeight);
      p_m_maxSeparation += 60;
      v191.m_enum = v15;
      v4.m128_f32[0] = *(p_m_maxSeparation - 60);
      m_maxStepHeight = fmaxf(m_maxStepHeight, *(float *)&v191.m_enum);
      v191.m_enum = LODWORD(m_maxSeparation);
      resulta.m_enum = v4.m128_i32[0];
      v4 = (__m128)v4.m128_u32[0];
      m_maxSeparation = fmaxf(m_maxSeparation, v4.m128_f32[0]);
      --m_size;
    }
    while ( m_size );
  }
  if ( settings->m_wallClimbingSettings.m_enableWallClimbing.m_bool )
  {
    v191.m_enum = LODWORD(m_maxStepHeight);
    resulta.m_enum = LODWORD(m_maxSeparation);
    v5.m128_f32[0] = fmaxf(m_maxStepHeight, m_maxSeparation);
    v16 = (hkFixedArray<int>)_mm_shuffle_ps(v5, v5, 0);
  }
  else
  {
    v4.m128_f32[0] = m_maxSeparation;
    v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&settings->m_up), 1u), 1u);
    parents = (hkFixedArray<int>)_mm_shuffle_ps(v4, v4, 0);
    *((float *)&parents.m_data.m_storage
    + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                             _mm_and_ps(
                                                               _mm_cmple_ps(
                                                                 _mm_max_ps(
                                                                   _mm_shuffle_ps(v17, v17, 170),
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v17, v17, 85),
                                                                     _mm_shuffle_ps(v17, v17, 0))),
                                                                 v17),
                                                               (__m128)xmmword_141A4D050))]) = m_maxStepHeight;
    v16 = parents;
  }
  v18 = (__m128)xmmword_141A712A0;
  v19 = _mm_mul_ps((__m128)v16, (__m128)xmmword_141A711B0);
  v166 = 0x80000000;
  meshAabb.m_min = (hkVector4f)xmmword_141A712A0;
  array = 0i64;
  v20 = 0;
  size = 0;
  v21 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v180 = (__m128i)v21;
  m_quad = _mm_xor_ps(v21, (__m128)xmmword_141A712A0);
  meshAabb.m_max.m_quad = m_quad;
  if ( (int)v7 + 4 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v7 + 4, 32);
    if ( resulta.m_enum )
    {
      v23 = v166;
      size = 0;
      result->m_enum = HK_FAILURE;
      if ( v23 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v23);
      return result;
    }
    m_quad = meshAabb.m_max.m_quad;
    v18 = meshAabb.m_min.m_quad;
    v20 = size;
    walkableInOut = v192;
  }
  v25 = v7;
  v26 = 0;
  if ( (int)v7 > 0 )
  {
    v27 = 0i64;
    do
    {
      if ( ((walkableInOut->m_storage.m_words.m_data[(__int64)v26 >> 5] >> (v26 & 0x1F)) & 1) != 0 )
      {
        m_data = triMeshIn->m_vertices.m_data;
        v29 = triMeshIn->m_triangles.m_data;
        v30 = m_data[v29[v27].m_b].m_quad;
        v31 = _mm_min_ps(_mm_min_ps(m_data[v29[v27].m_a].m_quad, v30), m_data[v29[v27].m_c].m_quad);
        v32 = _mm_max_ps(_mm_max_ps(m_data[v29[v27].m_a].m_quad, v30), m_data[v29[v27].m_c].m_quad);
        size = v20 + 1;
        aabbIn.m_min.m_quad = _mm_sub_ps(v31, v19);
        aabbIn.m_max.m_quad = _mm_add_ps(v32, v19);
        meshAabb.m_min.m_quad = _mm_min_ps(v18, aabbIn.m_min.m_quad);
        meshAabb.m_max.m_quad = _mm_max_ps(m_quad, aabbIn.m_max.m_quad);
        hk1AxisSweep::AabbInt::set(&array[v20], &aabbIn, v26);
        v20 = size;
        walkableInOut = v192;
        m_quad = meshAabb.m_max.m_quad;
        v18 = meshAabb.m_min.m_quad;
      }
      ++v26;
      ++v27;
      --v25;
    }
    while ( v25 );
    result = v189;
  }
  v33.m_quad = (__m128)settings->m_boundsAabb.m_max;
  v34.m_quad = (__m128)settings->m_boundsAabb.m_min;
  if ( (_mm_movemask_ps(_mm_cmple_ps(v33.m_quad, v34.m_quad)) & 7) == 0 )
  {
    aabbIn.m_min.m_quad = v18;
    meshAabb.m_min.m_quad = _mm_max_ps(v18, v34.m_quad);
    meshAabb.m_max.m_quad = _mm_min_ps(m_quad, v33.m_quad);
  }
  v35 = v20;
  v173 = v20;
  v36 = 4i64;
  while ( 1 )
  {
    size = v20 + 1;
    array[v20].m_min[0] = -1;
    if ( !--v36 )
      break;
    v20 = size;
  }
  v37 = 0;
  sortedAabbs.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  sortedAabbs.m_storage.m_words.m_data = 0i64;
  sortedAabbs.m_storage.m_words.m_size = 0;
  if ( v35 + 4 <= 0 )
  {
    v191.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v191, &hkContainerTempAllocator::s_alloc, &sortedAabbs, v35 + 4, 32);
    if ( v191.m_enum )
    {
      result->m_enum = HK_FAILURE;
LABEL_38:
      sortedAabbs.m_storage.m_words.m_size = 0;
      if ( sortedAabbs.m_storage.m_words.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_storage.m_words.m_data,
          32 * sortedAabbs.m_storage.m_words.m_capacityAndFlags);
      sortedAabbs.m_storage.m_words.m_data = 0i64;
      sortedAabbs.m_storage.m_words.m_capacityAndFlags = 0x80000000;
      goto LABEL_56;
    }
  }
  v38 = 0x80000000;
  sortedAabbs.m_storage.m_words.m_size = v35 + 4;
  *(_QWORD *)&elementsPerGroup.m_size = 0i64;
  v169.m_enum = HK_SUCCESS;
  v170 = 0x80000000;
  if ( v35 + 4 <= 0 )
  {
    m_enum = HK_SUCCESS;
    goto LABEL_33;
  }
  hkArrayUtil::_reserve(&v169, &hkContainerHeapAllocator::s_alloc, &elementsPerGroup.m_size, v35 + 4, 8);
  m_enum = v169.m_enum;
  v38 = v170;
  if ( v169.m_enum == HK_SUCCESS )
LABEL_33:
    v169.m_enum = v35 + 4;
  v191.m_enum = m_enum;
  if ( m_enum )
  {
    v169.m_enum = HK_SUCCESS;
    result->m_enum = HK_FAILURE;
    if ( v38 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&elementsPerGroup.m_size,
        8 * v38);
    *(_QWORD *)&elementsPerGroup.m_size = 0i64;
    v170 = 0x80000000;
    goto LABEL_38;
  }
  hk1AxisSweep::sortAabbs(
    array,
    v35,
    (hkArrayBase<hkRadixSort::SortData32> *)&elementsPerGroup.m_size,
    (hkArrayBase<hk1AxisSweep::AabbInt> *)&sortedAabbs);
  v169.m_enum = HK_SUCCESS;
  if ( v170 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&elementsPerGroup.m_size,
      8 * v170);
  *(_QWORD *)&elementsPerGroup.m_size = 0i64;
  v170 = 0x80000000;
  sortedAabbs.m_storage.m_words.m_size = 0;
  if ( sortedAabbs.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      sortedAabbs.m_storage.m_words.m_data,
      32 * sortedAabbs.m_storage.m_words.m_capacityAndFlags);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v42 = (4 * v7 + 127) & 0xFFFFFF80;
  v43 = (char *)m_cur + v42;
  if ( v42 > Value->m_slabSize || v43 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v42);
  else
    Value->m_cur = v43;
  parents.m_data.m_storage = m_cur;
  parents.m_size.m_storage = v7;
  if ( (int)v7 > 0 && !m_cur )
  {
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    result->m_enum = HK_FAILURE;
    v45 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v46 = (v42 + 15) & 0xFFFFFFF0;
    if ( v42 <= v45->m_slabSize && (void *)v46 == v45->m_cur && v45->m_firstNonLifoEnd )
      v45->m_cur = 0i64;
    else
      hkLifoAllocator::slowBlockFree(v45, 0i64, v46);
LABEL_56:
    size = 0;
    if ( v166 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v166);
    return result;
  }
  hkUnionFind::hkUnionFind(&v177, &parents, v7);
  v47 = array;
  v48 = v35 - 1;
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_size = 0;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
  parents.m_data.m_storage = 0i64;
  parents.m_size.m_storage = 0;
  *((_DWORD *)&parents.m_size + 1) = 0x80000000;
  v177.m_isCollapsed = 0;
  v49 = 1;
  if ( v48 > 0 )
  {
    while ( 1 )
    {
      v50 = v37;
      v51 = array[v50].m_max[0];
      v52 = &array[v49];
      if ( v52->m_min[0] <= v51 )
        break;
LABEL_63:
      v49 = ++v37 + 1;
      if ( v37 >= v48 )
        goto LABEL_64;
    }
    while ( (((v52->m_max[2] - array[v50].m_min[2]) | (v52->m_max[1] - array[v50].m_min[1]) | (array[v50].m_max[2]
                                                                                             - v52->m_min[2]) | (array[v50].m_max[1] - v52->m_min[1])) & 0x80000000) != 0 )
    {
      v52 = &array[++v49];
      if ( v52->m_min[0] > v51 )
        goto LABEL_63;
    }
  }
LABEL_64:
  while ( v37 < v48 )
  {
    hkUnionFind::addEdge(&v177, *(_DWORD *)v47[v37].m_expansionMin, *(_DWORD *)v47[v49++].m_expansionMin);
    if ( v37 >= v48 )
      break;
    while ( 1 )
    {
      v53 = v37;
      v54 = v47[v53].m_max[0];
      v55 = &v47[v49];
      if ( v55->m_min[0] <= v54 )
        break;
LABEL_69:
      v49 = ++v37 + 1;
      if ( v37 >= v48 )
        goto LABEL_72;
    }
    while ( (((v55->m_max[2] - v47[v53].m_min[2]) | (v55->m_max[1] - v47[v53].m_min[1]) | (v47[v53].m_max[2]
                                                                                         - v55->m_min[2]) | (v47[v53].m_max[1] - v55->m_min[1])) & 0x80000000) != 0 )
    {
      v55 = &v47[++v49];
      if ( v55->m_min[0] > v54 )
        goto LABEL_69;
    }
  }
LABEL_72:
  hkUnionFind::assignGroups(&v177, &v191, &elementsPerGroup);
  if ( v191.m_enum
    || (hkUnionFind::sortByGroupId(&v177, &v169, &elementsPerGroup, (hkArray<int,hkContainerHeapAllocator> *)&parents),
        v169.m_enum) )
  {
    v56 = v189;
    v189->m_enum = HK_FAILURE;
  }
  else
  {
    v61 = (unsigned int *)elementsPerGroup.m_size;
    sortedAabbs.m_storage.m_words.m_data = 0i64;
    sortedAabbs.m_storage.m_words.m_size = 0;
    sortedAabbs.m_storage.m_words.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_storage.m_numBits = 0;
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
      &sortedAabbs,
      &v191,
      0,
      elementsPerGroup.m_size,
      0);
    if ( v191.m_enum )
    {
      v56 = v189;
      m_capacityAndFlags = sortedAabbs.m_storage.m_words.m_capacityAndFlags;
      sortedAabbs.m_storage.m_words.m_size = 0;
      v189->m_enum = HK_FAILURE;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          sortedAabbs.m_storage.m_words.m_data,
          4 * m_capacityAndFlags);
      sortedAabbs.m_storage.m_words.m_data = 0i64;
      sortedAabbs.m_storage.m_words.m_capacityAndFlags = 0x80000000;
    }
    else
    {
      v63 = HK_SUCCESS;
      v191.m_enum = HK_SUCCESS;
      hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(
        &settings->m_regionPruningSettings,
        &settings->m_up,
        &expansion);
      m_minDistanceToSeedPoints_low = (__m128)LODWORD(settings->m_regionPruningSettings.m_minDistanceToSeedPoints);
      v65 = 0i64;
      v169.m_enum = HK_SUCCESS;
      v66 = 0i64;
      v184 = _mm_shuffle_ps(m_minDistanceToSeedPoints_low, m_minDistanceToSeedPoints_low, 0);
      sortedAabbs.m_storage.m_words.m_data = v61;
      v67 = 1;
      *(_QWORD *)&elementsPerGroup.m_size = 0i64;
      v68 = v61;
      if ( (int)v61 > 0 )
      {
        do
        {
          v69 = (__m128)xmmword_141A712A0;
          v70 = aabbOut.m_quad;
          v71 = settings->m_regionPruningSettings.m_regionSeedPoints.m_size == 0;
          v72 = 0;
          v73 = settings->m_regionPruningSettings.m_regionSeedPoints.m_size;
          v74.m_quad = _mm_xor_ps(v21, (__m128)xmmword_141A712A0);
          aabbIn.m_min = (hkVector4f)xmmword_141A712A0;
          aabbIn.m_max = (hkVector4f)v74.m_quad;
          v75 = elementsPerGroup.m_data[v65];
          v76.m_quad = (__m128)xmmword_141A712A0;
          v77 = aabbOut.m_quad;
          if ( v75 > 0 )
          {
            v78 = (unsigned int)v75;
            v79 = v192->m_storage.m_words.m_data;
            do
            {
              v80 = parents.m_data.m_storage[v66++];
              if ( ((v79[v80 >> 5] >> (v80 & 0x1F)) & 1) != 0 )
              {
                v81 = 2 * v80;
                ++v72;
                v82 = *(_QWORD *)(i + 16);
                v83 = *(_QWORD *)(i + 32);
                v84 = *(__m128 *)(v82 + 16i64 * *(int *)(v83 + 8 * v81));
                v85 = 2i64 * *(int *)(v83 + 8 * v81 + 4);
                v176 = v84;
                v86 = *(__m128 *)(v82 + 8 * v85);
                v87 = 2i64 * *(int *)(v83 + 8 * v81 + 8);
                v188 = v86;
                v89 = _mm_sub_ps(v86, v84);
                v179 = *(__m128 *)(v82 + 8 * v87);
                v88 = v179;
                v76.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v76.m_quad, v84), v86), v179);
                v74.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v74.m_quad, v84), v86), v179);
                v185 = v76.m_quad;
                aabbIn.m_min = (hkVector4f)v76.m_quad;
                v90 = _mm_sub_ps(v179, v84);
                v181 = v74.m_quad;
                aabbIn.m_max = (hkVector4f)v74.m_quad;
                v91 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v89),
                        _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v90));
                v92 = _mm_shuffle_ps(v91, v91, 201);
                v93 = _mm_mul_ps(v92, v92);
                v94 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                        _mm_shuffle_ps(v93, v93, 170));
                v95 = _mm_rsqrt_ps(v94);
                v77 = _mm_add_ps(
                        v77,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v94, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v95, v94), v95)),
                              _mm_mul_ps(*(__m128 *)_xmm, v95)),
                            v94)));
                v183 = v77;
                if ( !v71 && v73 > 0 )
                {
                  v96 = settings->m_regionPruningSettings.m_regionSeedPoints.m_data;
                  v97 = v84;
                  v98 = v73;
                  v99 = _mm_sub_ps(v84, v179);
                  v100 = _mm_sub_ps(v179, v86);
                  v101 = _mm_shuffle_ps(v100, v100, 201);
                  v178 = _mm_shuffle_ps(v70, _mm_unpackhi_ps(v70, (__m128)xmmword_141A712F0), 196);
                  v182 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, v69), 196);
                  v102 = _mm_shuffle_ps(v89, v89, 201);
                  v186 = v102;
                  v103 = _mm_sub_ps(_mm_mul_ps(v101, v89), _mm_mul_ps(v102, v100));
                  v104 = _mm_shuffle_ps(v103, v103, 201);
                  v176 = _mm_shuffle_ps(v99, v99, 201);
                  do
                  {
                    v105 = v96->m_quad;
                    v106 = _mm_sub_ps(v96->m_quad, v86);
                    v107 = _mm_sub_ps(v96->m_quad, v97);
                    v108 = _mm_sub_ps(v96->m_quad, v88);
                    v109 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v89), _mm_mul_ps(v102, v107));
                    v110 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v106, v106, 201), v100), _mm_mul_ps(v101, v106));
                    v111 = _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v104);
                    v112 = _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v104);
                    v113 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v108, v108, 201), v99), _mm_mul_ps(v176, v108));
                    v114 = _mm_unpackhi_ps(v111, v112);
                    v115 = _mm_unpacklo_ps(v111, v112);
                    v116 = _mm_mul_ps(_mm_shuffle_ps(v113, v113, 201), v104);
                    v117 = _mm_movelh_ps(v115, v116);
                    if ( (_mm_movemask_ps(
                            _mm_cmplt_ps(
                              v178,
                              _mm_add_ps(
                                _mm_shuffle_ps(v114, v116, 228),
                                _mm_add_ps(v117, _mm_shuffle_ps(_mm_movehl_ps(v117, v115), v116, 212))))) & 7) == 7 )
                    {
                      v118 = _mm_mul_ps(v104, v104);
                      v119 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                               _mm_shuffle_ps(v118, v118, 170));
                      v120 = _mm_mul_ps(v104, v107);
                      v121 = _mm_sub_ps(
                               v105,
                               _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmpeq_ps(v119, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_rcp_ps(v119),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v120, v120, 85), _mm_shuffle_ps(v120, v120, 0)),
                                       _mm_shuffle_ps(v120, v120, 170)))),
                                 v104));
                    }
                    else
                    {
                      v122 = _mm_mul_ps(v100, v100);
                      v123 = _mm_mul_ps(v89, v89);
                      v124 = _mm_mul_ps(v107, v89);
                      v125 = _mm_unpacklo_ps(v123, v122);
                      v126 = _mm_mul_ps(v99, v99);
                      v127 = _mm_movelh_ps(v125, v126);
                      v128 = _mm_shuffle_ps(_mm_unpackhi_ps(v123, v122), v126, 228);
                      v129 = _mm_add_ps(v127, _mm_shuffle_ps(_mm_movehl_ps(v127, v125), v126, 212));
                      v130 = _mm_mul_ps(v108, v99);
                      v131 = _mm_add_ps(v128, v129);
                      v132 = _mm_mul_ps(v106, v100);
                      v133 = _mm_unpacklo_ps(v124, v132);
                      v134 = _mm_movelh_ps(v133, v130);
                      v135 = _mm_andnot_ps(
                               _mm_cmpeq_ps(v131, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_rcp_ps(v131),
                                 _mm_add_ps(
                                   _mm_shuffle_ps(_mm_unpackhi_ps(v124, v132), v130, 228),
                                   _mm_add_ps(v134, _mm_shuffle_ps(_mm_movehl_ps(v134, v133), v130, 212)))));
                      v136 = _mm_cmplt_ps(v135, v182);
                      v137 = _mm_max_ps(v178, _mm_or_ps(_mm_and_ps(v136, v135), _mm_andnot_ps(v136, v182)));
                      v138 = _mm_sub_ps(v107, _mm_mul_ps(_mm_shuffle_ps(v137, v137, 0), v89));
                      v139 = _mm_mul_ps(v138, v138);
                      v140 = _mm_sub_ps(v106, _mm_mul_ps(_mm_shuffle_ps(v137, v137, 85), v100));
                      v141 = _mm_sub_ps(v108, _mm_mul_ps(_mm_shuffle_ps(v137, v137, 170), v99));
                      v142 = _mm_mul_ps(v140, v140);
                      v143 = _mm_cmplt_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
                                 _mm_shuffle_ps(v139, v139, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                                 _mm_shuffle_ps(v142, v142, 170)));
                      v144 = _mm_or_ps(_mm_andnot_ps(v143, v140), _mm_and_ps(v143, v138));
                      v145 = _mm_mul_ps(v141, v141);
                      v146 = _mm_mul_ps(v144, v144);
                      v147 = _mm_cmplt_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v146, v146, 85), _mm_shuffle_ps(v146, v146, 0)),
                                 _mm_shuffle_ps(v146, v146, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                                 _mm_shuffle_ps(v145, v145, 170)));
                      v148 = _mm_or_ps(_mm_andnot_ps(v147, v141), _mm_and_ps(v144, v147));
                      v88 = v179;
                      v121 = _mm_sub_ps(v105, v148);
                    }
                    v86 = v188;
                    v149 = _mm_sub_ps(v121, v105);
                    v150 = _mm_mul_ps(v149, v149);
                    v102 = v186;
                    if ( (float)((float)(_mm_shuffle_ps(v150, v150, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v150, v150, 0).m128_f32[0])
                               + _mm_shuffle_ps(v150, v150, 170).m128_f32[0]) < v184.m128_f32[0] )
                      v71 = 1;
                    ++v96;
                    --v98;
                  }
                  while ( v98 );
                  v74.m_quad = v181;
                  v76.m_quad = v185;
                  v77 = v183;
                  v70 = aabbOut.m_quad;
                  v69 = (__m128)xmmword_141A712A0;
                }
              }
              --v78;
            }
            while ( v78 );
          }
          aabbIn.m_max.m_quad = _mm_add_ps(v74.m_quad, expansion.m_quad);
          aabbIn.m_min.m_quad = _mm_sub_ps(v76.m_quad, expansion.m_quad);
          v151 = (float)(v77.m128_f32[0] * 0.5) < settings->m_regionPruningSettings.m_minRegionArea;
          isRegionNearBoundary = hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(
                                   &aabbIn,
                                   &meshAabb);
          if ( !v151 && v71 )
          {
            v63 = v191.m_enum;
          }
          else
          {
            v63 = v191.m_enum;
            if ( !isRegionNearBoundary )
            {
              sortedAabbs.m_storage.m_words.m_data[(__int64)(int)v169.m_enum >> 5] |= v67;
              v63 += v72;
              v191.m_enum = v63;
            }
          }
          v67 = __ROL4__(v67, 1);
          v68 = sortedAabbs.m_storage.m_words.m_data;
          v21 = (__m128)_mm_load_si128(&v180);
          ++v169.m_enum;
          v65 = *(_QWORD *)&elementsPerGroup.m_size + 1i64;
          *(_QWORD *)&elementsPerGroup.m_size = v65;
        }
        while ( v65 < (__int64)sortedAabbs.m_storage.m_words.m_data );
      }
      if ( v63 != v173 )
      {
        v153 = 0i64;
        v154 = 0;
        v155 = 0;
        for ( i = 0i64; v153 < (__int64)v68; i = v153 )
        {
          v156 = elementsPerGroup.m_data[v153];
          if ( ((sortedAabbs.m_storage.m_words.m_data[(__int64)v155 >> 5] >> (v155 & 0x1F)) & 1) != 0 )
          {
            if ( v156 > 0 )
            {
              v157 = v192;
              v158 = v154;
              v159 = (unsigned int)v156;
              v154 += v156;
              do
              {
                ++v158;
                v157->m_storage.m_words.m_data[(__int64)parents.m_data.m_storage[v158 - 1] >> 5] &= ~(1 << (parents.m_data.m_storage[v158 - 1] & 0x1F));
                --v159;
              }
              while ( v159 );
              v153 = i;
            }
          }
          else
          {
            v154 += v156;
          }
          ++v153;
          ++v155;
        }
        v56 = v189;
        v189->m_enum = HK_SUCCESS;
        hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&sortedAabbs);
        parents.m_size.m_storage = 0;
        if ( *((int *)&parents.m_size + 1) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            parents.m_data.m_storage,
            4 * *((_DWORD *)&parents.m_size + 1));
        parents.m_data.m_storage = 0i64;
        *((_DWORD *)&parents.m_size + 1) = 0x80000000;
        elementsPerGroup.m_size = 0;
        if ( elementsPerGroup.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            elementsPerGroup.m_data,
            4 * elementsPerGroup.m_capacityAndFlags);
        m_storage = parents.m_data.m_storage;
        elementsPerGroup.m_data = 0i64;
        elementsPerGroup.m_capacityAndFlags = 0x80000000;
        v161 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
        v162 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v163 = (v161 + 15) & 0xFFFFFFF0;
        if ( v161 > v162->m_slabSize || (char *)m_storage + v163 != v162->m_cur || v162->m_firstNonLifoEnd == m_storage )
          hkLifoAllocator::slowBlockFree(v162, m_storage, v163);
        else
          v162->m_cur = m_storage;
        size = 0;
        goto LABEL_129;
      }
      v56 = v189;
      v189->m_enum = HK_SUCCESS;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&sortedAabbs);
    }
  }
  parents.m_size.m_storage = 0;
  if ( *((int *)&parents.m_size + 1) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      parents.m_data.m_storage,
      4 * *((_DWORD *)&parents.m_size + 1));
  elementsPerGroup.m_size = 0;
  *((_DWORD *)&parents.m_size + 1) = 0x80000000;
  parents.m_data.m_storage = 0i64;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  v57 = parents.m_data.m_storage;
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
  v58 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v60 = (v58 + 15) & 0xFFFFFFF0;
  if ( v58 > v59->m_slabSize || (char *)v57 + v60 != v59->m_cur || v59->m_firstNonLifoEnd == v57 )
  {
    hkLifoAllocator::slowBlockFree(v59, v57, v60);
    size = 0;
  }
  else
  {
    v59->m_cur = v57;
    size = 0;
  }
LABEL_129:
  if ( v166 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v166);
  return v56;
}nerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  v57 = parents.m_data.m_storage;
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
  v58 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v59 = (hkLifoAllocator *)TlsGetValue(hkMemor

// File Line: 2681
// RVA: 0xB72B90
hkResult *__fastcall hkaiNavMeshGenerationUtils::_pruneRegions(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkVector4f *up,
        hkaiNavMeshGenerationSettings::RegionPruningSettings *pruneSettings)
{
  int m_size; // edi
  int v5; // r15d
  hkResult *v9; // r12
  int m_capacityAndFlags; // r8d
  int v11; // edx
  hkVector4f *m_data; // rcx
  __m128 v13; // xmm6
  int v14; // eax
  __int64 v15; // r14
  __int64 v16; // rdx
  __int64 v17; // rcx
  hkAabb *v18; // rax
  __m128 m_minDistanceToSeedPoints_low; // xmm6
  int v20; // edi
  float v21; // xmm6_4
  __int32 v22; // eax
  void *v23; // r9
  int v24; // r8d
  int v25; // r9d
  __int64 v26; // rcx
  int *v27; // rdi
  int v28; // eax
  __int64 v29; // rbx
  __int64 v30; // r12
  __int64 v31; // rdi
  __m128 *p_m_quad; // rax
  __int64 v33; // rcx
  __m128 v34; // xmm1
  int v35; // edi
  __int64 v36; // rbx
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  float m_minRegionArea; // xmm6_4
  int v40; // r15d
  int v41; // edi
  bool v42; // zf
  bool v43; // si
  bool isRegionNearBoundary; // al
  int v45; // r9d
  int v46; // edx
  int i; // edi
  hkAabb *sizeElem; // [rsp+20h] [rbp-E0h]
  hkArray<float,hkContainerHeapAllocator> areasOut; // [rsp+30h] [rbp-D0h] BYREF
  hkAabb *v51; // [rsp+40h] [rbp-C0h] BYREF
  int v52; // [rsp+48h] [rbp-B8h]
  int v53; // [rsp+4Ch] [rbp-B4h]
  hkArrayBase<int> array; // [rsp+50h] [rbp-B0h] BYREF
  _DWORD *v55; // [rsp+60h] [rbp-A0h] BYREF
  int v56; // [rsp+68h] [rbp-98h]
  int v57; // [rsp+6Ch] [rbp-94h]
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+70h] [rbp-90h] BYREF
  void *v59; // [rsp+80h] [rbp-80h] BYREF
  int v60; // [rsp+88h] [rbp-78h]
  int v61; // [rsp+8Ch] [rbp-74h]
  int v62; // [rsp+90h] [rbp-70h]
  hkErrStream v63; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v64; // [rsp+C0h] [rbp-40h]
  hkVector4f position; // [rsp+D0h] [rbp-30h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+E0h] [rbp-20h] BYREF
  __m128 v67; // [rsp+F0h] [rbp-10h]
  hkVector4f closestPointOut; // [rsp+100h] [rbp+0h] BYREF
  hkAabb aabbOut; // [rsp+110h] [rbp+10h] BYREF
  int faceIndex[4]; // [rsp+130h] [rbp+30h] BYREF
  char buf[512]; // [rsp+140h] [rbp+40h] BYREF
  hkResult resulta; // [rsp+398h] [rbp+298h] BYREF
  int v74; // [rsp+3A8h] [rbp+2A8h]

  m_size = mesh->m_faces.m_size;
  v5 = 0;
  v9 = result;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = array.m_capacityAndFlags;
      v9->m_enum = HK_FAILURE;
      array.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          array.m_data,
          4 * m_capacityAndFlags);
      return v9;
    }
  }
  v11 = mesh->m_vertices.m_size;
  m_data = mesh->m_vertices.m_data;
  aabbOut.m_min = (hkVector4f)xmmword_141A712A0;
  array.m_size = m_size;
  v13 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  aabbOut.m_max.m_quad = _mm_xor_ps(v13, (__m128)xmmword_141A712A0);
  hkAabbUtil::calcAabb(m_data, v11, &aabbOut);
  areasOut.m_data = 0i64;
  areasOut.m_size = 0;
  areasOut.m_capacityAndFlags = 0x80000000;
  v14 = hkaiNavMeshUtils::computeRegions(mesh, 1, &array, &areasOut);
  v15 = v14;
  v74 = v14;
  if ( v14 != -1 )
  {
    if ( !v14 )
    {
      hkErrStream::hkErrStream(&v63, buf, 512);
      hkOstream::operator<<(&v63, "No regions found. Empty nav mesh?");
      hkError::messageWarning(640513734, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 2706);
      hkOstream::~hkOstream(&v63);
      v9->m_enum = HK_SUCCESS;
      goto LABEL_7;
    }
    v51 = 0i64;
    v52 = 0;
    v53 = 0x80000000;
    if ( v14 <= 0 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v51, v14, 32);
      if ( resulta.m_enum )
      {
        v9->m_enum = HK_FAILURE;
LABEL_15:
        v52 = 0;
        if ( v53 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v51, 32 * v53);
        v51 = 0i64;
        v53 = 0x80000000;
        goto LABEL_7;
      }
    }
    v52 = v15;
    v16 = v15;
    if ( (int)v15 > 0 )
    {
      v17 = 0i64;
      do
      {
        v18 = v51;
        v51[v17++].m_min = (hkVector4f)xmmword_141A712A0;
        v18[v17 - 1].m_max.m_quad = _mm_xor_ps(v13, (__m128)xmmword_141A712A0);
        --v16;
      }
      while ( v16 );
    }
    m_minDistanceToSeedPoints_low = (__m128)LODWORD(pruneSettings->m_minDistanceToSeedPoints);
    v59 = 0i64;
    v20 = ((int)v15 + 31) >> 5;
    v60 = 0;
    v61 = 0x80000000;
    m_minDistanceToSeedPoints_low.m128_f32[0] = _mm_shuffle_ps(
                                                  m_minDistanceToSeedPoints_low,
                                                  m_minDistanceToSeedPoints_low,
                                                  0).m128_f32[0];
    v21 = m_minDistanceToSeedPoints_low.m128_f32[0] * m_minDistanceToSeedPoints_low.m128_f32[0];
    v22 = v20;
    if ( v20 )
    {
      resulta.m_enum = 4 * v20;
      v23 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &resulta);
      v22 = resulta.m_enum / 4;
    }
    else
    {
      v23 = 0i64;
    }
    v24 = 0x80000000;
    v59 = v23;
    if ( v22 )
      v24 = v22;
    v60 = ((int)v15 + 31) >> 5;
    v62 = v15;
    v61 = v24;
    if ( (v24 & 0x3FFFFFFF) < v20 )
    {
      v25 = ((int)v15 + 31) >> 5;
      if ( v20 < 2 * (v24 & 0x3FFFFFFF) )
        v25 = 2 * (v24 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v59, v25, 4);
      v24 = v61;
      v23 = v59;
    }
    v60 = ((int)v15 + 31) >> 5;
    if ( !v23 )
    {
      v9->m_enum = HK_FAILURE;
      v60 = 0;
      if ( v24 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * v24);
      v59 = 0i64;
      v61 = 0x80000000;
      goto LABEL_15;
    }
    if ( v20 - 1 >= 0 )
    {
      v26 = (unsigned int)v20;
      v27 = (int *)v23;
      v28 = -(pruneSettings->m_regionSeedPoints.m_size <= 0);
      while ( v26 )
      {
        *v27++ = v28;
        --v26;
      }
    }
    hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(pruneSettings, up, (hkVector4f *)&v63);
    v29 = 0i64;
    if ( mesh->m_faces.m_size > 0 )
    {
      v30 = 0i64;
      do
      {
        v31 = array.m_data[v30];
        *(hkVector4f *)faceIndex = (hkVector4f)::aabbOut.m_quad;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>(
          (hkaiNavMeshUtils *)mesh,
          (hkaiNavMesh *)(unsigned int)v5,
          (int)faceIndex,
          &extraRadius,
          sizeElem);
        p_m_quad = &v51[v31].m_min.m_quad;
        v33 = v31 >> 5;
        LODWORD(v31) = v31 & 0x1F;
        v64 = v33;
        resulta.m_enum = (int)v31;
        v67 = _mm_add_ps(v67, (__m128)v63.hkReferencedObject);
        extraRadius.m_real = _mm_sub_ps(extraRadius.m_real, (__m128)v63.hkReferencedObject);
        v34 = p_m_quad[1];
        *p_m_quad = _mm_min_ps(*p_m_quad, extraRadius.m_real);
        p_m_quad[1] = _mm_max_ps(v34, v67);
        if ( ((*((_DWORD *)v59 + v33) >> v31) & 1) == 0 )
        {
          v35 = 0;
          if ( pruneSettings->m_regionSeedPoints.m_size > 0 )
          {
            v36 = 0i64;
            while ( 1 )
            {
              position.m_quad = (__m128)pruneSettings->m_regionSeedPoints.m_data[v36];
              closestPointOut.m_quad = position.m_quad;
              hkaiNavMeshUtils::getClosestPointOnFace(mesh, &position, v5, &closestPointOut);
              v37 = _mm_sub_ps(position.m_quad, closestPointOut.m_quad);
              v38 = _mm_mul_ps(v37, v37);
              if ( (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0] + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                         + _mm_shuffle_ps(v38, v38, 170).m128_f32[0]) < v21 )
                break;
              ++v35;
              ++v36;
              if ( v35 >= pruneSettings->m_regionSeedPoints.m_size )
                goto LABEL_48;
            }
            *((_DWORD *)v59 + v64) |= 1 << SLOBYTE(resulta.m_enum);
          }
        }
LABEL_48:
        ++v5;
        ++v30;
      }
      while ( v5 < mesh->m_faces.m_size );
      LODWORD(v15) = v74;
      v9 = result;
      v29 = 0i64;
    }
    v55 = 0i64;
    v56 = 0;
    v57 = 0x80000000;
    if ( (int)v15 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v55, v15, 4);
      if ( resulta.m_enum )
      {
        v9->m_enum = HK_FAILURE;
LABEL_82:
        v56 = 0;
        if ( v57 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v55, 4 * v57);
        v60 = 0;
        v57 = 0x80000000;
        v55 = 0i64;
        if ( v61 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v59, 4 * v61);
        v52 = 0;
        v61 = 0x80000000;
        v59 = 0i64;
        if ( v53 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v51, 32 * v53);
        areasOut.m_size = 0;
        v53 = 0x80000000;
        v51 = 0i64;
        if ( areasOut.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            areasOut.m_data,
            4 * areasOut.m_capacityAndFlags);
        array.m_size = 0;
        areasOut.m_data = 0i64;
        goto LABEL_91;
      }
    }
    m_minRegionArea = pruneSettings->m_minRegionArea;
    v56 = v15;
    v40 = 0;
    v41 = 0;
    v42 = (_DWORD)v15 == 0;
    if ( (int)v15 > 0 )
    {
      do
      {
        v43 = m_minRegionArea < areasOut.m_data[v29]
           && ((*((_DWORD *)v59 + ((__int64)v41 >> 5)) >> (v41 & 0x1F)) & 1) != 0;
        isRegionNearBoundary = hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(
                                 &v51[v41],
                                 &aabbOut);
        if ( v43 || isRegionNearBoundary )
        {
          v55[v29] = v40++;
        }
        else
        {
          LODWORD(v15) = v15 - 1;
          v55[v29] = -1;
        }
        ++v41;
        ++v29;
      }
      while ( v41 < v56 );
      v29 = 0i64;
      v42 = (_DWORD)v15 == 0;
    }
    if ( v42 )
    {
      hkErrStream::hkErrStream(&v63, buf, 512);
      hkOstream::operator<<(
        &v63,
        "All regions are either below the area threshold or too far from a seed point. Keeping the largest region.");
      hkError::messageWarning(808710226, buf, "NavMesh\\hkaiNavMeshGenerationUtils.cpp", 2804);
      hkOstream::~hkOstream(&v63);
      *v55 = v40;
    }
    v45 = mesh->m_faces.m_size;
    facesToRemove.m_data = 0i64;
    v46 = 0;
    facesToRemove.m_size = 0;
    facesToRemove.m_capacityAndFlags = 0x80000000;
    if ( v45 > 0 )
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &facesToRemove, v45, 4);
      if ( resulta.m_enum )
      {
        v9->m_enum = HK_FAILURE;
LABEL_79:
        facesToRemove.m_size = 0;
        if ( facesToRemove.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            facesToRemove.m_data,
            4 * facesToRemove.m_capacityAndFlags);
        facesToRemove.m_data = 0i64;
        facesToRemove.m_capacityAndFlags = 0x80000000;
        goto LABEL_82;
      }
      v46 = facesToRemove.m_size;
    }
    for ( i = 0; i < mesh->m_faces.m_size; ++v29 )
    {
      if ( v55[array.m_data[v29]] == -1 )
      {
        if ( v46 == (facesToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &facesToRemove, 4);
          v46 = facesToRemove.m_size;
        }
        facesToRemove.m_data[v46] = i;
        v46 = ++facesToRemove.m_size;
      }
      ++i;
    }
    hkaiNavMeshUtils::removeFaces(&resulta, mesh, &facesToRemove, 1);
    if ( resulta.m_enum )
      v9->m_enum = HK_FAILURE;
    else
      v9->m_enum = HK_SUCCESS;
    goto LABEL_79;
  }
  v9->m_enum = HK_FAILURE;
LABEL_7:
  areasOut.m_size = 0;
  if ( areasOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      areasOut.m_data,
      4 * areasOut.m_capacityAndFlags);
  areasOut.m_data = 0i64;
  array.m_size = 0;
LABEL_91:
  areasOut.m_capacityAndFlags = 0x80000000;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
  return v9;
}

// File Line: 2844
// RVA: 0xB74FE0
void __fastcall hkaiNavMeshGenerationUtils::_saveSnapshot(hkaiNavMeshGenerationSettings *input, hkGeometry *geom)
{
  hkClass *v4; // rax
  hkOstream v5; // [rsp+30h] [rbp-438h] BYREF
  hkaiNavMeshGenerationSettings settings; // [rsp+50h] [rbp-418h] BYREF
  hkaiNavMeshGenerationSnapshot object; // [rsp+240h] [rbp-228h] BYREF
  hkResult result; // [rsp+470h] [rbp+8h] BYREF

  hkOstream::hkOstream(
    &v5,
    (const char *)((unsigned __int64)input->m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  if ( hkOstream::isOk(&v5, (hkBool *)&result)->m_bool )
  {
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&settings);
    hkaiNavMeshGenerationSettings::operator=(&settings, input);
    settings.m_saveInputSnapshot.m_bool = 0;
    hkaiNavMeshGenerationSnapshot::hkaiNavMeshGenerationSnapshot(&object, geom, &settings);
    v4 = hkaiNavMeshGenerationSnapshot::staticClass();
    hkSerializeUtil::save(&result, &object, v4, v5.m_writer.m_pntr, 0);
    hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(&object);
    hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&settings);
  }
  hkOstream::~hkOstream(&v5);
}

// File Line: 2862
// RVA: 0xB74620
hkResult *__fastcall hkaiNavMeshGenerationUtils::_blockUntraversableEdges(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometryRaycaster *raycaster)
{
  int m_size; // ebx
  hkaiNavMesh *v7; // r13
  int v9; // edi
  float v10; // xmm6_4
  __int32 v11; // eax
  unsigned int *v12; // rcx
  int v13; // r8d
  int v14; // r8d
  int v15; // r9d
  int m_capacityAndFlags; // r8d
  int v18; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v21; // ebx
  int v22; // edi
  unsigned __int32 v23; // eax
  void *v24; // r9
  __int64 v25; // r8
  int v26; // r9d
  __int64 v27; // r8
  void *v28; // rdx
  __int64 v29; // rcx
  _DWORD *v30; // rdi
  int v31; // ebx
  int v32; // edi
  __int32 v33; // ecx
  __int64 v34; // rax
  void *v35; // r10
  int v36; // eax
  int v37; // ecx
  int v38; // r9d
  __int64 v39; // rcx
  _DWORD *v40; // rdi
  int v41; // esi
  __int64 v42; // r11
  hkaiNavMesh::Face *v43; // rbx
  __int64 m_startEdgeIndex; // r10
  __int64 v45; // r8
  hkaiNavMesh::Edge *v46; // rdi
  char v47; // r15
  int v48; // r12d
  __int64 v49; // rbx
  hkaiNavMesh::Face *v50; // r14
  __int64 v51; // r11
  __int64 v52; // r8
  hkaiNavMesh::Edge *v53; // rdi
  __int64 m_oppositeEdge; // rax
  __int64 m_a; // r10
  __int64 v56; // rsi
  __int64 m_b; // rax
  __int64 v58; // r10
  __int64 v59; // rdx
  bool v60; // cc
  __int64 v61; // rdx
  unsigned int *v62; // r10
  __int64 m_faceDataStriding; // rax
  hkaiNavMesh::Face *v64; // r11
  int v65; // r12d
  __int64 v66; // r14
  int v67; // esi
  __int64 v68; // r15
  hkaiNavMesh::Edge *v69; // rax
  __int64 v70; // r8
  hkVector4f *v71; // rcx
  hkaiNavMeshGenerationSettings *v72; // r13
  __int64 v73; // rbx
  __int64 v74; // rax
  hkVector4f *v75; // rdi
  int v76; // r9d
  __int64 v77; // rdi
  hkaiNavMesh::Edge *v78; // r8
  __m128 v79; // xmm2
  __m128 v80; // xmm2
  __int64 v81; // rax
  _DWORD *v82; // rdi
  int v83; // r8d
  int v84; // r8d
  hkResult v85; // [rsp+40h] [rbp-88h] BYREF
  void *v86; // [rsp+48h] [rbp-80h] BYREF
  int v87; // [rsp+50h] [rbp-78h]
  unsigned int v88; // [rsp+54h] [rbp-74h]
  int v89; // [rsp+58h] [rbp-70h]
  hkBitField array; // [rsp+60h] [rbp-68h] BYREF
  hkResult resulta[4]; // [rsp+78h] [rbp-50h] BYREF
  hkVector4f v92; // [rsp+88h] [rbp-40h]
  hkaiNavMesh mesha; // [rsp+98h] [rbp-30h] BYREF
  _DWORD *v94; // [rsp+198h] [rbp+D0h]
  hkaiNavMesh *v95; // [rsp+1A0h] [rbp+D8h]
  hkaiNavMeshGenerationSettings *v96; // [rsp+1A8h] [rbp+E0h]

  m_size = mesh->m_edges.m_size;
  v7 = mesh;
  *(float *)&v85.m_enum = input->m_minCharacterWidth * input->m_minCharacterWidth;
  v9 = (m_size + 31) >> 5;
  array.m_storage.m_words.m_data = 0i64;
  *(_QWORD *)&array.m_storage.m_words.m_size = 0x8000000000000000ui64;
  LODWORD(v10) = _mm_shuffle_ps((__m128)(unsigned int)v85.m_enum, (__m128)(unsigned int)v85.m_enum, 0).m128_u32[0];
  v11 = v9;
  if ( v9 )
  {
    v85.m_enum = 4 * v9;
    v12 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v85);
    v11 = v85.m_enum / 4;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 0x80000000;
  array.m_storage.m_words.m_data = v12;
  if ( v11 )
    v13 = v11;
  array.m_storage.m_words.m_size = (m_size + 31) >> 5;
  array.m_storage.m_numBits = m_size;
  array.m_storage.m_words.m_capacityAndFlags = v13;
  v14 = v13 & 0x3FFFFFFF;
  if ( v14 < v9 )
  {
    v15 = (m_size + 31) >> 5;
    if ( v9 < 2 * v14 )
      v15 = 2 * v14;
    hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &array, v15, 4);
  }
  array.m_storage.m_words.m_size = (m_size + 31) >> 5;
  if ( !array.m_storage.m_words.m_data )
  {
    m_capacityAndFlags = array.m_storage.m_words.m_capacityAndFlags;
    result->m_enum = HK_FAILURE;
    array.m_storage.m_words.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * m_capacityAndFlags);
    return result;
  }
  v18 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    m_data = array.m_storage.m_words.m_data;
    for ( i = (unsigned int)(v18 + 1); i; --i )
      *m_data++ = 0;
  }
  if ( !input->m_enableSimplification.m_bool )
  {
LABEL_26:
    v21 = v7->m_vertices.m_size;
    v88 = 0x80000000;
    v86 = 0i64;
    v87 = 0;
    v22 = (v21 + 31) >> 5;
    v23 = v22;
    if ( v22 )
    {
      v85.m_enum = 4 * v22;
      v24 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v85);
      v23 = v85.m_enum / 4;
    }
    else
    {
      v24 = 0i64;
    }
    v25 = 0x80000000i64;
    v86 = v24;
    if ( v23 )
      v25 = v23;
    v87 = (v21 + 31) >> 5;
    v89 = v21;
    v88 = v25;
    if ( (v25 & 0x3FFFFFFF) < v22 )
    {
      v26 = (v21 + 31) >> 5;
      if ( v22 < (int)(2 * (v25 & 0x3FFFFFFF)) )
        v26 = 2 * (v25 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &v86, v26, 4);
      v25 = v88;
      v24 = v86;
    }
    v87 = (v21 + 31) >> 5;
    if ( v24 )
    {
      if ( v22 - 1 >= 0 )
      {
        v29 = (unsigned int)v22;
        v30 = v24;
        while ( v29 )
        {
          *v30++ = 0;
          --v29;
        }
        v25 = v88;
        v24 = v86;
      }
      v31 = v7->m_edges.m_size;
      v86 = 0i64;
      v87 = 0;
      v88 = 0x80000000;
      v32 = (v31 + 31) >> 5;
      v33 = v32;
      if ( v32 )
      {
        v85.m_enum = 4 * v32;
        v34 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, void *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                &hkContainerHeapAllocator::s_alloc,
                &v85,
                v25,
                v24);
        LODWORD(v25) = v88;
        v24 = v86;
        v35 = (void *)v34;
        v33 = v85.m_enum / 4;
      }
      else
      {
        v35 = 0i64;
      }
      v36 = 0x80000000;
      v86 = v35;
      if ( v33 )
        v36 = v33;
      v87 = (v31 + 31) >> 5;
      v89 = v31;
      v88 = v36;
      v37 = v36 & 0x3FFFFFFF;
      if ( (v36 & 0x3FFFFFFF) < v32 )
      {
        v38 = (v31 + 31) >> 5;
        if ( v32 < 2 * v37 )
          v38 = 2 * v37;
        hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &v86, v38, 4);
        LODWORD(v25) = v88;
        v24 = v86;
        v36 = v88;
        v35 = v86;
      }
      v87 = (v31 + 31) >> 5;
      if ( v35 )
      {
        if ( v32 - 1 >= 0 )
        {
          v39 = (unsigned int)v32;
          v40 = v35;
          while ( v39 )
          {
            *v40++ = 0;
            --v39;
          }
          v24 = v86;
        }
        v41 = 0;
        if ( v7->m_faces.m_size > 0 )
        {
          v42 = 0i64;
          do
          {
            v43 = v7->m_faces.m_data;
            m_startEdgeIndex = v43[v42].m_startEdgeIndex;
            if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v43[v42].m_numEdges )
            {
              v45 = m_startEdgeIndex;
              do
              {
                v46 = v7->m_edges.m_data;
                if ( (v46[v45].m_oppositeEdge == -1 || (v46[v45].m_flags.m_storage & 0x20) != 0)
                  && ((array.m_storage.m_words.m_data[(__int64)(int)m_startEdgeIndex >> 5] >> (m_startEdgeIndex & 0x1F)) & 1) == 0 )
                {
                  *((_DWORD *)v24 + ((__int64)v46[v45].m_a >> 5)) |= 1 << (v46[v45].m_a & 0x1F);
                  *((_DWORD *)v86 + ((__int64)v46[v45].m_b >> 5)) |= 1 << (v46[v45].m_b & 0x1F);
                  v24 = v86;
                }
                LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
                ++v45;
              }
              while ( (int)m_startEdgeIndex < v43[v42].m_startEdgeIndex + v43[v42].m_numEdges );
            }
            ++v41;
            ++v42;
          }
          while ( v41 < v7->m_faces.m_size );
        }
        do
        {
          v47 = 0;
          v48 = 0;
          if ( v7->m_faces.m_size <= 0 )
            break;
          v49 = 0i64;
          do
          {
            v50 = v7->m_faces.m_data;
            v51 = v50[v49].m_startEdgeIndex;
            if ( (int)v51 < (int)v51 + v50[v49].m_numEdges )
            {
              v52 = v51;
              do
              {
                v53 = v7->m_edges.m_data;
                m_oppositeEdge = (int)v53[v52].m_oppositeEdge;
                if ( (_DWORD)m_oppositeEdge != -1 && (v53[v52].m_flags.m_storage & 0x20) == 0 )
                {
                  m_a = v53[v52].m_a;
                  v56 = m_oppositeEdge;
                  if ( ((*((_DWORD *)v24 + (m_a >> 5)) >> (v53[v52].m_a & 0x1F)) & 1) == 0 )
                  {
                    m_b = v53[m_oppositeEdge].m_b;
                    if ( ((*((_DWORD *)v24 + (m_b >> 5)) >> (m_b & 0x1F)) & 1) != 0 )
                    {
                      v47 = 1;
                      *((_DWORD *)v24 + ((__int64)v53[v52].m_a >> 5)) |= 1 << (m_a & 0x1F);
                      v24 = v86;
                    }
                  }
                  v58 = v53[v52].m_b;
                  if ( ((*((_DWORD *)v24 + (v58 >> 5)) >> (v53[v52].m_b & 0x1F)) & 1) == 0
                    && ((*((_DWORD *)v24 + ((__int64)v53[v56].m_a >> 5)) >> (v53[v56].m_a & 0x1F)) & 1) != 0 )
                  {
                    v59 = (__int64)v53[v52].m_b >> 5;
                    v47 = 1;
                    *((_DWORD *)v24 + v59) |= 1 << (v58 & 0x1F);
                    v24 = v86;
                  }
                }
                LODWORD(v51) = v51 + 1;
                ++v52;
              }
              while ( (int)v51 < v50[v49].m_startEdgeIndex + v50[v49].m_numEdges );
            }
            ++v48;
            ++v49;
          }
          while ( v48 < v7->m_faces.m_size );
        }
        while ( v47 );
        v60 = v7->m_faces.m_size <= 0;
        v61 = 0i64;
        *(float *)&v85.m_enum = 0.0;
        *(_QWORD *)&resulta[0].m_enum = 0i64;
        if ( !v60 )
        {
          v62 = 0i64;
          array.m_storage.m_words.m_data = 0i64;
          do
          {
            m_faceDataStriding = v7->m_faceDataStriding;
            v64 = v7->m_faces.m_data;
            *(_QWORD *)&array.m_storage.m_words.m_size = v64;
            if ( (_DWORD)m_faceDataStriding )
              v65 = v7->m_faceData.m_data[v61 * m_faceDataStriding];
            else
              v65 = 0;
            v66 = *(int *)((char *)&v64->m_startEdgeIndex + (_QWORD)v62);
            v67 = __ROL4__(1, v66);
            if ( (int)v66 < (int)v66 + *(__int16 *)((char *)&v64->m_numEdges + (_QWORD)v62) )
            {
              v68 = v66;
              do
              {
                v69 = v7->m_edges.m_data;
                if ( v69[v68].m_oppositeEdge != -1 )
                {
                  v70 = v69[v68].m_a;
                  if ( ((*((_DWORD *)v24 + (v70 >> 5)) >> (v69[v68].m_a & 0x1F)) & 1) != 0
                    && ((*((_DWORD *)v24 + ((__int64)v69[v68].m_b >> 5)) >> (v69[v68].m_b & 0x1F)) & 1) != 0 )
                  {
                    v71 = v7->m_vertices.m_data;
                    v72 = v96;
                    v73 = 2i64;
                    v74 = v69[v68].m_b;
                    v75 = (hkVector4f *)resulta;
                    *(hkVector4f *)&resulta[0].m_enum = v71[v70];
                    v92.m_quad = (__m128)v71[v74];
                    do
                    {
                      hkaiNavMeshGenerationSettings::getCharacterWidthUsage(v72, v75++, v65);
                      --v73;
                    }
                    while ( v73 );
                    v7 = v95;
                    v62 = array.m_storage.m_words.m_data;
                    v64 = *(hkaiNavMesh::Face **)&array.m_storage.m_words.m_size;
                    *((_DWORD *)v86 + ((__int64)(int)v66 >> 5)) |= v67;
                    v24 = v86;
                  }
                }
                v67 = __ROL4__(v67, 1);
                LODWORD(v66) = v66 + 1;
                ++v68;
              }
              while ( (int)v66 < *(int *)((char *)&v64->m_startEdgeIndex + (_QWORD)v62)
                               + *(__int16 *)((char *)&v64->m_numEdges + (_QWORD)v62) );
            }
            v62 += 4;
            v61 = *(_QWORD *)&resulta[0].m_enum + 1i64;
            array.m_storage.m_words.m_data = v62;
            ++v85.m_enum;
            ++*(_QWORD *)&resulta[0].m_enum;
          }
          while ( v85.m_enum < v7->m_faces.m_size );
        }
        v76 = 0;
        if ( v7->m_edges.m_size > 0 )
        {
          v77 = 0i64;
          do
          {
            v78 = v7->m_edges.m_data;
            v79 = _mm_sub_ps(v7->m_vertices.m_data[v78[v77].m_a].m_quad, v7->m_vertices.m_data[v78[v77].m_b].m_quad);
            v80 = _mm_mul_ps(v79, v79);
            if ( ((*((_DWORD *)v86 + ((__int64)v76 >> 5)) >> (v76 & 0x1F)) & 1) != 0
              && (float)((float)(_mm_shuffle_ps(v80, v80, 85).m128_f32[0] + _mm_shuffle_ps(v80, v80, 0).m128_f32[0])
                       + _mm_shuffle_ps(v80, v80, 170).m128_f32[0]) < v10 )
            {
              v81 = (int)v78[v77].m_oppositeEdge;
              if ( (_DWORD)v81 != -1 )
                *(_QWORD *)&v78[v81].m_oppositeEdge = -1i64;
              *(_QWORD *)&v78[v77].m_oppositeEdge = -1i64;
            }
            ++v76;
            ++v77;
          }
          while ( v76 < v7->m_edges.m_size );
        }
        hkaiNavMeshUtils::validate(v7, 0);
        v82 = v94;
        v83 = v88;
        *v94 = 0;
        v87 = 0;
        if ( v83 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v86, 4 * v83);
        v84 = v88;
        v86 = 0i64;
        v88 = 0x80000000;
        v87 = 0;
        if ( v84 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v86, 4 * v84);
        v86 = 0i64;
        v88 = 0x80000000;
        array.m_storage.m_words.m_size = 0;
        if ( array.m_storage.m_words.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            array.m_storage.m_words.m_data,
            4 * array.m_storage.m_words.m_capacityAndFlags);
        return (hkResult *)v82;
      }
      result->m_enum = HK_FAILURE;
      v87 = 0;
      if ( v36 >= 0 )
      {
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, void *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          0i64,
          (unsigned int)(4 * v36),
          v24);
        LODWORD(v25) = v88;
        v24 = v86;
      }
      v86 = 0i64;
      v88 = 0x80000000;
      v87 = 0;
      if ( (int)v25 < 0 )
        goto LABEL_39;
      v28 = v24;
      v27 = (unsigned int)(4 * v25);
    }
    else
    {
      result->m_enum = HK_FAILURE;
      v87 = 0;
      if ( (int)v25 < 0 )
      {
LABEL_39:
        v86 = 0i64;
        v88 = 0x80000000;
        array.m_storage.m_words.m_size = 0;
        goto LABEL_21;
      }
      v27 = (unsigned int)(4 * v25);
      v28 = 0i64;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v28, v27);
    goto LABEL_39;
  }
  hkaiNavMesh::hkaiNavMesh(&mesha);
  hkaiNavMesh::copy(&mesha, &v85, v7);
  if ( *(float *)&v85.m_enum == 0.0 )
  {
    hkaiNavMeshSimplificationUtils::_selectiveMergeSharedVertices((hkResult *)&array, input, &mesha);
    if ( !LODWORD(array.m_storage.m_words.m_data) )
    {
      hkaiNavMeshSimplificationUtils::_findRemovableBoundaryEdges(resulta, input, &mesha, raycaster, 0i64, 0i64, &array);
      if ( resulta[0].m_enum == HK_SUCCESS )
      {
        hkaiNavMesh::~hkaiNavMesh(&mesha);
        goto LABEL_26;
      }
    }
  }
  result->m_enum = HK_FAILURE;
  hkaiNavMesh::~hkaiNavMesh(&mesha);
  array.m_storage.m_words.m_size = 0;
LABEL_21:
  if ( array.m_storage.m_words.m_capacityAndFlags < 0 )
    return result;
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
    &hkContainerHeapAllocator::s_alloc,
    array.m_storage.m_words.m_data,
    4 * array.m_storage.m_words.m_capacityAndFlags);
  return result;
}K_SUCCESS )
      {
        hkaiNavMesh::~hkaiNavMesh(&mesha);
        goto LABEL_26;
      }
    }
  }
  result->m_enum = HK_FAILURE;
  hkaiNavMesh::~hkaiNavMesh(&mesha);
  array.m_stor

