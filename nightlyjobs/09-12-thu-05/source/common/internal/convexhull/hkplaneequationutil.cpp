// File Line: 34
// RVA: 0xCA8360
hkResult *__fastcall hkPlaneEquationUtil::findTriPlaneIntersectionPoint(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, int planeAIndex, int planeBIndex, int planeCIndex, hkPlaneEquationUtil::IntersectionPoint *intersectionPointOut)
{
  hkVector4f *v6; // rax
  __m128 v7; // xmm0
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
  hkResult *v21; // rax
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm3

  v7 = planeEquations->m_data[planeCIndex].m_quad;
  v8 = planeEquations->m_data[planeBIndex].m_quad;
  v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
  v10 = planeEquations->m_data[planeCIndex].m_quad;
  v11 = planeEquations->m_data[planeAIndex].m_quad;
  v12 = _mm_shuffle_ps(v9, v9, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
  v14 = planeEquations->m_data[planeAIndex].m_quad;
  v15 = planeEquations->m_data[planeBIndex].m_quad;
  v16 = _mm_shuffle_ps(v13, v13, 201);
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15));
  v18 = _mm_mul_ps(planeEquations->m_data[planeAIndex].m_quad, v12);
  v19 = _mm_shuffle_ps(v17, v17, 201);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= 0.00000011920929 )
  {
    v6 = planeEquations->m_data;
    v22 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              _mm_shuffle_ps(v6[planeAIndex].m_quad, v6[planeAIndex].m_quad, 255),
              _mm_shuffle_ps(v6[planeBIndex].m_quad, v6[planeBIndex].m_quad, 255)),
            _mm_unpacklo_ps(_mm_shuffle_ps(v6[planeCIndex].m_quad, v6[planeCIndex].m_quad, 255), aabbOut.m_quad));
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
    result->m_enum = 0;
    v21 = result;
  }
  else
  {
    result->m_enum = 1;
    v21 = result;
  }
  return v21;
}

// File Line: 91
// RVA: 0xCA84E0
hkResult *__fastcall hkPlaneEquationUtil::findPlanarIntersections(hkResult *result, hkVector4f *intersectionLineDir, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, int planeAIndex, int planeBIndex, hkPlaneEquationUtil::IntersectionPoint *upperPointOut, hkPlaneEquationUtil::IntersectionPoint *lowerPointOut)
{
  hkPlaneEquationUtil::IntersectionPoint *v7; // rbx
  __m128 *v8; // rdi
  int planeCIndex; // esi
  int v10; // er13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // r14
  hkResult *v12; // r15
  int v13; // er12
  __int64 v14; // rbp
  hkVector4f *v15; // r15
  hkVector4f v16; // xmm3
  __m128 v17; // xmm1
  float v18; // xmm4_4
  int v19; // ecx
  int v20; // edx
  int v21; // er8
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  int v24; // eax
  int v25; // eax
  hkPlaneEquationUtil::IntersectionPoint intersectionPointOut; // [rsp+30h] [rbp-58h]
  hkResult *v28; // [rsp+90h] [rbp+8h]
  hkResult resulta; // [rsp+A0h] [rbp+18h]

  v28 = result;
  v7 = upperPointOut;
  v8 = &lowerPointOut->m_location.m_quad;
  *(_QWORD *)&upperPointOut->m_planeA = -1i64;
  v7->m_planeC = -1;
  planeCIndex = 0;
  v8[1].m128_u64[0] = -1i64;
  v8[1].m128_i32[2] = -1;
  v10 = planeAIndex;
  v11 = planeEquations;
  v12 = result;
  LOBYTE(upperPointOut) = 0;
  if ( planeEquations->m_size > 0 )
  {
    v13 = planeBIndex;
    v14 = 0i64;
    v15 = intersectionLineDir;
    do
    {
      if ( planeCIndex != v10
        && planeCIndex != v13
        && hkPlaneEquationUtil::findTriPlaneIntersectionPoint(
             &resulta,
             v11,
             v10,
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
                  _mm_mul_ps(_mm_shuffle_ps((__m128)0xC7C35000, (__m128)0xC7C35000, 0), v15->m_quad),
                  intersectionPointOut.m_location.m_quad);
          *v8 = v17;
          v7->m_location.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v17);
        }
        v18 = epsilon;
        v19 = intersectionPointOut.m_planeC;
        v20 = intersectionPointOut.m_planeB;
        v21 = intersectionPointOut.m_planeA;
        v22 = _mm_mul_ps(_mm_sub_ps(*v8, v16.m_quad), v11->m_data[v14].m_quad);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170))) > (float)(0.0 - 0.00000011920929) )
        {
          *(hkVector4f *)v8 = (hkVector4f)v16.m_quad;
          v8[1].m128_i32[0] = v21;
          v8[1].m128_i32[1] = v20;
          v8[1].m128_i32[2] = v19;
          v18 = epsilon;
        }
        v23 = _mm_mul_ps(_mm_sub_ps(v7->m_location.m_quad, v16.m_quad), v11->m_data[v14].m_quad);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170))) > (float)(0.0 - v18) )
        {
          v7->m_location = (hkVector4f)v16.m_quad;
          v7->m_planeA = v21;
          v7->m_planeB = v20;
          v7->m_planeC = v19;
        }
      }
      ++planeCIndex;
      ++v14;
    }
    while ( planeCIndex < v11->m_size );
    v12 = v28;
  }
  if ( v7->m_planeA == -1 )
  {
    v24 = v8[1].m128_i32[0];
    if ( v24 == -1 )
      goto LABEL_21;
    v7->m_planeA = v24;
    v7->m_planeB = v8[1].m128_i32[1];
    v7->m_planeC = v8[1].m128_i32[2];
  }
  if ( v8[1].m128_i32[0] != -1 )
  {
LABEL_20:
    v12->m_enum = 0;
    return v12;
  }
  v25 = v7->m_planeA;
  if ( v25 != -1 )
  {
    v8[1].m128_i32[0] = v25;
    v8[1].m128_i32[1] = v7->m_planeB;
    v8[1].m128_i32[2] = v7->m_planeC;
    goto LABEL_20;
  }
