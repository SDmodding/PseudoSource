// File Line: 34
// RVA: 0xCA8360
hkResult *__fastcall hkPlaneEquationUtil::findTriPlaneIntersectionPoint(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        int planeAIndex,
        int planeBIndex,
        int planeCIndex,
        hkPlaneEquationUtil::IntersectionPoint *intersectionPointOut)
{
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm5
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm3

  m_quad = planeEquations->m_data[planeCIndex].m_quad;
  v8 = planeEquations->m_data[planeBIndex].m_quad;
  v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad));
  v10 = m_quad;
  v11 = planeEquations->m_data[planeAIndex].m_quad;
  v12 = _mm_shuffle_ps(v9, v9, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
  v14 = v11;
  v15 = planeEquations->m_data[planeBIndex].m_quad;
  v16 = _mm_shuffle_ps(v13, v13, 201);
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15));
  v18 = _mm_mul_ps(planeEquations->m_data[planeAIndex].m_quad, v12);
  v19 = _mm_shuffle_ps(v17, v17, 201);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= 0.00000011920929 )
  {
    m_data = planeEquations->m_data;
    v22 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              _mm_shuffle_ps(m_data[planeAIndex].m_quad, m_data[planeAIndex].m_quad, 255),
              _mm_shuffle_ps(m_data[planeBIndex].m_quad, m_data[planeBIndex].m_quad, 255)),
            _mm_unpacklo_ps(_mm_shuffle_ps(m_data[planeCIndex].m_quad, m_data[planeCIndex].m_quad, 255), aabbOut.m_quad));
    v23 = _mm_rcp_ps(v20);
    intersectionPointOut->m_planeA = planeAIndex;
    intersectionPointOut->m_planeB = planeBIndex;
    intersectionPointOut->m_planeC = planeCIndex;
    v24 = _mm_xor_ps(v22, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
    intersectionPointOut->m_location.m_quad = _mm_mul_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v16),
                                                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v12)),
                                                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v19)),
                                                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v20)), v23));
    if ( planeAIndex > planeBIndex )
    {
      intersectionPointOut->m_planeA = planeBIndex;
      intersectionPointOut->m_planeB = planeAIndex;
    }
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 91
// RVA: 0xCA84E0
hkResult *__fastcall hkPlaneEquationUtil::findPlanarIntersections(
        hkResult *result,
        hkVector4f *intersectionLineDir,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        int planeAIndex,
        int planeBIndex,
        hkPlaneEquationUtil::IntersectionPoint *upperPointOut,
        hkPlaneEquationUtil::IntersectionPoint *lowerPointOut)
{
  hkPlaneEquationUtil::IntersectionPoint *v7; // rbx
  __m128 *p_m_quad; // rdi
  int planeCIndex; // esi
  hkResult *v12; // r15
  int v13; // r12d
  __int64 v14; // rbp
  hkVector4f v16; // xmm3
  __m128 v17; // xmm1
  int m_planeC; // ecx
  int m_planeB; // edx
  int m_planeA; // r8d
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  int v23; // eax
  int v24; // eax
  hkPlaneEquationUtil::IntersectionPoint intersectionPointOut; // [rsp+30h] [rbp-58h] BYREF
  hkResult resulta; // [rsp+A0h] [rbp+18h] BYREF

  v7 = upperPointOut;
  p_m_quad = &lowerPointOut->m_location.m_quad;
  *(_QWORD *)&upperPointOut->m_planeA = -1i64;
  v7->m_planeC = -1;
  planeCIndex = 0;
  p_m_quad[1].m128_u64[0] = -1i64;
  p_m_quad[1].m128_i32[2] = -1;
  v12 = result;
  LOBYTE(upperPointOut) = 0;
  if ( planeEquations->m_size > 0 )
  {
    v13 = planeBIndex;
    v14 = 0i64;
    do
    {
      if ( planeCIndex != planeAIndex
        && planeCIndex != v13
        && hkPlaneEquationUtil::findTriPlaneIntersectionPoint(
             &resulta,
             planeEquations,
             planeAIndex,
             v13,
             planeCIndex,
             &intersectionPointOut)->m_enum == HK_SUCCESS )
      {
        v16.m_quad = (__m128)intersectionPointOut.m_location;
        if ( !(_BYTE)upperPointOut )
        {
          LODWORD(lowerPointOut) = -943501312;
          LOBYTE(upperPointOut) = 1;
          v17 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)0xC7C35000, (__m128)0xC7C35000, 0), intersectionLineDir->m_quad),
                  intersectionPointOut.m_location.m_quad);
          *p_m_quad = v17;
          v7->m_location.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v17);
        }
        m_planeC = intersectionPointOut.m_planeC;
        m_planeB = intersectionPointOut.m_planeB;
        m_planeA = intersectionPointOut.m_planeA;
        v21 = _mm_mul_ps(_mm_sub_ps(*p_m_quad, v16.m_quad), planeEquations->m_data[v14].m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                   + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) > (float)(0.0 - 0.00000011920929) )
        {
          *(hkVector4f *)p_m_quad = (hkVector4f)v16.m_quad;
          p_m_quad[1].m128_i32[0] = m_planeA;
          p_m_quad[1].m128_i32[1] = m_planeB;
          p_m_quad[1].m128_i32[2] = m_planeC;
        }
        v22 = _mm_mul_ps(_mm_sub_ps(v7->m_location.m_quad, v16.m_quad), planeEquations->m_data[v14].m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
                   + _mm_shuffle_ps(v22, v22, 170).m128_f32[0]) > (float)(0.0 - 0.00000011920929) )
        {
          v7->m_location = (hkVector4f)v16.m_quad;
          v7->m_planeA = m_planeA;
          v7->m_planeB = m_planeB;
          v7->m_planeC = m_planeC;
        }
      }
      ++planeCIndex;
      ++v14;
    }
    while ( planeCIndex < planeEquations->m_size );
    v12 = result;
  }
  if ( v7->m_planeA == -1 )
  {
    v23 = p_m_quad[1].m128_i32[0];
    if ( v23 == -1 )
      goto LABEL_21;
    v7->m_planeA = v23;
    v7->m_planeB = p_m_quad[1].m128_i32[1];
    v7->m_planeC = p_m_quad[1].m128_i32[2];
  }
  if ( p_m_quad[1].m128_i32[0] != -1 )
  {
LABEL_20:
    v12->m_enum = HK_SUCCESS;
    return v12;
  }
  v24 = v7->m_planeA;
  if ( v24 != -1 )
  {
    p_m_quad[1].m128_i32[0] = v24;
    p_m_quad[1].m128_i32[1] = v7->m_planeB;
    p_m_quad[1].m128_i32[2] = v7->m_planeC;
    goto LABEL_20;
  }
