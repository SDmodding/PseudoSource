// File Line: 50
// RVA: 0xC00D00
__int64 __fastcall hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(hkaiStreamingCollection::InstanceInfo *sectionInfo, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges, unsigned int startFaceKey, hkVector4f *startPoint, hkVector4f *endPoint, unsigned int project, unsigned int computeNormals, hkVector4f *up, float radius, bool useSimpleSmoothing, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut, hkaiPath::PathPoint *pathPtrOut, int maxPathLength, hkSimdFloat32 *stringPulledLength)
{
  hkVector4f *v14; // rbx
  unsigned int v15; // edi
  hkArray<unsigned int,hkContainerHeapAllocator> *v16; // rsi
  unsigned int v17; // ebx
  bool v18; // al
  hkaiGeneralAccessor accessor; // [rsp+60h] [rbp-1C8h]
  hkaiPathWriter writer; // [rsp+80h] [rbp-1A8h]
  hkaiStringPulling v22; // [rsp+C0h] [rbp-168h]
  hkaiNavMeshPathSmoothingUtil v23; // [rsp+1D0h] [rbp-58h]

  accessor.m_sectionInfo = sectionInfo;
  v14 = startPoint;
  v15 = startFaceKey;
  v16 = visitedEdges;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  hkaiPathWriter::hkaiPathWriter(&writer);
  hkaiPathWriter::init(&writer, pathArrayOut, pathPtrOut, maxPathLength);
  if ( useSimpleSmoothing )
  {
    hkaiNavMeshPathSmoothingUtil::hkaiNavMeshPathSmoothingUtil(
      &v23,
      &accessor,
      v16,
      v15,
      v14,
      endPoint,
      up,
      radius,
      &writer);
    v17 = hkaiNavMeshPathSmoothingUtil::findSimpleSmoothPath(&v23, computeNormals);
  }
  else
  {
    hkaiStringPulling::hkaiStringPulling(
      &v22,
      &accessor,
      v16,
      v15,
      v14,
      endPoint,
      project,
      computeNormals,
      up,
      radius,
      &writer);
    v18 = hkaiStringPulling::stringPull(&v22);
    v22.m_funnel.m_data.m_size = 0;
    v17 = v18;
    if ( v22.m_funnel.m_data.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v22.m_funnel.m_data.m_data,
        48 * (v22.m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF));
    v22.m_funnel.m_data.m_data = 0i64;
    v22.m_funnel.m_data.m_capacityAndFlags = 2147483648;
    hkaiStringPulling::PathEdgeCache::~PathEdgeCache(&v22.m_pathEdgeCache);
  }
  if ( stringPulledLength )
    *stringPulledLength = writer.m_totalDistance;
  return v17;
}

// File Line: 93
// RVA: 0xC00ED0
__int64 __fastcall hkaiNavMeshPathSmoothingUtil::projectStraightPath(hkaiStreamingCollection::InstanceInfo *sectionInfo, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges, unsigned int startFaceKey, hkVector4f *startPoint, hkVector4f *endPoint, unsigned int project, unsigned int computeNormals, hkVector4f *up, float radius, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut, hkaiPath::PathPoint *pathPtrOut, int maxPathLength)
{
  hkVector4f *v12; // rsi
  unsigned int v13; // ebx
  hkArray<unsigned int,hkContainerHeapAllocator> *v14; // r14
  int v15; // eax
  __m128 v16; // xmm0
  bool v17; // cf
  bool v18; // zf
  bool v19; // al
  BOOL v20; // ebx
  hkaiStringPulling::Vertex a; // [rsp+60h] [rbp-A0h]
  hkaiStringPulling::Vertex b; // [rsp+90h] [rbp-70h]
  hkaiGeneralAccessor accessor; // [rsp+C0h] [rbp-40h]
  hkaiPathWriter writer; // [rsp+E0h] [rbp-20h]
  hkaiStringPulling v26; // [rsp+120h] [rbp+20h]

  accessor.m_sectionInfo = sectionInfo;
  v12 = startPoint;
  v13 = startFaceKey;
  v14 = visitedEdges;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  hkaiPathWriter::hkaiPathWriter(&writer);
  hkaiPathWriter::init(&writer, pathArrayOut, pathPtrOut, maxPathLength);
  hkaiStringPulling::hkaiStringPulling(
    &v26,
    &accessor,
    v14,
    v13,
    v12,
    endPoint,
    project,
    computeNormals,
    up,
    radius,
    &writer);
  v15 = v14->m_size;
  a.m_pos = (hkVector4f)v12->m_quad;
  a.m_center = a.m_pos;
  v16 = endPoint->m_quad;
  a.m_clearanceIsNegative.m_bool = v12->m_quad.m128_f32[3] < 0.0;
  v17 = endPoint->m_quad.m128_f32[3] > 0.0;
  v18 = endPoint->m_quad.m128_f32[3] == 0.0;
  b.m_pos.m_quad = v16;
  b.m_center.m_quad = v16;
  *(_WORD *)&a.m_userEdge.m_bool = 0;
  *(_WORD *)&b.m_userEdge.m_bool = 0;
  *(_WORD *)&b.m_clearanceIsNegative.m_bool = !v17 && !v18;
  *(_WORD *)&a.m_side.m_storage = 511;
  a.m_index = -1;
  *(_WORD *)&b.m_side.m_storage = 767;
  b.m_index = v15;
  hkaiStringPulling::addSegmentToPath(&v26, &a, &b);
  v19 = hkaiStringPulling::terminateOutput(&v26);
  v26.m_funnel.m_data.m_size = 0;
  v20 = v19;
  if ( v26.m_funnel.m_data.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v26.m_funnel.m_data.m_data,
      48 * (v26.m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF));
  v26.m_funnel.m_data.m_data = 0i64;
  v26.m_funnel.m_data.m_capacityAndFlags = 2147483648;
  hkaiStringPulling::PathEdgeCache::~PathEdgeCache(&v26.m_pathEdgeCache);
  return (unsigned int)v20;
}