LABEL_21:
  v12->m_enum = 1;
  return v12;
}>m_planeB;
    v8[1].m128_i32[2] = v7->

// File Line: 204
// RVA: 0xCA8720
hkBool *__fastcall hkPlaneEquationUtil::isNextIntersectionPoint(hkBool *result, hkVector4f *intersectionLineDir, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, int planeAIndex, int planeBIndex, hkVector4f *vertex, hkArray<hkPlaneEquationUtil::IntersectionPoint,hkContainerHeapAllocator> *pointsOut)
{
  int planeCIndex; // edi
  char v8; // r12
  float v9; // xmm7_4
  int v10; // er14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // rsi
  __int64 v12; // rbp
  __m128 v13; // xmm1
  __m128i v14; // xmm2
  __m128 v15; // xmm2
  hkVector4f v16; // xmm1
  float v17; // xmm8_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm6_4
  hkPlaneEquationUtil::IntersectionPoint *v21; // rax
  __int128 v22; // xmm1
  bool v23; // zf
  hkPlaneEquationUtil::IntersectionPoint *v24; // rax
  __int128 v25; // xmm1
  hkBool *v26; // rax
  hkResult resulta; // [rsp+34h] [rbp-94h]
  hkPlaneEquationUtil::IntersectionPoint intersectionPointOut; // [rsp+40h] [rbp-88h]
  hkBool *v29; // [rsp+D0h] [rbp+8h]
  hkVector4f *v30; // [rsp+D8h] [rbp+10h]

  v30 = intersectionLineDir;
  v29 = result;
  planeCIndex = 0;
  v8 = 0;
  v9 = *(float *)&xmmword_141A712A0;
  v10 = planeAIndex;
  v11 = planeEquations;
  if ( planeEquations->m_size <= 0 )
  {
    result->m_bool = 0;
    v26 = result;
  }
  else
  {
    v12 = 0i64;
    do
    {
      if ( planeCIndex != v10 && planeCIndex != planeBIndex )
      {
        v13 = _mm_mul_ps(v11->m_data[v12].m_quad, intersectionLineDir->m_quad);
        v14 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                         _mm_shuffle_ps(v13, v13, 170));
        if ( *(float *)v14.m128i_i32 > COERCE_FLOAT(_mm_shuffle_ps((__m128)0x322BCC77u, (__m128)0x322BCC77u, 0)) )
        {
          v15 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u);
          v16.m_quad = _mm_shuffle_ps(vertex->m_quad, _mm_unpackhi_ps(vertex->m_quad, query.m_quad), 196);
          LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
          *vertex = (hkVector4f)v16.m_quad;
          v18 = _mm_mul_ps(v11->m_data[v12].m_quad, v16.m_quad);
          v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
          v18.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 177)) + v19.m128_f32[0];
          v19.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v15);
          v20 = (float)(0.0 - v18.m128_f32[0])
              * (float)((float)(2.0 - (float)(v15.m128_f32[0] * v19.m128_f32[0])) * v19.m128_f32[0]);
          if ( v20 < (float)(v17 + v9) )
          {
            if ( hkPlaneEquationUtil::findTriPlaneIntersectionPoint(
                   &resulta,
                   v11,
                   v10,
                   planeBIndex,
                   planeCIndex,
                   &intersectionPointOut)->m_enum == HK_SUCCESS )
            {
              v8 = 1;
              if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v20 - v9)) >> 1) >= v17 )
              {
                v23 = (pointsOut->m_capacityAndFlags & 0x3FFFFFFF) == 0;
                pointsOut->m_size = 0;
                if ( v23 )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    pointsOut,
                    32);
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
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    pointsOut,
                    32);
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
    while ( planeCIndex < v11->m_size );
    v29->m_bool = v8;
    v26 = v29;
  }
  return v26;
}

