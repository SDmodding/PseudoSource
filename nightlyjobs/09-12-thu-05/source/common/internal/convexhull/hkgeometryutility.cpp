// File Line: 23
// RVA: 0xCA3690
void __fastcall hkGeometryUtility::createConvexGeometry(hkStridedVertices *stridedVertsIn, hkGeometry *geometryOut)
{
  hkStridedVertices *v2; // rbx
  hkGeometry *v3; // rdi
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-48h]
  hkgpConvexHull v5; // [rsp+40h] [rbp-38h]

  v2 = stridedVertsIn;
  v3 = geometryOut;
  hkgpConvexHull::hkgpConvexHull(&v5);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  if ( hkgpConvexHull::build(&v5, v2, &config) != -1 )
    hkgpConvexHull::generateGeometry(&v5, INTERNAL_VERTICES, v3, -1, 1);
  hkgpConvexHull::~hkgpConvexHull(&v5);
}

// File Line: 35
// RVA: 0xCA3710
void __fastcall hkGeometryUtility::createConvexGeometry(hkStridedVertices *stridedVertsIn, hkGeometry *geometryOut, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsOut)
{
  hkStridedVertices *v3; // rbx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rdi
  hkGeometry *v5; // rsi
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-48h]
  hkgpConvexHull v7; // [rsp+40h] [rbp-38h]

  v3 = stridedVertsIn;
  v4 = planeEquationsOut;
  v5 = geometryOut;
  hkgpConvexHull::hkgpConvexHull(&v7);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  if ( hkgpConvexHull::build(&v7, v3, &config) != -1 )
  {
    hkgpConvexHull::generateGeometry(&v7, INTERNAL_VERTICES, v5, -1, 1);
    hkgpConvexHull::buildIndices(&v7, 0.99998999, 0);
    hkgpConvexHull::fetchPlanes(&v7, v4);
  }
  hkgpConvexHull::~hkgpConvexHull(&v7);
}

// File Line: 51
// RVA: 0xCA37C0
void __fastcall hkGeometryUtility::createVerticesFromPlaneEquations(hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn, hkArray<hkVector4f,hkContainerHeapAllocator> *vertsOut)
{
  hkResult result; // [rsp+40h] [rbp+18h]

  hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(&result, planeEquationsIn, vertsOut);
}

// File Line: 57
// RVA: 0xCA37E0
void __fastcall hkGeometryUtility::createGeometryFromPlaneEquations(hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn, hkGeometry *geometryOut)
{
  hkGeometry *v2; // rbx
  hkArray<hkVector4f,hkContainerHeapAllocator> vertexCloudOut; // [rsp+20h] [rbp-28h]
  hkStridedVertices stridedVertsIn; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+60h] [rbp+18h]

  v2 = geometryOut;
  vertexCloudOut.m_capacityAndFlags = 2147483648;
  vertexCloudOut.m_data = 0i64;
  vertexCloudOut.m_size = 0;
  hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(&result, planeEquationsIn, &vertexCloudOut);
  if ( vertexCloudOut.m_size <= 0 )
  {
    v2->m_triangles.m_size = 0;
    v2->m_vertices.m_size = 0;
  }
  else
  {
    stridedVertsIn.m_numVertices = vertexCloudOut.m_size;
    stridedVertsIn.m_striding = 16;
    stridedVertsIn.m_vertices = vertexCloudOut.m_data->m_quad.m128_f32;
    hkGeometryUtility::createConvexGeometry(&stridedVertsIn, v2);
  }
  vertexCloudOut.m_size = 0;
  if ( vertexCloudOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertexCloudOut.m_data,
      16 * vertexCloudOut.m_capacityAndFlags);
}

// File Line: 80
// RVA: 0xCA3FB0
void __fastcall hkGeometryUtility::expandPlanes(hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, float byDistance)
{
  int v2; // eax
  __m128 v3; // xmm2
  __int64 v4; // rdx

  v2 = 0;
  v3 = _mm_shuffle_ps(
         (__m128)0i64,
         _mm_unpackhi_ps((__m128)0i64, _mm_shuffle_ps((__m128)LODWORD(byDistance), (__m128)LODWORD(byDistance), 0)),
         196);
  if ( planeEquations->m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v2;
      ++v4;
      planeEquations->m_data[v4 - 1].m_quad = _mm_sub_ps(planeEquations->m_data[v4 - 1].m_quad, v3);
    }
    while ( v2 < planeEquations->m_size );
  }
}