// File Line: 135
// RVA: 0xC01DC0
signed __int64 __fastcall getLineSegInterpolationValue(hkVector4f *A, hkVector4f *dA, hkVector4f *B, hkVector4f *dB, float *uOut)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  float v7; // xmm7_4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  float v10; // xmm10_4
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  float v13; // xmm11_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm8_4
  float v17; // xmm2_4
  float v18; // xmm9_4
  float v19; // xmm2_4
  signed __int64 result; // rax
  float v21; // xmm2_4
  unsigned int v22; // ecx
  float v23; // xmm0_4

  v5 = _mm_sub_ps(B->m_quad, A->m_quad);
  v6 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v7 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
     + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_mul_ps(dA->m_quad, v5);
  v9 = _mm_mul_ps(dA->m_quad, dA->m_quad);
  v10 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170));
  v11 = _mm_mul_ps(dB->m_quad, v5);
  v12 = _mm_mul_ps(dB->m_quad, dB->m_quad);
  v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
  v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170));
  v15 = *(float *)&FLOAT_1_0;
  v16 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
  v17 = (float)(v16 * v10) - (float)(v13 * v7);
  LODWORD(v18) = (unsigned int)(2 * COERCE_SIGNED_INT((float)(v16 * v14) - (float)(v7 * v7))) >> 1;
  if ( (float)(v17 * v18) >= (float)(v18 * v18) )
    goto LABEL_19;
  if ( v17 <= 0.0 )
  {
    v19 = 0.0;
    result = 2i64;
    goto LABEL_7;
  }
  if ( v18 <= (float)((float)((float)(v7 * v7) + (float)(v16 * v14)) * 0.00000095367432) )
  {
LABEL_19:
    result = 1i64;
    v19 = *(float *)&FLOAT_1_0;
  }
  else
  {
    v19 = v17 / v18;
    result = 0i64;
  }
LABEL_7:
  v21 = (float)(v19 * v7) - v13;
  if ( v21 < v16 )
  {
    if ( v21 > 0.0 )
    {
      *uOut = v21 / v16;
      return result;
    }
    v15 = 0.0;
    v22 = 8;
  }
  else
  {
    v22 = 4;
  }
  *uOut = v15;
  v23 = (float)(v15 * v7) + v10;
  if ( v23 < -0.0099999998 )
    return v22 | 2;
  if ( v23 > (float)(v14 + 0.0099999998) )
    v22 |= 1u;
  return v22;
}