// File Line: 286
// RVA: 0xCA8040
hkResult *__fastcall hkPlaneEquationUtil::getStartingPoint(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, int *nearlyParallelPlaneLower, int *nearlyParallelPlaneUpper)
{
  __int64 *v4; // r10
  int v5; // er14
  signed int v6; // ecx
  int *v7; // r12
  int *v8; // r13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v9; // rdi
  int v10; // eax
  float v11; // xmm3_4
  signed int v12; // ebx
  int v13; // er8
  __int64 v14; // rsi
  int v15; // er15
  int v16; // edx
  signed __int64 v17; // r11
  __m128 v18; // xmm1
  float v19; // xmm2_4
  int v20; // ecx
  signed __int64 v21; // rax
  signed __int64 *v22; // rcx
  int planeBIndex; // er8
  hkVector4f *v24; // rcx
  int v25; // er9
  signed __int64 v26; // rdx
  __int64 v27; // rax
  __m128 v28; // xmm6
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  _DWORD *v31; // rbx
  _DWORD *v33; // rsi
  signed int v34; // [rsp+40h] [rbp-98h]
  signed __int64 v35; // [rsp+48h] [rbp-90h]
  hkResult resulta; // [rsp+54h] [rbp-84h]
  hkVector4f intersectionLineDir; // [rsp+60h] [rbp-78h]
  __int64 *array; // [rsp+70h] [rbp-68h]
  int v39; // [rsp+78h] [rbp-60h]
  int v40; // [rsp+7Ch] [rbp-5Ch]
  __int64 v41; // [rsp+80h] [rbp-58h]
  _DWORD *v42; // [rsp+198h] [rbp+C0h]
  hkPlaneEquationUtil::IntersectionPoint *lowerPointOut; // [rsp+1B8h] [rbp+E0h]
  hkPlaneEquationUtil::IntersectionPoint *upperPointOut; // [rsp+1C0h] [rbp+E8h]

  upperPointOut = (hkPlaneEquationUtil::IntersectionPoint *)result;
  v4 = &v41;
  v5 = 0;
  v6 = -2147483616;
  v7 = nearlyParallelPlaneUpper;
  v8 = nearlyParallelPlaneLower;
  v9 = planeEquations;
  array = &v41;
  v39 = 0;
  v40 = -2147483616;
  while ( 1 )
  {
    v10 = v9->m_size;
    v11 = *(float *)&xmmword_141A712F0;
    v12 = -1;
    v13 = 0;
    v34 = v6;
    v35 = -1i64;
    if ( v10 <= 0 )
      goto LABEL_32;
    v14 = 0i64;
    do
    {
      v15 = v13 + 1;
      v16 = v13 + 1;
      if ( v13 + 1 < v10 )
      {
        v17 = v14 * 16 + 16;
        do
        {
          v18 = _mm_mul_ps(v9->m_data[v14].m_quad, *(__m128 *)((char *)&v9->m_data->m_quad + v17));
          v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
          if ( v19 > v11 && v19 < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0)) )
          {
            v20 = 0;
            v21 = 0i64;
            if ( v5 <= 0 )
              goto LABEL_14;
            while ( LODWORD(v4[v21]) != v13 || HIDWORD(v4[v21]) != v16 )
            {
              ++v21;
              ++v20;
              if ( v21 >= v5 )
                goto LABEL_14;
            }
            if ( v20 == -1 )
            {
LABEL_14:
              *v8 = v13;
              v11 = v19;
              v12 = v13;
              *v7 = v16;
              HIDWORD(v35) = v16;
            }
          }
          ++v16;
          v17 += 16i64;
        }
        while ( v16 < v9->m_size );
        LODWORD(v35) = v12;
      }
      v10 = v9->m_size;
      ++v14;
      ++v13;
    }
    while ( v15 < v10 );
    if ( v12 == -1 )
      break;
    if ( v5 == (v34 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
      v5 = v39;
      v4 = array;
    }
    v22 = &v4[v5];
    if ( v22 )
    {
      *v22 = v35;
      v5 = v39;
    }
    planeBIndex = *v7;
    v24 = v9->m_data;
    v25 = *v8;
    v26 = *v7;
    v27 = *v8;
    v39 = v5 + 1;
    v28 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v24[v26].m_quad, v24[v26].m_quad, 201), v24[v27].m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v24[v27].m_quad, v24[v27].m_quad, 201), v24[v26].m_quad));
    v29 = _mm_shuffle_ps(v28, v28, 201);
    intersectionLineDir.m_quad = v29;
    if ( hkPlaneEquationUtil::findPlanarIntersections(
           &resulta,
           &intersectionLineDir,
           v9,
           v25,
           planeBIndex,
           upperPointOut,
           lowerPointOut)->m_enum == 1 )
    {
      v31 = v42;
      *v42 = 1;
      goto LABEL_28;
    }
    v30 = _mm_mul_ps(_mm_sub_ps(upperPointOut->m_location.m_quad, lowerPointOut->m_location.m_quad), v29);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) > (float)(0.0 - 0.00000011920929) )
    {
      v31 = v42;
      *v42 = 0;
LABEL_28:
      v39 = 0;
      if ( v40 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          8 * v40);
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v4,
      8 * v6);
  return (hkResult *)v33;
}