// File Line: 117
// RVA: 0xCA4010
void __fastcall getMeanAndCovariance(const float *vertexArray, int numVertices, int striding, hkMatrix3f *cov, hkVector4f *mu, hkBool perturb)
{
  int v6; // er10
  __int64 v7; // r14
  signed int v8; // er8
  hkMatrix3f *v9; // rbx
  __m128 v10; // xmm8
  const float *v11; // rdi
  __m128 v12; // xmm15
  __m128 v13; // xmm14
  __m128 *v14; // r9
  int v15; // eax
  int v16; // esi
  int v17; // er9
  __int64 v18; // r12
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  float v21; // xmm1_4
  __int64 v22; // r11
  unsigned int *v23; // r8
  signed __int64 v24; // rcx
  float *v25; // rdx
  __m128 v26; // xmm0
  __m128 v27; // xmm11
  unsigned int *v28; // r8
  unsigned __int64 *v29; // rdi
  __m128 v30; // xmm6
  __m128 v31; // xmm11
  __m128 v32; // xmm0
  unsigned int *v33; // r8
  unsigned __int64 *v34; // rdi
  __m128 v35; // xmm12
  __m128 v36; // xmm6
  __m128 v37; // xmm0
  __m128 v38; // xmm12
  int v39; // ecx
  float v40; // xmm0_4
  int v41; // ecx
  signed int v42; // eax
  int v43; // ecx
  float v44; // xmm0_4
  int v45; // eax
  __m128 v46; // xmm1
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm7
  float v55; // xmm9_4
  float v56; // xmm10_4
  __m128 v57; // xmm6
  char *v58; // rcx
  char *v59; // rsi
  char *v60; // r14
  signed __int64 v61; // rax
  signed __int64 v62; // r10
  float v63; // xmm11_4
  __m128 v64; // xmm6
  float v65; // xmm12_4
  __m128 v66; // xmm6
  float v67; // xmm4_4
  float v68; // xmm5_4
  float v69; // xmm1_4
  float v70; // xmm6_4
  float v71; // xmm2_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  float v75; // xmm6_4
  __m128 v76; // xmm0
  float v77; // xmm10_4
  float v78; // xmm7_4
  float v79; // xmm5_4
  float v80; // xmm8_4
  float v81; // xmm2_4
  float v82; // xmm4_4
  float v83; // xmm1_4
  float v84; // xmm6_4
  float v85; // xmm1_4
  float v86; // xmm4_4
  float v87; // xmm3_4
  float v88; // xmm10_4
  __m128 v89; // xmm2
  __m128 v90; // xmm14
  float v91; // xmm5_4
  float v92; // xmm6_4
  float v93; // xmm0_4
  float v94; // xmm4_4
  float v95; // xmm3_4
  __m128 *array; // [rsp+38h] [rbp-C0h]
  int v97; // [rsp+40h] [rbp-B8h]
  int v98; // [rsp+44h] [rbp-B4h]
  __m128 v99; // [rsp+50h] [rbp-A8h]
  __m128 v100; // [rsp+60h] [rbp-98h]
  __m128 v101; // [rsp+70h] [rbp-88h]
  float v102; // [rsp+80h] [rbp-78h]
  void *retaddr; // [rsp+168h] [rbp+70h]
  int v104; // [rsp+170h] [rbp+78h]
  __m128 *v105; // [rsp+188h] [rbp+90h]

  v6 = numVertices;
  v7 = striding;
  v8 = 2147483648;
  v9 = cov;
  v10 = 0i64;
  v11 = vertexArray;
  array = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v98 = 2147483648;
  v15 = 0;
  v97 = 0;
  v16 = numVertices / 3;
  if ( numVertices / 3 <= 0 )
  {
    LODWORD(retaddr) = 0;
  }
  else
  {
    v17 = numVertices / 3;
    if ( v16 < 0 )
      v17 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v17,
      16);
    v8 = v98;
    v15 = v97;
    v14 = array;
    v6 = v104;
  }
  v9->m_col0 = 0i64;
  v18 = v16;
  v97 = v16 + v15;
  v9->m_col1 = 0i64;
  v9->m_col2 = 0i64;
  if ( v16 > 0 )
  {
    v19 = (__m128)_xmm;
    v20 = *(__m128 *)_xmm;
    v21 = FLOAT_2_3283064eN10;
    v22 = v7;
    v23 = (unsigned int *)(v11 + 2);
    v24 = -32i64 - (_QWORD)v9;
    v25 = (float *)&v14->m128_u64[1];
    do
    {
      v26 = (__m128)*v23;
      v27 = (__m128)*(unsigned __int64 *)v11;
      v28 = (unsigned int *)((char *)v23 + v22);
      v29 = (unsigned __int64 *)((char *)v11 + v22);
      v30 = (__m128)*v29;
      v31 = _mm_movelh_ps(v27, v26);
      v32 = (__m128)*v28;
      v100 = v31;
      v33 = (unsigned int *)((char *)v28 + v22);
      v34 = (unsigned __int64 *)((char *)v29 + v22);
      v35 = (__m128)*v34;
      v36 = _mm_movelh_ps(v30, v32);
      v37 = (__m128)*v33;
      v101 = v36;
      v11 = (const float *)((char *)v34 + v22);
      v23 = (unsigned int *)((char *)v33 + v22);
      v38 = _mm_movelh_ps(v35, v37);
      *(__m128 *)((char *)&v101 + 8) = v38;
      if ( (_BYTE)mu )
      {
        v39 = 1664525 * v6 + 1013904223;
        v40 = (float)v39;
        v41 = 1664525 * v39 + 1013904223;
        v42 = v41;
        v43 = 1664525 * v41 + 1013904223;
        v99.m128_f32[0] = v40 * v21;
        v99.m128_f32[1] = (float)v42 * v21;
        v44 = (float)v43;
        v45 = 1664525 * v43 + 1013904223;
        v24 = -32i64 - (_QWORD)v9;
        v99.m128_f32[2] = v44 * v21;
        v99.m128_f32[3] = (float)v45 * v21;
        v46 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0), v99), v31);
      }
      else
      {
        v46 = v31;
      }
      v47 = _mm_sub_ps(v46, v36);
      v48 = _mm_sub_ps(v31, v38);
      v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v48));
      v50 = _mm_shuffle_ps(v49, v49, 201);
      v51 = _mm_mul_ps(v50, v50);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = _mm_rsqrt_ps(v52);
      v54 = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v52, v10),
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps(v19, _mm_mul_ps(_mm_mul_ps(v53, v52), v53)), _mm_mul_ps(v53, v20)),
                  v52)),
              (__m128)xmmword_141A711B0);
      if ( v54.m128_f32[0] <= v10.m128_f32[0] )
      {
        v76 = _mm_add_ps(_mm_add_ps(v36, v31), v38);
        LODWORD(v77) = (unsigned __int128)_mm_shuffle_ps(v36, v36, 170);
        LODWORD(v78) = (unsigned __int128)_mm_shuffle_ps(v31, v31, 85);
        *v14 = v76;
        LODWORD(v79) = (unsigned __int128)_mm_shuffle_ps(v38, v38, 85);
        LODWORD(v80) = (unsigned __int128)_mm_shuffle_ps(v31, v31, 170);
        LODWORD(v81) = (unsigned __int128)_mm_shuffle_ps(v36, v36, 85);
        *v14 = _mm_mul_ps(v76, (__m128)xmmword_141A711C0);
        v82 = v77 * v36.m128_f32[0];
        v9->m_col0.m_quad.m128_f32[0] = (float)((float)((float)(v36.m128_f32[0] * v36.m128_f32[0])
                                                      + (float)(v31.m128_f32[0] * v31.m128_f32[0]))
                                              + (float)(v38.m128_f32[0] * v38.m128_f32[0]))
                                      + v9->m_col0.m_quad.m128_f32[0];
        v83 = v81 * v36.m128_f32[0];
        LODWORD(v84) = (unsigned __int128)_mm_shuffle_ps(v38, v38, 170);
        v85 = (float)(v83 + (float)(v78 * v31.m128_f32[0])) + (float)(v79 * v38.m128_f32[0]);
        v9->m_col1.m_quad.m128_f32[0] = v85 + v9->m_col1.m_quad.m128_f32[0];
        v86 = (float)(v82 + (float)(v80 * v31.m128_f32[0])) + (float)(v84 * v38.m128_f32[0]);
        v9->m_col2.m_quad.m128_f32[0] = v86 + v9->m_col2.m_quad.m128_f32[0];
        v9->m_col0.m_quad.m128_f32[1] = v85 + v9->m_col0.m_quad.m128_f32[1];
        v9->m_col1.m_quad.m128_f32[1] = (float)((float)((float)(v81 * v81) + (float)(v78 * v78)) + (float)(v79 * v79))
                                      + v9->m_col1.m_quad.m128_f32[1];
        v87 = (float)((float)(v77 * v81) + (float)(v80 * v78)) + (float)(v84 * v79);
        v9->m_col2.m_quad.m128_f32[1] = v87 + v9->m_col2.m_quad.m128_f32[1];
        v9->m_col0.m_quad.m128_f32[2] = v86 + v9->m_col0.m_quad.m128_f32[2];
        v9->m_col1.m_quad.m128_f32[2] = v87 + v9->m_col1.m_quad.m128_f32[2];
        v88 = (float)((float)(v77 * v77) + (float)(v80 * v80)) + (float)(v84 * v84);
        v10 = 0i64;
        v9->m_col2.m_quad.m128_f32[2] = v88 + v9->m_col2.m_quad.m128_f32[2];
      }
      else
      {
        v55 = v100.m128_f32[2];
        v56 = v100.m128_f32[1];
        v57 = _mm_add_ps(v36, v31);
        v58 = (char *)v14 + v24;
        v59 = (char *)((char *)&v100 - (char *)v9);
        v60 = (char *)((char *)&v101 - (char *)v9);
        v61 = (signed __int64)&v9->m_col2;
        v62 = 3i64;
        v63 = v100.m128_f32[0];
        v64 = _mm_add_ps(v57, v38);
        v65 = v101.m128_f32[2];
        v66 = _mm_mul_ps(v64, (__m128)xmmword_141A711C0);
        v12 = _mm_add_ps(v12, v54);
        *v14 = v66;
        v13 = _mm_add_ps(v13, _mm_mul_ps(v54, v66));
        do
        {
          v67 = *(float *)&v59[v61 - 32];
          v68 = *(float *)&v60[v61 - 32];
          v69 = *(float *)&v60[v61 - 32] * v101.m128_f32[0];
          v70 = *(float *)((char *)&v101.m128_u16[4] - (char *)v9 + v61 - 32);
          v71 = (float)((float)(*(float *)&v58[v61] * 9.0) * *(v25 - 2)) + (float)(*(float *)&v59[v61 - 32] * v63);
          v61 += 4i64;
          v72 = v71 + v69;
          v73 = v68 * v101.m128_f32[1];
          *(float *)(v61 - 36) = (float)((float)(v72 + (float)(v70 * v101.m128_f32[2])) * v54.m128_f32[0])
                               + *(float *)(v61 - 36);
          v74 = v70;
          v75 = v70 * v102;
          *(float *)(v61 - 20) = (float)((float)((float)((float)((float)((float)(*(float *)&v58[v61 - 4] * 9.0)
                                                                       * *(v25 - 1))
                                                               + (float)(v67 * v56))
                                                       + v73)
                                               + (float)(v74 * v101.m128_f32[3]))
                                       * v54.m128_f32[0])
                               + *(float *)(v61 - 20);
          *(float *)(v61 - 4) = (float)((float)((float)((float)((float)((float)(*(float *)&v58[v61 - 4] * 9.0) * *v25)
                                                              + (float)(v67 * v55))
                                                      + (float)(v68 * v65))
                                              + v75)
                                      * v54.m128_f32[0])
                              + *(float *)(v61 - 4);
          --v62;
        }
        while ( v62 );
      }
      v19 = (__m128)_xmm;
      v20 = *(__m128 *)_xmm;
      v21 = FLOAT_2_3283064eN10;
      v24 = -32i64 - (_QWORD)v9;
      v6 = v104;
      v25 += 4;
      ++v14;
      --v18;
    }
    while ( v18 );
    v8 = v98;
    v14 = array;
  }
  if ( v12.m128_f32[0] > v10.m128_f32[0] )
  {
    v89 = _mm_rcp_ps(v12);
    v90 = _mm_mul_ps(v13, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v89, v12)), v89));
    LODWORD(v91) = (unsigned __int128)_mm_shuffle_ps(v90, v90, 85);
    LODWORD(v92) = (unsigned __int128)_mm_shuffle_ps(v90, v90, 170);
    v93 = v9->m_col1.m_quad.m128_f32[0];
    v9->m_col0.m_quad.m128_f32[0] = (float)(v9->m_col0.m_quad.m128_f32[0] * 0.083333336)
                                  - (float)((float)(v90.m128_f32[0] * v90.m128_f32[0]) * v12.m128_f32[0]);
    v89.m128_f32[0] = (float)(v91 * v90.m128_f32[0]) * v12.m128_f32[0];
    v94 = (float)(v92 * v90.m128_f32[0]) * v12.m128_f32[0];
    v9->m_col1.m_quad.m128_f32[0] = (float)(v93 * 0.083333336) - v89.m128_f32[0];
    v9->m_col2.m_quad.m128_f32[0] = (float)(v9->m_col2.m_quad.m128_f32[0] * 0.083333336) - v94;
    v95 = (float)(v92 * v91) * v12.m128_f32[0];
    v9->m_col0.m_quad.m128_f32[1] = (float)(v9->m_col0.m_quad.m128_f32[1] * 0.083333336) - v89.m128_f32[0];
    v9->m_col1.m_quad.m128_f32[1] = (float)(v9->m_col1.m_quad.m128_f32[1] * 0.083333336)
                                  - (float)((float)(v91 * v91) * v12.m128_f32[0]);
    v9->m_col2.m_quad.m128_f32[1] = (float)(v9->m_col2.m_quad.m128_f32[1] * 0.083333336) - v95;
    v9->m_col0.m_quad.m128_f32[2] = (float)(v9->m_col0.m_quad.m128_f32[2] * 0.083333336) - v94;
    v9->m_col1.m_quad.m128_f32[2] = (float)(v9->m_col1.m_quad.m128_f32[2] * 0.083333336) - v95;
    v9->m_col2.m_quad.m128_f32[2] = (float)(v9->m_col2.m_quad.m128_f32[2] * 0.083333336)
                                  - (float)((float)(v92 * v92) * v12.m128_f32[0]);
    *v105 = v90;
  }
  else
  {
    *v105 = v10;
    v9->m_col0 = (hkVector4f)transform.m_quad;
    v9->m_col1 = (hkVector4f)direction.m_quad;
    v9->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  }
  v97 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v14,
      16 * v8);
}0;
    v9->m_col0 = (hkVector4f)transfo