// File Line: 226
// RVA: 0xC01FD0
void __usercall getProjectedMidpoint(hkVector4f *apex@<rcx>, hkVector4f *edgeA@<rdx>, hkVector4f *edgeB@<r8>, float tA@<xmm3>, __m128 a5@<xmm4>, float tB, hkVector4f *portalA, hkVector4f *portalB, hkVector4f *collapse)
{
  hkVector4f *v9; // rax
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // ST10_16
  __m128 v13; // xmm14
  __m128 v14; // ST00_16
  __m128 v15; // xmm1
  __m128 v16; // xmm11
  __m128 v17; // xmm9
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm8
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm7
  __m128 v36; // xmm1
  __m128 v37; // xmm14
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm15
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  float portalAa; // [rsp+F8h] [rbp+30h]

  v9 = portalA;
  a5.m128_f32[0] = tA;
  v10 = _mm_sub_ps(edgeB->m_quad, edgeA->m_quad);
  v11 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), v10), edgeA->m_quad), apex->m_quad);
  v12 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(tB), (__m128)LODWORD(tB), 0), v10), edgeA->m_quad),
          apex->m_quad);
  v13 = _mm_sub_ps(portalA->m_quad, apex->m_quad);
  v14 = _mm_sub_ps(portalB->m_quad, portalA->m_quad);
  v15 = _mm_mul_ps(v14, v11);
  v16 = _mm_mul_ps(v14, v14);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v18 = _mm_mul_ps(v13, v11);
  v19 = _mm_mul_ps(v11, v11);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v21 = _mm_mul_ps(v13, v14);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v24 = _mm_max_ps(
          _mm_sub_ps(
            _mm_mul_ps(
              v23,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170))),
            _mm_mul_ps(v17, v17)),
          *(__m128 *)&epsilon);
  v25 = _mm_rcp_ps(v24);
  v26 = _mm_cmpleps(v24, *(__m128 *)&epsilon);
  v27 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v24)), v25);
  v28 = _mm_rcp_ps(v23);
  v29 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v23)), v28);
  v30 = _mm_sub_ps(_mm_mul_ps(v23, v20), _mm_mul_ps(v22, v17));
  v31 = _mm_cmpltps(v30, v24);
  v32 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v26,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v31, v24), _mm_and_ps(v30, v31))), v27)),
              _mm_and_ps(v26, query.m_quad)),
            _mm_mul_ps(v29, v17)),
          _mm_mul_ps(v29, v22));
  v33 = _mm_cmpltps(v32, query.m_quad);
  v22.m128_f32[0] = fmax(
                      0.0,
                      COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(v33, query.m_quad) | v32.m128_i32[0] & v33.m128_i32[0]));
  v34 = _mm_mul_ps(v14, v12);
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v36 = v13;
  v37 = _mm_mul_ps(v13, v14);
  v38 = _mm_mul_ps(v36, v12);
  v39 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v40 = _mm_mul_ps(v12, v12);
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v42 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v43 = _mm_max_ps(
          _mm_sub_ps(
            _mm_mul_ps(
              v42,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                _mm_shuffle_ps(v40, v40, 170))),
            _mm_mul_ps(v35, v35)),
          *(__m128 *)&epsilon);
  v44 = _mm_rcp_ps(v43);
  v45 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v43)), v44);
  v46 = _mm_rcp_ps(v42);
  v47 = _mm_mul_ps(v46, v42);
  v48 = _mm_mul_ps(v42, v39);
  v49 = _mm_cmpleps(v43, *(__m128 *)&epsilon);
  v50 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v47), v46);
  v51 = _mm_sub_ps(v48, _mm_mul_ps(v41, v35));
  v52 = _mm_cmpltps(v51, v43);
  v53 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v49,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v52, v43), _mm_and_ps(v51, v52))), v45)),
              _mm_and_ps(v49, query.m_quad)),
            _mm_mul_ps(v50, v35)),
          _mm_mul_ps(v50, v41));
  v54 = _mm_cmpltps(v53, query.m_quad);
  portalAa = fmax(
               0.0,
               COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(v54, query.m_quad) | v53.m128_i32[0] & v54.m128_i32[0]));
  v55 = (__m128)LODWORD(portalAa);
  v55.m128_f32[0] = (float)(fminf(fmaxf(portalAa, 0.050000001), 0.94999999)
                          + fminf(fmaxf(v22.m128_f32[0], 0.050000001), 0.94999999))
                  * 0.5;
  collapse->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v14), v9->m_quad);
}

