// File Line: 23
// RVA: 0xCA3690
void __fastcall hkGeometryUtility::createConvexGeometry(hkStridedVertices *stridedVertsIn, hkGeometry *geometryOut)
{
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-48h] BYREF
  hkgpConvexHull v5; // [rsp+40h] [rbp-38h] BYREF

  hkgpConvexHull::hkgpConvexHull(&v5);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  if ( hkgpConvexHull::build(&v5, stridedVertsIn, &config) != -1 )
    hkgpConvexHull::generateGeometry(&v5, INTERNAL_VERTICES, geometryOut, -1, 1);
  hkgpConvexHull::~hkgpConvexHull(&v5);
}

// File Line: 35
// RVA: 0xCA3710
void __fastcall hkGeometryUtility::createConvexGeometry(
        hkStridedVertices *stridedVertsIn,
        hkGeometry *geometryOut,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsOut)
{
  hkgpConvexHull::BuildConfig config; // [rsp+30h] [rbp-48h] BYREF
  hkgpConvexHull v7; // [rsp+40h] [rbp-38h] BYREF

  hkgpConvexHull::hkgpConvexHull(&v7);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  if ( hkgpConvexHull::build(&v7, stridedVertsIn, &config) != -1 )
  {
    hkgpConvexHull::generateGeometry(&v7, INTERNAL_VERTICES, geometryOut, -1, 1);
    hkgpConvexHull::buildIndices(&v7, 0.99998999, 0);
    hkgpConvexHull::fetchPlanes(&v7, planeEquationsOut);
  }
  hkgpConvexHull::~hkgpConvexHull(&v7);
}

// File Line: 51
// RVA: 0xCA37C0
void __fastcall hkGeometryUtility::createVerticesFromPlaneEquations(
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertsOut)
{
  hkResult result; // [rsp+40h] [rbp+18h] BYREF

  hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(&result, planeEquationsIn, vertsOut);
}

// File Line: 57
// RVA: 0xCA37E0
void __fastcall hkGeometryUtility::createGeometryFromPlaneEquations(
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquationsIn,
        hkGeometry *geometryOut)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> vertexCloudOut; // [rsp+20h] [rbp-28h] BYREF
  hkStridedVertices stridedVertsIn; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  vertexCloudOut.m_capacityAndFlags = 0x80000000;
  vertexCloudOut.m_data = 0i64;
  vertexCloudOut.m_size = 0;
  hkPlaneEquationUtil::getConvexVerticesFromPlaneEquations(&result, planeEquationsIn, &vertexCloudOut);
  if ( vertexCloudOut.m_size <= 0 )
  {
    geometryOut->m_triangles.m_size = 0;
    geometryOut->m_vertices.m_size = 0;
  }
  else
  {
    stridedVertsIn.m_numVertices = vertexCloudOut.m_size;
    stridedVertsIn.m_striding = 16;
    stridedVertsIn.m_vertices = vertexCloudOut.m_data->m_quad.m128_f32;
    hkGeometryUtility::createConvexGeometry(&stridedVertsIn, geometryOut);
  }
  vertexCloudOut.m_size = 0;
  if ( vertexCloudOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertexCloudOut.m_data,
      16 * vertexCloudOut.m_capacityAndFlags);
}