// File Line: 277
// RVA: 0xCA4810
hkBool *__fastcall makeEigenvectors(hkBool *result, hkMatrix3f *mat, int max_iters)
{
  int v3; // ebx
  hkMatrix3f *v4; // r11
  hkBool *v5; // rsi
  signed __int64 v6; // r9
  hkMatrix3f *v7; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  int v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm3_4
  int v23; // xmm0_4
  int v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  signed int v27; // edi
  signed __int64 v28; // r8
  int i; // er10
  signed __int64 v30; // rcx
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  signed __int64 v36; // rdx
  int v37; // xmm4_4
  int v38; // xmm5_4
  float v39; // xmm8_4
  float v40; // xmm6_4
  float *v41; // r9
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm6_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm0_4
  int v64; // [rsp+0h] [rbp-59h]
  int v65; // [rsp+4h] [rbp-55h]
  int v66[2]; // [rsp+8h] [rbp-51h]
  float v67; // [rsp+10h] [rbp-49h]
  float v68; // [rsp+14h] [rbp-45h]
  int v69; // [rsp+18h] [rbp-41h]
  float vars0; // [rsp+C8h] [rbp+6Fh]

  v3 = max_iters;
  v4 = mat;
  v5 = result;
  v6 = 3i64;
  v7 = mat;
  v8 = 0i64;
  do
  {
    v9 = _mm_mul_ps(v7->m_col0.m_quad, v7->m_col0.m_quad);
    v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    if ( v10.m128_f32[0] > v8.m128_f32[0] )
      v8 = v10;
    v7 = (hkMatrix3f *)((char *)v7 + 16);
    --v6;
  }
  while ( v6 );
  if ( v8.m128_f32[0] != 0.0 )
  {
    LODWORD(v11) = (unsigned __int128)_mm_rsqrt_ps(v8);
    v12 = (float)(3.0 - (float)((float)(v8.m128_f32[0] * v11) * v11)) * (float)(0.5 * v11);
    v13 = v12 * mat->m_col1.m_quad.m128_f32[0];
    mat->m_col0.m_quad.m128_f32[0] = v12 * mat->m_col0.m_quad.m128_f32[0];
    mat->m_col1.m_quad.m128_f32[0] = v13;
    mat->m_col2.m_quad.m128_f32[0] = v12 * mat->m_col2.m_quad.m128_f32[0];
    mat->m_col0.m_quad.m128_f32[1] = v12 * mat->m_col0.m_quad.m128_f32[1];
    mat->m_col1.m_quad.m128_f32[1] = v12 * mat->m_col1.m_quad.m128_f32[1];
    mat->m_col2.m_quad.m128_f32[1] = v12 * mat->m_col2.m_quad.m128_f32[1];
    mat->m_col0.m_quad.m128_f32[2] = v12 * mat->m_col0.m_quad.m128_f32[2];
    mat->m_col1.m_quad.m128_f32[2] = v12 * mat->m_col1.m_quad.m128_f32[2];
    mat->m_col2.m_quad.m128_f32[2] = v12 * mat->m_col2.m_quad.m128_f32[2];
  }
  v14 = mat->m_col2.m_quad.m128_f32[0];
  v15 = mat->m_col0.m_quad.m128_i32[0];
  v69 = 0;
  v64 = v15;
  if ( v14 == 0.0 )
  {
    v24 = mat->m_col2.m_quad.m128_i32[2];
    v65 = mat->m_col1.m_quad.m128_i32[1];
    v25 = mat->m_col1.m_quad.m128_f32[0];
    v66[0] = v24;
    v26 = mat->m_col2.m_quad.m128_f32[1];
    v67 = v25;
    mat->m_col0 = (hkVector4f)transform.m_quad;
    v68 = v26;
    mat->m_col1 = (hkVector4f)direction.m_quad;
    mat->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  }
  else
  {
    v16 = mat->m_col1.m_quad.m128_f32[0];
    v17 = mat->m_col2.m_quad.m128_f32[2];
    v18 = mat->m_col2.m_quad.m128_f32[1];
    mat->m_col0.m_quad.m128_u64[0] = 1065353216i64;
    mat->m_col1.m_quad.m128_i32[0] = 0;
    mat->m_col2.m_quad.m128_i32[0] = 0;
    mat->m_col0.m_quad.m128_i32[2] = 0;
    vars0 = (float)(v16 * v16) + (float)(v14 * v14);
    v67 = fsqrt(vars0);
    v19 = (float)(1.0 / v67) * v14;
    v20 = (float)(1.0 / v67) * v16;
    v21 = (float)(v17 - mat->m_col1.m_quad.m128_f32[1]) * v19;
    mat->m_col2.m_quad.m128_f32[1] = v19;
    mat->m_col1.m_quad.m128_f32[2] = v19;
    v22 = v21 + (float)((float)(v20 * 2.0) * v18);
    v68 = v18 - (float)(v22 * v20);
    *(float *)&v23 = (float)(v22 * v19) + mat->m_col1.m_quad.m128_f32[1];
    mat->m_col1.m_quad.m128_f32[1] = v20;
    *(float *)v66 = v17 - (float)(v22 * v19);
    v65 = v23;
    mat->m_col2.m_quad.m128_i32[2] = LODWORD(v20) ^ _xmm[0];
  }
  v27 = 0;
  v28 = 0i64;
  while ( 1 )
  {
    for ( i = 0; i < v3; *((float *)&v64 + v28) = v62 - v39 )
    {
      v30 = v28;
      if ( v28 > 1 )
        break;
      do
      {
        vars0 = *(&v67 + v30);
        if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(vars0)) >> 1) < 0.000001 )
          break;
        ++v30;
      }
      while ( v30 <= 1 );
      if ( v30 == v28 )
        break;
      v31 = *(&v67 + v28);
      v32 = *((float *)&v64 + v28);
      v33 = (float)(*((float *)&v65 + v28) - v32) / (float)(*(&v67 + v28) * 2.0);
      vars0 = (float)(v33 * v33) + 1.0;
      v34 = fsqrt(vars0);
      if ( v33 >= 0.0 )
        v35 = v31 / (float)(v34 + v33);
      else
        v35 = v31 / (float)(v33 - v34);
      v36 = v30 - 1;
      v37 = (int)FLOAT_1_0;
      v38 = (int)FLOAT_1_0;
      v39 = 0.0;
      v40 = v35 + (float)(*((float *)&v64 + v30) - v32);
      if ( v30 - 1 >= v28 )
      {
        v41 = &v4->m_col1.m_quad.m128_f32[4 * v36 + 1];
        do
        {
          v42 = *(&v67 + v36);
          v43 = v42 * *(float *)&v38;
          v44 = v42 * *(float *)&v37;
          vars0 = v44;
          if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v44)) >> 1) <= COERCE_FLOAT((unsigned int)(2 * LODWORD(v40)) >> 1) )
          {
            v47 = (float)(-1.0 / v40) * v44;
            vars0 = (float)(v47 * v47) + 1.0;
            v48 = -1.0 / fsqrt(vars0);
            *(float *)&v37 = v47 * v48;
            v38 = LODWORD(v48) ^ _xmm[0];
            *(&v68 + v36) = v40 / *(float *)&v38;
          }
          else
          {
            v45 = (float)(-1.0 / v44) * v40;
            vars0 = (float)(v45 * v45) + 1.0;
            v46 = -1.0 / fsqrt(vars0);
            *(float *)&v38 = v45 * v46;
            v37 = LODWORD(v46) ^ _xmm[0];
            *(&v68 + v36) = v44 / *(float *)&v37;
          }
          v49 = *((float *)&v65 + v36);
          v50 = *((float *)&v64 + v36--);
          v41 -= 4;
          v51 = v49 - v39;
          v52 = (float)((float)(v50 - v51) * *(float *)&v37) + (float)((float)(v43 * 2.0) * *(float *)&v38);
          v39 = *(float *)&v37 * v52;
          v53 = *(float *)&v38 * v52;
          v54 = v41[3];
          v40 = v53 - v43;
          v55 = *(v41 - 1);
          *(float *)&v66[v36] = v39 + v51;
          v41[3] = (float)(v55 * *(float *)&v37) + (float)(*(float *)&v38 * v54);
          v56 = *(float *)&v37 * v54;
          v57 = v41[4];
          *(v41 - 1) = (float)(v55 * *(float *)&v38) - v56;
          v58 = *v41 * *(float *)&v38;
          v41[4] = (float)(*v41 * *(float *)&v37) + (float)(*(float *)&v38 * v57);
          v59 = *(float *)&v37 * v57;
          v60 = v41[5];
          *v41 = v58 - v59;
          v61 = v41[1];
          v41[5] = (float)(v41[1] * *(float *)&v37) + (float)(*(float *)&v38 * v60);
          v41[1] = (float)(v61 * *(float *)&v38) - (float)(*(float *)&v37 * v60);
        }
        while ( v36 >= v28 );
      }
      v62 = *((float *)&v64 + v28);
      ++i;
      *(&v67 + v28) = v40;
      *(&v67 + v30) = 0.0;
    }
    if ( i == v3 )
      break;
    ++v27;
    ++v28;
    if ( v27 >= 3 )
    {
      v5->m_bool = 1;
      return v5;
    }
  }
  v5->m_bool = 0;
  return v5;
}

// File Line: 449
// RVA: 0xCA3890
hkBool *__fastcall hkGeometryUtility::getAxesFromCovariance(hkBool *result, hkMatrix3f *covArray, hkVector4f *axis0, hkVector4f *axis1, hkVector4f *axis2)
{
  hkVector4f *v5; // rsi
  hkVector4f *v6; // rdi
  hkMatrix3f *v7; // rbp
  hkBool *v8; // rbx
  hkVector4f v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm2

  v5 = axis0;
  v6 = axis1;
  v7 = covArray;
  v8 = result;
  makeEigenvectors(result, covArray, 30);
  if ( v8->m_bool )
  {
    *v5 = v7->m_col0;
    *v6 = v7->m_col1;
    v9.m_quad = (__m128)v7->m_col2;
    *axis2 = (hkVector4f)v9.m_quad;
    v10 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 201), v5->m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 201), v6->m_quad));
    v11 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9.m_quad);
    axis2->m_quad = _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmpltps(
                                             _mm_add_ps(
                                               _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                                               _mm_shuffle_ps(v11, v11, 170)),
                                             (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v9.m_quad);
  }
  else
  {
    *v5 = (hkVector4f)transform.m_quad;
    *v6 = (hkVector4f)direction.m_quad;
    *axis2 = (hkVector4f)stru_141A71280.m_quad;
  }
  return v8;
}

// File Line: 483
// RVA: 0xCA4DC0
signed __int64 __fastcall isMultOfXYorZ(hkVector4f *v, hkSimdFloat32 *epsilon)
{
  signed __int64 result; // rax
  __m128 v3; // xmm2

  result = 0i64;
  v3 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v), 1u), 1u);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     fmax(
                                       COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 170)),
                                       fmax(
                                         COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 85)),
                                         COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 0))))
                                   - 1.0)) >> 1) < epsilon->m_real.m128_f32[0] )
    result = 1i64;
  return result;
}