// File Line: 244
// RVA: 0xC01090
__int64 __fastcall hkaiNavMeshPathSmoothingUtil::findSimpleSmoothPath(hkaiNavMeshPathSmoothingUtil *this, unsigned int computeNormals)
{
  int v2; // er13
  unsigned int v3; // er14
  hkaiNavMeshPathSmoothingUtil *v4; // rsi
  __int64 v5; // rdi
  int v6; // ebx
  int v7; // er15
  hkLifoAllocator *v8; // rax
  int v9; // edx
  char *v10; // rcx
  hkLifoAllocator *v11; // rax
  _OWORD *v12; // r15
  int v13; // edx
  char *v14; // rcx
  hkLifoAllocator *v15; // rax
  hkLifoAllocator *v16; // rcx
  hkVector4f *v17; // rax
  int v18; // edx
  char *v19; // r8
  signed int v20; // er14
  __int64 v21; // r12
  unsigned int v22; // ebx
  hkaiGeneralAccessor *v23; // rcx
  hkaiNavMesh::Edge *v24; // rax
  unsigned int v25; // edx
  hkaiNavMesh::Edge *v26; // r15
  char v27; // r8
  unsigned int v28; // ecx
  int v29; // esi
  unsigned int v30; // edx
  unsigned int v31; // eax
  unsigned int v32; // edi
  __int64 v33; // rbx
  signed __int64 v34; // rax
  int v35; // edx
  __m128 *v36; // rcx
  int v37; // edx
  __m128 v38; // xmm2
  int v39; // edx
  int v40; // edx
  __m128 *v41; // rcx
  int v42; // edx
  __m128 v43; // xmm2
  signed __int64 v44; // rcx
  signed __int64 v45; // rax
  hkaiGeneralAccessor **v46; // r13
  _OWORD *v47; // r8
  int v48; // eax
  __int128 v49; // xmm0
  int v50; // ecx
  int v51; // er14
  hkVector4f *v52; // rdi
  int v53; // ebx
  signed __int64 v54; // rdx
  float v55; // xmm9_4
  float v56; // xmm10_4
  __m128 v57; // xmm11
  __m128 v58; // xmm1
  float v59; // esi
  signed __int64 v60; // r12
  bool v61; // zf
  __m128 *v62; // rax
  __m128 v63; // xmm1
  __m128 *v64; // rax
  __m128 v65; // xmm0
  int v66; // er15
  int v67; // eax
  float v68; // xmm7_4
  float v69; // xmm2_4
  float v70; // xmm6_4
  float v71; // xmm1_4
  __m128 v72; // xmm8
  float v73; // eax
  signed __int64 v74; // r15
  signed __int64 v75; // r12
  signed __int64 v76; // rdi
  __int64 v77; // rbx
  signed __int64 v78; // r14
  __m128 v79; // xmm1
  __m128 v80; // xmm0
  __m128 v81; // xmm7
  __m128 v82; // xmm6
  __m128 v83; // xmm6
  __m128 v84; // xmm2
  __m128 v85; // xmm0
  __int64 v86; // r12
  __int64 v87; // rbx
  __int64 v88; // r14
  __m128 v89; // xmm7
  __m128 v90; // xmm6
  __m128i *v91; // r15
  int v92; // edi
  signed __int64 v93; // rbx
  int v94; // er14
  unsigned int v95; // er12
  unsigned int v96; // edx
  int v97; // er9
  char v98; // al
  hkaiGeneralAccessor *v99; // rcx
  bool v100; // al
  char *v101; // rdi
  int v102; // eax
  BOOL v103; // esi
  signed int v104; // ebx
  hkLifoAllocator *v105; // rax
  int v106; // er8
  int v107; // edi
  signed int v108; // ebx
  hkLifoAllocator *v109; // rax
  int v110; // er8
  int v111; // ebx
  signed int v112; // edi
  hkLifoAllocator *v113; // rax
  int v114; // er8
  _OWORD *v116; // [rsp+40h] [rbp-A0h]
  int v117; // [rsp+48h] [rbp-98h]
  int v118; // [rsp+48h] [rbp-98h]
  hkVector4f *array; // [rsp+50h] [rbp-90h]
  int v120; // [rsp+58h] [rbp-88h]
  int v121; // [rsp+5Ch] [rbp-84h]
  void *v122; // [rsp+60h] [rbp-80h]
  hkVector4f normalOut; // [rsp+68h] [rbp-78h]
  float v124; // [rsp+78h] [rbp-68h]
  hkVector4f edgeAOut; // [rsp+80h] [rbp-60h]
  hkVector4f edgeBOut; // [rsp+90h] [rbp-50h]
  int v127; // [rsp+A0h] [rbp-40h]
  float uOut; // [rsp+A4h] [rbp-3Ch]
  hkVector4f normal; // [rsp+B0h] [rbp-30h]
  int v130; // [rsp+C0h] [rbp-20h]
  hkVector4f B; // [rsp+D0h] [rbp-10h]
  __int64 v132; // [rsp+E0h] [rbp+0h]
  __int64 v133; // [rsp+E8h] [rbp+8h]
  hkVector4f dB; // [rsp+F0h] [rbp+10h]
  hkVector4f p; // [rsp+100h] [rbp+20h]
  __int64 v136; // [rsp+110h] [rbp+30h]
  unsigned __int64 v137; // [rsp+118h] [rbp+38h]
  hkVector4f B2; // [rsp+120h] [rbp+40h]
  __int64 v139; // [rsp+130h] [rbp+50h]
  hkVector4f edgeB; // [rsp+140h] [rbp+60h]
  unsigned __int64 v141; // [rsp+150h] [rbp+70h]
  hkVector4f v142; // [rsp+160h] [rbp+80h]
  hkVector4f dA; // [rsp+170h] [rbp+90h]
  hkaiGeneralAccessor **v144; // [rsp+240h] [rbp+160h]
  float v145; // [rsp+248h] [rbp+168h]
  int vars0; // [rsp+250h] [rbp+170h]
  int *edgeDataOut; // [rsp+258h] [rbp+178h]

  v2 = 0;
  v3 = computeNormals;
  v4 = this;
  v5 = this->m_visitedEdges->m_size;
  v6 = 2 * v5;
  v7 = 2 * v5 + 2;
  v127 = 2 * v5 + 2;
  if ( 2 * (_DWORD)v5 == -2 )
  {
    v116 = 0i64;
  }
  else
  {
    v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v116 = v8->m_cur;
    v9 = (16 * v7 + 127) & 0xFFFFFF80;
    v10 = (char *)v116 + v9;
    if ( v9 > v8->m_slabSize || v10 > v8->m_end )
      v116 = hkLifoAllocator::allocateFromNewSlab(v8, v9);
    else
      v8->m_cur = v10;
  }
  v130 = v7 | 0x80000000;
  if ( 2 * (_DWORD)v5 == -2 )
  {
    v12 = 0i64;
    normalOut.m_quad.m128_u64[1] = 0i64;
  }
  else
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = v11->m_cur;
    normalOut.m_quad.m128_u64[1] = (unsigned __int64)v12;
    v13 = (16 * (2 * v5 + 2) + 127) & 0xFFFFFF80;
    v14 = (char *)v12 + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    {
      v12 = hkLifoAllocator::allocateFromNewSlab(v11, v13);
      normalOut.m_quad.m128_u64[1] = (unsigned __int64)v12;
    }
    else
    {
      v11->m_cur = v14;
    }
  }
  array = 0i64;
  v120 = 0;
  v121 = 2147483648;
  normalOut.m_quad.m128_i32[0] = 2 * v5;
  if ( v6 )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = v15;
    v17 = (hkVector4f *)v15->m_cur;
    v18 = (96 * v5 + 127) & 0xFFFFFF80;
    v19 = (char *)v17 + v18;
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      v17 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
  }
  else
  {
    v17 = 0i64;
  }
  array = v17;
  v122 = v17;
  v121 = v6 | 0x80000000;
  if ( v3 )
  {
    hkaiGeneralAccessor::setSection(v4->m_accessor, v4->m_startFaceKey >> 22);
    v20 = 1;
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&normal,
      (hkSimdFloat32 *)v4->m_accessor->m_accessor,
      (hkaiNavMeshInstance *)(v4->m_startFaceKey & 0x3FFFFF),
      (__int64)v12);
  }
  else
  {
    v20 = 1;
    *v12 = v4->m_up;
  }
  vars0 = -1;
  v132 = v5;
  v21 = 0i64;
  if ( (signed int)v5 > 0 )
  {
    v117 = v5 - 1;
    do
    {
      v22 = v4->m_visitedEdges->m_data[v21];
      v23 = v4->m_accessor;
      normalOut.m_quad.m128_u64[0] = 0i64;
      LODWORD(edgeDataOut) = v22;
      v24 = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(v23, v22, &edgeAOut, &edgeBOut, (const int **)&normalOut);
      v25 = v24->m_oppositeEdge;
      v26 = v24;
      v27 = v24->m_flags.m_storage & 0x40;
      if ( v27 )
        v28 = v25 & 0xFFC00000;
      else
        v28 = v4->m_accessor->m_accessor->m_runtimeId << 22;
      v29 = v28 | v25 & 0x3FFFFF;
      v61 = v25 == -1;
      v30 = v24->m_oppositeFace;
      if ( v61 )
        v29 = -1;
      if ( v27 )
        v31 = v30 & 0xFFC00000;
      else
        v31 = (*v144)->m_accessor->m_runtimeId << 22;
      v32 = v31 | v30 & 0x3FFFFF;
      if ( v30 == -1 )
        v32 = -1;
      if ( v145 == 0.0 )
      {
        v34 = 16i64 * v20++;
        *(_OWORD *)(normalOut.m_quad.m128_u64[1] + v34) = *((_OWORD *)v144 + 3);
      }
      else
      {
        v33 = v20++;
        hkaiGeneralAccessor::setSection(*v144, v32 >> 22);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&normal,
          (hkSimdFloat32 *)(*v144)->m_accessor,
          (hkaiNavMeshInstance *)(v32 & 0x3FFFFF),
          normalOut.m_quad.m128_u64[1] + 16 * v33);
        v22 = (unsigned int)edgeDataOut;
      }
      v35 = v120;
      if ( v120 == (v121 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 48);
        v35 = v120;
      }
      v120 = v35 + 1;
      v36 = &array[3 * v35].m_quad;
      v37 = 0;
      *v36 = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, (__m128)0i64), 196);
      v38 = edgeBOut.m_quad;
      v36[2].m128_i32[0] = v22;
      v36[1] = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, query.m_quad), 196);
      if ( v26->m_flags.m_storage & 0x10 && normalOut.m_quad.m128_u64[0] )
        v37 = *(_DWORD *)normalOut.m_quad.m128_u64[0];
      v36[2].m128_i32[1] = v37;
      v39 = vars0;
      if ( v2 == v117 )
        v39 = v29;
      v36[2].m128_i8[8] = ((unsigned __int8)v26->m_flags.m_storage >> 4) & 1;
      v61 = (v26->m_flags.m_storage & 0x10) == 0;
      vars0 = v39;
      if ( v61 )
      {
        v12 = (_OWORD *)normalOut.m_quad.m128_u64[1];
      }
      else
      {
        edgeDataOut = 0i64;
        hkaiGeneralAccessor::getEdgeAndVertsFromPacked(*v144, v29, &edgeAOut, &edgeBOut, (const int **)&edgeDataOut);
        v40 = v120;
        if ( v120 == (v121 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 48);
          v40 = v120;
        }
        v120 = v40 + 1;
        v41 = &array[3 * v40].m_quad;
        v42 = 0;
        *v41 = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, (__m128)0i64), 196);
        v43 = edgeBOut.m_quad;
        v41[2].m128_i32[0] = v29;
        v41[1] = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, query.m_quad), 196);
        if ( v26->m_flags.m_storage & 0x10 && edgeDataOut )
          v42 = *edgeDataOut;
        v12 = (_OWORD *)normalOut.m_quad.m128_u64[1];
        v41[2].m128_i32[1] = v42;
        v41[2].m128_i8[8] = 2;
        v44 = v20;
        v45 = v20++;
        v12[v44] = v12[v45 - 1];
      }
      v4 = (hkaiNavMeshPathSmoothingUtil *)v144;
      ++v21;
      ++v2;
    }
    while ( v21 < v132 );
  }
  v46 = v144;
  v47 = v116;
  *(float *)&v48 = 0.0;
  v12[v20] = v12[v20 - 1];
  v49 = *((_OWORD *)v46 + 1);
  LODWORD(v144) = 0;
  v50 = v120 + 2;
  v118 = v120 + 2;
  *v116 = v49;
  v51 = v120;
  if ( v120 > 0 )
  {
    v52 = array;
    while ( 1 )
    {
      v53 = v48 + 1;
      normalOut.m_quad.m128_i32[3] = v48;
      v139 = v48;
      v54 = v48;
      v55 = 0.0;
      v56 = *(float *)&FLOAT_1_0;
      normalOut.m_quad.m128_i32[2] = v48;
      v57 = (__m128)v47[v54];
      edgeAOut.m_quad = (__m128)v47[v54];
      v137 = 48i64 * v48;
      v141 = 16i64 * v48;
      v58 = v52[v137 / 0x10].m_quad;
      edgeB.m_quad = (__m128)v52[v137 / 0x10 + 1];
      B.m_quad = v58;
      dB.m_quad = _mm_sub_ps(edgeB.m_quad, v58);
      if ( v48 + 1 > v51 )
      {
LABEL_86:
        v73 = *(float *)&v144;
        goto LABEL_87;
      }
      v59 = *(float *)&v48;
      v133 = 48i64 * v48;
      v60 = 48i64 * v53;
      v61 = v53 == v51;
      v136 = 48i64 * v48;
      v145 = *(float *)&v48;
      while ( 1 )
      {
        if ( v61 )
          v62 = (__m128 *)(v46 + 4);
        else
          v62 = &v52[3 * v53].m_quad;
        v63 = *v62;
        if ( v53 == v51 )
          v64 = (__m128 *)(v46 + 4);
        else
          v64 = &v52[3 * v53 + 1].m_quad;
        v65 = _mm_sub_ps(*v64, v57);
        dA.m_quad = _mm_sub_ps(v63, v57);
        v142.m_quad = v65;
        v66 = getLineSegInterpolationValue(&edgeAOut, &dA, &B, &dB, &uOut);
        v67 = getLineSegInterpolationValue(&edgeAOut, &v142, &B, &dB, (float *)&edgeDataOut);
        v68 = uOut;
        if ( ((unsigned __int8)v66 | (unsigned __int8)v67) & 3 )
        {
          if ( v66 )
          {
            v69 = v55;
          }
          else
          {
            *(float *)&v122 = v55;
            v124 = uOut;
            v69 = fmaxf(v55, uOut);
          }
          v70 = *(float *)&edgeDataOut;
          if ( v67 )
          {
            v71 = v56;
          }
          else
          {
            *(float *)&v122 = v56;
            v124 = *(float *)&edgeDataOut;
            v71 = fminf(v56, *(float *)&edgeDataOut);
          }
          getProjectedMidpoint(
            &edgeAOut,
            &B,
            &edgeB,
            v69,
            v71,
            &v52[3 * SLODWORD(v145)],
            &v52[3 * SLODWORD(v145) + 1],
            &edgeBOut);
          v51 = v120;
          v52 = array;
          v72 = edgeBOut.m_quad;
          goto LABEL_78;
        }
        v70 = *(float *)&edgeDataOut;
        if ( v55 >= *(float *)&edgeDataOut )
        {
          v59 = normalOut.m_quad.m128_f32[3];
          v72 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(*(__m128 *)((char *)&v52[1].m_quad + v136), *(__m128 *)((char *)&v52->m_quad + v136)),
                    (__m128)_xmm),
                  *(__m128 *)((char *)&v52->m_quad + v136));
          goto LABEL_77;
        }
        if ( v56 <= uOut )
        {
          v59 = normalOut.m_quad.m128_f32[2];
          v72 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(*(__m128 *)((char *)&v52[1].m_quad + v133), *(__m128 *)((char *)&v52->m_quad + v133)),
                    (__m128)_xmm),
                  *(__m128 *)((char *)&v52->m_quad + v133));
          goto LABEL_77;
        }
        if ( v53 == v51 )
          break;