// File Line: 80
// RVA: 0xCA3FB0
void __fastcall hkGeometryUtility::expandPlanes(
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        float byDistance)
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
void __fastcall getMeanAndCovariance(
        const float *vertexArray,
        int numVertices,
        int striding,
        hkMatrix3f *cov,
        hkVector4f *mu,
        hkBool perturb)
{
  int v6; // r10d
  __int64 v7; // r14
  int v8; // r8d
  __m128 v10; // xmm8
  __m128 v12; // xmm15
  __m128 v13; // xmm14
  __m128 *v14; // r9
  int v15; // eax
  int v16; // esi
  int v17; // r9d
  __int64 v18; // r12
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  float v21; // xmm1_4
  const float *v22; // r8
  __int64 v23; // rcx
  float *v24; // rdx
  __m128 v25; // xmm0
  __m128 v26; // xmm11
  unsigned int *v27; // r8
  unsigned __int64 *v28; // rdi
  __m128 v29; // xmm6
  __m128 v30; // xmm11
  __m128 v31; // xmm0
  unsigned int *v32; // r8
  unsigned __int64 *v33; // rdi
  __m128 v34; // xmm12
  __m128 v35; // xmm6
  __m128 v36; // xmm0
  __m128 v37; // xmm12
  int v38; // eax
  float v39; // xmm0_4
  int v40; // eax
  float v41; // xmm0_4
  int v42; // eax
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm7
  float v52; // xmm9_4
  float v53; // xmm10_4
  __m128 v54; // xmm6
  char *v55; // rcx
  hkVector4f *p_m_col2; // rax
  __int64 v57; // r10
  float v58; // xmm11_4
  __m128 v59; // xmm6
  float v60; // xmm12_4
  __m128 v61; // xmm6
  float v62; // xmm4_4
  float v63; // xmm5_4
  float v64; // xmm6_4
  float v65; // xmm2_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm6_4
  __m128 v69; // xmm0
  float v70; // xmm10_4
  float v71; // xmm7_4
  float v72; // xmm5_4
  float v73; // xmm8_4
  float v74; // xmm2_4
  float v75; // xmm4_4
  float v76; // xmm1_4
  float v77; // xmm6_4
  float v78; // xmm1_4
  float v79; // xmm4_4
  float v80; // xmm3_4
  float v81; // xmm10_4
  __m128 v82; // xmm2
  __m128 v83; // xmm14
  float v84; // xmm5_4
  float v85; // xmm6_4
  float v86; // xmm0_4
  float v87; // xmm4_4
  float v88; // xmm3_4
  __m128 *array; // [rsp+38h] [rbp-C0h] BYREF
  int v90; // [rsp+40h] [rbp-B8h]
  int v91; // [rsp+44h] [rbp-B4h]
  __m128 v92; // [rsp+50h] [rbp-A8h]
  __m128 v93; // [rsp+60h] [rbp-98h] BYREF
  unsigned __int64 v94; // [rsp+70h] [rbp-88h] BYREF
  __m128 v95; // [rsp+78h] [rbp-80h] BYREF
  void *retaddr; // [rsp+168h] [rbp+70h] BYREF
  int v97; // [rsp+170h] [rbp+78h]
  __m128 *v98; // [rsp+188h] [rbp+90h]

  v6 = numVertices;
  v7 = striding;
  v8 = 0x80000000;
  v10 = 0i64;
  array = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v91 = 0x80000000;
  v15 = 0;
  v90 = 0;
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
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v17, 16);
    v8 = v91;
    v15 = v90;
    v14 = array;
    v6 = v97;
  }
  cov->m_col0 = 0i64;
  v18 = v16;
  v90 = v16 + v15;
  cov->m_col1 = 0i64;
  cov->m_col2 = 0i64;
  if ( v16 > 0 )
  {
    v19 = (__m128)_xmm;
    v20 = *(__m128 *)_xmm;
    v21 = FLOAT_2_3283064eN10;
    v22 = vertexArray + 2;
    v23 = -32i64 - (_QWORD)cov;
    v24 = &v14->m128_f32[2];
    do
    {
      v25 = (__m128)*(unsigned int *)v22;
      v26 = (__m128)*(unsigned __int64 *)vertexArray;
      v27 = (unsigned int *)((char *)v22 + v7);
      v28 = (unsigned __int64 *)((char *)vertexArray + v7);
      v29 = (__m128)*v28;
      v30 = _mm_movelh_ps(v26, v25);
      v31 = (__m128)*v27;
      v93 = v30;
      v32 = (unsigned int *)((char *)v27 + v7);
      v33 = (unsigned __int64 *)((char *)v28 + v7);
      v34 = (__m128)*v33;
      v35 = _mm_movelh_ps(v29, v31);
      v36 = (__m128)*v32;
      v94 = v35.m128_u64[0];
      vertexArray = (const float *)((char *)v33 + v7);
      v22 = (const float *)((char *)v32 + v7);
      v37 = _mm_movelh_ps(v34, v36);
      v95 = v37;
      if ( (_BYTE)mu )
      {
        v38 = 1664525 * v6 + 1013904223;
        v39 = (float)v38;
        v40 = 1664525 * v38 + 1013904223;
        v92.m128_f32[0] = v39 * v21;
        v41 = (float)v40;
        v42 = 1664525 * v40 + 1013904223;
        v92.m128_f32[1] = v41 * v21;
        v23 = -32i64 - (_QWORD)cov;
        v92.m128_f32[2] = (float)v42 * v21;
        v92.m128_f32[3] = (float)(1664525 * v42 + 1013904223) * v21;
        v43 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0), v92), v30);
      }
      else
      {
        v43 = v30;
      }
      v44 = _mm_sub_ps(v43, v35);
      v45 = _mm_sub_ps(v30, v37);
      v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v45));
      v47 = _mm_shuffle_ps(v46, v46, 201);
      v48 = _mm_mul_ps(v47, v47);
      v49 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
              _mm_shuffle_ps(v48, v48, 170));
      v50 = _mm_rsqrt_ps(v49);
      v51 = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v49, v10),
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps(v19, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)), _mm_mul_ps(v50, v20)),
                  v49)),
              (__m128)xmmword_141A711B0);
      if ( v51.m128_f32[0] <= v10.m128_f32[0] )
      {
        v69 = _mm_add_ps(_mm_add_ps(v35, v30), v37);
        v70 = _mm_shuffle_ps(v35, v35, 170).m128_f32[0];
        v71 = _mm_shuffle_ps(v30, v30, 85).m128_f32[0];
        *v14 = v69;
        v72 = _mm_shuffle_ps(v37, v37, 85).m128_f32[0];
        v73 = _mm_shuffle_ps(v30, v30, 170).m128_f32[0];
        v74 = _mm_shuffle_ps(v35, v35, 85).m128_f32[0];
        *v14 = _mm_mul_ps(v69, (__m128)xmmword_141A711C0);
        v75 = v70 * v35.m128_f32[0];
        cov->m_col0.m_quad.m128_f32[0] = (float)((float)((float)(v35.m128_f32[0] * v35.m128_f32[0])
                                                       + (float)(v30.m128_f32[0] * v30.m128_f32[0]))
                                               + (float)(v37.m128_f32[0] * v37.m128_f32[0]))
                                       + cov->m_col0.m_quad.m128_f32[0];
        v76 = v74 * v35.m128_f32[0];
        v77 = _mm_shuffle_ps(v37, v37, 170).m128_f32[0];
        v78 = (float)(v76 + (float)(v71 * v30.m128_f32[0])) + (float)(v72 * v37.m128_f32[0]);
        cov->m_col1.m_quad.m128_f32[0] = v78 + cov->m_col1.m_quad.m128_f32[0];
        v79 = (float)(v75 + (float)(v73 * v30.m128_f32[0])) + (float)(v77 * v37.m128_f32[0]);
        cov->m_col2.m_quad.m128_f32[0] = v79 + cov->m_col2.m_quad.m128_f32[0];
        cov->m_col0.m_quad.m128_f32[1] = v78 + cov->m_col0.m_quad.m128_f32[1];
        cov->m_col1.m_quad.m128_f32[1] = (float)((float)((float)(v74 * v74) + (float)(v71 * v71)) + (float)(v72 * v72))
                                       + cov->m_col1.m_quad.m128_f32[1];
        v80 = (float)((float)(v70 * v74) + (float)(v73 * v71)) + (float)(v77 * v72);
        cov->m_col2.m_quad.m128_f32[1] = v80 + cov->m_col2.m_quad.m128_f32[1];
        cov->m_col0.m_quad.m128_f32[2] = v79 + cov->m_col0.m_quad.m128_f32[2];
        cov->m_col1.m_quad.m128_f32[2] = v80 + cov->m_col1.m_quad.m128_f32[2];
        v81 = (float)((float)(v70 * v70) + (float)(v73 * v73)) + (float)(v77 * v77);
        v10 = 0i64;
        cov->m_col2.m_quad.m128_f32[2] = v81 + cov->m_col2.m_quad.m128_f32[2];
      }
      else
      {
        v52 = v93.m128_f32[2];
        v53 = v93.m128_f32[1];
        v54 = _mm_add_ps(v35, v30);
        v55 = (char *)v14 + v23;
        p_m_col2 = &cov->m_col2;
        v57 = 3i64;
        v58 = v93.m128_f32[0];
        v59 = _mm_add_ps(v54, v37);
        v60 = v95.m128_f32[0];
        v61 = _mm_mul_ps(v59, (__m128)xmmword_141A711C0);
        v12 = _mm_add_ps(v12, v51);
        *v14 = v61;
        v13 = _mm_add_ps(v13, _mm_mul_ps(v51, v61));
        do
        {
          v62 = *(float *)((char *)p_m_col2[-2].m_quad.m128_f32 + (char *)&v93 - (char *)cov);
          v63 = *(float *)((char *)p_m_col2[-2].m_quad.m128_f32 + (char *)&v94 - (char *)cov);
          v64 = *(float *)((char *)p_m_col2[-2].m_quad.m128_f32 + (char *)&v95 - (char *)cov);
          v65 = (float)((float)(*(float *)((char *)p_m_col2->m_quad.m128_f32 + (_QWORD)v55) * 9.0) * *(v24 - 2))
              + (float)(v62 * v58);
          p_m_col2 = (hkVector4f *)((char *)p_m_col2 + 4);
          v66 = v63 * *((float *)&v94 + 1);
          p_m_col2[-3].m_quad.m128_f32[3] = (float)((float)((float)(v65 + (float)(v63 * *(float *)&v94))
                                                          + (float)(v64 * v95.m128_f32[0]))
                                                  * v51.m128_f32[0])
                                          + p_m_col2[-3].m_quad.m128_f32[3];
          v67 = v64;
          v68 = v64 * v95.m128_f32[2];
          p_m_col2[-2].m_quad.m128_f32[3] = (float)((float)((float)((float)((float)((float)(*(float *)((char *)&p_m_col2->m_quad.m128_f32[-1] + (_QWORD)v55)
                                                                                          * 9.0)
                                                                                  * *(v24 - 1))
                                                                          + (float)(v62 * v53))
                                                                  + v66)
                                                          + (float)(v67 * v95.m128_f32[1]))
                                                  * v51.m128_f32[0])
                                          + p_m_col2[-2].m_quad.m128_f32[3];
          p_m_col2[-1].m_quad.m128_f32[3] = (float)((float)((float)((float)((float)((float)(*(float *)((char *)&p_m_col2->m_quad.m128_f32[-1] + (_QWORD)v55)
                                                                                          * 9.0)
                                                                                  * *v24)
                                                                          + (float)(v62 * v52))
                                                                  + (float)(v63 * v60))
                                                          + v68)
                                                  * v51.m128_f32[0])
                                          + p_m_col2[-1].m_quad.m128_f32[3];
          --v57;
        }
        while ( v57 );
      }
      v19 = (__m128)_xmm;
      v20 = *(__m128 *)_xmm;
      v21 = FLOAT_2_3283064eN10;
      v23 = -32i64 - (_QWORD)cov;
      v6 = v97;
      v24 += 4;
      ++v14;
      --v18;
    }
    while ( v18 );
    v8 = v91;
    v14 = array;
  }
  if ( v12.m128_f32[0] > v10.m128_f32[0] )
  {
    v82 = _mm_rcp_ps(v12);
    v83 = _mm_mul_ps(v13, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v82, v12)), v82));
    v84 = _mm_shuffle_ps(v83, v83, 85).m128_f32[0];
    v85 = _mm_shuffle_ps(v83, v83, 170).m128_f32[0];
    v86 = cov->m_col1.m_quad.m128_f32[0];
    cov->m_col0.m_quad.m128_f32[0] = (float)(cov->m_col0.m_quad.m128_f32[0] * 0.083333336)
                                   - (float)((float)(v83.m128_f32[0] * v83.m128_f32[0]) * v12.m128_f32[0]);
    v82.m128_f32[0] = (float)(v84 * v83.m128_f32[0]) * v12.m128_f32[0];
    v87 = (float)(v85 * v83.m128_f32[0]) * v12.m128_f32[0];
    cov->m_col1.m_quad.m128_f32[0] = (float)(v86 * 0.083333336) - v82.m128_f32[0];
    cov->m_col2.m_quad.m128_f32[0] = (float)(cov->m_col2.m_quad.m128_f32[0] * 0.083333336) - v87;
    v88 = (float)(v85 * v84) * v12.m128_f32[0];
    cov->m_col0.m_quad.m128_f32[1] = (float)(cov->m_col0.m_quad.m128_f32[1] * 0.083333336) - v82.m128_f32[0];
    cov->m_col1.m_quad.m128_f32[1] = (float)(cov->m_col1.m_quad.m128_f32[1] * 0.083333336)
                                   - (float)((float)(v84 * v84) * v12.m128_f32[0]);
    cov->m_col2.m_quad.m128_f32[1] = (float)(cov->m_col2.m_quad.m128_f32[1] * 0.083333336) - v88;
    cov->m_col0.m_quad.m128_f32[2] = (float)(cov->m_col0.m_quad.m128_f32[2] * 0.083333336) - v87;
    cov->m_col1.m_quad.m128_f32[2] = (float)(cov->m_col1.m_quad.m128_f32[2] * 0.083333336) - v88;
    cov->m_col2.m_quad.m128_f32[2] = (float)(cov->m_col2.m_quad.m128_f32[2] * 0.083333336)
                                   - (float)((float)(v85 * v85) * v12.m128_f32[0]);
    *v98 = v83;
  }
  else
  {
    *v98 = v10;
    cov->m_col0 = (hkVector4f)transform.m_quad;
    cov->m_col1 = (hkVector4f)direction.m_quad;
    cov->m_col2 = (hkVector4f)stru_141A71280.m_quad;
  }
  v90 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v14, 16 * v8);
}