LABEL_21:
  v12->m_enum = HK_FAILURE;
  return v12;
}_quad[1].m128_i32[

// File Line: 204
// RVA: 0xCA8720
hkBool *__fastcall hkPlaneEquationUtil::isNextIntersectionPoint(
        hkBool *result,
        hkVector4f *intersectionLineDir,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        int planeAIndex,
        int planeBIndex,
        hkVector4f *vertex,
        hkArray<hkPlaneEquationUtil::IntersectionPoint,hkContainerHeapAllocator> *pointsOut)
{
  int planeCIndex; // edi
  char v8; // r12
  float v9; // xmm7_4
  __int64 v12; // rbp
  __m128 v13; // xmm1
  __m128i v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  float v17; // xmm8_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm6_4
  hkPlaneEquationUtil::IntersectionPoint *v21; // rax
  __int128 v22; // xmm1
  bool v23; // zf
  hkPlaneEquationUtil::IntersectionPoint *v24; // rax
  __int128 v25; // xmm1
  hkResult resulta; // [rsp+34h] [rbp-94h] BYREF
  hkPlaneEquationUtil::IntersectionPoint intersectionPointOut; // [rsp+40h] [rbp-88h] BYREF
  hkVector4f *v30; // [rsp+D8h] [rbp+10h]

  v30 = intersectionLineDir;
  planeCIndex = 0;
  v8 = 0;
  v9 = 3.40282e38;
  if ( planeEquations->m_size <= 0 )
  {
    result->m_bool = 0;
    return result;
  }
  else
  {
    v12 = 0i64;
    do
    {
      if ( planeCIndex != planeAIndex && planeCIndex != planeBIndex )
      {
        v13 = _mm_mul_ps(planeEquations->m_data[v12].m_quad, intersectionLineDir->m_quad);
        v14 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                         _mm_shuffle_ps(v13, v13, 170));
        if ( *(float *)v14.m128i_i32 > _mm_shuffle_ps((__m128)0x322BCC77u, (__m128)0x322BCC77u, 0).m128_f32[0] )
        {
          v15 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u);
          v16 = _mm_shuffle_ps(vertex->m_quad, _mm_unpackhi_ps(vertex->m_quad, query.m_quad), 196);
          v17 = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0];
          *vertex = (hkVector4f)v16;
          v18 = _mm_mul_ps(planeEquations->m_data[v12].m_quad, v16);
          v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
          v18.m128_f32[0] = _mm_shuffle_ps(v19, v19, 177).m128_f32[0] + v19.m128_f32[0];
          v19.m128_f32[0] = _mm_rcp_ps(v15).m128_f32[0];
          v20 = (float)(0.0 - v18.m128_f32[0])
              * (float)((float)(2.0 - (float)(v15.m128_f32[0] * v19.m128_f32[0])) * v19.m128_f32[0]);
          if ( v20 < (float)(v17 + v9) )
          {
            if ( hkPlaneEquationUtil::findTriPlaneIntersectionPoint(
                   &resulta,
                   planeEquations,
                   planeAIndex,
                   planeBIndex,
                   planeCIndex,
                   &intersectionPointOut)->m_enum == HK_SUCCESS )
            {
              v8 = 1;
              if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v20 - v9)) >> 1) >= v17 )
              {
                v23 = (pointsOut->m_capacityAndFlags & 0x3FFFFFFF) == 0;
                pointsOut->m_size = 0;
                if ( v23 )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pointsOut->m_data, 32);
                v24 = &pointsOut->m_data[pointsOut->m_size];
                if ( v24 )
                {
                  v25 = *(_OWORD *)&intersectionPointOut.m_planeA;
                  v24->m_location = intersectionPointOut.m_location;
                  *(_OWORD *)&v24->m_planeA = v25;
                }
                v9 = v20;
              }
              else
              {
                if ( pointsOut->m_size == (pointsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pointsOut->m_data, 32);
                v21 = &pointsOut->m_data[pointsOut->m_size];
                if ( v21 )
                {
                  v22 = *(_OWORD *)&intersectionPointOut.m_planeA;
                  v21->m_location = intersectionPointOut.m_location;
                  *(_OWORD *)&v21->m_planeA = v22;
                }
              }
              ++pointsOut->m_size;
            }
            intersectionLineDir = v30;
          }
        }
      }
      ++planeCIndex;
      ++v12;
    }
    while ( planeCIndex < planeEquations->m_size );
    result->m_bool = v8;
    return result;
  }
}