// File Line: 492
// RVA: 0xCA4E10
__int64 __fastcall getIsBoxGeometry(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkVector4f *halfExtents, hkTransformf *boxToGeom, const float epsilonR)
{
  hkVector4f *v4; // r12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // r13
  float v6; // xmm12_4
  hkSphere *v7; // rax
  __m128 v8; // xmm6
  float v9; // xmm7_4
  __m128 *v10; // rax
  __int64 v11; // rsi
  int v12; // er15
  __m128 *v13; // rdi
  signed int v14; // er8
  int v15; // eax
  __int64 v16; // rbx
  hkVector4f *v17; // r14
  __m128 v18; // xmm1
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 *v22; // rbx
  __m128 *v23; // rcx
  __m128 v24; // xmm7
  __m128 v25; // xmm10
  __m128 v26; // xmm11
  __m128 v27; // xmm10
  signed __int64 v28; // rax
  __m128 v29; // xmm6
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  float v33; // xmm1_4
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm9
  __m128 v37; // xmm9
  __m128 v38; // xmm6
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm7
  __m128 v42; // xmm1
  __m128 v43; // xmm4
  __m128 v44; // xmm8
  __m128 v45; // xmm5
  __m128 *v46; // rax
  signed __int64 v47; // rcx
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  signed __int64 v50; // rax
  __m128 v51; // xmm2
  signed int v52; // er8
  __m128 *v53; // r9
  __m128 v54; // xmm4
  hkTransformf *v55; // rbx
  hkTransformf *v56; // rcx
  __m128 v57; // xmm0
  __m128 v58; // xmm2
  __m128 v59; // xmm2
  __m128 v60; // xmm2
  __m128i v61; // xmm1
  __m128i v62; // xmm0
  __int64 v63; // r8
  __int64 v64; // rcx
  __m128 v65; // xmm3
  __m128 *v66; // rdx
  unsigned __int8 v67; // bl
  __m128 *array; // [rsp+20h] [rbp-C0h]
  int v70; // [rsp+28h] [rbp-B8h]
  int v71; // [rsp+2Ch] [rbp-B4h]
  hkResult v72; // [rsp+30h] [rbp-B0h]
  hkMatrix3f v73; // [rsp+40h] [rbp-A0h]
  hkStridedVertices stridedVertsIn; // [rsp+70h] [rbp-70h]
  hkVector4f v75; // [rsp+80h] [rbp-60h]
  __m128 v76; // [rsp+90h] [rbp-50h]
  hkSphere result; // [rsp+A0h] [rbp-40h]
  int v78; // [rsp+190h] [rbp+B0h]
  hkTransformf *t; // [rsp+1A0h] [rbp+C0h]
  void *retaddr; // [rsp+1A8h] [rbp+C8h]

  v4 = halfExtents;
  v5 = vertices;
  stridedVertsIn.m_striding = 16;
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  stridedVertsIn.m_numVertices = vertices->m_size;
  stridedVertsIn.m_vertices = vertices->m_data->m_quad.m128_f32;
  v7 = hkGeometryUtility::createMinBoundingSphere(&result, &stridedVertsIn, 0.0000099999997);
  v78 = 128;
  v8 = v7->m_pos.m_quad;
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(v8, v8, 255);
  v10 = (__m128 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    &v78);
  v11 = v5->m_size;
  v12 = 2147483648;
  v13 = v10;
  v14 = 2147483648;
  array = 0i64;
  v71 = 2147483648;
  if ( v78 / 16 )
    v12 = v78 / 16;
  v15 = 0;
  v70 = 0;
  if ( v11 > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v5->m_data;
      v18 = _mm_sub_ps(v5->m_data[v16].m_quad, v8);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      if ( COERCE_FLOAT((unsigned int)(2
                                     * COERCE_SIGNED_INT(
                                         COERCE_FLOAT(
                                           _mm_andnot_ps(
                                             _mm_cmpleps(v20, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                 _mm_mul_ps(*(__m128 *)_xmm, v21)),
                                               v20)))
                                       - v9)) >> 1) < v6 )
      {
        if ( v15 == (v14 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v15 = v70;
        }
        array[v15] = v17[v16].m_quad;
        v14 = v71;
        v15 = v70++ + 1;
      }
      ++v16;
      --v11;
    }
    while ( v11 );
    if ( v15 == 8 )
    {
      v22 = v13 + 1;
      v23 = v13 + 3;
      *v13 = *array;
      v24 = *v13;
      v25 = *v13;
      v13[1] = array[1];
      v26 = _mm_sub_ps(v24, v13[1]);
      v13[2] = array[2];
      v27 = _mm_sub_ps(v25, v13[2]);
      v13[3] = array[3];
      v13[4] = array[4];
      v13[5] = array[5];
      v13[6] = array[6];
      v28 = 5i64;
      v13[7] = array[7];
      do
      {
        v29 = _mm_sub_ps(v24, *v23);
        v30 = _mm_mul_ps(v26, v26);
        v31 = _mm_mul_ps(v29, v29);
        v32 = _mm_mul_ps(v27, v27);
        LODWORD(v33) = (unsigned __int128)_mm_shuffle_ps(v32, v32, 85);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 170))) >= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                                                                   + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                                                                           + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) )
        {
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 170))) < (float)((float)(v33
                                                                                    + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                                                                            + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170))) )
            v27 = v29;
        }
        else
        {
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) < (float)((float)(v33
                                                                                    + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                                                                            + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170))) )
            v27 = v26;
          v26 = v29;
        }
        ++v23;
        --v28;
      }
      while ( v28 );
      v72.m_enum = 925353388;
      v34 = _mm_mul_ps(v27, v26);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170))) <= COERCE_FLOAT(
                                                                     _mm_shuffle_ps(
                                                                       (__m128)0x3727C5ACu,
                                                                       (__m128)0x3727C5ACu,
                                                                       0)) )
      {
        v35 = _mm_mul_ps(v26, v26);
        v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v27));
        v37 = _mm_shuffle_ps(v36, v36, 201);
        v38 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                _mm_shuffle_ps(v35, v35, 170));
        v39 = _mm_mul_ps(v27, v27);
        v40 = _mm_rsqrt_ps(v38);
        v41 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                _mm_shuffle_ps(v39, v39, 170));
        v42 = _mm_mul_ps(v37, v37);
        v43 = _mm_rsqrt_ps(v41);
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                _mm_shuffle_ps(v42, v42, 170));
        v45 = _mm_rsqrt_ps(v44);
        v73.m_col0.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v38, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v38), v40)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v40))),
                              v26);
        v73.m_col1.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v41, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v41), v43)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v43))),
                              v27);
        v73.m_col2.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v44, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v45))),
                              v37);
        hkMatrix3f::invert(&v73, &v72, 0.0099999998);
        v46 = v13;
        v47 = 8i64;
        do
        {
          v48 = *v46;
          ++v46;
          v46[-1] = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v73.m_col1.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v73.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v73.m_col2.m_quad));
          --v47;
        }
        while ( v47 );
        v49 = *v13;
        v50 = 7i64;
        v51 = *v13;
        do
        {
          v49 = _mm_min_ps(v49, *v22);
          v51 = _mm_max_ps(v51, *v22);
          ++v22;
          --v50;
        }
        while ( v50 );
        v52 = 0;
        v53 = v13;
        v72.m_enum = LODWORD(FLOAT_0_001);
        v54 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
        while ( ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(
                                                        _mm_slli_epi32((__m128i)_mm_sub_ps(*v53, v49), 1u),
                                                        1u), v54)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                    _mm_cmpltps(
                                                                                      (__m128)_mm_srli_epi32(
                                                                                                _mm_slli_epi32(
                                                                                                  (__m128i)_mm_sub_ps(*v53, v51),
                                                                                                  1u),
                                                                                                1u),
                                                                                      v54)) & 7) == 7) )
        {
          ++v52;
          ++v53;
          if ( v52 >= 8 )
          {
            v55 = t;
            v56 = t;
            v57 = _mm_sub_ps(v51, v49);
            stridedVertsIn = (hkStridedVertices)v73.m_col1;
            *v4 = (hkVector4f)v57;
            v4->m_quad = _mm_mul_ps(v57, (__m128)xmmword_141A711B0);
            v73.m_col2 = v73.m_col0;
            v76 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0), _mm_add_ps(v51, v49));
            v75.m_quad = (__m128)v73.m_col0;
            hkTransformf::setInverse(v56, (hkTransformf *)&v73.m_col2);
            v58 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73), 1u), 1u);
            if ( COERCE_FLOAT((unsigned int)(2
                                           * COERCE_SIGNED_INT(
                                               fmax(
                                                 COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 170)),
                                                 fmax(
                                                   COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 85)),
                                                   COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 0))))
                                             - 1.0)) >> 1) < v6 )
            {
              v59 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73.m_col1), 1u), 1u);
              if ( COERCE_FLOAT((unsigned int)(2
                                             * COERCE_SIGNED_INT(
                                                 fmax(
                                                   COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 170)),
                                                   fmax(
                                                     COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85)),
                                                     COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 0))))
                                               - 1.0)) >> 1) < v6 )
              {
                v60 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73.m_col2), 1u), 1u);
                if ( COERCE_FLOAT((unsigned int)(2
                                               * COERCE_SIGNED_INT(
                                                   fmax(
                                                     COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 170)),
                                                     fmax(
                                                       COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 85)),
                                                       COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 0))))
                                                 - 1.0)) >> 1) < v6 )
                {
                  v61 = (__m128i)_mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v4->m_quad, v4->m_quad, 0),
                                       v55->m_rotation.m_col0.m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v4->m_quad, v4->m_quad, 85),
                                       v55->m_rotation.m_col1.m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v4->m_quad, v4->m_quad, 170),
                                     v55->m_rotation.m_col2.m_quad));
                  *v4 = (hkVector4f)v61;
                  v62 = _mm_srli_si128(_mm_slli_si128(v61, 4), 4);
                  *v4 = (hkVector4f)v62;
                  *(__m128i *)v4 = _mm_srli_epi32(_mm_slli_epi32(v62, 1u), 1u);
                  v73.m_col0 = (hkVector4f)transform.m_quad;
                  v73.m_col1 = (hkVector4f)direction.m_quad;
                  v73.m_col2 = (hkVector4f)stru_141A71280.m_quad;
                  v55->m_rotation.m_col0 = (hkVector4f)transform.m_quad;
                  v55->m_rotation.m_col1 = (hkVector4f)direction.m_quad;
                  v55->m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
                }
              }
            }
            hkTransformf::setInverse((hkTransformf *)&v73.m_col2, v55);
            v63 = v5->m_size;
            v64 = 0i64;
            v65 = _mm_mul_ps((__m128)_xmm, v4->m_quad);
            if ( v63 <= 0 )
            {
LABEL_35:
              v14 = v71;
              v67 = 1;
              goto LABEL_38;
            }
            v66 = &v5->m_data->m_quad;
            while ( !(_mm_movemask_ps(
                        _mm_cmpltps(
                          v65,
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(*v66, *v66, 85), (__m128)stridedVertsIn),
                                _mm_mul_ps(_mm_shuffle_ps(*v66, *v66, 0), v73.m_col2.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(*v66, *v66, 170), v75.m_quad)),
                            v76))) & 7) )
            {
              ++v64;
              ++v66;
              if ( v64 >= v63 )
                goto LABEL_35;
            }
            break;
          }
        }
      }
      v14 = v71;
    }
  }
  v67 = 0;