// File Line: 277
// RVA: 0xCA4810
hkBool *__fastcall makeEigenvectors(hkBool *result, hkMatrix3f *mat, int max_iters)
{
  __int64 v6; // r9
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
  int v25; // xmm1_4
  int v26; // xmm0_4
  int v27; // edi
  __int64 i; // r8
  int j; // r10d
  __int64 v30; // rcx
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  __int64 v36; // rdx
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
  int v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm0_4
  int v65; // [rsp+0h] [rbp-59h]
  int v66; // [rsp+4h] [rbp-55h]
  int v67[2]; // [rsp+8h] [rbp-51h]
  float v68; // [rsp+10h] [rbp-49h]
  int v69[9]; // [rsp+14h] [rbp-45h]
  float vars0; // [rsp+C8h] [rbp+6Fh]

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
    v11 = _mm_rsqrt_ps(v8).m128_f32[0];
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
  v69[1] = 0;
  v65 = v15;
  if ( v14 == 0.0 )
  {
    v24 = mat->m_col2.m_quad.m128_i32[2];
    v66 = mat->m_col1.m_quad.m128_i32[1];
    v25 = mat->m_col1.m_quad.m128_i32[0];
    v67[0] = v24;
    v26 = mat->m_col2.m_quad.m128_i32[1];
    v68 = *(float *)&v25;
    mat->m_col0 = (hkVector4f)transform.m_quad;
    v69[0] = v26;
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
    v68 = fsqrt(vars0);
    v19 = (float)(1.0 / v68) * v14;
    v20 = (float)(1.0 / v68) * v16;
    v21 = (float)(v17 - mat->m_col1.m_quad.m128_f32[1]) * v19;
    mat->m_col2.m_quad.m128_f32[1] = v19;
    mat->m_col1.m_quad.m128_f32[2] = v19;
    v22 = v21 + (float)((float)(v20 * 2.0) * v18);
    *(float *)v69 = v18 - (float)(v22 * v20);
    *(float *)&v23 = (float)(v22 * v19) + mat->m_col1.m_quad.m128_f32[1];
    mat->m_col1.m_quad.m128_f32[1] = v20;
    *(float *)v67 = v17 - (float)(v22 * v19);
    v66 = v23;
    mat->m_col2.m_quad.m128_i32[2] = LODWORD(v20) ^ _xmm[0];
  }
  v27 = 0;
  for ( i = 0i64; ; ++i )
  {
    for ( j = 0; j < max_iters; *((float *)&v65 + i) = v63 - v39 )
    {
      v30 = i;
      if ( i > 1 )
        break;
      do
      {
        vars0 = *(float *)&v69[v30 - 1];
        if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(vars0)) >> 1) < 0.000001 )
          break;
        ++v30;
      }
      while ( v30 <= 1 );
      if ( v30 == i )
        break;
      v31 = *(float *)&v69[i - 1];
      v32 = *((float *)&v65 + i);
      v33 = (float)(*(float *)&v67[i - 1] - v32) / (float)(v31 * 2.0);
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
      v40 = v35 + (float)(*((float *)&v65 + v30) - v32);
      if ( v30 - 1 >= i )
      {
        v41 = &mat->m_col1.m_quad.m128_f32[4 * v36 + 1];
        do
        {
          v42 = *(float *)&v69[v36 - 1];
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
            *(float *)&v69[v36] = v40 / *(float *)&v38;
          }
          else
          {
            v45 = (float)(-1.0 / v44) * v40;
            vars0 = (float)(v45 * v45) + 1.0;
            v46 = -1.0 / fsqrt(vars0);
            *(float *)&v38 = v45 * v46;
            v37 = LODWORD(v46) ^ _xmm[0];
            *(float *)&v69[v36] = v44 / *(float *)&v37;
          }
          v49 = *(float *)&v67[v36 - 1];
          v50 = *((float *)&v65 + v36--);
          v41 -= 4;
          v51 = v49 - v39;
          v52 = (float)((float)(v50 - v51) * *(float *)&v37) + (float)((float)(v43 * 2.0) * *(float *)&v38);
          v39 = *(float *)&v37 * v52;
          v53 = *(float *)&v38 * v52;
          v54 = v41[3];
          v40 = v53 - v43;
          *(float *)&v55 = v39 + v51;
          v56 = *(v41 - 1);
          v67[v36] = v55;
          v41[3] = (float)(v56 * *(float *)&v37) + (float)(*(float *)&v38 * v54);
          v57 = *(float *)&v37 * v54;
          v58 = v41[4];
          *(v41 - 1) = (float)(v56 * *(float *)&v38) - v57;
          v59 = *v41 * *(float *)&v38;
          v41[4] = (float)(*v41 * *(float *)&v37) + (float)(*(float *)&v38 * v58);
          v60 = *(float *)&v37 * v58;
          v61 = v41[5];
          *v41 = v59 - v60;
          v62 = v41[1];
          v41[5] = (float)(v62 * *(float *)&v37) + (float)(*(float *)&v38 * v61);
          v41[1] = (float)(v62 * *(float *)&v38) - (float)(*(float *)&v37 * v61);
        }
        while ( v36 >= i );
      }
      v63 = *((float *)&v65 + i);
      ++j;
      *(float *)&v69[i - 1] = v40;
      *(float *)&v69[v30 - 1] = 0.0;
    }
    if ( j == max_iters )
      break;
    if ( ++v27 >= 3 )
    {
      result->m_bool = 1;
      return result;
    }
  }
  result->m_bool = 0;
  return result;
}

// File Line: 449
// RVA: 0xCA3890
hkBool *__fastcall hkGeometryUtility::getAxesFromCovariance(
        hkBool *result,
        hkMatrix3f *covArray,
        hkVector4f *axis0,
        hkVector4f *axis1,
        hkVector4f *axis2)
{
  hkVector4f v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm2

  makeEigenvectors(result, covArray, 30);
  if ( result->m_bool )
  {
    *axis0 = covArray->m_col0;
    *axis1 = covArray->m_col1;
    v9.m_quad = (__m128)covArray->m_col2;
    *axis2 = (hkVector4f)v9.m_quad;
    v10 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(axis1->m_quad, axis1->m_quad, 201), axis0->m_quad),
            _mm_mul_ps(_mm_shuffle_ps(axis0->m_quad, axis0->m_quad, 201), axis1->m_quad));
    v11 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9.m_quad);
    axis2->m_quad = _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmplt_ps(
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
    *axis0 = (hkVector4f)transform.m_quad;
    *axis1 = (hkVector4f)direction.m_quad;
    *axis2 = (hkVector4f)stru_141A71280.m_quad;
  }
  return result;
}