// File Line: 286
// RVA: 0xCA8040
hkResult *__fastcall hkPlaneEquationUtil::getStartingPoint(
        hkPlaneEquationUtil::IntersectionPoint *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        int *nearlyParallelPlaneLower,
        int *nearlyParallelPlaneUpper)
{
  _BYTE *v4; // r10
  int v5; // r14d
  int v6; // ecx
  int m_size; // eax
  float v11; // xmm3_4
  int v12; // ebx
  int v13; // r8d
  __int64 v14; // rsi
  int v15; // r15d
  int v16; // edx
  __int64 v17; // r11
  __m128 v18; // xmm1
  float v19; // xmm2_4
  int v20; // ecx
  __int64 v21; // rax
  __int64 *v22; // rcx
  int planeBIndex; // r8d
  hkVector4f *m_data; // rcx
  int v25; // r9d
  __int64 v26; // rdx
  __int64 v27; // rax
  __m128 v28; // xmm6
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  _DWORD *v31; // rbx
  _DWORD *v33; // rsi
  int v34; // [rsp+40h] [rbp-98h]
  __int64 v35; // [rsp+48h] [rbp-90h]
  hkResult resulta; // [rsp+54h] [rbp-84h] BYREF
  hkVector4f intersectionLineDir; // [rsp+60h] [rbp-78h] BYREF
  _BYTE *array; // [rsp+70h] [rbp-68h] BYREF
  int v39; // [rsp+78h] [rbp-60h]
  int v40; // [rsp+7Ch] [rbp-5Ch]
  _BYTE v41[256]; // [rsp+80h] [rbp-58h] BYREF
  _DWORD *v42; // [rsp+198h] [rbp+C0h]
  hkPlaneEquationUtil::IntersectionPoint *lowerPointOut; // [rsp+1B8h] [rbp+E0h]

  v4 = v41;
  v5 = 0;
  v6 = -2147483616;
  array = v41;
  v39 = 0;
  v40 = -2147483616;
  while ( 1 )
  {
    m_size = planeEquations->m_size;
    v11 = -3.40282e38;
    v12 = -1;
    v13 = 0;
    v34 = v6;
    v35 = -1i64;
    if ( m_size <= 0 )
      goto LABEL_32;
    v14 = 0i64;
    do
    {
      v15 = v13 + 1;
      v16 = v13 + 1;
      if ( v13 + 1 < m_size )
      {
        v17 = v14 * 16 + 16;
        do
        {
          v18 = _mm_mul_ps(
                  planeEquations->m_data[v14].m_quad,
                  *(__m128 *)((char *)&planeEquations->m_data->m_quad + v17));
          v19 = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
              + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
          if ( v19 > v11 && v19 < _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0).m128_f32[0] )
          {
            v20 = 0;
            v21 = 0i64;
            if ( v5 <= 0 )
              goto LABEL_14;
            while ( *(_DWORD *)&v4[8 * v21] != v13 || *(_DWORD *)&v4[8 * v21 + 4] != v16 )
            {
              ++v21;
              ++v20;
              if ( v21 >= v5 )
                goto LABEL_14;
            }
            if ( v20 == -1 )
            {
LABEL_14:
              *nearlyParallelPlaneLower = v13;
              v11 = v19;
              v12 = v13;
              *nearlyParallelPlaneUpper = v16;
              HIDWORD(v35) = v16;
            }
          }
          ++v16;
          v17 += 16i64;
        }
        while ( v16 < planeEquations->m_size );
        LODWORD(v35) = v12;
      }
      m_size = planeEquations->m_size;
      ++v14;
      ++v13;
    }
    while ( v15 < m_size );
    if ( v12 == -1 )
      break;
    if ( v5 == (v34 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
      v5 = v39;
      v4 = array;
    }
    v22 = (__int64 *)&v4[8 * v5];
    if ( v22 )
    {
      *v22 = v35;
      v5 = v39;
    }
    planeBIndex = *nearlyParallelPlaneUpper;
    m_data = planeEquations->m_data;
    v25 = *nearlyParallelPlaneLower;
    v26 = *nearlyParallelPlaneUpper;
    v27 = *nearlyParallelPlaneLower;
    v39 = v5 + 1;
    v28 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_data[v26].m_quad, m_data[v26].m_quad, 201), m_data[v27].m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_data[v27].m_quad, m_data[v27].m_quad, 201), m_data[v26].m_quad));
    v29 = _mm_shuffle_ps(v28, v28, 201);
    intersectionLineDir.m_quad = v29;
    if ( hkPlaneEquationUtil::findPlanarIntersections(
           &resulta,
           &intersectionLineDir,
           planeEquations,
           v25,
           planeBIndex,
           result,
           lowerPointOut)->m_enum == HK_FAILURE )
    {
      v31 = v42;
      *v42 = 1;
      goto LABEL_28;
    }
    v30 = _mm_mul_ps(_mm_sub_ps(result->m_location.m_quad, lowerPointOut->m_location.m_quad), v29);
    if ( (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
               + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) > (float)(0.0 - 0.00000011920929) )
    {
      v31 = v42;
      *v42 = 0;
LABEL_28:
      v39 = 0;
      if ( v40 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v40);
      return (hkResult *)v31;
    }
    v6 = v40;
    v5 = v39;
    v4 = array;
  }
  v6 = v34;