LABEL_38:
  v70 = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v14);
  array = 0i64;
  v71 = 2147483648;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      16 * v12);
  return v67;
}

// File Line: 668
// RVA: 0xCA56F0
void __fastcall makeOBBUsingAxes(const float *vertexArray, int numVertices, int striding, hkVector4f *extents, hkVector4f *axes, hkVector4f *position)
{
  const float *v6; // rax
  __m128 v7; // xmm6
  hkVector4f *v8; // r10
  __m128 v9; // xmm5
  __int64 v10; // r9
  __int64 v11; // r8
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  hkVector4f v24; // xmm0
  hkVector4f v25; // xmm1

  v6 = vertexArray;
  v7 = (__m128)_xmm;
  v8 = extents;
  v9 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)_xmm);
  if ( numVertices > 0 )
  {
    v10 = striding;
    v11 = (unsigned int)numVertices;
    do
    {
      v12 = (__m128)*(unsigned __int64 *)v6;
      v13 = (__m128)*((unsigned int *)v6 + 2);
      v6 = (const float *)((char *)v6 + v10);
      v14 = _mm_movelh_ps(v12, v13);
      v15 = _mm_mul_ps(axes[1].m_quad, v14);
      v16 = _mm_mul_ps(axes->m_quad, v14);
      v17 = _mm_mul_ps(axes[2].m_quad, v14);
      v18 = _mm_unpacklo_ps(v16, v15);
      v19 = _mm_movelh_ps(v18, v17);
      v20 = _mm_add_ps(
              _mm_shuffle_ps(_mm_unpackhi_ps(v16, v15), v17, 228),
              _mm_add_ps(v19, _mm_shuffle_ps(_mm_movehl_ps(v19, v18), v17, 212)));
      v7 = _mm_min_ps(v7, v20);
      v9 = _mm_max_ps(v9, v20);
      --v11;
    }
    while ( v11 );
  }
  v21 = v9;
  v22 = _mm_sub_ps(v9, v7);
  v23 = _mm_mul_ps(_mm_add_ps(v21, v7), (__m128)xmmword_141A711B0);
  *v8 = (hkVector4f)v22;
  v8->m_quad = _mm_mul_ps(v22, (__m128)xmmword_141A711B0);
  v24.m_quad = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), axes->m_quad);
  *position = (hkVector4f)v24.m_quad;
  v25.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), axes[1].m_quad), v24.m_quad);
  *position = (hkVector4f)v25.m_quad;
  position->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), axes[2].m_quad), v25.m_quad);
}

// File Line: 708
// RVA: 0xCA5820
hkSimdFloat32 *__fastcall getVolumeFromAxes(hkSimdFloat32 *result, const float *vertexArray, int numVertices, int striding, hkVector4f *axes)
{
  hkSimdFloat32 *v5; // rdi
  __m128 v6; // xmm6
  __m128 v7; // xmm10
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm10
  __m128 v17; // xmm10
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  hkSimdFloat32 *v21; // rax
  hkVector4f extents; // [rsp+30h] [rbp-A8h]
  hkVector4f position; // [rsp+40h] [rbp-98h]
  hkVector4f v24; // [rsp+50h] [rbp-88h]
  __m128 v25; // [rsp+60h] [rbp-78h]
  __m128 v26; // [rsp+70h] [rbp-68h]

  v5 = result;
  v6 = axes->m_quad;
  v7 = axes[1].m_quad;
  v8 = _mm_mul_ps(v6, v6);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(axes[1].m_quad, axes->m_quad);
  v24.m_quad = _mm_mul_ps(
                 axes->m_quad,
                 _mm_andnot_ps(
                   _mm_cmpleps(v9, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                     _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v12 = _mm_sub_ps(
          v7,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            v6));
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v25 = _mm_mul_ps(
          v12,
          _mm_andnot_ps(
            _mm_cmpleps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15))));
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v26 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmpleps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20))));
  makeOBBUsingAxes(vertexArray, numVertices, striding, &extents, &v24, &position);
  v21 = v5;
  v5->m_real = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(extents.m_quad, extents.m_quad, 85),
                   _mm_shuffle_ps(extents.m_quad, extents.m_quad, 0)),
                 _mm_shuffle_ps(extents.m_quad, extents.m_quad, 170));
  return v21;
}

// File Line: 738
// RVA: 0xCA5A20
void __fastcall getVolumeGradient(const float *vertexArray, int numVertices, int striding, hkVector4f *axes, hkSimdFloat32 *step, hkVector4f *gradOut)
{
  hkVector4f v6; // xmm1
  int v7; // er13
  hkVector4f *v8; // r14
  hkVector4f *v9; // rbx
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  signed __int64 v12; // r14
  signed __int64 v13; // r15
  __m128 v14; // xmm6
  __m128 *v15; // rsi
  __m128 *v16; // rdi
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  bool v22; // zf
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  hkSimdFloat32 result; // [rsp+40h] [rbp-98h]
  hkVector4f v30; // [rsp+50h] [rbp-88h]
  __m128 v31; // [rsp+60h] [rbp-78h]
  float *vertexArraya; // [rsp+E0h] [rbp+8h]
  int numVerticesa; // [rsp+E8h] [rbp+10h]
  signed __int64 v34; // [rsp+F8h] [rbp+20h]

  numVerticesa = numVertices;
  vertexArraya = (float *)vertexArray;
  v6.m_quad = (__m128)axes[1];
  v7 = striding;
  v8 = axes;
  v30.m_quad = axes->m_quad;
  v31 = v6.m_quad;
  getVolumeFromAxes(&result, vertexArray, numVertices, striding, axes);
  v9 = gradOut;
  v10 = result.m_real;
  v11 = _mm_rcp_ps(step->m_real);
  v34 = 2i64;
  v12 = (char *)v8 - (char *)&v30;
  v13 = (char *)&v30 - (char *)gradOut;
  v14 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(step->m_real, v11)), v11);
  do
  {
    v15 = (__m128 *)((char *)&v9->m_quad + v13);
    v16 = 0i64;
    do
    {
      v17 = _mm_and_ps(*v15, v16[337020912]);
      v18 = _mm_or_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      *v15 = _mm_or_ps(
               _mm_and_ps(_mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v18, v18, 177), v18), step->m_real), v16[337020912]),
               _mm_andnot_ps(v16[337020912], *v15));
      getVolumeFromAxes(&result, vertexArraya, numVerticesa, v7, &v30);
      ++v16;
      v19 = _mm_or_ps(
              _mm_and_ps(_mm_mul_ps(_mm_sub_ps(result.m_real, v10), v14), v16[337020911]),
              _mm_andnot_ps(v16[337020911], v9->m_quad));
      *v9 = (hkVector4f)v19;
      v20 = _mm_and_ps(*(__m128 *)((char *)v15 + v12), v16[337020911]);
      v21 = _mm_or_ps(_mm_shuffle_ps(v20, v20, 78), v20);
      *v15 = _mm_or_ps(
               _mm_and_ps(_mm_or_ps(_mm_shuffle_ps(v21, v21, 177), v21), v16[337020911]),
               _mm_andnot_ps(v16[337020911], *v15));
    }
    while ( (signed __int64)v16 < 48 );
    v13 = (char *)&v30 - (char *)gradOut;
    ++v9;
    v22 = v34-- == 1;
    v9[-1].m_quad = _mm_mul_ps(v19, g_vectorfConstants[0]);
  }
  while ( !v22 );
  v23 = gradOut->m_quad;
  v24 = _mm_mul_ps(gradOut[1].m_quad, gradOut[1].m_quad);
  v25 = _mm_mul_ps(v23, v23);
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  if ( v26.m128_f32[0] > 1.0 )
  {
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_andnot_ps(
            _mm_cmpleps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27)));
    gradOut->m_quad = _mm_mul_ps(v23, v28);
    gradOut[1].m_quad = _mm_mul_ps(v28, gradOut[1].m_quad);
  }
}