// File Line: 483
// RVA: 0xCA4DC0
__int64 __fastcall isMultOfXYorZ(const __m128i *v, hkSimdFloat32 *epsilon)
{
  __int64 result; // rax
  __m128 v3; // xmm2

  result = 0i64;
  v3 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v), 1u), 1u);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     fmax(
                                       _mm_shuffle_ps(v3, v3, 170).m128_f32[0],
                                       fmax(
                                         _mm_shuffle_ps(v3, v3, 85).m128_f32[0],
                                         _mm_shuffle_ps(v3, v3, 0).m128_f32[0]))
                                   - 1.0)) >> 1) < epsilon->m_real.m128_f32[0] )
    return 1i64;
  return result;
}

// File Line: 492
// RVA: 0xCA4E10
__int64 __fastcall getIsBoxGeometry(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        __m128i *halfExtents,
        hkTransformf *boxToGeom,
        const float epsilonR)
{
  float v6; // xmm12_4
  hkSphere *v7; // rax
  __m128 m_quad; // xmm6
  float v9; // xmm7_4
  __m128 *v10; // rax
  __int64 m_size; // rsi
  int v12; // r15d
  __m128 *v13; // rdi
  int v14; // r8d
  int v15; // eax
  __int64 v16; // rbx
  hkVector4f *m_data; // r14
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
  __int64 v28; // rax
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
  __int64 v47; // rcx
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __int64 v50; // rax
  __m128 v51; // xmm2
  int v52; // r8d
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
  hkVector4f *v66; // rdx
  unsigned __int8 v67; // bl
  __m128 *array; // [rsp+20h] [rbp-C0h] BYREF
  int v70; // [rsp+28h] [rbp-B8h]
  int v71; // [rsp+2Ch] [rbp-B4h]
  hkResult v72; // [rsp+30h] [rbp-B0h] BYREF
  hkMatrix3f v73; // [rsp+40h] [rbp-A0h] BYREF
  hkStridedVertices stridedVertsIn; // [rsp+70h] [rbp-70h] BYREF
  __m128 v75; // [rsp+80h] [rbp-60h]
  __m128 v76; // [rsp+90h] [rbp-50h]
  hkSphere result; // [rsp+A0h] [rbp-40h] BYREF
  int v78[4]; // [rsp+190h] [rbp+B0h] BYREF
  hkTransformf *t; // [rsp+1A0h] [rbp+C0h]
  void *retaddr; // [rsp+1A8h] [rbp+C8h]

  stridedVertsIn.m_striding = 16;
  LODWORD(v6) = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0).m128_u32[0];
  stridedVertsIn.m_numVertices = vertices->m_size;
  stridedVertsIn.m_vertices = vertices->m_data->m_quad.m128_f32;
  v7 = hkGeometryUtility::createMinBoundingSphere(&result, &stridedVertsIn, 0.0000099999997);
  v78[0] = 128;
  m_quad = v7->m_pos.m_quad;
  LODWORD(v9) = _mm_shuffle_ps(m_quad, m_quad, 255).m128_u32[0];
  v10 = (__m128 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, v78);
  m_size = vertices->m_size;
  v12 = 0x80000000;
  v13 = v10;
  v14 = 0x80000000;
  array = 0i64;
  v71 = 0x80000000;
  if ( v78[0] / 16 )
    v12 = v78[0] / 16;
  v15 = 0;
  v70 = 0;
  if ( m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      m_data = vertices->m_data;
      v18 = _mm_sub_ps(vertices->m_data[v16].m_quad, m_quad);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      if ( COERCE_FLOAT((unsigned int)(2
                                     * COERCE_INT(
                                         _mm_andnot_ps(
                                           _mm_cmple_ps(v20, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v21)),
                                             v20)).m128_f32[0]
                                       - v9)) >> 1) < v6 )
      {
        if ( v15 == (v14 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
          v15 = v70;
        }
        array[v15] = m_data[v16].m_quad;
        v14 = v71;
        v15 = ++v70;
      }
      ++v16;
      --m_size;
    }
    while ( m_size );
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
        LODWORD(v33) = _mm_shuffle_ps(v32, v32, 85).m128_u32[0];
        if ( (float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                   + _mm_shuffle_ps(v31, v31, 170).m128_f32[0]) >= (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0]
                                                                                 + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
                                                                         + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) )
        {
          if ( (float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                     + _mm_shuffle_ps(v31, v31, 170).m128_f32[0]) < (float)((float)(v33
                                                                                  + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
                                                                          + _mm_shuffle_ps(v32, v32, 170).m128_f32[0]) )
            v27 = v29;
        }
        else
        {
          if ( (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
                     + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) < (float)((float)(v33
                                                                                  + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
                                                                          + _mm_shuffle_ps(v32, v32, 170).m128_f32[0]) )
            v27 = v26;
          v26 = v29;
        }
        ++v23;
        --v28;
      }
      while ( v28 );
      v72.m_enum = 925353388;
      v34 = _mm_mul_ps(v27, v26);
      if ( (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                 + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]) <= _mm_shuffle_ps(
                                                                   (__m128)0x3727C5ACu,
                                                                   (__m128)0x3727C5ACu,
                                                                   0).m128_f32[0] )
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
                                _mm_cmple_ps(v38, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v38), v40)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v40))),
                              v26);
        v73.m_col1.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v41, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v41), v43)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v43))),
                              v27);
        v73.m_col2.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v44, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v45))),
                              v37);
        hkMatrix3f::invert(&v73, &v72, 0.0099999998);
        v46 = v13;
        v47 = 8i64;
        do
        {
          v48 = *v46++;
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
          v51 = _mm_max_ps(v51, *v22++);
          --v50;
        }
        while ( v50 );
        v52 = 0;
        v53 = v13;
        v72.m_enum = LODWORD(FLOAT_0_001);
        v54 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
        while ( ((_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(
                                                         _mm_slli_epi32((__m128i)_mm_sub_ps(*v53, v49), 1u),
                                                         1u), v54)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                     _mm_cmplt_ps(
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
            *halfExtents = (__m128i)v57;
            *(__m128 *)halfExtents = _mm_mul_ps(v57, (__m128)xmmword_141A711B0);
            v73.m_col2 = v73.m_col0;
            v76 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0), _mm_add_ps(v51, v49));
            v75 = v73.m_col0.m_quad;
            hkTransformf::setInverse(v56, (hkTransformf *)&v73.m_col2);
            v58 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73), 1u), 1u);
            if ( COERCE_FLOAT((unsigned int)(2
                                           * COERCE_INT(
                                               fmax(
                                                 _mm_shuffle_ps(v58, v58, 170).m128_f32[0],
                                                 fmax(
                                                   _mm_shuffle_ps(v58, v58, 85).m128_f32[0],
                                                   _mm_shuffle_ps(v58, v58, 0).m128_f32[0]))
                                             - 1.0)) >> 1) < v6 )
            {
              v59 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73.m_col1), 1u), 1u);
              if ( COERCE_FLOAT((unsigned int)(2
                                             * COERCE_INT(
                                                 fmax(
                                                   _mm_shuffle_ps(v59, v59, 170).m128_f32[0],
                                                   fmax(
                                                     _mm_shuffle_ps(v59, v59, 85).m128_f32[0],
                                                     _mm_shuffle_ps(v59, v59, 0).m128_f32[0]))
                                               - 1.0)) >> 1) < v6 )
              {
                v60 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v73.m_col2), 1u), 1u);
                if ( COERCE_FLOAT((unsigned int)(2
                                               * COERCE_INT(
                                                   fmax(
                                                     _mm_shuffle_ps(v60, v60, 170).m128_f32[0],
                                                     fmax(
                                                       _mm_shuffle_ps(v60, v60, 85).m128_f32[0],
                                                       _mm_shuffle_ps(v60, v60, 0).m128_f32[0]))
                                                 - 1.0)) >> 1) < v6 )
                {
                  v61 = (__m128i)_mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(*(__m128 *)halfExtents, *(__m128 *)halfExtents, 0),
                                       v55->m_rotation.m_col0.m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(*(__m128 *)halfExtents, *(__m128 *)halfExtents, 85),
                                       v55->m_rotation.m_col1.m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(*(__m128 *)halfExtents, *(__m128 *)halfExtents, 170),
                                     v55->m_rotation.m_col2.m_quad));
                  *halfExtents = v61;
                  v62 = _mm_srli_si128(_mm_slli_si128(v61, 4), 4);
                  *halfExtents = v62;
                  *halfExtents = _mm_srli_epi32(_mm_slli_epi32(v62, 1u), 1u);
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
            v63 = vertices->m_size;
            v64 = 0i64;
            v65 = _mm_mul_ps((__m128)_xmm, *(__m128 *)halfExtents);
            if ( v63 <= 0 )
            {
LABEL_35:
              v14 = v71;
              v67 = 1;
              goto LABEL_38;
            }
            v66 = vertices->m_data;
            while ( (_mm_movemask_ps(
                       _mm_cmplt_ps(
                         v65,
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v66->m_quad, v66->m_quad, 85), (__m128)stridedVertsIn),
                               _mm_mul_ps(_mm_shuffle_ps(v66->m_quad, v66->m_quad, 0), v73.m_col2.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v66->m_quad, v66->m_quad, 170), v75)),
                           v76))) & 7) == 0 )
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v14);
  array = 0i64;
  v71 = 0x80000000;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v13, 16 * v12);
  return v67;
}