LABEL_32:
  v33 = v42;
  v39 = 0;
  *v42 = 1;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v4, 8 * v6);
  return (hkResult *)v33;
}

// File Line: 367
// RVA: 0xCA7F90
hkResult *__fastcall hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertexCloudOut)
{
  int m_size; // ebx
  hkVector4f *m_data; // rdi
  hkgpConvexHull::BuildConfig *v8; // rax
  hkgpConvexHull::BuildConfig v10; // [rsp+20h] [rbp-48h] BYREF
  hkgpConvexHull v11; // [rsp+30h] [rbp-38h] BYREF

  if ( planeEquationsIn->m_size < 4 )
    goto LABEL_5;
  hkgpConvexHull::hkgpConvexHull(&v11);
  m_size = planeEquationsIn->m_size;
  m_data = planeEquationsIn->m_data;
  hkgpConvexHull::BuildConfig::BuildConfig(&v10);
  if ( hkgpConvexHull::buildFromPlanes(&v11, m_data, m_size, v8) == -1 )
  {
    hkgpConvexHull::~hkgpConvexHull(&v11);
LABEL_5:
    result->m_enum = HK_FAILURE;
    return result;
  }
  hkgpConvexHull::fetchPositions(&v11, INTERNAL_VERTICES, vertexCloudOut);
  result->m_enum = HK_SUCCESS;
  hkgpConvexHull::~hkgpConvexHull(&v11);
  return result;
}