LABEL_80:
        if ( v68 > v55 )
        {
          v55 = v68;
          normalOut.m_quad.m128_i32[3] = v53;
          v136 = v60;
        }
        if ( v70 < v56 )
        {
          v56 = v70;
          normalOut.m_quad.m128_i32[2] = v53;
          v133 = v60;
        }
        ++LODWORD(v59);
        ++v53;
        v60 += 48i64;
        v145 = v59;
        v61 = v53 == v51;
        if ( v53 > v51 )
        {
          v47 = v116;
          goto LABEL_86;
        }
      }
      v72 = *((__m128 *)v46 + 2);
      v59 = *(float *)&v53;
LABEL_77:
      edgeBOut.m_quad = v72;
LABEL_78:
      if ( v59 == -6.8056469e38/*NaN*/ )
      {
        v59 = v145;
        goto LABEL_80;
      }
      normal.m_quad = _mm_sub_ps(v72, v57);
      if ( v139 < SLODWORD(v59) )
      {
        v86 = v137;
        v87 = (__int64)&v116[v141 / 0x10 + 1];
        v88 = SLODWORD(v59) - v139;
        while ( 1 )
        {
          v89 = *(__m128 *)((char *)&v52->m_quad + v86);
          v90 = _mm_sub_ps(*(__m128 *)((char *)&v52[1].m_quad + v86), v89);
          p.m_quad = *(__m128 *)((char *)v52 + v86);
          B2.m_quad = v90;
          getLineSegInterpolationValue(&edgeAOut, &normal, &p, &B2, normalOut.m_quad.m128_f32);
          v87 += 16i64;
          v86 += 48i64;
          *(__m128 *)(v87 - 16) = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)normalOut.m_quad.m128_u32[0],
                                        (__m128)normalOut.m_quad.m128_u32[0],
                                        0),
                                      v90),
                                    v89);
          if ( !--v88 )
            break;
          v52 = array;
        }
      }
      v47 = v116;
      v116[SLODWORD(v59) + 1i64] = v72;
      v51 = v120;
      v52 = array;
      v73 = v59;