// File Line: 668
// RVA: 0xCA56F0
void __fastcall makeOBBUsingAxes(
        const float *vertexArray,
        unsigned int numVertices,
        int striding,
        hkVector4f *extents,
        hkVector4f *axes,
        hkVector4f *position)
{
  __m128 v7; // xmm6
  __m128 v9; // xmm5
  __int64 v10; // r9
  __int64 v11; // r8
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1

  v7 = (__m128)_xmm;
  v9 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)_xmm);
  if ( (int)numVertices > 0 )
  {
    v10 = striding;
    v11 = numVertices;
    do
    {
      v12 = (__m128)*(unsigned __int64 *)vertexArray;
      v13 = (__m128)*((unsigned int *)vertexArray + 2);
      vertexArray = (const float *)((char *)vertexArray + v10);
      v14 = _mm_movelh_ps(v12, v13);
      v15 = _mm_mul_ps(axes[1].m_quad, v14);
      v16 = _mm_mul_ps(axes[2].m_quad, v14);
      v17 = _mm_mul_ps(axes->m_quad, v14);
      v18 = _mm_unpackhi_ps(v17, v15);
      v19 = _mm_unpacklo_ps(v17, v15);
      v20 = _mm_movelh_ps(v19, v16);
      v21 = _mm_add_ps(
              _mm_shuffle_ps(v18, v16, 228),
              _mm_add_ps(v20, _mm_shuffle_ps(_mm_movehl_ps(v20, v19), v16, 212)));
      v7 = _mm_min_ps(v7, v21);
      v9 = _mm_max_ps(v9, v21);
      --v11;
    }
    while ( v11 );
  }
  v22 = v9;
  v23 = _mm_sub_ps(v9, v7);
  v24 = _mm_mul_ps(_mm_add_ps(v22, v7), (__m128)xmmword_141A711B0);
  *extents = (hkVector4f)v23;
  extents->m_quad = _mm_mul_ps(v23, (__m128)xmmword_141A711B0);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), axes->m_quad);
  *position = (hkVector4f)v25;
  v26 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), axes[1].m_quad), v25);
  *position = (hkVector4f)v26;
  position->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), axes[2].m_quad), v26);
}

// File Line: 708
// RVA: 0xCA5820
hkSimdFloat32 *__fastcall getVolumeFromAxes(
        hkSimdFloat32 *result,
        const float *vertexArray,
        unsigned int numVertices,
        int striding,
        hkVector4f *axes)
{
  __m128 m_quad; // xmm6
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
  hkVector4f extents; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f position; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f v24; // [rsp+50h] [rbp-88h] BYREF
  __m128 v25; // [rsp+60h] [rbp-78h]
  __m128 v26; // [rsp+70h] [rbp-68h]

  m_quad = axes->m_quad;
  v7 = axes[1].m_quad;
  v8 = _mm_mul_ps(m_quad, m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(v7, axes->m_quad);
  v24.m_quad = _mm_mul_ps(
                 axes->m_quad,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v9, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                     _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v12 = _mm_sub_ps(
          v7,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            m_quad));
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v25 = _mm_mul_ps(
          v12,
          _mm_andnot_ps(
            _mm_cmple_ps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15))));
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), m_quad), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v7));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v26 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmple_ps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20))));
  makeOBBUsingAxes(vertexArray, numVertices, striding, &extents, &v24, &position);
  v21 = result;
  result->m_real = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(extents.m_quad, extents.m_quad, 85),
                       _mm_shuffle_ps(extents.m_quad, extents.m_quad, 0)),
                     _mm_shuffle_ps(extents.m_quad, extents.m_quad, 170));
  return v21;
}

// File Line: 738
// RVA: 0xCA5A20
void __fastcall getVolumeGradient(
        const float *vertexArray,
        unsigned int numVertices,
        int striding,
        hkVector4f *axes,
        hkSimdFloat32 *step,
        hkVector4f *gradOut)
{
  hkVector4f v6; // xmm1
  hkVector4f *v9; // rbx
  __m128 m_real; // xmm7
  __m128 v11; // xmm1
  signed __int64 v12; // r14
  signed __int64 v13; // r15
  __m128 v14; // xmm6
  __m128 *v15; // rsi
  __int64 i; // rdi
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
  hkSimdFloat32 result; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f v30; // [rsp+50h] [rbp-88h] BYREF
  __m128 m_quad; // [rsp+60h] [rbp-78h]
  __int64 v34; // [rsp+F8h] [rbp+20h]

  v6.m_quad = (__m128)axes[1];
  v30.m_quad = axes->m_quad;
  m_quad = v6.m_quad;
  getVolumeFromAxes(&result, vertexArray, numVertices, striding, axes);
  v9 = gradOut;
  m_real = result.m_real;
  v11 = _mm_rcp_ps(step->m_real);
  v34 = 2i64;
  v12 = (char *)axes - (char *)&v30;
  v13 = (char *)&v30 - (char *)gradOut;
  v14 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(step->m_real, v11)), v11);
  do
  {
    v15 = (__m128 *)((char *)&v9->m_quad + v13);
    for ( i = 0i64;
          i < 3;
          *v15 = _mm_or_ps(
                   _mm_and_ps(
                     _mm_or_ps(_mm_shuffle_ps(v21, v21, 177), v21),
                     *(__m128 *)((char *)&off_141687EF0 + i * 16)),
                   _mm_andnot_ps(*(__m128 *)((char *)&off_141687EF0 + i * 16), *v15)) )
    {
      v17 = _mm_and_ps(*v15, (__m128)`hkVector4f::getComponent::`2::indexToMask[i]);
      v18 = _mm_or_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      *v15 = _mm_or_ps(
               _mm_and_ps(
                 _mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v18, v18, 177), v18), step->m_real),
                 (__m128)`hkVector4f::getComponent::`2::indexToMask[i]),
               _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[i], *v15));
      getVolumeFromAxes(&result, vertexArray, numVertices, striding, &v30);
      ++i;
      v19 = _mm_or_ps(
              _mm_and_ps(
                _mm_mul_ps(_mm_sub_ps(result.m_real, m_real), v14),
                *(__m128 *)((char *)&off_141687EF0 + i * 16)),
              _mm_andnot_ps(*(__m128 *)((char *)&off_141687EF0 + i * 16), v9->m_quad));
      *v9 = (hkVector4f)v19;
      v20 = _mm_and_ps(*(__m128 *)((char *)v15 + v12), *(__m128 *)((char *)&off_141687EF0 + i * 16));
      v21 = _mm_or_ps(_mm_shuffle_ps(v20, v20, 78), v20);
    }
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
            _mm_cmple_ps(v26, (__m128)0i64),
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
  __int64 v7; // r10
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm4
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
  v12 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))),
          axesOut->m_quad);
  *axesOut = (hkVector4f)v12;
  v13 = _mm_mul_ps(v12, axesOut[1].m_quad);
  v14 = _mm_sub_ps(
          axesOut[1].m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            v12));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v16, (__m128)0i64),
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
                          _mm_cmple_ps(v22, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                            _mm_mul_ps(*(__m128 *)_xmm, v23))),
                        v20);
}