// File Line: 542
// RVA: 0xCA89B0
void __fastcall hkPlaneEquationUtil::calculateIntersectionLine(
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        int planeAIndex,
        int planeBIndex,
        int planeCIndex,
        hkVector4f *intersectionLineDir)
{
  hkVector4f *m_data; // r10
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  __m128 v8; // xmm2

  m_data = planeEquations->m_data;
  v6 = _mm_sub_ps(
         _mm_mul_ps(
           _mm_shuffle_ps(m_data[planeBIndex].m_quad, m_data[planeBIndex].m_quad, 201),
           m_data[planeAIndex].m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(m_data[planeAIndex].m_quad, m_data[planeAIndex].m_quad, 201),
           m_data[planeBIndex].m_quad));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  *intersectionLineDir = (hkVector4f)v7;
  v8 = _mm_mul_ps(planeEquations->m_data[planeCIndex].m_quad, v7);
  intersectionLineDir->m_quad = _mm_xor_ps(
                                  (__m128)_mm_slli_epi32(
                                            _mm_srli_epi32(
                                              (__m128i)_mm_cmplt_ps(
                                                         (__m128)0i64,
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_shuffle_ps(v8, v8, 85),
                                                             _mm_shuffle_ps(v8, v8, 0)),
                                                           _mm_shuffle_ps(v8, v8, 170))),
                                              0x1Fu),
                                            0x1Fu),
                                  v7);
}