// File Line: 367
// RVA: 0xCA7F90
hkResult *__fastcall hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn, hkArray<hkVector4f,hkContainerHeapAllocator> *vertexCloudOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rdi
  hkResult *v5; // rsi
  int v6; // ebx
  hkVector4f *v7; // rdi
  hkgpConvexHull::BuildConfig *v8; // rax
  hkgpConvexHull::BuildConfig v10; // [rsp+20h] [rbp-48h]
  hkgpConvexHull v11; // [rsp+30h] [rbp-38h]

  v3 = vertexCloudOut;
  v4 = planeEquationsIn;
  v5 = result;
  if ( planeEquationsIn->m_size < 4 )
    goto LABEL_5;
  hkgpConvexHull::hkgpConvexHull(&v11);
  v6 = v4->m_size;
  v7 = v4->m_data;
  hkgpConvexHull::BuildConfig::BuildConfig(&v10);
  if ( hkgpConvexHull::buildFromPlanes(&v11, v7, v6, v8) == -1 )
  {
    hkgpConvexHull::~hkgpConvexHull(&v11);
LABEL_5:
    v5->m_enum = 1;
    return v5;
  }
  hkgpConvexHull::fetchPositions(&v11, INTERNAL_VERTICES, v3);
  v5->m_enum = 0;
  hkgpConvexHull::~hkgpConvexHull(&v11);
  return v5;
}