// File Line: 798
// RVA: 0xCA5E40
hkSimdFloat32 *__fastcall lineMinimize(
        hkSimdFloat32 *result,
        const float *vertexArray,
        unsigned int numVertices,
        int striding)
{
  __m128 v8; // xmm10
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  float v11; // xmm11_4
  float v12; // xmm12_4
  __m128 i; // xmm6
  int v14; // ebx
  __m128 m_real; // xmm7
  __m128 v16; // xmm11
  int v17; // ebx
  __m128 v18; // xmm11
  __int64 v19; // rbx
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm9
  __m128 v23; // xmm9
  hkSimdFloat32 v25; // [rsp+40h] [rbp-98h] BYREF
  hkSimdFloat32 resulta; // [rsp+50h] [rbp-88h] BYREF
  hkSimdFloat32 v27; // [rsp+60h] [rbp-78h] BYREF
  hkSimdFloat32 v28; // [rsp+70h] [rbp-68h] BYREF
  hkVector4f *retaddr; // [rsp+148h] [rbp+70h]
  hkSimdFloat32 *stepLength; // [rsp+150h] [rbp+78h]
  hkVector4f *v31; // [rsp+158h] [rbp+80h]
  int v32; // [rsp+160h] [rbp+88h]

  v8 = 0i64;
  getVolumeFromAxes(&resulta, vertexArray, numVertices, striding, retaddr);
  v9.m128_i32[0] = 0;
  v10.m128_i32[0] = 0;
  takeStepAxes(retaddr, v31, stepLength, (hkVector4f *)&resulta.m_real.m128_u16[4]);
  getVolumeFromAxes(&v25, vertexArray, numVertices, striding, (hkVector4f *)&resulta.m_real.m128_u16[4]);
  v11 = v25.m_real.m128_f32[0];
  v12 = resulta.m_real.m128_f32[0];
  if ( v25.m_real.m128_f32[0] >= resulta.m_real.m128_f32[0] )
  {
    m_real = stepLength->m_real;
    v17 = 0;
    v10.m128_i32[0] = v25.m_real.m128_i32[0];
    for ( i = stepLength->m_real; v17 < v32; ++v17 )
    {
      i = _mm_mul_ps(_mm_add_ps(i, (__m128)0i64), (__m128)xmmword_141A711B0);
      resulta.m_real = i;
      takeStepAxes(retaddr, v31, &resulta, (hkVector4f *)&resulta.m_real.m128_u16[4]);
      v9 = getVolumeFromAxes(&v28, vertexArray, numVertices, striding, (hkVector4f *)&resulta.m_real.m128_u16[4])->m_real;
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
    m_real = stepLength->m_real;
    if ( v32 > 0 )
    {
      v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0);
      do
      {
        m_real = _mm_mul_ps(m_real, v16);
        resulta.m_real = m_real;
        takeStepAxes(retaddr, v31, &resulta, (hkVector4f *)&resulta.m_real.m128_u16[4]);
        v10 = getVolumeFromAxes(&v28, vertexArray, numVertices, striding, (hkVector4f *)&resulta.m_real.m128_u16[4])->m_real;
        if ( v9.m128_f32[0] < v10.m128_f32[0] )
          break;
        i = m_real;
        v9.m128_i32[0] = v10.m128_i32[0];
        if ( v14 == v32 - 1 )
        {
          *result = (hkSimdFloat32)m_real;
          return result;
        }
        ++v14;
      }
      while ( v14 < v32 );
    }
  }
  if ( i.m128_f32[0] < 0.0
    || i.m128_f32[0] > m_real.m128_f32[0]
    || v12 < v9.m128_f32[0]
    || v10.m128_f32[0] < v9.m128_f32[0] )
  {
LABEL_29:
    *result = (hkSimdFloat32)g_vectorfConstants[0];
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
        v21 = _mm_sub_ps(m_real, i);
        if ( v20.m128_f32[0] <= v21.m128_f32[0] )
        {
          v23 = _mm_add_ps(_mm_mul_ps(v18, v21), i);
          v27.m_real = v23;
          takeStepAxes(retaddr, v31, &v27, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          getVolumeFromAxes(&v28, vertexArray, numVertices, striding, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          if ( v28.m_real.m128_f32[0] >= v9.m128_f32[0] )
          {
            m_real = v23;
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
          getVolumeFromAxes(&v25, vertexArray, numVertices, striding, (hkVector4f *)&resulta.m_real.m128_u16[4]);
          if ( v25.m_real.m128_f32[0] >= v9.m128_f32[0] )
          {
            v8 = v22;
          }
          else
          {
            m_real = i;
            v9.m128_i32[0] = v25.m_real.m128_i32[0];
            i = v22;
          }
        }
        --v19;
      }
      while ( v19 );
    }
    *result = (hkSimdFloat32)i;
  }
  return result;
}

// File Line: 928
// RVA: 0xCA61B0
hkSimdFloat32 *__fastcall doSteepestDescent(
        hkSimdFloat32 *result,
        const float *vertexArray,
        unsigned int numVertices,
        int striding,
        hkVector4f *axesIn,
        hkVector4f *axesOut,
        int maxIter)
{
  int v11; // ebx
  __m128 m_quad; // xmm8
  hkVector4f v13; // xmm9
  hkVector4f v14; // xmm10
  __m128 m_real; // xmm6
  __m128 v16; // xmm7
  hkSimdFloat32 *VolumeFromAxes; // rax
  hkSimdFloat32 v18; // xmm0
  hkSimdFloat32 stepIn; // [rsp+40h] [rbp-E8h] BYREF
  hkSimdFloat32 step; // [rsp+50h] [rbp-D8h] BYREF
  hkSimdFloat32 resulta; // [rsp+60h] [rbp-C8h] BYREF
  hkSimdFloat32 v23; // [rsp+70h] [rbp-B8h] BYREF
  hkVector4f gradOut; // [rsp+80h] [rbp-A8h] BYREF

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
      m_quad = axesOut->m_quad;
      v13.m_quad = (__m128)axesOut[1];
      v14.m_quad = (__m128)axesOut[2];
      getVolumeGradient(vertexArray, numVertices, striding, axesOut, &step, &gradOut);
      m_real = lineMinimize(&resulta, vertexArray, numVertices, striding)->m_real;
      stepIn.m_real = m_real;
      if ( m_real.m128_f32[0] < 0.0 )
        break;
      takeStepAxes(axesOut, &gradOut, &stepIn, axesOut);
      v16 = result->m_real;
      VolumeFromAxes = getVolumeFromAxes(&v23, vertexArray, numVertices, striding, axesOut);
      v18.m_real = VolumeFromAxes->m_real;
      *result = (hkSimdFloat32)VolumeFromAxes->m_real;
      if ( v16.m128_f32[0] < v18.m_real.m128_f32[0] )
      {
        *result = (hkSimdFloat32)v16;
        *axesOut = (hkVector4f)m_quad;
        axesOut[1] = (hkVector4f)v13.m_quad;
        axesOut[2] = (hkVector4f)v14.m_quad;
        return result;
      }
      if ( m_real.m128_f32[0] >= _mm_shuffle_ps((__m128)0x35A00000u, (__m128)0x35A00000u, 0).m128_f32[0]
        && ++v11 < maxIter )
      {
        continue;
      }
      return result;
    }
  }
  return result;
}