// File Line: 553
// RVA: 0xCA8A40
void __fastcall hkPlaneEquationUtil::walkAlongEdge(
        hkPlaneEquationUtil::VisitedEdge *v,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        hkArray<hkPlaneEquationUtil::VisitedEdge,hkContainerHeapAllocator> *visitedEdges,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertexCloudOut)
{
  __int64 m_size; // r9
  int v6; // r11d
  __int64 v7; // r10
  int m_planeA; // r8d
  hkPlaneEquationUtil::VisitedEdge *m_data; // rax
  hkPlaneEquationUtil::VisitedEdge *v12; // rax
  int v13; // r9d
  hkPlaneEquationUtil::IntersectionPoint *vertex; // rax
  hkPlaneEquationUtil::IntersectionPoint *v15; // rbx
  hkVector4f v16; // xmm0
  int v17; // r8d
  __int64 v18; // rax
  unsigned __int64 v19; // rdx
  __int64 v20; // rbx
  hkBool result; // [rsp+40h] [rbp-9h] BYREF
  int v22; // [rsp+44h] [rbp-5h]
  unsigned __int64 v23; // [rsp+48h] [rbp-1h]
  hkArray<hkPlaneEquationUtil::IntersectionPoint,hkContainerHeapAllocator> pointsOut; // [rsp+50h] [rbp+7h] BYREF
  hkPlaneEquationUtil::VisitedEdge va; // [rsp+60h] [rbp+17h] BYREF
  hkPlaneEquationUtil::VisitedEdge v26; // [rsp+80h] [rbp+37h] BYREF

  m_size = visitedEdges->m_size;
  v6 = 0;
  v7 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_10;
  m_planeA = v->m_planeA;
  m_data = visitedEdges->m_data;
  while ( (m_data->m_planeA != m_planeA || m_data->m_planeB != v->m_planeB)
       && (m_data->m_planeB != m_planeA || m_data->m_planeA != v->m_planeB) )
  {
    ++v7;
    ++v6;
    ++m_data;
    if ( v7 >= m_size )
      goto LABEL_10;
  }
  if ( v6 == -1 )
  {
LABEL_10:
    if ( visitedEdges->m_size == (visitedEdges->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&visitedEdges->m_data, 32);
    v12 = &visitedEdges->m_data[visitedEdges->m_size];
    if ( v12 )
    {
      *(_OWORD *)&v12->m_planeA = *(_OWORD *)&v->m_planeA;
      v12->m_intersectionLineDir = v->m_intersectionLineDir;
    }
    ++visitedEdges->m_size;
    v13 = v->m_planeA;
    pointsOut.m_data = 0i64;
    pointsOut.m_size = 0;
    vertex = v->m_fromPoint;
    pointsOut.m_capacityAndFlags = 0x80000000;
    if ( hkPlaneEquationUtil::isNextIntersectionPoint(
           &result,
           &v->m_intersectionLineDir,
           planeEquations,
           v13,
           v->m_planeB,
           &vertex->m_location,
           &pointsOut)->m_bool )
    {
      v15 = pointsOut.m_data;
      if ( vertexCloudOut->m_size == (vertexCloudOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vertexCloudOut->m_data, 16);
      v16.m_quad = (__m128)v15->m_location;
      v17 = 0;
      v18 = vertexCloudOut->m_size;
      v22 = 0;
      vertexCloudOut->m_data[v18] = (hkVector4f)v16.m_quad;
      ++vertexCloudOut->m_size;
      if ( pointsOut.m_size > 0 )
      {
        v19 = 0i64;
        v23 = 0i64;
        do
        {
          v20 = v17;
          va.m_planeA = *(int *)((char *)&pointsOut.m_data->m_planeA + v19);
          va.m_planeB = *(int *)((char *)&pointsOut.m_data->m_planeC + v19);
          va.m_fromPoint = &pointsOut.m_data[v20];
          hkPlaneEquationUtil::calculateIntersectionLine(
            planeEquations,
            *(int *)((char *)&pointsOut.m_data->m_planeA + v19),
            *(int *)((char *)&pointsOut.m_data->m_planeC + v19),
            *(int *)((char *)&pointsOut.m_data->m_planeB + v19),
            &va.m_intersectionLineDir);
          hkPlaneEquationUtil::walkAlongEdge(&va, planeEquations, visitedEdges, vertexCloudOut);
          v26.m_planeA = pointsOut.m_data[v23 / 0x20].m_planeB;
          v26.m_planeB = pointsOut.m_data[v23 / 0x20].m_planeC;
          v26.m_fromPoint = &pointsOut.m_data[v20];
          hkPlaneEquationUtil::calculateIntersectionLine(
            planeEquations,
            pointsOut.m_data[v23 / 0x20].m_planeB,
            pointsOut.m_data[v23 / 0x20].m_planeC,
            pointsOut.m_data[v23 / 0x20].m_planeA,
            &v26.m_intersectionLineDir);
          hkPlaneEquationUtil::walkAlongEdge(&v26, planeEquations, visitedEdges, vertexCloudOut);
          v17 = v22 + 1;
          v19 = v23 + 32;
          v22 = v17;
          v23 += 32i64;
        }
        while ( v17 < pointsOut.m_size );
      }
    }
    pointsOut.m_size = 0;
    if ( pointsOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pointsOut.m_data,
        32 * pointsOut.m_capacityAndFlags);
  }
}

// File Line: 605
// RVA: 0xCA8CB0
void __fastcall hkPlaneEquationUtil::weldXsortedVertices(
        float weldTolerance,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verts,
        int *numVertices)
{
  hkVector4f *m_data; // r9
  int v4; // ecx
  float v7; // xmm5_4
  hkVector4f *v8; // rbx
  hkVector4f *v9; // r8
  hkVector4f *v10; // rdx
  __m128 *p_m_quad; // rax
  __m128 m_quad; // xmm4
  float v13; // xmm3_4
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  hkVector4f *v17; // rax
  __int64 v18; // rbx
  int v19; // eax
  int v20; // eax
  int v21; // r9d
  int i; // edx
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  m_data = verts->m_data;
  v4 = verts->m_size - 1;
  LODWORD(v7) = _mm_shuffle_ps((__m128)LODWORD(weldTolerance), (__m128)LODWORD(weldTolerance), 0).m128_u32[0];
  v8 = verts->m_data;
  if ( v4 >= 0 )
  {
    v9 = m_data - 1;
    do
    {
      v10 = verts->m_data;
      p_m_quad = &v9->m_quad;
      if ( v9 >= verts->m_data )
      {
        m_quad = m_data->m_quad;
        result.m_enum = 1008981770;
        v13 = _mm_shuffle_ps(m_quad, m_quad, 0).m128_f32[0]
            - _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0).m128_f32[0];
        do
        {
          v14 = *p_m_quad;
          if ( _mm_shuffle_ps(v14, v14, 0).m128_f32[0] < v13 )
            break;
          v15 = _mm_sub_ps(v14, m_quad);
          v16 = _mm_mul_ps(v15, v15);
          if ( (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                     + _mm_shuffle_ps(v16, v16, 170).m128_f32[0]) < v7 )
          {
            for ( i = v4 - 1; i >= 0; --i )
            {
              v23 = _mm_sub_ps(*p_m_quad, m_data[1].m_quad);
              v24 = _mm_mul_ps(v23, v23);
              if ( (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0] + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
                         + _mm_shuffle_ps(v24, v24, 170).m128_f32[0]) >= v7 )
                break;
              ++m_data;
              --v4;
            }
            goto LABEL_9;
          }
          --p_m_quad;
        }
        while ( p_m_quad >= (__m128 *)v10 );
      }
      v17 = v8++;
      *v17 = (hkVector4f)m_data->m_quad;
      ++v9;
LABEL_9:
      ++m_data;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v18 = v8 - verts->m_data;
  *numVertices = v18;
  v19 = verts->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v19 < (int)v18 )
  {
    v20 = 2 * v19;
    v21 = v18;
    if ( (int)v18 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&verts->m_data, v21, 16);
  }
  verts->m_size = v18;
}