// File Line: 542
// RVA: 0xCA89B0
void __fastcall hkPlaneEquationUtil::calculateIntersectionLine(hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, int planeAIndex, int planeBIndex, int planeCIndex, hkVector4f *intersectionLineDir)
{
  hkVector4f *v5; // r10
  __m128 v6; // xmm3
  hkVector4f v7; // xmm3
  __m128 v8; // xmm2

  v5 = planeEquations->m_data;
  v6 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5[planeBIndex].m_quad, v5[planeBIndex].m_quad, 201), v5[planeAIndex].m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v5[planeAIndex].m_quad, v5[planeAIndex].m_quad, 201), v5[planeBIndex].m_quad));
  v7.m_quad = _mm_shuffle_ps(v6, v6, 201);
  *intersectionLineDir = (hkVector4f)v7.m_quad;
  v8 = _mm_mul_ps(planeEquations->m_data[planeCIndex].m_quad, v7.m_quad);
  intersectionLineDir->m_quad = _mm_xor_ps(
                                  (__m128)_mm_slli_epi32(
                                            _mm_srli_epi32(
                                              (__m128i)_mm_cmpltps(
                                                         (__m128)0i64,
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_shuffle_ps(v8, v8, 85),
                                                             _mm_shuffle_ps(v8, v8, 0)),
                                                           _mm_shuffle_ps(v8, v8, 170))),
                                              0x1Fu),
                                            0x1Fu),
                                  v7.m_quad);
}

// File Line: 553
// RVA: 0xCA8A40
void __fastcall hkPlaneEquationUtil::walkAlongEdge(hkPlaneEquationUtil::VisitedEdge *v, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, hkArray<hkPlaneEquationUtil::VisitedEdge,hkContainerHeapAllocator> *visitedEdges, hkArray<hkVector4f,hkContainerHeapAllocator> *vertexCloudOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rsi
  __int64 v5; // r9
  int v6; // er11
  __int64 v7; // r10
  hkArray<hkPlaneEquationUtil::VisitedEdge,hkContainerHeapAllocator> *v8; // rdi
  hkPlaneEquationUtil::VisitedEdge *v9; // rbx
  int v10; // er8
  hkPlaneEquationUtil::VisitedEdge *v11; // rax
  hkPlaneEquationUtil::VisitedEdge *v12; // rax
  int v13; // er9
  hkVector4f *vertex; // rax
  hkPlaneEquationUtil::IntersectionPoint *v15; // rbx
  hkVector4f v16; // xmm0
  int v17; // er8
  signed __int64 v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rbx
  hkBool result; // [rsp+40h] [rbp-9h]
  int v22; // [rsp+44h] [rbp-5h]
  unsigned __int64 v23; // [rsp+48h] [rbp-1h]
  hkArray<hkPlaneEquationUtil::IntersectionPoint,hkContainerHeapAllocator> pointsOut; // [rsp+50h] [rbp+7h]
  hkPlaneEquationUtil::VisitedEdge va; // [rsp+60h] [rbp+17h]
  hkPlaneEquationUtil::VisitedEdge v26; // [rsp+80h] [rbp+37h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsa; // [rsp+B8h] [rbp+6Fh]

  planeEquationsa = planeEquations;
  v4 = vertexCloudOut;
  v5 = visitedEdges->m_size;
  v6 = 0;
  v7 = 0i64;
  v8 = visitedEdges;
  v9 = v;
  if ( v5 <= 0 )
    goto LABEL_10;
  v10 = v->m_planeA;
  v11 = v8->m_data;
  while ( (v11->m_planeA != v10 || v11->m_planeB != v->m_planeB)
       && (v11->m_planeB != v10 || v11->m_planeA != v->m_planeB) )
  {
    ++v7;
    ++v6;
    ++v11;
    if ( v7 >= v5 )
      goto LABEL_10;
  }
  if ( v6 == -1 )
  {
LABEL_10:
    if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 32);
    v12 = &v8->m_data[v8->m_size];
    if ( v12 )
    {
      *(_OWORD *)&v12->m_planeA = *(_OWORD *)&v9->m_planeA;
      v12->m_intersectionLineDir = v9->m_intersectionLineDir;
    }
    ++v8->m_size;
    v13 = v9->m_planeA;
    pointsOut.m_data = 0i64;
    pointsOut.m_size = 0;
    vertex = &v9->m_fromPoint->m_location;
    pointsOut.m_capacityAndFlags = 2147483648;
    if ( hkPlaneEquationUtil::isNextIntersectionPoint(
           &result,
           &v9->m_intersectionLineDir,
           planeEquationsa,
           v13,
           v9->m_planeB,
           vertex,
           &pointsOut)->m_bool )
    {
      v15 = pointsOut.m_data;
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
      v16.m_quad = (__m128)v15->m_location;
      v17 = 0;
      v18 = v4->m_size;
      v22 = 0;
      v4->m_data[v18] = (hkVector4f)v16.m_quad;
      ++v4->m_size;
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
            planeEquationsa,
            *(int *)((char *)&pointsOut.m_data->m_planeA + v19),
            *(int *)((char *)&pointsOut.m_data->m_planeC + v19),
            *(int *)((char *)&pointsOut.m_data->m_planeB + v19),
            &va.m_intersectionLineDir);
          hkPlaneEquationUtil::walkAlongEdge(&va, planeEquationsa, v8, v4);
          v26.m_planeA = pointsOut.m_data[v23 / 0x20].m_planeB;
          v26.m_planeB = pointsOut.m_data[v23 / 0x20].m_planeC;
          v26.m_fromPoint = &pointsOut.m_data[v20];
          hkPlaneEquationUtil::calculateIntersectionLine(
            planeEquationsa,
            pointsOut.m_data[v23 / 0x20].m_planeB,
            pointsOut.m_data[v23 / 0x20].m_planeC,
            pointsOut.m_data[v23 / 0x20].m_planeA,
            &v26.m_intersectionLineDir);
          hkPlaneEquationUtil::walkAlongEdge(&v26, planeEquationsa, v8, v4);
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
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pointsOut.m_data,
        32 * pointsOut.m_capacityAndFlags);
  }
}