// File Line: 975
// RVA: 0xCA3970
void __fastcall hkGeometryUtility::calcObb(
        hkStridedVertices *stridedVertsIn,
        hkVector4f *halfExtents,
        hkTransformf *transform,
        hkGeomObbMode mode)
{
  int m_data; // eax
  int v8; // ebx
  hkLifoAllocator *Value; // rax
  float *m_cur; // r9
  int v11; // edx
  char *v12; // rcx
  int v13; // esi
  int v14; // ebx
  int v15; // r9d
  int v16; // r10d
  __int64 v17; // rdx
  __int64 v18; // r8
  const float *v19; // rbx
  int v20; // esi
  __m128 v21; // xmm8
  __m128 m_real; // xmm6
  int v23; // edx
  __m128 v24; // xmm2
  __m128 v25; // xmm7
  __m128 v26; // xmm3
  hkVector4f *p_axis0; // rax
  hkVector4f v28; // xmm1
  hkVector4f v29; // xmm2
  int v30; // eax
  char *v31; // rdi
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // r8d
  hkBool v35; // [rsp+40h] [rbp-B8h] BYREF
  float *array; // [rsp+48h] [rbp-B0h] BYREF
  int numVertices; // [rsp+50h] [rbp-A8h]
  int v38; // [rsp+54h] [rbp-A4h]
  void *p; // [rsp+58h] [rbp-A0h]
  int v40; // [rsp+60h] [rbp-98h]
  hkGeometry geometryOut; // [rsp+68h] [rbp-90h] BYREF
  hkVector4f mu; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f extents; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f v44; // [rsp+B8h] [rbp-40h] BYREF
  hkResult result; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f position; // [rsp+D8h] [rbp-20h] BYREF
  hkVector4f axes; // [rsp+E8h] [rbp-10h] BYREF
  __m128 v48; // [rsp+F8h] [rbp+0h]
  __m128 m_quad; // [rsp+108h] [rbp+10h]
  hkVector4f axis0; // [rsp+118h] [rbp+20h] BYREF
  hkVector4f axis1; // [rsp+128h] [rbp+30h] BYREF
  hkVector4f axis2; // [rsp+138h] [rbp+40h] BYREF
  hkSimdFloat32 v53; // [rsp+148h] [rbp+50h] BYREF
  hkMatrix3f cov; // [rsp+158h] [rbp+60h] BYREF

  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.m_vertices.m_data = (hkVector4f *)0x8000000000000000i64;
  *(_QWORD *)&geometryOut.m_vertices.m_size = 0i64;
  geometryOut.m_triangles.m_data = (hkGeometry::Triangle *)0x8000000000000000i64;
  hkGeometryUtility::createConvexGeometry(stridedVertsIn, &geometryOut);
  m_data = (int)geometryOut.m_triangles.m_data;
  array = 0i64;
  numVertices = 0;
  v8 = 3 * LODWORD(geometryOut.m_triangles.m_data);
  v38 = 0x80000000;
  v40 = 3 * LODWORD(geometryOut.m_triangles.m_data);
  if ( 3 * LODWORD(geometryOut.m_triangles.m_data) )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (float *)Value->m_cur;
    v11 = (16 * v8 + 127) & 0xFFFFFF80;
    v12 = (char *)m_cur + v11;
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    {
      m_cur = (float *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
      array = m_cur;
      m_data = (int)geometryOut.m_triangles.m_data;
    }
    else
    {
      Value->m_cur = v12;
      m_data = (int)geometryOut.m_triangles.m_data;
      array = m_cur;
    }
  }
  else
  {
    m_cur = 0i64;
    array = 0i64;
  }
  v13 = 3 * m_data;
  p = m_cur;
  v38 = v8 | 0x80000000;
  v14 = v8 & 0x3FFFFFFF;
  if ( v14 < 3 * m_data )
  {
    v15 = 3 * m_data;
    if ( v13 < 2 * v14 )
      v15 = 2 * v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v15, 16);
    m_data = (int)geometryOut.m_triangles.m_data;
    m_cur = array;
  }
  numVertices = v13;
  v16 = 0;
  if ( m_data > 0 )
  {
    v17 = 0i64;
    v18 = 0i64;
    while ( 1 )
    {
      ++v16;
      v18 += 16i64;
      v17 += 12i64;
      *(hkVector4f *)&m_cur[v17 - 12] = geometryOut.m_vertices.m_data[*(int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                             + v18
                                                                             - 16)];
      *(hkVector4f *)&array[v17 - 8] = geometryOut.m_vertices.m_data[*(int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                            + v18
                                                                            - 12)];
      *(hkVector4f *)&array[v17 - 4] = geometryOut.m_vertices.m_data[*(int *)(*(_QWORD *)&geometryOut.m_vertices.m_size
                                                                            + v18
                                                                            - 8)];
      if ( v16 >= SLODWORD(geometryOut.m_triangles.m_data) )
        break;
      m_cur = array;
    }
  }
  if ( !getIsBoxGeometry(&geometryOut.m_vertices, halfExtents, transform, 0.0099999998) )
  {
    v19 = array;
    v20 = numVertices;
    axes.m_quad = ::transform.m_quad;
    m_quad = stru_141A71280.m_quad;
    v48 = direction.m_quad;
    makeOBBUsingAxes(array, numVertices, 16, &extents, &axes, &position);
    v21 = extents.m_quad;
    m_real.m128_f32[0] = (float)(_mm_shuffle_ps(extents.m_quad, extents.m_quad, 85).m128_f32[0]
                               * _mm_shuffle_ps(extents.m_quad, extents.m_quad, 0).m128_f32[0])
                       * _mm_shuffle_ps(extents.m_quad, extents.m_quad, 170).m128_f32[0];
    getMeanAndCovariance(v19, v23, 16, &cov, &mu, 0);
    hkGeometryUtility::getAxesFromCovariance(&v35, &cov, &axis0, &axis1, &axis2);
    makeOBBUsingAxes(v19, v20, 16, &v44, &axis0, &mu);
    v24 = v44.m_quad;
    v25.m128_f32[0] = (float)(_mm_shuffle_ps(v44.m_quad, v44.m_quad, 85).m128_f32[0]
                            * _mm_shuffle_ps(v44.m_quad, v44.m_quad, 0).m128_f32[0])
                    * _mm_shuffle_ps(v44.m_quad, v44.m_quad, 170).m128_f32[0];
    if ( mode == HK_GEOM_OBB_MODE_BETTER_FIT_BUT_SLOWER )
    {
      m_real = doSteepestDescent(&v53, v19, v20, 16, &axes, &axes, 20)->m_real;
      makeOBBUsingAxes(v19, v20, 16, &extents, &axes, &position);
      v25 = doSteepestDescent(&v53, v19, v20, 16, &axis0, &axis0, 20)->m_real;
      makeOBBUsingAxes(v19, v20, 16, &v44, &axis0, &mu);
      v21 = extents.m_quad;
      v24 = v44.m_quad;
    }
    if ( m_real.m128_f32[0] >= v25.m128_f32[0] )
    {
      v26 = mu.m_quad;
      p_axis0 = &axis0;
      *halfExtents = (hkVector4f)v24;
    }
    else
    {
      v26 = position.m_quad;
      p_axis0 = &axes;
      *halfExtents = (hkVector4f)v21;
    }
    v28.m_quad = (__m128)p_axis0[1];
    v29.m_quad = (__m128)p_axis0[2];
    transform->m_rotation.m_col0 = (hkVector4f)p_axis0->m_quad;
    transform->m_rotation.m_col1 = (hkVector4f)v28.m_quad;
    transform->m_rotation.m_col2 = (hkVector4f)v29.m_quad;
    transform->m_translation.m_quad = v26;
  }
  v30 = numVertices;
  v31 = (char *)p;
  if ( p == array )
    v30 = 0;
  numVertices = v30;
  v32 = (16 * v40 + 127) & 0xFFFFFF80;
  v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v34 = (v32 + 15) & 0xFFFFFFF0;
  if ( v32 > v33->m_slabSize || &v31[v34] != v33->m_cur || v33->m_firstNonLifoEnd == v31 )
    hkLifoAllocator::slowBlockFree(v33, v31, v34);
  else
    v33->m_cur = v31;
  numVertices = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v38);
  array = 0i64;
  v38 = 0x80000000;
  LODWORD(geometryOut.m_triangles.m_data) = 0;
  if ( SHIDWORD(geometryOut.m_triangles.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&geometryOut.m_vertices.m_size,
      16 * HIDWORD(geometryOut.m_triangles.m_data));
  *(_QWORD *)&geometryOut.m_vertices.m_size = 0i64;
  LODWORD(geometryOut.m_vertices.m_data) = 0;
  HIDWORD(geometryOut.m_triangles.m_data) = 0x80000000;
  if ( SHIDWORD(geometryOut.m_vertices.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
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
                                 _mm_cmple_ps(v8, (__m128)0i64),
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
hkSphere *__fastcall makeSphere_0(
        hkSphere *result,
        hkVector4f *pA,
        hkVector4f *pB,
        hkVector4f *pC,
        hkSimdFloat32 *radiusEpsilon)
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
  v12 = _mm_shuffle_ps(v10, v10, 201);
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
                                 _mm_cmple_ps(v24, (__m128)0i64),
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
hkSphere *__fastcall makeSphere_1(
        hkSphere *result,
        hkVector4f *pA,
        hkVector4f *pB,
        hkVector4f *pC,
        hkVector4f *pD,
        hkSimdFloat32 *radiusEpsilon)
{
  __m128 m_quad; // xmm0
  hkVector4f v9; // xmm7
  __m128 v10; // xmm10
  hkVector4f v11; // xmm10
  __m128 v12; // xmm6
  hkVector4f v13; // xmm6
  hkSimdFloat32 *Determinant; // rax
  __m128 v15; // xmm2
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm9
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm0
  __m128 v26; // xmm10
  __m128 v27; // xmm5
  __m128 v28; // xmm8
  __m128 v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  hkSphere *v34; // rax
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-98h] BYREF
  hkMatrix3f v36; // [rsp+30h] [rbp-88h] BYREF

  m_quad = pA->m_quad;
  v9.m_quad = _mm_sub_ps(pC->m_quad, pA->m_quad);
  v10 = pB->m_quad;
  v36.m_col1 = (hkVector4f)v9.m_quad;
  v11.m_quad = _mm_sub_ps(v10, m_quad);
  v12 = pD->m_quad;
  v36.m_col0 = (hkVector4f)v11.m_quad;
  v13.m_quad = _mm_sub_ps(v12, m_quad);
  v36.m_col2 = (hkVector4f)v13.m_quad;
  Determinant = hkMatrix3f::getDeterminant(&v36, &resulta);
  v15 = _mm_mul_ps(v13.m_quad, v13.m_quad);
  v16 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 201);
  v17 = _mm_rcp_ps(Determinant->m_real);
  v18 = _mm_mul_ps(v9.m_quad, v9.m_quad);
  v19 = _mm_shuffle_ps(v11.m_quad, v11.m_quad, 201);
  v20 = _mm_mul_ps(v19, v13.m_quad);
  v21 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(Determinant->m_real, v17)), v17);
  v22 = _mm_shuffle_ps(v9.m_quad, v9.m_quad, 201);
  v23 = _mm_mul_ps(v22, v13.m_quad);
  v24 = _mm_sub_ps(_mm_mul_ps(v22, v11.m_quad), _mm_mul_ps(v19, v9.m_quad));
  v25 = _mm_mul_ps(v16, v11.m_quad);
  v26 = _mm_mul_ps(v11.m_quad, v11.m_quad);
  v27 = _mm_sub_ps(v20, v25);
  v28 = _mm_sub_ps(_mm_mul_ps(v16, v9.m_quad), v23);
  v29 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  _mm_shuffle_ps(v24, v24, 201)),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                  _mm_shuffle_ps(v18, v18, 170)),
                _mm_shuffle_ps(v27, v27, 201))),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170)),
              _mm_shuffle_ps(v28, v28, 201))),
          _mm_mul_ps(v21, (__m128)xmmword_141A711B0));
  v30 = _mm_add_ps(pA->m_quad, v29);
  v31 = _mm_mul_ps(v29, v29);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  v34 = result;
  result->m_pos.m_quad = _mm_shuffle_ps(
                           v30,
                           _mm_unpackhi_ps(
                             v30,
                             _mm_add_ps(
                               _mm_andnot_ps(
                                 _mm_cmple_ps(v32, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v33)),
                                   v32)),
                               radiusEpsilon->m_real)),
                           196);
  return v34;
}