// File Line: 775
// RVA: 0xCA5CA0
void __fastcall takeStepAxes(hkVector4f *axesIn, hkVector4f *direction, hkSimdFloat32 *stepLength, hkVector4f *axesOut)
{
  signed __int64 v4; // rcx
  hkVector4f *v5; // rax
  signed __int64 v6; // rdx
  signed __int64 v7; // r10
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  hkVector4f v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1

  v4 = (char *)axesIn - (char *)axesOut;
  v5 = axesOut;
  v6 = (char *)direction - (char *)axesOut;
  v7 = 2i64;
  do
  {
    v8 = *(__m128 *)((char *)&v5->m_quad + v4);
    ++v5;
    v5[-1] = (hkVector4f)v8;
    v5[-1].m_quad = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)&v5[-1].m_quad + v6), stepLength->m_real), v8);
    --v7;
  }
  while ( v7 );
  v9 = _mm_mul_ps(axesOut->m_quad, axesOut->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v10, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                     _mm_mul_ps(*(__m128 *)_xmm, v11))),
                 axesOut->m_quad);
  *axesOut = (hkVector4f)v12.m_quad;
  v13 = _mm_mul_ps(v12.m_quad, axesOut[1].m_quad);
  v14 = _mm_sub_ps(
          axesOut[1].m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            v12.m_quad));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))),
          v14);
  axesOut[1] = (hkVector4f)v18;
  v19 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), axesOut->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(axesOut->m_quad, axesOut->m_quad, 201), v18));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v20, v20);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  axesOut[2].m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v22, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                            _mm_mul_ps(*(__m128 *)_xmm, v23))),
                        v20);
}

// File Line: 798
// RVA: 0xCA5E40
__m128i *__fastcall lineMinimize(hkSimdFloat32 *result, const float *vertexArray, int numVertices, int striding)
{
  __m128i *v4; // rsi
  int v5; // er14
  int v6; // er15
  const float *v7; // r12
  __m128 v8; // xmm10
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  float v11; // xmm11_4
  float v12; // xmm12_4
  __m128 i; // xmm6
  int v14; // ebx
  __m128 v15; // xmm7
  __m128 v16; // xmm11
  int v17; // ebx
  __m128 v18; // xmm11
  __int64 v19; // rbx
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm9
  __m128 v23; // xmm9
  hkSimdFloat32 v25; // [rsp+40h] [rbp-98h]
  hkSimdFloat32 resulta; // [rsp+50h] [rbp-88h]
  hkSimdFloat32 v27; // [rsp+60h] [rbp-78h]
  hkSimdFloat32 v28; // [rsp+70h] [rbp-68h]
  hkVector4f *retaddr; // [rsp+148h] [rbp+70h]
  hkSimdFloat32 *stepLength; // [rsp+150h] [rbp+78h]
  hkVector4f *v31; // [rsp+158h] [rbp+80h]
  signed int v32; // [rsp+160h] [rbp+88h]

  v4 = (__m128i *)result;
  v5 = striding;
  v6 = numVertices;
  v7 = vertexArray;
  v8 = 0i64;
  getVolumeFromAxes(&resulta, vertexArray, numVertices, striding, retaddr);
  v9.m128_i32[0] = 0;
  v10.m128_i32[0] = 0;
  takeStepAxes(retaddr, v31, stepLength, (hkVector4f *)&resulta.m_real.m128_u16[4]);
  getVolumeFromAxes(&v25, v7, v6, v5, (hkVector4f *)&resulta.m_real.m128_u16[4]);
  v11 = v25.m_real.m128_f32[0];
  v12 = resulta.m_real.m128_f32[0];
  if ( v25.m_real.m128_f32[0] >= resulta.m_real.m128_f32[0] )
  {
    v15 = stepLength->m_real;
    v17 = 0;
    v10.m128_i32[0] = v25.m_real.m128_i32[0];
    for ( i = stepLength->m_real; v17 < v32; ++v17 )
    {
      i = _mm_mul_ps(_mm_add_ps(i, (__m128)0i64), (__m128)xmmword_141A711B0);
      resulta.m_real = i;
      takeStepAxes(retaddr, v31, &resulta, (hkVector4f *)&resulta.m_real.m128_u16[4]);
      v9 = getVolumeFromAxes(&v28, v7, v6, v5, (hkVector4f *)&resulta.m_real.m128_u16[4])->m_real;
      if ( v9.m128_f32[0] < v12 && v9.m128_f32[0] < v11 )
        break;
      if ( v17 == v32 - 1 )
        goto LABEL_29;
    }
  }
  else
  {
    i = stepLength->m_real;
    v14 = 0;
    v9.m128_i32[0] = v25.m_real.m128_i32[0];
    v15 = stepLength->m_real;
    if ( v32 > 0 )
    {
      v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0);
      do
      {
        v15 = _mm_mul_ps(v15, v16);
        resulta.m_real = v15;
        takeStepAxes(retaddr, v31, &resulta, (hkVector4f *)&resulta.m_real.m128_u16[4]);
        v10 = getVolumeFromAxes(&v28, v7, v6, v5, (hkVector4f *)&resulta.m_real.m128_u16[4])->m_real;
        if ( v9.m128_f32[0] < v10.m128_f32[0] )
          break;
        i = v15;
        v9.m128_i32[0] = v10.m128_i32[0];
        if ( v14 == v32 - 1 )
        {
          _mm_store_si128(v4, (__m128i)v15);
          return v4;
        }
        ++v14;
      }
      while ( v14 < v32 );
    }
  }
  if ( v8.m128_f32[0] > i.m128_f32[0]
    || i.m128_f32[0] > v15.m128_f32[0]
    || v12 < v9.m128_f32[0]
    || v10.m128_f32[0] < v9.m128_f32[0] )
  {
LABEL_29:
    *v4 = (__m128i)g_vectorfConstants[0];
  }
  else
  {
    v18 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_38196602), (__m128)LODWORD(FLOAT_0_38196602), 0);
    if ( v32 > 0 )
    {
      v19 = (unsigned int)v32;
      do
      {
        v20 = _mm_sub_ps(i, v8);
        v21 = _mm_sub_ps(v15, i);
        if ( v20.m128_f32[0] <= v21.m128_f32[0] )
        {
          v23 = _mm_add_ps(_mm_mul_ps(v18, v21), i);
          v27.m_real = v23;
          takeStepAxes(retaddr, v31, &v27, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          getVolumeFromAxes(&v28, v7, v6, v5, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          if ( v28.m_real.m128_f32[0] >= v9.m128_f32[0] )
          {
            v15 = v23;
          }
          else
          {
            v8 = i;
            v9.m128_i32[0] = v28.m_real.m128_i32[0];
            i = v23;
          }
        }
        else
        {
          v22 = _mm_sub_ps(i, _mm_mul_ps(v18, v20));
          resulta.m_real = v22;
          takeStepAxes(retaddr, v31, &resulta, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          getVolumeFromAxes(&v25, v7, v6, v5, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          if ( v25.m_real.m128_f32[0] >= v9.m128_f32[0] )
          {
            v8 = v22;
          }
          else
          {
            v15 = i;
            v9.m128_i32[0] = v25.m_real.m128_i32[0];
            i = v22;
          }
        }
        --v19;
      }
      while ( v19 );
    }
    _mm_store_si128(v4, (__m128i)i);
  }
  return v4;
}

// File Line: 928
// RVA: 0xCA61B0
hkSimdFloat32 *__fastcall doSteepestDescent(hkSimdFloat32 *result, const float *vertexArray, int numVertices, int striding, hkVector4f *axesIn, hkVector4f *axesOut, int maxIter)
{
  int v7; // er14
  int v8; // er15
  const float *v9; // r12
  hkSimdFloat32 *v10; // rsi
  int v11; // ebx
  __m128 v12; // xmm8
  hkVector4f v13; // xmm9
  hkVector4f v14; // xmm10
  __m128i v15; // xmm6
  __m128 v16; // xmm7
  hkSimdFloat32 *v17; // rax
  __m128 v18; // xmm0
  hkSimdFloat32 stepIn; // [rsp+40h] [rbp-E8h]
  hkSimdFloat32 step; // [rsp+50h] [rbp-D8h]
  hkSimdFloat32 resulta; // [rsp+60h] [rbp-C8h]
  hkSimdFloat32 v23; // [rsp+70h] [rbp-B8h]
  hkVector4f gradOut; // [rsp+80h] [rbp-A8h]

  v7 = striding;
  v8 = numVertices;
  v9 = vertexArray;
  v10 = result;
  step.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  stepIn.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  getVolumeFromAxes(result, vertexArray, numVertices, striding, axesIn);
  *axesOut = (hkVector4f)axesIn->m_quad;
  axesOut[1] = (hkVector4f)axesIn[1].m_quad;
  v11 = 0;
  axesOut[2] = (hkVector4f)axesIn[2].m_quad;
  if ( maxIter > 0 )
  {
    while ( 1 )
    {
      v12 = axesOut->m_quad;
      v13.m_quad = (__m128)axesOut[1];
      v14.m_quad = (__m128)axesOut[2];
      getVolumeGradient(v9, v8, v7, axesOut, &step, &gradOut);
      v15 = *lineMinimize(&resulta, v9, v8, v7);
      stepIn.m_real = (__m128)v15;
      if ( *(float *)v15.m128i_i32 < 0.0 )
        break;
      takeStepAxes(axesOut, &gradOut, &stepIn, axesOut);
      v16 = v10->m_real;
      v17 = getVolumeFromAxes(&v23, v9, v8, v7, axesOut);
      v18 = v17->m_real;
      *v10 = (hkSimdFloat32)v17->m_real;
      if ( v16.m128_f32[0] < v18.m128_f32[0] )
      {
        *v10 = (hkSimdFloat32)v16;
        *axesOut = (hkVector4f)v12;
        axesOut[1] = (hkVector4f)v13.m_quad;
        axesOut[2] = (hkVector4f)v14.m_quad;
        return v10;
      }
      if ( *(float *)v15.m128i_i32 >= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x35A00000u, (__m128)0x35A00000u, 0))
        && ++v11 < maxIter )
      {
        continue;
      }
      return v10;
    }
  }
  return v10;
}