LABEL_87:
      v48 = LODWORD(v73) + 1;
      LODWORD(v144) = v48;
      if ( v48 >= v51 )
      {
        v50 = v118;
        break;
      }
    }
  }
  v74 = 5i64;
  v47[v50 - 1] = *((_OWORD *)v46 + 2);
  normalOut.m_quad.m128_i32[0] = v50 - 1;
  v75 = v50 - 1;
  do
  {
    if ( v75 > 1 )
    {
      v76 = (signed __int64)(v47 + 1);
      v77 = 0i64;
      v78 = v75 - 1;
      do
      {
        v79 = *(__m128 *)(v76 - 16);
        B.m_quad = *(__m128 *)(v76 - 16);
        v80 = *(__m128 *)(v76 + 16);
        v81 = array[v77].m_quad;
        dB.m_quad = (__m128)array[v77];
        v82 = array[v77 + 1].m_quad;
        B2.m_quad = (__m128)array[v77 + 1];
        if ( array[v77 + 2].m_quad.m128_i8[8] == 1 )
        {
          hkLineSegmentUtil::closestPointLineSeg(&B, &dB, &B2, (hkLineSegmentUtil::ClosestPointLineSegResult *)&edgeB);
          v85 = edgeB.m_quad;
        }
        else
        {
          v83 = _mm_sub_ps(v82, v81);
          if ( array[v77 + 2].m_quad.m128_i8[8] == 2 )
          {
            v85 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, _mm_shuffle_ps(v79, v79, 255)), v83), v81);
          }
          else
          {
            normal.m_quad = v83;
            p.m_quad = _mm_sub_ps(v80, v79);
            getLineSegInterpolationValue(&B, &p, &dB, &normal, &v145);
            LODWORD(v144) = 0;
            LODWORD(edgeDataOut) = 1065353216;
            v145 = (float)(v145 * 1.5) - (float)(*(float *)(v76 + 12) * 0.5);
            v84 = (__m128)LODWORD(v145);
            v84.m128_f32[0] = fminf(fmaxf(v145, 0.0), 1.0);
            v145 = v84.m128_f32[0];
            v85 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), v83), v81);
          }
        }
        *(__m128 *)v76 = v85;
        v76 += 16i64;
        v77 += 3i64;
        --v78;
      }
      while ( v78 );
      v47 = v116;
    }
    --v74;
  }
  while ( v74 );
  v91 = (__m128i *)normalOut.m_quad.m128_u64[1];
  v92 = 0;
  v93 = 0i64;
  if ( v118 > 0 )
  {
    v94 = normalOut.m_quad.m128_i32[0];
    v95 = vars0;
    do
    {
      _mm_store_si128((__m128i *)&p, (__m128i)v47[v93]);
      _mm_store_si128((__m128i *)&normal, v91[v93]);
      if ( v93 )
      {
        if ( v92 == v94 )
        {
          if ( v132 )
          {
            v96 = 0;
            v97 = v95 >> 22;
          }
          else
          {
            v96 = 0;
            v97 = *((_DWORD *)v46 + 16) >> 22;
          }
          v98 = 0;
        }
        else
        {
          v96 = *((_DWORD *)&array[3 * v93] - 3);
          v98 = *((_BYTE *)&array[3 * v93] - 8);
          v97 = (unsigned int)array[3 * v93 - 1].m_quad.m128_i32[0] >> 22;
        }
      }
      else
      {
        v96 = 0;
        v97 = *((_DWORD *)v46 + 16) >> 22;
        v98 = 0;
      }
      hkaiPathWriter::addPointToPath((hkaiPathWriter *)v46[9], &p, &normal, v97, v96, v98);
      v47 = v116;
      ++v93;
      ++v92;
    }
    while ( v93 < v118 );
  }
  hkaiPathWriter::addTerminatorToPathPointer((hkaiPathWriter *)v46[9]);
  v99 = v46[9];
  v100 = !v99->m_accessor && SHIDWORD(v99->m_sectionInfo) >= SLODWORD(v99->m_sectionInfo);
  v101 = (char *)v122;
  v61 = v100 == 0;
  v102 = v120;
  v103 = v61;
  if ( v122 == array )
    v102 = 0;
  v120 = v102;
  v104 = (48 * normalOut.m_quad.m128_i32[0] + 127) & 0xFFFFFF80;
  v105 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v106 = (v104 + 15) & 0xFFFFFFF0;
  if ( v104 > v105->m_slabSize || &v101[v106] != v105->m_cur || v105->m_firstNonLifoEnd == v101 )
    hkLifoAllocator::slowBlockFree(v105, v101, v106);
  else
    v105->m_cur = v101;
  v120 = 0;
  if ( v121 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      48 * (v121 & 0x3FFFFFFF));
  v107 = v127;
  array = 0i64;
  v121 = 2147483648;
  v108 = (16 * v127 + 127) & 0xFFFFFF80;
  v109 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v110 = (v108 + 15) & 0xFFFFFFF0;
  if ( v108 > v109->m_slabSize || &v91->m128i_i8[v110] != v109->m_cur || v109->m_firstNonLifoEnd == v91 )
    hkLifoAllocator::slowBlockFree(v109, v91, v110);
  else
    v109->m_cur = v91;
  v111 = v130;
  if ( v130 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v91,
      16 * v130);
  v112 = (16 * v107 + 127) & 0xFFFFFF80;
  v113 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v114 = (v112 + 15) & 0xFFFFFFF0;
  if ( v112 > v113->m_slabSize || (char *)v116 + v114 != v113->m_cur || v113->m_firstNonLifoEnd == v116 )
    hkLifoAllocator::slowBlockFree(v113, v116, v114);
  else
    v113->m_cur = v116;
  if ( v111 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v116,
      16 * v111);
  return (unsigned int)v103;
}Allocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v91,
      16 * v130);
  v112 = (16 * v107 + 127) & 0xFFFFFF80;
  v113 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v114 = (v112 + 15) & 0xFFFFFFF0;
  if ( v112 > v113->m_slabSize || (char *)v116 + v114 != v113->m_cur || v113->m_firstNonLifoEnd == v116 )
    hkLifoAllocator::slowBlockFree(v113, v116, v114);
  else
    v113->m_cur = v116;
  if ( v111 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapA

// File Line: 601
// RVA: 0xC01D70
void __fastcall hkaiNavMeshPathSmoothingUtil::hkaiNavMeshPathSmoothingUtil(hkaiNavMeshPathSmoothingUtil *this, hkaiGeneralAccessor *accessor, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges, unsigned int startFaceKey, hkVector4f *startPoint, hkVector4f *endPoint, hkVector4f *up, float radius, hkaiPathWriter *writer)
{
  __m128 v9; // xmm0

  this->m_accessor = accessor;
  this->m_visitedEdges = visitedEdges;
  this->m_startPoint = (hkVector4f)startPoint->m_quad;
  this->m_endPoint = (hkVector4f)endPoint->m_quad;
  v9 = up->m_quad;
  this->m_radius = radius;
  this->m_writer = writer;
  this->m_startFaceKey = startFaceKey;
  this->m_up.m_quad = v9;
}