// File Line: 1148
// RVA: 0xCA67E0
hkSphere *__fastcall miniSphereRecurseCall(
        hkSphere *result,
        hkVector4f *verts,
        int numVerts,
        int supportSize,
        hkSimdFloat32 *radiusEpsilon)
{
  hkSphere *v5; // r10
  int v6; // r11d
  hkVector4f *v8; // rdx
  hkVector4f *v9; // r8
  int v10; // ecx
  hkVector4f *v11; // r9
  __m128 m_quad; // xmm0
  hkSphere *v13; // rax
  hkSphere *Sphere_0; // rax
  hkSphere *Sphere; // rax
  hkSimdFloat32 *v16; // r9
  hkSimdFloat32 *v17; // r8
  int v18; // ebx
  __int64 v19; // rdi
  hkVector4f *v20; // rbp
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __int64 v25; // rcx
  hkVector4f *v26; // rax
  __m128 v27; // xmm1
  hkVector4f v28; // xmm0
  hkSphere *v29; // rax
  hkSphere resulta; // [rsp+30h] [rbp-78h] BYREF
  hkSphere v31; // [rsp+40h] [rbp-68h] BYREF
  hkSphere v32; // [rsp+50h] [rbp-58h] BYREF
  int v35; // [rsp+C8h] [rbp+20h]

  v35 = supportSize;
  v5 = result;
  v6 = numVerts;
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
    v9 = verts - 2;
    v10 = supportSize - 2;
    if ( supportSize != 2 )
    {
      v11 = verts - 3;
      if ( v10 != 1 )
      {
        m_quad = makeSphere_1(&resulta, v8, v9, v11, verts - 4, radiusEpsilon)->m_pos.m_quad;
        v13 = result;
        *result = (hkSphere)m_quad;
        return v13;
      }
      Sphere_0 = makeSphere_0(&v31, v8, v9, v11, radiusEpsilon);
      supportSize = v35;
      *v5 = (hkSphere)Sphere_0->m_pos.m_quad;
      goto LABEL_10;
    }
    Sphere = makeSphere(&v32, v8, v9, radiusEpsilon);
    v17 = v16;
    supportSize = v35;
    *v5 = (hkSphere)Sphere->m_pos.m_quad;
  }
LABEL_11:
  v18 = 0;
  v19 = 0i64;
  if ( v6 > 0 )
  {
    v20 = verts;
    do
    {
      v21 = _mm_sub_ps(v20->m_quad, v5->m_pos.m_quad);
      v22 = _mm_mul_ps(v21, v21);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_rsqrt_ps(v23);
      if ( _mm_andnot_ps(
             _mm_cmple_ps(v23, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                 _mm_mul_ps(*(__m128 *)_xmm, v24)),
               v23)).m128_f32[0] > _mm_shuffle_ps(v5->m_pos.m_quad, v5->m_pos.m_quad, 255).m128_f32[0] )
      {
        v25 = v19;
        if ( v19 > 0 )
        {
          v26 = v20;
          do
          {
            v27 = v26->m_quad;
            v28.m_quad = (__m128)v26[-1];
            --v25;
            --v26;
            v26[1] = (hkVector4f)v28.m_quad;
            *v26 = (hkVector4f)v27;
          }
          while ( v25 > 0 );
        }
        v29 = miniSphereRecurseCall(&v32, verts + 1, v18, supportSize + 1, v17);
        v5 = result;
        v6 = numVerts;
        *result = (hkSphere)v29->m_pos.m_quad;
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
hkSphere *__fastcall hkGeometryUtility::createMinBoundingSphere(
        hkSphere *result,
        hkStridedVertices *stridedVertsIn,
        const float radiusEpsilon)
{
  int m_numVertices; // ebx
  hkMemoryAllocator **Value; // rax
  hkVector4f *v7; // rax
  int v8; // r8d
  hkVector4f *v9; // rbx
  int v10; // eax
  int v11; // r9d
  hkVector4f *v12; // r10
  __int64 v13; // rdx
  int v14; // r8d
  hkMemoryAllocator **v15; // rax
  hkSimdFloat32 v17; // [rsp+30h] [rbp-18h] BYREF

  m_numVertices = stridedVertsIn->m_numVertices;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkVector4f *)hkMemoryRouter::alignedAlloc(Value[11], 16 * m_numVertices, 16);
  v8 = 0;
  v9 = v7;
  v10 = stridedVertsIn->m_striding / 4;
  if ( stridedVertsIn->m_numVertices > 0 )
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
                         (__m128)*(unsigned __int64 *)&stridedVertsIn->m_vertices[v13],
                         (__m128)LODWORD(stridedVertsIn->m_vertices[v13 + 2]));
    }
    while ( v8 < stridedVertsIn->m_numVertices );
  }
  v14 = stridedVertsIn->m_numVertices;
  v17.m_real = _mm_shuffle_ps((__m128)LODWORD(radiusEpsilon), (__m128)LODWORD(radiusEpsilon), 0);
  miniSphereRecurseCall(result, v9, v14, 0, &v17);
  v15 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v15[11], (int *)v9);
  return result;
}