// File Line: 975
// RVA: 0xCA3970
void __fastcall hkGeometryUtility::calcObb(hkStridedVertices *stridedVertsIn, hkVector4f *halfExtents, hkTransformf *transform, hkGeomObbMode mode)
{
  hkVector4f *v4; // r14
  hkGeomObbMode v5; // er15
  hkTransformf *v6; // rdi
  int v7; // eax
  int v8; // ebx
  hkLifoAllocator *v9; // rax
  float *v10; // r9
  int v11; // edx
  char *v12; // rcx
  float *v13; // rax
  unsigned int v14; // ebx
  int v15; // esi
  int v16; // ebx
  int v17; // er9
  int v18; // er10
  __int64 v19; // rdx
  __int64 v20; // r8
  const float *v21; // rbx
  int v22; // esi
  __m128 v23; // xmm8
  __m128 v24; // xmm6
  int v25; // edx
  __m128 v26; // xmm2
  __m128 v27; // xmm7
  __m128 v28; // xmm3
  hkVector4f *v29; // rax
  hkVector4f v30; // xmm1
  hkVector4f v31; // xmm2
  int v32; // eax
  char *v33; // rdi
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // er8
  hkBool v37; // [rsp+40h] [rbp-B8h]
  float *array; // [rsp+48h] [rbp-B0h]
  int numVertices; // [rsp+50h] [rbp-A8h]
  int v40; // [rsp+54h] [rbp-A4h]
  void *p; // [rsp+58h] [rbp-A0h]
  int v42; // [rsp+60h] [rbp-98h]
  hkGeometry geometryOut; // [rsp+68h] [rbp-90h]
  hkVector4f mu; // [rsp+98h] [rbp-60h]
  hkVector4f extents; // [rsp+A8h] [rbp-50h]
  hkVector4f v46; // [rsp+B8h] [rbp-40h]
  hkResult result; // [rsp+C8h] [rbp-30h]
  hkVector4f position; // [rsp+D8h] [rbp-20h]
  hkVector4f axes; // [rsp+E8h] [rbp-10h]
  __m128 v50; // [rsp+F8h] [rbp+0h]
  __m128 v51; // [rsp+108h] [rbp+10h]
  hkVector4f axis0; // [rsp+118h] [rbp+20h]
  hkVector4f axis1; // [rsp+128h] [rbp+30h]
  hkVector4f axis2; // [rsp+138h] [rbp+40h]
  hkSimdFloat32 v55; // [rsp+148h] [rbp+50h]
  hkMatrix3f cov; // [rsp+158h] [rbp+60h]

  v4 = halfExtents;
  v5 = mode;
  v6 = transform;
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.m_vertices.m_data = (hkVector4f *)0x8000000000000000i64;
  *(_QWORD *)&geometryOut.m_vertices.m_size = 0i64;
  geometryOut.m_triangles.m_data = (hkGeometry::Triangle *)0x8000000000000000i64;
  hkGeometryUtility::createConvexGeometry(stridedVertsIn, &geometryOut);
  v7 = (int)geometryOut.m_triangles.m_data;
  array = 0i64;
  numVertices = 0;
  v8 = 3 * LODWORD(geometryOut.m_triangles.m_data);
  v40 = 2147483648;
  v42 = 3 * LODWORD(geometryOut.m_triangles.m_data);
  if ( 3 * LODWORD(geometryOut.m_triangles.m_data) )
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (float *)v9->m_cur;
    v11 = (16 * v8 + 127) & 0xFFFFFF80;
    v12 = (char *)v10 + v11;
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    {
      v13 = (float *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
      v10 = v13;
      array = v13;
      v7 = (int)geometryOut.m_triangles.m_data;
    }
    else
    {
      v9->m_cur = v12;
      v7 = (int)geometryOut.m_triangles.m_data;
      array = v10;
    }
  }
  else
  {
    v10 = 0i64;
    array = 0i64;
  }
  v14 = v8 | 0x80000000;
  v15 = 3 * v7;
  p = v10;
  v40 = v14;
  v16 = v14 & 0x3FFFFFFF;
  if ( v16 < 3 * v7 )
  {
    v17 = 3 * v7;
    if ( v15 < 2 * v16 )
      v17 = 2 * v16;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v17, 16);
    v7 = (int)geometryOut.m_triangles.m_data;
    v10 = array;
  }
  numVertices = v15;
  v18 = 0;
  if ( v7 > 0 )
  {
    v19 = 0i64;
    v20 = 0i64;
    while ( 1 )
    {
      ++v18;
      v20 += 16i64;
      v19 += 12i64;
      *(hkVector4f *)&v10[v19 - 12] = geometryOut.m_vertices.m_data[*(signed int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                                  + v20
                                                                                  - 16)];
      *(hkVector4f *)&array[v19 - 8] = geometryOut.m_vertices.m_data[*(signed int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                                   + v20
                                                                                   - 12)];
      *(hkVector4f *)&array[v19 - 4] = geometryOut.m_vertices.m_data[*(signed int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                                   + v20
                                                                                   - 8)];
      if ( v18 >= SLODWORD(geometryOut.m_triangles.m_data) )
        break;
      v10 = array;
    }
  }
  if ( !getIsBoxGeometry(&geometryOut.m_vertices, v4, v6, 0.0099999998) )
  {
    v21 = array;
    v22 = numVertices;
    axes.m_quad = ::transform.m_quad;
    v51 = stru_141A71280.m_quad;
    v50 = direction.m_quad;
    makeOBBUsingAxes(array, numVertices, 16, &extents, &axes, &position);
    v23 = extents.m_quad;
    v24.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(extents.m_quad, extents.m_quad, 85))
                            * COERCE_FLOAT(_mm_shuffle_ps(extents.m_quad, extents.m_quad, 0)))
                    * COERCE_FLOAT(_mm_shuffle_ps(extents.m_quad, extents.m_quad, 170));
    getMeanAndCovariance(v21, v25, 16, &cov, &mu, 0);
    hkGeometryUtility::getAxesFromCovariance(&v37, &cov, &axis0, &axis1, &axis2);
    makeOBBUsingAxes(v21, v22, 16, &v46, &axis0, &mu);
    v26 = v46.m_quad;
    v27.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 85))
                            * COERCE_FLOAT(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 0)))
                    * COERCE_FLOAT(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 170));
    if ( v5 == 2 )
    {
      v24 = doSteepestDescent(&v55, v21, v22, 16, &axes, &axes, 20)->m_real;
      makeOBBUsingAxes(v21, v22, 16, &extents, &axes, &position);
      v27 = doSteepestDescent(&v55, v21, v22, 16, &axis0, &axis0, 20)->m_real;
      makeOBBUsingAxes(v21, v22, 16, &v46, &axis0, &mu);
      v23 = extents.m_quad;
      v26 = v46.m_quad;
    }
    if ( v24.m128_f32[0] >= v27.m128_f32[0] )
    {
      v28 = mu.m_quad;
      v29 = &axis0;
      *v4 = (hkVector4f)v26;
    }
    else
    {
      v28 = position.m_quad;
      v29 = &axes;
      *v4 = (hkVector4f)v23;
    }
    v30.m_quad = (__m128)v29[1];
    v31.m_quad = (__m128)v29[2];
    v6->m_rotation.m_col0 = (hkVector4f)v29->m_quad;
    v6->m_rotation.m_col1 = (hkVector4f)v30.m_quad;
    v6->m_rotation.m_col2 = (hkVector4f)v31.m_quad;
    v6->m_translation.m_quad = v28;
  }
  v32 = numVertices;
  v33 = (char *)p;
  if ( p == array )
    v32 = 0;
  numVertices = v32;
  v34 = (16 * v42 + 127) & 0xFFFFFF80;
  v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (v34 + 15) & 0xFFFFFFF0;
  if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
    hkLifoAllocator::slowBlockFree(v35, v33, v36);
  else
    v35->m_cur = v33;
  numVertices = 0;
  if ( v40 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v40);
  array = 0i64;
  v40 = 2147483648;
  LODWORD(geometryOut.m_triangles.m_data) = 0;
  if ( SHIDWORD(geometryOut.m_triangles.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&geometryOut.m_vertices.m_size,
      16 * HIDWORD(geometryOut.m_triangles.m_data));
  *(_QWORD *)&geometryOut.m_vertices.m_size = 0i64;
  LODWORD(geometryOut.m_vertices.m_data) = 0;
  HIDWORD(geometryOut.m_triangles.m_data) = 2147483648;
  if ( SHIDWORD(geometryOut.m_vertices.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * HIDWORD(geometryOut.m_vertices.m_data));
}

// File Line: 1082
// RVA: 0xCA63E0
hkSphere *__fastcall makeSphere(hkSphere *result, hkVector4f *pA, hkVector4f *pB, hkSimdFloat32 *radiusEpsilon)
{
  hkSphere *v4; // rax
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v4 = result;
  v5 = _mm_mul_ps(_mm_sub_ps(pB->m_quad, pA->m_quad), (__m128)xmmword_141A711B0);
  v6 = _mm_add_ps(pA->m_quad, v5);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  result->m_pos.m_quad = _mm_shuffle_ps(
                           v6,
                           _mm_unpackhi_ps(
                             v6,
                             _mm_add_ps(
                               _mm_andnot_ps(
                                 _mm_cmpleps(v8, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v9)),
                                   v8)),
                               radiusEpsilon->m_real)),
                           196);
  return v4;
}

// File Line: 1095
// RVA: 0xCA6460
hkSphere *__fastcall makeSphere_0(hkSphere *result, hkVector4f *pA, hkVector4f *pB, hkVector4f *pC, hkSimdFloat32 *radiusEpsilon)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm9
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm8
  __m128 v14; // xmm0
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm9
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  hkSphere *v26; // rax

  v5 = _mm_sub_ps(pC->m_quad, pA->m_quad);
  v6 = _mm_shuffle_ps(v5, v5, 201);
  v7 = _mm_sub_ps(pB->m_quad, pA->m_quad);
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_sub_ps(_mm_mul_ps(v6, v7), _mm_mul_ps(v8, v5));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = v10;
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_mul_ps(v12, v7);
  v15 = _mm_sub_ps(_mm_mul_ps(v12, v5), _mm_mul_ps(v6, v10));
  v16 = _mm_sub_ps(_mm_mul_ps(v8, v10), v14);
  v17 = _mm_mul_ps(v5, v5);
  v18 = _mm_mul_ps(v7, v7);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170)),
              _mm_shuffle_ps(v16, v16, 201)),
            (__m128)0i64),
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170)),
            _mm_shuffle_ps(v15, v15, 201)));
  v20 = _mm_rcp_ps(v13);
  v21 = _mm_mul_ps(
          v19,
          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v13)), v20), (__m128)xmmword_141A711B0));
  v22 = _mm_add_ps(pA->m_quad, v21);
  v23 = _mm_mul_ps(v21, v21);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v26 = result;
  result->m_pos.m_quad = _mm_shuffle_ps(
                           v22,
                           _mm_unpackhi_ps(
                             v22,
                             _mm_add_ps(
                               _mm_andnot_ps(
                                 _mm_cmpleps(v24, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v25)),
                                   v24)),
                               radiusEpsilon->m_real)),
                           196);
  return v26;
}