// File Line: 605
// RVA: 0xCA8CB0
void __fastcall hkPlaneEquationUtil::weldXsortedVertices(float weldTolerance, hkArray<hkVector4f,hkContainerHeapAllocator> *verts, int *numVertices)
{
  hkVector4f *v3; // r9
  int v4; // ecx
  int *v5; // r10
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rdi
  float v7; // xmm5_4
  hkVector4f *v8; // rbx
  unsigned __int64 v9; // r8
  hkVector4f *v10; // rdx
  __m128 *v11; // rax
  __m128 v12; // xmm4
  float v13; // xmm3_4
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  hkVector4f *v17; // rax
  signed __int64 v18; // rbx
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int i; // edx
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  hkResult result; // [rsp+48h] [rbp+10h]

  v3 = verts->m_data;
  v4 = verts->m_size - 1;
  v5 = numVertices;
  v6 = verts;
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(weldTolerance), (__m128)LODWORD(weldTolerance), 0);
  v8 = verts->m_data;
  if ( v4 >= 0 )
  {
    v9 = (unsigned __int64)&v3[-1];
    do
    {
      v10 = v6->m_data;
      v11 = (__m128 *)v9;
      if ( (hkVector4f *)v9 >= v6->m_data )
      {
        v12 = v3->m_quad;
        result.m_enum = 1008981770;
        v13 = COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0))
            - COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0));
        do
        {
          v14 = *v11;
          if ( COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)) < v13 )
            break;
          v15 = _mm_sub_ps(v14, v12);
          v16 = _mm_mul_ps(v15, v15);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) < v7 )
          {
            for ( i = v4 - 1; i >= 0; --i )
            {
              v23 = _mm_sub_ps(*v11, v3[1].m_quad);
              v24 = _mm_mul_ps(v23, v23);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) >= v7 )
                break;
              ++v3;
              --v4;
            }
            goto LABEL_9;
          }
          --v11;
        }
        while ( v11 >= (__m128 *)v10 );
      }
      v17 = v8;
      ++v8;
      *v17 = (hkVector4f)v3->m_quad;
      v9 += 16i64;
LABEL_9:
      ++v3;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v18 = v8 - v6->m_data;
  *v5 = v18;
  v19 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v19 < (signed int)v18 )
  {
    v20 = 2 * v19;
    v21 = v18;
    if ( (signed int)v18 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v21, 16);
  }
  v6->m_size = v18;
}