// File Line: 1120
// RVA: 0xCA65F0
hkSphere *__fastcall makeSphere_1(hkSphere *result, hkVector4f *pA, hkVector4f *pB, hkVector4f *pC, hkVector4f *pD, hkSimdFloat32 *radiusEpsilon)
{
  __m128 v6; // xmm0
  hkVector4f *v7; // rbx
  hkSphere *v8; // rdi
  hkVector4f v9; // xmm7
  __m128 v10; // xmm10
  hkVector4f v11; // xmm10
  __m128 v12; // xmm6
  hkVector4f v13; // xmm6
  hkSimdFloat32 *v14; // rax
  __m128 v15; // xmm2
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm3
  __m128 v20; // xmm9
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm0
  __m128 v24; // xmm10
  __m128 v25; // xmm5
  __m128 v26; // xmm8
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  hkSphere *v32; // rax
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-98h]
  hkMatrix3f v34; // [rsp+30h] [rbp-88h]

  v6 = pA->m_quad;
  v7 = pA;
  v8 = result;
  v9.m_quad = _mm_sub_ps(pC->m_quad, pA->m_quad);
  v10 = pB->m_quad;
  v34.m_col1 = (hkVector4f)v9.m_quad;
  v11.m_quad = _mm_sub_ps(v10, v6);
  v12 = pD->m_quad;
  v34.m_col0 = (hkVector4f)v11.m_quad;
  v13.m_quad = _mm_sub_ps(v12, v6);
  v34.m_col2 = (hkVector4f)v13.m_quad;
  v14 = hkMatrix3f::getDeterminant(&v34, &resulta);
  v15 = _mm_mul_ps(v13.m_quad, v13.m_quad);
  v16 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 201);
  v17 = _mm_rcp_ps(v14->m_real);
  v18 = _mm_shuffle_ps(v11.m_quad, v11.m_quad, 201);
  v19 = _mm_mul_ps(v9.m_quad, v9.m_quad);
  v20 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14->m_real, v17)), v17);
  v21 = _mm_shuffle_ps(v9.m_quad, v9.m_quad, 201);
  v22 = _mm_sub_ps(_mm_mul_ps(v21, v11.m_quad), _mm_mul_ps(v18, v9.m_quad));
  v23 = _mm_mul_ps(v16, v11.m_quad);
  v24 = _mm_mul_ps(v11.m_quad, v11.m_quad);
  v25 = _mm_sub_ps(_mm_mul_ps(v18, v13.m_quad), v23);
  v26 = _mm_sub_ps(_mm_mul_ps(v16, v9.m_quad), _mm_mul_ps(v21, v13.m_quad));
  v27 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  _mm_shuffle_ps(v22, v22, 201)),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                  _mm_shuffle_ps(v19, v19, 170)),
                _mm_shuffle_ps(v25, v25, 201))),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              _mm_shuffle_ps(v26, v26, 201))),
          _mm_mul_ps(v20, (__m128)xmmword_141A711B0));
  v28 = _mm_add_ps(v7->m_quad, v27);
  v29 = _mm_mul_ps(v27, v27);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = v8;
  v8->m_pos.m_quad = _mm_shuffle_ps(
                       v28,
                       _mm_unpackhi_ps(
                         v28,
                         _mm_add_ps(
                           _mm_andnot_ps(
                             _mm_cmpleps(v30, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v31)),
                               v30)),
                           radiusEpsilon->m_real)),
                       196);
  return v32;
}

// File Line: 1148
// RVA: 0xCA67E0
hkSphere *__fastcall miniSphereRecurseCall(hkSphere *result, hkVector4f *verts, int numVerts, int supportSize, hkSimdFloat32 *radiusEpsilon)
{
  hkSphere *v5; // r10
  int v6; // er11
  hkVector4f *v7; // rsi
  hkVector4f *v8; // rdx
  hkVector4f *v9; // r8
  int v10; // ecx
  hkVector4f *v11; // r9
  __m128 v12; // xmm0
  hkSphere *v13; // rax
  hkSphere *v14; // rax
  hkSphere *v15; // rax
  hkSimdFloat32 *v16; // r9
  hkSimdFloat32 *v17; // r8
  int v18; // ebx
  __int64 v19; // rdi
  __m128 *v20; // rbp
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __int64 v25; // rcx
  __m128 *v26; // rax
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  hkSphere *v29; // rax
  hkSphere resulta; // [rsp+30h] [rbp-78h]
  hkSphere v31; // [rsp+40h] [rbp-68h]
  hkSphere v32; // [rsp+50h] [rbp-58h]
  hkSphere *v33; // [rsp+B0h] [rbp+8h]
  int v34; // [rsp+C0h] [rbp+18h]
  int v35; // [rsp+C8h] [rbp+20h]

  v35 = supportSize;
  v34 = numVerts;
  v33 = result;
  v5 = result;
  v6 = numVerts;
  v7 = verts;
  if ( !supportSize )
  {
    result->m_pos.m_quad = _mm_shuffle_ps((__m128)0i64, _mm_unpackhi_ps((__m128)0i64, g_vectorfConstants[0]), 196);
LABEL_10:
    v17 = radiusEpsilon;
    goto LABEL_11;
  }
  if ( supportSize == 1 )
  {
    v17 = radiusEpsilon;
    result->m_pos.m_quad = _mm_shuffle_ps(
                             verts[-1].m_quad,
                             _mm_unpackhi_ps(verts[-1].m_quad, radiusEpsilon->m_real),
                             196);
  }
  else
  {
    v8 = verts - 1;
    v9 = v7 - 2;
    v10 = supportSize - 2;
    if ( supportSize != 2 )
    {
      v11 = v7 - 3;
      if ( v10 != 1 )
      {
        v12 = makeSphere_1(&resulta, v8, v9, v11, v7 - 4, radiusEpsilon)->m_pos.m_quad;
        v13 = v33;
        *v33 = (hkSphere)v12;
        return v13;
      }
      v14 = makeSphere_0(&v31, v8, v9, v11, radiusEpsilon);
      supportSize = v35;
      *v5 = (hkSphere)v14->m_pos.m_quad;
      goto LABEL_10;
    }
    v15 = makeSphere(&v32, v8, v9, radiusEpsilon);
    v17 = v16;
    supportSize = v35;
    *v5 = (hkSphere)v15->m_pos.m_quad;
  }
LABEL_11:
  v18 = 0;
  v19 = 0i64;
  if ( v6 > 0 )
  {
    v20 = &v7->m_quad;
    do
    {
      v21 = _mm_sub_ps(*v20, v5->m_pos.m_quad);
      v22 = _mm_mul_ps(v21, v21);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_rsqrt_ps(v23);
      if ( COERCE_FLOAT(
             _mm_andnot_ps(
               _mm_cmpleps(v23, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                   _mm_mul_ps(*(__m128 *)_xmm, v24)),
                 v23))) > COERCE_FLOAT(_mm_shuffle_ps(v5->m_pos.m_quad, v5->m_pos.m_quad, 255)) )
      {
        v25 = v19;
        if ( v19 > 0 )
        {
          v26 = v20;
          do
          {
            v27 = *v26;
            v28 = v26[-1];
            --v25;
            --v26;
            v26[1] = v28;
            *v26 = v27;
          }
          while ( v25 > 0 );
        }
        v29 = miniSphereRecurseCall(&v32, v7 + 1, v18, supportSize + 1, v17);
        v5 = v33;
        v6 = v34;
        *v33 = (hkSphere)v29->m_pos.m_quad;
      }
      v17 = radiusEpsilon;
      supportSize = v35;
      ++v18;
      ++v19;
      ++v20;
    }
    while ( v18 < v6 );
  }
  return v5;
}

// File Line: 1201
// RVA: 0xCA3EC0
hkSphere *__fastcall hkGeometryUtility::createMinBoundingSphere(hkSphere *result, hkStridedVertices *stridedVertsIn, const float radiusEpsilon)
{
  int v3; // ebx
  hkSphere *v4; // rsi
  hkStridedVertices *v5; // rdi
  hkMemoryAllocator **v6; // rax
  hkVector4f *v7; // rax
  int v8; // er8
  hkVector4f *v9; // rbx
  int v10; // eax
  int v11; // er9
  hkVector4f *v12; // r10
  __int64 v13; // rdx
  int v14; // er8
  hkMemoryAllocator **v15; // rax
  hkSimdFloat32 v17; // [rsp+30h] [rbp-18h]

  v3 = stridedVertsIn->m_numVertices;
  v4 = result;
  v5 = stridedVertsIn;
  v6 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v6[11], 16 * v3, 16);
  v8 = 0;
  v9 = v7;
  v10 = v5->m_striding / 4;
  if ( v5->m_numVertices > 0 )
  {
    v11 = 0;
    v12 = v9;
    do
    {
      v13 = v11;
      ++v8;
      v11 += v10;
      ++v12;
      v12[-1].m_quad = _mm_movelh_ps(
                         (__m128)*(unsigned __int64 *)&v5->m_vertices[v13],
                         (__m128)LODWORD(v5->m_vertices[v13 + 2]));
    }
    while ( v8 < v5->m_numVertices );
  }
  v14 = v5->m_numVertices;
  v17.m_real = _mm_shuffle_ps((__m128)LODWORD(radiusEpsilon), (__m128)LODWORD(radiusEpsilon), 0);
  miniSphereRecurseCall(v4, v9, v14, 0, &v17);
  v15 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v15[11], v9);
  return v4;
}

